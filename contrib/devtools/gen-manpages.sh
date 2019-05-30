#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

GTHPCOIND=${GTHPCOIND:-$BINDIR/gthpcoind}
GTHPCOINCLI=${GTHPCOINCLI:-$BINDIR/gthpcoin-cli}
GTHPCOINTX=${GTHPCOINTX:-$BINDIR/gthpcoin-tx}
WALLET_TOOL=${WALLET_TOOL:-$BINDIR/gthpcoin-wallet}
GTHPCOINQT=${GTHPCOINQT:-$BINDIR/qt/gthpcoin-qt}

[ ! -x $GTHPCOIND ] && echo "$GTHPCOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BTCVER=($($GTHPCOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for gthpcoind if --version-string is not set,
# but has different outcomes for gthpcoin-qt and gthpcoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$GTHPCOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $GTHPCOIND $GTHPCOINCLI $GTHPCOINTX $WALLET_TOOL $GTHPCOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m

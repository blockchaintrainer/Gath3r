// Copyright (c) 2011-2014 The Gthpcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef GTHPCOIN_QT_GTHPCOINADDRESSVALIDATOR_H
#define GTHPCOIN_QT_GTHPCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class GthpcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit GthpcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Gthpcoin address widget validator, checks for a valid gthpcoin address.
 */
class GthpcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit GthpcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // GTHPCOIN_QT_GTHPCOINADDRESSVALIDATOR_H

// Copyright (c) 2016-2018 The Gthpcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef GTHPCOIN_QT_TEST_RPCNESTEDTESTS_H
#define GTHPCOIN_QT_TEST_RPCNESTEDTESTS_H

#include <QObject>
#include <QTest>

#include <txdb.h>
#include <txmempool.h>

class RPCNestedTests : public QObject
{
    Q_OBJECT

    private Q_SLOTS:
    void rpcNestedTests();
};

#endif // GTHPCOIN_QT_TEST_RPCNESTEDTESTS_H

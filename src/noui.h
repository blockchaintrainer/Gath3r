// Copyright (c) 2013-2018 The Gthpcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef GTHPCOIN_NOUI_H
#define GTHPCOIN_NOUI_H

#include <string>

/** Non-GUI handler, which logs and prints messages. */
bool noui_ThreadSafeMessageBox(const std::string& message, const std::string& caption, unsigned int style);
/** Non-GUI handler, which logs and prints questions. */
bool noui_ThreadSafeQuestion(const std::string& /* ignored interactive message */, const std::string& message, const std::string& caption, unsigned int style);
/** Non-GUI handler, which only logs a message. */
void noui_InitMessage(const std::string& message);

/** Connect all gthpcoind signal handlers */
void noui_connect();

#endif // GTHPCOIN_NOUI_H

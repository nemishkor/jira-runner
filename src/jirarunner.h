/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef JIRARUNNER_H
#define JIRARUNNER_H

#include <KRunner/AbstractRunner>

class JiraRunner : public Plasma::AbstractRunner
{
    Q_OBJECT

public:
    JiraRunner(QObject *parent, const QVariantList &args);
    ~JiraRunner() override;

public: // Plasma::AbstractRunner API
    void match(Plasma::RunnerContext &context) override;
    void run(const Plasma::RunnerContext &context, const Plasma::QueryMatch &match) override;
};

#endif

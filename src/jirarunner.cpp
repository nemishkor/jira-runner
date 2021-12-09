/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "jirarunner.h"

// KF
#include <KLocalizedString>

JiraRunner::JiraRunner(QObject *parent, const QVariantList &args)
    : Plasma::AbstractRunner(parent, args)
{
    setObjectName(QStringLiteral("JiraRunner"));
}

JiraRunner::~JiraRunner()
{
}


void JiraRunner::match(Plasma::RunnerContext &context)
{
    const QString term = context.query();
    if (term.length() < 3) {
        return;
    }

    // TODO
}

void JiraRunner::run(const Plasma::RunnerContext &context, const Plasma::QueryMatch &match)
{
    Q_UNUSED(context)
    Q_UNUSED(match)

    // TODO
}

K_EXPORT_PLASMA_RUNNER_WITH_JSON(JiraRunner, "plasma-runner-jirarunner.json")

// needed for the QObject subclass declared as part of K_EXPORT_PLASMA_RUNNER_WITH_JSON
#include "jirarunner.moc"

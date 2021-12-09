/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "jirarunner.h"

// KF
#include <KLocalizedString>
#include <KRunner/QueryMatch>
#include <QDesktopServices>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QString>

JiraRunner::JiraRunner(QObject *parent, const QVariantList &args)
    : Plasma::AbstractRunner(parent, args)
{
    setObjectName(QStringLiteral("JiraRunner"));
    setPriority(LowPriority);
    setMinLetterCount(4);
}

JiraRunner::~JiraRunner()
{
}

void JiraRunner::match(Plasma::RunnerContext &context)
{
    const QString term = context.query();
    const QRegularExpression regex(QString::fromUtf8("\\w+-\\d+"));
    const QRegularExpressionMatch termMatch = regex.match(term);
    if(termMatch.hasMatch()){
        Plasma::QueryMatch match(this);
        match.setText(termMatch.captured());
        context.addMatch(match);
    }
}

void JiraRunner::run(const Plasma::RunnerContext &context, const Plasma::QueryMatch &match)
{
    Q_UNUSED(context)
    Q_UNUSED(match)
    QDesktopServices::openUrl(QUrl(QString::fromUtf8("https://dermpro.atlassian.net/browse/").append(match.text())));
}

K_EXPORT_PLASMA_RUNNER_WITH_JSON(JiraRunner, "plasma-runner-jirarunner.json")

// needed for the QObject subclass declared as part of K_EXPORT_PLASMA_RUNNER_WITH_JSON
#include "jirarunner.moc"

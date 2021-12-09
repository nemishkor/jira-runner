add_definitions(-DTRANSLATION_DOMAIN=\"plasma_runner_org.kde.jirarunner\")

add_library(jirarunner MODULE)

target_sources(jirarunner PRIVATE
    jirarunner.cpp
)

kcoreaddons_desktop_to_json(jirarunner plasma-runner-jirarunner.desktop)
target_link_libraries(jirarunner KF5::Runner KF5::I18n)

install(TARGETS jirarunner DESTINATION ${KDE_INSTALL_PLUGINDIR}/kf5/krunner)

install(FILES plasma-runner-jirarunner.desktop DESTINATION ${KDE_INSTALL_KSERVICES5DIR})

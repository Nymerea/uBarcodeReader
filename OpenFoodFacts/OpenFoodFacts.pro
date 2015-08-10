TEMPLATE = app
TARGET = OpenFoodFacts

QT += quick qml gui multimedia


QML_FILES += $$files(*.qml,true) \
             $$files(*.js,true)

CONF_FILES +=  OpenFoodFacts.apparmor \
               OpenFoodFacts.desktop \
               OpenFoodFacts.png


OTHER_FILES += $${CONF_FILES} \
               $${QML_FILES}


#specify where the qml/js files are installed to
qml_files.path = /OpenFoodFacts
qml_files.files += $${QML_FILES}

#specify where the config files are installed to
config_files.path = /OpenFoodFacts
config_files.files += $${CONF_FILES}

INSTALLS+=config_files qml_files

SOURCES += \
    main.cpp \
    QDecoder.cpp

HEADERS += \
    QDecoder.h



RESOURCES += \
    ressources.qrc




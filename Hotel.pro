QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addhotelform.cpp \
    addofferform.cpp \
    adminmenuwindow.cpp \
    hotel.cpp \
    lookadminhotelform.cpp \
    lookofferadminform.cpp \
    lookofferuserform.cpp \
    lookuserhotelform.cpp \
    main.cpp \
    mainwindow.cpp \
    offer.cpp \
    usermenuwindow.cpp

HEADERS += \
    Files.h \
    Queue.h \
    addhotelform.h \
    addofferform.h \
    adminmenuwindow.h \
    hotel.h \
    lookadminhotelform.h \
    lookofferadminform.h \
    lookofferuserform.h \
    lookuserhotelform.h \
    mainwindow.h \
    offer.h \
    usermenuwindow.h

FORMS += \
    addhotelform.ui \
    addofferform.ui \
    adminmenuwindow.ui \
    lookadminhotelform.ui \
    lookofferadminform.ui \
    lookofferuserform.ui \
    lookuserhotelform.ui \
    mainwindow.ui \
    usermenuwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

CONFIG += console c++14

INCLUDEPATH += "gtest/include"
INCLUDEPATH += "gtest/"
INCLUDEPATH += "../../"



SOURCES += \
    main.cpp \
    gtest/src/gtest.cc \
    gtest/src/gtest-all.cc \
    gtest/src/gtest-death-test.cc \
    gtest/src/gtest-filepath.cc \
    gtest/src/gtest-port.cc \
    gtest/src/gtest-printers.cc \
    gtest/src/gtest-test-part.cc \
    gtest/src/gtest-typed-test.cc





QMAKE_CXXFLAGS += -DGTEST_HAS_TR1_TUPLE=0 -DGTEST_USE_OWN_TR1_TUPLE=0

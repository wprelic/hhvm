HHVM_DEFINE_EXTENSION("mailparse"
  SOURCES
    ext_mailparse.cpp
    mime.cpp
    rfc822.cpp
  HEADERS
    mime.h
    rfc822.h
  SYSTEMLIB
    ext_mailparse.php
  DEPENDS
    libMbfl
)

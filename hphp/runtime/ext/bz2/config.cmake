HHVM_DEFINE_EXTENSION("bz2"
  SOURCES
    bz2-file.cpp
    ext_bz2.cpp
  HEADERS
    bz2-file.h
  SYSTEMLIB
    ext_bz2.php
  DEPENDS
    libBZip2
    libFolly
)

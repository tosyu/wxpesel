file(GLOB SOURCES
    *.cc
)

file(GLOB HEADERS
    *.h
)

target_sources(wxpesel PRIVATE ${HEADERS} ${SOURCES})
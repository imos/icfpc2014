cc_library(
    NAME "sbl"
    SOURCES "sbl.cc"
    DEPENDENCIES
        ":tree"
        ":list"
        ":stack"
        ":queue"
        ":array256"
)

cc_library(
    NAME "array256"
    SOURCES "array256.cpp" "array256_translator.cpp"
    DEPENDENCIES
        "//translator:lib"
	":list"
)

cc_library(
    NAME "tree"
    SOURCES "tree.cpp"
    DEPENDENCIES
        "//translator:lib"
	":list"
)

cc_library(
    NAME "fasttree"
    SOURCES "fasttree.cpp"
    DEPENDENCIES
        "//translator:lib"
	":list"
)

cc_library(
    NAME "list"
    SOURCES "list.cpp"
    DEPENDENCIES
        "//translator:lib"
)

cc_library(
    NAME "stack"
    SOURCES "stack.cpp"
    DEPENDENCIES
        "//translator:lib"
)

cc_library(
    NAME "queue"
    SOURCES "queue.cpp"
    DEPENDENCIES
        "//translator:lib"
	":list"
	":stack"
)

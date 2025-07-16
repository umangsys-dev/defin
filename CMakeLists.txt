cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(defin LANGUAGES C CXX)

include(GNUInstallDirs)

add_executable(${PROJECT_NAME} 
	src/main.cpp 
	src/curate_missing.cpp 
	src/fetch_dbmap.cpp 
	src/fetch_pm.cpp 
	src/fetch_headers.cpp 
	src/json_parser_engine.cpp 
	src/resolver.cpp
	src/auto_install.cpp
	)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/headers  PRIVATE ${CMAKE_SOURCE_DIR})

target_link_directories(${PROJECT_NAME} PRIVATE tiny-process-library/build)

target_link_libraries(${PROJECT_NAME} tiny-process-library)

install(TARGETS ${PROJECT_NAME}

	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES json-db/header-llib.json json-db/llib-pkg_apt.json json-db/llib-pkg_pacman.json json-db/llib-pkg_dnf.json json-db/pm-cmd.json
	DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME}
)
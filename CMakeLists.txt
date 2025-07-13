cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(defin LANGUAGES C CXX)

include(GNUInstallDirs)

add_executable(${PROJECT_NAME} 
	main.cpp 
	curate_missing.cpp 
	fetch_dbmap.cpp 
	fetch_pm.cpp 
	fetch_headers.cpp 
	json_parser_engine.cpp 
	resolver.cpp
	auto_install.cpp
	)

target_link_directories(${PROJECT_NAME} PRIVATE tiny-process-library/build)

target_link_libraries(${PROJECT_NAME} tiny-process-library)

install(TARGETS ${PROJECT_NAME}

	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES json-db/header-llib.json json-db/llib-pkg_apt.json json-db/llib-pkg_pacman.json json-db/llib-pkg_dnf.json json-db/pm-cmd.json
	DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME}
)
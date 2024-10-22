---@diagnostic disable: undefined-global
---
set_project("Project name")
set_version("1.0.0")

set_languages("c++latest")

add_rules("mode.debug", "mode.release")

set_warnings("all", "error")

if is_mode("debug") then
  set_symbols("debug")
  set_optimize("none")
else
  set_symbols("hidden")
  set_optimize("fastest")
  set_strip("all")
end

function add_platform_specific_flags()
  if is_plat("windows") then
    add_cxxflags("/EHsc")
  else
    -- Add flags for e.g. linux here
  end
end

target("aliases")
set_kind("binary")
add_files("src/*.cpp")
add_files("src/**/*.cpp")
add_includedirs("include")
add_platform_specific_flags()
target_end()

add_requires("gtest", { configs = { main = false, gmock = true } })

target("tests")
set_kind("binary")
add_packages("gtest")
set_default(false)
add_files("tests/test_*.cpp")
add_tests("default")
add_deps("aliases")
target_end()

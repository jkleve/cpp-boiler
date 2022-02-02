from conans import ConanFile
from conan.tools.cmake import CMakeDeps, CMakeToolchain, CMake
from conan.tools.layout import cmake_layout


class LiteLoggerConan(ConanFile):
    name = "lite_logger"
    version = "0.1"

    # Optional metadata
    license = "<license>"
    author = "<name> <email>"
    url = "<url>"
    description = "<description>"
    topics = ("<put>", "<topics>", "<here>")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "include/*", "src/*", "test/*"

    def requirements(self):
        self.requires("gtest/1.10.0")
        self.requires("rapidcheck/cci.20210702")
        self.requires("spdlog/1.9.2")

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        CMakeDeps(self).generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["lite_logger"]
        self.cpp_info.requires = ['spdlog::spdlog']


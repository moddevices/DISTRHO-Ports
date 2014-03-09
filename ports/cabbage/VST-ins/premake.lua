
dofile("../../../scripts/make-project.lua")

package = make_juce_vst_project("CabbagePluginSynth")

project.bindir  = "../../../bin/cabbage"
package.links   = { package.links, "csound64" }
package.defines = { package.defines, "Cabbage_Plugin_Synth=1", "USE_DOUBLE=1", "CSOUND6=1" }

package.includepaths = {
  package.includepaths,
  "/opt/kxstudio/include/csound",
  "/usr/include/csound"
}

package.libpaths = {
  package.libpaths,
  "/opt/kxstudio/lib"
}

package.links = {
  package.links,
  "sndfile"
}

package.files = {
  matchfiles (
    "../source/*.cpp",
    "../source/Plugin/*.cpp",
    "../../../libs/juce-plugin/JucePluginMain.cpp"
  )
}
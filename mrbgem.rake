MRuby::Gem::Specification.new('mruby-imgtype') do |spec|
  spec.license = 'MIT'
  spec.authors = 'Junichi Kajiwara'

  if ENV['VisualStudioVersion'] || ENV['VSINSTALLDIR'] then
    spec.linker.flags_before_libraries << "imgtype.lib"
    spec.linker.flags_before_libraries << "User32.lib"
  end
end

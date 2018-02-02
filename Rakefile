require "rake/extensiontask"

Rake::ExtensionTask.new "kmp" do |ext|
  ext.lib_dir = "lib/kmp"
end

require 'bundler/gem_tasks'
require 'rspec/core/rake_task'

RSpec::Core::RakeTask.new(:spec)

task default: :spec

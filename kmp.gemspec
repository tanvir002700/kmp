
lib = File.expand_path("../lib", __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require "kmp/version"

Gem::Specification.new do |spec|
  spec.name          = "kmp"
  spec.version       = Kmp::VERSION
  spec.authors       = ["tanvir hasan"]
  spec.email         = ["tanvir002700@gmail.com"]

  spec.summary       = %q{Kmp algorithm implementation with c extension in ruby.}
  spec.description   = %q{A string matching algorithm wants to find the starting index m in string S[] that matches the search word W[].}
  spec.homepage      = "https://rubygems.org/gems/kmp"
  spec.license       = "MIT"
  spec.metadata      = { 'source_code_uri' => 'https://github.com/tanvir002700/kmp' }

  # Prevent pushing this gem to RubyGems.org. To allow pushes either set the 'allowed_push_host'
  # to allow pushing to a single host or delete this section to allow pushing to any host.
  if spec.respond_to?(:metadata)
    spec.metadata["allowed_push_host"] = 'https://rubygems.org'
  else
    raise "RubyGems 2.0 or newer is required to protect against " \
      "public gem pushes."
  end

  spec.files         = `git ls-files -z`.split("\x0").reject do |f|
    f.match(%r{^(test|spec|features)/})
  end
  spec.bindir        = "exe"
  spec.executables   = spec.files.grep(%r{^exe/}) { |f| File.basename(f) }
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.16"
  spec.add_development_dependency 'coveralls', '~> 0.8.21'
  spec.add_development_dependency "rake", "~> 10.0"
  spec.add_development_dependency "rspec", "~> 3.0"
  spec.add_development_dependency 'rake-compiler', '~> 1.0', '>= 1.0.0'
  spec.extensions = %w[ext/kmp/extconf.rb]
end

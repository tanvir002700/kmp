# Kmp
[![Build Status](https://travis-ci.org/tanvir002700/kmp.svg?branch=master)](https://travis-ci.org/tanvir002700/kmp)
[![Maintainability](https://api.codeclimate.com/v1/badges/69f40101eeb294c05163/maintainability)](https://codeclimate.com/github/tanvir002700/kmp/maintainability)
[![Coverage Status](https://coveralls.io/repos/github/tanvir002700/kmp/badge.svg?branch=master)](https://coveralls.io/github/tanvir002700/kmp?branch=master)
[![Gem Version](https://badge.fury.io/rb/kmp.svg)](https://badge.fury.io/rb/kmp)
[![Downloads](https://img.shields.io/gem/dt/kmp.svg)](https://rubygems.org/gems/kmp)
[![GitHub last commit (branch)](https://img.shields.io/github/last-commit/tanvir002700/kmp/master.svg)](https://github.com/tanvir002700/kmp)
[![license](https://img.shields.io/github/license/tanvir002700/kmp.svg)](https://github.com/tanvir002700/kmp/blob/master/LICENSE)

This gem is KMP (Knuth–Morris–Pratt algorithm) implemantation with c Extension.
A super first substring find technique in a big string.

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'kmp'
```

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install kmp

## Usage

``` ruby
require 'kmp'
k = Kmp::String.new 'abcdeab'
k.match 'ab' #=> [0, 5]

k.length #=> 7
```

## Complexity

- match function complexity O(N+M), N original text string length, M match string length
- length complexity O(1)

## Benchmark
This benchmark between kmp implementation in c-extenstion vs pure ruby. [Benchmark](http://ruby-doc.org/stdlib-2.0.0/libdoc/benchmark/rdoc/Benchmark.html) module use for comparison.

```
lenght of string: 500
Rehearsal -----------------------------------------------
c-extension   0.000000   0.000000   0.000000 (  0.000028)
ruby          0.000000   0.000000   0.000000 (  0.001067)
-------------------------------------- total: 0.000000sec

                  user     system      total        real
c-extension   0.000000   0.000000   0.000000 (  0.000019)
ruby          0.000000   0.000000   0.000000 (  0.000731)

lenght of string: 5000
Rehearsal -----------------------------------------------
c-extension   0.000000   0.000000   0.000000 (  0.000074)
ruby          0.000000   0.000000   0.000000 (  0.006990)
-------------------------------------- total: 0.000000sec

                  user     system      total        real
c-extension   0.000000   0.000000   0.000000 (  0.000059)
ruby          0.000000   0.000000   0.000000 (  0.003058)

lenght of string: 50000
Rehearsal -----------------------------------------------
c-extension   0.000000   0.000000   0.000000 (  0.000276)
ruby          0.030000   0.000000   0.030000 (  0.022061)
-------------------------------------- total: 0.030000sec

                  user     system      total        real
c-extension   0.000000   0.000000   0.000000 (  0.000117)
ruby          0.010000   0.000000   0.010000 (  0.014624)

lenght of string: 500000
Rehearsal -----------------------------------------------
c-extension   0.000000   0.000000   0.000000 (  0.001346)
ruby          0.140000   0.000000   0.140000 (  0.147500)
-------------------------------------- total: 0.140000sec

                  user     system      total        real
c-extension   0.000000   0.000000   0.000000 (  0.001188)
ruby          0.140000   0.000000   0.140000 (  0.146642)

lenght of string: 5000000
Rehearsal -----------------------------------------------
c-extension   0.010000   0.000000   0.010000 (  0.013171)
ruby          1.480000   0.010000   1.490000 (  1.482893)
-------------------------------------- total: 1.500000sec

                  user     system      total        real
c-extension   0.010000   0.000000   0.010000 (  0.013098)
ruby          1.510000   0.000000   1.510000 (  1.508361)

lenght of string: 50000000
Rehearsal -----------------------------------------------
c-extension   0.120000   0.020000   0.140000 (  0.143160)
ruby         16.320000   0.020000  16.340000 ( 16.356332)
------------------------------------- total: 16.480000sec

                  user     system      total        real
c-extension   0.120000   0.010000   0.130000 (  0.143203)
ruby         15.130000   0.050000  15.180000 ( 15.191924)

lenght of string: 500000000
Rehearsal -----------------------------------------------
c-extension   1.190000   0.200000   1.390000 (  1.491211)
ruby        159.510000   0.210000 159.720000 (159.723059)
------------------------------------ total: 161.110000sec

                  user     system      total        real
c-extension   1.270000   0.200000   1.470000 (  1.568321)
ruby        161.190000   0.250000 161.440000 (161.449839)

```

## Development

After checking out the repo, run `bin/setup` to install dependencies. Then, run `rake spec` to run the tests. You can also run `bin/console` for an interactive prompt that will allow you to experiment. For compile c extension run `rake compile`.

To install this gem onto your local machine, run `bundle exec rake install`. To release a new version, update the version number in `version.rb`, and then run `bundle exec rake release`, which will create a git tag for the version, push git commits and tags, and push the `.gem` file to [rubygems.org](https://rubygems.org).

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/tanvir002700/kmp. This project is intended to be a safe, welcoming space for collaboration, and contributors are expected to adhere to the [Contributor Covenant](http://contributor-covenant.org) code of conduct.

## License

The gem is available as open source under the terms of the [MIT License](https://opensource.org/licenses/MIT).

## Code of Conduct

Everyone interacting in the Kmp project’s codebases, issue trackers, chat rooms and mailing lists is expected to follow the [code of conduct](https://github.com/tanvir002700/kmp/blob/master/CODE_OF_CONDUCT.md).

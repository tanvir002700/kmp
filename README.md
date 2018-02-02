# Kmp
[![Build Status](https://travis-ci.org/tanvir002700/kmp.svg?branch=master)](https://travis-ci.org/tanvir002700/kmp)
[![Maintainability](https://api.codeclimate.com/v1/badges/69f40101eeb294c05163/maintainability)](https://codeclimate.com/github/tanvir002700/kmp/maintainability)
[![Coverage Status](https://coveralls.io/repos/github/tanvir002700/kmp/badge.svg?branch=master)](https://coveralls.io/github/tanvir002700/kmp?branch=master)
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
k.match 'ab' #=> [0, 4]

k.length #=> 7
```

## Complexity

- match function complexity O(N+M), N original text string length, M match string length
- length complexity O(1)

## Development

After checking out the repo, run `bin/setup` to install dependencies. Then, run `rake spec` to run the tests. You can also run `bin/console` for an interactive prompt that will allow you to experiment.

To install this gem onto your local machine, run `bundle exec rake install`. To release a new version, update the version number in `version.rb`, and then run `bundle exec rake release`, which will create a git tag for the version, push git commits and tags, and push the `.gem` file to [rubygems.org](https://rubygems.org).

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/tanvir002700/kmp. This project is intended to be a safe, welcoming space for collaboration, and contributors are expected to adhere to the [Contributor Covenant](http://contributor-covenant.org) code of conduct.

## License

The gem is available as open source under the terms of the [MIT License](https://opensource.org/licenses/MIT).

## Code of Conduct

Everyone interacting in the Kmp project’s codebases, issue trackers, chat rooms and mailing lists is expected to follow the [code of conduct](https://github.com/tanvir002700/kmp/blob/master/CODE_OF_CONDUCT.md).

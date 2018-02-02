#!/usr/bin/env ruby

require "bundler/setup"
require "kmp"

txt = ''
50.times{txt << 'abc'}

a = Kmp::String.new txt
puts a.length

#!/usr/bin/env ruby

require "bundler/setup"
require "kmp"

txt = ''
50000.times{txt << 'abc'}

ktxt = Kmp::String.new txt

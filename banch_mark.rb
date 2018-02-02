#!/usr/bin/env ruby

require "bundler/setup"
require "kmp"

#(0...50).map { ('a'..'z').to_a[rand(26)] }.join
txt = ''
10000.times{txt << 'abc'}

t1 = Time.now
a = Kmp::String.new txt
b = a.match 'abcabcabcabcabcabc'
puts Time.now - t1
puts b.length

t1 = Time.now
b = txt.enum_for(:scan, /(?=abcabcabcabcabcabc)/).map { Regexp.last_match.offset(0).first }
puts Time.now - t1
puts b.size

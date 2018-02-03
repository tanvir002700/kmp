#!/usr/bin/env ruby

require "bundler/setup"
require "kmp"

def compute_prefix(ptrn)
  m = ptrn.size
  prefix = Array.new m, 0
  k = -1
  prefix[0] = -1
  (m-1).times do |i|
    i = i + 1
    while k>-1 && ptrn[k+1] != ptrn[i] do
      k = prefix[k];
    end
    if ptrn[k+1] == ptrn[i]
      k = k + 1
    end
    prefix[i] = k
  end
  prefix
end

def kmp_ruby(txt, ptrn)
  prefix = compute_prefix(ptrn)
  n = txt.size
  m = ptrn.size
  pos = []

  q = -1
  (n).times do |i|
    while(q>-1 && ptrn[q+1]!=txt[i]) do
      q = prefix[q]
    end
    if ptrn[q+1] == txt[i]
      q = q + 1
    end
    if q == (m-1)
      pos << (i-m+1)
      q = prefix[q]
    end
  end
  return pos
end

#(0...50).map { ('a'..'z').to_a[rand(26)] }.join
txt = ''
1000000.times{txt << 'abc'}

t1 = Time.now
a = Kmp::String.new txt
a.match 'abcabcabcabcabcabc'
puts (Time.now - t1).to_f

t1 = Time.now
kmp_ruby(txt, 'abcabcabcabcabcabc')
puts Time.now - t1



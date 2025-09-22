#!/usr/bin/env ruby
# Number Base Quiz (Lv1, Ruby). Type 'q' to quit.

STDOUT.sync = true
srand(Time.now.to_i)

def ask_round
  n = rand(0..255)
  kind = %i[d2b d2h b2d h2d].sample
  correct = nil
  prompt  = nil

  case kind
  when :d2b
    correct = n.to_s(2)
    prompt  = "dec #{n} -> bin ?"
  when :d2h
    correct = n.to_s(16)
    prompt  = "dec #{n} -> hex ?"
  when :b2d
    s = n.to_s(2)
    correct = n.to_s(10)
    prompt  = "bin #{s} -> dec ?"
  when :h2d
    s = n.to_s(16)
    correct = n.to_s(10)
    prompt  = "hex #{s} -> dec ?"
  end

  print "> #{prompt} : "
  ans = STDIN.gets
  return :quit if ans.nil?
  ans = ans.strip.downcase
  return :quit if %w[q quit exit].include?(ans)

  if ans == correct.downcase
    puts "correct! (#{correct})"
    true
  else
    puts "oops, answer = #{correct}"
    false
  end
end

puts "Number Base Quiz (0..255). Type 'q' to quit."
wins = tries = 0
loop do
  r = ask_round
  break if r == :quit
  tries += 1
  wins  += 1 if r
  pct = tries > 0 ? wins * 100.0 / tries : 0.0
  puts "score: #{wins}/#{tries} (#{format('%.1f', pct)}%)"
end
puts "bye! score: #{wins}/#{tries} (#{format('%.1f', tries>0 ? wins*100.0/tries : 0.0)}%)"

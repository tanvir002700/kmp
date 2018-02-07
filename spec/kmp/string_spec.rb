module Kmp
  RSpec.describe String, type: :class do
    describe 'Kmp::String' do
      context 'new method' do
        it 'initialize object successfully' do
          expect(String.new('abc')).to be_a String
        end
      end

      context 'str accessor' do
        it 'has str attribute accesor' do
          expect(String.new('abcdek').str).to eq('abcdek')
        end
      end

      context 'length method' do
        it 'return initialize string length' do
          expect(String.new('abdec').length).to eq(5)
        end
      end
    end

    describe '#match' do
      it 'return all occurance of string' do
        expect(String.new('ababacaababacaab').match('ababaca')).to match_array [0, 7]
      end

      it 'return empty array' do
        expect(String.new('ababacaababacaab').match('ababacafdkadjfkdjfkjsf')).to match_array []
      end

      it 'return 100 occurance' do
        txt = ''
        100.times { txt << 'abc'}
        expect(String.new(txt).match('abc').size).to eq(100)
      end
    end

    describe '#inspect' do
      it 'return actual string' do
        expect(String.new('abc').inspect).to eq('abc')
      end
    end

    describe '#replace' do
      context 'replace the match sub string with given string' do
        let(:str) { String.new 'abcdefghabcdef' }
        it 'replace the match position with given string' do
          expect(str.replace('de', 'X')).to eq('abcXfghabcXf')
        end
      end
    end
  end
end

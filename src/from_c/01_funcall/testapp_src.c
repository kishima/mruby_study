#include <stdio.h>
#include "mruby.h"
#include "mruby/compile.h"

const char* script = 
" def function;\
    puts 'Hello mruby!';\
  end;\
";

int main(){
  mrb_state *mrb = mrb_open();
  mrb_value obj = mrb_load_string(mrb,script);
  mrb_funcall(mrb,obj,"function",0);
  mrb_close(mrb);
  return 0;
}

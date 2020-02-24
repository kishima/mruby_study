#include <stdio.h>
#include "mruby.h"
#include "mruby/compile.h"

int main(){
  mrb_state *mrb = mrb_open();
  mrb_load_string(mrb,"puts 'Hello mruby!'");
  mrb_close(mrb);
  return 0;
}

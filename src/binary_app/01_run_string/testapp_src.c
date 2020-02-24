#include <stdio.h>
#include "mruby.h"
#include "mruby/irep.h"
#include "mruby/compile.h"
#include "mruby/error.h"
#include "mruby/string.h"
#include "mruby/array.h"
#include "mruby/variable.h"



int main(){
  printf("Test01\n");

  const char* script = "puts 'Hello mruby!'";

  mrb_state *mrb = mrb_open();
  int ai = mrb_gc_arena_save(mrb);

  mrb_load_string(mrb,script);
  if (mrb->exc) {
    printf("Exception occurred: %s\n", mrb_str_to_cstr(mrb, mrb_inspect(mrb, mrb_obj_value(mrb->exc))));
    mrb->exc = 0;
  } else {
    printf("Success\n");
  }

  mrb_gc_arena_restore(mrb, ai);
  mrb_close(mrb);
  return 0;
}


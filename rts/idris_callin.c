#include "idris_callin.h"
#include "idris_opts.h"
#include "idris_stats.h"
#include "idris_rts.h"

// The default options should give satisfactory results under many circumstances.
RTSOpts opts = { 
    .init_heap_size = 4096000,
    .max_stack_size = 4096000,
    .show_summary   = 0
};

static VM * vm = NULL;

void idris_init()
{
    vm = init_vm(opts.max_stack_size, opts.init_heap_size, 1);
    initNullaries();
}

void idris_exit()
{
    Stats stats = terminate(vm);

    if (opts.show_summary) {
        print_stats(&stats);
    }

    freeNullaries();
}

static void do_hcall(struct lg_cpu *cpu, struct hcall_args *args)
{
switch (args->arg0) {
case LHCALL_FLUSH_ASYNC:
break;
case LHCALL_SEND_INTERRUPTS:
break;
case LHCALL_LGUEST_INIT:
kill_guest(cpu, "already have lguest_data");
break;
case LHCALL_SHUTDOWN: {
char msg[128];
__lgread(cpu, msg, args->arg1, sizeof(msg));
msg[sizeof(msg)-1] = '\0';
kill_guest(cpu, "CRASH: %s", msg);
if (args->arg2 == LGUEST_SHUTDOWN_RESTART)
cpu->lg->dead = ERR_PTR(-ERESTART);
break;
}
case LHCALL_FLUSH_TLB:
if (args->arg1)
guest_pagetable_clear_all(cpu);
else
guest_pagetable_flush_user(cpu);
break;
case LHCALL_NEW_PGTABLE:
guest_new_pagetable(cpu, args->arg1);
break;
case LHCALL_SET_STACK:
guest_set_stack(cpu, args->arg1, args->arg2, args->arg3);
break;
case LHCALL_SET_PTE:
#ifdef CONFIG_X86_PAE
guest_set_pte(cpu, args->arg1, args->arg2,
__pte(args->arg3 | (u64)args->arg4 << 32));
#else
guest_set_pte(cpu, args->arg1, args->arg2, __pte(args->arg3));
#endif
break;
case LHCALL_SET_PGD:
guest_set_pgd(cpu->lg, args->arg1, args->arg2);
break;
#ifdef CONFIG_X86_PAE
case LHCALL_SET_PMD:
guest_set_pmd(cpu->lg, args->arg1, args->arg2);
break;
#endif
case LHCALL_SET_CLOCKEVENT:
guest_set_clockevent(cpu, args->arg1);
break;
case LHCALL_TS:
cpu->ts = args->arg1;
break;
case LHCALL_HALT:
cpu->halted = 1;
break;
default:
if (lguest_arch_do_hcall(cpu, args))
kill_guest(cpu, "Bad hypercall %li\n", args->arg0);
}
}
static void do_async_hcalls(struct lg_cpu *cpu)
{
unsigned int i;
u8 st[LHCALL_RING_SIZE];
if (copy_from_user(&st, &cpu->lg->lguest_data->hcall_status, sizeof(st)))
return;
for (i = 0; i < ARRAY_SIZE(st); i++) {
struct hcall_args args;
unsigned int n = cpu->next_hcall;
if (st[n] == 0xFF)
break;
if (++cpu->next_hcall == LHCALL_RING_SIZE)
cpu->next_hcall = 0;
if (copy_from_user(&args, &cpu->lg->lguest_data->hcalls[n],
sizeof(struct hcall_args))) {
kill_guest(cpu, "Fetching async hypercalls");
break;
}
do_hcall(cpu, &args);
if (put_user(0xFF, &cpu->lg->lguest_data->hcall_status[n])) {
kill_guest(cpu, "Writing result for async hypercall");
break;
}
if (cpu->pending.trap)
break;
}
}
static void initialize(struct lg_cpu *cpu)
{
if (cpu->hcall->arg0 != LHCALL_LGUEST_INIT) {
kill_guest(cpu, "hypercall %li before INIT", cpu->hcall->arg0);
return;
}
if (lguest_arch_init_hypercalls(cpu))
kill_guest(cpu, "bad guest page %p", cpu->lg->lguest_data);
if (get_user(cpu->lg->noirq_iret, &cpu->lg->lguest_data->noirq_iret))
kill_guest(cpu, "bad guest page %p", cpu->lg->lguest_data);
write_timestamp(cpu);
page_table_guest_data_init(cpu);
guest_pagetable_clear_all(cpu);
}
void do_hypercalls(struct lg_cpu *cpu)
{
if (unlikely(!cpu->lg->lguest_data)) {
initialize(cpu);
cpu->hcall = NULL;
return;
}
do_async_hcalls(cpu);
if (!cpu->pending.trap) {
do_hcall(cpu, cpu->hcall);
cpu->hcall = NULL;
}
}
void write_timestamp(struct lg_cpu *cpu)
{
struct timespec now;
ktime_get_real_ts(&now);
if (copy_to_user(&cpu->lg->lguest_data->time,
&now, sizeof(struct timespec)))
kill_guest(cpu, "Writing timestamp");
}

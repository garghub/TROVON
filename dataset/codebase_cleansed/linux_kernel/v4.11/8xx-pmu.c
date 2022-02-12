static s64 get_insn_ctr(void)
{
int ctr;
unsigned long counta;
do {
ctr = atomic_read(&instruction_counter);
counta = mfspr(SPRN_COUNTA);
} while (ctr != atomic_read(&instruction_counter));
return ((s64)ctr << 16) | (counta >> 16);
}
static int event_type(struct perf_event *event)
{
switch (event->attr.type) {
case PERF_TYPE_HARDWARE:
if (event->attr.config == PERF_COUNT_HW_CPU_CYCLES)
return PERF_8xx_ID_CPU_CYCLES;
if (event->attr.config == PERF_COUNT_HW_INSTRUCTIONS)
return PERF_8xx_ID_HW_INSTRUCTIONS;
break;
case PERF_TYPE_HW_CACHE:
if (event->attr.config == ITLB_LOAD_MISS)
return PERF_8xx_ID_ITLB_LOAD_MISS;
if (event->attr.config == DTLB_LOAD_MISS)
return PERF_8xx_ID_DTLB_LOAD_MISS;
break;
case PERF_TYPE_RAW:
break;
default:
return -ENOENT;
}
return -EOPNOTSUPP;
}
static int mpc8xx_pmu_event_init(struct perf_event *event)
{
int type = event_type(event);
if (type < 0)
return type;
return 0;
}
static int mpc8xx_pmu_add(struct perf_event *event, int flags)
{
int type = event_type(event);
s64 val = 0;
if (type < 0)
return type;
switch (type) {
case PERF_8xx_ID_CPU_CYCLES:
val = get_tb();
break;
case PERF_8xx_ID_HW_INSTRUCTIONS:
if (atomic_inc_return(&insn_ctr_ref) == 1)
mtspr(SPRN_ICTRL, 0xc0080007);
val = get_insn_ctr();
break;
case PERF_8xx_ID_ITLB_LOAD_MISS:
val = itlb_miss_counter;
break;
case PERF_8xx_ID_DTLB_LOAD_MISS:
val = dtlb_miss_counter;
break;
}
local64_set(&event->hw.prev_count, val);
return 0;
}
static void mpc8xx_pmu_read(struct perf_event *event)
{
int type = event_type(event);
s64 prev, val = 0, delta = 0;
if (type < 0)
return;
do {
prev = local64_read(&event->hw.prev_count);
switch (type) {
case PERF_8xx_ID_CPU_CYCLES:
val = get_tb();
delta = 16 * (val - prev);
break;
case PERF_8xx_ID_HW_INSTRUCTIONS:
val = get_insn_ctr();
delta = prev - val;
if (delta < 0)
delta += 0x1000000000000LL;
break;
case PERF_8xx_ID_ITLB_LOAD_MISS:
val = itlb_miss_counter;
delta = (s64)((s32)val - (s32)prev);
break;
case PERF_8xx_ID_DTLB_LOAD_MISS:
val = dtlb_miss_counter;
delta = (s64)((s32)val - (s32)prev);
break;
}
} while (local64_cmpxchg(&event->hw.prev_count, prev, val) != prev);
local64_add(delta, &event->count);
}
static void mpc8xx_pmu_del(struct perf_event *event, int flags)
{
mpc8xx_pmu_read(event);
if (event_type(event) != PERF_8xx_ID_HW_INSTRUCTIONS)
return;
if (atomic_dec_return(&insn_ctr_ref) == 0)
mtspr(SPRN_ICTRL, 7);
}
static int init_mpc8xx_pmu(void)
{
mtspr(SPRN_ICTRL, 7);
mtspr(SPRN_CMPA, 0);
mtspr(SPRN_COUNTA, 0xffff);
return perf_pmu_register(&mpc8xx_pmu, "cpu", PERF_TYPE_RAW);
}

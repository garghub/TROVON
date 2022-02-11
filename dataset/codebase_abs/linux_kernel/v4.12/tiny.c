void F_1 ( void )
{
F_2 ( V_1 ) ;
}
void F_3 ( void )
{
F_2 ( V_2 ) ;
}
bool T_1 F_4 ( void )
{
return true ;
}
static int F_5 ( struct V_3 * V_4 )
{
F_6 (reset_cpu_stall_ticks(rcp);)
if ( V_4 -> V_5 != V_4 -> V_6 ) {
V_4 -> V_5 = V_4 -> V_6 ;
return 1 ;
}
return 0 ;
}
void F_7 ( void )
{
unsigned long V_7 ;
F_8 ( V_7 ) ;
if ( F_5 ( & V_8 ) +
F_5 ( & V_9 ) )
F_9 ( V_10 ) ;
F_10 ( V_7 ) ;
}
void F_11 ( void )
{
unsigned long V_7 ;
F_8 ( V_7 ) ;
if ( F_5 ( & V_9 ) )
F_9 ( V_10 ) ;
F_10 ( V_7 ) ;
}
void F_12 ( int V_11 )
{
F_6 (check_cpu_stalls();)
if ( V_11 )
F_7 () ;
else if ( ! F_13 () )
F_11 () ;
if ( V_11 )
F_14 ( V_12 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
const char * V_13 = NULL ;
struct V_14 * V_15 , * V_16 ;
unsigned long V_7 ;
F_6 (int cb_count = 0;)
F_8 ( V_7 ) ;
if ( V_4 -> V_5 == & V_4 -> V_17 ) {
F_10 ( V_7 ) ;
return;
}
F_6 (trace_rcu_batch_start(rcp->name, 0, rcp->qlen, -1);)
V_16 = V_4 -> V_17 ;
V_4 -> V_17 = * V_4 -> V_5 ;
* V_4 -> V_5 = NULL ;
if ( V_4 -> V_6 == V_4 -> V_5 )
V_4 -> V_6 = & V_4 -> V_17 ;
V_4 -> V_5 = & V_4 -> V_17 ;
F_10 ( V_7 ) ;
F_6 (rn = rcp->name;)
while ( V_16 ) {
V_15 = V_16 -> V_15 ;
F_16 ( V_15 ) ;
F_17 ( V_16 ) ;
F_18 () ;
F_19 ( V_13 , V_16 ) ;
F_20 () ;
V_16 = V_15 ;
F_6 (cb_count++;)
}
F_6 (rcu_trace_sub_qlen(rcp, cb_count);)
F_6 ( F_21 ( V_4 -> V_18 ,
V_19 , 0 , F_22 () ,
F_23 ( V_12 ) ,
false ) ) ;
}
static T_2 void F_24 ( struct V_20 * V_21 )
{
F_15 ( & V_8 ) ;
F_15 ( & V_9 ) ;
}
void F_25 ( void )
{
F_26 ( F_27 ( & V_22 ) ||
F_27 ( & V_23 ) ||
F_27 ( & V_24 ) ,
L_1 ) ;
}
static void F_28 ( struct V_14 * V_25 ,
T_3 V_26 ,
struct V_3 * V_4 )
{
unsigned long V_7 ;
F_29 ( V_25 ) ;
V_25 -> V_26 = V_26 ;
V_25 -> V_15 = NULL ;
F_8 ( V_7 ) ;
* V_4 -> V_6 = V_25 ;
V_4 -> V_6 = & V_25 -> V_15 ;
F_6 (rcp->qlen++;)
F_10 ( V_7 ) ;
if ( F_30 ( F_23 ( V_12 ) ) ) {
F_31 ( 0 ) ;
}
}
void V_2 ( struct V_14 * V_25 , T_3 V_26 )
{
F_28 ( V_25 , V_26 , & V_8 ) ;
}
void V_1 ( struct V_14 * V_25 , T_3 V_26 )
{
F_28 ( V_25 , V_26 , & V_9 ) ;
}
void T_4 F_32 ( void )
{
F_33 ( V_10 , F_24 ) ;
F_6 (reset_cpu_stall_ticks(&rcu_sched_ctrlblk);)
F_6 (reset_cpu_stall_ticks(&rcu_bh_ctrlblk);)
F_34 () ;
}

static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
unsigned int V_5 = ( unsigned long ) V_4 ;
struct V_6 * V_7 ;
F_2 ( & V_8 ) ;
F_3 (notify, &blk_mq_cpu_notify_list, list)
V_7 -> V_7 ( V_7 -> V_9 , V_3 , V_5 ) ;
F_4 ( & V_8 ) ;
return V_10 ;
}
static void F_5 ( void * V_9 , unsigned long V_3 ,
unsigned int V_5 )
{
if ( V_3 == V_11 || V_3 == V_12 ) {
struct V_13 * V_14 ;
struct V_15 * V_16 ;
F_6 () ;
V_14 = F_7 ( & F_8 ( V_17 , V_5 ) ) ;
while ( V_14 ) {
struct V_13 * V_18 = V_14 -> V_18 ;
V_16 = F_9 ( V_14 , struct V_15 , V_19 ) ;
F_10 ( V_16 , V_16 -> V_20 ) ;
V_14 = V_18 ;
}
F_11 () ;
}
}
void F_12 ( struct V_6 * V_21 )
{
F_13 ( ! V_21 -> V_7 ) ;
F_2 ( & V_8 ) ;
F_14 ( & V_21 -> V_22 , & V_23 ) ;
F_4 ( & V_8 ) ;
}
void F_15 ( struct V_6 * V_21 )
{
F_2 ( & V_8 ) ;
F_16 ( & V_21 -> V_22 ) ;
F_4 ( & V_8 ) ;
}
void F_17 ( struct V_6 * V_21 ,
void (* F_18)( void * , unsigned long , unsigned int ) ,
void * V_9 )
{
V_21 -> V_7 = F_18 ;
V_21 -> V_9 = V_9 ;
}
void T_1 F_19 ( void )
{
F_20 ( & V_24 ) ;
F_12 ( & V_25 ) ;
}

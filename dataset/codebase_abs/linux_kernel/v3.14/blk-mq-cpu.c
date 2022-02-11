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
void F_5 ( struct V_6 * V_11 )
{
F_6 ( ! V_11 -> V_7 ) ;
F_2 ( & V_8 ) ;
F_7 ( & V_11 -> V_12 , & V_13 ) ;
F_4 ( & V_8 ) ;
}
void F_8 ( struct V_6 * V_11 )
{
F_2 ( & V_8 ) ;
F_9 ( & V_11 -> V_12 ) ;
F_4 ( & V_8 ) ;
}
void F_10 ( struct V_6 * V_11 ,
void (* F_11)( void * , unsigned long , unsigned int ) ,
void * V_9 )
{
V_11 -> V_7 = F_11 ;
V_11 -> V_9 = V_9 ;
}
void T_1 F_12 ( void )
{
F_13 ( F_1 , 0 ) ;
}

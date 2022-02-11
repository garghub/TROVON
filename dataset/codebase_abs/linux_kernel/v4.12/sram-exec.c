int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
unsigned long V_7 = ( unsigned long ) V_6 -> V_7 ;
unsigned long V_8 = V_7 + V_4 -> V_9 ;
if ( ! F_2 ( V_7 ) || ! F_2 ( V_8 ) ) {
F_3 ( V_2 -> V_10 ,
L_1 ) ;
return - V_11 ;
}
return 0 ;
}
int F_4 ( struct V_5 * V_6 )
{
F_5 ( & V_12 ) ;
F_6 ( & V_6 -> V_13 , & V_14 ) ;
F_7 ( & V_12 ) ;
return 0 ;
}
int F_8 ( struct V_15 * V_16 , void * V_17 , void * V_18 ,
T_1 V_9 )
{
struct V_5 * V_6 = NULL , * V_19 ;
unsigned long V_7 ;
int V_20 ;
F_5 ( & V_12 ) ;
F_9 (p, &exec_pool_list, list) {
if ( V_19 -> V_16 == V_16 )
V_6 = V_19 ;
}
F_7 ( & V_12 ) ;
if ( ! V_6 )
return - V_21 ;
if ( ! F_10 ( V_16 , ( unsigned long ) V_17 , V_9 ) )
return - V_21 ;
V_7 = ( unsigned long ) V_6 -> V_7 ;
V_20 = F_11 ( V_9 ) / V_22 ;
F_5 ( & V_6 -> V_23 ) ;
F_12 ( ( unsigned long ) V_7 , V_20 ) ;
F_13 ( ( unsigned long ) V_7 , V_20 ) ;
memcpy ( V_17 , V_18 , V_9 ) ;
F_14 ( ( unsigned long ) V_7 , V_20 ) ;
F_15 ( ( unsigned long ) V_7 , V_20 ) ;
F_7 ( & V_6 -> V_23 ) ;
return 0 ;
}

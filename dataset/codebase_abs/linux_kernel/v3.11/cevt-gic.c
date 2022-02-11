static int F_1 ( unsigned long V_1 , struct V_2 * V_3 )
{
T_1 V_4 ;
int V_5 ;
V_4 = F_2 () ;
V_4 += ( T_1 ) V_1 ;
F_3 ( V_4 ) ;
V_5 = ( ( int ) ( F_2 () - V_4 ) >= 0 ) ? - V_6 : 0 ;
return V_5 ;
}
void F_4 ( enum V_7 V_8 ,
struct V_2 * V_3 )
{
}
T_2 F_5 ( int V_9 , void * V_10 )
{
struct V_2 * V_11 ;
int V_12 = F_6 () ;
F_3 ( F_7 () ) ;
V_11 = & F_8 ( V_13 , V_12 ) ;
V_11 -> V_14 ( V_11 ) ;
return V_15 ;
}
void F_9 ( struct V_2 * V_16 )
{
}
int F_10 ( void )
{
unsigned int V_12 = F_6 () ;
struct V_2 * V_11 ;
unsigned int V_9 ;
if ( ! V_17 || ! V_18 )
return - V_19 ;
V_9 = V_20 ;
V_11 = & F_8 ( V_13 , V_12 ) ;
V_11 -> V_21 = L_1 ;
V_11 -> V_22 = V_23 ;
F_11 ( V_11 , V_18 ) ;
V_11 -> V_24 = F_12 ( 0x7fffffff , V_11 ) ;
V_11 -> V_25 = F_12 ( 0x300 , V_11 ) ;
V_11 -> V_26 = 300 ;
V_11 -> V_9 = V_9 ;
V_11 -> V_27 = F_13 ( V_12 ) ;
V_11 -> V_28 = F_1 ;
V_11 -> V_29 = F_4 ;
V_11 -> V_14 = F_9 ;
F_14 ( V_11 ) ;
F_15 ( F_16 ( V_30 , V_31 ) , 0x80000002 ) ;
F_15 ( F_16 ( V_30 , V_32 ) , V_33 ) ;
if ( V_34 )
return 0 ;
V_34 = 1 ;
F_17 ( V_9 , & V_35 ) ;
F_18 ( V_9 , V_36 ) ;
return 0 ;
}

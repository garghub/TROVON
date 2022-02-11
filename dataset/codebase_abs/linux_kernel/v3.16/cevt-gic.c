static int F_1 ( unsigned long V_1 , struct V_2 * V_3 )
{
T_1 V_4 ;
int V_5 ;
V_4 = F_2 () ;
V_4 += ( T_1 ) V_1 ;
F_3 ( V_4 , F_4 ( V_3 -> V_6 ) ) ;
V_5 = ( ( int ) ( F_2 () - V_4 ) >= 0 ) ? - V_7 : 0 ;
return V_5 ;
}
void F_5 ( enum V_8 V_9 ,
struct V_2 * V_3 )
{
}
T_2 F_6 ( int V_10 , void * V_11 )
{
struct V_2 * V_12 ;
int V_13 = F_7 () ;
F_8 ( F_9 () ) ;
V_12 = & F_10 ( V_14 , V_13 ) ;
V_12 -> V_15 ( V_12 ) ;
return V_16 ;
}
void F_11 ( struct V_2 * V_17 )
{
}
int F_12 ( void )
{
unsigned int V_13 = F_7 () ;
struct V_2 * V_12 ;
unsigned int V_10 ;
if ( ! V_18 || ! V_19 )
return - V_20 ;
V_10 = V_21 ;
V_12 = & F_10 ( V_14 , V_13 ) ;
V_12 -> V_22 = L_1 ;
V_12 -> V_23 = V_24 |
V_25 ;
F_13 ( V_12 , V_19 ) ;
V_12 -> V_26 = F_14 ( 0x7fffffff , V_12 ) ;
V_12 -> V_27 = F_14 ( 0x300 , V_12 ) ;
V_12 -> V_28 = 300 ;
V_12 -> V_10 = V_10 ;
V_12 -> V_6 = F_15 ( V_13 ) ;
V_12 -> V_29 = F_1 ;
V_12 -> V_30 = F_5 ;
V_12 -> V_15 = F_11 ;
F_16 ( V_12 ) ;
F_17 ( F_18 ( V_31 , V_32 ) , 0x80000002 ) ;
F_17 ( F_18 ( V_31 , V_33 ) , V_34 ) ;
if ( V_35 )
return 0 ;
V_35 = 1 ;
F_19 ( V_10 , & V_36 ) ;
F_20 ( V_10 , V_37 ) ;
return 0 ;
}

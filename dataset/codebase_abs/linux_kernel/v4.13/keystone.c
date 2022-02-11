static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
if ( V_3 != V_7 )
return V_8 ;
if ( ! V_6 )
return V_9 ;
if ( ! V_6 -> V_10 ) {
V_6 -> V_11 = V_12 ;
F_2 ( V_6 , L_1 ,
V_6 -> V_11 ) ;
}
return V_13 ;
}
static void T_1 F_3 ( void )
{
if ( V_14 >= V_15 ) {
V_12 = F_4 ( V_15 -
V_16 ) ;
F_5 ( & V_17 , & V_18 ) ;
}
F_6 () ;
}
static long long T_1 F_7 ( void )
{
long long V_19 ;
T_2 V_20 , V_21 ;
V_20 = F_8 () ;
V_21 = F_9 () ;
if ( V_20 >= V_16 &&
V_21 <= V_22 )
return 0 ;
if ( V_20 < V_15 ||
V_21 > V_23 ) {
F_10 ( L_2 ,
( V_24 ) V_20 , ( V_24 ) V_21 ) ;
return 0 ;
}
V_19 = V_15 - V_16 ;
V_25 = - V_19 ;
return V_19 ;
}

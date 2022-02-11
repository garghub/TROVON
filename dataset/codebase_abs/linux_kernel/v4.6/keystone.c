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
F_7 ( NULL , V_19 , NULL , NULL ) ;
}
static unsigned long F_8 ( unsigned long V_20 )
{
return ( V_21 ) ( V_20 ) - V_22 + V_16 ;
}
static long long T_1 F_9 ( void )
{
long long V_23 ;
V_21 V_24 , V_25 ;
V_24 = F_10 () ;
V_25 = F_11 () ;
if ( V_24 >= V_16 &&
V_25 <= V_26 )
return 0 ;
if ( V_24 < V_15 ||
V_25 > V_27 ) {
F_12 ( L_2 ,
( V_28 ) V_24 , ( V_28 ) V_25 ) ;
return 0 ;
}
V_23 = V_15 - V_16 ;
V_29 = F_8 ;
return V_23 ;
}

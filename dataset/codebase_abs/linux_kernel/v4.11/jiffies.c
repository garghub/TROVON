static T_1 F_1 ( struct V_1 * V_2 )
{
return ( T_1 ) V_3 ;
}
T_1 F_2 ( void )
{
unsigned long V_4 ;
T_1 V_5 ;
do {
V_4 = F_3 ( & V_6 ) ;
V_5 = V_7 ;
} while ( F_4 ( & V_6 , V_4 ) );
return V_5 ;
}
static int T_2 F_5 ( void )
{
return F_6 ( & V_8 ) ;
}
struct V_1 * T_2 __weak F_7 ( void )
{
return & V_8 ;
}
int F_8 ( long V_9 )
{
T_1 V_10 , V_11 ;
long V_12 ;
V_13 = V_8 ;
V_13 . V_14 = L_1 ;
V_13 . V_15 ++ ;
V_12 = ( V_9 + V_16 / 2 ) / V_16 ;
V_11 = ( T_1 ) V_9 << 8 ;
V_11 += V_12 / 2 ;
F_9 ( V_11 , V_12 ) ;
V_10 = ( T_1 ) V_17 << 8 ;
V_10 += ( V_18 ) V_11 / 2 ;
F_9 ( V_10 , ( V_18 ) V_11 ) ;
V_13 . V_19 = ( ( V_18 ) V_10 ) << V_20 ;
F_6 ( & V_13 ) ;
return 0 ;
}

static int T_1 F_1 ( void )
{
if ( ! V_1 )
return 0 ;
V_2 . V_3 = NULL ;
V_2 . V_4 = V_1 ;
V_2 . V_5 = V_6 ;
V_2 . V_7 = V_8 | V_9 | V_10 | V_11 ;
V_2 . V_12 = V_13 ;
V_2 . V_7 |= V_14 ;
return 0 ;
}
struct V_15 * F_2 ( struct V_16 * V_17 )
{
return V_1 ? & V_2 : NULL ;
}
int F_3 ( unsigned long V_18 )
{
if ( ! V_1 )
return 0 ;
if ( ( V_18 >= V_1 ) && ( V_18 < V_6 ) )
return 1 ;
return 0 ;
}
int F_4 ( struct V_16 * V_17 , unsigned long V_18 )
{
struct V_15 * V_19 = F_2 ( V_17 ) ;
if ( ! V_19 )
return 0 ;
return ( V_18 >= V_19 -> V_4 ) && ( V_18 < V_19 -> V_5 ) ;
}

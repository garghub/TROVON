static int T_1 F_1 ( void )
{
if ( ! V_1 )
return 0 ;
V_2 . V_3 = NULL ;
V_2 . V_4 = V_1 ;
V_2 . V_5 = V_6 ;
V_2 . V_7 = V_8 | V_9 | V_10 | V_11 ;
V_2 . V_12 = V_13 ;
return 0 ;
}
struct V_14 * F_2 ( struct V_15 * V_16 )
{
return V_1 ? & V_2 : NULL ;
}
int F_3 ( unsigned long V_17 )
{
if ( ! V_1 )
return 0 ;
if ( ( V_17 >= V_1 ) && ( V_17 < V_6 ) )
return 1 ;
return 0 ;
}
int F_4 ( struct V_15 * V_16 , unsigned long V_17 )
{
struct V_14 * V_18 = F_2 ( V_16 ) ;
if ( ! V_18 )
return 0 ;
return ( V_17 >= V_18 -> V_4 ) && ( V_17 < V_18 -> V_5 ) ;
}

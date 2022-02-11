static inline int F_1 ( void )
{
if ( V_1 -> V_2 & V_3 )
return 1 ;
if ( F_2 ( V_4 ) == V_5 )
return 1 ;
return V_6 ;
}
static unsigned long F_3 ( void )
{
unsigned long V_7 = 0 ;
if ( V_1 -> V_8 & V_9 ) {
if ( F_4 () )
V_7 = ( long ) ( F_5 () % ( 1 << ( 22 - V_10 ) ) ) ;
else
V_7 = ( long ) ( F_5 () % ( 1 << ( 29 - V_10 ) ) ) ;
}
return ( V_7 << V_10 ) * 2 ;
}
static inline unsigned long F_6 ( void )
{
unsigned long V_11 = F_2 ( V_4 ) ;
if ( V_11 < V_12 )
V_11 = V_12 ;
else if ( V_11 > V_13 )
V_11 = V_13 ;
return F_7 ( V_14 - V_11 - F_3 () ) ;
}
void F_8 ( struct V_15 * V_16 )
{
if ( F_1 () ) {
V_16 -> F_6 = V_17 ;
V_16 -> V_18 = V_19 ;
V_16 -> V_20 = V_21 ;
} else {
V_16 -> F_6 = F_6 () ;
V_16 -> V_18 = V_22 ;
V_16 -> V_20 = V_23 ;
}
}

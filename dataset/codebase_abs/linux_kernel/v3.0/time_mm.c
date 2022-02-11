static inline int F_1 ( unsigned long V_1 )
{
if ( V_2 )
return V_2 ( V_1 ) ;
return - 1 ;
}
static T_1 F_2 ( int V_3 , void * V_4 )
{
F_3 ( 1 ) ;
F_4 ( F_5 ( F_6 () ) ) ;
F_7 ( V_5 ) ;
#ifdef F_8
if ( V_6 ) {
static unsigned V_7 = 0 , V_8 = 0 , V_9 = 0 ;
if ( V_7 == 0 || V_7 == V_9 )
V_6 ( 1 ) ;
else if ( V_7 == 7 || V_7 == V_9 + 7 )
V_6 ( 0 ) ;
if ( ++ V_7 > V_8 ) {
V_7 = 0 ;
V_8 = ( ( 672 << V_10 ) / ( 5 * V_11 [ 0 ] + ( 7 << V_10 ) ) ) + 30 ;
V_9 = V_8 / 4 ;
}
}
#endif
return V_12 ;
}
void F_9 ( struct V_13 * V_14 )
{
struct V_15 time ;
V_14 -> V_16 = 0 ;
V_14 -> V_17 = 0 ;
if ( V_18 ) {
V_18 ( 0 , & time ) ;
if ( ( time . V_19 += 1900 ) < 1970 )
time . V_19 += 100 ;
V_14 -> V_16 = mktime ( time . V_19 , time . V_20 , time . V_21 ,
time . V_22 , time . V_23 , time . V_24 ) ;
}
}
void T_2 F_10 ( void )
{
F_11 ( F_2 ) ;
}
T_3 F_12 ( void )
{
return F_13 () * 1000 ;
}
static int T_2 F_14 ( void )
{
struct V_25 * V_26 ;
if ( ! V_18 )
return - V_27 ;
V_26 = F_15 ( L_1 , - 1 , NULL , 0 ) ;
if ( F_16 ( V_26 ) )
return F_17 ( V_26 ) ;
return 0 ;
}

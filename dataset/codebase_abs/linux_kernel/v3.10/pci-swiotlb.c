static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 ,
struct V_6 * V_7 )
{
if ( V_2 -> V_8 != F_2 ( 64 ) )
V_5 |= V_9 ;
return F_3 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_10 , T_2 V_11 ,
struct V_6 * V_7 )
{
F_5 ( V_2 , V_3 , V_10 , V_11 ) ;
}
void T_4 F_6 ( void )
{
V_12 = & V_13 ;
F_7 ( 1 ) ;
}
void T_4 F_8 ( void )
{
if ( ! V_14 ) {
#ifdef F_9
V_15 = 1 ;
F_10 ( V_16 L_1 ) ;
F_11 ( L_2 ) ;
F_7 ( 1 ) ;
V_12 = & V_13 ;
#else
F_12 ( L_3 ) ;
#endif
}
}

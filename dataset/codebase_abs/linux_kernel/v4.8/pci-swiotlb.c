static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 ,
unsigned long V_6 )
{
if ( V_2 -> V_7 != F_2 ( 64 ) )
V_5 |= V_8 ;
return F_3 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_9 , T_2 V_10 ,
unsigned long V_6 )
{
F_5 ( V_2 , V_3 , V_9 , V_10 ) ;
}
void T_4 F_6 ( void )
{
V_11 = & V_12 ;
F_7 ( 1 ) ;
}
void T_4 F_8 ( void )
{
if ( ! V_13 ) {
#ifdef F_9
V_14 = 1 ;
F_10 ( V_15 L_1 ) ;
F_11 ( L_2 ) ;
F_7 ( 1 ) ;
V_11 = & V_12 ;
#else
F_12 ( L_3 ) ;
#endif
}
}

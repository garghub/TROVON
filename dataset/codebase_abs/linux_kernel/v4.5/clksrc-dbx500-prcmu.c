static T_1 T_2 F_1 ( struct V_1 * V_2 )
{
void T_3 * V_3 = V_4 ;
T_4 V_5 , V_6 ;
do {
V_5 = F_2 ( V_3 + V_7 ) ;
V_6 = F_2 ( V_3 + V_7 ) ;
} while ( V_6 != V_5 );
return ~ V_5 ;
}
static T_5 T_2 F_3 ( void )
{
if ( F_4 ( ! V_4 ) )
return 0 ;
return F_1 ( & V_8 ) ;
}
static void T_6 F_5 ( struct V_9 * V_10 )
{
V_4 = F_6 ( V_10 , 0 ) ;
if ( F_7 ( V_4 + V_11 ) !=
V_12 ) {
F_8 ( V_12 ,
V_4 + V_11 ) ;
F_8 ( V_13 ,
V_4 + V_14 ) ;
}
#ifdef F_9
F_10 ( F_3 , 32 , V_15 ) ;
#endif
F_11 ( & V_8 , V_15 ) ;
}

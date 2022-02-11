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
void T_6 F_5 ( void T_3 * V_3 )
{
V_4 = V_3 ;
if ( F_6 ( V_4 + V_9 ) !=
V_10 ) {
F_7 ( V_10 ,
V_4 + V_9 ) ;
F_7 ( V_11 ,
V_4 + V_12 ) ;
}
#ifdef F_8
F_9 ( F_3 , 32 , V_13 ) ;
#endif
F_10 ( & V_8 , V_13 ) ;
}

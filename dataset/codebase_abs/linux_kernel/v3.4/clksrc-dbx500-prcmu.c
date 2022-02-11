static T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 , V_4 ;
do {
V_3 = F_2 ( V_5 +
V_6 ) ;
V_4 = F_2 ( V_5 +
V_6 ) ;
} while ( V_4 != V_3 );
return ~ V_3 ;
}
static T_2 T_3 F_3 ( void )
{
if ( F_4 ( ! V_5 ) )
return 0 ;
return F_1 ( & V_7 ) ;
}
void T_4 F_5 ( void T_5 * V_8 )
{
V_5 = V_8 ;
if ( F_2 ( V_5 + V_9 ) !=
V_10 ) {
F_6 ( V_10 ,
V_5 + V_9 ) ;
F_6 ( V_11 ,
V_5 + V_12 ) ;
}
#ifdef F_7
F_8 ( F_3 ,
32 , V_13 ) ;
#endif
F_9 ( & V_7 , V_13 ) ;
}

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
unsigned long long T_3 F_3 ( void )
{
T_2 V_7 ;
if ( F_4 ( ! V_5 ) )
return 0 ;
V_7 = F_1 ( & V_8 ) ;
return F_5 ( & V_9 , V_7 , ( T_2 ) ~ 0 ) ;
}
static void T_3 F_6 ( void )
{
T_2 V_7 = F_1 ( & V_8 ) ;
F_7 ( & V_9 , V_7 , ( T_2 ) ~ 0 ) ;
}
void T_4 F_8 ( void T_5 * V_10 )
{
V_5 = V_10 ;
if ( F_2 ( V_5 + V_11 ) !=
V_12 ) {
F_9 ( V_12 ,
V_5 + V_11 ) ;
F_9 ( V_13 ,
V_5 + V_14 ) ;
}
#ifdef F_10
F_11 ( & V_9 , F_6 ,
32 , V_15 ) ;
#endif
F_12 ( & V_8 ,
V_15 , V_16 ) ;
F_13 ( & V_8 ) ;
}

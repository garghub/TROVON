static T_1 F_1 ( void )
{
#ifdef F_2
return F_2 ;
#else
return F_3 ( V_1 ) ;
#endif
}
void * F_4 ( T_2 V_2 , T_1 V_3 )
{
T_3 * V_4 ;
T_2 V_5 ;
T_1 V_6 ;
int V_7 ;
V_7 = F_5 ( V_8 , V_9 | V_10 ) ;
if ( V_7 < 0 ) {
fprintf ( V_11 , L_1 , V_8 ) ;
return ( NULL ) ;
}
V_6 = F_1 () ;
V_5 = V_2 % V_6 ;
V_4 = F_6 ( NULL , ( V_3 + V_5 ) , V_12 , V_13 ,
V_7 , ( V_2 - V_5 ) ) ;
if ( V_4 == V_14 ) {
fprintf ( V_11 , L_2 , V_8 ) ;
F_7 ( V_7 ) ;
return ( NULL ) ;
}
F_7 ( V_7 ) ;
return ( F_8 ( V_4 + V_5 ) ) ;
}
void F_9 ( void * V_2 , T_1 V_3 )
{
T_2 V_5 ;
T_1 V_6 ;
V_6 = F_1 () ;
V_5 = F_10 ( V_2 ) % V_6 ;
F_11 ( ( T_3 * ) V_2 - V_5 , ( V_3 + V_5 ) ) ;
}

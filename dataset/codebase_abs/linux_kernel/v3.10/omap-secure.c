T_1 F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 )
{
T_1 V_8 ;
T_1 V_9 [ 5 ] ;
V_9 [ 0 ] = V_3 ;
V_9 [ 1 ] = V_4 ;
V_9 [ 2 ] = V_5 ;
V_9 [ 3 ] = V_6 ;
V_9 [ 4 ] = V_7 ;
F_2 () ;
F_3 ( F_4 ( V_9 ) , F_4 ( V_9 + 5 ) ) ;
V_8 = F_5 ( V_1 , V_2 , F_4 ( V_9 ) ) ;
return V_8 ;
}
int T_2 F_6 ( void )
{
T_1 V_10 = V_11 ;
V_10 = F_7 ( V_10 , V_12 ) ;
V_13 = F_8 ( V_10 , V_12 ) ;
return 0 ;
}
T_3 F_9 ( void )
{
return V_13 ;
}

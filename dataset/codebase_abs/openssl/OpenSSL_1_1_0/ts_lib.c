int F_1 ( T_1 * V_1 , const T_2 * V_2 )
{
T_3 * V_3 ;
int V_4 = 0 ;
char * V_5 ;
V_3 = F_2 () ;
if ( V_3 == NULL )
return - 1 ;
F_3 ( V_2 , V_3 ) ;
if ( ( V_5 = F_4 ( V_3 ) ) ) {
V_4 = F_5 ( V_1 , L_1 , 2 ) > 0 ;
V_4 = V_4 && F_5 ( V_1 , V_5 , strlen ( V_5 ) ) > 0 ;
F_6 ( V_5 ) ;
}
F_7 ( V_3 ) ;
return V_4 ;
}
int F_8 ( T_1 * V_1 , const T_4 * V_6 )
{
char V_7 [ 128 ] ;
F_9 ( V_7 , sizeof( V_7 ) , V_6 , 0 ) ;
F_10 ( V_1 , L_2 , V_7 ) ;
return 1 ;
}
int F_11 ( T_1 * V_1 , const T_5 * V_8 )
{
int V_9 = F_12 ( V_8 -> V_10 ) ;
return F_10 ( V_1 , L_3 ,
( V_9 == V_11 ) ? L_4 : F_13 ( V_9 ) ) ;
}
int F_14 ( T_1 * V_1 , T_6 * V_12 )
{
T_7 * V_13 ;
F_11 ( V_1 , V_12 -> V_14 ) ;
F_10 ( V_1 , L_5 ) ;
V_13 = V_12 -> V_15 ;
F_15 ( V_1 , ( const char * ) F_16 ( V_13 ) ,
F_17 ( V_13 ) , 4 ) ;
return 1 ;
}

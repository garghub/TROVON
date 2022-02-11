int F_1 (
unsigned char V_1 ,
unsigned char V_2 ,
unsigned char V_3 ,
unsigned char V_4 ,
unsigned char V_5 ,
unsigned char V_6 ,
unsigned char V_7 ,
unsigned char V_8 ,
unsigned char V_9 ,
unsigned char V_10
)
{
T_1 * V_11 ;
V_11 = V_12 ;
if ( V_11 -> V_13 != NULL ) {
return V_11 -> V_13 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , V_6 , V_7 , V_8 ,
V_9 , V_10 ) ;
}
return - 1 ;
}
unsigned short F_2 ( void )
{
T_1 * V_11 ;
V_11 = V_12 ;
if ( V_11 != ( T_1 * ) 0 )
return V_11 -> V_14 () ;
return 0x0000 ;
}
unsigned short F_3 ( void )
{
T_1 * V_11 ;
V_11 = V_12 ;
if ( V_11 != ( T_1 * ) 0 )
return V_11 -> V_15 () ;
return 0x0000 ;
}

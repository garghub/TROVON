static void F_1 ( T_1 * V_1 , const unsigned char V_2 ,
const unsigned char V_3 )
{
int V_4 = V_5 ;
if ( V_2 == V_6 ) {
if ( V_3 == V_7 )
V_4 = V_8 ;
else if ( V_3 == V_9 )
V_4 = V_10 ;
}
if ( V_4 == V_5 )
F_2 ( V_1 , L_1 , V_2 , V_3 ) ;
else
F_2 ( V_1 , L_2 , F_3 ( V_4 ) ) ;
}
static void F_4 ( T_1 * V_1 , T_2 V_11 )
{
T_3 * V_12 ;
char V_13 [ 20 ] ;
V_12 = F_5 () ;
F_6 ( V_12 , ( V_14 ) 0 ,
( int ) ( V_11 / 86400000 ) ,
( V_11 % 86400000 ) / 1000 ) ;
F_7 ( V_13 , sizeof( V_13 ) , L_3 ,
F_8 ( V_12 ) , ( unsigned int ) ( V_11 % 1000 ) ) ;
F_9 ( V_12 , V_13 ) ;
F_10 ( V_1 , V_12 ) ;
F_11 ( V_12 ) ;
}
static void F_12 ( T_4 * V_15 )
{
if ( V_15 ) {
if ( V_15 -> V_15 )
F_13 ( V_15 -> V_15 ) ;
F_13 ( V_15 ) ;
}
}

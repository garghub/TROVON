void F_1 ( const T_1 V_1 )
{
V_2 = V_1 ;
V_3 . V_4 = 0 ;
V_3 . V_5 = 0 ;
}
void F_2 ( const T_2 V_1 )
{
T_3 V_6 = V_7 ;
T_4 V_8 = 1 ;
T_4 V_4 = 0 ;
T_4 V_5 = 0 ;
V_9 = V_1 ;
F_3 ( V_1 + V_10 ,
& V_6 , sizeof( T_3 ) ) ;
F_3 ( V_1 + V_11 ,
& V_4 , sizeof( T_4 ) ) ;
F_3 ( V_1 + V_12 ,
& V_5 , sizeof( T_4 ) ) ;
F_3 ( V_1 + V_13 ,
& V_8 , sizeof( T_4 ) ) ;
V_3 . V_4 = 0 ;
V_3 . V_5 = 0 ;
}
void F_4 ( const T_3 V_6 )
{
assert ( V_2 != ( ( T_1 ) - 1 ) ) ;
F_5 ( V_14 ,
V_2 + V_15 , V_6 ) ;
}

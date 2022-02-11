T_1
F_1 ( T_2 * V_1 , T_3 V_2 )
{
const T_4 * V_3 ;
F_2 ( V_1 , 0 , V_2 ) ;
V_3 = F_3 ( V_1 , 0 , V_2 ) ;
return ( F_4 ( V_3 , V_2 , V_4 ) ) ;
}
T_1
F_5 ( T_2 * V_1 , T_3 V_5 , T_3 V_2 )
{
const T_4 * V_3 ;
F_2 ( V_1 , V_5 , V_2 ) ;
V_3 = F_3 ( V_1 , V_5 , V_2 ) ;
return ( F_6 ( V_3 , V_2 ) ) ;
}
T_1
F_7 ( T_2 * V_1 , T_3 V_2 , T_1 V_6 )
{
const T_4 * V_3 ;
F_2 ( V_1 , 0 , V_2 ) ;
V_3 = F_3 ( V_1 , 0 , V_2 ) ;
return ( F_4 ( V_3 , V_2 , V_6 ) ) ;
}
T_1
F_8 ( T_2 * V_1 , T_3 V_5 , T_3 V_2 ,
T_1 V_6 )
{
const T_4 * V_3 ;
F_2 ( V_1 , V_5 , V_2 ) ;
V_3 = F_3 ( V_1 , V_5 , V_2 ) ;
return ( F_4 ( V_3 , V_2 , V_6 ) ) ;
}
T_1
F_9 ( T_2 * V_1 , T_3 V_2 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_2 ) ;
V_7 = ( ( unsigned char ) ( V_7 >> 0 ) << 24 ) |
( ( unsigned char ) ( V_7 >> 8 ) << 16 ) |
( ( unsigned char ) ( V_7 >> 16 ) << 8 ) |
( ( unsigned char ) ( V_7 >> 24 ) << 0 ) ;
return ( V_7 ) ;
}
T_1
F_10 ( T_2 * V_1 , T_3 V_5 ,
T_3 V_2 , T_1 V_6 )
{
const T_4 * V_3 ;
F_2 ( V_1 , V_5 , V_2 ) ;
V_3 = F_3 ( V_1 , V_5 , V_2 ) ;
return ( F_11 ( V_3 , V_2 , V_6 ) ) ;
}
T_1
F_12 ( T_2 * V_1 , T_3 V_2 )
{
return ( F_10 ( V_1 , 0 , V_2 , V_8 ) ) ;
}
T_1
F_13 ( T_2 * V_1 , T_3 V_5 , T_3 V_2 )
{
return ( F_10 ( V_1 , V_5 , V_2 , V_8 ) ) ;
}
T_1
F_14 ( T_2 * V_1 , T_3 V_2 , T_1 V_6 )
{
return ( F_10 ( V_1 , 0 , V_2 , V_6 ) ) ;
}

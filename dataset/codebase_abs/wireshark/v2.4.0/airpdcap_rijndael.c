T_1 *
F_1 ( T_1 * V_1 , T_2 V_2 , T_1 * V_3 , T_2 V_4 )
{
T_1 * V_5 ;
T_1 V_6 [ 8 ] , V_7 [ 16 ] ;
T_1 * V_8 ;
T_3 V_9 , V_10 , V_11 ;
T_4 V_12 ;
if ( V_1 == NULL || V_4 < 16 || V_3 == NULL ) {
return NULL ;
}
V_5 = ( V_13 * ) F_2 ( V_4 ) ;
V_11 = ( V_4 / 8 ) - 1 ;
memcpy ( V_6 , V_3 , 8 ) ;
V_8 = V_5 ;
memcpy ( V_8 , V_3 + 8 , V_4 - 8 ) ;
if ( F_3 ( & V_12 , V_14 , V_15 , 0 ) ) {
return V_5 ;
}
if ( F_4 ( V_12 , V_1 , V_2 ) ) {
F_5 ( V_12 ) ;
return V_5 ;
}
for ( V_10 = 5 ; V_10 >= 0 ; -- V_10 ) {
V_8 = V_5 + ( V_11 - 1 ) * 8 ;
for ( V_9 = V_11 ; V_9 >= 1 ; -- V_9 ) {
T_2 V_16 = ( V_11 * V_10 ) + V_9 ;
memcpy ( V_7 , V_6 , 8 ) ;
V_7 [ 7 ] ^= V_16 ;
memcpy ( V_7 + 8 , V_8 , 8 ) ;
F_6 ( V_12 , V_7 , 16 , NULL , 0 ) ;
memcpy ( V_6 , V_7 , 8 ) ;
memcpy ( V_8 , V_7 + 8 , 8 ) ;
V_8 -= 8 ;
}
}
F_5 ( V_12 ) ;
return V_5 ;
}

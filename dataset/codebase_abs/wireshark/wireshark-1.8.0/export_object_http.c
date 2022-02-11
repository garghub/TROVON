static int
F_1 ( void * V_1 , T_1 * V_2 , T_2 * T_3 V_3 ,
const void * V_4 )
{
T_4 * V_5 = V_1 ;
const T_5 * V_6 = V_4 ;
T_6 * V_7 ;
if( V_6 ) {
V_7 = F_2 ( sizeof( T_6 ) ) ;
V_7 -> V_8 = V_2 -> V_9 -> V_10 ;
V_7 -> V_11 = F_3 ( V_6 -> V_11 ) ;
V_7 -> V_12 = F_3 ( V_6 -> V_12 ) ;
V_7 -> V_13 = F_3 ( F_4 ( V_6 -> V_13 ) ) ;
V_7 -> V_14 = V_6 -> V_14 ;
V_7 -> V_15 = F_5 ( V_6 -> V_15 ,
V_6 -> V_14 ) ;
V_5 -> V_16 =
F_6 ( V_5 -> V_16 , V_7 ) ;
return 1 ;
} else {
return 0 ;
}
}
void
F_7 ( T_7 * T_8 V_3 , T_9 V_4 V_3 )
{
F_8 ( L_1 , L_2 , F_1 , NULL ) ;
}

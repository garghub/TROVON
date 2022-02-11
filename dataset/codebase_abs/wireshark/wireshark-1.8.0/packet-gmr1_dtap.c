static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 , V_5 ;
T_5 V_6 ;
const T_6 * V_7 ;
T_7 V_8 ;
int V_9 ;
T_8 * V_10 = NULL ;
T_3 * V_11 = NULL ;
T_4 V_12 [ 2 ] ;
T_9 V_13 ;
V_4 = F_2 ( V_1 ) ;
V_5 = 0 ;
V_12 [ 0 ] = F_3 ( V_1 , V_5 ++ ) ;
if ( ( V_12 [ 0 ] & V_14 ) == V_15 )
V_13 = V_12 [ 0 ] & 0xff ;
else
V_13 = V_12 [ 0 ] & 0x0f ;
if ( V_13 != V_16 ) {
F_4 ( V_17 , V_1 , V_2 , V_3 ) ;
return;
}
F_5 ( V_2 -> V_18 , V_19 , L_1 ) ;
F_6 ( V_2 -> V_18 , V_19 , L_2 ,
F_7 ( V_13 , V_20 , L_3 ) ) ;
V_12 [ 1 ] = F_3 ( V_1 , V_5 ) ;
F_8 ( V_13 , V_12 [ 1 ] , & V_7 , & V_8 , & V_9 , & V_6 ) ;
if ( V_7 == NULL )
{
V_10 = F_9 (
V_3 , V_21 , V_1 , 0 , V_4 ,
L_4 , V_12 [ 1 ] ) ;
V_11 = F_10 ( V_10 , V_22 ) ;
F_6 ( V_2 -> V_18 , V_19 , L_5 , V_12 [ 1 ] ) ;
}
else
{
V_10 = F_9 (
V_3 , V_21 , V_1 , 0 , - 1 ,
L_6 , V_7 ) ;
V_11 = F_10 ( V_10 , V_22 ) ;
F_6 ( V_2 -> V_18 , V_19 , L_7 , V_7 ) ;
}
V_5 = 0 ;
F_11 (
V_11 , V_1 , 1 , 1 ,
L_8 ,
F_7 ( V_13 , V_23 , L_3 )
) ;
V_5 ++ ;
F_12 (
V_11 , V_9 , V_1 , V_5 , 1 , V_12 [ 1 ] ,
L_9 , V_7 ? V_7 : L_10
) ;
V_5 ++ ;
if ( V_6 ) {
(* V_6)( V_1 , V_11 , V_2 , V_5 , V_4 - V_5 ) ;
} else {
F_11 ( V_11 , V_1 , V_5 , V_4 - V_5 ,
L_11 ) ;
}
return;
}
void
F_13 ( void )
{
#if 0
static hf_register_info hf[] = {
};
#endif
static T_7 * V_24 [] = {
& V_22 ,
& V_25 ,
} ;
F_14 ( V_24 , F_15 ( V_24 ) ) ;
V_21 = F_16 ( L_12 , L_13 , L_14 ) ;
#if 0
proto_register_field_array(proto_gmr1_dtap, hf, array_length(hf));
#endif
F_17 ( L_14 , F_1 , V_21 ) ;
}
void
F_18 ( void )
{
T_10 V_26 ;
V_26 = F_19 ( L_14 ) ;
F_20 ( L_15 , 0 , V_26 ) ;
F_20 ( L_15 , 3 , V_26 ) ;
V_27 = F_19 ( L_16 ) ;
V_17 = F_19 ( L_17 ) ;
}

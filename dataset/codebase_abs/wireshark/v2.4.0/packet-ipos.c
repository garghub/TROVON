static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 = NULL ;
T_3 * V_6 = NULL ;
T_1 * V_7 ;
int V_8 = 0 ;
F_2 ( V_2 -> V_9 , V_10 , L_1 ) ;
F_3 ( V_2 -> V_9 , V_11 ) ;
if ( V_3 ) {
V_5 = F_4 ( V_3 , V_12 , V_1 , 0 , - 1 , V_13 ) ;
V_6 = F_5 ( V_5 , V_14 ) ;
F_4 ( V_6 , V_15 , V_1 , V_8 , 1 , V_16 ) ;
F_4 ( V_6 , V_17 , V_1 , V_8 , 1 , V_16 ) ;
V_8 += 1 ;
F_4 ( V_6 , V_18 , V_1 , V_8 , 1 , V_16 ) ;
V_8 += 1 ;
F_4 ( V_6 , V_19 , V_1 , V_8 , 2 , V_16 ) ;
V_8 += 2 ;
}
if ( V_20 ) {
V_7 = F_6 ( V_1 , V_8 ) ;
F_7 ( V_20 , V_7 , V_2 , V_3 ) ;
}
return F_8 ( V_1 ) ;
}
void
F_9 ( void )
{
static T_6 V_21 [] = {
{ & V_15 ,
{ L_2 , L_3 , V_22 , V_23 , F_10 ( V_24 ) , 0xF0 ,
NULL , V_25 } } ,
{ & V_17 ,
{ L_4 , L_5 , V_22 , V_23 , NULL , 0x0F ,
NULL , V_25 } } ,
{ & V_18 ,
{ L_6 , L_7 , V_22 , V_26 , F_10 ( V_27 ) , 0x0 ,
NULL , V_25 } } ,
{ & V_19 ,
{ L_8 , L_9 , V_28 , V_23 , NULL , 0x0 ,
NULL , V_25 } }
} ;
static T_7 * V_29 [] = {
& V_14
} ;
#if 0
static ei_register_info ei[] = {
{ &ei_ipos_protocol,
{ "ipos.protocol.unknown", PI_PROTOCOL, PI_WARN,
"Unknown Protocol Data", EXPFILL }}
};
expert_module_t* expert_ipos;
#endif
V_12 = F_11 ( L_10 , L_1 , L_11 ) ;
F_12 ( V_12 , V_21 , F_13 ( V_21 ) ) ;
F_14 ( V_29 , F_13 ( V_29 ) ) ;
#if 0
expert_ipos = expert_register_protocol(proto_ipos);
expert_register_field_array(expert_ipos, ei, array_length(ei));
#endif
V_30 = F_15 ( L_11 , F_1 , V_12 ) ;
}
void
F_16 ( void )
{
V_20 = F_17 ( L_12 , V_12 ) ;
F_18 ( L_13 , V_31 , V_30 ) ;
F_18 ( L_13 , V_32 , V_30 ) ;
F_18 ( L_13 , V_33 , V_30 ) ;
F_18 ( L_13 , V_34 , V_30 ) ;
F_18 ( L_13 , V_35 , V_30 ) ;
F_18 ( L_13 , V_36 , V_30 ) ;
}

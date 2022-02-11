static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_1 * V_5 ;
T_3 * V_6 = NULL ;
F_2 ( V_2 -> V_7 , V_8 , L_1 ) ;
F_3 ( V_2 -> V_7 , V_9 ) ;
if ( V_3 ) {
T_5 * V_10 ;
V_10 = F_4 ( V_3 , V_11 , V_1 , 0 , - 1 ,
L_2 ) ;
V_6 = F_5 ( V_10 , V_12 ) ;
}
V_5 = F_6 ( V_1 , 0 ) ;
F_7 ( V_13 [ V_14 ] , V_5 , V_2 , V_6 ) ;
return F_8 ( V_1 ) ;
}
void
F_9 ( void )
{
#if 0
static hf_register_info hf[] = {
{&hf_ipdc_esg_bootstrap_xml,
{"ESG Provider Discovery", "dvb_ipdc.bootstrap",
FT_STRING, BASE_NONE, NULL, 0x0, "List of ESG Providers", HFILL}}
};
#endif
static T_6 * V_15 [] = {
& V_12 ,
} ;
V_11 = F_10 ( L_3 ,
L_2 , L_4 ) ;
#if 0
proto_register_field_array(proto_ipdc, hf, array_length(hf));
#endif
F_11 ( V_15 , F_12 ( V_15 ) ) ;
F_13 ( L_4 , F_1 , V_11 ) ;
}
void
F_14 ( void )
{
T_7 V_16 ;
V_13 [ V_14 ] = F_15 ( L_5 , V_11 ) ;
V_16 = F_16 ( F_1 , V_11 ) ;
F_17 ( L_6 , V_17 , V_16 ) ;
}

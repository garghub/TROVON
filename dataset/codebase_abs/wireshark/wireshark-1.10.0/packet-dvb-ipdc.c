static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_1 * V_4 ;
T_3 * V_5 = NULL ;
F_2 ( V_2 -> V_6 , V_7 , L_1 ) ;
F_3 ( V_2 -> V_6 , V_8 ) ;
if ( V_3 ) {
T_4 * V_9 ;
V_9 = F_4 ( V_3 , V_10 , V_1 , 0 , - 1 ,
L_2 ) ;
V_5 = F_5 ( V_9 , V_11 ) ;
}
V_4 = F_6 ( V_1 , 0 ) ;
F_7 ( V_12 [ V_13 ] , V_4 , V_2 , V_5 ) ;
}
void
F_8 ( void )
{
#if 0
static hf_register_info hf[] = {
{&hf_ipdc_esg_bootstrap_xml,
{"ESG Provider Discovery", "ipdc.bootstrap",
FT_STRING, BASE_NONE, NULL, 0x0, "List of ESG Providers", HFILL}}
};
#endif
static T_5 * V_14 [] = {
& V_11 ,
} ;
V_10 = F_9 ( L_3 ,
L_2 , L_4 ) ;
#if 0
proto_register_field_array(proto_ipdc, hf, array_length(hf));
#endif
F_10 ( V_14 , F_11 ( V_14 ) ) ;
F_12 ( L_4 , F_1 , V_10 ) ;
}
void
F_13 ( void )
{
T_6 V_15 ;
V_12 [ V_13 ] = F_14 ( L_5 ) ;
V_15 = F_15 ( F_1 , V_10 ) ;
F_16 ( L_6 , V_16 , V_15 ) ;
}

static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 ;
T_3 * V_6 ;
T_6 V_7 = 0 ;
T_6 V_8 = 0 ;
if ( F_2 ( V_1 ) < V_9 )
{
return 0 ;
}
V_7 = F_3 ( V_1 , V_10 + V_11 +
V_12 ) ;
V_8 = F_3 ( V_1 , V_10 + V_11 +
V_12 + V_13 ) ;
F_4 ( V_2 -> V_14 , V_15 , L_1 ) ;
F_5 ( V_2 -> V_14 , V_16 ,
L_2 ,
V_8 , V_7 ) ;
if ( V_3 ) {
V_5 = F_6 ( V_3 , V_17 , V_1 , 0 ,
V_9 , V_18 ) ;
V_6 = F_7 ( V_5 , V_19 ) ;
F_6 ( V_6 ,
V_20 , V_1 , 0 , V_10 , V_21 ) ;
F_6 ( V_6 ,
V_22 , V_1 , V_10 , V_11 , V_21 ) ;
F_6 ( V_6 ,
V_23 , V_1 , V_10 + V_11 +
V_12 , V_13 , V_21 ) ;
F_6 ( V_6 ,
V_24 , V_1 , V_10 + V_11 +
V_12 + V_13 , V_25 , V_21 ) ;
F_6 ( V_6 ,
V_26 , V_1 , V_10 + V_11 +
V_12 + V_13 + V_25 ,
V_27 , V_21 ) ;
F_6 ( V_6 ,
V_28 , V_1 , V_10 + V_11 +
V_12 + V_13 + V_25 +
V_27 + V_29 , V_30 , V_21 ) ;
}
return F_8 ( V_1 ) ;
}
void
F_9 ( void )
{
static T_7 V_31 [] = {
{ & V_20 ,
{ L_3 , L_4 ,
V_32 , V_33 , NULL , 0x0 ,
NULL , V_34 }
} ,
{ & V_22 ,
{ L_5 , L_6 ,
V_32 , V_33 , NULL , 0x0 ,
NULL , V_34 }
} ,
#if 0
{ &hf_tte_pcf_res0,
{ "Reserved 0", "tte_pcf.res0",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#endif
{ & V_23 ,
{ L_7 , L_8 ,
V_35 , V_33 , NULL , 0x0 ,
NULL , V_34 }
} ,
{ & V_24 ,
{ L_9 , L_10 ,
V_35 , V_33 , NULL , 0x0 ,
NULL , V_34 }
} ,
{ & V_26 ,
{ L_11 , L_12 ,
V_35 , V_33 , F_10 ( V_36 ) , 0x0F ,
NULL , V_34 }
} ,
#if 0
{ &hf_tte_pcf_res1,
{ "Reserved 1", "tte_pcf.res1",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ & V_28 ,
{ L_13 , L_14 ,
V_37 , V_33 , NULL , 0x0 ,
NULL , V_34 }
}
} ;
static T_8 * V_38 [] = {
& V_19
} ;
V_17 = F_11 ( L_15 ,
L_16 , L_17 ) ;
F_12 ( V_17 , V_31 , F_13 ( V_31 ) ) ;
F_14 ( V_38 , F_13 ( V_38 ) ) ;
V_39 = F_15 ( L_17 , F_1 , V_17 ) ;
}
void
F_16 ( void )
{
F_17 ( L_18 , V_40 , V_39 ) ;
}

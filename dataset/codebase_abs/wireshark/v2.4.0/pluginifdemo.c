void
F_1 ( T_1 V_1 , T_2 V_2 , T_2 T_3 V_3 )
{
F_2 ( V_1 , V_2 ) ;
}
void
F_3 ( T_1 V_1 V_3 , T_2 V_2 V_3 , T_2 T_3 V_3 )
{
F_4 ( V_1 , V_2 ) ;
}
void
F_5 ( void )
{
static T_4 V_4 [] = {
} ;
static T_5 * V_5 [] = {
} ;
#if 0
module_t *pluginif_module = NULL;
#endif
T_6 * V_6 = NULL ;
V_7 = F_6 ( L_1 , L_2 , L_3 ) ;
F_7 ( V_7 , V_4 , F_8 ( V_4 ) ) ;
F_9 ( V_5 , F_8 ( V_5 ) ) ;
V_6 = F_10 ( V_7 , L_4 , TRUE ) ;
F_11 ( V_6 , L_5 ) ;
F_12 ( V_6 , L_6 , L_7 , F_1 , NULL ) ;
F_13 ( V_6 ) ;
F_14 ( V_6 , L_8 , L_9 , L_10 ) ;
F_13 ( V_6 ) ;
F_12 ( V_6 , L_11 , L_12 , F_3 , NULL ) ;
#if 0
pluginif_module = prefs_register_protocol(proto_pluginifdemo, NULL);
#endif
T_7 * V_8 = F_15 ( L_13 ) ;
F_16 ( V_8 , V_9 , L_14 , 0 , L_15 , FALSE , 0 , FALSE , 0 , V_10 , 0 ) ;
F_16 ( V_8 , V_9 , L_16 , 0 , L_17 , TRUE , 0 , FALSE , 0 , V_10 , 0 ) ;
F_16 ( V_8 , V_11 , L_18 , 0 , L_19 , FALSE , 0 , FALSE , 0 , V_10 , 0 ) ;
F_16 ( V_8 , V_12 , L_20 , L_21 , L_22 , FALSE , 0 , TRUE , 0 , V_10 , 0 ) ;
F_16 ( V_8 , V_12 , L_23 , L_24 , L_25 , FALSE , 0 , FALSE , L_26 , V_10 , 0 ) ;
T_8 * V_13 = 0 ;
V_13 = F_17 ( V_13 , L_27 , L_28 , FALSE ) ;
V_13 = F_17 ( V_13 , L_29 , L_30 , FALSE ) ;
V_13 = F_17 ( V_13 , L_31 , L_32 , TRUE ) ;
V_13 = F_17 ( V_13 , L_33 , L_34 , FALSE ) ;
V_13 = F_17 ( V_13 , L_35 , L_36 , FALSE ) ;
V_13 = F_17 ( V_13 , L_37 , L_38 , FALSE ) ;
V_13 = F_17 ( V_13 , L_39 , L_40 , FALSE ) ;
V_13 = F_17 ( V_13 , L_41 , L_42 , FALSE ) ;
F_16 ( V_8 , V_14 , L_43 , 0 , L_44 , FALSE , V_13 , FALSE , 0 , V_10 , 0 ) ;
F_18 ( V_8 ) ;
}
void V_10 ( T_2 V_15 , T_2 V_16 , T_2 T_3 V_3 )
{
if ( ! V_15 )
return;
T_9 * V_17 = 0 ;
T_7 * V_18 = ( T_7 * ) V_15 ;
if ( V_18 -> V_19 == V_9 )
F_19 ( L_45 ) ;
else if ( V_18 -> V_19 == V_11 )
{
T_10 V_20 = * ( ( T_10 * ) V_16 ) ;
V_17 = F_20 ( L_46 , ( int ) ( V_20 ) ) ;
F_19 ( V_17 ) ;
}
else if ( V_18 -> V_19 == V_12 )
{
T_9 * V_20 = ( T_9 * ) V_16 ;
V_17 = F_20 ( L_47 , V_20 ) ;
F_19 ( V_17 ) ;
}
else if ( V_18 -> V_19 == V_14 )
{
T_11 * V_20 = ( T_11 * ) V_16 ;
V_17 = F_20 ( L_48 , V_20 -> V_21 ) ;
F_19 ( V_17 ) ;
}
F_21 ( V_17 ) ;
}
void
F_22 ( void )
{
}

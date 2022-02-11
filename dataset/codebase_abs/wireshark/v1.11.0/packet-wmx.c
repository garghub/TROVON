T_1 * F_1 ( T_2 * V_1 , T_3 * V_2 , int V_3 , T_4 * V_4 , T_5 V_5 , const T_6 V_6 )
{
T_7 * V_7 ;
T_3 * V_8 ;
T_1 * V_9 ;
T_5 V_10 , V_11 ;
T_8 V_12 ;
T_8 V_13 ;
if ( F_2 ( V_1 ) < 0 )
return V_2 ;
V_11 = F_3 ( V_1 ) ;
V_10 = F_4 ( V_1 ) ;
V_12 = F_5 ( V_1 ) ;
V_13 = F_2 ( V_1 ) ;
V_7 = F_6 ( V_3 ) ;
V_9 = F_7 ( V_2 , V_4 , V_5 , V_10 + V_11 , L_1 , V_7 -> V_14 ) ;
V_8 = F_8 ( V_9 , * V_15 [ V_13 ] ) ;
F_9 ( V_8 , V_16 , V_4 , V_5 , 1 , V_13 ) ;
if ( V_12 > 0 )
{
F_9 ( V_8 , V_17 , V_4 , V_5 + 1 , 1 , V_12 ) ;
F_9 ( V_8 , V_18 , V_4 , V_5 + 2 , V_12 , V_10 ) ;
} else {
F_9 ( V_8 , V_18 , V_4 , V_5 + 1 , 1 , V_10 ) ;
}
V_9 = F_10 ( V_8 , V_3 , V_4 , V_5 + V_11 , V_10 , V_6 ) ;
return V_9 ;
}
T_3 * F_11 ( T_2 * V_1 , T_3 * V_2 , int V_3 , T_4 * V_4 , T_5 V_5 )
{
T_7 * V_7 ;
T_3 * V_8 ;
T_1 * V_9 ;
T_5 V_10 , V_11 ;
T_8 V_12 ;
T_8 V_13 ;
if ( F_2 ( V_1 ) < 0 )
return V_2 ;
V_11 = F_3 ( V_1 ) ;
V_10 = F_4 ( V_1 ) ;
V_12 = F_5 ( V_1 ) ;
V_13 = F_2 ( V_1 ) ;
V_7 = F_6 ( V_3 ) ;
V_9 = F_7 ( V_2 , V_4 , V_5 , V_10 + V_11 , L_1 , V_7 -> V_14 ) ;
V_8 = F_8 ( V_9 , * V_15 [ V_13 ] ) ;
F_9 ( V_8 , V_16 , V_4 , V_5 , 1 , V_13 ) ;
if ( V_12 > 0 )
{
F_9 ( V_8 , V_17 , V_4 , V_5 + 1 , 1 , V_12 ) ;
F_9 ( V_8 , V_18 , V_4 , V_5 + 2 , V_12 , V_10 ) ;
} else {
F_9 ( V_8 , V_18 , V_4 , V_5 + 1 , 1 , V_10 ) ;
}
return V_8 ;
}
T_3 * F_12 ( T_2 * V_1 , T_5 V_19 , T_3 * V_2 , int V_3 , T_4 * V_4 , T_5 V_5 , T_5 T_9 V_20 , const char * V_21 )
{
T_3 * V_8 ;
T_1 * V_9 ;
T_5 V_10 , V_11 ;
T_8 V_12 ;
T_8 V_13 ;
T_10 V_22 ;
const T_11 * V_23 ;
if ( F_2 ( V_1 ) < 0 )
return V_2 ;
V_11 = F_3 ( V_1 ) ;
V_10 = F_4 ( V_1 ) ;
V_12 = F_5 ( V_1 ) ;
V_13 = F_2 ( V_1 ) ;
V_9 = F_13 ( V_2 , V_3 , V_4 , V_5 , V_10 + V_11 , L_2 , V_21 , V_10 ) ;
V_8 = F_8 ( V_9 , * V_15 [ V_13 ] ) ;
F_9 ( V_8 , V_16 , V_4 , V_5 , 1 , V_13 ) ;
if ( V_12 > 0 )
{
F_9 ( V_8 , V_17 , V_4 , V_5 + 1 , 1 , V_12 ) ;
F_9 ( V_8 , V_18 , V_4 , V_5 + 2 , V_12 , V_10 ) ;
} else {
F_9 ( V_8 , V_18 , V_4 , V_5 + 1 , 1 , V_10 ) ;
}
switch ( V_10 )
{
case 1 :
V_22 = F_14 ( V_4 , V_5 + V_11 ) ;
V_23 = V_24 ;
break;
case 2 :
V_22 = F_15 ( V_4 , V_5 + V_11 ) ;
V_23 = V_25 ;
break;
case 3 :
V_22 = F_16 ( V_4 , V_5 + V_11 ) ;
V_23 = V_26 ;
break;
case 4 :
V_22 = F_17 ( V_4 , V_5 + V_11 ) ;
V_23 = V_27 ;
break;
default:
V_22 = F_17 ( V_4 , V_5 + V_11 ) ;
V_23 = V_28 ;
break;
}
V_9 = F_7 ( V_8 , V_4 , V_5 + V_11 , V_10 , V_23 , V_21 , V_22 ) ;
V_8 = F_8 ( V_9 , V_19 ) ;
return V_8 ;
}
static void F_18 ( T_4 * V_4 V_20 , T_12 * V_29 , T_3 * V_2 V_20 )
{
F_19 ( V_29 -> V_30 , V_31 , L_3 ) ;
F_20 ( V_29 -> V_30 , V_32 ) ;
}
T_13 F_21 ( T_12 * V_29 )
{
if ( V_29 -> V_33 == V_34 )
return TRUE ;
if ( V_29 -> V_33 == V_35 )
if( V_36 . V_37 && ! F_22 ( & V_36 , & V_29 -> V_38 ) )
return TRUE ;
return FALSE ;
}
void F_23 ( void )
{
static T_14 V_7 [] = {
{ & V_16 , { L_4 , L_5 , V_39 , V_40 , NULL , 0x0 , NULL , V_41 } } ,
{ & V_18 , { L_6 , L_7 , V_42 , V_40 , NULL , 0x0 , NULL , V_41 } } ,
{ & V_17 , { L_8 , L_9 , V_39 , V_40 , NULL , 0x0 , NULL , V_41 } } ,
} ;
#if 0
static gint *ett[] =
{
&ett_wimax,
&ett_wimax_tlv,
&ett_wimax_fch,
&ett_wimax_cdma,
&ett_wimax_ffb,
};
#endif
T_15 * V_43 ;
V_44 = F_24 (
L_10 ,
L_11 ,
L_12
) ;
F_25 ( V_44 , V_7 , F_26 ( V_7 ) ) ;
#if 0
proto_register_subtree_array(ett, array_length(ett));
#endif
F_27 ( L_12 , F_18 , V_44 ) ;
#if 0
wimax_module = prefs_register_protocol(proto_wimax, proto_reg_handoff_wimax);
#endif
V_43 = F_28 ( V_44 , NULL ) ;
F_29 ( V_43 , L_13 ,
L_14 ,
L_15
L_16
L_17
L_18
L_19 ,
10 , & V_45 ) ;
F_30 ( V_43 , L_20 ,
L_21 ,
L_22
L_23
L_24
L_25 ,
& V_46 ) ;
F_31 ( V_43 , L_26 ) ;
F_31 ( V_43 , L_27 ) ;
#if 0
register_dissector_table("wimax.max_basic_cid", "Max Basic CID", FT_UINT16, BASE_DEC);
register_dissector_table("wimax.corrigendum_2_version", "Corrigendum 2 Version", FT_UINT16, BASE_DEC);
#endif
F_32 ( V_15 , F_26 ( V_15 ) ) ;
}
void
F_33 ( void )
{
#if 0
static int wimax_prefs_initialized = FALSE;
static dissector_handle_t wimax_handle;
if(!wimax_prefs_initialized)
{
wimax_handle = create_dissector_handle(dissect_wimax, proto_wimax);
wimax_prefs_initialized = TRUE;
} else {
dissector_delete_uint("wimax.max_basic_cid", global_cid_max_basic, wimax_handle);
dissector_delete_uint("wimax.corrigendum_2_version", include_cor2_changes, wimax_handle);
}
dissector_add_uint("wimax.max_basic_cid", global_cid_max_basic, wimax_handle);
dissector_add_uint("wimax.corrigendum_2_version", include_cor2_changes, wimax_handle);
#endif
}

T_1 * F_1 ( T_2 * V_1 , T_3 V_2 , T_1 * V_3 , int V_4 , T_4 * V_5 , T_3 V_6 , T_3 T_5 V_7 , T_6 V_8 )
{
T_1 * V_9 ;
T_7 * V_10 ;
T_8 V_11 ;
T_3 V_12 , V_13 ;
T_9 V_14 ;
T_9 V_15 ;
T_10 V_16 ;
const T_11 * V_17 ;
V_13 = F_2 ( V_1 ) ;
V_11 = V_6 - V_13 ;
V_12 = F_3 ( V_1 ) ;
V_14 = F_4 ( V_1 ) ;
V_15 = F_5 ( V_1 ) ;
if ( F_5 ( V_1 ) < 0 )
return V_3 ;
V_10 = F_6 ( V_3 , V_4 , V_5 , V_6 , V_12 , V_8 ) ;
if ( ! F_7 ( V_10 ) )
return V_3 ;
F_7 ( V_10 ) -> V_6 -= V_13 ;
F_7 ( V_10 ) -> T_5 += V_13 ;
V_9 = F_8 ( V_10 , * V_18 [ V_15 ] ) ;
F_9 ( V_9 , V_5 , V_11 , 1 , L_1 , V_15 ) ;
if ( V_14 > 0 )
{
F_9 ( V_9 , V_5 , V_11 + 1 , 1 , L_2 , V_14 ) ;
F_9 ( V_9 , V_5 , V_11 + 2 , V_14 , L_3 , V_12 ) ;
} else {
F_9 ( V_9 , V_5 , V_11 + 1 , 1 , L_3 , V_12 ) ;
}
switch ( V_12 )
{
case 1 :
V_16 = F_10 ( V_5 , V_6 ) ;
V_17 = V_19 ;
break;
case 2 :
V_16 = F_11 ( V_5 , V_6 ) ;
V_17 = V_20 ;
break;
case 3 :
V_16 = F_12 ( V_5 , V_6 ) ;
V_17 = V_21 ;
break;
case 4 :
V_16 = F_13 ( V_5 , V_6 ) ;
V_17 = V_22 ;
break;
default:
V_16 = F_13 ( V_5 , V_6 ) ;
V_17 = V_23 ;
break;
}
V_10 = F_9 ( V_9 , V_5 , V_6 , V_12 , V_17 , F_7 ( V_10 ) -> V_24 -> V_25 , V_16 ) ;
V_9 = F_8 ( V_10 , V_2 ) ;
return V_9 ;
}
T_1 * F_14 ( T_2 * V_1 , T_3 V_2 , T_1 * V_3 , int V_4 , T_4 * V_5 , T_3 V_6 , T_3 T_5 , const char * V_26 , ... )
{
T_1 * V_9 ;
T_7 * V_10 ;
T_8 V_11 ;
T_3 V_12 , V_13 ;
T_9 V_14 ;
T_9 V_15 ;
T_10 V_16 ;
T_12 V_27 ;
T_11 * V_28 = NULL ;
const T_11 * V_17 ;
if ( F_5 ( V_1 ) < 0 )
return V_3 ;
V_13 = F_2 ( V_1 ) ;
V_11 = V_6 - V_13 ;
V_12 = F_3 ( V_1 ) ;
V_14 = F_4 ( V_1 ) ;
V_15 = F_5 ( V_1 ) ;
va_start ( V_27 , V_26 ) ;
V_28 = F_15 ( V_26 , V_27 ) ;
va_end ( V_27 ) ;
V_10 = F_16 ( V_3 , V_4 , V_5 , V_6 , T_5 , L_4 , V_28 ) ;
if ( ! F_7 ( V_10 ) )
return V_3 ;
F_7 ( V_10 ) -> V_6 -= V_13 ;
F_7 ( V_10 ) -> T_5 += V_13 ;
V_9 = F_8 ( V_10 , * V_18 [ V_15 ] ) ;
F_9 ( V_9 , V_5 , V_11 , 1 , L_1 , V_15 ) ;
if ( V_14 > 0 )
{
F_9 ( V_9 , V_5 , V_11 + 1 , 1 , L_2 , V_14 ) ;
F_9 ( V_9 , V_5 , V_11 + 2 , V_14 , L_3 , V_12 ) ;
} else {
F_9 ( V_9 , V_5 , V_11 + 1 , 1 , L_3 , V_12 ) ;
}
switch ( V_12 )
{
case 1 :
V_16 = F_10 ( V_5 , V_6 ) ;
V_17 = V_19 ;
break;
case 2 :
V_16 = F_11 ( V_5 , V_6 ) ;
V_17 = V_20 ;
break;
case 3 :
V_16 = F_12 ( V_5 , V_6 ) ;
V_17 = V_21 ;
break;
case 4 :
V_16 = F_13 ( V_5 , V_6 ) ;
V_17 = V_22 ;
break;
default:
V_16 = F_13 ( V_5 , V_6 ) ;
V_17 = V_23 ;
break;
}
V_10 = F_9 ( V_9 , V_5 , V_6 , T_5 , V_17 , V_28 , V_16 ) ;
V_9 = F_8 ( V_10 , V_2 ) ;
return V_9 ;
}
static void F_17 ( T_4 * V_5 V_7 , T_13 * V_29 , T_1 * V_3 V_7 )
{
F_18 ( V_29 -> V_30 , V_31 , L_5 ) ;
F_19 ( V_29 -> V_30 , V_32 ) ;
}
T_6 F_20 ( T_13 * V_29 )
{
if ( V_29 -> V_33 == V_34 )
return TRUE ;
if ( V_29 -> V_33 == V_35 )
if( V_36 . V_37 && ! F_21 ( & V_36 , & V_29 -> V_38 ) )
return TRUE ;
return FALSE ;
}
void F_22 ( void )
{
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
T_14 * V_39 ;
V_40 = F_23 (
L_6 ,
L_7 ,
L_8
) ;
#if 0
proto_register_subtree_array(ett, array_length(ett));
#endif
F_24 ( L_8 , F_17 , V_40 ) ;
F_25 () ;
F_26 () ;
F_27 () ;
F_28 () ;
F_29 () ;
F_30 () ;
F_31 () ;
F_32 () ;
F_33 () ;
#if 0
wimax_module = prefs_register_protocol(proto_wimax, proto_reg_handoff_wimax);
#endif
V_39 = F_34 ( V_40 , NULL ) ;
F_35 ( V_39 , L_9 ,
L_10 ,
L_11
L_12
L_13
L_14
L_15 ,
10 , & V_41 ) ;
F_36 ( V_39 , L_16 ,
L_17 ,
L_18
L_19
L_20
L_21 ,
& V_42 ) ;
F_37 ( V_39 , L_22 ) ;
F_37 ( V_39 , L_23 ) ;
#if 0
register_dissector_table("wimax.max_basic_cid", "Max Basic CID", FT_UINT16, BASE_DEC);
register_dissector_table("wimax.corrigendum_2_version", "Corrigendum 2 Version", FT_UINT16, BASE_DEC);
#endif
F_38 ( V_18 , F_39 ( V_18 ) ) ;
}
void
F_40 ( void )
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

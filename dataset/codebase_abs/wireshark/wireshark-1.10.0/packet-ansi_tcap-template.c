static void F_1 ( struct V_1 * V_2 ) {
memset ( V_2 , '\0' , sizeof( * V_2 ) ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = FALSE ;
V_2 -> V_6 = NULL ;
}
static void
F_2 ( void ) {
if ( V_7 ) {
F_3 ( V_7 ) ;
V_7 = NULL ;
}
V_7 = F_4 ( V_8 , V_9 ) ;
}
static void
F_5 ( void )
{
F_2 () ;
}
static void
F_6 ( T_1 * V_10 , T_2 * T_3 V_11 , T_4 * T_5 V_11 ) {
struct V_12 * V_13 ;
T_6 * V_14 = & ( V_10 -> V_14 ) ;
T_6 * V_15 = & ( V_10 -> V_15 ) ;
char * V_16 ;
if ( ( ! V_10 -> V_17 -> V_18 . V_19 ) && ( V_20 . V_6 ) ) {
switch( V_21 ) {
case 0 :
V_16 = F_7 ( V_20 . V_6 ) ;
break;
case 1 :
V_16 = F_8 ( L_1 , V_20 . V_6 , F_9 ( V_14 ) ) ;
break;
default:
V_16 = F_8 ( L_2 , V_20 . V_6 , F_9 ( V_14 ) , F_9 ( V_15 ) ) ;
break;
}
V_13 = (struct V_12 * ) F_10 ( V_7 , V_16 ) ;
if( V_13 )
return;
V_13 = F_11 ( struct V_12 ) ;
V_13 -> V_22 = V_20 . V_23 . V_22 ;
V_13 -> V_24 = V_20 . V_23 . V_24 ;
V_13 -> V_25 = V_20 . V_23 . V_25 ;
F_12 ( V_7 ,
F_13 ( V_16 ) ,
V_13 ) ;
}
}
static T_7
F_14 ( T_1 * V_10 , T_2 * T_3 V_11 , T_4 * T_5 V_11 ) {
struct V_12 * V_13 ;
T_6 * V_14 = & ( V_10 -> V_14 ) ;
T_6 * V_15 = & ( V_10 -> V_15 ) ;
char * V_16 ;
if ( ! V_20 . V_6 ) {
return FALSE ;
}
V_16 = ( char * ) F_15 ( V_26 ) ;
V_16 [ 0 ] = '\0' ;
F_16 ( V_16 , V_26 , L_2 ,
V_20 . V_6 , F_9 ( V_15 ) ,
F_9 ( V_14 ) ) ;
switch( V_21 ) {
case 0 :
F_16 ( V_16 , V_26 , L_3 , V_20 . V_6 ) ;
break;
case 1 :
F_16 ( V_16 , V_26 , L_1 , V_20 . V_6 , F_9 ( V_15 ) ) ;
break;
default:
F_16 ( V_16 , V_26 , L_2 , V_20 . V_6 , F_9 ( V_15 ) , F_9 ( V_14 ) ) ;
break;
}
V_13 = (struct V_12 * ) F_10 ( V_7 , V_16 ) ;
if( V_13 ) {
V_20 . V_23 . V_22 = V_13 -> V_22 ;
V_20 . V_23 . V_24 = V_13 -> V_24 ;
V_20 . V_23 . V_25 = V_13 -> V_25 ;
return TRUE ;
}
return FALSE ;
}
static T_7
F_17 ( T_4 * T_5 , T_8 * V_27 , T_2 * T_3 ) {
T_9 * V_28 ;
if( V_20 . V_23 . V_29 == 1 ) {
F_6 ( V_27 -> V_10 , T_3 , T_5 ) ;
} else{
if( F_14 ( V_27 -> V_10 , T_3 , T_5 ) ) {
if( V_20 . V_23 . V_22 == 0 ) {
V_28 = F_18 ( T_3 , V_30 , T_5 , 0 , 0 , V_20 . V_23 . V_24 ) ;
} else{
V_28 = F_18 ( T_3 , V_31 , T_5 , 0 , 0 , V_20 . V_23 . V_25 ) ;
}
F_19 ( V_28 ) ;
V_20 . V_23 . V_32 = V_28 ;
}
}
if( V_20 . V_23 . V_22 == 0 ) {
T_10 V_33 = ( V_20 . V_23 . V_24 & 0x7f00 ) >> 8 ;
T_10 V_34 = ( T_10 ) ( V_20 . V_23 . V_24 & 0xff ) ;
if( ! F_20 ( V_35 , V_20 . V_23 . V_24 , T_5 , V_27 -> V_10 , V_36 ) ) {
V_28 = F_21 ( T_3 , T_5 , 0 , - 1 ,
L_4
L_5 ,
V_20 . V_23 . V_24 , V_33 , V_34 ) ;
F_19 ( V_28 ) ;
return FALSE ;
}
return TRUE ;
} else if( V_20 . V_23 . V_22 == 1 ) {
if( ( V_20 . V_23 . V_25 & 0x0900 ) != 0x0900 ) {
V_28 = F_21 ( T_3 , T_5 , 0 , - 1 ,
L_6
L_7 ,
V_20 . V_23 . V_25 ) ;
F_19 ( V_28 ) ;
return FALSE ;
}
}
F_22 ( V_37 , T_5 , V_27 -> V_10 , V_36 ) ;
return TRUE ;
}
static void
F_23 ( T_4 * T_5 , T_1 * V_10 , T_2 * V_38 )
{
T_9 * V_28 = NULL ;
T_2 * T_3 = NULL ;
#if 0
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
gint offset = 0;
struct tcaphash_context_t * p_tcap_context;
dissector_handle_t subdissector_handle;
#endif
T_8 V_39 ;
F_24 ( & V_39 , V_40 , TRUE , V_10 ) ;
F_1 ( & V_20 ) ;
V_36 = V_38 ;
F_25 ( V_10 -> V_41 , V_42 , L_8 ) ;
if( V_38 ) {
V_28 = F_26 ( V_38 , V_43 , T_5 , 0 , - 1 , V_44 ) ;
T_3 = F_27 ( V_28 , V_45 ) ;
V_46 = V_28 ;
V_47 = T_3 ;
}
V_48 = NULL ;
V_49 = NULL ;
V_10 -> V_50 = & V_20 ;
V_51 = F_28 () ;
V_52 = FALSE ;
V_53 = NULL ;
F_29 ( FALSE , T_5 , 0 , & V_39 , T_3 , - 1 ) ;
#if 0
if (g_ansi_tcap_HandleSRT && !tcap_subdissector_used ) {
if (gtcap_DisplaySRT && tree) {
stat_item = proto_tree_add_text(tree, tvb, 0, 0, "Stat");
PROTO_ITEM_SET_GENERATED(stat_item);
stat_tree = proto_item_add_subtree(stat_item, ett_ansi_tcap_stat);
}
p_tcap_context=tcapsrt_call_matching(tvb, pinfo, stat_tree, gp_tcapsrt_info);
ansi_tcap_private.context=p_tcap_context;
if ( p_tcap_context && cur_oid && !p_tcap_context->oid_present ) {
g_strlcpy(p_tcap_context->oid, cur_oid, sizeof(p_tcap_context->oid));
if ( (subdissector_handle = dissector_get_string_handle(ber_oid_dissector_table, cur_oid)) ) {
p_tcap_context->subdissector_handle=subdissector_handle;
p_tcap_context->oid_present=TRUE;
}
}
if (g_ansi_tcap_HandleSRT && p_tcap_context && p_tcap_context->callback) {
(p_tcap_context->callback)(tvb, pinfo, stat_tree, p_tcap_context);
}
}
#endif
}
void
F_30 ( void )
{
V_37 = F_31 ( L_9 ) ;
V_54 = F_32 ( L_10 ) ;
}
void
F_33 ( void )
{
T_11 * V_55 ;
static T_12 V_56 [] = {
{ & V_57 ,
{ L_11 ,
L_12 ,
V_58 , V_59 , NULL , 0x0 ,
NULL , V_60 }
} ,
{ & V_61 ,
{ L_13 ,
L_14 ,
V_62 , V_63 , NULL , 0x0 ,
L_15 , V_60 }
} ,
{ & V_64 ,
{ L_16 ,
L_17 ,
V_62 , V_63 , NULL , 0x0 ,
L_18 , V_60 }
} ,
{ & V_65 ,
{ L_19 ,
L_20 ,
V_66 , V_63 , NULL , 0x0 ,
L_21 , V_60 }
} ,
{ & V_67 ,
{ L_22 ,
L_23 ,
V_58 , V_59 , NULL , 0x0 ,
NULL , V_60 }
} ,
{ & V_68 ,
{ L_24 , L_25 ,
V_69 , 16 , NULL , 0x8000 ,
NULL , V_60 }
} ,
{ & V_70 ,
{ L_26 ,
L_27 ,
V_71 , V_59 , F_34 ( V_72 ) , 0x7f00 ,
NULL , V_60 }
} ,
{ & V_73 ,
{ L_28 ,
L_29 ,
V_71 , V_59 , NULL , 0x00ff ,
NULL , V_60 }
} ,
#include "packet-ansi_tcap-hfarr.c"
} ;
static T_13 * V_74 [] = {
& V_45 ,
& V_75 ,
& V_76 ,
& V_77 ,
& V_78 ,
& V_79 ,
#include "packet-ansi_tcap-ettarr.c"
} ;
static const T_14 V_80 [] = {
{ L_30 , L_31 , 0 } ,
{ L_32 , L_33 , 1 } ,
{ L_34 , L_35 , 2 } ,
{ NULL , NULL , - 1 }
} ;
V_43 = F_35 ( V_81 , V_82 , V_83 ) ;
F_36 ( L_36 , F_23 , V_43 ) ;
V_35 = F_37 ( L_37 , L_38 , V_71 , V_59 ) ;
F_38 ( V_43 , V_56 , F_39 ( V_56 ) ) ;
F_40 ( V_74 , F_39 ( V_74 ) ) ;
V_55 = F_41 ( V_43 , F_30 ) ;
F_42 ( V_55 , L_39 ,
L_40 ,
L_41 ,
& V_21 , V_80 , FALSE ) ;
F_43 ( & F_5 ) ;
}

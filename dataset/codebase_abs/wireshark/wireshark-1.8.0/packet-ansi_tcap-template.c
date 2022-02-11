static void F_1 ( struct V_1 * V_2 ) {
memset ( V_2 , '\0' , sizeof( * V_2 ) ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = FALSE ;
V_2 -> V_6 = NULL ;
}
static void
F_2 ( T_1 V_7 , T_1 V_8 , T_1 T_2 V_9 ) {
struct V_10 * V_11 = (struct V_10 * ) V_8 ;
T_3 * V_12 = ( T_3 * ) V_7 ;
F_3 ( V_12 ) ;
F_3 ( V_11 ) ;
}
static void
F_4 ( void ) {
if ( V_13 ) {
F_5 ( V_13 , F_2 , NULL ) ;
F_6 ( V_13 ) ;
V_13 = NULL ;
}
V_13 = F_7 ( V_14 , V_15 ) ;
}
static void
F_8 ( void )
{
F_4 () ;
}
static void
F_9 ( T_4 * V_16 , T_5 * T_6 V_9 , T_7 * T_8 V_9 ) {
struct V_10 * V_11 ;
T_9 * V_17 = & ( V_16 -> V_17 ) ;
T_9 * V_18 = & ( V_16 -> V_18 ) ;
char * V_19 ;
if ( ( ! V_16 -> V_20 -> V_21 . V_22 ) && ( V_23 . V_6 ) ) {
V_19 = F_10 ( V_24 ) ;
V_19 [ 0 ] = '\0' ;
switch( V_25 ) {
case 0 :
F_11 ( V_19 , V_24 , L_1 , V_23 . V_6 ) ;
break;
case 1 :
F_11 ( V_19 , V_24 , L_2 , V_23 . V_6 , F_12 ( V_17 ) ) ;
break;
default:
F_11 ( V_19 , V_24 , L_3 , V_23 . V_6 , F_12 ( V_17 ) , F_12 ( V_18 ) ) ;
break;
}
V_11 = (struct V_10 * ) F_13 ( V_13 , V_19 ) ;
if( V_11 )
return;
V_11 = F_14 ( struct V_10 , 1 ) ;
V_11 -> V_26 = V_23 . V_27 . V_26 ;
V_11 -> V_28 = V_23 . V_27 . V_28 ;
V_11 -> V_29 = V_23 . V_27 . V_29 ;
F_15 ( V_13 ,
F_16 ( V_19 ) ,
V_11 ) ;
}
}
static T_10
F_17 ( T_4 * V_16 , T_5 * T_6 V_9 , T_7 * T_8 V_9 ) {
struct V_10 * V_11 ;
T_9 * V_17 = & ( V_16 -> V_17 ) ;
T_9 * V_18 = & ( V_16 -> V_18 ) ;
char * V_19 ;
if ( ! V_23 . V_6 ) {
return FALSE ;
}
V_19 = F_10 ( V_24 ) ;
V_19 [ 0 ] = '\0' ;
F_11 ( V_19 , V_24 , L_3 ,
V_23 . V_6 , F_12 ( V_18 ) ,
F_12 ( V_17 ) ) ;
switch( V_25 ) {
case 0 :
F_11 ( V_19 , V_24 , L_1 , V_23 . V_6 ) ;
break;
case 1 :
F_11 ( V_19 , V_24 , L_2 , V_23 . V_6 , F_12 ( V_18 ) ) ;
break;
default:
F_11 ( V_19 , V_24 , L_3 , V_23 . V_6 , F_12 ( V_18 ) , F_12 ( V_17 ) ) ;
break;
}
V_11 = (struct V_10 * ) F_13 ( V_13 , V_19 ) ;
if( V_11 ) {
V_23 . V_27 . V_26 = V_11 -> V_26 ;
V_23 . V_27 . V_28 = V_11 -> V_28 ;
V_23 . V_27 . V_29 = V_11 -> V_29 ;
return TRUE ;
}
return FALSE ;
}
static T_10
F_18 ( T_7 * T_8 , T_11 * V_30 , T_5 * T_6 ) {
T_12 * V_31 ;
if( V_23 . V_27 . V_32 == 1 ) {
F_9 ( V_30 -> V_16 , T_6 , T_8 ) ;
} else{
if( F_17 ( V_30 -> V_16 , T_6 , T_8 ) ) {
if( V_23 . V_27 . V_26 == 0 ) {
V_31 = F_19 ( T_6 , V_33 , T_8 , 0 , 0 , V_23 . V_27 . V_28 ) ;
} else{
V_31 = F_19 ( T_6 , V_34 , T_8 , 0 , 0 , V_23 . V_27 . V_29 ) ;
}
F_20 ( V_31 ) ;
V_23 . V_27 . V_35 = V_31 ;
}
}
if( V_23 . V_27 . V_26 == 0 ) {
T_13 V_36 = ( V_23 . V_27 . V_28 & 0x7f00 ) >> 8 ;
T_13 V_37 = ( T_13 ) ( V_23 . V_27 . V_28 & 0xff ) ;
if( ! F_21 ( V_38 , V_23 . V_27 . V_28 , T_8 , V_30 -> V_16 , V_39 ) ) {
V_31 = F_22 ( T_6 , T_8 , 0 , - 1 ,
L_4
L_5 ,
V_23 . V_27 . V_28 , V_36 , V_37 ) ;
F_20 ( V_31 ) ;
return FALSE ;
}
return TRUE ;
} else if( V_23 . V_27 . V_26 == 1 ) {
if( ( V_23 . V_27 . V_29 & 0x0900 ) != 0x0900 ) {
V_31 = F_22 ( T_6 , T_8 , 0 , - 1 ,
L_6
L_7 ,
V_23 . V_27 . V_29 ) ;
F_20 ( V_31 ) ;
return FALSE ;
}
}
F_23 ( V_40 , T_8 , V_30 -> V_16 , V_39 ) ;
return TRUE ;
}
static void
F_24 ( T_7 * T_8 , T_4 * V_16 , T_5 * V_41 )
{
T_12 * V_31 = NULL ;
T_5 * T_6 = NULL ;
#if 0
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
gint offset = 0;
struct tcaphash_context_t * p_tcap_context;
dissector_handle_t subdissector_handle;
#endif
T_11 V_42 ;
F_25 ( & V_42 , V_43 , TRUE , V_16 ) ;
F_1 ( & V_23 ) ;
V_39 = V_41 ;
F_26 ( V_16 -> V_44 , V_45 , L_8 ) ;
if( V_41 ) {
V_31 = F_27 ( V_41 , V_46 , T_8 , 0 , - 1 , V_47 ) ;
T_6 = F_28 ( V_31 , V_48 ) ;
V_49 = V_31 ;
V_50 = T_6 ;
}
V_51 = NULL ;
V_52 = NULL ;
V_16 -> V_53 = & V_23 ;
V_54 = F_29 () ;
V_55 = FALSE ;
V_56 = NULL ;
F_30 ( FALSE , T_8 , 0 , & V_42 , T_6 , - 1 ) ;
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
F_31 ( void )
{
V_40 = F_32 ( L_9 ) ;
V_57 = F_33 ( L_10 ) ;
}
void
F_34 ( void )
{
T_14 * V_58 ;
static T_15 V_59 [] = {
{ & V_60 ,
{ L_11 ,
L_12 ,
V_61 , V_62 , NULL , 0x0 ,
NULL , V_63 }
} ,
{ & V_64 ,
{ L_13 ,
L_14 ,
V_65 , V_66 , NULL , 0x0 ,
L_15 , V_63 }
} ,
{ & V_67 ,
{ L_16 ,
L_17 ,
V_65 , V_66 , NULL , 0x0 ,
L_18 , V_63 }
} ,
{ & V_68 ,
{ L_19 ,
L_20 ,
V_69 , V_66 , NULL , 0x0 ,
L_21 , V_63 }
} ,
{ & V_70 ,
{ L_22 ,
L_23 ,
V_61 , V_62 , NULL , 0x0 ,
NULL , V_63 }
} ,
{ & V_71 ,
{ L_24 , L_25 ,
V_72 , 16 , NULL , 0x8000 ,
NULL , V_63 }
} ,
{ & V_73 ,
{ L_26 ,
L_27 ,
V_74 , V_62 , F_35 ( V_75 ) , 0x7f00 ,
NULL , V_63 }
} ,
{ & V_76 ,
{ L_28 ,
L_29 ,
V_74 , V_62 , NULL , 0x00ff ,
NULL , V_63 }
} ,
#include "packet-ansi_tcap-hfarr.c"
} ;
static T_16 * V_77 [] = {
& V_48 ,
& V_78 ,
& V_79 ,
& V_80 ,
& V_81 ,
& V_82 ,
#include "packet-ansi_tcap-ettarr.c"
} ;
static T_17 V_83 [] = {
{ L_30 , L_31 , 0 } ,
{ L_32 , L_33 , 1 } ,
{ L_34 , L_35 , 2 } ,
{ NULL , NULL , - 1 }
} ;
V_46 = F_36 ( V_84 , V_85 , V_86 ) ;
F_37 ( L_36 , F_24 , V_46 ) ;
V_38 = F_38 ( L_37 , L_38 , V_74 , V_62 ) ;
F_39 ( V_46 , V_59 , F_40 ( V_59 ) ) ;
F_41 ( V_77 , F_40 ( V_77 ) ) ;
V_58 = F_42 ( V_46 , F_31 ) ;
F_43 ( V_58 , L_39 ,
L_40 ,
L_41 ,
& V_25 , V_83 , FALSE ) ;
F_44 ( & F_8 ) ;
}

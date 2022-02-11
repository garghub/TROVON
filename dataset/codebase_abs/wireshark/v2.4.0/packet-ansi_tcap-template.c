static void F_1 ( struct V_1 * V_2 ) {
memset ( V_2 , '\0' , sizeof( * V_2 ) ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = FALSE ;
V_2 -> V_6 = NULL ;
}
static void
F_2 ( T_1 * V_7 , T_2 * T_3 V_8 , T_4 * T_5 V_8 ) {
struct V_9 * V_10 ;
T_6 * V_11 , * V_12 ;
char * V_13 ;
V_11 = F_3 ( F_4 () , & ( V_7 -> V_11 ) ) ;
V_12 = F_3 ( F_4 () , & ( V_7 -> V_12 ) ) ;
if ( ( ! V_7 -> V_14 -> V_15 . V_16 ) && ( V_17 . V_6 ) ) {
switch( V_18 ) {
case V_19 :
V_13 = F_5 ( F_4 () , V_17 . V_6 ) ;
break;
case V_20 :
V_13 = F_6 ( F_4 () , L_1 , V_17 . V_6 , V_11 ) ;
break;
case V_21 :
default:
V_13 = F_6 ( F_4 () , L_2 , V_17 . V_6 , V_11 , V_12 ) ;
break;
}
V_10 = (struct V_9 * ) F_7 ( V_22 , V_13 ) ;
if( V_10 )
return;
V_10 = F_8 ( F_9 () , struct V_9 ) ;
V_10 -> V_23 = V_17 . V_24 . V_23 ;
V_10 -> V_25 = V_17 . V_24 . V_25 ;
V_10 -> V_26 = V_17 . V_24 . V_26 ;
F_10 ( V_22 ,
F_5 ( F_9 () , V_13 ) ,
V_10 ) ;
}
}
static T_7
F_11 ( T_1 * V_7 , T_2 * T_3 V_8 , T_4 * T_5 V_8 ) {
struct V_9 * V_10 ;
T_6 * V_11 , * V_12 ;
char * V_13 ;
if ( ! V_17 . V_6 ) {
return FALSE ;
}
V_11 = F_3 ( F_4 () , & ( V_7 -> V_11 ) ) ;
V_12 = F_3 ( F_4 () , & ( V_7 -> V_12 ) ) ;
V_13 = ( char * ) F_12 ( F_4 () , V_27 ) ;
V_13 [ 0 ] = '\0' ;
switch( V_18 ) {
case V_19 :
F_13 ( V_13 , V_27 , L_3 , V_17 . V_6 ) ;
break;
case V_20 :
F_13 ( V_13 , V_27 , L_1 , V_17 . V_6 , V_12 ) ;
break;
case V_21 :
default:
F_13 ( V_13 , V_27 , L_2 , V_17 . V_6 , V_12 , V_11 ) ;
break;
}
V_10 = (struct V_9 * ) F_7 ( V_22 , V_13 ) ;
if( V_10 ) {
V_17 . V_24 . V_23 = V_10 -> V_23 ;
V_17 . V_24 . V_25 = V_10 -> V_25 ;
V_17 . V_24 . V_26 = V_10 -> V_26 ;
return TRUE ;
}
return FALSE ;
}
static T_7
F_14 ( T_4 * T_5 , T_8 * V_28 , T_2 * T_3 ) {
T_9 * V_29 ;
if( V_17 . V_24 . V_30 == 1 ) {
F_2 ( V_28 -> V_7 , T_3 , T_5 ) ;
} else{
if( F_11 ( V_28 -> V_7 , T_3 , T_5 ) ) {
if( V_17 . V_24 . V_23 == 0 ) {
V_29 = F_15 ( T_3 , V_31 , T_5 , 0 , 0 , V_17 . V_24 . V_25 ) ;
} else{
V_29 = F_15 ( T_3 , V_32 , T_5 , 0 , 0 , V_17 . V_24 . V_26 ) ;
}
F_16 ( V_29 ) ;
V_17 . V_24 . V_33 = V_29 ;
}
}
if( V_17 . V_24 . V_23 == 0 ) {
T_10 V_34 = ( V_17 . V_24 . V_25 & 0x7f00 ) >> 8 ;
T_10 V_35 = ( T_10 ) ( V_17 . V_24 . V_25 & 0xff ) ;
if( ! F_17 ( V_36 , V_17 . V_24 . V_25 , T_5 , V_28 -> V_7 , V_37 ) ) {
F_18 ( T_3 , V_28 -> V_7 , & V_38 , T_5 , 0 , - 1 ,
L_4
L_5 ,
V_17 . V_24 . V_25 , V_34 , V_35 ) ;
return FALSE ;
}
return TRUE ;
} else if( V_17 . V_24 . V_23 == 1 ) {
if( ( V_17 . V_24 . V_26 & 0x0900 ) != 0x0900 ) {
F_18 ( T_3 , V_28 -> V_7 , & V_38 , T_5 , 0 , - 1 ,
L_6
L_7 ,
V_17 . V_24 . V_26 ) ;
return FALSE ;
}
}
F_19 ( V_39 , T_5 , V_28 -> V_7 , V_37 , & V_17 ) ;
return TRUE ;
}
static int
F_20 ( T_4 * T_5 , T_1 * V_7 , T_2 * V_40 , void * T_11 V_8 )
{
T_9 * V_29 = NULL ;
T_2 * T_3 = NULL ;
#if 0
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
gint offset = 0;
struct tcaphash_context_t * p_tcap_context;
dissector_handle_t subdissector_handle;
#endif
T_8 V_41 ;
F_21 ( & V_41 , V_42 , TRUE , V_7 ) ;
F_1 ( & V_17 ) ;
V_37 = V_40 ;
F_22 ( V_7 -> V_43 , V_44 , L_8 ) ;
if( V_40 ) {
V_29 = F_23 ( V_40 , V_45 , T_5 , 0 , - 1 , V_46 ) ;
T_3 = F_24 ( V_29 , V_47 ) ;
V_48 = V_29 ;
V_49 = T_3 ;
}
V_50 = NULL ;
V_51 = NULL ;
V_52 = F_25 () ;
V_53 = FALSE ;
V_54 = NULL ;
F_26 ( FALSE , T_5 , 0 , & V_41 , T_3 , - 1 ) ;
#if 0
if (g_ansi_tcap_HandleSRT && !tcap_subdissector_used ) {
if (gtcap_DisplaySRT && tree) {
stat_tree = proto_tree_add_subtree(tree, tvb, 0, 0, ett_ansi_tcap_stat, &stat_item, "Stat");
PROTO_ITEM_SET_GENERATED(stat_item);
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
return F_27 ( T_5 ) ;
}
void
F_28 ( void )
{
V_39 = F_29 ( L_9 , V_45 ) ;
V_55 = F_30 ( L_10 ) ;
}
void
F_31 ( void )
{
T_12 * V_56 ;
static T_13 V_57 [] = {
{ & V_58 ,
{ L_11 ,
L_12 ,
V_59 , V_60 , NULL , 0x0 ,
NULL , V_61 }
} ,
{ & V_62 ,
{ L_13 ,
L_14 ,
V_63 , V_64 , NULL , 0x0 ,
L_15 , V_61 }
} ,
{ & V_65 ,
{ L_16 ,
L_17 ,
V_63 , V_64 , NULL , 0x0 ,
L_18 , V_61 }
} ,
{ & V_66 ,
{ L_19 ,
L_20 ,
V_67 , V_64 , NULL , 0x0 ,
L_21 , V_61 }
} ,
{ & V_68 ,
{ L_22 ,
L_23 ,
V_59 , V_60 , NULL , 0x0 ,
NULL , V_61 }
} ,
{ & V_69 ,
{ L_24 , L_25 ,
V_70 , 16 , NULL , 0x8000 ,
NULL , V_61 }
} ,
{ & V_71 ,
{ L_26 ,
L_27 ,
V_72 , V_60 , F_32 ( V_73 ) , 0x7f00 ,
NULL , V_61 }
} ,
{ & V_74 ,
{ L_28 ,
L_29 ,
V_72 , V_60 , NULL , 0x00ff ,
NULL , V_61 }
} ,
#include "packet-ansi_tcap-hfarr.c"
} ;
static T_14 * V_75 [] = {
& V_47 ,
& V_76 ,
& V_77 ,
& V_78 ,
& V_79 ,
& V_80 ,
#include "packet-ansi_tcap-ettarr.c"
} ;
static T_15 V_81 [] = {
{ & V_38 , { L_30 , V_82 , V_83 , L_31 , V_84 } } ,
} ;
T_16 * V_85 ;
static const T_17 V_86 [] = {
{ L_32 , L_33 , V_19 } ,
{ L_34 , L_35 , V_20 } ,
{ L_36 , L_37 , V_21 } ,
{ NULL , NULL , - 1 }
} ;
V_45 = F_33 ( V_87 , V_88 , V_89 ) ;
F_34 ( L_38 , F_20 , V_45 ) ;
V_36 = F_35 ( L_39 , L_40 , V_45 , V_72 , V_60 ) ;
F_36 ( V_45 , V_57 , F_37 ( V_57 ) ) ;
F_38 ( V_75 , F_37 ( V_75 ) ) ;
V_85 = F_39 ( V_45 ) ;
F_40 ( V_85 , V_81 , F_37 ( V_81 ) ) ;
V_56 = F_41 ( V_45 , F_28 ) ;
F_42 ( V_56 , L_41 ,
L_42 ,
L_43 ,
& V_18 , V_86 , FALSE ) ;
V_22 = F_43 ( F_44 () , F_9 () , V_90 , V_91 ) ;
}

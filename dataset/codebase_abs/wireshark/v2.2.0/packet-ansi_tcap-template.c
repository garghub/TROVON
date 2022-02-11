static void F_1 ( struct V_1 * V_2 ) {
memset ( V_2 , '\0' , sizeof( * V_2 ) ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = FALSE ;
V_2 -> V_6 = NULL ;
}
static void
F_2 ( void )
{
V_7 = F_3 ( V_8 , V_9 ) ;
}
static void
F_4 ( void )
{
F_5 ( V_7 ) ;
}
static void
F_6 ( T_1 * V_10 , T_2 * T_3 V_11 , T_4 * T_5 V_11 ) {
struct V_12 * V_13 ;
T_6 * V_14 , * V_15 ;
char * V_16 ;
V_14 = F_7 ( F_8 () , & ( V_10 -> V_14 ) ) ;
V_15 = F_7 ( F_8 () , & ( V_10 -> V_15 ) ) ;
if ( ( ! V_10 -> V_17 -> V_18 . V_19 ) && ( V_20 . V_6 ) ) {
switch( V_21 ) {
case V_22 :
V_16 = F_9 ( F_8 () , V_20 . V_6 ) ;
break;
case V_23 :
V_16 = F_10 ( F_8 () , L_1 , V_20 . V_6 , V_14 ) ;
break;
case V_24 :
default:
V_16 = F_10 ( F_8 () , L_2 , V_20 . V_6 , V_14 , V_15 ) ;
break;
}
V_13 = (struct V_12 * ) F_11 ( V_7 , V_16 ) ;
if( V_13 )
return;
V_13 = F_12 ( F_13 () , struct V_12 ) ;
V_13 -> V_25 = V_20 . V_26 . V_25 ;
V_13 -> V_27 = V_20 . V_26 . V_27 ;
V_13 -> V_28 = V_20 . V_26 . V_28 ;
F_14 ( V_7 ,
F_9 ( F_13 () , V_16 ) ,
V_13 ) ;
}
}
static T_7
F_15 ( T_1 * V_10 , T_2 * T_3 V_11 , T_4 * T_5 V_11 ) {
struct V_12 * V_13 ;
T_6 * V_14 , * V_15 ;
char * V_16 ;
if ( ! V_20 . V_6 ) {
return FALSE ;
}
V_14 = F_7 ( F_8 () , & ( V_10 -> V_14 ) ) ;
V_15 = F_7 ( F_8 () , & ( V_10 -> V_15 ) ) ;
V_16 = ( char * ) F_16 ( F_8 () , V_29 ) ;
V_16 [ 0 ] = '\0' ;
switch( V_21 ) {
case V_22 :
F_17 ( V_16 , V_29 , L_3 , V_20 . V_6 ) ;
break;
case V_23 :
F_17 ( V_16 , V_29 , L_1 , V_20 . V_6 , V_15 ) ;
break;
case V_24 :
default:
F_17 ( V_16 , V_29 , L_2 , V_20 . V_6 , V_15 , V_14 ) ;
break;
}
V_13 = (struct V_12 * ) F_11 ( V_7 , V_16 ) ;
if( V_13 ) {
V_20 . V_26 . V_25 = V_13 -> V_25 ;
V_20 . V_26 . V_27 = V_13 -> V_27 ;
V_20 . V_26 . V_28 = V_13 -> V_28 ;
return TRUE ;
}
return FALSE ;
}
static T_7
F_18 ( T_4 * T_5 , T_8 * V_30 , T_2 * T_3 ) {
T_9 * V_31 ;
if( V_20 . V_26 . V_32 == 1 ) {
F_6 ( V_30 -> V_10 , T_3 , T_5 ) ;
} else{
if( F_15 ( V_30 -> V_10 , T_3 , T_5 ) ) {
if( V_20 . V_26 . V_25 == 0 ) {
V_31 = F_19 ( T_3 , V_33 , T_5 , 0 , 0 , V_20 . V_26 . V_27 ) ;
} else{
V_31 = F_19 ( T_3 , V_34 , T_5 , 0 , 0 , V_20 . V_26 . V_28 ) ;
}
F_20 ( V_31 ) ;
V_20 . V_26 . V_35 = V_31 ;
}
}
if( V_20 . V_26 . V_25 == 0 ) {
T_10 V_36 = ( V_20 . V_26 . V_27 & 0x7f00 ) >> 8 ;
T_10 V_37 = ( T_10 ) ( V_20 . V_26 . V_27 & 0xff ) ;
if( ! F_21 ( V_38 , V_20 . V_26 . V_27 , T_5 , V_30 -> V_10 , V_39 ) ) {
F_22 ( T_3 , V_30 -> V_10 , & V_40 , T_5 , 0 , - 1 ,
L_4
L_5 ,
V_20 . V_26 . V_27 , V_36 , V_37 ) ;
return FALSE ;
}
return TRUE ;
} else if( V_20 . V_26 . V_25 == 1 ) {
if( ( V_20 . V_26 . V_28 & 0x0900 ) != 0x0900 ) {
F_22 ( T_3 , V_30 -> V_10 , & V_40 , T_5 , 0 , - 1 ,
L_6
L_7 ,
V_20 . V_26 . V_28 ) ;
return FALSE ;
}
}
F_23 ( V_41 , T_5 , V_30 -> V_10 , V_39 , & V_20 ) ;
return TRUE ;
}
static int
F_24 ( T_4 * T_5 , T_1 * V_10 , T_2 * V_42 , void * T_11 V_11 )
{
T_9 * V_31 = NULL ;
T_2 * T_3 = NULL ;
#if 0
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
gint offset = 0;
struct tcaphash_context_t * p_tcap_context;
dissector_handle_t subdissector_handle;
#endif
T_8 V_43 ;
F_25 ( & V_43 , V_44 , TRUE , V_10 ) ;
F_1 ( & V_20 ) ;
V_39 = V_42 ;
F_26 ( V_10 -> V_45 , V_46 , L_8 ) ;
if( V_42 ) {
V_31 = F_27 ( V_42 , V_47 , T_5 , 0 , - 1 , V_48 ) ;
T_3 = F_28 ( V_31 , V_49 ) ;
V_50 = V_31 ;
V_51 = T_3 ;
}
V_52 = NULL ;
V_53 = NULL ;
V_54 = F_29 () ;
V_55 = FALSE ;
V_56 = NULL ;
F_30 ( FALSE , T_5 , 0 , & V_43 , T_3 , - 1 ) ;
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
return F_31 ( T_5 ) ;
}
void
F_32 ( void )
{
V_41 = F_33 ( L_9 , V_47 ) ;
V_57 = F_34 ( L_10 ) ;
}
void
F_35 ( void )
{
T_12 * V_58 ;
static T_13 V_59 [] = {
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
V_74 , V_62 , F_36 ( V_75 ) , 0x7f00 ,
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
static T_14 * V_77 [] = {
& V_49 ,
& V_78 ,
& V_79 ,
& V_80 ,
& V_81 ,
& V_82 ,
#include "packet-ansi_tcap-ettarr.c"
} ;
static T_15 V_83 [] = {
{ & V_40 , { L_30 , V_84 , V_85 , L_31 , V_86 } } ,
} ;
T_16 * V_87 ;
static const T_17 V_88 [] = {
{ L_32 , L_33 , V_22 } ,
{ L_34 , L_35 , V_23 } ,
{ L_36 , L_37 , V_24 } ,
{ NULL , NULL , - 1 }
} ;
V_47 = F_37 ( V_89 , V_90 , V_91 ) ;
F_38 ( L_38 , F_24 , V_47 ) ;
V_38 = F_39 ( L_39 , L_40 , V_47 , V_74 , V_62 ) ;
F_40 ( V_47 , V_59 , F_41 ( V_59 ) ) ;
F_42 ( V_77 , F_41 ( V_77 ) ) ;
V_87 = F_43 ( V_47 ) ;
F_44 ( V_87 , V_83 , F_41 ( V_83 ) ) ;
V_58 = F_45 ( V_47 , F_32 ) ;
F_46 ( V_58 , L_41 ,
L_42 ,
L_43 ,
& V_21 , V_88 , FALSE ) ;
F_47 ( & F_2 ) ;
F_48 ( & F_4 ) ;
}

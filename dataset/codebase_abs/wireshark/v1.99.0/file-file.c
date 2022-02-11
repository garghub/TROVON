void
F_1 ( T_1 * V_1 , void (* F_2)( void ) )
{
V_1 -> V_2 = F_3 ( V_1 -> V_2 , ( V_3 ) F_2 ) ;
}
static void
F_4 ( V_3 V_4 , V_3 T_2 V_5 )
{
T_3 F_2 = ( T_3 ) V_4 ;
(* F_2)() ;
}
static void
F_5 ( T_4 * V_6 , T_1 * V_1 , T_5 * V_7 )
{
T_6 * volatile V_8 = NULL ;
T_7 V_9 = 0 , V_10 = 0 ;
T_5 * volatile V_11 ;
T_6 * V_12 ;
const T_8 * V_13 , * V_14 ;
V_11 = V_7 ;
V_1 -> V_15 = L_1 ;
if( ! F_6 ( V_11 , V_16 ) ) {
V_11 = NULL ;
} else {
T_5 * V_17 ;
T_9 V_18 ;
V_9 = F_7 ( V_6 ) ;
V_10 = F_8 ( V_6 ) ;
V_13 = F_9 ( V_9 , L_2 , L_3 ) ;
V_14 = F_9 ( V_10 , L_2 , L_3 ) ;
V_8 = F_10 ( V_11 , V_16 , V_6 , 0 , - 1 ,
L_4 ,
V_1 -> V_19 -> V_20 , V_10 , V_14 ) ;
F_11 ( V_8 , L_5 ,
V_9 , V_13 ) ;
V_17 = F_12 ( V_8 , V_21 ) ;
F_13 ( V_17 , V_22 , V_6 , 0 , 0 , V_1 -> V_19 -> V_23 ) ;
F_14 ( V_17 , V_24 , V_6 , 0 , 0 , V_1 -> V_19 -> V_20 ) ;
F_15 ( V_17 , V_25 , V_6 ,
0 , 0 , V_10 , L_6 ,
V_10 , V_14 , V_10 * 8 ) ;
V_8 = F_16 ( V_17 , V_26 , V_6 , 0 , 0 , V_1 -> V_19 -> V_27 . V_28 ) ;
F_17 ( V_8 ) ;
V_8 = F_16 ( V_17 , V_29 , V_6 , 0 , 0 , V_1 -> V_19 -> V_27 . V_30 ) ;
F_17 ( V_8 ) ;
if( F_6 ( V_11 , V_31 ) ) {
V_18 = F_18 ( V_17 , TRUE ) ;
V_8 = F_19 ( V_17 , V_31 , V_6 , 0 , 0 , L_2 ) ;
F_17 ( V_8 ) ;
F_18 ( V_17 , V_18 ) ;
}
if( V_1 -> V_19 -> V_32 != 0 ) {
T_6 * V_33 ;
T_7 V_34 = F_20 ( V_1 -> V_19 -> V_32 ) ;
T_7 V_35 ;
V_33 = F_14 ( V_17 , V_36 , V_6 , 0 , 0 , V_34 ) ;
F_17 ( V_33 ) ;
for( V_35 = 0 ; V_35 < V_34 ; V_35 ++ ) {
F_21 ( V_17 , V_6 , 0 , 0 , L_7 , F_22 ( F_23 () , V_1 , V_35 ) ) ;
}
}
#if 0
if (show_file_off) {
proto_tree_add_int64_format_value(fh_tree, hf_frame_file_off, tvb,
0, 0, pinfo->fd->file_off,
"%" G_GINT64_MODIFIER "d (0x%" G_GINT64_MODIFIER "x)",
pinfo->fd->file_off, pinfo->fd->file_off);
}
#endif
if( V_1 -> V_19 -> V_37 != NULL ) {
const T_10 * V_37 = ( const T_10 * ) V_1 -> V_19 -> V_37 ;
V_12 = F_19 ( V_17 , V_38 , V_6 ,
0 , 0 , V_37 -> V_39 ) ;
F_17 ( V_12 ) ;
V_12 = F_19 ( V_17 , V_40 , V_6 ,
0 , 0 , V_37 -> V_41 ) ;
F_17 ( V_12 ) ;
}
}
if ( V_1 -> V_19 -> V_27 . V_30 ) {
F_24 ( V_1 -> V_42 , V_43 , L_8 ) ;
F_21 ( V_11 , V_6 , 0 , - 1 , L_9 ) ;
return;
}
F_25 {
#ifdef F_26
F_27 {
#endif
if ( ! F_28 ( V_44 , V_1 -> V_19 -> V_23 ,
V_6 , V_1 , V_7 ) ) {
F_24 ( V_1 -> V_42 , V_45 , L_10 ) ;
F_29 ( V_1 -> V_42 , V_43 , L_11 ,
V_1 -> V_19 -> V_23 ) ;
F_30 ( V_46 , V_6 , V_1 , V_7 ) ;
}
#ifdef F_26
} F_31 (EXCEPTION_EXECUTE_HANDLER ) {
switch( F_32 () ) {
case ( V_47 ) :
F_33 ( V_6 , V_1 , V_7 , V_48 ,
L_12 ) ;
break;
case ( V_49 ) :
F_33 ( V_6 , V_1 , V_7 , V_48 ,
L_13 ) ;
break;
case ( V_50 ) :
F_33 ( V_6 , V_1 , V_7 , V_48 ,
L_14 ) ;
break;
default:
F_33 ( V_6 , V_1 , V_7 , V_48 ,
F_34 ( L_15 , F_32 () ) ) ;
}
}
#endif
}
F_35 {
F_33 ( V_6 , V_1 , V_7 , V_51 , V_52 ) ;
}
V_53 ;
if( F_6 ( V_11 , V_31 ) ) {
T_11 * V_54 = F_36 ( F_37 () , L_2 ) ;
T_12 * V_55 ;
V_55 = F_38 ( F_39 ( V_1 -> V_56 ) ) ;
if ( V_55 ) {
F_40 ( V_54 , F_41 ( F_42 ( F_43 ( V_55 ) ) ) ) ;
V_55 = F_38 ( V_55 ) ;
}
while ( V_55 ) {
F_44 ( V_54 , ':' ) ;
F_40 ( V_54 , F_41 ( F_42 ( F_43 ( V_55 ) ) ) ) ;
V_55 = F_38 ( V_55 ) ;
}
F_45 ( V_8 , F_46 ( V_54 ) ) ;
}
if ( F_47 () ) {
F_25 {
#ifdef F_26
F_27 {
#endif
F_48 ( V_6 , V_1 , V_7 ) ;
#ifdef F_26
} F_31 (EXCEPTION_EXECUTE_HANDLER ) {
switch( F_32 () ) {
case ( V_47 ) :
F_33 ( V_6 , V_1 , V_7 , V_48 ,
L_12 ) ;
break;
case ( V_49 ) :
F_33 ( V_6 , V_1 , V_7 , V_48 ,
L_13 ) ;
break;
case ( V_50 ) :
F_33 ( V_6 , V_1 , V_7 , V_48 ,
L_14 ) ;
break;
default:
F_33 ( V_6 , V_1 , V_7 , V_48 ,
F_34 ( L_15 , F_32 () ) ) ;
}
}
#endif
}
F_35 {
F_33 ( V_6 , V_1 , V_7 , V_51 , V_52 ) ;
}
V_53 ;
}
F_49 ( V_57 , V_1 , NULL ) ;
if ( V_1 -> V_2 ) {
F_50 ( V_1 -> V_2 , & F_4 , NULL ) ;
F_51 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
}
void
F_52 ( void )
{
static T_13 V_58 [] = {
{ & V_24 ,
{ L_16 , L_17 ,
V_59 , V_60 , NULL , 0x0 ,
NULL , V_61 } } ,
{ & V_25 ,
{ L_18 , L_19 ,
V_59 , V_60 , NULL , 0x0 ,
NULL , V_61 } } ,
#if 0
{ &hf_frame_file_off,
{ "File Offset", "file.file_off",
FT_INT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
{ & V_26 ,
{ L_20 , L_21 ,
V_62 , V_63 , NULL , 0x0 ,
L_22 , V_61 } } ,
{ & V_29 ,
{ L_23 , L_24 ,
V_62 , V_63 , NULL , 0x0 ,
L_25 , V_61 } } ,
{ & V_31 ,
{ L_26 , L_27 ,
V_64 , V_63 , NULL , 0x0 ,
L_28 , V_61 } } ,
{ & V_38 ,
{ L_29 , L_30 ,
V_64 , V_63 , NULL , 0x0 ,
L_31 , V_61 } } ,
{ & V_40 ,
{ L_32 , L_33 ,
V_64 , V_63 , NULL , 0x0 ,
L_34 , V_61 } } ,
{ & V_36 ,
{ L_35 , L_36 ,
V_59 , V_60 , NULL , 0x0 ,
NULL , V_61 } } ,
{ & V_22 ,
{ L_37 , L_38 ,
V_65 , V_60 , NULL , 0x0 ,
NULL , V_61 } } ,
} ;
static T_14 * V_66 [] = {
& V_21
} ;
#if 0
module_t *file_module;
#endif
V_44 = F_53 ( L_39 ,
L_40 , V_59 , V_60 ) ;
V_16 = F_54 ( L_1 , L_1 , L_41 ) ;
F_55 ( V_16 , V_58 , F_56 ( V_58 ) ) ;
F_57 ( V_66 , F_56 ( V_66 ) ) ;
F_58 ( L_41 , F_5 , V_16 ) ;
F_59 ( V_16 ) ;
#if 0
frame_module = prefs_register_protocol(proto_frame, NULL);
prefs_register_bool_preference(frame_module, "show_file_off",
"Show File Offset", "Show offset of frame in capture file", &show_file_off);
#endif
V_57 = F_60 ( L_41 ) ;
}
void
F_61 ( void )
{
V_46 = F_62 ( L_42 ) ;
}

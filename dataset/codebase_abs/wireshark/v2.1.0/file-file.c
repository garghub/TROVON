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
static int
F_5 ( T_4 * V_6 , T_1 * V_1 , T_5 * V_7 , void * V_8 )
{
T_6 * volatile V_9 = NULL ;
T_7 V_10 = 0 , V_11 = 0 ;
T_5 * volatile V_12 = NULL ;
T_5 * volatile V_13 ;
T_6 * V_14 ;
const T_8 * V_15 , * V_16 ;
const T_9 * V_17 ;
T_10 * V_18 = ( T_10 * ) V_8 ;
V_13 = V_7 ;
V_1 -> V_19 = L_1 ;
if( ! F_6 ( V_13 , V_20 ) ) {
V_13 = NULL ;
} else {
V_10 = F_7 ( V_6 ) ;
V_11 = F_8 ( V_6 ) ;
V_15 = F_9 ( V_10 , L_2 , L_3 ) ;
V_16 = F_9 ( V_11 , L_2 , L_3 ) ;
V_9 = F_10 ( V_13 , V_20 , V_6 , 0 , - 1 ,
L_4 ,
V_1 -> V_21 , V_11 , V_16 ) ;
F_11 ( V_9 , L_5 ,
V_10 , V_15 ) ;
V_12 = F_12 ( V_9 , V_22 ) ;
F_13 ( V_12 , V_23 , V_6 , 0 , 0 , V_1 -> V_24 ) ;
F_14 ( V_12 , V_25 , V_6 , 0 , 0 , V_1 -> V_21 ) ;
F_15 ( V_12 , V_26 , V_6 ,
0 , 0 , V_11 , L_6 ,
V_11 , V_16 , V_11 * 8 ) ;
V_9 = F_16 ( V_12 , V_27 , V_6 , 0 , 0 , V_1 -> V_28 -> V_29 . V_30 ) ;
F_17 ( V_9 ) ;
V_9 = F_16 ( V_12 , V_31 , V_6 , 0 , 0 , V_1 -> V_28 -> V_29 . V_32 ) ;
F_17 ( V_9 ) ;
if( V_1 -> V_28 -> V_33 != 0 ) {
T_6 * V_34 ;
T_7 V_35 = F_18 ( V_1 -> V_28 -> V_33 ) ;
T_7 V_36 ;
V_34 = F_14 ( V_12 , V_37 , V_6 , 0 , 0 , V_35 ) ;
F_17 ( V_34 ) ;
for( V_36 = 0 ; V_36 < V_35 ; V_36 ++ ) {
T_8 * V_38 = F_19 ( F_20 () , V_1 , V_36 ) ;
F_21 ( V_12 , V_39 , V_6 , 0 , 0 , V_38 , L_7 , V_38 ) ;
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
}
if ( V_1 -> V_28 -> V_29 . V_32 ) {
F_22 ( V_1 -> V_40 , V_41 , L_8 ) ;
F_23 ( V_13 , V_31 , V_6 , 0 , - 1 , TRUE , L_9 ) ;
return F_7 ( V_6 ) ;
}
F_24 {
#ifdef F_25
F_26 {
#endif
if ( ! F_27 ( V_42 , V_1 -> V_24 ,
V_6 , V_1 , V_7 ) ) {
F_22 ( V_1 -> V_40 , V_43 , L_10 ) ;
F_28 ( V_1 -> V_40 , V_41 , L_11 ,
V_1 -> V_24 ) ;
F_29 ( V_6 , V_1 , V_7 ) ;
}
#ifdef F_25
} F_30 (EXCEPTION_EXECUTE_HANDLER ) {
switch( F_31 () ) {
case ( V_44 ) :
F_32 ( V_6 , V_1 , V_7 , V_45 ,
L_12 ) ;
break;
case ( V_46 ) :
F_32 ( V_6 , V_1 , V_7 , V_45 ,
L_13 ) ;
break;
case ( V_47 ) :
F_32 ( V_6 , V_1 , V_7 , V_45 ,
L_14 ) ;
break;
default:
F_32 ( V_6 , V_1 , V_7 , V_45 ,
F_33 ( L_15 , F_31 () ) ) ;
}
}
#endif
}
F_34 {
F_32 ( V_6 , V_1 , V_7 , V_48 , V_49 ) ;
}
V_50 ;
if( F_6 ( V_13 , V_51 ) ) {
T_11 * V_52 = F_35 ( F_36 () , L_2 ) ;
T_12 * V_53 ;
V_53 = F_37 ( F_38 ( V_1 -> V_54 ) ) ;
if ( V_53 ) {
F_39 ( V_52 , F_40 ( F_41 ( F_42 ( V_53 ) ) ) ) ;
V_53 = F_37 ( V_53 ) ;
}
while ( V_53 ) {
F_43 ( V_52 , ':' ) ;
F_39 ( V_52 , F_40 ( F_41 ( F_42 ( V_53 ) ) ) ) ;
V_53 = F_37 ( V_53 ) ;
}
V_9 = F_44 ( V_12 , V_51 , V_6 , 0 , 0 , F_45 ( V_52 ) ) ;
F_17 ( V_9 ) ;
}
if ( F_46 () ) {
F_24 {
#ifdef F_25
F_26 {
#endif
F_47 ( V_6 , V_1 , V_7 ) ;
#ifdef F_25
} F_30 (EXCEPTION_EXECUTE_HANDLER ) {
switch( F_31 () ) {
case ( V_44 ) :
F_32 ( V_6 , V_1 , V_7 , V_45 ,
L_12 ) ;
break;
case ( V_46 ) :
F_32 ( V_6 , V_1 , V_7 , V_45 ,
L_13 ) ;
break;
case ( V_47 ) :
F_32 ( V_6 , V_1 , V_7 , V_45 ,
L_14 ) ;
break;
default:
F_32 ( V_6 , V_1 , V_7 , V_45 ,
F_33 ( L_15 , F_31 () ) ) ;
}
}
#endif
}
F_34 {
F_32 ( V_6 , V_1 , V_7 , V_48 , V_49 ) ;
}
V_50 ;
}
if ( V_1 -> V_28 -> V_29 . V_55 ) {
V_17 = F_48 ( V_18 -> V_56 ) ;
V_1 -> V_28 -> V_17 = V_17 ;
V_1 -> V_28 -> V_29 . V_55 = 0 ;
} else {
V_17 = V_1 -> V_28 -> V_17 ;
}
if ( V_17 ) {
V_1 -> V_28 -> V_17 = V_17 ;
V_14 = F_44 ( V_12 , V_57 , V_6 ,
0 , 0 , V_17 -> V_58 ) ;
F_17 ( V_14 ) ;
V_14 = F_44 ( V_12 , V_59 , V_6 ,
0 , 0 , V_17 -> V_60 ) ;
F_17 ( V_14 ) ;
}
F_49 ( V_61 , V_1 , NULL ) ;
if ( V_1 -> V_2 ) {
F_50 ( V_1 -> V_2 , & F_4 , NULL ) ;
F_51 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
return F_7 ( V_6 ) ;
}
void
F_52 ( void )
{
static T_13 V_62 [] = {
{ & V_25 ,
{ L_16 , L_17 ,
V_63 , V_64 , NULL , 0x0 ,
NULL , V_65 } } ,
{ & V_26 ,
{ L_18 , L_19 ,
V_63 , V_64 , NULL , 0x0 ,
NULL , V_65 } } ,
#if 0
{ &hf_frame_file_off,
{ "File Offset", "file.offset",
FT_INT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
{ & V_27 ,
{ L_20 , L_21 ,
V_66 , V_67 , NULL , 0x0 ,
L_22 , V_65 } } ,
{ & V_31 ,
{ L_23 , L_24 ,
V_66 , V_67 , NULL , 0x0 ,
L_25 , V_65 } } ,
{ & V_51 ,
{ L_26 , L_27 ,
V_68 , V_67 , NULL , 0x0 ,
L_28 , V_65 } } ,
{ & V_57 ,
{ L_29 , L_30 ,
V_68 , V_67 , NULL , 0x0 ,
L_31 , V_65 } } ,
{ & V_59 ,
{ L_32 , L_33 ,
V_68 , V_67 , NULL , 0x0 ,
L_34 , V_65 } } ,
{ & V_37 ,
{ L_35 , L_36 ,
V_63 , V_64 , NULL , 0x0 ,
NULL , V_65 } } ,
{ & V_39 ,
{ L_37 , L_38 ,
V_68 , V_67 , NULL , 0x0 ,
NULL , V_65 } } ,
{ & V_23 ,
{ L_39 , L_40 ,
V_69 , V_64 , NULL , 0x0 ,
NULL , V_65 } } ,
} ;
static T_14 * V_70 [] = {
& V_22
} ;
#if 0
module_t *file_module;
#endif
V_20 = F_53 ( L_1 , L_1 , L_41 ) ;
F_54 ( V_20 , V_62 , F_55 ( V_62 ) ) ;
F_56 ( V_70 , F_55 ( V_70 ) ) ;
F_57 ( L_41 , F_5 , V_20 ) ;
V_42 = F_58 ( L_42 ,
L_43 , V_20 , V_63 , V_64 , V_71 ) ;
F_59 ( V_20 ) ;
#if 0
frame_module = prefs_register_protocol(proto_frame, NULL);
prefs_register_bool_preference(frame_module, "show_file_off",
"Show File Offset", "Show offset of frame in capture file", &show_file_off);
#endif
V_61 = F_60 ( L_41 ) ;
}

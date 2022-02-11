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
F_5 ( T_4 * V_6 , T_1 * V_1 , T_5 * V_7 , void * T_6 V_5 )
{
T_7 * volatile V_8 = NULL ;
T_8 V_9 = 0 , V_10 = 0 ;
T_5 * volatile V_11 ;
T_7 * V_12 ;
const T_9 * V_13 , * V_14 ;
V_11 = V_7 ;
V_1 -> V_15 = L_1 ;
if( ! F_6 ( V_11 , V_16 ) ) {
V_11 = NULL ;
} else {
T_5 * V_17 ;
T_10 V_18 ;
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
T_7 * V_33 ;
T_8 V_34 = F_20 ( V_1 -> V_19 -> V_32 ) ;
T_8 V_35 ;
V_33 = F_14 ( V_17 , V_36 , V_6 , 0 , 0 , V_34 ) ;
F_17 ( V_33 ) ;
for( V_35 = 0 ; V_35 < V_34 ; V_35 ++ ) {
T_9 * V_37 = F_21 ( F_22 () , V_1 , V_35 ) ;
F_23 ( V_17 , V_38 , V_6 , 0 , 0 , V_37 , L_7 , V_37 ) ;
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
if( V_1 -> V_19 -> V_39 != NULL ) {
const T_11 * V_39 = ( const T_11 * ) V_1 -> V_19 -> V_39 ;
V_12 = F_19 ( V_17 , V_40 , V_6 ,
0 , 0 , V_39 -> V_41 ) ;
F_17 ( V_12 ) ;
V_12 = F_19 ( V_17 , V_42 , V_6 ,
0 , 0 , V_39 -> V_43 ) ;
F_17 ( V_12 ) ;
}
}
if ( V_1 -> V_19 -> V_27 . V_30 ) {
F_24 ( V_1 -> V_44 , V_45 , L_8 ) ;
F_25 ( V_11 , V_29 , V_6 , 0 , - 1 , TRUE , L_9 ) ;
return F_7 ( V_6 ) ;
}
F_26 {
#ifdef F_27
F_28 {
#endif
if ( ! F_29 ( V_46 , V_1 -> V_19 -> V_23 ,
V_6 , V_1 , V_7 ) ) {
F_24 ( V_1 -> V_44 , V_47 , L_10 ) ;
F_30 ( V_1 -> V_44 , V_45 , L_11 ,
V_1 -> V_19 -> V_23 ) ;
F_31 ( V_48 , V_6 , V_1 , V_7 ) ;
}
#ifdef F_27
} F_32 (EXCEPTION_EXECUTE_HANDLER ) {
switch( F_33 () ) {
case ( V_49 ) :
F_34 ( V_6 , V_1 , V_7 , V_50 ,
L_12 ) ;
break;
case ( V_51 ) :
F_34 ( V_6 , V_1 , V_7 , V_50 ,
L_13 ) ;
break;
case ( V_52 ) :
F_34 ( V_6 , V_1 , V_7 , V_50 ,
L_14 ) ;
break;
default:
F_34 ( V_6 , V_1 , V_7 , V_50 ,
F_35 ( L_15 , F_33 () ) ) ;
}
}
#endif
}
F_36 {
F_34 ( V_6 , V_1 , V_7 , V_53 , V_54 ) ;
}
V_55 ;
if( F_6 ( V_11 , V_31 ) ) {
T_12 * V_56 = F_37 ( F_38 () , L_2 ) ;
T_13 * V_57 ;
V_57 = F_39 ( F_40 ( V_1 -> V_58 ) ) ;
if ( V_57 ) {
F_41 ( V_56 , F_42 ( F_43 ( F_44 ( V_57 ) ) ) ) ;
V_57 = F_39 ( V_57 ) ;
}
while ( V_57 ) {
F_45 ( V_56 , ':' ) ;
F_41 ( V_56 , F_42 ( F_43 ( F_44 ( V_57 ) ) ) ) ;
V_57 = F_39 ( V_57 ) ;
}
F_46 ( V_8 , F_47 ( V_56 ) ) ;
}
if ( F_48 () ) {
F_26 {
#ifdef F_27
F_28 {
#endif
F_49 ( V_6 , V_1 , V_7 ) ;
#ifdef F_27
} F_32 (EXCEPTION_EXECUTE_HANDLER ) {
switch( F_33 () ) {
case ( V_49 ) :
F_34 ( V_6 , V_1 , V_7 , V_50 ,
L_12 ) ;
break;
case ( V_51 ) :
F_34 ( V_6 , V_1 , V_7 , V_50 ,
L_13 ) ;
break;
case ( V_52 ) :
F_34 ( V_6 , V_1 , V_7 , V_50 ,
L_14 ) ;
break;
default:
F_34 ( V_6 , V_1 , V_7 , V_50 ,
F_35 ( L_15 , F_33 () ) ) ;
}
}
#endif
}
F_36 {
F_34 ( V_6 , V_1 , V_7 , V_53 , V_54 ) ;
}
V_55 ;
}
F_50 ( V_59 , V_1 , NULL ) ;
if ( V_1 -> V_2 ) {
F_51 ( V_1 -> V_2 , & F_4 , NULL ) ;
F_52 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
return F_7 ( V_6 ) ;
}
void
F_53 ( void )
{
static T_14 V_60 [] = {
{ & V_24 ,
{ L_16 , L_17 ,
V_61 , V_62 , NULL , 0x0 ,
NULL , V_63 } } ,
{ & V_25 ,
{ L_18 , L_19 ,
V_61 , V_62 , NULL , 0x0 ,
NULL , V_63 } } ,
#if 0
{ &hf_frame_file_off,
{ "File Offset", "file.offset",
FT_INT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
{ & V_26 ,
{ L_20 , L_21 ,
V_64 , V_65 , NULL , 0x0 ,
L_22 , V_63 } } ,
{ & V_29 ,
{ L_23 , L_24 ,
V_64 , V_65 , NULL , 0x0 ,
L_25 , V_63 } } ,
{ & V_31 ,
{ L_26 , L_27 ,
V_66 , V_65 , NULL , 0x0 ,
L_28 , V_63 } } ,
{ & V_40 ,
{ L_29 , L_30 ,
V_66 , V_65 , NULL , 0x0 ,
L_31 , V_63 } } ,
{ & V_42 ,
{ L_32 , L_33 ,
V_66 , V_65 , NULL , 0x0 ,
L_34 , V_63 } } ,
{ & V_36 ,
{ L_35 , L_36 ,
V_61 , V_62 , NULL , 0x0 ,
NULL , V_63 } } ,
{ & V_38 ,
{ L_37 , L_38 ,
V_66 , V_65 , NULL , 0x0 ,
NULL , V_63 } } ,
{ & V_22 ,
{ L_39 , L_40 ,
V_67 , V_62 , NULL , 0x0 ,
NULL , V_63 } } ,
} ;
static T_15 * V_68 [] = {
& V_21
} ;
#if 0
module_t *file_module;
#endif
V_46 = F_54 ( L_41 ,
L_42 , V_61 , V_62 ) ;
V_16 = F_55 ( L_1 , L_1 , L_43 ) ;
F_56 ( V_16 , V_60 , F_57 ( V_60 ) ) ;
F_58 ( V_68 , F_57 ( V_68 ) ) ;
F_59 ( L_43 , F_5 , V_16 ) ;
F_60 ( V_16 ) ;
#if 0
frame_module = prefs_register_protocol(proto_frame, NULL);
prefs_register_bool_preference(frame_module, "show_file_off",
"Show File Offset", "Show offset of frame in capture file", &show_file_off);
#endif
V_59 = F_61 ( L_43 ) ;
}
void
F_62 ( void )
{
V_48 = F_63 ( L_44 ) ;
}

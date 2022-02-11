static int
F_1 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , T_5 V_4 )
{
T_6 V_5 ;
V_5 . V_6 = F_2 ( V_1 , 0 ) ;
V_5 . V_7 = F_2 ( V_1 , 4 ) * 1000 ;
F_3 ( V_3 , V_8 , V_1 , V_4 , 8 , & V_5 ) ;
V_4 += 8 ;
F_4 ( V_3 , V_9 , V_1 , 8 , 4 , V_10 ) ;
V_4 += 4 ;
F_4 ( V_3 , V_11 , V_1 , 12 , 4 , V_10 ) ;
V_4 += 4 ;
return V_4 ;
}
static T_4 *
F_5 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_12 , int * V_4 V_2 )
{
T_7 * V_13 ;
T_4 * V_3 ;
F_6 ( T_3 -> V_14 , V_15 , V_16 ) ;
F_6 ( T_3 -> V_14 , V_17 , V_16 ) ;
V_13 = F_4 ( V_12 , V_18 , V_1 , 0 , 0 , V_19 ) ;
V_3 = F_7 ( V_13 , V_20 ) ;
return V_3 ;
}
static void
F_8 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_12 )
{
int V_4 = 0 ;
if ( ! F_9 ( V_21 , 0 , V_1 , T_3 , V_12 ) ) {
F_5 ( V_1 , T_3 , V_12 , & V_4 ) ;
F_10 ( V_12 , T_3 , & V_22 , V_1 , V_4 , - 1 ) ;
F_11 ( V_23 , V_1 , T_3 , V_12 ) ;
}
}
static void
F_12 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_12 )
{
T_1 * V_24 ;
int V_4 = 0 ;
T_4 * V_3 ;
V_3 = F_5 ( V_1 , T_3 , V_12 , & V_4 ) ;
V_4 = F_1 ( V_1 , T_3 , V_3 , V_4 ) ;
F_13 ( V_3 , V_4 ) ;
V_24 = F_14 ( V_1 , V_4 ) ;
F_11 ( V_25 , V_24 , T_3 , V_12 ) ;
}
static void
F_15 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_12 )
{
int V_4 = 0 ;
F_5 ( V_1 , T_3 , V_12 , & V_4 ) ;
F_16 ( V_26 , V_1 , T_3 , V_12 , F_17 ( V_27 ) ) ;
}
static void
F_18 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_12 )
{
int V_4 = 0 ;
F_5 ( V_1 , T_3 , V_12 , & V_4 ) ;
F_10 ( V_12 , T_3 , & V_28 , V_1 , V_4 , - 1 ) ;
F_11 ( V_23 , V_1 , T_3 , V_12 ) ;
}
static void
F_19 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_12 )
{
T_1 * V_24 ;
int V_4 = 0 ;
T_4 * V_3 ;
struct V_29 V_30 ;
T_8 V_31 ;
T_7 * V_32 ;
T_9 V_33 ;
T_10 V_34 ;
V_3 = F_5 ( V_1 , T_3 , V_12 , & V_4 ) ;
V_4 = F_1 ( V_1 , T_3 , V_3 , V_4 ) ;
V_30 . V_35 = FALSE ;
V_30 . V_36 = FALSE ;
V_30 . V_37 = V_38 ;
V_30 . V_39 =
V_40 |
V_41 |
V_42 ;
V_33 = F_20 ( V_1 , V_4 ) ;
V_30 . V_33 = V_33 ;
F_4 ( V_3 , V_43 , V_1 , V_4 , 2 , V_10 ) ;
V_32 = F_21 ( V_3 , V_44 ,
V_1 , 16 , 2 ,
( float ) V_33 / 2 ,
L_1 ,
( float ) V_33 / 2 ) ;
F_22 ( V_32 ) ;
V_4 += 2 ;
F_23 ( V_3 , V_45 , V_1 , V_4 , 1 , V_10 , & V_34 ) ;
V_30 . V_34 = V_34 ;
V_4 += 1 ;
F_23 ( V_3 , V_46 , V_1 , V_4 , 1 , V_10 , & V_31 ) ;
V_30 . V_47 = V_31 ;
V_4 += 1 ;
F_13 ( V_3 , V_4 ) ;
V_24 = F_14 ( V_1 , V_4 ) ;
if( V_31 == 100 ) {
V_30 . V_48 = 0 ;
} else {
V_30 . V_48 = 4 ;
}
F_16 ( V_49 , V_24 , T_3 , V_12 , & V_30 ) ;
}
static void
F_24 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_12 )
{
int V_4 = 0 ;
F_5 ( V_1 , T_3 , V_12 , & V_4 ) ;
F_11 ( V_50 , V_1 , T_3 , V_12 ) ;
}
static void
F_25 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_12 )
{
int V_4 = 0 ;
F_5 ( V_1 , T_3 , V_12 , & V_4 ) ;
F_16 ( V_26 , V_1 , T_3 , V_12 , F_17 ( V_27 ) ) ;
}
static void
F_26 ( T_2 * T_3 V_2 , T_11 * V_51 )
{
F_27 ( V_51 , V_52 , L_2 ) ;
}
static T_12
F_28 ( T_2 * T_3 V_2 )
{
return NULL ;
}
void
F_29 ( void )
{
static T_13 V_53 [] = {
{ & V_8 ,
{ L_3 , L_4 , V_54 , V_55 , NULL ,
0x00 , NULL , V_56 } } ,
{ & V_9 ,
{ L_5 , L_6 , V_57 , V_58 , NULL ,
0x00 , NULL , V_56 } } ,
{ & V_11 ,
{ L_7 , L_8 , V_57 , V_58 , NULL ,
0x00 , NULL , V_56 } } ,
{ & V_43 ,
{ L_9 , L_10 , V_59 , V_58 , NULL ,
0x00 , L_11 , V_56 } } ,
{ & V_44 ,
{ L_9 , L_12 , V_60 , V_61 , NULL ,
0x00 , L_11 , V_56 } } ,
{ & V_45 ,
{ L_13 , L_14 , V_62 , V_58 , NULL ,
0x00 , L_15 , V_56 } } ,
{ & V_46 ,
{ L_16 , L_17 , V_62 , V_58 , NULL ,
0x00 , L_18 , V_56 } } ,
} ;
static T_5 * V_63 [] = {
& V_20 ,
} ;
static T_14 V_64 [] = {
{ & V_28 , { L_19 , V_65 , V_66 , L_20 , V_67 } } ,
{ & V_22 , { L_21 , V_65 , V_68 , L_22 , V_67 } }
} ;
#if 0
static const enum_val_t aruba_erm_types[] = {
{ "pcap_type_0", "pcap (type 0)", TYPE_PCAP},
{ "peek_type_1", "peek (type 1)", TYPE_PEEK},
{ "airmagnet_type_2", "Airmagnet (type 2)", TYPE_AIRMAGNET},
{ "pcapplusradio_type_3", "pcap + radio header (type 3)", TYPE_PCAPPLUSRADIO},
{ "ppi_type_4", "PPI (type 4)", TYPE_PPI},
{ NULL, NULL, -1}
};
#endif
T_15 * V_69 ;
static T_16 V_70 [ 1 ] = { F_28 } ;
static T_17 V_71 = { F_26 , 1 , V_70 } ;
static T_18 V_72 = {
L_23 , L_24 , L_25 , 1 , 0 ,
& V_71 , NULL , NULL ,
V_73 ,
V_74 ,
V_75 ,
NULL ,
} ;
T_19 * V_76 ;
V_18 = F_30 ( V_77 , L_26 , L_23 ) ;
V_78 = F_30 ( L_27 , L_28 , L_29 ) ;
V_79 = F_30 ( L_30 , L_31 , L_32 ) ;
V_80 = F_30 ( L_33 , L_34 , L_35 ) ;
V_81 = F_30 ( L_36 , L_37 , L_38 ) ;
V_82 = F_30 ( L_39 , L_40 , L_41 ) ;
V_83 = F_30 ( L_42 , L_43 , L_44 ) ;
F_31 ( & V_84 , L_45 , V_85 ) ;
V_69 = F_32 ( V_18 , V_86 ) ;
F_33 ( V_69 , L_46 , L_47 ,
L_48
L_49
L_50 ,
& V_84 , V_85 ) ;
#if 0
prefs_register_enum_preference(aruba_erm_module, "type.captured",
"Type of formats for captured packets",
"Type of formats for captured packets",
&aruba_erm_type, aruba_erm_types, FALSE);
#endif
F_34 ( V_69 , L_51 ) ;
F_35 ( V_18 , V_53 , F_36 ( V_53 ) ) ;
F_37 ( V_63 , F_36 ( V_63 ) ) ;
V_76 = F_38 ( V_18 ) ;
F_39 ( V_76 , V_64 , F_36 ( V_64 ) ) ;
V_21 = F_40 (
L_25 , L_24 ,
V_57 , V_58 ) ;
F_41 ( & V_72 ) ;
}
void
V_86 ( void )
{
static T_20 * V_87 ;
static T_20 * V_88 ;
static T_21 V_89 = FALSE ;
if ( ! V_89 ) {
V_49 = F_42 ( L_52 ) ;
V_25 = F_42 ( L_53 ) ;
V_50 = F_42 ( L_54 ) ;
V_26 = F_42 ( L_55 ) ;
V_23 = F_42 ( L_56 ) ;
V_90 = F_43 ( F_8 , V_18 ) ;
V_91 = F_43 ( F_12 , V_78 ) ;
V_92 = F_43 ( F_15 , V_79 ) ;
V_93 = F_43 ( F_18 , V_80 ) ;
V_94 = F_43 ( F_19 , V_81 ) ;
V_95 = F_43 ( F_24 , V_82 ) ;
V_96 = F_43 ( F_25 , V_83 ) ;
V_89 = TRUE ;
} else {
F_44 ( L_57 , V_87 , V_90 ) ;
F_45 ( V_87 ) ;
F_45 ( V_88 ) ;
}
V_87 = F_46 ( V_84 ) ;
F_47 ( L_57 , V_87 , V_90 ) ;
F_48 ( L_25 , V_91 ) ;
F_48 ( L_25 , V_92 ) ;
F_48 ( L_25 , V_93 ) ;
F_48 ( L_25 , V_94 ) ;
F_48 ( L_25 , V_95 ) ;
F_48 ( L_25 , V_96 ) ;
}

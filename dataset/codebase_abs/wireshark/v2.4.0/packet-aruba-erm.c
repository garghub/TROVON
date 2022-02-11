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
static int
F_8 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_12 , void * T_8 V_2 )
{
int V_4 = 0 ;
if ( ! F_9 ( V_21 , 0 , V_1 , T_3 , V_12 ) ) {
F_5 ( V_1 , T_3 , V_12 , & V_4 ) ;
F_10 ( V_12 , T_3 , & V_22 , V_1 , V_4 , - 1 ) ;
F_11 ( V_1 , T_3 , V_12 ) ;
}
return F_12 ( V_1 ) ;
}
static int
F_13 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_12 , void * T_8 V_2 )
{
T_1 * V_23 ;
int V_4 = 0 ;
T_4 * V_3 ;
V_3 = F_5 ( V_1 , T_3 , V_12 , & V_4 ) ;
V_4 = F_1 ( V_1 , T_3 , V_3 , V_4 ) ;
F_14 ( V_3 , V_4 ) ;
V_23 = F_15 ( V_1 , V_4 ) ;
F_16 ( V_24 , V_23 , T_3 , V_12 ) ;
return F_12 ( V_1 ) ;
}
static int
F_17 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_12 , void * T_8 V_2 )
{
int V_4 = 0 ;
F_5 ( V_1 , T_3 , V_12 , & V_4 ) ;
F_18 ( V_25 , V_1 , T_3 , V_12 , F_19 ( V_26 ) ) ;
return F_12 ( V_1 ) ;
}
static int
F_20 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_12 , void * T_8 V_2 )
{
int V_4 = 0 ;
F_5 ( V_1 , T_3 , V_12 , & V_4 ) ;
F_10 ( V_12 , T_3 , & V_27 , V_1 , V_4 , - 1 ) ;
F_11 ( V_1 , T_3 , V_12 ) ;
return F_12 ( V_1 ) ;
}
static int
F_21 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_12 , void * T_8 V_2 )
{
T_1 * V_23 ;
int V_4 = 0 ;
T_4 * V_3 ;
struct V_28 V_29 ;
T_9 V_30 ;
T_7 * V_31 ;
T_10 V_32 ;
T_11 V_33 ;
V_3 = F_5 ( V_1 , T_3 , V_12 , & V_4 ) ;
V_4 = F_1 ( V_1 , T_3 , V_3 , V_4 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_34 = FALSE ;
V_29 . V_35 = FALSE ;
V_29 . V_36 = V_37 ;
V_29 . V_38 = TRUE ;
V_32 = F_22 ( V_1 , V_4 ) ;
V_29 . V_32 = V_32 ;
F_4 ( V_3 , V_39 , V_1 , V_4 , 2 , V_10 ) ;
V_31 = F_23 ( V_3 , V_40 ,
V_1 , 16 , 2 ,
( float ) V_32 / 2 ,
L_1 ,
( float ) V_32 / 2 ) ;
F_24 ( V_31 ) ;
V_4 += 2 ;
F_25 ( V_3 , V_41 , V_1 , V_4 , 1 , V_10 , & V_33 ) ;
V_29 . V_42 = TRUE ;
V_29 . V_33 = V_33 ;
V_4 += 1 ;
F_25 ( V_3 , V_43 , V_1 , V_4 , 1 , V_10 , & V_30 ) ;
V_29 . V_44 = TRUE ;
V_29 . V_45 = V_30 ;
V_4 += 1 ;
F_14 ( V_3 , V_4 ) ;
V_23 = F_15 ( V_1 , V_4 ) ;
if( V_30 == 100 ) {
V_29 . V_46 = 0 ;
} else {
V_29 . V_46 = 4 ;
}
F_18 ( V_47 , V_23 , T_3 , V_12 , & V_29 ) ;
return F_12 ( V_1 ) ;
}
static int
F_26 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_12 , void * T_8 V_2 )
{
int V_4 = 0 ;
F_5 ( V_1 , T_3 , V_12 , & V_4 ) ;
F_16 ( V_48 , V_1 , T_3 , V_12 ) ;
return F_12 ( V_1 ) ;
}
static int
F_27 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_12 , void * T_8 V_2 )
{
int V_4 = 0 ;
F_5 ( V_1 , T_3 , V_12 , & V_4 ) ;
F_18 ( V_25 , V_1 , T_3 , V_12 , F_19 ( V_26 ) ) ;
return F_12 ( V_1 ) ;
}
static void
F_28 ( T_2 * T_3 V_2 , T_12 * V_49 )
{
F_29 ( V_49 , V_50 , L_2 ) ;
}
static T_13
F_30 ( T_2 * T_3 V_2 )
{
return NULL ;
}
void
F_31 ( void )
{
static T_14 V_51 [] = {
{ & V_8 ,
{ L_3 , L_4 , V_52 , V_53 , NULL ,
0x00 , NULL , V_54 } } ,
{ & V_9 ,
{ L_5 , L_6 , V_55 , V_56 , NULL ,
0x00 , NULL , V_54 } } ,
{ & V_11 ,
{ L_7 , L_8 , V_55 , V_56 , NULL ,
0x00 , NULL , V_54 } } ,
{ & V_39 ,
{ L_9 , L_10 , V_57 , V_56 , NULL ,
0x00 , L_11 , V_54 } } ,
{ & V_40 ,
{ L_9 , L_12 , V_58 , V_59 , NULL ,
0x00 , L_11 , V_54 } } ,
{ & V_41 ,
{ L_13 , L_14 , V_60 , V_56 , NULL ,
0x00 , L_15 , V_54 } } ,
{ & V_43 ,
{ L_16 , L_17 , V_60 , V_56 , NULL ,
0x00 , L_18 , V_54 } } ,
} ;
static T_5 * V_61 [] = {
& V_20 ,
} ;
static T_15 V_62 [] = {
{ & V_27 , { L_19 , V_63 , V_64 , L_20 , V_65 } } ,
{ & V_22 , { L_21 , V_63 , V_66 , L_22 , V_65 } }
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
T_16 * V_67 ;
static T_17 V_68 [ 1 ] = { F_30 } ;
static T_18 V_69 = { F_28 , 1 , V_68 } ;
static T_19 V_70 = {
L_23 , L_24 , L_25 , 1 , 0 ,
& V_69 , NULL , NULL ,
V_71 ,
V_72 ,
V_73 ,
NULL ,
} ;
T_20 * V_74 ;
V_18 = F_32 ( V_75 , L_26 , L_23 ) ;
V_76 = F_33 ( L_27 , L_28 , L_29 , V_18 , V_77 ) ;
V_78 = F_33 ( L_30 , L_31 , L_32 , V_18 , V_77 ) ;
V_79 = F_33 ( L_33 , L_34 , L_35 , V_18 , V_77 ) ;
V_80 = F_33 ( L_36 , L_37 , L_38 , V_18 , V_77 ) ;
V_81 = F_33 ( L_39 , L_40 , L_41 , V_18 , V_77 ) ;
V_82 = F_33 ( L_42 , L_43 , L_44 , V_18 , V_77 ) ;
V_67 = F_34 ( V_18 , NULL ) ;
#if 0
prefs_register_enum_preference(aruba_erm_module, "type.captured",
"Type of formats for captured packets",
"Type of formats for captured packets",
&aruba_erm_type, aruba_erm_types, FALSE);
#endif
F_35 ( V_67 , L_45 ) ;
F_36 ( V_18 , V_51 , F_37 ( V_51 ) ) ;
F_38 ( V_61 , F_37 ( V_61 ) ) ;
V_74 = F_39 ( V_18 ) ;
F_40 ( V_74 , V_62 , F_37 ( V_62 ) ) ;
F_41 ( L_23 , F_8 , V_18 ) ;
V_21 = F_42 (
L_25 , L_24 , V_18 ,
V_55 , V_56 ) ;
F_43 ( & V_70 ) ;
}
void
F_44 ( void )
{
V_47 = F_45 ( L_46 , V_18 ) ;
V_24 = F_45 ( L_47 , V_18 ) ;
V_48 = F_45 ( L_48 , V_18 ) ;
V_25 = F_45 ( L_49 , V_18 ) ;
V_83 = F_46 ( F_8 , V_18 ) ;
V_84 = F_46 ( F_13 , V_76 ) ;
V_85 = F_46 ( F_17 , V_78 ) ;
V_86 = F_46 ( F_20 , V_79 ) ;
V_87 = F_46 ( F_21 , V_80 ) ;
V_88 = F_46 ( F_26 , V_81 ) ;
V_89 = F_46 ( F_27 , V_82 ) ;
F_47 ( L_50 , L_51 , V_83 ) ;
F_48 ( L_25 , V_84 ) ;
F_48 ( L_25 , V_85 ) ;
F_48 ( L_25 , V_86 ) ;
F_48 ( L_25 , V_87 ) ;
F_48 ( L_25 , V_88 ) ;
F_48 ( L_25 , V_89 ) ;
}

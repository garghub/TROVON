static const char * F_1 ( int V_1 , int V_2 )
{
static int V_3 = 0 ;
T_1 V_4 ;
int V_5 ;
int V_6 ;
int V_7 = 1000 ;
if ( 0 == V_3 )
{
for ( V_5 = 1970 ; V_5 < 1980 ; ++ V_5 )
{
V_3 += ( F_2 ( V_5 ) ? 366 : 365 ) * 24 * 60 * 60 ;
}
V_3 += 5 * 24 * 60 * 60 ;
}
V_4 . V_8 = V_1 + V_3 ;
V_6 = ( V_7 * ( ( int ) V_2 & 0xff ) ) / 256 ;
V_4 . V_9 = V_6 * 1000000 ;
return F_3 ( F_4 () , & V_4 , V_10 , TRUE ) ;
}
static void
F_5 ( T_2 * V_11 , T_3 * V_12 , T_4 * V_13 )
{
int V_14 = 0 ;
T_5 * V_15 ;
T_4 * V_16 ;
T_5 * V_17 ;
T_4 * V_18 ;
T_6 V_19 ;
T_7 V_1 ;
T_8 V_2 ;
T_5 * V_20 ;
T_4 * V_21 ;
const char * V_22 ;
T_9 V_23 ;
T_9 V_24 = 0 ;
T_9 V_25 ;
T_8 V_26 = 0 ;
T_9 V_27 = 0 ;
T_5 * V_28 , * V_29 = NULL ;
T_4 * V_30 ;
T_6 V_31 = 0 ;
T_6 V_32 = 0 ;
T_2 * V_33 ;
F_6 ( V_12 -> V_34 , V_35 , L_1 ) ;
F_6 ( V_12 -> V_34 , V_36 , L_2 ) ;
V_19 = F_7 ( V_11 , 0 ) ;
F_8 ( V_12 -> V_34 , V_36 , L_3 , V_19 & V_37 , V_19 & V_37 ) ;
V_25 = F_9 ( V_11 , 0 ) ;
V_23 = F_7 ( V_11 , 4 ) + V_38 + 1 ;
if ( V_23 > V_25 )
V_24 = V_25 ;
else if ( V_23 < V_38 + V_39 )
V_24 = V_38 + V_39 ;
else
V_24 = V_23 ;
V_15 = F_10 ( V_13 , V_40 , V_11 , 0 , V_24 , V_41 ) ;
V_16 = F_11 ( V_15 , V_42 ) ;
V_18 = F_12 ( V_16 , V_11 , V_14 , V_38 ,
V_43 , & V_17 , L_4 ) ;
F_13 ( V_18 , V_44 , V_11 , V_14 , 2 , V_19 ) ;
F_13 ( V_18 , V_45 , V_11 , V_14 , 2 , V_19 ) ;
F_14 ( V_18 , V_46 , V_11 , V_14 , 2 , V_19 ) ;
F_13 ( V_18 , V_47 , V_11 , V_14 , 2 , V_19 ) ;
V_14 += 2 ;
F_10 ( V_18 , V_48 , V_11 , V_14 , 2 , V_49 ) ;
F_10 ( V_18 , V_50 , V_11 , V_14 , 2 , V_49 ) ;
V_14 += 2 ;
V_28 = F_10 ( V_18 , V_51 , V_11 , V_14 , 2 , V_49 ) ;
if ( V_23 > V_25 ) {
F_15 ( V_12 , V_28 , & V_52 ) ;
}
V_14 += 2 ;
F_16 ( V_17 , V_11 , V_14 ) ;
if ( V_19 & V_53 )
{
V_21 = F_12 ( V_16 , V_11 , V_14 , V_39 ,
V_54 , & V_20 , L_5 ) ;
V_1 = F_17 ( V_11 , V_14 ) ;
F_10 ( V_21 , V_55 , V_11 , V_14 , 4 , V_49 ) ;
V_14 += 4 ;
V_2 = F_18 ( V_11 , V_14 ) ;
F_10 ( V_21 , V_56 , V_11 , V_14 , 1 , V_49 ) ;
++ V_14 ;
V_22 = F_1 ( V_1 , V_2 ) ;
F_19 ( V_21 , V_57 , V_11 , V_14 - 5 , 5 , V_22 ) ;
F_10 ( V_21 , V_58 , V_11 , V_14 , 1 , V_49 ) ;
V_29 = F_10 ( V_21 , V_59 , V_11 , V_14 , 1 , V_49 ) ;
switch ( V_60 ) {
case 0 :
V_26 = 0 ;
break;
case 1 :
V_26 = 1 ;
break;
default:
V_26 = ( F_18 ( V_11 , V_14 ) & 0x20 ) >> 5 ;
break;
}
if ( V_19 & V_61 )
{
F_10 ( V_21 , V_62 , V_11 , V_14 , 1 , V_49 ) ;
F_10 ( V_21 , V_63 , V_11 , V_14 , 1 , V_49 ) ;
++ V_14 ;
F_10 ( V_21 , V_64 , V_11 , V_14 , 2 , V_49 ) ;
V_14 += 2 ;
F_10 ( V_21 , V_65 , V_11 , V_14 , 2 , V_49 ) ;
V_14 += 2 ;
}
else
{
F_10 ( V_21 , V_66 , V_11 , V_14 , 1 , V_49 ) ;
++ V_14 ;
F_10 ( V_21 , V_67 , V_11 , V_14 , 2 , V_49 ) ;
F_10 ( V_21 , V_68 , V_11 , V_14 , 2 , V_49 ) ;
F_10 ( V_21 , V_69 , V_11 , V_14 , 2 , V_49 ) ;
F_10 ( V_21 , V_70 , V_11 , V_14 , 2 , V_49 ) ;
V_14 += 2 ;
++ V_14 ;
F_10 ( V_21 , V_71 , V_11 , V_14 , 1 , V_49 ) ;
++ V_14 ;
}
F_16 ( V_20 , V_11 , V_14 ) ;
}
if ( V_25 < V_23 || V_23 < V_38 + V_39 ) {
if ( V_24 > V_14 )
F_10 ( V_16 , V_72 , V_11 , V_14 , V_24 - V_14 , V_41 ) ;
V_14 += V_24 - V_14 ;
if ( V_26 == 1 )
F_15 ( V_12 , V_29 , & V_73 ) ;
}
else {
V_33 = F_20 ( V_11 , V_14 ) ;
if ( ! F_21 ( V_74 , V_19 & V_37 , V_33 , V_12 , V_13 ) ) {
F_10 ( V_16 , V_72 , V_11 , V_14 , V_24 - V_14 - 2 * V_26 , V_41 ) ;
}
V_14 += V_24 - V_14 - 2 * V_26 ;
if ( V_26 == 1 ) {
while ( V_27 < V_23 - 2 ) {
V_32 += F_7 ( V_11 , V_27 ) ;
V_27 += 2 ;
}
V_31 = F_7 ( V_11 , V_14 ) ;
if ( V_32 == V_31 ) {
V_28 = F_22 ( V_16 , V_75 , V_11 , V_14 , 2 , V_31 ,
L_6 , V_31 ) ;
V_30 = F_11 ( V_28 , V_76 ) ;
V_28 = F_14 ( V_30 , V_77 , V_11 , V_14 , 2 , TRUE ) ;
F_23 ( V_28 ) ;
V_28 = F_14 ( V_30 , V_78 , V_11 , V_14 , 2 , FALSE ) ;
F_23 ( V_28 ) ;
} else {
V_28 = F_22 ( V_16 , V_75 , V_11 , V_14 , 2 , V_31 ,
L_7 , V_31 , V_32 ) ;
V_30 = F_11 ( V_28 , V_76 ) ;
V_28 = F_14 ( V_30 , V_77 , V_11 , V_14 , 2 , FALSE ) ;
F_23 ( V_28 ) ;
V_28 = F_14 ( V_30 , V_78 , V_11 , V_14 , 2 , TRUE ) ;
F_23 ( V_28 ) ;
}
V_14 += 2 ;
}
}
F_24 ( V_79 , F_20 ( V_11 , V_14 ) , V_12 , V_13 ) ;
}
void
F_25 ( void )
{
static T_10 V_80 [] = {
{ & V_44 ,
{ L_8 , L_9 ,
V_81 , V_82 , NULL , V_83 ,
NULL , V_84 }
} ,
{ & V_45 ,
{ L_10 , L_11 ,
V_81 , V_82 , F_26 ( V_85 ) , V_61 ,
NULL , V_84 }
} ,
{ & V_46 ,
{ L_12 , L_13 ,
V_86 , 16 , NULL , V_53 ,
L_14 , V_84 }
} ,
{ & V_47 ,
{ L_15 , L_16 ,
V_81 , V_82 , NULL , V_37 ,
NULL , V_84 }
} ,
{ & V_48 ,
{ L_17 , L_18 ,
V_81 , V_82 , F_26 ( V_87 ) , 0xc000 ,
NULL , V_84 }
} ,
{ & V_50 ,
{ L_19 , L_20 ,
V_81 , V_82 , NULL , 0x3fff ,
NULL , V_84 }
} ,
{ & V_51 ,
{ L_21 , L_22 ,
V_81 , V_82 , NULL , 0xffff ,
NULL , V_84 }
} ,
{ & V_55 ,
{ L_23 , L_24 ,
V_88 , V_82 , NULL , 0x0 ,
NULL , V_84 }
} ,
{ & V_56 ,
{ L_25 , L_26 ,
V_89 , V_82 , NULL , 0xff ,
NULL , V_84 }
} ,
{ & V_58 ,
{ L_27 , L_28 ,
V_89 , V_82 , NULL , 0xc0 ,
NULL , V_84 }
} ,
{ & V_59 ,
{ L_29 , L_30 ,
V_86 , 8 , NULL , 0x20 ,
L_31 , V_84 }
} ,
{ & V_62 ,
{ L_32 , L_33 ,
V_89 , V_82 , NULL , 0x10 ,
L_34 , V_84 }
} ,
{ & V_63 ,
{ L_35 , L_36 ,
V_89 , V_82 , NULL , 0x0f ,
NULL , V_84 }
} ,
{ & V_64 ,
{ L_37 , L_38 ,
V_81 , V_82 , NULL , 0x0 ,
NULL , V_84 }
} ,
{ & V_65 ,
{ L_39 , L_40 ,
V_81 , V_82 , NULL , 0x0 ,
NULL , V_84 }
} ,
#if 0
{ &hf_ccsds_spare1,
{ "Spare Bit 1", "ccsds.spare1",
FT_UINT8, BASE_DEC, NULL, 0x10,
"unused spare bit 1", HFILL }
},
#endif
{ & V_66 ,
{ L_41 , L_36 ,
V_89 , V_82 , F_26 ( V_90 ) , 0x0f ,
NULL , V_84 }
} ,
#if 0
{ &hf_ccsds_spare2,
{ "Spare Bit 2", "ccsds.spare2",
FT_UINT16, BASE_DEC, NULL, 0x8000,
NULL, HFILL }
},
#endif
{ & V_67 ,
{ L_42 , L_43 ,
V_81 , V_82 , F_26 ( V_91 ) , 0x7800 ,
NULL , V_84 }
} ,
{ & V_68 ,
{ L_44 , L_45 ,
V_81 , V_82 , F_26 ( V_92 ) , 0x0400 ,
NULL , V_84 }
} ,
{ & V_69 ,
{ L_46 , L_47 ,
V_81 , V_82 , NULL , 0x03c0 ,
NULL , V_84 }
} ,
{ & V_70 ,
{ L_48 , L_49 ,
V_81 , V_82 | V_93 , & V_94 , 0x003f ,
NULL , V_84 }
} ,
#if 0
{ &hf_ccsds_spare3,
{ "Spare Bits 3", "ccsds.spare3",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
#endif
{ & V_71 ,
{ L_50 , L_51 ,
V_89 , V_82 , NULL , 0xff ,
NULL , V_84 }
} ,
{ & V_57 ,
{ L_52 , L_53 ,
V_95 , V_96 , NULL , 0x0 ,
NULL , V_84 }
} ,
{ & V_72 ,
{ L_54 , L_55 ,
V_97 , V_96 , NULL , 0x0 ,
NULL , V_84 }
} ,
{ & V_75 ,
{ L_56 , L_57 ,
V_81 , V_98 , NULL , 0x0 ,
L_58 , V_84 }
} ,
{ & V_77 ,
{ L_59 , L_60 ,
V_86 , V_96 , NULL , 0x0 ,
L_61 , V_84 }
} ,
{ & V_78 ,
{ L_62 , L_63 ,
V_86 , V_96 , NULL , 0x0 ,
L_64 , V_84 }
}
} ;
static T_9 * V_99 [] = {
& V_42 ,
& V_43 ,
& V_54 ,
& V_76
} ;
static T_11 V_100 [] = {
{ & V_52 , { L_65 , V_101 , V_102 , L_66 , V_103 } } ,
{ & V_73 , { L_67 , V_104 , V_105 , L_68 , V_103 } } ,
} ;
T_12 * V_106 ;
T_13 * V_107 ;
V_40 = F_27 ( L_1 , L_1 , L_69 ) ;
F_28 ( V_40 , V_80 , F_29 ( V_80 ) ) ;
F_30 ( V_99 , F_29 ( V_99 ) ) ;
V_107 = F_31 ( V_40 ) ;
F_32 ( V_107 , V_100 , F_29 ( V_100 ) ) ;
F_33 ( L_69 , F_5 , V_40 ) ;
V_106 = F_34 ( V_40 , NULL ) ;
F_35 ( V_106 , L_70 ,
L_71 ,
L_72 ,
& V_60 , V_108 , FALSE ) ;
V_74 = F_36 ( L_16 , L_73 , V_81 , V_82 ) ;
}
void
F_37 ( void )
{
F_38 ( L_74 , F_39 ( L_69 ) ) ;
V_79 = F_39 ( L_75 ) ;
}

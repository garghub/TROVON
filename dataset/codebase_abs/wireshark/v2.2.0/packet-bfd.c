static T_1
F_1 ( T_1 V_1 )
{
T_1 V_2 = 0 ;
switch ( V_1 ) {
case V_3 :
case V_4 :
V_2 = V_5 ;
break;
case V_6 :
case V_7 :
V_2 = V_8 ;
break;
default:
break;
}
return V_2 ;
}
static T_1
F_2 ( T_1 V_1 )
{
T_1 V_9 = 0 ;
switch ( V_1 ) {
case V_3 :
case V_4 :
V_9 = V_10 ;
break;
case V_6 :
case V_7 :
V_9 = V_11 ;
break;
default:
break;
}
return V_9 ;
}
static void
F_3 ( T_2 * V_12 , T_3 * V_13 , T_4 * V_14 )
{
int V_15 = 24 ;
T_1 V_1 ;
T_1 V_2 ;
T_5 * V_16 = NULL ;
T_5 * V_17 = NULL ;
T_4 * V_18 = NULL ;
const T_1 * V_19 ;
V_1 = F_4 ( V_12 , V_15 ) ;
V_2 = F_4 ( V_12 , V_15 + 1 ) ;
if ( V_14 ) {
V_18 = F_5 ( V_14 , V_12 , V_15 , V_2 ,
V_20 , NULL , L_1 ,
F_6 ( V_1 ,
V_21 ,
L_2 ) ) ;
F_7 ( V_18 , V_22 , V_12 , V_15 , 1 , V_23 ) ;
V_16 = F_7 ( V_18 , V_24 , V_12 , V_15 + 1 , 1 , V_23 ) ;
F_8 ( V_16 , L_3 ) ;
F_7 ( V_18 , V_25 , V_12 , V_15 + 2 , 1 , V_23 ) ;
}
switch ( V_1 ) {
case V_26 :
F_9 ( V_18 , V_27 , V_12 , V_15 + 3 ,
V_2 - 3 , V_28 | V_29 , F_10 () , & V_19 ) ;
F_8 ( V_17 , L_4 , V_19 ) ;
break;
case V_3 :
case V_4 :
case V_6 :
case V_7 :
if ( V_2 != F_1 ( V_1 ) ) {
F_11 ( V_18 , V_13 , & V_30 , V_12 , V_15 , V_2 ,
L_5 ,
V_2 , F_6 ( V_1 , V_21 , L_2 ) ) ;
F_8 ( V_17 , L_6 ) ;
}
if ( V_14 ) {
F_7 ( V_18 , V_31 , V_12 , V_15 + 4 , 4 , V_23 ) ;
F_7 ( V_18 , V_32 , V_12 , V_15 + 8 , F_2 ( V_1 ) , V_29 ) ;
}
break;
default:
break;
}
}
static int
F_12 ( T_2 * V_12 , T_3 * V_13 , T_4 * V_14 , void * T_6 V_33 )
{
T_7 V_34 ;
T_7 V_35 ;
T_7 V_36 ;
T_7 V_37 = 0 ;
T_7 V_38 ;
T_7 V_39 = 0 ;
T_7 V_40 ;
T_7 V_41 ;
T_7 V_42 ;
T_7 V_43 ;
T_7 V_44 ;
T_7 V_45 ;
T_7 V_46 ;
T_4 * V_47 = NULL ;
F_13 ( V_13 -> V_48 , V_49 , L_7 ) ;
F_14 ( V_13 -> V_48 , V_50 ) ;
V_35 = ( F_4 ( V_12 , 0 ) & 0xe0 ) >> 5 ;
V_36 = ( F_4 ( V_12 , 0 ) & 0x1f ) ;
V_34 = F_4 ( V_12 , 1 ) ;
switch ( V_35 ) {
case 0 :
V_38 = V_34 ;
break;
case 1 :
default:
V_37 = V_34 & 0xc0 ;
V_38 = V_34 & 0x3e ;
V_39 = V_34 & 0x04 ;
break;
}
V_40 = F_4 ( V_12 , 2 ) ;
V_41 = F_4 ( V_12 , 3 ) ;
V_42 = F_15 ( V_12 , 4 ) ;
V_43 = F_15 ( V_12 , 8 ) ;
V_44 = F_15 ( V_12 , 12 ) ;
V_45 = F_15 ( V_12 , 16 ) ;
V_46 = F_15 ( V_12 , 20 ) ;
switch ( V_35 ) {
case 0 :
F_16 ( V_13 -> V_48 , V_50 , L_8 ,
F_17 ( V_36 , V_51 , L_9 ) ,
V_38 ) ;
break;
case 1 :
default:
F_16 ( V_13 -> V_48 , V_50 , L_10 ,
F_17 ( V_36 , V_52 , L_9 ) ,
F_17 ( V_37 >> 6 , V_53 , L_9 ) ,
V_38 ) ;
break;
}
if ( V_14 ) {
T_5 * V_16 ;
V_16 = F_18 ( V_14 , V_54 , V_12 , 0 , V_41 ,
L_11 ) ;
V_47 = F_19 ( V_16 , V_55 ) ;
F_20 ( V_47 , V_56 , V_12 , 0 ,
1 , V_35 << 5 ) ;
F_20 ( V_47 , V_57 , V_12 , 0 ,
1 , V_36 ) ;
switch ( V_35 ) {
case 0 :
break;
case 1 :
default:
F_20 ( V_47 , V_58 , V_12 , 1 ,
1 , V_37 ) ;
break;
}
switch ( V_35 ) {
case 0 :
{
static const int * V_59 [] = {
& V_60 ,
& V_61 ,
& V_62 ,
& V_63 ,
NULL
} ;
F_21 ( V_47 , V_12 , 1 , V_64 , V_65 , V_59 , V_29 , V_66 ) ;
}
break;
case 1 :
default:
{
static const int * V_59 [] = {
& V_67 ,
& V_68 ,
& V_69 ,
& V_70 ,
& V_71 ,
& V_72 ,
NULL
} ;
F_21 ( V_47 , V_12 , 1 , V_64 , V_65 , V_59 , V_29 , V_66 ) ;
}
break;
}
F_22 ( V_47 , V_73 , V_12 , 2 ,
1 , V_40 ,
L_12 ,
V_40 ,
V_40 * ( V_44 / 1000 ) ) ;
F_22 ( V_47 , V_74 , V_12 , 3 , 1 , V_41 ,
L_13 , V_41 ) ;
F_20 ( V_47 , V_75 , V_12 , 4 ,
4 , V_42 ) ;
F_20 ( V_47 , V_76 , V_12 , 8 ,
4 , V_43 ) ;
F_22 ( V_47 , V_77 , V_12 , 12 ,
4 , V_44 ,
L_14 ,
V_44 / 1000 ,
V_44 ) ;
F_22 ( V_47 , V_78 , V_12 , 16 ,
4 , V_45 ,
L_14 ,
V_45 / 1000 ,
V_45 ) ;
F_22 ( V_47 , V_79 , V_12 , 20 ,
4 , V_46 ,
L_14 ,
V_46 / 1000 ,
V_46 ) ;
}
if ( V_35 && V_39 ) {
if ( V_41 >= 28 ) {
F_3 ( V_12 , V_13 , V_47 ) ;
} else {
F_11 ( V_47 , V_13 , & V_80 , V_12 , 24 , V_41 - 24 ,
L_15 , V_41 ) ;
}
}
return F_23 ( V_12 ) ;
}
void
F_24 ( T_2 * V_12 , T_4 * V_14 , const int V_81 )
{
T_5 * V_16 ;
T_4 * V_47 ;
T_8 V_15 = 0 ;
T_8 V_82 ;
T_8 V_83 ;
T_8 V_84 ;
if ( ! V_14 )
return;
if ( ! V_81 )
{
V_15 = F_4 ( V_12 , 3 ) ;
V_82 = F_25 ( V_12 , V_15 ) ;
V_83 = F_25 ( V_12 , ( V_15 + 2 ) ) ;
V_16 = F_18 ( V_14 , V_54 , V_12 , V_15 , ( V_83 + 4 ) ,
L_16 ) ;
}
else
{
V_82 = F_25 ( V_12 , V_15 ) ;
V_83 = F_25 ( V_12 , ( V_15 + 2 ) ) ;
V_16 = F_18 ( V_14 , V_81 , V_12 , V_15 , ( V_83 + 4 ) ,
L_16 ) ;
}
switch ( V_82 ) {
case V_85 :
V_47 = F_19 ( V_16 , V_55 ) ;
F_20 ( V_47 , V_86 , V_12 , V_15 ,
2 , V_82 ) ;
F_20 ( V_47 , V_87 , V_12 , ( V_15 + 2 ) ,
2 , V_83 ) ;
F_7 ( V_47 , V_88 , V_12 , ( V_15 + 4 ) ,
4 , V_23 ) ;
F_7 ( V_47 , V_89 , V_12 , ( V_15 + 8 ) ,
4 , V_23 ) ;
F_7 ( V_47 , V_90 , V_12 , ( V_15 + 12 ) ,
4 , V_23 ) ;
break;
case V_91 :
V_47 = F_19 ( V_16 , V_55 ) ;
F_20 ( V_47 , V_86 , V_12 , V_15 ,
2 , V_82 ) ;
F_20 ( V_47 , V_87 , V_12 , ( V_15 + 2 ) ,
2 , V_83 ) ;
F_7 ( V_47 , V_88 , V_12 , ( V_15 + 4 ) ,
4 , V_23 ) ;
F_7 ( V_47 , V_89 , V_12 , ( V_15 + 8 ) ,
4 , V_23 ) ;
F_7 ( V_47 , V_92 , V_12 , ( V_15 + 12 ) ,
2 , V_23 ) ;
F_7 ( V_47 , V_93 , V_12 , ( V_15 + 14 ) ,
2 , V_23 ) ;
break;
case V_94 :
V_84 = F_4 ( V_12 , ( V_15 + 17 ) ) ;
V_47 = F_19 ( V_16 , V_55 ) ;
F_20 ( V_47 , V_86 , V_12 , V_15 ,
2 , ( V_82 ) ) ;
F_20 ( V_47 , V_87 , V_12 , ( V_15 + 2 ) ,
2 , V_83 ) ;
F_7 ( V_47 , V_88 , V_12 , ( V_15 + 4 ) ,
4 , V_23 ) ;
F_7 ( V_47 , V_89 , V_12 , ( V_15 + 8 ) ,
4 , V_23 ) ;
F_7 ( V_47 , V_95 , V_12 , ( V_15 + 12 ) ,
4 , V_23 ) ;
F_7 ( V_47 , V_96 , V_12 , ( V_15 + 16 ) ,
1 , V_23 ) ;
F_20 ( V_47 , V_97 , V_12 , ( V_15 + 17 ) ,
1 , V_84 ) ;
F_7 ( V_47 , V_98 , V_12 , ( V_15 + 18 ) ,
V_84 , V_28 | V_29 ) ;
break;
default:
break;
}
return;
}
void
F_26 ( void )
{
static T_9 V_99 [] = {
{ & V_56 ,
{ L_17 , L_18 ,
V_100 , V_101 , NULL , 0xe0 ,
L_19 , V_102 }
} ,
{ & V_57 ,
{ L_20 , L_21 ,
V_100 , V_103 , F_27 ( V_52 ) , 0x1f ,
L_22 , V_102 }
} ,
{ & V_58 ,
{ L_23 , L_24 ,
V_100 , V_103 , F_27 ( V_53 ) , 0xc0 ,
L_25 , V_102 }
} ,
{ & V_64 ,
{ L_26 , L_27 ,
V_100 , V_103 , NULL , 0x00 ,
NULL , V_102 }
} ,
{ & V_60 ,
{ L_28 , L_29 ,
V_104 , 8 , F_28 ( & V_105 ) , 0x80 ,
NULL , V_102 }
} ,
{ & V_61 ,
{ L_30 , L_31 ,
V_104 , 8 , F_28 ( & V_105 ) , 0x40 ,
NULL , V_102 }
} ,
{ & V_62 ,
{ L_32 , L_33 ,
V_104 , 8 , F_28 ( & V_105 ) , 0x20 ,
NULL , V_102 }
} ,
{ & V_63 ,
{ L_34 , L_35 ,
V_104 , 8 , F_28 ( & V_105 ) , 0x10 ,
NULL , V_102 }
} ,
{ & V_67 ,
{ L_32 , L_33 ,
V_104 , 6 , F_28 ( & V_105 ) , 0x20 ,
L_36 ,
V_102 }
} ,
{ & V_68 ,
{ L_34 , L_35 ,
V_104 , 6 , F_28 ( & V_105 ) , 0x10 ,
L_37 ,
V_102 }
} ,
{ & V_69 ,
{ L_38 , L_39 ,
V_104 , 6 , F_28 ( & V_105 ) , 0x08 ,
L_40 , V_102 }
} ,
{ & V_70 ,
{ L_41 , L_42 ,
V_104 , 6 , F_28 ( & V_105 ) , 0x04 ,
L_43 , V_102 }
} ,
{ & V_71 ,
{ L_30 , L_31 ,
V_104 , 6 , F_28 ( & V_105 ) , 0x02 ,
L_44 , V_102 }
} ,
{ & V_72 ,
{ L_45 , L_46 ,
V_104 , 6 , F_28 ( & V_105 ) , 0x01 ,
L_47 , V_102 }
} ,
{ & V_73 ,
{ L_48 , L_49 ,
V_100 , V_101 , NULL , 0x0 ,
L_50 , V_102 }
} ,
{ & V_74 ,
{ L_51 , L_52 ,
V_100 , V_101 , NULL , 0x0 ,
L_53 , V_102 }
} ,
{ & V_75 ,
{ L_54 , L_55 ,
V_106 , V_103 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_76 ,
{ L_56 , L_57 ,
V_106 , V_103 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_77 ,
{ L_58 , L_59 ,
V_106 , V_101 , NULL , 0x0 ,
L_60 , V_102 }
} ,
{ & V_78 ,
{ L_61 , L_62 ,
V_106 , V_101 , NULL , 0x0 ,
L_63 , V_102 }
} ,
{ & V_79 ,
{ L_64 , L_65 ,
V_106 , V_101 , NULL , 0x0 ,
L_66 , V_102 }
} ,
{ & V_32 ,
{ L_67 , L_68 ,
V_107 , V_108 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_22 ,
{ L_69 , L_70 ,
V_100 , V_101 , F_27 ( V_21 ) , 0x0 ,
L_71 , V_102 }
} ,
{ & V_24 ,
{ L_72 , L_73 ,
V_100 , V_101 , NULL , 0x0 ,
L_74 , V_102 }
} ,
{ & V_25 ,
{ L_75 , L_76 ,
V_100 , V_101 , NULL , 0x0 ,
L_77 , V_102 }
} ,
{ & V_27 ,
{ L_78 , L_79 ,
V_109 , V_108 , NULL , 0x0 ,
L_80 , V_102 }
} ,
{ & V_31 ,
{ L_81 , L_82 ,
V_106 , V_103 , NULL , 0x0 ,
L_83 , V_102 }
} ,
{ & V_86 ,
{ L_84 , L_85 ,
V_110 , V_101 , F_27 ( V_111 ) , 0x0 ,
L_86 , V_102 }
} ,
{ & V_87 ,
{ L_87 , L_88 ,
V_110 , V_101 , NULL , 0x0 ,
L_89 , V_102 }
} ,
{ & V_88 ,
{ L_90 , L_91 ,
V_106 , V_101 , NULL , 0x0 ,
L_92 , V_102 }
} ,
{ & V_89 ,
{ L_93 , L_94 ,
V_112 , V_108 , NULL , 0x0 ,
L_95 , V_102 }
} ,
#if 0
{ &hf_mep_interface_no,
{ "Interface Number", "bfd.mep.interface.no",
FT_UINT32, BASE_DEC, NULL , 0x0,
"MPLS-TP Interface Number", HFILL }
},
#endif
{ & V_92 ,
{ L_96 , L_97 ,
V_110 , V_101 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_93 ,
{ L_98 , L_99 ,
V_110 , V_101 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_95 ,
{ L_100 , L_101 ,
V_106 , V_101 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_96 ,
{ L_102 , L_103 ,
V_100 , V_101 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_97 ,
{ L_104 , L_105 ,
V_100 , V_101 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_98 ,
{ L_106 , L_107 ,
V_109 , V_108 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_90 ,
{ L_108 , L_109 ,
V_106 , V_101 , NULL , 0x0 ,
L_110 , V_102 }
}
} ;
static T_8 * V_113 [] = {
& V_55 ,
& V_65 ,
& V_20
} ;
static T_10 V_114 [] = {
{ & V_30 , { L_111 , V_115 , V_116 , L_112 , V_117 } } ,
{ & V_80 , { L_113 , V_115 , V_116 , L_114 , V_117 } } ,
} ;
T_11 * V_118 ;
V_54 = F_29 ( L_115 ,
L_7 ,
L_116 ) ;
F_30 ( L_116 , F_12 , V_54 ) ;
F_31 ( V_54 , V_99 , F_32 ( V_99 ) ) ;
F_33 ( V_113 , F_32 ( V_113 ) ) ;
V_118 = F_34 ( V_54 ) ;
F_35 ( V_118 , V_114 , F_32 ( V_114 ) ) ;
}
void
F_36 ( void )
{
T_12 V_119 ;
V_119 = F_37 ( L_116 ) ;
F_38 ( L_117 , V_120 , V_119 ) ;
F_38 ( L_117 , V_121 , V_119 ) ;
F_38 ( L_118 , V_122 , V_119 ) ;
F_38 ( L_118 , V_123 , V_119 ) ;
F_38 ( L_118 , 0x7 , V_119 ) ;
}

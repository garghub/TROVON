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
T_4 * V_17 = NULL ;
const T_1 * V_18 ;
V_1 = F_4 ( V_12 , V_15 ) ;
V_2 = F_4 ( V_12 , V_15 + 1 ) ;
if ( V_14 ) {
V_17 = F_5 ( V_14 , V_12 , V_15 , V_2 ,
V_19 , NULL , L_1 ,
F_6 ( V_1 ,
V_20 ,
L_2 ) ) ;
F_7 ( V_17 , V_21 , V_12 , V_15 , 1 , V_22 ) ;
F_7 ( V_17 , V_23 , V_12 , V_15 + 1 , 1 , V_22 ) ;
F_7 ( V_17 , V_24 , V_12 , V_15 + 2 , 1 , V_22 ) ;
}
switch ( V_1 ) {
case V_25 :
F_8 ( V_17 , V_26 , V_12 , V_15 + 3 ,
V_2 - 3 , V_27 | V_28 , F_9 () , & V_18 ) ;
F_10 ( V_16 , L_3 , V_18 ) ;
break;
case V_3 :
case V_4 :
case V_6 :
case V_7 :
if ( V_2 != F_1 ( V_1 ) ) {
F_11 ( V_17 , V_13 , & V_29 , V_12 , V_15 , V_2 ,
L_4 ,
V_2 , F_6 ( V_1 , V_20 , L_2 ) ) ;
F_10 ( V_16 , L_5 ) ;
}
if ( V_14 ) {
F_7 ( V_17 , V_30 , V_12 , V_15 + 4 , 4 , V_22 ) ;
F_7 ( V_17 , V_31 , V_12 , V_15 + 8 , F_2 ( V_1 ) , V_28 ) ;
}
break;
default:
break;
}
}
static int
F_12 ( T_2 * V_12 , T_3 * V_13 , T_4 * V_14 , void * T_6 V_32 )
{
T_7 V_33 ;
T_7 V_34 ;
T_7 V_35 ;
T_7 V_36 = 0 ;
T_7 V_37 ;
T_7 V_38 = 0 ;
T_7 V_39 ;
T_7 V_40 ;
T_7 V_41 ;
T_7 V_42 ;
T_7 V_43 ;
T_7 V_44 ;
T_7 V_45 ;
T_4 * V_46 = NULL ;
F_13 ( V_13 -> V_47 , V_48 , L_6 ) ;
F_14 ( V_13 -> V_47 , V_49 ) ;
V_34 = ( F_4 ( V_12 , 0 ) & 0xe0 ) >> 5 ;
V_35 = ( F_4 ( V_12 , 0 ) & 0x1f ) ;
V_33 = F_4 ( V_12 , 1 ) ;
switch ( V_34 ) {
case 0 :
V_37 = V_33 ;
break;
case 1 :
default:
V_36 = V_33 & 0xc0 ;
V_37 = V_33 & 0x3e ;
V_38 = V_33 & 0x04 ;
break;
}
V_39 = F_4 ( V_12 , 2 ) ;
V_40 = F_4 ( V_12 , 3 ) ;
V_41 = F_15 ( V_12 , 4 ) ;
V_42 = F_15 ( V_12 , 8 ) ;
V_43 = F_15 ( V_12 , 12 ) ;
V_44 = F_15 ( V_12 , 16 ) ;
V_45 = F_15 ( V_12 , 20 ) ;
switch ( V_34 ) {
case 0 :
F_16 ( V_13 -> V_47 , V_49 , L_7 ,
F_17 ( V_35 , V_50 , L_8 ) ,
V_37 ) ;
break;
case 1 :
default:
F_16 ( V_13 -> V_47 , V_49 , L_9 ,
F_17 ( V_35 , V_51 , L_8 ) ,
F_17 ( V_36 >> 6 , V_52 , L_8 ) ,
V_37 ) ;
break;
}
if ( V_14 ) {
T_5 * V_53 ;
V_53 = F_18 ( V_14 , V_54 , V_12 , 0 , V_40 ,
L_10 ) ;
V_46 = F_19 ( V_53 , V_55 ) ;
F_20 ( V_46 , V_56 , V_12 , 0 ,
1 , V_34 << 5 ) ;
F_20 ( V_46 , V_57 , V_12 , 0 ,
1 , V_35 ) ;
switch ( V_34 ) {
case 0 :
break;
case 1 :
default:
F_20 ( V_46 , V_58 , V_12 , 1 ,
1 , V_36 ) ;
break;
}
switch ( V_34 ) {
case 0 :
{
static const int * V_59 [] = {
& V_60 ,
& V_61 ,
& V_62 ,
& V_63 ,
NULL
} ;
F_21 ( V_46 , V_12 , 1 , V_64 , V_65 , V_59 , V_28 , V_66 ) ;
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
F_21 ( V_46 , V_12 , 1 , V_64 , V_65 , V_59 , V_28 , V_66 ) ;
}
break;
}
F_22 ( V_46 , V_73 , V_12 , 2 ,
1 , V_39 ,
L_11 ,
V_39 ,
V_39 * ( V_43 / 1000 ) ) ;
F_20 ( V_46 , V_74 , V_12 , 3 , 1 , V_40 ) ;
F_20 ( V_46 , V_75 , V_12 , 4 ,
4 , V_41 ) ;
F_20 ( V_46 , V_76 , V_12 , 8 ,
4 , V_42 ) ;
F_22 ( V_46 , V_77 , V_12 , 12 ,
4 , V_43 ,
L_12 ,
V_43 / 1000 ,
V_43 ) ;
F_22 ( V_46 , V_78 , V_12 , 16 ,
4 , V_44 ,
L_12 ,
V_44 / 1000 ,
V_44 ) ;
F_22 ( V_46 , V_79 , V_12 , 20 ,
4 , V_45 ,
L_12 ,
V_45 / 1000 ,
V_45 ) ;
}
if ( V_34 && V_38 ) {
if ( V_40 >= 28 ) {
F_3 ( V_12 , V_13 , V_46 ) ;
} else {
F_11 ( V_46 , V_13 , & V_80 , V_12 , 24 , V_40 - 24 ,
L_13 , V_40 ) ;
}
}
return F_23 ( V_12 ) ;
}
void
F_24 ( T_2 * V_12 , T_4 * V_14 , const int V_81 )
{
T_5 * V_53 ;
T_4 * V_46 ;
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
V_53 = F_18 ( V_14 , V_54 , V_12 , V_15 , ( V_83 + 4 ) ,
L_14 ) ;
}
else
{
V_82 = F_25 ( V_12 , V_15 ) ;
V_83 = F_25 ( V_12 , ( V_15 + 2 ) ) ;
V_53 = F_18 ( V_14 , V_81 , V_12 , V_15 , ( V_83 + 4 ) ,
L_14 ) ;
}
switch ( V_82 ) {
case V_85 :
V_46 = F_19 ( V_53 , V_55 ) ;
F_20 ( V_46 , V_86 , V_12 , V_15 ,
2 , V_82 ) ;
F_20 ( V_46 , V_87 , V_12 , ( V_15 + 2 ) ,
2 , V_83 ) ;
F_7 ( V_46 , V_88 , V_12 , ( V_15 + 4 ) ,
4 , V_22 ) ;
F_7 ( V_46 , V_89 , V_12 , ( V_15 + 8 ) ,
4 , V_22 ) ;
F_7 ( V_46 , V_90 , V_12 , ( V_15 + 12 ) ,
4 , V_22 ) ;
break;
case V_91 :
V_46 = F_19 ( V_53 , V_55 ) ;
F_20 ( V_46 , V_86 , V_12 , V_15 ,
2 , V_82 ) ;
F_20 ( V_46 , V_87 , V_12 , ( V_15 + 2 ) ,
2 , V_83 ) ;
F_7 ( V_46 , V_88 , V_12 , ( V_15 + 4 ) ,
4 , V_22 ) ;
F_7 ( V_46 , V_89 , V_12 , ( V_15 + 8 ) ,
4 , V_22 ) ;
F_7 ( V_46 , V_92 , V_12 , ( V_15 + 12 ) ,
2 , V_22 ) ;
F_7 ( V_46 , V_93 , V_12 , ( V_15 + 14 ) ,
2 , V_22 ) ;
break;
case V_94 :
V_84 = F_4 ( V_12 , ( V_15 + 17 ) ) ;
V_46 = F_19 ( V_53 , V_55 ) ;
F_20 ( V_46 , V_86 , V_12 , V_15 ,
2 , ( V_82 ) ) ;
F_20 ( V_46 , V_87 , V_12 , ( V_15 + 2 ) ,
2 , V_83 ) ;
F_7 ( V_46 , V_88 , V_12 , ( V_15 + 4 ) ,
4 , V_22 ) ;
F_7 ( V_46 , V_89 , V_12 , ( V_15 + 8 ) ,
4 , V_22 ) ;
F_7 ( V_46 , V_95 , V_12 , ( V_15 + 12 ) ,
4 , V_22 ) ;
F_7 ( V_46 , V_96 , V_12 , ( V_15 + 16 ) ,
1 , V_22 ) ;
F_20 ( V_46 , V_97 , V_12 , ( V_15 + 17 ) ,
1 , V_84 ) ;
F_7 ( V_46 , V_98 , V_12 , ( V_15 + 18 ) ,
V_84 , V_27 | V_28 ) ;
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
{ L_15 , L_16 ,
V_100 , V_101 , NULL , 0xe0 ,
L_17 , V_102 }
} ,
{ & V_57 ,
{ L_18 , L_19 ,
V_100 , V_103 , F_27 ( V_51 ) , 0x1f ,
L_20 , V_102 }
} ,
{ & V_58 ,
{ L_21 , L_22 ,
V_100 , V_103 , F_27 ( V_52 ) , 0xc0 ,
L_23 , V_102 }
} ,
{ & V_64 ,
{ L_24 , L_25 ,
V_100 , V_103 , NULL , 0x00 ,
NULL , V_102 }
} ,
{ & V_60 ,
{ L_26 , L_27 ,
V_104 , 8 , F_28 ( & V_105 ) , 0x80 ,
NULL , V_102 }
} ,
{ & V_61 ,
{ L_28 , L_29 ,
V_104 , 8 , F_28 ( & V_105 ) , 0x40 ,
NULL , V_102 }
} ,
{ & V_62 ,
{ L_30 , L_31 ,
V_104 , 8 , F_28 ( & V_105 ) , 0x20 ,
NULL , V_102 }
} ,
{ & V_63 ,
{ L_32 , L_33 ,
V_104 , 8 , F_28 ( & V_105 ) , 0x10 ,
NULL , V_102 }
} ,
{ & V_67 ,
{ L_30 , L_31 ,
V_104 , 6 , F_28 ( & V_105 ) , 0x20 ,
L_34 ,
V_102 }
} ,
{ & V_68 ,
{ L_32 , L_33 ,
V_104 , 6 , F_28 ( & V_105 ) , 0x10 ,
L_35 ,
V_102 }
} ,
{ & V_69 ,
{ L_36 , L_37 ,
V_104 , 6 , F_28 ( & V_105 ) , 0x08 ,
L_38 , V_102 }
} ,
{ & V_70 ,
{ L_39 , L_40 ,
V_104 , 6 , F_28 ( & V_105 ) , 0x04 ,
L_41 , V_102 }
} ,
{ & V_71 ,
{ L_28 , L_29 ,
V_104 , 6 , F_28 ( & V_105 ) , 0x02 ,
L_42 , V_102 }
} ,
{ & V_72 ,
{ L_43 , L_44 ,
V_104 , 6 , F_28 ( & V_105 ) , 0x01 ,
L_45 , V_102 }
} ,
{ & V_73 ,
{ L_46 , L_47 ,
V_100 , V_101 , NULL , 0x0 ,
L_48 , V_102 }
} ,
{ & V_74 ,
{ L_49 , L_50 ,
V_100 , V_101 | V_106 , & V_107 , 0x0 ,
L_51 , V_102 }
} ,
{ & V_75 ,
{ L_52 , L_53 ,
V_108 , V_103 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_76 ,
{ L_54 , L_55 ,
V_108 , V_103 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_77 ,
{ L_56 , L_57 ,
V_108 , V_101 , NULL , 0x0 ,
L_58 , V_102 }
} ,
{ & V_78 ,
{ L_59 , L_60 ,
V_108 , V_101 , NULL , 0x0 ,
L_61 , V_102 }
} ,
{ & V_79 ,
{ L_62 , L_63 ,
V_108 , V_101 , NULL , 0x0 ,
L_64 , V_102 }
} ,
{ & V_31 ,
{ L_65 , L_66 ,
V_109 , V_110 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_21 ,
{ L_67 , L_68 ,
V_100 , V_101 , F_27 ( V_20 ) , 0x0 ,
L_69 , V_102 }
} ,
{ & V_23 ,
{ L_70 , L_71 ,
V_100 , V_101 | V_106 , & V_107 , 0x0 ,
L_72 , V_102 }
} ,
{ & V_24 ,
{ L_73 , L_74 ,
V_100 , V_101 , NULL , 0x0 ,
L_75 , V_102 }
} ,
{ & V_26 ,
{ L_76 , L_77 ,
V_111 , V_110 , NULL , 0x0 ,
L_78 , V_102 }
} ,
{ & V_30 ,
{ L_79 , L_80 ,
V_108 , V_103 , NULL , 0x0 ,
L_81 , V_102 }
} ,
{ & V_86 ,
{ L_82 , L_83 ,
V_112 , V_101 , F_27 ( V_113 ) , 0x0 ,
L_84 , V_102 }
} ,
{ & V_87 ,
{ L_85 , L_86 ,
V_112 , V_101 , NULL , 0x0 ,
L_87 , V_102 }
} ,
{ & V_88 ,
{ L_88 , L_89 ,
V_108 , V_101 , NULL , 0x0 ,
L_90 , V_102 }
} ,
{ & V_89 ,
{ L_91 , L_92 ,
V_114 , V_110 , NULL , 0x0 ,
L_93 , V_102 }
} ,
#if 0
{ &hf_mep_interface_no,
{ "Interface Number", "bfd.mep.interface.no",
FT_UINT32, BASE_DEC, NULL , 0x0,
"MPLS-TP Interface Number", HFILL }
},
#endif
{ & V_92 ,
{ L_94 , L_95 ,
V_112 , V_101 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_93 ,
{ L_96 , L_97 ,
V_112 , V_101 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_95 ,
{ L_98 , L_99 ,
V_108 , V_101 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_96 ,
{ L_100 , L_101 ,
V_100 , V_101 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_97 ,
{ L_102 , L_103 ,
V_100 , V_101 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_98 ,
{ L_104 , L_105 ,
V_111 , V_110 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_90 ,
{ L_106 , L_107 ,
V_108 , V_101 , NULL , 0x0 ,
L_108 , V_102 }
}
} ;
static T_8 * V_115 [] = {
& V_55 ,
& V_65 ,
& V_19
} ;
static T_10 V_116 [] = {
{ & V_29 , { L_109 , V_117 , V_118 , L_110 , V_119 } } ,
{ & V_80 , { L_111 , V_117 , V_118 , L_112 , V_119 } } ,
} ;
T_11 * V_120 ;
V_54 = F_29 ( L_113 ,
L_6 ,
L_114 ) ;
V_121 = F_30 ( L_114 , F_12 , V_54 ) ;
F_31 ( V_54 , V_99 , F_32 ( V_99 ) ) ;
F_33 ( V_115 , F_32 ( V_115 ) ) ;
V_120 = F_34 ( V_54 ) ;
F_35 ( V_120 , V_116 , F_32 ( V_116 ) ) ;
}
void
F_36 ( void )
{
F_37 ( L_115 , V_122 , V_121 ) ;
F_38 ( L_116 , V_123 , V_121 ) ;
F_38 ( L_116 , V_124 , V_121 ) ;
F_38 ( L_116 , V_125 , V_121 ) ;
}

static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 0 ;
T_4 * V_5 = NULL ;
T_3 * V_6 = NULL ;
T_4 * V_7 = NULL ;
T_3 * V_8 = NULL ;
T_4 * V_9 = NULL ;
T_3 * V_10 = NULL ;
T_5 V_11 ;
T_6 * V_12 ;
T_7 * V_13 = NULL ;
T_8 V_14 ;
if ( F_2 ( V_1 ) < 16 )
return 0 ;
if ( V_15 ) {
if ( ( F_3 ( & V_2 -> V_16 , & V_17 [ 0 ] ) &&
F_3 ( & V_2 -> V_18 , & V_17 [ 1 ] ) &&
( V_2 -> V_19 == 0xffffffff || V_2 -> V_19 == V_20 [ 0 ] ) &&
( V_2 -> V_21 == 0xffffffff || V_2 -> V_21 == V_20 [ 1 ] ) ) ||
( F_3 ( & V_2 -> V_16 , & V_17 [ 1 ] ) &&
F_3 ( & V_2 -> V_18 , & V_17 [ 0 ] ) &&
( V_2 -> V_19 == 0xffffffff || V_2 -> V_19 == V_20 [ 1 ] ) &&
( V_2 -> V_21 == 0xffffffff || V_2 -> V_21 == V_20 [ 0 ] ) ) )
goto V_22;
}
V_12 = F_4 ( V_2 -> V_23 -> V_24 , & V_2 -> V_16 , & V_2 -> V_18 ,
V_25 , V_2 -> V_19 , V_2 -> V_21 , 0 ) ;
if ( ! V_12 ) {
V_12 = F_4 ( V_2 -> V_23 -> V_24 , & V_2 -> V_18 , & V_2 -> V_18 ,
V_25 , V_2 -> V_21 , V_2 -> V_21 , V_26 | V_27 ) ;
if ( ! V_12 )
return 0 ;
}
if ( V_28 < 0 ) {
V_14 = F_5 ( L_1 ) ;
if ( ! V_14 )
return 0 ;
V_28 = F_6 ( V_14 ) ;
}
V_13 = F_7 ( V_12 , V_28 ) ;
if ( ! ( V_13 -> V_29 & V_30 ) )
return 0 ;
V_22:
F_8 ( V_2 -> V_31 , V_32 , L_2 ) ;
V_5 = F_9 ( V_3 , V_33 , V_1 , V_4 , - 1 , V_34 ) ;
V_6 = F_10 ( V_5 , V_35 ) ;
V_7 = F_9 ( V_6 , V_36 , V_1 , V_4 , 16 , V_34 ) ;
V_8 = F_10 ( V_7 , V_37 ) ;
V_11 = F_11 ( V_1 , V_4 ) ;
F_9 ( V_8 , V_38 , V_1 , V_4 , 1 , V_39 ) ; V_4 += 1 ;
F_9 ( V_8 , V_40 , V_1 , V_4 , 1 , V_39 ) ;
F_9 ( V_8 , V_41 , V_1 , V_4 , 2 , V_39 ) ;
F_9 ( V_8 , V_42 , V_1 , V_4 , 4 , V_39 ) ;
F_9 ( V_8 , V_43 , V_1 , V_4 , 4 , V_39 ) ; V_4 += 1 ;
F_9 ( V_8 , V_44 , V_1 , V_4 , 2 , V_39 ) ; V_4 += 2 ;
F_9 ( V_8 , V_45 , V_1 , V_4 , 4 , V_39 ) ; V_4 += 4 ;
F_9 ( V_8 , V_46 , V_1 , V_4 , 4 , V_39 ) ; V_4 += 4 ;
F_9 ( V_8 , V_47 , V_1 , V_4 , 4 , V_39 ) ; V_4 += 4 ;
switch ( V_11 ) {
case V_48 :
V_9 = F_9 ( V_6 , V_49 , V_1 , V_4 , 48 , V_34 ) ;
V_10 = F_10 ( V_9 , V_50 ) ;
F_9 ( V_10 , V_51 , V_1 , V_4 , 1 , V_39 ) ;
F_9 ( V_10 , V_52 , V_1 , V_4 , 1 , V_39 ) ; V_4 += 1 ;
F_9 ( V_10 , V_53 , V_1 , V_4 , 1 , V_39 ) ;
F_9 ( V_10 , V_54 , V_1 , V_4 , 1 , V_39 ) ;
F_9 ( V_10 , V_55 , V_1 , V_4 , 1 , V_39 ) ;
F_9 ( V_10 , V_56 , V_1 , V_4 , 1 , V_39 ) ; V_4 += 1 ;
V_4 += 1 ;
F_9 ( V_10 , V_57 , V_1 , V_4 , 1 , V_39 ) ; V_4 += 1 ;
F_9 ( V_10 , V_58 , V_1 , V_4 , 4 , V_39 ) ; V_4 += 4 ;
F_9 ( V_10 , V_59 , V_1 , V_4 , 4 , V_39 ) ; V_4 += 4 ;
F_9 ( V_10 , V_60 , V_1 , V_4 , 2 , V_39 ) ; V_4 += 2 ;
V_4 += 2 ;
F_9 ( V_10 , V_61 , V_1 , V_4 , 16 , V_34 ) ; V_4 += 16 ;
F_9 ( V_10 , V_62 , V_1 , V_4 , 16 , V_34 ) ; V_4 += 16 ;
V_4 += 2 ;
F_9 ( V_10 , V_63 , V_1 , V_4 , 2 , V_39 ) ;
break;
case V_64 :
F_9 ( V_6 , V_65 , V_1 , V_4 , 48 , V_34 ) ;
break;
case V_66 :
break;
case V_67 :
break;
case V_68 :
break;
case V_69 :
F_9 ( V_6 , V_70 , V_1 , V_4 , 48 , V_34 ) ;
break;
case V_71 :
F_9 ( V_6 , V_72 , V_1 , V_4 , 48 , V_34 ) ;
break;
case V_73 :
F_9 ( V_8 , V_74 , V_1 , V_4 , 48 , V_34 ) ;
break;
case V_75 :
break;
case V_76 :
break;
case V_77 :
break;
case V_78 :
F_9 ( V_6 , V_79 , V_1 , V_4 , 48 , V_34 ) ;
break;
case V_80 :
F_9 ( V_6 , V_81 , V_1 , V_4 , 48 , V_34 ) ;
break;
case V_82 :
F_9 ( V_6 , V_83 , V_1 , V_4 , 48 , V_34 ) ;
break;
case V_84 :
break;
case V_85 :
F_9 ( V_6 , V_86 , V_1 , V_4 , 48 , V_34 ) ;
break;
case V_87 :
F_9 ( V_6 , V_88 , V_1 , V_4 , 48 , V_34 ) ;
break;
case V_89 :
F_9 ( V_6 , V_90 , V_1 , V_4 , - 1 , V_34 ) ;
break;
default:
break;
}
F_12 ( V_2 -> V_31 , V_91 , L_3 ,
F_13 ( V_11 , V_92 , L_4 ) ) ;
return F_2 ( V_1 ) ;
}
void
F_14 ( void )
{
T_9 * V_93 ;
static T_10 V_94 [] = {
{ & V_33 , {
L_2 , L_5 ,
V_95 , V_96 , NULL , 0x0 , NULL , V_97 }
} ,
{ & V_36 , {
L_6 , L_7 ,
V_95 , V_96 , NULL , 0x0 , NULL , V_97 }
} ,
{ & V_38 , {
L_8 , L_9 ,
V_98 , V_99 | V_100 , F_15 ( V_92 ) , 0x0 , NULL , V_97 }
} ,
{ & V_40 , {
L_10 , L_11 ,
V_98 , V_99 , NULL , 0x0 , NULL , V_97 }
} ,
{ & V_41 , {
L_12 , L_13 ,
V_98 , V_99 , NULL , 0x1 , L_14 , V_97 }
} ,
{ & V_42 , {
L_15 , L_16 ,
V_98 , V_99 , NULL , 0x2 , L_17 , V_97 }
} ,
{ & V_43 , {
L_18 , L_19 ,
V_98 , V_99 , NULL , 0x4 , L_20 , V_97 }
} ,
{ & V_44 , {
L_21 , L_22 ,
V_101 , V_102 , NULL , 0x0 , NULL , V_97 }
} ,
{ & V_45 , {
L_23 , L_24 ,
V_103 , V_102 , NULL , 0x0 , NULL , V_97 }
} ,
{ & V_46 , {
L_25 , L_26 ,
V_103 , V_99 , NULL , 0x0 , L_27 , V_97 }
} ,
{ & V_47 , {
L_28 , L_29 ,
V_103 , V_99 , NULL , 0x0 , L_30 , V_97 }
} ,
{ & V_49 , {
L_31 , L_32 ,
V_95 , V_96 , NULL , 0x00 , NULL , V_97 }
} ,
{ & V_51 , {
L_33 , L_34 ,
V_98 , V_99 , NULL , 0xf0 , NULL , V_97 }
} ,
{ & V_52 , {
L_35 , L_36 ,
V_98 , V_99 , NULL , 0x0f , NULL , V_97 }
} ,
{ & V_53 ,
{ L_37 , L_38 ,
V_98 , V_99 , NULL , 0xf0 , NULL , V_97 }
} ,
{ & V_54 , {
L_39 , L_40 ,
V_98 , V_99 , NULL , 0x0f , NULL , V_97 }
} ,
{ & V_55 , {
L_41 , L_42 ,
V_98 , V_99 , NULL , 0x1 , L_43 , V_97 }
} ,
{ & V_56 , {
L_44 , L_45 ,
V_98 , V_99 , NULL , 0x2 , L_46 , V_97 }
} ,
{ & V_57 , {
L_47 , L_48 ,
V_98 , V_99 , NULL , 0x0 , NULL , V_97 }
} ,
{ & V_58 , {
L_49 , L_50 ,
V_103 , V_102 , NULL , 0x0 , L_51 , V_97 }
} ,
{ & V_59 ,
{ L_52 , L_53 ,
V_103 , V_102 , NULL , 0x0 , L_54 , V_97 }
} ,
{ & V_60 , {
L_55 , L_56 ,
V_101 , V_102 , NULL , 0x0 , NULL , V_97 }
} ,
{ & V_61 , {
L_57 , L_58 ,
V_104 , V_96 , NULL , 0x0 , NULL , V_97 }
} ,
{ & V_62 , {
L_59 , L_60 ,
V_104 , V_96 , NULL , 0x0 , NULL , V_97 }
} ,
{ & V_63 , {
L_61 , L_62 ,
V_101 , V_99 , NULL , 0x0 , NULL , V_97 }
} ,
{ & V_65 , {
L_63 , L_64 ,
V_95 , V_96 , NULL , 0x00 , NULL , V_97 }
} ,
{ & V_70 , {
L_65 , L_66 ,
V_95 , V_96 , NULL , 0x00 , L_67 , V_97 }
} ,
{ & V_72 , {
L_68 , L_69 ,
V_95 , V_96 , NULL , 0x00 , L_70 , V_97 }
} ,
{ & V_74 , {
L_71 , L_72 ,
V_95 , V_96 , NULL , 0x00 , NULL , V_97 }
} ,
{ & V_79 , {
L_73 , L_74 ,
V_95 , V_96 , NULL , 0x00 , L_75 , V_97 }
} ,
{ & V_81 , {
L_76 , L_77 ,
V_95 , V_96 , NULL , 0x00 , L_78 , V_97 }
} ,
{ & V_83 , {
L_79 , L_80 ,
V_95 , V_96 , NULL , 0x00 , L_81 , V_97 }
} ,
{ & V_86 , {
L_82 , L_83 ,
V_95 , V_96 , NULL , 0x00 , L_84 , V_97 }
} ,
{ & V_88 , {
L_85 , L_86 ,
V_95 , V_96 , NULL , 0x00 , L_87 , V_97 }
} ,
{ & V_90 , {
L_88 , L_89 ,
V_95 , V_96 , NULL , 0x0 , NULL , V_97 }
}
} ;
static T_11 * V_105 [] = {
& V_35 ,
& V_37 ,
& V_50 ,
} ;
V_106 = F_16 ( L_90 , L_91 , L_92 ) ;
F_17 ( L_5 , F_1 , V_106 ) ;
F_18 ( V_106 , V_94 , F_19 ( V_94 ) ) ;
F_20 ( V_105 , F_19 ( V_105 ) ) ;
V_93 = F_21 ( V_106 , V_107 ) ;
F_22 ( V_93 , L_93 , L_94 ,
L_95 ,
& V_15 ) ;
F_23 ( V_93 , L_96 , L_97 ,
L_98 ) ;
F_24 ( V_93 , L_99 , L_100 ,
L_101 , & V_108 [ 0 ] , V_109 , FALSE ) ;
F_25 ( V_93 , L_102 , L_103 ,
L_104 , & V_110 [ 0 ] ) ;
F_26 ( V_93 , L_105 , L_106 ,
L_107 , 10 , & V_20 [ 0 ] ) ;
F_23 ( V_93 , L_108 , L_109 ,
L_110 ) ;
F_24 ( V_93 , L_111 , L_100 ,
L_101 , & V_108 [ 1 ] , V_109 , FALSE ) ;
F_25 ( V_93 , L_112 , L_103 ,
L_113 , & V_110 [ 1 ] ) ;
F_26 ( V_93 , L_114 , L_106 ,
L_115 , 10 , & V_20 [ 1 ] ) ;
}
void
V_107 ( void )
{
static T_12 V_111 = FALSE ;
if ( ! V_111 ) {
F_27 ( L_116 , F_1 , V_106 ) ;
F_27 ( L_117 , F_1 , V_106 ) ;
V_112 [ 0 ] = F_28 ( V_113 ) ;
V_112 [ 1 ] = F_28 ( V_113 ) ;
V_111 = TRUE ;
}
if ( V_15 ) {
T_12 V_114 = FALSE ;
char * V_115 ;
int V_116 ;
for ( V_116 = 0 ; V_116 < 2 ; V_116 ++ ) {
if ( V_108 [ V_116 ] == 0 ) {
V_117 = 0 ;
* ( ( V_118 * ) V_112 [ V_116 ] ) = ( V_118 ) strtoul ( V_110 [ V_116 ] , & V_115 , 0 ) ;
if ( V_117 || * V_115 != '\0' ) {
V_114 = TRUE ;
} else {
F_29 ( & V_17 [ V_116 ] , V_119 , sizeof( V_118 ) , V_112 [ V_116 ] ) ;
}
} else {
if ( ! F_30 ( V_120 , V_110 [ V_116 ] , V_112 [ V_116 ] ) ) {
V_114 = TRUE ;
} else {
F_29 ( & V_17 [ V_116 ] , V_119 , V_113 , V_112 [ V_116 ] ) ;
}
}
if ( V_114 ) {
V_15 = FALSE ;
break;
}
}
}
}

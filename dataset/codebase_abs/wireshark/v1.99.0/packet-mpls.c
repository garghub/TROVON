static void F_1 ( T_1 * V_1 , T_2 * V_2 )
{
F_2 ( V_2 , V_3 , L_1 ,
F_3 ( F_4 ( V_1 -> V_4 , V_1 , V_5 , 0 ) ) ) ;
}
static T_3 F_5 ( T_1 * V_1 )
{
return F_4 ( V_1 -> V_4 , V_1 , V_5 , 0 ) ;
}
void
F_6 ( T_4 * V_6 , int V_7 ,
T_5 * V_8 , T_6 * exp ,
T_6 * V_9 , T_6 * V_10 )
{
T_6 V_11 = F_7 ( V_6 , V_7 + 0 ) ;
T_6 V_12 = F_7 ( V_6 , V_7 + 1 ) ;
T_6 V_13 = F_7 ( V_6 , V_7 + 2 ) ;
* V_8 = ( V_11 << 12 ) + ( V_12 << 4 ) + ( ( V_13 >> 4 ) & 0xff ) ;
* exp = ( V_13 >> 1 ) & 0x7 ;
* V_9 = ( V_13 & 0x1 ) ;
* V_10 = F_7 ( V_6 , V_7 + 3 ) ;
}
static void
F_8 ( T_4 * V_6 , T_1 * V_1 , T_7 * V_14 )
{
T_4 * V_15 ;
T_8 V_16 ;
if ( F_9 ( V_6 , 0 ) < 4 ) {
F_10 ( V_14 , V_6 , 0 , - 1 , L_2 ) ;
return;
}
V_16 = F_11 ( V_6 , 2 ) ;
if ( V_14 ) {
T_7 * V_17 ;
T_9 * V_18 ;
T_8 V_19 ;
V_18 = F_12 ( V_14 , V_20 , V_6 , 0 , 4 , V_21 ) ;
V_17 = F_13 ( V_18 , V_22 ) ;
F_12 ( V_17 , V_23 ,
V_6 , 0 , 1 , V_24 ) ;
V_19 = F_7 ( V_6 , 1 ) ;
V_18 = F_14 ( V_17 , V_25 ,
V_6 , 1 , 1 , V_19 ) ;
if ( V_19 != 0 )
F_10 ( V_17 , V_6 , 1 , 1 ,
L_3 ) ;
else
F_15 ( V_18 ) ;
F_16 ( V_17 , V_26 ,
V_6 , 2 , 2 , V_16 ,
L_4 ,
F_17 ( V_16 , & V_27 , L_5 ) ,
V_16 ) ;
}
V_15 = F_18 ( V_6 , 4 ) ;
switch ( V_16 ) {
case V_28 :
F_19 ( V_29 , V_15 , V_1 , V_14 ) ;
break;
case V_30 :
F_19 ( V_29 , V_15 , V_1 , V_14 ) ;
F_20 ( V_15 , V_14 , 0 ) ;
break;
case V_31 :
F_21 ( V_15 , V_1 , V_14 , NULL ) ;
break;
case 0x21 :
F_19 ( V_32 , V_15 , V_1 , V_14 ) ;
break;
case 0x7 :
F_19 ( V_29 , V_15 , V_1 , V_14 ) ;
break;
case 0x57 :
F_19 ( V_33 , V_15 , V_1 , V_14 ) ;
break;
case 0x000A :
F_19 ( V_34 , V_15 , V_1 , V_14 ) ;
break;
case 0x000B :
F_19 ( V_35 , V_15 , V_1 , V_14 ) ;
break;
case 0x000C :
F_19 ( V_36 , V_15 , V_1 , V_14 ) ;
break;
case 0x000D :
F_19 ( V_37 , V_15 , V_1 , V_14 ) ;
break;
case 0x000E :
F_19 ( V_38 , V_15 , V_1 , V_14 ) ;
break;
case 0x0024 :
F_19 ( V_39 , V_15 , V_1 , V_14 ) ;
break;
case 0x0026 :
F_19 ( V_40 , V_15 , V_1 , V_14 ) ;
break;
case 0x0027 :
F_19 ( V_41 , V_15 , V_1 , V_14 ) ;
break;
case 0x0058 :
F_19 ( V_42 , V_15 , V_1 , V_14 ) ;
break;
default:
F_19 ( V_43 , V_15 , V_1 , V_14 ) ;
break;
}
}
T_10
F_22 ( T_4 * V_6 , T_1 * V_1 , T_7 * V_14 )
{
T_6 V_44 ;
V_44 = ( F_7 ( V_6 , 0 ) >> 4 ) & 0x0F ;
switch ( V_44 )
{
case 6 :
F_19 ( V_33 , V_6 , V_1 , V_14 ) ;
return TRUE ;
case 4 :
F_19 ( V_32 , V_6 , V_1 , V_14 ) ;
return TRUE ;
case 1 :
F_8 ( V_6 , V_1 , V_14 ) ;
return TRUE ;
default:
break;
}
return FALSE ;
}
static void
F_23 ( T_4 * V_6 , T_1 * V_1 , T_7 * V_14 )
{
T_4 * V_15 ;
if ( F_9 ( V_6 , 0 ) < 4 ) {
F_10 ( V_14 , V_6 , 0 , - 1 , L_2 ) ;
return;
}
if ( F_22 ( V_6 , V_1 , V_14 ) )
return;
if ( V_14 ) {
T_7 * V_45 ;
T_9 * V_18 ;
V_18 = F_12 ( V_14 , V_46 , V_6 , 0 , 4 , V_21 ) ;
V_45 = F_13 ( V_18 , V_47 ) ;
F_12 ( V_45 , V_48 ,
V_6 , 0 , 2 , V_24 ) ;
F_12 ( V_45 , V_49 ,
V_6 , 1 , 1 , V_24 ) ;
F_12 ( V_45 , V_50 ,
V_6 , 2 , 2 , V_24 ) ;
}
V_15 = F_18 ( V_6 , 4 ) ;
F_19 ( V_43 , V_15 , V_1 , V_14 ) ;
}
static void
F_24 ( T_4 * V_6 , T_1 * V_1 , T_7 * V_14 )
{
int V_7 = 0 ;
T_5 V_8 = V_51 ;
T_6 exp ;
T_6 V_9 ;
T_6 V_10 ;
T_4 * V_15 ;
T_10 V_52 ;
T_6 V_53 ;
struct V_54 V_54 ;
F_25 ( V_1 -> V_55 , V_56 , L_6 ) ;
F_25 ( V_1 -> V_55 , V_57 , L_7 ) ;
memset ( & V_54 , 0 , sizeof( struct V_54 ) ) ;
while ( F_9 ( V_6 , V_7 ) > 0 ) {
F_6 ( V_6 , V_7 , & V_8 , & exp , & V_9 , & V_10 ) ;
V_54 . V_8 = V_8 ;
F_26 ( V_1 -> V_4 , V_1 , V_5 , 0 , F_27 ( V_8 ) ) ;
V_54 . exp = exp ;
V_54 . V_9 = V_9 ;
V_54 . V_10 = V_10 ;
if ( V_14 ) {
T_9 * V_18 ;
T_7 * V_58 ;
V_18 = F_12 ( V_14 , V_5 , V_6 , V_7 , 4 , V_21 ) ;
V_58 = F_13 ( V_18 , V_59 ) ;
if ( V_60 ) {
F_28 ( V_18 , L_8 , V_8 ) ;
} else {
F_28 ( V_18 , L_9 , V_8 ) ;
}
if ( V_8 <= V_61 ) {
F_12 ( V_58 , V_62 , V_6 ,
V_7 , 4 , V_24 ) ;
F_28 ( V_18 , L_10 ,
F_29 ( V_8 , V_63 , L_11 ) ) ;
} else {
F_12 ( V_58 , V_64 , V_6 , V_7 , 4 ,
V_24 ) ;
}
F_12 ( V_58 , V_65 , V_6 , V_7 , 4 ,
V_24 ) ;
F_28 ( V_18 , L_12 , exp ) ;
F_12 ( V_58 , V_66 , V_6 , V_7 , 4 ,
V_24 ) ;
F_28 ( V_18 , L_13 , V_9 ) ;
F_12 ( V_58 , V_67 , V_6 , V_7 , 4 ,
V_24 ) ;
F_28 ( V_18 , L_14 , V_10 ) ;
}
V_7 += 4 ;
if ( ( V_8 == V_68 ) && ! V_9 ) {
F_10 ( V_14 , V_6 , 0 , - 1 , L_15 ) ;
}
if ( ( V_8 == V_68 ) && V_9 ) {
F_30 ( V_69 , L_16 , 50 ) ;
V_15 = F_18 ( V_6 , V_7 ) ;
F_8 ( V_15 , V_1 , V_14 ) ;
return;
}
else
F_30 ( V_69 , L_17 , 50 ) ;
if ( V_9 )
break;
}
V_53 = ( F_7 ( V_6 , V_7 ) >> 4 ) & 0x0F ;
V_15 = F_18 ( V_6 , V_7 ) ;
V_52 = F_31 ( V_70 , V_8 ,
V_15 , V_1 , V_14 , FALSE , & V_54 ) ;
if ( V_52 )
return;
if ( V_53 == 4 ) {
F_19 ( V_32 , V_15 , V_1 , V_14 ) ;
F_32 ( V_6 , V_7 + F_33 ( V_15 ) ) ;
return;
} else if ( V_53 == 6 ) {
F_19 ( V_33 , V_15 , V_1 , V_14 ) ;
F_32 ( V_6 , V_7 + F_33 ( V_15 ) ) ;
return;
} else if ( V_53 == 1 ) {
F_8 ( V_15 , V_1 , V_14 ) ;
return;
} else if ( V_53 == 0 ) {
}
switch ( V_71 ) {
case V_72 :
F_19 ( V_73 , V_15 , V_1 , V_14 ) ;
break;
case V_74 :
F_19 ( V_75 , V_15 , V_1 , V_14 ) ;
break;
case V_76 :
F_19 ( V_77 , V_15 , V_1 , V_14 ) ;
break;
case V_78 :
F_19 ( V_79 , V_15 , V_1 , V_14 ) ;
break;
case V_80 :
F_19 ( V_81 , V_15 , V_1 , V_14 ) ;
break;
case V_82 :
F_19 ( V_83 , V_15 , V_1 , V_14 ) ;
break;
case V_84 :
F_19 ( V_85 , V_15 , V_1 , V_14 ) ;
break;
case V_86 :
F_19 ( V_87 , V_15 , V_1 , V_14 ) ;
break;
case V_88 :
F_19 ( V_89 , V_15 , V_1 , V_14 ) ;
break;
case V_90 :
F_19 ( V_91 , V_15 , V_1 , V_14 ) ;
break;
case V_92 :
F_19 ( V_93 , V_15 , V_1 , V_14 ) ;
break;
case V_94 :
F_19 ( V_95 , V_15 , V_1 , V_14 ) ;
break;
case V_96 :
F_19 ( V_97 , V_15 , V_1 , V_14 ) ;
break;
default:
case V_98 :
F_23 ( V_15 , V_1 , V_14 ) ;
break;
}
}
void
F_34 ( void )
{
static T_11 V_99 [] = {
{ & V_64 ,
{ L_18 , L_19 ,
V_100 , V_101 , NULL , 0xFFFFF000 ,
NULL , V_102 }
} ,
{ & V_62 ,
{ L_18 , L_19 ,
V_100 , V_101 , F_35 ( V_63 ) , 0xFFFFF000 ,
NULL , V_102 }
} ,
{ & V_65 ,
{ L_20 , L_21 ,
V_100 , V_101 , NULL , 0x00000E00 ,
NULL , V_102 }
} ,
{ & V_66 ,
{ L_22 , L_23 ,
V_100 , V_101 , NULL , 0x00000100 ,
NULL , V_102 }
} ,
{ & V_67 ,
{ L_24 , L_25 ,
V_100 , V_101 , NULL , 0x0000000FF ,
NULL , V_102 }
} ,
{ & V_23 ,
{ L_26 , L_27 ,
V_103 , V_101 , NULL , 0x0F ,
L_28 , V_102 }
} ,
{ & V_25 ,
{ L_29 , L_30 ,
V_103 , V_104 , NULL , 0x0 ,
NULL , V_102 }
} ,
{ & V_26 ,
{ L_31 , L_32 ,
V_105 , V_104 , NULL , 0x0 ,
L_33 , V_102 }
} ,
{ & V_48 ,
{ L_34 , L_35 ,
V_103 , V_104 , NULL , 0x0FC0 ,
L_36 , V_102 }
} ,
{ & V_49 ,
{ L_37 , L_38 ,
V_103 , V_101 , NULL , 0x3F ,
L_39 , V_102 }
} ,
{ & V_50 ,
{ L_40 , L_41 ,
V_105 , V_101 , NULL , 0x0 ,
L_42 , V_102 }
} ,
} ;
static T_12 * V_106 [] = {
& V_59 ,
& V_22 ,
& V_47 ,
} ;
static T_13 V_107 [ 1 ] = { F_5 } ;
static T_14 V_108 = { F_1 , 1 , V_107 } ;
static T_15 V_109 = { L_43 , L_6 , L_19 , 1 , 0 , & V_108 , NULL , NULL ,
V_110 , V_111 , V_112 , NULL } ;
T_16 * V_113 ;
V_70 = F_36 ( L_19 ,
L_44 ,
V_100 , V_101 ) ;
V_5 = F_37 ( L_45 ,
L_6 , L_43 ) ;
V_20 = F_37 ( V_69 ,
L_46 , L_47 ) ;
V_46 = F_37 ( L_48 ,
L_49 , L_50 ) ;
F_38 ( V_5 , V_99 , F_39 ( V_99 ) ) ;
F_40 ( V_106 , F_39 ( V_106 ) ) ;
F_41 ( L_43 , F_24 , V_5 ) ;
F_41 ( L_51 , F_23 , V_46 ) ;
V_113 = F_42 ( V_5 , NULL ) ;
F_43 ( V_113 ,
L_52 ,
L_53 ,
L_53 ,
& V_71 ,
V_114 ,
FALSE ) ;
F_44 ( V_113 ,
L_54 ,
L_55 ,
L_56 ,
& V_60 ) ;
F_45 ( & V_109 ) ;
}
void
F_46 ( void )
{
T_17 V_115 ;
V_115 = F_47 ( L_43 ) ;
F_48 ( L_57 , V_116 , V_115 ) ;
F_48 ( L_57 , V_117 , V_115 ) ;
F_48 ( L_58 , V_118 , V_115 ) ;
F_48 ( L_58 , V_119 , V_115 ) ;
F_48 ( L_59 , V_116 , V_115 ) ;
F_48 ( L_59 , V_117 , V_115 ) ;
F_48 ( L_60 , V_116 , V_115 ) ;
F_48 ( L_60 , V_117 , V_115 ) ;
F_48 ( L_61 , V_120 , V_115 ) ;
V_115 = F_47 ( L_51 ) ;
F_48 ( L_19 , V_51 , V_115 ) ;
V_43 = F_47 ( L_62 ) ;
V_33 = F_47 ( L_63 ) ;
V_32 = F_47 ( L_64 ) ;
V_29 = F_47 ( L_65 ) ;
V_34 = F_47 ( L_66 ) ;
V_35 = F_47 ( L_67 ) ;
V_36 = F_47 ( L_68 ) ;
V_37 = F_47 ( L_69 ) ;
V_38 = F_47 ( L_70 ) ;
V_39 = F_47 ( L_71 ) ;
V_40 = F_47 ( L_72 ) ;
V_42 = F_47 ( L_73 ) ;
V_41 = F_47 ( L_74 ) ;
V_77 = F_47 ( L_75 ) ;
V_83 = F_47 ( L_76 ) ;
V_85 = F_47 ( L_77 ) ;
V_87 = F_47 ( L_78 ) ;
V_79 = F_47 ( L_79 ) ;
V_81 = F_47 ( L_80 ) ;
V_73 = F_47 ( L_81 ) ;
V_89 = F_47 ( L_82 ) ;
V_91 = F_47 ( L_83 ) ;
V_93 = F_47 ( L_84 ) ;
V_95 = F_47 ( L_85 ) ;
V_97 = F_47 ( L_86 ) ;
V_75 = F_47 ( L_87 ) ;
}

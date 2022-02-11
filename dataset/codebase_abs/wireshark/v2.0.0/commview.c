T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
T_4 V_4 ;
if( ! F_2 ( & V_4 , V_1 -> V_5 , V_2 , V_3 ) ) {
if ( * V_2 != 0 && * V_2 != V_6 )
return V_7 ;
return V_8 ;
}
if( V_4 . V_9 != 0 ||
V_4 . V_10 < 1970 || V_4 . V_10 >= 2038 ||
V_4 . V_11 < 1 || V_4 . V_11 > 12 ||
V_4 . V_12 < 1 || V_4 . V_12 > 31 ||
V_4 . V_13 > 23 ||
V_4 . V_14 > 59 ||
V_4 . V_15 > 60 ||
V_4 . V_16 > 100 ||
( V_4 . V_17 & V_18 ) != 0 ||
( ( V_4 . V_17 & V_19 ) != V_20 &&
( V_4 . V_17 & V_19 ) != V_21 &&
( V_4 . V_17 & V_19 ) != V_22 ) )
return V_8 ;
if ( F_3 ( V_1 -> V_5 , 0 , V_23 , V_2 ) == - 1 )
return V_7 ;
V_1 -> V_24 = V_25 ;
V_1 -> V_26 = V_27 ;
V_1 -> V_28 = V_29 ;
V_1 -> V_30 = V_31 ;
V_1 -> V_32 = V_33 ;
return V_34 ;
}
static int
F_4 ( T_5 V_5 , struct V_35 * V_36 , T_6 * V_37 ,
int * V_2 , T_3 * * V_3 )
{
T_4 V_4 ;
struct V_38 V_38 ;
T_7 V_39 ;
if( ! F_2 ( & V_4 , V_5 , V_2 , V_3 ) )
return FALSE ;
switch( V_4 . V_17 & V_19 ) {
case V_20 :
V_36 -> V_40 = V_41 ;
V_36 -> V_42 . V_43 . V_44 = - 1 ;
break;
case V_21 :
V_36 -> V_40 = V_45 ;
V_36 -> V_42 . V_46 . V_44 = - 1 ;
V_36 -> V_42 . V_46 . V_47 = FALSE ;
V_36 -> V_42 . V_46 . V_48 = FALSE ;
V_36 -> V_42 . V_46 . V_49 = V_50 ;
V_36 -> V_42 . V_46 . V_51 =
V_52 |
V_53 |
V_54 ;
switch ( V_4 . V_55 ) {
case V_56 :
V_36 -> V_42 . V_46 . V_49 = V_57 ;
V_36 -> V_42 . V_46 . V_58 . V_59 . V_51 =
V_60 ;
V_36 -> V_42 . V_46 . V_58 . V_59 . V_61 =
V_62 ;
V_39 = F_5 ( V_4 . V_63 , FALSE ) ;
break;
case V_64 :
V_36 -> V_42 . V_46 . V_49 = V_65 ;
V_36 -> V_42 . V_46 . V_58 . V_66 . V_51 = 0 ;
V_39 = F_5 ( V_4 . V_63 , TRUE ) ;
break;
case V_67 :
V_36 -> V_42 . V_46 . V_49 = V_68 ;
V_36 -> V_42 . V_46 . V_58 . V_69 . V_51 =
V_70 ;
V_36 -> V_42 . V_46 . V_58 . V_69 . V_71 =
V_72 ;
V_39 = F_5 ( V_4 . V_63 , TRUE ) ;
break;
case V_73 :
V_36 -> V_42 . V_46 . V_49 = V_57 ;
V_36 -> V_42 . V_46 . V_58 . V_59 . V_51 =
V_60 ;
V_36 -> V_42 . V_46 . V_58 . V_59 . V_61 =
V_74 ;
V_39 = F_5 ( V_4 . V_63 , FALSE ) ;
break;
case V_75 :
V_36 -> V_42 . V_46 . V_49 = V_68 ;
V_36 -> V_42 . V_46 . V_58 . V_69 . V_51 =
V_70 ;
V_36 -> V_42 . V_46 . V_58 . V_69 . V_71 =
V_76 ;
V_39 = F_5 ( V_4 . V_63 , TRUE ) ;
break;
case V_77 :
V_36 -> V_42 . V_46 . V_49 = V_78 ;
V_36 -> V_42 . V_46 . V_58 . V_79 . V_51 =
0 ;
V_39 = F_5 ( V_4 . V_63 , FALSE ) ;
break;
case V_80 :
V_36 -> V_42 . V_46 . V_49 = V_78 ;
V_36 -> V_42 . V_46 . V_58 . V_79 . V_51 =
0 ;
V_39 = F_5 ( V_4 . V_63 , TRUE ) ;
break;
case V_81 :
V_39 = 0 ;
break;
default:
V_39 = 0 ;
break;
}
if ( V_39 != 0 ) {
V_36 -> V_42 . V_46 . V_51 |=
V_82 ;
V_36 -> V_42 . V_46 . V_39 = V_39 ;
}
V_36 -> V_42 . V_46 . V_63 = V_4 . V_63 ;
V_36 -> V_42 . V_46 . V_83 =
V_4 . V_84 | ( V_4 . V_85 << 8 ) ;
V_36 -> V_42 . V_46 . V_86 = V_4 . V_16 ;
if ( V_4 . V_87 != 0 ) {
V_36 -> V_42 . V_46 . V_88 = - V_4 . V_87 ;
V_36 -> V_42 . V_46 . V_51 |=
V_89 ;
}
if ( V_4 . V_90 != 0 ) {
V_36 -> V_42 . V_46 . V_91 = - V_4 . V_90 ;
V_36 -> V_42 . V_46 . V_51 |=
V_92 ;
}
break;
case V_22 :
V_36 -> V_40 = V_93 ;
break;
default :
* V_2 = V_94 ;
* V_3 = F_6 ( L_1 ,
V_4 . V_17 & V_19 ) ;
return FALSE ;
}
V_38 . V_95 = V_4 . V_10 - 1900 ;
V_38 . V_96 = V_4 . V_11 - 1 ;
V_38 . V_97 = V_4 . V_12 ;
V_38 . V_98 = V_4 . V_13 ;
V_38 . V_99 = V_4 . V_14 ;
V_38 . V_100 = V_4 . V_15 ;
V_38 . V_101 = - 1 ;
V_36 -> V_102 = V_103 ;
V_36 -> V_51 = V_104 ;
V_36 -> V_105 = V_4 . V_106 ;
V_36 -> V_107 = V_4 . V_106 ;
V_36 -> V_108 . V_109 = mktime ( & V_38 ) ;
V_36 -> V_108 . V_110 = V_4 . V_111 * 1000 ;
return F_7 ( V_5 , V_37 , V_36 -> V_107 , V_2 , V_3 ) ;
}
static T_8
V_25 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 , T_9 * V_112 )
{
* V_112 = F_8 ( V_1 -> V_5 ) ;
return F_4 ( V_1 -> V_5 , & V_1 -> V_36 , V_1 -> V_113 , V_2 ,
V_3 ) ;
}
static T_8
V_27 ( T_2 * V_1 , T_9 V_114 , struct V_35 * V_36 ,
T_6 * V_37 , int * V_2 , T_3 * * V_3 )
{
if( F_3 ( V_1 -> V_115 , V_114 , V_23 , V_2 ) == - 1 )
return FALSE ;
return F_4 ( V_1 -> V_115 , V_36 , V_37 , V_2 , V_3 ) ;
}
static T_8
F_2 ( T_4 * V_4 , T_5 V_5 , int * V_2 ,
T_3 * * V_3 )
{
if ( ! F_9 ( V_5 , & V_4 -> V_106 , 2 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_116 , 2 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_9 , 1 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_10 , 2 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_11 , 1 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_12 , 1 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_13 , 1 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_14 , 1 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_15 , 1 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_111 , 4 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_17 , 1 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_16 , 1 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_84 , 1 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_55 , 1 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_63 , 1 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_85 , 1 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_87 , 1 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_5 , & V_4 -> V_90 , 1 , V_2 , V_3 ) )
return FALSE ;
V_4 -> V_106 = F_11 ( V_4 -> V_106 ) ;
V_4 -> V_116 = F_11 ( V_4 -> V_116 ) ;
V_4 -> V_10 = F_11 ( V_4 -> V_10 ) ;
V_4 -> V_111 = F_12 ( V_4 -> V_111 ) ;
return TRUE ;
}
int F_13 ( int V_117 )
{
switch ( V_117 ) {
case V_41 :
case V_118 :
case V_45 :
case V_93 :
case V_31 :
return 0 ;
default:
return V_119 ;
}
}
T_8 F_14 ( T_10 * V_120 , int * V_2 V_121 )
{
V_120 -> V_122 = V_123 ;
V_120 -> V_124 = 0 ;
return TRUE ;
}
static T_8 V_123 ( T_10 * V_120 ,
const struct V_35 * V_36 ,
const T_11 * V_125 , int * V_2 , T_3 * * V_3 V_121 )
{
T_4 V_4 ;
struct V_38 * V_38 ;
if ( V_36 -> V_102 != V_103 ) {
* V_2 = V_126 ;
return FALSE ;
}
if ( V_36 -> V_107 > 65535 ) {
* V_2 = V_127 ;
return FALSE ;
}
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_106 = F_15 ( ( V_128 ) V_36 -> V_107 ) ;
V_4 . V_116 = F_15 ( ( V_128 ) V_36 -> V_107 ) ;
V_4 . V_9 = 0 ;
V_38 = localtime ( & V_36 -> V_108 . V_109 ) ;
V_4 . V_10 = V_38 -> V_95 + 1900 ;
V_4 . V_11 = V_38 -> V_96 + 1 ;
V_4 . V_12 = V_38 -> V_97 ;
V_4 . V_13 = V_38 -> V_98 ;
V_4 . V_14 = V_38 -> V_99 ;
V_4 . V_15 = V_38 -> V_100 ;
V_4 . V_111 = F_16 ( V_36 -> V_108 . V_110 / 1000 ) ;
switch( V_36 -> V_40 ) {
case V_41 :
V_4 . V_17 |= V_20 ;
break;
case V_118 :
V_4 . V_17 |= V_21 ;
break;
case V_45 :
V_4 . V_17 |= V_21 ;
switch ( V_36 -> V_42 . V_46 . V_49 ) {
case V_57 :
if ( ! ( V_36 -> V_42 . V_46 . V_58 . V_59 . V_51 & V_60 ) ||
V_36 -> V_42 . V_46 . V_58 . V_59 . V_61 == V_62 )
V_4 . V_55 = V_56 ;
else
V_4 . V_55 = V_73 ;
break;
case V_65 :
V_4 . V_55 = V_64 ;
break;
case V_68 :
if ( ! ( V_36 -> V_42 . V_46 . V_58 . V_69 . V_51 & V_70 ) )
V_4 . V_55 = V_67 ;
else {
switch ( V_36 -> V_42 . V_46 . V_58 . V_69 . V_71 ) {
case V_72 :
V_4 . V_55 = V_67 ;
break;
case V_76 :
V_4 . V_55 = V_75 ;
break;
default:
V_4 . V_55 = V_67 ;
break;
}
}
break;
case V_78 :
if ( V_36 -> V_42 . V_46 . V_51 & V_82 ) {
if ( V_36 -> V_42 . V_46 . V_39 > 2484 ) {
V_4 . V_55 = V_77 ;
} else {
V_4 . V_55 = V_80 ;
}
} else {
V_4 . V_55 = 0 ;
}
break;
default:
V_4 . V_55 = 0 ;
break;
}
V_4 . V_63 =
( V_36 -> V_42 . V_46 . V_51 & V_52 ) ?
V_36 -> V_42 . V_46 . V_63 :
0 ;
V_4 . V_84 =
( V_36 -> V_42 . V_46 . V_51 & V_53 ) ?
( T_11 ) ( V_36 -> V_42 . V_46 . V_83 & 0xFF ) :
0 ;
V_4 . V_85 =
( V_36 -> V_42 . V_46 . V_51 & V_53 ) ?
( T_11 ) ( ( V_36 -> V_42 . V_46 . V_83 >> 8 ) & 0xFF ) :
0 ;
V_4 . V_16 =
( V_36 -> V_42 . V_46 . V_51 & V_54 ) ?
V_36 -> V_42 . V_46 . V_86 :
0 ;
V_4 . V_87 =
( V_36 -> V_42 . V_46 . V_51 & V_89 ) ?
- V_36 -> V_42 . V_46 . V_88 :
0 ;
V_4 . V_90 =
( V_36 -> V_42 . V_46 . V_51 & V_92 ) ?
- V_36 -> V_42 . V_46 . V_91 :
0 ;
break;
case V_93 :
V_4 . V_17 |= V_22 ;
break;
default :
* V_2 = V_119 ;
return FALSE ;
}
if ( ! F_17 ( V_120 , & V_4 . V_106 , 2 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_116 , 2 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_9 , 1 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_10 , 2 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_11 , 1 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_12 , 1 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_13 , 1 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_14 , 1 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_15 , 1 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_111 , 4 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_17 , 1 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_16 , 1 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_84 , 1 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_55 , 1 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_63 , 1 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_85 , 1 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_87 , 2 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_120 , & V_4 . V_90 , 2 , V_2 ) )
return FALSE ;
V_120 -> V_124 += V_129 ;
if ( ! F_17 ( V_120 , V_125 , V_36 -> V_107 , V_2 ) )
return FALSE ;
V_120 -> V_124 += V_36 -> V_107 ;
return TRUE ;
}

T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
char V_4 [ sizeof F_2 ] ;
struct V_5 V_6 ;
struct V_7 * V_8 ;
int V_9 ;
if ( ! F_3 ( V_1 -> V_10 , V_4 , sizeof V_4 , V_2 , V_3 ) )
{
if ( * V_2 != V_11 )
return V_12 ;
return V_13 ;
}
if ( memcmp ( V_4 , F_2 , sizeof F_2 ) != 0 )
{
return V_13 ;
}
if ( ! F_3 ( V_1 -> V_10 , & V_6 , sizeof V_6 , V_2 , V_3 ) )
{
return V_12 ;
}
V_6 . V_14 = F_4 ( & V_6 . V_14 ) ;
if ( V_6 . V_14 != 1 )
{
* V_2 = V_15 ;
* V_3 = F_5 ( L_1 , V_6 . V_14 ) ;
return V_12 ;
}
switch ( F_4 ( & V_6 . V_16 ) )
{
case 6 :
V_9 = V_17 ;
break;
case 9 :
V_9 = V_18 ;
break;
case 16 :
V_9 = V_19 ;
break;
case 22 :
case 118 :
V_9 = V_20 ;
break;
case 32 :
V_9 = V_21 ;
break;
case 37 :
V_9 = V_22 ;
break;
default:
* V_2 = V_15 ;
* V_3 = F_5 ( L_2 ,
V_6 . V_16 ) ;
return V_12 ;
}
V_1 -> V_23 = V_24 ;
V_1 -> V_25 = V_9 ;
V_1 -> V_26 = F_4 ( & V_6 . V_27 ) ;
V_1 -> V_28 = V_29 ;
V_1 -> V_30 = V_31 ;
V_1 -> V_32 = V_33 ;
V_8 = (struct V_7 * ) F_6 ( sizeof( struct V_7 ) ) ;
V_1 -> V_34 = ( void * ) V_8 ;
V_8 -> V_35 = F_7 ( & V_6 . V_35 ) ;
V_8 -> V_36 = F_7 ( & V_6 . V_36 ) ;
V_8 -> V_37 = 1 ;
return V_38 ;
}
static T_4 V_29 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_5 * V_39 )
{
struct V_7 * V_8 = (struct V_7 * ) V_1 -> V_34 ;
if ( V_8 -> V_37 > V_8 -> V_35 )
{
* V_2 = 0 ;
return FALSE ;
}
V_8 -> V_37 ++ ;
* V_39 = F_8 ( V_1 -> V_10 ) ;
return F_9 ( V_1 , V_1 -> V_10 , & V_1 -> V_40 , V_1 -> V_41 ,
V_2 , V_3 ) ;
}
static T_4 V_31 ( T_2 * V_1 , T_5 V_42 ,
struct V_43 * V_40 , T_6 * V_44 , int * V_2 , T_3 * * V_3 )
{
if ( F_10 ( V_1 -> V_45 , V_42 , V_46 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_9 ( V_1 , V_1 -> V_45 , V_40 , V_44 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_11 ;
return FALSE ;
}
return TRUE ;
}
static T_4
F_9 ( T_2 * V_1 , T_7 V_10 , struct V_43 * V_40 ,
T_6 * V_44 , int * V_2 , T_3 * * V_3 )
{
struct V_7 * V_8 = (struct V_7 * ) V_1 -> V_34 ;
struct V_47 V_48 ;
T_8 V_49 ;
struct V_50 V_51 ;
T_8 V_52 ;
T_8 V_53 ;
T_9 * V_54 ;
if ( ! F_11 ( V_10 , & V_48 , ( unsigned int ) sizeof V_48 , V_2 , V_3 ) )
{
return FALSE ;
}
V_49 = F_4 ( & V_48 . V_55 ) ;
V_40 -> V_56 = V_57 ;
V_40 -> V_58 = V_59 | V_60 ;
V_52 = F_7 ( & V_48 . V_61 ) ;
V_40 -> V_62 . V_63 = V_8 -> V_36 + V_52 / 1000 ;
V_40 -> V_62 . V_64 = ( V_52 % 1000 ) * 1000000 ;
V_40 -> V_65 = F_4 ( & V_48 . V_66 ) ;
V_53 = F_7 ( & V_48 . V_67 ) ;
switch ( V_1 -> V_25 )
{
case V_17 :
if ( V_40 -> V_65 < 4 )
{
* V_2 = V_68 ;
* V_3 = F_5 ( L_3 ,
V_40 -> V_65 ) ;
return FALSE ;
}
V_40 -> V_65 -= 4 ;
V_40 -> V_69 . V_70 . V_71 = - 1 ;
break;
case V_20 :
if ( V_40 -> V_65 < 2 )
{
* V_2 = V_68 ;
* V_3 = F_5 ( L_4 ,
V_40 -> V_65 ) ;
return FALSE ;
}
V_40 -> V_65 -= 2 ;
V_40 -> V_69 . V_72 . V_73 = ( V_53 & V_74 ) ? TRUE : FALSE ;
break;
case V_75 :
V_40 -> V_69 . V_72 . V_73 = ( V_53 & V_74 ) ? TRUE : FALSE ;
break;
case V_21 :
if ( V_40 -> V_65 < 2 )
{
* V_2 = V_68 ;
* V_3 = F_5 ( L_5 ,
V_40 -> V_65 ) ;
return FALSE ;
}
V_40 -> V_65 -= 2 ;
V_40 -> V_69 . V_76 . V_77 =
( V_53 & V_74 ) ? 0x00 : V_78 ;
break;
case V_19 :
if ( V_40 -> V_65 < 2 )
{
* V_2 = V_68 ;
* V_3 = F_5 ( L_5 ,
V_40 -> V_65 ) ;
return FALSE ;
}
V_40 -> V_65 -= 2 ;
V_40 -> V_69 . V_76 . V_77 =
( V_53 & V_74 ) ? 0x00 : V_78 ;
break;
case V_22 :
if ( ! F_3 ( V_10 , & V_51 , ( unsigned int ) sizeof V_51 , V_2 , V_3 ) )
{
return FALSE ;
}
V_49 -= ( T_8 ) sizeof V_51 ;
V_40 -> V_69 . V_79 . type = V_80 ;
V_40 -> V_69 . V_79 . V_81 = V_82 ;
V_40 -> V_69 . V_79 . V_83 = 0 ;
V_40 -> V_69 . V_79 . V_84 = 0 ;
V_40 -> V_69 . V_79 . V_85 = 0 ;
V_40 -> V_69 . V_79 . V_77 = 0 ;
V_40 -> V_69 . V_79 . V_86 = 0 ;
switch( V_51 . V_87 & V_88 )
{
case V_89 :
V_40 -> V_69 . V_79 . V_90 = V_91 ;
break;
case V_92 :
V_40 -> V_69 . V_79 . V_90 = V_93 ;
break;
case V_94 :
V_40 -> V_69 . V_79 . V_90 = V_95 ;
break;
case V_96 :
V_40 -> V_69 . V_79 . V_90 = V_97 ;
V_40 -> V_69 . V_79 . type = V_98 ;
V_40 -> V_69 . V_79 . V_83 = F_12 ( & V_51 . V_99 ) ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
V_40 -> V_69 . V_79 . V_90 = V_104 ;
break;
case V_105 :
default:
V_40 -> V_69 . V_79 . V_90 = V_106 ;
break;
}
V_40 -> V_69 . V_79 . V_107 = F_13 ( & V_51 . V_107 ) & 0x0FFF ;
V_40 -> V_69 . V_79 . V_108 = F_13 ( & V_51 . V_108 ) ;
V_40 -> V_69 . V_79 . V_109 = F_13 ( & V_51 . V_110 ) ;
V_40 -> V_69 . V_79 . V_111 = V_51 . V_112 & V_113 ;
break;
case V_18 :
default:
break;
}
V_40 -> V_114 = V_49 ;
if ( V_49 > V_115 )
{
* V_2 = V_68 ;
* V_3 = F_5 ( L_6 ,
V_49 , V_115 ) ;
return FALSE ;
}
if ( ! F_14 ( V_10 , V_44 , V_49 , V_2 , V_3 ) )
return FALSE ;
if ( V_1 -> V_25 == V_20 )
{
V_54 = F_15 ( V_44 ) ;
if ( V_48 . V_116 == 14 )
{
if ( V_49 >= 3 &&
( 0xfe == V_54 [ 0 ] ) && ( 0xfe == V_54 [ 1 ] ) && ( 0x03 == V_54 [ 2 ] ) )
{
V_40 -> V_117 = V_118 ;
}
else
{
V_40 -> V_117 = V_75 ;
}
}
else
{
if ( V_49 >= 2 && ( 0xff == V_54 [ 0 ] ) && ( 0x03 == V_54 [ 1 ] ) )
{
V_40 -> V_117 = V_75 ;
}
}
}
return TRUE ;
}
int F_16 ( int V_9 )
{
if ( V_9 == V_119 )
return V_120 ;
switch ( V_9 )
{
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_121 :
case V_75 :
return 0 ;
}
return V_122 ;
}
T_4 F_17 ( T_10 * V_123 , int * V_2 )
{
struct V_124 * V_8 ;
V_123 -> V_125 = V_126 ;
V_123 -> V_127 = V_128 ;
V_8 = (struct V_124 * ) F_6 ( sizeof( struct V_124 ) ) ;
V_123 -> V_34 = ( void * ) V_8 ;
V_8 -> V_129 = 0 ;
V_8 -> V_130 = 1024 ;
V_8 -> V_131 = 0 ;
V_8 -> V_132 = V_133 ;
if ( F_18 ( V_123 , V_133 , V_46 , V_2 ) == - 1 )
return FALSE ;
return TRUE ;
}
static T_4 V_126 ( T_10 * V_123 , const struct V_43 * V_40 ,
const T_9 * V_54 , int * V_2 , T_3 * * V_3 V_134 )
{
const union V_135 * V_69 = & V_40 -> V_69 ;
struct V_124 * V_8 = (struct V_124 * ) V_123 -> V_34 ;
struct V_47 V_48 ;
T_11 V_136 = sizeof V_48 ;
T_12 V_137 ;
T_8 V_53 ;
if ( V_40 -> V_56 != V_57 ) {
* V_2 = V_138 ;
return FALSE ;
}
if ( V_40 -> V_114 > V_115 ) {
* V_2 = V_139 ;
return FALSE ;
}
if ( V_8 == 0 )
return FALSE ;
memset ( & V_48 , 0 , V_136 ) ;
if ( V_8 -> V_129 == 0 )
{
V_8 -> V_36 = V_40 -> V_62 . V_63 ;
V_8 -> V_131 = ( T_8 * ) F_6 ( 1024 * sizeof * V_8 -> V_131 ) ;
V_8 -> V_130 = 1024 ;
}
V_137 = V_40 -> V_62 . V_64 / 1000000 ;
V_137 += ( T_8 ) ( ( V_40 -> V_62 . V_63 - V_8 -> V_36 ) * 1000 ) ;
V_48 . V_61 = F_19 ( V_137 ) ;
V_48 . V_66 = F_20 ( V_40 -> V_65 ) ;
V_48 . V_55 = F_20 ( V_40 -> V_114 ) ;
switch ( V_123 -> V_9 )
{
case V_17 :
V_48 . V_116 = 2 ;
break;
case V_18 :
V_48 . V_116 = 3 ;
break;
case V_121 :
case V_75 :
V_48 . V_116 = 14 ;
break;
case V_20 :
V_48 . V_116 = 13 ;
break;
case V_21 :
V_48 . V_116 = 12 ;
break;
case V_19 :
default:
V_48 . V_116 = 1 ;
break;
}
V_53 = 0 ;
switch ( V_123 -> V_9 )
{
case V_20 :
V_53 |= ( V_69 -> V_72 . V_73 ? V_74 : 0x00 ) ;
break;
case V_21 :
case V_19 :
V_53 |=
( ( V_69 -> V_76 . V_77 & V_78 ) ? 0x00 : V_74 ) ;
break;
}
V_48 . V_67 = F_19 ( V_53 ) ;
if ( ! F_21 ( V_123 , & V_48 , V_136 , V_2 ) )
return FALSE ;
if ( ! F_21 ( V_123 , V_54 , V_40 -> V_114 , V_2 ) )
return FALSE ;
if ( V_8 -> V_129 >= V_8 -> V_130 )
{
V_8 -> V_130 *= 2 ;
V_8 -> V_131 = ( T_8 * ) F_22 ( V_8 -> V_131 ,
V_8 -> V_130 * sizeof * V_8 -> V_131 ) ;
}
V_8 -> V_131 [ V_8 -> V_129 ] = F_19 ( V_8 -> V_132 ) ;
V_8 -> V_129 ++ ;
V_8 -> V_132 += ( T_8 ) V_136 + V_40 -> V_114 ;
return TRUE ;
}
static T_4 V_128 ( T_10 * V_123 , int * V_2 )
{
struct V_124 * V_8 = (struct V_124 * ) V_123 -> V_34 ;
T_11 V_140 ;
struct V_5 V_6 ;
const char * V_141 ;
T_11 V_142 ;
if ( V_8 == 0 )
return FALSE ;
if ( V_8 -> V_131 )
{
V_140 = V_8 -> V_129 * sizeof * V_8 -> V_131 ;
if ( ! F_21 ( V_123 , V_8 -> V_131 , V_140 , V_2 ) )
{
F_23 ( V_123 ) ;
return FALSE ;
}
}
if ( F_18 ( V_123 , 0 , V_46 , V_2 ) == - 1 )
return FALSE ;
V_141 = F_2 ;
V_142 = sizeof F_2 ;
if ( ! F_21 ( V_123 , V_141 , V_142 , V_2 ) )
{
F_23 ( V_123 ) ;
return FALSE ;
}
memset ( & V_6 , '\0' , sizeof V_6 ) ;
V_6 . V_35 = F_19 ( V_8 -> V_129 ) ;
V_6 . V_36 = F_19 ( V_8 -> V_36 ) ;
V_6 . V_27 = F_20 ( 65535 ) ;
V_6 . V_143 = F_20 ( 1 ) ;
V_6 . V_14 = F_20 ( 1 ) ;
F_24 ( V_6 . V_144 , L_7 , 64 ) ;
switch ( V_123 -> V_9 )
{
case V_17 :
V_6 . V_16 = F_20 ( 6 ) ;
break;
case V_18 :
V_6 . V_16 = F_20 ( 9 ) ;
break;
case V_19 :
V_6 . V_16 = F_20 ( 16 ) ;
break;
case V_121 :
case V_75 :
case V_20 :
V_6 . V_16 = F_20 ( 22 ) ;
break;
case V_21 :
V_6 . V_16 = F_20 ( 32 ) ;
break;
}
if ( ! F_21 ( V_123 , & V_6 , sizeof V_6 , V_2 ) )
{
F_23 ( V_123 ) ;
return FALSE ;
}
F_23 ( V_123 ) ;
return TRUE ;
}
static void F_23 ( T_10 * V_123 )
{
struct V_124 * V_8 = (struct V_124 * ) V_123 -> V_34 ;
if ( V_8 )
{
if ( V_8 -> V_131 )
F_25 ( V_8 -> V_131 ) ;
}
}

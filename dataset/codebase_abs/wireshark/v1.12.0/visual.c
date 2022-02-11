int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
char V_5 [ sizeof F_2 ] ;
struct V_6 V_7 ;
struct V_8 * V_9 ;
int V_10 ;
V_11 = V_12 ;
V_4 = F_3 ( V_5 , sizeof V_5 , V_1 -> V_13 ) ;
if ( V_4 != sizeof V_5 )
{
* V_2 = F_4 ( V_1 -> V_13 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_14 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_5 , F_2 , sizeof F_2 ) != 0 )
{
return 0 ;
}
V_11 = V_12 ;
V_4 = F_3 ( & V_7 , sizeof V_7 , V_1 -> V_13 ) ;
if ( V_4 != sizeof V_7 )
{
* V_2 = F_4 ( V_1 -> V_13 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_14 ;
return - 1 ;
}
V_7 . V_15 = F_5 ( & V_7 . V_15 ) ;
if ( V_7 . V_15 != 1 )
{
* V_2 = V_16 ;
* V_3 = F_6 ( L_1 , V_7 . V_15 ) ;
return - 1 ;
}
switch ( F_5 ( & V_7 . V_17 ) )
{
case 6 :
V_10 = V_18 ;
break;
case 9 :
V_10 = V_19 ;
break;
case 16 :
V_10 = V_20 ;
break;
case 22 :
case 118 :
V_10 = V_21 ;
break;
case 32 :
V_10 = V_22 ;
break;
case 37 :
V_10 = V_23 ;
break;
default:
* V_2 = V_24 ;
* V_3 = F_6 ( L_2 ,
V_7 . V_17 ) ;
return - 1 ;
}
V_1 -> V_25 = V_26 ;
V_1 -> V_27 = V_10 ;
V_1 -> V_28 = F_5 ( & V_7 . V_29 ) ;
V_1 -> V_30 = V_31 ;
V_1 -> V_32 = V_33 ;
V_1 -> V_34 = V_35 ;
V_9 = (struct V_8 * ) F_7 ( sizeof( struct V_8 ) ) ;
V_1 -> V_36 = ( void * ) V_9 ;
V_9 -> V_37 = F_8 ( & V_7 . V_37 ) ;
V_9 -> V_38 = ( ( double ) F_8 ( & V_7 . V_38 ) ) * 1000000 ;
V_9 -> V_39 = 1 ;
return 1 ;
}
static T_3 V_31 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_4 * V_40 )
{
struct V_8 * V_9 = (struct V_8 * ) V_1 -> V_36 ;
if ( V_9 -> V_39 > V_9 -> V_37 )
{
* V_2 = 0 ;
return FALSE ;
}
V_9 -> V_39 ++ ;
* V_40 = F_9 ( V_1 -> V_13 ) ;
return F_10 ( V_1 , V_1 -> V_13 , & V_1 -> V_41 , V_1 -> V_42 ,
V_2 , V_3 ) ;
}
static T_3 V_33 ( T_1 * V_1 , T_4 V_43 ,
struct V_44 * V_41 , T_5 * V_45 , int * V_2 , T_2 * * V_3 )
{
if ( F_11 ( V_1 -> V_46 , V_43 , V_47 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_10 ( V_1 , V_1 -> V_46 , V_41 , V_45 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_14 ;
return FALSE ;
}
return TRUE ;
}
static T_3
F_10 ( T_1 * V_1 , T_6 V_13 , struct V_44 * V_41 ,
T_5 * V_45 , int * V_2 , T_2 * * V_3 )
{
struct V_8 * V_9 = (struct V_8 * ) V_1 -> V_36 ;
struct V_48 V_49 ;
int V_4 ;
T_7 V_50 ;
struct V_51 V_52 ;
double V_53 ;
T_8 V_54 ;
T_7 V_55 ;
T_7 V_56 ;
T_9 * V_57 ;
V_11 = V_12 ;
V_4 = F_3 ( & V_49 , ( unsigned int ) sizeof V_49 , V_13 ) ;
if ( V_4 < 0 || ( V_58 ) V_4 != sizeof V_49 )
{
* V_2 = F_4 ( V_13 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
{
* V_2 = V_14 ;
}
return FALSE ;
}
V_50 = F_5 ( & V_49 . V_59 ) ;
V_41 -> V_60 = V_61 ;
V_41 -> V_62 = V_63 | V_64 ;
V_53 = V_9 -> V_38 ;
V_53 += ( ( double ) F_8 ( & V_49 . V_65 ) ) * 1000 ;
V_54 = ( T_8 ) ( V_53 / 1000000 ) ;
V_55 = ( T_7 ) ( V_53 - V_54 * 1000000 ) ;
V_41 -> V_66 . V_54 = V_54 ;
V_41 -> V_66 . V_67 = V_55 * 1000 ;
V_41 -> V_68 = F_5 ( & V_49 . V_69 ) ;
V_56 = F_8 ( & V_49 . V_70 ) ;
switch ( V_1 -> V_27 )
{
case V_18 :
if ( V_41 -> V_68 < 4 )
{
* V_2 = V_71 ;
* V_3 = F_6 ( L_3 ,
V_41 -> V_68 ) ;
return FALSE ;
}
V_41 -> V_68 -= 4 ;
V_41 -> V_72 . V_73 . V_74 = - 1 ;
break;
case V_21 :
if ( V_41 -> V_68 < 2 )
{
* V_2 = V_71 ;
* V_3 = F_6 ( L_4 ,
V_41 -> V_68 ) ;
return FALSE ;
}
V_41 -> V_68 -= 2 ;
V_41 -> V_72 . V_75 . V_76 = ( V_56 & V_77 ) ? TRUE : FALSE ;
break;
case V_78 :
V_41 -> V_72 . V_75 . V_76 = ( V_56 & V_77 ) ? TRUE : FALSE ;
break;
case V_22 :
if ( V_41 -> V_68 < 2 )
{
* V_2 = V_71 ;
* V_3 = F_6 ( L_5 ,
V_41 -> V_68 ) ;
return FALSE ;
}
V_41 -> V_68 -= 2 ;
V_41 -> V_72 . V_79 . V_80 =
( V_56 & V_77 ) ? 0x00 : V_81 ;
break;
case V_20 :
if ( V_41 -> V_68 < 2 )
{
* V_2 = V_71 ;
* V_3 = F_6 ( L_5 ,
V_41 -> V_68 ) ;
return FALSE ;
}
V_41 -> V_68 -= 2 ;
V_41 -> V_72 . V_79 . V_80 =
( V_56 & V_77 ) ? 0x00 : V_81 ;
break;
case V_23 :
V_11 = V_12 ;
V_4 = F_3 ( & V_52 , ( unsigned int ) sizeof V_52 , V_13 ) ;
if ( V_4 < 0 || ( V_58 ) V_4 != sizeof V_52 )
{
* V_2 = F_4 ( V_13 , V_3 ) ;
if ( * V_2 == 0 )
{
* V_2 = V_14 ;
}
return FALSE ;
}
V_50 -= ( T_7 ) sizeof V_52 ;
V_41 -> V_72 . V_82 . type = V_83 ;
V_41 -> V_72 . V_82 . V_84 = V_85 ;
V_41 -> V_72 . V_82 . V_86 = 0 ;
V_41 -> V_72 . V_82 . V_87 = 0 ;
V_41 -> V_72 . V_82 . V_88 = 0 ;
V_41 -> V_72 . V_82 . V_80 = 0 ;
V_41 -> V_72 . V_82 . V_89 = 0 ;
switch( V_52 . V_90 & V_91 )
{
case V_92 :
V_41 -> V_72 . V_82 . V_93 = V_94 ;
break;
case V_95 :
V_41 -> V_72 . V_82 . V_93 = V_96 ;
break;
case V_97 :
V_41 -> V_72 . V_82 . V_93 = V_98 ;
break;
case V_99 :
V_41 -> V_72 . V_82 . V_93 = V_100 ;
V_41 -> V_72 . V_82 . type = V_101 ;
V_41 -> V_72 . V_82 . V_86 = F_12 ( & V_52 . V_102 ) ;
break;
case V_103 :
case V_104 :
case V_105 :
case V_106 :
V_41 -> V_72 . V_82 . V_93 = V_107 ;
break;
case V_108 :
default:
V_41 -> V_72 . V_82 . V_93 = V_109 ;
break;
}
V_41 -> V_72 . V_82 . V_110 = F_13 ( & V_52 . V_110 ) & 0x0FFF ;
V_41 -> V_72 . V_82 . V_111 = F_13 ( & V_52 . V_111 ) ;
V_41 -> V_72 . V_82 . V_112 = F_13 ( & V_52 . V_113 ) ;
V_41 -> V_72 . V_82 . V_114 = V_52 . V_115 & V_116 ;
break;
case V_19 :
default:
break;
}
V_41 -> V_117 = V_50 ;
if ( V_50 > V_118 )
{
* V_2 = V_71 ;
* V_3 = F_6 ( L_6 ,
V_50 , V_118 ) ;
return FALSE ;
}
if ( ! F_14 ( V_13 , V_45 , V_50 , V_2 , V_3 ) )
return FALSE ;
if ( V_1 -> V_27 == V_21 )
{
V_57 = F_15 ( V_45 ) ;
if ( V_49 . V_119 == 14 )
{
if ( V_50 >= 3 &&
( 0xfe == V_57 [ 0 ] ) && ( 0xfe == V_57 [ 1 ] ) && ( 0x03 == V_57 [ 2 ] ) )
{
V_41 -> V_120 = V_121 ;
}
else
{
V_41 -> V_120 = V_78 ;
}
}
else
{
if ( V_50 >= 2 && ( 0xff == V_57 [ 0 ] ) && ( 0x03 == V_57 [ 1 ] ) )
{
V_41 -> V_120 = V_78 ;
}
}
}
return TRUE ;
}
int F_16 ( int V_10 )
{
if ( V_10 == V_122 )
return V_123 ;
switch ( V_10 )
{
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_124 :
case V_78 :
return 0 ;
}
return V_24 ;
}
T_3 F_17 ( T_10 * V_125 , int * V_2 )
{
struct V_126 * V_9 ;
V_125 -> V_127 = V_128 ;
V_125 -> V_129 = V_130 ;
V_9 = (struct V_126 * ) F_7 ( sizeof( struct V_126 ) ) ;
V_125 -> V_36 = ( void * ) V_9 ;
V_9 -> V_131 = 0 ;
V_9 -> V_132 = 1024 ;
V_9 -> V_133 = 0 ;
V_9 -> V_134 = V_135 ;
if ( F_18 ( V_125 , V_135 , V_47 , V_2 ) == - 1 )
return FALSE ;
return TRUE ;
}
static T_3 V_128 ( T_10 * V_125 , const struct V_44 * V_41 ,
const T_9 * V_57 , int * V_2 )
{
const union V_136 * V_72 = & V_41 -> V_72 ;
struct V_126 * V_9 = (struct V_126 * ) V_125 -> V_36 ;
struct V_48 V_49 ;
V_58 V_137 = sizeof V_49 ;
T_11 V_138 ;
T_7 V_56 ;
if ( V_41 -> V_60 != V_61 ) {
* V_2 = V_139 ;
return FALSE ;
}
if ( V_41 -> V_117 > V_118 ) {
* V_2 = V_140 ;
return FALSE ;
}
if ( V_9 == 0 )
return FALSE ;
memset ( & V_49 , 0 , V_137 ) ;
if ( V_9 -> V_131 == 0 )
{
V_9 -> V_38 = ( T_7 ) V_41 -> V_66 . V_54 ;
V_9 -> V_133 = ( T_7 * ) F_7 ( 1024 * sizeof * V_9 -> V_133 ) ;
V_9 -> V_132 = 1024 ;
}
V_138 = V_41 -> V_66 . V_67 / 1000000 ;
V_138 += ( ( T_7 ) V_41 -> V_66 . V_54 - V_9 -> V_38 ) * 1000 ;
V_49 . V_65 = F_19 ( V_138 ) ;
V_49 . V_69 = F_20 ( V_41 -> V_68 ) ;
V_49 . V_59 = F_20 ( V_41 -> V_117 ) ;
switch ( V_125 -> V_10 )
{
case V_18 :
V_49 . V_119 = 2 ;
break;
case V_19 :
V_49 . V_119 = 3 ;
break;
case V_124 :
case V_78 :
V_49 . V_119 = 14 ;
break;
case V_21 :
V_49 . V_119 = 13 ;
break;
case V_22 :
V_49 . V_119 = 12 ;
break;
case V_20 :
default:
V_49 . V_119 = 1 ;
break;
}
V_56 = 0 ;
switch ( V_125 -> V_10 )
{
case V_21 :
V_56 |= ( V_72 -> V_75 . V_76 ? V_77 : 0x00 ) ;
break;
case V_22 :
case V_20 :
V_56 |=
( ( V_72 -> V_79 . V_80 & V_81 ) ? 0x00 : V_77 ) ;
break;
}
V_49 . V_70 = F_19 ( V_56 ) ;
if ( ! F_21 ( V_125 , & V_49 , V_137 , V_2 ) )
return FALSE ;
if ( ! F_21 ( V_125 , V_57 , V_41 -> V_117 , V_2 ) )
return FALSE ;
if ( V_9 -> V_131 >= V_9 -> V_132 )
{
V_9 -> V_132 *= 2 ;
V_9 -> V_133 = ( T_7 * ) F_22 ( V_9 -> V_133 ,
V_9 -> V_132 * sizeof * V_9 -> V_133 ) ;
}
V_9 -> V_133 [ V_9 -> V_131 ] = F_19 ( V_9 -> V_134 ) ;
V_9 -> V_131 ++ ;
V_9 -> V_134 += ( T_7 ) V_137 + V_41 -> V_117 ;
return TRUE ;
}
static T_3 V_130 ( T_10 * V_125 , int * V_2 )
{
struct V_126 * V_9 = (struct V_126 * ) V_125 -> V_36 ;
V_58 V_141 ;
struct V_6 V_7 ;
const char * V_142 ;
V_58 V_143 ;
if ( V_9 == 0 )
return FALSE ;
if ( V_9 -> V_133 )
{
V_141 = V_9 -> V_131 * sizeof * V_9 -> V_133 ;
if ( ! F_21 ( V_125 , V_9 -> V_133 , V_141 , V_2 ) )
{
F_23 ( V_125 ) ;
return FALSE ;
}
}
if ( F_18 ( V_125 , 0 , V_47 , V_2 ) == - 1 )
return FALSE ;
V_142 = F_2 ;
V_143 = sizeof F_2 ;
if ( ! F_21 ( V_125 , V_142 , V_143 , V_2 ) )
{
F_23 ( V_125 ) ;
return FALSE ;
}
memset ( & V_7 , '\0' , sizeof V_7 ) ;
V_7 . V_37 = F_19 ( V_9 -> V_131 ) ;
V_7 . V_38 = F_19 ( V_9 -> V_38 ) ;
V_7 . V_29 = F_20 ( 65535 ) ;
V_7 . V_144 = F_20 ( 1 ) ;
V_7 . V_15 = F_20 ( 1 ) ;
F_24 ( V_7 . V_145 , L_7 , 64 ) ;
switch ( V_125 -> V_10 )
{
case V_18 :
V_7 . V_17 = F_20 ( 6 ) ;
break;
case V_19 :
V_7 . V_17 = F_20 ( 9 ) ;
break;
case V_20 :
V_7 . V_17 = F_20 ( 16 ) ;
break;
case V_124 :
case V_78 :
case V_21 :
V_7 . V_17 = F_20 ( 22 ) ;
break;
case V_22 :
V_7 . V_17 = F_20 ( 32 ) ;
break;
}
if ( ! F_21 ( V_125 , & V_7 , sizeof V_7 , V_2 ) )
{
F_23 ( V_125 ) ;
return FALSE ;
}
F_23 ( V_125 ) ;
return TRUE ;
}
static void F_23 ( T_10 * V_125 )
{
struct V_126 * V_9 = (struct V_126 * ) V_125 -> V_36 ;
if ( V_9 )
{
if ( V_9 -> V_133 )
F_25 ( V_9 -> V_133 ) ;
}
}

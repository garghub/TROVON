int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
char V_4 [ sizeof F_2 ] ;
struct V_5 V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_10 = V_11 ;
if ( ! F_3 ( V_1 -> V_12 , V_4 , sizeof V_4 , V_2 , V_3 ) )
{
if ( * V_2 != V_13 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_4 , F_2 , sizeof F_2 ) != 0 )
{
return 0 ;
}
V_10 = V_11 ;
if ( ! F_3 ( V_1 -> V_12 , & V_6 , sizeof V_6 , V_2 , V_3 ) )
{
return - 1 ;
}
V_6 . V_14 = F_4 ( & V_6 . V_14 ) ;
if ( V_6 . V_14 != 1 )
{
* V_2 = V_15 ;
* V_3 = F_5 ( L_1 , V_6 . V_14 ) ;
return - 1 ;
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
* V_2 = V_23 ;
* V_3 = F_5 ( L_2 ,
V_6 . V_16 ) ;
return - 1 ;
}
V_1 -> V_24 = V_25 ;
V_1 -> V_26 = V_9 ;
V_1 -> V_27 = F_4 ( & V_6 . V_28 ) ;
V_1 -> V_29 = V_30 ;
V_1 -> V_31 = V_32 ;
V_1 -> V_33 = V_34 ;
V_8 = (struct V_7 * ) F_6 ( sizeof( struct V_7 ) ) ;
V_1 -> V_35 = ( void * ) V_8 ;
V_8 -> V_36 = F_7 ( & V_6 . V_36 ) ;
V_8 -> V_37 = ( ( double ) F_7 ( & V_6 . V_37 ) ) * 1000000 ;
V_8 -> V_38 = 1 ;
return 1 ;
}
static T_3 V_30 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_4 * V_39 )
{
struct V_7 * V_8 = (struct V_7 * ) V_1 -> V_35 ;
if ( V_8 -> V_38 > V_8 -> V_36 )
{
* V_2 = 0 ;
return FALSE ;
}
V_8 -> V_38 ++ ;
* V_39 = F_8 ( V_1 -> V_12 ) ;
return F_9 ( V_1 , V_1 -> V_12 , & V_1 -> V_40 , V_1 -> V_41 ,
V_2 , V_3 ) ;
}
static T_3 V_32 ( T_1 * V_1 , T_4 V_42 ,
struct V_43 * V_40 , T_5 * V_44 , int * V_2 , T_2 * * V_3 )
{
if ( F_10 ( V_1 -> V_45 , V_42 , V_46 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_9 ( V_1 , V_1 -> V_45 , V_40 , V_44 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_13 ;
return FALSE ;
}
return TRUE ;
}
static T_3
F_9 ( T_1 * V_1 , T_6 V_12 , struct V_43 * V_40 ,
T_5 * V_44 , int * V_2 , T_2 * * V_3 )
{
struct V_7 * V_8 = (struct V_7 * ) V_1 -> V_35 ;
struct V_47 V_48 ;
T_7 V_49 ;
struct V_50 V_51 ;
double V_52 ;
T_8 V_53 ;
T_7 V_54 ;
T_7 V_55 ;
T_9 * V_56 ;
V_10 = V_11 ;
if ( ! F_11 ( V_12 , & V_48 , ( unsigned int ) sizeof V_48 , V_2 , V_3 ) )
{
return FALSE ;
}
V_49 = F_4 ( & V_48 . V_57 ) ;
V_40 -> V_58 = V_59 ;
V_40 -> V_60 = V_61 | V_62 ;
V_52 = V_8 -> V_37 ;
V_52 += ( ( double ) F_7 ( & V_48 . V_63 ) ) * 1000 ;
V_53 = ( T_8 ) ( V_52 / 1000000 ) ;
V_54 = ( T_7 ) ( V_52 - V_53 * 1000000 ) ;
V_40 -> V_64 . V_53 = V_53 ;
V_40 -> V_64 . V_65 = V_54 * 1000 ;
V_40 -> V_66 = F_4 ( & V_48 . V_67 ) ;
V_55 = F_7 ( & V_48 . V_68 ) ;
switch ( V_1 -> V_26 )
{
case V_17 :
if ( V_40 -> V_66 < 4 )
{
* V_2 = V_69 ;
* V_3 = F_5 ( L_3 ,
V_40 -> V_66 ) ;
return FALSE ;
}
V_40 -> V_66 -= 4 ;
V_40 -> V_70 . V_71 . V_72 = - 1 ;
break;
case V_20 :
if ( V_40 -> V_66 < 2 )
{
* V_2 = V_69 ;
* V_3 = F_5 ( L_4 ,
V_40 -> V_66 ) ;
return FALSE ;
}
V_40 -> V_66 -= 2 ;
V_40 -> V_70 . V_73 . V_74 = ( V_55 & V_75 ) ? TRUE : FALSE ;
break;
case V_76 :
V_40 -> V_70 . V_73 . V_74 = ( V_55 & V_75 ) ? TRUE : FALSE ;
break;
case V_21 :
if ( V_40 -> V_66 < 2 )
{
* V_2 = V_69 ;
* V_3 = F_5 ( L_5 ,
V_40 -> V_66 ) ;
return FALSE ;
}
V_40 -> V_66 -= 2 ;
V_40 -> V_70 . V_77 . V_78 =
( V_55 & V_75 ) ? 0x00 : V_79 ;
break;
case V_19 :
if ( V_40 -> V_66 < 2 )
{
* V_2 = V_69 ;
* V_3 = F_5 ( L_5 ,
V_40 -> V_66 ) ;
return FALSE ;
}
V_40 -> V_66 -= 2 ;
V_40 -> V_70 . V_77 . V_78 =
( V_55 & V_75 ) ? 0x00 : V_79 ;
break;
case V_22 :
V_10 = V_11 ;
if ( ! F_3 ( V_12 , & V_51 , ( unsigned int ) sizeof V_51 , V_2 , V_3 ) )
{
return FALSE ;
}
V_49 -= ( T_7 ) sizeof V_51 ;
V_40 -> V_70 . V_80 . type = V_81 ;
V_40 -> V_70 . V_80 . V_82 = V_83 ;
V_40 -> V_70 . V_80 . V_84 = 0 ;
V_40 -> V_70 . V_80 . V_85 = 0 ;
V_40 -> V_70 . V_80 . V_86 = 0 ;
V_40 -> V_70 . V_80 . V_78 = 0 ;
V_40 -> V_70 . V_80 . V_87 = 0 ;
switch( V_51 . V_88 & V_89 )
{
case V_90 :
V_40 -> V_70 . V_80 . V_91 = V_92 ;
break;
case V_93 :
V_40 -> V_70 . V_80 . V_91 = V_94 ;
break;
case V_95 :
V_40 -> V_70 . V_80 . V_91 = V_96 ;
break;
case V_97 :
V_40 -> V_70 . V_80 . V_91 = V_98 ;
V_40 -> V_70 . V_80 . type = V_99 ;
V_40 -> V_70 . V_80 . V_84 = F_12 ( & V_51 . V_100 ) ;
break;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
V_40 -> V_70 . V_80 . V_91 = V_105 ;
break;
case V_106 :
default:
V_40 -> V_70 . V_80 . V_91 = V_107 ;
break;
}
V_40 -> V_70 . V_80 . V_108 = F_13 ( & V_51 . V_108 ) & 0x0FFF ;
V_40 -> V_70 . V_80 . V_109 = F_13 ( & V_51 . V_109 ) ;
V_40 -> V_70 . V_80 . V_110 = F_13 ( & V_51 . V_111 ) ;
V_40 -> V_70 . V_80 . V_112 = V_51 . V_113 & V_114 ;
break;
case V_18 :
default:
break;
}
V_40 -> V_115 = V_49 ;
if ( V_49 > V_116 )
{
* V_2 = V_69 ;
* V_3 = F_5 ( L_6 ,
V_49 , V_116 ) ;
return FALSE ;
}
if ( ! F_14 ( V_12 , V_44 , V_49 , V_2 , V_3 ) )
return FALSE ;
if ( V_1 -> V_26 == V_20 )
{
V_56 = F_15 ( V_44 ) ;
if ( V_48 . V_117 == 14 )
{
if ( V_49 >= 3 &&
( 0xfe == V_56 [ 0 ] ) && ( 0xfe == V_56 [ 1 ] ) && ( 0x03 == V_56 [ 2 ] ) )
{
V_40 -> V_118 = V_119 ;
}
else
{
V_40 -> V_118 = V_76 ;
}
}
else
{
if ( V_49 >= 2 && ( 0xff == V_56 [ 0 ] ) && ( 0x03 == V_56 [ 1 ] ) )
{
V_40 -> V_118 = V_76 ;
}
}
}
return TRUE ;
}
int F_16 ( int V_9 )
{
if ( V_9 == V_120 )
return V_121 ;
switch ( V_9 )
{
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_122 :
case V_76 :
return 0 ;
}
return V_23 ;
}
T_3 F_17 ( T_10 * V_123 , int * V_2 )
{
struct V_124 * V_8 ;
V_123 -> V_125 = V_126 ;
V_123 -> V_127 = V_128 ;
V_8 = (struct V_124 * ) F_6 ( sizeof( struct V_124 ) ) ;
V_123 -> V_35 = ( void * ) V_8 ;
V_8 -> V_129 = 0 ;
V_8 -> V_130 = 1024 ;
V_8 -> V_131 = 0 ;
V_8 -> V_132 = V_133 ;
if ( F_18 ( V_123 , V_133 , V_46 , V_2 ) == - 1 )
return FALSE ;
return TRUE ;
}
static T_3 V_126 ( T_10 * V_123 , const struct V_43 * V_40 ,
const T_9 * V_56 , int * V_2 )
{
const union V_134 * V_70 = & V_40 -> V_70 ;
struct V_124 * V_8 = (struct V_124 * ) V_123 -> V_35 ;
struct V_47 V_48 ;
T_11 V_135 = sizeof V_48 ;
T_12 V_136 ;
T_7 V_55 ;
if ( V_40 -> V_58 != V_59 ) {
* V_2 = V_137 ;
return FALSE ;
}
if ( V_40 -> V_115 > V_116 ) {
* V_2 = V_138 ;
return FALSE ;
}
if ( V_8 == 0 )
return FALSE ;
memset ( & V_48 , 0 , V_135 ) ;
if ( V_8 -> V_129 == 0 )
{
V_8 -> V_37 = ( T_7 ) V_40 -> V_64 . V_53 ;
V_8 -> V_131 = ( T_7 * ) F_6 ( 1024 * sizeof * V_8 -> V_131 ) ;
V_8 -> V_130 = 1024 ;
}
V_136 = V_40 -> V_64 . V_65 / 1000000 ;
V_136 += ( ( T_7 ) V_40 -> V_64 . V_53 - V_8 -> V_37 ) * 1000 ;
V_48 . V_63 = F_19 ( V_136 ) ;
V_48 . V_67 = F_20 ( V_40 -> V_66 ) ;
V_48 . V_57 = F_20 ( V_40 -> V_115 ) ;
switch ( V_123 -> V_9 )
{
case V_17 :
V_48 . V_117 = 2 ;
break;
case V_18 :
V_48 . V_117 = 3 ;
break;
case V_122 :
case V_76 :
V_48 . V_117 = 14 ;
break;
case V_20 :
V_48 . V_117 = 13 ;
break;
case V_21 :
V_48 . V_117 = 12 ;
break;
case V_19 :
default:
V_48 . V_117 = 1 ;
break;
}
V_55 = 0 ;
switch ( V_123 -> V_9 )
{
case V_20 :
V_55 |= ( V_70 -> V_73 . V_74 ? V_75 : 0x00 ) ;
break;
case V_21 :
case V_19 :
V_55 |=
( ( V_70 -> V_77 . V_78 & V_79 ) ? 0x00 : V_75 ) ;
break;
}
V_48 . V_68 = F_19 ( V_55 ) ;
if ( ! F_21 ( V_123 , & V_48 , V_135 , V_2 ) )
return FALSE ;
if ( ! F_21 ( V_123 , V_56 , V_40 -> V_115 , V_2 ) )
return FALSE ;
if ( V_8 -> V_129 >= V_8 -> V_130 )
{
V_8 -> V_130 *= 2 ;
V_8 -> V_131 = ( T_7 * ) F_22 ( V_8 -> V_131 ,
V_8 -> V_130 * sizeof * V_8 -> V_131 ) ;
}
V_8 -> V_131 [ V_8 -> V_129 ] = F_19 ( V_8 -> V_132 ) ;
V_8 -> V_129 ++ ;
V_8 -> V_132 += ( T_7 ) V_135 + V_40 -> V_115 ;
return TRUE ;
}
static T_3 V_128 ( T_10 * V_123 , int * V_2 )
{
struct V_124 * V_8 = (struct V_124 * ) V_123 -> V_35 ;
T_11 V_139 ;
struct V_5 V_6 ;
const char * V_140 ;
T_11 V_141 ;
if ( V_8 == 0 )
return FALSE ;
if ( V_8 -> V_131 )
{
V_139 = V_8 -> V_129 * sizeof * V_8 -> V_131 ;
if ( ! F_21 ( V_123 , V_8 -> V_131 , V_139 , V_2 ) )
{
F_23 ( V_123 ) ;
return FALSE ;
}
}
if ( F_18 ( V_123 , 0 , V_46 , V_2 ) == - 1 )
return FALSE ;
V_140 = F_2 ;
V_141 = sizeof F_2 ;
if ( ! F_21 ( V_123 , V_140 , V_141 , V_2 ) )
{
F_23 ( V_123 ) ;
return FALSE ;
}
memset ( & V_6 , '\0' , sizeof V_6 ) ;
V_6 . V_36 = F_19 ( V_8 -> V_129 ) ;
V_6 . V_37 = F_19 ( V_8 -> V_37 ) ;
V_6 . V_28 = F_20 ( 65535 ) ;
V_6 . V_142 = F_20 ( 1 ) ;
V_6 . V_14 = F_20 ( 1 ) ;
F_24 ( V_6 . V_143 , L_7 , 64 ) ;
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
case V_122 :
case V_76 :
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
struct V_124 * V_8 = (struct V_124 * ) V_123 -> V_35 ;
if ( V_8 )
{
if ( V_8 -> V_131 )
F_25 ( V_8 -> V_131 ) ;
}
}

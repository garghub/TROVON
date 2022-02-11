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
T_5 V_41 = 0 ;
int V_4 ;
struct V_42 V_43 ;
struct V_44 V_45 ;
int V_46 = sizeof( V_43 ) ;
int V_47 = sizeof( V_45 ) ;
T_6 V_48 ;
T_5 V_49 ;
double V_50 ;
if ( V_9 -> V_39 > V_9 -> V_37 )
{
* V_2 = 0 ;
return FALSE ;
}
V_9 -> V_39 ++ ;
V_11 = V_12 ;
V_4 = F_3 ( & V_43 , V_46 , V_1 -> V_13 ) ;
if ( V_4 != V_46 )
{
* V_2 = F_4 ( V_1 -> V_13 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
{
* V_2 = V_14 ;
}
return FALSE ;
}
V_41 = F_5 ( & V_43 . V_51 ) ;
if ( V_1 -> V_27 == V_23 )
{
V_11 = V_12 ;
V_4 = F_3 ( & V_45 , V_47 , V_1 -> V_13 ) ;
if ( V_4 != V_47 )
{
* V_2 = F_4 ( V_1 -> V_13 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
{
* V_2 = V_14 ;
}
return FALSE ;
}
V_41 -= V_47 ;
}
if ( V_41 > V_52 )
{
* V_2 = V_53 ;
* V_3 = F_6 ( L_3 ,
V_41 , V_52 ) ;
return FALSE ;
}
F_9 ( V_1 -> V_54 , V_41 ) ;
* V_40 = F_10 ( V_1 -> V_13 ) ;
V_11 = V_12 ;
V_4 = F_3 ( F_11 ( V_1 -> V_54 ) ,
V_41 , V_1 -> V_13 ) ;
if ( V_4 != ( int ) V_41 )
{
* V_2 = F_4 ( V_1 -> V_13 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_14 ;
return FALSE ;
}
V_1 -> V_55 . V_56 = V_57 | V_58 ;
V_50 = V_9 -> V_38 ;
V_50 += ( ( double ) F_8 ( & V_43 . V_59 ) ) * 1000 ;
V_48 = ( T_6 ) ( V_50 / 1000000 ) ;
V_49 = ( T_5 ) ( V_50 - V_48 * 1000000 ) ;
V_1 -> V_55 . V_60 . V_48 = V_48 ;
V_1 -> V_55 . V_60 . V_61 = V_49 * 1000 ;
V_1 -> V_55 . V_62 = V_41 ;
V_1 -> V_55 . V_63 = F_5 ( & V_43 . V_64 ) ;
switch ( V_1 -> V_27 )
{
case V_18 :
V_1 -> V_55 . V_63 -= 4 ;
break;
case V_22 :
case V_21 :
case V_20 :
V_1 -> V_55 . V_63 -= 2 ;
break;
case V_23 :
case V_19 :
default:
break;
}
if ( V_1 -> V_55 . V_63 > V_52 ) {
* V_2 = V_53 ;
* V_3 = F_6 ( L_4 ,
V_1 -> V_55 . V_63 , V_52 ) ;
return FALSE ;
}
if ( V_1 -> V_55 . V_63 < V_1 -> V_55 . V_62 )
{
V_1 -> V_55 . V_63 = V_1 -> V_55 . V_62 ;
}
F_12 ( V_1 -> V_27 , & V_43 , & V_45 , & V_1 -> V_55 . V_65 ) ;
if ( V_1 -> V_27 == V_21 )
{
if ( V_43 . V_66 == 14 )
{
T_7 * V_67 = F_11 ( V_1 -> V_54 ) ;
if ( ( 0xfe == V_67 [ 0 ] ) && ( 0xfe == V_67 [ 1 ] ) && ( 0x03 == V_67 [ 2 ] ) )
{
V_1 -> V_55 . V_68 = V_69 ;
}
else
{
V_1 -> V_55 . V_68 = V_70 ;
}
}
else
{
T_7 * V_67 = F_11 ( V_1 -> V_54 ) ;
if ( ( 0xff == V_67 [ 0 ] ) && ( 0x03 == V_67 [ 1 ] ) )
{
V_1 -> V_55 . V_68 = V_70 ;
}
}
}
return TRUE ;
}
static T_3 V_33 ( T_1 * V_1 , T_4 V_71 ,
struct V_72 * V_55 , T_7 * V_73 , int V_63 ,
int * V_2 , T_2 * * V_3 )
{
union V_74 * V_65 = & V_55 -> V_65 ;
struct V_42 V_43 ;
struct V_44 V_45 ;
int V_46 = sizeof( V_43 ) ;
int V_47 = sizeof( V_45 ) ;
int V_4 ;
int V_75 ;
V_75 = sizeof( struct V_42 ) ;
if ( V_1 -> V_27 == V_23 )
{
V_75 += ( int ) sizeof( struct V_44 ) ;
}
if ( F_13 ( V_1 -> V_76 , V_71 - V_75 ,
V_77 , V_2 ) == - 1 )
return FALSE ;
V_11 = V_12 ;
V_4 = F_3 ( & V_43 , V_46 , V_1 -> V_76 ) ;
if ( V_4 != V_46 ) {
* V_2 = F_4 ( V_1 -> V_76 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_14 ;
return FALSE ;
}
if ( V_1 -> V_27 == V_23 )
{
V_11 = V_12 ;
V_4 = F_3 ( & V_45 , V_47 , V_1 -> V_76 ) ;
if ( V_4 != V_47 )
{
* V_2 = F_4 ( V_1 -> V_13 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
{
* V_2 = V_14 ;
}
return FALSE ;
}
}
V_11 = V_12 ;
V_4 = F_3 ( V_73 , V_63 , V_1 -> V_76 ) ;
if ( V_4 != V_63 ) {
if ( * V_2 == 0 )
* V_2 = V_14 ;
return FALSE ;
}
F_12 ( V_1 -> V_27 , & V_43 , & V_45 , V_65 ) ;
return TRUE ;
}
static void F_12 ( int V_10 , struct V_42 * V_43 ,
struct V_44 * V_45 , union V_74 * V_65 )
{
T_5 V_78 ;
V_78 = F_8 ( & V_43 -> V_79 ) ;
switch ( V_10 )
{
case V_18 :
V_65 -> V_80 . V_81 = - 1 ;
break;
case V_21 :
case V_70 :
V_65 -> V_82 . V_83 = ( V_78 & V_84 ) ? TRUE : FALSE ;
break;
case V_22 :
case V_20 :
V_65 -> V_85 . V_86 =
( V_78 & V_84 ) ? 0x00 : V_87 ;
break;
case V_23 :
V_65 -> V_88 . type = V_89 ;
V_65 -> V_88 . V_90 = V_91 ;
V_65 -> V_88 . V_92 = 0 ;
V_65 -> V_88 . V_93 = 0 ;
V_65 -> V_88 . V_94 = 0 ;
V_65 -> V_88 . V_86 = 0 ;
V_65 -> V_88 . V_95 = 0 ;
switch( V_45 -> V_96 & V_97 )
{
case V_98 :
V_65 -> V_88 . V_99 = V_100 ;
break;
case V_101 :
V_65 -> V_88 . V_99 = V_102 ;
break;
case V_103 :
V_65 -> V_88 . V_99 = V_104 ;
break;
case V_105 :
V_65 -> V_88 . V_99 = V_106 ;
V_65 -> V_88 . type = V_107 ;
V_65 -> V_88 . V_92 = F_14 ( & V_45 -> V_108 ) ;
break;
case V_109 :
case V_110 :
case V_111 :
case V_112 :
V_65 -> V_88 . V_99 = V_113 ;
break;
case V_114 :
default:
V_65 -> V_88 . V_99 = V_115 ;
break;
}
V_65 -> V_88 . V_116 = F_15 ( & V_45 -> V_116 ) & 0x0FFF ;
V_65 -> V_88 . V_117 = F_15 ( & V_45 -> V_117 ) ;
V_65 -> V_88 . V_118 = F_15 ( & V_45 -> V_119 ) ;
V_65 -> V_88 . V_120 = V_45 -> V_121 & V_122 ;
break;
}
}
int F_16 ( int V_10 )
{
if ( V_10 == V_123 )
return V_124 ;
switch ( V_10 )
{
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_125 :
case V_70 :
return 0 ;
}
return V_24 ;
}
T_3 F_17 ( T_8 * V_126 , int * V_2 )
{
struct V_127 * V_9 ;
V_126 -> V_128 = V_129 ;
V_126 -> V_130 = V_131 ;
V_9 = (struct V_127 * ) F_7 ( sizeof( struct V_127 ) ) ;
V_126 -> V_36 = ( void * ) V_9 ;
V_9 -> V_132 = 0 ;
V_9 -> V_133 = 1024 ;
V_9 -> V_134 = 0 ;
V_9 -> V_135 = V_136 ;
if ( F_18 ( V_126 , V_136 , V_77 , V_2 ) == - 1 )
return FALSE ;
return TRUE ;
}
static T_3 V_129 ( T_8 * V_126 , const struct V_72 * V_55 ,
const T_7 * V_73 , int * V_2 )
{
const union V_74 * V_65 = & V_55 -> V_65 ;
struct V_127 * V_9 = (struct V_127 * ) V_126 -> V_36 ;
struct V_42 V_43 ;
T_9 V_137 = sizeof V_43 ;
T_10 V_138 ;
T_5 V_78 ;
if ( V_9 == 0 )
return FALSE ;
memset ( & V_43 , 0 , V_137 ) ;
if ( V_9 -> V_132 == 0 )
{
V_9 -> V_38 = ( T_5 ) V_55 -> V_60 . V_48 ;
V_9 -> V_134 = ( T_5 * ) F_7 ( 1024 * sizeof * V_9 -> V_134 ) ;
V_9 -> V_133 = 1024 ;
}
V_138 = V_55 -> V_60 . V_61 / 1000000 ;
V_138 += ( ( T_5 ) V_55 -> V_60 . V_48 - V_9 -> V_38 ) * 1000 ;
V_43 . V_59 = F_19 ( V_138 ) ;
V_43 . V_64 = F_20 ( V_55 -> V_63 ) ;
V_43 . V_51 = F_20 ( V_55 -> V_62 ) ;
switch ( V_126 -> V_10 )
{
case V_18 :
V_43 . V_66 = 2 ;
break;
case V_19 :
V_43 . V_66 = 3 ;
break;
case V_125 :
case V_70 :
V_43 . V_66 = 14 ;
break;
case V_21 :
V_43 . V_66 = 13 ;
break;
case V_22 :
V_43 . V_66 = 12 ;
break;
case V_20 :
default:
V_43 . V_66 = 1 ;
break;
}
V_78 = 0 ;
switch ( V_126 -> V_10 )
{
case V_21 :
V_78 |= ( V_65 -> V_82 . V_83 ? V_84 : 0x00 ) ;
break;
case V_22 :
case V_20 :
V_78 |=
( ( V_65 -> V_85 . V_86 & V_87 ) ? 0x00 : V_84 ) ;
break;
}
V_43 . V_79 = F_19 ( V_78 ) ;
if ( ! F_21 ( V_126 , & V_43 , V_137 , V_2 ) )
return FALSE ;
if ( ! F_21 ( V_126 , V_73 , V_55 -> V_62 , V_2 ) )
return FALSE ;
if ( V_9 -> V_132 >= V_9 -> V_133 )
{
V_9 -> V_133 *= 2 ;
V_9 -> V_134 = ( T_5 * ) F_22 ( V_9 -> V_134 ,
V_9 -> V_133 * sizeof * V_9 -> V_134 ) ;
}
V_9 -> V_134 [ V_9 -> V_132 ] = F_19 ( V_9 -> V_135 ) ;
V_9 -> V_132 ++ ;
V_9 -> V_135 += ( T_5 ) V_137 + V_55 -> V_62 ;
return TRUE ;
}
static T_3 V_131 ( T_8 * V_126 , int * V_2 )
{
struct V_127 * V_9 = (struct V_127 * ) V_126 -> V_36 ;
T_9 V_139 ;
struct V_6 V_7 ;
const char * V_140 ;
T_9 V_141 ;
if ( V_9 == 0 )
return FALSE ;
if ( V_9 -> V_134 )
{
V_139 = V_9 -> V_132 * sizeof * V_9 -> V_134 ;
if ( ! F_21 ( V_126 , V_9 -> V_134 , V_139 , V_2 ) )
{
F_23 ( V_126 ) ;
return FALSE ;
}
}
if ( F_18 ( V_126 , 0 , V_77 , V_2 ) == - 1 )
return FALSE ;
V_140 = F_2 ;
V_141 = sizeof F_2 ;
if ( ! F_21 ( V_126 , V_140 , V_141 , V_2 ) )
{
F_23 ( V_126 ) ;
return FALSE ;
}
memset ( & V_7 , '\0' , sizeof V_7 ) ;
V_7 . V_37 = F_19 ( V_9 -> V_132 ) ;
V_7 . V_38 = F_19 ( V_9 -> V_38 ) ;
V_7 . V_29 = F_20 ( 65535 ) ;
V_7 . V_142 = F_20 ( 1 ) ;
V_7 . V_15 = F_20 ( 1 ) ;
F_24 ( V_7 . V_143 , L_5 , 64 ) ;
switch ( V_126 -> V_10 )
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
case V_125 :
case V_70 :
case V_21 :
V_7 . V_17 = F_20 ( 22 ) ;
break;
case V_22 :
V_7 . V_17 = F_20 ( 32 ) ;
break;
}
if ( ! F_21 ( V_126 , & V_7 , sizeof V_7 , V_2 ) )
{
F_23 ( V_126 ) ;
return FALSE ;
}
F_23 ( V_126 ) ;
return TRUE ;
}
static void F_23 ( T_8 * V_126 )
{
struct V_127 * V_9 = (struct V_127 * ) V_126 -> V_36 ;
if ( V_9 )
{
if ( V_9 -> V_134 )
F_25 ( V_9 -> V_134 ) ;
}
}

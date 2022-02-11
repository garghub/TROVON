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
if ( * V_2 != 0 )
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
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
V_7 . V_14 = F_5 ( & V_7 . V_14 ) ;
if ( V_7 . V_14 != 1 )
{
* V_2 = V_15 ;
* V_3 = F_6 ( L_1 , V_7 . V_14 ) ;
return - 1 ;
}
switch ( F_5 ( & V_7 . V_16 ) )
{
case 6 :
V_10 = V_17 ;
break;
case 9 :
V_10 = V_18 ;
break;
case 16 :
V_10 = V_19 ;
break;
case 22 :
case 118 :
V_10 = V_20 ;
break;
case 32 :
V_10 = V_21 ;
break;
case 37 :
V_10 = V_22 ;
break;
default:
* V_2 = V_23 ;
* V_3 = F_6 ( L_2 ,
V_7 . V_16 ) ;
return - 1 ;
}
V_1 -> V_24 = V_25 ;
V_1 -> V_26 = V_10 ;
V_1 -> V_27 = F_5 ( & V_7 . V_28 ) ;
V_1 -> V_29 = V_30 ;
V_1 -> V_31 = V_32 ;
V_1 -> V_33 = V_34 ;
V_9 = (struct V_8 * ) F_7 ( sizeof( struct V_8 ) ) ;
V_1 -> V_35 = ( void * ) V_9 ;
V_9 -> V_36 = F_8 ( & V_7 . V_36 ) ;
V_9 -> V_37 = ( ( double ) F_8 ( & V_7 . V_37 ) ) * 1000000 ;
V_9 -> V_38 = 1 ;
return 1 ;
}
static T_3 V_30 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_4 * V_39 )
{
struct V_8 * V_9 = (struct V_8 * ) V_1 -> V_35 ;
T_5 V_40 = 0 ;
int V_4 ;
struct V_41 V_42 ;
struct V_43 V_44 ;
int V_45 = sizeof( V_42 ) ;
int V_46 = sizeof( V_44 ) ;
T_6 V_47 ;
T_5 V_48 ;
double V_49 ;
if ( V_9 -> V_38 > V_9 -> V_36 )
{
* V_2 = 0 ;
return FALSE ;
}
V_9 -> V_38 ++ ;
V_11 = V_12 ;
V_4 = F_3 ( & V_42 , V_45 , V_1 -> V_13 ) ;
if ( V_4 != V_45 )
{
* V_2 = F_4 ( V_1 -> V_13 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
{
* V_2 = V_50 ;
}
return FALSE ;
}
V_40 = F_5 ( & V_42 . V_51 ) ;
if ( V_1 -> V_26 == V_22 )
{
V_11 = V_12 ;
V_4 = F_3 ( & V_44 , V_46 , V_1 -> V_13 ) ;
if ( V_4 != V_46 )
{
* V_2 = F_4 ( V_1 -> V_13 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
{
* V_2 = V_50 ;
}
return FALSE ;
}
V_40 -= V_46 ;
}
if ( V_40 > V_52 )
{
* V_2 = V_53 ;
* V_3 = F_6 ( L_3 ,
V_40 , V_52 ) ;
return FALSE ;
}
F_9 ( V_1 -> V_54 , V_40 ) ;
* V_39 = F_10 ( V_1 -> V_13 ) ;
V_11 = V_12 ;
V_4 = F_3 ( F_11 ( V_1 -> V_54 ) ,
V_40 , V_1 -> V_13 ) ;
if ( V_4 != ( int ) V_40 )
{
* V_2 = F_4 ( V_1 -> V_13 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_50 ;
return FALSE ;
}
V_1 -> V_55 . V_56 = V_57 | V_58 ;
V_49 = V_9 -> V_37 ;
V_49 += ( ( double ) F_8 ( & V_42 . V_59 ) ) * 1000 ;
V_47 = ( T_6 ) ( V_49 / 1000000 ) ;
V_48 = ( T_5 ) ( V_49 - V_47 * 1000000 ) ;
V_1 -> V_55 . V_60 . V_47 = V_47 ;
V_1 -> V_55 . V_60 . V_61 = V_48 * 1000 ;
V_1 -> V_55 . V_62 = V_40 ;
V_1 -> V_55 . V_63 = F_5 ( & V_42 . V_64 ) ;
switch ( V_1 -> V_26 )
{
case V_17 :
V_1 -> V_55 . V_63 -= 4 ;
break;
case V_21 :
case V_20 :
case V_19 :
V_1 -> V_55 . V_63 -= 2 ;
break;
case V_22 :
case V_18 :
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
F_12 ( V_1 -> V_26 , & V_42 , & V_44 , & V_1 -> V_65 ) ;
if ( V_1 -> V_26 == V_20 )
{
if ( V_42 . V_66 == 14 )
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
static T_3 V_32 ( T_1 * V_1 , T_4 V_71 ,
union V_72 * V_65 , T_7 * V_73 , int V_63 ,
int * V_2 , T_2 * * V_3 )
{
struct V_41 V_42 ;
struct V_43 V_44 ;
int V_45 = sizeof( V_42 ) ;
int V_46 = sizeof( V_44 ) ;
int V_4 ;
int V_74 ;
V_74 = sizeof( struct V_41 ) ;
if ( V_1 -> V_26 == V_22 )
{
V_74 += ( int ) sizeof( struct V_43 ) ;
}
if ( F_13 ( V_1 -> V_75 , V_71 - V_74 ,
V_76 , V_2 ) == - 1 )
return FALSE ;
V_11 = V_12 ;
V_4 = F_3 ( & V_42 , V_45 , V_1 -> V_75 ) ;
if ( V_4 != V_45 ) {
* V_2 = F_4 ( V_1 -> V_75 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_50 ;
return FALSE ;
}
if ( V_1 -> V_26 == V_22 )
{
V_11 = V_12 ;
V_4 = F_3 ( & V_44 , V_46 , V_1 -> V_75 ) ;
if ( V_4 != V_46 )
{
* V_2 = F_4 ( V_1 -> V_13 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
{
* V_2 = V_50 ;
}
return FALSE ;
}
}
V_11 = V_12 ;
V_4 = F_3 ( V_73 , V_63 , V_1 -> V_75 ) ;
if ( V_4 != V_63 ) {
if ( * V_2 == 0 )
* V_2 = V_50 ;
return FALSE ;
}
F_12 ( V_1 -> V_26 , & V_42 , & V_44 , V_65 ) ;
return TRUE ;
}
static void F_12 ( int V_10 , struct V_41 * V_42 ,
struct V_43 * V_44 , union V_72 * V_65 )
{
T_5 V_77 ;
V_77 = F_8 ( & V_42 -> V_78 ) ;
switch ( V_10 )
{
case V_17 :
V_65 -> V_79 . V_80 = - 1 ;
break;
case V_20 :
case V_70 :
V_65 -> V_81 . V_82 = ( V_77 & V_83 ) ? TRUE : FALSE ;
break;
case V_21 :
case V_19 :
V_65 -> V_84 . V_85 =
( V_77 & V_83 ) ? 0x00 : V_86 ;
break;
case V_22 :
V_65 -> V_87 . type = V_88 ;
V_65 -> V_87 . V_89 = V_90 ;
V_65 -> V_87 . V_91 = 0 ;
V_65 -> V_87 . V_92 = 0 ;
V_65 -> V_87 . V_93 = 0 ;
V_65 -> V_87 . V_85 = 0 ;
V_65 -> V_87 . V_94 = 0 ;
switch( V_44 -> V_95 & V_96 )
{
case V_97 :
V_65 -> V_87 . V_98 = V_99 ;
break;
case V_100 :
V_65 -> V_87 . V_98 = V_101 ;
break;
case V_102 :
V_65 -> V_87 . V_98 = V_103 ;
break;
case V_104 :
V_65 -> V_87 . V_98 = V_105 ;
V_65 -> V_87 . type = V_106 ;
V_65 -> V_87 . V_91 = F_14 ( & V_44 -> V_107 ) ;
break;
case V_108 :
case V_109 :
case V_110 :
case V_111 :
V_65 -> V_87 . V_98 = V_112 ;
break;
case V_113 :
default:
V_65 -> V_87 . V_98 = V_114 ;
break;
}
V_65 -> V_87 . V_115 = F_15 ( & V_44 -> V_115 ) & 0x0FFF ;
V_65 -> V_87 . V_116 = F_15 ( & V_44 -> V_116 ) ;
V_65 -> V_87 . V_117 = F_15 ( & V_44 -> V_118 ) ;
V_65 -> V_87 . V_119 = V_44 -> V_120 & V_121 ;
break;
}
}
int F_16 ( int V_10 )
{
if ( V_10 == V_122 )
return V_123 ;
switch ( V_10 )
{
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_124 :
case V_70 :
return 0 ;
}
return V_23 ;
}
T_3 F_17 ( T_8 * V_125 , int * V_2 )
{
struct V_126 * V_9 ;
V_125 -> V_127 = V_128 ;
V_125 -> V_129 = V_130 ;
V_9 = (struct V_126 * ) F_7 ( sizeof( struct V_126 ) ) ;
V_125 -> V_35 = ( void * ) V_9 ;
V_9 -> V_131 = 0 ;
V_9 -> V_132 = 1024 ;
V_9 -> V_133 = 0 ;
V_9 -> V_134 = V_135 ;
if ( fseek ( V_125 -> V_13 , V_135 , V_76 ) == - 1 ) {
* V_2 = V_11 ;
return FALSE ;
}
return TRUE ;
}
static T_3 V_128 ( T_8 * V_125 , const struct V_136 * V_55 ,
const union V_72 * V_65 , const T_7 * V_73 , int * V_2 )
{
struct V_126 * V_9 = (struct V_126 * ) V_125 -> V_35 ;
struct V_41 V_42 ;
T_9 V_137 = sizeof V_42 ;
unsigned V_138 ;
T_5 V_77 ;
if ( V_9 == 0 )
return FALSE ;
memset ( & V_42 , 0 , V_137 ) ;
if ( V_9 -> V_131 == 0 )
{
V_9 -> V_37 = ( T_5 ) V_55 -> V_60 . V_47 ;
V_9 -> V_133 = ( T_5 * ) F_7 ( 1024 * sizeof * V_9 -> V_133 ) ;
V_9 -> V_132 = 1024 ;
}
V_138 = V_55 -> V_60 . V_61 / 1000000 ;
V_138 += ( ( T_5 ) V_55 -> V_60 . V_47 - V_9 -> V_37 ) * 1000 ;
V_42 . V_59 = F_18 ( V_138 ) ;
V_42 . V_64 = F_19 ( V_55 -> V_63 ) ;
V_42 . V_51 = F_19 ( V_55 -> V_62 ) ;
switch ( V_125 -> V_10 )
{
case V_17 :
V_42 . V_66 = 2 ;
break;
case V_18 :
V_42 . V_66 = 3 ;
break;
case V_124 :
case V_70 :
V_42 . V_66 = 14 ;
break;
case V_20 :
V_42 . V_66 = 13 ;
break;
case V_21 :
V_42 . V_66 = 12 ;
break;
case V_19 :
default:
V_42 . V_66 = 1 ;
break;
}
V_77 = 0 ;
switch ( V_125 -> V_10 )
{
case V_20 :
V_77 |= ( V_65 -> V_81 . V_82 ? V_83 : 0x00 ) ;
break;
case V_21 :
case V_19 :
V_77 |=
( ( V_65 -> V_84 . V_85 & V_86 ) ? 0x00 : V_83 ) ;
break;
}
V_42 . V_78 = F_18 ( V_77 ) ;
if ( ! F_20 ( V_125 , & V_42 , V_137 , V_2 ) )
return FALSE ;
if ( ! F_20 ( V_125 , V_73 , V_55 -> V_62 , V_2 ) )
return FALSE ;
if ( V_9 -> V_131 >= V_9 -> V_132 )
{
V_9 -> V_132 *= 2 ;
V_9 -> V_133 = ( T_5 * ) F_21 ( V_9 -> V_133 ,
V_9 -> V_132 * sizeof * V_9 -> V_133 ) ;
}
V_9 -> V_133 [ V_9 -> V_131 ] = F_18 ( V_9 -> V_134 ) ;
V_9 -> V_131 ++ ;
V_9 -> V_134 += ( T_5 ) V_137 + V_55 -> V_62 ;
return TRUE ;
}
static T_3 V_130 ( T_8 * V_125 , int * V_2 )
{
struct V_126 * V_9 = (struct V_126 * ) V_125 -> V_35 ;
T_9 V_139 ;
struct V_6 V_7 ;
const char * V_140 ;
T_9 V_141 ;
if ( V_9 == 0 )
return FALSE ;
if ( V_9 -> V_133 )
{
V_139 = V_9 -> V_131 * sizeof * V_9 -> V_133 ;
if ( ! F_20 ( V_125 , V_9 -> V_133 , V_139 , V_2 ) )
{
F_22 ( V_125 ) ;
return FALSE ;
}
}
fseek ( V_125 -> V_13 , 0 , V_76 ) ;
V_140 = F_2 ;
V_141 = sizeof F_2 ;
if ( ! F_20 ( V_125 , V_140 , V_141 , V_2 ) )
{
F_22 ( V_125 ) ;
return FALSE ;
}
memset ( & V_7 , '\0' , sizeof V_7 ) ;
V_7 . V_36 = F_18 ( V_9 -> V_131 ) ;
V_7 . V_37 = F_18 ( V_9 -> V_37 ) ;
V_7 . V_28 = F_19 ( 65535 ) ;
V_7 . V_142 = F_19 ( 1 ) ;
V_7 . V_14 = F_19 ( 1 ) ;
F_23 ( V_7 . V_143 , L_5 , 64 ) ;
switch ( V_125 -> V_10 )
{
case V_17 :
V_7 . V_16 = F_19 ( 6 ) ;
break;
case V_18 :
V_7 . V_16 = F_19 ( 9 ) ;
break;
case V_19 :
V_7 . V_16 = F_19 ( 16 ) ;
break;
case V_124 :
case V_70 :
case V_20 :
V_7 . V_16 = F_19 ( 22 ) ;
break;
case V_21 :
V_7 . V_16 = F_19 ( 32 ) ;
break;
}
if ( ! F_20 ( V_125 , & V_7 , sizeof V_7 , V_2 ) )
{
F_22 ( V_125 ) ;
return FALSE ;
}
F_22 ( V_125 ) ;
return TRUE ;
}
static void F_22 ( T_8 * V_125 )
{
struct V_126 * V_9 = (struct V_126 * ) V_125 -> V_35 ;
if ( V_9 )
{
if ( V_9 -> V_133 )
F_24 ( V_9 -> V_133 ) ;
}
}

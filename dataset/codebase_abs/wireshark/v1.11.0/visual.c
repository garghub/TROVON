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
struct V_44 * V_41 , T_5 * V_45 , int T_6 V_46 ,
int * V_2 , T_2 * * V_3 )
{
if ( F_11 ( V_1 -> V_47 , V_43 , V_48 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_10 ( V_1 , V_1 -> V_47 , V_41 , V_45 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_14 ;
return FALSE ;
}
return TRUE ;
}
static T_3
F_10 ( T_1 * V_1 , T_7 V_13 , struct V_44 * V_41 ,
T_5 * V_45 , int * V_2 , T_2 * * V_3 )
{
struct V_8 * V_9 = (struct V_8 * ) V_1 -> V_36 ;
struct V_49 V_50 ;
int V_4 ;
T_8 V_51 ;
struct V_52 V_53 ;
double V_54 ;
T_9 V_55 ;
T_8 V_56 ;
T_8 V_57 ;
T_10 * V_58 ;
V_11 = V_12 ;
V_4 = F_3 ( & V_50 , ( unsigned int ) sizeof V_50 , V_13 ) ;
if ( V_4 < 0 || ( V_59 ) V_4 != sizeof V_50 )
{
* V_2 = F_4 ( V_13 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
{
* V_2 = V_14 ;
}
return FALSE ;
}
V_51 = F_5 ( & V_50 . V_60 ) ;
V_41 -> V_61 = V_62 | V_63 ;
V_54 = V_9 -> V_38 ;
V_54 += ( ( double ) F_8 ( & V_50 . V_64 ) ) * 1000 ;
V_55 = ( T_9 ) ( V_54 / 1000000 ) ;
V_56 = ( T_8 ) ( V_54 - V_55 * 1000000 ) ;
V_41 -> V_65 . V_55 = V_55 ;
V_41 -> V_65 . V_66 = V_56 * 1000 ;
V_41 -> T_6 = F_5 ( & V_50 . V_67 ) ;
V_57 = F_8 ( & V_50 . V_68 ) ;
switch ( V_1 -> V_27 )
{
case V_18 :
if ( V_41 -> T_6 < 4 )
{
* V_2 = V_69 ;
* V_3 = F_6 ( L_3 ,
V_41 -> T_6 ) ;
return FALSE ;
}
V_41 -> T_6 -= 4 ;
V_41 -> V_70 . V_71 . V_72 = - 1 ;
break;
case V_21 :
if ( V_41 -> T_6 < 2 )
{
* V_2 = V_69 ;
* V_3 = F_6 ( L_4 ,
V_41 -> T_6 ) ;
return FALSE ;
}
V_41 -> T_6 -= 2 ;
V_41 -> V_70 . V_73 . V_74 = ( V_57 & V_75 ) ? TRUE : FALSE ;
break;
case V_76 :
V_41 -> V_70 . V_73 . V_74 = ( V_57 & V_75 ) ? TRUE : FALSE ;
break;
case V_22 :
if ( V_41 -> T_6 < 2 )
{
* V_2 = V_69 ;
* V_3 = F_6 ( L_5 ,
V_41 -> T_6 ) ;
return FALSE ;
}
V_41 -> T_6 -= 2 ;
V_41 -> V_70 . V_77 . V_78 =
( V_57 & V_75 ) ? 0x00 : V_79 ;
break;
case V_20 :
if ( V_41 -> T_6 < 2 )
{
* V_2 = V_69 ;
* V_3 = F_6 ( L_5 ,
V_41 -> T_6 ) ;
return FALSE ;
}
V_41 -> T_6 -= 2 ;
V_41 -> V_70 . V_77 . V_78 =
( V_57 & V_75 ) ? 0x00 : V_79 ;
break;
case V_23 :
V_11 = V_12 ;
V_4 = F_3 ( & V_53 , ( unsigned int ) sizeof V_53 , V_13 ) ;
if ( V_4 < 0 || ( V_59 ) V_4 != sizeof V_53 )
{
* V_2 = F_4 ( V_13 , V_3 ) ;
if ( * V_2 == 0 )
{
* V_2 = V_14 ;
}
return FALSE ;
}
V_51 -= ( T_8 ) sizeof V_53 ;
V_41 -> V_70 . V_80 . type = V_81 ;
V_41 -> V_70 . V_80 . V_82 = V_83 ;
V_41 -> V_70 . V_80 . V_84 = 0 ;
V_41 -> V_70 . V_80 . V_85 = 0 ;
V_41 -> V_70 . V_80 . V_86 = 0 ;
V_41 -> V_70 . V_80 . V_78 = 0 ;
V_41 -> V_70 . V_80 . V_87 = 0 ;
switch( V_53 . V_88 & V_89 )
{
case V_90 :
V_41 -> V_70 . V_80 . V_91 = V_92 ;
break;
case V_93 :
V_41 -> V_70 . V_80 . V_91 = V_94 ;
break;
case V_95 :
V_41 -> V_70 . V_80 . V_91 = V_96 ;
break;
case V_97 :
V_41 -> V_70 . V_80 . V_91 = V_98 ;
V_41 -> V_70 . V_80 . type = V_99 ;
V_41 -> V_70 . V_80 . V_84 = F_12 ( & V_53 . V_100 ) ;
break;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
V_41 -> V_70 . V_80 . V_91 = V_105 ;
break;
case V_106 :
default:
V_41 -> V_70 . V_80 . V_91 = V_107 ;
break;
}
V_41 -> V_70 . V_80 . V_108 = F_13 ( & V_53 . V_108 ) & 0x0FFF ;
V_41 -> V_70 . V_80 . V_109 = F_13 ( & V_53 . V_109 ) ;
V_41 -> V_70 . V_80 . V_110 = F_13 ( & V_53 . V_111 ) ;
V_41 -> V_70 . V_80 . V_112 = V_53 . V_113 & V_114 ;
break;
case V_19 :
default:
break;
}
V_41 -> V_115 = V_51 ;
if ( V_51 > V_116 )
{
* V_2 = V_69 ;
* V_3 = F_6 ( L_6 ,
V_51 , V_116 ) ;
return FALSE ;
}
if ( V_41 -> T_6 < V_41 -> V_115 )
{
V_41 -> T_6 = V_41 -> V_115 ;
}
if ( ! F_14 ( V_13 , V_45 , V_51 , V_2 , V_3 ) )
return FALSE ;
if ( V_1 -> V_27 == V_21 )
{
V_58 = F_15 ( V_45 ) ;
if ( V_50 . V_117 == 14 )
{
if ( V_51 >= 3 &&
( 0xfe == V_58 [ 0 ] ) && ( 0xfe == V_58 [ 1 ] ) && ( 0x03 == V_58 [ 2 ] ) )
{
V_41 -> V_118 = V_119 ;
}
else
{
V_41 -> V_118 = V_76 ;
}
}
else
{
if ( V_51 >= 2 && ( 0xff == V_58 [ 0 ] ) && ( 0x03 == V_58 [ 1 ] ) )
{
V_41 -> V_118 = V_76 ;
}
}
}
return TRUE ;
}
int F_16 ( int V_10 )
{
if ( V_10 == V_120 )
return V_121 ;
switch ( V_10 )
{
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_122 :
case V_76 :
return 0 ;
}
return V_24 ;
}
T_3 F_17 ( T_11 * V_123 , int * V_2 )
{
struct V_124 * V_9 ;
V_123 -> V_125 = V_126 ;
V_123 -> V_127 = V_128 ;
V_9 = (struct V_124 * ) F_7 ( sizeof( struct V_124 ) ) ;
V_123 -> V_36 = ( void * ) V_9 ;
V_9 -> V_129 = 0 ;
V_9 -> V_130 = 1024 ;
V_9 -> V_131 = 0 ;
V_9 -> V_132 = V_133 ;
if ( F_18 ( V_123 , V_133 , V_48 , V_2 ) == - 1 )
return FALSE ;
return TRUE ;
}
static T_3 V_126 ( T_11 * V_123 , const struct V_44 * V_41 ,
const T_10 * V_58 , int * V_2 )
{
const union V_134 * V_70 = & V_41 -> V_70 ;
struct V_124 * V_9 = (struct V_124 * ) V_123 -> V_36 ;
struct V_49 V_50 ;
V_59 V_135 = sizeof V_50 ;
T_12 V_136 ;
T_8 V_57 ;
if ( V_9 == 0 )
return FALSE ;
memset ( & V_50 , 0 , V_135 ) ;
if ( V_9 -> V_129 == 0 )
{
V_9 -> V_38 = ( T_8 ) V_41 -> V_65 . V_55 ;
V_9 -> V_131 = ( T_8 * ) F_7 ( 1024 * sizeof * V_9 -> V_131 ) ;
V_9 -> V_130 = 1024 ;
}
V_136 = V_41 -> V_65 . V_66 / 1000000 ;
V_136 += ( ( T_8 ) V_41 -> V_65 . V_55 - V_9 -> V_38 ) * 1000 ;
V_50 . V_64 = F_19 ( V_136 ) ;
V_50 . V_67 = F_20 ( V_41 -> T_6 ) ;
V_50 . V_60 = F_20 ( V_41 -> V_115 ) ;
switch ( V_123 -> V_10 )
{
case V_18 :
V_50 . V_117 = 2 ;
break;
case V_19 :
V_50 . V_117 = 3 ;
break;
case V_122 :
case V_76 :
V_50 . V_117 = 14 ;
break;
case V_21 :
V_50 . V_117 = 13 ;
break;
case V_22 :
V_50 . V_117 = 12 ;
break;
case V_20 :
default:
V_50 . V_117 = 1 ;
break;
}
V_57 = 0 ;
switch ( V_123 -> V_10 )
{
case V_21 :
V_57 |= ( V_70 -> V_73 . V_74 ? V_75 : 0x00 ) ;
break;
case V_22 :
case V_20 :
V_57 |=
( ( V_70 -> V_77 . V_78 & V_79 ) ? 0x00 : V_75 ) ;
break;
}
V_50 . V_68 = F_19 ( V_57 ) ;
if ( ! F_21 ( V_123 , & V_50 , V_135 , V_2 ) )
return FALSE ;
if ( ! F_21 ( V_123 , V_58 , V_41 -> V_115 , V_2 ) )
return FALSE ;
if ( V_9 -> V_129 >= V_9 -> V_130 )
{
V_9 -> V_130 *= 2 ;
V_9 -> V_131 = ( T_8 * ) F_22 ( V_9 -> V_131 ,
V_9 -> V_130 * sizeof * V_9 -> V_131 ) ;
}
V_9 -> V_131 [ V_9 -> V_129 ] = F_19 ( V_9 -> V_132 ) ;
V_9 -> V_129 ++ ;
V_9 -> V_132 += ( T_8 ) V_135 + V_41 -> V_115 ;
return TRUE ;
}
static T_3 V_128 ( T_11 * V_123 , int * V_2 )
{
struct V_124 * V_9 = (struct V_124 * ) V_123 -> V_36 ;
V_59 V_137 ;
struct V_6 V_7 ;
const char * V_138 ;
V_59 V_139 ;
if ( V_9 == 0 )
return FALSE ;
if ( V_9 -> V_131 )
{
V_137 = V_9 -> V_129 * sizeof * V_9 -> V_131 ;
if ( ! F_21 ( V_123 , V_9 -> V_131 , V_137 , V_2 ) )
{
F_23 ( V_123 ) ;
return FALSE ;
}
}
if ( F_18 ( V_123 , 0 , V_48 , V_2 ) == - 1 )
return FALSE ;
V_138 = F_2 ;
V_139 = sizeof F_2 ;
if ( ! F_21 ( V_123 , V_138 , V_139 , V_2 ) )
{
F_23 ( V_123 ) ;
return FALSE ;
}
memset ( & V_7 , '\0' , sizeof V_7 ) ;
V_7 . V_37 = F_19 ( V_9 -> V_129 ) ;
V_7 . V_38 = F_19 ( V_9 -> V_38 ) ;
V_7 . V_29 = F_20 ( 65535 ) ;
V_7 . V_140 = F_20 ( 1 ) ;
V_7 . V_15 = F_20 ( 1 ) ;
F_24 ( V_7 . V_141 , L_7 , 64 ) ;
switch ( V_123 -> V_10 )
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
case V_122 :
case V_76 :
case V_21 :
V_7 . V_17 = F_20 ( 22 ) ;
break;
case V_22 :
V_7 . V_17 = F_20 ( 32 ) ;
break;
}
if ( ! F_21 ( V_123 , & V_7 , sizeof V_7 , V_2 ) )
{
F_23 ( V_123 ) ;
return FALSE ;
}
F_23 ( V_123 ) ;
return TRUE ;
}
static void F_23 ( T_11 * V_123 )
{
struct V_124 * V_9 = (struct V_124 * ) V_123 -> V_36 ;
if ( V_9 )
{
if ( V_9 -> V_131 )
F_25 ( V_9 -> V_131 ) ;
}
}

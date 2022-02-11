static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( void )
{
static int V_4 ;
T_1 * V_5 = V_6 ;
if ( V_4 )
return;
V_4 = 1 ;
V_5 [ V_7 ] = 0x2c ;
V_5 [ V_8 ] = 0x12 ;
V_5 [ V_9 ] = 0x00 ;
V_5 [ V_10 ] = 0x01 ;
V_5 [ V_11 ] = 0x00 ;
V_5 [ V_12 ] = 0x00 ;
V_5 [ V_13 ] = 0x10 ;
V_5 [ V_14 ] = 0x00 ;
V_5 [ V_15 ] = 0x00 ;
V_5 [ V_16 ] = 0x00 ;
V_5 [ V_17 ] = 0x53 ;
V_5 [ V_18 ] = 0x00 ;
V_5 [ V_19 ] = 0x00 ;
V_5 [ V_20 ] = 0x0f ;
V_5 [ V_21 ] = 0x01 ;
V_5 [ V_22 ] = 0x00 ;
V_5 [ V_23 ] = 0x00 ;
V_5 [ V_24 ] = 0x2a ;
V_5 [ V_25 ] = 0x90 ;
V_5 [ V_26 ] = 0x00 ;
V_5 [ V_27 ] = 0x00 ;
V_5 [ V_28 ] = 0x00 ;
V_5 [ V_29 ] = 0x00 ;
V_5 [ V_30 ] = 0x12 ;
V_5 [ V_31 ] = 0x0b ;
V_5 [ V_32 ] = 0x00 ;
V_5 [ V_33 ] = 0x00 ;
V_5 [ V_34 ] = 0x00 ;
V_5 [ V_35 ] = 0x00 ;
V_5 [ V_36 ] = 0x30 ;
V_5 [ V_37 ] = 0x00 ;
V_5 [ V_38 ] = 0x5d ;
V_5 [ V_39 ] = 0x00 ;
V_5 [ V_40 ] = 0x00 ;
V_5 [ V_41 ] = 0xa8 ;
V_5 [ V_42 ] = 0xaa ;
V_5 [ V_43 ] = 0x2a ;
V_5 [ V_44 ] = 0x00 ;
V_5 [ V_45 ] = 0x00 ;
V_5 [ V_46 ] = 0x00 ;
V_5 [ V_47 ] = 0x00 ;
V_5 [ V_48 ] = 0x00 ;
V_5 [ V_49 ] = 0x00 ;
V_5 [ V_50 ] = 0x00 ;
V_5 [ V_51 ] = 0x07 ;
V_5 [ V_52 ] = 0x00 ;
V_5 [ V_53 ] = 0x00 ;
V_5 [ V_54 ] = 0x41 ;
V_5 [ V_55 ] = 0x80 ;
V_5 [ V_56 ] = 0x10 ;
V_5 [ V_57 ] = 0x80 ;
V_5 [ V_58 ] = 0x80 ;
V_5 [ V_59 ] = 0x10 ;
V_5 [ V_60 ] = 0x80 ;
V_5 [ V_61 ] = 0x80 ;
V_5 [ V_62 ] = 0x00 ;
V_5 [ V_63 ] = 0x00 ;
V_5 [ V_64 ] = 0x00 ;
V_5 [ V_65 ] = 0x80 ;
V_5 [ V_66 ] = 0x00 ;
V_5 [ V_67 ] = 0x00 ;
V_5 [ V_68 ] = 0x00 ;
V_5 [ V_69 ] = 0x02 ;
}
static T_1 F_4 ( struct V_2 * V_3 , T_1 V_70 )
{
struct V_71 * V_72 = F_5 ( V_3 ) ;
char V_73 = 0 ;
struct V_74 V_75 [] = {
{
. V_76 = V_72 -> V_76 ,
. V_77 = sizeof( V_70 ) ,
. V_78 = & V_70
} ,
{
. V_76 = V_72 -> V_76 ,
. V_79 = V_80 | V_81 ,
. V_77 = sizeof( V_73 ) ,
. V_78 = & V_73
}
} ;
int V_82 ;
V_82 = F_6 ( V_72 -> V_83 , V_75 , F_7 ( V_75 ) ) ;
if ( V_82 != F_7 ( V_75 ) )
F_8 ( 1 , V_84 , V_3 , L_1 ) ;
return V_73 ;
}
static void F_9 ( struct V_2 * V_3 , T_1 V_70 , T_1 V_73 )
{
struct V_71 * V_72 = F_5 ( V_3 ) ;
struct V_1 * V_85 = F_1 ( V_3 ) ;
char V_86 [] = { V_70 , V_73 } ;
if ( F_10 ( V_72 , V_86 , sizeof( V_86 ) ) != sizeof( V_86 ) )
F_8 ( 1 , V_84 , V_3 , L_2 ) ;
V_85 -> V_87 [ V_70 ] = V_73 ;
}
static void F_11 ( struct V_2 * V_3 , T_1 V_70 , T_1 V_88 , T_1 V_89 )
{
struct V_1 * V_85 = F_1 ( V_3 ) ;
T_1 V_73 = V_85 -> V_87 [ V_70 ] ;
V_73 = ( V_73 & V_88 ) | V_89 ;
F_9 ( V_3 , V_70 , V_73 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_85 = F_1 ( V_3 ) ;
T_1 * V_5 = V_6 ;
int V_90 ;
V_85 -> V_91 = V_92 ;
F_8 ( 1 , V_84 , V_3 , L_3 ) ;
F_13 ( 1 ) ;
for ( V_90 = 1 ; V_90 < 33 ; V_90 ++ )
F_9 ( V_3 , V_90 , V_5 [ V_90 ] ) ;
for ( V_90 = 35 ; V_90 < 40 ; V_90 ++ )
F_9 ( V_3 , V_90 , V_5 [ V_90 ] ) ;
for ( V_90 = 41 ; V_90 < 56 ; V_90 ++ )
F_9 ( V_3 , V_90 , V_5 [ V_90 ] ) ;
for ( V_90 = 58 ; V_90 < 64 ; V_90 ++ )
F_9 ( V_3 , V_90 , V_5 [ V_90 ] ) ;
if ( ( F_4 ( V_3 , V_93 ) & 0x80 ) == 0 ) {
V_85 -> V_91 = V_94 ;
F_8 ( 1 , V_84 , V_3 , L_4 ) ;
return;
}
switch ( F_4 ( V_3 , V_67 ) & 0x0f ) {
case 0 :
F_8 ( 1 , V_84 , V_3 , L_5 ) ;
break;
case 9 :
V_85 -> V_91 = V_95 ;
F_8 ( 1 , V_84 , V_3 , L_6 ) ;
break;
default:
F_8 ( 1 , V_84 , V_3 , L_7 ) ;
break;
}
}
static int F_14 ( struct V_2 * V_3 ,
T_2 V_96 , T_2 V_97 , T_2 V_98 )
{
struct V_1 * V_85 = F_1 ( V_3 ) ;
switch ( V_96 ) {
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
F_8 ( 1 , V_84 , V_3 ,
L_8 , V_96 ) ;
F_11 ( V_3 , V_7 , 0xfc , 0x00 ) ;
F_11 ( V_3 , V_7 , ~ 0x40 , 0x00 ) ;
F_11 ( V_3 , V_8 , 0xb0 , V_96 ) ;
F_11 ( V_3 , V_9 , 0x70 , 0x0a ) ;
F_11 ( V_3 , V_10 , 0x03 , 0x00 ) ;
F_11 ( V_3 , V_53 , 0xcf , 0x00 ) ;
F_11 ( V_3 , V_21 , 0x00 ,
( V_6 [ V_21 ] ) | 0x0c ) ;
F_11 ( V_3 , V_29 , 0x08 , 0x81 ) ;
F_11 ( V_3 , V_31 , 0x0f , 0x90 ) ;
F_11 ( V_3 , V_25 , 0x0f , 0x90 ) ;
F_9 ( V_3 , V_49 , V_6 [ V_49 ] ) ;
F_9 ( V_3 , V_50 , V_6 [ V_50 ] ) ;
F_9 ( V_3 , V_47 , V_6 [ V_47 ] ) ;
F_9 ( V_3 , V_48 , V_6 [ V_48 ] ) ;
break;
case V_105 :
case V_106 :
case V_107 :
F_8 ( 1 , V_84 , V_3 ,
L_9 , V_96 ) ;
F_11 ( V_3 , V_7 , 0xfc , 0x00 ) ;
F_11 ( V_3 , V_7 , ~ 0x40 , 0x00 ) ;
F_11 ( V_3 , V_8 , 0xb0 , V_96 ) ;
F_11 ( V_3 , V_9 , 0x70 , 0x0a ) ;
F_11 ( V_3 , V_10 , 0x03 , 0x00 ) ;
F_11 ( V_3 , V_53 , 0xcf , 0x00 ) ;
F_11 ( V_3 , V_21 , 0x00 ,
V_6 [ V_21 ] ) ;
F_11 ( V_3 , V_29 , 0x08 ,
( V_6 [ V_29 ] & 0xf0 ) | 0x01 ) ;
F_11 ( V_3 , V_31 , 0x0f ,
V_6 [ V_31 ] & 0xf0 ) ;
F_11 ( V_3 , V_25 , 0x0f ,
V_6 [ V_25 ] & 0xf0 ) ;
F_9 ( V_3 , V_49 , V_6 [ V_49 ] ) ;
F_9 ( V_3 , V_50 , V_6 [ V_50 ] ) ;
F_9 ( V_3 , V_47 , V_6 [ V_47 ] ) ;
F_9 ( V_3 , V_48 , V_6 [ V_48 ] ) ;
break;
case V_108 :
F_8 ( 1 , V_84 , V_3 , L_10 ) ;
if ( V_85 -> V_109 & V_110 )
F_11 ( V_3 , V_7 , 0xfc , 0x03 ) ;
else
F_11 ( V_3 , V_7 , 0xfc , 0x02 ) ;
F_11 ( V_3 , V_7 , 0xff , 0x40 ) ;
F_11 ( V_3 , V_8 , 0xb0 , ( V_96 | 0x40 ) ) ;
F_11 ( V_3 , V_9 , 0x70 , 0x87 ) ;
F_11 ( V_3 , V_10 , 0x03 , 0x08 ) ;
F_11 ( V_3 , V_53 , 0xcf , 0x30 ) ;
F_11 ( V_3 , V_21 , 0x00 , 0x71 ) ;
F_11 ( V_3 , V_31 , 0x0f ,
V_6 [ V_31 ] & 0xf0 ) ;
F_11 ( V_3 , V_29 , 0x08 , 0x81 ) ;
F_11 ( V_3 , V_25 , 0x0f ,
V_6 [ V_25 ] & 0xf0 ) ;
F_11 ( V_3 , V_22 , 0x00 , 0x00 ) ;
F_11 ( V_3 , V_23 , 0x00 , 32 ) ;
F_11 ( V_3 , V_27 , 0x00 , 0xe8 ) ;
F_11 ( V_3 , V_28 , 0x00 , 0 ) ;
F_11 ( V_3 , V_49 , 0x00 , 238 ) ;
F_11 ( V_3 , V_50 , 0x00 , 0x00 ) ;
F_11 ( V_3 , V_47 , 0x00 , 0x4f ) ;
F_11 ( V_3 , V_48 , 0x00 , 0x00 ) ;
break;
default:
F_8 ( 1 , V_84 , V_3 ,
L_11 , V_96 ) ;
break;
}
F_9 ( V_3 , V_26 , V_6 [ V_26 ] ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , T_3 V_111 )
{
struct V_1 * V_85 = F_1 ( V_3 ) ;
F_11 ( V_3 , V_26 , 0xf0 , 0x00 ) ;
V_85 -> V_109 = V_111 ;
if ( V_111 & V_112 ) {
F_8 ( 1 , V_84 , V_3 ,
L_12 ) ;
F_11 ( V_3 , V_24 , 0x9f , 0x20 ) ;
} else if ( V_111 & V_113 ) {
F_8 ( 1 , V_84 , V_3 ,
L_13 ) ;
F_11 ( V_3 , V_24 , 0x9f , 0x40 ) ;
} else if ( V_111 & V_114 ) {
F_8 ( 1 , V_84 , V_3 ,
L_14 ) ;
F_11 ( V_3 , V_24 , 0x9f , 0x20 ) ;
} else if ( V_111 & V_115 ) {
F_8 ( 1 , V_84 , V_3 ,
L_15 ) ;
F_11 ( V_3 , V_24 , 0x9f , 0x40 ) ;
} else if ( V_111 & V_116 ) {
F_8 ( 1 , V_84 , V_3 ,
L_16 ) ;
F_11 ( V_3 , V_24 , 0xdf , 0x20 ) ;
F_11 ( V_3 , V_26 , 0xf0 , 0x00 ) ;
F_16 ( V_117 / 10 + 1 ) ;
if ( ! ( F_4 ( V_3 , V_26 ) & 0x40 ) )
F_11 ( V_3 , V_26 , 0xf0 , 0x0f ) ;
} else {
F_8 ( 1 , V_84 , V_3 , L_17 ,
( unsigned long long ) V_111 ) ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , int V_118 )
{
F_8 ( 1 , V_84 , V_3 , L_18 , V_118 ) ;
if ( V_118 ) {
F_11 ( V_3 , V_36 , 0xcf , 0x30 ) ;
F_11 ( V_3 , V_19 , 0x7f , 0x00 ) ;
} else {
F_11 ( V_3 , V_36 , 0xcf , 0x00 ) ;
F_11 ( V_3 , V_19 , 0x7f , 0x80 ) ;
}
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , T_2 * V_119 , T_3 * V_120 )
{
int V_121 = V_122 ;
T_1 V_123 ;
T_3 V_111 = V_124 ;
V_123 = F_4 ( V_3 , V_93 ) ;
if ( ! ( V_123 & 0x20 ) )
V_121 = 0 ;
if ( ! ( V_123 & 0x01 ) )
V_121 |= V_125 ;
if ( ( V_123 & 0x08 ) )
V_111 = V_114 ;
else
V_111 = V_112 ;
if ( V_120 )
* V_120 = V_111 ;
if ( V_119 )
* V_119 = V_121 ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , T_3 * V_111 )
{
F_8 ( 1 , V_84 , V_3 , L_19 ) ;
return F_18 ( V_3 , NULL , V_111 ) ;
}
static int F_20 ( struct V_2 * V_3 , T_2 * V_123 )
{
F_8 ( 1 , V_84 , V_3 , L_20 ) ;
return F_18 ( V_3 , V_123 , NULL ) ;
}
static int F_21 ( struct V_2 * V_3 , struct V_126 * V_127 )
{
struct V_71 * V_72 = F_5 ( V_3 ) ;
struct V_1 * V_85 = F_1 ( V_3 ) ;
return F_22 ( V_72 , V_127 , V_85 -> V_91 , 0 ) ;
}
static int F_23 ( struct V_71 * V_72 , const struct V_128 * V_129 )
{
struct V_1 * V_85 ;
struct V_2 * V_3 ;
F_24 ( V_72 , L_21 ,
V_72 -> V_76 == ( V_130 >> 1 ) ? L_22 : L_23 ,
V_72 -> V_76 << 1 , V_72 -> V_83 -> V_131 ) ;
V_85 = F_25 ( sizeof( * V_85 ) , V_132 ) ;
if ( V_85 == NULL )
return - V_133 ;
V_3 = & V_85 -> V_3 ;
F_26 ( V_3 , V_72 , & V_134 ) ;
F_3 () ;
F_9 ( V_3 , V_7 , 0x2c ) ;
F_27 ( 10 ) ;
F_12 ( V_3 ) ;
return 0 ;
}
static int F_28 ( struct V_71 * V_72 )
{
struct V_2 * V_3 = F_29 ( V_72 ) ;
F_30 ( V_3 ) ;
F_9 ( V_3 , V_36 , 0x20 ) ;
F_9 ( V_3 , V_7 , 0x2c | 0x80 ) ;
F_31 ( F_1 ( V_3 ) ) ;
return 0 ;
}

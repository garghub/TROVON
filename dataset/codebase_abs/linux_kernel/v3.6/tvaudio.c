static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 , int V_5 , int V_6 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
struct V_7 * V_8 = F_4 ( V_3 ) ;
unsigned char V_9 [ 2 ] ;
if ( V_5 < 0 ) {
F_5 ( 1 , V_10 , V_3 , L_1 , V_6 ) ;
V_4 -> V_11 . V_12 [ 1 ] = V_6 ;
V_9 [ 0 ] = V_6 ;
if ( 1 != F_6 ( V_8 , V_9 , 1 ) ) {
F_7 ( V_3 , L_2 , V_6 ) ;
return - 1 ;
}
} else {
if ( V_5 + 1 >= F_8 ( V_4 -> V_11 . V_12 ) ) {
F_9 ( V_3 ,
L_3 ,
V_5 ) ;
return - V_13 ;
}
F_5 ( 1 , V_10 , V_3 , L_4 ,
V_5 , V_6 ) ;
V_4 -> V_11 . V_12 [ V_5 + 1 ] = V_6 ;
V_9 [ 0 ] = V_5 ;
V_9 [ 1 ] = V_6 ;
if ( 2 != F_6 ( V_8 , V_9 , 2 ) ) {
F_7 ( V_3 , L_5 ,
V_5 , V_6 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_10 ( struct V_1 * V_4 ,
int V_5 , int V_6 , int V_14 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
if ( V_14 != 0 ) {
if ( V_5 < 0 ) {
V_6 = ( V_4 -> V_11 . V_12 [ 1 ] & ~ V_14 ) | ( V_6 & V_14 ) ;
} else {
if ( V_5 + 1 >= F_8 ( V_4 -> V_11 . V_12 ) ) {
F_9 ( V_3 ,
L_3 ,
V_5 ) ;
return - V_13 ;
}
V_6 = ( V_4 -> V_11 . V_12 [ V_5 + 1 ] & ~ V_14 ) | ( V_6 & V_14 ) ;
}
}
return F_3 ( V_4 , V_5 , V_6 ) ;
}
static int F_11 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
struct V_7 * V_8 = F_4 ( V_3 ) ;
unsigned char V_9 ;
if ( 1 != F_12 ( V_8 , & V_9 , 1 ) ) {
F_7 ( V_3 , L_6 ) ;
return - 1 ;
}
F_5 ( 1 , V_10 , V_3 , L_7 , V_9 ) ;
return V_9 ;
}
static int F_13 ( struct V_1 * V_4 , int V_5 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
struct V_7 * V_8 = F_4 ( V_3 ) ;
unsigned char V_15 [ 1 ] ;
unsigned char V_16 [ 1 ] ;
struct V_17 V_18 [ 2 ] = {
{ V_8 -> V_19 , 0 , 1 , V_15 } ,
{ V_8 -> V_19 , V_20 , 1 , V_16 }
} ;
V_15 [ 0 ] = V_5 ;
if ( 2 != F_14 ( V_8 -> V_21 , V_18 , 2 ) ) {
F_7 ( V_3 , L_8 ) ;
return - 1 ;
}
F_5 ( 1 , V_10 , V_3 , L_9 ,
V_5 , V_16 [ 0 ] ) ;
return V_16 [ 0 ] ;
}
static int F_15 ( struct V_1 * V_4 , char * V_22 , T_1 * V_23 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
struct V_7 * V_8 = F_4 ( V_3 ) ;
int V_24 ;
if ( 0 == V_23 -> V_25 )
return 0 ;
if ( V_23 -> V_25 + V_23 -> V_12 [ 0 ] - 1 >= F_8 ( V_4 -> V_11 . V_12 ) ) {
F_9 ( V_3 ,
L_10 ,
V_23 -> V_12 [ 0 ] + 1 , V_23 -> V_12 [ 0 ] + V_23 -> V_25 - 1 ) ;
return - V_13 ;
}
F_5 ( 1 , V_10 , V_3 , L_11 ,
V_22 , V_23 -> V_12 [ 0 ] ) ;
for ( V_24 = 1 ; V_24 < V_23 -> V_25 ; V_24 ++ ) {
if ( V_10 )
F_16 ( V_26 L_12 , V_23 -> V_12 [ V_24 ] ) ;
V_4 -> V_11 . V_12 [ V_24 + V_23 -> V_12 [ 0 ] ] = V_23 -> V_12 [ V_24 ] ;
}
if ( V_10 )
F_16 ( V_26 L_13 ) ;
if ( V_23 -> V_25 != F_6 ( V_8 , V_23 -> V_12 , V_23 -> V_25 ) ) {
F_7 ( V_3 , L_14 , V_22 ) ;
return - 1 ;
}
return 0 ;
}
static void F_17 ( unsigned long V_27 )
{
struct V_1 * V_4 = (struct V_1 * ) V_27 ;
F_18 ( V_4 -> V_28 ) ;
}
static int F_19 ( void * V_27 )
{
struct V_1 * V_4 = V_27 ;
struct V_29 * V_30 = V_4 -> V_30 ;
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_31 , V_32 ;
F_5 ( 1 , V_10 , V_3 , L_15 ) ;
F_20 () ;
for (; ; ) {
F_21 ( V_33 ) ;
if ( ! F_22 () )
F_23 () ;
F_21 ( V_34 ) ;
F_24 () ;
if ( F_22 () )
break;
F_5 ( 1 , V_10 , V_3 , L_16 ) ;
if ( V_4 -> V_35 )
continue;
V_31 = V_30 -> V_36 ( V_4 ) ;
if ( V_31 == V_4 -> V_37 )
continue;
F_5 ( 1 , V_10 , V_3 , L_17 ) ;
V_4 -> V_37 = V_31 ;
V_32 = V_38 ;
switch ( V_4 -> V_39 ) {
case V_38 :
if ( V_31 & V_40 )
V_32 = V_41 ;
break;
case V_42 :
case V_41 :
if ( V_31 & V_40 )
V_32 = V_41 ;
else if ( V_31 & V_43 )
V_32 = V_42 ;
break;
case V_44 :
if ( V_31 & V_45 )
V_32 = V_44 ;
else if ( V_31 & V_43 )
V_32 = V_42 ;
break;
case V_46 :
if ( V_31 & V_45 )
V_32 = V_46 ;
else if ( V_31 & V_43 )
V_32 = V_42 ;
}
V_30 -> V_47 ( V_4 , V_32 ) ;
F_25 ( & V_4 -> V_48 , V_49 + F_26 ( 2000 ) ) ;
}
F_5 ( 1 , V_10 , V_3 , L_18 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_6 , V_31 ;
V_6 = F_11 ( V_4 ) ;
V_31 = V_50 ;
if ( V_6 & V_51 )
V_31 |= V_40 | V_45 ;
if ( V_6 & V_52 )
V_31 = V_43 ;
F_5 ( 1 , V_10 , V_3 ,
L_19 ,
V_6 , V_31 ) ;
return V_31 ;
}
static void F_28 ( struct V_1 * V_4 , int V_31 )
{
int V_53 = 1 ;
int V_54 = V_4 -> V_11 . V_12 [ V_55 + 1 ] & ~ 0x7e ;
switch ( V_31 ) {
case V_38 :
V_54 |= V_56 ;
break;
case V_42 :
V_54 |= V_57 ;
break;
case V_41 :
V_54 |= V_58 ;
break;
case V_44 :
V_54 |= V_59 ;
break;
case V_46 :
V_54 |= V_60 ;
break;
default:
V_53 = 0 ;
}
if ( V_53 )
F_3 ( V_4 , V_55 , V_54 ) ;
}
static int F_29 ( struct V_1 * V_4 )
{
int V_61 ;
V_61 = F_11 ( V_4 ) ;
return ( ( V_61 & 0x1f ) == 0 ) ? 1 : 0 ;
}
static int F_30 ( int V_6 ) { return V_6 / 0x2e8 + 0x27 ; }
static int F_31 ( int V_6 ) { return V_6 / 0xccc + 0x06 ; }
static int F_32 ( int V_6 ) { return ( V_6 / 0x1c71 + 0x3 ) << 1 ; }
static int F_33 ( struct V_1 * V_4 )
{
int V_31 , V_6 ;
V_31 = V_50 ;
V_6 = F_11 ( V_4 ) ;
if ( V_6 & V_62 )
V_31 = V_43 ;
if ( V_6 & V_63 )
V_31 |= V_64 ;
return V_31 ;
}
static void F_34 ( struct V_1 * V_4 , int V_31 )
{
int V_53 = 1 ;
int V_65 = V_4 -> V_11 . V_12 [ V_66 + 1 ] & 0x3f ;
switch ( V_31 ) {
case V_38 :
V_65 |= V_67 ;
break;
case V_42 :
case V_41 :
V_65 |= V_68 ;
break;
case V_69 :
V_65 |= V_70 ;
break;
case V_46 :
V_65 |= V_71 ;
break;
default:
V_53 = 0 ;
}
if ( V_53 )
F_3 ( V_4 , V_66 , V_65 ) ;
}
static int F_35 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_6 , V_31 ;
V_6 = F_11 ( V_4 ) ;
V_31 = V_50 ;
if ( V_6 & V_72 )
V_31 = V_43 ;
if ( V_6 & V_73 )
V_31 |= V_40 | V_45 ;
F_5 ( 1 , V_10 , V_3 ,
L_20 ,
V_6 , V_31 ) ;
return V_31 ;
}
static void F_36 ( struct V_1 * V_4 , int V_31 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_74 = V_4 -> V_11 . V_12 [ V_75 + 1 ] & ~ V_76 ;
if ( ( V_74 & V_77 ) != V_78 ) {
F_5 ( 1 , V_10 , V_3 ,
L_21 ) ;
return;
}
F_5 ( 1 , V_10 , V_3 ,
L_22 ,
V_75 + 1 , V_4 -> V_11 . V_12 [ V_75 + 1 ] ) ;
F_5 ( 1 , V_10 , V_3 , L_23 ,
V_74 ) ;
switch ( V_31 ) {
case V_38 :
V_74 |= V_79 ;
break;
case V_42 :
V_74 |= V_80 ;
break;
case V_41 :
V_74 |= V_81 ;
break;
case V_44 :
V_74 |= V_82 ;
break;
case V_46 :
V_74 |= V_83 ;
break;
default:
return;
}
F_3 ( V_4 , V_75 , V_74 ) ;
F_5 ( 1 , V_10 , V_3 ,
L_24 ,
V_31 , V_74 ) ;
}
static int F_37 ( struct V_1 * V_4 )
{
int V_61 ;
if ( - 1 == ( V_61 = F_13 ( V_4 , 254 ) ) )
return 0 ;
return ( V_61 & ~ 0x1f ) == 0x80 ;
}
static int F_38 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
F_3 ( V_4 , V_84 , 0x00 ) ;
F_3 ( V_4 , V_85 , V_86 ) ;
F_3 ( V_4 , V_87 , ( V_88 ) ? 0x03 : 0x02 ) ;
if( V_89 == 0x11 ) {
F_3 ( V_4 , V_90 , 0x80 ) ;
} else {
F_15 ( V_4 , L_25 , & V_91 [ V_92 ] . V_23 ) ;
F_3 ( V_4 , V_90 , 0x00 ) ;
}
F_3 ( V_4 , V_93 , 0x00 ) ;
F_3 ( V_4 , V_94 , 0x00 ) ;
F_3 ( V_4 , V_95 , V_96 ) ;
F_3 ( V_4 , V_97 , 0x00 ) ;
F_3 ( V_4 , V_98 , 0x14 ) ;
F_3 ( V_4 , V_99 , 0x50 ) ;
if( V_89 == 0x11 ) {
F_3 ( V_4 , V_100 , 0xf9 ) ;
F_3 ( V_4 , V_101 , ( V_88 ) ? 0x81 : 0x80 ) ;
F_3 ( V_4 , V_102 , 0x80 ) ;
F_3 ( V_4 , V_103 , ( V_88 ) ? 0x82 : 0x80 ) ;
F_3 ( V_4 , V_104 , V_105 ) ;
} else {
F_3 ( V_4 , V_100 , 0xfb ) ;
F_3 ( V_4 , V_101 , ( V_88 ) ? 0x81 : 0x80 ) ;
F_3 ( V_4 , V_102 , 0x00 ) ;
}
F_5 ( 1 , V_10 , V_3 , L_26 ,
V_91 [ V_92 ] . V_22 , V_92 ) ;
return 1 ;
}
static int F_39 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_106 , V_107 , V_31 ;
int V_108 ;
V_31 = V_50 ;
if( - 1 == ( V_106 = F_13 ( V_4 , V_109 ) ) )
return V_31 ;
if( - 1 == ( V_107 = F_13 ( V_4 , V_110 ) ) )
return V_31 ;
if( - 1 == ( V_108 = F_13 ( V_4 , V_111 ) ) )
return V_31 ;
V_4 -> V_11 . V_12 [ V_112 - 2 ] = V_106 ;
V_4 -> V_11 . V_12 [ V_112 - 1 ] = V_107 ;
if( V_88 ) {
if( V_107 & 0x02 )
V_31 = V_43 ;
if( V_107 & 0x01 )
V_31 |= V_40 | V_45 ;
} else {
if( V_106 & 0x02 )
V_31 = V_43 ;
if( V_106 & 0x04 )
V_31 |= V_40 | V_45 ;
}
F_5 ( 1 , V_10 , V_3 ,
L_27 ,
V_106 , V_107 , V_108 , V_31 ) ;
return V_31 ;
}
static void F_40 ( struct V_1 * V_4 , int V_31 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
if ( V_88 ) {
if( V_4 -> V_11 . V_12 [ V_112 - 2 ] & 0x20 )
V_96 &= 0xfe ;
else
V_96 |= 0x01 ;
F_3 ( V_4 , V_95 , V_96 ) ;
}
if( V_89 == 0x11 ) {
int V_113 = 0x80 ;
int V_114 = ( V_88 ) ? 0x82 : 0x80 ;
switch( V_31 ) {
case V_38 :
case V_42 :
break;
case V_41 :
V_113 = 0x80 ;
V_114 = ( V_88 ) ? 0x82 : 0x80 ;
break;
case V_44 :
V_113 = 0xa0 ;
V_114 = ( V_88 ) ? 0x83 : 0x81 ;
break;
case V_46 :
V_113 = 0x00 ;
V_114 = ( V_88 ) ? 0x82 : 0x80 ;
break;
default:
return;
}
F_3 ( V_4 , V_102 , V_113 ) ;
F_3 ( V_4 , V_103 , V_114 ) ;
F_5 ( 1 , V_10 , V_3 ,
L_28 ,
V_31 , V_113 , V_114 ) ;
} else {
int V_115 , V_113 ;
switch( V_31 ) {
case V_38 :
V_115 = 0x00 ;
V_113 = 0x10 ;
break;
case V_42 :
if( V_88 ) {
V_115 = 0x00 ;
V_113 = 0x00 ;
} else {
V_115 = ( V_105 == 1 ) ? 0x05 : 0x04 ;
V_113 = 0x00 ;
}
break;
case V_41 :
V_115 = 0x02 ;
V_113 = 0x10 ;
break;
case V_44 :
V_115 = 0x02 ;
V_113 = 0x20 ;
break;
case V_46 :
V_115 = 0x02 ;
V_113 = 0x00 ;
break;
default:
return;
}
F_3 ( V_4 , V_90 , V_115 ) ;
F_3 ( V_4 , V_102 , V_113 ) ;
F_5 ( 1 , V_10 , V_3 ,
L_29 ,
V_31 , V_115 , V_113 ) ;
}
}
static int F_41 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_116 , V_117 ;
if( - 1 == ( V_116 = F_13 ( V_4 , V_118 ) ) )
return 0 ;
if( - 1 == ( V_117 = F_13 ( V_4 , V_119 ) ) )
return 0 ;
F_5 ( 1 , V_10 , V_3 , L_30 , V_116 , V_117 ) ;
if( ( V_116 == 0x11 ) || ( V_116 == 0x07 ) ) {
F_9 ( V_3 , L_31 , ( V_116 == 0x11 ) ? L_32 : L_33 ) ;
V_89 = V_116 ;
return 1 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_4 )
{
if ( V_120 > 2 )
V_120 = 1 ;
if ( V_92 >= F_8 ( V_91 ) )
V_92 = 0 ;
if( V_121 > 1 )
V_121 = 0 ;
if( V_120 == 1 )
V_86 = 0xc0 ;
else
V_86 = 0xc1 ;
V_105 = V_92 ;
V_88 = ( V_92 < 5 ) ? 0 : 1 ;
if( V_121 == 0 )
V_96 = 0x01 ;
else
V_96 = 0x05 ;
F_38 ( V_4 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_4 )
{
F_3 ( V_4 , V_122 , 0xd0 ) ;
F_3 ( V_4 , V_123 , 0x03 ) ;
F_3 ( V_4 , V_124 , 0x00 ) ;
F_3 ( V_4 , V_125 , 0x00 ) ;
F_3 ( V_4 , V_126 , 0x00 ) ;
F_3 ( V_4 , V_127 , 0x00 ) ;
F_3 ( V_4 , V_128 , 0x00 ) ;
F_3 ( V_4 , V_129 , 0x00 ) ;
F_3 ( V_4 , V_130 , 0x00 ) ;
F_3 ( V_4 , V_131 , 0x44 ) ;
F_3 ( V_4 , V_132 , 0x00 ) ;
F_3 ( V_4 , V_133 , 0x00 ) ;
F_3 ( V_4 , V_134 , 0x01 ) ;
F_3 ( V_4 , V_135 , 0x10 ) ;
F_3 ( V_4 , V_136 , 0x10 ) ;
F_3 ( V_4 , V_137 , 0x02 ) ;
F_3 ( V_4 , V_138 , 0x6f ) ;
F_3 ( V_4 , V_139 , 0x00 ) ;
F_3 ( V_4 , V_140 , 0x00 ) ;
F_3 ( V_4 , V_141 , 0x44 ) ;
F_3 ( V_4 , V_142 , 0x03 ) ;
F_3 ( V_4 , V_143 , 0x03 ) ;
F_3 ( V_4 , V_144 , 0x00 ) ;
F_3 ( V_4 , V_145 , 0x00 ) ;
F_3 ( V_4 , V_146 , 0x44 ) ;
F_3 ( V_4 , V_147 , 0x00 ) ;
F_3 ( V_4 , V_148 , 0x00 ) ;
F_3 ( V_4 , V_149 , 0x00 ) ;
F_3 ( V_4 , V_150 , 0x00 ) ;
F_3 ( V_4 , V_151 , 0xcc ) ;
return 0 ;
}
static int F_44 ( int V_6 ) { return ( unsigned char ) ( V_6 / 602 - 84 ) ; }
static int F_45 ( int V_6 ) { return ( unsigned char ) ( F_46 ( - 12 , V_6 / 2115 - 15 ) ) ; }
static int F_47 ( int V_6 ) { return ( unsigned char ) ( V_6 / 2622 - 12 ) ; }
static int F_48 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_116 , V_152 ;
V_116 = F_13 ( V_4 , 254 ) ;
V_152 = F_13 ( V_4 , 255 ) ;
if ( V_116 == 0 || V_116 == 2 ) {
F_9 ( V_3 , L_34 ,
V_116 == 0 ? L_35 : L_36 , V_152 ) ;
return 1 ;
}
return 0 ;
}
static int F_49 ( int V_6 ) { return V_6 >> 10 ; }
static int F_50 ( int V_6 ) { return V_6 >> 12 ; }
static int F_51 ( int V_6 ) { return ( V_6 / ( 65535 / ( 63 - 12 ) ) + 12 ) & 0x3f ; }
static int F_52 ( int V_6 ) { return V_6 >> 11 ; }
static int F_53 ( struct V_1 * V_4 )
{
F_3 ( V_4 , V_153 , 0x3f ) ;
F_3 ( V_4 , V_154 , 0x3f ) ;
F_3 ( V_4 , V_155 , 0x3f ) ;
F_3 ( V_4 , V_156 , 0x3f ) ;
return 0 ;
}
static int F_54 ( int V_6 ) { return ( V_6 >> 10 ) | 0xc0 ; }
static int F_55 ( int V_6 ) { return ( V_6 >> 12 ) | 0xf0 ; }
static void F_56 ( struct V_1 * V_4 , int V_31 )
{
int V_157 = V_4 -> V_11 . V_12 [ V_158 + 1 ] & 0xe1 ;
switch ( V_31 ) {
case V_41 :
V_157 |= V_159 ;
V_157 |= V_160 ;
break;
case V_44 :
V_157 |= V_161 ;
V_157 |= V_160 ;
break;
case V_46 :
V_157 |= V_162 ;
V_157 |= V_163 ;
break;
case V_38 :
V_157 |= V_162 ;
V_157 |= V_164 ;
break;
case V_42 :
V_157 |= V_162 ;
V_157 |= V_165 ;
break;
default:
return;
}
F_3 ( V_4 , V_158 , V_157 ) ;
}
static int F_57 ( struct V_1 * V_4 )
{
int V_6 , V_31 ;
V_6 = F_11 ( V_4 ) ;
V_31 = V_50 ;
if ( V_6 & V_166 ) {
V_31 |= V_40 | V_45 ;
} else if ( ! ( V_6 & V_167 ) ) {
V_31 = V_43 ;
}
return V_31 ;
}
static void F_58 ( struct V_1 * V_4 , int V_31 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_53 = 1 ;
T_1 * V_54 = NULL ;
F_5 ( 1 , V_10 , V_3 , L_37 , V_31 ) ;
switch( V_31 ) {
case V_38 :
V_54 = & V_168 ;
break;
case V_42 :
V_54 = & V_169 ;
break;
case V_41 :
V_54 = & V_170 ;
break;
case V_44 :
V_54 = & V_171 ;
break;
case V_46 :
V_54 = & V_172 ;
break;
default:
V_53 = 0 ;
}
if( V_53 )
F_15 ( V_4 , L_38 , V_54 ) ;
}
static int F_59 ( struct V_1 * V_4 )
{
int V_61 ;
V_61 = F_11 ( V_4 ) ;
return ( ( V_61 & 0x1f ) == 0x1f ) ? 1 : 0 ;
}
static int F_60 ( struct V_2 * V_3 ,
struct V_173 * V_174 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_4 -> V_30 ;
switch ( V_174 -> V_175 ) {
case V_176 :
if ( ! ( V_30 -> V_177 & V_178 ) )
break;
V_174 -> V_179 = V_4 -> V_180 ;
return 0 ;
case V_181 :
if ( ! ( V_30 -> V_177 & V_182 ) )
break;
V_174 -> V_179 = F_46 ( V_4 -> V_183 , V_4 -> V_184 ) ;
return 0 ;
case V_185 :
{
int V_186 ;
if ( ! ( V_30 -> V_177 & V_182 ) )
break;
V_186 = F_46 ( V_4 -> V_183 , V_4 -> V_184 ) ;
if ( V_186 )
V_174 -> V_179 = ( 32768 * F_61 ( V_4 -> V_183 , V_4 -> V_184 ) ) / V_186 ;
else
V_174 -> V_179 = 32768 ;
return 0 ;
}
case V_187 :
if ( ! ( V_30 -> V_177 & V_188 ) )
break;
V_174 -> V_179 = V_4 -> V_189 ;
return 0 ;
case V_190 :
if ( ! ( V_30 -> V_177 & V_188 ) )
break;
V_174 -> V_179 = V_4 -> V_191 ;
return 0 ;
}
return - V_13 ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_173 * V_174 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_4 -> V_30 ;
switch ( V_174 -> V_175 ) {
case V_176 :
if ( ! ( V_30 -> V_177 & V_178 ) )
break;
if ( V_174 -> V_179 < 0 || V_174 -> V_179 >= 2 )
return - V_192 ;
V_4 -> V_180 = V_174 -> V_179 ;
if ( V_4 -> V_180 )
F_10 ( V_4 , V_30 -> V_193 , V_30 -> V_194 , V_30 -> V_195 ) ;
else
F_10 ( V_4 , V_30 -> V_193 ,
V_30 -> V_196 [ V_4 -> V_197 ] , V_30 -> V_195 ) ;
return 0 ;
case V_181 :
{
int V_186 , V_198 ;
if ( ! ( V_30 -> V_177 & V_182 ) )
break;
V_186 = F_46 ( V_4 -> V_183 , V_4 -> V_184 ) ;
if ( V_186 )
V_198 = ( 32768 * F_61 ( V_4 -> V_183 , V_4 -> V_184 ) ) / V_186 ;
else
V_198 = 32768 ;
V_186 = V_174 -> V_179 ;
V_4 -> V_183 = ( F_61 ( 65536 - V_198 , 32768 ) * V_186 ) / 32768 ;
V_4 -> V_184 = ( F_61 ( V_198 , V_186 * ( V_199 ) 32768 ) ) / 32768 ;
F_3 ( V_4 , V_30 -> V_200 , V_30 -> V_201 ( V_4 -> V_183 ) ) ;
F_3 ( V_4 , V_30 -> V_202 , V_30 -> V_201 ( V_4 -> V_184 ) ) ;
return 0 ;
}
case V_185 :
{
int V_186 , V_198 ;
if ( ! ( V_30 -> V_177 & V_182 ) )
break;
V_186 = F_46 ( V_4 -> V_183 , V_4 -> V_184 ) ;
V_198 = V_174 -> V_179 ;
V_4 -> V_183 = ( F_61 ( 65536 - V_198 , 32768 ) * V_186 ) / 32768 ;
V_4 -> V_184 = ( F_61 ( V_198 , V_186 * ( V_199 ) 32768 ) ) / 32768 ;
F_3 ( V_4 , V_30 -> V_200 , V_30 -> V_201 ( V_4 -> V_183 ) ) ;
F_3 ( V_4 , V_30 -> V_202 , V_30 -> V_201 ( V_4 -> V_184 ) ) ;
return 0 ;
}
case V_187 :
if ( ! ( V_30 -> V_177 & V_188 ) )
break;
V_4 -> V_189 = V_174 -> V_179 ;
F_3 ( V_4 , V_30 -> V_203 , V_30 -> V_204 ( V_4 -> V_189 ) ) ;
return 0 ;
case V_190 :
if ( ! ( V_30 -> V_177 & V_188 ) )
break;
V_4 -> V_191 = V_174 -> V_179 ;
F_3 ( V_4 , V_30 -> V_205 , V_30 -> V_206 ( V_4 -> V_191 ) ) ;
return 0 ;
}
return - V_13 ;
}
static int F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_35 = 1 ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 , struct V_207 * V_208 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_4 -> V_30 ;
switch ( V_208 -> V_175 ) {
case V_176 :
if ( V_30 -> V_177 & V_178 )
return F_65 ( V_208 , 0 , 1 , 1 , 0 ) ;
break;
case V_181 :
if ( V_30 -> V_177 & V_182 )
return F_65 ( V_208 , 0 , 65535 , 65535 / 100 , 58880 ) ;
break;
case V_185 :
if ( V_30 -> V_177 & V_182 )
return F_65 ( V_208 , 0 , 65535 , 65535 / 100 , 32768 ) ;
break;
case V_187 :
case V_190 :
if ( V_30 -> V_177 & V_188 )
return F_65 ( V_208 , 0 , 65535 , 65535 / 100 , 32768 ) ;
break;
default:
break;
}
return - V_13 ;
}
static int F_66 ( struct V_2 * V_3 ,
T_2 V_197 , T_2 V_209 , T_2 V_210 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_4 -> V_30 ;
if ( ! ( V_30 -> V_177 & V_178 ) )
return 0 ;
if ( V_197 >= 4 )
return - V_13 ;
V_4 -> V_197 = V_197 ;
if ( V_4 -> V_180 )
return 0 ;
F_10 ( V_4 , V_30 -> V_193 ,
V_30 -> V_196 [ V_4 -> V_197 ] , V_30 -> V_195 ) ;
return 0 ;
}
static int F_67 ( struct V_2 * V_3 , struct V_211 * V_212 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_4 -> V_30 ;
if ( ! V_30 -> V_47 )
return 0 ;
if ( V_4 -> V_35 )
return 0 ;
switch ( V_212 -> V_39 ) {
case V_38 :
case V_42 :
case V_41 :
case V_44 :
case V_46 :
break;
default:
return - V_13 ;
}
V_4 -> V_39 = V_212 -> V_39 ;
if ( V_4 -> V_28 )
F_18 ( V_4 -> V_28 ) ;
else
V_30 -> V_47 ( V_4 , V_212 -> V_39 ) ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 , struct V_211 * V_212 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_4 -> V_30 ;
if ( ! V_30 -> V_36 )
return 0 ;
if ( V_4 -> V_35 )
return 0 ;
V_212 -> V_39 = V_4 -> V_39 ;
V_212 -> V_213 = V_30 -> V_36 ( V_4 ) ;
V_212 -> V_214 = V_215 |
V_216 | V_217 ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 , T_3 V_218 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_35 = 0 ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 , struct V_219 * V_220 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_4 -> V_30 ;
if ( V_4 -> V_28 ) {
V_30 -> V_47 ( V_4 , V_38 ) ;
V_4 -> V_37 = - 1 ;
F_25 ( & V_4 -> V_48 , V_49 + F_26 ( 2000 ) ) ;
}
return 0 ;
}
static int F_71 ( struct V_2 * V_3 , struct V_221 * V_4 )
{
struct V_7 * V_222 = F_4 ( V_3 ) ;
return F_72 ( V_222 , V_4 , V_223 , 0 ) ;
}
static int F_73 ( struct V_7 * V_222 , const struct V_224 * V_175 )
{
struct V_1 * V_4 ;
struct V_29 * V_30 ;
struct V_2 * V_3 ;
if ( V_10 ) {
F_16 ( V_225 L_39 ) ;
F_16 ( V_225 L_40 ) ;
for ( V_30 = V_226 ; V_30 -> V_22 != NULL ; V_30 ++ )
F_16 ( L_41 , ( V_30 == V_226 ) ? L_35 : L_42 , V_30 -> V_22 ) ;
F_16 ( L_13 ) ;
}
V_4 = F_74 ( sizeof( * V_4 ) , V_227 ) ;
if ( ! V_4 )
return - V_228 ;
V_3 = & V_4 -> V_3 ;
F_75 ( V_3 , V_222 , & V_229 ) ;
F_5 ( 1 , V_10 , V_3 , L_43 , V_222 -> V_19 << 1 ) ;
for ( V_30 = V_226 ; V_30 -> V_22 != NULL ; V_30 ++ ) {
if ( 0 == * ( V_30 -> V_230 ) )
continue;
if ( V_222 -> V_19 < V_30 -> V_231 ||
V_222 -> V_19 > V_30 -> V_232 )
continue;
if ( V_30 -> V_233 && ! V_30 -> V_233 ( V_4 ) )
continue;
break;
}
if ( V_30 -> V_22 == NULL ) {
F_5 ( 1 , V_10 , V_3 , L_44 ) ;
F_76 ( V_4 ) ;
return - V_234 ;
}
F_9 ( V_3 , L_45 , V_30 -> V_22 , V_222 -> V_19 << 1 , V_222 -> V_21 -> V_22 ) ;
if ( V_30 -> V_177 ) {
F_5 ( 1 , V_10 , V_3 , L_46 ,
( V_30 -> V_177 & V_182 ) ? L_47 : L_35 ,
( V_30 -> V_177 & V_188 ) ? L_48 : L_35 ,
( V_30 -> V_177 & V_178 ) ? L_49 : L_35 ) ;
}
if ( ! V_175 )
F_77 ( V_222 -> V_22 , V_30 -> V_22 , V_235 ) ;
V_4 -> V_30 = V_30 ;
V_4 -> V_11 . V_25 = V_30 -> V_236 + 1 ;
V_4 -> V_37 = - 1 ;
V_4 -> V_39 = V_41 ;
if ( V_30 -> V_237 != NULL )
V_30 -> V_237 ( V_4 ) ;
else
F_15 ( V_4 , L_50 , & V_30 -> V_238 ) ;
if ( V_30 -> V_177 & V_182 ) {
if ( ! V_30 -> V_201 ) {
F_9 ( V_3 , L_51 ) ;
V_30 -> V_177 &= ~ V_182 ;
} else {
V_4 -> V_183 = V_30 -> V_239 ? V_30 -> V_239 : 65535 ;
V_4 -> V_184 = V_30 -> V_240 ? V_30 -> V_240 : 65535 ;
F_3 ( V_4 , V_30 -> V_200 ,
V_30 -> V_201 ( V_4 -> V_183 ) ) ;
F_3 ( V_4 , V_30 -> V_202 ,
V_30 -> V_201 ( V_4 -> V_184 ) ) ;
}
}
if ( V_30 -> V_177 & V_188 ) {
if ( ! V_30 -> V_204 || ! V_30 -> V_206 ) {
F_9 ( V_3 , L_52 ) ;
V_30 -> V_177 &= ~ V_188 ;
} else {
V_4 -> V_191 = V_30 -> V_241 ?
V_30 -> V_241 : 32768 ;
V_4 -> V_189 = V_30 -> V_242 ?
V_30 -> V_242 : 32768 ;
F_3 ( V_4 , V_30 -> V_203 ,
V_30 -> V_204 ( V_4 -> V_189 ) ) ;
F_3 ( V_4 , V_30 -> V_205 ,
V_30 -> V_206 ( V_4 -> V_191 ) ) ;
}
}
V_4 -> V_28 = NULL ;
F_78 ( & V_4 -> V_48 ) ;
if ( V_30 -> V_177 & V_243 ) {
if ( ! V_30 -> V_36 || ! V_30 -> V_47 ) {
F_9 ( V_3 , L_53 ) ;
return 0 ;
}
V_4 -> V_48 . V_244 = F_17 ;
V_4 -> V_48 . V_27 = ( unsigned long ) V_4 ;
V_4 -> V_28 = F_79 ( F_19 , V_4 , V_222 -> V_22 ) ;
if ( F_80 ( V_4 -> V_28 ) ) {
F_7 ( V_3 , L_54 ) ;
V_4 -> V_28 = NULL ;
}
}
return 0 ;
}
static int F_81 ( struct V_7 * V_222 )
{
struct V_2 * V_3 = F_82 ( V_222 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_83 ( & V_4 -> V_48 ) ;
if ( V_4 -> V_28 ) {
F_84 ( V_4 -> V_28 ) ;
V_4 -> V_28 = NULL ;
}
F_85 ( V_3 ) ;
F_76 ( V_4 ) ;
return 0 ;
}

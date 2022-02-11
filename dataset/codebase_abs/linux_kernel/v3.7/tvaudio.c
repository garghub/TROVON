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
{
. V_19 = V_8 -> V_19 ,
. V_20 = 1 ,
. V_21 = V_15
} ,
{
. V_19 = V_8 -> V_19 ,
. V_22 = V_23 ,
. V_20 = 1 ,
. V_21 = V_16
}
} ;
V_15 [ 0 ] = V_5 ;
if ( 2 != F_14 ( V_8 -> V_24 , V_18 , 2 ) ) {
F_7 ( V_3 , L_8 ) ;
return - 1 ;
}
F_5 ( 1 , V_10 , V_3 , L_9 ,
V_5 , V_16 [ 0 ] ) ;
return V_16 [ 0 ] ;
}
static int F_15 ( struct V_1 * V_4 , char * V_25 , T_1 * V_26 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
struct V_7 * V_8 = F_4 ( V_3 ) ;
int V_27 ;
if ( 0 == V_26 -> V_28 )
return 0 ;
if ( V_26 -> V_28 + V_26 -> V_12 [ 0 ] - 1 >= F_8 ( V_4 -> V_11 . V_12 ) ) {
F_9 ( V_3 ,
L_10 ,
V_26 -> V_12 [ 0 ] + 1 , V_26 -> V_12 [ 0 ] + V_26 -> V_28 - 1 ) ;
return - V_13 ;
}
F_5 ( 1 , V_10 , V_3 , L_11 ,
V_25 , V_26 -> V_12 [ 0 ] ) ;
for ( V_27 = 1 ; V_27 < V_26 -> V_28 ; V_27 ++ ) {
if ( V_10 )
F_16 ( V_29 L_12 , V_26 -> V_12 [ V_27 ] ) ;
V_4 -> V_11 . V_12 [ V_27 + V_26 -> V_12 [ 0 ] ] = V_26 -> V_12 [ V_27 ] ;
}
if ( V_10 )
F_16 ( V_29 L_13 ) ;
if ( V_26 -> V_28 != F_6 ( V_8 , V_26 -> V_12 , V_26 -> V_28 ) ) {
F_7 ( V_3 , L_14 , V_25 ) ;
return - 1 ;
}
return 0 ;
}
static void F_17 ( unsigned long V_30 )
{
struct V_1 * V_4 = (struct V_1 * ) V_30 ;
F_18 ( V_4 -> V_31 ) ;
}
static int F_19 ( void * V_30 )
{
struct V_1 * V_4 = V_30 ;
struct V_32 * V_33 = V_4 -> V_33 ;
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_34 , V_35 ;
F_5 ( 1 , V_10 , V_3 , L_15 ) ;
F_20 () ;
for (; ; ) {
F_21 ( V_36 ) ;
if ( ! F_22 () )
F_23 () ;
F_21 ( V_37 ) ;
F_24 () ;
if ( F_22 () )
break;
F_5 ( 1 , V_10 , V_3 , L_16 ) ;
if ( V_4 -> V_38 )
continue;
V_34 = V_33 -> V_39 ( V_4 ) ;
if ( V_34 == V_4 -> V_40 )
continue;
F_5 ( 1 , V_10 , V_3 , L_17 ) ;
V_4 -> V_40 = V_34 ;
V_35 = V_41 ;
switch ( V_4 -> V_42 ) {
case V_41 :
if ( V_34 & V_43 )
V_35 = V_44 ;
break;
case V_45 :
case V_44 :
if ( V_34 & V_43 )
V_35 = V_44 ;
else if ( V_34 & V_46 )
V_35 = V_45 ;
break;
case V_47 :
if ( V_34 & V_48 )
V_35 = V_47 ;
else if ( V_34 & V_46 )
V_35 = V_45 ;
break;
case V_49 :
if ( V_34 & V_48 )
V_35 = V_49 ;
else if ( V_34 & V_46 )
V_35 = V_45 ;
}
V_33 -> V_50 ( V_4 , V_35 ) ;
F_25 ( & V_4 -> V_51 , V_52 + F_26 ( 2000 ) ) ;
}
F_5 ( 1 , V_10 , V_3 , L_18 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_6 , V_34 ;
V_6 = F_11 ( V_4 ) ;
V_34 = V_53 ;
if ( V_6 & V_54 )
V_34 |= V_43 | V_48 ;
if ( V_6 & V_55 )
V_34 = V_46 ;
F_5 ( 1 , V_10 , V_3 ,
L_19 ,
V_6 , V_34 ) ;
return V_34 ;
}
static void F_28 ( struct V_1 * V_4 , int V_34 )
{
int V_56 = 1 ;
int V_57 = V_4 -> V_11 . V_12 [ V_58 + 1 ] & ~ 0x7e ;
switch ( V_34 ) {
case V_41 :
V_57 |= V_59 ;
break;
case V_45 :
V_57 |= V_60 ;
break;
case V_44 :
V_57 |= V_61 ;
break;
case V_47 :
V_57 |= V_62 ;
break;
case V_49 :
V_57 |= V_63 ;
break;
default:
V_56 = 0 ;
}
if ( V_56 )
F_3 ( V_4 , V_58 , V_57 ) ;
}
static int F_29 ( struct V_1 * V_4 )
{
int V_64 ;
V_64 = F_11 ( V_4 ) ;
return ( ( V_64 & 0x1f ) == 0 ) ? 1 : 0 ;
}
static int F_30 ( int V_6 ) { return V_6 / 0x2e8 + 0x27 ; }
static int F_31 ( int V_6 ) { return V_6 / 0xccc + 0x06 ; }
static int F_32 ( int V_6 ) { return ( V_6 / 0x1c71 + 0x3 ) << 1 ; }
static int F_33 ( struct V_1 * V_4 )
{
int V_34 , V_6 ;
V_34 = V_53 ;
V_6 = F_11 ( V_4 ) ;
if ( V_6 & V_65 )
V_34 = V_46 ;
if ( V_6 & V_66 )
V_34 |= V_67 ;
return V_34 ;
}
static void F_34 ( struct V_1 * V_4 , int V_34 )
{
int V_56 = 1 ;
int V_68 = V_4 -> V_11 . V_12 [ V_69 + 1 ] & 0x3f ;
switch ( V_34 ) {
case V_41 :
V_68 |= V_70 ;
break;
case V_45 :
case V_44 :
V_68 |= V_71 ;
break;
case V_72 :
V_68 |= V_73 ;
break;
case V_49 :
V_68 |= V_74 ;
break;
default:
V_56 = 0 ;
}
if ( V_56 )
F_3 ( V_4 , V_69 , V_68 ) ;
}
static int F_35 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_6 , V_34 ;
V_6 = F_11 ( V_4 ) ;
V_34 = V_53 ;
if ( V_6 & V_75 )
V_34 = V_46 ;
if ( V_6 & V_76 )
V_34 |= V_43 | V_48 ;
F_5 ( 1 , V_10 , V_3 ,
L_20 ,
V_6 , V_34 ) ;
return V_34 ;
}
static void F_36 ( struct V_1 * V_4 , int V_34 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_77 = V_4 -> V_11 . V_12 [ V_78 + 1 ] & ~ V_79 ;
if ( ( V_77 & V_80 ) != V_81 ) {
F_5 ( 1 , V_10 , V_3 ,
L_21 ) ;
return;
}
F_5 ( 1 , V_10 , V_3 ,
L_22 ,
V_78 + 1 , V_4 -> V_11 . V_12 [ V_78 + 1 ] ) ;
F_5 ( 1 , V_10 , V_3 , L_23 ,
V_77 ) ;
switch ( V_34 ) {
case V_41 :
V_77 |= V_82 ;
break;
case V_45 :
V_77 |= V_83 ;
break;
case V_44 :
V_77 |= V_84 ;
break;
case V_47 :
V_77 |= V_85 ;
break;
case V_49 :
V_77 |= V_86 ;
break;
default:
return;
}
F_3 ( V_4 , V_78 , V_77 ) ;
F_5 ( 1 , V_10 , V_3 ,
L_24 ,
V_34 , V_77 ) ;
}
static int F_37 ( struct V_1 * V_4 )
{
int V_64 ;
if ( - 1 == ( V_64 = F_13 ( V_4 , 254 ) ) )
return 0 ;
return ( V_64 & ~ 0x1f ) == 0x80 ;
}
static int F_38 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
F_3 ( V_4 , V_87 , 0x00 ) ;
F_3 ( V_4 , V_88 , V_89 ) ;
F_3 ( V_4 , V_90 , ( V_91 ) ? 0x03 : 0x02 ) ;
if( V_92 == 0x11 ) {
F_3 ( V_4 , V_93 , 0x80 ) ;
} else {
F_15 ( V_4 , L_25 , & V_94 [ V_95 ] . V_26 ) ;
F_3 ( V_4 , V_93 , 0x00 ) ;
}
F_3 ( V_4 , V_96 , 0x00 ) ;
F_3 ( V_4 , V_97 , 0x00 ) ;
F_3 ( V_4 , V_98 , V_99 ) ;
F_3 ( V_4 , V_100 , 0x00 ) ;
F_3 ( V_4 , V_101 , 0x14 ) ;
F_3 ( V_4 , V_102 , 0x50 ) ;
if( V_92 == 0x11 ) {
F_3 ( V_4 , V_103 , 0xf9 ) ;
F_3 ( V_4 , V_104 , ( V_91 ) ? 0x81 : 0x80 ) ;
F_3 ( V_4 , V_105 , 0x80 ) ;
F_3 ( V_4 , V_106 , ( V_91 ) ? 0x82 : 0x80 ) ;
F_3 ( V_4 , V_107 , V_108 ) ;
} else {
F_3 ( V_4 , V_103 , 0xfb ) ;
F_3 ( V_4 , V_104 , ( V_91 ) ? 0x81 : 0x80 ) ;
F_3 ( V_4 , V_105 , 0x00 ) ;
}
F_5 ( 1 , V_10 , V_3 , L_26 ,
V_94 [ V_95 ] . V_25 , V_95 ) ;
return 1 ;
}
static int F_39 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_109 , V_110 , V_34 ;
int V_111 ;
V_34 = V_53 ;
if( - 1 == ( V_109 = F_13 ( V_4 , V_112 ) ) )
return V_34 ;
if( - 1 == ( V_110 = F_13 ( V_4 , V_113 ) ) )
return V_34 ;
if( - 1 == ( V_111 = F_13 ( V_4 , V_114 ) ) )
return V_34 ;
V_4 -> V_11 . V_12 [ V_115 - 2 ] = V_109 ;
V_4 -> V_11 . V_12 [ V_115 - 1 ] = V_110 ;
if( V_91 ) {
if( V_110 & 0x02 )
V_34 = V_46 ;
if( V_110 & 0x01 )
V_34 |= V_43 | V_48 ;
} else {
if( V_109 & 0x02 )
V_34 = V_46 ;
if( V_109 & 0x04 )
V_34 |= V_43 | V_48 ;
}
F_5 ( 1 , V_10 , V_3 ,
L_27 ,
V_109 , V_110 , V_111 , V_34 ) ;
return V_34 ;
}
static void F_40 ( struct V_1 * V_4 , int V_34 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
if ( V_91 ) {
if( V_4 -> V_11 . V_12 [ V_115 - 2 ] & 0x20 )
V_99 &= 0xfe ;
else
V_99 |= 0x01 ;
F_3 ( V_4 , V_98 , V_99 ) ;
}
if( V_92 == 0x11 ) {
int V_116 = 0x80 ;
int V_117 = ( V_91 ) ? 0x82 : 0x80 ;
switch( V_34 ) {
case V_41 :
case V_45 :
break;
case V_44 :
V_116 = 0x80 ;
V_117 = ( V_91 ) ? 0x82 : 0x80 ;
break;
case V_47 :
V_116 = 0xa0 ;
V_117 = ( V_91 ) ? 0x83 : 0x81 ;
break;
case V_49 :
V_116 = 0x00 ;
V_117 = ( V_91 ) ? 0x82 : 0x80 ;
break;
default:
return;
}
F_3 ( V_4 , V_105 , V_116 ) ;
F_3 ( V_4 , V_106 , V_117 ) ;
F_5 ( 1 , V_10 , V_3 ,
L_28 ,
V_34 , V_116 , V_117 ) ;
} else {
int V_118 , V_116 ;
switch( V_34 ) {
case V_41 :
V_118 = 0x00 ;
V_116 = 0x10 ;
break;
case V_45 :
if( V_91 ) {
V_118 = 0x00 ;
V_116 = 0x00 ;
} else {
V_118 = ( V_108 == 1 ) ? 0x05 : 0x04 ;
V_116 = 0x00 ;
}
break;
case V_44 :
V_118 = 0x02 ;
V_116 = 0x10 ;
break;
case V_47 :
V_118 = 0x02 ;
V_116 = 0x20 ;
break;
case V_49 :
V_118 = 0x02 ;
V_116 = 0x00 ;
break;
default:
return;
}
F_3 ( V_4 , V_93 , V_118 ) ;
F_3 ( V_4 , V_105 , V_116 ) ;
F_5 ( 1 , V_10 , V_3 ,
L_29 ,
V_34 , V_118 , V_116 ) ;
}
}
static int F_41 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_119 , V_120 ;
if( - 1 == ( V_119 = F_13 ( V_4 , V_121 ) ) )
return 0 ;
if( - 1 == ( V_120 = F_13 ( V_4 , V_122 ) ) )
return 0 ;
F_5 ( 1 , V_10 , V_3 , L_30 , V_119 , V_120 ) ;
if( ( V_119 == 0x11 ) || ( V_119 == 0x07 ) ) {
F_9 ( V_3 , L_31 , ( V_119 == 0x11 ) ? L_32 : L_33 ) ;
V_92 = V_119 ;
return 1 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_4 )
{
if ( V_123 > 2 )
V_123 = 1 ;
if ( V_95 >= F_8 ( V_94 ) )
V_95 = 0 ;
if( V_124 > 1 )
V_124 = 0 ;
if( V_123 == 1 )
V_89 = 0xc0 ;
else
V_89 = 0xc1 ;
V_108 = V_95 ;
V_91 = ( V_95 < 5 ) ? 0 : 1 ;
if( V_124 == 0 )
V_99 = 0x01 ;
else
V_99 = 0x05 ;
F_38 ( V_4 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_4 )
{
F_3 ( V_4 , V_125 , 0xd0 ) ;
F_3 ( V_4 , V_126 , 0x03 ) ;
F_3 ( V_4 , V_127 , 0x00 ) ;
F_3 ( V_4 , V_128 , 0x00 ) ;
F_3 ( V_4 , V_129 , 0x00 ) ;
F_3 ( V_4 , V_130 , 0x00 ) ;
F_3 ( V_4 , V_131 , 0x00 ) ;
F_3 ( V_4 , V_132 , 0x00 ) ;
F_3 ( V_4 , V_133 , 0x00 ) ;
F_3 ( V_4 , V_134 , 0x44 ) ;
F_3 ( V_4 , V_135 , 0x00 ) ;
F_3 ( V_4 , V_136 , 0x00 ) ;
F_3 ( V_4 , V_137 , 0x01 ) ;
F_3 ( V_4 , V_138 , 0x10 ) ;
F_3 ( V_4 , V_139 , 0x10 ) ;
F_3 ( V_4 , V_140 , 0x02 ) ;
F_3 ( V_4 , V_141 , 0x6f ) ;
F_3 ( V_4 , V_142 , 0x00 ) ;
F_3 ( V_4 , V_143 , 0x00 ) ;
F_3 ( V_4 , V_144 , 0x44 ) ;
F_3 ( V_4 , V_145 , 0x03 ) ;
F_3 ( V_4 , V_146 , 0x03 ) ;
F_3 ( V_4 , V_147 , 0x00 ) ;
F_3 ( V_4 , V_148 , 0x00 ) ;
F_3 ( V_4 , V_149 , 0x44 ) ;
F_3 ( V_4 , V_150 , 0x00 ) ;
F_3 ( V_4 , V_151 , 0x00 ) ;
F_3 ( V_4 , V_152 , 0x00 ) ;
F_3 ( V_4 , V_153 , 0x00 ) ;
F_3 ( V_4 , V_154 , 0xcc ) ;
return 0 ;
}
static int F_44 ( int V_6 ) { return ( unsigned char ) ( V_6 / 602 - 84 ) ; }
static int F_45 ( int V_6 ) { return ( unsigned char ) ( F_46 ( - 12 , V_6 / 2115 - 15 ) ) ; }
static int F_47 ( int V_6 ) { return ( unsigned char ) ( V_6 / 2622 - 12 ) ; }
static int F_48 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_119 , V_155 ;
V_119 = F_13 ( V_4 , 254 ) ;
V_155 = F_13 ( V_4 , 255 ) ;
if ( V_119 == 0 || V_119 == 2 ) {
F_9 ( V_3 , L_34 ,
V_119 == 0 ? L_35 : L_36 , V_155 ) ;
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
F_3 ( V_4 , V_156 , 0x3f ) ;
F_3 ( V_4 , V_157 , 0x3f ) ;
F_3 ( V_4 , V_158 , 0x3f ) ;
F_3 ( V_4 , V_159 , 0x3f ) ;
return 0 ;
}
static int F_54 ( int V_6 ) { return ( V_6 >> 10 ) | 0xc0 ; }
static int F_55 ( int V_6 ) { return ( V_6 >> 12 ) | 0xf0 ; }
static void F_56 ( struct V_1 * V_4 , int V_34 )
{
int V_160 = V_4 -> V_11 . V_12 [ V_161 + 1 ] & 0xe1 ;
switch ( V_34 ) {
case V_44 :
V_160 |= V_162 ;
V_160 |= V_163 ;
break;
case V_47 :
V_160 |= V_164 ;
V_160 |= V_163 ;
break;
case V_49 :
V_160 |= V_165 ;
V_160 |= V_166 ;
break;
case V_41 :
V_160 |= V_165 ;
V_160 |= V_167 ;
break;
case V_45 :
V_160 |= V_165 ;
V_160 |= V_168 ;
break;
default:
return;
}
F_3 ( V_4 , V_161 , V_160 ) ;
}
static int F_57 ( struct V_1 * V_4 )
{
int V_6 , V_34 ;
V_6 = F_11 ( V_4 ) ;
V_34 = V_53 ;
if ( V_6 & V_169 ) {
V_34 |= V_43 | V_48 ;
} else if ( ! ( V_6 & V_170 ) ) {
V_34 = V_46 ;
}
return V_34 ;
}
static void F_58 ( struct V_1 * V_4 , int V_34 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_56 = 1 ;
T_1 * V_57 = NULL ;
F_5 ( 1 , V_10 , V_3 , L_37 , V_34 ) ;
switch( V_34 ) {
case V_41 :
V_57 = & V_171 ;
break;
case V_45 :
V_57 = & V_172 ;
break;
case V_44 :
V_57 = & V_173 ;
break;
case V_47 :
V_57 = & V_174 ;
break;
case V_49 :
V_57 = & V_175 ;
break;
default:
V_56 = 0 ;
}
if( V_56 )
F_15 ( V_4 , L_38 , V_57 ) ;
}
static int F_59 ( struct V_1 * V_4 )
{
int V_64 ;
V_64 = F_11 ( V_4 ) ;
return ( ( V_64 & 0x1f ) == 0x1f ) ? 1 : 0 ;
}
static int F_60 ( struct V_2 * V_3 ,
struct V_176 * V_177 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_32 * V_33 = V_4 -> V_33 ;
switch ( V_177 -> V_178 ) {
case V_179 :
if ( ! ( V_33 -> V_22 & V_180 ) )
break;
V_177 -> V_181 = V_4 -> V_182 ;
return 0 ;
case V_183 :
if ( ! ( V_33 -> V_22 & V_184 ) )
break;
V_177 -> V_181 = F_46 ( V_4 -> V_185 , V_4 -> V_186 ) ;
return 0 ;
case V_187 :
{
int V_188 ;
if ( ! ( V_33 -> V_22 & V_184 ) )
break;
V_188 = F_46 ( V_4 -> V_185 , V_4 -> V_186 ) ;
if ( V_188 )
V_177 -> V_181 = ( 32768 * F_61 ( V_4 -> V_185 , V_4 -> V_186 ) ) / V_188 ;
else
V_177 -> V_181 = 32768 ;
return 0 ;
}
case V_189 :
if ( ! ( V_33 -> V_22 & V_190 ) )
break;
V_177 -> V_181 = V_4 -> V_191 ;
return 0 ;
case V_192 :
if ( ! ( V_33 -> V_22 & V_190 ) )
break;
V_177 -> V_181 = V_4 -> V_193 ;
return 0 ;
}
return - V_13 ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_176 * V_177 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_32 * V_33 = V_4 -> V_33 ;
switch ( V_177 -> V_178 ) {
case V_179 :
if ( ! ( V_33 -> V_22 & V_180 ) )
break;
if ( V_177 -> V_181 < 0 || V_177 -> V_181 >= 2 )
return - V_194 ;
V_4 -> V_182 = V_177 -> V_181 ;
if ( V_4 -> V_182 )
F_10 ( V_4 , V_33 -> V_195 , V_33 -> V_196 , V_33 -> V_197 ) ;
else
F_10 ( V_4 , V_33 -> V_195 ,
V_33 -> V_198 [ V_4 -> V_199 ] , V_33 -> V_197 ) ;
return 0 ;
case V_183 :
{
int V_188 , V_200 ;
if ( ! ( V_33 -> V_22 & V_184 ) )
break;
V_188 = F_46 ( V_4 -> V_185 , V_4 -> V_186 ) ;
if ( V_188 )
V_200 = ( 32768 * F_61 ( V_4 -> V_185 , V_4 -> V_186 ) ) / V_188 ;
else
V_200 = 32768 ;
V_188 = V_177 -> V_181 ;
V_4 -> V_185 = ( F_61 ( 65536 - V_200 , 32768 ) * V_188 ) / 32768 ;
V_4 -> V_186 = ( F_61 ( V_200 , V_188 * ( V_201 ) 32768 ) ) / 32768 ;
F_3 ( V_4 , V_33 -> V_202 , V_33 -> V_203 ( V_4 -> V_185 ) ) ;
F_3 ( V_4 , V_33 -> V_204 , V_33 -> V_203 ( V_4 -> V_186 ) ) ;
return 0 ;
}
case V_187 :
{
int V_188 , V_200 ;
if ( ! ( V_33 -> V_22 & V_184 ) )
break;
V_188 = F_46 ( V_4 -> V_185 , V_4 -> V_186 ) ;
V_200 = V_177 -> V_181 ;
V_4 -> V_185 = ( F_61 ( 65536 - V_200 , 32768 ) * V_188 ) / 32768 ;
V_4 -> V_186 = ( F_61 ( V_200 , V_188 * ( V_201 ) 32768 ) ) / 32768 ;
F_3 ( V_4 , V_33 -> V_202 , V_33 -> V_203 ( V_4 -> V_185 ) ) ;
F_3 ( V_4 , V_33 -> V_204 , V_33 -> V_203 ( V_4 -> V_186 ) ) ;
return 0 ;
}
case V_189 :
if ( ! ( V_33 -> V_22 & V_190 ) )
break;
V_4 -> V_191 = V_177 -> V_181 ;
F_3 ( V_4 , V_33 -> V_205 , V_33 -> V_206 ( V_4 -> V_191 ) ) ;
return 0 ;
case V_192 :
if ( ! ( V_33 -> V_22 & V_190 ) )
break;
V_4 -> V_193 = V_177 -> V_181 ;
F_3 ( V_4 , V_33 -> V_207 , V_33 -> V_208 ( V_4 -> V_193 ) ) ;
return 0 ;
}
return - V_13 ;
}
static int F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_38 = 1 ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 , struct V_209 * V_210 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_32 * V_33 = V_4 -> V_33 ;
switch ( V_210 -> V_178 ) {
case V_179 :
if ( V_33 -> V_22 & V_180 )
return F_65 ( V_210 , 0 , 1 , 1 , 0 ) ;
break;
case V_183 :
if ( V_33 -> V_22 & V_184 )
return F_65 ( V_210 , 0 , 65535 , 65535 / 100 , 58880 ) ;
break;
case V_187 :
if ( V_33 -> V_22 & V_184 )
return F_65 ( V_210 , 0 , 65535 , 65535 / 100 , 32768 ) ;
break;
case V_189 :
case V_192 :
if ( V_33 -> V_22 & V_190 )
return F_65 ( V_210 , 0 , 65535 , 65535 / 100 , 32768 ) ;
break;
default:
break;
}
return - V_13 ;
}
static int F_66 ( struct V_2 * V_3 ,
T_2 V_199 , T_2 V_211 , T_2 V_212 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_32 * V_33 = V_4 -> V_33 ;
if ( ! ( V_33 -> V_22 & V_180 ) )
return 0 ;
if ( V_199 >= 4 )
return - V_13 ;
V_4 -> V_199 = V_199 ;
if ( V_4 -> V_182 )
return 0 ;
F_10 ( V_4 , V_33 -> V_195 ,
V_33 -> V_198 [ V_4 -> V_199 ] , V_33 -> V_197 ) ;
return 0 ;
}
static int F_67 ( struct V_2 * V_3 , struct V_213 * V_214 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_32 * V_33 = V_4 -> V_33 ;
if ( ! V_33 -> V_50 )
return 0 ;
if ( V_4 -> V_38 )
return 0 ;
switch ( V_214 -> V_42 ) {
case V_41 :
case V_45 :
case V_44 :
case V_47 :
case V_49 :
break;
default:
return - V_13 ;
}
V_4 -> V_42 = V_214 -> V_42 ;
if ( V_4 -> V_31 )
F_18 ( V_4 -> V_31 ) ;
else
V_33 -> V_50 ( V_4 , V_214 -> V_42 ) ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 , struct V_213 * V_214 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_32 * V_33 = V_4 -> V_33 ;
if ( ! V_33 -> V_39 )
return 0 ;
if ( V_4 -> V_38 )
return 0 ;
V_214 -> V_42 = V_4 -> V_42 ;
V_214 -> V_215 = V_33 -> V_39 ( V_4 ) ;
V_214 -> V_216 = V_217 |
V_218 | V_219 ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 , T_3 V_220 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_38 = 0 ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 , struct V_221 * V_222 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_32 * V_33 = V_4 -> V_33 ;
if ( V_4 -> V_31 ) {
V_33 -> V_50 ( V_4 , V_41 ) ;
V_4 -> V_40 = - 1 ;
F_25 ( & V_4 -> V_51 , V_52 + F_26 ( 2000 ) ) ;
}
return 0 ;
}
static int F_71 ( struct V_2 * V_3 , struct V_223 * V_4 )
{
struct V_7 * V_224 = F_4 ( V_3 ) ;
return F_72 ( V_224 , V_4 , V_225 , 0 ) ;
}
static int F_73 ( struct V_7 * V_224 , const struct V_226 * V_178 )
{
struct V_1 * V_4 ;
struct V_32 * V_33 ;
struct V_2 * V_3 ;
if ( V_10 ) {
F_16 ( V_227 L_39 ) ;
F_16 ( V_227 L_40 ) ;
for ( V_33 = V_228 ; V_33 -> V_25 != NULL ; V_33 ++ )
F_16 ( L_41 , ( V_33 == V_228 ) ? L_35 : L_42 , V_33 -> V_25 ) ;
F_16 ( L_13 ) ;
}
V_4 = F_74 ( sizeof( * V_4 ) , V_229 ) ;
if ( ! V_4 )
return - V_230 ;
V_3 = & V_4 -> V_3 ;
F_75 ( V_3 , V_224 , & V_231 ) ;
F_5 ( 1 , V_10 , V_3 , L_43 , V_224 -> V_19 << 1 ) ;
for ( V_33 = V_228 ; V_33 -> V_25 != NULL ; V_33 ++ ) {
if ( 0 == * ( V_33 -> V_232 ) )
continue;
if ( V_224 -> V_19 < V_33 -> V_233 ||
V_224 -> V_19 > V_33 -> V_234 )
continue;
if ( V_33 -> V_235 && ! V_33 -> V_235 ( V_4 ) )
continue;
break;
}
if ( V_33 -> V_25 == NULL ) {
F_5 ( 1 , V_10 , V_3 , L_44 ) ;
F_76 ( V_4 ) ;
return - V_236 ;
}
F_9 ( V_3 , L_45 , V_33 -> V_25 , V_224 -> V_19 << 1 , V_224 -> V_24 -> V_25 ) ;
if ( V_33 -> V_22 ) {
F_5 ( 1 , V_10 , V_3 , L_46 ,
( V_33 -> V_22 & V_184 ) ? L_47 : L_35 ,
( V_33 -> V_22 & V_190 ) ? L_48 : L_35 ,
( V_33 -> V_22 & V_180 ) ? L_49 : L_35 ) ;
}
if ( ! V_178 )
F_77 ( V_224 -> V_25 , V_33 -> V_25 , V_237 ) ;
V_4 -> V_33 = V_33 ;
V_4 -> V_11 . V_28 = V_33 -> V_238 + 1 ;
V_4 -> V_40 = - 1 ;
V_4 -> V_42 = V_44 ;
if ( V_33 -> V_239 != NULL )
V_33 -> V_239 ( V_4 ) ;
else
F_15 ( V_4 , L_50 , & V_33 -> V_240 ) ;
if ( V_33 -> V_22 & V_184 ) {
if ( ! V_33 -> V_203 ) {
F_9 ( V_3 , L_51 ) ;
V_33 -> V_22 &= ~ V_184 ;
} else {
V_4 -> V_185 = V_33 -> V_241 ? V_33 -> V_241 : 65535 ;
V_4 -> V_186 = V_33 -> V_242 ? V_33 -> V_242 : 65535 ;
F_3 ( V_4 , V_33 -> V_202 ,
V_33 -> V_203 ( V_4 -> V_185 ) ) ;
F_3 ( V_4 , V_33 -> V_204 ,
V_33 -> V_203 ( V_4 -> V_186 ) ) ;
}
}
if ( V_33 -> V_22 & V_190 ) {
if ( ! V_33 -> V_206 || ! V_33 -> V_208 ) {
F_9 ( V_3 , L_52 ) ;
V_33 -> V_22 &= ~ V_190 ;
} else {
V_4 -> V_193 = V_33 -> V_243 ?
V_33 -> V_243 : 32768 ;
V_4 -> V_191 = V_33 -> V_244 ?
V_33 -> V_244 : 32768 ;
F_3 ( V_4 , V_33 -> V_205 ,
V_33 -> V_206 ( V_4 -> V_191 ) ) ;
F_3 ( V_4 , V_33 -> V_207 ,
V_33 -> V_208 ( V_4 -> V_193 ) ) ;
}
}
V_4 -> V_31 = NULL ;
F_78 ( & V_4 -> V_51 ) ;
if ( V_33 -> V_22 & V_245 ) {
if ( ! V_33 -> V_39 || ! V_33 -> V_50 ) {
F_9 ( V_3 , L_53 ) ;
return 0 ;
}
V_4 -> V_51 . V_246 = F_17 ;
V_4 -> V_51 . V_30 = ( unsigned long ) V_4 ;
V_4 -> V_31 = F_79 ( F_19 , V_4 , V_224 -> V_25 ) ;
if ( F_80 ( V_4 -> V_31 ) ) {
F_7 ( V_3 , L_54 ) ;
V_4 -> V_31 = NULL ;
}
}
return 0 ;
}
static int F_81 ( struct V_7 * V_224 )
{
struct V_2 * V_3 = F_82 ( V_224 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_83 ( & V_4 -> V_51 ) ;
if ( V_4 -> V_31 ) {
F_84 ( V_4 -> V_31 ) ;
V_4 -> V_31 = NULL ;
}
F_85 ( V_3 ) ;
F_76 ( V_4 ) ;
return 0 ;
}

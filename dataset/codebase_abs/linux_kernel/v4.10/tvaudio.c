static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static int F_4 ( struct V_1 * V_8 , int V_9 , int V_10 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
struct V_11 * V_12 = F_5 ( V_3 ) ;
unsigned char V_13 [ 2 ] ;
if ( V_9 < 0 ) {
F_6 ( 1 , V_14 , V_3 , L_1 , V_10 ) ;
V_8 -> V_15 . V_16 [ 1 ] = V_10 ;
V_13 [ 0 ] = V_10 ;
if ( 1 != F_7 ( V_12 , V_13 , 1 ) ) {
F_8 ( V_3 , L_2 , V_10 ) ;
return - 1 ;
}
} else {
if ( V_9 + 1 >= F_9 ( V_8 -> V_15 . V_16 ) ) {
F_10 ( V_3 ,
L_3 ,
V_9 ) ;
return - V_17 ;
}
F_6 ( 1 , V_14 , V_3 , L_4 ,
V_9 , V_10 ) ;
V_8 -> V_15 . V_16 [ V_9 + 1 ] = V_10 ;
V_13 [ 0 ] = V_9 ;
V_13 [ 1 ] = V_10 ;
if ( 2 != F_7 ( V_12 , V_13 , 2 ) ) {
F_8 ( V_3 , L_5 ,
V_9 , V_10 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_11 ( struct V_1 * V_8 ,
int V_9 , int V_10 , int V_18 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
if ( V_18 != 0 ) {
if ( V_9 < 0 ) {
V_10 = ( V_8 -> V_15 . V_16 [ 1 ] & ~ V_18 ) | ( V_10 & V_18 ) ;
} else {
if ( V_9 + 1 >= F_9 ( V_8 -> V_15 . V_16 ) ) {
F_10 ( V_3 ,
L_3 ,
V_9 ) ;
return - V_17 ;
}
V_10 = ( V_8 -> V_15 . V_16 [ V_9 + 1 ] & ~ V_18 ) | ( V_10 & V_18 ) ;
}
}
return F_4 ( V_8 , V_9 , V_10 ) ;
}
static int F_12 ( struct V_1 * V_8 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
struct V_11 * V_12 = F_5 ( V_3 ) ;
unsigned char V_13 ;
if ( 1 != F_13 ( V_12 , & V_13 , 1 ) ) {
F_8 ( V_3 , L_6 ) ;
return - 1 ;
}
F_6 ( 1 , V_14 , V_3 , L_7 , V_13 ) ;
return V_13 ;
}
static int F_14 ( struct V_1 * V_8 , int V_9 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
struct V_11 * V_12 = F_5 ( V_3 ) ;
unsigned char V_19 [ 1 ] ;
unsigned char V_20 [ 1 ] ;
struct V_21 V_22 [ 2 ] = {
{
. V_23 = V_12 -> V_23 ,
. V_24 = 1 ,
. V_25 = V_19
} ,
{
. V_23 = V_12 -> V_23 ,
. V_26 = V_27 ,
. V_24 = 1 ,
. V_25 = V_20
}
} ;
V_19 [ 0 ] = V_9 ;
if ( 2 != F_15 ( V_12 -> V_28 , V_22 , 2 ) ) {
F_8 ( V_3 , L_8 ) ;
return - 1 ;
}
F_6 ( 1 , V_14 , V_3 , L_9 ,
V_9 , V_20 [ 0 ] ) ;
return V_20 [ 0 ] ;
}
static int F_16 ( struct V_1 * V_8 , char * V_29 , T_1 * V_30 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
struct V_11 * V_12 = F_5 ( V_3 ) ;
int V_31 ;
if ( 0 == V_30 -> V_32 )
return 0 ;
if ( V_30 -> V_32 + V_30 -> V_16 [ 0 ] - 1 >= F_9 ( V_8 -> V_15 . V_16 ) ) {
F_10 ( V_3 ,
L_10 ,
V_30 -> V_16 [ 0 ] + 1 , V_30 -> V_16 [ 0 ] + V_30 -> V_32 - 1 ) ;
return - V_17 ;
}
F_6 ( 1 , V_14 , V_3 , L_11 ,
V_29 , V_30 -> V_16 [ 0 ] ) ;
for ( V_31 = 1 ; V_31 < V_30 -> V_32 ; V_31 ++ ) {
if ( V_14 )
F_17 ( V_33 L_12 , V_30 -> V_16 [ V_31 ] ) ;
V_8 -> V_15 . V_16 [ V_31 + V_30 -> V_16 [ 0 ] ] = V_30 -> V_16 [ V_31 ] ;
}
if ( V_14 )
F_17 ( V_33 L_13 ) ;
if ( V_30 -> V_32 != F_7 ( V_12 , V_30 -> V_16 , V_30 -> V_32 ) ) {
F_8 ( V_3 , L_14 , V_29 ) ;
return - 1 ;
}
return 0 ;
}
static void F_18 ( unsigned long V_34 )
{
struct V_1 * V_8 = (struct V_1 * ) V_34 ;
F_19 ( V_8 -> V_35 ) ;
}
static int F_20 ( void * V_34 )
{
struct V_1 * V_8 = V_34 ;
struct V_36 * V_37 = V_8 -> V_37 ;
struct V_2 * V_3 = & V_8 -> V_3 ;
int V_38 , V_39 ;
F_6 ( 1 , V_14 , V_3 , L_15 ) ;
F_21 () ;
for (; ; ) {
F_22 ( V_40 ) ;
if ( ! F_23 () )
F_24 () ;
F_22 ( V_41 ) ;
F_25 () ;
if ( F_23 () )
break;
F_6 ( 1 , V_14 , V_3 , L_16 ) ;
if ( V_8 -> V_42 )
continue;
V_38 = V_37 -> V_43 ( V_8 ) ;
if ( V_38 == V_8 -> V_44 )
continue;
F_6 ( 1 , V_14 , V_3 , L_17 ) ;
V_8 -> V_44 = V_38 ;
V_39 = V_45 ;
switch ( V_8 -> V_46 ) {
case V_45 :
if ( V_38 & V_47 )
V_39 = V_48 ;
break;
case V_49 :
case V_48 :
if ( V_38 & V_47 )
V_39 = V_48 ;
else if ( V_38 & V_50 )
V_39 = V_49 ;
break;
case V_51 :
if ( V_38 & V_52 )
V_39 = V_51 ;
else if ( V_38 & V_50 )
V_39 = V_49 ;
break;
case V_53 :
if ( V_38 & V_52 )
V_39 = V_53 ;
else if ( V_38 & V_50 )
V_39 = V_49 ;
}
V_37 -> V_54 ( V_8 , V_39 ) ;
F_26 ( & V_8 -> V_55 , V_56 + F_27 ( 2000 ) ) ;
}
F_6 ( 1 , V_14 , V_3 , L_18 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_8 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
int V_10 , V_38 ;
V_10 = F_12 ( V_8 ) ;
V_38 = V_57 ;
if ( V_10 & V_58 )
V_38 |= V_47 | V_52 ;
if ( V_10 & V_59 )
V_38 = V_50 ;
F_6 ( 1 , V_14 , V_3 ,
L_19 ,
V_10 , V_38 ) ;
return V_38 ;
}
static void F_29 ( struct V_1 * V_8 , int V_38 )
{
int V_60 = 1 ;
int V_61 = V_8 -> V_15 . V_16 [ V_62 + 1 ] & ~ 0x7e ;
switch ( V_38 ) {
case V_45 :
V_61 |= V_63 ;
break;
case V_49 :
V_61 |= V_64 ;
break;
case V_48 :
V_61 |= V_65 ;
break;
case V_51 :
V_61 |= V_66 ;
break;
case V_53 :
V_61 |= V_67 ;
break;
default:
V_60 = 0 ;
}
if ( V_60 )
F_4 ( V_8 , V_62 , V_61 ) ;
}
static int F_30 ( struct V_1 * V_8 )
{
int V_68 ;
V_68 = F_12 ( V_8 ) ;
return ( ( V_68 & 0x1f ) == 0 ) ? 1 : 0 ;
}
static int F_31 ( int V_10 ) { return V_10 / 0x2e8 + 0x27 ; }
static int F_32 ( int V_10 ) { return V_10 / 0xccc + 0x06 ; }
static int F_33 ( int V_10 ) { return ( V_10 / 0x1c71 + 0x3 ) << 1 ; }
static int F_34 ( struct V_1 * V_8 )
{
int V_38 , V_10 ;
V_38 = V_57 ;
V_10 = F_12 ( V_8 ) ;
if ( V_10 & V_69 )
V_38 = V_50 ;
if ( V_10 & V_70 )
V_38 |= V_71 ;
return V_38 ;
}
static void F_35 ( struct V_1 * V_8 , int V_38 )
{
int V_60 = 1 ;
int V_72 = V_8 -> V_15 . V_16 [ V_73 + 1 ] & 0x3f ;
switch ( V_38 ) {
case V_45 :
V_72 |= V_74 ;
break;
case V_49 :
case V_48 :
V_72 |= V_75 ;
break;
case V_76 :
V_72 |= V_77 ;
break;
case V_53 :
V_72 |= V_78 ;
break;
default:
V_60 = 0 ;
}
if ( V_60 )
F_4 ( V_8 , V_73 , V_72 ) ;
}
static int F_36 ( struct V_1 * V_8 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
int V_10 , V_38 ;
V_10 = F_12 ( V_8 ) ;
V_38 = V_57 ;
if ( V_10 & V_79 )
V_38 = V_50 ;
if ( V_10 & V_80 )
V_38 |= V_47 | V_52 ;
F_6 ( 1 , V_14 , V_3 ,
L_20 ,
V_10 , V_38 ) ;
return V_38 ;
}
static void F_37 ( struct V_1 * V_8 , int V_38 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
int V_81 = V_8 -> V_15 . V_16 [ V_82 + 1 ] & ~ V_83 ;
if ( ( V_81 & V_84 ) != V_85 ) {
F_6 ( 1 , V_14 , V_3 ,
L_21 ) ;
return;
}
F_6 ( 1 , V_14 , V_3 ,
L_22 ,
V_82 + 1 , V_8 -> V_15 . V_16 [ V_82 + 1 ] ) ;
F_6 ( 1 , V_14 , V_3 , L_23 ,
V_81 ) ;
switch ( V_38 ) {
case V_45 :
V_81 |= V_86 ;
break;
case V_49 :
V_81 |= V_87 ;
break;
case V_48 :
V_81 |= V_88 ;
break;
case V_51 :
V_81 |= V_89 ;
break;
case V_53 :
V_81 |= V_90 ;
break;
default:
return;
}
F_4 ( V_8 , V_82 , V_81 ) ;
F_6 ( 1 , V_14 , V_3 ,
L_24 ,
V_38 , V_81 ) ;
}
static int F_38 ( struct V_1 * V_8 )
{
int V_68 ;
if ( - 1 == ( V_68 = F_14 ( V_8 , 254 ) ) )
return 0 ;
return ( V_68 & ~ 0x1f ) == 0x80 ;
}
static int F_39 ( struct V_1 * V_8 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
F_4 ( V_8 , V_91 , 0x00 ) ;
F_4 ( V_8 , V_92 , V_93 ) ;
F_4 ( V_8 , V_94 , ( V_95 ) ? 0x03 : 0x02 ) ;
if( V_96 == 0x11 ) {
F_4 ( V_8 , V_97 , 0x80 ) ;
} else {
F_16 ( V_8 , L_25 , & V_98 [ V_99 ] . V_30 ) ;
F_4 ( V_8 , V_97 , 0x00 ) ;
}
F_4 ( V_8 , V_100 , 0x00 ) ;
F_4 ( V_8 , V_101 , 0x00 ) ;
F_4 ( V_8 , V_102 , V_103 ) ;
F_4 ( V_8 , V_104 , 0x00 ) ;
F_4 ( V_8 , V_105 , 0x14 ) ;
F_4 ( V_8 , V_106 , 0x50 ) ;
if( V_96 == 0x11 ) {
F_4 ( V_8 , V_107 , 0xf9 ) ;
F_4 ( V_8 , V_108 , ( V_95 ) ? 0x81 : 0x80 ) ;
F_4 ( V_8 , V_109 , 0x80 ) ;
F_4 ( V_8 , V_110 , ( V_95 ) ? 0x82 : 0x80 ) ;
F_4 ( V_8 , V_111 , V_112 ) ;
} else {
F_4 ( V_8 , V_107 , 0xfb ) ;
F_4 ( V_8 , V_108 , ( V_95 ) ? 0x81 : 0x80 ) ;
F_4 ( V_8 , V_109 , 0x00 ) ;
}
F_6 ( 1 , V_14 , V_3 , L_26 ,
V_98 [ V_99 ] . V_29 , V_99 ) ;
return 1 ;
}
static int F_40 ( struct V_1 * V_8 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
int V_113 , V_114 , V_38 ;
int V_115 ;
V_38 = V_57 ;
if( - 1 == ( V_113 = F_14 ( V_8 , V_116 ) ) )
return V_38 ;
if( - 1 == ( V_114 = F_14 ( V_8 , V_117 ) ) )
return V_38 ;
if( - 1 == ( V_115 = F_14 ( V_8 , V_118 ) ) )
return V_38 ;
V_8 -> V_15 . V_16 [ V_119 - 2 ] = V_113 ;
V_8 -> V_15 . V_16 [ V_119 - 1 ] = V_114 ;
if( V_95 ) {
if( V_114 & 0x02 )
V_38 = V_50 ;
if( V_114 & 0x01 )
V_38 |= V_47 | V_52 ;
} else {
if( V_113 & 0x02 )
V_38 = V_50 ;
if( V_113 & 0x04 )
V_38 |= V_47 | V_52 ;
}
F_6 ( 1 , V_14 , V_3 ,
L_27 ,
V_113 , V_114 , V_115 , V_38 ) ;
return V_38 ;
}
static void F_41 ( struct V_1 * V_8 , int V_38 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
if ( V_95 ) {
if( V_8 -> V_15 . V_16 [ V_119 - 2 ] & 0x20 )
V_103 &= 0xfe ;
else
V_103 |= 0x01 ;
F_4 ( V_8 , V_102 , V_103 ) ;
}
if( V_96 == 0x11 ) {
int V_120 = 0x80 ;
int V_121 = ( V_95 ) ? 0x82 : 0x80 ;
switch( V_38 ) {
case V_45 :
case V_49 :
break;
case V_48 :
V_120 = 0x80 ;
V_121 = ( V_95 ) ? 0x82 : 0x80 ;
break;
case V_51 :
V_120 = 0xa0 ;
V_121 = ( V_95 ) ? 0x83 : 0x81 ;
break;
case V_53 :
V_120 = 0x00 ;
V_121 = ( V_95 ) ? 0x82 : 0x80 ;
break;
default:
return;
}
F_4 ( V_8 , V_109 , V_120 ) ;
F_4 ( V_8 , V_110 , V_121 ) ;
F_6 ( 1 , V_14 , V_3 ,
L_28 ,
V_38 , V_120 , V_121 ) ;
} else {
int V_122 , V_120 ;
switch( V_38 ) {
case V_45 :
V_122 = 0x00 ;
V_120 = 0x10 ;
break;
case V_49 :
if( V_95 ) {
V_122 = 0x00 ;
V_120 = 0x00 ;
} else {
V_122 = ( V_112 == 1 ) ? 0x05 : 0x04 ;
V_120 = 0x00 ;
}
break;
case V_48 :
V_122 = 0x02 ;
V_120 = 0x10 ;
break;
case V_51 :
V_122 = 0x02 ;
V_120 = 0x20 ;
break;
case V_53 :
V_122 = 0x02 ;
V_120 = 0x00 ;
break;
default:
return;
}
F_4 ( V_8 , V_97 , V_122 ) ;
F_4 ( V_8 , V_109 , V_120 ) ;
F_6 ( 1 , V_14 , V_3 ,
L_29 ,
V_38 , V_122 , V_120 ) ;
}
}
static int F_42 ( struct V_1 * V_8 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
int V_123 , V_124 ;
if( - 1 == ( V_123 = F_14 ( V_8 , V_125 ) ) )
return 0 ;
if( - 1 == ( V_124 = F_14 ( V_8 , V_126 ) ) )
return 0 ;
F_6 ( 1 , V_14 , V_3 , L_30 , V_123 , V_124 ) ;
if( ( V_123 == 0x11 ) || ( V_123 == 0x07 ) ) {
F_10 ( V_3 , L_31 , ( V_123 == 0x11 ) ? L_32 : L_33 ) ;
V_96 = V_123 ;
return 1 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_8 )
{
if ( V_127 > 2 )
V_127 = 1 ;
if ( V_99 >= F_9 ( V_98 ) )
V_99 = 0 ;
if( V_128 > 1 )
V_128 = 0 ;
if( V_127 == 1 )
V_93 = 0xc0 ;
else
V_93 = 0xc1 ;
V_112 = V_99 ;
V_95 = ( V_99 < 5 ) ? 0 : 1 ;
if( V_128 == 0 )
V_103 = 0x01 ;
else
V_103 = 0x05 ;
F_39 ( V_8 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_8 )
{
F_4 ( V_8 , V_129 , 0xd0 ) ;
F_4 ( V_8 , V_130 , 0x03 ) ;
F_4 ( V_8 , V_131 , 0x00 ) ;
F_4 ( V_8 , V_132 , 0x00 ) ;
F_4 ( V_8 , V_133 , 0x00 ) ;
F_4 ( V_8 , V_134 , 0x00 ) ;
F_4 ( V_8 , V_135 , 0x00 ) ;
F_4 ( V_8 , V_136 , 0x00 ) ;
F_4 ( V_8 , V_137 , 0x00 ) ;
F_4 ( V_8 , V_138 , 0x44 ) ;
F_4 ( V_8 , V_139 , 0x00 ) ;
F_4 ( V_8 , V_140 , 0x00 ) ;
F_4 ( V_8 , V_141 , 0x01 ) ;
F_4 ( V_8 , V_142 , 0x10 ) ;
F_4 ( V_8 , V_143 , 0x10 ) ;
F_4 ( V_8 , V_144 , 0x02 ) ;
F_4 ( V_8 , V_145 , 0x6f ) ;
F_4 ( V_8 , V_146 , 0x00 ) ;
F_4 ( V_8 , V_147 , 0x00 ) ;
F_4 ( V_8 , V_148 , 0x44 ) ;
F_4 ( V_8 , V_149 , 0x03 ) ;
F_4 ( V_8 , V_150 , 0x03 ) ;
F_4 ( V_8 , V_151 , 0x00 ) ;
F_4 ( V_8 , V_152 , 0x00 ) ;
F_4 ( V_8 , V_153 , 0x44 ) ;
F_4 ( V_8 , V_154 , 0x00 ) ;
F_4 ( V_8 , V_155 , 0x00 ) ;
F_4 ( V_8 , V_156 , 0x00 ) ;
F_4 ( V_8 , V_157 , 0x00 ) ;
F_4 ( V_8 , V_158 , 0xcc ) ;
return 0 ;
}
static int F_45 ( int V_10 ) { return ( unsigned char ) ( V_10 / 602 - 84 ) ; }
static int F_46 ( int V_10 ) { return ( unsigned char ) ( F_47 ( - 12 , V_10 / 2115 - 15 ) ) ; }
static int F_48 ( int V_10 ) { return ( unsigned char ) ( V_10 / 2622 - 12 ) ; }
static int F_49 ( struct V_1 * V_8 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
int V_123 , V_159 ;
V_123 = F_14 ( V_8 , 254 ) ;
V_159 = F_14 ( V_8 , 255 ) ;
if ( V_123 == 0 || V_123 == 2 ) {
F_10 ( V_3 , L_34 ,
V_123 == 0 ? L_35 : L_36 , V_159 ) ;
return 1 ;
}
return 0 ;
}
static int F_50 ( int V_10 ) { return V_10 >> 10 ; }
static int F_51 ( int V_10 ) { return V_10 >> 12 ; }
static int F_52 ( int V_10 ) { return ( V_10 / ( 65535 / ( 63 - 12 ) ) + 12 ) & 0x3f ; }
static int F_53 ( int V_10 ) { return V_10 >> 11 ; }
static int F_54 ( struct V_1 * V_8 )
{
F_4 ( V_8 , V_160 , 0x3f ) ;
F_4 ( V_8 , V_161 , 0x3f ) ;
F_4 ( V_8 , V_162 , 0x3f ) ;
F_4 ( V_8 , V_163 , 0x3f ) ;
return 0 ;
}
static int F_55 ( int V_10 ) { return ( V_10 >> 10 ) | 0xc0 ; }
static int F_56 ( int V_10 ) { return ( V_10 >> 12 ) | 0xf0 ; }
static void F_57 ( struct V_1 * V_8 , int V_38 )
{
int V_164 = V_8 -> V_15 . V_16 [ V_165 + 1 ] & 0xe1 ;
switch ( V_38 ) {
case V_48 :
V_164 |= V_166 ;
V_164 |= V_167 ;
break;
case V_51 :
V_164 |= V_168 ;
V_164 |= V_167 ;
break;
case V_53 :
V_164 |= V_169 ;
V_164 |= V_170 ;
break;
case V_45 :
V_164 |= V_169 ;
V_164 |= V_171 ;
break;
case V_49 :
V_164 |= V_169 ;
V_164 |= V_172 ;
break;
default:
return;
}
F_4 ( V_8 , V_165 , V_164 ) ;
}
static int F_58 ( struct V_1 * V_8 )
{
int V_10 , V_38 ;
V_10 = F_12 ( V_8 ) ;
V_38 = V_57 ;
if ( V_10 & V_173 ) {
V_38 |= V_47 | V_52 ;
} else if ( ! ( V_10 & V_174 ) ) {
V_38 = V_50 ;
}
return V_38 ;
}
static void F_59 ( struct V_1 * V_8 , int V_38 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
int V_60 = 1 ;
T_1 * V_61 = NULL ;
F_6 ( 1 , V_14 , V_3 , L_37 , V_38 ) ;
switch( V_38 ) {
case V_45 :
V_61 = & V_175 ;
break;
case V_49 :
V_61 = & V_176 ;
break;
case V_48 :
V_61 = & V_177 ;
break;
case V_51 :
V_61 = & V_178 ;
break;
case V_53 :
V_61 = & V_179 ;
break;
default:
V_60 = 0 ;
}
if( V_60 )
F_16 ( V_8 , L_38 , V_61 ) ;
}
static int F_60 ( struct V_1 * V_8 )
{
int V_68 ;
V_68 = F_12 ( V_8 ) ;
return ( ( V_68 & 0x1f ) == 0x1f ) ? 1 : 0 ;
}
static int F_61 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_36 * V_37 = V_8 -> V_37 ;
switch ( V_5 -> V_180 ) {
case V_181 :
V_8 -> V_182 = V_5 -> V_10 ;
if ( V_8 -> V_182 )
F_11 ( V_8 , V_37 -> V_183 , V_37 -> V_184 , V_37 -> V_185 ) ;
else
F_11 ( V_8 , V_37 -> V_183 ,
V_37 -> V_186 [ V_8 -> V_187 ] , V_37 -> V_185 ) ;
return 0 ;
case V_188 : {
T_2 V_189 , V_190 ;
T_2 V_191 , V_192 ;
V_189 = V_8 -> V_189 -> V_10 ;
V_190 = V_8 -> V_190 -> V_10 ;
V_191 = ( F_62 ( 65536U - V_190 , 32768U ) * V_189 ) / 32768U ;
V_192 = ( F_62 ( V_190 , 32768U ) * V_189 ) / 32768U ;
F_4 ( V_8 , V_37 -> V_193 , V_37 -> V_194 ( V_191 ) ) ;
F_4 ( V_8 , V_37 -> V_195 , V_37 -> V_194 ( V_192 ) ) ;
return 0 ;
}
case V_196 :
F_4 ( V_8 , V_37 -> V_197 , V_37 -> V_198 ( V_5 -> V_10 ) ) ;
return 0 ;
case V_199 :
F_4 ( V_8 , V_37 -> V_200 , V_37 -> V_201 ( V_5 -> V_10 ) ) ;
return 0 ;
}
return - V_17 ;
}
static int F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_8 -> V_42 = 1 ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 ,
T_2 V_187 , T_2 V_202 , T_2 V_203 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_36 * V_37 = V_8 -> V_37 ;
if ( ! ( V_37 -> V_26 & V_204 ) )
return 0 ;
if ( V_187 >= 4 )
return - V_17 ;
V_8 -> V_187 = V_187 ;
if ( V_8 -> V_182 )
return 0 ;
F_11 ( V_8 , V_37 -> V_183 ,
V_37 -> V_186 [ V_8 -> V_187 ] , V_37 -> V_185 ) ;
return 0 ;
}
static int F_65 ( struct V_2 * V_3 , const struct V_205 * V_206 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_36 * V_37 = V_8 -> V_37 ;
if ( ! V_37 -> V_54 )
return 0 ;
if ( V_8 -> V_42 )
return 0 ;
switch ( V_206 -> V_46 ) {
case V_45 :
case V_49 :
case V_48 :
case V_51 :
case V_53 :
break;
default:
return - V_17 ;
}
V_8 -> V_46 = V_206 -> V_46 ;
if ( V_8 -> V_35 )
F_19 ( V_8 -> V_35 ) ;
else
V_37 -> V_54 ( V_8 , V_206 -> V_46 ) ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 , struct V_205 * V_206 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_36 * V_37 = V_8 -> V_37 ;
if ( ! V_37 -> V_43 )
return 0 ;
if ( V_8 -> V_42 )
return 0 ;
V_206 -> V_46 = V_8 -> V_46 ;
V_206 -> V_207 = V_37 -> V_43 ( V_8 ) ;
V_206 -> V_208 |= V_209 |
V_210 | V_211 ;
return 0 ;
}
static int F_67 ( struct V_2 * V_3 , T_3 V_212 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_8 -> V_42 = 0 ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 , const struct V_213 * V_214 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_36 * V_37 = V_8 -> V_37 ;
if ( V_8 -> V_35 ) {
V_37 -> V_54 ( V_8 , V_45 ) ;
V_8 -> V_44 = - 1 ;
F_26 ( & V_8 -> V_55 , V_56 + F_27 ( 2000 ) ) ;
}
return 0 ;
}
static int F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_36 * V_37 = V_8 -> V_37 ;
F_10 ( V_3 , L_39 , V_37 -> V_29 ) ;
F_70 ( & V_8 -> V_7 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_71 ( struct V_11 * V_215 , const struct V_216 * V_180 )
{
struct V_1 * V_8 ;
struct V_36 * V_37 ;
struct V_2 * V_3 ;
if ( V_14 ) {
F_17 ( V_217 L_40 ) ;
F_17 ( V_217 L_41 ) ;
for ( V_37 = V_218 ; V_37 -> V_29 != NULL ; V_37 ++ )
F_17 ( V_33 L_42 ,
( V_37 == V_218 ) ? L_35 : L_43 , V_37 -> V_29 ) ;
F_17 ( V_33 L_13 ) ;
}
V_8 = F_72 ( & V_215 -> V_219 , sizeof( * V_8 ) , V_220 ) ;
if ( ! V_8 )
return - V_221 ;
V_3 = & V_8 -> V_3 ;
F_73 ( V_3 , V_215 , & V_222 ) ;
F_6 ( 1 , V_14 , V_3 , L_44 , V_215 -> V_23 << 1 ) ;
for ( V_37 = V_218 ; V_37 -> V_29 != NULL ; V_37 ++ ) {
if ( 0 == * ( V_37 -> V_223 ) )
continue;
if ( V_215 -> V_23 < V_37 -> V_224 ||
V_215 -> V_23 > V_37 -> V_225 )
continue;
if ( V_37 -> V_226 && ! V_37 -> V_226 ( V_8 ) )
continue;
break;
}
if ( V_37 -> V_29 == NULL ) {
F_6 ( 1 , V_14 , V_3 , L_45 ) ;
return - V_227 ;
}
F_10 ( V_3 , L_46 , V_37 -> V_29 , V_215 -> V_23 << 1 , V_215 -> V_28 -> V_29 ) ;
if ( V_37 -> V_26 ) {
F_6 ( 1 , V_14 , V_3 , L_47 ,
( V_37 -> V_26 & V_228 ) ? L_48 : L_35 ,
( V_37 -> V_26 & V_229 ) ? L_49 : L_35 ,
( V_37 -> V_26 & V_204 ) ? L_50 : L_35 ) ;
}
if ( ! V_180 )
F_74 ( V_215 -> V_29 , V_37 -> V_29 , V_230 ) ;
V_8 -> V_37 = V_37 ;
V_8 -> V_15 . V_32 = V_37 -> V_231 + 1 ;
V_8 -> V_44 = - 1 ;
V_8 -> V_46 = V_48 ;
if ( V_37 -> V_232 != NULL )
V_37 -> V_232 ( V_8 ) ;
else
F_16 ( V_8 , L_51 , & V_37 -> V_233 ) ;
F_75 ( & V_8 -> V_7 , 5 ) ;
if ( V_37 -> V_26 & V_204 )
F_76 ( & V_8 -> V_7 , & V_234 ,
V_181 , 0 , 1 , 1 , 0 ) ;
if ( V_37 -> V_26 & V_228 ) {
if ( ! V_37 -> V_194 ) {
F_10 ( V_3 , L_52 ) ;
V_37 -> V_26 &= ~ V_228 ;
} else {
V_8 -> V_189 = F_76 ( & V_8 -> V_7 ,
& V_234 , V_188 ,
0 , 65535 , 65535 / 100 ,
V_37 -> V_235 ? V_37 -> V_235 : 65535 ) ;
V_8 -> V_190 = F_76 ( & V_8 -> V_7 ,
& V_234 , V_236 ,
0 , 65535 , 65535 / 100 , 32768 ) ;
F_77 ( 2 , & V_8 -> V_189 ) ;
}
}
if ( V_37 -> V_26 & V_229 ) {
if ( ! V_37 -> V_198 || ! V_37 -> V_201 ) {
F_10 ( V_3 , L_53 ) ;
V_37 -> V_26 &= ~ V_229 ;
} else {
F_76 ( & V_8 -> V_7 ,
& V_234 , V_196 ,
0 , 65535 , 65535 / 100 ,
V_37 -> V_237 ? V_37 -> V_237 : 32768 ) ;
F_76 ( & V_8 -> V_7 ,
& V_234 , V_199 ,
0 , 65535 , 65535 / 100 ,
V_37 -> V_238 ? V_37 -> V_238 : 32768 ) ;
}
}
V_3 -> V_239 = & V_8 -> V_7 ;
if ( V_8 -> V_7 . error ) {
int V_240 = V_8 -> V_7 . error ;
F_78 ( & V_8 -> V_7 ) ;
return V_240 ;
}
F_79 ( & V_8 -> V_7 ) ;
V_8 -> V_35 = NULL ;
F_80 ( & V_8 -> V_55 ) ;
if ( V_37 -> V_26 & V_241 ) {
if ( ! V_37 -> V_43 || ! V_37 -> V_54 ) {
F_10 ( V_3 , L_54 ) ;
return 0 ;
}
V_8 -> V_55 . V_242 = F_18 ;
V_8 -> V_55 . V_34 = ( unsigned long ) V_8 ;
V_8 -> V_35 = F_81 ( F_20 , V_8 , L_55 ,
V_215 -> V_29 ) ;
if ( F_82 ( V_8 -> V_35 ) ) {
F_8 ( V_3 , L_56 ) ;
V_8 -> V_35 = NULL ;
}
}
return 0 ;
}
static int F_83 ( struct V_11 * V_215 )
{
struct V_2 * V_3 = F_84 ( V_215 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_85 ( & V_8 -> V_55 ) ;
if ( V_8 -> V_35 ) {
F_86 ( V_8 -> V_35 ) ;
V_8 -> V_35 = NULL ;
}
F_87 ( V_3 ) ;
F_78 ( & V_8 -> V_7 ) ;
return 0 ;
}

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
int V_31 ;
F_5 ( 1 , V_10 , V_3 , L_15 ) ;
F_20 () ;
for (; ; ) {
F_21 ( V_32 ) ;
if ( ! F_22 () )
F_23 () ;
F_21 ( V_33 ) ;
F_24 () ;
if ( F_22 () )
break;
F_5 ( 1 , V_10 , V_3 , L_16 ) ;
if ( V_4 -> V_34 || V_4 -> V_31 != 0 )
continue;
V_31 = V_30 -> V_35 ( V_4 ) ;
if ( V_31 == V_4 -> V_36 )
continue;
F_5 ( 1 , V_10 , V_3 , L_17 ) ;
V_4 -> V_36 = V_31 ;
if ( V_31 & V_37 )
V_30 -> V_38 ( V_4 , V_37 ) ;
if ( V_31 & V_39 )
V_30 -> V_38 ( V_4 , V_37 ) ;
else if ( V_31 & V_40 )
V_30 -> V_38 ( V_4 , V_40 ) ;
else if ( V_31 & V_41 )
V_30 -> V_38 ( V_4 , V_41 ) ;
else
V_30 -> V_38 ( V_4 , V_42 ) ;
F_25 ( & V_4 -> V_43 , V_44 + F_26 ( 2000 ) ) ;
}
F_5 ( 1 , V_10 , V_3 , L_18 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_6 , V_31 ;
V_6 = F_11 ( V_4 ) ;
V_31 = V_42 ;
if ( V_6 & V_45 )
V_31 |= V_40 | V_41 ;
if ( V_6 & V_46 )
V_31 |= V_37 ;
F_5 ( 1 , V_10 , V_3 , L_19 ,
V_6 , V_31 ) ;
return V_31 ;
}
static void F_28 ( struct V_1 * V_4 , int V_31 )
{
int V_47 = 1 ;
int V_48 = V_4 -> V_11 . V_12 [ V_49 + 1 ] & ~ 0x7e ;
switch ( V_31 ) {
case V_42 :
V_48 |= V_50 ;
break;
case V_37 :
V_48 |= V_51 ;
break;
case V_40 :
V_48 |= V_52 ;
break;
case V_41 :
V_48 |= V_53 ;
break;
default:
V_47 = 0 ;
}
if ( V_47 )
F_3 ( V_4 , V_49 , V_48 ) ;
}
static int F_29 ( struct V_1 * V_4 )
{
int V_54 ;
V_54 = F_11 ( V_4 ) ;
return ( ( V_54 & 0x1f ) == 0 ) ? 1 : 0 ;
}
static int F_30 ( int V_6 ) { return V_6 / 0x2e8 + 0x27 ; }
static int F_31 ( int V_6 ) { return V_6 / 0xccc + 0x06 ; }
static int F_32 ( int V_6 ) { return ( V_6 / 0x1c71 + 0x3 ) << 1 ; }
static int F_33 ( struct V_1 * V_4 )
{
int V_31 ;
V_31 = ( ( V_55 | V_56 ) &
F_11 ( V_4 ) ) >> 4 ;
return V_31 | V_42 ;
}
static void F_34 ( struct V_1 * V_4 , int V_31 )
{
int V_47 = 1 ;
int V_57 = V_4 -> V_11 . V_12 [ V_58 + 1 ] & 0x3f ;
switch ( V_31 ) {
case V_42 :
V_57 |= V_59 ;
break;
case V_37 :
V_57 |= V_60 ;
break;
case V_40 :
V_57 |= V_61 ;
break;
default:
V_47 = 0 ;
}
if ( V_47 )
F_3 ( V_4 , V_58 , V_57 ) ;
}
static int F_35 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_6 , V_31 ;
V_6 = F_11 ( V_4 ) ;
V_31 = V_42 ;
if ( V_6 & V_62 )
V_31 |= V_37 ;
if ( V_6 & V_63 )
V_31 |= V_40 | V_41 ;
F_5 ( 1 , V_10 , V_3 , L_20 ,
V_6 , V_31 ) ;
return V_31 ;
}
static void F_36 ( struct V_1 * V_4 , int V_31 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_64 = V_4 -> V_11 . V_12 [ V_65 + 1 ] & ~ V_66 ;
if ( ( V_64 & V_67 ) != V_68 ) {
F_5 ( 1 , V_10 , V_3 , L_21 ) ;
return;
}
F_5 ( 1 , V_10 , V_3 , L_22 , V_65 + 1 , V_4 -> V_11 . V_12 [ V_65 + 1 ] ) ;
F_5 ( 1 , V_10 , V_3 , L_23 , V_64 ) ;
switch ( V_31 ) {
case V_42 :
V_64 |= V_69 ;
break;
case V_37 :
V_64 |= V_70 ;
break;
case V_40 :
V_64 |= V_71 ;
break;
case V_41 :
V_64 |= V_72 ;
break;
default:
V_4 -> V_31 = 0 ;
return;
}
F_3 ( V_4 , V_65 , V_64 ) ;
F_5 ( 1 , V_10 , V_3 , L_24 ,
V_31 , V_64 ) ;
}
static int F_37 ( struct V_1 * V_4 )
{
int V_54 ;
if ( - 1 == ( V_54 = F_13 ( V_4 , 254 ) ) )
return 0 ;
return ( V_54 & ~ 0x1f ) == 0x80 ;
}
static int F_38 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
F_3 ( V_4 , V_73 , 0x00 ) ;
F_3 ( V_4 , V_74 , V_75 ) ;
F_3 ( V_4 , V_76 , ( V_77 ) ? 0x03 : 0x02 ) ;
if( V_78 == 0x11 ) {
F_3 ( V_4 , V_79 , 0x80 ) ;
} else {
F_15 ( V_4 , L_25 , & V_80 [ V_81 ] . V_23 ) ;
F_3 ( V_4 , V_79 , 0x00 ) ;
}
F_3 ( V_4 , V_82 , 0x00 ) ;
F_3 ( V_4 , V_83 , 0x00 ) ;
F_3 ( V_4 , V_84 , V_85 ) ;
F_3 ( V_4 , V_86 , 0x00 ) ;
F_3 ( V_4 , V_87 , 0x14 ) ;
F_3 ( V_4 , V_88 , 0x50 ) ;
if( V_78 == 0x11 ) {
F_3 ( V_4 , V_89 , 0xf9 ) ;
F_3 ( V_4 , V_90 , ( V_77 ) ? 0x81 : 0x80 ) ;
F_3 ( V_4 , V_91 , 0x80 ) ;
F_3 ( V_4 , V_92 , ( V_77 ) ? 0x82 : 0x80 ) ;
F_3 ( V_4 , V_93 , V_94 ) ;
} else {
F_3 ( V_4 , V_89 , 0xfb ) ;
F_3 ( V_4 , V_90 , ( V_77 ) ? 0x81 : 0x80 ) ;
F_3 ( V_4 , V_91 , 0x00 ) ;
}
F_5 ( 1 , V_10 , V_3 , L_26 ,
V_80 [ V_81 ] . V_22 , V_81 ) ;
return 1 ;
}
static int F_39 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_95 , V_96 , V_31 ;
int V_97 ;
V_31 = V_42 ;
if( - 1 == ( V_95 = F_13 ( V_4 , V_98 ) ) )
return V_31 ;
if( - 1 == ( V_96 = F_13 ( V_4 , V_99 ) ) )
return V_31 ;
if( - 1 == ( V_97 = F_13 ( V_4 , V_100 ) ) )
return V_31 ;
V_4 -> V_11 . V_12 [ V_101 - 2 ] = V_95 ;
V_4 -> V_11 . V_12 [ V_101 - 1 ] = V_96 ;
if( V_77 ) {
if( V_96 & 0x02 )
V_31 |= V_37 ;
if( V_96 & 0x01 )
V_31 |= V_40 | V_41 ;
} else {
if( V_95 & 0x02 )
V_31 |= V_37 ;
if( V_95 & 0x04 )
V_31 |= V_40 | V_41 ;
}
F_5 ( 1 , V_10 , V_3 , L_27 ,
V_95 , V_96 , V_97 , V_31 ) ;
return V_31 ;
}
static void F_40 ( struct V_1 * V_4 , int V_31 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
if ( V_77 ) {
if( V_4 -> V_11 . V_12 [ V_101 - 2 ] & 0x20 )
V_85 &= 0xfe ;
else
V_85 |= 0x01 ;
F_3 ( V_4 , V_84 , V_85 ) ;
}
if( V_78 == 0x11 ) {
int V_102 = 0x80 ;
int V_103 = ( V_77 ) ? 0x82 : 0x80 ;
switch( V_31 ) {
case V_42 :
case V_37 :
break;
case V_40 :
V_102 = 0x80 ;
V_103 = ( V_77 ) ? 0x82 : 0x80 ;
break;
case V_41 :
V_102 = 0xa0 ;
V_103 = ( V_77 ) ? 0x83 : 0x81 ;
break;
default:
V_4 -> V_31 = 0 ;
return;
}
F_3 ( V_4 , V_91 , V_102 ) ;
F_3 ( V_4 , V_92 , V_103 ) ;
F_5 ( 1 , V_10 , V_3 , L_28 ,
V_31 , V_102 , V_103 ) ;
} else {
int V_104 , V_102 ;
switch( V_31 ) {
case V_42 :
V_104 = 0x00 ;
V_102 = 0x10 ;
break;
case V_37 :
if( V_77 ) {
V_104 = 0x00 ;
V_102 = 0x00 ;
} else {
V_104 = ( V_94 == 1 ) ? 0x05 : 0x04 ;
V_102 = 0x00 ;
}
break;
case V_40 :
V_104 = 0x02 ;
V_102 = 0x10 ;
break;
case V_41 :
V_104 = 0x02 ;
V_102 = 0x20 ;
break;
default:
V_4 -> V_31 = 0 ;
return;
}
F_3 ( V_4 , V_79 , V_104 ) ;
F_3 ( V_4 , V_91 , V_102 ) ;
F_5 ( 1 , V_10 , V_3 , L_29 ,
V_31 , V_104 , V_102 ) ;
}
}
static int F_41 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_105 , V_106 ;
if( - 1 == ( V_105 = F_13 ( V_4 , V_107 ) ) )
return 0 ;
if( - 1 == ( V_106 = F_13 ( V_4 , V_108 ) ) )
return 0 ;
F_5 ( 1 , V_10 , V_3 , L_30 , V_105 , V_106 ) ;
if( ( V_105 == 0x11 ) || ( V_105 == 0x07 ) ) {
F_9 ( V_3 , L_31 , ( V_105 == 0x11 ) ? L_32 : L_33 ) ;
V_78 = V_105 ;
return 1 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_4 )
{
if ( V_109 > 2 )
V_109 = 1 ;
if ( V_81 >= F_8 ( V_80 ) )
V_81 = 0 ;
if( V_110 > 1 )
V_110 = 0 ;
if( V_109 == 1 )
V_75 = 0xc0 ;
else
V_75 = 0xc1 ;
V_94 = V_81 ;
V_77 = ( V_81 < 5 ) ? 0 : 1 ;
if( V_110 == 0 )
V_85 = 0x01 ;
else
V_85 = 0x05 ;
F_38 ( V_4 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_4 )
{
F_3 ( V_4 , V_111 , 0xd0 ) ;
F_3 ( V_4 , V_112 , 0x03 ) ;
F_3 ( V_4 , V_113 , 0x00 ) ;
F_3 ( V_4 , V_114 , 0x00 ) ;
F_3 ( V_4 , V_115 , 0x00 ) ;
F_3 ( V_4 , V_116 , 0x00 ) ;
F_3 ( V_4 , V_117 , 0x00 ) ;
F_3 ( V_4 , V_118 , 0x00 ) ;
F_3 ( V_4 , V_119 , 0x00 ) ;
F_3 ( V_4 , V_120 , 0x44 ) ;
F_3 ( V_4 , V_121 , 0x00 ) ;
F_3 ( V_4 , V_122 , 0x00 ) ;
F_3 ( V_4 , V_123 , 0x01 ) ;
F_3 ( V_4 , V_124 , 0x10 ) ;
F_3 ( V_4 , V_125 , 0x10 ) ;
F_3 ( V_4 , V_126 , 0x02 ) ;
F_3 ( V_4 , V_127 , 0x6f ) ;
F_3 ( V_4 , V_128 , 0x00 ) ;
F_3 ( V_4 , V_129 , 0x00 ) ;
F_3 ( V_4 , V_130 , 0x44 ) ;
F_3 ( V_4 , V_131 , 0x03 ) ;
F_3 ( V_4 , V_132 , 0x03 ) ;
F_3 ( V_4 , V_133 , 0x00 ) ;
F_3 ( V_4 , V_134 , 0x00 ) ;
F_3 ( V_4 , V_135 , 0x44 ) ;
F_3 ( V_4 , V_136 , 0x00 ) ;
F_3 ( V_4 , V_137 , 0x00 ) ;
F_3 ( V_4 , V_138 , 0x00 ) ;
F_3 ( V_4 , V_139 , 0x00 ) ;
F_3 ( V_4 , V_140 , 0xcc ) ;
return 0 ;
}
static int F_44 ( int V_6 ) { return ( unsigned char ) ( V_6 / 602 - 84 ) ; }
static int F_45 ( int V_6 ) { return ( unsigned char ) ( F_46 ( - 12 , V_6 / 2115 - 15 ) ) ; }
static int F_47 ( int V_6 ) { return ( unsigned char ) ( V_6 / 2622 - 12 ) ; }
static int F_48 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_105 , V_141 ;
V_105 = F_13 ( V_4 , 254 ) ;
V_141 = F_13 ( V_4 , 255 ) ;
if ( V_105 == 0 || V_105 == 2 ) {
F_9 ( V_3 , L_34 ,
V_105 == 0 ? L_35 : L_36 , V_141 ) ;
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
F_3 ( V_4 , V_142 , 0x3f ) ;
F_3 ( V_4 , V_143 , 0x3f ) ;
F_3 ( V_4 , V_144 , 0x3f ) ;
F_3 ( V_4 , V_145 , 0x3f ) ;
return 0 ;
}
static int F_54 ( int V_6 ) { return ( V_6 >> 10 ) | 0xc0 ; }
static int F_55 ( int V_6 ) { return ( V_6 >> 12 ) | 0xf0 ; }
static void F_56 ( struct V_1 * V_4 , int V_31 )
{
int V_146 = V_4 -> V_11 . V_12 [ V_147 + 1 ] & 0xe1 ;
if ( V_31 & V_40 ) {
V_146 |= V_148 ;
V_146 |= V_149 ;
} else if ( V_31 & V_41 ) {
V_146 |= V_150 ;
V_146 |= V_149 ;
} else {
V_146 |= V_151 ;
if ( V_31 & V_42 )
V_146 |= V_152 ;
if ( V_31 & V_37 )
V_146 |= V_153 ;
}
F_3 ( V_4 , V_147 , V_146 ) ;
}
static int F_57 ( struct V_1 * V_4 )
{
int V_6 , V_31 ;
V_6 = F_11 ( V_4 ) ;
V_31 = V_42 ;
if ( V_6 & V_154 ) {
V_31 |= V_40 | V_41 ;
} else if ( ! ( V_6 & V_155 ) ) {
V_31 |= V_37 ;
}
return V_31 ;
}
static void F_58 ( struct V_1 * V_4 , int V_31 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_47 = 1 ;
T_1 * V_48 = NULL ;
F_5 ( 1 , V_10 , V_3 , L_37 , V_31 ) ;
switch( V_31 ) {
case V_42 :
V_48 = & V_156 ;
break;
case V_37 :
V_48 = & V_157 ;
break;
case V_40 :
V_48 = & V_158 ;
break;
case V_41 :
V_48 = & V_159 ;
break;
default:
V_47 = 0 ;
}
if( V_47 )
F_15 ( V_4 , L_38 , V_48 ) ;
}
static int F_59 ( struct V_1 * V_4 )
{
int V_54 ;
V_54 = F_11 ( V_4 ) ;
return ( ( V_54 & 0x1f ) == 0x1f ) ? 1 : 0 ;
}
static int F_60 ( struct V_2 * V_3 ,
struct V_160 * V_161 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_4 -> V_30 ;
switch ( V_161 -> V_162 ) {
case V_163 :
if ( ! ( V_30 -> V_164 & V_165 ) )
break;
V_161 -> V_166 = V_4 -> V_167 ;
return 0 ;
case V_168 :
if ( ! ( V_30 -> V_164 & V_169 ) )
break;
V_161 -> V_166 = F_46 ( V_4 -> V_170 , V_4 -> V_171 ) ;
return 0 ;
case V_172 :
{
int V_173 ;
if ( ! ( V_30 -> V_164 & V_169 ) )
break;
V_173 = F_46 ( V_4 -> V_170 , V_4 -> V_171 ) ;
if ( V_173 )
V_161 -> V_166 = ( 32768 * F_61 ( V_4 -> V_170 , V_4 -> V_171 ) ) / V_173 ;
else
V_161 -> V_166 = 32768 ;
return 0 ;
}
case V_174 :
if ( ! ( V_30 -> V_164 & V_175 ) )
break;
V_161 -> V_166 = V_4 -> V_176 ;
return 0 ;
case V_177 :
if ( ! ( V_30 -> V_164 & V_175 ) )
break;
V_161 -> V_166 = V_4 -> V_178 ;
return 0 ;
}
return - V_13 ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_160 * V_161 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_4 -> V_30 ;
switch ( V_161 -> V_162 ) {
case V_163 :
if ( ! ( V_30 -> V_164 & V_165 ) )
break;
if ( V_161 -> V_166 < 0 || V_161 -> V_166 >= 2 )
return - V_179 ;
V_4 -> V_167 = V_161 -> V_166 ;
if ( V_4 -> V_167 )
F_10 ( V_4 , V_30 -> V_180 , V_30 -> V_181 , V_30 -> V_182 ) ;
else
F_10 ( V_4 , V_30 -> V_180 ,
V_30 -> V_183 [ V_4 -> V_184 ] , V_30 -> V_182 ) ;
return 0 ;
case V_168 :
{
int V_173 , V_185 ;
if ( ! ( V_30 -> V_164 & V_169 ) )
break;
V_173 = F_46 ( V_4 -> V_170 , V_4 -> V_171 ) ;
if ( V_173 )
V_185 = ( 32768 * F_61 ( V_4 -> V_170 , V_4 -> V_171 ) ) / V_173 ;
else
V_185 = 32768 ;
V_173 = V_161 -> V_166 ;
V_4 -> V_170 = ( F_61 ( 65536 - V_185 , 32768 ) * V_173 ) / 32768 ;
V_4 -> V_171 = ( F_61 ( V_185 , V_173 * ( V_186 ) 32768 ) ) / 32768 ;
F_3 ( V_4 , V_30 -> V_187 , V_30 -> V_188 ( V_4 -> V_170 ) ) ;
F_3 ( V_4 , V_30 -> V_189 , V_30 -> V_188 ( V_4 -> V_171 ) ) ;
return 0 ;
}
case V_172 :
{
int V_173 , V_185 ;
if ( ! ( V_30 -> V_164 & V_169 ) )
break;
V_173 = F_46 ( V_4 -> V_170 , V_4 -> V_171 ) ;
V_185 = V_161 -> V_166 ;
V_4 -> V_170 = ( F_61 ( 65536 - V_185 , 32768 ) * V_173 ) / 32768 ;
V_4 -> V_171 = ( F_61 ( V_185 , V_173 * ( V_186 ) 32768 ) ) / 32768 ;
F_3 ( V_4 , V_30 -> V_187 , V_30 -> V_188 ( V_4 -> V_170 ) ) ;
F_3 ( V_4 , V_30 -> V_189 , V_30 -> V_188 ( V_4 -> V_171 ) ) ;
return 0 ;
}
case V_174 :
if ( ! ( V_30 -> V_164 & V_175 ) )
break;
V_4 -> V_176 = V_161 -> V_166 ;
F_3 ( V_4 , V_30 -> V_190 , V_30 -> V_191 ( V_4 -> V_176 ) ) ;
return 0 ;
case V_177 :
if ( ! ( V_30 -> V_164 & V_175 ) )
break;
V_4 -> V_178 = V_161 -> V_166 ;
F_3 ( V_4 , V_30 -> V_192 , V_30 -> V_193 ( V_4 -> V_178 ) ) ;
return 0 ;
}
return - V_13 ;
}
static int F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_34 = 1 ;
V_4 -> V_194 = 0 ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 , struct V_195 * V_196 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_4 -> V_30 ;
switch ( V_196 -> V_162 ) {
case V_163 :
if ( V_30 -> V_164 & V_165 )
return F_65 ( V_196 , 0 , 1 , 1 , 0 ) ;
break;
case V_168 :
if ( V_30 -> V_164 & V_169 )
return F_65 ( V_196 , 0 , 65535 , 65535 / 100 , 58880 ) ;
break;
case V_172 :
if ( V_30 -> V_164 & V_169 )
return F_65 ( V_196 , 0 , 65535 , 65535 / 100 , 32768 ) ;
break;
case V_174 :
case V_177 :
if ( V_30 -> V_164 & V_175 )
return F_65 ( V_196 , 0 , 65535 , 65535 / 100 , 32768 ) ;
break;
default:
break;
}
return - V_13 ;
}
static int F_66 ( struct V_2 * V_3 ,
T_2 V_184 , T_2 V_197 , T_2 V_198 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_4 -> V_30 ;
if ( ! ( V_30 -> V_164 & V_165 ) )
return 0 ;
if ( V_184 >= 4 )
return - V_13 ;
V_4 -> V_184 = V_184 ;
if ( V_4 -> V_167 )
return 0 ;
F_10 ( V_4 , V_30 -> V_180 ,
V_30 -> V_183 [ V_4 -> V_184 ] , V_30 -> V_182 ) ;
return 0 ;
}
static int F_67 ( struct V_2 * V_3 , struct V_199 * V_200 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_4 -> V_30 ;
int V_31 = 0 ;
if ( ! V_30 -> V_38 )
return 0 ;
if ( V_4 -> V_34 )
return 0 ;
switch ( V_200 -> V_201 ) {
case V_42 :
case V_37 :
case V_40 :
case V_41 :
V_31 = V_200 -> V_201 ;
break;
case V_39 :
V_31 = V_37 ;
break;
default:
return - V_13 ;
}
V_4 -> V_201 = V_200 -> V_201 ;
if ( V_31 ) {
V_4 -> V_194 = 0 ;
V_4 -> V_31 = V_31 ;
V_30 -> V_38 ( V_4 , V_31 ) ;
}
return 0 ;
}
static int F_68 ( struct V_2 * V_3 , struct V_199 * V_200 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_4 -> V_30 ;
int V_31 = V_42 ;
if ( ! V_30 -> V_35 )
return 0 ;
if ( V_4 -> V_34 )
return 0 ;
V_200 -> V_201 = V_4 -> V_201 ;
V_200 -> V_202 = 0 ;
V_200 -> V_203 = V_204 |
V_205 | V_206 ;
V_31 = V_30 -> V_35 ( V_4 ) ;
if ( V_31 & V_42 )
V_200 -> V_202 |= V_207 ;
if ( V_31 & V_37 )
V_200 -> V_202 |= V_208 ;
if ( V_31 & V_40 )
V_200 -> V_202 = V_209 |
V_210 ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 , T_3 V_211 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_34 = 0 ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 , struct V_212 * V_213 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_4 -> V_30 ;
V_4 -> V_31 = 0 ;
if ( V_4 -> V_28 ) {
V_30 -> V_38 ( V_4 , V_42 ) ;
if ( V_4 -> V_36 != V_42 )
V_4 -> V_36 = - 1 ;
F_25 ( & V_4 -> V_43 , V_44 + F_26 ( 2000 ) ) ;
}
return 0 ;
}
static int F_71 ( struct V_2 * V_3 , struct V_214 * V_4 )
{
struct V_7 * V_215 = F_4 ( V_3 ) ;
return F_72 ( V_215 , V_4 , V_216 , 0 ) ;
}
static int F_73 ( struct V_7 * V_215 , const struct V_217 * V_162 )
{
struct V_1 * V_4 ;
struct V_29 * V_30 ;
struct V_2 * V_3 ;
if ( V_10 ) {
F_16 ( V_218 L_39 ) ;
F_16 ( V_218 L_40 ) ;
for ( V_30 = V_219 ; V_30 -> V_22 != NULL ; V_30 ++ )
F_16 ( L_41 , ( V_30 == V_219 ) ? L_35 : L_42 , V_30 -> V_22 ) ;
F_16 ( L_13 ) ;
}
V_4 = F_74 ( sizeof( * V_4 ) , V_220 ) ;
if ( ! V_4 )
return - V_221 ;
V_3 = & V_4 -> V_3 ;
F_75 ( V_3 , V_215 , & V_222 ) ;
F_5 ( 1 , V_10 , V_3 , L_43 , V_215 -> V_19 << 1 ) ;
for ( V_30 = V_219 ; V_30 -> V_22 != NULL ; V_30 ++ ) {
if ( 0 == * ( V_30 -> V_223 ) )
continue;
if ( V_215 -> V_19 < V_30 -> V_224 ||
V_215 -> V_19 > V_30 -> V_225 )
continue;
if ( V_30 -> V_226 && ! V_30 -> V_226 ( V_4 ) )
continue;
break;
}
if ( V_30 -> V_22 == NULL ) {
F_5 ( 1 , V_10 , V_3 , L_44 ) ;
F_76 ( V_4 ) ;
return - V_227 ;
}
F_9 ( V_3 , L_45 , V_30 -> V_22 , V_215 -> V_19 << 1 , V_215 -> V_21 -> V_22 ) ;
if ( V_30 -> V_164 ) {
F_5 ( 1 , V_10 , V_3 , L_46 ,
( V_30 -> V_164 & V_169 ) ? L_47 : L_35 ,
( V_30 -> V_164 & V_175 ) ? L_48 : L_35 ,
( V_30 -> V_164 & V_165 ) ? L_49 : L_35 ) ;
}
if ( ! V_162 )
F_77 ( V_215 -> V_22 , V_30 -> V_22 , V_228 ) ;
V_4 -> V_30 = V_30 ;
V_4 -> V_11 . V_25 = V_30 -> V_229 + 1 ;
V_4 -> V_36 = - 1 ;
V_4 -> V_201 = V_40 ;
if ( V_30 -> V_230 != NULL )
V_30 -> V_230 ( V_4 ) ;
else
F_15 ( V_4 , L_50 , & V_30 -> V_231 ) ;
if ( V_30 -> V_164 & V_169 ) {
if ( ! V_30 -> V_188 ) {
F_9 ( V_3 , L_51 ) ;
V_30 -> V_164 &= ~ V_169 ;
} else {
V_4 -> V_170 = V_30 -> V_232 ? V_30 -> V_232 : 65535 ;
V_4 -> V_171 = V_30 -> V_233 ? V_30 -> V_233 : 65535 ;
F_3 ( V_4 , V_30 -> V_187 ,
V_30 -> V_188 ( V_4 -> V_170 ) ) ;
F_3 ( V_4 , V_30 -> V_189 ,
V_30 -> V_188 ( V_4 -> V_171 ) ) ;
}
}
if ( V_30 -> V_164 & V_175 ) {
if ( ! V_30 -> V_191 || ! V_30 -> V_193 ) {
F_9 ( V_3 , L_52 ) ;
V_30 -> V_164 &= ~ V_175 ;
} else {
V_4 -> V_178 = V_30 -> V_234 ?
V_30 -> V_234 : 32768 ;
V_4 -> V_176 = V_30 -> V_235 ?
V_30 -> V_235 : 32768 ;
F_3 ( V_4 , V_30 -> V_190 ,
V_30 -> V_191 ( V_4 -> V_176 ) ) ;
F_3 ( V_4 , V_30 -> V_192 ,
V_30 -> V_193 ( V_4 -> V_178 ) ) ;
}
}
V_4 -> V_28 = NULL ;
F_78 ( & V_4 -> V_43 ) ;
if ( V_30 -> V_164 & V_236 ) {
if ( ! V_30 -> V_35 || ! V_30 -> V_38 ) {
F_9 ( V_3 , L_53 ) ;
return 0 ;
}
V_4 -> V_43 . V_237 = F_17 ;
V_4 -> V_43 . V_27 = ( unsigned long ) V_4 ;
V_4 -> V_28 = F_79 ( F_19 , V_4 , V_215 -> V_22 ) ;
if ( F_80 ( V_4 -> V_28 ) ) {
F_7 ( V_3 , L_54 ) ;
V_4 -> V_28 = NULL ;
}
}
return 0 ;
}
static int F_81 ( struct V_7 * V_215 )
{
struct V_2 * V_3 = F_82 ( V_215 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_83 ( & V_4 -> V_43 ) ;
if ( V_4 -> V_28 ) {
F_84 ( V_4 -> V_28 ) ;
V_4 -> V_28 = NULL ;
}
F_85 ( V_3 ) ;
F_76 ( V_4 ) ;
return 0 ;
}

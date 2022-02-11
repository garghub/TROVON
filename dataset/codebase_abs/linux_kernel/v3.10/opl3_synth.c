int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
return 0 ;
}
int F_2 ( struct V_1 * V_2 , struct V_3 * V_3 ,
unsigned int V_4 , unsigned long V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
void T_1 * V_9 = ( void T_1 * ) V_5 ;
if ( F_3 ( ! V_7 ) )
return - V_10 ;
switch ( V_4 ) {
case V_11 :
{
struct V_12 V_13 ;
V_13 . V_14 = V_7 -> V_14 ;
V_13 . V_15 = V_7 -> V_15 ;
if ( F_4 ( V_9 , & V_13 , sizeof( struct V_12 ) ) )
return - V_16 ;
return 0 ;
}
case V_17 :
#ifdef F_5
case V_18 :
#endif
F_6 ( V_7 ) ;
return 0 ;
case V_19 :
#ifdef F_5
case V_20 :
#endif
{
struct V_21 V_22 ;
if ( F_7 ( & V_22 , V_9 , sizeof( struct V_21 ) ) )
return - V_16 ;
return F_8 ( V_7 , & V_22 ) ;
}
case V_23 :
#ifdef F_5
case V_24 :
#endif
{
struct V_25 V_26 ;
if ( F_7 ( & V_26 , V_9 , sizeof( struct V_25 ) ) )
return - V_16 ;
return F_9 ( V_7 , & V_26 ) ;
}
case V_27 :
#ifdef F_5
case V_28 :
#endif
{
struct V_29 V_30 ;
if ( F_7 ( & V_30 , V_9 , sizeof( struct V_29 ) ) )
return - V_16 ;
return F_10 ( V_7 , & V_30 ) ;
}
case V_31 :
#ifdef F_5
case V_32 :
#endif
return F_11 ( V_7 , ( int ) V_5 ) ;
case V_33 :
#ifdef F_5
case V_34 :
#endif
return F_12 ( V_7 , ( int ) V_5 ) ;
#ifdef F_13
case V_35 :
F_14 ( V_7 ) ;
return 0 ;
#endif
#ifdef F_15
default:
F_16 ( V_36 L_1 , V_4 ) ;
#endif
}
return - V_37 ;
}
int F_17 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_6 ( V_7 ) ;
return 0 ;
}
long F_18 ( struct V_1 * V_2 , const char T_1 * V_38 , long V_39 ,
T_2 * V_40 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
long V_41 = 0 ;
int V_42 = 0 ;
struct V_43 V_44 ;
while ( V_39 >= sizeof( V_44 ) ) {
unsigned char type ;
if ( F_7 ( & V_44 , V_38 , sizeof( V_44 ) ) )
return - V_16 ;
if ( ! memcmp ( V_44 . V_45 , V_46 , 4 ) ||
! memcmp ( V_44 . V_45 , V_47 , 4 ) )
type = V_48 ;
else if ( ! memcmp ( V_44 . V_45 , V_49 , 4 ) )
type = V_50 ;
else
break;
V_42 = F_19 ( V_7 , V_44 . V_51 , V_44 . V_52 , type ,
V_44 . V_53 , V_44 . V_54 ,
V_44 . V_55 ) ;
if ( V_42 < 0 )
break;
V_41 += sizeof( V_44 ) ;
V_39 -= sizeof( V_44 ) ;
}
return V_41 > 0 ? V_41 : V_42 ;
}
int F_19 ( struct V_6 * V_7 ,
int V_51 , int V_52 , int type ,
const char * V_53 ,
const unsigned char * V_56 ,
const unsigned char * V_55 )
{
struct V_57 * V_58 ;
int V_59 ;
V_58 = F_20 ( V_7 , V_51 , V_52 , 1 ) ;
if ( ! V_58 )
return - V_60 ;
V_58 -> type = type ;
for ( V_59 = 0 ; V_59 < 2 ; V_59 ++ ) {
V_58 -> V_44 . V_61 [ V_59 ] . V_62 = V_55 [ V_63 + V_59 ] ;
V_58 -> V_44 . V_61 [ V_59 ] . V_64 = V_55 [ V_65 + V_59 ] ;
V_58 -> V_44 . V_61 [ V_59 ] . V_66 = V_55 [ V_67 + V_59 ] ;
V_58 -> V_44 . V_61 [ V_59 ] . V_68 = V_55 [ V_69 + V_59 ] ;
V_58 -> V_44 . V_61 [ V_59 ] . V_70 = V_55 [ V_71 + V_59 ] ;
}
V_58 -> V_44 . V_72 [ 0 ] = V_55 [ V_73 ] ;
if ( type == V_50 ) {
for ( V_59 = 0 ; V_59 < 2 ; V_59 ++ ) {
V_58 -> V_44 . V_61 [ V_59 + 2 ] . V_62 =
V_55 [ V_74 + V_63 + V_59 ] ;
V_58 -> V_44 . V_61 [ V_59 + 2 ] . V_64 =
V_55 [ V_74 + V_65 + V_59 ] ;
V_58 -> V_44 . V_61 [ V_59 + 2 ] . V_66 =
V_55 [ V_74 + V_67 + V_59 ] ;
V_58 -> V_44 . V_61 [ V_59 + 2 ] . V_68 =
V_55 [ V_74 + V_69 + V_59 ] ;
V_58 -> V_44 . V_61 [ V_59 + 2 ] . V_70 =
V_55 [ V_74 + V_71 + V_59 ] ;
}
V_58 -> V_44 . V_72 [ 1 ] =
V_55 [ V_74 + V_73 ] ;
}
if ( V_56 ) {
V_58 -> V_44 . V_75 = V_56 [ 0 ] ;
V_58 -> V_44 . V_76 = V_56 [ 1 ] ;
V_58 -> V_44 . V_77 = V_56 [ 2 ] ;
V_58 -> V_44 . V_78 = V_56 [ 3 ] ;
V_58 -> V_44 . V_79 = V_56 [ 4 ] ;
V_58 -> V_44 . V_80 = V_56 [ 5 ] ;
V_58 -> V_44 . V_81 = V_56 [ 6 ] ;
}
if ( V_53 )
F_21 ( V_58 -> V_53 , V_53 , sizeof( V_58 -> V_53 ) ) ;
return 0 ;
}
struct V_57 * F_20 ( struct V_6 * V_7 , int V_51 , int V_52 ,
int V_82 )
{
unsigned int V_45 = ( V_51 + V_52 ) % V_83 ;
struct V_57 * V_58 ;
for ( V_58 = V_7 -> V_84 [ V_45 ] ; V_58 ; V_58 = V_58 -> V_85 ) {
if ( V_58 -> V_51 == V_51 && V_58 -> V_52 == V_52 )
return V_58 ;
}
if ( ! V_82 )
return NULL ;
V_58 = F_22 ( sizeof( * V_58 ) , V_86 ) ;
if ( ! V_58 )
return NULL ;
V_58 -> V_51 = V_51 ;
V_58 -> V_52 = V_52 ;
V_58 -> V_85 = V_7 -> V_84 [ V_45 ] ;
V_7 -> V_84 [ V_45 ] = V_58 ;
return V_58 ;
}
void F_14 ( struct V_6 * V_7 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_83 ; V_59 ++ ) {
struct V_57 * V_58 , * V_85 ;
for ( V_58 = V_7 -> V_84 [ V_59 ] ; V_58 ; V_58 = V_85 ) {
V_85 = V_58 -> V_85 ;
F_23 ( V_58 ) ;
}
}
memset ( V_7 -> V_84 , 0 , sizeof( V_7 -> V_84 ) ) ;
}
void F_6 ( struct V_6 * V_7 )
{
unsigned short V_87 ;
unsigned short V_88 ;
unsigned char V_89 ;
int V_90 , V_59 ;
V_90 = ( V_7 -> V_91 < V_92 ) ?
V_93 : V_94 ;
for ( V_59 = 0 ; V_59 < V_90 ; V_59 ++ ) {
if ( V_59 < V_93 ) {
V_88 = V_95 ;
V_89 = V_59 ;
} else {
V_88 = V_96 ;
V_89 = V_59 - V_93 ;
}
V_87 = V_88 | ( V_97 + V_98 [ V_89 ] [ 0 ] ) ;
V_7 -> V_99 ( V_7 , V_87 , V_100 ) ;
V_87 = V_88 | ( V_97 + V_98 [ V_89 ] [ 1 ] ) ;
V_7 -> V_99 ( V_7 , V_87 , V_100 ) ;
V_87 = V_88 | ( V_101 + V_89 ) ;
V_7 -> V_99 ( V_7 , V_87 , 0x00 ) ;
}
V_7 -> V_90 = V_93 ;
V_7 -> V_14 = V_102 ;
V_7 -> V_99 ( V_7 , V_95 | V_103 , V_104 ) ;
V_7 -> V_99 ( V_7 , V_95 | V_105 , 0x00 ) ;
V_7 -> V_15 = 0 ;
}
static int F_8 ( struct V_6 * V_7 , struct V_21 * V_22 )
{
unsigned short V_88 ;
unsigned char V_89 ;
unsigned short V_87 ;
unsigned char V_106 ;
if ( V_22 -> V_26 >= ( ( V_7 -> V_14 == V_107 ) ?
V_94 : V_93 ) )
return - V_10 ;
if ( V_22 -> V_26 < V_93 ) {
V_88 = V_95 ;
V_89 = V_22 -> V_26 ;
} else {
V_88 = V_96 ;
V_89 = V_22 -> V_26 - V_93 ;
}
V_106 = ( unsigned char ) V_22 -> V_108 ;
V_87 = V_88 | ( V_109 + V_89 ) ;
V_7 -> V_99 ( V_7 , V_87 , V_106 ) ;
V_106 = 0x00 ;
if ( V_22 -> V_110 )
V_106 |= V_111 ;
V_106 |= ( V_22 -> V_112 << 2 ) & V_113 ;
V_106 |= ( unsigned char ) ( V_22 -> V_108 >> 8 ) & V_114 ;
V_87 = V_88 | ( V_101 + V_89 ) ;
V_7 -> V_99 ( V_7 , V_87 , V_106 ) ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 , struct V_25 * V_26 )
{
unsigned short V_88 ;
unsigned char V_115 ;
unsigned char V_89 ;
unsigned short V_87 ;
unsigned char V_106 ;
if ( V_26 -> V_61 > 1 )
return - V_10 ;
if ( V_26 -> V_26 >= ( ( V_7 -> V_14 == V_107 ) ?
V_94 : V_93 ) )
return - V_10 ;
if ( V_26 -> V_26 < V_93 ) {
V_88 = V_95 ;
V_89 = V_26 -> V_26 ;
} else {
V_88 = V_96 ;
V_89 = V_26 -> V_26 - V_93 ;
}
V_115 = V_98 [ V_89 ] [ V_26 -> V_61 ] ;
V_106 = 0x00 ;
if ( V_26 -> V_116 )
V_106 |= V_117 ;
if ( V_26 -> V_118 )
V_106 |= V_119 ;
if ( V_26 -> V_120 )
V_106 |= V_121 ;
if ( V_26 -> V_122 )
V_106 |= V_123 ;
V_106 |= V_26 -> V_124 & V_125 ;
V_87 = V_88 | ( V_126 + V_115 ) ;
V_7 -> V_99 ( V_7 , V_87 , V_106 ) ;
V_106 = ( V_26 -> V_127 << 6 ) & V_128 ;
V_106 |= ~ V_26 -> V_129 & V_100 ;
V_87 = V_88 | ( V_97 + V_115 ) ;
V_7 -> V_99 ( V_7 , V_87 , V_106 ) ;
V_106 = ( V_26 -> V_130 << 4 ) & V_131 ;
V_106 |= V_26 -> V_132 & V_133 ;
V_87 = V_88 | ( V_134 + V_115 ) ;
V_7 -> V_99 ( V_7 , V_87 , V_106 ) ;
V_106 = ( V_26 -> V_135 << 4 ) & V_136 ;
V_106 |= V_26 -> V_137 & V_138 ;
V_87 = V_88 | ( V_139 + V_115 ) ;
V_7 -> V_99 ( V_7 , V_87 , V_106 ) ;
V_106 = ( V_26 -> V_140 << 1 ) & V_141 ;
if ( V_26 -> V_142 )
V_106 |= V_143 ;
if ( V_7 -> V_14 == V_107 ) {
if ( V_26 -> V_144 )
V_106 |= V_145 ;
if ( V_26 -> V_146 )
V_106 |= V_147 ;
}
V_87 = V_88 | ( V_148 + V_89 ) ;
V_7 -> V_99 ( V_7 , V_87 , V_106 ) ;
V_106 = V_26 -> V_149 & V_150 ;
V_87 = V_88 | ( V_151 + V_115 ) ;
V_7 -> V_99 ( V_7 , V_87 , V_106 ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
unsigned char V_106 ;
V_106 = 0x00 ;
if ( V_30 -> V_152 )
V_106 |= V_153 ;
V_7 -> V_99 ( V_7 , V_95 | V_154 , V_106 ) ;
V_106 = 0x00 ;
if ( V_30 -> V_155 )
V_106 |= V_156 ;
if ( V_30 -> V_157 )
V_106 |= V_158 ;
if ( V_30 -> V_15 ) {
V_106 |= V_159 ;
V_7 -> V_15 = 1 ;
} else {
V_7 -> V_15 = 0 ;
}
if ( V_30 -> V_160 )
V_106 |= V_161 ;
if ( V_30 -> V_162 )
V_106 |= V_163 ;
if ( V_30 -> V_164 )
V_106 |= V_165 ;
if ( V_30 -> V_166 )
V_106 |= V_167 ;
if ( V_30 -> V_168 )
V_106 |= V_169 ;
V_7 -> V_99 ( V_7 , V_95 | V_105 , V_106 ) ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 , int V_170 )
{
if ( ( V_170 == V_107 ) && ( V_7 -> V_91 < V_92 ) )
return - V_10 ;
V_7 -> V_14 = V_170 ;
if ( V_7 -> V_91 >= V_92 )
V_7 -> V_99 ( V_7 , V_96 | V_171 , 0x00 ) ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 , int V_142 )
{
unsigned char V_106 ;
if ( V_7 -> V_14 != V_107 )
return - V_10 ;
V_106 = V_142 & ( V_172 | V_173 | V_174 |
V_175 | V_176 | V_177 ) ;
V_7 -> V_99 ( V_7 , V_96 | V_171 , V_106 ) ;
return 0 ;
}

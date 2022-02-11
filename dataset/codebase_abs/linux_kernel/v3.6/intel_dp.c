static bool F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 . type == V_3 ;
}
static bool F_2 ( struct V_1 * V_1 )
{
return V_1 -> F_2 ;
}
static bool F_3 ( struct V_1 * V_1 )
{
return F_1 ( V_1 ) && ! F_2 ( V_1 ) ;
}
static struct V_1 * F_4 ( struct V_4 * V_5 )
{
return F_5 ( V_5 , struct V_1 , V_2 . V_2 ) ;
}
static struct V_1 * F_6 ( struct V_6 * V_7 )
{
return F_5 ( F_7 ( V_7 ) ,
struct V_1 , V_2 ) ;
}
bool F_8 ( struct V_4 * V_5 )
{
struct V_1 * V_1 ;
if ( ! V_5 )
return false ;
V_1 = F_4 ( V_5 ) ;
return F_2 ( V_1 ) ;
}
void
F_9 ( struct V_8 * V_8 ,
int * V_9 , int * V_10 )
{
struct V_1 * V_1 = F_5 ( V_8 , struct V_1 , V_2 ) ;
* V_9 = V_1 -> V_11 ;
if ( V_1 -> V_10 == V_12 )
* V_10 = 162000 ;
else if ( V_1 -> V_10 == V_13 )
* V_10 = 270000 ;
}
int
F_10 ( struct V_8 * V_8 ,
struct V_14 * V_15 )
{
struct V_1 * V_1 = F_5 ( V_8 , struct V_1 , V_2 ) ;
if ( V_1 -> V_16 )
return V_1 -> V_16 -> clock ;
else
return V_15 -> clock ;
}
static int
F_11 ( struct V_1 * V_1 )
{
int V_17 = V_1 -> V_18 [ V_19 ] & 0x1f ;
switch ( V_17 ) {
case 1 : case 2 : case 4 :
break;
default:
V_17 = 4 ;
}
return V_17 ;
}
static int
F_12 ( struct V_1 * V_1 )
{
int V_20 = V_1 -> V_18 [ V_21 ] ;
switch ( V_20 ) {
case V_12 :
case V_13 :
break;
default:
V_20 = V_12 ;
break;
}
return V_20 ;
}
static int
F_13 ( T_1 V_10 )
{
if ( V_10 == V_13 )
return 270000 ;
else
return 162000 ;
}
static int
F_14 ( int V_22 , int V_23 )
{
return ( V_22 * V_23 + 9 ) / 10 ;
}
static int
F_15 ( int V_24 , int V_25 )
{
return ( V_24 * V_25 * 8 ) / 10 ;
}
static bool
F_16 ( struct V_1 * V_1 ,
struct V_14 * V_15 ,
bool V_26 )
{
int V_24 = F_13 ( F_12 ( V_1 ) ) ;
int V_25 = F_11 ( V_1 ) ;
int V_27 , V_28 ;
V_28 = F_14 ( V_15 -> clock , 24 ) ;
V_27 = F_15 ( V_24 , V_25 ) ;
if ( V_28 > V_27 ) {
V_28 = F_14 ( V_15 -> clock , 18 ) ;
if ( V_28 > V_27 )
return false ;
if ( V_26 )
V_15 -> V_29
|= V_30 ;
return true ;
}
return true ;
}
static int
F_17 ( struct V_6 * V_7 ,
struct V_14 * V_15 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
if ( F_1 ( V_1 ) && V_1 -> V_16 ) {
if ( V_15 -> V_31 > V_1 -> V_16 -> V_31 )
return V_32 ;
if ( V_15 -> V_33 > V_1 -> V_16 -> V_33 )
return V_32 ;
}
if ( ! F_16 ( V_1 , V_15 , false ) )
return V_34 ;
if ( V_15 -> clock < 10000 )
return V_35 ;
if ( V_15 -> V_36 & V_37 )
return V_38 ;
return V_39 ;
}
static T_2
F_18 ( T_1 * V_40 , int V_41 )
{
int V_42 ;
T_2 V_43 = 0 ;
if ( V_41 > 4 )
V_41 = 4 ;
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ )
V_43 |= ( ( T_2 ) V_40 [ V_42 ] ) << ( ( 3 - V_42 ) * 8 ) ;
return V_43 ;
}
static void
F_19 ( T_2 V_40 , T_1 * V_44 , int V_45 )
{
int V_42 ;
if ( V_45 > 4 )
V_45 = 4 ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ )
V_44 [ V_42 ] = V_40 >> ( ( 3 - V_42 ) * 8 ) ;
}
static int
F_20 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_51 ;
V_51 = F_21 ( V_52 ) ;
switch ( V_51 & V_53 ) {
case V_54 :
return 100 ;
case V_55 :
return 133 ;
case V_56 :
return 166 ;
case V_57 :
return 200 ;
case V_58 :
return 266 ;
case V_59 :
return 333 ;
case V_60 :
case V_61 :
return 400 ;
default:
return 133 ;
}
}
static bool F_22 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
return ( F_21 ( V_62 ) & V_63 ) != 0 ;
}
static bool F_23 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
return ( F_21 ( V_64 ) & V_65 ) != 0 ;
}
static void
F_24 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_22 ( V_1 ) && ! F_23 ( V_1 ) ) {
F_25 ( 1 , L_1 ) ;
F_26 ( L_2 ,
F_21 ( V_62 ) ,
F_21 ( V_64 ) ) ;
}
}
static int
F_27 ( struct V_1 * V_1 ,
T_1 * V_66 , int V_67 ,
T_1 * V_68 , int V_69 )
{
T_2 V_70 = V_1 -> V_70 ;
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_71 = V_70 + 0x10 ;
T_2 V_72 = V_71 + 4 ;
int V_42 ;
int V_73 ;
T_2 V_74 ;
T_2 V_75 ;
int V_76 , V_77 ;
F_24 ( V_1 ) ;
if ( F_3 ( V_1 ) ) {
if ( F_28 ( V_47 ) || F_29 ( V_47 ) )
V_75 = 200 ;
else
V_75 = 225 ;
} else if ( F_30 ( V_47 ) )
V_75 = 63 ;
else
V_75 = F_20 ( V_47 ) / 2 ;
if ( F_28 ( V_47 ) )
V_77 = 3 ;
else
V_77 = 5 ;
for ( V_76 = 0 ; V_76 < 3 ; V_76 ++ ) {
V_74 = F_21 ( V_71 ) ;
if ( ( V_74 & V_78 ) == 0 )
break;
F_31 ( 1 ) ;
}
if ( V_76 == 3 ) {
F_25 ( 1 , L_3 ,
F_21 ( V_71 ) ) ;
return - V_79 ;
}
for ( V_76 = 0 ; V_76 < 5 ; V_76 ++ ) {
for ( V_42 = 0 ; V_42 < V_67 ; V_42 += 4 )
F_32 ( V_72 + V_42 ,
F_18 ( V_66 + V_42 , V_67 - V_42 ) ) ;
F_32 ( V_71 ,
V_78 |
V_80 |
( V_67 << V_81 ) |
( V_77 << V_82 ) |
( V_75 << V_83 ) |
V_84 |
V_85 |
V_86 ) ;
for (; ; ) {
V_74 = F_21 ( V_71 ) ;
if ( ( V_74 & V_78 ) == 0 )
break;
F_33 ( 100 ) ;
}
F_32 ( V_71 ,
V_74 |
V_84 |
V_85 |
V_86 ) ;
if ( V_74 & ( V_85 |
V_86 ) )
continue;
if ( V_74 & V_84 )
break;
}
if ( ( V_74 & V_84 ) == 0 ) {
F_34 ( L_4 , V_74 ) ;
return - V_79 ;
}
if ( V_74 & V_86 ) {
F_34 ( L_5 , V_74 ) ;
return - V_87 ;
}
if ( V_74 & V_85 ) {
F_26 ( L_6 , V_74 ) ;
return - V_88 ;
}
V_73 = ( ( V_74 & V_89 ) >>
V_81 ) ;
if ( V_73 > V_69 )
V_73 = V_69 ;
for ( V_42 = 0 ; V_42 < V_73 ; V_42 += 4 )
F_19 ( F_21 ( V_72 + V_42 ) ,
V_68 + V_42 , V_73 - V_42 ) ;
return V_73 ;
}
static int
F_35 ( struct V_1 * V_1 ,
T_3 V_90 , T_1 * V_66 , int V_67 )
{
int V_91 ;
T_1 V_92 [ 20 ] ;
int V_93 ;
T_1 V_94 ;
F_24 ( V_1 ) ;
if ( V_67 > 16 )
return - 1 ;
V_92 [ 0 ] = V_95 << 4 ;
V_92 [ 1 ] = V_90 >> 8 ;
V_92 [ 2 ] = V_90 & 0xff ;
V_92 [ 3 ] = V_67 - 1 ;
memcpy ( & V_92 [ 4 ] , V_66 , V_67 ) ;
V_93 = V_67 + 4 ;
for (; ; ) {
V_91 = F_27 ( V_1 , V_92 , V_93 , & V_94 , 1 ) ;
if ( V_91 < 0 )
return V_91 ;
if ( ( V_94 & V_96 ) == V_97 )
break;
else if ( ( V_94 & V_96 ) == V_98 )
F_33 ( 100 ) ;
else
return - V_87 ;
}
return V_67 ;
}
static int
F_36 ( struct V_1 * V_1 ,
T_3 V_90 , T_1 V_99 )
{
return F_35 ( V_1 , V_90 , & V_99 , 1 ) ;
}
static int
F_37 ( struct V_1 * V_1 ,
T_3 V_90 , T_1 * V_68 , int V_73 )
{
T_1 V_92 [ 4 ] ;
int V_93 ;
T_1 V_100 [ 20 ] ;
int V_101 ;
T_1 V_94 ;
int V_91 ;
F_24 ( V_1 ) ;
V_92 [ 0 ] = V_102 << 4 ;
V_92 [ 1 ] = V_90 >> 8 ;
V_92 [ 2 ] = V_90 & 0xff ;
V_92 [ 3 ] = V_73 - 1 ;
V_93 = 4 ;
V_101 = V_73 + 1 ;
for (; ; ) {
V_91 = F_27 ( V_1 , V_92 , V_93 ,
V_100 , V_101 ) ;
if ( V_91 == 0 )
return - V_103 ;
if ( V_91 < 0 )
return V_91 ;
V_94 = V_100 [ 0 ] ;
if ( ( V_94 & V_96 ) == V_97 ) {
memcpy ( V_68 , V_100 + 1 , V_91 - 1 ) ;
return V_91 - 1 ;
}
else if ( ( V_94 & V_96 ) == V_98 )
F_33 ( 100 ) ;
else
return - V_87 ;
}
}
static int
F_38 ( struct V_104 * V_105 , int V_15 ,
T_1 V_106 , T_1 * V_107 )
{
struct V_108 * V_109 = V_105 -> V_109 ;
struct V_1 * V_1 = F_5 ( V_105 ,
struct V_1 ,
V_105 ) ;
T_3 V_90 = V_109 -> V_90 ;
T_1 V_92 [ 5 ] ;
T_1 V_100 [ 2 ] ;
unsigned V_110 ;
int V_93 ;
int V_101 ;
int V_91 ;
F_24 ( V_1 ) ;
if ( V_15 & V_111 )
V_92 [ 0 ] = V_112 << 4 ;
else
V_92 [ 0 ] = V_113 << 4 ;
if ( ! ( V_15 & V_114 ) )
V_92 [ 0 ] |= V_115 << 4 ;
V_92 [ 1 ] = V_90 >> 8 ;
V_92 [ 2 ] = V_90 ;
switch ( V_15 ) {
case V_116 :
V_92 [ 3 ] = 0 ;
V_92 [ 4 ] = V_106 ;
V_93 = 5 ;
V_101 = 1 ;
break;
case V_111 :
V_92 [ 3 ] = 0 ;
V_93 = 4 ;
V_101 = 2 ;
break;
default:
V_93 = 3 ;
V_101 = 1 ;
break;
}
for ( V_110 = 0 ; V_110 < 5 ; V_110 ++ ) {
V_91 = F_27 ( V_1 ,
V_92 , V_93 ,
V_100 , V_101 ) ;
if ( V_91 < 0 ) {
F_26 ( L_7 , V_91 ) ;
return V_91 ;
}
switch ( V_100 [ 0 ] & V_96 ) {
case V_97 :
break;
case V_117 :
F_26 ( L_8 ) ;
return - V_118 ;
case V_98 :
F_33 ( 100 ) ;
continue;
default:
F_34 ( L_9 ,
V_100 [ 0 ] ) ;
return - V_118 ;
}
switch ( V_100 [ 0 ] & V_119 ) {
case V_120 :
if ( V_15 == V_111 ) {
* V_107 = V_100 [ 1 ] ;
}
return V_101 - 1 ;
case V_121 :
F_26 ( L_10 ) ;
return - V_118 ;
case V_122 :
F_26 ( L_11 ) ;
F_33 ( 100 ) ;
break;
default:
F_34 ( L_12 , V_100 [ 0 ] ) ;
return - V_118 ;
}
}
F_34 ( L_13 ) ;
return - V_118 ;
}
static int
F_39 ( struct V_1 * V_1 ,
struct V_123 * V_123 , const char * V_124 )
{
int V_91 ;
F_26 ( L_14 , V_124 ) ;
V_1 -> V_125 . V_126 = false ;
V_1 -> V_125 . V_90 = 0 ;
V_1 -> V_125 . V_127 = F_38 ;
memset ( & V_1 -> V_105 , '\0' , sizeof( V_1 -> V_105 ) ) ;
V_1 -> V_105 . V_128 = V_129 ;
V_1 -> V_105 . V_130 = V_131 ;
strncpy ( V_1 -> V_105 . V_124 , V_124 , sizeof( V_1 -> V_105 . V_124 ) - 1 ) ;
V_1 -> V_105 . V_124 [ sizeof( V_1 -> V_105 . V_124 ) - 1 ] = '\0' ;
V_1 -> V_105 . V_109 = & V_1 -> V_125 ;
V_1 -> V_105 . V_47 . V_132 = & V_123 -> V_2 . V_133 ;
F_40 ( V_1 ) ;
V_91 = F_41 ( & V_1 -> V_105 ) ;
F_42 ( V_1 , false ) ;
return V_91 ;
}
static bool
F_43 ( struct V_4 * V_5 ,
const struct V_14 * V_15 ,
struct V_14 * V_134 )
{
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_1 * V_1 = F_4 ( V_5 ) ;
int V_11 , clock ;
int V_17 = F_11 ( V_1 ) ;
int V_135 = F_12 ( V_1 ) == V_13 ? 1 : 0 ;
int V_23 , V_28 ;
static int V_136 [ 2 ] = { V_12 , V_13 } ;
if ( F_1 ( V_1 ) && V_1 -> V_16 ) {
F_44 ( V_1 -> V_16 , V_134 ) ;
F_45 ( V_47 , V_137 ,
V_15 , V_134 ) ;
}
if ( V_134 -> V_36 & V_37 )
return false ;
F_26 ( L_15
L_16 ,
V_17 , V_136 [ V_135 ] , V_134 -> clock ) ;
if ( ! F_16 ( V_1 , V_134 , true ) )
return false ;
V_23 = V_134 -> V_29 & V_30 ? 18 : 24 ;
V_28 = F_14 ( V_134 -> clock , V_23 ) ;
for ( clock = 0 ; clock <= V_135 ; clock ++ ) {
for ( V_11 = 1 ; V_11 <= V_17 ; V_11 <<= 1 ) {
int V_138 = F_15 ( F_13 ( V_136 [ clock ] ) , V_11 ) ;
if ( V_28 <= V_138 ) {
V_1 -> V_10 = V_136 [ clock ] ;
V_1 -> V_11 = V_11 ;
V_134 -> clock = F_13 ( V_1 -> V_10 ) ;
F_26 ( L_17
L_18 ,
V_1 -> V_10 , V_1 -> V_11 ,
V_134 -> clock , V_23 ) ;
F_26 ( L_19 ,
V_28 , V_138 ) ;
return true ;
}
}
}
return false ;
}
static void
F_46 ( T_2 * V_139 , T_2 * V_140 )
{
while ( * V_139 > 0xffffff || * V_140 > 0xffffff ) {
* V_139 >>= 1 ;
* V_140 >>= 1 ;
}
}
static void
F_47 ( int V_23 ,
int V_141 ,
int V_22 ,
int V_142 ,
struct V_143 * V_144 )
{
V_144 -> V_145 = 64 ;
V_144 -> V_146 = ( V_22 * V_23 ) >> 3 ;
V_144 -> V_147 = V_142 * V_141 ;
F_46 ( & V_144 -> V_146 , & V_144 -> V_147 ) ;
V_144 -> V_148 = V_22 ;
V_144 -> V_149 = V_142 ;
F_46 ( & V_144 -> V_148 , & V_144 -> V_149 ) ;
}
void
F_48 ( struct V_150 * V_151 , struct V_14 * V_15 ,
struct V_14 * V_134 )
{
struct V_46 * V_47 = V_151 -> V_47 ;
struct V_8 * V_5 ;
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_152 * V_152 = F_49 ( V_151 ) ;
int V_11 = 4 ;
struct V_143 V_144 ;
int V_153 = V_152 -> V_153 ;
F_50 (dev, crtc, encoder) {
struct V_1 * V_1 = F_4 ( & V_5 -> V_2 ) ;
if ( V_1 -> V_2 . type == V_154 ||
V_1 -> V_2 . type == V_3 )
{
V_11 = V_1 -> V_11 ;
break;
}
}
F_47 ( V_152 -> V_23 , V_11 ,
V_15 -> clock , V_134 -> clock , & V_144 ) ;
if ( F_30 ( V_47 ) ) {
F_32 ( F_51 ( V_153 ) ,
( ( V_144 . V_145 - 1 ) << V_155 ) |
V_144 . V_146 ) ;
F_32 ( F_52 ( V_153 ) , V_144 . V_147 ) ;
F_32 ( F_53 ( V_153 ) , V_144 . V_148 ) ;
F_32 ( F_54 ( V_153 ) , V_144 . V_149 ) ;
} else {
F_32 ( F_55 ( V_153 ) ,
( ( V_144 . V_145 - 1 ) << V_155 ) |
V_144 . V_146 ) ;
F_32 ( F_56 ( V_153 ) , V_144 . V_147 ) ;
F_32 ( F_57 ( V_153 ) , V_144 . V_148 ) ;
F_32 ( F_58 ( V_153 ) , V_144 . V_149 ) ;
}
}
static void
F_59 ( struct V_4 * V_5 , struct V_14 * V_15 ,
struct V_14 * V_134 )
{
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_1 * V_1 = F_4 ( V_5 ) ;
struct V_150 * V_151 = V_1 -> V_2 . V_2 . V_151 ;
struct V_152 * V_152 = F_49 ( V_151 ) ;
if ( F_1 ( V_1 ) ) {
if ( ! F_2 ( V_1 ) )
F_60 ( V_5 ) ;
else
F_61 ( V_5 ) ;
}
V_1 -> V_156 = F_21 ( V_1 -> V_70 ) & V_157 ;
V_1 -> V_156 |= V_158 | V_159 ;
V_1 -> V_156 |= V_158 | V_159 ;
switch ( V_1 -> V_11 ) {
case 1 :
V_1 -> V_156 |= V_160 ;
break;
case 2 :
V_1 -> V_156 |= V_161 ;
break;
case 4 :
V_1 -> V_156 |= V_162 ;
break;
}
if ( V_1 -> V_163 ) {
F_62 ( L_20 ,
F_63 ( V_152 -> V_153 ) ) ;
V_1 -> V_156 |= V_164 ;
F_64 ( V_5 , V_134 ) ;
}
memset ( V_1 -> V_165 , 0 , V_166 ) ;
V_1 -> V_165 [ 0 ] = V_1 -> V_10 ;
V_1 -> V_165 [ 1 ] = V_1 -> V_11 ;
V_1 -> V_165 [ 8 ] = V_167 ;
if ( V_1 -> V_18 [ V_168 ] >= 0x11 &&
( V_1 -> V_18 [ V_19 ] & V_169 ) ) {
V_1 -> V_165 [ 1 ] |= V_170 ;
}
if ( F_3 ( V_1 ) && F_29 ( V_47 ) ) {
if ( V_134 -> V_36 & V_171 )
V_1 -> V_156 |= V_172 ;
if ( V_134 -> V_36 & V_173 )
V_1 -> V_156 |= V_174 ;
V_1 -> V_156 |= V_175 ;
if ( V_1 -> V_165 [ 1 ] & V_170 )
V_1 -> V_156 |= V_176 ;
V_1 -> V_156 |= V_152 -> V_153 << 29 ;
V_1 -> V_156 |= V_177 ;
if ( V_134 -> clock < 200000 )
V_1 -> V_156 |= V_178 ;
else
V_1 -> V_156 |= V_179 ;
} else if ( ! F_65 ( V_47 ) || F_3 ( V_1 ) ) {
V_1 -> V_156 |= V_1 -> V_180 ;
if ( V_134 -> V_36 & V_171 )
V_1 -> V_156 |= V_172 ;
if ( V_134 -> V_36 & V_173 )
V_1 -> V_156 |= V_174 ;
V_1 -> V_156 |= V_181 ;
if ( V_1 -> V_165 [ 1 ] & V_170 )
V_1 -> V_156 |= V_176 ;
if ( V_152 -> V_153 == 1 )
V_1 -> V_156 |= V_182 ;
if ( F_3 ( V_1 ) ) {
V_1 -> V_156 |= V_177 ;
if ( V_134 -> clock < 200000 )
V_1 -> V_156 |= V_178 ;
else
V_1 -> V_156 |= V_179 ;
}
} else {
V_1 -> V_156 |= V_175 ;
}
}
static void F_66 ( struct V_1 * V_1 ,
T_4 V_183 ,
T_4 V_184 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
F_26 ( L_21 ,
V_183 , V_184 ,
F_21 ( V_62 ) ,
F_21 ( V_64 ) ) ;
if ( F_67 ( ( F_21 ( V_62 ) & V_183 ) == V_184 , 5000 , 10 ) ) {
F_34 ( L_22 ,
F_21 ( V_62 ) ,
F_21 ( V_64 ) ) ;
}
}
static void F_68 ( struct V_1 * V_1 )
{
F_26 ( L_23 ) ;
F_66 ( V_1 , V_185 , V_186 ) ;
}
static void F_69 ( struct V_1 * V_1 )
{
F_26 ( L_24 ) ;
F_66 ( V_1 , V_187 , V_188 ) ;
}
static void F_70 ( struct V_1 * V_1 )
{
F_26 ( L_25 ) ;
F_66 ( V_1 , V_189 , V_190 ) ;
}
static T_4 F_71 ( struct V_48 * V_49 )
{
T_4 V_191 = F_21 ( V_64 ) ;
V_191 &= ~ V_192 ;
V_191 |= V_193 ;
return V_191 ;
}
static void F_40 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_194 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_26 ) ;
F_25 ( V_1 -> V_195 ,
L_27 ) ;
V_1 -> V_195 = true ;
if ( F_23 ( V_1 ) ) {
F_26 ( L_28 ) ;
return;
}
if ( ! F_22 ( V_1 ) )
F_70 ( V_1 ) ;
V_194 = F_71 ( V_49 ) ;
V_194 |= V_65 ;
F_32 ( V_64 , V_194 ) ;
F_72 ( V_64 ) ;
F_26 ( L_29 ,
F_21 ( V_62 ) , F_21 ( V_64 ) ) ;
if ( ! F_22 ( V_1 ) ) {
F_26 ( L_30 ) ;
F_31 ( V_1 -> V_196 ) ;
}
}
static void F_73 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_194 ;
if ( ! V_1 -> V_195 && F_23 ( V_1 ) ) {
V_194 = F_71 ( V_49 ) ;
V_194 &= ~ V_65 ;
F_32 ( V_64 , V_194 ) ;
F_72 ( V_64 ) ;
F_26 ( L_29 ,
F_21 ( V_62 ) , F_21 ( V_64 ) ) ;
F_31 ( V_1 -> V_197 ) ;
}
}
static void F_74 ( struct V_198 * V_199 )
{
struct V_1 * V_1 = F_5 ( F_75 ( V_199 ) ,
struct V_1 , V_200 ) ;
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
F_76 ( & V_47 -> V_201 . V_202 ) ;
F_73 ( V_1 ) ;
F_77 ( & V_47 -> V_201 . V_202 ) ;
}
static void F_42 ( struct V_1 * V_1 , bool V_203 )
{
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_31 , V_1 -> V_195 ) ;
F_25 ( ! V_1 -> V_195 , L_32 ) ;
V_1 -> V_195 = false ;
if ( V_203 ) {
F_73 ( V_1 ) ;
} else {
F_78 ( & V_1 -> V_200 ,
F_79 ( V_1 -> V_204 * 5 ) ) ;
}
}
static void F_80 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_194 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_33 ) ;
if ( F_22 ( V_1 ) ) {
F_26 ( L_34 ) ;
return;
}
F_70 ( V_1 ) ;
V_194 = F_71 ( V_49 ) ;
if ( F_81 ( V_47 ) ) {
V_194 &= ~ V_205 ;
F_32 ( V_64 , V_194 ) ;
F_72 ( V_64 ) ;
}
V_194 |= V_206 ;
if ( ! F_81 ( V_47 ) )
V_194 |= V_205 ;
F_32 ( V_64 , V_194 ) ;
F_72 ( V_64 ) ;
F_68 ( V_1 ) ;
if ( F_81 ( V_47 ) ) {
V_194 |= V_205 ;
F_32 ( V_64 , V_194 ) ;
F_72 ( V_64 ) ;
}
}
static void F_82 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_194 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_35 ) ;
F_25 ( ! V_1 -> V_195 , L_36 ) ;
V_194 = F_71 ( V_49 ) ;
V_194 &= ~ ( V_206 | V_65 | V_205 | V_207 ) ;
F_32 ( V_64 , V_194 ) ;
F_72 ( V_64 ) ;
V_1 -> V_195 = false ;
F_69 ( V_1 ) ;
}
static void F_83 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_194 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_37 ) ;
F_31 ( V_1 -> V_208 ) ;
V_194 = F_71 ( V_49 ) ;
V_194 |= V_207 ;
F_32 ( V_64 , V_194 ) ;
F_72 ( V_64 ) ;
}
static void F_84 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_194 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_37 ) ;
V_194 = F_71 ( V_49 ) ;
V_194 &= ~ V_207 ;
F_32 ( V_64 , V_194 ) ;
F_72 ( V_64 ) ;
F_31 ( V_1 -> V_209 ) ;
}
static void F_60 ( struct V_4 * V_5 )
{
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_210 ;
F_26 ( L_37 ) ;
V_210 = F_21 ( V_211 ) ;
V_210 |= V_177 ;
F_32 ( V_211 , V_210 ) ;
F_72 ( V_211 ) ;
F_33 ( 200 ) ;
}
static void F_61 ( struct V_4 * V_5 )
{
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_210 ;
V_210 = F_21 ( V_211 ) ;
V_210 &= ~ V_177 ;
F_32 ( V_211 , V_210 ) ;
F_72 ( V_211 ) ;
F_33 ( 200 ) ;
}
static void F_85 ( struct V_1 * V_1 , int V_15 )
{
int V_91 , V_42 ;
if ( V_1 -> V_18 [ V_168 ] < 0x11 )
return;
if ( V_15 != V_212 ) {
V_91 = F_36 ( V_1 , V_213 ,
V_214 ) ;
if ( V_91 != 1 )
F_62 ( L_38 ) ;
} else {
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ ) {
V_91 = F_36 ( V_1 ,
V_213 ,
V_215 ) ;
if ( V_91 == 1 )
break;
F_31 ( 1 ) ;
}
}
}
static void F_86 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
F_40 ( V_1 ) ;
F_84 ( V_1 ) ;
F_85 ( V_1 , V_212 ) ;
F_82 ( V_1 ) ;
F_87 ( V_1 ) ;
}
static void F_88 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_152 * V_152 = F_49 ( V_1 -> V_2 . V_2 . V_151 ) ;
F_40 ( V_1 ) ;
F_85 ( V_1 , V_212 ) ;
F_89 ( V_1 ) ;
F_80 ( V_1 ) ;
F_42 ( V_1 , true ) ;
F_90 ( V_1 ) ;
F_83 ( V_1 ) ;
V_1 -> V_216 = V_212 ;
if ( F_65 ( V_47 ) )
F_91 ( V_47 , V_152 -> V_153 ) ;
}
static void
F_92 ( struct V_4 * V_5 , int V_15 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_217 = F_21 ( V_1 -> V_70 ) ;
if ( V_15 != V_212 ) {
F_40 ( V_1 ) ;
F_84 ( V_1 ) ;
F_85 ( V_1 , V_15 ) ;
F_82 ( V_1 ) ;
F_87 ( V_1 ) ;
if ( F_3 ( V_1 ) )
F_61 ( V_5 ) ;
} else {
if ( F_3 ( V_1 ) )
F_60 ( V_5 ) ;
F_40 ( V_1 ) ;
F_85 ( V_1 , V_15 ) ;
if ( ! ( V_217 & V_218 ) ) {
F_89 ( V_1 ) ;
F_80 ( V_1 ) ;
F_42 ( V_1 , true ) ;
F_90 ( V_1 ) ;
} else
F_42 ( V_1 , false ) ;
F_83 ( V_1 ) ;
}
V_1 -> V_216 = V_15 ;
}
static bool
F_93 ( struct V_1 * V_1 , T_3 V_90 ,
T_1 * V_68 , int V_73 )
{
int V_91 , V_42 ;
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ ) {
V_91 = F_37 ( V_1 , V_90 , V_68 ,
V_73 ) ;
if ( V_91 == V_73 )
return true ;
F_31 ( 1 ) ;
}
return false ;
}
static bool
F_94 ( struct V_1 * V_1 , T_1 V_219 [ V_220 ] )
{
return F_93 ( V_1 ,
V_221 ,
V_219 ,
V_220 ) ;
}
static T_1
F_95 ( T_1 V_219 [ V_220 ] ,
int V_222 )
{
return V_219 [ V_222 - V_221 ] ;
}
static T_1
F_96 ( T_1 V_223 [ 2 ] ,
int V_224 )
{
int V_225 = ( ( V_224 & 1 ) ?
V_226 :
V_227 ) ;
T_1 V_228 = V_223 [ V_224 >> 1 ] ;
return ( ( V_228 >> V_225 ) & 3 ) << V_229 ;
}
static T_1
F_97 ( T_1 V_223 [ 2 ] ,
int V_224 )
{
int V_225 = ( ( V_224 & 1 ) ?
V_230 :
V_231 ) ;
T_1 V_228 = V_223 [ V_224 >> 1 ] ;
return ( ( V_228 >> V_225 ) & 3 ) << V_232 ;
}
static T_1
F_98 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
if ( F_29 ( V_47 ) && F_3 ( V_1 ) )
return V_233 ;
else if ( F_65 ( V_47 ) && ! F_3 ( V_1 ) )
return V_234 ;
else
return V_233 ;
}
static T_1
F_99 ( struct V_1 * V_1 , T_1 V_235 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
if ( F_29 ( V_47 ) && F_3 ( V_1 ) ) {
switch ( V_235 & V_236 ) {
case V_237 :
return V_238 ;
case V_239 :
case V_233 :
return V_240 ;
default:
return V_241 ;
}
} else {
switch ( V_235 & V_236 ) {
case V_237 :
return V_238 ;
case V_239 :
return V_238 ;
case V_233 :
return V_240 ;
case V_234 :
default:
return V_241 ;
}
}
}
static void
F_100 ( struct V_1 * V_1 , T_1 V_219 [ V_220 ] )
{
T_1 V_43 = 0 ;
T_1 V_242 = 0 ;
int V_224 ;
T_1 * V_223 = V_219 + ( V_243 - V_221 ) ;
T_1 V_244 ;
T_1 V_245 ;
for ( V_224 = 0 ; V_224 < V_1 -> V_11 ; V_224 ++ ) {
T_1 V_246 = F_96 ( V_223 , V_224 ) ;
T_1 V_247 = F_97 ( V_223 , V_224 ) ;
if ( V_246 > V_43 )
V_43 = V_246 ;
if ( V_247 > V_242 )
V_242 = V_247 ;
}
V_244 = F_98 ( V_1 ) ;
if ( V_43 >= V_244 )
V_43 = V_244 | V_248 ;
V_245 = F_99 ( V_1 , V_43 ) ;
if ( V_242 >= V_245 )
V_242 = V_245 | V_249 ;
for ( V_224 = 0 ; V_224 < 4 ; V_224 ++ )
V_1 -> V_250 [ V_224 ] = V_43 | V_242 ;
}
static T_2
F_101 ( T_1 V_250 )
{
T_2 V_251 = 0 ;
switch ( V_250 & V_236 ) {
case V_237 :
default:
V_251 |= V_158 ;
break;
case V_239 :
V_251 |= V_252 ;
break;
case V_233 :
V_251 |= V_253 ;
break;
case V_234 :
V_251 |= V_254 ;
break;
}
switch ( V_250 & V_255 ) {
case V_241 :
default:
V_251 |= V_159 ;
break;
case V_240 :
V_251 |= V_256 ;
break;
case V_238 :
V_251 |= V_257 ;
break;
case V_258 :
V_251 |= V_259 ;
break;
}
return V_251 ;
}
static T_2
F_102 ( T_1 V_250 )
{
int V_251 = V_250 & ( V_236 |
V_255 ) ;
switch ( V_251 ) {
case V_237 | V_241 :
case V_239 | V_241 :
return V_260 ;
case V_237 | V_240 :
return V_261 ;
case V_237 | V_238 :
case V_239 | V_238 :
return V_262 ;
case V_239 | V_240 :
case V_233 | V_240 :
return V_263 ;
case V_233 | V_241 :
case V_234 | V_241 :
return V_264 ;
default:
F_26 ( L_39
L_40 , V_251 ) ;
return V_260 ;
}
}
static T_2
F_103 ( T_1 V_250 )
{
int V_251 = V_250 & ( V_236 |
V_255 ) ;
switch ( V_251 ) {
case V_237 | V_241 :
return V_265 ;
case V_237 | V_240 :
return V_266 ;
case V_237 | V_238 :
return V_267 ;
case V_239 | V_241 :
return V_268 ;
case V_239 | V_240 :
return V_269 ;
case V_233 | V_241 :
return V_270 ;
case V_233 | V_240 :
return V_271 ;
default:
F_26 ( L_39
L_40 , V_251 ) ;
return V_272 ;
}
}
static T_1
F_104 ( T_1 V_219 [ V_220 ] ,
int V_224 )
{
int V_225 = ( V_224 & 1 ) * 4 ;
T_1 V_228 = V_219 [ V_224 >> 1 ] ;
return ( V_228 >> V_225 ) & 0xf ;
}
static bool
F_105 ( T_1 V_219 [ V_220 ] , int V_11 )
{
int V_224 ;
T_1 V_273 ;
for ( V_224 = 0 ; V_224 < V_11 ; V_224 ++ ) {
V_273 = F_104 ( V_219 , V_224 ) ;
if ( ( V_273 & V_274 ) == 0 )
return false ;
}
return true ;
}
static bool
F_106 ( struct V_1 * V_1 , T_1 V_219 [ V_220 ] )
{
T_1 V_275 ;
T_1 V_273 ;
int V_224 ;
V_275 = F_95 ( V_219 ,
V_276 ) ;
if ( ( V_275 & V_277 ) == 0 )
return false ;
for ( V_224 = 0 ; V_224 < V_1 -> V_11 ; V_224 ++ ) {
V_273 = F_104 ( V_219 , V_224 ) ;
if ( ( V_273 & V_278 ) != V_278 )
return false ;
}
return true ;
}
static bool
F_107 ( struct V_1 * V_1 ,
T_2 V_279 ,
T_1 V_280 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
int V_91 ;
F_32 ( V_1 -> V_70 , V_279 ) ;
F_72 ( V_1 -> V_70 ) ;
F_36 ( V_1 ,
V_281 ,
V_280 ) ;
V_91 = F_35 ( V_1 ,
V_282 ,
V_1 -> V_250 ,
V_1 -> V_11 ) ;
if ( V_91 != V_1 -> V_11 )
return false ;
return true ;
}
static void
F_89 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_152 * V_152 = F_49 ( V_1 -> V_2 . V_2 . V_151 ) ;
int V_42 ;
T_1 V_283 ;
bool V_284 = false ;
int V_285 , V_286 ;
T_4 V_287 ;
T_2 V_156 = V_1 -> V_156 ;
if ( ! F_65 ( V_47 ) ) {
F_32 ( V_1 -> V_70 , V_1 -> V_156 ) ;
F_72 ( V_1 -> V_70 ) ;
F_108 ( V_47 , V_152 -> V_153 ) ;
}
F_35 ( V_1 , V_288 ,
V_1 -> V_165 ,
V_166 ) ;
V_156 |= V_218 ;
if ( F_65 ( V_47 ) && ( F_29 ( V_47 ) || ! F_3 ( V_1 ) ) )
V_156 &= ~ V_289 ;
else
V_156 &= ~ V_290 ;
memset ( V_1 -> V_250 , 0 , 4 ) ;
V_283 = 0xff ;
V_285 = 0 ;
V_286 = 0 ;
V_284 = false ;
for (; ; ) {
T_1 V_219 [ V_220 ] ;
T_2 V_251 ;
if ( F_29 ( V_47 ) && F_3 ( V_1 ) ) {
V_251 = F_103 ( V_1 -> V_250 [ 0 ] ) ;
V_156 = ( V_156 & ~ V_291 ) | V_251 ;
} else if ( F_28 ( V_47 ) && F_3 ( V_1 ) ) {
V_251 = F_102 ( V_1 -> V_250 [ 0 ] ) ;
V_156 = ( V_156 & ~ V_292 ) | V_251 ;
} else {
V_251 = F_101 ( V_1 -> V_250 [ 0 ] ) ;
F_26 ( L_41 , V_251 ) ;
V_156 = ( V_156 & ~ ( V_293 | V_294 ) ) | V_251 ;
}
if ( F_65 ( V_47 ) && ( F_29 ( V_47 ) || ! F_3 ( V_1 ) ) )
V_287 = V_156 | V_295 ;
else
V_287 = V_156 | V_296 ;
if ( ! F_107 ( V_1 , V_287 ,
V_297 |
V_298 ) )
break;
F_33 ( 100 ) ;
if ( ! F_94 ( V_1 , V_219 ) ) {
F_34 ( L_42 ) ;
break;
}
if ( F_105 ( V_219 , V_1 -> V_11 ) ) {
F_26 ( L_43 ) ;
V_284 = true ;
break;
}
for ( V_42 = 0 ; V_42 < V_1 -> V_11 ; V_42 ++ )
if ( ( V_1 -> V_250 [ V_42 ] & V_248 ) == 0 )
break;
if ( V_42 == V_1 -> V_11 && V_285 == 5 ) {
++ V_286 ;
if ( V_286 == 5 ) {
F_26 ( L_44 ) ;
break;
}
memset ( V_1 -> V_250 , 0 , 4 ) ;
V_285 = 0 ;
continue;
}
if ( ( V_1 -> V_250 [ 0 ] & V_236 ) == V_283 ) {
++ V_285 ;
if ( V_285 == 5 ) {
F_26 ( L_45 ) ;
break;
}
} else
V_285 = 0 ;
V_283 = V_1 -> V_250 [ 0 ] & V_236 ;
F_100 ( V_1 , V_219 ) ;
}
V_1 -> V_156 = V_156 ;
}
static void
F_90 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
bool V_299 = false ;
int V_300 , V_301 ;
T_4 V_287 ;
T_2 V_156 = V_1 -> V_156 ;
V_300 = 0 ;
V_301 = 0 ;
V_299 = false ;
for (; ; ) {
T_2 V_251 ;
T_1 V_219 [ V_220 ] ;
if ( V_301 > 5 ) {
F_34 ( L_46 ) ;
F_87 ( V_1 ) ;
break;
}
if ( F_29 ( V_47 ) && F_3 ( V_1 ) ) {
V_251 = F_103 ( V_1 -> V_250 [ 0 ] ) ;
V_156 = ( V_156 & ~ V_291 ) | V_251 ;
} else if ( F_28 ( V_47 ) && F_3 ( V_1 ) ) {
V_251 = F_102 ( V_1 -> V_250 [ 0 ] ) ;
V_156 = ( V_156 & ~ V_292 ) | V_251 ;
} else {
V_251 = F_101 ( V_1 -> V_250 [ 0 ] ) ;
V_156 = ( V_156 & ~ ( V_293 | V_294 ) ) | V_251 ;
}
if ( F_65 ( V_47 ) && ( F_29 ( V_47 ) || ! F_3 ( V_1 ) ) )
V_287 = V_156 | V_302 ;
else
V_287 = V_156 | V_303 ;
if ( ! F_107 ( V_1 , V_287 ,
V_304 |
V_298 ) )
break;
F_33 ( 400 ) ;
if ( ! F_94 ( V_1 , V_219 ) )
break;
if ( ! F_105 ( V_219 , V_1 -> V_11 ) ) {
F_89 ( V_1 ) ;
V_301 ++ ;
continue;
}
if ( F_106 ( V_1 , V_219 ) ) {
V_299 = true ;
break;
}
if ( V_300 > 5 ) {
F_87 ( V_1 ) ;
F_89 ( V_1 ) ;
V_300 = 0 ;
V_301 ++ ;
continue;
}
F_100 ( V_1 , V_219 ) ;
++ V_300 ;
}
if ( F_65 ( V_47 ) && ( F_29 ( V_47 ) || ! F_3 ( V_1 ) ) )
V_287 = V_156 | V_175 ;
else
V_287 = V_156 | V_181 ;
F_32 ( V_1 -> V_70 , V_287 ) ;
F_72 ( V_1 -> V_70 ) ;
F_36 ( V_1 ,
V_281 , V_305 ) ;
}
static void
F_87 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_156 = V_1 -> V_156 ;
if ( ( F_21 ( V_1 -> V_70 ) & V_218 ) == 0 )
return;
F_26 ( L_37 ) ;
if ( F_1 ( V_1 ) ) {
V_156 &= ~ V_177 ;
F_32 ( V_1 -> V_70 , V_156 ) ;
F_72 ( V_1 -> V_70 ) ;
F_33 ( 100 ) ;
}
if ( F_65 ( V_47 ) && ( F_29 ( V_47 ) || ! F_3 ( V_1 ) ) ) {
V_156 &= ~ V_289 ;
F_32 ( V_1 -> V_70 , V_156 | V_306 ) ;
} else {
V_156 &= ~ V_290 ;
F_32 ( V_1 -> V_70 , V_156 | V_307 ) ;
}
F_72 ( V_1 -> V_70 ) ;
F_31 ( 17 ) ;
if ( F_1 ( V_1 ) ) {
if ( F_65 ( V_47 ) && ( F_29 ( V_47 ) || ! F_3 ( V_1 ) ) )
V_156 |= V_175 ;
else
V_156 |= V_181 ;
}
if ( F_109 ( V_47 ) &&
F_21 ( V_1 -> V_70 ) & V_182 ) {
struct V_150 * V_151 = V_1 -> V_2 . V_2 . V_151 ;
V_156 &= ~ V_182 ;
F_32 ( V_1 -> V_70 , V_156 ) ;
if ( V_151 == NULL ) {
F_72 ( V_1 -> V_70 ) ;
F_31 ( 50 ) ;
} else
F_108 ( V_47 , F_49 ( V_151 ) -> V_153 ) ;
}
V_156 &= ~ V_164 ;
F_32 ( V_1 -> V_70 , V_156 & ~ V_218 ) ;
F_72 ( V_1 -> V_70 ) ;
F_31 ( V_1 -> V_197 ) ;
}
static bool
F_110 ( struct V_1 * V_1 )
{
if ( F_93 ( V_1 , 0x000 , V_1 -> V_18 ,
sizeof( V_1 -> V_18 ) ) &&
( V_1 -> V_18 [ V_168 ] != 0 ) ) {
return true ;
}
return false ;
}
static void
F_111 ( struct V_1 * V_1 )
{
T_5 V_308 [ 3 ] ;
if ( ! ( V_1 -> V_18 [ V_309 ] & V_310 ) )
return;
F_40 ( V_1 ) ;
if ( F_93 ( V_1 , V_311 , V_308 , 3 ) )
F_26 ( L_47 ,
V_308 [ 0 ] , V_308 [ 1 ] , V_308 [ 2 ] ) ;
if ( F_93 ( V_1 , V_312 , V_308 , 3 ) )
F_26 ( L_48 ,
V_308 [ 0 ] , V_308 [ 1 ] , V_308 [ 2 ] ) ;
F_42 ( V_1 , false ) ;
}
static bool
F_112 ( struct V_1 * V_1 , T_5 * V_313 )
{
int V_91 ;
V_91 = F_93 ( V_1 ,
V_314 ,
V_313 , 1 ) ;
if ( ! V_91 )
return false ;
return true ;
}
static void
F_113 ( struct V_1 * V_1 )
{
F_36 ( V_1 , V_315 , V_316 ) ;
}
static void
F_114 ( struct V_1 * V_1 )
{
T_5 V_313 ;
T_5 V_219 [ V_220 ] ;
if ( V_1 -> V_216 != V_212 )
return;
if ( ! V_1 -> V_2 . V_2 . V_151 )
return;
if ( ! F_94 ( V_1 , V_219 ) ) {
F_87 ( V_1 ) ;
return;
}
if ( ! F_110 ( V_1 ) ) {
F_87 ( V_1 ) ;
return;
}
if ( V_1 -> V_18 [ V_168 ] >= 0x11 &&
F_112 ( V_1 , & V_313 ) ) {
F_36 ( V_1 ,
V_314 ,
V_313 ) ;
if ( V_313 & V_317 )
F_113 ( V_1 ) ;
if ( V_313 & ( V_318 | V_319 ) )
F_62 ( L_49 ) ;
}
if ( ! F_106 ( V_1 , V_219 ) ) {
F_26 ( L_50 ,
F_115 ( & V_1 -> V_2 . V_2 ) ) ;
F_89 ( V_1 ) ;
F_90 ( V_1 ) ;
}
}
static enum V_320
F_116 ( struct V_1 * V_1 )
{
if ( F_110 ( V_1 ) )
return V_321 ;
return V_322 ;
}
static enum V_320
F_117 ( struct V_1 * V_1 )
{
enum V_320 V_74 ;
if ( F_1 ( V_1 ) ) {
V_74 = F_118 ( V_1 -> V_2 . V_2 . V_47 ) ;
if ( V_74 == V_323 )
V_74 = V_321 ;
return V_74 ;
}
return F_116 ( V_1 ) ;
}
static enum V_320
F_119 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_324 ;
switch ( V_1 -> V_70 ) {
case V_325 :
V_324 = V_326 ;
break;
case V_327 :
V_324 = V_328 ;
break;
case V_329 :
V_324 = V_330 ;
break;
default:
return V_323 ;
}
if ( ( F_21 ( V_331 ) & V_324 ) == 0 )
return V_322 ;
return F_116 ( V_1 ) ;
}
static struct V_332 *
F_120 ( struct V_6 * V_7 , struct V_104 * V_105 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_332 * V_332 ;
int V_333 ;
if ( F_1 ( V_1 ) ) {
if ( ! V_1 -> V_332 )
return NULL ;
V_333 = ( V_1 -> V_332 -> V_334 + 1 ) * V_335 ;
V_332 = F_121 ( V_333 , V_336 ) ;
if ( ! V_332 )
return NULL ;
memcpy ( V_332 , V_1 -> V_332 , V_333 ) ;
return V_332 ;
}
V_332 = F_122 ( V_7 , V_105 ) ;
return V_332 ;
}
static int
F_123 ( struct V_6 * V_7 , struct V_104 * V_105 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
int V_91 ;
if ( F_1 ( V_1 ) ) {
F_124 ( V_7 ,
V_1 -> V_332 ) ;
V_91 = F_125 ( V_7 , V_1 -> V_332 ) ;
F_126 ( V_7 ,
V_1 -> V_332 ) ;
V_7 -> V_337 . V_338 = NULL ;
return V_1 -> V_339 ;
}
V_91 = F_127 ( V_7 , V_105 ) ;
return V_91 ;
}
static enum V_320
F_128 ( struct V_6 * V_7 , bool V_340 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
enum V_320 V_74 ;
struct V_332 * V_332 = NULL ;
V_1 -> V_163 = false ;
if ( F_30 ( V_47 ) )
V_74 = F_117 ( V_1 ) ;
else
V_74 = F_119 ( V_1 ) ;
F_26 ( L_51 ,
V_1 -> V_18 [ 0 ] , V_1 -> V_18 [ 1 ] , V_1 -> V_18 [ 2 ] ,
V_1 -> V_18 [ 3 ] , V_1 -> V_18 [ 4 ] , V_1 -> V_18 [ 5 ] ,
V_1 -> V_18 [ 6 ] , V_1 -> V_18 [ 7 ] ) ;
if ( V_74 != V_321 )
return V_74 ;
F_111 ( V_1 ) ;
if ( V_1 -> V_341 != V_342 ) {
V_1 -> V_163 = ( V_1 -> V_341 == V_343 ) ;
} else {
V_332 = F_120 ( V_7 , & V_1 -> V_105 ) ;
if ( V_332 ) {
V_1 -> V_163 = F_129 ( V_332 ) ;
V_7 -> V_337 . V_338 = NULL ;
F_130 ( V_332 ) ;
}
}
return V_321 ;
}
static int F_131 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
int V_91 ;
V_91 = F_123 ( V_7 , & V_1 -> V_105 ) ;
if ( V_91 ) {
if ( F_1 ( V_1 ) && ! V_1 -> V_16 ) {
struct V_14 * V_344 ;
F_132 (newmode, &connector->probed_modes,
head) {
if ( ( V_344 -> type & V_345 ) ) {
V_1 -> V_16 =
F_133 ( V_47 , V_344 ) ;
break;
}
}
}
return V_91 ;
}
if ( F_1 ( V_1 ) ) {
if ( V_1 -> V_16 == NULL && V_49 -> V_346 != NULL ) {
V_1 -> V_16 =
F_133 ( V_47 , V_49 -> V_346 ) ;
if ( V_1 -> V_16 ) {
V_1 -> V_16 -> type |=
V_345 ;
}
}
if ( V_1 -> V_16 ) {
struct V_14 * V_15 ;
V_15 = F_133 ( V_47 , V_1 -> V_16 ) ;
F_134 ( V_7 , V_15 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_135 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_332 * V_332 ;
bool V_163 = false ;
V_332 = F_120 ( V_7 , & V_1 -> V_105 ) ;
if ( V_332 ) {
V_163 = F_129 ( V_332 ) ;
V_7 -> V_337 . V_338 = NULL ;
F_130 ( V_332 ) ;
}
return V_163 ;
}
static int
F_136 ( struct V_6 * V_7 ,
struct V_347 * V_348 ,
T_6 V_349 )
{
struct V_48 * V_49 = V_7 -> V_47 -> V_50 ;
struct V_1 * V_1 = F_6 ( V_7 ) ;
int V_91 ;
V_91 = F_137 ( V_7 , V_348 , V_349 ) ;
if ( V_91 )
return V_91 ;
if ( V_348 == V_49 -> V_350 ) {
int V_42 = V_349 ;
bool V_163 ;
if ( V_42 == V_1 -> V_341 )
return 0 ;
V_1 -> V_341 = V_42 ;
if ( V_42 == V_342 )
V_163 = F_135 ( V_7 ) ;
else
V_163 = ( V_42 == V_343 ) ;
if ( V_163 == V_1 -> V_163 )
return 0 ;
V_1 -> V_163 = V_163 ;
goto V_351;
}
if ( V_348 == V_49 -> V_352 ) {
if ( V_349 == ! ! V_1 -> V_180 )
return 0 ;
V_1 -> V_180 = V_349 ? V_353 : 0 ;
goto V_351;
}
return - V_354 ;
V_351:
if ( V_1 -> V_2 . V_2 . V_151 ) {
struct V_150 * V_151 = V_1 -> V_2 . V_2 . V_151 ;
F_138 ( V_151 , & V_151 -> V_15 ,
V_151 -> V_355 , V_151 -> V_356 ,
V_151 -> V_357 ) ;
}
return 0 ;
}
static void
F_139 ( struct V_6 * V_7 )
{
struct V_46 * V_47 = V_7 -> V_47 ;
if ( F_140 ( V_47 ) )
F_141 ( V_47 ) ;
F_142 ( V_7 ) ;
F_143 ( V_7 ) ;
F_130 ( V_7 ) ;
}
static void F_144 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
F_145 ( & V_1 -> V_105 ) ;
F_146 ( V_5 ) ;
if ( F_1 ( V_1 ) ) {
F_130 ( V_1 -> V_332 ) ;
F_147 ( & V_1 -> V_200 ) ;
F_73 ( V_1 ) ;
}
F_130 ( V_1 ) ;
}
static void
F_148 ( struct V_8 * V_8 )
{
struct V_1 * V_1 = F_5 ( V_8 , struct V_1 , V_2 ) ;
F_114 ( V_1 ) ;
}
int
F_149 ( struct V_150 * V_151 )
{
struct V_46 * V_47 = V_151 -> V_47 ;
struct V_8 * V_5 ;
F_50 (dev, crtc, encoder) {
struct V_1 * V_1 = F_4 ( & V_5 -> V_2 ) ;
if ( V_1 -> V_2 . type == V_154 ||
V_1 -> V_2 . type == V_3 )
return V_1 -> V_70 ;
}
return - 1 ;
}
bool F_140 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_358 * V_359 ;
int V_42 ;
if ( ! V_49 -> V_360 )
return false ;
for ( V_42 = 0 ; V_42 < V_49 -> V_360 ; V_42 ++ ) {
V_359 = V_49 -> V_361 + V_42 ;
if ( V_359 -> V_362 == V_363 &&
V_359 -> V_364 == V_365 )
return true ;
}
return false ;
}
static void
F_150 ( struct V_1 * V_1 , struct V_6 * V_7 )
{
F_151 ( V_7 ) ;
F_152 ( V_7 ) ;
}
void
F_153 ( struct V_46 * V_47 , int V_70 )
{
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
struct V_8 * V_8 ;
struct V_123 * V_123 ;
const char * V_124 = NULL ;
int type ;
V_1 = F_154 ( sizeof( struct V_1 ) , V_336 ) ;
if ( ! V_1 )
return;
V_1 -> V_70 = V_70 ;
V_1 -> V_216 = - 1 ;
V_123 = F_154 ( sizeof( struct V_123 ) , V_336 ) ;
if ( ! V_123 ) {
F_130 ( V_1 ) ;
return;
}
V_8 = & V_1 -> V_2 ;
if ( F_30 ( V_47 ) && V_70 == V_366 )
if ( F_140 ( V_47 ) )
V_1 -> F_2 = true ;
if ( V_70 == V_211 || F_2 ( V_1 ) ) {
type = V_367 ;
V_8 -> type = V_3 ;
} else {
type = V_368 ;
V_8 -> type = V_154 ;
}
V_7 = & V_123 -> V_2 ;
F_155 ( V_47 , V_7 , & V_369 , type ) ;
F_156 ( V_7 , & V_370 ) ;
V_7 -> V_371 = V_372 ;
if ( V_70 == V_325 || V_70 == V_373 )
V_8 -> V_374 = ( 1 << V_375 ) ;
else if ( V_70 == V_327 || V_70 == V_376 )
V_8 -> V_374 = ( 1 << V_377 ) ;
else if ( V_70 == V_329 || V_70 == V_366 )
V_8 -> V_374 = ( 1 << V_378 ) ;
if ( F_1 ( V_1 ) ) {
V_8 -> V_374 = ( 1 << V_379 ) ;
F_157 ( & V_1 -> V_200 ,
F_74 ) ;
}
V_8 -> V_380 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_7 -> V_381 = true ;
V_7 -> V_382 = 0 ;
F_158 ( V_47 , & V_8 -> V_2 , & V_383 ,
V_384 ) ;
F_159 ( & V_8 -> V_2 , & V_385 ) ;
F_160 ( V_123 , V_8 ) ;
F_161 ( V_7 ) ;
switch ( V_70 ) {
case V_211 :
V_124 = L_52 ;
break;
case V_325 :
case V_373 :
V_49 -> V_386 |=
V_387 ;
V_124 = L_53 ;
break;
case V_327 :
case V_376 :
V_49 -> V_386 |=
V_388 ;
V_124 = L_54 ;
break;
case V_329 :
case V_366 :
V_49 -> V_386 |=
V_389 ;
V_124 = L_55 ;
break;
}
if ( F_1 ( V_1 ) ) {
struct V_390 V_391 , V_392 ;
T_4 V_393 , V_394 , V_395 ;
V_393 = F_21 ( V_396 ) ;
V_394 = F_21 ( V_397 ) ;
V_395 = F_21 ( V_398 ) ;
if ( ! V_393 || ! V_394 || ! V_395 ) {
F_162 ( L_56 ) ;
F_144 ( & V_1 -> V_2 . V_2 ) ;
F_139 ( & V_123 -> V_2 ) ;
return;
}
V_391 . V_399 = ( V_393 & V_400 ) >>
V_401 ;
V_391 . V_402 = ( V_393 & V_403 ) >>
V_404 ;
V_391 . V_405 = ( V_394 & V_406 ) >>
V_407 ;
V_391 . V_408 = ( V_394 & V_409 ) >>
V_410 ;
V_391 . V_411 = ( ( V_395 & V_412 ) >>
V_413 ) * 1000 ;
F_26 ( L_57 ,
V_391 . V_399 , V_391 . V_402 , V_391 . V_405 , V_391 . V_408 , V_391 . V_411 ) ;
V_392 = V_49 -> V_414 . V_415 ;
F_26 ( L_58 ,
V_392 . V_399 , V_392 . V_402 , V_392 . V_405 , V_392 . V_408 , V_392 . V_411 ) ;
#define F_163 ( T_7 ) ((max(cur.field, vbt.field) + 9) / 10)
V_1 -> V_196 = F_163 ( V_399 ) ;
V_1 -> V_208 = F_163 ( V_402 ) ;
V_1 -> V_209 = F_163 ( V_405 ) ;
V_1 -> V_197 = F_163 ( V_408 ) ;
V_1 -> V_204 = F_163 ( V_411 ) ;
F_26 ( L_59 ,
V_1 -> V_196 , V_1 -> V_197 ,
V_1 -> V_204 ) ;
F_26 ( L_60 ,
V_1 -> V_208 , V_1 -> V_209 ) ;
}
F_39 ( V_1 , V_123 , V_124 ) ;
if ( F_1 ( V_1 ) ) {
bool V_91 ;
struct V_332 * V_332 ;
F_40 ( V_1 ) ;
V_91 = F_110 ( V_1 ) ;
F_42 ( V_1 , false ) ;
if ( V_91 ) {
if ( V_1 -> V_18 [ V_168 ] >= 0x11 )
V_49 -> V_416 =
V_1 -> V_18 [ V_417 ] &
V_418 ;
} else {
F_162 ( L_61 ) ;
F_144 ( & V_1 -> V_2 . V_2 ) ;
F_139 ( & V_123 -> V_2 ) ;
return;
}
F_40 ( V_1 ) ;
V_332 = F_122 ( V_7 , & V_1 -> V_105 ) ;
if ( V_332 ) {
F_124 ( V_7 ,
V_332 ) ;
V_1 -> V_339 =
F_125 ( V_7 , V_332 ) ;
F_126 ( V_7 , V_332 ) ;
V_1 -> V_332 = V_332 ;
}
F_42 ( V_1 , false ) ;
}
V_8 -> V_419 = F_148 ;
if ( F_1 ( V_1 ) ) {
V_49 -> V_420 = V_7 ;
F_164 ( V_47 ) ;
}
F_150 ( V_1 , V_7 ) ;
if ( F_165 ( V_47 ) && ! F_166 ( V_47 ) ) {
T_4 V_421 = F_21 ( V_422 ) ;
F_32 ( V_422 , ( V_421 & ~ 0xf ) | 0xd ) ;
}
}

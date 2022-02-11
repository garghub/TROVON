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
V_1 -> V_156 = F_21 ( V_1 -> V_70 ) & V_157 ;
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
F_60 ( L_20 ,
F_61 ( V_152 -> V_153 ) ) ;
V_1 -> V_156 |= V_164 ;
F_62 ( V_5 , V_134 ) ;
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
if ( V_134 -> clock < 200000 )
V_1 -> V_156 |= V_177 ;
else
V_1 -> V_156 |= V_178 ;
} else if ( ! F_63 ( V_47 ) || F_3 ( V_1 ) ) {
V_1 -> V_156 |= V_1 -> V_179 ;
if ( V_134 -> V_36 & V_171 )
V_1 -> V_156 |= V_172 ;
if ( V_134 -> V_36 & V_173 )
V_1 -> V_156 |= V_174 ;
V_1 -> V_156 |= V_180 ;
if ( V_1 -> V_165 [ 1 ] & V_170 )
V_1 -> V_156 |= V_176 ;
if ( V_152 -> V_153 == 1 )
V_1 -> V_156 |= V_181 ;
if ( F_3 ( V_1 ) ) {
if ( V_134 -> clock < 200000 )
V_1 -> V_156 |= V_177 ;
else
V_1 -> V_156 |= V_178 ;
}
} else {
V_1 -> V_156 |= V_175 ;
}
}
static void F_64 ( struct V_1 * V_1 ,
T_4 V_182 ,
T_4 V_183 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
F_26 ( L_21 ,
V_182 , V_183 ,
F_21 ( V_62 ) ,
F_21 ( V_64 ) ) ;
if ( F_65 ( ( F_21 ( V_62 ) & V_182 ) == V_183 , 5000 , 10 ) ) {
F_34 ( L_22 ,
F_21 ( V_62 ) ,
F_21 ( V_64 ) ) ;
}
}
static void F_66 ( struct V_1 * V_1 )
{
F_26 ( L_23 ) ;
F_64 ( V_1 , V_184 , V_185 ) ;
}
static void F_67 ( struct V_1 * V_1 )
{
F_26 ( L_24 ) ;
F_64 ( V_1 , V_186 , V_187 ) ;
}
static void F_68 ( struct V_1 * V_1 )
{
F_26 ( L_25 ) ;
F_64 ( V_1 , V_188 , V_189 ) ;
}
static T_4 F_69 ( struct V_48 * V_49 )
{
T_4 V_190 = F_21 ( V_64 ) ;
V_190 &= ~ V_191 ;
V_190 |= V_192 ;
return V_190 ;
}
static void F_40 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_193 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_26 ) ;
F_25 ( V_1 -> V_194 ,
L_27 ) ;
V_1 -> V_194 = true ;
if ( F_23 ( V_1 ) ) {
F_26 ( L_28 ) ;
return;
}
if ( ! F_22 ( V_1 ) )
F_68 ( V_1 ) ;
V_193 = F_69 ( V_49 ) ;
V_193 |= V_65 ;
F_32 ( V_64 , V_193 ) ;
F_70 ( V_64 ) ;
F_26 ( L_29 ,
F_21 ( V_62 ) , F_21 ( V_64 ) ) ;
if ( ! F_22 ( V_1 ) ) {
F_26 ( L_30 ) ;
F_31 ( V_1 -> V_195 ) ;
}
}
static void F_71 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_193 ;
if ( ! V_1 -> V_194 && F_23 ( V_1 ) ) {
V_193 = F_69 ( V_49 ) ;
V_193 &= ~ V_65 ;
F_32 ( V_64 , V_193 ) ;
F_70 ( V_64 ) ;
F_26 ( L_29 ,
F_21 ( V_62 ) , F_21 ( V_64 ) ) ;
F_31 ( V_1 -> V_196 ) ;
}
}
static void F_72 ( struct V_197 * V_198 )
{
struct V_1 * V_1 = F_5 ( F_73 ( V_198 ) ,
struct V_1 , V_199 ) ;
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
F_74 ( & V_47 -> V_200 . V_201 ) ;
F_71 ( V_1 ) ;
F_75 ( & V_47 -> V_200 . V_201 ) ;
}
static void F_42 ( struct V_1 * V_1 , bool V_202 )
{
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_31 , V_1 -> V_194 ) ;
F_25 ( ! V_1 -> V_194 , L_32 ) ;
V_1 -> V_194 = false ;
if ( V_202 ) {
F_71 ( V_1 ) ;
} else {
F_76 ( & V_1 -> V_199 ,
F_77 ( V_1 -> V_203 * 5 ) ) ;
}
}
static void F_78 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_193 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_33 ) ;
if ( F_22 ( V_1 ) ) {
F_26 ( L_34 ) ;
return;
}
F_68 ( V_1 ) ;
V_193 = F_69 ( V_49 ) ;
if ( F_79 ( V_47 ) ) {
V_193 &= ~ V_204 ;
F_32 ( V_64 , V_193 ) ;
F_70 ( V_64 ) ;
}
V_193 |= V_205 ;
if ( ! F_79 ( V_47 ) )
V_193 |= V_204 ;
F_32 ( V_64 , V_193 ) ;
F_70 ( V_64 ) ;
F_66 ( V_1 ) ;
if ( F_79 ( V_47 ) ) {
V_193 |= V_204 ;
F_32 ( V_64 , V_193 ) ;
F_70 ( V_64 ) ;
}
}
static void F_80 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_193 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_35 ) ;
F_25 ( ! V_1 -> V_194 , L_36 ) ;
V_193 = F_69 ( V_49 ) ;
V_193 &= ~ ( V_205 | V_65 | V_204 | V_206 ) ;
F_32 ( V_64 , V_193 ) ;
F_70 ( V_64 ) ;
V_1 -> V_194 = false ;
F_67 ( V_1 ) ;
}
static void F_81 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_193 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_37 ) ;
F_31 ( V_1 -> V_207 ) ;
V_193 = F_69 ( V_49 ) ;
V_193 |= V_206 ;
F_32 ( V_64 , V_193 ) ;
F_70 ( V_64 ) ;
}
static void F_82 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_193 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_37 ) ;
V_193 = F_69 ( V_49 ) ;
V_193 &= ~ V_206 ;
F_32 ( V_64 , V_193 ) ;
F_70 ( V_64 ) ;
F_31 ( V_1 -> V_208 ) ;
}
static void F_83 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_150 * V_151 = V_1 -> V_2 . V_2 . V_151 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_209 ;
F_84 ( V_49 ,
F_49 ( V_151 ) -> V_153 ) ;
F_26 ( L_37 ) ;
V_209 = F_21 ( V_210 ) ;
F_25 ( V_209 & V_211 , L_38 ) ;
F_25 ( V_209 & V_212 , L_39 ) ;
V_1 -> V_156 &= ~ ( V_212 | V_164 ) ;
V_1 -> V_156 |= V_211 ;
F_32 ( V_210 , V_1 -> V_156 ) ;
F_70 ( V_210 ) ;
F_33 ( 200 ) ;
}
static void F_85 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_150 * V_151 = V_1 -> V_2 . V_2 . V_151 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_209 ;
F_84 ( V_49 ,
F_49 ( V_151 ) -> V_153 ) ;
V_209 = F_21 ( V_210 ) ;
F_25 ( ( V_209 & V_211 ) == 0 ,
L_40 ) ;
F_25 ( V_209 & V_212 , L_39 ) ;
V_209 &= ~ V_211 ;
F_32 ( V_210 , V_209 ) ;
F_70 ( V_210 ) ;
F_33 ( 200 ) ;
}
static void F_86 ( struct V_1 * V_1 , int V_15 )
{
int V_91 , V_42 ;
if ( V_1 -> V_18 [ V_168 ] < 0x11 )
return;
if ( V_15 != V_213 ) {
V_91 = F_36 ( V_1 , V_214 ,
V_215 ) ;
if ( V_91 != 1 )
F_60 ( L_41 ) ;
} else {
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ ) {
V_91 = F_36 ( V_1 ,
V_214 ,
V_216 ) ;
if ( V_91 == 1 )
break;
F_31 ( 1 ) ;
}
}
}
static bool F_87 ( struct V_8 * V_5 ,
enum V_153 * V_153 )
{
struct V_1 * V_1 = F_4 ( & V_5 -> V_2 ) ;
struct V_46 * V_47 = V_5 -> V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_217 = F_21 ( V_1 -> V_70 ) ;
if ( ! ( V_217 & V_212 ) )
return false ;
if ( F_3 ( V_1 ) && F_29 ( V_47 ) ) {
* V_153 = F_88 ( V_217 ) ;
} else if ( ! F_63 ( V_47 ) || F_3 ( V_1 ) ) {
* V_153 = F_89 ( V_217 ) ;
} else {
T_4 V_218 ;
T_4 V_219 ;
int V_42 ;
switch ( V_1 -> V_70 ) {
case V_220 :
V_218 = V_221 ;
break;
case V_222 :
V_218 = V_223 ;
break;
case V_224 :
V_218 = V_225 ;
break;
default:
return true ;
}
F_90 (i) {
V_219 = F_21 ( F_91 ( V_42 ) ) ;
if ( ( V_219 & V_226 ) == V_218 ) {
* V_153 = V_42 ;
return true ;
}
}
}
F_26 ( L_42 , V_1 -> V_70 ) ;
return true ;
}
static void F_92 ( struct V_8 * V_5 )
{
struct V_1 * V_1 = F_4 ( & V_5 -> V_2 ) ;
F_40 ( V_1 ) ;
F_82 ( V_1 ) ;
F_86 ( V_1 , V_213 ) ;
F_80 ( V_1 ) ;
if ( ! F_3 ( V_1 ) )
F_93 ( V_1 ) ;
}
static void F_94 ( struct V_8 * V_5 )
{
struct V_1 * V_1 = F_4 ( & V_5 -> V_2 ) ;
if ( F_3 ( V_1 ) ) {
F_93 ( V_1 ) ;
F_85 ( V_1 ) ;
}
}
static void F_95 ( struct V_8 * V_5 )
{
struct V_1 * V_1 = F_4 ( & V_5 -> V_2 ) ;
struct V_46 * V_47 = V_5 -> V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_227 = F_21 ( V_1 -> V_70 ) ;
if ( F_96 ( V_227 & V_212 ) )
return;
F_40 ( V_1 ) ;
F_86 ( V_1 , V_213 ) ;
F_97 ( V_1 ) ;
F_78 ( V_1 ) ;
F_42 ( V_1 , true ) ;
F_98 ( V_1 ) ;
F_81 ( V_1 ) ;
}
static void F_99 ( struct V_8 * V_5 )
{
struct V_1 * V_1 = F_4 ( & V_5 -> V_2 ) ;
if ( F_3 ( V_1 ) )
F_83 ( V_1 ) ;
}
static bool
F_100 ( struct V_1 * V_1 , T_3 V_90 ,
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
F_101 ( struct V_1 * V_1 , T_1 V_228 [ V_229 ] )
{
return F_100 ( V_1 ,
V_230 ,
V_228 ,
V_229 ) ;
}
static T_1
F_102 ( T_1 V_228 [ V_229 ] ,
int V_231 )
{
return V_228 [ V_231 - V_230 ] ;
}
static T_1
F_103 ( T_1 V_232 [ 2 ] ,
int V_233 )
{
int V_234 = ( ( V_233 & 1 ) ?
V_235 :
V_236 ) ;
T_1 V_237 = V_232 [ V_233 >> 1 ] ;
return ( ( V_237 >> V_234 ) & 3 ) << V_238 ;
}
static T_1
F_104 ( T_1 V_232 [ 2 ] ,
int V_233 )
{
int V_234 = ( ( V_233 & 1 ) ?
V_239 :
V_240 ) ;
T_1 V_237 = V_232 [ V_233 >> 1 ] ;
return ( ( V_237 >> V_234 ) & 3 ) << V_241 ;
}
static T_1
F_105 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
if ( F_29 ( V_47 ) && F_3 ( V_1 ) )
return V_242 ;
else if ( F_63 ( V_47 ) && ! F_3 ( V_1 ) )
return V_243 ;
else
return V_242 ;
}
static T_1
F_106 ( struct V_1 * V_1 , T_1 V_244 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
if ( F_29 ( V_47 ) && F_3 ( V_1 ) ) {
switch ( V_244 & V_245 ) {
case V_246 :
return V_247 ;
case V_248 :
case V_242 :
return V_249 ;
default:
return V_250 ;
}
} else {
switch ( V_244 & V_245 ) {
case V_246 :
return V_247 ;
case V_248 :
return V_247 ;
case V_242 :
return V_249 ;
case V_243 :
default:
return V_250 ;
}
}
}
static void
F_107 ( struct V_1 * V_1 , T_1 V_228 [ V_229 ] )
{
T_1 V_43 = 0 ;
T_1 V_251 = 0 ;
int V_233 ;
T_1 * V_232 = V_228 + ( V_252 - V_230 ) ;
T_1 V_253 ;
T_1 V_254 ;
for ( V_233 = 0 ; V_233 < V_1 -> V_11 ; V_233 ++ ) {
T_1 V_255 = F_103 ( V_232 , V_233 ) ;
T_1 V_256 = F_104 ( V_232 , V_233 ) ;
if ( V_255 > V_43 )
V_43 = V_255 ;
if ( V_256 > V_251 )
V_251 = V_256 ;
}
V_253 = F_105 ( V_1 ) ;
if ( V_43 >= V_253 )
V_43 = V_253 | V_257 ;
V_254 = F_106 ( V_1 , V_43 ) ;
if ( V_251 >= V_254 )
V_251 = V_254 | V_258 ;
for ( V_233 = 0 ; V_233 < 4 ; V_233 ++ )
V_1 -> V_259 [ V_233 ] = V_43 | V_251 ;
}
static T_2
F_108 ( T_1 V_259 )
{
T_2 V_260 = 0 ;
switch ( V_259 & V_245 ) {
case V_246 :
default:
V_260 |= V_158 ;
break;
case V_248 :
V_260 |= V_261 ;
break;
case V_242 :
V_260 |= V_262 ;
break;
case V_243 :
V_260 |= V_263 ;
break;
}
switch ( V_259 & V_264 ) {
case V_250 :
default:
V_260 |= V_159 ;
break;
case V_249 :
V_260 |= V_265 ;
break;
case V_247 :
V_260 |= V_266 ;
break;
case V_267 :
V_260 |= V_268 ;
break;
}
return V_260 ;
}
static T_2
F_109 ( T_1 V_259 )
{
int V_260 = V_259 & ( V_245 |
V_264 ) ;
switch ( V_260 ) {
case V_246 | V_250 :
case V_248 | V_250 :
return V_269 ;
case V_246 | V_249 :
return V_270 ;
case V_246 | V_247 :
case V_248 | V_247 :
return V_271 ;
case V_248 | V_249 :
case V_242 | V_249 :
return V_272 ;
case V_242 | V_250 :
case V_243 | V_250 :
return V_273 ;
default:
F_26 ( L_43
L_44 , V_260 ) ;
return V_269 ;
}
}
static T_2
F_110 ( T_1 V_259 )
{
int V_260 = V_259 & ( V_245 |
V_264 ) ;
switch ( V_260 ) {
case V_246 | V_250 :
return V_274 ;
case V_246 | V_249 :
return V_275 ;
case V_246 | V_247 :
return V_276 ;
case V_248 | V_250 :
return V_277 ;
case V_248 | V_249 :
return V_278 ;
case V_242 | V_250 :
return V_279 ;
case V_242 | V_249 :
return V_280 ;
default:
F_26 ( L_43
L_44 , V_260 ) ;
return V_281 ;
}
}
static T_1
F_111 ( T_1 V_228 [ V_229 ] ,
int V_233 )
{
int V_234 = ( V_233 & 1 ) * 4 ;
T_1 V_237 = V_228 [ V_233 >> 1 ] ;
return ( V_237 >> V_234 ) & 0xf ;
}
static bool
F_112 ( T_1 V_228 [ V_229 ] , int V_11 )
{
int V_233 ;
T_1 V_282 ;
for ( V_233 = 0 ; V_233 < V_11 ; V_233 ++ ) {
V_282 = F_111 ( V_228 , V_233 ) ;
if ( ( V_282 & V_283 ) == 0 )
return false ;
}
return true ;
}
static bool
F_113 ( struct V_1 * V_1 , T_1 V_228 [ V_229 ] )
{
T_1 V_284 ;
T_1 V_282 ;
int V_233 ;
V_284 = F_102 ( V_228 ,
V_285 ) ;
if ( ( V_284 & V_286 ) == 0 )
return false ;
for ( V_233 = 0 ; V_233 < V_1 -> V_11 ; V_233 ++ ) {
V_282 = F_111 ( V_228 , V_233 ) ;
if ( ( V_282 & V_287 ) != V_287 )
return false ;
}
return true ;
}
static bool
F_114 ( struct V_1 * V_1 ,
T_2 V_288 ,
T_1 V_289 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
int V_91 ;
if ( F_63 ( V_47 ) && ( F_29 ( V_47 ) || ! F_3 ( V_1 ) ) ) {
V_288 &= ~ V_290 ;
switch ( V_289 & V_291 ) {
case V_292 :
V_288 |= V_175 ;
break;
case V_293 :
V_288 |= V_294 ;
break;
case V_295 :
V_288 |= V_296 ;
break;
case V_297 :
F_34 ( L_45 ) ;
V_288 |= V_296 ;
break;
}
} else {
V_288 &= ~ V_298 ;
switch ( V_289 & V_291 ) {
case V_292 :
V_288 |= V_180 ;
break;
case V_293 :
V_288 |= V_299 ;
break;
case V_295 :
V_288 |= V_300 ;
break;
case V_297 :
F_34 ( L_45 ) ;
V_288 |= V_300 ;
break;
}
}
F_32 ( V_1 -> V_70 , V_288 ) ;
F_70 ( V_1 -> V_70 ) ;
F_36 ( V_1 ,
V_301 ,
V_289 ) ;
if ( ( V_289 & V_291 ) !=
V_292 ) {
V_91 = F_35 ( V_1 ,
V_302 ,
V_1 -> V_259 ,
V_1 -> V_11 ) ;
if ( V_91 != V_1 -> V_11 )
return false ;
}
return true ;
}
static void
F_97 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
int V_42 ;
T_1 V_303 ;
bool V_304 = false ;
int V_305 , V_306 ;
T_2 V_156 = V_1 -> V_156 ;
F_35 ( V_1 , V_307 ,
V_1 -> V_165 ,
V_166 ) ;
V_156 |= V_212 ;
memset ( V_1 -> V_259 , 0 , 4 ) ;
V_303 = 0xff ;
V_305 = 0 ;
V_306 = 0 ;
V_304 = false ;
for (; ; ) {
T_1 V_228 [ V_229 ] ;
T_2 V_260 ;
if ( F_29 ( V_47 ) && F_3 ( V_1 ) ) {
V_260 = F_110 ( V_1 -> V_259 [ 0 ] ) ;
V_156 = ( V_156 & ~ V_308 ) | V_260 ;
} else if ( F_28 ( V_47 ) && F_3 ( V_1 ) ) {
V_260 = F_109 ( V_1 -> V_259 [ 0 ] ) ;
V_156 = ( V_156 & ~ V_309 ) | V_260 ;
} else {
V_260 = F_108 ( V_1 -> V_259 [ 0 ] ) ;
F_26 ( L_46 , V_260 ) ;
V_156 = ( V_156 & ~ ( V_310 | V_311 ) ) | V_260 ;
}
if ( ! F_114 ( V_1 , V_156 ,
V_293 |
V_312 ) )
break;
F_33 ( 100 ) ;
if ( ! F_101 ( V_1 , V_228 ) ) {
F_34 ( L_47 ) ;
break;
}
if ( F_112 ( V_228 , V_1 -> V_11 ) ) {
F_26 ( L_48 ) ;
V_304 = true ;
break;
}
for ( V_42 = 0 ; V_42 < V_1 -> V_11 ; V_42 ++ )
if ( ( V_1 -> V_259 [ V_42 ] & V_257 ) == 0 )
break;
if ( V_42 == V_1 -> V_11 && V_305 == 5 ) {
++ V_306 ;
if ( V_306 == 5 ) {
F_26 ( L_49 ) ;
break;
}
memset ( V_1 -> V_259 , 0 , 4 ) ;
V_305 = 0 ;
continue;
}
if ( ( V_1 -> V_259 [ 0 ] & V_245 ) == V_303 ) {
++ V_305 ;
if ( V_305 == 5 ) {
F_26 ( L_50 ) ;
break;
}
} else
V_305 = 0 ;
V_303 = V_1 -> V_259 [ 0 ] & V_245 ;
F_107 ( V_1 , V_228 ) ;
}
V_1 -> V_156 = V_156 ;
}
static void
F_98 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
bool V_313 = false ;
int V_314 , V_315 ;
T_2 V_156 = V_1 -> V_156 ;
V_314 = 0 ;
V_315 = 0 ;
V_313 = false ;
for (; ; ) {
T_2 V_260 ;
T_1 V_228 [ V_229 ] ;
if ( V_315 > 5 ) {
F_34 ( L_51 ) ;
F_93 ( V_1 ) ;
break;
}
if ( F_29 ( V_47 ) && F_3 ( V_1 ) ) {
V_260 = F_110 ( V_1 -> V_259 [ 0 ] ) ;
V_156 = ( V_156 & ~ V_308 ) | V_260 ;
} else if ( F_28 ( V_47 ) && F_3 ( V_1 ) ) {
V_260 = F_109 ( V_1 -> V_259 [ 0 ] ) ;
V_156 = ( V_156 & ~ V_309 ) | V_260 ;
} else {
V_260 = F_108 ( V_1 -> V_259 [ 0 ] ) ;
V_156 = ( V_156 & ~ ( V_310 | V_311 ) ) | V_260 ;
}
if ( ! F_114 ( V_1 , V_156 ,
V_295 |
V_312 ) )
break;
F_33 ( 400 ) ;
if ( ! F_101 ( V_1 , V_228 ) )
break;
if ( ! F_112 ( V_228 , V_1 -> V_11 ) ) {
F_97 ( V_1 ) ;
V_315 ++ ;
continue;
}
if ( F_113 ( V_1 , V_228 ) ) {
V_313 = true ;
break;
}
if ( V_314 > 5 ) {
F_93 ( V_1 ) ;
F_97 ( V_1 ) ;
V_314 = 0 ;
V_315 ++ ;
continue;
}
F_107 ( V_1 , V_228 ) ;
++ V_314 ;
}
F_114 ( V_1 , V_156 , V_292 ) ;
}
static void
F_93 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_156 = V_1 -> V_156 ;
if ( F_96 ( ( F_21 ( V_1 -> V_70 ) & V_212 ) == 0 ) )
return;
F_26 ( L_37 ) ;
if ( F_63 ( V_47 ) && ( F_29 ( V_47 ) || ! F_3 ( V_1 ) ) ) {
V_156 &= ~ V_290 ;
F_32 ( V_1 -> V_70 , V_156 | V_316 ) ;
} else {
V_156 &= ~ V_298 ;
F_32 ( V_1 -> V_70 , V_156 | V_317 ) ;
}
F_70 ( V_1 -> V_70 ) ;
F_31 ( 17 ) ;
if ( F_115 ( V_47 ) &&
F_21 ( V_1 -> V_70 ) & V_181 ) {
struct V_150 * V_151 = V_1 -> V_2 . V_2 . V_151 ;
V_156 &= ~ V_181 ;
F_32 ( V_1 -> V_70 , V_156 ) ;
if ( V_151 == NULL ) {
F_70 ( V_1 -> V_70 ) ;
F_31 ( 50 ) ;
} else
F_116 ( V_47 , F_49 ( V_151 ) -> V_153 ) ;
}
V_156 &= ~ V_164 ;
F_32 ( V_1 -> V_70 , V_156 & ~ V_212 ) ;
F_70 ( V_1 -> V_70 ) ;
F_31 ( V_1 -> V_196 ) ;
}
static bool
F_117 ( struct V_1 * V_1 )
{
if ( F_100 ( V_1 , 0x000 , V_1 -> V_18 ,
sizeof( V_1 -> V_18 ) ) == 0 )
return false ;
if ( V_1 -> V_18 [ V_168 ] == 0 )
return false ;
if ( ! ( V_1 -> V_18 [ V_318 ] &
V_319 ) )
return true ;
if ( V_1 -> V_18 [ V_168 ] == 0x10 )
return true ;
if ( F_100 ( V_1 , V_320 ,
V_1 -> V_321 ,
V_322 ) == 0 )
return false ;
return true ;
}
static void
F_118 ( struct V_1 * V_1 )
{
T_5 V_323 [ 3 ] ;
if ( ! ( V_1 -> V_18 [ V_324 ] & V_325 ) )
return;
F_40 ( V_1 ) ;
if ( F_100 ( V_1 , V_326 , V_323 , 3 ) )
F_26 ( L_52 ,
V_323 [ 0 ] , V_323 [ 1 ] , V_323 [ 2 ] ) ;
if ( F_100 ( V_1 , V_327 , V_323 , 3 ) )
F_26 ( L_53 ,
V_323 [ 0 ] , V_323 [ 1 ] , V_323 [ 2 ] ) ;
F_42 ( V_1 , false ) ;
}
static bool
F_119 ( struct V_1 * V_1 , T_5 * V_328 )
{
int V_91 ;
V_91 = F_100 ( V_1 ,
V_329 ,
V_328 , 1 ) ;
if ( ! V_91 )
return false ;
return true ;
}
static void
F_120 ( struct V_1 * V_1 )
{
F_36 ( V_1 , V_330 , V_331 ) ;
}
static void
F_121 ( struct V_1 * V_1 )
{
T_5 V_328 ;
T_5 V_228 [ V_229 ] ;
if ( ! V_1 -> V_2 . V_332 )
return;
if ( F_96 ( ! V_1 -> V_2 . V_2 . V_151 ) )
return;
if ( ! F_101 ( V_1 , V_228 ) ) {
F_93 ( V_1 ) ;
return;
}
if ( ! F_117 ( V_1 ) ) {
F_93 ( V_1 ) ;
return;
}
if ( V_1 -> V_18 [ V_168 ] >= 0x11 &&
F_119 ( V_1 , & V_328 ) ) {
F_36 ( V_1 ,
V_329 ,
V_328 ) ;
if ( V_328 & V_333 )
F_120 ( V_1 ) ;
if ( V_328 & ( V_334 | V_335 ) )
F_60 ( L_54 ) ;
}
if ( ! F_113 ( V_1 , V_228 ) ) {
F_26 ( L_55 ,
F_122 ( & V_1 -> V_2 . V_2 ) ) ;
F_97 ( V_1 ) ;
F_98 ( V_1 ) ;
}
}
static enum V_336
F_123 ( struct V_1 * V_1 )
{
T_1 * V_18 = V_1 -> V_18 ;
bool V_337 ;
T_1 type ;
if ( ! F_117 ( V_1 ) )
return V_338 ;
if ( ! ( V_18 [ V_318 ] & V_319 ) )
return V_339 ;
V_337 = ! ! ( V_1 -> V_321 [ 0 ] & V_340 ) ;
if ( V_337 ) {
T_1 V_341 ;
if ( ! F_100 ( V_1 , V_342 ,
& V_341 , 1 ) )
return V_343 ;
return F_124 ( V_341 ) ? V_339
: V_338 ;
}
if ( F_125 ( & V_1 -> V_105 ) )
return V_339 ;
type = V_1 -> V_321 [ 0 ] & V_344 ;
if ( type == V_345 || type == V_346 )
return V_343 ;
F_26 ( L_56 ) ;
return V_338 ;
}
static enum V_336
F_126 ( struct V_1 * V_1 )
{
enum V_336 V_74 ;
if ( F_1 ( V_1 ) ) {
V_74 = F_127 ( V_1 -> V_2 . V_2 . V_47 ) ;
if ( V_74 == V_343 )
V_74 = V_339 ;
return V_74 ;
}
return F_123 ( V_1 ) ;
}
static enum V_336
F_128 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_347 ;
switch ( V_1 -> V_70 ) {
case V_348 :
V_347 = V_349 ;
break;
case V_350 :
V_347 = V_351 ;
break;
case V_352 :
V_347 = V_353 ;
break;
default:
return V_343 ;
}
if ( ( F_21 ( V_354 ) & V_347 ) == 0 )
return V_338 ;
return F_123 ( V_1 ) ;
}
static struct V_355 *
F_129 ( struct V_6 * V_7 , struct V_104 * V_105 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_355 * V_355 ;
int V_356 ;
if ( F_1 ( V_1 ) ) {
if ( ! V_1 -> V_355 )
return NULL ;
V_356 = ( V_1 -> V_355 -> V_357 + 1 ) * V_358 ;
V_355 = F_130 ( V_356 , V_359 ) ;
if ( ! V_355 )
return NULL ;
memcpy ( V_355 , V_1 -> V_355 , V_356 ) ;
return V_355 ;
}
V_355 = F_131 ( V_7 , V_105 ) ;
return V_355 ;
}
static int
F_132 ( struct V_6 * V_7 , struct V_104 * V_105 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
int V_91 ;
if ( F_1 ( V_1 ) ) {
F_133 ( V_7 ,
V_1 -> V_355 ) ;
V_91 = F_134 ( V_7 , V_1 -> V_355 ) ;
F_135 ( V_7 ,
V_1 -> V_355 ) ;
return V_1 -> V_360 ;
}
V_91 = F_136 ( V_7 , V_105 ) ;
return V_91 ;
}
static enum V_336
F_137 ( struct V_6 * V_7 , bool V_361 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
enum V_336 V_74 ;
struct V_355 * V_355 = NULL ;
V_1 -> V_163 = false ;
if ( F_30 ( V_47 ) )
V_74 = F_126 ( V_1 ) ;
else
V_74 = F_128 ( V_1 ) ;
F_26 ( L_57 ,
V_1 -> V_18 [ 0 ] , V_1 -> V_18 [ 1 ] , V_1 -> V_18 [ 2 ] ,
V_1 -> V_18 [ 3 ] , V_1 -> V_18 [ 4 ] , V_1 -> V_18 [ 5 ] ,
V_1 -> V_18 [ 6 ] , V_1 -> V_18 [ 7 ] ) ;
if ( V_74 != V_339 )
return V_74 ;
F_118 ( V_1 ) ;
if ( V_1 -> V_362 != V_363 ) {
V_1 -> V_163 = ( V_1 -> V_362 == V_364 ) ;
} else {
V_355 = F_129 ( V_7 , & V_1 -> V_105 ) ;
if ( V_355 ) {
V_1 -> V_163 = F_138 ( V_355 ) ;
F_139 ( V_355 ) ;
}
}
return V_339 ;
}
static int F_140 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
int V_91 ;
V_91 = F_132 ( V_7 , & V_1 -> V_105 ) ;
if ( V_91 ) {
if ( F_1 ( V_1 ) && ! V_1 -> V_16 ) {
struct V_14 * V_365 ;
F_141 (newmode, &connector->probed_modes,
head) {
if ( ( V_365 -> type & V_366 ) ) {
V_1 -> V_16 =
F_142 ( V_47 , V_365 ) ;
break;
}
}
}
return V_91 ;
}
if ( F_1 ( V_1 ) ) {
if ( V_1 -> V_16 == NULL && V_49 -> V_367 != NULL ) {
V_1 -> V_16 =
F_142 ( V_47 , V_49 -> V_367 ) ;
if ( V_1 -> V_16 ) {
V_1 -> V_16 -> type |=
V_366 ;
}
}
if ( V_1 -> V_16 ) {
struct V_14 * V_15 ;
V_15 = F_142 ( V_47 , V_1 -> V_16 ) ;
F_143 ( V_7 , V_15 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_144 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_355 * V_355 ;
bool V_163 = false ;
V_355 = F_129 ( V_7 , & V_1 -> V_105 ) ;
if ( V_355 ) {
V_163 = F_138 ( V_355 ) ;
F_139 ( V_355 ) ;
}
return V_163 ;
}
static int
F_145 ( struct V_6 * V_7 ,
struct V_368 * V_369 ,
T_6 V_370 )
{
struct V_48 * V_49 = V_7 -> V_47 -> V_50 ;
struct V_1 * V_1 = F_6 ( V_7 ) ;
int V_91 ;
V_91 = F_146 ( V_7 , V_369 , V_370 ) ;
if ( V_91 )
return V_91 ;
if ( V_369 == V_49 -> V_371 ) {
int V_42 = V_370 ;
bool V_163 ;
if ( V_42 == V_1 -> V_362 )
return 0 ;
V_1 -> V_362 = V_42 ;
if ( V_42 == V_363 )
V_163 = F_144 ( V_7 ) ;
else
V_163 = ( V_42 == V_364 ) ;
if ( V_163 == V_1 -> V_163 )
return 0 ;
V_1 -> V_163 = V_163 ;
goto V_372;
}
if ( V_369 == V_49 -> V_373 ) {
if ( V_370 == ! ! V_1 -> V_179 )
return 0 ;
V_1 -> V_179 = V_370 ? V_374 : 0 ;
goto V_372;
}
return - V_375 ;
V_372:
if ( V_1 -> V_2 . V_2 . V_151 ) {
struct V_150 * V_151 = V_1 -> V_2 . V_2 . V_151 ;
F_147 ( V_151 , & V_151 -> V_15 ,
V_151 -> V_376 , V_151 -> V_377 , V_151 -> V_378 ) ;
}
return 0 ;
}
static void
F_148 ( struct V_6 * V_7 )
{
struct V_46 * V_47 = V_7 -> V_47 ;
struct V_1 * V_1 = F_6 ( V_7 ) ;
if ( F_1 ( V_1 ) )
F_149 ( V_47 ) ;
F_150 ( V_7 ) ;
F_151 ( V_7 ) ;
F_139 ( V_7 ) ;
}
static void F_152 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
F_153 ( & V_1 -> V_105 ) ;
F_154 ( V_5 ) ;
if ( F_1 ( V_1 ) ) {
F_139 ( V_1 -> V_355 ) ;
F_155 ( & V_1 -> V_199 ) ;
F_71 ( V_1 ) ;
}
F_139 ( V_1 ) ;
}
static void
F_156 ( struct V_8 * V_8 )
{
struct V_1 * V_1 = F_5 ( V_8 , struct V_1 , V_2 ) ;
F_121 ( V_1 ) ;
}
int
F_157 ( struct V_150 * V_151 )
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
bool F_158 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_379 * V_380 ;
int V_42 ;
if ( ! V_49 -> V_381 )
return false ;
for ( V_42 = 0 ; V_42 < V_49 -> V_381 ; V_42 ++ ) {
V_380 = V_49 -> V_382 + V_42 ;
if ( V_380 -> V_383 == V_384 &&
V_380 -> V_385 == V_386 )
return true ;
}
return false ;
}
static void
F_159 ( struct V_1 * V_1 , struct V_6 * V_7 )
{
F_160 ( V_7 ) ;
F_161 ( V_7 ) ;
}
void
F_162 ( struct V_46 * V_47 , int V_70 , enum V_387 V_387 )
{
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
struct V_8 * V_8 ;
struct V_123 * V_123 ;
const char * V_124 = NULL ;
int type ;
V_1 = F_163 ( sizeof( struct V_1 ) , V_359 ) ;
if ( ! V_1 )
return;
V_1 -> V_70 = V_70 ;
V_1 -> V_387 = V_387 ;
V_1 -> V_156 = F_21 ( V_1 -> V_70 ) ;
V_123 = F_163 ( sizeof( struct V_123 ) , V_359 ) ;
if ( ! V_123 ) {
F_139 ( V_1 ) ;
return;
}
V_8 = & V_1 -> V_2 ;
if ( F_30 ( V_47 ) && V_70 == V_224 )
if ( F_158 ( V_47 ) )
V_1 -> F_2 = true ;
if ( V_70 == V_210 || F_2 ( V_1 ) ) {
type = V_388 ;
V_8 -> type = V_3 ;
} else {
type = V_389 ;
V_8 -> type = V_154 ;
}
V_7 = & V_123 -> V_2 ;
F_164 ( V_47 , V_7 , & V_390 , type ) ;
F_165 ( V_7 , & V_391 ) ;
V_7 -> V_392 = V_393 ;
V_8 -> V_394 = false ;
F_166 ( & V_1 -> V_199 ,
F_72 ) ;
V_8 -> V_395 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_7 -> V_396 = true ;
V_7 -> V_397 = 0 ;
F_167 ( V_47 , & V_8 -> V_2 , & V_398 ,
V_399 ) ;
F_168 ( & V_8 -> V_2 , & V_400 ) ;
F_169 ( V_123 , V_8 ) ;
F_170 ( V_7 ) ;
V_8 -> V_401 = F_95 ;
V_8 -> V_402 = F_99 ;
V_8 -> V_403 = F_92 ;
V_8 -> V_404 = F_94 ;
V_8 -> V_405 = F_87 ;
V_123 -> V_405 = V_406 ;
switch ( V_387 ) {
case V_407 :
V_124 = L_58 ;
break;
case V_408 :
V_49 -> V_409 |= V_410 ;
V_124 = L_59 ;
break;
case V_411 :
V_49 -> V_409 |= V_412 ;
V_124 = L_60 ;
break;
case V_413 :
V_49 -> V_409 |= V_414 ;
V_124 = L_61 ;
break;
default:
F_25 ( 1 , L_62 , F_171 ( V_387 ) ) ;
break;
}
if ( F_1 ( V_1 ) ) {
struct V_415 V_416 , V_417 ;
T_4 V_418 , V_419 , V_420 ;
V_418 = F_21 ( V_421 ) ;
V_419 = F_21 ( V_422 ) ;
V_420 = F_21 ( V_423 ) ;
if ( ! V_418 || ! V_419 || ! V_420 ) {
F_172 ( L_63 ) ;
F_152 ( & V_1 -> V_2 . V_2 ) ;
F_148 ( & V_123 -> V_2 ) ;
return;
}
V_416 . V_424 = ( V_418 & V_425 ) >>
V_426 ;
V_416 . V_427 = ( V_418 & V_428 ) >>
V_429 ;
V_416 . V_430 = ( V_419 & V_431 ) >>
V_432 ;
V_416 . V_433 = ( V_419 & V_434 ) >>
V_435 ;
V_416 . V_436 = ( ( V_420 & V_437 ) >>
V_438 ) * 1000 ;
F_26 ( L_64 ,
V_416 . V_424 , V_416 . V_427 , V_416 . V_430 , V_416 . V_433 , V_416 . V_436 ) ;
V_417 = V_49 -> V_439 . V_440 ;
F_26 ( L_65 ,
V_417 . V_424 , V_417 . V_427 , V_417 . V_430 , V_417 . V_433 , V_417 . V_436 ) ;
#define F_173 ( T_7 ) ((max(cur.field, vbt.field) + 9) / 10)
V_1 -> V_195 = F_173 ( V_424 ) ;
V_1 -> V_207 = F_173 ( V_427 ) ;
V_1 -> V_208 = F_173 ( V_430 ) ;
V_1 -> V_196 = F_173 ( V_433 ) ;
V_1 -> V_203 = F_173 ( V_436 ) ;
F_26 ( L_66 ,
V_1 -> V_195 , V_1 -> V_196 ,
V_1 -> V_203 ) ;
F_26 ( L_67 ,
V_1 -> V_207 , V_1 -> V_208 ) ;
}
F_39 ( V_1 , V_123 , V_124 ) ;
if ( F_1 ( V_1 ) ) {
bool V_91 ;
struct V_355 * V_355 ;
F_40 ( V_1 ) ;
V_91 = F_117 ( V_1 ) ;
F_42 ( V_1 , false ) ;
if ( V_91 ) {
if ( V_1 -> V_18 [ V_168 ] >= 0x11 )
V_49 -> V_441 =
V_1 -> V_18 [ V_442 ] &
V_443 ;
} else {
F_172 ( L_68 ) ;
F_152 ( & V_1 -> V_2 . V_2 ) ;
F_148 ( & V_123 -> V_2 ) ;
return;
}
F_40 ( V_1 ) ;
V_355 = F_131 ( V_7 , & V_1 -> V_105 ) ;
if ( V_355 ) {
F_133 ( V_7 ,
V_355 ) ;
V_1 -> V_360 =
F_134 ( V_7 , V_355 ) ;
F_135 ( V_7 , V_355 ) ;
V_1 -> V_355 = V_355 ;
}
F_42 ( V_1 , false ) ;
}
V_8 -> V_444 = F_156 ;
if ( F_1 ( V_1 ) ) {
V_49 -> V_445 = V_7 ;
F_174 ( V_47 ) ;
}
F_159 ( V_1 , V_7 ) ;
if ( F_175 ( V_47 ) && ! F_176 ( V_47 ) ) {
T_4 V_446 = F_21 ( V_447 ) ;
F_32 ( V_447 , ( V_446 & ~ 0xf ) | 0xd ) ;
}
}

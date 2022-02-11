static bool F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
return V_3 -> V_4 . type == V_5 ;
}
static bool F_3 ( struct V_1 * V_1 )
{
return V_1 -> F_3 ;
}
static bool F_4 ( struct V_1 * V_1 )
{
return F_1 ( V_1 ) && ! F_3 ( V_1 ) ;
}
static struct V_6 * F_5 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
return V_3 -> V_4 . V_4 . V_7 ;
}
static struct V_1 * F_6 ( struct V_8 * V_9 )
{
return F_7 ( & F_8 ( V_9 ) -> V_4 ) ;
}
bool F_9 ( struct V_10 * V_11 )
{
struct V_1 * V_1 ;
if ( ! V_11 )
return false ;
V_1 = F_7 ( V_11 ) ;
return F_3 ( V_1 ) ;
}
void
F_10 ( struct V_12 * V_12 ,
int * V_13 , int * V_14 )
{
struct V_1 * V_1 = F_7 ( & V_12 -> V_4 ) ;
* V_13 = V_1 -> V_15 ;
* V_14 = F_11 ( V_1 -> V_14 ) ;
}
int
F_12 ( struct V_12 * V_12 ,
struct V_16 * V_17 )
{
struct V_1 * V_1 = F_7 ( & V_12 -> V_4 ) ;
struct V_18 * V_18 = V_1 -> V_19 ;
if ( V_18 -> V_20 . V_21 )
return V_18 -> V_20 . V_21 -> clock ;
else
return V_17 -> clock ;
}
static int
F_13 ( struct V_1 * V_1 )
{
int V_22 = V_1 -> V_23 [ V_24 ] ;
switch ( V_22 ) {
case V_25 :
case V_26 :
break;
default:
V_22 = V_25 ;
break;
}
return V_22 ;
}
static int
F_14 ( T_1 V_14 )
{
if ( V_14 == V_26 )
return 270000 ;
else
return 162000 ;
}
static int
F_15 ( int V_27 , int V_28 )
{
return ( V_27 * V_28 + 9 ) / 10 ;
}
static int
F_16 ( int V_29 , int V_30 )
{
return ( V_29 * V_30 * 8 ) / 10 ;
}
static bool
F_17 ( struct V_1 * V_1 ,
struct V_16 * V_17 ,
bool V_31 )
{
int V_29 = F_14 ( F_13 ( V_1 ) ) ;
int V_30 = F_18 ( V_1 -> V_23 ) ;
int V_32 , V_33 ;
V_33 = F_15 ( V_17 -> clock , 24 ) ;
V_32 = F_16 ( V_29 , V_30 ) ;
if ( V_33 > V_32 ) {
V_33 = F_15 ( V_17 -> clock , 18 ) ;
if ( V_33 > V_32 )
return false ;
if ( V_31 )
V_17 -> V_34
|= V_35 ;
return true ;
}
return true ;
}
static int
F_19 ( struct V_8 * V_9 ,
struct V_16 * V_17 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
struct V_18 * V_18 = F_20 ( V_9 ) ;
struct V_16 * V_21 = V_18 -> V_20 . V_21 ;
if ( F_1 ( V_1 ) && V_21 ) {
if ( V_17 -> V_36 > V_21 -> V_36 )
return V_37 ;
if ( V_17 -> V_38 > V_21 -> V_38 )
return V_37 ;
}
if ( ! F_17 ( V_1 , V_17 , false ) )
return V_39 ;
if ( V_17 -> clock < 10000 )
return V_40 ;
if ( V_17 -> V_41 & V_42 )
return V_43 ;
return V_44 ;
}
static T_2
F_21 ( T_1 * V_45 , int V_46 )
{
int V_47 ;
T_2 V_48 = 0 ;
if ( V_46 > 4 )
V_46 = 4 ;
for ( V_47 = 0 ; V_47 < V_46 ; V_47 ++ )
V_48 |= ( ( T_2 ) V_45 [ V_47 ] ) << ( ( 3 - V_47 ) * 8 ) ;
return V_48 ;
}
static void
F_22 ( T_2 V_45 , T_1 * V_49 , int V_50 )
{
int V_47 ;
if ( V_50 > 4 )
V_50 = 4 ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ )
V_49 [ V_47 ] = V_45 >> ( ( 3 - V_47 ) * 8 ) ;
}
static int
F_23 ( struct V_6 * V_7 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
T_2 V_54 ;
if ( F_24 ( V_7 ) )
return 200 ;
V_54 = F_25 ( V_55 ) ;
switch ( V_54 & V_56 ) {
case V_57 :
return 100 ;
case V_58 :
return 133 ;
case V_59 :
return 166 ;
case V_60 :
return 200 ;
case V_61 :
return 266 ;
case V_62 :
return 333 ;
case V_63 :
case V_64 :
return 400 ;
default:
return 133 ;
}
}
static bool F_26 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
return ( F_25 ( V_65 ) & V_66 ) != 0 ;
}
static bool F_27 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
return ( F_25 ( V_67 ) & V_68 ) != 0 ;
}
static void
F_28 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_26 ( V_1 ) && ! F_27 ( V_1 ) ) {
F_29 ( 1 , L_1 ) ;
F_30 ( L_2 ,
F_25 ( V_65 ) ,
F_25 ( V_67 ) ) ;
}
}
static int
F_31 ( struct V_1 * V_1 ,
T_1 * V_69 , int V_70 ,
T_1 * V_71 , int V_72 )
{
T_2 V_73 = V_1 -> V_73 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_2 V_74 = V_73 + 0x10 ;
T_2 V_75 = V_74 + 4 ;
int V_47 ;
int V_76 ;
T_2 V_77 ;
T_2 V_78 ;
int V_79 , V_80 ;
if ( F_32 ( V_7 ) ) {
switch ( V_3 -> V_81 ) {
case V_82 :
V_74 = V_83 ;
V_75 = V_84 ;
break;
case V_85 :
V_74 = V_86 ;
V_75 = V_87 ;
break;
case V_88 :
V_74 = V_89 ;
V_75 = V_90 ;
break;
case V_91 :
V_74 = V_92 ;
V_75 = V_93 ;
break;
default:
F_33 () ;
}
}
F_28 ( V_1 ) ;
if ( F_4 ( V_1 ) ) {
if ( F_32 ( V_7 ) )
V_78 = F_34 ( V_52 ) >> 1 ;
else if ( F_24 ( V_7 ) )
V_78 = 100 ;
else if ( F_35 ( V_7 ) || F_36 ( V_7 ) )
V_78 = 200 ;
else
V_78 = 225 ;
} else if ( F_37 ( V_7 ) )
V_78 = F_38 ( F_39 ( V_7 ) , 2 ) ;
else
V_78 = F_23 ( V_7 ) / 2 ;
if ( F_35 ( V_7 ) )
V_80 = 3 ;
else
V_80 = 5 ;
for ( V_79 = 0 ; V_79 < 3 ; V_79 ++ ) {
V_77 = F_25 ( V_74 ) ;
if ( ( V_77 & V_94 ) == 0 )
break;
F_40 ( 1 ) ;
}
if ( V_79 == 3 ) {
F_29 ( 1 , L_3 ,
F_25 ( V_74 ) ) ;
return - V_95 ;
}
for ( V_79 = 0 ; V_79 < 5 ; V_79 ++ ) {
for ( V_47 = 0 ; V_47 < V_70 ; V_47 += 4 )
F_41 ( V_75 + V_47 ,
F_21 ( V_69 + V_47 , V_70 - V_47 ) ) ;
F_41 ( V_74 ,
V_94 |
V_96 |
( V_70 << V_97 ) |
( V_80 << V_98 ) |
( V_78 << V_99 ) |
V_100 |
V_101 |
V_102 ) ;
for (; ; ) {
V_77 = F_25 ( V_74 ) ;
if ( ( V_77 & V_94 ) == 0 )
break;
F_42 ( 100 ) ;
}
F_41 ( V_74 ,
V_77 |
V_100 |
V_101 |
V_102 ) ;
if ( V_77 & ( V_101 |
V_102 ) )
continue;
if ( V_77 & V_100 )
break;
}
if ( ( V_77 & V_100 ) == 0 ) {
F_43 ( L_4 , V_77 ) ;
return - V_95 ;
}
if ( V_77 & V_102 ) {
F_43 ( L_5 , V_77 ) ;
return - V_103 ;
}
if ( V_77 & V_101 ) {
F_30 ( L_6 , V_77 ) ;
return - V_104 ;
}
V_76 = ( ( V_77 & V_105 ) >>
V_97 ) ;
if ( V_76 > V_72 )
V_76 = V_72 ;
for ( V_47 = 0 ; V_47 < V_76 ; V_47 += 4 )
F_22 ( F_25 ( V_75 + V_47 ) ,
V_71 + V_47 , V_76 - V_47 ) ;
return V_76 ;
}
static int
F_44 ( struct V_1 * V_1 ,
T_3 V_106 , T_1 * V_69 , int V_70 )
{
int V_107 ;
T_1 V_108 [ 20 ] ;
int V_109 ;
T_1 V_110 ;
F_28 ( V_1 ) ;
if ( V_70 > 16 )
return - 1 ;
V_108 [ 0 ] = V_111 << 4 ;
V_108 [ 1 ] = V_106 >> 8 ;
V_108 [ 2 ] = V_106 & 0xff ;
V_108 [ 3 ] = V_70 - 1 ;
memcpy ( & V_108 [ 4 ] , V_69 , V_70 ) ;
V_109 = V_70 + 4 ;
for (; ; ) {
V_107 = F_31 ( V_1 , V_108 , V_109 , & V_110 , 1 ) ;
if ( V_107 < 0 )
return V_107 ;
if ( ( V_110 & V_112 ) == V_113 )
break;
else if ( ( V_110 & V_112 ) == V_114 )
F_42 ( 100 ) ;
else
return - V_103 ;
}
return V_70 ;
}
static int
F_45 ( struct V_1 * V_1 ,
T_3 V_106 , T_1 V_115 )
{
return F_44 ( V_1 , V_106 , & V_115 , 1 ) ;
}
static int
F_46 ( struct V_1 * V_1 ,
T_3 V_106 , T_1 * V_71 , int V_76 )
{
T_1 V_108 [ 4 ] ;
int V_109 ;
T_1 V_116 [ 20 ] ;
int V_117 ;
T_1 V_110 ;
int V_107 ;
F_28 ( V_1 ) ;
V_108 [ 0 ] = V_118 << 4 ;
V_108 [ 1 ] = V_106 >> 8 ;
V_108 [ 2 ] = V_106 & 0xff ;
V_108 [ 3 ] = V_76 - 1 ;
V_109 = 4 ;
V_117 = V_76 + 1 ;
for (; ; ) {
V_107 = F_31 ( V_1 , V_108 , V_109 ,
V_116 , V_117 ) ;
if ( V_107 == 0 )
return - V_119 ;
if ( V_107 < 0 )
return V_107 ;
V_110 = V_116 [ 0 ] ;
if ( ( V_110 & V_112 ) == V_113 ) {
memcpy ( V_71 , V_116 + 1 , V_107 - 1 ) ;
return V_107 - 1 ;
}
else if ( ( V_110 & V_112 ) == V_114 )
F_42 ( 100 ) ;
else
return - V_103 ;
}
}
static int
F_47 ( struct V_120 * V_121 , int V_17 ,
T_1 V_122 , T_1 * V_123 )
{
struct V_124 * V_125 = V_121 -> V_125 ;
struct V_1 * V_1 = F_48 ( V_121 ,
struct V_1 ,
V_121 ) ;
T_3 V_106 = V_125 -> V_106 ;
T_1 V_108 [ 5 ] ;
T_1 V_116 [ 2 ] ;
unsigned V_126 ;
int V_109 ;
int V_117 ;
int V_107 ;
F_28 ( V_1 ) ;
if ( V_17 & V_127 )
V_108 [ 0 ] = V_128 << 4 ;
else
V_108 [ 0 ] = V_129 << 4 ;
if ( ! ( V_17 & V_130 ) )
V_108 [ 0 ] |= V_131 << 4 ;
V_108 [ 1 ] = V_106 >> 8 ;
V_108 [ 2 ] = V_106 ;
switch ( V_17 ) {
case V_132 :
V_108 [ 3 ] = 0 ;
V_108 [ 4 ] = V_122 ;
V_109 = 5 ;
V_117 = 1 ;
break;
case V_127 :
V_108 [ 3 ] = 0 ;
V_109 = 4 ;
V_117 = 2 ;
break;
default:
V_109 = 3 ;
V_117 = 1 ;
break;
}
for ( V_126 = 0 ; V_126 < 5 ; V_126 ++ ) {
V_107 = F_31 ( V_1 ,
V_108 , V_109 ,
V_116 , V_117 ) ;
if ( V_107 < 0 ) {
F_30 ( L_7 , V_107 ) ;
return V_107 ;
}
switch ( V_116 [ 0 ] & V_112 ) {
case V_113 :
break;
case V_133 :
F_30 ( L_8 ) ;
return - V_134 ;
case V_114 :
F_42 ( 100 ) ;
continue;
default:
F_43 ( L_9 ,
V_116 [ 0 ] ) ;
return - V_134 ;
}
switch ( V_116 [ 0 ] & V_135 ) {
case V_136 :
if ( V_17 == V_127 ) {
* V_123 = V_116 [ 1 ] ;
}
return V_117 - 1 ;
case V_137 :
F_30 ( L_10 ) ;
return - V_134 ;
case V_138 :
F_30 ( L_11 ) ;
F_42 ( 100 ) ;
break;
default:
F_43 ( L_12 , V_116 [ 0 ] ) ;
return - V_134 ;
}
}
F_43 ( L_13 ) ;
return - V_134 ;
}
static int
F_49 ( struct V_1 * V_1 ,
struct V_18 * V_18 , const char * V_139 )
{
int V_107 ;
F_30 ( L_14 , V_139 ) ;
V_1 -> V_140 . V_141 = false ;
V_1 -> V_140 . V_106 = 0 ;
V_1 -> V_140 . V_142 = F_47 ;
memset ( & V_1 -> V_121 , '\0' , sizeof( V_1 -> V_121 ) ) ;
V_1 -> V_121 . V_143 = V_144 ;
V_1 -> V_121 . V_145 = V_146 ;
strncpy ( V_1 -> V_121 . V_139 , V_139 , sizeof( V_1 -> V_121 . V_139 ) - 1 ) ;
V_1 -> V_121 . V_139 [ sizeof( V_1 -> V_121 . V_139 ) - 1 ] = '\0' ;
V_1 -> V_121 . V_125 = & V_1 -> V_140 ;
V_1 -> V_121 . V_7 . V_147 = & V_18 -> V_4 . V_148 ;
F_50 ( V_1 ) ;
V_107 = F_51 ( & V_1 -> V_121 ) ;
F_52 ( V_1 , false ) ;
return V_107 ;
}
bool
F_53 ( struct V_10 * V_11 ,
const struct V_16 * V_17 ,
struct V_16 * V_149 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_1 * V_1 = F_7 ( V_11 ) ;
struct V_18 * V_18 = V_1 -> V_19 ;
int V_15 , clock ;
int V_150 = F_18 ( V_1 -> V_23 ) ;
int V_151 = F_13 ( V_1 ) == V_26 ? 1 : 0 ;
int V_28 , V_33 ;
static int V_152 [ 2 ] = { V_25 , V_26 } ;
if ( F_1 ( V_1 ) && V_18 -> V_20 . V_21 ) {
F_54 ( V_18 -> V_20 . V_21 ,
V_149 ) ;
F_55 ( V_7 ,
V_18 -> V_20 . V_153 ,
V_17 , V_149 ) ;
}
if ( V_149 -> V_41 & V_42 )
return false ;
F_30 ( L_15
L_16 ,
V_150 , V_152 [ V_151 ] , V_149 -> clock ) ;
if ( ! F_17 ( V_1 , V_149 , true ) )
return false ;
V_28 = V_149 -> V_34 & V_35 ? 18 : 24 ;
V_33 = F_15 ( V_149 -> clock , V_28 ) ;
for ( clock = 0 ; clock <= V_151 ; clock ++ ) {
for ( V_15 = 1 ; V_15 <= V_150 ; V_15 <<= 1 ) {
int V_154 = F_16 ( F_14 ( V_152 [ clock ] ) , V_15 ) ;
if ( V_33 <= V_154 ) {
V_1 -> V_14 = V_152 [ clock ] ;
V_1 -> V_15 = V_15 ;
V_149 -> clock = F_14 ( V_1 -> V_14 ) ;
F_30 ( L_17
L_18 ,
V_1 -> V_14 , V_1 -> V_15 ,
V_149 -> clock , V_28 ) ;
F_30 ( L_19 ,
V_33 , V_154 ) ;
return true ;
}
}
}
return false ;
}
static void
F_56 ( T_2 * V_155 , T_2 * V_156 )
{
while ( * V_155 > 0xffffff || * V_156 > 0xffffff ) {
* V_155 >>= 1 ;
* V_156 >>= 1 ;
}
}
static void
F_57 ( int V_28 ,
int V_157 ,
int V_27 ,
int V_158 ,
struct V_159 * V_160 )
{
V_160 -> V_161 = 64 ;
V_160 -> V_162 = ( V_27 * V_28 ) >> 3 ;
V_160 -> V_163 = V_158 * V_157 ;
F_56 ( & V_160 -> V_162 , & V_160 -> V_163 ) ;
V_160 -> V_164 = V_27 ;
V_160 -> V_165 = V_158 ;
F_56 ( & V_160 -> V_164 , & V_160 -> V_165 ) ;
}
void
F_58 ( struct V_166 * V_167 , struct V_16 * V_17 ,
struct V_16 * V_149 )
{
struct V_6 * V_7 = V_167 -> V_7 ;
struct V_12 * V_12 ;
struct V_1 * V_1 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_168 * V_168 = F_59 ( V_167 ) ;
int V_15 = 4 ;
struct V_159 V_160 ;
int V_169 = V_168 -> V_169 ;
enum V_170 V_171 = V_168 -> V_171 ;
F_60 (dev, crtc, intel_encoder) {
V_1 = F_7 ( & V_12 -> V_4 ) ;
if ( V_12 -> type == V_172 ||
V_12 -> type == V_5 )
{
V_15 = V_1 -> V_15 ;
break;
}
}
F_57 ( V_168 -> V_28 , V_15 ,
V_17 -> clock , V_149 -> clock , & V_160 ) ;
if ( F_32 ( V_7 ) ) {
F_41 ( F_61 ( V_171 ) ,
F_62 ( V_160 . V_161 ) | V_160 . V_162 ) ;
F_41 ( F_63 ( V_171 ) , V_160 . V_163 ) ;
F_41 ( F_64 ( V_171 ) , V_160 . V_164 ) ;
F_41 ( F_65 ( V_171 ) , V_160 . V_165 ) ;
} else if ( F_37 ( V_7 ) ) {
F_41 ( F_66 ( V_169 ) , F_62 ( V_160 . V_161 ) | V_160 . V_162 ) ;
F_41 ( F_67 ( V_169 ) , V_160 . V_163 ) ;
F_41 ( F_68 ( V_169 ) , V_160 . V_164 ) ;
F_41 ( F_69 ( V_169 ) , V_160 . V_165 ) ;
} else if ( F_24 ( V_7 ) ) {
F_41 ( F_61 ( V_169 ) , F_62 ( V_160 . V_161 ) | V_160 . V_162 ) ;
F_41 ( F_63 ( V_169 ) , V_160 . V_163 ) ;
F_41 ( F_64 ( V_169 ) , V_160 . V_164 ) ;
F_41 ( F_65 ( V_169 ) , V_160 . V_165 ) ;
} else {
F_41 ( F_70 ( V_169 ) ,
F_62 ( V_160 . V_161 ) | V_160 . V_162 ) ;
F_41 ( F_71 ( V_169 ) , V_160 . V_163 ) ;
F_41 ( F_72 ( V_169 ) , V_160 . V_164 ) ;
F_41 ( F_73 ( V_169 ) , V_160 . V_165 ) ;
}
}
void F_74 ( struct V_1 * V_1 )
{
memset ( V_1 -> V_173 , 0 , V_174 ) ;
V_1 -> V_173 [ 0 ] = V_1 -> V_14 ;
V_1 -> V_173 [ 1 ] = V_1 -> V_15 ;
V_1 -> V_173 [ 8 ] = V_175 ;
if ( V_1 -> V_23 [ V_176 ] >= 0x11 &&
( V_1 -> V_23 [ V_177 ] & V_178 ) ) {
V_1 -> V_173 [ 1 ] |= V_179 ;
}
}
static void
F_75 ( struct V_10 * V_11 , struct V_16 * V_17 ,
struct V_16 * V_149 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_1 * V_1 = F_7 ( V_11 ) ;
struct V_166 * V_167 = V_11 -> V_167 ;
struct V_168 * V_168 = F_59 ( V_167 ) ;
V_1 -> V_180 = F_25 ( V_1 -> V_73 ) & V_181 ;
V_1 -> V_180 |= V_182 | V_183 ;
switch ( V_1 -> V_15 ) {
case 1 :
V_1 -> V_180 |= V_184 ;
break;
case 2 :
V_1 -> V_180 |= V_185 ;
break;
case 4 :
V_1 -> V_180 |= V_186 ;
break;
}
if ( V_1 -> V_187 ) {
F_76 ( L_20 ,
F_77 ( V_168 -> V_169 ) ) ;
V_1 -> V_180 |= V_188 ;
F_78 ( V_11 , V_149 ) ;
}
F_74 ( V_1 ) ;
if ( F_4 ( V_1 ) && F_36 ( V_7 ) && ! F_24 ( V_7 ) ) {
if ( V_149 -> V_41 & V_189 )
V_1 -> V_180 |= V_190 ;
if ( V_149 -> V_41 & V_191 )
V_1 -> V_180 |= V_192 ;
V_1 -> V_180 |= V_193 ;
if ( V_1 -> V_173 [ 1 ] & V_179 )
V_1 -> V_180 |= V_194 ;
V_1 -> V_180 |= V_168 -> V_169 << 29 ;
if ( V_149 -> clock < 200000 )
V_1 -> V_180 |= V_195 ;
else
V_1 -> V_180 |= V_196 ;
} else if ( ! F_79 ( V_7 ) || F_4 ( V_1 ) ) {
V_1 -> V_180 |= V_1 -> V_197 ;
if ( V_149 -> V_41 & V_189 )
V_1 -> V_180 |= V_190 ;
if ( V_149 -> V_41 & V_191 )
V_1 -> V_180 |= V_192 ;
V_1 -> V_180 |= V_198 ;
if ( V_1 -> V_173 [ 1 ] & V_179 )
V_1 -> V_180 |= V_194 ;
if ( V_168 -> V_169 == 1 )
V_1 -> V_180 |= V_199 ;
if ( F_4 ( V_1 ) ) {
if ( V_149 -> clock < 200000 )
V_1 -> V_180 |= V_195 ;
else
V_1 -> V_180 |= V_196 ;
}
} else {
V_1 -> V_180 |= V_193 ;
}
}
static void F_80 ( struct V_1 * V_1 ,
T_4 V_200 ,
T_4 V_201 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
F_30 ( L_21 ,
V_200 , V_201 ,
F_25 ( V_65 ) ,
F_25 ( V_67 ) ) ;
if ( F_81 ( ( F_25 ( V_65 ) & V_200 ) == V_201 , 5000 , 10 ) ) {
F_43 ( L_22 ,
F_25 ( V_65 ) ,
F_25 ( V_67 ) ) ;
}
}
static void F_82 ( struct V_1 * V_1 )
{
F_30 ( L_23 ) ;
F_80 ( V_1 , V_202 , V_203 ) ;
}
static void F_83 ( struct V_1 * V_1 )
{
F_30 ( L_24 ) ;
F_80 ( V_1 , V_204 , V_205 ) ;
}
static void F_84 ( struct V_1 * V_1 )
{
F_30 ( L_25 ) ;
F_80 ( V_1 , V_206 , V_207 ) ;
}
static T_4 F_85 ( struct V_51 * V_52 )
{
T_4 V_208 = F_25 ( V_67 ) ;
V_208 &= ~ V_209 ;
V_208 |= V_210 ;
return V_208 ;
}
void F_50 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_211 ;
if ( ! F_1 ( V_1 ) )
return;
F_30 ( L_26 ) ;
F_29 ( V_1 -> V_212 ,
L_27 ) ;
V_1 -> V_212 = true ;
if ( F_27 ( V_1 ) ) {
F_30 ( L_28 ) ;
return;
}
if ( ! F_26 ( V_1 ) )
F_84 ( V_1 ) ;
V_211 = F_85 ( V_52 ) ;
V_211 |= V_68 ;
F_41 ( V_67 , V_211 ) ;
F_86 ( V_67 ) ;
F_30 ( L_29 ,
F_25 ( V_65 ) , F_25 ( V_67 ) ) ;
if ( ! F_26 ( V_1 ) ) {
F_30 ( L_30 ) ;
F_40 ( V_1 -> V_213 ) ;
}
}
static void F_87 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_211 ;
if ( ! V_1 -> V_212 && F_27 ( V_1 ) ) {
V_211 = F_85 ( V_52 ) ;
V_211 &= ~ V_68 ;
F_41 ( V_67 , V_211 ) ;
F_86 ( V_67 ) ;
F_30 ( L_29 ,
F_25 ( V_65 ) , F_25 ( V_67 ) ) ;
F_40 ( V_1 -> V_214 ) ;
}
}
static void F_88 ( struct V_215 * V_216 )
{
struct V_1 * V_1 = F_48 ( F_89 ( V_216 ) ,
struct V_1 , V_217 ) ;
struct V_6 * V_7 = F_5 ( V_1 ) ;
F_90 ( & V_7 -> V_218 . V_219 ) ;
F_87 ( V_1 ) ;
F_91 ( & V_7 -> V_218 . V_219 ) ;
}
void F_52 ( struct V_1 * V_1 , bool V_220 )
{
if ( ! F_1 ( V_1 ) )
return;
F_30 ( L_31 , V_1 -> V_212 ) ;
F_29 ( ! V_1 -> V_212 , L_32 ) ;
V_1 -> V_212 = false ;
if ( V_220 ) {
F_87 ( V_1 ) ;
} else {
F_92 ( & V_1 -> V_217 ,
F_93 ( V_1 -> V_221 * 5 ) ) ;
}
}
void F_94 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_211 ;
if ( ! F_1 ( V_1 ) )
return;
F_30 ( L_33 ) ;
if ( F_26 ( V_1 ) ) {
F_30 ( L_34 ) ;
return;
}
F_84 ( V_1 ) ;
V_211 = F_85 ( V_52 ) ;
if ( F_95 ( V_7 ) ) {
V_211 &= ~ V_222 ;
F_41 ( V_67 , V_211 ) ;
F_86 ( V_67 ) ;
}
V_211 |= V_223 ;
if ( ! F_95 ( V_7 ) )
V_211 |= V_222 ;
F_41 ( V_67 , V_211 ) ;
F_86 ( V_67 ) ;
F_82 ( V_1 ) ;
if ( F_95 ( V_7 ) ) {
V_211 |= V_222 ;
F_41 ( V_67 , V_211 ) ;
F_86 ( V_67 ) ;
}
}
void F_96 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_211 ;
if ( ! F_1 ( V_1 ) )
return;
F_30 ( L_35 ) ;
F_29 ( ! V_1 -> V_212 , L_36 ) ;
V_211 = F_85 ( V_52 ) ;
V_211 &= ~ ( V_223 | V_68 | V_222 | V_224 ) ;
F_41 ( V_67 , V_211 ) ;
F_86 ( V_67 ) ;
V_1 -> V_212 = false ;
F_83 ( V_1 ) ;
}
void F_97 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
int V_169 = F_59 ( V_3 -> V_4 . V_4 . V_167 ) -> V_169 ;
T_4 V_211 ;
if ( ! F_1 ( V_1 ) )
return;
F_30 ( L_37 ) ;
F_40 ( V_1 -> V_225 ) ;
V_211 = F_85 ( V_52 ) ;
V_211 |= V_224 ;
F_41 ( V_67 , V_211 ) ;
F_86 ( V_67 ) ;
F_98 ( V_7 , V_169 ) ;
}
void F_99 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_211 ;
if ( ! F_1 ( V_1 ) )
return;
F_100 ( V_7 ) ;
F_30 ( L_37 ) ;
V_211 = F_85 ( V_52 ) ;
V_211 &= ~ V_224 ;
F_41 ( V_67 , V_211 ) ;
F_86 ( V_67 ) ;
F_40 ( V_1 -> V_226 ) ;
}
static void F_101 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_166 * V_167 = V_3 -> V_4 . V_4 . V_167 ;
struct V_6 * V_7 = V_167 -> V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_227 ;
F_102 ( V_52 ,
F_59 ( V_167 ) -> V_169 ) ;
F_30 ( L_37 ) ;
V_227 = F_25 ( V_228 ) ;
F_29 ( V_227 & V_229 , L_38 ) ;
F_29 ( V_227 & V_230 , L_39 ) ;
V_1 -> V_180 &= ~ ( V_230 | V_188 ) ;
V_1 -> V_180 |= V_229 ;
F_41 ( V_228 , V_1 -> V_180 ) ;
F_86 ( V_228 ) ;
F_42 ( 200 ) ;
}
static void F_103 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_166 * V_167 = V_3 -> V_4 . V_4 . V_167 ;
struct V_6 * V_7 = V_167 -> V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_227 ;
F_102 ( V_52 ,
F_59 ( V_167 ) -> V_169 ) ;
V_227 = F_25 ( V_228 ) ;
F_29 ( ( V_227 & V_229 ) == 0 ,
L_40 ) ;
F_29 ( V_227 & V_230 , L_39 ) ;
V_227 &= ~ V_229 ;
F_41 ( V_228 , V_227 ) ;
F_86 ( V_228 ) ;
F_42 ( 200 ) ;
}
void F_104 ( struct V_1 * V_1 , int V_17 )
{
int V_107 , V_47 ;
if ( V_1 -> V_23 [ V_176 ] < 0x11 )
return;
if ( V_17 != V_231 ) {
V_107 = F_45 ( V_1 , V_232 ,
V_233 ) ;
if ( V_107 != 1 )
F_76 ( L_41 ) ;
} else {
for ( V_47 = 0 ; V_47 < 3 ; V_47 ++ ) {
V_107 = F_45 ( V_1 ,
V_232 ,
V_234 ) ;
if ( V_107 == 1 )
break;
F_40 ( 1 ) ;
}
}
}
static bool F_105 ( struct V_12 * V_11 ,
enum V_169 * V_169 )
{
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
struct V_6 * V_7 = V_11 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_235 = F_25 ( V_1 -> V_73 ) ;
if ( ! ( V_235 & V_230 ) )
return false ;
if ( F_4 ( V_1 ) && F_36 ( V_7 ) ) {
* V_169 = F_106 ( V_235 ) ;
} else if ( ! F_79 ( V_7 ) || F_4 ( V_1 ) ) {
* V_169 = F_107 ( V_235 ) ;
} else {
T_4 V_236 ;
T_4 V_237 ;
int V_47 ;
switch ( V_1 -> V_73 ) {
case V_238 :
V_236 = V_239 ;
break;
case V_240 :
V_236 = V_241 ;
break;
case V_242 :
V_236 = V_243 ;
break;
default:
return true ;
}
F_108 (i) {
V_237 = F_25 ( F_109 ( V_47 ) ) ;
if ( ( V_237 & V_244 ) == V_236 ) {
* V_169 = V_47 ;
return true ;
}
}
F_30 ( L_42 ,
V_1 -> V_73 ) ;
}
return true ;
}
static void F_110 ( struct V_12 * V_11 )
{
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
F_50 ( V_1 ) ;
F_99 ( V_1 ) ;
F_104 ( V_1 , V_231 ) ;
F_96 ( V_1 ) ;
if ( ! F_4 ( V_1 ) )
F_111 ( V_1 ) ;
}
static void F_112 ( struct V_12 * V_11 )
{
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
if ( F_4 ( V_1 ) ) {
F_111 ( V_1 ) ;
F_103 ( V_1 ) ;
}
}
static void F_113 ( struct V_12 * V_11 )
{
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
struct V_6 * V_7 = V_11 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_2 V_245 = F_25 ( V_1 -> V_73 ) ;
if ( F_114 ( V_245 & V_230 ) )
return;
F_50 ( V_1 ) ;
F_104 ( V_1 , V_231 ) ;
F_115 ( V_1 ) ;
F_94 ( V_1 ) ;
F_52 ( V_1 , true ) ;
F_116 ( V_1 ) ;
F_97 ( V_1 ) ;
}
static void F_117 ( struct V_12 * V_11 )
{
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
if ( F_4 ( V_1 ) )
F_101 ( V_1 ) ;
}
static bool
F_118 ( struct V_1 * V_1 , T_3 V_106 ,
T_1 * V_71 , int V_76 )
{
int V_107 , V_47 ;
for ( V_47 = 0 ; V_47 < 3 ; V_47 ++ ) {
V_107 = F_46 ( V_1 , V_106 , V_71 ,
V_76 ) ;
if ( V_107 == V_76 )
return true ;
F_40 ( 1 ) ;
}
return false ;
}
static bool
F_119 ( struct V_1 * V_1 , T_1 V_246 [ V_247 ] )
{
return F_118 ( V_1 ,
V_248 ,
V_246 ,
V_247 ) ;
}
static T_1
F_120 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
if ( F_36 ( V_7 ) && F_4 ( V_1 ) )
return V_249 ;
else if ( F_79 ( V_7 ) && ! F_4 ( V_1 ) )
return V_250 ;
else
return V_249 ;
}
static T_1
F_121 ( struct V_1 * V_1 , T_1 V_251 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
if ( F_32 ( V_7 ) ) {
switch ( V_251 & V_252 ) {
case V_253 :
return V_254 ;
case V_255 :
return V_256 ;
case V_249 :
return V_257 ;
case V_250 :
default:
return V_258 ;
}
} else if ( F_36 ( V_7 ) && F_4 ( V_1 ) && ! F_24 ( V_7 ) ) {
switch ( V_251 & V_252 ) {
case V_253 :
return V_256 ;
case V_255 :
case V_249 :
return V_257 ;
default:
return V_258 ;
}
} else {
switch ( V_251 & V_252 ) {
case V_253 :
return V_256 ;
case V_255 :
return V_256 ;
case V_249 :
return V_257 ;
case V_250 :
default:
return V_258 ;
}
}
}
static void
F_122 ( struct V_1 * V_1 , T_1 V_246 [ V_247 ] )
{
T_1 V_48 = 0 ;
T_1 V_259 = 0 ;
int V_260 ;
T_1 V_261 ;
T_1 V_262 ;
for ( V_260 = 0 ; V_260 < V_1 -> V_15 ; V_260 ++ ) {
T_1 V_263 = F_123 ( V_246 , V_260 ) ;
T_1 V_264 = F_124 ( V_246 , V_260 ) ;
if ( V_263 > V_48 )
V_48 = V_263 ;
if ( V_264 > V_259 )
V_259 = V_264 ;
}
V_261 = F_120 ( V_1 ) ;
if ( V_48 >= V_261 )
V_48 = V_261 | V_265 ;
V_262 = F_121 ( V_1 , V_48 ) ;
if ( V_259 >= V_262 )
V_259 = V_262 | V_266 ;
for ( V_260 = 0 ; V_260 < 4 ; V_260 ++ )
V_1 -> V_267 [ V_260 ] = V_48 | V_259 ;
}
static T_2
F_125 ( T_1 V_267 )
{
T_2 V_268 = 0 ;
switch ( V_267 & V_252 ) {
case V_253 :
default:
V_268 |= V_182 ;
break;
case V_255 :
V_268 |= V_269 ;
break;
case V_249 :
V_268 |= V_270 ;
break;
case V_250 :
V_268 |= V_271 ;
break;
}
switch ( V_267 & V_272 ) {
case V_258 :
default:
V_268 |= V_183 ;
break;
case V_257 :
V_268 |= V_273 ;
break;
case V_256 :
V_268 |= V_274 ;
break;
case V_254 :
V_268 |= V_275 ;
break;
}
return V_268 ;
}
static T_2
F_126 ( T_1 V_267 )
{
int V_268 = V_267 & ( V_252 |
V_272 ) ;
switch ( V_268 ) {
case V_253 | V_258 :
case V_255 | V_258 :
return V_276 ;
case V_253 | V_257 :
return V_277 ;
case V_253 | V_256 :
case V_255 | V_256 :
return V_278 ;
case V_255 | V_257 :
case V_249 | V_257 :
return V_279 ;
case V_249 | V_258 :
case V_250 | V_258 :
return V_280 ;
default:
F_30 ( L_43
L_44 , V_268 ) ;
return V_276 ;
}
}
static T_2
F_127 ( T_1 V_267 )
{
int V_268 = V_267 & ( V_252 |
V_272 ) ;
switch ( V_268 ) {
case V_253 | V_258 :
return V_281 ;
case V_253 | V_257 :
return V_282 ;
case V_253 | V_256 :
return V_283 ;
case V_255 | V_258 :
return V_284 ;
case V_255 | V_257 :
return V_285 ;
case V_249 | V_258 :
return V_286 ;
case V_249 | V_257 :
return V_287 ;
default:
F_30 ( L_43
L_44 , V_268 ) ;
return V_288 ;
}
}
static T_2
F_128 ( T_1 V_267 )
{
int V_268 = V_267 & ( V_252 |
V_272 ) ;
switch ( V_268 ) {
case V_253 | V_258 :
return V_289 ;
case V_253 | V_257 :
return V_290 ;
case V_253 | V_256 :
return V_291 ;
case V_253 | V_254 :
return V_292 ;
case V_255 | V_258 :
return V_293 ;
case V_255 | V_257 :
return V_294 ;
case V_255 | V_256 :
return V_295 ;
case V_249 | V_258 :
return V_296 ;
case V_249 | V_257 :
return V_297 ;
default:
F_30 ( L_43
L_44 , V_268 ) ;
return V_289 ;
}
}
static bool
F_129 ( struct V_1 * V_1 ,
T_2 V_298 ,
T_1 V_299 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_81 V_81 = V_3 -> V_81 ;
int V_107 ;
T_2 V_300 ;
if ( F_32 ( V_7 ) ) {
V_300 = F_25 ( F_130 ( V_81 ) ) ;
if ( V_299 & V_301 )
V_300 |= V_302 ;
else
V_300 &= ~ V_302 ;
V_300 &= ~ V_303 ;
switch ( V_299 & V_304 ) {
case V_305 :
V_300 |= V_306 ;
F_41 ( F_130 ( V_81 ) , V_300 ) ;
if ( F_131 ( ( F_25 ( F_132 ( V_81 ) ) &
V_307 ) , 1 ) )
F_43 ( L_45 ) ;
V_300 &= ~ V_303 ;
V_300 |= V_308 ;
break;
case V_309 :
V_300 |= V_310 ;
break;
case V_311 :
V_300 |= V_312 ;
break;
case V_313 :
V_300 |= V_314 ;
break;
}
F_41 ( F_130 ( V_81 ) , V_300 ) ;
} else if ( F_79 ( V_7 ) &&
( F_36 ( V_7 ) || ! F_4 ( V_1 ) ) ) {
V_298 &= ~ V_315 ;
switch ( V_299 & V_304 ) {
case V_305 :
V_298 |= V_193 ;
break;
case V_309 :
V_298 |= V_316 ;
break;
case V_311 :
V_298 |= V_317 ;
break;
case V_313 :
F_43 ( L_46 ) ;
V_298 |= V_317 ;
break;
}
} else {
V_298 &= ~ V_318 ;
switch ( V_299 & V_304 ) {
case V_305 :
V_298 |= V_198 ;
break;
case V_309 :
V_298 |= V_319 ;
break;
case V_311 :
V_298 |= V_320 ;
break;
case V_313 :
F_43 ( L_46 ) ;
V_298 |= V_320 ;
break;
}
}
F_41 ( V_1 -> V_73 , V_298 ) ;
F_86 ( V_1 -> V_73 ) ;
F_45 ( V_1 ,
V_321 ,
V_299 ) ;
if ( ( V_299 & V_304 ) !=
V_305 ) {
V_107 = F_44 ( V_1 ,
V_322 ,
V_1 -> V_267 ,
V_1 -> V_15 ) ;
if ( V_107 != V_1 -> V_15 )
return false ;
}
return true ;
}
void
F_115 ( struct V_1 * V_1 )
{
struct V_10 * V_11 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_11 -> V_7 ;
int V_47 ;
T_1 V_323 ;
bool V_324 = false ;
int V_325 , V_326 ;
T_2 V_180 = V_1 -> V_180 ;
if ( F_32 ( V_7 ) )
F_133 ( V_11 ) ;
F_44 ( V_1 , V_327 ,
V_1 -> V_173 ,
V_174 ) ;
V_180 |= V_230 ;
memset ( V_1 -> V_267 , 0 , 4 ) ;
V_323 = 0xff ;
V_325 = 0 ;
V_326 = 0 ;
V_324 = false ;
for (; ; ) {
T_1 V_246 [ V_247 ] ;
T_2 V_268 ;
if ( F_32 ( V_7 ) ) {
V_268 = F_128 (
V_1 -> V_267 [ 0 ] ) ;
V_180 = ( V_180 & ~ V_328 ) | V_268 ;
} else if ( F_36 ( V_7 ) && F_4 ( V_1 ) && ! F_24 ( V_7 ) ) {
V_268 = F_127 ( V_1 -> V_267 [ 0 ] ) ;
V_180 = ( V_180 & ~ V_329 ) | V_268 ;
} else if ( F_35 ( V_7 ) && F_4 ( V_1 ) ) {
V_268 = F_126 ( V_1 -> V_267 [ 0 ] ) ;
V_180 = ( V_180 & ~ V_330 ) | V_268 ;
} else {
V_268 = F_125 ( V_1 -> V_267 [ 0 ] ) ;
V_180 = ( V_180 & ~ ( V_331 | V_332 ) ) | V_268 ;
}
F_30 ( L_47 ,
V_268 ) ;
if ( ! F_129 ( V_1 , V_180 ,
V_309 |
V_301 ) )
break;
F_134 ( V_1 -> V_23 ) ;
if ( ! F_119 ( V_1 , V_246 ) ) {
F_43 ( L_48 ) ;
break;
}
if ( F_135 ( V_246 , V_1 -> V_15 ) ) {
F_30 ( L_49 ) ;
V_324 = true ;
break;
}
for ( V_47 = 0 ; V_47 < V_1 -> V_15 ; V_47 ++ )
if ( ( V_1 -> V_267 [ V_47 ] & V_265 ) == 0 )
break;
if ( V_47 == V_1 -> V_15 && V_325 == 5 ) {
++ V_326 ;
if ( V_326 == 5 ) {
F_30 ( L_50 ) ;
break;
}
memset ( V_1 -> V_267 , 0 , 4 ) ;
V_325 = 0 ;
continue;
}
if ( ( V_1 -> V_267 [ 0 ] & V_252 ) == V_323 ) {
++ V_325 ;
if ( V_325 == 5 ) {
F_30 ( L_51 ) ;
break;
}
} else
V_325 = 0 ;
V_323 = V_1 -> V_267 [ 0 ] & V_252 ;
F_122 ( V_1 , V_246 ) ;
}
V_1 -> V_180 = V_180 ;
}
void
F_116 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
bool V_333 = false ;
int V_334 , V_335 ;
T_2 V_180 = V_1 -> V_180 ;
V_334 = 0 ;
V_335 = 0 ;
V_333 = false ;
for (; ; ) {
T_2 V_268 ;
T_1 V_246 [ V_247 ] ;
if ( V_335 > 5 ) {
F_43 ( L_52 ) ;
F_111 ( V_1 ) ;
break;
}
if ( F_32 ( V_7 ) ) {
V_268 = F_128 ( V_1 -> V_267 [ 0 ] ) ;
V_180 = ( V_180 & ~ V_328 ) | V_268 ;
} else if ( F_36 ( V_7 ) && F_4 ( V_1 ) && ! F_24 ( V_7 ) ) {
V_268 = F_127 ( V_1 -> V_267 [ 0 ] ) ;
V_180 = ( V_180 & ~ V_329 ) | V_268 ;
} else if ( F_35 ( V_7 ) && F_4 ( V_1 ) ) {
V_268 = F_126 ( V_1 -> V_267 [ 0 ] ) ;
V_180 = ( V_180 & ~ V_330 ) | V_268 ;
} else {
V_268 = F_125 ( V_1 -> V_267 [ 0 ] ) ;
V_180 = ( V_180 & ~ ( V_331 | V_332 ) ) | V_268 ;
}
if ( ! F_129 ( V_1 , V_180 ,
V_311 |
V_301 ) )
break;
F_136 ( V_1 -> V_23 ) ;
if ( ! F_119 ( V_1 , V_246 ) )
break;
if ( ! F_135 ( V_246 , V_1 -> V_15 ) ) {
F_115 ( V_1 ) ;
V_335 ++ ;
continue;
}
if ( F_137 ( V_246 , V_1 -> V_15 ) ) {
V_333 = true ;
break;
}
if ( V_334 > 5 ) {
F_111 ( V_1 ) ;
F_115 ( V_1 ) ;
V_334 = 0 ;
V_335 ++ ;
continue;
}
F_122 ( V_1 , V_246 ) ;
++ V_334 ;
}
if ( V_333 )
F_30 ( L_53 ) ;
F_129 ( V_1 , V_180 , V_305 ) ;
}
static void
F_111 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_2 V_180 = V_1 -> V_180 ;
if ( F_32 ( V_7 ) )
return;
if ( F_114 ( ( F_25 ( V_1 -> V_73 ) & V_230 ) == 0 ) )
return;
F_30 ( L_37 ) ;
if ( F_79 ( V_7 ) && ( F_36 ( V_7 ) || ! F_4 ( V_1 ) ) ) {
V_180 &= ~ V_315 ;
F_41 ( V_1 -> V_73 , V_180 | V_336 ) ;
} else {
V_180 &= ~ V_318 ;
F_41 ( V_1 -> V_73 , V_180 | V_337 ) ;
}
F_86 ( V_1 -> V_73 ) ;
F_40 ( 17 ) ;
if ( F_138 ( V_7 ) &&
F_25 ( V_1 -> V_73 ) & V_199 ) {
struct V_166 * V_167 = V_3 -> V_4 . V_4 . V_167 ;
V_180 &= ~ V_199 ;
F_41 ( V_1 -> V_73 , V_180 ) ;
if ( V_167 == NULL ) {
F_86 ( V_1 -> V_73 ) ;
F_40 ( 50 ) ;
} else
F_139 ( V_7 , F_59 ( V_167 ) -> V_169 ) ;
}
V_180 &= ~ V_188 ;
F_41 ( V_1 -> V_73 , V_180 & ~ V_230 ) ;
F_86 ( V_1 -> V_73 ) ;
F_40 ( V_1 -> V_214 ) ;
}
static bool
F_140 ( struct V_1 * V_1 )
{
if ( F_118 ( V_1 , 0x000 , V_1 -> V_23 ,
sizeof( V_1 -> V_23 ) ) == 0 )
return false ;
if ( V_1 -> V_23 [ V_176 ] == 0 )
return false ;
if ( ! ( V_1 -> V_23 [ V_338 ] &
V_339 ) )
return true ;
if ( V_1 -> V_23 [ V_176 ] == 0x10 )
return true ;
if ( F_118 ( V_1 , V_340 ,
V_1 -> V_341 ,
V_342 ) == 0 )
return false ;
return true ;
}
static void
F_141 ( struct V_1 * V_1 )
{
T_5 V_343 [ 3 ] ;
if ( ! ( V_1 -> V_23 [ V_344 ] & V_345 ) )
return;
F_50 ( V_1 ) ;
if ( F_118 ( V_1 , V_346 , V_343 , 3 ) )
F_30 ( L_54 ,
V_343 [ 0 ] , V_343 [ 1 ] , V_343 [ 2 ] ) ;
if ( F_118 ( V_1 , V_347 , V_343 , 3 ) )
F_30 ( L_55 ,
V_343 [ 0 ] , V_343 [ 1 ] , V_343 [ 2 ] ) ;
F_52 ( V_1 , false ) ;
}
static bool
F_142 ( struct V_1 * V_1 , T_5 * V_348 )
{
int V_107 ;
V_107 = F_118 ( V_1 ,
V_349 ,
V_348 , 1 ) ;
if ( ! V_107 )
return false ;
return true ;
}
static void
F_143 ( struct V_1 * V_1 )
{
F_45 ( V_1 , V_350 , V_351 ) ;
}
void
F_144 ( struct V_1 * V_1 )
{
struct V_12 * V_12 = & F_2 ( V_1 ) -> V_4 ;
T_5 V_348 ;
T_5 V_246 [ V_247 ] ;
if ( ! V_12 -> V_352 )
return;
if ( F_114 ( ! V_12 -> V_4 . V_167 ) )
return;
if ( ! F_119 ( V_1 , V_246 ) ) {
F_111 ( V_1 ) ;
return;
}
if ( ! F_140 ( V_1 ) ) {
F_111 ( V_1 ) ;
return;
}
if ( V_1 -> V_23 [ V_176 ] >= 0x11 &&
F_142 ( V_1 , & V_348 ) ) {
F_45 ( V_1 ,
V_349 ,
V_348 ) ;
if ( V_348 & V_353 )
F_143 ( V_1 ) ;
if ( V_348 & ( V_354 | V_355 ) )
F_76 ( L_56 ) ;
}
if ( ! F_137 ( V_246 , V_1 -> V_15 ) ) {
F_30 ( L_57 ,
F_145 ( & V_12 -> V_4 ) ) ;
F_115 ( V_1 ) ;
F_116 ( V_1 ) ;
}
}
static enum V_356
F_146 ( struct V_1 * V_1 )
{
T_1 * V_23 = V_1 -> V_23 ;
bool V_357 ;
T_1 type ;
if ( ! F_140 ( V_1 ) )
return V_358 ;
if ( ! ( V_23 [ V_338 ] & V_339 ) )
return V_359 ;
V_357 = ! ! ( V_1 -> V_341 [ 0 ] & V_360 ) ;
if ( V_357 ) {
T_1 V_361 ;
if ( ! F_118 ( V_1 , V_362 ,
& V_361 , 1 ) )
return V_363 ;
return F_147 ( V_361 ) ? V_359
: V_358 ;
}
if ( F_148 ( & V_1 -> V_121 ) )
return V_359 ;
type = V_1 -> V_341 [ 0 ] & V_364 ;
if ( type == V_365 || type == V_366 )
return V_363 ;
F_30 ( L_58 ) ;
return V_358 ;
}
static enum V_356
F_149 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
enum V_356 V_77 ;
if ( F_1 ( V_1 ) ) {
V_77 = F_150 ( V_7 ) ;
if ( V_77 == V_363 )
V_77 = V_359 ;
return V_77 ;
}
return F_146 ( V_1 ) ;
}
static enum V_356
F_151 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_2 V_367 ;
switch ( V_1 -> V_73 ) {
case V_368 :
V_367 = V_369 ;
break;
case V_370 :
V_367 = V_371 ;
break;
case V_372 :
V_367 = V_373 ;
break;
default:
return V_363 ;
}
if ( ( F_25 ( V_374 ) & V_367 ) == 0 )
return V_358 ;
return F_146 ( V_1 ) ;
}
static struct V_375 *
F_152 ( struct V_8 * V_9 , struct V_120 * V_121 )
{
struct V_18 * V_18 = F_20 ( V_9 ) ;
if ( V_18 -> V_375 ) {
struct V_375 * V_375 ;
int V_376 ;
if ( F_153 ( V_18 -> V_375 ) )
return NULL ;
V_376 = ( V_18 -> V_375 -> V_377 + 1 ) * V_378 ;
V_375 = F_154 ( V_376 , V_379 ) ;
if ( ! V_375 )
return NULL ;
memcpy ( V_375 , V_18 -> V_375 , V_376 ) ;
return V_375 ;
}
return F_155 ( V_9 , V_121 ) ;
}
static int
F_156 ( struct V_8 * V_9 , struct V_120 * V_121 )
{
struct V_18 * V_18 = F_20 ( V_9 ) ;
if ( V_18 -> V_375 ) {
if ( F_153 ( V_18 -> V_375 ) )
return 0 ;
return F_157 ( V_9 ,
V_18 -> V_375 ) ;
}
return F_158 ( V_9 , V_121 ) ;
}
static enum V_356
F_159 ( struct V_8 * V_9 , bool V_380 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_12 * V_12 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_356 V_77 ;
struct V_375 * V_375 = NULL ;
char V_381 [ sizeof( V_1 -> V_23 ) * 3 ] ;
V_1 -> V_187 = false ;
if ( F_37 ( V_7 ) )
V_77 = F_149 ( V_1 ) ;
else
V_77 = F_151 ( V_1 ) ;
F_160 ( V_1 -> V_23 , sizeof( V_1 -> V_23 ) ,
32 , 1 , V_381 , sizeof( V_381 ) , false ) ;
F_30 ( L_59 , V_381 ) ;
if ( V_77 != V_359 )
return V_77 ;
F_141 ( V_1 ) ;
if ( V_1 -> V_382 != V_383 ) {
V_1 -> V_187 = ( V_1 -> V_382 == V_384 ) ;
} else {
V_375 = F_152 ( V_9 , & V_1 -> V_121 ) ;
if ( V_375 ) {
V_1 -> V_187 = F_161 ( V_375 ) ;
F_162 ( V_375 ) ;
}
}
if ( V_12 -> type != V_5 )
V_12 -> type = V_172 ;
return V_359 ;
}
static int F_163 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
struct V_18 * V_18 = F_20 ( V_9 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
int V_107 ;
V_107 = F_156 ( V_9 , & V_1 -> V_121 ) ;
if ( V_107 )
return V_107 ;
if ( F_1 ( V_1 ) && V_18 -> V_20 . V_21 ) {
struct V_16 * V_17 ;
V_17 = F_164 ( V_7 ,
V_18 -> V_20 . V_21 ) ;
if ( V_17 ) {
F_165 ( V_9 , V_17 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_166 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
struct V_375 * V_375 ;
bool V_187 = false ;
V_375 = F_152 ( V_9 , & V_1 -> V_121 ) ;
if ( V_375 ) {
V_187 = F_161 ( V_375 ) ;
F_162 ( V_375 ) ;
}
return V_187 ;
}
static int
F_167 ( struct V_8 * V_9 ,
struct V_385 * V_386 ,
T_6 V_387 )
{
struct V_51 * V_52 = V_9 -> V_7 -> V_53 ;
struct V_18 * V_18 = F_20 ( V_9 ) ;
struct V_12 * V_12 = F_8 ( V_9 ) ;
struct V_1 * V_1 = F_7 ( & V_12 -> V_4 ) ;
int V_107 ;
V_107 = F_168 ( & V_9 -> V_4 , V_386 , V_387 ) ;
if ( V_107 )
return V_107 ;
if ( V_386 == V_52 -> V_388 ) {
int V_47 = V_387 ;
bool V_187 ;
if ( V_47 == V_1 -> V_382 )
return 0 ;
V_1 -> V_382 = V_47 ;
if ( V_47 == V_383 )
V_187 = F_166 ( V_9 ) ;
else
V_187 = ( V_47 == V_384 ) ;
if ( V_187 == V_1 -> V_187 )
return 0 ;
V_1 -> V_187 = V_187 ;
goto V_389;
}
if ( V_386 == V_52 -> V_390 ) {
if ( V_387 == ! ! V_1 -> V_197 )
return 0 ;
V_1 -> V_197 = V_387 ? V_391 : 0 ;
goto V_389;
}
if ( F_1 ( V_1 ) &&
V_386 == V_9 -> V_7 -> V_218 . V_392 ) {
if ( V_387 == V_393 ) {
F_30 ( L_60 ) ;
return - V_394 ;
}
if ( V_18 -> V_20 . V_153 == V_387 ) {
return 0 ;
}
V_18 -> V_20 . V_153 = V_387 ;
goto V_389;
}
return - V_394 ;
V_389:
if ( V_12 -> V_4 . V_167 ) {
struct V_166 * V_167 = V_12 -> V_4 . V_167 ;
F_169 ( V_167 , & V_167 -> V_17 ,
V_167 -> V_395 , V_167 -> V_396 , V_167 -> V_397 ) ;
}
return 0 ;
}
static void
F_170 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_1 * V_1 = F_6 ( V_9 ) ;
struct V_18 * V_18 = F_20 ( V_9 ) ;
if ( ! F_171 ( V_18 -> V_375 ) )
F_162 ( V_18 -> V_375 ) ;
if ( F_1 ( V_1 ) ) {
F_172 ( V_7 ) ;
F_173 ( & V_18 -> V_20 ) ;
}
F_174 ( V_9 ) ;
F_175 ( V_9 ) ;
F_162 ( V_9 ) ;
}
void F_176 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_177 ( V_11 ) ;
struct V_1 * V_1 = & V_3 -> V_398 ;
F_178 ( & V_1 -> V_121 ) ;
F_179 ( V_11 ) ;
if ( F_1 ( V_1 ) ) {
F_180 ( & V_1 -> V_217 ) ;
F_87 ( V_1 ) ;
}
F_162 ( V_3 ) ;
}
static void
F_181 ( struct V_12 * V_12 )
{
struct V_1 * V_1 = F_7 ( & V_12 -> V_4 ) ;
F_144 ( V_1 ) ;
}
int
F_182 ( struct V_166 * V_167 )
{
struct V_6 * V_7 = V_167 -> V_7 ;
struct V_12 * V_12 ;
struct V_1 * V_1 ;
F_60 (dev, crtc, intel_encoder) {
V_1 = F_7 ( & V_12 -> V_4 ) ;
if ( V_12 -> type == V_172 ||
V_12 -> type == V_5 )
return V_1 -> V_73 ;
}
return - 1 ;
}
bool F_183 ( struct V_6 * V_7 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_399 * V_400 ;
int V_47 ;
if ( ! V_52 -> V_401 )
return false ;
for ( V_47 = 0 ; V_47 < V_52 -> V_401 ; V_47 ++ ) {
V_400 = V_52 -> V_402 + V_47 ;
if ( V_400 -> V_403 == V_404 &&
V_400 -> V_405 == V_406 )
return true ;
}
return false ;
}
static void
F_184 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_18 * V_18 = F_20 ( V_9 ) ;
F_185 ( V_9 ) ;
F_186 ( V_9 ) ;
if ( F_1 ( V_1 ) ) {
F_187 ( V_9 -> V_7 ) ;
F_188 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_218 . V_392 ,
V_407 ) ;
V_18 -> V_20 . V_153 = V_407 ;
}
}
static void
F_189 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_408 * V_409 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_408 V_410 , V_411 , V_412 , V_413 ;
T_4 V_414 , V_415 , V_416 , V_211 ;
V_211 = F_85 ( V_52 ) ;
F_41 ( V_67 , V_211 ) ;
V_414 = F_25 ( V_417 ) ;
V_415 = F_25 ( V_418 ) ;
V_416 = F_25 ( V_419 ) ;
V_410 . V_420 = ( V_414 & V_421 ) >>
V_422 ;
V_410 . V_423 = ( V_414 & V_424 ) >>
V_425 ;
V_410 . V_426 = ( V_415 & V_427 ) >>
V_428 ;
V_410 . V_429 = ( V_415 & V_430 ) >>
V_431 ;
V_410 . V_432 = ( ( V_416 & V_433 ) >>
V_434 ) * 1000 ;
F_30 ( L_61 ,
V_410 . V_420 , V_410 . V_423 , V_410 . V_426 , V_410 . V_429 , V_410 . V_432 ) ;
V_411 = V_52 -> V_435 . V_436 ;
V_412 . V_420 = 210 * 10 ;
V_412 . V_423 = 50 * 10 ;
V_412 . V_426 = 50 * 10 ;
V_412 . V_429 = 500 * 10 ;
V_412 . V_432 = ( 510 + 100 ) * 10 ;
F_30 ( L_62 ,
V_411 . V_420 , V_411 . V_423 , V_411 . V_426 , V_411 . V_429 , V_411 . V_432 ) ;
#define F_190 ( T_7 ) final.field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_190 ( V_420 ) ;
F_190 ( V_423 ) ;
F_190 ( V_426 ) ;
F_190 ( V_429 ) ;
F_190 ( V_432 ) ;
#undef F_190
#define F_191 ( T_7 ) (DIV_ROUND_UP(final.field, 10))
V_1 -> V_213 = F_191 ( V_420 ) ;
V_1 -> V_225 = F_191 ( V_423 ) ;
V_1 -> V_226 = F_191 ( V_426 ) ;
V_1 -> V_214 = F_191 ( V_429 ) ;
V_1 -> V_221 = F_191 ( V_432 ) ;
#undef F_191
F_30 ( L_63 ,
V_1 -> V_213 , V_1 -> V_214 ,
V_1 -> V_221 ) ;
F_30 ( L_64 ,
V_1 -> V_225 , V_1 -> V_226 ) ;
if ( V_409 )
* V_409 = V_413 ;
}
static void
F_192 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_408 * V_437 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_414 , V_415 , V_416 ;
V_414 = ( V_437 -> V_420 << V_422 ) |
( V_437 -> V_423 << V_425 ) ;
V_415 = ( V_437 -> V_426 << V_428 ) |
( V_437 -> V_429 << V_431 ) ;
V_416 = ( ( 100 * F_39 ( V_7 ) ) / 2 - 1 )
<< V_438 ;
V_416 |= ( F_38 ( V_437 -> V_432 , 1000 )
<< V_434 ) ;
if ( F_138 ( V_7 ) || F_79 ( V_7 ) ) {
if ( F_4 ( V_1 ) )
V_414 |= V_439 ;
else
V_414 |= V_440 ;
}
F_41 ( V_417 , V_414 ) ;
F_41 ( V_418 , V_415 ) ;
F_41 ( V_419 , V_416 ) ;
F_30 ( L_65 ,
F_25 ( V_417 ) ,
F_25 ( V_418 ) ,
F_25 ( V_419 ) ) ;
}
void
F_193 ( struct V_2 * V_3 ,
struct V_18 * V_18 )
{
struct V_8 * V_9 = & V_18 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_398 ;
struct V_12 * V_12 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_12 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_16 * V_21 = NULL ;
struct V_408 V_441 = { 0 } ;
enum V_81 V_81 = V_3 -> V_81 ;
const char * V_139 = NULL ;
int type ;
V_1 -> V_180 = F_25 ( V_1 -> V_73 ) ;
V_1 -> V_19 = V_18 ;
if ( F_37 ( V_7 ) && V_81 == V_91 )
if ( F_183 ( V_7 ) )
V_1 -> F_3 = true ;
if ( F_24 ( V_7 ) && V_81 == V_88 ) {
type = V_442 ;
V_12 -> type = V_5 ;
} else if ( V_81 == V_82 || F_3 ( V_1 ) ) {
type = V_442 ;
V_12 -> type = V_5 ;
} else {
type = V_443 ;
}
F_194 ( V_7 , V_9 , & V_444 , type ) ;
F_195 ( V_9 , & V_445 ) ;
V_9 -> V_446 = V_447 ;
V_9 -> V_448 = true ;
V_9 -> V_449 = 0 ;
F_196 ( & V_1 -> V_217 ,
F_88 ) ;
F_197 ( V_18 , V_12 ) ;
F_198 ( V_9 ) ;
if ( F_32 ( V_7 ) )
V_18 -> V_450 = V_451 ;
else
V_18 -> V_450 = V_452 ;
switch ( V_81 ) {
case V_82 :
V_139 = L_66 ;
break;
case V_85 :
V_52 -> V_453 |= V_454 ;
V_139 = L_67 ;
break;
case V_88 :
V_52 -> V_453 |= V_455 ;
V_139 = L_68 ;
break;
case V_91 :
V_52 -> V_453 |= V_456 ;
V_139 = L_69 ;
break;
default:
F_29 ( 1 , L_70 , F_199 ( V_81 ) ) ;
break;
}
if ( F_1 ( V_1 ) )
F_189 ( V_7 , V_1 , & V_441 ) ;
F_49 ( V_1 , V_18 , V_139 ) ;
if ( F_1 ( V_1 ) ) {
bool V_107 ;
struct V_16 * V_457 ;
struct V_375 * V_375 ;
F_50 ( V_1 ) ;
V_107 = F_140 ( V_1 ) ;
F_52 ( V_1 , false ) ;
if ( V_107 ) {
if ( V_1 -> V_23 [ V_176 ] >= 0x11 )
V_52 -> V_458 =
V_1 -> V_23 [ V_459 ] &
V_460 ;
} else {
F_200 ( L_71 ) ;
F_176 ( & V_12 -> V_4 ) ;
F_170 ( V_9 ) ;
return;
}
F_192 ( V_7 , V_1 ,
& V_441 ) ;
F_50 ( V_1 ) ;
V_375 = F_155 ( V_9 , & V_1 -> V_121 ) ;
if ( V_375 ) {
if ( F_201 ( V_9 , V_375 ) ) {
F_202 ( V_9 , V_375 ) ;
F_203 ( V_9 , V_375 ) ;
} else {
F_162 ( V_375 ) ;
V_375 = F_204 ( - V_394 ) ;
}
} else {
V_375 = F_204 ( - V_461 ) ;
}
V_18 -> V_375 = V_375 ;
F_205 (scan, &connector->probed_modes, head) {
if ( ( V_457 -> type & V_462 ) ) {
V_21 = F_164 ( V_7 , V_457 ) ;
break;
}
}
if ( ! V_21 && V_52 -> V_463 ) {
V_21 = F_164 ( V_7 , V_52 -> V_463 ) ;
if ( V_21 )
V_21 -> type |= V_462 ;
}
F_52 ( V_1 , false ) ;
}
if ( F_1 ( V_1 ) ) {
F_206 ( & V_18 -> V_20 , V_21 ) ;
F_207 ( V_9 ) ;
}
F_184 ( V_1 , V_9 ) ;
if ( F_208 ( V_7 ) && ! F_209 ( V_7 ) ) {
T_4 V_300 = F_25 ( V_464 ) ;
F_41 ( V_464 , ( V_300 & ~ 0xf ) | 0xd ) ;
}
}
void
F_210 ( struct V_6 * V_7 , int V_73 , enum V_81 V_81 )
{
struct V_2 * V_3 ;
struct V_12 * V_12 ;
struct V_10 * V_11 ;
struct V_18 * V_18 ;
V_3 = F_211 ( sizeof( struct V_2 ) , V_379 ) ;
if ( ! V_3 )
return;
V_18 = F_211 ( sizeof( struct V_18 ) , V_379 ) ;
if ( ! V_18 ) {
F_162 ( V_3 ) ;
return;
}
V_12 = & V_3 -> V_4 ;
V_11 = & V_12 -> V_4 ;
F_212 ( V_7 , & V_12 -> V_4 , & V_465 ,
V_466 ) ;
F_213 ( & V_12 -> V_4 , & V_467 ) ;
V_12 -> V_468 = F_113 ;
V_12 -> V_469 = F_117 ;
V_12 -> V_470 = F_110 ;
V_12 -> V_471 = F_112 ;
V_12 -> V_450 = F_105 ;
V_3 -> V_81 = V_81 ;
V_3 -> V_398 . V_73 = V_73 ;
V_12 -> type = V_172 ;
V_12 -> V_472 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_12 -> V_473 = false ;
V_12 -> V_474 = F_181 ;
F_193 ( V_3 , V_18 ) ;
}

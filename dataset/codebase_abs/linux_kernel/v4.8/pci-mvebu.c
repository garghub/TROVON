static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static inline bool F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_6 != - 1 && V_2 -> V_7 != - 1 ;
}
static bool F_6 ( struct V_1 * V_2 )
{
return ! ( F_3 ( V_2 , V_8 ) & V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_10 )
{
T_1 V_11 ;
V_11 = F_3 ( V_2 , V_8 ) ;
V_11 &= ~ V_12 ;
V_11 |= V_10 << 8 ;
F_1 ( V_2 , V_11 , V_8 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_10 )
{
T_1 V_11 ;
V_11 = F_3 ( V_2 , V_8 ) ;
V_11 &= ~ V_13 ;
V_11 |= V_10 << 16 ;
F_1 ( V_2 , V_11 , V_8 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
const struct V_14 * V_15 ;
T_1 V_16 ;
int V_17 ;
V_15 = F_10 () ;
for ( V_17 = 1 ; V_17 < 3 ; V_17 ++ ) {
F_1 ( V_2 , 0 , F_11 ( V_17 ) ) ;
F_1 ( V_2 , 0 , F_12 ( V_17 ) ) ;
F_1 ( V_2 , 0 , F_13 ( V_17 ) ) ;
}
for ( V_17 = 0 ; V_17 < 5 ; V_17 ++ ) {
F_1 ( V_2 , 0 , F_14 ( V_17 ) ) ;
F_1 ( V_2 , 0 , F_15 ( V_17 ) ) ;
F_1 ( V_2 , 0 , F_16 ( V_17 ) ) ;
}
F_1 ( V_2 , 0 , V_18 ) ;
F_1 ( V_2 , 0 , V_19 ) ;
F_1 ( V_2 , 0 , V_20 ) ;
V_16 = 0 ;
for ( V_17 = 0 ; V_17 < V_15 -> V_21 ; V_17 ++ ) {
const struct V_22 * V_23 = V_15 -> V_23 + V_17 ;
F_1 ( V_2 , V_23 -> V_5 & 0xffff0000 ,
F_15 ( V_17 ) ) ;
F_1 ( V_2 , 0 , F_16 ( V_17 ) ) ;
F_1 ( V_2 ,
( ( V_23 -> V_16 - 1 ) & 0xffff0000 ) |
( V_23 -> V_24 << 8 ) |
( V_15 -> V_25 << 4 ) | 1 ,
F_14 ( V_17 ) ) ;
V_16 += V_23 -> V_16 ;
}
if ( ( V_16 & ( V_16 - 1 ) ) != 0 )
V_16 = 1 << F_17 ( V_16 ) ;
F_1 ( V_2 , V_15 -> V_23 [ 0 ] . V_5 , F_12 ( 1 ) ) ;
F_1 ( V_2 , 0 , F_13 ( 1 ) ) ;
F_1 ( V_2 , ( ( V_16 - 1 ) & 0xffff0000 ) | 1 ,
F_11 ( 1 ) ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_26 , V_27 ;
F_9 ( V_2 ) ;
V_26 = F_3 ( V_2 , V_28 ) ;
V_26 |= V_29 ;
V_26 |= V_30 ;
V_26 |= V_31 ;
F_1 ( V_2 , V_26 , V_28 ) ;
V_27 = F_3 ( V_2 , V_32 ) ;
V_27 |= V_33 ;
F_1 ( V_2 , V_27 , V_32 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
T_1 V_36 , int V_37 , int V_16 , T_1 * V_3 )
{
void T_2 * V_38 = V_2 -> V_5 + V_39 ;
F_1 ( V_2 , F_20 ( V_35 -> V_40 , V_36 , V_37 ) ,
V_41 ) ;
switch ( V_16 ) {
case 1 :
* V_3 = F_21 ( V_38 + ( V_37 & 3 ) ) ;
break;
case 2 :
* V_3 = F_22 ( V_38 + ( V_37 & 2 ) ) ;
break;
case 4 :
* V_3 = F_23 ( V_38 ) ;
break;
}
return V_42 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
T_1 V_36 , int V_37 , int V_16 , T_1 V_3 )
{
void T_2 * V_38 = V_2 -> V_5 + V_39 ;
F_1 ( V_2 , F_20 ( V_35 -> V_40 , V_36 , V_37 ) ,
V_41 ) ;
switch ( V_16 ) {
case 1 :
F_25 ( V_3 , V_38 + ( V_37 & 3 ) ) ;
break;
case 2 :
F_26 ( V_3 , V_38 + ( V_37 & 2 ) ) ;
break;
case 4 :
F_2 ( V_3 , V_38 ) ;
break;
default:
return V_43 ;
}
return V_42 ;
}
static void F_27 ( struct V_1 * V_2 ,
T_3 V_5 , T_4 V_16 )
{
while ( V_16 ) {
T_4 V_44 = 1 << ( F_17 ( V_16 ) - 1 ) ;
F_28 ( V_5 , V_44 ) ;
V_5 += V_44 ;
V_16 -= V_44 ;
}
}
static void F_29 ( struct V_1 * V_2 ,
unsigned int V_45 , unsigned int V_46 ,
T_3 V_5 , T_4 V_16 ,
T_3 V_47 )
{
T_4 V_48 = 0 ;
while ( V_16 ) {
T_4 V_44 = 1 << ( F_17 ( V_16 ) - 1 ) ;
int V_49 ;
V_49 = F_30 ( V_45 , V_46 , V_5 ,
V_44 , V_47 ) ;
if ( V_49 ) {
T_3 V_50 = V_5 + V_44 - 1 ;
F_31 ( & V_2 -> V_51 -> V_52 -> V_53 ,
L_1 ,
& V_5 , & V_50 , V_49 ) ;
F_27 ( V_2 , V_5 - V_48 ,
V_48 ) ;
return;
}
V_16 -= V_44 ;
V_48 += V_44 ;
V_5 += V_44 ;
if ( V_47 != V_54 )
V_47 += V_44 ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
T_3 V_55 ;
if ( V_2 -> V_56 . V_57 < V_2 -> V_56 . V_55 ||
V_2 -> V_56 . V_58 < V_2 -> V_56 . V_59 ||
! ( V_2 -> V_56 . V_60 & V_29 ) ) {
if ( V_2 -> V_61 ) {
F_27 ( V_2 , V_2 -> V_61 ,
V_2 -> V_62 ) ;
V_2 -> V_61 = 0 ;
V_2 -> V_62 = 0 ;
}
return;
}
if ( ! F_5 ( V_2 ) ) {
F_33 ( & V_2 -> V_51 -> V_52 -> V_53 ,
L_2 ) ;
return;
}
V_55 = ( ( V_2 -> V_56 . V_55 & 0xF0 ) << 8 ) |
( V_2 -> V_56 . V_59 << 16 ) ;
V_2 -> V_61 = V_2 -> V_51 -> V_63 . V_64 + V_55 ;
V_2 -> V_62 = ( ( 0xFFF | ( ( V_2 -> V_56 . V_57 & 0xF0 ) << 8 ) |
( V_2 -> V_56 . V_58 << 16 ) ) -
V_55 ) + 1 ;
F_29 ( V_2 , V_2 -> V_6 , V_2 -> V_7 ,
V_2 -> V_61 , V_2 -> V_62 ,
V_55 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_56 . V_65 < V_2 -> V_56 . V_66 ||
! ( V_2 -> V_56 . V_60 & V_30 ) ) {
if ( V_2 -> V_67 ) {
F_27 ( V_2 , V_2 -> V_67 ,
V_2 -> V_68 ) ;
V_2 -> V_67 = 0 ;
V_2 -> V_68 = 0 ;
}
return;
}
V_2 -> V_67 = ( ( V_2 -> V_56 . V_66 & 0xFFF0 ) << 16 ) ;
V_2 -> V_68 =
( ( ( V_2 -> V_56 . V_65 & 0xFFF0 ) << 16 ) | 0xFFFFF ) -
V_2 -> V_67 + 1 ;
F_29 ( V_2 , V_2 -> V_69 , V_2 -> V_70 ,
V_2 -> V_67 , V_2 -> V_68 ,
V_54 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_71 * V_56 = & V_2 -> V_56 ;
memset ( V_56 , 0 , sizeof( struct V_71 ) ) ;
V_56 -> V_72 = V_73 ;
V_56 -> V_74 = V_75 ;
V_56 -> V_76 = F_3 ( V_2 , V_77 ) >> 16 ;
V_56 -> V_78 = F_3 ( V_2 , V_79 ) & 0xff ;
V_56 -> V_80 = V_81 ;
V_56 -> V_82 = 0x10 ;
V_56 -> V_55 = V_83 ;
V_56 -> V_57 = V_83 ;
V_56 -> V_84 = V_85 ;
}
static int F_36 ( struct V_1 * V_2 ,
unsigned int V_37 , int V_16 , T_1 * V_86 )
{
struct V_71 * V_56 = & V_2 -> V_56 ;
switch ( V_37 & ~ 3 ) {
case V_87 :
* V_86 = V_56 -> V_76 << 16 | V_56 -> V_74 ;
break;
case V_88 :
* V_86 = V_56 -> V_60 | V_56 -> V_84 << 16 ;
break;
case V_89 :
* V_86 = V_56 -> V_72 << 16 | V_56 -> V_90 << 8 |
V_56 -> V_78 ;
break;
case V_91 :
* V_86 = V_56 -> V_92 << 24 | V_56 -> V_80 << 16 |
V_56 -> V_93 << 8 | V_56 -> V_82 ;
break;
case V_94 ... V_95 :
* V_86 = V_56 -> V_96 [ ( ( V_37 & ~ 3 ) - V_94 ) / 4 ] ;
break;
case V_97 :
* V_86 = ( V_56 -> V_98 << 24 |
V_56 -> V_99 << 16 |
V_56 -> V_100 << 8 |
V_56 -> V_101 ) ;
break;
case V_102 :
if ( ! F_5 ( V_2 ) )
* V_86 = V_56 -> V_103 << 16 ;
else
* V_86 = ( V_56 -> V_103 << 16 |
V_56 -> V_57 << 8 |
V_56 -> V_55 ) ;
break;
case V_104 :
* V_86 = ( V_56 -> V_65 << 16 | V_56 -> V_66 ) ;
break;
case V_105 :
* V_86 = 0 ;
break;
case V_106 :
* V_86 = ( V_56 -> V_58 << 16 | V_56 -> V_59 ) ;
break;
case V_107 :
* V_86 = V_108 ;
break;
case V_109 :
* V_86 = 0 ;
break;
case V_110 :
* V_86 = 0 ;
break;
case V_111 :
* V_86 = ( V_112 << 4 | 2 |
V_113 ) << 16 | V_114 ;
break;
case V_115 :
* V_86 = F_3 ( V_2 , V_116 + V_117 ) ;
break;
case V_118 :
* V_86 = F_3 ( V_2 , V_116 + V_119 ) &
~ ( V_120 | V_121 |
V_122 | V_123 ) ;
* V_86 |= V_56 -> V_124 ;
break;
case V_125 :
* V_86 = F_3 ( V_2 , V_116 + V_126 ) &
~ V_127 ;
break;
case V_128 :
* V_86 = F_3 ( V_2 , V_116 + V_129 ) ;
break;
case V_130 :
* V_86 = V_56 -> V_131 ;
break;
case V_132 :
* V_86 = V_133 << 16 ;
break;
case V_134 :
* V_86 = V_56 -> V_135 ;
break;
case V_136 :
* V_86 = F_3 ( V_2 , V_137 ) ;
break;
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
default:
* V_86 = 0 ;
return V_42 ;
}
if ( V_16 == 2 )
* V_86 = ( * V_86 >> ( 8 * ( V_37 & 3 ) ) ) & 0xffff ;
else if ( V_16 == 1 )
* V_86 = ( * V_86 >> ( 8 * ( V_37 & 3 ) ) ) & 0xff ;
return V_42 ;
}
static int F_37 ( struct V_1 * V_2 ,
unsigned int V_37 , int V_16 , T_1 V_86 )
{
struct V_71 * V_56 = & V_2 -> V_56 ;
T_1 V_27 , V_4 ;
int V_144 ;
if ( V_16 == 4 )
V_27 = 0x0 ;
else if ( V_16 == 2 )
V_27 = ~ ( 0xffff << ( ( V_37 & 3 ) * 8 ) ) ;
else if ( V_16 == 1 )
V_27 = ~ ( 0xff << ( ( V_37 & 3 ) * 8 ) ) ;
else
return V_43 ;
V_144 = F_36 ( V_2 , V_37 & ~ 3 , 4 , & V_4 ) ;
if ( V_144 )
return V_144 ;
V_86 = ( V_4 & V_27 ) | V_86 << ( ( V_37 & 3 ) * 8 ) ;
switch ( V_37 & ~ 3 ) {
case V_88 :
{
T_1 V_145 = V_56 -> V_60 ;
if ( ! F_5 ( V_2 ) )
V_86 &= ~ V_29 ;
V_56 -> V_60 = V_86 & 0xffff ;
if ( ( V_145 ^ V_56 -> V_60 ) & V_29 )
F_32 ( V_2 ) ;
if ( ( V_145 ^ V_56 -> V_60 ) & V_30 )
F_34 ( V_2 ) ;
break;
}
case V_94 ... V_95 :
V_56 -> V_96 [ ( ( V_37 & ~ 3 ) - V_94 ) / 4 ] = V_86 ;
break;
case V_102 :
V_56 -> V_55 = ( V_86 & 0xff ) | V_83 ;
V_56 -> V_57 = ( ( V_86 >> 8 ) & 0xff ) | V_83 ;
F_32 ( V_2 ) ;
break;
case V_104 :
V_56 -> V_66 = V_86 & 0xffff ;
V_56 -> V_65 = V_86 >> 16 ;
F_34 ( V_2 ) ;
break;
case V_106 :
V_56 -> V_59 = V_86 & 0xffff ;
V_56 -> V_58 = V_86 >> 16 ;
F_32 ( V_2 ) ;
break;
case V_97 :
V_56 -> V_101 = V_86 & 0xff ;
V_56 -> V_100 = ( V_86 >> 8 ) & 0xff ;
V_56 -> V_99 = ( V_86 >> 16 ) & 0xff ;
V_56 -> V_98 = ( V_86 >> 24 ) & 0xff ;
F_7 ( V_2 , V_56 -> V_100 ) ;
break;
case V_118 :
V_86 &= ~ ( V_120 | V_121 |
V_122 | V_123 ) ;
if ( V_27 == 0xffff0000 )
V_86 &= 0xffff ;
F_1 ( V_2 , V_86 , V_116 + V_119 ) ;
break;
case V_128 :
V_86 &= ~ V_146 ;
if ( V_27 == 0xffff0000 )
V_86 &= 0xffff ;
F_1 ( V_2 , V_86 , V_116 + V_129 ) ;
break;
case V_136 :
F_1 ( V_2 , V_86 , V_137 ) ;
break;
default:
break;
}
return V_42 ;
}
static inline struct V_147 * F_38 ( struct V_148 * V_149 )
{
return V_149 -> V_150 ;
}
static struct V_1 * F_39 ( struct V_147 * V_51 ,
struct V_34 * V_35 ,
int V_36 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_51 -> V_151 ; V_17 ++ ) {
struct V_1 * V_2 = & V_51 -> V_152 [ V_17 ] ;
if ( V_35 -> V_40 == 0 && V_2 -> V_36 == V_36 )
return V_2 ;
if ( V_35 -> V_40 != 0 &&
V_35 -> V_40 >= V_2 -> V_56 . V_100 &&
V_35 -> V_40 <= V_2 -> V_56 . V_99 )
return V_2 ;
}
return NULL ;
}
static int F_40 ( struct V_34 * V_35 , T_1 V_36 ,
int V_37 , int V_16 , T_1 V_3 )
{
struct V_147 * V_51 = F_38 ( V_35 -> V_153 ) ;
struct V_1 * V_2 ;
int V_49 ;
V_2 = F_39 ( V_51 , V_35 , V_36 ) ;
if ( ! V_2 )
return V_154 ;
if ( V_35 -> V_40 == 0 )
return F_37 ( V_2 , V_37 , V_16 , V_3 ) ;
if ( ! F_6 ( V_2 ) )
return V_154 ;
V_49 = F_24 ( V_2 , V_35 , V_36 ,
V_37 , V_16 , V_3 ) ;
return V_49 ;
}
static int F_41 ( struct V_34 * V_35 , T_1 V_36 , int V_37 ,
int V_16 , T_1 * V_3 )
{
struct V_147 * V_51 = F_38 ( V_35 -> V_153 ) ;
struct V_1 * V_2 ;
int V_49 ;
V_2 = F_39 ( V_51 , V_35 , V_36 ) ;
if ( ! V_2 ) {
* V_3 = 0xffffffff ;
return V_154 ;
}
if ( V_35 -> V_40 == 0 )
return F_36 ( V_2 , V_37 , V_16 , V_3 ) ;
if ( ! F_6 ( V_2 ) ) {
* V_3 = 0xffffffff ;
return V_154 ;
}
V_49 = F_19 ( V_2 , V_35 , V_36 ,
V_37 , V_16 , V_3 ) ;
return V_49 ;
}
static int F_42 ( int V_10 , struct V_148 * V_149 )
{
struct V_147 * V_51 = F_38 ( V_149 ) ;
int V_144 , V_17 ;
V_51 -> V_155 . V_156 = L_3 ;
V_51 -> V_157 . V_156 = L_4 ;
if ( F_43 ( & V_51 -> V_157 ) != 0 )
F_44 ( & V_149 -> V_158 , & V_51 -> V_157 ,
V_149 -> V_159 ) ;
F_44 ( & V_149 -> V_158 , & V_51 -> V_155 , V_149 -> V_160 ) ;
F_45 ( & V_149 -> V_158 , & V_51 -> V_161 ) ;
V_144 = F_46 ( & V_51 -> V_52 -> V_53 , & V_149 -> V_158 ) ;
if ( V_144 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_51 -> V_151 ; V_17 ++ ) {
struct V_1 * V_2 = & V_51 -> V_152 [ V_17 ] ;
if ( ! V_2 -> V_5 )
continue;
F_18 ( V_2 ) ;
}
return 1 ;
}
static T_5 F_47 ( struct V_162 * V_53 ,
const struct V_163 * V_164 ,
T_5 V_64 ,
T_5 V_16 ,
T_5 V_165 )
{
if ( V_53 -> V_35 -> V_40 != 0 )
return V_64 ;
if ( V_164 -> V_166 & V_167 )
return F_48 ( V_64 , F_49 ( T_5 , V_168 ,
F_50 ( V_16 ) ) ) ;
else if ( V_164 -> V_166 & V_169 )
return F_48 ( V_64 , F_49 ( T_5 , V_170 ,
F_50 ( V_16 ) ) ) ;
else
return V_64 ;
}
static void F_51 ( struct V_147 * V_51 )
{
struct V_171 V_172 ;
memset ( & V_172 , 0 , sizeof( V_172 ) ) ;
#ifdef F_52
V_172 . V_173 = V_51 -> V_174 ;
#endif
V_172 . V_175 = 1 ;
V_172 . V_150 = ( void * * ) & V_51 ;
V_172 . V_176 = F_42 ;
V_172 . V_177 = V_178 ;
V_172 . V_179 = & V_180 ;
V_172 . V_181 = F_47 ;
F_53 ( & V_51 -> V_52 -> V_53 , & V_172 ) ;
}
static void T_2 * F_54 ( struct V_182 * V_52 ,
struct V_183 * V_184 ,
struct V_1 * V_2 )
{
struct V_163 V_185 ;
int V_49 = 0 ;
V_49 = F_55 ( V_184 , 0 , & V_185 ) ;
if ( V_49 )
return F_56 ( V_49 ) ;
return F_57 ( & V_52 -> V_53 , & V_185 ) ;
}
static int F_58 ( struct V_183 * V_184 , int V_36 ,
unsigned long type ,
unsigned int * V_186 ,
unsigned int * V_187 )
{
const int V_188 = 3 , V_189 = 2 ;
const T_6 * V_190 ;
int V_191 , V_192 , V_193 , V_194 , V_17 ;
* V_186 = - 1 ;
* V_187 = - 1 ;
V_190 = F_59 ( V_184 , L_5 , & V_191 ) ;
if ( ! V_190 )
return - V_195 ;
V_194 = F_60 ( V_184 ) ;
V_193 = V_194 + V_188 + V_189 ;
V_192 = V_191 / sizeof( T_6 ) / V_193 ;
for ( V_17 = 0 ; V_17 < V_192 ; V_17 ++ , V_190 += V_193 ) {
T_1 V_166 = F_61 ( V_190 , 1 ) ;
T_1 V_196 = F_61 ( V_190 + 1 , 1 ) ;
T_7 V_197 = F_61 ( V_190 + V_188 , V_194 ) ;
unsigned long V_198 ;
if ( F_62 ( V_166 ) == V_199 )
V_198 = V_167 ;
else if ( F_62 ( V_166 ) == V_200 )
V_198 = V_169 ;
else
continue;
if ( V_196 == F_63 ( V_36 ) && type == V_198 ) {
* V_186 = F_64 ( V_197 ) ;
* V_187 = F_65 ( V_197 ) ;
return 0 ;
}
}
return - V_201 ;
}
static void F_66 ( struct V_147 * V_51 )
{
struct V_183 * V_202 ;
V_202 = F_67 ( V_51 -> V_52 -> V_53 . V_203 ,
L_6 , 0 ) ;
if ( ! V_202 )
return;
V_51 -> V_174 = F_68 ( V_202 ) ;
F_69 ( V_202 ) ;
if ( V_51 -> V_174 )
V_51 -> V_174 -> V_53 = & V_51 -> V_52 -> V_53 ;
}
static int F_70 ( struct V_76 * V_53 )
{
struct V_147 * V_51 ;
int V_17 ;
V_51 = F_71 ( V_53 ) ;
for ( V_17 = 0 ; V_17 < V_51 -> V_151 ; V_17 ++ ) {
struct V_1 * V_2 = V_51 -> V_152 + V_17 ;
V_2 -> V_204 = F_3 ( V_2 , V_8 ) ;
}
return 0 ;
}
static int F_72 ( struct V_76 * V_53 )
{
struct V_147 * V_51 ;
int V_17 ;
V_51 = F_71 ( V_53 ) ;
for ( V_17 = 0 ; V_17 < V_51 -> V_151 ; V_17 ++ ) {
struct V_1 * V_2 = V_51 -> V_152 + V_17 ;
F_1 ( V_2 , V_2 -> V_204 , V_8 ) ;
F_18 ( V_2 ) ;
}
return 0 ;
}
static void F_73 ( void * V_205 )
{
struct V_1 * V_2 = V_205 ;
F_74 ( V_2 -> V_206 ) ;
}
static int F_75 ( struct V_147 * V_51 ,
struct V_1 * V_2 , struct V_183 * V_207 )
{
struct V_76 * V_53 = & V_51 -> V_52 -> V_53 ;
enum V_208 V_166 ;
int V_209 , V_49 ;
V_2 -> V_51 = V_51 ;
if ( F_76 ( V_207 , L_7 , & V_2 -> V_2 ) ) {
F_77 ( V_53 , L_8 ,
F_78 ( V_207 ) ) ;
goto V_210;
}
if ( F_76 ( V_207 , L_9 , & V_2 -> V_211 ) )
V_2 -> V_211 = 0 ;
V_2 -> V_156 = F_79 ( V_53 , V_212 , L_10 , V_2 -> V_2 ,
V_2 -> V_211 ) ;
if ( ! V_2 -> V_156 ) {
V_49 = - V_213 ;
goto V_144;
}
V_2 -> V_36 = F_80 ( V_207 ) ;
if ( V_2 -> V_36 < 0 )
goto V_210;
V_49 = F_58 ( V_53 -> V_203 , V_2 -> V_36 , V_169 ,
& V_2 -> V_69 , & V_2 -> V_70 ) ;
if ( V_49 < 0 ) {
F_31 ( V_53 , L_11 ,
V_2 -> V_156 ) ;
goto V_210;
}
if ( F_43 ( & V_51 -> V_63 ) != 0 ) {
F_58 ( V_53 -> V_203 , V_2 -> V_36 , V_167 ,
& V_2 -> V_6 , & V_2 -> V_7 ) ;
} else {
V_2 -> V_6 = - 1 ;
V_2 -> V_7 = - 1 ;
}
V_209 = F_81 ( V_207 , L_12 , 0 , & V_166 ) ;
if ( V_209 == - V_214 ) {
V_49 = V_209 ;
goto V_144;
}
if ( F_82 ( V_209 ) ) {
unsigned long V_215 ;
V_2 -> V_216 = F_79 ( V_53 , V_212 , L_13 ,
V_2 -> V_156 ) ;
if ( ! V_2 -> V_216 ) {
V_49 = - V_213 ;
goto V_144;
}
if ( V_166 & V_217 ) {
F_83 ( V_53 , L_14 ,
F_78 ( V_207 ) ) ;
V_215 = V_218 |
V_219 ;
} else {
V_215 = V_220 ;
}
V_49 = F_84 ( V_53 , V_209 , V_215 ,
V_2 -> V_216 ) ;
if ( V_49 ) {
if ( V_49 == - V_214 )
goto V_144;
goto V_210;
}
V_2 -> V_209 = F_85 ( V_209 ) ;
}
V_2 -> V_206 = F_86 ( V_207 , NULL ) ;
if ( F_87 ( V_2 -> V_206 ) ) {
F_31 ( V_53 , L_15 , V_2 -> V_156 ) ;
goto V_210;
}
V_49 = F_88 ( V_53 , F_73 , V_2 ) ;
if ( V_49 < 0 ) {
F_74 ( V_2 -> V_206 ) ;
goto V_144;
}
return 1 ;
V_210:
V_49 = 0 ;
F_89 ( V_53 , V_2 -> V_216 ) ;
V_2 -> V_216 = NULL ;
F_89 ( V_53 , V_2 -> V_156 ) ;
V_2 -> V_156 = NULL ;
V_144:
return V_49 ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_49 ;
V_49 = F_91 ( V_2 -> V_206 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_2 -> V_209 ) {
T_1 V_221 = 20000 ;
F_76 ( V_2 -> V_222 , L_16 ,
& V_221 ) ;
F_92 ( 100 ) ;
F_93 ( V_2 -> V_209 , 0 ) ;
F_94 ( V_221 / 1000 ) ;
}
return 0 ;
}
static void F_95 ( struct V_1 * V_2 )
{
if ( V_2 -> V_209 )
F_93 ( V_2 -> V_209 , 1 ) ;
F_96 ( V_2 -> V_206 ) ;
}
static int F_97 ( struct V_182 * V_52 )
{
struct V_147 * V_51 ;
struct V_183 * V_184 = V_52 -> V_53 . V_203 ;
struct V_183 * V_207 ;
int V_223 , V_17 , V_49 ;
V_51 = F_98 ( & V_52 -> V_53 , sizeof( struct V_147 ) ,
V_212 ) ;
if ( ! V_51 )
return - V_213 ;
V_51 -> V_52 = V_52 ;
F_99 ( V_52 , V_51 ) ;
F_100 ( & V_51 -> V_155 ) ;
if ( F_43 ( & V_51 -> V_155 ) == 0 ) {
F_31 ( & V_52 -> V_53 , L_17 ) ;
return - V_195 ;
}
F_101 ( & V_51 -> V_63 ) ;
if ( F_43 ( & V_51 -> V_63 ) != 0 ) {
V_51 -> V_157 . V_166 = V_51 -> V_63 . V_166 ;
V_51 -> V_157 . V_64 = V_224 ;
V_51 -> V_157 . V_50 = F_102 ( T_5 ,
V_225 ,
F_43 ( & V_51 -> V_63 ) ) ;
} else
V_51 -> V_157 = V_51 -> V_63 ;
V_49 = F_103 ( V_184 , & V_51 -> V_161 ) ;
if ( V_49 ) {
F_31 ( & V_52 -> V_53 , L_18 ,
V_49 ) ;
return V_49 ;
}
V_223 = F_104 ( V_52 -> V_53 . V_203 ) ;
V_51 -> V_152 = F_105 ( & V_52 -> V_53 , V_223 , sizeof( * V_51 -> V_152 ) ,
V_212 ) ;
if ( ! V_51 -> V_152 )
return - V_213 ;
V_17 = 0 ;
F_106 (pdev->dev.of_node, child) {
struct V_1 * V_2 = & V_51 -> V_152 [ V_17 ] ;
V_49 = F_75 ( V_51 , V_2 , V_207 ) ;
if ( V_49 < 0 ) {
F_69 ( V_207 ) ;
return V_49 ;
} else if ( V_49 == 0 ) {
continue;
}
V_2 -> V_222 = V_207 ;
V_17 ++ ;
}
V_51 -> V_151 = V_17 ;
for ( V_17 = 0 ; V_17 < V_51 -> V_151 ; V_17 ++ ) {
struct V_1 * V_2 = & V_51 -> V_152 [ V_17 ] ;
V_207 = V_2 -> V_222 ;
if ( ! V_207 )
continue;
V_49 = F_90 ( V_2 ) ;
if ( V_49 < 0 )
continue;
V_2 -> V_5 = F_54 ( V_52 , V_207 , V_2 ) ;
if ( F_87 ( V_2 -> V_5 ) ) {
F_31 ( & V_52 -> V_53 , L_19 ,
V_2 -> V_156 ) ;
V_2 -> V_5 = NULL ;
F_95 ( V_2 ) ;
continue;
}
F_8 ( V_2 , 1 ) ;
F_35 ( V_2 ) ;
}
V_51 -> V_151 = V_17 ;
for ( V_17 = 0 ; V_17 < ( V_225 - V_168 ) ; V_17 += V_168 )
F_107 ( V_17 , V_51 -> V_63 . V_64 + V_17 ) ;
F_66 ( V_51 ) ;
F_51 ( V_51 ) ;
F_99 ( V_52 , V_51 ) ;
return 0 ;
}

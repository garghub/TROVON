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
int V_17 ;
V_51 -> V_155 . V_156 = L_3 ;
V_51 -> V_157 . V_156 = L_4 ;
if ( F_43 ( & V_158 , & V_51 -> V_155 ) )
return 0 ;
if ( F_44 ( & V_51 -> V_157 ) != 0 ) {
if ( F_43 ( & V_159 , & V_51 -> V_157 ) ) {
F_45 ( & V_51 -> V_155 ) ;
return 0 ;
}
F_46 ( & V_149 -> V_160 , & V_51 -> V_157 ,
V_149 -> V_161 ) ;
}
F_46 ( & V_149 -> V_160 , & V_51 -> V_155 , V_149 -> V_162 ) ;
F_47 ( & V_149 -> V_160 , & V_51 -> V_163 ) ;
for ( V_17 = 0 ; V_17 < V_51 -> V_151 ; V_17 ++ ) {
struct V_1 * V_2 = & V_51 -> V_152 [ V_17 ] ;
if ( ! V_2 -> V_5 )
continue;
F_18 ( V_2 ) ;
}
return 1 ;
}
static T_5 F_48 ( struct V_164 * V_53 ,
const struct V_165 * V_166 ,
T_5 V_64 ,
T_5 V_16 ,
T_5 V_167 )
{
if ( V_53 -> V_35 -> V_40 != 0 )
return V_64 ;
if ( V_166 -> V_168 & V_169 )
return F_49 ( V_64 , F_50 ( T_5 , V_170 ,
F_51 ( V_16 ) ) ) ;
else if ( V_166 -> V_168 & V_171 )
return F_49 ( V_64 , F_50 ( T_5 , V_172 ,
F_51 ( V_16 ) ) ) ;
else
return V_64 ;
}
static void F_52 ( struct V_147 * V_51 )
{
struct V_173 V_174 ;
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
#ifdef F_53
V_174 . V_175 = V_51 -> V_176 ;
#endif
V_174 . V_177 = 1 ;
V_174 . V_150 = ( void * * ) & V_51 ;
V_174 . V_178 = F_42 ;
V_174 . V_179 = V_180 ;
V_174 . V_181 = & V_182 ;
V_174 . V_183 = F_48 ;
F_54 ( & V_51 -> V_52 -> V_53 , & V_174 ) ;
}
static void T_2 * F_55 ( struct V_184 * V_52 ,
struct V_185 * V_186 ,
struct V_1 * V_2 )
{
struct V_165 V_187 ;
int V_49 = 0 ;
V_49 = F_56 ( V_186 , 0 , & V_187 ) ;
if ( V_49 )
return F_57 ( V_49 ) ;
return F_58 ( & V_52 -> V_53 , & V_187 ) ;
}
static int F_59 ( struct V_185 * V_186 , int V_36 ,
unsigned long type ,
unsigned int * V_188 ,
unsigned int * V_189 )
{
const int V_190 = 3 , V_191 = 2 ;
const T_6 * V_192 ;
int V_193 , V_194 , V_195 , V_196 , V_17 ;
* V_188 = - 1 ;
* V_189 = - 1 ;
V_192 = F_60 ( V_186 , L_5 , & V_193 ) ;
if ( ! V_192 )
return - V_197 ;
V_196 = F_61 ( V_186 ) ;
V_195 = V_196 + V_190 + V_191 ;
V_194 = V_193 / sizeof( T_6 ) / V_195 ;
for ( V_17 = 0 ; V_17 < V_194 ; V_17 ++ , V_192 += V_195 ) {
T_1 V_168 = F_62 ( V_192 , 1 ) ;
T_1 V_198 = F_62 ( V_192 + 1 , 1 ) ;
T_7 V_199 = F_62 ( V_192 + V_190 , V_196 ) ;
unsigned long V_200 ;
if ( F_63 ( V_168 ) == V_201 )
V_200 = V_169 ;
else if ( F_63 ( V_168 ) == V_202 )
V_200 = V_171 ;
else
continue;
if ( V_198 == F_64 ( V_36 ) && type == V_200 ) {
* V_188 = F_65 ( V_199 ) ;
* V_189 = F_66 ( V_199 ) ;
return 0 ;
}
}
return - V_203 ;
}
static void F_67 ( struct V_147 * V_51 )
{
struct V_185 * V_204 ;
V_204 = F_68 ( V_51 -> V_52 -> V_53 . V_205 ,
L_6 , 0 ) ;
if ( ! V_204 )
return;
V_51 -> V_176 = F_69 ( V_204 ) ;
F_70 ( V_204 ) ;
if ( V_51 -> V_176 )
V_51 -> V_176 -> V_53 = & V_51 -> V_52 -> V_53 ;
}
static int F_71 ( struct V_76 * V_53 )
{
struct V_147 * V_51 ;
int V_17 ;
V_51 = F_72 ( V_53 ) ;
for ( V_17 = 0 ; V_17 < V_51 -> V_151 ; V_17 ++ ) {
struct V_1 * V_2 = V_51 -> V_152 + V_17 ;
V_2 -> V_206 = F_3 ( V_2 , V_8 ) ;
}
return 0 ;
}
static int F_73 ( struct V_76 * V_53 )
{
struct V_147 * V_51 ;
int V_17 ;
V_51 = F_72 ( V_53 ) ;
for ( V_17 = 0 ; V_17 < V_51 -> V_151 ; V_17 ++ ) {
struct V_1 * V_2 = V_51 -> V_152 + V_17 ;
F_1 ( V_2 , V_2 -> V_206 , V_8 ) ;
F_18 ( V_2 ) ;
}
return 0 ;
}
static void F_74 ( void * V_207 )
{
struct V_1 * V_2 = V_207 ;
F_75 ( V_2 -> V_208 ) ;
}
static int F_76 ( struct V_147 * V_51 ,
struct V_1 * V_2 , struct V_185 * V_209 )
{
struct V_76 * V_53 = & V_51 -> V_52 -> V_53 ;
enum V_210 V_168 ;
int V_211 , V_49 ;
V_2 -> V_51 = V_51 ;
if ( F_77 ( V_209 , L_7 , & V_2 -> V_2 ) ) {
F_78 ( V_53 , L_8 ,
F_79 ( V_209 ) ) ;
goto V_212;
}
if ( F_77 ( V_209 , L_9 , & V_2 -> V_213 ) )
V_2 -> V_213 = 0 ;
V_2 -> V_156 = F_80 ( V_53 , V_214 , L_10 , V_2 -> V_2 ,
V_2 -> V_213 ) ;
if ( ! V_2 -> V_156 ) {
V_49 = - V_215 ;
goto V_144;
}
V_2 -> V_36 = F_81 ( V_209 ) ;
if ( V_2 -> V_36 < 0 )
goto V_212;
V_49 = F_59 ( V_53 -> V_205 , V_2 -> V_36 , V_171 ,
& V_2 -> V_69 , & V_2 -> V_70 ) ;
if ( V_49 < 0 ) {
F_31 ( V_53 , L_11 ,
V_2 -> V_156 ) ;
goto V_212;
}
if ( F_44 ( & V_51 -> V_63 ) != 0 ) {
F_59 ( V_53 -> V_205 , V_2 -> V_36 , V_169 ,
& V_2 -> V_6 , & V_2 -> V_7 ) ;
} else {
V_2 -> V_6 = - 1 ;
V_2 -> V_7 = - 1 ;
}
V_211 = F_82 ( V_209 , L_12 , 0 , & V_168 ) ;
if ( V_211 == - V_216 ) {
V_49 = V_211 ;
goto V_144;
}
if ( F_83 ( V_211 ) ) {
unsigned long V_217 ;
V_2 -> V_218 = F_80 ( V_53 , V_214 , L_13 ,
V_2 -> V_156 ) ;
if ( ! V_2 -> V_218 ) {
V_49 = - V_215 ;
goto V_144;
}
if ( V_168 & V_219 ) {
F_84 ( V_53 , L_14 ,
F_79 ( V_209 ) ) ;
V_217 = V_220 |
V_221 ;
} else {
V_217 = V_222 ;
}
V_49 = F_85 ( V_53 , V_211 , V_217 ,
V_2 -> V_218 ) ;
if ( V_49 ) {
if ( V_49 == - V_216 )
goto V_144;
goto V_212;
}
V_2 -> V_211 = F_86 ( V_211 ) ;
}
V_2 -> V_208 = F_87 ( V_209 , NULL ) ;
if ( F_88 ( V_2 -> V_208 ) ) {
F_31 ( V_53 , L_15 , V_2 -> V_156 ) ;
goto V_212;
}
V_49 = F_89 ( V_53 , F_74 , V_2 ) ;
if ( V_49 < 0 ) {
F_75 ( V_2 -> V_208 ) ;
goto V_144;
}
return 1 ;
V_212:
V_49 = 0 ;
F_90 ( V_53 , V_2 -> V_218 ) ;
V_2 -> V_218 = NULL ;
F_90 ( V_53 , V_2 -> V_156 ) ;
V_2 -> V_156 = NULL ;
V_144:
return V_49 ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_49 ;
V_49 = F_92 ( V_2 -> V_208 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_2 -> V_211 ) {
T_1 V_223 = 20000 ;
F_77 ( V_2 -> V_224 , L_16 ,
& V_223 ) ;
F_93 ( 100 ) ;
F_94 ( V_2 -> V_211 , 0 ) ;
F_95 ( V_223 / 1000 ) ;
}
return 0 ;
}
static void F_96 ( struct V_1 * V_2 )
{
if ( V_2 -> V_211 )
F_94 ( V_2 -> V_211 , 1 ) ;
F_97 ( V_2 -> V_208 ) ;
}
static int F_98 ( struct V_184 * V_52 )
{
struct V_147 * V_51 ;
struct V_185 * V_186 = V_52 -> V_53 . V_205 ;
struct V_185 * V_209 ;
int V_225 , V_17 , V_49 ;
V_51 = F_99 ( & V_52 -> V_53 , sizeof( struct V_147 ) ,
V_214 ) ;
if ( ! V_51 )
return - V_215 ;
V_51 -> V_52 = V_52 ;
F_100 ( V_52 , V_51 ) ;
F_101 ( & V_51 -> V_155 ) ;
if ( F_44 ( & V_51 -> V_155 ) == 0 ) {
F_31 ( & V_52 -> V_53 , L_17 ) ;
return - V_197 ;
}
F_102 ( & V_51 -> V_63 ) ;
if ( F_44 ( & V_51 -> V_63 ) != 0 ) {
V_51 -> V_157 . V_168 = V_51 -> V_63 . V_168 ;
V_51 -> V_157 . V_64 = V_226 ;
V_51 -> V_157 . V_50 = F_103 ( T_5 ,
V_227 ,
F_44 ( & V_51 -> V_63 ) ) ;
} else
V_51 -> V_157 = V_51 -> V_63 ;
V_49 = F_104 ( V_186 , & V_51 -> V_163 ) ;
if ( V_49 ) {
F_31 ( & V_52 -> V_53 , L_18 ,
V_49 ) ;
return V_49 ;
}
V_225 = F_105 ( V_52 -> V_53 . V_205 ) ;
V_51 -> V_152 = F_106 ( & V_52 -> V_53 , V_225 , sizeof( * V_51 -> V_152 ) ,
V_214 ) ;
if ( ! V_51 -> V_152 )
return - V_215 ;
V_17 = 0 ;
F_107 (pdev->dev.of_node, child) {
struct V_1 * V_2 = & V_51 -> V_152 [ V_17 ] ;
V_49 = F_76 ( V_51 , V_2 , V_209 ) ;
if ( V_49 < 0 ) {
F_70 ( V_209 ) ;
return V_49 ;
} else if ( V_49 == 0 ) {
continue;
}
V_2 -> V_224 = V_209 ;
V_17 ++ ;
}
V_51 -> V_151 = V_17 ;
for ( V_17 = 0 ; V_17 < V_51 -> V_151 ; V_17 ++ ) {
struct V_1 * V_2 = & V_51 -> V_152 [ V_17 ] ;
V_209 = V_2 -> V_224 ;
if ( ! V_209 )
continue;
V_49 = F_91 ( V_2 ) ;
if ( V_49 < 0 )
continue;
V_2 -> V_5 = F_55 ( V_52 , V_209 , V_2 ) ;
if ( F_88 ( V_2 -> V_5 ) ) {
F_31 ( & V_52 -> V_53 , L_19 ,
V_2 -> V_156 ) ;
V_2 -> V_5 = NULL ;
F_96 ( V_2 ) ;
continue;
}
F_8 ( V_2 , 1 ) ;
F_35 ( V_2 ) ;
}
V_51 -> V_151 = V_17 ;
for ( V_17 = 0 ; V_17 < ( V_227 - V_170 ) ; V_17 += V_170 )
F_108 ( V_17 , V_51 -> V_63 . V_64 + V_17 ) ;
F_67 ( V_51 ) ;
F_52 ( V_51 ) ;
F_100 ( V_52 , V_51 ) ;
return 0 ;
}

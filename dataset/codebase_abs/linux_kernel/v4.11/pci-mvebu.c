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
static void F_32 ( struct V_1 * V_2 ,
unsigned int V_45 , unsigned int V_46 ,
const struct V_55 * V_56 ,
struct V_55 * V_57 )
{
if ( V_56 -> V_5 == V_57 -> V_5 && V_56 -> V_47 == V_57 -> V_47 &&
V_56 -> V_16 == V_57 -> V_16 )
return;
if ( V_57 -> V_16 != 0 ) {
F_27 ( V_2 , V_57 -> V_5 , V_57 -> V_16 ) ;
V_57 -> V_16 = 0 ;
V_57 -> V_5 = 0 ;
}
if ( V_56 -> V_16 == 0 )
return;
F_29 ( V_2 , V_45 , V_46 , V_56 -> V_5 ,
V_56 -> V_16 , V_56 -> V_47 ) ;
* V_57 = * V_56 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_55 V_56 = {} ;
if ( V_2 -> V_58 . V_59 < V_2 -> V_58 . V_60 ||
V_2 -> V_58 . V_61 < V_2 -> V_58 . V_62 ||
! ( V_2 -> V_58 . V_63 & V_29 ) ) {
F_32 ( V_2 , V_2 -> V_6 , V_2 -> V_7 ,
& V_56 , & V_2 -> V_64 ) ;
return;
}
if ( ! F_5 ( V_2 ) ) {
F_34 ( & V_2 -> V_51 -> V_52 -> V_53 ,
L_2 ) ;
return;
}
V_56 . V_47 = ( ( V_2 -> V_58 . V_60 & 0xF0 ) << 8 ) |
( V_2 -> V_58 . V_62 << 16 ) ;
V_56 . V_5 = V_2 -> V_51 -> V_65 . V_66 + V_56 . V_47 ;
V_56 . V_16 = ( ( 0xFFF | ( ( V_2 -> V_58 . V_59 & 0xF0 ) << 8 ) |
( V_2 -> V_58 . V_61 << 16 ) ) -
V_56 . V_47 ) +
1 ;
F_32 ( V_2 , V_2 -> V_6 , V_2 -> V_7 , & V_56 ,
& V_2 -> V_64 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_55 V_56 = { . V_47 = V_54 } ;
if ( V_2 -> V_58 . V_67 < V_2 -> V_58 . V_68 ||
! ( V_2 -> V_58 . V_63 & V_30 ) ) {
F_32 ( V_2 , V_2 -> V_69 , V_2 -> V_70 ,
& V_56 , & V_2 -> V_71 ) ;
return;
}
V_56 . V_5 = ( ( V_2 -> V_58 . V_68 & 0xFFF0 ) << 16 ) ;
V_56 . V_16 = ( ( ( V_2 -> V_58 . V_67 & 0xFFF0 ) << 16 ) | 0xFFFFF ) -
V_56 . V_5 + 1 ;
F_32 ( V_2 , V_2 -> V_69 , V_2 -> V_70 , & V_56 ,
& V_2 -> V_71 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_72 * V_58 = & V_2 -> V_58 ;
memset ( V_58 , 0 , sizeof( struct V_72 ) ) ;
V_58 -> V_73 = V_74 ;
V_58 -> V_75 = V_76 ;
V_58 -> V_77 = F_3 ( V_2 , V_78 ) >> 16 ;
V_58 -> V_79 = F_3 ( V_2 , V_80 ) & 0xff ;
V_58 -> V_81 = V_82 ;
V_58 -> V_83 = 0x10 ;
V_58 -> V_60 = V_84 ;
V_58 -> V_59 = V_84 ;
V_58 -> V_85 = V_86 ;
}
static int F_37 ( struct V_1 * V_2 ,
unsigned int V_37 , int V_16 , T_1 * V_87 )
{
struct V_72 * V_58 = & V_2 -> V_58 ;
switch ( V_37 & ~ 3 ) {
case V_88 :
* V_87 = V_58 -> V_77 << 16 | V_58 -> V_75 ;
break;
case V_89 :
* V_87 = V_58 -> V_63 | V_58 -> V_85 << 16 ;
break;
case V_90 :
* V_87 = V_58 -> V_73 << 16 | V_58 -> V_91 << 8 |
V_58 -> V_79 ;
break;
case V_92 :
* V_87 = V_58 -> V_93 << 24 | V_58 -> V_81 << 16 |
V_58 -> V_94 << 8 | V_58 -> V_83 ;
break;
case V_95 ... V_96 :
* V_87 = V_58 -> V_97 [ ( ( V_37 & ~ 3 ) - V_95 ) / 4 ] ;
break;
case V_98 :
* V_87 = ( V_58 -> V_99 << 24 |
V_58 -> V_100 << 16 |
V_58 -> V_101 << 8 |
V_58 -> V_102 ) ;
break;
case V_103 :
if ( ! F_5 ( V_2 ) )
* V_87 = V_58 -> V_104 << 16 ;
else
* V_87 = ( V_58 -> V_104 << 16 |
V_58 -> V_59 << 8 |
V_58 -> V_60 ) ;
break;
case V_105 :
* V_87 = ( V_58 -> V_67 << 16 | V_58 -> V_68 ) ;
break;
case V_106 :
* V_87 = 0 ;
break;
case V_107 :
* V_87 = ( V_58 -> V_61 << 16 | V_58 -> V_62 ) ;
break;
case V_108 :
* V_87 = V_109 ;
break;
case V_110 :
* V_87 = 0 ;
break;
case V_111 :
* V_87 = 0 ;
break;
case V_112 :
* V_87 = ( V_113 << 4 | 2 |
V_114 ) << 16 | V_115 ;
break;
case V_116 :
* V_87 = F_3 ( V_2 , V_117 + V_118 ) ;
break;
case V_119 :
* V_87 = F_3 ( V_2 , V_117 + V_120 ) &
~ ( V_121 | V_122 |
V_123 | V_124 ) ;
* V_87 |= V_58 -> V_125 ;
break;
case V_126 :
* V_87 = F_3 ( V_2 , V_117 + V_127 ) &
~ V_128 ;
break;
case V_129 :
* V_87 = F_3 ( V_2 , V_117 + V_130 ) ;
break;
case V_131 :
* V_87 = V_58 -> V_132 ;
break;
case V_133 :
* V_87 = V_134 << 16 ;
break;
case V_135 :
* V_87 = V_58 -> V_136 ;
break;
case V_137 :
* V_87 = F_3 ( V_2 , V_138 ) ;
break;
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
default:
* V_87 = 0 ;
return V_42 ;
}
if ( V_16 == 2 )
* V_87 = ( * V_87 >> ( 8 * ( V_37 & 3 ) ) ) & 0xffff ;
else if ( V_16 == 1 )
* V_87 = ( * V_87 >> ( 8 * ( V_37 & 3 ) ) ) & 0xff ;
return V_42 ;
}
static int F_38 ( struct V_1 * V_2 ,
unsigned int V_37 , int V_16 , T_1 V_87 )
{
struct V_72 * V_58 = & V_2 -> V_58 ;
T_1 V_27 , V_4 ;
int V_145 ;
if ( V_16 == 4 )
V_27 = 0x0 ;
else if ( V_16 == 2 )
V_27 = ~ ( 0xffff << ( ( V_37 & 3 ) * 8 ) ) ;
else if ( V_16 == 1 )
V_27 = ~ ( 0xff << ( ( V_37 & 3 ) * 8 ) ) ;
else
return V_43 ;
V_145 = F_37 ( V_2 , V_37 & ~ 3 , 4 , & V_4 ) ;
if ( V_145 )
return V_145 ;
V_87 = ( V_4 & V_27 ) | V_87 << ( ( V_37 & 3 ) * 8 ) ;
switch ( V_37 & ~ 3 ) {
case V_89 :
{
T_1 V_146 = V_58 -> V_63 ;
if ( ! F_5 ( V_2 ) )
V_87 &= ~ V_29 ;
V_58 -> V_63 = V_87 & 0xffff ;
if ( ( V_146 ^ V_58 -> V_63 ) & V_29 )
F_33 ( V_2 ) ;
if ( ( V_146 ^ V_58 -> V_63 ) & V_30 )
F_35 ( V_2 ) ;
break;
}
case V_95 ... V_96 :
V_58 -> V_97 [ ( ( V_37 & ~ 3 ) - V_95 ) / 4 ] = V_87 ;
break;
case V_103 :
V_58 -> V_60 = ( V_87 & 0xff ) | V_84 ;
V_58 -> V_59 = ( ( V_87 >> 8 ) & 0xff ) | V_84 ;
F_33 ( V_2 ) ;
break;
case V_105 :
V_58 -> V_68 = V_87 & 0xffff ;
V_58 -> V_67 = V_87 >> 16 ;
F_35 ( V_2 ) ;
break;
case V_107 :
V_58 -> V_62 = V_87 & 0xffff ;
V_58 -> V_61 = V_87 >> 16 ;
F_33 ( V_2 ) ;
break;
case V_98 :
V_58 -> V_102 = V_87 & 0xff ;
V_58 -> V_101 = ( V_87 >> 8 ) & 0xff ;
V_58 -> V_100 = ( V_87 >> 16 ) & 0xff ;
V_58 -> V_99 = ( V_87 >> 24 ) & 0xff ;
F_7 ( V_2 , V_58 -> V_101 ) ;
break;
case V_119 :
V_87 &= ~ ( V_121 | V_122 |
V_123 | V_124 ) ;
if ( V_27 == 0xffff0000 )
V_87 &= 0xffff ;
F_1 ( V_2 , V_87 , V_117 + V_120 ) ;
break;
case V_129 :
V_87 &= ~ V_147 ;
if ( V_27 == 0xffff0000 )
V_87 &= 0xffff ;
F_1 ( V_2 , V_87 , V_117 + V_130 ) ;
break;
case V_137 :
F_1 ( V_2 , V_87 , V_138 ) ;
break;
default:
break;
}
return V_42 ;
}
static inline struct V_148 * F_39 ( struct V_149 * V_150 )
{
return V_150 -> V_151 ;
}
static struct V_1 * F_40 ( struct V_148 * V_51 ,
struct V_34 * V_35 ,
int V_36 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_51 -> V_152 ; V_17 ++ ) {
struct V_1 * V_2 = & V_51 -> V_153 [ V_17 ] ;
if ( V_35 -> V_40 == 0 && V_2 -> V_36 == V_36 )
return V_2 ;
if ( V_35 -> V_40 != 0 &&
V_35 -> V_40 >= V_2 -> V_58 . V_101 &&
V_35 -> V_40 <= V_2 -> V_58 . V_100 )
return V_2 ;
}
return NULL ;
}
static int F_41 ( struct V_34 * V_35 , T_1 V_36 ,
int V_37 , int V_16 , T_1 V_3 )
{
struct V_148 * V_51 = F_39 ( V_35 -> V_154 ) ;
struct V_1 * V_2 ;
int V_49 ;
V_2 = F_40 ( V_51 , V_35 , V_36 ) ;
if ( ! V_2 )
return V_155 ;
if ( V_35 -> V_40 == 0 )
return F_38 ( V_2 , V_37 , V_16 , V_3 ) ;
if ( ! F_6 ( V_2 ) )
return V_155 ;
V_49 = F_24 ( V_2 , V_35 , V_36 ,
V_37 , V_16 , V_3 ) ;
return V_49 ;
}
static int F_42 ( struct V_34 * V_35 , T_1 V_36 , int V_37 ,
int V_16 , T_1 * V_3 )
{
struct V_148 * V_51 = F_39 ( V_35 -> V_154 ) ;
struct V_1 * V_2 ;
int V_49 ;
V_2 = F_40 ( V_51 , V_35 , V_36 ) ;
if ( ! V_2 ) {
* V_3 = 0xffffffff ;
return V_155 ;
}
if ( V_35 -> V_40 == 0 )
return F_37 ( V_2 , V_37 , V_16 , V_3 ) ;
if ( ! F_6 ( V_2 ) ) {
* V_3 = 0xffffffff ;
return V_155 ;
}
V_49 = F_19 ( V_2 , V_35 , V_36 ,
V_37 , V_16 , V_3 ) ;
return V_49 ;
}
static int F_43 ( int V_10 , struct V_149 * V_150 )
{
struct V_148 * V_51 = F_39 ( V_150 ) ;
int V_145 , V_17 ;
V_51 -> V_156 . V_157 = L_3 ;
V_51 -> V_158 . V_157 = L_4 ;
if ( F_44 ( & V_51 -> V_158 ) != 0 )
F_45 ( & V_150 -> V_159 , & V_51 -> V_158 ,
V_150 -> V_160 ) ;
F_45 ( & V_150 -> V_159 , & V_51 -> V_156 , V_150 -> V_161 ) ;
F_46 ( & V_150 -> V_159 , & V_51 -> V_162 ) ;
V_145 = F_47 ( & V_51 -> V_52 -> V_53 , & V_150 -> V_159 ) ;
if ( V_145 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_51 -> V_152 ; V_17 ++ ) {
struct V_1 * V_2 = & V_51 -> V_153 [ V_17 ] ;
if ( ! V_2 -> V_5 )
continue;
F_18 ( V_2 ) ;
}
return 1 ;
}
static T_5 F_48 ( struct V_163 * V_53 ,
const struct V_164 * V_165 ,
T_5 V_66 ,
T_5 V_16 ,
T_5 V_166 )
{
if ( V_53 -> V_35 -> V_40 != 0 )
return V_66 ;
if ( V_165 -> V_167 & V_168 )
return F_49 ( V_66 , F_50 ( T_5 , V_169 ,
F_51 ( V_16 ) ) ) ;
else if ( V_165 -> V_167 & V_170 )
return F_49 ( V_66 , F_50 ( T_5 , V_171 ,
F_51 ( V_16 ) ) ) ;
else
return V_66 ;
}
static void F_52 ( struct V_148 * V_51 )
{
struct V_172 V_173 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
#ifdef F_53
V_173 . V_174 = V_51 -> V_175 ;
#endif
V_173 . V_176 = 1 ;
V_173 . V_151 = ( void * * ) & V_51 ;
V_173 . V_177 = F_43 ;
V_173 . V_178 = V_179 ;
V_173 . V_180 = & V_181 ;
V_173 . V_182 = F_48 ;
F_54 ( & V_51 -> V_52 -> V_53 , & V_173 ) ;
}
static void T_2 * F_55 ( struct V_183 * V_52 ,
struct V_184 * V_185 ,
struct V_1 * V_2 )
{
struct V_164 V_186 ;
int V_49 = 0 ;
V_49 = F_56 ( V_185 , 0 , & V_186 ) ;
if ( V_49 )
return F_57 ( V_49 ) ;
return F_58 ( & V_52 -> V_53 , & V_186 ) ;
}
static int F_59 ( struct V_184 * V_185 , int V_36 ,
unsigned long type ,
unsigned int * V_187 ,
unsigned int * V_188 )
{
const int V_189 = 3 , V_190 = 2 ;
const T_6 * V_191 ;
int V_192 , V_193 , V_194 , V_195 , V_17 ;
* V_187 = - 1 ;
* V_188 = - 1 ;
V_191 = F_60 ( V_185 , L_5 , & V_192 ) ;
if ( ! V_191 )
return - V_196 ;
V_195 = F_61 ( V_185 ) ;
V_194 = V_195 + V_189 + V_190 ;
V_193 = V_192 / sizeof( T_6 ) / V_194 ;
for ( V_17 = 0 ; V_17 < V_193 ; V_17 ++ , V_191 += V_194 ) {
T_1 V_167 = F_62 ( V_191 , 1 ) ;
T_1 V_197 = F_62 ( V_191 + 1 , 1 ) ;
T_7 V_198 = F_62 ( V_191 + V_189 , V_195 ) ;
unsigned long V_199 ;
if ( F_63 ( V_167 ) == V_200 )
V_199 = V_168 ;
else if ( F_63 ( V_167 ) == V_201 )
V_199 = V_170 ;
else
continue;
if ( V_197 == F_64 ( V_36 ) && type == V_199 ) {
* V_187 = F_65 ( V_198 ) ;
* V_188 = F_66 ( V_198 ) ;
return 0 ;
}
}
return - V_202 ;
}
static void F_67 ( struct V_148 * V_51 )
{
struct V_184 * V_203 ;
V_203 = F_68 ( V_51 -> V_52 -> V_53 . V_204 ,
L_6 , 0 ) ;
if ( ! V_203 )
return;
V_51 -> V_175 = F_69 ( V_203 ) ;
F_70 ( V_203 ) ;
if ( V_51 -> V_175 )
V_51 -> V_175 -> V_53 = & V_51 -> V_52 -> V_53 ;
}
static int F_71 ( struct V_77 * V_53 )
{
struct V_148 * V_51 ;
int V_17 ;
V_51 = F_72 ( V_53 ) ;
for ( V_17 = 0 ; V_17 < V_51 -> V_152 ; V_17 ++ ) {
struct V_1 * V_2 = V_51 -> V_153 + V_17 ;
V_2 -> V_205 = F_3 ( V_2 , V_8 ) ;
}
return 0 ;
}
static int F_73 ( struct V_77 * V_53 )
{
struct V_148 * V_51 ;
int V_17 ;
V_51 = F_72 ( V_53 ) ;
for ( V_17 = 0 ; V_17 < V_51 -> V_152 ; V_17 ++ ) {
struct V_1 * V_2 = V_51 -> V_153 + V_17 ;
F_1 ( V_2 , V_2 -> V_205 , V_8 ) ;
F_18 ( V_2 ) ;
}
return 0 ;
}
static void F_74 ( void * V_206 )
{
struct V_1 * V_2 = V_206 ;
F_75 ( V_2 -> V_207 ) ;
}
static int F_76 ( struct V_148 * V_51 ,
struct V_1 * V_2 , struct V_184 * V_208 )
{
struct V_77 * V_53 = & V_51 -> V_52 -> V_53 ;
enum V_209 V_167 ;
int V_210 , V_49 ;
V_2 -> V_51 = V_51 ;
if ( F_77 ( V_208 , L_7 , & V_2 -> V_2 ) ) {
F_78 ( V_53 , L_8 ,
F_79 ( V_208 ) ) ;
goto V_211;
}
if ( F_77 ( V_208 , L_9 , & V_2 -> V_212 ) )
V_2 -> V_212 = 0 ;
V_2 -> V_157 = F_80 ( V_53 , V_213 , L_10 , V_2 -> V_2 ,
V_2 -> V_212 ) ;
if ( ! V_2 -> V_157 ) {
V_49 = - V_214 ;
goto V_145;
}
V_2 -> V_36 = F_81 ( V_208 ) ;
if ( V_2 -> V_36 < 0 )
goto V_211;
V_49 = F_59 ( V_53 -> V_204 , V_2 -> V_36 , V_170 ,
& V_2 -> V_69 , & V_2 -> V_70 ) ;
if ( V_49 < 0 ) {
F_31 ( V_53 , L_11 ,
V_2 -> V_157 ) ;
goto V_211;
}
if ( F_44 ( & V_51 -> V_65 ) != 0 ) {
F_59 ( V_53 -> V_204 , V_2 -> V_36 , V_168 ,
& V_2 -> V_6 , & V_2 -> V_7 ) ;
} else {
V_2 -> V_6 = - 1 ;
V_2 -> V_7 = - 1 ;
}
V_210 = F_82 ( V_208 , L_12 , 0 , & V_167 ) ;
if ( V_210 == - V_215 ) {
V_49 = V_210 ;
goto V_145;
}
if ( F_83 ( V_210 ) ) {
unsigned long V_216 ;
V_2 -> V_217 = F_80 ( V_53 , V_213 , L_13 ,
V_2 -> V_157 ) ;
if ( ! V_2 -> V_217 ) {
V_49 = - V_214 ;
goto V_145;
}
if ( V_167 & V_218 ) {
F_84 ( V_53 , L_14 ,
F_79 ( V_208 ) ) ;
V_216 = V_219 |
V_220 ;
} else {
V_216 = V_221 ;
}
V_49 = F_85 ( V_53 , V_210 , V_216 ,
V_2 -> V_217 ) ;
if ( V_49 ) {
if ( V_49 == - V_215 )
goto V_145;
goto V_211;
}
V_2 -> V_210 = F_86 ( V_210 ) ;
}
V_2 -> V_207 = F_87 ( V_208 , NULL ) ;
if ( F_88 ( V_2 -> V_207 ) ) {
F_31 ( V_53 , L_15 , V_2 -> V_157 ) ;
goto V_211;
}
V_49 = F_89 ( V_53 , F_74 , V_2 ) ;
if ( V_49 < 0 ) {
F_75 ( V_2 -> V_207 ) ;
goto V_145;
}
return 1 ;
V_211:
V_49 = 0 ;
F_90 ( V_53 , V_2 -> V_217 ) ;
V_2 -> V_217 = NULL ;
F_90 ( V_53 , V_2 -> V_157 ) ;
V_2 -> V_157 = NULL ;
V_145:
return V_49 ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_49 ;
V_49 = F_92 ( V_2 -> V_207 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_2 -> V_210 ) {
T_1 V_222 = V_223 * 1000 ;
F_77 ( V_2 -> V_224 , L_16 ,
& V_222 ) ;
F_93 ( 100 ) ;
F_94 ( V_2 -> V_210 , 0 ) ;
F_95 ( V_222 / 1000 ) ;
}
return 0 ;
}
static void F_96 ( struct V_1 * V_2 )
{
if ( V_2 -> V_210 )
F_94 ( V_2 -> V_210 , 1 ) ;
F_97 ( V_2 -> V_207 ) ;
}
static int F_98 ( struct V_183 * V_52 )
{
struct V_77 * V_53 = & V_52 -> V_53 ;
struct V_148 * V_51 ;
struct V_184 * V_185 = V_53 -> V_204 ;
struct V_184 * V_208 ;
int V_225 , V_17 , V_49 ;
V_51 = F_99 ( V_53 , sizeof( * V_51 ) , V_213 ) ;
if ( ! V_51 )
return - V_214 ;
V_51 -> V_52 = V_52 ;
F_100 ( V_52 , V_51 ) ;
F_101 ( & V_51 -> V_156 ) ;
if ( F_44 ( & V_51 -> V_156 ) == 0 ) {
F_31 ( V_53 , L_17 ) ;
return - V_196 ;
}
F_102 ( & V_51 -> V_65 ) ;
if ( F_44 ( & V_51 -> V_65 ) != 0 ) {
V_51 -> V_158 . V_167 = V_51 -> V_65 . V_167 ;
V_51 -> V_158 . V_66 = V_226 ;
V_51 -> V_158 . V_50 = F_103 ( T_5 ,
V_227 ,
F_44 ( & V_51 -> V_65 ) ) ;
} else
V_51 -> V_158 = V_51 -> V_65 ;
V_49 = F_104 ( V_185 , & V_51 -> V_162 ) ;
if ( V_49 ) {
F_31 ( V_53 , L_18 , V_49 ) ;
return V_49 ;
}
V_225 = F_105 ( V_185 ) ;
V_51 -> V_153 = F_106 ( V_53 , V_225 , sizeof( * V_51 -> V_153 ) , V_213 ) ;
if ( ! V_51 -> V_153 )
return - V_214 ;
V_17 = 0 ;
F_107 (np, child) {
struct V_1 * V_2 = & V_51 -> V_153 [ V_17 ] ;
V_49 = F_76 ( V_51 , V_2 , V_208 ) ;
if ( V_49 < 0 ) {
F_70 ( V_208 ) ;
return V_49 ;
} else if ( V_49 == 0 ) {
continue;
}
V_2 -> V_224 = V_208 ;
V_17 ++ ;
}
V_51 -> V_152 = V_17 ;
for ( V_17 = 0 ; V_17 < V_51 -> V_152 ; V_17 ++ ) {
struct V_1 * V_2 = & V_51 -> V_153 [ V_17 ] ;
V_208 = V_2 -> V_224 ;
if ( ! V_208 )
continue;
V_49 = F_91 ( V_2 ) ;
if ( V_49 < 0 )
continue;
V_2 -> V_5 = F_55 ( V_52 , V_208 , V_2 ) ;
if ( F_88 ( V_2 -> V_5 ) ) {
F_31 ( V_53 , L_19 , V_2 -> V_157 ) ;
V_2 -> V_5 = NULL ;
F_96 ( V_2 ) ;
continue;
}
F_8 ( V_2 , 1 ) ;
F_36 ( V_2 ) ;
}
V_51 -> V_152 = V_17 ;
for ( V_17 = 0 ; V_17 < ( V_227 - V_169 ) ; V_17 += V_169 )
F_108 ( V_17 , V_51 -> V_65 . V_66 + V_17 ) ;
F_67 ( V_51 ) ;
F_52 ( V_51 ) ;
F_100 ( V_52 , V_51 ) ;
return 0 ;
}

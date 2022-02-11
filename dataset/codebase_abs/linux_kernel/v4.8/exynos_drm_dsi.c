static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline void F_3 ( struct V_1 * V_5 , enum V_6 V_7 ,
T_1 V_8 )
{
F_4 ( V_8 , V_5 -> V_9 + V_5 -> V_10 -> V_11 [ V_7 ] ) ;
}
static inline T_1 F_5 ( struct V_1 * V_5 , enum V_6 V_7 )
{
return F_6 ( V_5 -> V_9 + V_5 -> V_10 -> V_11 [ V_7 ] ) ;
}
static void F_7 ( struct V_1 * V_5 )
{
if ( F_8 ( & V_5 -> V_12 , F_9 ( 300 ) ) )
return;
F_10 ( V_5 -> V_13 , L_1 ) ;
}
static void F_11 ( struct V_1 * V_5 )
{
T_1 V_14 = V_5 -> V_10 -> V_15 [ V_16 ] ;
F_12 ( & V_5 -> V_12 ) ;
F_3 ( V_5 , V_17 , V_14 ) ;
}
static unsigned long F_13 ( struct V_1 * V_5 ,
unsigned long V_18 , unsigned long V_19 , T_2 * V_20 , T_3 * V_21 , T_2 * V_22 )
{
const struct V_23 * V_10 = V_5 -> V_10 ;
unsigned long V_24 = 0 ;
T_1 V_25 = 0xffffffff ;
T_2 V_26 , V_27 ;
T_2 V_28 , V_29 ( V_30 ) ;
T_3 V_31 , V_29 ( V_32 ) ;
T_2 V_33 , V_29 ( V_34 ) ;
V_26 = F_14 ( V_18 , ( 12 * V_35 ) ) ;
V_27 = V_18 / ( 6 * V_35 ) ;
for ( V_28 = V_26 ; V_28 <= V_27 ; ++ V_28 ) {
for ( V_33 = 0 ; V_33 <= 5 ; ++ V_33 ) {
T_4 V_36 ;
T_1 V_37 ;
V_36 = ( T_4 ) V_19 * ( V_28 << V_33 ) ;
F_15 ( V_36 , V_18 ) ;
V_31 = V_36 ;
if ( V_31 < 41 || V_31 > 125 )
continue;
V_36 = ( T_4 ) V_31 * V_18 ;
F_15 ( V_36 , V_28 ) ;
if ( V_36 < 500 * V_35 ||
V_36 > V_10 -> V_38 * V_35 )
continue;
V_36 = ( T_4 ) V_31 * V_18 ;
F_15 ( V_36 , V_28 << V_33 ) ;
V_37 = abs ( V_19 - V_36 ) ;
if ( V_37 < V_25 ) {
V_30 = V_28 ;
V_32 = V_31 ;
V_34 = V_33 ;
V_25 = V_37 ;
V_24 = V_36 ;
}
}
}
if ( V_24 ) {
* V_20 = V_30 ;
* V_21 = V_32 ;
* V_22 = V_34 ;
}
return V_24 ;
}
static unsigned long F_16 ( struct V_1 * V_5 ,
unsigned long V_39 )
{
const struct V_23 * V_10 = V_5 -> V_10 ;
unsigned long V_18 , V_19 ;
int V_40 ;
T_2 V_20 , V_22 ;
T_3 V_21 ;
T_1 V_41 ;
V_18 = V_5 -> V_42 ;
V_19 = F_13 ( V_5 , V_18 , V_39 , & V_20 , & V_21 , & V_22 ) ;
if ( ! V_19 ) {
F_10 ( V_5 -> V_13 ,
L_2 ) ;
return 0 ;
}
F_17 ( V_5 -> V_13 , L_3 , V_19 , V_20 , V_21 , V_22 ) ;
F_4 ( V_10 -> V_15 [ V_43 ] ,
V_5 -> V_9 + V_10 -> V_44 ) ;
V_41 = V_45 | F_18 ( V_20 ) | F_19 ( V_21 ) | F_20 ( V_22 ) ;
if ( V_10 -> V_46 ) {
static const unsigned long V_47 [] = {
100 * V_35 , 120 * V_35 , 160 * V_35 , 200 * V_35 ,
270 * V_35 , 320 * V_35 , 390 * V_35 , 450 * V_35 ,
510 * V_35 , 560 * V_35 , 640 * V_35 , 690 * V_35 ,
770 * V_35 , 870 * V_35 , 950 * V_35 ,
} ;
int V_48 ;
for ( V_48 = 0 ; V_48 < F_21 ( V_47 ) ; ++ V_48 )
if ( V_19 < V_47 [ V_48 ] )
break;
F_17 ( V_5 -> V_13 , L_4 , V_48 ) ;
V_41 |= F_22 ( V_48 ) ;
}
F_3 ( V_5 , V_49 , V_41 ) ;
V_40 = 1000 ;
do {
if ( V_40 -- == 0 ) {
F_10 ( V_5 -> V_13 , L_5 ) ;
return 0 ;
}
V_41 = F_5 ( V_5 , V_50 ) ;
} while ( ( V_41 & V_51 ) == 0 );
return V_19 ;
}
static int F_23 ( struct V_1 * V_5 )
{
unsigned long V_52 , V_53 , V_54 ;
unsigned long V_55 ;
T_1 V_41 ;
V_52 = F_16 ( V_5 , V_5 -> V_56 ) ;
if ( ! V_52 ) {
F_10 ( V_5 -> V_13 , L_6 ) ;
return - V_57 ;
}
V_53 = V_52 / 8 ;
V_55 = F_14 ( V_53 , V_5 -> V_58 ) ;
V_54 = V_53 / V_55 ;
if ( V_54 > 20 * V_35 ) {
++ V_55 ;
V_54 = V_53 / V_55 ;
}
F_17 ( V_5 -> V_13 , L_7 ,
V_52 , V_53 , V_54 ) ;
V_41 = F_5 ( V_5 , V_59 ) ;
V_41 &= ~ ( V_60 | V_61
| V_62 | V_63
| V_64 ) ;
V_41 |= V_65 | V_66
| F_24 ( V_55 )
| V_61
| F_25 ( F_26 ( V_5 -> V_67 ) - 1 )
| F_27 ( 0 )
| V_68 ;
F_3 ( V_5 , V_59 , V_41 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_5 )
{
const struct V_23 * V_10 = V_5 -> V_10 ;
const unsigned int * V_15 = V_10 -> V_15 ;
T_1 V_41 ;
if ( V_10 -> V_46 )
return;
V_41 = V_15 [ V_69 ] | V_15 [ V_70 ] |
V_15 [ V_71 ] ;
F_3 ( V_5 , V_72 , V_41 ) ;
V_41 = V_15 [ V_73 ] | V_15 [ V_74 ] ;
F_3 ( V_5 , V_75 , V_41 ) ;
V_41 = V_15 [ V_76 ] |
V_15 [ V_77 ] |
V_15 [ V_78 ] |
V_15 [ V_79 ] ;
F_3 ( V_5 , V_80 , V_41 ) ;
V_41 = V_15 [ V_81 ] | V_15 [ V_82 ] |
V_15 [ V_83 ] ;
F_3 ( V_5 , V_84 , V_41 ) ;
}
static void F_29 ( struct V_1 * V_5 )
{
T_1 V_41 ;
V_41 = F_5 ( V_5 , V_59 ) ;
V_41 &= ~ ( V_61 | V_62
| V_65 | V_66 ) ;
F_3 ( V_5 , V_59 , V_41 ) ;
V_41 = F_5 ( V_5 , V_49 ) ;
V_41 &= ~ V_45 ;
F_3 ( V_5 , V_49 , V_41 ) ;
}
static void F_30 ( struct V_1 * V_5 , T_1 V_85 )
{
T_1 V_41 = F_5 ( V_5 , V_86 ) ;
V_41 |= ( F_31 ( V_5 -> V_67 - 1 ) | V_87 |
F_32 ( V_85 ) ) ;
F_3 ( V_5 , V_86 , V_41 ) ;
}
static int F_33 ( struct V_1 * V_5 )
{
const struct V_23 * V_10 = V_5 -> V_10 ;
int V_40 ;
T_1 V_41 ;
T_1 V_88 ;
V_41 = F_5 ( V_5 , V_89 ) ;
V_41 &= ~ 0x1f ;
F_3 ( V_5 , V_89 , V_41 ) ;
F_34 ( 9000 , 11000 ) ;
V_41 |= 0x1f ;
F_3 ( V_5 , V_89 , V_41 ) ;
F_34 ( 9000 , 11000 ) ;
V_41 = 0 ;
if ( V_5 -> V_90 & V_91 ) {
V_41 |= V_92 ;
if ( ! ( V_5 -> V_90 & V_93 ) )
V_41 |= V_94 ;
if ( V_5 -> V_90 & V_95 )
V_41 |= V_96 ;
if ( V_5 -> V_90 & V_97 )
V_41 |= V_98 ;
if ( V_5 -> V_90 & V_99 )
V_41 |= V_100 ;
if ( V_5 -> V_90 & V_101 )
V_41 |= V_102 ;
if ( ! ( V_5 -> V_90 & V_103 ) )
V_41 |= V_104 ;
if ( ! ( V_5 -> V_90 & V_105 ) )
V_41 |= V_106 ;
if ( ! ( V_5 -> V_90 & V_107 ) )
V_41 |= V_108 ;
}
if ( ! ( V_5 -> V_90 & V_109 ) )
V_41 |= V_110 ;
switch ( V_5 -> V_111 ) {
case V_112 :
V_41 |= V_113 ;
break;
case V_114 :
V_41 |= V_115 ;
break;
case V_116 :
V_41 |= V_117 ;
break;
case V_118 :
V_41 |= V_119 ;
break;
default:
F_10 ( V_5 -> V_13 , L_8 ) ;
return - V_120 ;
}
if ( V_10 -> V_121 &&
V_5 -> V_90 & V_122 ) {
V_41 |= V_123 ;
}
F_3 ( V_5 , V_86 , V_41 ) ;
V_88 = F_26 ( V_5 -> V_67 ) - 1 ;
F_30 ( V_5 , V_88 ) ;
V_40 = 100 ;
do {
if ( V_40 -- == 0 ) {
F_10 ( V_5 -> V_13 , L_9 ) ;
return - V_57 ;
}
V_41 = F_5 ( V_5 , V_50 ) ;
if ( ( V_41 & F_35 ( V_88 ) )
!= F_35 ( V_88 ) )
continue;
} while ( ! ( V_41 & ( V_124 | V_125 ) ) );
V_41 = F_5 ( V_5 , V_126 ) ;
V_41 &= ~ V_127 ;
V_41 |= F_36 ( V_10 -> V_15 [ V_128 ] ) ;
F_3 ( V_5 , V_126 , V_41 ) ;
V_41 = F_37 ( 0xff ) | F_38 ( 0xffff ) ;
F_3 ( V_5 , V_129 , V_41 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_5 )
{
struct V_130 * V_131 = & V_5 -> V_131 ;
unsigned int V_132 = V_5 -> V_10 -> V_132 ;
T_1 V_41 ;
if ( V_5 -> V_90 & V_91 ) {
V_41 = F_40 ( 0xf )
| F_41 ( V_131 -> V_133 )
| F_42 ( V_131 -> V_134 ) ;
F_3 ( V_5 , V_135 , V_41 ) ;
V_41 = F_43 ( V_131 -> V_136 )
| F_44 ( V_131 -> V_137 ) ;
F_3 ( V_5 , V_138 , V_41 ) ;
V_41 = F_45 ( V_131 -> V_139 )
| F_46 ( V_131 -> V_140 ) ;
F_3 ( V_5 , V_141 , V_41 ) ;
}
V_41 = F_47 ( V_131 -> V_142 , V_132 ) |
F_48 ( V_131 -> V_143 , V_132 ) ;
F_3 ( V_5 , V_144 , V_41 ) ;
F_17 ( V_5 -> V_13 , L_10 , V_131 -> V_142 , V_131 -> V_143 ) ;
}
static void F_49 ( struct V_1 * V_5 , bool V_145 )
{
T_1 V_41 ;
V_41 = F_5 ( V_5 , V_144 ) ;
if ( V_145 )
V_41 |= V_146 ;
else
V_41 &= ~ V_146 ;
F_3 ( V_5 , V_144 , V_41 ) ;
}
static int F_50 ( struct V_1 * V_5 )
{
int V_40 = 2000 ;
do {
T_1 V_41 = F_5 ( V_5 , V_89 ) ;
if ( ! ( V_41 & V_147 ) )
return 0 ;
if ( ! F_51 () )
F_34 ( 950 , 1050 ) ;
} while ( -- V_40 );
return - V_148 ;
}
static void F_52 ( struct V_1 * V_5 , bool V_149 )
{
T_1 V_150 = F_5 ( V_5 , V_126 ) ;
if ( V_149 )
V_150 |= V_151 ;
else
V_150 &= ~ V_151 ;
F_3 ( V_5 , V_126 , V_150 ) ;
}
static void F_53 ( struct V_1 * V_5 )
{
T_1 V_150 = F_5 ( V_5 , V_126 ) ;
V_150 |= V_152 ;
F_3 ( V_5 , V_126 , V_150 ) ;
}
static void F_54 ( struct V_1 * V_5 ,
struct V_153 * V_154 )
{
struct V_155 * V_13 = V_5 -> V_13 ;
struct V_156 * V_157 = & V_154 -> V_158 ;
const T_2 * V_159 = V_157 -> V_159 + V_154 -> V_160 ;
T_3 V_161 = V_157 -> V_162 - V_154 -> V_160 ;
bool V_163 = ! V_154 -> V_160 ;
T_1 V_41 ;
F_17 ( V_13 , L_11 ,
V_154 , V_161 , V_154 -> V_160 , V_154 -> V_164 , V_154 -> V_165 ) ;
if ( V_161 > V_166 )
V_161 = V_166 ;
V_154 -> V_160 += V_161 ;
while ( V_161 >= 4 ) {
V_41 = F_55 ( V_159 ) ;
F_3 ( V_5 , V_167 , V_41 ) ;
V_159 += 4 ;
V_161 -= 4 ;
}
V_41 = 0 ;
switch ( V_161 ) {
case 3 :
V_41 |= V_159 [ 2 ] << 16 ;
case 2 :
V_41 |= V_159 [ 1 ] << 8 ;
case 1 :
V_41 |= V_159 [ 0 ] ;
F_3 ( V_5 , V_167 , V_41 ) ;
break;
}
if ( ! V_163 )
return;
V_41 = F_55 ( V_157 -> V_168 ) ;
if ( F_50 ( V_5 ) ) {
F_10 ( V_13 , L_12 ) ;
return;
}
if ( F_56 ( V_154 -> V_169 & V_170 ,
V_5 -> V_171 & V_172 ) ) {
F_52 ( V_5 , V_154 -> V_169 & V_170 ) ;
V_5 -> V_171 ^= V_172 ;
}
F_3 ( V_5 , V_173 , V_41 ) ;
if ( V_154 -> V_169 & V_174 )
F_53 ( V_5 ) ;
}
static void F_57 ( struct V_1 * V_5 ,
struct V_153 * V_154 )
{
T_2 * V_159 = V_154 -> V_175 + V_154 -> V_165 ;
bool V_163 = ! V_154 -> V_165 ;
struct V_155 * V_13 = V_5 -> V_13 ;
T_3 V_161 ;
T_1 V_41 ;
if ( V_163 ) {
V_41 = F_5 ( V_5 , V_176 ) ;
switch ( V_41 & 0x3f ) {
case V_177 :
case V_178 :
if ( V_154 -> V_164 >= 2 ) {
V_159 [ 1 ] = V_41 >> 16 ;
++ V_154 -> V_165 ;
}
case V_179 :
case V_180 :
V_159 [ 0 ] = V_41 >> 8 ;
++ V_154 -> V_165 ;
V_154 -> V_164 = V_154 -> V_165 ;
V_154 -> V_181 = 0 ;
goto V_182;
case V_183 :
F_10 ( V_13 , L_13 ,
( V_41 >> 8 ) & 0xffff ) ;
V_154 -> V_181 = 0 ;
goto V_182;
}
V_161 = ( V_41 >> 8 ) & 0xffff ;
if ( V_161 > V_154 -> V_164 ) {
F_10 ( V_13 ,
L_14 ,
V_154 -> V_164 , V_161 ) ;
V_161 = V_154 -> V_164 ;
} else if ( V_161 < V_154 -> V_164 )
V_154 -> V_164 = V_161 ;
}
V_161 = V_154 -> V_164 - V_154 -> V_165 ;
V_154 -> V_165 += V_161 ;
while ( V_161 >= 4 ) {
V_41 = F_5 ( V_5 , V_176 ) ;
V_159 [ 0 ] = ( V_41 >> 0 ) & 0xff ;
V_159 [ 1 ] = ( V_41 >> 8 ) & 0xff ;
V_159 [ 2 ] = ( V_41 >> 16 ) & 0xff ;
V_159 [ 3 ] = ( V_41 >> 24 ) & 0xff ;
V_159 += 4 ;
V_161 -= 4 ;
}
if ( V_161 ) {
V_41 = F_5 ( V_5 , V_176 ) ;
switch ( V_161 ) {
case 3 :
V_159 [ 2 ] = ( V_41 >> 16 ) & 0xff ;
case 2 :
V_159 [ 1 ] = ( V_41 >> 8 ) & 0xff ;
case 1 :
V_159 [ 0 ] = V_41 & 0xff ;
}
}
if ( V_154 -> V_165 == V_154 -> V_164 )
V_154 -> V_181 = 0 ;
V_182:
V_161 = V_184 / 4 ;
do {
V_41 = F_5 ( V_5 , V_176 ) ;
if ( V_41 == V_185 )
break;
} while ( -- V_161 );
}
static void F_58 ( struct V_1 * V_5 )
{
unsigned long V_169 ;
struct V_153 * V_154 ;
bool V_186 = false ;
V_187:
F_59 ( & V_5 -> V_188 , V_169 ) ;
if ( F_60 ( & V_5 -> V_189 ) ) {
F_61 ( & V_5 -> V_188 , V_169 ) ;
return;
}
V_154 = F_62 ( & V_5 -> V_189 ,
struct V_153 , V_190 ) ;
F_61 ( & V_5 -> V_188 , V_169 ) ;
if ( V_154 -> V_158 . V_162 &&
V_154 -> V_160 == V_154 -> V_158 . V_162 )
return;
F_54 ( V_5 , V_154 ) ;
if ( V_154 -> V_158 . V_162 || V_154 -> V_164 )
return;
V_154 -> V_181 = 0 ;
F_63 ( & V_154 -> V_12 ) ;
F_59 ( & V_5 -> V_188 , V_169 ) ;
F_64 ( & V_154 -> V_190 ) ;
V_186 = ! F_60 ( & V_5 -> V_189 ) ;
F_61 ( & V_5 -> V_188 , V_169 ) ;
if ( V_186 )
goto V_187;
}
static bool F_65 ( struct V_1 * V_5 )
{
struct V_153 * V_154 ;
unsigned long V_169 ;
bool V_186 = true ;
F_59 ( & V_5 -> V_188 , V_169 ) ;
if ( F_60 ( & V_5 -> V_189 ) ) {
F_61 ( & V_5 -> V_188 , V_169 ) ;
return false ;
}
V_154 = F_62 ( & V_5 -> V_189 ,
struct V_153 , V_190 ) ;
F_61 ( & V_5 -> V_188 , V_169 ) ;
F_17 ( V_5 -> V_13 ,
L_15 ,
V_154 , V_154 -> V_158 . V_162 , V_154 -> V_160 , V_154 -> V_164 ,
V_154 -> V_165 ) ;
if ( V_154 -> V_160 != V_154 -> V_158 . V_162 )
return true ;
if ( V_154 -> V_165 != V_154 -> V_164 )
F_57 ( V_5 , V_154 ) ;
if ( V_154 -> V_165 != V_154 -> V_164 )
return true ;
F_59 ( & V_5 -> V_188 , V_169 ) ;
F_64 ( & V_154 -> V_190 ) ;
V_186 = ! F_60 ( & V_5 -> V_189 ) ;
F_61 ( & V_5 -> V_188 , V_169 ) ;
if ( ! V_154 -> V_164 )
V_154 -> V_181 = 0 ;
F_63 ( & V_154 -> V_12 ) ;
return V_186 ;
}
static void F_66 ( struct V_1 * V_5 ,
struct V_153 * V_154 )
{
unsigned long V_169 ;
bool V_186 ;
F_59 ( & V_5 -> V_188 , V_169 ) ;
if ( ! F_60 ( & V_5 -> V_189 ) &&
V_154 == F_62 ( & V_5 -> V_189 ,
struct V_153 , V_190 ) ) {
F_64 ( & V_154 -> V_190 ) ;
V_186 = ! F_60 ( & V_5 -> V_189 ) ;
F_61 ( & V_5 -> V_188 , V_169 ) ;
if ( V_186 )
F_58 ( V_5 ) ;
return;
}
F_64 ( & V_154 -> V_190 ) ;
F_61 ( & V_5 -> V_188 , V_169 ) ;
}
static int V_153 ( struct V_1 * V_5 ,
struct V_153 * V_154 )
{
unsigned long V_169 ;
bool V_191 ;
V_154 -> V_160 = 0 ;
V_154 -> V_165 = 0 ;
V_154 -> V_181 = - V_148 ;
F_67 ( & V_154 -> V_12 ) ;
F_59 ( & V_5 -> V_188 , V_169 ) ;
V_191 = F_60 ( & V_5 -> V_189 ) ;
F_68 ( & V_154 -> V_190 , & V_5 -> V_189 ) ;
F_61 ( & V_5 -> V_188 , V_169 ) ;
if ( V_191 )
F_58 ( V_5 ) ;
F_8 ( & V_154 -> V_12 ,
F_9 ( V_192 ) ) ;
if ( V_154 -> V_181 == - V_148 ) {
struct V_156 * V_157 = & V_154 -> V_158 ;
F_66 ( V_5 , V_154 ) ;
F_10 ( V_5 -> V_13 , L_16 , 4 , V_157 -> V_168 ,
( int ) V_157 -> V_162 , V_157 -> V_159 ) ;
return - V_148 ;
}
return V_154 -> V_181 ;
}
static T_5 F_69 ( int V_193 , void * V_194 )
{
struct V_1 * V_5 = V_194 ;
T_1 V_195 ;
V_195 = F_5 ( V_5 , V_196 ) ;
if ( ! V_195 ) {
static unsigned long int V_197 ;
if ( F_70 ( & V_197 , 500 ) )
F_71 ( V_5 -> V_13 , L_17 ) ;
return V_198 ;
}
F_3 ( V_5 , V_196 , V_195 ) ;
if ( V_195 & V_199 ) {
T_1 V_200 = ~ ( V_201 | V_202 |
V_203 | V_204 |
V_205 | V_199 ) ;
F_3 ( V_5 , V_206 , V_200 ) ;
F_63 ( & V_5 -> V_12 ) ;
return V_198 ;
}
if ( ! ( V_195 & ( V_201 | V_202 |
V_204 | V_207 ) ) )
return V_198 ;
if ( F_65 ( V_5 ) )
F_58 ( V_5 ) ;
return V_198 ;
}
static T_5 F_72 ( int V_193 , void * V_194 )
{
struct V_1 * V_5 = (struct V_1 * ) V_194 ;
struct V_2 * V_4 = & V_5 -> V_4 ;
if ( V_5 -> V_171 & V_208 )
F_73 ( V_4 -> V_209 ) ;
return V_198 ;
}
static void F_74 ( struct V_1 * V_5 )
{
F_75 ( V_5 -> V_193 ) ;
if ( F_76 ( V_5 -> V_210 ) )
F_75 ( F_77 ( V_5 -> V_210 ) ) ;
}
static void F_78 ( struct V_1 * V_5 )
{
if ( F_76 ( V_5 -> V_210 ) )
F_79 ( F_77 ( V_5 -> V_210 ) ) ;
F_79 ( V_5 -> V_193 ) ;
}
static int F_80 ( struct V_1 * V_5 )
{
const struct V_23 * V_10 = V_5 -> V_10 ;
F_11 ( V_5 ) ;
F_74 ( V_5 ) ;
if ( V_10 -> V_15 [ V_16 ] == V_211 )
F_30 ( V_5 , F_26 ( V_5 -> V_67 ) - 1 ) ;
F_23 ( V_5 ) ;
if ( V_10 -> V_212 )
F_7 ( V_5 ) ;
F_28 ( V_5 ) ;
F_33 ( V_5 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_5 )
{
int V_213 ;
int V_214 ;
V_5 -> V_210 = F_82 ( V_5 -> V_215 , L_18 , 0 ) ;
if ( ! F_76 ( V_5 -> V_210 ) ) {
F_10 ( V_5 -> V_13 , L_19 ) ;
V_213 = V_5 -> V_210 ;
goto V_216;
}
V_213 = F_83 ( V_5 -> V_210 , L_20 ) ;
if ( V_213 ) {
F_10 ( V_5 -> V_13 , L_21 , V_213 ) ;
goto V_216;
}
V_214 = F_77 ( V_5 -> V_210 ) ;
F_84 ( V_214 , V_217 ) ;
V_213 = F_85 ( V_214 , F_72 , NULL ,
V_218 , L_22 , V_5 ) ;
if ( V_213 ) {
F_10 ( V_5 -> V_13 , L_23 , V_213 ) ;
F_86 ( V_5 -> V_210 ) ;
goto V_216;
}
V_216:
return V_213 ;
}
static void F_87 ( struct V_1 * V_5 )
{
if ( F_76 ( V_5 -> V_210 ) ) {
F_88 ( F_77 ( V_5 -> V_210 ) , V_5 ) ;
F_86 ( V_5 -> V_210 ) ;
V_5 -> V_210 = - V_219 ;
}
}
static int F_89 ( struct V_220 * V_221 ,
struct V_222 * V_155 )
{
struct V_1 * V_5 = F_90 ( V_221 ) ;
V_5 -> V_67 = V_155 -> V_67 ;
V_5 -> V_111 = V_155 -> V_111 ;
V_5 -> V_90 = V_155 -> V_90 ;
V_5 -> V_215 = V_155 -> V_13 . V_223 ;
if ( ! ( V_5 -> V_90 & V_91 ) ) {
int V_213 = F_81 ( V_5 ) ;
if ( V_213 )
return V_213 ;
}
if ( V_5 -> V_224 . V_13 )
F_91 ( V_5 -> V_224 . V_13 ) ;
return 0 ;
}
static int F_92 ( struct V_220 * V_221 ,
struct V_222 * V_155 )
{
struct V_1 * V_5 = F_90 ( V_221 ) ;
F_87 ( V_5 ) ;
V_5 -> V_215 = NULL ;
if ( V_5 -> V_224 . V_13 )
F_91 ( V_5 -> V_224 . V_13 ) ;
return 0 ;
}
static T_6 F_93 ( struct V_220 * V_221 ,
const struct V_225 * V_226 )
{
struct V_1 * V_5 = F_90 ( V_221 ) ;
struct V_153 V_154 ;
int V_213 ;
if ( ! ( V_5 -> V_171 & V_227 ) )
return - V_120 ;
if ( ! ( V_5 -> V_171 & V_228 ) ) {
V_213 = F_80 ( V_5 ) ;
if ( V_213 )
return V_213 ;
V_5 -> V_171 |= V_228 ;
}
V_213 = F_94 ( & V_154 . V_158 , V_226 ) ;
if ( V_213 < 0 )
return V_213 ;
V_154 . V_164 = V_226 -> V_164 ;
V_154 . V_175 = V_226 -> V_229 ;
V_154 . V_169 = V_226 -> V_169 ;
V_213 = V_153 ( V_5 , & V_154 ) ;
return ( V_213 < 0 ) ? V_213 : V_154 . V_165 ;
}
static void F_95 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_213 ;
if ( V_5 -> V_171 & V_227 )
return;
F_96 ( V_5 -> V_13 ) ;
V_5 -> V_171 |= V_227 ;
V_213 = F_97 ( V_5 -> V_230 ) ;
if ( V_213 < 0 ) {
V_5 -> V_171 &= ~ V_227 ;
F_98 ( V_5 -> V_13 ) ;
return;
}
F_39 ( V_5 ) ;
F_49 ( V_5 , true ) ;
V_213 = F_99 ( V_5 -> V_230 ) ;
if ( V_213 < 0 ) {
V_5 -> V_171 &= ~ V_227 ;
F_49 ( V_5 , false ) ;
F_100 ( V_5 -> V_230 ) ;
F_98 ( V_5 -> V_13 ) ;
return;
}
V_5 -> V_171 |= V_208 ;
}
static void F_101 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( ! ( V_5 -> V_171 & V_227 ) )
return;
V_5 -> V_171 &= ~ V_208 ;
F_102 ( V_5 -> V_230 ) ;
F_49 ( V_5 , false ) ;
F_100 ( V_5 -> V_230 ) ;
V_5 -> V_171 &= ~ V_227 ;
F_98 ( V_5 -> V_13 ) ;
}
static enum V_231
F_103 ( struct V_232 * V_224 , bool V_233 )
{
struct V_1 * V_5 = F_104 ( V_224 ) ;
if ( ! V_5 -> V_230 ) {
V_5 -> V_230 = F_105 ( V_5 -> V_215 ) ;
if ( V_5 -> V_230 )
F_106 ( V_5 -> V_230 , & V_5 -> V_224 ) ;
} else if ( ! V_5 -> V_215 ) {
struct V_2 * V_4 ;
V_4 = F_107 ( F_108 ( V_5 -> V_13 ) ) ;
F_101 ( V_4 ) ;
F_109 ( V_5 -> V_230 ) ;
V_5 -> V_230 = NULL ;
}
if ( V_5 -> V_230 )
return V_234 ;
return V_235 ;
}
static void F_110 ( struct V_232 * V_224 )
{
F_111 ( V_224 ) ;
F_112 ( V_224 ) ;
V_224 -> V_13 = NULL ;
}
static int F_113 ( struct V_232 * V_224 )
{
struct V_1 * V_5 = F_104 ( V_224 ) ;
if ( V_5 -> V_230 )
return V_5 -> V_230 -> V_236 -> V_237 ( V_5 -> V_230 ) ;
return 0 ;
}
static int F_114 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_232 * V_224 = & V_5 -> V_224 ;
int V_213 ;
V_224 -> V_238 = V_239 ;
V_213 = F_115 ( V_4 -> V_13 , V_224 ,
& V_240 ,
V_241 ) ;
if ( V_213 ) {
F_116 ( L_24 ) ;
return V_213 ;
}
F_117 ( V_224 , & V_242 ) ;
F_118 ( V_224 ) ;
F_119 ( V_224 , V_4 ) ;
return 0 ;
}
static void F_120 ( struct V_2 * V_4 ,
struct V_243 * V_244 ,
struct V_243 * V_245 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_130 * V_131 = & V_5 -> V_131 ;
struct V_243 * V_21 = V_245 ;
V_131 -> V_142 = V_21 -> V_246 ;
V_131 -> V_143 = V_21 -> V_247 ;
V_131 -> V_133 = V_21 -> V_248 - V_21 -> V_247 ;
V_131 -> V_134 = V_21 -> V_249 - V_21 -> V_250 ;
V_131 -> V_139 = V_21 -> V_250 - V_21 -> V_248 ;
V_131 -> V_136 = V_21 -> V_251 - V_21 -> V_246 ;
V_131 -> V_137 = V_21 -> V_252 - V_21 -> V_253 ;
V_131 -> V_140 = V_21 -> V_253 - V_21 -> V_251 ;
}
static int F_121 ( const struct V_254 * V_255 ,
const char * V_256 , T_1 * V_257 )
{
int V_213 = F_122 ( V_255 , V_256 , V_257 ) ;
if ( V_213 < 0 )
F_123 ( L_25 , V_255 -> V_258 ,
V_256 ) ;
return V_213 ;
}
static int F_124 ( struct V_1 * V_5 )
{
struct V_155 * V_13 = V_5 -> V_13 ;
struct V_254 * V_259 = V_13 -> V_223 ;
struct V_254 * V_260 ;
int V_213 ;
V_213 = F_121 ( V_259 , L_26 ,
& V_5 -> V_42 ) ;
if ( V_213 < 0 )
return V_213 ;
V_260 = F_125 ( V_259 , V_261 , 0 ) ;
if ( ! V_260 ) {
F_10 ( V_13 , L_27 ) ;
return - V_120 ;
}
V_213 = F_121 ( V_260 , L_28 ,
& V_5 -> V_56 ) ;
if ( V_213 < 0 )
goto V_262;
V_213 = F_121 ( V_260 , L_29 ,
& V_5 -> V_58 ) ;
if ( V_213 < 0 )
goto V_262;
F_126 ( V_260 ) ;
V_260 = F_127 ( V_259 , NULL ) ;
if ( ! V_260 ) {
V_213 = - V_120 ;
goto V_262;
}
V_5 -> V_263 = F_128 ( V_260 ) ;
if ( ! V_5 -> V_263 ) {
V_213 = - V_120 ;
goto V_262;
}
V_262:
F_126 ( V_260 ) ;
return V_213 ;
}
static int F_129 ( struct V_155 * V_13 , struct V_155 * V_264 ,
void * V_265 )
{
struct V_2 * V_4 = F_130 ( V_13 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_266 * V_267 = V_265 ;
struct V_268 * V_269 ;
int V_213 ;
V_213 = F_131 ( V_267 ,
V_270 ) ;
if ( V_213 < 0 )
return V_213 ;
V_4 -> V_271 = 1 << V_213 ;
F_132 ( L_30 , V_4 -> V_271 ) ;
F_133 ( V_267 , V_4 , & V_272 ,
V_273 , NULL ) ;
F_134 ( V_4 , & V_274 ) ;
V_213 = F_114 ( V_4 ) ;
if ( V_213 ) {
F_116 ( L_31 , V_213 ) ;
F_135 ( V_4 ) ;
return V_213 ;
}
V_269 = F_136 ( V_5 -> V_263 ) ;
if ( V_269 ) {
V_4 -> V_269 = V_269 ;
F_137 ( V_267 , V_269 ) ;
}
return F_138 ( & V_5 -> V_275 ) ;
}
static void F_139 ( struct V_155 * V_13 , struct V_155 * V_264 ,
void * V_265 )
{
struct V_2 * V_4 = F_130 ( V_13 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_101 ( V_4 ) ;
F_140 ( & V_5 -> V_275 ) ;
}
static int F_141 ( struct V_276 * V_277 )
{
struct V_155 * V_13 = & V_277 -> V_13 ;
struct V_278 * V_279 ;
struct V_1 * V_5 ;
int V_213 , V_280 ;
V_5 = F_142 ( V_13 , sizeof( * V_5 ) , V_281 ) ;
if ( ! V_5 )
return - V_282 ;
V_5 -> V_210 = - V_219 ;
F_67 ( & V_5 -> V_12 ) ;
F_143 ( & V_5 -> V_188 ) ;
F_144 ( & V_5 -> V_189 ) ;
V_5 -> V_275 . V_283 = & V_284 ;
V_5 -> V_275 . V_13 = V_13 ;
V_5 -> V_13 = V_13 ;
V_5 -> V_10 = F_145 ( V_13 ) ;
V_213 = F_124 ( V_5 ) ;
if ( V_213 )
return V_213 ;
V_5 -> V_285 [ 0 ] . V_286 = L_32 ;
V_5 -> V_285 [ 1 ] . V_286 = L_33 ;
V_213 = F_146 ( V_13 , F_21 ( V_5 -> V_285 ) ,
V_5 -> V_285 ) ;
if ( V_213 ) {
F_147 ( V_13 , L_34 , V_213 ) ;
return - V_287 ;
}
V_5 -> V_288 = F_142 ( V_13 ,
sizeof( * V_5 -> V_288 ) * V_5 -> V_10 -> V_289 ,
V_281 ) ;
if ( ! V_5 -> V_288 )
return - V_282 ;
for ( V_280 = 0 ; V_280 < V_5 -> V_10 -> V_289 ; V_280 ++ ) {
V_5 -> V_288 [ V_280 ] = F_148 ( V_13 , V_290 [ V_280 ] ) ;
if ( F_149 ( V_5 -> V_288 [ V_280 ] ) ) {
if ( strcmp ( V_290 [ V_280 ] , L_35 ) == 0 ) {
strcpy ( V_290 [ V_280 ] , V_291 ) ;
V_280 -- ;
continue;
}
F_147 ( V_13 , L_36 ,
V_290 [ V_280 ] ) ;
return F_150 ( V_5 -> V_288 [ V_280 ] ) ;
}
}
V_279 = F_151 ( V_277 , V_292 , 0 ) ;
V_5 -> V_9 = F_152 ( V_13 , V_279 ) ;
if ( F_149 ( V_5 -> V_9 ) ) {
F_10 ( V_13 , L_37 ) ;
return F_150 ( V_5 -> V_9 ) ;
}
V_5 -> V_293 = F_153 ( V_13 , L_38 ) ;
if ( F_149 ( V_5 -> V_293 ) ) {
F_147 ( V_13 , L_39 ) ;
return F_150 ( V_5 -> V_293 ) ;
}
V_5 -> V_193 = F_154 ( V_277 , 0 ) ;
if ( V_5 -> V_193 < 0 ) {
F_10 ( V_13 , L_40 ) ;
return V_5 -> V_193 ;
}
F_84 ( V_5 -> V_193 , V_217 ) ;
V_213 = F_155 ( V_13 , V_5 -> V_193 , NULL ,
F_69 , V_294 ,
F_156 ( V_13 ) , V_5 ) ;
if ( V_213 ) {
F_10 ( V_13 , L_41 ) ;
return V_213 ;
}
F_157 ( V_277 , & V_5 -> V_4 ) ;
F_158 ( V_13 ) ;
return F_159 ( V_13 , & V_295 ) ;
}
static int F_160 ( struct V_276 * V_277 )
{
F_161 ( & V_277 -> V_13 ) ;
F_162 ( & V_277 -> V_13 , & V_295 ) ;
return 0 ;
}
static int T_7 F_163 ( struct V_155 * V_13 )
{
struct V_2 * V_4 = F_130 ( V_13 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
const struct V_23 * V_10 = V_5 -> V_10 ;
int V_213 , V_280 ;
F_34 ( 10000 , 20000 ) ;
if ( V_5 -> V_171 & V_228 ) {
V_5 -> V_171 &= ~ V_228 ;
F_29 ( V_5 ) ;
F_78 ( V_5 ) ;
}
V_5 -> V_171 &= ~ V_172 ;
F_164 ( V_5 -> V_293 ) ;
for ( V_280 = V_10 -> V_289 - 1 ; V_280 > - 1 ; V_280 -- )
F_165 ( V_5 -> V_288 [ V_280 ] ) ;
V_213 = F_166 ( F_21 ( V_5 -> V_285 ) , V_5 -> V_285 ) ;
if ( V_213 < 0 )
F_10 ( V_5 -> V_13 , L_42 , V_213 ) ;
return 0 ;
}
static int T_7 F_167 ( struct V_155 * V_13 )
{
struct V_2 * V_4 = F_130 ( V_13 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
const struct V_23 * V_10 = V_5 -> V_10 ;
int V_213 , V_280 ;
V_213 = F_168 ( F_21 ( V_5 -> V_285 ) , V_5 -> V_285 ) ;
if ( V_213 < 0 ) {
F_10 ( V_5 -> V_13 , L_43 , V_213 ) ;
return V_213 ;
}
for ( V_280 = 0 ; V_280 < V_10 -> V_289 ; V_280 ++ ) {
V_213 = F_169 ( V_5 -> V_288 [ V_280 ] ) ;
if ( V_213 < 0 )
goto V_296;
}
V_213 = F_170 ( V_5 -> V_293 ) ;
if ( V_213 < 0 ) {
F_10 ( V_5 -> V_13 , L_44 , V_213 ) ;
goto V_296;
}
return 0 ;
V_296:
while ( -- V_280 > - 1 )
F_165 ( V_5 -> V_288 [ V_280 ] ) ;
F_166 ( F_21 ( V_5 -> V_285 ) , V_5 -> V_285 ) ;
return V_213 ;
}

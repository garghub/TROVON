static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_6 + V_3 ;
F_2 ( F_3 ( V_5 ) | V_4 , V_5 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_6 + V_3 ;
F_2 ( ( F_3 ( V_5 ) & ~ ( V_4 ) ) , V_5 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_7 )
{
void T_2 * V_5 = V_2 -> V_6 + V_3 ;
F_2 ( ( F_3 ( V_5 ) & ~ V_7 ) | V_4 , V_5 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_6 + V_3 ) ;
}
static inline T_1 F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
return ( T_1 ) F_3 ( V_2 -> V_6 + V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_4 )
{
int V_9 = 0 ;
F_1 ( V_2 , V_8 , V_4 ) ;
for ( V_9 = 0 ; V_9 < 1000 ; V_9 ++ ) {
if ( ( F_7 ( V_2 , V_8 ) & V_4 ) == V_4 )
break;
}
if ( V_9 == 1000 && ( ( F_7 ( V_2 , V_8 ) & V_4 ) != V_4 ) )
F_9 ( V_10 L_1 ) ;
}
static bool F_10 ( struct V_1 * V_2 )
{
T_1 V_11 = F_7 ( V_2 , V_12 ) ;
T_1 V_13 = F_7 ( V_2 , V_14 ) ;
return ! ( V_13 & V_15 ) && V_11 & V_16 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_17 , V_18 ) ;
F_8 ( V_2 , V_17 , V_19 ) ;
if ( F_10 ( V_2 ) ) {
F_8 ( V_2 , V_20 , V_21 ) ;
F_8 ( V_2 , V_20 , V_22 ) ;
}
F_8 ( V_2 , V_17 , V_23 ) ;
F_6 ( V_2 , V_24 , 0 ) ;
F_8 ( V_2 , V_17 , V_25 ) ;
F_8 ( V_2 , V_17 , V_26 ) ;
F_6 ( V_2 , V_24 , 0 ) ;
F_8 ( V_2 , V_17 , V_25 ) ;
F_8 ( V_2 , V_17 , V_26 ) ;
if ( F_10 ( V_2 ) )
F_8 ( V_2 , V_20 , V_27 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_3 V_3 = 0 , V_9 ;
T_1 V_28 ;
F_8 ( V_2 , V_20 , V_21 ) ;
F_8 ( V_2 , V_20 , V_22 ) ;
F_8 ( V_2 , V_20 , V_29 ) ;
F_6 ( V_2 , V_30 , 0 ) ;
F_8 ( V_2 , V_20 , V_31 ) ;
F_8 ( V_2 , V_20 , V_27 ) ;
F_6 ( V_2 , V_30 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_32 ; V_9 ++ ) {
if ( V_2 -> V_33 [ V_9 ] == V_34 ) {
V_3 = V_9 ;
break;
}
}
V_28 = 0 ;
while ( ! ( F_7 ( V_2 , F_13 ( V_3 ) ) &
V_35 ) && ( V_28 < 100000 ) )
V_28 ++ ;
F_6 ( V_2 , V_30 , 0 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_36 )
{
T_1 V_5 ;
V_2 -> V_37 ++ ;
if ( V_36 == V_38 ) {
if ( V_2 -> V_39 ) {
V_5 = V_2 -> V_40 + V_41 ;
F_4 ( V_2 , V_5 , V_42 ) ;
F_1 ( V_2 , V_5 , V_42 ) ;
}
F_12 ( V_2 ) ;
} else {
if ( V_2 -> V_43 ) {
V_5 = V_2 -> V_40 + V_44 ;
F_4 ( V_2 , V_5 , V_42 ) ;
F_1 ( V_2 , V_5 , V_42 ) ;
}
F_11 ( V_2 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
if ( F_10 ( V_2 ) && ! V_2 -> V_37 )
F_6 ( V_2 , V_20 , 0 ) ;
F_6 ( V_2 , V_17 , 0 ) ;
F_6 ( V_2 , V_45 , 0xFFFFFFFF ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_4 = 0 ;
if ( F_10 ( V_2 ) && V_2 -> V_37 )
V_4 = V_21 | V_22 | V_27 ;
F_6 ( V_2 , V_20 , V_4 ) ;
F_6 ( V_2 , V_46 , 0xFFFFFFFF ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_36 )
{
T_1 V_5 ;
V_2 -> V_37 -- ;
if ( V_36 == V_38 ) {
if ( V_2 -> V_39 ) {
V_5 = V_2 -> V_40 + V_41 ;
F_4 ( V_2 , V_5 , V_42 ) ;
}
F_16 ( V_2 ) ;
} else {
if ( V_2 -> V_43 ) {
V_5 = V_2 -> V_40 + V_44 ;
F_4 ( V_2 , V_5 , V_42 ) ;
}
F_15 ( V_2 ) ;
}
}
static int F_18 ( struct V_47 * V_48 ,
unsigned int V_49 )
{
struct V_1 * V_2 = F_19 ( V_48 ) ;
int V_50 = 0 ;
T_1 V_51 ;
bool V_52 ;
bool V_53 = false ;
F_20 ( V_2 -> V_54 ) ;
switch ( V_49 & V_55 ) {
case V_56 :
F_4 ( V_2 , V_57 , V_58 ) ;
F_4 ( V_2 , V_12 , V_59 ) ;
V_51 = 1 ;
break;
case V_60 :
case V_61 :
F_4 ( V_2 , V_57 , V_58 ) ;
F_4 ( V_2 , V_12 , V_59 ) ;
V_51 = 0 ;
break;
case V_62 :
F_1 ( V_2 , V_57 , V_58 ) ;
F_1 ( V_2 , V_12 , V_59 ) ;
V_51 = 1 ;
V_53 = true ;
break;
case V_63 :
F_1 ( V_2 , V_57 , V_58 ) ;
F_1 ( V_2 , V_12 , V_59 ) ;
V_51 = 0 ;
break;
default:
V_50 = - V_64 ;
goto V_65;
}
F_5 ( V_2 , V_66 , F_21 ( V_51 ) ,
F_21 ( 3 ) ) ;
F_5 ( V_2 , V_67 , F_22 ( V_51 ) ,
F_22 ( 3 ) ) ;
switch ( V_49 & V_68 ) {
case V_69 :
F_1 ( V_2 , V_14 , V_70 ) ;
F_1 ( V_2 , V_57 , V_71 ) ;
F_1 ( V_2 , V_72 , V_73 ) ;
F_1 ( V_2 , V_12 , V_16 ) ;
F_1 ( V_2 , V_74 , V_75 | V_76 ) ;
F_1 ( V_2 , V_74 , V_77 | V_78 ) ;
V_2 -> V_79 = 1 ;
break;
case V_80 :
F_4 ( V_2 , V_14 , V_70 ) ;
F_1 ( V_2 , V_57 , V_71 ) ;
F_4 ( V_2 , V_72 , V_73 ) ;
F_1 ( V_2 , V_12 , V_16 ) ;
F_4 ( V_2 , V_74 , V_75 | V_76 ) ;
F_1 ( V_2 , V_74 , V_77 | V_78 ) ;
V_2 -> V_79 = 0 ;
break;
case V_81 :
F_4 ( V_2 , V_14 , V_70 ) ;
F_4 ( V_2 , V_57 , V_71 ) ;
F_4 ( V_2 , V_72 , V_73 ) ;
F_4 ( V_2 , V_12 , V_16 ) ;
F_4 ( V_2 , V_74 ,
V_75 | V_82 | V_77 | V_76 | V_83 | V_78 ) ;
V_2 -> V_79 = 0 ;
break;
default:
V_50 = - V_64 ;
goto V_65;
}
switch ( V_49 & V_84 ) {
case V_85 :
F_4 ( V_2 , V_14 , V_86 ) ;
F_4 ( V_2 , V_72 , V_87 ) ;
V_52 = true ;
break;
case V_88 :
F_1 ( V_2 , V_14 , V_86 ) ;
F_1 ( V_2 , V_72 , V_87 ) ;
V_52 = false ;
break;
case V_89 :
F_4 ( V_2 , V_14 , V_86 ) ;
F_4 ( V_2 , V_72 , V_87 ) ;
V_52 = false ;
break;
case V_90 :
F_1 ( V_2 , V_14 , V_86 ) ;
F_1 ( V_2 , V_72 , V_87 ) ;
V_52 = true ;
break;
default:
V_50 = - V_64 ;
goto V_65;
}
if ( V_53 )
V_52 = ! V_52 ;
if ( V_52 ) {
F_4 ( V_2 , V_57 , V_91 ) ;
F_4 ( V_2 , V_12 , V_92 ) ;
} else {
F_1 ( V_2 , V_57 , V_91 ) ;
F_1 ( V_2 , V_12 , V_92 ) ;
}
V_65:
F_23 ( V_2 -> V_54 ) ;
return V_50 ;
}
static int F_24 ( struct V_47 * V_93 , int V_94 ,
int div , bool V_95 )
{
struct V_1 * V_2 = F_19 ( V_93 ) ;
switch ( V_94 ) {
case 0 :
F_5 ( V_2 , V_96 ,
F_25 ( div - 1 ) , V_97 ) ;
F_5 ( V_2 , V_98 ,
F_26 ( div - 1 ) , V_99 ) ;
break;
case 1 :
F_5 ( V_2 , V_14 ,
F_27 ( div - 1 ) , V_100 ) ;
F_5 ( V_2 , V_72 ,
F_28 ( div - 1 ) , V_101 ) ;
if ( V_95 )
V_2 -> V_102 = div ;
break;
case 2 :
V_2 -> V_103 = div ;
break;
default:
return - V_64 ;
}
return 0 ;
}
static int F_29 ( struct V_47 * V_93 , int V_94 ,
int div )
{
return F_24 ( V_93 , V_94 , div , 1 ) ;
}
static int F_30 ( struct V_47 * V_93 , int V_104 ,
unsigned int V_105 , int V_106 )
{
struct V_1 * V_2 = F_19 ( V_93 ) ;
if ( V_106 == V_107 ) {
F_1 ( V_2 , V_96 , V_108 ) ;
F_1 ( V_2 , V_98 , V_109 ) ;
F_1 ( V_2 , V_74 , V_82 ) ;
} else {
F_4 ( V_2 , V_96 , V_108 ) ;
F_4 ( V_2 , V_98 , V_109 ) ;
F_4 ( V_2 , V_74 , V_82 ) ;
}
V_2 -> V_110 = V_105 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
int V_111 )
{
T_1 V_49 ;
T_1 V_112 = ( V_111 / 4 ) & 0x7 ;
T_1 V_7 = ( 1ULL << V_111 ) - 1 ;
T_1 V_113 = 0 ;
if ( V_2 -> V_103 )
V_111 = V_2 -> V_103 / V_2 -> V_114 ;
V_49 = ( V_111 >> 1 ) - 1 ;
if ( V_2 -> V_115 != V_116 ) {
F_5 ( V_2 , V_67 , F_32 ( V_49 ) ,
F_32 ( 0x0F ) ) ;
F_5 ( V_2 , V_66 , F_33 ( V_49 ) ,
F_33 ( 0x0F ) ) ;
F_5 ( V_2 , V_66 , F_34 ( V_112 ) ,
F_34 ( 7 ) ) ;
F_5 ( V_2 , V_67 , F_35 ( V_113 ) ,
F_35 ( 7 ) ) ;
F_6 ( V_2 , V_117 , V_7 ) ;
}
F_6 ( V_2 , V_118 , V_7 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , int V_36 ,
int V_119 , int V_120 )
{
struct V_121 * V_122 = & V_2 -> V_122 [ V_36 ] ;
struct V_123 * V_124 = & V_2 -> V_124 [ V_36 ] ;
int V_9 ;
T_3 V_125 = 0 ;
T_3 V_126 = 0 ;
T_3 V_127 = V_2 -> V_114 ;
T_3 V_128 = ( V_120 + V_127 - 1 ) / V_127 ;
int V_129 , V_130 , V_131 ;
T_1 V_5 ;
if ( V_2 -> V_132 < V_133 )
F_1 ( V_2 , V_134 , V_135 ) ;
F_6 ( V_2 , V_136 , 0x00000000 ) ;
if ( V_36 == V_38 ) {
F_6 ( V_2 , V_46 , 0xFFFFFFFF ) ;
F_4 ( V_2 , V_137 , V_138 ) ;
} else {
F_6 ( V_2 , V_45 , 0xFFFFFFFF ) ;
F_4 ( V_2 , V_139 , V_140 ) ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_32 ; V_9 ++ ) {
F_1 ( V_2 , F_13 ( V_9 ) ,
V_2 -> V_33 [ V_9 ] ) ;
if ( V_2 -> V_33 [ V_9 ] == V_34 &&
V_125 < V_128 ) {
F_1 ( V_2 , V_74 , F_37 ( V_9 ) ) ;
V_125 ++ ;
} else if ( V_2 -> V_33 [ V_9 ] == V_141 &&
V_126 < V_128 ) {
F_4 ( V_2 , V_74 , F_37 ( V_9 ) ) ;
V_126 ++ ;
} else {
F_5 ( V_2 , F_13 ( V_9 ) ,
V_142 , V_143 ) ;
}
}
if ( V_36 == V_38 ) {
V_129 = V_125 ;
V_130 = V_2 -> V_39 ;
V_5 = V_2 -> V_40 + V_41 ;
} else {
V_129 = V_126 ;
V_130 = V_2 -> V_43 ;
V_5 = V_2 -> V_40 + V_44 ;
}
if ( V_129 < V_128 ) {
F_38 ( V_2 -> V_54 , L_2
L_3 , V_120 ,
V_129 * V_127 ) ;
return - V_64 ;
}
if ( ! V_130 ) {
if ( V_129 > 1 ) {
V_122 -> V_144 = V_129 ;
V_124 -> V_145 = V_129 ;
} else {
V_122 -> V_144 = 0 ;
V_124 -> V_145 = 0 ;
}
return 0 ;
}
if ( V_119 % V_129 ) {
F_39 ( V_2 -> V_54 , L_4
L_5 , V_119 ,
V_129 ) ;
return - V_64 ;
}
V_131 = V_130 % V_129 ;
if ( V_131 )
V_130 += ( V_129 - V_131 ) ;
while ( V_119 % V_130 && V_130 > 0 )
V_130 -= V_129 ;
if ( V_130 <= 0 )
V_130 = V_129 ;
F_5 ( V_2 , V_5 , V_129 , V_146 ) ;
F_5 ( V_2 , V_5 , F_40 ( V_130 ) , V_147 ) ;
if ( V_130 == 1 )
V_130 = 0 ;
V_122 -> V_144 = V_130 ;
V_124 -> V_145 = V_130 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , int V_36 )
{
int V_9 , V_148 ;
T_1 V_7 = 0 ;
T_1 V_149 = 0 ;
if ( ( V_2 -> V_114 < 2 ) || ( V_2 -> V_114 > 32 ) ) {
F_39 ( V_2 -> V_54 , L_6 ,
V_2 -> V_114 ) ;
return - V_64 ;
}
V_148 = ( V_2 -> V_114 > 31 ) ? 32 : V_2 -> V_114 ;
for ( V_9 = 0 ; V_9 < V_148 ; V_9 ++ )
V_7 |= ( 1 << V_9 ) ;
F_4 ( V_2 , V_14 , V_15 ) ;
if ( ! V_2 -> V_150 )
V_149 = V_151 ;
F_6 ( V_2 , V_152 , V_7 ) ;
F_1 ( V_2 , V_66 , V_149 | V_153 ) ;
F_5 ( V_2 , V_57 ,
F_42 ( V_2 -> V_114 ) , F_42 ( 0x1FF ) ) ;
F_6 ( V_2 , V_154 , V_7 ) ;
F_1 ( V_2 , V_67 , V_149 | V_155 ) ;
F_5 ( V_2 , V_12 ,
F_43 ( V_2 -> V_114 ) , F_43 ( 0x1FF ) ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
unsigned int V_156 )
{
T_1 V_157 = 0 ;
T_3 * V_158 = ( T_3 * ) & V_157 ;
F_1 ( V_2 , V_66 , F_34 ( 6 ) | F_33 ( 15 ) ) ;
F_6 ( V_2 , V_57 , V_71 | F_42 ( 0x180 ) ) ;
F_6 ( V_2 , V_152 , 0xFFFFFFFF ) ;
F_1 ( V_2 , V_14 , V_70 | V_15 ) ;
F_4 ( V_2 , V_137 , V_138 ) ;
F_1 ( V_2 , V_96 , F_25 ( 3 ) ) ;
F_1 ( V_2 , V_159 , V_160 ) ;
V_158 [ 0 ] = V_161 ;
V_158 [ 1 ] = V_162 ;
switch ( V_156 ) {
case 22050 :
V_158 [ 3 ] |= V_163 ;
break;
case 24000 :
V_158 [ 3 ] |= V_164 ;
break;
case 32000 :
V_158 [ 3 ] |= V_165 ;
break;
case 44100 :
V_158 [ 3 ] |= V_166 ;
break;
case 48000 :
V_158 [ 3 ] |= V_167 ;
break;
case 88200 :
V_158 [ 3 ] |= V_168 ;
break;
case 96000 :
V_158 [ 3 ] |= V_169 ;
break;
case 176400 :
V_158 [ 3 ] |= V_170 ;
break;
case 192000 :
V_158 [ 3 ] |= V_171 ;
break;
default:
F_9 ( V_172 L_7 , V_156 ) ;
return - V_64 ;
}
F_6 ( V_2 , V_173 , V_157 ) ;
F_6 ( V_2 , V_174 , V_157 ) ;
return 0 ;
}
static int F_45 ( struct V_175 * V_176 ,
struct V_177 * V_178 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_19 ( V_48 ) ;
struct V_121 * V_122 =
& V_2 -> V_122 [ V_176 -> V_36 ] ;
int V_111 ;
int V_120 = F_46 ( V_178 ) ;
int V_179 = F_47 ( V_178 ) ;
int V_50 ;
if ( V_2 -> V_79 && V_2 -> V_102 == 0 && V_2 -> V_110 ) {
unsigned int V_180 = F_48 ( V_178 ) ;
unsigned int div = V_2 -> V_110 / V_180 ;
if ( V_2 -> V_110 % V_180 != 0 ) {
if ( ( ( V_2 -> V_110 / div ) - V_180 ) >
( V_180 - ( V_2 -> V_110 / ( div + 1 ) ) ) )
div ++ ;
F_38 ( V_2 -> V_54 ,
L_8 ,
V_2 -> V_110 , div , V_180 ) ;
}
F_24 ( V_48 , 1 , div , 0 ) ;
}
V_50 = F_36 ( V_2 , V_176 -> V_36 ,
V_179 * V_120 , V_120 ) ;
if ( V_50 )
return V_50 ;
if ( V_2 -> V_115 == V_116 )
V_50 = F_44 ( V_2 , F_49 ( V_178 ) ) ;
else
V_50 = F_41 ( V_2 , V_176 -> V_36 ) ;
if ( V_50 )
return V_50 ;
switch ( F_50 ( V_178 ) ) {
case V_181 :
case V_182 :
V_122 -> V_183 = 1 ;
V_111 = 8 ;
break;
case V_184 :
case V_185 :
V_122 -> V_183 = 2 ;
V_111 = 16 ;
break;
case V_186 :
case V_187 :
V_122 -> V_183 = 3 ;
V_111 = 24 ;
break;
case V_188 :
case V_189 :
V_122 -> V_183 = 4 ;
V_111 = 24 ;
break;
case V_190 :
case V_191 :
V_122 -> V_183 = 4 ;
V_111 = 32 ;
break;
default:
F_9 ( V_172 L_9 ) ;
return - V_64 ;
}
if ( V_2 -> V_132 == V_192 && ! V_122 -> V_144 )
V_122 -> V_193 = 4 ;
else
V_122 -> V_193 = V_122 -> V_183 ;
F_31 ( V_2 , V_111 ) ;
return 0 ;
}
static int F_51 ( struct V_175 * V_176 ,
int V_194 , struct V_47 * V_48 )
{
struct V_1 * V_2 = F_19 ( V_48 ) ;
int V_50 = 0 ;
switch ( V_194 ) {
case V_195 :
case V_196 :
case V_197 :
F_14 ( V_2 , V_176 -> V_36 ) ;
break;
case V_198 :
case V_199 :
case V_200 :
F_17 ( V_2 , V_176 -> V_36 ) ;
break;
default:
V_50 = - V_64 ;
}
return V_50 ;
}
static int F_52 ( struct V_47 * V_93 )
{
struct V_1 * V_2 = F_19 ( V_93 ) ;
if ( V_2 -> V_132 >= V_133 ) {
V_93 -> V_201 =
& V_2 -> V_124 [ V_38 ] ;
V_93 -> V_202 =
& V_2 -> V_124 [ V_203 ] ;
} else {
V_93 -> V_201 = V_2 -> V_122 ;
V_93 -> V_202 = V_2 -> V_122 ;
}
return 0 ;
}
static int F_53 ( struct V_47 * V_93 )
{
struct V_1 * V_2 = F_19 ( V_93 ) ;
struct V_204 * V_205 = & V_2 -> V_205 ;
V_205 -> V_206 = F_7 ( V_2 , V_57 ) ;
V_205 -> V_207 = F_7 ( V_2 , V_12 ) ;
V_205 -> V_208 = F_7 ( V_2 , V_66 ) ;
V_205 -> V_209 = F_7 ( V_2 , V_67 ) ;
V_205 -> V_13 = F_7 ( V_2 , V_14 ) ;
V_205 -> V_210 = F_7 ( V_2 , V_72 ) ;
V_205 -> V_211 = F_7 ( V_2 , V_74 ) ;
return 0 ;
}
static int F_54 ( struct V_47 * V_93 )
{
struct V_1 * V_2 = F_19 ( V_93 ) ;
struct V_204 * V_205 = & V_2 -> V_205 ;
F_6 ( V_2 , V_57 , V_205 -> V_206 ) ;
F_6 ( V_2 , V_12 , V_205 -> V_207 ) ;
F_6 ( V_2 , V_66 , V_205 -> V_208 ) ;
F_6 ( V_2 , V_67 , V_205 -> V_209 ) ;
F_6 ( V_2 , V_14 , V_205 -> V_13 ) ;
F_6 ( V_2 , V_72 , V_205 -> V_210 ) ;
F_6 ( V_2 , V_74 , V_205 -> V_211 ) ;
return 0 ;
}
static int F_55 ( struct V_212 * V_213 )
{
struct V_214 * V_215 = V_213 -> V_54 . V_216 ;
struct V_217 * V_218 , * V_219 ;
const char * V_220 ;
int V_50 ;
if ( ! V_215 )
return 0 ;
V_220 = F_56 ( V_215 , L_10 , NULL ) ;
if ( ! V_220 )
return 0 ;
V_218 = F_57 ( & V_213 -> V_54 , L_11 ) ;
if ( F_58 ( V_218 ) ) {
F_39 ( & V_213 -> V_54 , L_12 ) ;
return F_59 ( V_218 ) ;
}
V_219 = F_57 ( NULL , V_220 ) ;
if ( F_58 ( V_219 ) ) {
F_39 ( & V_213 -> V_54 , L_13 ) ;
V_50 = F_59 ( V_219 ) ;
goto V_221;
}
V_50 = F_60 ( V_218 , V_219 ) ;
if ( V_50 ) {
F_39 ( & V_213 -> V_54 , L_14 ) ;
goto V_222;
}
V_222:
F_61 ( V_219 ) ;
V_221:
F_61 ( V_218 ) ;
return V_50 ;
}
static struct V_223 * F_62 (
struct V_212 * V_213 )
{
struct V_214 * V_224 = V_213 -> V_54 . V_216 ;
struct V_223 * V_225 = NULL ;
const struct V_226 * V_227 =
F_63 ( V_228 , & V_213 -> V_54 ) ;
struct V_229 V_230 ;
const T_1 * V_231 ;
T_1 V_4 ;
int V_9 , V_50 = 0 ;
if ( V_213 -> V_54 . V_232 ) {
V_225 = V_213 -> V_54 . V_232 ;
return V_225 ;
} else if ( V_227 ) {
V_225 = (struct V_223 * ) V_227 -> V_233 ;
} else {
V_50 = - V_64 ;
goto V_234;
}
V_50 = F_64 ( V_224 , L_15 , & V_4 ) ;
if ( V_50 >= 0 )
V_225 -> V_115 = V_4 ;
V_50 = F_64 ( V_224 , L_16 , & V_4 ) ;
if ( V_50 >= 0 ) {
if ( V_4 < 2 || V_4 > 32 ) {
F_39 ( & V_213 -> V_54 ,
L_17 ) ;
V_50 = - V_64 ;
goto V_234;
}
V_225 -> V_114 = V_4 ;
}
V_231 = F_56 ( V_224 , L_18 , & V_4 ) ;
V_4 /= sizeof( T_1 ) ;
if ( V_231 ) {
T_3 * V_235 = F_65 ( & V_213 -> V_54 ,
( sizeof( * V_235 ) * V_4 ) ,
V_236 ) ;
if ( ! V_235 ) {
V_50 = - V_237 ;
goto V_234;
}
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ )
V_235 [ V_9 ] = F_66 ( & V_231 [ V_9 ] ) ;
V_225 -> V_32 = V_4 ;
V_225 -> V_33 = V_235 ;
}
V_50 = F_67 ( V_224 , L_19 , L_20 ) ;
if ( V_50 < 0 )
goto V_234;
V_50 = F_68 ( V_224 , L_21 , L_22 , V_50 ,
& V_230 ) ;
if ( V_50 < 0 )
goto V_234;
V_225 -> V_238 = V_230 . args [ 0 ] ;
V_50 = F_67 ( V_224 , L_19 , L_23 ) ;
if ( V_50 < 0 )
goto V_234;
V_50 = F_68 ( V_224 , L_21 , L_22 , V_50 ,
& V_230 ) ;
if ( V_50 < 0 )
goto V_234;
V_225 -> V_239 = V_230 . args [ 0 ] ;
V_50 = F_64 ( V_224 , L_24 , & V_4 ) ;
if ( V_50 >= 0 )
V_225 -> V_39 = V_4 ;
V_50 = F_64 ( V_224 , L_25 , & V_4 ) ;
if ( V_50 >= 0 )
V_225 -> V_43 = V_4 ;
V_50 = F_64 ( V_224 , L_26 , & V_4 ) ;
if ( V_50 >= 0 )
V_225 -> V_240 = V_4 ;
V_50 = F_64 ( V_224 , L_27 , & V_4 ) ;
if ( V_50 >= 0 )
V_225 -> V_241 = V_4 ;
return V_225 ;
V_234:
if ( V_50 < 0 ) {
F_39 ( & V_213 -> V_54 , L_28 ,
V_50 ) ;
V_225 = NULL ;
}
return V_225 ;
}
static int F_69 ( struct V_212 * V_213 )
{
struct V_121 * V_122 ;
struct V_123 * V_124 ;
struct V_242 * V_243 , * V_244 , * V_245 , * V_246 ;
struct V_223 * V_225 ;
struct V_1 * V_2 ;
int V_50 ;
if ( ! V_213 -> V_54 . V_232 && ! V_213 -> V_54 . V_216 ) {
F_39 ( & V_213 -> V_54 , L_29 ) ;
return - V_64 ;
}
V_2 = F_65 ( & V_213 -> V_54 , sizeof( struct V_1 ) ,
V_236 ) ;
if ( ! V_2 )
return - V_237 ;
V_225 = F_62 ( V_213 ) ;
if ( ! V_225 ) {
F_39 ( & V_213 -> V_54 , L_30 ) ;
return - V_64 ;
}
V_243 = F_70 ( V_213 , V_247 , L_31 ) ;
if ( ! V_243 ) {
F_38 ( V_2 -> V_54 ,
L_32 ) ;
V_243 = F_71 ( V_213 , V_247 , 0 ) ;
if ( ! V_243 ) {
F_39 ( & V_213 -> V_54 , L_33 ) ;
return - V_248 ;
}
}
V_244 = F_72 ( & V_213 -> V_54 , V_243 -> V_249 ,
F_73 ( V_243 ) , V_213 -> V_250 ) ;
if ( ! V_244 ) {
F_39 ( & V_213 -> V_54 , L_34 ) ;
return - V_251 ;
}
F_74 ( & V_213 -> V_54 ) ;
V_50 = F_20 ( & V_213 -> V_54 ) ;
if ( F_75 ( V_50 ) ) {
F_39 ( & V_213 -> V_54 , L_35 ) ;
return V_50 ;
}
V_2 -> V_6 = F_76 ( & V_213 -> V_54 , V_243 -> V_249 , F_73 ( V_243 ) ) ;
if ( ! V_2 -> V_6 ) {
F_39 ( & V_213 -> V_54 , L_36 ) ;
V_50 = - V_237 ;
goto V_252;
}
V_2 -> V_115 = V_225 -> V_115 ;
V_2 -> V_114 = V_225 -> V_114 ;
V_2 -> V_32 = V_225 -> V_32 ;
V_2 -> V_33 = V_225 -> V_33 ;
V_2 -> V_132 = V_225 -> V_132 ;
V_2 -> V_39 = V_225 -> V_39 ;
V_2 -> V_43 = V_225 -> V_43 ;
V_2 -> V_54 = & V_213 -> V_54 ;
V_246 = F_70 ( V_213 , V_247 , L_37 ) ;
if ( V_246 )
V_2 -> V_150 = true ;
V_122 = & V_2 -> V_122 [ V_38 ] ;
V_124 = & V_2 -> V_124 [ V_38 ] ;
V_122 -> V_253 = V_225 -> V_253 ;
V_122 -> V_254 = V_225 -> V_254 ;
V_122 -> V_255 = V_225 -> V_255 ;
V_122 -> V_256 = V_225 -> V_240 ;
if ( V_246 )
V_122 -> V_257 = V_246 -> V_249 ;
else
V_122 -> V_257 = V_243 -> V_249 + V_225 -> V_258 ;
V_124 -> V_259 = V_122 -> V_257 ;
V_245 = F_71 ( V_213 , V_260 , 0 ) ;
if ( V_245 )
V_122 -> V_261 = V_245 -> V_249 ;
else
V_122 -> V_261 = V_225 -> V_238 ;
if ( V_213 -> V_54 . V_216 )
V_124 -> V_262 = L_20 ;
else
V_124 -> V_262 = & V_122 -> V_261 ;
V_122 = & V_2 -> V_122 [ V_203 ] ;
V_124 = & V_2 -> V_124 [ V_203 ] ;
V_122 -> V_253 = V_225 -> V_253 ;
V_122 -> V_254 = V_225 -> V_254 ;
V_122 -> V_255 = V_225 -> V_255 ;
V_122 -> V_256 = V_225 -> V_241 ;
if ( V_246 )
V_122 -> V_257 = V_246 -> V_249 ;
else
V_122 -> V_257 = V_243 -> V_249 + V_225 -> V_263 ;
V_124 -> V_259 = V_122 -> V_257 ;
if ( V_2 -> V_132 < V_133 ) {
V_2 -> V_40 = V_264 ;
V_2 -> V_150 = true ;
} else {
V_2 -> V_40 = V_265 ;
}
V_245 = F_71 ( V_213 , V_260 , 1 ) ;
if ( V_245 )
V_122 -> V_261 = V_245 -> V_249 ;
else
V_122 -> V_261 = V_225 -> V_239 ;
if ( V_213 -> V_54 . V_216 )
V_124 -> V_262 = L_23 ;
else
V_124 -> V_262 = & V_122 -> V_261 ;
F_77 ( & V_213 -> V_54 , V_2 ) ;
F_55 ( V_213 ) ;
V_50 = F_78 ( & V_213 -> V_54 ,
& V_266 ,
& V_267 [ V_225 -> V_115 ] , 1 ) ;
if ( V_50 != 0 )
goto V_252;
switch ( V_2 -> V_132 ) {
#if F_79 ( V_268 ) || \
( F_80 ( V_269 ) && \
F_80 ( V_268 ) )
case V_270 :
case V_192 :
V_50 = F_81 ( & V_213 -> V_54 ) ;
break;
#endif
#if F_79 ( V_271 ) || \
( F_80 ( V_269 ) && \
F_80 ( V_271 ) )
case V_133 :
V_50 = F_82 ( & V_213 -> V_54 ) ;
break;
#endif
#if F_79 ( V_272 ) || \
( F_80 ( V_269 ) && \
F_80 ( V_272 ) )
case V_273 :
V_50 = F_83 ( & V_213 -> V_54 ) ;
break;
#endif
default:
F_39 ( & V_213 -> V_54 , L_38 ,
V_2 -> V_132 ) ;
V_50 = - V_64 ;
break;
}
if ( V_50 ) {
F_39 ( & V_213 -> V_54 , L_39 , V_50 ) ;
goto V_252;
}
return 0 ;
V_252:
F_23 ( & V_213 -> V_54 ) ;
F_84 ( & V_213 -> V_54 ) ;
return V_50 ;
}
static int F_85 ( struct V_212 * V_213 )
{
F_23 ( & V_213 -> V_54 ) ;
F_84 ( & V_213 -> V_54 ) ;
return 0 ;
}

static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_7 = V_2 -> V_8 + V_9 ;
F_2 ( V_7 , 0 , 2 , V_10 | V_11 ) ;
F_2 ( V_7 , 0 , 1 , V_10 | V_11 ) ;
F_3 ( 1 ) ;
if ( V_3 ) {
F_4 ( V_7 , 0 , 2 , V_5 -> V_12 ) ;
F_4 ( V_7 , 0 , 1 , V_5 -> V_13 ) ;
}
}
static void F_5 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned int V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_5 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_20 [ V_18 -> V_21 ] ;
unsigned int V_22 ;
unsigned int V_23 ;
unsigned int V_24 ;
F_6 ( V_18 -> V_25 ) ;
V_22 = V_5 -> V_26 ? F_7 ( V_15 ) : V_20 -> V_27 ;
V_23 = F_8 ( V_15 , V_22 ) ;
V_24 = F_9 ( V_15 , V_23 + V_16 ) ;
if ( V_24 > V_16 ) {
V_24 -= V_16 ;
V_20 -> V_28 = F_10 ( V_15 , V_24 ) ;
F_11 ( V_20 ) ;
}
}
static void F_12 ( struct V_1 * V_2 ,
unsigned int V_29 , char V_30 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_25 = F_13 ( V_29 ) ;
unsigned int V_31 = F_14 ( V_29 ) ;
unsigned int V_32 = 0 ;
if ( V_29 == V_5 -> V_33 )
return;
V_5 -> V_33 = V_29 ;
if ( V_5 -> V_34 ) {
if ( V_5 -> V_35 ) {
V_32 |= V_36 | V_37 ;
} else {
if ( V_25 < 8 )
V_32 |= V_36 ;
else
V_32 |= V_37 ;
}
}
F_15 ( V_32 | F_16 ( V_25 ) , V_2 -> V_8 + V_38 ) ;
F_15 ( V_31 + V_5 -> V_39 , V_2 -> V_8 + V_40 ) ;
if ( V_30 )
F_3 ( V_5 -> V_41 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_15 ( 0 , V_2 -> V_8 + V_42 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_15 ( 255 , V_2 -> V_8 + V_43 ) ;
}
static unsigned int F_19 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
unsigned int V_44 ;
V_44 = F_20 ( V_2 -> V_8 + V_45 ) << 8 ;
V_44 |= F_20 ( V_2 -> V_8 + V_46 ) ;
return V_44 & V_15 -> V_47 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_48 * V_49 ,
unsigned long V_50 )
{
unsigned int V_51 ;
if ( V_15 -> V_47 > 0x0fff ) {
V_51 = F_20 ( V_2 -> V_8 + V_42 ) ;
if ( ( V_51 & V_52 ) == 0 )
return 0 ;
} else {
V_51 = F_20 ( V_2 -> V_8 + V_45 ) ;
if ( ( V_51 & V_53 ) == 0 )
return 0 ;
}
return - V_54 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_14 * V_15 , struct V_55 * V_56 )
{
const struct V_57 * V_58 = V_2 -> V_59 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_60 = 0 ;
unsigned int V_61 ;
unsigned int V_62 ;
V_60 |= F_23 ( & V_56 -> V_63 , V_64 ) ;
V_60 |= F_23 ( & V_56 -> V_65 , V_66 ) ;
if ( V_5 -> V_67 )
V_61 = V_68 ;
else
V_61 = V_69 ;
V_60 |= F_23 ( & V_56 -> V_70 , V_61 ) ;
V_60 |= F_23 ( & V_56 -> V_71 , V_72 ) ;
V_60 |= F_23 ( & V_56 -> V_73 , V_72 | V_74 ) ;
if ( V_60 )
return 1 ;
V_60 |= F_24 ( V_56 -> V_73 ) ;
if ( V_60 )
return 2 ;
V_60 |= F_25 ( & V_56 -> V_75 , 0 ) ;
V_60 |= F_25 ( & V_56 -> V_76 , 0 ) ;
if ( V_56 -> V_70 == V_69 )
V_60 |= F_26 ( & V_56 -> V_77 ,
V_58 -> V_78 ) ;
else
V_60 |= F_25 ( & V_56 -> V_77 , 0 ) ;
V_60 |= F_26 ( & V_56 -> V_79 , 1 ) ;
V_60 |= F_25 ( & V_56 -> V_80 , V_56 -> V_79 ) ;
if ( V_56 -> V_73 == V_72 )
V_60 |= F_26 ( & V_56 -> V_81 , 1 ) ;
else
V_60 |= F_25 ( & V_56 -> V_81 , 0 ) ;
if ( V_60 )
return 3 ;
if ( V_56 -> V_70 == V_69 ) {
V_62 = V_56 -> V_77 ;
F_27 ( V_82 ,
& V_5 -> V_13 ,
& V_5 -> V_12 ,
& V_62 , V_56 -> V_61 ) ;
V_60 |= F_25 ( & V_56 -> V_77 , V_62 ) ;
}
if ( V_60 )
return 4 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_5 -> V_18 ;
struct V_55 * V_56 = & V_15 -> V_83 -> V_56 ;
unsigned int V_84 = 0 ;
unsigned int V_85 ;
F_1 ( V_2 , false ) ;
F_12 ( V_2 , V_56 -> V_86 [ 0 ] , 1 ) ;
if ( V_18 ) {
V_5 -> V_87 = 1 ;
for ( V_85 = 1 ; V_85 < V_56 -> V_79 ; V_85 ++ )
if ( V_56 -> V_86 [ 0 ] != V_56 -> V_86 [ V_85 ] ) {
V_5 -> V_87 = 0 ;
break;
}
} else {
V_5 -> V_87 = 0 ;
}
V_5 -> V_88 = 0 ;
if ( V_56 -> V_61 & V_89 ) {
V_5 -> V_26 = 1 ;
if ( V_56 -> V_79 == 1 )
V_5 -> V_87 = 0 ;
}
if ( V_5 -> V_87 ) {
V_18 -> V_21 = 0 ;
F_5 ( V_2 , V_15 , 0 ) ;
}
switch ( V_56 -> V_70 ) {
case V_69 :
F_1 ( V_2 , true ) ;
break;
}
if ( V_5 -> V_87 )
V_84 |= V_90 ;
else
V_84 |= V_91 ;
F_15 ( V_5 -> V_92 | V_84 , V_2 -> V_8 + V_93 ) ;
return 0 ;
}
static bool F_29 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_55 * V_56 = & V_15 -> V_83 -> V_56 ;
if ( V_56 -> V_73 == V_72 &&
V_15 -> V_83 -> V_94 >= V_56 -> V_81 ) {
V_15 -> V_83 -> V_95 |= V_96 ;
return false ;
}
return true ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_55 * V_56 = & V_15 -> V_83 -> V_56 ;
unsigned int V_25 = V_15 -> V_83 -> V_97 ;
unsigned int V_98 ;
unsigned short V_44 ;
if ( F_21 ( V_2 , V_15 , NULL , 0 ) ) {
F_31 ( V_2 -> V_99 , L_1 ) ;
V_15 -> V_83 -> V_95 |= V_100 ;
return;
}
V_44 = F_19 ( V_2 , V_15 ) ;
F_32 ( V_15 , & V_44 , 1 ) ;
V_98 = V_15 -> V_83 -> V_97 ;
if ( V_56 -> V_86 [ V_25 ] != V_56 -> V_86 [ V_98 ] )
F_12 ( V_2 , V_56 -> V_86 [ V_98 ] , 0 ) ;
F_29 ( V_2 , V_15 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned short * V_101 ,
unsigned int V_102 , unsigned int V_103 )
{
unsigned int V_85 ;
unsigned short V_44 ;
for ( V_85 = V_103 ; V_85 ; V_85 -- ) {
V_44 = V_101 [ V_102 ++ ] ;
F_32 ( V_15 , & V_44 , 1 ) ;
if ( ! F_29 ( V_2 , V_15 ) )
break;
}
}
static void F_34 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_5 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_20 [ V_18 -> V_21 ] ;
unsigned int V_24 ;
int V_102 ;
V_24 = F_8 ( V_15 , V_20 -> V_28 ) -
V_5 -> V_88 ;
V_102 = V_5 -> V_88 ;
V_5 -> V_88 = 0 ;
V_18 -> V_21 = 1 - V_18 -> V_21 ;
F_5 ( V_2 , V_15 , V_24 ) ;
F_33 ( V_2 , V_15 , V_20 -> V_104 , V_102 , V_24 ) ;
}
static T_1 F_35 ( int V_105 , void * V_106 )
{
struct V_1 * V_2 = V_106 ;
struct V_14 * V_15 = V_2 -> V_107 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_2 -> V_108 ) {
F_17 ( V_2 ) ;
return V_109 ;
}
if ( V_5 -> V_87 )
F_34 ( V_2 , V_15 ) ;
else
F_30 ( V_2 , V_15 ) ;
F_17 ( V_2 ) ;
F_36 ( V_2 , V_15 ) ;
return V_109 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_5 -> V_18 ;
struct V_19 * V_20 ;
unsigned long V_61 ;
unsigned int V_110 ;
int V_111 ;
if ( ! V_5 -> V_87 )
return 0 ;
F_38 ( & V_2 -> V_112 , V_61 ) ;
V_110 = F_39 ( V_18 ) ;
V_110 = F_8 ( V_15 , V_110 ) ;
if ( V_110 > V_5 -> V_88 ) {
V_20 = & V_18 -> V_20 [ V_18 -> V_21 ] ;
F_33 ( V_2 , V_15 , V_20 -> V_104 ,
V_5 -> V_88 ,
V_110 - V_5 -> V_88 ) ;
V_5 -> V_88 = V_110 ;
V_111 = F_40 ( V_15 ) ;
} else {
V_111 = 0 ;
}
F_41 ( & V_2 -> V_112 , V_61 ) ;
return V_111 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_87 )
F_6 ( V_5 -> V_18 -> V_25 ) ;
F_15 ( V_5 -> V_92 | V_113 ,
V_2 -> V_8 + V_93 ) ;
F_1 ( V_2 , false ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_48 * V_49 ,
unsigned int * V_114 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_111 = 0 ;
int V_85 ;
F_15 ( V_5 -> V_92 | V_115 ,
V_2 -> V_8 + V_93 ) ;
F_12 ( V_2 , V_49 -> V_29 , 1 ) ;
for ( V_85 = 0 ; V_85 < V_49 -> V_116 ; V_85 ++ ) {
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
V_111 = F_44 ( V_2 , V_15 , V_49 , F_21 , 0 ) ;
if ( V_111 )
break;
V_114 [ V_85 ] = F_19 ( V_2 , V_15 ) ;
}
F_15 ( V_5 -> V_92 | V_113 ,
V_2 -> V_8 + V_93 ) ;
F_17 ( V_2 ) ;
return V_111 ? V_111 : V_49 -> V_116 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_48 * V_49 ,
unsigned int * V_114 )
{
unsigned int V_25 = F_13 ( V_49 -> V_29 ) ;
unsigned int V_44 = V_15 -> V_117 [ V_25 ] ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_49 -> V_116 ; V_85 ++ ) {
V_44 = V_114 [ V_85 ] ;
F_15 ( V_44 & 0xff , V_2 -> V_8 + F_46 ( V_25 ) ) ;
F_15 ( ( V_44 >> 8 ) & 0x0f , V_2 -> V_8 + F_47 ( V_25 ) ) ;
}
V_15 -> V_117 [ V_25 ] = V_44 ;
return V_49 -> V_116 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_48 * V_49 ,
unsigned int * V_114 )
{
V_114 [ 1 ] = F_20 ( V_2 -> V_8 + V_118 ) |
( F_20 ( V_2 -> V_8 + V_119 ) << 8 ) ;
return V_49 -> V_116 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_48 * V_49 ,
unsigned int * V_114 )
{
if ( F_50 ( V_15 , V_114 ) ) {
F_15 ( V_15 -> V_120 & 0xff , V_2 -> V_8 + V_121 ) ;
F_15 ( ( V_15 -> V_120 >> 8 ) , V_2 -> V_8 + V_122 ) ;
}
V_114 [ 1 ] = V_15 -> V_120 ;
return V_49 -> V_116 ;
}
static void F_51 ( struct V_1 * V_2 )
{
const struct V_57 * V_58 = V_2 -> V_59 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_25 ;
F_15 ( V_5 -> V_92 | V_113 ,
V_2 -> V_8 + V_93 ) ;
F_17 ( V_2 ) ;
if ( V_58 -> V_123 )
F_1 ( V_2 , false ) ;
V_5 -> V_33 = F_52 ( 16 , 0 , 0 ) ;
F_12 ( V_2 , F_52 ( 0 , 0 , 0 ) , 0 ) ;
for ( V_25 = 0 ; V_25 < V_58 -> V_124 ; V_25 ++ ) {
F_15 ( 0 , V_2 -> V_8 + F_46 ( V_25 ) ) ;
F_15 ( 0 , V_2 -> V_8 + F_47 ( V_25 ) ) ;
}
if ( V_58 -> V_125 ) {
F_15 ( 0 , V_2 -> V_8 + V_122 ) ;
F_15 ( 0 , V_2 -> V_8 + V_121 ) ;
}
}
static void F_53 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_126 * V_127 )
{
const struct V_57 * V_58 = V_2 -> V_59 ;
struct V_4 * V_5 = V_2 -> V_6 ;
V_15 -> V_128 = V_58 -> V_129 ;
switch ( V_58 -> V_130 ) {
case V_131 :
if ( V_127 -> V_132 [ 4 ] == 1 )
V_15 -> V_128 = & V_133 ;
break;
case V_134 :
switch ( V_127 -> V_132 [ 4 ] ) {
case 0 :
V_15 -> V_128 = & V_135 ;
break;
case 1 :
V_15 -> V_128 = & V_136 ;
break;
case 2 :
V_15 -> V_128 = & V_137 ;
break;
case 3 :
V_15 -> V_128 = & V_138 ;
break;
case 4 :
V_15 -> V_128 = & V_139 ;
break;
case 5 :
V_15 -> V_128 = & V_140 ;
break;
default:
V_15 -> V_128 = & V_135 ;
break;
}
break;
case V_141 :
if ( V_127 -> V_132 [ 1 ] == 1 )
V_15 -> V_128 = & V_142 ;
break;
case V_143 :
switch ( V_127 -> V_132 [ 1 ] ) {
case 0 :
V_15 -> V_128 = & V_144 ;
break;
case 1 :
V_15 -> V_128 = & V_145 ;
break;
case 2 :
V_15 -> V_128 = & V_146 ;
V_5 -> V_39 = 1 ;
break;
case 3 :
V_15 -> V_128 = & V_147 ;
V_5 -> V_39 = 1 ;
break;
default:
V_15 -> V_128 = & V_144 ;
break;
}
break;
case V_148 :
switch ( V_127 -> V_132 [ 1 ] ) {
case 0 :
V_15 -> V_128 = & V_149 ;
break;
case 1 :
V_15 -> V_128 = & V_150 ;
break;
case 2 :
V_15 -> V_128 = & V_151 ;
V_5 -> V_39 = 1 ;
break;
case 3 :
V_15 -> V_128 = & V_152 ;
V_5 -> V_39 = 1 ;
break;
default:
V_15 -> V_128 = & V_149 ;
break;
}
break;
}
}
static void F_54 ( struct V_1 * V_2 , unsigned int V_153 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! ( V_153 == 3 || V_153 == 1 ) )
return;
V_5 -> V_18 = F_55 ( V_2 , 2 , V_153 , V_153 ,
V_154 * 2 , V_155 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 )
F_57 ( V_5 -> V_18 ) ;
}
static int F_58 ( struct V_1 * V_2 , struct V_126 * V_127 )
{
const struct V_57 * V_58 = V_2 -> V_59 ;
struct V_4 * V_5 ;
struct V_14 * V_15 ;
int V_156 ;
int V_157 ;
int V_111 ;
V_5 = F_59 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_158 ;
V_111 = F_60 ( V_2 , V_127 -> V_132 [ 0 ] , 0x10 ) ;
if ( V_111 )
return V_111 ;
if ( ( 1 << V_127 -> V_132 [ 1 ] ) & V_58 -> V_123 ) {
V_111 = F_61 ( V_127 -> V_132 [ 1 ] , F_35 , 0 ,
V_2 -> V_159 , V_2 ) ;
if ( V_111 == 0 )
V_2 -> V_105 = V_127 -> V_132 [ 1 ] ;
}
if ( V_2 -> V_105 && V_58 -> V_160 )
F_54 ( V_2 , V_127 -> V_132 [ 2 ] ) ;
switch ( V_58 -> V_130 ) {
case V_161 :
if ( V_127 -> V_132 [ 2 ] == 1 )
V_5 -> V_35 = 1 ;
break;
case V_162 :
case V_163 :
if ( V_127 -> V_132 [ 4 ] == 1 )
V_5 -> V_35 = 1 ;
break;
}
V_156 = 1 ;
if ( V_58 -> V_124 > 0 )
V_156 ++ ;
if ( V_58 -> V_125 )
V_156 += 2 ;
V_111 = F_62 ( V_2 , V_156 ) ;
if ( V_111 )
return V_111 ;
V_157 = 0 ;
V_15 = & V_2 -> V_164 [ V_157 ] ;
V_15 -> type = V_165 ;
V_15 -> V_166 = V_167 ;
if ( V_5 -> V_35 ) {
V_15 -> V_166 |= V_168 ;
V_15 -> V_169 = V_58 -> V_170 / 2 ;
} else {
V_15 -> V_166 |= V_171 ;
V_15 -> V_169 = V_58 -> V_170 ;
}
V_15 -> V_47 = V_58 -> V_172 ? 0xffff : 0x0fff ;
F_53 ( V_2 , V_15 , V_127 ) ;
V_15 -> V_173 = F_43 ;
if ( V_2 -> V_105 ) {
V_2 -> V_107 = V_15 ;
V_15 -> V_166 |= V_174 ;
V_15 -> V_175 = V_176 ;
V_15 -> V_177 = F_22 ;
V_15 -> V_178 = F_28 ;
V_15 -> V_110 = F_37 ;
V_15 -> V_179 = F_42 ;
}
V_5 -> V_34 = V_58 -> V_180 ;
V_157 ++ ;
if ( V_58 -> V_124 > 0 ) {
V_15 = & V_2 -> V_164 [ V_157 ] ;
V_15 -> type = V_181 ;
V_15 -> V_166 = V_182 | V_171 ;
V_15 -> V_169 = V_58 -> V_124 ;
V_15 -> V_47 = 0xfff ;
V_15 -> V_128 = & V_183 ;
switch ( V_58 -> V_130 ) {
case V_161 :
if ( V_127 -> V_132 [ 3 ] == 1 )
V_15 -> V_128 = & V_184 ;
break;
case V_134 :
case V_162 :
case V_131 :
case V_163 :
if ( V_127 -> V_132 [ 5 ] == 1 )
V_15 -> V_128 = & V_184 ;
if ( V_127 -> V_132 [ 5 ] == 2 )
V_15 -> V_128 = & V_185 ;
break;
}
V_15 -> V_186 = F_45 ;
V_111 = F_63 ( V_15 ) ;
if ( V_111 )
return V_111 ;
V_157 ++ ;
}
if ( V_58 -> V_125 ) {
V_15 = & V_2 -> V_164 [ V_157 ] ;
V_15 -> type = V_187 ;
V_15 -> V_166 = V_167 ;
V_15 -> V_169 = 16 ;
V_15 -> V_47 = 1 ;
V_15 -> V_128 = & V_188 ;
V_15 -> V_189 = F_48 ;
V_157 ++ ;
V_15 = & V_2 -> V_164 [ V_157 ] ;
V_15 -> type = V_190 ;
V_15 -> V_166 = V_182 ;
V_15 -> V_169 = 16 ;
V_15 -> V_47 = 1 ;
V_15 -> V_128 = & V_188 ;
V_15 -> V_189 = F_49 ;
V_157 ++ ;
}
switch ( V_58 -> V_130 ) {
case V_163 :
case V_131 :
case V_134 :
case V_162 :
V_5 -> V_41 = 1 ;
if ( V_127 -> V_132 [ 3 ] > 0 )
V_5 -> V_67 = 1 ;
break;
case V_161 :
V_5 -> V_41 = 1 ;
V_5 -> V_92 = ( V_2 -> V_105 << 4 ) & 0xf0 ;
break;
case V_141 :
case V_191 :
case V_143 :
case V_148 :
V_5 -> V_41 = 5 ;
break;
}
F_51 ( V_2 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_56 ( V_2 ) ;
F_65 ( V_2 ) ;
}

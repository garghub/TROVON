static inline unsigned int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
return ( V_2 & 0x3 ) << ( 8 + 2 * ( V_1 & 0x1 ) ) ;
}
static inline unsigned int F_2 ( unsigned int V_1 )
{
return 0x3 << ( 8 + 2 * ( V_1 & 0x1 ) ) ;
}
static inline unsigned int F_3 ( unsigned int V_1 )
{
return 1 << ( 5 + ( V_1 & 0x1 ) ) ;
}
static inline unsigned int F_4 ( unsigned int V_1 )
{
return 2 * ( V_1 & 0x1 ) ;
}
static inline unsigned int F_5 ( struct V_3 * V_4 )
{
return V_5 | F_6 ( V_6 -> V_7 ) ;
}
static int F_7 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 = NULL ;
int V_14 ;
int V_15 ;
F_8 ( L_1 , V_4 -> V_16 ) ;
if ( F_9 ( V_4 , sizeof( struct V_17 ) ) < 0 )
return - V_18 ;
F_8 ( L_2 ) ;
F_10 (pcidev) {
if ( V_13 -> V_19 != V_20 )
continue;
for ( V_14 = 0 ; V_14 < F_11 ( V_21 ) ; V_14 ++ ) {
if ( V_21 [ V_14 ] . V_22 != V_13 -> V_23 )
continue;
if ( V_9 -> V_24 [ 0 ] || V_9 -> V_24 [ 1 ] ) {
if ( V_13 -> V_25 -> V_26 != V_9 -> V_24 [ 0 ] ||
F_12 ( V_13 -> V_27 ) != V_9 -> V_24 [ 1 ] ) {
continue;
}
}
V_6 -> V_12 = V_13 ;
V_4 -> V_28 = V_21 + V_14 ;
goto V_29;
}
}
F_8 ( L_3
L_4 ) ;
return - V_30 ;
V_29:
F_8 ( L_5 , V_21 [ V_14 ] . V_31 ,
V_13 -> V_25 -> V_26 , F_12 ( V_13 -> V_27 ) ) ;
if ( F_13 ( V_13 , L_6 ) ) {
F_8 ( L_7 ) ;
return - V_30 ;
}
V_6 -> V_32 =
F_14 ( V_6 -> V_12 , V_33 ) ;
V_6 -> V_34 =
F_14 ( V_6 -> V_12 , V_35 ) ;
V_6 -> V_36 =
F_14 ( V_6 -> V_12 , V_37 ) ;
V_6 -> V_38 =
F_14 ( V_6 -> V_12 , V_39 ) ;
if ( V_40 -> V_41 ) {
V_6 -> V_42 =
F_14 ( V_6 -> V_12 , V_43 ) ;
}
F_15 ( V_44 ,
V_6 -> V_32 + V_45 ) ;
if ( F_16 ( V_6 -> V_12 -> V_46 , V_47 ,
V_48 , L_6 , V_4 ) ) {
F_8 ( L_8 , V_6 -> V_12 -> V_46 ) ;
return - V_49 ;
}
V_4 -> V_46 = V_6 -> V_12 -> V_46 ;
V_4 -> V_50 = V_40 -> V_31 ;
if ( F_17 ( V_4 , 7 ) < 0 )
return - V_18 ;
V_11 = V_4 -> V_51 + 0 ;
V_4 -> V_52 = V_11 ;
V_11 -> type = V_53 ;
V_11 -> V_54 = V_55 | V_56 | V_57 | V_58 ;
V_11 -> V_59 = V_40 -> V_60 ;
V_11 -> V_61 = V_40 -> V_60 ;
V_11 -> V_62 = ( 1 << V_40 -> V_63 ) - 1 ;
V_11 -> V_64 = V_40 -> V_65 ;
V_11 -> V_66 = V_67 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_70 = V_71 ;
V_11 -> V_72 = V_73 ;
V_11 -> V_74 = V_75 ;
V_11 = V_4 -> V_51 + 1 ;
if ( V_40 -> V_41 ) {
V_11 -> type = V_76 ;
V_11 -> V_54 = V_55 | V_77 | V_56 ;
V_11 -> V_59 = V_40 -> V_41 ;
V_11 -> V_62 = ( 1 << V_40 -> V_63 ) - 1 ;
V_11 -> V_64 = & V_78 ;
V_11 -> V_66 = V_79 ;
if ( V_40 -> V_80 ) {
V_4 -> V_81 = V_11 ;
V_11 -> V_54 |= V_82 ;
V_11 -> V_83 = V_84 ;
V_11 -> V_72 = V_85 ;
V_11 -> V_70 = V_86 ;
V_11 -> V_74 = V_87 ;
} else {
V_11 -> V_83 = V_88 ;
}
} else {
V_11 -> type = V_89 ;
}
V_11 = V_4 -> V_51 + 2 ;
F_18 ( V_4 , V_11 , NULL , V_6 -> V_38 + V_90 ) ;
V_11 = V_4 -> V_51 + 3 ;
V_11 -> type = V_91 ;
V_11 -> V_54 = V_55 | V_92 ;
V_11 -> V_59 = 256 ;
V_11 -> V_62 = 0xff ;
V_11 -> V_66 = V_93 ;
V_11 = V_4 -> V_51 + 4 ;
V_11 -> type = V_94 ;
V_11 -> V_54 = V_55 | V_77 | V_92 ;
V_11 -> V_59 = V_95 ;
V_11 -> V_62 = 0xff ;
V_11 -> V_66 = V_96 ;
V_11 -> V_83 = V_97 ;
for ( V_15 = 0 ; V_15 < V_11 -> V_59 ; V_15 ++ )
F_19 ( V_4 , V_15 , V_11 -> V_62 / 2 ) ;
V_11 = V_4 -> V_51 + 5 ;
V_11 -> type = V_94 ;
V_11 -> V_54 = V_55 | V_77 | V_92 ;
if ( V_40 -> V_98 == V_99 ) {
V_11 -> V_59 = V_100 ;
V_11 -> V_62 = 0x7f ;
} else {
V_11 -> V_59 = V_101 ;
V_11 -> V_62 = 0xff ;
}
V_11 -> V_66 = V_102 ;
V_11 -> V_83 = V_103 ;
for ( V_15 = 0 ; V_15 < V_11 -> V_59 ; V_15 ++ )
F_20 ( V_4 , V_15 , V_11 -> V_62 / 2 ) ;
V_11 = V_4 -> V_51 + 6 ;
if ( V_40 -> V_104 ) {
V_11 -> type = V_94 ;
V_11 -> V_54 = V_55 | V_77 | V_92 ;
V_11 -> V_59 = V_105 ;
V_11 -> V_66 = V_106 ;
V_11 -> V_83 = V_107 ;
V_11 -> V_62 = 0xff ;
F_21 ( V_4 , V_11 -> V_62 / 2 ) ;
} else
V_11 -> type = V_89 ;
F_22 ( V_6 -> V_32 + V_108 ) ;
V_6 -> V_109 =
F_23 ( 3 ) | F_24 ( 3 ) |
V_110 ;
F_15 ( V_6 -> V_109 | V_44 ,
V_6 -> V_32 + V_45 ) ;
return 1 ;
}
static int F_25 ( struct V_3 * V_4 )
{
F_8 ( L_9 , V_4 -> V_16 ) ;
if ( V_6 ) {
if ( V_6 -> V_32 ) {
F_15 ( V_44 ,
V_6 -> V_32 + V_45 ) ;
#ifdef F_26
F_8 ( L_10 ,
F_22 ( V_6 -> V_32 + V_45 ) ) ;
#endif
}
}
if ( V_4 -> V_46 )
F_27 ( V_4 -> V_46 , V_4 ) ;
if ( V_4 -> V_51 )
F_28 ( V_4 , V_4 -> V_51 + 2 ) ;
if ( V_6 && V_6 -> V_12 ) {
if ( V_6 -> V_32 )
F_29 ( V_6 -> V_12 ) ;
F_30 ( V_6 -> V_12 ) ;
}
return 0 ;
}
static int V_67 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_111 * V_112 , unsigned int * V_113 )
{
int V_114 , V_15 ;
unsigned int V_115 ;
static const int V_116 = 10000 ;
int V_1 ;
if ( V_112 -> V_117 & V_118 ) {
F_31 ( F_5 ( V_4 ) ,
V_6 -> V_34 + V_119 ) ;
V_1 = 0 ;
} else {
F_31 ( 0 , V_6 -> V_34 + V_119 ) ;
V_1 = F_32 ( V_112 -> V_117 ) ;
}
V_115 = F_33 ( V_1 ) |
F_34 ( V_1 ) | F_35 ( F_36 ( V_112 -> V_117 ) ) ;
if ( F_36 ( V_112 -> V_117 ) & V_120 )
V_115 |= V_121 ;
if ( F_37 ( V_112 -> V_117 ) != V_122 )
V_115 |= V_123 ;
F_31 ( V_115 , V_6 -> V_34 + V_124 ) ;
F_31 ( 0 , V_6 -> V_36 + V_125 ) ;
for ( V_114 = 0 ; V_114 < V_112 -> V_114 ; V_114 ++ ) {
F_31 ( 0 , V_6 -> V_36 + V_126 ) ;
for ( V_15 = 0 ; V_15 < V_116 ; V_15 ++ ) {
if ( F_38 ( V_6 -> V_34 + V_124 ) & V_127 )
break;
}
if ( V_15 == V_116 )
return - V_128 ;
V_113 [ V_114 ] = F_38 ( V_6 -> V_36 + V_126 ) ;
}
return V_114 ;
}
static int F_39 ( struct V_3 * V_4 ,
unsigned int * V_113 )
{
static const int V_129 = 8 ;
unsigned int V_130 = V_113 [ 1 ] ;
if ( V_130 >= V_129 ) {
F_8 ( L_11 , V_130 ) ;
return - V_49 ;
}
V_6 -> V_7 = V_130 ;
return 2 ;
}
static int V_69 ( struct V_3 * V_4 , struct V_10 * V_11 ,
struct V_111 * V_112 , unsigned int * V_113 )
{
int V_131 = V_113 [ 0 ] ;
switch ( V_131 ) {
case V_132 :
return F_39 ( V_4 , V_113 ) ;
break;
default:
return - V_49 ;
break;
}
return - V_49 ;
}
static int V_88 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
int V_1 ;
unsigned long V_133 ;
V_1 = F_32 ( V_112 -> V_117 ) ;
F_40 ( & V_4 -> V_134 , V_133 ) ;
V_6 -> V_135 &=
~ V_136 & ~ F_2 ( V_1 ) ;
V_6 -> V_135 |=
V_137 | F_1 ( V_1 , F_36 ( V_112 -> V_117 ) ) ;
F_31 ( V_6 -> V_135 , V_6 -> V_34 + V_138 ) ;
F_41 ( & V_4 -> V_134 , V_133 ) ;
V_6 -> V_139 [ V_1 ] = V_113 [ 0 ] ;
F_31 ( V_113 [ 0 ] , V_6 -> V_42 + F_4 ( V_1 ) ) ;
return 1 ;
}
static int V_84 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_111 * V_112 , unsigned int * V_113 )
{
int V_1 ;
unsigned long V_133 ;
F_31 ( 0 , V_6 -> V_42 + V_140 ) ;
V_1 = F_32 ( V_112 -> V_117 ) ;
F_40 ( & V_4 -> V_134 , V_133 ) ;
V_6 -> V_135 &=
~ F_3 ( 0 ) & ~ F_3 ( 1 ) & ~ F_2 ( V_1 ) &
~ V_141 ;
V_6 -> V_135 |=
V_137 | F_1 ( V_1 ,
F_36 ( V_112 ->
V_117 ) ) | F_3 ( V_1 ) |
V_142 ;
F_31 ( V_6 -> V_135 , V_6 -> V_34 + V_138 ) ;
F_41 ( & V_4 -> V_134 , V_133 ) ;
V_6 -> V_139 [ V_1 ] = V_113 [ 0 ] ;
F_31 ( V_113 [ 0 ] , V_6 -> V_42 + V_143 ) ;
return 1 ;
}
static int V_79 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
V_113 [ 0 ] = V_6 -> V_139 [ F_32 ( V_112 -> V_117 ) ] ;
return 1 ;
}
static int V_93 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_111 * V_112 , unsigned int * V_113 )
{
T_1 V_144 ;
int V_145 ;
V_145 = F_42 ( V_4 , F_32 ( V_112 -> V_117 ) , & V_144 ) ;
if ( V_145 < 0 )
return V_145 ;
V_113 [ 0 ] = V_144 ;
return 1 ;
}
static int V_97 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_111 * V_112 , unsigned int * V_113 )
{
const unsigned int V_1 = F_32 ( V_112 -> V_117 ) ;
return F_19 ( V_4 , V_1 , V_113 [ 0 ] ) ;
}
static int V_96 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_111 * V_112 , unsigned int * V_113 )
{
V_113 [ 0 ] = V_6 -> V_146 [ F_32 ( V_112 -> V_117 ) ] ;
return 1 ;
}
static int F_21 ( struct V_3 * V_4 , unsigned int V_147 )
{
if ( V_6 -> V_148 == V_147 )
return 1 ;
V_6 -> V_148 = V_147 ;
F_31 ( F_5 ( V_4 ) | ( V_147 & 0xff ) ,
V_6 -> V_34 + V_119 ) ;
F_43 ( 1 ) ;
F_31 ( F_5 ( V_4 ) | V_149 | ( V_147 & 0xff ) ,
V_6 -> V_34 + V_119 ) ;
F_43 ( 1 ) ;
F_31 ( F_5 ( V_4 ) | ( V_147 & 0xff ) ,
V_6 -> V_34 + V_119 ) ;
F_43 ( 1 ) ;
return 1 ;
}
static int V_107 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_111 * V_112 , unsigned int * V_113 )
{
return F_21 ( V_4 , V_113 [ 0 ] ) ;
}
static int V_106 ( struct V_3 * V_4 ,
struct V_10 * V_11 , struct V_111 * V_112 ,
unsigned int * V_113 )
{
V_113 [ 0 ] = V_6 -> V_148 ;
return 1 ;
}
static int F_20 ( struct V_3 * V_4 ,
unsigned int V_1 , unsigned int V_147 )
{
if ( V_6 -> V_150 [ V_1 ] == V_147 )
return 1 ;
V_6 -> V_150 [ V_1 ] = V_147 ;
switch ( V_40 -> V_98 ) {
case V_99 :
F_44 ( V_4 , V_147 ) ;
break;
case V_151 :
F_45 ( V_4 , V_1 , V_147 ) ;
break;
default:
F_46 ( V_4 , L_12 ) ;
return - 1 ;
break;
}
return 1 ;
}
static int V_103 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_111 * V_112 , unsigned int * V_113 )
{
unsigned int V_1 = F_32 ( V_112 -> V_117 ) ;
return F_20 ( V_4 , V_1 , V_113 [ 0 ] ) ;
}
static int V_102 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_111 * V_112 , unsigned int * V_113 )
{
unsigned int V_1 = F_32 ( V_112 -> V_117 ) ;
V_113 [ 0 ] = V_6 -> V_150 [ V_1 ] ;
return 1 ;
}
static int V_73 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_152 * V_153 )
{
int V_154 = 0 ;
int V_155 ;
int V_15 , V_156 , V_157 ;
V_155 = V_153 -> V_158 ;
V_153 -> V_158 &= V_159 | V_160 ;
if ( ! V_153 -> V_158 || V_155 != V_153 -> V_158 )
V_154 ++ ;
V_155 = V_153 -> V_161 ;
V_153 -> V_161 &= V_162 | V_163 | V_160 ;
if ( ! V_153 -> V_161 || V_155 != V_153 -> V_161 )
V_154 ++ ;
V_155 = V_153 -> V_164 ;
V_153 -> V_164 &= V_163 | V_159 | V_160 ;
if ( ! V_153 -> V_164 || V_155 != V_153 -> V_164 )
V_154 ++ ;
V_155 = V_153 -> V_165 ;
V_153 -> V_165 &= V_166 ;
if ( ! V_153 -> V_165 || V_155 != V_153 -> V_165 )
V_154 ++ ;
V_155 = V_153 -> V_167 ;
V_153 -> V_167 &= V_166 | V_168 ;
if ( ! V_153 -> V_167 || V_155 != V_153 -> V_167 )
V_154 ++ ;
if ( V_154 )
return 1 ;
if ( V_153 -> V_158 != V_159 && V_153 -> V_158 != V_160 )
V_154 ++ ;
if ( V_153 -> V_161 != V_162 &&
V_153 -> V_161 != V_163 &&
V_153 -> V_161 != V_160 )
V_154 ++ ;
if ( V_153 -> V_164 != V_163 &&
V_153 -> V_164 != V_160 && V_153 -> V_164 != V_159 )
V_154 ++ ;
if ( V_153 -> V_167 != V_166 && V_153 -> V_167 != V_168 )
V_154 ++ ;
if ( V_153 -> V_161 == V_162 && V_153 -> V_164 == V_159 )
V_154 ++ ;
if ( V_153 -> V_161 != V_162 && V_153 -> V_164 != V_159 )
V_154 ++ ;
if ( V_153 -> V_158 == V_160 &&
( V_153 -> V_164 == V_160 || V_153 -> V_161 == V_160 ) )
V_154 ++ ;
if ( V_154 )
return 2 ;
switch ( V_153 -> V_158 ) {
case V_160 :
if ( ( V_153 -> V_169
& ( V_170 & ~ ( V_171 | V_172 ) ) ) != 0 ) {
V_153 -> V_169 &=
~ ( V_170 & ~ ( V_171 | V_172 ) ) ;
V_154 ++ ;
}
if ( ! V_40 -> V_173 &&
( V_153 -> V_169 & V_172 ) ) {
V_153 -> V_169 &= ( V_170 & ~ V_172 ) ;
V_154 ++ ;
}
break;
default:
if ( V_153 -> V_169 != 0 ) {
V_153 -> V_169 = 0 ;
V_154 ++ ;
}
break;
}
if ( V_153 -> V_161 == V_163 ) {
if ( V_153 -> V_174 <
V_40 -> V_175 * V_153 -> V_176 ) {
V_153 -> V_174 =
V_40 -> V_175 * V_153 -> V_176 ;
V_154 ++ ;
}
}
if ( V_153 -> V_164 == V_163 ) {
if ( V_153 -> V_177 < V_40 -> V_175 ) {
V_153 -> V_177 = V_40 -> V_175 ;
V_154 ++ ;
}
}
if ( V_153 -> V_178 != V_153 -> V_176 ) {
V_153 -> V_178 = V_153 -> V_176 ;
V_154 ++ ;
}
if ( V_153 -> V_167 == V_168 ) {
if ( V_153 -> V_179 != 0 ) {
V_153 -> V_179 = 0 ;
V_154 ++ ;
}
}
if ( V_154 )
return 3 ;
if ( V_153 -> V_161 == V_163 ) {
V_155 = V_153 -> V_174 ;
F_47 ( V_180 ,
& ( V_6 -> V_181 ) ,
& ( V_6 -> V_182 ) ,
& ( V_153 -> V_174 ) ,
V_153 -> V_133 & V_183 ) ;
if ( V_155 != V_153 -> V_174 )
V_154 ++ ;
}
if ( V_153 -> V_164 == V_163 ) {
V_155 = V_153 -> V_177 ;
F_47 ( V_180 ,
& ( V_6 -> V_181 ) ,
& ( V_6 -> V_182 ) ,
& ( V_153 -> V_177 ) ,
V_153 -> V_133 & V_183 ) ;
if ( V_155 != V_153 -> V_177 )
V_154 ++ ;
}
if ( V_154 )
return 4 ;
if ( V_153 -> V_184 ) {
V_156 = F_36 ( V_153 -> V_184 [ 0 ] ) ;
V_157 = F_32 ( V_153 -> V_184 [ 0 ] ) ;
for ( V_15 = 1 ; V_15 < V_153 -> V_176 ; V_15 ++ ) {
if ( F_32 ( V_153 -> V_184 [ V_15 ] ) !=
( V_157 + V_15 ) % V_11 -> V_59 ) {
F_46 ( V_4 ,
L_13 ) ;
V_154 ++ ;
}
if ( F_36 ( V_153 -> V_184 [ V_15 ] ) != V_156 ) {
F_46 ( V_4 ,
L_14 ) ;
V_154 ++ ;
}
}
}
if ( V_154 )
return 5 ;
return 0 ;
}
static int V_71 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_185 * V_186 = V_11 -> V_186 ;
struct V_152 * V_153 = & V_186 -> V_153 ;
unsigned int V_115 ;
unsigned long V_133 ;
F_31 ( 0 , V_6 -> V_34 + V_119 ) ;
F_31 ( 0 , V_6 -> V_34 + V_187 ) ;
F_31 ( 0 , V_6 -> V_36 + V_125 ) ;
V_115 = F_33 ( F_32 ( V_153 -> V_184 [ 0 ] ) ) |
F_34 ( F_32 ( V_153 -> V_184 [ V_153 -> V_176 - 1 ] ) ) |
F_35 ( F_36 ( V_153 -> V_184 [ 0 ] ) ) ;
if ( F_36 ( V_153 -> V_184 [ 0 ] ) & V_120 )
V_115 |= V_121 ;
if ( F_37 ( V_153 -> V_184 [ 0 ] ) != V_122 )
V_115 |= V_123 ;
if ( V_153 -> V_164 == V_160 || V_153 -> V_161 == V_160 )
V_115 |= V_188 ;
else
V_115 |= V_189 ;
F_31 ( V_115 , V_6 -> V_34 + V_124 ) ;
#ifdef F_26
F_8 ( L_15 , V_115 ) ;
#endif
if ( V_153 -> V_164 == V_163 )
F_48 ( V_4 , & V_153 -> V_177 ,
V_153 -> V_133 & V_183 ) ;
else if ( V_153 -> V_161 == V_163 )
F_48 ( V_4 , & V_153 -> V_174 ,
V_153 -> V_133 & V_183 ) ;
if ( V_153 -> V_167 == V_166 )
V_6 -> V_190 = V_153 -> V_176 * V_153 -> V_179 ;
F_40 ( & V_4 -> V_134 , V_133 ) ;
V_6 -> V_191 |= V_192 ;
V_6 -> V_191 &= ~ V_193 ;
if ( V_153 -> V_133 & V_194 ) {
if ( V_153 -> V_164 == V_159 && V_153 -> V_176 > 1 )
V_6 -> V_191 |= V_195 ;
else
V_6 -> V_191 |= V_196 ;
} else {
V_6 -> V_191 |= V_197 ;
}
#ifdef F_26
F_8 ( L_16 , V_6 -> V_191 ) ;
#endif
F_31 ( V_6 -> V_191 | V_198 | INT | V_199 ,
V_6 -> V_34 + V_200 ) ;
F_41 ( & V_4 -> V_134 , V_133 ) ;
V_115 = 0 ;
if ( V_153 -> V_158 == V_159 )
V_115 |= V_201 ;
else if ( V_153 -> V_158 == V_160 ) {
V_115 |= V_202 | V_203 | V_204 ;
if ( V_40 -> V_173
&& ( V_153 -> V_169 & V_172 ) )
V_115 |= V_205 ;
if ( V_40 -> V_206 && ( V_153 -> V_169 & V_171 ) )
V_115 |= V_207 ;
} else {
F_46 ( V_4 , L_17 ) ;
return - 1 ;
}
if ( V_153 -> V_164 == V_159 && V_153 -> V_176 > 1 )
V_115 |= V_208 ;
F_31 ( V_115 , V_6 -> V_34 + V_187 ) ;
#ifdef F_26
F_8 ( L_18 , V_115 ) ;
#endif
return 0 ;
}
static int V_85 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_152 * V_153 )
{
int V_154 = 0 ;
int V_155 ;
V_155 = V_153 -> V_158 ;
V_153 -> V_158 &= V_209 ;
if ( ! V_153 -> V_158 || V_155 != V_153 -> V_158 )
V_154 ++ ;
V_155 = V_153 -> V_161 ;
V_153 -> V_161 &= V_163 | V_160 ;
if ( ! V_153 -> V_161 || V_155 != V_153 -> V_161 )
V_154 ++ ;
V_155 = V_153 -> V_164 ;
V_153 -> V_164 &= V_159 ;
if ( ! V_153 -> V_164 || V_155 != V_153 -> V_164 )
V_154 ++ ;
V_155 = V_153 -> V_165 ;
V_153 -> V_165 &= V_166 ;
if ( ! V_153 -> V_165 || V_155 != V_153 -> V_165 )
V_154 ++ ;
V_155 = V_153 -> V_167 ;
V_153 -> V_167 &= V_166 | V_168 ;
if ( ! V_153 -> V_167 || V_155 != V_153 -> V_167 )
V_154 ++ ;
if ( V_154 )
return 1 ;
if ( V_153 -> V_161 != V_163 &&
V_153 -> V_161 != V_160 )
V_154 ++ ;
if ( V_153 -> V_167 != V_166 && V_153 -> V_167 != V_168 )
V_154 ++ ;
if ( V_154 )
return 2 ;
if ( V_153 -> V_169 != 0 ) {
V_153 -> V_169 = 0 ;
V_154 ++ ;
}
if ( V_153 -> V_161 == V_163 ) {
if ( V_153 -> V_174 < V_40 -> V_210 ) {
V_153 -> V_174 = V_40 -> V_210 ;
V_154 ++ ;
}
}
if ( V_153 -> V_178 != V_153 -> V_176 ) {
V_153 -> V_178 = V_153 -> V_176 ;
V_154 ++ ;
}
if ( V_153 -> V_167 == V_168 ) {
if ( V_153 -> V_179 != 0 ) {
V_153 -> V_179 = 0 ;
V_154 ++ ;
}
}
if ( V_154 )
return 3 ;
if ( V_153 -> V_161 == V_163 ) {
V_155 = V_153 -> V_174 ;
F_47 ( V_180 ,
& ( V_6 -> V_211 ) ,
& ( V_6 -> V_212 ) ,
& ( V_153 -> V_174 ) ,
V_153 -> V_133 & V_183 ) ;
if ( V_155 != V_153 -> V_174 )
V_154 ++ ;
}
if ( V_154 )
return 4 ;
if ( V_153 -> V_184 && V_153 -> V_176 > 1 ) {
if ( F_32 ( V_153 -> V_184 [ 0 ] ) != 0 ||
F_32 ( V_153 -> V_184 [ 1 ] ) != 1 ) {
F_46 ( V_4 ,
L_19 ) ;
V_154 ++ ;
}
}
if ( V_154 )
return 5 ;
return 0 ;
}
static int V_86 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_185 * V_186 = V_11 -> V_186 ;
struct V_152 * V_153 = & V_186 -> V_153 ;
unsigned int V_15 ;
unsigned long V_133 ;
F_40 ( & V_4 -> V_134 , V_133 ) ;
for ( V_15 = 0 ; V_15 < V_153 -> V_176 ; V_15 ++ ) {
V_6 -> V_135 |=
F_3 ( F_32 ( V_153 -> V_184 [ V_15 ] ) ) ;
V_6 -> V_135 |= F_1 ( F_32 ( V_153 -> V_184 [ V_15 ] ) ,
F_36 ( V_153 ->
V_184 [ V_15 ] ) ) ;
}
F_31 ( V_6 -> V_135 , V_6 -> V_34 + V_138 ) ;
F_41 ( & V_4 -> V_134 , V_133 ) ;
F_31 ( 0 , V_6 -> V_42 + V_140 ) ;
if ( V_153 -> V_161 == V_163 ) {
F_47 ( V_180 ,
& ( V_6 -> V_211 ) ,
& ( V_6 -> V_212 ) ,
& ( V_153 -> V_174 ) ,
V_153 -> V_133 ) ;
F_49 ( V_6 -> V_38 + V_213 , 0 , 1 ,
V_6 -> V_211 , 2 ) ;
F_49 ( V_6 -> V_38 + V_213 , 0 , 2 ,
V_6 -> V_212 , 2 ) ;
}
if ( V_153 -> V_167 == V_166 )
V_6 -> V_214 = V_153 -> V_176 * V_153 -> V_179 ;
F_40 ( & V_4 -> V_134 , V_133 ) ;
switch ( V_153 -> V_161 ) {
case V_163 :
V_6 -> V_135 |= V_215 ;
break;
case V_160 :
V_6 -> V_135 |= V_216 ;
break;
default:
F_41 ( & V_4 -> V_134 , V_133 ) ;
F_46 ( V_4 , L_20 ) ;
return - 1 ;
break;
}
F_41 ( & V_4 -> V_134 , V_133 ) ;
V_186 -> V_217 = V_218 ;
return 0 ;
}
static int V_218 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
unsigned int V_219 )
{
unsigned int V_220 , V_221 = V_40 -> V_222 ;
struct V_185 * V_186 = V_11 -> V_186 ;
struct V_152 * V_153 = & V_11 -> V_186 -> V_153 ;
unsigned long V_133 ;
if ( V_219 != 0 )
return - V_49 ;
if ( V_153 -> V_167 == V_166 && V_6 -> V_214 < V_221 )
V_221 = V_6 -> V_214 ;
V_220 = F_50 ( V_11 , V_6 -> V_223 ,
V_221 * sizeof( short ) ) ;
V_221 = V_220 / sizeof( short ) ;
if ( V_153 -> V_167 == V_166 )
V_6 -> V_214 -= V_221 ;
F_51 ( V_6 -> V_42 + V_143 , V_6 -> V_223 , V_220 ) ;
F_40 ( & V_4 -> V_134 , V_133 ) ;
V_6 -> V_191 |= V_224 | V_225 ;
#ifdef F_26
F_8 ( L_16 , V_6 -> V_191 ) ;
#endif
F_31 ( V_6 -> V_191 | V_226 | V_227 ,
V_6 -> V_34 + V_200 ) ;
V_6 -> V_135 |= V_142 | V_137 | V_228 ;
F_31 ( V_6 -> V_135 , V_6 -> V_34 + V_138 ) ;
#ifdef F_26
F_8 ( L_21 , V_6 -> V_135 ) ;
#endif
F_41 ( & V_4 -> V_134 , V_133 ) ;
V_186 -> V_217 = NULL ;
return 0 ;
}
static T_2 V_47 ( int V_46 , void * V_229 )
{
struct V_3 * V_4 = (struct V_3 * ) V_229 ;
struct V_10 * V_11 = V_4 -> V_52 ;
struct V_185 * V_186 ;
int V_230 , V_231 ;
int V_232 = V_40 -> V_222 / 2 ;
unsigned int V_233 , V_15 ;
static const int V_116 = 10000 ;
unsigned long V_133 ;
if ( V_4 -> V_234 == 0 )
return V_235 ;
V_186 = V_11 -> V_186 ;
V_186 -> V_236 = 0 ;
V_231 = F_22 ( V_6 -> V_32 + V_45 ) ;
#ifdef F_26
F_8 ( L_22 , V_231 ) ;
F_8 ( L_23 , F_22 ( V_6 -> V_32 + V_237 ) ) ;
#endif
if ( ( V_238 & V_231 ) == 0 )
return V_235 ;
F_52 ( V_6 -> V_32 + V_108 ) ;
F_15 ( V_6 -> V_109 | V_44 ,
V_6 -> V_32 + V_45 ) ;
V_230 = F_38 ( V_6 -> V_34 + V_200 ) ;
#ifdef F_26
if ( ( V_230 & ( INT | V_198 | V_199 | V_227 | V_226 ) ) == 0 )
F_46 ( V_4 , L_24 ) ;
#endif
if ( V_230 & ( V_227 | V_226 ) )
F_53 ( V_4 , V_230 ) ;
if ( V_230 & V_239 ) {
V_233 = V_232 ;
if ( V_186 -> V_153 . V_167 == V_166 &&
V_233 > V_6 -> V_190 ) {
V_233 = V_6 -> V_190 ;
}
F_54 ( V_6 -> V_36 + V_126 , V_6 -> V_240 ,
V_233 ) ;
F_55 ( V_11 , V_6 -> V_240 ,
V_233 * sizeof( short ) ) ;
V_6 -> V_190 -= V_233 ;
if ( V_186 -> V_153 . V_167 == V_166 && V_6 -> V_190 == 0 ) {
V_186 -> V_236 |= V_241 ;
V_75 ( V_4 , V_11 ) ;
}
F_40 ( & V_4 -> V_134 , V_133 ) ;
F_31 ( V_6 -> V_191 | INT ,
V_6 -> V_34 + V_200 ) ;
F_41 ( & V_4 -> V_134 , V_133 ) ;
} else if ( V_230 & ( V_242 | V_243 ) ) {
for ( V_15 = 0 ; V_15 < V_116 ; V_15 ++ ) {
if ( ( V_244 & F_38 ( V_6 -> V_34 +
V_200 ) ) == 0 )
break;
F_56 ( V_11 , F_38 ( V_6 -> V_36 ) ) ;
if ( V_186 -> V_153 . V_167 == V_166 && -- V_6 -> V_190 == 0 ) {
V_75 ( V_4 , V_11 ) ;
V_186 -> V_236 |= V_241 ;
break;
}
}
F_40 ( & V_4 -> V_134 , V_133 ) ;
F_31 ( V_6 -> V_191 | INT ,
V_6 -> V_34 + V_200 ) ;
F_41 ( & V_4 -> V_134 , V_133 ) ;
} else if ( V_230 & V_198 ) {
F_46 ( V_4 ,
L_25 ) ;
F_40 ( & V_4 -> V_134 , V_133 ) ;
F_31 ( V_6 -> V_191 | V_198 ,
V_6 -> V_34 + V_200 ) ;
F_41 ( & V_4 -> V_134 , V_133 ) ;
}
if ( V_230 & V_199 ) {
F_46 ( V_4 , L_26 ) ;
F_40 ( & V_4 -> V_134 , V_133 ) ;
F_31 ( V_6 -> V_191 | V_199 ,
V_6 -> V_34 + V_200 ) ;
F_41 ( & V_4 -> V_134 , V_133 ) ;
V_75 ( V_4 , V_11 ) ;
V_186 -> V_236 |= V_241 | V_245 ;
}
F_57 ( V_4 , V_11 ) ;
return V_246 ;
}
static void F_53 ( struct V_3 * V_4 , unsigned int V_230 )
{
struct V_10 * V_11 = V_4 -> V_81 ;
struct V_185 * V_186 = V_11 -> V_186 ;
struct V_152 * V_153 = & V_186 -> V_153 ;
unsigned int V_232 = V_40 -> V_222 / 2 ;
unsigned int V_221 ;
unsigned long V_133 ;
V_186 -> V_236 = 0 ;
if ( V_230 & V_226 ) {
F_40 ( & V_4 -> V_134 , V_133 ) ;
F_31 ( V_6 -> V_191 | V_226 ,
V_6 -> V_34 + V_200 ) ;
F_41 ( & V_4 -> V_134 , V_133 ) ;
if ( F_38 ( V_6 -> V_42 + V_138 ) & V_228 ) {
if ( V_153 -> V_167 == V_168 ||
( V_153 -> V_167 == V_166
&& V_6 -> V_214 ) ) {
F_46 ( V_4 , L_27 ) ;
V_87 ( V_4 , V_11 ) ;
V_186 -> V_236 |= V_245 ;
}
V_186 -> V_236 |= V_241 ;
}
} else if ( V_230 & V_227 ) {
unsigned int V_220 ;
V_221 = V_232 ;
if ( V_153 -> V_167 == V_166 &&
V_6 -> V_214 < V_221 )
V_221 = V_6 -> V_214 ;
V_220 =
F_50 ( V_11 , V_6 -> V_223 ,
V_221 * sizeof( short ) ) ;
V_221 = V_220 / sizeof( short ) ;
if ( V_186 -> V_153 . V_167 == V_166 )
V_6 -> V_214 -= V_221 ;
F_51 ( V_6 -> V_42 + V_143 , V_6 -> V_223 ,
V_221 ) ;
F_40 ( & V_4 -> V_134 , V_133 ) ;
F_31 ( V_6 -> V_191 | V_227 ,
V_6 -> V_34 + V_200 ) ;
F_41 ( & V_4 -> V_134 , V_133 ) ;
}
F_57 ( V_4 , V_11 ) ;
}
static int V_75 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
unsigned long V_133 ;
F_40 ( & V_4 -> V_134 , V_133 ) ;
V_6 -> V_191 &= ~ V_192 & ~ V_247 ;
F_31 ( V_6 -> V_191 , V_6 -> V_34 + V_200 ) ;
F_41 ( & V_4 -> V_134 , V_133 ) ;
F_31 ( 0 , V_6 -> V_34 + V_187 ) ;
F_31 ( 0 , V_6 -> V_34 + V_124 ) ;
return 0 ;
}
static int V_87 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
unsigned long V_133 ;
F_40 ( & V_4 -> V_134 , V_133 ) ;
V_6 -> V_191 &= ~ V_225 & ~ V_224 ;
F_31 ( V_6 -> V_191 , V_6 -> V_34 + V_200 ) ;
V_6 -> V_135 &= ~ V_137 & ~ V_141 ;
F_31 ( V_6 -> V_135 , V_6 -> V_34 + V_138 ) ;
F_41 ( & V_4 -> V_134 , V_133 ) ;
return 0 ;
}
static void F_48 ( struct V_3 * V_4 , unsigned int * V_248 ,
int V_249 )
{
F_47 ( V_180 , & ( V_6 -> V_181 ) ,
& ( V_6 -> V_182 ) , V_248 ,
V_249 & V_183 ) ;
F_49 ( V_6 -> V_38 + V_250 , 0 , 1 ,
V_6 -> V_181 , 2 ) ;
F_49 ( V_6 -> V_38 + V_250 , 0 , 2 ,
V_6 -> V_182 , 2 ) ;
}
static void F_58 ( struct V_3 * V_4 ,
unsigned int V_251 ,
unsigned int V_252 ,
unsigned int V_253 )
{
static const int V_254 = 1 ;
unsigned int V_255 ;
for ( V_255 = 1 << ( V_253 - 1 ) ; V_255 ; V_255 >>= 1 ) {
if ( V_252 & V_255 )
V_251 |= V_256 ;
else
V_251 &= ~ V_256 ;
F_43 ( V_254 ) ;
F_31 ( V_251 , V_6 -> V_34 + V_119 ) ;
}
}
static int F_19 ( struct V_3 * V_4 , unsigned int V_257 ,
T_1 V_147 )
{
static const int V_258 = 8 ;
static const int V_253 = 11 ;
unsigned int V_252 = ( ( V_257 & 0x7 ) << 8 ) | V_147 ;
static const int V_259 = 1 ;
if ( V_257 >= V_258 ) {
F_46 ( V_4 , L_28 ) ;
return - 1 ;
}
if ( V_147 == V_6 -> V_146 [ V_257 ] )
return 1 ;
V_6 -> V_146 [ V_257 ] = V_147 ;
F_58 ( V_4 , F_5 ( V_4 ) , V_252 ,
V_253 ) ;
F_43 ( V_259 ) ;
F_31 ( F_5 ( V_4 ) | V_260 ,
V_6 -> V_34 + V_119 ) ;
F_43 ( V_259 ) ;
F_31 ( F_5 ( V_4 ) , V_6 -> V_34 + V_119 ) ;
return 1 ;
}
static int F_44 ( struct V_3 * V_4 , T_1 V_147 )
{
static const int V_253 = 7 ;
unsigned int V_252 = V_147 & 0x7f ;
unsigned int V_251 ;
static const int V_261 = 1 ;
V_251 = F_5 ( V_4 ) | V_262 ;
F_43 ( V_261 ) ;
F_31 ( V_251 , V_6 -> V_34 + V_119 ) ;
F_58 ( V_4 , V_251 , V_252 ,
V_253 ) ;
F_43 ( V_261 ) ;
F_31 ( F_5 ( V_4 ) , V_6 -> V_34 + V_119 ) ;
return 0 ;
}
static int F_45 ( struct V_3 * V_4 , unsigned int V_1 ,
T_1 V_147 )
{
static const int V_253 = 10 ;
unsigned int V_252 = ( ( V_1 & 0x3 ) << 8 ) | ( V_147 & 0xff ) ;
unsigned int V_251 ;
static const int V_263 = 1 ;
V_251 = F_5 ( V_4 ) | V_262 ;
F_43 ( V_263 ) ;
F_31 ( V_251 , V_6 -> V_34 + V_119 ) ;
F_58 ( V_4 , V_251 , V_252 ,
V_253 ) ;
F_43 ( V_263 ) ;
F_31 ( F_5 ( V_4 ) , V_6 -> V_34 + V_119 ) ;
return 0 ;
}
static int F_59 ( unsigned long V_264 )
{
static const int V_116 = 1000 ;
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_116 ; V_15 ++ ) {
if ( ( F_60 ( V_264 +
V_265 ) & V_266 )
== 0 )
return 0 ;
F_43 ( 1 ) ;
}
return - 1 ;
}
static int F_42 ( struct V_3 * V_4 , unsigned int V_257 ,
T_1 * V_113 )
{
unsigned long V_267 = V_6 -> V_32 ;
if ( F_59 ( V_267 ) < 0 )
return - V_128 ;
F_61 ( V_268 | V_269 ,
V_267 + V_265 ) ;
F_61 ( V_257 & 0xff , V_267 + V_270 ) ;
F_61 ( V_268 | V_271 ,
V_267 + V_265 ) ;
F_61 ( ( V_257 >> 8 ) & 0xff , V_267 + V_270 ) ;
F_61 ( V_268 | V_272 , V_267 + V_265 ) ;
if ( F_59 ( V_267 ) < 0 )
return - V_128 ;
* V_113 = F_60 ( V_267 + V_270 ) ;
return 0 ;
}
static int T_3 F_62 ( struct V_12 * V_4 ,
const struct V_273 * V_274 )
{
return F_63 ( V_4 , V_275 . V_276 ) ;
}
static void T_4 F_64 ( struct V_12 * V_4 )
{
F_65 ( V_4 ) ;
}
static int T_5 F_66 ( void )
{
int V_145 ;
V_145 = F_67 ( & V_275 ) ;
if ( V_145 < 0 )
return V_145 ;
V_277 . V_31 = ( char * ) V_275 . V_276 ;
return F_68 ( & V_277 ) ;
}
static void T_6 F_69 ( void )
{
F_70 ( & V_277 ) ;
F_71 ( & V_275 ) ;
}

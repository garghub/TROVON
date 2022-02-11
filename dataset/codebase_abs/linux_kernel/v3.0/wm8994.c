static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_5 -> V_7 ;
switch ( V_3 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return 1 ;
case V_22 :
case V_23 :
case V_24 :
if ( V_6 -> type == V_25 )
return 1 ;
else
return 0 ;
default:
break;
}
if ( V_3 >= V_26 )
return 0 ;
return V_27 [ V_3 ] . V_28 != 0 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 >= V_26 )
return 1 ;
switch ( V_3 ) {
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_24 :
case V_36 :
return 1 ;
default:
return 0 ;
}
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_37 )
{
int V_38 ;
F_5 ( V_3 > V_39 ) ;
if ( ! F_3 ( V_2 , V_3 ) ) {
V_38 = F_6 ( V_2 , V_3 , V_37 ) ;
if ( V_38 != 0 )
F_7 ( V_2 -> V_40 , L_1 ,
V_3 , V_38 ) ;
}
return F_8 ( V_2 -> V_7 , V_3 , V_37 ) ;
}
static unsigned int F_9 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_41 ;
int V_38 ;
F_5 ( V_3 > V_39 ) ;
if ( ! F_3 ( V_2 , V_3 ) && F_1 ( V_2 , V_3 ) &&
V_3 < V_2 -> V_42 -> V_43 ) {
V_38 = F_10 ( V_2 , V_3 , & V_41 ) ;
if ( V_38 >= 0 )
return V_41 ;
else
F_7 ( V_2 -> V_40 , L_2 ,
V_3 , V_38 ) ;
}
return F_11 ( V_2 -> V_7 , V_3 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_44 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_45 ;
int V_46 = 0 ;
int V_47 ;
if ( V_44 )
V_47 = 4 ;
else
V_47 = 0 ;
switch ( V_5 -> V_48 [ V_44 ] ) {
case V_49 :
V_45 = V_5 -> V_50 [ 0 ] ;
break;
case V_51 :
V_46 |= 0x8 ;
V_45 = V_5 -> V_50 [ 1 ] ;
break;
case V_52 :
V_46 |= 0x10 ;
V_45 = V_5 -> V_53 [ 0 ] . V_54 ;
break;
case V_55 :
V_46 |= 0x18 ;
V_45 = V_5 -> V_53 [ 1 ] . V_54 ;
break;
default:
return - V_56 ;
}
if ( V_45 >= 13500000 ) {
V_45 /= 2 ;
V_46 |= V_57 ;
F_13 ( V_2 -> V_40 , L_3 ,
V_44 + 1 , V_45 ) ;
}
if ( V_45 && V_45 < 3000000 )
F_14 ( V_2 -> V_40 , L_4 ,
V_44 + 1 , V_45 ) ;
V_5 -> V_58 [ V_44 ] = V_45 ;
F_15 ( V_2 , V_59 + V_47 ,
V_60 | V_57 ,
V_46 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_61 , V_62 ;
F_12 ( V_2 , 0 ) ;
F_12 ( V_2 , 1 ) ;
if ( V_5 -> V_58 [ 0 ] == V_5 -> V_58 [ 1 ] )
return 0 ;
if ( V_5 -> V_58 [ 0 ] < V_5 -> V_58 [ 1 ] )
V_62 = V_63 ;
else
V_62 = 0 ;
V_61 = F_17 ( V_2 , V_64 ) & V_63 ;
if ( V_61 == V_62 )
return 0 ;
F_15 ( V_2 , V_64 , V_63 , V_62 ) ;
F_18 ( & V_2 -> V_65 ) ;
return 0 ;
}
static int F_19 ( struct V_66 * V_67 ,
struct V_66 * V_68 )
{
int V_3 = F_17 ( V_67 -> V_2 , V_64 ) ;
const char * V_69 ;
if ( V_3 & V_63 )
V_69 = L_5 ;
else
V_69 = L_6 ;
return strcmp ( V_67 -> V_70 , V_69 ) == 0 ;
}
static int F_20 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_75 * V_76 =
(struct V_75 * ) V_72 -> V_77 ;
struct V_1 * V_2 = F_21 ( V_72 ) ;
int V_78 , V_38 ;
if ( V_76 -> V_79 == V_80 )
V_78 = V_81 |
V_82 ;
else
V_78 = V_83 ;
V_38 = F_17 ( V_2 , V_76 -> V_3 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 & V_78 )
return - V_56 ;
return F_22 ( V_72 , V_74 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_84 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_85 * V_86 = V_5 -> V_86 ;
int V_87 = V_88 [ V_84 ] ;
int V_89 = V_5 -> V_90 [ V_84 ] ;
int V_91 , V_92 ;
V_91 = F_17 ( V_2 , V_87 ) ;
V_91 &= V_93 | V_94 |
V_95 ;
for ( V_92 = 0 ; V_92 < V_96 ; V_92 ++ )
F_15 ( V_2 , V_87 + V_92 , 0xffff ,
V_86 -> V_97 [ V_89 ] . V_98 [ V_92 ] ) ;
F_15 ( V_2 , V_87 , V_93 |
V_94 |
V_95 , V_91 ) ;
}
static int F_24 ( const char * V_70 )
{
if ( strcmp ( V_70 , L_7 ) == 0 )
return 0 ;
if ( strcmp ( V_70 , L_8 ) == 0 )
return 1 ;
if ( strcmp ( V_70 , L_9 ) == 0 )
return 2 ;
return - V_56 ;
}
static int F_25 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_21 ( V_72 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_85 * V_86 = V_5 -> V_86 ;
int V_84 = F_24 ( V_72 -> V_99 . V_70 ) ;
int V_37 = V_74 -> V_37 . integer . V_37 [ 0 ] ;
if ( V_84 < 0 )
return V_84 ;
if ( V_37 >= V_86 -> V_100 )
return - V_56 ;
V_5 -> V_90 [ V_84 ] = V_37 ;
F_23 ( V_2 , V_84 ) ;
return 0 ;
}
static int F_26 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_21 ( V_72 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_84 = F_24 ( V_72 -> V_99 . V_70 ) ;
V_74 -> V_37 . V_101 . V_102 [ 0 ] = V_5 -> V_90 [ V_84 ] ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 , int V_103 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_85 * V_86 = V_5 -> V_86 ;
int V_87 = V_104 [ V_103 ] ;
int V_105 , V_106 , V_107 , V_91 , V_92 , V_89 ;
if ( ! V_86 || ! V_5 -> V_108 )
return;
switch ( V_103 ) {
case 0 :
case 1 :
V_105 = 0 ;
break;
case 2 :
V_105 = 1 ;
break;
default:
return;
}
V_89 = V_5 -> V_109 [ V_103 ] ;
V_106 = 0 ;
V_107 = V_110 ;
for ( V_92 = 0 ; V_92 < V_86 -> V_111 ; V_92 ++ ) {
if ( strcmp ( V_86 -> V_112 [ V_92 ] . V_70 ,
V_5 -> V_113 [ V_89 ] ) == 0 &&
abs ( V_86 -> V_112 [ V_92 ] . V_45
- V_5 -> V_114 [ V_105 ] ) < V_107 ) {
V_106 = V_92 ;
V_107 = abs ( V_86 -> V_112 [ V_92 ] . V_45
- V_5 -> V_114 [ V_105 ] ) ;
}
}
F_13 ( V_2 -> V_40 , L_10 ,
V_103 ,
V_86 -> V_112 [ V_106 ] . V_70 ,
V_86 -> V_112 [ V_106 ] . V_45 ,
V_5 -> V_114 [ V_105 ] ) ;
V_91 = F_17 ( V_2 , V_87 ) ;
V_91 &= V_115 ;
for ( V_92 = 0 ; V_92 < V_116 ; V_92 ++ )
F_15 ( V_2 , V_87 + V_92 , 0xffff ,
V_86 -> V_112 [ V_106 ] . V_98 [ V_92 ] ) ;
F_15 ( V_2 , V_87 , V_115 , V_91 ) ;
}
static int F_28 ( const char * V_70 )
{
if ( strcmp ( V_70 , L_11 ) == 0 )
return 0 ;
if ( strcmp ( V_70 , L_12 ) == 0 )
return 1 ;
if ( strcmp ( V_70 , L_13 ) == 0 )
return 2 ;
return - V_56 ;
}
static int F_29 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_21 ( V_72 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_85 * V_86 = V_5 -> V_86 ;
int V_103 = F_28 ( V_72 -> V_99 . V_70 ) ;
int V_37 = V_74 -> V_37 . integer . V_37 [ 0 ] ;
if ( V_103 < 0 )
return V_103 ;
if ( V_37 >= V_86 -> V_111 )
return - V_56 ;
V_5 -> V_109 [ V_103 ] = V_37 ;
F_27 ( V_2 , V_103 ) ;
return 0 ;
}
static int F_30 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_21 ( V_72 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_103 = F_28 ( V_72 -> V_99 . V_70 ) ;
V_74 -> V_37 . V_101 . V_102 [ 0 ] = V_5 -> V_109 [ V_103 ] ;
return 0 ;
}
static int F_31 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
switch ( V_118 ) {
case V_119 :
return F_16 ( V_2 ) ;
case V_120 :
F_16 ( V_2 ) ;
break;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_121 = 1 ;
int V_67 = 0 ;
int V_3 , V_122 ;
V_3 = F_17 ( V_2 , V_123 ) ;
if ( ! ( V_3 & V_124 ) ) {
F_33 ( V_2 -> V_40 , L_14 ) ;
V_121 = 0 ;
}
V_3 = F_17 ( V_2 , V_125 ) ;
if ( ! ( V_3 & V_126 ) ) {
F_33 ( V_2 -> V_40 , L_15 ) ;
V_121 = 0 ;
}
V_3 = F_17 ( V_2 , V_127 ) ;
switch ( V_3 ) {
case V_128 :
F_33 ( V_2 -> V_40 , L_16 ) ;
V_67 = 2 << V_129 ;
break;
case V_130 :
F_33 ( V_2 -> V_40 , L_17 ) ;
V_67 = 1 << V_129 ;
break;
case V_131 :
F_33 ( V_2 -> V_40 , L_18 ) ;
V_67 = 0 << V_129 ;
break;
default:
F_33 ( V_2 -> V_40 , L_19 , V_3 ) ;
V_121 = 0 ;
break;
}
V_122 = F_17 ( V_2 , V_132 ) ;
if ( V_122 != V_3 ) {
F_33 ( V_2 -> V_40 , L_20 ) ;
V_121 = 0 ;
}
if ( V_121 ) {
F_13 ( V_2 -> V_40 , L_21 ) ;
F_15 ( V_2 , V_133 ,
V_134 |
V_135 ,
V_67 | V_134 ) ;
V_5 -> V_136 . V_137 = true ;
} else {
F_13 ( V_2 -> V_40 , L_22 ) ;
F_15 ( V_2 , V_133 ,
V_134 , 0 ) ;
V_5 -> V_136 . V_137 = false ;
}
}
static int F_34 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_118 ) {
case V_119 :
if ( V_5 -> V_138 ) {
F_15 ( V_2 , V_59 ,
V_139 ,
V_140 ) ;
V_5 -> V_138 = 0 ;
}
if ( V_5 -> V_141 ) {
F_15 ( V_2 , V_142 ,
V_143 ,
V_144 ) ;
V_5 -> V_141 = 0 ;
}
break;
}
F_35 ( V_117 , V_72 , V_118 ) ;
return 0 ;
}
static int F_36 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_118 ) {
case V_120 :
if ( V_5 -> V_145 ) {
F_15 ( V_2 , V_59 ,
V_139 , 0 ) ;
V_5 -> V_145 = 0 ;
}
if ( V_5 -> V_146 ) {
F_15 ( V_2 , V_142 ,
V_143 , 0 ) ;
V_5 -> V_146 = 0 ;
}
break;
}
return 0 ;
}
static int F_37 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_118 ) {
case V_119 :
V_5 -> V_138 = 1 ;
break;
case V_120 :
V_5 -> V_145 = 1 ;
break;
}
return 0 ;
}
static int F_38 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_118 ) {
case V_119 :
V_5 -> V_141 = 1 ;
break;
case V_120 :
V_5 -> V_146 = 1 ;
break;
}
return 0 ;
}
static int F_39 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
F_34 ( V_117 , V_72 , V_118 ) ;
return 0 ;
}
static int F_40 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
F_34 ( V_117 , V_72 , V_118 ) ;
return 0 ;
}
static int F_41 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
unsigned int V_78 = 1 << V_117 -> V_79 ;
F_15 ( V_2 , V_147 ,
V_78 , V_78 ) ;
return 0 ;
}
static int F_42 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_148 * V_149 = F_21 ( V_72 ) ;
struct V_66 * V_117 = V_149 -> V_150 [ 0 ] ;
struct V_1 * V_2 = V_117 -> V_2 ;
int V_38 ;
V_38 = F_43 ( V_72 , V_74 ) ;
F_32 ( V_2 ) ;
return V_38 ;
}
static int F_44 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
F_13 ( V_2 -> V_40 , L_23 ,
F_17 ( V_2 ,
V_33 ) ) ;
return 0 ;
}
static int F_45 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_148 * V_149 = F_21 ( V_72 ) ;
struct V_66 * V_117 = V_149 -> V_150 [ 0 ] ;
struct V_1 * V_2 = V_117 -> V_2 ;
int V_38 ;
V_38 = F_46 ( V_72 , V_74 ) ;
F_32 ( V_2 ) ;
return V_38 ;
}
static int F_47 ( struct V_151 * V_53 ,
int V_152 , int V_153 )
{
T_1 V_154 ;
unsigned int V_155 , V_156 , V_157 ;
F_48 ( L_24 , V_152 , V_153 ) ;
V_53 -> V_158 = 0 ;
while ( V_152 > 13500000 ) {
V_53 -> V_158 ++ ;
V_152 /= 2 ;
if ( V_53 -> V_158 > 3 )
return - V_56 ;
}
F_48 ( L_25 , V_53 -> V_158 , V_152 ) ;
V_53 -> V_159 = 3 ;
while ( V_153 * ( V_53 -> V_159 + 1 ) < 90000000 ) {
V_53 -> V_159 ++ ;
if ( V_53 -> V_159 > 63 )
return - V_56 ;
}
V_153 *= V_53 -> V_159 + 1 ;
F_48 ( L_26 , V_53 -> V_159 , V_153 ) ;
if ( V_152 > 1000000 ) {
V_53 -> V_160 = 0 ;
} else if ( V_152 > 256000 ) {
V_53 -> V_160 = 1 ;
V_152 *= 2 ;
} else if ( V_152 > 128000 ) {
V_53 -> V_160 = 2 ;
V_152 *= 4 ;
} else if ( V_152 > 64000 ) {
V_53 -> V_160 = 3 ;
V_152 *= 8 ;
} else {
V_53 -> V_160 = 4 ;
V_152 *= 16 ;
}
F_48 ( L_27 , V_53 -> V_160 , V_152 ) ;
V_156 = V_153 / V_152 ;
V_53 -> V_161 = V_156 ;
V_157 = V_153 % V_152 ;
F_48 ( L_28 , V_157 ) ;
V_154 = V_162 * ( long long ) V_157 ;
F_49 ( V_154 , V_152 ) ;
V_155 = V_154 & 0xFFFFFFFF ;
if ( ( V_155 % 10 ) >= 5 )
V_155 += 5 ;
V_53 -> V_163 = V_155 / 10 ;
F_48 ( L_29 , V_53 -> V_161 , V_53 -> V_163 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , int V_99 , int V_164 ,
unsigned int V_152 , unsigned int V_153 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_165 , V_38 ;
struct V_151 V_53 ;
T_2 V_3 , V_166 , V_167 ;
V_166 = F_17 ( V_2 , V_59 )
& V_140 ;
V_167 = F_17 ( V_2 , V_142 )
& V_144 ;
switch ( V_99 ) {
case V_168 :
V_165 = 0 ;
V_99 = 0 ;
break;
case V_169 :
V_165 = 0x20 ;
V_99 = 1 ;
break;
default:
return - V_56 ;
}
switch ( V_164 ) {
case 0 :
if ( V_153 )
return - V_56 ;
V_164 = V_5 -> V_53 [ V_99 ] . V_164 ;
break;
case V_170 :
case V_171 :
case V_172 :
case V_173 :
break;
default:
return - V_56 ;
}
if ( V_5 -> V_53 [ V_99 ] . V_164 == V_164 &&
V_5 -> V_53 [ V_99 ] . V_174 == V_152 && V_5 -> V_53 [ V_99 ] . V_54 == V_153 )
return 0 ;
if ( V_153 )
V_38 = F_47 ( & V_53 , V_152 , V_153 ) ;
else
V_38 = F_47 ( & V_53 , V_5 -> V_53 [ V_99 ] . V_174 ,
V_5 -> V_53 [ V_99 ] . V_54 ) ;
if ( V_38 < 0 )
return V_38 ;
F_15 ( V_2 , V_59 ,
V_140 , 0 ) ;
F_15 ( V_2 , V_142 ,
V_144 , 0 ) ;
F_15 ( V_2 , V_175 + V_165 ,
V_176 , 0 ) ;
V_3 = ( V_53 . V_159 << V_177 ) |
( V_53 . V_160 << V_178 ) ;
F_15 ( V_2 , V_179 + V_165 ,
V_180 |
V_181 , V_3 ) ;
F_51 ( V_2 , V_182 + V_165 , V_53 . V_163 ) ;
F_15 ( V_2 , V_183 + V_165 ,
V_184 ,
V_53 . V_161 << V_185 ) ;
F_15 ( V_2 , V_186 + V_165 ,
V_187 |
V_188 ,
( V_53 . V_158 << V_189 ) |
( V_164 - 1 ) ) ;
if ( V_153 ) {
if ( V_53 . V_163 )
V_3 = V_176 | V_190 ;
else
V_3 = V_176 ;
F_15 ( V_2 , V_175 + V_165 ,
V_176 | V_190 ,
V_3 ) ;
F_52 ( 5 ) ;
}
V_5 -> V_53 [ V_99 ] . V_174 = V_152 ;
V_5 -> V_53 [ V_99 ] . V_54 = V_153 ;
V_5 -> V_53 [ V_99 ] . V_164 = V_164 ;
F_15 ( V_2 , V_59 ,
V_140 , V_166 ) ;
F_15 ( V_2 , V_142 ,
V_144 , V_167 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_191 * V_192 , int V_99 , int V_164 ,
unsigned int V_152 , unsigned int V_153 )
{
return F_50 ( V_192 -> V_2 , V_99 , V_164 , V_152 , V_153 ) ;
}
static int F_54 ( struct V_191 * V_192 ,
int V_193 , unsigned int V_194 , int V_195 )
{
struct V_1 * V_2 = V_192 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_92 ;
switch ( V_192 -> V_99 ) {
case 1 :
case 2 :
break;
default:
return - V_56 ;
}
switch ( V_193 ) {
case V_49 :
V_5 -> V_48 [ V_192 -> V_99 - 1 ] = V_49 ;
V_5 -> V_50 [ 0 ] = V_194 ;
F_13 ( V_192 -> V_40 , L_30 ,
V_192 -> V_99 , V_194 ) ;
break;
case V_51 :
V_5 -> V_48 [ V_192 -> V_99 - 1 ] = V_51 ;
V_5 -> V_50 [ 1 ] = V_194 ;
F_13 ( V_192 -> V_40 , L_31 ,
V_192 -> V_99 , V_194 ) ;
break;
case V_52 :
V_5 -> V_48 [ V_192 -> V_99 - 1 ] = V_52 ;
F_13 ( V_192 -> V_40 , L_32 , V_192 -> V_99 ) ;
break;
case V_55 :
V_5 -> V_48 [ V_192 -> V_99 - 1 ] = V_55 ;
F_13 ( V_192 -> V_40 , L_33 , V_192 -> V_99 ) ;
break;
case V_196 :
if ( V_194 ) {
for ( V_92 = 0 ; V_92 < F_55 ( V_197 ) ; V_92 ++ )
if ( V_197 [ V_92 ] == V_194 )
break;
if ( V_92 == F_55 ( V_197 ) )
return - V_56 ;
F_15 ( V_2 , V_198 ,
V_199 , V_92 ) ;
F_15 ( V_2 , V_200 ,
V_201 , V_201 ) ;
} else {
F_15 ( V_2 , V_200 ,
V_201 , 0 ) ;
}
default:
return - V_56 ;
}
F_16 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
enum V_202 V_203 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_203 ) {
case V_204 :
break;
case V_205 :
F_15 ( V_2 , V_206 ,
V_207 , 0x2 ) ;
break;
case V_208 :
if ( V_2 -> V_65 . V_209 == V_210 ) {
F_57 ( V_2 -> V_40 ) ;
switch ( V_6 -> type ) {
case V_211 :
if ( V_5 -> V_212 < 4 ) {
F_51 ( V_2 , 0x102 , 0x3 ) ;
F_51 ( V_2 , 0x56 , 0x3 ) ;
F_51 ( V_2 , 0x817 , 0 ) ;
F_51 ( V_2 , 0x102 , 0 ) ;
}
break;
case V_25 :
if ( V_5 -> V_212 == 0 ) {
F_51 ( V_2 , 0x102 , 0x3 ) ;
F_51 ( V_2 , 0xcb , 0x81 ) ;
F_51 ( V_2 , 0x817 , 0 ) ;
F_51 ( V_2 , 0x102 , 0 ) ;
F_15 ( V_2 ,
V_213 ,
V_214 ,
V_214 ) ;
}
break;
}
F_15 ( V_2 , V_215 ,
V_216 |
V_217 ,
V_216 |
V_217 ) ;
F_15 ( V_2 , V_218 ,
V_219 |
V_220 |
V_221 ,
V_219 |
V_220 |
( 0x11 << V_222 ) ) ;
F_15 ( V_2 , V_206 ,
V_223 |
V_207 ,
V_223 | 0x2 ) ;
F_52 ( 20 ) ;
}
F_15 ( V_2 , V_206 ,
V_207 , 0x4 ) ;
break;
case V_210 :
if ( V_2 -> V_65 . V_209 == V_208 ) {
F_15 ( V_2 , V_218 ,
V_224 |
V_219 |
V_220 |
V_221 ,
V_224 |
V_219 |
V_220 |
( 1 << V_222 ) ) ;
F_15 ( V_2 , V_206 ,
V_223 |
V_207 , 0 ) ;
F_15 ( V_2 , V_215 ,
V_216 |
V_217 ,
V_216 |
V_217 ) ;
F_52 ( 5 ) ;
F_15 ( V_2 , V_218 ,
V_224 |
V_219 |
V_220 |
V_221 , 0 ) ;
V_5 -> V_225 = NULL ;
F_58 ( V_2 -> V_40 ) ;
}
break;
}
V_2 -> V_65 . V_209 = V_203 ;
return 0 ;
}
static int F_59 ( struct V_191 * V_192 , unsigned int V_226 )
{
struct V_1 * V_2 = V_192 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_227 ;
int V_228 ;
int V_229 = 0 ;
int V_166 = 0 ;
switch ( V_192 -> V_99 ) {
case 1 :
V_227 = V_230 ;
V_228 = V_231 ;
break;
case 2 :
V_227 = V_232 ;
V_228 = V_233 ;
break;
default:
return - V_56 ;
}
switch ( V_226 & V_234 ) {
case V_235 :
break;
case V_236 :
V_229 = V_237 ;
break;
default:
return - V_56 ;
}
switch ( V_226 & V_238 ) {
case V_239 :
V_166 |= V_240 ;
case V_241 :
V_166 |= 0x18 ;
break;
case V_242 :
V_166 |= 0x10 ;
break;
case V_243 :
break;
case V_244 :
V_166 |= 0x8 ;
break;
default:
return - V_56 ;
}
switch ( V_226 & V_238 ) {
case V_241 :
case V_239 :
switch ( V_226 & V_245 ) {
case V_246 :
break;
case V_247 :
V_166 |= V_248 ;
break;
default:
return - V_56 ;
}
break;
case V_242 :
case V_243 :
case V_244 :
switch ( V_226 & V_245 ) {
case V_246 :
break;
case V_249 :
V_166 |= V_248 | V_240 ;
break;
case V_247 :
V_166 |= V_248 ;
break;
case V_250 :
V_166 |= V_240 ;
break;
default:
return - V_56 ;
}
break;
default:
return - V_56 ;
}
if ( V_6 -> type == V_25 && V_192 -> V_99 == 2 )
F_15 ( V_2 , V_251 ,
V_240 |
V_252 , V_166 ) ;
F_15 ( V_2 , V_228 ,
V_248 | V_240 |
V_253 ,
V_166 ) ;
F_15 ( V_2 , V_227 , V_237 ,
V_229 ) ;
return 0 ;
}
static int F_60 ( struct V_254 * V_255 ,
struct V_256 * V_257 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = V_192 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_228 ;
int V_258 ;
int V_259 ;
int V_260 ;
int V_261 ;
int V_166 = 0 ;
int V_167 = 0 ;
int V_262 = 0 ;
int V_263 = 0 ;
int V_264 = 0 ;
int V_99 = V_192 -> V_99 - 1 ;
int V_92 , V_265 , V_107 , V_266 , V_106 ;
switch ( V_192 -> V_99 ) {
case 1 :
V_228 = V_231 ;
V_258 = V_267 ;
V_259 = V_268 ;
V_261 = V_269 ;
if ( V_255 -> V_270 == V_271 ||
V_5 -> V_272 [ 0 ] ) {
V_260 = V_273 ;
} else {
V_260 = V_274 ;
F_13 ( V_2 -> V_40 , L_34 ) ;
}
break;
case 2 :
V_228 = V_233 ;
V_258 = V_275 ;
V_259 = V_276 ;
V_261 = V_277 ;
if ( V_255 -> V_270 == V_271 ||
V_5 -> V_272 [ 1 ] ) {
V_260 = V_278 ;
} else {
V_260 = V_279 ;
F_13 ( V_2 -> V_40 , L_35 ) ;
}
break;
case 3 :
switch ( V_6 -> type ) {
case V_25 :
V_228 = V_251 ;
break;
default:
return 0 ;
}
default:
return - V_56 ;
}
V_266 = F_61 ( V_257 ) * 2 ;
switch ( F_62 ( V_257 ) ) {
case V_280 :
V_266 *= 16 ;
break;
case V_281 :
V_266 *= 20 ;
V_166 |= 0x20 ;
break;
case V_282 :
V_266 *= 24 ;
V_166 |= 0x40 ;
break;
case V_283 :
V_266 *= 32 ;
V_166 |= 0x60 ;
break;
default:
return - V_56 ;
}
for ( V_92 = 0 ; V_92 < F_55 ( V_284 ) ; V_92 ++ )
if ( V_284 [ V_92 ] . V_45 == F_61 ( V_257 ) )
break;
if ( V_92 == F_55 ( V_284 ) )
return - V_56 ;
V_264 |= V_284 [ V_92 ] . V_41 << V_285 ;
F_13 ( V_192 -> V_40 , L_36 , V_284 [ V_92 ] . V_45 ) ;
F_13 ( V_192 -> V_40 , L_37 ,
V_192 -> V_99 , V_5 -> V_58 [ V_99 ] , V_266 ) ;
if ( F_63 ( V_257 ) == 1 &&
( F_17 ( V_2 , V_228 ) & 0x18 ) == 0x18 )
V_167 |= V_286 ;
if ( V_5 -> V_58 [ V_99 ] == 0 ) {
F_7 ( V_192 -> V_40 , L_38 , V_192 -> V_99 ) ;
return - V_56 ;
}
V_106 = 0 ;
V_107 = abs ( ( V_287 [ 0 ] * F_61 ( V_257 ) )
- V_5 -> V_58 [ V_99 ] ) ;
for ( V_92 = 1 ; V_92 < F_55 ( V_287 ) ; V_92 ++ ) {
V_265 = abs ( ( V_287 [ V_92 ] * F_61 ( V_257 ) )
- V_5 -> V_58 [ V_99 ] ) ;
if ( V_265 >= V_107 )
continue;
V_106 = V_92 ;
V_107 = V_265 ;
}
F_13 ( V_192 -> V_40 , L_39 ,
V_192 -> V_99 , V_287 [ V_106 ] ) ;
V_264 |= V_106 ;
V_106 = 0 ;
for ( V_92 = 0 ; V_92 < F_55 ( V_288 ) ; V_92 ++ ) {
V_265 = ( V_5 -> V_58 [ V_99 ] * 10 / V_288 [ V_92 ] ) - V_266 ;
if ( V_265 < 0 )
break;
V_106 = V_92 ;
}
V_266 = V_5 -> V_58 [ V_99 ] * 10 / V_288 [ V_106 ] ;
F_13 ( V_192 -> V_40 , L_40 ,
V_288 [ V_106 ] , V_266 ) ;
V_262 |= V_106 << V_289 ;
V_263 = V_266 / F_61 ( V_257 ) ;
F_13 ( V_192 -> V_40 , L_41 ,
V_263 , V_266 / V_263 ) ;
F_15 ( V_2 , V_228 , V_290 , V_166 ) ;
F_15 ( V_2 , V_258 , V_286 , V_167 ) ;
F_15 ( V_2 , V_259 , V_291 , V_262 ) ;
F_15 ( V_2 , V_260 , V_292 ,
V_263 ) ;
F_15 ( V_2 , V_261 , V_293 |
V_294 , V_264 ) ;
if ( V_255 -> V_270 == V_271 ) {
switch ( V_192 -> V_99 ) {
case 1 :
V_5 -> V_114 [ 0 ] = F_61 ( V_257 ) ;
F_27 ( V_2 , 0 ) ;
F_27 ( V_2 , 1 ) ;
break;
case 2 :
V_5 -> V_114 [ 1 ] = F_61 ( V_257 ) ;
F_27 ( V_2 , 2 ) ;
break;
}
}
return 0 ;
}
static int F_64 ( struct V_254 * V_255 ,
struct V_256 * V_257 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = V_192 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_228 ;
int V_166 = 0 ;
switch ( V_192 -> V_99 ) {
case 3 :
switch ( V_6 -> type ) {
case V_25 :
V_228 = V_251 ;
break;
default:
return 0 ;
}
default:
return 0 ;
}
switch ( F_62 ( V_257 ) ) {
case V_280 :
break;
case V_281 :
V_166 |= 0x20 ;
break;
case V_282 :
V_166 |= 0x40 ;
break;
case V_283 :
V_166 |= 0x60 ;
break;
default:
return - V_56 ;
}
return F_15 ( V_2 , V_228 , V_290 , V_166 ) ;
}
static int F_65 ( struct V_191 * V_295 , int V_296 )
{
struct V_1 * V_2 = V_295 -> V_2 ;
int V_297 ;
int V_3 ;
switch ( V_295 -> V_99 ) {
case 1 :
V_297 = V_298 ;
break;
case 2 :
V_297 = V_299 ;
break;
default:
return - V_56 ;
}
if ( V_296 )
V_3 = V_300 ;
else
V_3 = 0 ;
F_15 ( V_2 , V_297 , V_300 , V_3 ) ;
return 0 ;
}
static int F_66 ( struct V_191 * V_295 , int V_301 )
{
struct V_1 * V_2 = V_295 -> V_2 ;
int V_3 , V_41 , V_78 ;
switch ( V_295 -> V_99 ) {
case 1 :
V_3 = V_230 ;
V_78 = V_302 ;
break;
case 2 :
V_3 = V_232 ;
V_78 = V_303 ;
break;
case 3 :
V_3 = V_304 ;
V_78 = V_305 ;
break;
default:
return - V_56 ;
}
if ( V_301 )
V_41 = V_78 ;
else
V_41 = 0 ;
return F_15 ( V_2 , V_3 , V_78 , V_41 ) ;
}
static int F_67 ( struct V_1 * V_2 , T_3 V_306 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_92 , V_38 ;
switch ( V_6 -> type ) {
case V_211 :
F_15 ( V_2 , V_307 , V_308 , 0 ) ;
break;
case V_25 :
F_15 ( V_2 , V_309 ,
V_310 , 0 ) ;
break;
}
for ( V_92 = 0 ; V_92 < F_55 ( V_5 -> V_53 ) ; V_92 ++ ) {
memcpy ( & V_5 -> V_311 [ V_92 ] , & V_5 -> V_53 [ V_92 ] ,
sizeof( struct V_312 ) ) ;
V_38 = F_50 ( V_2 , V_92 + 1 , 0 , 0 , 0 ) ;
if ( V_38 < 0 )
F_14 ( V_2 -> V_40 , L_42 ,
V_92 + 1 , V_38 ) ;
}
F_56 ( V_2 , V_210 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_92 , V_38 ;
unsigned int V_41 , V_78 ;
if ( V_5 -> V_212 < 4 ) {
V_41 = F_11 ( V_2 -> V_7 ,
V_147 ) ;
V_2 -> V_313 = 1 ;
V_78 = V_314 | V_315 |
V_316 | V_317 ;
V_41 &= V_78 ;
F_15 ( V_2 , V_147 ,
V_78 , V_41 ) ;
V_2 -> V_313 = 0 ;
}
V_38 = F_69 ( V_2 ) ;
if ( V_38 != 0 )
F_7 ( V_2 -> V_40 , L_43 , V_38 ) ;
F_56 ( V_2 , V_208 ) ;
for ( V_92 = 0 ; V_92 < F_55 ( V_5 -> V_53 ) ; V_92 ++ ) {
if ( ! V_5 -> V_311 [ V_92 ] . V_54 )
continue;
V_38 = F_50 ( V_2 , V_92 + 1 ,
V_5 -> V_311 [ V_92 ] . V_164 ,
V_5 -> V_311 [ V_92 ] . V_174 ,
V_5 -> V_311 [ V_92 ] . V_54 ) ;
if ( V_38 < 0 )
F_14 ( V_2 -> V_40 , L_44 ,
V_92 + 1 , V_38 ) ;
}
switch ( V_6 -> type ) {
case V_211 :
if ( V_5 -> V_318 [ 0 ] . V_319 || V_5 -> V_318 [ 1 ] . V_319 )
F_15 ( V_2 , V_307 ,
V_308 , V_308 ) ;
break;
case V_25 :
if ( V_5 -> V_320 )
F_15 ( V_2 , V_309 ,
V_310 , V_310 ) ;
break;
}
return 0 ;
}
static void F_70 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_85 * V_86 = V_5 -> V_86 ;
struct V_321 V_322 [] = {
F_71 ( L_11 ,
V_5 -> V_323 ,
F_30 ,
F_29 ) ,
F_71 ( L_12 ,
V_5 -> V_323 ,
F_30 ,
F_29 ) ,
F_71 ( L_13 ,
V_5 -> V_323 ,
F_30 ,
F_29 ) ,
} ;
int V_38 , V_92 , V_324 ;
const char * * V_325 ;
V_5 -> V_108 = 0 ;
V_5 -> V_113 = NULL ;
for ( V_92 = 0 ; V_92 < V_86 -> V_111 ; V_92 ++ ) {
for ( V_324 = 0 ; V_324 < V_5 -> V_108 ; V_324 ++ ) {
if ( strcmp ( V_86 -> V_112 [ V_92 ] . V_70 ,
V_5 -> V_113 [ V_324 ] ) == 0 )
break;
}
if ( V_324 != V_5 -> V_108 )
continue;
V_325 = F_72 ( V_5 -> V_113 ,
sizeof( char * ) *
( V_5 -> V_108 + 1 ) ,
V_326 ) ;
if ( V_325 == NULL )
continue;
V_325 [ V_5 -> V_108 ] =
V_86 -> V_112 [ V_92 ] . V_70 ;
V_5 -> V_108 ++ ;
V_5 -> V_113 = V_325 ;
}
F_13 ( V_2 -> V_40 , L_45 ,
V_5 -> V_108 ) ;
V_5 -> V_323 . V_327 = V_5 -> V_108 ;
V_5 -> V_323 . V_328 = V_5 -> V_113 ;
V_38 = F_73 ( V_5 -> V_2 , V_322 ,
F_55 ( V_322 ) ) ;
if ( V_38 != 0 )
F_7 ( V_5 -> V_2 -> V_40 ,
L_46 , V_38 ) ;
}
static void F_74 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_85 * V_86 = V_5 -> V_86 ;
int V_38 , V_92 ;
if ( ! V_86 )
return;
F_75 ( V_2 , V_86 -> V_329 ,
V_86 -> V_330 ,
V_86 -> V_331 ,
V_86 -> V_332 ,
V_86 -> V_333 ,
V_86 -> V_334 ,
V_86 -> V_335 ,
V_86 -> V_336 ) ;
F_13 ( V_2 -> V_40 , L_47 , V_86 -> V_100 ) ;
if ( V_86 -> V_100 ) {
struct V_321 V_322 [] = {
F_71 ( L_7 , V_5 -> V_337 ,
F_26 , F_25 ) ,
F_71 ( L_8 , V_5 -> V_337 ,
F_26 , F_25 ) ,
F_71 ( L_9 , V_5 -> V_337 ,
F_26 , F_25 ) ,
} ;
V_5 -> V_338 = F_76 ( sizeof( char * )
* V_86 -> V_100 , V_326 ) ;
if ( ! V_5 -> V_338 ) {
F_7 ( V_5 -> V_2 -> V_40 ,
L_48 ,
V_86 -> V_100 ) ;
return;
}
for ( V_92 = 0 ; V_92 < V_86 -> V_100 ; V_92 ++ )
V_5 -> V_338 [ V_92 ] = V_86 -> V_97 [ V_92 ] . V_70 ;
V_5 -> V_337 . V_327 = V_86 -> V_100 ;
V_5 -> V_337 . V_328 = V_5 -> V_338 ;
V_38 = F_73 ( V_5 -> V_2 , V_322 ,
F_55 ( V_322 ) ) ;
if ( V_38 != 0 )
F_7 ( V_5 -> V_2 -> V_40 ,
L_49 , V_38 ) ;
for ( V_92 = 0 ; V_92 < V_339 ; V_92 ++ )
F_23 ( V_2 , V_92 ) ;
}
F_13 ( V_2 -> V_40 , L_50 ,
V_86 -> V_111 ) ;
if ( V_86 -> V_111 )
F_70 ( V_5 ) ;
else
F_73 ( V_5 -> V_2 , V_340 ,
F_55 ( V_340 ) ) ;
for ( V_92 = 0 ; V_92 < F_55 ( V_86 -> V_341 ) ; V_92 ++ ) {
if ( V_86 -> V_341 [ V_92 ] ) {
F_51 ( V_2 , V_342 + V_92 ,
V_86 -> V_341 [ V_92 ] & 0xffff ) ;
}
}
}
int F_77 ( struct V_1 * V_2 , struct V_343 * V_319 ,
int V_341 , int V_344 , int V_345 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_346 * V_318 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_3 ;
if ( V_6 -> type != V_211 )
return - V_56 ;
switch ( V_341 ) {
case 1 :
V_318 = & V_5 -> V_318 [ 0 ] ;
break;
case 2 :
V_318 = & V_5 -> V_318 [ 1 ] ;
break;
default:
return - V_56 ;
}
F_13 ( V_2 -> V_40 , L_51 ,
V_341 , V_344 , V_345 ) ;
V_318 -> V_319 = V_319 ;
V_318 -> V_344 = V_344 ;
V_318 -> V_345 = V_345 ;
if ( V_5 -> V_318 [ 0 ] . V_319 || V_5 -> V_318 [ 1 ] . V_319 )
V_3 = V_308 ;
else
V_3 = 0 ;
F_15 ( V_2 , V_307 , V_308 , V_3 ) ;
return 0 ;
}
static T_4 F_78 ( int V_347 , void * V_348 )
{
struct V_4 * V_349 = V_348 ;
struct V_1 * V_2 = V_349 -> V_2 ;
int V_3 ;
int V_350 ;
#ifndef F_79
F_80 ( F_81 ( V_2 -> V_40 ) ) ;
#endif
V_3 = F_17 ( V_2 , V_21 ) ;
if ( V_3 < 0 ) {
F_7 ( V_2 -> V_40 , L_52 ,
V_3 ) ;
return V_351 ;
}
F_13 ( V_2 -> V_40 , L_53 , V_3 ) ;
V_350 = 0 ;
if ( V_3 & V_352 )
V_350 |= V_349 -> V_318 [ 0 ] . V_344 ;
if ( V_3 & V_353 )
V_350 |= V_349 -> V_318 [ 0 ] . V_345 ;
F_82 ( V_349 -> V_318 [ 0 ] . V_319 , V_350 ,
V_349 -> V_318 [ 0 ] . V_344 | V_349 -> V_318 [ 0 ] . V_345 ) ;
V_350 = 0 ;
if ( V_3 & V_354 )
V_350 |= V_349 -> V_318 [ 1 ] . V_344 ;
if ( V_3 & V_355 )
V_350 |= V_349 -> V_318 [ 1 ] . V_345 ;
F_82 ( V_349 -> V_318 [ 1 ] . V_319 , V_350 ,
V_349 -> V_318 [ 1 ] . V_344 | V_349 -> V_318 [ 1 ] . V_345 ) ;
return V_351 ;
}
static void F_83 ( T_2 V_356 , void * V_348 )
{
struct V_1 * V_2 = V_348 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_350 = 0 ;
if ( ! ( V_356 & V_357 ) )
goto V_358;
V_350 = V_359 ;
if ( V_356 & 0x1c )
V_350 |= V_360 ;
V_358:
F_82 ( V_5 -> V_318 [ 0 ] . V_319 , V_350 ,
V_360 | V_359 ) ;
}
int F_84 ( struct V_1 * V_2 , struct V_343 * V_319 ,
T_5 V_361 , void * V_362 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> type != V_25 )
return - V_56 ;
if ( V_319 ) {
if ( ! V_361 ) {
F_13 ( V_2 -> V_40 , L_54 ) ;
V_361 = F_83 ;
V_362 = V_2 ;
}
V_5 -> V_318 [ 0 ] . V_319 = V_319 ;
V_5 -> V_320 = V_361 ;
V_5 -> V_363 = V_362 ;
F_15 ( V_2 , V_309 ,
V_310 , V_310 ) ;
} else {
F_15 ( V_2 , V_309 ,
V_310 , 0 ) ;
}
return 0 ;
}
static T_4 F_85 ( int V_347 , void * V_348 )
{
struct V_4 * V_5 = V_348 ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_3 ;
V_3 = F_17 ( V_2 , V_36 ) ;
if ( V_3 < 0 ) {
F_7 ( V_2 -> V_40 , L_55 ,
V_3 ) ;
return V_364 ;
}
if ( ! ( V_3 & V_365 ) ) {
F_13 ( V_2 -> V_40 , L_56 ) ;
goto V_54;
}
#ifndef F_79
F_80 ( F_81 ( V_2 -> V_40 ) ) ;
#endif
if ( V_5 -> V_320 )
V_5 -> V_320 ( V_3 , V_5 -> V_363 ) ;
else
F_14 ( V_2 -> V_40 , L_57 ) ;
V_54:
return V_351 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_4 * V_5 ;
struct V_366 * V_65 = & V_2 -> V_65 ;
int V_38 , V_92 ;
V_2 -> V_7 = F_87 ( V_2 -> V_40 -> V_367 ) ;
V_6 = V_2 -> V_7 ;
V_5 = F_88 ( sizeof( struct V_4 ) , V_326 ) ;
if ( V_5 == NULL )
return - V_368 ;
F_89 ( V_2 , V_5 ) ;
V_5 -> V_86 = F_90 ( V_2 -> V_40 -> V_367 ) ;
V_5 -> V_2 = V_2 ;
if ( V_5 -> V_86 && V_5 -> V_86 -> V_369 )
V_5 -> V_369 = V_5 -> V_86 -> V_369 ;
else if ( V_5 -> V_86 && V_5 -> V_86 -> V_370 )
V_5 -> V_369 = V_5 -> V_86 -> V_370 +
V_371 ;
F_91 ( V_2 -> V_40 ) ;
F_92 ( V_2 -> V_40 ) ;
for ( V_92 = 0 ; V_92 < V_26 ; V_92 ++ ) {
if ( ! F_1 ( V_2 , V_92 ) || F_3 ( V_2 , V_92 ) )
continue;
V_38 = F_11 ( V_2 -> V_7 , V_92 ) ;
if ( V_38 <= 0 )
continue;
V_38 = F_6 ( V_2 , V_92 , V_38 ) ;
if ( V_38 != 0 ) {
F_7 ( V_2 -> V_40 ,
L_58 ,
V_92 , V_38 ) ;
goto V_372;
}
}
V_5 -> V_212 = F_17 ( V_2 , V_30 ) ;
switch ( V_6 -> type ) {
case V_211 :
switch ( V_5 -> V_212 ) {
case 2 :
case 3 :
V_5 -> V_136 . V_373 = - 5 ;
V_5 -> V_136 . V_374 = 1 ;
V_5 -> V_136 . V_375 = 1 ;
break;
default:
V_5 -> V_136 . V_375 = 1 ;
break;
}
case V_25 :
V_5 -> V_136 . V_375 = 1 ;
break;
default:
break;
}
switch ( V_6 -> type ) {
case V_211 :
if ( V_5 -> V_369 ) {
V_38 = F_93 ( V_5 -> V_369 , NULL ,
F_78 ,
V_376 ,
L_59 ,
V_5 ) ;
if ( V_38 != 0 )
F_14 ( V_2 -> V_40 ,
L_60 ,
V_38 ) ;
}
V_38 = F_94 ( V_2 -> V_7 ,
V_377 ,
F_78 , L_61 ,
V_5 ) ;
if ( V_38 != 0 )
F_14 ( V_2 -> V_40 ,
L_62 ,
V_38 ) ;
V_38 = F_94 ( V_2 -> V_7 ,
V_378 ,
F_78 , L_63 ,
V_5 ) ;
if ( V_38 != 0 )
F_14 ( V_2 -> V_40 ,
L_64 ,
V_38 ) ;
V_38 = F_94 ( V_2 -> V_7 ,
V_379 ,
F_78 , L_65 ,
V_5 ) ;
if ( V_38 != 0 )
F_14 ( V_2 -> V_40 ,
L_66 ,
V_38 ) ;
break;
case V_25 :
if ( V_5 -> V_369 ) {
V_38 = F_93 ( V_5 -> V_369 , NULL ,
F_85 ,
V_376 ,
L_67 ,
V_5 ) ;
if ( V_38 != 0 )
F_14 ( V_2 -> V_40 ,
L_68 ,
V_38 ) ;
}
}
V_38 = F_11 ( V_2 -> V_7 , V_8 ) ;
if ( V_38 < 0 ) {
F_7 ( V_2 -> V_40 , L_69 , V_38 ) ;
goto V_380;
}
if ( ( V_38 & V_381 ) != V_382 ) {
V_5 -> V_272 [ 0 ] = 1 ;
V_383 [ 0 ] . V_384 = 1 ;
} else {
V_5 -> V_272 [ 0 ] = 0 ;
}
V_38 = F_11 ( V_2 -> V_7 , V_13 ) ;
if ( V_38 < 0 ) {
F_7 ( V_2 -> V_40 , L_70 , V_38 ) ;
goto V_380;
}
if ( ( V_38 & V_381 ) != V_382 ) {
V_5 -> V_272 [ 1 ] = 1 ;
V_383 [ 1 ] . V_384 = 1 ;
} else {
V_5 -> V_272 [ 1 ] = 0 ;
}
F_56 ( V_2 , V_208 ) ;
F_15 ( V_2 , V_385 ,
V_386 , V_386 ) ;
F_15 ( V_2 , V_387 ,
V_386 , V_386 ) ;
F_15 ( V_2 , V_388 ,
V_389 , V_389 ) ;
F_15 ( V_2 , V_390 ,
V_389 , V_389 ) ;
F_15 ( V_2 , V_391 ,
V_392 , V_392 ) ;
F_15 ( V_2 , V_393 ,
V_392 , V_392 ) ;
F_15 ( V_2 , V_394 ,
V_395 , V_395 ) ;
F_15 ( V_2 , V_396 ,
V_395 , V_395 ) ;
F_15 ( V_2 , V_397 ,
V_398 , V_398 ) ;
F_15 ( V_2 , V_399 ,
V_398 , V_398 ) ;
F_15 ( V_2 , V_400 ,
V_401 , V_398 ) ;
F_15 ( V_2 , V_402 ,
V_401 , V_398 ) ;
F_15 ( V_2 , V_403 ,
V_404 , V_404 ) ;
F_15 ( V_2 , V_405 ,
V_404 , V_404 ) ;
F_15 ( V_2 , V_406 ,
V_407 , V_407 ) ;
F_15 ( V_2 , V_408 ,
V_407 , V_407 ) ;
F_15 ( V_2 , V_409 ,
1 << V_410 ,
1 << V_410 ) ;
F_15 ( V_2 , V_411 ,
1 << V_412 ,
1 << V_412 ) ;
F_15 ( V_2 , V_413 ,
1 << V_414 ,
1 << V_414 ) ;
F_15 ( V_2 , V_231 ,
V_415 , V_415 ) ;
F_32 ( V_2 ) ;
F_74 ( V_5 ) ;
F_95 ( V_2 ) ;
F_73 ( V_2 , V_416 ,
F_55 ( V_416 ) ) ;
F_96 ( V_65 , V_417 ,
F_55 ( V_417 ) ) ;
switch ( V_6 -> type ) {
case V_211 :
F_96 ( V_65 , V_418 ,
F_55 ( V_418 ) ) ;
if ( V_5 -> V_212 < 4 ) {
F_96 ( V_65 , V_419 ,
F_55 ( V_419 ) ) ;
F_96 ( V_65 , V_420 ,
F_55 ( V_420 ) ) ;
F_96 ( V_65 , V_421 ,
F_55 ( V_421 ) ) ;
} else {
F_96 ( V_65 , V_422 ,
F_55 ( V_422 ) ) ;
F_96 ( V_65 , V_423 ,
F_55 ( V_423 ) ) ;
F_96 ( V_65 , V_424 ,
F_55 ( V_424 ) ) ;
}
break;
case V_25 :
F_73 ( V_2 , V_425 ,
F_55 ( V_425 ) ) ;
F_96 ( V_65 , V_426 ,
F_55 ( V_426 ) ) ;
if ( V_5 -> V_212 < 1 ) {
F_96 ( V_65 , V_419 ,
F_55 ( V_419 ) ) ;
F_96 ( V_65 , V_420 ,
F_55 ( V_420 ) ) ;
F_96 ( V_65 , V_421 ,
F_55 ( V_421 ) ) ;
} else {
F_96 ( V_65 , V_422 ,
F_55 ( V_422 ) ) ;
F_96 ( V_65 , V_423 ,
F_55 ( V_423 ) ) ;
F_96 ( V_65 , V_424 ,
F_55 ( V_424 ) ) ;
}
break;
}
F_97 ( V_2 , 0 , 0 ) ;
F_98 ( V_65 , V_427 , F_55 ( V_427 ) ) ;
switch ( V_6 -> type ) {
case V_211 :
F_98 ( V_65 , V_428 ,
F_55 ( V_428 ) ) ;
if ( V_5 -> V_212 < 4 ) {
F_98 ( V_65 , V_429 ,
F_55 ( V_429 ) ) ;
F_98 ( V_65 , V_430 ,
F_55 ( V_430 ) ) ;
} else {
F_98 ( V_65 , V_431 ,
F_55 ( V_431 ) ) ;
}
break;
case V_25 :
if ( V_5 -> V_212 < 1 ) {
F_98 ( V_65 , V_429 ,
F_55 ( V_429 ) ) ;
F_98 ( V_65 , V_430 ,
F_55 ( V_430 ) ) ;
} else {
F_98 ( V_65 , V_431 ,
F_55 ( V_431 ) ) ;
F_98 ( V_65 , V_432 ,
F_55 ( V_432 ) ) ;
}
F_99 ( V_2 ) ;
break;
}
return 0 ;
V_380:
F_100 ( V_2 -> V_7 , V_379 , V_5 ) ;
F_100 ( V_2 -> V_7 , V_378 , V_5 ) ;
F_100 ( V_2 -> V_7 , V_377 , V_5 ) ;
if ( V_5 -> V_369 )
F_101 ( V_5 -> V_369 , V_5 ) ;
V_372:
F_102 ( V_5 ) ;
return V_38 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_56 ( V_2 , V_210 ) ;
F_104 ( V_2 -> V_40 ) ;
switch ( V_6 -> type ) {
case V_211 :
if ( V_5 -> V_369 )
F_101 ( V_5 -> V_369 , V_5 ) ;
F_100 ( V_2 -> V_7 , V_378 ,
V_5 ) ;
F_100 ( V_2 -> V_7 , V_377 ,
V_5 ) ;
F_100 ( V_2 -> V_7 , V_371 ,
V_5 ) ;
break;
case V_25 :
if ( V_5 -> V_369 )
F_101 ( V_5 -> V_369 , V_5 ) ;
break;
}
if ( V_5 -> V_433 )
F_105 ( V_5 -> V_433 ) ;
if ( V_5 -> V_434 )
F_105 ( V_5 -> V_434 ) ;
if ( V_5 -> V_435 )
F_105 ( V_5 -> V_435 ) ;
F_102 ( V_5 -> V_113 ) ;
F_102 ( V_5 -> V_338 ) ;
F_102 ( V_5 ) ;
return 0 ;
}
static int T_6 F_106 ( struct V_436 * V_437 )
{
return F_107 ( & V_437 -> V_40 , & V_438 ,
V_383 , F_55 ( V_383 ) ) ;
}
static int T_7 F_108 ( struct V_436 * V_437 )
{
F_109 ( & V_437 -> V_40 ) ;
return 0 ;
}
static T_8 int F_110 ( void )
{
return F_111 ( & V_439 ) ;
}
static T_9 void F_112 ( void )
{
F_113 ( & V_439 ) ;
}

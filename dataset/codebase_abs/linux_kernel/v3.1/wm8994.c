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
V_5 -> V_58 [ V_44 ] = V_45 ;
F_14 ( V_2 , V_59 + V_47 ,
V_60 | V_57 ,
V_46 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
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
V_61 = F_16 ( V_2 , V_64 ) & V_63 ;
if ( V_61 == V_62 )
return 0 ;
F_14 ( V_2 , V_64 , V_63 , V_62 ) ;
F_17 ( & V_2 -> V_65 ) ;
return 0 ;
}
static int F_18 ( struct V_66 * V_67 ,
struct V_66 * V_68 )
{
int V_3 = F_16 ( V_67 -> V_2 , V_64 ) ;
const char * V_69 ;
if ( V_3 & V_63 )
V_69 = L_4 ;
else
V_69 = L_5 ;
return strcmp ( V_67 -> V_70 , V_69 ) == 0 ;
}
static int F_19 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_75 * V_76 =
(struct V_75 * ) V_72 -> V_77 ;
struct V_1 * V_2 = F_20 ( V_72 ) ;
int V_78 , V_38 ;
if ( V_76 -> V_79 == V_80 )
V_78 = V_81 |
V_82 ;
else
V_78 = V_83 ;
V_38 = F_16 ( V_2 , V_76 -> V_3 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 & V_78 )
return - V_56 ;
return F_21 ( V_72 , V_74 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_84 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_85 * V_86 = V_5 -> V_86 ;
int V_87 = V_88 [ V_84 ] ;
int V_89 = V_5 -> V_90 [ V_84 ] ;
int V_91 , V_92 ;
V_91 = F_16 ( V_2 , V_87 ) ;
V_91 &= V_93 | V_94 |
V_95 ;
for ( V_92 = 0 ; V_92 < V_96 ; V_92 ++ )
F_14 ( V_2 , V_87 + V_92 , 0xffff ,
V_86 -> V_97 [ V_89 ] . V_98 [ V_92 ] ) ;
F_14 ( V_2 , V_87 , V_93 |
V_94 |
V_95 , V_91 ) ;
}
static int F_23 ( const char * V_70 )
{
if ( strcmp ( V_70 , L_6 ) == 0 )
return 0 ;
if ( strcmp ( V_70 , L_7 ) == 0 )
return 1 ;
if ( strcmp ( V_70 , L_8 ) == 0 )
return 2 ;
return - V_56 ;
}
static int F_24 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_20 ( V_72 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_85 * V_86 = V_5 -> V_86 ;
int V_84 = F_23 ( V_72 -> V_99 . V_70 ) ;
int V_37 = V_74 -> V_37 . integer . V_37 [ 0 ] ;
if ( V_84 < 0 )
return V_84 ;
if ( V_37 >= V_86 -> V_100 )
return - V_56 ;
V_5 -> V_90 [ V_84 ] = V_37 ;
F_22 ( V_2 , V_84 ) ;
return 0 ;
}
static int F_25 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_20 ( V_72 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_84 = F_23 ( V_72 -> V_99 . V_70 ) ;
V_74 -> V_37 . V_101 . V_102 [ 0 ] = V_5 -> V_90 [ V_84 ] ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 , int V_103 )
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
F_13 ( V_2 -> V_40 , L_9 ,
V_103 ,
V_86 -> V_112 [ V_106 ] . V_70 ,
V_86 -> V_112 [ V_106 ] . V_45 ,
V_5 -> V_114 [ V_105 ] ) ;
V_91 = F_16 ( V_2 , V_87 ) ;
V_91 &= V_115 ;
for ( V_92 = 0 ; V_92 < V_116 ; V_92 ++ )
F_14 ( V_2 , V_87 + V_92 , 0xffff ,
V_86 -> V_112 [ V_106 ] . V_98 [ V_92 ] ) ;
F_14 ( V_2 , V_87 , V_115 , V_91 ) ;
}
static int F_27 ( const char * V_70 )
{
if ( strcmp ( V_70 , L_10 ) == 0 )
return 0 ;
if ( strcmp ( V_70 , L_11 ) == 0 )
return 1 ;
if ( strcmp ( V_70 , L_12 ) == 0 )
return 2 ;
return - V_56 ;
}
static int F_28 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_20 ( V_72 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_85 * V_86 = V_5 -> V_86 ;
int V_103 = F_27 ( V_72 -> V_99 . V_70 ) ;
int V_37 = V_74 -> V_37 . integer . V_37 [ 0 ] ;
if ( V_103 < 0 )
return V_103 ;
if ( V_37 >= V_86 -> V_111 )
return - V_56 ;
V_5 -> V_109 [ V_103 ] = V_37 ;
F_26 ( V_2 , V_103 ) ;
return 0 ;
}
static int F_29 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_20 ( V_72 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_103 = F_27 ( V_72 -> V_99 . V_70 ) ;
V_74 -> V_37 . V_101 . V_102 [ 0 ] = V_5 -> V_109 [ V_103 ] ;
return 0 ;
}
static int F_30 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
switch ( V_118 ) {
case V_119 :
return F_15 ( V_2 ) ;
case V_120 :
F_15 ( V_2 ) ;
break;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_121 = 1 ;
int V_67 = 0 ;
int V_3 , V_122 ;
V_3 = F_16 ( V_2 , V_123 ) ;
if ( ! ( V_3 & V_124 ) ) {
F_32 ( V_2 -> V_40 , L_13 ) ;
V_121 = 0 ;
}
V_3 = F_16 ( V_2 , V_125 ) ;
if ( ! ( V_3 & V_126 ) ) {
F_32 ( V_2 -> V_40 , L_14 ) ;
V_121 = 0 ;
}
V_3 = F_16 ( V_2 , V_127 ) ;
switch ( V_3 ) {
case V_128 :
F_32 ( V_2 -> V_40 , L_15 ) ;
V_67 = 2 << V_129 ;
break;
case V_130 :
F_32 ( V_2 -> V_40 , L_16 ) ;
V_67 = 1 << V_129 ;
break;
case V_131 :
F_32 ( V_2 -> V_40 , L_17 ) ;
V_67 = 0 << V_129 ;
break;
default:
F_32 ( V_2 -> V_40 , L_18 , V_3 ) ;
V_121 = 0 ;
break;
}
V_122 = F_16 ( V_2 , V_132 ) ;
if ( V_122 != V_3 ) {
F_32 ( V_2 -> V_40 , L_19 ) ;
V_121 = 0 ;
}
if ( V_121 ) {
F_13 ( V_2 -> V_40 , L_20 ) ;
F_14 ( V_2 , V_133 ,
V_134 |
V_135 ,
V_67 | V_134 ) ;
V_5 -> V_136 . V_137 = true ;
} else {
F_13 ( V_2 -> V_40 , L_21 ) ;
F_14 ( V_2 , V_133 ,
V_134 , 0 ) ;
V_5 -> V_136 . V_137 = false ;
}
}
static int F_33 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_118 ) {
case V_119 :
if ( V_5 -> V_138 ) {
F_14 ( V_2 , V_59 ,
V_139 ,
V_140 ) ;
V_5 -> V_138 = 0 ;
}
if ( V_5 -> V_141 ) {
F_14 ( V_2 , V_142 ,
V_143 ,
V_144 ) ;
V_5 -> V_141 = 0 ;
}
break;
}
F_34 ( V_117 , V_72 , V_118 ) ;
return 0 ;
}
static int F_35 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_118 ) {
case V_120 :
if ( V_5 -> V_145 ) {
F_14 ( V_2 , V_59 ,
V_139 , 0 ) ;
V_5 -> V_145 = 0 ;
}
if ( V_5 -> V_146 ) {
F_14 ( V_2 , V_142 ,
V_143 , 0 ) ;
V_5 -> V_146 = 0 ;
}
break;
}
return 0 ;
}
static int F_36 ( struct V_66 * V_117 ,
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
static int F_37 ( struct V_66 * V_117 ,
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
static int F_38 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
F_33 ( V_117 , V_72 , V_118 ) ;
return 0 ;
}
static int F_39 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
F_33 ( V_117 , V_72 , V_118 ) ;
return 0 ;
}
static int F_40 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
unsigned int V_78 = 1 << V_117 -> V_79 ;
F_14 ( V_2 , V_147 ,
V_78 , V_78 ) ;
return 0 ;
}
static int F_41 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_148 * V_149 = F_20 ( V_72 ) ;
struct V_66 * V_117 = V_149 -> V_150 [ 0 ] ;
struct V_1 * V_2 = V_117 -> V_2 ;
int V_38 ;
V_38 = F_42 ( V_72 , V_74 ) ;
F_31 ( V_2 ) ;
return V_38 ;
}
static int F_43 ( struct V_66 * V_117 ,
struct V_71 * V_72 , int V_118 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
F_13 ( V_2 -> V_40 , L_22 ,
F_16 ( V_2 ,
V_33 ) ) ;
return 0 ;
}
static int F_44 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_148 * V_149 = F_20 ( V_72 ) ;
struct V_66 * V_117 = V_149 -> V_150 [ 0 ] ;
struct V_1 * V_2 = V_117 -> V_2 ;
int V_38 ;
V_38 = F_45 ( V_72 , V_74 ) ;
F_31 ( V_2 ) ;
return V_38 ;
}
static int F_46 ( struct V_151 * V_53 ,
int V_152 , int V_153 )
{
T_1 V_154 ;
unsigned int V_155 , V_156 , V_157 ;
F_47 ( L_23 , V_152 , V_153 ) ;
V_53 -> V_158 = 0 ;
while ( V_152 > 13500000 ) {
V_53 -> V_158 ++ ;
V_152 /= 2 ;
if ( V_53 -> V_158 > 3 )
return - V_56 ;
}
F_47 ( L_24 , V_53 -> V_158 , V_152 ) ;
V_53 -> V_159 = 3 ;
while ( V_153 * ( V_53 -> V_159 + 1 ) < 90000000 ) {
V_53 -> V_159 ++ ;
if ( V_53 -> V_159 > 63 )
return - V_56 ;
}
V_153 *= V_53 -> V_159 + 1 ;
F_47 ( L_25 , V_53 -> V_159 , V_153 ) ;
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
F_47 ( L_26 , V_53 -> V_160 , V_152 ) ;
V_156 = V_153 / V_152 ;
V_53 -> V_161 = V_156 ;
V_157 = V_153 % V_152 ;
F_47 ( L_27 , V_157 ) ;
V_154 = V_162 * ( long long ) V_157 ;
F_48 ( V_154 , V_152 ) ;
V_155 = V_154 & 0xFFFFFFFF ;
if ( ( V_155 % 10 ) >= 5 )
V_155 += 5 ;
V_53 -> V_163 = V_155 / 10 ;
F_47 ( L_28 , V_53 -> V_161 , V_53 -> V_163 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , int V_99 , int V_164 ,
unsigned int V_152 , unsigned int V_153 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_165 , V_38 ;
struct V_151 V_53 ;
T_2 V_3 , V_166 , V_167 ;
unsigned long V_168 ;
V_166 = F_16 ( V_2 , V_59 )
& V_140 ;
V_167 = F_16 ( V_2 , V_142 )
& V_144 ;
switch ( V_99 ) {
case V_169 :
V_165 = 0 ;
V_99 = 0 ;
break;
case V_170 :
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
case V_171 :
case V_172 :
case V_173 :
case V_174 :
break;
default:
return - V_56 ;
}
if ( V_5 -> V_53 [ V_99 ] . V_164 == V_164 &&
V_5 -> V_53 [ V_99 ] . V_175 == V_152 && V_5 -> V_53 [ V_99 ] . V_54 == V_153 )
return 0 ;
if ( V_153 )
V_38 = F_46 ( & V_53 , V_152 , V_153 ) ;
else
V_38 = F_46 ( & V_53 , V_5 -> V_53 [ V_99 ] . V_175 ,
V_5 -> V_53 [ V_99 ] . V_54 ) ;
if ( V_38 < 0 )
return V_38 ;
F_14 ( V_2 , V_59 ,
V_140 , 0 ) ;
F_14 ( V_2 , V_142 ,
V_144 , 0 ) ;
F_14 ( V_2 , V_176 + V_165 ,
V_177 , 0 ) ;
V_3 = ( V_53 . V_159 << V_178 ) |
( V_53 . V_160 << V_179 ) ;
F_14 ( V_2 , V_180 + V_165 ,
V_181 |
V_182 , V_3 ) ;
F_50 ( V_2 , V_183 + V_165 , V_53 . V_163 ) ;
F_14 ( V_2 , V_184 + V_165 ,
V_185 ,
V_53 . V_161 << V_186 ) ;
F_14 ( V_2 , V_187 + V_165 ,
V_188 |
V_189 ,
( V_53 . V_158 << V_190 ) |
( V_164 - 1 ) ) ;
F_51 ( & V_5 -> V_191 [ V_99 ] ) ;
if ( V_153 ) {
if ( V_53 . V_163 )
V_3 = V_177 | V_192 ;
else
V_3 = V_177 ;
F_14 ( V_2 , V_176 + V_165 ,
V_177 | V_192 ,
V_3 ) ;
if ( V_5 -> V_193 ) {
V_168 = F_52 ( & V_5 -> V_191 [ V_99 ] ,
F_53 ( 10 ) ) ;
if ( V_168 == 0 )
F_54 ( V_2 -> V_40 ,
L_29 ) ;
} else {
F_55 ( 5 ) ;
}
}
V_5 -> V_53 [ V_99 ] . V_175 = V_152 ;
V_5 -> V_53 [ V_99 ] . V_54 = V_153 ;
V_5 -> V_53 [ V_99 ] . V_164 = V_164 ;
F_14 ( V_2 , V_59 ,
V_140 , V_166 ) ;
F_14 ( V_2 , V_142 ,
V_144 , V_167 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static T_3 F_56 ( int V_194 , void * V_195 )
{
struct V_196 * V_196 = V_195 ;
F_57 ( V_196 ) ;
return V_197 ;
}
static int F_58 ( struct V_198 * V_199 , int V_99 , int V_164 ,
unsigned int V_152 , unsigned int V_153 )
{
return F_49 ( V_199 -> V_2 , V_99 , V_164 , V_152 , V_153 ) ;
}
static int F_59 ( struct V_198 * V_199 ,
int V_200 , unsigned int V_201 , int V_202 )
{
struct V_1 * V_2 = V_199 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_92 ;
switch ( V_199 -> V_99 ) {
case 1 :
case 2 :
break;
default:
return - V_56 ;
}
switch ( V_200 ) {
case V_49 :
V_5 -> V_48 [ V_199 -> V_99 - 1 ] = V_49 ;
V_5 -> V_50 [ 0 ] = V_201 ;
F_13 ( V_199 -> V_40 , L_30 ,
V_199 -> V_99 , V_201 ) ;
break;
case V_51 :
V_5 -> V_48 [ V_199 -> V_99 - 1 ] = V_51 ;
V_5 -> V_50 [ 1 ] = V_201 ;
F_13 ( V_199 -> V_40 , L_31 ,
V_199 -> V_99 , V_201 ) ;
break;
case V_52 :
V_5 -> V_48 [ V_199 -> V_99 - 1 ] = V_52 ;
F_13 ( V_199 -> V_40 , L_32 , V_199 -> V_99 ) ;
break;
case V_55 :
V_5 -> V_48 [ V_199 -> V_99 - 1 ] = V_55 ;
F_13 ( V_199 -> V_40 , L_33 , V_199 -> V_99 ) ;
break;
case V_203 :
if ( V_201 ) {
for ( V_92 = 0 ; V_92 < F_60 ( V_204 ) ; V_92 ++ )
if ( V_204 [ V_92 ] == V_201 )
break;
if ( V_92 == F_60 ( V_204 ) )
return - V_56 ;
F_14 ( V_2 , V_205 ,
V_206 , V_92 ) ;
F_14 ( V_2 , V_207 ,
V_208 , V_208 ) ;
} else {
F_14 ( V_2 , V_207 ,
V_208 , 0 ) ;
}
default:
return - V_56 ;
}
F_15 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
enum V_209 V_210 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_210 ) {
case V_211 :
break;
case V_212 :
F_14 ( V_2 , V_213 ,
V_214 , 0x2 ) ;
break;
case V_215 :
if ( V_2 -> V_65 . V_216 == V_217 ) {
F_62 ( V_2 -> V_40 ) ;
switch ( V_6 -> type ) {
case V_218 :
if ( V_5 -> V_219 < 4 ) {
F_50 ( V_2 , 0x102 , 0x3 ) ;
F_50 ( V_2 , 0x56 , 0x3 ) ;
F_50 ( V_2 , 0x817 , 0 ) ;
F_50 ( V_2 , 0x102 , 0 ) ;
}
break;
case V_25 :
if ( V_5 -> V_219 == 0 ) {
F_50 ( V_2 , 0x102 , 0x3 ) ;
F_50 ( V_2 , 0xcb , 0x81 ) ;
F_50 ( V_2 , 0x817 , 0 ) ;
F_50 ( V_2 , 0x102 , 0 ) ;
F_14 ( V_2 ,
V_220 ,
V_221 ,
V_221 ) ;
}
break;
}
F_14 ( V_2 , V_222 ,
V_223 |
V_224 ,
V_223 |
V_224 ) ;
F_14 ( V_2 , V_225 ,
V_226 |
V_227 |
V_228 ,
V_226 |
V_227 |
( 0x11 << V_229 ) ) ;
F_14 ( V_2 , V_213 ,
V_230 |
V_214 ,
V_230 | 0x2 ) ;
F_55 ( 20 ) ;
}
F_14 ( V_2 , V_213 ,
V_214 , 0x4 ) ;
break;
case V_217 :
if ( V_2 -> V_65 . V_216 == V_215 ) {
F_14 ( V_2 , V_225 ,
V_231 |
V_226 |
V_227 |
V_228 ,
V_231 |
V_226 |
V_227 |
( 1 << V_229 ) ) ;
F_14 ( V_2 , V_213 ,
V_230 |
V_214 , 0 ) ;
F_14 ( V_2 , V_222 ,
V_223 |
V_224 ,
V_223 |
V_224 ) ;
F_55 ( 5 ) ;
F_14 ( V_2 , V_225 ,
V_231 |
V_226 |
V_227 |
V_228 , 0 ) ;
V_5 -> V_232 = NULL ;
F_63 ( V_2 -> V_40 ) ;
}
break;
}
V_2 -> V_65 . V_216 = V_210 ;
return 0 ;
}
static int F_64 ( struct V_198 * V_199 , unsigned int V_233 )
{
struct V_1 * V_2 = V_199 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_234 ;
int V_235 ;
int V_236 = 0 ;
int V_166 = 0 ;
switch ( V_199 -> V_99 ) {
case 1 :
V_234 = V_237 ;
V_235 = V_238 ;
break;
case 2 :
V_234 = V_239 ;
V_235 = V_240 ;
break;
default:
return - V_56 ;
}
switch ( V_233 & V_241 ) {
case V_242 :
break;
case V_243 :
V_236 = V_244 ;
break;
default:
return - V_56 ;
}
switch ( V_233 & V_245 ) {
case V_246 :
V_166 |= V_247 ;
case V_248 :
V_166 |= 0x18 ;
break;
case V_249 :
V_166 |= 0x10 ;
break;
case V_250 :
break;
case V_251 :
V_166 |= 0x8 ;
break;
default:
return - V_56 ;
}
switch ( V_233 & V_245 ) {
case V_248 :
case V_246 :
switch ( V_233 & V_252 ) {
case V_253 :
break;
case V_254 :
V_166 |= V_255 ;
break;
default:
return - V_56 ;
}
break;
case V_249 :
case V_250 :
case V_251 :
switch ( V_233 & V_252 ) {
case V_253 :
break;
case V_256 :
V_166 |= V_255 | V_247 ;
break;
case V_254 :
V_166 |= V_255 ;
break;
case V_257 :
V_166 |= V_247 ;
break;
default:
return - V_56 ;
}
break;
default:
return - V_56 ;
}
if ( V_6 -> type == V_25 && V_199 -> V_99 == 2 )
F_14 ( V_2 , V_258 ,
V_247 |
V_259 , V_166 ) ;
F_14 ( V_2 , V_235 ,
V_255 | V_247 |
V_260 ,
V_166 ) ;
F_14 ( V_2 , V_234 , V_244 ,
V_236 ) ;
return 0 ;
}
static int F_65 ( struct V_261 * V_262 ,
struct V_263 * V_264 ,
struct V_198 * V_199 )
{
struct V_1 * V_2 = V_199 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_235 ;
int V_265 ;
int V_266 ;
int V_267 ;
int V_268 ;
int V_166 = 0 ;
int V_167 = 0 ;
int V_269 = 0 ;
int V_270 = 0 ;
int V_271 = 0 ;
int V_99 = V_199 -> V_99 - 1 ;
int V_92 , V_272 , V_107 , V_273 , V_106 ;
switch ( V_199 -> V_99 ) {
case 1 :
V_235 = V_238 ;
V_265 = V_274 ;
V_266 = V_275 ;
V_268 = V_276 ;
if ( V_262 -> V_277 == V_278 ||
V_5 -> V_279 [ 0 ] ) {
V_267 = V_280 ;
} else {
V_267 = V_281 ;
F_13 ( V_2 -> V_40 , L_34 ) ;
}
break;
case 2 :
V_235 = V_240 ;
V_265 = V_282 ;
V_266 = V_283 ;
V_268 = V_284 ;
if ( V_262 -> V_277 == V_278 ||
V_5 -> V_279 [ 1 ] ) {
V_267 = V_285 ;
} else {
V_267 = V_286 ;
F_13 ( V_2 -> V_40 , L_35 ) ;
}
break;
case 3 :
switch ( V_6 -> type ) {
case V_25 :
V_235 = V_258 ;
break;
default:
return 0 ;
}
default:
return - V_56 ;
}
V_273 = F_66 ( V_264 ) * 2 ;
switch ( F_67 ( V_264 ) ) {
case V_287 :
V_273 *= 16 ;
break;
case V_288 :
V_273 *= 20 ;
V_166 |= 0x20 ;
break;
case V_289 :
V_273 *= 24 ;
V_166 |= 0x40 ;
break;
case V_290 :
V_273 *= 32 ;
V_166 |= 0x60 ;
break;
default:
return - V_56 ;
}
for ( V_92 = 0 ; V_92 < F_60 ( V_291 ) ; V_92 ++ )
if ( V_291 [ V_92 ] . V_45 == F_66 ( V_264 ) )
break;
if ( V_92 == F_60 ( V_291 ) )
return - V_56 ;
V_271 |= V_291 [ V_92 ] . V_41 << V_292 ;
F_13 ( V_199 -> V_40 , L_36 , V_291 [ V_92 ] . V_45 ) ;
F_13 ( V_199 -> V_40 , L_37 ,
V_199 -> V_99 , V_5 -> V_58 [ V_99 ] , V_273 ) ;
if ( F_68 ( V_264 ) == 1 &&
( F_16 ( V_2 , V_235 ) & 0x18 ) == 0x18 )
V_167 |= V_293 ;
if ( V_5 -> V_58 [ V_99 ] == 0 ) {
F_7 ( V_199 -> V_40 , L_38 , V_199 -> V_99 ) ;
return - V_56 ;
}
V_106 = 0 ;
V_107 = abs ( ( V_294 [ 0 ] * F_66 ( V_264 ) )
- V_5 -> V_58 [ V_99 ] ) ;
for ( V_92 = 1 ; V_92 < F_60 ( V_294 ) ; V_92 ++ ) {
V_272 = abs ( ( V_294 [ V_92 ] * F_66 ( V_264 ) )
- V_5 -> V_58 [ V_99 ] ) ;
if ( V_272 >= V_107 )
continue;
V_106 = V_92 ;
V_107 = V_272 ;
}
F_13 ( V_199 -> V_40 , L_39 ,
V_199 -> V_99 , V_294 [ V_106 ] ) ;
V_271 |= V_106 ;
V_106 = 0 ;
for ( V_92 = 0 ; V_92 < F_60 ( V_295 ) ; V_92 ++ ) {
V_272 = ( V_5 -> V_58 [ V_99 ] * 10 / V_295 [ V_92 ] ) - V_273 ;
if ( V_272 < 0 )
break;
V_106 = V_92 ;
}
V_273 = V_5 -> V_58 [ V_99 ] * 10 / V_295 [ V_106 ] ;
F_13 ( V_199 -> V_40 , L_40 ,
V_295 [ V_106 ] , V_273 ) ;
V_269 |= V_106 << V_296 ;
V_270 = V_273 / F_66 ( V_264 ) ;
F_13 ( V_199 -> V_40 , L_41 ,
V_270 , V_273 / V_270 ) ;
F_14 ( V_2 , V_235 , V_297 , V_166 ) ;
F_14 ( V_2 , V_265 , V_293 , V_167 ) ;
F_14 ( V_2 , V_266 , V_298 , V_269 ) ;
F_14 ( V_2 , V_267 , V_299 ,
V_270 ) ;
F_14 ( V_2 , V_268 , V_300 |
V_301 , V_271 ) ;
if ( V_262 -> V_277 == V_278 ) {
switch ( V_199 -> V_99 ) {
case 1 :
V_5 -> V_114 [ 0 ] = F_66 ( V_264 ) ;
F_26 ( V_2 , 0 ) ;
F_26 ( V_2 , 1 ) ;
break;
case 2 :
V_5 -> V_114 [ 1 ] = F_66 ( V_264 ) ;
F_26 ( V_2 , 2 ) ;
break;
}
}
return 0 ;
}
static int F_69 ( struct V_261 * V_262 ,
struct V_263 * V_264 ,
struct V_198 * V_199 )
{
struct V_1 * V_2 = V_199 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_235 ;
int V_166 = 0 ;
switch ( V_199 -> V_99 ) {
case 3 :
switch ( V_6 -> type ) {
case V_25 :
V_235 = V_258 ;
break;
default:
return 0 ;
}
default:
return 0 ;
}
switch ( F_67 ( V_264 ) ) {
case V_287 :
break;
case V_288 :
V_166 |= 0x20 ;
break;
case V_289 :
V_166 |= 0x40 ;
break;
case V_290 :
V_166 |= 0x60 ;
break;
default:
return - V_56 ;
}
return F_14 ( V_2 , V_235 , V_297 , V_166 ) ;
}
static void F_70 ( struct V_261 * V_262 ,
struct V_198 * V_199 )
{
struct V_1 * V_2 = V_199 -> V_2 ;
int V_268 = 0 ;
switch ( V_199 -> V_99 ) {
case 1 :
V_268 = V_276 ;
break;
case 2 :
V_268 = V_276 ;
break;
default:
break;
}
if ( V_268 && ! V_199 -> V_302 && ! V_199 -> V_303 )
F_14 ( V_2 , V_268 ,
V_300 |
V_301 , 0x9 ) ;
}
static int F_71 ( struct V_198 * V_304 , int V_305 )
{
struct V_1 * V_2 = V_304 -> V_2 ;
int V_306 ;
int V_3 ;
switch ( V_304 -> V_99 ) {
case 1 :
V_306 = V_307 ;
break;
case 2 :
V_306 = V_308 ;
break;
default:
return - V_56 ;
}
if ( V_305 )
V_3 = V_309 ;
else
V_3 = 0 ;
F_14 ( V_2 , V_306 , V_309 , V_3 ) ;
return 0 ;
}
static int F_72 ( struct V_198 * V_304 , int V_310 )
{
struct V_1 * V_2 = V_304 -> V_2 ;
int V_3 , V_41 , V_78 ;
switch ( V_304 -> V_99 ) {
case 1 :
V_3 = V_237 ;
V_78 = V_311 ;
break;
case 2 :
V_3 = V_239 ;
V_78 = V_312 ;
break;
case 3 :
V_3 = V_313 ;
V_78 = V_314 ;
break;
default:
return - V_56 ;
}
if ( V_310 )
V_41 = V_78 ;
else
V_41 = 0 ;
return F_14 ( V_2 , V_3 , V_78 , V_41 ) ;
}
static int F_73 ( struct V_1 * V_2 , T_4 V_315 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_92 , V_38 ;
switch ( V_6 -> type ) {
case V_218 :
F_14 ( V_2 , V_316 , V_317 , 0 ) ;
break;
case V_25 :
F_14 ( V_2 , V_318 ,
V_319 , 0 ) ;
break;
}
for ( V_92 = 0 ; V_92 < F_60 ( V_5 -> V_53 ) ; V_92 ++ ) {
memcpy ( & V_5 -> V_320 [ V_92 ] , & V_5 -> V_53 [ V_92 ] ,
sizeof( struct V_321 ) ) ;
V_38 = F_49 ( V_2 , V_92 + 1 , 0 , 0 , 0 ) ;
if ( V_38 < 0 )
F_54 ( V_2 -> V_40 , L_42 ,
V_92 + 1 , V_38 ) ;
}
F_61 ( V_2 , V_217 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_92 , V_38 ;
unsigned int V_41 , V_78 ;
if ( V_5 -> V_219 < 4 ) {
V_41 = F_11 ( V_2 -> V_7 ,
V_147 ) ;
V_2 -> V_322 = 1 ;
V_78 = V_323 | V_324 |
V_325 | V_326 ;
V_41 &= V_78 ;
F_14 ( V_2 , V_147 ,
V_78 , V_41 ) ;
V_2 -> V_322 = 0 ;
}
V_38 = F_75 ( V_2 ) ;
if ( V_38 != 0 )
F_7 ( V_2 -> V_40 , L_43 , V_38 ) ;
F_61 ( V_2 , V_215 ) ;
for ( V_92 = 0 ; V_92 < F_60 ( V_5 -> V_53 ) ; V_92 ++ ) {
if ( ! V_5 -> V_320 [ V_92 ] . V_54 )
continue;
V_38 = F_49 ( V_2 , V_92 + 1 ,
V_5 -> V_320 [ V_92 ] . V_164 ,
V_5 -> V_320 [ V_92 ] . V_175 ,
V_5 -> V_320 [ V_92 ] . V_54 ) ;
if ( V_38 < 0 )
F_54 ( V_2 -> V_40 , L_44 ,
V_92 + 1 , V_38 ) ;
}
switch ( V_6 -> type ) {
case V_218 :
if ( V_5 -> V_327 [ 0 ] . V_328 || V_5 -> V_327 [ 1 ] . V_328 )
F_14 ( V_2 , V_316 ,
V_317 , V_317 ) ;
break;
case V_25 :
if ( V_5 -> V_329 )
F_14 ( V_2 , V_318 ,
V_319 , V_319 ) ;
break;
}
return 0 ;
}
static void F_76 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_85 * V_86 = V_5 -> V_86 ;
struct V_330 V_331 [] = {
F_77 ( L_10 ,
V_5 -> V_332 ,
F_29 ,
F_28 ) ,
F_77 ( L_11 ,
V_5 -> V_332 ,
F_29 ,
F_28 ) ,
F_77 ( L_12 ,
V_5 -> V_332 ,
F_29 ,
F_28 ) ,
} ;
int V_38 , V_92 , V_333 ;
const char * * V_334 ;
V_5 -> V_108 = 0 ;
V_5 -> V_113 = NULL ;
for ( V_92 = 0 ; V_92 < V_86 -> V_111 ; V_92 ++ ) {
for ( V_333 = 0 ; V_333 < V_5 -> V_108 ; V_333 ++ ) {
if ( strcmp ( V_86 -> V_112 [ V_92 ] . V_70 ,
V_5 -> V_113 [ V_333 ] ) == 0 )
break;
}
if ( V_333 != V_5 -> V_108 )
continue;
V_334 = F_78 ( V_5 -> V_113 ,
sizeof( char * ) *
( V_5 -> V_108 + 1 ) ,
V_335 ) ;
if ( V_334 == NULL )
continue;
V_334 [ V_5 -> V_108 ] =
V_86 -> V_112 [ V_92 ] . V_70 ;
V_5 -> V_108 ++ ;
V_5 -> V_113 = V_334 ;
}
F_13 ( V_2 -> V_40 , L_45 ,
V_5 -> V_108 ) ;
V_5 -> V_332 . V_336 = V_5 -> V_108 ;
V_5 -> V_332 . V_337 = V_5 -> V_113 ;
V_38 = F_79 ( V_5 -> V_2 , V_331 ,
F_60 ( V_331 ) ) ;
if ( V_38 != 0 )
F_7 ( V_5 -> V_2 -> V_40 ,
L_46 , V_38 ) ;
}
static void F_80 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_85 * V_86 = V_5 -> V_86 ;
int V_38 , V_92 ;
if ( ! V_86 )
return;
F_81 ( V_2 , V_86 -> V_338 ,
V_86 -> V_339 ,
V_86 -> V_340 ,
V_86 -> V_341 ,
V_86 -> V_342 ,
V_86 -> V_343 ,
V_86 -> V_344 ,
V_86 -> V_345 ) ;
F_13 ( V_2 -> V_40 , L_47 , V_86 -> V_100 ) ;
if ( V_86 -> V_100 ) {
struct V_330 V_331 [] = {
F_77 ( L_6 , V_5 -> V_346 ,
F_25 , F_24 ) ,
F_77 ( L_7 , V_5 -> V_346 ,
F_25 , F_24 ) ,
F_77 ( L_8 , V_5 -> V_346 ,
F_25 , F_24 ) ,
} ;
V_5 -> V_347 = F_82 ( sizeof( char * )
* V_86 -> V_100 , V_335 ) ;
if ( ! V_5 -> V_347 ) {
F_7 ( V_5 -> V_2 -> V_40 ,
L_48 ,
V_86 -> V_100 ) ;
return;
}
for ( V_92 = 0 ; V_92 < V_86 -> V_100 ; V_92 ++ )
V_5 -> V_347 [ V_92 ] = V_86 -> V_97 [ V_92 ] . V_70 ;
V_5 -> V_346 . V_336 = V_86 -> V_100 ;
V_5 -> V_346 . V_337 = V_5 -> V_347 ;
V_38 = F_79 ( V_5 -> V_2 , V_331 ,
F_60 ( V_331 ) ) ;
if ( V_38 != 0 )
F_7 ( V_5 -> V_2 -> V_40 ,
L_49 , V_38 ) ;
for ( V_92 = 0 ; V_92 < V_348 ; V_92 ++ )
F_22 ( V_2 , V_92 ) ;
}
F_13 ( V_2 -> V_40 , L_50 ,
V_86 -> V_111 ) ;
if ( V_86 -> V_111 )
F_76 ( V_5 ) ;
else
F_79 ( V_5 -> V_2 , V_349 ,
F_60 ( V_349 ) ) ;
for ( V_92 = 0 ; V_92 < F_60 ( V_86 -> V_350 ) ; V_92 ++ ) {
if ( V_86 -> V_350 [ V_92 ] ) {
F_50 ( V_2 , V_351 + V_92 ,
V_86 -> V_350 [ V_92 ] & 0xffff ) ;
}
}
}
int F_83 ( struct V_1 * V_2 , struct V_352 * V_328 ,
int V_350 , int V_353 , int V_354 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_355 * V_327 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_3 ;
if ( V_6 -> type != V_218 )
return - V_56 ;
switch ( V_350 ) {
case 1 :
V_327 = & V_5 -> V_327 [ 0 ] ;
break;
case 2 :
V_327 = & V_5 -> V_327 [ 1 ] ;
break;
default:
return - V_56 ;
}
F_13 ( V_2 -> V_40 , L_51 ,
V_350 , V_353 , V_354 ) ;
V_327 -> V_328 = V_328 ;
V_327 -> V_353 = V_353 ;
V_327 -> V_354 = V_354 ;
if ( V_5 -> V_327 [ 0 ] . V_328 || V_5 -> V_327 [ 1 ] . V_328 )
V_3 = V_317 ;
else
V_3 = 0 ;
F_14 ( V_2 , V_316 , V_317 , V_3 ) ;
return 0 ;
}
static T_3 F_84 ( int V_194 , void * V_195 )
{
struct V_4 * V_356 = V_195 ;
struct V_1 * V_2 = V_356 -> V_2 ;
int V_3 ;
int V_357 ;
#ifndef F_85
F_86 ( F_87 ( V_2 -> V_40 ) ) ;
#endif
V_3 = F_16 ( V_2 , V_21 ) ;
if ( V_3 < 0 ) {
F_7 ( V_2 -> V_40 , L_52 ,
V_3 ) ;
return V_197 ;
}
F_13 ( V_2 -> V_40 , L_53 , V_3 ) ;
V_357 = 0 ;
if ( V_3 & V_358 )
V_357 |= V_356 -> V_327 [ 0 ] . V_353 ;
if ( V_3 & V_359 )
V_357 |= V_356 -> V_327 [ 0 ] . V_354 ;
F_88 ( V_356 -> V_327 [ 0 ] . V_328 , V_357 ,
V_356 -> V_327 [ 0 ] . V_353 | V_356 -> V_327 [ 0 ] . V_354 ) ;
V_357 = 0 ;
if ( V_3 & V_360 )
V_357 |= V_356 -> V_327 [ 1 ] . V_353 ;
if ( V_3 & V_361 )
V_357 |= V_356 -> V_327 [ 1 ] . V_354 ;
F_88 ( V_356 -> V_327 [ 1 ] . V_328 , V_357 ,
V_356 -> V_327 [ 1 ] . V_353 | V_356 -> V_327 [ 1 ] . V_354 ) ;
return V_197 ;
}
static void F_89 ( T_2 V_362 , void * V_195 )
{
struct V_1 * V_2 = V_195 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_357 = 0 ;
if ( ! ( V_362 & V_363 ) )
goto V_364;
V_357 = V_365 ;
if ( V_362 & 0x1c )
V_357 |= V_366 ;
V_364:
F_88 ( V_5 -> V_327 [ 0 ] . V_328 , V_357 ,
V_366 | V_365 ) ;
}
int F_90 ( struct V_1 * V_2 , struct V_352 * V_328 ,
T_5 V_367 , void * V_368 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> type != V_25 )
return - V_56 ;
if ( V_328 ) {
if ( ! V_367 ) {
F_13 ( V_2 -> V_40 , L_54 ) ;
V_367 = F_89 ;
V_368 = V_2 ;
}
V_5 -> V_327 [ 0 ] . V_328 = V_328 ;
V_5 -> V_329 = V_367 ;
V_5 -> V_369 = V_368 ;
F_14 ( V_2 , V_318 ,
V_319 , V_319 ) ;
} else {
F_14 ( V_2 , V_318 ,
V_319 , 0 ) ;
}
return 0 ;
}
static T_3 F_91 ( int V_194 , void * V_195 )
{
struct V_4 * V_5 = V_195 ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_3 ;
V_3 = F_16 ( V_2 , V_36 ) ;
if ( V_3 < 0 ) {
F_7 ( V_2 -> V_40 , L_55 ,
V_3 ) ;
return V_370 ;
}
if ( ! ( V_3 & V_371 ) ) {
F_13 ( V_2 -> V_40 , L_56 ) ;
goto V_54;
}
#ifndef F_85
F_86 ( F_87 ( V_2 -> V_40 ) ) ;
#endif
if ( V_5 -> V_329 )
V_5 -> V_329 ( V_3 , V_5 -> V_369 ) ;
else
F_54 ( V_2 -> V_40 , L_57 ) ;
V_54:
return V_197 ;
}
static T_3 F_92 ( int V_194 , void * V_195 )
{
struct V_1 * V_2 = V_195 ;
F_7 ( V_2 -> V_40 , L_58 ) ;
return V_197 ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_4 * V_5 ;
struct V_372 * V_65 = & V_2 -> V_65 ;
int V_38 , V_92 ;
V_2 -> V_7 = F_94 ( V_2 -> V_40 -> V_373 ) ;
V_6 = V_2 -> V_7 ;
V_5 = F_95 ( sizeof( struct V_4 ) , V_335 ) ;
if ( V_5 == NULL )
return - V_374 ;
F_96 ( V_2 , V_5 ) ;
V_5 -> V_86 = F_97 ( V_2 -> V_40 -> V_373 ) ;
V_5 -> V_2 = V_2 ;
for ( V_92 = 0 ; V_92 < F_60 ( V_5 -> V_191 ) ; V_92 ++ )
F_98 ( & V_5 -> V_191 [ V_92 ] ) ;
if ( V_5 -> V_86 && V_5 -> V_86 -> V_375 )
V_5 -> V_375 = V_5 -> V_86 -> V_375 ;
else if ( V_5 -> V_86 && V_5 -> V_86 -> V_376 )
V_5 -> V_375 = V_5 -> V_86 -> V_376 +
V_377 ;
F_99 ( V_2 -> V_40 ) ;
F_100 ( V_2 -> V_40 ) ;
for ( V_92 = 0 ; V_92 < V_26 ; V_92 ++ ) {
if ( ! F_1 ( V_2 , V_92 ) || F_3 ( V_2 , V_92 ) )
continue;
V_38 = F_11 ( V_2 -> V_7 , V_92 ) ;
if ( V_38 <= 0 )
continue;
V_38 = F_6 ( V_2 , V_92 , V_38 ) ;
if ( V_38 != 0 ) {
F_7 ( V_2 -> V_40 ,
L_59 ,
V_92 , V_38 ) ;
goto V_378;
}
}
V_5 -> V_219 = F_16 ( V_2 , V_30 ) ;
switch ( V_6 -> type ) {
case V_218 :
switch ( V_5 -> V_219 ) {
case 2 :
case 3 :
V_5 -> V_136 . V_379 = - 5 ;
V_5 -> V_136 . V_380 = 1 ;
V_5 -> V_136 . V_381 = 1 ;
V_5 -> V_136 . V_382 = 1 ;
break;
default:
V_5 -> V_136 . V_381 = 1 ;
break;
}
break;
case V_25 :
V_5 -> V_136 . V_381 = 1 ;
break;
default:
break;
}
F_101 ( V_2 -> V_7 , V_383 ,
F_92 , L_60 , V_2 ) ;
V_38 = F_101 ( V_2 -> V_7 , V_384 ,
V_385 , L_61 ,
& V_5 -> V_136 ) ;
if ( V_38 == 0 )
V_5 -> V_136 . V_386 = true ;
switch ( V_6 -> type ) {
case V_218 :
if ( V_5 -> V_375 ) {
V_38 = F_102 ( V_5 -> V_375 , NULL ,
F_84 ,
V_387 ,
L_62 ,
V_5 ) ;
if ( V_38 != 0 )
F_54 ( V_2 -> V_40 ,
L_63 ,
V_38 ) ;
}
V_38 = F_101 ( V_2 -> V_7 ,
V_388 ,
F_84 , L_64 ,
V_5 ) ;
if ( V_38 != 0 )
F_54 ( V_2 -> V_40 ,
L_65 ,
V_38 ) ;
V_38 = F_101 ( V_2 -> V_7 ,
V_389 ,
F_84 , L_66 ,
V_5 ) ;
if ( V_38 != 0 )
F_54 ( V_2 -> V_40 ,
L_67 ,
V_38 ) ;
V_38 = F_101 ( V_2 -> V_7 ,
V_390 ,
F_84 , L_68 ,
V_5 ) ;
if ( V_38 != 0 )
F_54 ( V_2 -> V_40 ,
L_69 ,
V_38 ) ;
break;
case V_25 :
if ( V_5 -> V_375 ) {
V_38 = F_102 ( V_5 -> V_375 , NULL ,
F_91 ,
V_387 ,
L_70 ,
V_5 ) ;
if ( V_38 != 0 )
F_54 ( V_2 -> V_40 ,
L_71 ,
V_38 ) ;
}
}
V_5 -> V_193 = true ;
for ( V_92 = 0 ; V_92 < F_60 ( V_5 -> V_191 ) ; V_92 ++ ) {
V_38 = F_101 ( V_2 -> V_7 ,
V_391 + V_92 ,
F_56 , L_72 ,
& V_5 -> V_191 [ V_92 ] ) ;
if ( V_38 != 0 )
V_5 -> V_193 = false ;
}
V_38 = F_11 ( V_2 -> V_7 , V_8 ) ;
if ( V_38 < 0 ) {
F_7 ( V_2 -> V_40 , L_73 , V_38 ) ;
goto V_392;
}
if ( ( V_38 & V_393 ) != V_394 ) {
V_5 -> V_279 [ 0 ] = 1 ;
V_395 [ 0 ] . V_396 = 1 ;
} else {
V_5 -> V_279 [ 0 ] = 0 ;
}
V_38 = F_11 ( V_2 -> V_7 , V_13 ) ;
if ( V_38 < 0 ) {
F_7 ( V_2 -> V_40 , L_74 , V_38 ) ;
goto V_392;
}
if ( ( V_38 & V_393 ) != V_394 ) {
V_5 -> V_279 [ 1 ] = 1 ;
V_395 [ 1 ] . V_396 = 1 ;
} else {
V_5 -> V_279 [ 1 ] = 0 ;
}
F_61 ( V_2 , V_215 ) ;
F_14 ( V_2 , V_397 ,
V_398 , V_398 ) ;
F_14 ( V_2 , V_399 ,
V_398 , V_398 ) ;
F_14 ( V_2 , V_400 ,
V_401 , V_401 ) ;
F_14 ( V_2 , V_402 ,
V_401 , V_401 ) ;
F_14 ( V_2 , V_403 ,
V_404 , V_404 ) ;
F_14 ( V_2 , V_405 ,
V_404 , V_404 ) ;
F_14 ( V_2 , V_406 ,
V_407 , V_407 ) ;
F_14 ( V_2 , V_408 ,
V_407 , V_407 ) ;
F_14 ( V_2 , V_409 ,
V_410 , V_410 ) ;
F_14 ( V_2 , V_411 ,
V_410 , V_410 ) ;
F_14 ( V_2 , V_412 ,
V_413 , V_410 ) ;
F_14 ( V_2 , V_414 ,
V_413 , V_410 ) ;
F_14 ( V_2 , V_415 ,
V_416 , V_416 ) ;
F_14 ( V_2 , V_417 ,
V_416 , V_416 ) ;
F_14 ( V_2 , V_418 ,
V_419 , V_419 ) ;
F_14 ( V_2 , V_420 ,
V_419 , V_419 ) ;
F_14 ( V_2 , V_421 ,
1 << V_422 ,
1 << V_422 ) ;
F_14 ( V_2 , V_423 ,
1 << V_424 ,
1 << V_424 ) ;
F_14 ( V_2 , V_425 ,
1 << V_426 ,
1 << V_426 ) ;
switch ( V_6 -> type ) {
case V_218 :
case V_25 :
F_14 ( V_2 , V_238 ,
V_427 , V_427 ) ;
break;
default:
break;
}
F_31 ( V_2 ) ;
F_80 ( V_5 ) ;
F_103 ( V_2 ) ;
F_79 ( V_2 , V_428 ,
F_60 ( V_428 ) ) ;
F_104 ( V_65 , V_429 ,
F_60 ( V_429 ) ) ;
switch ( V_6 -> type ) {
case V_218 :
F_104 ( V_65 , V_430 ,
F_60 ( V_430 ) ) ;
if ( V_5 -> V_219 < 4 ) {
F_104 ( V_65 , V_431 ,
F_60 ( V_431 ) ) ;
F_104 ( V_65 , V_432 ,
F_60 ( V_432 ) ) ;
F_104 ( V_65 , V_433 ,
F_60 ( V_433 ) ) ;
} else {
F_104 ( V_65 , V_434 ,
F_60 ( V_434 ) ) ;
F_104 ( V_65 , V_435 ,
F_60 ( V_435 ) ) ;
F_104 ( V_65 , V_436 ,
F_60 ( V_436 ) ) ;
}
break;
case V_25 :
F_79 ( V_2 , V_437 ,
F_60 ( V_437 ) ) ;
F_104 ( V_65 , V_438 ,
F_60 ( V_438 ) ) ;
if ( V_5 -> V_219 < 1 ) {
F_104 ( V_65 , V_431 ,
F_60 ( V_431 ) ) ;
F_104 ( V_65 , V_432 ,
F_60 ( V_432 ) ) ;
F_104 ( V_65 , V_433 ,
F_60 ( V_433 ) ) ;
} else {
F_104 ( V_65 , V_434 ,
F_60 ( V_434 ) ) ;
F_104 ( V_65 , V_435 ,
F_60 ( V_435 ) ) ;
F_104 ( V_65 , V_436 ,
F_60 ( V_436 ) ) ;
}
break;
}
F_105 ( V_2 , 0 , 0 ) ;
F_106 ( V_65 , V_439 , F_60 ( V_439 ) ) ;
switch ( V_6 -> type ) {
case V_218 :
F_106 ( V_65 , V_440 ,
F_60 ( V_440 ) ) ;
if ( V_5 -> V_219 < 4 ) {
F_106 ( V_65 , V_441 ,
F_60 ( V_441 ) ) ;
F_106 ( V_65 , V_442 ,
F_60 ( V_442 ) ) ;
} else {
F_106 ( V_65 , V_443 ,
F_60 ( V_443 ) ) ;
}
break;
case V_25 :
if ( V_5 -> V_219 < 1 ) {
F_106 ( V_65 , V_441 ,
F_60 ( V_441 ) ) ;
F_106 ( V_65 , V_442 ,
F_60 ( V_442 ) ) ;
} else {
F_106 ( V_65 , V_443 ,
F_60 ( V_443 ) ) ;
F_106 ( V_65 , V_444 ,
F_60 ( V_444 ) ) ;
}
F_107 ( V_2 ) ;
break;
}
return 0 ;
V_392:
F_108 ( V_2 -> V_7 , V_390 , V_5 ) ;
F_108 ( V_2 -> V_7 , V_389 , V_5 ) ;
F_108 ( V_2 -> V_7 , V_388 , V_5 ) ;
if ( V_5 -> V_375 )
F_109 ( V_5 -> V_375 , V_5 ) ;
for ( V_92 = 0 ; V_92 < F_60 ( V_5 -> V_191 ) ; V_92 ++ )
F_108 ( V_2 -> V_7 , V_391 + V_92 ,
& V_5 -> V_191 [ V_92 ] ) ;
F_108 ( V_2 -> V_7 , V_384 ,
& V_5 -> V_136 ) ;
F_108 ( V_2 -> V_7 , V_383 , V_2 ) ;
V_378:
F_110 ( V_5 ) ;
return V_38 ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_92 ;
F_61 ( V_2 , V_217 ) ;
F_112 ( V_2 -> V_40 ) ;
for ( V_92 = 0 ; V_92 < F_60 ( V_5 -> V_191 ) ; V_92 ++ )
F_108 ( V_2 -> V_7 , V_391 + V_92 ,
& V_5 -> V_191 [ V_92 ] ) ;
F_108 ( V_2 -> V_7 , V_384 ,
& V_5 -> V_136 ) ;
F_108 ( V_2 -> V_7 , V_383 , V_2 ) ;
switch ( V_6 -> type ) {
case V_218 :
if ( V_5 -> V_375 )
F_109 ( V_5 -> V_375 , V_5 ) ;
F_108 ( V_2 -> V_7 , V_389 ,
V_5 ) ;
F_108 ( V_2 -> V_7 , V_388 ,
V_5 ) ;
F_108 ( V_2 -> V_7 , V_377 ,
V_5 ) ;
break;
case V_25 :
if ( V_5 -> V_375 )
F_109 ( V_5 -> V_375 , V_5 ) ;
break;
}
if ( V_5 -> V_445 )
F_113 ( V_5 -> V_445 ) ;
if ( V_5 -> V_446 )
F_113 ( V_5 -> V_446 ) ;
if ( V_5 -> V_447 )
F_113 ( V_5 -> V_447 ) ;
F_110 ( V_5 -> V_113 ) ;
F_110 ( V_5 -> V_347 ) ;
F_110 ( V_5 ) ;
return 0 ;
}
static int T_6 F_114 ( struct V_448 * V_449 )
{
return F_115 ( & V_449 -> V_40 , & V_450 ,
V_395 , F_60 ( V_395 ) ) ;
}
static int T_7 F_116 ( struct V_448 * V_449 )
{
F_117 ( & V_449 -> V_40 ) ;
return 0 ;
}
static T_8 int F_118 ( void )
{
return F_119 ( & V_451 ) ;
}
static T_9 void F_120 ( void )
{
F_121 ( & V_451 ) ;
}

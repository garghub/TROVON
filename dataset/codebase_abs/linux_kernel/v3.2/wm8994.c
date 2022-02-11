static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
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
case V_37 :
return 1 ;
default:
return 0 ;
}
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_38 )
{
int V_39 ;
F_5 ( V_3 > V_40 ) ;
if ( ! F_3 ( V_2 , V_3 ) ) {
V_39 = F_6 ( V_2 , V_3 , V_38 ) ;
if ( V_39 != 0 )
F_7 ( V_2 -> V_41 , L_1 ,
V_3 , V_39 ) ;
}
return F_8 ( V_2 -> V_7 , V_3 , V_38 ) ;
}
static unsigned int F_9 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_42 ;
int V_39 ;
F_5 ( V_3 > V_40 ) ;
if ( ! F_3 ( V_2 , V_3 ) && F_1 ( V_2 , V_3 ) &&
V_3 < V_2 -> V_43 -> V_44 ) {
V_39 = F_10 ( V_2 , V_3 , & V_42 ) ;
if ( V_39 >= 0 )
return V_42 ;
else
F_7 ( V_2 -> V_41 , L_2 ,
V_3 , V_39 ) ;
}
return F_11 ( V_2 -> V_7 , V_3 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_45 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_46 ;
int V_47 = 0 ;
int V_48 ;
if ( V_45 )
V_48 = 4 ;
else
V_48 = 0 ;
switch ( V_5 -> V_49 [ V_45 ] ) {
case V_50 :
V_46 = V_5 -> V_51 [ 0 ] ;
break;
case V_52 :
V_47 |= 0x8 ;
V_46 = V_5 -> V_51 [ 1 ] ;
break;
case V_53 :
V_47 |= 0x10 ;
V_46 = V_5 -> V_54 [ 0 ] . V_55 ;
break;
case V_56 :
V_47 |= 0x18 ;
V_46 = V_5 -> V_54 [ 1 ] . V_55 ;
break;
default:
return - V_57 ;
}
if ( V_46 >= 13500000 ) {
V_46 /= 2 ;
V_47 |= V_58 ;
F_13 ( V_2 -> V_41 , L_3 ,
V_45 + 1 , V_46 ) ;
}
V_5 -> V_59 [ V_45 ] = V_46 ;
F_14 ( V_2 , V_60 + V_48 ,
V_61 | V_58 ,
V_47 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_62 , V_63 ;
F_12 ( V_2 , 0 ) ;
F_12 ( V_2 , 1 ) ;
if ( V_5 -> V_59 [ 0 ] == V_5 -> V_59 [ 1 ] )
return 0 ;
if ( V_5 -> V_59 [ 0 ] < V_5 -> V_59 [ 1 ] )
V_63 = V_64 ;
else
V_63 = 0 ;
V_62 = F_14 ( V_2 , V_65 ,
V_64 , V_63 ) ;
if ( ! V_62 )
return 0 ;
F_16 ( & V_2 -> V_66 ) ;
return 0 ;
}
static int F_17 ( struct V_67 * V_68 ,
struct V_67 * V_69 )
{
int V_3 = F_18 ( V_68 -> V_2 , V_65 ) ;
const char * V_70 ;
if ( V_3 & V_64 )
V_70 = L_4 ;
else
V_70 = L_5 ;
return strcmp ( V_68 -> V_71 , V_70 ) == 0 ;
}
static int F_19 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_76 * V_77 =
(struct V_76 * ) V_73 -> V_78 ;
struct V_1 * V_2 = F_20 ( V_73 ) ;
int V_79 , V_39 ;
if ( V_77 -> V_80 == V_81 )
V_79 = V_82 |
V_83 ;
else
V_79 = V_84 ;
V_39 = F_18 ( V_2 , V_77 -> V_3 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 & V_79 )
return - V_57 ;
return F_21 ( V_73 , V_75 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_85 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_86 * V_87 = V_5 -> V_87 ;
int V_88 = V_89 [ V_85 ] ;
int V_90 = V_5 -> V_91 [ V_85 ] ;
int V_92 , V_93 ;
V_92 = F_18 ( V_2 , V_88 ) ;
V_92 &= V_94 | V_95 |
V_96 ;
for ( V_93 = 0 ; V_93 < V_97 ; V_93 ++ )
F_14 ( V_2 , V_88 + V_93 , 0xffff ,
V_87 -> V_98 [ V_90 ] . V_99 [ V_93 ] ) ;
F_14 ( V_2 , V_88 , V_94 |
V_95 |
V_96 , V_92 ) ;
}
static int F_23 ( const char * V_71 )
{
if ( strcmp ( V_71 , L_6 ) == 0 )
return 0 ;
if ( strcmp ( V_71 , L_7 ) == 0 )
return 1 ;
if ( strcmp ( V_71 , L_8 ) == 0 )
return 2 ;
return - V_57 ;
}
static int F_24 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 = F_20 ( V_73 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_86 * V_87 = V_5 -> V_87 ;
int V_85 = F_23 ( V_73 -> V_100 . V_71 ) ;
int V_38 = V_75 -> V_38 . integer . V_38 [ 0 ] ;
if ( V_85 < 0 )
return V_85 ;
if ( V_38 >= V_87 -> V_101 )
return - V_57 ;
V_5 -> V_91 [ V_85 ] = V_38 ;
F_22 ( V_2 , V_85 ) ;
return 0 ;
}
static int F_25 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 = F_20 ( V_73 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_85 = F_23 ( V_73 -> V_100 . V_71 ) ;
V_75 -> V_38 . V_102 . V_103 [ 0 ] = V_5 -> V_91 [ V_85 ] ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 , int V_104 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_86 * V_87 = V_5 -> V_87 ;
int V_88 = V_105 [ V_104 ] ;
int V_106 , V_107 , V_108 , V_92 , V_93 , V_90 ;
if ( ! V_87 || ! V_5 -> V_109 )
return;
switch ( V_104 ) {
case 0 :
case 1 :
V_106 = 0 ;
break;
case 2 :
V_106 = 1 ;
break;
default:
return;
}
V_90 = V_5 -> V_110 [ V_104 ] ;
V_107 = 0 ;
V_108 = V_111 ;
for ( V_93 = 0 ; V_93 < V_87 -> V_112 ; V_93 ++ ) {
if ( strcmp ( V_87 -> V_113 [ V_93 ] . V_71 ,
V_5 -> V_114 [ V_90 ] ) == 0 &&
abs ( V_87 -> V_113 [ V_93 ] . V_46
- V_5 -> V_115 [ V_106 ] ) < V_108 ) {
V_107 = V_93 ;
V_108 = abs ( V_87 -> V_113 [ V_93 ] . V_46
- V_5 -> V_115 [ V_106 ] ) ;
}
}
F_13 ( V_2 -> V_41 , L_9 ,
V_104 ,
V_87 -> V_113 [ V_107 ] . V_71 ,
V_87 -> V_113 [ V_107 ] . V_46 ,
V_5 -> V_115 [ V_106 ] ) ;
V_92 = F_18 ( V_2 , V_88 ) ;
V_92 &= V_116 ;
for ( V_93 = 0 ; V_93 < V_117 ; V_93 ++ )
F_14 ( V_2 , V_88 + V_93 , 0xffff ,
V_87 -> V_113 [ V_107 ] . V_99 [ V_93 ] ) ;
F_14 ( V_2 , V_88 , V_116 , V_92 ) ;
}
static int F_27 ( const char * V_71 )
{
if ( strcmp ( V_71 , L_10 ) == 0 )
return 0 ;
if ( strcmp ( V_71 , L_11 ) == 0 )
return 1 ;
if ( strcmp ( V_71 , L_12 ) == 0 )
return 2 ;
return - V_57 ;
}
static int F_28 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 = F_20 ( V_73 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_86 * V_87 = V_5 -> V_87 ;
int V_104 = F_27 ( V_73 -> V_100 . V_71 ) ;
int V_38 = V_75 -> V_38 . integer . V_38 [ 0 ] ;
if ( V_104 < 0 )
return V_104 ;
if ( V_38 >= V_87 -> V_112 )
return - V_57 ;
V_5 -> V_110 [ V_104 ] = V_38 ;
F_26 ( V_2 , V_104 ) ;
return 0 ;
}
static int F_29 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 = F_20 ( V_73 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_104 = F_27 ( V_73 -> V_100 . V_71 ) ;
V_75 -> V_38 . V_102 . V_103 [ 0 ] = V_5 -> V_110 [ V_104 ] ;
return 0 ;
}
static int F_30 ( struct V_67 * V_118 ,
struct V_72 * V_73 , int V_119 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
switch ( V_119 ) {
case V_120 :
return F_15 ( V_2 ) ;
case V_121 :
F_15 ( V_2 ) ;
break;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_122 ++ ;
F_13 ( V_2 -> V_41 , L_13 ,
V_5 -> V_122 ) ;
if ( V_5 -> V_122 == 1 ) {
F_14 ( V_2 , V_123 ,
V_124 |
V_125 |
V_126 ,
V_124 |
V_125 |
( 0x11 << V_127 ) ) ;
F_14 ( V_2 , V_128 ,
V_129 |
V_130 ,
V_129 | 0x2 ) ;
F_32 ( 20 ) ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_122 -- ;
F_13 ( V_2 -> V_41 , L_14 ,
V_5 -> V_122 ) ;
if ( V_5 -> V_122 == 0 ) {
F_14 ( V_2 , V_123 ,
V_131 |
V_124 |
V_125 |
V_126 ,
V_131 |
V_124 |
V_125 |
( 1 << V_127 ) ) ;
F_14 ( V_2 , V_128 ,
V_129 |
V_130 , 0 ) ;
F_14 ( V_2 , V_132 ,
V_133 |
V_134 ,
V_133 |
V_134 ) ;
F_32 ( 5 ) ;
F_14 ( V_2 , V_123 ,
V_131 |
V_124 |
V_125 |
V_126 , 0 ) ;
}
}
static int F_34 ( struct V_67 * V_118 ,
struct V_72 * V_73 , int V_119 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
switch ( V_119 ) {
case V_120 :
F_31 ( V_2 ) ;
break;
case V_121 :
F_33 ( V_2 ) ;
break;
}
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_135 = 1 ;
int V_68 = 0 ;
int V_3 , V_136 ;
V_3 = F_18 ( V_2 , V_137 ) ;
if ( ! ( V_3 & V_138 ) ) {
F_36 ( V_2 -> V_41 , L_15 ) ;
V_135 = 0 ;
}
V_3 = F_18 ( V_2 , V_139 ) ;
if ( ! ( V_3 & V_140 ) ) {
F_36 ( V_2 -> V_41 , L_16 ) ;
V_135 = 0 ;
}
V_3 = F_18 ( V_2 , V_141 ) ;
switch ( V_3 ) {
case V_142 :
F_36 ( V_2 -> V_41 , L_17 ) ;
V_68 = 2 << V_143 ;
break;
case V_144 :
F_36 ( V_2 -> V_41 , L_18 ) ;
V_68 = 1 << V_143 ;
break;
case V_145 :
F_36 ( V_2 -> V_41 , L_19 ) ;
V_68 = 0 << V_143 ;
break;
default:
F_36 ( V_2 -> V_41 , L_20 , V_3 ) ;
V_135 = 0 ;
break;
}
V_136 = F_18 ( V_2 , V_146 ) ;
if ( V_136 != V_3 ) {
F_36 ( V_2 -> V_41 , L_21 ) ;
V_135 = 0 ;
}
if ( V_135 ) {
F_13 ( V_2 -> V_41 , L_22 ) ;
F_14 ( V_2 , V_147 ,
V_148 |
V_149 ,
V_68 | V_148 ) ;
V_5 -> V_150 . V_151 = true ;
} else {
F_13 ( V_2 -> V_41 , L_23 ) ;
F_14 ( V_2 , V_147 ,
V_148 , 0 ) ;
V_5 -> V_150 . V_151 = false ;
}
}
static int F_37 ( struct V_67 * V_118 ,
struct V_72 * V_73 , int V_119 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_119 ) {
case V_120 :
if ( V_5 -> V_152 ) {
F_14 ( V_2 , V_60 ,
V_153 ,
V_154 ) ;
V_5 -> V_152 = 0 ;
}
if ( V_5 -> V_155 ) {
F_14 ( V_2 , V_156 ,
V_157 ,
V_158 ) ;
V_5 -> V_155 = 0 ;
}
break;
}
F_38 ( V_118 , V_73 , V_119 ) ;
return 0 ;
}
static int F_39 ( struct V_67 * V_118 ,
struct V_72 * V_73 , int V_119 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_119 ) {
case V_121 :
if ( V_5 -> V_159 ) {
F_14 ( V_2 , V_60 ,
V_153 , 0 ) ;
V_5 -> V_159 = 0 ;
}
if ( V_5 -> V_160 ) {
F_14 ( V_2 , V_156 ,
V_157 , 0 ) ;
V_5 -> V_160 = 0 ;
}
break;
}
return 0 ;
}
static int F_40 ( struct V_67 * V_118 ,
struct V_72 * V_73 , int V_119 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_119 ) {
case V_120 :
V_5 -> V_152 = 1 ;
break;
case V_121 :
V_5 -> V_159 = 1 ;
break;
}
return 0 ;
}
static int F_41 ( struct V_67 * V_118 ,
struct V_72 * V_73 , int V_119 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_119 ) {
case V_120 :
V_5 -> V_155 = 1 ;
break;
case V_121 :
V_5 -> V_160 = 1 ;
break;
}
return 0 ;
}
static int F_42 ( struct V_67 * V_118 ,
struct V_72 * V_73 , int V_119 )
{
F_37 ( V_118 , V_73 , V_119 ) ;
return 0 ;
}
static int F_43 ( struct V_67 * V_118 ,
struct V_72 * V_73 , int V_119 )
{
F_37 ( V_118 , V_73 , V_119 ) ;
return 0 ;
}
static int F_44 ( struct V_67 * V_118 ,
struct V_72 * V_73 , int V_119 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
unsigned int V_79 = 1 << V_118 -> V_80 ;
F_14 ( V_2 , V_161 ,
V_79 , V_79 ) ;
return 0 ;
}
static int F_45 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_162 * V_163 = F_20 ( V_73 ) ;
struct V_67 * V_118 = V_163 -> V_164 [ 0 ] ;
struct V_1 * V_2 = V_118 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_73 , V_75 ) ;
F_35 ( V_2 ) ;
return V_39 ;
}
static int F_47 ( struct V_67 * V_118 ,
struct V_72 * V_73 , int V_119 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
F_13 ( V_2 -> V_41 , L_24 ,
F_18 ( V_2 ,
V_33 ) ) ;
return 0 ;
}
static int F_48 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_162 * V_163 = F_20 ( V_73 ) ;
struct V_67 * V_118 = V_163 -> V_164 [ 0 ] ;
struct V_1 * V_2 = V_118 -> V_2 ;
int V_39 ;
V_39 = F_49 ( V_73 , V_75 ) ;
F_35 ( V_2 ) ;
return V_39 ;
}
static int F_50 ( struct V_165 * V_54 ,
int V_166 , int V_167 )
{
T_1 V_168 ;
unsigned int V_169 , V_170 , V_171 ;
F_51 ( L_25 , V_166 , V_167 ) ;
V_54 -> V_172 = 0 ;
while ( V_166 > 13500000 ) {
V_54 -> V_172 ++ ;
V_166 /= 2 ;
if ( V_54 -> V_172 > 3 )
return - V_57 ;
}
F_51 ( L_26 , V_54 -> V_172 , V_166 ) ;
V_54 -> V_173 = 3 ;
while ( V_167 * ( V_54 -> V_173 + 1 ) < 90000000 ) {
V_54 -> V_173 ++ ;
if ( V_54 -> V_173 > 63 )
return - V_57 ;
}
V_167 *= V_54 -> V_173 + 1 ;
F_51 ( L_27 , V_54 -> V_173 , V_167 ) ;
if ( V_166 > 1000000 ) {
V_54 -> V_174 = 0 ;
} else if ( V_166 > 256000 ) {
V_54 -> V_174 = 1 ;
V_166 *= 2 ;
} else if ( V_166 > 128000 ) {
V_54 -> V_174 = 2 ;
V_166 *= 4 ;
} else if ( V_166 > 64000 ) {
V_54 -> V_174 = 3 ;
V_166 *= 8 ;
} else {
V_54 -> V_174 = 4 ;
V_166 *= 16 ;
}
F_51 ( L_28 , V_54 -> V_174 , V_166 ) ;
V_170 = V_167 / V_166 ;
V_54 -> V_175 = V_170 ;
V_171 = V_167 % V_166 ;
F_51 ( L_29 , V_171 ) ;
V_168 = V_176 * ( long long ) V_171 ;
F_52 ( V_168 , V_166 ) ;
V_169 = V_168 & 0xFFFFFFFF ;
if ( ( V_169 % 10 ) >= 5 )
V_169 += 5 ;
V_54 -> V_177 = V_169 / 10 ;
F_51 ( L_30 , V_54 -> V_175 , V_54 -> V_177 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , int V_100 , int V_178 ,
unsigned int V_166 , unsigned int V_167 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_179 , V_39 ;
struct V_165 V_54 ;
T_2 V_3 , V_180 , V_181 ;
unsigned long V_182 ;
bool V_183 ;
V_180 = F_18 ( V_2 , V_60 )
& V_154 ;
V_181 = F_18 ( V_2 , V_156 )
& V_158 ;
switch ( V_100 ) {
case V_184 :
V_179 = 0 ;
V_100 = 0 ;
break;
case V_185 :
V_179 = 0x20 ;
V_100 = 1 ;
break;
default:
return - V_57 ;
}
V_3 = F_18 ( V_2 , V_186 + V_179 ) ;
V_183 = V_3 & V_187 ;
switch ( V_178 ) {
case 0 :
if ( V_167 )
return - V_57 ;
V_178 = V_5 -> V_54 [ V_100 ] . V_178 ;
break;
case V_188 :
case V_189 :
case V_190 :
case V_191 :
break;
default:
return - V_57 ;
}
if ( V_5 -> V_54 [ V_100 ] . V_178 == V_178 &&
V_5 -> V_54 [ V_100 ] . V_192 == V_166 && V_5 -> V_54 [ V_100 ] . V_55 == V_167 )
return 0 ;
if ( V_167 )
V_39 = F_50 ( & V_54 , V_166 , V_167 ) ;
else
V_39 = F_50 ( & V_54 , V_5 -> V_54 [ V_100 ] . V_192 ,
V_5 -> V_54 [ V_100 ] . V_55 ) ;
if ( V_39 < 0 )
return V_39 ;
F_14 ( V_2 , V_60 ,
V_154 , 0 ) ;
F_14 ( V_2 , V_156 ,
V_158 , 0 ) ;
F_14 ( V_2 , V_186 + V_179 ,
V_187 , 0 ) ;
V_3 = ( V_54 . V_173 << V_193 ) |
( V_54 . V_174 << V_194 ) ;
F_14 ( V_2 , V_195 + V_179 ,
V_196 |
V_197 , V_3 ) ;
F_54 ( V_2 , V_198 + V_179 , V_54 . V_177 ) ;
F_14 ( V_2 , V_199 + V_179 ,
V_200 ,
V_54 . V_175 << V_201 ) ;
F_14 ( V_2 , V_202 + V_179 ,
V_203 |
V_204 ,
( V_54 . V_172 << V_205 ) |
( V_178 - 1 ) ) ;
F_55 ( & V_5 -> V_206 [ V_100 ] ) ;
if ( V_167 ) {
if ( ! V_183 ) {
switch ( V_6 -> type ) {
case V_207 :
F_31 ( V_2 ) ;
break;
case V_25 :
if ( V_5 -> V_208 < 1 )
F_31 ( V_2 ) ;
break;
default:
break;
}
}
if ( V_54 . V_177 )
V_3 = V_187 | V_209 ;
else
V_3 = V_187 ;
F_14 ( V_2 , V_186 + V_179 ,
V_187 | V_209 ,
V_3 ) ;
if ( V_5 -> V_210 ) {
V_182 = F_56 ( & V_5 -> V_206 [ V_100 ] ,
F_57 ( 10 ) ) ;
if ( V_182 == 0 )
F_58 ( V_2 -> V_41 ,
L_31 ) ;
} else {
F_32 ( 5 ) ;
}
} else {
if ( V_183 ) {
switch ( V_6 -> type ) {
case V_207 :
F_33 ( V_2 ) ;
break;
case V_25 :
if ( V_5 -> V_208 < 1 )
F_33 ( V_2 ) ;
break;
default:
break;
}
}
}
V_5 -> V_54 [ V_100 ] . V_192 = V_166 ;
V_5 -> V_54 [ V_100 ] . V_55 = V_167 ;
V_5 -> V_54 [ V_100 ] . V_178 = V_178 ;
F_14 ( V_2 , V_60 ,
V_154 , V_180 ) ;
F_14 ( V_2 , V_156 ,
V_158 , V_181 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static T_3 F_59 ( int V_211 , void * V_212 )
{
struct V_213 * V_213 = V_212 ;
F_60 ( V_213 ) ;
return V_214 ;
}
static int F_61 ( struct V_215 * V_216 , int V_100 , int V_178 ,
unsigned int V_166 , unsigned int V_167 )
{
return F_53 ( V_216 -> V_2 , V_100 , V_178 , V_166 , V_167 ) ;
}
static int F_62 ( struct V_215 * V_216 ,
int V_217 , unsigned int V_218 , int V_219 )
{
struct V_1 * V_2 = V_216 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_93 ;
switch ( V_216 -> V_100 ) {
case 1 :
case 2 :
break;
default:
return - V_57 ;
}
switch ( V_217 ) {
case V_50 :
V_5 -> V_49 [ V_216 -> V_100 - 1 ] = V_50 ;
V_5 -> V_51 [ 0 ] = V_218 ;
F_13 ( V_216 -> V_41 , L_32 ,
V_216 -> V_100 , V_218 ) ;
break;
case V_52 :
V_5 -> V_49 [ V_216 -> V_100 - 1 ] = V_52 ;
V_5 -> V_51 [ 1 ] = V_218 ;
F_13 ( V_216 -> V_41 , L_33 ,
V_216 -> V_100 , V_218 ) ;
break;
case V_53 :
V_5 -> V_49 [ V_216 -> V_100 - 1 ] = V_53 ;
F_13 ( V_216 -> V_41 , L_34 , V_216 -> V_100 ) ;
break;
case V_56 :
V_5 -> V_49 [ V_216 -> V_100 - 1 ] = V_56 ;
F_13 ( V_216 -> V_41 , L_35 , V_216 -> V_100 ) ;
break;
case V_220 :
if ( V_218 ) {
for ( V_93 = 0 ; V_93 < F_63 ( V_221 ) ; V_93 ++ )
if ( V_221 [ V_93 ] == V_218 )
break;
if ( V_93 == F_63 ( V_221 ) )
return - V_57 ;
F_14 ( V_2 , V_222 ,
V_223 , V_93 ) ;
F_14 ( V_2 , V_224 ,
V_225 , V_225 ) ;
} else {
F_14 ( V_2 , V_224 ,
V_225 , 0 ) ;
}
default:
return - V_57 ;
}
F_15 ( V_2 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
enum V_226 V_227 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_227 ) {
case V_228 :
break;
case V_229 :
break;
case V_230 :
if ( V_2 -> V_66 . V_231 == V_232 ) {
F_65 ( V_2 -> V_41 ) ;
switch ( V_6 -> type ) {
case V_207 :
if ( V_5 -> V_208 < 4 ) {
F_54 ( V_2 , 0x102 , 0x3 ) ;
F_54 ( V_2 , 0x56 , 0x3 ) ;
F_54 ( V_2 , 0x817 , 0 ) ;
F_54 ( V_2 , 0x102 , 0 ) ;
}
break;
case V_25 :
if ( V_5 -> V_208 == 0 ) {
F_54 ( V_2 , 0x102 , 0x3 ) ;
F_54 ( V_2 , 0xcb , 0x81 ) ;
F_54 ( V_2 , 0x817 , 0 ) ;
F_54 ( V_2 , 0x102 , 0 ) ;
F_14 ( V_2 ,
V_233 ,
V_234 ,
V_234 ) ;
}
break;
case V_235 :
if ( V_5 -> V_208 < 2 ) {
F_54 ( V_2 , 0x102 , 0x3 ) ;
F_54 ( V_2 , 0x5d , 0x7e ) ;
F_54 ( V_2 , 0x5e , 0x0 ) ;
F_54 ( V_2 , 0x102 , 0x0 ) ;
}
break;
}
F_14 ( V_2 , V_132 ,
V_133 |
V_134 ,
V_133 |
V_134 ) ;
}
break;
case V_232 :
if ( V_2 -> V_66 . V_231 == V_230 ) {
V_5 -> V_236 = NULL ;
F_66 ( V_2 -> V_41 ) ;
}
break;
}
V_2 -> V_66 . V_231 = V_227 ;
return 0 ;
}
static int F_67 ( struct V_215 * V_216 , unsigned int V_237 )
{
struct V_1 * V_2 = V_216 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_238 ;
int V_239 ;
int V_240 = 0 ;
int V_180 = 0 ;
switch ( V_216 -> V_100 ) {
case 1 :
V_238 = V_241 ;
V_239 = V_242 ;
break;
case 2 :
V_238 = V_243 ;
V_239 = V_244 ;
break;
default:
return - V_57 ;
}
switch ( V_237 & V_245 ) {
case V_246 :
break;
case V_247 :
V_240 = V_248 ;
break;
default:
return - V_57 ;
}
switch ( V_237 & V_249 ) {
case V_250 :
V_180 |= V_251 ;
case V_252 :
V_180 |= 0x18 ;
break;
case V_253 :
V_180 |= 0x10 ;
break;
case V_254 :
break;
case V_255 :
V_180 |= 0x8 ;
break;
default:
return - V_57 ;
}
switch ( V_237 & V_249 ) {
case V_252 :
case V_250 :
switch ( V_237 & V_256 ) {
case V_257 :
break;
case V_258 :
V_180 |= V_259 ;
break;
default:
return - V_57 ;
}
break;
case V_253 :
case V_254 :
case V_255 :
switch ( V_237 & V_256 ) {
case V_257 :
break;
case V_260 :
V_180 |= V_259 | V_251 ;
break;
case V_258 :
V_180 |= V_259 ;
break;
case V_261 :
V_180 |= V_251 ;
break;
default:
return - V_57 ;
}
break;
default:
return - V_57 ;
}
switch ( V_6 -> type ) {
case V_235 :
case V_25 :
if ( V_216 -> V_100 == 2 )
F_14 ( V_2 , V_262 ,
V_251 |
V_263 , V_180 ) ;
break;
default:
break;
}
F_14 ( V_2 , V_239 ,
V_259 | V_251 |
V_264 ,
V_180 ) ;
F_14 ( V_2 , V_238 , V_248 ,
V_240 ) ;
return 0 ;
}
static int F_68 ( struct V_265 * V_266 ,
struct V_267 * V_268 ,
struct V_215 * V_216 )
{
struct V_1 * V_2 = V_216 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_239 ;
int V_269 ;
int V_270 ;
int V_271 ;
int V_272 ;
int V_180 = 0 ;
int V_181 = 0 ;
int V_273 = 0 ;
int V_274 = 0 ;
int V_275 = 0 ;
int V_100 = V_216 -> V_100 - 1 ;
int V_93 , V_276 , V_108 , V_277 , V_107 ;
switch ( V_216 -> V_100 ) {
case 1 :
V_239 = V_242 ;
V_269 = V_278 ;
V_270 = V_279 ;
V_272 = V_280 ;
if ( V_266 -> V_281 == V_282 ||
V_5 -> V_283 [ 0 ] ) {
V_271 = V_284 ;
} else {
V_271 = V_285 ;
F_13 ( V_2 -> V_41 , L_36 ) ;
}
break;
case 2 :
V_239 = V_244 ;
V_269 = V_286 ;
V_270 = V_287 ;
V_272 = V_288 ;
if ( V_266 -> V_281 == V_282 ||
V_5 -> V_283 [ 1 ] ) {
V_271 = V_289 ;
} else {
V_271 = V_290 ;
F_13 ( V_2 -> V_41 , L_37 ) ;
}
break;
default:
return - V_57 ;
}
V_277 = F_69 ( V_268 ) * 2 ;
switch ( F_70 ( V_268 ) ) {
case V_291 :
V_277 *= 16 ;
break;
case V_292 :
V_277 *= 20 ;
V_180 |= 0x20 ;
break;
case V_293 :
V_277 *= 24 ;
V_180 |= 0x40 ;
break;
case V_294 :
V_277 *= 32 ;
V_180 |= 0x60 ;
break;
default:
return - V_57 ;
}
for ( V_93 = 0 ; V_93 < F_63 ( V_295 ) ; V_93 ++ )
if ( V_295 [ V_93 ] . V_46 == F_69 ( V_268 ) )
break;
if ( V_93 == F_63 ( V_295 ) )
return - V_57 ;
V_275 |= V_295 [ V_93 ] . V_42 << V_296 ;
F_13 ( V_216 -> V_41 , L_38 , V_295 [ V_93 ] . V_46 ) ;
F_13 ( V_216 -> V_41 , L_39 ,
V_216 -> V_100 , V_5 -> V_59 [ V_100 ] , V_277 ) ;
if ( F_71 ( V_268 ) == 1 &&
( F_18 ( V_2 , V_239 ) & 0x18 ) == 0x18 )
V_181 |= V_297 ;
if ( V_5 -> V_59 [ V_100 ] == 0 ) {
F_7 ( V_216 -> V_41 , L_40 , V_216 -> V_100 ) ;
return - V_57 ;
}
V_107 = 0 ;
V_108 = abs ( ( V_298 [ 0 ] * F_69 ( V_268 ) )
- V_5 -> V_59 [ V_100 ] ) ;
for ( V_93 = 1 ; V_93 < F_63 ( V_298 ) ; V_93 ++ ) {
V_276 = abs ( ( V_298 [ V_93 ] * F_69 ( V_268 ) )
- V_5 -> V_59 [ V_100 ] ) ;
if ( V_276 >= V_108 )
continue;
V_107 = V_93 ;
V_108 = V_276 ;
}
F_13 ( V_216 -> V_41 , L_41 ,
V_216 -> V_100 , V_298 [ V_107 ] ) ;
V_275 |= V_107 ;
V_107 = 0 ;
for ( V_93 = 0 ; V_93 < F_63 ( V_299 ) ; V_93 ++ ) {
V_276 = ( V_5 -> V_59 [ V_100 ] * 10 / V_299 [ V_93 ] ) - V_277 ;
if ( V_276 < 0 )
break;
V_107 = V_93 ;
}
V_277 = V_5 -> V_59 [ V_100 ] * 10 / V_299 [ V_107 ] ;
F_13 ( V_216 -> V_41 , L_42 ,
V_299 [ V_107 ] , V_277 ) ;
V_273 |= V_107 << V_300 ;
V_274 = V_277 / F_69 ( V_268 ) ;
if ( ! V_274 ) {
F_7 ( V_216 -> V_41 , L_43 ,
V_277 ) ;
return - V_57 ;
}
F_13 ( V_216 -> V_41 , L_44 ,
V_274 , V_277 / V_274 ) ;
F_14 ( V_2 , V_239 , V_301 , V_180 ) ;
F_14 ( V_2 , V_269 , V_297 , V_181 ) ;
F_14 ( V_2 , V_270 , V_302 , V_273 ) ;
F_14 ( V_2 , V_271 , V_303 ,
V_274 ) ;
F_14 ( V_2 , V_272 , V_304 |
V_305 , V_275 ) ;
if ( V_266 -> V_281 == V_282 ) {
switch ( V_216 -> V_100 ) {
case 1 :
V_5 -> V_115 [ 0 ] = F_69 ( V_268 ) ;
F_26 ( V_2 , 0 ) ;
F_26 ( V_2 , 1 ) ;
break;
case 2 :
V_5 -> V_115 [ 1 ] = F_69 ( V_268 ) ;
F_26 ( V_2 , 2 ) ;
break;
}
}
return 0 ;
}
static int F_72 ( struct V_265 * V_266 ,
struct V_267 * V_268 ,
struct V_215 * V_216 )
{
struct V_1 * V_2 = V_216 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_239 ;
int V_180 = 0 ;
switch ( V_216 -> V_100 ) {
case 3 :
switch ( V_6 -> type ) {
case V_235 :
case V_25 :
V_239 = V_262 ;
break;
default:
return 0 ;
}
default:
return 0 ;
}
switch ( F_70 ( V_268 ) ) {
case V_291 :
break;
case V_292 :
V_180 |= 0x20 ;
break;
case V_293 :
V_180 |= 0x40 ;
break;
case V_294 :
V_180 |= 0x60 ;
break;
default:
return - V_57 ;
}
return F_14 ( V_2 , V_239 , V_301 , V_180 ) ;
}
static void F_73 ( struct V_265 * V_266 ,
struct V_215 * V_216 )
{
struct V_1 * V_2 = V_216 -> V_2 ;
int V_272 = 0 ;
switch ( V_216 -> V_100 ) {
case 1 :
V_272 = V_280 ;
break;
case 2 :
V_272 = V_288 ;
break;
default:
break;
}
if ( V_272 && ! V_216 -> V_306 && ! V_216 -> V_307 )
F_14 ( V_2 , V_272 ,
V_304 |
V_305 , 0x9 ) ;
}
static int F_74 ( struct V_215 * V_308 , int V_309 )
{
struct V_1 * V_2 = V_308 -> V_2 ;
int V_310 ;
int V_3 ;
switch ( V_308 -> V_100 ) {
case 1 :
V_310 = V_311 ;
break;
case 2 :
V_310 = V_312 ;
break;
default:
return - V_57 ;
}
if ( V_309 )
V_3 = V_313 ;
else
V_3 = 0 ;
F_14 ( V_2 , V_310 , V_313 , V_3 ) ;
return 0 ;
}
static int F_75 ( struct V_215 * V_308 , int V_314 )
{
struct V_1 * V_2 = V_308 -> V_2 ;
int V_3 , V_42 , V_79 ;
switch ( V_308 -> V_100 ) {
case 1 :
V_3 = V_241 ;
V_79 = V_315 ;
break;
case 2 :
V_3 = V_243 ;
V_79 = V_316 ;
break;
case 3 :
V_3 = V_317 ;
V_79 = V_318 ;
break;
default:
return - V_57 ;
}
if ( V_314 )
V_42 = V_79 ;
else
V_42 = 0 ;
return F_14 ( V_2 , V_3 , V_79 , V_42 ) ;
}
static int F_76 ( struct V_215 * V_216 )
{
struct V_1 * V_2 = V_216 -> V_2 ;
F_14 ( V_2 , V_10 ,
V_319 | V_320 , 0 ) ;
F_14 ( V_2 , V_11 ,
V_319 | V_320 , 0 ) ;
F_14 ( V_2 , V_12 ,
V_319 | V_320 , 0 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , T_4 V_321 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_93 , V_39 ;
switch ( V_6 -> type ) {
case V_207 :
F_14 ( V_2 , V_322 , V_323 , 0 ) ;
break;
case V_235 :
case V_25 :
F_14 ( V_2 , V_324 ,
V_325 , 0 ) ;
break;
}
for ( V_93 = 0 ; V_93 < F_63 ( V_5 -> V_54 ) ; V_93 ++ ) {
memcpy ( & V_5 -> V_326 [ V_93 ] , & V_5 -> V_54 [ V_93 ] ,
sizeof( struct V_327 ) ) ;
V_39 = F_53 ( V_2 , V_93 + 1 , 0 , 0 , 0 ) ;
if ( V_39 < 0 )
F_58 ( V_2 -> V_41 , L_45 ,
V_93 + 1 , V_39 ) ;
}
F_64 ( V_2 , V_232 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_93 , V_39 ;
unsigned int V_42 , V_79 ;
if ( V_5 -> V_208 < 4 ) {
V_42 = F_11 ( V_2 -> V_7 ,
V_161 ) ;
V_2 -> V_328 = 1 ;
V_79 = V_329 | V_330 |
V_331 | V_332 ;
V_42 &= V_79 ;
F_14 ( V_2 , V_161 ,
V_79 , V_42 ) ;
V_2 -> V_328 = 0 ;
}
V_39 = F_79 ( V_2 ) ;
if ( V_39 != 0 )
F_7 ( V_2 -> V_41 , L_46 , V_39 ) ;
F_64 ( V_2 , V_230 ) ;
for ( V_93 = 0 ; V_93 < F_63 ( V_5 -> V_54 ) ; V_93 ++ ) {
if ( ! V_5 -> V_326 [ V_93 ] . V_55 )
continue;
V_39 = F_53 ( V_2 , V_93 + 1 ,
V_5 -> V_326 [ V_93 ] . V_178 ,
V_5 -> V_326 [ V_93 ] . V_192 ,
V_5 -> V_326 [ V_93 ] . V_55 ) ;
if ( V_39 < 0 )
F_58 ( V_2 -> V_41 , L_47 ,
V_93 + 1 , V_39 ) ;
}
switch ( V_6 -> type ) {
case V_207 :
if ( V_5 -> V_333 [ 0 ] . V_334 || V_5 -> V_333 [ 1 ] . V_334 )
F_14 ( V_2 , V_322 ,
V_323 , V_323 ) ;
break;
case V_235 :
case V_25 :
if ( V_5 -> V_335 )
F_14 ( V_2 , V_324 ,
V_325 , V_325 ) ;
break;
}
return 0 ;
}
static void F_80 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_86 * V_87 = V_5 -> V_87 ;
struct V_336 V_337 [] = {
F_81 ( L_10 ,
V_5 -> V_338 ,
F_29 ,
F_28 ) ,
F_81 ( L_11 ,
V_5 -> V_338 ,
F_29 ,
F_28 ) ,
F_81 ( L_12 ,
V_5 -> V_338 ,
F_29 ,
F_28 ) ,
} ;
int V_39 , V_93 , V_339 ;
const char * * V_340 ;
V_5 -> V_109 = 0 ;
V_5 -> V_114 = NULL ;
for ( V_93 = 0 ; V_93 < V_87 -> V_112 ; V_93 ++ ) {
for ( V_339 = 0 ; V_339 < V_5 -> V_109 ; V_339 ++ ) {
if ( strcmp ( V_87 -> V_113 [ V_93 ] . V_71 ,
V_5 -> V_114 [ V_339 ] ) == 0 )
break;
}
if ( V_339 != V_5 -> V_109 )
continue;
V_340 = F_82 ( V_5 -> V_114 ,
sizeof( char * ) *
( V_5 -> V_109 + 1 ) ,
V_341 ) ;
if ( V_340 == NULL )
continue;
V_340 [ V_5 -> V_109 ] =
V_87 -> V_113 [ V_93 ] . V_71 ;
V_5 -> V_109 ++ ;
V_5 -> V_114 = V_340 ;
}
F_13 ( V_2 -> V_41 , L_48 ,
V_5 -> V_109 ) ;
V_5 -> V_338 . V_342 = V_5 -> V_109 ;
V_5 -> V_338 . V_343 = V_5 -> V_114 ;
V_39 = F_83 ( V_5 -> V_2 , V_337 ,
F_63 ( V_337 ) ) ;
if ( V_39 != 0 )
F_7 ( V_5 -> V_2 -> V_41 ,
L_49 , V_39 ) ;
}
static void F_84 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_86 * V_87 = V_5 -> V_87 ;
int V_39 , V_93 ;
if ( ! V_87 )
return;
F_85 ( V_2 , V_87 -> V_344 ,
V_87 -> V_345 ,
V_87 -> V_346 ,
V_87 -> V_347 ,
V_87 -> V_348 ,
V_87 -> V_349 ,
V_87 -> V_350 ,
V_87 -> V_351 ) ;
F_13 ( V_2 -> V_41 , L_50 , V_87 -> V_101 ) ;
if ( V_87 -> V_101 ) {
struct V_336 V_337 [] = {
F_81 ( L_6 , V_5 -> V_352 ,
F_25 , F_24 ) ,
F_81 ( L_7 , V_5 -> V_352 ,
F_25 , F_24 ) ,
F_81 ( L_8 , V_5 -> V_352 ,
F_25 , F_24 ) ,
} ;
V_5 -> V_353 = F_86 ( sizeof( char * )
* V_87 -> V_101 , V_341 ) ;
if ( ! V_5 -> V_353 ) {
F_7 ( V_5 -> V_2 -> V_41 ,
L_51 ,
V_87 -> V_101 ) ;
return;
}
for ( V_93 = 0 ; V_93 < V_87 -> V_101 ; V_93 ++ )
V_5 -> V_353 [ V_93 ] = V_87 -> V_98 [ V_93 ] . V_71 ;
V_5 -> V_352 . V_342 = V_87 -> V_101 ;
V_5 -> V_352 . V_343 = V_5 -> V_353 ;
V_39 = F_83 ( V_5 -> V_2 , V_337 ,
F_63 ( V_337 ) ) ;
if ( V_39 != 0 )
F_7 ( V_5 -> V_2 -> V_41 ,
L_52 , V_39 ) ;
for ( V_93 = 0 ; V_93 < V_354 ; V_93 ++ )
F_22 ( V_2 , V_93 ) ;
}
F_13 ( V_2 -> V_41 , L_53 ,
V_87 -> V_112 ) ;
if ( V_87 -> V_112 )
F_80 ( V_5 ) ;
else
F_83 ( V_5 -> V_2 , V_355 ,
F_63 ( V_355 ) ) ;
for ( V_93 = 0 ; V_93 < F_63 ( V_87 -> V_356 ) ; V_93 ++ ) {
if ( V_87 -> V_356 [ V_93 ] ) {
F_54 ( V_2 , V_357 + V_93 ,
V_87 -> V_356 [ V_93 ] & 0xffff ) ;
}
}
}
int F_87 ( struct V_1 * V_2 , struct V_358 * V_334 ,
int V_356 , int V_359 , int V_360 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_361 * V_333 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_3 ;
if ( V_6 -> type != V_207 )
return - V_57 ;
switch ( V_356 ) {
case 1 :
V_333 = & V_5 -> V_333 [ 0 ] ;
break;
case 2 :
V_333 = & V_5 -> V_333 [ 1 ] ;
break;
default:
return - V_57 ;
}
F_13 ( V_2 -> V_41 , L_54 ,
V_356 , V_359 , V_360 ) ;
V_333 -> V_334 = V_334 ;
V_333 -> V_359 = V_359 ;
V_333 -> V_360 = V_360 ;
if ( V_5 -> V_333 [ 0 ] . V_334 || V_5 -> V_333 [ 1 ] . V_334 )
V_3 = V_323 ;
else
V_3 = 0 ;
F_14 ( V_2 , V_322 , V_323 , V_3 ) ;
return 0 ;
}
static T_3 F_88 ( int V_211 , void * V_212 )
{
struct V_4 * V_362 = V_212 ;
struct V_1 * V_2 = V_362 -> V_2 ;
int V_3 ;
int V_363 ;
#ifndef F_89
F_90 ( F_91 ( V_2 -> V_41 ) ) ;
#endif
V_3 = F_18 ( V_2 , V_21 ) ;
if ( V_3 < 0 ) {
F_7 ( V_2 -> V_41 , L_55 ,
V_3 ) ;
return V_214 ;
}
F_13 ( V_2 -> V_41 , L_56 , V_3 ) ;
V_363 = 0 ;
if ( V_3 & V_364 )
V_363 |= V_362 -> V_333 [ 0 ] . V_359 ;
if ( V_3 & V_365 )
V_363 |= V_362 -> V_333 [ 0 ] . V_360 ;
F_92 ( V_362 -> V_333 [ 0 ] . V_334 , V_363 ,
V_362 -> V_333 [ 0 ] . V_359 | V_362 -> V_333 [ 0 ] . V_360 ) ;
V_363 = 0 ;
if ( V_3 & V_366 )
V_363 |= V_362 -> V_333 [ 1 ] . V_359 ;
if ( V_3 & V_367 )
V_363 |= V_362 -> V_333 [ 1 ] . V_360 ;
F_92 ( V_362 -> V_333 [ 1 ] . V_334 , V_363 ,
V_362 -> V_333 [ 1 ] . V_359 | V_362 -> V_333 [ 1 ] . V_360 ) ;
return V_214 ;
}
static void F_93 ( T_2 V_368 , void * V_212 )
{
struct V_1 * V_2 = V_212 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_363 = 0 ;
if ( ! ( V_368 & V_369 ) )
goto V_370;
V_363 = V_371 ;
if ( V_368 & 0x1c )
V_363 |= V_372 ;
V_370:
F_92 ( V_5 -> V_333 [ 0 ] . V_334 , V_363 ,
V_372 | V_371 ) ;
}
int F_94 ( struct V_1 * V_2 , struct V_358 * V_334 ,
T_5 V_373 , void * V_374 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
switch ( V_6 -> type ) {
case V_235 :
case V_25 :
break;
default:
return - V_57 ;
}
if ( V_334 ) {
if ( ! V_373 ) {
F_13 ( V_2 -> V_41 , L_57 ) ;
V_373 = F_93 ;
V_374 = V_2 ;
}
V_5 -> V_333 [ 0 ] . V_334 = V_334 ;
V_5 -> V_335 = V_373 ;
V_5 -> V_375 = V_374 ;
F_14 ( V_2 , V_324 ,
V_325 , V_325 ) ;
} else {
F_14 ( V_2 , V_324 ,
V_325 , 0 ) ;
}
return 0 ;
}
static T_3 F_95 ( int V_211 , void * V_212 )
{
struct V_4 * V_5 = V_212 ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_3 , V_376 ;
V_376 = 10 ;
do {
V_3 = F_18 ( V_2 , V_36 ) ;
if ( V_3 < 0 ) {
F_7 ( V_2 -> V_41 ,
L_58 ,
V_3 ) ;
return V_377 ;
}
if ( ! ( V_3 & V_378 ) ) {
F_13 ( V_2 -> V_41 , L_59 ) ;
goto V_55;
}
if ( ! ( V_3 & V_369 ) || ( V_3 & V_379 ) )
break;
F_32 ( 1 ) ;
} while ( V_376 -- );
if ( V_376 == 0 )
F_58 ( V_2 -> V_41 , L_60 ) ;
#ifndef F_89
F_90 ( F_91 ( V_2 -> V_41 ) ) ;
#endif
if ( V_5 -> V_335 )
V_5 -> V_335 ( V_3 , V_5 -> V_375 ) ;
else
F_58 ( V_2 -> V_41 , L_61 ) ;
V_55:
return V_214 ;
}
static T_3 F_96 ( int V_211 , void * V_212 )
{
struct V_1 * V_2 = V_212 ;
F_7 ( V_2 -> V_41 , L_62 ) ;
return V_214 ;
}
static T_3 F_97 ( int V_211 , void * V_212 )
{
struct V_1 * V_2 = V_212 ;
F_7 ( V_2 -> V_41 , L_63 ) ;
return V_214 ;
}
static T_3 F_98 ( int V_211 , void * V_212 )
{
struct V_1 * V_2 = V_212 ;
F_99 ( V_2 -> V_41 , L_64 ) ;
return V_214 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_4 * V_5 ;
struct V_380 * V_66 = & V_2 -> V_66 ;
int V_39 , V_93 ;
V_2 -> V_7 = F_101 ( V_2 -> V_41 -> V_381 ) ;
V_6 = V_2 -> V_7 ;
V_5 = F_102 ( sizeof( struct V_4 ) , V_341 ) ;
if ( V_5 == NULL )
return - V_382 ;
F_103 ( V_2 , V_5 ) ;
V_5 -> V_87 = F_104 ( V_2 -> V_41 -> V_381 ) ;
V_5 -> V_2 = V_2 ;
for ( V_93 = 0 ; V_93 < F_63 ( V_5 -> V_206 ) ; V_93 ++ )
F_105 ( & V_5 -> V_206 [ V_93 ] ) ;
if ( V_5 -> V_87 && V_5 -> V_87 -> V_383 )
V_5 -> V_383 = V_5 -> V_87 -> V_383 ;
else if ( V_5 -> V_87 && V_5 -> V_87 -> V_384 )
V_5 -> V_383 = V_5 -> V_87 -> V_384 +
V_385 ;
F_106 ( V_2 -> V_41 ) ;
F_107 ( V_2 -> V_41 ) ;
for ( V_93 = 0 ; V_93 < V_26 ; V_93 ++ ) {
if ( ! F_1 ( V_2 , V_93 ) || F_3 ( V_2 , V_93 ) )
continue;
V_39 = F_11 ( V_2 -> V_7 , V_93 ) ;
if ( V_39 <= 0 )
continue;
V_39 = F_6 ( V_2 , V_93 , V_39 ) ;
if ( V_39 != 0 ) {
F_7 ( V_2 -> V_41 ,
L_65 ,
V_93 , V_39 ) ;
goto V_386;
}
}
V_5 -> V_208 = F_18 ( V_2 , V_30 ) ;
switch ( V_6 -> type ) {
case V_207 :
switch ( V_5 -> V_208 ) {
case 2 :
case 3 :
V_5 -> V_150 . V_387 = - 5 ;
V_5 -> V_150 . V_388 = - 5 ;
V_5 -> V_150 . V_389 = 1 ;
V_5 -> V_150 . V_390 = 1 ;
V_5 -> V_150 . V_391 = 1 ;
break;
default:
V_5 -> V_150 . V_390 = 2 ;
break;
}
break;
case V_25 :
V_5 -> V_150 . V_390 = 1 ;
break;
case V_235 :
V_5 -> V_150 . V_390 = 2 ;
V_5 -> V_150 . V_392 = 1 ;
switch ( V_5 -> V_208 ) {
case 0 :
case 1 :
case 2 :
case 3 :
V_5 -> V_150 . V_387 = - 9 ;
V_5 -> V_150 . V_388 = - 5 ;
break;
default:
break;
}
F_14 ( V_2 , V_393 ,
V_394 , V_394 ) ;
break;
default:
break;
}
F_108 ( V_2 -> V_7 , V_395 ,
F_96 , L_66 , V_2 ) ;
F_108 ( V_2 -> V_7 , V_396 ,
F_97 , L_67 , V_2 ) ;
F_108 ( V_2 -> V_7 , V_397 ,
F_98 , L_68 , V_2 ) ;
V_39 = F_108 ( V_2 -> V_7 , V_398 ,
V_399 , L_69 ,
& V_5 -> V_150 ) ;
if ( V_39 == 0 )
V_5 -> V_150 . V_400 = true ;
switch ( V_6 -> type ) {
case V_207 :
if ( V_5 -> V_383 ) {
V_39 = F_109 ( V_5 -> V_383 , NULL ,
F_88 ,
V_401 ,
L_70 ,
V_5 ) ;
if ( V_39 != 0 )
F_58 ( V_2 -> V_41 ,
L_71 ,
V_39 ) ;
}
V_39 = F_108 ( V_2 -> V_7 ,
V_402 ,
F_88 , L_72 ,
V_5 ) ;
if ( V_39 != 0 )
F_58 ( V_2 -> V_41 ,
L_73 ,
V_39 ) ;
V_39 = F_108 ( V_2 -> V_7 ,
V_403 ,
F_88 , L_74 ,
V_5 ) ;
if ( V_39 != 0 )
F_58 ( V_2 -> V_41 ,
L_75 ,
V_39 ) ;
V_39 = F_108 ( V_2 -> V_7 ,
V_404 ,
F_88 , L_76 ,
V_5 ) ;
if ( V_39 != 0 )
F_58 ( V_2 -> V_41 ,
L_77 ,
V_39 ) ;
break;
case V_25 :
case V_235 :
if ( V_5 -> V_383 ) {
V_39 = F_109 ( V_5 -> V_383 , NULL ,
F_95 ,
V_401 ,
L_78 ,
V_5 ) ;
if ( V_39 != 0 )
F_58 ( V_2 -> V_41 ,
L_79 ,
V_39 ) ;
}
}
V_5 -> V_210 = true ;
for ( V_93 = 0 ; V_93 < F_63 ( V_5 -> V_206 ) ; V_93 ++ ) {
V_39 = F_108 ( V_2 -> V_7 ,
V_405 + V_93 ,
F_59 , L_80 ,
& V_5 -> V_206 [ V_93 ] ) ;
if ( V_39 != 0 )
V_5 -> V_210 = false ;
}
V_39 = F_11 ( V_2 -> V_7 , V_8 ) ;
if ( V_39 < 0 ) {
F_7 ( V_2 -> V_41 , L_81 , V_39 ) ;
goto V_406;
}
if ( ( V_39 & V_407 ) != V_408 ) {
V_5 -> V_283 [ 0 ] = 1 ;
V_409 [ 0 ] . V_410 = 1 ;
} else {
V_5 -> V_283 [ 0 ] = 0 ;
}
V_39 = F_11 ( V_2 -> V_7 , V_13 ) ;
if ( V_39 < 0 ) {
F_7 ( V_2 -> V_41 , L_82 , V_39 ) ;
goto V_406;
}
if ( ( V_39 & V_407 ) != V_408 ) {
V_5 -> V_283 [ 1 ] = 1 ;
V_409 [ 1 ] . V_410 = 1 ;
} else {
V_5 -> V_283 [ 1 ] = 0 ;
}
F_64 ( V_2 , V_230 ) ;
F_14 ( V_2 , V_411 ,
V_412 , V_412 ) ;
F_14 ( V_2 , V_413 ,
V_412 , V_412 ) ;
F_14 ( V_2 , V_414 ,
V_415 , V_415 ) ;
F_14 ( V_2 , V_416 ,
V_415 , V_415 ) ;
F_14 ( V_2 , V_417 ,
V_418 , V_418 ) ;
F_14 ( V_2 , V_419 ,
V_418 , V_418 ) ;
F_14 ( V_2 , V_420 ,
V_421 , V_421 ) ;
F_14 ( V_2 , V_422 ,
V_421 , V_421 ) ;
F_14 ( V_2 , V_423 ,
V_424 , V_424 ) ;
F_14 ( V_2 , V_425 ,
V_424 , V_424 ) ;
F_14 ( V_2 , V_426 ,
V_427 , V_424 ) ;
F_14 ( V_2 , V_428 ,
V_427 , V_424 ) ;
F_14 ( V_2 , V_429 ,
V_430 , V_430 ) ;
F_14 ( V_2 , V_431 ,
V_430 , V_430 ) ;
F_14 ( V_2 , V_432 ,
V_433 , V_433 ) ;
F_14 ( V_2 , V_434 ,
V_433 , V_433 ) ;
F_14 ( V_2 , V_435 ,
1 << V_436 ,
1 << V_436 ) ;
F_14 ( V_2 , V_437 ,
1 << V_438 ,
1 << V_438 ) ;
F_14 ( V_2 , V_439 ,
1 << V_440 ,
1 << V_440 ) ;
switch ( V_6 -> type ) {
case V_207 :
case V_25 :
F_14 ( V_2 , V_242 ,
V_441 , V_441 ) ;
break;
default:
break;
}
F_35 ( V_2 ) ;
F_84 ( V_5 ) ;
F_110 ( V_2 ) ;
F_83 ( V_2 , V_442 ,
F_63 ( V_442 ) ) ;
F_111 ( V_66 , V_443 ,
F_63 ( V_443 ) ) ;
switch ( V_6 -> type ) {
case V_207 :
F_111 ( V_66 , V_444 ,
F_63 ( V_444 ) ) ;
if ( V_5 -> V_208 < 4 ) {
F_111 ( V_66 , V_445 ,
F_63 ( V_445 ) ) ;
F_111 ( V_66 , V_446 ,
F_63 ( V_446 ) ) ;
F_111 ( V_66 , V_447 ,
F_63 ( V_447 ) ) ;
} else {
F_111 ( V_66 , V_448 ,
F_63 ( V_448 ) ) ;
F_111 ( V_66 , V_449 ,
F_63 ( V_449 ) ) ;
F_111 ( V_66 , V_450 ,
F_63 ( V_450 ) ) ;
}
break;
case V_25 :
F_83 ( V_2 , V_451 ,
F_63 ( V_451 ) ) ;
F_111 ( V_66 , V_452 ,
F_63 ( V_452 ) ) ;
if ( V_5 -> V_208 < 1 ) {
F_111 ( V_66 , V_445 ,
F_63 ( V_445 ) ) ;
F_111 ( V_66 , V_446 ,
F_63 ( V_446 ) ) ;
F_111 ( V_66 , V_447 ,
F_63 ( V_447 ) ) ;
} else {
F_111 ( V_66 , V_448 ,
F_63 ( V_448 ) ) ;
F_111 ( V_66 , V_449 ,
F_63 ( V_449 ) ) ;
F_111 ( V_66 , V_450 ,
F_63 ( V_450 ) ) ;
}
break;
case V_235 :
F_83 ( V_2 , V_451 ,
F_63 ( V_451 ) ) ;
F_111 ( V_66 , V_452 ,
F_63 ( V_452 ) ) ;
F_111 ( V_66 , V_448 ,
F_63 ( V_448 ) ) ;
F_111 ( V_66 , V_449 ,
F_63 ( V_449 ) ) ;
F_111 ( V_66 , V_450 ,
F_63 ( V_450 ) ) ;
break;
}
F_112 ( V_2 , 0 , 0 ) ;
F_113 ( V_66 , V_453 , F_63 ( V_453 ) ) ;
switch ( V_6 -> type ) {
case V_207 :
F_113 ( V_66 , V_454 ,
F_63 ( V_454 ) ) ;
if ( V_5 -> V_208 < 4 ) {
F_113 ( V_66 , V_455 ,
F_63 ( V_455 ) ) ;
F_113 ( V_66 , V_456 ,
F_63 ( V_456 ) ) ;
} else {
F_113 ( V_66 , V_457 ,
F_63 ( V_457 ) ) ;
}
break;
case V_25 :
if ( V_5 -> V_208 < 1 ) {
F_113 ( V_66 , V_455 ,
F_63 ( V_455 ) ) ;
F_113 ( V_66 , V_456 ,
F_63 ( V_456 ) ) ;
} else {
F_113 ( V_66 , V_457 ,
F_63 ( V_457 ) ) ;
F_113 ( V_66 , V_458 ,
F_63 ( V_458 ) ) ;
}
F_114 ( V_2 ) ;
break;
case V_235 :
F_113 ( V_66 , V_457 ,
F_63 ( V_457 ) ) ;
F_113 ( V_66 , V_458 ,
F_63 ( V_458 ) ) ;
break;
}
return 0 ;
V_406:
F_115 ( V_2 -> V_7 , V_404 , V_5 ) ;
F_115 ( V_2 -> V_7 , V_403 , V_5 ) ;
F_115 ( V_2 -> V_7 , V_402 , V_5 ) ;
if ( V_5 -> V_383 )
F_116 ( V_5 -> V_383 , V_5 ) ;
for ( V_93 = 0 ; V_93 < F_63 ( V_5 -> V_206 ) ; V_93 ++ )
F_115 ( V_2 -> V_7 , V_405 + V_93 ,
& V_5 -> V_206 [ V_93 ] ) ;
F_115 ( V_2 -> V_7 , V_398 ,
& V_5 -> V_150 ) ;
F_115 ( V_2 -> V_7 , V_395 , V_2 ) ;
F_115 ( V_2 -> V_7 , V_397 , V_2 ) ;
F_115 ( V_2 -> V_7 , V_396 , V_2 ) ;
V_386:
F_117 ( V_5 ) ;
return V_39 ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_93 ;
F_64 ( V_2 , V_232 ) ;
F_119 ( V_2 -> V_41 ) ;
for ( V_93 = 0 ; V_93 < F_63 ( V_5 -> V_206 ) ; V_93 ++ )
F_115 ( V_2 -> V_7 , V_405 + V_93 ,
& V_5 -> V_206 [ V_93 ] ) ;
F_115 ( V_2 -> V_7 , V_398 ,
& V_5 -> V_150 ) ;
F_115 ( V_2 -> V_7 , V_395 , V_2 ) ;
F_115 ( V_2 -> V_7 , V_397 , V_2 ) ;
F_115 ( V_2 -> V_7 , V_396 , V_2 ) ;
switch ( V_6 -> type ) {
case V_207 :
if ( V_5 -> V_383 )
F_116 ( V_5 -> V_383 , V_5 ) ;
F_115 ( V_2 -> V_7 , V_403 ,
V_5 ) ;
F_115 ( V_2 -> V_7 , V_402 ,
V_5 ) ;
F_115 ( V_2 -> V_7 , V_385 ,
V_5 ) ;
break;
case V_235 :
case V_25 :
if ( V_5 -> V_383 )
F_116 ( V_5 -> V_383 , V_5 ) ;
break;
}
if ( V_5 -> V_459 )
F_120 ( V_5 -> V_459 ) ;
if ( V_5 -> V_460 )
F_120 ( V_5 -> V_460 ) ;
if ( V_5 -> V_461 )
F_120 ( V_5 -> V_461 ) ;
F_117 ( V_5 -> V_114 ) ;
F_117 ( V_5 -> V_353 ) ;
F_117 ( V_5 ) ;
return 0 ;
}
static int T_6 F_121 ( struct V_462 * V_463 )
{
return F_122 ( & V_463 -> V_41 , & V_464 ,
V_409 , F_63 ( V_409 ) ) ;
}
static int T_7 F_123 ( struct V_462 * V_463 )
{
F_124 ( & V_463 -> V_41 ) ;
return 0 ;
}
static T_8 int F_125 ( void )
{
return F_126 ( & V_465 ) ;
}
static T_9 void F_127 ( void )
{
F_128 ( & V_465 ) ;
}

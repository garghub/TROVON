static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_11 * V_12 = & V_10 -> V_12 [ V_10 -> V_13 ] ;
unsigned int V_14 ;
unsigned int V_15 ;
unsigned int V_16 ;
F_2 ( V_10 -> V_17 ) ;
V_14 = V_7 -> V_18 ? F_3 ( V_4 ) : V_12 -> V_19 ;
V_15 = F_4 ( V_4 , V_14 ) ;
V_16 = F_5 ( V_4 , V_15 + V_5 ) ;
if ( V_16 > V_5 ) {
V_16 -= V_5 ;
V_12 -> V_20 = F_6 ( V_4 , V_16 ) ;
F_7 ( V_12 ) ;
}
}
static void F_8 ( struct V_1 * V_2 ,
unsigned int V_21 , char V_22 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_17 = F_9 ( V_21 ) ;
unsigned int V_23 = F_10 ( V_21 ) ;
unsigned int V_24 = 0 ;
if ( V_21 == V_7 -> V_25 )
return;
V_7 -> V_25 = V_21 ;
if ( V_7 -> V_26 ) {
if ( V_7 -> V_27 ) {
V_24 |= V_28 | V_29 ;
} else {
if ( V_17 < 8 )
V_24 |= V_28 ;
else
V_24 |= V_29 ;
}
}
F_11 ( V_24 | F_12 ( V_17 ) , V_2 -> V_30 + V_31 ) ;
F_11 ( V_23 + V_7 -> V_32 , V_2 -> V_30 + V_33 ) ;
if ( V_22 )
F_13 ( V_7 -> V_34 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_11 ( 0 , V_2 -> V_30 + V_35 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_11 ( 255 , V_2 -> V_30 + V_36 ) ;
}
static unsigned int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_37 ;
V_37 = F_17 ( V_2 -> V_30 + V_38 ) << 8 ;
V_37 |= F_17 ( V_2 -> V_30 + V_39 ) ;
return V_37 & V_4 -> V_40 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
unsigned long V_43 )
{
unsigned int V_44 ;
if ( V_4 -> V_40 > 0x0fff ) {
V_44 = F_17 ( V_2 -> V_30 + V_35 ) ;
if ( ( V_44 & V_45 ) == 0 )
return 0 ;
} else {
V_44 = F_17 ( V_2 -> V_30 + V_38 ) ;
if ( ( V_44 & V_46 ) == 0 )
return 0 ;
}
return - V_47 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_48 * V_49 )
{
const struct V_50 * V_51 = V_2 -> V_52 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_53 = 0 ;
unsigned int V_54 ;
V_53 |= F_20 ( & V_49 -> V_55 , V_56 ) ;
V_53 |= F_20 ( & V_49 -> V_57 , V_58 ) ;
if ( V_7 -> V_59 )
V_54 = V_60 ;
else
V_54 = V_61 ;
V_53 |= F_20 ( & V_49 -> V_62 , V_54 ) ;
V_53 |= F_20 ( & V_49 -> V_63 , V_64 ) ;
V_53 |= F_20 ( & V_49 -> V_65 , V_64 | V_66 ) ;
if ( V_53 )
return 1 ;
V_53 |= F_21 ( V_49 -> V_65 ) ;
if ( V_53 )
return 2 ;
V_53 |= F_22 ( & V_49 -> V_67 , 0 ) ;
V_53 |= F_22 ( & V_49 -> V_68 , 0 ) ;
if ( V_49 -> V_62 == V_61 ) {
V_53 |= F_23 ( & V_49 -> V_69 ,
V_51 -> V_70 ) ;
} else {
V_53 |= F_22 ( & V_49 -> V_69 , 0 ) ;
}
V_53 |= F_23 ( & V_49 -> V_71 , 1 ) ;
V_53 |= F_22 ( & V_49 -> V_72 ,
V_49 -> V_71 ) ;
if ( V_49 -> V_65 == V_64 )
V_53 |= F_23 ( & V_49 -> V_73 , 1 ) ;
else
V_53 |= F_22 ( & V_49 -> V_73 , 0 ) ;
if ( V_53 )
return 3 ;
if ( V_49 -> V_62 == V_61 ) {
unsigned int V_74 = V_49 -> V_69 ;
F_24 ( V_2 -> V_75 , & V_74 , V_49 -> V_54 ) ;
V_53 |= F_22 ( & V_49 -> V_69 , V_74 ) ;
}
if ( V_53 )
return 4 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_48 * V_49 = & V_4 -> V_76 -> V_49 ;
unsigned int V_77 = 0 ;
unsigned int V_78 ;
F_8 ( V_2 , V_49 -> V_79 [ 0 ] , 1 ) ;
if ( V_10 ) {
V_7 -> V_80 = 1 ;
for ( V_78 = 1 ; V_78 < V_49 -> V_71 ; V_78 ++ )
if ( V_49 -> V_79 [ 0 ] != V_49 -> V_79 [ V_78 ] ) {
V_7 -> V_80 = 0 ;
break;
}
} else {
V_7 -> V_80 = 0 ;
}
V_7 -> V_81 = 0 ;
if ( V_49 -> V_54 & V_82 ) {
V_7 -> V_18 = 1 ;
if ( V_49 -> V_71 == 1 )
V_7 -> V_80 = 0 ;
}
if ( V_7 -> V_80 ) {
V_10 -> V_13 = 0 ;
F_1 ( V_2 , V_4 , 0 ) ;
}
switch ( V_49 -> V_62 ) {
case V_61 :
F_26 ( V_2 -> V_75 ) ;
F_27 ( V_2 -> V_75 , 1 , 2 , true ) ;
break;
}
if ( V_7 -> V_80 )
V_77 |= V_83 ;
else
V_77 |= V_84 ;
F_11 ( V_7 -> V_85 | V_77 , V_2 -> V_30 + V_86 ) ;
return 0 ;
}
static bool F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_48 * V_49 = & V_4 -> V_76 -> V_49 ;
if ( V_49 -> V_65 == V_64 &&
V_4 -> V_76 -> V_87 >= V_49 -> V_73 ) {
V_4 -> V_76 -> V_88 |= V_89 ;
return false ;
}
return true ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_48 * V_49 = & V_4 -> V_76 -> V_49 ;
unsigned int V_17 = V_4 -> V_76 -> V_90 ;
unsigned int V_91 ;
unsigned short V_37 ;
if ( F_18 ( V_2 , V_4 , NULL , 0 ) ) {
F_30 ( V_2 -> V_92 , L_1 ) ;
V_4 -> V_76 -> V_88 |= V_93 ;
return;
}
V_37 = F_16 ( V_2 , V_4 ) ;
F_31 ( V_4 , & V_37 , 1 ) ;
V_91 = V_4 -> V_76 -> V_90 ;
if ( V_49 -> V_79 [ V_17 ] != V_49 -> V_79 [ V_91 ] )
F_8 ( V_2 , V_49 -> V_79 [ V_91 ] , 0 ) ;
F_28 ( V_2 , V_4 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned short * V_94 ,
unsigned int V_95 , unsigned int V_96 )
{
unsigned int V_78 ;
unsigned short V_37 ;
for ( V_78 = V_96 ; V_78 ; V_78 -- ) {
V_37 = V_94 [ V_95 ++ ] ;
F_31 ( V_4 , & V_37 , 1 ) ;
if ( ! F_28 ( V_2 , V_4 ) )
break;
}
}
static void F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_11 * V_12 = & V_10 -> V_12 [ V_10 -> V_13 ] ;
unsigned int V_16 ;
int V_95 ;
V_16 = F_4 ( V_4 , V_12 -> V_20 ) -
V_7 -> V_81 ;
V_95 = V_7 -> V_81 ;
V_7 -> V_81 = 0 ;
V_10 -> V_13 = 1 - V_10 -> V_13 ;
F_1 ( V_2 , V_4 , V_16 ) ;
F_32 ( V_2 , V_4 , V_12 -> V_97 , V_95 , V_16 ) ;
}
static T_1 F_34 ( int V_98 , void * V_99 )
{
struct V_1 * V_2 = V_99 ;
struct V_3 * V_4 = V_2 -> V_100 ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! V_2 -> V_101 ) {
F_14 ( V_2 ) ;
return V_102 ;
}
if ( V_7 -> V_80 )
F_33 ( V_2 , V_4 ) ;
else
F_29 ( V_2 , V_4 ) ;
F_14 ( V_2 ) ;
F_35 ( V_2 , V_4 ) ;
return V_102 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_11 * V_12 ;
unsigned long V_54 ;
unsigned int V_103 ;
int V_104 ;
if ( ! V_7 -> V_80 )
return 0 ;
F_37 ( & V_2 -> V_105 , V_54 ) ;
V_103 = F_38 ( V_10 ) ;
V_103 = F_4 ( V_4 , V_103 ) ;
if ( V_103 > V_7 -> V_81 ) {
V_12 = & V_10 -> V_12 [ V_10 -> V_13 ] ;
F_32 ( V_2 , V_4 , V_12 -> V_97 ,
V_7 -> V_81 ,
V_103 - V_7 -> V_81 ) ;
V_7 -> V_81 = V_103 ;
V_104 = F_39 ( V_4 ) ;
} else {
V_104 = 0 ;
}
F_40 ( & V_2 -> V_105 , V_54 ) ;
return V_104 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_7 -> V_80 )
F_2 ( V_7 -> V_10 -> V_17 ) ;
F_11 ( V_7 -> V_85 | V_106 ,
V_2 -> V_30 + V_86 ) ;
F_27 ( V_2 -> V_75 , 1 , 2 , false ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
unsigned int * V_107 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_104 = 0 ;
int V_78 ;
F_11 ( V_7 -> V_85 | V_108 ,
V_2 -> V_30 + V_86 ) ;
F_8 ( V_2 , V_42 -> V_21 , 1 ) ;
for ( V_78 = 0 ; V_78 < V_42 -> V_109 ; V_78 ++ ) {
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
V_104 = F_43 ( V_2 , V_4 , V_42 , F_18 , 0 ) ;
if ( V_104 )
break;
V_107 [ V_78 ] = F_16 ( V_2 , V_4 ) ;
}
F_11 ( V_7 -> V_85 | V_106 ,
V_2 -> V_30 + V_86 ) ;
F_14 ( V_2 ) ;
return V_104 ? V_104 : V_42 -> V_109 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
unsigned int * V_107 )
{
unsigned int V_17 = F_9 ( V_42 -> V_21 ) ;
unsigned int V_37 = V_4 -> V_110 [ V_17 ] ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_42 -> V_109 ; V_78 ++ ) {
V_37 = V_107 [ V_78 ] ;
F_11 ( V_37 & 0xff , V_2 -> V_30 + F_45 ( V_17 ) ) ;
F_11 ( ( V_37 >> 8 ) & 0x0f , V_2 -> V_30 + F_46 ( V_17 ) ) ;
}
V_4 -> V_110 [ V_17 ] = V_37 ;
return V_42 -> V_109 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
unsigned int * V_107 )
{
V_107 [ 1 ] = F_17 ( V_2 -> V_30 + V_111 ) |
( F_17 ( V_2 -> V_30 + V_112 ) << 8 ) ;
return V_42 -> V_109 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
unsigned int * V_107 )
{
if ( F_49 ( V_4 , V_107 ) ) {
F_11 ( V_4 -> V_113 & 0xff , V_2 -> V_30 + V_114 ) ;
F_11 ( ( V_4 -> V_113 >> 8 ) , V_2 -> V_30 + V_115 ) ;
}
V_107 [ 1 ] = V_4 -> V_113 ;
return V_42 -> V_109 ;
}
static void F_50 ( struct V_1 * V_2 )
{
const struct V_50 * V_51 = V_2 -> V_52 ;
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_17 ;
F_11 ( V_7 -> V_85 | V_106 ,
V_2 -> V_30 + V_86 ) ;
F_14 ( V_2 ) ;
V_7 -> V_25 = F_51 ( 16 , 0 , 0 ) ;
F_8 ( V_2 , F_51 ( 0 , 0 , 0 ) , 0 ) ;
for ( V_17 = 0 ; V_17 < V_51 -> V_116 ; V_17 ++ ) {
F_11 ( 0 , V_2 -> V_30 + F_45 ( V_17 ) ) ;
F_11 ( 0 , V_2 -> V_30 + F_46 ( V_17 ) ) ;
}
if ( V_51 -> V_117 ) {
F_11 ( 0 , V_2 -> V_30 + V_115 ) ;
F_11 ( 0 , V_2 -> V_30 + V_114 ) ;
}
}
static void F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_118 * V_119 )
{
const struct V_50 * V_51 = V_2 -> V_52 ;
struct V_6 * V_7 = V_2 -> V_8 ;
switch ( V_51 -> V_120 ) {
case V_121 :
if ( V_119 -> V_122 [ 4 ] == 1 )
V_4 -> V_123 = & V_124 ;
else
V_4 -> V_123 = V_51 -> V_125 ;
break;
case V_126 :
switch ( V_119 -> V_122 [ 4 ] ) {
case 0 :
V_4 -> V_123 = & V_127 ;
break;
case 1 :
V_4 -> V_123 = & V_128 ;
break;
case 2 :
V_4 -> V_123 = & V_129 ;
break;
case 3 :
V_4 -> V_123 = & V_130 ;
break;
case 4 :
V_4 -> V_123 = & V_131 ;
break;
case 5 :
V_4 -> V_123 = & V_132 ;
break;
default:
V_4 -> V_123 = & V_127 ;
break;
}
break;
case V_133 :
if ( V_119 -> V_122 [ 1 ] == 1 )
V_4 -> V_123 = & V_134 ;
else
V_4 -> V_123 = V_51 -> V_125 ;
break;
case V_135 :
switch ( V_119 -> V_122 [ 1 ] ) {
case 0 :
V_4 -> V_123 = & V_136 ;
break;
case 1 :
V_4 -> V_123 = & V_137 ;
break;
case 2 :
V_4 -> V_123 = & V_138 ;
V_7 -> V_32 = 1 ;
break;
case 3 :
V_4 -> V_123 = & V_139 ;
V_7 -> V_32 = 1 ;
break;
default:
V_4 -> V_123 = & V_136 ;
break;
}
break;
case V_140 :
switch ( V_119 -> V_122 [ 1 ] ) {
case 0 :
V_4 -> V_123 = & V_141 ;
break;
case 1 :
V_4 -> V_123 = & V_142 ;
break;
case 2 :
V_4 -> V_123 = & V_143 ;
V_7 -> V_32 = 1 ;
break;
case 3 :
V_4 -> V_123 = & V_144 ;
V_7 -> V_32 = 1 ;
break;
default:
V_4 -> V_123 = & V_141 ;
break;
}
break;
default:
V_4 -> V_123 = V_51 -> V_125 ;
break;
}
}
static void F_53 ( struct V_1 * V_2 , unsigned int V_145 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! ( V_145 == 3 || V_145 == 1 ) )
return;
V_7 -> V_10 = F_54 ( V_2 , 2 , V_145 , V_145 ,
V_146 * 2 , V_147 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_7 )
F_56 ( V_7 -> V_10 ) ;
}
static int F_57 ( struct V_1 * V_2 , struct V_118 * V_119 )
{
const struct V_50 * V_51 = V_2 -> V_52 ;
struct V_6 * V_7 ;
struct V_3 * V_4 ;
int V_148 ;
int V_149 ;
int V_104 ;
V_7 = F_58 ( V_2 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_150 ;
V_104 = F_59 ( V_2 , V_119 -> V_122 [ 0 ] , 0x10 ) ;
if ( V_104 )
return V_104 ;
if ( V_51 -> V_151 ) {
V_2 -> V_75 = F_60 ( V_2 -> V_30 + V_152 ,
V_153 ,
V_154 , 0 ) ;
if ( ! V_2 -> V_75 )
return - V_150 ;
if ( ( 1 << V_119 -> V_122 [ 1 ] ) & V_51 -> V_151 ) {
V_104 = F_61 ( V_119 -> V_122 [ 1 ] , F_34 , 0 ,
V_2 -> V_155 , V_2 ) ;
if ( V_104 == 0 )
V_2 -> V_98 = V_119 -> V_122 [ 1 ] ;
}
}
if ( V_2 -> V_98 && V_51 -> V_156 )
F_53 ( V_2 , V_119 -> V_122 [ 2 ] ) ;
switch ( V_51 -> V_120 ) {
case V_157 :
if ( V_119 -> V_122 [ 2 ] == 1 )
V_7 -> V_27 = 1 ;
break;
case V_158 :
case V_159 :
if ( V_119 -> V_122 [ 4 ] == 1 )
V_7 -> V_27 = 1 ;
break;
default:
break;
}
V_148 = 1 ;
if ( V_51 -> V_116 > 0 )
V_148 ++ ;
if ( V_51 -> V_117 )
V_148 += 2 ;
V_104 = F_62 ( V_2 , V_148 ) ;
if ( V_104 )
return V_104 ;
V_149 = 0 ;
V_4 = & V_2 -> V_160 [ V_149 ] ;
V_4 -> type = V_161 ;
V_4 -> V_162 = V_163 ;
if ( V_7 -> V_27 ) {
V_4 -> V_162 |= V_164 ;
V_4 -> V_165 = V_51 -> V_166 / 2 ;
} else {
V_4 -> V_162 |= V_167 ;
V_4 -> V_165 = V_51 -> V_166 ;
}
V_4 -> V_40 = V_51 -> V_168 ? 0xffff : 0x0fff ;
F_52 ( V_2 , V_4 , V_119 ) ;
V_4 -> V_169 = F_42 ;
if ( V_2 -> V_98 ) {
V_2 -> V_100 = V_4 ;
V_4 -> V_162 |= V_170 ;
V_4 -> V_171 = V_172 ;
V_4 -> V_173 = F_19 ;
V_4 -> V_174 = F_25 ;
V_4 -> V_103 = F_36 ;
V_4 -> V_175 = F_41 ;
}
V_7 -> V_26 = V_51 -> V_176 ;
V_149 ++ ;
if ( V_51 -> V_116 > 0 ) {
V_4 = & V_2 -> V_160 [ V_149 ] ;
V_4 -> type = V_177 ;
V_4 -> V_162 = V_178 | V_167 ;
V_4 -> V_165 = V_51 -> V_116 ;
V_4 -> V_40 = 0xfff ;
switch ( V_51 -> V_120 ) {
case V_157 :
if ( V_119 -> V_122 [ 3 ] == 1 )
V_4 -> V_123 = & V_179 ;
else
V_4 -> V_123 = & V_180 ;
break;
case V_126 :
case V_158 :
case V_121 :
case V_159 :
switch ( V_119 -> V_122 [ 5 ] ) {
case 1 :
V_4 -> V_123 = & V_179 ;
break;
case 2 :
V_4 -> V_123 = & V_181 ;
break;
default:
V_4 -> V_123 = & V_180 ;
break;
}
break;
default:
V_4 -> V_123 = & V_180 ;
break;
}
V_4 -> V_182 = F_44 ;
V_104 = F_63 ( V_4 ) ;
if ( V_104 )
return V_104 ;
V_149 ++ ;
}
if ( V_51 -> V_117 ) {
V_4 = & V_2 -> V_160 [ V_149 ] ;
V_4 -> type = V_183 ;
V_4 -> V_162 = V_163 ;
V_4 -> V_165 = 16 ;
V_4 -> V_40 = 1 ;
V_4 -> V_123 = & V_184 ;
V_4 -> V_185 = F_47 ;
V_149 ++ ;
V_4 = & V_2 -> V_160 [ V_149 ] ;
V_4 -> type = V_186 ;
V_4 -> V_162 = V_178 ;
V_4 -> V_165 = 16 ;
V_4 -> V_40 = 1 ;
V_4 -> V_123 = & V_184 ;
V_4 -> V_185 = F_48 ;
V_149 ++ ;
}
switch ( V_51 -> V_120 ) {
case V_159 :
case V_121 :
case V_126 :
case V_158 :
V_7 -> V_34 = 1 ;
if ( V_119 -> V_122 [ 3 ] > 0 )
V_7 -> V_59 = 1 ;
break;
case V_157 :
V_7 -> V_34 = 1 ;
V_7 -> V_85 = ( V_2 -> V_98 << 4 ) & 0xf0 ;
break;
case V_133 :
case V_187 :
case V_135 :
case V_140 :
V_7 -> V_34 = 5 ;
break;
}
F_50 ( V_2 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_55 ( V_2 ) ;
F_65 ( V_2 ) ;
}

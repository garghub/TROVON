void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 , V_4 = 0 ;
T_1 V_5 = 0 , V_6 = 0 ;
T_2 V_7 = 0 ;
if ( V_2 -> V_8 )
return;
F_2 ( V_2 -> V_9 ,
V_10 , & V_4 ) ;
F_2 ( V_2 -> V_9 ,
V_11 ,
& V_6 ) ;
F_2 ( V_2 -> V_9 ,
V_12 ,
& V_3 ) ;
F_2 ( V_2 -> V_9 ,
V_13 ,
& V_5 ) ;
V_4 = ( V_4 & ~ V_6 ) ;
V_3 = ( V_3 & ~ V_5 ) ;
if ( V_4 || V_3 ) {
V_2 -> V_8 = true ;
F_3 ( V_2 , V_14 ,
V_15 | V_16 ,
L_1 ) ;
}
if ( V_4 ) {
for ( V_7 = 0 ; V_4 ; V_4 >>= 1 , V_7 ++ ) {
if ( V_4 & 1 )
F_3 ( V_2 , V_14 ,
V_15 ,
L_2 ,
V_17 [ V_7 ] ) ;
}
}
if ( V_3 ) {
for ( V_7 = 0 ; V_3 ; V_3 >>= 1 , V_7 ++ ) {
if ( V_3 & 1 )
F_3 ( V_2 , V_14 ,
V_15 ,
L_3 ,
V_18 [ V_7 ] ) ;
}
}
}
unsigned int F_4 ( struct V_1 * V_2 ,
unsigned int V_19 ,
unsigned int V_20 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
unsigned int V_27 = 0 ;
F_3 ( V_2 , V_28 ,
V_15 | V_16 ,
L_4 ) ;
F_5 ( & V_22 -> V_29 ) ;
V_27 = F_6 ( V_2 ) ;
if ( ! V_27 ) {
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
V_24 = F_8 ( V_2 ) ;
V_26 = F_9 ( V_24 ) ;
V_24 -> V_30 |= V_27 ;
F_10 ( V_24 , sizeof( * V_26 ) , true , 0 ) ;
F_11 ( & V_26 -> V_31 , V_32 ,
V_33 ,
sizeof( struct V_34 ) ) ;
V_26 -> V_19 = V_19 ;
V_26 -> V_35 = V_20 ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
unsigned int F_13 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 ;
struct V_36 * V_26 ;
unsigned int V_27 = 0 ;
F_3 ( V_2 , V_28 ,
V_15 | V_16 ,
L_4 ) ;
F_5 ( & V_22 -> V_29 ) ;
V_27 = F_6 ( V_2 ) ;
if ( ! V_27 ) {
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
V_24 = F_8 ( V_2 ) ;
V_26 = F_9 ( V_24 ) ;
V_24 -> V_30 |= V_27 ;
F_10 ( V_24 , sizeof( * V_26 ) , true , 0 ) ;
F_11 ( & V_26 -> V_31 , V_32 ,
V_37 ,
sizeof( struct V_38 ) ) ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
unsigned int F_14 ( struct V_1 * V_2 ,
T_3 V_39 ,
struct V_40 * V_41 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 ;
unsigned int V_27 = 0 ;
struct V_42 * V_26 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
F_3 ( V_2 , V_28 ,
V_15 | V_16 ,
L_5 ) ;
F_5 ( & V_22 -> V_29 ) ;
V_27 = F_6 ( V_2 ) ;
if ( ! V_27 ) {
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
V_41 -> V_47 = sizeof( * V_44 ) ;
V_26 = V_41 -> V_48 ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
V_24 = F_8 ( V_2 ) ;
V_46 = F_15 ( V_24 ) ;
V_24 -> V_30 |= V_27 ;
V_24 -> V_30 |= V_27 ;
F_10 ( V_24 , sizeof( * V_26 ) , false , 1 ) ;
F_11 ( & V_26 -> V_31 , V_32 ,
V_49 ,
sizeof( * V_44 ) ) ;
V_26 -> V_35 = V_39 ;
V_46 -> V_50 = F_16 ( F_17 ( V_41 -> V_51 ) ) ;
V_46 -> V_52 = F_16 ( V_41 -> V_51 & 0xFFFFFFFF ) ;
V_46 -> V_53 = F_16 ( V_41 -> V_47 ) ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
int F_18 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_23 * V_24 = F_19 ( & V_22 -> V_54 ) ;
struct V_55 * V_26 = F_9 ( V_24 ) ;
int V_56 = 0 ;
F_5 ( & V_22 -> V_29 ) ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
F_10 ( V_24 , sizeof( * V_26 ) , true , 0 ) ;
F_11 ( & V_26 -> V_31 , V_57 ,
V_58 , sizeof( * V_26 ) ) ;
V_56 = F_20 ( V_22 ) ;
if ( ! V_56 ) {
struct V_55 * V_59 ;
V_59 = V_26 ;
V_2 -> V_60 . V_61 = V_59 -> V_61 ;
V_2 -> V_60 . V_62 =
V_59 -> V_63 [ 0 ] . V_64 ;
V_2 -> V_60 . V_65 =
V_59 -> V_63 [ 0 ] . V_66 ;
V_2 -> V_60 . V_67 =
V_59 -> V_63 [ 0 ] . V_68 ;
V_2 -> V_60 . V_69 =
V_59 -> V_63 [ 0 ] . V_70 ;
if ( V_2 -> V_60 . V_69 > ( V_71 / 2 ) ) {
F_3 ( V_2 , V_28 , V_72 ,
L_6
L_7 ,
V_2 -> V_60 . V_69 ,
V_71 ) ;
V_2 -> V_60 . V_69 = V_71 / 2 ;
}
} else {
F_3 ( V_2 , V_73 , V_72 ,
L_8 ) ;
}
F_7 ( & V_22 -> V_29 ) ;
return V_56 ;
}
int F_21 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_40 V_41 ;
struct V_23 * V_24 = F_19 ( & V_22 -> V_54 ) ;
struct V_74 * V_26 ;
struct V_45 * V_46 = F_15 ( V_24 ) ;
int V_56 = 0 ;
V_41 . V_48 = F_22 ( V_22 -> V_75 ,
sizeof( struct V_74 ) ,
& V_41 . V_51 ) ;
if ( V_41 . V_48 == NULL ) {
F_3 ( V_2 , V_14 , V_72 ,
L_9
L_10 ) ;
return - V_76 ;
}
V_41 . V_47 = sizeof( struct V_74 ) ;
V_26 = V_41 . V_48 ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
F_5 ( & V_22 -> V_29 ) ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
F_10 ( V_24 , sizeof( * V_26 ) , false , 1 ) ;
F_11 ( & V_26 -> V_31 , V_57 ,
V_77 , sizeof( * V_26 ) ) ;
V_46 -> V_50 = F_16 ( F_17 ( V_41 . V_51 ) ) ;
V_46 -> V_52 = F_16 ( V_41 . V_51 & 0xFFFFFFFF ) ;
V_46 -> V_53 = F_16 ( V_41 . V_47 ) ;
V_56 = F_20 ( V_22 ) ;
if ( ! V_56 ) {
struct V_78 * V_44 = V_41 . V_48 ;
F_3 ( V_2 , V_28 , V_72 ,
L_11
L_12
L_13 ,
V_44 -> V_79 . V_80
. V_81 ,
V_44 -> V_79 . V_80 .
V_82 ) ;
V_2 -> V_60 . V_83 =
V_44 -> V_79 . V_80 . V_83 ;
F_3 ( V_2 , V_28 , V_72 ,
L_14 ,
V_2 -> V_60 . V_83 ) ;
memcpy ( V_2 -> V_84 , V_44 -> V_79 . V_80 .
V_82 , V_85 ) ;
} else
F_3 ( V_2 , V_14 , V_72 ,
L_15 ) ;
F_7 ( & V_22 -> V_29 ) ;
if ( V_41 . V_48 )
F_23 ( V_22 -> V_75 , V_41 . V_47 ,
V_41 . V_48 , V_41 . V_51 ) ;
return V_56 ;
}
unsigned int F_24 ( struct V_21 * V_22 ,
struct V_1 * V_2 ,
struct V_86 * V_87 ,
struct V_40 * V_41 )
{
struct V_88 * V_44 ;
struct V_23 * V_24 = F_8 ( V_2 ) ;
struct V_45 * V_89 = F_15 ( V_24 ) ;
unsigned int V_27 = 0 ;
struct V_90 * V_91 = V_87 -> V_92 ;
struct V_93 * V_26 = V_41 -> V_48 ;
unsigned short V_94 , V_95 , V_96 , V_97 ;
V_41 -> V_47 = V_87 -> V_98 . V_99 ;
memset ( V_41 -> V_48 , 0 , V_41 -> V_47 ) ;
V_44 = V_41 -> V_48 ;
V_94 = V_91 -> V_100 . V_101 . V_102 [ 1 ] ;
V_95 = V_91 -> V_100 . V_101 . V_102 [ 2 ] ;
V_96 = V_91 -> V_100 . V_101 . V_102 [ 3 ] ;
V_97 = V_91 -> V_100 . V_101 . V_102 [ 4 ] ;
V_26 -> V_94 = V_94 ;
V_26 -> V_96 = V_96 ;
V_26 -> V_97 = V_97 ;
F_5 ( & V_22 -> V_29 ) ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
switch ( V_91 -> V_100 . V_101 . V_102 [ 0 ] ) {
case V_103 :
V_97 = V_96 * V_95 + V_97 ;
F_11 ( & V_26 -> V_31 , V_104 ,
V_105 , sizeof( * V_26 ) ) ;
F_25 ( V_87 -> V_98 . V_106 ,
V_87 -> V_98 . V_107 ,
V_41 -> V_48 + V_97 , V_87 -> V_108 ) ;
break;
case V_109 :
F_11 ( & V_26 -> V_31 , V_104 ,
V_110 , sizeof( * V_26 ) ) ;
break;
default:
F_3 ( V_2 , V_73 , V_15 ,
L_16 ,
V_91 -> V_100 . V_101 . V_102 [ 0 ] ) ;
F_7 ( & V_22 -> V_29 ) ;
return - V_111 ;
}
V_27 = F_6 ( V_2 ) ;
if ( ! V_27 ) {
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
F_10 ( V_24 , V_41 -> V_47 , false ,
V_87 -> V_98 . V_107 ) ;
V_89 -> V_50 = F_16 ( F_17 ( V_41 -> V_51 ) ) ;
V_89 -> V_52 = F_16 ( V_41 -> V_51 & 0xFFFFFFFF ) ;
V_89 -> V_53 = F_16 ( V_41 -> V_47 ) ;
V_24 -> V_30 |= V_27 ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
int F_26 ( struct V_1 * V_2 , unsigned short V_112 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 = F_8 ( V_2 ) ;
struct V_113 * V_26 = F_9 ( V_24 ) ;
int V_56 = 0 ;
F_5 ( & V_22 -> V_29 ) ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
F_10 ( V_24 , sizeof( * V_26 ) , true , 0 ) ;
F_11 ( & V_26 -> V_31 , V_104 ,
V_114 , sizeof( * V_26 ) ) ;
V_26 -> V_112 = V_112 ;
V_26 -> V_115 = F_27 ( F_28 ( V_2 ) ) ;
V_26 -> V_116 = F_27 ( F_29 ( V_2 ) ) ;
V_56 = F_30 ( V_2 ) ;
if ( V_56 )
F_3 ( V_2 , V_73 , V_72 ,
L_17 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_56 ;
}
unsigned int F_31 ( struct V_1 * V_2 ,
struct V_117 * V_118 ,
unsigned int V_119 , unsigned int V_120 ,
struct V_40 * V_41 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 ;
struct V_45 * V_46 ;
struct V_121 * V_26 ;
unsigned int V_7 , V_27 = 0 ;
F_5 ( & V_22 -> V_29 ) ;
V_27 = F_6 ( V_2 ) ;
if ( ! V_27 ) {
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
V_26 = V_41 -> V_48 ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
V_24 = F_8 ( V_2 ) ;
V_46 = F_15 ( V_24 ) ;
V_24 -> V_30 |= V_27 ;
F_10 ( V_24 , sizeof( * V_26 ) , false , 1 ) ;
F_11 ( & V_26 -> V_31 , V_104 ,
V_122 ,
sizeof( * V_26 ) ) ;
V_26 -> V_123 = 0 ;
V_26 -> V_124 = V_125 ;
for ( V_7 = 0 ; V_7 < V_119 ; V_7 ++ ) {
V_26 -> V_126 [ V_7 ] . V_127 = V_118 -> V_127 ;
V_26 -> V_126 [ V_7 ] . V_120 = V_118 -> V_120 ;
V_26 -> V_66 ++ ;
V_118 ++ ;
}
V_46 -> V_50 = F_16 ( F_17 ( V_41 -> V_51 ) ) ;
V_46 -> V_52 = F_16 ( V_41 -> V_51 & 0xFFFFFFFF ) ;
V_46 -> V_53 = F_16 ( V_41 -> V_47 ) ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
unsigned int F_32 ( struct V_1 * V_2 ,
struct V_128 * V_129 ,
unsigned short V_120 ,
unsigned short V_130 ,
unsigned short V_131 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 ;
struct V_132 * V_26 ;
unsigned int V_27 = 0 ;
F_5 ( & V_22 -> V_29 ) ;
V_27 = F_6 ( V_2 ) ;
if ( ! V_27 ) {
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
V_24 = F_8 ( V_2 ) ;
V_24 -> V_30 |= V_27 ;
V_26 = F_9 ( V_24 ) ;
F_10 ( V_24 , sizeof( * V_26 ) , true , 0 ) ;
F_11 ( & V_26 -> V_31 , V_32 ,
V_133 ,
sizeof( * V_26 ) ) ;
V_26 -> V_35 = V_129 -> V_134 ;
V_26 -> V_120 = V_120 ;
if ( V_130 )
V_26 -> V_124 = V_135 ;
else
V_26 -> V_124 = V_136 ;
V_26 -> V_137 = V_131 ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
unsigned int F_33 ( struct V_1 * V_2 ,
unsigned short V_120 , unsigned int V_138 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 ;
struct V_139 * V_26 ;
unsigned int V_27 = 0 ;
F_5 ( & V_22 -> V_29 ) ;
V_27 = F_6 ( V_2 ) ;
if ( ! V_27 ) {
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
V_24 = F_8 ( V_2 ) ;
V_26 = F_9 ( V_24 ) ;
V_24 -> V_30 |= V_27 ;
F_10 ( V_24 , sizeof( * V_26 ) , true , 0 ) ;
F_11 ( & V_26 -> V_31 , V_140 ,
V_141 , sizeof( * V_26 ) ) ;
V_26 -> V_142 = ( unsigned short ) V_120 ;
V_26 -> V_143 = ( unsigned char ) V_138 ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_144 * V_145 ,
struct V_128 * V_129 ,
struct V_40 * V_41 )
{
struct V_146 * V_147 ;
struct V_148 * V_149 ;
struct V_150 * V_151 = (struct V_150 * ) V_145 ;
struct V_152 * V_153 = (struct V_152 * ) V_145 ;
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 ;
struct V_154 * V_26 ;
unsigned short V_155 ;
unsigned short V_156 ;
struct V_157 V_158 = { 0 , 0 } ;
struct V_157 * V_159 ;
unsigned int V_27 = 0 ;
unsigned int V_7 ;
unsigned short V_120 = V_129 -> V_160 ;
struct V_45 * V_46 ;
V_147 = V_2 -> V_147 ;
V_149 = V_147 -> V_161 ;
V_155 = ( unsigned short ) F_28 ( V_2 ) ;
V_156 = ( unsigned short ) F_29 ( V_2 ) ;
V_159 = & V_158 ;
F_35 ( V_2 , V_159 ) ;
F_5 ( & V_22 -> V_29 ) ;
V_27 = F_6 ( V_2 ) ;
if ( ! V_27 ) {
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
V_24 = F_8 ( V_2 ) ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_46 = F_15 ( V_24 ) ;
V_26 = V_41 -> V_48 ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
V_24 -> V_30 |= V_27 ;
F_10 ( V_24 , sizeof( * V_26 ) , false , 1 ) ;
F_11 ( & V_26 -> V_31 , V_104 ,
V_162 ,
sizeof( * V_26 ) ) ;
if ( V_145 -> V_163 == V_164 ) {
T_4 V_165 = V_151 -> V_166 . V_165 ;
V_26 -> V_167 . V_168 = V_169 ;
V_26 -> V_167 . V_170 [ 0 ] = V_165 & 0x000000ff ;
V_26 -> V_167 . V_170 [ 1 ] = ( V_165 & 0x0000ff00 ) >> 8 ;
V_26 -> V_167 . V_170 [ 2 ] = ( V_165 & 0x00ff0000 ) >> 16 ;
V_26 -> V_167 . V_170 [ 3 ] = ( V_165 & 0xff000000 ) >> 24 ;
V_26 -> V_171 = F_36 ( V_151 -> V_172 ) ;
V_129 -> V_145 = V_151 -> V_166 . V_165 ;
V_129 -> V_173 = F_36 ( V_151 -> V_172 ) ;
V_129 -> V_168 = V_169 ;
} else if ( V_145 -> V_163 == V_174 ) {
V_26 -> V_167 . V_168 = V_175 ;
memcpy ( & V_26 -> V_167 . V_170 ,
& V_153 -> V_176 . V_177 . V_178 , 16 ) ;
V_26 -> V_171 = F_36 ( V_153 -> V_179 ) ;
V_129 -> V_173 = F_36 ( V_153 -> V_179 ) ;
memcpy ( & V_129 -> V_180 ,
& V_153 -> V_176 . V_177 . V_178 , 16 ) ;
V_129 -> V_168 = V_175 ;
} else{
F_3 ( V_2 , V_14 , V_15 ,
L_18 ,
V_145 -> V_163 ) ;
F_7 ( & V_22 -> V_29 ) ;
F_37 ( & V_2 -> V_22 , V_27 ) ;
return - V_181 ;
}
V_26 -> V_120 = V_120 ;
V_7 = V_2 -> V_182 ++ ;
if ( V_2 -> V_182 == V_2 -> V_183 )
V_2 -> V_182 = 0 ;
V_26 -> V_184 = V_149 -> V_185 [ V_7 ] . V_142 ;
F_3 ( V_2 , V_28 , V_15 ,
L_19 , V_7 , V_26 -> V_184 ) ;
V_26 -> V_186 = V_155 ;
V_26 -> V_115 = V_155 ;
V_26 -> V_116 = V_156 ;
V_26 -> V_187 = 1 ;
V_26 -> V_188 . V_189 = V_159 -> V_189 ;
V_26 -> V_188 . V_190 = V_159 -> V_190 ;
V_46 -> V_50 = F_16 ( F_17 ( V_41 -> V_51 ) ) ;
V_46 -> V_52 = F_16 ( V_41 -> V_51 & 0xFFFFFFFF ) ;
V_46 -> V_53 = F_16 ( V_41 -> V_47 ) ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
unsigned int F_38 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 = F_19 ( & V_22 -> V_54 ) ;
struct V_191 * V_26 = F_9 ( V_24 ) ;
struct V_191 * V_192 = V_26 ;
int V_56 = 0 ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
F_5 ( & V_22 -> V_29 ) ;
F_10 ( V_24 , sizeof( * V_26 ) , true , 0 ) ;
F_11 ( & V_26 -> V_31 , V_104 ,
V_193 ,
sizeof( * V_26 ) ) ;
V_56 = F_20 ( V_22 ) ;
if ( ! V_56 )
V_2 -> V_194 = V_192 -> V_195 [ 0 ] ;
else {
F_3 ( V_2 , V_73 , V_15 ,
L_20 ) ;
}
F_7 ( & V_22 -> V_29 ) ;
return V_56 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_40 * V_41 , void * V_196 ,
int V_197 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 = F_8 ( V_2 ) ;
struct V_45 * V_46 ;
unsigned int V_27 ;
int V_198 = 0 ;
F_5 ( & V_22 -> V_29 ) ;
V_27 = F_6 ( V_2 ) ;
if ( ! V_27 ) {
F_7 ( & V_22 -> V_29 ) ;
V_198 = - V_76 ;
goto V_199;
}
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_24 -> V_30 |= V_27 ;
V_46 = F_15 ( V_24 ) ;
F_10 ( V_24 , V_41 -> V_47 , false , 1 ) ;
V_46 -> V_50 = F_16 ( F_17 ( V_41 -> V_51 ) ) ;
V_46 -> V_52 = F_16 ( F_40 ( V_41 -> V_51 ) ) ;
V_46 -> V_53 = F_16 ( V_41 -> V_47 ) ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
V_198 = F_41 ( V_2 , V_27 , NULL , V_41 -> V_48 ) ;
if ( V_198 ) {
F_3 ( V_2 , V_14 ,
V_15 | V_16 ,
L_21 ) ;
V_198 = - V_200 ;
goto V_199;
}
if ( V_196 )
memcpy ( V_196 , V_41 -> V_48 , V_197 ) ;
V_199:
F_23 ( V_22 -> V_75 , V_41 -> V_47 ,
V_41 -> V_48 , V_41 -> V_51 ) ;
return V_198 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_40 * V_201 ,
int V_202 , int V_47 )
{
V_201 -> V_48 = F_22 ( V_2 -> V_22 . V_75 , V_47 , & V_201 -> V_51 ) ;
if ( ! V_201 -> V_48 ) {
F_3 ( V_2 , V_14 , V_15 ,
L_22 ) ;
return - V_76 ;
}
memset ( V_201 -> V_48 , 0 , V_47 ) ;
V_201 -> V_47 = V_47 ;
F_11 ( V_201 -> V_48 , V_104 , V_202 , V_47 ) ;
return 0 ;
}
static int
F_43 ( struct V_1 * V_2 ,
struct V_203 * V_204 ,
struct V_205 * V_206 ,
struct V_205 * V_207 ,
T_1 V_208 )
{
struct V_209 * V_26 ;
struct V_40 V_41 ;
T_1 V_168 ;
int V_198 ;
V_198 = F_42 ( V_2 , & V_41 ,
V_210 ,
sizeof( * V_26 ) ) ;
if ( V_198 )
return V_198 ;
V_168 = ( V_206 -> V_211 == V_212 ) ?
V_175 : V_169 ;
V_26 = V_41 . V_48 ;
V_26 -> V_213 . V_214 = 1 ;
V_26 -> V_213 . V_215 . V_216 = V_208 ;
V_26 -> V_213 . V_215 . V_217 =
V_2 -> V_194 ;
V_26 -> V_213 . V_215 . V_218 . V_219 =
sizeof( struct V_220 ) ;
V_26 -> V_213 . V_215 . V_218 . V_168 = V_168 ;
if ( V_208 == V_221 ) {
memcpy ( V_26 -> V_213 . V_215 . V_218 . V_170 , V_206 -> V_222 ,
V_206 -> V_53 ) ;
if ( V_207 )
memcpy ( V_26 -> V_213 . V_215 . V_218 . V_223 ,
V_207 -> V_222 , V_207 -> V_53 ) ;
} else {
memcpy ( V_26 -> V_213 . V_215 . V_218 . V_170 ,
V_204 -> V_218 . V_170 , V_206 -> V_53 ) ;
memcpy ( V_26 -> V_213 . V_215 . V_218 . V_223 ,
V_204 -> V_218 . V_223 , V_206 -> V_53 ) ;
}
V_198 = F_39 ( V_2 , & V_41 , NULL , 0 ) ;
if ( V_198 < 0 )
F_3 ( V_2 , V_73 , V_15 ,
L_23 ) ;
return V_198 ;
}
static int F_44 ( struct V_1 * V_2 , T_2 * V_224 ,
T_1 V_225 , T_1 V_226 )
{
struct V_227 * V_26 ;
struct V_40 V_41 ;
int V_228 ;
V_228 = F_42 ( V_2 , & V_41 ,
V_229 ,
sizeof( * V_26 ) ) ;
if ( V_228 )
return V_228 ;
V_26 = V_41 . V_48 ;
V_26 -> V_216 = V_225 ;
V_26 -> V_218 . V_168 = V_169 ;
memcpy ( V_26 -> V_218 . V_170 , V_224 , V_226 ) ;
return F_39 ( V_2 , & V_41 , NULL , 0 ) ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_205 * V_206 ,
struct V_205 * V_207 ,
T_1 V_230 )
{
struct V_231 V_232 ;
struct V_203 V_204 ;
struct V_233 * V_234 ;
struct V_235 * V_236 ;
struct V_40 V_41 ;
T_2 * V_237 ;
T_1 V_168 ;
int V_198 ;
if ( F_38 ( V_2 ) )
return - V_200 ;
memset ( & V_204 , 0 , sizeof( V_204 ) ) ;
V_168 = ( V_206 -> V_211 == V_212 ) ?
V_175 : V_169 ;
V_198 = F_46 ( V_2 , V_168 , & V_204 ) ;
if ( V_198 )
return V_198 ;
if ( V_230 == V_238 ) {
if ( V_204 . V_239 ) {
F_3 ( V_2 , V_73 , V_15 ,
L_24 ) ;
return 0 ;
}
V_206 -> V_53 = ( V_206 -> V_211 == V_212 ) ?
V_240 : V_241 ;
} else {
if ( V_204 . V_239 ) {
memset ( & V_204 , 0 , sizeof( V_204 ) ) ;
V_198 = F_42 ( V_2 , & V_41 ,
V_242 ,
sizeof( * V_236 ) ) ;
if ( V_198 )
return V_198 ;
V_236 = V_41 . V_48 ;
V_236 -> V_217 = V_2 -> V_194 ;
V_236 -> V_168 = V_168 ;
V_198 = F_39 ( V_2 , & V_41 , NULL , 0 ) ;
if ( V_198 < 0 ) {
F_3 ( V_2 , V_73 ,
V_15 ,
L_25 ) ;
return V_198 ;
}
}
}
if ( V_204 . V_218 . V_170 [ 0 ] ) {
V_198 = F_43 ( V_2 , & V_204 , V_206 , NULL ,
V_243 ) ;
if ( V_198 )
return V_198 ;
}
if ( V_230 == V_238 ) {
memset ( & V_232 , 0 , sizeof( V_232 ) ) ;
V_198 = F_47 ( V_2 , V_169 , & V_232 ) ;
if ( V_198 ) {
F_3 ( V_2 , V_73 , V_15 ,
L_26 ) ;
return V_198 ;
}
if ( V_232 . V_218 . V_170 [ 0 ] ) {
V_237 = ( T_2 * ) & V_232 . V_218 . V_170 ;
V_198 = F_44 ( V_2 , V_237 ,
V_243 , V_241 ) ;
if ( V_198 ) {
F_3 ( V_2 , V_73 ,
V_15 ,
L_27 ) ;
return V_198 ;
}
}
}
if ( V_230 == V_238 ) {
V_198 = F_42 ( V_2 , & V_41 ,
V_244 ,
sizeof( * V_234 ) ) ;
if ( V_198 )
return V_198 ;
V_234 = V_41 . V_48 ;
V_234 -> V_245 = V_246 ;
V_234 -> V_247 = 1 ;
V_234 -> V_217 = V_2 -> V_194 ;
V_234 -> V_168 = V_248 ;
return F_39 ( V_2 , & V_41 , NULL , 0 ) ;
} else {
return F_43 ( V_2 , & V_204 , V_206 ,
V_207 , V_221 ) ;
}
return V_198 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_205 * V_249 )
{
struct V_231 V_232 ;
T_2 * V_237 ;
int V_228 ;
memset ( & V_232 , 0 , sizeof( V_232 ) ) ;
V_228 = F_47 ( V_2 , V_169 , & V_232 ) ;
if ( V_228 ) {
F_3 ( V_2 , V_73 , V_15 ,
L_26 ) ;
return V_228 ;
}
if ( V_232 . V_218 . V_170 [ 0 ] ) {
V_237 = ( T_2 * ) & V_232 . V_218 . V_170 ;
V_228 = F_44 ( V_2 , V_237 , V_243 ,
V_249 -> V_53 ) ;
if ( V_228 ) {
F_3 ( V_2 , V_73 , V_15 ,
L_27 ) ;
return V_228 ;
}
}
V_237 = ( T_2 * ) & V_249 -> V_222 ;
V_228 = F_44 ( V_2 , V_237 , V_221 ,
V_249 -> V_53 ) ;
if ( V_228 )
F_3 ( V_2 , V_73 , V_15 ,
L_28 ) ;
return V_228 ;
}
int F_47 ( struct V_1 * V_2 , int V_168 ,
struct V_231 * V_250 )
{
struct V_251 * V_26 ;
struct V_40 V_41 ;
int V_198 ;
V_198 = F_42 ( V_2 , & V_41 ,
V_252 ,
sizeof( * V_250 ) ) ;
if ( V_198 )
return V_198 ;
V_26 = V_41 . V_48 ;
V_26 -> V_168 = V_168 ;
return F_39 ( V_2 , & V_41 , V_250 ,
sizeof( * V_250 ) ) ;
}
int F_46 ( struct V_1 * V_2 , int V_168 ,
struct V_203 * V_204 )
{
struct V_253 * V_26 ;
struct V_40 V_41 ;
int V_198 ;
if ( F_38 ( V_2 ) )
return - V_200 ;
V_198 = F_42 ( V_2 , & V_41 ,
V_254 ,
sizeof( * V_204 ) ) ;
if ( V_198 )
return V_198 ;
V_26 = V_41 . V_48 ;
V_26 -> V_217 = V_2 -> V_194 ;
V_26 -> V_168 = V_168 ;
return F_39 ( V_2 , & V_41 , V_204 ,
sizeof( * V_204 ) ) ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_255 * V_256 )
{
struct V_40 V_41 ;
int V_198 ;
V_198 = F_42 ( V_2 , & V_41 ,
V_257 ,
sizeof( * V_256 ) ) ;
if ( V_198 )
return V_198 ;
return F_39 ( V_2 , & V_41 , V_256 , sizeof( * V_256 ) ) ;
}
unsigned int F_50 ( struct V_1 * V_2 )
{
unsigned int V_27 = 0 ;
struct V_23 * V_24 ;
struct V_258 * V_26 ;
struct V_21 * V_22 = & V_2 -> V_22 ;
F_5 ( & V_22 -> V_29 ) ;
V_27 = F_6 ( V_2 ) ;
if ( ! V_27 ) {
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
V_24 = F_8 ( V_2 ) ;
V_26 = F_9 ( V_24 ) ;
V_24 -> V_30 |= V_27 ;
F_10 ( V_24 , sizeof( * V_26 ) , true , 0 ) ;
F_11 ( & V_26 -> V_31 , V_32 ,
V_259 ,
sizeof( * V_26 ) ) ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
unsigned int F_51 ( struct V_1 * V_2 )
{
unsigned int V_27 = 0 ;
struct V_23 * V_24 ;
struct V_260 * V_26 ;
struct V_21 * V_22 = & V_2 -> V_22 ;
F_5 ( & V_22 -> V_29 ) ;
V_27 = F_6 ( V_2 ) ;
if ( ! V_27 ) {
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
V_24 = F_8 ( V_2 ) ;
V_26 = F_9 ( V_24 ) ;
V_24 -> V_30 |= V_27 ;
F_10 ( V_24 , sizeof( * V_26 ) , true , 0 ) ;
F_11 ( & V_26 -> V_31 , V_57 ,
V_261 ,
sizeof( * V_26 ) ) ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
int F_52 ( struct V_1 * V_2 ,
unsigned int * V_262 )
{
struct V_38 * V_263 ;
struct V_23 * V_24 ;
unsigned int V_27 ;
T_2 V_264 = 3 ;
int V_198 ;
do {
V_27 = F_13 ( V_2 ) ;
if ( ! V_27 ) {
F_3 ( V_2 , V_14 ,
V_15 | V_72 ,
L_29 ) ;
return - V_265 ;
}
V_198 = F_41 ( V_2 , V_27 , & V_24 , NULL ) ;
if ( V_198 ) {
F_3 ( V_2 , V_14 ,
V_72 | V_15 ,
L_30 ) ;
return - V_266 ;
}
V_263 = F_9 ( V_24 ) ;
if ( ! V_263 -> V_267 ) {
F_3 ( V_2 , V_28 ,
V_72 | V_15 ,
L_31 ) ;
return - V_268 ;
}
if ( V_263 -> V_39 != V_269 ) {
* V_262 = V_263 -> V_39 ;
return 0 ;
}
V_27 = F_4 ( V_2 , V_270 ,
V_269 ) ;
if ( ! V_27 ) {
F_3 ( V_2 , V_14 ,
V_72 | V_15 ,
L_32 ) ;
return - V_265 ;
}
V_198 = F_41 ( V_2 , V_27 , NULL , NULL ) ;
if ( V_198 ) {
F_3 ( V_2 , V_14 ,
V_72 | V_15 ,
L_33 ) ;
return V_198 ;
}
} while ( -- V_264 );
F_3 ( V_2 , V_14 ,
V_72 | V_15 ,
L_34 ) ;
return - V_268 ;
}
int F_53 ( struct V_1 * V_2 ,
T_5 V_271 )
{
int V_198 ;
unsigned int V_27 ;
struct V_23 * V_24 = NULL ;
V_27 = F_54 ( V_2 , V_271 ) ;
if ( ! V_27 ) {
F_3 ( V_2 , V_14 ,
( V_15 | V_16 ) ,
L_35 ) ;
return - V_266 ;
}
V_198 = F_41 ( V_2 , V_27 , & V_24 , NULL ) ;
if ( V_198 ) {
F_3 ( V_2 , V_14 ,
( V_15 | V_16 ) ,
L_36 ) ;
return V_198 ;
}
return V_198 ;
}
T_6
F_55 ( struct V_272 * V_273 , struct V_274 * V_275 ,
char * V_276 )
{
return snprintf ( V_276 , V_277 , V_278 L_37 ) ;
}
T_6
F_56 ( struct V_272 * V_273 , struct V_274 * V_275 ,
char * V_276 )
{
struct V_279 * V_280 = F_57 ( V_273 ) ;
struct V_1 * V_2 = F_58 ( V_280 ) ;
return snprintf ( V_276 , V_277 , L_38 , V_2 -> V_84 ) ;
}
T_6
F_59 ( struct V_272 * V_273 , struct V_274 * V_275 ,
char * V_276 )
{
struct V_279 * V_280 = F_57 ( V_273 ) ;
struct V_1 * V_2 = F_58 ( V_280 ) ;
return snprintf ( V_276 , V_277 , L_39 ,
( V_2 -> V_79 . V_281 - V_2 -> V_282 ) ) ;
}
T_6
F_60 ( struct V_272 * V_273 , struct V_274 * V_275 ,
char * V_276 )
{
T_5 V_283 = 0 ;
struct V_279 * V_280 = F_57 ( V_273 ) ;
struct V_1 * V_2 = F_58 ( V_280 ) ;
V_283 = V_2 -> V_9 -> V_272 ;
switch ( V_283 ) {
case V_284 :
case V_285 :
case V_286 :
return snprintf ( V_276 , V_277 , L_40 ) ;
break;
case V_287 :
case V_288 :
return snprintf ( V_276 , V_277 , L_41 ) ;
break;
case V_289 :
return snprintf ( V_276 , V_277 , L_42 ) ;
break;
default:
return snprintf ( V_276 , V_277 ,
L_43 , V_283 ) ;
break;
}
}
void F_61 ( struct V_290 * V_79 ,
struct V_291 * V_292 ,
struct V_293 * V_294 )
{
struct V_295 * V_296 = V_292 -> V_296 ;
memset ( V_296 , 0 , sizeof( * V_296 ) ) ;
F_62 ( struct V_297 ,
V_298 , V_296 ,
V_79 -> V_299 [ F_63 ( struct V_300 ,
V_298 ) / 32 ] ) ;
F_62 ( struct V_297 , type , V_296 ,
V_301 ) ;
F_62 ( struct V_297 ,
V_302 ,
V_296 ,
V_79 -> V_299 [ F_63 ( struct V_300 ,
V_302 ) / 32 ] ) ;
F_62 ( struct V_297 , V_303 , V_296 ,
( V_79 -> V_299 [ F_63 ( struct V_300 ,
V_303 ) / 32 ] & V_304 ) ) ;
F_62 ( struct V_297 , V_305 , V_296 ,
( V_79 -> V_299 [ F_63 ( struct V_300 ,
V_305 ) / 32 ] & V_306 ) >> 2 ) ;
F_62 ( struct V_297 , V_307 , V_296 ,
( V_79 -> V_299 [ F_63 ( struct V_300 ,
V_307 ) / 32 ] & V_308 ) >> 3 ) ;
F_62 ( struct V_297 , V_309 , V_296 ,
( V_79 -> V_299 [ F_63 ( struct V_300 ,
V_309 ) / 32 ] & V_310 ) >> 4 ) ;
F_62 ( struct V_297 , V_311 , V_296 ,
( V_79 -> V_299 [ F_63 ( struct V_300 ,
V_311 ) / 32 ] & V_312 ) >> 5 ) ;
F_62 ( struct V_297 , V_313 ,
V_296 ,
( V_79 -> V_299 [ F_63 ( struct V_300 ,
V_314 ) / 32 ] + 1 ) ) ;
F_62 ( struct V_297 , V_315 ,
V_296 , V_292 -> V_316 ) ;
F_62 ( struct V_297 ,
V_317 , V_296 , V_79 -> V_299 [ F_63
( struct V_300 ,
V_317 ) / 32 ] ) ;
F_62 ( struct V_297 , V_318 ,
V_296 , V_292 -> V_319 ) ;
F_62 ( struct V_297 ,
V_320 , V_296 , 0 ) ;
F_62 ( struct V_297 , V_321 ,
V_296 , 1 ) ;
F_62 ( struct V_297 , V_322 ,
V_296 , 0 ) ;
F_62 ( struct V_297 , V_323 , V_296 ,
0 ) ;
V_294 += V_324 ;
F_62 ( struct V_297 ,
V_325 , V_296 ,
V_294 -> V_326 [ 0 ] . V_327 . V_328 . V_329 . V_330 ) ;
F_62 ( struct V_297 ,
V_331 , V_296 ,
V_294 -> V_326 [ 0 ] . V_327 . V_328 . V_329 . V_332 ) ;
}
void F_64 ( struct V_290 * V_79 ,
struct V_291 * V_292 )
{
struct V_295 * V_296 = V_292 -> V_296 ;
memset ( V_296 , 0 , sizeof( * V_296 ) ) ;
F_62 ( struct V_297 ,
V_317 , V_296 , V_79 -> V_299 [ F_63
( struct V_300 ,
V_317 ) / 32 ] ) ;
F_62 ( struct V_333 ,
V_317 , V_296 , V_79 -> V_299 [ F_63
( struct V_300 ,
V_317 ) / 32 ] ) ;
F_62 ( struct V_333 ,
type , V_296 ,
V_301 ) ;
F_62 ( struct V_333 ,
V_318 ,
V_296 , V_292 -> V_319 ) ;
F_62 ( struct V_333 , V_315 ,
V_296 , V_292 -> V_316 ) ;
F_62 ( struct V_333 ,
V_298 , V_296 ,
V_79 -> V_299 [ F_63 ( struct V_300 ,
V_298 ) / 32 ] ) ;
F_62 ( struct V_333 ,
V_302 , V_296 ,
V_79 -> V_299 [ F_63 ( struct V_300 ,
V_302 ) / 32 ] ) ;
F_62 ( struct V_333 ,
V_334 , V_296 , V_335 ) ;
F_62 ( struct V_333 ,
V_336 , V_296 , V_337 ) ;
F_62 ( struct V_333 , V_303 , V_296 ,
( V_79 -> V_299 [ F_63 ( struct V_300 ,
V_303 ) / 32 ] & V_304 ) ) ;
F_62 ( struct V_333 , V_305 , V_296 ,
( V_79 -> V_299 [ F_63 ( struct V_300 ,
V_305 ) / 32 ] & V_306 ) >> 2 ) ;
F_62 ( struct V_333 , V_307 , V_296 ,
( V_79 -> V_299 [ F_63 ( struct V_300 ,
V_307 ) / 32 ] & V_308 ) >> 3 ) ;
F_62 ( struct V_333 ,
V_309 , V_296 ,
( V_79 -> V_299 [ F_63 ( struct V_300 ,
V_309 ) / 32 ] & V_310 ) >> 4 ) ;
F_62 ( struct V_333 , V_311 , V_296 ,
( V_79 -> V_299 [ F_63 ( struct V_300 ,
V_311 ) / 32 ] & V_312 ) >> 5 ) ;
F_62 ( struct V_333 ,
V_338 ,
V_296 ,
( V_79 -> V_299 [ F_63 ( struct V_300 ,
V_338 ) / 32 ] &
V_339 ) >> 6 ) ;
F_62 ( struct V_333 ,
V_340 ,
V_296 ,
( V_79 -> V_299 [ F_63 ( struct V_300 ,
V_340 ) / 32 ] &
V_341 ) >> 7 ) ;
F_62 ( struct V_333 , V_342 ,
V_296 ,
( V_79 -> V_299 [ F_63 ( struct V_300 ,
V_342 ) / 32 ] &
V_343 ) >> 8 ) ;
F_62 ( struct V_333 , V_313 ,
V_296 ,
( V_79 -> V_299 [ F_63 ( struct V_300 ,
V_314 ) / 32 ] + 1 ) ) ;
}

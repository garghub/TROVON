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
struct V_84 * V_85 ,
struct V_40 * V_41 )
{
struct V_86 * V_44 ;
struct V_23 * V_24 = F_8 ( V_2 ) ;
struct V_45 * V_87 = F_15 ( V_24 ) ;
unsigned int V_27 = 0 ;
struct V_88 * V_89 = V_85 -> V_90 ;
struct V_91 * V_26 = V_41 -> V_48 ;
unsigned short V_92 , V_93 , V_94 , V_95 ;
V_41 -> V_47 = V_85 -> V_96 . V_97 ;
memset ( V_41 -> V_48 , 0 , V_41 -> V_47 ) ;
V_44 = V_41 -> V_48 ;
V_92 = V_89 -> V_98 . V_99 . V_100 [ 1 ] ;
V_93 = V_89 -> V_98 . V_99 . V_100 [ 2 ] ;
V_94 = V_89 -> V_98 . V_99 . V_100 [ 3 ] ;
V_95 = V_89 -> V_98 . V_99 . V_100 [ 4 ] ;
V_26 -> V_92 = V_92 ;
V_26 -> V_94 = V_94 ;
V_26 -> V_95 = V_95 ;
F_5 ( & V_22 -> V_29 ) ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
switch ( V_89 -> V_98 . V_99 . V_100 [ 0 ] ) {
case V_101 :
V_95 = V_94 * V_93 + V_95 ;
F_11 ( & V_26 -> V_31 , V_102 ,
V_103 , sizeof( * V_26 ) ) ;
F_25 ( V_85 -> V_96 . V_104 ,
V_85 -> V_96 . V_105 ,
V_41 -> V_48 + V_95 , V_85 -> V_106 ) ;
break;
case V_107 :
F_11 ( & V_26 -> V_31 , V_102 ,
V_108 , sizeof( * V_26 ) ) ;
break;
default:
F_3 ( V_2 , V_73 , V_15 ,
L_16 ,
V_89 -> V_98 . V_99 . V_100 [ 0 ] ) ;
F_7 ( & V_22 -> V_29 ) ;
return - V_109 ;
}
V_27 = F_6 ( V_2 ) ;
if ( ! V_27 ) {
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
F_10 ( V_24 , V_41 -> V_47 , false ,
V_85 -> V_96 . V_105 ) ;
V_87 -> V_50 = F_16 ( F_17 ( V_41 -> V_51 ) ) ;
V_87 -> V_52 = F_16 ( V_41 -> V_51 & 0xFFFFFFFF ) ;
V_87 -> V_53 = F_16 ( V_41 -> V_47 ) ;
V_24 -> V_30 |= V_27 ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
int F_26 ( struct V_1 * V_2 , unsigned short V_110 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 = F_8 ( V_2 ) ;
struct V_111 * V_26 = F_9 ( V_24 ) ;
int V_56 = 0 ;
F_5 ( & V_22 -> V_29 ) ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
F_10 ( V_24 , sizeof( * V_26 ) , true , 0 ) ;
F_11 ( & V_26 -> V_31 , V_102 ,
V_112 , sizeof( * V_26 ) ) ;
V_26 -> V_110 = V_110 ;
V_26 -> V_113 = F_27 ( F_28 ( V_2 ) ) ;
V_26 -> V_114 = F_27 ( F_29 ( V_2 ) ) ;
V_56 = F_30 ( V_2 ) ;
if ( V_56 )
F_3 ( V_2 , V_73 , V_72 ,
L_17 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_56 ;
}
unsigned int F_31 ( struct V_1 * V_2 ,
struct V_115 * V_116 ,
unsigned int V_117 , unsigned int V_118 ,
struct V_40 * V_41 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 ;
struct V_45 * V_46 ;
struct V_119 * V_26 ;
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
F_11 ( & V_26 -> V_31 , V_102 ,
V_120 ,
sizeof( * V_26 ) ) ;
V_26 -> V_121 = 0 ;
V_26 -> V_122 = V_123 ;
for ( V_7 = 0 ; V_7 < V_117 ; V_7 ++ ) {
V_26 -> V_124 [ V_7 ] . V_125 = V_116 -> V_125 ;
V_26 -> V_124 [ V_7 ] . V_118 = V_116 -> V_118 ;
V_26 -> V_66 ++ ;
V_116 ++ ;
}
V_46 -> V_50 = F_16 ( F_17 ( V_41 -> V_51 ) ) ;
V_46 -> V_52 = F_16 ( V_41 -> V_51 & 0xFFFFFFFF ) ;
V_46 -> V_53 = F_16 ( V_41 -> V_47 ) ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
unsigned int F_32 ( struct V_1 * V_2 ,
struct V_126 * V_127 ,
unsigned short V_118 ,
unsigned short V_128 ,
unsigned short V_129 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 ;
struct V_130 * V_26 ;
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
V_131 ,
sizeof( * V_26 ) ) ;
V_26 -> V_35 = V_127 -> V_132 ;
V_26 -> V_118 = V_118 ;
if ( V_128 )
V_26 -> V_122 = V_133 ;
else
V_26 -> V_122 = V_134 ;
V_26 -> V_135 = V_129 ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
unsigned int F_33 ( struct V_1 * V_2 ,
unsigned short V_118 , unsigned int V_136 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 ;
struct V_137 * V_26 ;
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
F_11 ( & V_26 -> V_31 , V_138 ,
V_139 , sizeof( * V_26 ) ) ;
V_26 -> V_140 = ( unsigned short ) V_118 ;
V_26 -> V_141 = ( unsigned char ) V_136 ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_142 * V_143 ,
struct V_126 * V_127 ,
struct V_40 * V_41 )
{
struct V_144 * V_145 ;
struct V_146 * V_147 ;
struct V_148 * V_149 = (struct V_148 * ) V_143 ;
struct V_150 * V_151 = (struct V_150 * ) V_143 ;
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 ;
struct V_152 * V_26 ;
unsigned short V_153 ;
unsigned short V_154 ;
struct V_155 V_156 = { 0 , 0 } ;
struct V_155 * V_157 ;
unsigned int V_27 = 0 ;
unsigned int V_7 ;
unsigned short V_118 = V_127 -> V_158 ;
struct V_45 * V_46 ;
V_145 = V_2 -> V_145 ;
V_147 = V_145 -> V_159 ;
V_153 = ( unsigned short ) F_28 ( V_2 ) ;
V_154 = ( unsigned short ) F_29 ( V_2 ) ;
V_157 = & V_156 ;
F_35 ( V_2 , V_157 ) ;
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
F_11 ( & V_26 -> V_31 , V_102 ,
V_160 ,
sizeof( * V_26 ) ) ;
if ( V_143 -> V_161 == V_162 ) {
T_4 V_163 = V_149 -> V_164 . V_163 ;
V_26 -> V_165 . V_166 = V_167 ;
V_26 -> V_165 . V_168 [ 0 ] = V_163 & 0x000000ff ;
V_26 -> V_165 . V_168 [ 1 ] = ( V_163 & 0x0000ff00 ) >> 8 ;
V_26 -> V_165 . V_168 [ 2 ] = ( V_163 & 0x00ff0000 ) >> 16 ;
V_26 -> V_165 . V_168 [ 3 ] = ( V_163 & 0xff000000 ) >> 24 ;
V_26 -> V_169 = F_36 ( V_149 -> V_170 ) ;
V_127 -> V_143 = V_149 -> V_164 . V_163 ;
V_127 -> V_171 = F_36 ( V_149 -> V_170 ) ;
V_127 -> V_166 = V_167 ;
} else if ( V_143 -> V_161 == V_172 ) {
V_26 -> V_165 . V_166 = V_173 ;
memcpy ( & V_26 -> V_165 . V_168 ,
& V_151 -> V_174 . V_175 . V_176 , 16 ) ;
V_26 -> V_169 = F_36 ( V_151 -> V_177 ) ;
V_127 -> V_171 = F_36 ( V_151 -> V_177 ) ;
memcpy ( & V_127 -> V_178 ,
& V_151 -> V_174 . V_175 . V_176 , 16 ) ;
V_127 -> V_166 = V_173 ;
} else{
F_3 ( V_2 , V_14 , V_15 ,
L_18 ,
V_143 -> V_161 ) ;
F_7 ( & V_22 -> V_29 ) ;
F_37 ( & V_2 -> V_22 , V_27 ) ;
return - V_179 ;
}
V_26 -> V_118 = V_118 ;
V_7 = V_2 -> V_180 ++ ;
if ( V_2 -> V_180 == V_2 -> V_181 )
V_2 -> V_180 = 0 ;
V_26 -> V_182 = V_147 -> V_183 [ V_7 ] . V_140 ;
F_3 ( V_2 , V_28 , V_15 ,
L_19 , V_7 , V_26 -> V_182 ) ;
V_26 -> V_184 = V_153 ;
V_26 -> V_113 = V_153 ;
V_26 -> V_114 = V_154 ;
V_26 -> V_185 = 1 ;
V_26 -> V_186 . V_187 = V_157 -> V_187 ;
V_26 -> V_186 . V_188 = V_157 -> V_188 ;
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
struct V_189 * V_26 = F_9 ( V_24 ) ;
struct V_189 * V_190 = V_26 ;
int V_56 = 0 ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
F_5 ( & V_22 -> V_29 ) ;
F_10 ( V_24 , sizeof( * V_26 ) , true , 0 ) ;
F_11 ( & V_26 -> V_31 , V_102 ,
V_191 ,
sizeof( * V_26 ) ) ;
V_56 = F_20 ( V_22 ) ;
if ( ! V_56 )
V_2 -> V_192 = V_190 -> V_193 [ 0 ] ;
else {
F_3 ( V_2 , V_73 , V_15 ,
L_20 ) ;
}
F_7 ( & V_22 -> V_29 ) ;
return V_56 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_40 * V_41 , void * V_194 ,
int V_195 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_23 * V_24 = F_8 ( V_2 ) ;
struct V_45 * V_46 ;
unsigned int V_27 ;
int V_196 = 0 ;
F_5 ( & V_22 -> V_29 ) ;
V_27 = F_6 ( V_2 ) ;
if ( ! V_27 ) {
F_7 ( & V_22 -> V_29 ) ;
V_196 = - V_76 ;
goto V_197;
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
V_196 = F_41 ( V_2 , V_27 , NULL , V_41 -> V_48 ) ;
if ( V_196 ) {
F_3 ( V_2 , V_14 ,
V_15 | V_16 ,
L_21 ) ;
V_196 = - V_198 ;
goto V_197;
}
if ( V_194 )
memcpy ( V_194 , V_41 -> V_48 , V_195 ) ;
V_197:
F_23 ( V_22 -> V_75 , V_41 -> V_47 ,
V_41 -> V_48 , V_41 -> V_51 ) ;
return V_196 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_40 * V_199 ,
int V_200 , int V_47 )
{
V_199 -> V_48 = F_22 ( V_2 -> V_22 . V_75 , V_47 , & V_199 -> V_51 ) ;
if ( ! V_199 -> V_48 ) {
F_3 ( V_2 , V_14 , V_15 ,
L_22 ) ;
return - V_76 ;
}
memset ( V_199 -> V_48 , 0 , V_47 ) ;
V_199 -> V_47 = V_47 ;
F_11 ( V_199 -> V_48 , V_102 , V_200 , V_47 ) ;
return 0 ;
}
static int
F_43 ( struct V_1 * V_2 ,
struct V_201 * V_202 ,
struct V_203 * V_204 ,
struct V_203 * V_205 ,
T_1 V_206 )
{
struct V_207 * V_26 ;
struct V_40 V_41 ;
T_1 V_166 ;
int V_196 ;
V_196 = F_42 ( V_2 , & V_41 ,
V_208 ,
sizeof( * V_26 ) ) ;
if ( V_196 )
return V_196 ;
V_166 = ( V_204 -> V_209 == V_210 ) ?
V_173 : V_167 ;
V_26 = V_41 . V_48 ;
V_26 -> V_211 . V_212 = 1 ;
V_26 -> V_211 . V_213 . V_214 = V_206 ;
V_26 -> V_211 . V_213 . V_215 =
V_2 -> V_192 ;
V_26 -> V_211 . V_213 . V_216 . V_217 =
sizeof( struct V_218 ) ;
V_26 -> V_211 . V_213 . V_216 . V_166 = V_166 ;
if ( V_206 == V_219 ) {
memcpy ( V_26 -> V_211 . V_213 . V_216 . V_168 , V_204 -> V_220 ,
V_204 -> V_53 ) ;
if ( V_205 )
memcpy ( V_26 -> V_211 . V_213 . V_216 . V_221 ,
V_205 -> V_220 , V_205 -> V_53 ) ;
} else {
memcpy ( V_26 -> V_211 . V_213 . V_216 . V_168 ,
V_202 -> V_216 . V_168 , V_204 -> V_53 ) ;
memcpy ( V_26 -> V_211 . V_213 . V_216 . V_221 ,
V_202 -> V_216 . V_221 , V_204 -> V_53 ) ;
}
V_196 = F_39 ( V_2 , & V_41 , NULL , 0 ) ;
if ( V_196 < 0 )
F_3 ( V_2 , V_73 , V_15 ,
L_23 ) ;
return V_196 ;
}
static int F_44 ( struct V_1 * V_2 , T_2 * V_222 ,
T_1 V_223 , T_1 V_224 )
{
struct V_225 * V_26 ;
struct V_40 V_41 ;
int V_226 ;
V_226 = F_42 ( V_2 , & V_41 ,
V_227 ,
sizeof( * V_26 ) ) ;
if ( V_226 )
return V_226 ;
V_26 = V_41 . V_48 ;
V_26 -> V_214 = V_223 ;
V_26 -> V_216 . V_166 = V_167 ;
memcpy ( V_26 -> V_216 . V_168 , V_222 , V_224 ) ;
return F_39 ( V_2 , & V_41 , NULL , 0 ) ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_203 * V_204 ,
struct V_203 * V_205 ,
T_1 V_228 )
{
struct V_229 V_230 ;
struct V_201 V_202 ;
struct V_231 * V_232 ;
struct V_233 * V_234 ;
struct V_40 V_41 ;
T_2 * V_235 ;
T_1 V_166 ;
int V_196 ;
if ( F_38 ( V_2 ) )
return - V_198 ;
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_166 = ( V_204 -> V_209 == V_210 ) ?
V_173 : V_167 ;
V_196 = F_46 ( V_2 , V_166 , & V_202 ) ;
if ( V_196 )
return V_196 ;
if ( V_228 == V_236 ) {
if ( V_202 . V_237 ) {
F_3 ( V_2 , V_73 , V_15 ,
L_24 ) ;
return 0 ;
}
V_204 -> V_53 = ( V_204 -> V_209 == V_210 ) ?
V_238 : V_239 ;
} else {
if ( V_202 . V_237 ) {
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_196 = F_42 ( V_2 , & V_41 ,
V_240 ,
sizeof( * V_234 ) ) ;
if ( V_196 )
return V_196 ;
V_234 = V_41 . V_48 ;
V_234 -> V_215 = V_2 -> V_192 ;
V_234 -> V_166 = V_166 ;
V_196 = F_39 ( V_2 , & V_41 , NULL , 0 ) ;
if ( V_196 < 0 ) {
F_3 ( V_2 , V_73 ,
V_15 ,
L_25 ) ;
return V_196 ;
}
}
}
if ( V_202 . V_216 . V_168 [ 0 ] ) {
V_196 = F_43 ( V_2 , & V_202 , V_204 , NULL ,
V_241 ) ;
if ( V_196 )
return V_196 ;
}
if ( V_228 == V_236 ) {
memset ( & V_230 , 0 , sizeof( V_230 ) ) ;
V_196 = F_47 ( V_2 , V_167 , & V_230 ) ;
if ( V_196 ) {
F_3 ( V_2 , V_73 , V_15 ,
L_26 ) ;
return V_196 ;
}
if ( V_230 . V_216 . V_168 [ 0 ] ) {
V_235 = ( T_2 * ) & V_230 . V_216 . V_168 ;
V_196 = F_44 ( V_2 , V_235 ,
V_241 , V_239 ) ;
if ( V_196 ) {
F_3 ( V_2 , V_73 ,
V_15 ,
L_27 ) ;
return V_196 ;
}
}
}
if ( V_228 == V_236 ) {
V_196 = F_42 ( V_2 , & V_41 ,
V_242 ,
sizeof( * V_232 ) ) ;
if ( V_196 )
return V_196 ;
V_232 = V_41 . V_48 ;
V_232 -> V_243 = V_244 ;
V_232 -> V_245 = 1 ;
V_232 -> V_215 = V_2 -> V_192 ;
V_232 -> V_166 = V_246 ;
return F_39 ( V_2 , & V_41 , NULL , 0 ) ;
} else {
return F_43 ( V_2 , & V_202 , V_204 ,
V_205 , V_219 ) ;
}
return V_196 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_203 * V_247 )
{
struct V_229 V_230 ;
T_2 * V_235 ;
int V_226 ;
memset ( & V_230 , 0 , sizeof( V_230 ) ) ;
V_226 = F_47 ( V_2 , V_167 , & V_230 ) ;
if ( V_226 ) {
F_3 ( V_2 , V_73 , V_15 ,
L_26 ) ;
return V_226 ;
}
if ( V_230 . V_216 . V_168 [ 0 ] ) {
V_235 = ( T_2 * ) & V_230 . V_216 . V_168 ;
V_226 = F_44 ( V_2 , V_235 , V_241 ,
V_247 -> V_53 ) ;
if ( V_226 ) {
F_3 ( V_2 , V_73 , V_15 ,
L_27 ) ;
return V_226 ;
}
}
V_235 = ( T_2 * ) & V_247 -> V_220 ;
V_226 = F_44 ( V_2 , V_235 , V_219 ,
V_247 -> V_53 ) ;
if ( V_226 )
F_3 ( V_2 , V_73 , V_15 ,
L_28 ) ;
return V_226 ;
}
int F_47 ( struct V_1 * V_2 , int V_166 ,
struct V_229 * V_248 )
{
struct V_249 * V_26 ;
struct V_40 V_41 ;
int V_196 ;
V_196 = F_42 ( V_2 , & V_41 ,
V_250 ,
sizeof( * V_248 ) ) ;
if ( V_196 )
return V_196 ;
V_26 = V_41 . V_48 ;
V_26 -> V_166 = V_166 ;
return F_39 ( V_2 , & V_41 , V_248 ,
sizeof( * V_248 ) ) ;
}
int F_46 ( struct V_1 * V_2 , int V_166 ,
struct V_201 * V_202 )
{
struct V_251 * V_26 ;
struct V_40 V_41 ;
int V_196 ;
if ( F_38 ( V_2 ) )
return - V_198 ;
V_196 = F_42 ( V_2 , & V_41 ,
V_252 ,
sizeof( * V_202 ) ) ;
if ( V_196 )
return V_196 ;
V_26 = V_41 . V_48 ;
V_26 -> V_215 = V_2 -> V_192 ;
V_26 -> V_166 = V_166 ;
return F_39 ( V_2 , & V_41 , V_202 ,
sizeof( * V_202 ) ) ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_253 * V_254 )
{
struct V_40 V_41 ;
int V_196 ;
V_196 = F_42 ( V_2 , & V_41 ,
V_255 ,
sizeof( * V_254 ) ) ;
if ( V_196 )
return V_196 ;
return F_39 ( V_2 , & V_41 , V_254 , sizeof( * V_254 ) ) ;
}
unsigned int F_50 ( struct V_1 * V_2 )
{
unsigned int V_27 = 0 ;
struct V_23 * V_24 ;
struct V_256 * V_26 ;
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
V_257 ,
sizeof( * V_26 ) ) ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
unsigned int F_51 ( struct V_1 * V_2 )
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
F_11 ( & V_26 -> V_31 , V_57 ,
V_259 ,
sizeof( * V_26 ) ) ;
F_12 ( V_2 ) ;
F_7 ( & V_22 -> V_29 ) ;
return V_27 ;
}
int F_52 ( struct V_1 * V_2 ,
unsigned int * V_260 )
{
struct V_38 * V_261 ;
struct V_23 * V_24 ;
unsigned int V_27 ;
T_2 V_262 = 3 ;
int V_196 ;
do {
V_27 = F_13 ( V_2 ) ;
if ( ! V_27 ) {
F_3 ( V_2 , V_14 ,
V_15 | V_72 ,
L_29 ) ;
return - V_263 ;
}
V_196 = F_41 ( V_2 , V_27 , & V_24 , NULL ) ;
if ( V_196 ) {
F_3 ( V_2 , V_14 ,
V_72 | V_15 ,
L_30 ) ;
return - V_264 ;
}
V_261 = F_9 ( V_24 ) ;
if ( ! V_261 -> V_265 ) {
F_3 ( V_2 , V_28 ,
V_72 | V_15 ,
L_31 ) ;
return - V_266 ;
}
if ( V_261 -> V_39 != V_267 ) {
* V_260 = V_261 -> V_39 ;
return 0 ;
}
V_27 = F_4 ( V_2 , V_268 ,
V_267 ) ;
if ( ! V_27 ) {
F_3 ( V_2 , V_14 ,
V_72 | V_15 ,
L_32 ) ;
return - V_263 ;
}
V_196 = F_41 ( V_2 , V_27 , NULL , NULL ) ;
if ( V_196 ) {
F_3 ( V_2 , V_14 ,
V_72 | V_15 ,
L_33 ) ;
return V_196 ;
}
} while ( -- V_262 );
F_3 ( V_2 , V_14 ,
V_72 | V_15 ,
L_34 ) ;
return - V_266 ;
}
int F_53 ( struct V_1 * V_2 ,
T_5 V_269 )
{
int V_196 ;
unsigned int V_27 ;
struct V_23 * V_24 = NULL ;
V_27 = F_54 ( V_2 , V_269 ) ;
if ( ! V_27 ) {
F_3 ( V_2 , V_14 ,
( V_15 | V_16 ) ,
L_35 ) ;
return - V_264 ;
}
V_196 = F_41 ( V_2 , V_27 , & V_24 , NULL ) ;
if ( V_196 ) {
F_3 ( V_2 , V_14 ,
( V_15 | V_16 ) ,
L_36 ) ;
return V_196 ;
}
return V_196 ;
}
T_6
F_55 ( struct V_270 * V_271 , struct V_272 * V_273 ,
char * V_274 )
{
return snprintf ( V_274 , V_275 , V_276 L_37 ) ;
}
T_6
F_56 ( struct V_270 * V_271 , struct V_272 * V_273 ,
char * V_274 )
{
T_5 V_277 = 0 ;
struct V_278 * V_279 = F_57 ( V_271 ) ;
struct V_1 * V_2 = F_58 ( V_279 ) ;
V_277 = V_2 -> V_9 -> V_270 ;
switch ( V_277 ) {
case V_280 :
case V_281 :
case V_282 :
return snprintf ( V_274 , V_275 , L_38 ) ;
break;
case V_283 :
case V_284 :
return snprintf ( V_274 , V_275 , L_39 ) ;
break;
case V_285 :
return snprintf ( V_274 , V_275 , L_40 ) ;
break;
default:
return snprintf ( V_274 , V_275 ,
L_41 , V_277 ) ;
break;
}
}
void F_59 ( struct V_286 * V_79 ,
struct V_287 * V_288 ,
struct V_289 * V_290 )
{
struct V_291 * V_292 = V_288 -> V_292 ;
memset ( V_292 , 0 , sizeof( * V_292 ) ) ;
F_60 ( struct V_293 ,
V_294 , V_292 ,
V_79 -> V_295 [ F_61 ( struct V_296 ,
V_294 ) / 32 ] ) ;
F_60 ( struct V_293 , type , V_292 ,
V_297 ) ;
F_60 ( struct V_293 ,
V_298 ,
V_292 ,
V_79 -> V_295 [ F_61 ( struct V_296 ,
V_298 ) / 32 ] ) ;
F_60 ( struct V_293 , V_299 , V_292 ,
( V_79 -> V_295 [ F_61 ( struct V_296 ,
V_299 ) / 32 ] & V_300 ) ) ;
F_60 ( struct V_293 , V_301 , V_292 ,
( V_79 -> V_295 [ F_61 ( struct V_296 ,
V_301 ) / 32 ] & V_302 ) >> 2 ) ;
F_60 ( struct V_293 , V_303 , V_292 ,
( V_79 -> V_295 [ F_61 ( struct V_296 ,
V_303 ) / 32 ] & V_304 ) >> 3 ) ;
F_60 ( struct V_293 , V_305 , V_292 ,
( V_79 -> V_295 [ F_61 ( struct V_296 ,
V_305 ) / 32 ] & V_306 ) >> 4 ) ;
F_60 ( struct V_293 , V_307 , V_292 ,
( V_79 -> V_295 [ F_61 ( struct V_296 ,
V_307 ) / 32 ] & V_308 ) >> 5 ) ;
F_60 ( struct V_293 , V_309 ,
V_292 ,
( V_79 -> V_295 [ F_61 ( struct V_296 ,
V_310 ) / 32 ] + 1 ) ) ;
F_60 ( struct V_293 , V_311 ,
V_292 , V_288 -> V_312 ) ;
F_60 ( struct V_293 ,
V_313 , V_292 , V_79 -> V_295 [ F_61
( struct V_296 ,
V_313 ) / 32 ] ) ;
F_60 ( struct V_293 , V_314 ,
V_292 , V_288 -> V_315 ) ;
F_60 ( struct V_293 ,
V_316 , V_292 , 0 ) ;
F_60 ( struct V_293 , V_317 ,
V_292 , 1 ) ;
F_60 ( struct V_293 , V_318 ,
V_292 , 0 ) ;
F_60 ( struct V_293 , V_319 , V_292 ,
0 ) ;
V_290 += V_320 ;
F_60 ( struct V_293 ,
V_321 , V_292 ,
V_290 -> V_322 [ 0 ] . V_323 . V_324 . V_325 . V_326 ) ;
F_60 ( struct V_293 ,
V_327 , V_292 ,
V_290 -> V_322 [ 0 ] . V_323 . V_324 . V_325 . V_328 ) ;
}
void F_62 ( struct V_286 * V_79 ,
struct V_287 * V_288 )
{
struct V_291 * V_292 = V_288 -> V_292 ;
memset ( V_292 , 0 , sizeof( * V_292 ) ) ;
F_60 ( struct V_293 ,
V_313 , V_292 , V_79 -> V_295 [ F_61
( struct V_296 ,
V_313 ) / 32 ] ) ;
F_60 ( struct V_329 ,
V_313 , V_292 , V_79 -> V_295 [ F_61
( struct V_296 ,
V_313 ) / 32 ] ) ;
F_60 ( struct V_329 ,
type , V_292 ,
V_297 ) ;
F_60 ( struct V_329 ,
V_314 ,
V_292 , V_288 -> V_315 ) ;
F_60 ( struct V_329 , V_311 ,
V_292 , V_288 -> V_312 ) ;
F_60 ( struct V_329 ,
V_294 , V_292 ,
V_79 -> V_295 [ F_61 ( struct V_296 ,
V_294 ) / 32 ] ) ;
F_60 ( struct V_329 ,
V_298 , V_292 ,
V_79 -> V_295 [ F_61 ( struct V_296 ,
V_298 ) / 32 ] ) ;
F_60 ( struct V_329 ,
V_330 , V_292 , V_331 ) ;
F_60 ( struct V_329 ,
V_332 , V_292 , V_333 ) ;
F_60 ( struct V_329 , V_299 , V_292 ,
( V_79 -> V_295 [ F_61 ( struct V_296 ,
V_299 ) / 32 ] & V_300 ) ) ;
F_60 ( struct V_329 , V_301 , V_292 ,
( V_79 -> V_295 [ F_61 ( struct V_296 ,
V_301 ) / 32 ] & V_302 ) >> 2 ) ;
F_60 ( struct V_329 , V_303 , V_292 ,
( V_79 -> V_295 [ F_61 ( struct V_296 ,
V_303 ) / 32 ] & V_304 ) >> 3 ) ;
F_60 ( struct V_329 ,
V_305 , V_292 ,
( V_79 -> V_295 [ F_61 ( struct V_296 ,
V_305 ) / 32 ] & V_306 ) >> 4 ) ;
F_60 ( struct V_329 , V_307 , V_292 ,
( V_79 -> V_295 [ F_61 ( struct V_296 ,
V_307 ) / 32 ] & V_308 ) >> 5 ) ;
F_60 ( struct V_329 ,
V_334 ,
V_292 ,
( V_79 -> V_295 [ F_61 ( struct V_296 ,
V_334 ) / 32 ] &
V_335 ) >> 6 ) ;
F_60 ( struct V_329 ,
V_336 ,
V_292 ,
( V_79 -> V_295 [ F_61 ( struct V_296 ,
V_336 ) / 32 ] &
V_337 ) >> 7 ) ;
F_60 ( struct V_329 , V_338 ,
V_292 ,
( V_79 -> V_295 [ F_61 ( struct V_296 ,
V_338 ) / 32 ] &
V_339 ) >> 8 ) ;
F_60 ( struct V_329 , V_309 ,
V_292 ,
( V_79 -> V_295 [ F_61 ( struct V_296 ,
V_310 ) / 32 ] + 1 ) ) ;
}

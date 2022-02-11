unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
unsigned int V_9 = 0 ;
F_2 ( V_10 , L_1 ) ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
V_6 = F_6 ( V_2 ) ;
V_8 = F_7 ( V_6 ) ;
V_6 -> V_12 |= V_9 ;
F_8 ( V_6 , sizeof( * V_8 ) , true , 0 ) ;
F_9 ( & V_8 -> V_13 , V_14 ,
V_15 ,
sizeof( struct V_16 ) ) ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
unsigned int F_11 ( struct V_1 * V_2 ,
T_1 V_17 ,
struct V_18 * V_19 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
unsigned int V_9 = 0 ;
struct V_20 * V_8 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
F_2 ( V_10 , L_2 ) ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
V_19 -> V_25 = sizeof( * V_22 ) ;
V_8 = V_19 -> V_26 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_6 = F_6 ( V_2 ) ;
V_24 = F_12 ( V_6 ) ;
V_6 -> V_12 |= V_9 ;
V_6 -> V_12 |= V_9 ;
F_8 ( V_6 , sizeof( * V_8 ) , false , 1 ) ;
F_9 ( & V_8 -> V_13 , V_14 ,
V_27 ,
sizeof( * V_22 ) ) ;
V_8 -> V_28 = V_17 ;
V_24 -> V_29 = F_13 ( F_14 ( V_19 -> V_30 ) ) ;
V_24 -> V_31 = F_13 ( V_19 -> V_30 & 0xFFFFFFFF ) ;
V_24 -> V_32 = F_13 ( V_19 -> V_25 ) ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
int F_15 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = F_16 ( & V_4 -> V_33 ) ;
struct V_34 * V_8 = F_7 ( V_6 ) ;
int V_35 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_8 ( V_6 , sizeof( * V_8 ) , true , 0 ) ;
F_9 ( & V_8 -> V_13 , V_36 ,
V_37 , sizeof( * V_8 ) ) ;
V_35 = F_17 ( V_4 ) ;
if ( ! V_35 ) {
struct V_34 * V_38 ;
V_38 = V_8 ;
V_2 -> V_39 . V_40 = V_38 -> V_40 ;
V_2 -> V_39 . V_41 =
V_38 -> V_42 [ 0 ] . V_43 ;
V_2 -> V_39 . V_44 =
V_38 -> V_42 [ 0 ] . V_45 ;
V_2 -> V_39 . V_46 =
V_38 -> V_42 [ 0 ] . V_47 ;
V_2 -> V_39 . V_48 =
V_38 -> V_42 [ 0 ] . V_49 ;
if ( V_2 -> V_39 . V_48 > ( V_50 / 2 ) ) {
F_2 ( V_10 ,
L_3
L_4 ,
V_2 -> V_39 . V_48 ,
V_50 ) ;
V_2 -> V_39 . V_48 = V_50 / 2 ;
}
} else {
F_18 ( V_51 , V_2 -> V_52 ,
L_5 ) ;
}
F_5 ( & V_4 -> V_11 ) ;
return V_35 ;
}
int F_19 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_18 V_19 ;
struct V_5 * V_6 = F_16 ( & V_4 -> V_33 ) ;
struct V_53 * V_8 ;
struct V_23 * V_24 = F_12 ( V_6 ) ;
int V_35 = 0 ;
V_19 . V_26 = F_20 ( V_4 -> V_54 ,
sizeof( struct V_53 ) ,
& V_19 . V_30 ) ;
if ( V_19 . V_26 == NULL ) {
F_2 ( V_55 ,
L_6
L_7 ) ;
return - V_56 ;
}
V_19 . V_25 = sizeof( struct V_53 ) ;
V_8 = V_19 . V_26 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
F_3 ( & V_4 -> V_11 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_8 ( V_6 , sizeof( * V_8 ) , false , 1 ) ;
F_9 ( & V_8 -> V_13 , V_36 ,
V_57 , sizeof( * V_8 ) ) ;
V_24 -> V_29 = F_13 ( F_14 ( V_19 . V_30 ) ) ;
V_24 -> V_31 = F_13 ( V_19 . V_30 & 0xFFFFFFFF ) ;
V_24 -> V_32 = F_13 ( V_19 . V_25 ) ;
V_35 = F_17 ( V_4 ) ;
if ( ! V_35 ) {
struct V_58 * V_22 = V_19 . V_26 ;
F_2 ( V_10 , L_8 ,
V_22 -> V_59 . V_60 . V_61 ) ;
F_2 ( V_10 , L_9 ,
V_22 -> V_59 . V_60 . V_62 ) ;
F_2 ( V_10 ,
L_10 ) ;
V_2 -> V_39 . V_63 =
V_22 -> V_59 . V_60 . V_63 ;
F_2 ( V_10 , L_11 ,
V_2 -> V_39 . V_63 ) ;
} else
F_2 ( V_55 , L_12 ) ;
F_5 ( & V_4 -> V_11 ) ;
if ( V_19 . V_26 )
F_21 ( V_4 -> V_54 , V_19 . V_25 ,
V_19 . V_26 , V_19 . V_30 ) ;
return V_35 ;
}
unsigned int F_22 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_64 * V_65 ,
struct V_18 * V_19 )
{
struct V_66 * V_22 ;
struct V_5 * V_6 = F_6 ( V_2 ) ;
struct V_23 * V_67 = F_12 ( V_6 ) ;
unsigned int V_9 = 0 ;
struct V_68 * V_69 = V_65 -> V_70 ;
struct V_71 * V_8 = V_19 -> V_26 ;
unsigned short V_72 , V_73 , V_74 , V_75 ;
V_19 -> V_25 = V_65 -> V_76 . V_77 ;
memset ( V_19 -> V_26 , 0 , V_19 -> V_25 ) ;
V_22 = V_19 -> V_26 ;
V_72 = V_69 -> V_78 . V_79 . V_80 [ 1 ] ;
V_73 = V_69 -> V_78 . V_79 . V_80 [ 2 ] ;
V_74 = V_69 -> V_78 . V_79 . V_80 [ 3 ] ;
V_75 = V_69 -> V_78 . V_79 . V_80 [ 4 ] ;
V_8 -> V_72 = V_72 ;
V_8 -> V_74 = V_74 ;
V_8 -> V_75 = V_75 ;
F_3 ( & V_4 -> V_11 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
switch ( V_69 -> V_78 . V_79 . V_80 [ 0 ] ) {
case V_81 :
V_75 = V_74 * V_73 + V_75 ;
F_9 ( & V_8 -> V_13 , V_82 ,
V_83 , sizeof( * V_8 ) ) ;
F_23 ( V_65 -> V_76 . V_84 ,
V_65 -> V_76 . V_85 ,
V_19 -> V_26 + V_75 , V_65 -> V_86 ) ;
break;
case V_87 :
F_9 ( & V_8 -> V_13 , V_82 ,
V_88 , sizeof( * V_8 ) ) ;
break;
default:
F_18 ( V_51 , V_2 -> V_52 ,
L_13 , V_69 -> V_78 .
V_79 . V_80 [ 0 ] ) ;
F_5 ( & V_4 -> V_11 ) ;
return - V_89 ;
}
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
F_8 ( V_6 , V_19 -> V_25 , false ,
V_65 -> V_76 . V_85 ) ;
V_67 -> V_29 = F_13 ( F_14 ( V_19 -> V_30 ) ) ;
V_67 -> V_31 = F_13 ( V_19 -> V_30 & 0xFFFFFFFF ) ;
V_67 -> V_32 = F_13 ( V_19 -> V_25 ) ;
V_6 -> V_12 |= V_9 ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
int F_24 ( struct V_1 * V_2 , unsigned short V_90 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = F_6 ( V_2 ) ;
struct V_91 * V_8 = F_7 ( V_6 ) ;
int V_35 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_8 ( V_6 , sizeof( * V_8 ) , true , 0 ) ;
F_9 ( & V_8 -> V_13 , V_82 ,
V_92 , sizeof( * V_8 ) ) ;
V_8 -> V_90 = V_90 ;
V_8 -> V_93 = F_25 ( F_26 ( V_2 ) ) ;
V_8 -> V_94 = F_25 ( F_27 ( V_2 ) ) ;
V_35 = F_28 ( V_2 ) ;
if ( V_35 )
F_18 ( V_51 , V_2 -> V_52 ,
L_14 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_35 ;
}
unsigned int F_29 ( struct V_1 * V_2 ,
struct V_95 * V_96 ,
unsigned int V_97 , unsigned int V_98 ,
struct V_18 * V_19 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_23 * V_24 ;
struct V_99 * V_8 ;
unsigned int V_100 , V_9 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
V_8 = V_19 -> V_26 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_6 = F_6 ( V_2 ) ;
V_24 = F_12 ( V_6 ) ;
V_6 -> V_12 |= V_9 ;
F_8 ( V_6 , sizeof( * V_8 ) , false , 1 ) ;
F_9 ( & V_8 -> V_13 , V_82 ,
V_101 ,
sizeof( * V_8 ) ) ;
V_8 -> V_102 = 0 ;
V_8 -> V_103 = V_104 ;
for ( V_100 = 0 ; V_100 < V_97 ; V_100 ++ ) {
V_8 -> V_105 [ V_100 ] . V_106 = V_96 -> V_106 ;
V_8 -> V_105 [ V_100 ] . V_98 = V_96 -> V_98 ;
V_8 -> V_45 ++ ;
V_96 ++ ;
}
V_24 -> V_29 = F_13 ( F_14 ( V_19 -> V_30 ) ) ;
V_24 -> V_31 = F_13 ( V_19 -> V_30 & 0xFFFFFFFF ) ;
V_24 -> V_32 = F_13 ( V_19 -> V_25 ) ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
unsigned int F_30 ( struct V_1 * V_2 ,
struct V_107 * V_108 ,
unsigned short V_98 ,
unsigned short V_109 ,
unsigned short V_110 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_111 * V_8 ;
unsigned int V_9 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
V_6 = F_6 ( V_2 ) ;
V_6 -> V_12 |= V_9 ;
V_8 = F_7 ( V_6 ) ;
F_8 ( V_6 , sizeof( * V_8 ) , true , 0 ) ;
F_9 ( & V_8 -> V_13 , V_14 ,
V_112 ,
sizeof( * V_8 ) ) ;
V_8 -> V_28 = V_108 -> V_113 ;
V_8 -> V_98 = V_98 ;
if ( V_109 )
V_8 -> V_103 = V_114 ;
else
V_8 -> V_103 = V_115 ;
V_8 -> V_116 = V_110 ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
unsigned int F_31 ( struct V_1 * V_2 ,
unsigned short V_98 , unsigned int V_117 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_118 * V_8 ;
unsigned int V_9 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
V_6 = F_6 ( V_2 ) ;
V_8 = F_7 ( V_6 ) ;
V_6 -> V_12 |= V_9 ;
F_8 ( V_6 , sizeof( * V_8 ) , true , 0 ) ;
F_9 ( & V_8 -> V_13 , V_119 ,
V_120 , sizeof( * V_8 ) ) ;
V_8 -> V_121 = ( unsigned short ) V_98 ;
V_8 -> V_122 = ( unsigned char ) V_117 ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
int F_32 ( struct V_1 * V_2 ,
struct V_123 * V_124 ,
struct V_107 * V_108 ,
struct V_18 * V_19 )
{
struct V_125 * V_126 ;
struct V_127 * V_128 ;
struct V_129 * V_130 = (struct V_129 * ) V_124 ;
struct V_131 * V_132 = (struct V_131 * ) V_124 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_133 * V_8 ;
unsigned short V_134 ;
unsigned short V_135 ;
struct V_136 V_137 = { 0 , 0 } ;
struct V_136 * V_138 ;
unsigned int V_9 = 0 ;
unsigned int V_100 ;
unsigned short V_98 = V_108 -> V_139 ;
struct V_23 * V_24 ;
V_126 = V_2 -> V_126 ;
V_128 = V_126 -> V_140 ;
V_134 = ( unsigned short ) F_26 ( V_2 ) ;
V_135 = ( unsigned short ) F_27 ( V_2 ) ;
V_138 = & V_137 ;
F_33 ( V_2 , V_138 ) ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
V_6 = F_6 ( V_2 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_24 = F_12 ( V_6 ) ;
V_8 = V_19 -> V_26 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_6 -> V_12 |= V_9 ;
F_8 ( V_6 , sizeof( * V_8 ) , false , 1 ) ;
F_9 ( & V_8 -> V_13 , V_82 ,
V_141 ,
sizeof( * V_8 ) ) ;
if ( V_124 -> V_142 == V_143 ) {
T_2 V_144 = V_130 -> V_145 . V_144 ;
V_8 -> V_146 . V_147 = V_148 ;
V_8 -> V_146 . V_149 [ 0 ] = V_144 & 0x000000ff ;
V_8 -> V_146 . V_149 [ 1 ] = ( V_144 & 0x0000ff00 ) >> 8 ;
V_8 -> V_146 . V_149 [ 2 ] = ( V_144 & 0x00ff0000 ) >> 16 ;
V_8 -> V_146 . V_149 [ 3 ] = ( V_144 & 0xff000000 ) >> 24 ;
V_8 -> V_150 = F_34 ( V_130 -> V_151 ) ;
V_108 -> V_124 = V_130 -> V_145 . V_144 ;
V_108 -> V_152 = F_34 ( V_130 -> V_151 ) ;
V_108 -> V_147 = V_148 ;
} else if ( V_124 -> V_142 == V_153 ) {
V_8 -> V_146 . V_147 = V_154 ;
memcpy ( & V_8 -> V_146 . V_149 ,
& V_132 -> V_155 . V_156 . V_157 , 16 ) ;
V_8 -> V_150 = F_34 ( V_132 -> V_158 ) ;
V_108 -> V_152 = F_34 ( V_132 -> V_158 ) ;
memcpy ( & V_108 -> V_159 ,
& V_132 -> V_155 . V_156 . V_157 , 16 ) ;
V_108 -> V_147 = V_154 ;
} else{
F_18 ( V_160 , V_2 -> V_52 , L_15 ,
V_124 -> V_142 ) ;
F_5 ( & V_4 -> V_11 ) ;
F_35 ( & V_2 -> V_4 , V_9 ) ;
return - V_161 ;
}
V_8 -> V_98 = V_98 ;
V_100 = V_2 -> V_162 ++ ;
if ( V_2 -> V_162 == V_2 -> V_163 )
V_2 -> V_162 = 0 ;
V_8 -> V_164 = V_128 -> V_165 [ V_100 ] . V_121 ;
F_2 ( V_10 , L_16 , V_100 , V_8 -> V_164 ) ;
V_8 -> V_166 = V_134 ;
V_8 -> V_93 = V_134 ;
V_8 -> V_94 = V_135 ;
V_8 -> V_167 = 1 ;
V_8 -> V_168 . V_169 = V_138 -> V_169 ;
V_8 -> V_168 . V_170 = V_138 -> V_170 ;
V_24 -> V_29 = F_13 ( F_14 ( V_19 -> V_30 ) ) ;
V_24 -> V_31 = F_13 ( V_19 -> V_30 & 0xFFFFFFFF ) ;
V_24 -> V_32 = F_13 ( V_19 -> V_25 ) ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
unsigned int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = F_16 ( & V_4 -> V_33 ) ;
struct V_171 * V_8 = F_7 ( V_6 ) ;
struct V_171 * V_172 = V_8 ;
int V_35 = 0 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_3 ( & V_4 -> V_11 ) ;
F_8 ( V_6 , sizeof( * V_8 ) , true , 0 ) ;
F_9 ( & V_8 -> V_13 , V_82 ,
V_173 ,
sizeof( * V_8 ) ) ;
V_35 = F_17 ( V_4 ) ;
if ( ! V_35 )
V_2 -> V_174 = V_172 -> V_175 [ 0 ] ;
else {
F_18 ( V_51 , V_2 -> V_52 ,
L_17 ) ;
}
F_5 ( & V_4 -> V_11 ) ;
return V_35 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_18 * V_19 , void * V_176 ,
int V_177 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = F_6 ( V_2 ) ;
unsigned short V_35 , V_178 ;
struct V_23 * V_24 ;
unsigned int V_9 ;
int V_179 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
V_179 = - V_56 ;
goto V_180;
}
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_12 |= V_9 ;
V_24 = F_12 ( V_6 ) ;
F_8 ( V_6 , V_19 -> V_25 , false , 1 ) ;
V_24 -> V_29 = F_13 ( F_14 ( V_19 -> V_30 ) ) ;
V_24 -> V_31 = F_13 ( V_19 -> V_30 & 0xFFFFFFFF ) ;
V_24 -> V_32 = F_13 ( V_19 -> V_25 ) ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
F_38 ( V_2 -> V_4 . V_181 [ V_9 ] ,
V_2 -> V_4 . V_182 [ V_9 ] ) ;
V_178 = ( V_2 -> V_4 . V_182 [ V_9 ] & 0x0000FF00 ) >> 8 ;
V_35 = V_2 -> V_4 . V_182 [ V_9 ] & 0x000000FF ;
if ( V_35 || V_178 ) {
F_2 ( V_55 ,
L_18
L_19 , V_35 , V_178 ) ;
V_179 = - V_183 ;
goto V_184;
}
if ( V_176 )
memcpy ( V_176 , V_19 -> V_26 , V_177 ) ;
V_184:
F_35 ( & V_2 -> V_4 , V_9 ) ;
V_180:
F_21 ( V_4 -> V_54 , V_19 -> V_25 ,
V_19 -> V_26 , V_19 -> V_30 ) ;
return V_179 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_18 * V_185 ,
int V_186 , int V_25 )
{
V_185 -> V_26 = F_20 ( V_2 -> V_4 . V_54 , V_25 , & V_185 -> V_30 ) ;
if ( ! V_185 -> V_26 ) {
F_2 ( V_55 , L_20 ) ;
return - V_56 ;
}
memset ( V_185 -> V_26 , 0 , V_25 ) ;
V_185 -> V_25 = V_25 ;
F_9 ( V_185 -> V_26 , V_82 , V_186 , V_25 ) ;
return 0 ;
}
static int
F_40 ( struct V_1 * V_2 ,
struct V_187 * V_188 ,
struct V_189 * V_190 ,
struct V_189 * V_191 ,
T_3 V_192 )
{
struct V_193 * V_8 ;
struct V_18 V_19 ;
T_3 V_147 ;
int V_179 ;
V_179 = F_39 ( V_2 , & V_19 ,
V_194 ,
sizeof( * V_8 ) ) ;
if ( V_179 )
return V_179 ;
V_147 = ( V_190 -> V_195 == V_196 ) ?
V_154 : V_148 ;
V_8 = V_19 . V_26 ;
V_8 -> V_197 . V_198 = 1 ;
V_8 -> V_197 . V_199 . V_200 = V_192 ;
V_8 -> V_197 . V_199 . V_201 =
V_2 -> V_174 ;
V_8 -> V_197 . V_199 . V_202 . V_203 =
sizeof( struct V_204 ) ;
V_8 -> V_197 . V_199 . V_202 . V_147 = V_147 ;
if ( V_192 == V_205 ) {
memcpy ( V_8 -> V_197 . V_199 . V_202 . V_149 , V_190 -> V_206 ,
V_190 -> V_32 ) ;
if ( V_191 )
memcpy ( V_8 -> V_197 . V_199 . V_202 . V_207 ,
V_191 -> V_206 , V_191 -> V_32 ) ;
} else {
memcpy ( V_8 -> V_197 . V_199 . V_202 . V_149 ,
V_188 -> V_202 . V_149 , V_190 -> V_32 ) ;
memcpy ( V_8 -> V_197 . V_199 . V_202 . V_207 ,
V_188 -> V_202 . V_207 , V_190 -> V_32 ) ;
}
V_179 = F_37 ( V_2 , & V_19 , NULL , 0 ) ;
if ( V_179 < 0 )
F_18 ( V_51 , V_2 -> V_52 ,
L_21 ) ;
return V_179 ;
}
static int F_41 ( struct V_1 * V_2 , T_4 * V_208 ,
T_3 V_209 , T_3 V_210 )
{
struct V_211 * V_8 ;
struct V_18 V_19 ;
int V_212 ;
V_212 = F_39 ( V_2 , & V_19 ,
V_213 ,
sizeof( * V_8 ) ) ;
if ( V_212 )
return V_212 ;
V_8 = V_19 . V_26 ;
V_8 -> V_200 = V_209 ;
V_8 -> V_202 . V_147 = V_148 ;
memcpy ( V_8 -> V_202 . V_149 , V_208 , V_210 ) ;
return F_37 ( V_2 , & V_19 , NULL , 0 ) ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_189 * V_190 ,
struct V_189 * V_191 ,
T_3 V_214 )
{
struct V_215 V_216 ;
struct V_187 V_188 ;
struct V_217 * V_218 ;
struct V_219 * V_220 ;
struct V_18 V_19 ;
T_4 * V_221 ;
T_3 V_147 ;
int V_179 ;
if ( F_36 ( V_2 ) )
return - V_183 ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
V_147 = ( V_190 -> V_195 == V_196 ) ?
V_154 : V_148 ;
V_179 = F_43 ( V_2 , V_147 , & V_188 ) ;
if ( V_179 )
return V_179 ;
if ( V_214 == V_222 ) {
if ( V_188 . V_223 ) {
F_18 ( V_51 , V_2 -> V_52 ,
L_22 ) ;
return 0 ;
}
V_190 -> V_32 = ( V_190 -> V_195 == V_196 ) ?
V_224 : V_225 ;
} else {
if ( V_188 . V_223 ) {
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
V_179 = F_39 ( V_2 , & V_19 ,
V_226 ,
sizeof( * V_220 ) ) ;
if ( V_179 )
return V_179 ;
V_220 = V_19 . V_26 ;
V_220 -> V_201 = V_2 -> V_174 ;
V_220 -> V_147 = V_147 ;
V_179 = F_37 ( V_2 , & V_19 , NULL , 0 ) ;
if ( V_179 < 0 ) {
F_18 ( V_51 , V_2 -> V_52 ,
L_23 ) ;
return V_179 ;
}
}
}
if ( V_188 . V_202 . V_149 [ 0 ] ) {
V_179 = F_40 ( V_2 , & V_188 , V_190 , NULL ,
V_227 ) ;
if ( V_179 )
return V_179 ;
}
if ( V_214 == V_222 ) {
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
V_179 = F_44 ( V_2 , V_148 , & V_216 ) ;
if ( V_179 ) {
F_18 ( V_51 , V_2 -> V_52 ,
L_24 ) ;
return V_179 ;
}
if ( V_216 . V_202 . V_149 [ 0 ] ) {
V_221 = ( T_4 * ) & V_216 . V_202 . V_149 ;
V_179 = F_41 ( V_2 , V_221 ,
V_227 , V_225 ) ;
if ( V_179 ) {
F_18 ( V_51 , V_2 -> V_52 ,
L_25 ) ;
return V_179 ;
}
}
}
if ( V_214 == V_222 ) {
V_179 = F_39 ( V_2 , & V_19 ,
V_228 ,
sizeof( * V_218 ) ) ;
if ( V_179 )
return V_179 ;
V_218 = V_19 . V_26 ;
V_218 -> V_229 = V_230 ;
V_218 -> V_231 = 1 ;
V_218 -> V_201 = V_2 -> V_174 ;
V_218 -> V_147 = V_232 ;
return F_37 ( V_2 , & V_19 , NULL , 0 ) ;
} else {
return F_40 ( V_2 , & V_188 , V_190 ,
V_191 , V_205 ) ;
}
return V_179 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_189 * V_233 )
{
struct V_215 V_216 ;
T_4 * V_221 ;
int V_212 ;
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
V_212 = F_44 ( V_2 , V_148 , & V_216 ) ;
if ( V_212 ) {
F_18 ( V_51 , V_2 -> V_52 ,
L_24 ) ;
return V_212 ;
}
if ( V_216 . V_202 . V_149 [ 0 ] ) {
V_221 = ( T_4 * ) & V_216 . V_202 . V_149 ;
V_212 = F_41 ( V_2 , V_221 , V_227 ,
V_233 -> V_32 ) ;
if ( V_212 ) {
F_18 ( V_51 , V_2 -> V_52 ,
L_25 ) ;
return V_212 ;
}
}
V_221 = ( T_4 * ) & V_233 -> V_206 ;
V_212 = F_41 ( V_2 , V_221 , V_205 ,
V_233 -> V_32 ) ;
if ( V_212 )
F_18 ( V_51 , V_2 -> V_52 ,
L_26 ) ;
return V_212 ;
}
int F_44 ( struct V_1 * V_2 , int V_147 ,
struct V_215 * V_234 )
{
struct V_235 * V_8 ;
struct V_18 V_19 ;
int V_179 ;
V_179 = F_39 ( V_2 , & V_19 ,
V_236 ,
sizeof( * V_234 ) ) ;
if ( V_179 )
return V_179 ;
V_8 = V_19 . V_26 ;
V_8 -> V_147 = V_147 ;
return F_37 ( V_2 , & V_19 , V_234 ,
sizeof( * V_234 ) ) ;
}
int F_43 ( struct V_1 * V_2 , int V_147 ,
struct V_187 * V_188 )
{
struct V_237 * V_8 ;
struct V_18 V_19 ;
int V_179 ;
if ( F_36 ( V_2 ) )
return - V_183 ;
V_179 = F_39 ( V_2 , & V_19 ,
V_238 ,
sizeof( * V_188 ) ) ;
if ( V_179 )
return V_179 ;
V_8 = V_19 . V_26 ;
V_8 -> V_201 = V_2 -> V_174 ;
V_8 -> V_147 = V_147 ;
return F_37 ( V_2 , & V_19 , V_188 ,
sizeof( * V_188 ) ) ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_239 * V_240 )
{
struct V_18 V_19 ;
int V_179 ;
V_179 = F_39 ( V_2 , & V_19 ,
V_241 ,
sizeof( * V_240 ) ) ;
if ( V_179 )
return V_179 ;
return F_37 ( V_2 , & V_19 , V_240 , sizeof( * V_240 ) ) ;
}
unsigned int F_47 ( struct V_1 * V_2 )
{
unsigned int V_9 = 0 ;
struct V_5 * V_6 ;
struct V_242 * V_8 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
V_6 = F_6 ( V_2 ) ;
V_8 = F_7 ( V_6 ) ;
V_6 -> V_12 |= V_9 ;
F_8 ( V_6 , sizeof( * V_8 ) , true , 0 ) ;
F_9 ( & V_8 -> V_13 , V_14 ,
V_243 ,
sizeof( * V_8 ) ) ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
unsigned int F_48 ( struct V_1 * V_2 )
{
unsigned int V_9 = 0 ;
struct V_5 * V_6 ;
struct V_244 * V_8 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
V_6 = F_6 ( V_2 ) ;
V_8 = F_7 ( V_6 ) ;
V_6 -> V_12 |= V_9 ;
F_8 ( V_6 , sizeof( * V_8 ) , true , 0 ) ;
F_9 ( & V_8 -> V_13 , V_36 ,
V_245 ,
sizeof( * V_8 ) ) ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}

int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
unsigned int V_12 ;
int V_13 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_16 ,
V_17 , sizeof( * V_11 ) ) ;
V_11 -> V_18 = F_8 ( V_5 ) ;
for ( V_13 = 0 ; V_13 < V_5 ; V_13 ++ ) {
V_11 -> V_19 [ V_13 ] . V_20 = F_8 ( V_4 [ V_13 ] . V_20 ) ;
V_11 -> V_19 [ V_13 ] . V_21 = 0 ;
V_11 -> V_19 [ V_13 ] . V_22 =
F_8 ( V_4 [ V_13 ] . V_22 ) ;
}
F_9 ( V_23 , & V_7 -> V_24 [ V_12 ] . V_25 ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_11 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 ;
struct V_8 * V_9 ;
struct V_32 * V_33 ;
unsigned int V_12 = 0 ;
struct V_34 * V_35 = V_27 -> V_36 ;
struct V_37 * V_11 = V_29 -> V_38 ;
unsigned short V_39 , V_40 , V_41 , V_42 ;
V_29 -> V_43 = V_27 -> V_44 . V_45 ;
memset ( V_29 -> V_38 , 0 , V_29 -> V_43 ) ;
V_31 = V_29 -> V_38 ;
V_39 = V_35 -> V_46 . V_47 . V_48 [ 1 ] ;
V_40 = V_35 -> V_46 . V_47 . V_48 [ 2 ] ;
V_41 = V_35 -> V_46 . V_47 . V_48 [ 3 ] ;
V_42 = V_35 -> V_46 . V_47 . V_48 [ 4 ] ;
V_11 -> V_39 = V_39 ;
V_11 -> V_41 = V_41 ;
V_11 -> V_42 = V_42 ;
if ( F_12 ( & V_7 -> V_14 ) )
return 0 ;
switch ( V_35 -> V_46 . V_47 . V_48 [ 0 ] ) {
case V_49 :
V_42 = V_41 * V_40 + V_42 ;
F_7 ( & V_11 -> V_15 , V_50 ,
V_51 , sizeof( * V_11 ) ) ;
F_13 ( V_27 -> V_44 . V_52 ,
V_27 -> V_44 . V_53 ,
V_29 -> V_38 + V_42 , V_27 -> V_54 ) ;
break;
case V_55 :
F_7 ( & V_11 -> V_15 , V_50 ,
V_56 , sizeof( * V_11 ) ) ;
break;
default:
F_14 ( V_2 , V_57 , V_58 ,
L_1 ,
V_35 -> V_46 . V_47 . V_48 [ 0 ] ) ;
F_4 ( & V_7 -> V_14 ) ;
return - V_59 ;
}
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_33 = F_15 ( V_9 ) ;
F_6 ( V_9 , V_29 -> V_43 , false ,
V_27 -> V_44 . V_53 ) ;
V_33 -> V_60 = F_8 ( F_16 ( V_29 -> V_61 ) ) ;
V_33 -> V_62 = F_8 ( V_29 -> V_61 & 0xFFFFFFFF ) ;
V_33 -> V_63 = F_8 ( V_29 -> V_43 ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_17 ( struct V_1 * V_2 ,
struct V_64 * V_65 ,
unsigned int V_66 , unsigned int V_67 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_32 * V_68 ;
struct V_69 * V_11 ;
unsigned int V_13 , V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = V_29 -> V_38 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_68 = F_15 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , false , 1 ) ;
F_7 ( & V_11 -> V_15 , V_50 ,
V_70 ,
sizeof( * V_11 ) ) ;
V_11 -> V_71 = 0 ;
V_11 -> V_72 = V_73 ;
for ( V_13 = 0 ; V_13 < V_66 ; V_13 ++ ) {
V_11 -> V_74 [ V_13 ] . V_75 = V_65 -> V_75 ;
V_11 -> V_74 [ V_13 ] . V_67 = V_65 -> V_67 ;
V_11 -> V_76 ++ ;
V_65 ++ ;
}
V_68 -> V_60 = F_8 ( F_16 ( V_29 -> V_61 ) ) ;
V_68 -> V_62 = F_8 ( V_29 -> V_61 & 0xFFFFFFFF ) ;
V_68 -> V_63 = F_8 ( V_29 -> V_43 ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_18 ( struct V_1 * V_2 ,
struct V_77 * V_78 ,
unsigned short V_67 ,
unsigned short V_79 ,
unsigned short V_80 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_81 * V_11 ;
unsigned int V_12 = 0 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_82 ,
V_83 ,
sizeof( * V_11 ) ) ;
V_11 -> V_84 = V_78 -> V_85 ;
V_11 -> V_67 = V_67 ;
if ( V_79 )
V_11 -> V_72 = V_86 ;
else
V_11 -> V_72 = V_87 ;
V_11 -> V_88 = V_80 ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_19 ( struct V_1 * V_2 ,
unsigned short V_67 , unsigned int V_89 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_90 * V_11 ;
unsigned int V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_91 ,
V_92 , sizeof( * V_11 ) ) ;
V_11 -> V_93 = ( unsigned short ) V_67 ;
V_11 -> V_94 = ( unsigned char ) V_89 ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_95 * V_96 ,
struct V_77 * V_78 ,
struct V_28 * V_29 )
{
struct V_97 * V_98 ;
struct V_99 * V_100 ;
struct V_101 * V_102 = (struct V_101 * ) V_96 ;
struct V_103 * V_104 = (struct V_103 * ) V_96 ;
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_105 * V_11 ;
unsigned short V_106 ;
unsigned short V_107 ;
struct V_108 V_109 = { 0 , 0 } ;
struct V_108 * V_110 ;
unsigned int V_12 = 0 ;
unsigned int V_13 , V_111 ;
unsigned short V_67 = V_78 -> V_112 ;
struct V_32 * V_68 ;
if ( V_96 -> V_113 != V_114 && V_96 -> V_113 != V_115 ) {
F_14 ( V_2 , V_116 , V_58 ,
L_2 ,
V_96 -> V_113 ) ;
return - V_117 ;
}
V_98 = V_2 -> V_98 ;
V_100 = V_98 -> V_118 ;
V_111 = V_98 -> V_119 [ F_21 ( V_67 ) ] . V_111 ;
V_106 = ( unsigned short ) F_22 ( V_2 , V_111 ) ;
V_107 = ( unsigned short ) F_23 ( V_2 , V_111 ) ;
V_110 = & V_109 ;
F_24 ( V_2 , V_110 ) ;
if ( F_12 ( & V_7 -> V_14 ) )
return 0 ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_68 = F_15 ( V_9 ) ;
V_11 = V_29 -> V_38 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_6 ( V_9 , V_29 -> V_43 , false , 1 ) ;
F_7 ( & V_11 -> V_15 , V_50 ,
V_120 ,
V_29 -> V_43 ) ;
if ( V_96 -> V_113 == V_114 ) {
T_1 V_121 = V_102 -> V_122 . V_121 ;
V_11 -> V_123 . V_124 = V_125 ;
V_11 -> V_123 . V_126 [ 0 ] = V_121 & 0x000000ff ;
V_11 -> V_123 . V_126 [ 1 ] = ( V_121 & 0x0000ff00 ) >> 8 ;
V_11 -> V_123 . V_126 [ 2 ] = ( V_121 & 0x00ff0000 ) >> 16 ;
V_11 -> V_123 . V_126 [ 3 ] = ( V_121 & 0xff000000 ) >> 24 ;
V_11 -> V_127 = F_25 ( V_102 -> V_128 ) ;
V_78 -> V_96 = V_102 -> V_122 . V_121 ;
V_78 -> V_129 = F_25 ( V_102 -> V_128 ) ;
V_78 -> V_124 = V_125 ;
} else {
V_11 -> V_123 . V_124 = V_130 ;
memcpy ( & V_11 -> V_123 . V_126 ,
& V_104 -> V_131 . V_132 . V_133 , 16 ) ;
V_11 -> V_127 = F_25 ( V_104 -> V_134 ) ;
V_78 -> V_129 = F_25 ( V_104 -> V_134 ) ;
memcpy ( & V_78 -> V_135 ,
& V_104 -> V_131 . V_132 . V_133 , 16 ) ;
V_78 -> V_124 = V_130 ;
}
V_11 -> V_67 = V_67 ;
V_13 = V_2 -> V_136 ++ ;
if ( V_2 -> V_136 == V_2 -> V_137 )
V_2 -> V_136 = 0 ;
V_11 -> V_138 = V_100 -> V_139 [ V_13 ] . V_93 ;
F_14 ( V_2 , V_140 , V_58 ,
L_3 , V_13 , V_11 -> V_138 ) ;
V_11 -> V_141 = V_106 ;
V_11 -> V_142 = V_106 ;
V_11 -> V_143 = V_107 ;
V_11 -> V_144 = 1 ;
V_11 -> V_145 . V_146 = V_110 -> V_146 ;
V_11 -> V_145 . V_147 = V_110 -> V_147 ;
V_68 -> V_60 = F_8 ( F_16 ( V_29 -> V_61 ) ) ;
V_68 -> V_62 = F_8 ( V_29 -> V_61 & 0xFFFFFFFF ) ;
V_68 -> V_63 = F_8 ( V_29 -> V_43 ) ;
if ( ! F_26 ( V_2 ) ) {
V_11 -> V_15 . V_148 = V_149 ;
V_11 -> V_150 = 0x8000 ;
V_11 -> V_151 = 2 ;
}
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_28 * V_29 , void * V_152 ,
int V_153 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_32 * V_68 ;
unsigned int V_12 ;
int V_154 = 0 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
V_154 = - V_155 ;
goto V_156;
}
V_68 = F_15 ( V_9 ) ;
F_6 ( V_9 , V_29 -> V_43 , false , 1 ) ;
V_68 -> V_60 = F_8 ( F_16 ( V_29 -> V_61 ) ) ;
V_68 -> V_62 = F_8 ( F_28 ( V_29 -> V_61 ) ) ;
V_68 -> V_63 = F_8 ( V_29 -> V_43 ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
V_154 = F_29 ( V_2 , V_12 , NULL , V_29 ) ;
if ( V_152 )
memcpy ( V_152 , V_29 -> V_38 , V_153 ) ;
if ( V_154 ) {
if ( V_154 == - V_157 )
return V_154 ;
F_14 ( V_2 , V_57 ,
V_58 | V_158 ,
L_4 ) ;
if ( V_154 != - V_159 )
goto V_156;
else
return V_154 ;
}
V_156:
F_30 ( V_7 -> V_160 , V_29 -> V_43 ,
V_29 -> V_38 , V_29 -> V_61 ) ;
return V_154 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_28 * V_161 ,
int V_162 , int V_43 )
{
V_161 -> V_38 = F_32 ( V_2 -> V_7 . V_160 , V_43 , & V_161 -> V_61 ) ;
if ( ! V_161 -> V_38 ) {
F_14 ( V_2 , V_116 , V_58 ,
L_5 ) ;
return - V_155 ;
}
V_161 -> V_43 = V_43 ;
F_7 ( V_161 -> V_38 , V_50 , V_162 , V_43 ) ;
F_14 ( V_2 , V_140 , V_58 ,
L_6 ,
V_162 , V_43 ) ;
return 0 ;
}
unsigned int F_33 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_163 * V_11 ;
struct V_163 * V_164 ;
unsigned int V_12 ;
int V_165 = 0 ;
if ( F_12 ( & V_7 -> V_14 ) )
return - V_166 ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return - V_155 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_50 ,
V_167 ,
sizeof( * V_11 ) ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
V_165 = F_29 ( V_2 , V_12 , & V_9 , NULL ) ;
if ( V_165 ) {
F_14 ( V_2 , V_57 , V_58 ,
L_7 , V_168 , V_165 ) ;
return - V_159 ;
}
V_164 = F_5 ( V_9 ) ;
V_2 -> V_169 = V_164 -> V_170 [ 0 ] ;
return V_165 ;
}
static inline bool F_34 ( T_2 * V_171 , T_3 V_124 )
{
T_3 V_63 ;
V_63 = ( V_124 < V_130 ) ? V_172 : V_173 ;
while ( V_63 && ! V_171 [ V_63 - 1 ] )
V_63 -- ;
return ( V_63 == 0 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
T_3 V_174 , T_3 V_124 , T_2 * V_175 )
{
struct V_176 * V_11 ;
struct V_28 V_29 ;
int V_177 ;
V_177 = F_31 ( V_2 , & V_29 ,
V_178 ,
sizeof( * V_11 ) ) ;
if ( V_177 )
return V_177 ;
V_11 = V_29 . V_38 ;
V_11 -> V_174 = V_174 ;
V_11 -> V_179 . V_124 = V_124 ;
memcpy ( V_11 -> V_179 . V_126 , V_175 ,
( V_124 < V_130 ) ? V_172 : V_173 ) ;
return F_27 ( V_2 , & V_29 , NULL , 0 ) ;
}
int F_36 ( struct V_1 * V_2 , T_3 V_124 , T_2 * V_175 )
{
struct V_180 V_181 ;
int V_177 ;
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
V_177 = F_37 ( V_2 , V_124 , & V_181 ) ;
if ( V_177 ) {
F_14 ( V_2 , V_57 , V_58 ,
L_8 ) ;
return V_177 ;
}
if ( ! F_34 ( V_181 . V_179 . V_126 , V_124 ) ) {
V_177 = F_35 ( V_2 , V_182 , V_124 ,
V_181 . V_179 . V_126 ) ;
if ( V_177 ) {
F_14 ( V_2 , V_57 , V_58 ,
L_9 ) ;
return V_177 ;
}
}
V_177 = F_35 ( V_2 , V_183 , V_124 , V_175 ) ;
if ( V_177 )
F_14 ( V_2 , V_57 , V_58 ,
L_10 ) ;
return V_177 ;
}
int F_37 ( struct V_1 * V_2 , T_3 V_124 ,
struct V_180 * V_31 )
{
struct V_184 * V_11 ;
struct V_28 V_29 ;
int V_154 ;
V_154 = F_31 ( V_2 , & V_29 ,
V_185 ,
sizeof( * V_31 ) ) ;
if ( V_154 )
return V_154 ;
V_11 = V_29 . V_38 ;
V_11 -> V_124 = V_124 ;
return F_27 ( V_2 , & V_29 , V_31 ,
sizeof( * V_31 ) ) ;
}
static int
F_38 ( struct V_1 * V_2 ,
struct V_186 * V_187 )
{
struct V_188 * V_11 ;
struct V_28 V_29 ;
int V_154 ;
V_154 = F_31 ( V_2 , & V_29 ,
V_189 ,
sizeof( * V_11 ) ) ;
if ( V_154 )
return V_154 ;
V_11 = V_29 . V_38 ;
V_11 -> V_190 . V_191 = 1 ;
V_11 -> V_190 . V_192 . V_174 = V_182 ;
V_11 -> V_190 . V_192 . V_193 =
V_2 -> V_169 ;
V_11 -> V_190 . V_192 . V_179 . V_194 =
sizeof( struct V_195 ) ;
V_11 -> V_190 . V_192 . V_179 . V_124 = V_187 -> V_179 . V_124 ;
memcpy ( V_11 -> V_190 . V_192 . V_179 . V_126 ,
V_187 -> V_179 . V_126 ,
sizeof( V_187 -> V_179 . V_126 ) ) ;
memcpy ( V_11 -> V_190 . V_192 . V_179 . V_196 ,
V_187 -> V_179 . V_196 ,
sizeof( V_187 -> V_179 . V_196 ) ) ;
V_154 = F_27 ( V_2 , & V_29 , NULL , 0 ) ;
if ( V_154 < 0 || V_11 -> V_190 . V_192 . V_165 ) {
F_14 ( V_2 , V_140 , V_58 ,
L_11 ,
V_154 , V_11 -> V_190 . V_192 . V_165 ) ;
}
return V_154 ;
}
static int
F_39 ( struct V_1 * V_2 , T_2 * V_171 ,
T_2 * V_197 , T_3 V_124 )
{
struct V_188 * V_11 ;
struct V_28 V_29 ;
T_4 V_198 ;
int V_154 ;
V_154 = F_31 ( V_2 , & V_29 ,
V_189 ,
sizeof( * V_11 ) ) ;
if ( V_154 )
return V_154 ;
V_11 = V_29 . V_38 ;
V_11 -> V_190 . V_191 = 1 ;
V_11 -> V_190 . V_192 . V_174 = V_183 ;
V_11 -> V_190 . V_192 . V_193 =
V_2 -> V_169 ;
V_11 -> V_190 . V_192 . V_179 . V_194 =
sizeof( struct V_195 ) ;
V_11 -> V_190 . V_192 . V_179 . V_124 = V_124 ;
V_198 = ( V_124 < V_130 ) ? V_172 : V_173 ;
memcpy ( V_11 -> V_190 . V_192 . V_179 . V_126 , V_171 , V_198 ) ;
if ( V_197 )
memcpy ( V_11 -> V_190 . V_192 . V_179 . V_196 ,
V_197 , V_198 ) ;
V_154 = F_27 ( V_2 , & V_29 , NULL , 0 ) ;
if ( V_154 < 0 || V_11 -> V_190 . V_192 . V_165 ) {
F_40 ( V_2 , V_116 ,
L_12 ,
V_154 , V_11 -> V_190 . V_192 . V_165 ) ;
if ( V_11 -> V_190 . V_192 . V_165 )
V_154 = - V_117 ;
}
return V_154 ;
}
int F_41 ( struct V_1 * V_2 , T_3 V_124 ,
T_2 * V_171 , T_2 * V_197 )
{
struct V_186 * V_187 ;
struct V_199 * V_200 ;
struct V_28 V_29 ;
int V_154 ;
V_154 = F_42 ( V_2 , V_124 , & V_187 ) ;
if ( V_154 )
return V_154 ;
if ( V_187 -> V_201 ) {
V_154 = F_31 ( V_2 , & V_29 ,
V_202 ,
sizeof( * V_200 ) ) ;
if ( V_154 )
goto exit;
V_200 = V_29 . V_38 ;
V_200 -> V_193 = V_2 -> V_169 ;
V_200 -> V_124 = V_124 ;
V_154 = F_27 ( V_2 , & V_29 , NULL , 0 ) ;
if ( V_154 < 0 ) {
F_14 ( V_2 , V_57 , V_58 ,
L_13 ,
V_154 ) ;
goto exit;
}
}
if ( ! F_34 ( V_187 -> V_179 . V_126 , V_124 ) ) {
V_154 = F_38 ( V_2 , V_187 ) ;
if ( V_154 )
goto exit;
}
if ( V_171 )
V_154 = F_39 ( V_2 , V_171 , V_197 , V_124 ) ;
exit:
F_43 ( V_187 ) ;
return V_154 ;
}
int F_44 ( struct V_1 * V_2 , T_3 V_124 )
{
struct V_180 V_181 ;
struct V_186 * V_187 ;
struct V_203 * V_204 ;
struct V_28 V_29 ;
T_2 * V_175 ;
int V_154 ;
V_154 = F_42 ( V_2 , V_124 , & V_187 ) ;
if ( V_154 )
return V_154 ;
if ( V_187 -> V_201 ) {
F_14 ( V_2 , V_57 , V_58 ,
L_14 ) ;
goto exit;
}
if ( ! F_34 ( V_187 -> V_179 . V_126 , V_124 ) ) {
V_154 = F_38 ( V_2 , V_187 ) ;
if ( V_154 )
goto exit;
}
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
V_154 = F_37 ( V_2 , V_187 -> V_179 . V_124 , & V_181 ) ;
if ( V_154 ) {
F_14 ( V_2 , V_57 , V_58 ,
L_8 ) ;
goto exit;
}
V_175 = ( T_2 * ) & V_181 . V_179 . V_126 ;
if ( ! F_34 ( V_175 , V_187 -> V_179 . V_124 ) ) {
V_154 = F_35 ( V_2 , V_182 ,
V_187 -> V_179 . V_124 , V_175 ) ;
if ( V_154 ) {
F_14 ( V_2 , V_57 , V_58 ,
L_9 ) ;
goto exit;
}
}
V_154 = F_31 ( V_2 , & V_29 ,
V_205 ,
sizeof( * V_204 ) ) ;
if ( V_154 )
goto exit;
V_204 = V_29 . V_38 ;
V_204 -> V_206 = 1 ;
V_204 -> V_207 = 1 ;
V_204 -> V_193 = V_2 -> V_169 ;
V_204 -> V_124 = V_124 ;
V_154 = F_27 ( V_2 , & V_29 , NULL , 0 ) ;
exit:
F_43 ( V_187 ) ;
return V_154 ;
}
int F_45 ( struct V_1 * V_2 , T_5 V_208 )
{
int V_154 ;
unsigned int V_12 ;
V_12 = F_46 ( V_2 , V_208 ) ;
if ( ! V_12 ) {
F_14 ( V_2 , V_116 ,
( V_58 | V_158 ) ,
L_15 ) ;
return - V_159 ;
}
V_154 = F_29 ( V_2 , V_12 , NULL , NULL ) ;
if ( V_154 ) {
F_14 ( V_2 , V_116 ,
( V_58 | V_158 ) ,
L_16 ) ;
return V_154 ;
}
return V_154 ;
}
int F_42 ( struct V_1 * V_2 , int V_124 ,
struct V_186 * * V_187 )
{
struct V_209 * V_11 ;
struct V_28 V_29 ;
T_4 V_210 = sizeof( struct V_186 ) ;
int V_154 ;
V_154 = F_33 ( V_2 ) ;
if ( V_154 )
return V_154 ;
do {
V_154 = F_31 ( V_2 , & V_29 ,
V_211 ,
V_210 ) ;
if ( V_154 )
return V_154 ;
V_11 = V_29 . V_38 ;
V_11 -> V_193 = V_2 -> V_169 ;
V_11 -> V_124 = V_124 ;
* V_187 = F_47 ( V_210 , V_212 ) ;
if ( ! * V_187 ) {
F_14 ( V_2 , V_116 ,
V_213 | V_58 ,
L_17 ) ;
F_30 ( V_2 -> V_7 . V_160 ,
V_29 . V_43 ,
V_29 . V_38 ,
V_29 . V_61 ) ;
return - V_155 ;
}
V_154 = F_27 ( V_2 , & V_29 , * V_187 ,
V_210 ) ;
if ( V_154 == - V_157 ) {
V_210 = ( (struct V_30 * )
V_29 . V_38 ) -> V_214 ;
V_210 += sizeof( struct V_215 ) ;
F_30 ( V_2 -> V_7 . V_160 , V_29 . V_43 ,
V_29 . V_38 ,
V_29 . V_61 ) ;
F_43 ( * V_187 ) ;
} else
break;
} while ( true );
return V_154 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
struct V_28 V_29 ;
int V_154 ;
V_154 = F_31 ( V_2 , & V_29 ,
V_218 ,
sizeof( * V_217 ) ) ;
if ( V_154 )
return V_154 ;
return F_27 ( V_2 , & V_29 , V_217 , sizeof( * V_217 ) ) ;
}
unsigned int F_49 ( struct V_1 * V_2 )
{
unsigned int V_12 ;
struct V_8 * V_9 ;
struct V_219 * V_11 ;
struct V_6 * V_7 = & V_2 -> V_7 ;
if ( F_12 ( & V_7 -> V_14 ) )
return 0 ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_82 ,
V_220 ,
sizeof( * V_11 ) ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
static void F_50 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
struct V_221 * V_222 ;
struct V_223 * V_224 ;
struct V_225 * V_226 ;
struct V_8 * V_9 ;
struct V_227 * V_228 ;
int V_229 , V_165 ;
if ( ! F_51 ( V_230 , & V_2 -> V_231 ) ) {
F_40 ( V_2 , V_116 ,
L_18 ,
V_168 , V_2 -> V_231 ) ;
return;
}
if ( V_2 -> V_227 . V_12 != V_12 ) {
F_40 ( V_2 , V_116 ,
L_19 ,
V_168 , V_12 , V_2 -> V_227 . V_12 ) ;
return;
}
V_228 = & V_2 -> V_227 ;
V_229 = 1 ;
V_165 = 0 ;
switch ( V_228 -> V_174 ) {
case V_232 :
V_165 = F_52 ( V_2 , V_12 , NULL , NULL ) ;
if ( ! V_165 )
V_228 -> V_174 = V_233 ;
else
V_228 -> V_234 -- ;
break;
case V_233 :
V_165 = F_52 ( V_2 , V_12 , & V_9 , NULL ) ;
if ( ! V_165 ) {
V_222 = F_5 ( V_9 ) ;
V_228 -> V_235 = V_222 -> V_236 ;
}
if ( V_228 -> V_235 == V_237 ) {
V_228 -> V_174 = V_232 ;
V_228 -> V_234 -- ;
} else {
V_228 -> V_174 = V_238 ;
}
break;
case V_238 :
V_165 = F_52 ( V_2 , V_12 , NULL ,
& V_228 -> V_29 ) ;
if ( ! V_165 ) {
V_226 = V_228 -> V_29 . V_38 ;
memcpy ( & V_228 -> V_239 , & V_226 -> V_240 ,
sizeof( struct V_241 ) ) ;
V_228 -> V_174 = V_242 ;
} else {
F_40 ( V_2 , V_116 ,
L_20 ,
V_165 ) ;
V_229 = 0 ;
}
F_30 ( V_2 -> V_7 . V_160 , V_228 -> V_29 . V_43 ,
V_228 -> V_29 . V_38 , V_228 -> V_29 . V_61 ) ;
V_228 -> V_29 . V_38 = NULL ;
break;
case V_242 :
V_165 = F_52 ( V_2 , V_12 , & V_9 , NULL ) ;
if ( ! V_165 ) {
V_224 = F_5 ( V_9 ) ;
if ( V_224 -> V_243 != V_244 ) {
F_40 ( V_2 , V_116 ,
L_21 ,
V_224 -> V_243 ) ;
}
}
V_228 -> V_174 = V_245 ;
break;
default:
break;
}
V_228 -> V_12 = 0 ;
if ( ! V_228 -> V_234 ) {
V_229 = 0 ;
F_40 ( V_2 , V_116 ,
L_22 ,
V_165 , V_228 -> V_174 ) ;
}
if ( ! V_229 ) {
F_53 ( V_230 , & V_2 -> V_231 ) ;
return;
}
F_54 ( & V_2 -> V_229 ) ;
}
unsigned int F_55 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_246 * V_11 ;
unsigned int V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_82 ,
V_247 ,
sizeof( struct V_246 ) ) ;
V_11 -> V_84 = V_2 -> V_227 . V_239 . V_84 ;
V_2 -> V_227 . V_12 = V_12 ;
F_9 ( V_248 , & V_7 -> V_24 [ V_12 ] . V_25 ) ;
V_7 -> V_24 [ V_12 ] . V_249 = F_50 ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_56 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_250 * V_11 ;
unsigned int V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_82 ,
V_251 ,
sizeof( struct V_252 ) ) ;
V_11 -> V_253 = V_254 ;
V_11 -> V_84 = V_237 ;
V_2 -> V_227 . V_12 = V_12 ;
F_9 ( V_248 , & V_7 -> V_24 [ V_12 ] . V_25 ) ;
V_7 -> V_24 [ V_12 ] . V_249 = F_50 ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_57 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_225 * V_31 ;
struct V_255 * V_11 ;
struct V_28 * V_29 ;
struct V_8 * V_9 ;
struct V_32 * V_68 ;
unsigned int V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_29 = & V_2 -> V_227 . V_29 ;
V_29 -> V_43 = sizeof( * V_31 ) ;
V_29 -> V_38 = F_58 ( V_2 -> V_7 . V_160 ,
V_29 -> V_43 ,
& V_29 -> V_61 ) ;
if ( ! V_29 -> V_38 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = V_29 -> V_38 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_68 = F_15 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , false , 1 ) ;
F_7 ( & V_11 -> V_15 , V_82 ,
V_256 ,
sizeof( * V_31 ) ) ;
V_11 -> V_84 = V_2 -> V_227 . V_235 ;
V_68 -> V_60 = F_8 ( F_16 ( V_29 -> V_61 ) ) ;
V_68 -> V_62 = F_8 ( V_29 -> V_61 & 0xFFFFFFFF ) ;
V_68 -> V_63 = F_8 ( V_29 -> V_43 ) ;
V_2 -> V_227 . V_12 = V_12 ;
F_9 ( V_248 , & V_7 -> V_24 [ V_12 ] . V_25 ) ;
V_7 -> V_24 [ V_12 ] . V_249 = F_50 ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_59 ( struct V_1 * V_2 , int V_257 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_258 * V_11 ;
unsigned int V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_82 ,
V_259 ,
sizeof( struct V_221 ) ) ;
if ( V_257 ) {
V_2 -> V_227 . V_12 = V_12 ;
F_9 ( V_248 , & V_7 -> V_24 [ V_12 ] . V_25 ) ;
V_7 -> V_24 [ V_12 ] . V_249 = F_50 ;
}
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
int F_60 ( struct V_1 * V_2 , unsigned int * V_235 )
{
struct V_221 * V_222 ;
struct V_8 * V_9 ;
unsigned int V_12 ;
int V_154 ;
* V_235 = V_237 ;
V_12 = F_59 ( V_2 , 0 ) ;
if ( ! V_12 ) {
F_14 ( V_2 , V_116 ,
V_58 | V_213 ,
L_23 ) ;
return - V_157 ;
}
V_154 = F_29 ( V_2 , V_12 , & V_9 , NULL ) ;
if ( V_154 ) {
F_14 ( V_2 , V_116 ,
V_213 | V_58 ,
L_24 ) ;
return - V_159 ;
}
V_222 = F_5 ( V_9 ) ;
if ( ! V_222 -> V_260 ) {
F_40 ( V_2 , V_140 ,
L_25 ) ;
return - V_261 ;
}
* V_235 = V_222 -> V_236 ;
return 1 ;
}
T_6
F_61 ( struct V_262 * V_263 , struct V_264 * V_265 ,
char * V_266 )
{
return snprintf ( V_266 , V_267 , V_268 L_26 ) ;
}
T_6
F_62 ( struct V_262 * V_263 , struct V_264 * V_265 ,
char * V_266 )
{
struct V_269 * V_270 = F_63 ( V_263 ) ;
struct V_1 * V_2 = F_64 ( V_270 ) ;
return snprintf ( V_266 , V_267 , L_27 , V_2 -> V_271 ) ;
}
T_6
F_65 ( struct V_262 * V_263 , struct V_264 * V_265 ,
char * V_266 )
{
struct V_269 * V_270 = F_63 ( V_263 ) ;
struct V_1 * V_2 = F_64 ( V_270 ) ;
T_5 V_272 = 0 , V_111 , V_63 = 0 , V_273 = 0 ;
for ( V_111 = 0 ; V_111 < V_274 ; V_111 ++ ) {
if ( F_51 ( V_111 , ( void * ) & V_2 -> V_275 . V_276 ) ) {
V_272 = F_66 ( V_2 , V_111 ) ;
V_273 = F_67 ( V_2 , V_111 ) ;
V_63 += snprintf ( V_266 + V_63 , V_267 - V_63 ,
L_28 , V_111 ,
( V_273 - V_272 ) ) ;
} else
V_63 += snprintf ( V_266 + V_63 , V_267 - V_63 ,
L_28 , V_111 , 0 ) ;
}
return V_63 ;
}
T_6
F_68 ( struct V_262 * V_263 , struct V_264 * V_265 ,
char * V_266 )
{
struct V_269 * V_270 = F_63 ( V_263 ) ;
struct V_1 * V_2 = F_64 ( V_270 ) ;
T_5 V_111 , V_63 = 0 ;
for ( V_111 = 0 ; V_111 < V_274 ; V_111 ++ ) {
if ( F_51 ( V_111 , ( void * ) & V_2 -> V_275 . V_276 ) )
V_63 += snprintf ( V_266 + V_63 , V_267 - V_63 ,
L_28 , V_111 ,
F_66 ( V_2 , V_111 ) ) ;
else
V_63 += snprintf ( V_266 + V_63 , V_267 - V_63 ,
L_28 , V_111 , 0 ) ;
}
return V_63 ;
}
T_6
F_69 ( struct V_262 * V_263 , struct V_264 * V_265 ,
char * V_266 )
{
T_5 V_277 = 0 ;
struct V_269 * V_270 = F_63 ( V_263 ) ;
struct V_1 * V_2 = F_64 ( V_270 ) ;
V_277 = V_2 -> V_278 -> V_262 ;
switch ( V_277 ) {
case V_279 :
case V_280 :
case V_281 :
return snprintf ( V_266 , V_267 , L_29 ) ;
break;
case V_282 :
case V_283 :
return snprintf ( V_266 , V_267 , L_30 ) ;
break;
case V_284 :
return snprintf ( V_266 , V_267 , L_31 ) ;
break;
default:
return snprintf ( V_266 , V_267 ,
L_32 , V_277 ) ;
break;
}
}
T_6
F_70 ( struct V_262 * V_263 , struct V_264 * V_265 ,
char * V_266 )
{
struct V_269 * V_270 = F_63 ( V_263 ) ;
struct V_1 * V_2 = F_64 ( V_270 ) ;
return snprintf ( V_266 , V_267 , L_33 ,
V_2 -> V_275 . V_285 ) ;
}
void F_71 ( struct V_286 * V_287 ,
struct V_288 * V_289 ,
struct V_290 * V_291 ,
struct V_292 * V_293 )
{
struct V_294 * V_295 = V_289 -> V_295 ;
F_72 ( struct V_296 ,
V_297 , V_295 ,
V_287 -> V_298 [ F_73 ( struct V_299 ,
V_297 ) / 32 ] ) ;
F_72 ( struct V_296 , type , V_295 ,
V_300 ) ;
F_72 ( struct V_296 ,
V_301 ,
V_295 ,
V_287 -> V_298 [ F_73 ( struct V_299 ,
V_301 ) / 32 ] ) ;
F_72 ( struct V_296 , V_302 , V_295 ,
( V_287 -> V_298 [ F_73 ( struct V_299 ,
V_302 ) / 32 ] & V_303 ) ) ;
F_72 ( struct V_296 , V_304 , V_295 ,
( V_287 -> V_298 [ F_73 ( struct V_299 ,
V_304 ) / 32 ] & V_305 ) >> 2 ) ;
F_72 ( struct V_296 , V_306 , V_295 ,
( V_287 -> V_298 [ F_73 ( struct V_299 ,
V_306 ) / 32 ] & V_307 ) >> 3 ) ;
F_72 ( struct V_296 , V_308 , V_295 ,
( V_287 -> V_298 [ F_73 ( struct V_299 ,
V_308 ) / 32 ] & V_309 ) >> 4 ) ;
F_72 ( struct V_296 , V_310 , V_295 ,
( V_287 -> V_298 [ F_73 ( struct V_299 ,
V_310 ) / 32 ] & V_311 ) >> 5 ) ;
F_72 ( struct V_296 , V_312 ,
V_295 ,
( V_287 -> V_298 [ F_73 ( struct V_299 ,
V_313 ) / 32 ] + 1 ) ) ;
F_72 ( struct V_296 , V_314 ,
V_295 , V_289 -> V_315 ) ;
F_72 ( struct V_296 ,
V_316 , V_295 , V_287 -> V_298 [ F_73
( struct V_299 ,
V_316 ) / 32 ] ) ;
F_72 ( struct V_296 , V_317 ,
V_295 , V_289 -> V_315 ) ;
if ( V_293 -> V_318 )
F_72 ( struct V_296 ,
V_317 ,
V_293 -> V_318 ,
V_289 -> V_315 ) ;
V_293 -> V_318 = V_295 ;
F_72 ( struct V_296 ,
V_319 , V_295 , 0 ) ;
F_72 ( struct V_296 , V_320 ,
V_295 , 1 ) ;
F_72 ( struct V_296 , V_321 ,
V_295 , 0 ) ;
F_72 ( struct V_296 , V_322 , V_295 ,
0 ) ;
V_291 += V_323 ;
F_72 ( struct V_296 ,
V_324 , V_295 ,
V_291 -> V_325 [ 0 ] . V_326 . V_327 . V_328 . V_329 ) ;
F_72 ( struct V_296 ,
V_330 , V_295 ,
V_291 -> V_325 [ 0 ] . V_326 . V_327 . V_328 . V_331 ) ;
}
void F_74 ( struct V_286 * V_287 ,
struct V_288 * V_289 ,
struct V_292 * V_293 )
{
struct V_294 * V_295 = V_289 -> V_295 ;
F_72 ( struct V_332 ,
V_316 , V_295 , V_287 -> V_298 [ F_73
( struct V_299 ,
V_316 ) / 32 ] ) ;
F_72 ( struct V_332 ,
type , V_295 ,
V_300 ) ;
F_72 ( struct V_332 ,
V_317 ,
V_295 , V_289 -> V_315 ) ;
if ( V_293 -> V_318 )
F_72 ( struct V_332 ,
V_317 ,
V_293 -> V_318 ,
V_289 -> V_315 ) ;
V_293 -> V_318 = V_295 ;
F_72 ( struct V_332 , V_314 ,
V_295 , V_289 -> V_315 ) ;
F_72 ( struct V_332 ,
V_297 , V_295 ,
V_287 -> V_298 [ F_73 ( struct V_299 ,
V_297 ) / 32 ] ) ;
F_72 ( struct V_332 ,
V_301 , V_295 ,
V_287 -> V_298 [ F_73 ( struct V_299 ,
V_301 ) / 32 ] ) ;
F_72 ( struct V_332 ,
V_333 , V_295 ,
V_287 -> V_298 [ F_73 ( struct V_299 ,
V_334 ) / 32 ] ) ;
F_72 ( struct V_332 ,
V_335 , V_295 , V_336 ) ;
F_72 ( struct V_332 , V_302 , V_295 ,
( V_287 -> V_298 [ F_73 ( struct V_299 ,
V_302 ) / 32 ] & V_303 ) ) ;
F_72 ( struct V_332 , V_304 , V_295 ,
( V_287 -> V_298 [ F_73 ( struct V_299 ,
V_304 ) / 32 ] & V_305 ) >> 2 ) ;
F_72 ( struct V_332 , V_306 , V_295 ,
( V_287 -> V_298 [ F_73 ( struct V_299 ,
V_306 ) / 32 ] & V_307 ) >> 3 ) ;
F_72 ( struct V_332 ,
V_308 , V_295 ,
( V_287 -> V_298 [ F_73 ( struct V_299 ,
V_308 ) / 32 ] & V_309 ) >> 4 ) ;
F_72 ( struct V_332 , V_310 , V_295 ,
( V_287 -> V_298 [ F_73 ( struct V_299 ,
V_310 ) / 32 ] & V_311 ) >> 5 ) ;
F_72 ( struct V_332 ,
V_337 ,
V_295 ,
( V_287 -> V_298 [ F_73 ( struct V_299 ,
V_337 ) / 32 ] &
V_338 ) >> 6 ) ;
F_72 ( struct V_332 ,
V_339 ,
V_295 ,
( V_287 -> V_298 [ F_73 ( struct V_299 ,
V_339 ) / 32 ] &
V_340 ) >> 7 ) ;
F_72 ( struct V_332 , V_341 ,
V_295 ,
( V_287 -> V_298 [ F_73 ( struct V_299 ,
V_341 ) / 32 ] &
V_342 ) >> 8 ) ;
F_72 ( struct V_332 , V_312 ,
V_295 ,
( V_287 -> V_298 [ F_73 ( struct V_299 ,
V_313 ) / 32 ] + 1 ) ) ;
}

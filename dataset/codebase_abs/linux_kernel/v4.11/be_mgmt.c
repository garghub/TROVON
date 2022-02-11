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
struct V_8 * V_9 ;
struct V_30 * V_31 ;
unsigned int V_12 = 0 ;
struct V_32 * V_33 = V_27 -> V_34 ;
struct V_35 * V_11 = V_29 -> V_36 ;
unsigned short V_37 , V_38 , V_39 , V_40 ;
V_29 -> V_41 = V_27 -> V_42 . V_43 ;
memset ( V_29 -> V_36 , 0 , V_29 -> V_41 ) ;
V_37 = V_33 -> V_44 . V_45 . V_46 [ 1 ] ;
V_38 = V_33 -> V_44 . V_45 . V_46 [ 2 ] ;
V_39 = V_33 -> V_44 . V_45 . V_46 [ 3 ] ;
V_40 = V_33 -> V_44 . V_45 . V_46 [ 4 ] ;
V_11 -> V_37 = V_37 ;
V_11 -> V_39 = V_39 ;
V_11 -> V_40 = V_40 ;
if ( F_12 ( & V_7 -> V_14 ) )
return 0 ;
switch ( V_33 -> V_44 . V_45 . V_46 [ 0 ] ) {
case V_47 :
V_40 = V_39 * V_38 + V_40 ;
F_7 ( & V_11 -> V_15 , V_48 ,
V_49 , sizeof( * V_11 ) ) ;
F_13 ( V_27 -> V_42 . V_50 ,
V_27 -> V_42 . V_51 ,
V_29 -> V_36 + V_40 , V_27 -> V_52 ) ;
break;
case V_53 :
F_7 ( & V_11 -> V_15 , V_48 ,
V_54 , sizeof( * V_11 ) ) ;
break;
default:
F_14 ( V_2 , V_55 , V_56 ,
L_1 ,
V_33 -> V_44 . V_45 . V_46 [ 0 ] ) ;
F_4 ( & V_7 -> V_14 ) ;
return - V_57 ;
}
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_31 = F_15 ( V_9 ) ;
F_6 ( V_9 , V_29 -> V_41 , false ,
V_27 -> V_42 . V_51 ) ;
V_31 -> V_58 = F_8 ( F_16 ( V_29 -> V_59 ) ) ;
V_31 -> V_60 = F_8 ( V_29 -> V_59 & 0xFFFFFFFF ) ;
V_31 -> V_61 = F_8 ( V_29 -> V_41 ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_17 ( struct V_1 * V_2 ,
struct V_62 * V_63 ,
unsigned short V_64 ,
unsigned short V_65 ,
unsigned short V_66 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_67 * V_11 ;
unsigned int V_12 = 0 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_68 ,
V_69 ,
sizeof( * V_11 ) ) ;
V_11 -> V_70 = V_63 -> V_71 ;
V_11 -> V_64 = V_64 ;
if ( V_65 )
V_11 -> V_72 = V_73 ;
else
V_11 -> V_72 = V_74 ;
V_11 -> V_75 = V_66 ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_18 ( struct V_1 * V_2 ,
unsigned short V_64 , unsigned int V_76 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_77 * V_11 ;
unsigned int V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_78 ,
V_79 , sizeof( * V_11 ) ) ;
V_11 -> V_80 = ( unsigned short ) V_64 ;
V_11 -> V_81 = ( unsigned char ) V_76 ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_62 * V_63 ,
struct V_28 * V_29 )
{
struct V_84 * V_85 ;
struct V_86 * V_87 ;
struct V_88 * V_89 = (struct V_88 * ) V_83 ;
struct V_90 * V_91 = (struct V_90 * ) V_83 ;
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_92 * V_11 ;
unsigned short V_93 ;
unsigned short V_94 ;
struct V_95 V_96 = { 0 , 0 } ;
struct V_95 * V_97 ;
unsigned int V_12 = 0 ;
unsigned int V_13 , V_98 ;
unsigned short V_64 = V_63 -> V_99 ;
struct V_30 * V_100 ;
if ( V_83 -> V_101 != V_102 && V_83 -> V_101 != V_103 ) {
F_14 ( V_2 , V_104 , V_56 ,
L_2 ,
V_83 -> V_101 ) ;
return - V_105 ;
}
V_85 = V_2 -> V_85 ;
V_87 = V_85 -> V_106 ;
V_98 = V_85 -> V_107 [ F_20 ( V_64 ) ] . V_98 ;
V_93 = ( unsigned short ) F_21 ( V_2 , V_98 ) ;
V_94 = ( unsigned short ) F_22 ( V_2 , V_98 ) ;
V_97 = & V_96 ;
F_23 ( V_2 , V_97 ) ;
if ( F_12 ( & V_7 -> V_14 ) )
return 0 ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_100 = F_15 ( V_9 ) ;
V_11 = V_29 -> V_36 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_6 ( V_9 , V_29 -> V_41 , false , 1 ) ;
F_7 ( & V_11 -> V_15 , V_48 ,
V_108 ,
V_29 -> V_41 ) ;
if ( V_83 -> V_101 == V_102 ) {
T_1 V_109 = V_89 -> V_110 . V_109 ;
V_11 -> V_111 . V_112 = V_113 ;
V_11 -> V_111 . V_114 [ 0 ] = V_109 & 0x000000ff ;
V_11 -> V_111 . V_114 [ 1 ] = ( V_109 & 0x0000ff00 ) >> 8 ;
V_11 -> V_111 . V_114 [ 2 ] = ( V_109 & 0x00ff0000 ) >> 16 ;
V_11 -> V_111 . V_114 [ 3 ] = ( V_109 & 0xff000000 ) >> 24 ;
V_11 -> V_115 = F_24 ( V_89 -> V_116 ) ;
V_63 -> V_83 = V_89 -> V_110 . V_109 ;
V_63 -> V_117 = F_24 ( V_89 -> V_116 ) ;
V_63 -> V_112 = V_113 ;
} else {
V_11 -> V_111 . V_112 = V_118 ;
memcpy ( & V_11 -> V_111 . V_114 ,
& V_91 -> V_119 . V_120 . V_121 , 16 ) ;
V_11 -> V_115 = F_24 ( V_91 -> V_122 ) ;
V_63 -> V_117 = F_24 ( V_91 -> V_122 ) ;
memcpy ( & V_63 -> V_123 ,
& V_91 -> V_119 . V_120 . V_121 , 16 ) ;
V_63 -> V_112 = V_118 ;
}
V_11 -> V_64 = V_64 ;
V_13 = V_2 -> V_124 ++ ;
if ( V_2 -> V_124 == V_2 -> V_125 )
V_2 -> V_124 = 0 ;
V_11 -> V_126 = V_87 -> V_127 [ V_13 ] . V_80 ;
F_14 ( V_2 , V_128 , V_56 ,
L_3 , V_13 , V_11 -> V_126 ) ;
V_11 -> V_129 = V_93 ;
V_11 -> V_130 = V_93 ;
V_11 -> V_131 = V_94 ;
V_11 -> V_132 = 1 ;
V_11 -> V_133 . V_134 = V_97 -> V_134 ;
V_11 -> V_133 . V_135 = V_97 -> V_135 ;
V_100 -> V_58 = F_8 ( F_16 ( V_29 -> V_59 ) ) ;
V_100 -> V_60 = F_8 ( V_29 -> V_59 & 0xFFFFFFFF ) ;
V_100 -> V_61 = F_8 ( V_29 -> V_41 ) ;
if ( ! F_25 ( V_2 ) ) {
V_11 -> V_15 . V_136 = V_137 ;
V_11 -> V_138 = 0x8000 ;
V_11 -> V_139 = 2 ;
}
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_28 * V_29 , void * V_140 ,
int V_141 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_30 * V_100 ;
unsigned int V_12 ;
int V_142 = 0 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
V_142 = - V_143 ;
goto V_144;
}
V_100 = F_15 ( V_9 ) ;
F_6 ( V_9 , V_29 -> V_41 , false , 1 ) ;
V_100 -> V_58 = F_8 ( F_16 ( V_29 -> V_59 ) ) ;
V_100 -> V_60 = F_8 ( F_27 ( V_29 -> V_59 ) ) ;
V_100 -> V_61 = F_8 ( V_29 -> V_41 ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
V_142 = F_28 ( V_2 , V_12 , NULL , V_29 ) ;
if ( V_140 )
memcpy ( V_140 , V_29 -> V_36 , V_141 ) ;
if ( V_142 ) {
if ( V_142 == - V_145 )
return V_142 ;
F_14 ( V_2 , V_55 ,
V_56 | V_146 ,
L_4 ) ;
if ( V_142 != - V_147 )
goto V_144;
else
return V_142 ;
}
V_144:
F_29 ( V_7 -> V_148 , V_29 -> V_41 ,
V_29 -> V_36 , V_29 -> V_59 ) ;
return V_142 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_28 * V_149 ,
int V_150 , int V_41 )
{
V_149 -> V_36 = F_31 ( V_2 -> V_7 . V_148 , V_41 , & V_149 -> V_59 ) ;
if ( ! V_149 -> V_36 ) {
F_14 ( V_2 , V_104 , V_56 ,
L_5 ) ;
return - V_143 ;
}
V_149 -> V_41 = V_41 ;
F_7 ( V_149 -> V_36 , V_48 , V_150 , V_41 ) ;
F_14 ( V_2 , V_128 , V_56 ,
L_6 ,
V_150 , V_41 ) ;
return 0 ;
}
unsigned int F_32 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_151 * V_11 ;
struct V_151 * V_152 ;
unsigned int V_12 ;
int V_153 = 0 ;
if ( F_12 ( & V_7 -> V_14 ) )
return - V_154 ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return - V_143 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_48 ,
V_155 ,
sizeof( * V_11 ) ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
V_153 = F_28 ( V_2 , V_12 , & V_9 , NULL ) ;
if ( V_153 ) {
F_14 ( V_2 , V_55 , V_56 ,
L_7 , V_156 , V_153 ) ;
return - V_147 ;
}
V_152 = F_5 ( V_9 ) ;
V_2 -> V_157 = V_152 -> V_158 [ 0 ] ;
return V_153 ;
}
static inline bool F_33 ( T_2 * V_159 , T_3 V_112 )
{
T_3 V_61 ;
V_61 = ( V_112 < V_118 ) ? V_160 : V_161 ;
while ( V_61 && ! V_159 [ V_61 - 1 ] )
V_61 -- ;
return ( V_61 == 0 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
T_3 V_162 , T_3 V_112 , T_2 * V_163 )
{
struct V_164 * V_11 ;
struct V_28 V_29 ;
int V_165 ;
V_165 = F_30 ( V_2 , & V_29 ,
V_166 ,
sizeof( * V_11 ) ) ;
if ( V_165 )
return V_165 ;
V_11 = V_29 . V_36 ;
V_11 -> V_162 = V_162 ;
V_11 -> V_167 . V_112 = V_112 ;
memcpy ( V_11 -> V_167 . V_114 , V_163 ,
( V_112 < V_118 ) ? V_160 : V_161 ) ;
return F_26 ( V_2 , & V_29 , NULL , 0 ) ;
}
int F_35 ( struct V_1 * V_2 , T_3 V_112 , T_2 * V_163 )
{
struct V_168 V_169 ;
int V_165 ;
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
V_165 = F_36 ( V_2 , V_112 , & V_169 ) ;
if ( V_165 ) {
F_14 ( V_2 , V_55 , V_56 ,
L_8 ) ;
return V_165 ;
}
if ( ! F_33 ( V_169 . V_167 . V_114 , V_112 ) ) {
V_165 = F_34 ( V_2 , V_170 , V_112 ,
V_169 . V_167 . V_114 ) ;
if ( V_165 ) {
F_14 ( V_2 , V_55 , V_56 ,
L_9 ) ;
return V_165 ;
}
}
V_165 = F_34 ( V_2 , V_171 , V_112 , V_163 ) ;
if ( V_165 )
F_14 ( V_2 , V_55 , V_56 ,
L_10 ) ;
return V_165 ;
}
int F_36 ( struct V_1 * V_2 , T_3 V_112 ,
struct V_168 * V_172 )
{
struct V_173 * V_11 ;
struct V_28 V_29 ;
int V_142 ;
V_142 = F_30 ( V_2 , & V_29 ,
V_174 ,
sizeof( * V_172 ) ) ;
if ( V_142 )
return V_142 ;
V_11 = V_29 . V_36 ;
V_11 -> V_112 = V_112 ;
return F_26 ( V_2 , & V_29 , V_172 ,
sizeof( * V_172 ) ) ;
}
static int
F_37 ( struct V_1 * V_2 ,
struct V_175 * V_176 )
{
struct V_177 * V_11 ;
struct V_28 V_29 ;
int V_142 ;
V_142 = F_30 ( V_2 , & V_29 ,
V_178 ,
sizeof( * V_11 ) ) ;
if ( V_142 )
return V_142 ;
V_11 = V_29 . V_36 ;
V_11 -> V_179 . V_180 = 1 ;
V_11 -> V_179 . V_181 . V_162 = V_170 ;
V_11 -> V_179 . V_181 . V_182 =
V_2 -> V_157 ;
V_11 -> V_179 . V_181 . V_167 . V_183 =
sizeof( struct V_184 ) ;
V_11 -> V_179 . V_181 . V_167 . V_112 = V_176 -> V_167 . V_112 ;
memcpy ( V_11 -> V_179 . V_181 . V_167 . V_114 ,
V_176 -> V_167 . V_114 ,
sizeof( V_176 -> V_167 . V_114 ) ) ;
memcpy ( V_11 -> V_179 . V_181 . V_167 . V_185 ,
V_176 -> V_167 . V_185 ,
sizeof( V_176 -> V_167 . V_185 ) ) ;
V_142 = F_26 ( V_2 , & V_29 , NULL , 0 ) ;
if ( V_142 < 0 || V_11 -> V_179 . V_181 . V_153 ) {
F_14 ( V_2 , V_128 , V_56 ,
L_11 ,
V_142 , V_11 -> V_179 . V_181 . V_153 ) ;
}
return V_142 ;
}
static int
F_38 ( struct V_1 * V_2 , T_2 * V_159 ,
T_2 * V_186 , T_3 V_112 )
{
struct V_177 * V_11 ;
struct V_28 V_29 ;
T_4 V_187 ;
int V_142 ;
V_142 = F_30 ( V_2 , & V_29 ,
V_178 ,
sizeof( * V_11 ) ) ;
if ( V_142 )
return V_142 ;
V_11 = V_29 . V_36 ;
V_11 -> V_179 . V_180 = 1 ;
V_11 -> V_179 . V_181 . V_162 = V_171 ;
V_11 -> V_179 . V_181 . V_182 =
V_2 -> V_157 ;
V_11 -> V_179 . V_181 . V_167 . V_183 =
sizeof( struct V_184 ) ;
V_11 -> V_179 . V_181 . V_167 . V_112 = V_112 ;
V_187 = ( V_112 < V_118 ) ? V_160 : V_161 ;
memcpy ( V_11 -> V_179 . V_181 . V_167 . V_114 , V_159 , V_187 ) ;
if ( V_186 )
memcpy ( V_11 -> V_179 . V_181 . V_167 . V_185 ,
V_186 , V_187 ) ;
V_142 = F_26 ( V_2 , & V_29 , NULL , 0 ) ;
if ( V_142 < 0 || V_11 -> V_179 . V_181 . V_153 ) {
F_39 ( V_2 , V_104 ,
L_12 ,
V_142 , V_11 -> V_179 . V_181 . V_153 ) ;
if ( V_11 -> V_179 . V_181 . V_153 )
V_142 = - V_105 ;
}
return V_142 ;
}
int F_40 ( struct V_1 * V_2 , T_3 V_112 ,
T_2 * V_159 , T_2 * V_186 )
{
struct V_175 * V_176 ;
struct V_188 * V_189 ;
struct V_28 V_29 ;
int V_142 ;
V_142 = F_41 ( V_2 , V_112 , & V_176 ) ;
if ( V_142 )
return V_142 ;
if ( V_176 -> V_190 ) {
V_142 = F_30 ( V_2 , & V_29 ,
V_191 ,
sizeof( * V_189 ) ) ;
if ( V_142 )
goto exit;
V_189 = V_29 . V_36 ;
V_189 -> V_182 = V_2 -> V_157 ;
V_189 -> V_112 = V_112 ;
V_142 = F_26 ( V_2 , & V_29 , NULL , 0 ) ;
if ( V_142 < 0 ) {
F_14 ( V_2 , V_55 , V_56 ,
L_13 ,
V_142 ) ;
goto exit;
}
}
if ( ! F_33 ( V_176 -> V_167 . V_114 , V_112 ) ) {
V_142 = F_37 ( V_2 , V_176 ) ;
if ( V_142 )
goto exit;
}
if ( V_159 )
V_142 = F_38 ( V_2 , V_159 , V_186 , V_112 ) ;
exit:
F_42 ( V_176 ) ;
return V_142 ;
}
int F_43 ( struct V_1 * V_2 , T_3 V_112 )
{
struct V_168 V_169 ;
struct V_175 * V_176 ;
struct V_192 * V_193 ;
struct V_28 V_29 ;
T_2 * V_163 ;
int V_142 ;
V_142 = F_41 ( V_2 , V_112 , & V_176 ) ;
if ( V_142 )
return V_142 ;
if ( V_176 -> V_190 ) {
F_14 ( V_2 , V_55 , V_56 ,
L_14 ) ;
goto exit;
}
if ( ! F_33 ( V_176 -> V_167 . V_114 , V_112 ) ) {
V_142 = F_37 ( V_2 , V_176 ) ;
if ( V_142 )
goto exit;
}
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
V_142 = F_36 ( V_2 , V_176 -> V_167 . V_112 , & V_169 ) ;
if ( V_142 ) {
F_14 ( V_2 , V_55 , V_56 ,
L_8 ) ;
goto exit;
}
V_163 = ( T_2 * ) & V_169 . V_167 . V_114 ;
if ( ! F_33 ( V_163 , V_176 -> V_167 . V_112 ) ) {
V_142 = F_34 ( V_2 , V_170 ,
V_176 -> V_167 . V_112 , V_163 ) ;
if ( V_142 ) {
F_14 ( V_2 , V_55 , V_56 ,
L_9 ) ;
goto exit;
}
}
V_142 = F_30 ( V_2 , & V_29 ,
V_194 ,
sizeof( * V_193 ) ) ;
if ( V_142 )
goto exit;
V_193 = V_29 . V_36 ;
V_193 -> V_195 = 1 ;
V_193 -> V_196 = 1 ;
V_193 -> V_182 = V_2 -> V_157 ;
V_193 -> V_112 = V_112 ;
V_142 = F_26 ( V_2 , & V_29 , NULL , 0 ) ;
exit:
F_42 ( V_176 ) ;
return V_142 ;
}
int F_44 ( struct V_1 * V_2 , T_5 V_197 )
{
int V_142 ;
unsigned int V_12 ;
V_12 = F_45 ( V_2 , V_197 ) ;
if ( ! V_12 ) {
F_14 ( V_2 , V_104 ,
( V_56 | V_146 ) ,
L_15 ) ;
return - V_147 ;
}
V_142 = F_28 ( V_2 , V_12 , NULL , NULL ) ;
if ( V_142 ) {
F_14 ( V_2 , V_104 ,
( V_56 | V_146 ) ,
L_16 ) ;
return V_142 ;
}
return V_142 ;
}
int F_41 ( struct V_1 * V_2 , int V_112 ,
struct V_175 * * V_176 )
{
struct V_198 * V_11 ;
struct V_28 V_29 ;
T_4 V_199 = sizeof( struct V_175 ) ;
int V_142 ;
V_142 = F_32 ( V_2 ) ;
if ( V_142 )
return V_142 ;
do {
V_142 = F_30 ( V_2 , & V_29 ,
V_200 ,
V_199 ) ;
if ( V_142 )
return V_142 ;
V_11 = V_29 . V_36 ;
V_11 -> V_182 = V_2 -> V_157 ;
V_11 -> V_112 = V_112 ;
* V_176 = F_46 ( V_199 , V_201 ) ;
if ( ! * V_176 ) {
F_14 ( V_2 , V_104 ,
V_202 | V_56 ,
L_17 ) ;
F_29 ( V_2 -> V_7 . V_148 ,
V_29 . V_41 ,
V_29 . V_36 ,
V_29 . V_59 ) ;
return - V_143 ;
}
V_142 = F_26 ( V_2 , & V_29 , * V_176 ,
V_199 ) ;
if ( V_142 == - V_145 ) {
V_199 = ( (struct V_203 * )
V_29 . V_36 ) -> V_204 ;
V_199 += sizeof( struct V_205 ) ;
F_29 ( V_2 -> V_7 . V_148 , V_29 . V_41 ,
V_29 . V_36 ,
V_29 . V_59 ) ;
F_42 ( * V_176 ) ;
} else
break;
} while ( true );
return V_142 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_206 * V_207 )
{
struct V_28 V_29 ;
int V_142 ;
V_142 = F_30 ( V_2 , & V_29 ,
V_208 ,
sizeof( * V_207 ) ) ;
if ( V_142 )
return V_142 ;
return F_26 ( V_2 , & V_29 , V_207 , sizeof( * V_207 ) ) ;
}
unsigned int F_48 ( struct V_1 * V_2 )
{
unsigned int V_12 ;
struct V_8 * V_9 ;
struct V_209 * V_11 ;
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
F_7 ( & V_11 -> V_15 , V_68 ,
V_210 ,
sizeof( * V_11 ) ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
static void F_49 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
struct V_211 * V_212 ;
struct V_213 * V_214 ;
struct V_215 * V_216 ;
struct V_8 * V_9 ;
struct V_217 * V_218 ;
int V_219 , V_153 ;
if ( ! F_50 ( V_220 , & V_2 -> V_221 ) ) {
F_39 ( V_2 , V_104 ,
L_18 ,
V_156 , V_2 -> V_221 ) ;
return;
}
if ( V_2 -> V_217 . V_12 != V_12 ) {
F_39 ( V_2 , V_104 ,
L_19 ,
V_156 , V_12 , V_2 -> V_217 . V_12 ) ;
return;
}
V_218 = & V_2 -> V_217 ;
V_219 = 1 ;
V_153 = 0 ;
switch ( V_218 -> V_162 ) {
case V_222 :
V_153 = F_51 ( V_2 , V_12 , NULL , NULL ) ;
if ( ! V_153 )
V_218 -> V_162 = V_223 ;
else
V_218 -> V_224 -- ;
break;
case V_223 :
V_153 = F_51 ( V_2 , V_12 , & V_9 , NULL ) ;
if ( ! V_153 ) {
V_212 = F_5 ( V_9 ) ;
V_218 -> V_225 = V_212 -> V_226 ;
}
if ( V_218 -> V_225 == V_227 ) {
V_218 -> V_162 = V_222 ;
V_218 -> V_224 -- ;
} else {
V_218 -> V_162 = V_228 ;
}
break;
case V_228 :
V_153 = F_51 ( V_2 , V_12 , NULL ,
& V_218 -> V_29 ) ;
if ( ! V_153 ) {
V_216 = V_218 -> V_29 . V_36 ;
memcpy ( & V_218 -> V_229 , & V_216 -> V_230 ,
sizeof( struct V_231 ) ) ;
V_218 -> V_162 = V_232 ;
} else {
F_39 ( V_2 , V_104 ,
L_20 ,
V_153 ) ;
V_219 = 0 ;
}
F_29 ( V_2 -> V_7 . V_148 , V_218 -> V_29 . V_41 ,
V_218 -> V_29 . V_36 , V_218 -> V_29 . V_59 ) ;
V_218 -> V_29 . V_36 = NULL ;
break;
case V_232 :
V_153 = F_51 ( V_2 , V_12 , & V_9 , NULL ) ;
if ( ! V_153 ) {
V_214 = F_5 ( V_9 ) ;
if ( V_214 -> V_233 != V_234 ) {
F_39 ( V_2 , V_104 ,
L_21 ,
V_214 -> V_233 ) ;
}
}
V_218 -> V_162 = V_235 ;
break;
default:
break;
}
V_218 -> V_12 = 0 ;
if ( ! V_218 -> V_224 ) {
V_219 = 0 ;
F_39 ( V_2 , V_104 ,
L_22 ,
V_153 , V_218 -> V_162 ) ;
}
if ( ! V_219 ) {
F_52 ( V_220 , & V_2 -> V_221 ) ;
return;
}
F_53 ( & V_2 -> V_219 ) ;
}
unsigned int F_54 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_236 * V_11 ;
unsigned int V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_68 ,
V_237 ,
sizeof( struct V_236 ) ) ;
V_11 -> V_70 = V_2 -> V_217 . V_229 . V_70 ;
V_2 -> V_217 . V_12 = V_12 ;
F_9 ( V_238 , & V_7 -> V_24 [ V_12 ] . V_25 ) ;
V_7 -> V_24 [ V_12 ] . V_239 = F_49 ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_55 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_240 * V_11 ;
unsigned int V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_68 ,
V_241 ,
sizeof( struct V_242 ) ) ;
V_11 -> V_243 = V_244 ;
V_11 -> V_70 = V_227 ;
V_2 -> V_217 . V_12 = V_12 ;
F_9 ( V_238 , & V_7 -> V_24 [ V_12 ] . V_25 ) ;
V_7 -> V_24 [ V_12 ] . V_239 = F_49 ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_56 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_245 * V_11 ;
struct V_28 * V_29 ;
struct V_8 * V_9 ;
struct V_30 * V_100 ;
unsigned int V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_29 = & V_2 -> V_217 . V_29 ;
V_29 -> V_41 = sizeof( struct V_215 ) ;
V_29 -> V_36 = F_57 ( V_2 -> V_7 . V_148 ,
V_29 -> V_41 ,
& V_29 -> V_59 ) ;
if ( ! V_29 -> V_36 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = V_29 -> V_36 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_100 = F_15 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , false , 1 ) ;
F_7 ( & V_11 -> V_15 , V_68 ,
V_246 ,
sizeof( struct V_215 ) ) ;
V_11 -> V_70 = V_2 -> V_217 . V_225 ;
V_100 -> V_58 = F_8 ( F_16 ( V_29 -> V_59 ) ) ;
V_100 -> V_60 = F_8 ( V_29 -> V_59 & 0xFFFFFFFF ) ;
V_100 -> V_61 = F_8 ( V_29 -> V_41 ) ;
V_2 -> V_217 . V_12 = V_12 ;
F_9 ( V_238 , & V_7 -> V_24 [ V_12 ] . V_25 ) ;
V_7 -> V_24 [ V_12 ] . V_239 = F_49 ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_58 ( struct V_1 * V_2 , int V_247 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_248 * V_11 ;
unsigned int V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_68 ,
V_249 ,
sizeof( struct V_211 ) ) ;
if ( V_247 ) {
V_2 -> V_217 . V_12 = V_12 ;
F_9 ( V_238 , & V_7 -> V_24 [ V_12 ] . V_25 ) ;
V_7 -> V_24 [ V_12 ] . V_239 = F_49 ;
}
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
int F_59 ( struct V_1 * V_2 , unsigned int * V_225 )
{
struct V_211 * V_212 ;
struct V_8 * V_9 ;
unsigned int V_12 ;
int V_142 ;
* V_225 = V_227 ;
V_12 = F_58 ( V_2 , 0 ) ;
if ( ! V_12 ) {
F_14 ( V_2 , V_104 ,
V_56 | V_202 ,
L_23 ) ;
return - V_145 ;
}
V_142 = F_28 ( V_2 , V_12 , & V_9 , NULL ) ;
if ( V_142 ) {
F_14 ( V_2 , V_104 ,
V_202 | V_56 ,
L_24 ) ;
return - V_147 ;
}
V_212 = F_5 ( V_9 ) ;
if ( ! V_212 -> V_250 ) {
F_39 ( V_2 , V_128 ,
L_25 ) ;
return - V_251 ;
}
* V_225 = V_212 -> V_226 ;
return 1 ;
}
T_6
F_60 ( struct V_252 * V_253 , struct V_254 * V_255 ,
char * V_256 )
{
return snprintf ( V_256 , V_257 , V_258 L_26 ) ;
}
T_6
F_61 ( struct V_252 * V_253 , struct V_254 * V_255 ,
char * V_256 )
{
struct V_259 * V_260 = F_62 ( V_253 ) ;
struct V_1 * V_2 = F_63 ( V_260 ) ;
return snprintf ( V_256 , V_257 , L_27 , V_2 -> V_261 ) ;
}
T_6
F_64 ( struct V_252 * V_253 , struct V_254 * V_255 ,
char * V_256 )
{
struct V_259 * V_260 = F_62 ( V_253 ) ;
struct V_1 * V_2 = F_63 ( V_260 ) ;
T_5 V_262 = 0 , V_98 , V_61 = 0 , V_263 = 0 ;
for ( V_98 = 0 ; V_98 < V_264 ; V_98 ++ ) {
if ( F_50 ( V_98 , ( void * ) & V_2 -> V_265 . V_266 ) ) {
V_262 = F_65 ( V_2 , V_98 ) ;
V_263 = F_66 ( V_2 , V_98 ) ;
V_61 += snprintf ( V_256 + V_61 , V_257 - V_61 ,
L_28 , V_98 ,
( V_263 - V_262 ) ) ;
} else
V_61 += snprintf ( V_256 + V_61 , V_257 - V_61 ,
L_28 , V_98 , 0 ) ;
}
return V_61 ;
}
T_6
F_67 ( struct V_252 * V_253 , struct V_254 * V_255 ,
char * V_256 )
{
struct V_259 * V_260 = F_62 ( V_253 ) ;
struct V_1 * V_2 = F_63 ( V_260 ) ;
T_5 V_98 , V_61 = 0 ;
for ( V_98 = 0 ; V_98 < V_264 ; V_98 ++ ) {
if ( F_50 ( V_98 , ( void * ) & V_2 -> V_265 . V_266 ) )
V_61 += snprintf ( V_256 + V_61 , V_257 - V_61 ,
L_28 , V_98 ,
F_65 ( V_2 , V_98 ) ) ;
else
V_61 += snprintf ( V_256 + V_61 , V_257 - V_61 ,
L_28 , V_98 , 0 ) ;
}
return V_61 ;
}
T_6
F_68 ( struct V_252 * V_253 , struct V_254 * V_255 ,
char * V_256 )
{
T_5 V_267 = 0 ;
struct V_259 * V_260 = F_62 ( V_253 ) ;
struct V_1 * V_2 = F_63 ( V_260 ) ;
V_267 = V_2 -> V_268 -> V_252 ;
switch ( V_267 ) {
case V_269 :
case V_270 :
case V_271 :
return snprintf ( V_256 , V_257 ,
L_29 ) ;
break;
case V_272 :
case V_273 :
return snprintf ( V_256 , V_257 , L_30 ) ;
break;
case V_274 :
return snprintf ( V_256 , V_257 , L_31 ) ;
break;
default:
return snprintf ( V_256 , V_257 ,
L_32 , V_267 ) ;
break;
}
}
T_6
F_69 ( struct V_252 * V_253 , struct V_254 * V_255 ,
char * V_256 )
{
struct V_259 * V_260 = F_62 ( V_253 ) ;
struct V_1 * V_2 = F_63 ( V_260 ) ;
return snprintf ( V_256 , V_257 , L_33 ,
V_2 -> V_265 . V_275 ) ;
}
void F_70 ( struct V_276 * V_277 ,
struct V_278 * V_279 ,
struct V_280 * V_281 ,
struct V_282 * V_283 )
{
struct V_284 * V_285 = V_279 -> V_285 ;
F_71 ( struct V_286 ,
V_287 , V_285 ,
V_277 -> V_288 [ F_72 ( struct V_289 ,
V_287 ) / 32 ] ) ;
F_71 ( struct V_286 , type , V_285 ,
V_290 ) ;
F_71 ( struct V_286 ,
V_291 ,
V_285 ,
V_277 -> V_288 [ F_72 ( struct V_289 ,
V_291 ) / 32 ] ) ;
F_71 ( struct V_286 , V_292 , V_285 ,
( V_277 -> V_288 [ F_72 ( struct V_289 ,
V_292 ) / 32 ] & V_293 ) ) ;
F_71 ( struct V_286 , V_294 , V_285 ,
( V_277 -> V_288 [ F_72 ( struct V_289 ,
V_294 ) / 32 ] & V_295 ) >> 2 ) ;
F_71 ( struct V_286 , V_296 , V_285 ,
( V_277 -> V_288 [ F_72 ( struct V_289 ,
V_296 ) / 32 ] & V_297 ) >> 3 ) ;
F_71 ( struct V_286 , V_298 , V_285 ,
( V_277 -> V_288 [ F_72 ( struct V_289 ,
V_298 ) / 32 ] & V_299 ) >> 4 ) ;
F_71 ( struct V_286 , V_300 , V_285 ,
( V_277 -> V_288 [ F_72 ( struct V_289 ,
V_300 ) / 32 ] & V_301 ) >> 5 ) ;
F_71 ( struct V_286 , V_302 ,
V_285 ,
( V_277 -> V_288 [ F_72 ( struct V_289 ,
V_303 ) / 32 ] + 1 ) ) ;
F_71 ( struct V_286 , V_304 ,
V_285 , V_279 -> V_305 ) ;
F_71 ( struct V_286 ,
V_306 , V_285 , V_277 -> V_288 [ F_72
( struct V_289 ,
V_306 ) / 32 ] ) ;
F_71 ( struct V_286 , V_307 ,
V_285 , V_279 -> V_305 ) ;
if ( V_283 -> V_308 )
F_71 ( struct V_286 ,
V_307 ,
V_283 -> V_308 ,
V_279 -> V_305 ) ;
V_283 -> V_308 = V_285 ;
F_71 ( struct V_286 ,
V_309 , V_285 , 0 ) ;
F_71 ( struct V_286 , V_310 ,
V_285 , 1 ) ;
F_71 ( struct V_286 , V_311 ,
V_285 , 0 ) ;
F_71 ( struct V_286 , V_312 , V_285 ,
0 ) ;
V_281 += V_313 ;
F_71 ( struct V_286 ,
V_314 , V_285 ,
V_281 -> V_315 [ 0 ] . V_316 . V_317 . V_318 . V_319 ) ;
F_71 ( struct V_286 ,
V_320 , V_285 ,
V_281 -> V_315 [ 0 ] . V_316 . V_317 . V_318 . V_321 ) ;
}
void F_73 ( struct V_276 * V_277 ,
struct V_278 * V_279 ,
struct V_282 * V_283 )
{
struct V_284 * V_285 = V_279 -> V_285 ;
F_71 ( struct V_322 ,
V_306 , V_285 , V_277 -> V_288 [ F_72
( struct V_289 ,
V_306 ) / 32 ] ) ;
F_71 ( struct V_322 ,
type , V_285 ,
V_290 ) ;
F_71 ( struct V_322 ,
V_307 ,
V_285 , V_279 -> V_305 ) ;
if ( V_283 -> V_308 )
F_71 ( struct V_322 ,
V_307 ,
V_283 -> V_308 ,
V_279 -> V_305 ) ;
V_283 -> V_308 = V_285 ;
F_71 ( struct V_322 , V_304 ,
V_285 , V_279 -> V_305 ) ;
F_71 ( struct V_322 ,
V_287 , V_285 ,
V_277 -> V_288 [ F_72 ( struct V_289 ,
V_287 ) / 32 ] ) ;
F_71 ( struct V_322 ,
V_291 , V_285 ,
V_277 -> V_288 [ F_72 ( struct V_289 ,
V_291 ) / 32 ] ) ;
F_71 ( struct V_322 ,
V_323 , V_285 ,
V_277 -> V_288 [ F_72 ( struct V_289 ,
V_324 ) / 32 ] ) ;
F_71 ( struct V_322 ,
V_325 , V_285 , V_326 ) ;
F_71 ( struct V_322 , V_292 , V_285 ,
( V_277 -> V_288 [ F_72 ( struct V_289 ,
V_292 ) / 32 ] & V_293 ) ) ;
F_71 ( struct V_322 , V_294 , V_285 ,
( V_277 -> V_288 [ F_72 ( struct V_289 ,
V_294 ) / 32 ] & V_295 ) >> 2 ) ;
F_71 ( struct V_322 , V_296 , V_285 ,
( V_277 -> V_288 [ F_72 ( struct V_289 ,
V_296 ) / 32 ] & V_297 ) >> 3 ) ;
F_71 ( struct V_322 ,
V_298 , V_285 ,
( V_277 -> V_288 [ F_72 ( struct V_289 ,
V_298 ) / 32 ] & V_299 ) >> 4 ) ;
F_71 ( struct V_322 , V_300 , V_285 ,
( V_277 -> V_288 [ F_72 ( struct V_289 ,
V_300 ) / 32 ] & V_301 ) >> 5 ) ;
F_71 ( struct V_322 ,
V_327 ,
V_285 ,
( V_277 -> V_288 [ F_72 ( struct V_289 ,
V_327 ) / 32 ] &
V_328 ) >> 6 ) ;
F_71 ( struct V_322 ,
V_329 ,
V_285 ,
( V_277 -> V_288 [ F_72 ( struct V_289 ,
V_329 ) / 32 ] &
V_330 ) >> 7 ) ;
F_71 ( struct V_322 , V_331 ,
V_285 ,
( V_277 -> V_288 [ F_72 ( struct V_289 ,
V_331 ) / 32 ] &
V_332 ) >> 8 ) ;
F_71 ( struct V_322 , V_302 ,
V_285 ,
( V_277 -> V_288 [ F_72 ( struct V_289 ,
V_303 ) / 32 ] + 1 ) ) ;
}
int F_74 ( struct V_1 * V_2 ,
struct V_333 * V_334 ,
unsigned int V_335 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_336 * V_11 ;
struct V_28 V_29 ;
struct V_8 * V_9 ;
unsigned int V_13 , V_12 ;
struct V_30 * V_100 ;
int V_142 ;
if ( ! V_335 || V_335 > V_337 )
return - V_105 ;
V_29 . V_41 = sizeof( union V_338 ) ;
V_29 . V_36 = F_31 ( V_2 -> V_7 . V_148 ,
V_29 . V_41 ,
& V_29 . V_59 ) ;
if ( ! V_29 . V_36 ) {
F_14 ( V_2 , V_104 , V_339 ,
L_34 ) ;
return - V_143 ;
}
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
F_29 ( V_2 -> V_7 . V_148 , V_29 . V_41 ,
V_29 . V_36 , V_29 . V_59 ) ;
return - V_143 ;
}
V_11 = V_29 . V_36 ;
F_6 ( V_9 , V_29 . V_41 , false , 1 ) ;
F_7 ( & V_11 -> V_15 , V_48 ,
V_340 ,
sizeof( * V_11 ) ) ;
V_11 -> V_341 = 0 ;
V_11 -> V_72 = V_342 ;
for ( V_13 = 0 ; V_13 < V_335 ; V_13 ++ ) {
V_11 -> V_343 [ V_13 ] . V_344 = V_334 [ V_13 ] . V_344 ;
V_11 -> V_343 [ V_13 ] . V_64 = V_334 [ V_13 ] . V_64 ;
V_11 -> V_345 ++ ;
}
V_100 = F_15 ( V_9 ) ;
V_100 -> V_58 = F_8 ( F_16 ( V_29 . V_59 ) ) ;
V_100 -> V_60 = F_8 ( F_27 ( V_29 . V_59 ) ) ;
V_100 -> V_61 = F_8 ( V_29 . V_41 ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
V_142 = F_28 ( V_2 , V_12 , NULL , & V_29 ) ;
if ( V_142 != - V_147 )
F_29 ( V_2 -> V_7 . V_148 , V_29 . V_41 ,
V_29 . V_36 , V_29 . V_59 ) ;
return V_142 ;
}

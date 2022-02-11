static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_5 -> V_6 == V_7 )
return V_4 -> V_8 & V_9 ;
else
return 1 ;
}
inline void F_2 ( struct V_10 * V_11 )
{
F_3 ( V_11 -> V_12 , V_11 -> V_13 ) ;
}
int F_4 ( struct V_14 * V_15 , int V_16 )
{
int V_17 = sizeof( struct V_18 ) * V_16 ;
V_15 -> V_19 = F_5 ( V_17 , V_20 ) ;
return V_15 -> V_19 == NULL ;
}
void F_6 ( struct V_14 * V_15 )
{
if ( V_15 -> V_19 != NULL )
F_7 ( V_15 -> V_19 ) ;
V_15 -> V_19 = NULL ;
}
static int
F_8 ( struct V_1 * V_2 )
{
T_2 V_21 [ V_22 ] ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_25 * V_5 = V_2 -> V_5 ;
if ( F_9 ( V_2 , V_21 ) != 0 )
return - V_26 ;
memcpy ( V_24 -> V_27 , V_21 , V_22 ) ;
memcpy ( V_2 -> V_21 , V_24 -> V_27 , V_24 -> V_28 ) ;
if ( ! F_10 ( V_24 -> V_27 ) )
F_11 ( & V_5 -> V_29 , L_1 ,
V_24 -> V_27 ) ;
return 0 ;
}
static int F_12 ( struct V_23 * V_24 , void * V_30 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
struct V_31 * V_32 = V_30 ;
if ( ( V_2 -> V_33 & V_34 ) )
return - V_35 ;
if ( ! F_10 ( V_32 -> V_36 ) )
return - V_37 ;
if ( F_14 ( V_38 , & V_2 -> V_39 ) ) {
F_15 ( V_24 ) ;
F_16 ( V_2 ) ;
}
memcpy ( V_2 -> V_21 , V_32 -> V_36 , V_24 -> V_28 ) ;
memcpy ( V_24 -> V_27 , V_32 -> V_36 , V_24 -> V_28 ) ;
F_17 ( V_2 -> V_24 ) ;
if ( F_14 ( V_38 , & V_2 -> V_39 ) ) {
F_18 ( V_24 ) ;
F_19 ( V_2 ) ;
}
return 0 ;
}
static int F_20 ( struct V_40 * V_41 , struct V_42 * V_43 [] ,
struct V_23 * V_24 , const unsigned char * V_32 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
int V_44 = - V_35 ;
if ( ! V_2 -> V_45 ) {
F_21 ( L_2 ,
V_46 ) ;
return V_44 ;
}
if ( V_2 -> V_33 & V_47 ) {
if ( F_22 ( V_32 ) )
V_44 = F_23 ( V_2 , V_32 ) ;
else if ( F_24 ( V_32 ) )
V_44 = F_25 ( V_24 , V_32 ) ;
else
V_44 = - V_37 ;
}
return V_44 ;
}
static int F_26 ( struct V_40 * V_41 , struct V_42 * V_43 [] ,
struct V_23 * V_24 ,
const unsigned char * V_32 , T_3 V_33 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
int V_44 = 0 ;
if ( ! V_2 -> V_45 ) {
F_21 ( L_2 ,
V_46 ) ;
return - V_35 ;
}
if ( ! ( V_2 -> V_33 & V_47 ) ) {
F_21 ( L_3 , V_46 ) ;
return - V_35 ;
}
if ( F_27 ( V_32 , V_2 -> V_21 ) )
return V_44 ;
if ( F_22 ( V_32 ) )
V_44 = F_28 ( V_2 , V_32 ) ;
else if ( F_24 ( V_32 ) )
V_44 = F_29 ( V_24 , V_32 ) ;
else
V_44 = - V_37 ;
return V_44 ;
}
static int F_30 ( struct V_48 * V_49 , struct V_50 * V_51 ,
struct V_23 * V_24 , int V_52 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
if ( ! V_2 -> V_45 ) {
F_21 ( L_2 ,
V_46 ) ;
return - V_35 ;
}
if ( V_2 -> V_33 & V_47 )
V_52 = F_31 ( V_49 , V_51 , V_24 , V_52 ) ;
return V_52 ;
}
static void F_32 ( struct V_1 * V_2 )
{
while ( F_33 ( V_53 , & V_2 -> V_39 ) )
F_34 ( 10000 , 11000 ) ;
F_35 ( & V_2 -> V_54 ) ;
}
int F_36 ( struct V_1 * V_2 , T_1 V_55 )
{
struct V_25 * V_5 = V_2 -> V_5 ;
int V_44 = - 1 , V_56 ;
int V_57 ;
if ( ! V_2 -> V_58 ) {
V_2 -> V_58 = F_37 ( V_55 ,
sizeof( struct V_59 ) ,
V_20 ) ;
if ( ! V_2 -> V_58 )
return - V_60 ;
}
V_2 -> V_61 = 1 ;
V_2 -> V_33 &= ~ ( V_62 | V_63 ) ;
if ( V_2 -> V_4 -> V_64 ) {
V_65:
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ )
V_2 -> V_58 [ V_56 ] . V_66 = V_56 ;
V_44 = F_38 ( V_5 , V_2 -> V_58 , V_55 ) ;
if ( V_44 == 0 ) {
V_2 -> V_33 |= V_63 ;
if ( F_39 ( V_2 ) ) {
V_2 -> V_4 -> V_55 = V_55 ;
V_57 = V_2 -> V_67 ;
V_2 -> V_61 = V_55 -
V_57 - 1 ;
} else {
V_2 -> V_61 = V_55 ;
}
F_40 ( & V_5 -> V_29 , L_4 ) ;
return V_44 ;
} else if ( V_44 > 0 ) {
F_40 ( & V_5 -> V_29 ,
L_5 ,
V_55 ) ;
if ( F_39 ( V_2 ) ) {
if ( V_44 < V_68 )
return V_44 ;
V_44 -= ( V_2 -> V_67 + 1 ) ;
V_55 = F_41 ( V_44 ) ;
V_55 += ( V_2 -> V_67 + 1 ) ;
} else {
V_55 = F_41 ( V_44 ) ;
}
if ( V_55 ) {
F_40 ( & V_5 -> V_29 ,
L_6 ,
V_55 ) ;
goto V_65;
}
} else {
F_40 ( & V_5 -> V_29 ,
L_5 ,
V_55 ) ;
}
}
return V_44 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_44 = 0 ;
T_1 V_69 , V_70 ;
const struct V_71 * V_72 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_25 * V_5 = V_2 -> V_5 ;
if ( V_73 && ! F_43 ( V_5 ) ) {
V_2 -> V_33 |= V_62 ;
V_69 = V_74 [ V_2 -> V_4 -> V_75 ] ;
V_2 -> V_76 = F_44 ( V_2 -> V_4 ,
V_69 ) ;
F_40 ( & V_5 -> V_29 , L_7 ) ;
V_2 -> V_58 [ 0 ] . V_77 = V_5 -> V_78 ;
return V_44 ;
}
if ( V_73 || V_79 )
return - V_35 ;
V_72 = & V_80 [ V_2 -> V_4 -> V_75 ] ;
V_2 -> V_4 -> V_81 = V_72 -> V_81 ;
V_69 = V_72 -> V_76 ;
V_2 -> V_76 = F_44 ( V_4 , V_69 ) ;
V_70 = V_72 -> V_82 ;
V_2 -> V_82 = F_44 ( V_4 , V_70 ) ;
V_2 -> V_83 = F_44 ( V_4 , V_84 ) ;
V_2 -> V_85 = F_44 ( V_4 , V_86 ) ;
F_40 ( & V_5 -> V_29 , L_8 ) ;
V_2 -> V_58 [ 0 ] . V_77 = V_5 -> V_78 ;
return V_44 ;
}
int F_45 ( struct V_1 * V_2 , T_2 V_87 )
{
int V_55 , V_44 = 0 ;
if ( ! V_87 )
V_87 = V_88 ;
if ( V_2 -> V_4 -> V_64 )
V_55 = F_41 ( F_46 ( int , F_47 () ,
V_87 ) ) ;
else
V_55 = 1 ;
V_44 = F_36 ( V_2 , V_55 ) ;
if ( V_44 == - V_60 || ! V_44 )
return V_44 ;
V_44 = F_42 ( V_2 ) ;
if ( ! V_44 )
return V_44 ;
return - V_26 ;
}
void F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_33 & V_63 )
F_49 ( V_2 -> V_5 ) ;
if ( V_2 -> V_33 & V_62 )
F_50 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_58 ) ;
V_2 -> V_58 = NULL ;
if ( V_2 -> V_4 -> V_89 ) {
F_51 ( V_2 -> V_4 -> V_89 ) ;
V_2 -> V_4 -> V_89 = NULL ;
}
}
static void
F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 -> V_90 != NULL )
F_53 ( V_2 -> V_4 -> V_90 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_91 * V_92 ;
int V_93 ;
if ( ! ( V_2 -> V_33 & V_47 ) ) {
switch ( V_2 -> V_4 -> V_94 ) {
case V_95 :
V_2 -> V_4 -> V_96 = V_97 ;
break;
case V_98 :
V_2 -> V_4 -> V_96 = V_99 ;
break;
}
return 0 ;
}
if ( V_2 -> V_4 -> V_100 == V_101 )
return 0 ;
V_92 = F_37 ( V_102 , sizeof( * V_92 ) , V_20 ) ;
if ( ! V_92 )
return - V_60 ;
V_93 = F_55 ( V_2 , V_92 ) ;
F_7 ( V_92 ) ;
return V_93 ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_91 * V_92 ;
int V_56 , V_93 = 0 , V_103 = 0 ;
T_3 V_96 ;
T_2 V_104 ;
V_92 = F_37 ( V_102 , sizeof( * V_92 ) , V_20 ) ;
if ( ! V_92 )
return - V_60 ;
V_93 = F_55 ( V_2 , V_92 ) ;
if ( V_93 )
goto V_105;
V_96 = V_2 -> V_4 -> V_96 ;
V_2 -> V_106 = F_5 ( sizeof( struct V_107 ) *
V_96 , V_20 ) ;
if ( ! V_2 -> V_106 ) {
V_93 = - V_60 ;
goto V_105;
}
V_2 -> V_108 = F_5 ( sizeof( struct V_109 ) *
V_99 , V_20 ) ;
if ( ! V_2 -> V_108 ) {
V_93 = - V_60 ;
goto V_110;
}
for ( V_56 = 0 ; V_56 < V_102 ; V_56 ++ ) {
V_104 = V_92 [ V_56 ] . V_111 ;
if ( V_104 >= V_102 ) {
V_93 = V_112 ;
goto V_113;
}
if ( ! V_92 [ V_56 ] . V_114 ||
( V_92 [ V_56 ] . type != V_115 ) )
continue;
V_2 -> V_106 [ V_103 ] . V_75 = V_104 ;
V_2 -> V_106 [ V_103 ] . V_114 = ( T_2 ) V_92 [ V_56 ] . V_114 ;
V_2 -> V_106 [ V_103 ] . type = ( T_2 ) V_92 [ V_56 ] . type ;
V_2 -> V_106 [ V_103 ] . V_116 = ( T_2 ) V_92 [ V_56 ] . V_117 ;
V_2 -> V_106 [ V_103 ] . V_118 = V_92 [ V_56 ] . V_119 ;
V_2 -> V_106 [ V_103 ] . V_120 = V_92 [ V_56 ] . V_121 ;
V_103 ++ ;
}
for ( V_56 = 0 ; V_56 < V_99 ; V_56 ++ ) {
V_2 -> V_108 [ V_56 ] . V_33 |= V_122 ;
if ( F_39 ( V_2 ) )
F_57 ( V_2 , V_56 , 1 ) ;
}
F_7 ( V_92 ) ;
return 0 ;
V_113:
F_7 ( V_2 -> V_108 ) ;
V_2 -> V_108 = NULL ;
V_110:
F_7 ( V_2 -> V_106 ) ;
V_2 -> V_106 = NULL ;
V_105:
F_7 ( V_92 ) ;
return V_93 ;
}
static int
F_58 ( struct V_1 * V_2 )
{
T_2 V_111 ;
int V_56 , V_93 = 1 ;
T_1 V_123 = V_101 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_93 = F_59 ( V_2 ) ;
if ( V_93 )
goto V_124;
if ( V_125 ) {
for ( V_56 = 0 ; V_56 < V_4 -> V_96 ; V_56 ++ ) {
V_111 = V_2 -> V_106 [ V_56 ] . V_75 ;
if ( V_111 == V_4 -> V_75 )
continue;
V_123 |= ( V_125 &
F_60 ( 0xf , V_111 ) ) ;
}
} else {
V_123 = F_61 ( V_2 , V_126 ) ;
V_123 = ( V_123 & ~ F_60 ( 0xf , V_4 -> V_75 ) ) |
( F_60 ( V_101 ,
V_4 -> V_75 ) ) ;
}
F_62 ( V_2 , V_126 , V_123 ) ;
F_63 ( V_2 ) ;
V_124:
return V_93 ;
}
static void F_64 ( struct V_1 * V_2 ,
const struct V_127 * V_128 )
{
T_1 V_100 , V_129 ;
V_2 -> V_4 -> V_130 = F_61 ( V_2 ,
V_131 ) ;
F_65 ( V_2 ) ;
V_100 = F_61 ( V_2 , V_126 ) ;
if ( V_100 == V_132 )
V_129 = V_101 ;
else
V_129 = F_66 ( V_100 , V_2 -> V_4 -> V_75 ) ;
if ( V_129 == V_133 ) {
V_2 -> V_4 -> V_100 = V_133 ;
F_40 ( & V_2 -> V_5 -> V_29 ,
L_9 ,
V_2 -> V_4 -> V_130 ) ;
V_2 -> V_134 = & V_135 ;
} else
V_2 -> V_134 = & V_136 ;
}
static void F_67 ( T_1 V_137 , T_4 * V_138 )
{
switch ( V_137 ) {
case V_7 :
* V_138 = V_139 ;
break;
case V_140 :
* V_138 = V_141 ;
break;
default:
* V_138 = 0 ;
}
}
static int F_68 ( struct V_25 * V_5 ,
struct V_3 * V_4 )
{
T_1 V_69 ;
void T_5 * V_142 = NULL ;
unsigned long V_143 , V_144 = 0 , V_145 ;
V_143 = F_69 ( V_5 , 0 ) ;
F_67 ( V_5 -> V_6 , & V_145 ) ;
if ( V_143 >= V_145 ) {
V_142 = F_70 ( V_5 , 0 ) ;
if ( V_142 == NULL ) {
F_71 ( & V_5 -> V_29 , L_10 ) ;
return - V_26 ;
}
V_144 = V_143 ;
} else {
return - V_26 ;
}
F_40 ( & V_5 -> V_29 , L_11 , ( int ) ( V_143 >> 20 ) ) ;
V_4 -> V_90 = V_142 ;
V_4 -> V_144 = V_144 ;
V_69 = F_72 ( F_73 ( V_4 -> V_75 ) ) ;
F_44 ( V_4 , V_69 ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 , char * V_146 )
{
struct V_25 * V_5 = V_2 -> V_5 ;
int V_56 , V_147 = 0 ;
for ( V_56 = 0 ; V_56 < V_148 ; ++ V_56 ) {
if ( V_149 [ V_56 ] . V_150 == V_5 -> V_150 &&
V_149 [ V_56 ] . V_6 == V_5 -> V_6 &&
V_149 [ V_56 ] . V_151 == V_5 -> V_152 &&
V_149 [ V_56 ] . V_153 == V_5 -> V_154 ) {
sprintf ( V_146 , L_12 ,
V_2 -> V_21 ,
V_149 [ V_56 ] . V_155 ) ;
V_147 = 1 ;
break;
}
}
if ( ! V_147 )
sprintf ( V_146 , L_13 , V_2 -> V_21 ) ;
}
static void
F_75 ( struct V_1 * V_2 )
{
int V_44 ;
T_1 V_156 , V_157 , V_158 , V_159 ;
struct V_25 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_160 * V_161 = & V_4 -> V_161 ;
V_159 = V_2 -> V_162 ;
V_156 = F_61 ( V_2 , V_163 ) ;
V_157 = F_61 ( V_2 , V_164 ) ;
V_158 = F_61 ( V_2 , V_165 ) ;
V_2 -> V_162 = F_76 ( V_156 , V_157 , V_158 ) ;
V_44 = F_77 ( V_2 ) ;
if ( V_44 ) {
F_71 ( & V_5 -> V_29 , L_14 ) ;
return;
}
if ( V_4 -> V_100 != V_133 ) {
if ( V_161 -> V_166 == NULL ||
V_2 -> V_162 > V_159 ) {
if ( V_161 -> V_166 )
F_51 ( V_161 -> V_166 ) ;
if ( ! F_78 ( V_2 ) )
F_40 ( & V_5 -> V_29 ,
L_15 ) ;
}
}
F_40 ( & V_5 -> V_29 , L_16 ,
V_167 , V_156 , V_157 , V_158 ) ;
if ( V_2 -> V_4 -> V_94 == V_98 ) {
if ( V_2 -> V_33 & V_47 ) {
V_2 -> V_168 = V_169 ;
V_2 -> V_170 = V_171 ;
} else {
V_2 -> V_168 = V_172 ;
V_2 -> V_170 = V_173 ;
}
V_2 -> V_174 = V_175 ;
V_2 -> V_176 = V_175 ;
} else if ( V_2 -> V_4 -> V_94 == V_95 ) {
V_2 -> V_168 = V_177 ;
V_2 -> V_174 = V_178 ;
V_2 -> V_176 = V_178 ;
V_2 -> V_170 = V_179 ;
}
V_2 -> V_4 -> V_64 = ! ! V_79 ;
V_2 -> V_180 = V_181 ;
V_2 -> V_182 = V_183 ;
}
static int
F_79 ( struct V_1 * V_2 )
{
int V_44 ;
struct V_184 V_185 ;
memset ( & V_185 , 0 , sizeof( struct V_184 ) ) ;
V_44 = F_80 ( V_2 , & V_185 , V_2 -> V_4 -> V_75 ) ;
if ( V_44 )
return V_44 ;
V_2 -> V_4 -> V_186 = ( T_2 ) V_185 . V_187 ;
V_2 -> V_4 -> V_188 = V_185 . V_188 ;
V_2 -> V_4 -> V_189 = V_185 . V_189 ;
V_2 -> V_4 -> V_190 = V_185 . V_190 ;
V_2 -> V_4 -> V_8 = V_185 . V_8 ;
if ( V_2 -> V_4 -> V_8 & V_191 ) {
T_1 V_192 ;
V_192 = F_81 ( V_2 , V_193 ) ;
V_2 -> V_4 -> V_194 = V_192 ;
}
V_2 -> V_4 -> V_195 = V_185 . V_195 ;
V_2 -> V_4 -> V_196 = V_185 . V_196 ;
if ( F_39 ( V_2 ) )
return V_44 ;
if ( V_2 -> V_4 -> V_8 & V_197 )
V_2 -> V_33 |= V_47 ;
else
V_2 -> V_33 &= ~ V_47 ;
return V_44 ;
}
void F_82 ( struct V_1 * V_2 ,
struct V_198 * V_199 )
{
if ( V_199 -> V_200 )
V_2 -> V_33 &= ~ V_201 ;
else
V_2 -> V_33 |= V_201 ;
if ( V_199 -> V_202 )
V_2 -> V_203 = V_199 -> V_202 ;
else
V_2 -> V_203 = 0 ;
}
static int
F_83 ( struct V_23 * V_24 , T_3 V_204 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
F_84 ( V_204 , V_2 -> V_205 ) ;
return 0 ;
}
static int
F_85 ( struct V_23 * V_24 , T_3 V_204 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
F_86 ( V_24 , V_206 ) ;
F_87 ( V_204 , V_2 -> V_205 ) ;
return 0 ;
}
void F_88 ( struct V_1 * V_2 ,
struct V_198 * V_199 )
{
V_2 -> V_33 &= ~ ( V_207 | V_34 |
V_208 ) ;
if ( V_199 -> V_209 )
V_2 -> V_33 |= V_207 ;
if ( ! V_199 -> V_210 )
V_2 -> V_33 |= V_34 ;
if ( ! V_199 -> V_211 )
V_2 -> V_33 |= V_208 ;
F_89 ( V_2 , V_199 ) ;
}
int F_90 ( struct V_1 * V_2 )
{
struct V_198 V_199 ;
if ( ! ( V_2 -> V_33 & V_47 ) )
return 0 ;
V_199 . V_75 = V_2 -> V_4 -> V_75 ;
if ( F_91 ( V_2 , & V_199 ) )
return - V_26 ;
F_82 ( V_2 , & V_199 ) ;
F_88 ( V_2 , & V_199 ) ;
return 0 ;
}
static void
F_89 ( struct V_1 * V_2 ,
struct V_198 * V_199 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
unsigned long V_212 , V_213 ;
if ( F_39 ( V_2 ) )
return;
V_212 = ( V_214 | V_215 | V_216 |
V_217 | V_218 ) ;
V_213 = ( V_214 | V_215 |
V_217 ) ;
if ( F_92 ( V_2 ) ) {
V_212 |= ( V_219 | V_220 ) ;
V_213 |= ( V_219 | V_220 ) ;
}
if ( V_24 -> V_212 & V_221 )
V_212 |= V_221 ;
if ( V_199 -> V_222 & V_223 ) {
V_24 -> V_212 |= V_212 ;
V_2 -> V_224 = 1 ;
if ( ! ( V_199 -> V_222 & V_225 ) ) {
V_24 -> V_212 &= ~ V_219 ;
V_212 &= ~ V_219 ;
}
if ( ! ( V_199 -> V_222 & V_226 ) ) {
V_24 -> V_212 &= ~ V_220 ;
V_212 &= ~ V_220 ;
}
} else {
V_24 -> V_212 &= ~ V_212 ;
V_212 &= ~ V_212 ;
V_2 -> V_224 = 0 ;
}
V_24 -> V_213 = ( V_212 & V_213 ) ;
}
static int
F_93 ( struct V_1 * V_2 )
{
T_1 V_100 , V_129 ;
int V_44 = 0 ;
V_44 = F_79 ( V_2 ) ;
if ( V_44 )
return V_44 ;
if ( V_2 -> V_33 & V_227 )
return 0 ;
V_100 = F_61 ( V_2 , V_126 ) ;
V_129 = F_66 ( V_100 , V_2 -> V_4 -> V_75 ) ;
if ( V_100 == V_132 )
V_129 = V_101 ;
else
V_129 = F_66 ( V_100 , V_2 -> V_4 -> V_75 ) ;
if ( V_2 -> V_33 & V_47 ) {
if ( V_129 == V_101 ) {
V_2 -> V_4 -> V_100 = V_101 ;
V_44 = F_56 ( V_2 ) ;
if ( V_44 )
return V_44 ;
F_58 ( V_2 ) ;
F_40 ( & V_2 -> V_5 -> V_29 ,
L_17 ,
V_2 -> V_4 -> V_130 ) ;
} else if ( V_129 == V_228 ) {
V_2 -> V_4 -> V_100 = V_228 ;
F_40 ( & V_2 -> V_5 -> V_29 ,
L_18 ,
V_2 -> V_4 -> V_130 ) ;
}
}
V_2 -> V_33 |= V_227 ;
return V_44 ;
}
int F_94 ( struct V_1 * V_2 )
{
struct V_198 V_199 ;
struct V_107 * V_229 ;
T_2 V_56 ;
if ( V_2 -> V_230 )
return 0 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_4 -> V_96 ; V_56 ++ ) {
memset ( & V_199 , 0 , sizeof( struct V_198 ) ) ;
V_199 . V_75 = V_2 -> V_106 [ V_56 ] . V_75 ;
V_199 . V_210 = V_223 ;
V_199 . V_211 = V_223 ;
if ( F_95 ( V_2 ) ) {
V_199 . V_222 = V_223 ;
if ( F_92 ( V_2 ) )
V_199 . V_222 |= ( V_225 | V_226 ) ;
}
if ( F_96 ( V_2 , & V_199 ) )
return - V_26 ;
V_229 = & V_2 -> V_106 [ V_56 ] ;
V_229 -> V_203 = V_199 . V_202 ;
V_229 -> V_210 = V_199 . V_210 ;
V_229 -> V_209 = V_199 . V_209 ;
V_229 -> V_200 = V_199 . V_200 ;
V_229 -> V_211 = V_199 . V_211 ;
V_229 -> V_222 = V_199 . V_222 ;
}
return 0 ;
}
static int
F_97 ( struct V_1 * V_2 ,
struct V_107 * V_229 , int V_75 )
{
struct V_198 V_199 ;
V_199 . V_100 = V_231 ;
V_199 . V_75 = V_75 ;
V_199 . V_202 = V_229 -> V_203 ;
V_199 . V_210 = V_229 -> V_210 ;
V_199 . V_200 = V_229 -> V_200 ;
V_199 . V_209 = V_229 -> V_209 ;
V_199 . V_222 = V_229 -> V_222 ;
V_199 . V_211 = V_229 -> V_211 ;
if ( F_96 ( V_2 , & V_199 ) )
return - V_26 ;
V_199 . V_100 = V_232 ;
if ( F_96 ( V_2 , & V_199 ) )
return - V_26 ;
return 0 ;
}
int F_98 ( struct V_1 * V_2 )
{
int V_56 , V_44 ;
struct V_107 * V_229 ;
struct V_184 V_185 ;
T_2 V_75 ;
if ( F_95 ( V_2 ) )
if ( ! V_2 -> V_230 )
return 0 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_4 -> V_96 ; V_56 ++ ) {
V_229 = & V_2 -> V_106 [ V_56 ] ;
V_75 = V_229 -> V_75 ;
memset ( & V_185 , 0 , sizeof( struct V_184 ) ) ;
V_44 = F_80 ( V_2 , & V_185 , V_75 ) ;
if ( V_44 )
return V_44 ;
V_185 . V_233 = V_229 -> V_118 ;
V_185 . V_234 = V_229 -> V_120 ;
V_44 = F_99 ( V_2 , & V_185 ) ;
if ( V_44 )
return V_44 ;
if ( V_229 -> V_235 ) {
V_44 = F_100 ( V_2 ,
V_229 -> V_236 , 1 ,
V_75 ) ;
if ( V_44 )
return V_44 ;
}
V_44 = F_97 ( V_2 , V_229 , V_75 ) ;
if ( V_44 )
return V_44 ;
}
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
T_2 V_237 = V_238 ;
T_1 V_239 ;
if ( V_2 -> V_4 -> V_100 == V_101 )
return 0 ;
V_239 = F_61 ( V_2 ,
V_240 ) ;
while ( V_239 != V_241 && -- V_237 ) {
F_102 ( 1000 ) ;
V_239 = F_61 ( V_2 ,
V_240 ) ;
}
if ( ! V_237 ) {
F_71 ( & V_2 -> V_5 -> V_29 ,
L_19 ) ;
return - V_26 ;
}
return 0 ;
}
static int
F_103 ( struct V_1 * V_2 )
{
int V_44 ;
if ( ! ( V_2 -> V_33 & V_47 ) ||
V_2 -> V_4 -> V_100 != V_101 )
return 0 ;
V_44 = F_94 ( V_2 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_98 ( V_2 ) ;
if ( V_44 )
return V_44 ;
F_104 ( V_2 ) ;
return V_44 ;
}
int F_105 ( struct V_1 * V_2 )
{
int V_44 ;
V_44 = F_106 ( V_2 ) ;
if ( V_44 < 0 )
return V_44 ;
else if ( ! V_44 )
goto V_242;
if ( V_243 )
F_107 ( V_2 ) ;
else {
V_44 = F_108 ( V_2 ) ;
if ( V_44 )
goto V_244;
V_2 -> V_4 -> V_245 = V_246 ;
}
V_44 = F_109 ( V_2 ) ;
if ( V_44 == 0 )
goto V_242;
V_44 = F_110 ( V_2 ) ;
if ( V_44 )
goto V_244;
V_44 = F_111 ( V_2 ) ;
if ( V_44 )
goto V_244;
F_112 ( V_2 ) ;
F_113 ( V_2 , V_247 , V_248 ) ;
V_242:
V_44 = F_114 ( V_2 ) ;
if ( V_44 )
goto V_244;
F_62 ( V_2 , V_249 , V_250 ) ;
F_115 ( V_2 , 1 ) ;
V_44 = F_93 ( V_2 ) ;
if ( V_44 ) {
F_71 ( & V_2 -> V_5 -> V_29 ,
L_20 ) ;
goto V_244;
}
V_44 = F_103 ( V_2 ) ;
if ( V_44 )
goto V_244;
F_75 ( V_2 ) ;
V_2 -> V_230 = 0 ;
F_112 ( V_2 ) ;
return 0 ;
V_244:
F_62 ( V_2 , V_249 , V_251 ) ;
F_71 ( & V_2 -> V_5 -> V_29 , L_21 ) ;
F_112 ( V_2 ) ;
return V_44 ;
}
static int
F_116 ( struct V_1 * V_2 )
{
T_6 V_252 ;
struct V_18 * V_253 ;
struct V_10 * V_11 ;
int V_44 , V_254 ;
unsigned long V_33 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_255 == V_256 ) {
if ( F_95 ( V_2 ) )
V_252 = V_257 ;
if ( ! F_117 ( V_2 ) )
V_33 |= V_258 ;
} else {
if ( V_2 -> V_33 & V_63 )
V_252 = V_259 ;
else if ( V_2 -> V_33 & V_62 )
V_252 = V_260 ;
else {
V_33 |= V_258 ;
if ( F_95 ( V_2 ) )
V_252 = V_261 ;
else
V_252 = V_262 ;
}
}
V_2 -> V_78 = V_24 -> V_78 ;
if ( V_2 -> V_4 -> V_255 != V_263 ) {
if ( F_95 ( V_2 ) ||
( F_39 ( V_2 ) &&
( V_2 -> V_33 & V_63 ) ) ) {
for ( V_254 = 0 ; V_254 < V_2 -> V_61 ; V_254 ++ ) {
V_253 = & V_15 -> V_19 [ V_254 ] ;
snprintf ( V_253 -> V_146 , sizeof( int ) + V_264 ,
L_22 , V_24 -> V_146 , V_254 ) ;
V_44 = F_118 ( V_253 -> V_78 , V_252 , V_33 ,
V_253 -> V_146 , V_253 ) ;
if ( V_44 )
return V_44 ;
}
}
if ( F_39 ( V_2 ) &&
( V_2 -> V_33 & V_63 ) ) {
V_252 = V_265 ;
for ( V_254 = 0 ; V_254 < V_2 -> V_67 ;
V_254 ++ ) {
V_11 = & V_2 -> V_11 [ V_254 ] ;
snprintf ( V_11 -> V_146 , sizeof( int ) + V_264 ,
L_22 , V_24 -> V_146 ,
V_2 -> V_61 + V_254 ) ;
V_44 = F_118 ( V_11 -> V_78 , V_252 , V_33 ,
V_11 -> V_146 , V_11 ) ;
if ( V_44 )
return V_44 ;
}
}
}
return 0 ;
}
static void
F_119 ( struct V_1 * V_2 )
{
int V_254 ;
struct V_18 * V_253 ;
struct V_10 * V_11 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_255 != V_263 ) {
if ( F_95 ( V_2 ) ||
( F_39 ( V_2 ) &&
( V_2 -> V_33 & V_63 ) ) ) {
for ( V_254 = 0 ; V_254 < V_2 -> V_61 ; V_254 ++ ) {
V_253 = & V_15 -> V_19 [ V_254 ] ;
F_120 ( V_253 -> V_78 , V_253 ) ;
}
}
if ( F_39 ( V_2 ) ) {
for ( V_254 = 0 ; V_254 < V_2 -> V_67 ;
V_254 ++ ) {
V_11 = & V_2 -> V_11 [ V_254 ] ;
if ( V_11 -> V_78 )
F_120 ( V_11 -> V_78 , V_11 ) ;
}
}
}
}
static void F_121 ( struct V_1 * V_2 )
{
T_1 V_266 = 0 ;
if ( F_95 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_194 &
V_267 )
V_2 -> V_33 |= V_268 ;
} else {
V_266 = V_2 -> V_4 -> V_8 ;
if ( F_122 ( V_266 ) )
V_2 -> V_33 |= V_268 ;
}
}
int F_123 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
int V_254 ;
struct V_269 * V_270 ;
if ( V_2 -> V_271 != V_272 )
return - V_26 ;
if ( F_14 ( V_38 , & V_2 -> V_39 ) )
return 0 ;
if ( F_90 ( V_2 ) )
return - V_26 ;
F_121 ( V_2 ) ;
if ( F_124 ( V_2 ) )
return - V_26 ;
for ( V_254 = 0 ; V_254 < V_2 -> V_182 ; V_254 ++ ) {
V_270 = & V_2 -> V_15 -> V_273 [ V_254 ] ;
F_125 ( V_2 , V_270 , V_254 ) ;
}
F_17 ( V_24 ) ;
F_126 ( V_2 , V_24 -> V_274 ) ;
V_2 -> V_4 -> V_275 = 0 ;
if ( V_2 -> V_61 > 1 )
F_127 ( V_2 , 1 ) ;
F_128 ( V_2 ) ;
if ( V_24 -> V_212 & V_221 )
F_129 ( V_2 , V_276 ) ;
F_19 ( V_2 ) ;
F_130 ( V_2 , 1 ) ;
V_2 -> V_4 -> V_277 = 0 ;
F_84 ( V_38 , & V_2 -> V_39 ) ;
return 0 ;
}
int F_131 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
int V_44 = 0 ;
F_132 () ;
if ( F_133 ( V_24 ) )
V_44 = F_123 ( V_2 , V_24 ) ;
F_134 () ;
return V_44 ;
}
void F_135 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
if ( V_2 -> V_271 != V_272 )
return;
if ( ! F_136 ( V_38 , & V_2 -> V_39 ) )
return;
F_137 () ;
F_138 ( & V_2 -> V_278 ) ;
F_139 ( V_24 ) ;
F_140 ( V_24 ) ;
F_141 ( V_2 ) ;
if ( V_2 -> V_279 . V_280 )
F_142 ( V_2 ) ;
F_143 ( V_2 , V_281 ) ;
F_16 ( V_2 ) ;
F_144 ( V_2 ) ;
V_2 -> V_33 &= ~ V_268 ;
F_145 ( V_2 ) ;
F_146 ( V_2 ) ;
F_147 ( & V_2 -> V_278 ) ;
}
void F_148 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
F_132 () ;
if ( F_133 ( V_24 ) )
F_135 ( V_2 , V_24 ) ;
F_134 () ;
}
int
F_149 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_25 * V_5 = V_2 -> V_5 ;
int V_44 ;
if ( V_2 -> V_271 == V_272 )
return 0 ;
V_44 = F_150 ( V_2 , V_24 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_151 ( V_2 ) ;
if ( V_44 ) {
F_71 ( & V_5 -> V_29 , L_23 ) ;
goto V_282;
}
V_44 = F_152 ( V_2 ) ;
if ( V_44 ) {
F_71 ( & V_5 -> V_29 , L_24 ) ;
goto V_283;
}
V_44 = F_116 ( V_2 ) ;
if ( V_44 ) {
F_71 ( & V_5 -> V_29 , L_25 ) ;
goto V_284;
}
F_153 ( V_2 ) ;
V_2 -> V_271 = V_272 ;
return 0 ;
V_284:
F_154 ( V_2 ) ;
V_283:
F_155 ( V_2 ) ;
V_282:
F_156 ( V_2 ) ;
return V_44 ;
}
void F_157 ( struct V_1 * V_2 )
{
if ( V_2 -> V_271 != V_272 )
return;
F_158 ( V_2 ) ;
F_154 ( V_2 ) ;
F_159 ( V_2 ) ;
F_119 ( V_2 ) ;
F_156 ( V_2 ) ;
F_155 ( V_2 ) ;
V_2 -> V_271 = 0 ;
}
void F_160 ( struct V_23 * V_24 , int V_61 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
struct V_18 * V_253 ;
int V_254 ;
F_87 ( V_38 , & V_2 -> V_39 ) ;
if ( V_2 -> V_4 -> V_255 == V_256 ) {
for ( V_254 = 0 ; V_254 < V_2 -> V_61 ; V_254 ++ ) {
V_253 = & V_2 -> V_15 -> V_19 [ V_254 ] ;
F_161 ( V_253 ) ;
}
}
F_144 ( V_2 ) ;
F_157 ( V_2 ) ;
V_2 -> V_4 -> V_255 = 0 ;
V_2 -> V_61 = V_61 ;
if ( F_149 ( V_2 ) )
goto V_285;
if ( F_133 ( V_24 ) )
F_123 ( V_2 , V_24 ) ;
V_285:
F_18 ( V_24 ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
int V_44 = 0 ;
V_2 -> V_15 = F_5 ( sizeof( struct V_14 ) ,
V_20 ) ;
if ( ! V_2 -> V_15 ) {
V_44 = - V_60 ;
goto V_244;
}
V_2 -> V_4 -> V_286 . V_287 = V_288 ;
V_2 -> V_4 -> V_286 . V_289 = V_290 ;
V_2 -> V_4 -> V_286 . V_291 = V_292 ;
memset ( & V_2 -> V_293 , 0 , sizeof( V_2 -> V_293 ) ) ;
V_244:
return V_44 ;
}
static void F_163 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_2 -> V_4 -> V_161 . V_166 ) {
F_51 ( V_2 -> V_4 -> V_161 . V_166 ) ;
V_2 -> V_4 -> V_161 . V_166 = NULL ;
}
F_7 ( V_2 -> V_4 -> V_294 . V_295 ) ;
V_2 -> V_4 -> V_161 . V_166 = NULL ;
}
int F_164 ( struct V_23 * V_24 , int V_296 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
struct V_18 * V_253 ;
struct V_269 * V_270 ;
int V_254 ;
int V_93 ;
F_15 ( V_24 ) ;
if ( F_133 ( V_24 ) )
F_135 ( V_2 , V_24 ) ;
F_157 ( V_2 ) ;
V_2 -> V_61 = 1 ;
V_2 -> V_4 -> V_255 = V_296 ;
V_2 -> V_4 -> V_275 = 0 ;
V_93 = F_149 ( V_2 ) ;
if ( V_93 ) {
F_18 ( V_24 ) ;
return V_93 ;
}
V_93 = F_124 ( V_2 ) ;
if ( V_93 ) {
F_157 ( V_2 ) ;
F_18 ( V_24 ) ;
return V_93 ;
}
for ( V_254 = 0 ; V_254 < V_2 -> V_182 ; V_254 ++ ) {
V_270 = & V_2 -> V_15 -> V_273 [ V_254 ] ;
F_125 ( V_2 , V_270 , V_254 ) ;
}
if ( V_2 -> V_4 -> V_255 == V_256 ) {
for ( V_254 = 0 ; V_254 < V_2 -> V_61 ; V_254 ++ ) {
V_253 = & V_2 -> V_15 -> V_19 [ V_254 ] ;
F_165 ( V_253 ) ;
}
}
if ( V_2 -> V_4 -> V_255 == V_263 ) {
V_2 -> V_4 -> V_297 = 0 ;
F_130 ( V_2 , 1 ) ;
}
F_84 ( V_38 , & V_2 -> V_39 ) ;
return 0 ;
}
static int
F_166 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
if ( F_33 ( V_53 , & V_2 -> V_39 ) )
return - V_298 ;
F_15 ( V_24 ) ;
F_148 ( V_2 , V_24 ) ;
F_131 ( V_2 , V_24 ) ;
F_18 ( V_24 ) ;
F_87 ( V_53 , & V_2 -> V_39 ) ;
F_71 ( & V_2 -> V_5 -> V_29 , L_26 , V_46 ) ;
return 0 ;
}
int
F_167 ( struct V_1 * V_2 )
{
int V_44 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( F_33 ( V_53 , & V_2 -> V_39 ) )
return - V_298 ;
if ( V_2 -> V_271 == V_272 ) {
F_15 ( V_24 ) ;
if ( F_133 ( V_24 ) )
F_135 ( V_2 , V_24 ) ;
F_157 ( V_2 ) ;
if ( F_133 ( V_24 ) ) {
V_44 = F_149 ( V_2 ) ;
if ( ! V_44 ) {
F_123 ( V_2 , V_24 ) ;
F_86 ( V_24 , V_299 ) ;
}
}
F_18 ( V_24 ) ;
}
F_87 ( V_53 , & V_2 -> V_39 ) ;
return V_44 ;
}
static int
F_168 ( struct V_1 * V_2 , struct V_23 * V_24 ,
int V_300 )
{
int V_44 ;
struct V_25 * V_5 = V_2 -> V_5 ;
V_2 -> V_224 = 1 ;
V_2 -> V_4 -> V_301 = 0 ;
V_2 -> V_4 -> V_302 = V_303 ;
V_24 -> V_304 = & V_305 ;
V_24 -> V_306 = V_307 * V_308 ;
F_169 ( V_24 , V_24 -> V_274 ) ;
F_170 ( V_24 , & V_309 ) ;
V_24 -> V_212 |= ( V_214 | V_215 | V_216 |
V_217 | V_218 |
V_310 ) ;
V_24 -> V_213 |= ( V_214 | V_215 |
V_217 ) ;
if ( F_92 ( V_2 ) ) {
V_24 -> V_212 |= ( V_219 | V_220 ) ;
V_24 -> V_213 |= ( V_219 | V_220 ) ;
}
if ( V_300 ) {
V_24 -> V_212 |= V_311 ;
V_24 -> V_213 |= V_311 ;
}
if ( F_1 ( V_2 ) )
V_24 -> V_212 |= ( V_312 ) ;
if ( V_2 -> V_4 -> V_8 & V_313 )
V_24 -> V_212 |= V_221 ;
V_24 -> V_314 = V_24 -> V_212 ;
V_24 -> V_78 = V_2 -> V_58 [ 0 ] . V_77 ;
V_44 = F_171 ( V_24 ) ;
if ( V_44 ) {
F_71 ( & V_5 -> V_29 , L_27 ) ;
return V_44 ;
}
return 0 ;
}
static int F_172 ( struct V_25 * V_5 , int * V_300 )
{
if ( ! F_173 ( V_5 , F_174 ( 64 ) ) &&
! F_175 ( V_5 , F_174 ( 64 ) ) )
* V_300 = 1 ;
else if ( ! F_173 ( V_5 , F_174 ( 32 ) ) &&
! F_175 ( V_5 , F_174 ( 32 ) ) )
* V_300 = 0 ;
else {
F_71 ( & V_5 -> V_29 , L_28 ) ;
return - V_26 ;
}
return 0 ;
}
void F_176 ( struct V_1 * V_2 )
{
int V_254 ;
struct V_10 * V_11 ;
for ( V_254 = 0 ; V_254 < V_2 -> V_67 ; V_254 ++ ) {
V_11 = & V_2 -> V_11 [ V_254 ] ;
if ( V_11 && V_11 -> V_315 != NULL ) {
F_51 ( V_11 -> V_315 ) ;
V_11 -> V_315 = NULL ;
}
}
if ( V_2 -> V_11 != NULL )
F_7 ( V_2 -> V_11 ) ;
}
int F_177 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
int V_254 , V_77 , V_316 ;
struct V_10 * V_11 ;
struct V_317 * V_315 ;
V_11 = F_37 ( V_2 -> V_67 ,
sizeof( struct V_10 ) , V_20 ) ;
if ( V_11 == NULL )
return - V_60 ;
V_2 -> V_11 = V_11 ;
for ( V_254 = 0 ; V_254 < V_2 -> V_67 ; V_254 ++ ) {
V_11 = & V_2 -> V_11 [ V_254 ] ;
V_11 -> V_318 = V_2 -> V_180 ;
V_11 -> V_319 = F_178 ( V_24 , V_254 ) ;
V_315 = F_179 ( F_180 ( V_11 ) ) ;
if ( V_315 == NULL ) {
F_176 ( V_2 ) ;
return - V_60 ;
}
memset ( V_315 , 0 , F_180 ( V_11 ) ) ;
V_11 -> V_315 = V_315 ;
}
if ( F_39 ( V_2 ) ) {
for ( V_254 = 0 ; V_254 < V_2 -> V_67 ; V_254 ++ ) {
V_11 = & V_2 -> V_11 [ V_254 ] ;
V_11 -> V_2 = V_2 ;
if ( V_2 -> V_33 & V_63 ) {
V_316 = V_2 -> V_61 + V_254 ;
V_77 = V_2 -> V_58 [ V_316 ] . V_77 ;
V_11 -> V_78 = V_77 ;
}
}
}
return 0 ;
}
static int
F_181 ( struct V_25 * V_5 , const struct V_127 * V_128 )
{
struct V_23 * V_24 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_44 , V_300 = - 1 ;
T_1 V_320 ;
char V_321 [ V_322 + 19 ] ;
V_44 = F_182 ( V_5 ) ;
if ( V_44 )
return V_44 ;
if ( ! ( F_183 ( V_5 , 0 ) & V_323 ) ) {
V_44 = - V_324 ;
goto V_325;
}
V_44 = F_172 ( V_5 , & V_300 ) ;
if ( V_44 )
goto V_325;
V_44 = F_184 ( V_5 , V_326 ) ;
if ( V_44 )
goto V_325;
F_185 ( V_5 ) ;
F_186 ( V_5 ) ;
V_4 = F_5 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 )
goto V_327;
if ( V_128 -> V_6 == V_7 ) {
V_4 -> V_328 = & V_329 ;
V_4 -> V_330 = ( T_1 * ) V_331 ;
} else if ( V_128 -> V_6 == V_140 ) {
F_187 ( V_4 ) ;
} else {
goto V_332;
}
V_44 = F_68 ( V_5 , V_4 ) ;
if ( V_44 )
goto V_332;
V_24 = F_188 ( sizeof( struct V_1 ) ) ;
if ( ! V_24 ) {
V_44 = - V_60 ;
goto V_333;
}
F_189 ( V_24 , & V_5 -> V_29 ) ;
V_2 = F_13 ( V_24 ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_334 = F_190 ( L_29 ) ;
if ( V_2 -> V_334 == NULL ) {
F_71 ( & V_5 -> V_29 , L_30 ) ;
goto V_335;
}
V_44 = F_162 ( V_2 ) ;
if ( V_44 )
goto V_335;
V_2 -> V_336 = V_337 ;
V_2 -> V_4 -> V_338 = V_5 -> V_339 ;
if ( V_340 == V_341 )
V_2 -> V_45 = true ;
else if ( V_340 == V_342 )
V_2 -> V_343 = true ;
V_2 -> V_67 = 1 ;
F_191 ( & V_2 -> V_4 -> V_344 ) ;
F_192 ( & V_2 -> V_4 -> V_345 ) ;
F_193 ( & V_2 -> V_278 ) ;
F_194 ( & V_2 -> V_346 ) ;
if ( F_95 ( V_2 ) ) {
F_64 ( V_2 , V_128 ) ;
V_2 -> V_347 = V_2 -> V_4 -> V_75 ;
V_44 = F_195 ( V_2 ) ;
if ( V_44 ) {
F_71 ( & V_5 -> V_29 , L_31 ) ;
goto V_284;
}
V_44 = F_196 ( V_2 ) ;
if ( V_44 )
goto V_284;
V_2 -> V_33 |= V_348 ;
} else if ( F_39 ( V_2 ) ) {
F_197 ( V_2 , V_128 ) ;
V_2 -> V_347 = V_2 -> V_4 -> V_75 ;
V_44 = F_198 ( V_2 ) ;
if ( V_44 ) {
F_71 ( & V_5 -> V_29 , L_32 , V_46 ) ;
goto V_284;
}
} else {
F_71 ( & V_5 -> V_29 ,
L_33 , V_46 ) ;
goto V_284;
}
if ( F_8 ( V_2 ) )
F_11 ( & V_5 -> V_29 , L_34 ) ;
if ( V_2 -> V_347 == 0 ) {
F_74 ( V_2 , V_321 ) ;
F_21 ( L_35 ,
F_199 ( V_349 ) ,
V_321 , V_2 -> V_4 -> V_338 ) ;
}
V_44 = F_200 ( V_2 , 0 ) ;
if ( V_44 ) {
F_71 ( & V_5 -> V_29 , L_36 ) ;
goto V_350;
}
if ( F_39 ( V_2 ) ) {
V_44 = F_201 ( V_2 ) ;
if ( V_44 )
goto V_350;
}
V_44 = F_168 ( V_2 , V_24 , V_300 ) ;
if ( V_44 )
goto V_351;
if ( F_95 ( V_2 ) ) {
if ( V_4 -> V_8 & V_191 ) {
V_320 = F_81 ( V_2 , V_193 ) ;
if ( V_320 & V_352 )
F_202 ( V_2 ) ;
}
}
F_203 ( V_5 , V_2 ) ;
if ( F_95 ( V_2 ) )
F_204 ( V_2 , V_353 ,
V_354 ) ;
switch ( V_2 -> V_4 -> V_94 ) {
case V_95 :
F_40 ( & V_2 -> V_5 -> V_29 , L_37 ,
V_2 -> V_24 -> V_146 ) ;
break;
case V_98 :
F_40 ( & V_2 -> V_5 -> V_29 , L_38 ,
V_2 -> V_24 -> V_146 ) ;
break;
}
if ( F_54 ( V_2 ) )
goto V_351;
if ( V_2 -> V_343 )
F_205 ( V_2 ) ;
F_206 ( V_2 ) ;
return 0 ;
V_351:
if ( F_39 ( V_2 ) )
F_207 ( V_2 ) ;
V_350:
F_48 ( V_2 ) ;
F_208 ( V_2 ) ;
F_209 ( V_2 , 0 ) ;
V_284:
F_163 ( V_2 ) ;
V_335:
F_210 ( V_24 ) ;
V_333:
F_52 ( V_2 ) ;
V_332:
F_7 ( V_4 ) ;
V_327:
F_211 ( V_5 ) ;
V_325:
F_203 ( V_5 , NULL ) ;
F_212 ( V_5 ) ;
return V_44 ;
}
static void F_213 ( struct V_25 * V_5 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
struct V_3 * V_4 ;
V_2 = F_214 ( V_5 ) ;
if ( V_2 == NULL )
return;
V_24 = V_2 -> V_24 ;
F_208 ( V_2 ) ;
V_4 = V_2 -> V_4 ;
F_215 ( V_24 ) ;
if ( F_39 ( V_2 ) ) {
F_207 ( V_2 ) ;
F_216 ( V_2 , 0 ) ;
F_35 ( & V_2 -> V_355 ) ;
}
F_157 ( V_2 ) ;
if ( V_2 -> V_106 != NULL )
F_7 ( V_2 -> V_106 ) ;
if ( V_2 -> V_108 != NULL )
F_7 ( V_2 -> V_108 ) ;
if ( F_95 ( V_2 ) )
F_209 ( V_2 , 0 ) ;
F_87 ( V_53 , & V_2 -> V_39 ) ;
F_217 ( V_2 ) ;
F_48 ( V_2 ) ;
F_218 ( V_2 ) ;
F_52 ( V_2 ) ;
F_112 ( V_2 ) ;
F_219 ( V_5 ) ;
F_211 ( V_5 ) ;
F_212 ( V_5 ) ;
F_203 ( V_5 , NULL ) ;
if ( V_2 -> V_334 ) {
F_220 ( V_2 -> V_334 ) ;
V_2 -> V_334 = NULL ;
}
F_163 ( V_2 ) ;
F_7 ( V_4 ) ;
F_210 ( V_24 ) ;
}
static int F_221 ( struct V_25 * V_5 )
{
struct V_1 * V_2 = F_214 ( V_5 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_356 ;
F_15 ( V_24 ) ;
F_208 ( V_2 ) ;
if ( F_133 ( V_24 ) )
F_148 ( V_2 , V_24 ) ;
if ( F_95 ( V_2 ) )
F_209 ( V_2 , 0 ) ;
F_87 ( V_53 , & V_2 -> V_39 ) ;
V_356 = F_222 ( V_5 ) ;
if ( V_356 )
return V_356 ;
if ( F_95 ( V_2 ) ) {
if ( F_223 ( V_2 ) ) {
F_224 ( V_5 , V_357 , 1 ) ;
F_224 ( V_5 , V_358 , 1 ) ;
}
}
return 0 ;
}
static void F_225 ( struct V_25 * V_5 )
{
if ( F_221 ( V_5 ) )
return;
F_212 ( V_5 ) ;
}
static int
F_226 ( struct V_25 * V_5 , T_7 V_39 )
{
int V_356 ;
V_356 = F_221 ( V_5 ) ;
if ( V_356 )
return V_356 ;
F_227 ( V_5 , F_228 ( V_5 , V_39 ) ) ;
return 0 ;
}
static int
F_229 ( struct V_25 * V_5 )
{
struct V_1 * V_2 = F_214 ( V_5 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_44 ;
V_44 = F_182 ( V_5 ) ;
if ( V_44 )
return V_44 ;
F_227 ( V_5 , V_359 ) ;
F_185 ( V_5 ) ;
F_230 ( V_5 ) ;
V_44 = F_195 ( V_2 ) ;
if ( V_44 ) {
F_71 ( & V_5 -> V_29 , L_39 ) ;
return V_44 ;
}
if ( F_133 ( V_24 ) ) {
V_44 = F_131 ( V_2 , V_24 ) ;
if ( V_44 )
goto V_360;
F_86 ( V_24 , V_299 ) ;
}
V_360:
F_18 ( V_24 ) ;
F_204 ( V_2 , V_353 , V_354 ) ;
return 0 ;
}
static int F_231 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
int V_44 ;
F_139 ( V_24 ) ;
V_44 = F_149 ( V_2 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_123 ( V_2 , V_24 ) ;
if ( V_44 )
goto V_244;
F_232 ( V_24 ) ;
return 0 ;
V_244:
F_157 ( V_2 ) ;
return V_44 ;
}
static int F_233 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
F_135 ( V_2 , V_24 ) ;
return 0 ;
}
void F_205 ( struct V_1 * V_2 )
{
void * V_361 ;
int V_56 ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_362 = 0 ;
T_3 V_96 = 0 ;
if ( V_2 -> V_279 . V_363 && V_2 -> V_279 . V_364 )
return;
V_96 = V_2 -> V_4 -> V_96 ;
F_193 ( & V_2 -> V_365 ) ;
F_193 ( & V_2 -> V_366 ) ;
if ( F_95 ( V_2 ) ) {
V_362 = V_367 ;
V_2 -> V_279 . V_368 = V_369 ;
} else {
V_362 = V_370 ;
V_2 -> V_279 . V_368 = V_371 ;
}
V_361 = F_37 ( V_2 -> V_279 . V_368 ,
sizeof( struct V_372 ) , V_373 ) ;
if ( ! V_361 )
return;
V_2 -> V_279 . V_363 = ( V_362 / V_96 ) ;
V_2 -> V_279 . V_364 = V_361 ;
F_234 ( V_24 , L_40 ,
V_96 , V_2 -> V_279 . V_363 ) ;
for ( V_56 = 0 ; V_56 < V_2 -> V_279 . V_368 ; V_56 ++ )
F_235 ( & V_2 -> V_279 . V_364 [ V_56 ] ) ;
V_2 -> V_374 . V_368 = V_2 -> V_279 . V_368 ;
V_361 = F_37 ( V_2 -> V_374 . V_368 ,
sizeof( struct V_372 ) , V_373 ) ;
if ( ! V_361 )
return;
V_2 -> V_374 . V_363 = ( V_362 / V_96 ) ;
V_2 -> V_374 . V_364 = V_361 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_374 . V_368 ; V_56 ++ )
F_235 ( & V_2 -> V_374 . V_364 [ V_56 ] ) ;
}
static void F_217 ( struct V_1 * V_2 )
{
if ( V_2 -> V_279 . V_363 && V_2 -> V_279 . V_364 )
F_7 ( V_2 -> V_279 . V_364 ) ;
V_2 -> V_279 . V_364 = NULL ;
V_2 -> V_279 . V_363 = 0 ;
if ( V_2 -> V_374 . V_363 && V_2 -> V_374 . V_364 )
F_7 ( V_2 -> V_374 . V_364 ) ;
V_2 -> V_374 . V_363 = 0 ;
V_2 -> V_374 . V_364 = NULL ;
}
int F_236 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_375 , V_376 , V_192 = 0 ;
int V_377 = 0 ;
if ( F_39 ( V_2 ) )
V_192 = F_237 ( V_2 -> V_4 , V_378 ) ;
if ( F_95 ( V_2 ) )
V_192 = F_61 ( V_2 , V_379 ) ;
V_375 = F_238 ( V_192 ) ;
V_376 = F_239 ( V_192 ) ;
if ( V_375 == V_380 ) {
F_71 ( & V_24 -> V_29 ,
L_41
L_42 ,
V_376 ) ;
V_377 = 1 ;
} else if ( V_375 == V_381 ) {
if ( V_2 -> V_4 -> V_192 == V_382 ) {
F_71 ( & V_24 -> V_29 ,
L_43
L_44
L_45 ,
V_376 ) ;
}
} else {
if ( V_2 -> V_4 -> V_192 == V_381 ) {
F_40 ( & V_24 -> V_29 ,
L_46
L_47 , V_376 ) ;
}
}
V_2 -> V_4 -> V_192 = V_375 ;
return V_377 ;
}
static void F_240 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
if ( F_14 ( V_53 , & V_2 -> V_39 ) )
return;
F_71 ( & V_24 -> V_29 , L_48 ) ;
if ( ++ V_2 -> V_383 >= V_384 )
V_2 -> V_230 = 1 ;
else
V_2 -> V_4 -> V_277 = 1 ;
}
static struct V_385 * F_241 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
struct V_385 * V_293 = & V_24 -> V_293 ;
V_293 -> V_291 = V_2 -> V_293 . V_386 + V_2 -> V_293 . V_387 ;
V_293 -> V_388 = V_2 -> V_293 . V_389 ;
V_293 -> V_390 = V_2 -> V_293 . V_391 + V_2 -> V_293 . V_392 ;
V_293 -> V_393 = V_2 -> V_293 . V_394 ;
V_293 -> V_395 = V_2 -> V_293 . V_396 ;
V_293 -> V_397 = V_2 -> V_293 . V_398 ;
return V_293 ;
}
T_8 F_242 ( struct V_1 * V_2 )
{
T_1 V_399 ;
V_399 = F_243 ( V_2 -> V_83 ) ;
if ( ! ( V_399 & V_2 -> V_4 -> V_81 ) )
return V_400 ;
V_399 = F_243 ( V_2 -> V_85 ) ;
if ( ! F_244 ( V_399 ) )
return V_400 ;
F_3 ( 0xffffffff , V_2 -> V_76 ) ;
F_243 ( V_2 -> V_83 ) ;
F_243 ( V_2 -> V_83 ) ;
return V_401 ;
}
static T_8 V_257 ( int V_78 , void * V_123 )
{
struct V_18 * V_253 = V_123 ;
struct V_1 * V_2 = V_253 -> V_2 ;
if ( V_2 -> V_33 & V_63 )
goto V_360;
else if ( V_2 -> V_33 & V_62 ) {
F_3 ( 0xffffffff , V_2 -> V_76 ) ;
goto V_360;
}
if ( F_245 ( V_2 ) == V_400 )
return V_400 ;
V_360:
V_2 -> V_4 -> V_402 ++ ;
F_165 ( V_253 ) ;
return V_401 ;
}
static T_8 V_261 ( int V_78 , void * V_123 )
{
struct V_18 * V_253 = V_123 ;
struct V_1 * V_2 = V_253 -> V_2 ;
if ( F_245 ( V_2 ) == V_400 )
return V_400 ;
F_246 ( & V_253 -> V_403 ) ;
return V_401 ;
}
static T_8 V_260 ( int V_78 , void * V_123 )
{
struct V_18 * V_253 = V_123 ;
struct V_1 * V_2 = V_253 -> V_2 ;
F_3 ( 0xffffffff , V_2 -> V_76 ) ;
F_246 ( & V_253 -> V_403 ) ;
return V_401 ;
}
static T_8 V_259 ( int V_78 , void * V_123 )
{
struct V_18 * V_253 = V_123 ;
F_246 ( & V_253 -> V_403 ) ;
return V_401 ;
}
static T_8 V_265 ( int V_78 , void * V_123 )
{
struct V_10 * V_11 = V_123 ;
F_246 ( & V_11 -> V_403 ) ;
return V_401 ;
}
static void F_247 ( struct V_23 * V_24 )
{
int V_254 ;
struct V_18 * V_253 ;
struct V_1 * V_2 = F_13 ( V_24 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
F_248 ( V_2 -> V_78 ) ;
for ( V_254 = 0 ; V_254 < V_2 -> V_61 ; V_254 ++ ) {
V_253 = & V_15 -> V_19 [ V_254 ] ;
V_261 ( V_2 -> V_78 , V_253 ) ;
}
F_249 ( V_2 -> V_78 ) ;
}
static void
F_115 ( struct V_1 * V_2 , T_2 V_404 )
{
T_1 V_405 ;
V_405 = V_2 -> V_347 & 0xf ;
V_405 |= V_404 << 7 ;
V_405 |= ( V_337 - V_2 -> V_336 ) << 8 ;
F_62 ( V_2 , V_406 , V_405 ) ;
V_2 -> V_336 = V_337 ;
}
static int
F_250 ( struct V_1 * V_2 , T_2 V_39 )
{
T_1 V_405 ;
F_251 ( V_39 != V_407 &&
V_39 != V_408 ) ;
if ( F_59 ( V_2 ) )
return - V_26 ;
V_405 = F_61 ( V_2 , V_409 ) ;
if ( V_39 == V_407 )
F_252 ( V_405 , V_2 -> V_347 ) ;
else if ( V_39 == V_408 )
F_253 ( V_405 , V_2 -> V_347 ) ;
F_62 ( V_2 , V_409 , V_405 ) ;
F_63 ( V_2 ) ;
return 0 ;
}
static int
F_254 ( struct V_1 * V_2 )
{
T_1 V_405 ;
if ( F_59 ( V_2 ) )
return - V_298 ;
V_405 = F_61 ( V_2 , V_409 ) ;
F_255 ( V_405 , V_2 -> V_347 ) ;
F_62 ( V_2 , V_409 , V_405 ) ;
F_63 ( V_2 ) ;
return 0 ;
}
static void
F_209 ( struct V_1 * V_2 , T_2 V_410 )
{
T_1 V_405 ;
if ( F_59 ( V_2 ) )
goto V_44;
V_405 = F_61 ( V_2 , V_411 ) ;
F_256 ( V_405 , V_2 -> V_347 ) ;
F_62 ( V_2 , V_411 , V_405 ) ;
if ( V_410 ) {
F_62 ( V_2 , V_249 ,
V_251 ) ;
F_40 ( & V_2 -> V_5 -> V_29 ,
L_49 ) ;
} else if ( ! ( V_405 & 0x11111111 ) )
F_62 ( V_2 , V_249 ,
V_412 ) ;
V_405 = F_61 ( V_2 , V_409 ) ;
F_255 ( V_405 , V_2 -> V_347 ) ;
F_62 ( V_2 , V_409 , V_405 ) ;
F_63 ( V_2 ) ;
V_44:
V_2 -> V_413 = 0 ;
V_2 -> V_33 &= ~ V_414 ;
F_87 ( V_415 , & V_2 -> V_39 ) ;
F_87 ( V_53 , & V_2 -> V_39 ) ;
}
static int
F_257 ( struct V_1 * V_2 )
{
int V_416 , V_39 , V_417 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_39 = F_61 ( V_2 , V_409 ) ;
V_416 = F_61 ( V_2 , V_411 ) ;
if ( V_2 -> V_33 & V_418 ) {
V_417 = ( ~ ( 1 << ( V_4 -> V_75 * 4 ) ) ) ;
V_416 = V_416 & V_417 ;
}
if ( ( ( V_39 & 0x11111111 ) == ( V_416 & 0x11111111 ) ) ||
( ( V_416 & 0x11111111 ) == ( ( V_39 >> 1 ) & 0x11111111 ) ) )
return 0 ;
else
return 1 ;
}
static int F_258 ( struct V_1 * V_2 )
{
T_1 V_405 = F_61 ( V_2 , V_419 ) ;
if ( V_405 != V_420 ) {
F_11 ( & V_2 -> V_5 -> V_29 , L_50
L_51 , V_420 , V_405 ) ;
}
return 0 ;
}
static int
F_106 ( struct V_1 * V_2 )
{
T_1 V_405 , V_421 ;
T_2 V_422 = V_2 -> V_422 ;
T_2 V_347 = V_2 -> V_347 ;
T_2 V_93 ;
if ( F_136 ( V_415 , & V_2 -> V_39 ) )
return 1 ;
if ( F_59 ( V_2 ) )
return - 1 ;
V_405 = F_61 ( V_2 , V_411 ) ;
if ( ! ( V_405 & ( 1 << ( V_347 * 4 ) ) ) ) {
F_259 ( V_405 , V_347 ) ;
F_62 ( V_2 , V_411 , V_405 ) ;
}
V_421 = F_61 ( V_2 , V_249 ) ;
F_260 ( V_2 , V_423 , L_52 , V_421 ) ;
switch ( V_421 ) {
case V_412 :
F_62 ( V_2 , V_249 ,
V_424 ) ;
F_62 ( V_2 , V_419 ,
V_420 ) ;
F_115 ( V_2 , 0 ) ;
F_63 ( V_2 ) ;
return 1 ;
case V_250 :
V_93 = F_258 ( V_2 ) ;
F_63 ( V_2 ) ;
return V_93 ;
case V_407 :
V_405 = F_61 ( V_2 , V_409 ) ;
F_252 ( V_405 , V_347 ) ;
F_62 ( V_2 , V_409 , V_405 ) ;
break;
case V_408 :
V_405 = F_61 ( V_2 , V_409 ) ;
F_253 ( V_405 , V_347 ) ;
F_62 ( V_2 , V_409 , V_405 ) ;
break;
case V_251 :
F_71 ( & V_2 -> V_5 -> V_29 , L_53 ) ;
F_63 ( V_2 ) ;
return - 1 ;
case V_424 :
case V_425 :
break;
}
F_63 ( V_2 ) ;
do {
F_102 ( 1000 ) ;
V_421 = F_61 ( V_2 , V_249 ) ;
if ( V_421 == V_425 )
continue;
} while ( ( V_421 != V_250 ) && -- V_422 );
if ( ! V_422 ) {
F_71 ( & V_2 -> V_5 -> V_29 ,
L_54 ) ;
return - 1 ;
}
if ( F_59 ( V_2 ) )
return - 1 ;
V_405 = F_61 ( V_2 , V_409 ) ;
F_255 ( V_405 , V_347 ) ;
F_62 ( V_2 , V_409 , V_405 ) ;
V_93 = F_258 ( V_2 ) ;
F_63 ( V_2 ) ;
return V_93 ;
}
static void
F_261 ( struct V_426 * V_427 )
{
struct V_1 * V_2 = F_262 ( V_427 ,
struct V_1 , V_54 . V_427 ) ;
T_1 V_428 = 0xf ;
T_1 V_405 ;
if ( F_59 ( V_2 ) )
goto V_429;
V_428 = F_61 ( V_2 , V_249 ) ;
if ( V_428 == V_425 ||
V_428 == V_408 ) {
F_63 ( V_2 ) ;
F_204 ( V_2 , F_261 ,
V_354 * 2 ) ;
return;
}
if ( V_2 -> V_4 -> V_100 == V_133 ) {
F_63 ( V_2 ) ;
goto V_430;
}
if ( V_428 == V_424 ||
V_428 == V_250 ) {
F_40 ( & V_2 -> V_5 -> V_29 , L_55
L_56 ) ;
goto V_431;
}
if ( V_2 -> V_432 ++ > V_2 -> V_433 ) {
F_40 ( & V_2 -> V_5 -> V_29 , L_57 ,
V_2 -> V_433 ) ;
goto V_431;
}
if ( ! F_257 ( V_2 ) ) {
V_431:
V_428 = F_61 ( V_2 , V_249 ) ;
if ( V_428 == V_407 ) {
F_62 ( V_2 , V_249 ,
V_424 ) ;
F_84 ( V_415 , & V_2 -> V_39 ) ;
F_260 ( V_2 , V_434 , L_58 ) ;
F_115 ( V_2 , 0 ) ;
V_405 = F_61 ( V_2 ,
V_409 ) ;
F_252 ( V_405 , V_2 -> V_347 ) ;
F_62 ( V_2 ,
V_409 , V_405 ) ;
}
F_63 ( V_2 ) ;
F_132 () ;
if ( V_2 -> V_4 -> V_161 . V_435 &&
( V_2 -> V_33 & V_418 ) ) {
F_260 ( V_2 , V_434 , L_59 ) ;
F_263 ( V_2 ) ;
V_2 -> V_33 |= V_414 ;
}
F_134 () ;
V_2 -> V_33 &= ~ V_418 ;
if ( ! V_2 -> V_134 -> V_436 ( V_2 ) ) {
F_204 ( V_2 , V_437 , 0 ) ;
V_2 -> V_432 = 0 ;
return;
}
goto V_429;
}
F_63 ( V_2 ) ;
V_430:
V_428 = F_61 ( V_2 , V_249 ) ;
F_260 ( V_2 , V_423 , L_60 , V_428 ) ;
switch ( V_428 ) {
case V_250 :
if ( ! F_195 ( V_2 ) ) {
F_204 ( V_2 , V_437 , 0 ) ;
V_2 -> V_432 = 0 ;
return;
}
case V_251 :
break;
default:
F_204 ( V_2 ,
F_261 , V_354 ) ;
return;
}
V_429:
F_71 ( & V_2 -> V_5 -> V_29 , L_61
L_62 , V_428 , V_2 -> V_432 ) ;
F_18 ( V_2 -> V_24 ) ;
F_209 ( V_2 , 0 ) ;
}
static void
F_264 ( struct V_426 * V_427 )
{
struct V_1 * V_2 = F_262 ( V_427 ,
struct V_1 , V_54 . V_427 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_399 ;
F_15 ( V_24 ) ;
if ( V_2 -> V_428 == V_408 ) {
if ( F_133 ( V_24 ) )
F_135 ( V_2 , V_24 ) ;
} else
F_148 ( V_2 , V_24 ) ;
V_399 = F_61 ( V_2 , V_438 ) ;
if ( V_399 & V_439 ) {
F_71 ( & V_2 -> V_5 -> V_29 ,
L_63 ,
V_399 ) ;
if ( F_265 ( V_399 ) == V_440 ) {
F_71 ( & V_2 -> V_5 -> V_29 ,
L_64
L_65 ) ;
F_71 ( & V_2 -> V_5 -> V_29 ,
L_66 ) ;
}
goto V_429;
}
if ( V_2 -> V_4 -> V_192 == V_380 ) {
F_71 ( & V_2 -> V_5 -> V_29 , L_67 ,
V_2 -> V_4 -> V_192 ) ;
goto V_429;
}
if ( ! ( V_2 -> V_33 & V_418 ) ) {
if ( F_250 ( V_2 , V_2 -> V_428 ) ) {
F_71 ( & V_2 -> V_5 -> V_29 ,
L_68
L_69 ) ;
goto V_429;
}
}
V_2 -> V_432 = 0 ;
F_204 ( V_2 , F_261 , V_354 ) ;
return;
V_429:
F_18 ( V_24 ) ;
F_209 ( V_2 , 1 ) ;
}
static void
F_266 ( struct V_1 * V_2 )
{
T_1 V_39 ;
V_39 = F_61 ( V_2 , V_240 ) ;
if ( V_39 == V_441 )
return;
if ( F_59 ( V_2 ) )
return;
F_62 ( V_2 , V_240 ,
V_441 ) ;
F_63 ( V_2 ) ;
}
void F_267 ( struct V_1 * V_2 , T_1 V_442 )
{
T_1 V_39 , V_443 = 0 , V_444 = 0 ;
F_268 ( V_443 ) ;
F_269 ( V_443 ) ;
F_113 ( V_2 , V_445 , V_443 ) ;
F_270 ( V_444 ) ;
F_271 ( V_444 ) ;
F_272 ( V_444 ) ;
F_273 ( V_444 ) ;
F_113 ( V_2 , V_446 , V_444 ) ;
F_40 ( & V_2 -> V_5 -> V_29 , L_70
L_71 ) ;
V_2 -> V_230 = 1 ;
if ( F_59 ( V_2 ) )
return;
V_39 = F_61 ( V_2 , V_249 ) ;
if ( V_39 == V_250 ) {
F_62 ( V_2 , V_249 ,
V_407 ) ;
V_2 -> V_33 |= V_418 ;
F_260 ( V_2 , V_434 , L_72 ) ;
F_115 ( V_2 , 0 ) ;
}
F_62 ( V_2 , V_240 ,
V_441 ) ;
F_63 ( V_2 ) ;
}
static void
F_104 ( struct V_1 * V_2 )
{
if ( F_59 ( V_2 ) )
return;
F_62 ( V_2 , V_240 ,
V_241 ) ;
F_260 ( V_2 , V_434 , L_73 ) ;
F_63 ( V_2 ) ;
}
void F_204 ( struct V_1 * V_2 ,
T_9 V_447 , int V_448 )
{
if ( F_14 ( V_449 , & V_2 -> V_39 ) )
return;
F_274 ( & V_2 -> V_54 , V_447 ) ;
F_275 ( V_2 -> V_334 , & V_2 -> V_54 ,
F_276 ( V_448 ) ) ;
}
static void
V_437 ( struct V_426 * V_427 )
{
struct V_1 * V_2 = F_262 ( V_427 ,
struct V_1 , V_54 . V_427 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_239 ;
if ( V_2 -> V_4 -> V_100 != V_101 ) {
V_239 = F_61 ( V_2 ,
V_240 ) ;
if ( V_2 -> V_432 ++ > V_238 )
F_209 ( V_2 , 0 ) ;
else if ( V_239 != V_241 )
F_204 ( V_2 , V_437 ,
V_354 ) ;
else
goto V_450;
F_260 ( V_2 , V_434 , L_74 ) ;
return;
}
V_450:
if ( F_133 ( V_24 ) ) {
if ( F_131 ( V_2 , V_24 ) )
goto V_360;
F_86 ( V_24 , V_299 ) ;
}
V_360:
F_18 ( V_24 ) ;
V_2 -> V_413 = 0 ;
V_2 -> V_33 &= ~ V_414 ;
F_87 ( V_53 , & V_2 -> V_39 ) ;
if ( ! F_254 ( V_2 ) )
F_204 ( V_2 , V_353 ,
V_354 ) ;
}
static int
F_277 ( struct V_1 * V_2 )
{
T_1 V_39 = 0 , V_451 ;
T_1 V_452 ;
if ( F_236 ( V_2 ) )
goto V_453;
if ( V_2 -> V_230 )
F_278 ( V_2 , 0 ) ;
V_39 = F_61 ( V_2 , V_249 ) ;
if ( V_39 == V_407 ) {
F_266 ( V_2 ) ;
V_2 -> V_230 = 1 ;
} else if ( V_39 == V_408 )
goto V_453;
V_451 = F_61 ( V_2 , V_454 ) ;
if ( V_451 != V_2 -> V_451 ) {
V_2 -> V_451 = V_451 ;
V_2 -> V_413 = 0 ;
if ( V_2 -> V_230 )
goto V_453;
if ( V_2 -> V_4 -> V_277 && V_455 ) {
F_166 ( V_2 ) ;
V_2 -> V_24 -> V_456 = V_337 ;
}
return 0 ;
}
if ( ++ V_2 -> V_413 < V_457 )
return 0 ;
V_2 -> V_33 |= V_414 ;
F_278 ( V_2 , 0 ) ;
if ( V_455 )
F_87 ( V_458 , & V_2 -> V_39 ) ;
F_71 ( & V_2 -> V_5 -> V_29 , L_75 ) ;
V_452 = F_61 ( V_2 , V_438 ) ;
F_71 ( & V_2 -> V_5 -> V_29 , L_76
L_77
L_78
L_79
L_80 ,
V_452 ,
F_61 ( V_2 , V_459 ) ,
F_81 ( V_2 , V_460 + 0x3c ) ,
F_81 ( V_2 , V_461 + 0x3c ) ,
F_81 ( V_2 , V_462 + 0x3c ) ,
F_81 ( V_2 , V_463 + 0x3c ) ,
F_81 ( V_2 , V_464 + 0x3c ) ) ;
if ( F_265 ( V_452 ) == 0x67 )
F_71 ( & V_2 -> V_5 -> V_29 ,
L_81
L_82 ) ;
V_453:
V_2 -> V_428 = ( V_39 == V_408 ) ? V_39 :
V_407 ;
if ( V_455 && ! F_33 ( V_53 ,
& V_2 -> V_39 ) ) {
F_204 ( V_2 , F_264 , 0 ) ;
F_260 ( V_2 , V_434 , L_83 ) ;
}
return 1 ;
}
static void
V_353 ( struct V_426 * V_427 )
{
struct V_1 * V_2 = F_262 ( V_427 ,
struct V_1 , V_54 . V_427 ) ;
if ( F_14 ( V_53 , & V_2 -> V_39 ) )
goto V_465;
if ( F_277 ( V_2 ) )
return;
if ( V_2 -> V_279 . V_280 )
F_279 ( V_2 ) ;
V_465:
F_204 ( V_2 , V_353 , V_354 ) ;
}
static int F_280 ( struct V_25 * V_5 )
{
struct V_25 * V_466 ;
int V_405 = V_5 -> V_467 ;
while ( V_405 -- > 0 ) {
V_466 = F_281 ( F_282
( V_5 -> V_468 ) , V_5 -> V_468 -> V_469 ,
F_283 ( F_284 ( V_5 -> V_467 ) , V_405 ) ) ;
if ( ! V_466 )
continue;
if ( V_466 -> V_470 != V_357 ) {
F_285 ( V_466 ) ;
return 0 ;
}
F_285 ( V_466 ) ;
}
return 1 ;
}
static int F_286 ( struct V_25 * V_5 )
{
int V_44 , V_471 ;
struct V_1 * V_2 = F_214 ( V_5 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
V_5 -> V_472 = V_473 ;
V_44 = F_182 ( V_5 ) ;
if ( V_44 )
return V_44 ;
F_227 ( V_5 , V_359 ) ;
F_185 ( V_5 ) ;
F_230 ( V_5 ) ;
V_471 = F_280 ( V_5 ) ;
if ( F_59 ( V_2 ) )
return - V_37 ;
if ( V_2 -> V_4 -> V_100 != V_133 && V_471 ) {
V_2 -> V_230 = 1 ;
F_84 ( V_415 , & V_2 -> V_39 ) ;
F_62 ( V_2 , V_249 ,
V_424 ) ;
F_260 ( V_2 , V_434 , L_58 ) ;
}
F_63 ( V_2 ) ;
V_44 = F_195 ( V_2 ) ;
if ( V_44 )
return V_44 ;
F_254 ( V_2 ) ;
F_7 ( V_2 -> V_58 ) ;
V_2 -> V_58 = NULL ;
V_44 = F_200 ( V_2 , 0 ) ;
if ( V_44 ) {
F_7 ( V_2 -> V_58 ) ;
F_287 ( V_24 , L_25 ) ;
return V_44 ;
}
if ( F_39 ( V_2 ) ) {
F_216 ( V_2 , 1 ) ;
V_44 = F_201 ( V_2 ) ;
if ( V_44 ) {
F_71 ( & V_2 -> V_5 -> V_29 ,
L_84 ) ;
F_209 ( V_2 , 1 ) ;
F_87 ( V_449 , & V_2 -> V_39 ) ;
goto V_360;
}
}
if ( F_133 ( V_24 ) ) {
V_44 = F_149 ( V_2 ) ;
if ( V_44 ) {
F_209 ( V_2 , 1 ) ;
F_87 ( V_449 , & V_2 -> V_39 ) ;
F_18 ( V_24 ) ;
return V_44 ;
}
V_44 = F_131 ( V_2 , V_24 ) ;
if ( V_44 )
goto V_360;
F_86 ( V_24 , V_299 ) ;
}
V_360:
F_18 ( V_24 ) ;
return V_44 ;
}
static T_10 F_288 ( struct V_25 * V_5 ,
T_11 V_39 )
{
struct V_1 * V_2 = F_214 ( V_5 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( V_39 == V_474 )
return V_475 ;
if ( V_39 == V_473 )
return V_476 ;
F_84 ( V_449 , & V_2 -> V_39 ) ;
F_15 ( V_24 ) ;
F_35 ( & V_2 -> V_54 ) ;
if ( F_133 ( V_24 ) )
F_148 ( V_2 , V_24 ) ;
if ( F_39 ( V_2 ) ) {
F_207 ( V_2 ) ;
F_216 ( V_2 , 0 ) ;
F_35 ( & V_2 -> V_355 ) ;
}
F_157 ( V_2 ) ;
F_48 ( V_2 ) ;
F_87 ( V_53 , & V_2 -> V_39 ) ;
F_222 ( V_5 ) ;
F_212 ( V_5 ) ;
return V_477 ;
}
static T_10 F_289 ( struct V_25 * V_5 )
{
return F_286 ( V_5 ) ? V_475 :
V_476 ;
}
static void F_290 ( struct V_25 * V_5 )
{
T_1 V_39 ;
struct V_1 * V_2 = F_214 ( V_5 ) ;
F_291 ( V_5 ) ;
V_39 = F_61 ( V_2 , V_249 ) ;
if ( V_39 == V_250 && F_136 ( V_449 ,
& V_2 -> V_39 ) )
F_204 ( V_2 , V_353 ,
V_354 ) ;
}
static int
F_292 ( struct V_1 * V_2 )
{
int V_44 ;
V_44 = F_106 ( V_2 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_101 ( V_2 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_79 ( V_2 ) ;
if ( V_44 )
return V_44 ;
F_75 ( V_2 ) ;
V_44 = F_90 ( V_2 ) ;
if ( V_44 )
return V_44 ;
V_2 -> V_230 = 0 ;
return V_44 ;
}
int F_293 ( T_2 V_478 , T_2 V_405 )
{
T_1 V_479 ;
if ( V_478 > V_480 ) {
V_478 = V_480 ;
F_21 ( L_85 , V_480 ) ;
}
V_479 = F_41 ( F_46 ( int , V_478 ,
F_47 () ) ) ;
if ( ( V_405 > V_479 ) || ( V_405 < 2 ) || ! F_294 ( V_405 ) ) {
F_21 ( L_86 ,
V_479 ) ;
return - V_37 ;
}
return 0 ;
}
int F_295 ( struct V_1 * V_2 , T_2 V_123 , T_12 V_481 )
{
int V_44 ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( F_14 ( V_53 , & V_2 -> V_39 ) )
return - V_298 ;
F_15 ( V_24 ) ;
if ( F_133 ( V_24 ) )
F_135 ( V_2 , V_24 ) ;
F_157 ( V_2 ) ;
if ( F_39 ( V_2 ) )
F_207 ( V_2 ) ;
F_48 ( V_2 ) ;
V_44 = F_200 ( V_2 , V_123 ) ;
if ( V_44 ) {
F_7 ( V_2 -> V_58 ) ;
F_287 ( V_24 , L_25 ) ;
return V_44 ;
}
if ( F_39 ( V_2 ) ) {
F_216 ( V_2 , 1 ) ;
V_44 = F_201 ( V_2 ) ;
if ( V_44 ) {
F_71 ( & V_2 -> V_5 -> V_29 ,
L_84 ) ;
goto V_360;
}
}
if ( F_133 ( V_24 ) ) {
V_44 = F_149 ( V_2 ) ;
if ( V_44 )
goto V_360;
V_44 = F_123 ( V_2 , V_24 ) ;
if ( V_44 )
goto V_360;
F_86 ( V_24 , V_299 ) ;
}
V_44 = V_481 ;
V_360:
F_18 ( V_24 ) ;
F_87 ( V_53 , & V_2 -> V_39 ) ;
return V_44 ;
}
static void
F_296 ( struct V_1 * V_2 ,
struct V_23 * V_29 , unsigned long V_482 )
{
struct V_483 * V_484 ;
V_484 = F_297 ( V_29 ) ;
if ( ! V_484 )
return;
F_298 (indev) {
switch ( V_482 ) {
case V_299 :
F_299 ( V_2 ,
V_485 -> V_486 , V_487 ) ;
break;
case V_206 :
F_299 ( V_2 ,
V_485 -> V_486 , V_488 ) ;
break;
default:
break;
}
} F_300 ( V_484 ) ;
F_301 ( V_484 ) ;
}
void F_86 ( struct V_23 * V_24 , unsigned long V_482 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
struct V_23 * V_29 ;
T_3 V_204 ;
F_296 ( V_2 , V_24 , V_482 ) ;
F_302 () ;
F_303 (vid, adapter->vlans, VLAN_N_VID) {
V_29 = F_304 ( V_24 , V_204 ) ;
if ( ! V_29 )
continue;
F_296 ( V_2 , V_29 , V_482 ) ;
}
F_305 () ;
}
static int F_306 ( struct V_489 * V_490 ,
unsigned long V_482 , void * V_491 )
{
struct V_1 * V_2 ;
struct V_23 * V_29 = (struct V_23 * ) V_491 ;
V_492:
if ( V_29 == NULL )
goto V_360;
if ( V_29 -> V_493 & V_494 ) {
V_29 = F_307 ( V_29 ) ;
goto V_492;
}
if ( ! F_308 ( V_29 ) )
goto V_360;
V_2 = F_13 ( V_29 ) ;
if ( ! V_2 )
goto V_360;
if ( ! F_14 ( V_38 , & V_2 -> V_39 ) )
goto V_360;
F_296 ( V_2 , V_29 , V_482 ) ;
V_360:
return V_495 ;
}
static int
F_309 ( struct V_489 * V_490 ,
unsigned long V_482 , void * V_491 )
{
struct V_1 * V_2 ;
struct V_23 * V_29 ;
struct V_496 * V_485 = (struct V_496 * ) V_491 ;
V_29 = V_485 -> V_497 ? V_485 -> V_497 -> V_29 : NULL ;
V_492:
if ( V_29 == NULL )
goto V_360;
if ( V_29 -> V_493 & V_494 ) {
V_29 = F_307 ( V_29 ) ;
goto V_492;
}
if ( ! F_308 ( V_29 ) )
goto V_360;
V_2 = F_13 ( V_29 ) ;
if ( ! V_2 )
goto V_360;
if ( ! F_14 ( V_38 , & V_2 -> V_39 ) )
goto V_360;
switch ( V_482 ) {
case V_299 :
F_299 ( V_2 , V_485 -> V_486 , V_487 ) ;
break;
case V_206 :
F_299 ( V_2 , V_485 -> V_486 , V_488 ) ;
break;
default:
break;
}
V_360:
return V_495 ;
}
void F_86 ( struct V_23 * V_29 , unsigned long V_482 )
{ }
static int T_13 F_310 ( void )
{
int V_93 ;
F_311 ( V_498 L_87 , V_499 ) ;
#ifdef F_312
F_313 ( & V_500 ) ;
F_314 ( & V_501 ) ;
#endif
V_93 = F_315 ( & V_502 ) ;
if ( V_93 ) {
#ifdef F_312
F_316 ( & V_501 ) ;
F_317 ( & V_500 ) ;
#endif
}
return V_93 ;
}
static void T_14 F_318 ( void )
{
F_319 ( & V_502 ) ;
#ifdef F_312
F_316 ( & V_501 ) ;
F_317 ( & V_500 ) ;
#endif
}

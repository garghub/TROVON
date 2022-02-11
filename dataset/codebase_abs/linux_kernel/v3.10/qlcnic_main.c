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
int F_8 ( struct V_1 * V_2 )
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
static void F_12 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
F_13 (head, &adapter->mac_list) {
V_31 = F_14 ( V_33 , struct V_30 , V_34 ) ;
if ( ! memcmp ( V_2 -> V_21 , V_31 -> V_21 , V_22 ) ) {
F_15 ( V_2 , V_31 -> V_21 ,
0 , V_35 ) ;
F_16 ( & V_31 -> V_34 ) ;
F_7 ( V_31 ) ;
return;
}
}
}
static int F_17 ( struct V_23 * V_24 , void * V_36 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_37 * V_38 = V_36 ;
if ( F_19 ( V_2 ) )
return - V_39 ;
if ( ( V_2 -> V_40 & V_41 ) )
return - V_42 ;
if ( ! F_10 ( V_38 -> V_43 ) )
return - V_39 ;
if ( ! memcmp ( V_2 -> V_21 , V_38 -> V_43 , V_22 ) )
return 0 ;
if ( F_20 ( V_44 , & V_2 -> V_45 ) ) {
F_21 ( V_24 ) ;
F_22 ( V_2 ) ;
}
F_12 ( V_2 ) ;
memcpy ( V_2 -> V_21 , V_38 -> V_43 , V_24 -> V_28 ) ;
memcpy ( V_24 -> V_27 , V_38 -> V_43 , V_24 -> V_28 ) ;
F_23 ( V_2 -> V_24 ) ;
if ( F_20 ( V_44 , & V_2 -> V_45 ) ) {
F_24 ( V_24 ) ;
F_25 ( V_2 ) ;
}
return 0 ;
}
static int F_26 ( struct V_46 * V_47 , struct V_48 * V_49 [] ,
struct V_23 * V_24 , const unsigned char * V_38 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
int V_50 = - V_42 ;
if ( ! V_2 -> V_51 )
return F_27 ( V_47 , V_49 , V_24 , V_38 ) ;
if ( V_2 -> V_40 & V_52 ) {
if ( F_28 ( V_38 ) )
V_50 = F_29 ( V_2 , V_38 ) ;
else if ( F_30 ( V_38 ) )
V_50 = F_31 ( V_24 , V_38 ) ;
else
V_50 = - V_39 ;
}
return V_50 ;
}
static int F_32 ( struct V_46 * V_47 , struct V_48 * V_49 [] ,
struct V_23 * V_24 ,
const unsigned char * V_38 , T_3 V_40 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
int V_50 = 0 ;
if ( ! V_2 -> V_51 )
return F_33 ( V_47 , V_49 , V_24 , V_38 , V_40 ) ;
if ( ! ( V_2 -> V_40 & V_52 ) ) {
F_34 ( L_2 , V_53 ) ;
return - V_42 ;
}
if ( F_35 ( V_38 , V_2 -> V_21 ) )
return V_50 ;
if ( F_28 ( V_38 ) )
V_50 = F_36 ( V_2 , V_38 , 0 ) ;
else if ( F_30 ( V_38 ) )
V_50 = F_37 ( V_24 , V_38 ) ;
else
V_50 = - V_39 ;
return V_50 ;
}
static int F_38 ( struct V_54 * V_55 , struct V_56 * V_57 ,
struct V_23 * V_24 , int V_58 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
if ( ! V_2 -> V_51 )
return F_39 ( V_55 , V_57 , V_24 , V_58 ) ;
if ( V_2 -> V_40 & V_52 )
V_58 = F_39 ( V_55 , V_57 , V_24 , V_58 ) ;
return V_58 ;
}
static void F_40 ( struct V_1 * V_2 )
{
while ( F_41 ( V_59 , & V_2 -> V_45 ) )
F_42 ( 10000 , 11000 ) ;
F_43 ( & V_2 -> V_60 ) ;
}
int F_44 ( struct V_1 * V_2 , T_1 V_61 )
{
struct V_25 * V_5 = V_2 -> V_5 ;
int V_50 = - 1 , V_62 ;
int V_63 , V_64 ;
if ( V_2 -> V_40 & V_65 ) {
V_63 = 0 ;
V_64 = 0 ;
} else {
V_63 = V_2 -> V_66 ;
V_64 = 1 ;
}
if ( ! V_2 -> V_67 ) {
V_2 -> V_67 = F_45 ( V_61 ,
sizeof( struct V_68 ) ,
V_20 ) ;
if ( ! V_2 -> V_67 )
return - V_69 ;
}
V_2 -> V_70 = 1 ;
V_2 -> V_40 &= ~ ( V_71 | V_72 ) ;
if ( V_2 -> V_4 -> V_73 ) {
V_74:
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ )
V_2 -> V_67 [ V_62 ] . V_75 = V_62 ;
V_50 = F_46 ( V_5 , V_2 -> V_67 , V_61 ) ;
if ( V_50 == 0 ) {
V_2 -> V_40 |= V_72 ;
if ( F_47 ( V_2 ) ) {
V_2 -> V_4 -> V_61 = V_61 ;
V_2 -> V_70 = V_61 -
V_63 - 1 ;
} else {
V_2 -> V_70 = V_61 ;
}
F_48 ( & V_5 -> V_29 , L_3 ) ;
return V_50 ;
} else if ( V_50 > 0 ) {
F_48 ( & V_5 -> V_29 ,
L_4 ,
V_61 ) ;
if ( F_47 ( V_2 ) ) {
if ( V_50 < ( V_76 - V_64 ) )
return V_50 ;
V_50 -= ( V_63 + 1 ) ;
V_61 = F_49 ( V_50 ) ;
V_61 += ( V_63 + 1 ) ;
} else {
V_61 = F_49 ( V_50 ) ;
}
if ( V_61 ) {
F_48 ( & V_5 -> V_29 ,
L_5 ,
V_61 ) ;
goto V_74;
}
} else {
F_48 ( & V_5 -> V_29 ,
L_4 ,
V_61 ) ;
}
}
return V_50 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_50 = 0 ;
T_1 V_77 , V_78 ;
const struct V_79 * V_80 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_25 * V_5 = V_2 -> V_5 ;
if ( V_81 && ! F_51 ( V_5 ) ) {
V_2 -> V_40 |= V_71 ;
V_77 = V_82 [ V_2 -> V_4 -> V_83 ] ;
V_2 -> V_84 = F_52 ( V_2 -> V_4 ,
V_77 ) ;
F_48 ( & V_5 -> V_29 , L_6 ) ;
V_2 -> V_67 [ 0 ] . V_85 = V_5 -> V_86 ;
return V_50 ;
}
if ( V_81 || V_87 )
return - V_42 ;
V_80 = & V_88 [ V_2 -> V_4 -> V_83 ] ;
V_2 -> V_4 -> V_89 = V_80 -> V_89 ;
V_77 = V_80 -> V_84 ;
V_2 -> V_84 = F_52 ( V_4 , V_77 ) ;
V_78 = V_80 -> V_90 ;
V_2 -> V_90 = F_52 ( V_4 , V_78 ) ;
V_2 -> V_91 = F_52 ( V_4 , V_92 ) ;
V_2 -> V_93 = F_52 ( V_4 , V_94 ) ;
F_48 ( & V_5 -> V_29 , L_7 ) ;
V_2 -> V_67 [ 0 ] . V_85 = V_5 -> V_86 ;
return V_50 ;
}
int F_53 ( struct V_1 * V_2 , T_2 V_95 )
{
int V_61 , V_50 = 0 ;
if ( ! V_95 )
V_95 = V_96 ;
if ( V_2 -> V_4 -> V_73 )
V_61 = F_49 ( F_54 ( int , F_55 () ,
V_95 ) ) ;
else
V_61 = 1 ;
V_50 = F_44 ( V_2 , V_61 ) ;
if ( V_50 == - V_69 || ! V_50 )
return V_50 ;
V_50 = F_50 ( V_2 ) ;
if ( ! V_50 )
return V_50 ;
return - V_26 ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 & V_72 )
F_57 ( V_2 -> V_5 ) ;
if ( V_2 -> V_40 & V_71 )
F_58 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
if ( V_2 -> V_4 -> V_97 ) {
F_59 ( V_2 -> V_4 -> V_97 ) ;
V_2 -> V_4 -> V_97 = NULL ;
}
}
static void F_60 ( struct V_3 * V_4 )
{
if ( V_4 -> V_98 != NULL )
F_61 ( V_4 -> V_98 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_99 * V_100 ;
int V_101 ;
if ( ! ( V_2 -> V_40 & V_52 ) ) {
switch ( V_2 -> V_4 -> V_102 ) {
case V_103 :
V_2 -> V_4 -> V_104 = V_105 ;
break;
case V_106 :
V_2 -> V_4 -> V_104 = V_107 ;
break;
}
return 0 ;
}
if ( V_2 -> V_4 -> V_108 == V_109 )
return 0 ;
V_100 = F_45 ( V_110 , sizeof( * V_100 ) , V_20 ) ;
if ( ! V_100 )
return - V_69 ;
V_101 = F_63 ( V_2 , V_100 ) ;
F_7 ( V_100 ) ;
return V_101 ;
}
int F_64 ( struct V_1 * V_2 )
{
struct V_99 * V_100 ;
int V_62 , V_101 = 0 , V_111 = 0 ;
T_3 V_104 ;
T_2 V_112 ;
V_100 = F_45 ( V_110 , sizeof( * V_100 ) , V_20 ) ;
if ( ! V_100 )
return - V_69 ;
V_101 = F_63 ( V_2 , V_100 ) ;
if ( V_101 )
goto V_113;
V_104 = V_2 -> V_4 -> V_104 ;
V_2 -> V_114 = F_5 ( sizeof( struct V_115 ) *
V_104 , V_20 ) ;
if ( ! V_2 -> V_114 ) {
V_101 = - V_69 ;
goto V_113;
}
V_2 -> V_116 = F_5 ( sizeof( struct V_117 ) *
V_107 , V_20 ) ;
if ( ! V_2 -> V_116 ) {
V_101 = - V_69 ;
goto V_118;
}
for ( V_62 = 0 ; V_62 < V_110 ; V_62 ++ ) {
V_112 = V_100 [ V_62 ] . V_119 ;
if ( V_112 >= V_110 ) {
V_101 = V_120 ;
goto V_121;
}
if ( ! V_100 [ V_62 ] . V_122 ||
( V_100 [ V_62 ] . type != V_123 ) )
continue;
V_2 -> V_114 [ V_111 ] . V_83 = V_112 ;
V_2 -> V_114 [ V_111 ] . V_122 = ( T_2 ) V_100 [ V_62 ] . V_122 ;
V_2 -> V_114 [ V_111 ] . type = ( T_2 ) V_100 [ V_62 ] . type ;
V_2 -> V_114 [ V_111 ] . V_124 = ( T_2 ) V_100 [ V_62 ] . V_125 ;
V_2 -> V_114 [ V_111 ] . V_126 = V_100 [ V_62 ] . V_127 ;
V_2 -> V_114 [ V_111 ] . V_128 = V_100 [ V_62 ] . V_129 ;
V_111 ++ ;
}
for ( V_62 = 0 ; V_62 < V_107 ; V_62 ++ ) {
V_2 -> V_116 [ V_62 ] . V_40 |= V_130 ;
if ( F_47 ( V_2 ) )
F_65 ( V_2 , V_62 , 1 ) ;
}
F_7 ( V_100 ) ;
return 0 ;
V_121:
F_7 ( V_2 -> V_116 ) ;
V_2 -> V_116 = NULL ;
V_118:
F_7 ( V_2 -> V_114 ) ;
V_2 -> V_114 = NULL ;
V_113:
F_7 ( V_100 ) ;
return V_101 ;
}
static int
F_66 ( struct V_1 * V_2 )
{
T_2 V_119 ;
int V_62 , V_101 = 1 ;
T_1 V_131 = V_109 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_101 = F_67 ( V_2 ) ;
if ( V_101 )
goto V_132;
if ( V_133 ) {
for ( V_62 = 0 ; V_62 < V_4 -> V_104 ; V_62 ++ ) {
V_119 = V_2 -> V_114 [ V_62 ] . V_83 ;
if ( V_119 == V_4 -> V_83 )
continue;
V_131 |= ( V_133 &
F_68 ( 0xf , V_119 ) ) ;
}
} else {
V_131 = F_69 ( V_2 , V_134 ) ;
V_131 = ( V_131 & ~ F_68 ( 0xf , V_4 -> V_83 ) ) |
( F_68 ( V_109 ,
V_4 -> V_83 ) ) ;
}
F_70 ( V_2 , V_134 , V_131 ) ;
F_71 ( V_2 ) ;
V_132:
return V_101 ;
}
static void F_72 ( struct V_1 * V_2 ,
const struct V_135 * V_136 )
{
T_1 V_108 , V_137 ;
V_2 -> V_4 -> V_138 = F_69 ( V_2 ,
V_139 ) ;
F_73 ( V_2 ) ;
V_108 = F_69 ( V_2 , V_134 ) ;
if ( V_108 == V_140 )
V_137 = V_109 ;
else
V_137 = F_74 ( V_108 , V_2 -> V_4 -> V_83 ) ;
if ( V_137 == V_141 ) {
V_2 -> V_4 -> V_108 = V_141 ;
F_48 ( & V_2 -> V_5 -> V_29 ,
L_8 ,
V_2 -> V_4 -> V_138 ) ;
V_2 -> V_142 = & V_143 ;
} else
V_2 -> V_142 = & V_144 ;
}
static void F_75 ( T_1 V_145 , T_4 * V_146 )
{
switch ( V_145 ) {
case V_7 :
* V_146 = V_147 ;
break;
case V_148 :
case V_149 :
* V_146 = V_150 ;
break;
default:
* V_146 = 0 ;
}
}
static int F_76 ( struct V_25 * V_5 ,
struct V_3 * V_4 )
{
T_1 V_77 ;
void T_5 * V_151 = NULL ;
unsigned long V_152 , V_153 = 0 , V_154 ;
V_152 = F_77 ( V_5 , 0 ) ;
F_75 ( V_5 -> V_6 , & V_154 ) ;
if ( V_152 >= V_154 ) {
V_151 = F_78 ( V_5 , 0 ) ;
if ( V_151 == NULL ) {
F_79 ( & V_5 -> V_29 , L_9 ) ;
return - V_26 ;
}
V_153 = V_152 ;
} else {
return - V_26 ;
}
F_48 ( & V_5 -> V_29 , L_10 , ( int ) ( V_152 >> 10 ) ) ;
V_4 -> V_98 = V_151 ;
V_4 -> V_153 = V_153 ;
V_77 = F_80 ( F_81 ( V_4 -> V_83 ) ) ;
F_52 ( V_4 , V_77 ) ;
return 0 ;
}
static void F_82 ( struct V_1 * V_2 , char * V_155 )
{
struct V_25 * V_5 = V_2 -> V_5 ;
int V_62 , V_156 = 0 ;
for ( V_62 = 0 ; V_62 < V_157 ; ++ V_62 ) {
if ( V_158 [ V_62 ] . V_159 == V_5 -> V_159 &&
V_158 [ V_62 ] . V_6 == V_5 -> V_6 &&
V_158 [ V_62 ] . V_160 == V_5 -> V_161 &&
V_158 [ V_62 ] . V_162 == V_5 -> V_163 ) {
sprintf ( V_155 , L_11 ,
V_2 -> V_21 ,
V_158 [ V_62 ] . V_164 ) ;
V_156 = 1 ;
break;
}
}
if ( ! V_156 )
sprintf ( V_155 , L_12 , V_2 -> V_21 ) ;
}
static void
F_83 ( struct V_1 * V_2 )
{
int V_50 ;
T_1 V_165 , V_166 , V_167 , V_168 ;
struct V_25 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_169 * V_170 = & V_4 -> V_170 ;
V_168 = V_2 -> V_171 ;
V_165 = F_69 ( V_2 , V_172 ) ;
V_166 = F_69 ( V_2 , V_173 ) ;
V_167 = F_69 ( V_2 , V_174 ) ;
V_2 -> V_171 = F_84 ( V_165 , V_166 , V_167 ) ;
V_50 = F_85 ( V_2 ) ;
if ( V_50 ) {
F_79 ( & V_5 -> V_29 , L_13 ) ;
return;
}
if ( V_4 -> V_108 != V_141 ) {
if ( V_170 -> V_175 == NULL ||
V_2 -> V_171 > V_168 ) {
if ( V_170 -> V_175 )
F_59 ( V_170 -> V_175 ) ;
if ( ! F_86 ( V_2 ) )
F_48 ( & V_5 -> V_29 ,
L_14 ) ;
}
}
F_48 ( & V_5 -> V_29 , L_15 ,
V_176 , V_165 , V_166 , V_167 ) ;
if ( V_2 -> V_4 -> V_102 == V_106 ) {
if ( V_2 -> V_40 & V_52 ) {
V_2 -> V_177 = V_178 ;
V_2 -> V_179 = V_180 ;
} else {
V_2 -> V_177 = V_181 ;
V_2 -> V_179 = V_182 ;
}
V_2 -> V_183 = V_184 ;
V_2 -> V_185 = V_184 ;
} else if ( V_2 -> V_4 -> V_102 == V_103 ) {
V_2 -> V_177 = V_186 ;
V_2 -> V_183 = V_187 ;
V_2 -> V_185 = V_187 ;
V_2 -> V_179 = V_188 ;
}
V_2 -> V_4 -> V_73 = ! ! V_87 ;
V_2 -> V_189 = V_190 ;
V_2 -> V_191 = V_192 ;
}
static int
F_87 ( struct V_1 * V_2 )
{
int V_50 ;
struct V_193 V_194 ;
memset ( & V_194 , 0 , sizeof( struct V_193 ) ) ;
V_50 = F_88 ( V_2 , & V_194 , V_2 -> V_4 -> V_83 ) ;
if ( V_50 )
return V_50 ;
V_2 -> V_4 -> V_195 = ( T_2 ) V_194 . V_196 ;
V_2 -> V_4 -> V_197 = V_194 . V_197 ;
V_2 -> V_4 -> V_198 = V_194 . V_198 ;
V_2 -> V_4 -> V_199 = V_194 . V_199 ;
V_2 -> V_4 -> V_8 = V_194 . V_8 ;
if ( V_2 -> V_4 -> V_8 & V_200 ) {
T_1 V_201 ;
V_201 = F_89 ( V_2 , V_202 ) ;
V_2 -> V_4 -> V_203 = V_201 ;
}
V_2 -> V_4 -> V_204 = V_194 . V_204 ;
V_2 -> V_4 -> V_205 = V_194 . V_205 ;
if ( F_47 ( V_2 ) )
return V_50 ;
if ( V_2 -> V_4 -> V_8 & V_206 )
V_2 -> V_40 |= V_52 ;
else
V_2 -> V_40 &= ~ V_52 ;
return V_50 ;
}
void F_90 ( struct V_1 * V_2 ,
struct V_207 * V_208 )
{
if ( V_208 -> V_209 )
V_2 -> V_40 &= ~ V_210 ;
else
V_2 -> V_40 |= V_210 ;
if ( V_208 -> V_211 ) {
V_2 -> V_212 = V_208 -> V_211 ;
V_2 -> V_213 = V_208 -> V_211 ;
} else {
V_2 -> V_212 = 0 ;
V_2 -> V_213 = 0 ;
}
}
static int
F_91 ( struct V_23 * V_24 , T_6 V_214 , T_3 V_215 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
int V_50 ;
if ( F_19 ( V_2 ) ) {
V_50 = F_92 ( V_2 , V_215 , 1 ) ;
if ( V_50 ) {
F_93 ( V_24 ,
L_16 ,
V_215 , V_50 ) ;
return V_50 ;
}
}
F_94 ( V_215 , V_2 -> V_216 ) ;
return 0 ;
}
static int
F_95 ( struct V_23 * V_24 , T_6 V_214 , T_3 V_215 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
int V_50 ;
if ( F_19 ( V_2 ) ) {
V_50 = F_92 ( V_2 , V_215 , 0 ) ;
if ( V_50 ) {
F_93 ( V_24 ,
L_17 ,
V_215 , V_50 ) ;
return V_50 ;
}
}
F_96 ( V_24 , V_217 ) ;
F_97 ( V_215 , V_2 -> V_216 ) ;
return 0 ;
}
void F_98 ( struct V_1 * V_2 ,
struct V_207 * V_208 )
{
V_2 -> V_40 &= ~ ( V_218 | V_41 |
V_219 ) ;
if ( V_208 -> V_220 )
V_2 -> V_40 |= V_218 ;
if ( ! V_208 -> V_221 )
V_2 -> V_40 |= V_41 ;
if ( ! V_208 -> V_222 )
V_2 -> V_40 |= V_219 ;
}
int F_99 ( struct V_1 * V_2 )
{
struct V_207 V_208 ;
if ( ! ( V_2 -> V_40 & V_52 ) )
return 0 ;
V_208 . V_83 = V_2 -> V_4 -> V_83 ;
if ( F_100 ( V_2 , & V_208 ) )
return - V_26 ;
F_90 ( V_2 , & V_208 ) ;
F_98 ( V_2 , & V_208 ) ;
F_101 ( V_2 , & V_208 ) ;
return 0 ;
}
void F_101 ( struct V_1 * V_2 ,
struct V_207 * V_208 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
if ( F_47 ( V_2 ) )
return;
V_2 -> V_223 = V_208 -> V_223 ;
V_2 -> V_40 |= V_224 ;
F_102 ( V_24 ) ;
V_2 -> V_40 &= ~ V_224 ;
}
static int
F_103 ( struct V_1 * V_2 )
{
T_1 V_108 , V_137 ;
int V_50 = 0 ;
V_50 = F_87 ( V_2 ) ;
if ( V_50 )
return V_50 ;
if ( V_2 -> V_40 & V_225 )
return 0 ;
V_108 = F_69 ( V_2 , V_134 ) ;
V_137 = F_74 ( V_108 , V_2 -> V_4 -> V_83 ) ;
if ( V_108 == V_140 )
V_137 = V_109 ;
else
V_137 = F_74 ( V_108 , V_2 -> V_4 -> V_83 ) ;
if ( V_2 -> V_40 & V_52 ) {
if ( V_137 == V_109 ) {
V_2 -> V_4 -> V_108 = V_109 ;
V_50 = F_64 ( V_2 ) ;
if ( V_50 )
return V_50 ;
F_66 ( V_2 ) ;
F_48 ( & V_2 -> V_5 -> V_29 ,
L_18 ,
V_2 -> V_4 -> V_138 ) ;
} else if ( V_137 == V_226 ) {
V_2 -> V_4 -> V_108 = V_226 ;
F_48 ( & V_2 -> V_5 -> V_29 ,
L_19 ,
V_2 -> V_4 -> V_138 ) ;
}
}
V_2 -> V_40 |= V_225 ;
return V_50 ;
}
int F_104 ( struct V_1 * V_2 )
{
struct V_207 V_208 ;
struct V_115 * V_227 ;
T_2 V_62 ;
if ( V_2 -> V_228 )
return 0 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_4 -> V_104 ; V_62 ++ ) {
memset ( & V_208 , 0 , sizeof( struct V_207 ) ) ;
V_208 . V_83 = V_2 -> V_114 [ V_62 ] . V_83 ;
V_208 . V_221 = V_229 ;
V_208 . V_222 = V_229 ;
if ( F_105 ( V_2 ) ) {
V_208 . V_223 = V_229 ;
if ( F_106 ( V_2 ) )
V_208 . V_223 |= ( V_230 | V_231 ) ;
}
if ( F_107 ( V_2 , & V_208 ) )
return - V_26 ;
V_227 = & V_2 -> V_114 [ V_62 ] ;
V_227 -> V_232 = V_208 . V_211 ;
V_227 -> V_221 = V_208 . V_221 ;
V_227 -> V_220 = V_208 . V_220 ;
V_227 -> V_209 = V_208 . V_209 ;
V_227 -> V_222 = V_208 . V_222 ;
V_227 -> V_223 = V_208 . V_223 ;
}
return 0 ;
}
static int
F_108 ( struct V_1 * V_2 ,
struct V_115 * V_227 , int V_83 )
{
struct V_207 V_208 ;
V_208 . V_108 = V_233 ;
V_208 . V_83 = V_83 ;
V_208 . V_211 = V_227 -> V_232 ;
V_208 . V_221 = V_227 -> V_221 ;
V_208 . V_209 = V_227 -> V_209 ;
V_208 . V_220 = V_227 -> V_220 ;
V_208 . V_223 = V_227 -> V_223 ;
V_208 . V_222 = V_227 -> V_222 ;
if ( F_107 ( V_2 , & V_208 ) )
return - V_26 ;
V_208 . V_108 = V_234 ;
if ( F_107 ( V_2 , & V_208 ) )
return - V_26 ;
return 0 ;
}
int F_109 ( struct V_1 * V_2 )
{
int V_62 , V_50 ;
struct V_115 * V_227 ;
struct V_193 V_194 ;
T_2 V_83 ;
if ( F_105 ( V_2 ) )
if ( ! V_2 -> V_228 )
return 0 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_4 -> V_104 ; V_62 ++ ) {
V_227 = & V_2 -> V_114 [ V_62 ] ;
V_83 = V_227 -> V_83 ;
memset ( & V_194 , 0 , sizeof( struct V_193 ) ) ;
V_50 = F_88 ( V_2 , & V_194 , V_83 ) ;
if ( V_50 )
return V_50 ;
V_194 . V_235 = V_227 -> V_126 ;
V_194 . V_236 = V_227 -> V_128 ;
V_50 = F_110 ( V_2 , & V_194 ) ;
if ( V_50 )
return V_50 ;
if ( V_227 -> V_237 ) {
V_50 = F_111 ( V_2 ,
V_227 -> V_238 , 1 ,
V_83 ) ;
if ( V_50 )
return V_50 ;
}
V_50 = F_108 ( V_2 , V_227 , V_83 ) ;
if ( V_50 )
return V_50 ;
}
return 0 ;
}
static int F_112 ( struct V_1 * V_2 )
{
T_2 V_239 = V_240 ;
T_1 V_241 ;
if ( V_2 -> V_4 -> V_108 == V_109 )
return 0 ;
V_241 = F_69 ( V_2 ,
V_242 ) ;
while ( V_241 != V_243 && -- V_239 ) {
F_113 ( 1000 ) ;
V_241 = F_69 ( V_2 ,
V_242 ) ;
}
if ( ! V_239 ) {
F_79 ( & V_2 -> V_5 -> V_29 ,
L_20 ) ;
return - V_26 ;
}
return 0 ;
}
static int
F_114 ( struct V_1 * V_2 )
{
int V_50 ;
if ( ! ( V_2 -> V_40 & V_52 ) ||
V_2 -> V_4 -> V_108 != V_109 )
return 0 ;
V_50 = F_104 ( V_2 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_109 ( V_2 ) ;
if ( V_50 )
return V_50 ;
F_115 ( V_2 ) ;
return V_50 ;
}
int F_116 ( struct V_1 * V_2 )
{
int V_50 ;
V_50 = F_117 ( V_2 ) ;
if ( V_50 < 0 )
return V_50 ;
else if ( ! V_50 )
goto V_244;
if ( V_245 )
F_118 ( V_2 ) ;
else {
V_50 = F_119 ( V_2 ) ;
if ( V_50 )
goto V_246;
V_2 -> V_4 -> V_247 = V_248 ;
}
V_50 = F_120 ( V_2 ) ;
if ( V_50 == 0 )
goto V_244;
V_50 = F_121 ( V_2 ) ;
if ( V_50 )
goto V_246;
V_50 = F_122 ( V_2 ) ;
if ( V_50 )
goto V_246;
F_123 ( V_2 ) ;
F_124 ( V_2 , V_249 , V_250 ) ;
V_244:
V_50 = F_125 ( V_2 ) ;
if ( V_50 )
goto V_246;
F_70 ( V_2 , V_251 , V_252 ) ;
F_126 ( V_2 , 1 ) ;
V_50 = F_103 ( V_2 ) ;
if ( V_50 ) {
F_79 ( & V_2 -> V_5 -> V_29 ,
L_21 ) ;
goto V_246;
}
V_50 = F_114 ( V_2 ) ;
if ( V_50 )
goto V_246;
F_83 ( V_2 ) ;
V_2 -> V_228 = 0 ;
F_123 ( V_2 ) ;
return 0 ;
V_246:
F_70 ( V_2 , V_251 , V_253 ) ;
F_79 ( & V_2 -> V_5 -> V_29 , L_22 ) ;
F_123 ( V_2 ) ;
return V_50 ;
}
static int
F_127 ( struct V_1 * V_2 )
{
T_7 V_254 ;
struct V_18 * V_255 ;
struct V_10 * V_11 ;
int V_50 , V_256 , V_257 ;
unsigned long V_40 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_258 == V_259 ) {
if ( F_105 ( V_2 ) )
V_254 = V_260 ;
if ( ! F_128 ( V_2 ) )
V_40 |= V_261 ;
} else {
if ( V_2 -> V_40 & V_72 )
V_254 = V_262 ;
else if ( V_2 -> V_40 & V_71 )
V_254 = V_263 ;
else {
V_40 |= V_261 ;
if ( F_105 ( V_2 ) )
V_254 = V_264 ;
else
V_254 = V_265 ;
}
}
V_2 -> V_86 = V_24 -> V_86 ;
if ( V_2 -> V_4 -> V_258 != V_266 ) {
if ( F_105 ( V_2 ) ||
( F_47 ( V_2 ) &&
( V_2 -> V_40 & V_72 ) ) ) {
V_257 = V_2 -> V_70 ;
for ( V_256 = 0 ; V_256 < V_257 ; V_256 ++ ) {
V_255 = & V_15 -> V_19 [ V_256 ] ;
if ( F_105 ( V_2 ) &&
( V_256 == ( V_257 - 1 ) ) )
snprintf ( V_255 -> V_155 ,
sizeof( V_255 -> V_155 ) ,
L_23 ,
V_24 -> V_155 , V_256 ) ;
else
snprintf ( V_255 -> V_155 ,
sizeof( V_255 -> V_155 ) ,
L_24 ,
V_24 -> V_155 , V_256 ) ;
V_50 = F_129 ( V_255 -> V_86 , V_254 , V_40 ,
V_255 -> V_155 , V_255 ) ;
if ( V_50 )
return V_50 ;
}
}
if ( F_47 ( V_2 ) &&
( V_2 -> V_40 & V_72 ) &&
! ( V_2 -> V_40 & V_65 ) ) {
V_254 = V_267 ;
for ( V_256 = 0 ; V_256 < V_2 -> V_66 ;
V_256 ++ ) {
V_11 = & V_2 -> V_11 [ V_256 ] ;
snprintf ( V_11 -> V_155 , sizeof( V_11 -> V_155 ) ,
L_25 , V_24 -> V_155 , V_256 ) ;
V_50 = F_129 ( V_11 -> V_86 , V_254 , V_40 ,
V_11 -> V_155 , V_11 ) ;
if ( V_50 )
return V_50 ;
}
}
}
return 0 ;
}
static void
F_130 ( struct V_1 * V_2 )
{
int V_256 ;
struct V_18 * V_255 ;
struct V_10 * V_11 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_258 != V_266 ) {
if ( F_105 ( V_2 ) ||
( F_47 ( V_2 ) &&
( V_2 -> V_40 & V_72 ) ) ) {
for ( V_256 = 0 ; V_256 < V_2 -> V_70 ; V_256 ++ ) {
V_255 = & V_15 -> V_19 [ V_256 ] ;
F_131 ( V_255 -> V_86 , V_255 ) ;
}
}
if ( F_47 ( V_2 ) &&
! ( V_2 -> V_40 & V_65 ) ) {
for ( V_256 = 0 ; V_256 < V_2 -> V_66 ;
V_256 ++ ) {
V_11 = & V_2 -> V_11 [ V_256 ] ;
if ( V_11 -> V_86 )
F_131 ( V_11 -> V_86 , V_11 ) ;
}
}
}
}
static void F_132 ( struct V_1 * V_2 )
{
T_1 V_268 = 0 ;
if ( F_105 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_203 &
V_269 )
V_2 -> V_40 |= V_270 ;
} else {
V_268 = V_2 -> V_4 -> V_8 ;
if ( F_133 ( V_268 ) )
V_2 -> V_40 |= V_270 ;
}
}
int F_134 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
int V_256 ;
struct V_271 * V_272 ;
if ( V_2 -> V_273 != V_274 )
return - V_26 ;
if ( F_20 ( V_44 , & V_2 -> V_45 ) )
return 0 ;
if ( F_99 ( V_2 ) )
return - V_26 ;
F_132 ( V_2 ) ;
if ( F_135 ( V_2 ) )
return - V_26 ;
for ( V_256 = 0 ; V_256 < V_2 -> V_191 ; V_256 ++ ) {
V_272 = & V_2 -> V_15 -> V_275 [ V_256 ] ;
F_136 ( V_2 , V_272 , V_256 ) ;
}
F_23 ( V_24 ) ;
F_137 ( V_2 , V_24 -> V_276 ) ;
V_2 -> V_4 -> V_277 = 0 ;
if ( V_2 -> V_70 > 1 )
F_138 ( V_2 , 1 ) ;
F_139 ( V_2 ) ;
if ( V_24 -> V_278 & V_279 )
F_140 ( V_2 , V_280 ) ;
F_25 ( V_2 ) ;
F_141 ( V_2 , 1 ) ;
V_2 -> V_4 -> V_281 = 0 ;
F_94 ( V_44 , & V_2 -> V_45 ) ;
return 0 ;
}
int F_142 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
int V_50 = 0 ;
F_143 () ;
if ( F_144 ( V_24 ) )
V_50 = F_134 ( V_2 , V_24 ) ;
F_145 () ;
return V_50 ;
}
void F_146 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
if ( V_2 -> V_273 != V_274 )
return;
if ( ! F_147 ( V_44 , & V_2 -> V_45 ) )
return;
if ( F_19 ( V_2 ) )
F_148 ( & V_2 -> V_4 -> V_282 -> V_283 ) ;
F_149 () ;
F_150 ( & V_2 -> V_284 ) ;
F_151 ( V_24 ) ;
V_2 -> V_4 -> V_277 = 0 ;
F_152 ( V_24 ) ;
F_153 ( V_2 ) ;
if ( V_2 -> V_285 . V_286 )
F_154 ( V_2 ) ;
F_155 ( V_2 , V_287 ) ;
F_22 ( V_2 ) ;
F_156 ( V_2 ) ;
V_2 -> V_40 &= ~ V_270 ;
F_157 ( V_2 ) ;
F_158 ( V_2 ) ;
F_159 ( & V_2 -> V_284 ) ;
}
void F_160 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
F_143 () ;
if ( F_144 ( V_24 ) )
F_146 ( V_2 , V_24 ) ;
F_145 () ;
}
int
F_161 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_25 * V_5 = V_2 -> V_5 ;
int V_50 ;
if ( V_2 -> V_273 == V_274 )
return 0 ;
V_50 = F_162 ( V_2 , V_24 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_163 ( V_2 ) ;
if ( V_50 ) {
F_79 ( & V_5 -> V_29 , L_26 ) ;
goto V_288;
}
V_50 = F_164 ( V_2 ) ;
if ( V_50 ) {
F_79 ( & V_5 -> V_29 , L_27 ) ;
goto V_289;
}
V_50 = F_127 ( V_2 ) ;
if ( V_50 ) {
F_79 ( & V_5 -> V_29 , L_28 ) ;
goto V_290;
}
F_165 ( V_2 ) ;
V_2 -> V_273 = V_274 ;
return 0 ;
V_290:
F_166 ( V_2 ) ;
V_289:
F_167 ( V_2 ) ;
V_288:
F_168 ( V_2 ) ;
return V_50 ;
}
void F_169 ( struct V_1 * V_2 )
{
if ( V_2 -> V_273 != V_274 )
return;
F_170 ( V_2 ) ;
F_166 ( V_2 ) ;
F_171 ( V_2 ) ;
F_130 ( V_2 ) ;
F_168 ( V_2 ) ;
F_167 ( V_2 ) ;
V_2 -> V_273 = 0 ;
}
void F_172 ( struct V_23 * V_24 , int V_70 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_18 * V_255 ;
int V_256 ;
F_97 ( V_44 , & V_2 -> V_45 ) ;
if ( V_2 -> V_4 -> V_258 == V_259 ) {
for ( V_256 = 0 ; V_256 < V_2 -> V_70 ; V_256 ++ ) {
V_255 = & V_2 -> V_15 -> V_19 [ V_256 ] ;
F_173 ( V_255 ) ;
}
}
F_156 ( V_2 ) ;
F_169 ( V_2 ) ;
V_2 -> V_4 -> V_258 = 0 ;
V_2 -> V_70 = V_70 ;
if ( F_161 ( V_2 ) )
goto V_291;
if ( F_144 ( V_24 ) )
F_134 ( V_2 , V_24 ) ;
V_291:
F_24 ( V_24 ) ;
}
static int F_174 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_50 = 0 ;
V_2 -> V_15 = F_5 ( sizeof( struct V_14 ) ,
V_20 ) ;
if ( ! V_2 -> V_15 ) {
V_50 = - V_69 ;
goto V_246;
}
V_4 -> V_292 . V_293 = V_294 ;
V_4 -> V_292 . type = V_295 ;
V_4 -> V_292 . V_296 = V_297 ;
V_4 -> V_292 . V_298 = V_299 ;
if ( F_47 ( V_2 ) ) {
V_4 -> V_292 . V_300 = V_301 ;
V_4 -> V_292 . V_302 = V_303 ;
}
memset ( & V_2 -> V_304 , 0 , sizeof( V_2 -> V_304 ) ) ;
V_246:
return V_50 ;
}
static void F_175 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_2 -> V_4 -> V_170 . V_175 ) {
F_59 ( V_2 -> V_4 -> V_170 . V_175 ) ;
V_2 -> V_4 -> V_170 . V_175 = NULL ;
}
F_7 ( V_2 -> V_4 -> V_305 . V_306 ) ;
V_2 -> V_4 -> V_170 . V_175 = NULL ;
}
int F_176 ( struct V_23 * V_24 , int V_307 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_18 * V_255 ;
struct V_271 * V_272 ;
int V_256 ;
int V_101 ;
F_21 ( V_24 ) ;
if ( F_144 ( V_24 ) )
F_146 ( V_2 , V_24 ) ;
F_169 ( V_2 ) ;
V_2 -> V_70 = 1 ;
V_2 -> V_4 -> V_258 = V_307 ;
V_2 -> V_4 -> V_277 = 0 ;
V_101 = F_161 ( V_2 ) ;
if ( V_101 ) {
F_24 ( V_24 ) ;
return V_101 ;
}
V_101 = F_135 ( V_2 ) ;
if ( V_101 ) {
F_169 ( V_2 ) ;
F_24 ( V_24 ) ;
return V_101 ;
}
for ( V_256 = 0 ; V_256 < V_2 -> V_191 ; V_256 ++ ) {
V_272 = & V_2 -> V_15 -> V_275 [ V_256 ] ;
F_136 ( V_2 , V_272 , V_256 ) ;
}
if ( V_2 -> V_4 -> V_258 == V_259 ) {
for ( V_256 = 0 ; V_256 < V_2 -> V_70 ; V_256 ++ ) {
V_255 = & V_2 -> V_15 -> V_19 [ V_256 ] ;
F_177 ( V_255 ) ;
}
}
if ( V_2 -> V_4 -> V_258 == V_266 ) {
V_2 -> V_4 -> V_308 = 0 ;
F_141 ( V_2 , 1 ) ;
}
F_94 ( V_44 , & V_2 -> V_45 ) ;
return 0 ;
}
static int
F_178 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
if ( F_41 ( V_59 , & V_2 -> V_45 ) )
return - V_309 ;
F_21 ( V_24 ) ;
F_160 ( V_2 , V_24 ) ;
F_142 ( V_2 , V_24 ) ;
F_24 ( V_24 ) ;
F_97 ( V_59 , & V_2 -> V_45 ) ;
F_79 ( & V_2 -> V_5 -> V_29 , L_29 , V_53 ) ;
return 0 ;
}
int
F_179 ( struct V_1 * V_2 )
{
int V_50 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( F_41 ( V_59 , & V_2 -> V_45 ) )
return - V_309 ;
if ( V_2 -> V_273 == V_274 ) {
F_21 ( V_24 ) ;
if ( F_144 ( V_24 ) )
F_146 ( V_2 , V_24 ) ;
F_169 ( V_2 ) ;
if ( F_144 ( V_24 ) ) {
V_50 = F_161 ( V_2 ) ;
if ( ! V_50 ) {
F_134 ( V_2 , V_24 ) ;
F_96 ( V_24 , V_310 ) ;
}
}
F_24 ( V_24 ) ;
}
F_97 ( V_59 , & V_2 -> V_45 ) ;
return V_50 ;
}
int
F_180 ( struct V_1 * V_2 , struct V_23 * V_24 ,
int V_311 )
{
int V_50 ;
struct V_25 * V_5 = V_2 -> V_5 ;
V_2 -> V_312 = 1 ;
V_2 -> V_4 -> V_313 = 0 ;
V_2 -> V_4 -> V_314 = V_315 ;
V_24 -> V_316 = & V_317 ;
V_24 -> V_318 = V_319 * V_320 ;
F_181 ( V_24 , V_24 -> V_276 ) ;
if ( F_19 ( V_2 ) )
F_182 ( V_24 , & V_321 ) ;
else
F_182 ( V_24 , & V_322 ) ;
V_24 -> V_278 |= ( V_323 | V_324 | V_325 |
V_326 | V_327 |
V_328 ) ;
V_24 -> V_329 |= ( V_323 | V_324 |
V_326 ) ;
if ( F_106 ( V_2 ) ) {
V_24 -> V_278 |= ( V_330 | V_331 ) ;
V_24 -> V_329 |= ( V_330 | V_331 ) ;
}
if ( V_311 ) {
V_24 -> V_278 |= V_332 ;
V_24 -> V_329 |= V_332 ;
}
if ( F_1 ( V_2 ) )
V_24 -> V_278 |= ( V_333 ) ;
if ( F_19 ( V_2 ) )
V_24 -> V_278 |= V_334 ;
if ( V_2 -> V_4 -> V_8 & V_335 )
V_24 -> V_278 |= V_279 ;
V_24 -> V_336 = V_24 -> V_278 ;
V_24 -> V_86 = V_2 -> V_67 [ 0 ] . V_85 ;
V_50 = F_183 ( V_24 ) ;
if ( V_50 ) {
F_79 ( & V_5 -> V_29 , L_30 ) ;
return V_50 ;
}
return 0 ;
}
static int F_184 ( struct V_25 * V_5 , int * V_311 )
{
if ( ! F_185 ( V_5 , F_186 ( 64 ) ) &&
! F_187 ( V_5 , F_186 ( 64 ) ) )
* V_311 = 1 ;
else if ( ! F_185 ( V_5 , F_186 ( 32 ) ) &&
! F_187 ( V_5 , F_186 ( 32 ) ) )
* V_311 = 0 ;
else {
F_79 ( & V_5 -> V_29 , L_31 ) ;
return - V_26 ;
}
return 0 ;
}
void F_188 ( struct V_1 * V_2 )
{
int V_256 ;
struct V_10 * V_11 ;
for ( V_256 = 0 ; V_256 < V_2 -> V_66 ; V_256 ++ ) {
V_11 = & V_2 -> V_11 [ V_256 ] ;
if ( V_11 && V_11 -> V_337 != NULL ) {
F_59 ( V_11 -> V_337 ) ;
V_11 -> V_337 = NULL ;
}
}
if ( V_2 -> V_11 != NULL )
F_7 ( V_2 -> V_11 ) ;
}
int F_189 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
int V_256 , V_85 , V_338 ;
struct V_10 * V_11 ;
struct V_339 * V_337 ;
V_11 = F_45 ( V_2 -> V_66 ,
sizeof( struct V_10 ) , V_20 ) ;
if ( V_11 == NULL )
return - V_69 ;
V_2 -> V_11 = V_11 ;
for ( V_256 = 0 ; V_256 < V_2 -> V_66 ; V_256 ++ ) {
V_11 = & V_2 -> V_11 [ V_256 ] ;
V_11 -> V_340 = V_2 -> V_189 ;
V_11 -> V_341 = F_190 ( V_24 , V_256 ) ;
V_337 = F_191 ( F_192 ( V_11 ) ) ;
if ( V_337 == NULL ) {
F_188 ( V_2 ) ;
return - V_69 ;
}
memset ( V_337 , 0 , F_192 ( V_11 ) ) ;
V_11 -> V_337 = V_337 ;
}
if ( F_47 ( V_2 ) ) {
for ( V_256 = 0 ; V_256 < V_2 -> V_66 ; V_256 ++ ) {
V_11 = & V_2 -> V_11 [ V_256 ] ;
V_11 -> V_2 = V_2 ;
if ( V_2 -> V_40 & V_72 ) {
V_338 = V_2 -> V_70 + V_256 ;
V_85 = V_2 -> V_67 [ V_338 ] . V_85 ;
V_11 -> V_86 = V_85 ;
}
}
}
return 0 ;
}
static int
F_193 ( struct V_25 * V_5 , const struct V_135 * V_136 )
{
struct V_23 * V_24 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_50 , V_311 = - 1 ;
T_1 V_342 ;
char V_343 [ V_344 + 19 ] ;
if ( V_5 -> V_345 )
return - V_346 ;
V_50 = F_194 ( V_5 ) ;
if ( V_50 )
return V_50 ;
if ( ! ( F_195 ( V_5 , 0 ) & V_347 ) ) {
V_50 = - V_346 ;
goto V_348;
}
V_50 = F_184 ( V_5 , & V_311 ) ;
if ( V_50 )
goto V_348;
V_50 = F_196 ( V_5 , V_349 ) ;
if ( V_50 )
goto V_348;
F_197 ( V_5 ) ;
F_198 ( V_5 ) ;
V_4 = F_5 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 ) {
V_50 = - V_69 ;
goto V_350;
}
switch ( V_136 -> V_6 ) {
case V_7 :
V_4 -> V_351 = & V_352 ;
V_4 -> V_353 = ( T_1 * ) V_354 ;
break;
case V_148 :
F_199 ( V_4 ) ;
break;
case V_149 :
F_200 ( V_4 ) ;
break;
default:
goto V_355;
}
V_50 = F_76 ( V_5 , V_4 ) ;
if ( V_50 )
goto V_355;
V_24 = F_201 ( sizeof( struct V_1 ) ) ;
if ( ! V_24 ) {
V_50 = - V_69 ;
goto V_356;
}
F_202 ( V_24 , & V_5 -> V_29 ) ;
V_2 = F_18 ( V_24 ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_357 = F_203 ( L_32 ) ;
if ( V_2 -> V_357 == NULL ) {
V_50 = - V_69 ;
F_79 ( & V_5 -> V_29 , L_33 ) ;
goto V_358;
}
V_50 = F_174 ( V_2 ) ;
if ( V_50 )
goto V_358;
V_2 -> V_359 = V_360 ;
V_2 -> V_4 -> V_361 = V_5 -> V_362 ;
if ( V_363 == V_364 )
V_2 -> V_51 = true ;
else if ( V_363 == V_365 )
V_2 -> V_366 = true ;
V_2 -> V_66 = 1 ;
F_204 ( & V_2 -> V_4 -> V_367 ) ;
F_205 ( & V_2 -> V_4 -> V_368 ) ;
F_206 ( & V_2 -> V_284 ) ;
F_207 ( & V_2 -> V_369 ) ;
if ( F_105 ( V_2 ) ) {
F_72 ( V_2 , V_136 ) ;
V_2 -> V_370 = V_2 -> V_4 -> V_83 ;
V_50 = F_208 ( V_2 ) ;
if ( V_50 ) {
F_79 ( & V_5 -> V_29 , L_34 ) ;
goto V_290;
}
V_50 = F_209 ( V_2 ) ;
if ( V_50 )
goto V_290;
V_2 -> V_40 |= V_371 ;
} else if ( F_47 ( V_2 ) ) {
F_210 ( V_2 , V_136 ) ;
V_2 -> V_370 = V_2 -> V_4 -> V_83 ;
V_50 = F_211 ( V_2 , V_311 ) ;
if ( V_50 ) {
F_79 ( & V_5 -> V_29 , L_35 , V_53 ) ;
goto V_290;
}
if ( F_19 ( V_2 ) )
return 0 ;
} else {
F_79 ( & V_5 -> V_29 ,
L_36 , V_53 ) ;
goto V_290;
}
if ( F_8 ( V_2 ) )
F_11 ( & V_5 -> V_29 , L_37 ) ;
if ( V_2 -> V_370 == 0 ) {
F_82 ( V_2 , V_343 ) ;
F_34 ( L_38 ,
F_212 ( V_372 ) ,
V_343 , V_2 -> V_4 -> V_361 ) ;
}
if ( F_47 ( V_2 ) && ! V_87 &&
! ! V_81 )
F_11 ( & V_5 -> V_29 ,
L_39 ) ;
V_50 = F_213 ( V_2 , 0 ) ;
if ( V_50 ) {
F_79 ( & V_5 -> V_29 , L_40 ) ;
goto V_373;
}
if ( F_47 ( V_2 ) ) {
V_50 = F_214 ( V_2 ) ;
if ( V_50 )
goto V_373;
}
V_50 = F_62 ( V_2 ) ;
if ( V_50 )
goto V_374;
V_50 = F_180 ( V_2 , V_24 , V_311 ) ;
if ( V_50 )
goto V_374;
if ( F_105 ( V_2 ) ) {
if ( V_4 -> V_8 & V_200 ) {
V_342 = F_89 ( V_2 , V_202 ) ;
if ( V_342 & V_375 )
F_215 ( V_2 ) ;
}
}
F_216 ( V_5 , V_2 ) ;
if ( F_105 ( V_2 ) )
F_217 ( V_2 , V_376 ,
V_377 ) ;
switch ( V_2 -> V_4 -> V_102 ) {
case V_103 :
F_48 ( & V_2 -> V_5 -> V_29 , L_41 ,
V_2 -> V_24 -> V_155 ) ;
break;
case V_106 :
F_48 ( & V_2 -> V_5 -> V_29 , L_42 ,
V_2 -> V_24 -> V_155 ) ;
break;
}
if ( V_2 -> V_366 )
F_218 ( V_2 ) ;
F_219 ( V_2 ) ;
return 0 ;
V_374:
if ( F_47 ( V_2 ) )
F_220 ( V_2 ) ;
V_373:
F_56 ( V_2 ) ;
F_221 ( V_2 ) ;
F_222 ( V_2 , 0 ) ;
V_290:
F_175 ( V_2 ) ;
V_358:
F_223 ( V_24 ) ;
V_356:
F_60 ( V_4 ) ;
V_355:
F_7 ( V_4 ) ;
V_350:
F_224 ( V_5 ) ;
V_348:
F_216 ( V_5 , NULL ) ;
F_225 ( V_5 ) ;
return V_50 ;
}
static void F_226 ( struct V_25 * V_5 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
struct V_3 * V_4 ;
V_2 = F_227 ( V_5 ) ;
if ( V_2 == NULL )
return;
V_24 = V_2 -> V_24 ;
F_228 ( V_2 ) ;
F_221 ( V_2 ) ;
V_4 = V_2 -> V_4 ;
F_229 ( V_24 ) ;
F_230 ( V_2 ) ;
if ( F_47 ( V_2 ) ) {
F_220 ( V_2 ) ;
F_231 ( V_2 , 0 ) ;
F_43 ( & V_2 -> V_378 ) ;
}
F_169 ( V_2 ) ;
if ( V_2 -> V_114 != NULL )
F_7 ( V_2 -> V_114 ) ;
if ( V_2 -> V_116 != NULL )
F_7 ( V_2 -> V_116 ) ;
if ( F_105 ( V_2 ) )
F_222 ( V_2 , 0 ) ;
F_97 ( V_59 , & V_2 -> V_45 ) ;
F_232 ( V_2 ) ;
F_56 ( V_2 ) ;
F_233 ( V_2 ) ;
F_60 ( V_2 -> V_4 ) ;
F_123 ( V_2 ) ;
F_234 ( V_5 ) ;
F_224 ( V_5 ) ;
F_225 ( V_5 ) ;
F_216 ( V_5 , NULL ) ;
if ( V_2 -> V_357 ) {
F_235 ( V_2 -> V_357 ) ;
V_2 -> V_357 = NULL ;
}
F_175 ( V_2 ) ;
F_7 ( V_4 ) ;
F_223 ( V_24 ) ;
}
static int F_236 ( struct V_25 * V_5 )
{
struct V_1 * V_2 = F_227 ( V_5 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_379 ;
F_21 ( V_24 ) ;
F_221 ( V_2 ) ;
if ( F_144 ( V_24 ) )
F_160 ( V_2 , V_24 ) ;
F_230 ( V_2 ) ;
if ( F_105 ( V_2 ) )
F_222 ( V_2 , 0 ) ;
F_97 ( V_59 , & V_2 -> V_45 ) ;
V_379 = F_237 ( V_5 ) ;
if ( V_379 )
return V_379 ;
if ( F_105 ( V_2 ) ) {
if ( F_238 ( V_2 ) ) {
F_239 ( V_5 , V_380 , 1 ) ;
F_239 ( V_5 , V_381 , 1 ) ;
}
}
return 0 ;
}
static void F_240 ( struct V_25 * V_5 )
{
if ( F_236 ( V_5 ) )
return;
F_225 ( V_5 ) ;
}
static int
F_241 ( struct V_25 * V_5 , T_8 V_45 )
{
int V_379 ;
V_379 = F_236 ( V_5 ) ;
if ( V_379 )
return V_379 ;
F_242 ( V_5 , F_243 ( V_5 , V_45 ) ) ;
return 0 ;
}
static int
F_244 ( struct V_25 * V_5 )
{
struct V_1 * V_2 = F_227 ( V_5 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_50 ;
V_50 = F_194 ( V_5 ) ;
if ( V_50 )
return V_50 ;
F_242 ( V_5 , V_382 ) ;
F_197 ( V_5 ) ;
F_245 ( V_5 ) ;
V_50 = F_208 ( V_2 ) ;
if ( V_50 ) {
F_79 ( & V_5 -> V_29 , L_43 ) ;
return V_50 ;
}
if ( F_144 ( V_24 ) ) {
V_50 = F_142 ( V_2 , V_24 ) ;
if ( V_50 )
goto V_383;
F_96 ( V_24 , V_310 ) ;
}
V_383:
F_24 ( V_24 ) ;
F_217 ( V_2 , V_376 , V_377 ) ;
return 0 ;
}
static int F_246 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
int V_50 ;
F_151 ( V_24 ) ;
V_50 = F_161 ( V_2 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_134 ( V_2 , V_24 ) ;
if ( V_50 )
goto V_246;
F_247 ( V_24 ) ;
return 0 ;
V_246:
F_169 ( V_2 ) ;
return V_50 ;
}
static int F_248 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
F_146 ( V_2 , V_24 ) ;
return 0 ;
}
void F_218 ( struct V_1 * V_2 )
{
void * V_33 ;
int V_62 ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_384 = 0 ;
T_3 V_104 = 0 ;
if ( V_2 -> V_285 . V_385 && V_2 -> V_285 . V_386 )
return;
V_104 = V_2 -> V_4 -> V_104 ;
F_206 ( & V_2 -> V_387 ) ;
F_206 ( & V_2 -> V_388 ) ;
if ( F_105 ( V_2 ) ) {
V_384 = V_389 ;
V_2 -> V_285 . V_390 = V_391 ;
} else {
V_384 = V_392 ;
V_2 -> V_285 . V_390 = V_393 ;
}
V_33 = F_45 ( V_2 -> V_285 . V_390 ,
sizeof( struct V_394 ) , V_395 ) ;
if ( ! V_33 )
return;
V_2 -> V_285 . V_385 = ( V_384 / V_104 ) ;
V_2 -> V_285 . V_386 = V_33 ;
F_249 ( V_24 , L_44 ,
V_104 , V_2 -> V_285 . V_385 ) ;
for ( V_62 = 0 ; V_62 < V_2 -> V_285 . V_390 ; V_62 ++ )
F_250 ( & V_2 -> V_285 . V_386 [ V_62 ] ) ;
V_2 -> V_396 . V_390 = V_2 -> V_285 . V_390 ;
V_33 = F_45 ( V_2 -> V_396 . V_390 ,
sizeof( struct V_394 ) , V_395 ) ;
if ( ! V_33 )
return;
V_2 -> V_396 . V_385 = ( V_384 / V_104 ) ;
V_2 -> V_396 . V_386 = V_33 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_396 . V_390 ; V_62 ++ )
F_250 ( & V_2 -> V_396 . V_386 [ V_62 ] ) ;
}
static void F_232 ( struct V_1 * V_2 )
{
if ( V_2 -> V_285 . V_385 && V_2 -> V_285 . V_386 )
F_7 ( V_2 -> V_285 . V_386 ) ;
V_2 -> V_285 . V_386 = NULL ;
V_2 -> V_285 . V_385 = 0 ;
if ( V_2 -> V_396 . V_385 && V_2 -> V_396 . V_386 )
F_7 ( V_2 -> V_396 . V_386 ) ;
V_2 -> V_396 . V_385 = 0 ;
V_2 -> V_396 . V_386 = NULL ;
}
int F_251 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_397 , V_398 , V_201 = 0 ;
int V_399 = 0 ;
if ( F_47 ( V_2 ) )
V_201 = F_252 ( V_2 -> V_4 , V_400 ) ;
if ( F_105 ( V_2 ) )
V_201 = F_69 ( V_2 , V_401 ) ;
V_397 = F_253 ( V_201 ) ;
V_398 = F_254 ( V_201 ) ;
if ( V_397 == V_402 ) {
F_79 ( & V_24 -> V_29 ,
L_45
L_46 ,
V_398 ) ;
V_399 = 1 ;
} else if ( V_397 == V_403 ) {
if ( V_2 -> V_4 -> V_201 == V_404 ) {
F_79 ( & V_24 -> V_29 ,
L_47
L_48
L_49 ,
V_398 ) ;
}
} else {
if ( V_2 -> V_4 -> V_201 == V_403 ) {
F_48 ( & V_24 -> V_29 ,
L_50
L_51 , V_398 ) ;
}
}
V_2 -> V_4 -> V_201 = V_397 ;
return V_399 ;
}
static void F_255 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
if ( F_20 ( V_59 , & V_2 -> V_45 ) )
return;
if ( ++ V_2 -> V_405 >= V_406 ) {
F_249 ( V_24 , L_52 ) ;
if ( F_105 ( V_2 ) )
V_2 -> V_228 = 1 ;
else if ( F_47 ( V_2 ) )
F_256 ( V_2 ,
V_407 ) ;
} else {
F_249 ( V_24 , L_53 ) ;
V_2 -> V_4 -> V_281 = 1 ;
}
}
static struct V_408 * F_257 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_408 * V_304 = & V_24 -> V_304 ;
V_304 -> V_298 = V_2 -> V_304 . V_409 + V_2 -> V_304 . V_410 ;
V_304 -> V_302 = V_2 -> V_304 . V_411 ;
V_304 -> V_412 = V_2 -> V_304 . V_413 + V_2 -> V_304 . V_414 ;
V_304 -> V_415 = V_2 -> V_304 . V_416 ;
V_304 -> V_417 = V_2 -> V_304 . V_418 ;
V_304 -> V_419 = V_2 -> V_304 . V_420 ;
return V_304 ;
}
T_9 F_258 ( struct V_1 * V_2 )
{
T_1 V_421 ;
V_421 = F_259 ( V_2 -> V_91 ) ;
if ( ! ( V_421 & V_2 -> V_4 -> V_89 ) )
return V_422 ;
V_421 = F_259 ( V_2 -> V_93 ) ;
if ( ! F_260 ( V_421 ) )
return V_422 ;
F_3 ( 0xffffffff , V_2 -> V_84 ) ;
F_259 ( V_2 -> V_91 ) ;
F_259 ( V_2 -> V_91 ) ;
return V_423 ;
}
static T_9 V_260 ( int V_86 , void * V_131 )
{
struct V_18 * V_255 = V_131 ;
struct V_1 * V_2 = V_255 -> V_2 ;
if ( V_2 -> V_40 & V_72 )
goto V_383;
else if ( V_2 -> V_40 & V_71 ) {
F_3 ( 0xffffffff , V_2 -> V_84 ) ;
goto V_383;
}
if ( F_261 ( V_2 ) == V_422 )
return V_422 ;
V_383:
V_2 -> V_4 -> V_424 ++ ;
F_177 ( V_255 ) ;
return V_423 ;
}
static T_9 V_264 ( int V_86 , void * V_131 )
{
struct V_18 * V_255 = V_131 ;
struct V_1 * V_2 = V_255 -> V_2 ;
if ( F_261 ( V_2 ) == V_422 )
return V_422 ;
F_262 ( & V_255 -> V_425 ) ;
return V_423 ;
}
static T_9 V_263 ( int V_86 , void * V_131 )
{
struct V_18 * V_255 = V_131 ;
struct V_1 * V_2 = V_255 -> V_2 ;
F_3 ( 0xffffffff , V_2 -> V_84 ) ;
F_262 ( & V_255 -> V_425 ) ;
return V_423 ;
}
static T_9 V_262 ( int V_86 , void * V_131 )
{
struct V_18 * V_255 = V_131 ;
F_262 ( & V_255 -> V_425 ) ;
return V_423 ;
}
static T_9 V_267 ( int V_86 , void * V_131 )
{
struct V_10 * V_11 = V_131 ;
F_262 ( & V_11 -> V_425 ) ;
return V_423 ;
}
static void F_263 ( struct V_23 * V_24 )
{
int V_256 ;
struct V_18 * V_255 ;
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
F_264 ( V_2 -> V_86 ) ;
for ( V_256 = 0 ; V_256 < V_2 -> V_70 ; V_256 ++ ) {
V_255 = & V_15 -> V_19 [ V_256 ] ;
V_264 ( V_2 -> V_86 , V_255 ) ;
}
F_265 ( V_2 -> V_86 ) ;
}
static void
F_126 ( struct V_1 * V_2 , T_2 V_426 )
{
T_1 V_427 ;
V_427 = V_2 -> V_370 & 0xf ;
V_427 |= V_426 << 7 ;
V_427 |= ( V_360 - V_2 -> V_359 ) << 8 ;
F_70 ( V_2 , V_428 , V_427 ) ;
V_2 -> V_359 = V_360 ;
}
static int
F_266 ( struct V_1 * V_2 , T_2 V_45 )
{
T_1 V_427 ;
F_267 ( V_45 != V_429 &&
V_45 != V_430 ) ;
if ( F_67 ( V_2 ) )
return - V_26 ;
V_427 = F_69 ( V_2 , V_431 ) ;
if ( V_45 == V_429 )
F_268 ( V_427 , V_2 -> V_370 ) ;
else if ( V_45 == V_430 )
F_269 ( V_427 , V_2 -> V_370 ) ;
F_70 ( V_2 , V_431 , V_427 ) ;
F_71 ( V_2 ) ;
return 0 ;
}
static int
F_270 ( struct V_1 * V_2 )
{
T_1 V_427 ;
if ( F_67 ( V_2 ) )
return - V_309 ;
V_427 = F_69 ( V_2 , V_431 ) ;
F_271 ( V_427 , V_2 -> V_370 ) ;
F_70 ( V_2 , V_431 , V_427 ) ;
F_71 ( V_2 ) ;
return 0 ;
}
static void
F_222 ( struct V_1 * V_2 , T_2 V_432 )
{
T_1 V_427 ;
if ( F_67 ( V_2 ) )
goto V_50;
V_427 = F_69 ( V_2 , V_433 ) ;
F_272 ( V_427 , V_2 -> V_370 ) ;
F_70 ( V_2 , V_433 , V_427 ) ;
if ( V_432 ) {
F_70 ( V_2 , V_251 ,
V_253 ) ;
F_48 ( & V_2 -> V_5 -> V_29 ,
L_54 ) ;
} else if ( ! ( V_427 & 0x11111111 ) )
F_70 ( V_2 , V_251 ,
V_434 ) ;
V_427 = F_69 ( V_2 , V_431 ) ;
F_271 ( V_427 , V_2 -> V_370 ) ;
F_70 ( V_2 , V_431 , V_427 ) ;
F_71 ( V_2 ) ;
V_50:
V_2 -> V_435 = 0 ;
V_2 -> V_40 &= ~ V_436 ;
F_97 ( V_437 , & V_2 -> V_45 ) ;
F_97 ( V_59 , & V_2 -> V_45 ) ;
}
static int
F_273 ( struct V_1 * V_2 )
{
int V_438 , V_45 , V_439 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_45 = F_69 ( V_2 , V_431 ) ;
V_438 = F_69 ( V_2 , V_433 ) ;
if ( V_2 -> V_40 & V_440 ) {
V_439 = ( ~ ( 1 << ( V_4 -> V_83 * 4 ) ) ) ;
V_438 = V_438 & V_439 ;
}
if ( ( ( V_45 & 0x11111111 ) == ( V_438 & 0x11111111 ) ) ||
( ( V_438 & 0x11111111 ) == ( ( V_45 >> 1 ) & 0x11111111 ) ) )
return 0 ;
else
return 1 ;
}
static int F_274 ( struct V_1 * V_2 )
{
T_1 V_427 = F_69 ( V_2 , V_441 ) ;
if ( V_427 != V_442 ) {
F_11 ( & V_2 -> V_5 -> V_29 , L_55
L_56 , V_442 , V_427 ) ;
}
return 0 ;
}
static int
F_117 ( struct V_1 * V_2 )
{
T_1 V_427 , V_443 ;
T_2 V_444 = V_2 -> V_444 ;
T_2 V_370 = V_2 -> V_370 ;
T_2 V_101 ;
if ( F_147 ( V_437 , & V_2 -> V_45 ) )
return 1 ;
if ( F_67 ( V_2 ) )
return - 1 ;
V_427 = F_69 ( V_2 , V_433 ) ;
if ( ! ( V_427 & ( 1 << ( V_370 * 4 ) ) ) ) {
F_275 ( V_427 , V_370 ) ;
F_70 ( V_2 , V_433 , V_427 ) ;
}
V_443 = F_69 ( V_2 , V_251 ) ;
F_276 ( V_2 , V_445 , L_57 , V_443 ) ;
switch ( V_443 ) {
case V_434 :
F_70 ( V_2 , V_251 ,
V_446 ) ;
F_70 ( V_2 , V_441 ,
V_442 ) ;
F_126 ( V_2 , 0 ) ;
F_71 ( V_2 ) ;
return 1 ;
case V_252 :
V_101 = F_274 ( V_2 ) ;
F_71 ( V_2 ) ;
return V_101 ;
case V_429 :
V_427 = F_69 ( V_2 , V_431 ) ;
F_268 ( V_427 , V_370 ) ;
F_70 ( V_2 , V_431 , V_427 ) ;
break;
case V_430 :
V_427 = F_69 ( V_2 , V_431 ) ;
F_269 ( V_427 , V_370 ) ;
F_70 ( V_2 , V_431 , V_427 ) ;
break;
case V_253 :
F_79 ( & V_2 -> V_5 -> V_29 , L_58 ) ;
F_71 ( V_2 ) ;
return - 1 ;
case V_446 :
case V_447 :
break;
}
F_71 ( V_2 ) ;
do {
F_113 ( 1000 ) ;
V_443 = F_69 ( V_2 , V_251 ) ;
if ( V_443 == V_447 )
continue;
} while ( ( V_443 != V_252 ) && -- V_444 );
if ( ! V_444 ) {
F_79 ( & V_2 -> V_5 -> V_29 ,
L_59 ) ;
return - 1 ;
}
if ( F_67 ( V_2 ) )
return - 1 ;
V_427 = F_69 ( V_2 , V_431 ) ;
F_271 ( V_427 , V_370 ) ;
F_70 ( V_2 , V_431 , V_427 ) ;
V_101 = F_274 ( V_2 ) ;
F_71 ( V_2 ) ;
return V_101 ;
}
static void
F_277 ( struct V_448 * V_449 )
{
struct V_1 * V_2 = F_278 ( V_449 ,
struct V_1 , V_60 . V_449 ) ;
T_1 V_450 = 0xf ;
T_1 V_427 ;
if ( F_67 ( V_2 ) )
goto V_451;
V_450 = F_69 ( V_2 , V_251 ) ;
if ( V_450 == V_447 ||
V_450 == V_430 ) {
F_71 ( V_2 ) ;
F_217 ( V_2 , F_277 ,
V_377 * 2 ) ;
return;
}
if ( V_2 -> V_4 -> V_108 == V_141 ) {
F_71 ( V_2 ) ;
goto V_452;
}
if ( V_450 == V_446 ||
V_450 == V_252 ) {
F_48 ( & V_2 -> V_5 -> V_29 , L_60
L_61 ) ;
goto V_453;
}
if ( V_2 -> V_454 ++ > V_2 -> V_455 ) {
F_48 ( & V_2 -> V_5 -> V_29 , L_62 ,
V_2 -> V_455 ) ;
goto V_453;
}
if ( ! F_273 ( V_2 ) ) {
V_453:
V_450 = F_69 ( V_2 , V_251 ) ;
if ( V_450 == V_429 ) {
F_70 ( V_2 , V_251 ,
V_446 ) ;
F_94 ( V_437 , & V_2 -> V_45 ) ;
F_276 ( V_2 , V_456 , L_63 ) ;
F_126 ( V_2 , 0 ) ;
V_427 = F_69 ( V_2 ,
V_431 ) ;
F_268 ( V_427 , V_2 -> V_370 ) ;
F_70 ( V_2 ,
V_431 , V_427 ) ;
}
F_71 ( V_2 ) ;
F_143 () ;
if ( V_2 -> V_4 -> V_170 . V_457 &&
( V_2 -> V_40 & V_440 ) ) {
F_276 ( V_2 , V_456 , L_64 ) ;
F_279 ( V_2 ) ;
V_2 -> V_40 |= V_436 ;
}
F_145 () ;
V_2 -> V_40 &= ~ V_440 ;
if ( ! V_2 -> V_142 -> V_458 ( V_2 ) ) {
F_217 ( V_2 , V_459 , 0 ) ;
V_2 -> V_454 = 0 ;
return;
}
goto V_451;
}
F_71 ( V_2 ) ;
V_452:
V_450 = F_69 ( V_2 , V_251 ) ;
F_276 ( V_2 , V_445 , L_65 , V_450 ) ;
switch ( V_450 ) {
case V_252 :
if ( ! F_208 ( V_2 ) ) {
F_217 ( V_2 , V_459 , 0 ) ;
V_2 -> V_454 = 0 ;
return;
}
case V_253 :
break;
default:
F_217 ( V_2 ,
F_277 , V_377 ) ;
return;
}
V_451:
F_79 ( & V_2 -> V_5 -> V_29 , L_66
L_67 , V_450 , V_2 -> V_454 ) ;
F_24 ( V_2 -> V_24 ) ;
F_222 ( V_2 , 0 ) ;
}
static void
F_280 ( struct V_448 * V_449 )
{
struct V_1 * V_2 = F_278 ( V_449 ,
struct V_1 , V_60 . V_449 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_421 ;
F_21 ( V_24 ) ;
if ( V_2 -> V_450 == V_430 ) {
if ( F_144 ( V_24 ) )
F_146 ( V_2 , V_24 ) ;
} else
F_160 ( V_2 , V_24 ) ;
V_421 = F_69 ( V_2 , V_460 ) ;
if ( V_421 & V_461 ) {
F_79 ( & V_2 -> V_5 -> V_29 ,
L_68 ,
V_421 ) ;
if ( F_281 ( V_421 ) == V_462 ) {
F_79 ( & V_2 -> V_5 -> V_29 ,
L_69
L_70 ) ;
F_79 ( & V_2 -> V_5 -> V_29 ,
L_71 ) ;
}
goto V_451;
}
if ( V_2 -> V_4 -> V_201 == V_402 ) {
F_79 ( & V_2 -> V_5 -> V_29 , L_72 ,
V_2 -> V_4 -> V_201 ) ;
goto V_451;
}
if ( ! ( V_2 -> V_40 & V_440 ) ) {
if ( F_266 ( V_2 , V_2 -> V_450 ) ) {
F_79 ( & V_2 -> V_5 -> V_29 ,
L_73
L_74 ) ;
goto V_451;
}
}
V_2 -> V_454 = 0 ;
F_217 ( V_2 , F_277 , V_377 ) ;
return;
V_451:
F_24 ( V_24 ) ;
F_222 ( V_2 , 1 ) ;
}
static void
F_282 ( struct V_1 * V_2 )
{
T_1 V_45 ;
V_45 = F_69 ( V_2 , V_242 ) ;
if ( V_45 == V_463 )
return;
if ( F_67 ( V_2 ) )
return;
F_70 ( V_2 , V_242 ,
V_463 ) ;
F_71 ( V_2 ) ;
}
void F_283 ( struct V_1 * V_2 , T_1 V_464 )
{
T_1 V_45 , V_465 = 0 , V_466 = 0 ;
F_284 ( V_465 ) ;
F_285 ( V_465 ) ;
F_124 ( V_2 , V_467 , V_465 ) ;
F_286 ( V_466 ) ;
F_287 ( V_466 ) ;
F_288 ( V_466 ) ;
F_289 ( V_466 ) ;
F_124 ( V_2 , V_468 , V_466 ) ;
F_48 ( & V_2 -> V_5 -> V_29 , L_75
L_76 ) ;
V_2 -> V_228 = 1 ;
if ( F_67 ( V_2 ) )
return;
V_45 = F_69 ( V_2 , V_251 ) ;
if ( V_45 == V_252 ) {
F_70 ( V_2 , V_251 ,
V_429 ) ;
V_2 -> V_40 |= V_440 ;
F_276 ( V_2 , V_456 , L_77 ) ;
F_126 ( V_2 , 0 ) ;
}
F_70 ( V_2 , V_242 ,
V_463 ) ;
F_71 ( V_2 ) ;
}
static void
F_115 ( struct V_1 * V_2 )
{
if ( F_67 ( V_2 ) )
return;
F_70 ( V_2 , V_242 ,
V_243 ) ;
F_276 ( V_2 , V_456 , L_78 ) ;
F_71 ( V_2 ) ;
}
void F_217 ( struct V_1 * V_2 ,
T_10 V_469 , int V_470 )
{
if ( F_20 ( V_471 , & V_2 -> V_45 ) )
return;
F_290 ( & V_2 -> V_60 , V_469 ) ;
F_291 ( V_2 -> V_357 , & V_2 -> V_60 ,
F_292 ( V_470 ) ) ;
}
static void
V_459 ( struct V_448 * V_449 )
{
struct V_1 * V_2 = F_278 ( V_449 ,
struct V_1 , V_60 . V_449 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_241 ;
if ( V_2 -> V_4 -> V_108 != V_109 ) {
V_241 = F_69 ( V_2 ,
V_242 ) ;
if ( V_2 -> V_454 ++ > V_240 )
F_222 ( V_2 , 0 ) ;
else if ( V_241 != V_243 )
F_217 ( V_2 , V_459 ,
V_377 ) ;
else
goto V_472;
F_276 ( V_2 , V_456 , L_79 ) ;
return;
}
V_472:
if ( F_144 ( V_24 ) ) {
if ( F_142 ( V_2 , V_24 ) )
goto V_383;
F_96 ( V_24 , V_310 ) ;
}
V_383:
F_24 ( V_24 ) ;
V_2 -> V_435 = 0 ;
V_2 -> V_40 &= ~ V_436 ;
F_97 ( V_59 , & V_2 -> V_45 ) ;
if ( ! F_270 ( V_2 ) )
F_217 ( V_2 , V_376 ,
V_377 ) ;
}
static int
F_293 ( struct V_1 * V_2 )
{
T_1 V_45 = 0 , V_473 ;
T_1 V_474 ;
if ( F_251 ( V_2 ) )
goto V_475;
if ( V_2 -> V_228 )
F_294 ( V_2 , 0 ) ;
V_45 = F_69 ( V_2 , V_251 ) ;
if ( V_45 == V_429 ) {
F_282 ( V_2 ) ;
V_2 -> V_228 = 1 ;
} else if ( V_45 == V_430 )
goto V_475;
V_473 = F_69 ( V_2 , V_476 ) ;
if ( V_473 != V_2 -> V_473 ) {
V_2 -> V_473 = V_473 ;
V_2 -> V_435 = 0 ;
if ( V_2 -> V_228 )
goto V_475;
if ( V_2 -> V_4 -> V_281 && V_477 )
F_178 ( V_2 ) ;
return 0 ;
}
if ( ++ V_2 -> V_435 < V_478 )
return 0 ;
V_2 -> V_40 |= V_436 ;
F_294 ( V_2 , 0 ) ;
if ( V_477 )
F_97 ( V_479 , & V_2 -> V_45 ) ;
F_79 ( & V_2 -> V_5 -> V_29 , L_80 ) ;
V_474 = F_69 ( V_2 , V_460 ) ;
F_79 ( & V_2 -> V_5 -> V_29 , L_81
L_82
L_83
L_84
L_85 ,
V_474 ,
F_69 ( V_2 , V_480 ) ,
F_89 ( V_2 , V_481 + 0x3c ) ,
F_89 ( V_2 , V_482 + 0x3c ) ,
F_89 ( V_2 , V_483 + 0x3c ) ,
F_89 ( V_2 , V_484 + 0x3c ) ,
F_89 ( V_2 , V_485 + 0x3c ) ) ;
if ( F_281 ( V_474 ) == 0x67 )
F_79 ( & V_2 -> V_5 -> V_29 ,
L_86
L_87 ) ;
V_475:
V_2 -> V_450 = ( V_45 == V_430 ) ? V_45 :
V_429 ;
if ( V_477 && ! F_41 ( V_59 ,
& V_2 -> V_45 ) ) {
F_217 ( V_2 , F_280 , 0 ) ;
F_276 ( V_2 , V_456 , L_88 ) ;
}
return 1 ;
}
static void
V_376 ( struct V_448 * V_449 )
{
struct V_1 * V_2 = F_278 ( V_449 ,
struct V_1 , V_60 . V_449 ) ;
if ( F_20 ( V_59 , & V_2 -> V_45 ) )
goto V_486;
if ( F_293 ( V_2 ) )
return;
if ( V_2 -> V_285 . V_286 )
F_295 ( V_2 ) ;
V_486:
F_217 ( V_2 , V_376 , V_377 ) ;
}
static int F_296 ( struct V_25 * V_5 )
{
struct V_25 * V_487 ;
int V_427 = V_5 -> V_488 ;
while ( V_427 -- > 0 ) {
V_487 = F_297 ( F_298
( V_5 -> V_489 ) , V_5 -> V_489 -> V_490 ,
F_299 ( F_300 ( V_5 -> V_488 ) , V_427 ) ) ;
if ( ! V_487 )
continue;
if ( V_487 -> V_491 != V_380 ) {
F_301 ( V_487 ) ;
return 0 ;
}
F_301 ( V_487 ) ;
}
return 1 ;
}
static int F_302 ( struct V_25 * V_5 )
{
int V_50 , V_492 ;
struct V_1 * V_2 = F_227 ( V_5 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
V_5 -> V_493 = V_494 ;
V_50 = F_194 ( V_5 ) ;
if ( V_50 )
return V_50 ;
F_242 ( V_5 , V_382 ) ;
F_197 ( V_5 ) ;
F_245 ( V_5 ) ;
V_492 = F_296 ( V_5 ) ;
if ( F_67 ( V_2 ) )
return - V_39 ;
if ( V_2 -> V_4 -> V_108 != V_141 && V_492 ) {
V_2 -> V_228 = 1 ;
F_94 ( V_437 , & V_2 -> V_45 ) ;
F_70 ( V_2 , V_251 ,
V_446 ) ;
F_276 ( V_2 , V_456 , L_63 ) ;
}
F_71 ( V_2 ) ;
V_50 = F_208 ( V_2 ) ;
if ( V_50 )
return V_50 ;
F_270 ( V_2 ) ;
F_7 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
V_50 = F_213 ( V_2 , 0 ) ;
if ( V_50 ) {
F_7 ( V_2 -> V_67 ) ;
F_93 ( V_24 , L_28 ) ;
return V_50 ;
}
if ( F_47 ( V_2 ) ) {
F_231 ( V_2 , 1 ) ;
V_50 = F_214 ( V_2 ) ;
if ( V_50 ) {
F_79 ( & V_2 -> V_5 -> V_29 ,
L_89 ) ;
F_222 ( V_2 , 1 ) ;
F_97 ( V_471 , & V_2 -> V_45 ) ;
goto V_383;
}
}
if ( F_144 ( V_24 ) ) {
V_50 = F_161 ( V_2 ) ;
if ( V_50 ) {
F_222 ( V_2 , 1 ) ;
F_97 ( V_471 , & V_2 -> V_45 ) ;
F_24 ( V_24 ) ;
return V_50 ;
}
V_50 = F_142 ( V_2 , V_24 ) ;
if ( V_50 )
goto V_383;
F_96 ( V_24 , V_310 ) ;
}
V_383:
F_24 ( V_24 ) ;
return V_50 ;
}
static T_11 F_303 ( struct V_25 * V_5 ,
T_12 V_45 )
{
struct V_1 * V_2 = F_227 ( V_5 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( V_45 == V_495 )
return V_496 ;
if ( V_45 == V_494 )
return V_497 ;
F_94 ( V_471 , & V_2 -> V_45 ) ;
F_21 ( V_24 ) ;
F_43 ( & V_2 -> V_60 ) ;
if ( F_144 ( V_24 ) )
F_160 ( V_2 , V_24 ) ;
if ( F_47 ( V_2 ) ) {
F_220 ( V_2 ) ;
F_231 ( V_2 , 0 ) ;
F_43 ( & V_2 -> V_378 ) ;
}
F_169 ( V_2 ) ;
F_56 ( V_2 ) ;
F_97 ( V_59 , & V_2 -> V_45 ) ;
F_237 ( V_5 ) ;
F_225 ( V_5 ) ;
return V_498 ;
}
static T_11 F_304 ( struct V_25 * V_5 )
{
return F_302 ( V_5 ) ? V_496 :
V_497 ;
}
static void F_305 ( struct V_25 * V_5 )
{
T_1 V_45 ;
struct V_1 * V_2 = F_227 ( V_5 ) ;
F_306 ( V_5 ) ;
V_45 = F_69 ( V_2 , V_251 ) ;
if ( V_45 == V_252 && F_147 ( V_471 ,
& V_2 -> V_45 ) )
F_217 ( V_2 , V_376 ,
V_377 ) ;
}
static int
F_307 ( struct V_1 * V_2 )
{
int V_50 ;
V_50 = F_117 ( V_2 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_112 ( V_2 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_87 ( V_2 ) ;
if ( V_50 )
return V_50 ;
F_83 ( V_2 ) ;
V_50 = F_99 ( V_2 ) ;
if ( V_50 )
return V_50 ;
V_2 -> V_228 = 0 ;
return V_50 ;
}
int F_308 ( struct V_1 * V_2 ,
T_13 V_427 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
T_2 V_499 = V_2 -> V_4 -> V_199 ;
T_1 V_500 ;
if ( V_427 > V_501 ) {
F_93 ( V_24 , L_90 ,
V_501 ) ;
return - V_39 ;
}
V_500 = F_49 ( F_54 ( int , V_499 ,
F_55 () ) ) ;
if ( ( V_427 > V_500 ) || ( V_427 < 2 ) || ! F_309 ( V_427 ) ) {
if ( ! F_309 ( V_427 ) )
F_93 ( V_24 , L_91 ) ;
if ( V_427 < 2 )
F_93 ( V_24 , L_92 ) ;
if ( V_427 > V_499 )
F_93 ( V_24 ,
L_93 ,
V_499 ) ;
if ( V_427 > F_55 () )
F_93 ( V_24 ,
L_94 ,
F_55 () ) ;
F_93 ( V_24 , L_95 , V_427 ) ;
return - V_39 ;
}
return 0 ;
}
int F_310 ( struct V_1 * V_2 , T_2 V_131 , T_14 V_502 )
{
int V_50 ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( F_20 ( V_59 , & V_2 -> V_45 ) )
return - V_309 ;
F_21 ( V_24 ) ;
if ( F_144 ( V_24 ) )
F_146 ( V_2 , V_24 ) ;
F_169 ( V_2 ) ;
if ( F_47 ( V_2 ) ) {
F_220 ( V_2 ) ;
F_311 ( V_2 ) ;
}
F_56 ( V_2 ) ;
V_50 = F_213 ( V_2 , V_131 ) ;
if ( V_50 ) {
F_7 ( V_2 -> V_67 ) ;
F_93 ( V_24 , L_28 ) ;
return V_50 ;
}
if ( F_47 ( V_2 ) ) {
F_231 ( V_2 , 1 ) ;
V_50 = F_214 ( V_2 ) ;
F_312 ( V_2 ) ;
if ( V_50 ) {
F_79 ( & V_2 -> V_5 -> V_29 ,
L_89 ) ;
goto V_383;
}
}
if ( F_144 ( V_24 ) ) {
V_50 = F_161 ( V_2 ) ;
if ( V_50 )
goto V_383;
V_50 = F_134 ( V_2 , V_24 ) ;
if ( V_50 )
goto V_383;
F_96 ( V_24 , V_310 ) ;
}
V_50 = V_502 ;
V_383:
F_24 ( V_24 ) ;
F_97 ( V_59 , & V_2 -> V_45 ) ;
return V_50 ;
}
static void
F_313 ( struct V_1 * V_2 ,
struct V_23 * V_29 , unsigned long V_503 )
{
struct V_504 * V_505 ;
V_505 = F_314 ( V_29 ) ;
if ( ! V_505 )
return;
F_315 (indev) {
switch ( V_503 ) {
case V_310 :
F_316 ( V_2 ,
V_506 -> V_507 , V_508 ) ;
break;
case V_217 :
F_316 ( V_2 ,
V_506 -> V_507 , V_509 ) ;
break;
default:
break;
}
} F_317 ( V_505 ) ;
F_318 ( V_505 ) ;
}
void F_96 ( struct V_23 * V_24 , unsigned long V_503 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_23 * V_29 ;
T_3 V_215 ;
F_313 ( V_2 , V_24 , V_503 ) ;
F_319 () ;
F_320 (vid, adapter->vlans, VLAN_N_VID) {
V_29 = F_321 ( V_24 , F_322 ( V_510 ) , V_215 ) ;
if ( ! V_29 )
continue;
F_313 ( V_2 , V_29 , V_503 ) ;
}
F_323 () ;
}
static int F_324 ( struct V_511 * V_512 ,
unsigned long V_503 , void * V_513 )
{
struct V_1 * V_2 ;
struct V_23 * V_29 = (struct V_23 * ) V_513 ;
V_514:
if ( V_29 == NULL )
goto V_383;
if ( V_29 -> V_515 & V_516 ) {
V_29 = F_325 ( V_29 ) ;
goto V_514;
}
if ( ! F_326 ( V_29 ) )
goto V_383;
V_2 = F_18 ( V_29 ) ;
if ( ! V_2 )
goto V_383;
if ( ! F_20 ( V_44 , & V_2 -> V_45 ) )
goto V_383;
F_313 ( V_2 , V_29 , V_503 ) ;
V_383:
return V_517 ;
}
static int
F_327 ( struct V_511 * V_512 ,
unsigned long V_503 , void * V_513 )
{
struct V_1 * V_2 ;
struct V_23 * V_29 ;
struct V_518 * V_506 = (struct V_518 * ) V_513 ;
V_29 = V_506 -> V_519 ? V_506 -> V_519 -> V_29 : NULL ;
V_514:
if ( V_29 == NULL )
goto V_383;
if ( V_29 -> V_515 & V_516 ) {
V_29 = F_325 ( V_29 ) ;
goto V_514;
}
if ( ! F_326 ( V_29 ) )
goto V_383;
V_2 = F_18 ( V_29 ) ;
if ( ! V_2 )
goto V_383;
if ( ! F_20 ( V_44 , & V_2 -> V_45 ) )
goto V_383;
switch ( V_503 ) {
case V_310 :
F_316 ( V_2 , V_506 -> V_507 , V_508 ) ;
break;
case V_217 :
F_316 ( V_2 , V_506 -> V_507 , V_509 ) ;
break;
default:
break;
}
V_383:
return V_517 ;
}
void F_96 ( struct V_23 * V_29 , unsigned long V_503 )
{ }
static int T_15 F_328 ( void )
{
int V_101 ;
F_329 ( V_520 L_96 , V_521 ) ;
#ifdef F_330
F_331 ( & V_522 ) ;
F_332 ( & V_523 ) ;
#endif
V_101 = F_333 ( & V_524 ) ;
if ( V_101 ) {
#ifdef F_330
F_334 ( & V_523 ) ;
F_335 ( & V_522 ) ;
#endif
}
return V_101 ;
}
static void T_16 F_336 ( void )
{
F_337 ( & V_524 ) ;
#ifdef F_330
F_334 ( & V_523 ) ;
F_335 ( & V_522 ) ;
#endif
}

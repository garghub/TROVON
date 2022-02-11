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
if ( F_28 ( V_38 ) ) {
V_50 = F_29 ( V_24 , V_38 ) ;
if ( ! V_50 )
V_50 = F_30 ( V_2 , V_38 ) ;
} else if ( F_31 ( V_38 ) ) {
V_50 = F_32 ( V_24 , V_38 ) ;
} else {
V_50 = - V_39 ;
}
}
return V_50 ;
}
static int F_33 ( struct V_46 * V_47 , struct V_48 * V_49 [] ,
struct V_23 * V_24 ,
const unsigned char * V_38 , T_3 V_40 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
int V_50 = 0 ;
if ( ! V_2 -> V_51 )
return F_34 ( V_47 , V_49 , V_24 , V_38 , V_40 ) ;
if ( ! ( V_2 -> V_40 & V_52 ) ) {
F_35 ( L_2 , V_53 ) ;
return - V_42 ;
}
if ( F_36 ( V_38 , V_2 -> V_21 ) )
return V_50 ;
if ( F_28 ( V_38 ) ) {
if ( F_37 ( V_24 ) < V_2 -> V_4 -> V_54 )
V_50 = F_38 ( V_24 , V_38 ) ;
else
V_50 = - V_55 ;
} else if ( F_31 ( V_38 ) ) {
V_50 = F_39 ( V_24 , V_38 ) ;
} else {
V_50 = - V_39 ;
}
return V_50 ;
}
static int F_40 ( struct V_56 * V_57 , struct V_58 * V_59 ,
struct V_23 * V_24 , int V_60 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
if ( ! V_2 -> V_51 )
return F_41 ( V_57 , V_59 , V_24 , V_60 ) ;
if ( V_2 -> V_40 & V_52 )
V_60 = F_41 ( V_57 , V_59 , V_24 , V_60 ) ;
return V_60 ;
}
static void F_42 ( struct V_1 * V_2 )
{
while ( F_43 ( V_61 , & V_2 -> V_45 ) )
F_44 ( 10000 , 11000 ) ;
F_45 ( & V_2 -> V_62 ) ;
}
int F_46 ( struct V_1 * V_2 , T_1 V_63 )
{
struct V_25 * V_5 = V_2 -> V_5 ;
int V_50 = - 1 , V_64 ;
int V_65 , V_66 ;
if ( V_2 -> V_40 & V_67 ) {
V_65 = 0 ;
V_66 = 0 ;
} else {
V_65 = V_2 -> V_68 ;
V_66 = 1 ;
}
if ( ! V_2 -> V_69 ) {
V_2 -> V_69 = F_47 ( V_63 ,
sizeof( struct V_70 ) ,
V_20 ) ;
if ( ! V_2 -> V_69 )
return - V_55 ;
}
V_2 -> V_71 = 1 ;
V_2 -> V_40 &= ~ ( V_72 | V_73 ) ;
if ( V_2 -> V_4 -> V_74 ) {
V_75:
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ )
V_2 -> V_69 [ V_64 ] . V_76 = V_64 ;
V_50 = F_48 ( V_5 , V_2 -> V_69 , V_63 ) ;
if ( V_50 == 0 ) {
V_2 -> V_40 |= V_73 ;
if ( F_49 ( V_2 ) ) {
V_2 -> V_4 -> V_63 = V_63 ;
V_2 -> V_71 = V_63 -
V_65 - 1 ;
} else {
V_2 -> V_71 = V_63 ;
}
F_50 ( & V_5 -> V_29 , L_3 ) ;
return V_50 ;
} else if ( V_50 > 0 ) {
F_50 ( & V_5 -> V_29 ,
L_4 ,
V_63 ) ;
if ( F_49 ( V_2 ) ) {
if ( V_50 < ( V_77 - V_66 ) )
return V_50 ;
V_50 -= ( V_65 + 1 ) ;
V_63 = F_51 ( V_50 ) ;
V_63 += ( V_65 + 1 ) ;
} else {
V_63 = F_51 ( V_50 ) ;
}
if ( V_63 ) {
F_50 ( & V_5 -> V_29 ,
L_5 ,
V_63 ) ;
goto V_75;
}
} else {
F_50 ( & V_5 -> V_29 ,
L_4 ,
V_63 ) ;
}
}
return V_50 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_50 = 0 ;
T_1 V_78 , V_79 ;
const struct V_80 * V_81 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_25 * V_5 = V_2 -> V_5 ;
if ( V_82 && ! F_53 ( V_5 ) ) {
V_2 -> V_40 |= V_72 ;
V_78 = V_83 [ V_2 -> V_4 -> V_84 ] ;
V_2 -> V_85 = F_54 ( V_2 -> V_4 ,
V_78 ) ;
F_50 ( & V_5 -> V_29 , L_6 ) ;
V_2 -> V_69 [ 0 ] . V_86 = V_5 -> V_87 ;
return V_50 ;
}
if ( V_82 || V_88 )
return - V_42 ;
V_81 = & V_89 [ V_2 -> V_4 -> V_84 ] ;
V_2 -> V_4 -> V_90 = V_81 -> V_90 ;
V_78 = V_81 -> V_85 ;
V_2 -> V_85 = F_54 ( V_4 , V_78 ) ;
V_79 = V_81 -> V_91 ;
V_2 -> V_91 = F_54 ( V_4 , V_79 ) ;
V_2 -> V_92 = F_54 ( V_4 , V_93 ) ;
V_2 -> V_94 = F_54 ( V_4 , V_95 ) ;
F_50 ( & V_5 -> V_29 , L_7 ) ;
V_2 -> V_69 [ 0 ] . V_86 = V_5 -> V_87 ;
return V_50 ;
}
int F_55 ( struct V_1 * V_2 , T_2 V_96 )
{
int V_63 , V_50 = 0 ;
if ( ! V_96 )
V_96 = V_97 ;
if ( V_2 -> V_4 -> V_74 )
V_63 = F_51 ( F_56 ( int , F_57 () ,
V_96 ) ) ;
else
V_63 = 1 ;
V_50 = F_46 ( V_2 , V_63 ) ;
if ( V_50 == - V_55 || ! V_50 )
return V_50 ;
V_50 = F_52 ( V_2 ) ;
if ( ! V_50 )
return V_50 ;
return - V_26 ;
}
void F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 & V_73 )
F_59 ( V_2 -> V_5 ) ;
if ( V_2 -> V_40 & V_72 )
F_60 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_69 ) ;
V_2 -> V_69 = NULL ;
if ( V_2 -> V_4 -> V_98 ) {
F_61 ( V_2 -> V_4 -> V_98 ) ;
V_2 -> V_4 -> V_98 = NULL ;
}
}
static void F_62 ( struct V_3 * V_4 )
{
if ( V_4 -> V_99 != NULL )
F_63 ( V_4 -> V_99 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_100 * V_101 ;
int V_102 ;
if ( ! ( V_2 -> V_40 & V_52 ) ) {
switch ( V_2 -> V_4 -> V_103 ) {
case V_104 :
V_2 -> V_4 -> V_105 = V_106 ;
break;
case V_107 :
V_2 -> V_4 -> V_105 = V_108 ;
break;
}
return 0 ;
}
if ( V_2 -> V_4 -> V_109 == V_110 )
return 0 ;
V_101 = F_47 ( V_111 , sizeof( * V_101 ) , V_20 ) ;
if ( ! V_101 )
return - V_55 ;
V_102 = F_65 ( V_2 , V_101 ) ;
F_7 ( V_101 ) ;
return V_102 ;
}
int F_66 ( struct V_1 * V_2 )
{
struct V_100 * V_101 ;
int V_64 , V_102 = 0 , V_112 = 0 ;
T_3 V_105 ;
T_2 V_113 ;
V_101 = F_47 ( V_111 , sizeof( * V_101 ) , V_20 ) ;
if ( ! V_101 )
return - V_55 ;
V_102 = F_65 ( V_2 , V_101 ) ;
if ( V_102 )
goto V_114;
V_105 = V_2 -> V_4 -> V_105 ;
V_2 -> V_115 = F_5 ( sizeof( struct V_116 ) *
V_105 , V_20 ) ;
if ( ! V_2 -> V_115 ) {
V_102 = - V_55 ;
goto V_114;
}
V_2 -> V_117 = F_5 ( sizeof( struct V_118 ) *
V_108 , V_20 ) ;
if ( ! V_2 -> V_117 ) {
V_102 = - V_55 ;
goto V_119;
}
for ( V_64 = 0 ; V_64 < V_111 ; V_64 ++ ) {
V_113 = V_101 [ V_64 ] . V_120 ;
if ( V_113 >= V_111 ) {
V_102 = V_121 ;
goto V_122;
}
if ( ! V_101 [ V_64 ] . V_123 ||
( V_101 [ V_64 ] . type != V_124 ) )
continue;
V_2 -> V_115 [ V_112 ] . V_84 = V_113 ;
V_2 -> V_115 [ V_112 ] . V_123 = ( T_2 ) V_101 [ V_64 ] . V_123 ;
V_2 -> V_115 [ V_112 ] . type = ( T_2 ) V_101 [ V_64 ] . type ;
V_2 -> V_115 [ V_112 ] . V_125 = ( T_2 ) V_101 [ V_64 ] . V_126 ;
V_2 -> V_115 [ V_112 ] . V_127 = V_101 [ V_64 ] . V_128 ;
V_2 -> V_115 [ V_112 ] . V_129 = V_101 [ V_64 ] . V_130 ;
V_112 ++ ;
}
for ( V_64 = 0 ; V_64 < V_108 ; V_64 ++ ) {
V_2 -> V_117 [ V_64 ] . V_40 |= V_131 ;
if ( F_49 ( V_2 ) )
F_67 ( V_2 , V_64 , 1 ) ;
}
F_7 ( V_101 ) ;
return 0 ;
V_122:
F_7 ( V_2 -> V_117 ) ;
V_2 -> V_117 = NULL ;
V_119:
F_7 ( V_2 -> V_115 ) ;
V_2 -> V_115 = NULL ;
V_114:
F_7 ( V_101 ) ;
return V_102 ;
}
static int
F_68 ( struct V_1 * V_2 )
{
T_2 V_120 ;
int V_102 ;
T_1 V_132 = V_110 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_102 = F_69 ( V_2 ) ;
if ( V_102 )
goto V_133;
V_120 = V_4 -> V_84 ;
V_132 = F_70 ( V_2 , V_134 ) ;
V_132 = ( V_132 & ~ F_71 ( 0xf , V_120 ) ) |
F_71 ( V_110 , V_120 ) ;
F_72 ( V_2 , V_134 , V_132 ) ;
F_73 ( V_2 ) ;
V_133:
return V_102 ;
}
static void F_74 ( struct V_1 * V_2 ,
const struct V_135 * V_136 )
{
T_1 V_109 , V_137 ;
V_2 -> V_4 -> V_138 = F_70 ( V_2 ,
V_139 ) ;
F_75 ( V_2 ) ;
V_109 = F_70 ( V_2 , V_134 ) ;
if ( V_109 == V_140 )
V_137 = V_110 ;
else
V_137 = F_76 ( V_109 , V_2 -> V_4 -> V_84 ) ;
if ( V_137 == V_141 ) {
V_2 -> V_4 -> V_109 = V_141 ;
F_50 ( & V_2 -> V_5 -> V_29 ,
L_8 ,
V_2 -> V_4 -> V_138 ) ;
V_2 -> V_142 = & V_143 ;
} else
V_2 -> V_142 = & V_144 ;
}
static void F_77 ( T_1 V_145 , T_4 * V_146 )
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
static int F_78 ( struct V_25 * V_5 ,
struct V_3 * V_4 )
{
T_1 V_78 ;
void T_5 * V_151 = NULL ;
unsigned long V_152 , V_153 = 0 , V_154 ;
V_152 = F_79 ( V_5 , 0 ) ;
F_77 ( V_5 -> V_6 , & V_154 ) ;
if ( V_152 >= V_154 ) {
V_151 = F_80 ( V_5 , 0 ) ;
if ( V_151 == NULL ) {
F_81 ( & V_5 -> V_29 , L_9 ) ;
return - V_26 ;
}
V_153 = V_152 ;
} else {
return - V_26 ;
}
F_50 ( & V_5 -> V_29 , L_10 , ( int ) ( V_152 >> 10 ) ) ;
V_4 -> V_99 = V_151 ;
V_4 -> V_153 = V_153 ;
V_78 = F_82 ( F_83 ( V_4 -> V_84 ) ) ;
F_54 ( V_4 , V_78 ) ;
return 0 ;
}
static inline bool F_84 ( struct V_1 * V_2 ,
int V_155 )
{
struct V_25 * V_5 = V_2 -> V_5 ;
unsigned short V_156 ;
bool V_102 = true ;
V_156 = V_5 -> V_156 ;
if ( V_5 -> V_6 == V_7 ||
V_5 -> V_6 == V_148 ) {
if ( V_157 [ V_155 ] . V_158 == V_156 &&
V_157 [ V_155 ] . V_159 == V_5 -> V_160 )
V_102 = true ;
else
V_102 = false ;
}
return V_102 ;
}
static void F_85 ( struct V_1 * V_2 , char * V_161 )
{
struct V_25 * V_5 = V_2 -> V_5 ;
int V_64 , V_162 = 0 ;
for ( V_64 = 0 ; V_64 < V_163 ; ++ V_64 ) {
if ( V_157 [ V_64 ] . V_164 == V_5 -> V_164 &&
V_157 [ V_64 ] . V_6 == V_5 -> V_6 &&
F_84 ( V_2 , V_64 ) ) {
V_162 = 1 ;
break;
}
}
if ( ! V_162 )
sprintf ( V_161 , L_11 , V_2 -> V_21 ) ;
else
sprintf ( V_161 , L_12 , V_2 -> V_21 ,
V_157 [ V_64 ] . V_165 ) ;
}
static void
F_86 ( struct V_1 * V_2 )
{
int V_50 ;
T_1 V_166 , V_167 , V_168 , V_169 ;
struct V_25 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_170 * V_171 = & V_4 -> V_171 ;
V_169 = V_2 -> V_172 ;
V_166 = F_70 ( V_2 , V_173 ) ;
V_167 = F_70 ( V_2 , V_174 ) ;
V_168 = F_70 ( V_2 , V_175 ) ;
V_2 -> V_172 = F_87 ( V_166 , V_167 , V_168 ) ;
V_50 = F_88 ( V_2 ) ;
if ( V_50 ) {
F_81 ( & V_5 -> V_29 , L_13 ) ;
return;
}
if ( V_4 -> V_109 != V_141 ) {
if ( V_171 -> V_176 == NULL ||
V_2 -> V_172 > V_169 ) {
if ( V_171 -> V_176 )
F_61 ( V_171 -> V_176 ) ;
if ( ! F_89 ( V_2 ) )
F_50 ( & V_5 -> V_29 ,
L_14 ) ;
}
}
F_50 ( & V_5 -> V_29 , L_15 ,
V_177 , V_166 , V_167 , V_168 ) ;
if ( V_2 -> V_4 -> V_103 == V_107 ) {
if ( V_2 -> V_40 & V_52 ) {
V_2 -> V_178 = V_179 ;
V_2 -> V_180 = V_181 ;
} else {
V_2 -> V_178 = V_182 ;
V_2 -> V_180 = V_183 ;
}
V_2 -> V_184 = V_185 ;
V_2 -> V_186 = V_185 ;
} else if ( V_2 -> V_4 -> V_103 == V_104 ) {
V_2 -> V_178 = V_187 ;
V_2 -> V_184 = V_188 ;
V_2 -> V_186 = V_188 ;
V_2 -> V_180 = V_189 ;
}
V_2 -> V_4 -> V_74 = ! ! V_88 ;
V_2 -> V_190 = V_191 ;
V_2 -> V_192 = V_193 ;
}
static int
F_90 ( struct V_1 * V_2 )
{
struct V_194 V_195 ;
int V_50 = 0 ;
memset ( & V_195 , 0 , sizeof( struct V_194 ) ) ;
V_50 = F_91 ( V_2 , & V_195 , V_2 -> V_4 -> V_84 ) ;
if ( V_50 )
return V_50 ;
V_2 -> V_4 -> V_196 = ( T_2 ) V_195 . V_197 ;
V_2 -> V_4 -> V_198 = V_195 . V_198 ;
V_2 -> V_4 -> V_199 = V_195 . V_199 ;
V_2 -> V_4 -> V_200 = V_195 . V_200 ;
V_2 -> V_4 -> V_8 = V_195 . V_8 ;
if ( V_2 -> V_4 -> V_8 & V_201 ) {
T_1 V_202 ;
V_202 = F_92 ( V_2 , V_203 , & V_50 ) ;
if ( V_50 == - V_26 )
return V_50 ;
V_2 -> V_4 -> V_204 [ 0 ] = V_202 ;
}
V_2 -> V_4 -> V_205 = V_195 . V_205 ;
V_2 -> V_4 -> V_206 = V_195 . V_206 ;
if ( F_49 ( V_2 ) )
return V_50 ;
if ( V_2 -> V_4 -> V_8 & V_207 )
V_2 -> V_40 |= V_52 ;
else
V_2 -> V_40 &= ~ V_52 ;
return V_50 ;
}
void F_93 ( struct V_1 * V_2 ,
struct V_208 * V_209 )
{
if ( V_209 -> V_210 )
V_2 -> V_40 &= ~ V_211 ;
else
V_2 -> V_40 |= V_211 ;
if ( V_209 -> V_212 ) {
V_2 -> V_213 = V_209 -> V_212 ;
V_2 -> V_214 = V_209 -> V_212 ;
} else {
V_2 -> V_213 = 0 ;
V_2 -> V_214 = 0 ;
}
}
static int
F_94 ( struct V_23 * V_24 , T_6 V_215 , T_3 V_216 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
int V_50 ;
if ( F_19 ( V_2 ) ) {
V_50 = F_95 ( V_2 , V_216 , 1 ) ;
if ( V_50 ) {
F_96 ( V_24 ,
L_16 ,
V_216 , V_50 ) ;
return V_50 ;
}
}
F_97 ( V_216 , V_2 -> V_217 ) ;
return 0 ;
}
static int
F_98 ( struct V_23 * V_24 , T_6 V_215 , T_3 V_216 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
int V_50 ;
if ( F_19 ( V_2 ) ) {
V_50 = F_95 ( V_2 , V_216 , 0 ) ;
if ( V_50 ) {
F_96 ( V_24 ,
L_17 ,
V_216 , V_50 ) ;
return V_50 ;
}
}
F_99 ( V_24 , V_218 ) ;
F_100 ( V_216 , V_2 -> V_217 ) ;
return 0 ;
}
void F_101 ( struct V_1 * V_2 ,
struct V_208 * V_209 )
{
V_2 -> V_40 &= ~ ( V_219 | V_41 |
V_220 ) ;
if ( V_209 -> V_221 )
V_2 -> V_40 |= V_219 ;
if ( ! V_209 -> V_222 )
V_2 -> V_40 |= V_41 ;
if ( ! V_209 -> V_223 )
V_2 -> V_40 |= V_220 ;
}
int F_102 ( struct V_1 * V_2 )
{
struct V_208 V_209 ;
if ( ! ( V_2 -> V_40 & V_52 ) )
return 0 ;
V_209 . V_84 = V_2 -> V_4 -> V_84 ;
if ( F_103 ( V_2 , & V_209 ) )
return - V_26 ;
F_93 ( V_2 , & V_209 ) ;
F_101 ( V_2 , & V_209 ) ;
F_104 ( V_2 , & V_209 ) ;
return 0 ;
}
void F_104 ( struct V_1 * V_2 ,
struct V_208 * V_209 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
if ( F_49 ( V_2 ) )
return;
V_2 -> V_224 = V_209 -> V_224 ;
V_2 -> V_40 |= V_225 ;
F_105 ( V_24 ) ;
V_2 -> V_40 &= ~ V_225 ;
}
static int
F_106 ( struct V_1 * V_2 )
{
T_1 V_109 , V_137 ;
int V_50 = 0 ;
V_50 = F_90 ( V_2 ) ;
if ( V_50 )
return V_50 ;
if ( V_2 -> V_40 & V_226 )
return 0 ;
V_109 = F_70 ( V_2 , V_134 ) ;
V_137 = F_76 ( V_109 , V_2 -> V_4 -> V_84 ) ;
if ( V_109 == V_140 )
V_137 = V_110 ;
else
V_137 = F_76 ( V_109 , V_2 -> V_4 -> V_84 ) ;
if ( V_2 -> V_40 & V_52 ) {
if ( V_137 == V_110 ) {
V_2 -> V_4 -> V_109 = V_110 ;
V_50 = F_66 ( V_2 ) ;
if ( V_50 )
return V_50 ;
F_68 ( V_2 ) ;
F_50 ( & V_2 -> V_5 -> V_29 ,
L_18 ,
V_2 -> V_4 -> V_138 ) ;
} else if ( V_137 == V_227 ) {
V_2 -> V_4 -> V_109 = V_227 ;
F_50 ( & V_2 -> V_5 -> V_29 ,
L_19 ,
V_2 -> V_4 -> V_138 ) ;
}
}
V_2 -> V_40 |= V_226 ;
return V_50 ;
}
int F_107 ( struct V_1 * V_2 )
{
struct V_208 V_209 ;
struct V_116 * V_228 ;
T_2 V_64 ;
if ( V_2 -> V_229 )
return 0 ;
for ( V_64 = 0 ; V_64 < V_2 -> V_4 -> V_105 ; V_64 ++ ) {
memset ( & V_209 , 0 , sizeof( struct V_208 ) ) ;
V_209 . V_84 = V_2 -> V_115 [ V_64 ] . V_84 ;
V_209 . V_222 = V_230 ;
V_209 . V_223 = V_230 ;
if ( F_108 ( V_2 ) ) {
V_209 . V_224 = V_230 ;
if ( F_109 ( V_2 ) )
V_209 . V_224 |= ( V_231 | V_232 ) ;
}
if ( F_110 ( V_2 , & V_209 ) )
return - V_26 ;
V_228 = & V_2 -> V_115 [ V_64 ] ;
V_228 -> V_233 = V_209 . V_212 ;
V_228 -> V_222 = V_209 . V_222 ;
V_228 -> V_221 = V_209 . V_221 ;
V_228 -> V_210 = V_209 . V_210 ;
V_228 -> V_223 = V_209 . V_223 ;
V_228 -> V_224 = V_209 . V_224 ;
}
return 0 ;
}
static int
F_111 ( struct V_1 * V_2 ,
struct V_116 * V_228 , int V_84 )
{
struct V_208 V_209 ;
V_209 . V_109 = V_234 ;
V_209 . V_84 = V_84 ;
V_209 . V_212 = V_228 -> V_233 ;
V_209 . V_222 = V_228 -> V_222 ;
V_209 . V_210 = V_228 -> V_210 ;
V_209 . V_221 = V_228 -> V_221 ;
V_209 . V_224 = V_228 -> V_224 ;
V_209 . V_223 = V_228 -> V_223 ;
if ( F_110 ( V_2 , & V_209 ) )
return - V_26 ;
V_209 . V_109 = V_235 ;
if ( F_110 ( V_2 , & V_209 ) )
return - V_26 ;
return 0 ;
}
int F_112 ( struct V_1 * V_2 )
{
int V_64 , V_50 ;
struct V_116 * V_228 ;
struct V_194 V_195 ;
T_2 V_84 ;
if ( F_108 ( V_2 ) )
if ( ! V_2 -> V_229 )
return 0 ;
for ( V_64 = 0 ; V_64 < V_2 -> V_4 -> V_105 ; V_64 ++ ) {
V_228 = & V_2 -> V_115 [ V_64 ] ;
V_84 = V_228 -> V_84 ;
memset ( & V_195 , 0 , sizeof( struct V_194 ) ) ;
V_50 = F_91 ( V_2 , & V_195 , V_84 ) ;
if ( V_50 )
return V_50 ;
V_195 . V_236 = V_228 -> V_127 ;
V_195 . V_237 = V_228 -> V_129 ;
V_50 = F_113 ( V_2 , & V_195 ) ;
if ( V_50 )
return V_50 ;
if ( V_228 -> V_238 ) {
V_50 = F_114 ( V_2 ,
V_228 -> V_239 , 1 ,
V_84 ) ;
if ( V_50 )
return V_50 ;
}
V_50 = F_111 ( V_2 , V_228 , V_84 ) ;
if ( V_50 )
return V_50 ;
}
return 0 ;
}
static int F_115 ( struct V_1 * V_2 )
{
T_2 V_240 = V_241 ;
T_1 V_242 ;
if ( V_2 -> V_4 -> V_109 == V_110 )
return 0 ;
V_242 = F_70 ( V_2 ,
V_243 ) ;
while ( V_242 != V_244 && -- V_240 ) {
F_116 ( 1000 ) ;
V_242 = F_70 ( V_2 ,
V_243 ) ;
}
if ( ! V_240 ) {
F_81 ( & V_2 -> V_5 -> V_29 ,
L_20 ) ;
return - V_26 ;
}
return 0 ;
}
static int
F_117 ( struct V_1 * V_2 )
{
int V_50 ;
if ( ! ( V_2 -> V_40 & V_52 ) ||
V_2 -> V_4 -> V_109 != V_110 )
return 0 ;
V_50 = F_107 ( V_2 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_112 ( V_2 ) ;
if ( V_50 )
return V_50 ;
F_118 ( V_2 ) ;
return V_50 ;
}
int F_119 ( struct V_1 * V_2 )
{
int V_50 ;
V_50 = F_120 ( V_2 ) ;
if ( V_50 < 0 )
return V_50 ;
else if ( ! V_50 )
goto V_245;
if ( V_246 )
F_121 ( V_2 ) ;
else {
V_50 = F_122 ( V_2 ) ;
if ( V_50 )
goto V_247;
V_2 -> V_4 -> V_248 = V_249 ;
}
V_50 = F_123 ( V_2 ) ;
if ( V_50 == 0 )
goto V_245;
V_50 = F_124 ( V_2 ) ;
if ( V_50 )
goto V_247;
V_50 = F_125 ( V_2 ) ;
if ( V_50 )
goto V_247;
F_126 ( V_2 ) ;
F_127 ( V_2 , V_250 , V_251 ) ;
V_245:
V_50 = F_128 ( V_2 ) ;
if ( V_50 )
goto V_247;
F_72 ( V_2 , V_252 , V_253 ) ;
F_129 ( V_2 , 1 ) ;
V_50 = F_106 ( V_2 ) ;
if ( V_50 ) {
F_81 ( & V_2 -> V_5 -> V_29 ,
L_21 ) ;
goto V_247;
}
V_50 = F_117 ( V_2 ) ;
if ( V_50 )
goto V_247;
F_86 ( V_2 ) ;
V_2 -> V_229 = 0 ;
F_126 ( V_2 ) ;
return 0 ;
V_247:
F_72 ( V_2 , V_252 , V_254 ) ;
F_81 ( & V_2 -> V_5 -> V_29 , L_22 ) ;
F_126 ( V_2 ) ;
return V_50 ;
}
static int
F_130 ( struct V_1 * V_2 )
{
T_7 V_255 ;
struct V_18 * V_256 ;
struct V_10 * V_11 ;
int V_50 , V_257 , V_258 ;
unsigned long V_40 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_259 == V_260 ) {
if ( F_108 ( V_2 ) )
V_255 = V_261 ;
else
V_255 = V_262 ;
if ( ! F_131 ( V_2 ) )
V_40 |= V_263 ;
} else {
if ( V_2 -> V_40 & V_73 )
V_255 = V_264 ;
else if ( V_2 -> V_40 & V_72 )
V_255 = V_265 ;
else {
V_40 |= V_263 ;
if ( F_108 ( V_2 ) )
V_255 = V_266 ;
else
V_255 = V_267 ;
}
}
V_2 -> V_87 = V_24 -> V_87 ;
if ( V_2 -> V_4 -> V_259 != V_268 ) {
if ( F_108 ( V_2 ) ||
( F_49 ( V_2 ) &&
( V_2 -> V_40 & V_73 ) ) ) {
V_258 = V_2 -> V_71 ;
for ( V_257 = 0 ; V_257 < V_258 ; V_257 ++ ) {
V_256 = & V_15 -> V_19 [ V_257 ] ;
if ( F_108 ( V_2 ) &&
( V_257 == ( V_258 - 1 ) ) ) {
if ( ! ( V_2 -> V_40 &
V_73 ) )
snprintf ( V_256 -> V_161 ,
sizeof( V_256 -> V_161 ) ,
L_23 ) ;
else
snprintf ( V_256 -> V_161 ,
sizeof( V_256 -> V_161 ) ,
L_24 ,
V_24 -> V_161 , V_257 ) ;
} else {
snprintf ( V_256 -> V_161 ,
sizeof( V_256 -> V_161 ) ,
L_25 ,
V_24 -> V_161 , V_257 ) ;
}
V_50 = F_132 ( V_256 -> V_87 , V_255 , V_40 ,
V_256 -> V_161 , V_256 ) ;
if ( V_50 )
return V_50 ;
}
}
if ( F_49 ( V_2 ) &&
( V_2 -> V_40 & V_73 ) &&
! ( V_2 -> V_40 & V_67 ) ) {
V_255 = V_269 ;
for ( V_257 = 0 ; V_257 < V_2 -> V_68 ;
V_257 ++ ) {
V_11 = & V_2 -> V_11 [ V_257 ] ;
snprintf ( V_11 -> V_161 , sizeof( V_11 -> V_161 ) ,
L_26 , V_24 -> V_161 , V_257 ) ;
V_50 = F_132 ( V_11 -> V_87 , V_255 , V_40 ,
V_11 -> V_161 , V_11 ) ;
if ( V_50 )
return V_50 ;
}
}
}
return 0 ;
}
static void
F_133 ( struct V_1 * V_2 )
{
int V_257 ;
struct V_18 * V_256 ;
struct V_10 * V_11 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_259 != V_268 ) {
if ( F_108 ( V_2 ) ||
( F_49 ( V_2 ) &&
( V_2 -> V_40 & V_73 ) ) ) {
for ( V_257 = 0 ; V_257 < V_2 -> V_71 ; V_257 ++ ) {
V_256 = & V_15 -> V_19 [ V_257 ] ;
F_134 ( V_256 -> V_87 , V_256 ) ;
}
}
if ( F_49 ( V_2 ) &&
! ( V_2 -> V_40 & V_67 ) ) {
for ( V_257 = 0 ; V_257 < V_2 -> V_68 ;
V_257 ++ ) {
V_11 = & V_2 -> V_11 [ V_257 ] ;
if ( V_11 -> V_87 )
F_134 ( V_11 -> V_87 , V_11 ) ;
}
}
}
}
static void F_135 ( struct V_1 * V_2 )
{
T_1 V_270 = 0 ;
if ( F_108 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_204 [ 0 ] &
V_271 )
V_2 -> V_40 |= V_272 ;
} else {
V_270 = V_2 -> V_4 -> V_8 ;
if ( F_136 ( V_270 ) )
V_2 -> V_40 |= V_272 ;
}
}
int F_137 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
int V_257 ;
struct V_273 * V_274 ;
if ( V_2 -> V_275 != V_276 )
return - V_26 ;
if ( F_20 ( V_44 , & V_2 -> V_45 ) )
return 0 ;
if ( F_102 ( V_2 ) )
return - V_26 ;
F_135 ( V_2 ) ;
if ( F_138 ( V_2 ) )
return - V_26 ;
for ( V_257 = 0 ; V_257 < V_2 -> V_192 ; V_257 ++ ) {
V_274 = & V_2 -> V_15 -> V_277 [ V_257 ] ;
F_139 ( V_2 , V_274 , V_257 ) ;
}
F_23 ( V_24 ) ;
F_140 ( V_2 , V_24 -> V_278 ) ;
V_2 -> V_4 -> V_279 = 0 ;
if ( V_2 -> V_71 > 1 )
F_141 ( V_2 , 1 ) ;
F_142 ( V_2 ) ;
if ( V_24 -> V_280 & V_281 )
F_143 ( V_2 , V_282 ) ;
F_97 ( V_44 , & V_2 -> V_45 ) ;
F_25 ( V_2 ) ;
F_144 ( V_2 , 1 ) ;
V_2 -> V_4 -> V_283 = 0 ;
return 0 ;
}
int F_145 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
int V_50 = 0 ;
F_146 () ;
if ( F_147 ( V_24 ) )
V_50 = F_137 ( V_2 , V_24 ) ;
F_148 () ;
return V_50 ;
}
void F_149 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
if ( V_2 -> V_275 != V_276 )
return;
if ( ! F_150 ( V_44 , & V_2 -> V_45 ) )
return;
if ( F_19 ( V_2 ) )
F_151 ( & V_2 -> V_4 -> V_284 -> V_285 ) ;
F_152 () ;
F_153 ( & V_2 -> V_286 ) ;
F_154 ( V_24 ) ;
V_2 -> V_4 -> V_279 = 0 ;
F_155 ( V_24 ) ;
F_156 ( V_2 ) ;
if ( V_2 -> V_287 . V_288 )
F_157 ( V_2 ) ;
F_158 ( V_2 , V_289 ) ;
F_22 ( V_2 ) ;
F_159 ( V_2 ) ;
V_2 -> V_40 &= ~ V_272 ;
F_160 ( V_2 ) ;
F_161 ( V_2 ) ;
F_162 ( & V_2 -> V_286 ) ;
}
void F_163 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
F_146 () ;
if ( F_147 ( V_24 ) )
F_149 ( V_2 , V_24 ) ;
F_148 () ;
}
int
F_164 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_25 * V_5 = V_2 -> V_5 ;
int V_50 ;
if ( V_2 -> V_275 == V_276 )
return 0 ;
V_50 = F_165 ( V_2 , V_24 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_166 ( V_2 ) ;
if ( V_50 ) {
F_81 ( & V_5 -> V_29 , L_27 ) ;
goto V_290;
}
V_50 = F_167 ( V_2 ) ;
if ( V_50 ) {
F_81 ( & V_5 -> V_29 , L_28 ) ;
goto V_291;
}
V_50 = F_130 ( V_2 ) ;
if ( V_50 ) {
F_81 ( & V_5 -> V_29 , L_29 ) ;
goto V_292;
}
F_168 ( V_2 ) ;
V_2 -> V_275 = V_276 ;
return 0 ;
V_292:
F_169 ( V_2 ) ;
V_291:
F_170 ( V_2 ) ;
V_290:
F_171 ( V_2 ) ;
return V_50 ;
}
void F_172 ( struct V_1 * V_2 )
{
if ( V_2 -> V_275 != V_276 )
return;
F_173 ( V_2 ) ;
F_169 ( V_2 ) ;
F_174 ( V_2 ) ;
F_133 ( V_2 ) ;
F_171 ( V_2 ) ;
F_170 ( V_2 ) ;
V_2 -> V_275 = 0 ;
}
void F_175 ( struct V_23 * V_24 , int V_71 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_18 * V_256 ;
int V_257 ;
F_100 ( V_44 , & V_2 -> V_45 ) ;
if ( V_2 -> V_4 -> V_259 == V_260 ) {
for ( V_257 = 0 ; V_257 < V_2 -> V_71 ; V_257 ++ ) {
V_256 = & V_2 -> V_15 -> V_19 [ V_257 ] ;
F_176 ( V_256 ) ;
}
}
F_159 ( V_2 ) ;
F_172 ( V_2 ) ;
V_2 -> V_4 -> V_259 = 0 ;
V_2 -> V_71 = V_71 ;
if ( F_164 ( V_2 ) )
goto V_293;
if ( F_147 ( V_24 ) )
F_137 ( V_2 , V_24 ) ;
V_293:
F_24 ( V_24 ) ;
}
static int F_177 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_50 = 0 ;
V_2 -> V_15 = F_5 ( sizeof( struct V_14 ) ,
V_20 ) ;
if ( ! V_2 -> V_15 ) {
V_50 = - V_55 ;
goto V_247;
}
V_4 -> V_294 . V_295 = V_296 ;
V_4 -> V_294 . type = V_297 ;
V_4 -> V_294 . V_298 = V_299 ;
V_4 -> V_294 . V_300 = V_301 ;
if ( F_49 ( V_2 ) ) {
V_4 -> V_294 . V_302 = V_303 ;
V_4 -> V_294 . V_304 = V_305 ;
}
memset ( & V_2 -> V_306 , 0 , sizeof( V_2 -> V_306 ) ) ;
V_247:
return V_50 ;
}
static void F_178 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_2 -> V_4 -> V_171 . V_176 ) {
F_61 ( V_2 -> V_4 -> V_171 . V_176 ) ;
V_2 -> V_4 -> V_171 . V_176 = NULL ;
}
F_7 ( V_2 -> V_4 -> V_307 . V_308 ) ;
V_2 -> V_4 -> V_171 . V_176 = NULL ;
}
int F_179 ( struct V_23 * V_24 , int V_309 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_18 * V_256 ;
struct V_273 * V_274 ;
int V_257 ;
int V_102 ;
F_21 ( V_24 ) ;
if ( F_147 ( V_24 ) )
F_149 ( V_2 , V_24 ) ;
F_172 ( V_2 ) ;
V_2 -> V_71 = 1 ;
V_2 -> V_4 -> V_259 = V_309 ;
V_2 -> V_4 -> V_279 = 0 ;
V_102 = F_164 ( V_2 ) ;
if ( V_102 ) {
F_24 ( V_24 ) ;
return V_102 ;
}
V_102 = F_138 ( V_2 ) ;
if ( V_102 ) {
F_172 ( V_2 ) ;
F_24 ( V_24 ) ;
return V_102 ;
}
for ( V_257 = 0 ; V_257 < V_2 -> V_192 ; V_257 ++ ) {
V_274 = & V_2 -> V_15 -> V_277 [ V_257 ] ;
F_139 ( V_2 , V_274 , V_257 ) ;
}
if ( V_2 -> V_4 -> V_259 == V_260 ) {
for ( V_257 = 0 ; V_257 < V_2 -> V_71 ; V_257 ++ ) {
V_256 = & V_2 -> V_15 -> V_19 [ V_257 ] ;
F_180 ( V_256 ) ;
}
}
if ( V_2 -> V_4 -> V_259 == V_268 ) {
V_2 -> V_4 -> V_310 = 0 ;
F_144 ( V_2 , 1 ) ;
}
F_97 ( V_44 , & V_2 -> V_45 ) ;
return 0 ;
}
static int
F_181 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
if ( F_43 ( V_61 , & V_2 -> V_45 ) )
return - V_311 ;
F_21 ( V_24 ) ;
F_163 ( V_2 , V_24 ) ;
F_145 ( V_2 , V_24 ) ;
F_24 ( V_24 ) ;
F_100 ( V_61 , & V_2 -> V_45 ) ;
F_81 ( & V_2 -> V_5 -> V_29 , L_30 , V_53 ) ;
return 0 ;
}
int
F_182 ( struct V_1 * V_2 )
{
int V_50 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( F_43 ( V_61 , & V_2 -> V_45 ) )
return - V_311 ;
if ( V_2 -> V_275 == V_276 ) {
F_21 ( V_24 ) ;
if ( F_147 ( V_24 ) )
F_149 ( V_2 , V_24 ) ;
F_172 ( V_2 ) ;
if ( F_147 ( V_24 ) ) {
V_50 = F_164 ( V_2 ) ;
if ( ! V_50 ) {
F_137 ( V_2 , V_24 ) ;
F_99 ( V_24 , V_312 ) ;
}
}
F_24 ( V_24 ) ;
}
F_100 ( V_61 , & V_2 -> V_45 ) ;
return V_50 ;
}
void F_183 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_313 = V_4 -> V_105 ;
T_3 V_16 ;
V_4 -> V_314 = V_315 ;
if ( V_313 <= 2 )
V_16 = ( V_316 - V_315 ) /
V_313 ;
else
V_16 = ( V_317 - V_315 ) /
V_313 ;
V_4 -> V_54 = V_16 ;
}
int
F_184 ( struct V_1 * V_2 , struct V_23 * V_24 ,
int V_318 )
{
int V_50 ;
struct V_25 * V_5 = V_2 -> V_5 ;
V_2 -> V_319 = 1 ;
V_2 -> V_4 -> V_320 = 0 ;
F_185 ( V_2 ) ;
V_24 -> V_321 = & V_322 ;
V_24 -> V_323 = V_324 * V_325 ;
F_186 ( V_24 , V_24 -> V_278 ) ;
if ( F_19 ( V_2 ) )
F_187 ( V_24 , & V_326 ) ;
else
F_187 ( V_24 , & V_327 ) ;
V_24 -> V_280 |= ( V_328 | V_329 | V_330 |
V_331 | V_332 |
V_333 ) ;
V_24 -> V_334 |= ( V_328 | V_329 |
V_331 ) ;
if ( F_109 ( V_2 ) ) {
V_24 -> V_280 |= ( V_335 | V_336 ) ;
V_24 -> V_334 |= ( V_335 | V_336 ) ;
}
if ( V_318 ) {
V_24 -> V_280 |= V_337 ;
V_24 -> V_334 |= V_337 ;
}
if ( F_1 ( V_2 ) )
V_24 -> V_280 |= ( V_338 ) ;
if ( F_19 ( V_2 ) )
V_24 -> V_280 |= V_339 ;
if ( V_2 -> V_4 -> V_8 & V_340 )
V_24 -> V_280 |= V_281 ;
V_24 -> V_341 = V_24 -> V_280 ;
V_24 -> V_342 |= V_343 ;
V_24 -> V_87 = V_2 -> V_69 [ 0 ] . V_86 ;
V_50 = F_188 ( V_24 ) ;
if ( V_50 ) {
F_81 ( & V_5 -> V_29 , L_31 ) ;
return V_50 ;
}
return 0 ;
}
static int F_189 ( struct V_25 * V_5 , int * V_318 )
{
if ( ! F_190 ( V_5 , F_191 ( 64 ) ) &&
! F_192 ( V_5 , F_191 ( 64 ) ) )
* V_318 = 1 ;
else if ( ! F_190 ( V_5 , F_191 ( 32 ) ) &&
! F_192 ( V_5 , F_191 ( 32 ) ) )
* V_318 = 0 ;
else {
F_81 ( & V_5 -> V_29 , L_32 ) ;
return - V_26 ;
}
return 0 ;
}
void F_193 ( struct V_1 * V_2 )
{
int V_257 ;
struct V_10 * V_11 ;
for ( V_257 = 0 ; V_257 < V_2 -> V_68 ; V_257 ++ ) {
V_11 = & V_2 -> V_11 [ V_257 ] ;
if ( V_11 && V_11 -> V_344 != NULL ) {
F_61 ( V_11 -> V_344 ) ;
V_11 -> V_344 = NULL ;
}
}
if ( V_2 -> V_11 != NULL )
F_7 ( V_2 -> V_11 ) ;
}
int F_194 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
int V_257 , V_86 , V_155 ;
struct V_10 * V_11 ;
struct V_345 * V_344 ;
V_11 = F_47 ( V_2 -> V_68 ,
sizeof( struct V_10 ) , V_20 ) ;
if ( V_11 == NULL )
return - V_55 ;
V_2 -> V_11 = V_11 ;
for ( V_257 = 0 ; V_257 < V_2 -> V_68 ; V_257 ++ ) {
V_11 = & V_2 -> V_11 [ V_257 ] ;
V_11 -> V_346 = V_2 -> V_190 ;
V_11 -> V_347 = F_195 ( V_24 , V_257 ) ;
V_344 = F_196 ( F_197 ( V_11 ) ) ;
if ( V_344 == NULL ) {
F_193 ( V_2 ) ;
return - V_55 ;
}
memset ( V_344 , 0 , F_197 ( V_11 ) ) ;
V_11 -> V_344 = V_344 ;
}
if ( F_49 ( V_2 ) ) {
for ( V_257 = 0 ; V_257 < V_2 -> V_68 ; V_257 ++ ) {
V_11 = & V_2 -> V_11 [ V_257 ] ;
V_11 -> V_2 = V_2 ;
if ( V_2 -> V_40 & V_73 ) {
V_155 = V_2 -> V_71 + V_257 ;
V_86 = V_2 -> V_69 [ V_155 ] . V_86 ;
V_11 -> V_87 = V_86 ;
}
}
}
return 0 ;
}
void F_198 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_348 = 0 ;
if ( F_108 ( V_2 ) )
V_348 = V_349 ;
else if ( F_49 ( V_2 ) )
V_348 = V_350 ;
if ( ( V_4 -> V_8 & V_201 ) &&
( V_4 -> V_204 [ 0 ] & V_351 ) )
F_199 ( V_2 , V_348 ) ;
}
static int
F_200 ( struct V_25 * V_5 , const struct V_135 * V_136 )
{
struct V_23 * V_24 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_50 , V_318 = - 1 ;
char V_352 [ V_353 + 19 ] ;
if ( V_5 -> V_354 )
return - V_355 ;
V_50 = F_201 ( V_5 ) ;
if ( V_50 )
return V_50 ;
if ( ! ( F_202 ( V_5 , 0 ) & V_356 ) ) {
V_50 = - V_355 ;
goto V_357;
}
V_50 = F_189 ( V_5 , & V_318 ) ;
if ( V_50 )
goto V_357;
V_50 = F_203 ( V_5 , V_358 ) ;
if ( V_50 )
goto V_357;
F_204 ( V_5 ) ;
F_205 ( V_5 ) ;
V_4 = F_5 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 ) {
V_50 = - V_55 ;
goto V_359;
}
switch ( V_136 -> V_6 ) {
case V_7 :
V_4 -> V_360 = & V_361 ;
V_4 -> V_362 = ( T_1 * ) V_363 ;
break;
case V_148 :
F_206 ( V_4 ) ;
break;
case V_149 :
F_207 ( V_4 ) ;
break;
default:
goto V_364;
}
V_50 = F_78 ( V_5 , V_4 ) ;
if ( V_50 )
goto V_364;
V_24 = F_208 ( sizeof( struct V_1 ) ) ;
if ( ! V_24 ) {
V_50 = - V_55 ;
goto V_365;
}
F_209 ( V_24 , & V_5 -> V_29 ) ;
V_2 = F_18 ( V_24 ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_366 = F_210 ( L_23 ) ;
if ( V_2 -> V_366 == NULL ) {
V_50 = - V_55 ;
F_81 ( & V_5 -> V_29 , L_33 ) ;
goto V_367;
}
V_50 = F_177 ( V_2 ) ;
if ( V_50 )
goto V_367;
V_2 -> V_368 = V_369 ;
V_2 -> V_4 -> V_370 = V_5 -> V_371 ;
if ( V_372 == V_373 )
V_2 -> V_51 = true ;
else if ( V_372 == V_374 )
V_2 -> V_375 = true ;
V_2 -> V_68 = 1 ;
F_211 ( & V_2 -> V_4 -> V_376 ) ;
F_212 ( & V_2 -> V_4 -> V_377 ) ;
F_213 ( & V_2 -> V_286 ) ;
F_214 ( & V_2 -> V_378 ) ;
if ( F_108 ( V_2 ) ) {
F_74 ( V_2 , V_136 ) ;
V_2 -> V_379 = V_2 -> V_4 -> V_84 ;
V_50 = F_215 ( V_2 ) ;
if ( V_50 ) {
F_81 ( & V_5 -> V_29 , L_34 ) ;
goto V_292;
}
V_50 = F_216 ( V_2 ) ;
if ( V_50 )
goto V_292;
V_2 -> V_40 |= V_380 ;
} else if ( F_49 ( V_2 ) ) {
F_217 ( V_2 , V_136 ) ;
V_2 -> V_379 = V_2 -> V_4 -> V_84 ;
V_50 = F_218 ( V_2 , V_318 ) ;
if ( V_50 ) {
F_81 ( & V_5 -> V_29 , L_35 , V_53 ) ;
goto V_292;
}
if ( F_19 ( V_2 ) )
return 0 ;
} else {
F_81 ( & V_5 -> V_29 ,
L_36 , V_53 ) ;
goto V_292;
}
if ( F_8 ( V_2 ) )
F_11 ( & V_5 -> V_29 , L_37 ) ;
if ( V_2 -> V_379 == 0 ) {
F_85 ( V_2 , V_352 ) ;
F_35 ( L_38 ,
F_219 ( V_381 ) ,
V_352 , V_2 -> V_4 -> V_370 ) ;
}
if ( F_49 ( V_2 ) && ! V_88 &&
! ! V_82 )
F_11 ( & V_5 -> V_29 ,
L_39 ) ;
V_50 = F_220 ( V_2 , 0 ) ;
if ( V_50 ) {
F_81 ( & V_5 -> V_29 , L_40 ) ;
goto V_382;
}
if ( F_49 ( V_2 ) ) {
V_50 = F_221 ( V_2 ) ;
if ( V_50 )
goto V_382;
}
V_50 = F_64 ( V_2 ) ;
if ( V_50 )
goto V_383;
V_50 = F_184 ( V_2 , V_24 , V_318 ) ;
if ( V_50 )
goto V_383;
if ( V_2 -> V_379 == 0 )
F_198 ( V_2 ) ;
F_222 ( V_5 , V_2 ) ;
if ( F_108 ( V_2 ) )
F_223 ( V_2 , V_384 ,
V_385 ) ;
switch ( V_2 -> V_4 -> V_103 ) {
case V_104 :
F_50 ( & V_2 -> V_5 -> V_29 , L_41 ,
V_2 -> V_24 -> V_161 ) ;
break;
case V_107 :
F_50 ( & V_2 -> V_5 -> V_29 , L_42 ,
V_2 -> V_24 -> V_161 ) ;
break;
}
if ( V_2 -> V_375 )
F_224 ( V_2 ) ;
F_225 ( V_2 ) ;
return 0 ;
V_383:
if ( F_49 ( V_2 ) )
F_226 ( V_2 ) ;
V_382:
F_58 ( V_2 ) ;
F_227 ( V_2 ) ;
F_228 ( V_2 , 0 ) ;
V_292:
F_178 ( V_2 ) ;
V_367:
F_229 ( V_24 ) ;
V_365:
F_62 ( V_4 ) ;
V_364:
F_7 ( V_4 ) ;
V_359:
F_230 ( V_5 ) ;
V_357:
F_222 ( V_5 , NULL ) ;
F_231 ( V_5 ) ;
return V_50 ;
}
static void F_232 ( struct V_25 * V_5 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
struct V_3 * V_4 ;
V_2 = F_233 ( V_5 ) ;
if ( V_2 == NULL )
return;
V_24 = V_2 -> V_24 ;
F_234 ( V_2 ) ;
F_227 ( V_2 ) ;
V_4 = V_2 -> V_4 ;
F_235 ( V_24 ) ;
F_236 ( V_2 ) ;
if ( F_49 ( V_2 ) ) {
F_226 ( V_2 ) ;
F_237 ( V_2 , 0 ) ;
F_45 ( & V_2 -> V_386 ) ;
}
F_172 ( V_2 ) ;
if ( V_2 -> V_115 != NULL )
F_7 ( V_2 -> V_115 ) ;
if ( V_2 -> V_117 != NULL )
F_7 ( V_2 -> V_117 ) ;
if ( F_108 ( V_2 ) )
F_228 ( V_2 , 0 ) ;
F_100 ( V_61 , & V_2 -> V_45 ) ;
F_238 ( V_2 ) ;
F_58 ( V_2 ) ;
F_239 ( V_2 ) ;
F_62 ( V_2 -> V_4 ) ;
F_126 ( V_2 ) ;
F_240 ( V_5 ) ;
F_230 ( V_5 ) ;
F_231 ( V_5 ) ;
F_222 ( V_5 , NULL ) ;
if ( V_2 -> V_366 ) {
F_241 ( V_2 -> V_366 ) ;
V_2 -> V_366 = NULL ;
}
F_178 ( V_2 ) ;
F_7 ( V_4 ) ;
F_229 ( V_24 ) ;
}
static void F_242 ( struct V_25 * V_5 )
{
if ( F_243 ( V_5 ) )
return;
F_231 ( V_5 ) ;
}
static int F_244 ( struct V_25 * V_5 , T_8 V_45 )
{
int V_387 ;
V_387 = F_243 ( V_5 ) ;
if ( V_387 )
return V_387 ;
F_245 ( V_5 , F_246 ( V_5 , V_45 ) ) ;
return 0 ;
}
static int F_247 ( struct V_25 * V_5 )
{
struct V_1 * V_2 = F_233 ( V_5 ) ;
int V_50 ;
V_50 = F_201 ( V_5 ) ;
if ( V_50 )
return V_50 ;
F_245 ( V_5 , V_388 ) ;
F_204 ( V_5 ) ;
F_248 ( V_5 ) ;
return F_249 ( V_2 ) ;
}
static int F_250 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
int V_50 ;
F_154 ( V_24 ) ;
V_50 = F_164 ( V_2 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_137 ( V_2 , V_24 ) ;
if ( V_50 )
goto V_247;
F_251 ( V_24 ) ;
return 0 ;
V_247:
F_172 ( V_2 ) ;
return V_50 ;
}
static int F_252 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
F_149 ( V_2 , V_24 ) ;
return 0 ;
}
void F_224 ( struct V_1 * V_2 )
{
void * V_33 ;
int V_64 ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_389 = 0 ;
T_3 V_105 = 0 ;
if ( V_2 -> V_287 . V_390 && V_2 -> V_287 . V_391 )
return;
V_105 = V_2 -> V_4 -> V_105 ;
F_213 ( & V_2 -> V_392 ) ;
F_213 ( & V_2 -> V_393 ) ;
if ( F_108 ( V_2 ) ) {
V_389 = V_317 ;
V_2 -> V_287 . V_394 = V_395 ;
} else {
V_389 = V_396 ;
V_2 -> V_287 . V_394 = V_397 ;
}
V_33 = F_47 ( V_2 -> V_287 . V_394 ,
sizeof( struct V_398 ) , V_399 ) ;
if ( ! V_33 )
return;
V_2 -> V_287 . V_390 = ( V_389 / V_105 ) ;
V_2 -> V_287 . V_391 = V_33 ;
F_253 ( V_24 , L_43 ,
V_105 , V_2 -> V_287 . V_390 ) ;
for ( V_64 = 0 ; V_64 < V_2 -> V_287 . V_394 ; V_64 ++ )
F_254 ( & V_2 -> V_287 . V_391 [ V_64 ] ) ;
V_2 -> V_400 . V_394 = V_2 -> V_287 . V_394 ;
V_33 = F_47 ( V_2 -> V_400 . V_394 ,
sizeof( struct V_398 ) , V_399 ) ;
if ( ! V_33 )
return;
V_2 -> V_400 . V_390 = ( V_389 / V_105 ) ;
V_2 -> V_400 . V_391 = V_33 ;
for ( V_64 = 0 ; V_64 < V_2 -> V_400 . V_394 ; V_64 ++ )
F_254 ( & V_2 -> V_400 . V_391 [ V_64 ] ) ;
}
static void F_238 ( struct V_1 * V_2 )
{
if ( V_2 -> V_287 . V_390 && V_2 -> V_287 . V_391 )
F_7 ( V_2 -> V_287 . V_391 ) ;
V_2 -> V_287 . V_391 = NULL ;
V_2 -> V_287 . V_390 = 0 ;
if ( V_2 -> V_400 . V_390 && V_2 -> V_400 . V_391 )
F_7 ( V_2 -> V_400 . V_391 ) ;
V_2 -> V_400 . V_390 = 0 ;
V_2 -> V_400 . V_391 = NULL ;
}
int F_255 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_401 , V_402 , V_202 = 0 ;
int V_403 = 0 ;
if ( F_49 ( V_2 ) )
V_202 = F_256 ( V_2 -> V_4 , V_404 ) ;
if ( F_108 ( V_2 ) )
V_202 = F_70 ( V_2 , V_405 ) ;
V_401 = F_257 ( V_202 ) ;
V_402 = F_258 ( V_202 ) ;
if ( V_401 == V_406 ) {
F_81 ( & V_24 -> V_29 ,
L_44
L_45 ,
V_402 ) ;
V_403 = 1 ;
} else if ( V_401 == V_407 ) {
if ( V_2 -> V_4 -> V_202 == V_408 ) {
F_81 ( & V_24 -> V_29 ,
L_46
L_47
L_48 ,
V_402 ) ;
}
} else {
if ( V_2 -> V_4 -> V_202 == V_407 ) {
F_50 ( & V_24 -> V_29 ,
L_49
L_50 , V_402 ) ;
}
}
V_2 -> V_4 -> V_202 = V_401 ;
return V_403 ;
}
static void F_259 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
if ( F_20 ( V_61 , & V_2 -> V_45 ) )
return;
if ( ++ V_2 -> V_409 >= V_410 ) {
F_253 ( V_24 , L_51 ) ;
if ( F_108 ( V_2 ) )
V_2 -> V_229 = 1 ;
else if ( F_49 ( V_2 ) )
F_260 ( V_2 ,
V_411 ) ;
} else {
F_253 ( V_24 , L_52 ) ;
V_2 -> V_4 -> V_283 = 1 ;
}
}
static struct V_412 * F_261 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_412 * V_306 = & V_24 -> V_306 ;
V_306 -> V_300 = V_2 -> V_306 . V_413 + V_2 -> V_306 . V_414 ;
V_306 -> V_304 = V_2 -> V_306 . V_415 ;
V_306 -> V_416 = V_2 -> V_306 . V_417 + V_2 -> V_306 . V_418 ;
V_306 -> V_419 = V_2 -> V_306 . V_420 ;
V_306 -> V_421 = V_2 -> V_306 . V_422 ;
V_306 -> V_423 = V_2 -> V_306 . V_424 ;
return V_306 ;
}
T_9 F_262 ( struct V_1 * V_2 )
{
T_1 V_425 ;
V_425 = F_263 ( V_2 -> V_92 ) ;
if ( ! ( V_425 & V_2 -> V_4 -> V_90 ) )
return V_426 ;
V_425 = F_263 ( V_2 -> V_94 ) ;
if ( ! F_264 ( V_425 ) )
return V_426 ;
F_3 ( 0xffffffff , V_2 -> V_85 ) ;
F_263 ( V_2 -> V_92 ) ;
F_263 ( V_2 -> V_92 ) ;
return V_427 ;
}
static T_9 V_261 ( int V_87 , void * V_132 )
{
struct V_18 * V_256 = V_132 ;
struct V_1 * V_2 = V_256 -> V_2 ;
if ( V_2 -> V_40 & V_73 )
goto V_428;
else if ( V_2 -> V_40 & V_72 ) {
F_3 ( 0xffffffff , V_2 -> V_85 ) ;
goto V_428;
}
if ( F_265 ( V_2 ) == V_426 )
return V_426 ;
V_428:
V_2 -> V_4 -> V_429 ++ ;
F_180 ( V_256 ) ;
return V_427 ;
}
static T_9 V_266 ( int V_87 , void * V_132 )
{
struct V_18 * V_256 = V_132 ;
struct V_1 * V_2 = V_256 -> V_2 ;
if ( F_265 ( V_2 ) == V_426 )
return V_426 ;
F_266 ( & V_256 -> V_430 ) ;
return V_427 ;
}
static T_9 V_265 ( int V_87 , void * V_132 )
{
struct V_18 * V_256 = V_132 ;
struct V_1 * V_2 = V_256 -> V_2 ;
F_3 ( 0xffffffff , V_2 -> V_85 ) ;
F_266 ( & V_256 -> V_430 ) ;
return V_427 ;
}
static T_9 V_264 ( int V_87 , void * V_132 )
{
struct V_18 * V_256 = V_132 ;
F_266 ( & V_256 -> V_430 ) ;
return V_427 ;
}
static T_9 V_269 ( int V_87 , void * V_132 )
{
struct V_10 * V_11 = V_132 ;
F_266 ( & V_11 -> V_430 ) ;
return V_427 ;
}
static void F_267 ( struct V_23 * V_24 )
{
int V_257 ;
struct V_18 * V_256 ;
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
F_268 ( V_2 -> V_87 ) ;
for ( V_257 = 0 ; V_257 < V_2 -> V_71 ; V_257 ++ ) {
V_256 = & V_15 -> V_19 [ V_257 ] ;
V_266 ( V_2 -> V_87 , V_256 ) ;
}
F_269 ( V_2 -> V_87 ) ;
}
static void
F_129 ( struct V_1 * V_2 , T_2 V_431 )
{
T_1 V_432 ;
V_432 = V_2 -> V_379 & 0xf ;
V_432 |= V_431 << 7 ;
V_432 |= ( V_369 - V_2 -> V_368 ) << 8 ;
F_72 ( V_2 , V_433 , V_432 ) ;
V_2 -> V_368 = V_369 ;
}
static int
F_270 ( struct V_1 * V_2 , T_2 V_45 )
{
T_1 V_432 ;
F_271 ( V_45 != V_434 &&
V_45 != V_435 ) ;
if ( F_69 ( V_2 ) )
return - V_26 ;
V_432 = F_70 ( V_2 , V_436 ) ;
if ( V_45 == V_434 )
F_272 ( V_432 , V_2 -> V_379 ) ;
else if ( V_45 == V_435 )
F_273 ( V_432 , V_2 -> V_379 ) ;
F_72 ( V_2 , V_436 , V_432 ) ;
F_73 ( V_2 ) ;
return 0 ;
}
static int
F_274 ( struct V_1 * V_2 )
{
T_1 V_432 ;
if ( F_69 ( V_2 ) )
return - V_311 ;
V_432 = F_70 ( V_2 , V_436 ) ;
F_275 ( V_432 , V_2 -> V_379 ) ;
F_72 ( V_2 , V_436 , V_432 ) ;
F_73 ( V_2 ) ;
return 0 ;
}
void F_228 ( struct V_1 * V_2 , T_2 V_437 )
{
T_1 V_432 ;
if ( F_69 ( V_2 ) )
goto V_50;
V_432 = F_70 ( V_2 , V_438 ) ;
F_276 ( V_432 , V_2 -> V_379 ) ;
F_72 ( V_2 , V_438 , V_432 ) ;
if ( V_437 ) {
F_72 ( V_2 , V_252 ,
V_254 ) ;
F_50 ( & V_2 -> V_5 -> V_29 ,
L_53 ) ;
} else if ( ! ( V_432 & 0x11111111 ) )
F_72 ( V_2 , V_252 ,
V_439 ) ;
V_432 = F_70 ( V_2 , V_436 ) ;
F_275 ( V_432 , V_2 -> V_379 ) ;
F_72 ( V_2 , V_436 , V_432 ) ;
F_73 ( V_2 ) ;
V_50:
V_2 -> V_440 = 0 ;
V_2 -> V_40 &= ~ V_441 ;
F_100 ( V_442 , & V_2 -> V_45 ) ;
F_100 ( V_61 , & V_2 -> V_45 ) ;
}
static int
F_277 ( struct V_1 * V_2 )
{
int V_443 , V_45 , V_444 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_45 = F_70 ( V_2 , V_436 ) ;
V_443 = F_70 ( V_2 , V_438 ) ;
if ( V_2 -> V_40 & V_445 ) {
V_444 = ( ~ ( 1 << ( V_4 -> V_84 * 4 ) ) ) ;
V_443 = V_443 & V_444 ;
}
if ( ( ( V_45 & 0x11111111 ) == ( V_443 & 0x11111111 ) ) ||
( ( V_443 & 0x11111111 ) == ( ( V_45 >> 1 ) & 0x11111111 ) ) )
return 0 ;
else
return 1 ;
}
static int F_278 ( struct V_1 * V_2 )
{
T_1 V_432 = F_70 ( V_2 , V_446 ) ;
if ( V_432 != V_447 ) {
F_11 ( & V_2 -> V_5 -> V_29 , L_54
L_55 , V_447 , V_432 ) ;
}
return 0 ;
}
static int
F_120 ( struct V_1 * V_2 )
{
T_1 V_432 , V_448 ;
T_2 V_449 = V_2 -> V_449 ;
T_2 V_379 = V_2 -> V_379 ;
T_2 V_102 ;
if ( F_150 ( V_442 , & V_2 -> V_45 ) )
return 1 ;
if ( F_69 ( V_2 ) )
return - 1 ;
V_432 = F_70 ( V_2 , V_438 ) ;
if ( ! ( V_432 & ( 1 << ( V_379 * 4 ) ) ) ) {
F_279 ( V_432 , V_379 ) ;
F_72 ( V_2 , V_438 , V_432 ) ;
}
V_448 = F_70 ( V_2 , V_252 ) ;
F_280 ( V_2 , V_450 , L_56 , V_448 ) ;
switch ( V_448 ) {
case V_439 :
F_72 ( V_2 , V_252 ,
V_451 ) ;
F_72 ( V_2 , V_446 ,
V_447 ) ;
F_129 ( V_2 , 0 ) ;
F_73 ( V_2 ) ;
return 1 ;
case V_253 :
V_102 = F_278 ( V_2 ) ;
F_73 ( V_2 ) ;
return V_102 ;
case V_434 :
V_432 = F_70 ( V_2 , V_436 ) ;
F_272 ( V_432 , V_379 ) ;
F_72 ( V_2 , V_436 , V_432 ) ;
break;
case V_435 :
V_432 = F_70 ( V_2 , V_436 ) ;
F_273 ( V_432 , V_379 ) ;
F_72 ( V_2 , V_436 , V_432 ) ;
break;
case V_254 :
F_81 ( & V_2 -> V_5 -> V_29 , L_57 ) ;
F_73 ( V_2 ) ;
return - 1 ;
case V_451 :
case V_452 :
break;
}
F_73 ( V_2 ) ;
do {
F_116 ( 1000 ) ;
V_448 = F_70 ( V_2 , V_252 ) ;
if ( V_448 == V_452 )
continue;
} while ( ( V_448 != V_253 ) && -- V_449 );
if ( ! V_449 ) {
F_81 ( & V_2 -> V_5 -> V_29 ,
L_58 ) ;
return - 1 ;
}
if ( F_69 ( V_2 ) )
return - 1 ;
V_432 = F_70 ( V_2 , V_436 ) ;
F_275 ( V_432 , V_379 ) ;
F_72 ( V_2 , V_436 , V_432 ) ;
V_102 = F_278 ( V_2 ) ;
F_73 ( V_2 ) ;
return V_102 ;
}
static void
F_281 ( struct V_453 * V_454 )
{
struct V_1 * V_2 = F_282 ( V_454 ,
struct V_1 , V_62 . V_454 ) ;
T_1 V_455 = 0xf ;
T_1 V_432 ;
if ( F_69 ( V_2 ) )
goto V_456;
V_455 = F_70 ( V_2 , V_252 ) ;
if ( V_455 == V_452 ||
V_455 == V_435 ) {
F_73 ( V_2 ) ;
F_223 ( V_2 , F_281 ,
V_385 * 2 ) ;
return;
}
if ( V_2 -> V_4 -> V_109 == V_141 ) {
F_73 ( V_2 ) ;
goto V_457;
}
if ( V_455 == V_451 ||
V_455 == V_253 ) {
F_50 ( & V_2 -> V_5 -> V_29 , L_59
L_60 ) ;
goto V_458;
}
if ( V_2 -> V_459 ++ > V_2 -> V_460 ) {
F_50 ( & V_2 -> V_5 -> V_29 , L_61 ,
V_2 -> V_460 ) ;
goto V_458;
}
if ( ! F_277 ( V_2 ) ) {
V_458:
V_455 = F_70 ( V_2 , V_252 ) ;
if ( V_455 == V_434 ) {
F_72 ( V_2 , V_252 ,
V_451 ) ;
F_97 ( V_442 , & V_2 -> V_45 ) ;
F_280 ( V_2 , V_461 , L_62 ) ;
F_129 ( V_2 , 0 ) ;
V_432 = F_70 ( V_2 ,
V_436 ) ;
F_272 ( V_432 , V_2 -> V_379 ) ;
F_72 ( V_2 ,
V_436 , V_432 ) ;
}
F_73 ( V_2 ) ;
F_146 () ;
if ( V_2 -> V_4 -> V_171 . V_462 &&
( V_2 -> V_40 & V_445 ) ) {
F_280 ( V_2 , V_461 , L_63 ) ;
F_283 ( V_2 ) ;
V_2 -> V_40 |= V_441 ;
}
F_148 () ;
V_2 -> V_40 &= ~ V_445 ;
if ( ! V_2 -> V_142 -> V_463 ( V_2 ) ) {
F_223 ( V_2 , V_464 , 0 ) ;
V_2 -> V_459 = 0 ;
return;
}
goto V_456;
}
F_73 ( V_2 ) ;
V_457:
V_455 = F_70 ( V_2 , V_252 ) ;
F_280 ( V_2 , V_450 , L_64 , V_455 ) ;
switch ( V_455 ) {
case V_253 :
if ( ! F_215 ( V_2 ) ) {
F_223 ( V_2 , V_464 , 0 ) ;
V_2 -> V_459 = 0 ;
return;
}
case V_254 :
break;
default:
F_223 ( V_2 ,
F_281 , V_385 ) ;
return;
}
V_456:
F_81 ( & V_2 -> V_5 -> V_29 , L_65
L_66 , V_455 , V_2 -> V_459 ) ;
F_24 ( V_2 -> V_24 ) ;
F_228 ( V_2 , 0 ) ;
}
static void
F_284 ( struct V_453 * V_454 )
{
struct V_1 * V_2 = F_282 ( V_454 ,
struct V_1 , V_62 . V_454 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_425 ;
F_21 ( V_24 ) ;
if ( V_2 -> V_455 == V_435 ) {
if ( F_147 ( V_24 ) )
F_149 ( V_2 , V_24 ) ;
} else
F_163 ( V_2 , V_24 ) ;
V_425 = F_70 ( V_2 , V_465 ) ;
if ( V_425 & V_466 ) {
F_81 ( & V_2 -> V_5 -> V_29 ,
L_67 ,
V_425 ) ;
if ( F_285 ( V_425 ) == V_467 ) {
F_81 ( & V_2 -> V_5 -> V_29 ,
L_68
L_69 ) ;
F_81 ( & V_2 -> V_5 -> V_29 ,
L_70 ) ;
}
goto V_456;
}
if ( V_2 -> V_4 -> V_202 == V_406 ) {
F_81 ( & V_2 -> V_5 -> V_29 , L_71 ,
V_2 -> V_4 -> V_202 ) ;
goto V_456;
}
if ( ! ( V_2 -> V_40 & V_445 ) ) {
if ( F_270 ( V_2 , V_2 -> V_455 ) ) {
F_81 ( & V_2 -> V_5 -> V_29 ,
L_72
L_73 ) ;
goto V_456;
}
}
V_2 -> V_459 = 0 ;
F_223 ( V_2 , F_281 , V_385 ) ;
return;
V_456:
F_24 ( V_24 ) ;
F_228 ( V_2 , 1 ) ;
}
static void
F_286 ( struct V_1 * V_2 )
{
T_1 V_45 ;
V_45 = F_70 ( V_2 , V_243 ) ;
if ( V_45 == V_468 )
return;
if ( F_69 ( V_2 ) )
return;
F_72 ( V_2 , V_243 ,
V_468 ) ;
F_73 ( V_2 ) ;
}
void F_287 ( struct V_1 * V_2 , T_1 V_469 )
{
T_1 V_45 , V_470 = 0 , V_471 = 0 ;
F_288 ( V_470 ) ;
F_289 ( V_470 ) ;
F_127 ( V_2 , V_472 , V_470 ) ;
F_290 ( V_471 ) ;
F_291 ( V_471 ) ;
F_292 ( V_471 ) ;
F_293 ( V_471 ) ;
F_127 ( V_2 , V_473 , V_471 ) ;
F_50 ( & V_2 -> V_5 -> V_29 , L_74
L_75 ) ;
V_2 -> V_229 = 1 ;
if ( F_69 ( V_2 ) )
return;
V_45 = F_70 ( V_2 , V_252 ) ;
if ( V_45 == V_253 ) {
F_72 ( V_2 , V_252 ,
V_434 ) ;
V_2 -> V_40 |= V_445 ;
F_280 ( V_2 , V_461 , L_76 ) ;
F_129 ( V_2 , 0 ) ;
}
F_72 ( V_2 , V_243 ,
V_468 ) ;
F_73 ( V_2 ) ;
}
static void
F_118 ( struct V_1 * V_2 )
{
if ( F_69 ( V_2 ) )
return;
F_72 ( V_2 , V_243 ,
V_244 ) ;
F_280 ( V_2 , V_461 , L_77 ) ;
F_73 ( V_2 ) ;
}
void F_223 ( struct V_1 * V_2 ,
T_10 V_474 , int V_475 )
{
if ( F_20 ( V_476 , & V_2 -> V_45 ) )
return;
F_294 ( & V_2 -> V_62 , V_474 ) ;
F_295 ( V_2 -> V_366 , & V_2 -> V_62 ,
F_296 ( V_475 ) ) ;
}
static void
V_464 ( struct V_453 * V_454 )
{
struct V_1 * V_2 = F_282 ( V_454 ,
struct V_1 , V_62 . V_454 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_242 ;
if ( V_2 -> V_4 -> V_109 != V_110 ) {
V_242 = F_70 ( V_2 ,
V_243 ) ;
if ( V_2 -> V_459 ++ > V_241 )
F_228 ( V_2 , 0 ) ;
else if ( V_242 != V_244 )
F_223 ( V_2 , V_464 ,
V_385 ) ;
else
goto V_477;
F_280 ( V_2 , V_461 , L_78 ) ;
return;
}
V_477:
if ( F_147 ( V_24 ) ) {
if ( F_145 ( V_2 , V_24 ) )
goto V_428;
F_99 ( V_24 , V_312 ) ;
}
V_428:
F_24 ( V_24 ) ;
V_2 -> V_440 = 0 ;
V_2 -> V_40 &= ~ V_441 ;
F_100 ( V_61 , & V_2 -> V_45 ) ;
if ( V_2 -> V_379 == 0 )
F_198 ( V_2 ) ;
if ( ! F_274 ( V_2 ) )
F_223 ( V_2 , V_384 ,
V_385 ) ;
}
static int
F_297 ( struct V_1 * V_2 )
{
T_1 V_45 = 0 , V_478 ;
T_1 V_479 ;
int V_50 = 0 ;
if ( F_255 ( V_2 ) )
goto V_480;
if ( V_2 -> V_229 )
F_298 ( V_2 , 0 ) ;
V_45 = F_70 ( V_2 , V_252 ) ;
if ( V_45 == V_434 ) {
F_286 ( V_2 ) ;
V_2 -> V_229 = 1 ;
} else if ( V_45 == V_435 )
goto V_480;
V_478 = F_70 ( V_2 , V_481 ) ;
if ( V_478 != V_2 -> V_478 ) {
V_2 -> V_478 = V_478 ;
V_2 -> V_440 = 0 ;
if ( V_2 -> V_229 )
goto V_480;
if ( V_2 -> V_4 -> V_283 && V_482 )
F_181 ( V_2 ) ;
return 0 ;
}
if ( ++ V_2 -> V_440 < V_483 )
return 0 ;
V_2 -> V_40 |= V_441 ;
F_298 ( V_2 , 0 ) ;
if ( V_482 )
F_100 ( V_484 , & V_2 -> V_45 ) ;
F_81 ( & V_2 -> V_5 -> V_29 , L_79 ) ;
V_479 = F_70 ( V_2 , V_465 ) ;
F_81 ( & V_2 -> V_5 -> V_29 , L_80
L_81
L_82
L_83
L_84 ,
V_479 ,
F_70 ( V_2 , V_485 ) ,
F_92 ( V_2 , V_486 + 0x3c , & V_50 ) ,
F_92 ( V_2 , V_487 + 0x3c , & V_50 ) ,
F_92 ( V_2 , V_488 + 0x3c , & V_50 ) ,
F_92 ( V_2 , V_489 + 0x3c , & V_50 ) ,
F_92 ( V_2 , V_490 + 0x3c , & V_50 ) ) ;
if ( F_285 ( V_479 ) == 0x67 )
F_81 ( & V_2 -> V_5 -> V_29 ,
L_85
L_86 ) ;
V_480:
V_2 -> V_455 = ( V_45 == V_435 ) ? V_45 :
V_434 ;
if ( V_482 && ! F_43 ( V_61 ,
& V_2 -> V_45 ) ) {
F_223 ( V_2 , F_284 , 0 ) ;
F_280 ( V_2 , V_461 , L_87 ) ;
}
return 1 ;
}
void V_384 ( struct V_453 * V_454 )
{
struct V_1 * V_2 = F_282 ( V_454 ,
struct V_1 , V_62 . V_454 ) ;
if ( F_20 ( V_61 , & V_2 -> V_45 ) )
goto V_491;
if ( F_297 ( V_2 ) )
return;
if ( V_2 -> V_287 . V_288 )
F_299 ( V_2 ) ;
V_491:
F_223 ( V_2 , V_384 , V_385 ) ;
}
static int F_300 ( struct V_25 * V_5 )
{
struct V_25 * V_492 ;
int V_432 = V_5 -> V_493 ;
while ( V_432 -- > 0 ) {
V_492 = F_301 ( F_302
( V_5 -> V_494 ) , V_5 -> V_494 -> V_495 ,
F_303 ( F_304 ( V_5 -> V_493 ) , V_432 ) ) ;
if ( ! V_492 )
continue;
if ( V_492 -> V_496 != V_497 ) {
F_305 ( V_492 ) ;
return 0 ;
}
F_305 ( V_492 ) ;
}
return 1 ;
}
static int F_306 ( struct V_25 * V_5 )
{
int V_50 , V_498 ;
struct V_1 * V_2 = F_233 ( V_5 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
V_5 -> V_499 = V_500 ;
V_50 = F_201 ( V_5 ) ;
if ( V_50 )
return V_50 ;
F_204 ( V_5 ) ;
F_248 ( V_5 ) ;
V_498 = F_300 ( V_5 ) ;
if ( F_69 ( V_2 ) )
return - V_39 ;
if ( V_2 -> V_4 -> V_109 != V_141 && V_498 ) {
V_2 -> V_229 = 1 ;
F_97 ( V_442 , & V_2 -> V_45 ) ;
F_72 ( V_2 , V_252 ,
V_451 ) ;
F_280 ( V_2 , V_461 , L_62 ) ;
}
F_73 ( V_2 ) ;
V_50 = F_215 ( V_2 ) ;
if ( V_50 )
return V_50 ;
F_274 ( V_2 ) ;
F_7 ( V_2 -> V_69 ) ;
V_2 -> V_69 = NULL ;
V_50 = F_220 ( V_2 , 0 ) ;
if ( V_50 ) {
F_7 ( V_2 -> V_69 ) ;
F_96 ( V_24 , L_29 ) ;
return V_50 ;
}
if ( F_49 ( V_2 ) ) {
F_237 ( V_2 , 1 ) ;
V_50 = F_221 ( V_2 ) ;
if ( V_50 ) {
F_81 ( & V_2 -> V_5 -> V_29 ,
L_88 ) ;
F_228 ( V_2 , 1 ) ;
F_100 ( V_476 , & V_2 -> V_45 ) ;
goto V_428;
}
}
if ( F_147 ( V_24 ) ) {
V_50 = F_164 ( V_2 ) ;
if ( V_50 ) {
F_228 ( V_2 , 1 ) ;
F_100 ( V_476 , & V_2 -> V_45 ) ;
F_24 ( V_24 ) ;
return V_50 ;
}
V_50 = F_145 ( V_2 , V_24 ) ;
if ( V_50 )
goto V_428;
F_99 ( V_24 , V_312 ) ;
}
V_428:
F_24 ( V_24 ) ;
return V_50 ;
}
static T_11 F_307 ( struct V_25 * V_5 ,
T_12 V_45 )
{
struct V_1 * V_2 = F_233 ( V_5 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( V_45 == V_501 )
return V_502 ;
if ( V_45 == V_500 )
return V_503 ;
F_97 ( V_476 , & V_2 -> V_45 ) ;
F_21 ( V_24 ) ;
F_45 ( & V_2 -> V_62 ) ;
if ( F_147 ( V_24 ) )
F_163 ( V_2 , V_24 ) ;
if ( F_49 ( V_2 ) ) {
F_226 ( V_2 ) ;
F_237 ( V_2 , 0 ) ;
F_45 ( & V_2 -> V_386 ) ;
}
F_172 ( V_2 ) ;
F_58 ( V_2 ) ;
F_100 ( V_61 , & V_2 -> V_45 ) ;
F_308 ( V_5 ) ;
F_231 ( V_5 ) ;
return V_504 ;
}
static T_11 F_309 ( struct V_25 * V_5 )
{
return F_306 ( V_5 ) ? V_502 :
V_503 ;
}
static void F_310 ( struct V_25 * V_5 )
{
T_1 V_45 ;
struct V_1 * V_2 = F_233 ( V_5 ) ;
F_311 ( V_5 ) ;
V_45 = F_70 ( V_2 , V_252 ) ;
if ( V_45 == V_253 && F_150 ( V_476 ,
& V_2 -> V_45 ) )
F_223 ( V_2 , V_384 ,
V_385 ) ;
}
static int
F_312 ( struct V_1 * V_2 )
{
int V_50 ;
V_50 = F_120 ( V_2 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_115 ( V_2 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_90 ( V_2 ) ;
if ( V_50 )
return V_50 ;
F_86 ( V_2 ) ;
V_50 = F_102 ( V_2 ) ;
if ( V_50 )
return V_50 ;
V_2 -> V_229 = 0 ;
return V_50 ;
}
int F_313 ( struct V_1 * V_2 ,
T_13 V_432 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
T_2 V_505 = V_2 -> V_4 -> V_200 ;
T_1 V_506 ;
if ( V_432 > V_507 ) {
F_96 ( V_24 , L_89 ,
V_507 ) ;
return - V_39 ;
}
V_506 = F_51 ( F_56 ( int , V_505 ,
F_57 () ) ) ;
if ( ( V_432 > V_506 ) || ( V_432 < 2 ) || ! F_314 ( V_432 ) ) {
if ( ! F_314 ( V_432 ) )
F_96 ( V_24 , L_90 ) ;
if ( V_432 < 2 )
F_96 ( V_24 , L_91 ) ;
if ( V_432 > V_505 )
F_96 ( V_24 ,
L_92 ,
V_505 ) ;
if ( V_432 > F_57 () )
F_96 ( V_24 ,
L_93 ,
F_57 () ) ;
F_96 ( V_24 , L_94 , V_432 ) ;
return - V_39 ;
}
return 0 ;
}
int F_315 ( struct V_1 * V_2 , T_2 V_132 , T_14 V_508 )
{
int V_50 ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( F_20 ( V_61 , & V_2 -> V_45 ) )
return - V_311 ;
F_21 ( V_24 ) ;
if ( F_147 ( V_24 ) )
F_149 ( V_2 , V_24 ) ;
F_172 ( V_2 ) ;
if ( F_49 ( V_2 ) ) {
F_226 ( V_2 ) ;
F_316 ( V_2 ) ;
}
F_58 ( V_2 ) ;
V_50 = F_220 ( V_2 , V_132 ) ;
if ( V_50 ) {
F_7 ( V_2 -> V_69 ) ;
F_96 ( V_24 , L_29 ) ;
return V_50 ;
}
if ( F_49 ( V_2 ) ) {
F_237 ( V_2 , 1 ) ;
V_50 = F_221 ( V_2 ) ;
F_317 ( V_2 ) ;
if ( V_50 ) {
F_81 ( & V_2 -> V_5 -> V_29 ,
L_88 ) ;
goto V_428;
}
}
if ( F_147 ( V_24 ) ) {
V_50 = F_164 ( V_2 ) ;
if ( V_50 )
goto V_428;
V_50 = F_137 ( V_2 , V_24 ) ;
if ( V_50 )
goto V_428;
F_99 ( V_24 , V_312 ) ;
}
V_50 = V_508 ;
V_428:
F_24 ( V_24 ) ;
F_100 ( V_61 , & V_2 -> V_45 ) ;
return V_50 ;
}
static void
F_318 ( struct V_1 * V_2 ,
struct V_23 * V_29 , unsigned long V_509 )
{
struct V_510 * V_511 ;
V_511 = F_319 ( V_29 ) ;
if ( ! V_511 )
return;
F_320 (indev) {
switch ( V_509 ) {
case V_312 :
F_321 ( V_2 ,
V_512 -> V_513 , V_514 ) ;
break;
case V_218 :
F_321 ( V_2 ,
V_512 -> V_513 , V_515 ) ;
break;
default:
break;
}
} F_322 ( V_511 ) ;
F_323 ( V_511 ) ;
}
void F_99 ( struct V_23 * V_24 , unsigned long V_509 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_23 * V_29 ;
T_3 V_216 ;
F_318 ( V_2 , V_24 , V_509 ) ;
F_324 () ;
F_325 (vid, adapter->vlans, VLAN_N_VID) {
V_29 = F_326 ( V_24 , F_327 ( V_516 ) , V_216 ) ;
if ( ! V_29 )
continue;
F_318 ( V_2 , V_29 , V_509 ) ;
}
F_328 () ;
}
static int F_329 ( struct V_517 * V_518 ,
unsigned long V_509 , void * V_519 )
{
struct V_1 * V_2 ;
struct V_23 * V_29 = F_330 ( V_519 ) ;
V_520:
if ( V_29 == NULL )
goto V_428;
if ( V_29 -> V_342 & V_521 ) {
V_29 = F_331 ( V_29 ) ;
goto V_520;
}
if ( ! F_332 ( V_29 ) )
goto V_428;
V_2 = F_18 ( V_29 ) ;
if ( ! V_2 )
goto V_428;
if ( ! F_20 ( V_44 , & V_2 -> V_45 ) )
goto V_428;
F_318 ( V_2 , V_29 , V_509 ) ;
V_428:
return V_522 ;
}
static int
F_333 ( struct V_517 * V_518 ,
unsigned long V_509 , void * V_519 )
{
struct V_1 * V_2 ;
struct V_23 * V_29 ;
struct V_523 * V_512 = (struct V_523 * ) V_519 ;
V_29 = V_512 -> V_524 ? V_512 -> V_524 -> V_29 : NULL ;
V_520:
if ( V_29 == NULL )
goto V_428;
if ( V_29 -> V_342 & V_521 ) {
V_29 = F_331 ( V_29 ) ;
goto V_520;
}
if ( ! F_332 ( V_29 ) )
goto V_428;
V_2 = F_18 ( V_29 ) ;
if ( ! V_2 )
goto V_428;
if ( ! F_20 ( V_44 , & V_2 -> V_45 ) )
goto V_428;
switch ( V_509 ) {
case V_312 :
F_321 ( V_2 , V_512 -> V_513 , V_514 ) ;
break;
case V_218 :
F_321 ( V_2 , V_512 -> V_513 , V_515 ) ;
break;
default:
break;
}
V_428:
return V_522 ;
}
void F_99 ( struct V_23 * V_29 , unsigned long V_509 )
{ }
static int T_15 F_334 ( void )
{
int V_102 ;
F_335 ( V_525 L_95 , V_526 ) ;
#ifdef F_336
F_337 ( & V_527 ) ;
F_338 ( & V_528 ) ;
#endif
V_102 = F_339 ( & V_529 ) ;
if ( V_102 ) {
#ifdef F_336
F_340 ( & V_528 ) ;
F_341 ( & V_527 ) ;
#endif
}
return V_102 ;
}
static void T_16 F_342 ( void )
{
F_343 ( & V_529 ) ;
#ifdef F_336
F_340 ( & V_528 ) ;
F_341 ( & V_527 ) ;
#endif
}

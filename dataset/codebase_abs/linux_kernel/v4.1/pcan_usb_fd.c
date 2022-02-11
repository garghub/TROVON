static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & 0xf ;
}
static inline
struct V_4 * F_2 ( struct V_5 * V_6 )
{
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_6 ) ;
return V_8 -> V_9 ;
}
static inline void * F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_6 ) ;
return V_8 -> V_10 ;
}
static int F_5 ( struct V_5 * V_6 , void * V_11 )
{
void * V_12 = F_4 ( V_6 ) ;
int V_13 = 0 ;
T_1 * V_14 ;
int V_15 , V_16 = 1 , V_17 ;
T_2 V_18 ;
if ( ! ( V_6 -> V_19 & V_20 ) )
return 0 ;
V_18 = V_11 - V_12 ;
if ( V_18 <= ( V_21 - sizeof( V_22 ) ) ) {
memset ( V_11 , 0xff , sizeof( V_22 ) ) ;
V_18 += sizeof( V_22 ) ;
}
V_14 = V_12 ;
if ( ( V_6 -> V_23 -> V_24 != V_25 ) &&
( V_18 > V_26 ) ) {
V_17 = V_26 ;
V_16 += V_18 / V_17 ;
} else {
V_17 = V_18 ;
}
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_13 = F_6 ( V_6 -> V_23 ,
F_7 ( V_6 -> V_23 ,
V_27 ) ,
V_14 , V_17 ,
NULL , V_28 ) ;
if ( V_13 ) {
F_8 ( V_6 -> V_29 ,
L_1 , V_13 ) ;
break;
}
V_14 += V_17 ;
}
return V_13 ;
}
static int F_9 ( struct V_5 * V_6 , T_1 * V_30 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
T_1 * V_35 = V_30 ;
V_32 = (struct V_31 * ) V_35 ;
V_32 -> V_36 = F_10 ( V_6 ,
V_37 ) ;
V_32 -> V_38 = F_11 ( V_39 | V_40 ) ;
V_32 -> V_41 = 0 ;
V_32 -> V_42 = 0 ;
V_35 += sizeof( struct V_31 ) ;
if ( V_6 -> V_43 . V_44 & V_45 ) {
struct V_46 * V_47 = (struct V_46 * ) V_35 ;
V_47 -> V_36 =
( V_6 -> V_43 . V_48 & V_45 ) ?
F_10 ( V_6 ,
V_49 ) :
F_10 ( V_6 , V_50 ) ;
V_47 -> V_51 = F_11 ( V_52 ) ;
V_47 -> V_53 = 0 ;
V_35 += sizeof( struct V_46 ) ;
}
V_34 = (struct V_33 * ) V_35 ;
V_34 -> V_36 = F_10 ( V_6 ,
( V_6 -> V_43 . V_48 & V_54 ) ?
V_55 :
V_56 ) ;
V_35 += sizeof( struct V_33 ) ;
return V_35 - V_30 ;
}
static int F_12 ( struct V_5 * V_6 , T_1 V_57 )
{
T_1 * V_35 = F_4 ( V_6 ) ;
int V_58 ;
if ( V_57 ) {
V_58 = F_9 ( V_6 , V_35 ) ;
} else {
struct V_33 * V_34 = (struct V_33 * ) V_35 ;
V_34 -> V_36 = F_10 ( V_6 ,
V_59 ) ;
V_58 = sizeof( struct V_33 ) ;
}
return F_5 ( V_6 , V_35 + V_58 ) ;
}
static int F_13 ( struct V_5 * V_6 , int V_60 ,
T_3 V_61 )
{
struct V_62 * V_34 = F_4 ( V_6 ) ;
int V_15 , V_16 ;
if ( ( V_60 < 0 ) || ( V_60 >= ( 1 << V_63 ) ) ) {
V_16 = 1 << V_63 ;
V_60 = 0 ;
} else {
V_16 = V_60 + 1 ;
}
for ( V_15 = V_60 ; V_15 < V_16 ; V_15 ++ , V_34 ++ ) {
V_34 -> V_36 = F_10 ( V_6 ,
V_64 ) ;
V_34 -> V_60 = F_11 ( V_15 ) ;
V_34 -> V_61 = F_14 ( V_61 ) ;
}
return F_5 ( V_6 , V_34 ) ;
}
static int F_15 ( struct V_5 * V_6 ,
bool V_57 , T_4 V_65 , T_4 V_66 )
{
struct V_67 * V_34 = F_4 ( V_6 ) ;
V_34 -> V_36 = F_10 ( V_6 ,
( V_57 ) ? V_50 :
V_49 ) ;
V_34 -> V_65 = F_11 ( V_65 ) ;
V_34 -> V_66 = F_11 ( V_66 ) ;
return F_5 ( V_6 , ++ V_34 ) ;
}
static int F_16 ( struct V_5 * V_6 , T_1 V_68 )
{
struct V_69 * V_34 = F_4 ( V_6 ) ;
V_34 -> V_36 = F_10 ( V_6 ,
V_70 ) ;
V_34 -> V_71 = V_68 ;
return F_5 ( V_6 , ++ V_34 ) ;
}
static int F_17 ( struct V_5 * V_6 ,
T_1 V_72 )
{
struct V_73 * V_34 = F_4 ( V_6 ) ;
V_34 -> V_36 = F_10 ( V_6 ,
V_74 ) ;
V_34 -> V_71 = V_72 ;
return F_5 ( V_6 , ++ V_34 ) ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_75 * V_76 )
{
struct V_77 * V_34 = F_4 ( V_6 ) ;
V_34 -> V_36 = F_10 ( V_6 ,
V_78 ) ;
V_34 -> V_79 = F_19 ( V_76 -> V_80 - 1 ,
V_6 -> V_43 . V_48 & V_81 ) ;
V_34 -> V_82 = F_20 ( V_76 -> V_83 - 1 ) ;
V_34 -> V_84 = F_21 ( V_76 -> V_85 + V_76 -> V_86 - 1 ) ;
V_34 -> V_87 = F_11 ( F_22 ( V_76 -> V_87 - 1 ) ) ;
V_34 -> V_88 = 96 ;
return F_5 ( V_6 , ++ V_34 ) ;
}
static int F_23 ( struct V_5 * V_6 ,
struct V_75 * V_76 )
{
struct V_89 * V_34 = F_4 ( V_6 ) ;
V_34 -> V_36 = F_10 ( V_6 ,
V_90 ) ;
V_34 -> V_80 = F_24 ( V_76 -> V_80 - 1 ) ;
V_34 -> V_82 = F_25 ( V_76 -> V_83 - 1 ) ;
V_34 -> V_84 = F_26 ( V_76 -> V_85 + V_76 -> V_86 - 1 ) ;
V_34 -> V_87 = F_11 ( F_27 ( V_76 -> V_87 - 1 ) ) ;
return F_5 ( V_6 , ++ V_34 ) ;
}
static int F_28 ( struct V_5 * V_6 ,
struct V_91 * V_91 , T_1 * V_30 )
{
T_1 * V_35 = V_30 ;
V_35 += F_9 ( V_6 , V_35 ) ;
memset ( V_35 , 0xff , sizeof( struct V_33 ) ) ;
V_35 += sizeof( struct V_33 ) ;
F_29 ( V_91 , V_6 -> V_23 ,
F_7 ( V_6 -> V_23 , V_27 ) ,
V_30 , V_35 - V_30 ,
V_92 , V_6 ) ;
return F_30 ( V_91 , V_93 ) ;
}
static int F_31 ( struct V_5 * V_6 , bool V_94 )
{
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_6 ) ;
V_8 -> V_10 [ 0 ] = 0 ;
V_8 -> V_10 [ 1 ] = ! ! V_94 ;
return F_32 ( V_6 ,
V_95 ,
V_96 ,
V_8 -> V_10 ,
V_97 ) ;
}
static int F_33 ( struct V_4 * V_9 ,
struct V_98 * V_99 )
{
struct V_100 * V_101 = (struct V_100 * ) V_99 ;
struct V_5 * V_6 = V_9 -> V_6 [ F_34 ( V_101 ) ] ;
struct V_102 * V_29 = V_6 -> V_29 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
const T_4 V_107 = F_35 ( V_101 -> V_108 ) ;
if ( V_107 & V_109 ) {
V_106 = F_36 ( V_29 , & V_104 ) ;
if ( ! V_106 )
return - V_110 ;
if ( V_107 & V_111 )
V_104 -> V_108 |= V_112 ;
if ( V_107 & V_113 )
V_104 -> V_108 |= V_114 ;
V_104 -> V_115 = F_37 ( F_38 ( F_39 ( V_101 ) ) ) ;
} else {
V_106 = F_40 ( V_29 , (struct V_116 * * ) & V_104 ) ;
if ( ! V_106 )
return - V_110 ;
V_104 -> V_115 = F_41 ( F_39 ( V_101 ) ) ;
}
V_104 -> V_117 = F_42 ( V_101 -> V_117 ) ;
if ( V_107 & V_118 )
V_104 -> V_117 |= V_119 ;
if ( V_107 & V_120 )
V_104 -> V_117 |= V_121 ;
else
memcpy ( V_104 -> V_122 , V_101 -> V_123 , V_104 -> V_115 ) ;
F_43 ( V_106 , & V_9 -> V_124 ,
F_42 ( V_101 -> V_125 ) , F_42 ( V_101 -> V_126 ) ) ;
V_29 -> V_127 . V_128 ++ ;
V_29 -> V_127 . V_129 += V_104 -> V_115 ;
return 0 ;
}
static int F_44 ( struct V_4 * V_9 ,
struct V_98 * V_99 )
{
struct V_130 * V_131 = (struct V_130 * ) V_99 ;
struct V_5 * V_6 = V_9 -> V_6 [ F_45 ( V_131 ) ] ;
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_6 ) ;
enum V_132 V_133 = V_134 ;
enum V_132 V_135 , V_136 ;
struct V_102 * V_29 = V_6 -> V_29 ;
struct V_116 * V_137 ;
struct V_105 * V_106 ;
if ( V_6 -> V_43 . V_19 == V_138 )
return 0 ;
if ( V_131 -> V_139 & V_140 ) {
V_133 = V_138 ;
} else if ( V_131 -> V_139 & V_141 ) {
V_133 = V_142 ;
} else if ( V_131 -> V_139 & V_143 ) {
V_133 = V_144 ;
} else {
V_6 -> V_43 . V_19 = V_134 ;
V_8 -> V_145 . V_146 = 0 ;
V_8 -> V_145 . V_147 = 0 ;
return 0 ;
}
if ( V_133 == V_6 -> V_43 . V_19 )
return 0 ;
V_136 = ( V_8 -> V_145 . V_146 >= V_8 -> V_145 . V_147 ) ? V_133 : 0 ;
V_135 = ( V_8 -> V_145 . V_146 <= V_8 -> V_145 . V_147 ) ? V_133 : 0 ;
V_106 = F_46 ( V_29 , & V_137 ) ;
if ( V_106 )
F_47 ( V_29 , V_137 , V_136 , V_135 ) ;
if ( V_133 == V_138 )
F_48 ( V_29 ) ;
if ( ! V_106 )
return - V_110 ;
F_43 ( V_106 , & V_9 -> V_124 ,
F_42 ( V_131 -> V_125 ) , F_42 ( V_131 -> V_126 ) ) ;
V_29 -> V_127 . V_128 ++ ;
V_29 -> V_127 . V_129 += V_137 -> V_148 ;
return 0 ;
}
static int F_49 ( struct V_4 * V_9 ,
struct V_98 * V_99 )
{
struct V_149 * V_150 = (struct V_149 * ) V_99 ;
struct V_5 * V_6 = V_9 -> V_6 [ F_50 ( V_150 ) ] ;
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_6 ) ;
V_8 -> V_145 . V_146 = V_150 -> V_151 ;
V_8 -> V_145 . V_147 = V_150 -> V_152 ;
return 0 ;
}
static int F_51 ( struct V_4 * V_9 ,
struct V_98 * V_99 )
{
struct V_1 * V_153 = (struct V_1 * ) V_99 ;
struct V_5 * V_6 = V_9 -> V_6 [ F_1 ( V_153 ) ] ;
struct V_102 * V_29 = V_6 -> V_29 ;
struct V_116 * V_137 ;
struct V_105 * V_106 ;
V_106 = F_46 ( V_29 , & V_137 ) ;
if ( ! V_106 )
return - V_110 ;
V_137 -> V_117 |= V_154 ;
V_137 -> V_122 [ 1 ] |= V_155 ;
F_43 ( V_106 , & V_9 -> V_124 ,
F_42 ( V_153 -> V_125 ) , F_42 ( V_153 -> V_126 ) ) ;
V_29 -> V_127 . V_156 ++ ;
V_29 -> V_127 . V_157 ++ ;
return 0 ;
}
static void F_52 ( struct V_4 * V_9 ,
struct V_98 * V_99 )
{
struct V_158 * V_159 = (struct V_158 * ) V_99 ;
if ( V_9 -> V_160 > 0 )
V_9 -> V_160 -- ;
else
F_53 ( & V_9 -> V_124 , F_42 ( V_159 -> V_125 ) ) ;
}
static int F_54 ( struct V_5 * V_6 , struct V_91 * V_91 )
{
struct V_4 * V_9 = F_2 ( V_6 ) ;
struct V_102 * V_29 = V_6 -> V_29 ;
struct V_98 * V_99 ;
T_1 * V_161 , * V_162 ;
int V_13 = 0 ;
V_161 = V_91 -> V_163 ;
V_162 = V_91 -> V_163 + V_91 -> V_164 ;
for (; V_161 < V_162 ; ) {
T_4 V_165 , V_166 ;
V_99 = (struct V_98 * ) V_161 ;
if ( ! V_99 -> V_167 ) {
break;
}
V_166 = F_35 ( V_99 -> V_167 ) ;
V_165 = F_35 ( V_99 -> type ) ;
if ( V_161 + V_166 > V_162 ) {
F_8 ( V_29 ,
L_2 ) ;
V_13 = - V_168 ;
break;
}
switch ( V_165 ) {
case V_169 :
V_13 = F_33 ( V_9 , V_99 ) ;
if ( V_13 < 0 )
goto V_170;
break;
case V_171 :
F_52 ( V_9 , V_99 ) ;
break;
case V_172 :
V_13 = F_49 ( V_9 , V_99 ) ;
if ( V_13 < 0 )
goto V_170;
break;
case V_173 :
V_13 = F_44 ( V_9 , V_99 ) ;
if ( V_13 < 0 )
goto V_170;
break;
case V_174 :
V_13 = F_51 ( V_9 , V_99 ) ;
if ( V_13 < 0 )
goto V_170;
break;
default:
F_8 ( V_29 ,
L_3 ,
V_165 , V_165 ) ;
break;
}
V_161 += V_166 ;
}
V_170:
if ( V_13 )
F_55 ( L_4 ,
V_91 -> V_163 , V_91 -> V_164 ) ;
return V_13 ;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_105 * V_106 , T_1 * V_175 , T_5 * V_167 )
{
struct V_176 * V_177 = (struct V_176 * ) V_175 ;
struct V_103 * V_104 = (struct V_103 * ) V_106 -> V_122 ;
T_4 V_178 , V_179 ;
T_1 V_148 ;
V_178 = F_57 ( sizeof( struct V_176 ) + V_104 -> V_115 , 4 ) ;
V_177 -> V_167 = F_11 ( V_178 ) ;
V_177 -> type = F_11 ( V_180 ) ;
V_179 = 0 ;
if ( V_104 -> V_117 & V_119 ) {
V_179 |= V_118 ;
V_177 -> V_117 = F_14 ( V_104 -> V_117 & V_181 ) ;
} else {
V_177 -> V_117 = F_14 ( V_104 -> V_117 & V_182 ) ;
}
if ( F_58 ( V_106 ) ) {
V_148 = F_59 ( V_104 -> V_115 ) ;
V_179 |= V_109 ;
if ( V_104 -> V_108 & V_112 )
V_179 |= V_111 ;
if ( V_104 -> V_108 & V_114 )
V_179 |= V_113 ;
} else {
V_148 = V_104 -> V_115 ;
if ( V_104 -> V_117 & V_121 )
V_179 |= V_120 ;
}
V_177 -> V_108 = F_11 ( V_179 ) ;
V_177 -> V_183 = F_60 ( V_6 -> V_184 , V_148 ) ;
memcpy ( V_177 -> V_123 , V_104 -> V_122 , V_104 -> V_115 ) ;
V_177 = (struct V_176 * ) ( V_175 + V_178 ) ;
V_177 -> V_167 = 0 ;
* V_167 = V_178 + sizeof( T_3 ) ;
return 0 ;
}
static int F_61 ( struct V_5 * V_6 )
{
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_6 ) ;
int V_13 ;
V_13 = F_13 ( V_6 , - 1 , 0xffffffff ) ;
if ( V_13 )
return V_13 ;
if ( V_8 -> V_9 -> V_185 == 0 ) {
F_62 ( & V_8 -> V_9 -> V_124 ,
& V_186 ) ;
V_13 = F_15 ( V_6 , 1 ,
V_187 ,
V_188 ) ;
}
V_8 -> V_9 -> V_185 ++ ;
V_8 -> V_145 . V_146 = 0 ;
V_8 -> V_145 . V_147 = 0 ;
return V_13 ;
}
static int F_63 ( const struct V_102 * V_29 ,
struct V_189 * V_145 )
{
struct V_5 * V_6 = F_64 ( V_29 ) ;
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_6 ) ;
* V_145 = V_8 -> V_145 ;
return 0 ;
}
static int F_65 ( struct V_5 * V_6 )
{
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_6 ) ;
if ( V_8 -> V_9 -> V_185 == 1 )
F_15 ( V_6 , 0 ,
V_187 ,
V_188 ) ;
V_8 -> V_9 -> V_185 -- ;
return 0 ;
}
static int F_66 ( struct V_5 * V_6 )
{
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_6 ) ;
int V_15 , V_13 = - V_110 ;
if ( ! V_6 -> V_190 ) {
V_8 -> V_9 = F_67 ( sizeof( * V_8 -> V_9 ) , V_191 ) ;
if ( ! V_8 -> V_9 )
goto V_192;
V_8 -> V_10 = F_68 ( V_21 ,
V_191 ) ;
if ( ! V_8 -> V_10 )
goto V_193;
V_8 -> V_9 -> V_160 = 5 ;
V_13 = F_32 ( V_6 , V_194 ,
V_195 ,
& V_8 -> V_9 -> V_196 ,
sizeof( V_8 -> V_9 -> V_196 ) ) ;
if ( V_13 ) {
F_69 ( V_6 -> V_29 -> V_6 . V_197 ,
L_5 ,
V_6 -> V_198 -> V_199 , V_13 ) ;
goto V_200;
}
F_70 ( V_6 -> V_29 -> V_6 . V_197 ,
L_6 ,
V_6 -> V_198 -> V_199 , V_8 -> V_9 -> V_196 . V_201 ,
V_8 -> V_9 -> V_196 . V_202 [ 0 ] ,
V_8 -> V_9 -> V_196 . V_202 [ 1 ] ,
V_8 -> V_9 -> V_196 . V_202 [ 2 ] ,
V_6 -> V_198 -> V_203 ) ;
if ( V_8 -> V_9 -> V_196 . V_202 [ 0 ] >= 2 ) {
V_6 -> V_43 . V_44 |= V_45 ;
} else {
V_6 -> V_43 . V_48 |= V_45 ;
}
V_13 = F_31 ( V_6 , 1 ) ;
if ( V_13 ) {
F_69 ( V_6 -> V_29 -> V_6 . V_197 ,
L_7 ,
V_6 -> V_198 -> V_199 , V_13 ) ;
goto V_200;
}
} else {
struct V_7 * V_204 =
F_3 ( V_6 -> V_190 ,
struct V_7 , V_6 ) ;
V_8 -> V_9 = V_204 -> V_9 ;
V_8 -> V_10 = V_204 -> V_10 ;
V_6 -> V_43 . V_48 = V_204 -> V_6 . V_43 . V_48 ;
V_6 -> V_43 . V_44 = V_204 -> V_6 . V_43 . V_44 ;
}
V_8 -> V_9 -> V_6 [ V_6 -> V_184 ] = V_6 ;
V_6 -> V_205 =
F_42 ( V_8 -> V_9 -> V_196 . V_206 [ V_6 -> V_184 ] ) ;
for ( V_15 = 0 ; V_15 < F_71 ( V_207 ) ; V_15 ++ )
if ( V_6 -> V_198 -> clock . V_208 == V_207 [ V_15 ] )
break;
if ( V_15 >= F_71 ( V_207 ) ) {
F_72 ( V_6 -> V_29 -> V_6 . V_197 ,
L_8 ) ;
V_13 = - V_209 ;
goto V_200;
}
F_17 ( V_6 , V_15 ) ;
F_16 ( V_6 , V_210 ) ;
return 0 ;
V_200:
F_73 ( V_8 -> V_10 ) ;
V_193:
F_73 ( V_8 -> V_9 ) ;
V_192:
return V_13 ;
}
static void F_74 ( struct V_5 * V_6 )
{
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_6 ) ;
if ( V_6 -> V_43 . V_19 != V_211 ) {
F_12 ( V_6 , 0 ) ;
}
F_16 ( V_6 , V_212 ) ;
if ( V_6 -> V_184 == 0 ) {
if ( V_8 -> V_9 -> V_185 > 0 )
F_15 ( V_6 , 0 ,
V_187 ,
V_188 ) ;
F_31 ( V_6 , 0 ) ;
}
}
static void F_75 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_190 && ! V_6 -> V_213 ) {
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_6 ) ;
F_73 ( V_8 -> V_10 ) ;
F_73 ( V_8 -> V_9 ) ;
}
}

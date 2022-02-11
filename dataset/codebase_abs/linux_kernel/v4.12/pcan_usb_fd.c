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
V_32 -> V_36 = F_10 ( V_6 -> V_37 ,
V_38 ) ;
V_32 -> V_39 = F_11 ( V_40 | V_41 ) ;
V_32 -> V_42 = 0 ;
V_32 -> V_43 = 0 ;
V_35 += sizeof( struct V_31 ) ;
if ( V_6 -> V_44 . V_45 & V_46 ) {
struct V_47 * V_48 = (struct V_47 * ) V_35 ;
V_48 -> V_36 =
( V_6 -> V_44 . V_49 & V_46 ) ?
F_10 ( V_6 -> V_37 ,
V_50 ) :
F_10 ( V_6 -> V_37 ,
V_51 ) ;
V_48 -> V_52 = F_11 ( V_53 ) ;
V_48 -> V_54 = 0 ;
V_35 += sizeof( struct V_47 ) ;
}
V_34 = (struct V_33 * ) V_35 ;
V_34 -> V_36 = F_10 ( V_6 -> V_37 ,
( V_6 -> V_44 . V_49 & V_55 ) ?
V_56 :
V_57 ) ;
V_35 += sizeof( struct V_33 ) ;
return V_35 - V_30 ;
}
static int F_12 ( struct V_5 * V_6 , T_1 V_58 )
{
T_1 * V_35 = F_4 ( V_6 ) ;
int V_59 ;
if ( V_58 ) {
V_59 = F_9 ( V_6 , V_35 ) ;
} else {
struct V_33 * V_34 = (struct V_33 * ) V_35 ;
V_34 -> V_36 = F_10 ( V_6 -> V_37 ,
V_60 ) ;
V_59 = sizeof( struct V_33 ) ;
}
return F_5 ( V_6 , V_35 + V_59 ) ;
}
static int F_13 ( struct V_5 * V_6 , int V_61 ,
T_3 V_62 )
{
struct V_63 * V_34 = F_4 ( V_6 ) ;
int V_15 , V_16 ;
if ( ( V_61 < 0 ) || ( V_61 >= ( 1 << V_64 ) ) ) {
V_16 = 1 << V_64 ;
V_61 = 0 ;
} else {
V_16 = V_61 + 1 ;
}
for ( V_15 = V_61 ; V_15 < V_16 ; V_15 ++ , V_34 ++ ) {
V_34 -> V_36 = F_10 ( V_6 -> V_37 ,
V_65 ) ;
V_34 -> V_61 = F_11 ( V_15 ) ;
V_34 -> V_62 = F_14 ( V_62 ) ;
}
return F_5 ( V_6 , V_34 ) ;
}
static int F_15 ( struct V_5 * V_6 ,
bool V_58 , T_4 V_66 , T_4 V_67 )
{
struct V_68 * V_34 = F_4 ( V_6 ) ;
V_34 -> V_36 = F_10 ( V_6 -> V_37 ,
( V_58 ) ? V_51 :
V_50 ) ;
V_34 -> V_66 = F_11 ( V_66 ) ;
V_34 -> V_67 = F_11 ( V_67 ) ;
return F_5 ( V_6 , ++ V_34 ) ;
}
static int F_16 ( struct V_5 * V_6 , T_1 V_69 )
{
struct V_70 * V_34 = F_4 ( V_6 ) ;
V_34 -> V_36 = F_10 ( V_6 -> V_37 ,
V_71 ) ;
V_34 -> V_72 = V_69 ;
return F_5 ( V_6 , ++ V_34 ) ;
}
static int F_17 ( struct V_5 * V_6 ,
T_1 V_73 )
{
struct V_74 * V_34 = F_4 ( V_6 ) ;
V_34 -> V_36 = F_10 ( V_6 -> V_37 ,
V_75 ) ;
V_34 -> V_72 = V_73 ;
return F_5 ( V_6 , ++ V_34 ) ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_76 * V_77 )
{
struct V_78 * V_34 = F_4 ( V_6 ) ;
V_34 -> V_36 = F_10 ( V_6 -> V_37 ,
V_79 ) ;
V_34 -> V_80 = F_19 ( V_77 -> V_81 - 1 ,
V_6 -> V_44 . V_49 & V_82 ) ;
V_34 -> V_83 = F_20 ( V_77 -> V_84 - 1 ) ;
V_34 -> V_85 = F_21 ( V_77 -> V_86 + V_77 -> V_87 - 1 ) ;
V_34 -> V_88 = F_11 ( F_22 ( V_77 -> V_88 - 1 ) ) ;
V_34 -> V_89 = 96 ;
return F_5 ( V_6 , ++ V_34 ) ;
}
static int F_23 ( struct V_5 * V_6 ,
struct V_76 * V_77 )
{
struct V_90 * V_34 = F_4 ( V_6 ) ;
V_34 -> V_36 = F_10 ( V_6 -> V_37 ,
V_91 ) ;
V_34 -> V_81 = F_24 ( V_77 -> V_81 - 1 ) ;
V_34 -> V_83 = F_25 ( V_77 -> V_84 - 1 ) ;
V_34 -> V_85 = F_26 ( V_77 -> V_86 + V_77 -> V_87 - 1 ) ;
V_34 -> V_88 = F_11 ( F_27 ( V_77 -> V_88 - 1 ) ) ;
return F_5 ( V_6 , ++ V_34 ) ;
}
static int F_28 ( struct V_5 * V_6 ,
struct V_92 * V_92 , T_1 * V_30 )
{
T_1 * V_35 = V_30 ;
V_35 += F_9 ( V_6 , V_35 ) ;
memset ( V_35 , 0xff , sizeof( struct V_33 ) ) ;
V_35 += sizeof( struct V_33 ) ;
F_29 ( V_92 , V_6 -> V_23 ,
F_7 ( V_6 -> V_23 , V_27 ) ,
V_30 , V_35 - V_30 ,
V_93 , V_6 ) ;
return F_30 ( V_92 , V_94 ) ;
}
static int F_31 ( struct V_5 * V_6 , bool V_95 )
{
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_6 ) ;
V_8 -> V_10 [ 0 ] = 0 ;
V_8 -> V_10 [ 1 ] = ! ! V_95 ;
return F_32 ( V_6 ,
V_96 ,
V_97 ,
V_8 -> V_10 ,
V_98 ) ;
}
static int F_33 ( struct V_4 * V_9 ,
struct V_99 * V_100 )
{
struct V_101 * V_102 = (struct V_101 * ) V_100 ;
struct V_5 * V_6 = V_9 -> V_6 [ F_34 ( V_102 ) ] ;
struct V_103 * V_29 = V_6 -> V_29 ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
const T_4 V_108 = F_35 ( V_102 -> V_109 ) ;
if ( V_108 & V_110 ) {
V_107 = F_36 ( V_29 , & V_105 ) ;
if ( ! V_107 )
return - V_111 ;
if ( V_108 & V_112 )
V_105 -> V_109 |= V_113 ;
if ( V_108 & V_114 )
V_105 -> V_109 |= V_115 ;
V_105 -> V_116 = F_37 ( F_38 ( F_39 ( V_102 ) ) ) ;
} else {
V_107 = F_40 ( V_29 , (struct V_117 * * ) & V_105 ) ;
if ( ! V_107 )
return - V_111 ;
V_105 -> V_116 = F_41 ( F_39 ( V_102 ) ) ;
}
V_105 -> V_118 = F_42 ( V_102 -> V_118 ) ;
if ( V_108 & V_119 )
V_105 -> V_118 |= V_120 ;
if ( V_108 & V_121 )
V_105 -> V_118 |= V_122 ;
else
memcpy ( V_105 -> V_123 , V_102 -> V_124 , V_105 -> V_116 ) ;
F_43 ( V_107 , & V_9 -> V_125 ,
F_42 ( V_102 -> V_126 ) , F_42 ( V_102 -> V_127 ) ) ;
V_29 -> V_128 . V_129 ++ ;
V_29 -> V_128 . V_130 += V_105 -> V_116 ;
return 0 ;
}
static int F_44 ( struct V_4 * V_9 ,
struct V_99 * V_100 )
{
struct V_131 * V_132 = (struct V_131 * ) V_100 ;
struct V_5 * V_6 = V_9 -> V_6 [ F_45 ( V_132 ) ] ;
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_6 ) ;
enum V_133 V_134 = V_135 ;
enum V_133 V_136 , V_137 ;
struct V_103 * V_29 = V_6 -> V_29 ;
struct V_117 * V_138 ;
struct V_106 * V_107 ;
if ( V_6 -> V_44 . V_19 == V_139 )
return 0 ;
if ( V_132 -> V_140 & V_141 ) {
V_134 = V_139 ;
} else if ( V_132 -> V_140 & V_142 ) {
V_134 = V_143 ;
} else if ( V_132 -> V_140 & V_144 ) {
V_134 = V_145 ;
} else {
V_6 -> V_44 . V_19 = V_135 ;
V_8 -> V_146 . V_147 = 0 ;
V_8 -> V_146 . V_148 = 0 ;
return 0 ;
}
if ( V_134 == V_6 -> V_44 . V_19 )
return 0 ;
V_137 = ( V_8 -> V_146 . V_147 >= V_8 -> V_146 . V_148 ) ? V_134 : 0 ;
V_136 = ( V_8 -> V_146 . V_147 <= V_8 -> V_146 . V_148 ) ? V_134 : 0 ;
V_107 = F_46 ( V_29 , & V_138 ) ;
if ( V_107 )
F_47 ( V_29 , V_138 , V_137 , V_136 ) ;
if ( V_134 == V_139 )
F_48 ( V_29 ) ;
if ( ! V_107 )
return - V_111 ;
F_43 ( V_107 , & V_9 -> V_125 ,
F_42 ( V_132 -> V_126 ) , F_42 ( V_132 -> V_127 ) ) ;
V_29 -> V_128 . V_129 ++ ;
V_29 -> V_128 . V_130 += V_138 -> V_149 ;
return 0 ;
}
static int F_49 ( struct V_4 * V_9 ,
struct V_99 * V_100 )
{
struct V_150 * V_151 = (struct V_150 * ) V_100 ;
struct V_5 * V_6 = V_9 -> V_6 [ F_50 ( V_151 ) ] ;
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_6 ) ;
V_8 -> V_146 . V_147 = V_151 -> V_152 ;
V_8 -> V_146 . V_148 = V_151 -> V_153 ;
return 0 ;
}
static int F_51 ( struct V_4 * V_9 ,
struct V_99 * V_100 )
{
struct V_1 * V_154 = (struct V_1 * ) V_100 ;
struct V_5 * V_6 = V_9 -> V_6 [ F_1 ( V_154 ) ] ;
struct V_103 * V_29 = V_6 -> V_29 ;
struct V_117 * V_138 ;
struct V_106 * V_107 ;
V_107 = F_46 ( V_29 , & V_138 ) ;
if ( ! V_107 )
return - V_111 ;
V_138 -> V_118 |= V_155 ;
V_138 -> V_123 [ 1 ] |= V_156 ;
F_43 ( V_107 , & V_9 -> V_125 ,
F_42 ( V_154 -> V_126 ) , F_42 ( V_154 -> V_127 ) ) ;
V_29 -> V_128 . V_157 ++ ;
V_29 -> V_128 . V_158 ++ ;
return 0 ;
}
static void F_52 ( struct V_4 * V_9 ,
struct V_99 * V_100 )
{
struct V_159 * V_160 = (struct V_159 * ) V_100 ;
if ( V_9 -> V_161 > 0 )
V_9 -> V_161 -- ;
else
F_53 ( & V_9 -> V_125 , F_42 ( V_160 -> V_126 ) ) ;
}
static int F_54 ( struct V_5 * V_6 , struct V_92 * V_92 )
{
struct V_4 * V_9 = F_2 ( V_6 ) ;
struct V_103 * V_29 = V_6 -> V_29 ;
struct V_99 * V_100 ;
T_1 * V_162 , * V_163 ;
int V_13 = 0 ;
V_162 = V_92 -> V_164 ;
V_163 = V_92 -> V_164 + V_92 -> V_165 ;
for (; V_162 < V_163 ; ) {
T_4 V_166 , V_167 ;
V_100 = (struct V_99 * ) V_162 ;
if ( ! V_100 -> V_168 ) {
break;
}
V_167 = F_35 ( V_100 -> V_168 ) ;
V_166 = F_35 ( V_100 -> type ) ;
if ( V_162 + V_167 > V_163 ) {
F_8 ( V_29 ,
L_2 ) ;
V_13 = - V_169 ;
break;
}
switch ( V_166 ) {
case V_170 :
V_13 = F_33 ( V_9 , V_100 ) ;
if ( V_13 < 0 )
goto V_171;
break;
case V_172 :
F_52 ( V_9 , V_100 ) ;
break;
case V_173 :
V_13 = F_49 ( V_9 , V_100 ) ;
if ( V_13 < 0 )
goto V_171;
break;
case V_174 :
V_13 = F_44 ( V_9 , V_100 ) ;
if ( V_13 < 0 )
goto V_171;
break;
case V_175 :
V_13 = F_51 ( V_9 , V_100 ) ;
if ( V_13 < 0 )
goto V_171;
break;
default:
F_8 ( V_29 ,
L_3 ,
V_166 , V_166 ) ;
break;
}
V_162 += V_167 ;
}
V_171:
if ( V_13 )
F_55 ( L_4 ,
V_92 -> V_164 , V_92 -> V_165 ) ;
return V_13 ;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_106 * V_107 , T_1 * V_176 , T_5 * V_168 )
{
struct V_177 * V_178 = (struct V_177 * ) V_176 ;
struct V_104 * V_105 = (struct V_104 * ) V_107 -> V_123 ;
T_4 V_179 , V_180 ;
T_1 V_149 ;
V_179 = F_57 ( sizeof( struct V_177 ) + V_105 -> V_116 , 4 ) ;
V_178 -> V_168 = F_11 ( V_179 ) ;
V_178 -> type = F_11 ( V_181 ) ;
V_180 = 0 ;
if ( V_105 -> V_118 & V_120 ) {
V_180 |= V_119 ;
V_178 -> V_118 = F_14 ( V_105 -> V_118 & V_182 ) ;
} else {
V_178 -> V_118 = F_14 ( V_105 -> V_118 & V_183 ) ;
}
if ( F_58 ( V_107 ) ) {
V_149 = F_59 ( V_105 -> V_116 ) ;
V_180 |= V_110 ;
if ( V_105 -> V_109 & V_113 )
V_180 |= V_112 ;
if ( V_105 -> V_109 & V_115 )
V_180 |= V_114 ;
} else {
V_149 = V_105 -> V_116 ;
if ( V_105 -> V_118 & V_122 )
V_180 |= V_121 ;
}
V_178 -> V_109 = F_11 ( V_180 ) ;
V_178 -> V_184 = F_60 ( V_6 -> V_37 , V_149 ) ;
memcpy ( V_178 -> V_124 , V_105 -> V_123 , V_105 -> V_116 ) ;
V_178 = (struct V_177 * ) ( V_176 + V_179 ) ;
V_178 -> V_168 = 0 ;
* V_168 = V_179 + sizeof( T_3 ) ;
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
F_62 ( & V_8 -> V_9 -> V_125 ,
& V_186 ) ;
V_13 = F_15 ( V_6 , 1 ,
V_187 ,
V_188 ) ;
}
V_8 -> V_9 -> V_185 ++ ;
V_8 -> V_146 . V_147 = 0 ;
V_8 -> V_146 . V_148 = 0 ;
return V_13 ;
}
static int F_63 ( const struct V_103 * V_29 ,
struct V_189 * V_146 )
{
struct V_5 * V_6 = F_64 ( V_29 ) ;
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_6 ) ;
* V_146 = V_8 -> V_146 ;
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
int V_15 , V_13 = - V_111 ;
if ( ! V_6 -> V_190 ) {
V_8 -> V_9 = F_67 ( sizeof( * V_8 -> V_9 ) , V_191 ) ;
if ( ! V_8 -> V_9 )
goto V_192;
V_8 -> V_10 = F_68 ( V_21 ,
V_191 ) ;
if ( ! V_8 -> V_10 )
goto V_193;
V_8 -> V_9 -> V_161 = 5 ;
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
V_6 -> V_44 . V_45 |= V_46 ;
} else {
V_6 -> V_44 . V_49 |= V_46 ;
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
V_6 -> V_44 . V_49 = V_204 -> V_6 . V_44 . V_49 ;
V_6 -> V_44 . V_45 = V_204 -> V_6 . V_44 . V_45 ;
}
V_8 -> V_9 -> V_6 [ V_6 -> V_37 ] = V_6 ;
V_6 -> V_205 =
F_42 ( V_8 -> V_9 -> V_196 . V_206 [ V_6 -> V_37 ] ) ;
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
if ( V_6 -> V_44 . V_19 != V_211 ) {
F_12 ( V_6 , 0 ) ;
}
F_16 ( V_6 , V_212 ) ;
if ( V_6 -> V_37 == 0 ) {
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

static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_5 , int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ ) {
int V_8 = ( V_4 -> V_9 . V_10 > V_2 -> V_11 ) ?
V_2 -> V_11 : V_4 -> V_9 . V_10 ;
V_2 -> V_12 . V_13 = F_2 ( V_2 , V_4 ,
V_4 -> V_14 . V_13 ) ;
if ( V_4 -> V_14 . V_15 & V_16 ) {
V_4 -> V_9 . V_10 -= V_8 ;
V_4 -> V_9 . V_17 += V_8 ;
} else {
F_3 ( & V_4 -> V_9 , V_8 ) ;
}
if ( V_5 & V_18 )
V_4 -> V_19 += V_2 -> V_11 ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_20 ;
unsigned int V_5 ;
int V_6 ;
int V_21 = 1 ;
V_4 = F_5 ( V_2 -> V_22 . V_23 ) ;
V_6 = ( V_2 -> V_24 . V_25 - V_4 -> V_26 ) & V_27 ;
V_2 -> V_12 . V_20 = F_6 ( V_2 -> V_22 . V_23 ) ;
V_2 -> V_12 . V_25 = V_2 -> V_24 . V_25 ;
V_2 -> V_12 . V_13 = - 1 ;
for ( V_20 = F_6 ( V_2 -> V_22 . V_23 ) ;
V_20 != F_7 ( V_2 -> V_22 . V_23 ) ;
V_20 = F_8 ( V_2 -> V_22 . V_23 , V_20 ) ) {
V_4 = F_9 ( V_2 -> V_22 . V_23 , V_20 ) ;
V_5 = F_10 ( V_4 -> V_14 . V_13 , V_2 ) ;
if ( V_4 -> V_28 == V_29 )
break;
if ( V_4 -> V_28 == V_30 )
continue;
V_4 -> V_19 = ( V_5 & V_31 ) ?
V_4 -> V_14 . V_14 . V_32 . V_33 :
( V_5 & V_34 ) ?
V_4 -> V_14 . V_14 . V_35 . V_33 :
0 ;
if ( ! V_21 || ( V_5 & V_36 ) == 0 ) {
V_4 -> V_9 . V_10 = V_4 -> V_9 . V_37 ;
V_4 -> V_9 . V_38 = 0 ;
V_4 -> V_9 . V_17 = 0 ;
}
if ( V_21 ) {
V_21 = 0 ;
if ( V_5 & V_39 )
F_1 ( V_2 , V_4 , V_5 , V_6 ) ;
if ( V_5 & V_36 )
V_4 -> V_19 += V_6 * V_2 -> V_11 ;
}
V_4 -> V_28 = V_29 ;
}
}
void F_11 ( unsigned long V_40 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 ;
F_12 ( L_1 , F_13 ( V_2 ) ) ;
F_14 ( & V_2 -> V_12 . V_41 , 1 ) ;
}
static struct V_3 * F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 -> V_22 . V_23 ) ;
unsigned long V_42 ;
if ( F_16 ( V_2 -> V_12 . V_28 == V_43 ) ) {
F_17 ( & V_2 -> V_44 , V_42 ) ;
do {
if ( V_2 -> V_12 . V_28 != V_43 ) {
F_18 ( & V_2 -> V_44 ,
V_42 ) ;
break;
}
if ( V_4 && ( ( V_2 -> V_12 . V_20 !=
F_6 ( V_2 -> V_22 . V_23 ) ) ||
( V_4 -> V_28 != V_29 ) ) ) {
F_18 ( & V_2 -> V_44 ,
V_42 ) ;
break;
}
V_2 -> V_12 . V_28 = V_45 ;
F_18 ( & V_2 -> V_44 , V_42 ) ;
if ( V_2 -> V_46 . V_47 ) {
struct V_48 V_49 ;
V_49 . V_50 = V_2 -> V_46 . V_50 ;
V_49 . V_51 . V_2 = & V_2 -> V_46 ;
V_49 . V_52 = V_53 ;
V_2 -> V_46 . V_47 ( & V_49 ,
V_2 -> V_46 . V_54 ) ;
}
} while ( 0 );
}
if ( V_2 -> V_12 . V_20 == F_7 ( V_2 -> V_22 . V_23 ) )
return NULL ;
V_4 = F_9 ( V_2 -> V_22 . V_23 , V_2 -> V_12 . V_20 ) ;
if ( F_16 ( ( V_2 -> V_12 . V_28 == V_43 ||
V_2 -> V_12 . V_28 == V_45 ) &&
( V_4 -> V_28 != V_55 ) ) )
return NULL ;
if ( F_16 ( ( V_4 -> V_14 . V_15 & V_56 ) &&
( V_2 -> V_12 . V_20 != F_6 ( V_2 -> V_22 . V_23 ) ) ) ) {
V_2 -> V_12 . V_57 = 1 ;
return NULL ;
}
V_4 -> V_5 = F_10 ( V_4 -> V_14 . V_13 , V_2 ) ;
return V_4 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_13 , int V_58 )
{
switch ( V_13 ) {
case V_59 :
if ( V_2 -> V_12 . V_13 == V_60 ||
V_2 -> V_12 . V_13 == V_61 )
return V_58 ?
V_62 :
V_61 ;
else
return V_58 ?
V_63 :
V_60 ;
case V_64 :
if ( V_2 -> V_12 . V_13 == V_60 ||
V_2 -> V_12 . V_13 == V_61 )
return V_58 ?
V_65 :
V_61 ;
else
return V_58 ?
V_66 :
V_60 ;
case V_67 :
if ( V_2 -> V_12 . V_13 == V_68 ||
V_2 -> V_12 . V_13 == V_69 )
return V_58 ?
V_70 :
V_69 ;
else
return V_58 ?
V_71 :
V_68 ;
case V_72 :
if ( V_2 -> V_12 . V_13 == V_68 ||
V_2 -> V_12 . V_13 == V_69 )
return V_58 ?
V_73 :
V_69 ;
else
return V_58 ?
V_74 :
V_68 ;
case V_75 :
return V_76 ;
case V_77 :
return V_78 ;
case V_79 :
return V_80 ;
case V_81 :
if ( V_2 -> V_12 . V_13 == V_68 ||
V_2 -> V_12 . V_13 == V_69 )
return V_58 ? V_82 :
V_69 ;
else
return V_58 ? V_83 :
V_68 ;
case V_84 :
case V_85 :
return V_13 ;
}
return - V_86 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_13 , int V_58 )
{
switch ( V_13 ) {
case V_59 :
if ( V_2 -> V_12 . V_13 == V_87 ||
V_2 -> V_12 . V_13 == V_88 )
return V_58 ?
V_89 :
V_88 ;
else
return V_58 ?
V_90 :
V_87 ;
case V_64 :
if ( V_2 -> V_12 . V_13 == V_87 ||
V_2 -> V_12 . V_13 == V_88 )
return V_58 ?
V_91 :
V_88 ;
else
return V_58 ?
V_92 :
V_87 ;
case V_67 :
if ( V_2 -> V_12 . V_13 == V_93 ||
V_2 -> V_12 . V_13 == V_94 )
return V_58 ?
V_95 :
V_94 ;
else
return V_58 ?
V_96 :
V_93 ;
case V_72 :
if ( V_2 -> V_12 . V_13 == V_93 ||
V_2 -> V_12 . V_13 == V_94 )
return V_58 ?
V_97 :
V_94 ;
else
return V_58 ?
V_98 :
V_93 ;
}
return - V_86 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_13 )
{
int V_58 = ( V_4 -> V_9 . V_10 <= V_2 -> V_11 ) ;
switch ( F_21 ( V_2 ) ) {
case V_99 :
return F_19 ( V_2 , V_13 , V_58 ) ;
case V_100 :
return F_20 ( V_2 , V_13 , V_58 ) ;
case V_101 :
case V_102 :
case V_103 :
switch ( V_13 ) {
case V_67 :
return V_104 ;
case V_72 :
return V_105 ;
}
break;
default:
break;
}
return - V_86 ;
}
static inline int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_106 ;
if ( V_4 -> V_107 )
return 0 ;
V_2 -> V_12 . V_108 = 1 ;
V_106 = F_23 ( & V_2 -> V_12 . V_109 ) ;
if ( V_106 >= 0 ) {
V_2 -> V_12 . V_108 = 0 ;
V_4 -> V_107 = 1 ;
return 0 ;
}
F_24 ( & V_2 -> V_12 . V_109 ) ;
return - V_110 ;
}
static inline int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_111 * V_112 = F_26 ( V_2 -> V_46 . V_50 ) ;
struct V_113 * V_114 ;
struct V_115 * V_116 ;
if ( ( F_21 ( V_2 ) == V_99 ) || ( F_21 ( V_2 ) == V_100 ) )
return V_2 -> V_11 ;
V_116 = & V_4 -> V_116 ;
V_114 = & V_112 -> V_114 ;
return V_114 -> V_117 ;
}
static struct V_118 * F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_13 , int V_119 ,
struct V_120 * V_121 )
{
struct V_111 * V_112 = F_26 ( V_2 -> V_46 . V_50 ) ;
struct V_113 * V_114 = & V_112 -> V_114 ;
struct V_118 * V_122 ;
struct V_123 * V_124 = & V_4 -> V_14 ;
struct V_115 * V_116 ;
int V_125 = ( - V_119 ) & 0x3 ;
int V_126 ;
int V_127 ;
T_2 V_128 ;
T_1 F_13 ;
int V_129 ;
V_126 = V_130 [ V_13 ] . V_37 + V_119 + V_125 + V_131 ;
V_121 -> V_13 = V_13 ;
V_121 -> V_2 = V_2 ;
V_121 -> V_25 = V_2 -> V_12 . V_25 ;
V_121 -> V_5 = V_130 [ V_13 ] . V_5 ;
V_121 -> V_126 = V_126 ;
V_121 -> V_132 = 0 ;
V_121 -> V_4 = V_4 ;
V_116 = F_28 ( V_121 ) ;
V_122 = V_112 -> V_133 -> V_134 ( V_112 , V_116 , V_126 , V_121 ) ;
if ( F_16 ( ! V_122 ) )
return NULL ;
V_127 = ( V_124 -> V_15 & V_135 ) &&
( V_121 -> V_5 & V_136 ) &&
( ( V_121 -> V_5 & ( V_137 ) ) ||
( V_121 -> V_5 & ( V_138 | V_139 ) ) ==
( V_138 | V_139 ) ) ;
V_128 = ( F_21 ( V_2 ) == V_103 ) ?
V_114 -> V_140 [ V_124 -> V_14 . V_141 . V_142 ] :
V_114 -> V_140 [ V_2 -> V_143 . V_142 ] ;
F_13 = ( V_121 -> V_5 & V_144 ) ? V_124 -> V_14 . V_141 . V_145 :
V_2 -> V_143 . V_146 ;
V_129 = ( ( V_121 -> V_5 & V_136 ) ||
( V_2 -> V_12 . V_147 ++ > V_148 ) ) ;
if ( V_129 )
V_2 -> V_12 . V_147 = 0 ;
F_29 ( V_121 , V_121 -> V_13 , V_127 , 0 , V_125 , V_128 , F_13 ,
V_129 , V_121 -> V_25 ) ;
if ( V_121 -> V_5 & V_149 ) {
F_30 ( V_121 , V_124 -> V_14 . V_35 . V_150 ) ;
F_31 ( V_121 , V_4 -> V_19 ) ;
F_32 ( V_121 , V_4 -> V_9 . V_37 ) ;
}
if ( V_121 -> V_5 & V_139 )
F_33 ( V_121 , V_124 -> V_151 . V_152 ) ;
if ( V_121 -> V_5 & V_153 )
F_34 ( V_121 , V_124 -> V_151 . V_154 ) ;
if ( V_121 -> V_5 & V_155 ) {
F_35 ( V_121 , V_4 -> V_19 ) ;
if ( V_13 == V_78 ||
V_13 == V_156 ) {
F_36 ( V_121 , V_124 -> V_14 . V_32 . V_157 ) ;
F_37 ( V_121 , V_124 -> V_14 . V_32 . V_158 ) ;
} else {
F_36 ( V_121 , V_124 -> V_14 . V_32 . V_158 ) ;
}
F_38 ( V_121 , V_124 -> V_14 . V_32 . V_150 ) ;
}
if ( V_121 -> V_5 & V_144 ) {
if ( V_2 -> V_46 . F_13 == 1 )
F_39 ( V_121 , V_159 ) ;
else
F_39 ( V_121 , V_124 -> V_14 . V_141 . V_160 ) ;
F_40 ( V_121 , V_2 -> V_46 . F_13 ) ;
}
return V_122 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_120 * V_121 , struct V_118 * V_122 ,
int V_126 )
{
struct V_111 * V_112 = F_26 ( V_2 -> V_46 . V_50 ) ;
T_1 V_161 = 0 ;
T_1 * V_162 ;
int V_163 ;
V_163 = V_112 -> V_133 -> V_164 ( V_112 , V_121 , V_122 , & V_161 ) ;
if ( V_163 )
return V_163 ;
if ( V_121 -> V_5 & V_165 ) {
if ( V_4 -> V_14 . V_15 & V_16 ) {
T_3 * V_166 = & V_4 -> V_9 . V_167 [ V_4 -> V_9 . V_17 ] ;
V_161 = F_42 ( V_161 , V_166 , V_126 ) ;
memcpy ( F_43 ( V_121 ) , V_166 , V_126 ) ;
V_4 -> V_9 . V_10 -= V_126 ;
V_4 -> V_9 . V_17 += V_126 ;
} else {
V_163 = F_44 ( V_112 , V_2 -> V_168 , 0 , & V_4 -> V_9 ,
F_43 ( V_121 ) , V_126 ,
V_169 ,
& V_161 ) ;
if ( V_163 )
return V_163 ;
}
}
V_162 = F_43 ( V_121 ) + V_126 + F_45 ( V_121 ) ;
* V_162 = ~ V_161 ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_121 )
{
if ( V_121 -> V_5 & V_136 ) {
if ( F_21 ( V_2 ) == V_99 )
V_4 -> V_28 = V_170 ;
} else {
V_4 -> V_28 = V_55 ;
}
}
static void F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_121 ,
int V_119 )
{
int V_171 = ( V_4 -> V_9 . V_10 + V_119 + V_2 -> V_11 - 1 ) / V_2 -> V_11 ;
if ( V_171 == 0 )
V_171 = 1 ;
if ( V_121 -> V_5 & V_172 ) {
V_4 -> V_26 = V_2 -> V_12 . V_25 ;
V_4 -> V_173 = ( V_2 -> V_12 . V_25 + V_171 - 1 ) & V_27 ;
}
if ( V_121 -> V_5 & V_174 )
V_2 -> V_12 . V_25 = ( V_4 -> V_26 + V_171 ) & V_27 ;
else
V_2 -> V_12 . V_25 = ( V_2 -> V_12 . V_25 + 1 ) & V_27 ;
}
static void F_48 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_3 * V_175 ,
T_1 * V_176 )
{
V_175 -> V_28 = V_4 -> V_28 ;
V_175 -> V_26 = V_4 -> V_26 ;
V_175 -> V_173 = V_4 -> V_173 ;
* V_176 = V_2 -> V_12 . V_25 ;
}
static void F_49 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_3 * V_175 ,
T_1 V_176 )
{
V_4 -> V_28 = V_175 -> V_28 ;
V_4 -> V_26 = V_175 -> V_26 ;
V_4 -> V_173 = V_175 -> V_173 ;
V_2 -> V_12 . V_25 = V_176 ;
}
static void F_50 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_120 * V_121 , int V_119 )
{
V_2 -> V_12 . V_13 = V_121 -> V_13 ;
if ( V_121 -> V_5 & V_136 )
V_2 -> V_12 . V_20 = F_8 ( V_2 -> V_22 . V_23 , V_2 -> V_12 . V_20 ) ;
V_2 -> V_177 = 0 ;
if ( V_2 -> V_178 && ! F_51 ( & V_2 -> V_179 ) )
F_52 ( & V_2 -> V_179 ,
V_180 + V_2 -> V_178 ) ;
}
int F_53 ( void * V_181 )
{
struct V_1 * V_2 = (struct V_1 * ) V_181 ;
struct V_120 V_121 ;
struct V_118 * V_122 ;
struct V_3 * V_4 ;
enum V_182 V_5 ;
int V_119 ;
int V_11 ;
int V_13 ;
int V_183 ;
struct V_3 V_175 ;
T_1 V_176 ;
F_54 ( V_2 ) ;
V_184:
if ( F_16 ( ! V_2 -> V_185 || V_2 -> V_12 . V_28 == V_186 ) )
goto exit;
if ( F_16 ( V_2 -> V_12 . V_28 == V_187 ) ) {
V_2 -> V_12 . V_20 = F_6 ( V_2 -> V_22 . V_23 ) ;
V_2 -> V_12 . V_13 = - 1 ;
V_2 -> V_12 . V_108 = 0 ;
V_2 -> V_12 . V_188 = 0 ;
V_2 -> V_12 . V_189 = 0 ;
goto exit;
}
if ( F_16 ( V_2 -> V_12 . V_189 ) ) {
F_4 ( V_2 ) ;
V_2 -> V_12 . V_189 = 0 ;
}
V_4 = F_15 ( V_2 ) ;
if ( F_16 ( ! V_4 ) )
goto exit;
if ( V_4 -> V_5 & V_190 ) {
if ( V_4 -> V_14 . V_13 == V_85 ) {
struct V_111 * V_112 = F_26 ( V_2 -> V_46 . V_50 ) ;
struct V_191 * V_192 ;
V_192 = F_55 ( & V_112 -> V_193 ,
V_4 -> V_14 . V_151 . V_154 >> 8 ) ;
if ( ! V_192 ) {
F_56 ( L_2 ,
V_4 -> V_14 . V_151 . V_154 ) ;
V_4 -> V_28 = V_194 ;
V_4 -> V_195 = V_196 ;
goto exit;
}
V_192 -> V_28 = V_197 ;
V_4 -> V_28 = V_30 ;
V_4 -> V_195 = V_198 ;
} else if ( V_4 -> V_14 . V_13 == V_84 ) {
struct V_191 * V_192 = F_57 ( V_4 -> V_14 . V_14 . V_199 . V_200 ) ;
V_192 -> V_28 = V_201 ;
V_192 -> V_202 = V_4 -> V_14 . V_14 . V_199 . V_202 ;
V_192 -> V_203 = V_4 -> V_14 . V_14 . V_199 . V_204 ;
V_192 -> V_150 = V_4 -> V_14 . V_14 . V_199 . V_204 ;
V_4 -> V_28 = V_30 ;
V_4 -> V_195 = V_198 ;
} else {
goto exit;
}
V_2 -> V_12 . V_20 = F_8 ( V_2 -> V_22 . V_23 ,
V_2 -> V_12 . V_20 ) ;
goto V_184;
}
if ( F_16 ( F_21 ( V_2 ) == V_99 &&
V_2 -> V_12 . V_25 > ( V_2 -> V_24 . V_25 + V_205 ) ) ) {
V_2 -> V_12 . V_188 = 1 ;
goto exit;
}
if ( F_16 ( F_58 ( & V_2 -> V_206 ) >
V_207 ) ) {
V_2 -> V_177 = 1 ;
goto exit;
}
V_13 = F_2 ( V_2 , V_4 , V_4 -> V_14 . V_13 ) ;
if ( F_16 ( V_13 < 0 ) ) {
V_4 -> V_195 = V_208 ;
goto exit;
}
V_5 = V_130 [ V_13 ] . V_5 ;
if ( F_16 ( V_5 & V_209 ) ) {
if ( F_22 ( V_2 , V_4 ) )
goto exit;
}
V_11 = F_25 ( V_2 , V_4 ) ;
V_119 = ( V_5 & V_165 ) ? V_4 -> V_9 . V_10 : 0 ;
if ( V_119 > V_11 ) {
if ( F_21 ( V_2 ) == V_102 ) {
V_4 -> V_26 = V_2 -> V_12 . V_25 ;
V_4 -> V_173 = V_2 -> V_12 . V_25 ;
V_2 -> V_12 . V_25 = ( V_2 -> V_12 . V_25 + 1 ) & V_27 ;
V_2 -> V_12 . V_13 = V_104 ;
V_2 -> V_12 . V_20 = F_8 ( V_2 -> V_22 . V_23 ,
V_2 -> V_12 . V_20 ) ;
V_4 -> V_28 = V_30 ;
V_4 -> V_195 = V_198 ;
F_59 ( & V_2 -> V_24 . V_41 ) ;
F_60 ( V_2 ) ;
return 0 ;
}
V_119 = V_11 ;
}
V_122 = F_27 ( V_2 , V_4 , V_13 , V_119 , & V_121 ) ;
if ( F_16 ( ! V_122 ) ) {
F_56 ( L_3 , F_13 ( V_2 ) ) ;
goto V_163;
}
if ( F_41 ( V_2 , V_4 , & V_121 , V_122 , V_119 ) ) {
F_12 ( L_4 , F_13 ( V_2 ) ) ;
goto V_163;
}
F_48 ( V_4 , V_2 , & V_175 , & V_176 ) ;
F_46 ( V_2 , V_4 , & V_121 ) ;
F_47 ( V_2 , V_4 , & V_121 , V_119 ) ;
V_183 = F_61 ( F_26 ( V_2 -> V_46 . V_50 ) , V_2 , & V_121 , V_122 ) ;
if ( V_183 ) {
V_2 -> V_177 = 1 ;
F_62 ( V_122 ) ;
F_49 ( V_4 , V_2 , & V_175 , V_176 ) ;
if ( V_183 == - V_110 ) {
F_14 ( & V_2 -> V_12 . V_41 , 1 ) ;
goto exit;
}
goto V_163;
}
F_50 ( V_2 , V_4 , & V_121 , V_119 ) ;
goto V_184;
V_163:
F_62 ( V_122 ) ;
V_4 -> V_195 = V_210 ;
V_4 -> V_28 = V_194 ;
V_4 -> V_14 . V_15 |= V_211 ;
F_59 ( & V_2 -> V_24 . V_41 ) ;
exit:
F_60 ( V_2 ) ;
return - V_110 ;
}

static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( L_1 , V_2 -> V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( L_2 , V_2 -> V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 ,
struct V_1 * V_4 )
{
F_2 ( L_3 , V_4 -> V_4 ,
V_4 -> V_7 -> V_8 , V_4 -> V_9 . V_10 ) ;
}
static int F_5 ( struct V_11 * V_7 )
{
V_7 -> V_12 = F_6 ( V_7 -> V_13 ) ;
if ( F_7 ( V_7 -> V_12 ) )
goto V_14;
V_7 -> V_15 = F_8 ( V_7 -> V_13 ,
V_16 ,
F_1 ,
( void * ) V_7 ,
V_17 , 0 ) ;
if ( F_7 ( V_7 -> V_15 ) )
goto V_18;
V_7 -> V_19 = F_8 ( V_7 -> V_13 ,
NULL , F_1 ,
( void * ) V_7 ,
V_20 , 0 ) ;
if ( F_7 ( V_7 -> V_19 ) )
goto V_21;
if ( F_9 ( V_7 -> V_15 , V_22 ) )
goto V_23;
F_10 ( & V_7 -> V_24 ,
V_25 ,
( unsigned long ) V_7 ) ;
V_7 -> V_26 = F_11 ( V_7 -> V_12 , V_27 |
V_28 |
V_29 ) ;
if ( F_7 ( V_7 -> V_26 ) )
goto V_30;
F_12 ( & V_7 -> V_31 , V_7 -> V_13 ,
F_4 ) ;
if ( F_13 ( & V_7 -> V_31 ) )
goto V_32;
return 0 ;
V_32:
F_14 ( V_7 -> V_26 ) ;
V_30:
F_15 ( & V_7 -> V_24 ) ;
V_23:
F_16 ( V_7 -> V_19 ) ;
V_21:
F_16 ( V_7 -> V_15 ) ;
V_18:
F_17 ( V_7 -> V_12 ) ;
V_14:
F_2 ( L_4 ) ;
return - 1 ;
}
static void F_18 ( struct V_11 * V_7 )
{
F_19 ( V_7 -> V_26 == NULL ) ;
F_15 ( & V_7 -> V_24 ) ;
( void ) F_20 ( & V_7 -> V_31 ) ;
( void ) F_14 ( V_7 -> V_26 ) ;
( void ) F_16 ( V_7 -> V_19 ) ;
( void ) F_16 ( V_7 -> V_15 ) ;
( void ) F_17 ( V_7 -> V_12 ) ;
V_7 -> V_26 = NULL ;
V_7 -> V_19 = NULL ;
V_7 -> V_15 = NULL ;
V_7 -> V_12 = NULL ;
}
static int F_21 ( struct V_33 * V_34 )
{
struct V_11 * V_7 ;
struct V_35 V_36 ;
int V_37 , V_38 , V_39 = - V_40 ;
struct V_41 V_42 ;
F_19 ( V_34 -> V_7 == NULL ) ;
V_7 = V_34 -> V_7 ;
V_34 -> V_43 = F_22 ( V_44 +
V_45 , V_46 ) ;
if ( ! V_34 -> V_43 )
goto V_47;
V_34 -> V_48 = V_34 -> V_43 ;
V_34 -> V_49 = V_34 -> V_43 + V_44 ;
V_34 -> V_50 = F_23 ( V_34 -> V_7 -> V_13 ,
( void * ) V_34 -> V_48 ,
V_44 , V_51 ) ;
V_34 -> V_52 = F_23 ( V_34 -> V_7 -> V_13 ,
( void * ) V_34 -> V_49 ,
V_45 , V_53 ) ;
V_37 = F_24 ( V_7 -> V_13 , V_34 -> V_50 ) ;
V_38 = F_24 ( V_7 -> V_13 , V_34 -> V_52 ) ;
if ( V_37 || V_38 ) {
if ( V_37 )
V_34 -> V_50 = 0 ;
if ( V_38 )
V_34 -> V_52 = 0 ;
goto V_47;
}
V_34 -> V_54 = F_22 ( sizeof( struct V_55 ) +
( sizeof( V_56 ) * ( V_57 + 1 ) ) ,
V_46 ) ;
if ( ! V_34 -> V_54 )
goto V_47;
V_34 -> V_54 -> V_58 = ( V_56 * ) ( V_34 -> V_54 + 1 ) ;
V_42 . V_59 = V_60 ;
V_42 . V_61 = V_57 + 1 ;
V_42 . V_62 = V_63 * 2 ;
V_42 . V_64 = V_63 ;
V_42 . V_65 = 0 ;
V_42 . V_66 = NULL ;
V_42 . V_67 = ( V_27 |
V_28 |
V_29 ) ;
V_34 -> V_68 = F_25 ( V_7 -> V_12 , & V_42 ) ;
if ( F_7 ( V_34 -> V_68 ) ) {
V_39 = F_26 ( V_34 -> V_68 ) ;
V_34 -> V_68 = NULL ;
goto V_47;
}
memset ( & V_36 , 0 , sizeof V_36 ) ;
V_36 . V_31 = F_3 ;
V_36 . V_69 = ( void * ) V_34 ;
V_36 . V_70 = V_7 -> V_19 ;
V_36 . V_71 = V_7 -> V_15 ;
V_36 . V_72 . V_73 = V_74 ;
V_36 . V_72 . V_75 = V_76 ;
V_36 . V_72 . V_77 = 2 ;
V_36 . V_72 . V_78 = 1 ;
V_36 . V_79 = V_80 ;
V_36 . V_81 = V_82 ;
V_39 = F_27 ( V_34 -> V_83 , V_7 -> V_12 , & V_36 ) ;
if ( V_39 )
goto V_47;
V_34 -> V_84 = V_34 -> V_83 -> V_84 ;
F_2 ( L_5 ,
V_34 , V_34 -> V_83 ,
V_34 -> V_68 , V_34 -> V_83 -> V_84 ) ;
return V_39 ;
V_47:
F_2 ( L_6 , V_39 ) ;
return V_39 ;
}
static int F_28 ( struct V_33 * V_34 , int V_85 )
{
F_19 ( V_34 == NULL ) ;
F_2 ( L_7 ,
V_34 , V_34 -> V_83 ,
V_34 -> V_68 , V_34 -> V_84 ) ;
if ( V_34 -> V_68 != NULL )
F_29 ( V_34 -> V_68 ) ;
if ( V_34 -> V_84 != NULL )
F_30 ( V_34 -> V_83 ) ;
if ( V_34 -> V_83 != NULL && V_85 )
F_31 ( V_34 -> V_83 ) ;
V_34 -> V_68 = NULL ;
V_34 -> V_84 = NULL ;
V_34 -> V_83 = NULL ;
F_32 ( V_34 -> V_54 ) ;
return 0 ;
}
static
struct V_11 * F_33 ( struct V_86 * V_83 )
{
struct V_11 * V_7 ;
F_34 ( & V_87 . V_88 ) ;
F_35 (device, &ig.device_list, ig_list)
if ( V_7 -> V_13 -> V_89 == V_83 -> V_7 -> V_89 )
goto V_90;
V_7 = F_36 ( sizeof *V_7 , V_46 ) ;
if ( V_7 == NULL )
goto V_91;
V_7 -> V_13 = V_83 -> V_7 ;
if ( F_5 ( V_7 ) ) {
F_32 ( V_7 ) ;
V_7 = NULL ;
goto V_91;
}
F_37 ( & V_7 -> V_92 , & V_87 . V_93 ) ;
V_90:
V_7 -> V_94 ++ ;
V_91:
F_38 ( & V_87 . V_88 ) ;
return V_7 ;
}
static void F_39 ( struct V_11 * V_7 )
{
F_34 ( & V_87 . V_88 ) ;
V_7 -> V_94 -- ;
F_2 ( L_8 , V_7 , V_7 -> V_94 ) ;
if ( ! V_7 -> V_94 ) {
F_18 ( V_7 ) ;
F_40 ( & V_7 -> V_92 ) ;
F_32 ( V_7 ) ;
}
F_38 ( & V_87 . V_88 ) ;
}
static int F_41 ( struct V_33 * V_34 ,
enum V_95 V_96 ,
enum V_95 V_97 )
{
int V_39 ;
F_42 ( & V_34 -> V_98 ) ;
if ( ( V_39 = ( V_34 -> V_99 == V_96 ) ) )
V_34 -> V_99 = V_97 ;
F_43 ( & V_34 -> V_98 ) ;
return V_39 ;
}
static void F_44 ( struct V_33 * V_34 , int V_85 )
{
struct V_11 * V_7 = V_34 -> V_7 ;
F_19 ( V_34 -> V_99 != V_100 ) ;
F_34 ( & V_87 . V_101 ) ;
F_40 ( & V_34 -> V_102 ) ;
F_38 ( & V_87 . V_101 ) ;
F_45 ( V_34 ) ;
F_28 ( V_34 , V_85 ) ;
V_34 -> V_7 = NULL ;
if ( V_7 != NULL )
F_39 ( V_7 ) ;
F_46 ( V_34 -> V_103 ) ;
}
void F_47 ( struct V_33 * V_34 )
{
F_48 ( & V_34 -> V_94 ) ;
}
int F_49 ( struct V_33 * V_34 , int V_85 )
{
if ( F_50 ( & V_34 -> V_94 ) ) {
F_44 ( V_34 , V_85 ) ;
return 1 ;
}
return 0 ;
}
void F_51 ( struct V_33 * V_34 )
{
int V_104 = 0 ;
F_41 ( V_34 , V_105 , V_106 ) ;
V_104 = F_52 ( V_34 -> V_83 ) ;
if ( V_104 )
F_2 ( L_9 ,
V_34 , V_104 ) ;
F_53 ( V_34 -> V_107 ,
V_34 -> V_99 == V_100 ) ;
F_49 ( V_34 , 1 ) ;
}
static int F_54 ( struct V_86 * V_83 )
{
struct V_33 * V_34 ;
V_34 = (struct V_33 * ) V_83 -> V_3 ;
V_34 -> V_99 = V_100 ;
F_55 ( & V_34 -> V_107 ) ;
return F_49 ( V_34 , 0 ) ;
}
static int F_56 ( struct V_86 * V_83 )
{
struct V_11 * V_7 ;
struct V_33 * V_34 ;
int V_39 ;
V_7 = F_33 ( V_83 ) ;
if ( ! V_7 ) {
F_2 ( L_10 ) ;
return F_54 ( V_83 ) ;
}
V_34 = (struct V_33 * ) V_83 -> V_3 ;
V_34 -> V_7 = V_7 ;
V_39 = F_57 ( V_83 , 1000 ) ;
if ( V_39 ) {
F_2 ( L_11 , V_39 ) ;
return F_54 ( V_83 ) ;
}
return 0 ;
}
static int F_58 ( struct V_86 * V_83 )
{
struct V_108 V_109 ;
int V_39 ;
V_39 = F_21 ( (struct V_33 * ) V_83 -> V_3 ) ;
if ( V_39 )
goto V_110;
memset ( & V_109 , 0 , sizeof V_109 ) ;
V_109 . V_111 = 4 ;
V_109 . V_112 = 1 ;
V_109 . V_113 = 7 ;
V_109 . V_114 = 6 ;
V_39 = F_59 ( V_83 , & V_109 ) ;
if ( V_39 ) {
F_2 ( L_12 , V_39 ) ;
goto V_110;
}
return 0 ;
V_110:
return F_54 ( V_83 ) ;
}
static void F_60 ( struct V_86 * V_83 )
{
struct V_33 * V_34 ;
V_34 = (struct V_33 * ) V_83 -> V_3 ;
V_34 -> V_99 = V_105 ;
F_55 ( & V_34 -> V_107 ) ;
}
static int F_61 ( struct V_86 * V_83 )
{
struct V_33 * V_34 ;
int V_39 ;
V_34 = (struct V_33 * ) V_83 -> V_3 ;
if ( F_41 ( V_34 , V_105 ,
V_106 ) )
F_62 ( V_34 -> V_33 -> V_115 ,
V_116 ) ;
if ( V_34 -> V_117 == 0 &&
( F_63 ( & V_34 -> V_118 ) == 0 ) ) {
V_34 -> V_99 = V_100 ;
F_55 ( & V_34 -> V_107 ) ;
}
V_39 = F_49 ( V_34 , 0 ) ;
return V_39 ;
}
static int F_64 ( struct V_86 * V_83 , struct V_119 * V_4 )
{
int V_39 = 0 ;
F_2 ( L_13 ,
V_4 -> V_4 , V_4 -> V_120 , V_83 -> V_3 , V_83 ) ;
switch ( V_4 -> V_4 ) {
case V_121 :
V_39 = F_56 ( V_83 ) ;
break;
case V_122 :
V_39 = F_58 ( V_83 ) ;
break;
case V_123 :
F_60 ( V_83 ) ;
break;
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
V_39 = F_54 ( V_83 ) ;
break;
case V_129 :
case V_130 :
case V_131 :
V_39 = F_61 ( V_83 ) ;
break;
default:
F_2 ( L_14 , V_4 -> V_4 ) ;
break;
}
return V_39 ;
}
void F_65 ( struct V_33 * V_34 )
{
V_34 -> V_99 = V_132 ;
F_66 ( & V_34 -> V_107 ) ;
V_34 -> V_117 = 0 ;
F_67 ( & V_34 -> V_118 , 0 ) ;
F_67 ( & V_34 -> V_94 , 1 ) ;
F_68 ( & V_34 -> V_102 ) ;
F_69 ( & V_34 -> V_98 ) ;
}
int F_70 ( struct V_33 * V_34 ,
struct V_133 * V_134 ,
struct V_133 * V_135 ,
int V_136 )
{
struct V_137 * V_138 , * V_139 ;
int V_104 = 0 ;
sprintf ( V_34 -> V_8 , L_15 ,
& V_135 -> V_140 . V_141 , V_135 -> V_142 ) ;
V_34 -> V_7 = NULL ;
F_2 ( L_16 ,
& V_135 -> V_140 , V_135 -> V_142 ) ;
V_34 -> V_99 = V_143 ;
F_47 ( V_34 ) ;
V_34 -> V_83 = F_71 ( F_64 ,
( void * ) V_34 ,
V_144 , V_82 ) ;
if ( F_7 ( V_34 -> V_83 ) ) {
V_104 = F_26 ( V_34 -> V_83 ) ;
F_2 ( L_17 , V_104 ) ;
goto V_145;
}
V_138 = (struct V_137 * ) V_134 ;
V_139 = (struct V_137 * ) V_135 ;
V_104 = F_72 ( V_34 -> V_83 , V_138 , V_139 , 1000 ) ;
if ( V_104 ) {
F_2 ( L_18 , V_104 ) ;
goto V_146;
}
if ( ! V_136 ) {
F_53 ( V_34 -> V_107 ,
( V_34 -> V_99 != V_143 ) ) ;
if ( V_34 -> V_99 != V_105 ) {
V_104 = - V_147 ;
goto V_148;
}
}
F_34 ( & V_87 . V_101 ) ;
F_37 ( & V_34 -> V_102 , & V_87 . V_149 ) ;
F_38 ( & V_87 . V_101 ) ;
return 0 ;
V_145:
V_34 -> V_83 = NULL ;
V_146:
V_34 -> V_99 = V_100 ;
V_148:
F_44 ( V_34 , 1 ) ;
return V_104 ;
}
int F_73 ( struct V_33 * V_34 ,
struct V_55 * V_54 ,
struct V_150 * V_151 )
{
struct V_152 * V_153 ;
V_56 V_154 ;
V_56 * V_155 ;
int V_120 ;
V_155 = V_54 -> V_58 ;
V_154 = V_155 [ 0 ] ;
V_153 = F_74 ( V_34 -> V_68 ,
V_155 ,
V_54 -> V_156 ,
V_154 ) ;
if ( F_7 ( V_153 ) ) {
V_120 = ( int ) F_26 ( V_153 ) ;
F_2 ( L_19 , V_120 ) ;
return V_120 ;
}
V_151 -> V_157 = V_153 -> V_158 -> V_157 ;
V_151 -> V_159 = V_153 -> V_158 -> V_159 ;
V_151 -> V_160 = V_54 -> V_156 * V_161 ;
V_151 -> V_162 = V_154 ;
V_151 -> V_163 = 1 ;
V_151 -> V_164 = ( void * ) V_153 ;
V_151 -> V_162 += V_54 -> V_165 ;
V_151 -> V_160 = V_54 -> V_166 ;
F_75 ( L_20
L_21
L_22 ,
V_54 , V_54 -> V_156 ,
( unsigned long ) V_54 -> V_58 [ 0 ] ,
( unsigned long ) V_54 -> V_166 ,
( unsigned int ) V_151 -> V_157 , V_151 -> V_164 ,
( unsigned long ) V_151 -> V_162 , ( unsigned long ) V_151 -> V_160 ) ;
return 0 ;
}
void F_76 ( struct V_150 * V_167 )
{
int V_39 ;
F_75 ( L_23 , V_167 -> V_164 ) ;
V_39 = F_77 ( (struct V_152 * ) V_167 -> V_164 ) ;
if ( V_39 )
F_2 ( L_24 , V_39 ) ;
V_167 -> V_164 = NULL ;
}
int F_78 ( struct V_33 * V_34 )
{
struct V_168 V_169 , * V_170 ;
struct V_171 V_172 ;
int V_173 ;
V_172 . V_174 = V_34 -> V_52 ;
V_172 . V_156 = V_45 ;
V_172 . V_157 = V_34 -> V_7 -> V_26 -> V_157 ;
V_169 . V_175 = ( unsigned long ) V_34 -> V_49 ;
V_169 . V_176 = & V_172 ;
V_169 . V_177 = 1 ;
V_169 . V_178 = NULL ;
V_34 -> V_117 ++ ;
V_173 = F_79 ( V_34 -> V_84 , & V_169 , & V_170 ) ;
if ( V_173 ) {
F_2 ( L_25 , V_173 ) ;
V_34 -> V_117 -- ;
}
return V_173 ;
}
int F_80 ( struct V_33 * V_34 , int V_179 )
{
struct V_168 * V_169 , * V_170 ;
int V_180 , V_173 ;
unsigned int V_181 = V_34 -> V_182 ;
struct V_183 * V_184 ;
for ( V_169 = V_34 -> V_169 , V_180 = 0 ; V_180 < V_179 ; V_180 ++ , V_169 ++ ) {
V_184 = & V_34 -> V_185 [ V_181 ] ;
V_169 -> V_175 = ( unsigned long ) V_184 ;
V_169 -> V_176 = & V_184 -> V_186 ;
V_169 -> V_177 = 1 ;
V_169 -> V_178 = V_169 + 1 ;
V_181 = ( V_181 + 1 ) & ( V_76 - 1 ) ;
}
V_169 -- ;
V_169 -> V_178 = NULL ;
V_34 -> V_117 += V_179 ;
V_173 = F_79 ( V_34 -> V_84 , V_34 -> V_169 , & V_170 ) ;
if ( V_173 ) {
F_2 ( L_25 , V_173 ) ;
V_34 -> V_117 -= V_179 ;
} else
V_34 -> V_182 = V_181 ;
return V_173 ;
}
int F_81 ( struct V_33 * V_34 , struct V_187 * V_188 )
{
int V_173 ;
struct V_189 V_190 , * V_191 ;
F_82 ( V_34 -> V_7 -> V_13 ,
V_188 -> V_192 , V_193 , V_51 ) ;
V_190 . V_178 = NULL ;
V_190 . V_175 = ( unsigned long ) V_188 ;
V_190 . V_176 = V_188 -> V_194 ;
V_190 . V_177 = V_188 -> V_177 ;
V_190 . V_195 = V_196 ;
V_190 . V_197 = V_198 ;
F_48 ( & V_34 -> V_118 ) ;
V_173 = F_83 ( V_34 -> V_84 , & V_190 , & V_191 ) ;
if ( V_173 ) {
F_2 ( L_26 , V_173 ) ;
F_84 ( & V_34 -> V_118 ) ;
}
return V_173 ;
}
static void F_85 ( struct V_187 * V_199 ,
struct V_33 * V_34 )
{
if ( V_199 && V_199 -> type == V_200 )
F_86 ( V_87 . V_201 , V_199 ) ;
if ( V_34 -> V_117 == 0 &&
F_63 ( & V_34 -> V_118 ) == 0 ) {
if ( F_41 ( V_34 , V_105 ,
V_106 ) )
F_62 ( V_34 -> V_33 -> V_115 ,
V_116 ) ;
V_34 -> V_99 = V_100 ;
F_55 ( & V_34 -> V_107 ) ;
}
}
static int F_87 ( struct V_11 * V_7 )
{
struct V_202 * V_203 = V_7 -> V_19 ;
struct V_204 V_205 ;
struct V_187 * V_188 ;
struct V_33 * V_34 ;
int V_206 = 0 ;
while ( F_88 ( V_203 , 1 , & V_205 ) == 1 ) {
V_188 = (struct V_187 * ) ( unsigned long ) V_205 . V_175 ;
V_34 = V_205 . V_84 -> V_69 ;
if ( V_205 . V_120 == V_207 ) {
if ( V_205 . V_195 == V_208 )
F_89 ( V_188 , V_34 ) ;
else
F_2 ( L_27 ,
V_208 , V_205 . V_195 ) ;
} else {
F_2 ( L_28 ,
V_205 . V_175 , V_205 . V_120 , V_205 . V_209 ) ;
F_84 ( & V_34 -> V_118 ) ;
F_85 ( V_188 , V_34 ) ;
}
V_206 ++ ;
}
return V_206 ;
}
static void V_25 ( unsigned long V_210 )
{
struct V_11 * V_7 = (struct V_11 * ) V_210 ;
struct V_202 * V_203 = V_7 -> V_15 ;
struct V_204 V_205 ;
struct V_183 * V_199 ;
unsigned long V_211 ;
struct V_33 * V_34 ;
int V_206 , V_212 ;
V_206 = V_212 = 0 ;
while ( F_88 ( V_203 , 1 , & V_205 ) == 1 ) {
V_199 = (struct V_183 * ) ( unsigned long ) V_205 . V_175 ;
F_19 ( V_199 == NULL ) ;
V_34 = V_205 . V_84 -> V_69 ;
if ( V_205 . V_120 == V_207 ) {
if ( V_205 . V_195 == V_213 ) {
V_211 = ( unsigned long ) V_205 . V_214 ;
F_90 ( V_199 , V_211 , V_34 ) ;
} else
F_2 ( L_27 ,
V_213 , V_205 . V_195 ) ;
} else {
if ( V_205 . V_120 != V_215 )
F_2 ( L_29 ,
V_205 . V_175 , V_205 . V_120 , V_205 . V_209 ) ;
V_34 -> V_117 -- ;
F_85 ( NULL , V_34 ) ;
}
V_212 ++ ;
if ( ! ( V_212 & 63 ) )
V_206 += F_87 ( V_7 ) ;
}
F_9 ( V_203 , V_22 ) ;
V_206 += F_87 ( V_7 ) ;
F_75 ( L_30 , V_212 , V_206 ) ;
}
static void V_16 ( struct V_202 * V_203 , void * V_216 )
{
struct V_11 * V_7 = (struct V_11 * ) V_216 ;
F_91 ( & V_7 -> V_24 ) ;
}

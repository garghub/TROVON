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
int V_37 = - V_38 ;
struct V_39 V_40 ;
F_19 ( V_34 -> V_7 == NULL ) ;
V_7 = V_34 -> V_7 ;
V_34 -> V_41 = F_22 ( V_42 , V_43 ) ;
if ( ! V_34 -> V_41 )
goto V_44;
V_34 -> V_45 = F_23 ( V_34 -> V_7 -> V_13 ,
( void * ) V_34 -> V_41 , V_42 ,
V_46 ) ;
V_34 -> V_47 = F_22 ( sizeof( struct V_48 ) +
( sizeof( V_49 ) * ( V_50 + 1 ) ) ,
V_43 ) ;
if ( ! V_34 -> V_47 )
goto V_44;
V_34 -> V_47 -> V_51 = ( V_49 * ) ( V_34 -> V_47 + 1 ) ;
V_40 . V_52 = V_53 ;
V_40 . V_54 = V_50 + 1 ;
V_40 . V_55 = V_56 * 2 ;
V_40 . V_57 = V_56 ;
V_40 . V_58 = 0 ;
V_40 . V_59 = NULL ;
V_40 . V_60 = ( V_27 |
V_28 |
V_29 ) ;
V_34 -> V_61 = F_24 ( V_7 -> V_12 , & V_40 ) ;
if ( F_7 ( V_34 -> V_61 ) ) {
V_37 = F_25 ( V_34 -> V_61 ) ;
V_34 -> V_61 = NULL ;
goto V_44;
}
memset ( & V_36 , 0 , sizeof V_36 ) ;
V_36 . V_31 = F_3 ;
V_36 . V_62 = ( void * ) V_34 ;
V_36 . V_63 = V_7 -> V_19 ;
V_36 . V_64 = V_7 -> V_15 ;
V_36 . V_65 . V_66 = V_67 ;
V_36 . V_65 . V_68 = V_69 ;
V_36 . V_65 . V_70 = 2 ;
V_36 . V_65 . V_71 = 1 ;
V_36 . V_72 = V_73 ;
V_36 . V_74 = V_75 ;
V_37 = F_26 ( V_34 -> V_76 , V_7 -> V_12 , & V_36 ) ;
if ( V_37 )
goto V_44;
V_34 -> V_77 = V_34 -> V_76 -> V_77 ;
F_2 ( L_5 ,
V_34 , V_34 -> V_76 ,
V_34 -> V_61 , V_34 -> V_76 -> V_77 ) ;
return V_37 ;
V_44:
F_2 ( L_6 , V_37 ) ;
return V_37 ;
}
static int F_27 ( struct V_33 * V_34 , int V_78 )
{
F_19 ( V_34 == NULL ) ;
F_2 ( L_7 ,
V_34 , V_34 -> V_76 ,
V_34 -> V_61 , V_34 -> V_77 ) ;
if ( V_34 -> V_61 != NULL )
F_28 ( V_34 -> V_61 ) ;
if ( V_34 -> V_77 != NULL )
F_29 ( V_34 -> V_76 ) ;
if ( V_34 -> V_76 != NULL && V_78 )
F_30 ( V_34 -> V_76 ) ;
V_34 -> V_61 = NULL ;
V_34 -> V_77 = NULL ;
V_34 -> V_76 = NULL ;
F_31 ( V_34 -> V_47 ) ;
return 0 ;
}
static
struct V_11 * F_32 ( struct V_79 * V_76 )
{
struct V_11 * V_7 ;
F_33 ( & V_80 . V_81 ) ;
F_34 (device, &ig.device_list, ig_list)
if ( V_7 -> V_13 -> V_82 == V_76 -> V_7 -> V_82 )
goto V_83;
V_7 = F_35 ( sizeof *V_7 , V_43 ) ;
if ( V_7 == NULL )
goto V_84;
V_7 -> V_13 = V_76 -> V_7 ;
if ( F_5 ( V_7 ) ) {
F_31 ( V_7 ) ;
V_7 = NULL ;
goto V_84;
}
F_36 ( & V_7 -> V_85 , & V_80 . V_86 ) ;
V_83:
V_7 -> V_87 ++ ;
V_84:
F_37 ( & V_80 . V_81 ) ;
return V_7 ;
}
static void F_38 ( struct V_11 * V_7 )
{
F_33 ( & V_80 . V_81 ) ;
V_7 -> V_87 -- ;
F_2 ( L_8 , V_7 , V_7 -> V_87 ) ;
if ( ! V_7 -> V_87 ) {
F_18 ( V_7 ) ;
F_39 ( & V_7 -> V_85 ) ;
F_31 ( V_7 ) ;
}
F_37 ( & V_80 . V_81 ) ;
}
static int F_40 ( struct V_33 * V_34 ,
enum V_88 V_89 ,
enum V_88 V_90 )
{
int V_37 ;
F_41 ( & V_34 -> V_91 ) ;
if ( ( V_37 = ( V_34 -> V_92 == V_89 ) ) )
V_34 -> V_92 = V_90 ;
F_42 ( & V_34 -> V_91 ) ;
return V_37 ;
}
static void F_43 ( struct V_33 * V_34 , int V_78 )
{
struct V_11 * V_7 = V_34 -> V_7 ;
F_19 ( V_34 -> V_92 != V_93 ) ;
F_33 ( & V_80 . V_94 ) ;
F_39 ( & V_34 -> V_95 ) ;
F_37 ( & V_80 . V_94 ) ;
F_44 ( V_34 ) ;
F_27 ( V_34 , V_78 ) ;
V_34 -> V_7 = NULL ;
if ( V_7 != NULL )
F_38 ( V_7 ) ;
F_45 ( V_34 -> V_96 ) ;
}
void F_46 ( struct V_33 * V_34 )
{
F_47 ( & V_34 -> V_87 ) ;
}
int F_48 ( struct V_33 * V_34 , int V_78 )
{
if ( F_49 ( & V_34 -> V_87 ) ) {
F_43 ( V_34 , V_78 ) ;
return 1 ;
}
return 0 ;
}
void F_50 ( struct V_33 * V_34 )
{
int V_97 = 0 ;
F_40 ( V_34 , V_98 , V_99 ) ;
V_97 = F_51 ( V_34 -> V_76 ) ;
if ( V_97 )
F_2 ( L_9 ,
V_34 , V_97 ) ;
F_52 ( V_34 -> V_100 ,
V_34 -> V_92 == V_93 ) ;
F_48 ( V_34 , 1 ) ;
}
static int F_53 ( struct V_79 * V_76 )
{
struct V_33 * V_34 ;
V_34 = (struct V_33 * ) V_76 -> V_3 ;
V_34 -> V_92 = V_93 ;
F_54 ( & V_34 -> V_100 ) ;
return F_48 ( V_34 , 0 ) ;
}
static int F_55 ( struct V_79 * V_76 )
{
struct V_11 * V_7 ;
struct V_33 * V_34 ;
int V_37 ;
V_7 = F_32 ( V_76 ) ;
if ( ! V_7 ) {
F_2 ( L_10 ) ;
return F_53 ( V_76 ) ;
}
V_34 = (struct V_33 * ) V_76 -> V_3 ;
V_34 -> V_7 = V_7 ;
V_37 = F_56 ( V_76 , 1000 ) ;
if ( V_37 ) {
F_2 ( L_11 , V_37 ) ;
return F_53 ( V_76 ) ;
}
return 0 ;
}
static int F_57 ( struct V_79 * V_76 )
{
struct V_101 V_102 ;
int V_37 ;
V_37 = F_21 ( (struct V_33 * ) V_76 -> V_3 ) ;
if ( V_37 )
goto V_103;
memset ( & V_102 , 0 , sizeof V_102 ) ;
V_102 . V_104 = 4 ;
V_102 . V_105 = 1 ;
V_102 . V_106 = 7 ;
V_102 . V_107 = 6 ;
V_37 = F_58 ( V_76 , & V_102 ) ;
if ( V_37 ) {
F_2 ( L_12 , V_37 ) ;
goto V_103;
}
return 0 ;
V_103:
return F_53 ( V_76 ) ;
}
static void F_59 ( struct V_79 * V_76 )
{
struct V_33 * V_34 ;
V_34 = (struct V_33 * ) V_76 -> V_3 ;
V_34 -> V_92 = V_98 ;
F_54 ( & V_34 -> V_100 ) ;
}
static int F_60 ( struct V_79 * V_76 )
{
struct V_33 * V_34 ;
int V_37 ;
V_34 = (struct V_33 * ) V_76 -> V_3 ;
if ( F_40 ( V_34 , V_98 ,
V_99 ) )
F_61 ( V_34 -> V_33 -> V_108 ,
V_109 ) ;
if ( V_34 -> V_110 == 0 &&
( F_62 ( & V_34 -> V_111 ) == 0 ) ) {
V_34 -> V_92 = V_93 ;
F_54 ( & V_34 -> V_100 ) ;
}
V_37 = F_48 ( V_34 , 0 ) ;
return V_37 ;
}
static int F_63 ( struct V_79 * V_76 , struct V_112 * V_4 )
{
int V_37 = 0 ;
F_2 ( L_13 ,
V_4 -> V_4 , V_4 -> V_113 , V_76 -> V_3 , V_76 ) ;
switch ( V_4 -> V_4 ) {
case V_114 :
V_37 = F_55 ( V_76 ) ;
break;
case V_115 :
V_37 = F_57 ( V_76 ) ;
break;
case V_116 :
F_59 ( V_76 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_37 = F_53 ( V_76 ) ;
break;
case V_122 :
case V_123 :
case V_124 :
V_37 = F_60 ( V_76 ) ;
break;
default:
F_2 ( L_14 , V_4 -> V_4 ) ;
break;
}
return V_37 ;
}
void F_64 ( struct V_33 * V_34 )
{
V_34 -> V_92 = V_125 ;
F_65 ( & V_34 -> V_100 ) ;
V_34 -> V_110 = 0 ;
F_66 ( & V_34 -> V_111 , 0 ) ;
F_66 ( & V_34 -> V_87 , 1 ) ;
F_67 ( & V_34 -> V_95 ) ;
F_68 ( & V_34 -> V_91 ) ;
}
int F_69 ( struct V_33 * V_34 ,
struct V_126 * V_127 ,
struct V_126 * V_128 ,
int V_129 )
{
struct V_130 * V_131 , * V_132 ;
int V_97 = 0 ;
sprintf ( V_34 -> V_8 , L_15 ,
& V_128 -> V_133 . V_134 , V_128 -> V_135 ) ;
V_34 -> V_7 = NULL ;
F_2 ( L_16 ,
& V_128 -> V_133 , V_128 -> V_135 ) ;
V_34 -> V_92 = V_136 ;
F_46 ( V_34 ) ;
V_34 -> V_76 = F_70 ( F_63 ,
( void * ) V_34 ,
V_137 , V_75 ) ;
if ( F_7 ( V_34 -> V_76 ) ) {
V_97 = F_25 ( V_34 -> V_76 ) ;
F_2 ( L_17 , V_97 ) ;
goto V_138;
}
V_131 = (struct V_130 * ) V_127 ;
V_132 = (struct V_130 * ) V_128 ;
V_97 = F_71 ( V_34 -> V_76 , V_131 , V_132 , 1000 ) ;
if ( V_97 ) {
F_2 ( L_18 , V_97 ) ;
goto V_139;
}
if ( ! V_129 ) {
F_52 ( V_34 -> V_100 ,
( V_34 -> V_92 != V_136 ) ) ;
if ( V_34 -> V_92 != V_98 ) {
V_97 = - V_140 ;
goto V_141;
}
}
F_33 ( & V_80 . V_94 ) ;
F_36 ( & V_34 -> V_95 , & V_80 . V_142 ) ;
F_37 ( & V_80 . V_94 ) ;
return 0 ;
V_138:
V_34 -> V_76 = NULL ;
V_139:
V_34 -> V_92 = V_93 ;
V_141:
F_43 ( V_34 , 1 ) ;
return V_97 ;
}
int F_72 ( struct V_33 * V_34 ,
struct V_48 * V_47 ,
struct V_143 * V_144 )
{
struct V_145 * V_146 ;
V_49 V_147 ;
V_49 * V_148 ;
int V_113 ;
V_148 = V_47 -> V_51 ;
V_147 = V_148 [ 0 ] ;
V_146 = F_73 ( V_34 -> V_61 ,
V_148 ,
V_47 -> V_149 ,
V_147 ) ;
if ( F_7 ( V_146 ) ) {
V_113 = ( int ) F_25 ( V_146 ) ;
F_2 ( L_19 , V_113 ) ;
return V_113 ;
}
V_144 -> V_150 = V_146 -> V_151 -> V_150 ;
V_144 -> V_152 = V_146 -> V_151 -> V_152 ;
V_144 -> V_153 = V_47 -> V_149 * V_154 ;
V_144 -> V_155 = V_147 ;
V_144 -> V_156 = 1 ;
V_144 -> V_157 = ( void * ) V_146 ;
V_144 -> V_155 += V_47 -> V_158 ;
V_144 -> V_153 = V_47 -> V_159 ;
F_74 ( L_20
L_21
L_22 ,
V_47 , V_47 -> V_149 ,
( unsigned long ) V_47 -> V_51 [ 0 ] ,
( unsigned long ) V_47 -> V_159 ,
( unsigned int ) V_144 -> V_150 , V_144 -> V_157 ,
( unsigned long ) V_144 -> V_155 , ( unsigned long ) V_144 -> V_153 ) ;
return 0 ;
}
void F_75 ( struct V_143 * V_160 )
{
int V_37 ;
F_74 ( L_23 , V_160 -> V_157 ) ;
V_37 = F_76 ( (struct V_145 * ) V_160 -> V_157 ) ;
if ( V_37 )
F_2 ( L_24 , V_37 ) ;
V_160 -> V_157 = NULL ;
}
int F_77 ( struct V_33 * V_34 )
{
struct V_161 V_162 , * V_163 ;
struct V_164 V_165 ;
int V_166 ;
V_165 . V_167 = V_34 -> V_45 ;
V_165 . V_149 = V_42 ;
V_165 . V_150 = V_34 -> V_7 -> V_26 -> V_150 ;
V_162 . V_168 = ( unsigned long ) V_34 -> V_41 ;
V_162 . V_169 = & V_165 ;
V_162 . V_170 = 1 ;
V_162 . V_171 = NULL ;
V_34 -> V_110 ++ ;
V_166 = F_78 ( V_34 -> V_77 , & V_162 , & V_163 ) ;
if ( V_166 ) {
F_2 ( L_25 , V_166 ) ;
V_34 -> V_110 -- ;
}
return V_166 ;
}
int F_79 ( struct V_33 * V_34 , int V_172 )
{
struct V_161 * V_162 , * V_163 ;
int V_173 , V_166 ;
unsigned int V_174 = V_34 -> V_175 ;
struct V_176 * V_177 ;
for ( V_162 = V_34 -> V_162 , V_173 = 0 ; V_173 < V_172 ; V_173 ++ , V_162 ++ ) {
V_177 = & V_34 -> V_178 [ V_174 ] ;
V_162 -> V_168 = ( unsigned long ) V_177 ;
V_162 -> V_169 = & V_177 -> V_179 ;
V_162 -> V_170 = 1 ;
V_162 -> V_171 = V_162 + 1 ;
V_174 = ( V_174 + 1 ) & ( V_69 - 1 ) ;
}
V_162 -- ;
V_162 -> V_171 = NULL ;
V_34 -> V_110 += V_172 ;
V_166 = F_78 ( V_34 -> V_77 , V_34 -> V_162 , & V_163 ) ;
if ( V_166 ) {
F_2 ( L_25 , V_166 ) ;
V_34 -> V_110 -= V_172 ;
} else
V_34 -> V_175 = V_174 ;
return V_166 ;
}
int F_80 ( struct V_33 * V_34 , struct V_180 * V_181 )
{
int V_166 ;
struct V_182 V_183 , * V_184 ;
F_81 ( V_34 -> V_7 -> V_13 ,
V_181 -> V_185 , V_186 , V_187 ) ;
V_183 . V_171 = NULL ;
V_183 . V_168 = ( unsigned long ) V_181 ;
V_183 . V_169 = V_181 -> V_188 ;
V_183 . V_170 = V_181 -> V_170 ;
V_183 . V_189 = V_190 ;
V_183 . V_191 = V_192 ;
F_47 ( & V_34 -> V_111 ) ;
V_166 = F_82 ( V_34 -> V_77 , & V_183 , & V_184 ) ;
if ( V_166 ) {
F_2 ( L_26 , V_166 ) ;
F_83 ( & V_34 -> V_111 ) ;
}
return V_166 ;
}
static void F_84 ( struct V_180 * V_193 ,
struct V_33 * V_34 )
{
if ( V_193 && V_193 -> type == V_194 )
F_85 ( V_80 . V_195 , V_193 ) ;
if ( V_34 -> V_110 == 0 &&
F_62 ( & V_34 -> V_111 ) == 0 ) {
if ( F_40 ( V_34 , V_98 ,
V_99 ) )
F_61 ( V_34 -> V_33 -> V_108 ,
V_109 ) ;
V_34 -> V_92 = V_93 ;
F_54 ( & V_34 -> V_100 ) ;
}
}
static int F_86 ( struct V_11 * V_7 )
{
struct V_196 * V_197 = V_7 -> V_19 ;
struct V_198 V_199 ;
struct V_180 * V_181 ;
struct V_33 * V_34 ;
int V_200 = 0 ;
while ( F_87 ( V_197 , 1 , & V_199 ) == 1 ) {
V_181 = (struct V_180 * ) ( unsigned long ) V_199 . V_168 ;
V_34 = V_199 . V_77 -> V_62 ;
if ( V_199 . V_113 == V_201 ) {
if ( V_199 . V_189 == V_202 )
F_88 ( V_181 , V_34 ) ;
else
F_2 ( L_27 ,
V_202 , V_199 . V_189 ) ;
} else {
F_2 ( L_28 ,
V_199 . V_168 , V_199 . V_113 , V_199 . V_203 ) ;
F_83 ( & V_34 -> V_111 ) ;
F_84 ( V_181 , V_34 ) ;
}
V_200 ++ ;
}
return V_200 ;
}
static void V_25 ( unsigned long V_204 )
{
struct V_11 * V_7 = (struct V_11 * ) V_204 ;
struct V_196 * V_197 = V_7 -> V_15 ;
struct V_198 V_199 ;
struct V_176 * V_193 ;
unsigned long V_205 ;
struct V_33 * V_34 ;
int V_200 , V_206 ;
V_200 = V_206 = 0 ;
while ( F_87 ( V_197 , 1 , & V_199 ) == 1 ) {
V_193 = (struct V_176 * ) ( unsigned long ) V_199 . V_168 ;
F_19 ( V_193 == NULL ) ;
V_34 = V_199 . V_77 -> V_62 ;
if ( V_199 . V_113 == V_201 ) {
if ( V_199 . V_189 == V_207 ) {
V_205 = ( unsigned long ) V_199 . V_208 ;
F_89 ( V_193 , V_205 , V_34 ) ;
} else
F_2 ( L_27 ,
V_207 , V_199 . V_189 ) ;
} else {
if ( V_199 . V_113 != V_209 )
F_2 ( L_29 ,
V_199 . V_168 , V_199 . V_113 , V_199 . V_203 ) ;
V_34 -> V_110 -- ;
F_84 ( NULL , V_34 ) ;
}
V_206 ++ ;
if ( ! ( V_206 & 63 ) )
V_200 += F_86 ( V_7 ) ;
}
F_9 ( V_197 , V_22 ) ;
V_200 += F_86 ( V_7 ) ;
F_74 ( L_30 , V_206 , V_200 ) ;
}
static void V_16 ( struct V_196 * V_197 , void * V_210 )
{
struct V_11 * V_7 = (struct V_11 * ) V_210 ;
F_90 ( & V_7 -> V_24 ) ;
}

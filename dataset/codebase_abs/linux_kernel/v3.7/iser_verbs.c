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
int V_12 , V_13 ;
struct V_14 * V_15 ;
V_7 -> V_16 = F_6 ( V_17 , V_7 -> V_18 -> V_19 ) ;
F_2 ( L_4 , V_7 -> V_16 ,
V_7 -> V_18 -> V_8 , V_7 -> V_18 -> V_19 ) ;
V_7 -> V_15 = F_7 ( sizeof( struct V_14 ) * V_7 -> V_16 ,
V_20 ) ;
if ( V_7 -> V_15 == NULL )
goto V_21;
V_15 = V_7 -> V_15 ;
V_7 -> V_22 = F_8 ( V_7 -> V_18 ) ;
if ( F_9 ( V_7 -> V_22 ) )
goto V_23;
for ( V_12 = 0 ; V_12 < V_7 -> V_16 ; V_12 ++ ) {
V_15 [ V_12 ] . V_7 = V_7 ;
V_15 [ V_12 ] . V_24 = V_12 ;
V_7 -> V_25 [ V_12 ] = F_10 ( V_7 -> V_18 ,
V_26 ,
F_1 ,
( void * ) & V_15 [ V_12 ] ,
V_27 , V_12 ) ;
if ( F_9 ( V_7 -> V_25 [ V_12 ] ) )
goto V_28;
V_7 -> V_29 [ V_12 ] = F_10 ( V_7 -> V_18 ,
NULL , F_1 ,
( void * ) & V_15 [ V_12 ] ,
V_30 , V_12 ) ;
if ( F_9 ( V_7 -> V_29 [ V_12 ] ) )
goto V_28;
if ( F_11 ( V_7 -> V_25 [ V_12 ] , V_31 ) )
goto V_28;
F_12 ( & V_7 -> V_32 [ V_12 ] ,
V_33 ,
( unsigned long ) & V_15 [ V_12 ] ) ;
}
V_7 -> V_34 = F_13 ( V_7 -> V_22 , V_35 |
V_36 |
V_37 ) ;
if ( F_9 ( V_7 -> V_34 ) )
goto V_38;
F_14 ( & V_7 -> V_39 , V_7 -> V_18 ,
F_4 ) ;
if ( F_15 ( & V_7 -> V_39 ) )
goto V_40;
return 0 ;
V_40:
F_16 ( V_7 -> V_34 ) ;
V_38:
for ( V_13 = 0 ; V_13 < V_7 -> V_16 ; V_13 ++ )
F_17 ( & V_7 -> V_32 [ V_13 ] ) ;
V_28:
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
if ( V_7 -> V_29 [ V_13 ] )
F_18 ( V_7 -> V_29 [ V_13 ] ) ;
if ( V_7 -> V_25 [ V_13 ] )
F_18 ( V_7 -> V_25 [ V_13 ] ) ;
}
F_19 ( V_7 -> V_22 ) ;
V_23:
F_20 ( V_7 -> V_15 ) ;
V_21:
F_2 ( L_5 ) ;
return - 1 ;
}
static void F_21 ( struct V_11 * V_7 )
{
int V_12 ;
F_22 ( V_7 -> V_34 == NULL ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_16 ; V_12 ++ ) {
F_17 ( & V_7 -> V_32 [ V_12 ] ) ;
( void ) F_18 ( V_7 -> V_29 [ V_12 ] ) ;
( void ) F_18 ( V_7 -> V_25 [ V_12 ] ) ;
V_7 -> V_29 [ V_12 ] = NULL ;
V_7 -> V_25 [ V_12 ] = NULL ;
}
( void ) F_23 ( & V_7 -> V_39 ) ;
( void ) F_16 ( V_7 -> V_34 ) ;
( void ) F_19 ( V_7 -> V_22 ) ;
F_20 ( V_7 -> V_15 ) ;
V_7 -> V_34 = NULL ;
V_7 -> V_22 = NULL ;
}
static int F_24 ( struct V_41 * V_42 )
{
struct V_11 * V_7 ;
struct V_43 V_44 ;
int V_45 , V_46 , V_47 = - V_48 ;
struct V_49 V_50 ;
int V_51 , V_52 = 0 ;
F_22 ( V_42 -> V_7 == NULL ) ;
V_7 = V_42 -> V_7 ;
V_42 -> V_53 = F_7 ( V_54 +
V_55 , V_20 ) ;
if ( ! V_42 -> V_53 )
goto V_56;
V_42 -> V_57 = V_42 -> V_53 ;
V_42 -> V_58 = V_42 -> V_53 + V_54 ;
V_42 -> V_59 = F_25 ( V_42 -> V_7 -> V_18 ,
( void * ) V_42 -> V_57 ,
V_54 , V_60 ) ;
V_42 -> V_61 = F_25 ( V_42 -> V_7 -> V_18 ,
( void * ) V_42 -> V_58 ,
V_55 , V_62 ) ;
V_45 = F_26 ( V_7 -> V_18 , V_42 -> V_59 ) ;
V_46 = F_26 ( V_7 -> V_18 , V_42 -> V_61 ) ;
if ( V_45 || V_46 ) {
if ( V_45 )
V_42 -> V_59 = 0 ;
if ( V_46 )
V_42 -> V_61 = 0 ;
goto V_56;
}
V_42 -> V_63 = F_7 ( sizeof( struct V_64 ) +
( sizeof( V_65 ) * ( V_66 + 1 ) ) ,
V_20 ) ;
if ( ! V_42 -> V_63 )
goto V_56;
V_42 -> V_63 -> V_67 = ( V_65 * ) ( V_42 -> V_63 + 1 ) ;
V_50 . V_68 = V_69 ;
V_50 . V_70 = V_66 + 1 ;
V_50 . V_71 = V_72 * 2 ;
V_50 . V_73 = V_72 ;
V_50 . V_74 = 0 ;
V_50 . V_75 = NULL ;
V_50 . V_76 = ( V_35 |
V_36 |
V_37 ) ;
V_42 -> V_77 = F_27 ( V_7 -> V_22 , & V_50 ) ;
if ( F_9 ( V_42 -> V_77 ) ) {
V_47 = F_28 ( V_42 -> V_77 ) ;
V_42 -> V_77 = NULL ;
goto V_56;
}
memset ( & V_44 , 0 , sizeof V_44 ) ;
F_29 ( & V_78 . V_79 ) ;
for ( V_51 = 0 ; V_51 < V_7 -> V_16 ; V_51 ++ )
if ( V_7 -> V_80 [ V_51 ] <
V_7 -> V_80 [ V_52 ] )
V_52 = V_51 ;
V_7 -> V_80 [ V_52 ] ++ ;
F_30 ( & V_78 . V_79 ) ;
F_2 ( L_6 , V_52 , V_42 ) ;
V_44 . V_39 = F_3 ;
V_44 . V_81 = ( void * ) V_42 ;
V_44 . V_82 = V_7 -> V_29 [ V_52 ] ;
V_44 . V_83 = V_7 -> V_25 [ V_52 ] ;
V_44 . V_84 . V_85 = V_86 ;
V_44 . V_84 . V_87 = V_88 ;
V_44 . V_84 . V_89 = 2 ;
V_44 . V_84 . V_90 = 1 ;
V_44 . V_91 = V_92 ;
V_44 . V_93 = V_94 ;
V_47 = F_31 ( V_42 -> V_95 , V_7 -> V_22 , & V_44 ) ;
if ( V_47 )
goto V_56;
V_42 -> V_96 = V_42 -> V_95 -> V_96 ;
F_2 ( L_7 ,
V_42 , V_42 -> V_95 ,
V_42 -> V_77 , V_42 -> V_95 -> V_96 ) ;
return V_47 ;
V_56:
F_2 ( L_8 , V_47 ) ;
return V_47 ;
}
static int F_32 ( struct V_41 * V_42 , int V_97 )
{
int V_24 ;
F_22 ( V_42 == NULL ) ;
F_2 ( L_9 ,
V_42 , V_42 -> V_95 ,
V_42 -> V_77 , V_42 -> V_96 ) ;
if ( V_42 -> V_77 != NULL )
F_33 ( V_42 -> V_77 ) ;
if ( V_42 -> V_96 != NULL ) {
V_24 = ( (struct V_14 * ) V_42 -> V_96 -> V_83 -> V_98 ) -> V_24 ;
V_42 -> V_7 -> V_80 [ V_24 ] -- ;
F_34 ( V_42 -> V_95 ) ;
}
if ( V_42 -> V_95 != NULL && V_97 )
F_35 ( V_42 -> V_95 ) ;
V_42 -> V_77 = NULL ;
V_42 -> V_96 = NULL ;
V_42 -> V_95 = NULL ;
F_20 ( V_42 -> V_63 ) ;
if ( V_42 -> V_53 ) {
if ( V_42 -> V_59 )
F_36 ( V_42 -> V_7 -> V_18 ,
V_42 -> V_59 ,
V_54 , V_60 ) ;
if ( V_42 -> V_61 )
F_36 ( V_42 -> V_7 -> V_18 ,
V_42 -> V_61 ,
V_55 , V_62 ) ;
F_20 ( V_42 -> V_53 ) ;
}
return 0 ;
}
static
struct V_11 * F_37 ( struct V_99 * V_95 )
{
struct V_11 * V_7 ;
F_29 ( & V_78 . V_100 ) ;
F_38 (device, &ig.device_list, ig_list)
if ( V_7 -> V_18 -> V_101 == V_95 -> V_7 -> V_101 )
goto V_102;
V_7 = F_39 ( sizeof *V_7 , V_20 ) ;
if ( V_7 == NULL )
goto V_103;
V_7 -> V_18 = V_95 -> V_7 ;
if ( F_5 ( V_7 ) ) {
F_20 ( V_7 ) ;
V_7 = NULL ;
goto V_103;
}
F_40 ( & V_7 -> V_104 , & V_78 . V_105 ) ;
V_102:
V_7 -> V_106 ++ ;
V_103:
F_30 ( & V_78 . V_100 ) ;
return V_7 ;
}
static void F_41 ( struct V_11 * V_7 )
{
F_29 ( & V_78 . V_100 ) ;
V_7 -> V_106 -- ;
F_2 ( L_10 , V_7 , V_7 -> V_106 ) ;
if ( ! V_7 -> V_106 ) {
F_21 ( V_7 ) ;
F_42 ( & V_7 -> V_104 ) ;
F_20 ( V_7 ) ;
}
F_30 ( & V_78 . V_100 ) ;
}
static int F_43 ( struct V_41 * V_42 ,
enum V_107 V_108 ,
enum V_107 V_109 )
{
int V_47 ;
F_44 ( & V_42 -> V_110 ) ;
if ( ( V_47 = ( V_42 -> V_111 == V_108 ) ) )
V_42 -> V_111 = V_109 ;
F_45 ( & V_42 -> V_110 ) ;
return V_47 ;
}
static void F_46 ( struct V_41 * V_42 , int V_97 )
{
struct V_11 * V_7 = V_42 -> V_7 ;
F_22 ( V_42 -> V_111 != V_112 ) ;
F_29 ( & V_78 . V_79 ) ;
F_42 ( & V_42 -> V_113 ) ;
F_30 ( & V_78 . V_79 ) ;
F_47 ( V_42 ) ;
F_32 ( V_42 , V_97 ) ;
V_42 -> V_7 = NULL ;
if ( V_7 != NULL )
F_41 ( V_7 ) ;
F_48 ( V_42 -> V_114 ) ;
}
void F_49 ( struct V_41 * V_42 )
{
F_50 ( & V_42 -> V_106 ) ;
}
int F_51 ( struct V_41 * V_42 , int V_97 )
{
if ( F_52 ( & V_42 -> V_106 ) ) {
F_46 ( V_42 , V_97 ) ;
return 1 ;
}
return 0 ;
}
void F_53 ( struct V_41 * V_42 )
{
int V_115 = 0 ;
F_43 ( V_42 , V_116 , V_117 ) ;
V_115 = F_54 ( V_42 -> V_95 ) ;
if ( V_115 )
F_2 ( L_11 ,
V_42 , V_115 ) ;
F_55 ( V_42 -> V_118 ,
V_42 -> V_111 == V_112 ) ;
F_51 ( V_42 , 1 ) ;
}
static int F_56 ( struct V_99 * V_95 )
{
struct V_41 * V_42 ;
V_42 = (struct V_41 * ) V_95 -> V_3 ;
V_42 -> V_111 = V_112 ;
F_57 ( & V_42 -> V_118 ) ;
return F_51 ( V_42 , 0 ) ;
}
static int F_58 ( struct V_99 * V_95 )
{
struct V_11 * V_7 ;
struct V_41 * V_42 ;
int V_47 ;
V_7 = F_37 ( V_95 ) ;
if ( ! V_7 ) {
F_2 ( L_12 ) ;
return F_56 ( V_95 ) ;
}
V_42 = (struct V_41 * ) V_95 -> V_3 ;
V_42 -> V_7 = V_7 ;
V_47 = F_59 ( V_95 , 1000 ) ;
if ( V_47 ) {
F_2 ( L_13 , V_47 ) ;
return F_56 ( V_95 ) ;
}
return 0 ;
}
static int F_60 ( struct V_99 * V_95 )
{
struct V_119 V_120 ;
int V_47 ;
V_47 = F_24 ( (struct V_41 * ) V_95 -> V_3 ) ;
if ( V_47 )
goto V_121;
memset ( & V_120 , 0 , sizeof V_120 ) ;
V_120 . V_122 = 4 ;
V_120 . V_123 = 1 ;
V_120 . V_124 = 7 ;
V_120 . V_125 = 6 ;
V_47 = F_61 ( V_95 , & V_120 ) ;
if ( V_47 ) {
F_2 ( L_14 , V_47 ) ;
goto V_121;
}
return 0 ;
V_121:
return F_56 ( V_95 ) ;
}
static void F_62 ( struct V_99 * V_95 )
{
struct V_41 * V_42 ;
V_42 = (struct V_41 * ) V_95 -> V_3 ;
V_42 -> V_111 = V_116 ;
F_57 ( & V_42 -> V_118 ) ;
}
static int F_63 ( struct V_99 * V_95 )
{
struct V_41 * V_42 ;
int V_47 ;
V_42 = (struct V_41 * ) V_95 -> V_3 ;
if ( F_43 ( V_42 , V_116 ,
V_117 ) )
F_64 ( V_42 -> V_41 -> V_126 ,
V_127 ) ;
if ( V_42 -> V_128 == 0 &&
( F_65 ( & V_42 -> V_129 ) == 0 ) ) {
V_42 -> V_111 = V_112 ;
F_57 ( & V_42 -> V_118 ) ;
}
V_47 = F_51 ( V_42 , 0 ) ;
return V_47 ;
}
static int F_66 ( struct V_99 * V_95 , struct V_130 * V_4 )
{
int V_47 = 0 ;
F_2 ( L_15 ,
V_4 -> V_4 , V_4 -> V_131 , V_95 -> V_3 , V_95 ) ;
switch ( V_4 -> V_4 ) {
case V_132 :
V_47 = F_58 ( V_95 ) ;
break;
case V_133 :
V_47 = F_60 ( V_95 ) ;
break;
case V_134 :
F_62 ( V_95 ) ;
break;
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
V_47 = F_56 ( V_95 ) ;
break;
case V_140 :
case V_141 :
case V_142 :
V_47 = F_63 ( V_95 ) ;
break;
default:
F_2 ( L_16 , V_4 -> V_4 ) ;
break;
}
return V_47 ;
}
void F_67 ( struct V_41 * V_42 )
{
V_42 -> V_111 = V_143 ;
F_68 ( & V_42 -> V_118 ) ;
V_42 -> V_128 = 0 ;
F_69 ( & V_42 -> V_129 , 0 ) ;
F_69 ( & V_42 -> V_106 , 1 ) ;
F_70 ( & V_42 -> V_113 ) ;
F_71 ( & V_42 -> V_110 ) ;
}
int F_72 ( struct V_41 * V_42 ,
struct V_144 * V_145 ,
struct V_144 * V_146 ,
int V_147 )
{
struct V_148 * V_149 , * V_150 ;
int V_115 = 0 ;
sprintf ( V_42 -> V_8 , L_17 ,
& V_146 -> V_151 . V_152 , V_146 -> V_153 ) ;
V_42 -> V_7 = NULL ;
F_2 ( L_18 ,
& V_146 -> V_151 , V_146 -> V_153 ) ;
V_42 -> V_111 = V_154 ;
F_49 ( V_42 ) ;
V_42 -> V_95 = F_73 ( F_66 ,
( void * ) V_42 ,
V_155 , V_94 ) ;
if ( F_9 ( V_42 -> V_95 ) ) {
V_115 = F_28 ( V_42 -> V_95 ) ;
F_2 ( L_19 , V_115 ) ;
goto V_156;
}
V_149 = (struct V_148 * ) V_145 ;
V_150 = (struct V_148 * ) V_146 ;
V_115 = F_74 ( V_42 -> V_95 , V_149 , V_150 , 1000 ) ;
if ( V_115 ) {
F_2 ( L_20 , V_115 ) ;
goto V_157;
}
if ( ! V_147 ) {
F_55 ( V_42 -> V_118 ,
( V_42 -> V_111 != V_154 ) ) ;
if ( V_42 -> V_111 != V_116 ) {
V_115 = - V_158 ;
goto V_159;
}
}
F_29 ( & V_78 . V_79 ) ;
F_40 ( & V_42 -> V_113 , & V_78 . V_160 ) ;
F_30 ( & V_78 . V_79 ) ;
return 0 ;
V_156:
V_42 -> V_95 = NULL ;
V_157:
V_42 -> V_111 = V_112 ;
F_51 ( V_42 , 1 ) ;
V_159:
F_51 ( V_42 , 1 ) ;
return V_115 ;
}
int F_75 ( struct V_41 * V_42 ,
struct V_64 * V_63 ,
struct V_161 * V_162 )
{
struct V_163 * V_164 ;
V_65 V_165 ;
V_65 * V_166 ;
int V_131 ;
V_166 = V_63 -> V_67 ;
V_165 = V_166 [ 0 ] ;
V_164 = F_76 ( V_42 -> V_77 ,
V_166 ,
V_63 -> V_167 ,
V_165 ) ;
if ( F_9 ( V_164 ) ) {
V_131 = ( int ) F_28 ( V_164 ) ;
F_2 ( L_21 , V_131 ) ;
return V_131 ;
}
V_162 -> V_168 = V_164 -> V_169 -> V_168 ;
V_162 -> V_170 = V_164 -> V_169 -> V_170 ;
V_162 -> V_171 = V_63 -> V_167 * V_172 ;
V_162 -> V_173 = V_165 ;
V_162 -> V_174 = 1 ;
V_162 -> V_175 = ( void * ) V_164 ;
V_162 -> V_173 += V_63 -> V_176 ;
V_162 -> V_171 = V_63 -> V_177 ;
F_77 ( L_22
L_23
L_24 ,
V_63 , V_63 -> V_167 ,
( unsigned long ) V_63 -> V_67 [ 0 ] ,
( unsigned long ) V_63 -> V_177 ,
( unsigned int ) V_162 -> V_168 , V_162 -> V_175 ,
( unsigned long ) V_162 -> V_173 , ( unsigned long ) V_162 -> V_171 ) ;
return 0 ;
}
void F_78 ( struct V_161 * V_178 )
{
int V_47 ;
F_77 ( L_25 , V_178 -> V_175 ) ;
V_47 = F_79 ( (struct V_163 * ) V_178 -> V_175 ) ;
if ( V_47 )
F_2 ( L_26 , V_47 ) ;
V_178 -> V_175 = NULL ;
}
int F_80 ( struct V_41 * V_42 )
{
struct V_179 V_180 , * V_181 ;
struct V_182 V_183 ;
int V_184 ;
V_183 . V_185 = V_42 -> V_61 ;
V_183 . V_167 = V_55 ;
V_183 . V_168 = V_42 -> V_7 -> V_34 -> V_168 ;
V_180 . V_186 = ( unsigned long ) V_42 -> V_58 ;
V_180 . V_187 = & V_183 ;
V_180 . V_188 = 1 ;
V_180 . V_189 = NULL ;
V_42 -> V_128 ++ ;
V_184 = F_81 ( V_42 -> V_96 , & V_180 , & V_181 ) ;
if ( V_184 ) {
F_2 ( L_27 , V_184 ) ;
V_42 -> V_128 -- ;
}
return V_184 ;
}
int F_82 ( struct V_41 * V_42 , int V_190 )
{
struct V_179 * V_180 , * V_181 ;
int V_12 , V_184 ;
unsigned int V_191 = V_42 -> V_192 ;
struct V_193 * V_194 ;
for ( V_180 = V_42 -> V_180 , V_12 = 0 ; V_12 < V_190 ; V_12 ++ , V_180 ++ ) {
V_194 = & V_42 -> V_195 [ V_191 ] ;
V_180 -> V_186 = ( unsigned long ) V_194 ;
V_180 -> V_187 = & V_194 -> V_196 ;
V_180 -> V_188 = 1 ;
V_180 -> V_189 = V_180 + 1 ;
V_191 = ( V_191 + 1 ) & ( V_88 - 1 ) ;
}
V_180 -- ;
V_180 -> V_189 = NULL ;
V_42 -> V_128 += V_190 ;
V_184 = F_81 ( V_42 -> V_96 , V_42 -> V_180 , & V_181 ) ;
if ( V_184 ) {
F_2 ( L_27 , V_184 ) ;
V_42 -> V_128 -= V_190 ;
} else
V_42 -> V_192 = V_191 ;
return V_184 ;
}
int F_83 ( struct V_41 * V_42 , struct V_197 * V_198 )
{
int V_184 ;
struct V_199 V_200 , * V_201 ;
F_84 ( V_42 -> V_7 -> V_18 ,
V_198 -> V_202 , V_203 , V_60 ) ;
V_200 . V_189 = NULL ;
V_200 . V_186 = ( unsigned long ) V_198 ;
V_200 . V_187 = V_198 -> V_204 ;
V_200 . V_188 = V_198 -> V_188 ;
V_200 . V_205 = V_206 ;
V_200 . V_207 = V_208 ;
F_50 ( & V_42 -> V_129 ) ;
V_184 = F_85 ( V_42 -> V_96 , & V_200 , & V_201 ) ;
if ( V_184 ) {
F_2 ( L_28 , V_184 ) ;
F_86 ( & V_42 -> V_129 ) ;
}
return V_184 ;
}
static void F_87 ( struct V_197 * V_209 ,
struct V_41 * V_42 )
{
if ( V_209 && V_209 -> type == V_210 )
F_88 ( V_78 . V_211 , V_209 ) ;
if ( V_42 -> V_128 == 0 &&
F_65 ( & V_42 -> V_129 ) == 0 ) {
if ( F_43 ( V_42 , V_116 ,
V_117 ) )
F_64 ( V_42 -> V_41 -> V_126 ,
V_127 ) ;
V_42 -> V_111 = V_112 ;
F_57 ( & V_42 -> V_118 ) ;
}
}
static int F_89 ( struct V_11 * V_7 , int V_24 )
{
struct V_212 * V_213 = V_7 -> V_29 [ V_24 ] ;
struct V_214 V_215 ;
struct V_197 * V_198 ;
struct V_41 * V_42 ;
int V_216 = 0 ;
while ( F_90 ( V_213 , 1 , & V_215 ) == 1 ) {
V_198 = (struct V_197 * ) ( unsigned long ) V_215 . V_186 ;
V_42 = V_215 . V_96 -> V_81 ;
if ( V_215 . V_131 == V_217 ) {
if ( V_215 . V_205 == V_218 )
F_91 ( V_198 , V_42 ) ;
else
F_2 ( L_29 ,
V_218 , V_215 . V_205 ) ;
} else {
F_2 ( L_30 ,
V_215 . V_186 , V_215 . V_131 , V_215 . V_219 ) ;
F_86 ( & V_42 -> V_129 ) ;
F_87 ( V_198 , V_42 ) ;
}
V_216 ++ ;
}
return V_216 ;
}
static void V_33 ( unsigned long V_220 )
{
struct V_14 * V_15 = (struct V_14 * ) V_220 ;
struct V_11 * V_7 = V_15 -> V_7 ;
int V_24 = V_15 -> V_24 ;
struct V_212 * V_213 = V_7 -> V_25 [ V_24 ] ;
struct V_214 V_215 ;
struct V_193 * V_209 ;
unsigned long V_221 ;
struct V_41 * V_42 ;
int V_216 , V_222 ;
V_216 = V_222 = 0 ;
while ( F_90 ( V_213 , 1 , & V_215 ) == 1 ) {
V_209 = (struct V_193 * ) ( unsigned long ) V_215 . V_186 ;
F_22 ( V_209 == NULL ) ;
V_42 = V_215 . V_96 -> V_81 ;
if ( V_215 . V_131 == V_217 ) {
if ( V_215 . V_205 == V_223 ) {
V_221 = ( unsigned long ) V_215 . V_224 ;
F_92 ( V_209 , V_221 , V_42 ) ;
} else
F_2 ( L_29 ,
V_223 , V_215 . V_205 ) ;
} else {
if ( V_215 . V_131 != V_225 )
F_2 ( L_31 ,
V_215 . V_186 , V_215 . V_131 , V_215 . V_219 ) ;
V_42 -> V_128 -- ;
F_87 ( NULL , V_42 ) ;
}
V_222 ++ ;
if ( ! ( V_222 & 63 ) )
V_216 += F_89 ( V_7 , V_24 ) ;
}
F_11 ( V_213 , V_31 ) ;
V_216 += F_89 ( V_7 , V_24 ) ;
F_77 ( L_32 , V_222 , V_216 ) ;
}
static void V_26 ( struct V_212 * V_213 , void * V_98 )
{
struct V_14 * V_15 = (struct V_14 * ) V_98 ;
struct V_11 * V_7 = V_15 -> V_7 ;
int V_24 = V_15 -> V_24 ;
F_93 ( & V_7 -> V_32 [ V_24 ] ) ;
}

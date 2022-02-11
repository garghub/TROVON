static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_3 ( V_4 -> V_10 ) ;
if ( V_7 == NULL || V_7 -> V_11 == NULL )
return;
V_9 = V_7 -> V_12 ;
if ( V_9 == NULL )
return;
if ( V_7 -> V_11 -> V_13 & V_14 )
F_4 ( V_9 ,
V_15 ) ;
else
F_4 ( V_9 ,
V_16 |
V_17 |
V_18 ) ;
}
static void F_5 ( struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
F_7 ( & V_21 -> V_5 ) ;
}
static int F_8 ( struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_22 * V_23 = V_21 -> V_10 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_24 = 0 ;
F_9 ( V_20 ) ;
V_24 = F_10 ( V_23 ) ;
if ( V_24 != 0 ) {
F_11 ( V_20 , L_1 , V_24 ) ;
return V_24 ;
}
F_12 ( V_20 ) ;
V_7 = F_3 ( V_23 ) ;
V_9 = V_7 -> V_12 ;
if ( ! V_9 -> V_25 )
F_13 ( V_20 ) ;
return V_24 ;
}
static int F_14 ( struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_22 * V_23 = V_21 -> V_10 ;
int V_24 ;
F_15 ( V_20 ) ;
F_16 ( & V_21 -> V_5 ) ;
V_24 = F_17 ( V_23 ) ;
if ( V_24 != 0 )
F_11 ( V_20 , L_2 , V_24 ) ;
return V_24 ;
}
static void * F_18 ( struct V_26 * V_27 , T_1 V_28 ,
int V_29 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
V_31 = & V_27 -> V_27 . V_34 ;
V_31 -> V_35 += V_28 ;
V_33 = (struct V_32 * ) ( ( void * ) V_31 +
V_31 -> V_36 + V_31 -> V_37 ) ;
V_33 -> V_38 = V_28 ;
V_33 -> type = V_29 ;
V_33 -> V_39 = sizeof( struct V_32 ) ;
V_31 -> V_37 += V_28 ;
return V_33 ;
}
static void F_19 ( void * V_40 )
{
struct V_41 * V_42 = (struct V_41 * ) V_40 ;
struct V_43 * V_44 = (struct V_43 * )
( unsigned long ) V_42 -> V_45 . V_46 . V_47 ;
F_20 ( V_42 ) ;
if ( V_44 )
F_21 ( V_44 ) ;
}
static T_1 F_22 ( struct V_48 * V_48 , T_1 V_49 , T_1 V_50 ,
struct V_51 * V_52 )
{
int V_53 = 0 ;
V_48 += ( V_49 >> V_54 ) ;
V_49 &= ~ V_55 ;
while ( V_50 > 0 ) {
unsigned long V_56 ;
V_56 = V_57 - V_49 ;
if ( V_56 > V_50 )
V_56 = V_50 ;
V_52 [ V_53 ] . V_58 = F_23 ( V_48 ) ;
V_52 [ V_53 ] . V_49 = V_49 ;
V_52 [ V_53 ] . V_50 = V_56 ;
V_49 += V_56 ;
V_50 -= V_56 ;
if ( V_49 == V_57 && V_50 ) {
V_48 ++ ;
V_49 = 0 ;
V_53 ++ ;
}
}
return V_53 + 1 ;
}
static T_1 F_24 ( void * V_59 , T_1 V_50 , struct V_43 * V_44 ,
struct V_51 * V_52 )
{
T_1 V_60 = 0 ;
char * V_61 = V_44 -> V_61 ;
int V_62 = F_25 ( V_44 ) -> V_63 ;
int V_64 ;
if ( V_59 != NULL )
V_60 += F_22 ( F_26 ( V_59 ) ,
F_27 ( V_59 ) ,
V_50 , & V_52 [ V_60 ] ) ;
V_60 += F_22 ( F_26 ( V_61 ) ,
F_27 ( V_61 ) ,
F_28 ( V_44 ) , & V_52 [ V_60 ] ) ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
T_2 * V_65 = F_25 ( V_44 ) -> V_62 + V_64 ;
V_60 += F_22 ( F_29 ( V_65 ) ,
V_65 -> V_66 ,
F_30 ( V_65 ) , & V_52 [ V_60 ] ) ;
}
return V_60 ;
}
static int F_31 ( struct V_43 * V_44 )
{
int V_64 , V_62 = F_25 ( V_44 ) -> V_63 ;
int V_67 = 0 ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
T_2 * V_65 = F_25 ( V_44 ) -> V_62 + V_64 ;
unsigned long V_38 = F_30 ( V_65 ) ;
unsigned long V_49 = V_65 -> V_66 ;
V_49 &= ~ V_55 ;
V_67 += F_32 ( V_49 + V_38 ) ;
}
return V_67 ;
}
static int F_33 ( struct V_43 * V_44 )
{
char * V_61 = V_44 -> V_61 ;
unsigned int V_49 = F_27 ( V_61 ) ;
unsigned int V_50 = F_28 ( V_44 ) ;
int V_68 ;
int V_69 ;
V_68 = F_34 ( V_49 + V_50 , V_57 ) ;
V_69 = F_31 ( V_44 ) ;
return V_68 + V_69 ;
}
static T_1 F_35 ( struct V_43 * V_44 , T_1 * V_70 )
{
T_1 V_71 = V_72 ;
if ( ( F_36 ( V_44 ) -> V_73 != F_37 ( V_74 ) ) &&
( F_36 ( V_44 ) -> V_73 != F_37 ( V_75 ) ) ) {
goto V_76;
}
* V_70 = F_38 ( V_44 ) ;
if ( ( F_36 ( V_44 ) -> V_73 == F_37 ( V_74 ) ) ) {
struct V_77 * V_77 = F_39 ( V_44 ) ;
if ( V_77 -> V_78 == V_79 )
V_71 = V_80 ;
else if ( V_77 -> V_78 == V_81 )
V_71 = V_82 ;
} else {
if ( F_40 ( V_44 ) -> V_83 == V_79 )
V_71 = V_84 ;
else if ( F_40 ( V_44 ) -> V_83 == V_81 )
V_71 = V_85 ;
}
V_76:
return V_71 ;
}
static int F_41 ( struct V_43 * V_44 , struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_41 * V_42 ;
int V_24 ;
unsigned int V_86 ;
struct V_26 * V_87 ;
struct V_30 * V_31 ;
T_1 V_88 ;
bool V_89 ;
struct V_32 * V_33 ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
int V_94 ;
T_1 V_95 ;
V_86 = F_33 ( V_44 ) + 2 ;
if ( V_86 > V_96 ) {
F_11 ( V_20 , L_3 , V_44 -> V_50 ) ;
F_42 ( V_44 ) ;
V_20 -> V_97 . V_98 ++ ;
return V_99 ;
}
V_42 = F_43 ( sizeof( struct V_41 ) +
( V_86 * sizeof( struct V_51 ) ) +
sizeof( struct V_26 ) +
V_100 +
V_101 +
V_102 , V_103 ) ;
if ( ! V_42 ) {
F_11 ( V_20 , L_4 ) ;
F_42 ( V_44 ) ;
V_20 -> V_97 . V_98 ++ ;
return V_99 ;
}
V_42 -> V_104 = V_44 -> V_104 ;
V_42 -> V_105 = true ;
V_42 -> V_106 = V_44 -> V_50 ;
V_42 -> V_87 = (struct V_26 * ) ( ( unsigned long ) V_42 +
sizeof( struct V_41 ) +
( V_86 * sizeof( struct V_51 ) ) ) ;
V_42 -> V_45 . V_46 . V_107 = F_19 ;
V_42 -> V_45 . V_46 . V_108 = V_42 ;
V_42 -> V_45 . V_46 . V_47 = ( unsigned long ) V_44 ;
V_89 = V_42 -> V_104 & V_109 ;
V_87 = V_42 -> V_87 ;
V_87 -> V_110 = V_111 ;
V_87 -> V_112 = V_42 -> V_106 ;
V_31 = & V_87 -> V_27 . V_34 ;
V_31 -> V_35 = sizeof( struct V_30 ) ;
V_31 -> V_113 = V_42 -> V_106 ;
V_31 -> V_36 = sizeof( struct V_30 ) ;
V_88 = F_44 ( struct V_30 ) ;
if ( V_89 ) {
struct V_114 * V_115 ;
V_88 += V_100 ;
V_33 = F_18 ( V_87 , V_100 ,
V_116 ) ;
V_115 = (struct V_114 * ) ( ( void * ) V_33 +
V_33 -> V_39 ) ;
V_115 -> V_117 = V_42 -> V_104 & V_118 ;
V_115 -> V_119 = ( V_42 -> V_104 & V_120 ) >>
V_121 ;
}
V_95 = F_35 ( V_44 , & V_94 ) ;
if ( V_95 == V_72 )
goto V_122;
if ( F_45 ( V_44 ) )
goto V_123;
if ( ( V_44 -> V_124 == V_125 ) ||
( V_44 -> V_124 == V_126 ) )
goto V_122;
V_88 += V_101 ;
V_33 = F_18 ( V_87 , V_101 ,
V_127 ) ;
V_91 = (struct V_90 * ) ( ( void * ) V_33 +
V_33 -> V_39 ) ;
if ( V_95 & ( V_128 << 16 ) )
V_91 -> V_129 . V_130 = 1 ;
else
V_91 -> V_129 . V_131 = 1 ;
if ( V_95 & V_132 ) {
V_91 -> V_129 . V_133 = 1 ;
V_91 -> V_129 . V_134 = V_94 ;
} else if ( V_95 & V_135 ) {
struct V_136 * V_137 ;
T_3 V_138 ;
V_24 = F_46 ( V_44 , 0 ) ;
if ( V_24 )
goto V_139;
V_137 = F_47 ( V_44 ) ;
V_138 = F_48 ( V_137 -> V_50 ) ;
V_137 -> V_140 = 0 ;
V_137 -> V_140 = F_49 ( F_39 ( V_44 ) -> V_141 ,
F_39 ( V_44 ) -> V_142 ,
V_138 , V_81 ,
F_50 ( V_137 , V_138 , 0 ) ) ;
if ( V_137 -> V_140 == 0 )
V_137 -> V_140 = V_143 ;
V_91 -> V_129 . V_144 = 0 ;
}
goto V_122;
V_123:
V_88 += V_102 ;
V_33 = F_18 ( V_87 , V_102 ,
V_145 ) ;
V_93 = (struct V_92 * ) ( ( void * ) V_33 +
V_33 -> V_39 ) ;
V_93 -> V_146 . type = V_147 ;
if ( V_95 & ( V_128 << 16 ) ) {
V_93 -> V_146 . V_148 =
V_149 ;
F_39 ( V_44 ) -> V_150 = 0 ;
F_39 ( V_44 ) -> V_140 = 0 ;
F_51 ( V_44 ) -> V_140 =
~ F_49 ( F_39 ( V_44 ) -> V_141 ,
F_39 ( V_44 ) -> V_142 , 0 , V_79 , 0 ) ;
} else {
V_93 -> V_146 . V_148 =
V_151 ;
F_40 ( V_44 ) -> V_152 = 0 ;
F_51 ( V_44 ) -> V_140 =
~ F_52 ( & F_40 ( V_44 ) -> V_141 ,
& F_40 ( V_44 ) -> V_142 , 0 , V_79 , 0 ) ;
}
V_93 -> V_146 . V_134 = V_94 ;
V_93 -> V_146 . V_153 = F_25 ( V_44 ) -> V_154 ;
V_122:
V_87 -> V_112 += V_88 ;
V_42 -> V_155 = F_24 ( V_87 , V_88 ,
V_44 , & V_42 -> V_156 [ 0 ] ) ;
V_24 = F_53 ( V_21 -> V_10 , V_42 ) ;
V_139:
if ( V_24 == 0 ) {
V_20 -> V_97 . V_157 += V_44 -> V_50 ;
V_20 -> V_97 . V_158 ++ ;
} else {
F_20 ( V_42 ) ;
if ( V_24 != - V_159 ) {
F_21 ( V_44 ) ;
V_20 -> V_97 . V_98 ++ ;
}
}
return ( V_24 == - V_159 ) ? V_160 : V_99 ;
}
void F_54 ( struct V_22 * V_23 ,
unsigned int V_161 )
{
struct V_19 * V_20 ;
struct V_3 * V_162 ;
struct V_6 * V_19 ;
struct V_8 * V_9 ;
V_19 = F_3 ( V_23 ) ;
V_9 = V_19 -> V_12 ;
V_9 -> V_25 = V_161 != 1 ;
V_20 = V_19 -> V_11 ;
if ( ! V_20 || V_20 -> V_163 != V_164 )
return;
V_162 = F_6 ( V_20 ) ;
if ( V_161 == 1 ) {
F_55 ( & V_162 -> V_165 , 0 ) ;
F_55 ( & V_162 -> V_165 , F_56 ( 20 ) ) ;
} else {
F_55 ( & V_162 -> V_165 , 0 ) ;
}
}
int F_57 ( struct V_22 * V_23 ,
struct V_41 * V_42 ,
struct V_90 * V_91 )
{
struct V_19 * V_20 ;
struct V_43 * V_44 ;
V_20 = ( (struct V_6 * ) F_3 ( V_23 ) ) -> V_11 ;
if ( ! V_20 || V_20 -> V_163 != V_164 ) {
V_42 -> V_161 = V_166 ;
return 0 ;
}
V_44 = F_58 ( V_20 , V_42 -> V_106 ) ;
if ( F_59 ( ! V_44 ) ) {
++ V_20 -> V_97 . V_167 ;
V_42 -> V_161 = V_166 ;
return 0 ;
}
memcpy ( F_60 ( V_44 , V_42 -> V_106 ) , V_42 -> V_61 ,
V_42 -> V_106 ) ;
V_44 -> V_78 = F_61 ( V_44 , V_20 ) ;
if ( V_91 ) {
if ( V_91 -> V_168 . V_169 )
V_44 -> V_124 = V_126 ;
else
V_44 -> V_124 = V_125 ;
}
if ( V_42 -> V_104 & V_109 )
F_62 ( V_44 , F_37 ( V_170 ) ,
V_42 -> V_104 ) ;
V_20 -> V_97 . V_171 ++ ;
V_20 -> V_97 . V_172 += V_42 -> V_106 ;
F_63 ( V_44 ) ;
return 0 ;
}
static void F_64 ( struct V_19 * V_20 ,
struct V_173 * V_174 )
{
F_65 ( V_174 -> V_175 , V_176 , sizeof( V_174 -> V_175 ) ) ;
F_65 ( V_174 -> V_177 , L_5 , sizeof( V_174 -> V_177 ) ) ;
}
static int F_66 ( struct V_19 * V_11 , int V_178 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_179 = V_4 -> V_10 ;
struct V_6 * V_7 = F_3 ( V_179 ) ;
struct V_180 V_181 ;
int V_182 = V_183 ;
if ( V_7 == NULL || V_7 -> V_184 )
return - V_185 ;
if ( V_7 -> V_186 >= V_187 )
V_182 = V_188 ;
if ( V_178 < 68 || V_178 > V_182 )
return - V_189 ;
V_7 -> V_190 = true ;
F_16 ( & V_4 -> V_5 ) ;
F_15 ( V_11 ) ;
F_67 ( V_179 ) ;
V_11 -> V_178 = V_178 ;
V_4 -> V_10 = V_179 ;
F_68 ( V_179 , V_11 ) ;
V_181 . V_191 = V_191 ;
F_69 ( V_179 , & V_181 ) ;
F_70 ( V_11 ) ;
return 0 ;
}
static int F_71 ( struct V_19 * V_11 , void * V_192 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_179 = V_4 -> V_10 ;
struct V_193 * V_194 = V_192 ;
char V_195 [ V_196 ] ;
unsigned char V_197 ;
int V_198 ;
memcpy ( V_195 , V_11 -> V_199 , V_196 ) ;
V_197 = V_11 -> V_200 ;
V_198 = F_72 ( V_11 , V_192 ) ;
if ( V_198 != 0 )
return V_198 ;
V_198 = F_73 ( V_179 , V_194 -> V_201 ) ;
if ( V_198 != 0 ) {
memcpy ( V_11 -> V_199 , V_195 , V_196 ) ;
V_11 -> V_200 = V_197 ;
}
return V_198 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_162 ;
struct V_19 * V_20 ;
struct V_6 * V_19 ;
struct V_8 * V_9 ;
bool V_202 ;
F_75 () ;
V_162 = F_2 ( V_2 , struct V_3 , V_165 . V_5 ) ;
V_19 = F_3 ( V_162 -> V_10 ) ;
V_9 = V_19 -> V_12 ;
V_20 = V_19 -> V_11 ;
if ( V_9 -> V_25 ) {
F_9 ( V_20 ) ;
V_202 = false ;
} else {
F_13 ( V_20 ) ;
V_202 = true ;
}
F_76 () ;
if ( V_202 )
F_77 ( V_20 ) ;
}
static int F_78 ( struct V_22 * V_203 ,
const struct V_204 * V_205 )
{
struct V_19 * V_20 = NULL ;
struct V_3 * V_21 ;
struct V_180 V_181 ;
int V_24 ;
V_20 = F_79 ( sizeof( struct V_3 ) ) ;
if ( ! V_20 )
return - V_206 ;
F_9 ( V_20 ) ;
V_21 = F_6 ( V_20 ) ;
V_21 -> V_10 = V_203 ;
F_68 ( V_203 , V_20 ) ;
F_80 ( & V_21 -> V_165 , F_74 ) ;
F_81 ( & V_21 -> V_5 , F_1 ) ;
V_20 -> V_207 = & V_208 ;
V_20 -> V_209 = V_210 | V_211 | V_212 |
V_213 ;
V_20 -> V_214 = V_215 | V_211 | V_210 |
V_212 | V_213 ;
F_82 ( V_20 , & V_216 ) ;
F_83 ( V_20 , & V_203 -> V_217 ) ;
V_181 . V_191 = V_191 ;
V_24 = F_69 ( V_203 , & V_181 ) ;
if ( V_24 != 0 ) {
F_11 ( V_20 , L_6 , V_24 ) ;
F_84 ( V_20 ) ;
F_68 ( V_203 , NULL ) ;
return V_24 ;
}
memcpy ( V_20 -> V_199 , V_181 . V_218 , V_196 ) ;
V_24 = F_85 ( V_20 ) ;
if ( V_24 != 0 ) {
F_86 ( L_7 ) ;
F_67 ( V_203 ) ;
F_84 ( V_20 ) ;
} else {
F_55 ( & V_21 -> V_165 , 0 ) ;
}
return V_24 ;
}
static int F_87 ( struct V_22 * V_203 )
{
struct V_19 * V_20 ;
struct V_3 * V_162 ;
struct V_6 * V_19 ;
V_19 = F_3 ( V_203 ) ;
V_20 = V_19 -> V_11 ;
if ( V_20 == NULL ) {
F_88 ( & V_203 -> V_217 , L_8 ) ;
return 0 ;
}
V_19 -> V_190 = true ;
V_162 = F_6 ( V_20 ) ;
F_89 ( & V_162 -> V_165 ) ;
F_16 ( & V_162 -> V_5 ) ;
F_15 ( V_20 ) ;
F_90 ( V_20 ) ;
F_67 ( V_203 ) ;
F_84 ( V_20 ) ;
return 0 ;
}
static void T_4 F_91 ( void )
{
F_92 ( & V_219 ) ;
}
static int T_5 F_93 ( void )
{
if ( V_191 < V_220 ) {
V_191 = V_220 ;
F_94 ( L_9 ,
V_191 ) ;
}
return F_95 ( & V_219 ) ;
}

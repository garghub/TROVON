static inline unsigned int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 - ( V_2 -> V_4 - V_2 -> V_5 ) ) ;
}
static int F_2 ( struct V_6 * V_7 , unsigned int V_8 )
{
unsigned int V_9 ;
if ( V_8 > V_10 ) {
F_3 ( V_7 , L_1 ) ;
return - V_11 ;
}
V_9 = V_8 + V_12 + V_13 + V_14 ;
if ( V_9 < V_15 )
V_9 = V_15 ;
V_9 = ( V_9 + V_16 - 1 ) & ~ ( V_16 - 1 ) ;
return V_9 ;
}
static void F_4 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_21 * V_22 ;
unsigned int V_23 ;
V_22 = V_18 -> V_22 ;
for ( V_23 = 0 ; V_23 < V_18 -> V_24 ; V_23 ++ , V_22 ++ ) {
if ( V_22 -> V_25 )
V_20 -> V_26 ( V_22 ,
V_27 ) ;
if ( V_22 -> V_28 )
V_20 -> V_26 ( V_22 ,
V_29 ) ;
}
}
static void F_5 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_21 * V_22 ;
unsigned int V_23 ;
V_22 = V_18 -> V_22 ;
for ( V_23 = 0 ; V_23 < V_18 -> V_24 ; V_23 ++ , V_22 ++ ) {
if ( V_22 -> V_25 )
V_20 -> V_30 ( V_22 ,
V_27 ) ;
if ( V_22 -> V_28 )
V_20 -> V_30 ( V_22 ,
V_29 ) ;
}
}
static T_1 F_6 ( int V_31 , void * V_32 )
{
struct V_17 * V_18 = V_32 ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_21 * V_22 ;
unsigned int V_33 , V_34 ;
unsigned int V_35 ;
unsigned int V_23 ;
V_33 = F_7 ( V_18 , V_36 ) ;
if ( ! V_33 )
goto V_37;
F_8 ( L_2 ) ;
F_8 ( L_3 , V_33 ) ;
F_8 ( L_4 , F_7 ( V_18 , V_38 ) ) ;
F_8 ( L_5 , F_7 ( V_18 , V_39 ) ) ;
for ( V_23 = 0 ; V_23 < V_18 -> V_24 ; V_23 ++ ) {
if ( ! ( V_33 & ( 1 << V_23 ) ) )
continue;
V_22 = V_18 -> V_22 + V_23 ;
V_34 = F_9 ( V_22 , V_40 ) ;
F_8 ( L_6 , V_23 , V_34 ) ;
if ( F_10 ( V_34 , V_40 , V_41 ) ||
F_10 ( V_34 , V_40 , V_42 ) ) {
if ( F_11 ( & V_18 -> V_43 ) ) {
F_5 ( V_18 ) ;
F_12 ( & V_18 -> V_43 ) ;
}
}
if ( F_10 ( V_34 , V_40 , V_44 ) )
F_13 ( & V_18 -> V_45 ) ;
F_14 ( V_22 , V_40 , V_34 ) ;
}
if ( F_10 ( V_33 , V_36 , V_46 ) ) {
V_35 = F_7 ( V_18 , V_47 ) ;
if ( F_10 ( V_35 , V_47 , V_48 ) )
V_20 -> V_49 ( V_18 ) ;
if ( F_10 ( V_35 , V_47 , V_50 ) )
V_20 -> V_51 ( V_18 ) ;
}
F_8 ( L_3 , F_7 ( V_18 , V_36 ) ) ;
F_8 ( L_7 ) ;
V_37:
return V_52 ;
}
static enum V_53 F_15 ( struct V_54 * V_55 )
{
struct V_21 * V_22 = F_16 ( V_55 ,
struct V_21 ,
V_56 ) ;
struct V_1 * V_2 = V_22 -> V_25 ;
struct V_17 * V_18 = V_22 -> V_18 ;
unsigned long V_57 ;
F_8 ( L_8 ) ;
F_17 ( & V_2 -> V_58 , V_57 ) ;
if ( F_11 ( & V_18 -> V_43 ) ) {
F_5 ( V_18 ) ;
F_12 ( & V_18 -> V_43 ) ;
}
V_22 -> V_59 = 0 ;
F_18 ( & V_2 -> V_58 , V_57 ) ;
F_8 ( L_9 ) ;
return V_60 ;
}
static void F_19 ( struct V_17 * V_18 )
{
struct V_21 * V_22 ;
unsigned int V_23 ;
F_8 ( L_10 ) ;
V_22 = V_18 -> V_22 ;
for ( V_23 = 0 ; V_23 < V_18 -> V_24 ; V_23 ++ , V_22 ++ ) {
if ( ! V_22 -> V_25 )
break;
F_8 ( L_11 , V_22 -> V_61 ) ;
F_20 ( & V_22 -> V_56 , V_62 ,
V_63 ) ;
V_22 -> V_56 . V_64 = F_15 ;
}
F_8 ( L_12 ) ;
}
static void F_21 ( struct V_17 * V_18 )
{
struct V_21 * V_22 ;
unsigned int V_23 ;
F_8 ( L_13 ) ;
V_22 = V_18 -> V_22 ;
for ( V_23 = 0 ; V_23 < V_18 -> V_24 ; V_23 ++ , V_22 ++ ) {
if ( ! V_22 -> V_25 )
break;
F_8 ( L_14 , V_22 -> V_61 ) ;
V_22 -> V_59 = 0 ;
F_22 ( & V_22 -> V_56 ) ;
}
F_8 ( L_15 ) ;
}
void F_23 ( struct V_17 * V_18 )
{
unsigned int V_65 , V_66 , V_67 ;
struct V_68 * V_69 = & V_18 -> V_69 ;
F_8 ( L_16 ) ;
V_65 = F_7 ( V_18 , V_70 ) ;
V_66 = F_7 ( V_18 , V_71 ) ;
V_67 = F_7 ( V_18 , V_72 ) ;
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
V_69 -> V_73 = F_10 ( V_65 , V_70 , V_74 ) ;
V_69 -> V_75 = F_10 ( V_65 , V_70 , V_76 ) ;
V_69 -> V_77 = F_10 ( V_65 , V_70 , V_78 ) ;
V_69 -> V_79 = F_10 ( V_65 , V_70 , V_80 ) ;
V_69 -> V_81 = F_10 ( V_65 , V_70 , V_82 ) ;
V_69 -> V_83 = F_10 ( V_65 , V_70 , V_84 ) ;
V_69 -> V_85 = F_10 ( V_65 , V_70 , V_86 ) ;
V_69 -> V_87 = F_10 ( V_65 , V_70 , V_88 ) ;
V_69 -> V_89 = F_10 ( V_65 , V_70 , V_90 ) ;
V_69 -> V_91 = F_10 ( V_65 , V_70 , V_92 ) ;
V_69 -> V_93 = F_10 ( V_65 , V_70 , V_94 ) ;
V_69 -> V_95 = F_10 ( V_65 , V_70 ,
V_96 ) ;
V_69 -> V_97 = F_10 ( V_65 , V_70 , V_98 ) ;
V_69 -> V_99 = F_10 ( V_65 , V_70 , V_100 ) ;
V_69 -> V_101 = F_10 ( V_66 , V_71 ,
V_102 ) ;
V_69 -> V_103 = F_10 ( V_66 , V_71 ,
V_104 ) ;
V_69 -> V_105 = F_10 ( V_66 , V_71 , V_106 ) ;
V_69 -> V_107 = F_10 ( V_66 , V_71 , V_108 ) ;
V_69 -> V_109 = F_10 ( V_66 , V_71 , V_110 ) ;
V_69 -> V_111 = F_10 ( V_66 , V_71 , V_112 ) ;
V_69 -> V_113 = F_10 ( V_66 , V_71 ,
V_114 ) ;
V_69 -> V_115 = F_10 ( V_66 , V_71 ,
V_116 ) ;
V_69 -> V_117 = F_10 ( V_67 , V_72 , V_118 ) ;
V_69 -> V_119 = F_10 ( V_67 , V_72 , V_120 ) ;
V_69 -> V_121 = F_10 ( V_67 , V_72 , V_122 ) ;
V_69 -> V_123 = F_10 ( V_67 , V_72 , V_124 ) ;
V_69 -> V_125 = F_10 ( V_67 , V_72 , V_126 ) ;
V_69 -> V_127 = F_10 ( V_67 , V_72 , V_128 ) ;
V_69 -> V_117 ++ ;
V_69 -> V_119 ++ ;
V_69 -> V_121 ++ ;
V_69 -> V_123 ++ ;
F_8 ( L_17 ) ;
}
static void F_24 ( struct V_17 * V_18 , unsigned int V_129 )
{
if ( V_129 )
F_25 ( V_18 -> V_7 , & V_18 -> V_43 , V_130 ,
V_131 ) ;
F_26 ( & V_18 -> V_43 ) ;
}
static void F_27 ( struct V_17 * V_18 )
{
F_28 ( & V_18 -> V_43 ) ;
}
void F_29 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
F_8 ( L_18 ) ;
V_18 -> V_132 = V_133 ;
V_18 -> V_134 = V_135 ;
V_20 -> V_136 ( V_18 ) ;
F_8 ( L_19 ) ;
}
void F_30 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
F_8 ( L_20 ) ;
V_18 -> V_137 = V_20 -> V_138 ( V_18 , V_139 ) ;
V_18 -> V_140 = V_141 ;
V_20 -> V_142 ( V_18 ) ;
F_8 ( L_21 ) ;
}
static void F_31 ( struct V_17 * V_18 )
{
struct V_143 * V_144 = & V_18 -> V_144 ;
struct V_21 * V_22 ;
struct V_1 * V_2 ;
struct V_145 * V_146 ;
unsigned int V_23 , V_147 ;
F_8 ( L_22 ) ;
V_22 = V_18 -> V_22 ;
for ( V_23 = 0 ; V_23 < V_18 -> V_24 ; V_23 ++ , V_22 ++ ) {
V_2 = V_22 -> V_25 ;
if ( ! V_2 )
break;
for ( V_147 = 0 ; V_147 < V_2 -> V_3 ; V_147 ++ ) {
V_146 = F_32 ( V_2 , V_147 ) ;
V_144 -> V_148 ( V_18 , V_146 ) ;
}
}
F_8 ( L_23 ) ;
}
static void F_33 ( struct V_17 * V_18 )
{
struct V_143 * V_144 = & V_18 -> V_144 ;
struct V_21 * V_22 ;
struct V_1 * V_2 ;
struct V_145 * V_146 ;
unsigned int V_23 , V_147 ;
F_8 ( L_24 ) ;
V_22 = V_18 -> V_22 ;
for ( V_23 = 0 ; V_23 < V_18 -> V_24 ; V_23 ++ , V_22 ++ ) {
V_2 = V_22 -> V_28 ;
if ( ! V_2 )
break;
for ( V_147 = 0 ; V_147 < V_2 -> V_3 ; V_147 ++ ) {
V_146 = F_32 ( V_2 , V_147 ) ;
V_144 -> V_148 ( V_18 , V_146 ) ;
}
}
F_8 ( L_25 ) ;
}
int F_34 ( struct V_6 * V_7 , unsigned int V_149 )
{
struct V_17 * V_18 = F_35 ( V_7 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
unsigned long V_57 ;
F_8 ( L_26 ) ;
if ( ! F_36 ( V_7 ) ||
( V_149 == V_150 && V_18 -> V_151 ) ) {
F_3 ( V_7 , L_27 ) ;
F_8 ( L_28 ) ;
return - V_11 ;
}
F_37 ( V_18 -> V_152 ) ;
F_17 ( & V_18 -> V_58 , V_57 ) ;
if ( V_149 == V_153 )
F_38 ( V_7 ) ;
F_39 ( V_7 ) ;
F_27 ( V_18 ) ;
V_20 -> V_154 ( V_18 ) ;
V_20 -> V_155 ( V_18 ) ;
V_18 -> V_151 = 1 ;
F_18 ( & V_18 -> V_58 , V_57 ) ;
F_8 ( L_28 ) ;
return 0 ;
}
int F_40 ( struct V_6 * V_7 , unsigned int V_149 )
{
struct V_17 * V_18 = F_35 ( V_7 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
unsigned long V_57 ;
F_8 ( L_29 ) ;
if ( ! F_36 ( V_7 ) ||
( V_149 == V_150 && ! V_18 -> V_151 ) ) {
F_3 ( V_7 , L_30 ) ;
F_8 ( L_31 ) ;
return - V_11 ;
}
F_17 ( & V_18 -> V_58 , V_57 ) ;
V_18 -> V_151 = 0 ;
F_41 ( V_18 -> V_152 ) ;
V_20 -> V_156 ( V_18 ) ;
V_20 -> V_157 ( V_18 ) ;
if ( V_149 == V_153 )
F_42 ( V_7 ) ;
F_24 ( V_18 , 0 ) ;
F_43 ( V_7 ) ;
F_18 ( & V_18 -> V_58 , V_57 ) ;
F_8 ( L_31 ) ;
return 0 ;
}
static int F_44 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_6 * V_7 = V_18 -> V_7 ;
F_8 ( L_32 ) ;
F_45 ( V_7 ) ;
V_20 -> V_158 ( V_18 ) ;
F_41 ( V_18 -> V_152 ) ;
V_20 -> V_159 ( V_18 ) ;
V_20 -> V_160 ( V_18 ) ;
F_19 ( V_18 ) ;
F_24 ( V_18 , 1 ) ;
F_43 ( V_7 ) ;
F_8 ( L_33 ) ;
return 0 ;
}
static void F_46 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_6 * V_7 = V_18 -> V_7 ;
F_8 ( L_34 ) ;
F_37 ( V_18 -> V_152 ) ;
F_39 ( V_7 ) ;
F_27 ( V_18 ) ;
F_21 ( V_18 ) ;
V_20 -> V_161 ( V_18 ) ;
V_20 -> V_162 ( V_18 ) ;
F_8 ( L_35 ) ;
}
static void F_47 ( struct V_17 * V_18 , unsigned int V_163 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
F_8 ( L_36 ) ;
if ( ! F_36 ( V_18 -> V_7 ) )
return;
F_46 ( V_18 ) ;
F_48 ( V_18 -> V_164 ) ;
F_31 ( V_18 ) ;
F_33 ( V_18 ) ;
if ( V_163 )
V_20 -> exit ( V_18 ) ;
F_44 ( V_18 ) ;
F_8 ( L_37 ) ;
}
static void F_49 ( struct V_165 * V_166 )
{
struct V_17 * V_18 = F_16 ( V_166 ,
struct V_17 ,
V_45 ) ;
F_50 () ;
F_47 ( V_18 , 1 ) ;
F_51 () ;
}
static void F_52 ( struct V_167 * V_168 , struct V_169 * V_170 )
{
if ( F_53 ( V_168 ) )
V_170 -> V_171 = F_54 ( V_168 ) ;
}
static int F_55 ( struct V_167 * V_168 , struct V_169 * V_170 )
{
int V_172 ;
if ( ! F_10 ( V_170 -> V_173 , V_174 ,
V_175 ) )
return 0 ;
V_172 = F_56 ( V_168 , 0 ) ;
if ( V_172 )
return V_172 ;
V_170 -> V_176 = F_57 ( V_168 ) + F_58 ( V_168 ) ;
V_170 -> V_177 = F_58 ( V_168 ) ;
V_170 -> V_178 = V_168 -> V_179 - V_170 -> V_176 ;
V_170 -> V_180 = F_59 ( V_168 ) -> V_181 ;
F_8 ( L_38 , V_170 -> V_176 ) ;
F_8 ( L_39 ,
V_170 -> V_177 , V_170 -> V_178 ) ;
F_8 ( L_40 , V_170 -> V_180 ) ;
return 0 ;
}
static int F_60 ( struct V_167 * V_168 )
{
if ( V_168 -> V_182 != V_183 )
return 0 ;
if ( ! F_61 ( V_168 ) )
return 0 ;
F_8 ( L_41 ) ;
return 1 ;
}
static void F_62 ( struct V_1 * V_2 , struct V_167 * V_168 ,
struct V_169 * V_170 )
{
struct V_184 * V_185 ;
unsigned int V_186 ;
unsigned int V_179 ;
unsigned int V_23 ;
V_186 = 0 ;
V_170 -> V_3 = 0 ;
if ( F_60 ( V_168 ) ) {
if ( F_59 ( V_168 ) -> V_181 != V_2 -> V_187 . V_188 ) {
V_186 = 1 ;
V_170 -> V_3 ++ ;
}
V_170 -> V_3 ++ ;
F_63 ( V_170 -> V_173 , V_174 ,
V_175 , 1 ) ;
F_63 ( V_170 -> V_173 , V_174 ,
V_189 , 1 ) ;
} else if ( V_168 -> V_182 == V_183 )
F_63 ( V_170 -> V_173 , V_174 ,
V_189 , 1 ) ;
if ( F_53 ( V_168 ) ) {
if ( F_54 ( V_168 ) != V_2 -> V_187 . V_190 )
if ( ! V_186 ) {
V_186 = 1 ;
V_170 -> V_3 ++ ;
}
F_63 ( V_170 -> V_173 , V_174 ,
V_191 , 1 ) ;
}
for ( V_179 = F_64 ( V_168 ) ; V_179 ; ) {
V_170 -> V_3 ++ ;
V_179 -= F_65 (unsigned int, len, TX_MAX_BUF_SIZE) ;
}
for ( V_23 = 0 ; V_23 < F_59 ( V_168 ) -> V_192 ; V_23 ++ ) {
V_185 = & F_59 ( V_168 ) -> V_193 [ V_23 ] ;
for ( V_179 = F_66 ( V_185 ) ; V_179 ; ) {
V_170 -> V_3 ++ ;
V_179 -= F_65 (unsigned int, len, TX_MAX_BUF_SIZE) ;
}
}
}
static int F_67 ( struct V_6 * V_7 )
{
struct V_17 * V_18 = F_35 ( V_7 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_143 * V_144 = & V_18 -> V_144 ;
int V_172 ;
F_8 ( L_42 ) ;
V_172 = F_68 ( V_18 -> V_194 ) ;
if ( V_172 ) {
F_3 ( V_7 , L_43 ) ;
return V_172 ;
}
V_172 = F_2 ( V_7 , V_7 -> V_8 ) ;
if ( V_172 < 0 )
goto V_195;
V_18 -> V_9 = V_172 ;
V_172 = V_144 -> V_196 ( V_18 ) ;
if ( V_172 )
goto V_195;
F_69 ( & V_18 -> V_45 , F_49 ) ;
V_172 = F_70 ( V_18 -> V_197 , V_7 -> V_31 , F_6 , 0 ,
V_7 -> V_61 , V_18 ) ;
if ( V_172 ) {
F_3 ( V_7 , L_44 ,
V_18 -> V_164 ) ;
goto V_198;
}
V_18 -> V_164 = V_7 -> V_31 ;
V_172 = F_44 ( V_18 ) ;
if ( V_172 )
goto V_199;
F_8 ( L_45 ) ;
return 0 ;
V_199:
V_20 -> exit ( V_18 ) ;
F_71 ( V_18 -> V_197 , V_18 -> V_164 , V_18 ) ;
V_18 -> V_164 = 0 ;
V_198:
V_144 -> V_200 ( V_18 ) ;
V_195:
F_72 ( V_18 -> V_194 ) ;
return V_172 ;
}
static int F_73 ( struct V_6 * V_7 )
{
struct V_17 * V_18 = F_35 ( V_7 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_143 * V_144 = & V_18 -> V_144 ;
F_8 ( L_46 ) ;
F_46 ( V_18 ) ;
V_20 -> exit ( V_18 ) ;
V_144 -> V_200 ( V_18 ) ;
if ( V_18 -> V_164 != 0 ) {
F_71 ( V_18 -> V_197 , V_18 -> V_164 , V_18 ) ;
V_18 -> V_164 = 0 ;
}
F_72 ( V_18 -> V_194 ) ;
F_8 ( L_47 ) ;
return 0 ;
}
static int F_74 ( struct V_167 * V_168 , struct V_6 * V_7 )
{
struct V_17 * V_18 = F_35 ( V_7 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_143 * V_144 = & V_18 -> V_144 ;
struct V_21 * V_22 ;
struct V_1 * V_2 ;
struct V_169 * V_170 ;
unsigned long V_57 ;
int V_172 ;
F_8 ( L_48 , V_168 -> V_179 ) ;
V_22 = V_18 -> V_22 + V_168 -> V_201 ;
V_2 = V_22 -> V_25 ;
V_170 = & V_2 -> V_202 ;
V_172 = V_203 ;
F_17 ( & V_2 -> V_58 , V_57 ) ;
if ( V_168 -> V_179 == 0 ) {
F_75 ( V_7 , L_49 ) ;
F_76 ( V_168 ) ;
goto V_204;
}
memset ( V_170 , 0 , sizeof( * V_170 ) ) ;
F_62 ( V_2 , V_168 , V_170 ) ;
if ( V_170 -> V_3 > F_1 ( V_2 ) ) {
F_8 ( L_50 ) ;
F_77 ( V_7 , V_22 -> V_205 ) ;
V_2 -> V_187 . V_206 = 1 ;
V_172 = V_207 ;
goto V_204;
}
V_172 = F_55 ( V_168 , V_170 ) ;
if ( V_172 ) {
F_75 ( V_7 , L_51 ) ;
F_76 ( V_168 ) ;
goto V_204;
}
F_52 ( V_168 , V_170 ) ;
if ( ! V_144 -> V_208 ( V_22 , V_168 ) ) {
F_76 ( V_168 ) ;
goto V_204;
}
V_20 -> V_209 ( V_22 ) ;
#ifdef F_78
F_79 ( V_7 , V_168 , true ) ;
#endif
V_204:
F_18 ( & V_2 -> V_58 , V_57 ) ;
F_8 ( L_52 ) ;
return V_172 ;
}
static void F_45 ( struct V_6 * V_7 )
{
struct V_17 * V_18 = F_35 ( V_7 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
unsigned int V_210 , V_211 ;
F_8 ( L_53 ) ;
V_210 = ( ( V_7 -> V_57 & V_212 ) != 0 ) ;
V_211 = ( ( V_7 -> V_57 & V_213 ) != 0 ) ;
if ( F_80 ( V_7 ) > V_18 -> V_69 . V_95 )
V_210 = 1 ;
if ( F_81 ( V_7 ) > V_18 -> V_69 . V_95 )
V_211 = 1 ;
if ( ( F_80 ( V_7 ) + F_81 ( V_7 ) ) >
V_18 -> V_69 . V_95 )
V_210 = 1 ;
V_20 -> V_214 ( V_18 , V_210 ) ;
V_20 -> V_215 ( V_18 , V_211 ) ;
if ( ! V_210 )
V_20 -> V_216 ( V_18 , V_211 ) ;
F_8 ( L_54 ) ;
}
static int F_82 ( struct V_6 * V_7 , void * V_217 )
{
struct V_17 * V_18 = F_35 ( V_7 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_218 * V_219 = V_217 ;
F_8 ( L_55 ) ;
if ( ! F_83 ( V_219 -> V_220 ) )
return - V_221 ;
memcpy ( V_7 -> V_222 , V_219 -> V_220 , V_7 -> V_223 ) ;
V_20 -> V_224 ( V_18 , V_7 -> V_222 ) ;
F_8 ( L_56 ) ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 , int V_8 )
{
struct V_17 * V_18 = F_35 ( V_7 ) ;
int V_172 ;
F_8 ( L_57 ) ;
V_172 = F_2 ( V_7 , V_8 ) ;
if ( V_172 < 0 )
return V_172 ;
V_18 -> V_9 = V_172 ;
V_7 -> V_8 = V_8 ;
F_47 ( V_18 , 0 ) ;
F_8 ( L_58 ) ;
return 0 ;
}
static struct V_225 * F_85 ( struct V_6 * V_7 ,
struct V_225 * V_226 )
{
struct V_17 * V_18 = F_35 ( V_7 ) ;
struct V_227 * V_228 = & V_18 -> V_229 ;
F_8 ( L_59 , V_230 ) ;
V_18 -> V_20 . V_231 ( V_18 ) ;
V_226 -> V_232 = V_228 -> V_233 ;
V_226 -> V_234 = V_228 -> V_235 ;
V_226 -> V_236 = V_228 -> V_233 -
V_228 -> V_237 -
V_228 -> V_238 -
V_228 -> V_239 ;
V_226 -> V_240 = V_228 -> V_238 ;
V_226 -> V_241 = V_228 -> V_242 ;
V_226 -> V_243 = V_228 -> V_244 ;
V_226 -> V_245 = V_228 -> V_246 ;
V_226 -> V_247 = V_228 -> V_248 ;
V_226 -> V_249 = V_228 -> V_250 ;
V_226 -> V_251 = V_228 -> V_248 - V_228 -> V_252 ;
V_226 -> V_253 = V_7 -> V_254 . V_253 ;
F_8 ( L_60 , V_230 ) ;
return V_226 ;
}
static void F_86 ( struct V_6 * V_7 )
{
struct V_17 * V_18 = F_35 ( V_7 ) ;
F_8 ( L_61 ) ;
F_87 ( V_18 -> V_164 ) ;
F_6 ( V_18 -> V_164 , V_18 ) ;
F_88 ( V_18 -> V_164 ) ;
F_8 ( L_62 ) ;
}
static int F_89 ( struct V_6 * V_7 ,
T_2 V_255 )
{
struct V_17 * V_18 = F_35 ( V_7 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
unsigned int V_256 , V_257 ;
V_256 = ! ! ( V_18 -> V_258 & V_259 ) ;
V_257 = ! ! ( V_18 -> V_258 & V_260 ) ;
if ( ( V_255 & V_259 ) && ! V_256 ) {
V_20 -> V_261 ( V_18 ) ;
F_3 ( V_7 , L_63 ) ;
} else if ( ! ( V_255 & V_259 ) && V_256 ) {
V_20 -> V_262 ( V_18 ) ;
F_3 ( V_7 , L_64 ) ;
}
if ( ( V_255 & V_260 ) && ! V_257 ) {
V_20 -> V_263 ( V_18 ) ;
F_3 ( V_7 , L_65 ) ;
} else if ( ! ( V_255 & V_260 ) && V_257 ) {
V_20 -> V_264 ( V_18 ) ;
F_3 ( V_7 , L_66 ) ;
}
V_18 -> V_258 = V_255 ;
F_8 ( L_67 ) ;
return 0 ;
}
struct V_265 * F_90 ( void )
{
return (struct V_265 * ) & V_266 ;
}
static int F_91 ( struct V_21 * V_22 )
{
struct V_17 * V_18 = V_22 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_143 * V_144 = & V_18 -> V_144 ;
struct V_1 * V_2 = V_22 -> V_25 ;
struct V_145 * V_146 ;
struct V_267 * V_268 ;
struct V_6 * V_7 = V_18 -> V_7 ;
unsigned long V_57 ;
int V_269 = 0 ;
F_8 ( L_68 ) ;
if ( ! V_2 )
return 0 ;
F_17 ( & V_2 -> V_58 , V_57 ) ;
while ( ( V_269 < V_270 ) && ( V_2 -> V_5 < V_2 -> V_4 ) ) {
V_146 = F_32 ( V_2 , V_2 -> V_5 ) ;
V_268 = V_146 -> V_268 ;
if ( ! V_20 -> V_271 ( V_268 ) )
break;
#ifdef F_92
F_93 ( V_2 , V_2 -> V_5 , 1 , 0 ) ;
#endif
V_144 -> V_148 ( V_18 , V_146 ) ;
V_20 -> V_272 ( V_146 ) ;
V_269 ++ ;
V_2 -> V_5 ++ ;
}
if ( ( V_2 -> V_187 . V_206 == 1 ) &&
( F_1 ( V_2 ) > V_273 ) ) {
V_2 -> V_187 . V_206 = 0 ;
F_94 ( V_7 , V_22 -> V_205 ) ;
}
F_8 ( L_69 , V_269 ) ;
F_18 ( & V_2 -> V_58 , V_57 ) ;
return V_269 ;
}
static int F_95 ( struct V_21 * V_22 , int V_274 )
{
struct V_17 * V_18 = V_22 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_143 * V_144 = & V_18 -> V_144 ;
struct V_1 * V_2 = V_22 -> V_28 ;
struct V_145 * V_146 ;
struct V_169 * V_170 ;
struct V_6 * V_7 = V_18 -> V_7 ;
struct V_167 * V_168 ;
unsigned int V_275 , error ;
unsigned int V_276 , V_277 , V_278 ;
int V_279 = 0 ;
F_8 ( L_70 , V_274 ) ;
if ( ! V_2 )
return 0 ;
V_170 = & V_2 -> V_202 ;
while ( V_279 < V_274 ) {
F_8 ( L_71 , V_2 -> V_4 ) ;
memset ( V_170 , 0 , sizeof( * V_170 ) ) ;
V_168 = NULL ;
error = 0 ;
V_276 = 0 ;
V_280:
V_146 = F_32 ( V_2 , V_2 -> V_4 ) ;
if ( V_20 -> V_281 ( V_22 ) )
break;
V_279 ++ ;
V_2 -> V_4 ++ ;
V_2 -> V_5 ++ ;
F_96 ( V_18 -> V_197 , V_146 -> V_282 ,
V_146 -> V_283 , V_284 ) ;
V_146 -> V_282 = 0 ;
V_275 = F_10 ( V_170 -> V_173 ,
V_285 ,
V_286 ) ;
if ( V_275 && error )
goto V_280;
if ( error || V_170 -> V_287 ) {
if ( V_170 -> V_287 )
F_8 ( L_72 ) ;
F_97 ( V_168 ) ;
continue;
}
V_277 = V_146 -> V_179 - V_276 ;
if ( V_168 ) {
if ( F_98 ( V_168 , 0 , V_277 , V_288 ) ) {
F_8 ( L_73 ) ;
if ( V_275 ) {
error = 1 ;
goto V_280;
}
F_97 ( V_168 ) ;
continue;
}
memcpy ( F_99 ( V_168 ) , V_146 -> V_168 -> V_32 ,
V_277 ) ;
} else {
V_168 = V_146 -> V_168 ;
V_146 -> V_168 = NULL ;
}
F_100 ( V_168 , V_277 ) ;
V_276 += V_277 ;
if ( V_275 )
goto V_280;
V_278 = V_7 -> V_8 + V_12 ;
if ( ! ( V_7 -> V_255 & V_260 ) &&
( V_168 -> V_289 == F_101 ( V_290 ) ) )
V_278 += V_14 ;
if ( V_168 -> V_179 > V_278 ) {
F_8 ( L_74 ) ;
F_97 ( V_168 ) ;
continue;
}
#ifdef F_102
F_79 ( V_7 , V_168 , false ) ;
#endif
F_103 ( V_168 ) ;
if ( F_10 ( V_170 -> V_173 ,
V_285 , V_291 ) )
V_168 -> V_182 = V_292 ;
if ( F_10 ( V_170 -> V_173 ,
V_285 , V_191 ) )
F_104 ( V_168 , F_101 ( V_290 ) ,
V_170 -> V_171 ) ;
V_168 -> V_197 = V_7 ;
V_168 -> V_289 = F_105 ( V_168 , V_7 ) ;
F_106 ( V_168 , V_22 -> V_205 ) ;
F_107 ( V_168 , & V_18 -> V_43 ) ;
V_7 -> V_293 = V_294 ;
F_108 ( & V_18 -> V_43 , V_168 ) ;
}
if ( V_279 ) {
V_144 -> V_295 ( V_22 ) ;
V_146 = F_32 ( V_2 , V_2 -> V_296 . V_297 - 1 ) ;
F_14 ( V_22 , V_298 ,
F_109 ( V_146 -> V_299 ) ) ;
}
F_8 ( L_75 , V_279 ) ;
return V_279 ;
}
static int V_130 ( struct V_300 * V_43 , int V_274 )
{
struct V_17 * V_18 = F_16 ( V_43 , struct V_17 ,
V_43 ) ;
struct V_21 * V_22 ;
int V_269 ;
unsigned int V_23 ;
F_8 ( L_76 , V_274 ) ;
V_22 = V_18 -> V_22 ;
for ( V_23 = 0 ; V_23 < V_18 -> V_24 ; V_23 ++ , V_22 ++ )
F_91 ( V_22 ) ;
V_269 = 0 ;
V_22 = V_18 -> V_22 ;
for ( V_23 = 0 ; V_23 < V_18 -> V_24 ; V_23 ++ , V_22 ++ )
V_269 += F_95 ( V_22 , V_274 - V_269 ) ;
if ( V_269 < V_274 ) {
F_110 ( V_43 ) ;
F_4 ( V_18 ) ;
}
F_8 ( L_77 , V_269 ) ;
return V_269 ;
}
void F_93 ( struct V_1 * V_2 , unsigned int V_301 ,
unsigned int V_302 , unsigned int V_303 )
{
struct V_145 * V_146 ;
struct V_267 * V_268 ;
while ( V_302 -- ) {
V_146 = F_32 ( V_2 , V_301 ) ;
V_268 = V_146 -> V_268 ;
F_8 ( L_78 , V_301 ,
( V_303 == 1 ) ? L_79 : L_80 ,
F_111 ( V_268 -> V_304 ) , F_111 ( V_268 -> V_305 ) ,
F_111 ( V_268 -> V_306 ) , F_111 ( V_268 -> V_307 ) ) ;
V_301 ++ ;
}
}
void F_112 ( struct V_1 * V_2 , struct V_267 * V_308 ,
unsigned int V_301 )
{
F_8 ( L_81 , V_301 ,
F_111 ( V_308 -> V_304 ) , F_111 ( V_308 -> V_305 ) ,
F_111 ( V_308 -> V_306 ) , F_111 ( V_308 -> V_307 ) ) ;
}
void F_79 ( struct V_6 * V_7 , struct V_167 * V_168 , bool V_309 )
{
struct V_310 * V_311 = (struct V_310 * ) V_168 -> V_32 ;
unsigned char * V_312 = V_168 -> V_32 ;
unsigned char V_313 [ 128 ] ;
unsigned int V_23 , V_147 ;
F_3 ( V_7 , L_82 ) ;
F_3 ( V_7 , L_83 ,
( V_309 ? L_84 : L_85 ) , V_168 -> V_179 ) ;
F_3 ( V_7 , L_86 , V_311 -> V_314 ) ;
F_3 ( V_7 , L_87 , V_311 -> V_315 ) ;
F_3 ( V_7 , L_88 , F_113 ( V_311 -> V_316 ) ) ;
for ( V_23 = 0 , V_147 = 0 ; V_23 < V_168 -> V_179 ; ) {
V_147 += snprintf ( V_313 + V_147 , sizeof( V_313 ) - V_147 , L_89 ,
V_312 [ V_23 ++ ] ) ;
if ( ( V_23 % 32 ) == 0 ) {
F_3 ( V_7 , L_90 , V_23 - 32 , V_313 ) ;
V_147 = 0 ;
} else if ( ( V_23 % 16 ) == 0 ) {
V_313 [ V_147 ++ ] = ' ' ;
V_313 [ V_147 ++ ] = ' ' ;
} else if ( ( V_23 % 4 ) == 0 ) {
V_313 [ V_147 ++ ] = ' ' ;
}
}
if ( V_23 % 32 )
F_3 ( V_7 , L_90 , V_23 - ( V_23 % 32 ) , V_313 ) ;
F_3 ( V_7 , L_82 ) ;
}

static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 * V_7 , * V_8 ;
unsigned int V_9 , V_10 ;
int V_11 = - V_12 ;
V_9 = F_2 (unsigned int, pdata->tx_ring_count, pdata->rx_ring_count) ;
V_4 = F_3 ( V_9 , sizeof( struct V_3 ) , V_13 ) ;
if ( ! V_4 )
goto V_14;
V_7 = F_3 ( V_2 -> V_15 , sizeof( struct V_6 ) ,
V_13 ) ;
if ( ! V_7 )
goto V_16;
V_8 = F_3 ( V_2 -> V_17 , sizeof( struct V_6 ) ,
V_13 ) ;
if ( ! V_8 )
goto V_18;
for ( V_10 = 0 , V_5 = V_4 ; V_10 < V_9 ; V_10 ++ , V_5 ++ ) {
snprintf ( V_5 -> V_19 , sizeof( V_5 -> V_19 ) , L_1 , V_10 ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_20 = V_10 ;
V_5 -> V_21 = V_2 -> V_22 + V_23 +
( V_24 * V_10 ) ;
if ( V_2 -> V_25 ) {
V_11 = F_4 ( V_2 -> V_26 , V_10 + 1 ) ;
if ( V_11 < 0 ) {
F_5 ( V_2 -> V_27 ,
L_2 ,
V_10 + 1 ) ;
goto V_28;
}
V_5 -> V_29 = V_11 ;
}
if ( V_10 < V_2 -> V_15 ) {
F_6 ( & V_7 -> V_30 ) ;
V_5 -> V_7 = V_7 ++ ;
}
if ( V_10 < V_2 -> V_17 ) {
F_6 ( & V_8 -> V_30 ) ;
V_5 -> V_8 = V_8 ++ ;
}
F_7 ( V_2 , V_31 , V_2 -> V_27 ,
L_3 ,
V_5 -> V_19 , V_5 -> V_21 , V_5 -> V_29 ,
V_5 -> V_7 , V_5 -> V_8 ) ;
}
V_2 -> V_5 = V_4 ;
V_2 -> V_32 = V_9 ;
return 0 ;
V_28:
F_8 ( V_8 ) ;
V_18:
F_8 ( V_7 ) ;
V_16:
F_8 ( V_4 ) ;
V_14:
return V_11 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 )
return;
F_8 ( V_2 -> V_5 -> V_8 ) ;
F_8 ( V_2 -> V_5 -> V_7 ) ;
F_8 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_2 -> V_32 = 0 ;
}
static inline unsigned int F_10 ( struct V_6 * V_33 )
{
return ( V_33 -> V_34 - ( V_33 -> V_35 - V_33 -> V_36 ) ) ;
}
static inline unsigned int F_11 ( struct V_6 * V_33 )
{
return ( V_33 -> V_35 - V_33 -> V_36 ) ;
}
static int F_12 ( struct V_3 * V_5 ,
struct V_6 * V_33 , unsigned int V_9 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
if ( V_9 > F_10 ( V_33 ) ) {
F_13 ( V_2 , V_31 , V_2 -> V_27 ,
L_4 ) ;
F_14 ( V_2 -> V_27 , V_5 -> V_20 ) ;
V_33 -> V_37 . V_38 = 1 ;
if ( V_33 -> V_37 . V_39 )
V_2 -> V_40 . V_41 ( V_5 , V_33 ) ;
return V_42 ;
}
return 0 ;
}
static int F_15 ( struct V_43 * V_27 , unsigned int V_44 )
{
unsigned int V_45 ;
if ( V_44 > V_46 ) {
F_16 ( V_27 , L_5 ) ;
return - V_47 ;
}
V_45 = V_44 + V_48 + V_49 + V_50 ;
V_45 = F_17 ( V_45 , V_51 , V_52 ) ;
V_45 = ( V_45 + V_53 - 1 ) &
~ ( V_53 - 1 ) ;
return V_45 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_3 * V_5 ;
enum V_55 V_56 ;
unsigned int V_10 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
if ( V_5 -> V_7 && V_5 -> V_8 )
V_56 = V_57 ;
else if ( V_5 -> V_7 )
V_56 = V_58 ;
else if ( V_5 -> V_8 )
V_56 = V_59 ;
else
continue;
V_40 -> V_60 ( V_5 , V_56 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_3 * V_5 ;
enum V_55 V_56 ;
unsigned int V_10 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
if ( V_5 -> V_7 && V_5 -> V_8 )
V_56 = V_57 ;
else if ( V_5 -> V_7 )
V_56 = V_58 ;
else if ( V_5 -> V_8 )
V_56 = V_59 ;
else
continue;
V_40 -> V_61 ( V_5 , V_56 ) ;
}
}
static T_1 F_20 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_3 * V_5 ;
unsigned int V_64 , V_65 ;
unsigned int V_66 , V_67 ;
unsigned int V_10 ;
V_64 = F_21 ( V_2 , V_68 ) ;
if ( ! V_64 )
goto V_69;
F_7 ( V_2 , V_70 , V_2 -> V_27 , L_6 , V_64 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ ) {
if ( ! ( V_64 & ( 1 << V_10 ) ) )
continue;
V_5 = V_2 -> V_5 + V_10 ;
V_65 = F_22 ( V_5 , V_71 ) ;
F_7 ( V_2 , V_70 , V_2 -> V_27 , L_7 ,
V_10 , V_65 ) ;
if ( ! V_2 -> V_25 &&
( F_23 ( V_65 , V_71 , V_72 ) ||
F_23 ( V_65 , V_71 , V_73 ) ) ) {
if ( F_24 ( & V_2 -> V_74 ) ) {
F_19 ( V_2 ) ;
F_25 ( & V_2 -> V_74 ) ;
}
}
if ( F_23 ( V_65 , V_71 , V_75 ) )
F_26 ( & V_2 -> V_76 ) ;
F_27 ( V_5 , V_71 , V_65 ) ;
}
if ( F_23 ( V_64 , V_68 , V_77 ) ) {
V_66 = F_21 ( V_2 , V_78 ) ;
if ( F_23 ( V_66 , V_78 , V_79 ) )
V_40 -> V_80 ( V_2 ) ;
if ( F_23 ( V_66 , V_78 , V_81 ) )
V_40 -> V_82 ( V_2 ) ;
if ( F_23 ( V_66 , V_78 , V_83 ) ) {
V_67 = F_21 ( V_2 , V_84 ) ;
if ( F_23 ( V_67 , V_84 , V_85 ) ) {
V_2 -> V_86 =
V_40 -> V_87 ( V_2 ) ;
F_26 ( & V_2 -> V_88 ) ;
}
}
}
V_69:
return V_89 ;
}
static T_1 F_28 ( int V_62 , void * V_63 )
{
struct V_3 * V_5 = V_63 ;
if ( F_24 ( & V_5 -> V_74 ) ) {
F_29 ( V_5 -> V_29 ) ;
F_25 ( & V_5 -> V_74 ) ;
}
return V_89 ;
}
static void F_30 ( unsigned long V_63 )
{
struct V_3 * V_5 = (struct V_3 * ) V_63 ;
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_90 * V_74 ;
F_31 ( L_8 ) ;
V_74 = ( V_2 -> V_25 ) ? & V_5 -> V_74 : & V_2 -> V_74 ;
if ( F_24 ( V_74 ) ) {
if ( V_2 -> V_25 )
F_29 ( V_5 -> V_29 ) ;
else
F_19 ( V_2 ) ;
F_25 ( V_74 ) ;
}
V_5 -> V_91 = 0 ;
F_31 ( L_9 ) ;
}
static void F_32 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_33 ( V_93 ,
struct V_1 ,
V_94 ) ;
V_2 -> V_95 . V_96 ( V_2 ) ;
}
static void F_34 ( unsigned long V_63 )
{
struct V_1 * V_2 = (struct V_1 * ) V_63 ;
F_26 ( & V_2 -> V_94 ) ;
F_35 ( & V_2 -> V_97 , V_98 + V_99 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_37 ( & V_2 -> V_97 , F_34 ,
( unsigned long ) V_2 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
break;
F_37 ( & V_5 -> V_100 , F_30 ,
( unsigned long ) V_5 ) ;
}
}
static void F_38 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_97 , V_98 + V_99 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_40 ( & V_2 -> V_97 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
break;
F_40 ( & V_5 -> V_100 ) ;
}
}
void F_41 ( struct V_1 * V_2 )
{
unsigned int V_101 , V_102 , V_103 ;
struct V_104 * V_105 = & V_2 -> V_105 ;
F_31 ( L_10 ) ;
V_101 = F_21 ( V_2 , V_106 ) ;
V_102 = F_21 ( V_2 , V_107 ) ;
V_103 = F_21 ( V_2 , V_108 ) ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_109 = F_21 ( V_2 , V_110 ) ;
V_105 -> V_111 = F_23 ( V_101 , V_106 , V_112 ) ;
V_105 -> V_113 = F_23 ( V_101 , V_106 , V_114 ) ;
V_105 -> V_115 = F_23 ( V_101 , V_106 , V_116 ) ;
V_105 -> V_117 = F_23 ( V_101 , V_106 , V_118 ) ;
V_105 -> V_119 = F_23 ( V_101 , V_106 , V_120 ) ;
V_105 -> V_121 = F_23 ( V_101 , V_106 , V_122 ) ;
V_105 -> V_123 = F_23 ( V_101 , V_106 , V_124 ) ;
V_105 -> V_125 = F_23 ( V_101 , V_106 , V_126 ) ;
V_105 -> V_127 = F_23 ( V_101 , V_106 , V_128 ) ;
V_105 -> V_129 = F_23 ( V_101 , V_106 , V_130 ) ;
V_105 -> V_131 = F_23 ( V_101 , V_106 , V_132 ) ;
V_105 -> V_133 = F_23 ( V_101 , V_106 ,
V_134 ) ;
V_105 -> V_135 = F_23 ( V_101 , V_106 , V_136 ) ;
V_105 -> V_137 = F_23 ( V_101 , V_106 , V_138 ) ;
V_105 -> V_139 = F_23 ( V_102 , V_107 ,
V_140 ) ;
V_105 -> V_141 = F_23 ( V_102 , V_107 ,
V_142 ) ;
V_105 -> V_143 = F_23 ( V_102 , V_107 , V_144 ) ;
V_105 -> V_145 = F_23 ( V_102 , V_107 , V_146 ) ;
V_105 -> V_147 = F_23 ( V_102 , V_107 , V_148 ) ;
V_105 -> V_149 = F_23 ( V_102 , V_107 , V_150 ) ;
V_105 -> V_151 = F_23 ( V_102 , V_107 , V_152 ) ;
V_105 -> V_153 = F_23 ( V_102 , V_107 , V_154 ) ;
V_105 -> V_155 = F_23 ( V_102 , V_107 , V_156 ) ;
V_105 -> V_157 = F_23 ( V_102 , V_107 , V_158 ) ;
V_105 -> V_159 = F_23 ( V_102 , V_107 ,
V_160 ) ;
V_105 -> V_161 = F_23 ( V_102 , V_107 ,
V_162 ) ;
V_105 -> V_163 = F_23 ( V_103 , V_108 , V_164 ) ;
V_105 -> V_165 = F_23 ( V_103 , V_108 , V_166 ) ;
V_105 -> V_167 = F_23 ( V_103 , V_108 , V_168 ) ;
V_105 -> V_169 = F_23 ( V_103 , V_108 , V_170 ) ;
V_105 -> V_171 = F_23 ( V_103 , V_108 , V_172 ) ;
V_105 -> V_173 = F_23 ( V_103 , V_108 , V_174 ) ;
switch ( V_105 -> V_159 ) {
case 0 :
break;
case 1 :
V_105 -> V_159 = 64 ;
break;
case 2 :
V_105 -> V_159 = 128 ;
break;
case 3 :
V_105 -> V_159 = 256 ;
break;
}
switch ( V_105 -> V_145 ) {
case 0 :
V_105 -> V_145 = 32 ;
break;
case 1 :
V_105 -> V_145 = 40 ;
break;
case 2 :
V_105 -> V_145 = 48 ;
break;
default:
V_105 -> V_145 = 32 ;
}
V_105 -> V_163 ++ ;
V_105 -> V_165 ++ ;
V_105 -> V_167 ++ ;
V_105 -> V_169 ++ ;
V_105 -> V_157 ++ ;
F_31 ( L_11 ) ;
}
static void F_42 ( struct V_1 * V_2 , unsigned int V_175 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
if ( V_175 )
F_43 ( V_2 -> V_27 , & V_5 -> V_74 ,
V_176 , V_177 ) ;
F_44 ( & V_5 -> V_74 ) ;
}
} else {
if ( V_175 )
F_43 ( V_2 -> V_27 , & V_2 -> V_74 ,
V_178 , V_177 ) ;
F_44 ( & V_2 -> V_74 ) ;
}
}
static void F_45 ( struct V_1 * V_2 , unsigned int V_179 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
F_46 ( & V_5 -> V_74 ) ;
if ( V_179 )
F_47 ( & V_5 -> V_74 ) ;
}
} else {
F_46 ( & V_2 -> V_74 ) ;
if ( V_179 )
F_47 ( & V_2 -> V_74 ) ;
}
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
struct V_43 * V_27 = V_2 -> V_27 ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_49 ( V_2 -> V_180 , V_2 -> V_181 , F_20 , 0 ,
V_27 -> V_19 , V_2 ) ;
if ( V_11 ) {
F_16 ( V_27 , L_12 ,
V_2 -> V_181 ) ;
return V_11 ;
}
if ( ! V_2 -> V_25 )
return 0 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
snprintf ( V_5 -> V_182 ,
sizeof( V_5 -> V_182 ) - 1 ,
L_13 , F_50 ( V_27 ) ,
V_5 -> V_20 ) ;
V_11 = F_49 ( V_2 -> V_180 , V_5 -> V_29 ,
F_28 , 0 ,
V_5 -> V_182 , V_5 ) ;
if ( V_11 ) {
F_16 ( V_27 , L_12 ,
V_5 -> V_29 ) ;
goto V_28;
}
}
return 0 ;
V_28:
for ( V_10 -- , V_5 -- ; V_10 < V_2 -> V_32 ; V_10 -- , V_5 -- )
F_51 ( V_2 -> V_180 , V_5 -> V_29 , V_5 ) ;
F_51 ( V_2 -> V_180 , V_2 -> V_181 , V_2 ) ;
return V_11 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_51 ( V_2 -> V_180 , V_2 -> V_181 , V_2 ) ;
if ( ! V_2 -> V_25 )
return;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ )
F_51 ( V_2 -> V_180 , V_5 -> V_29 , V_5 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_54 * V_40 = & V_2 -> V_40 ;
F_31 ( L_14 ) ;
V_2 -> V_183 = V_184 ;
V_2 -> V_185 = V_186 ;
V_40 -> V_187 ( V_2 ) ;
F_31 ( L_15 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_54 * V_40 = & V_2 -> V_40 ;
F_31 ( L_16 ) ;
V_2 -> V_188 = V_40 -> V_189 ( V_2 , V_190 ) ;
V_2 -> V_191 = V_190 ;
V_2 -> V_192 = V_193 ;
V_40 -> V_194 ( V_2 ) ;
F_31 ( L_17 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_195 * V_196 = & V_2 -> V_196 ;
struct V_3 * V_5 ;
struct V_6 * V_33 ;
struct V_197 * V_198 ;
unsigned int V_10 , V_199 ;
F_31 ( L_18 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
V_33 = V_5 -> V_7 ;
if ( ! V_33 )
break;
for ( V_199 = 0 ; V_199 < V_33 -> V_34 ; V_199 ++ ) {
V_198 = F_56 ( V_33 , V_199 ) ;
V_196 -> V_200 ( V_2 , V_198 ) ;
}
}
F_31 ( L_19 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_195 * V_196 = & V_2 -> V_196 ;
struct V_3 * V_5 ;
struct V_6 * V_33 ;
struct V_197 * V_198 ;
unsigned int V_10 , V_199 ;
F_31 ( L_20 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
V_33 = V_5 -> V_8 ;
if ( ! V_33 )
break;
for ( V_199 = 0 ; V_199 < V_33 -> V_34 ; V_199 ++ ) {
V_198 = F_56 ( V_33 , V_199 ) ;
V_196 -> V_200 ( V_2 , V_198 ) ;
}
}
F_31 ( L_21 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
V_2 -> V_201 = - 1 ;
V_2 -> V_202 = V_203 ;
return V_2 -> V_95 . V_204 ( V_2 ) ;
}
int F_59 ( struct V_43 * V_27 , unsigned int V_205 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
unsigned long V_206 ;
F_31 ( L_22 ) ;
if ( ! F_61 ( V_27 ) ||
( V_205 == V_207 && V_2 -> V_208 ) ) {
F_16 ( V_27 , L_23 ) ;
F_31 ( L_24 ) ;
return - V_47 ;
}
F_62 ( & V_2 -> V_30 , V_206 ) ;
if ( V_205 == V_209 )
F_63 ( V_27 ) ;
F_64 ( V_27 ) ;
F_39 ( V_2 ) ;
F_65 ( V_2 -> V_210 ) ;
V_40 -> V_211 ( V_2 ) ;
V_40 -> V_212 ( V_2 ) ;
F_45 ( V_2 , 0 ) ;
V_2 -> V_208 = 1 ;
F_66 ( & V_2 -> V_30 , V_206 ) ;
F_31 ( L_24 ) ;
return 0 ;
}
int F_67 ( struct V_43 * V_27 , unsigned int V_205 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
unsigned long V_206 ;
F_31 ( L_25 ) ;
if ( ! F_61 ( V_27 ) ||
( V_205 == V_207 && ! V_2 -> V_208 ) ) {
F_16 ( V_27 , L_26 ) ;
F_31 ( L_27 ) ;
return - V_47 ;
}
F_62 ( & V_2 -> V_30 , V_206 ) ;
V_2 -> V_208 = 0 ;
F_42 ( V_2 , 0 ) ;
V_40 -> V_213 ( V_2 ) ;
V_40 -> V_214 ( V_2 ) ;
if ( V_205 == V_209 )
F_68 ( V_27 ) ;
F_69 ( V_27 ) ;
F_38 ( V_2 ) ;
F_66 ( & V_2 -> V_30 , V_206 ) ;
F_31 ( L_27 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_215 * V_95 = & V_2 -> V_95 ;
struct V_43 * V_27 = V_2 -> V_27 ;
int V_11 ;
F_31 ( L_28 ) ;
V_40 -> V_216 ( V_2 ) ;
V_11 = V_95 -> V_217 ( V_2 ) ;
if ( V_11 )
goto V_218;
F_42 ( V_2 , 1 ) ;
V_11 = F_48 ( V_2 ) ;
if ( V_11 )
goto V_219;
V_40 -> V_220 ( V_2 ) ;
V_40 -> V_221 ( V_2 ) ;
F_69 ( V_27 ) ;
F_38 ( V_2 ) ;
F_26 ( & V_2 -> V_94 ) ;
F_31 ( L_29 ) ;
return 0 ;
V_219:
F_45 ( V_2 , 1 ) ;
V_95 -> V_222 ( V_2 ) ;
V_218:
V_40 -> exit ( V_2 ) ;
return V_11 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_215 * V_95 = & V_2 -> V_95 ;
struct V_3 * V_5 ;
struct V_43 * V_27 = V_2 -> V_27 ;
struct V_223 * V_224 ;
unsigned int V_10 ;
F_31 ( L_30 ) ;
F_64 ( V_27 ) ;
F_39 ( V_2 ) ;
F_65 ( V_2 -> V_210 ) ;
V_40 -> V_225 ( V_2 ) ;
V_40 -> V_226 ( V_2 ) ;
F_52 ( V_2 ) ;
F_45 ( V_2 , 1 ) ;
V_95 -> V_222 ( V_2 ) ;
V_40 -> exit ( V_2 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
continue;
V_224 = F_72 ( V_27 , V_5 -> V_20 ) ;
F_73 ( V_224 ) ;
}
F_31 ( L_31 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
F_31 ( L_32 ) ;
if ( ! F_61 ( V_2 -> V_27 ) )
return;
F_71 ( V_2 ) ;
F_55 ( V_2 ) ;
F_57 ( V_2 ) ;
F_70 ( V_2 ) ;
F_31 ( L_33 ) ;
}
static void F_75 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_33 ( V_93 ,
struct V_1 ,
V_76 ) ;
F_76 () ;
F_74 ( V_2 ) ;
F_77 () ;
}
static void F_78 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_33 ( V_93 ,
struct V_1 ,
V_88 ) ;
struct V_227 V_228 ;
T_2 V_229 ;
unsigned long V_206 ;
if ( V_2 -> V_86 ) {
V_229 = F_79 ( & V_2 -> V_230 ,
V_2 -> V_86 ) ;
memset ( & V_228 , 0 , sizeof( V_228 ) ) ;
V_228 . V_231 = F_80 ( V_229 ) ;
F_81 ( V_2 -> V_232 , & V_228 ) ;
}
F_82 ( V_2 -> V_232 ) ;
F_62 ( & V_2 -> V_233 , V_206 ) ;
V_2 -> V_232 = NULL ;
F_66 ( & V_2 -> V_233 , V_206 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_234 * V_234 )
{
if ( F_84 ( V_234 -> V_235 , & V_2 -> V_236 ,
sizeof( V_2 -> V_236 ) ) )
return - V_237 ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_234 * V_234 )
{
struct V_238 V_239 ;
unsigned int V_240 ;
if ( F_86 ( & V_239 , V_234 -> V_235 , sizeof( V_239 ) ) )
return - V_237 ;
if ( V_239 . V_206 )
return - V_47 ;
V_240 = 0 ;
switch ( V_239 . V_241 ) {
case V_242 :
break;
case V_243 :
F_87 ( V_240 , V_244 , V_245 , 1 ) ;
break;
default:
return - V_246 ;
}
switch ( V_239 . V_247 ) {
case V_248 :
break;
case V_249 :
F_87 ( V_240 , V_244 , V_250 , 1 ) ;
F_87 ( V_240 , V_244 , V_245 , 1 ) ;
break;
case V_251 :
F_87 ( V_240 , V_244 , V_252 , 1 ) ;
case V_253 :
F_87 ( V_240 , V_244 , V_254 , 1 ) ;
F_87 ( V_240 , V_244 , V_255 , 1 ) ;
F_87 ( V_240 , V_244 , V_256 , 1 ) ;
F_87 ( V_240 , V_244 , V_245 , 1 ) ;
break;
case V_257 :
F_87 ( V_240 , V_244 , V_252 , 1 ) ;
case V_258 :
F_87 ( V_240 , V_244 , V_254 , 1 ) ;
F_87 ( V_240 , V_244 , V_255 , 1 ) ;
F_87 ( V_240 , V_244 , V_259 , 1 ) ;
F_87 ( V_240 , V_244 , V_245 , 1 ) ;
break;
case V_260 :
F_87 ( V_240 , V_244 , V_252 , 1 ) ;
case V_261 :
F_87 ( V_240 , V_244 , V_254 , 1 ) ;
F_87 ( V_240 , V_244 , V_255 , 1 ) ;
F_87 ( V_240 , V_244 , V_259 , 1 ) ;
F_87 ( V_240 , V_244 , V_262 , 1 ) ;
F_87 ( V_240 , V_244 , V_245 , 1 ) ;
break;
case V_263 :
F_87 ( V_240 , V_244 , V_264 , 1 ) ;
F_87 ( V_240 , V_244 , V_256 , 1 ) ;
F_87 ( V_240 , V_244 , V_245 , 1 ) ;
break;
case V_265 :
F_87 ( V_240 , V_244 , V_264 , 1 ) ;
F_87 ( V_240 , V_244 , V_259 , 1 ) ;
F_87 ( V_240 , V_244 , V_245 , 1 ) ;
break;
case V_266 :
F_87 ( V_240 , V_244 , V_264 , 1 ) ;
F_87 ( V_240 , V_244 , V_262 , 1 ) ;
F_87 ( V_240 , V_244 , V_259 , 1 ) ;
F_87 ( V_240 , V_244 , V_245 , 1 ) ;
break;
case V_267 :
F_87 ( V_240 , V_244 , V_252 , 1 ) ;
F_87 ( V_240 , V_244 , V_268 , 1 ) ;
F_87 ( V_240 , V_244 , V_254 , 1 ) ;
F_87 ( V_240 , V_244 , V_255 , 1 ) ;
F_87 ( V_240 , V_244 , V_256 , 1 ) ;
F_87 ( V_240 , V_244 , V_245 , 1 ) ;
break;
case V_269 :
F_87 ( V_240 , V_244 , V_252 , 1 ) ;
F_87 ( V_240 , V_244 , V_268 , 1 ) ;
F_87 ( V_240 , V_244 , V_254 , 1 ) ;
F_87 ( V_240 , V_244 , V_255 , 1 ) ;
F_87 ( V_240 , V_244 , V_259 , 1 ) ;
F_87 ( V_240 , V_244 , V_245 , 1 ) ;
break;
case V_270 :
F_87 ( V_240 , V_244 , V_252 , 1 ) ;
F_87 ( V_240 , V_244 , V_268 , 1 ) ;
F_87 ( V_240 , V_244 , V_254 , 1 ) ;
F_87 ( V_240 , V_244 , V_255 , 1 ) ;
F_87 ( V_240 , V_244 , V_262 , 1 ) ;
F_87 ( V_240 , V_244 , V_259 , 1 ) ;
F_87 ( V_240 , V_244 , V_245 , 1 ) ;
break;
default:
return - V_246 ;
}
V_2 -> V_40 . V_271 ( V_2 , V_240 ) ;
memcpy ( & V_2 -> V_236 , & V_239 , sizeof( V_239 ) ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_272 * V_273 ,
struct V_274 * V_275 )
{
unsigned long V_206 ;
if ( F_23 ( V_275 -> V_276 , V_277 , V_278 ) ) {
F_62 ( & V_2 -> V_233 , V_206 ) ;
if ( V_2 -> V_232 ) {
F_87 ( V_275 -> V_276 ,
V_277 , V_278 , 0 ) ;
} else {
V_2 -> V_232 = F_89 ( V_273 ) ;
F_90 ( V_273 ) -> V_279 |= V_280 ;
}
F_66 ( & V_2 -> V_233 , V_206 ) ;
}
if ( ! F_23 ( V_275 -> V_276 , V_277 , V_278 ) )
F_91 ( V_273 ) ;
}
static void F_92 ( struct V_272 * V_273 , struct V_274 * V_275 )
{
if ( F_93 ( V_273 ) )
V_275 -> V_281 = F_94 ( V_273 ) ;
}
static int F_95 ( struct V_272 * V_273 , struct V_274 * V_275 )
{
int V_11 ;
if ( ! F_23 ( V_275 -> V_276 , V_277 ,
V_282 ) )
return 0 ;
V_11 = F_96 ( V_273 , 0 ) ;
if ( V_11 )
return V_11 ;
V_275 -> V_283 = F_97 ( V_273 ) + F_98 ( V_273 ) ;
V_275 -> V_284 = F_98 ( V_273 ) ;
V_275 -> V_285 = V_273 -> V_286 - V_275 -> V_283 ;
V_275 -> V_287 = F_90 ( V_273 ) -> V_288 ;
F_31 ( L_34 , V_275 -> V_283 ) ;
F_31 ( L_35 ,
V_275 -> V_284 , V_275 -> V_285 ) ;
F_31 ( L_36 , V_275 -> V_287 ) ;
V_275 -> V_289 = F_90 ( V_273 ) -> V_290 ;
V_275 -> V_291 += ( V_275 -> V_289 - 1 ) * V_275 -> V_283 ;
return 0 ;
}
static int F_99 ( struct V_272 * V_273 )
{
if ( V_273 -> V_292 != V_293 )
return 0 ;
if ( ! F_100 ( V_273 ) )
return 0 ;
F_31 ( L_37 ) ;
return 1 ;
}
static void F_101 ( struct V_1 * V_2 ,
struct V_6 * V_33 , struct V_272 * V_273 ,
struct V_274 * V_275 )
{
struct V_294 * V_295 ;
unsigned int V_296 ;
unsigned int V_286 ;
unsigned int V_10 ;
V_275 -> V_273 = V_273 ;
V_296 = 0 ;
V_275 -> V_34 = 0 ;
V_275 -> V_289 = 1 ;
V_275 -> V_291 = V_273 -> V_286 ;
if ( F_99 ( V_273 ) ) {
if ( F_90 ( V_273 ) -> V_288 != V_33 -> V_37 . V_297 ) {
V_296 = 1 ;
V_275 -> V_34 ++ ;
}
V_275 -> V_34 ++ ;
F_87 ( V_275 -> V_276 , V_277 ,
V_282 , 1 ) ;
F_87 ( V_275 -> V_276 , V_277 ,
V_298 , 1 ) ;
} else if ( V_273 -> V_292 == V_293 )
F_87 ( V_275 -> V_276 , V_277 ,
V_298 , 1 ) ;
if ( F_93 ( V_273 ) ) {
if ( F_94 ( V_273 ) != V_33 -> V_37 . V_299 )
if ( ! V_296 ) {
V_296 = 1 ;
V_275 -> V_34 ++ ;
}
F_87 ( V_275 -> V_276 , V_277 ,
V_300 , 1 ) ;
}
if ( ( F_90 ( V_273 ) -> V_279 & V_301 ) &&
( V_2 -> V_236 . V_241 == V_243 ) )
F_87 ( V_275 -> V_276 , V_277 ,
V_278 , 1 ) ;
for ( V_286 = F_102 ( V_273 ) ; V_286 ; ) {
V_275 -> V_34 ++ ;
V_286 -= F_103 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
for ( V_10 = 0 ; V_10 < F_90 ( V_273 ) -> V_302 ; V_10 ++ ) {
V_295 = & F_90 ( V_273 ) -> V_303 [ V_10 ] ;
for ( V_286 = F_104 ( V_295 ) ; V_286 ; ) {
V_275 -> V_34 ++ ;
V_286 -= F_103 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
}
}
static int F_105 ( struct V_43 * V_27 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
struct V_195 * V_196 = & V_2 -> V_196 ;
int V_11 ;
F_31 ( L_38 ) ;
V_11 = F_58 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_106 ( V_2 -> V_304 ) ;
if ( V_11 ) {
F_16 ( V_27 , L_39 ) ;
return V_11 ;
}
V_11 = F_106 ( V_2 -> V_305 ) ;
if ( V_11 ) {
F_16 ( V_27 , L_40 ) ;
goto V_306;
}
V_11 = F_15 ( V_27 , V_27 -> V_44 ) ;
if ( V_11 < 0 )
goto V_307;
V_2 -> V_45 = V_11 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 )
goto V_307;
V_11 = V_196 -> V_308 ( V_2 ) ;
if ( V_11 )
goto V_309;
F_107 ( & V_2 -> V_94 , F_32 ) ;
F_107 ( & V_2 -> V_76 , F_75 ) ;
F_107 ( & V_2 -> V_88 , F_78 ) ;
F_36 ( V_2 ) ;
V_11 = F_70 ( V_2 ) ;
if ( V_11 )
goto V_310;
F_108 ( V_311 , & V_2 -> V_312 ) ;
F_31 ( L_41 ) ;
return 0 ;
V_310:
V_196 -> V_313 ( V_2 ) ;
V_309:
F_9 ( V_2 ) ;
V_307:
F_109 ( V_2 -> V_305 ) ;
V_306:
F_109 ( V_2 -> V_304 ) ;
return V_11 ;
}
static int F_110 ( struct V_43 * V_27 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
struct V_195 * V_196 = & V_2 -> V_196 ;
F_31 ( L_42 ) ;
F_71 ( V_2 ) ;
V_196 -> V_313 ( V_2 ) ;
F_9 ( V_2 ) ;
F_109 ( V_2 -> V_305 ) ;
F_109 ( V_2 -> V_304 ) ;
F_111 ( V_311 , & V_2 -> V_312 ) ;
F_31 ( L_43 ) ;
return 0 ;
}
static int F_112 ( struct V_272 * V_273 , struct V_43 * V_27 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_195 * V_196 = & V_2 -> V_196 ;
struct V_3 * V_5 ;
struct V_6 * V_33 ;
struct V_274 * V_275 ;
struct V_223 * V_224 ;
int V_11 ;
F_31 ( L_44 , V_273 -> V_286 ) ;
V_5 = V_2 -> V_5 + V_273 -> V_314 ;
V_224 = F_72 ( V_27 , V_5 -> V_20 ) ;
V_33 = V_5 -> V_7 ;
V_275 = & V_33 -> V_315 ;
V_11 = V_316 ;
if ( V_273 -> V_286 == 0 ) {
F_113 ( V_2 , V_317 , V_27 ,
L_45 ) ;
F_82 ( V_273 ) ;
goto V_318;
}
memset ( V_275 , 0 , sizeof( * V_275 ) ) ;
F_101 ( V_2 , V_33 , V_273 , V_275 ) ;
V_11 = F_12 ( V_5 , V_33 , V_275 -> V_34 ) ;
if ( V_11 )
goto V_318;
V_11 = F_95 ( V_273 , V_275 ) ;
if ( V_11 ) {
F_113 ( V_2 , V_317 , V_27 ,
L_46 ) ;
F_82 ( V_273 ) ;
goto V_318;
}
F_92 ( V_273 , V_275 ) ;
if ( ! V_196 -> V_319 ( V_5 , V_273 ) ) {
F_82 ( V_273 ) ;
goto V_318;
}
F_88 ( V_2 , V_273 , V_275 ) ;
F_114 ( V_224 , V_275 -> V_291 ) ;
V_40 -> V_320 ( V_5 ) ;
if ( F_115 ( V_2 ) )
F_116 ( V_27 , V_273 , true ) ;
F_12 ( V_5 , V_33 , V_321 ) ;
V_11 = V_316 ;
V_318:
return V_11 ;
}
static void F_117 ( struct V_43 * V_27 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
F_31 ( L_47 ) ;
V_40 -> V_322 ( V_2 ) ;
F_31 ( L_48 ) ;
}
static int F_118 ( struct V_43 * V_27 , void * V_323 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_324 * V_325 = V_323 ;
F_31 ( L_49 ) ;
if ( ! F_119 ( V_325 -> V_326 ) )
return - V_327 ;
memcpy ( V_27 -> V_328 , V_325 -> V_326 , V_27 -> V_329 ) ;
V_40 -> V_330 ( V_2 , V_27 -> V_328 ) ;
F_31 ( L_50 ) ;
return 0 ;
}
static int F_120 ( struct V_43 * V_27 , struct V_234 * V_234 , int V_331 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
int V_11 ;
switch ( V_331 ) {
case V_332 :
V_11 = F_83 ( V_2 , V_234 ) ;
break;
case V_333 :
V_11 = F_85 ( V_2 , V_234 ) ;
break;
default:
V_11 = - V_334 ;
}
return V_11 ;
}
static int F_121 ( struct V_43 * V_27 , int V_44 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
int V_11 ;
F_31 ( L_51 ) ;
V_11 = F_15 ( V_27 , V_44 ) ;
if ( V_11 < 0 )
return V_11 ;
V_2 -> V_45 = V_11 ;
V_27 -> V_44 = V_44 ;
F_74 ( V_2 ) ;
F_31 ( L_52 ) ;
return 0 ;
}
static void F_122 ( struct V_43 * V_27 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
F_123 ( V_27 , L_53 ) ;
F_26 ( & V_2 -> V_76 ) ;
}
static struct V_335 * F_124 ( struct V_43 * V_27 ,
struct V_335 * V_336 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
struct V_337 * V_338 = & V_2 -> V_339 ;
F_31 ( L_54 , V_340 ) ;
V_2 -> V_40 . V_341 ( V_2 ) ;
V_336 -> V_342 = V_338 -> V_343 ;
V_336 -> V_344 = V_338 -> V_345 ;
V_336 -> V_346 = V_338 -> V_343 -
V_338 -> V_347 -
V_338 -> V_348 -
V_338 -> V_349 ;
V_336 -> V_350 = V_338 -> V_348 ;
V_336 -> V_351 = V_338 -> V_352 ;
V_336 -> V_353 = V_338 -> V_354 ;
V_336 -> V_355 = V_338 -> V_356 ;
V_336 -> V_289 = V_338 -> V_357 ;
V_336 -> V_291 = V_338 -> V_358 ;
V_336 -> V_359 = V_338 -> V_357 - V_338 -> V_360 ;
V_336 -> V_361 = V_27 -> V_362 . V_361 ;
F_31 ( L_55 , V_340 ) ;
return V_336 ;
}
static int F_125 ( struct V_43 * V_27 , T_3 V_363 ,
T_4 V_364 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
F_31 ( L_54 , V_340 ) ;
F_111 ( V_364 , V_2 -> V_365 ) ;
V_40 -> V_366 ( V_2 ) ;
F_31 ( L_55 , V_340 ) ;
return 0 ;
}
static int F_126 ( struct V_43 * V_27 , T_3 V_363 ,
T_4 V_364 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
F_31 ( L_54 , V_340 ) ;
F_108 ( V_364 , V_2 -> V_365 ) ;
V_40 -> V_366 ( V_2 ) ;
F_31 ( L_55 , V_340 ) ;
return 0 ;
}
static void F_127 ( struct V_43 * V_27 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
struct V_3 * V_5 ;
unsigned int V_10 ;
F_31 ( L_56 ) ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ )
F_28 ( V_5 -> V_29 , V_5 ) ;
} else {
F_128 ( V_2 -> V_181 ) ;
F_20 ( V_2 -> V_181 , V_2 ) ;
F_129 ( V_2 -> V_181 ) ;
}
F_31 ( L_57 ) ;
}
static int F_130 ( struct V_43 * V_27 , T_5 V_367 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
unsigned int V_368 , V_369 ;
T_5 V_10 ;
if ( V_367 && ( V_367 != V_2 -> V_105 . V_157 ) )
return - V_47 ;
if ( V_367 ) {
F_131 ( V_27 , V_367 ) ;
for ( V_10 = 0 , V_369 = 0 , V_368 = 0 ; V_10 < V_367 ; V_10 ++ ) {
while ( ( V_369 < V_2 -> V_370 ) &&
( V_2 -> V_371 [ V_369 ] == V_10 ) )
V_369 ++ ;
F_7 ( V_2 , V_31 , V_27 , L_58 ,
V_10 , V_368 , V_369 - 1 ) ;
F_132 ( V_27 , V_10 , V_369 - V_368 , V_368 ) ;
V_368 = V_369 ;
}
} else {
F_133 ( V_27 ) ;
}
return 0 ;
}
static int F_134 ( struct V_43 * V_27 ,
T_6 V_372 )
{
struct V_1 * V_2 = F_60 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
T_6 V_373 , V_374 , V_375 , V_376 ;
int V_11 = 0 ;
V_373 = V_2 -> V_377 & V_378 ;
V_374 = V_2 -> V_377 & V_379 ;
V_375 = V_2 -> V_377 & V_380 ;
V_376 = V_2 -> V_377 & V_381 ;
if ( ( V_372 & V_378 ) && ! V_373 )
V_11 = V_40 -> V_382 ( V_2 ) ;
else if ( ! ( V_372 & V_378 ) && V_373 )
V_11 = V_40 -> V_383 ( V_2 ) ;
if ( V_11 )
return V_11 ;
if ( ( V_372 & V_379 ) && ! V_374 )
V_40 -> V_384 ( V_2 ) ;
else if ( ! ( V_372 & V_379 ) && V_374 )
V_40 -> V_385 ( V_2 ) ;
if ( ( V_372 & V_380 ) && ! V_375 )
V_40 -> V_386 ( V_2 ) ;
else if ( ! ( V_372 & V_380 ) && V_375 )
V_40 -> V_387 ( V_2 ) ;
if ( ( V_372 & V_381 ) && ! V_376 )
V_40 -> V_388 ( V_2 ) ;
else if ( ! ( V_372 & V_381 ) && V_376 )
V_40 -> V_389 ( V_2 ) ;
V_2 -> V_377 = V_372 ;
F_31 ( L_59 ) ;
return 0 ;
}
struct V_390 * F_135 ( void )
{
return (struct V_390 * ) & V_391 ;
}
static void F_136 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_195 * V_196 = & V_2 -> V_196 ;
struct V_6 * V_33 = V_5 -> V_8 ;
struct V_197 * V_198 ;
while ( V_33 -> V_36 != V_33 -> V_35 ) {
V_198 = F_56 ( V_33 , V_33 -> V_36 ) ;
V_196 -> V_200 ( V_2 , V_198 ) ;
if ( V_196 -> V_392 ( V_2 , V_33 , V_198 ) )
break;
V_40 -> V_393 ( V_2 , V_198 , V_33 -> V_36 ) ;
V_33 -> V_36 ++ ;
}
F_137 () ;
V_198 = F_56 ( V_33 , V_33 -> V_36 - 1 ) ;
F_27 ( V_5 , V_394 ,
F_138 ( V_198 -> V_395 ) ) ;
}
static struct V_272 * F_139 ( struct V_1 * V_2 ,
struct V_90 * V_74 ,
struct V_197 * V_198 ,
unsigned int V_286 )
{
struct V_272 * V_273 ;
T_5 * V_275 ;
unsigned int V_396 ;
V_273 = F_140 ( V_74 , V_198 -> V_397 . V_398 . V_399 ) ;
if ( ! V_273 )
return NULL ;
F_141 ( V_2 -> V_180 , V_198 -> V_397 . V_398 . V_400 ,
V_198 -> V_397 . V_398 . V_401 ,
V_198 -> V_397 . V_398 . V_399 , V_402 ) ;
V_275 = F_142 ( V_198 -> V_397 . V_398 . V_403 . V_404 ) +
V_198 -> V_397 . V_398 . V_403 . V_405 ;
V_396 = ( V_198 -> V_397 . V_406 ) ? V_198 -> V_397 . V_406 : V_286 ;
V_396 = F_143 ( V_198 -> V_397 . V_398 . V_399 , V_396 ) ;
F_144 ( V_273 , V_275 , V_396 ) ;
F_145 ( V_273 , V_396 ) ;
V_286 -= V_396 ;
if ( V_286 ) {
F_141 ( V_2 -> V_180 ,
V_198 -> V_397 . V_407 . V_400 ,
V_198 -> V_397 . V_407 . V_401 ,
V_198 -> V_397 . V_407 . V_399 ,
V_402 ) ;
F_146 ( V_273 , F_90 ( V_273 ) -> V_302 ,
V_198 -> V_397 . V_407 . V_403 . V_404 ,
V_198 -> V_397 . V_407 . V_403 . V_405 ,
V_286 , V_198 -> V_397 . V_407 . V_399 ) ;
V_198 -> V_397 . V_407 . V_403 . V_404 = NULL ;
}
return V_273 ;
}
static int F_147 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_195 * V_196 = & V_2 -> V_196 ;
struct V_6 * V_33 = V_5 -> V_7 ;
struct V_197 * V_198 ;
struct V_408 * V_409 ;
struct V_43 * V_27 = V_2 -> V_27 ;
struct V_223 * V_224 ;
int V_410 = 0 ;
unsigned int V_289 = 0 , V_291 = 0 ;
unsigned int V_35 ;
F_31 ( L_60 ) ;
if ( ! V_33 )
return 0 ;
V_35 = V_33 -> V_35 ;
F_148 () ;
V_224 = F_72 ( V_27 , V_5 -> V_20 ) ;
while ( ( V_410 < V_411 ) &&
( V_33 -> V_36 != V_35 ) ) {
V_198 = F_56 ( V_33 , V_33 -> V_36 ) ;
V_409 = V_198 -> V_409 ;
if ( ! V_40 -> V_412 ( V_409 ) )
break;
F_149 () ;
if ( F_150 ( V_2 ) )
F_151 ( V_2 , V_33 , V_33 -> V_36 , 1 , 0 ) ;
if ( V_40 -> V_413 ( V_409 ) ) {
V_289 += V_198 -> V_37 . V_414 ;
V_291 += V_198 -> V_37 . V_415 ;
}
V_196 -> V_200 ( V_2 , V_198 ) ;
V_40 -> V_416 ( V_198 ) ;
V_410 ++ ;
V_33 -> V_36 ++ ;
}
if ( ! V_410 )
return 0 ;
F_152 ( V_224 , V_289 , V_291 ) ;
if ( ( V_33 -> V_37 . V_38 == 1 ) &&
( F_10 ( V_33 ) > V_417 ) ) {
V_33 -> V_37 . V_38 = 0 ;
F_153 ( V_224 ) ;
}
F_31 ( L_61 , V_410 ) ;
return V_410 ;
}
static int F_154 ( struct V_3 * V_5 , int V_418 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_6 * V_33 = V_5 -> V_8 ;
struct V_197 * V_198 ;
struct V_274 * V_275 ;
struct V_43 * V_27 = V_2 -> V_27 ;
struct V_90 * V_74 ;
struct V_272 * V_273 ;
struct V_227 * V_228 ;
unsigned int V_419 , error , V_420 , V_421 ;
unsigned int V_286 , V_422 , V_423 ;
unsigned int V_424 = 0 ;
int V_425 = 0 ;
F_31 ( L_62 , V_418 ) ;
if ( ! V_33 )
return 0 ;
V_419 = 0 ;
V_420 = 0 ;
V_74 = ( V_2 -> V_25 ) ? & V_5 -> V_74 : & V_2 -> V_74 ;
V_198 = F_56 ( V_33 , V_33 -> V_35 ) ;
V_275 = & V_33 -> V_315 ;
while ( V_425 < V_418 ) {
F_31 ( L_63 , V_33 -> V_35 ) ;
if ( ! V_424 && V_198 -> V_426 ) {
V_273 = V_198 -> V_427 . V_273 ;
error = V_198 -> V_427 . error ;
V_286 = V_198 -> V_427 . V_286 ;
} else {
memset ( V_275 , 0 , sizeof( * V_275 ) ) ;
V_273 = NULL ;
error = 0 ;
V_286 = 0 ;
}
V_428:
V_198 = F_56 ( V_33 , V_33 -> V_35 ) ;
if ( F_11 ( V_33 ) > ( V_429 >> 3 ) )
F_136 ( V_5 ) ;
if ( V_40 -> V_430 ( V_5 ) )
break;
V_424 ++ ;
V_33 -> V_35 ++ ;
V_419 = F_23 ( V_275 -> V_276 ,
V_431 ,
V_432 ) ;
V_420 = F_23 ( V_275 -> V_276 ,
V_431 ,
V_433 ) ;
V_421 = F_23 ( V_275 -> V_276 ,
V_431 ,
V_434 ) ;
if ( ( V_419 || V_420 ) && error )
goto V_428;
if ( error || V_275 -> V_435 ) {
if ( V_275 -> V_435 )
F_113 ( V_2 , V_436 , V_27 ,
L_64 ) ;
F_155 ( V_273 ) ;
goto V_437;
}
if ( ! V_421 ) {
V_422 = V_198 -> V_397 . V_286 - V_286 ;
V_286 += V_422 ;
if ( V_422 && ! V_273 ) {
V_273 = F_139 ( V_2 , V_74 , V_198 ,
V_422 ) ;
if ( ! V_273 )
error = 1 ;
} else if ( V_422 ) {
F_141 ( V_2 -> V_180 ,
V_198 -> V_397 . V_407 . V_400 ,
V_198 -> V_397 . V_407 . V_401 ,
V_198 -> V_397 . V_407 . V_399 ,
V_402 ) ;
F_146 ( V_273 , F_90 ( V_273 ) -> V_302 ,
V_198 -> V_397 . V_407 . V_403 . V_404 ,
V_198 -> V_397 . V_407 . V_403 . V_405 ,
V_422 ,
V_198 -> V_397 . V_407 . V_399 ) ;
V_198 -> V_397 . V_407 . V_403 . V_404 = NULL ;
}
}
if ( V_419 || V_420 )
goto V_428;
if ( ! V_273 )
goto V_437;
V_423 = V_27 -> V_44 + V_48 ;
if ( ! ( V_27 -> V_372 & V_380 ) &&
( V_273 -> V_438 == F_156 ( V_439 ) ) )
V_423 += V_50 ;
if ( V_273 -> V_286 > V_423 ) {
F_113 ( V_2 , V_436 , V_27 ,
L_65 ) ;
F_155 ( V_273 ) ;
goto V_437;
}
if ( F_115 ( V_2 ) )
F_116 ( V_27 , V_273 , false ) ;
F_157 ( V_273 ) ;
if ( F_23 ( V_275 -> V_276 ,
V_431 , V_440 ) )
V_273 -> V_292 = V_441 ;
if ( F_23 ( V_275 -> V_276 ,
V_431 , V_300 ) )
F_158 ( V_273 , F_156 ( V_439 ) ,
V_275 -> V_281 ) ;
if ( F_23 ( V_275 -> V_276 ,
V_431 , V_442 ) ) {
T_2 V_229 ;
V_229 = F_79 ( & V_2 -> V_230 ,
V_275 -> V_443 ) ;
V_228 = F_159 ( V_273 ) ;
V_228 -> V_231 = F_80 ( V_229 ) ;
}
if ( F_23 ( V_275 -> V_276 ,
V_431 , V_444 ) )
F_160 ( V_273 , V_275 -> V_445 ,
V_275 -> V_446 ) ;
V_273 -> V_180 = V_27 ;
V_273 -> V_438 = F_161 ( V_273 , V_27 ) ;
F_162 ( V_273 , V_5 -> V_20 ) ;
F_163 ( V_273 , V_74 ) ;
F_164 ( V_74 , V_273 ) ;
V_437:
V_425 ++ ;
}
if ( V_424 && ( V_419 || V_420 ) ) {
V_198 = F_56 ( V_33 , V_33 -> V_35 ) ;
V_198 -> V_426 = 1 ;
V_198 -> V_427 . V_273 = V_273 ;
V_198 -> V_427 . V_286 = V_286 ;
V_198 -> V_427 . error = error ;
}
F_31 ( L_66 , V_425 ) ;
return V_425 ;
}
static int V_176 ( struct V_90 * V_74 , int V_418 )
{
struct V_3 * V_5 = F_33 ( V_74 , struct V_3 ,
V_74 ) ;
int V_410 = 0 ;
F_31 ( L_67 , V_418 ) ;
F_147 ( V_5 ) ;
V_410 = F_154 ( V_5 , V_418 ) ;
if ( V_410 < V_418 ) {
F_165 ( V_74 ) ;
F_129 ( V_5 -> V_29 ) ;
}
F_31 ( L_68 , V_410 ) ;
return V_410 ;
}
static int V_178 ( struct V_90 * V_74 , int V_418 )
{
struct V_1 * V_2 = F_33 ( V_74 , struct V_1 ,
V_74 ) ;
struct V_3 * V_5 ;
int V_447 ;
int V_410 , V_448 ;
unsigned int V_10 ;
F_31 ( L_69 , V_418 ) ;
V_410 = 0 ;
V_447 = V_418 / V_2 -> V_17 ;
do {
V_448 = V_410 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
F_147 ( V_5 ) ;
if ( V_447 > ( V_418 - V_410 ) )
V_447 = V_418 - V_410 ;
V_410 += F_154 ( V_5 , V_447 ) ;
}
} while ( ( V_410 < V_418 ) && ( V_410 != V_448 ) );
if ( V_410 < V_418 ) {
F_165 ( V_74 ) ;
F_18 ( V_2 ) ;
}
F_31 ( L_70 , V_410 ) ;
return V_410 ;
}
void F_151 ( struct V_1 * V_2 , struct V_6 * V_33 ,
unsigned int V_449 , unsigned int V_9 , unsigned int V_450 )
{
struct V_197 * V_198 ;
struct V_408 * V_409 ;
while ( V_9 -- ) {
V_198 = F_56 ( V_33 , V_449 ) ;
V_409 = V_198 -> V_409 ;
F_166 ( V_2 -> V_27 ,
L_71 , V_449 ,
( V_450 == 1 ) ? L_72 : L_73 ,
F_167 ( V_409 -> V_451 ) ,
F_167 ( V_409 -> V_452 ) ,
F_167 ( V_409 -> V_453 ) ,
F_167 ( V_409 -> V_454 ) ) ;
V_449 ++ ;
}
}
void F_168 ( struct V_1 * V_2 , struct V_6 * V_33 ,
unsigned int V_449 )
{
struct V_197 * V_198 ;
struct V_408 * V_409 ;
V_198 = F_56 ( V_33 , V_449 ) ;
V_409 = V_198 -> V_409 ;
F_166 ( V_2 -> V_27 ,
L_74 ,
V_449 , F_167 ( V_409 -> V_451 ) , F_167 ( V_409 -> V_452 ) ,
F_167 ( V_409 -> V_453 ) , F_167 ( V_409 -> V_454 ) ) ;
}
void F_116 ( struct V_43 * V_27 , struct V_272 * V_273 , bool V_455 )
{
struct V_456 * V_457 = (struct V_456 * ) V_273 -> V_63 ;
unsigned char * V_407 = V_273 -> V_63 ;
unsigned char V_458 [ 128 ] ;
unsigned int V_10 , V_199 ;
F_166 ( V_27 , L_75 ) ;
F_166 ( V_27 , L_76 ,
( V_455 ? L_77 : L_78 ) , V_273 -> V_286 ) ;
F_166 ( V_27 , L_79 , V_457 -> V_459 ) ;
F_166 ( V_27 , L_80 , V_457 -> V_460 ) ;
F_166 ( V_27 , L_81 , F_169 ( V_457 -> V_461 ) ) ;
for ( V_10 = 0 , V_199 = 0 ; V_10 < V_273 -> V_286 ; ) {
V_199 += snprintf ( V_458 + V_199 , sizeof( V_458 ) - V_199 , L_82 ,
V_407 [ V_10 ++ ] ) ;
if ( ( V_10 % 32 ) == 0 ) {
F_166 ( V_27 , L_83 , V_10 - 32 , V_458 ) ;
V_199 = 0 ;
} else if ( ( V_10 % 16 ) == 0 ) {
V_458 [ V_199 ++ ] = ' ' ;
V_458 [ V_199 ++ ] = ' ' ;
} else if ( ( V_10 % 4 ) == 0 ) {
V_458 [ V_199 ++ ] = ' ' ;
}
}
if ( V_10 % 32 )
F_166 ( V_27 , L_83 , V_10 - ( V_10 % 32 ) , V_458 ) ;
F_166 ( V_27 , L_75 ) ;
}

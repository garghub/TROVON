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
V_2 -> V_76 . V_77 ++ ;
if ( F_23 ( V_65 , V_71 , V_78 ) )
F_26 ( & V_2 -> V_79 ) ;
F_27 ( V_5 , V_71 , V_65 ) ;
}
if ( F_23 ( V_64 , V_68 , V_80 ) ) {
V_66 = F_21 ( V_2 , V_81 ) ;
if ( F_23 ( V_66 , V_81 , V_82 ) )
V_40 -> V_83 ( V_2 ) ;
if ( F_23 ( V_66 , V_81 , V_84 ) )
V_40 -> V_85 ( V_2 ) ;
if ( F_23 ( V_66 , V_81 , V_86 ) ) {
V_67 = F_21 ( V_2 , V_87 ) ;
if ( F_23 ( V_67 , V_87 , V_88 ) ) {
V_2 -> V_89 =
V_40 -> V_90 ( V_2 ) ;
F_28 ( V_2 -> V_91 ,
& V_2 -> V_92 ) ;
}
}
}
V_69:
return V_93 ;
}
static T_1 F_29 ( int V_62 , void * V_63 )
{
struct V_3 * V_5 = V_63 ;
if ( F_24 ( & V_5 -> V_74 ) ) {
F_30 ( V_5 -> V_29 ) ;
F_25 ( & V_5 -> V_74 ) ;
}
return V_93 ;
}
static void F_31 ( unsigned long V_63 )
{
struct V_3 * V_5 = (struct V_3 * ) V_63 ;
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_94 * V_74 ;
F_32 ( L_8 ) ;
V_74 = ( V_2 -> V_25 ) ? & V_5 -> V_74 : & V_2 -> V_74 ;
if ( F_24 ( V_74 ) ) {
if ( V_2 -> V_25 )
F_30 ( V_5 -> V_29 ) ;
else
F_19 ( V_2 ) ;
F_25 ( V_74 ) ;
}
V_5 -> V_95 = 0 ;
F_32 ( L_9 ) ;
}
static void F_33 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_34 ( V_97 ,
struct V_1 ,
V_98 ) ;
V_2 -> V_99 . V_100 ( V_2 ) ;
}
static void F_35 ( unsigned long V_63 )
{
struct V_1 * V_2 = (struct V_1 * ) V_63 ;
F_28 ( V_2 -> V_91 , & V_2 -> V_98 ) ;
F_36 ( & V_2 -> V_101 , V_102 + V_103 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_38 ( & V_2 -> V_101 , F_35 ,
( unsigned long ) V_2 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
break;
F_38 ( & V_5 -> V_104 , F_31 ,
( unsigned long ) V_5 ) ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_101 , V_102 + V_103 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_41 ( & V_2 -> V_101 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
break;
F_41 ( & V_5 -> V_104 ) ;
}
}
void F_42 ( struct V_1 * V_2 )
{
unsigned int V_105 , V_106 , V_107 ;
struct V_108 * V_109 = & V_2 -> V_109 ;
F_32 ( L_10 ) ;
V_105 = F_21 ( V_2 , V_110 ) ;
V_106 = F_21 ( V_2 , V_111 ) ;
V_107 = F_21 ( V_2 , V_112 ) ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_109 -> V_113 = F_21 ( V_2 , V_114 ) ;
V_109 -> V_115 = F_23 ( V_105 , V_110 , V_116 ) ;
V_109 -> V_117 = F_23 ( V_105 , V_110 , V_118 ) ;
V_109 -> V_119 = F_23 ( V_105 , V_110 , V_120 ) ;
V_109 -> V_121 = F_23 ( V_105 , V_110 , V_122 ) ;
V_109 -> V_123 = F_23 ( V_105 , V_110 , V_124 ) ;
V_109 -> V_125 = F_23 ( V_105 , V_110 , V_126 ) ;
V_109 -> V_127 = F_23 ( V_105 , V_110 , V_128 ) ;
V_109 -> V_129 = F_23 ( V_105 , V_110 , V_130 ) ;
V_109 -> V_131 = F_23 ( V_105 , V_110 , V_132 ) ;
V_109 -> V_133 = F_23 ( V_105 , V_110 , V_134 ) ;
V_109 -> V_135 = F_23 ( V_105 , V_110 , V_136 ) ;
V_109 -> V_137 = F_23 ( V_105 , V_110 ,
V_138 ) ;
V_109 -> V_139 = F_23 ( V_105 , V_110 , V_140 ) ;
V_109 -> V_141 = F_23 ( V_105 , V_110 , V_142 ) ;
V_109 -> V_143 = F_23 ( V_106 , V_111 ,
V_144 ) ;
V_109 -> V_145 = F_23 ( V_106 , V_111 ,
V_146 ) ;
V_109 -> V_147 = F_23 ( V_106 , V_111 , V_148 ) ;
V_109 -> V_149 = F_23 ( V_106 , V_111 , V_150 ) ;
V_109 -> V_151 = F_23 ( V_106 , V_111 , V_152 ) ;
V_109 -> V_153 = F_23 ( V_106 , V_111 , V_154 ) ;
V_109 -> V_155 = F_23 ( V_106 , V_111 , V_156 ) ;
V_109 -> V_157 = F_23 ( V_106 , V_111 , V_158 ) ;
V_109 -> V_159 = F_23 ( V_106 , V_111 , V_160 ) ;
V_109 -> V_161 = F_23 ( V_106 , V_111 , V_162 ) ;
V_109 -> V_163 = F_23 ( V_106 , V_111 ,
V_164 ) ;
V_109 -> V_165 = F_23 ( V_106 , V_111 ,
V_166 ) ;
V_109 -> V_167 = F_23 ( V_107 , V_112 , V_168 ) ;
V_109 -> V_169 = F_23 ( V_107 , V_112 , V_170 ) ;
V_109 -> V_171 = F_23 ( V_107 , V_112 , V_172 ) ;
V_109 -> V_173 = F_23 ( V_107 , V_112 , V_174 ) ;
V_109 -> V_175 = F_23 ( V_107 , V_112 , V_176 ) ;
V_109 -> V_177 = F_23 ( V_107 , V_112 , V_178 ) ;
switch ( V_109 -> V_163 ) {
case 0 :
break;
case 1 :
V_109 -> V_163 = 64 ;
break;
case 2 :
V_109 -> V_163 = 128 ;
break;
case 3 :
V_109 -> V_163 = 256 ;
break;
}
switch ( V_109 -> V_149 ) {
case 0 :
V_109 -> V_149 = 32 ;
break;
case 1 :
V_109 -> V_149 = 40 ;
break;
case 2 :
V_109 -> V_149 = 48 ;
break;
default:
V_109 -> V_149 = 32 ;
}
V_109 -> V_167 ++ ;
V_109 -> V_169 ++ ;
V_109 -> V_171 ++ ;
V_109 -> V_173 ++ ;
V_109 -> V_161 ++ ;
F_32 ( L_11 ) ;
}
static void F_43 ( struct V_1 * V_2 , unsigned int V_179 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
if ( V_179 )
F_44 ( V_2 -> V_27 , & V_5 -> V_74 ,
V_180 , V_181 ) ;
F_45 ( & V_5 -> V_74 ) ;
}
} else {
if ( V_179 )
F_44 ( V_2 -> V_27 , & V_2 -> V_74 ,
V_182 , V_181 ) ;
F_45 ( & V_2 -> V_74 ) ;
}
}
static void F_46 ( struct V_1 * V_2 , unsigned int V_183 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
F_47 ( & V_5 -> V_74 ) ;
if ( V_183 )
F_48 ( & V_5 -> V_74 ) ;
}
} else {
F_47 ( & V_2 -> V_74 ) ;
if ( V_183 )
F_48 ( & V_2 -> V_74 ) ;
}
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
struct V_43 * V_27 = V_2 -> V_27 ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_50 ( V_2 -> V_184 , V_2 -> V_185 , F_20 , 0 ,
V_27 -> V_19 , V_2 ) ;
if ( V_11 ) {
F_16 ( V_27 , L_12 ,
V_2 -> V_185 ) ;
return V_11 ;
}
if ( ! V_2 -> V_25 )
return 0 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
snprintf ( V_5 -> V_186 ,
sizeof( V_5 -> V_186 ) - 1 ,
L_13 , F_51 ( V_27 ) ,
V_5 -> V_20 ) ;
V_11 = F_50 ( V_2 -> V_184 , V_5 -> V_29 ,
F_29 , 0 ,
V_5 -> V_186 , V_5 ) ;
if ( V_11 ) {
F_16 ( V_27 , L_12 ,
V_5 -> V_29 ) ;
goto V_28;
}
}
return 0 ;
V_28:
for ( V_10 -- , V_5 -- ; V_10 < V_2 -> V_32 ; V_10 -- , V_5 -- )
F_52 ( V_2 -> V_184 , V_5 -> V_29 , V_5 ) ;
F_52 ( V_2 -> V_184 , V_2 -> V_185 , V_2 ) ;
return V_11 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_52 ( V_2 -> V_184 , V_2 -> V_185 , V_2 ) ;
if ( ! V_2 -> V_25 )
return;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ )
F_52 ( V_2 -> V_184 , V_5 -> V_29 , V_5 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_54 * V_40 = & V_2 -> V_40 ;
F_32 ( L_14 ) ;
V_2 -> V_187 = V_188 ;
V_2 -> V_189 = V_190 ;
V_40 -> V_191 ( V_2 ) ;
F_32 ( L_15 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_54 * V_40 = & V_2 -> V_40 ;
F_32 ( L_16 ) ;
V_2 -> V_192 = V_40 -> V_193 ( V_2 , V_194 ) ;
V_2 -> V_195 = V_194 ;
V_2 -> V_196 = V_197 ;
V_40 -> V_198 ( V_2 ) ;
F_32 ( L_17 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_199 * V_200 = & V_2 -> V_200 ;
struct V_3 * V_5 ;
struct V_6 * V_33 ;
struct V_201 * V_202 ;
unsigned int V_10 , V_203 ;
F_32 ( L_18 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
V_33 = V_5 -> V_7 ;
if ( ! V_33 )
break;
for ( V_203 = 0 ; V_203 < V_33 -> V_34 ; V_203 ++ ) {
V_202 = F_57 ( V_33 , V_203 ) ;
V_200 -> V_204 ( V_2 , V_202 ) ;
}
}
F_32 ( L_19 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_199 * V_200 = & V_2 -> V_200 ;
struct V_3 * V_5 ;
struct V_6 * V_33 ;
struct V_201 * V_202 ;
unsigned int V_10 , V_203 ;
F_32 ( L_20 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
V_33 = V_5 -> V_8 ;
if ( ! V_33 )
break;
for ( V_203 = 0 ; V_203 < V_33 -> V_34 ; V_203 ++ ) {
V_202 = F_57 ( V_33 , V_203 ) ;
V_200 -> V_204 ( V_2 , V_202 ) ;
}
}
F_32 ( L_21 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
V_2 -> V_205 = - 1 ;
V_2 -> V_206 = V_207 ;
return V_2 -> V_99 . V_208 ( V_2 ) ;
}
int F_60 ( struct V_43 * V_27 , unsigned int V_209 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
unsigned long V_210 ;
F_32 ( L_22 ) ;
if ( ! F_62 ( V_27 ) ||
( V_209 == V_211 && V_2 -> V_212 ) ) {
F_16 ( V_27 , L_23 ) ;
F_32 ( L_24 ) ;
return - V_47 ;
}
F_63 ( & V_2 -> V_30 , V_210 ) ;
if ( V_209 == V_213 )
F_64 ( V_27 ) ;
F_65 ( V_27 ) ;
F_40 ( V_2 ) ;
F_66 ( V_2 -> V_91 ) ;
V_40 -> V_214 ( V_2 ) ;
V_40 -> V_215 ( V_2 ) ;
F_46 ( V_2 , 0 ) ;
V_2 -> V_212 = 1 ;
F_67 ( & V_2 -> V_30 , V_210 ) ;
F_32 ( L_24 ) ;
return 0 ;
}
int F_68 ( struct V_43 * V_27 , unsigned int V_209 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
unsigned long V_210 ;
F_32 ( L_25 ) ;
if ( ! F_62 ( V_27 ) ||
( V_209 == V_211 && ! V_2 -> V_212 ) ) {
F_16 ( V_27 , L_26 ) ;
F_32 ( L_27 ) ;
return - V_47 ;
}
F_63 ( & V_2 -> V_30 , V_210 ) ;
V_2 -> V_212 = 0 ;
F_43 ( V_2 , 0 ) ;
V_40 -> V_216 ( V_2 ) ;
V_40 -> V_217 ( V_2 ) ;
if ( V_209 == V_213 )
F_69 ( V_27 ) ;
F_70 ( V_27 ) ;
F_39 ( V_2 ) ;
F_67 ( & V_2 -> V_30 , V_210 ) ;
F_32 ( L_27 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_218 * V_99 = & V_2 -> V_99 ;
struct V_43 * V_27 = V_2 -> V_27 ;
int V_11 ;
F_32 ( L_28 ) ;
V_40 -> V_219 ( V_2 ) ;
V_11 = V_99 -> V_220 ( V_2 ) ;
if ( V_11 )
goto V_221;
F_43 ( V_2 , 1 ) ;
V_11 = F_49 ( V_2 ) ;
if ( V_11 )
goto V_222;
V_40 -> V_223 ( V_2 ) ;
V_40 -> V_224 ( V_2 ) ;
F_70 ( V_27 ) ;
F_39 ( V_2 ) ;
F_28 ( V_2 -> V_91 , & V_2 -> V_98 ) ;
F_32 ( L_29 ) ;
return 0 ;
V_222:
F_46 ( V_2 , 1 ) ;
V_99 -> V_225 ( V_2 ) ;
V_221:
V_40 -> exit ( V_2 ) ;
return V_11 ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_218 * V_99 = & V_2 -> V_99 ;
struct V_3 * V_5 ;
struct V_43 * V_27 = V_2 -> V_27 ;
struct V_226 * V_227 ;
unsigned int V_10 ;
F_32 ( L_30 ) ;
F_65 ( V_27 ) ;
F_40 ( V_2 ) ;
F_66 ( V_2 -> V_91 ) ;
V_40 -> V_228 ( V_2 ) ;
V_40 -> V_229 ( V_2 ) ;
F_53 ( V_2 ) ;
F_46 ( V_2 , 1 ) ;
V_99 -> V_225 ( V_2 ) ;
V_40 -> exit ( V_2 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
continue;
V_227 = F_73 ( V_27 , V_5 -> V_20 ) ;
F_74 ( V_227 ) ;
}
F_32 ( L_31 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_32 ( L_32 ) ;
if ( ! F_62 ( V_2 -> V_27 ) )
return;
F_72 ( V_2 ) ;
F_56 ( V_2 ) ;
F_58 ( V_2 ) ;
F_71 ( V_2 ) ;
F_32 ( L_33 ) ;
}
static void F_76 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_34 ( V_97 ,
struct V_1 ,
V_79 ) ;
F_77 () ;
F_75 ( V_2 ) ;
F_78 () ;
}
static void F_79 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_34 ( V_97 ,
struct V_1 ,
V_92 ) ;
struct V_230 V_231 ;
T_2 V_232 ;
unsigned long V_210 ;
if ( V_2 -> V_89 ) {
V_232 = F_80 ( & V_2 -> V_233 ,
V_2 -> V_89 ) ;
memset ( & V_231 , 0 , sizeof( V_231 ) ) ;
V_231 . V_234 = F_81 ( V_232 ) ;
F_82 ( V_2 -> V_235 , & V_231 ) ;
}
F_83 ( V_2 -> V_235 ) ;
F_63 ( & V_2 -> V_236 , V_210 ) ;
V_2 -> V_235 = NULL ;
F_67 ( & V_2 -> V_236 , V_210 ) ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_237 * V_237 )
{
if ( F_85 ( V_237 -> V_238 , & V_2 -> V_239 ,
sizeof( V_2 -> V_239 ) ) )
return - V_240 ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_237 * V_237 )
{
struct V_241 V_242 ;
unsigned int V_243 ;
if ( F_87 ( & V_242 , V_237 -> V_238 , sizeof( V_242 ) ) )
return - V_240 ;
if ( V_242 . V_210 )
return - V_47 ;
V_243 = 0 ;
switch ( V_242 . V_244 ) {
case V_245 :
break;
case V_246 :
F_88 ( V_243 , V_247 , V_248 , 1 ) ;
break;
default:
return - V_249 ;
}
switch ( V_242 . V_250 ) {
case V_251 :
break;
case V_252 :
F_88 ( V_243 , V_247 , V_253 , 1 ) ;
F_88 ( V_243 , V_247 , V_248 , 1 ) ;
break;
case V_254 :
F_88 ( V_243 , V_247 , V_255 , 1 ) ;
case V_256 :
F_88 ( V_243 , V_247 , V_257 , 1 ) ;
F_88 ( V_243 , V_247 , V_258 , 1 ) ;
F_88 ( V_243 , V_247 , V_259 , 1 ) ;
F_88 ( V_243 , V_247 , V_248 , 1 ) ;
break;
case V_260 :
F_88 ( V_243 , V_247 , V_255 , 1 ) ;
case V_261 :
F_88 ( V_243 , V_247 , V_257 , 1 ) ;
F_88 ( V_243 , V_247 , V_258 , 1 ) ;
F_88 ( V_243 , V_247 , V_262 , 1 ) ;
F_88 ( V_243 , V_247 , V_248 , 1 ) ;
break;
case V_263 :
F_88 ( V_243 , V_247 , V_255 , 1 ) ;
case V_264 :
F_88 ( V_243 , V_247 , V_257 , 1 ) ;
F_88 ( V_243 , V_247 , V_258 , 1 ) ;
F_88 ( V_243 , V_247 , V_262 , 1 ) ;
F_88 ( V_243 , V_247 , V_265 , 1 ) ;
F_88 ( V_243 , V_247 , V_248 , 1 ) ;
break;
case V_266 :
F_88 ( V_243 , V_247 , V_267 , 1 ) ;
F_88 ( V_243 , V_247 , V_259 , 1 ) ;
F_88 ( V_243 , V_247 , V_248 , 1 ) ;
break;
case V_268 :
F_88 ( V_243 , V_247 , V_267 , 1 ) ;
F_88 ( V_243 , V_247 , V_262 , 1 ) ;
F_88 ( V_243 , V_247 , V_248 , 1 ) ;
break;
case V_269 :
F_88 ( V_243 , V_247 , V_267 , 1 ) ;
F_88 ( V_243 , V_247 , V_265 , 1 ) ;
F_88 ( V_243 , V_247 , V_262 , 1 ) ;
F_88 ( V_243 , V_247 , V_248 , 1 ) ;
break;
case V_270 :
F_88 ( V_243 , V_247 , V_255 , 1 ) ;
F_88 ( V_243 , V_247 , V_271 , 1 ) ;
F_88 ( V_243 , V_247 , V_257 , 1 ) ;
F_88 ( V_243 , V_247 , V_258 , 1 ) ;
F_88 ( V_243 , V_247 , V_259 , 1 ) ;
F_88 ( V_243 , V_247 , V_248 , 1 ) ;
break;
case V_272 :
F_88 ( V_243 , V_247 , V_255 , 1 ) ;
F_88 ( V_243 , V_247 , V_271 , 1 ) ;
F_88 ( V_243 , V_247 , V_257 , 1 ) ;
F_88 ( V_243 , V_247 , V_258 , 1 ) ;
F_88 ( V_243 , V_247 , V_262 , 1 ) ;
F_88 ( V_243 , V_247 , V_248 , 1 ) ;
break;
case V_273 :
F_88 ( V_243 , V_247 , V_255 , 1 ) ;
F_88 ( V_243 , V_247 , V_271 , 1 ) ;
F_88 ( V_243 , V_247 , V_257 , 1 ) ;
F_88 ( V_243 , V_247 , V_258 , 1 ) ;
F_88 ( V_243 , V_247 , V_265 , 1 ) ;
F_88 ( V_243 , V_247 , V_262 , 1 ) ;
F_88 ( V_243 , V_247 , V_248 , 1 ) ;
break;
default:
return - V_249 ;
}
V_2 -> V_40 . V_274 ( V_2 , V_243 ) ;
memcpy ( & V_2 -> V_239 , & V_242 , sizeof( V_242 ) ) ;
return 0 ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_275 * V_276 ,
struct V_277 * V_278 )
{
unsigned long V_210 ;
if ( F_23 ( V_278 -> V_279 , V_280 , V_281 ) ) {
F_63 ( & V_2 -> V_236 , V_210 ) ;
if ( V_2 -> V_235 ) {
F_88 ( V_278 -> V_279 ,
V_280 , V_281 , 0 ) ;
} else {
V_2 -> V_235 = F_90 ( V_276 ) ;
F_91 ( V_276 ) -> V_282 |= V_283 ;
}
F_67 ( & V_2 -> V_236 , V_210 ) ;
}
if ( ! F_23 ( V_278 -> V_279 , V_280 , V_281 ) )
F_92 ( V_276 ) ;
}
static void F_93 ( struct V_275 * V_276 , struct V_277 * V_278 )
{
if ( F_94 ( V_276 ) )
V_278 -> V_284 = F_95 ( V_276 ) ;
}
static int F_96 ( struct V_275 * V_276 , struct V_277 * V_278 )
{
int V_11 ;
if ( ! F_23 ( V_278 -> V_279 , V_280 ,
V_285 ) )
return 0 ;
V_11 = F_97 ( V_276 , 0 ) ;
if ( V_11 )
return V_11 ;
V_278 -> V_286 = F_98 ( V_276 ) + F_99 ( V_276 ) ;
V_278 -> V_287 = F_99 ( V_276 ) ;
V_278 -> V_288 = V_276 -> V_289 - V_278 -> V_286 ;
V_278 -> V_290 = F_91 ( V_276 ) -> V_291 ;
F_32 ( L_34 , V_278 -> V_286 ) ;
F_32 ( L_35 ,
V_278 -> V_287 , V_278 -> V_288 ) ;
F_32 ( L_36 , V_278 -> V_290 ) ;
V_278 -> V_292 = F_91 ( V_276 ) -> V_293 ;
V_278 -> V_294 += ( V_278 -> V_292 - 1 ) * V_278 -> V_286 ;
return 0 ;
}
static int F_100 ( struct V_275 * V_276 )
{
if ( V_276 -> V_295 != V_296 )
return 0 ;
if ( ! F_101 ( V_276 ) )
return 0 ;
F_32 ( L_37 ) ;
return 1 ;
}
static void F_102 ( struct V_1 * V_2 ,
struct V_6 * V_33 , struct V_275 * V_276 ,
struct V_277 * V_278 )
{
struct V_297 * V_298 ;
unsigned int V_299 ;
unsigned int V_289 ;
unsigned int V_10 ;
V_278 -> V_276 = V_276 ;
V_299 = 0 ;
V_278 -> V_34 = 0 ;
V_278 -> V_292 = 1 ;
V_278 -> V_294 = V_276 -> V_289 ;
if ( F_100 ( V_276 ) ) {
if ( F_91 ( V_276 ) -> V_291 != V_33 -> V_37 . V_300 ) {
V_299 = 1 ;
V_278 -> V_34 ++ ;
}
V_278 -> V_34 ++ ;
F_88 ( V_278 -> V_279 , V_280 ,
V_285 , 1 ) ;
F_88 ( V_278 -> V_279 , V_280 ,
V_301 , 1 ) ;
} else if ( V_276 -> V_295 == V_296 )
F_88 ( V_278 -> V_279 , V_280 ,
V_301 , 1 ) ;
if ( F_94 ( V_276 ) ) {
if ( F_95 ( V_276 ) != V_33 -> V_37 . V_302 )
if ( ! V_299 ) {
V_299 = 1 ;
V_278 -> V_34 ++ ;
}
F_88 ( V_278 -> V_279 , V_280 ,
V_303 , 1 ) ;
}
if ( ( F_91 ( V_276 ) -> V_282 & V_304 ) &&
( V_2 -> V_239 . V_244 == V_246 ) )
F_88 ( V_278 -> V_279 , V_280 ,
V_281 , 1 ) ;
for ( V_289 = F_103 ( V_276 ) ; V_289 ; ) {
V_278 -> V_34 ++ ;
V_289 -= F_104 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
for ( V_10 = 0 ; V_10 < F_91 ( V_276 ) -> V_305 ; V_10 ++ ) {
V_298 = & F_91 ( V_276 ) -> V_306 [ V_10 ] ;
for ( V_289 = F_105 ( V_298 ) ; V_289 ; ) {
V_278 -> V_34 ++ ;
V_289 -= F_104 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
}
}
static int F_106 ( struct V_43 * V_27 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
struct V_199 * V_200 = & V_2 -> V_200 ;
int V_11 ;
F_32 ( L_38 ) ;
V_11 = F_59 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_107 ( V_2 -> V_307 ) ;
if ( V_11 ) {
F_16 ( V_27 , L_39 ) ;
return V_11 ;
}
V_11 = F_107 ( V_2 -> V_308 ) ;
if ( V_11 ) {
F_16 ( V_27 , L_40 ) ;
goto V_309;
}
V_11 = F_15 ( V_27 , V_27 -> V_44 ) ;
if ( V_11 < 0 )
goto V_310;
V_2 -> V_45 = V_11 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 )
goto V_310;
V_11 = V_200 -> V_311 ( V_2 ) ;
if ( V_11 )
goto V_312;
F_108 ( & V_2 -> V_98 , F_33 ) ;
F_108 ( & V_2 -> V_79 , F_76 ) ;
F_108 ( & V_2 -> V_92 , F_79 ) ;
F_37 ( V_2 ) ;
V_11 = F_71 ( V_2 ) ;
if ( V_11 )
goto V_313;
F_109 ( V_314 , & V_2 -> V_315 ) ;
F_32 ( L_41 ) ;
return 0 ;
V_313:
V_200 -> V_316 ( V_2 ) ;
V_312:
F_9 ( V_2 ) ;
V_310:
F_110 ( V_2 -> V_308 ) ;
V_309:
F_110 ( V_2 -> V_307 ) ;
return V_11 ;
}
static int F_111 ( struct V_43 * V_27 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
struct V_199 * V_200 = & V_2 -> V_200 ;
F_32 ( L_42 ) ;
F_72 ( V_2 ) ;
V_200 -> V_316 ( V_2 ) ;
F_9 ( V_2 ) ;
F_110 ( V_2 -> V_308 ) ;
F_110 ( V_2 -> V_307 ) ;
F_112 ( V_314 , & V_2 -> V_315 ) ;
F_32 ( L_43 ) ;
return 0 ;
}
static int F_113 ( struct V_275 * V_276 , struct V_43 * V_27 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_199 * V_200 = & V_2 -> V_200 ;
struct V_3 * V_5 ;
struct V_6 * V_33 ;
struct V_277 * V_278 ;
struct V_226 * V_227 ;
int V_11 ;
F_32 ( L_44 , V_276 -> V_289 ) ;
V_5 = V_2 -> V_5 + V_276 -> V_317 ;
V_227 = F_73 ( V_27 , V_5 -> V_20 ) ;
V_33 = V_5 -> V_7 ;
V_278 = & V_33 -> V_318 ;
V_11 = V_319 ;
if ( V_276 -> V_289 == 0 ) {
F_114 ( V_2 , V_320 , V_27 ,
L_45 ) ;
F_83 ( V_276 ) ;
goto V_321;
}
memset ( V_278 , 0 , sizeof( * V_278 ) ) ;
F_102 ( V_2 , V_33 , V_276 , V_278 ) ;
V_11 = F_12 ( V_5 , V_33 , V_278 -> V_34 ) ;
if ( V_11 )
goto V_321;
V_11 = F_96 ( V_276 , V_278 ) ;
if ( V_11 ) {
F_114 ( V_2 , V_320 , V_27 ,
L_46 ) ;
F_83 ( V_276 ) ;
goto V_321;
}
F_93 ( V_276 , V_278 ) ;
if ( ! V_200 -> V_322 ( V_5 , V_276 ) ) {
F_83 ( V_276 ) ;
goto V_321;
}
F_89 ( V_2 , V_276 , V_278 ) ;
F_115 ( V_227 , V_278 -> V_294 ) ;
V_40 -> V_323 ( V_5 ) ;
if ( F_116 ( V_2 ) )
F_117 ( V_27 , V_276 , true ) ;
F_12 ( V_5 , V_33 , V_324 ) ;
V_11 = V_319 ;
V_321:
return V_11 ;
}
static void F_118 ( struct V_43 * V_27 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
F_32 ( L_47 ) ;
V_40 -> V_325 ( V_2 ) ;
F_32 ( L_48 ) ;
}
static int F_119 ( struct V_43 * V_27 , void * V_326 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_327 * V_328 = V_326 ;
F_32 ( L_49 ) ;
if ( ! F_120 ( V_328 -> V_329 ) )
return - V_330 ;
memcpy ( V_27 -> V_331 , V_328 -> V_329 , V_27 -> V_332 ) ;
V_40 -> V_333 ( V_2 , V_27 -> V_331 ) ;
F_32 ( L_50 ) ;
return 0 ;
}
static int F_121 ( struct V_43 * V_27 , struct V_237 * V_237 , int V_334 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
int V_11 ;
switch ( V_334 ) {
case V_335 :
V_11 = F_84 ( V_2 , V_237 ) ;
break;
case V_336 :
V_11 = F_86 ( V_2 , V_237 ) ;
break;
default:
V_11 = - V_337 ;
}
return V_11 ;
}
static int F_122 ( struct V_43 * V_27 , int V_44 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
int V_11 ;
F_32 ( L_51 ) ;
V_11 = F_15 ( V_27 , V_44 ) ;
if ( V_11 < 0 )
return V_11 ;
V_2 -> V_45 = V_11 ;
V_27 -> V_44 = V_44 ;
F_75 ( V_2 ) ;
F_32 ( L_52 ) ;
return 0 ;
}
static void F_123 ( struct V_43 * V_27 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
F_124 ( V_27 , L_53 ) ;
F_26 ( & V_2 -> V_79 ) ;
}
static struct V_338 * F_125 ( struct V_43 * V_27 ,
struct V_338 * V_339 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
struct V_340 * V_341 = & V_2 -> V_342 ;
F_32 ( L_54 , V_343 ) ;
V_2 -> V_40 . V_344 ( V_2 ) ;
V_339 -> V_345 = V_341 -> V_346 ;
V_339 -> V_347 = V_341 -> V_348 ;
V_339 -> V_349 = V_341 -> V_346 -
V_341 -> V_350 -
V_341 -> V_351 -
V_341 -> V_352 ;
V_339 -> V_353 = V_341 -> V_351 ;
V_339 -> V_354 = V_341 -> V_355 ;
V_339 -> V_356 = V_341 -> V_357 ;
V_339 -> V_358 = V_341 -> V_359 ;
V_339 -> V_292 = V_341 -> V_360 ;
V_339 -> V_294 = V_341 -> V_361 ;
V_339 -> V_362 = V_341 -> V_360 - V_341 -> V_363 ;
V_339 -> V_364 = V_27 -> V_365 . V_364 ;
F_32 ( L_55 , V_343 ) ;
return V_339 ;
}
static int F_126 ( struct V_43 * V_27 , T_3 V_366 ,
T_4 V_367 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
F_32 ( L_54 , V_343 ) ;
F_112 ( V_367 , V_2 -> V_368 ) ;
V_40 -> V_369 ( V_2 ) ;
F_32 ( L_55 , V_343 ) ;
return 0 ;
}
static int F_127 ( struct V_43 * V_27 , T_3 V_366 ,
T_4 V_367 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
F_32 ( L_54 , V_343 ) ;
F_109 ( V_367 , V_2 -> V_368 ) ;
V_40 -> V_369 ( V_2 ) ;
F_32 ( L_55 , V_343 ) ;
return 0 ;
}
static void F_128 ( struct V_43 * V_27 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
struct V_3 * V_5 ;
unsigned int V_10 ;
F_32 ( L_56 ) ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ )
F_29 ( V_5 -> V_29 , V_5 ) ;
} else {
F_129 ( V_2 -> V_185 ) ;
F_20 ( V_2 -> V_185 , V_2 ) ;
F_130 ( V_2 -> V_185 ) ;
}
F_32 ( L_57 ) ;
}
static int F_131 ( struct V_43 * V_27 , T_5 V_370 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
unsigned int V_371 , V_372 ;
T_5 V_10 ;
if ( V_370 && ( V_370 != V_2 -> V_109 . V_161 ) )
return - V_47 ;
if ( V_370 ) {
F_132 ( V_27 , V_370 ) ;
for ( V_10 = 0 , V_372 = 0 , V_371 = 0 ; V_10 < V_370 ; V_10 ++ ) {
while ( ( V_372 < V_2 -> V_373 ) &&
( V_2 -> V_374 [ V_372 ] == V_10 ) )
V_372 ++ ;
F_7 ( V_2 , V_31 , V_27 , L_58 ,
V_10 , V_371 , V_372 - 1 ) ;
F_133 ( V_27 , V_10 , V_372 - V_371 , V_371 ) ;
V_371 = V_372 ;
}
} else {
F_134 ( V_27 ) ;
}
return 0 ;
}
static int F_135 ( struct V_43 * V_27 ,
T_6 V_375 )
{
struct V_1 * V_2 = F_61 ( V_27 ) ;
struct V_54 * V_40 = & V_2 -> V_40 ;
T_6 V_376 , V_377 , V_378 , V_379 ;
int V_11 = 0 ;
V_376 = V_2 -> V_380 & V_381 ;
V_377 = V_2 -> V_380 & V_382 ;
V_378 = V_2 -> V_380 & V_383 ;
V_379 = V_2 -> V_380 & V_384 ;
if ( ( V_375 & V_381 ) && ! V_376 )
V_11 = V_40 -> V_385 ( V_2 ) ;
else if ( ! ( V_375 & V_381 ) && V_376 )
V_11 = V_40 -> V_386 ( V_2 ) ;
if ( V_11 )
return V_11 ;
if ( ( V_375 & V_382 ) && ! V_377 )
V_40 -> V_387 ( V_2 ) ;
else if ( ! ( V_375 & V_382 ) && V_377 )
V_40 -> V_388 ( V_2 ) ;
if ( ( V_375 & V_383 ) && ! V_378 )
V_40 -> V_389 ( V_2 ) ;
else if ( ! ( V_375 & V_383 ) && V_378 )
V_40 -> V_390 ( V_2 ) ;
if ( ( V_375 & V_384 ) && ! V_379 )
V_40 -> V_391 ( V_2 ) ;
else if ( ! ( V_375 & V_384 ) && V_379 )
V_40 -> V_392 ( V_2 ) ;
V_2 -> V_380 = V_375 ;
F_32 ( L_59 ) ;
return 0 ;
}
struct V_393 * F_136 ( void )
{
return (struct V_393 * ) & V_394 ;
}
static void F_137 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_199 * V_200 = & V_2 -> V_200 ;
struct V_6 * V_33 = V_5 -> V_8 ;
struct V_201 * V_202 ;
while ( V_33 -> V_36 != V_33 -> V_35 ) {
V_202 = F_57 ( V_33 , V_33 -> V_36 ) ;
V_200 -> V_204 ( V_2 , V_202 ) ;
if ( V_200 -> V_395 ( V_2 , V_33 , V_202 ) )
break;
V_40 -> V_396 ( V_2 , V_202 , V_33 -> V_36 ) ;
V_33 -> V_36 ++ ;
}
F_138 () ;
V_202 = F_57 ( V_33 , V_33 -> V_36 - 1 ) ;
F_27 ( V_5 , V_397 ,
F_139 ( V_202 -> V_398 ) ) ;
}
static struct V_275 * F_140 ( struct V_1 * V_2 ,
struct V_94 * V_74 ,
struct V_201 * V_202 ,
unsigned int V_289 )
{
struct V_275 * V_276 ;
T_5 * V_278 ;
unsigned int V_399 ;
V_276 = F_141 ( V_74 , V_202 -> V_400 . V_401 . V_402 ) ;
if ( ! V_276 )
return NULL ;
F_142 ( V_2 -> V_184 , V_202 -> V_400 . V_401 . V_403 ,
V_202 -> V_400 . V_401 . V_404 ,
V_202 -> V_400 . V_401 . V_402 , V_405 ) ;
V_278 = F_143 ( V_202 -> V_400 . V_401 . V_406 . V_407 ) +
V_202 -> V_400 . V_401 . V_406 . V_408 ;
V_399 = ( V_202 -> V_400 . V_409 ) ? V_202 -> V_400 . V_409 : V_289 ;
V_399 = F_144 ( V_202 -> V_400 . V_401 . V_402 , V_399 ) ;
F_145 ( V_276 , V_278 , V_399 ) ;
F_146 ( V_276 , V_399 ) ;
V_289 -= V_399 ;
if ( V_289 ) {
F_142 ( V_2 -> V_184 ,
V_202 -> V_400 . V_410 . V_403 ,
V_202 -> V_400 . V_410 . V_404 ,
V_202 -> V_400 . V_410 . V_402 ,
V_405 ) ;
F_147 ( V_276 , F_91 ( V_276 ) -> V_305 ,
V_202 -> V_400 . V_410 . V_406 . V_407 ,
V_202 -> V_400 . V_410 . V_406 . V_408 ,
V_289 , V_202 -> V_400 . V_410 . V_402 ) ;
V_202 -> V_400 . V_410 . V_406 . V_407 = NULL ;
}
return V_276 ;
}
static int F_148 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_199 * V_200 = & V_2 -> V_200 ;
struct V_6 * V_33 = V_5 -> V_7 ;
struct V_201 * V_202 ;
struct V_411 * V_412 ;
struct V_43 * V_27 = V_2 -> V_27 ;
struct V_226 * V_227 ;
int V_413 = 0 ;
unsigned int V_292 = 0 , V_294 = 0 ;
unsigned int V_35 ;
F_32 ( L_60 ) ;
if ( ! V_33 )
return 0 ;
V_35 = V_33 -> V_35 ;
F_149 () ;
V_227 = F_73 ( V_27 , V_5 -> V_20 ) ;
while ( ( V_413 < V_414 ) &&
( V_33 -> V_36 != V_35 ) ) {
V_202 = F_57 ( V_33 , V_33 -> V_36 ) ;
V_412 = V_202 -> V_412 ;
if ( ! V_40 -> V_415 ( V_412 ) )
break;
F_150 () ;
if ( F_151 ( V_2 ) )
F_152 ( V_2 , V_33 , V_33 -> V_36 , 1 , 0 ) ;
if ( V_40 -> V_416 ( V_412 ) ) {
V_292 += V_202 -> V_37 . V_417 ;
V_294 += V_202 -> V_37 . V_418 ;
}
V_200 -> V_204 ( V_2 , V_202 ) ;
V_40 -> V_419 ( V_202 ) ;
V_413 ++ ;
V_33 -> V_36 ++ ;
}
if ( ! V_413 )
return 0 ;
F_153 ( V_227 , V_292 , V_294 ) ;
if ( ( V_33 -> V_37 . V_38 == 1 ) &&
( F_10 ( V_33 ) > V_420 ) ) {
V_33 -> V_37 . V_38 = 0 ;
F_154 ( V_227 ) ;
}
F_32 ( L_61 , V_413 ) ;
return V_413 ;
}
static int F_155 ( struct V_3 * V_5 , int V_421 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_54 * V_40 = & V_2 -> V_40 ;
struct V_6 * V_33 = V_5 -> V_8 ;
struct V_201 * V_202 ;
struct V_277 * V_278 ;
struct V_43 * V_27 = V_2 -> V_27 ;
struct V_94 * V_74 ;
struct V_275 * V_276 ;
struct V_230 * V_231 ;
unsigned int V_422 , error , V_423 , V_424 ;
unsigned int V_289 , V_425 , V_426 ;
unsigned int V_427 = 0 ;
int V_428 = 0 ;
F_32 ( L_62 , V_421 ) ;
if ( ! V_33 )
return 0 ;
V_422 = 0 ;
V_423 = 0 ;
V_74 = ( V_2 -> V_25 ) ? & V_5 -> V_74 : & V_2 -> V_74 ;
V_202 = F_57 ( V_33 , V_33 -> V_35 ) ;
V_278 = & V_33 -> V_318 ;
while ( V_428 < V_421 ) {
F_32 ( L_63 , V_33 -> V_35 ) ;
if ( ! V_427 && V_202 -> V_429 ) {
V_276 = V_202 -> V_430 . V_276 ;
error = V_202 -> V_430 . error ;
V_289 = V_202 -> V_430 . V_289 ;
} else {
memset ( V_278 , 0 , sizeof( * V_278 ) ) ;
V_276 = NULL ;
error = 0 ;
V_289 = 0 ;
}
V_431:
V_202 = F_57 ( V_33 , V_33 -> V_35 ) ;
if ( F_11 ( V_33 ) > ( V_432 >> 3 ) )
F_137 ( V_5 ) ;
if ( V_40 -> V_433 ( V_5 ) )
break;
V_427 ++ ;
V_33 -> V_35 ++ ;
V_422 = F_23 ( V_278 -> V_279 ,
V_434 ,
V_435 ) ;
V_423 = F_23 ( V_278 -> V_279 ,
V_434 ,
V_436 ) ;
V_424 = F_23 ( V_278 -> V_279 ,
V_434 ,
V_437 ) ;
if ( ( V_422 || V_423 ) && error )
goto V_431;
if ( error || V_278 -> V_438 ) {
if ( V_278 -> V_438 )
F_114 ( V_2 , V_439 , V_27 ,
L_64 ) ;
F_156 ( V_276 ) ;
goto V_440;
}
if ( ! V_424 ) {
V_425 = V_202 -> V_400 . V_289 - V_289 ;
V_289 += V_425 ;
if ( V_425 && ! V_276 ) {
V_276 = F_140 ( V_2 , V_74 , V_202 ,
V_425 ) ;
if ( ! V_276 )
error = 1 ;
} else if ( V_425 ) {
F_142 ( V_2 -> V_184 ,
V_202 -> V_400 . V_410 . V_403 ,
V_202 -> V_400 . V_410 . V_404 ,
V_202 -> V_400 . V_410 . V_402 ,
V_405 ) ;
F_147 ( V_276 , F_91 ( V_276 ) -> V_305 ,
V_202 -> V_400 . V_410 . V_406 . V_407 ,
V_202 -> V_400 . V_410 . V_406 . V_408 ,
V_425 ,
V_202 -> V_400 . V_410 . V_402 ) ;
V_202 -> V_400 . V_410 . V_406 . V_407 = NULL ;
}
}
if ( V_422 || V_423 )
goto V_431;
if ( ! V_276 )
goto V_440;
V_426 = V_27 -> V_44 + V_48 ;
if ( ! ( V_27 -> V_375 & V_383 ) &&
( V_276 -> V_441 == F_157 ( V_442 ) ) )
V_426 += V_50 ;
if ( V_276 -> V_289 > V_426 ) {
F_114 ( V_2 , V_439 , V_27 ,
L_65 ) ;
F_156 ( V_276 ) ;
goto V_440;
}
if ( F_116 ( V_2 ) )
F_117 ( V_27 , V_276 , false ) ;
F_158 ( V_276 ) ;
if ( F_23 ( V_278 -> V_279 ,
V_434 , V_443 ) )
V_276 -> V_295 = V_444 ;
if ( F_23 ( V_278 -> V_279 ,
V_434 , V_303 ) )
F_159 ( V_276 , F_157 ( V_442 ) ,
V_278 -> V_284 ) ;
if ( F_23 ( V_278 -> V_279 ,
V_434 , V_445 ) ) {
T_2 V_232 ;
V_232 = F_80 ( & V_2 -> V_233 ,
V_278 -> V_446 ) ;
V_231 = F_160 ( V_276 ) ;
V_231 -> V_234 = F_81 ( V_232 ) ;
}
if ( F_23 ( V_278 -> V_279 ,
V_434 , V_447 ) )
F_161 ( V_276 , V_278 -> V_448 ,
V_278 -> V_449 ) ;
V_276 -> V_184 = V_27 ;
V_276 -> V_441 = F_162 ( V_276 , V_27 ) ;
F_163 ( V_276 , V_5 -> V_20 ) ;
F_164 ( V_276 , V_74 ) ;
F_165 ( V_74 , V_276 ) ;
V_440:
V_428 ++ ;
}
if ( V_427 && ( V_422 || V_423 ) ) {
V_202 = F_57 ( V_33 , V_33 -> V_35 ) ;
V_202 -> V_429 = 1 ;
V_202 -> V_430 . V_276 = V_276 ;
V_202 -> V_430 . V_289 = V_289 ;
V_202 -> V_430 . error = error ;
}
F_32 ( L_66 , V_428 ) ;
return V_428 ;
}
static int V_180 ( struct V_94 * V_74 , int V_421 )
{
struct V_3 * V_5 = F_34 ( V_74 , struct V_3 ,
V_74 ) ;
int V_413 = 0 ;
F_32 ( L_67 , V_421 ) ;
F_148 ( V_5 ) ;
V_413 = F_155 ( V_5 , V_421 ) ;
if ( V_413 < V_421 ) {
F_166 ( V_74 ) ;
F_130 ( V_5 -> V_29 ) ;
}
F_32 ( L_68 , V_413 ) ;
return V_413 ;
}
static int V_182 ( struct V_94 * V_74 , int V_421 )
{
struct V_1 * V_2 = F_34 ( V_74 , struct V_1 ,
V_74 ) ;
struct V_3 * V_5 ;
int V_450 ;
int V_413 , V_451 ;
unsigned int V_10 ;
F_32 ( L_69 , V_421 ) ;
V_413 = 0 ;
V_450 = V_421 / V_2 -> V_17 ;
do {
V_451 = V_413 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_32 ; V_10 ++ , V_5 ++ ) {
F_148 ( V_5 ) ;
if ( V_450 > ( V_421 - V_413 ) )
V_450 = V_421 - V_413 ;
V_413 += F_155 ( V_5 , V_450 ) ;
}
} while ( ( V_413 < V_421 ) && ( V_413 != V_451 ) );
if ( V_413 < V_421 ) {
F_166 ( V_74 ) ;
F_18 ( V_2 ) ;
}
F_32 ( L_70 , V_413 ) ;
return V_413 ;
}
void F_152 ( struct V_1 * V_2 , struct V_6 * V_33 ,
unsigned int V_452 , unsigned int V_9 , unsigned int V_453 )
{
struct V_201 * V_202 ;
struct V_411 * V_412 ;
while ( V_9 -- ) {
V_202 = F_57 ( V_33 , V_452 ) ;
V_412 = V_202 -> V_412 ;
F_167 ( V_2 -> V_27 ,
L_71 , V_452 ,
( V_453 == 1 ) ? L_72 : L_73 ,
F_168 ( V_412 -> V_454 ) ,
F_168 ( V_412 -> V_455 ) ,
F_168 ( V_412 -> V_456 ) ,
F_168 ( V_412 -> V_457 ) ) ;
V_452 ++ ;
}
}
void F_169 ( struct V_1 * V_2 , struct V_6 * V_33 ,
unsigned int V_452 )
{
struct V_201 * V_202 ;
struct V_411 * V_412 ;
V_202 = F_57 ( V_33 , V_452 ) ;
V_412 = V_202 -> V_412 ;
F_167 ( V_2 -> V_27 ,
L_74 ,
V_452 , F_168 ( V_412 -> V_454 ) , F_168 ( V_412 -> V_455 ) ,
F_168 ( V_412 -> V_456 ) , F_168 ( V_412 -> V_457 ) ) ;
}
void F_117 ( struct V_43 * V_27 , struct V_275 * V_276 , bool V_458 )
{
struct V_459 * V_460 = (struct V_459 * ) V_276 -> V_63 ;
unsigned char * V_410 = V_276 -> V_63 ;
unsigned char V_461 [ 128 ] ;
unsigned int V_10 , V_203 ;
F_167 ( V_27 , L_75 ) ;
F_167 ( V_27 , L_76 ,
( V_458 ? L_77 : L_78 ) , V_276 -> V_289 ) ;
F_167 ( V_27 , L_79 , V_460 -> V_462 ) ;
F_167 ( V_27 , L_80 , V_460 -> V_463 ) ;
F_167 ( V_27 , L_81 , F_170 ( V_460 -> V_464 ) ) ;
for ( V_10 = 0 , V_203 = 0 ; V_10 < V_276 -> V_289 ; ) {
V_203 += snprintf ( V_461 + V_203 , sizeof( V_461 ) - V_203 , L_82 ,
V_410 [ V_10 ++ ] ) ;
if ( ( V_10 % 32 ) == 0 ) {
F_167 ( V_27 , L_83 , V_10 - 32 , V_461 ) ;
V_203 = 0 ;
} else if ( ( V_10 % 16 ) == 0 ) {
V_461 [ V_203 ++ ] = ' ' ;
V_461 [ V_203 ++ ] = ' ' ;
} else if ( ( V_10 % 4 ) == 0 ) {
V_461 [ V_203 ++ ] = ' ' ;
}
}
if ( V_10 % 32 )
F_167 ( V_27 , L_83 , V_10 - ( V_10 % 32 ) , V_461 ) ;
F_167 ( V_27 , L_75 ) ;
}

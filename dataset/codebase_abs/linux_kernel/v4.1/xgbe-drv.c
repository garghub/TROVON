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
F_7 ( L_3 ,
V_5 -> V_19 , V_5 -> V_20 , V_5 -> V_21 ,
V_5 -> V_29 , V_5 -> V_7 , V_5 -> V_8 ) ;
}
V_2 -> V_5 = V_4 ;
V_2 -> V_31 = V_9 ;
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
V_2 -> V_31 = 0 ;
}
static inline unsigned int F_10 ( struct V_6 * V_32 )
{
return ( V_32 -> V_33 - ( V_32 -> V_34 - V_32 -> V_35 ) ) ;
}
static inline unsigned int F_11 ( struct V_6 * V_32 )
{
return ( V_32 -> V_34 - V_32 -> V_35 ) ;
}
static int F_12 ( struct V_3 * V_5 ,
struct V_6 * V_32 , unsigned int V_9 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
if ( V_9 > F_10 ( V_32 ) ) {
F_7 ( L_4 ) ;
F_13 ( V_2 -> V_27 , V_5 -> V_20 ) ;
V_32 -> V_36 . V_37 = 1 ;
if ( V_32 -> V_36 . V_38 )
V_2 -> V_39 . V_40 ( V_5 , V_32 ) ;
return V_41 ;
}
return 0 ;
}
static int F_14 ( struct V_42 * V_27 , unsigned int V_43 )
{
unsigned int V_44 ;
if ( V_43 > V_45 ) {
F_15 ( V_27 , L_5 ) ;
return - V_46 ;
}
V_44 = V_43 + V_47 + V_48 + V_49 ;
V_44 = F_16 ( V_44 , V_50 , V_51 ) ;
V_44 = ( V_44 + V_52 - 1 ) &
~ ( V_52 - 1 ) ;
return V_44 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_3 * V_5 ;
enum V_54 V_55 ;
unsigned int V_10 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( V_5 -> V_7 && V_5 -> V_8 )
V_55 = V_56 ;
else if ( V_5 -> V_7 )
V_55 = V_57 ;
else if ( V_5 -> V_8 )
V_55 = V_58 ;
else
continue;
V_39 -> V_59 ( V_5 , V_55 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_3 * V_5 ;
enum V_54 V_55 ;
unsigned int V_10 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( V_5 -> V_7 && V_5 -> V_8 )
V_55 = V_56 ;
else if ( V_5 -> V_7 )
V_55 = V_57 ;
else if ( V_5 -> V_8 )
V_55 = V_58 ;
else
continue;
V_39 -> V_60 ( V_5 , V_55 ) ;
}
}
static T_1 F_19 ( int V_61 , void * V_62 )
{
struct V_1 * V_2 = V_62 ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_3 * V_5 ;
unsigned int V_63 , V_64 ;
unsigned int V_65 , V_66 ;
unsigned int V_10 ;
V_63 = F_20 ( V_2 , V_67 ) ;
if ( ! V_63 )
goto V_68;
F_7 ( L_6 , V_63 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ ) {
if ( ! ( V_63 & ( 1 << V_10 ) ) )
continue;
V_5 = V_2 -> V_5 + V_10 ;
V_64 = F_21 ( V_5 , V_69 ) ;
F_7 ( L_7 , V_10 , V_64 ) ;
if ( ! V_2 -> V_25 &&
( F_22 ( V_64 , V_69 , V_70 ) ||
F_22 ( V_64 , V_69 , V_71 ) ) ) {
if ( F_23 ( & V_2 -> V_72 ) ) {
F_18 ( V_2 ) ;
F_24 ( & V_2 -> V_72 ) ;
}
}
if ( F_22 ( V_64 , V_69 , V_73 ) )
F_25 ( & V_2 -> V_74 ) ;
F_26 ( V_5 , V_69 , V_64 ) ;
}
if ( F_22 ( V_63 , V_67 , V_75 ) ) {
V_65 = F_20 ( V_2 , V_76 ) ;
if ( F_22 ( V_65 , V_76 , V_77 ) )
V_39 -> V_78 ( V_2 ) ;
if ( F_22 ( V_65 , V_76 , V_79 ) )
V_39 -> V_80 ( V_2 ) ;
if ( F_22 ( V_65 , V_76 , V_81 ) ) {
V_66 = F_20 ( V_2 , V_82 ) ;
if ( F_22 ( V_66 , V_82 , V_83 ) ) {
V_2 -> V_84 =
V_39 -> V_85 ( V_2 ) ;
F_25 ( & V_2 -> V_86 ) ;
}
}
}
F_7 ( L_6 , F_20 ( V_2 , V_67 ) ) ;
V_68:
return V_87 ;
}
static T_1 F_27 ( int V_61 , void * V_62 )
{
struct V_3 * V_5 = V_62 ;
if ( F_23 ( & V_5 -> V_72 ) ) {
F_28 ( V_5 -> V_29 ) ;
F_24 ( & V_5 -> V_72 ) ;
}
return V_87 ;
}
static void F_29 ( unsigned long V_62 )
{
struct V_3 * V_5 = (struct V_3 * ) V_62 ;
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_88 * V_72 ;
F_7 ( L_8 ) ;
V_72 = ( V_2 -> V_25 ) ? & V_5 -> V_72 : & V_2 -> V_72 ;
if ( F_23 ( V_72 ) ) {
if ( V_2 -> V_25 )
F_28 ( V_5 -> V_29 ) ;
else
F_18 ( V_2 ) ;
F_24 ( V_72 ) ;
}
V_5 -> V_89 = 0 ;
F_7 ( L_9 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_7 ( L_10 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
break;
F_7 ( L_11 , V_5 -> V_19 ) ;
F_31 ( & V_5 -> V_90 , F_29 ,
( unsigned long ) V_5 ) ;
}
F_7 ( L_12 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_7 ( L_13 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
break;
F_7 ( L_14 , V_5 -> V_19 ) ;
F_33 ( & V_5 -> V_90 ) ;
}
F_7 ( L_15 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
unsigned int V_91 , V_92 , V_93 ;
struct V_94 * V_95 = & V_2 -> V_95 ;
F_7 ( L_16 ) ;
V_91 = F_20 ( V_2 , V_96 ) ;
V_92 = F_20 ( V_2 , V_97 ) ;
V_93 = F_20 ( V_2 , V_98 ) ;
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_95 -> V_99 = F_20 ( V_2 , V_100 ) ;
V_95 -> V_101 = F_22 ( V_91 , V_96 , V_102 ) ;
V_95 -> V_103 = F_22 ( V_91 , V_96 , V_104 ) ;
V_95 -> V_105 = F_22 ( V_91 , V_96 , V_106 ) ;
V_95 -> V_107 = F_22 ( V_91 , V_96 , V_108 ) ;
V_95 -> V_109 = F_22 ( V_91 , V_96 , V_110 ) ;
V_95 -> V_111 = F_22 ( V_91 , V_96 , V_112 ) ;
V_95 -> V_113 = F_22 ( V_91 , V_96 , V_114 ) ;
V_95 -> V_115 = F_22 ( V_91 , V_96 , V_116 ) ;
V_95 -> V_117 = F_22 ( V_91 , V_96 , V_118 ) ;
V_95 -> V_119 = F_22 ( V_91 , V_96 , V_120 ) ;
V_95 -> V_121 = F_22 ( V_91 , V_96 , V_122 ) ;
V_95 -> V_123 = F_22 ( V_91 , V_96 ,
V_124 ) ;
V_95 -> V_125 = F_22 ( V_91 , V_96 , V_126 ) ;
V_95 -> V_127 = F_22 ( V_91 , V_96 , V_128 ) ;
V_95 -> V_129 = F_22 ( V_92 , V_97 ,
V_130 ) ;
V_95 -> V_131 = F_22 ( V_92 , V_97 ,
V_132 ) ;
V_95 -> V_133 = F_22 ( V_92 , V_97 , V_134 ) ;
V_95 -> V_135 = F_22 ( V_92 , V_97 , V_136 ) ;
V_95 -> V_137 = F_22 ( V_92 , V_97 , V_138 ) ;
V_95 -> V_139 = F_22 ( V_92 , V_97 , V_140 ) ;
V_95 -> V_141 = F_22 ( V_92 , V_97 , V_142 ) ;
V_95 -> V_143 = F_22 ( V_92 , V_97 , V_144 ) ;
V_95 -> V_145 = F_22 ( V_92 , V_97 , V_146 ) ;
V_95 -> V_147 = F_22 ( V_92 , V_97 ,
V_148 ) ;
V_95 -> V_149 = F_22 ( V_92 , V_97 ,
V_150 ) ;
V_95 -> V_151 = F_22 ( V_93 , V_98 , V_152 ) ;
V_95 -> V_153 = F_22 ( V_93 , V_98 , V_154 ) ;
V_95 -> V_155 = F_22 ( V_93 , V_98 , V_156 ) ;
V_95 -> V_157 = F_22 ( V_93 , V_98 , V_158 ) ;
V_95 -> V_159 = F_22 ( V_93 , V_98 , V_160 ) ;
V_95 -> V_161 = F_22 ( V_93 , V_98 , V_162 ) ;
switch ( V_95 -> V_147 ) {
case 0 :
break;
case 1 :
V_95 -> V_147 = 64 ;
break;
case 2 :
V_95 -> V_147 = 128 ;
break;
case 3 :
V_95 -> V_147 = 256 ;
break;
}
switch ( V_95 -> V_133 ) {
case 0 :
V_95 -> V_133 = 32 ;
break;
case 1 :
V_95 -> V_133 = 40 ;
break;
case 2 :
V_95 -> V_133 = 48 ;
break;
default:
V_95 -> V_133 = 32 ;
}
V_95 -> V_151 ++ ;
V_95 -> V_153 ++ ;
V_95 -> V_155 ++ ;
V_95 -> V_157 ++ ;
V_95 -> V_145 ++ ;
F_7 ( L_17 ) ;
}
static void F_35 ( struct V_1 * V_2 , unsigned int V_163 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( V_163 )
F_36 ( V_2 -> V_27 , & V_5 -> V_72 ,
V_164 , V_165 ) ;
F_37 ( & V_5 -> V_72 ) ;
}
} else {
if ( V_163 )
F_36 ( V_2 -> V_27 , & V_2 -> V_72 ,
V_166 , V_165 ) ;
F_37 ( & V_2 -> V_72 ) ;
}
}
static void F_38 ( struct V_1 * V_2 , unsigned int V_167 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
F_39 ( & V_5 -> V_72 ) ;
if ( V_167 )
F_40 ( & V_5 -> V_72 ) ;
}
} else {
F_39 ( & V_2 -> V_72 ) ;
if ( V_167 )
F_40 ( & V_2 -> V_72 ) ;
}
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
struct V_42 * V_27 = V_2 -> V_27 ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_42 ( V_2 -> V_168 , V_2 -> V_169 , F_19 , 0 ,
V_27 -> V_19 , V_2 ) ;
if ( V_11 ) {
F_15 ( V_27 , L_18 ,
V_2 -> V_169 ) ;
return V_11 ;
}
if ( ! V_2 -> V_25 )
return 0 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
snprintf ( V_5 -> V_170 ,
sizeof( V_5 -> V_170 ) - 1 ,
L_19 , F_43 ( V_27 ) ,
V_5 -> V_20 ) ;
V_11 = F_42 ( V_2 -> V_168 , V_5 -> V_29 ,
F_27 , 0 ,
V_5 -> V_170 , V_5 ) ;
if ( V_11 ) {
F_15 ( V_27 , L_18 ,
V_5 -> V_29 ) ;
goto V_28;
}
}
return 0 ;
V_28:
for ( V_10 -- , V_5 -- ; V_10 < V_2 -> V_31 ; V_10 -- , V_5 -- )
F_44 ( V_2 -> V_168 , V_5 -> V_29 , V_5 ) ;
F_44 ( V_2 -> V_168 , V_2 -> V_169 , V_2 ) ;
return V_11 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_44 ( V_2 -> V_168 , V_2 -> V_169 , V_2 ) ;
if ( ! V_2 -> V_25 )
return;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ )
F_44 ( V_2 -> V_168 , V_5 -> V_29 , V_5 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
F_7 ( L_20 ) ;
V_2 -> V_171 = V_172 ;
V_2 -> V_173 = V_174 ;
V_39 -> V_175 ( V_2 ) ;
F_7 ( L_21 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
F_7 ( L_22 ) ;
V_2 -> V_176 = V_39 -> V_177 ( V_2 , V_178 ) ;
V_2 -> V_179 = V_178 ;
V_2 -> V_180 = V_181 ;
V_39 -> V_182 ( V_2 ) ;
F_7 ( L_23 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_183 * V_184 = & V_2 -> V_184 ;
struct V_3 * V_5 ;
struct V_6 * V_32 ;
struct V_185 * V_186 ;
unsigned int V_10 , V_187 ;
F_7 ( L_24 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
V_32 = V_5 -> V_7 ;
if ( ! V_32 )
break;
for ( V_187 = 0 ; V_187 < V_32 -> V_33 ; V_187 ++ ) {
V_186 = F_49 ( V_32 , V_187 ) ;
V_184 -> V_188 ( V_2 , V_186 ) ;
}
}
F_7 ( L_25 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_183 * V_184 = & V_2 -> V_184 ;
struct V_3 * V_5 ;
struct V_6 * V_32 ;
struct V_185 * V_186 ;
unsigned int V_10 , V_187 ;
F_7 ( L_26 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
V_32 = V_5 -> V_8 ;
if ( ! V_32 )
break;
for ( V_187 = 0 ; V_187 < V_32 -> V_33 ; V_187 ++ ) {
V_186 = F_49 ( V_32 , V_187 ) ;
V_184 -> V_188 ( V_2 , V_186 ) ;
}
}
F_7 ( L_27 ) ;
}
static void F_51 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_189 * V_190 = V_2 -> V_190 ;
int V_191 = 0 ;
if ( ! V_190 )
return;
if ( V_190 -> V_192 ) {
if ( V_2 -> V_193 ) {
if ( V_190 -> V_194 || V_190 -> V_195 ) {
V_2 -> V_196 = 1 ;
V_2 -> V_197 = 1 ;
} else {
V_2 -> V_196 = 0 ;
V_2 -> V_197 = 0 ;
}
}
if ( V_2 -> V_196 != V_2 -> V_198 ) {
V_39 -> V_199 ( V_2 ) ;
V_2 -> V_198 = V_2 -> V_196 ;
}
if ( V_2 -> V_197 != V_2 -> V_200 ) {
V_39 -> V_201 ( V_2 ) ;
V_2 -> V_200 = V_2 -> V_197 ;
}
if ( V_190 -> V_202 != V_2 -> V_203 ) {
V_191 = 1 ;
switch ( V_190 -> V_202 ) {
case V_204 :
V_39 -> V_205 ( V_2 ) ;
break;
case V_206 :
V_39 -> V_207 ( V_2 ) ;
break;
case V_208 :
V_39 -> V_209 ( V_2 ) ;
break;
}
V_2 -> V_203 = V_190 -> V_202 ;
}
if ( V_190 -> V_192 != V_2 -> V_210 ) {
V_191 = 1 ;
V_2 -> V_210 = 1 ;
}
} else if ( V_2 -> V_210 ) {
V_191 = 1 ;
V_2 -> V_210 = 0 ;
V_2 -> V_203 = V_211 ;
}
if ( V_191 )
F_53 ( V_190 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_42 * V_27 = V_2 -> V_27 ;
struct V_189 * V_190 = V_2 -> V_190 ;
int V_11 ;
V_2 -> V_210 = - 1 ;
V_2 -> V_203 = V_211 ;
V_2 -> V_198 = V_2 -> V_196 ;
V_2 -> V_200 = V_2 -> V_197 ;
V_11 = F_55 ( V_27 , V_190 , & F_51 ,
V_2 -> V_212 ) ;
if ( V_11 ) {
F_5 ( V_27 , L_28 ) ;
return V_11 ;
}
if ( ! V_190 -> V_213 || ( V_190 -> V_213 -> V_214 == 0 ) ) {
F_5 ( V_27 , L_29 ) ;
V_11 = - V_215 ;
goto V_216;
}
F_7 ( L_30 ,
F_56 ( & V_190 -> V_168 ) , V_190 -> V_192 ) ;
return 0 ;
V_216:
F_57 ( V_190 ) ;
return V_11 ;
}
static void F_58 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_190 )
return;
F_57 ( V_2 -> V_190 ) ;
}
int F_59 ( struct V_42 * V_27 , unsigned int V_217 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
unsigned long V_218 ;
F_7 ( L_31 ) ;
if ( ! F_60 ( V_27 ) ||
( V_217 == V_219 && V_2 -> V_220 ) ) {
F_15 ( V_27 , L_32 ) ;
F_7 ( L_33 ) ;
return - V_46 ;
}
F_61 ( & V_2 -> V_30 , V_218 ) ;
if ( V_217 == V_221 )
F_62 ( V_27 ) ;
F_63 ( V_27 ) ;
V_39 -> V_222 ( V_2 ) ;
V_39 -> V_223 ( V_2 ) ;
F_38 ( V_2 , 0 ) ;
F_64 ( V_2 -> V_190 ) ;
V_2 -> V_220 = 1 ;
F_65 ( & V_2 -> V_30 , V_218 ) ;
F_7 ( L_33 ) ;
return 0 ;
}
int F_66 ( struct V_42 * V_27 , unsigned int V_217 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
unsigned long V_218 ;
F_7 ( L_34 ) ;
if ( ! F_60 ( V_27 ) ||
( V_217 == V_219 && ! V_2 -> V_220 ) ) {
F_15 ( V_27 , L_35 ) ;
F_7 ( L_36 ) ;
return - V_46 ;
}
F_61 ( & V_2 -> V_30 , V_218 ) ;
V_2 -> V_220 = 0 ;
F_67 ( V_2 -> V_190 ) ;
F_35 ( V_2 , 0 ) ;
V_39 -> V_224 ( V_2 ) ;
V_39 -> V_225 ( V_2 ) ;
if ( V_217 == V_221 )
F_68 ( V_27 ) ;
F_69 ( V_27 ) ;
F_65 ( & V_2 -> V_30 , V_218 ) ;
F_7 ( L_36 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_42 * V_27 = V_2 -> V_27 ;
int V_11 ;
F_7 ( L_37 ) ;
V_39 -> V_226 ( V_2 ) ;
F_67 ( V_2 -> V_190 ) ;
F_35 ( V_2 , 1 ) ;
V_11 = F_41 ( V_2 ) ;
if ( V_11 )
goto V_227;
V_39 -> V_228 ( V_2 ) ;
V_39 -> V_229 ( V_2 ) ;
F_30 ( V_2 ) ;
F_69 ( V_27 ) ;
F_7 ( L_38 ) ;
return 0 ;
V_227:
F_38 ( V_2 , 1 ) ;
F_64 ( V_2 -> V_190 ) ;
V_39 -> exit ( V_2 ) ;
return V_11 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_3 * V_5 ;
struct V_42 * V_27 = V_2 -> V_27 ;
struct V_230 * V_231 ;
unsigned int V_10 ;
F_7 ( L_39 ) ;
F_63 ( V_27 ) ;
F_32 ( V_2 ) ;
V_39 -> V_232 ( V_2 ) ;
V_39 -> V_233 ( V_2 ) ;
F_45 ( V_2 ) ;
F_38 ( V_2 , 1 ) ;
F_64 ( V_2 -> V_190 ) ;
V_39 -> exit ( V_2 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
continue;
V_231 = F_72 ( V_27 , V_5 -> V_20 ) ;
F_73 ( V_231 ) ;
}
F_7 ( L_40 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
F_7 ( L_41 ) ;
if ( ! F_60 ( V_2 -> V_27 ) )
return;
F_71 ( V_2 ) ;
F_48 ( V_2 ) ;
F_50 ( V_2 ) ;
F_70 ( V_2 ) ;
F_7 ( L_42 ) ;
}
static void F_75 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_76 ( V_235 ,
struct V_1 ,
V_74 ) ;
F_77 () ;
F_74 ( V_2 ) ;
F_78 () ;
}
static void F_79 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_76 ( V_235 ,
struct V_1 ,
V_86 ) ;
struct V_236 V_237 ;
T_2 V_238 ;
unsigned long V_218 ;
if ( V_2 -> V_84 ) {
V_238 = F_80 ( & V_2 -> V_239 ,
V_2 -> V_84 ) ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_237 . V_240 = F_81 ( V_238 ) ;
F_82 ( V_2 -> V_241 , & V_237 ) ;
}
F_83 ( V_2 -> V_241 ) ;
F_61 ( & V_2 -> V_242 , V_218 ) ;
V_2 -> V_241 = NULL ;
F_65 ( & V_2 -> V_242 , V_218 ) ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_243 * V_243 )
{
if ( F_85 ( V_243 -> V_244 , & V_2 -> V_245 ,
sizeof( V_2 -> V_245 ) ) )
return - V_246 ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_243 * V_243 )
{
struct V_247 V_248 ;
unsigned int V_249 ;
if ( F_87 ( & V_248 , V_243 -> V_244 , sizeof( V_248 ) ) )
return - V_246 ;
if ( V_248 . V_218 )
return - V_46 ;
V_249 = 0 ;
switch ( V_248 . V_250 ) {
case V_251 :
break;
case V_252 :
F_88 ( V_249 , V_253 , V_254 , 1 ) ;
break;
default:
return - V_255 ;
}
switch ( V_248 . V_256 ) {
case V_257 :
break;
case V_258 :
F_88 ( V_249 , V_253 , V_259 , 1 ) ;
F_88 ( V_249 , V_253 , V_254 , 1 ) ;
break;
case V_260 :
F_88 ( V_249 , V_253 , V_261 , 1 ) ;
case V_262 :
F_88 ( V_249 , V_253 , V_263 , 1 ) ;
F_88 ( V_249 , V_253 , V_264 , 1 ) ;
F_88 ( V_249 , V_253 , V_265 , 1 ) ;
F_88 ( V_249 , V_253 , V_254 , 1 ) ;
break;
case V_266 :
F_88 ( V_249 , V_253 , V_261 , 1 ) ;
case V_267 :
F_88 ( V_249 , V_253 , V_263 , 1 ) ;
F_88 ( V_249 , V_253 , V_264 , 1 ) ;
F_88 ( V_249 , V_253 , V_268 , 1 ) ;
F_88 ( V_249 , V_253 , V_254 , 1 ) ;
break;
case V_269 :
F_88 ( V_249 , V_253 , V_261 , 1 ) ;
case V_270 :
F_88 ( V_249 , V_253 , V_263 , 1 ) ;
F_88 ( V_249 , V_253 , V_264 , 1 ) ;
F_88 ( V_249 , V_253 , V_268 , 1 ) ;
F_88 ( V_249 , V_253 , V_271 , 1 ) ;
F_88 ( V_249 , V_253 , V_254 , 1 ) ;
break;
case V_272 :
F_88 ( V_249 , V_253 , V_273 , 1 ) ;
F_88 ( V_249 , V_253 , V_265 , 1 ) ;
F_88 ( V_249 , V_253 , V_254 , 1 ) ;
break;
case V_274 :
F_88 ( V_249 , V_253 , V_273 , 1 ) ;
F_88 ( V_249 , V_253 , V_268 , 1 ) ;
F_88 ( V_249 , V_253 , V_254 , 1 ) ;
break;
case V_275 :
F_88 ( V_249 , V_253 , V_273 , 1 ) ;
F_88 ( V_249 , V_253 , V_271 , 1 ) ;
F_88 ( V_249 , V_253 , V_268 , 1 ) ;
F_88 ( V_249 , V_253 , V_254 , 1 ) ;
break;
case V_276 :
F_88 ( V_249 , V_253 , V_261 , 1 ) ;
F_88 ( V_249 , V_253 , V_277 , 1 ) ;
F_88 ( V_249 , V_253 , V_263 , 1 ) ;
F_88 ( V_249 , V_253 , V_264 , 1 ) ;
F_88 ( V_249 , V_253 , V_265 , 1 ) ;
F_88 ( V_249 , V_253 , V_254 , 1 ) ;
break;
case V_278 :
F_88 ( V_249 , V_253 , V_261 , 1 ) ;
F_88 ( V_249 , V_253 , V_277 , 1 ) ;
F_88 ( V_249 , V_253 , V_263 , 1 ) ;
F_88 ( V_249 , V_253 , V_264 , 1 ) ;
F_88 ( V_249 , V_253 , V_268 , 1 ) ;
F_88 ( V_249 , V_253 , V_254 , 1 ) ;
break;
case V_279 :
F_88 ( V_249 , V_253 , V_261 , 1 ) ;
F_88 ( V_249 , V_253 , V_277 , 1 ) ;
F_88 ( V_249 , V_253 , V_263 , 1 ) ;
F_88 ( V_249 , V_253 , V_264 , 1 ) ;
F_88 ( V_249 , V_253 , V_271 , 1 ) ;
F_88 ( V_249 , V_253 , V_268 , 1 ) ;
F_88 ( V_249 , V_253 , V_254 , 1 ) ;
break;
default:
return - V_255 ;
}
V_2 -> V_39 . V_280 ( V_2 , V_249 ) ;
memcpy ( & V_2 -> V_245 , & V_248 , sizeof( V_248 ) ) ;
return 0 ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_281 * V_282 ,
struct V_283 * V_284 )
{
unsigned long V_218 ;
if ( F_22 ( V_284 -> V_285 , V_286 , V_287 ) ) {
F_61 ( & V_2 -> V_242 , V_218 ) ;
if ( V_2 -> V_241 ) {
F_88 ( V_284 -> V_285 ,
V_286 , V_287 , 0 ) ;
} else {
V_2 -> V_241 = F_90 ( V_282 ) ;
F_91 ( V_282 ) -> V_288 |= V_289 ;
}
F_65 ( & V_2 -> V_242 , V_218 ) ;
}
if ( ! F_22 ( V_284 -> V_285 , V_286 , V_287 ) )
F_92 ( V_282 ) ;
}
static void F_93 ( struct V_281 * V_282 , struct V_283 * V_284 )
{
if ( F_94 ( V_282 ) )
V_284 -> V_290 = F_95 ( V_282 ) ;
}
static int F_96 ( struct V_281 * V_282 , struct V_283 * V_284 )
{
int V_11 ;
if ( ! F_22 ( V_284 -> V_285 , V_286 ,
V_291 ) )
return 0 ;
V_11 = F_97 ( V_282 , 0 ) ;
if ( V_11 )
return V_11 ;
V_284 -> V_292 = F_98 ( V_282 ) + F_99 ( V_282 ) ;
V_284 -> V_293 = F_99 ( V_282 ) ;
V_284 -> V_294 = V_282 -> V_295 - V_284 -> V_292 ;
V_284 -> V_296 = F_91 ( V_282 ) -> V_297 ;
F_7 ( L_43 , V_284 -> V_292 ) ;
F_7 ( L_44 ,
V_284 -> V_293 , V_284 -> V_294 ) ;
F_7 ( L_45 , V_284 -> V_296 ) ;
V_284 -> V_298 = F_91 ( V_282 ) -> V_299 ;
V_284 -> V_300 += ( V_284 -> V_298 - 1 ) * V_284 -> V_292 ;
return 0 ;
}
static int F_100 ( struct V_281 * V_282 )
{
if ( V_282 -> V_301 != V_302 )
return 0 ;
if ( ! F_101 ( V_282 ) )
return 0 ;
F_7 ( L_46 ) ;
return 1 ;
}
static void F_102 ( struct V_1 * V_2 ,
struct V_6 * V_32 , struct V_281 * V_282 ,
struct V_283 * V_284 )
{
struct V_303 * V_304 ;
unsigned int V_305 ;
unsigned int V_295 ;
unsigned int V_10 ;
V_284 -> V_282 = V_282 ;
V_305 = 0 ;
V_284 -> V_33 = 0 ;
V_284 -> V_298 = 1 ;
V_284 -> V_300 = V_282 -> V_295 ;
if ( F_100 ( V_282 ) ) {
if ( F_91 ( V_282 ) -> V_297 != V_32 -> V_36 . V_306 ) {
V_305 = 1 ;
V_284 -> V_33 ++ ;
}
V_284 -> V_33 ++ ;
F_88 ( V_284 -> V_285 , V_286 ,
V_291 , 1 ) ;
F_88 ( V_284 -> V_285 , V_286 ,
V_307 , 1 ) ;
} else if ( V_282 -> V_301 == V_302 )
F_88 ( V_284 -> V_285 , V_286 ,
V_307 , 1 ) ;
if ( F_94 ( V_282 ) ) {
if ( F_95 ( V_282 ) != V_32 -> V_36 . V_308 )
if ( ! V_305 ) {
V_305 = 1 ;
V_284 -> V_33 ++ ;
}
F_88 ( V_284 -> V_285 , V_286 ,
V_309 , 1 ) ;
}
if ( ( F_91 ( V_282 ) -> V_288 & V_310 ) &&
( V_2 -> V_245 . V_250 == V_252 ) )
F_88 ( V_284 -> V_285 , V_286 ,
V_287 , 1 ) ;
for ( V_295 = F_103 ( V_282 ) ; V_295 ; ) {
V_284 -> V_33 ++ ;
V_295 -= F_104 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
for ( V_10 = 0 ; V_10 < F_91 ( V_282 ) -> V_311 ; V_10 ++ ) {
V_304 = & F_91 ( V_282 ) -> V_312 [ V_10 ] ;
for ( V_295 = F_105 ( V_304 ) ; V_295 ; ) {
V_284 -> V_33 ++ ;
V_295 -= F_104 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
}
}
static int F_106 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
struct V_183 * V_184 = & V_2 -> V_184 ;
int V_11 ;
F_7 ( L_47 ) ;
V_11 = F_54 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_107 ( V_2 -> V_313 ) ;
if ( V_11 ) {
F_15 ( V_27 , L_48 ) ;
goto V_314;
}
V_11 = F_107 ( V_2 -> V_315 ) ;
if ( V_11 ) {
F_15 ( V_27 , L_49 ) ;
goto V_316;
}
V_11 = F_14 ( V_27 , V_27 -> V_43 ) ;
if ( V_11 < 0 )
goto V_317;
V_2 -> V_44 = V_11 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 )
goto V_317;
V_11 = V_184 -> V_318 ( V_2 ) ;
if ( V_11 )
goto V_319;
F_108 ( & V_2 -> V_74 , F_75 ) ;
F_108 ( & V_2 -> V_86 , F_79 ) ;
V_11 = F_70 ( V_2 ) ;
if ( V_11 )
goto V_320;
F_7 ( L_50 ) ;
return 0 ;
V_320:
V_184 -> V_321 ( V_2 ) ;
V_319:
F_9 ( V_2 ) ;
V_317:
F_109 ( V_2 -> V_315 ) ;
V_316:
F_109 ( V_2 -> V_313 ) ;
V_314:
F_58 ( V_2 ) ;
return V_11 ;
}
static int F_110 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
struct V_183 * V_184 = & V_2 -> V_184 ;
F_7 ( L_51 ) ;
F_71 ( V_2 ) ;
V_184 -> V_321 ( V_2 ) ;
F_9 ( V_2 ) ;
F_109 ( V_2 -> V_315 ) ;
F_109 ( V_2 -> V_313 ) ;
F_58 ( V_2 ) ;
F_7 ( L_52 ) ;
return 0 ;
}
static int F_111 ( struct V_281 * V_282 , struct V_42 * V_27 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_183 * V_184 = & V_2 -> V_184 ;
struct V_3 * V_5 ;
struct V_6 * V_32 ;
struct V_283 * V_284 ;
struct V_230 * V_231 ;
int V_11 ;
F_7 ( L_53 , V_282 -> V_295 ) ;
V_5 = V_2 -> V_5 + V_282 -> V_322 ;
V_231 = F_72 ( V_27 , V_5 -> V_20 ) ;
V_32 = V_5 -> V_7 ;
V_284 = & V_32 -> V_323 ;
V_11 = V_324 ;
if ( V_282 -> V_295 == 0 ) {
F_5 ( V_27 , L_54 ) ;
F_83 ( V_282 ) ;
goto V_325;
}
memset ( V_284 , 0 , sizeof( * V_284 ) ) ;
F_102 ( V_2 , V_32 , V_282 , V_284 ) ;
V_11 = F_12 ( V_5 , V_32 , V_284 -> V_33 ) ;
if ( V_11 )
goto V_325;
V_11 = F_96 ( V_282 , V_284 ) ;
if ( V_11 ) {
F_5 ( V_27 , L_55 ) ;
F_83 ( V_282 ) ;
goto V_325;
}
F_93 ( V_282 , V_284 ) ;
if ( ! V_184 -> V_326 ( V_5 , V_282 ) ) {
F_83 ( V_282 ) ;
goto V_325;
}
F_89 ( V_2 , V_282 , V_284 ) ;
F_112 ( V_231 , V_284 -> V_300 ) ;
V_39 -> V_327 ( V_5 ) ;
#ifdef F_113
F_114 ( V_27 , V_282 , true ) ;
#endif
F_12 ( V_5 , V_32 , V_328 ) ;
V_11 = V_324 ;
V_325:
return V_11 ;
}
static void F_115 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
F_7 ( L_56 ) ;
V_39 -> V_329 ( V_2 ) ;
F_7 ( L_57 ) ;
}
static int F_116 ( struct V_42 * V_27 , void * V_330 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_331 * V_332 = V_330 ;
F_7 ( L_58 ) ;
if ( ! F_117 ( V_332 -> V_333 ) )
return - V_334 ;
memcpy ( V_27 -> V_335 , V_332 -> V_333 , V_27 -> V_336 ) ;
V_39 -> V_337 ( V_2 , V_27 -> V_335 ) ;
F_7 ( L_59 ) ;
return 0 ;
}
static int F_118 ( struct V_42 * V_27 , struct V_243 * V_243 , int V_338 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
int V_11 ;
switch ( V_338 ) {
case V_339 :
V_11 = F_84 ( V_2 , V_243 ) ;
break;
case V_340 :
V_11 = F_86 ( V_2 , V_243 ) ;
break;
default:
V_11 = - V_341 ;
}
return V_11 ;
}
static int F_119 ( struct V_42 * V_27 , int V_43 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
int V_11 ;
F_7 ( L_60 ) ;
V_11 = F_14 ( V_27 , V_43 ) ;
if ( V_11 < 0 )
return V_11 ;
V_2 -> V_44 = V_11 ;
V_27 -> V_43 = V_43 ;
F_74 ( V_2 ) ;
F_7 ( L_61 ) ;
return 0 ;
}
static void F_120 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
F_121 ( V_27 , L_62 ) ;
F_25 ( & V_2 -> V_74 ) ;
}
static struct V_342 * F_122 ( struct V_42 * V_27 ,
struct V_342 * V_343 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
struct V_344 * V_345 = & V_2 -> V_346 ;
F_7 ( L_63 , V_347 ) ;
V_2 -> V_39 . V_348 ( V_2 ) ;
V_343 -> V_349 = V_345 -> V_350 ;
V_343 -> V_351 = V_345 -> V_352 ;
V_343 -> V_353 = V_345 -> V_350 -
V_345 -> V_354 -
V_345 -> V_355 -
V_345 -> V_356 ;
V_343 -> V_357 = V_345 -> V_355 ;
V_343 -> V_358 = V_345 -> V_359 ;
V_343 -> V_360 = V_345 -> V_361 ;
V_343 -> V_362 = V_345 -> V_363 ;
V_343 -> V_298 = V_345 -> V_364 ;
V_343 -> V_300 = V_345 -> V_365 ;
V_343 -> V_366 = V_345 -> V_364 - V_345 -> V_367 ;
V_343 -> V_368 = V_27 -> V_369 . V_368 ;
F_7 ( L_64 , V_347 ) ;
return V_343 ;
}
static int F_123 ( struct V_42 * V_27 , T_3 V_370 ,
T_4 V_371 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
F_7 ( L_63 , V_347 ) ;
F_124 ( V_371 , V_2 -> V_372 ) ;
V_39 -> V_373 ( V_2 ) ;
F_7 ( L_64 , V_347 ) ;
return 0 ;
}
static int F_125 ( struct V_42 * V_27 , T_3 V_370 ,
T_4 V_371 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
F_7 ( L_63 , V_347 ) ;
F_126 ( V_371 , V_2 -> V_372 ) ;
V_39 -> V_373 ( V_2 ) ;
F_7 ( L_64 , V_347 ) ;
return 0 ;
}
static void F_127 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
struct V_3 * V_5 ;
unsigned int V_10 ;
F_7 ( L_65 ) ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ )
F_27 ( V_5 -> V_29 , V_5 ) ;
} else {
F_128 ( V_2 -> V_169 ) ;
F_19 ( V_2 -> V_169 , V_2 ) ;
F_129 ( V_2 -> V_169 ) ;
}
F_7 ( L_66 ) ;
}
static int F_130 ( struct V_42 * V_27 , T_5 V_374 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
unsigned int V_375 , V_376 ;
T_5 V_10 ;
if ( V_374 && ( V_374 != V_2 -> V_95 . V_145 ) )
return - V_46 ;
if ( V_374 ) {
F_131 ( V_27 , V_374 ) ;
for ( V_10 = 0 , V_376 = 0 , V_375 = 0 ; V_10 < V_374 ; V_10 ++ ) {
while ( ( V_376 < V_2 -> V_377 ) &&
( V_2 -> V_378 [ V_376 ] == V_10 ) )
V_376 ++ ;
F_7 ( L_67 , V_10 , V_375 , V_376 - 1 ) ;
F_132 ( V_27 , V_10 , V_376 - V_375 , V_375 ) ;
V_375 = V_376 ;
}
} else {
F_133 ( V_27 ) ;
}
return 0 ;
}
static int F_134 ( struct V_42 * V_27 ,
T_6 V_379 )
{
struct V_1 * V_2 = F_52 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
T_6 V_380 , V_381 , V_382 , V_383 ;
int V_11 = 0 ;
V_380 = V_2 -> V_384 & V_385 ;
V_381 = V_2 -> V_384 & V_386 ;
V_382 = V_2 -> V_384 & V_387 ;
V_383 = V_2 -> V_384 & V_388 ;
if ( ( V_379 & V_385 ) && ! V_380 )
V_11 = V_39 -> V_389 ( V_2 ) ;
else if ( ! ( V_379 & V_385 ) && V_380 )
V_11 = V_39 -> V_390 ( V_2 ) ;
if ( V_11 )
return V_11 ;
if ( ( V_379 & V_386 ) && ! V_381 )
V_39 -> V_391 ( V_2 ) ;
else if ( ! ( V_379 & V_386 ) && V_381 )
V_39 -> V_392 ( V_2 ) ;
if ( ( V_379 & V_387 ) && ! V_382 )
V_39 -> V_393 ( V_2 ) ;
else if ( ! ( V_379 & V_387 ) && V_382 )
V_39 -> V_394 ( V_2 ) ;
if ( ( V_379 & V_388 ) && ! V_383 )
V_39 -> V_395 ( V_2 ) ;
else if ( ! ( V_379 & V_388 ) && V_383 )
V_39 -> V_396 ( V_2 ) ;
V_2 -> V_384 = V_379 ;
F_7 ( L_68 ) ;
return 0 ;
}
struct V_397 * F_135 ( void )
{
return (struct V_397 * ) & V_398 ;
}
static void F_136 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_183 * V_184 = & V_2 -> V_184 ;
struct V_6 * V_32 = V_5 -> V_8 ;
struct V_185 * V_186 ;
while ( V_32 -> V_35 != V_32 -> V_34 ) {
V_186 = F_49 ( V_32 , V_32 -> V_35 ) ;
V_184 -> V_188 ( V_2 , V_186 ) ;
if ( V_184 -> V_399 ( V_2 , V_32 , V_186 ) )
break;
V_39 -> V_400 ( V_2 , V_186 , V_32 -> V_35 ) ;
V_32 -> V_35 ++ ;
}
F_137 () ;
V_186 = F_49 ( V_32 , V_32 -> V_35 - 1 ) ;
F_26 ( V_5 , V_401 ,
F_138 ( V_186 -> V_402 ) ) ;
}
static struct V_281 * F_139 ( struct V_88 * V_72 ,
struct V_185 * V_186 ,
unsigned int * V_295 )
{
struct V_281 * V_282 ;
T_5 * V_284 ;
unsigned int V_403 ;
V_282 = F_140 ( V_72 , V_186 -> V_404 . V_405 . V_406 ) ;
if ( ! V_282 )
return NULL ;
V_284 = F_141 ( V_186 -> V_404 . V_405 . V_407 . V_408 ) +
V_186 -> V_404 . V_405 . V_407 . V_409 ;
V_403 = ( V_186 -> V_404 . V_410 ) ? V_186 -> V_404 . V_410 : * V_295 ;
V_403 = F_142 ( V_186 -> V_404 . V_405 . V_406 , V_403 ) ;
F_143 ( V_282 , V_284 , V_403 ) ;
F_144 ( V_282 , V_403 ) ;
* V_295 -= V_403 ;
return V_282 ;
}
static int F_145 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_183 * V_184 = & V_2 -> V_184 ;
struct V_6 * V_32 = V_5 -> V_7 ;
struct V_185 * V_186 ;
struct V_411 * V_412 ;
struct V_42 * V_27 = V_2 -> V_27 ;
struct V_230 * V_231 ;
int V_413 = 0 ;
unsigned int V_298 = 0 , V_300 = 0 ;
F_7 ( L_69 ) ;
if ( ! V_32 )
return 0 ;
V_231 = F_72 ( V_27 , V_5 -> V_20 ) ;
while ( ( V_413 < V_414 ) &&
( V_32 -> V_35 != V_32 -> V_34 ) ) {
V_186 = F_49 ( V_32 , V_32 -> V_35 ) ;
V_412 = V_186 -> V_412 ;
if ( ! V_39 -> V_415 ( V_412 ) )
break;
F_146 () ;
#ifdef F_147
F_148 ( V_32 , V_32 -> V_35 , 1 , 0 ) ;
#endif
if ( V_39 -> V_416 ( V_412 ) ) {
V_298 += V_186 -> V_36 . V_417 ;
V_300 += V_186 -> V_36 . V_418 ;
}
V_184 -> V_188 ( V_2 , V_186 ) ;
V_39 -> V_419 ( V_186 ) ;
V_413 ++ ;
V_32 -> V_35 ++ ;
}
if ( ! V_413 )
return 0 ;
F_149 ( V_231 , V_298 , V_300 ) ;
if ( ( V_32 -> V_36 . V_37 == 1 ) &&
( F_10 ( V_32 ) > V_420 ) ) {
V_32 -> V_36 . V_37 = 0 ;
F_150 ( V_231 ) ;
}
F_7 ( L_70 , V_413 ) ;
return V_413 ;
}
static int F_151 ( struct V_3 * V_5 , int V_421 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_6 * V_32 = V_5 -> V_8 ;
struct V_185 * V_186 ;
struct V_283 * V_284 ;
struct V_42 * V_27 = V_2 -> V_27 ;
struct V_88 * V_72 ;
struct V_281 * V_282 ;
struct V_236 * V_237 ;
unsigned int V_422 , error , V_423 , V_424 ;
unsigned int V_295 , V_425 , V_426 ;
unsigned int V_427 = 0 ;
int V_428 = 0 ;
F_7 ( L_71 , V_421 ) ;
if ( ! V_32 )
return 0 ;
V_72 = ( V_2 -> V_25 ) ? & V_5 -> V_72 : & V_2 -> V_72 ;
V_186 = F_49 ( V_32 , V_32 -> V_34 ) ;
V_284 = & V_32 -> V_323 ;
while ( V_428 < V_421 ) {
F_7 ( L_72 , V_32 -> V_34 ) ;
if ( ! V_427 && V_186 -> V_429 ) {
V_422 = V_186 -> V_430 . V_422 ;
V_423 = V_186 -> V_430 . V_423 ;
V_282 = V_186 -> V_430 . V_282 ;
error = V_186 -> V_430 . error ;
V_295 = V_186 -> V_430 . V_295 ;
} else {
memset ( V_284 , 0 , sizeof( * V_284 ) ) ;
V_422 = 0 ;
V_423 = 0 ;
V_282 = NULL ;
error = 0 ;
V_295 = 0 ;
}
V_431:
V_186 = F_49 ( V_32 , V_32 -> V_34 ) ;
if ( F_11 ( V_32 ) > ( V_432 >> 3 ) )
F_136 ( V_5 ) ;
if ( V_39 -> V_433 ( V_5 ) )
break;
V_427 ++ ;
V_32 -> V_34 ++ ;
V_422 = F_22 ( V_284 -> V_285 ,
V_434 ,
V_435 ) ;
V_423 = F_22 ( V_284 -> V_285 ,
V_434 ,
V_436 ) ;
V_424 = F_22 ( V_284 -> V_285 ,
V_434 ,
V_437 ) ;
if ( ( V_422 || V_423 ) && error )
goto V_431;
if ( error || V_284 -> V_438 ) {
if ( V_284 -> V_438 )
F_7 ( L_73 ) ;
F_152 ( V_282 ) ;
goto V_439;
}
if ( ! V_424 ) {
V_425 = V_186 -> V_404 . V_295 - V_295 ;
V_295 += V_425 ;
if ( ! V_282 ) {
F_153 ( V_2 -> V_168 ,
V_186 -> V_404 . V_405 . V_440 ,
V_186 -> V_404 . V_405 . V_406 ,
V_441 ) ;
V_282 = F_139 ( V_72 , V_186 , & V_425 ) ;
if ( ! V_282 ) {
error = 1 ;
goto V_442;
}
}
if ( V_425 ) {
F_153 ( V_2 -> V_168 ,
V_186 -> V_404 . V_443 . V_440 ,
V_186 -> V_404 . V_443 . V_406 ,
V_441 ) ;
F_154 ( V_282 , F_91 ( V_282 ) -> V_311 ,
V_186 -> V_404 . V_443 . V_407 . V_408 ,
V_186 -> V_404 . V_443 . V_407 . V_409 ,
V_425 , V_186 -> V_404 . V_443 . V_406 ) ;
V_186 -> V_404 . V_443 . V_407 . V_408 = NULL ;
}
}
V_442:
if ( V_422 || V_423 )
goto V_431;
if ( ! V_282 )
goto V_439;
V_426 = V_27 -> V_43 + V_47 ;
if ( ! ( V_27 -> V_379 & V_387 ) &&
( V_282 -> V_444 == F_155 ( V_445 ) ) )
V_426 += V_49 ;
if ( V_282 -> V_295 > V_426 ) {
F_7 ( L_74 ) ;
F_152 ( V_282 ) ;
goto V_439;
}
#ifdef F_156
F_114 ( V_27 , V_282 , false ) ;
#endif
F_157 ( V_282 ) ;
if ( F_22 ( V_284 -> V_285 ,
V_434 , V_446 ) )
V_282 -> V_301 = V_447 ;
if ( F_22 ( V_284 -> V_285 ,
V_434 , V_309 ) )
F_158 ( V_282 , F_155 ( V_445 ) ,
V_284 -> V_290 ) ;
if ( F_22 ( V_284 -> V_285 ,
V_434 , V_448 ) ) {
T_2 V_238 ;
V_238 = F_80 ( & V_2 -> V_239 ,
V_284 -> V_449 ) ;
V_237 = F_159 ( V_282 ) ;
V_237 -> V_240 = F_81 ( V_238 ) ;
}
if ( F_22 ( V_284 -> V_285 ,
V_434 , V_450 ) )
F_160 ( V_282 , V_284 -> V_451 ,
V_284 -> V_452 ) ;
V_282 -> V_168 = V_27 ;
V_282 -> V_444 = F_161 ( V_282 , V_27 ) ;
F_162 ( V_282 , V_5 -> V_20 ) ;
F_163 ( V_282 , V_72 ) ;
V_27 -> V_453 = V_454 ;
F_164 ( V_72 , V_282 ) ;
V_439:
V_428 ++ ;
}
if ( V_427 && ( V_422 || V_423 ) ) {
V_186 = F_49 ( V_32 , V_32 -> V_34 ) ;
V_186 -> V_429 = 1 ;
V_186 -> V_430 . V_422 = V_422 ;
V_186 -> V_430 . V_423 = V_423 ;
V_186 -> V_430 . V_282 = V_282 ;
V_186 -> V_430 . V_295 = V_295 ;
V_186 -> V_430 . error = error ;
}
F_7 ( L_75 , V_428 ) ;
return V_428 ;
}
static int V_164 ( struct V_88 * V_72 , int V_421 )
{
struct V_3 * V_5 = F_76 ( V_72 , struct V_3 ,
V_72 ) ;
int V_413 = 0 ;
F_7 ( L_76 , V_421 ) ;
F_145 ( V_5 ) ;
V_413 = F_151 ( V_5 , V_421 ) ;
if ( V_413 < V_421 ) {
F_165 ( V_72 ) ;
F_129 ( V_5 -> V_29 ) ;
}
F_7 ( L_77 , V_413 ) ;
return V_413 ;
}
static int V_166 ( struct V_88 * V_72 , int V_421 )
{
struct V_1 * V_2 = F_76 ( V_72 , struct V_1 ,
V_72 ) ;
struct V_3 * V_5 ;
int V_455 ;
int V_413 , V_456 ;
unsigned int V_10 ;
F_7 ( L_78 , V_421 ) ;
V_413 = 0 ;
V_455 = V_421 / V_2 -> V_17 ;
do {
V_456 = V_413 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
F_145 ( V_5 ) ;
if ( V_455 > ( V_421 - V_413 ) )
V_455 = V_421 - V_413 ;
V_413 += F_151 ( V_5 , V_455 ) ;
}
} while ( ( V_413 < V_421 ) && ( V_413 != V_456 ) );
if ( V_413 < V_421 ) {
F_165 ( V_72 ) ;
F_17 ( V_2 ) ;
}
F_7 ( L_79 , V_413 ) ;
return V_413 ;
}
void F_148 ( struct V_6 * V_32 , unsigned int V_457 ,
unsigned int V_9 , unsigned int V_458 )
{
struct V_185 * V_186 ;
struct V_411 * V_412 ;
while ( V_9 -- ) {
V_186 = F_49 ( V_32 , V_457 ) ;
V_412 = V_186 -> V_412 ;
F_166 ( L_80 , V_457 ,
( V_458 == 1 ) ? L_81 : L_82 ,
F_167 ( V_412 -> V_459 ) , F_167 ( V_412 -> V_460 ) ,
F_167 ( V_412 -> V_461 ) , F_167 ( V_412 -> V_462 ) ) ;
V_457 ++ ;
}
}
void F_168 ( struct V_6 * V_32 , struct V_411 * V_463 ,
unsigned int V_457 )
{
F_166 ( L_83 , V_457 ,
F_167 ( V_463 -> V_459 ) , F_167 ( V_463 -> V_460 ) ,
F_167 ( V_463 -> V_461 ) , F_167 ( V_463 -> V_462 ) ) ;
}
void F_114 ( struct V_42 * V_27 , struct V_281 * V_282 , bool V_464 )
{
struct V_465 * V_466 = (struct V_465 * ) V_282 -> V_62 ;
unsigned char * V_443 = V_282 -> V_62 ;
unsigned char V_467 [ 128 ] ;
unsigned int V_10 , V_187 ;
F_15 ( V_27 , L_84 ) ;
F_15 ( V_27 , L_85 ,
( V_464 ? L_86 : L_87 ) , V_282 -> V_295 ) ;
F_15 ( V_27 , L_88 , V_466 -> V_468 ) ;
F_15 ( V_27 , L_89 , V_466 -> V_469 ) ;
F_15 ( V_27 , L_90 , F_169 ( V_466 -> V_470 ) ) ;
for ( V_10 = 0 , V_187 = 0 ; V_10 < V_282 -> V_295 ; ) {
V_187 += snprintf ( V_467 + V_187 , sizeof( V_467 ) - V_187 , L_91 ,
V_443 [ V_10 ++ ] ) ;
if ( ( V_10 % 32 ) == 0 ) {
F_15 ( V_27 , L_92 , V_10 - 32 , V_467 ) ;
V_187 = 0 ;
} else if ( ( V_10 % 16 ) == 0 ) {
V_467 [ V_187 ++ ] = ' ' ;
V_467 [ V_187 ++ ] = ' ' ;
} else if ( ( V_10 % 4 ) == 0 ) {
V_467 [ V_187 ++ ] = ' ' ;
}
}
if ( V_10 % 32 )
F_15 ( V_27 , L_92 , V_10 - ( V_10 % 32 ) , V_467 ) ;
F_15 ( V_27 , L_84 ) ;
}

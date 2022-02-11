void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
V_8 -> V_9 . V_1 = V_2 ;
V_8 -> V_9 . V_10 = V_5 ;
if ( V_5 -> V_11 == V_2 && V_5 -> V_12 != V_13 )
V_5 -> V_14 += F_2 () - V_5 -> V_15 ;
}
void F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
if ( V_5 -> V_11 == V_2 && V_5 -> V_12 != V_13 )
V_5 -> V_15 = F_2 () ;
}
void F_4 ( struct V_1 * V_2 , T_1 V_16 )
{
V_2 -> V_6 . V_17 . V_16 = V_16 ;
F_5 ( V_2 ) ;
}
void F_6 ( struct V_1 * V_2 , T_2 V_18 )
{
V_2 -> V_6 . V_18 = V_18 ;
}
void F_7 ( struct V_1 * V_2 )
{
int V_19 ;
F_8 ( L_1 , V_2 , V_2 -> V_20 ) ;
F_8 ( L_2 ,
V_2 -> V_6 . V_21 , V_2 -> V_6 . V_17 . V_16 , V_2 -> V_6 . V_22 ) ;
for ( V_19 = 0 ; V_19 < 16 ; ++ V_19 )
F_8 ( L_3 ,
V_19 , F_9 ( V_2 , V_19 ) ,
V_19 + 16 , F_9 ( V_2 , V_19 + 16 ) ) ;
F_8 ( L_4 ,
V_2 -> V_6 . V_23 , V_2 -> V_6 . V_24 ) ;
F_8 ( L_5 ,
V_2 -> V_6 . V_17 . V_25 , V_2 -> V_6 . V_17 . V_26 ) ;
F_8 ( L_6 ,
V_2 -> V_6 . V_17 . V_27 , V_2 -> V_6 . V_17 . V_28 ) ;
F_8 ( L_7 ,
V_2 -> V_6 . V_17 . V_29 , V_2 -> V_6 . V_17 . V_30 ) ;
F_8 ( L_8 ,
V_2 -> V_6 . V_31 , V_2 -> V_6 . V_32 , V_2 -> V_6 . V_17 . V_33 ) ;
F_8 ( L_9 , V_2 -> V_6 . V_17 . V_34 ) ;
F_8 ( L_10 ,
V_2 -> V_6 . V_35 , V_2 -> V_6 . V_36 ) ;
F_8 ( L_11 , V_2 -> V_6 . V_37 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_6 . V_37 ; ++ V_19 )
F_8 ( L_12 ,
V_2 -> V_6 . V_38 [ V_19 ] . V_39 , V_2 -> V_6 . V_38 [ V_19 ] . V_40 ) ;
F_8 ( L_13 ,
V_2 -> V_41 -> V_6 . V_42 , V_2 -> V_41 -> V_6 . V_43 ,
V_2 -> V_6 . V_44 ) ;
}
struct V_1 * F_10 ( struct V_41 * V_41 , int V_45 )
{
int V_19 ;
struct V_1 * V_46 , * V_47 = NULL ;
F_11 ( & V_41 -> V_48 ) ;
F_12 (r, v, kvm) {
if ( V_46 -> V_20 == V_45 ) {
V_47 = V_46 ;
break;
}
}
F_13 ( & V_41 -> V_48 ) ;
return V_47 ;
}
static void F_14 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
V_50 -> V_51 = 1 ;
V_50 -> V_52 = 1 ;
}
static int F_15 ( struct V_53 * V_54 )
{
if ( V_54 -> V_55 )
return V_54 -> V_56 != 0 ;
return V_54 -> V_57 != NULL ;
}
static unsigned long F_16 ( struct V_1 * V_2 ,
unsigned long V_58 ,
unsigned long V_59 , unsigned long V_50 )
{
struct V_41 * V_41 = V_2 -> V_41 ;
unsigned long V_60 , V_61 ;
void * V_62 ;
struct V_1 * V_63 ;
int V_64 ;
int V_65 ;
struct V_53 * V_54 ;
V_63 = F_10 ( V_41 , V_59 ) ;
if ( ! V_63 )
return V_66 ;
V_65 = ( V_58 >> V_67 ) & V_68 ;
if ( V_65 == V_69 || V_65 == V_70 ||
V_65 == V_71 ) {
if ( ( V_50 & ( V_72 - 1 ) ) || ! V_50 )
return V_66 ;
V_62 = F_17 ( V_41 , V_50 , & V_61 ) ;
if ( V_62 == NULL )
return V_66 ;
if ( V_65 == V_69 )
V_60 = ( (struct V_73 * ) V_62 ) -> V_74 . V_75 ;
else
V_60 = ( (struct V_73 * ) V_62 ) -> V_74 . V_76 ;
F_18 ( V_41 , V_62 ) ;
if ( V_60 > V_61 || V_60 < sizeof( struct V_73 ) )
return V_66 ;
} else {
V_50 = 0 ;
V_60 = 0 ;
}
V_64 = V_66 ;
V_54 = NULL ;
F_19 ( & V_63 -> V_6 . V_77 ) ;
switch ( V_65 ) {
case V_69 :
if ( V_60 < sizeof( struct V_49 ) )
break;
V_54 = & V_63 -> V_6 . V_50 ;
V_64 = 0 ;
break;
case V_70 :
if ( V_60 < sizeof( struct V_78 ) )
break;
V_60 -= V_60 % sizeof( struct V_78 ) ;
V_64 = V_79 ;
if ( ! F_15 ( & V_63 -> V_6 . V_50 ) )
break;
V_54 = & V_63 -> V_6 . V_80 ;
V_64 = 0 ;
break;
case V_71 :
V_64 = V_79 ;
if ( ! F_15 ( & V_63 -> V_6 . V_50 ) )
break;
V_54 = & V_63 -> V_6 . V_81 ;
V_64 = 0 ;
break;
case V_82 :
V_64 = V_79 ;
if ( F_15 ( & V_63 -> V_6 . V_80 ) ||
F_15 ( & V_63 -> V_6 . V_81 ) )
break;
V_54 = & V_63 -> V_6 . V_50 ;
V_64 = 0 ;
break;
case V_83 :
V_54 = & V_63 -> V_6 . V_80 ;
V_64 = 0 ;
break;
case V_84 :
V_54 = & V_63 -> V_6 . V_81 ;
V_64 = 0 ;
break;
}
if ( V_54 ) {
V_54 -> V_56 = V_50 ;
V_54 -> V_60 = V_60 ;
V_54 -> V_55 = 1 ;
}
F_20 ( & V_63 -> V_6 . V_77 ) ;
return V_64 ;
}
static void F_21 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_41 * V_41 = V_2 -> V_41 ;
void * V_62 ;
unsigned long V_61 ;
unsigned long V_85 ;
for (; ; ) {
V_85 = V_54 -> V_56 ;
F_20 ( & V_2 -> V_6 . V_77 ) ;
V_62 = NULL ;
V_61 = 0 ;
if ( V_85 )
V_62 = F_17 ( V_41 , V_54 -> V_56 , & V_61 ) ;
F_19 ( & V_2 -> V_6 . V_77 ) ;
if ( V_85 == V_54 -> V_56 )
break;
if ( V_62 )
F_18 ( V_41 , V_62 ) ;
}
V_54 -> V_55 = 0 ;
if ( V_62 && V_61 < V_54 -> V_60 ) {
F_18 ( V_41 , V_62 ) ;
V_62 = NULL ;
}
if ( V_54 -> V_57 )
F_18 ( V_41 , V_54 -> V_57 ) ;
V_54 -> V_57 = V_62 ;
if ( V_62 )
V_54 -> V_86 = V_62 + V_54 -> V_60 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_6 . V_77 ) ;
if ( V_2 -> V_6 . V_50 . V_55 ) {
F_21 ( V_2 , & V_2 -> V_6 . V_50 ) ;
F_14 ( V_2 , V_2 -> V_6 . V_50 . V_57 ) ;
}
if ( V_2 -> V_6 . V_80 . V_55 ) {
F_21 ( V_2 , & V_2 -> V_6 . V_80 ) ;
V_2 -> V_6 . V_87 = V_2 -> V_6 . V_80 . V_57 ;
V_2 -> V_6 . V_88 = 0 ;
}
if ( V_2 -> V_6 . V_81 . V_55 )
F_21 ( V_2 , & V_2 -> V_6 . V_81 ) ;
F_20 ( & V_2 -> V_6 . V_77 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_78 * V_89 ;
struct V_49 * V_50 ;
unsigned long V_90 ;
V_89 = V_2 -> V_6 . V_87 ;
V_50 = V_2 -> V_6 . V_50 . V_57 ;
V_90 = V_2 -> V_6 . V_91 ;
V_2 -> V_6 . V_91 = V_5 -> V_14 ;
if ( ! V_89 || ! V_50 )
return;
memset ( V_89 , 0 , sizeof( struct V_78 ) ) ;
V_89 -> V_92 = 7 ;
V_89 -> V_93 = V_5 -> V_94 + V_2 -> V_6 . V_95 ;
V_89 -> V_96 = F_2 () ;
V_89 -> V_97 = V_5 -> V_14 - V_90 ;
V_89 -> V_25 = F_24 ( V_2 ) ;
V_89 -> V_26 = V_2 -> V_6 . V_17 . V_16 ;
++ V_89 ;
if ( V_89 == V_2 -> V_6 . V_80 . V_86 )
V_89 = V_2 -> V_6 . V_80 . V_57 ;
V_2 -> V_6 . V_87 = V_89 ;
F_25 () ;
V_50 -> V_98 = ++ V_2 -> V_6 . V_88 ;
}
int F_26 ( struct V_1 * V_2 )
{
unsigned long V_99 = F_9 ( V_2 , 3 ) ;
unsigned long V_100 , V_47 = V_101 ;
struct V_1 * V_63 ;
switch ( V_99 ) {
case V_102 :
V_47 = F_27 ( V_2 , F_9 ( V_2 , 4 ) ,
F_9 ( V_2 , 5 ) ,
F_9 ( V_2 , 6 ) ,
F_9 ( V_2 , 7 ) ) ;
break;
case V_103 :
break;
case V_104 :
V_100 = F_9 ( V_2 , 4 ) ;
V_63 = F_10 ( V_2 -> V_41 , V_100 ) ;
if ( ! V_63 ) {
V_47 = V_66 ;
break;
}
V_63 -> V_6 . V_105 = 1 ;
F_28 () ;
if ( V_2 -> V_6 . V_106 ) {
if ( F_29 ( & V_2 -> V_107 ) ) {
F_30 ( & V_2 -> V_107 ) ;
V_2 -> V_108 . V_109 ++ ;
}
}
break;
case V_110 :
break;
case V_111 :
V_47 = F_16 ( V_2 , F_9 ( V_2 , 4 ) ,
F_9 ( V_2 , 5 ) ,
F_9 ( V_2 , 6 ) ) ;
break;
default:
return V_112 ;
}
F_31 ( V_2 , 3 , V_47 ) ;
V_2 -> V_6 . V_113 = 0 ;
return V_114 ;
}
static int F_32 ( struct V_115 * V_116 , struct V_1 * V_2 ,
struct V_117 * V_118 )
{
int V_19 = V_112 ;
V_2 -> V_108 . V_119 ++ ;
V_116 -> V_120 = V_121 ;
V_116 -> V_122 = 1 ;
switch ( V_2 -> V_6 . V_22 ) {
case V_123 :
V_2 -> V_108 . V_124 ++ ;
V_19 = V_114 ;
break;
case V_125 :
V_2 -> V_108 . V_126 ++ ;
V_19 = V_114 ;
break;
case V_127 :
V_19 = V_114 ;
break;
case V_128 :
{
T_3 V_58 ;
V_58 = V_2 -> V_6 . V_17 . V_16 & 0x1f0000ull ;
F_33 ( V_2 , V_58 ) ;
V_19 = V_114 ;
break;
}
case V_129 :
{
int V_130 ;
if ( V_2 -> V_6 . V_17 . V_16 & V_131 ) {
F_34 ( V_2 , V_129 ) ;
V_19 = V_114 ;
break;
}
V_116 -> V_132 . V_133 = F_9 ( V_2 , 3 ) ;
for ( V_130 = 0 ; V_130 < 9 ; ++ V_130 )
V_116 -> V_132 . args [ V_130 ] = F_9 ( V_2 , 4 + V_130 ) ;
V_116 -> V_120 = V_134 ;
V_2 -> V_6 . V_113 = 1 ;
V_19 = V_112 ;
break;
}
case V_135 :
V_19 = F_35 ( V_116 , V_2 ,
V_2 -> V_6 . V_35 , V_2 -> V_6 . V_36 ) ;
break;
case V_136 :
V_19 = F_35 ( V_116 , V_2 ,
F_24 ( V_2 ) , 0 ) ;
break;
case V_137 :
F_33 ( V_2 , 0x80000 ) ;
V_19 = V_114 ;
break;
default:
F_7 ( V_2 ) ;
F_36 ( V_138 L_14 ,
V_2 -> V_6 . V_22 , F_24 ( V_2 ) ,
V_2 -> V_6 . V_17 . V_16 ) ;
V_19 = V_112 ;
F_37 () ;
break;
}
return V_19 ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_139 * V_140 )
{
int V_130 ;
V_140 -> V_18 = V_2 -> V_6 . V_18 ;
memset ( V_140 , 0 , sizeof( struct V_139 ) ) ;
for ( V_130 = 0 ; V_130 < V_2 -> V_6 . V_37 ; V_130 ++ ) {
V_140 -> V_141 . V_142 . V_143 . V_38 [ V_130 ] . V_144 = V_2 -> V_6 . V_38 [ V_130 ] . V_39 ;
V_140 -> V_141 . V_142 . V_143 . V_38 [ V_130 ] . V_145 = V_2 -> V_6 . V_38 [ V_130 ] . V_40 ;
}
return 0 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_139 * V_140 )
{
int V_130 , V_146 ;
F_6 ( V_2 , V_140 -> V_18 ) ;
V_146 = 0 ;
for ( V_130 = 0 ; V_130 < V_2 -> V_6 . V_147 ; V_130 ++ ) {
if ( V_140 -> V_141 . V_142 . V_143 . V_38 [ V_130 ] . V_144 & V_148 ) {
V_2 -> V_6 . V_38 [ V_146 ] . V_39 = V_140 -> V_141 . V_142 . V_143 . V_38 [ V_130 ] . V_144 ;
V_2 -> V_6 . V_38 [ V_146 ] . V_40 = V_140 -> V_141 . V_142 . V_143 . V_38 [ V_130 ] . V_145 ;
++ V_146 ;
}
}
V_2 -> V_6 . V_37 = V_146 ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 , struct V_149 * V_150 )
{
int V_19 = - V_151 ;
switch ( V_150 -> V_45 ) {
case V_152 :
V_19 = F_41 ( 0 , ( T_1 V_153 * ) V_150 -> V_154 ) ;
break;
default:
break;
}
return V_19 ;
}
int F_42 ( struct V_1 * V_2 , struct V_149 * V_150 )
{
int V_19 = - V_151 ;
switch ( V_150 -> V_45 ) {
case V_152 :
{
T_1 V_155 ;
V_19 = F_43 ( V_155 , ( T_1 V_153 * ) V_150 -> V_154 ) ;
if ( ! V_19 && ( V_155 != 0 ) )
V_19 = - V_151 ;
break;
}
default:
break;
}
return V_19 ;
}
int F_44 ( void )
{
if ( F_45 ( V_156 ) )
return 0 ;
return - V_157 ;
}
struct V_1 * F_46 ( struct V_41 * V_41 , unsigned int V_45 )
{
struct V_1 * V_2 ;
int V_64 = - V_151 ;
int V_158 ;
struct V_4 * V_7 ;
V_158 = V_45 / V_159 ;
if ( V_158 >= V_160 )
goto V_161;
V_64 = - V_162 ;
V_2 = F_47 ( V_163 , V_164 ) ;
if ( ! V_2 )
goto V_161;
V_64 = F_48 ( V_2 , V_41 , V_45 ) ;
if ( V_64 )
goto V_165;
V_2 -> V_6 . V_166 = & V_2 -> V_6 . V_17 ;
V_2 -> V_6 . V_167 = - 1 ;
V_2 -> V_6 . V_168 [ 0 ] = V_169 ;
V_2 -> V_6 . V_170 = V_171 ;
V_2 -> V_6 . V_18 = F_49 ( V_172 ) ;
F_6 ( V_2 , V_2 -> V_6 . V_18 ) ;
F_50 ( & V_2 -> V_6 . V_77 ) ;
F_51 ( V_2 ) ;
V_2 -> V_6 . V_173 = V_174 ;
F_52 ( & V_2 -> V_6 . V_175 ) ;
F_11 ( & V_41 -> V_48 ) ;
V_7 = V_41 -> V_6 . V_176 [ V_158 ] ;
if ( ! V_7 ) {
V_7 = F_53 ( sizeof( struct V_4 ) , V_164 ) ;
if ( V_7 ) {
F_54 ( & V_7 -> V_177 ) ;
F_50 ( & V_7 -> V_48 ) ;
F_52 ( & V_7 -> V_107 ) ;
V_7 -> V_15 = F_2 () ;
}
V_41 -> V_6 . V_176 [ V_158 ] = V_7 ;
}
F_13 ( & V_41 -> V_48 ) ;
if ( ! V_7 )
goto V_165;
F_19 ( & V_7 -> V_48 ) ;
++ V_7 -> V_178 ;
F_20 ( & V_7 -> V_48 ) ;
V_2 -> V_6 . V_7 = V_7 ;
V_2 -> V_6 . V_91 = V_7 -> V_14 ;
V_2 -> V_6 . V_179 = V_180 ;
F_55 ( V_2 ) ;
return V_2 ;
V_165:
F_56 ( V_163 , V_2 ) ;
V_161:
return F_57 ( V_64 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_6 . V_77 ) ;
if ( V_2 -> V_6 . V_80 . V_57 )
F_18 ( V_2 -> V_41 , V_2 -> V_6 . V_80 . V_57 ) ;
if ( V_2 -> V_6 . V_81 . V_57 )
F_18 ( V_2 -> V_41 , V_2 -> V_6 . V_81 . V_57 ) ;
if ( V_2 -> V_6 . V_50 . V_57 )
F_18 ( V_2 -> V_41 , V_2 -> V_6 . V_50 . V_57 ) ;
F_20 ( & V_2 -> V_6 . V_77 ) ;
F_59 ( V_2 ) ;
F_56 ( V_163 , V_2 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
unsigned long V_181 , V_182 ;
V_182 = F_61 () ;
if ( V_182 > V_2 -> V_6 . V_183 ) {
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
return;
}
V_181 = ( V_2 -> V_6 . V_183 - V_182 ) * V_184
/ V_185 ;
F_64 ( & V_2 -> V_6 . V_186 , F_65 ( 0 , V_181 ) ,
V_187 ) ;
V_2 -> V_6 . V_188 = 1 ;
}
static void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_106 = 0 ;
if ( V_2 -> V_6 . V_188 ) {
F_66 ( & V_2 -> V_6 . V_186 ) ;
V_2 -> V_6 . V_188 = 0 ;
}
}
static void F_67 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_1 * V_46 ;
if ( V_2 -> V_6 . V_173 != V_189 )
return;
V_2 -> V_6 . V_173 = V_190 ;
-- V_5 -> V_191 ;
++ V_5 -> V_192 ;
V_46 = V_2 ;
F_68 ( V_46 , & V_5 -> V_177 , V_6 . V_193 )
-- V_46 -> V_6 . V_95 ;
F_69 ( & V_2 -> V_6 . V_193 ) ;
}
static int F_70 ( int V_3 )
{
struct V_194 * V_195 ;
long V_196 = 1000 ;
V_195 = & V_197 [ V_3 ] ;
V_195 -> V_9 . V_198 = 1 ;
F_28 () ;
while ( V_195 -> V_9 . V_199 == V_200 ) {
if ( -- V_196 <= 0 ) {
F_8 ( L_15 , V_3 ) ;
return - V_201 ;
}
F_71 ( 1 ) ;
}
return 0 ;
}
static void F_72 ( int V_3 )
{
struct V_194 * V_195 ;
V_195 = & V_197 [ V_3 ] ;
V_195 -> V_9 . V_198 = 0 ;
V_195 -> V_9 . V_1 = NULL ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_194 * V_195 ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
if ( V_2 -> V_6 . V_188 ) {
F_66 ( & V_2 -> V_6 . V_186 ) ;
V_2 -> V_6 . V_188 = 0 ;
}
V_3 = V_5 -> V_94 + V_2 -> V_6 . V_95 ;
V_195 = & V_197 [ V_3 ] ;
V_195 -> V_9 . V_1 = V_2 ;
V_195 -> V_9 . V_10 = V_5 ;
V_195 -> V_9 . V_202 = 0 ;
V_2 -> V_3 = V_5 -> V_94 ;
F_25 () ;
#if F_74 ( V_203 ) && F_74 ( V_204 )
if ( V_2 -> V_6 . V_95 ) {
F_70 ( V_3 ) ;
F_75 ( V_3 ) ;
++ V_5 -> V_205 ;
}
#endif
}
static void F_76 ( struct V_4 * V_5 )
{
int V_130 ;
F_77 () ;
V_130 = 0 ;
while ( V_5 -> V_206 < V_5 -> V_205 ) {
if ( ++ V_130 >= 1000000 ) {
F_8 ( L_16 ,
V_5 -> V_206 , V_5 -> V_205 ) ;
break;
}
F_78 () ;
}
F_79 () ;
}
static int F_80 ( void )
{
int V_3 = F_81 () ;
int V_207 = F_82 ( V_3 ) ;
if ( V_207 )
return 0 ;
while ( ++ V_207 < V_159 )
if ( F_83 ( V_3 + V_207 ) )
return 0 ;
return 1 ;
}
static int F_84 ( struct V_4 * V_5 )
{
struct V_1 * V_2 , * V_208 , * V_209 ;
long V_47 ;
T_1 V_182 ;
int V_95 , V_130 , V_210 ;
V_210 = 0 ;
F_85 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( F_86 ( V_2 -> V_6 . V_211 ) )
return 0 ;
V_210 |= V_2 -> V_6 . V_50 . V_55 |
V_2 -> V_6 . V_81 . V_55 |
V_2 -> V_6 . V_80 . V_55 ;
}
V_5 -> V_205 = 0 ;
V_5 -> V_206 = 0 ;
V_5 -> V_212 = 0 ;
V_5 -> V_12 = V_213 ;
V_5 -> V_214 = 0 ;
V_5 -> V_215 = 0 ;
if ( V_210 ) {
F_20 ( & V_5 -> V_48 ) ;
F_85 (vcpu, &vc->runnable_threads, arch.run_list)
F_22 ( V_2 ) ;
F_19 ( & V_5 -> V_48 ) ;
}
if ( V_159 > 1 && ! F_80 () ) {
F_85 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_6 . V_47 = - V_201 ;
goto V_161;
}
V_95 = 0 ;
V_208 = NULL ;
F_85 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( ! V_2 -> V_6 . V_106 ) {
if ( ! V_95 )
V_208 = V_2 ;
V_2 -> V_6 . V_95 = V_95 ++ ;
}
}
if ( ! V_208 )
return 0 ;
F_85 (vcpu, &vc->runnable_threads, arch.run_list)
if ( V_2 -> V_6 . V_106 )
V_2 -> V_6 . V_95 = V_95 ++ ;
V_5 -> V_14 += F_2 () - V_5 -> V_15 ;
V_5 -> V_94 = F_81 () ;
F_85 (vcpu, &vc->runnable_threads, arch.run_list) {
F_73 ( V_2 ) ;
F_23 ( V_2 , V_5 ) ;
}
for ( V_130 = V_95 ; V_130 < V_159 ; ++ V_130 )
F_70 ( V_5 -> V_94 + V_130 ) ;
F_87 () ;
F_20 ( & V_5 -> V_48 ) ;
F_88 () ;
F_89 ( NULL , V_208 ) ;
for ( V_130 = 0 ; V_130 < V_159 ; ++ V_130 )
F_72 ( V_5 -> V_94 + V_130 ) ;
F_19 ( & V_5 -> V_48 ) ;
F_85 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_3 = - 1 ;
if ( V_5 -> V_206 < V_5 -> V_205 )
F_76 ( V_5 ) ;
V_5 -> V_12 = V_216 ;
F_20 ( & V_5 -> V_48 ) ;
F_28 () ;
F_90 () ;
F_91 () ;
F_92 ( V_2 ) ;
V_182 = F_61 () ;
F_85 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_182 < V_2 -> V_6 . V_183 &&
F_93 ( V_2 ) )
F_94 ( V_2 ) ;
V_47 = V_114 ;
if ( V_2 -> V_6 . V_22 )
V_47 = F_32 ( V_2 -> V_6 . V_115 , V_2 ,
V_2 -> V_6 . V_211 ) ;
V_2 -> V_6 . V_47 = V_47 ;
V_2 -> V_6 . V_22 = 0 ;
if ( V_2 -> V_6 . V_106 ) {
if ( V_47 != V_114 )
F_5 ( V_2 ) ;
else
F_60 ( V_2 ) ;
}
}
F_19 ( & V_5 -> V_48 ) ;
V_161:
V_5 -> V_12 = V_13 ;
V_5 -> V_15 = F_2 () ;
F_95 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( V_2 -> V_6 . V_47 != V_114 ) {
F_67 ( V_5 , V_2 ) ;
F_96 ( & V_2 -> V_6 . V_175 ) ;
}
}
return 1 ;
}
static void F_97 ( struct V_1 * V_2 , int V_217 )
{
F_98 ( V_218 ) ;
F_99 ( & V_2 -> V_6 . V_175 , & V_218 , V_217 ) ;
if ( V_2 -> V_6 . V_173 == V_189 )
F_100 () ;
F_101 ( & V_2 -> V_6 . V_175 , & V_218 ) ;
}
static void F_102 ( struct V_4 * V_5 )
{
F_98 ( V_218 ) ;
struct V_1 * V_46 ;
int V_219 = 1 ;
F_99 ( & V_5 -> V_107 , & V_218 , V_220 ) ;
V_5 -> V_12 = V_221 ;
F_20 ( & V_5 -> V_48 ) ;
F_85 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_46 -> V_6 . V_106 || V_46 -> V_6 . V_222 ) {
V_219 = 0 ;
break;
}
}
if ( V_219 )
F_100 () ;
F_101 ( & V_5 -> V_107 , & V_218 ) ;
F_19 ( & V_5 -> V_48 ) ;
V_5 -> V_12 = V_13 ;
}
static int F_103 ( struct V_115 * V_115 , struct V_1 * V_2 )
{
int V_223 ;
int V_224 ;
struct V_4 * V_5 ;
struct V_1 * V_46 , * V_225 ;
V_115 -> V_120 = 0 ;
V_2 -> V_6 . V_47 = V_114 ;
V_2 -> V_6 . V_22 = 0 ;
V_5 = V_2 -> V_6 . V_7 ;
F_19 ( & V_5 -> V_48 ) ;
V_2 -> V_6 . V_106 = 0 ;
V_2 -> V_6 . V_211 = V_226 ;
V_2 -> V_6 . V_115 = V_115 ;
V_224 = V_2 -> V_6 . V_173 ;
V_2 -> V_6 . V_173 = V_189 ;
F_104 ( & V_2 -> V_6 . V_193 , & V_5 -> V_177 ) ;
++ V_5 -> V_191 ;
if ( V_224 == V_174 ) {
if ( V_5 -> V_12 == V_213 &&
F_105 ( V_5 ) == 0 ) {
V_2 -> V_6 . V_95 = V_5 -> V_191 - 1 ;
F_73 ( V_2 ) ;
}
} else if ( V_224 == V_190 )
-- V_5 -> V_192 ;
while ( V_2 -> V_6 . V_173 == V_189 &&
! F_86 ( V_226 ) ) {
if ( V_5 -> V_192 || V_5 -> V_12 != V_13 ) {
F_20 ( & V_5 -> V_48 ) ;
F_97 ( V_2 , V_220 ) ;
F_19 ( & V_5 -> V_48 ) ;
continue;
}
V_5 -> V_11 = V_2 ;
V_223 = 0 ;
F_85 (v, &vc->runnable_threads, arch.run_list)
V_223 += V_46 -> V_6 . V_106 ;
if ( V_223 == V_5 -> V_191 )
F_102 ( V_5 ) ;
else
F_84 ( V_5 ) ;
F_95 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_63 ( V_46 ) ;
if ( F_86 ( V_46 -> V_6 . V_211 ) ) {
F_67 ( V_5 , V_46 ) ;
V_46 -> V_108 . V_227 ++ ;
V_46 -> V_6 . V_115 -> V_120 = V_228 ;
V_46 -> V_6 . V_47 = - V_229 ;
F_96 ( & V_46 -> V_6 . V_175 ) ;
}
}
V_5 -> V_11 = NULL ;
}
if ( F_86 ( V_226 ) ) {
if ( V_5 -> V_12 == V_213 ||
V_5 -> V_12 == V_216 ) {
F_20 ( & V_5 -> V_48 ) ;
F_97 ( V_2 , V_230 ) ;
F_19 ( & V_5 -> V_48 ) ;
}
if ( V_2 -> V_6 . V_173 == V_189 ) {
F_67 ( V_5 , V_2 ) ;
V_2 -> V_108 . V_227 ++ ;
V_115 -> V_120 = V_228 ;
V_2 -> V_6 . V_47 = - V_229 ;
}
}
F_20 ( & V_5 -> V_48 ) ;
return V_2 -> V_6 . V_47 ;
}
int F_106 ( struct V_115 * V_116 , struct V_1 * V_2 )
{
int V_19 ;
if ( ! V_2 -> V_6 . V_231 ) {
V_116 -> V_120 = V_232 ;
return - V_151 ;
}
F_63 ( V_2 ) ;
if ( F_86 ( V_226 ) ) {
V_116 -> V_120 = V_228 ;
return - V_229 ;
}
if ( ! V_2 -> V_41 -> V_6 . V_233 ) {
V_19 = F_107 ( V_2 ) ;
if ( V_19 )
return V_19 ;
}
F_108 ( V_226 ) ;
F_109 ( V_226 ) ;
F_110 ( V_226 ) ;
V_2 -> V_6 . V_234 = & V_2 -> V_6 . V_7 -> V_107 ;
V_2 -> V_6 . V_235 = V_226 -> V_236 -> V_237 ;
do {
V_19 = F_103 ( V_116 , V_2 ) ;
if ( V_116 -> V_120 == V_134 &&
! ( V_2 -> V_6 . V_17 . V_16 & V_131 ) ) {
V_19 = F_26 ( V_2 ) ;
F_63 ( V_2 ) ;
}
} while ( V_19 == V_114 );
return V_19 ;
}
static inline int F_111 ( unsigned long V_238 )
{
switch ( V_238 ) {
case 32ul << 20 :
if ( F_45 ( V_239 ) )
return 8 ;
return - 1 ;
case 64ul << 20 :
return 3 ;
case 128ul << 20 :
return 7 ;
case 256ul << 20 :
return 4 ;
case 1ul << 30 :
return 2 ;
case 16ul << 30 :
return 1 ;
case 256ul << 30 :
return 0 ;
default:
return - 1 ;
}
}
static int F_112 ( struct V_240 * V_241 , struct V_242 * V_243 )
{
struct V_244 * V_245 = V_241 -> V_246 -> V_247 ;
struct V_248 * V_248 ;
if ( V_243 -> V_249 >= V_245 -> V_250 )
return V_251 ;
V_248 = F_113 ( V_245 -> V_252 + V_243 -> V_249 ) ;
F_114 ( V_248 ) ;
V_243 -> V_248 = V_248 ;
return 0 ;
}
static int F_115 ( struct V_253 * V_253 , struct V_240 * V_241 )
{
V_241 -> V_254 |= V_255 ;
V_241 -> V_256 = & V_257 ;
return 0 ;
}
static int F_116 ( struct V_258 * V_258 , struct V_253 * V_259 )
{
struct V_244 * V_245 = V_259 -> V_247 ;
F_117 ( V_245 ) ;
return 0 ;
}
long F_118 ( struct V_41 * V_41 , struct V_260 * V_47 )
{
struct V_244 * V_245 ;
long V_261 ;
V_245 = F_119 () ;
if ( ! V_245 )
return - V_162 ;
V_261 = F_120 ( L_17 , & V_262 , V_245 , V_263 ) ;
if ( V_261 < 0 )
F_117 ( V_245 ) ;
V_47 -> V_238 = V_245 -> V_250 << V_264 ;
return V_261 ;
}
static void F_121 ( struct V_265 * * V_266 ,
int V_267 )
{
struct V_268 * V_269 = & V_270 [ V_267 ] ;
if ( ! V_269 -> V_271 )
return;
( * V_266 ) -> V_272 = V_269 -> V_271 ;
( * V_266 ) -> V_273 = V_269 -> V_274 ;
( * V_266 ) -> V_275 [ 0 ] . V_272 = V_269 -> V_271 ;
( * V_266 ) -> V_275 [ 0 ] . V_276 = V_269 -> V_277 ;
( * V_266 ) ++ ;
}
int F_122 ( struct V_41 * V_41 , struct V_278 * V_279 )
{
struct V_265 * V_266 ;
V_279 -> V_58 = V_280 ;
if ( F_123 ( V_281 ) )
V_279 -> V_58 |= V_282 ;
V_279 -> V_283 = V_284 ;
V_266 = & V_279 -> V_266 [ 0 ] ;
F_121 ( & V_266 , V_285 ) ;
F_121 ( & V_266 , V_286 ) ;
F_121 ( & V_266 , V_287 ) ;
return 0 ;
}
int F_124 ( struct V_41 * V_41 , struct V_288 * log )
{
struct V_289 * V_290 ;
int V_19 ;
unsigned long V_291 ;
F_11 ( & V_41 -> V_292 ) ;
V_19 = - V_151 ;
if ( log -> V_293 >= V_294 )
goto V_161;
V_290 = F_125 ( V_41 -> V_295 , log -> V_293 ) ;
V_19 = - V_296 ;
if ( ! V_290 -> V_297 )
goto V_161;
V_291 = F_126 ( V_290 ) ;
memset ( V_290 -> V_297 , 0 , V_291 ) ;
V_19 = F_127 ( V_41 , V_290 ) ;
if ( V_19 )
goto V_161;
V_19 = - V_298 ;
if ( F_128 ( log -> V_297 , V_290 -> V_297 , V_291 ) )
goto V_161;
V_19 = 0 ;
V_161:
F_13 ( & V_41 -> V_292 ) ;
return V_19 ;
}
static unsigned long F_129 ( unsigned long V_299 )
{
unsigned long V_300 = 0 ;
if ( V_299 > 0x1000 ) {
V_300 = V_301 ;
if ( V_299 == 0x10000 )
V_300 |= V_302 ;
}
return V_300 ;
}
int F_130 ( struct V_41 * V_41 ,
struct V_303 * V_304 )
{
unsigned long V_250 ;
unsigned long * V_305 ;
V_305 = V_41 -> V_6 . V_306 [ V_304 -> V_293 ] ;
if ( ! V_41 -> V_6 . V_307 && ! V_305 ) {
V_250 = V_304 -> V_308 >> V_264 ;
V_305 = F_131 ( V_250 * sizeof( unsigned long ) ) ;
if ( ! V_305 )
return - V_162 ;
V_41 -> V_6 . V_306 [ V_304 -> V_293 ] = V_305 ;
V_41 -> V_6 . V_309 [ V_304 -> V_293 ] = V_250 ;
}
return 0 ;
}
static void F_132 ( struct V_41 * V_41 , int V_310 )
{
unsigned long * V_311 ;
unsigned long V_146 , V_250 , V_312 ;
struct V_248 * V_248 ;
V_311 = V_41 -> V_6 . V_306 [ V_310 ] ;
V_250 = V_41 -> V_6 . V_309 [ V_310 ] ;
if ( V_311 ) {
F_19 ( & V_41 -> V_6 . V_313 ) ;
for ( V_146 = 0 ; V_146 < V_250 ; V_146 ++ ) {
if ( ! ( V_311 [ V_146 ] & V_314 ) )
continue;
V_312 = V_311 [ V_146 ] >> V_264 ;
V_248 = F_113 ( V_312 ) ;
F_133 ( V_248 ) ;
F_134 ( V_248 ) ;
}
V_41 -> V_6 . V_306 [ V_310 ] = NULL ;
F_20 ( & V_41 -> V_6 . V_313 ) ;
F_135 ( V_311 ) ;
}
}
void F_136 ( struct V_41 * V_41 ,
struct V_303 * V_304 )
{
}
static int F_107 ( struct V_1 * V_2 )
{
int V_64 = 0 ;
struct V_41 * V_41 = V_2 -> V_41 ;
struct V_244 * V_245 = NULL ;
unsigned long V_315 ;
struct V_289 * V_290 ;
struct V_240 * V_241 ;
unsigned long V_42 , V_300 ;
unsigned long V_299 , V_316 ;
unsigned long V_238 ;
unsigned long V_317 ;
unsigned long * V_311 ;
unsigned long V_130 , V_250 ;
F_11 ( & V_41 -> V_48 ) ;
if ( V_41 -> V_6 . V_233 )
goto V_161;
V_290 = F_137 ( V_41 , 0 ) ;
V_64 = - V_151 ;
if ( ! V_290 || ( V_290 -> V_58 & V_318 ) )
goto V_161;
V_315 = V_290 -> V_319 ;
F_138 ( & V_226 -> V_236 -> V_320 ) ;
V_241 = F_139 ( V_226 -> V_236 , V_315 ) ;
if ( ! V_241 || V_241 -> V_321 > V_315 || ( V_241 -> V_254 & V_322 ) )
goto V_323;
V_299 = F_140 ( V_241 ) ;
V_316 = F_141 ( V_299 ) ;
if ( V_241 -> V_246 && V_241 -> V_246 -> V_324 == & V_262 &&
V_315 == V_241 -> V_321 )
V_245 = V_241 -> V_246 -> V_247 ;
F_142 ( & V_226 -> V_236 -> V_320 ) ;
if ( ! V_245 ) {
V_64 = - V_325 ;
if ( F_45 ( V_326 ) ) {
F_8 ( L_18 ) ;
goto V_161;
}
V_64 = - V_151 ;
if ( ! ( V_299 == 0x1000 || V_299 == 0x10000 ||
V_299 == 0x1000000 ) )
goto V_161;
V_300 = F_129 ( V_299 ) ;
V_41 -> V_6 . V_327 = V_300 | V_328 |
( V_329 << V_330 ) ;
V_42 = V_41 -> V_6 . V_42 & ~ V_331 ;
V_42 |= V_300 << ( V_332 - 4 ) ;
V_41 -> V_6 . V_42 = V_42 ;
F_143 ( V_2 , V_290 , V_316 ) ;
} else {
V_238 = V_245 -> V_250 ;
if ( V_238 > V_290 -> V_250 )
V_238 = V_290 -> V_250 ;
V_238 <<= V_264 ;
V_317 = F_111 ( V_238 ) ;
V_64 = - V_151 ;
if ( V_317 < 0 ) {
F_8 ( L_19 , V_238 ) ;
goto V_161;
}
F_144 ( & V_245 -> V_333 ) ;
V_41 -> V_6 . V_334 = V_245 ;
V_42 = V_41 -> V_6 . V_42 ;
if ( F_45 ( V_326 ) ) {
V_42 &= ~ ( ( 1ul << V_335 ) |
( 3ul << V_336 ) ) ;
V_42 |= ( ( V_317 >> 2 ) << V_335 ) |
( ( V_317 & 3 ) << V_336 ) ;
V_42 |= ( ( V_245 -> V_252 >> ( 26 - V_264 ) ) & 0xffff )
<< V_337 ;
} else {
V_42 &= ~ ( V_338 | V_339 ) ;
V_42 |= V_317 << V_340 ;
V_41 -> V_6 . V_341 = V_41 -> V_6 . V_334 -> V_252 << V_264 ;
}
V_41 -> V_6 . V_42 = V_42 ;
F_145 ( L_20 ,
V_245 -> V_252 << V_264 , V_238 , V_42 ) ;
V_250 = V_245 -> V_250 ;
V_316 = F_141 ( V_250 ) ;
V_311 = V_41 -> V_6 . V_306 [ V_290 -> V_45 ] ;
F_19 ( & V_41 -> V_6 . V_313 ) ;
for ( V_130 = 0 ; V_130 < V_250 ; ++ V_130 )
V_311 [ V_130 ] = ( ( V_245 -> V_252 + V_130 ) << V_264 ) + V_316 ;
F_20 ( & V_41 -> V_6 . V_313 ) ;
}
F_25 () ;
V_41 -> V_6 . V_233 = 1 ;
V_64 = 0 ;
V_161:
F_13 ( & V_41 -> V_48 ) ;
return V_64 ;
V_323:
F_142 ( & V_226 -> V_236 -> V_320 ) ;
goto V_161;
}
int F_146 ( struct V_41 * V_41 )
{
long V_19 ;
unsigned long V_42 ;
V_19 = F_147 ( V_41 ) ;
if ( V_19 )
return V_19 ;
F_54 ( & V_41 -> V_6 . V_342 ) ;
V_41 -> V_6 . V_334 = NULL ;
V_41 -> V_6 . V_343 = F_49 ( V_344 ) ;
if ( F_45 ( V_326 ) ) {
unsigned long V_345 = V_41 -> V_6 . V_345 ;
V_41 -> V_6 . V_346 = 0 ;
V_41 -> V_6 . V_347 = V_42 = F_49 ( V_348 ) ;
V_42 &= ~ ( ( 3 << V_349 ) | ( 0xful << V_350 ) ) ;
V_42 |= ( ( V_345 >> 4 ) << V_349 ) |
( ( V_345 & 0xf ) << V_350 ) ;
} else {
V_41 -> V_6 . V_346 = F_49 ( V_351 ) ;
V_41 -> V_6 . V_347 = V_42 = F_49 ( V_352 ) ;
V_42 &= V_353 | V_354 ;
V_42 |= ( 4UL << V_355 ) | V_356 |
V_338 | V_357 ;
V_41 -> V_6 . V_327 = V_328 |
( V_329 << V_330 ) ;
}
V_41 -> V_6 . V_42 = V_42 ;
V_41 -> V_6 . V_307 = ! ! F_45 ( V_239 ) ;
F_50 ( & V_41 -> V_6 . V_313 ) ;
return 0 ;
}
void F_148 ( struct V_41 * V_41 )
{
unsigned long V_130 ;
if ( ! V_41 -> V_6 . V_307 )
for ( V_130 = 0 ; V_130 < V_358 ; V_130 ++ )
F_132 ( V_41 , V_130 ) ;
if ( V_41 -> V_6 . V_334 ) {
F_117 ( V_41 -> V_6 . V_334 ) ;
V_41 -> V_6 . V_334 = NULL ;
}
F_149 ( V_41 ) ;
F_150 ( ! F_151 ( & V_41 -> V_6 . V_342 ) ) ;
}
void F_152 ( struct V_1 * V_2 , T_3 V_359 , T_3 V_360 )
{
}
int F_153 ( struct V_115 * V_116 , struct V_1 * V_2 ,
unsigned int V_361 , int * V_362 )
{
return V_363 ;
}
int F_154 ( struct V_1 * V_2 , int V_364 , T_3 V_365 )
{
return V_363 ;
}
int F_155 ( struct V_1 * V_2 , int V_364 , T_3 * V_365 )
{
return V_363 ;
}
static int F_156 ( void )
{
int V_19 ;
V_19 = F_157 ( NULL , sizeof( struct V_1 ) , 0 , V_366 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_158 () ;
return V_19 ;
}
static void F_159 ( void )
{
F_160 () ;
}

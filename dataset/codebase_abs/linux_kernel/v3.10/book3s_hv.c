void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = V_2 -> V_4 ;
T_1 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( V_5 ) ;
++ V_2 -> V_6 . V_7 ;
}
V_3 = F_5 () ;
if ( V_4 != V_3 && V_4 >= 0 && V_4 < V_8 ) {
int V_9 = V_4 + V_2 -> V_10 . V_11 ;
if ( V_12 [ V_9 ] . V_13 . V_14 )
F_6 ( V_9 ) ;
else if ( F_7 ( V_4 ) )
F_8 ( V_4 ) ;
}
F_9 () ;
}
void F_10 ( struct V_1 * V_2 , int V_4 )
{
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
F_11 ( & V_2 -> V_10 . V_18 ) ;
if ( V_16 -> V_19 == V_2 && V_16 -> V_20 != V_21 &&
V_16 -> V_22 != V_23 ) {
V_16 -> V_24 += F_12 () - V_16 -> V_22 ;
V_16 -> V_22 = V_23 ;
}
if ( V_2 -> V_10 . V_25 == V_26 &&
V_2 -> V_10 . V_27 != V_23 ) {
V_2 -> V_10 . V_28 += F_12 () - V_2 -> V_10 . V_27 ;
V_2 -> V_10 . V_27 = V_23 ;
}
F_13 ( & V_2 -> V_10 . V_18 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
F_11 ( & V_2 -> V_10 . V_18 ) ;
if ( V_16 -> V_19 == V_2 && V_16 -> V_20 != V_21 )
V_16 -> V_22 = F_12 () ;
if ( V_2 -> V_10 . V_25 == V_26 )
V_2 -> V_10 . V_27 = F_12 () ;
F_13 ( & V_2 -> V_10 . V_18 ) ;
}
void F_15 ( struct V_1 * V_2 , T_2 V_29 )
{
V_2 -> V_10 . V_30 . V_29 = V_29 ;
F_16 ( V_2 ) ;
}
void F_17 ( struct V_1 * V_2 , T_3 V_31 )
{
V_2 -> V_10 . V_31 = V_31 ;
}
void F_18 ( struct V_1 * V_2 )
{
int V_32 ;
F_19 ( L_1 , V_2 , V_2 -> V_33 ) ;
F_19 ( L_2 ,
V_2 -> V_10 . V_34 , V_2 -> V_10 . V_30 . V_29 , V_2 -> V_10 . V_35 ) ;
for ( V_32 = 0 ; V_32 < 16 ; ++ V_32 )
F_19 ( L_3 ,
V_32 , F_20 ( V_2 , V_32 ) ,
V_32 + 16 , F_20 ( V_2 , V_32 + 16 ) ) ;
F_19 ( L_4 ,
V_2 -> V_10 . V_36 , V_2 -> V_10 . V_37 ) ;
F_19 ( L_5 ,
V_2 -> V_10 . V_30 . V_38 , V_2 -> V_10 . V_30 . V_39 ) ;
F_19 ( L_6 ,
V_2 -> V_10 . V_30 . V_40 , V_2 -> V_10 . V_30 . V_41 ) ;
F_19 ( L_7 ,
V_2 -> V_10 . V_30 . V_42 , V_2 -> V_10 . V_30 . V_43 ) ;
F_19 ( L_8 ,
V_2 -> V_10 . V_44 , V_2 -> V_10 . V_45 , V_2 -> V_10 . V_30 . V_46 ) ;
F_19 ( L_9 , V_2 -> V_10 . V_30 . V_47 ) ;
F_19 ( L_10 ,
V_2 -> V_10 . V_48 , V_2 -> V_10 . V_49 ) ;
F_19 ( L_11 , V_2 -> V_10 . V_50 ) ;
for ( V_32 = 0 ; V_32 < V_2 -> V_10 . V_50 ; ++ V_32 )
F_19 ( L_12 ,
V_2 -> V_10 . V_51 [ V_32 ] . V_52 , V_2 -> V_10 . V_51 [ V_32 ] . V_53 ) ;
F_19 ( L_13 ,
V_2 -> V_54 -> V_10 . V_55 , V_2 -> V_54 -> V_10 . V_56 ,
V_2 -> V_10 . V_57 ) ;
}
struct V_1 * F_21 ( struct V_54 * V_54 , int V_58 )
{
int V_32 ;
struct V_1 * V_59 , * V_60 = NULL ;
F_22 ( & V_54 -> V_61 ) ;
F_23 (r, v, kvm) {
if ( V_59 -> V_33 == V_58 ) {
V_60 = V_59 ;
break;
}
}
F_24 ( & V_54 -> V_61 ) ;
return V_60 ;
}
static void F_25 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
V_63 -> V_64 = 1 ;
V_63 -> V_65 = 1 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_66 * V_59 ,
unsigned long V_67 , unsigned long V_68 )
{
if ( V_67 & ( V_69 - 1 ) )
return - V_70 ;
F_11 ( & V_2 -> V_10 . V_71 ) ;
if ( V_59 -> V_72 != V_67 || V_59 -> V_68 != V_68 ) {
V_59 -> V_72 = V_67 ;
V_59 -> V_68 = V_67 ? V_68 : 0 ;
V_59 -> V_73 = 1 ;
}
F_13 ( & V_2 -> V_10 . V_71 ) ;
return 0 ;
}
static int F_27 ( struct V_66 * V_74 )
{
if ( V_74 -> V_73 )
return V_74 -> V_72 != 0 ;
return V_74 -> V_75 != NULL ;
}
static unsigned long F_28 ( struct V_1 * V_2 ,
unsigned long V_76 ,
unsigned long V_77 , unsigned long V_63 )
{
struct V_54 * V_54 = V_2 -> V_54 ;
unsigned long V_68 , V_78 ;
void * V_79 ;
struct V_1 * V_80 ;
int V_81 ;
int V_82 ;
struct V_66 * V_74 ;
V_80 = F_21 ( V_54 , V_77 ) ;
if ( ! V_80 )
return V_83 ;
V_82 = ( V_76 >> V_84 ) & V_85 ;
if ( V_82 == V_86 || V_82 == V_87 ||
V_82 == V_88 ) {
if ( ( V_63 & ( V_69 - 1 ) ) || ! V_63 )
return V_83 ;
V_79 = F_29 ( V_54 , V_63 , & V_78 ) ;
if ( V_79 == NULL )
return V_83 ;
if ( V_82 == V_86 )
V_68 = ( (struct V_89 * ) V_79 ) -> V_90 . V_91 ;
else
V_68 = ( (struct V_89 * ) V_79 ) -> V_90 . V_92 ;
F_30 ( V_54 , V_79 , V_63 , false ) ;
if ( V_68 > V_78 || V_68 < sizeof( struct V_89 ) )
return V_83 ;
} else {
V_63 = 0 ;
V_68 = 0 ;
}
V_81 = V_83 ;
V_74 = NULL ;
F_11 ( & V_80 -> V_10 . V_71 ) ;
switch ( V_82 ) {
case V_86 :
if ( V_68 < sizeof( struct V_62 ) )
break;
V_74 = & V_80 -> V_10 . V_63 ;
V_81 = 0 ;
break;
case V_87 :
if ( V_68 < sizeof( struct V_93 ) )
break;
V_68 -= V_68 % sizeof( struct V_93 ) ;
V_81 = V_94 ;
if ( ! F_27 ( & V_80 -> V_10 . V_63 ) )
break;
V_74 = & V_80 -> V_10 . V_95 ;
V_81 = 0 ;
break;
case V_88 :
V_81 = V_94 ;
if ( ! F_27 ( & V_80 -> V_10 . V_63 ) )
break;
V_74 = & V_80 -> V_10 . V_96 ;
V_81 = 0 ;
break;
case V_97 :
V_81 = V_94 ;
if ( F_27 ( & V_80 -> V_10 . V_95 ) ||
F_27 ( & V_80 -> V_10 . V_96 ) )
break;
V_74 = & V_80 -> V_10 . V_63 ;
V_81 = 0 ;
break;
case V_98 :
V_74 = & V_80 -> V_10 . V_95 ;
V_81 = 0 ;
break;
case V_99 :
V_74 = & V_80 -> V_10 . V_96 ;
V_81 = 0 ;
break;
}
if ( V_74 ) {
V_74 -> V_72 = V_63 ;
V_74 -> V_68 = V_68 ;
V_74 -> V_73 = 1 ;
}
F_13 ( & V_80 -> V_10 . V_71 ) ;
return V_81 ;
}
static void F_31 ( struct V_1 * V_2 , struct V_66 * V_74 )
{
struct V_54 * V_54 = V_2 -> V_54 ;
void * V_79 ;
unsigned long V_78 ;
unsigned long V_100 ;
for (; ; ) {
V_100 = V_74 -> V_72 ;
F_13 ( & V_2 -> V_10 . V_71 ) ;
V_79 = NULL ;
V_78 = 0 ;
if ( V_100 )
V_79 = F_29 ( V_54 , V_100 , & V_78 ) ;
F_11 ( & V_2 -> V_10 . V_71 ) ;
if ( V_100 == V_74 -> V_72 )
break;
if ( V_79 )
F_30 ( V_54 , V_79 , V_100 , false ) ;
}
V_74 -> V_73 = 0 ;
if ( V_79 && V_78 < V_74 -> V_68 ) {
F_30 ( V_54 , V_79 , V_100 , false ) ;
V_79 = NULL ;
}
if ( V_74 -> V_75 )
F_30 ( V_54 , V_74 -> V_75 , V_74 -> V_100 ,
V_74 -> V_101 ) ;
V_74 -> V_100 = V_100 ;
V_74 -> V_75 = V_79 ;
V_74 -> V_101 = false ;
if ( V_79 )
V_74 -> V_102 = V_79 + V_74 -> V_68 ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_10 . V_63 . V_73 ||
V_2 -> V_10 . V_96 . V_73 ||
V_2 -> V_10 . V_95 . V_73 ) )
return;
F_11 ( & V_2 -> V_10 . V_71 ) ;
if ( V_2 -> V_10 . V_63 . V_73 ) {
F_31 ( V_2 , & V_2 -> V_10 . V_63 ) ;
if ( V_2 -> V_10 . V_63 . V_75 )
F_25 ( V_2 , V_2 -> V_10 . V_63 . V_75 ) ;
}
if ( V_2 -> V_10 . V_95 . V_73 ) {
F_31 ( V_2 , & V_2 -> V_10 . V_95 ) ;
V_2 -> V_10 . V_103 = V_2 -> V_10 . V_95 . V_75 ;
V_2 -> V_10 . V_104 = 0 ;
}
if ( V_2 -> V_10 . V_96 . V_73 )
F_31 ( V_2 , & V_2 -> V_10 . V_96 ) ;
F_13 ( & V_2 -> V_10 . V_71 ) ;
}
static T_2 F_33 ( struct V_15 * V_16 , T_2 V_105 )
{
T_2 V_106 ;
if ( V_16 -> V_20 != V_21 &&
V_16 -> V_19 -> V_10 . V_107 != V_108 ) {
F_11 ( & V_16 -> V_19 -> V_10 . V_18 ) ;
V_106 = V_16 -> V_24 ;
if ( V_16 -> V_22 != V_23 )
V_106 += V_105 - V_16 -> V_22 ;
F_13 ( & V_16 -> V_19 -> V_10 . V_18 ) ;
} else {
V_106 = V_16 -> V_24 ;
}
return V_106 ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_93 * V_109 ;
struct V_62 * V_63 ;
unsigned long V_110 ;
unsigned long V_111 ;
T_2 V_105 ;
V_109 = V_2 -> V_10 . V_103 ;
V_63 = V_2 -> V_10 . V_63 . V_75 ;
V_105 = F_12 () ;
V_111 = F_33 ( V_16 , V_105 ) ;
V_110 = V_111 - V_2 -> V_10 . V_112 ;
V_2 -> V_10 . V_112 = V_111 ;
F_11 ( & V_2 -> V_10 . V_18 ) ;
V_110 += V_2 -> V_10 . V_28 ;
V_2 -> V_10 . V_28 = 0 ;
F_13 ( & V_2 -> V_10 . V_18 ) ;
if ( ! V_109 || ! V_63 )
return;
memset ( V_109 , 0 , sizeof( struct V_93 ) ) ;
V_109 -> V_113 = 7 ;
V_109 -> V_114 = V_16 -> V_115 + V_2 -> V_10 . V_11 ;
V_109 -> V_116 = V_105 ;
V_109 -> V_117 = V_110 ;
V_109 -> V_38 = F_35 ( V_2 ) ;
V_109 -> V_39 = V_2 -> V_10 . V_30 . V_29 ;
++ V_109 ;
if ( V_109 == V_2 -> V_10 . V_95 . V_102 )
V_109 = V_2 -> V_10 . V_95 . V_75 ;
V_2 -> V_10 . V_103 = V_109 ;
F_36 () ;
V_63 -> V_118 = ++ V_2 -> V_10 . V_104 ;
V_2 -> V_10 . V_95 . V_101 = true ;
}
int F_37 ( struct V_1 * V_2 )
{
unsigned long V_119 = F_20 ( V_2 , 3 ) ;
unsigned long V_120 , V_60 = V_121 ;
struct V_1 * V_80 ;
int V_122 , V_123 ;
switch ( V_119 ) {
case V_124 :
V_122 = F_38 ( & V_2 -> V_54 -> V_125 ) ;
V_60 = F_39 ( V_2 , F_20 ( V_2 , 4 ) ,
F_20 ( V_2 , 5 ) ,
F_20 ( V_2 , 6 ) ,
F_20 ( V_2 , 7 ) ) ;
F_40 ( & V_2 -> V_54 -> V_125 , V_122 ) ;
break;
case V_126 :
break;
case V_127 :
V_120 = F_20 ( V_2 , 4 ) ;
V_80 = F_21 ( V_2 -> V_54 , V_120 ) ;
if ( ! V_80 ) {
V_60 = V_83 ;
break;
}
V_80 -> V_10 . V_128 = 1 ;
F_41 () ;
if ( V_2 -> V_10 . V_129 ) {
if ( F_3 ( & V_2 -> V_130 ) ) {
F_4 ( & V_2 -> V_130 ) ;
V_2 -> V_6 . V_7 ++ ;
}
}
break;
case V_131 :
break;
case V_132 :
V_60 = F_28 ( V_2 , F_20 ( V_2 , 4 ) ,
F_20 ( V_2 , 5 ) ,
F_20 ( V_2 , 6 ) ) ;
break;
case V_133 :
if ( F_42 ( & V_2 -> V_54 -> V_10 . V_134 ) )
return V_135 ;
V_123 = F_43 ( V_2 ) ;
if ( V_123 == - V_136 )
return V_135 ;
else if ( V_123 == 0 )
break;
return V_123 ;
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
if ( F_44 ( V_2 ) ) {
V_60 = F_45 ( V_2 , V_119 ) ;
break;
}
default:
return V_135 ;
}
F_46 ( V_2 , 3 , V_60 ) ;
V_2 -> V_10 . V_143 = 0 ;
return V_144 ;
}
static int F_47 ( struct V_145 * V_146 , struct V_1 * V_2 ,
struct V_147 * V_148 )
{
int V_32 = V_135 ;
V_2 -> V_6 . V_149 ++ ;
V_146 -> V_150 = V_151 ;
V_146 -> V_152 = 1 ;
switch ( V_2 -> V_10 . V_35 ) {
case V_153 :
V_2 -> V_6 . V_154 ++ ;
V_32 = V_144 ;
break;
case V_155 :
V_2 -> V_6 . V_156 ++ ;
V_32 = V_144 ;
break;
case V_157 :
V_32 = V_144 ;
break;
case V_158 :
F_48 ( V_2 ,
V_158 ) ;
V_32 = V_144 ;
break;
case V_159 :
{
T_4 V_76 ;
V_76 = V_2 -> V_10 . V_30 . V_29 & 0x1f0000ull ;
F_49 ( V_2 , V_76 ) ;
V_32 = V_144 ;
break;
}
case V_160 :
{
int V_161 ;
if ( V_2 -> V_10 . V_30 . V_29 & V_162 ) {
F_48 ( V_2 , V_160 ) ;
V_32 = V_144 ;
break;
}
V_146 -> V_163 . V_164 = F_20 ( V_2 , 3 ) ;
for ( V_161 = 0 ; V_161 < 9 ; ++ V_161 )
V_146 -> V_163 . args [ V_161 ] = F_20 ( V_2 , 4 + V_161 ) ;
V_146 -> V_150 = V_165 ;
V_2 -> V_10 . V_143 = 1 ;
V_32 = V_135 ;
break;
}
case V_166 :
V_32 = V_167 ;
break;
case V_168 :
V_2 -> V_10 . V_48 = F_35 ( V_2 ) ;
V_2 -> V_10 . V_49 = 0 ;
V_32 = V_167 ;
break;
case V_169 :
F_49 ( V_2 , 0x80000 ) ;
V_32 = V_144 ;
break;
default:
F_18 ( V_2 ) ;
F_50 ( V_170 L_14 ,
V_2 -> V_10 . V_35 , F_35 ( V_2 ) ,
V_2 -> V_10 . V_30 . V_29 ) ;
V_32 = V_135 ;
F_51 () ;
break;
}
return V_32 ;
}
int F_52 ( struct V_1 * V_2 ,
struct V_171 * V_172 )
{
int V_161 ;
V_172 -> V_31 = V_2 -> V_10 . V_31 ;
memset ( V_172 , 0 , sizeof( struct V_171 ) ) ;
for ( V_161 = 0 ; V_161 < V_2 -> V_10 . V_50 ; V_161 ++ ) {
V_172 -> V_173 . V_174 . V_175 . V_51 [ V_161 ] . V_176 = V_2 -> V_10 . V_51 [ V_161 ] . V_52 ;
V_172 -> V_173 . V_174 . V_175 . V_51 [ V_161 ] . V_177 = V_2 -> V_10 . V_51 [ V_161 ] . V_53 ;
}
return 0 ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_171 * V_172 )
{
int V_161 , V_178 ;
F_17 ( V_2 , V_172 -> V_31 ) ;
V_178 = 0 ;
for ( V_161 = 0 ; V_161 < V_2 -> V_10 . V_179 ; V_161 ++ ) {
if ( V_172 -> V_173 . V_174 . V_175 . V_51 [ V_161 ] . V_176 & V_180 ) {
V_2 -> V_10 . V_51 [ V_178 ] . V_52 = V_172 -> V_173 . V_174 . V_175 . V_51 [ V_161 ] . V_176 ;
V_2 -> V_10 . V_51 [ V_178 ] . V_53 = V_172 -> V_173 . V_174 . V_175 . V_51 [ V_161 ] . V_177 ;
++ V_178 ;
}
}
V_2 -> V_10 . V_50 = V_178 ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , T_2 V_58 , union V_181 * V_182 )
{
int V_32 = 0 ;
long int V_161 ;
switch ( V_58 ) {
case V_183 :
* V_182 = F_55 ( V_58 , 0 ) ;
break;
case V_184 :
* V_182 = F_55 ( V_58 , V_2 -> V_10 . V_185 ) ;
break;
case V_186 :
* V_182 = F_55 ( V_58 , V_2 -> V_10 . V_187 ) ;
break;
case V_188 :
* V_182 = F_55 ( V_58 , V_2 -> V_10 . V_189 ) ;
break;
case V_190 :
* V_182 = F_55 ( V_58 , V_2 -> V_10 . V_191 ) ;
break;
case V_192 :
* V_182 = F_55 ( V_58 , V_2 -> V_10 . V_193 ) ;
break;
case V_194 :
* V_182 = F_55 ( V_58 , V_2 -> V_10 . V_195 ) ;
break;
case V_196 ... V_197 :
V_161 = V_58 - V_196 ;
* V_182 = F_55 ( V_58 , V_2 -> V_10 . V_198 [ V_161 ] ) ;
break;
case V_199 ... V_200 :
V_161 = V_58 - V_199 ;
* V_182 = F_55 ( V_58 , V_2 -> V_10 . V_201 [ V_161 ] ) ;
break;
#ifdef F_56
case V_202 ... V_203 :
if ( F_57 ( V_204 ) ) {
long int V_161 = V_58 - V_202 ;
* V_182 = F_55 ( V_58 , V_2 -> V_10 . V_205 [ 2 * V_161 ] ) ;
} else {
V_32 = - V_70 ;
}
break;
case V_206 ... V_207 :
if ( F_57 ( V_204 ) ) {
long int V_161 = V_58 - V_206 ;
V_182 -> V_208 [ 0 ] = V_2 -> V_10 . V_205 [ 2 * V_161 ] ;
V_182 -> V_208 [ 1 ] = V_2 -> V_10 . V_205 [ 2 * V_161 + 1 ] ;
} else {
V_32 = - V_209 ;
}
break;
#endif
case V_210 :
F_11 ( & V_2 -> V_10 . V_71 ) ;
* V_182 = F_55 ( V_58 , V_2 -> V_10 . V_63 . V_72 ) ;
F_13 ( & V_2 -> V_10 . V_71 ) ;
break;
case V_211 :
F_11 ( & V_2 -> V_10 . V_71 ) ;
V_182 -> V_212 . V_67 = V_2 -> V_10 . V_96 . V_72 ;
V_182 -> V_212 . V_90 = V_2 -> V_10 . V_96 . V_68 ;
F_13 ( & V_2 -> V_10 . V_71 ) ;
break;
case V_213 :
F_11 ( & V_2 -> V_10 . V_71 ) ;
V_182 -> V_212 . V_67 = V_2 -> V_10 . V_95 . V_72 ;
V_182 -> V_212 . V_90 = V_2 -> V_10 . V_95 . V_68 ;
F_13 ( & V_2 -> V_10 . V_71 ) ;
break;
default:
V_32 = - V_70 ;
break;
}
return V_32 ;
}
int F_58 ( struct V_1 * V_2 , T_2 V_58 , union V_181 * V_182 )
{
int V_32 = 0 ;
long int V_161 ;
unsigned long V_67 , V_68 ;
switch ( V_58 ) {
case V_183 :
if ( F_59 ( V_58 , * V_182 ) )
V_32 = - V_70 ;
break;
case V_184 :
V_2 -> V_10 . V_185 = F_59 ( V_58 , * V_182 ) ;
break;
case V_186 :
V_2 -> V_10 . V_187 = F_59 ( V_58 , * V_182 ) ;
break;
case V_188 :
V_2 -> V_10 . V_189 = F_59 ( V_58 , * V_182 ) ;
break;
case V_190 :
V_2 -> V_10 . V_191 = F_59 ( V_58 , * V_182 ) ;
break;
case V_192 :
V_2 -> V_10 . V_193 = F_59 ( V_58 , * V_182 ) ;
break;
case V_194 :
V_2 -> V_10 . V_195 = F_59 ( V_58 , * V_182 ) ;
break;
case V_196 ... V_197 :
V_161 = V_58 - V_196 ;
V_2 -> V_10 . V_198 [ V_161 ] = F_59 ( V_58 , * V_182 ) ;
break;
case V_199 ... V_200 :
V_161 = V_58 - V_199 ;
V_2 -> V_10 . V_201 [ V_161 ] = F_59 ( V_58 , * V_182 ) ;
break;
#ifdef F_56
case V_202 ... V_203 :
if ( F_57 ( V_204 ) ) {
long int V_161 = V_58 - V_202 ;
V_2 -> V_10 . V_205 [ 2 * V_161 ] = F_59 ( V_58 , * V_182 ) ;
} else {
V_32 = - V_70 ;
}
break;
case V_206 ... V_207 :
if ( F_57 ( V_204 ) ) {
long int V_161 = V_58 - V_206 ;
V_2 -> V_10 . V_205 [ 2 * V_161 ] = V_182 -> V_208 [ 0 ] ;
V_2 -> V_10 . V_205 [ 2 * V_161 + 1 ] = V_182 -> V_208 [ 1 ] ;
} else {
V_32 = - V_209 ;
}
break;
#endif
case V_210 :
V_67 = F_59 ( V_58 , * V_182 ) ;
V_32 = - V_70 ;
if ( ! V_67 && ( V_2 -> V_10 . V_96 . V_72 ||
V_2 -> V_10 . V_95 . V_72 ) )
break;
V_32 = F_26 ( V_2 , & V_2 -> V_10 . V_63 , V_67 , sizeof( struct V_62 ) ) ;
break;
case V_211 :
V_67 = V_182 -> V_212 . V_67 ;
V_68 = V_182 -> V_212 . V_90 ;
V_32 = - V_70 ;
if ( V_67 && ! V_2 -> V_10 . V_63 . V_72 )
break;
V_32 = F_26 ( V_2 , & V_2 -> V_10 . V_96 , V_67 , V_68 ) ;
break;
case V_213 :
V_67 = V_182 -> V_212 . V_67 ;
V_68 = V_182 -> V_212 . V_90 ;
V_32 = - V_70 ;
if ( V_67 && ( V_68 < sizeof( struct V_93 ) ||
! V_2 -> V_10 . V_63 . V_72 ) )
break;
V_68 -= V_68 % sizeof( struct V_93 ) ;
V_32 = F_26 ( V_2 , & V_2 -> V_10 . V_95 , V_67 , V_68 ) ;
break;
default:
V_32 = - V_70 ;
break;
}
return V_32 ;
}
int F_60 ( void )
{
if ( F_57 ( V_214 ) )
return 0 ;
return - V_215 ;
}
struct V_1 * F_61 ( struct V_54 * V_54 , unsigned int V_58 )
{
struct V_1 * V_2 ;
int V_81 = - V_70 ;
int V_216 ;
struct V_15 * V_17 ;
V_216 = V_58 / V_217 ;
if ( V_216 >= V_218 )
goto V_219;
V_81 = - V_220 ;
V_2 = F_62 ( V_221 , V_222 ) ;
if ( ! V_2 )
goto V_219;
V_81 = F_63 ( V_2 , V_54 , V_58 ) ;
if ( V_81 )
goto V_223;
V_2 -> V_10 . V_224 = & V_2 -> V_10 . V_30 ;
V_2 -> V_10 . V_198 [ 0 ] = V_225 ;
V_2 -> V_10 . V_226 = V_227 ;
V_2 -> V_10 . V_31 = F_64 ( V_228 ) ;
F_17 ( V_2 , V_2 -> V_10 . V_31 ) ;
F_65 ( & V_2 -> V_10 . V_71 ) ;
F_65 ( & V_2 -> V_10 . V_18 ) ;
V_2 -> V_10 . V_27 = V_23 ;
F_66 ( V_2 ) ;
V_2 -> V_10 . V_25 = V_229 ;
F_67 ( & V_2 -> V_10 . V_230 ) ;
F_22 ( & V_54 -> V_61 ) ;
V_17 = V_54 -> V_10 . V_231 [ V_216 ] ;
if ( ! V_17 ) {
V_17 = F_68 ( sizeof( struct V_15 ) , V_222 ) ;
if ( V_17 ) {
F_69 ( & V_17 -> V_232 ) ;
F_65 ( & V_17 -> V_61 ) ;
F_67 ( & V_17 -> V_130 ) ;
V_17 -> V_22 = V_23 ;
}
V_54 -> V_10 . V_231 [ V_216 ] = V_17 ;
V_54 -> V_10 . V_233 ++ ;
}
F_24 ( & V_54 -> V_61 ) ;
if ( ! V_17 )
goto V_223;
F_11 ( & V_17 -> V_61 ) ;
++ V_17 -> V_234 ;
F_13 ( & V_17 -> V_61 ) ;
V_2 -> V_10 . V_17 = V_17 ;
V_2 -> V_10 . V_235 = V_236 ;
F_70 ( V_2 ) ;
return V_2 ;
V_223:
F_71 ( V_221 , V_2 ) ;
V_219:
return F_72 ( V_81 ) ;
}
static void F_73 ( struct V_54 * V_54 , struct V_66 * V_63 )
{
if ( V_63 -> V_75 )
F_30 ( V_54 , V_63 -> V_75 , V_63 -> V_100 ,
V_63 -> V_101 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_10 . V_71 ) ;
F_73 ( V_2 -> V_54 , & V_2 -> V_10 . V_95 ) ;
F_73 ( V_2 -> V_54 , & V_2 -> V_10 . V_96 ) ;
F_73 ( V_2 -> V_54 , & V_2 -> V_10 . V_63 ) ;
F_13 ( & V_2 -> V_10 . V_71 ) ;
F_75 ( V_2 ) ;
F_71 ( V_221 , V_2 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
unsigned long V_237 , V_105 ;
V_105 = F_77 () ;
if ( V_105 > V_2 -> V_10 . V_238 ) {
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
return;
}
V_237 = ( V_2 -> V_10 . V_238 - V_105 ) * V_239
/ V_240 ;
F_80 ( & V_2 -> V_10 . V_241 , F_81 ( 0 , V_237 ) ,
V_242 ) ;
V_2 -> V_10 . V_243 = 1 ;
}
static void F_16 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_129 = 0 ;
if ( V_2 -> V_10 . V_243 ) {
F_82 ( & V_2 -> V_10 . V_241 ) ;
V_2 -> V_10 . V_243 = 0 ;
}
}
static void F_83 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
T_2 V_105 ;
if ( V_2 -> V_10 . V_25 != V_244 )
return;
F_11 ( & V_2 -> V_10 . V_18 ) ;
V_105 = F_12 () ;
V_2 -> V_10 . V_28 += F_33 ( V_16 , V_105 ) -
V_2 -> V_10 . V_112 ;
V_2 -> V_10 . V_27 = V_105 ;
V_2 -> V_10 . V_25 = V_26 ;
F_13 ( & V_2 -> V_10 . V_18 ) ;
-- V_16 -> V_245 ;
F_84 ( & V_2 -> V_10 . V_246 ) ;
}
static int F_85 ( int V_4 )
{
struct V_247 * V_248 ;
long V_249 = 1000 ;
V_248 = & V_12 [ V_4 ] ;
V_248 -> V_13 . V_250 = 1 ;
V_248 -> V_13 . V_1 = NULL ;
F_41 () ;
while ( V_248 -> V_13 . V_251 == V_252 ) {
if ( -- V_249 <= 0 ) {
F_19 ( L_15 , V_4 ) ;
return - V_253 ;
}
F_86 ( 1 ) ;
}
return 0 ;
}
static void F_87 ( int V_4 )
{
struct V_247 * V_248 ;
V_248 = & V_12 [ V_4 ] ;
V_248 -> V_13 . V_250 = 0 ;
V_248 -> V_13 . V_1 = NULL ;
}
static void F_88 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_247 * V_248 ;
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
if ( V_2 -> V_10 . V_243 ) {
F_82 ( & V_2 -> V_10 . V_241 ) ;
V_2 -> V_10 . V_243 = 0 ;
}
V_4 = V_16 -> V_115 + V_2 -> V_10 . V_11 ;
V_248 = & V_12 [ V_4 ] ;
V_248 -> V_13 . V_1 = V_2 ;
V_248 -> V_13 . V_254 = V_16 ;
V_248 -> V_13 . V_255 = 0 ;
V_2 -> V_4 = V_16 -> V_115 ;
F_36 () ;
#if F_89 ( V_256 ) && F_89 ( V_257 )
if ( V_2 -> V_10 . V_11 ) {
F_6 ( V_4 ) ;
++ V_16 -> V_258 ;
}
#endif
}
static void F_90 ( struct V_15 * V_16 )
{
int V_161 ;
F_91 () ;
V_161 = 0 ;
while ( V_16 -> V_259 < V_16 -> V_258 ) {
if ( ++ V_161 >= 1000000 ) {
F_19 ( L_16 ,
V_16 -> V_259 , V_16 -> V_258 ) ;
break;
}
F_92 () ;
}
F_93 () ;
}
static int F_94 ( void )
{
int V_4 = F_95 () ;
int V_260 = F_96 ( V_4 ) ;
if ( V_260 )
return 0 ;
while ( ++ V_260 < V_217 )
if ( F_7 ( V_4 + V_260 ) )
return 0 ;
for ( V_260 = 1 ; V_260 < V_217 ; ++ V_260 ) {
if ( F_85 ( V_4 + V_260 ) ) {
do {
F_87 ( V_4 + V_260 ) ;
} while ( -- V_260 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_97 ( struct V_15 * V_16 )
{
struct V_1 * V_2 , * V_261 , * V_262 ;
long V_60 ;
T_2 V_105 ;
int V_11 , V_161 , V_263 ;
int V_264 ;
struct V_1 * V_265 [ V_217 ] ;
V_263 = 0 ;
F_98 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( F_99 ( V_2 -> V_10 . V_107 ) )
return;
if ( V_2 -> V_10 . V_63 . V_73 ||
V_2 -> V_10 . V_96 . V_73 ||
V_2 -> V_10 . V_95 . V_73 )
V_265 [ V_263 ++ ] = V_2 ;
}
V_16 -> V_258 = 0 ;
V_16 -> V_259 = 0 ;
V_16 -> V_266 = 0 ;
V_16 -> V_20 = V_267 ;
V_16 -> V_268 = 0 ;
V_16 -> V_269 = 0 ;
if ( V_263 ) {
F_13 ( & V_16 -> V_61 ) ;
for ( V_161 = 0 ; V_161 < V_263 ; ++ V_161 )
F_32 ( V_265 [ V_161 ] ) ;
F_11 ( & V_16 -> V_61 ) ;
}
V_11 = 0 ;
V_261 = NULL ;
F_98 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( ! V_2 -> V_10 . V_129 ) {
if ( ! V_11 )
V_261 = V_2 ;
V_2 -> V_10 . V_11 = V_11 ++ ;
}
}
if ( ! V_261 )
goto V_219;
F_98 (vcpu, &vc->runnable_threads, arch.run_list)
if ( V_2 -> V_10 . V_129 )
V_2 -> V_10 . V_11 = V_11 ++ ;
if ( V_217 > 1 && ! F_94 () ) {
F_98 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_10 . V_60 = - V_253 ;
goto V_219;
}
V_16 -> V_115 = F_95 () ;
F_98 (vcpu, &vc->runnable_threads, arch.run_list) {
F_88 ( V_2 ) ;
F_34 ( V_2 , V_16 ) ;
}
V_16 -> V_20 = V_270 ;
F_100 () ;
F_13 ( & V_16 -> V_61 ) ;
F_101 () ;
V_264 = F_38 ( & V_261 -> V_54 -> V_125 ) ;
F_102 ( NULL , V_261 ) ;
F_11 ( & V_16 -> V_61 ) ;
F_98 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_4 = - 1 ;
if ( V_16 -> V_259 < V_16 -> V_258 )
F_90 ( V_16 ) ;
for ( V_161 = 0 ; V_161 < V_217 ; ++ V_161 )
F_87 ( V_16 -> V_115 + V_161 ) ;
V_16 -> V_20 = V_271 ;
F_13 ( & V_16 -> V_61 ) ;
F_40 ( & V_261 -> V_54 -> V_125 , V_264 ) ;
F_41 () ;
F_103 () ;
F_104 () ;
F_105 ( V_2 ) ;
F_11 ( & V_16 -> V_61 ) ;
V_105 = F_77 () ;
F_98 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_105 < V_2 -> V_10 . V_238 &&
F_106 ( V_2 ) )
F_107 ( V_2 ) ;
V_60 = V_144 ;
if ( V_2 -> V_10 . V_35 )
V_60 = F_47 ( V_2 -> V_10 . V_145 , V_2 ,
V_2 -> V_10 . V_107 ) ;
V_2 -> V_10 . V_60 = V_60 ;
V_2 -> V_10 . V_35 = 0 ;
if ( V_2 -> V_10 . V_129 ) {
if ( V_60 != V_144 )
F_16 ( V_2 ) ;
else
F_76 ( V_2 ) ;
}
}
V_219:
V_16 -> V_20 = V_21 ;
F_108 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( V_2 -> V_10 . V_60 != V_144 ) {
F_83 ( V_16 , V_2 ) ;
F_109 ( & V_2 -> V_10 . V_230 ) ;
}
}
}
static void F_110 ( struct V_1 * V_2 , int V_272 )
{
F_111 ( V_273 ) ;
F_112 ( & V_2 -> V_10 . V_230 , & V_273 , V_272 ) ;
if ( V_2 -> V_10 . V_25 == V_244 )
F_113 () ;
F_114 ( & V_2 -> V_10 . V_230 , & V_273 ) ;
}
static void F_115 ( struct V_15 * V_16 )
{
F_111 ( V_273 ) ;
F_112 ( & V_16 -> V_130 , & V_273 , V_274 ) ;
V_16 -> V_20 = V_275 ;
F_13 ( & V_16 -> V_61 ) ;
F_113 () ;
F_114 ( & V_16 -> V_130 , & V_273 ) ;
F_11 ( & V_16 -> V_61 ) ;
V_16 -> V_20 = V_21 ;
}
static int F_116 ( struct V_145 * V_145 , struct V_1 * V_2 )
{
int V_276 ;
struct V_15 * V_16 ;
struct V_1 * V_59 , * V_277 ;
V_145 -> V_150 = 0 ;
V_2 -> V_10 . V_60 = V_144 ;
V_2 -> V_10 . V_35 = 0 ;
F_32 ( V_2 ) ;
V_16 = V_2 -> V_10 . V_17 ;
F_11 ( & V_16 -> V_61 ) ;
V_2 -> V_10 . V_129 = 0 ;
V_2 -> V_10 . V_107 = V_108 ;
V_2 -> V_10 . V_145 = V_145 ;
V_2 -> V_10 . V_112 = F_33 ( V_16 , F_12 () ) ;
V_2 -> V_10 . V_25 = V_244 ;
V_2 -> V_10 . V_27 = V_23 ;
F_117 ( & V_2 -> V_10 . V_246 , & V_16 -> V_232 ) ;
++ V_16 -> V_245 ;
if ( ! F_99 ( V_108 ) ) {
if ( V_16 -> V_20 == V_270 &&
F_118 ( V_16 ) == 0 ) {
V_2 -> V_10 . V_11 = V_16 -> V_245 - 1 ;
F_34 ( V_2 , V_16 ) ;
F_88 ( V_2 ) ;
} else if ( V_16 -> V_20 == V_275 ) {
F_109 ( & V_16 -> V_130 ) ;
}
}
while ( V_2 -> V_10 . V_25 == V_244 &&
! F_99 ( V_108 ) ) {
if ( V_16 -> V_20 != V_21 ) {
F_13 ( & V_16 -> V_61 ) ;
F_110 ( V_2 , V_274 ) ;
F_11 ( & V_16 -> V_61 ) ;
continue;
}
F_108 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_79 ( V_59 ) ;
if ( F_99 ( V_59 -> V_10 . V_107 ) ) {
F_83 ( V_16 , V_59 ) ;
V_59 -> V_6 . V_278 ++ ;
V_59 -> V_10 . V_145 -> V_150 = V_279 ;
V_59 -> V_10 . V_60 = - V_280 ;
F_109 ( & V_59 -> V_10 . V_230 ) ;
}
}
if ( ! V_16 -> V_245 || V_2 -> V_10 . V_25 != V_244 )
break;
V_16 -> V_19 = V_2 ;
V_276 = 0 ;
F_98 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_59 -> V_10 . V_281 )
V_276 += V_59 -> V_10 . V_129 ;
else
V_59 -> V_10 . V_129 = 0 ;
}
if ( V_276 == V_16 -> V_245 )
F_115 ( V_16 ) ;
else
F_97 ( V_16 ) ;
V_16 -> V_19 = NULL ;
}
while ( V_2 -> V_10 . V_25 == V_244 &&
( V_16 -> V_20 == V_270 ||
V_16 -> V_20 == V_271 ) ) {
F_13 ( & V_16 -> V_61 ) ;
F_110 ( V_2 , V_282 ) ;
F_11 ( & V_16 -> V_61 ) ;
}
if ( V_2 -> V_10 . V_25 == V_244 ) {
F_83 ( V_16 , V_2 ) ;
V_2 -> V_6 . V_278 ++ ;
V_145 -> V_150 = V_279 ;
V_2 -> V_10 . V_60 = - V_280 ;
}
if ( V_16 -> V_245 && V_16 -> V_20 == V_21 ) {
V_59 = F_119 ( & V_16 -> V_232 ,
struct V_1 , V_10 . V_246 ) ;
F_109 ( & V_59 -> V_10 . V_230 ) ;
}
F_13 ( & V_16 -> V_61 ) ;
return V_2 -> V_10 . V_60 ;
}
int F_120 ( struct V_145 * V_146 , struct V_1 * V_2 )
{
int V_32 ;
int V_264 ;
if ( ! V_2 -> V_10 . V_283 ) {
V_146 -> V_150 = V_284 ;
return - V_70 ;
}
F_79 ( V_2 ) ;
if ( F_99 ( V_108 ) ) {
V_146 -> V_150 = V_279 ;
return - V_280 ;
}
F_121 ( & V_2 -> V_54 -> V_10 . V_285 ) ;
F_41 () ;
if ( ! V_2 -> V_54 -> V_10 . V_286 ) {
V_32 = F_122 ( V_2 ) ;
if ( V_32 )
goto V_219;
}
F_123 ( V_108 ) ;
F_124 ( V_108 ) ;
F_125 ( V_108 ) ;
V_2 -> V_10 . V_5 = & V_2 -> V_10 . V_17 -> V_130 ;
V_2 -> V_10 . V_287 = V_108 -> V_288 -> V_289 ;
V_2 -> V_10 . V_25 = V_26 ;
do {
V_32 = F_116 ( V_146 , V_2 ) ;
if ( V_146 -> V_150 == V_165 &&
! ( V_2 -> V_10 . V_30 . V_29 & V_162 ) ) {
V_32 = F_37 ( V_2 ) ;
F_79 ( V_2 ) ;
} else if ( V_32 == V_167 ) {
V_264 = F_38 ( & V_2 -> V_54 -> V_125 ) ;
V_32 = F_126 ( V_146 , V_2 ,
V_2 -> V_10 . V_48 , V_2 -> V_10 . V_49 ) ;
F_40 ( & V_2 -> V_54 -> V_125 , V_264 ) ;
}
} while ( V_32 == V_144 );
V_219:
V_2 -> V_10 . V_25 = V_229 ;
F_127 ( & V_2 -> V_54 -> V_10 . V_285 ) ;
return V_32 ;
}
static inline int F_128 ( unsigned long V_290 )
{
switch ( V_290 ) {
case 32ul << 20 :
if ( F_57 ( V_291 ) )
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
static int F_129 ( struct V_292 * V_293 , struct V_294 * V_295 )
{
struct V_296 * V_297 = V_293 -> V_298 -> V_299 ;
struct V_300 * V_300 ;
if ( V_295 -> V_301 >= V_297 -> V_302 )
return V_303 ;
V_300 = F_130 ( V_297 -> V_304 + V_295 -> V_301 ) ;
F_131 ( V_300 ) ;
V_295 -> V_300 = V_300 ;
return 0 ;
}
static int F_132 ( struct V_305 * V_305 , struct V_292 * V_293 )
{
V_293 -> V_306 |= V_307 | V_308 ;
V_293 -> V_309 = & V_310 ;
return 0 ;
}
static int F_133 ( struct V_311 * V_311 , struct V_305 * V_312 )
{
struct V_296 * V_297 = V_312 -> V_299 ;
F_134 ( V_297 ) ;
return 0 ;
}
long F_135 ( struct V_54 * V_54 , struct V_313 * V_60 )
{
struct V_296 * V_297 ;
long V_314 ;
V_297 = F_136 () ;
if ( ! V_297 )
return - V_220 ;
V_314 = F_137 ( L_17 , & V_315 , V_297 , V_316 ) ;
if ( V_314 < 0 )
F_134 ( V_297 ) ;
V_60 -> V_290 = V_297 -> V_302 << V_317 ;
return V_314 ;
}
static void F_138 ( struct V_318 * * V_319 ,
int V_320 )
{
struct V_321 * V_322 = & V_323 [ V_320 ] ;
if ( ! V_322 -> V_324 )
return;
( * V_319 ) -> V_325 = V_322 -> V_324 ;
( * V_319 ) -> V_326 = V_322 -> V_327 ;
( * V_319 ) -> V_328 [ 0 ] . V_325 = V_322 -> V_324 ;
( * V_319 ) -> V_328 [ 0 ] . V_329 = V_322 -> V_330 [ V_320 ] ;
( * V_319 ) ++ ;
}
int F_139 ( struct V_54 * V_54 , struct V_331 * V_332 )
{
struct V_318 * V_319 ;
V_332 -> V_76 = V_333 ;
if ( F_140 ( V_334 ) )
V_332 -> V_76 |= V_335 ;
V_332 -> V_336 = V_337 ;
V_319 = & V_332 -> V_319 [ 0 ] ;
F_138 ( & V_319 , V_338 ) ;
F_138 ( & V_319 , V_339 ) ;
F_138 ( & V_319 , V_340 ) ;
return 0 ;
}
int F_141 ( struct V_54 * V_54 , struct V_341 * log )
{
struct V_342 * V_343 ;
int V_32 ;
unsigned long V_344 ;
F_22 ( & V_54 -> V_345 ) ;
V_32 = - V_70 ;
if ( log -> V_346 >= V_347 )
goto V_219;
V_343 = F_142 ( V_54 -> V_348 , log -> V_346 ) ;
V_32 = - V_136 ;
if ( ! V_343 -> V_349 )
goto V_219;
V_344 = F_143 ( V_343 ) ;
memset ( V_343 -> V_349 , 0 , V_344 ) ;
V_32 = F_144 ( V_54 , V_343 , V_343 -> V_349 ) ;
if ( V_32 )
goto V_219;
V_32 = - V_350 ;
if ( F_145 ( log -> V_349 , V_343 -> V_349 , V_344 ) )
goto V_219;
V_32 = 0 ;
V_219:
F_24 ( & V_54 -> V_345 ) ;
return V_32 ;
}
static void F_146 ( struct V_342 * V_343 )
{
unsigned long * V_351 ;
unsigned long V_178 , V_302 , V_352 ;
struct V_300 * V_300 ;
V_351 = V_343 -> V_10 . V_353 ;
V_302 = V_343 -> V_302 ;
if ( ! V_351 )
return;
for ( V_178 = 0 ; V_178 < V_302 ; V_178 ++ ) {
if ( ! ( V_351 [ V_178 ] & V_354 ) )
continue;
V_352 = V_351 [ V_178 ] >> V_317 ;
V_300 = F_130 ( V_352 ) ;
F_147 ( V_300 ) ;
F_148 ( V_300 ) ;
}
}
void F_149 ( struct V_342 * free ,
struct V_342 * V_355 )
{
if ( ! V_355 || free -> V_10 . V_356 != V_355 -> V_10 . V_356 ) {
F_150 ( free -> V_10 . V_356 ) ;
free -> V_10 . V_356 = NULL ;
}
if ( ! V_355 || free -> V_10 . V_353 != V_355 -> V_10 . V_353 ) {
F_146 ( free ) ;
F_150 ( free -> V_10 . V_353 ) ;
free -> V_10 . V_353 = NULL ;
}
}
int F_151 ( struct V_342 * V_346 ,
unsigned long V_302 )
{
V_346 -> V_10 . V_356 = F_152 ( V_302 * sizeof( * V_346 -> V_10 . V_356 ) ) ;
if ( ! V_346 -> V_10 . V_356 )
return - V_220 ;
V_346 -> V_10 . V_353 = NULL ;
return 0 ;
}
int F_153 ( struct V_54 * V_54 ,
struct V_342 * V_343 ,
struct V_357 * V_358 )
{
unsigned long * V_359 ;
V_359 = V_343 -> V_10 . V_353 ;
if ( ! V_54 -> V_10 . V_360 && ! V_359 && V_343 -> V_302 ) {
V_359 = F_152 ( V_343 -> V_302 * sizeof( unsigned long ) ) ;
if ( ! V_359 )
return - V_220 ;
V_343 -> V_10 . V_353 = V_359 ;
}
return 0 ;
}
void F_154 ( struct V_54 * V_54 ,
struct V_357 * V_358 ,
const struct V_342 * V_361 )
{
unsigned long V_302 = V_358 -> V_362 >> V_317 ;
struct V_342 * V_343 ;
if ( V_302 && V_361 -> V_302 ) {
V_343 = F_142 ( V_54 -> V_348 , V_358 -> V_346 ) ;
F_144 ( V_54 , V_343 , NULL ) ;
}
}
static int F_122 ( struct V_1 * V_2 )
{
int V_81 = 0 ;
struct V_54 * V_54 = V_2 -> V_54 ;
struct V_296 * V_297 = NULL ;
unsigned long V_363 ;
struct V_342 * V_343 ;
struct V_292 * V_293 ;
unsigned long V_55 , V_364 ;
unsigned long V_365 , V_366 ;
unsigned long V_290 ;
unsigned long V_367 ;
unsigned long * V_351 ;
unsigned long V_161 , V_302 ;
int V_264 ;
F_22 ( & V_54 -> V_61 ) ;
if ( V_54 -> V_10 . V_286 )
goto V_219;
if ( ! V_54 -> V_10 . V_368 ) {
V_81 = F_155 ( V_54 , NULL ) ;
if ( V_81 ) {
F_19 ( L_18 ) ;
goto V_219;
}
}
V_264 = F_38 ( & V_54 -> V_125 ) ;
V_343 = F_156 ( V_54 , 0 ) ;
V_81 = - V_70 ;
if ( ! V_343 || ( V_343 -> V_76 & V_369 ) )
goto V_370;
V_363 = V_343 -> V_371 ;
F_157 ( & V_108 -> V_288 -> V_372 ) ;
V_293 = F_158 ( V_108 -> V_288 , V_363 ) ;
if ( ! V_293 || V_293 -> V_373 > V_363 || ( V_293 -> V_306 & V_374 ) )
goto V_375;
V_365 = F_159 ( V_293 ) ;
V_366 = F_160 ( V_365 ) ;
if ( V_293 -> V_298 && V_293 -> V_298 -> V_376 == & V_315 &&
V_363 == V_293 -> V_373 )
V_297 = V_293 -> V_298 -> V_299 ;
F_161 ( & V_108 -> V_288 -> V_372 ) ;
if ( ! V_297 ) {
V_81 = - V_377 ;
if ( F_57 ( V_378 ) ) {
F_19 ( L_19 ) ;
goto V_370;
}
V_81 = - V_70 ;
if ( ! ( V_365 == 0x1000 || V_365 == 0x10000 ||
V_365 == 0x1000000 ) )
goto V_370;
V_364 = F_162 ( V_365 ) ;
V_54 -> V_10 . V_379 = V_364 | V_380 |
( V_381 << V_382 ) ;
V_55 = V_54 -> V_10 . V_55 & ~ V_383 ;
V_55 |= V_364 << ( V_384 - 4 ) ;
V_54 -> V_10 . V_55 = V_55 ;
F_163 ( V_2 , V_343 , V_366 ) ;
} else {
V_290 = V_297 -> V_302 ;
if ( V_290 > V_343 -> V_302 )
V_290 = V_343 -> V_302 ;
V_290 <<= V_317 ;
V_367 = F_128 ( V_290 ) ;
V_81 = - V_70 ;
if ( V_367 < 0 ) {
F_19 ( L_20 , V_290 ) ;
goto V_370;
}
F_121 ( & V_297 -> V_385 ) ;
V_54 -> V_10 . V_386 = V_297 ;
V_55 = V_54 -> V_10 . V_55 ;
if ( F_57 ( V_378 ) ) {
V_55 &= ~ ( ( 1ul << V_387 ) |
( 3ul << V_388 ) ) ;
V_55 |= ( ( V_367 >> 2 ) << V_387 ) |
( ( V_367 & 3 ) << V_388 ) ;
V_55 |= ( ( V_297 -> V_304 >> ( 26 - V_317 ) ) & 0xffff )
<< V_389 ;
} else {
V_55 &= ~ ( V_390 | V_391 ) ;
V_55 |= V_367 << V_392 ;
V_54 -> V_10 . V_393 = V_54 -> V_10 . V_386 -> V_304 << V_317 ;
}
V_54 -> V_10 . V_55 = V_55 ;
F_164 ( L_21 ,
V_297 -> V_304 << V_317 , V_290 , V_55 ) ;
V_302 = V_297 -> V_302 ;
V_366 = F_160 ( V_302 ) ;
V_351 = V_343 -> V_10 . V_353 ;
if ( V_351 ) {
if ( V_302 > V_343 -> V_302 )
V_302 = V_343 -> V_302 ;
F_11 ( & V_54 -> V_10 . V_394 ) ;
for ( V_161 = 0 ; V_161 < V_302 ; ++ V_161 )
V_351 [ V_161 ] = ( ( V_297 -> V_304 + V_161 ) << V_317 ) +
V_366 ;
F_13 ( & V_54 -> V_10 . V_394 ) ;
}
}
F_36 () ;
V_54 -> V_10 . V_286 = 1 ;
V_81 = 0 ;
V_370:
F_40 ( & V_54 -> V_125 , V_264 ) ;
V_219:
F_24 ( & V_54 -> V_61 ) ;
return V_81 ;
V_375:
F_161 ( & V_108 -> V_288 -> V_372 ) ;
goto V_219;
}
int F_165 ( struct V_54 * V_54 )
{
unsigned long V_55 , V_395 ;
V_395 = F_166 () ;
if ( V_395 < 0 )
return - V_220 ;
V_54 -> V_10 . V_395 = V_395 ;
F_167 ( & V_54 -> V_10 . V_396 ) ;
F_69 ( & V_54 -> V_10 . V_397 ) ;
F_69 ( & V_54 -> V_10 . V_134 ) ;
V_54 -> V_10 . V_386 = NULL ;
V_54 -> V_10 . V_398 = F_64 ( V_399 ) ;
if ( F_57 ( V_378 ) ) {
V_54 -> V_10 . V_400 = 0 ;
V_54 -> V_10 . V_401 = V_55 = F_64 ( V_402 ) ;
V_55 &= ~ ( ( 3 << V_403 ) | ( 0xful << V_404 ) ) ;
V_55 |= ( ( V_395 >> 4 ) << V_403 ) |
( ( V_395 & 0xf ) << V_404 ) ;
} else {
V_54 -> V_10 . V_400 = F_64 ( V_405 ) ;
V_54 -> V_10 . V_401 = V_55 = F_64 ( V_406 ) ;
V_55 &= V_407 | V_408 ;
V_55 |= ( 4UL << V_409 ) | V_410 |
V_390 | V_411 ;
V_54 -> V_10 . V_379 = V_380 |
( V_381 << V_382 ) ;
}
V_54 -> V_10 . V_55 = V_55 ;
V_54 -> V_10 . V_360 = ! ! F_57 ( V_291 ) ;
F_65 ( & V_54 -> V_10 . V_394 ) ;
F_168 () ;
return 0 ;
}
void F_169 ( struct V_54 * V_54 )
{
F_170 () ;
if ( V_54 -> V_10 . V_386 ) {
F_134 ( V_54 -> V_10 . V_386 ) ;
V_54 -> V_10 . V_386 = NULL ;
}
F_171 ( V_54 ) ;
F_172 ( V_54 ) ;
F_173 ( ! F_42 ( & V_54 -> V_10 . V_397 ) ) ;
}
void F_174 ( struct V_1 * V_2 , T_4 V_412 , T_4 V_413 )
{
}
int F_175 ( struct V_145 * V_146 , struct V_1 * V_2 ,
unsigned int V_414 , int * V_415 )
{
return V_416 ;
}
int F_176 ( struct V_1 * V_2 , int V_417 , T_4 V_418 )
{
return V_416 ;
}
int F_177 ( struct V_1 * V_2 , int V_417 , T_4 * V_418 )
{
return V_416 ;
}
static int F_178 ( void )
{
int V_32 ;
V_32 = F_179 ( NULL , sizeof( struct V_1 ) , 0 , V_419 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_180 () ;
return V_32 ;
}
static void F_181 ( void )
{
F_182 () ;
}

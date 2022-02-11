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
V_63 -> V_64 |= V_65 ;
V_63 -> V_66 = 1 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_67 * V_59 ,
unsigned long V_68 , unsigned long V_69 )
{
if ( V_68 & ( V_70 - 1 ) )
return - V_71 ;
F_11 ( & V_2 -> V_10 . V_72 ) ;
if ( V_59 -> V_73 != V_68 || V_59 -> V_69 != V_69 ) {
V_59 -> V_73 = V_68 ;
V_59 -> V_69 = V_68 ? V_69 : 0 ;
V_59 -> V_74 = 1 ;
}
F_13 ( & V_2 -> V_10 . V_72 ) ;
return 0 ;
}
static int F_27 ( struct V_67 * V_75 )
{
if ( V_75 -> V_74 )
return V_75 -> V_73 != 0 ;
return V_75 -> V_76 != NULL ;
}
static unsigned long F_28 ( struct V_1 * V_2 ,
unsigned long V_77 ,
unsigned long V_78 , unsigned long V_63 )
{
struct V_54 * V_54 = V_2 -> V_54 ;
unsigned long V_69 , V_79 ;
void * V_80 ;
struct V_1 * V_81 ;
int V_82 ;
int V_83 ;
struct V_67 * V_75 ;
V_81 = F_21 ( V_54 , V_78 ) ;
if ( ! V_81 )
return V_84 ;
V_83 = ( V_77 >> V_85 ) & V_86 ;
if ( V_83 == V_87 || V_83 == V_88 ||
V_83 == V_89 ) {
if ( ( V_63 & ( V_70 - 1 ) ) || ! V_63 )
return V_84 ;
V_80 = F_29 ( V_54 , V_63 , & V_79 ) ;
if ( V_80 == NULL )
return V_84 ;
if ( V_83 == V_87 )
V_69 = ( (struct V_90 * ) V_80 ) -> V_91 . V_92 ;
else
V_69 = ( (struct V_90 * ) V_80 ) -> V_91 . V_93 ;
F_30 ( V_54 , V_80 , V_63 , false ) ;
if ( V_69 > V_79 || V_69 < sizeof( struct V_90 ) )
return V_84 ;
} else {
V_63 = 0 ;
V_69 = 0 ;
}
V_82 = V_84 ;
V_75 = NULL ;
F_11 ( & V_81 -> V_10 . V_72 ) ;
switch ( V_83 ) {
case V_87 :
if ( V_69 < sizeof( struct V_62 ) )
break;
V_75 = & V_81 -> V_10 . V_63 ;
V_82 = 0 ;
break;
case V_88 :
if ( V_69 < sizeof( struct V_94 ) )
break;
V_69 -= V_69 % sizeof( struct V_94 ) ;
V_82 = V_95 ;
if ( ! F_27 ( & V_81 -> V_10 . V_63 ) )
break;
V_75 = & V_81 -> V_10 . V_96 ;
V_82 = 0 ;
break;
case V_89 :
V_82 = V_95 ;
if ( ! F_27 ( & V_81 -> V_10 . V_63 ) )
break;
V_75 = & V_81 -> V_10 . V_97 ;
V_82 = 0 ;
break;
case V_98 :
V_82 = V_95 ;
if ( F_27 ( & V_81 -> V_10 . V_96 ) ||
F_27 ( & V_81 -> V_10 . V_97 ) )
break;
V_75 = & V_81 -> V_10 . V_63 ;
V_82 = 0 ;
break;
case V_99 :
V_75 = & V_81 -> V_10 . V_96 ;
V_82 = 0 ;
break;
case V_100 :
V_75 = & V_81 -> V_10 . V_97 ;
V_82 = 0 ;
break;
}
if ( V_75 ) {
V_75 -> V_73 = V_63 ;
V_75 -> V_69 = V_69 ;
V_75 -> V_74 = 1 ;
}
F_13 ( & V_81 -> V_10 . V_72 ) ;
return V_82 ;
}
static void F_31 ( struct V_1 * V_2 , struct V_67 * V_75 )
{
struct V_54 * V_54 = V_2 -> V_54 ;
void * V_80 ;
unsigned long V_79 ;
unsigned long V_101 ;
for (; ; ) {
V_101 = V_75 -> V_73 ;
F_13 ( & V_2 -> V_10 . V_72 ) ;
V_80 = NULL ;
V_79 = 0 ;
if ( V_101 )
V_80 = F_29 ( V_54 , V_101 , & V_79 ) ;
F_11 ( & V_2 -> V_10 . V_72 ) ;
if ( V_101 == V_75 -> V_73 )
break;
if ( V_80 )
F_30 ( V_54 , V_80 , V_101 , false ) ;
}
V_75 -> V_74 = 0 ;
if ( V_80 && V_79 < V_75 -> V_69 ) {
F_30 ( V_54 , V_80 , V_101 , false ) ;
V_80 = NULL ;
}
if ( V_75 -> V_76 )
F_30 ( V_54 , V_75 -> V_76 , V_75 -> V_101 ,
V_75 -> V_102 ) ;
V_75 -> V_101 = V_101 ;
V_75 -> V_76 = V_80 ;
V_75 -> V_102 = false ;
if ( V_80 )
V_75 -> V_103 = V_80 + V_75 -> V_69 ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_10 . V_63 . V_74 ||
V_2 -> V_10 . V_97 . V_74 ||
V_2 -> V_10 . V_96 . V_74 ) )
return;
F_11 ( & V_2 -> V_10 . V_72 ) ;
if ( V_2 -> V_10 . V_63 . V_74 ) {
F_31 ( V_2 , & V_2 -> V_10 . V_63 ) ;
if ( V_2 -> V_10 . V_63 . V_76 )
F_25 ( V_2 , V_2 -> V_10 . V_63 . V_76 ) ;
}
if ( V_2 -> V_10 . V_96 . V_74 ) {
F_31 ( V_2 , & V_2 -> V_10 . V_96 ) ;
V_2 -> V_10 . V_104 = V_2 -> V_10 . V_96 . V_76 ;
V_2 -> V_10 . V_105 = 0 ;
}
if ( V_2 -> V_10 . V_97 . V_74 )
F_31 ( V_2 , & V_2 -> V_10 . V_97 ) ;
F_13 ( & V_2 -> V_10 . V_72 ) ;
}
static T_2 F_33 ( struct V_15 * V_16 , T_2 V_106 )
{
T_2 V_107 ;
if ( V_16 -> V_20 != V_21 &&
V_16 -> V_19 -> V_10 . V_108 != V_109 ) {
F_11 ( & V_16 -> V_19 -> V_10 . V_18 ) ;
V_107 = V_16 -> V_24 ;
if ( V_16 -> V_22 != V_23 )
V_107 += V_106 - V_16 -> V_22 ;
F_13 ( & V_16 -> V_19 -> V_10 . V_18 ) ;
} else {
V_107 = V_16 -> V_24 ;
}
return V_107 ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_94 * V_110 ;
struct V_62 * V_63 ;
unsigned long V_111 ;
unsigned long V_112 ;
T_2 V_106 ;
V_110 = V_2 -> V_10 . V_104 ;
V_63 = V_2 -> V_10 . V_63 . V_76 ;
V_106 = F_12 () ;
V_112 = F_33 ( V_16 , V_106 ) ;
V_111 = V_112 - V_2 -> V_10 . V_113 ;
V_2 -> V_10 . V_113 = V_112 ;
F_11 ( & V_2 -> V_10 . V_18 ) ;
V_111 += V_2 -> V_10 . V_28 ;
V_2 -> V_10 . V_28 = 0 ;
F_13 ( & V_2 -> V_10 . V_18 ) ;
if ( ! V_110 || ! V_63 )
return;
memset ( V_110 , 0 , sizeof( struct V_94 ) ) ;
V_110 -> V_114 = 7 ;
V_110 -> V_115 = V_16 -> V_116 + V_2 -> V_10 . V_11 ;
V_110 -> V_117 = V_106 ;
V_110 -> V_118 = V_111 ;
V_110 -> V_38 = F_35 ( V_2 ) ;
V_110 -> V_39 = V_2 -> V_10 . V_30 . V_29 ;
++ V_110 ;
if ( V_110 == V_2 -> V_10 . V_96 . V_103 )
V_110 = V_2 -> V_10 . V_96 . V_76 ;
V_2 -> V_10 . V_104 = V_110 ;
F_36 () ;
V_63 -> V_119 = ++ V_2 -> V_10 . V_105 ;
V_2 -> V_10 . V_96 . V_102 = true ;
}
int F_37 ( struct V_1 * V_2 )
{
unsigned long V_120 = F_20 ( V_2 , 3 ) ;
unsigned long V_121 , V_60 = V_122 ;
struct V_1 * V_81 ;
int V_123 , V_124 ;
switch ( V_120 ) {
case V_125 :
V_123 = F_38 ( & V_2 -> V_54 -> V_126 ) ;
V_60 = F_39 ( V_2 , F_20 ( V_2 , 4 ) ,
F_20 ( V_2 , 5 ) ,
F_20 ( V_2 , 6 ) ,
F_20 ( V_2 , 7 ) ) ;
F_40 ( & V_2 -> V_54 -> V_126 , V_123 ) ;
break;
case V_127 :
break;
case V_128 :
V_121 = F_20 ( V_2 , 4 ) ;
V_81 = F_21 ( V_2 -> V_54 , V_121 ) ;
if ( ! V_81 ) {
V_60 = V_84 ;
break;
}
V_81 -> V_10 . V_129 = 1 ;
F_41 () ;
if ( V_2 -> V_10 . V_130 ) {
if ( F_3 ( & V_2 -> V_131 ) ) {
F_4 ( & V_2 -> V_131 ) ;
V_2 -> V_6 . V_7 ++ ;
}
}
break;
case V_132 :
break;
case V_133 :
V_60 = F_28 ( V_2 , F_20 ( V_2 , 4 ) ,
F_20 ( V_2 , 5 ) ,
F_20 ( V_2 , 6 ) ) ;
break;
case V_134 :
if ( F_42 ( & V_2 -> V_54 -> V_10 . V_135 ) )
return V_136 ;
V_124 = F_43 ( V_2 ) ;
if ( V_124 == - V_137 )
return V_136 ;
else if ( V_124 == 0 )
break;
return V_124 ;
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
if ( F_44 ( V_2 ) ) {
V_60 = F_45 ( V_2 , V_120 ) ;
break;
}
default:
return V_136 ;
}
F_46 ( V_2 , 3 , V_60 ) ;
V_2 -> V_10 . V_144 = 0 ;
return V_145 ;
}
static int F_47 ( struct V_146 * V_147 , struct V_1 * V_2 ,
struct V_148 * V_149 )
{
int V_32 = V_136 ;
V_2 -> V_6 . V_150 ++ ;
V_147 -> V_151 = V_152 ;
V_147 -> V_153 = 1 ;
switch ( V_2 -> V_10 . V_35 ) {
case V_154 :
V_2 -> V_6 . V_155 ++ ;
V_32 = V_145 ;
break;
case V_156 :
V_2 -> V_6 . V_157 ++ ;
V_32 = V_145 ;
break;
case V_158 :
V_32 = V_145 ;
break;
case V_159 :
F_48 ( V_2 ,
V_159 ) ;
V_32 = V_145 ;
break;
case V_160 :
{
T_4 V_77 ;
V_77 = V_2 -> V_10 . V_30 . V_29 & 0x1f0000ull ;
F_49 ( V_2 , V_77 ) ;
V_32 = V_145 ;
break;
}
case V_161 :
{
int V_162 ;
if ( V_2 -> V_10 . V_30 . V_29 & V_163 ) {
F_48 ( V_2 , V_161 ) ;
V_32 = V_145 ;
break;
}
V_147 -> V_164 . V_165 = F_20 ( V_2 , 3 ) ;
for ( V_162 = 0 ; V_162 < 9 ; ++ V_162 )
V_147 -> V_164 . args [ V_162 ] = F_20 ( V_2 , 4 + V_162 ) ;
V_147 -> V_151 = V_166 ;
V_2 -> V_10 . V_144 = 1 ;
V_32 = V_136 ;
break;
}
case V_167 :
V_32 = V_168 ;
break;
case V_169 :
V_2 -> V_10 . V_48 = F_35 ( V_2 ) ;
V_2 -> V_10 . V_49 = 0 ;
V_32 = V_168 ;
break;
case V_170 :
F_49 ( V_2 , 0x80000 ) ;
V_32 = V_145 ;
break;
default:
F_18 ( V_2 ) ;
F_50 ( V_171 L_14 ,
V_2 -> V_10 . V_35 , F_35 ( V_2 ) ,
V_2 -> V_10 . V_30 . V_29 ) ;
V_32 = V_136 ;
F_51 () ;
break;
}
return V_32 ;
}
int F_52 ( struct V_1 * V_2 ,
struct V_172 * V_173 )
{
int V_162 ;
memset ( V_173 , 0 , sizeof( struct V_172 ) ) ;
V_173 -> V_31 = V_2 -> V_10 . V_31 ;
for ( V_162 = 0 ; V_162 < V_2 -> V_10 . V_50 ; V_162 ++ ) {
V_173 -> V_174 . V_175 . V_176 . V_51 [ V_162 ] . V_177 = V_2 -> V_10 . V_51 [ V_162 ] . V_52 ;
V_173 -> V_174 . V_175 . V_176 . V_51 [ V_162 ] . V_178 = V_2 -> V_10 . V_51 [ V_162 ] . V_53 ;
}
return 0 ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_172 * V_173 )
{
int V_162 , V_179 ;
F_17 ( V_2 , V_173 -> V_31 ) ;
V_179 = 0 ;
for ( V_162 = 0 ; V_162 < V_2 -> V_10 . V_180 ; V_162 ++ ) {
if ( V_173 -> V_174 . V_175 . V_176 . V_51 [ V_162 ] . V_177 & V_181 ) {
V_2 -> V_10 . V_51 [ V_179 ] . V_52 = V_173 -> V_174 . V_175 . V_176 . V_51 [ V_162 ] . V_177 ;
V_2 -> V_10 . V_51 [ V_179 ] . V_53 = V_173 -> V_174 . V_175 . V_176 . V_51 [ V_162 ] . V_178 ;
++ V_179 ;
}
}
V_2 -> V_10 . V_50 = V_179 ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , T_2 V_58 , union V_182 * V_183 )
{
int V_32 = 0 ;
long int V_162 ;
switch ( V_58 ) {
case V_184 :
* V_183 = F_55 ( V_58 , 0 ) ;
break;
case V_185 :
* V_183 = F_55 ( V_58 , V_2 -> V_10 . V_186 ) ;
break;
case V_187 :
* V_183 = F_55 ( V_58 , V_2 -> V_10 . V_188 ) ;
break;
case V_189 :
* V_183 = F_55 ( V_58 , V_2 -> V_10 . V_190 ) ;
break;
case V_191 :
* V_183 = F_55 ( V_58 , V_2 -> V_10 . V_192 ) ;
break;
case V_193 :
* V_183 = F_55 ( V_58 , V_2 -> V_10 . V_194 ) ;
break;
case V_195 :
* V_183 = F_55 ( V_58 , V_2 -> V_10 . V_196 ) ;
break;
case V_197 ... V_198 :
V_162 = V_58 - V_197 ;
* V_183 = F_55 ( V_58 , V_2 -> V_10 . V_199 [ V_162 ] ) ;
break;
case V_200 ... V_201 :
V_162 = V_58 - V_200 ;
* V_183 = F_55 ( V_58 , V_2 -> V_10 . V_202 [ V_162 ] ) ;
break;
#ifdef F_56
case V_203 ... V_204 :
if ( F_57 ( V_205 ) ) {
long int V_162 = V_58 - V_203 ;
* V_183 = F_55 ( V_58 , V_2 -> V_10 . V_206 [ 2 * V_162 ] ) ;
} else {
V_32 = - V_71 ;
}
break;
case V_207 ... V_208 :
if ( F_57 ( V_205 ) ) {
long int V_162 = V_58 - V_207 ;
V_183 -> V_209 [ 0 ] = V_2 -> V_10 . V_206 [ 2 * V_162 ] ;
V_183 -> V_209 [ 1 ] = V_2 -> V_10 . V_206 [ 2 * V_162 + 1 ] ;
} else {
V_32 = - V_210 ;
}
break;
#endif
case V_211 :
F_11 ( & V_2 -> V_10 . V_72 ) ;
* V_183 = F_55 ( V_58 , V_2 -> V_10 . V_63 . V_73 ) ;
F_13 ( & V_2 -> V_10 . V_72 ) ;
break;
case V_212 :
F_11 ( & V_2 -> V_10 . V_72 ) ;
V_183 -> V_213 . V_68 = V_2 -> V_10 . V_97 . V_73 ;
V_183 -> V_213 . V_91 = V_2 -> V_10 . V_97 . V_69 ;
F_13 ( & V_2 -> V_10 . V_72 ) ;
break;
case V_214 :
F_11 ( & V_2 -> V_10 . V_72 ) ;
V_183 -> V_213 . V_68 = V_2 -> V_10 . V_96 . V_73 ;
V_183 -> V_213 . V_91 = V_2 -> V_10 . V_96 . V_69 ;
F_13 ( & V_2 -> V_10 . V_72 ) ;
break;
default:
V_32 = - V_71 ;
break;
}
return V_32 ;
}
int F_58 ( struct V_1 * V_2 , T_2 V_58 , union V_182 * V_183 )
{
int V_32 = 0 ;
long int V_162 ;
unsigned long V_68 , V_69 ;
switch ( V_58 ) {
case V_184 :
if ( F_59 ( V_58 , * V_183 ) )
V_32 = - V_71 ;
break;
case V_185 :
V_2 -> V_10 . V_186 = F_59 ( V_58 , * V_183 ) ;
break;
case V_187 :
V_2 -> V_10 . V_188 = F_59 ( V_58 , * V_183 ) ;
break;
case V_189 :
V_2 -> V_10 . V_190 = F_59 ( V_58 , * V_183 ) ;
break;
case V_191 :
V_2 -> V_10 . V_192 = F_59 ( V_58 , * V_183 ) ;
break;
case V_193 :
V_2 -> V_10 . V_194 = F_59 ( V_58 , * V_183 ) ;
break;
case V_195 :
V_2 -> V_10 . V_196 = F_59 ( V_58 , * V_183 ) ;
break;
case V_197 ... V_198 :
V_162 = V_58 - V_197 ;
V_2 -> V_10 . V_199 [ V_162 ] = F_59 ( V_58 , * V_183 ) ;
break;
case V_200 ... V_201 :
V_162 = V_58 - V_200 ;
V_2 -> V_10 . V_202 [ V_162 ] = F_59 ( V_58 , * V_183 ) ;
break;
#ifdef F_56
case V_203 ... V_204 :
if ( F_57 ( V_205 ) ) {
long int V_162 = V_58 - V_203 ;
V_2 -> V_10 . V_206 [ 2 * V_162 ] = F_59 ( V_58 , * V_183 ) ;
} else {
V_32 = - V_71 ;
}
break;
case V_207 ... V_208 :
if ( F_57 ( V_205 ) ) {
long int V_162 = V_58 - V_207 ;
V_2 -> V_10 . V_206 [ 2 * V_162 ] = V_183 -> V_209 [ 0 ] ;
V_2 -> V_10 . V_206 [ 2 * V_162 + 1 ] = V_183 -> V_209 [ 1 ] ;
} else {
V_32 = - V_210 ;
}
break;
#endif
case V_211 :
V_68 = F_59 ( V_58 , * V_183 ) ;
V_32 = - V_71 ;
if ( ! V_68 && ( V_2 -> V_10 . V_97 . V_73 ||
V_2 -> V_10 . V_96 . V_73 ) )
break;
V_32 = F_26 ( V_2 , & V_2 -> V_10 . V_63 , V_68 , sizeof( struct V_62 ) ) ;
break;
case V_212 :
V_68 = V_183 -> V_213 . V_68 ;
V_69 = V_183 -> V_213 . V_91 ;
V_32 = - V_71 ;
if ( V_68 && ! V_2 -> V_10 . V_63 . V_73 )
break;
V_32 = F_26 ( V_2 , & V_2 -> V_10 . V_97 , V_68 , V_69 ) ;
break;
case V_214 :
V_68 = V_183 -> V_213 . V_68 ;
V_69 = V_183 -> V_213 . V_91 ;
V_32 = - V_71 ;
if ( V_68 && ( V_69 < sizeof( struct V_94 ) ||
! V_2 -> V_10 . V_63 . V_73 ) )
break;
V_69 -= V_69 % sizeof( struct V_94 ) ;
V_32 = F_26 ( V_2 , & V_2 -> V_10 . V_96 , V_68 , V_69 ) ;
break;
default:
V_32 = - V_71 ;
break;
}
return V_32 ;
}
int F_60 ( void )
{
if ( F_57 ( V_215 ) )
return 0 ;
return - V_216 ;
}
struct V_1 * F_61 ( struct V_54 * V_54 , unsigned int V_58 )
{
struct V_1 * V_2 ;
int V_82 = - V_71 ;
int V_217 ;
struct V_15 * V_17 ;
V_217 = V_58 / V_218 ;
if ( V_217 >= V_219 )
goto V_220;
V_82 = - V_221 ;
V_2 = F_62 ( V_222 , V_223 ) ;
if ( ! V_2 )
goto V_220;
V_82 = F_63 ( V_2 , V_54 , V_58 ) ;
if ( V_82 )
goto V_224;
V_2 -> V_10 . V_225 = & V_2 -> V_10 . V_30 ;
V_2 -> V_10 . V_199 [ 0 ] = V_226 ;
V_2 -> V_10 . V_227 = V_228 ;
V_2 -> V_10 . V_31 = F_64 ( V_229 ) ;
F_17 ( V_2 , V_2 -> V_10 . V_31 ) ;
F_65 ( & V_2 -> V_10 . V_72 ) ;
F_65 ( & V_2 -> V_10 . V_18 ) ;
V_2 -> V_10 . V_27 = V_23 ;
F_66 ( V_2 ) ;
V_2 -> V_10 . V_25 = V_230 ;
F_67 ( & V_2 -> V_10 . V_231 ) ;
F_22 ( & V_54 -> V_61 ) ;
V_17 = V_54 -> V_10 . V_232 [ V_217 ] ;
if ( ! V_17 ) {
V_17 = F_68 ( sizeof( struct V_15 ) , V_223 ) ;
if ( V_17 ) {
F_69 ( & V_17 -> V_233 ) ;
F_65 ( & V_17 -> V_61 ) ;
F_67 ( & V_17 -> V_131 ) ;
V_17 -> V_22 = V_23 ;
}
V_54 -> V_10 . V_232 [ V_217 ] = V_17 ;
V_54 -> V_10 . V_234 ++ ;
}
F_24 ( & V_54 -> V_61 ) ;
if ( ! V_17 )
goto V_224;
F_11 ( & V_17 -> V_61 ) ;
++ V_17 -> V_235 ;
F_13 ( & V_17 -> V_61 ) ;
V_2 -> V_10 . V_17 = V_17 ;
V_2 -> V_10 . V_236 = V_237 ;
F_70 ( V_2 ) ;
return V_2 ;
V_224:
F_71 ( V_222 , V_2 ) ;
V_220:
return F_72 ( V_82 ) ;
}
static void F_73 ( struct V_54 * V_54 , struct V_67 * V_63 )
{
if ( V_63 -> V_76 )
F_30 ( V_54 , V_63 -> V_76 , V_63 -> V_101 ,
V_63 -> V_102 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_10 . V_72 ) ;
F_73 ( V_2 -> V_54 , & V_2 -> V_10 . V_96 ) ;
F_73 ( V_2 -> V_54 , & V_2 -> V_10 . V_97 ) ;
F_73 ( V_2 -> V_54 , & V_2 -> V_10 . V_63 ) ;
F_13 ( & V_2 -> V_10 . V_72 ) ;
F_75 ( V_2 ) ;
F_71 ( V_222 , V_2 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
unsigned long V_238 , V_106 ;
V_106 = F_77 () ;
if ( V_106 > V_2 -> V_10 . V_239 ) {
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
return;
}
V_238 = ( V_2 -> V_10 . V_239 - V_106 ) * V_240
/ V_241 ;
F_80 ( & V_2 -> V_10 . V_242 , F_81 ( 0 , V_238 ) ,
V_243 ) ;
V_2 -> V_10 . V_244 = 1 ;
}
static void F_16 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_130 = 0 ;
if ( V_2 -> V_10 . V_244 ) {
F_82 ( & V_2 -> V_10 . V_242 ) ;
V_2 -> V_10 . V_244 = 0 ;
}
}
static void F_83 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
T_2 V_106 ;
if ( V_2 -> V_10 . V_25 != V_245 )
return;
F_11 ( & V_2 -> V_10 . V_18 ) ;
V_106 = F_12 () ;
V_2 -> V_10 . V_28 += F_33 ( V_16 , V_106 ) -
V_2 -> V_10 . V_113 ;
V_2 -> V_10 . V_27 = V_106 ;
V_2 -> V_10 . V_25 = V_26 ;
F_13 ( & V_2 -> V_10 . V_18 ) ;
-- V_16 -> V_246 ;
F_84 ( & V_2 -> V_10 . V_247 ) ;
}
static int F_85 ( int V_4 )
{
struct V_248 * V_249 ;
long V_250 = 1000 ;
V_249 = & V_12 [ V_4 ] ;
V_249 -> V_13 . V_251 = 1 ;
V_249 -> V_13 . V_1 = NULL ;
F_41 () ;
while ( V_249 -> V_13 . V_252 == V_253 ) {
if ( -- V_250 <= 0 ) {
F_19 ( L_15 , V_4 ) ;
return - V_254 ;
}
F_86 ( 1 ) ;
}
return 0 ;
}
static void F_87 ( int V_4 )
{
struct V_248 * V_249 ;
V_249 = & V_12 [ V_4 ] ;
V_249 -> V_13 . V_251 = 0 ;
V_249 -> V_13 . V_1 = NULL ;
}
static void F_88 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_248 * V_249 ;
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
if ( V_2 -> V_10 . V_244 ) {
F_82 ( & V_2 -> V_10 . V_242 ) ;
V_2 -> V_10 . V_244 = 0 ;
}
V_4 = V_16 -> V_116 + V_2 -> V_10 . V_11 ;
V_249 = & V_12 [ V_4 ] ;
V_249 -> V_13 . V_1 = V_2 ;
V_249 -> V_13 . V_255 = V_16 ;
V_249 -> V_13 . V_256 = 0 ;
V_2 -> V_4 = V_16 -> V_116 ;
F_36 () ;
#if F_89 ( V_257 ) && F_89 ( V_258 )
if ( V_2 -> V_10 . V_11 ) {
F_6 ( V_4 ) ;
++ V_16 -> V_259 ;
}
#endif
}
static void F_90 ( struct V_15 * V_16 )
{
int V_162 ;
F_91 () ;
V_162 = 0 ;
while ( V_16 -> V_260 < V_16 -> V_259 ) {
if ( ++ V_162 >= 1000000 ) {
F_19 ( L_16 ,
V_16 -> V_260 , V_16 -> V_259 ) ;
break;
}
F_92 () ;
}
F_93 () ;
}
static int F_94 ( void )
{
int V_4 = F_95 () ;
int V_261 = F_96 ( V_4 ) ;
if ( V_261 )
return 0 ;
while ( ++ V_261 < V_218 )
if ( F_7 ( V_4 + V_261 ) )
return 0 ;
for ( V_261 = 1 ; V_261 < V_218 ; ++ V_261 ) {
if ( F_85 ( V_4 + V_261 ) ) {
do {
F_87 ( V_4 + V_261 ) ;
} while ( -- V_261 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_97 ( struct V_15 * V_16 )
{
struct V_1 * V_2 , * V_262 , * V_263 ;
long V_60 ;
T_2 V_106 ;
int V_11 , V_162 , V_264 ;
int V_265 ;
struct V_1 * V_266 [ V_218 ] ;
V_264 = 0 ;
F_98 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( F_99 ( V_2 -> V_10 . V_108 ) )
return;
if ( V_2 -> V_10 . V_63 . V_74 ||
V_2 -> V_10 . V_97 . V_74 ||
V_2 -> V_10 . V_96 . V_74 )
V_266 [ V_264 ++ ] = V_2 ;
}
V_16 -> V_259 = 0 ;
V_16 -> V_260 = 0 ;
V_16 -> V_267 = 0 ;
V_16 -> V_20 = V_268 ;
V_16 -> V_269 = 0 ;
V_16 -> V_270 = 0 ;
if ( V_264 ) {
F_13 ( & V_16 -> V_61 ) ;
for ( V_162 = 0 ; V_162 < V_264 ; ++ V_162 )
F_32 ( V_266 [ V_162 ] ) ;
F_11 ( & V_16 -> V_61 ) ;
}
V_11 = 0 ;
V_262 = NULL ;
F_98 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( ! V_2 -> V_10 . V_130 ) {
if ( ! V_11 )
V_262 = V_2 ;
V_2 -> V_10 . V_11 = V_11 ++ ;
}
}
if ( ! V_262 )
goto V_220;
F_98 (vcpu, &vc->runnable_threads, arch.run_list)
if ( V_2 -> V_10 . V_130 )
V_2 -> V_10 . V_11 = V_11 ++ ;
if ( V_218 > 1 && ! F_94 () ) {
F_98 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_10 . V_60 = - V_254 ;
goto V_220;
}
V_16 -> V_116 = F_95 () ;
F_98 (vcpu, &vc->runnable_threads, arch.run_list) {
F_88 ( V_2 ) ;
F_34 ( V_2 , V_16 ) ;
}
V_16 -> V_20 = V_271 ;
F_100 () ;
F_13 ( & V_16 -> V_61 ) ;
F_101 () ;
V_265 = F_38 ( & V_262 -> V_54 -> V_126 ) ;
F_102 ( NULL , V_262 ) ;
F_11 ( & V_16 -> V_61 ) ;
F_98 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_4 = - 1 ;
if ( V_16 -> V_260 < V_16 -> V_259 )
F_90 ( V_16 ) ;
for ( V_162 = 0 ; V_162 < V_218 ; ++ V_162 )
F_87 ( V_16 -> V_116 + V_162 ) ;
V_16 -> V_20 = V_272 ;
F_13 ( & V_16 -> V_61 ) ;
F_40 ( & V_262 -> V_54 -> V_126 , V_265 ) ;
F_41 () ;
F_103 () ;
F_104 () ;
F_105 ( V_2 ) ;
F_11 ( & V_16 -> V_61 ) ;
V_106 = F_77 () ;
F_98 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_106 < V_2 -> V_10 . V_239 &&
F_106 ( V_2 ) )
F_107 ( V_2 ) ;
V_60 = V_145 ;
if ( V_2 -> V_10 . V_35 )
V_60 = F_47 ( V_2 -> V_10 . V_146 , V_2 ,
V_2 -> V_10 . V_108 ) ;
V_2 -> V_10 . V_60 = V_60 ;
V_2 -> V_10 . V_35 = 0 ;
if ( V_2 -> V_10 . V_130 ) {
if ( V_60 != V_145 )
F_16 ( V_2 ) ;
else
F_76 ( V_2 ) ;
}
}
V_220:
V_16 -> V_20 = V_21 ;
F_108 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( V_2 -> V_10 . V_60 != V_145 ) {
F_83 ( V_16 , V_2 ) ;
F_109 ( & V_2 -> V_10 . V_231 ) ;
}
}
}
static void F_110 ( struct V_1 * V_2 , int V_273 )
{
F_111 ( V_274 ) ;
F_112 ( & V_2 -> V_10 . V_231 , & V_274 , V_273 ) ;
if ( V_2 -> V_10 . V_25 == V_245 )
F_113 () ;
F_114 ( & V_2 -> V_10 . V_231 , & V_274 ) ;
}
static void F_115 ( struct V_15 * V_16 )
{
F_111 ( V_274 ) ;
F_112 ( & V_16 -> V_131 , & V_274 , V_275 ) ;
V_16 -> V_20 = V_276 ;
F_13 ( & V_16 -> V_61 ) ;
F_113 () ;
F_114 ( & V_16 -> V_131 , & V_274 ) ;
F_11 ( & V_16 -> V_61 ) ;
V_16 -> V_20 = V_21 ;
}
static int F_116 ( struct V_146 * V_146 , struct V_1 * V_2 )
{
int V_277 ;
struct V_15 * V_16 ;
struct V_1 * V_59 , * V_278 ;
V_146 -> V_151 = 0 ;
V_2 -> V_10 . V_60 = V_145 ;
V_2 -> V_10 . V_35 = 0 ;
F_32 ( V_2 ) ;
V_16 = V_2 -> V_10 . V_17 ;
F_11 ( & V_16 -> V_61 ) ;
V_2 -> V_10 . V_130 = 0 ;
V_2 -> V_10 . V_108 = V_109 ;
V_2 -> V_10 . V_146 = V_146 ;
V_2 -> V_10 . V_113 = F_33 ( V_16 , F_12 () ) ;
V_2 -> V_10 . V_25 = V_245 ;
V_2 -> V_10 . V_27 = V_23 ;
F_117 ( & V_2 -> V_10 . V_247 , & V_16 -> V_233 ) ;
++ V_16 -> V_246 ;
if ( ! F_99 ( V_109 ) ) {
if ( V_16 -> V_20 == V_271 &&
F_118 ( V_16 ) == 0 ) {
V_2 -> V_10 . V_11 = V_16 -> V_246 - 1 ;
F_34 ( V_2 , V_16 ) ;
F_88 ( V_2 ) ;
} else if ( V_16 -> V_20 == V_276 ) {
F_109 ( & V_16 -> V_131 ) ;
}
}
while ( V_2 -> V_10 . V_25 == V_245 &&
! F_99 ( V_109 ) ) {
if ( V_16 -> V_20 != V_21 ) {
F_13 ( & V_16 -> V_61 ) ;
F_110 ( V_2 , V_275 ) ;
F_11 ( & V_16 -> V_61 ) ;
continue;
}
F_108 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_79 ( V_59 ) ;
if ( F_99 ( V_59 -> V_10 . V_108 ) ) {
F_83 ( V_16 , V_59 ) ;
V_59 -> V_6 . V_279 ++ ;
V_59 -> V_10 . V_146 -> V_151 = V_280 ;
V_59 -> V_10 . V_60 = - V_281 ;
F_109 ( & V_59 -> V_10 . V_231 ) ;
}
}
if ( ! V_16 -> V_246 || V_2 -> V_10 . V_25 != V_245 )
break;
V_16 -> V_19 = V_2 ;
V_277 = 0 ;
F_98 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_59 -> V_10 . V_282 )
V_277 += V_59 -> V_10 . V_130 ;
else
V_59 -> V_10 . V_130 = 0 ;
}
if ( V_277 == V_16 -> V_246 )
F_115 ( V_16 ) ;
else
F_97 ( V_16 ) ;
V_16 -> V_19 = NULL ;
}
while ( V_2 -> V_10 . V_25 == V_245 &&
( V_16 -> V_20 == V_271 ||
V_16 -> V_20 == V_272 ) ) {
F_13 ( & V_16 -> V_61 ) ;
F_110 ( V_2 , V_283 ) ;
F_11 ( & V_16 -> V_61 ) ;
}
if ( V_2 -> V_10 . V_25 == V_245 ) {
F_83 ( V_16 , V_2 ) ;
V_2 -> V_6 . V_279 ++ ;
V_146 -> V_151 = V_280 ;
V_2 -> V_10 . V_60 = - V_281 ;
}
if ( V_16 -> V_246 && V_16 -> V_20 == V_21 ) {
V_59 = F_119 ( & V_16 -> V_233 ,
struct V_1 , V_10 . V_247 ) ;
F_109 ( & V_59 -> V_10 . V_231 ) ;
}
F_13 ( & V_16 -> V_61 ) ;
return V_2 -> V_10 . V_60 ;
}
int F_120 ( struct V_146 * V_147 , struct V_1 * V_2 )
{
int V_32 ;
int V_265 ;
if ( ! V_2 -> V_10 . V_284 ) {
V_147 -> V_151 = V_285 ;
return - V_71 ;
}
F_79 ( V_2 ) ;
if ( F_99 ( V_109 ) ) {
V_147 -> V_151 = V_280 ;
return - V_281 ;
}
F_121 ( & V_2 -> V_54 -> V_10 . V_286 ) ;
F_41 () ;
if ( ! V_2 -> V_54 -> V_10 . V_287 ) {
V_32 = F_122 ( V_2 ) ;
if ( V_32 )
goto V_220;
}
F_123 ( V_109 ) ;
F_124 ( V_109 ) ;
F_125 ( V_109 ) ;
V_2 -> V_10 . V_5 = & V_2 -> V_10 . V_17 -> V_131 ;
V_2 -> V_10 . V_288 = V_109 -> V_289 -> V_290 ;
V_2 -> V_10 . V_25 = V_26 ;
do {
V_32 = F_116 ( V_147 , V_2 ) ;
if ( V_147 -> V_151 == V_166 &&
! ( V_2 -> V_10 . V_30 . V_29 & V_163 ) ) {
V_32 = F_37 ( V_2 ) ;
F_79 ( V_2 ) ;
} else if ( V_32 == V_168 ) {
V_265 = F_38 ( & V_2 -> V_54 -> V_126 ) ;
V_32 = F_126 ( V_147 , V_2 ,
V_2 -> V_10 . V_48 , V_2 -> V_10 . V_49 ) ;
F_40 ( & V_2 -> V_54 -> V_126 , V_265 ) ;
}
} while ( V_32 == V_145 );
V_220:
V_2 -> V_10 . V_25 = V_230 ;
F_127 ( & V_2 -> V_54 -> V_10 . V_286 ) ;
return V_32 ;
}
static inline int F_128 ( unsigned long V_291 )
{
switch ( V_291 ) {
case 32ul << 20 :
if ( F_57 ( V_292 ) )
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
static int F_129 ( struct V_293 * V_294 , struct V_295 * V_296 )
{
struct V_297 * V_297 ;
struct V_298 * V_299 = V_294 -> V_300 -> V_301 ;
if ( V_296 -> V_302 >= V_303 )
return V_304 ;
V_297 = F_130 ( V_299 -> V_305 + V_296 -> V_302 ) ;
F_131 ( V_297 ) ;
V_296 -> V_297 = V_297 ;
return 0 ;
}
static int F_132 ( struct V_306 * V_306 , struct V_293 * V_294 )
{
V_294 -> V_307 |= V_308 | V_309 ;
V_294 -> V_310 = & V_311 ;
return 0 ;
}
static int F_133 ( struct V_312 * V_312 , struct V_306 * V_313 )
{
struct V_298 * V_299 = V_313 -> V_301 ;
F_134 ( V_299 ) ;
return 0 ;
}
long F_135 ( struct V_54 * V_54 , struct V_314 * V_60 )
{
long V_315 ;
struct V_298 * V_299 ;
if ( ! F_57 ( V_215 ) ||
! F_57 ( V_316 ) )
return - V_71 ;
if ( ! V_303 )
return - V_71 ;
V_299 = F_136 () ;
if ( ! V_299 )
return - V_221 ;
V_315 = F_137 ( L_17 , & V_317 , V_299 , V_318 | V_319 ) ;
if ( V_315 < 0 )
F_134 ( V_299 ) ;
V_60 -> V_291 = V_303 << V_320 ;
return V_315 ;
}
static void F_138 ( struct V_321 * * V_322 ,
int V_323 )
{
struct V_324 * V_325 = & V_326 [ V_323 ] ;
if ( ! V_325 -> V_327 )
return;
( * V_322 ) -> V_328 = V_325 -> V_327 ;
( * V_322 ) -> V_329 = V_325 -> V_330 ;
( * V_322 ) -> V_331 [ 0 ] . V_328 = V_325 -> V_327 ;
( * V_322 ) -> V_331 [ 0 ] . V_332 = V_325 -> V_333 [ V_323 ] ;
( * V_322 ) ++ ;
}
int F_139 ( struct V_54 * V_54 , struct V_334 * V_335 )
{
struct V_321 * V_322 ;
V_335 -> V_77 = V_336 ;
if ( F_140 ( V_337 ) )
V_335 -> V_77 |= V_338 ;
V_335 -> V_339 = V_340 ;
V_322 = & V_335 -> V_322 [ 0 ] ;
F_138 ( & V_322 , V_341 ) ;
F_138 ( & V_322 , V_342 ) ;
F_138 ( & V_322 , V_343 ) ;
return 0 ;
}
int F_141 ( struct V_54 * V_54 , struct V_344 * log )
{
struct V_345 * V_346 ;
int V_32 ;
unsigned long V_347 ;
F_22 ( & V_54 -> V_348 ) ;
V_32 = - V_71 ;
if ( log -> V_349 >= V_350 )
goto V_220;
V_346 = F_142 ( V_54 -> V_351 , log -> V_349 ) ;
V_32 = - V_137 ;
if ( ! V_346 -> V_352 )
goto V_220;
V_347 = F_143 ( V_346 ) ;
memset ( V_346 -> V_352 , 0 , V_347 ) ;
V_32 = F_144 ( V_54 , V_346 , V_346 -> V_352 ) ;
if ( V_32 )
goto V_220;
V_32 = - V_353 ;
if ( F_145 ( log -> V_352 , V_346 -> V_352 , V_347 ) )
goto V_220;
V_32 = 0 ;
V_220:
F_24 ( & V_54 -> V_348 ) ;
return V_32 ;
}
static void F_146 ( struct V_345 * V_346 )
{
unsigned long * V_354 ;
unsigned long V_179 , V_355 , V_356 ;
struct V_297 * V_297 ;
V_354 = V_346 -> V_10 . V_357 ;
V_355 = V_346 -> V_355 ;
if ( ! V_354 )
return;
for ( V_179 = 0 ; V_179 < V_355 ; V_179 ++ ) {
if ( ! ( V_354 [ V_179 ] & V_358 ) )
continue;
V_356 = V_354 [ V_179 ] >> V_320 ;
V_297 = F_130 ( V_356 ) ;
F_147 ( V_297 ) ;
F_148 ( V_297 ) ;
}
}
void F_149 ( struct V_345 * free ,
struct V_345 * V_359 )
{
if ( ! V_359 || free -> V_10 . V_360 != V_359 -> V_10 . V_360 ) {
F_150 ( free -> V_10 . V_360 ) ;
free -> V_10 . V_360 = NULL ;
}
if ( ! V_359 || free -> V_10 . V_357 != V_359 -> V_10 . V_357 ) {
F_146 ( free ) ;
F_150 ( free -> V_10 . V_357 ) ;
free -> V_10 . V_357 = NULL ;
}
}
int F_151 ( struct V_345 * V_349 ,
unsigned long V_355 )
{
V_349 -> V_10 . V_360 = F_152 ( V_355 * sizeof( * V_349 -> V_10 . V_360 ) ) ;
if ( ! V_349 -> V_10 . V_360 )
return - V_221 ;
V_349 -> V_10 . V_357 = NULL ;
return 0 ;
}
int F_153 ( struct V_54 * V_54 ,
struct V_345 * V_346 ,
struct V_361 * V_362 )
{
unsigned long * V_363 ;
V_363 = V_346 -> V_10 . V_357 ;
if ( ! V_54 -> V_10 . V_364 && ! V_363 && V_346 -> V_355 ) {
V_363 = F_152 ( V_346 -> V_355 * sizeof( unsigned long ) ) ;
if ( ! V_363 )
return - V_221 ;
V_346 -> V_10 . V_357 = V_363 ;
}
return 0 ;
}
void F_154 ( struct V_54 * V_54 ,
struct V_361 * V_362 ,
const struct V_345 * V_365 )
{
unsigned long V_355 = V_362 -> V_366 >> V_320 ;
struct V_345 * V_346 ;
if ( V_355 && V_365 -> V_355 ) {
V_346 = F_142 ( V_54 -> V_351 , V_362 -> V_349 ) ;
F_144 ( V_54 , V_346 , NULL ) ;
}
}
static int F_122 ( struct V_1 * V_2 )
{
int V_82 = 0 ;
struct V_54 * V_54 = V_2 -> V_54 ;
struct V_298 * V_299 = NULL ;
unsigned long V_367 ;
struct V_345 * V_346 ;
struct V_293 * V_294 ;
unsigned long V_55 , V_368 ;
unsigned long V_369 , V_370 ;
unsigned long V_291 ;
unsigned long V_371 ;
unsigned long * V_354 ;
unsigned long V_162 , V_355 ;
int V_265 ;
F_22 ( & V_54 -> V_61 ) ;
if ( V_54 -> V_10 . V_287 )
goto V_220;
if ( ! V_54 -> V_10 . V_372 ) {
V_82 = F_155 ( V_54 , NULL ) ;
if ( V_82 ) {
F_19 ( L_18 ) ;
goto V_220;
}
}
V_265 = F_38 ( & V_54 -> V_126 ) ;
V_346 = F_156 ( V_54 , 0 ) ;
V_82 = - V_71 ;
if ( ! V_346 || ( V_346 -> V_77 & V_373 ) )
goto V_374;
V_367 = V_346 -> V_375 ;
F_157 ( & V_109 -> V_289 -> V_376 ) ;
V_294 = F_158 ( V_109 -> V_289 , V_367 ) ;
if ( ! V_294 || V_294 -> V_377 > V_367 || ( V_294 -> V_307 & V_378 ) )
goto V_379;
V_369 = F_159 ( V_294 ) ;
V_370 = F_160 ( V_369 ) ;
if ( V_294 -> V_300 && V_294 -> V_300 -> V_380 == & V_317 &&
V_367 == V_294 -> V_377 )
V_299 = V_294 -> V_300 -> V_301 ;
F_161 ( & V_109 -> V_289 -> V_376 ) ;
if ( ! V_299 ) {
V_82 = - V_381 ;
if ( F_57 ( V_316 ) ) {
F_19 ( L_19 ) ;
goto V_374;
}
V_82 = - V_71 ;
if ( ! ( V_369 == 0x1000 || V_369 == 0x10000 ||
V_369 == 0x1000000 ) )
goto V_374;
V_368 = F_162 ( V_369 ) ;
V_54 -> V_10 . V_382 = V_368 | V_383 |
( V_384 << V_385 ) ;
V_55 = V_54 -> V_10 . V_55 & ~ V_386 ;
V_55 |= V_368 << ( V_387 - 4 ) ;
V_54 -> V_10 . V_55 = V_55 ;
F_163 ( V_2 , V_346 , V_370 ) ;
} else {
V_291 = V_303 ;
if ( V_291 > V_346 -> V_355 )
V_291 = V_346 -> V_355 ;
V_291 <<= V_320 ;
V_371 = F_128 ( V_291 ) ;
V_82 = - V_71 ;
if ( ( long ) V_371 < 0 ) {
F_19 ( L_20 , V_291 ) ;
goto V_374;
}
F_121 ( & V_299 -> V_388 ) ;
V_54 -> V_10 . V_389 = V_299 ;
V_55 = V_54 -> V_10 . V_55 ;
if ( F_57 ( V_316 ) ) {
V_55 &= ~ ( ( 1ul << V_390 ) |
( 3ul << V_391 ) ) ;
V_55 |= ( ( V_371 >> 2 ) << V_390 ) |
( ( V_371 & 3 ) << V_391 ) ;
V_55 |= ( ( V_299 -> V_305 >> ( 26 - V_320 ) ) & 0xffff )
<< V_392 ;
} else {
V_55 &= ~ ( V_393 | V_394 ) ;
V_55 |= V_371 << V_395 ;
V_54 -> V_10 . V_396 = V_299 -> V_305 << V_320 ;
}
V_54 -> V_10 . V_55 = V_55 ;
F_164 ( L_21 ,
V_299 -> V_305 << V_320 , V_291 , V_55 ) ;
V_355 = V_303 ;
V_370 = F_160 ( V_355 ) ;
V_354 = V_346 -> V_10 . V_357 ;
if ( V_354 ) {
if ( V_355 > V_346 -> V_355 )
V_355 = V_346 -> V_355 ;
F_11 ( & V_54 -> V_10 . V_397 ) ;
for ( V_162 = 0 ; V_162 < V_355 ; ++ V_162 )
V_354 [ V_162 ] = ( ( V_299 -> V_305 + V_162 ) << V_320 ) +
V_370 ;
F_13 ( & V_54 -> V_10 . V_397 ) ;
}
}
F_36 () ;
V_54 -> V_10 . V_287 = 1 ;
V_82 = 0 ;
V_374:
F_40 ( & V_54 -> V_126 , V_265 ) ;
V_220:
F_24 ( & V_54 -> V_61 ) ;
return V_82 ;
V_379:
F_161 ( & V_109 -> V_289 -> V_376 ) ;
goto V_374;
}
int F_165 ( struct V_54 * V_54 )
{
unsigned long V_55 , V_398 ;
V_398 = F_166 () ;
if ( ( long ) V_398 < 0 )
return - V_221 ;
V_54 -> V_10 . V_398 = V_398 ;
F_167 ( & V_54 -> V_10 . V_399 ) ;
F_69 ( & V_54 -> V_10 . V_400 ) ;
F_69 ( & V_54 -> V_10 . V_135 ) ;
V_54 -> V_10 . V_389 = NULL ;
V_54 -> V_10 . V_401 = F_64 ( V_402 ) ;
if ( F_57 ( V_316 ) ) {
V_54 -> V_10 . V_403 = 0 ;
V_54 -> V_10 . V_404 = V_55 = F_64 ( V_405 ) ;
V_55 &= ~ ( ( 3 << V_406 ) | ( 0xful << V_407 ) ) ;
V_55 |= ( ( V_398 >> 4 ) << V_406 ) |
( ( V_398 & 0xf ) << V_407 ) ;
} else {
V_54 -> V_10 . V_403 = F_64 ( V_408 ) ;
V_54 -> V_10 . V_404 = V_55 = F_64 ( V_409 ) ;
V_55 &= V_410 | V_411 ;
V_55 |= ( 4UL << V_412 ) | V_413 |
V_393 | V_414 ;
V_54 -> V_10 . V_382 = V_383 |
( V_384 << V_385 ) ;
}
V_54 -> V_10 . V_55 = V_55 ;
V_54 -> V_10 . V_364 = ! ! F_57 ( V_292 ) ;
F_65 ( & V_54 -> V_10 . V_397 ) ;
F_168 () ;
return 0 ;
}
void F_169 ( struct V_54 * V_54 )
{
F_170 () ;
if ( V_54 -> V_10 . V_389 ) {
F_134 ( V_54 -> V_10 . V_389 ) ;
V_54 -> V_10 . V_389 = NULL ;
}
F_171 ( V_54 ) ;
F_172 ( V_54 ) ;
F_173 ( ! F_42 ( & V_54 -> V_10 . V_400 ) ) ;
}
void F_174 ( struct V_1 * V_2 , T_4 V_415 , T_4 V_416 )
{
}
int F_175 ( struct V_146 * V_147 , struct V_1 * V_2 ,
unsigned int V_417 , int * V_418 )
{
return V_419 ;
}
int F_176 ( struct V_1 * V_2 , int V_420 , T_4 V_421 )
{
return V_419 ;
}
int F_177 ( struct V_1 * V_2 , int V_420 , T_4 * V_421 )
{
return V_419 ;
}
static int F_178 ( void )
{
int V_32 ;
V_32 = F_179 ( NULL , sizeof( struct V_1 ) , 0 , V_422 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_180 () ;
return V_32 ;
}
static void F_181 ( void )
{
F_182 () ;
}

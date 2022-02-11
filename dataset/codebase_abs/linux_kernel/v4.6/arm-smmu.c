static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
int V_7 = 0 ;
do {
if ( F_4 ( V_6 -> V_8 -> V_9 ,
V_10 [ V_7 ] . V_11 ) ) {
V_6 -> V_12 |= V_10 [ V_7 ] . V_13 ;
F_5 ( V_6 -> V_8 , L_1 ,
V_10 [ V_7 ] . V_11 ) ;
}
} while ( V_10 [ ++ V_7 ] . V_13 );
}
static struct V_14 * F_6 ( struct V_15 * V_8 )
{
if ( F_7 ( V_8 ) ) {
struct V_16 * V_17 = F_8 ( V_8 ) -> V_17 ;
while ( ! F_9 ( V_17 ) )
V_17 = V_17 -> V_18 ;
return V_17 -> V_19 -> V_18 -> V_9 ;
}
return V_8 -> V_9 ;
}
static struct V_20 * F_10 ( struct V_5 * V_6 ,
struct V_14 * V_21 )
{
struct V_22 * V_23 = V_6 -> V_24 . V_22 ;
while ( V_23 ) {
struct V_20 * V_25 ;
V_25 = F_2 ( V_23 , struct V_20 , V_23 ) ;
if ( V_21 < V_25 -> V_9 )
V_23 = V_23 -> V_26 ;
else if ( V_21 > V_25 -> V_9 )
V_23 = V_23 -> V_27 ;
else
return V_25 ;
}
return NULL ;
}
static struct V_28 *
F_11 ( struct V_15 * V_8 )
{
struct V_28 * V_29 = NULL ;
struct V_30 * V_31 = F_12 ( V_8 ) ;
if ( V_31 ) {
V_29 = F_13 ( V_31 ) ;
F_14 ( V_31 ) ;
}
return V_29 ;
}
static int F_15 ( struct V_5 * V_6 ,
struct V_20 * V_25 )
{
struct V_22 * * V_32 , * V_18 ;
V_32 = & V_6 -> V_24 . V_22 ;
V_18 = NULL ;
while ( * V_32 ) {
struct V_20 * V_33
= F_2 ( * V_32 , struct V_20 , V_23 ) ;
V_18 = * V_32 ;
if ( V_25 -> V_9 < V_33 -> V_9 )
V_32 = & ( ( * V_32 ) -> V_26 ) ;
else if ( V_25 -> V_9 > V_33 -> V_9 )
V_32 = & ( ( * V_32 ) -> V_27 ) ;
else
return - V_34 ;
}
F_16 ( & V_25 -> V_23 , V_18 , V_32 ) ;
F_17 ( & V_25 -> V_23 , & V_6 -> V_24 ) ;
return 0 ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_15 * V_8 ,
struct V_35 * V_36 )
{
int V_7 ;
struct V_20 * V_25 ;
V_25 = F_10 ( V_6 , V_36 -> V_37 ) ;
if ( V_25 ) {
F_19 ( V_8 ,
L_2 ,
V_36 -> V_37 -> V_38 ) ;
return - V_39 ;
}
if ( V_36 -> V_40 > V_41 ) {
F_19 ( V_8 ,
L_3 ,
V_41 , V_36 -> V_37 -> V_38 ) ;
return - V_42 ;
}
V_25 = F_20 ( V_8 , sizeof( * V_25 ) , V_43 ) ;
if ( ! V_25 )
return - V_44 ;
V_25 -> V_9 = V_36 -> V_37 ;
V_25 -> V_29 . V_45 = V_36 -> V_40 ;
for ( V_7 = 0 ; V_7 < V_25 -> V_29 . V_45 ; ++ V_7 ) {
T_1 V_46 = V_36 -> args [ V_7 ] ;
if ( ! ( V_6 -> V_47 & V_48 ) &&
( V_46 >= V_6 -> V_49 ) ) {
F_19 ( V_8 ,
L_4 ,
V_36 -> V_37 -> V_38 , V_6 -> V_49 ) ;
return - V_50 ;
}
V_25 -> V_29 . V_51 [ V_7 ] = V_46 ;
}
return F_15 ( V_6 , V_25 ) ;
}
static struct V_5 * F_21 ( struct V_15 * V_8 )
{
struct V_5 * V_6 ;
struct V_20 * V_25 = NULL ;
struct V_14 * V_21 = F_6 ( V_8 ) ;
F_22 ( & V_52 ) ;
F_23 (smmu, &arm_smmu_devices, list) {
V_25 = F_10 ( V_6 , V_21 ) ;
if ( V_25 )
break;
}
F_24 ( & V_52 ) ;
return V_25 ? V_6 : NULL ;
}
static int F_25 ( unsigned long * V_53 , int V_54 , int V_55 )
{
int V_56 ;
do {
V_56 = F_26 ( V_53 , V_55 , V_54 ) ;
if ( V_56 == V_55 )
return - V_42 ;
} while ( F_27 ( V_56 , V_53 ) );
return V_56 ;
}
static void F_28 ( unsigned long * V_53 , int V_56 )
{
F_29 ( V_56 , V_53 ) ;
}
static void F_30 ( struct V_5 * V_6 )
{
int V_57 = 0 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
F_32 ( 0 , V_58 + V_59 ) ;
while ( F_33 ( V_58 + V_60 )
& V_61 ) {
F_34 () ;
if ( ++ V_57 == V_62 ) {
F_35 ( V_6 -> V_8 ,
L_5 ) ;
return;
}
F_36 ( 1 ) ;
}
}
static void F_37 ( void * V_63 )
{
struct V_1 * V_64 = V_63 ;
F_30 ( V_64 -> V_6 ) ;
}
static void F_38 ( void * V_63 )
{
struct V_1 * V_64 = V_63 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_5 * V_6 = V_64 -> V_6 ;
bool V_66 = V_29 -> V_67 != V_68 ;
void T_2 * V_69 ;
if ( V_66 ) {
V_69 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
F_32 ( F_41 ( V_29 ) ,
V_69 + V_71 ) ;
} else {
V_69 = F_31 ( V_6 ) ;
F_32 ( F_42 ( V_29 ) ,
V_69 + V_72 ) ;
}
F_30 ( V_6 ) ;
}
static void F_43 ( unsigned long V_73 , T_3 V_74 ,
T_3 V_75 , bool V_76 , void * V_63 )
{
struct V_1 * V_64 = V_63 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_5 * V_6 = V_64 -> V_6 ;
bool V_66 = V_29 -> V_67 != V_68 ;
void T_2 * V_77 ;
if ( V_66 ) {
V_77 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_77 += V_76 ? V_78 : V_79 ;
if ( ! F_44 ( V_80 ) || V_6 -> V_81 == V_82 ) {
V_73 &= ~ 12UL ;
V_73 |= F_41 ( V_29 ) ;
do {
F_32 ( V_73 , V_77 ) ;
V_73 += V_75 ;
} while ( V_74 -= V_75 );
#ifdef V_80
} else {
V_73 >>= 12 ;
V_73 |= ( V_83 ) F_41 ( V_29 ) << 48 ;
do {
F_45 ( V_73 , V_77 ) ;
V_73 += V_75 >> 12 ;
} while ( V_74 -= V_75 );
#endif
}
#ifdef V_80
} else if ( V_6 -> V_81 == V_84 ) {
V_77 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_77 += V_76 ? V_85 :
V_86 ;
V_73 >>= 12 ;
do {
F_45 ( V_73 , V_77 ) ;
V_73 += V_75 >> 12 ;
} while ( V_74 -= V_75 );
#endif
} else {
V_77 = F_31 ( V_6 ) + V_72 ;
F_32 ( F_42 ( V_29 ) , V_77 ) ;
}
}
static T_4 F_46 ( int V_87 , void * V_8 )
{
int V_88 , V_89 ;
T_5 V_90 , V_91 , V_92 , V_93 ;
unsigned long V_73 ;
struct V_2 * V_4 = V_8 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_94 ;
V_94 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_90 = F_33 ( V_94 + V_95 ) ;
if ( ! ( V_90 & V_96 ) )
return V_97 ;
if ( V_90 & V_98 )
F_35 ( V_6 -> V_8 ,
L_6 ,
V_90 ) ;
V_92 = F_33 ( V_94 + V_99 ) ;
V_88 = V_92 & V_100 ? V_101 : V_102 ;
V_91 = F_33 ( V_94 + V_103 ) ;
V_73 = V_91 ;
#ifdef V_80
V_91 = F_33 ( V_94 + V_104 ) ;
V_73 |= ( ( unsigned long ) V_91 << 32 ) ;
#endif
if ( ! F_47 ( V_4 , V_6 -> V_8 , V_73 , V_88 ) ) {
V_89 = V_105 ;
V_93 = V_106 ;
} else {
F_35 ( V_6 -> V_8 ,
L_7 ,
V_73 , V_92 , V_29 -> V_70 ) ;
V_89 = V_97 ;
V_93 = V_107 ;
}
F_48 ( V_90 , V_94 + V_95 ) ;
if ( V_90 & V_108 )
F_32 ( V_93 , V_94 + V_109 ) ;
return V_89 ;
}
static T_4 F_49 ( int V_87 , void * V_8 )
{
T_5 V_110 , V_111 , V_112 , V_113 ;
struct V_5 * V_6 = V_8 ;
void T_2 * V_58 = F_50 ( V_6 ) ;
V_110 = F_33 ( V_58 + V_114 ) ;
V_111 = F_33 ( V_58 + V_115 ) ;
V_112 = F_33 ( V_58 + V_116 ) ;
V_113 = F_33 ( V_58 + V_117 ) ;
if ( ! V_110 )
return V_97 ;
F_35 ( V_6 -> V_8 ,
L_8 ) ;
F_35 ( V_6 -> V_8 ,
L_9 ,
V_110 , V_111 , V_112 , V_113 ) ;
F_48 ( V_110 , V_58 + V_114 ) ;
return V_105 ;
}
static void F_51 ( struct V_1 * V_64 ,
struct V_118 * V_119 )
{
T_5 V_77 ;
V_83 V_120 ;
bool V_66 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_94 , * V_121 ;
V_121 = F_52 ( V_6 ) ;
V_66 = V_29 -> V_67 != V_68 ;
V_94 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
if ( V_6 -> V_81 > V_82 ) {
#ifdef V_80
V_77 = V_122 ;
#else
V_77 = V_123 ;
#endif
F_32 ( V_77 , V_121 + F_53 ( V_29 -> V_70 ) ) ;
}
V_77 = V_29 -> V_67 ;
if ( V_6 -> V_81 == V_82 )
V_77 |= V_29 -> V_124 << V_125 ;
if ( V_66 ) {
V_77 |= ( V_126 << V_127 ) |
( V_128 << V_129 ) ;
} else {
V_77 |= F_42 ( V_29 ) << V_130 ;
}
F_32 ( V_77 , V_121 + F_54 ( V_29 -> V_70 ) ) ;
if ( V_66 ) {
V_120 = V_119 -> V_131 . V_132 [ 0 ] ;
V_120 |= ( ( V_83 ) F_41 ( V_29 ) ) << V_133 ;
F_55 ( V_120 , V_94 + V_134 ) ;
V_120 = V_119 -> V_131 . V_132 [ 1 ] ;
V_120 |= ( ( V_83 ) F_41 ( V_29 ) ) << V_133 ;
F_55 ( V_120 , V_94 + V_135 ) ;
} else {
V_120 = V_119 -> V_136 . V_137 ;
F_55 ( V_120 , V_94 + V_134 ) ;
}
if ( V_66 ) {
V_77 = V_119 -> V_131 . V_138 ;
F_32 ( V_77 , V_94 + V_139 ) ;
if ( V_6 -> V_81 > V_82 ) {
V_77 = V_119 -> V_131 . V_138 >> 32 ;
V_77 |= V_140 ;
F_32 ( V_77 , V_94 + V_141 ) ;
}
} else {
V_77 = V_119 -> V_136 . V_142 ;
F_32 ( V_77 , V_94 + V_139 ) ;
}
if ( V_66 ) {
V_77 = V_119 -> V_131 . V_143 [ 0 ] ;
F_32 ( V_77 , V_94 + V_144 ) ;
V_77 = V_119 -> V_131 . V_143 [ 1 ] ;
F_32 ( V_77 , V_94 + V_145 ) ;
}
V_77 = V_146 | V_147 | V_148 | V_149 | V_150 ;
if ( V_66 )
V_77 |= V_151 ;
#ifdef F_56
V_77 |= V_152 ;
#endif
F_32 ( V_77 , V_94 + V_153 ) ;
}
static int F_57 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
int V_87 , V_54 , V_89 = 0 ;
unsigned long V_154 , V_155 ;
struct V_156 * V_157 ;
struct V_118 V_119 ;
enum V_158 V_159 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_65 * V_29 = & V_64 -> V_29 ;
F_58 ( & V_64 -> V_160 ) ;
if ( V_64 -> V_6 )
goto V_161;
if ( V_4 -> type == V_162 ) {
V_64 -> V_6 = V_6 ;
goto V_161;
}
if ( ! ( V_6 -> V_47 & V_163 ) )
V_64 -> V_164 = V_165 ;
if ( ! ( V_6 -> V_47 & V_166 ) )
V_64 -> V_164 = V_167 ;
switch ( V_64 -> V_164 ) {
case V_167 :
V_29 -> V_67 = V_168 ;
V_54 = V_6 -> V_169 ;
V_154 = V_6 -> V_170 ;
V_155 = V_6 -> V_171 ;
if ( F_44 ( V_80 ) )
V_159 = V_172 ;
else
V_159 = V_173 ;
break;
case V_174 :
case V_165 :
V_29 -> V_67 = V_68 ;
V_54 = 0 ;
V_154 = V_6 -> V_171 ;
V_155 = V_6 -> V_175 ;
if ( F_44 ( V_80 ) )
V_159 = V_176 ;
else
V_159 = V_177 ;
break;
default:
V_89 = - V_178 ;
goto V_161;
}
V_89 = F_25 ( V_6 -> V_179 , V_54 ,
V_6 -> V_180 ) ;
if ( F_59 ( V_89 ) )
goto V_161;
V_29 -> V_70 = V_89 ;
if ( V_6 -> V_81 == V_82 ) {
V_29 -> V_124 = F_60 ( & V_6 -> V_124 ) ;
V_29 -> V_124 %= V_6 -> V_181 ;
} else {
V_29 -> V_124 = V_29 -> V_70 ;
}
V_119 = (struct V_118 ) {
. V_182 = V_183 . V_182 ,
. V_154 = V_154 ,
. V_155 = V_155 ,
. V_184 = & V_185 ,
. V_186 = V_6 -> V_8 ,
} ;
V_64 -> V_6 = V_6 ;
V_157 = F_61 ( V_159 , & V_119 , V_64 ) ;
if ( ! V_157 ) {
V_89 = - V_44 ;
goto V_187;
}
V_183 . V_182 = V_119 . V_182 ;
F_51 ( V_64 , & V_119 ) ;
V_87 = V_6 -> V_188 [ V_6 -> V_189 + V_29 -> V_124 ] ;
V_89 = F_62 ( V_87 , F_46 , V_190 ,
L_10 , V_4 ) ;
if ( F_59 ( V_89 ) ) {
F_19 ( V_6 -> V_8 , L_11 ,
V_29 -> V_124 , V_87 ) ;
V_29 -> V_124 = V_191 ;
}
F_63 ( & V_64 -> V_160 ) ;
V_64 -> V_157 = V_157 ;
return 0 ;
V_187:
V_64 -> V_6 = NULL ;
V_161:
F_63 ( & V_64 -> V_160 ) ;
return V_89 ;
}
static void F_64 ( struct V_2 * V_4 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_64 -> V_6 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
void T_2 * V_94 ;
int V_87 ;
if ( ! V_6 || V_4 -> type == V_162 )
return;
V_94 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
F_32 ( 0 , V_94 + V_153 ) ;
if ( V_29 -> V_124 != V_191 ) {
V_87 = V_6 -> V_188 [ V_6 -> V_189 + V_29 -> V_124 ] ;
F_65 ( V_87 , V_4 ) ;
}
F_66 ( V_64 -> V_157 ) ;
F_28 ( V_6 -> V_179 , V_29 -> V_70 ) ;
}
static struct V_2 * F_67 ( unsigned type )
{
struct V_1 * V_64 ;
if ( type != V_192 && type != V_162 )
return NULL ;
V_64 = F_68 ( sizeof( * V_64 ) , V_43 ) ;
if ( ! V_64 )
return NULL ;
if ( type == V_162 &&
F_69 ( & V_64 -> V_4 ) ) {
F_70 ( V_64 ) ;
return NULL ;
}
F_71 ( & V_64 -> V_160 ) ;
F_72 ( & V_64 -> V_193 ) ;
return & V_64 -> V_4 ;
}
static void F_73 ( struct V_2 * V_4 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
F_74 ( V_4 ) ;
F_64 ( V_4 ) ;
F_70 ( V_64 ) ;
}
static int F_75 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_7 ;
struct V_194 * V_195 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( ! ( V_6 -> V_47 & V_48 ) )
return 0 ;
if ( V_29 -> V_195 )
return - V_34 ;
V_195 = F_76 ( V_29 -> V_45 , sizeof( * V_195 ) , V_43 ) ;
if ( ! V_195 ) {
F_19 ( V_6 -> V_8 , L_12 ,
V_29 -> V_45 ) ;
return - V_44 ;
}
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
int V_56 = F_25 ( V_6 -> V_196 , 0 ,
V_6 -> V_49 ) ;
if ( F_59 ( V_56 ) ) {
F_19 ( V_6 -> V_8 , L_13 ) ;
goto V_197;
}
V_195 [ V_7 ] = (struct V_194 ) {
. V_56 = V_56 ,
. V_198 = 0 ,
. V_199 = V_29 -> V_51 [ V_7 ] ,
} ;
}
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_77 = V_200 | V_195 [ V_7 ] . V_199 << V_201 |
V_195 [ V_7 ] . V_198 << V_202 ;
F_32 ( V_77 , V_58 + F_77 ( V_195 [ V_7 ] . V_56 ) ) ;
}
V_29 -> V_195 = V_195 ;
return 0 ;
V_197:
while ( -- V_7 >= 0 )
F_28 ( V_6 -> V_196 , V_195 [ V_7 ] . V_56 ) ;
F_70 ( V_195 ) ;
return - V_42 ;
}
static void F_78 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_7 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
struct V_194 * V_195 = V_29 -> V_195 ;
if ( ! V_195 )
return;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_6 V_56 = V_195 [ V_7 ] . V_56 ;
F_32 ( ~ V_200 , V_58 + F_77 ( V_56 ) ) ;
F_28 ( V_6 -> V_196 , V_56 ) ;
}
V_29 -> V_195 = NULL ;
F_70 ( V_195 ) ;
}
static int F_79 ( struct V_1 * V_64 ,
struct V_28 * V_29 )
{
int V_7 , V_89 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( V_64 -> V_4 . type == V_162 )
return 0 ;
V_89 = F_75 ( V_6 , V_29 ) ;
if ( V_89 )
return V_89 == - V_34 ? 0 : V_89 ;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_56 , V_203 ;
V_56 = V_29 -> V_195 ? V_29 -> V_195 [ V_7 ] . V_56 : V_29 -> V_51 [ V_7 ] ;
V_203 = V_204 | V_205 |
( V_64 -> V_29 . V_70 << V_206 ) ;
F_32 ( V_203 , V_58 + F_80 ( V_56 ) ) ;
}
return 0 ;
}
static void F_81 ( struct V_1 * V_64 ,
struct V_28 * V_29 )
{
int V_7 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( ( V_6 -> V_47 & V_48 ) && ! V_29 -> V_195 )
return;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_56 = V_29 -> V_195 ? V_29 -> V_195 [ V_7 ] . V_56 : V_29 -> V_51 [ V_7 ] ;
T_5 V_77 = V_207 ? V_208 : V_209 ;
F_32 ( V_77 , V_58 + F_80 ( V_56 ) ) ;
}
F_78 ( V_6 , V_29 ) ;
}
static void F_82 ( struct V_15 * V_8 ,
struct V_28 * V_29 )
{
struct V_2 * V_4 = V_8 -> V_210 . V_211 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
V_8 -> V_210 . V_211 = NULL ;
F_81 ( V_64 , V_29 ) ;
}
static int F_83 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
int V_89 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 ;
struct V_28 * V_29 ;
V_6 = F_21 ( V_8 ) ;
if ( ! V_6 ) {
F_19 ( V_8 , L_14 ) ;
return - V_212 ;
}
V_89 = F_57 ( V_4 , V_6 ) ;
if ( F_59 ( V_89 ) )
return V_89 ;
if ( V_64 -> V_6 != V_6 ) {
F_19 ( V_8 ,
L_15 ,
F_84 ( V_64 -> V_6 -> V_8 ) , F_84 ( V_6 -> V_8 ) ) ;
return - V_178 ;
}
V_29 = F_11 ( V_8 ) ;
if ( ! V_29 )
return - V_213 ;
if ( V_8 -> V_210 . V_211 )
F_82 ( V_8 , V_29 ) ;
V_89 = F_79 ( V_64 , V_29 ) ;
if ( ! V_89 )
V_8 -> V_210 . V_211 = V_4 ;
return V_89 ;
}
static int F_85 ( struct V_2 * V_4 , unsigned long V_73 ,
T_7 V_214 , T_3 V_74 , int V_215 )
{
int V_89 ;
unsigned long V_88 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_156 * V_216 = V_64 -> V_157 ;
if ( ! V_216 )
return - V_213 ;
F_86 ( & V_64 -> V_193 , V_88 ) ;
V_89 = V_216 -> V_53 ( V_216 , V_73 , V_214 , V_74 , V_215 ) ;
F_87 ( & V_64 -> V_193 , V_88 ) ;
return V_89 ;
}
static T_3 F_88 ( struct V_2 * V_4 , unsigned long V_73 ,
T_3 V_74 )
{
T_3 V_89 ;
unsigned long V_88 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_156 * V_216 = V_64 -> V_157 ;
if ( ! V_216 )
return 0 ;
F_86 ( & V_64 -> V_193 , V_88 ) ;
V_89 = V_216 -> V_217 ( V_216 , V_73 , V_74 ) ;
F_87 ( & V_64 -> V_193 , V_88 ) ;
return V_89 ;
}
static T_7 F_89 ( struct V_2 * V_4 ,
T_8 V_73 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_64 -> V_6 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_156 * V_216 = V_64 -> V_157 ;
struct V_15 * V_8 = V_6 -> V_8 ;
void T_2 * V_94 ;
T_5 V_218 ;
V_83 V_219 ;
unsigned long V_220 ;
V_94 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_220 = V_73 & ~ 0xfffUL ;
if ( V_6 -> V_81 == V_84 )
F_55 ( V_220 , V_94 + V_221 ) ;
else
F_32 ( V_220 , V_94 + V_221 ) ;
if ( F_90 ( V_94 + V_222 , V_218 ,
! ( V_218 & V_223 ) , 5 , 50 ) ) {
F_19 ( V_8 ,
L_16 ,
& V_73 ) ;
return V_216 -> V_224 ( V_216 , V_73 ) ;
}
V_219 = F_33 ( V_94 + V_225 ) ;
V_219 |= ( ( V_83 ) F_33 ( V_94 + V_226 ) ) << 32 ;
if ( V_219 & V_227 ) {
F_19 ( V_8 , L_17 ) ;
F_19 ( V_8 , L_18 , V_219 ) ;
return 0 ;
}
return ( V_219 & F_91 ( 39 , 12 ) ) | ( V_73 & 0xfff ) ;
}
static T_7 F_92 ( struct V_2 * V_4 ,
T_8 V_73 )
{
T_7 V_89 ;
unsigned long V_88 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_156 * V_216 = V_64 -> V_157 ;
if ( ! V_216 )
return 0 ;
F_86 ( & V_64 -> V_193 , V_88 ) ;
if ( V_64 -> V_6 -> V_47 & V_228 &&
V_64 -> V_164 == V_167 ) {
V_89 = F_89 ( V_4 , V_73 ) ;
} else {
V_89 = V_216 -> V_224 ( V_216 , V_73 ) ;
}
F_87 ( & V_64 -> V_193 , V_88 ) ;
return V_89 ;
}
static bool F_93 ( enum V_229 V_230 )
{
switch ( V_230 ) {
case V_231 :
return true ;
case V_232 :
return true ;
case V_233 :
return true ;
default:
return false ;
}
}
static int F_94 ( struct V_234 * V_235 , T_1 V_236 , void * V_237 )
{
* ( ( T_1 * ) V_237 ) = V_236 ;
return 0 ;
}
static void F_95 ( void * V_237 )
{
F_70 ( V_237 ) ;
}
static int F_96 ( struct V_234 * V_235 ,
struct V_30 * V_31 )
{
struct V_28 * V_29 ;
T_1 V_238 ;
int V_7 ;
V_29 = F_13 ( V_31 ) ;
if ( ! V_29 ) {
V_29 = F_68 ( sizeof( * V_29 ) , V_43 ) ;
if ( ! V_29 )
return - V_44 ;
F_97 ( V_31 , V_29 ,
F_95 ) ;
}
if ( V_29 -> V_45 >= V_41 )
return - V_42 ;
F_98 ( V_235 , F_94 , & V_238 ) ;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 )
if ( V_29 -> V_51 [ V_7 ] == V_238 )
break;
if ( V_7 == V_29 -> V_45 )
V_29 -> V_51 [ V_29 -> V_45 ++ ] = V_238 ;
return 0 ;
}
static int F_99 ( struct V_15 * V_8 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = F_21 ( V_8 ) ;
struct V_20 * V_25 ;
if ( ! V_6 )
return - V_213 ;
V_25 = F_10 ( V_6 , V_8 -> V_9 ) ;
if ( ! V_25 )
return - V_213 ;
F_97 ( V_31 , & V_25 -> V_29 , NULL ) ;
return 0 ;
}
static int F_100 ( struct V_15 * V_8 )
{
struct V_30 * V_31 ;
V_31 = F_101 ( V_8 ) ;
if ( F_102 ( V_31 ) )
return F_103 ( V_31 ) ;
F_14 ( V_31 ) ;
return 0 ;
}
static void F_104 ( struct V_15 * V_8 )
{
F_105 ( V_8 ) ;
}
static struct V_30 * F_106 ( struct V_15 * V_8 )
{
struct V_30 * V_31 ;
int V_89 ;
if ( F_7 ( V_8 ) )
V_31 = F_107 ( V_8 ) ;
else
V_31 = F_108 ( V_8 ) ;
if ( F_102 ( V_31 ) )
return V_31 ;
if ( F_7 ( V_8 ) )
V_89 = F_96 ( F_8 ( V_8 ) , V_31 ) ;
else
V_89 = F_99 ( V_8 , V_31 ) ;
if ( V_89 ) {
F_14 ( V_31 ) ;
V_31 = F_109 ( V_89 ) ;
}
return V_31 ;
}
static int F_110 ( struct V_2 * V_4 ,
enum V_239 V_240 , void * V_237 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
switch ( V_240 ) {
case V_241 :
* ( int * ) V_237 = ( V_64 -> V_164 == V_174 ) ;
return 0 ;
default:
return - V_213 ;
}
}
static int F_111 ( struct V_2 * V_4 ,
enum V_239 V_240 , void * V_237 )
{
int V_89 = 0 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
F_58 ( & V_64 -> V_160 ) ;
switch ( V_240 ) {
case V_241 :
if ( V_64 -> V_6 ) {
V_89 = - V_242 ;
goto V_161;
}
if ( * ( int * ) V_237 )
V_64 -> V_164 = V_174 ;
else
V_64 -> V_164 = V_167 ;
break;
default:
V_89 = - V_213 ;
}
V_161:
F_63 ( & V_64 -> V_160 ) ;
return V_89 ;
}
static void F_112 ( struct V_5 * V_6 )
{
void T_2 * V_58 = F_31 ( V_6 ) ;
void T_2 * V_94 ;
int V_7 = 0 ;
T_5 V_77 ;
V_77 = F_33 ( F_50 ( V_6 ) + V_114 ) ;
F_48 ( V_77 , F_50 ( V_6 ) + V_114 ) ;
V_77 = V_207 ? V_208 : V_209 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_49 ; ++ V_7 ) {
F_32 ( 0 , V_58 + F_77 ( V_7 ) ) ;
F_32 ( V_77 , V_58 + F_80 ( V_7 ) ) ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_180 ; ++ V_7 ) {
V_94 = F_39 ( V_6 ) + F_40 ( V_6 , V_7 ) ;
F_32 ( 0 , V_94 + V_153 ) ;
F_32 ( V_96 , V_94 + V_95 ) ;
}
F_32 ( 0 , V_58 + V_243 ) ;
F_32 ( 0 , V_58 + V_244 ) ;
V_77 = F_33 ( F_50 ( V_6 ) + V_245 ) ;
V_77 |= ( V_246 | V_247 | V_248 | V_249 ) ;
V_77 |= ( V_250 | V_251 ) ;
V_77 &= ~ V_252 ;
if ( V_207 )
V_77 |= V_253 ;
else
V_77 &= ~ V_253 ;
V_77 &= ~ V_254 ;
V_77 &= ~ ( V_255 << V_256 ) ;
F_30 ( V_6 ) ;
F_48 ( V_77 , F_50 ( V_6 ) + V_245 ) ;
}
static int F_113 ( int V_74 )
{
switch ( V_74 ) {
case 0 :
return 32 ;
case 1 :
return 36 ;
case 2 :
return 40 ;
case 3 :
return 42 ;
case 4 :
return 44 ;
case 5 :
default:
return 48 ;
}
}
static int F_114 ( struct V_5 * V_6 )
{
unsigned long V_74 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
T_5 V_199 ;
bool V_257 , V_258 ;
F_5 ( V_6 -> V_8 , L_19 ) ;
F_5 ( V_6 -> V_8 , L_20 , V_6 -> V_81 ) ;
V_199 = F_33 ( V_58 + V_259 ) ;
if ( V_260 == 1 )
V_199 &= ~ ( V_261 | V_262 ) ;
else if ( V_260 == 2 )
V_199 &= ~ ( V_263 | V_262 ) ;
if ( V_199 & V_263 ) {
V_6 -> V_47 |= V_163 ;
F_5 ( V_6 -> V_8 , L_21 ) ;
}
if ( V_199 & V_261 ) {
V_6 -> V_47 |= V_166 ;
F_5 ( V_6 -> V_8 , L_22 ) ;
}
if ( V_199 & V_262 ) {
V_6 -> V_47 |= V_264 ;
F_5 ( V_6 -> V_8 , L_23 ) ;
}
if ( ! ( V_6 -> V_47 &
( V_163 | V_166 ) ) ) {
F_19 ( V_6 -> V_8 , L_24 ) ;
return - V_213 ;
}
if ( ( V_199 & V_263 ) && ( ( V_6 -> V_81 == 1 ) || ! ( V_199 & V_265 ) ) ) {
V_6 -> V_47 |= V_228 ;
F_5 ( V_6 -> V_8 , L_25 ) ;
}
V_257 = F_115 ( V_6 -> V_8 -> V_9 ) ;
V_258 = ! ! ( V_199 & V_266 ) ;
if ( V_257 )
V_6 -> V_47 |= V_267 ;
if ( V_257 || V_258 )
F_5 ( V_6 -> V_8 , L_26 ,
V_257 ? L_27 : L_28 ) ;
if ( V_257 != V_258 )
F_5 ( V_6 -> V_8 ,
L_29 ) ;
if ( V_199 & V_268 ) {
T_5 V_269 , V_238 , V_198 ;
V_6 -> V_47 |= V_48 ;
V_6 -> V_49 = ( V_199 >> V_270 ) &
V_271 ;
if ( V_6 -> V_49 == 0 ) {
F_19 ( V_6 -> V_8 ,
L_30 ) ;
return - V_213 ;
}
V_269 = V_272 << V_202 ;
V_269 |= ( V_273 << V_201 ) ;
F_32 ( V_269 , V_58 + F_77 ( 0 ) ) ;
V_269 = F_33 ( V_58 + F_77 ( 0 ) ) ;
V_198 = ( V_269 >> V_202 ) & V_272 ;
V_238 = ( V_269 >> V_201 ) & V_273 ;
if ( ( V_198 & V_238 ) != V_238 ) {
F_19 ( V_6 -> V_8 ,
L_31 ,
V_198 , V_238 ) ;
return - V_213 ;
}
F_5 ( V_6 -> V_8 ,
L_32 ,
V_6 -> V_49 , V_198 ) ;
} else {
V_6 -> V_49 = ( V_199 >> V_274 ) &
V_275 ;
}
V_199 = F_33 ( V_58 + V_276 ) ;
V_6 -> V_277 = ( V_199 & V_278 ) ? 16 : 12 ;
V_74 = 1 << ( ( ( V_199 >> V_279 ) & V_280 ) + 1 ) ;
V_74 *= 2 << V_6 -> V_277 ;
if ( V_6 -> V_74 != V_74 )
F_116 ( V_6 -> V_8 ,
L_33 ,
V_74 , V_6 -> V_74 ) ;
V_6 -> V_169 = ( V_199 >> V_281 ) & V_282 ;
V_6 -> V_180 = ( V_199 >> V_283 ) & V_284 ;
if ( V_6 -> V_169 > V_6 -> V_180 ) {
F_19 ( V_6 -> V_8 , L_34 ) ;
return - V_213 ;
}
F_5 ( V_6 -> V_8 , L_35 ,
V_6 -> V_180 , V_6 -> V_169 ) ;
V_199 = F_33 ( V_58 + V_285 ) ;
V_74 = F_113 ( ( V_199 >> V_286 ) & V_287 ) ;
V_6 -> V_171 = V_74 ;
V_74 = F_113 ( ( V_199 >> V_288 ) & V_289 ) ;
V_6 -> V_175 = V_74 ;
if ( F_117 ( V_6 -> V_8 , F_118 ( V_74 ) ) )
F_116 ( V_6 -> V_8 ,
L_36 ) ;
if ( V_6 -> V_81 == V_82 ) {
V_6 -> V_170 = V_6 -> V_171 ;
V_74 = V_290 | V_291 | V_292 ;
} else {
V_74 = ( V_199 >> V_293 ) & V_294 ;
V_6 -> V_170 = F_113 ( V_74 ) ;
#ifndef V_80
V_6 -> V_170 = F_119 ( 32UL , V_6 -> V_170 ) ;
#endif
V_74 = 0 ;
if ( V_199 & V_295 )
V_74 |= V_290 | V_291 | V_292 ;
if ( V_199 & V_296 )
V_74 |= V_297 | V_298 ;
if ( V_199 & V_299 )
V_74 |= V_300 | V_301 ;
}
V_183 . V_182 &= V_74 ;
F_5 ( V_6 -> V_8 , L_37 , V_74 ) ;
if ( V_6 -> V_47 & V_163 )
F_5 ( V_6 -> V_8 , L_38 ,
V_6 -> V_170 , V_6 -> V_171 ) ;
if ( V_6 -> V_47 & V_166 )
F_5 ( V_6 -> V_8 , L_39 ,
V_6 -> V_171 , V_6 -> V_175 ) ;
return 0 ;
}
static int F_120 ( struct V_302 * V_235 )
{
const struct V_303 * V_304 ;
struct V_305 * V_306 ;
struct V_5 * V_6 ;
struct V_15 * V_8 = & V_235 -> V_8 ;
struct V_22 * V_23 ;
struct V_35 V_36 ;
int V_307 , V_7 , V_308 ;
V_6 = F_20 ( V_8 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 ) {
F_19 ( V_8 , L_40 ) ;
return - V_44 ;
}
V_6 -> V_8 = V_8 ;
V_304 = F_121 ( V_309 , V_8 -> V_9 ) ;
V_6 -> V_81 = (enum V_310 ) V_304 -> V_237 ;
V_306 = F_122 ( V_235 , V_311 , 0 ) ;
V_6 -> V_69 = F_123 ( V_8 , V_306 ) ;
if ( F_102 ( V_6 -> V_69 ) )
return F_103 ( V_6 -> V_69 ) ;
V_6 -> V_74 = F_124 ( V_306 ) ;
if ( F_125 ( V_8 -> V_9 , L_41 ,
& V_6 -> V_189 ) ) {
F_19 ( V_8 , L_42 ) ;
return - V_213 ;
}
V_307 = 0 ;
while ( ( V_306 = F_122 ( V_235 , V_312 , V_307 ) ) ) {
V_307 ++ ;
if ( V_307 > V_6 -> V_189 )
V_6 -> V_181 ++ ;
}
if ( ! V_6 -> V_181 ) {
F_19 ( V_8 , L_43 ,
V_307 , V_6 -> V_189 + 1 ) ;
return - V_213 ;
}
V_6 -> V_188 = F_20 ( V_8 , sizeof( * V_6 -> V_188 ) * V_307 ,
V_43 ) ;
if ( ! V_6 -> V_188 ) {
F_19 ( V_8 , L_44 , V_307 ) ;
return - V_44 ;
}
for ( V_7 = 0 ; V_7 < V_307 ; ++ V_7 ) {
int V_87 = F_126 ( V_235 , V_7 ) ;
if ( V_87 < 0 ) {
F_19 ( V_8 , L_45 , V_7 ) ;
return - V_213 ;
}
V_6 -> V_188 [ V_7 ] = V_87 ;
}
V_308 = F_114 ( V_6 ) ;
if ( V_308 )
return V_308 ;
V_7 = 0 ;
V_6 -> V_24 = V_313 ;
while ( ! F_127 ( V_8 -> V_9 , L_46 ,
L_47 , V_7 ,
& V_36 ) ) {
V_308 = F_18 ( V_6 , V_8 , & V_36 ) ;
if ( V_308 ) {
F_19 ( V_8 , L_48 ,
V_36 . V_37 -> V_38 ) ;
goto V_314;
}
V_7 ++ ;
}
F_5 ( V_8 , L_49 , V_7 ) ;
F_3 ( V_6 ) ;
if ( V_6 -> V_81 > V_82 &&
V_6 -> V_180 != V_6 -> V_181 ) {
F_19 ( V_8 ,
L_50 ,
V_6 -> V_181 , V_6 -> V_180 ) ;
V_308 = - V_213 ;
goto V_314;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_189 ; ++ V_7 ) {
V_308 = F_62 ( V_6 -> V_188 [ V_7 ] ,
F_49 ,
V_190 ,
L_51 ,
V_6 ) ;
if ( V_308 ) {
F_19 ( V_8 , L_52 ,
V_7 , V_6 -> V_188 [ V_7 ] ) ;
goto V_315;
}
}
F_128 ( & V_6 -> V_316 ) ;
F_22 ( & V_52 ) ;
F_129 ( & V_6 -> V_316 , & V_317 ) ;
F_24 ( & V_52 ) ;
F_112 ( V_6 ) ;
return 0 ;
V_315:
while ( V_7 -- )
F_65 ( V_6 -> V_188 [ V_7 ] , V_6 ) ;
V_314:
for ( V_23 = F_130 ( & V_6 -> V_24 ) ; V_23 ; V_23 = F_131 ( V_23 ) ) {
struct V_20 * V_25
= F_2 ( V_23 , struct V_20 , V_23 ) ;
F_132 ( V_25 -> V_9 ) ;
}
return V_308 ;
}
static int F_133 ( struct V_302 * V_235 )
{
int V_7 ;
struct V_15 * V_8 = & V_235 -> V_8 ;
struct V_5 * V_318 , * V_6 = NULL ;
struct V_22 * V_23 ;
F_22 ( & V_52 ) ;
F_23 (curr, &arm_smmu_devices, list) {
if ( V_318 -> V_8 == V_8 ) {
V_6 = V_318 ;
F_134 ( & V_6 -> V_316 ) ;
break;
}
}
F_24 ( & V_52 ) ;
if ( ! V_6 )
return - V_213 ;
for ( V_23 = F_130 ( & V_6 -> V_24 ) ; V_23 ; V_23 = F_131 ( V_23 ) ) {
struct V_20 * V_25
= F_2 ( V_23 , struct V_20 , V_23 ) ;
F_132 ( V_25 -> V_9 ) ;
}
if ( ! F_135 ( V_6 -> V_179 , V_319 ) )
F_19 ( V_8 , L_53 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_189 ; ++ V_7 )
F_65 ( V_6 -> V_188 [ V_7 ] , V_6 ) ;
F_48 ( V_252 , F_50 ( V_6 ) + V_245 ) ;
return 0 ;
}
static int T_9 F_136 ( void )
{
struct V_14 * V_37 ;
int V_89 ;
V_37 = F_137 ( NULL , V_309 ) ;
if ( ! V_37 )
return 0 ;
F_132 ( V_37 ) ;
V_89 = F_138 ( & V_320 ) ;
if ( V_89 )
return V_89 ;
if ( ! F_139 ( & V_321 ) )
F_140 ( & V_321 , & V_183 ) ;
#ifdef F_141
if ( ! F_139 ( & V_322 ) )
F_140 ( & V_322 , & V_183 ) ;
#endif
#ifdef F_142
if ( ! F_139 ( & V_323 ) )
F_140 ( & V_323 , & V_183 ) ;
#endif
return 0 ;
}
static void T_10 F_143 ( void )
{
return F_144 ( & V_320 ) ;
}

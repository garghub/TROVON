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
bool V_75 , void * V_63 )
{
struct V_1 * V_64 = V_63 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_5 * V_6 = V_64 -> V_6 ;
bool V_66 = V_29 -> V_67 != V_68 ;
void T_2 * V_76 ;
if ( V_66 ) {
V_76 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_76 += V_75 ? V_77 : V_78 ;
if ( ! F_44 ( V_79 ) || V_6 -> V_80 == V_81 ) {
V_73 &= ~ 12UL ;
V_73 |= F_41 ( V_29 ) ;
F_32 ( V_73 , V_76 ) ;
#ifdef V_79
} else {
V_73 >>= 12 ;
V_73 |= ( V_82 ) F_41 ( V_29 ) << 48 ;
F_45 ( V_73 , V_76 ) ;
#endif
}
#ifdef V_79
} else if ( V_6 -> V_80 == V_83 ) {
V_76 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_76 += V_75 ? V_84 :
V_85 ;
F_45 ( V_73 >> 12 , V_76 ) ;
#endif
} else {
V_76 = F_31 ( V_6 ) + V_72 ;
F_32 ( F_42 ( V_29 ) , V_76 ) ;
}
}
static T_4 F_46 ( int V_86 , void * V_8 )
{
int V_87 , V_88 ;
T_5 V_89 , V_90 , V_91 , V_92 ;
unsigned long V_73 ;
struct V_2 * V_4 = V_8 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_93 ;
V_93 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_89 = F_33 ( V_93 + V_94 ) ;
if ( ! ( V_89 & V_95 ) )
return V_96 ;
if ( V_89 & V_97 )
F_35 ( V_6 -> V_8 ,
L_6 ,
V_89 ) ;
V_91 = F_33 ( V_93 + V_98 ) ;
V_87 = V_91 & V_99 ? V_100 : V_101 ;
V_90 = F_33 ( V_93 + V_102 ) ;
V_73 = V_90 ;
#ifdef V_79
V_90 = F_33 ( V_93 + V_103 ) ;
V_73 |= ( ( unsigned long ) V_90 << 32 ) ;
#endif
if ( ! F_47 ( V_4 , V_6 -> V_8 , V_73 , V_87 ) ) {
V_88 = V_104 ;
V_92 = V_105 ;
} else {
F_35 ( V_6 -> V_8 ,
L_7 ,
V_73 , V_91 , V_29 -> V_70 ) ;
V_88 = V_96 ;
V_92 = V_106 ;
}
F_48 ( V_89 , V_93 + V_94 ) ;
if ( V_89 & V_107 )
F_32 ( V_92 , V_93 + V_108 ) ;
return V_88 ;
}
static T_4 F_49 ( int V_86 , void * V_8 )
{
T_5 V_109 , V_110 , V_111 , V_112 ;
struct V_5 * V_6 = V_8 ;
void T_2 * V_58 = F_50 ( V_6 ) ;
V_109 = F_33 ( V_58 + V_113 ) ;
V_110 = F_33 ( V_58 + V_114 ) ;
V_111 = F_33 ( V_58 + V_115 ) ;
V_112 = F_33 ( V_58 + V_116 ) ;
if ( ! V_109 )
return V_96 ;
F_35 ( V_6 -> V_8 ,
L_8 ) ;
F_35 ( V_6 -> V_8 ,
L_9 ,
V_109 , V_110 , V_111 , V_112 ) ;
F_48 ( V_109 , V_58 + V_113 ) ;
return V_104 ;
}
static void F_51 ( struct V_1 * V_64 ,
struct V_117 * V_118 )
{
T_5 V_76 ;
bool V_66 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_93 , * V_58 , * V_119 ;
V_58 = F_31 ( V_6 ) ;
V_119 = F_52 ( V_6 ) ;
V_66 = V_29 -> V_67 != V_68 ;
V_93 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
if ( V_6 -> V_80 > V_81 ) {
#ifdef V_79
V_76 = V_120 ;
#else
V_76 = V_121 ;
#endif
F_32 ( V_76 , V_119 + F_53 ( V_29 -> V_70 ) ) ;
}
V_76 = V_29 -> V_67 ;
if ( V_6 -> V_80 == V_81 )
V_76 |= V_29 -> V_122 << V_123 ;
if ( V_66 ) {
V_76 |= ( V_124 << V_125 ) |
( V_126 << V_127 ) ;
} else {
V_76 |= F_42 ( V_29 ) << V_128 ;
}
F_32 ( V_76 , V_119 + F_54 ( V_29 -> V_70 ) ) ;
if ( V_66 ) {
V_76 = V_118 -> V_129 . V_130 [ 0 ] ;
F_32 ( V_76 , V_93 + V_131 ) ;
V_76 = V_118 -> V_129 . V_130 [ 0 ] >> 32 ;
V_76 |= F_41 ( V_29 ) << V_132 ;
F_32 ( V_76 , V_93 + V_133 ) ;
V_76 = V_118 -> V_129 . V_130 [ 1 ] ;
F_32 ( V_76 , V_93 + V_134 ) ;
V_76 = V_118 -> V_129 . V_130 [ 1 ] >> 32 ;
V_76 |= F_41 ( V_29 ) << V_132 ;
F_32 ( V_76 , V_93 + V_135 ) ;
} else {
V_76 = V_118 -> V_136 . V_137 ;
F_32 ( V_76 , V_93 + V_131 ) ;
V_76 = V_118 -> V_136 . V_137 >> 32 ;
F_32 ( V_76 , V_93 + V_133 ) ;
}
if ( V_66 ) {
V_76 = V_118 -> V_129 . V_138 ;
F_32 ( V_76 , V_93 + V_139 ) ;
if ( V_6 -> V_80 > V_81 ) {
V_76 = V_118 -> V_129 . V_138 >> 32 ;
V_76 |= V_140 ;
F_32 ( V_76 , V_93 + V_141 ) ;
}
} else {
V_76 = V_118 -> V_136 . V_142 ;
F_32 ( V_76 , V_93 + V_139 ) ;
}
if ( V_66 ) {
V_76 = V_118 -> V_129 . V_143 [ 0 ] ;
F_32 ( V_76 , V_93 + V_144 ) ;
V_76 = V_118 -> V_129 . V_143 [ 1 ] ;
F_32 ( V_76 , V_93 + V_145 ) ;
}
V_76 = V_146 | V_147 | V_148 | V_149 | V_150 ;
if ( V_66 )
V_76 |= V_151 ;
#ifdef F_55
V_76 |= V_152 ;
#endif
F_32 ( V_76 , V_93 + V_153 ) ;
}
static int F_56 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
int V_86 , V_54 , V_88 = 0 ;
unsigned long V_154 , V_155 ;
struct V_156 * V_157 ;
struct V_117 V_118 ;
enum V_158 V_159 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_65 * V_29 = & V_64 -> V_29 ;
F_57 ( & V_64 -> V_160 ) ;
if ( V_64 -> V_6 )
goto V_161;
if ( ! ( V_6 -> V_47 & V_162 ) )
V_64 -> V_163 = V_164 ;
if ( ! ( V_6 -> V_47 & V_165 ) )
V_64 -> V_163 = V_166 ;
switch ( V_64 -> V_163 ) {
case V_166 :
V_29 -> V_67 = V_167 ;
V_54 = V_6 -> V_168 ;
V_154 = V_6 -> V_169 ;
V_155 = V_6 -> V_170 ;
if ( F_44 ( V_79 ) )
V_159 = V_171 ;
else
V_159 = V_172 ;
break;
case V_173 :
case V_164 :
V_29 -> V_67 = V_68 ;
V_54 = 0 ;
V_154 = V_6 -> V_170 ;
V_155 = V_6 -> V_174 ;
if ( F_44 ( V_79 ) )
V_159 = V_175 ;
else
V_159 = V_176 ;
break;
default:
V_88 = - V_177 ;
goto V_161;
}
V_88 = F_25 ( V_6 -> V_178 , V_54 ,
V_6 -> V_179 ) ;
if ( F_58 ( V_88 ) )
goto V_161;
V_29 -> V_70 = V_88 ;
if ( V_6 -> V_80 == V_81 ) {
V_29 -> V_122 = F_59 ( & V_6 -> V_122 ) ;
V_29 -> V_122 %= V_6 -> V_180 ;
} else {
V_29 -> V_122 = V_29 -> V_70 ;
}
V_118 = (struct V_117 ) {
. V_181 = V_182 . V_181 ,
. V_154 = V_154 ,
. V_155 = V_155 ,
. V_183 = & V_184 ,
. V_185 = V_6 -> V_8 ,
} ;
V_64 -> V_6 = V_6 ;
V_157 = F_60 ( V_159 , & V_118 , V_64 ) ;
if ( ! V_157 ) {
V_88 = - V_44 ;
goto V_186;
}
V_182 . V_181 = V_118 . V_181 ;
F_51 ( V_64 , & V_118 ) ;
V_86 = V_6 -> V_187 [ V_6 -> V_188 + V_29 -> V_122 ] ;
V_88 = F_61 ( V_86 , F_46 , V_189 ,
L_10 , V_4 ) ;
if ( F_58 ( V_88 ) ) {
F_19 ( V_6 -> V_8 , L_11 ,
V_29 -> V_122 , V_86 ) ;
V_29 -> V_122 = V_190 ;
}
F_62 ( & V_64 -> V_160 ) ;
V_64 -> V_157 = V_157 ;
return 0 ;
V_186:
V_64 -> V_6 = NULL ;
V_161:
F_62 ( & V_64 -> V_160 ) ;
return V_88 ;
}
static void F_63 ( struct V_2 * V_4 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_64 -> V_6 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
void T_2 * V_93 ;
int V_86 ;
if ( ! V_6 )
return;
V_93 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
F_32 ( 0 , V_93 + V_153 ) ;
if ( V_29 -> V_122 != V_190 ) {
V_86 = V_6 -> V_187 [ V_6 -> V_188 + V_29 -> V_122 ] ;
F_64 ( V_86 , V_4 ) ;
}
if ( V_64 -> V_157 )
F_65 ( V_64 -> V_157 ) ;
F_28 ( V_6 -> V_178 , V_29 -> V_70 ) ;
}
static struct V_2 * F_66 ( unsigned type )
{
struct V_1 * V_64 ;
if ( type != V_191 )
return NULL ;
V_64 = F_67 ( sizeof( * V_64 ) , V_43 ) ;
if ( ! V_64 )
return NULL ;
F_68 ( & V_64 -> V_160 ) ;
F_69 ( & V_64 -> V_192 ) ;
return & V_64 -> V_4 ;
}
static void F_70 ( struct V_2 * V_4 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
F_63 ( V_4 ) ;
F_71 ( V_64 ) ;
}
static int F_72 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_7 ;
struct V_193 * V_194 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( ! ( V_6 -> V_47 & V_48 ) )
return 0 ;
if ( V_29 -> V_194 )
return - V_34 ;
V_194 = F_73 ( V_29 -> V_45 , sizeof( * V_194 ) , V_43 ) ;
if ( ! V_194 ) {
F_19 ( V_6 -> V_8 , L_12 ,
V_29 -> V_45 ) ;
return - V_44 ;
}
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
int V_56 = F_25 ( V_6 -> V_195 , 0 ,
V_6 -> V_49 ) ;
if ( F_58 ( V_56 ) ) {
F_19 ( V_6 -> V_8 , L_13 ) ;
goto V_196;
}
V_194 [ V_7 ] = (struct V_193 ) {
. V_56 = V_56 ,
. V_197 = 0 ,
. V_198 = V_29 -> V_51 [ V_7 ] ,
} ;
}
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_76 = V_199 | V_194 [ V_7 ] . V_198 << V_200 |
V_194 [ V_7 ] . V_197 << V_201 ;
F_32 ( V_76 , V_58 + F_74 ( V_194 [ V_7 ] . V_56 ) ) ;
}
V_29 -> V_194 = V_194 ;
return 0 ;
V_196:
while ( -- V_7 >= 0 )
F_28 ( V_6 -> V_195 , V_194 [ V_7 ] . V_56 ) ;
F_71 ( V_194 ) ;
return - V_42 ;
}
static void F_75 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_7 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
struct V_193 * V_194 = V_29 -> V_194 ;
if ( ! V_194 )
return;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_6 V_56 = V_194 [ V_7 ] . V_56 ;
F_32 ( ~ V_199 , V_58 + F_74 ( V_56 ) ) ;
F_28 ( V_6 -> V_195 , V_56 ) ;
}
V_29 -> V_194 = NULL ;
F_71 ( V_194 ) ;
}
static int F_76 ( struct V_1 * V_64 ,
struct V_28 * V_29 )
{
int V_7 , V_88 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
V_88 = F_72 ( V_6 , V_29 ) ;
if ( V_88 )
return V_88 == - V_34 ? 0 : V_88 ;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_56 , V_202 ;
V_56 = V_29 -> V_194 ? V_29 -> V_194 [ V_7 ] . V_56 : V_29 -> V_51 [ V_7 ] ;
V_202 = V_203 |
( V_64 -> V_29 . V_70 << V_204 ) ;
F_32 ( V_202 , V_58 + F_77 ( V_56 ) ) ;
}
return 0 ;
}
static void F_78 ( struct V_1 * V_64 ,
struct V_28 * V_29 )
{
int V_7 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( ( V_6 -> V_47 & V_48 ) && ! V_29 -> V_194 )
return;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_56 = V_29 -> V_194 ? V_29 -> V_194 [ V_7 ] . V_56 : V_29 -> V_51 [ V_7 ] ;
F_32 ( V_205 ,
V_58 + F_77 ( V_56 ) ) ;
}
F_75 ( V_6 , V_29 ) ;
}
static int F_79 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
int V_88 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 ;
struct V_28 * V_29 ;
V_6 = F_21 ( V_8 ) ;
if ( ! V_6 ) {
F_19 ( V_8 , L_14 ) ;
return - V_206 ;
}
if ( V_8 -> V_207 . V_208 ) {
F_19 ( V_8 , L_15 ) ;
return - V_34 ;
}
V_88 = F_56 ( V_4 , V_6 ) ;
if ( F_58 ( V_88 ) )
return V_88 ;
if ( V_64 -> V_6 != V_6 ) {
F_19 ( V_8 ,
L_16 ,
F_80 ( V_64 -> V_6 -> V_8 ) , F_80 ( V_6 -> V_8 ) ) ;
return - V_177 ;
}
V_29 = F_11 ( V_8 ) ;
if ( ! V_29 )
return - V_209 ;
V_88 = F_76 ( V_64 , V_29 ) ;
if ( ! V_88 )
V_8 -> V_207 . V_208 = V_4 ;
return V_88 ;
}
static void F_81 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_28 * V_29 ;
V_29 = F_11 ( V_8 ) ;
if ( ! V_29 )
return;
V_8 -> V_207 . V_208 = NULL ;
F_78 ( V_64 , V_29 ) ;
}
static int F_82 ( struct V_2 * V_4 , unsigned long V_73 ,
T_7 V_210 , T_3 V_74 , int V_211 )
{
int V_88 ;
unsigned long V_87 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_156 * V_212 = V_64 -> V_157 ;
if ( ! V_212 )
return - V_209 ;
F_83 ( & V_64 -> V_192 , V_87 ) ;
V_88 = V_212 -> V_53 ( V_212 , V_73 , V_210 , V_74 , V_211 ) ;
F_84 ( & V_64 -> V_192 , V_87 ) ;
return V_88 ;
}
static T_3 F_85 ( struct V_2 * V_4 , unsigned long V_73 ,
T_3 V_74 )
{
T_3 V_88 ;
unsigned long V_87 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_156 * V_212 = V_64 -> V_157 ;
if ( ! V_212 )
return 0 ;
F_83 ( & V_64 -> V_192 , V_87 ) ;
V_88 = V_212 -> V_213 ( V_212 , V_73 , V_74 ) ;
F_84 ( & V_64 -> V_192 , V_87 ) ;
return V_88 ;
}
static T_7 F_86 ( struct V_2 * V_4 ,
T_8 V_73 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_64 -> V_6 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_156 * V_212 = V_64 -> V_157 ;
struct V_15 * V_8 = V_6 -> V_8 ;
void T_2 * V_93 ;
T_5 V_214 ;
V_82 V_215 ;
unsigned long V_216 ;
V_93 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_216 = V_73 & ~ 0xfffUL ;
#ifdef V_79
if ( V_6 -> V_80 == V_83 )
F_45 ( V_216 , V_93 + V_217 ) ;
else
#endif
F_32 ( V_216 , V_93 + V_217 ) ;
if ( F_87 ( V_93 + V_218 , V_214 ,
! ( V_214 & V_219 ) , 5 , 50 ) ) {
F_19 ( V_8 ,
L_17 ,
& V_73 ) ;
return V_212 -> V_220 ( V_212 , V_73 ) ;
}
V_215 = F_33 ( V_93 + V_221 ) ;
V_215 |= ( ( V_82 ) F_33 ( V_93 + V_222 ) ) << 32 ;
if ( V_215 & V_223 ) {
F_19 ( V_8 , L_18 ) ;
F_19 ( V_8 , L_19 , V_215 ) ;
return 0 ;
}
return ( V_215 & F_88 ( 39 , 12 ) ) | ( V_73 & 0xfff ) ;
}
static T_7 F_89 ( struct V_2 * V_4 ,
T_8 V_73 )
{
T_7 V_88 ;
unsigned long V_87 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_156 * V_212 = V_64 -> V_157 ;
if ( ! V_212 )
return 0 ;
F_83 ( & V_64 -> V_192 , V_87 ) ;
if ( V_64 -> V_6 -> V_47 & V_224 &&
V_64 -> V_163 == V_166 ) {
V_88 = F_86 ( V_4 , V_73 ) ;
} else {
V_88 = V_212 -> V_220 ( V_212 , V_73 ) ;
}
F_84 ( & V_64 -> V_192 , V_87 ) ;
return V_88 ;
}
static bool F_90 ( enum V_225 V_226 )
{
switch ( V_226 ) {
case V_227 :
return true ;
case V_228 :
return true ;
case V_229 :
return true ;
default:
return false ;
}
}
static int F_91 ( struct V_230 * V_231 , T_1 V_232 , void * V_233 )
{
* ( ( T_1 * ) V_233 ) = V_232 ;
return 0 ;
}
static void F_92 ( void * V_233 )
{
F_71 ( V_233 ) ;
}
static int F_93 ( struct V_230 * V_231 )
{
int V_7 , V_88 ;
T_1 V_234 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
V_31 = F_94 ( & V_231 -> V_8 ) ;
if ( F_95 ( V_31 ) )
return F_96 ( V_31 ) ;
V_29 = F_13 ( V_31 ) ;
if ( ! V_29 ) {
V_29 = F_67 ( sizeof( * V_29 ) , V_43 ) ;
if ( ! V_29 ) {
V_88 = - V_44 ;
goto V_235;
}
F_97 ( V_31 , V_29 ,
F_92 ) ;
}
if ( V_29 -> V_45 >= V_41 ) {
V_88 = - V_42 ;
goto V_235;
}
F_98 ( V_231 , F_91 , & V_234 ) ;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 )
if ( V_29 -> V_51 [ V_7 ] == V_234 )
break;
if ( V_7 == V_29 -> V_45 )
V_29 -> V_51 [ V_29 -> V_45 ++ ] = V_234 ;
return 0 ;
V_235:
F_14 ( V_31 ) ;
return V_88 ;
}
static int F_99 ( struct V_15 * V_8 )
{
struct V_30 * V_31 ;
struct V_20 * V_25 ;
struct V_5 * V_6 = F_21 ( V_8 ) ;
if ( ! V_6 )
return - V_209 ;
V_25 = F_10 ( V_6 , V_8 -> V_9 ) ;
if ( ! V_25 )
return - V_209 ;
V_31 = F_100 () ;
if ( F_95 ( V_31 ) )
return F_96 ( V_31 ) ;
F_97 ( V_31 , & V_25 -> V_29 , NULL ) ;
return F_101 ( V_31 , V_8 ) ;
}
static int F_102 ( struct V_15 * V_8 )
{
if ( F_7 ( V_8 ) )
return F_93 ( F_8 ( V_8 ) ) ;
return F_99 ( V_8 ) ;
}
static void F_103 ( struct V_15 * V_8 )
{
F_104 ( V_8 ) ;
}
static int F_105 ( struct V_2 * V_4 ,
enum V_236 V_237 , void * V_233 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
switch ( V_237 ) {
case V_238 :
* ( int * ) V_233 = ( V_64 -> V_163 == V_173 ) ;
return 0 ;
default:
return - V_209 ;
}
}
static int F_106 ( struct V_2 * V_4 ,
enum V_236 V_237 , void * V_233 )
{
int V_88 = 0 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
F_57 ( & V_64 -> V_160 ) ;
switch ( V_237 ) {
case V_238 :
if ( V_64 -> V_6 ) {
V_88 = - V_239 ;
goto V_161;
}
if ( * ( int * ) V_233 )
V_64 -> V_163 = V_173 ;
else
V_64 -> V_163 = V_166 ;
break;
default:
V_88 = - V_209 ;
}
V_161:
F_62 ( & V_64 -> V_160 ) ;
return V_88 ;
}
static void F_107 ( struct V_5 * V_6 )
{
void T_2 * V_58 = F_31 ( V_6 ) ;
void T_2 * V_93 ;
int V_7 = 0 ;
T_5 V_76 ;
V_76 = F_33 ( F_50 ( V_6 ) + V_113 ) ;
F_48 ( V_76 , F_50 ( V_6 ) + V_113 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_49 ; ++ V_7 ) {
F_32 ( 0 , V_58 + F_74 ( V_7 ) ) ;
F_32 ( V_205 ,
V_58 + F_77 ( V_7 ) ) ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_179 ; ++ V_7 ) {
V_93 = F_39 ( V_6 ) + F_40 ( V_6 , V_7 ) ;
F_32 ( 0 , V_93 + V_153 ) ;
F_32 ( V_95 , V_93 + V_94 ) ;
}
F_32 ( 0 , V_58 + V_240 ) ;
F_32 ( 0 , V_58 + V_241 ) ;
V_76 = F_33 ( F_50 ( V_6 ) + V_242 ) ;
V_76 |= ( V_243 | V_244 | V_245 | V_246 ) ;
V_76 |= ( V_247 | V_248 ) ;
V_76 &= ~ ( V_249 | V_250 ) ;
V_76 &= ~ V_251 ;
V_76 &= ~ ( V_252 << V_253 ) ;
F_30 ( V_6 ) ;
F_48 ( V_76 , F_50 ( V_6 ) + V_242 ) ;
}
static int F_108 ( int V_74 )
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
static int F_109 ( struct V_5 * V_6 )
{
unsigned long V_74 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
T_5 V_198 ;
bool V_254 , V_255 ;
F_5 ( V_6 -> V_8 , L_20 ) ;
F_5 ( V_6 -> V_8 , L_21 , V_6 -> V_80 ) ;
V_198 = F_33 ( V_58 + V_256 ) ;
if ( V_257 == 1 )
V_198 &= ~ ( V_258 | V_259 ) ;
else if ( V_257 == 2 )
V_198 &= ~ ( V_260 | V_259 ) ;
if ( V_198 & V_260 ) {
V_6 -> V_47 |= V_162 ;
F_5 ( V_6 -> V_8 , L_22 ) ;
}
if ( V_198 & V_258 ) {
V_6 -> V_47 |= V_165 ;
F_5 ( V_6 -> V_8 , L_23 ) ;
}
if ( V_198 & V_259 ) {
V_6 -> V_47 |= V_261 ;
F_5 ( V_6 -> V_8 , L_24 ) ;
}
if ( ! ( V_6 -> V_47 &
( V_162 | V_165 ) ) ) {
F_19 ( V_6 -> V_8 , L_25 ) ;
return - V_209 ;
}
if ( ( V_198 & V_260 ) && ( ( V_6 -> V_80 == 1 ) || ! ( V_198 & V_262 ) ) ) {
V_6 -> V_47 |= V_224 ;
F_5 ( V_6 -> V_8 , L_26 ) ;
}
V_254 = F_110 ( V_6 -> V_8 -> V_9 ) ;
V_255 = ! ! ( V_198 & V_263 ) ;
if ( V_254 )
V_6 -> V_47 |= V_264 ;
if ( V_254 || V_255 )
F_5 ( V_6 -> V_8 , L_27 ,
V_254 ? L_28 : L_29 ) ;
if ( V_254 != V_255 )
F_5 ( V_6 -> V_8 ,
L_30 ) ;
if ( V_198 & V_265 ) {
T_5 V_266 , V_234 , V_197 ;
V_6 -> V_47 |= V_48 ;
V_6 -> V_49 = ( V_198 >> V_267 ) &
V_268 ;
if ( V_6 -> V_49 == 0 ) {
F_19 ( V_6 -> V_8 ,
L_31 ) ;
return - V_209 ;
}
V_266 = V_269 << V_201 ;
V_266 |= ( V_270 << V_200 ) ;
F_32 ( V_266 , V_58 + F_74 ( 0 ) ) ;
V_266 = F_33 ( V_58 + F_74 ( 0 ) ) ;
V_197 = ( V_266 >> V_201 ) & V_269 ;
V_234 = ( V_266 >> V_200 ) & V_270 ;
if ( ( V_197 & V_234 ) != V_234 ) {
F_19 ( V_6 -> V_8 ,
L_32 ,
V_197 , V_234 ) ;
return - V_209 ;
}
F_5 ( V_6 -> V_8 ,
L_33 ,
V_6 -> V_49 , V_197 ) ;
} else {
V_6 -> V_49 = ( V_198 >> V_271 ) &
V_272 ;
}
V_198 = F_33 ( V_58 + V_273 ) ;
V_6 -> V_274 = ( V_198 & V_275 ) ? 16 : 12 ;
V_74 = 1 << ( ( ( V_198 >> V_276 ) & V_277 ) + 1 ) ;
V_74 *= 2 << V_6 -> V_274 ;
if ( V_6 -> V_74 != V_74 )
F_111 ( V_6 -> V_8 ,
L_34 ,
V_74 , V_6 -> V_74 ) ;
V_6 -> V_168 = ( V_198 >> V_278 ) & V_279 ;
V_6 -> V_179 = ( V_198 >> V_280 ) & V_281 ;
if ( V_6 -> V_168 > V_6 -> V_179 ) {
F_19 ( V_6 -> V_8 , L_35 ) ;
return - V_209 ;
}
F_5 ( V_6 -> V_8 , L_36 ,
V_6 -> V_179 , V_6 -> V_168 ) ;
V_198 = F_33 ( V_58 + V_282 ) ;
V_74 = F_108 ( ( V_198 >> V_283 ) & V_284 ) ;
V_6 -> V_170 = V_74 ;
V_74 = F_108 ( ( V_198 >> V_285 ) & V_286 ) ;
V_6 -> V_174 = V_74 ;
if ( F_112 ( V_6 -> V_8 , F_113 ( V_74 ) ) )
F_111 ( V_6 -> V_8 ,
L_37 ) ;
if ( V_6 -> V_80 == V_81 ) {
V_6 -> V_169 = V_6 -> V_170 ;
V_74 = V_287 | V_288 | V_289 ;
} else {
V_74 = ( V_198 >> V_290 ) & V_291 ;
V_6 -> V_169 = F_108 ( V_74 ) ;
#ifndef V_79
V_6 -> V_169 = F_114 ( 32UL , V_6 -> V_169 ) ;
#endif
V_74 = 0 ;
if ( V_198 & V_292 )
V_74 |= V_287 | V_288 | V_289 ;
if ( V_198 & V_293 )
V_74 |= V_294 | V_295 ;
if ( V_198 & V_296 )
V_74 |= V_297 | V_298 ;
}
V_182 . V_181 &= V_74 ;
F_5 ( V_6 -> V_8 , L_38 , V_74 ) ;
if ( V_6 -> V_47 & V_162 )
F_5 ( V_6 -> V_8 , L_39 ,
V_6 -> V_169 , V_6 -> V_170 ) ;
if ( V_6 -> V_47 & V_165 )
F_5 ( V_6 -> V_8 , L_40 ,
V_6 -> V_170 , V_6 -> V_174 ) ;
return 0 ;
}
static int F_115 ( struct V_299 * V_231 )
{
const struct V_300 * V_301 ;
struct V_302 * V_303 ;
struct V_5 * V_6 ;
struct V_15 * V_8 = & V_231 -> V_8 ;
struct V_22 * V_23 ;
struct V_35 V_36 ;
int V_304 , V_7 , V_305 ;
V_6 = F_20 ( V_8 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 ) {
F_19 ( V_8 , L_41 ) ;
return - V_44 ;
}
V_6 -> V_8 = V_8 ;
V_301 = F_116 ( V_306 , V_8 -> V_9 ) ;
V_6 -> V_80 = (enum V_307 ) V_301 -> V_233 ;
V_303 = F_117 ( V_231 , V_308 , 0 ) ;
V_6 -> V_69 = F_118 ( V_8 , V_303 ) ;
if ( F_95 ( V_6 -> V_69 ) )
return F_96 ( V_6 -> V_69 ) ;
V_6 -> V_74 = F_119 ( V_303 ) ;
if ( F_120 ( V_8 -> V_9 , L_42 ,
& V_6 -> V_188 ) ) {
F_19 ( V_8 , L_43 ) ;
return - V_209 ;
}
V_304 = 0 ;
while ( ( V_303 = F_117 ( V_231 , V_309 , V_304 ) ) ) {
V_304 ++ ;
if ( V_304 > V_6 -> V_188 )
V_6 -> V_180 ++ ;
}
if ( ! V_6 -> V_180 ) {
F_19 ( V_8 , L_44 ,
V_304 , V_6 -> V_188 + 1 ) ;
return - V_209 ;
}
V_6 -> V_187 = F_20 ( V_8 , sizeof( * V_6 -> V_187 ) * V_304 ,
V_43 ) ;
if ( ! V_6 -> V_187 ) {
F_19 ( V_8 , L_45 , V_304 ) ;
return - V_44 ;
}
for ( V_7 = 0 ; V_7 < V_304 ; ++ V_7 ) {
int V_86 = F_121 ( V_231 , V_7 ) ;
if ( V_86 < 0 ) {
F_19 ( V_8 , L_46 , V_7 ) ;
return - V_209 ;
}
V_6 -> V_187 [ V_7 ] = V_86 ;
}
V_305 = F_109 ( V_6 ) ;
if ( V_305 )
return V_305 ;
V_7 = 0 ;
V_6 -> V_24 = V_310 ;
while ( ! F_122 ( V_8 -> V_9 , L_47 ,
L_48 , V_7 ,
& V_36 ) ) {
V_305 = F_18 ( V_6 , V_8 , & V_36 ) ;
if ( V_305 ) {
F_19 ( V_8 , L_49 ,
V_36 . V_37 -> V_38 ) ;
goto V_311;
}
V_7 ++ ;
}
F_5 ( V_8 , L_50 , V_7 ) ;
F_3 ( V_6 ) ;
if ( V_6 -> V_80 > V_81 &&
V_6 -> V_179 != V_6 -> V_180 ) {
F_19 ( V_8 ,
L_51 ,
V_6 -> V_180 , V_6 -> V_179 ) ;
V_305 = - V_209 ;
goto V_311;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_188 ; ++ V_7 ) {
V_305 = F_61 ( V_6 -> V_187 [ V_7 ] ,
F_49 ,
V_189 ,
L_52 ,
V_6 ) ;
if ( V_305 ) {
F_19 ( V_8 , L_53 ,
V_7 , V_6 -> V_187 [ V_7 ] ) ;
goto V_312;
}
}
F_123 ( & V_6 -> V_313 ) ;
F_22 ( & V_52 ) ;
F_124 ( & V_6 -> V_313 , & V_314 ) ;
F_24 ( & V_52 ) ;
F_107 ( V_6 ) ;
return 0 ;
V_312:
while ( V_7 -- )
F_64 ( V_6 -> V_187 [ V_7 ] , V_6 ) ;
V_311:
for ( V_23 = F_125 ( & V_6 -> V_24 ) ; V_23 ; V_23 = F_126 ( V_23 ) ) {
struct V_20 * V_25
= F_2 ( V_23 , struct V_20 , V_23 ) ;
F_127 ( V_25 -> V_9 ) ;
}
return V_305 ;
}
static int F_128 ( struct V_299 * V_231 )
{
int V_7 ;
struct V_15 * V_8 = & V_231 -> V_8 ;
struct V_5 * V_315 , * V_6 = NULL ;
struct V_22 * V_23 ;
F_22 ( & V_52 ) ;
F_23 (curr, &arm_smmu_devices, list) {
if ( V_315 -> V_8 == V_8 ) {
V_6 = V_315 ;
F_129 ( & V_6 -> V_313 ) ;
break;
}
}
F_24 ( & V_52 ) ;
if ( ! V_6 )
return - V_209 ;
for ( V_23 = F_125 ( & V_6 -> V_24 ) ; V_23 ; V_23 = F_126 ( V_23 ) ) {
struct V_20 * V_25
= F_2 ( V_23 , struct V_20 , V_23 ) ;
F_127 ( V_25 -> V_9 ) ;
}
if ( ! F_130 ( V_6 -> V_178 , V_316 ) )
F_19 ( V_8 , L_54 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_188 ; ++ V_7 )
F_64 ( V_6 -> V_187 [ V_7 ] , V_6 ) ;
F_48 ( V_249 , F_50 ( V_6 ) + V_242 ) ;
return 0 ;
}
static int T_9 F_131 ( void )
{
struct V_14 * V_37 ;
int V_88 ;
V_37 = F_132 ( NULL , V_306 ) ;
if ( ! V_37 )
return 0 ;
F_127 ( V_37 ) ;
V_88 = F_133 ( & V_317 ) ;
if ( V_88 )
return V_88 ;
if ( ! F_134 ( & V_318 ) )
F_135 ( & V_318 , & V_182 ) ;
#ifdef F_136
if ( ! F_134 ( & V_319 ) )
F_135 ( & V_319 , & V_182 ) ;
#endif
#ifdef F_137
if ( ! F_134 ( & V_320 ) )
F_135 ( & V_320 , & V_182 ) ;
#endif
return 0 ;
}
static void T_10 F_138 ( void )
{
return F_139 ( & V_317 ) ;
}

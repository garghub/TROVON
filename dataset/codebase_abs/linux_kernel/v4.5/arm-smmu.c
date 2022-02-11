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
if ( F_44 ( V_80 ) )
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
if ( F_44 ( V_80 ) )
V_159 = V_175 ;
else
V_159 = V_176 ;
break;
default:
V_89 = - V_177 ;
goto V_161;
}
V_89 = F_25 ( V_6 -> V_178 , V_54 ,
V_6 -> V_179 ) ;
if ( F_59 ( V_89 ) )
goto V_161;
V_29 -> V_70 = V_89 ;
if ( V_6 -> V_81 == V_82 ) {
V_29 -> V_124 = F_60 ( & V_6 -> V_124 ) ;
V_29 -> V_124 %= V_6 -> V_180 ;
} else {
V_29 -> V_124 = V_29 -> V_70 ;
}
V_119 = (struct V_118 ) {
. V_181 = V_182 . V_181 ,
. V_154 = V_154 ,
. V_155 = V_155 ,
. V_183 = & V_184 ,
. V_185 = V_6 -> V_8 ,
} ;
V_64 -> V_6 = V_6 ;
V_157 = F_61 ( V_159 , & V_119 , V_64 ) ;
if ( ! V_157 ) {
V_89 = - V_44 ;
goto V_186;
}
V_182 . V_181 = V_119 . V_181 ;
F_51 ( V_64 , & V_119 ) ;
V_87 = V_6 -> V_187 [ V_6 -> V_188 + V_29 -> V_124 ] ;
V_89 = F_62 ( V_87 , F_46 , V_189 ,
L_10 , V_4 ) ;
if ( F_59 ( V_89 ) ) {
F_19 ( V_6 -> V_8 , L_11 ,
V_29 -> V_124 , V_87 ) ;
V_29 -> V_124 = V_190 ;
}
F_63 ( & V_64 -> V_160 ) ;
V_64 -> V_157 = V_157 ;
return 0 ;
V_186:
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
if ( ! V_6 )
return;
V_94 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
F_32 ( 0 , V_94 + V_153 ) ;
if ( V_29 -> V_124 != V_190 ) {
V_87 = V_6 -> V_187 [ V_6 -> V_188 + V_29 -> V_124 ] ;
F_65 ( V_87 , V_4 ) ;
}
F_66 ( V_64 -> V_157 ) ;
F_28 ( V_6 -> V_178 , V_29 -> V_70 ) ;
}
static struct V_2 * F_67 ( unsigned type )
{
struct V_1 * V_64 ;
if ( type != V_191 )
return NULL ;
V_64 = F_68 ( sizeof( * V_64 ) , V_43 ) ;
if ( ! V_64 )
return NULL ;
F_69 ( & V_64 -> V_160 ) ;
F_70 ( & V_64 -> V_192 ) ;
return & V_64 -> V_4 ;
}
static void F_71 ( struct V_2 * V_4 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
F_64 ( V_4 ) ;
F_72 ( V_64 ) ;
}
static int F_73 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_7 ;
struct V_193 * V_194 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( ! ( V_6 -> V_47 & V_48 ) )
return 0 ;
if ( V_29 -> V_194 )
return - V_34 ;
V_194 = F_74 ( V_29 -> V_45 , sizeof( * V_194 ) , V_43 ) ;
if ( ! V_194 ) {
F_19 ( V_6 -> V_8 , L_12 ,
V_29 -> V_45 ) ;
return - V_44 ;
}
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
int V_56 = F_25 ( V_6 -> V_195 , 0 ,
V_6 -> V_49 ) ;
if ( F_59 ( V_56 ) ) {
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
T_5 V_77 = V_199 | V_194 [ V_7 ] . V_198 << V_200 |
V_194 [ V_7 ] . V_197 << V_201 ;
F_32 ( V_77 , V_58 + F_75 ( V_194 [ V_7 ] . V_56 ) ) ;
}
V_29 -> V_194 = V_194 ;
return 0 ;
V_196:
while ( -- V_7 >= 0 )
F_28 ( V_6 -> V_195 , V_194 [ V_7 ] . V_56 ) ;
F_72 ( V_194 ) ;
return - V_42 ;
}
static void F_76 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_7 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
struct V_193 * V_194 = V_29 -> V_194 ;
if ( ! V_194 )
return;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_6 V_56 = V_194 [ V_7 ] . V_56 ;
F_32 ( ~ V_199 , V_58 + F_75 ( V_56 ) ) ;
F_28 ( V_6 -> V_195 , V_56 ) ;
}
V_29 -> V_194 = NULL ;
F_72 ( V_194 ) ;
}
static int F_77 ( struct V_1 * V_64 ,
struct V_28 * V_29 )
{
int V_7 , V_89 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
V_89 = F_73 ( V_6 , V_29 ) ;
if ( V_89 )
return V_89 == - V_34 ? 0 : V_89 ;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_56 , V_202 ;
V_56 = V_29 -> V_194 ? V_29 -> V_194 [ V_7 ] . V_56 : V_29 -> V_51 [ V_7 ] ;
V_202 = V_203 |
( V_64 -> V_29 . V_70 << V_204 ) ;
F_32 ( V_202 , V_58 + F_78 ( V_56 ) ) ;
}
return 0 ;
}
static void F_79 ( struct V_1 * V_64 ,
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
V_58 + F_78 ( V_56 ) ) ;
}
F_76 ( V_6 , V_29 ) ;
}
static int F_80 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
int V_89 ;
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
V_89 = F_57 ( V_4 , V_6 ) ;
if ( F_59 ( V_89 ) )
return V_89 ;
if ( V_64 -> V_6 != V_6 ) {
F_19 ( V_8 ,
L_16 ,
F_81 ( V_64 -> V_6 -> V_8 ) , F_81 ( V_6 -> V_8 ) ) ;
return - V_177 ;
}
V_29 = F_11 ( V_8 ) ;
if ( ! V_29 )
return - V_209 ;
V_89 = F_77 ( V_64 , V_29 ) ;
if ( ! V_89 )
V_8 -> V_207 . V_208 = V_4 ;
return V_89 ;
}
static void F_82 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_28 * V_29 ;
V_29 = F_11 ( V_8 ) ;
if ( ! V_29 )
return;
V_8 -> V_207 . V_208 = NULL ;
F_79 ( V_64 , V_29 ) ;
}
static int F_83 ( struct V_2 * V_4 , unsigned long V_73 ,
T_7 V_210 , T_3 V_74 , int V_211 )
{
int V_89 ;
unsigned long V_88 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_156 * V_212 = V_64 -> V_157 ;
if ( ! V_212 )
return - V_209 ;
F_84 ( & V_64 -> V_192 , V_88 ) ;
V_89 = V_212 -> V_53 ( V_212 , V_73 , V_210 , V_74 , V_211 ) ;
F_85 ( & V_64 -> V_192 , V_88 ) ;
return V_89 ;
}
static T_3 F_86 ( struct V_2 * V_4 , unsigned long V_73 ,
T_3 V_74 )
{
T_3 V_89 ;
unsigned long V_88 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_156 * V_212 = V_64 -> V_157 ;
if ( ! V_212 )
return 0 ;
F_84 ( & V_64 -> V_192 , V_88 ) ;
V_89 = V_212 -> V_213 ( V_212 , V_73 , V_74 ) ;
F_85 ( & V_64 -> V_192 , V_88 ) ;
return V_89 ;
}
static T_7 F_87 ( struct V_2 * V_4 ,
T_8 V_73 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_64 -> V_6 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_156 * V_212 = V_64 -> V_157 ;
struct V_15 * V_8 = V_6 -> V_8 ;
void T_2 * V_94 ;
T_5 V_214 ;
V_83 V_215 ;
unsigned long V_216 ;
V_94 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_216 = V_73 & ~ 0xfffUL ;
if ( V_6 -> V_81 == V_84 )
F_55 ( V_216 , V_94 + V_217 ) ;
else
F_32 ( V_216 , V_94 + V_217 ) ;
if ( F_88 ( V_94 + V_218 , V_214 ,
! ( V_214 & V_219 ) , 5 , 50 ) ) {
F_19 ( V_8 ,
L_17 ,
& V_73 ) ;
return V_212 -> V_220 ( V_212 , V_73 ) ;
}
V_215 = F_33 ( V_94 + V_221 ) ;
V_215 |= ( ( V_83 ) F_33 ( V_94 + V_222 ) ) << 32 ;
if ( V_215 & V_223 ) {
F_19 ( V_8 , L_18 ) ;
F_19 ( V_8 , L_19 , V_215 ) ;
return 0 ;
}
return ( V_215 & F_89 ( 39 , 12 ) ) | ( V_73 & 0xfff ) ;
}
static T_7 F_90 ( struct V_2 * V_4 ,
T_8 V_73 )
{
T_7 V_89 ;
unsigned long V_88 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_156 * V_212 = V_64 -> V_157 ;
if ( ! V_212 )
return 0 ;
F_84 ( & V_64 -> V_192 , V_88 ) ;
if ( V_64 -> V_6 -> V_47 & V_224 &&
V_64 -> V_163 == V_166 ) {
V_89 = F_87 ( V_4 , V_73 ) ;
} else {
V_89 = V_212 -> V_220 ( V_212 , V_73 ) ;
}
F_85 ( & V_64 -> V_192 , V_88 ) ;
return V_89 ;
}
static bool F_91 ( enum V_225 V_226 )
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
static int F_92 ( struct V_230 * V_231 , T_1 V_232 , void * V_233 )
{
* ( ( T_1 * ) V_233 ) = V_232 ;
return 0 ;
}
static void F_93 ( void * V_233 )
{
F_72 ( V_233 ) ;
}
static int F_94 ( struct V_230 * V_231 ,
struct V_30 * V_31 )
{
struct V_28 * V_29 ;
T_1 V_234 ;
int V_7 ;
V_29 = F_13 ( V_31 ) ;
if ( ! V_29 ) {
V_29 = F_68 ( sizeof( * V_29 ) , V_43 ) ;
if ( ! V_29 )
return - V_44 ;
F_95 ( V_31 , V_29 ,
F_93 ) ;
}
if ( V_29 -> V_45 >= V_41 )
return - V_42 ;
F_96 ( V_231 , F_92 , & V_234 ) ;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 )
if ( V_29 -> V_51 [ V_7 ] == V_234 )
break;
if ( V_7 == V_29 -> V_45 )
V_29 -> V_51 [ V_29 -> V_45 ++ ] = V_234 ;
return 0 ;
}
static int F_97 ( struct V_15 * V_8 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = F_21 ( V_8 ) ;
struct V_20 * V_25 ;
if ( ! V_6 )
return - V_209 ;
V_25 = F_10 ( V_6 , V_8 -> V_9 ) ;
if ( ! V_25 )
return - V_209 ;
F_95 ( V_31 , & V_25 -> V_29 , NULL ) ;
return 0 ;
}
static int F_98 ( struct V_15 * V_8 )
{
struct V_30 * V_31 ;
V_31 = F_99 ( V_8 ) ;
if ( F_100 ( V_31 ) )
return F_101 ( V_31 ) ;
F_14 ( V_31 ) ;
return 0 ;
}
static void F_102 ( struct V_15 * V_8 )
{
F_103 ( V_8 ) ;
}
static struct V_30 * F_104 ( struct V_15 * V_8 )
{
struct V_30 * V_31 ;
int V_89 ;
if ( F_7 ( V_8 ) )
V_31 = F_105 ( V_8 ) ;
else
V_31 = F_106 ( V_8 ) ;
if ( F_100 ( V_31 ) )
return V_31 ;
if ( F_7 ( V_8 ) )
V_89 = F_94 ( F_8 ( V_8 ) , V_31 ) ;
else
V_89 = F_97 ( V_8 , V_31 ) ;
if ( V_89 ) {
F_14 ( V_31 ) ;
V_31 = F_107 ( V_89 ) ;
}
return V_31 ;
}
static int F_108 ( struct V_2 * V_4 ,
enum V_235 V_236 , void * V_233 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
switch ( V_236 ) {
case V_237 :
* ( int * ) V_233 = ( V_64 -> V_163 == V_173 ) ;
return 0 ;
default:
return - V_209 ;
}
}
static int F_109 ( struct V_2 * V_4 ,
enum V_235 V_236 , void * V_233 )
{
int V_89 = 0 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
F_58 ( & V_64 -> V_160 ) ;
switch ( V_236 ) {
case V_237 :
if ( V_64 -> V_6 ) {
V_89 = - V_238 ;
goto V_161;
}
if ( * ( int * ) V_233 )
V_64 -> V_163 = V_173 ;
else
V_64 -> V_163 = V_166 ;
break;
default:
V_89 = - V_209 ;
}
V_161:
F_63 ( & V_64 -> V_160 ) ;
return V_89 ;
}
static void F_110 ( struct V_5 * V_6 )
{
void T_2 * V_58 = F_31 ( V_6 ) ;
void T_2 * V_94 ;
int V_7 = 0 ;
T_5 V_77 ;
V_77 = F_33 ( F_50 ( V_6 ) + V_114 ) ;
F_48 ( V_77 , F_50 ( V_6 ) + V_114 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_49 ; ++ V_7 ) {
F_32 ( 0 , V_58 + F_75 ( V_7 ) ) ;
F_32 ( V_205 ,
V_58 + F_78 ( V_7 ) ) ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_179 ; ++ V_7 ) {
V_94 = F_39 ( V_6 ) + F_40 ( V_6 , V_7 ) ;
F_32 ( 0 , V_94 + V_153 ) ;
F_32 ( V_96 , V_94 + V_95 ) ;
}
F_32 ( 0 , V_58 + V_239 ) ;
F_32 ( 0 , V_58 + V_240 ) ;
V_77 = F_33 ( F_50 ( V_6 ) + V_241 ) ;
V_77 |= ( V_242 | V_243 | V_244 | V_245 ) ;
V_77 |= ( V_246 | V_247 ) ;
V_77 &= ~ ( V_248 | V_249 ) ;
V_77 &= ~ V_250 ;
V_77 &= ~ ( V_251 << V_252 ) ;
F_30 ( V_6 ) ;
F_48 ( V_77 , F_50 ( V_6 ) + V_241 ) ;
}
static int F_111 ( int V_74 )
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
static int F_112 ( struct V_5 * V_6 )
{
unsigned long V_74 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
T_5 V_198 ;
bool V_253 , V_254 ;
F_5 ( V_6 -> V_8 , L_20 ) ;
F_5 ( V_6 -> V_8 , L_21 , V_6 -> V_81 ) ;
V_198 = F_33 ( V_58 + V_255 ) ;
if ( V_256 == 1 )
V_198 &= ~ ( V_257 | V_258 ) ;
else if ( V_256 == 2 )
V_198 &= ~ ( V_259 | V_258 ) ;
if ( V_198 & V_259 ) {
V_6 -> V_47 |= V_162 ;
F_5 ( V_6 -> V_8 , L_22 ) ;
}
if ( V_198 & V_257 ) {
V_6 -> V_47 |= V_165 ;
F_5 ( V_6 -> V_8 , L_23 ) ;
}
if ( V_198 & V_258 ) {
V_6 -> V_47 |= V_260 ;
F_5 ( V_6 -> V_8 , L_24 ) ;
}
if ( ! ( V_6 -> V_47 &
( V_162 | V_165 ) ) ) {
F_19 ( V_6 -> V_8 , L_25 ) ;
return - V_209 ;
}
if ( ( V_198 & V_259 ) && ( ( V_6 -> V_81 == 1 ) || ! ( V_198 & V_261 ) ) ) {
V_6 -> V_47 |= V_224 ;
F_5 ( V_6 -> V_8 , L_26 ) ;
}
V_253 = F_113 ( V_6 -> V_8 -> V_9 ) ;
V_254 = ! ! ( V_198 & V_262 ) ;
if ( V_253 )
V_6 -> V_47 |= V_263 ;
if ( V_253 || V_254 )
F_5 ( V_6 -> V_8 , L_27 ,
V_253 ? L_28 : L_29 ) ;
if ( V_253 != V_254 )
F_5 ( V_6 -> V_8 ,
L_30 ) ;
if ( V_198 & V_264 ) {
T_5 V_265 , V_234 , V_197 ;
V_6 -> V_47 |= V_48 ;
V_6 -> V_49 = ( V_198 >> V_266 ) &
V_267 ;
if ( V_6 -> V_49 == 0 ) {
F_19 ( V_6 -> V_8 ,
L_31 ) ;
return - V_209 ;
}
V_265 = V_268 << V_201 ;
V_265 |= ( V_269 << V_200 ) ;
F_32 ( V_265 , V_58 + F_75 ( 0 ) ) ;
V_265 = F_33 ( V_58 + F_75 ( 0 ) ) ;
V_197 = ( V_265 >> V_201 ) & V_268 ;
V_234 = ( V_265 >> V_200 ) & V_269 ;
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
V_6 -> V_49 = ( V_198 >> V_270 ) &
V_271 ;
}
V_198 = F_33 ( V_58 + V_272 ) ;
V_6 -> V_273 = ( V_198 & V_274 ) ? 16 : 12 ;
V_74 = 1 << ( ( ( V_198 >> V_275 ) & V_276 ) + 1 ) ;
V_74 *= 2 << V_6 -> V_273 ;
if ( V_6 -> V_74 != V_74 )
F_114 ( V_6 -> V_8 ,
L_34 ,
V_74 , V_6 -> V_74 ) ;
V_6 -> V_168 = ( V_198 >> V_277 ) & V_278 ;
V_6 -> V_179 = ( V_198 >> V_279 ) & V_280 ;
if ( V_6 -> V_168 > V_6 -> V_179 ) {
F_19 ( V_6 -> V_8 , L_35 ) ;
return - V_209 ;
}
F_5 ( V_6 -> V_8 , L_36 ,
V_6 -> V_179 , V_6 -> V_168 ) ;
V_198 = F_33 ( V_58 + V_281 ) ;
V_74 = F_111 ( ( V_198 >> V_282 ) & V_283 ) ;
V_6 -> V_170 = V_74 ;
V_74 = F_111 ( ( V_198 >> V_284 ) & V_285 ) ;
V_6 -> V_174 = V_74 ;
if ( F_115 ( V_6 -> V_8 , F_116 ( V_74 ) ) )
F_114 ( V_6 -> V_8 ,
L_37 ) ;
if ( V_6 -> V_81 == V_82 ) {
V_6 -> V_169 = V_6 -> V_170 ;
V_74 = V_286 | V_287 | V_288 ;
} else {
V_74 = ( V_198 >> V_289 ) & V_290 ;
V_6 -> V_169 = F_111 ( V_74 ) ;
#ifndef V_80
V_6 -> V_169 = F_117 ( 32UL , V_6 -> V_169 ) ;
#endif
V_74 = 0 ;
if ( V_198 & V_291 )
V_74 |= V_286 | V_287 | V_288 ;
if ( V_198 & V_292 )
V_74 |= V_293 | V_294 ;
if ( V_198 & V_295 )
V_74 |= V_296 | V_297 ;
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
static int F_118 ( struct V_298 * V_231 )
{
const struct V_299 * V_300 ;
struct V_301 * V_302 ;
struct V_5 * V_6 ;
struct V_15 * V_8 = & V_231 -> V_8 ;
struct V_22 * V_23 ;
struct V_35 V_36 ;
int V_303 , V_7 , V_304 ;
V_6 = F_20 ( V_8 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 ) {
F_19 ( V_8 , L_41 ) ;
return - V_44 ;
}
V_6 -> V_8 = V_8 ;
V_300 = F_119 ( V_305 , V_8 -> V_9 ) ;
V_6 -> V_81 = (enum V_306 ) V_300 -> V_233 ;
V_302 = F_120 ( V_231 , V_307 , 0 ) ;
V_6 -> V_69 = F_121 ( V_8 , V_302 ) ;
if ( F_100 ( V_6 -> V_69 ) )
return F_101 ( V_6 -> V_69 ) ;
V_6 -> V_74 = F_122 ( V_302 ) ;
if ( F_123 ( V_8 -> V_9 , L_42 ,
& V_6 -> V_188 ) ) {
F_19 ( V_8 , L_43 ) ;
return - V_209 ;
}
V_303 = 0 ;
while ( ( V_302 = F_120 ( V_231 , V_308 , V_303 ) ) ) {
V_303 ++ ;
if ( V_303 > V_6 -> V_188 )
V_6 -> V_180 ++ ;
}
if ( ! V_6 -> V_180 ) {
F_19 ( V_8 , L_44 ,
V_303 , V_6 -> V_188 + 1 ) ;
return - V_209 ;
}
V_6 -> V_187 = F_20 ( V_8 , sizeof( * V_6 -> V_187 ) * V_303 ,
V_43 ) ;
if ( ! V_6 -> V_187 ) {
F_19 ( V_8 , L_45 , V_303 ) ;
return - V_44 ;
}
for ( V_7 = 0 ; V_7 < V_303 ; ++ V_7 ) {
int V_87 = F_124 ( V_231 , V_7 ) ;
if ( V_87 < 0 ) {
F_19 ( V_8 , L_46 , V_7 ) ;
return - V_209 ;
}
V_6 -> V_187 [ V_7 ] = V_87 ;
}
V_304 = F_112 ( V_6 ) ;
if ( V_304 )
return V_304 ;
V_7 = 0 ;
V_6 -> V_24 = V_309 ;
while ( ! F_125 ( V_8 -> V_9 , L_47 ,
L_48 , V_7 ,
& V_36 ) ) {
V_304 = F_18 ( V_6 , V_8 , & V_36 ) ;
if ( V_304 ) {
F_19 ( V_8 , L_49 ,
V_36 . V_37 -> V_38 ) ;
goto V_310;
}
V_7 ++ ;
}
F_5 ( V_8 , L_50 , V_7 ) ;
F_3 ( V_6 ) ;
if ( V_6 -> V_81 > V_82 &&
V_6 -> V_179 != V_6 -> V_180 ) {
F_19 ( V_8 ,
L_51 ,
V_6 -> V_180 , V_6 -> V_179 ) ;
V_304 = - V_209 ;
goto V_310;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_188 ; ++ V_7 ) {
V_304 = F_62 ( V_6 -> V_187 [ V_7 ] ,
F_49 ,
V_189 ,
L_52 ,
V_6 ) ;
if ( V_304 ) {
F_19 ( V_8 , L_53 ,
V_7 , V_6 -> V_187 [ V_7 ] ) ;
goto V_311;
}
}
F_126 ( & V_6 -> V_312 ) ;
F_22 ( & V_52 ) ;
F_127 ( & V_6 -> V_312 , & V_313 ) ;
F_24 ( & V_52 ) ;
F_110 ( V_6 ) ;
return 0 ;
V_311:
while ( V_7 -- )
F_65 ( V_6 -> V_187 [ V_7 ] , V_6 ) ;
V_310:
for ( V_23 = F_128 ( & V_6 -> V_24 ) ; V_23 ; V_23 = F_129 ( V_23 ) ) {
struct V_20 * V_25
= F_2 ( V_23 , struct V_20 , V_23 ) ;
F_130 ( V_25 -> V_9 ) ;
}
return V_304 ;
}
static int F_131 ( struct V_298 * V_231 )
{
int V_7 ;
struct V_15 * V_8 = & V_231 -> V_8 ;
struct V_5 * V_314 , * V_6 = NULL ;
struct V_22 * V_23 ;
F_22 ( & V_52 ) ;
F_23 (curr, &arm_smmu_devices, list) {
if ( V_314 -> V_8 == V_8 ) {
V_6 = V_314 ;
F_132 ( & V_6 -> V_312 ) ;
break;
}
}
F_24 ( & V_52 ) ;
if ( ! V_6 )
return - V_209 ;
for ( V_23 = F_128 ( & V_6 -> V_24 ) ; V_23 ; V_23 = F_129 ( V_23 ) ) {
struct V_20 * V_25
= F_2 ( V_23 , struct V_20 , V_23 ) ;
F_130 ( V_25 -> V_9 ) ;
}
if ( ! F_133 ( V_6 -> V_178 , V_315 ) )
F_19 ( V_8 , L_54 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_188 ; ++ V_7 )
F_65 ( V_6 -> V_187 [ V_7 ] , V_6 ) ;
F_48 ( V_248 , F_50 ( V_6 ) + V_241 ) ;
return 0 ;
}
static int T_9 F_134 ( void )
{
struct V_14 * V_37 ;
int V_89 ;
V_37 = F_135 ( NULL , V_305 ) ;
if ( ! V_37 )
return 0 ;
F_130 ( V_37 ) ;
V_89 = F_136 ( & V_316 ) ;
if ( V_89 )
return V_89 ;
if ( ! F_137 ( & V_317 ) )
F_138 ( & V_317 , & V_182 ) ;
#ifdef F_139
if ( ! F_137 ( & V_318 ) )
F_138 ( & V_318 , & V_182 ) ;
#endif
#ifdef F_140
if ( ! F_137 ( & V_319 ) )
F_138 ( & V_319 , & V_182 ) ;
#endif
return 0 ;
}
static void T_10 F_141 ( void )
{
return F_142 ( & V_316 ) ;
}

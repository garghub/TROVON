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
static void F_46 ( void * V_86 , T_3 V_74 , void * V_63 )
{
struct V_1 * V_64 = V_63 ;
struct V_5 * V_6 = V_64 -> V_6 ;
unsigned long V_87 = ( unsigned long ) V_86 & ~ V_88 ;
if ( V_6 -> V_47 & V_89 ) {
F_47 ( V_90 ) ;
} else {
F_48 ( V_6 -> V_8 , F_49 ( V_86 ) , V_87 , V_74 ,
V_91 ) ;
}
}
static T_4 F_50 ( int V_92 , void * V_8 )
{
int V_93 , V_94 ;
T_5 V_95 , V_96 , V_97 , V_98 ;
unsigned long V_73 ;
struct V_2 * V_4 = V_8 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_99 ;
V_99 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_95 = F_33 ( V_99 + V_100 ) ;
if ( ! ( V_95 & V_101 ) )
return V_102 ;
if ( V_95 & V_103 )
F_35 ( V_6 -> V_8 ,
L_6 ,
V_95 ) ;
V_97 = F_33 ( V_99 + V_104 ) ;
V_93 = V_97 & V_105 ? V_106 : V_107 ;
V_96 = F_33 ( V_99 + V_108 ) ;
V_73 = V_96 ;
#ifdef V_79
V_96 = F_33 ( V_99 + V_109 ) ;
V_73 |= ( ( unsigned long ) V_96 << 32 ) ;
#endif
if ( ! F_51 ( V_4 , V_6 -> V_8 , V_73 , V_93 ) ) {
V_94 = V_110 ;
V_98 = V_111 ;
} else {
F_35 ( V_6 -> V_8 ,
L_7 ,
V_73 , V_97 , V_29 -> V_70 ) ;
V_94 = V_102 ;
V_98 = V_112 ;
}
F_52 ( V_95 , V_99 + V_100 ) ;
if ( V_95 & V_113 )
F_32 ( V_98 , V_99 + V_114 ) ;
return V_94 ;
}
static T_4 F_53 ( int V_92 , void * V_8 )
{
T_5 V_115 , V_116 , V_117 , V_118 ;
struct V_5 * V_6 = V_8 ;
void T_2 * V_58 = F_54 ( V_6 ) ;
V_115 = F_33 ( V_58 + V_119 ) ;
V_116 = F_33 ( V_58 + V_120 ) ;
V_117 = F_33 ( V_58 + V_121 ) ;
V_118 = F_33 ( V_58 + V_122 ) ;
if ( ! V_115 )
return V_102 ;
F_35 ( V_6 -> V_8 ,
L_8 ) ;
F_35 ( V_6 -> V_8 ,
L_9 ,
V_115 , V_116 , V_117 , V_118 ) ;
F_52 ( V_115 , V_58 + V_119 ) ;
return V_110 ;
}
static void F_55 ( struct V_1 * V_64 ,
struct V_123 * V_124 )
{
T_5 V_76 ;
bool V_66 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_99 , * V_58 , * V_125 ;
V_58 = F_31 ( V_6 ) ;
V_125 = F_56 ( V_6 ) ;
V_66 = V_29 -> V_67 != V_68 ;
V_99 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
if ( V_6 -> V_80 > V_81 ) {
#ifdef V_79
V_76 = V_126 ;
#else
V_76 = V_127 ;
#endif
F_32 ( V_76 , V_125 + F_57 ( V_29 -> V_70 ) ) ;
}
V_76 = V_29 -> V_67 ;
if ( V_6 -> V_80 == V_81 )
V_76 |= V_29 -> V_128 << V_129 ;
if ( V_66 ) {
V_76 |= ( V_130 << V_131 ) |
( V_132 << V_133 ) ;
} else {
V_76 |= F_42 ( V_29 ) << V_134 ;
}
F_32 ( V_76 , V_125 + F_58 ( V_29 -> V_70 ) ) ;
if ( V_66 ) {
V_76 = V_124 -> V_135 . V_136 [ 0 ] ;
F_32 ( V_76 , V_99 + V_137 ) ;
V_76 = V_124 -> V_135 . V_136 [ 0 ] >> 32 ;
V_76 |= F_41 ( V_29 ) << V_138 ;
F_32 ( V_76 , V_99 + V_139 ) ;
V_76 = V_124 -> V_135 . V_136 [ 1 ] ;
F_32 ( V_76 , V_99 + V_140 ) ;
V_76 = V_124 -> V_135 . V_136 [ 1 ] >> 32 ;
V_76 |= F_41 ( V_29 ) << V_138 ;
F_32 ( V_76 , V_99 + V_141 ) ;
} else {
V_76 = V_124 -> V_142 . V_143 ;
F_32 ( V_76 , V_99 + V_137 ) ;
V_76 = V_124 -> V_142 . V_143 >> 32 ;
F_32 ( V_76 , V_99 + V_139 ) ;
}
if ( V_66 ) {
V_76 = V_124 -> V_135 . V_144 ;
F_32 ( V_76 , V_99 + V_145 ) ;
if ( V_6 -> V_80 > V_81 ) {
V_76 = V_124 -> V_135 . V_144 >> 32 ;
V_76 |= V_146 ;
F_32 ( V_76 , V_99 + V_147 ) ;
}
} else {
V_76 = V_124 -> V_142 . V_148 ;
F_32 ( V_76 , V_99 + V_145 ) ;
}
if ( V_66 ) {
V_76 = V_124 -> V_135 . V_149 [ 0 ] ;
F_32 ( V_76 , V_99 + V_150 ) ;
V_76 = V_124 -> V_135 . V_149 [ 1 ] ;
F_32 ( V_76 , V_99 + V_151 ) ;
}
V_76 = V_152 | V_153 | V_154 | V_155 | V_156 ;
if ( V_66 )
V_76 |= V_157 ;
#ifdef F_59
V_76 |= V_158 ;
#endif
F_32 ( V_76 , V_99 + V_159 ) ;
}
static int F_60 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
int V_92 , V_54 , V_94 = 0 ;
unsigned long V_160 , V_161 ;
struct V_162 * V_163 ;
struct V_123 V_124 ;
enum V_164 V_165 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_65 * V_29 = & V_64 -> V_29 ;
F_61 ( & V_64 -> V_166 ) ;
if ( V_64 -> V_6 )
goto V_167;
if ( ! ( V_6 -> V_47 & V_168 ) )
V_64 -> V_169 = V_170 ;
if ( ! ( V_6 -> V_47 & V_171 ) )
V_64 -> V_169 = V_172 ;
switch ( V_64 -> V_169 ) {
case V_172 :
V_29 -> V_67 = V_173 ;
V_54 = V_6 -> V_174 ;
V_160 = V_6 -> V_175 ;
V_161 = V_6 -> V_176 ;
if ( F_44 ( V_79 ) )
V_165 = V_177 ;
else
V_165 = V_178 ;
break;
case V_179 :
case V_170 :
V_29 -> V_67 = V_68 ;
V_54 = 0 ;
V_160 = V_6 -> V_176 ;
V_161 = V_6 -> V_180 ;
if ( F_44 ( V_79 ) )
V_165 = V_181 ;
else
V_165 = V_182 ;
break;
default:
V_94 = - V_183 ;
goto V_167;
}
V_94 = F_25 ( V_6 -> V_184 , V_54 ,
V_6 -> V_185 ) ;
if ( F_62 ( V_94 ) )
goto V_167;
V_29 -> V_70 = V_94 ;
if ( V_6 -> V_80 == V_81 ) {
V_29 -> V_128 = F_63 ( & V_6 -> V_128 ) ;
V_29 -> V_128 %= V_6 -> V_186 ;
} else {
V_29 -> V_128 = V_29 -> V_70 ;
}
V_124 = (struct V_123 ) {
. V_187 = V_188 . V_187 ,
. V_160 = V_160 ,
. V_161 = V_161 ,
. V_189 = & V_190 ,
} ;
V_64 -> V_6 = V_6 ;
V_163 = F_64 ( V_165 , & V_124 , V_64 ) ;
if ( ! V_163 ) {
V_94 = - V_44 ;
goto V_191;
}
V_188 . V_187 = V_124 . V_187 ;
F_55 ( V_64 , & V_124 ) ;
V_92 = V_6 -> V_192 [ V_6 -> V_193 + V_29 -> V_128 ] ;
V_94 = F_65 ( V_92 , F_50 , V_194 ,
L_10 , V_4 ) ;
if ( F_62 ( V_94 ) ) {
F_19 ( V_6 -> V_8 , L_11 ,
V_29 -> V_128 , V_92 ) ;
V_29 -> V_128 = V_195 ;
}
F_66 ( & V_64 -> V_166 ) ;
V_64 -> V_163 = V_163 ;
return 0 ;
V_191:
V_64 -> V_6 = NULL ;
V_167:
F_66 ( & V_64 -> V_166 ) ;
return V_94 ;
}
static void F_67 ( struct V_2 * V_4 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_64 -> V_6 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
void T_2 * V_99 ;
int V_92 ;
if ( ! V_6 )
return;
V_99 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
F_32 ( 0 , V_99 + V_159 ) ;
if ( V_29 -> V_128 != V_195 ) {
V_92 = V_6 -> V_192 [ V_6 -> V_193 + V_29 -> V_128 ] ;
F_68 ( V_92 , V_4 ) ;
}
if ( V_64 -> V_163 )
F_69 ( V_64 -> V_163 ) ;
F_28 ( V_6 -> V_184 , V_29 -> V_70 ) ;
}
static struct V_2 * F_70 ( unsigned type )
{
struct V_1 * V_64 ;
if ( type != V_196 )
return NULL ;
V_64 = F_71 ( sizeof( * V_64 ) , V_43 ) ;
if ( ! V_64 )
return NULL ;
F_72 ( & V_64 -> V_166 ) ;
F_73 ( & V_64 -> V_197 ) ;
return & V_64 -> V_4 ;
}
static void F_74 ( struct V_2 * V_4 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
F_67 ( V_4 ) ;
F_75 ( V_64 ) ;
}
static int F_76 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_7 ;
struct V_198 * V_199 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( ! ( V_6 -> V_47 & V_48 ) )
return 0 ;
if ( V_29 -> V_199 )
return - V_34 ;
V_199 = F_77 ( V_29 -> V_45 , sizeof( * V_199 ) , V_43 ) ;
if ( ! V_199 ) {
F_19 ( V_6 -> V_8 , L_12 ,
V_29 -> V_45 ) ;
return - V_44 ;
}
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
int V_56 = F_25 ( V_6 -> V_200 , 0 ,
V_6 -> V_49 ) ;
if ( F_62 ( V_56 ) ) {
F_19 ( V_6 -> V_8 , L_13 ) ;
goto V_201;
}
V_199 [ V_7 ] = (struct V_198 ) {
. V_56 = V_56 ,
. V_202 = 0 ,
. V_203 = V_29 -> V_51 [ V_7 ] ,
} ;
}
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_76 = V_204 | V_199 [ V_7 ] . V_203 << V_205 |
V_199 [ V_7 ] . V_202 << V_206 ;
F_32 ( V_76 , V_58 + F_78 ( V_199 [ V_7 ] . V_56 ) ) ;
}
V_29 -> V_199 = V_199 ;
return 0 ;
V_201:
while ( -- V_7 >= 0 )
F_28 ( V_6 -> V_200 , V_199 [ V_7 ] . V_56 ) ;
F_75 ( V_199 ) ;
return - V_42 ;
}
static void F_79 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_7 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
struct V_198 * V_199 = V_29 -> V_199 ;
if ( ! V_199 )
return;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_6 V_56 = V_199 [ V_7 ] . V_56 ;
F_32 ( ~ V_204 , V_58 + F_78 ( V_56 ) ) ;
F_28 ( V_6 -> V_200 , V_56 ) ;
}
V_29 -> V_199 = NULL ;
F_75 ( V_199 ) ;
}
static int F_80 ( struct V_1 * V_64 ,
struct V_28 * V_29 )
{
int V_7 , V_94 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
V_94 = F_76 ( V_6 , V_29 ) ;
if ( V_94 )
return V_94 == - V_34 ? 0 : V_94 ;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_56 , V_207 ;
V_56 = V_29 -> V_199 ? V_29 -> V_199 [ V_7 ] . V_56 : V_29 -> V_51 [ V_7 ] ;
V_207 = V_208 |
( V_64 -> V_29 . V_70 << V_209 ) ;
F_32 ( V_207 , V_58 + F_81 ( V_56 ) ) ;
}
return 0 ;
}
static void F_82 ( struct V_1 * V_64 ,
struct V_28 * V_29 )
{
int V_7 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( ( V_6 -> V_47 & V_48 ) && ! V_29 -> V_199 )
return;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_56 = V_29 -> V_199 ? V_29 -> V_199 [ V_7 ] . V_56 : V_29 -> V_51 [ V_7 ] ;
F_32 ( V_210 ,
V_58 + F_81 ( V_56 ) ) ;
}
F_79 ( V_6 , V_29 ) ;
}
static int F_83 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
int V_94 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 ;
struct V_28 * V_29 ;
V_6 = F_21 ( V_8 ) ;
if ( ! V_6 ) {
F_19 ( V_8 , L_14 ) ;
return - V_211 ;
}
if ( V_8 -> V_212 . V_213 ) {
F_19 ( V_8 , L_15 ) ;
return - V_34 ;
}
V_94 = F_60 ( V_4 , V_6 ) ;
if ( F_62 ( V_94 ) )
return V_94 ;
if ( V_64 -> V_6 != V_6 ) {
F_19 ( V_8 ,
L_16 ,
F_84 ( V_64 -> V_6 -> V_8 ) , F_84 ( V_6 -> V_8 ) ) ;
return - V_183 ;
}
V_29 = F_11 ( V_8 ) ;
if ( ! V_29 )
return - V_214 ;
V_94 = F_80 ( V_64 , V_29 ) ;
if ( ! V_94 )
V_8 -> V_212 . V_213 = V_4 ;
return V_94 ;
}
static void F_85 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_28 * V_29 ;
V_29 = F_11 ( V_8 ) ;
if ( ! V_29 )
return;
V_8 -> V_212 . V_213 = NULL ;
F_82 ( V_64 , V_29 ) ;
}
static int F_86 ( struct V_2 * V_4 , unsigned long V_73 ,
T_7 V_215 , T_3 V_74 , int V_216 )
{
int V_94 ;
unsigned long V_93 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_162 * V_217 = V_64 -> V_163 ;
if ( ! V_217 )
return - V_214 ;
F_87 ( & V_64 -> V_197 , V_93 ) ;
V_94 = V_217 -> V_53 ( V_217 , V_73 , V_215 , V_74 , V_216 ) ;
F_88 ( & V_64 -> V_197 , V_93 ) ;
return V_94 ;
}
static T_3 F_89 ( struct V_2 * V_4 , unsigned long V_73 ,
T_3 V_74 )
{
T_3 V_94 ;
unsigned long V_93 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_162 * V_217 = V_64 -> V_163 ;
if ( ! V_217 )
return 0 ;
F_87 ( & V_64 -> V_197 , V_93 ) ;
V_94 = V_217 -> V_218 ( V_217 , V_73 , V_74 ) ;
F_88 ( & V_64 -> V_197 , V_93 ) ;
return V_94 ;
}
static T_7 F_90 ( struct V_2 * V_4 ,
T_8 V_73 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_64 -> V_6 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_162 * V_217 = V_64 -> V_163 ;
struct V_15 * V_8 = V_6 -> V_8 ;
void T_2 * V_99 ;
T_5 V_219 ;
V_82 V_220 ;
V_99 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
if ( V_6 -> V_80 == 1 ) {
T_5 V_76 = V_73 & ~ 0xfff ;
F_32 ( V_76 , V_99 + V_221 ) ;
} else {
T_5 V_76 = V_73 & ~ 0xfff ;
F_32 ( V_76 , V_99 + V_221 ) ;
V_76 = ( ( V_82 ) V_73 & ~ 0xfff ) >> 32 ;
F_32 ( V_76 , V_99 + V_222 ) ;
}
if ( F_91 ( V_99 + V_223 , V_219 ,
! ( V_219 & V_224 ) , 5 , 50 ) ) {
F_19 ( V_8 ,
L_17 ,
& V_73 ) ;
return V_217 -> V_225 ( V_217 , V_73 ) ;
}
V_220 = F_33 ( V_99 + V_226 ) ;
V_220 |= ( ( V_82 ) F_33 ( V_99 + V_227 ) ) << 32 ;
if ( V_220 & V_228 ) {
F_19 ( V_8 , L_18 ) ;
F_19 ( V_8 , L_19 , V_220 ) ;
return 0 ;
}
return ( V_220 & F_92 ( 39 , 12 ) ) | ( V_73 & 0xfff ) ;
}
static T_7 F_93 ( struct V_2 * V_4 ,
T_8 V_73 )
{
T_7 V_94 ;
unsigned long V_93 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_162 * V_217 = V_64 -> V_163 ;
if ( ! V_217 )
return 0 ;
F_87 ( & V_64 -> V_197 , V_93 ) ;
if ( V_64 -> V_6 -> V_47 & V_229 &&
V_64 -> V_169 == V_172 ) {
V_94 = F_90 ( V_4 , V_73 ) ;
} else {
V_94 = V_217 -> V_225 ( V_217 , V_73 ) ;
}
F_88 ( & V_64 -> V_197 , V_93 ) ;
return V_94 ;
}
static bool F_94 ( enum V_230 V_231 )
{
switch ( V_231 ) {
case V_232 :
return true ;
case V_233 :
return true ;
case V_234 :
return true ;
default:
return false ;
}
}
static int F_95 ( struct V_235 * V_236 , T_1 V_237 , void * V_238 )
{
* ( ( T_1 * ) V_238 ) = V_237 ;
return 0 ;
}
static void F_96 ( void * V_238 )
{
F_75 ( V_238 ) ;
}
static int F_97 ( struct V_235 * V_236 )
{
int V_7 , V_94 ;
T_1 V_239 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
V_31 = F_98 ( & V_236 -> V_8 ) ;
if ( F_99 ( V_31 ) )
return F_100 ( V_31 ) ;
V_29 = F_13 ( V_31 ) ;
if ( ! V_29 ) {
V_29 = F_71 ( sizeof( * V_29 ) , V_43 ) ;
if ( ! V_29 ) {
V_94 = - V_44 ;
goto V_240;
}
F_101 ( V_31 , V_29 ,
F_96 ) ;
}
if ( V_29 -> V_45 >= V_41 ) {
V_94 = - V_42 ;
goto V_240;
}
F_102 ( V_236 , F_95 , & V_239 ) ;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 )
if ( V_29 -> V_51 [ V_7 ] == V_239 )
break;
if ( V_7 == V_29 -> V_45 )
V_29 -> V_51 [ V_29 -> V_45 ++ ] = V_239 ;
return 0 ;
V_240:
F_14 ( V_31 ) ;
return V_94 ;
}
static int F_103 ( struct V_15 * V_8 )
{
struct V_30 * V_31 ;
struct V_20 * V_25 ;
struct V_5 * V_6 = F_21 ( V_8 ) ;
if ( ! V_6 )
return - V_214 ;
V_25 = F_10 ( V_6 , V_8 -> V_9 ) ;
if ( ! V_25 )
return - V_214 ;
V_31 = F_104 () ;
if ( F_99 ( V_31 ) )
return F_100 ( V_31 ) ;
F_101 ( V_31 , & V_25 -> V_29 , NULL ) ;
return F_105 ( V_31 , V_8 ) ;
}
static int F_106 ( struct V_15 * V_8 )
{
if ( F_7 ( V_8 ) )
return F_97 ( F_8 ( V_8 ) ) ;
return F_103 ( V_8 ) ;
}
static void F_107 ( struct V_15 * V_8 )
{
F_108 ( V_8 ) ;
}
static int F_109 ( struct V_2 * V_4 ,
enum V_241 V_242 , void * V_238 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
switch ( V_242 ) {
case V_243 :
* ( int * ) V_238 = ( V_64 -> V_169 == V_179 ) ;
return 0 ;
default:
return - V_214 ;
}
}
static int F_110 ( struct V_2 * V_4 ,
enum V_241 V_242 , void * V_238 )
{
int V_94 = 0 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
F_61 ( & V_64 -> V_166 ) ;
switch ( V_242 ) {
case V_243 :
if ( V_64 -> V_6 ) {
V_94 = - V_244 ;
goto V_167;
}
if ( * ( int * ) V_238 )
V_64 -> V_169 = V_179 ;
else
V_64 -> V_169 = V_172 ;
break;
default:
V_94 = - V_214 ;
}
V_167:
F_66 ( & V_64 -> V_166 ) ;
return V_94 ;
}
static void F_111 ( struct V_5 * V_6 )
{
void T_2 * V_58 = F_31 ( V_6 ) ;
void T_2 * V_99 ;
int V_7 = 0 ;
T_5 V_76 ;
V_76 = F_33 ( F_54 ( V_6 ) + V_119 ) ;
F_52 ( V_76 , F_54 ( V_6 ) + V_119 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_49 ; ++ V_7 ) {
F_32 ( 0 , V_58 + F_78 ( V_7 ) ) ;
F_32 ( V_210 ,
V_58 + F_81 ( V_7 ) ) ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_185 ; ++ V_7 ) {
V_99 = F_39 ( V_6 ) + F_40 ( V_6 , V_7 ) ;
F_32 ( 0 , V_99 + V_159 ) ;
F_32 ( V_101 , V_99 + V_100 ) ;
}
F_32 ( 0 , V_58 + V_245 ) ;
F_32 ( 0 , V_58 + V_246 ) ;
V_76 = F_33 ( F_54 ( V_6 ) + V_247 ) ;
V_76 |= ( V_248 | V_249 | V_250 | V_251 ) ;
V_76 |= ( V_252 | V_253 ) ;
V_76 &= ~ ( V_254 | V_255 ) ;
V_76 &= ~ V_256 ;
V_76 &= ~ ( V_257 << V_258 ) ;
F_30 ( V_6 ) ;
F_52 ( V_76 , F_54 ( V_6 ) + V_247 ) ;
}
static int F_112 ( int V_74 )
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
static int F_113 ( struct V_5 * V_6 )
{
unsigned long V_74 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
T_5 V_203 ;
F_5 ( V_6 -> V_8 , L_20 ) ;
F_5 ( V_6 -> V_8 , L_21 , V_6 -> V_80 ) ;
V_203 = F_33 ( V_58 + V_259 ) ;
if ( V_260 == 1 )
V_203 &= ~ ( V_261 | V_262 ) ;
else if ( V_260 == 2 )
V_203 &= ~ ( V_263 | V_262 ) ;
if ( V_203 & V_263 ) {
V_6 -> V_47 |= V_168 ;
F_5 ( V_6 -> V_8 , L_22 ) ;
}
if ( V_203 & V_261 ) {
V_6 -> V_47 |= V_171 ;
F_5 ( V_6 -> V_8 , L_23 ) ;
}
if ( V_203 & V_262 ) {
V_6 -> V_47 |= V_264 ;
F_5 ( V_6 -> V_8 , L_24 ) ;
}
if ( ! ( V_6 -> V_47 &
( V_168 | V_171 ) ) ) {
F_19 ( V_6 -> V_8 , L_25 ) ;
return - V_214 ;
}
if ( ( V_203 & V_263 ) && ( ( V_6 -> V_80 == 1 ) || ( V_203 & V_265 ) ) ) {
V_6 -> V_47 |= V_229 ;
F_5 ( V_6 -> V_8 , L_26 ) ;
}
if ( V_203 & V_266 ) {
V_6 -> V_47 |= V_89 ;
F_5 ( V_6 -> V_8 , L_27 ) ;
}
if ( V_203 & V_267 ) {
T_5 V_268 , V_239 , V_202 ;
V_6 -> V_47 |= V_48 ;
V_6 -> V_49 = ( V_203 >> V_269 ) &
V_270 ;
if ( V_6 -> V_49 == 0 ) {
F_19 ( V_6 -> V_8 ,
L_28 ) ;
return - V_214 ;
}
V_268 = V_271 << V_206 ;
V_268 |= ( V_272 << V_205 ) ;
F_32 ( V_268 , V_58 + F_78 ( 0 ) ) ;
V_268 = F_33 ( V_58 + F_78 ( 0 ) ) ;
V_202 = ( V_268 >> V_206 ) & V_271 ;
V_239 = ( V_268 >> V_205 ) & V_272 ;
if ( ( V_202 & V_239 ) != V_239 ) {
F_19 ( V_6 -> V_8 ,
L_29 ,
V_202 , V_239 ) ;
return - V_214 ;
}
F_5 ( V_6 -> V_8 ,
L_30 ,
V_6 -> V_49 , V_202 ) ;
} else {
V_6 -> V_49 = ( V_203 >> V_273 ) &
V_274 ;
}
V_203 = F_33 ( V_58 + V_275 ) ;
V_6 -> V_276 = ( V_203 & V_277 ) ? 16 : 12 ;
V_74 = 1 << ( ( ( V_203 >> V_278 ) & V_279 ) + 1 ) ;
V_74 *= 2 << V_6 -> V_276 ;
if ( V_6 -> V_74 != V_74 )
F_114 ( V_6 -> V_8 ,
L_31 ,
V_74 , V_6 -> V_74 ) ;
V_6 -> V_174 = ( V_203 >> V_280 ) & V_281 ;
V_6 -> V_185 = ( V_203 >> V_282 ) & V_283 ;
if ( V_6 -> V_174 > V_6 -> V_185 ) {
F_19 ( V_6 -> V_8 , L_32 ) ;
return - V_214 ;
}
F_5 ( V_6 -> V_8 , L_33 ,
V_6 -> V_185 , V_6 -> V_174 ) ;
V_203 = F_33 ( V_58 + V_284 ) ;
V_74 = F_112 ( ( V_203 >> V_285 ) & V_286 ) ;
V_6 -> V_176 = V_74 ;
V_74 = F_112 ( ( V_203 >> V_287 ) & V_288 ) ;
V_6 -> V_180 = V_74 ;
if ( F_115 ( V_6 -> V_8 , F_116 ( V_74 ) ) )
F_114 ( V_6 -> V_8 ,
L_34 ) ;
if ( V_6 -> V_80 == V_81 ) {
V_6 -> V_175 = V_6 -> V_176 ;
V_74 = V_289 | V_290 | V_291 ;
} else {
V_74 = ( V_203 >> V_292 ) & V_293 ;
V_6 -> V_175 = F_112 ( V_74 ) ;
#ifndef V_79
V_6 -> V_175 = F_117 ( 32UL , V_6 -> V_175 ) ;
#endif
V_74 = 0 ;
if ( V_203 & V_294 )
V_74 |= V_289 | V_290 | V_291 ;
if ( V_203 & V_295 )
V_74 |= V_296 | V_297 ;
if ( V_203 & V_298 )
V_74 |= V_299 | V_300 ;
}
V_188 . V_187 &= V_74 ;
F_5 ( V_6 -> V_8 , L_35 , V_74 ) ;
if ( V_6 -> V_47 & V_168 )
F_5 ( V_6 -> V_8 , L_36 ,
V_6 -> V_175 , V_6 -> V_176 ) ;
if ( V_6 -> V_47 & V_171 )
F_5 ( V_6 -> V_8 , L_37 ,
V_6 -> V_176 , V_6 -> V_180 ) ;
return 0 ;
}
static int F_118 ( struct V_301 * V_236 )
{
const struct V_302 * V_303 ;
struct V_304 * V_305 ;
struct V_5 * V_6 ;
struct V_15 * V_8 = & V_236 -> V_8 ;
struct V_22 * V_23 ;
struct V_35 V_36 ;
int V_306 , V_7 , V_307 ;
V_6 = F_20 ( V_8 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 ) {
F_19 ( V_8 , L_38 ) ;
return - V_44 ;
}
V_6 -> V_8 = V_8 ;
V_303 = F_119 ( V_308 , V_8 -> V_9 ) ;
V_6 -> V_80 = (enum V_309 ) V_303 -> V_238 ;
V_305 = F_120 ( V_236 , V_310 , 0 ) ;
V_6 -> V_69 = F_121 ( V_8 , V_305 ) ;
if ( F_99 ( V_6 -> V_69 ) )
return F_100 ( V_6 -> V_69 ) ;
V_6 -> V_74 = F_122 ( V_305 ) ;
if ( F_123 ( V_8 -> V_9 , L_39 ,
& V_6 -> V_193 ) ) {
F_19 ( V_8 , L_40 ) ;
return - V_214 ;
}
V_306 = 0 ;
while ( ( V_305 = F_120 ( V_236 , V_311 , V_306 ) ) ) {
V_306 ++ ;
if ( V_306 > V_6 -> V_193 )
V_6 -> V_186 ++ ;
}
if ( ! V_6 -> V_186 ) {
F_19 ( V_8 , L_41 ,
V_306 , V_6 -> V_193 + 1 ) ;
return - V_214 ;
}
V_6 -> V_192 = F_20 ( V_8 , sizeof( * V_6 -> V_192 ) * V_306 ,
V_43 ) ;
if ( ! V_6 -> V_192 ) {
F_19 ( V_8 , L_42 , V_306 ) ;
return - V_44 ;
}
for ( V_7 = 0 ; V_7 < V_306 ; ++ V_7 ) {
int V_92 = F_124 ( V_236 , V_7 ) ;
if ( V_92 < 0 ) {
F_19 ( V_8 , L_43 , V_7 ) ;
return - V_214 ;
}
V_6 -> V_192 [ V_7 ] = V_92 ;
}
V_307 = F_113 ( V_6 ) ;
if ( V_307 )
return V_307 ;
V_7 = 0 ;
V_6 -> V_24 = V_312 ;
while ( ! F_125 ( V_8 -> V_9 , L_44 ,
L_45 , V_7 ,
& V_36 ) ) {
V_307 = F_18 ( V_6 , V_8 , & V_36 ) ;
if ( V_307 ) {
F_19 ( V_8 , L_46 ,
V_36 . V_37 -> V_38 ) ;
goto V_313;
}
V_7 ++ ;
}
F_5 ( V_8 , L_47 , V_7 ) ;
F_3 ( V_6 ) ;
if ( V_6 -> V_80 > V_81 &&
V_6 -> V_185 != V_6 -> V_186 ) {
F_19 ( V_8 ,
L_48 ,
V_6 -> V_186 , V_6 -> V_185 ) ;
V_307 = - V_214 ;
goto V_313;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_193 ; ++ V_7 ) {
V_307 = F_65 ( V_6 -> V_192 [ V_7 ] ,
F_53 ,
V_194 ,
L_49 ,
V_6 ) ;
if ( V_307 ) {
F_19 ( V_8 , L_50 ,
V_7 , V_6 -> V_192 [ V_7 ] ) ;
goto V_314;
}
}
F_126 ( & V_6 -> V_315 ) ;
F_22 ( & V_52 ) ;
F_127 ( & V_6 -> V_315 , & V_316 ) ;
F_24 ( & V_52 ) ;
F_111 ( V_6 ) ;
return 0 ;
V_314:
while ( V_7 -- )
F_68 ( V_6 -> V_192 [ V_7 ] , V_6 ) ;
V_313:
for ( V_23 = F_128 ( & V_6 -> V_24 ) ; V_23 ; V_23 = F_129 ( V_23 ) ) {
struct V_20 * V_25
= F_2 ( V_23 , struct V_20 , V_23 ) ;
F_130 ( V_25 -> V_9 ) ;
}
return V_307 ;
}
static int F_131 ( struct V_301 * V_236 )
{
int V_7 ;
struct V_15 * V_8 = & V_236 -> V_8 ;
struct V_5 * V_317 , * V_6 = NULL ;
struct V_22 * V_23 ;
F_22 ( & V_52 ) ;
F_23 (curr, &arm_smmu_devices, list) {
if ( V_317 -> V_8 == V_8 ) {
V_6 = V_317 ;
F_132 ( & V_6 -> V_315 ) ;
break;
}
}
F_24 ( & V_52 ) ;
if ( ! V_6 )
return - V_214 ;
for ( V_23 = F_128 ( & V_6 -> V_24 ) ; V_23 ; V_23 = F_129 ( V_23 ) ) {
struct V_20 * V_25
= F_2 ( V_23 , struct V_20 , V_23 ) ;
F_130 ( V_25 -> V_9 ) ;
}
if ( ! F_133 ( V_6 -> V_184 , V_318 ) )
F_19 ( V_8 , L_51 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_193 ; ++ V_7 )
F_68 ( V_6 -> V_192 [ V_7 ] , V_6 ) ;
F_52 ( V_254 , F_54 ( V_6 ) + V_247 ) ;
return 0 ;
}
static int T_9 F_134 ( void )
{
struct V_14 * V_37 ;
int V_94 ;
V_37 = F_135 ( NULL , V_308 ) ;
if ( ! V_37 )
return 0 ;
F_130 ( V_37 ) ;
V_94 = F_136 ( & V_319 ) ;
if ( V_94 )
return V_94 ;
if ( ! F_137 ( & V_320 ) )
F_138 ( & V_320 , & V_188 ) ;
#ifdef F_139
if ( ! F_137 ( & V_321 ) )
F_138 ( & V_321 , & V_188 ) ;
#endif
#ifdef F_140
if ( ! F_137 ( & V_322 ) )
F_138 ( & V_322 , & V_188 ) ;
#endif
return 0 ;
}
static void T_10 F_141 ( void )
{
return F_142 ( & V_319 ) ;
}

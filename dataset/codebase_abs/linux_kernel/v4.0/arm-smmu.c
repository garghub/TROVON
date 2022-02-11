static void F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
do {
if ( F_2 ( V_2 -> V_4 -> V_5 ,
V_6 [ V_3 ] . V_7 ) ) {
V_2 -> V_8 |= V_6 [ V_3 ] . V_9 ;
F_3 ( V_2 -> V_4 , L_1 ,
V_6 [ V_3 ] . V_7 ) ;
}
} while ( V_6 [ ++ V_3 ] . V_9 );
}
static struct V_10 * F_4 ( struct V_11 * V_4 )
{
if ( F_5 ( V_4 ) ) {
struct V_12 * V_13 = F_6 ( V_4 ) -> V_13 ;
while ( ! F_7 ( V_13 ) )
V_13 = V_13 -> V_14 ;
return V_13 -> V_15 -> V_14 -> V_5 ;
}
return V_4 -> V_5 ;
}
static struct V_16 * F_8 ( struct V_1 * V_2 ,
struct V_10 * V_17 )
{
struct V_18 * V_19 = V_2 -> V_20 . V_18 ;
while ( V_19 ) {
struct V_16 * V_21 ;
V_21 = F_9 ( V_19 , struct V_16 , V_19 ) ;
if ( V_17 < V_21 -> V_5 )
V_19 = V_19 -> V_22 ;
else if ( V_17 > V_21 -> V_5 )
V_19 = V_19 -> V_23 ;
else
return V_21 ;
}
return NULL ;
}
static struct V_24 *
F_10 ( struct V_11 * V_4 )
{
struct V_24 * V_25 = NULL ;
struct V_26 * V_27 = F_11 ( V_4 ) ;
if ( V_27 ) {
V_25 = F_12 ( V_27 ) ;
F_13 ( V_27 ) ;
}
return V_25 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_16 * V_21 )
{
struct V_18 * * V_28 , * V_14 ;
V_28 = & V_2 -> V_20 . V_18 ;
V_14 = NULL ;
while ( * V_28 ) {
struct V_16 * V_29
= F_9 ( * V_28 , struct V_16 , V_19 ) ;
V_14 = * V_28 ;
if ( V_21 -> V_5 < V_29 -> V_5 )
V_28 = & ( ( * V_28 ) -> V_22 ) ;
else if ( V_21 -> V_5 > V_29 -> V_5 )
V_28 = & ( ( * V_28 ) -> V_23 ) ;
else
return - V_30 ;
}
F_15 ( & V_21 -> V_19 , V_14 , V_28 ) ;
F_16 ( & V_21 -> V_19 , & V_2 -> V_20 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_11 * V_4 ,
struct V_31 * V_32 )
{
int V_3 ;
struct V_16 * V_21 ;
V_21 = F_8 ( V_2 , V_32 -> V_33 ) ;
if ( V_21 ) {
F_18 ( V_4 ,
L_2 ,
V_32 -> V_33 -> V_34 ) ;
return - V_35 ;
}
if ( V_32 -> V_36 > V_37 ) {
F_18 ( V_4 ,
L_3 ,
V_37 , V_32 -> V_33 -> V_34 ) ;
return - V_38 ;
}
V_21 = F_19 ( V_4 , sizeof( * V_21 ) , V_39 ) ;
if ( ! V_21 )
return - V_40 ;
V_21 -> V_5 = V_32 -> V_33 ;
V_21 -> V_25 . V_41 = V_32 -> V_36 ;
for ( V_3 = 0 ; V_3 < V_21 -> V_25 . V_41 ; ++ V_3 ) {
T_1 V_42 = V_32 -> args [ V_3 ] ;
if ( ! ( V_2 -> V_43 & V_44 ) &&
( V_42 >= V_2 -> V_45 ) ) {
F_18 ( V_4 ,
L_4 ,
V_32 -> V_33 -> V_34 , V_2 -> V_45 ) ;
return - V_46 ;
}
V_21 -> V_25 . V_47 [ V_3 ] = V_42 ;
}
return F_14 ( V_2 , V_21 ) ;
}
static struct V_1 * F_20 ( struct V_11 * V_4 )
{
struct V_1 * V_2 ;
struct V_16 * V_21 = NULL ;
struct V_10 * V_17 = F_4 ( V_4 ) ;
F_21 ( & V_48 ) ;
F_22 (smmu, &arm_smmu_devices, list) {
V_21 = F_8 ( V_2 , V_17 ) ;
if ( V_21 )
break;
}
F_23 ( & V_48 ) ;
return V_21 ? V_2 : NULL ;
}
static int F_24 ( unsigned long * V_49 , int V_50 , int V_51 )
{
int V_52 ;
do {
V_52 = F_25 ( V_49 , V_51 , V_50 ) ;
if ( V_52 == V_51 )
return - V_38 ;
} while ( F_26 ( V_52 , V_49 ) );
return V_52 ;
}
static void F_27 ( unsigned long * V_49 , int V_52 )
{
F_28 ( V_52 , V_49 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
int V_53 = 0 ;
void T_2 * V_54 = F_30 ( V_2 ) ;
F_31 ( 0 , V_54 + V_55 ) ;
while ( F_32 ( V_54 + V_56 )
& V_57 ) {
F_33 () ;
if ( ++ V_53 == V_58 ) {
F_34 ( V_2 -> V_4 ,
L_5 ) ;
return;
}
F_35 ( 1 ) ;
}
}
static void F_36 ( void * V_59 )
{
struct V_60 * V_61 = V_59 ;
F_29 ( V_61 -> V_2 ) ;
}
static void F_37 ( void * V_59 )
{
struct V_60 * V_61 = V_59 ;
struct V_62 * V_25 = & V_61 -> V_25 ;
struct V_1 * V_2 = V_61 -> V_2 ;
bool V_63 = V_25 -> V_64 != V_65 ;
void T_2 * V_66 ;
if ( V_63 ) {
V_66 = F_38 ( V_2 ) + F_39 ( V_2 , V_25 -> V_67 ) ;
F_31 ( F_40 ( V_25 ) ,
V_66 + V_68 ) ;
} else {
V_66 = F_30 ( V_2 ) ;
F_31 ( F_41 ( V_25 ) ,
V_66 + V_69 ) ;
}
F_29 ( V_2 ) ;
}
static void F_42 ( unsigned long V_70 , T_3 V_71 ,
bool V_72 , void * V_59 )
{
struct V_60 * V_61 = V_59 ;
struct V_62 * V_25 = & V_61 -> V_25 ;
struct V_1 * V_2 = V_61 -> V_2 ;
bool V_63 = V_25 -> V_64 != V_65 ;
void T_2 * V_73 ;
if ( V_63 ) {
V_73 = F_38 ( V_2 ) + F_39 ( V_2 , V_25 -> V_67 ) ;
V_73 += V_72 ? V_74 : V_75 ;
if ( ! F_43 ( V_76 ) || V_2 -> V_77 == V_78 ) {
V_70 &= ~ 12UL ;
V_70 |= F_40 ( V_25 ) ;
F_31 ( V_70 , V_73 ) ;
#ifdef V_76
} else {
V_70 >>= 12 ;
V_70 |= ( V_79 ) F_40 ( V_25 ) << 48 ;
F_44 ( V_70 , V_73 ) ;
#endif
}
#ifdef V_76
} else if ( V_2 -> V_77 == V_80 ) {
V_73 = F_38 ( V_2 ) + F_39 ( V_2 , V_25 -> V_67 ) ;
V_73 += V_72 ? V_81 :
V_82 ;
F_44 ( V_70 >> 12 , V_73 ) ;
#endif
} else {
V_73 = F_30 ( V_2 ) + V_69 ;
F_31 ( F_41 ( V_25 ) , V_73 ) ;
}
}
static void F_45 ( void * V_83 , T_3 V_71 , void * V_59 )
{
struct V_60 * V_61 = V_59 ;
struct V_1 * V_2 = V_61 -> V_2 ;
unsigned long V_84 = ( unsigned long ) V_83 & ~ V_85 ;
if ( V_2 -> V_43 & V_86 ) {
F_46 ( V_87 ) ;
} else {
F_47 ( V_2 -> V_4 , F_48 ( V_83 ) , V_84 , V_71 ,
V_88 ) ;
}
}
static T_4 F_49 ( int V_89 , void * V_4 )
{
int V_90 , V_91 ;
T_5 V_92 , V_93 , V_94 , V_95 ;
unsigned long V_70 ;
struct V_96 * V_97 = V_4 ;
struct V_60 * V_61 = V_97 -> V_98 ;
struct V_62 * V_25 = & V_61 -> V_25 ;
struct V_1 * V_2 = V_61 -> V_2 ;
void T_2 * V_99 ;
V_99 = F_38 ( V_2 ) + F_39 ( V_2 , V_25 -> V_67 ) ;
V_92 = F_32 ( V_99 + V_100 ) ;
if ( ! ( V_92 & V_101 ) )
return V_102 ;
if ( V_92 & V_103 )
F_34 ( V_2 -> V_4 ,
L_6 ,
V_92 ) ;
V_94 = F_32 ( V_99 + V_104 ) ;
V_90 = V_94 & V_105 ? V_106 : V_107 ;
V_93 = F_32 ( V_99 + V_108 ) ;
V_70 = V_93 ;
#ifdef V_76
V_93 = F_32 ( V_99 + V_109 ) ;
V_70 |= ( ( unsigned long ) V_93 << 32 ) ;
#endif
if ( ! F_50 ( V_97 , V_2 -> V_4 , V_70 , V_90 ) ) {
V_91 = V_110 ;
V_95 = V_111 ;
} else {
F_34 ( V_2 -> V_4 ,
L_7 ,
V_70 , V_94 , V_25 -> V_67 ) ;
V_91 = V_102 ;
V_95 = V_112 ;
}
F_51 ( V_92 , V_99 + V_100 ) ;
if ( V_92 & V_113 )
F_31 ( V_95 , V_99 + V_114 ) ;
return V_91 ;
}
static T_4 F_52 ( int V_89 , void * V_4 )
{
T_5 V_115 , V_116 , V_117 , V_118 ;
struct V_1 * V_2 = V_4 ;
void T_2 * V_54 = F_53 ( V_2 ) ;
V_115 = F_32 ( V_54 + V_119 ) ;
V_116 = F_32 ( V_54 + V_120 ) ;
V_117 = F_32 ( V_54 + V_121 ) ;
V_118 = F_32 ( V_54 + V_122 ) ;
if ( ! V_115 )
return V_102 ;
F_34 ( V_2 -> V_4 ,
L_8 ) ;
F_34 ( V_2 -> V_4 ,
L_9 ,
V_115 , V_116 , V_117 , V_118 ) ;
F_51 ( V_115 , V_54 + V_119 ) ;
return V_110 ;
}
static void F_54 ( struct V_60 * V_61 ,
struct V_123 * V_124 )
{
T_5 V_73 ;
bool V_63 ;
struct V_62 * V_25 = & V_61 -> V_25 ;
struct V_1 * V_2 = V_61 -> V_2 ;
void T_2 * V_99 , * V_54 , * V_125 ;
V_54 = F_30 ( V_2 ) ;
V_125 = F_55 ( V_2 ) ;
V_63 = V_25 -> V_64 != V_65 ;
V_99 = F_38 ( V_2 ) + F_39 ( V_2 , V_25 -> V_67 ) ;
V_73 = V_25 -> V_64 ;
if ( V_2 -> V_77 == V_78 )
V_73 |= V_25 -> V_126 << V_127 ;
if ( V_63 ) {
V_73 |= ( V_128 << V_129 ) |
( V_130 << V_131 ) ;
} else {
V_73 |= F_41 ( V_25 ) << V_132 ;
}
F_31 ( V_73 , V_125 + F_56 ( V_25 -> V_67 ) ) ;
if ( V_2 -> V_77 > V_78 ) {
#ifdef V_76
V_73 = V_133 ;
#else
V_73 = V_134 ;
#endif
F_31 ( V_73 , V_125 + F_57 ( V_25 -> V_67 ) ) ;
}
if ( V_63 ) {
V_73 = V_124 -> V_135 . V_136 [ 0 ] ;
F_31 ( V_73 , V_99 + V_137 ) ;
V_73 = V_124 -> V_135 . V_136 [ 0 ] >> 32 ;
V_73 |= F_40 ( V_25 ) << V_138 ;
F_31 ( V_73 , V_99 + V_139 ) ;
V_73 = V_124 -> V_135 . V_136 [ 1 ] ;
F_31 ( V_73 , V_99 + V_140 ) ;
V_73 = V_124 -> V_135 . V_136 [ 1 ] >> 32 ;
V_73 |= F_40 ( V_25 ) << V_138 ;
F_31 ( V_73 , V_99 + V_141 ) ;
} else {
V_73 = V_124 -> V_142 . V_143 ;
F_31 ( V_73 , V_99 + V_137 ) ;
V_73 = V_124 -> V_142 . V_143 >> 32 ;
F_31 ( V_73 , V_99 + V_139 ) ;
}
if ( V_63 ) {
V_73 = V_124 -> V_135 . V_144 ;
F_31 ( V_73 , V_99 + V_145 ) ;
if ( V_2 -> V_77 > V_78 ) {
V_73 = V_124 -> V_135 . V_144 >> 32 ;
switch ( V_2 -> V_146 ) {
case 32 :
V_73 |= ( V_147 << V_148 ) ;
break;
case 36 :
V_73 |= ( V_149 << V_148 ) ;
break;
case 40 :
V_73 |= ( V_150 << V_148 ) ;
break;
case 42 :
V_73 |= ( V_151 << V_148 ) ;
break;
case 44 :
V_73 |= ( V_152 << V_148 ) ;
break;
case 48 :
V_73 |= ( V_153 << V_148 ) ;
break;
}
F_31 ( V_73 , V_99 + V_154 ) ;
}
} else {
V_73 = V_124 -> V_142 . V_155 ;
F_31 ( V_73 , V_99 + V_145 ) ;
}
if ( V_63 ) {
V_73 = V_124 -> V_135 . V_156 [ 0 ] ;
F_31 ( V_73 , V_99 + V_157 ) ;
V_73 = V_124 -> V_135 . V_156 [ 1 ] ;
F_31 ( V_73 , V_99 + V_158 ) ;
}
V_73 = V_159 | V_160 | V_161 | V_162 | V_163 ;
if ( V_63 )
V_73 |= V_164 ;
#ifdef F_58
V_73 |= V_165 ;
#endif
F_31 ( V_73 , V_99 + V_166 ) ;
}
static int F_59 ( struct V_96 * V_97 ,
struct V_1 * V_2 )
{
int V_89 , V_50 , V_91 = 0 ;
unsigned long V_167 , V_168 ;
struct V_169 * V_170 ;
struct V_123 V_124 ;
enum V_171 V_172 ;
struct V_60 * V_61 = V_97 -> V_98 ;
struct V_62 * V_25 = & V_61 -> V_25 ;
F_60 ( & V_61 -> V_173 ) ;
if ( V_61 -> V_2 )
goto V_174;
if ( ! ( V_2 -> V_43 & V_175 ) )
V_61 -> V_176 = V_177 ;
if ( ! ( V_2 -> V_43 & V_178 ) )
V_61 -> V_176 = V_179 ;
switch ( V_61 -> V_176 ) {
case V_179 :
V_25 -> V_64 = V_180 ;
V_50 = V_2 -> V_181 ;
V_167 = V_2 -> V_146 ;
V_168 = V_2 -> V_182 ;
if ( F_43 ( V_76 ) )
V_172 = V_183 ;
else
V_172 = V_184 ;
break;
case V_185 :
case V_177 :
V_25 -> V_64 = V_65 ;
V_50 = 0 ;
V_167 = V_2 -> V_182 ;
V_168 = V_2 -> V_186 ;
if ( F_43 ( V_76 ) )
V_172 = V_187 ;
else
V_172 = V_188 ;
break;
default:
V_91 = - V_189 ;
goto V_174;
}
V_91 = F_24 ( V_2 -> V_190 , V_50 ,
V_2 -> V_191 ) ;
if ( F_61 ( V_91 ) )
goto V_174;
V_25 -> V_67 = V_91 ;
if ( V_2 -> V_77 == V_78 ) {
V_25 -> V_126 = F_62 ( & V_2 -> V_126 ) ;
V_25 -> V_126 %= V_2 -> V_192 ;
} else {
V_25 -> V_126 = V_25 -> V_67 ;
}
V_124 = (struct V_123 ) {
. V_193 = V_194 . V_193 ,
. V_167 = V_167 ,
. V_168 = V_168 ,
. V_195 = & V_196 ,
} ;
V_61 -> V_2 = V_2 ;
V_170 = F_63 ( V_172 , & V_124 , V_61 ) ;
if ( ! V_170 ) {
V_91 = - V_40 ;
goto V_197;
}
V_194 . V_193 = V_124 . V_193 ;
F_54 ( V_61 , & V_124 ) ;
V_89 = V_2 -> V_198 [ V_2 -> V_199 + V_25 -> V_126 ] ;
V_91 = F_64 ( V_89 , F_49 , V_200 ,
L_10 , V_97 ) ;
if ( F_61 ( V_91 ) ) {
F_18 ( V_2 -> V_4 , L_11 ,
V_25 -> V_126 , V_89 ) ;
V_25 -> V_126 = V_201 ;
}
F_65 ( & V_61 -> V_173 ) ;
V_61 -> V_170 = V_170 ;
return 0 ;
V_197:
V_61 -> V_2 = NULL ;
V_174:
F_65 ( & V_61 -> V_173 ) ;
return V_91 ;
}
static void F_66 ( struct V_96 * V_97 )
{
struct V_60 * V_61 = V_97 -> V_98 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_62 * V_25 = & V_61 -> V_25 ;
void T_2 * V_99 ;
int V_89 ;
if ( ! V_2 )
return;
V_99 = F_38 ( V_2 ) + F_39 ( V_2 , V_25 -> V_67 ) ;
F_31 ( 0 , V_99 + V_166 ) ;
if ( V_25 -> V_126 != V_201 ) {
V_89 = V_2 -> V_198 [ V_2 -> V_199 + V_25 -> V_126 ] ;
F_67 ( V_89 , V_97 ) ;
}
if ( V_61 -> V_170 )
F_68 ( V_61 -> V_170 ) ;
F_27 ( V_2 -> V_190 , V_25 -> V_67 ) ;
}
static int F_69 ( struct V_96 * V_97 )
{
struct V_60 * V_61 ;
V_61 = F_70 ( sizeof( * V_61 ) , V_39 ) ;
if ( ! V_61 )
return - V_40 ;
F_71 ( & V_61 -> V_173 ) ;
F_72 ( & V_61 -> V_202 ) ;
V_97 -> V_98 = V_61 ;
return 0 ;
}
static void F_73 ( struct V_96 * V_97 )
{
struct V_60 * V_61 = V_97 -> V_98 ;
F_66 ( V_97 ) ;
F_74 ( V_61 ) ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_3 ;
struct V_203 * V_204 ;
void T_2 * V_54 = F_30 ( V_2 ) ;
if ( ! ( V_2 -> V_43 & V_44 ) )
return 0 ;
if ( V_25 -> V_204 )
return - V_30 ;
V_204 = F_76 ( V_25 -> V_41 , sizeof( * V_204 ) , V_39 ) ;
if ( ! V_204 ) {
F_18 ( V_2 -> V_4 , L_12 ,
V_25 -> V_41 ) ;
return - V_40 ;
}
for ( V_3 = 0 ; V_3 < V_25 -> V_41 ; ++ V_3 ) {
int V_52 = F_24 ( V_2 -> V_205 , 0 ,
V_2 -> V_45 ) ;
if ( F_61 ( V_52 ) ) {
F_18 ( V_2 -> V_4 , L_13 ) ;
goto V_206;
}
V_204 [ V_3 ] = (struct V_203 ) {
. V_52 = V_52 ,
. V_207 = 0 ,
. V_208 = V_25 -> V_47 [ V_3 ] ,
} ;
}
for ( V_3 = 0 ; V_3 < V_25 -> V_41 ; ++ V_3 ) {
T_5 V_73 = V_209 | V_204 [ V_3 ] . V_208 << V_210 |
V_204 [ V_3 ] . V_207 << V_211 ;
F_31 ( V_73 , V_54 + F_77 ( V_204 [ V_3 ] . V_52 ) ) ;
}
V_25 -> V_204 = V_204 ;
return 0 ;
V_206:
while ( -- V_3 >= 0 )
F_27 ( V_2 -> V_205 , V_204 [ V_3 ] . V_52 ) ;
F_74 ( V_204 ) ;
return - V_38 ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_3 ;
void T_2 * V_54 = F_30 ( V_2 ) ;
struct V_203 * V_204 = V_25 -> V_204 ;
if ( ! V_204 )
return;
for ( V_3 = 0 ; V_3 < V_25 -> V_41 ; ++ V_3 ) {
T_6 V_52 = V_204 [ V_3 ] . V_52 ;
F_31 ( ~ V_209 , V_54 + F_77 ( V_52 ) ) ;
F_27 ( V_2 -> V_205 , V_52 ) ;
}
V_25 -> V_204 = NULL ;
F_74 ( V_204 ) ;
}
static int F_79 ( struct V_60 * V_61 ,
struct V_24 * V_25 )
{
int V_3 , V_91 ;
struct V_1 * V_2 = V_61 -> V_2 ;
void T_2 * V_54 = F_30 ( V_2 ) ;
V_91 = F_75 ( V_2 , V_25 ) ;
if ( V_91 )
return V_91 == - V_30 ? 0 : V_91 ;
for ( V_3 = 0 ; V_3 < V_25 -> V_41 ; ++ V_3 ) {
T_5 V_52 , V_212 ;
V_52 = V_25 -> V_204 ? V_25 -> V_204 [ V_3 ] . V_52 : V_25 -> V_47 [ V_3 ] ;
V_212 = V_213 |
( V_61 -> V_25 . V_67 << V_214 ) ;
F_31 ( V_212 , V_54 + F_80 ( V_52 ) ) ;
}
return 0 ;
}
static void F_81 ( struct V_60 * V_61 ,
struct V_24 * V_25 )
{
int V_3 ;
struct V_1 * V_2 = V_61 -> V_2 ;
void T_2 * V_54 = F_30 ( V_2 ) ;
if ( ( V_2 -> V_43 & V_44 ) && ! V_25 -> V_204 )
return;
for ( V_3 = 0 ; V_3 < V_25 -> V_41 ; ++ V_3 ) {
T_5 V_52 = V_25 -> V_204 ? V_25 -> V_204 [ V_3 ] . V_52 : V_25 -> V_47 [ V_3 ] ;
F_31 ( V_215 ,
V_54 + F_80 ( V_52 ) ) ;
}
F_78 ( V_2 , V_25 ) ;
}
static int F_82 ( struct V_96 * V_97 , struct V_11 * V_4 )
{
int V_91 ;
struct V_60 * V_61 = V_97 -> V_98 ;
struct V_1 * V_2 ;
struct V_24 * V_25 ;
V_2 = F_20 ( V_4 ) ;
if ( ! V_2 ) {
F_18 ( V_4 , L_14 ) ;
return - V_216 ;
}
if ( V_4 -> V_217 . V_218 ) {
F_18 ( V_4 , L_15 ) ;
return - V_30 ;
}
V_91 = F_59 ( V_97 , V_2 ) ;
if ( F_61 ( V_91 ) )
return V_91 ;
if ( V_61 -> V_2 != V_2 ) {
F_18 ( V_4 ,
L_16 ,
F_83 ( V_61 -> V_2 -> V_4 ) , F_83 ( V_2 -> V_4 ) ) ;
return - V_189 ;
}
V_25 = F_10 ( V_4 ) ;
if ( ! V_25 )
return - V_219 ;
V_91 = F_79 ( V_61 , V_25 ) ;
if ( ! V_91 )
V_4 -> V_217 . V_218 = V_97 ;
return V_91 ;
}
static void F_84 ( struct V_96 * V_97 , struct V_11 * V_4 )
{
struct V_60 * V_61 = V_97 -> V_98 ;
struct V_24 * V_25 ;
V_25 = F_10 ( V_4 ) ;
if ( ! V_25 )
return;
V_4 -> V_217 . V_218 = NULL ;
F_81 ( V_61 , V_25 ) ;
}
static int F_85 ( struct V_96 * V_97 , unsigned long V_70 ,
T_7 V_220 , T_3 V_71 , int V_221 )
{
int V_91 ;
unsigned long V_90 ;
struct V_60 * V_61 = V_97 -> V_98 ;
struct V_169 * V_222 = V_61 -> V_170 ;
if ( ! V_222 )
return - V_219 ;
F_86 ( & V_61 -> V_202 , V_90 ) ;
V_91 = V_222 -> V_49 ( V_222 , V_70 , V_220 , V_71 , V_221 ) ;
F_87 ( & V_61 -> V_202 , V_90 ) ;
return V_91 ;
}
static T_3 F_88 ( struct V_96 * V_97 , unsigned long V_70 ,
T_3 V_71 )
{
T_3 V_91 ;
unsigned long V_90 ;
struct V_60 * V_61 = V_97 -> V_98 ;
struct V_169 * V_222 = V_61 -> V_170 ;
if ( ! V_222 )
return 0 ;
F_86 ( & V_61 -> V_202 , V_90 ) ;
V_91 = V_222 -> V_223 ( V_222 , V_70 , V_71 ) ;
F_87 ( & V_61 -> V_202 , V_90 ) ;
return V_91 ;
}
static T_7 F_89 ( struct V_96 * V_97 ,
T_8 V_70 )
{
struct V_60 * V_61 = V_97 -> V_98 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_62 * V_25 = & V_61 -> V_25 ;
struct V_169 * V_222 = V_61 -> V_170 ;
struct V_11 * V_4 = V_2 -> V_4 ;
void T_2 * V_99 ;
T_5 V_224 ;
V_79 V_225 ;
V_99 = F_38 ( V_2 ) + F_39 ( V_2 , V_25 -> V_67 ) ;
if ( V_2 -> V_77 == 1 ) {
T_5 V_73 = V_70 & ~ 0xfff ;
F_31 ( V_73 , V_99 + V_226 ) ;
} else {
T_5 V_73 = V_70 & ~ 0xfff ;
F_31 ( V_73 , V_99 + V_226 ) ;
V_73 = ( ( V_79 ) V_70 & ~ 0xfff ) >> 32 ;
F_31 ( V_73 , V_99 + V_227 ) ;
}
if ( F_90 ( V_99 + V_228 , V_224 ,
! ( V_224 & V_229 ) , 5 , 50 ) ) {
F_18 ( V_4 ,
L_17 ,
& V_70 ) ;
return V_222 -> V_230 ( V_222 , V_70 ) ;
}
V_225 = F_32 ( V_99 + V_231 ) ;
V_225 |= ( ( V_79 ) F_32 ( V_99 + V_232 ) ) << 32 ;
if ( V_225 & V_233 ) {
F_18 ( V_4 , L_18 ) ;
F_18 ( V_4 , L_19 , V_225 ) ;
return 0 ;
}
return ( V_225 & F_91 ( 39 , 12 ) ) | ( V_70 & 0xfff ) ;
}
static T_7 F_92 ( struct V_96 * V_97 ,
T_8 V_70 )
{
T_7 V_91 ;
unsigned long V_90 ;
struct V_60 * V_61 = V_97 -> V_98 ;
struct V_169 * V_222 = V_61 -> V_170 ;
if ( ! V_222 )
return 0 ;
F_86 ( & V_61 -> V_202 , V_90 ) ;
if ( V_61 -> V_2 -> V_43 & V_234 &&
V_61 -> V_176 == V_179 ) {
V_91 = F_89 ( V_97 , V_70 ) ;
} else {
V_91 = V_222 -> V_230 ( V_222 , V_70 ) ;
}
F_87 ( & V_61 -> V_202 , V_90 ) ;
return V_91 ;
}
static bool F_93 ( enum V_235 V_236 )
{
switch ( V_236 ) {
case V_237 :
return true ;
case V_238 :
return true ;
case V_239 :
return true ;
default:
return false ;
}
}
static int F_94 ( struct V_240 * V_241 , T_1 V_242 , void * V_243 )
{
* ( ( T_1 * ) V_243 ) = V_242 ;
return 0 ;
}
static void F_95 ( void * V_243 )
{
F_74 ( V_243 ) ;
}
static int F_96 ( struct V_11 * V_4 )
{
struct V_1 * V_2 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
void (* F_97)( void * ) = NULL ;
int V_91 ;
V_2 = F_20 ( V_4 ) ;
if ( ! V_2 )
return - V_219 ;
V_27 = F_98 () ;
if ( F_99 ( V_27 ) ) {
F_18 ( V_4 , L_20 ) ;
return F_100 ( V_27 ) ;
}
if ( F_5 ( V_4 ) ) {
struct V_240 * V_241 = F_6 ( V_4 ) ;
V_25 = F_70 ( sizeof( * V_25 ) , V_39 ) ;
if ( ! V_25 ) {
V_91 = - V_40 ;
goto V_244;
}
V_25 -> V_41 = 1 ;
F_101 ( V_241 , F_94 ,
& V_25 -> V_47 [ 0 ] ) ;
F_97 = F_95 ;
} else {
struct V_16 * V_21 ;
V_21 = F_8 ( V_2 , V_4 -> V_5 ) ;
if ( ! V_21 ) {
V_91 = - V_219 ;
goto V_244;
}
V_25 = & V_21 -> V_25 ;
}
F_102 ( V_27 , V_25 , F_97 ) ;
V_91 = F_103 ( V_27 , V_4 ) ;
V_244:
F_13 ( V_27 ) ;
return V_91 ;
}
static void F_104 ( struct V_11 * V_4 )
{
F_105 ( V_4 ) ;
}
static int F_106 ( struct V_96 * V_97 ,
enum V_245 V_246 , void * V_243 )
{
struct V_60 * V_61 = V_97 -> V_98 ;
switch ( V_246 ) {
case V_247 :
* ( int * ) V_243 = ( V_61 -> V_176 == V_185 ) ;
return 0 ;
default:
return - V_219 ;
}
}
static int F_107 ( struct V_96 * V_97 ,
enum V_245 V_246 , void * V_243 )
{
int V_91 = 0 ;
struct V_60 * V_61 = V_97 -> V_98 ;
F_60 ( & V_61 -> V_173 ) ;
switch ( V_246 ) {
case V_247 :
if ( V_61 -> V_2 ) {
V_91 = - V_248 ;
goto V_174;
}
if ( * ( int * ) V_243 )
V_61 -> V_176 = V_185 ;
else
V_61 -> V_176 = V_179 ;
break;
default:
V_91 = - V_219 ;
}
V_174:
F_65 ( & V_61 -> V_173 ) ;
return V_91 ;
}
static void F_108 ( struct V_1 * V_2 )
{
void T_2 * V_54 = F_30 ( V_2 ) ;
void T_2 * V_99 ;
int V_3 = 0 ;
T_5 V_73 ;
V_73 = F_32 ( F_53 ( V_2 ) + V_119 ) ;
F_51 ( V_73 , F_53 ( V_2 ) + V_119 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_45 ; ++ V_3 ) {
F_31 ( 0 , V_54 + F_77 ( V_3 ) ) ;
F_31 ( V_215 ,
V_54 + F_80 ( V_3 ) ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_191 ; ++ V_3 ) {
V_99 = F_38 ( V_2 ) + F_39 ( V_2 , V_3 ) ;
F_31 ( 0 , V_99 + V_166 ) ;
F_31 ( V_101 , V_99 + V_100 ) ;
}
F_31 ( 0 , V_54 + V_249 ) ;
F_31 ( 0 , V_54 + V_250 ) ;
V_73 = F_32 ( F_53 ( V_2 ) + V_251 ) ;
V_73 |= ( V_252 | V_253 | V_254 | V_255 ) ;
V_73 |= ( V_256 | V_257 ) ;
V_73 &= ~ ( V_258 | V_259 ) ;
V_73 &= ~ V_260 ;
V_73 &= ~ ( V_261 << V_262 ) ;
F_29 ( V_2 ) ;
F_51 ( V_73 , F_53 ( V_2 ) + V_251 ) ;
}
static int F_109 ( int V_71 )
{
switch ( V_71 ) {
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
static int F_110 ( struct V_1 * V_2 )
{
unsigned long V_71 ;
void T_2 * V_54 = F_30 ( V_2 ) ;
T_5 V_208 ;
F_3 ( V_2 -> V_4 , L_21 ) ;
F_3 ( V_2 -> V_4 , L_22 , V_2 -> V_77 ) ;
V_208 = F_32 ( V_54 + V_263 ) ;
if ( V_264 == 1 )
V_208 &= ~ ( V_265 | V_266 ) ;
else if ( V_264 == 2 )
V_208 &= ~ ( V_267 | V_266 ) ;
if ( V_208 & V_267 ) {
V_2 -> V_43 |= V_175 ;
F_3 ( V_2 -> V_4 , L_23 ) ;
}
if ( V_208 & V_265 ) {
V_2 -> V_43 |= V_178 ;
F_3 ( V_2 -> V_4 , L_24 ) ;
}
if ( V_208 & V_266 ) {
V_2 -> V_43 |= V_268 ;
F_3 ( V_2 -> V_4 , L_25 ) ;
}
if ( ! ( V_2 -> V_43 &
( V_175 | V_178 ) ) ) {
F_18 ( V_2 -> V_4 , L_26 ) ;
return - V_219 ;
}
if ( ( V_208 & V_267 ) && ( ( V_2 -> V_77 == 1 ) || ( V_208 & V_269 ) ) ) {
V_2 -> V_43 |= V_234 ;
F_3 ( V_2 -> V_4 , L_27 ) ;
}
if ( V_208 & V_270 ) {
V_2 -> V_43 |= V_86 ;
F_3 ( V_2 -> V_4 , L_28 ) ;
}
if ( V_208 & V_271 ) {
T_5 V_272 , V_273 , V_207 ;
V_2 -> V_43 |= V_44 ;
V_2 -> V_45 = ( V_208 >> V_274 ) &
V_275 ;
if ( V_2 -> V_45 == 0 ) {
F_18 ( V_2 -> V_4 ,
L_29 ) ;
return - V_219 ;
}
V_272 = V_276 << V_211 ;
V_272 |= ( V_277 << V_210 ) ;
F_31 ( V_272 , V_54 + F_77 ( 0 ) ) ;
V_272 = F_32 ( V_54 + F_77 ( 0 ) ) ;
V_207 = ( V_272 >> V_211 ) & V_276 ;
V_273 = ( V_272 >> V_210 ) & V_277 ;
if ( ( V_207 & V_273 ) != V_273 ) {
F_18 ( V_2 -> V_4 ,
L_30 ,
V_207 , V_273 ) ;
return - V_219 ;
}
F_3 ( V_2 -> V_4 ,
L_31 ,
V_2 -> V_45 , V_207 ) ;
} else {
V_2 -> V_45 = ( V_208 >> V_278 ) &
V_279 ;
}
V_208 = F_32 ( V_54 + V_280 ) ;
V_2 -> V_281 = ( V_208 & V_282 ) ? 16 : 12 ;
V_71 = 1 << ( ( ( V_208 >> V_283 ) & V_284 ) + 1 ) ;
V_71 *= 2 << V_2 -> V_281 ;
if ( V_2 -> V_71 != V_71 )
F_111 ( V_2 -> V_4 ,
L_32 ,
V_71 , V_2 -> V_71 ) ;
V_2 -> V_181 = ( V_208 >> V_285 ) & V_286 ;
V_2 -> V_191 = ( V_208 >> V_287 ) & V_288 ;
if ( V_2 -> V_181 > V_2 -> V_191 ) {
F_18 ( V_2 -> V_4 , L_33 ) ;
return - V_219 ;
}
F_3 ( V_2 -> V_4 , L_34 ,
V_2 -> V_191 , V_2 -> V_181 ) ;
V_208 = F_32 ( V_54 + V_289 ) ;
V_71 = F_109 ( ( V_208 >> V_290 ) & V_291 ) ;
V_2 -> V_182 = V_71 ;
V_71 = F_109 ( ( V_208 >> V_292 ) & V_293 ) ;
V_2 -> V_186 = V_71 ;
if ( V_2 -> V_77 == V_78 ) {
V_2 -> V_146 = V_2 -> V_182 ;
V_71 = V_294 | V_295 | V_296 ;
} else {
V_71 = ( V_208 >> V_297 ) & V_298 ;
V_2 -> V_146 = F_109 ( V_71 ) ;
#ifndef V_76
V_2 -> V_146 = F_112 ( 32UL , V_2 -> V_146 ) ;
#endif
V_71 = 0 ;
if ( V_208 & V_299 )
V_71 |= V_294 | V_295 | V_296 ;
if ( V_208 & V_300 )
V_71 |= V_301 | V_302 ;
if ( V_208 & V_303 )
V_71 |= V_304 | V_305 ;
}
V_194 . V_193 &= V_71 ;
F_3 ( V_2 -> V_4 , L_35 , V_71 ) ;
if ( V_2 -> V_43 & V_175 )
F_3 ( V_2 -> V_4 , L_36 ,
V_2 -> V_146 , V_2 -> V_182 ) ;
if ( V_2 -> V_43 & V_178 )
F_3 ( V_2 -> V_4 , L_37 ,
V_2 -> V_182 , V_2 -> V_186 ) ;
return 0 ;
}
static int F_113 ( struct V_306 * V_241 )
{
const struct V_307 * V_308 ;
struct V_309 * V_310 ;
struct V_1 * V_2 ;
struct V_11 * V_4 = & V_241 -> V_4 ;
struct V_18 * V_19 ;
struct V_31 V_32 ;
int V_311 , V_3 , V_312 ;
V_2 = F_19 ( V_4 , sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 ) {
F_18 ( V_4 , L_38 ) ;
return - V_40 ;
}
V_2 -> V_4 = V_4 ;
V_308 = F_114 ( V_313 , V_4 -> V_5 ) ;
V_2 -> V_77 = (enum V_314 ) V_308 -> V_243 ;
V_310 = F_115 ( V_241 , V_315 , 0 ) ;
V_2 -> V_66 = F_116 ( V_4 , V_310 ) ;
if ( F_99 ( V_2 -> V_66 ) )
return F_100 ( V_2 -> V_66 ) ;
V_2 -> V_71 = F_117 ( V_310 ) ;
if ( F_118 ( V_4 -> V_5 , L_39 ,
& V_2 -> V_199 ) ) {
F_18 ( V_4 , L_40 ) ;
return - V_219 ;
}
V_311 = 0 ;
while ( ( V_310 = F_115 ( V_241 , V_316 , V_311 ) ) ) {
V_311 ++ ;
if ( V_311 > V_2 -> V_199 )
V_2 -> V_192 ++ ;
}
if ( ! V_2 -> V_192 ) {
F_18 ( V_4 , L_41 ,
V_311 , V_2 -> V_199 + 1 ) ;
return - V_219 ;
}
V_2 -> V_198 = F_19 ( V_4 , sizeof( * V_2 -> V_198 ) * V_311 ,
V_39 ) ;
if ( ! V_2 -> V_198 ) {
F_18 ( V_4 , L_42 , V_311 ) ;
return - V_40 ;
}
for ( V_3 = 0 ; V_3 < V_311 ; ++ V_3 ) {
int V_89 = F_119 ( V_241 , V_3 ) ;
if ( V_89 < 0 ) {
F_18 ( V_4 , L_43 , V_3 ) ;
return - V_219 ;
}
V_2 -> V_198 [ V_3 ] = V_89 ;
}
V_312 = F_110 ( V_2 ) ;
if ( V_312 )
return V_312 ;
V_3 = 0 ;
V_2 -> V_20 = V_317 ;
while ( ! F_120 ( V_4 -> V_5 , L_44 ,
L_45 , V_3 ,
& V_32 ) ) {
V_312 = F_17 ( V_2 , V_4 , & V_32 ) ;
if ( V_312 ) {
F_18 ( V_4 , L_46 ,
V_32 . V_33 -> V_34 ) ;
goto V_318;
}
V_3 ++ ;
}
F_3 ( V_4 , L_47 , V_3 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_77 > V_78 &&
V_2 -> V_191 != V_2 -> V_192 ) {
F_18 ( V_4 ,
L_48 ,
V_2 -> V_192 , V_2 -> V_191 ) ;
V_312 = - V_219 ;
goto V_318;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_199 ; ++ V_3 ) {
V_312 = F_64 ( V_2 -> V_198 [ V_3 ] ,
F_52 ,
V_200 ,
L_49 ,
V_2 ) ;
if ( V_312 ) {
F_18 ( V_4 , L_50 ,
V_3 , V_2 -> V_198 [ V_3 ] ) ;
goto V_319;
}
}
F_121 ( & V_2 -> V_320 ) ;
F_21 ( & V_48 ) ;
F_122 ( & V_2 -> V_320 , & V_321 ) ;
F_23 ( & V_48 ) ;
F_108 ( V_2 ) ;
return 0 ;
V_319:
while ( V_3 -- )
F_67 ( V_2 -> V_198 [ V_3 ] , V_2 ) ;
V_318:
for ( V_19 = F_123 ( & V_2 -> V_20 ) ; V_19 ; V_19 = F_124 ( V_19 ) ) {
struct V_16 * V_21
= F_9 ( V_19 , struct V_16 , V_19 ) ;
F_125 ( V_21 -> V_5 ) ;
}
return V_312 ;
}
static int F_126 ( struct V_306 * V_241 )
{
int V_3 ;
struct V_11 * V_4 = & V_241 -> V_4 ;
struct V_1 * V_322 , * V_2 = NULL ;
struct V_18 * V_19 ;
F_21 ( & V_48 ) ;
F_22 (curr, &arm_smmu_devices, list) {
if ( V_322 -> V_4 == V_4 ) {
V_2 = V_322 ;
F_127 ( & V_2 -> V_320 ) ;
break;
}
}
F_23 ( & V_48 ) ;
if ( ! V_2 )
return - V_219 ;
for ( V_19 = F_123 ( & V_2 -> V_20 ) ; V_19 ; V_19 = F_124 ( V_19 ) ) {
struct V_16 * V_21
= F_9 ( V_19 , struct V_16 , V_19 ) ;
F_125 ( V_21 -> V_5 ) ;
}
if ( ! F_128 ( V_2 -> V_190 , V_323 ) )
F_18 ( V_4 , L_51 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_199 ; ++ V_3 )
F_67 ( V_2 -> V_198 [ V_3 ] , V_2 ) ;
F_51 ( V_258 , F_53 ( V_2 ) + V_251 ) ;
return 0 ;
}
static int T_9 F_129 ( void )
{
struct V_10 * V_33 ;
int V_91 ;
V_33 = F_130 ( NULL , V_313 ) ;
if ( ! V_33 )
return 0 ;
F_125 ( V_33 ) ;
V_91 = F_131 ( & V_324 ) ;
if ( V_91 )
return V_91 ;
if ( ! F_132 ( & V_325 ) )
F_133 ( & V_325 , & V_194 ) ;
#ifdef F_134
if ( ! F_132 ( & V_326 ) )
F_133 ( & V_326 , & V_194 ) ;
#endif
#ifdef F_135
if ( ! F_132 ( & V_327 ) )
F_133 ( & V_327 , & V_194 ) ;
#endif
return 0 ;
}
static void T_10 F_136 ( void )
{
return F_137 ( & V_324 ) ;
}

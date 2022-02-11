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
V_82 V_119 ;
bool V_66 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_93 , * V_120 ;
V_120 = F_52 ( V_6 ) ;
V_66 = V_29 -> V_67 != V_68 ;
V_93 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
if ( V_6 -> V_80 > V_81 ) {
#ifdef V_79
V_76 = V_121 ;
#else
V_76 = V_122 ;
#endif
F_32 ( V_76 , V_120 + F_53 ( V_29 -> V_70 ) ) ;
}
V_76 = V_29 -> V_67 ;
if ( V_6 -> V_80 == V_81 )
V_76 |= V_29 -> V_123 << V_124 ;
if ( V_66 ) {
V_76 |= ( V_125 << V_126 ) |
( V_127 << V_128 ) ;
} else {
V_76 |= F_42 ( V_29 ) << V_129 ;
}
F_32 ( V_76 , V_120 + F_54 ( V_29 -> V_70 ) ) ;
if ( V_66 ) {
V_119 = V_118 -> V_130 . V_131 [ 0 ] ;
V_119 |= ( ( V_82 ) F_41 ( V_29 ) ) << V_132 ;
F_55 ( V_119 , V_93 + V_133 ) ;
V_119 = V_118 -> V_130 . V_131 [ 1 ] ;
V_119 |= ( ( V_82 ) F_41 ( V_29 ) ) << V_132 ;
F_55 ( V_119 , V_93 + V_134 ) ;
} else {
V_119 = V_118 -> V_135 . V_136 ;
F_55 ( V_119 , V_93 + V_133 ) ;
}
if ( V_66 ) {
V_76 = V_118 -> V_130 . V_137 ;
F_32 ( V_76 , V_93 + V_138 ) ;
if ( V_6 -> V_80 > V_81 ) {
V_76 = V_118 -> V_130 . V_137 >> 32 ;
V_76 |= V_139 ;
F_32 ( V_76 , V_93 + V_140 ) ;
}
} else {
V_76 = V_118 -> V_135 . V_141 ;
F_32 ( V_76 , V_93 + V_138 ) ;
}
if ( V_66 ) {
V_76 = V_118 -> V_130 . V_142 [ 0 ] ;
F_32 ( V_76 , V_93 + V_143 ) ;
V_76 = V_118 -> V_130 . V_142 [ 1 ] ;
F_32 ( V_76 , V_93 + V_144 ) ;
}
V_76 = V_145 | V_146 | V_147 | V_148 | V_149 ;
if ( V_66 )
V_76 |= V_150 ;
#ifdef F_56
V_76 |= V_151 ;
#endif
F_32 ( V_76 , V_93 + V_152 ) ;
}
static int F_57 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
int V_86 , V_54 , V_88 = 0 ;
unsigned long V_153 , V_154 ;
struct V_155 * V_156 ;
struct V_117 V_118 ;
enum V_157 V_158 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_65 * V_29 = & V_64 -> V_29 ;
F_58 ( & V_64 -> V_159 ) ;
if ( V_64 -> V_6 )
goto V_160;
if ( ! ( V_6 -> V_47 & V_161 ) )
V_64 -> V_162 = V_163 ;
if ( ! ( V_6 -> V_47 & V_164 ) )
V_64 -> V_162 = V_165 ;
switch ( V_64 -> V_162 ) {
case V_165 :
V_29 -> V_67 = V_166 ;
V_54 = V_6 -> V_167 ;
V_153 = V_6 -> V_168 ;
V_154 = V_6 -> V_169 ;
if ( F_44 ( V_79 ) )
V_158 = V_170 ;
else
V_158 = V_171 ;
break;
case V_172 :
case V_163 :
V_29 -> V_67 = V_68 ;
V_54 = 0 ;
V_153 = V_6 -> V_169 ;
V_154 = V_6 -> V_173 ;
if ( F_44 ( V_79 ) )
V_158 = V_174 ;
else
V_158 = V_175 ;
break;
default:
V_88 = - V_176 ;
goto V_160;
}
V_88 = F_25 ( V_6 -> V_177 , V_54 ,
V_6 -> V_178 ) ;
if ( F_59 ( V_88 ) )
goto V_160;
V_29 -> V_70 = V_88 ;
if ( V_6 -> V_80 == V_81 ) {
V_29 -> V_123 = F_60 ( & V_6 -> V_123 ) ;
V_29 -> V_123 %= V_6 -> V_179 ;
} else {
V_29 -> V_123 = V_29 -> V_70 ;
}
V_118 = (struct V_117 ) {
. V_180 = V_181 . V_180 ,
. V_153 = V_153 ,
. V_154 = V_154 ,
. V_182 = & V_183 ,
. V_184 = V_6 -> V_8 ,
} ;
V_64 -> V_6 = V_6 ;
V_156 = F_61 ( V_158 , & V_118 , V_64 ) ;
if ( ! V_156 ) {
V_88 = - V_44 ;
goto V_185;
}
V_181 . V_180 = V_118 . V_180 ;
F_51 ( V_64 , & V_118 ) ;
V_86 = V_6 -> V_186 [ V_6 -> V_187 + V_29 -> V_123 ] ;
V_88 = F_62 ( V_86 , F_46 , V_188 ,
L_10 , V_4 ) ;
if ( F_59 ( V_88 ) ) {
F_19 ( V_6 -> V_8 , L_11 ,
V_29 -> V_123 , V_86 ) ;
V_29 -> V_123 = V_189 ;
}
F_63 ( & V_64 -> V_159 ) ;
V_64 -> V_156 = V_156 ;
return 0 ;
V_185:
V_64 -> V_6 = NULL ;
V_160:
F_63 ( & V_64 -> V_159 ) ;
return V_88 ;
}
static void F_64 ( struct V_2 * V_4 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_64 -> V_6 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
void T_2 * V_93 ;
int V_86 ;
if ( ! V_6 )
return;
V_93 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
F_32 ( 0 , V_93 + V_152 ) ;
if ( V_29 -> V_123 != V_189 ) {
V_86 = V_6 -> V_186 [ V_6 -> V_187 + V_29 -> V_123 ] ;
F_65 ( V_86 , V_4 ) ;
}
if ( V_64 -> V_156 )
F_66 ( V_64 -> V_156 ) ;
F_28 ( V_6 -> V_177 , V_29 -> V_70 ) ;
}
static struct V_2 * F_67 ( unsigned type )
{
struct V_1 * V_64 ;
if ( type != V_190 )
return NULL ;
V_64 = F_68 ( sizeof( * V_64 ) , V_43 ) ;
if ( ! V_64 )
return NULL ;
F_69 ( & V_64 -> V_159 ) ;
F_70 ( & V_64 -> V_191 ) ;
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
struct V_192 * V_193 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( ! ( V_6 -> V_47 & V_48 ) )
return 0 ;
if ( V_29 -> V_193 )
return - V_34 ;
V_193 = F_74 ( V_29 -> V_45 , sizeof( * V_193 ) , V_43 ) ;
if ( ! V_193 ) {
F_19 ( V_6 -> V_8 , L_12 ,
V_29 -> V_45 ) ;
return - V_44 ;
}
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
int V_56 = F_25 ( V_6 -> V_194 , 0 ,
V_6 -> V_49 ) ;
if ( F_59 ( V_56 ) ) {
F_19 ( V_6 -> V_8 , L_13 ) ;
goto V_195;
}
V_193 [ V_7 ] = (struct V_192 ) {
. V_56 = V_56 ,
. V_196 = 0 ,
. V_197 = V_29 -> V_51 [ V_7 ] ,
} ;
}
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_76 = V_198 | V_193 [ V_7 ] . V_197 << V_199 |
V_193 [ V_7 ] . V_196 << V_200 ;
F_32 ( V_76 , V_58 + F_75 ( V_193 [ V_7 ] . V_56 ) ) ;
}
V_29 -> V_193 = V_193 ;
return 0 ;
V_195:
while ( -- V_7 >= 0 )
F_28 ( V_6 -> V_194 , V_193 [ V_7 ] . V_56 ) ;
F_72 ( V_193 ) ;
return - V_42 ;
}
static void F_76 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_7 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
struct V_192 * V_193 = V_29 -> V_193 ;
if ( ! V_193 )
return;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_6 V_56 = V_193 [ V_7 ] . V_56 ;
F_32 ( ~ V_198 , V_58 + F_75 ( V_56 ) ) ;
F_28 ( V_6 -> V_194 , V_56 ) ;
}
V_29 -> V_193 = NULL ;
F_72 ( V_193 ) ;
}
static int F_77 ( struct V_1 * V_64 ,
struct V_28 * V_29 )
{
int V_7 , V_88 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
V_88 = F_73 ( V_6 , V_29 ) ;
if ( V_88 )
return V_88 == - V_34 ? 0 : V_88 ;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_56 , V_201 ;
V_56 = V_29 -> V_193 ? V_29 -> V_193 [ V_7 ] . V_56 : V_29 -> V_51 [ V_7 ] ;
V_201 = V_202 |
( V_64 -> V_29 . V_70 << V_203 ) ;
F_32 ( V_201 , V_58 + F_78 ( V_56 ) ) ;
}
return 0 ;
}
static void F_79 ( struct V_1 * V_64 ,
struct V_28 * V_29 )
{
int V_7 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( ( V_6 -> V_47 & V_48 ) && ! V_29 -> V_193 )
return;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_56 = V_29 -> V_193 ? V_29 -> V_193 [ V_7 ] . V_56 : V_29 -> V_51 [ V_7 ] ;
F_32 ( V_204 ,
V_58 + F_78 ( V_56 ) ) ;
}
F_76 ( V_6 , V_29 ) ;
}
static int F_80 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
int V_88 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 ;
struct V_28 * V_29 ;
V_6 = F_21 ( V_8 ) ;
if ( ! V_6 ) {
F_19 ( V_8 , L_14 ) ;
return - V_205 ;
}
if ( V_8 -> V_206 . V_207 ) {
F_19 ( V_8 , L_15 ) ;
return - V_34 ;
}
V_88 = F_57 ( V_4 , V_6 ) ;
if ( F_59 ( V_88 ) )
return V_88 ;
if ( V_64 -> V_6 != V_6 ) {
F_19 ( V_8 ,
L_16 ,
F_81 ( V_64 -> V_6 -> V_8 ) , F_81 ( V_6 -> V_8 ) ) ;
return - V_176 ;
}
V_29 = F_11 ( V_8 ) ;
if ( ! V_29 )
return - V_208 ;
V_88 = F_77 ( V_64 , V_29 ) ;
if ( ! V_88 )
V_8 -> V_206 . V_207 = V_4 ;
return V_88 ;
}
static void F_82 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_28 * V_29 ;
V_29 = F_11 ( V_8 ) ;
if ( ! V_29 )
return;
V_8 -> V_206 . V_207 = NULL ;
F_79 ( V_64 , V_29 ) ;
}
static int F_83 ( struct V_2 * V_4 , unsigned long V_73 ,
T_7 V_209 , T_3 V_74 , int V_210 )
{
int V_88 ;
unsigned long V_87 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_155 * V_211 = V_64 -> V_156 ;
if ( ! V_211 )
return - V_208 ;
F_84 ( & V_64 -> V_191 , V_87 ) ;
V_88 = V_211 -> V_53 ( V_211 , V_73 , V_209 , V_74 , V_210 ) ;
F_85 ( & V_64 -> V_191 , V_87 ) ;
return V_88 ;
}
static T_3 F_86 ( struct V_2 * V_4 , unsigned long V_73 ,
T_3 V_74 )
{
T_3 V_88 ;
unsigned long V_87 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_155 * V_211 = V_64 -> V_156 ;
if ( ! V_211 )
return 0 ;
F_84 ( & V_64 -> V_191 , V_87 ) ;
V_88 = V_211 -> V_212 ( V_211 , V_73 , V_74 ) ;
F_85 ( & V_64 -> V_191 , V_87 ) ;
return V_88 ;
}
static T_7 F_87 ( struct V_2 * V_4 ,
T_8 V_73 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_64 -> V_6 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_155 * V_211 = V_64 -> V_156 ;
struct V_15 * V_8 = V_6 -> V_8 ;
void T_2 * V_93 ;
T_5 V_213 ;
V_82 V_214 ;
unsigned long V_215 ;
V_93 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_215 = V_73 & ~ 0xfffUL ;
if ( V_6 -> V_80 == V_83 )
F_55 ( V_215 , V_93 + V_216 ) ;
else
F_32 ( V_215 , V_93 + V_216 ) ;
if ( F_88 ( V_93 + V_217 , V_213 ,
! ( V_213 & V_218 ) , 5 , 50 ) ) {
F_19 ( V_8 ,
L_17 ,
& V_73 ) ;
return V_211 -> V_219 ( V_211 , V_73 ) ;
}
V_214 = F_33 ( V_93 + V_220 ) ;
V_214 |= ( ( V_82 ) F_33 ( V_93 + V_221 ) ) << 32 ;
if ( V_214 & V_222 ) {
F_19 ( V_8 , L_18 ) ;
F_19 ( V_8 , L_19 , V_214 ) ;
return 0 ;
}
return ( V_214 & F_89 ( 39 , 12 ) ) | ( V_73 & 0xfff ) ;
}
static T_7 F_90 ( struct V_2 * V_4 ,
T_8 V_73 )
{
T_7 V_88 ;
unsigned long V_87 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_155 * V_211 = V_64 -> V_156 ;
if ( ! V_211 )
return 0 ;
F_84 ( & V_64 -> V_191 , V_87 ) ;
if ( V_64 -> V_6 -> V_47 & V_223 &&
V_64 -> V_162 == V_165 ) {
V_88 = F_87 ( V_4 , V_73 ) ;
} else {
V_88 = V_211 -> V_219 ( V_211 , V_73 ) ;
}
F_85 ( & V_64 -> V_191 , V_87 ) ;
return V_88 ;
}
static bool F_91 ( enum V_224 V_225 )
{
switch ( V_225 ) {
case V_226 :
return true ;
case V_227 :
return true ;
case V_228 :
return true ;
default:
return false ;
}
}
static int F_92 ( struct V_229 * V_230 , T_1 V_231 , void * V_232 )
{
* ( ( T_1 * ) V_232 ) = V_231 ;
return 0 ;
}
static void F_93 ( void * V_232 )
{
F_72 ( V_232 ) ;
}
static int F_94 ( struct V_229 * V_230 ,
struct V_30 * V_31 )
{
struct V_28 * V_29 ;
T_1 V_233 ;
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
F_96 ( V_230 , F_92 , & V_233 ) ;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 )
if ( V_29 -> V_51 [ V_7 ] == V_233 )
break;
if ( V_7 == V_29 -> V_45 )
V_29 -> V_51 [ V_29 -> V_45 ++ ] = V_233 ;
return 0 ;
}
static int F_97 ( struct V_15 * V_8 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = F_21 ( V_8 ) ;
struct V_20 * V_25 ;
if ( ! V_6 )
return - V_208 ;
V_25 = F_10 ( V_6 , V_8 -> V_9 ) ;
if ( ! V_25 )
return - V_208 ;
F_95 ( V_31 , & V_25 -> V_29 , NULL ) ;
return 0 ;
}
static int F_98 ( struct V_15 * V_8 )
{
struct V_30 * V_31 ;
V_31 = F_99 ( V_8 ) ;
if ( F_100 ( V_31 ) )
return F_101 ( V_31 ) ;
return 0 ;
}
static void F_102 ( struct V_15 * V_8 )
{
F_103 ( V_8 ) ;
}
static struct V_30 * F_104 ( struct V_15 * V_8 )
{
struct V_30 * V_31 ;
int V_88 ;
if ( F_7 ( V_8 ) )
V_31 = F_105 ( V_8 ) ;
else
V_31 = F_106 ( V_8 ) ;
if ( F_100 ( V_31 ) )
return V_31 ;
if ( F_7 ( V_8 ) )
V_88 = F_94 ( F_8 ( V_8 ) , V_31 ) ;
else
V_88 = F_97 ( V_8 , V_31 ) ;
if ( V_88 ) {
F_14 ( V_31 ) ;
V_31 = F_107 ( V_88 ) ;
}
return V_31 ;
}
static int F_108 ( struct V_2 * V_4 ,
enum V_234 V_235 , void * V_232 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
switch ( V_235 ) {
case V_236 :
* ( int * ) V_232 = ( V_64 -> V_162 == V_172 ) ;
return 0 ;
default:
return - V_208 ;
}
}
static int F_109 ( struct V_2 * V_4 ,
enum V_234 V_235 , void * V_232 )
{
int V_88 = 0 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
F_58 ( & V_64 -> V_159 ) ;
switch ( V_235 ) {
case V_236 :
if ( V_64 -> V_6 ) {
V_88 = - V_237 ;
goto V_160;
}
if ( * ( int * ) V_232 )
V_64 -> V_162 = V_172 ;
else
V_64 -> V_162 = V_165 ;
break;
default:
V_88 = - V_208 ;
}
V_160:
F_63 ( & V_64 -> V_159 ) ;
return V_88 ;
}
static void F_110 ( struct V_5 * V_6 )
{
void T_2 * V_58 = F_31 ( V_6 ) ;
void T_2 * V_93 ;
int V_7 = 0 ;
T_5 V_76 ;
V_76 = F_33 ( F_50 ( V_6 ) + V_113 ) ;
F_48 ( V_76 , F_50 ( V_6 ) + V_113 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_49 ; ++ V_7 ) {
F_32 ( 0 , V_58 + F_75 ( V_7 ) ) ;
F_32 ( V_204 ,
V_58 + F_78 ( V_7 ) ) ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_178 ; ++ V_7 ) {
V_93 = F_39 ( V_6 ) + F_40 ( V_6 , V_7 ) ;
F_32 ( 0 , V_93 + V_152 ) ;
F_32 ( V_95 , V_93 + V_94 ) ;
}
F_32 ( 0 , V_58 + V_238 ) ;
F_32 ( 0 , V_58 + V_239 ) ;
V_76 = F_33 ( F_50 ( V_6 ) + V_240 ) ;
V_76 |= ( V_241 | V_242 | V_243 | V_244 ) ;
V_76 |= ( V_245 | V_246 ) ;
V_76 &= ~ ( V_247 | V_248 ) ;
V_76 &= ~ V_249 ;
V_76 &= ~ ( V_250 << V_251 ) ;
F_30 ( V_6 ) ;
F_48 ( V_76 , F_50 ( V_6 ) + V_240 ) ;
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
T_5 V_197 ;
bool V_252 , V_253 ;
F_5 ( V_6 -> V_8 , L_20 ) ;
F_5 ( V_6 -> V_8 , L_21 , V_6 -> V_80 ) ;
V_197 = F_33 ( V_58 + V_254 ) ;
if ( V_255 == 1 )
V_197 &= ~ ( V_256 | V_257 ) ;
else if ( V_255 == 2 )
V_197 &= ~ ( V_258 | V_257 ) ;
if ( V_197 & V_258 ) {
V_6 -> V_47 |= V_161 ;
F_5 ( V_6 -> V_8 , L_22 ) ;
}
if ( V_197 & V_256 ) {
V_6 -> V_47 |= V_164 ;
F_5 ( V_6 -> V_8 , L_23 ) ;
}
if ( V_197 & V_257 ) {
V_6 -> V_47 |= V_259 ;
F_5 ( V_6 -> V_8 , L_24 ) ;
}
if ( ! ( V_6 -> V_47 &
( V_161 | V_164 ) ) ) {
F_19 ( V_6 -> V_8 , L_25 ) ;
return - V_208 ;
}
if ( ( V_197 & V_258 ) && ( ( V_6 -> V_80 == 1 ) || ! ( V_197 & V_260 ) ) ) {
V_6 -> V_47 |= V_223 ;
F_5 ( V_6 -> V_8 , L_26 ) ;
}
V_252 = F_113 ( V_6 -> V_8 -> V_9 ) ;
V_253 = ! ! ( V_197 & V_261 ) ;
if ( V_252 )
V_6 -> V_47 |= V_262 ;
if ( V_252 || V_253 )
F_5 ( V_6 -> V_8 , L_27 ,
V_252 ? L_28 : L_29 ) ;
if ( V_252 != V_253 )
F_5 ( V_6 -> V_8 ,
L_30 ) ;
if ( V_197 & V_263 ) {
T_5 V_264 , V_233 , V_196 ;
V_6 -> V_47 |= V_48 ;
V_6 -> V_49 = ( V_197 >> V_265 ) &
V_266 ;
if ( V_6 -> V_49 == 0 ) {
F_19 ( V_6 -> V_8 ,
L_31 ) ;
return - V_208 ;
}
V_264 = V_267 << V_200 ;
V_264 |= ( V_268 << V_199 ) ;
F_32 ( V_264 , V_58 + F_75 ( 0 ) ) ;
V_264 = F_33 ( V_58 + F_75 ( 0 ) ) ;
V_196 = ( V_264 >> V_200 ) & V_267 ;
V_233 = ( V_264 >> V_199 ) & V_268 ;
if ( ( V_196 & V_233 ) != V_233 ) {
F_19 ( V_6 -> V_8 ,
L_32 ,
V_196 , V_233 ) ;
return - V_208 ;
}
F_5 ( V_6 -> V_8 ,
L_33 ,
V_6 -> V_49 , V_196 ) ;
} else {
V_6 -> V_49 = ( V_197 >> V_269 ) &
V_270 ;
}
V_197 = F_33 ( V_58 + V_271 ) ;
V_6 -> V_272 = ( V_197 & V_273 ) ? 16 : 12 ;
V_74 = 1 << ( ( ( V_197 >> V_274 ) & V_275 ) + 1 ) ;
V_74 *= 2 << V_6 -> V_272 ;
if ( V_6 -> V_74 != V_74 )
F_114 ( V_6 -> V_8 ,
L_34 ,
V_74 , V_6 -> V_74 ) ;
V_6 -> V_167 = ( V_197 >> V_276 ) & V_277 ;
V_6 -> V_178 = ( V_197 >> V_278 ) & V_279 ;
if ( V_6 -> V_167 > V_6 -> V_178 ) {
F_19 ( V_6 -> V_8 , L_35 ) ;
return - V_208 ;
}
F_5 ( V_6 -> V_8 , L_36 ,
V_6 -> V_178 , V_6 -> V_167 ) ;
V_197 = F_33 ( V_58 + V_280 ) ;
V_74 = F_111 ( ( V_197 >> V_281 ) & V_282 ) ;
V_6 -> V_169 = V_74 ;
V_74 = F_111 ( ( V_197 >> V_283 ) & V_284 ) ;
V_6 -> V_173 = V_74 ;
if ( F_115 ( V_6 -> V_8 , F_116 ( V_74 ) ) )
F_114 ( V_6 -> V_8 ,
L_37 ) ;
if ( V_6 -> V_80 == V_81 ) {
V_6 -> V_168 = V_6 -> V_169 ;
V_74 = V_285 | V_286 | V_287 ;
} else {
V_74 = ( V_197 >> V_288 ) & V_289 ;
V_6 -> V_168 = F_111 ( V_74 ) ;
#ifndef V_79
V_6 -> V_168 = F_117 ( 32UL , V_6 -> V_168 ) ;
#endif
V_74 = 0 ;
if ( V_197 & V_290 )
V_74 |= V_285 | V_286 | V_287 ;
if ( V_197 & V_291 )
V_74 |= V_292 | V_293 ;
if ( V_197 & V_294 )
V_74 |= V_295 | V_296 ;
}
V_181 . V_180 &= V_74 ;
F_5 ( V_6 -> V_8 , L_38 , V_74 ) ;
if ( V_6 -> V_47 & V_161 )
F_5 ( V_6 -> V_8 , L_39 ,
V_6 -> V_168 , V_6 -> V_169 ) ;
if ( V_6 -> V_47 & V_164 )
F_5 ( V_6 -> V_8 , L_40 ,
V_6 -> V_169 , V_6 -> V_173 ) ;
return 0 ;
}
static int F_118 ( struct V_297 * V_230 )
{
const struct V_298 * V_299 ;
struct V_300 * V_301 ;
struct V_5 * V_6 ;
struct V_15 * V_8 = & V_230 -> V_8 ;
struct V_22 * V_23 ;
struct V_35 V_36 ;
int V_302 , V_7 , V_303 ;
V_6 = F_20 ( V_8 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 ) {
F_19 ( V_8 , L_41 ) ;
return - V_44 ;
}
V_6 -> V_8 = V_8 ;
V_299 = F_119 ( V_304 , V_8 -> V_9 ) ;
V_6 -> V_80 = (enum V_305 ) V_299 -> V_232 ;
V_301 = F_120 ( V_230 , V_306 , 0 ) ;
V_6 -> V_69 = F_121 ( V_8 , V_301 ) ;
if ( F_100 ( V_6 -> V_69 ) )
return F_101 ( V_6 -> V_69 ) ;
V_6 -> V_74 = F_122 ( V_301 ) ;
if ( F_123 ( V_8 -> V_9 , L_42 ,
& V_6 -> V_187 ) ) {
F_19 ( V_8 , L_43 ) ;
return - V_208 ;
}
V_302 = 0 ;
while ( ( V_301 = F_120 ( V_230 , V_307 , V_302 ) ) ) {
V_302 ++ ;
if ( V_302 > V_6 -> V_187 )
V_6 -> V_179 ++ ;
}
if ( ! V_6 -> V_179 ) {
F_19 ( V_8 , L_44 ,
V_302 , V_6 -> V_187 + 1 ) ;
return - V_208 ;
}
V_6 -> V_186 = F_20 ( V_8 , sizeof( * V_6 -> V_186 ) * V_302 ,
V_43 ) ;
if ( ! V_6 -> V_186 ) {
F_19 ( V_8 , L_45 , V_302 ) ;
return - V_44 ;
}
for ( V_7 = 0 ; V_7 < V_302 ; ++ V_7 ) {
int V_86 = F_124 ( V_230 , V_7 ) ;
if ( V_86 < 0 ) {
F_19 ( V_8 , L_46 , V_7 ) ;
return - V_208 ;
}
V_6 -> V_186 [ V_7 ] = V_86 ;
}
V_303 = F_112 ( V_6 ) ;
if ( V_303 )
return V_303 ;
V_7 = 0 ;
V_6 -> V_24 = V_308 ;
while ( ! F_125 ( V_8 -> V_9 , L_47 ,
L_48 , V_7 ,
& V_36 ) ) {
V_303 = F_18 ( V_6 , V_8 , & V_36 ) ;
if ( V_303 ) {
F_19 ( V_8 , L_49 ,
V_36 . V_37 -> V_38 ) ;
goto V_309;
}
V_7 ++ ;
}
F_5 ( V_8 , L_50 , V_7 ) ;
F_3 ( V_6 ) ;
if ( V_6 -> V_80 > V_81 &&
V_6 -> V_178 != V_6 -> V_179 ) {
F_19 ( V_8 ,
L_51 ,
V_6 -> V_179 , V_6 -> V_178 ) ;
V_303 = - V_208 ;
goto V_309;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_187 ; ++ V_7 ) {
V_303 = F_62 ( V_6 -> V_186 [ V_7 ] ,
F_49 ,
V_188 ,
L_52 ,
V_6 ) ;
if ( V_303 ) {
F_19 ( V_8 , L_53 ,
V_7 , V_6 -> V_186 [ V_7 ] ) ;
goto V_310;
}
}
F_126 ( & V_6 -> V_311 ) ;
F_22 ( & V_52 ) ;
F_127 ( & V_6 -> V_311 , & V_312 ) ;
F_24 ( & V_52 ) ;
F_110 ( V_6 ) ;
return 0 ;
V_310:
while ( V_7 -- )
F_65 ( V_6 -> V_186 [ V_7 ] , V_6 ) ;
V_309:
for ( V_23 = F_128 ( & V_6 -> V_24 ) ; V_23 ; V_23 = F_129 ( V_23 ) ) {
struct V_20 * V_25
= F_2 ( V_23 , struct V_20 , V_23 ) ;
F_130 ( V_25 -> V_9 ) ;
}
return V_303 ;
}
static int F_131 ( struct V_297 * V_230 )
{
int V_7 ;
struct V_15 * V_8 = & V_230 -> V_8 ;
struct V_5 * V_313 , * V_6 = NULL ;
struct V_22 * V_23 ;
F_22 ( & V_52 ) ;
F_23 (curr, &arm_smmu_devices, list) {
if ( V_313 -> V_8 == V_8 ) {
V_6 = V_313 ;
F_132 ( & V_6 -> V_311 ) ;
break;
}
}
F_24 ( & V_52 ) ;
if ( ! V_6 )
return - V_208 ;
for ( V_23 = F_128 ( & V_6 -> V_24 ) ; V_23 ; V_23 = F_129 ( V_23 ) ) {
struct V_20 * V_25
= F_2 ( V_23 , struct V_20 , V_23 ) ;
F_130 ( V_25 -> V_9 ) ;
}
if ( ! F_133 ( V_6 -> V_177 , V_314 ) )
F_19 ( V_8 , L_54 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_187 ; ++ V_7 )
F_65 ( V_6 -> V_186 [ V_7 ] , V_6 ) ;
F_48 ( V_247 , F_50 ( V_6 ) + V_240 ) ;
return 0 ;
}
static int T_9 F_134 ( void )
{
struct V_14 * V_37 ;
int V_88 ;
V_37 = F_135 ( NULL , V_304 ) ;
if ( ! V_37 )
return 0 ;
F_130 ( V_37 ) ;
V_88 = F_136 ( & V_315 ) ;
if ( V_88 )
return V_88 ;
if ( ! F_137 ( & V_316 ) )
F_138 ( & V_316 , & V_181 ) ;
#ifdef F_139
if ( ! F_137 ( & V_317 ) )
F_138 ( & V_317 , & V_181 ) ;
#endif
#ifdef F_140
if ( ! F_137 ( & V_318 ) )
F_138 ( & V_318 , & V_181 ) ;
#endif
return 0 ;
}
static void T_10 F_141 ( void )
{
return F_142 ( & V_315 ) ;
}

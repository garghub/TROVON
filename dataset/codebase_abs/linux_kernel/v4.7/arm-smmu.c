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
F_32 ( F_41 ( V_6 , V_29 ) ,
V_69 + V_71 ) ;
} else {
V_69 = F_31 ( V_6 ) ;
F_32 ( F_42 ( V_6 , V_29 ) ,
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
if ( V_29 -> V_80 != V_81 ) {
V_73 &= ~ 12UL ;
V_73 |= F_41 ( V_6 , V_29 ) ;
do {
F_32 ( V_73 , V_77 ) ;
V_73 += V_75 ;
} while ( V_74 -= V_75 );
} else {
V_73 >>= 12 ;
V_73 |= ( V_82 ) F_41 ( V_6 , V_29 ) << 48 ;
do {
F_44 ( V_73 , V_77 ) ;
V_73 += V_75 >> 12 ;
} while ( V_74 -= V_75 );
}
} else if ( V_6 -> V_83 == V_84 ) {
V_77 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_77 += V_76 ? V_85 :
V_86 ;
V_73 >>= 12 ;
do {
F_45 ( V_73 , V_77 ) ;
V_73 += V_75 >> 12 ;
} while ( V_74 -= V_75 );
} else {
V_77 = F_31 ( V_6 ) + V_72 ;
F_32 ( F_42 ( V_6 , V_29 ) , V_77 ) ;
}
}
static T_4 F_46 ( int V_87 , void * V_8 )
{
int V_88 , V_89 ;
T_5 V_90 , V_91 , V_92 ;
unsigned long V_73 ;
struct V_2 * V_4 = V_8 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_93 ;
V_93 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_90 = F_33 ( V_93 + V_94 ) ;
if ( ! ( V_90 & V_95 ) )
return V_96 ;
if ( V_90 & V_97 )
F_35 ( V_6 -> V_8 ,
L_6 ,
V_90 ) ;
V_91 = F_33 ( V_93 + V_98 ) ;
V_88 = V_91 & V_99 ? V_100 : V_101 ;
V_73 = F_47 ( V_93 + V_102 ) ;
if ( ! F_48 ( V_4 , V_6 -> V_8 , V_73 , V_88 ) ) {
V_89 = V_103 ;
V_92 = V_104 ;
} else {
F_35 ( V_6 -> V_8 ,
L_7 ,
V_73 , V_91 , V_29 -> V_70 ) ;
V_89 = V_96 ;
V_92 = V_105 ;
}
F_49 ( V_90 , V_93 + V_94 ) ;
if ( V_90 & V_106 )
F_32 ( V_92 , V_93 + V_107 ) ;
return V_89 ;
}
static T_4 F_50 ( int V_87 , void * V_8 )
{
T_5 V_108 , V_109 , V_110 , V_111 ;
struct V_5 * V_6 = V_8 ;
void T_2 * V_58 = F_51 ( V_6 ) ;
V_108 = F_33 ( V_58 + V_112 ) ;
V_109 = F_33 ( V_58 + V_113 ) ;
V_110 = F_33 ( V_58 + V_114 ) ;
V_111 = F_33 ( V_58 + V_115 ) ;
if ( ! V_108 )
return V_96 ;
F_35 ( V_6 -> V_8 ,
L_8 ) ;
F_35 ( V_6 -> V_8 ,
L_9 ,
V_108 , V_109 , V_110 , V_111 ) ;
F_49 ( V_108 , V_58 + V_112 ) ;
return V_103 ;
}
static void F_52 ( struct V_1 * V_64 ,
struct V_116 * V_117 )
{
T_5 V_77 ;
V_82 V_118 ;
bool V_66 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_93 , * V_119 ;
V_119 = F_53 ( V_6 ) ;
V_66 = V_29 -> V_67 != V_68 ;
V_93 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
if ( V_6 -> V_83 > V_120 ) {
if ( V_29 -> V_80 == V_81 )
V_77 = V_121 ;
else
V_77 = V_122 ;
if ( V_6 -> V_47 & V_123 )
V_77 |= F_42 ( V_6 , V_29 ) << V_124 ;
F_32 ( V_77 , V_119 + F_54 ( V_29 -> V_70 ) ) ;
}
V_77 = V_29 -> V_67 ;
if ( V_6 -> V_83 < V_84 )
V_77 |= V_29 -> V_125 << V_126 ;
if ( V_66 ) {
V_77 |= ( V_127 << V_128 ) |
( V_129 << V_130 ) ;
} else if ( ! ( V_6 -> V_47 & V_123 ) ) {
V_77 |= F_42 ( V_6 , V_29 ) << V_131 ;
}
F_32 ( V_77 , V_119 + F_55 ( V_29 -> V_70 ) ) ;
if ( V_66 ) {
V_118 = V_117 -> V_132 . V_133 [ 0 ] ;
V_118 |= ( ( V_82 ) F_41 ( V_6 , V_29 ) ) << V_134 ;
F_44 ( V_118 , V_93 + V_135 ) ;
V_118 = V_117 -> V_132 . V_133 [ 1 ] ;
V_118 |= ( ( V_82 ) F_41 ( V_6 , V_29 ) ) << V_134 ;
F_44 ( V_118 , V_93 + V_136 ) ;
} else {
V_118 = V_117 -> V_137 . V_138 ;
F_44 ( V_118 , V_93 + V_135 ) ;
}
if ( V_66 ) {
V_77 = V_117 -> V_132 . V_139 ;
F_32 ( V_77 , V_93 + V_140 ) ;
if ( V_6 -> V_83 > V_120 ) {
V_77 = V_117 -> V_132 . V_139 >> 32 ;
V_77 |= V_141 ;
F_32 ( V_77 , V_93 + V_142 ) ;
}
} else {
V_77 = V_117 -> V_137 . V_143 ;
F_32 ( V_77 , V_93 + V_140 ) ;
}
if ( V_66 ) {
V_77 = V_117 -> V_132 . V_144 [ 0 ] ;
F_32 ( V_77 , V_93 + V_145 ) ;
V_77 = V_117 -> V_132 . V_144 [ 1 ] ;
F_32 ( V_77 , V_93 + V_146 ) ;
}
V_77 = V_147 | V_148 | V_149 | V_150 | V_151 ;
if ( V_66 )
V_77 |= V_152 ;
#ifdef F_56
V_77 |= V_153 ;
#endif
F_32 ( V_77 , V_93 + V_154 ) ;
}
static int F_57 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
int V_87 , V_54 , V_89 = 0 ;
unsigned long V_155 , V_156 ;
struct V_157 * V_158 ;
struct V_116 V_117 ;
enum V_159 V_80 ;
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
if ( V_6 -> V_47 & V_168 )
V_29 -> V_80 = V_169 ;
if ( ( F_59 ( V_170 ) || V_29 -> V_80 == V_171 ) &&
( V_6 -> V_47 & ( V_172 |
V_173 |
V_174 ) ) )
V_29 -> V_80 = V_81 ;
if ( V_29 -> V_80 == V_171 ) {
V_89 = - V_175 ;
goto V_161;
}
switch ( V_64 -> V_164 ) {
case V_167 :
V_29 -> V_67 = V_176 ;
V_54 = V_6 -> V_177 ;
V_155 = V_6 -> V_178 ;
V_156 = V_6 -> V_179 ;
if ( V_29 -> V_80 == V_81 ) {
V_80 = V_180 ;
} else {
V_80 = V_181 ;
V_155 = F_60 ( V_155 , 32UL ) ;
V_156 = F_60 ( V_156 , 40UL ) ;
}
break;
case V_182 :
case V_165 :
V_29 -> V_67 = V_68 ;
V_54 = 0 ;
V_155 = V_6 -> V_179 ;
V_156 = V_6 -> V_183 ;
if ( V_29 -> V_80 == V_81 ) {
V_80 = V_184 ;
} else {
V_80 = V_185 ;
V_155 = F_60 ( V_155 , 40UL ) ;
V_156 = F_60 ( V_156 , 40UL ) ;
}
break;
default:
V_89 = - V_175 ;
goto V_161;
}
V_89 = F_25 ( V_6 -> V_186 , V_54 ,
V_6 -> V_187 ) ;
if ( V_89 < 0 )
goto V_161;
V_29 -> V_70 = V_89 ;
if ( V_6 -> V_83 < V_84 ) {
V_29 -> V_125 = F_61 ( & V_6 -> V_125 ) ;
V_29 -> V_125 %= V_6 -> V_188 ;
} else {
V_29 -> V_125 = V_29 -> V_70 ;
}
V_117 = (struct V_116 ) {
. V_189 = V_6 -> V_189 ,
. V_155 = V_155 ,
. V_156 = V_156 ,
. V_190 = & V_191 ,
. V_192 = V_6 -> V_8 ,
} ;
V_64 -> V_6 = V_6 ;
V_158 = F_62 ( V_80 , & V_117 , V_64 ) ;
if ( ! V_158 ) {
V_89 = - V_44 ;
goto V_193;
}
V_4 -> V_189 = V_117 . V_189 ;
F_52 ( V_64 , & V_117 ) ;
V_87 = V_6 -> V_194 [ V_6 -> V_195 + V_29 -> V_125 ] ;
V_89 = F_63 ( V_87 , F_46 , V_196 ,
L_10 , V_4 ) ;
if ( V_89 < 0 ) {
F_19 ( V_6 -> V_8 , L_11 ,
V_29 -> V_125 , V_87 ) ;
V_29 -> V_125 = V_197 ;
}
F_64 ( & V_64 -> V_160 ) ;
V_64 -> V_158 = V_158 ;
return 0 ;
V_193:
V_64 -> V_6 = NULL ;
V_161:
F_64 ( & V_64 -> V_160 ) ;
return V_89 ;
}
static void F_65 ( struct V_2 * V_4 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_64 -> V_6 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
void T_2 * V_93 ;
int V_87 ;
if ( ! V_6 || V_4 -> type == V_162 )
return;
V_93 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
F_32 ( 0 , V_93 + V_154 ) ;
if ( V_29 -> V_125 != V_197 ) {
V_87 = V_6 -> V_194 [ V_6 -> V_195 + V_29 -> V_125 ] ;
F_66 ( V_87 , V_4 ) ;
}
F_67 ( V_64 -> V_158 ) ;
F_28 ( V_6 -> V_186 , V_29 -> V_70 ) ;
}
static struct V_2 * F_68 ( unsigned type )
{
struct V_1 * V_64 ;
if ( type != V_198 && type != V_162 )
return NULL ;
V_64 = F_69 ( sizeof( * V_64 ) , V_43 ) ;
if ( ! V_64 )
return NULL ;
if ( type == V_162 &&
F_70 ( & V_64 -> V_4 ) ) {
F_71 ( V_64 ) ;
return NULL ;
}
F_72 ( & V_64 -> V_160 ) ;
F_73 ( & V_64 -> V_199 ) ;
return & V_64 -> V_4 ;
}
static void F_74 ( struct V_2 * V_4 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
F_75 ( V_4 ) ;
F_65 ( V_4 ) ;
F_71 ( V_64 ) ;
}
static int F_76 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_7 ;
struct V_200 * V_201 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( ! ( V_6 -> V_47 & V_48 ) )
return 0 ;
if ( V_29 -> V_201 )
return - V_34 ;
V_201 = F_77 ( V_29 -> V_45 , sizeof( * V_201 ) , V_43 ) ;
if ( ! V_201 ) {
F_19 ( V_6 -> V_8 , L_12 ,
V_29 -> V_45 ) ;
return - V_44 ;
}
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
int V_56 = F_25 ( V_6 -> V_202 , 0 ,
V_6 -> V_49 ) ;
if ( V_56 < 0 ) {
F_19 ( V_6 -> V_8 , L_13 ) ;
goto V_203;
}
V_201 [ V_7 ] = (struct V_200 ) {
. V_56 = V_56 ,
. V_204 = 0 ,
. V_205 = V_29 -> V_51 [ V_7 ] ,
} ;
}
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_77 = V_206 | V_201 [ V_7 ] . V_205 << V_207 |
V_201 [ V_7 ] . V_204 << V_208 ;
F_32 ( V_77 , V_58 + F_78 ( V_201 [ V_7 ] . V_56 ) ) ;
}
V_29 -> V_201 = V_201 ;
return 0 ;
V_203:
while ( -- V_7 >= 0 )
F_28 ( V_6 -> V_202 , V_201 [ V_7 ] . V_56 ) ;
F_71 ( V_201 ) ;
return - V_42 ;
}
static void F_79 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_7 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
struct V_200 * V_201 = V_29 -> V_201 ;
if ( ! V_201 )
return;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_6 V_56 = V_201 [ V_7 ] . V_56 ;
F_32 ( ~ V_206 , V_58 + F_78 ( V_56 ) ) ;
F_28 ( V_6 -> V_202 , V_56 ) ;
}
V_29 -> V_201 = NULL ;
F_71 ( V_201 ) ;
}
static int F_80 ( struct V_1 * V_64 ,
struct V_28 * V_29 )
{
int V_7 , V_89 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( V_64 -> V_4 . type == V_162 )
return 0 ;
V_89 = F_76 ( V_6 , V_29 ) ;
if ( V_89 )
return V_89 == - V_34 ? 0 : V_89 ;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_56 , V_209 ;
V_56 = V_29 -> V_201 ? V_29 -> V_201 [ V_7 ] . V_56 : V_29 -> V_51 [ V_7 ] ;
V_209 = V_210 | V_211 |
( V_64 -> V_29 . V_70 << V_212 ) ;
F_32 ( V_209 , V_58 + F_81 ( V_56 ) ) ;
}
return 0 ;
}
static void F_82 ( struct V_1 * V_64 ,
struct V_28 * V_29 )
{
int V_7 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( ( V_6 -> V_47 & V_48 ) && ! V_29 -> V_201 )
return;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_56 = V_29 -> V_201 ? V_29 -> V_201 [ V_7 ] . V_56 : V_29 -> V_51 [ V_7 ] ;
T_5 V_77 = V_213 ? V_214 : V_215 ;
F_32 ( V_77 , V_58 + F_81 ( V_56 ) ) ;
}
F_79 ( V_6 , V_29 ) ;
}
static void F_83 ( struct V_15 * V_8 ,
struct V_28 * V_29 )
{
struct V_2 * V_4 = V_8 -> V_216 . V_217 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
V_8 -> V_216 . V_217 = NULL ;
F_82 ( V_64 , V_29 ) ;
}
static int F_84 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
int V_89 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 ;
struct V_28 * V_29 ;
V_6 = F_21 ( V_8 ) ;
if ( ! V_6 ) {
F_19 ( V_8 , L_14 ) ;
return - V_218 ;
}
V_89 = F_57 ( V_4 , V_6 ) ;
if ( V_89 < 0 )
return V_89 ;
if ( V_64 -> V_6 != V_6 ) {
F_19 ( V_8 ,
L_15 ,
F_85 ( V_64 -> V_6 -> V_8 ) , F_85 ( V_6 -> V_8 ) ) ;
return - V_175 ;
}
V_29 = F_11 ( V_8 ) ;
if ( ! V_29 )
return - V_219 ;
if ( V_8 -> V_216 . V_217 )
F_83 ( V_8 , V_29 ) ;
V_89 = F_80 ( V_64 , V_29 ) ;
if ( ! V_89 )
V_8 -> V_216 . V_217 = V_4 ;
return V_89 ;
}
static int F_86 ( struct V_2 * V_4 , unsigned long V_73 ,
T_7 V_220 , T_3 V_74 , int V_221 )
{
int V_89 ;
unsigned long V_88 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_157 * V_222 = V_64 -> V_158 ;
if ( ! V_222 )
return - V_219 ;
F_87 ( & V_64 -> V_199 , V_88 ) ;
V_89 = V_222 -> V_53 ( V_222 , V_73 , V_220 , V_74 , V_221 ) ;
F_88 ( & V_64 -> V_199 , V_88 ) ;
return V_89 ;
}
static T_3 F_89 ( struct V_2 * V_4 , unsigned long V_73 ,
T_3 V_74 )
{
T_3 V_89 ;
unsigned long V_88 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_157 * V_222 = V_64 -> V_158 ;
if ( ! V_222 )
return 0 ;
F_87 ( & V_64 -> V_199 , V_88 ) ;
V_89 = V_222 -> V_223 ( V_222 , V_73 , V_74 ) ;
F_88 ( & V_64 -> V_199 , V_88 ) ;
return V_89 ;
}
static T_7 F_90 ( struct V_2 * V_4 ,
T_8 V_73 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_64 -> V_6 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_157 * V_222 = V_64 -> V_158 ;
struct V_15 * V_8 = V_6 -> V_8 ;
void T_2 * V_93 ;
T_5 V_224 ;
V_82 V_225 ;
unsigned long V_226 ;
V_93 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_226 = V_73 & ~ 0xfffUL ;
if ( V_6 -> V_83 == V_84 )
F_45 ( V_226 , V_93 + V_227 ) ;
else
F_32 ( V_226 , V_93 + V_227 ) ;
if ( F_91 ( V_93 + V_228 , V_224 ,
! ( V_224 & V_229 ) , 5 , 50 ) ) {
F_19 ( V_8 ,
L_16 ,
& V_73 ) ;
return V_222 -> V_230 ( V_222 , V_73 ) ;
}
V_225 = F_47 ( V_93 + V_231 ) ;
if ( V_225 & V_232 ) {
F_19 ( V_8 , L_17 ) ;
F_19 ( V_8 , L_18 , V_225 ) ;
return 0 ;
}
return ( V_225 & F_92 ( 39 , 12 ) ) | ( V_73 & 0xfff ) ;
}
static T_7 F_93 ( struct V_2 * V_4 ,
T_8 V_73 )
{
T_7 V_89 ;
unsigned long V_88 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_157 * V_222 = V_64 -> V_158 ;
if ( ! V_222 )
return 0 ;
F_87 ( & V_64 -> V_199 , V_88 ) ;
if ( V_64 -> V_6 -> V_47 & V_233 &&
V_64 -> V_164 == V_167 ) {
V_89 = F_90 ( V_4 , V_73 ) ;
} else {
V_89 = V_222 -> V_230 ( V_222 , V_73 ) ;
}
F_88 ( & V_64 -> V_199 , V_88 ) ;
return V_89 ;
}
static bool F_94 ( enum V_234 V_235 )
{
switch ( V_235 ) {
case V_236 :
return true ;
case V_237 :
return true ;
case V_238 :
return true ;
default:
return false ;
}
}
static int F_95 ( struct V_239 * V_240 , T_1 V_241 , void * V_242 )
{
* ( ( T_1 * ) V_242 ) = V_241 ;
return 0 ;
}
static void F_96 ( void * V_242 )
{
F_71 ( V_242 ) ;
}
static int F_97 ( struct V_239 * V_240 ,
struct V_30 * V_31 )
{
struct V_28 * V_29 ;
T_1 V_243 ;
int V_7 ;
V_29 = F_13 ( V_31 ) ;
if ( ! V_29 ) {
V_29 = F_69 ( sizeof( * V_29 ) , V_43 ) ;
if ( ! V_29 )
return - V_44 ;
F_98 ( V_31 , V_29 ,
F_96 ) ;
}
if ( V_29 -> V_45 >= V_41 )
return - V_42 ;
F_99 ( V_240 , F_95 , & V_243 ) ;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 )
if ( V_29 -> V_51 [ V_7 ] == V_243 )
break;
if ( V_7 == V_29 -> V_45 )
V_29 -> V_51 [ V_29 -> V_45 ++ ] = V_243 ;
return 0 ;
}
static int F_100 ( struct V_15 * V_8 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = F_21 ( V_8 ) ;
struct V_20 * V_25 ;
if ( ! V_6 )
return - V_219 ;
V_25 = F_10 ( V_6 , V_8 -> V_9 ) ;
if ( ! V_25 )
return - V_219 ;
F_98 ( V_31 , & V_25 -> V_29 , NULL ) ;
return 0 ;
}
static int F_101 ( struct V_15 * V_8 )
{
struct V_30 * V_31 ;
V_31 = F_102 ( V_8 ) ;
if ( F_103 ( V_31 ) )
return F_104 ( V_31 ) ;
F_14 ( V_31 ) ;
return 0 ;
}
static void F_105 ( struct V_15 * V_8 )
{
F_106 ( V_8 ) ;
}
static struct V_30 * F_107 ( struct V_15 * V_8 )
{
struct V_30 * V_31 ;
int V_89 ;
if ( F_7 ( V_8 ) )
V_31 = F_108 ( V_8 ) ;
else
V_31 = F_109 ( V_8 ) ;
if ( F_103 ( V_31 ) )
return V_31 ;
if ( F_7 ( V_8 ) )
V_89 = F_97 ( F_8 ( V_8 ) , V_31 ) ;
else
V_89 = F_100 ( V_8 , V_31 ) ;
if ( V_89 ) {
F_14 ( V_31 ) ;
V_31 = F_110 ( V_89 ) ;
}
return V_31 ;
}
static int F_111 ( struct V_2 * V_4 ,
enum V_244 V_245 , void * V_242 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
switch ( V_245 ) {
case V_246 :
* ( int * ) V_242 = ( V_64 -> V_164 == V_182 ) ;
return 0 ;
default:
return - V_219 ;
}
}
static int F_112 ( struct V_2 * V_4 ,
enum V_244 V_245 , void * V_242 )
{
int V_89 = 0 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
F_58 ( & V_64 -> V_160 ) ;
switch ( V_245 ) {
case V_246 :
if ( V_64 -> V_6 ) {
V_89 = - V_247 ;
goto V_161;
}
if ( * ( int * ) V_242 )
V_64 -> V_164 = V_182 ;
else
V_64 -> V_164 = V_167 ;
break;
default:
V_89 = - V_219 ;
}
V_161:
F_64 ( & V_64 -> V_160 ) ;
return V_89 ;
}
static void F_113 ( struct V_5 * V_6 )
{
void T_2 * V_58 = F_31 ( V_6 ) ;
void T_2 * V_93 ;
int V_7 = 0 ;
T_5 V_77 , V_248 ;
V_77 = F_33 ( F_51 ( V_6 ) + V_112 ) ;
F_49 ( V_77 , F_51 ( V_6 ) + V_112 ) ;
V_77 = V_213 ? V_214 : V_215 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_49 ; ++ V_7 ) {
F_32 ( 0 , V_58 + F_78 ( V_7 ) ) ;
F_32 ( V_77 , V_58 + F_81 ( V_7 ) ) ;
}
V_77 = F_33 ( V_58 + V_249 ) ;
V_248 = ( V_77 >> V_250 ) & V_251 ;
if ( ( V_6 -> V_252 == V_253 ) && ( V_248 >= 2 ) ) {
V_77 = F_33 ( V_58 + V_254 ) ;
V_77 &= ~ V_255 ;
F_32 ( V_77 , V_58 + V_254 ) ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_187 ; ++ V_7 ) {
V_93 = F_39 ( V_6 ) + F_40 ( V_6 , V_7 ) ;
F_32 ( 0 , V_93 + V_154 ) ;
F_32 ( V_95 , V_93 + V_94 ) ;
if ( V_6 -> V_252 == V_253 ) {
V_77 = F_33 ( V_93 + V_256 ) ;
V_77 &= ~ V_257 ;
F_32 ( V_77 , V_93 + V_256 ) ;
}
}
F_32 ( 0 , V_58 + V_258 ) ;
F_32 ( 0 , V_58 + V_259 ) ;
V_77 = F_33 ( F_51 ( V_6 ) + V_260 ) ;
V_77 |= ( V_261 | V_262 | V_263 | V_264 ) ;
V_77 |= ( V_265 | V_266 ) ;
V_77 &= ~ V_267 ;
if ( V_213 )
V_77 |= V_268 ;
else
V_77 &= ~ V_268 ;
V_77 &= ~ V_269 ;
V_77 &= ~ ( V_270 << V_271 ) ;
if ( V_6 -> V_47 & V_123 )
V_77 |= V_272 ;
F_30 ( V_6 ) ;
F_49 ( V_77 , F_51 ( V_6 ) + V_260 ) ;
}
static int F_114 ( int V_74 )
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
static int F_115 ( struct V_5 * V_6 )
{
unsigned long V_74 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
T_5 V_205 ;
bool V_273 , V_274 ;
F_5 ( V_6 -> V_8 , L_19 ) ;
F_5 ( V_6 -> V_8 , L_20 ,
V_6 -> V_83 == V_84 ? 2 : 1 ) ;
V_205 = F_33 ( V_58 + V_275 ) ;
if ( V_276 == 1 )
V_205 &= ~ ( V_277 | V_278 ) ;
else if ( V_276 == 2 )
V_205 &= ~ ( V_279 | V_278 ) ;
if ( V_205 & V_279 ) {
V_6 -> V_47 |= V_163 ;
F_5 ( V_6 -> V_8 , L_21 ) ;
}
if ( V_205 & V_277 ) {
V_6 -> V_47 |= V_166 ;
F_5 ( V_6 -> V_8 , L_22 ) ;
}
if ( V_205 & V_278 ) {
V_6 -> V_47 |= V_280 ;
F_5 ( V_6 -> V_8 , L_23 ) ;
}
if ( ! ( V_6 -> V_47 &
( V_163 | V_166 ) ) ) {
F_19 ( V_6 -> V_8 , L_24 ) ;
return - V_219 ;
}
if ( ( V_205 & V_279 ) &&
( ( V_6 -> V_83 < V_84 ) || ! ( V_205 & V_281 ) ) ) {
V_6 -> V_47 |= V_233 ;
F_5 ( V_6 -> V_8 , L_25 ) ;
}
V_273 = F_116 ( V_6 -> V_8 -> V_9 ) ;
V_274 = ! ! ( V_205 & V_282 ) ;
if ( V_273 )
V_6 -> V_47 |= V_283 ;
if ( V_273 || V_274 )
F_5 ( V_6 -> V_8 , L_26 ,
V_273 ? L_27 : L_28 ) ;
if ( V_273 != V_274 )
F_5 ( V_6 -> V_8 ,
L_29 ) ;
if ( V_205 & V_284 ) {
T_5 V_285 , V_243 , V_204 ;
V_6 -> V_47 |= V_48 ;
V_6 -> V_49 = ( V_205 >> V_286 ) &
V_287 ;
if ( V_6 -> V_49 == 0 ) {
F_19 ( V_6 -> V_8 ,
L_30 ) ;
return - V_219 ;
}
V_285 = V_288 << V_208 ;
V_285 |= ( V_289 << V_207 ) ;
F_32 ( V_285 , V_58 + F_78 ( 0 ) ) ;
V_285 = F_33 ( V_58 + F_78 ( 0 ) ) ;
V_204 = ( V_285 >> V_208 ) & V_288 ;
V_243 = ( V_285 >> V_207 ) & V_289 ;
if ( ( V_204 & V_243 ) != V_243 ) {
F_19 ( V_6 -> V_8 ,
L_31 ,
V_204 , V_243 ) ;
return - V_219 ;
}
F_5 ( V_6 -> V_8 ,
L_32 ,
V_6 -> V_49 , V_204 ) ;
} else {
V_6 -> V_49 = ( V_205 >> V_290 ) &
V_291 ;
}
if ( V_6 -> V_83 < V_84 || ! ( V_205 & V_292 ) ) {
V_6 -> V_47 |= V_168 ;
if ( ! ( V_205 & V_293 ) )
V_6 -> V_47 |= V_294 ;
}
V_205 = F_33 ( V_58 + V_295 ) ;
V_6 -> V_296 = ( V_205 & V_297 ) ? 16 : 12 ;
V_74 = 1 << ( ( ( V_205 >> V_298 ) & V_299 ) + 1 ) ;
V_74 *= 2 << V_6 -> V_296 ;
if ( V_6 -> V_74 != V_74 )
F_117 ( V_6 -> V_8 ,
L_33 ,
V_74 , V_6 -> V_74 ) ;
V_6 -> V_177 = ( V_205 >> V_300 ) & V_301 ;
V_6 -> V_187 = ( V_205 >> V_302 ) & V_303 ;
if ( V_6 -> V_177 > V_6 -> V_187 ) {
F_19 ( V_6 -> V_8 , L_34 ) ;
return - V_219 ;
}
F_5 ( V_6 -> V_8 , L_35 ,
V_6 -> V_187 , V_6 -> V_177 ) ;
if ( V_6 -> V_252 == V_304 ) {
V_6 -> V_305 =
F_118 ( V_6 -> V_187 ,
& V_306 ) ;
V_6 -> V_305 -= V_6 -> V_187 ;
}
V_205 = F_33 ( V_58 + V_307 ) ;
V_74 = F_114 ( ( V_205 >> V_308 ) & V_309 ) ;
V_6 -> V_179 = V_74 ;
V_74 = F_114 ( ( V_205 >> V_310 ) & V_311 ) ;
V_6 -> V_183 = V_74 ;
if ( V_205 & V_312 )
V_6 -> V_47 |= V_123 ;
if ( F_119 ( V_6 -> V_8 , F_120 ( V_74 ) ) )
F_117 ( V_6 -> V_8 ,
L_36 ) ;
if ( V_6 -> V_83 < V_84 ) {
V_6 -> V_178 = V_6 -> V_179 ;
if ( V_6 -> V_83 == V_313 )
V_6 -> V_47 |= V_172 ;
} else {
V_74 = ( V_205 >> V_314 ) & V_315 ;
V_6 -> V_178 = F_114 ( V_74 ) ;
if ( V_205 & V_316 )
V_6 -> V_47 |= V_174 ;
if ( V_205 & V_317 )
V_6 -> V_47 |= V_173 ;
if ( V_205 & V_318 )
V_6 -> V_47 |= V_172 ;
}
if ( V_6 -> V_47 & V_294 )
V_6 -> V_189 |= V_319 | V_320 | V_321 | V_322 ;
if ( V_6 -> V_47 &
( V_168 | V_174 ) )
V_6 -> V_189 |= V_319 | V_323 | V_324 ;
if ( V_6 -> V_47 & V_173 )
V_6 -> V_189 |= V_325 | V_326 ;
if ( V_6 -> V_47 & V_172 )
V_6 -> V_189 |= V_320 | V_327 ;
if ( V_328 . V_189 == - 1UL )
V_328 . V_189 = V_6 -> V_189 ;
else
V_328 . V_189 |= V_6 -> V_189 ;
F_5 ( V_6 -> V_8 , L_37 ,
V_6 -> V_189 ) ;
if ( V_6 -> V_47 & V_163 )
F_5 ( V_6 -> V_8 , L_38 ,
V_6 -> V_178 , V_6 -> V_179 ) ;
if ( V_6 -> V_47 & V_166 )
F_5 ( V_6 -> V_8 , L_39 ,
V_6 -> V_179 , V_6 -> V_183 ) ;
return 0 ;
}
static int F_121 ( struct V_329 * V_240 )
{
const struct V_330 * V_331 ;
const struct V_332 * V_242 ;
struct V_333 * V_334 ;
struct V_5 * V_6 ;
struct V_15 * V_8 = & V_240 -> V_8 ;
struct V_22 * V_23 ;
struct V_335 V_336 ;
struct V_35 * V_36 ;
int V_337 , V_7 , V_338 ;
V_6 = F_20 ( V_8 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 ) {
F_19 ( V_8 , L_40 ) ;
return - V_44 ;
}
V_6 -> V_8 = V_8 ;
V_331 = F_122 ( V_339 , V_8 -> V_9 ) ;
V_242 = V_331 -> V_242 ;
V_6 -> V_83 = V_242 -> V_83 ;
V_6 -> V_252 = V_242 -> V_252 ;
V_334 = F_123 ( V_240 , V_340 , 0 ) ;
V_6 -> V_69 = F_124 ( V_8 , V_334 ) ;
if ( F_103 ( V_6 -> V_69 ) )
return F_104 ( V_6 -> V_69 ) ;
V_6 -> V_74 = F_125 ( V_334 ) ;
if ( F_126 ( V_8 -> V_9 , L_41 ,
& V_6 -> V_195 ) ) {
F_19 ( V_8 , L_42 ) ;
return - V_219 ;
}
V_337 = 0 ;
while ( ( V_334 = F_123 ( V_240 , V_341 , V_337 ) ) ) {
V_337 ++ ;
if ( V_337 > V_6 -> V_195 )
V_6 -> V_188 ++ ;
}
if ( ! V_6 -> V_188 ) {
F_19 ( V_8 , L_43 ,
V_337 , V_6 -> V_195 + 1 ) ;
return - V_219 ;
}
V_6 -> V_194 = F_20 ( V_8 , sizeof( * V_6 -> V_194 ) * V_337 ,
V_43 ) ;
if ( ! V_6 -> V_194 ) {
F_19 ( V_8 , L_44 , V_337 ) ;
return - V_44 ;
}
for ( V_7 = 0 ; V_7 < V_337 ; ++ V_7 ) {
int V_87 = F_127 ( V_240 , V_7 ) ;
if ( V_87 < 0 ) {
F_19 ( V_8 , L_45 , V_7 ) ;
return - V_219 ;
}
V_6 -> V_194 [ V_7 ] = V_87 ;
}
V_338 = F_115 ( V_6 ) ;
if ( V_338 )
return V_338 ;
V_7 = 0 ;
V_6 -> V_24 = V_342 ;
V_338 = - V_44 ;
V_36 = F_128 ( sizeof( * V_36 ) , V_43 ) ;
if ( ! V_36 )
goto V_343;
F_129 (&it, err, dev->of_node,
L_46 , L_47 , 0 ) {
int V_57 = F_130 ( & V_336 , V_36 -> args ,
V_41 ) ;
V_36 -> V_37 = F_131 ( V_336 . V_23 ) ;
V_36 -> V_40 = V_57 ;
V_338 = F_18 ( V_6 , V_8 , V_36 ) ;
if ( V_338 ) {
F_19 ( V_8 , L_48 ,
V_36 -> V_37 -> V_38 ) ;
F_71 ( V_36 ) ;
goto V_343;
}
V_7 ++ ;
}
F_5 ( V_8 , L_49 , V_7 ) ;
F_71 ( V_36 ) ;
F_3 ( V_6 ) ;
if ( V_6 -> V_83 == V_84 &&
V_6 -> V_187 != V_6 -> V_188 ) {
F_19 ( V_8 ,
L_50 ,
V_6 -> V_188 , V_6 -> V_187 ) ;
V_338 = - V_219 ;
goto V_343;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_195 ; ++ V_7 ) {
V_338 = F_63 ( V_6 -> V_194 [ V_7 ] ,
F_50 ,
V_196 ,
L_51 ,
V_6 ) ;
if ( V_338 ) {
F_19 ( V_8 , L_52 ,
V_7 , V_6 -> V_194 [ V_7 ] ) ;
goto V_344;
}
}
F_132 ( & V_6 -> V_345 ) ;
F_22 ( & V_52 ) ;
F_133 ( & V_6 -> V_345 , & V_346 ) ;
F_24 ( & V_52 ) ;
F_113 ( V_6 ) ;
return 0 ;
V_344:
while ( V_7 -- )
F_66 ( V_6 -> V_194 [ V_7 ] , V_6 ) ;
V_343:
for ( V_23 = F_134 ( & V_6 -> V_24 ) ; V_23 ; V_23 = F_135 ( V_23 ) ) {
struct V_20 * V_25
= F_2 ( V_23 , struct V_20 , V_23 ) ;
F_136 ( V_25 -> V_9 ) ;
}
return V_338 ;
}
static int F_137 ( struct V_329 * V_240 )
{
int V_7 ;
struct V_15 * V_8 = & V_240 -> V_8 ;
struct V_5 * V_347 , * V_6 = NULL ;
struct V_22 * V_23 ;
F_22 ( & V_52 ) ;
F_23 (curr, &arm_smmu_devices, list) {
if ( V_347 -> V_8 == V_8 ) {
V_6 = V_347 ;
F_138 ( & V_6 -> V_345 ) ;
break;
}
}
F_24 ( & V_52 ) ;
if ( ! V_6 )
return - V_219 ;
for ( V_23 = F_134 ( & V_6 -> V_24 ) ; V_23 ; V_23 = F_135 ( V_23 ) ) {
struct V_20 * V_25
= F_2 ( V_23 , struct V_20 , V_23 ) ;
F_136 ( V_25 -> V_9 ) ;
}
if ( ! F_139 ( V_6 -> V_186 , V_348 ) )
F_19 ( V_8 , L_53 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_195 ; ++ V_7 )
F_66 ( V_6 -> V_194 [ V_7 ] , V_6 ) ;
F_49 ( V_267 , F_51 ( V_6 ) + V_260 ) ;
return 0 ;
}
static int T_9 F_140 ( void )
{
struct V_14 * V_37 ;
int V_89 ;
V_37 = F_141 ( NULL , V_339 ) ;
if ( ! V_37 )
return 0 ;
F_136 ( V_37 ) ;
V_89 = F_142 ( & V_349 ) ;
if ( V_89 )
return V_89 ;
if ( ! F_143 ( & V_350 ) )
F_144 ( & V_350 , & V_328 ) ;
#ifdef F_145
if ( ! F_143 ( & V_351 ) )
F_144 ( & V_351 , & V_328 ) ;
#endif
#ifdef F_146
if ( ! F_143 ( & V_352 ) )
F_144 ( & V_352 , & V_328 ) ;
#endif
return 0 ;
}
static void T_10 F_147 ( void )
{
return F_148 ( & V_349 ) ;
}

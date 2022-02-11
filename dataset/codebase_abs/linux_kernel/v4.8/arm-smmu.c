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
T_5 V_88 , V_89 ;
unsigned long V_73 ;
struct V_2 * V_4 = V_8 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_90 ;
V_90 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_88 = F_33 ( V_90 + V_91 ) ;
if ( ! ( V_88 & V_92 ) )
return V_93 ;
V_89 = F_33 ( V_90 + V_94 ) ;
V_73 = F_47 ( V_90 + V_95 ) ;
F_35 ( V_6 -> V_8 ,
L_6 ,
V_88 , V_73 , V_89 , V_29 -> V_70 ) ;
F_48 ( V_88 , V_90 + V_91 ) ;
return V_96 ;
}
static T_4 F_49 ( int V_87 , void * V_8 )
{
T_5 V_97 , V_98 , V_99 , V_100 ;
struct V_5 * V_6 = V_8 ;
void T_2 * V_58 = F_50 ( V_6 ) ;
V_97 = F_33 ( V_58 + V_101 ) ;
V_98 = F_33 ( V_58 + V_102 ) ;
V_99 = F_33 ( V_58 + V_103 ) ;
V_100 = F_33 ( V_58 + V_104 ) ;
if ( ! V_97 )
return V_93 ;
F_35 ( V_6 -> V_8 ,
L_7 ) ;
F_35 ( V_6 -> V_8 ,
L_8 ,
V_97 , V_98 , V_99 , V_100 ) ;
F_48 ( V_97 , V_58 + V_101 ) ;
return V_96 ;
}
static void F_51 ( struct V_1 * V_64 ,
struct V_105 * V_106 )
{
T_5 V_77 ;
V_82 V_107 ;
bool V_66 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_90 , * V_108 ;
V_108 = F_52 ( V_6 ) ;
V_66 = V_29 -> V_67 != V_68 ;
V_90 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
if ( V_6 -> V_83 > V_109 ) {
if ( V_29 -> V_80 == V_81 )
V_77 = V_110 ;
else
V_77 = V_111 ;
if ( V_6 -> V_47 & V_112 )
V_77 |= F_42 ( V_6 , V_29 ) << V_113 ;
F_32 ( V_77 , V_108 + F_53 ( V_29 -> V_70 ) ) ;
}
V_77 = V_29 -> V_67 ;
if ( V_6 -> V_83 < V_84 )
V_77 |= V_29 -> V_114 << V_115 ;
if ( V_66 ) {
V_77 |= ( V_116 << V_117 ) |
( V_118 << V_119 ) ;
} else if ( ! ( V_6 -> V_47 & V_112 ) ) {
V_77 |= F_42 ( V_6 , V_29 ) << V_120 ;
}
F_32 ( V_77 , V_108 + F_54 ( V_29 -> V_70 ) ) ;
if ( V_66 ) {
V_107 = V_106 -> V_121 . V_122 [ 0 ] ;
V_107 |= ( ( V_82 ) F_41 ( V_6 , V_29 ) ) << V_123 ;
F_44 ( V_107 , V_90 + V_124 ) ;
V_107 = V_106 -> V_121 . V_122 [ 1 ] ;
V_107 |= ( ( V_82 ) F_41 ( V_6 , V_29 ) ) << V_123 ;
F_44 ( V_107 , V_90 + V_125 ) ;
} else {
V_107 = V_106 -> V_126 . V_127 ;
F_44 ( V_107 , V_90 + V_124 ) ;
}
if ( V_66 ) {
V_77 = V_106 -> V_121 . V_128 ;
F_32 ( V_77 , V_90 + V_129 ) ;
if ( V_6 -> V_83 > V_109 ) {
V_77 = V_106 -> V_121 . V_128 >> 32 ;
V_77 |= V_130 ;
F_32 ( V_77 , V_90 + V_131 ) ;
}
} else {
V_77 = V_106 -> V_126 . V_132 ;
F_32 ( V_77 , V_90 + V_129 ) ;
}
if ( V_66 ) {
V_77 = V_106 -> V_121 . V_133 [ 0 ] ;
F_32 ( V_77 , V_90 + V_134 ) ;
V_77 = V_106 -> V_121 . V_133 [ 1 ] ;
F_32 ( V_77 , V_90 + V_135 ) ;
}
V_77 = V_136 | V_137 | V_138 | V_139 ;
if ( V_66 )
V_77 |= V_140 ;
#ifdef F_55
V_77 |= V_141 ;
#endif
F_32 ( V_77 , V_90 + V_142 ) ;
}
static int F_56 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
int V_87 , V_54 , V_143 = 0 ;
unsigned long V_144 , V_145 ;
struct V_146 * V_147 ;
struct V_105 V_106 ;
enum V_148 V_80 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_65 * V_29 = & V_64 -> V_29 ;
F_57 ( & V_64 -> V_149 ) ;
if ( V_64 -> V_6 )
goto V_150;
if ( V_4 -> type == V_151 ) {
V_64 -> V_6 = V_6 ;
goto V_150;
}
if ( ! ( V_6 -> V_47 & V_152 ) )
V_64 -> V_153 = V_154 ;
if ( ! ( V_6 -> V_47 & V_155 ) )
V_64 -> V_153 = V_156 ;
if ( V_6 -> V_47 & V_157 )
V_29 -> V_80 = V_158 ;
if ( ( F_58 ( V_159 ) || V_29 -> V_80 == V_160 ) &&
( V_6 -> V_47 & ( V_161 |
V_162 |
V_163 ) ) )
V_29 -> V_80 = V_81 ;
if ( V_29 -> V_80 == V_160 ) {
V_143 = - V_164 ;
goto V_150;
}
switch ( V_64 -> V_153 ) {
case V_156 :
V_29 -> V_67 = V_165 ;
V_54 = V_6 -> V_166 ;
V_144 = V_6 -> V_167 ;
V_145 = V_6 -> V_168 ;
if ( V_29 -> V_80 == V_81 ) {
V_80 = V_169 ;
} else {
V_80 = V_170 ;
V_144 = F_59 ( V_144 , 32UL ) ;
V_145 = F_59 ( V_145 , 40UL ) ;
}
break;
case V_171 :
case V_154 :
V_29 -> V_67 = V_68 ;
V_54 = 0 ;
V_144 = V_6 -> V_168 ;
V_145 = V_6 -> V_172 ;
if ( V_29 -> V_80 == V_81 ) {
V_80 = V_173 ;
} else {
V_80 = V_174 ;
V_144 = F_59 ( V_144 , 40UL ) ;
V_145 = F_59 ( V_145 , 40UL ) ;
}
break;
default:
V_143 = - V_164 ;
goto V_150;
}
V_143 = F_25 ( V_6 -> V_175 , V_54 ,
V_6 -> V_176 ) ;
if ( V_143 < 0 )
goto V_150;
V_29 -> V_70 = V_143 ;
if ( V_6 -> V_83 < V_84 ) {
V_29 -> V_114 = F_60 ( & V_6 -> V_114 ) ;
V_29 -> V_114 %= V_6 -> V_177 ;
} else {
V_29 -> V_114 = V_29 -> V_70 ;
}
V_106 = (struct V_105 ) {
. V_178 = V_6 -> V_178 ,
. V_144 = V_144 ,
. V_145 = V_145 ,
. V_179 = & V_180 ,
. V_181 = V_6 -> V_8 ,
} ;
V_64 -> V_6 = V_6 ;
V_147 = F_61 ( V_80 , & V_106 , V_64 ) ;
if ( ! V_147 ) {
V_143 = - V_44 ;
goto V_182;
}
V_4 -> V_178 = V_106 . V_178 ;
F_51 ( V_64 , & V_106 ) ;
V_87 = V_6 -> V_183 [ V_6 -> V_184 + V_29 -> V_114 ] ;
V_143 = F_62 ( V_6 -> V_8 , V_87 , F_46 ,
V_185 , L_9 , V_4 ) ;
if ( V_143 < 0 ) {
F_19 ( V_6 -> V_8 , L_10 ,
V_29 -> V_114 , V_87 ) ;
V_29 -> V_114 = V_186 ;
}
F_63 ( & V_64 -> V_149 ) ;
V_64 -> V_147 = V_147 ;
return 0 ;
V_182:
V_64 -> V_6 = NULL ;
V_150:
F_63 ( & V_64 -> V_149 ) ;
return V_143 ;
}
static void F_64 ( struct V_2 * V_4 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_64 -> V_6 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
void T_2 * V_90 ;
int V_87 ;
if ( ! V_6 || V_4 -> type == V_151 )
return;
V_90 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
F_32 ( 0 , V_90 + V_142 ) ;
if ( V_29 -> V_114 != V_186 ) {
V_87 = V_6 -> V_183 [ V_6 -> V_184 + V_29 -> V_114 ] ;
F_65 ( V_6 -> V_8 , V_87 , V_4 ) ;
}
F_66 ( V_64 -> V_147 ) ;
F_28 ( V_6 -> V_175 , V_29 -> V_70 ) ;
}
static struct V_2 * F_67 ( unsigned type )
{
struct V_1 * V_64 ;
if ( type != V_187 && type != V_151 )
return NULL ;
V_64 = F_68 ( sizeof( * V_64 ) , V_43 ) ;
if ( ! V_64 )
return NULL ;
if ( type == V_151 &&
F_69 ( & V_64 -> V_4 ) ) {
F_70 ( V_64 ) ;
return NULL ;
}
F_71 ( & V_64 -> V_149 ) ;
F_72 ( & V_64 -> V_188 ) ;
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
struct V_189 * V_190 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( ! ( V_6 -> V_47 & V_48 ) )
return 0 ;
if ( V_29 -> V_190 )
return - V_34 ;
V_190 = F_76 ( V_29 -> V_45 , sizeof( * V_190 ) , V_43 ) ;
if ( ! V_190 ) {
F_19 ( V_6 -> V_8 , L_11 ,
V_29 -> V_45 ) ;
return - V_44 ;
}
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
int V_56 = F_25 ( V_6 -> V_191 , 0 ,
V_6 -> V_49 ) ;
if ( V_56 < 0 ) {
F_19 ( V_6 -> V_8 , L_12 ) ;
goto V_192;
}
V_190 [ V_7 ] = (struct V_189 ) {
. V_56 = V_56 ,
. V_193 = 0 ,
. V_194 = V_29 -> V_51 [ V_7 ] ,
} ;
}
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_77 = V_195 | V_190 [ V_7 ] . V_194 << V_196 |
V_190 [ V_7 ] . V_193 << V_197 ;
F_32 ( V_77 , V_58 + F_77 ( V_190 [ V_7 ] . V_56 ) ) ;
}
V_29 -> V_190 = V_190 ;
return 0 ;
V_192:
while ( -- V_7 >= 0 )
F_28 ( V_6 -> V_191 , V_190 [ V_7 ] . V_56 ) ;
F_70 ( V_190 ) ;
return - V_42 ;
}
static void F_78 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_7 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
struct V_189 * V_190 = V_29 -> V_190 ;
if ( ! V_190 )
return;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_6 V_56 = V_190 [ V_7 ] . V_56 ;
F_32 ( ~ V_195 , V_58 + F_77 ( V_56 ) ) ;
F_28 ( V_6 -> V_191 , V_56 ) ;
}
V_29 -> V_190 = NULL ;
F_70 ( V_190 ) ;
}
static int F_79 ( struct V_1 * V_64 ,
struct V_28 * V_29 )
{
int V_7 , V_143 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( V_64 -> V_4 . type == V_151 )
return 0 ;
V_143 = F_75 ( V_6 , V_29 ) ;
if ( V_143 )
return V_143 == - V_34 ? 0 : V_143 ;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_56 , V_198 ;
V_56 = V_29 -> V_190 ? V_29 -> V_190 [ V_7 ] . V_56 : V_29 -> V_51 [ V_7 ] ;
V_198 = V_199 | V_200 |
( V_64 -> V_29 . V_70 << V_201 ) ;
F_32 ( V_198 , V_58 + F_80 ( V_56 ) ) ;
}
return 0 ;
}
static void F_81 ( struct V_1 * V_64 ,
struct V_28 * V_29 )
{
int V_7 ;
struct V_5 * V_6 = V_64 -> V_6 ;
void T_2 * V_58 = F_31 ( V_6 ) ;
if ( ( V_6 -> V_47 & V_48 ) && ! V_29 -> V_190 )
return;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 ) {
T_5 V_56 = V_29 -> V_190 ? V_29 -> V_190 [ V_7 ] . V_56 : V_29 -> V_51 [ V_7 ] ;
T_5 V_77 = V_202 ? V_203 : V_204 ;
F_32 ( V_77 , V_58 + F_80 ( V_56 ) ) ;
}
F_78 ( V_6 , V_29 ) ;
}
static void F_82 ( struct V_15 * V_8 ,
struct V_28 * V_29 )
{
struct V_2 * V_4 = V_8 -> V_205 . V_206 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
V_8 -> V_205 . V_206 = NULL ;
F_81 ( V_64 , V_29 ) ;
}
static int F_83 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
int V_143 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 ;
struct V_28 * V_29 ;
V_6 = F_21 ( V_8 ) ;
if ( ! V_6 ) {
F_19 ( V_8 , L_13 ) ;
return - V_207 ;
}
V_143 = F_56 ( V_4 , V_6 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( V_64 -> V_6 != V_6 ) {
F_19 ( V_8 ,
L_14 ,
F_84 ( V_64 -> V_6 -> V_8 ) , F_84 ( V_6 -> V_8 ) ) ;
return - V_164 ;
}
V_29 = F_11 ( V_8 ) ;
if ( ! V_29 )
return - V_208 ;
if ( V_8 -> V_205 . V_206 )
F_82 ( V_8 , V_29 ) ;
V_143 = F_79 ( V_64 , V_29 ) ;
if ( ! V_143 )
V_8 -> V_205 . V_206 = V_4 ;
return V_143 ;
}
static int F_85 ( struct V_2 * V_4 , unsigned long V_73 ,
T_7 V_209 , T_3 V_74 , int V_210 )
{
int V_143 ;
unsigned long V_211 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_146 * V_212 = V_64 -> V_147 ;
if ( ! V_212 )
return - V_208 ;
F_86 ( & V_64 -> V_188 , V_211 ) ;
V_143 = V_212 -> V_53 ( V_212 , V_73 , V_209 , V_74 , V_210 ) ;
F_87 ( & V_64 -> V_188 , V_211 ) ;
return V_143 ;
}
static T_3 F_88 ( struct V_2 * V_4 , unsigned long V_73 ,
T_3 V_74 )
{
T_3 V_143 ;
unsigned long V_211 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_146 * V_212 = V_64 -> V_147 ;
if ( ! V_212 )
return 0 ;
F_86 ( & V_64 -> V_188 , V_211 ) ;
V_143 = V_212 -> V_213 ( V_212 , V_73 , V_74 ) ;
F_87 ( & V_64 -> V_188 , V_211 ) ;
return V_143 ;
}
static T_7 F_89 ( struct V_2 * V_4 ,
T_8 V_73 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_64 -> V_6 ;
struct V_65 * V_29 = & V_64 -> V_29 ;
struct V_146 * V_212 = V_64 -> V_147 ;
struct V_15 * V_8 = V_6 -> V_8 ;
void T_2 * V_90 ;
T_5 V_214 ;
V_82 V_215 ;
unsigned long V_216 ;
V_90 = F_39 ( V_6 ) + F_40 ( V_6 , V_29 -> V_70 ) ;
V_216 = V_73 & ~ 0xfffUL ;
if ( V_6 -> V_83 == V_84 )
F_45 ( V_216 , V_90 + V_217 ) ;
else
F_32 ( V_216 , V_90 + V_217 ) ;
if ( F_90 ( V_90 + V_218 , V_214 ,
! ( V_214 & V_219 ) , 5 , 50 ) ) {
F_19 ( V_8 ,
L_15 ,
& V_73 ) ;
return V_212 -> V_220 ( V_212 , V_73 ) ;
}
V_215 = F_47 ( V_90 + V_221 ) ;
if ( V_215 & V_222 ) {
F_19 ( V_8 , L_16 ) ;
F_19 ( V_8 , L_17 , V_215 ) ;
return 0 ;
}
return ( V_215 & F_91 ( 39 , 12 ) ) | ( V_73 & 0xfff ) ;
}
static T_7 F_92 ( struct V_2 * V_4 ,
T_8 V_73 )
{
T_7 V_143 ;
unsigned long V_211 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_146 * V_212 = V_64 -> V_147 ;
if ( ! V_212 )
return 0 ;
F_86 ( & V_64 -> V_188 , V_211 ) ;
if ( V_64 -> V_6 -> V_47 & V_223 &&
V_64 -> V_153 == V_156 ) {
V_143 = F_89 ( V_4 , V_73 ) ;
} else {
V_143 = V_212 -> V_220 ( V_212 , V_73 ) ;
}
F_87 ( & V_64 -> V_188 , V_211 ) ;
return V_143 ;
}
static bool F_93 ( enum V_224 V_225 )
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
static int F_94 ( struct V_229 * V_230 , T_1 V_231 , void * V_232 )
{
* ( ( T_1 * ) V_232 ) = V_231 ;
return 0 ;
}
static void F_95 ( void * V_232 )
{
F_70 ( V_232 ) ;
}
static int F_96 ( struct V_229 * V_230 ,
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
F_97 ( V_31 , V_29 ,
F_95 ) ;
}
if ( V_29 -> V_45 >= V_41 )
return - V_42 ;
F_98 ( V_230 , F_94 , & V_233 ) ;
for ( V_7 = 0 ; V_7 < V_29 -> V_45 ; ++ V_7 )
if ( V_29 -> V_51 [ V_7 ] == V_233 )
break;
if ( V_7 == V_29 -> V_45 )
V_29 -> V_51 [ V_29 -> V_45 ++ ] = V_233 ;
return 0 ;
}
static int F_99 ( struct V_15 * V_8 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = F_21 ( V_8 ) ;
struct V_20 * V_25 ;
if ( ! V_6 )
return - V_208 ;
V_25 = F_10 ( V_6 , V_8 -> V_9 ) ;
if ( ! V_25 )
return - V_208 ;
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
int V_143 ;
if ( F_7 ( V_8 ) )
V_31 = F_107 ( V_8 ) ;
else
V_31 = F_108 ( V_8 ) ;
if ( F_102 ( V_31 ) )
return V_31 ;
if ( F_7 ( V_8 ) )
V_143 = F_96 ( F_8 ( V_8 ) , V_31 ) ;
else
V_143 = F_99 ( V_8 , V_31 ) ;
if ( V_143 ) {
F_14 ( V_31 ) ;
V_31 = F_109 ( V_143 ) ;
}
return V_31 ;
}
static int F_110 ( struct V_2 * V_4 ,
enum V_234 V_235 , void * V_232 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
switch ( V_235 ) {
case V_236 :
* ( int * ) V_232 = ( V_64 -> V_153 == V_171 ) ;
return 0 ;
default:
return - V_208 ;
}
}
static int F_111 ( struct V_2 * V_4 ,
enum V_234 V_235 , void * V_232 )
{
int V_143 = 0 ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
F_57 ( & V_64 -> V_149 ) ;
switch ( V_235 ) {
case V_236 :
if ( V_64 -> V_6 ) {
V_143 = - V_237 ;
goto V_150;
}
if ( * ( int * ) V_232 )
V_64 -> V_153 = V_171 ;
else
V_64 -> V_153 = V_156 ;
break;
default:
V_143 = - V_208 ;
}
V_150:
F_63 ( & V_64 -> V_149 ) ;
return V_143 ;
}
static void F_112 ( struct V_5 * V_6 )
{
void T_2 * V_58 = F_31 ( V_6 ) ;
void T_2 * V_90 ;
int V_7 = 0 ;
T_5 V_77 , V_238 ;
V_77 = F_33 ( F_50 ( V_6 ) + V_101 ) ;
F_48 ( V_77 , F_50 ( V_6 ) + V_101 ) ;
V_77 = V_202 ? V_203 : V_204 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_49 ; ++ V_7 ) {
F_32 ( 0 , V_58 + F_77 ( V_7 ) ) ;
F_32 ( V_77 , V_58 + F_80 ( V_7 ) ) ;
}
V_77 = F_33 ( V_58 + V_239 ) ;
V_238 = ( V_77 >> V_240 ) & V_241 ;
if ( ( V_6 -> V_242 == V_243 ) && ( V_238 >= 2 ) ) {
V_77 = F_33 ( V_58 + V_244 ) ;
V_77 &= ~ V_245 ;
F_32 ( V_77 , V_58 + V_244 ) ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_176 ; ++ V_7 ) {
V_90 = F_39 ( V_6 ) + F_40 ( V_6 , V_7 ) ;
F_32 ( 0 , V_90 + V_142 ) ;
F_32 ( V_92 , V_90 + V_91 ) ;
if ( V_6 -> V_242 == V_243 ) {
V_77 = F_33 ( V_90 + V_246 ) ;
V_77 &= ~ V_247 ;
F_32 ( V_77 , V_90 + V_246 ) ;
}
}
F_32 ( 0 , V_58 + V_248 ) ;
F_32 ( 0 , V_58 + V_249 ) ;
V_77 = F_33 ( F_50 ( V_6 ) + V_250 ) ;
V_77 |= ( V_251 | V_252 | V_253 | V_254 ) ;
V_77 |= ( V_255 | V_256 ) ;
V_77 &= ~ V_257 ;
if ( V_202 )
V_77 |= V_258 ;
else
V_77 &= ~ V_258 ;
V_77 &= ~ V_259 ;
V_77 &= ~ ( V_260 << V_261 ) ;
if ( V_6 -> V_47 & V_112 )
V_77 |= V_262 ;
F_30 ( V_6 ) ;
F_48 ( V_77 , F_50 ( V_6 ) + V_250 ) ;
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
T_5 V_194 ;
bool V_263 , V_264 ;
F_5 ( V_6 -> V_8 , L_18 ) ;
F_5 ( V_6 -> V_8 , L_19 ,
V_6 -> V_83 == V_84 ? 2 : 1 ) ;
V_194 = F_33 ( V_58 + V_265 ) ;
if ( V_266 == 1 )
V_194 &= ~ ( V_267 | V_268 ) ;
else if ( V_266 == 2 )
V_194 &= ~ ( V_269 | V_268 ) ;
if ( V_194 & V_269 ) {
V_6 -> V_47 |= V_152 ;
F_5 ( V_6 -> V_8 , L_20 ) ;
}
if ( V_194 & V_267 ) {
V_6 -> V_47 |= V_155 ;
F_5 ( V_6 -> V_8 , L_21 ) ;
}
if ( V_194 & V_268 ) {
V_6 -> V_47 |= V_270 ;
F_5 ( V_6 -> V_8 , L_22 ) ;
}
if ( ! ( V_6 -> V_47 &
( V_152 | V_155 ) ) ) {
F_19 ( V_6 -> V_8 , L_23 ) ;
return - V_208 ;
}
if ( ( V_194 & V_269 ) &&
( ( V_6 -> V_83 < V_84 ) || ! ( V_194 & V_271 ) ) ) {
V_6 -> V_47 |= V_223 ;
F_5 ( V_6 -> V_8 , L_24 ) ;
}
V_263 = F_115 ( V_6 -> V_8 -> V_9 ) ;
V_264 = ! ! ( V_194 & V_272 ) ;
if ( V_263 )
V_6 -> V_47 |= V_273 ;
if ( V_263 || V_264 )
F_5 ( V_6 -> V_8 , L_25 ,
V_263 ? L_26 : L_27 ) ;
if ( V_263 != V_264 )
F_5 ( V_6 -> V_8 ,
L_28 ) ;
if ( V_194 & V_274 ) {
T_5 V_275 , V_233 , V_193 ;
V_6 -> V_47 |= V_48 ;
V_6 -> V_49 = ( V_194 >> V_276 ) &
V_277 ;
if ( V_6 -> V_49 == 0 ) {
F_19 ( V_6 -> V_8 ,
L_29 ) ;
return - V_208 ;
}
V_275 = V_278 << V_197 ;
V_275 |= ( V_279 << V_196 ) ;
F_32 ( V_275 , V_58 + F_77 ( 0 ) ) ;
V_275 = F_33 ( V_58 + F_77 ( 0 ) ) ;
V_193 = ( V_275 >> V_197 ) & V_278 ;
V_233 = ( V_275 >> V_196 ) & V_279 ;
if ( ( V_193 & V_233 ) != V_233 ) {
F_19 ( V_6 -> V_8 ,
L_30 ,
V_193 , V_233 ) ;
return - V_208 ;
}
F_5 ( V_6 -> V_8 ,
L_31 ,
V_6 -> V_49 , V_193 ) ;
} else {
V_6 -> V_49 = ( V_194 >> V_280 ) &
V_281 ;
}
if ( V_6 -> V_83 < V_84 || ! ( V_194 & V_282 ) ) {
V_6 -> V_47 |= V_157 ;
if ( ! ( V_194 & V_283 ) )
V_6 -> V_47 |= V_284 ;
}
V_194 = F_33 ( V_58 + V_285 ) ;
V_6 -> V_286 = ( V_194 & V_287 ) ? 16 : 12 ;
V_74 = 1 << ( ( ( V_194 >> V_288 ) & V_289 ) + 1 ) ;
V_74 *= 2 << V_6 -> V_286 ;
if ( V_6 -> V_74 != V_74 )
F_116 ( V_6 -> V_8 ,
L_32 ,
V_74 , V_6 -> V_74 ) ;
V_6 -> V_166 = ( V_194 >> V_290 ) & V_291 ;
V_6 -> V_176 = ( V_194 >> V_292 ) & V_293 ;
if ( V_6 -> V_166 > V_6 -> V_176 ) {
F_19 ( V_6 -> V_8 , L_33 ) ;
return - V_208 ;
}
F_5 ( V_6 -> V_8 , L_34 ,
V_6 -> V_176 , V_6 -> V_166 ) ;
if ( V_6 -> V_242 == V_294 ) {
V_6 -> V_295 =
F_117 ( V_6 -> V_176 ,
& V_296 ) ;
V_6 -> V_295 -= V_6 -> V_176 ;
}
V_194 = F_33 ( V_58 + V_297 ) ;
V_74 = F_113 ( ( V_194 >> V_298 ) & V_299 ) ;
V_6 -> V_168 = V_74 ;
V_74 = F_113 ( ( V_194 >> V_300 ) & V_301 ) ;
V_6 -> V_172 = V_74 ;
if ( V_194 & V_302 )
V_6 -> V_47 |= V_112 ;
if ( F_118 ( V_6 -> V_8 , F_119 ( V_74 ) ) )
F_116 ( V_6 -> V_8 ,
L_35 ) ;
if ( V_6 -> V_83 < V_84 ) {
V_6 -> V_167 = V_6 -> V_168 ;
if ( V_6 -> V_83 == V_303 )
V_6 -> V_47 |= V_161 ;
} else {
V_74 = ( V_194 >> V_304 ) & V_305 ;
V_6 -> V_167 = F_113 ( V_74 ) ;
if ( V_194 & V_306 )
V_6 -> V_47 |= V_163 ;
if ( V_194 & V_307 )
V_6 -> V_47 |= V_162 ;
if ( V_194 & V_308 )
V_6 -> V_47 |= V_161 ;
}
if ( V_6 -> V_47 & V_284 )
V_6 -> V_178 |= V_309 | V_310 | V_311 | V_312 ;
if ( V_6 -> V_47 &
( V_157 | V_163 ) )
V_6 -> V_178 |= V_309 | V_313 | V_314 ;
if ( V_6 -> V_47 & V_162 )
V_6 -> V_178 |= V_315 | V_316 ;
if ( V_6 -> V_47 & V_161 )
V_6 -> V_178 |= V_310 | V_317 ;
if ( V_318 . V_178 == - 1UL )
V_318 . V_178 = V_6 -> V_178 ;
else
V_318 . V_178 |= V_6 -> V_178 ;
F_5 ( V_6 -> V_8 , L_36 ,
V_6 -> V_178 ) ;
if ( V_6 -> V_47 & V_152 )
F_5 ( V_6 -> V_8 , L_37 ,
V_6 -> V_167 , V_6 -> V_168 ) ;
if ( V_6 -> V_47 & V_155 )
F_5 ( V_6 -> V_8 , L_38 ,
V_6 -> V_168 , V_6 -> V_172 ) ;
return 0 ;
}
static int F_120 ( struct V_319 * V_230 )
{
const struct V_320 * V_321 ;
const struct V_322 * V_232 ;
struct V_323 * V_324 ;
struct V_5 * V_6 ;
struct V_15 * V_8 = & V_230 -> V_8 ;
struct V_22 * V_23 ;
struct V_325 V_326 ;
struct V_35 * V_36 ;
int V_327 , V_7 , V_328 ;
V_6 = F_20 ( V_8 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 ) {
F_19 ( V_8 , L_39 ) ;
return - V_44 ;
}
V_6 -> V_8 = V_8 ;
V_321 = F_121 ( V_329 , V_8 -> V_9 ) ;
V_232 = V_321 -> V_232 ;
V_6 -> V_83 = V_232 -> V_83 ;
V_6 -> V_242 = V_232 -> V_242 ;
V_324 = F_122 ( V_230 , V_330 , 0 ) ;
V_6 -> V_69 = F_123 ( V_8 , V_324 ) ;
if ( F_102 ( V_6 -> V_69 ) )
return F_103 ( V_6 -> V_69 ) ;
V_6 -> V_74 = F_124 ( V_324 ) ;
if ( F_125 ( V_8 -> V_9 , L_40 ,
& V_6 -> V_184 ) ) {
F_19 ( V_8 , L_41 ) ;
return - V_208 ;
}
V_327 = 0 ;
while ( ( V_324 = F_122 ( V_230 , V_331 , V_327 ) ) ) {
V_327 ++ ;
if ( V_327 > V_6 -> V_184 )
V_6 -> V_177 ++ ;
}
if ( ! V_6 -> V_177 ) {
F_19 ( V_8 , L_42 ,
V_327 , V_6 -> V_184 + 1 ) ;
return - V_208 ;
}
V_6 -> V_183 = F_20 ( V_8 , sizeof( * V_6 -> V_183 ) * V_327 ,
V_43 ) ;
if ( ! V_6 -> V_183 ) {
F_19 ( V_8 , L_43 , V_327 ) ;
return - V_44 ;
}
for ( V_7 = 0 ; V_7 < V_327 ; ++ V_7 ) {
int V_87 = F_126 ( V_230 , V_7 ) ;
if ( V_87 < 0 ) {
F_19 ( V_8 , L_44 , V_7 ) ;
return - V_208 ;
}
V_6 -> V_183 [ V_7 ] = V_87 ;
}
V_328 = F_114 ( V_6 ) ;
if ( V_328 )
return V_328 ;
V_7 = 0 ;
V_6 -> V_24 = V_332 ;
V_328 = - V_44 ;
V_36 = F_127 ( sizeof( * V_36 ) , V_43 ) ;
if ( ! V_36 )
goto V_333;
F_128 (&it, err, dev->of_node,
L_45 , L_46 , 0 ) {
int V_57 = F_129 ( & V_326 , V_36 -> args ,
V_41 ) ;
V_36 -> V_37 = F_130 ( V_326 . V_23 ) ;
V_36 -> V_40 = V_57 ;
V_328 = F_18 ( V_6 , V_8 , V_36 ) ;
if ( V_328 ) {
F_19 ( V_8 , L_47 ,
V_36 -> V_37 -> V_38 ) ;
F_70 ( V_36 ) ;
goto V_333;
}
V_7 ++ ;
}
F_5 ( V_8 , L_48 , V_7 ) ;
F_70 ( V_36 ) ;
F_3 ( V_6 ) ;
if ( V_6 -> V_83 == V_84 &&
V_6 -> V_176 != V_6 -> V_177 ) {
F_19 ( V_8 ,
L_49 ,
V_6 -> V_177 , V_6 -> V_176 ) ;
V_328 = - V_208 ;
goto V_333;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_184 ; ++ V_7 ) {
V_328 = F_62 ( V_6 -> V_8 , V_6 -> V_183 [ V_7 ] ,
F_49 ,
V_185 ,
L_50 ,
V_6 ) ;
if ( V_328 ) {
F_19 ( V_8 , L_51 ,
V_7 , V_6 -> V_183 [ V_7 ] ) ;
goto V_333;
}
}
F_131 ( & V_6 -> V_334 ) ;
F_22 ( & V_52 ) ;
F_132 ( & V_6 -> V_334 , & V_335 ) ;
F_24 ( & V_52 ) ;
F_112 ( V_6 ) ;
return 0 ;
V_333:
for ( V_23 = F_133 ( & V_6 -> V_24 ) ; V_23 ; V_23 = F_134 ( V_23 ) ) {
struct V_20 * V_25
= F_2 ( V_23 , struct V_20 , V_23 ) ;
F_135 ( V_25 -> V_9 ) ;
}
return V_328 ;
}
static int F_136 ( struct V_319 * V_230 )
{
int V_7 ;
struct V_15 * V_8 = & V_230 -> V_8 ;
struct V_5 * V_336 , * V_6 = NULL ;
struct V_22 * V_23 ;
F_22 ( & V_52 ) ;
F_23 (curr, &arm_smmu_devices, list) {
if ( V_336 -> V_8 == V_8 ) {
V_6 = V_336 ;
F_137 ( & V_6 -> V_334 ) ;
break;
}
}
F_24 ( & V_52 ) ;
if ( ! V_6 )
return - V_208 ;
for ( V_23 = F_133 ( & V_6 -> V_24 ) ; V_23 ; V_23 = F_134 ( V_23 ) ) {
struct V_20 * V_25
= F_2 ( V_23 , struct V_20 , V_23 ) ;
F_135 ( V_25 -> V_9 ) ;
}
if ( ! F_138 ( V_6 -> V_175 , V_337 ) )
F_19 ( V_8 , L_52 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_184 ; ++ V_7 )
F_65 ( V_6 -> V_8 , V_6 -> V_183 [ V_7 ] , V_6 ) ;
F_48 ( V_257 , F_50 ( V_6 ) + V_250 ) ;
return 0 ;
}
static int T_9 F_139 ( void )
{
struct V_14 * V_37 ;
int V_143 ;
V_37 = F_140 ( NULL , V_329 ) ;
if ( ! V_37 )
return 0 ;
F_135 ( V_37 ) ;
V_143 = F_141 ( & V_338 ) ;
if ( V_143 )
return V_143 ;
if ( ! F_142 ( & V_339 ) )
F_143 ( & V_339 , & V_318 ) ;
#ifdef F_144
if ( ! F_142 ( & V_340 ) )
F_143 ( & V_340 , & V_318 ) ;
#endif
#ifdef F_145
if ( ! F_142 ( & V_341 ) ) {
F_146 () ;
F_143 ( & V_341 , & V_318 ) ;
}
#endif
return 0 ;
}
static void T_10 F_147 ( void )
{
return F_148 ( & V_338 ) ;
}

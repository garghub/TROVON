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
static struct V_10 * F_4 ( struct V_10 * V_4 )
{
if ( F_5 ( V_4 ) ) {
struct V_11 * V_12 = F_6 ( V_4 ) -> V_12 ;
while ( ! F_7 ( V_12 ) )
V_12 = V_12 -> V_13 ;
return V_12 -> V_14 -> V_13 ;
}
return V_4 ;
}
static struct V_15 * F_8 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_2 -> V_20 . V_18 ;
while ( V_19 ) {
struct V_15 * V_21 ;
V_21 = F_9 ( V_19 , struct V_15 , V_19 ) ;
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
F_10 ( struct V_1 * V_2 , struct V_10 * V_4 )
{
struct V_15 * V_21 ;
if ( F_5 ( V_4 ) )
return V_4 -> V_25 . V_26 ;
V_21 = F_8 ( V_2 , V_4 -> V_5 ) ;
return V_21 ? & V_21 -> V_27 : NULL ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_15 * V_21 )
{
struct V_18 * * V_28 , * V_13 ;
V_28 = & V_2 -> V_20 . V_18 ;
V_13 = NULL ;
while ( * V_28 ) {
struct V_15 * V_29
= F_9 ( * V_28 , struct V_15 , V_19 ) ;
V_13 = * V_28 ;
if ( V_21 -> V_5 < V_29 -> V_5 )
V_28 = & ( ( * V_28 ) -> V_22 ) ;
else if ( V_21 -> V_5 > V_29 -> V_5 )
V_28 = & ( ( * V_28 ) -> V_23 ) ;
else
return - V_30 ;
}
F_12 ( & V_21 -> V_19 , V_13 , V_28 ) ;
F_13 ( & V_21 -> V_19 , & V_2 -> V_20 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_10 * V_4 ,
struct V_31 * V_32 )
{
int V_3 ;
struct V_15 * V_21 ;
V_21 = F_8 ( V_2 , V_32 -> V_33 ) ;
if ( V_21 ) {
F_15 ( V_4 ,
L_2 ,
V_32 -> V_33 -> V_34 ) ;
return - V_35 ;
}
if ( V_32 -> V_36 > V_37 ) {
F_15 ( V_4 ,
L_3 ,
V_37 , V_32 -> V_33 -> V_34 ) ;
return - V_38 ;
}
V_21 = F_16 ( V_4 , sizeof( * V_21 ) , V_39 ) ;
if ( ! V_21 )
return - V_40 ;
V_21 -> V_5 = V_32 -> V_33 ;
V_21 -> V_27 . V_41 = V_32 -> V_36 ;
for ( V_3 = 0 ; V_3 < V_21 -> V_27 . V_41 ; ++ V_3 ) {
T_1 V_42 = V_32 -> args [ V_3 ] ;
if ( ! ( V_2 -> V_43 & V_44 ) &&
( V_42 >= V_2 -> V_45 ) ) {
F_15 ( V_4 ,
L_4 ,
V_32 -> V_33 -> V_34 , V_2 -> V_45 ) ;
return - V_46 ;
}
V_21 -> V_27 . V_47 [ V_3 ] = V_42 ;
}
return F_11 ( V_2 , V_21 ) ;
}
static struct V_1 * F_17 ( struct V_10 * V_4 )
{
struct V_1 * V_2 ;
struct V_15 * V_21 = NULL ;
struct V_16 * V_17 = F_4 ( V_4 ) -> V_5 ;
F_18 ( & V_48 ) ;
F_19 (smmu, &arm_smmu_devices, list) {
V_21 = F_8 ( V_2 , V_17 ) ;
if ( V_21 )
break;
}
F_20 ( & V_48 ) ;
return V_21 ? V_2 : NULL ;
}
static int F_21 ( unsigned long * V_49 , int V_50 , int V_51 )
{
int V_52 ;
do {
V_52 = F_22 ( V_49 , V_51 , V_50 ) ;
if ( V_52 == V_51 )
return - V_38 ;
} while ( F_23 ( V_52 , V_49 ) );
return V_52 ;
}
static void F_24 ( unsigned long * V_49 , int V_52 )
{
F_25 ( V_52 , V_49 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
int V_53 = 0 ;
void T_2 * V_54 = F_27 ( V_2 ) ;
F_28 ( 0 , V_54 + V_55 ) ;
while ( F_29 ( V_54 + V_56 )
& V_57 ) {
F_30 () ;
if ( ++ V_53 == V_58 ) {
F_31 ( V_2 -> V_4 ,
L_5 ) ;
return;
}
F_32 ( 1 ) ;
}
}
static void F_33 ( struct V_59 * V_60 )
{
struct V_61 * V_27 = & V_60 -> V_27 ;
struct V_1 * V_2 = V_60 -> V_2 ;
void T_2 * V_62 = F_27 ( V_2 ) ;
bool V_63 = V_27 -> V_64 != V_65 ;
if ( V_63 ) {
V_62 = F_34 ( V_2 ) + F_35 ( V_2 , V_27 -> V_66 ) ;
F_28 ( F_36 ( V_27 ) ,
V_62 + V_67 ) ;
} else {
V_62 = F_27 ( V_2 ) ;
F_28 ( F_37 ( V_27 ) ,
V_62 + V_68 ) ;
}
F_26 ( V_2 ) ;
}
static T_3 F_38 ( int V_69 , void * V_4 )
{
int V_70 , V_71 ;
T_4 V_72 , V_73 , V_74 , V_75 ;
unsigned long V_76 ;
struct V_77 * V_78 = V_4 ;
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_61 * V_27 = & V_60 -> V_27 ;
struct V_1 * V_2 = V_60 -> V_2 ;
void T_2 * V_80 ;
V_80 = F_34 ( V_2 ) + F_35 ( V_2 , V_27 -> V_66 ) ;
V_72 = F_29 ( V_80 + V_81 ) ;
if ( ! ( V_72 & V_82 ) )
return V_83 ;
if ( V_72 & V_84 )
F_31 ( V_2 -> V_4 ,
L_6 ,
V_72 ) ;
V_74 = F_29 ( V_80 + V_85 ) ;
V_70 = V_74 & V_86 ? V_87 : V_88 ;
V_73 = F_29 ( V_80 + V_89 ) ;
V_76 = V_73 ;
#ifdef F_39
V_73 = F_29 ( V_80 + V_90 ) ;
V_76 |= ( ( unsigned long ) V_73 << 32 ) ;
#endif
if ( ! F_40 ( V_78 , V_2 -> V_4 , V_76 , V_70 ) ) {
V_71 = V_91 ;
V_75 = V_92 ;
} else {
F_31 ( V_2 -> V_4 ,
L_7 ,
V_76 , V_74 , V_27 -> V_66 ) ;
V_71 = V_83 ;
V_75 = V_93 ;
}
F_41 ( V_72 , V_80 + V_81 ) ;
if ( V_72 & V_94 )
F_28 ( V_75 , V_80 + V_95 ) ;
return V_71 ;
}
static T_3 F_42 ( int V_69 , void * V_4 )
{
T_4 V_96 , V_97 , V_98 , V_99 ;
struct V_1 * V_2 = V_4 ;
void T_2 * V_54 = F_43 ( V_2 ) ;
V_96 = F_29 ( V_54 + V_100 ) ;
V_97 = F_29 ( V_54 + V_101 ) ;
V_98 = F_29 ( V_54 + V_102 ) ;
V_99 = F_29 ( V_54 + V_103 ) ;
if ( ! V_96 )
return V_83 ;
F_31 ( V_2 -> V_4 ,
L_8 ) ;
F_31 ( V_2 -> V_4 ,
L_9 ,
V_96 , V_97 , V_98 , V_99 ) ;
F_41 ( V_96 , V_54 + V_100 ) ;
return V_91 ;
}
static void F_44 ( struct V_1 * V_2 , void * V_104 ,
T_5 V_105 )
{
unsigned long V_106 = ( unsigned long ) V_104 & ~ V_107 ;
if ( V_2 -> V_43 & V_108 ) {
F_45 ( V_109 ) ;
} else {
F_46 ( V_2 -> V_4 , F_47 ( V_104 ) , V_106 , V_105 ,
V_110 ) ;
}
}
static void F_48 ( struct V_59 * V_60 )
{
T_4 V_111 ;
bool V_63 ;
struct V_61 * V_27 = & V_60 -> V_27 ;
struct V_1 * V_2 = V_60 -> V_2 ;
void T_2 * V_80 , * V_54 , * V_112 ;
V_54 = F_27 ( V_2 ) ;
V_112 = F_49 ( V_2 ) ;
V_63 = V_27 -> V_64 != V_65 ;
V_80 = F_34 ( V_2 ) + F_35 ( V_2 , V_27 -> V_66 ) ;
V_111 = V_27 -> V_64 ;
if ( V_2 -> V_113 == 1 )
V_111 |= V_27 -> V_114 << V_115 ;
if ( V_63 ) {
V_111 |= ( V_116 << V_117 ) |
( V_118 << V_119 ) ;
} else {
V_111 |= F_37 ( V_27 ) << V_120 ;
}
F_28 ( V_111 , V_112 + F_50 ( V_27 -> V_66 ) ) ;
if ( V_2 -> V_113 > 1 ) {
#ifdef F_39
V_111 = V_121 ;
#else
V_111 = V_122 ;
#endif
F_28 ( V_111 ,
V_112 + F_51 ( V_27 -> V_66 ) ) ;
switch ( V_2 -> V_123 ) {
case 32 :
V_111 = ( V_124 << V_125 ) ;
break;
case 36 :
V_111 = ( V_126 << V_125 ) ;
break;
case 39 :
case 40 :
V_111 = ( V_127 << V_125 ) ;
break;
case 42 :
V_111 = ( V_128 << V_125 ) ;
break;
case 44 :
V_111 = ( V_129 << V_125 ) ;
break;
case 48 :
V_111 = ( V_130 << V_125 ) ;
break;
}
switch ( V_2 -> V_131 ) {
case 32 :
V_111 |= ( V_124 << V_132 ) ;
break;
case 36 :
V_111 |= ( V_126 << V_132 ) ;
break;
case 39 :
case 40 :
V_111 |= ( V_127 << V_132 ) ;
break;
case 42 :
V_111 |= ( V_128 << V_132 ) ;
break;
case 44 :
V_111 |= ( V_129 << V_132 ) ;
break;
case 48 :
V_111 |= ( V_130 << V_132 ) ;
break;
}
if ( V_63 )
F_28 ( V_111 , V_80 + V_133 ) ;
}
F_44 ( V_2 , V_27 -> V_134 ,
V_135 * sizeof( V_136 ) ) ;
V_111 = F_52 ( V_27 -> V_134 ) ;
F_28 ( V_111 , V_80 + V_137 ) ;
V_111 = ( V_138 ) F_52 ( V_27 -> V_134 ) >> 32 ;
if ( V_63 )
V_111 |= F_36 ( V_27 ) << V_139 ;
F_28 ( V_111 , V_80 + V_140 ) ;
if ( V_2 -> V_113 > 1 ) {
if ( V_141 == V_142 )
V_111 = V_143 ;
else
V_111 = V_144 ;
if ( ! V_63 ) {
V_111 |= ( 64 - V_2 -> V_131 ) << V_145 ;
switch ( V_2 -> V_146 ) {
case 32 :
V_111 |= ( V_124 << V_147 ) ;
break;
case 36 :
V_111 |= ( V_126 << V_147 ) ;
break;
case 40 :
V_111 |= ( V_127 << V_147 ) ;
break;
case 42 :
V_111 |= ( V_128 << V_147 ) ;
break;
case 44 :
V_111 |= ( V_129 << V_147 ) ;
break;
case 48 :
V_111 |= ( V_130 << V_147 ) ;
break;
}
} else {
V_111 |= ( 64 - V_2 -> V_123 ) << V_145 ;
}
} else {
V_111 = 0 ;
}
V_111 |= V_148 |
( V_149 << V_150 ) |
( V_151 << V_152 ) |
( V_151 << V_153 ) ;
if ( ! V_63 )
V_111 |= ( V_154 << V_155 ) ;
F_28 ( V_111 , V_80 + V_156 ) ;
if ( V_63 ) {
V_111 = ( V_157 << F_53 ( V_158 ) ) |
( V_159 << F_53 ( V_160 ) ) |
( V_161 << F_53 ( V_162 ) ) ;
F_28 ( V_111 , V_80 + V_163 ) ;
}
V_111 = V_164 | V_165 | V_166 | V_167 | V_168 ;
if ( V_63 )
V_111 |= V_169 ;
#ifdef F_54
V_111 |= V_170 ;
#endif
F_28 ( V_111 , V_80 + V_171 ) ;
}
static int F_55 ( struct V_77 * V_78 ,
struct V_1 * V_2 )
{
int V_69 , V_50 , V_71 = 0 ;
unsigned long V_70 ;
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_61 * V_27 = & V_60 -> V_27 ;
F_56 ( & V_60 -> V_172 , V_70 ) ;
if ( V_60 -> V_2 )
goto V_173;
if ( V_2 -> V_43 & V_174 ) {
V_27 -> V_64 = V_175 ;
V_50 = V_2 -> V_176 ;
} else if ( V_2 -> V_43 & V_177 ) {
V_27 -> V_64 = V_175 ;
V_50 = V_2 -> V_176 ;
} else {
V_27 -> V_64 = V_65 ;
V_50 = 0 ;
}
V_71 = F_21 ( V_2 -> V_178 , V_50 ,
V_2 -> V_179 ) ;
if ( F_57 ( V_71 ) )
goto V_173;
V_27 -> V_66 = V_71 ;
if ( V_2 -> V_113 == 1 ) {
V_27 -> V_114 = F_58 ( & V_2 -> V_114 ) ;
V_27 -> V_114 %= V_2 -> V_180 ;
} else {
V_27 -> V_114 = V_27 -> V_66 ;
}
F_59 ( V_60 -> V_2 ) = V_2 ;
F_48 ( V_60 ) ;
F_60 ( & V_60 -> V_172 , V_70 ) ;
V_69 = V_2 -> V_181 [ V_2 -> V_182 + V_27 -> V_114 ] ;
V_71 = F_61 ( V_69 , F_38 , V_183 ,
L_10 , V_78 ) ;
if ( F_57 ( V_71 ) ) {
F_15 ( V_2 -> V_4 , L_11 ,
V_27 -> V_114 , V_69 ) ;
V_27 -> V_114 = V_184 ;
}
return 0 ;
V_173:
F_60 ( & V_60 -> V_172 , V_70 ) ;
return V_71 ;
}
static void F_62 ( struct V_77 * V_78 )
{
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_61 * V_27 = & V_60 -> V_27 ;
void T_2 * V_80 ;
int V_69 ;
if ( ! V_2 )
return;
V_80 = F_34 ( V_2 ) + F_35 ( V_2 , V_27 -> V_66 ) ;
F_28 ( 0 , V_80 + V_171 ) ;
F_33 ( V_60 ) ;
if ( V_27 -> V_114 != V_184 ) {
V_69 = V_2 -> V_181 [ V_2 -> V_182 + V_27 -> V_114 ] ;
F_63 ( V_69 , V_78 ) ;
}
F_24 ( V_2 -> V_178 , V_27 -> V_66 ) ;
}
static int F_64 ( struct V_77 * V_78 )
{
struct V_59 * V_60 ;
V_136 * V_134 ;
V_60 = F_65 ( sizeof( * V_60 ) , V_39 ) ;
if ( ! V_60 )
return - V_40 ;
V_134 = F_66 ( V_135 , sizeof( V_136 ) , V_39 ) ;
if ( ! V_134 )
goto V_185;
V_60 -> V_27 . V_134 = V_134 ;
F_67 ( & V_60 -> V_172 ) ;
V_78 -> V_79 = V_60 ;
return 0 ;
V_185:
F_68 ( V_60 ) ;
return - V_40 ;
}
static void F_69 ( T_6 * V_186 )
{
T_7 V_187 = F_70 ( * V_186 ) ;
F_71 ( V_187 ) ;
}
static void F_72 ( T_8 * V_188 )
{
int V_3 ;
T_6 * V_186 , * V_189 = F_73 ( V_188 , 0 ) ;
V_186 = V_189 ;
for ( V_3 = 0 ; V_3 < V_190 ; ++ V_3 ) {
if ( F_74 ( * V_186 ) )
continue;
F_69 ( V_186 ) ;
V_186 ++ ;
}
F_75 ( NULL , V_189 ) ;
}
static void F_76 ( V_136 * V_134 )
{
int V_3 ;
T_8 * V_188 , * V_191 = F_77 ( V_134 , 0 ) ;
V_188 = V_191 ;
for ( V_3 = 0 ; V_3 < V_192 ; ++ V_3 ) {
if ( F_78 ( * V_188 ) )
continue;
F_72 ( V_188 ) ;
V_188 ++ ;
}
F_79 ( NULL , V_191 ) ;
}
static void F_80 ( struct V_59 * V_60 )
{
int V_3 ;
struct V_61 * V_27 = & V_60 -> V_27 ;
V_136 * V_134 , * V_193 = V_27 -> V_134 ;
V_134 = V_193 ;
for ( V_3 = 0 ; V_3 < V_135 ; ++ V_3 ) {
if ( F_81 ( * V_134 ) )
continue;
F_76 ( V_134 ) ;
V_134 ++ ;
}
F_68 ( V_193 ) ;
}
static void F_82 ( struct V_77 * V_78 )
{
struct V_59 * V_60 = V_78 -> V_79 ;
F_62 ( V_78 ) ;
F_80 ( V_60 ) ;
F_68 ( V_60 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_24 * V_27 )
{
int V_3 ;
struct V_194 * V_195 ;
void T_2 * V_54 = F_27 ( V_2 ) ;
if ( ! ( V_2 -> V_43 & V_44 ) )
return 0 ;
if ( V_27 -> V_195 )
return - V_30 ;
V_195 = F_84 ( V_27 -> V_41 , sizeof( * V_195 ) , V_39 ) ;
if ( ! V_195 ) {
F_15 ( V_2 -> V_4 , L_12 ,
V_27 -> V_41 ) ;
return - V_40 ;
}
for ( V_3 = 0 ; V_3 < V_27 -> V_41 ; ++ V_3 ) {
int V_52 = F_21 ( V_2 -> V_196 , 0 ,
V_2 -> V_45 ) ;
if ( F_57 ( V_52 ) ) {
F_15 ( V_2 -> V_4 , L_13 ) ;
goto V_197;
}
V_195 [ V_3 ] = (struct V_194 ) {
. V_52 = V_52 ,
. V_198 = 0 ,
. V_199 = V_27 -> V_47 [ V_3 ] ,
} ;
}
for ( V_3 = 0 ; V_3 < V_27 -> V_41 ; ++ V_3 ) {
T_4 V_111 = V_200 | V_195 [ V_3 ] . V_199 << V_201 |
V_195 [ V_3 ] . V_198 << V_202 ;
F_28 ( V_111 , V_54 + F_85 ( V_195 [ V_3 ] . V_52 ) ) ;
}
V_27 -> V_195 = V_195 ;
return 0 ;
V_197:
while ( -- V_3 >= 0 )
F_24 ( V_2 -> V_196 , V_195 [ V_3 ] . V_52 ) ;
F_68 ( V_195 ) ;
return - V_38 ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_24 * V_27 )
{
int V_3 ;
void T_2 * V_54 = F_27 ( V_2 ) ;
struct V_194 * V_195 = V_27 -> V_195 ;
if ( ! V_195 )
return;
for ( V_3 = 0 ; V_3 < V_27 -> V_41 ; ++ V_3 ) {
T_9 V_52 = V_195 [ V_3 ] . V_52 ;
F_28 ( ~ V_200 , V_54 + F_85 ( V_52 ) ) ;
F_24 ( V_2 -> V_196 , V_52 ) ;
}
V_27 -> V_195 = NULL ;
F_68 ( V_195 ) ;
}
static int F_87 ( struct V_59 * V_60 ,
struct V_24 * V_27 )
{
int V_3 , V_71 ;
struct V_1 * V_2 = V_60 -> V_2 ;
void T_2 * V_54 = F_27 ( V_2 ) ;
V_71 = F_83 ( V_2 , V_27 ) ;
if ( V_71 )
return V_71 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_41 ; ++ V_3 ) {
T_4 V_52 , V_203 ;
V_52 = V_27 -> V_195 ? V_27 -> V_195 [ V_3 ] . V_52 : V_27 -> V_47 [ V_3 ] ;
V_203 = V_204 |
( V_60 -> V_27 . V_66 << V_205 ) ;
F_28 ( V_203 , V_54 + F_88 ( V_52 ) ) ;
}
return 0 ;
}
static void F_89 ( struct V_59 * V_60 ,
struct V_24 * V_27 )
{
int V_3 ;
struct V_1 * V_2 = V_60 -> V_2 ;
void T_2 * V_54 = F_27 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_27 -> V_41 ; ++ V_3 ) {
T_4 V_52 = V_27 -> V_195 ? V_27 -> V_195 [ V_3 ] . V_52 : V_27 -> V_47 [ V_3 ] ;
F_28 ( V_206 ,
V_54 + F_88 ( V_52 ) ) ;
}
F_86 ( V_2 , V_27 ) ;
}
static int F_90 ( struct V_77 * V_78 , struct V_10 * V_4 )
{
int V_71 ;
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_1 * V_2 , * V_207 ;
struct V_24 * V_27 ;
V_2 = F_4 ( V_4 ) -> V_25 . V_26 ;
if ( ! V_2 ) {
F_15 ( V_4 , L_14 ) ;
return - V_208 ;
}
V_207 = F_59 ( V_60 -> V_2 ) ;
if ( ! V_207 ) {
V_71 = F_55 ( V_78 , V_2 ) ;
if ( F_57 ( V_71 ) )
return V_71 ;
V_207 = V_60 -> V_2 ;
}
if ( V_207 != V_2 ) {
F_15 ( V_4 ,
L_15 ,
F_91 ( V_60 -> V_2 -> V_4 ) , F_91 ( V_2 -> V_4 ) ) ;
return - V_209 ;
}
V_27 = F_10 ( V_60 -> V_2 , V_4 ) ;
if ( ! V_27 )
return - V_210 ;
return F_87 ( V_60 , V_27 ) ;
}
static void F_92 ( struct V_77 * V_78 , struct V_10 * V_4 )
{
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_24 * V_27 ;
V_27 = F_10 ( V_60 -> V_2 , V_4 ) ;
if ( V_27 )
F_89 ( V_60 , V_27 ) ;
}
static bool F_93 ( unsigned long V_104 ,
unsigned long V_51 )
{
return ! ( V_104 & ~ V_211 ) &&
( V_104 + V_212 <= V_51 ) ;
}
static int F_94 ( struct V_1 * V_2 , T_6 * V_186 ,
unsigned long V_104 , unsigned long V_51 ,
unsigned long V_213 , int V_214 , int V_215 )
{
T_10 * V_216 , * V_50 ;
T_11 V_217 = V_218 | V_219 | V_220 ;
if ( F_74 ( * V_186 ) ) {
T_7 V_187 = F_95 ( V_221 | V_222 ) ;
if ( ! V_187 )
return - V_40 ;
F_44 ( V_2 , F_96 ( V_187 ) , V_141 ) ;
F_97 ( NULL , V_186 , V_187 ) ;
F_44 ( V_2 , V_186 , sizeof( * V_186 ) ) ;
}
if ( V_215 == 1 ) {
V_217 |= V_223 | V_224 ;
if ( ! ( V_214 & V_225 ) && ( V_214 & V_226 ) )
V_217 |= V_227 ;
if ( V_214 & V_228 )
V_217 |= ( V_160 <<
V_229 ) ;
} else {
V_217 |= V_230 ;
if ( V_214 & V_226 )
V_217 |= V_231 ;
if ( V_214 & V_225 )
V_217 |= V_232 ;
if ( V_214 & V_228 )
V_217 |= V_233 ;
else
V_217 |= V_234 ;
}
if ( V_214 & V_235 )
V_217 &= ~ V_220 ;
else if ( ! ( V_214 & ( V_226 | V_225 ) ) )
V_217 &= ~ V_218 ;
V_217 |= V_236 ;
V_50 = F_98 ( * V_186 ) + F_99 ( V_104 ) ;
V_216 = V_50 ;
do {
int V_3 = 1 ;
V_217 &= ~ V_237 ;
if ( F_93 ( V_104 , V_51 ) ) {
V_3 = V_238 ;
V_217 |= V_237 ;
} else if ( F_100 ( * V_216 ) &
( V_237 | V_218 ) ) {
int V_239 ;
T_10 * V_240 ;
unsigned long V_52 = F_99 ( V_104 ) ;
V_52 &= ~ ( V_238 - 1 ) ;
V_240 = F_98 ( * V_186 ) + V_52 ;
for ( V_239 = 0 ; V_239 < V_238 ; ++ V_239 )
F_100 ( * ( V_240 + V_239 ) ) &=
~ V_237 ;
F_44 ( V_2 , V_240 ,
sizeof( * V_216 ) *
V_238 ) ;
}
do {
* V_216 = F_101 ( V_213 , F_102 ( V_217 ) ) ;
} while ( V_216 ++ , V_213 ++ , V_104 += V_141 , -- V_3 );
} while ( V_104 != V_51 );
F_44 ( V_2 , V_50 , sizeof( * V_216 ) * ( V_216 - V_50 ) ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 , T_8 * V_188 ,
unsigned long V_104 , unsigned long V_51 ,
V_138 V_241 , int V_214 , int V_215 )
{
int V_71 ;
T_6 * V_186 ;
unsigned long V_242 , V_213 = F_104 ( V_241 ) ;
#ifndef F_105
if ( F_78 ( * V_188 ) ) {
V_186 = ( T_6 * ) F_106 ( V_221 ) ;
if ( ! V_186 )
return - V_40 ;
F_44 ( V_2 , V_186 , V_141 ) ;
F_107 ( NULL , V_188 , V_186 ) ;
F_44 ( V_2 , V_188 , sizeof( * V_188 ) ) ;
V_186 += F_108 ( V_104 ) ;
} else
#endif
V_186 = F_73 ( V_188 , V_104 ) ;
do {
V_242 = F_109 ( V_104 , V_51 ) ;
V_71 = F_94 ( V_2 , V_186 , V_104 , V_242 , V_213 ,
V_214 , V_215 ) ;
V_241 += V_242 - V_104 ;
} while ( V_186 ++ , V_104 = V_242 , V_104 < V_51 );
return V_71 ;
}
static int F_110 ( struct V_1 * V_2 , V_136 * V_134 ,
unsigned long V_104 , unsigned long V_51 ,
V_138 V_241 , int V_214 , int V_215 )
{
int V_71 = 0 ;
T_8 * V_188 ;
unsigned long V_242 ;
#ifndef F_111
if ( F_81 ( * V_134 ) ) {
V_188 = ( T_8 * ) F_106 ( V_221 ) ;
if ( ! V_188 )
return - V_40 ;
F_44 ( V_2 , V_188 , V_141 ) ;
F_112 ( NULL , V_134 , V_188 ) ;
F_44 ( V_2 , V_134 , sizeof( * V_134 ) ) ;
V_188 += F_113 ( V_104 ) ;
} else
#endif
V_188 = F_77 ( V_134 , V_104 ) ;
do {
V_242 = F_114 ( V_104 , V_51 ) ;
V_71 = F_103 ( V_2 , V_188 , V_104 , V_242 , V_241 ,
V_214 , V_215 ) ;
V_241 += V_242 - V_104 ;
} while ( V_188 ++ , V_104 = V_242 , V_104 < V_51 );
return V_71 ;
}
static int F_115 ( struct V_59 * V_60 ,
unsigned long V_76 , V_138 V_243 ,
T_5 V_105 , int V_214 )
{
int V_71 , V_215 ;
unsigned long V_51 ;
V_138 V_244 , V_245 ;
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_61 * V_27 = & V_60 -> V_27 ;
V_136 * V_134 = V_27 -> V_134 ;
unsigned long V_70 ;
if ( V_27 -> V_64 == V_65 ) {
V_215 = 2 ;
V_245 = ( 1ULL << V_2 -> V_146 ) - 1 ;
} else {
V_215 = 1 ;
V_245 = ( 1ULL << V_2 -> V_131 ) - 1 ;
}
if ( ! V_134 )
return - V_209 ;
if ( V_105 & ~ V_107 )
return - V_209 ;
V_244 = ( 1ULL << V_2 -> V_123 ) - 1 ;
if ( ( V_138 ) V_76 & ~ V_244 )
return - V_46 ;
if ( V_243 & ~ V_245 )
return - V_46 ;
F_56 ( & V_60 -> V_172 , V_70 ) ;
V_134 += F_116 ( V_76 ) ;
V_51 = V_76 + V_105 ;
do {
unsigned long V_242 = F_117 ( V_76 , V_51 ) ;
V_71 = F_110 ( V_2 , V_134 , V_76 , V_242 , V_243 ,
V_214 , V_215 ) ;
if ( V_71 )
goto V_173;
V_243 += V_242 - V_76 ;
V_76 = V_242 ;
} while ( V_134 ++ , V_76 != V_51 );
V_173:
F_60 ( & V_60 -> V_172 , V_70 ) ;
return V_71 ;
}
static int F_118 ( struct V_77 * V_78 , unsigned long V_76 ,
V_138 V_243 , T_5 V_105 , int V_214 )
{
struct V_59 * V_60 = V_78 -> V_79 ;
if ( ! V_60 )
return - V_210 ;
return F_115 ( V_60 , V_76 , V_243 , V_105 , V_214 ) ;
}
static T_5 F_119 ( struct V_77 * V_78 , unsigned long V_76 ,
T_5 V_105 )
{
int V_71 ;
struct V_59 * V_60 = V_78 -> V_79 ;
V_71 = F_115 ( V_60 , V_76 , 0 , V_105 , 0 ) ;
F_33 ( V_60 ) ;
return V_71 ? 0 : V_105 ;
}
static V_138 F_120 ( struct V_77 * V_78 ,
T_12 V_76 )
{
V_136 * V_246 , V_134 ;
T_8 V_188 ;
T_6 V_186 ;
T_10 V_216 ;
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_61 * V_27 = & V_60 -> V_27 ;
V_246 = V_27 -> V_134 ;
if ( ! V_246 )
return 0 ;
V_134 = * ( V_246 + F_116 ( V_76 ) ) ;
if ( F_81 ( V_134 ) )
return 0 ;
V_188 = * F_77 ( & V_134 , V_76 ) ;
if ( F_78 ( V_188 ) )
return 0 ;
V_186 = * F_73 ( & V_188 , V_76 ) ;
if ( F_74 ( V_186 ) )
return 0 ;
V_216 = * ( F_98 ( V_186 ) + F_99 ( V_76 ) ) ;
if ( F_121 ( V_216 ) )
return 0 ;
return F_122 ( F_123 ( V_216 ) ) | ( V_76 & ~ V_107 ) ;
}
static int F_124 ( struct V_77 * V_78 ,
unsigned long V_247 )
{
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_1 * V_2 = V_60 -> V_2 ;
T_4 V_43 = V_2 ? V_2 -> V_43 : 0 ;
switch ( V_247 ) {
case V_248 :
return V_43 & V_108 ;
case V_249 :
return 1 ;
default:
return 0 ;
}
}
static int F_125 ( struct V_250 * V_251 , T_1 V_252 , void * V_253 )
{
* ( ( T_1 * ) V_253 ) = V_252 ;
return 0 ;
}
static int F_126 ( struct V_10 * V_4 )
{
struct V_1 * V_2 ;
struct V_254 * V_255 ;
int V_71 ;
if ( V_4 -> V_25 . V_26 ) {
F_127 ( V_4 , L_16 ) ;
return - V_209 ;
}
V_2 = F_17 ( V_4 ) ;
if ( ! V_2 )
return - V_210 ;
V_255 = F_128 () ;
if ( F_129 ( V_255 ) ) {
F_15 ( V_4 , L_17 ) ;
return F_130 ( V_255 ) ;
}
if ( F_5 ( V_4 ) ) {
struct V_24 * V_27 ;
struct V_250 * V_251 = F_6 ( V_4 ) ;
V_27 = F_65 ( sizeof( * V_27 ) , V_39 ) ;
if ( ! V_27 ) {
V_71 = - V_40 ;
goto V_256;
}
V_27 -> V_41 = 1 ;
F_131 ( V_251 , F_125 ,
& V_27 -> V_47 [ 0 ] ) ;
V_4 -> V_25 . V_26 = V_27 ;
} else {
V_4 -> V_25 . V_26 = V_2 ;
}
V_71 = F_132 ( V_255 , V_4 ) ;
V_256:
F_133 ( V_255 ) ;
return V_71 ;
}
static void F_134 ( struct V_10 * V_4 )
{
if ( F_5 ( V_4 ) )
F_68 ( V_4 -> V_25 . V_26 ) ;
V_4 -> V_25 . V_26 = NULL ;
F_135 ( V_4 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
void T_2 * V_54 = F_27 ( V_2 ) ;
void T_2 * V_80 ;
int V_3 = 0 ;
T_4 V_111 ;
V_111 = F_29 ( F_43 ( V_2 ) + V_100 ) ;
F_41 ( V_111 , F_43 ( V_2 ) + V_100 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_45 ; ++ V_3 ) {
F_28 ( 0 , V_54 + F_85 ( V_3 ) ) ;
F_28 ( V_206 ,
V_54 + F_88 ( V_3 ) ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_179 ; ++ V_3 ) {
V_80 = F_34 ( V_2 ) + F_35 ( V_2 , V_3 ) ;
F_28 ( 0 , V_80 + V_171 ) ;
F_28 ( V_82 , V_80 + V_81 ) ;
}
F_28 ( 0 , V_54 + V_257 ) ;
F_28 ( 0 , V_54 + V_258 ) ;
F_28 ( 0 , V_54 + V_259 ) ;
V_111 = F_29 ( F_43 ( V_2 ) + V_260 ) ;
V_111 |= ( V_261 | V_262 | V_263 | V_264 ) ;
V_111 |= ( V_265 | V_266 ) ;
V_111 &= ~ ( V_267 | V_268 ) ;
V_111 &= ~ V_269 ;
V_111 &= ~ ( V_270 << V_271 ) ;
F_26 ( V_2 ) ;
F_41 ( V_111 , F_43 ( V_2 ) + V_260 ) ;
}
static int F_137 ( int V_105 )
{
switch ( V_105 ) {
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
static int F_138 ( struct V_1 * V_2 )
{
unsigned long V_105 ;
void T_2 * V_54 = F_27 ( V_2 ) ;
T_4 V_199 ;
F_3 ( V_2 -> V_4 , L_18 ) ;
V_199 = F_29 ( V_54 + V_272 ) ;
V_2 -> V_113 = ( ( V_199 >> V_273 ) & V_274 ) + 1 ;
F_3 ( V_2 -> V_4 , L_19 , V_2 -> V_113 ) ;
V_199 = F_29 ( V_54 + V_275 ) ;
#ifndef F_39
if ( ( ( V_199 >> V_276 ) & V_277 ) == V_278 ) {
F_15 ( V_2 -> V_4 , L_20 ) ;
return - V_210 ;
}
#endif
if ( V_199 & V_279 ) {
V_2 -> V_43 |= V_177 ;
F_3 ( V_2 -> V_4 , L_21 ) ;
}
if ( V_199 & V_280 ) {
V_2 -> V_43 |= V_281 ;
F_3 ( V_2 -> V_4 , L_22 ) ;
}
if ( V_199 & V_282 ) {
V_2 -> V_43 |= V_174 ;
F_3 ( V_2 -> V_4 , L_23 ) ;
}
if ( ! ( V_2 -> V_43 &
( V_177 | V_281 |
V_174 ) ) ) {
F_15 ( V_2 -> V_4 , L_24 ) ;
return - V_210 ;
}
if ( V_199 & V_283 ) {
V_2 -> V_43 |= V_108 ;
F_3 ( V_2 -> V_4 , L_25 ) ;
}
if ( V_199 & V_284 ) {
T_4 V_285 , V_286 , V_198 ;
V_2 -> V_43 |= V_44 ;
V_2 -> V_45 = ( V_199 >> V_287 ) &
V_288 ;
if ( V_2 -> V_45 == 0 ) {
F_15 ( V_2 -> V_4 ,
L_26 ) ;
return - V_210 ;
}
V_285 = V_289 << V_202 ;
V_285 |= ( V_290 << V_201 ) ;
F_28 ( V_285 , V_54 + F_85 ( 0 ) ) ;
V_285 = F_29 ( V_54 + F_85 ( 0 ) ) ;
V_198 = ( V_285 >> V_202 ) & V_289 ;
V_286 = ( V_285 >> V_201 ) & V_290 ;
if ( ( V_198 & V_286 ) != V_286 ) {
F_15 ( V_2 -> V_4 ,
L_27 ,
V_198 , V_286 ) ;
return - V_210 ;
}
F_3 ( V_2 -> V_4 ,
L_28 ,
V_2 -> V_45 , V_198 ) ;
} else {
V_2 -> V_45 = ( V_199 >> V_291 ) &
V_292 ;
}
V_199 = F_29 ( V_54 + V_293 ) ;
V_2 -> V_294 = ( V_199 & V_295 ) ? V_296 : V_142 ;
V_105 = 1 <<
( ( ( V_199 >> V_297 ) & V_298 ) + 1 ) ;
V_105 *= ( V_2 -> V_294 << 1 ) ;
if ( V_2 -> V_105 != V_105 )
F_127 ( V_2 -> V_4 ,
L_29 ,
V_105 , V_2 -> V_105 ) ;
V_2 -> V_176 = ( V_199 >> V_299 ) &
V_300 ;
V_2 -> V_179 = ( V_199 >> V_301 ) & V_302 ;
if ( V_2 -> V_176 > V_2 -> V_179 ) {
F_15 ( V_2 -> V_4 , L_30 ) ;
return - V_210 ;
}
F_3 ( V_2 -> V_4 , L_31 ,
V_2 -> V_179 , V_2 -> V_176 ) ;
V_199 = F_29 ( V_54 + V_303 ) ;
V_105 = F_137 ( ( V_199 >> V_304 ) & V_305 ) ;
if ( V_2 -> V_43 & V_174 ) {
#ifdef F_39
V_2 -> V_131 = F_139 (unsigned long, VA_BITS, size) ;
#else
V_2 -> V_131 = F_140 ( 32UL , V_105 ) ;
#endif
} else {
V_2 -> V_131 = F_139 (unsigned long, PHYS_MASK_SHIFT,
size) ;
}
V_105 = F_137 ( ( V_199 >> V_306 ) & V_307 ) ;
V_2 -> V_146 = F_139 (unsigned long, PHYS_MASK_SHIFT, size) ;
if ( V_2 -> V_113 == 1 ) {
V_2 -> V_123 = 32 ;
} else {
#ifdef F_39
V_105 = ( V_199 >> V_308 ) & V_309 ;
V_105 = F_140 ( V_310 , F_137 ( V_105 ) ) ;
#else
V_105 = 32 ;
#endif
V_2 -> V_123 = V_105 ;
if ( ( V_141 == V_142 && ! ( V_199 & V_311 ) ) ||
( V_141 == V_296 && ! ( V_199 & V_312 ) ) ||
( V_141 != V_142 && V_141 != V_296 ) ) {
F_15 ( V_2 -> V_4 , L_32 ,
V_141 ) ;
return - V_210 ;
}
}
F_3 ( V_2 -> V_4 ,
L_33 ,
V_2 -> V_123 , V_2 -> V_131 ,
V_2 -> V_146 ) ;
return 0 ;
}
static int F_141 ( struct V_313 * V_251 )
{
struct V_314 * V_315 ;
struct V_1 * V_2 ;
struct V_10 * V_4 = & V_251 -> V_4 ;
struct V_18 * V_19 ;
struct V_31 V_32 ;
int V_316 , V_3 , V_317 ;
V_2 = F_16 ( V_4 , sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 ) {
F_15 ( V_4 , L_34 ) ;
return - V_40 ;
}
V_2 -> V_4 = V_4 ;
V_315 = F_142 ( V_251 , V_318 , 0 ) ;
V_2 -> V_62 = F_143 ( V_4 , V_315 ) ;
if ( F_129 ( V_2 -> V_62 ) )
return F_130 ( V_2 -> V_62 ) ;
V_2 -> V_105 = F_144 ( V_315 ) ;
if ( F_145 ( V_4 -> V_5 , L_35 ,
& V_2 -> V_182 ) ) {
F_15 ( V_4 , L_36 ) ;
return - V_210 ;
}
V_316 = 0 ;
while ( ( V_315 = F_142 ( V_251 , V_319 , V_316 ) ) ) {
V_316 ++ ;
if ( V_316 > V_2 -> V_182 )
V_2 -> V_180 ++ ;
}
if ( ! V_2 -> V_180 ) {
F_15 ( V_4 , L_37 ,
V_316 , V_2 -> V_182 + 1 ) ;
return - V_210 ;
}
V_2 -> V_181 = F_16 ( V_4 , sizeof( * V_2 -> V_181 ) * V_316 ,
V_39 ) ;
if ( ! V_2 -> V_181 ) {
F_15 ( V_4 , L_38 , V_316 ) ;
return - V_40 ;
}
for ( V_3 = 0 ; V_3 < V_316 ; ++ V_3 ) {
int V_69 = F_146 ( V_251 , V_3 ) ;
if ( V_69 < 0 ) {
F_15 ( V_4 , L_39 , V_3 ) ;
return - V_210 ;
}
V_2 -> V_181 [ V_3 ] = V_69 ;
}
V_317 = F_138 ( V_2 ) ;
if ( V_317 )
return V_317 ;
V_3 = 0 ;
V_2 -> V_20 = V_320 ;
while ( ! F_147 ( V_4 -> V_5 , L_40 ,
L_41 , V_3 ,
& V_32 ) ) {
V_317 = F_14 ( V_2 , V_4 , & V_32 ) ;
if ( V_317 ) {
F_15 ( V_4 , L_42 ,
V_32 . V_33 -> V_34 ) ;
goto V_321;
}
V_3 ++ ;
}
F_3 ( V_4 , L_43 , V_3 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_113 > 1 &&
V_2 -> V_179 != V_2 -> V_180 ) {
F_15 ( V_4 ,
L_44 ,
V_2 -> V_180 , V_2 -> V_179 ) ;
V_317 = - V_210 ;
goto V_321;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_182 ; ++ V_3 ) {
V_317 = F_61 ( V_2 -> V_181 [ V_3 ] ,
F_42 ,
V_183 ,
L_45 ,
V_2 ) ;
if ( V_317 ) {
F_15 ( V_4 , L_46 ,
V_3 , V_2 -> V_181 [ V_3 ] ) ;
goto V_322;
}
}
F_148 ( & V_2 -> V_323 ) ;
F_18 ( & V_48 ) ;
F_149 ( & V_2 -> V_323 , & V_324 ) ;
F_20 ( & V_48 ) ;
F_136 ( V_2 ) ;
return 0 ;
V_322:
while ( V_3 -- )
F_63 ( V_2 -> V_181 [ V_3 ] , V_2 ) ;
V_321:
for ( V_19 = F_150 ( & V_2 -> V_20 ) ; V_19 ; V_19 = F_151 ( V_19 ) ) {
struct V_15 * V_21
= F_9 ( V_19 , struct V_15 , V_19 ) ;
F_152 ( V_21 -> V_5 ) ;
}
return V_317 ;
}
static int F_153 ( struct V_313 * V_251 )
{
int V_3 ;
struct V_10 * V_4 = & V_251 -> V_4 ;
struct V_1 * V_325 , * V_2 = NULL ;
struct V_18 * V_19 ;
F_18 ( & V_48 ) ;
F_19 (curr, &arm_smmu_devices, list) {
if ( V_325 -> V_4 == V_4 ) {
V_2 = V_325 ;
F_154 ( & V_2 -> V_323 ) ;
break;
}
}
F_20 ( & V_48 ) ;
if ( ! V_2 )
return - V_210 ;
for ( V_19 = F_150 ( & V_2 -> V_20 ) ; V_19 ; V_19 = F_151 ( V_19 ) ) {
struct V_15 * V_21
= F_9 ( V_19 , struct V_15 , V_19 ) ;
F_152 ( V_21 -> V_5 ) ;
}
if ( ! F_155 ( V_2 -> V_178 , V_326 ) )
F_15 ( V_4 , L_47 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_182 ; ++ V_3 )
F_63 ( V_2 -> V_181 [ V_3 ] , V_2 ) ;
F_41 ( V_267 , F_43 ( V_2 ) + V_260 ) ;
return 0 ;
}
static int T_13 F_156 ( void )
{
int V_71 ;
V_71 = F_157 ( & V_327 ) ;
if ( V_71 )
return V_71 ;
if ( ! F_158 ( & V_328 ) )
F_159 ( & V_328 , & V_329 ) ;
#ifdef F_160
if ( ! F_158 ( & V_330 ) )
F_159 ( & V_330 , & V_329 ) ;
#endif
#ifdef F_161
if ( ! F_158 ( & V_331 ) )
F_159 ( & V_331 , & V_329 ) ;
#endif
return 0 ;
}
static void T_14 F_162 ( void )
{
return F_163 ( & V_327 ) ;
}

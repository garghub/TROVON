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
static void F_36 ( struct V_59 * V_60 )
{
struct V_61 * V_25 = & V_60 -> V_25 ;
struct V_1 * V_2 = V_60 -> V_2 ;
void T_2 * V_62 = F_30 ( V_2 ) ;
bool V_63 = V_25 -> V_64 != V_65 ;
if ( V_63 ) {
V_62 = F_37 ( V_2 ) + F_38 ( V_2 , V_25 -> V_66 ) ;
F_31 ( F_39 ( V_25 ) ,
V_62 + V_67 ) ;
} else {
V_62 = F_30 ( V_2 ) ;
F_31 ( F_40 ( V_25 ) ,
V_62 + V_68 ) ;
}
F_29 ( V_2 ) ;
}
static T_3 F_41 ( int V_69 , void * V_4 )
{
int V_70 , V_71 ;
T_4 V_72 , V_73 , V_74 , V_75 ;
unsigned long V_76 ;
struct V_77 * V_78 = V_4 ;
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_61 * V_25 = & V_60 -> V_25 ;
struct V_1 * V_2 = V_60 -> V_2 ;
void T_2 * V_80 ;
V_80 = F_37 ( V_2 ) + F_38 ( V_2 , V_25 -> V_66 ) ;
V_72 = F_32 ( V_80 + V_81 ) ;
if ( ! ( V_72 & V_82 ) )
return V_83 ;
if ( V_72 & V_84 )
F_34 ( V_2 -> V_4 ,
L_6 ,
V_72 ) ;
V_74 = F_32 ( V_80 + V_85 ) ;
V_70 = V_74 & V_86 ? V_87 : V_88 ;
V_73 = F_32 ( V_80 + V_89 ) ;
V_76 = V_73 ;
#ifdef F_42
V_73 = F_32 ( V_80 + V_90 ) ;
V_76 |= ( ( unsigned long ) V_73 << 32 ) ;
#endif
if ( ! F_43 ( V_78 , V_2 -> V_4 , V_76 , V_70 ) ) {
V_71 = V_91 ;
V_75 = V_92 ;
} else {
F_34 ( V_2 -> V_4 ,
L_7 ,
V_76 , V_74 , V_25 -> V_66 ) ;
V_71 = V_83 ;
V_75 = V_93 ;
}
F_44 ( V_72 , V_80 + V_81 ) ;
if ( V_72 & V_94 )
F_31 ( V_75 , V_80 + V_95 ) ;
return V_71 ;
}
static T_3 F_45 ( int V_69 , void * V_4 )
{
T_4 V_96 , V_97 , V_98 , V_99 ;
struct V_1 * V_2 = V_4 ;
void T_2 * V_54 = F_46 ( V_2 ) ;
V_96 = F_32 ( V_54 + V_100 ) ;
V_97 = F_32 ( V_54 + V_101 ) ;
V_98 = F_32 ( V_54 + V_102 ) ;
V_99 = F_32 ( V_54 + V_103 ) ;
if ( ! V_96 )
return V_83 ;
F_34 ( V_2 -> V_4 ,
L_8 ) ;
F_34 ( V_2 -> V_4 ,
L_9 ,
V_96 , V_97 , V_98 , V_99 ) ;
F_44 ( V_96 , V_54 + V_100 ) ;
return V_91 ;
}
static void F_47 ( struct V_1 * V_2 , void * V_104 ,
T_5 V_105 )
{
unsigned long V_106 = ( unsigned long ) V_104 & ~ V_107 ;
if ( V_2 -> V_43 & V_108 ) {
F_48 ( V_109 ) ;
} else {
F_49 ( V_2 -> V_4 , F_50 ( V_104 ) , V_106 , V_105 ,
V_110 ) ;
}
}
static void F_51 ( struct V_59 * V_60 )
{
T_4 V_111 ;
bool V_63 ;
struct V_61 * V_25 = & V_60 -> V_25 ;
struct V_1 * V_2 = V_60 -> V_2 ;
void T_2 * V_80 , * V_54 , * V_112 ;
V_54 = F_30 ( V_2 ) ;
V_112 = F_52 ( V_2 ) ;
V_63 = V_25 -> V_64 != V_65 ;
V_80 = F_37 ( V_2 ) + F_38 ( V_2 , V_25 -> V_66 ) ;
V_111 = V_25 -> V_64 ;
if ( V_2 -> V_113 == V_114 )
V_111 |= V_25 -> V_115 << V_116 ;
if ( V_63 ) {
V_111 |= ( V_117 << V_118 ) |
( V_119 << V_120 ) ;
} else {
V_111 |= F_40 ( V_25 ) << V_121 ;
}
F_31 ( V_111 , V_112 + F_53 ( V_25 -> V_66 ) ) ;
if ( V_2 -> V_113 > V_114 ) {
#ifdef F_42
V_111 = V_122 ;
#else
V_111 = V_123 ;
#endif
F_31 ( V_111 ,
V_112 + F_54 ( V_25 -> V_66 ) ) ;
switch ( V_2 -> V_124 ) {
case 32 :
V_111 = ( V_125 << V_126 ) ;
break;
case 36 :
V_111 = ( V_127 << V_126 ) ;
break;
case 39 :
case 40 :
V_111 = ( V_128 << V_126 ) ;
break;
case 42 :
V_111 = ( V_129 << V_126 ) ;
break;
case 44 :
V_111 = ( V_130 << V_126 ) ;
break;
case 48 :
V_111 = ( V_131 << V_126 ) ;
break;
}
switch ( V_2 -> V_132 ) {
case 32 :
V_111 |= ( V_125 << V_133 ) ;
break;
case 36 :
V_111 |= ( V_127 << V_133 ) ;
break;
case 39 :
case 40 :
V_111 |= ( V_128 << V_133 ) ;
break;
case 42 :
V_111 |= ( V_129 << V_133 ) ;
break;
case 44 :
V_111 |= ( V_130 << V_133 ) ;
break;
case 48 :
V_111 |= ( V_131 << V_133 ) ;
break;
}
if ( V_63 )
F_31 ( V_111 , V_80 + V_134 ) ;
}
F_47 ( V_2 , V_25 -> V_135 ,
V_136 * sizeof( V_137 ) ) ;
V_111 = F_55 ( V_25 -> V_135 ) ;
F_31 ( V_111 , V_80 + V_138 ) ;
V_111 = ( V_139 ) F_55 ( V_25 -> V_135 ) >> 32 ;
if ( V_63 )
V_111 |= F_39 ( V_25 ) << V_140 ;
F_31 ( V_111 , V_80 + V_141 ) ;
if ( V_2 -> V_113 > V_114 ) {
if ( V_142 == V_143 )
V_111 = V_144 ;
else
V_111 = V_145 ;
if ( ! V_63 ) {
V_111 |= ( 64 - V_2 -> V_146 ) << V_147 ;
switch ( V_2 -> V_148 ) {
case 32 :
V_111 |= ( V_125 << V_149 ) ;
break;
case 36 :
V_111 |= ( V_127 << V_149 ) ;
break;
case 40 :
V_111 |= ( V_128 << V_149 ) ;
break;
case 42 :
V_111 |= ( V_129 << V_149 ) ;
break;
case 44 :
V_111 |= ( V_130 << V_149 ) ;
break;
case 48 :
V_111 |= ( V_131 << V_149 ) ;
break;
}
} else {
V_111 |= ( 64 - V_2 -> V_124 ) << V_147 ;
}
} else {
V_111 = 0 ;
}
V_111 |= V_150 |
( V_151 << V_152 ) |
( V_153 << V_154 ) |
( V_153 << V_155 ) ;
if ( ! V_63 )
V_111 |= ( V_156 << V_157 ) ;
F_31 ( V_111 , V_80 + V_158 ) ;
if ( V_63 ) {
V_111 = ( V_159 << F_56 ( V_160 ) ) |
( V_161 << F_56 ( V_162 ) ) |
( V_163 << F_56 ( V_164 ) ) ;
F_31 ( V_111 , V_80 + V_165 ) ;
}
V_111 = V_166 | V_167 | V_168 | V_169 | V_170 ;
if ( V_63 )
V_111 |= V_171 ;
#ifdef F_57
V_111 |= V_172 ;
#endif
F_31 ( V_111 , V_80 + V_173 ) ;
}
static int F_58 ( struct V_77 * V_78 ,
struct V_1 * V_2 )
{
int V_69 , V_50 , V_71 = 0 ;
unsigned long V_70 ;
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_61 * V_25 = & V_60 -> V_25 ;
F_59 ( & V_60 -> V_174 , V_70 ) ;
if ( V_60 -> V_2 )
goto V_175;
if ( V_2 -> V_43 & V_176 ) {
V_25 -> V_64 = V_177 ;
V_50 = V_2 -> V_178 ;
} else if ( V_2 -> V_43 & V_179 ) {
V_25 -> V_64 = V_177 ;
V_50 = V_2 -> V_178 ;
} else {
V_25 -> V_64 = V_65 ;
V_50 = 0 ;
}
V_71 = F_24 ( V_2 -> V_180 , V_50 ,
V_2 -> V_181 ) ;
if ( F_60 ( V_71 ) )
goto V_175;
V_25 -> V_66 = V_71 ;
if ( V_2 -> V_113 == V_114 ) {
V_25 -> V_115 = F_61 ( & V_2 -> V_115 ) ;
V_25 -> V_115 %= V_2 -> V_182 ;
} else {
V_25 -> V_115 = V_25 -> V_66 ;
}
F_62 ( V_60 -> V_2 ) = V_2 ;
F_51 ( V_60 ) ;
F_63 ( & V_60 -> V_174 , V_70 ) ;
V_69 = V_2 -> V_183 [ V_2 -> V_184 + V_25 -> V_115 ] ;
V_71 = F_64 ( V_69 , F_41 , V_185 ,
L_10 , V_78 ) ;
if ( F_60 ( V_71 ) ) {
F_18 ( V_2 -> V_4 , L_11 ,
V_25 -> V_115 , V_69 ) ;
V_25 -> V_115 = V_186 ;
}
return 0 ;
V_175:
F_63 ( & V_60 -> V_174 , V_70 ) ;
return V_71 ;
}
static void F_65 ( struct V_77 * V_78 )
{
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_61 * V_25 = & V_60 -> V_25 ;
void T_2 * V_80 ;
int V_69 ;
if ( ! V_2 )
return;
V_80 = F_37 ( V_2 ) + F_38 ( V_2 , V_25 -> V_66 ) ;
F_31 ( 0 , V_80 + V_173 ) ;
F_36 ( V_60 ) ;
if ( V_25 -> V_115 != V_186 ) {
V_69 = V_2 -> V_183 [ V_2 -> V_184 + V_25 -> V_115 ] ;
F_66 ( V_69 , V_78 ) ;
}
F_27 ( V_2 -> V_180 , V_25 -> V_66 ) ;
}
static int F_67 ( struct V_77 * V_78 )
{
struct V_59 * V_60 ;
V_137 * V_135 ;
V_60 = F_68 ( sizeof( * V_60 ) , V_39 ) ;
if ( ! V_60 )
return - V_40 ;
V_135 = F_69 ( V_136 , sizeof( V_137 ) , V_39 ) ;
if ( ! V_135 )
goto V_187;
V_60 -> V_25 . V_135 = V_135 ;
F_70 ( & V_60 -> V_174 ) ;
V_78 -> V_79 = V_60 ;
return 0 ;
V_187:
F_71 ( V_60 ) ;
return - V_40 ;
}
static void F_72 ( T_6 * V_188 )
{
T_7 V_189 = F_73 ( * V_188 ) ;
F_74 ( V_189 ) ;
}
static void F_75 ( T_8 * V_190 )
{
int V_3 ;
T_6 * V_188 , * V_191 = F_76 ( V_190 , 0 ) ;
V_188 = V_191 ;
for ( V_3 = 0 ; V_3 < V_192 ; ++ V_3 ) {
if ( F_77 ( * V_188 ) )
continue;
F_72 ( V_188 ) ;
V_188 ++ ;
}
F_78 ( NULL , V_191 ) ;
}
static void F_79 ( V_137 * V_135 )
{
int V_3 ;
T_8 * V_190 , * V_193 = F_80 ( V_135 , 0 ) ;
V_190 = V_193 ;
for ( V_3 = 0 ; V_3 < V_194 ; ++ V_3 ) {
if ( F_81 ( * V_190 ) )
continue;
F_75 ( V_190 ) ;
V_190 ++ ;
}
F_82 ( NULL , V_193 ) ;
}
static void F_83 ( struct V_59 * V_60 )
{
int V_3 ;
struct V_61 * V_25 = & V_60 -> V_25 ;
V_137 * V_135 , * V_195 = V_25 -> V_135 ;
V_135 = V_195 ;
for ( V_3 = 0 ; V_3 < V_136 ; ++ V_3 ) {
if ( F_84 ( * V_135 ) )
continue;
F_79 ( V_135 ) ;
V_135 ++ ;
}
F_71 ( V_195 ) ;
}
static void F_85 ( struct V_77 * V_78 )
{
struct V_59 * V_60 = V_78 -> V_79 ;
F_65 ( V_78 ) ;
F_83 ( V_60 ) ;
F_71 ( V_60 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_3 ;
struct V_196 * V_197 ;
void T_2 * V_54 = F_30 ( V_2 ) ;
if ( ! ( V_2 -> V_43 & V_44 ) )
return 0 ;
if ( V_25 -> V_197 )
return - V_30 ;
V_197 = F_87 ( V_25 -> V_41 , sizeof( * V_197 ) , V_39 ) ;
if ( ! V_197 ) {
F_18 ( V_2 -> V_4 , L_12 ,
V_25 -> V_41 ) ;
return - V_40 ;
}
for ( V_3 = 0 ; V_3 < V_25 -> V_41 ; ++ V_3 ) {
int V_52 = F_24 ( V_2 -> V_198 , 0 ,
V_2 -> V_45 ) ;
if ( F_60 ( V_52 ) ) {
F_18 ( V_2 -> V_4 , L_13 ) ;
goto V_199;
}
V_197 [ V_3 ] = (struct V_196 ) {
. V_52 = V_52 ,
. V_200 = 0 ,
. V_201 = V_25 -> V_47 [ V_3 ] ,
} ;
}
for ( V_3 = 0 ; V_3 < V_25 -> V_41 ; ++ V_3 ) {
T_4 V_111 = V_202 | V_197 [ V_3 ] . V_201 << V_203 |
V_197 [ V_3 ] . V_200 << V_204 ;
F_31 ( V_111 , V_54 + F_88 ( V_197 [ V_3 ] . V_52 ) ) ;
}
V_25 -> V_197 = V_197 ;
return 0 ;
V_199:
while ( -- V_3 >= 0 )
F_27 ( V_2 -> V_198 , V_197 [ V_3 ] . V_52 ) ;
F_71 ( V_197 ) ;
return - V_38 ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_3 ;
void T_2 * V_54 = F_30 ( V_2 ) ;
struct V_196 * V_197 = V_25 -> V_197 ;
if ( ! V_197 )
return;
for ( V_3 = 0 ; V_3 < V_25 -> V_41 ; ++ V_3 ) {
T_9 V_52 = V_197 [ V_3 ] . V_52 ;
F_31 ( ~ V_202 , V_54 + F_88 ( V_52 ) ) ;
F_27 ( V_2 -> V_198 , V_52 ) ;
}
V_25 -> V_197 = NULL ;
F_71 ( V_197 ) ;
}
static int F_90 ( struct V_59 * V_60 ,
struct V_24 * V_25 )
{
int V_3 , V_71 ;
struct V_1 * V_2 = V_60 -> V_2 ;
void T_2 * V_54 = F_30 ( V_2 ) ;
V_71 = F_86 ( V_2 , V_25 ) ;
if ( V_71 )
return V_71 == - V_30 ? 0 : V_71 ;
for ( V_3 = 0 ; V_3 < V_25 -> V_41 ; ++ V_3 ) {
T_4 V_52 , V_205 ;
V_52 = V_25 -> V_197 ? V_25 -> V_197 [ V_3 ] . V_52 : V_25 -> V_47 [ V_3 ] ;
V_205 = V_206 |
( V_60 -> V_25 . V_66 << V_207 ) ;
F_31 ( V_205 , V_54 + F_91 ( V_52 ) ) ;
}
return 0 ;
}
static void F_92 ( struct V_59 * V_60 ,
struct V_24 * V_25 )
{
int V_3 ;
struct V_1 * V_2 = V_60 -> V_2 ;
void T_2 * V_54 = F_30 ( V_2 ) ;
if ( ( V_2 -> V_43 & V_44 ) && ! V_25 -> V_197 )
return;
for ( V_3 = 0 ; V_3 < V_25 -> V_41 ; ++ V_3 ) {
T_4 V_52 = V_25 -> V_197 ? V_25 -> V_197 [ V_3 ] . V_52 : V_25 -> V_47 [ V_3 ] ;
F_31 ( V_208 ,
V_54 + F_91 ( V_52 ) ) ;
}
F_89 ( V_2 , V_25 ) ;
}
static int F_93 ( struct V_77 * V_78 , struct V_11 * V_4 )
{
int V_71 ;
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_1 * V_2 , * V_209 ;
struct V_24 * V_25 ;
V_2 = F_20 ( V_4 ) ;
if ( ! V_2 ) {
F_18 ( V_4 , L_14 ) ;
return - V_210 ;
}
if ( V_4 -> V_211 . V_212 ) {
F_18 ( V_4 , L_15 ) ;
return - V_30 ;
}
V_209 = F_62 ( V_60 -> V_2 ) ;
if ( ! V_209 ) {
V_71 = F_58 ( V_78 , V_2 ) ;
if ( F_60 ( V_71 ) )
return V_71 ;
V_209 = V_60 -> V_2 ;
}
if ( V_209 != V_2 ) {
F_18 ( V_4 ,
L_16 ,
F_94 ( V_60 -> V_2 -> V_4 ) , F_94 ( V_2 -> V_4 ) ) ;
return - V_213 ;
}
V_25 = F_10 ( V_4 ) ;
if ( ! V_25 )
return - V_214 ;
V_71 = F_90 ( V_60 , V_25 ) ;
if ( ! V_71 )
V_4 -> V_211 . V_212 = V_78 ;
return V_71 ;
}
static void F_95 ( struct V_77 * V_78 , struct V_11 * V_4 )
{
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_24 * V_25 ;
V_25 = F_10 ( V_4 ) ;
if ( ! V_25 )
return;
V_4 -> V_211 . V_212 = NULL ;
F_92 ( V_60 , V_25 ) ;
}
static bool F_96 ( unsigned long V_104 ,
unsigned long V_51 )
{
return ! ( V_104 & ~ V_215 ) &&
( V_104 + V_216 <= V_51 ) ;
}
static int F_97 ( struct V_1 * V_2 , T_6 * V_188 ,
unsigned long V_104 , unsigned long V_51 ,
unsigned long V_217 , int V_218 , int V_219 )
{
T_10 * V_220 , * V_50 ;
T_11 V_221 = V_222 | V_223 | V_224 ;
if ( F_77 ( * V_188 ) ) {
T_7 V_189 = F_98 ( V_225 | V_226 ) ;
if ( ! V_189 )
return - V_40 ;
F_47 ( V_2 , F_99 ( V_189 ) , V_142 ) ;
F_100 ( NULL , V_188 , V_189 ) ;
F_47 ( V_2 , V_188 , sizeof( * V_188 ) ) ;
}
if ( V_219 == 1 ) {
V_221 |= V_227 | V_228 ;
if ( ! ( V_218 & V_229 ) && ( V_218 & V_230 ) )
V_221 |= V_231 ;
if ( V_218 & V_232 )
V_221 |= ( V_162 <<
V_233 ) ;
} else {
V_221 |= V_234 ;
if ( V_218 & V_230 )
V_221 |= V_235 ;
if ( V_218 & V_229 )
V_221 |= V_236 ;
if ( V_218 & V_232 )
V_221 |= V_237 ;
else
V_221 |= V_238 ;
}
if ( V_218 & V_239 )
V_221 &= ~ V_224 ;
else if ( ! ( V_218 & ( V_230 | V_229 ) ) )
V_221 &= ~ V_222 ;
V_221 |= V_240 ;
V_50 = F_101 ( * V_188 ) + F_102 ( V_104 ) ;
V_220 = V_50 ;
do {
int V_3 = 1 ;
V_221 &= ~ V_241 ;
if ( F_96 ( V_104 , V_51 ) ) {
V_3 = V_242 ;
V_221 |= V_241 ;
} else if ( F_103 ( * V_220 ) &
( V_241 | V_222 ) ) {
int V_243 ;
T_10 * V_244 ;
unsigned long V_52 = F_102 ( V_104 ) ;
V_52 &= ~ ( V_242 - 1 ) ;
V_244 = F_101 ( * V_188 ) + V_52 ;
for ( V_243 = 0 ; V_243 < V_242 ; ++ V_243 )
F_103 ( * ( V_244 + V_243 ) ) &=
~ V_241 ;
F_47 ( V_2 , V_244 ,
sizeof( * V_220 ) *
V_242 ) ;
}
do {
* V_220 = F_104 ( V_217 , F_105 ( V_221 ) ) ;
} while ( V_220 ++ , V_217 ++ , V_104 += V_142 , -- V_3 );
} while ( V_104 != V_51 );
F_47 ( V_2 , V_50 , sizeof( * V_220 ) * ( V_220 - V_50 ) ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 , T_8 * V_190 ,
unsigned long V_104 , unsigned long V_51 ,
V_139 V_245 , int V_218 , int V_219 )
{
int V_71 ;
T_6 * V_188 ;
unsigned long V_246 , V_217 = F_107 ( V_245 ) ;
#ifndef F_108
if ( F_81 ( * V_190 ) ) {
V_188 = ( T_6 * ) F_109 ( V_225 ) ;
if ( ! V_188 )
return - V_40 ;
F_47 ( V_2 , V_188 , V_142 ) ;
F_110 ( NULL , V_190 , V_188 ) ;
F_47 ( V_2 , V_190 , sizeof( * V_190 ) ) ;
V_188 += F_111 ( V_104 ) ;
} else
#endif
V_188 = F_76 ( V_190 , V_104 ) ;
do {
V_246 = F_112 ( V_104 , V_51 ) ;
V_71 = F_97 ( V_2 , V_188 , V_104 , V_246 , V_217 ,
V_218 , V_219 ) ;
V_245 += V_246 - V_104 ;
V_217 = F_107 ( V_245 ) ;
} while ( V_188 ++ , V_104 = V_246 , V_104 < V_51 );
return V_71 ;
}
static int F_113 ( struct V_1 * V_2 , V_137 * V_135 ,
unsigned long V_104 , unsigned long V_51 ,
V_139 V_245 , int V_218 , int V_219 )
{
int V_71 = 0 ;
T_8 * V_190 ;
unsigned long V_246 ;
#ifndef F_114
if ( F_84 ( * V_135 ) ) {
V_190 = ( T_8 * ) F_109 ( V_225 ) ;
if ( ! V_190 )
return - V_40 ;
F_47 ( V_2 , V_190 , V_142 ) ;
F_115 ( NULL , V_135 , V_190 ) ;
F_47 ( V_2 , V_135 , sizeof( * V_135 ) ) ;
V_190 += F_116 ( V_104 ) ;
} else
#endif
V_190 = F_80 ( V_135 , V_104 ) ;
do {
V_246 = F_117 ( V_104 , V_51 ) ;
V_71 = F_106 ( V_2 , V_190 , V_104 , V_246 , V_245 ,
V_218 , V_219 ) ;
V_245 += V_246 - V_104 ;
} while ( V_190 ++ , V_104 = V_246 , V_104 < V_51 );
return V_71 ;
}
static int F_118 ( struct V_59 * V_60 ,
unsigned long V_76 , V_139 V_247 ,
T_5 V_105 , int V_218 )
{
int V_71 , V_219 ;
unsigned long V_51 ;
V_139 V_248 , V_249 ;
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_61 * V_25 = & V_60 -> V_25 ;
V_137 * V_135 = V_25 -> V_135 ;
unsigned long V_70 ;
if ( V_25 -> V_64 == V_65 ) {
V_219 = 2 ;
V_248 = ( 1ULL << V_2 -> V_146 ) - 1 ;
V_249 = ( 1ULL << V_2 -> V_148 ) - 1 ;
} else {
V_219 = 1 ;
V_248 = ( 1ULL << V_2 -> V_124 ) - 1 ;
V_249 = ( 1ULL << V_2 -> V_132 ) - 1 ;
}
if ( ! V_135 )
return - V_213 ;
if ( V_105 & ~ V_107 )
return - V_213 ;
if ( ( V_139 ) V_76 & ~ V_248 )
return - V_46 ;
if ( V_247 & ~ V_249 )
return - V_46 ;
F_59 ( & V_60 -> V_174 , V_70 ) ;
V_135 += F_119 ( V_76 ) ;
V_51 = V_76 + V_105 ;
do {
unsigned long V_246 = F_120 ( V_76 , V_51 ) ;
V_71 = F_113 ( V_2 , V_135 , V_76 , V_246 , V_247 ,
V_218 , V_219 ) ;
if ( V_71 )
goto V_175;
V_247 += V_246 - V_76 ;
V_76 = V_246 ;
} while ( V_135 ++ , V_76 != V_51 );
V_175:
F_63 ( & V_60 -> V_174 , V_70 ) ;
return V_71 ;
}
static int F_121 ( struct V_77 * V_78 , unsigned long V_76 ,
V_139 V_247 , T_5 V_105 , int V_218 )
{
struct V_59 * V_60 = V_78 -> V_79 ;
if ( ! V_60 )
return - V_214 ;
return F_118 ( V_60 , V_76 , V_247 , V_105 , V_218 ) ;
}
static T_5 F_122 ( struct V_77 * V_78 , unsigned long V_76 ,
T_5 V_105 )
{
int V_71 ;
struct V_59 * V_60 = V_78 -> V_79 ;
V_71 = F_118 ( V_60 , V_76 , 0 , V_105 , 0 ) ;
F_36 ( V_60 ) ;
return V_71 ? 0 : V_105 ;
}
static V_139 F_123 ( struct V_77 * V_78 ,
T_12 V_76 )
{
V_137 * V_250 , V_135 ;
T_8 V_190 ;
T_6 V_188 ;
T_10 V_220 ;
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_61 * V_25 = & V_60 -> V_25 ;
V_250 = V_25 -> V_135 ;
if ( ! V_250 )
return 0 ;
V_135 = * ( V_250 + F_119 ( V_76 ) ) ;
if ( F_84 ( V_135 ) )
return 0 ;
V_190 = * F_80 ( & V_135 , V_76 ) ;
if ( F_81 ( V_190 ) )
return 0 ;
V_188 = * F_76 ( & V_190 , V_76 ) ;
if ( F_77 ( V_188 ) )
return 0 ;
V_220 = * ( F_101 ( V_188 ) + F_102 ( V_76 ) ) ;
if ( F_124 ( V_220 ) )
return 0 ;
return F_125 ( F_126 ( V_220 ) ) | ( V_76 & ~ V_107 ) ;
}
static bool F_127 ( enum V_251 V_252 )
{
switch ( V_252 ) {
case V_253 :
return true ;
case V_254 :
return true ;
default:
return false ;
}
}
static int F_128 ( struct V_255 * V_256 , T_1 V_257 , void * V_258 )
{
* ( ( T_1 * ) V_258 ) = V_257 ;
return 0 ;
}
static void F_129 ( void * V_258 )
{
F_71 ( V_258 ) ;
}
static int F_130 ( struct V_11 * V_4 )
{
struct V_1 * V_2 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
void (* F_131)( void * ) = NULL ;
int V_71 ;
V_2 = F_20 ( V_4 ) ;
if ( ! V_2 )
return - V_214 ;
V_27 = F_132 () ;
if ( F_133 ( V_27 ) ) {
F_18 ( V_4 , L_17 ) ;
return F_134 ( V_27 ) ;
}
if ( F_5 ( V_4 ) ) {
struct V_255 * V_256 = F_6 ( V_4 ) ;
V_25 = F_68 ( sizeof( * V_25 ) , V_39 ) ;
if ( ! V_25 ) {
V_71 = - V_40 ;
goto V_259;
}
V_25 -> V_41 = 1 ;
F_135 ( V_256 , F_128 ,
& V_25 -> V_47 [ 0 ] ) ;
F_131 = F_129 ;
} else {
struct V_16 * V_21 ;
V_21 = F_8 ( V_2 , V_4 -> V_5 ) ;
if ( ! V_21 ) {
V_71 = - V_214 ;
goto V_259;
}
V_25 = & V_21 -> V_25 ;
}
F_136 ( V_27 , V_25 , F_131 ) ;
V_71 = F_137 ( V_27 , V_4 ) ;
V_259:
F_13 ( V_27 ) ;
return V_71 ;
}
static void F_138 ( struct V_11 * V_4 )
{
F_139 ( V_4 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
void T_2 * V_54 = F_30 ( V_2 ) ;
void T_2 * V_80 ;
int V_3 = 0 ;
T_4 V_111 ;
V_111 = F_32 ( F_46 ( V_2 ) + V_100 ) ;
F_44 ( V_111 , F_46 ( V_2 ) + V_100 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_45 ; ++ V_3 ) {
F_31 ( 0 , V_54 + F_88 ( V_3 ) ) ;
F_31 ( V_208 ,
V_54 + F_91 ( V_3 ) ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_181 ; ++ V_3 ) {
V_80 = F_37 ( V_2 ) + F_38 ( V_2 , V_3 ) ;
F_31 ( 0 , V_80 + V_173 ) ;
F_31 ( V_82 , V_80 + V_81 ) ;
}
F_31 ( 0 , V_54 + V_260 ) ;
F_31 ( 0 , V_54 + V_261 ) ;
F_31 ( 0 , V_54 + V_262 ) ;
V_111 = F_32 ( F_46 ( V_2 ) + V_263 ) ;
V_111 |= ( V_264 | V_265 | V_266 | V_267 ) ;
V_111 |= ( V_268 | V_269 ) ;
V_111 &= ~ ( V_270 | V_271 ) ;
V_111 &= ~ V_272 ;
V_111 &= ~ ( V_273 << V_274 ) ;
F_29 ( V_2 ) ;
F_44 ( V_111 , F_46 ( V_2 ) + V_263 ) ;
}
static int F_141 ( int V_105 )
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
static int F_142 ( struct V_1 * V_2 )
{
unsigned long V_105 ;
void T_2 * V_54 = F_30 ( V_2 ) ;
T_4 V_201 ;
F_3 ( V_2 -> V_4 , L_18 ) ;
F_3 ( V_2 -> V_4 , L_19 , V_2 -> V_113 ) ;
V_201 = F_32 ( V_54 + V_275 ) ;
#ifndef F_42
if ( ( ( V_201 >> V_276 ) & V_277 ) == V_278 ) {
F_18 ( V_2 -> V_4 , L_20 ) ;
return - V_214 ;
}
#endif
if ( V_279 == 1 )
V_201 &= ~ ( V_280 | V_281 ) ;
else if ( V_279 == 2 )
V_201 &= ~ ( V_282 | V_281 ) ;
if ( V_201 & V_282 ) {
V_2 -> V_43 |= V_179 ;
F_3 ( V_2 -> V_4 , L_21 ) ;
}
if ( V_201 & V_280 ) {
V_2 -> V_43 |= V_283 ;
F_3 ( V_2 -> V_4 , L_22 ) ;
}
if ( V_201 & V_281 ) {
V_2 -> V_43 |= V_176 ;
F_3 ( V_2 -> V_4 , L_23 ) ;
}
if ( ! ( V_2 -> V_43 &
( V_179 | V_283 ) ) ) {
F_18 ( V_2 -> V_4 , L_24 ) ;
return - V_214 ;
}
if ( V_201 & V_284 ) {
V_2 -> V_43 |= V_108 ;
F_3 ( V_2 -> V_4 , L_25 ) ;
}
if ( V_201 & V_285 ) {
T_4 V_286 , V_287 , V_200 ;
V_2 -> V_43 |= V_44 ;
V_2 -> V_45 = ( V_201 >> V_288 ) &
V_289 ;
if ( V_2 -> V_45 == 0 ) {
F_18 ( V_2 -> V_4 ,
L_26 ) ;
return - V_214 ;
}
V_286 = V_290 << V_204 ;
V_286 |= ( V_291 << V_203 ) ;
F_31 ( V_286 , V_54 + F_88 ( 0 ) ) ;
V_286 = F_32 ( V_54 + F_88 ( 0 ) ) ;
V_200 = ( V_286 >> V_204 ) & V_290 ;
V_287 = ( V_286 >> V_203 ) & V_291 ;
if ( ( V_200 & V_287 ) != V_287 ) {
F_18 ( V_2 -> V_4 ,
L_27 ,
V_200 , V_287 ) ;
return - V_214 ;
}
F_3 ( V_2 -> V_4 ,
L_28 ,
V_2 -> V_45 , V_200 ) ;
} else {
V_2 -> V_45 = ( V_201 >> V_292 ) &
V_293 ;
}
V_201 = F_32 ( V_54 + V_294 ) ;
V_2 -> V_295 = ( V_201 & V_296 ) ? 16 : 12 ;
V_105 = 1 <<
( ( ( V_201 >> V_297 ) & V_298 ) + 1 ) ;
V_105 *= 2 << V_2 -> V_295 ;
if ( V_2 -> V_105 != V_105 )
F_143 ( V_2 -> V_4 ,
L_29 ,
V_105 , V_2 -> V_105 ) ;
V_2 -> V_178 = ( V_201 >> V_299 ) &
V_300 ;
V_2 -> V_181 = ( V_201 >> V_301 ) & V_302 ;
if ( V_2 -> V_178 > V_2 -> V_181 ) {
F_18 ( V_2 -> V_4 , L_30 ) ;
return - V_214 ;
}
F_3 ( V_2 -> V_4 , L_31 ,
V_2 -> V_181 , V_2 -> V_178 ) ;
V_201 = F_32 ( V_54 + V_303 ) ;
V_105 = F_141 ( ( V_201 >> V_304 ) & V_305 ) ;
V_2 -> V_132 = F_144 (unsigned long, PHYS_MASK_SHIFT, size) ;
#ifdef F_42
V_2 -> V_146 = F_144 (unsigned long, VA_BITS, size) ;
#else
V_2 -> V_146 = F_145 ( 32UL , V_105 ) ;
#endif
V_105 = F_141 ( ( V_201 >> V_306 ) & V_307 ) ;
V_2 -> V_148 = F_144 (unsigned long, PHYS_MASK_SHIFT, size) ;
if ( V_2 -> V_113 == V_114 ) {
V_2 -> V_124 = 32 ;
} else {
#ifdef F_42
V_105 = ( V_201 >> V_308 ) & V_309 ;
V_105 = F_145 ( V_310 , F_141 ( V_105 ) ) ;
#else
V_105 = 32 ;
#endif
V_2 -> V_124 = V_105 ;
if ( ( V_142 == V_143 && ! ( V_201 & V_311 ) ) ||
( V_142 == V_312 && ! ( V_201 & V_313 ) ) ||
( V_142 != V_143 && V_142 != V_312 ) ) {
F_18 ( V_2 -> V_4 , L_32 ,
V_142 ) ;
return - V_214 ;
}
}
if ( V_2 -> V_43 & V_179 )
F_3 ( V_2 -> V_4 , L_33 ,
V_2 -> V_124 , V_2 -> V_132 ) ;
if ( V_2 -> V_43 & V_283 )
F_3 ( V_2 -> V_4 , L_34 ,
V_2 -> V_146 , V_2 -> V_148 ) ;
return 0 ;
}
static int F_146 ( struct V_314 * V_256 )
{
const struct V_315 * V_316 ;
struct V_317 * V_318 ;
struct V_1 * V_2 ;
struct V_11 * V_4 = & V_256 -> V_4 ;
struct V_18 * V_19 ;
struct V_31 V_32 ;
int V_319 , V_3 , V_320 ;
V_2 = F_19 ( V_4 , sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 ) {
F_18 ( V_4 , L_35 ) ;
return - V_40 ;
}
V_2 -> V_4 = V_4 ;
V_316 = F_147 ( V_321 , V_4 -> V_5 ) ;
V_2 -> V_113 = (enum V_322 ) V_316 -> V_258 ;
V_318 = F_148 ( V_256 , V_323 , 0 ) ;
V_2 -> V_62 = F_149 ( V_4 , V_318 ) ;
if ( F_133 ( V_2 -> V_62 ) )
return F_134 ( V_2 -> V_62 ) ;
V_2 -> V_105 = F_150 ( V_318 ) ;
if ( F_151 ( V_4 -> V_5 , L_36 ,
& V_2 -> V_184 ) ) {
F_18 ( V_4 , L_37 ) ;
return - V_214 ;
}
V_319 = 0 ;
while ( ( V_318 = F_148 ( V_256 , V_324 , V_319 ) ) ) {
V_319 ++ ;
if ( V_319 > V_2 -> V_184 )
V_2 -> V_182 ++ ;
}
if ( ! V_2 -> V_182 ) {
F_18 ( V_4 , L_38 ,
V_319 , V_2 -> V_184 + 1 ) ;
return - V_214 ;
}
V_2 -> V_183 = F_19 ( V_4 , sizeof( * V_2 -> V_183 ) * V_319 ,
V_39 ) ;
if ( ! V_2 -> V_183 ) {
F_18 ( V_4 , L_39 , V_319 ) ;
return - V_40 ;
}
for ( V_3 = 0 ; V_3 < V_319 ; ++ V_3 ) {
int V_69 = F_152 ( V_256 , V_3 ) ;
if ( V_69 < 0 ) {
F_18 ( V_4 , L_40 , V_3 ) ;
return - V_214 ;
}
V_2 -> V_183 [ V_3 ] = V_69 ;
}
V_320 = F_142 ( V_2 ) ;
if ( V_320 )
return V_320 ;
V_3 = 0 ;
V_2 -> V_20 = V_325 ;
while ( ! F_153 ( V_4 -> V_5 , L_41 ,
L_42 , V_3 ,
& V_32 ) ) {
V_320 = F_17 ( V_2 , V_4 , & V_32 ) ;
if ( V_320 ) {
F_18 ( V_4 , L_43 ,
V_32 . V_33 -> V_34 ) ;
goto V_326;
}
V_3 ++ ;
}
F_3 ( V_4 , L_44 , V_3 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_113 > V_114 &&
V_2 -> V_181 != V_2 -> V_182 ) {
F_18 ( V_4 ,
L_45 ,
V_2 -> V_182 , V_2 -> V_181 ) ;
V_320 = - V_214 ;
goto V_326;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_184 ; ++ V_3 ) {
V_320 = F_64 ( V_2 -> V_183 [ V_3 ] ,
F_45 ,
V_185 ,
L_46 ,
V_2 ) ;
if ( V_320 ) {
F_18 ( V_4 , L_47 ,
V_3 , V_2 -> V_183 [ V_3 ] ) ;
goto V_327;
}
}
F_154 ( & V_2 -> V_328 ) ;
F_21 ( & V_48 ) ;
F_155 ( & V_2 -> V_328 , & V_329 ) ;
F_23 ( & V_48 ) ;
F_140 ( V_2 ) ;
return 0 ;
V_327:
while ( V_3 -- )
F_66 ( V_2 -> V_183 [ V_3 ] , V_2 ) ;
V_326:
for ( V_19 = F_156 ( & V_2 -> V_20 ) ; V_19 ; V_19 = F_157 ( V_19 ) ) {
struct V_16 * V_21
= F_9 ( V_19 , struct V_16 , V_19 ) ;
F_158 ( V_21 -> V_5 ) ;
}
return V_320 ;
}
static int F_159 ( struct V_314 * V_256 )
{
int V_3 ;
struct V_11 * V_4 = & V_256 -> V_4 ;
struct V_1 * V_330 , * V_2 = NULL ;
struct V_18 * V_19 ;
F_21 ( & V_48 ) ;
F_22 (curr, &arm_smmu_devices, list) {
if ( V_330 -> V_4 == V_4 ) {
V_2 = V_330 ;
F_160 ( & V_2 -> V_328 ) ;
break;
}
}
F_23 ( & V_48 ) ;
if ( ! V_2 )
return - V_214 ;
for ( V_19 = F_156 ( & V_2 -> V_20 ) ; V_19 ; V_19 = F_157 ( V_19 ) ) {
struct V_16 * V_21
= F_9 ( V_19 , struct V_16 , V_19 ) ;
F_158 ( V_21 -> V_5 ) ;
}
if ( ! F_161 ( V_2 -> V_180 , V_331 ) )
F_18 ( V_4 , L_48 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_184 ; ++ V_3 )
F_66 ( V_2 -> V_183 [ V_3 ] , V_2 ) ;
F_44 ( V_270 , F_46 ( V_2 ) + V_263 ) ;
return 0 ;
}
static int T_13 F_162 ( void )
{
int V_71 ;
V_71 = F_163 ( & V_332 ) ;
if ( V_71 )
return V_71 ;
if ( ! F_164 ( & V_333 ) )
F_165 ( & V_333 , & V_334 ) ;
#ifdef F_166
if ( ! F_164 ( & V_335 ) )
F_165 ( & V_335 , & V_334 ) ;
#endif
#ifdef F_167
if ( ! F_164 ( & V_336 ) )
F_165 ( & V_336 , & V_334 ) ;
#endif
return 0 ;
}
static void T_14 F_168 ( void )
{
return F_169 ( & V_332 ) ;
}

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
if ( ! ( V_2 -> V_43 & V_176 ) )
V_60 -> V_177 = V_178 ;
if ( ! ( V_2 -> V_43 & V_179 ) )
V_60 -> V_177 = V_180 ;
switch ( V_60 -> V_177 ) {
case V_180 :
V_25 -> V_64 = V_181 ;
V_50 = V_2 -> V_182 ;
break;
case V_183 :
case V_178 :
V_25 -> V_64 = V_65 ;
V_50 = 0 ;
break;
default:
V_71 = - V_184 ;
goto V_175;
}
V_71 = F_24 ( V_2 -> V_185 , V_50 ,
V_2 -> V_186 ) ;
if ( F_60 ( V_71 ) )
goto V_175;
V_25 -> V_66 = V_71 ;
if ( V_2 -> V_113 == V_114 ) {
V_25 -> V_115 = F_61 ( & V_2 -> V_115 ) ;
V_25 -> V_115 %= V_2 -> V_187 ;
} else {
V_25 -> V_115 = V_25 -> V_66 ;
}
F_62 ( V_60 -> V_2 ) = V_2 ;
F_51 ( V_60 ) ;
F_63 ( & V_60 -> V_174 , V_70 ) ;
V_69 = V_2 -> V_188 [ V_2 -> V_189 + V_25 -> V_115 ] ;
V_71 = F_64 ( V_69 , F_41 , V_190 ,
L_10 , V_78 ) ;
if ( F_60 ( V_71 ) ) {
F_18 ( V_2 -> V_4 , L_11 ,
V_25 -> V_115 , V_69 ) ;
V_25 -> V_115 = V_191 ;
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
if ( V_25 -> V_115 != V_191 ) {
V_69 = V_2 -> V_188 [ V_2 -> V_189 + V_25 -> V_115 ] ;
F_66 ( V_69 , V_78 ) ;
}
F_27 ( V_2 -> V_185 , V_25 -> V_66 ) ;
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
goto V_192;
V_60 -> V_25 . V_135 = V_135 ;
F_70 ( & V_60 -> V_174 ) ;
V_78 -> V_79 = V_60 ;
return 0 ;
V_192:
F_71 ( V_60 ) ;
return - V_40 ;
}
static void F_72 ( T_6 * V_193 )
{
T_7 V_194 = F_73 ( * V_193 ) ;
F_74 ( V_194 ) ;
}
static void F_75 ( T_8 * V_195 )
{
int V_3 ;
T_6 * V_193 , * V_196 = F_76 ( V_195 , 0 ) ;
V_193 = V_196 ;
for ( V_3 = 0 ; V_3 < V_197 ; ++ V_3 ) {
if ( F_77 ( * V_193 ) )
continue;
F_72 ( V_193 ) ;
V_193 ++ ;
}
F_78 ( NULL , V_196 ) ;
}
static void F_79 ( V_137 * V_135 )
{
int V_3 ;
T_8 * V_195 , * V_198 = F_80 ( V_135 , 0 ) ;
V_195 = V_198 ;
for ( V_3 = 0 ; V_3 < V_199 ; ++ V_3 ) {
if ( F_81 ( * V_195 ) )
continue;
F_75 ( V_195 ) ;
V_195 ++ ;
}
F_82 ( NULL , V_198 ) ;
}
static void F_83 ( struct V_59 * V_60 )
{
int V_3 ;
struct V_61 * V_25 = & V_60 -> V_25 ;
V_137 * V_135 , * V_200 = V_25 -> V_135 ;
V_135 = V_200 ;
for ( V_3 = 0 ; V_3 < V_136 ; ++ V_3 ) {
if ( F_84 ( * V_135 ) )
continue;
F_79 ( V_135 ) ;
V_135 ++ ;
}
F_71 ( V_200 ) ;
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
struct V_201 * V_202 ;
void T_2 * V_54 = F_30 ( V_2 ) ;
if ( ! ( V_2 -> V_43 & V_44 ) )
return 0 ;
if ( V_25 -> V_202 )
return - V_30 ;
V_202 = F_87 ( V_25 -> V_41 , sizeof( * V_202 ) , V_39 ) ;
if ( ! V_202 ) {
F_18 ( V_2 -> V_4 , L_12 ,
V_25 -> V_41 ) ;
return - V_40 ;
}
for ( V_3 = 0 ; V_3 < V_25 -> V_41 ; ++ V_3 ) {
int V_52 = F_24 ( V_2 -> V_203 , 0 ,
V_2 -> V_45 ) ;
if ( F_60 ( V_52 ) ) {
F_18 ( V_2 -> V_4 , L_13 ) ;
goto V_204;
}
V_202 [ V_3 ] = (struct V_201 ) {
. V_52 = V_52 ,
. V_205 = 0 ,
. V_206 = V_25 -> V_47 [ V_3 ] ,
} ;
}
for ( V_3 = 0 ; V_3 < V_25 -> V_41 ; ++ V_3 ) {
T_4 V_111 = V_207 | V_202 [ V_3 ] . V_206 << V_208 |
V_202 [ V_3 ] . V_205 << V_209 ;
F_31 ( V_111 , V_54 + F_88 ( V_202 [ V_3 ] . V_52 ) ) ;
}
V_25 -> V_202 = V_202 ;
return 0 ;
V_204:
while ( -- V_3 >= 0 )
F_27 ( V_2 -> V_203 , V_202 [ V_3 ] . V_52 ) ;
F_71 ( V_202 ) ;
return - V_38 ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_3 ;
void T_2 * V_54 = F_30 ( V_2 ) ;
struct V_201 * V_202 = V_25 -> V_202 ;
if ( ! V_202 )
return;
for ( V_3 = 0 ; V_3 < V_25 -> V_41 ; ++ V_3 ) {
T_9 V_52 = V_202 [ V_3 ] . V_52 ;
F_31 ( ~ V_207 , V_54 + F_88 ( V_52 ) ) ;
F_27 ( V_2 -> V_203 , V_52 ) ;
}
V_25 -> V_202 = NULL ;
F_71 ( V_202 ) ;
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
T_4 V_52 , V_210 ;
V_52 = V_25 -> V_202 ? V_25 -> V_202 [ V_3 ] . V_52 : V_25 -> V_47 [ V_3 ] ;
V_210 = V_211 |
( V_60 -> V_25 . V_66 << V_212 ) ;
F_31 ( V_210 , V_54 + F_91 ( V_52 ) ) ;
}
return 0 ;
}
static void F_92 ( struct V_59 * V_60 ,
struct V_24 * V_25 )
{
int V_3 ;
struct V_1 * V_2 = V_60 -> V_2 ;
void T_2 * V_54 = F_30 ( V_2 ) ;
if ( ( V_2 -> V_43 & V_44 ) && ! V_25 -> V_202 )
return;
for ( V_3 = 0 ; V_3 < V_25 -> V_41 ; ++ V_3 ) {
T_4 V_52 = V_25 -> V_202 ? V_25 -> V_202 [ V_3 ] . V_52 : V_25 -> V_47 [ V_3 ] ;
F_31 ( V_213 ,
V_54 + F_91 ( V_52 ) ) ;
}
F_89 ( V_2 , V_25 ) ;
}
static int F_93 ( struct V_77 * V_78 , struct V_11 * V_4 )
{
int V_71 ;
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_1 * V_2 , * V_214 ;
struct V_24 * V_25 ;
V_2 = F_20 ( V_4 ) ;
if ( ! V_2 ) {
F_18 ( V_4 , L_14 ) ;
return - V_215 ;
}
if ( V_4 -> V_216 . V_217 ) {
F_18 ( V_4 , L_15 ) ;
return - V_30 ;
}
V_214 = F_62 ( V_60 -> V_2 ) ;
if ( ! V_214 ) {
V_71 = F_58 ( V_78 , V_2 ) ;
if ( F_60 ( V_71 ) )
return V_71 ;
V_214 = V_60 -> V_2 ;
}
if ( V_214 != V_2 ) {
F_18 ( V_4 ,
L_16 ,
F_94 ( V_60 -> V_2 -> V_4 ) , F_94 ( V_2 -> V_4 ) ) ;
return - V_184 ;
}
V_25 = F_10 ( V_4 ) ;
if ( ! V_25 )
return - V_218 ;
V_71 = F_90 ( V_60 , V_25 ) ;
if ( ! V_71 )
V_4 -> V_216 . V_217 = V_78 ;
return V_71 ;
}
static void F_95 ( struct V_77 * V_78 , struct V_11 * V_4 )
{
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_24 * V_25 ;
V_25 = F_10 ( V_4 ) ;
if ( ! V_25 )
return;
V_4 -> V_216 . V_217 = NULL ;
F_92 ( V_60 , V_25 ) ;
}
static bool F_96 ( unsigned long V_104 ,
unsigned long V_51 )
{
return ! ( V_104 & ~ V_219 ) &&
( V_104 + V_220 <= V_51 ) ;
}
static int F_97 ( struct V_1 * V_2 , T_6 * V_193 ,
unsigned long V_104 , unsigned long V_51 ,
unsigned long V_221 , int V_222 , int V_177 )
{
T_10 * V_223 , * V_50 ;
T_11 V_224 = V_225 | V_226 ;
if ( F_77 ( * V_193 ) ) {
T_7 V_194 = F_98 ( V_227 | V_228 ) ;
if ( ! V_194 )
return - V_40 ;
F_47 ( V_2 , F_99 ( V_194 ) , V_142 ) ;
F_100 ( NULL , V_193 , V_194 ) ;
F_47 ( V_2 , V_193 , sizeof( * V_193 ) ) ;
}
if ( V_177 == 1 ) {
V_224 |= V_229 | V_230 ;
if ( ! ( V_222 & V_231 ) && ( V_222 & V_232 ) )
V_224 |= V_233 ;
if ( V_222 & V_234 )
V_224 |= ( V_162 <<
V_235 ) ;
} else {
V_224 |= V_236 ;
if ( V_222 & V_232 )
V_224 |= V_237 ;
if ( V_222 & V_231 )
V_224 |= V_238 ;
if ( V_222 & V_234 )
V_224 |= V_239 ;
else
V_224 |= V_240 ;
}
if ( V_222 & V_241 )
V_224 |= V_242 ;
if ( ! ( V_222 & ( V_232 | V_231 ) ) )
V_224 &= ~ V_225 ;
V_224 |= V_243 ;
V_50 = F_101 ( * V_193 ) + F_102 ( V_104 ) ;
V_223 = V_50 ;
do {
int V_3 = 1 ;
V_224 &= ~ V_244 ;
if ( F_96 ( V_104 , V_51 ) ) {
V_3 = V_245 ;
V_224 |= V_244 ;
} else if ( F_103 ( * V_223 ) &
( V_244 | V_225 ) ) {
int V_246 ;
T_10 * V_247 ;
unsigned long V_52 = F_102 ( V_104 ) ;
V_52 &= ~ ( V_245 - 1 ) ;
V_247 = F_101 ( * V_193 ) + V_52 ;
for ( V_246 = 0 ; V_246 < V_245 ; ++ V_246 )
F_103 ( * ( V_247 + V_246 ) ) &=
~ V_244 ;
F_47 ( V_2 , V_247 ,
sizeof( * V_223 ) *
V_245 ) ;
}
do {
* V_223 = F_104 ( V_221 , F_105 ( V_224 ) ) ;
} while ( V_223 ++ , V_221 ++ , V_104 += V_142 , -- V_3 );
} while ( V_104 != V_51 );
F_47 ( V_2 , V_50 , sizeof( * V_223 ) * ( V_223 - V_50 ) ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 , T_8 * V_195 ,
unsigned long V_104 , unsigned long V_51 ,
V_139 V_248 , int V_222 , int V_177 )
{
int V_71 ;
T_6 * V_193 ;
unsigned long V_249 , V_221 = F_107 ( V_248 ) ;
#ifndef F_108
if ( F_81 ( * V_195 ) ) {
V_193 = ( T_6 * ) F_109 ( V_227 ) ;
if ( ! V_193 )
return - V_40 ;
F_47 ( V_2 , V_193 , V_142 ) ;
F_110 ( NULL , V_195 , V_193 ) ;
F_47 ( V_2 , V_195 , sizeof( * V_195 ) ) ;
V_193 += F_111 ( V_104 ) ;
} else
#endif
V_193 = F_76 ( V_195 , V_104 ) ;
do {
V_249 = F_112 ( V_104 , V_51 ) ;
V_71 = F_97 ( V_2 , V_193 , V_104 , V_249 , V_221 ,
V_222 , V_177 ) ;
V_248 += V_249 - V_104 ;
V_221 = F_107 ( V_248 ) ;
} while ( V_193 ++ , V_104 = V_249 , V_104 < V_51 );
return V_71 ;
}
static int F_113 ( struct V_1 * V_2 , V_137 * V_135 ,
unsigned long V_104 , unsigned long V_51 ,
V_139 V_248 , int V_222 , int V_177 )
{
int V_71 = 0 ;
T_8 * V_195 ;
unsigned long V_249 ;
#ifndef F_114
if ( F_84 ( * V_135 ) ) {
V_195 = ( T_8 * ) F_109 ( V_227 ) ;
if ( ! V_195 )
return - V_40 ;
F_47 ( V_2 , V_195 , V_142 ) ;
F_115 ( NULL , V_135 , V_195 ) ;
F_47 ( V_2 , V_135 , sizeof( * V_135 ) ) ;
V_195 += F_116 ( V_104 ) ;
} else
#endif
V_195 = F_80 ( V_135 , V_104 ) ;
do {
V_249 = F_117 ( V_104 , V_51 ) ;
V_71 = F_106 ( V_2 , V_195 , V_104 , V_249 , V_248 ,
V_222 , V_177 ) ;
V_248 += V_249 - V_104 ;
} while ( V_195 ++ , V_104 = V_249 , V_104 < V_51 );
return V_71 ;
}
static int F_118 ( struct V_59 * V_60 ,
unsigned long V_76 , V_139 V_250 ,
T_5 V_105 , int V_222 )
{
int V_71 , V_177 ;
unsigned long V_51 ;
V_139 V_251 , V_252 ;
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_61 * V_25 = & V_60 -> V_25 ;
V_137 * V_135 = V_25 -> V_135 ;
unsigned long V_70 ;
if ( V_25 -> V_64 == V_65 ) {
V_177 = 2 ;
V_251 = ( 1ULL << V_2 -> V_146 ) - 1 ;
V_252 = ( 1ULL << V_2 -> V_148 ) - 1 ;
} else {
V_177 = 1 ;
V_251 = ( 1ULL << V_2 -> V_124 ) - 1 ;
V_252 = ( 1ULL << V_2 -> V_132 ) - 1 ;
}
if ( ! V_135 )
return - V_184 ;
if ( V_105 & ~ V_107 )
return - V_184 ;
if ( ( V_139 ) V_76 & ~ V_251 )
return - V_46 ;
if ( V_250 & ~ V_252 )
return - V_46 ;
F_59 ( & V_60 -> V_174 , V_70 ) ;
V_135 += F_119 ( V_76 ) ;
V_51 = V_76 + V_105 ;
do {
unsigned long V_249 = F_120 ( V_76 , V_51 ) ;
V_71 = F_113 ( V_2 , V_135 , V_76 , V_249 , V_250 ,
V_222 , V_177 ) ;
if ( V_71 )
goto V_175;
V_250 += V_249 - V_76 ;
V_76 = V_249 ;
} while ( V_135 ++ , V_76 != V_51 );
V_175:
F_63 ( & V_60 -> V_174 , V_70 ) ;
return V_71 ;
}
static int F_121 ( struct V_77 * V_78 , unsigned long V_76 ,
V_139 V_250 , T_5 V_105 , int V_222 )
{
struct V_59 * V_60 = V_78 -> V_79 ;
if ( ! V_60 )
return - V_218 ;
return F_118 ( V_60 , V_76 , V_250 , V_105 , V_222 ) ;
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
V_137 * V_253 , V_135 ;
T_8 V_195 ;
T_6 V_193 ;
T_10 V_223 ;
struct V_59 * V_60 = V_78 -> V_79 ;
struct V_61 * V_25 = & V_60 -> V_25 ;
V_253 = V_25 -> V_135 ;
if ( ! V_253 )
return 0 ;
V_135 = * ( V_253 + F_119 ( V_76 ) ) ;
if ( F_84 ( V_135 ) )
return 0 ;
V_195 = * F_80 ( & V_135 , V_76 ) ;
if ( F_81 ( V_195 ) )
return 0 ;
V_193 = * F_76 ( & V_195 , V_76 ) ;
if ( F_77 ( V_193 ) )
return 0 ;
V_223 = * ( F_101 ( V_193 ) + F_102 ( V_76 ) ) ;
if ( F_124 ( V_223 ) )
return 0 ;
return F_125 ( F_126 ( V_223 ) ) | ( V_76 & ~ V_107 ) ;
}
static bool F_127 ( enum V_254 V_255 )
{
switch ( V_255 ) {
case V_256 :
return true ;
case V_257 :
return true ;
case V_258 :
return true ;
default:
return false ;
}
}
static int F_128 ( struct V_259 * V_260 , T_1 V_261 , void * V_262 )
{
* ( ( T_1 * ) V_262 ) = V_261 ;
return 0 ;
}
static void F_129 ( void * V_262 )
{
F_71 ( V_262 ) ;
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
return - V_218 ;
V_27 = F_132 () ;
if ( F_133 ( V_27 ) ) {
F_18 ( V_4 , L_17 ) ;
return F_134 ( V_27 ) ;
}
if ( F_5 ( V_4 ) ) {
struct V_259 * V_260 = F_6 ( V_4 ) ;
V_25 = F_68 ( sizeof( * V_25 ) , V_39 ) ;
if ( ! V_25 ) {
V_71 = - V_40 ;
goto V_263;
}
V_25 -> V_41 = 1 ;
F_135 ( V_260 , F_128 ,
& V_25 -> V_47 [ 0 ] ) ;
F_131 = F_129 ;
} else {
struct V_16 * V_21 ;
V_21 = F_8 ( V_2 , V_4 -> V_5 ) ;
if ( ! V_21 ) {
V_71 = - V_218 ;
goto V_263;
}
V_25 = & V_21 -> V_25 ;
}
F_136 ( V_27 , V_25 , F_131 ) ;
V_71 = F_137 ( V_27 , V_4 ) ;
V_263:
F_13 ( V_27 ) ;
return V_71 ;
}
static void F_138 ( struct V_11 * V_4 )
{
F_139 ( V_4 ) ;
}
static int F_140 ( struct V_77 * V_78 ,
enum V_264 V_265 , void * V_262 )
{
struct V_59 * V_60 = V_78 -> V_79 ;
switch ( V_265 ) {
case V_266 :
* ( int * ) V_262 = ( V_60 -> V_177 == V_183 ) ;
return 0 ;
default:
return - V_218 ;
}
}
static int F_141 ( struct V_77 * V_78 ,
enum V_264 V_265 , void * V_262 )
{
struct V_59 * V_60 = V_78 -> V_79 ;
switch ( V_265 ) {
case V_266 :
if ( V_60 -> V_2 )
return - V_267 ;
if ( * ( int * ) V_262 )
V_60 -> V_177 = V_183 ;
else
V_60 -> V_177 = V_180 ;
return 0 ;
default:
return - V_218 ;
}
}
static void F_142 ( struct V_1 * V_2 )
{
void T_2 * V_54 = F_30 ( V_2 ) ;
void T_2 * V_80 ;
int V_3 = 0 ;
T_4 V_111 ;
V_111 = F_32 ( F_46 ( V_2 ) + V_100 ) ;
F_44 ( V_111 , F_46 ( V_2 ) + V_100 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_45 ; ++ V_3 ) {
F_31 ( 0 , V_54 + F_88 ( V_3 ) ) ;
F_31 ( V_213 ,
V_54 + F_91 ( V_3 ) ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_186 ; ++ V_3 ) {
V_80 = F_37 ( V_2 ) + F_38 ( V_2 , V_3 ) ;
F_31 ( 0 , V_80 + V_173 ) ;
F_31 ( V_82 , V_80 + V_81 ) ;
}
F_31 ( 0 , V_54 + V_268 ) ;
F_31 ( 0 , V_54 + V_269 ) ;
F_31 ( 0 , V_54 + V_270 ) ;
V_111 = F_32 ( F_46 ( V_2 ) + V_271 ) ;
V_111 |= ( V_272 | V_273 | V_274 | V_275 ) ;
V_111 |= ( V_276 | V_277 ) ;
V_111 &= ~ ( V_278 | V_279 ) ;
V_111 &= ~ V_280 ;
V_111 &= ~ ( V_281 << V_282 ) ;
F_29 ( V_2 ) ;
F_44 ( V_111 , F_46 ( V_2 ) + V_271 ) ;
}
static int F_143 ( int V_105 )
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
static int F_144 ( struct V_1 * V_2 )
{
unsigned long V_105 ;
void T_2 * V_54 = F_30 ( V_2 ) ;
T_4 V_206 ;
F_3 ( V_2 -> V_4 , L_18 ) ;
F_3 ( V_2 -> V_4 , L_19 , V_2 -> V_113 ) ;
V_206 = F_32 ( V_54 + V_283 ) ;
#ifndef F_42
if ( ( ( V_206 >> V_284 ) & V_285 ) == V_286 ) {
F_18 ( V_2 -> V_4 , L_20 ) ;
return - V_218 ;
}
#endif
if ( V_287 == 1 )
V_206 &= ~ ( V_288 | V_289 ) ;
else if ( V_287 == 2 )
V_206 &= ~ ( V_290 | V_289 ) ;
if ( V_206 & V_290 ) {
V_2 -> V_43 |= V_176 ;
F_3 ( V_2 -> V_4 , L_21 ) ;
}
if ( V_206 & V_288 ) {
V_2 -> V_43 |= V_179 ;
F_3 ( V_2 -> V_4 , L_22 ) ;
}
if ( V_206 & V_289 ) {
V_2 -> V_43 |= V_291 ;
F_3 ( V_2 -> V_4 , L_23 ) ;
}
if ( ! ( V_2 -> V_43 &
( V_176 | V_179 ) ) ) {
F_18 ( V_2 -> V_4 , L_24 ) ;
return - V_218 ;
}
if ( V_206 & V_292 ) {
V_2 -> V_43 |= V_108 ;
F_3 ( V_2 -> V_4 , L_25 ) ;
}
if ( V_206 & V_293 ) {
T_4 V_294 , V_295 , V_205 ;
V_2 -> V_43 |= V_44 ;
V_2 -> V_45 = ( V_206 >> V_296 ) &
V_297 ;
if ( V_2 -> V_45 == 0 ) {
F_18 ( V_2 -> V_4 ,
L_26 ) ;
return - V_218 ;
}
V_294 = V_298 << V_209 ;
V_294 |= ( V_299 << V_208 ) ;
F_31 ( V_294 , V_54 + F_88 ( 0 ) ) ;
V_294 = F_32 ( V_54 + F_88 ( 0 ) ) ;
V_205 = ( V_294 >> V_209 ) & V_298 ;
V_295 = ( V_294 >> V_208 ) & V_299 ;
if ( ( V_205 & V_295 ) != V_295 ) {
F_18 ( V_2 -> V_4 ,
L_27 ,
V_205 , V_295 ) ;
return - V_218 ;
}
F_3 ( V_2 -> V_4 ,
L_28 ,
V_2 -> V_45 , V_205 ) ;
} else {
V_2 -> V_45 = ( V_206 >> V_300 ) &
V_301 ;
}
V_206 = F_32 ( V_54 + V_302 ) ;
V_2 -> V_303 = ( V_206 & V_304 ) ? 16 : 12 ;
V_105 = 1 <<
( ( ( V_206 >> V_305 ) & V_306 ) + 1 ) ;
V_105 *= 2 << V_2 -> V_303 ;
if ( V_2 -> V_105 != V_105 )
F_145 ( V_2 -> V_4 ,
L_29 ,
V_105 , V_2 -> V_105 ) ;
V_2 -> V_182 = ( V_206 >> V_307 ) &
V_308 ;
V_2 -> V_186 = ( V_206 >> V_309 ) & V_310 ;
if ( V_2 -> V_182 > V_2 -> V_186 ) {
F_18 ( V_2 -> V_4 , L_30 ) ;
return - V_218 ;
}
F_3 ( V_2 -> V_4 , L_31 ,
V_2 -> V_186 , V_2 -> V_182 ) ;
V_206 = F_32 ( V_54 + V_311 ) ;
V_105 = F_143 ( ( V_206 >> V_312 ) & V_313 ) ;
V_2 -> V_132 = F_146 (unsigned long, PHYS_MASK_SHIFT, size) ;
#ifdef F_42
V_2 -> V_146 = F_146 (unsigned long, VA_BITS, size) ;
#else
V_2 -> V_146 = F_147 ( 32UL , V_105 ) ;
#endif
V_105 = F_143 ( ( V_206 >> V_314 ) & V_315 ) ;
V_2 -> V_148 = F_146 (unsigned long, PHYS_MASK_SHIFT, size) ;
if ( V_2 -> V_113 == V_114 ) {
V_2 -> V_124 = 32 ;
} else {
#ifdef F_42
V_105 = ( V_206 >> V_316 ) & V_317 ;
V_105 = F_147 ( V_318 , F_143 ( V_105 ) ) ;
#else
V_105 = 32 ;
#endif
V_2 -> V_124 = V_105 ;
if ( ( V_142 == V_143 && ! ( V_206 & V_319 ) ) ||
( V_142 == V_320 && ! ( V_206 & V_321 ) ) ||
( V_142 != V_143 && V_142 != V_320 ) ) {
F_18 ( V_2 -> V_4 , L_32 ,
V_142 ) ;
return - V_218 ;
}
}
if ( V_2 -> V_43 & V_176 )
F_3 ( V_2 -> V_4 , L_33 ,
V_2 -> V_124 , V_2 -> V_132 ) ;
if ( V_2 -> V_43 & V_179 )
F_3 ( V_2 -> V_4 , L_34 ,
V_2 -> V_146 , V_2 -> V_148 ) ;
return 0 ;
}
static int F_148 ( struct V_322 * V_260 )
{
const struct V_323 * V_324 ;
struct V_325 * V_326 ;
struct V_1 * V_2 ;
struct V_11 * V_4 = & V_260 -> V_4 ;
struct V_18 * V_19 ;
struct V_31 V_32 ;
int V_327 , V_3 , V_328 ;
V_2 = F_19 ( V_4 , sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 ) {
F_18 ( V_4 , L_35 ) ;
return - V_40 ;
}
V_2 -> V_4 = V_4 ;
V_324 = F_149 ( V_329 , V_4 -> V_5 ) ;
V_2 -> V_113 = (enum V_330 ) V_324 -> V_262 ;
V_326 = F_150 ( V_260 , V_331 , 0 ) ;
V_2 -> V_62 = F_151 ( V_4 , V_326 ) ;
if ( F_133 ( V_2 -> V_62 ) )
return F_134 ( V_2 -> V_62 ) ;
V_2 -> V_105 = F_152 ( V_326 ) ;
if ( F_153 ( V_4 -> V_5 , L_36 ,
& V_2 -> V_189 ) ) {
F_18 ( V_4 , L_37 ) ;
return - V_218 ;
}
V_327 = 0 ;
while ( ( V_326 = F_150 ( V_260 , V_332 , V_327 ) ) ) {
V_327 ++ ;
if ( V_327 > V_2 -> V_189 )
V_2 -> V_187 ++ ;
}
if ( ! V_2 -> V_187 ) {
F_18 ( V_4 , L_38 ,
V_327 , V_2 -> V_189 + 1 ) ;
return - V_218 ;
}
V_2 -> V_188 = F_19 ( V_4 , sizeof( * V_2 -> V_188 ) * V_327 ,
V_39 ) ;
if ( ! V_2 -> V_188 ) {
F_18 ( V_4 , L_39 , V_327 ) ;
return - V_40 ;
}
for ( V_3 = 0 ; V_3 < V_327 ; ++ V_3 ) {
int V_69 = F_154 ( V_260 , V_3 ) ;
if ( V_69 < 0 ) {
F_18 ( V_4 , L_40 , V_3 ) ;
return - V_218 ;
}
V_2 -> V_188 [ V_3 ] = V_69 ;
}
V_328 = F_144 ( V_2 ) ;
if ( V_328 )
return V_328 ;
V_3 = 0 ;
V_2 -> V_20 = V_333 ;
while ( ! F_155 ( V_4 -> V_5 , L_41 ,
L_42 , V_3 ,
& V_32 ) ) {
V_328 = F_17 ( V_2 , V_4 , & V_32 ) ;
if ( V_328 ) {
F_18 ( V_4 , L_43 ,
V_32 . V_33 -> V_34 ) ;
goto V_334;
}
V_3 ++ ;
}
F_3 ( V_4 , L_44 , V_3 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_113 > V_114 &&
V_2 -> V_186 != V_2 -> V_187 ) {
F_18 ( V_4 ,
L_45 ,
V_2 -> V_187 , V_2 -> V_186 ) ;
V_328 = - V_218 ;
goto V_334;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_189 ; ++ V_3 ) {
V_328 = F_64 ( V_2 -> V_188 [ V_3 ] ,
F_45 ,
V_190 ,
L_46 ,
V_2 ) ;
if ( V_328 ) {
F_18 ( V_4 , L_47 ,
V_3 , V_2 -> V_188 [ V_3 ] ) ;
goto V_335;
}
}
F_156 ( & V_2 -> V_336 ) ;
F_21 ( & V_48 ) ;
F_157 ( & V_2 -> V_336 , & V_337 ) ;
F_23 ( & V_48 ) ;
F_142 ( V_2 ) ;
return 0 ;
V_335:
while ( V_3 -- )
F_66 ( V_2 -> V_188 [ V_3 ] , V_2 ) ;
V_334:
for ( V_19 = F_158 ( & V_2 -> V_20 ) ; V_19 ; V_19 = F_159 ( V_19 ) ) {
struct V_16 * V_21
= F_9 ( V_19 , struct V_16 , V_19 ) ;
F_160 ( V_21 -> V_5 ) ;
}
return V_328 ;
}
static int F_161 ( struct V_322 * V_260 )
{
int V_3 ;
struct V_11 * V_4 = & V_260 -> V_4 ;
struct V_1 * V_338 , * V_2 = NULL ;
struct V_18 * V_19 ;
F_21 ( & V_48 ) ;
F_22 (curr, &arm_smmu_devices, list) {
if ( V_338 -> V_4 == V_4 ) {
V_2 = V_338 ;
F_162 ( & V_2 -> V_336 ) ;
break;
}
}
F_23 ( & V_48 ) ;
if ( ! V_2 )
return - V_218 ;
for ( V_19 = F_158 ( & V_2 -> V_20 ) ; V_19 ; V_19 = F_159 ( V_19 ) ) {
struct V_16 * V_21
= F_9 ( V_19 , struct V_16 , V_19 ) ;
F_160 ( V_21 -> V_5 ) ;
}
if ( ! F_163 ( V_2 -> V_185 , V_339 ) )
F_18 ( V_4 , L_48 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_189 ; ++ V_3 )
F_66 ( V_2 -> V_188 [ V_3 ] , V_2 ) ;
F_44 ( V_278 , F_46 ( V_2 ) + V_271 ) ;
return 0 ;
}
static int T_13 F_164 ( void )
{
struct V_10 * V_33 ;
int V_71 ;
V_33 = F_165 ( NULL , V_329 ) ;
if ( ! V_33 )
return 0 ;
F_160 ( V_33 ) ;
V_71 = F_166 ( & V_340 ) ;
if ( V_71 )
return V_71 ;
if ( ! F_167 ( & V_341 ) )
F_168 ( & V_341 , & V_342 ) ;
#ifdef F_169
if ( ! F_167 ( & V_343 ) )
F_168 ( & V_343 , & V_342 ) ;
#endif
#ifdef F_170
if ( ! F_167 ( & V_344 ) )
F_168 ( & V_344 , & V_342 ) ;
#endif
return 0 ;
}
static void T_14 F_171 ( void )
{
return F_172 ( & V_340 ) ;
}

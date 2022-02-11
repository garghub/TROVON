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
static struct V_10 * F_4 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_2 -> V_15 . V_13 ;
while ( V_14 ) {
struct V_10 * V_16 ;
V_16 = F_5 ( V_14 , struct V_10 , V_14 ) ;
if ( V_12 < V_16 -> V_5 )
V_14 = V_14 -> V_17 ;
else if ( V_12 > V_16 -> V_5 )
V_14 = V_14 -> V_18 ;
else
return V_16 ;
}
return NULL ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_10 * V_16 )
{
struct V_13 * * V_19 , * V_20 ;
V_19 = & V_2 -> V_15 . V_13 ;
V_20 = NULL ;
while ( * V_19 ) {
struct V_10 * V_21 ;
V_21 = F_5 ( * V_19 , struct V_10 , V_14 ) ;
V_20 = * V_19 ;
if ( V_16 -> V_5 < V_21 -> V_5 )
V_19 = & ( ( * V_19 ) -> V_17 ) ;
else if ( V_16 -> V_5 > V_21 -> V_5 )
V_19 = & ( ( * V_19 ) -> V_18 ) ;
else
return - V_22 ;
}
F_7 ( & V_16 -> V_14 , V_20 , V_19 ) ;
F_8 ( & V_16 -> V_14 , & V_2 -> V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_23 * V_4 ,
struct V_24 * V_25 )
{
int V_3 ;
struct V_10 * V_16 ;
V_16 = F_4 ( V_2 , V_25 -> V_26 ) ;
if ( V_16 ) {
F_10 ( V_4 ,
L_2 ,
V_25 -> V_26 -> V_27 ) ;
return - V_28 ;
}
if ( V_25 -> V_29 > V_30 ) {
F_10 ( V_4 ,
L_3 ,
V_30 , V_25 -> V_26 -> V_27 ) ;
return - V_31 ;
}
V_16 = F_11 ( V_4 , sizeof( * V_16 ) , V_32 ) ;
if ( ! V_16 )
return - V_33 ;
V_16 -> V_5 = V_25 -> V_26 ;
V_16 -> V_34 = V_25 -> V_29 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_34 ; ++ V_3 )
V_16 -> V_35 [ V_3 ] = V_25 -> args [ V_3 ] ;
return F_6 ( V_2 , V_16 ) ;
}
static struct V_1 * F_12 ( struct V_1 * V_2 )
{
struct V_1 * V_20 ;
if ( ! V_2 -> V_36 )
return NULL ;
F_13 ( & V_37 ) ;
F_14 (parent, &arm_smmu_devices, list)
if ( V_20 -> V_4 -> V_5 == V_2 -> V_36 )
goto V_38;
V_20 = NULL ;
F_15 ( V_2 -> V_4 ,
L_4 ) ;
V_38:
F_16 ( & V_37 ) ;
return V_20 ;
}
static int F_17 ( unsigned long * V_39 , int V_40 , int V_41 )
{
int V_42 ;
do {
V_42 = F_18 ( V_39 , V_41 , V_40 ) ;
if ( V_42 == V_41 )
return - V_31 ;
} while ( F_19 ( V_42 , V_39 ) );
return V_42 ;
}
static void F_20 ( unsigned long * V_39 , int V_42 )
{
F_21 ( V_42 , V_39 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_43 = 0 ;
void T_1 * V_44 = F_23 ( V_2 ) ;
F_24 ( 0 , V_44 + V_45 ) ;
while ( F_25 ( V_44 + V_46 )
& V_47 ) {
F_26 () ;
if ( ++ V_43 == V_48 ) {
F_27 ( V_2 -> V_4 ,
L_5 ) ;
return;
}
F_28 ( 1 ) ;
}
}
static void F_29 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
void T_1 * V_51 = F_23 ( V_2 ) ;
bool V_52 = V_50 -> V_53 != V_54 ;
if ( V_52 ) {
V_51 = F_30 ( V_2 ) + F_31 ( V_2 , V_50 -> V_55 ) ;
F_24 ( F_32 ( V_50 ) ,
V_51 + V_56 ) ;
} else {
V_51 = F_23 ( V_2 ) ;
F_24 ( F_33 ( V_50 ) ,
V_51 + V_57 ) ;
}
F_22 ( V_2 ) ;
}
static T_2 F_34 ( int V_58 , void * V_4 )
{
int V_59 , V_60 ;
T_3 V_61 , V_62 , V_63 , V_64 ;
unsigned long V_65 ;
struct V_66 * V_67 = V_4 ;
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_49 * V_71 = & V_69 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_2 ;
void T_1 * V_72 ;
V_72 = F_30 ( V_2 ) + F_31 ( V_2 , V_71 -> V_55 ) ;
V_61 = F_25 ( V_72 + V_73 ) ;
if ( ! ( V_61 & V_74 ) )
return V_75 ;
if ( V_61 & V_76 )
F_27 ( V_2 -> V_4 ,
L_6 ,
V_61 ) ;
V_63 = F_25 ( V_72 + V_77 ) ;
V_59 = V_63 & V_78 ? V_79 : V_80 ;
V_62 = F_25 ( V_72 + V_81 ) ;
V_65 = V_62 ;
#ifdef F_35
V_62 = F_25 ( V_72 + V_82 ) ;
V_65 |= ( ( unsigned long ) V_62 << 32 ) ;
#endif
if ( ! F_36 ( V_67 , V_2 -> V_4 , V_65 , V_59 ) ) {
V_60 = V_83 ;
V_64 = V_84 ;
} else {
F_27 ( V_2 -> V_4 ,
L_7 ,
V_65 , V_63 , V_71 -> V_55 ) ;
V_60 = V_75 ;
V_64 = V_85 ;
}
F_37 ( V_61 , V_72 + V_73 ) ;
if ( V_61 & V_86 )
F_24 ( V_64 , V_72 + V_87 ) ;
return V_60 ;
}
static T_2 F_38 ( int V_58 , void * V_4 )
{
T_3 V_88 , V_89 , V_90 , V_91 ;
struct V_1 * V_2 = V_4 ;
void T_1 * V_44 = F_39 ( V_2 ) ;
V_88 = F_25 ( V_44 + V_92 ) ;
V_89 = F_25 ( V_44 + V_93 ) ;
V_90 = F_25 ( V_44 + V_94 ) ;
V_91 = F_25 ( V_44 + V_95 ) ;
if ( ! V_88 )
return V_75 ;
F_27 ( V_2 -> V_4 ,
L_8 ) ;
F_27 ( V_2 -> V_4 ,
L_9 ,
V_88 , V_89 , V_90 , V_91 ) ;
F_37 ( V_88 , V_44 + V_92 ) ;
return V_83 ;
}
static void F_40 ( struct V_1 * V_2 , void * V_96 ,
T_4 V_97 )
{
unsigned long V_98 = ( unsigned long ) V_96 & ~ V_99 ;
if ( V_2 -> V_100 & V_101 ) {
F_41 ( V_102 ) ;
} else {
F_42 ( V_2 -> V_4 , F_43 ( V_96 ) , V_98 , V_97 ,
V_103 ) ;
}
}
static void F_44 ( struct V_68 * V_69 )
{
T_3 V_104 ;
bool V_52 ;
struct V_49 * V_71 = & V_69 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_2 ;
void T_1 * V_72 , * V_44 , * V_105 ;
V_44 = F_23 ( V_2 ) ;
V_105 = F_45 ( V_2 ) ;
V_52 = V_71 -> V_53 != V_54 ;
V_72 = F_30 ( V_2 ) + F_31 ( V_2 , V_71 -> V_55 ) ;
V_104 = V_71 -> V_53 ;
if ( V_2 -> V_106 == 1 )
V_104 |= V_71 -> V_107 << V_108 ;
if ( V_52 ) {
V_104 |= ( V_109 << V_110 ) |
( V_111 << V_112 ) ;
} else {
V_104 |= F_33 ( V_71 ) << V_113 ;
}
F_24 ( V_104 , V_105 + F_46 ( V_71 -> V_55 ) ) ;
if ( V_2 -> V_106 > 1 ) {
#ifdef F_35
V_104 = V_114 ;
#else
V_104 = V_115 ;
#endif
F_24 ( V_104 ,
V_105 + F_47 ( V_71 -> V_55 ) ) ;
switch ( V_2 -> V_116 ) {
case 32 :
V_104 = ( V_117 << V_118 ) ;
break;
case 36 :
V_104 = ( V_119 << V_118 ) ;
break;
case 39 :
V_104 = ( V_120 << V_118 ) ;
break;
case 42 :
V_104 = ( V_121 << V_118 ) ;
break;
case 44 :
V_104 = ( V_122 << V_118 ) ;
break;
case 48 :
V_104 = ( V_123 << V_118 ) ;
break;
}
switch ( V_2 -> V_124 ) {
case 32 :
V_104 |= ( V_117 << V_125 ) ;
break;
case 36 :
V_104 |= ( V_119 << V_125 ) ;
break;
case 39 :
V_104 |= ( V_120 << V_125 ) ;
break;
case 42 :
V_104 |= ( V_121 << V_125 ) ;
break;
case 44 :
V_104 |= ( V_122 << V_125 ) ;
break;
case 48 :
V_104 |= ( V_123 << V_125 ) ;
break;
}
if ( V_52 )
F_24 ( V_104 , V_72 + V_126 ) ;
}
F_40 ( V_2 , V_71 -> V_127 ,
V_128 * sizeof( V_129 ) ) ;
V_104 = F_48 ( V_71 -> V_127 ) ;
F_24 ( V_104 , V_72 + V_130 ) ;
V_104 = ( V_131 ) F_48 ( V_71 -> V_127 ) >> 32 ;
if ( V_52 )
V_104 |= F_32 ( V_71 ) << V_132 ;
F_24 ( V_104 , V_72 + V_133 ) ;
if ( V_2 -> V_106 > 1 ) {
if ( V_134 == V_135 )
V_104 = V_136 ;
else
V_104 = V_137 ;
if ( ! V_52 ) {
switch ( V_2 -> V_138 ) {
case 32 :
V_104 |= ( V_117 << V_139 ) ;
break;
case 36 :
V_104 |= ( V_119 << V_139 ) ;
break;
case 40 :
V_104 |= ( V_120 << V_139 ) ;
break;
case 42 :
V_104 |= ( V_121 << V_139 ) ;
break;
case 44 :
V_104 |= ( V_122 << V_139 ) ;
break;
case 48 :
V_104 |= ( V_123 << V_139 ) ;
break;
}
} else {
V_104 |= ( 64 - V_2 -> V_124 ) << V_140 ;
}
} else {
V_104 = 0 ;
}
V_104 |= V_141 |
( V_142 << V_143 ) |
( V_144 << V_145 ) |
( V_144 << V_146 ) |
( V_147 << V_148 ) ;
F_24 ( V_104 , V_72 + V_149 ) ;
if ( V_52 ) {
V_104 = ( V_150 << F_49 ( V_151 ) ) |
( V_152 << F_49 ( V_153 ) ) |
( V_154 << F_49 ( V_155 ) ) ;
F_24 ( V_104 , V_72 + V_156 ) ;
}
V_104 = V_157 | V_158 | V_159 | V_160 | V_161 ;
if ( V_52 )
V_104 |= V_162 ;
#ifdef F_50
V_104 |= V_163 ;
#endif
F_24 ( V_104 , V_72 + V_164 ) ;
}
static int F_51 ( struct V_66 * V_67 ,
struct V_23 * V_4 )
{
int V_58 , V_60 , V_40 ;
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_49 * V_71 = & V_69 -> V_71 ;
struct V_1 * V_2 , * V_20 ;
V_20 = V_4 -> V_165 . V_166 ;
V_69 -> V_167 = - 1 ;
do {
V_2 = V_20 ;
V_69 -> V_167 &= ( 1ULL << V_2 -> V_138 ) - 1 ;
} while ( ( V_20 = F_12 ( V_2 ) ) );
if ( ! F_4 ( V_2 , V_4 -> V_5 ) ) {
F_10 ( V_4 , L_10 ) ;
return - V_168 ;
}
if ( V_2 -> V_100 & V_169 ) {
V_71 -> V_53 = V_170 ;
V_40 = V_2 -> V_171 ;
} else if ( V_2 -> V_100 & V_172 ) {
V_71 -> V_53 = V_54 ;
V_40 = 0 ;
} else {
V_71 -> V_53 = V_170 ;
V_40 = V_2 -> V_171 ;
}
V_60 = F_17 ( V_2 -> V_173 , V_40 ,
V_2 -> V_174 ) ;
if ( F_52 ( V_60 ) )
return V_60 ;
V_71 -> V_55 = V_60 ;
if ( V_2 -> V_106 == 1 ) {
V_71 -> V_107 = F_53 ( & V_2 -> V_107 ) ;
V_71 -> V_107 %= V_2 -> V_175 ;
} else {
V_71 -> V_107 = V_71 -> V_55 ;
}
V_58 = V_2 -> V_176 [ V_2 -> V_177 + V_71 -> V_107 ] ;
V_60 = F_54 ( V_58 , F_34 , V_178 ,
L_11 , V_67 ) ;
if ( F_52 ( V_60 ) ) {
F_10 ( V_2 -> V_4 , L_12 ,
V_71 -> V_107 , V_58 ) ;
V_71 -> V_107 = V_179 ;
goto V_180;
}
V_71 -> V_2 = V_2 ;
F_44 ( V_69 ) ;
return V_60 ;
V_180:
F_20 ( V_2 -> V_173 , V_71 -> V_55 ) ;
return V_60 ;
}
static void F_55 ( struct V_66 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_49 * V_71 = & V_69 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_2 ;
void T_1 * V_72 ;
int V_58 ;
if ( ! V_2 )
return;
V_72 = F_30 ( V_2 ) + F_31 ( V_2 , V_71 -> V_55 ) ;
F_24 ( 0 , V_72 + V_164 ) ;
F_29 ( V_71 ) ;
if ( V_71 -> V_107 != V_179 ) {
V_58 = V_2 -> V_176 [ V_2 -> V_177 + V_71 -> V_107 ] ;
F_56 ( V_58 , V_67 ) ;
}
F_20 ( V_2 -> V_173 , V_71 -> V_55 ) ;
}
static int F_57 ( struct V_66 * V_67 )
{
struct V_68 * V_69 ;
V_129 * V_127 ;
V_69 = F_58 ( sizeof( * V_69 ) , V_32 ) ;
if ( ! V_69 )
return - V_33 ;
V_127 = F_58 ( V_128 * sizeof( V_129 ) , V_32 ) ;
if ( ! V_127 )
goto V_181;
V_69 -> V_71 . V_127 = V_127 ;
F_59 ( & V_69 -> V_182 ) ;
V_67 -> V_70 = V_69 ;
return 0 ;
V_181:
F_60 ( V_69 ) ;
return - V_33 ;
}
static void F_61 ( T_5 * V_183 )
{
T_6 V_184 = F_62 ( * V_183 ) ;
F_63 ( V_184 ) ;
F_64 ( V_184 ) ;
}
static void F_65 ( T_7 * V_185 )
{
int V_3 ;
T_5 * V_183 , * V_186 = F_66 ( V_185 , 0 ) ;
V_183 = V_186 ;
for ( V_3 = 0 ; V_3 < V_187 ; ++ V_3 ) {
if ( F_67 ( * V_183 ) )
continue;
F_61 ( V_183 ) ;
V_183 ++ ;
}
F_68 ( NULL , V_186 ) ;
}
static void F_69 ( V_129 * V_127 )
{
int V_3 ;
T_7 * V_185 , * V_188 = F_70 ( V_127 , 0 ) ;
V_185 = V_188 ;
for ( V_3 = 0 ; V_3 < V_189 ; ++ V_3 ) {
if ( F_71 ( * V_185 ) )
continue;
F_65 ( V_185 ) ;
V_185 ++ ;
}
F_72 ( NULL , V_188 ) ;
}
static void F_73 ( struct V_68 * V_69 )
{
int V_3 ;
struct V_49 * V_71 = & V_69 -> V_71 ;
V_129 * V_127 , * V_190 = V_71 -> V_127 ;
V_127 = V_190 ;
for ( V_3 = 0 ; V_3 < V_128 ; ++ V_3 ) {
if ( F_74 ( * V_127 ) )
continue;
F_69 ( V_127 ) ;
V_127 ++ ;
}
F_60 ( V_190 ) ;
}
static void F_75 ( struct V_66 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_70 ;
F_55 ( V_67 ) ;
F_73 ( V_69 ) ;
F_60 ( V_69 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_10 * V_16 )
{
int V_3 ;
struct V_191 * V_192 ;
void T_1 * V_44 = F_23 ( V_2 ) ;
if ( ! ( V_2 -> V_100 & V_193 ) )
return 0 ;
if ( V_16 -> V_192 )
return - V_22 ;
V_192 = F_77 ( sizeof( * V_192 ) * V_16 -> V_34 , V_32 ) ;
if ( ! V_192 ) {
F_10 ( V_2 -> V_4 , L_13 ,
V_16 -> V_34 , V_16 -> V_5 -> V_27 ) ;
return - V_33 ;
}
for ( V_3 = 0 ; V_3 < V_16 -> V_34 ; ++ V_3 ) {
int V_42 = F_17 ( V_2 -> V_194 , 0 ,
V_2 -> V_195 ) ;
if ( F_52 ( V_42 ) ) {
F_10 ( V_2 -> V_4 , L_14 ) ;
goto V_196;
}
V_192 [ V_3 ] = (struct V_191 ) {
. V_42 = V_42 ,
. V_197 = 0 ,
. V_198 = V_16 -> V_35 [ V_3 ] ,
} ;
}
for ( V_3 = 0 ; V_3 < V_16 -> V_34 ; ++ V_3 ) {
T_3 V_104 = V_199 | V_192 [ V_3 ] . V_198 << V_200 |
V_192 [ V_3 ] . V_197 << V_201 ;
F_24 ( V_104 , V_44 + F_78 ( V_192 [ V_3 ] . V_42 ) ) ;
}
V_16 -> V_192 = V_192 ;
return 0 ;
V_196:
while ( -- V_3 >= 0 )
F_20 ( V_2 -> V_194 , V_192 [ V_3 ] . V_42 ) ;
F_60 ( V_192 ) ;
return - V_31 ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_10 * V_16 )
{
int V_3 ;
void T_1 * V_44 = F_23 ( V_2 ) ;
struct V_191 * V_192 = V_16 -> V_192 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_34 ; ++ V_3 ) {
T_8 V_42 = V_192 [ V_3 ] . V_42 ;
F_24 ( ~ V_199 , V_44 + F_78 ( V_42 ) ) ;
F_20 ( V_2 -> V_194 , V_42 ) ;
}
V_16 -> V_192 = NULL ;
F_60 ( V_192 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_10 * V_16 )
{
int V_3 ;
void T_1 * V_44 = F_23 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_16 -> V_34 ; ++ V_3 ) {
T_9 V_202 = V_16 -> V_35 [ V_3 ] ;
F_24 ( V_203 ,
V_44 + F_81 ( V_202 ) ) ;
}
}
static int F_82 ( struct V_68 * V_69 ,
struct V_10 * V_16 )
{
int V_3 , V_60 ;
struct V_1 * V_20 , * V_2 = V_69 -> V_71 . V_2 ;
void T_1 * V_44 = F_23 ( V_2 ) ;
V_60 = F_76 ( V_2 , V_16 ) ;
if ( V_60 )
return V_60 ;
V_2 = V_69 -> V_204 ;
while ( ( V_20 = F_12 ( V_2 ) ) ) {
if ( V_2 -> V_100 & V_193 )
continue;
F_80 ( V_2 , V_16 ) ;
V_2 = V_20 ;
}
for ( V_3 = 0 ; V_3 < V_16 -> V_34 ; ++ V_3 ) {
T_3 V_42 , V_205 ;
V_42 = V_16 -> V_192 ? V_16 -> V_192 [ V_3 ] . V_42 : V_16 -> V_35 [ V_3 ] ;
V_205 = V_206 |
( V_69 -> V_71 . V_55 << V_207 ) ;
F_24 ( V_205 , V_44 + F_81 ( V_42 ) ) ;
}
return 0 ;
}
static void F_83 ( struct V_68 * V_69 ,
struct V_10 * V_16 )
{
struct V_1 * V_2 = V_69 -> V_71 . V_2 ;
F_80 ( V_2 , V_16 ) ;
F_79 ( V_2 , V_16 ) ;
}
static int F_84 ( struct V_66 * V_67 , struct V_23 * V_4 )
{
int V_60 = - V_208 ;
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_1 * V_209 = V_4 -> V_165 . V_166 ;
struct V_10 * V_16 ;
unsigned long V_59 ;
if ( ! V_209 ) {
F_10 ( V_4 , L_15 ) ;
return - V_210 ;
}
F_85 ( & V_69 -> V_182 , V_59 ) ;
if ( ! V_69 -> V_204 ) {
V_60 = F_51 ( V_67 , V_4 ) ;
if ( F_52 ( V_60 ) )
goto V_211;
V_69 -> V_204 = V_209 ;
} else if ( V_69 -> V_204 != V_209 ) {
F_10 ( V_4 ,
L_16 ,
F_86 ( V_69 -> V_204 -> V_4 ) ,
F_86 ( V_209 -> V_4 ) ) ;
goto V_211;
}
F_87 ( & V_69 -> V_182 , V_59 ) ;
V_16 = F_4 ( V_69 -> V_204 , V_4 -> V_5 ) ;
if ( ! V_16 )
return - V_168 ;
return F_82 ( V_69 , V_16 ) ;
V_211:
F_87 ( & V_69 -> V_182 , V_59 ) ;
return V_60 ;
}
static void F_88 ( struct V_66 * V_67 , struct V_23 * V_4 )
{
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_10 * V_16 ;
V_16 = F_4 ( V_69 -> V_204 , V_4 -> V_5 ) ;
if ( V_16 )
F_83 ( V_69 , V_16 ) ;
}
static bool F_89 ( unsigned long V_96 ,
unsigned long V_41 )
{
return ! ( V_96 & ~ V_212 ) &&
( V_96 + V_213 <= V_41 ) ;
}
static int F_90 ( struct V_1 * V_2 , T_5 * V_183 ,
unsigned long V_96 , unsigned long V_41 ,
unsigned long V_214 , int V_215 , int V_216 )
{
T_10 * V_217 , * V_40 ;
T_11 V_218 = V_219 | V_220 | V_221 ;
if ( F_67 ( * V_183 ) ) {
T_6 V_184 = F_91 ( V_222 | V_223 ) ;
if ( ! V_184 )
return - V_33 ;
F_40 ( V_2 , F_92 ( V_184 ) , V_134 ) ;
if ( ! F_93 ( V_184 ) ) {
F_64 ( V_184 ) ;
return - V_33 ;
}
F_94 ( NULL , V_183 , V_184 ) ;
F_40 ( V_2 , V_183 , sizeof( * V_183 ) ) ;
}
if ( V_216 == 1 ) {
V_218 |= V_224 | V_225 ;
if ( ! ( V_215 & V_226 ) && ( V_215 & V_227 ) )
V_218 |= V_228 ;
if ( V_215 & V_229 )
V_218 |= ( V_153 <<
V_230 ) ;
} else {
V_218 |= V_231 ;
if ( V_215 & V_227 )
V_218 |= V_232 ;
if ( V_215 & V_226 )
V_218 |= V_233 ;
if ( V_215 & V_229 )
V_218 |= V_234 ;
else
V_218 |= V_235 ;
}
if ( V_215 & V_236 )
V_218 &= ~ V_221 ;
else if ( ! ( V_215 & ( V_227 | V_226 ) ) )
V_218 &= ~ V_219 ;
V_218 |= V_237 ;
V_40 = F_95 ( * V_183 ) + F_96 ( V_96 ) ;
V_217 = V_40 ;
do {
int V_3 = 1 ;
V_218 &= ~ V_238 ;
if ( F_89 ( V_96 , V_41 ) ) {
V_3 = V_239 ;
V_218 |= V_238 ;
} else if ( F_97 ( * V_217 ) &
( V_238 | V_219 ) ) {
int V_240 ;
T_10 * V_241 ;
unsigned long V_42 = F_96 ( V_96 ) ;
V_42 &= ~ ( V_239 - 1 ) ;
V_241 = F_95 ( * V_183 ) + V_42 ;
for ( V_240 = 0 ; V_240 < V_239 ; ++ V_240 )
F_97 ( * ( V_241 + V_240 ) ) &= ~ V_238 ;
F_40 ( V_2 , V_241 ,
sizeof( * V_217 ) *
V_239 ) ;
}
do {
* V_217 = F_98 ( V_214 , F_99 ( V_218 ) ) ;
} while ( V_217 ++ , V_214 ++ , V_96 += V_134 , -- V_3 );
} while ( V_96 != V_41 );
F_40 ( V_2 , V_40 , sizeof( * V_217 ) * ( V_217 - V_40 ) ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , T_7 * V_185 ,
unsigned long V_96 , unsigned long V_41 ,
V_131 V_242 , int V_215 , int V_216 )
{
int V_60 ;
T_5 * V_183 ;
unsigned long V_243 , V_214 = F_101 ( V_242 ) ;
#ifndef F_102
if ( F_71 ( * V_185 ) ) {
V_183 = ( T_5 * ) F_103 ( V_222 ) ;
if ( ! V_183 )
return - V_33 ;
F_40 ( V_2 , V_183 , V_134 ) ;
F_104 ( NULL , V_185 , V_183 ) ;
F_40 ( V_2 , V_185 , sizeof( * V_185 ) ) ;
V_183 += F_105 ( V_96 ) ;
} else
#endif
V_183 = F_66 ( V_185 , V_96 ) ;
do {
V_243 = F_106 ( V_96 , V_41 ) ;
V_60 = F_90 ( V_2 , V_183 , V_96 , V_243 , V_214 ,
V_215 , V_216 ) ;
V_242 += V_243 - V_96 ;
} while ( V_183 ++ , V_96 = V_243 , V_96 < V_41 );
return V_60 ;
}
static int F_107 ( struct V_1 * V_2 , V_129 * V_127 ,
unsigned long V_96 , unsigned long V_41 ,
V_131 V_242 , int V_215 , int V_216 )
{
int V_60 = 0 ;
T_7 * V_185 ;
unsigned long V_243 ;
#ifndef F_108
if ( F_74 ( * V_127 ) ) {
V_185 = ( T_7 * ) F_103 ( V_222 ) ;
if ( ! V_185 )
return - V_33 ;
F_40 ( V_2 , V_185 , V_134 ) ;
F_109 ( NULL , V_127 , V_185 ) ;
F_40 ( V_2 , V_127 , sizeof( * V_127 ) ) ;
V_185 += F_110 ( V_96 ) ;
} else
#endif
V_185 = F_70 ( V_127 , V_96 ) ;
do {
V_243 = F_111 ( V_96 , V_41 ) ;
V_60 = F_100 ( V_2 , V_185 , V_96 , V_243 , V_242 ,
V_215 , V_216 ) ;
V_242 += V_243 - V_96 ;
} while ( V_185 ++ , V_96 = V_243 , V_96 < V_41 );
return V_60 ;
}
static int F_112 ( struct V_68 * V_69 ,
unsigned long V_65 , V_131 V_244 ,
T_4 V_97 , int V_215 )
{
int V_60 , V_216 ;
unsigned long V_41 ;
V_131 V_245 , V_167 ;
struct V_49 * V_71 = & V_69 -> V_71 ;
V_129 * V_127 = V_71 -> V_127 ;
struct V_1 * V_2 = V_71 -> V_2 ;
unsigned long V_59 ;
if ( V_71 -> V_53 == V_54 ) {
V_216 = 2 ;
V_167 = ( 1ULL << V_2 -> V_138 ) - 1 ;
} else {
V_216 = 1 ;
V_167 = ( 1ULL << V_2 -> V_124 ) - 1 ;
}
if ( ! V_127 )
return - V_208 ;
if ( V_97 & ~ V_99 )
return - V_208 ;
V_245 = ( 1ULL << V_2 -> V_116 ) - 1 ;
if ( ( V_131 ) V_65 & ~ V_245 )
return - V_246 ;
if ( V_244 & ~ V_167 )
return - V_246 ;
F_85 ( & V_69 -> V_182 , V_59 ) ;
V_127 += F_113 ( V_65 ) ;
V_41 = V_65 + V_97 ;
do {
unsigned long V_243 = F_114 ( V_65 , V_41 ) ;
V_60 = F_107 ( V_2 , V_127 , V_65 , V_243 , V_244 ,
V_215 , V_216 ) ;
if ( V_60 )
goto V_38;
V_244 += V_243 - V_65 ;
V_65 = V_243 ;
} while ( V_127 ++ , V_65 != V_41 );
V_38:
F_87 ( & V_69 -> V_182 , V_59 ) ;
return V_60 ;
}
static int F_115 ( struct V_66 * V_67 , unsigned long V_65 ,
V_131 V_244 , T_4 V_97 , int V_215 )
{
struct V_68 * V_69 = V_67 -> V_70 ;
if ( ! V_69 )
return - V_168 ;
if ( ( V_131 ) V_65 & ~ V_69 -> V_167 )
return - V_246 ;
return F_112 ( V_69 , V_65 , V_244 , V_97 , V_215 ) ;
}
static T_4 F_116 ( struct V_66 * V_67 , unsigned long V_65 ,
T_4 V_97 )
{
int V_60 ;
struct V_68 * V_69 = V_67 -> V_70 ;
V_60 = F_112 ( V_69 , V_65 , 0 , V_97 , 0 ) ;
F_29 ( & V_69 -> V_71 ) ;
return V_60 ? 0 : V_97 ;
}
static V_131 F_117 ( struct V_66 * V_67 ,
T_12 V_65 )
{
V_129 * V_247 , V_127 ;
T_7 V_185 ;
T_5 V_183 ;
T_10 V_217 ;
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_49 * V_71 = & V_69 -> V_71 ;
V_247 = V_71 -> V_127 ;
if ( ! V_247 )
return 0 ;
V_127 = * ( V_247 + F_113 ( V_65 ) ) ;
if ( F_74 ( V_127 ) )
return 0 ;
V_185 = * F_70 ( & V_127 , V_65 ) ;
if ( F_71 ( V_185 ) )
return 0 ;
V_183 = * F_66 ( & V_185 , V_65 ) ;
if ( F_67 ( V_183 ) )
return 0 ;
V_217 = * ( F_95 ( V_183 ) + F_96 ( V_65 ) ) ;
if ( F_118 ( V_217 ) )
return 0 ;
return F_119 ( F_120 ( V_217 ) ) | ( V_65 & ~ V_99 ) ;
}
static int F_121 ( struct V_66 * V_67 ,
unsigned long V_248 )
{
unsigned long V_249 = 0 ;
struct V_68 * V_69 = V_67 -> V_70 ;
if ( V_69 -> V_71 . V_2 -> V_100 & V_101 )
V_249 |= V_250 ;
return ! ! ( V_248 & V_249 ) ;
}
static int F_122 ( struct V_23 * V_4 )
{
struct V_1 * V_251 , * V_20 , * V_2 ;
struct V_10 * V_16 = NULL ;
struct V_252 * V_253 ;
int V_60 ;
if ( V_4 -> V_165 . V_166 ) {
F_15 ( V_4 , L_17 ) ;
return - V_208 ;
}
F_13 ( & V_37 ) ;
F_14 (parent, &arm_smmu_devices, list) {
V_2 = V_20 ;
F_14 (child, &arm_smmu_devices, list) {
if ( V_251 -> V_36 == V_20 -> V_4 -> V_5 ) {
V_16 = F_4 ( V_251 , V_4 -> V_5 ) ;
if ( V_16 ) {
V_2 = NULL ;
break;
}
}
}
if ( ! V_2 ) {
V_16 = NULL ;
continue;
}
V_16 = F_4 ( V_2 , V_4 -> V_5 ) ;
if ( V_16 )
break;
}
F_16 ( & V_37 ) ;
if ( ! V_16 )
return - V_168 ;
V_253 = F_123 () ;
if ( F_124 ( V_253 ) ) {
F_10 ( V_4 , L_18 ) ;
return F_125 ( V_253 ) ;
}
V_60 = F_126 ( V_253 , V_4 ) ;
F_127 ( V_253 ) ;
V_4 -> V_165 . V_166 = V_2 ;
return V_60 ;
}
static void F_128 ( struct V_23 * V_4 )
{
V_4 -> V_165 . V_166 = NULL ;
F_129 ( V_4 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
void T_1 * V_44 = F_23 ( V_2 ) ;
void T_1 * V_72 ;
int V_3 = 0 ;
T_3 V_104 ;
V_104 = F_25 ( F_39 ( V_2 ) + V_92 ) ;
F_37 ( V_104 , F_39 ( V_2 ) + V_92 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_195 ; ++ V_3 ) {
F_24 ( ~ V_199 , V_44 + F_78 ( V_3 ) ) ;
F_24 ( V_203 , V_44 + F_81 ( V_3 ) ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_174 ; ++ V_3 ) {
V_72 = F_30 ( V_2 ) + F_31 ( V_2 , V_3 ) ;
F_24 ( 0 , V_72 + V_164 ) ;
F_24 ( V_74 , V_72 + V_73 ) ;
}
F_24 ( 0 , V_44 + V_254 ) ;
F_24 ( 0 , V_44 + V_255 ) ;
F_24 ( 0 , V_44 + V_256 ) ;
V_104 = F_25 ( F_39 ( V_2 ) + V_257 ) ;
V_104 |= ( V_258 | V_259 | V_260 | V_261 ) ;
V_104 |= ( V_262 | V_263 ) ;
V_104 &= ~ ( V_264 | V_265 ) ;
V_104 &= ~ V_266 ;
V_104 &= ~ ( V_267 << V_268 ) ;
F_22 ( V_2 ) ;
F_37 ( V_104 , F_39 ( V_2 ) + V_257 ) ;
}
static int F_131 ( int V_97 )
{
switch ( V_97 ) {
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
static int F_132 ( struct V_1 * V_2 )
{
unsigned long V_97 ;
void T_1 * V_44 = F_23 ( V_2 ) ;
T_3 V_198 ;
F_3 ( V_2 -> V_4 , L_19 ) ;
V_198 = F_25 ( V_44 + V_269 ) ;
V_2 -> V_106 = ( ( V_198 >> V_270 ) & V_271 ) + 1 ;
F_3 ( V_2 -> V_4 , L_20 , V_2 -> V_106 ) ;
V_198 = F_25 ( V_44 + V_272 ) ;
#ifndef F_35
if ( ( ( V_198 >> V_273 ) & V_274 ) == V_275 ) {
F_10 ( V_2 -> V_4 , L_21 ) ;
return - V_168 ;
}
#endif
if ( V_198 & V_276 ) {
V_2 -> V_100 |= V_277 ;
F_3 ( V_2 -> V_4 , L_22 ) ;
}
if ( V_198 & V_278 ) {
V_2 -> V_100 |= V_172 ;
F_3 ( V_2 -> V_4 , L_23 ) ;
}
if ( V_198 & V_279 ) {
V_2 -> V_100 |= V_169 ;
F_3 ( V_2 -> V_4 , L_24 ) ;
}
if ( ! ( V_2 -> V_100 &
( V_277 | V_172 |
V_169 ) ) ) {
F_10 ( V_2 -> V_4 , L_25 ) ;
return - V_168 ;
}
if ( V_198 & V_280 ) {
V_2 -> V_100 |= V_101 ;
F_3 ( V_2 -> V_4 , L_26 ) ;
}
if ( V_198 & V_281 ) {
T_3 V_282 , V_202 , V_197 ;
V_2 -> V_100 |= V_193 ;
V_2 -> V_195 = ( V_198 >> V_283 ) &
V_284 ;
if ( V_2 -> V_195 == 0 ) {
F_10 ( V_2 -> V_4 ,
L_27 ) ;
return - V_168 ;
}
V_282 = V_285 << V_201 ;
V_282 |= ( V_286 << V_200 ) ;
F_24 ( V_282 , V_44 + F_78 ( 0 ) ) ;
V_282 = F_25 ( V_44 + F_78 ( 0 ) ) ;
V_197 = ( V_282 >> V_201 ) & V_285 ;
V_202 = ( V_282 >> V_200 ) & V_286 ;
if ( ( V_197 & V_202 ) != V_202 ) {
F_10 ( V_2 -> V_4 ,
L_28 ,
V_197 , V_202 ) ;
return - V_168 ;
}
F_3 ( V_2 -> V_4 ,
L_29 ,
V_2 -> V_195 , V_197 ) ;
}
V_198 = F_25 ( V_44 + V_287 ) ;
V_2 -> V_288 = ( V_198 & V_289 ) ? V_290 : V_135 ;
V_97 = 1 << ( ( ( V_198 >> V_291 ) & V_292 ) + 1 ) ;
V_97 *= ( V_2 -> V_288 << 1 ) ;
if ( V_2 -> V_97 != V_97 )
F_15 ( V_2 -> V_4 , L_30
L_31 , V_97 , V_2 -> V_97 ) ;
V_2 -> V_171 = ( V_198 >> V_293 ) &
V_294 ;
V_2 -> V_174 = ( V_198 >> V_295 ) & V_296 ;
if ( V_2 -> V_171 > V_2 -> V_174 ) {
F_10 ( V_2 -> V_4 , L_32 ) ;
return - V_168 ;
}
F_3 ( V_2 -> V_4 , L_33 ,
V_2 -> V_174 , V_2 -> V_171 ) ;
V_198 = F_25 ( V_44 + V_297 ) ;
V_97 = F_131 ( ( V_198 >> V_298 ) & V_299 ) ;
#ifdef F_35
V_2 -> V_124 = F_133 ( ( unsigned long ) V_300 , V_97 ) ;
#else
V_2 -> V_124 = F_133 ( 32UL , V_97 ) ;
#endif
V_97 = F_131 ( ( V_198 >> V_301 ) & V_302 ) ;
V_2 -> V_138 = F_133 ( ( unsigned long ) V_303 , V_97 ) ;
if ( V_2 -> V_106 == 1 ) {
V_2 -> V_116 = 32 ;
} else {
#ifdef F_35
V_97 = ( V_198 >> V_304 ) & V_305 ;
V_97 = F_133 ( V_300 , F_131 ( V_97 ) ) ;
#else
V_97 = 32 ;
#endif
V_2 -> V_116 = V_97 ;
if ( ( V_134 == V_135 && ! ( V_198 & V_306 ) ) ||
( V_134 == V_290 && ! ( V_198 & V_307 ) ) ||
( V_134 != V_135 && V_134 != V_290 ) ) {
F_10 ( V_2 -> V_4 , L_34 ,
V_134 ) ;
return - V_168 ;
}
}
F_3 ( V_2 -> V_4 ,
L_35 ,
V_2 -> V_116 , V_2 -> V_124 , V_2 -> V_138 ) ;
return 0 ;
}
static int F_134 ( struct V_308 * V_309 )
{
struct V_310 * V_311 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_23 * V_4 = & V_309 -> V_4 ;
struct V_13 * V_14 ;
struct V_24 V_25 ;
int V_312 , V_3 , V_313 ;
V_2 = F_11 ( V_4 , sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 ) {
F_10 ( V_4 , L_36 ) ;
return - V_33 ;
}
V_2 -> V_4 = V_4 ;
V_311 = F_135 ( V_309 , V_314 , 0 ) ;
V_2 -> V_51 = F_136 ( V_4 , V_311 ) ;
if ( F_124 ( V_2 -> V_51 ) )
return F_125 ( V_2 -> V_51 ) ;
V_2 -> V_97 = F_137 ( V_311 ) ;
if ( F_138 ( V_4 -> V_5 , L_37 ,
& V_2 -> V_177 ) ) {
F_10 ( V_4 , L_38 ) ;
return - V_168 ;
}
V_312 = 0 ;
while ( ( V_311 = F_135 ( V_309 , V_315 , V_312 ) ) ) {
V_312 ++ ;
if ( V_312 > V_2 -> V_177 )
V_2 -> V_175 ++ ;
}
if ( ! V_2 -> V_175 ) {
F_10 ( V_4 , L_39 ,
V_312 , V_2 -> V_177 + 1 ) ;
return - V_168 ;
}
V_2 -> V_176 = F_11 ( V_4 , sizeof( * V_2 -> V_176 ) * V_312 ,
V_32 ) ;
if ( ! V_2 -> V_176 ) {
F_10 ( V_4 , L_40 , V_312 ) ;
return - V_33 ;
}
for ( V_3 = 0 ; V_3 < V_312 ; ++ V_3 ) {
int V_58 = F_139 ( V_309 , V_3 ) ;
if ( V_58 < 0 ) {
F_10 ( V_4 , L_41 , V_3 ) ;
return - V_168 ;
}
V_2 -> V_176 [ V_3 ] = V_58 ;
}
V_3 = 0 ;
V_2 -> V_15 = V_316 ;
while ( ! F_140 ( V_4 -> V_5 , L_42 ,
L_43 , V_3 ,
& V_25 ) ) {
V_313 = F_9 ( V_2 , V_4 , & V_25 ) ;
if ( V_313 ) {
F_10 ( V_4 , L_44 ,
V_25 . V_26 -> V_27 ) ;
goto V_317;
}
V_3 ++ ;
}
F_3 ( V_4 , L_45 , V_3 ) ;
if ( ( V_12 = F_141 ( V_4 -> V_5 , L_46 , 0 ) ) )
V_2 -> V_36 = V_12 ;
V_313 = F_132 ( V_2 ) ;
if ( V_313 )
goto V_318;
F_1 ( V_2 ) ;
if ( V_2 -> V_106 > 1 &&
V_2 -> V_174 != V_2 -> V_175 ) {
F_10 ( V_4 ,
L_47 ,
V_2 -> V_175 , V_2 -> V_174 ) ;
V_313 = - V_168 ;
goto V_318;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_177 ; ++ V_3 ) {
V_313 = F_54 ( V_2 -> V_176 [ V_3 ] ,
F_38 ,
V_178 ,
L_48 ,
V_2 ) ;
if ( V_313 ) {
F_10 ( V_4 , L_49 ,
V_3 , V_2 -> V_176 [ V_3 ] ) ;
goto V_319;
}
}
F_142 ( & V_2 -> V_320 ) ;
F_13 ( & V_37 ) ;
F_143 ( & V_2 -> V_320 , & V_321 ) ;
F_16 ( & V_37 ) ;
F_130 ( V_2 ) ;
return 0 ;
V_319:
while ( V_3 -- )
F_56 ( V_2 -> V_176 [ V_3 ] , V_2 ) ;
V_318:
if ( V_2 -> V_36 )
F_144 ( V_2 -> V_36 ) ;
V_317:
for ( V_14 = F_145 ( & V_2 -> V_15 ) ; V_14 ; V_14 = F_146 ( V_14 ) ) {
struct V_10 * V_16 ;
V_16 = F_5 ( V_14 , struct V_10 , V_14 ) ;
F_144 ( V_16 -> V_5 ) ;
}
return V_313 ;
}
static int F_147 ( struct V_308 * V_309 )
{
int V_3 ;
struct V_23 * V_4 = & V_309 -> V_4 ;
struct V_1 * V_322 , * V_2 = NULL ;
struct V_13 * V_14 ;
F_13 ( & V_37 ) ;
F_14 (curr, &arm_smmu_devices, list) {
if ( V_322 -> V_4 == V_4 ) {
V_2 = V_322 ;
F_148 ( & V_2 -> V_320 ) ;
break;
}
}
F_16 ( & V_37 ) ;
if ( ! V_2 )
return - V_168 ;
if ( V_2 -> V_36 )
F_144 ( V_2 -> V_36 ) ;
for ( V_14 = F_145 ( & V_2 -> V_15 ) ; V_14 ; V_14 = F_146 ( V_14 ) ) {
struct V_10 * V_16 ;
V_16 = F_5 ( V_14 , struct V_10 , V_14 ) ;
F_144 ( V_16 -> V_5 ) ;
}
if ( ! F_149 ( V_2 -> V_173 , V_323 ) )
F_10 ( V_4 , L_50 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_177 ; ++ V_3 )
F_56 ( V_2 -> V_176 [ V_3 ] , V_2 ) ;
F_37 ( V_264 , F_39 ( V_2 ) + V_257 ) ;
return 0 ;
}
static int T_13 F_150 ( void )
{
int V_60 ;
V_60 = F_151 ( & V_324 ) ;
if ( V_60 )
return V_60 ;
if ( ! F_152 ( & V_325 ) )
F_153 ( & V_325 , & V_326 ) ;
#ifdef F_154
if ( ! F_152 ( & V_327 ) )
F_153 ( & V_327 , & V_326 ) ;
#endif
return 0 ;
}
static void T_14 F_155 ( void )
{
return F_156 ( & V_324 ) ;
}

static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 . V_6 ;
while ( V_7 ) {
struct V_1 * V_9 ;
V_9 = F_2 ( V_7 , struct V_1 , V_7 ) ;
if ( V_5 < V_9 -> V_10 )
V_7 = V_7 -> V_11 ;
else if ( V_5 > V_9 -> V_10 )
V_7 = V_7 -> V_12 ;
else
return V_9 ;
}
return NULL ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
struct V_6 * * V_13 , * V_14 ;
V_13 = & V_3 -> V_8 . V_6 ;
V_14 = NULL ;
while ( * V_13 ) {
struct V_1 * V_15 ;
V_15 = F_2 ( * V_13 , struct V_1 , V_7 ) ;
V_14 = * V_13 ;
if ( V_9 -> V_10 < V_15 -> V_10 )
V_13 = & ( ( * V_13 ) -> V_11 ) ;
else if ( V_9 -> V_10 > V_15 -> V_10 )
V_13 = & ( ( * V_13 ) -> V_12 ) ;
else
return - V_16 ;
}
F_4 ( & V_9 -> V_7 , V_14 , V_13 ) ;
F_5 ( & V_9 -> V_7 , & V_3 -> V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
struct V_19 * V_20 )
{
int V_21 ;
struct V_1 * V_9 ;
V_9 = F_1 ( V_3 , V_20 -> V_22 ) ;
if ( V_9 ) {
F_7 ( V_18 ,
L_1 ,
V_20 -> V_22 -> V_23 ) ;
return - V_24 ;
}
if ( V_20 -> V_25 > V_26 ) {
F_7 ( V_18 ,
L_2 ,
V_26 , V_20 -> V_22 -> V_23 ) ;
return - V_27 ;
}
V_9 = F_8 ( V_18 , sizeof( * V_9 ) , V_28 ) ;
if ( ! V_9 )
return - V_29 ;
V_9 -> V_10 = V_20 -> V_22 ;
V_9 -> V_30 = V_20 -> V_25 ;
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 )
V_9 -> V_31 [ V_21 ] = V_20 -> args [ V_21 ] ;
return F_3 ( V_3 , V_9 ) ;
}
static struct V_2 * F_9 ( struct V_2 * V_3 )
{
struct V_2 * V_14 ;
if ( ! V_3 -> V_32 )
return NULL ;
F_10 ( & V_33 ) ;
F_11 (parent, &arm_smmu_devices, list)
if ( V_14 -> V_18 -> V_10 == V_3 -> V_32 )
goto V_34;
V_14 = NULL ;
F_12 ( V_3 -> V_18 ,
L_3 ) ;
V_34:
F_13 ( & V_33 ) ;
return V_14 ;
}
static int F_14 ( unsigned long * V_35 , int V_36 , int V_37 )
{
int V_38 ;
do {
V_38 = F_15 ( V_35 , V_37 , V_36 ) ;
if ( V_38 == V_37 )
return - V_27 ;
} while ( F_16 ( V_38 , V_35 ) );
return V_38 ;
}
static void F_17 ( unsigned long * V_35 , int V_38 )
{
F_18 ( V_38 , V_35 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
int V_39 = 0 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
F_21 ( 0 , V_40 + V_41 ) ;
while ( F_22 ( V_40 + V_42 )
& V_43 ) {
F_23 () ;
if ( ++ V_39 == V_44 ) {
F_24 ( V_3 -> V_18 ,
L_4 ) ;
return;
}
F_25 ( 1 ) ;
}
}
static void F_26 ( struct V_45 * V_46 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
void T_1 * V_47 = F_20 ( V_3 ) ;
bool V_48 = V_46 -> V_49 != V_50 ;
if ( V_48 ) {
V_47 = F_27 ( V_3 ) + F_28 ( V_3 , V_46 -> V_51 ) ;
F_21 ( F_29 ( V_46 ) ,
V_47 + V_52 ) ;
} else {
V_47 = F_20 ( V_3 ) ;
F_21 ( F_30 ( V_46 ) ,
V_47 + V_53 ) ;
}
F_19 ( V_3 ) ;
}
static T_2 F_31 ( int V_54 , void * V_18 )
{
int V_55 , V_56 ;
T_3 V_57 , V_58 , V_59 , V_60 ;
unsigned long V_61 ;
struct V_62 * V_63 = V_18 ;
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_45 * V_67 = & V_65 -> V_67 ;
struct V_2 * V_3 = V_67 -> V_3 ;
void T_1 * V_68 ;
V_68 = F_27 ( V_3 ) + F_28 ( V_3 , V_67 -> V_51 ) ;
V_57 = F_22 ( V_68 + V_69 ) ;
if ( ! ( V_57 & V_70 ) )
return V_71 ;
if ( V_57 & V_72 )
F_24 ( V_3 -> V_18 ,
L_5 ,
V_57 ) ;
V_59 = F_22 ( V_68 + V_73 ) ;
V_55 = V_59 & V_74 ? V_75 : V_76 ;
V_58 = F_22 ( V_68 + V_77 ) ;
V_61 = V_58 ;
#ifdef F_32
V_58 = F_22 ( V_68 + V_78 ) ;
V_61 |= ( ( unsigned long ) V_58 << 32 ) ;
#endif
if ( ! F_33 ( V_63 , V_3 -> V_18 , V_61 , V_55 ) ) {
V_56 = V_79 ;
V_60 = V_80 ;
} else {
F_24 ( V_3 -> V_18 ,
L_6 ,
V_61 , V_59 , V_67 -> V_51 ) ;
V_56 = V_71 ;
V_60 = V_81 ;
}
F_34 ( V_57 , V_68 + V_69 ) ;
if ( V_57 & V_82 )
F_21 ( V_60 , V_68 + V_83 ) ;
return V_56 ;
}
static T_2 F_35 ( int V_54 , void * V_18 )
{
T_3 V_84 , V_85 , V_86 , V_87 ;
struct V_2 * V_3 = V_18 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
V_84 = F_22 ( V_40 + V_88 ) ;
if ( ! V_84 )
return V_71 ;
V_85 = F_22 ( V_40 + V_89 ) ;
V_86 = F_22 ( V_40 + V_90 ) ;
V_87 = F_22 ( V_40 + V_91 ) ;
F_24 ( V_3 -> V_18 ,
L_7 ) ;
F_24 ( V_3 -> V_18 ,
L_8 ,
V_84 , V_85 , V_86 , V_87 ) ;
F_34 ( V_84 , V_40 + V_88 ) ;
return V_79 ;
}
static void F_36 ( struct V_2 * V_3 , void * V_92 ,
T_4 V_93 )
{
unsigned long V_94 = ( unsigned long ) V_92 & ~ V_95 ;
if ( V_3 -> V_96 & V_97 ) {
F_37 () ;
} else {
F_38 ( V_3 -> V_18 , F_39 ( V_92 ) , V_94 , V_93 ,
V_98 ) ;
}
}
static void F_40 ( struct V_64 * V_65 )
{
T_3 V_99 ;
bool V_48 ;
struct V_45 * V_67 = & V_65 -> V_67 ;
struct V_2 * V_3 = V_67 -> V_3 ;
void T_1 * V_68 , * V_40 , * V_100 ;
V_40 = F_20 ( V_3 ) ;
V_100 = F_41 ( V_3 ) ;
V_48 = V_67 -> V_49 != V_50 ;
V_68 = F_27 ( V_3 ) + F_28 ( V_3 , V_67 -> V_51 ) ;
V_99 = V_67 -> V_49 ;
if ( V_3 -> V_101 == 1 )
V_99 |= V_67 -> V_102 << V_103 ;
if ( V_48 ) {
V_99 |= ( V_104 << V_105 ) |
( V_106 << V_107 ) ;
} else {
V_99 |= F_30 ( V_67 ) << V_108 ;
}
F_21 ( V_99 , V_100 + F_42 ( V_67 -> V_51 ) ) ;
if ( V_3 -> V_101 > 1 ) {
#ifdef F_32
V_99 = V_109 ;
#else
V_99 = V_110 ;
#endif
F_21 ( V_99 ,
V_100 + F_43 ( V_67 -> V_51 ) ) ;
switch ( V_3 -> V_111 ) {
case 32 :
V_99 = ( V_112 << V_113 ) ;
break;
case 36 :
V_99 = ( V_114 << V_113 ) ;
break;
case 39 :
V_99 = ( V_115 << V_113 ) ;
break;
case 42 :
V_99 = ( V_116 << V_113 ) ;
break;
case 44 :
V_99 = ( V_117 << V_113 ) ;
break;
case 48 :
V_99 = ( V_118 << V_113 ) ;
break;
}
switch ( V_3 -> V_119 ) {
case 32 :
V_99 |= ( V_112 << V_120 ) ;
break;
case 36 :
V_99 |= ( V_114 << V_120 ) ;
break;
case 39 :
V_99 |= ( V_115 << V_120 ) ;
break;
case 42 :
V_99 |= ( V_116 << V_120 ) ;
break;
case 44 :
V_99 |= ( V_117 << V_120 ) ;
break;
case 48 :
V_99 |= ( V_118 << V_120 ) ;
break;
}
if ( V_48 )
F_21 ( V_99 , V_68 + V_121 ) ;
}
F_36 ( V_3 , V_67 -> V_122 ,
V_123 * sizeof( V_124 ) ) ;
V_99 = F_44 ( V_67 -> V_122 ) ;
F_21 ( V_99 , V_68 + V_125 ) ;
V_99 = ( V_126 ) F_44 ( V_67 -> V_122 ) >> 32 ;
if ( V_48 )
V_99 |= F_29 ( V_67 ) << V_127 ;
F_21 ( V_99 , V_68 + V_128 ) ;
if ( V_3 -> V_101 > 1 ) {
if ( V_129 == V_130 )
V_99 = V_131 ;
else
V_99 = V_132 ;
if ( ! V_48 ) {
switch ( V_3 -> V_133 ) {
case 32 :
V_99 |= ( V_112 << V_134 ) ;
break;
case 36 :
V_99 |= ( V_114 << V_134 ) ;
break;
case 40 :
V_99 |= ( V_115 << V_134 ) ;
break;
case 42 :
V_99 |= ( V_116 << V_134 ) ;
break;
case 44 :
V_99 |= ( V_117 << V_134 ) ;
break;
case 48 :
V_99 |= ( V_118 << V_134 ) ;
break;
}
} else {
V_99 |= ( 64 - V_3 -> V_119 ) << V_135 ;
}
} else {
V_99 = 0 ;
}
V_99 |= V_136 |
( V_137 << V_138 ) |
( V_139 << V_140 ) |
( V_139 << V_141 ) |
( V_142 << V_143 ) ;
F_21 ( V_99 , V_68 + V_144 ) ;
if ( V_48 ) {
V_99 = ( V_145 << F_45 ( V_146 ) ) |
( V_147 << F_45 ( V_148 ) ) |
( V_149 << F_45 ( V_150 ) ) ;
F_21 ( V_99 , V_68 + V_151 ) ;
}
V_99 = V_152 | V_153 | V_154 | V_155 | V_156 ;
if ( V_48 )
V_99 |= V_157 ;
#ifdef F_46
V_99 |= V_158 ;
#endif
F_21 ( V_99 , V_68 + V_159 ) ;
}
static int F_47 ( struct V_62 * V_63 ,
struct V_17 * V_18 )
{
int V_54 , V_56 , V_36 ;
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_45 * V_67 = & V_65 -> V_67 ;
struct V_2 * V_3 , * V_14 ;
V_14 = V_18 -> V_160 . V_161 ;
V_65 -> V_162 = - 1 ;
do {
V_3 = V_14 ;
V_65 -> V_162 &= ( 1ULL << V_3 -> V_133 ) - 1 ;
} while ( ( V_14 = F_9 ( V_3 ) ) );
if ( ! F_1 ( V_3 , V_18 -> V_10 ) ) {
F_7 ( V_18 , L_9 ) ;
return - V_163 ;
}
if ( V_3 -> V_96 & V_164 ) {
V_67 -> V_49 = V_165 ;
V_36 = V_3 -> V_166 ;
} else if ( V_3 -> V_96 & V_167 ) {
V_67 -> V_49 = V_50 ;
V_36 = 0 ;
} else {
V_67 -> V_49 = V_165 ;
V_36 = V_3 -> V_166 ;
}
V_56 = F_14 ( V_3 -> V_168 , V_36 ,
V_3 -> V_169 ) ;
if ( F_48 ( V_56 ) )
return V_56 ;
V_67 -> V_51 = V_56 ;
if ( V_3 -> V_101 == 1 ) {
V_67 -> V_102 = F_49 ( & V_3 -> V_102 ) ;
V_67 -> V_102 %= V_3 -> V_170 ;
} else {
V_67 -> V_102 = V_67 -> V_51 ;
}
V_54 = V_3 -> V_171 [ V_3 -> V_172 + V_67 -> V_102 ] ;
V_56 = F_50 ( V_54 , F_31 , V_173 ,
L_10 , V_63 ) ;
if ( F_48 ( V_56 ) ) {
F_7 ( V_3 -> V_18 , L_11 ,
V_67 -> V_102 , V_54 ) ;
V_67 -> V_102 = V_174 ;
goto V_175;
}
V_67 -> V_3 = V_3 ;
F_40 ( V_65 ) ;
return V_56 ;
V_175:
F_17 ( V_3 -> V_168 , V_67 -> V_51 ) ;
return V_56 ;
}
static void F_51 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_45 * V_67 = & V_65 -> V_67 ;
struct V_2 * V_3 = V_67 -> V_3 ;
void T_1 * V_68 ;
int V_54 ;
if ( ! V_3 )
return;
V_68 = F_27 ( V_3 ) + F_28 ( V_3 , V_67 -> V_51 ) ;
F_21 ( 0 , V_68 + V_159 ) ;
F_26 ( V_67 ) ;
if ( V_67 -> V_102 != V_174 ) {
V_54 = V_3 -> V_171 [ V_3 -> V_172 + V_67 -> V_102 ] ;
F_52 ( V_54 , V_63 ) ;
}
F_17 ( V_3 -> V_168 , V_67 -> V_51 ) ;
}
static int F_53 ( struct V_62 * V_63 )
{
struct V_64 * V_65 ;
V_124 * V_122 ;
V_65 = F_54 ( sizeof( * V_65 ) , V_28 ) ;
if ( ! V_65 )
return - V_29 ;
V_122 = F_54 ( V_123 * sizeof( V_124 ) , V_28 ) ;
if ( ! V_122 )
goto V_176;
V_65 -> V_67 . V_122 = V_122 ;
F_55 ( & V_65 -> V_177 ) ;
V_63 -> V_66 = V_65 ;
return 0 ;
V_176:
F_56 ( V_65 ) ;
return - V_29 ;
}
static void F_57 ( T_5 * V_178 )
{
T_6 V_179 = F_58 ( * V_178 ) ;
F_59 ( V_179 ) ;
F_60 ( V_179 ) ;
}
static void F_61 ( T_7 * V_180 )
{
int V_21 ;
T_5 * V_178 , * V_181 = F_62 ( V_180 , 0 ) ;
V_178 = V_181 ;
for ( V_21 = 0 ; V_21 < V_182 ; ++ V_21 ) {
if ( F_63 ( * V_178 ) )
continue;
F_57 ( V_178 ) ;
V_178 ++ ;
}
F_64 ( NULL , V_181 ) ;
}
static void F_65 ( V_124 * V_122 )
{
int V_21 ;
T_7 * V_180 , * V_183 = F_66 ( V_122 , 0 ) ;
V_180 = V_183 ;
for ( V_21 = 0 ; V_21 < V_184 ; ++ V_21 ) {
if ( F_67 ( * V_180 ) )
continue;
F_61 ( V_180 ) ;
V_180 ++ ;
}
F_68 ( NULL , V_183 ) ;
}
static void F_69 ( struct V_64 * V_65 )
{
int V_21 ;
struct V_45 * V_67 = & V_65 -> V_67 ;
V_124 * V_122 , * V_185 = V_67 -> V_122 ;
V_122 = V_185 ;
for ( V_21 = 0 ; V_21 < V_123 ; ++ V_21 ) {
if ( F_70 ( * V_122 ) )
continue;
F_65 ( V_122 ) ;
V_122 ++ ;
}
F_56 ( V_185 ) ;
}
static void F_71 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
F_51 ( V_63 ) ;
F_69 ( V_65 ) ;
F_56 ( V_65 ) ;
}
static int F_72 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
int V_21 ;
struct V_186 * V_187 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
if ( ! ( V_3 -> V_96 & V_188 ) )
return 0 ;
if ( V_9 -> V_187 )
return - V_16 ;
V_187 = F_73 ( sizeof( * V_187 ) * V_9 -> V_30 , V_28 ) ;
if ( ! V_187 ) {
F_7 ( V_3 -> V_18 , L_12 ,
V_9 -> V_30 , V_9 -> V_10 -> V_23 ) ;
return - V_29 ;
}
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 ) {
int V_38 = F_14 ( V_3 -> V_189 , 0 ,
V_3 -> V_190 ) ;
if ( F_48 ( V_38 ) ) {
F_7 ( V_3 -> V_18 , L_13 ) ;
goto V_191;
}
V_187 [ V_21 ] = (struct V_186 ) {
. V_38 = V_38 ,
. V_192 = 0 ,
. V_193 = V_9 -> V_31 [ V_21 ] ,
} ;
}
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 ) {
T_3 V_99 = V_194 | V_187 [ V_21 ] . V_193 << V_195 |
V_187 [ V_21 ] . V_192 << V_196 ;
F_21 ( V_99 , V_40 + F_74 ( V_187 [ V_21 ] . V_38 ) ) ;
}
V_9 -> V_187 = V_187 ;
return 0 ;
V_191:
while ( -- V_21 >= 0 )
F_17 ( V_3 -> V_189 , V_187 [ V_21 ] . V_38 ) ;
F_56 ( V_187 ) ;
return - V_27 ;
}
static void F_75 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
int V_21 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
struct V_186 * V_187 = V_9 -> V_187 ;
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 ) {
T_8 V_38 = V_187 [ V_21 ] . V_38 ;
F_21 ( ~ V_194 , V_40 + F_74 ( V_38 ) ) ;
F_17 ( V_3 -> V_189 , V_38 ) ;
}
V_9 -> V_187 = NULL ;
F_56 ( V_187 ) ;
}
static void F_76 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
int V_21 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 ) {
T_9 V_197 = V_9 -> V_31 [ V_21 ] ;
F_21 ( V_198 ,
V_40 + F_77 ( V_197 ) ) ;
}
}
static int F_78 ( struct V_64 * V_65 ,
struct V_1 * V_9 )
{
int V_21 , V_56 ;
struct V_2 * V_14 , * V_3 = V_65 -> V_67 . V_3 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
V_56 = F_72 ( V_3 , V_9 ) ;
if ( V_56 )
return V_56 ;
V_3 = V_65 -> V_199 ;
while ( ( V_14 = F_9 ( V_3 ) ) ) {
if ( V_3 -> V_96 & V_188 )
continue;
F_76 ( V_3 , V_9 ) ;
V_3 = V_14 ;
}
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 ) {
T_3 V_38 , V_200 ;
V_38 = V_9 -> V_187 ? V_9 -> V_187 [ V_21 ] . V_38 : V_9 -> V_31 [ V_21 ] ;
V_200 = ( V_201 << V_202 ) |
( V_65 -> V_67 . V_51 << V_203 ) ;
F_21 ( V_200 , V_40 + F_77 ( V_38 ) ) ;
}
return 0 ;
}
static void F_79 ( struct V_64 * V_65 ,
struct V_1 * V_9 )
{
struct V_2 * V_3 = V_65 -> V_67 . V_3 ;
F_76 ( V_3 , V_9 ) ;
F_75 ( V_3 , V_9 ) ;
}
static int F_80 ( struct V_62 * V_63 , struct V_17 * V_18 )
{
int V_56 = - V_204 ;
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_2 * V_205 = V_18 -> V_160 . V_161 ;
struct V_1 * V_9 ;
unsigned long V_55 ;
if ( ! V_205 ) {
F_7 ( V_18 , L_14 ) ;
return - V_206 ;
}
F_81 ( & V_65 -> V_177 , V_55 ) ;
if ( ! V_65 -> V_199 ) {
V_56 = F_47 ( V_63 , V_18 ) ;
if ( F_48 ( V_56 ) )
goto V_207;
V_65 -> V_199 = V_205 ;
} else if ( V_65 -> V_199 != V_205 ) {
F_7 ( V_18 ,
L_15 ,
F_82 ( V_65 -> V_199 -> V_18 ) ,
F_82 ( V_205 -> V_18 ) ) ;
goto V_207;
}
F_83 ( & V_65 -> V_177 , V_55 ) ;
V_9 = F_1 ( V_65 -> V_199 , V_18 -> V_10 ) ;
if ( ! V_9 )
return - V_163 ;
return F_78 ( V_65 , V_9 ) ;
V_207:
F_83 ( & V_65 -> V_177 , V_55 ) ;
return V_56 ;
}
static void F_84 ( struct V_62 * V_63 , struct V_17 * V_18 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_1 * V_9 ;
V_9 = F_1 ( V_65 -> V_199 , V_18 -> V_10 ) ;
if ( V_9 )
F_79 ( V_65 , V_9 ) ;
}
static bool F_85 ( unsigned long V_92 ,
unsigned long V_37 )
{
return ! ( V_92 & ~ V_208 ) &&
( V_92 + V_209 <= V_37 ) ;
}
static int F_86 ( struct V_2 * V_3 , T_5 * V_178 ,
unsigned long V_92 , unsigned long V_37 ,
unsigned long V_210 , int V_55 , int V_211 )
{
T_10 * V_212 , * V_36 ;
T_11 V_213 = V_214 | V_215 | V_216 ;
if ( F_63 ( * V_178 ) ) {
T_6 V_179 = F_87 ( V_217 | V_218 ) ;
if ( ! V_179 )
return - V_29 ;
F_36 ( V_3 , F_88 ( V_179 ) , V_129 ) ;
if ( ! F_89 ( V_179 ) ) {
F_60 ( V_179 ) ;
return - V_29 ;
}
F_90 ( NULL , V_178 , V_179 ) ;
F_36 ( V_3 , V_178 , sizeof( * V_178 ) ) ;
}
if ( V_211 == 1 ) {
V_213 |= V_219 | V_220 ;
if ( ! ( V_55 & V_221 ) && ( V_55 & V_222 ) )
V_213 |= V_223 ;
if ( V_55 & V_224 )
V_213 |= ( V_148 <<
V_225 ) ;
} else {
V_213 |= V_226 ;
if ( V_55 & V_222 )
V_213 |= V_227 ;
if ( V_55 & V_221 )
V_213 |= V_228 ;
if ( V_55 & V_224 )
V_213 |= V_229 ;
else
V_213 |= V_230 ;
}
if ( V_55 & V_231 )
V_213 &= ~ V_216 ;
else if ( ! ( V_55 & ( V_222 | V_221 ) ) )
V_213 &= ~ V_214 ;
V_213 |= V_232 ;
V_36 = F_91 ( * V_178 ) + F_92 ( V_92 ) ;
V_212 = V_36 ;
do {
int V_21 = 1 ;
V_213 &= ~ V_233 ;
if ( F_85 ( V_92 , V_37 ) ) {
V_21 = V_234 ;
V_213 |= V_233 ;
} else if ( F_93 ( * V_212 ) &
( V_233 | V_214 ) ) {
int V_235 ;
T_10 * V_236 ;
unsigned long V_38 = F_92 ( V_92 ) ;
V_38 &= ~ ( V_234 - 1 ) ;
V_236 = F_91 ( * V_178 ) + V_38 ;
for ( V_235 = 0 ; V_235 < V_234 ; ++ V_235 )
F_93 ( * ( V_236 + V_235 ) ) &= ~ V_233 ;
F_36 ( V_3 , V_236 ,
sizeof( * V_212 ) *
V_234 ) ;
}
do {
* V_212 = F_94 ( V_210 , F_95 ( V_213 ) ) ;
} while ( V_212 ++ , V_210 ++ , V_92 += V_129 , -- V_21 );
} while ( V_92 != V_37 );
F_36 ( V_3 , V_36 , sizeof( * V_212 ) * ( V_212 - V_36 ) ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 , T_7 * V_180 ,
unsigned long V_92 , unsigned long V_37 ,
V_126 V_237 , int V_55 , int V_211 )
{
int V_56 ;
T_5 * V_178 ;
unsigned long V_238 , V_210 = F_97 ( V_237 ) ;
#ifndef F_98
if ( F_67 ( * V_180 ) ) {
V_178 = ( T_5 * ) F_99 ( V_217 ) ;
if ( ! V_178 )
return - V_29 ;
F_36 ( V_3 , V_178 , V_129 ) ;
F_100 ( NULL , V_180 , V_178 ) ;
F_36 ( V_3 , V_180 , sizeof( * V_180 ) ) ;
V_178 += F_101 ( V_92 ) ;
} else
#endif
V_178 = F_62 ( V_180 , V_92 ) ;
do {
V_238 = F_102 ( V_92 , V_37 ) ;
V_56 = F_86 ( V_3 , V_178 , V_92 , V_37 , V_210 ,
V_55 , V_211 ) ;
V_237 += V_238 - V_92 ;
} while ( V_178 ++ , V_92 = V_238 , V_92 < V_37 );
return V_56 ;
}
static int F_103 ( struct V_2 * V_3 , V_124 * V_122 ,
unsigned long V_92 , unsigned long V_37 ,
V_126 V_237 , int V_55 , int V_211 )
{
int V_56 = 0 ;
T_7 * V_180 ;
unsigned long V_238 ;
#ifndef F_104
if ( F_70 ( * V_122 ) ) {
V_180 = ( T_7 * ) F_99 ( V_217 ) ;
if ( ! V_180 )
return - V_29 ;
F_36 ( V_3 , V_180 , V_129 ) ;
F_105 ( NULL , V_122 , V_180 ) ;
F_36 ( V_3 , V_122 , sizeof( * V_122 ) ) ;
V_180 += F_106 ( V_92 ) ;
} else
#endif
V_180 = F_66 ( V_122 , V_92 ) ;
do {
V_238 = F_107 ( V_92 , V_37 ) ;
V_56 = F_96 ( V_3 , V_180 , V_92 , V_238 , V_237 ,
V_55 , V_211 ) ;
V_237 += V_238 - V_92 ;
} while ( V_180 ++ , V_92 = V_238 , V_92 < V_37 );
return V_56 ;
}
static int F_108 ( struct V_64 * V_65 ,
unsigned long V_61 , V_126 V_239 ,
T_4 V_93 , int V_55 )
{
int V_56 , V_211 ;
unsigned long V_37 ;
V_126 V_240 , V_162 ;
struct V_45 * V_67 = & V_65 -> V_67 ;
V_124 * V_122 = V_67 -> V_122 ;
struct V_2 * V_3 = V_67 -> V_3 ;
unsigned long V_241 ;
if ( V_67 -> V_49 == V_50 ) {
V_211 = 2 ;
V_162 = ( 1ULL << V_3 -> V_133 ) - 1 ;
} else {
V_211 = 1 ;
V_162 = ( 1ULL << V_3 -> V_119 ) - 1 ;
}
if ( ! V_122 )
return - V_204 ;
if ( V_93 & ~ V_95 )
return - V_204 ;
V_240 = ( 1ULL << V_3 -> V_111 ) - 1 ;
if ( ( V_126 ) V_61 & ~ V_240 )
return - V_242 ;
if ( V_239 & ~ V_162 )
return - V_242 ;
F_81 ( & V_65 -> V_177 , V_241 ) ;
V_122 += F_109 ( V_61 ) ;
V_37 = V_61 + V_93 ;
do {
unsigned long V_238 = F_110 ( V_61 , V_37 ) ;
V_56 = F_103 ( V_3 , V_122 , V_61 , V_238 , V_239 ,
V_55 , V_211 ) ;
if ( V_56 )
goto V_34;
V_239 += V_238 - V_61 ;
V_61 = V_238 ;
} while ( V_122 ++ , V_61 != V_37 );
V_34:
F_83 ( & V_65 -> V_177 , V_241 ) ;
return V_56 ;
}
static int F_111 ( struct V_62 * V_63 , unsigned long V_61 ,
V_126 V_239 , T_4 V_93 , int V_55 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
if ( ! V_65 )
return - V_163 ;
if ( ( V_126 ) V_61 & ~ V_65 -> V_162 )
return - V_242 ;
return F_108 ( V_65 , V_61 , V_239 , V_93 , V_55 ) ;
}
static T_4 F_112 ( struct V_62 * V_63 , unsigned long V_61 ,
T_4 V_93 )
{
int V_56 ;
struct V_64 * V_65 = V_63 -> V_66 ;
V_56 = F_108 ( V_65 , V_61 , 0 , V_93 , 0 ) ;
F_26 ( & V_65 -> V_67 ) ;
return V_56 ? V_56 : V_93 ;
}
static V_126 F_113 ( struct V_62 * V_63 ,
T_12 V_61 )
{
V_124 * V_243 , V_122 ;
T_7 V_180 ;
T_5 V_178 ;
T_10 V_212 ;
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_45 * V_67 = & V_65 -> V_67 ;
V_243 = V_67 -> V_122 ;
if ( ! V_243 )
return 0 ;
V_122 = * ( V_243 + F_109 ( V_61 ) ) ;
if ( F_70 ( V_122 ) )
return 0 ;
V_180 = * F_66 ( & V_122 , V_61 ) ;
if ( F_67 ( V_180 ) )
return 0 ;
V_178 = * F_62 ( & V_180 , V_61 ) ;
if ( F_63 ( V_178 ) )
return 0 ;
V_212 = * ( F_91 ( V_178 ) + F_92 ( V_61 ) ) ;
if ( F_114 ( V_212 ) )
return 0 ;
return F_115 ( F_116 ( V_212 ) ) | ( V_61 & ~ V_95 ) ;
}
static int F_117 ( struct V_62 * V_63 ,
unsigned long V_244 )
{
unsigned long V_245 = 0 ;
struct V_64 * V_65 = V_63 -> V_66 ;
if ( V_65 -> V_67 . V_3 -> V_96 & V_97 )
V_245 |= V_246 ;
return ! ! ( V_244 & V_245 ) ;
}
static int F_118 ( struct V_17 * V_18 )
{
struct V_2 * V_247 , * V_14 , * V_3 ;
struct V_1 * V_9 = NULL ;
struct V_248 * V_249 ;
int V_56 ;
if ( V_18 -> V_160 . V_161 ) {
F_12 ( V_18 , L_16 ) ;
return - V_204 ;
}
F_10 ( & V_33 ) ;
F_11 (parent, &arm_smmu_devices, list) {
V_3 = V_14 ;
F_11 (child, &arm_smmu_devices, list) {
if ( V_247 -> V_32 == V_14 -> V_18 -> V_10 ) {
V_9 = F_1 ( V_247 , V_18 -> V_10 ) ;
if ( V_9 ) {
V_3 = NULL ;
break;
}
}
}
if ( ! V_3 ) {
V_9 = NULL ;
continue;
}
V_9 = F_1 ( V_3 , V_18 -> V_10 ) ;
if ( V_9 )
break;
}
F_13 ( & V_33 ) ;
if ( ! V_9 )
return - V_163 ;
V_249 = F_119 () ;
if ( F_120 ( V_249 ) ) {
F_7 ( V_18 , L_17 ) ;
return F_121 ( V_249 ) ;
}
V_56 = F_122 ( V_249 , V_18 ) ;
F_123 ( V_249 ) ;
V_18 -> V_160 . V_161 = V_3 ;
return V_56 ;
}
static void F_124 ( struct V_17 * V_18 )
{
V_18 -> V_160 . V_161 = NULL ;
F_125 ( V_18 ) ;
}
static void F_126 ( struct V_2 * V_3 )
{
void T_1 * V_40 = F_20 ( V_3 ) ;
void T_1 * V_68 ;
int V_21 = 0 ;
T_3 V_99 ;
V_99 = F_22 ( V_40 + V_88 ) ;
F_34 ( V_99 , V_40 + V_88 ) ;
for ( V_21 = 0 ; V_21 < V_3 -> V_190 ; ++ V_21 ) {
F_21 ( ~ V_194 , V_40 + F_74 ( V_21 ) ) ;
F_21 ( V_198 , V_40 + F_77 ( V_21 ) ) ;
}
for ( V_21 = 0 ; V_21 < V_3 -> V_169 ; ++ V_21 ) {
V_68 = F_27 ( V_3 ) + F_28 ( V_3 , V_21 ) ;
F_21 ( 0 , V_68 + V_159 ) ;
F_21 ( V_70 , V_68 + V_69 ) ;
}
F_21 ( 0 , V_40 + V_250 ) ;
F_21 ( 0 , V_40 + V_251 ) ;
F_21 ( 0 , V_40 + V_252 ) ;
V_99 = F_22 ( V_40 + V_253 ) ;
V_99 |= ( V_254 | V_255 | V_256 | V_257 ) ;
V_99 |= ( V_258 | V_259 ) ;
V_99 &= ~ ( V_260 | V_261 ) ;
V_99 &= ~ V_262 ;
V_99 &= ~ ( V_263 << V_264 ) ;
F_19 ( V_3 ) ;
F_21 ( V_99 , V_40 + V_253 ) ;
}
static int F_127 ( int V_93 )
{
switch ( V_93 ) {
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
static int F_128 ( struct V_2 * V_3 )
{
unsigned long V_93 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
T_3 V_193 ;
F_129 ( V_3 -> V_18 , L_18 ) ;
V_193 = F_22 ( V_40 + V_265 ) ;
V_3 -> V_101 = ( ( V_193 >> V_266 ) & V_267 ) + 1 ;
F_129 ( V_3 -> V_18 , L_19 , V_3 -> V_101 ) ;
V_193 = F_22 ( V_40 + V_268 ) ;
#ifndef F_32
if ( ( ( V_193 >> V_269 ) & V_270 ) == V_271 ) {
F_7 ( V_3 -> V_18 , L_20 ) ;
return - V_163 ;
}
#endif
if ( V_193 & V_272 ) {
V_3 -> V_96 |= V_273 ;
F_129 ( V_3 -> V_18 , L_21 ) ;
}
if ( V_193 & V_274 ) {
V_3 -> V_96 |= V_167 ;
F_129 ( V_3 -> V_18 , L_22 ) ;
}
if ( V_193 & V_275 ) {
V_3 -> V_96 |= V_164 ;
F_129 ( V_3 -> V_18 , L_23 ) ;
}
if ( ! ( V_3 -> V_96 &
( V_273 | V_167 |
V_164 ) ) ) {
F_7 ( V_3 -> V_18 , L_24 ) ;
return - V_163 ;
}
if ( V_193 & V_276 ) {
V_3 -> V_96 |= V_97 ;
F_129 ( V_3 -> V_18 , L_25 ) ;
}
if ( V_193 & V_277 ) {
T_3 V_278 , V_197 , V_192 ;
V_3 -> V_96 |= V_188 ;
V_3 -> V_190 = ( V_193 >> V_279 ) &
V_280 ;
if ( V_3 -> V_190 == 0 ) {
F_7 ( V_3 -> V_18 ,
L_26 ) ;
return - V_163 ;
}
V_278 = V_281 << V_196 ;
V_278 |= ( V_282 << V_195 ) ;
F_21 ( V_278 , V_40 + F_74 ( 0 ) ) ;
V_278 = F_22 ( V_40 + F_74 ( 0 ) ) ;
V_192 = ( V_278 >> V_196 ) & V_281 ;
V_197 = ( V_278 >> V_195 ) & V_282 ;
if ( ( V_192 & V_197 ) != V_197 ) {
F_7 ( V_3 -> V_18 ,
L_27 ,
V_192 , V_197 ) ;
return - V_163 ;
}
F_129 ( V_3 -> V_18 ,
L_28 ,
V_3 -> V_190 , V_192 ) ;
}
V_193 = F_22 ( V_40 + V_283 ) ;
V_3 -> V_284 = ( V_193 & V_285 ) ? V_286 : V_130 ;
V_93 = 1 << ( ( ( V_193 >> V_287 ) & V_288 ) + 1 ) ;
V_93 *= ( V_3 -> V_284 << 1 ) ;
if ( V_3 -> V_93 != V_93 )
F_12 ( V_3 -> V_18 , L_29
L_30 , V_93 , V_3 -> V_93 ) ;
V_3 -> V_166 = ( V_193 >> V_289 ) &
V_290 ;
V_3 -> V_169 = ( V_193 >> V_291 ) & V_292 ;
if ( V_3 -> V_166 > V_3 -> V_169 ) {
F_7 ( V_3 -> V_18 , L_31 ) ;
return - V_163 ;
}
F_129 ( V_3 -> V_18 , L_32 ,
V_3 -> V_169 , V_3 -> V_166 ) ;
V_193 = F_22 ( V_40 + V_293 ) ;
V_93 = F_127 ( ( V_193 >> V_294 ) & V_295 ) ;
#ifdef F_32
V_3 -> V_119 = F_130 ( 39UL , V_93 ) ;
#else
V_3 -> V_119 = F_130 ( 32UL , V_93 ) ;
#endif
V_93 = F_127 ( ( V_193 >> V_296 ) & V_297 ) ;
V_3 -> V_133 = F_130 ( ( unsigned long ) V_298 , V_93 ) ;
if ( V_3 -> V_101 == 1 ) {
V_3 -> V_111 = 32 ;
} else {
#ifdef F_32
V_93 = ( V_193 >> V_299 ) & V_300 ;
V_93 = F_130 ( V_301 , F_127 ( V_93 ) ) ;
#else
V_93 = 32 ;
#endif
V_3 -> V_111 = V_93 ;
if ( ( V_129 == V_130 && ! ( V_193 & V_302 ) ) ||
( V_129 == V_286 && ! ( V_193 & V_303 ) ) ||
( V_129 != V_130 && V_129 != V_286 ) ) {
F_7 ( V_3 -> V_18 , L_33 ,
V_129 ) ;
return - V_163 ;
}
}
F_129 ( V_3 -> V_18 ,
L_34 ,
V_3 -> V_111 , V_3 -> V_119 , V_3 -> V_133 ) ;
return 0 ;
}
static int F_131 ( struct V_304 * V_305 )
{
struct V_306 * V_307 ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_17 * V_18 = & V_305 -> V_18 ;
struct V_6 * V_7 ;
struct V_19 V_20 ;
int V_308 , V_21 , V_309 ;
V_3 = F_8 ( V_18 , sizeof( * V_3 ) , V_28 ) ;
if ( ! V_3 ) {
F_7 ( V_18 , L_35 ) ;
return - V_29 ;
}
V_3 -> V_18 = V_18 ;
V_307 = F_132 ( V_305 , V_310 , 0 ) ;
V_3 -> V_47 = F_133 ( V_18 , V_307 ) ;
if ( F_120 ( V_3 -> V_47 ) )
return F_121 ( V_3 -> V_47 ) ;
V_3 -> V_93 = F_134 ( V_307 ) ;
if ( F_135 ( V_18 -> V_10 , L_36 ,
& V_3 -> V_172 ) ) {
F_7 ( V_18 , L_37 ) ;
return - V_163 ;
}
V_308 = 0 ;
while ( ( V_307 = F_132 ( V_305 , V_311 , V_308 ) ) ) {
V_308 ++ ;
if ( V_308 > V_3 -> V_172 )
V_3 -> V_170 ++ ;
}
if ( ! V_3 -> V_170 ) {
F_7 ( V_18 , L_38 ,
V_308 , V_3 -> V_172 + 1 ) ;
return - V_163 ;
}
V_3 -> V_171 = F_8 ( V_18 , sizeof( * V_3 -> V_171 ) * V_308 ,
V_28 ) ;
if ( ! V_3 -> V_171 ) {
F_7 ( V_18 , L_39 , V_308 ) ;
return - V_29 ;
}
for ( V_21 = 0 ; V_21 < V_308 ; ++ V_21 ) {
int V_54 = F_136 ( V_305 , V_21 ) ;
if ( V_54 < 0 ) {
F_7 ( V_18 , L_40 , V_21 ) ;
return - V_163 ;
}
V_3 -> V_171 [ V_21 ] = V_54 ;
}
V_21 = 0 ;
V_3 -> V_8 = V_312 ;
while ( ! F_137 ( V_18 -> V_10 , L_41 ,
L_42 , V_21 ,
& V_20 ) ) {
V_309 = F_6 ( V_3 , V_18 , & V_20 ) ;
if ( V_309 ) {
F_7 ( V_18 , L_43 ,
V_20 . V_22 -> V_23 ) ;
goto V_313;
}
V_21 ++ ;
}
F_129 ( V_18 , L_44 , V_21 ) ;
if ( ( V_5 = F_138 ( V_18 -> V_10 , L_45 , 0 ) ) )
V_3 -> V_32 = V_5 ;
V_309 = F_128 ( V_3 ) ;
if ( V_309 )
goto V_314;
if ( V_3 -> V_101 > 1 &&
V_3 -> V_169 != V_3 -> V_170 ) {
F_7 ( V_18 ,
L_46 ,
V_3 -> V_170 , V_3 -> V_169 ) ;
V_309 = - V_163 ;
goto V_314;
}
for ( V_21 = 0 ; V_21 < V_3 -> V_172 ; ++ V_21 ) {
V_309 = F_50 ( V_3 -> V_171 [ V_21 ] ,
F_35 ,
V_173 ,
L_47 ,
V_3 ) ;
if ( V_309 ) {
F_7 ( V_18 , L_48 ,
V_21 , V_3 -> V_171 [ V_21 ] ) ;
goto V_315;
}
}
F_139 ( & V_3 -> V_316 ) ;
F_10 ( & V_33 ) ;
F_140 ( & V_3 -> V_316 , & V_317 ) ;
F_13 ( & V_33 ) ;
F_126 ( V_3 ) ;
return 0 ;
V_315:
while ( V_21 -- )
F_52 ( V_3 -> V_171 [ V_21 ] , V_3 ) ;
V_314:
if ( V_3 -> V_32 )
F_141 ( V_3 -> V_32 ) ;
V_313:
for ( V_7 = F_142 ( & V_3 -> V_8 ) ; V_7 ; V_7 = F_143 ( V_7 ) ) {
struct V_1 * V_9 ;
V_9 = F_2 ( V_7 , struct V_1 , V_7 ) ;
F_141 ( V_9 -> V_10 ) ;
}
return V_309 ;
}
static int F_144 ( struct V_304 * V_305 )
{
int V_21 ;
struct V_17 * V_18 = & V_305 -> V_18 ;
struct V_2 * V_318 , * V_3 = NULL ;
struct V_6 * V_7 ;
F_10 ( & V_33 ) ;
F_11 (curr, &arm_smmu_devices, list) {
if ( V_318 -> V_18 == V_18 ) {
V_3 = V_318 ;
F_145 ( & V_3 -> V_316 ) ;
break;
}
}
F_13 ( & V_33 ) ;
if ( ! V_3 )
return - V_163 ;
if ( V_3 -> V_32 )
F_141 ( V_3 -> V_32 ) ;
for ( V_7 = F_142 ( & V_3 -> V_8 ) ; V_7 ; V_7 = F_143 ( V_7 ) ) {
struct V_1 * V_9 ;
V_9 = F_2 ( V_7 , struct V_1 , V_7 ) ;
F_141 ( V_9 -> V_10 ) ;
}
if ( ! F_146 ( V_3 -> V_168 , V_319 ) )
F_7 ( V_18 , L_49 ) ;
for ( V_21 = 0 ; V_21 < V_3 -> V_172 ; ++ V_21 )
F_52 ( V_3 -> V_171 [ V_21 ] , V_3 ) ;
F_21 ( V_260 , F_20 ( V_3 ) + V_253 ) ;
return 0 ;
}
static int T_13 F_147 ( void )
{
int V_56 ;
V_56 = F_148 ( & V_320 ) ;
if ( V_56 )
return V_56 ;
if ( ! F_149 ( & V_321 ) )
F_150 ( & V_321 , & V_322 ) ;
#ifdef F_151
if ( ! F_149 ( & V_323 ) )
F_150 ( & V_323 , & V_322 ) ;
#endif
return 0 ;
}
static void T_14 F_152 ( void )
{
return F_153 ( & V_320 ) ;
}

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
static void F_36 ( struct V_64 * V_65 )
{
T_3 V_92 ;
bool V_48 ;
struct V_45 * V_67 = & V_65 -> V_67 ;
struct V_2 * V_3 = V_67 -> V_3 ;
void T_1 * V_68 , * V_40 , * V_93 ;
V_40 = F_20 ( V_3 ) ;
V_93 = F_37 ( V_3 ) ;
V_48 = V_67 -> V_49 != V_50 ;
V_68 = F_27 ( V_3 ) + F_28 ( V_3 , V_67 -> V_51 ) ;
V_92 = V_67 -> V_49 ;
if ( V_3 -> V_94 == 1 )
V_92 |= V_67 -> V_95 << V_96 ;
if ( V_48 )
V_92 |= ( V_97 << V_98 ) ;
else
V_92 |= F_30 ( V_67 ) << V_99 ;
F_21 ( V_92 , V_93 + F_38 ( V_67 -> V_51 ) ) ;
if ( V_3 -> V_94 > 1 ) {
#ifdef F_32
V_92 = V_100 ;
#else
V_92 = V_101 ;
#endif
F_21 ( V_92 ,
V_93 + F_39 ( V_67 -> V_51 ) ) ;
switch ( V_3 -> V_102 ) {
case 32 :
V_92 = ( V_103 << V_104 ) ;
break;
case 36 :
V_92 = ( V_105 << V_104 ) ;
break;
case 39 :
V_92 = ( V_106 << V_104 ) ;
break;
case 42 :
V_92 = ( V_107 << V_104 ) ;
break;
case 44 :
V_92 = ( V_108 << V_104 ) ;
break;
case 48 :
V_92 = ( V_109 << V_104 ) ;
break;
}
switch ( V_3 -> V_110 ) {
case 32 :
V_92 |= ( V_103 << V_111 ) ;
break;
case 36 :
V_92 |= ( V_105 << V_111 ) ;
break;
case 39 :
V_92 |= ( V_106 << V_111 ) ;
break;
case 42 :
V_92 |= ( V_107 << V_111 ) ;
break;
case 44 :
V_92 |= ( V_108 << V_111 ) ;
break;
case 48 :
V_92 |= ( V_109 << V_111 ) ;
break;
}
if ( V_48 )
F_21 ( V_92 , V_68 + V_112 ) ;
}
V_92 = F_40 ( V_67 -> V_113 ) ;
F_21 ( V_92 , V_68 + V_114 ) ;
V_92 = ( V_115 ) F_40 ( V_67 -> V_113 ) >> 32 ;
if ( V_48 )
V_92 |= F_29 ( V_67 ) << V_116 ;
F_21 ( V_92 , V_68 + V_117 ) ;
if ( V_3 -> V_94 > 1 ) {
if ( V_118 == V_119 )
V_92 = V_120 ;
else
V_92 = V_121 ;
if ( ! V_48 ) {
switch ( V_3 -> V_122 ) {
case 32 :
V_92 |= ( V_103 << V_123 ) ;
break;
case 36 :
V_92 |= ( V_105 << V_123 ) ;
break;
case 40 :
V_92 |= ( V_106 << V_123 ) ;
break;
case 42 :
V_92 |= ( V_107 << V_123 ) ;
break;
case 44 :
V_92 |= ( V_108 << V_123 ) ;
break;
case 48 :
V_92 |= ( V_109 << V_123 ) ;
break;
}
} else {
V_92 |= ( 64 - V_3 -> V_110 ) << V_124 ;
}
} else {
V_92 = 0 ;
}
V_92 |= V_125 |
( V_126 << V_127 ) |
( V_128 << V_129 ) |
( V_128 << V_130 ) |
( V_131 << V_132 ) ;
F_21 ( V_92 , V_68 + V_133 ) ;
if ( V_48 ) {
V_92 = ( V_134 << F_41 ( V_135 ) ) |
( V_136 << F_41 ( V_137 ) ) |
( V_138 << F_41 ( V_139 ) ) ;
F_21 ( V_92 , V_68 + V_140 ) ;
}
V_92 = V_141 | V_142 | V_143 | V_144 | V_145 ;
if ( V_48 )
V_92 |= V_146 ;
#ifdef F_42
V_92 |= V_147 ;
#endif
F_21 ( V_92 , V_68 + V_148 ) ;
}
static int F_43 ( struct V_62 * V_63 ,
struct V_17 * V_18 )
{
int V_54 , V_56 , V_36 ;
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_45 * V_67 = & V_65 -> V_67 ;
struct V_2 * V_3 , * V_14 ;
V_14 = V_18 -> V_149 . V_150 ;
V_65 -> V_151 = - 1 ;
do {
V_3 = V_14 ;
V_65 -> V_151 &= ( 1ULL << V_3 -> V_122 ) - 1 ;
} while ( ( V_14 = F_9 ( V_3 ) ) );
if ( ! F_1 ( V_3 , V_18 -> V_10 ) ) {
F_7 ( V_18 , L_9 ) ;
return - V_152 ;
}
if ( V_3 -> V_153 & V_154 ) {
V_67 -> V_49 = V_155 ;
V_36 = V_3 -> V_156 ;
} else if ( V_3 -> V_153 & V_157 ) {
V_67 -> V_49 = V_50 ;
V_36 = 0 ;
} else {
V_67 -> V_49 = V_155 ;
V_36 = V_3 -> V_156 ;
}
V_56 = F_14 ( V_3 -> V_158 , V_36 ,
V_3 -> V_159 ) ;
if ( F_44 ( V_56 ) )
return V_56 ;
V_67 -> V_51 = V_56 ;
if ( V_3 -> V_94 == 1 ) {
V_67 -> V_95 = F_45 ( & V_3 -> V_95 ) ;
V_67 -> V_95 %= V_3 -> V_160 ;
} else {
V_67 -> V_95 = V_67 -> V_51 ;
}
V_54 = V_3 -> V_161 [ V_3 -> V_162 + V_67 -> V_95 ] ;
V_56 = F_46 ( V_54 , F_31 , V_163 ,
L_10 , V_63 ) ;
if ( F_44 ( V_56 ) ) {
F_7 ( V_3 -> V_18 , L_11 ,
V_67 -> V_95 , V_54 ) ;
V_67 -> V_95 = V_164 ;
goto V_165;
}
V_67 -> V_3 = V_3 ;
F_36 ( V_65 ) ;
return V_56 ;
V_165:
F_17 ( V_3 -> V_158 , V_67 -> V_51 ) ;
return V_56 ;
}
static void F_47 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_45 * V_67 = & V_65 -> V_67 ;
struct V_2 * V_3 = V_67 -> V_3 ;
void T_1 * V_68 ;
int V_54 ;
if ( ! V_3 )
return;
V_68 = F_27 ( V_3 ) + F_28 ( V_3 , V_67 -> V_51 ) ;
F_21 ( 0 , V_68 + V_148 ) ;
F_26 ( V_67 ) ;
if ( V_67 -> V_95 != V_164 ) {
V_54 = V_3 -> V_161 [ V_3 -> V_162 + V_67 -> V_95 ] ;
F_48 ( V_54 , V_63 ) ;
}
F_17 ( V_3 -> V_158 , V_67 -> V_51 ) ;
}
static int F_49 ( struct V_62 * V_63 )
{
struct V_64 * V_65 ;
T_4 * V_113 ;
V_65 = F_50 ( sizeof( * V_65 ) , V_28 ) ;
if ( ! V_65 )
return - V_29 ;
V_113 = F_50 ( V_166 * sizeof( T_4 ) , V_28 ) ;
if ( ! V_113 )
goto V_167;
V_65 -> V_67 . V_113 = V_113 ;
F_51 ( & V_65 -> V_168 ) ;
V_63 -> V_66 = V_65 ;
return 0 ;
V_167:
F_52 ( V_65 ) ;
return - V_29 ;
}
static void F_53 ( T_5 * V_169 )
{
T_6 V_170 = F_54 ( * V_169 ) ;
F_55 ( V_170 ) ;
F_56 ( V_170 ) ;
}
static void F_57 ( T_7 * V_171 )
{
int V_21 ;
T_5 * V_169 , * V_172 = F_58 ( V_171 , 0 ) ;
V_169 = V_172 ;
for ( V_21 = 0 ; V_21 < V_173 ; ++ V_21 ) {
if ( F_59 ( * V_169 ) )
continue;
F_53 ( V_169 ) ;
V_169 ++ ;
}
F_60 ( NULL , V_172 ) ;
}
static void F_61 ( T_4 * V_113 )
{
int V_21 ;
T_7 * V_171 , * V_174 = F_62 ( V_113 , 0 ) ;
V_171 = V_174 ;
for ( V_21 = 0 ; V_21 < V_175 ; ++ V_21 ) {
if ( F_63 ( * V_171 ) )
continue;
F_57 ( V_171 ) ;
V_171 ++ ;
}
F_64 ( NULL , V_174 ) ;
}
static void F_65 ( struct V_64 * V_65 )
{
int V_21 ;
struct V_45 * V_67 = & V_65 -> V_67 ;
T_4 * V_113 , * V_176 = V_67 -> V_113 ;
V_113 = V_176 ;
for ( V_21 = 0 ; V_21 < V_166 ; ++ V_21 ) {
if ( F_66 ( * V_113 ) )
continue;
F_61 ( V_113 ) ;
V_113 ++ ;
}
F_52 ( V_176 ) ;
}
static void F_67 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
F_47 ( V_63 ) ;
F_65 ( V_65 ) ;
F_52 ( V_65 ) ;
}
static int F_68 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
int V_21 ;
struct V_177 * V_178 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
if ( ! ( V_3 -> V_153 & V_179 ) )
return 0 ;
if ( V_9 -> V_178 )
return - V_16 ;
V_178 = F_69 ( sizeof( * V_178 ) * V_9 -> V_30 , V_28 ) ;
if ( ! V_178 ) {
F_7 ( V_3 -> V_18 , L_12 ,
V_9 -> V_30 , V_9 -> V_10 -> V_23 ) ;
return - V_29 ;
}
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 ) {
int V_38 = F_14 ( V_3 -> V_180 , 0 ,
V_3 -> V_181 ) ;
if ( F_44 ( V_38 ) ) {
F_7 ( V_3 -> V_18 , L_13 ) ;
goto V_182;
}
V_178 [ V_21 ] = (struct V_177 ) {
. V_38 = V_38 ,
. V_183 = 0 ,
. V_184 = V_9 -> V_31 [ V_21 ] ,
} ;
}
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 ) {
T_3 V_92 = V_185 | V_178 [ V_21 ] . V_184 << V_186 |
V_178 [ V_21 ] . V_183 << V_187 ;
F_21 ( V_92 , V_40 + F_70 ( V_178 [ V_21 ] . V_38 ) ) ;
}
V_9 -> V_178 = V_178 ;
return 0 ;
V_182:
while ( -- V_21 >= 0 )
F_17 ( V_3 -> V_180 , V_178 [ V_21 ] . V_38 ) ;
F_52 ( V_178 ) ;
return - V_27 ;
}
static void F_71 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
int V_21 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
struct V_177 * V_178 = V_9 -> V_178 ;
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 ) {
T_8 V_38 = V_178 [ V_21 ] . V_38 ;
F_21 ( ~ V_185 , V_40 + F_70 ( V_38 ) ) ;
F_17 ( V_3 -> V_180 , V_38 ) ;
}
V_9 -> V_178 = NULL ;
F_52 ( V_178 ) ;
}
static void F_72 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
int V_21 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 ) {
T_9 V_188 = V_9 -> V_31 [ V_21 ] ;
F_21 ( V_189 ,
V_40 + F_73 ( V_188 ) ) ;
}
}
static int F_74 ( struct V_64 * V_65 ,
struct V_1 * V_9 )
{
int V_21 , V_56 ;
struct V_2 * V_14 , * V_3 = V_65 -> V_67 . V_3 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
V_56 = F_68 ( V_3 , V_9 ) ;
if ( V_56 )
return V_56 ;
V_3 = V_65 -> V_190 ;
while ( ( V_14 = F_9 ( V_3 ) ) ) {
if ( V_3 -> V_153 & V_179 )
continue;
F_72 ( V_3 , V_9 ) ;
V_3 = V_14 ;
}
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 ) {
T_3 V_38 , V_191 ;
V_38 = V_9 -> V_178 ? V_9 -> V_178 [ V_21 ] . V_38 : V_9 -> V_31 [ V_21 ] ;
V_191 = ( V_192 << V_193 ) |
( V_65 -> V_67 . V_51 << V_194 ) ;
F_21 ( V_191 , V_40 + F_73 ( V_38 ) ) ;
}
return 0 ;
}
static void F_75 ( struct V_64 * V_65 ,
struct V_1 * V_9 )
{
struct V_2 * V_3 = V_65 -> V_67 . V_3 ;
F_72 ( V_3 , V_9 ) ;
F_71 ( V_3 , V_9 ) ;
}
static int F_76 ( struct V_62 * V_63 , struct V_17 * V_18 )
{
int V_56 = - V_195 ;
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_2 * V_196 = V_18 -> V_149 . V_150 ;
struct V_1 * V_9 ;
if ( ! V_196 ) {
F_7 ( V_18 , L_14 ) ;
return - V_197 ;
}
F_77 ( & V_65 -> V_168 ) ;
if ( ! V_65 -> V_190 ) {
V_56 = F_43 ( V_63 , V_18 ) ;
if ( F_44 ( V_56 ) )
goto V_198;
V_65 -> V_190 = V_196 ;
} else if ( V_65 -> V_190 != V_196 ) {
F_7 ( V_18 ,
L_15 ,
F_78 ( V_65 -> V_190 -> V_18 ) ,
F_78 ( V_196 -> V_18 ) ) ;
goto V_198;
}
F_79 ( & V_65 -> V_168 ) ;
V_9 = F_1 ( V_65 -> V_190 , V_18 -> V_10 ) ;
if ( ! V_9 )
return - V_152 ;
return F_74 ( V_65 , V_9 ) ;
V_198:
F_79 ( & V_65 -> V_168 ) ;
return V_56 ;
}
static void F_80 ( struct V_62 * V_63 , struct V_17 * V_18 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_1 * V_9 ;
V_9 = F_1 ( V_65 -> V_190 , V_18 -> V_10 ) ;
if ( V_9 )
F_75 ( V_65 , V_9 ) ;
}
static void F_81 ( struct V_2 * V_3 , void * V_199 ,
T_10 V_200 )
{
unsigned long V_201 = ( unsigned long ) V_199 & ~ V_202 ;
if ( ! ( V_3 -> V_153 & V_203 ) )
F_82 ( V_3 -> V_18 , F_83 ( V_199 ) , V_201 , V_200 ,
V_204 ) ;
}
static bool F_84 ( unsigned long V_199 ,
unsigned long V_37 )
{
return ! ( V_199 & ~ V_205 ) &&
( V_199 + V_206 <= V_37 ) ;
}
static int F_85 ( struct V_2 * V_3 , T_5 * V_169 ,
unsigned long V_199 , unsigned long V_37 ,
unsigned long V_207 , int V_55 , int V_208 )
{
T_11 * V_209 , * V_36 ;
T_12 V_210 = V_211 | V_212 ;
if ( F_59 ( * V_169 ) ) {
T_6 V_170 = F_86 ( V_213 ) ;
if ( ! V_170 )
return - V_29 ;
F_81 ( V_3 , F_87 ( V_170 ) ,
V_214 ) ;
if ( ! F_88 ( V_170 ) ) {
F_56 ( V_170 ) ;
return - V_29 ;
}
F_89 ( NULL , V_169 , V_170 ) ;
F_81 ( V_3 , V_169 , sizeof( * V_169 ) ) ;
}
if ( V_208 == 1 ) {
V_210 |= V_215 | V_216 ;
if ( ! ( V_55 & V_217 ) && ( V_55 & V_218 ) )
V_210 |= V_219 ;
if ( V_55 & V_220 )
V_210 |= ( V_137 <<
V_221 ) ;
} else {
V_210 |= V_222 ;
if ( V_55 & V_218 )
V_210 |= V_223 ;
if ( V_55 & V_217 )
V_210 |= V_224 ;
if ( V_55 & V_220 )
V_210 |= V_225 ;
else
V_210 |= V_226 ;
}
if ( ! ( V_55 & ( V_218 | V_217 ) ) )
V_210 &= ~ V_211 ;
V_210 |= V_227 ;
V_36 = F_90 ( * V_169 ) + F_91 ( V_199 ) ;
V_209 = V_36 ;
do {
int V_21 = 1 ;
V_210 &= ~ V_228 ;
if ( F_84 ( V_199 , V_37 ) ) {
V_21 = V_229 ;
V_210 |= V_228 ;
} else if ( F_92 ( * V_209 ) &
( V_228 | V_211 ) ) {
int V_230 ;
T_11 * V_231 ;
unsigned long V_38 = F_91 ( V_199 ) ;
V_38 &= ~ ( V_229 - 1 ) ;
V_231 = F_90 ( * V_169 ) + V_38 ;
for ( V_230 = 0 ; V_230 < V_229 ; ++ V_230 )
F_92 ( * ( V_231 + V_230 ) ) &= ~ V_228 ;
F_81 ( V_3 , V_231 ,
sizeof( * V_209 ) *
V_229 ) ;
}
do {
* V_209 = F_93 ( V_207 , F_94 ( V_210 ) ) ;
} while ( V_209 ++ , V_207 ++ , V_199 += V_118 , -- V_21 );
} while ( V_199 != V_37 );
F_81 ( V_3 , V_36 , sizeof( * V_209 ) * ( V_209 - V_36 ) ) ;
return 0 ;
}
static int F_95 ( struct V_2 * V_3 , T_7 * V_171 ,
unsigned long V_199 , unsigned long V_37 ,
V_115 V_232 , int V_55 , int V_208 )
{
int V_56 ;
T_5 * V_169 ;
unsigned long V_233 , V_207 = F_96 ( V_232 ) ;
#ifndef F_97
if ( F_63 ( * V_171 ) ) {
V_169 = F_98 ( NULL , V_199 ) ;
if ( ! V_169 )
return - V_29 ;
} else
#endif
V_169 = F_58 ( V_171 , V_199 ) ;
do {
V_233 = F_99 ( V_199 , V_37 ) ;
V_56 = F_85 ( V_3 , V_169 , V_199 , V_37 , V_207 ,
V_55 , V_208 ) ;
F_100 ( NULL , V_171 , V_169 ) ;
F_81 ( V_3 , V_171 , sizeof( * V_171 ) ) ;
V_232 += V_233 - V_199 ;
} while ( V_169 ++ , V_199 = V_233 , V_199 < V_37 );
return V_56 ;
}
static int F_101 ( struct V_2 * V_3 , T_4 * V_113 ,
unsigned long V_199 , unsigned long V_37 ,
V_115 V_232 , int V_55 , int V_208 )
{
int V_56 = 0 ;
T_7 * V_171 ;
unsigned long V_233 ;
#ifndef F_102
if ( F_66 ( * V_113 ) ) {
V_171 = F_103 ( NULL , V_199 ) ;
if ( ! V_171 )
return - V_29 ;
} else
#endif
V_171 = F_62 ( V_113 , V_199 ) ;
do {
V_233 = F_104 ( V_199 , V_37 ) ;
V_56 = F_95 ( V_3 , V_171 , V_199 , V_233 , V_232 ,
V_55 , V_208 ) ;
F_105 ( NULL , V_171 , V_113 ) ;
F_81 ( V_3 , V_113 , sizeof( * V_113 ) ) ;
V_232 += V_233 - V_199 ;
} while ( V_171 ++ , V_199 = V_233 , V_199 < V_37 );
return V_56 ;
}
static int F_106 ( struct V_64 * V_65 ,
unsigned long V_61 , V_115 V_234 ,
T_10 V_200 , int V_55 )
{
int V_56 , V_208 ;
unsigned long V_37 ;
V_115 V_235 , V_151 ;
struct V_45 * V_67 = & V_65 -> V_67 ;
T_4 * V_113 = V_67 -> V_113 ;
struct V_2 * V_3 = V_67 -> V_3 ;
if ( V_67 -> V_49 == V_50 ) {
V_208 = 2 ;
V_151 = ( 1ULL << V_3 -> V_122 ) - 1 ;
} else {
V_208 = 1 ;
V_151 = ( 1ULL << V_3 -> V_110 ) - 1 ;
}
if ( ! V_113 )
return - V_195 ;
if ( V_200 & ~ V_202 )
return - V_195 ;
V_235 = ( 1ULL << V_3 -> V_102 ) - 1 ;
if ( ( V_115 ) V_61 & ~ V_235 )
return - V_236 ;
if ( V_234 & ~ V_151 )
return - V_236 ;
F_77 ( & V_65 -> V_168 ) ;
V_113 += F_107 ( V_61 ) ;
V_37 = V_61 + V_200 ;
do {
unsigned long V_233 = F_108 ( V_61 , V_37 ) ;
V_56 = F_101 ( V_3 , V_113 , V_61 , V_233 , V_234 ,
V_55 , V_208 ) ;
if ( V_56 )
goto V_34;
V_234 += V_233 - V_61 ;
V_61 = V_233 ;
} while ( V_113 ++ , V_61 != V_37 );
V_34:
F_79 ( & V_65 -> V_168 ) ;
if ( V_3 -> V_153 & V_203 )
F_109 () ;
return V_56 ;
}
static int F_110 ( struct V_62 * V_63 , unsigned long V_61 ,
V_115 V_234 , T_10 V_200 , int V_55 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
if ( ! V_65 )
return - V_152 ;
if ( ( V_115 ) V_61 & ~ V_65 -> V_151 )
return - V_236 ;
return F_106 ( V_65 , V_61 , V_234 , V_200 , V_55 ) ;
}
static T_10 F_111 ( struct V_62 * V_63 , unsigned long V_61 ,
T_10 V_200 )
{
int V_56 ;
struct V_64 * V_65 = V_63 -> V_66 ;
V_56 = F_106 ( V_65 , V_61 , 0 , V_200 , 0 ) ;
F_26 ( & V_65 -> V_67 ) ;
return V_56 ? V_56 : V_200 ;
}
static V_115 F_112 ( struct V_62 * V_63 ,
T_13 V_61 )
{
T_4 * V_237 , V_113 ;
T_7 V_171 ;
T_5 V_169 ;
T_11 V_209 ;
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_45 * V_67 = & V_65 -> V_67 ;
V_237 = V_67 -> V_113 ;
if ( ! V_237 )
return 0 ;
V_113 = * ( V_237 + F_107 ( V_61 ) ) ;
if ( F_66 ( V_113 ) )
return 0 ;
V_171 = * F_62 ( & V_113 , V_61 ) ;
if ( F_63 ( V_171 ) )
return 0 ;
V_169 = * F_58 ( & V_171 , V_61 ) ;
if ( F_59 ( V_169 ) )
return 0 ;
V_209 = * ( F_90 ( V_169 ) + F_91 ( V_61 ) ) ;
if ( F_113 ( V_209 ) )
return 0 ;
return F_114 ( F_115 ( V_209 ) ) | ( V_61 & ~ V_202 ) ;
}
static int F_116 ( struct V_62 * V_63 ,
unsigned long V_238 )
{
unsigned long V_239 = 0 ;
struct V_64 * V_65 = V_63 -> V_66 ;
if ( V_65 -> V_67 . V_3 -> V_153 & V_203 )
V_239 |= V_240 ;
return ! ! ( V_238 & V_239 ) ;
}
static int F_117 ( struct V_17 * V_18 )
{
struct V_2 * V_241 , * V_14 , * V_3 ;
struct V_1 * V_9 = NULL ;
F_10 ( & V_33 ) ;
F_11 (parent, &arm_smmu_devices, list) {
V_3 = V_14 ;
F_11 (child, &arm_smmu_devices, list) {
if ( V_241 -> V_32 == V_14 -> V_18 -> V_10 ) {
V_9 = F_1 ( V_241 , V_18 -> V_10 ) ;
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
return - V_152 ;
V_18 -> V_149 . V_150 = V_3 ;
return 0 ;
}
static void F_118 ( struct V_17 * V_18 )
{
V_18 -> V_149 . V_150 = NULL ;
}
static void F_119 ( struct V_2 * V_3 )
{
void T_1 * V_40 = F_20 ( V_3 ) ;
void T_1 * V_68 ;
int V_21 = 0 ;
T_3 V_92 ;
V_92 = F_22 ( V_40 + V_88 ) ;
F_34 ( V_92 , V_40 + V_88 ) ;
for ( V_21 = 0 ; V_21 < V_3 -> V_181 ; ++ V_21 ) {
F_21 ( ~ V_185 , V_40 + F_70 ( V_21 ) ) ;
F_21 ( V_189 , V_40 + F_73 ( V_21 ) ) ;
}
for ( V_21 = 0 ; V_21 < V_3 -> V_159 ; ++ V_21 ) {
V_68 = F_27 ( V_3 ) + F_28 ( V_3 , V_21 ) ;
F_21 ( 0 , V_68 + V_148 ) ;
F_21 ( V_70 , V_68 + V_69 ) ;
}
F_21 ( 0 , V_40 + V_242 ) ;
F_21 ( 0 , V_40 + V_243 ) ;
F_21 ( 0 , V_40 + V_244 ) ;
V_92 = F_22 ( V_40 + V_245 ) ;
V_92 |= ( V_246 | V_247 | V_248 | V_249 ) ;
V_92 |= ( V_250 | V_251 ) ;
V_92 &= ~ ( V_252 | V_253 ) ;
V_92 &= ~ V_254 ;
V_92 &= ~ ( V_255 << V_256 ) ;
F_19 ( V_3 ) ;
F_21 ( V_92 , V_40 + V_245 ) ;
}
static int F_120 ( int V_200 )
{
switch ( V_200 ) {
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
static int F_121 ( struct V_2 * V_3 )
{
unsigned long V_200 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
T_3 V_184 ;
F_122 ( V_3 -> V_18 , L_16 ) ;
V_184 = F_22 ( V_40 + V_257 ) ;
V_3 -> V_94 = ( ( V_184 >> V_258 ) & V_259 ) + 1 ;
F_122 ( V_3 -> V_18 , L_17 , V_3 -> V_94 ) ;
V_184 = F_22 ( V_40 + V_260 ) ;
#ifndef F_32
if ( ( ( V_184 >> V_261 ) & V_262 ) == V_263 ) {
F_7 ( V_3 -> V_18 , L_18 ) ;
return - V_152 ;
}
#endif
if ( V_184 & V_264 ) {
V_3 -> V_153 |= V_265 ;
F_122 ( V_3 -> V_18 , L_19 ) ;
}
if ( V_184 & V_266 ) {
V_3 -> V_153 |= V_157 ;
F_122 ( V_3 -> V_18 , L_20 ) ;
}
if ( V_184 & V_267 ) {
V_3 -> V_153 |= V_154 ;
F_122 ( V_3 -> V_18 , L_21 ) ;
}
if ( ! ( V_3 -> V_153 &
( V_265 | V_157 |
V_154 ) ) ) {
F_7 ( V_3 -> V_18 , L_22 ) ;
return - V_152 ;
}
if ( V_184 & V_268 ) {
V_3 -> V_153 |= V_203 ;
F_122 ( V_3 -> V_18 , L_23 ) ;
}
if ( V_184 & V_269 ) {
T_3 V_270 , V_188 , V_183 ;
V_3 -> V_153 |= V_179 ;
V_3 -> V_181 = ( V_184 >> V_271 ) &
V_272 ;
if ( V_3 -> V_181 == 0 ) {
F_7 ( V_3 -> V_18 ,
L_24 ) ;
return - V_152 ;
}
V_270 = V_273 << V_187 ;
V_270 |= ( V_274 << V_186 ) ;
F_21 ( V_270 , V_40 + F_70 ( 0 ) ) ;
V_270 = F_22 ( V_40 + F_70 ( 0 ) ) ;
V_183 = ( V_270 >> V_187 ) & V_273 ;
V_188 = ( V_270 >> V_186 ) & V_274 ;
if ( ( V_183 & V_188 ) != V_188 ) {
F_7 ( V_3 -> V_18 ,
L_25 ,
V_183 , V_188 ) ;
return - V_152 ;
}
F_122 ( V_3 -> V_18 ,
L_26 ,
V_3 -> V_181 , V_183 ) ;
}
V_184 = F_22 ( V_40 + V_275 ) ;
V_3 -> V_276 = ( V_184 & V_277 ) ? V_278 : V_119 ;
V_200 = 1 << ( ( ( V_184 >> V_279 ) & V_280 ) + 1 ) ;
V_200 *= ( V_3 -> V_276 << 1 ) ;
if ( V_3 -> V_200 != V_200 )
F_12 ( V_3 -> V_18 , L_27
L_28 , V_200 , V_3 -> V_200 ) ;
V_3 -> V_156 = ( V_184 >> V_281 ) &
V_282 ;
V_3 -> V_159 = ( V_184 >> V_283 ) & V_284 ;
if ( V_3 -> V_156 > V_3 -> V_159 ) {
F_7 ( V_3 -> V_18 , L_29 ) ;
return - V_152 ;
}
F_122 ( V_3 -> V_18 , L_30 ,
V_3 -> V_159 , V_3 -> V_156 ) ;
V_184 = F_22 ( V_40 + V_285 ) ;
V_200 = F_120 ( ( V_184 >> V_286 ) & V_287 ) ;
#ifdef F_32
V_3 -> V_110 = F_123 ( 39UL , V_200 ) ;
#else
V_3 -> V_110 = F_123 ( 32UL , V_200 ) ;
#endif
V_200 = F_120 ( ( V_184 >> V_288 ) & V_289 ) ;
V_3 -> V_122 = F_123 ( ( unsigned long ) V_290 , V_200 ) ;
if ( V_3 -> V_94 == 1 ) {
V_3 -> V_102 = 32 ;
} else {
#ifdef F_32
V_200 = ( V_184 >> V_291 ) & V_292 ;
V_200 = F_123 ( 39 , F_120 ( V_200 ) ) ;
#else
V_200 = 32 ;
#endif
V_3 -> V_102 = V_200 ;
if ( ( V_118 == V_119 && ! ( V_184 & V_293 ) ) ||
( V_118 == V_278 && ! ( V_184 & V_294 ) ) ||
( V_118 != V_119 && V_118 != V_278 ) ) {
F_7 ( V_3 -> V_18 , L_31 ,
V_118 ) ;
return - V_152 ;
}
}
F_122 ( V_3 -> V_18 ,
L_32 ,
V_3 -> V_102 , V_3 -> V_110 , V_3 -> V_122 ) ;
return 0 ;
}
static int F_124 ( struct V_295 * V_296 )
{
struct V_297 * V_298 ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_17 * V_18 = & V_296 -> V_18 ;
struct V_6 * V_7 ;
struct V_19 V_20 ;
int V_299 , V_21 , V_300 ;
V_3 = F_8 ( V_18 , sizeof( * V_3 ) , V_28 ) ;
if ( ! V_3 ) {
F_7 ( V_18 , L_33 ) ;
return - V_29 ;
}
V_3 -> V_18 = V_18 ;
V_298 = F_125 ( V_296 , V_301 , 0 ) ;
V_3 -> V_47 = F_126 ( V_18 , V_298 ) ;
if ( F_127 ( V_3 -> V_47 ) )
return F_128 ( V_3 -> V_47 ) ;
V_3 -> V_200 = F_129 ( V_298 ) ;
if ( F_130 ( V_18 -> V_10 , L_34 ,
& V_3 -> V_162 ) ) {
F_7 ( V_18 , L_35 ) ;
return - V_152 ;
}
V_299 = 0 ;
while ( ( V_298 = F_125 ( V_296 , V_302 , V_299 ) ) ) {
V_299 ++ ;
if ( V_299 > V_3 -> V_162 )
V_3 -> V_160 ++ ;
}
if ( ! V_3 -> V_160 ) {
F_7 ( V_18 , L_36 ,
V_299 , V_3 -> V_162 + 1 ) ;
return - V_152 ;
}
V_3 -> V_161 = F_8 ( V_18 , sizeof( * V_3 -> V_161 ) * V_299 ,
V_28 ) ;
if ( ! V_3 -> V_161 ) {
F_7 ( V_18 , L_37 , V_299 ) ;
return - V_29 ;
}
for ( V_21 = 0 ; V_21 < V_299 ; ++ V_21 ) {
int V_54 = F_131 ( V_296 , V_21 ) ;
if ( V_54 < 0 ) {
F_7 ( V_18 , L_38 , V_21 ) ;
return - V_152 ;
}
V_3 -> V_161 [ V_21 ] = V_54 ;
}
V_21 = 0 ;
V_3 -> V_8 = V_303 ;
while ( ! F_132 ( V_18 -> V_10 , L_39 ,
L_40 , V_21 ,
& V_20 ) ) {
V_300 = F_6 ( V_3 , V_18 , & V_20 ) ;
if ( V_300 ) {
F_7 ( V_18 , L_41 ,
V_20 . V_22 -> V_23 ) ;
goto V_304;
}
V_21 ++ ;
}
F_122 ( V_18 , L_42 , V_21 ) ;
if ( ( V_5 = F_133 ( V_18 -> V_10 , L_43 , 0 ) ) )
V_3 -> V_32 = V_5 ;
V_300 = F_121 ( V_3 ) ;
if ( V_300 )
goto V_305;
if ( V_3 -> V_94 > 1 &&
V_3 -> V_159 != V_3 -> V_160 ) {
F_7 ( V_18 ,
L_44 ,
V_3 -> V_160 , V_3 -> V_159 ) ;
V_300 = - V_152 ;
goto V_305;
}
for ( V_21 = 0 ; V_21 < V_3 -> V_162 ; ++ V_21 ) {
V_300 = F_46 ( V_3 -> V_161 [ V_21 ] ,
F_35 ,
V_163 ,
L_45 ,
V_3 ) ;
if ( V_300 ) {
F_7 ( V_18 , L_46 ,
V_21 , V_3 -> V_161 [ V_21 ] ) ;
goto V_306;
}
}
F_134 ( & V_3 -> V_307 ) ;
F_10 ( & V_33 ) ;
F_135 ( & V_3 -> V_307 , & V_308 ) ;
F_13 ( & V_33 ) ;
F_119 ( V_3 ) ;
return 0 ;
V_306:
while ( V_21 -- )
F_48 ( V_3 -> V_161 [ V_21 ] , V_3 ) ;
V_305:
if ( V_3 -> V_32 )
F_136 ( V_3 -> V_32 ) ;
V_304:
for ( V_7 = F_137 ( & V_3 -> V_8 ) ; V_7 ; V_7 = F_138 ( V_7 ) ) {
struct V_1 * V_9 ;
V_9 = F_2 ( V_7 , struct V_1 , V_7 ) ;
F_136 ( V_9 -> V_10 ) ;
}
return V_300 ;
}
static int F_139 ( struct V_295 * V_296 )
{
int V_21 ;
struct V_17 * V_18 = & V_296 -> V_18 ;
struct V_2 * V_309 , * V_3 = NULL ;
struct V_6 * V_7 ;
F_10 ( & V_33 ) ;
F_11 (curr, &arm_smmu_devices, list) {
if ( V_309 -> V_18 == V_18 ) {
V_3 = V_309 ;
F_140 ( & V_3 -> V_307 ) ;
break;
}
}
F_13 ( & V_33 ) ;
if ( ! V_3 )
return - V_152 ;
if ( V_3 -> V_32 )
F_136 ( V_3 -> V_32 ) ;
for ( V_7 = F_137 ( & V_3 -> V_8 ) ; V_7 ; V_7 = F_138 ( V_7 ) ) {
struct V_1 * V_9 ;
V_9 = F_2 ( V_7 , struct V_1 , V_7 ) ;
F_136 ( V_9 -> V_10 ) ;
}
if ( ! F_141 ( V_3 -> V_158 , V_310 ) )
F_7 ( V_18 , L_47 ) ;
for ( V_21 = 0 ; V_21 < V_3 -> V_162 ; ++ V_21 )
F_48 ( V_3 -> V_161 [ V_21 ] , V_3 ) ;
F_21 ( V_252 , F_20 ( V_3 ) + V_245 ) ;
return 0 ;
}
static int T_14 F_142 ( void )
{
int V_56 ;
V_56 = F_143 ( & V_311 ) ;
if ( V_56 )
return V_56 ;
if ( ! F_144 ( & V_312 ) )
F_145 ( & V_312 , & V_313 ) ;
if ( ! F_144 ( & V_314 ) )
F_145 ( & V_314 , & V_313 ) ;
return 0 ;
}
static void T_15 F_146 ( void )
{
return F_147 ( & V_311 ) ;
}

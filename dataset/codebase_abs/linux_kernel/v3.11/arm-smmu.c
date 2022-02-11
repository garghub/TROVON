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
static T_2 F_26 ( int V_45 , void * V_18 )
{
int V_46 , V_47 ;
T_3 V_48 , V_49 , V_50 , V_51 ;
unsigned long V_52 ;
struct V_53 * V_54 = V_18 ;
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_58 * V_59 = & V_56 -> V_59 ;
struct V_2 * V_3 = V_59 -> V_3 ;
void T_1 * V_60 ;
V_60 = F_27 ( V_3 ) + F_28 ( V_3 , V_59 -> V_61 ) ;
V_48 = F_22 ( V_60 + V_62 ) ;
if ( ! ( V_48 & V_63 ) )
return V_64 ;
if ( V_48 & V_65 )
F_24 ( V_3 -> V_18 ,
L_5 ,
V_48 ) ;
V_50 = F_22 ( V_60 + V_66 ) ;
V_46 = V_50 & V_67 ? V_68 : V_69 ;
V_49 = F_22 ( V_60 + V_70 ) ;
V_52 = V_49 ;
#ifdef F_29
V_49 = F_22 ( V_60 + V_71 ) ;
V_52 |= ( ( unsigned long ) V_49 << 32 ) ;
#endif
if ( ! F_30 ( V_54 , V_3 -> V_18 , V_52 , V_46 ) ) {
V_47 = V_72 ;
V_51 = V_73 ;
} else {
V_47 = V_64 ;
V_51 = V_74 ;
}
F_31 ( V_48 , V_60 + V_62 ) ;
if ( V_48 & V_75 )
F_21 ( V_51 , V_60 + V_76 ) ;
return V_47 ;
}
static T_2 F_32 ( int V_45 , void * V_18 )
{
T_3 V_77 , V_78 , V_79 , V_80 ;
struct V_2 * V_3 = V_18 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
V_77 = F_22 ( V_40 + V_81 ) ;
V_78 = F_22 ( V_40 + V_82 ) ;
V_79 = F_22 ( V_40 + V_83 ) ;
V_80 = F_22 ( V_40 + V_84 ) ;
F_24 ( V_3 -> V_18 ,
L_6 ) ;
F_24 ( V_3 -> V_18 ,
L_7 ,
V_77 , V_78 , V_79 , V_80 ) ;
F_31 ( V_77 , V_40 + V_81 ) ;
return V_64 ;
}
static void F_33 ( struct V_55 * V_56 )
{
T_3 V_85 ;
bool V_86 ;
struct V_58 * V_59 = & V_56 -> V_59 ;
struct V_2 * V_3 = V_59 -> V_3 ;
void T_1 * V_60 , * V_40 , * V_87 ;
V_40 = F_20 ( V_3 ) ;
V_87 = F_34 ( V_3 ) ;
V_86 = V_59 -> V_88 != V_89 ;
V_60 = F_27 ( V_3 ) + F_28 ( V_3 , V_59 -> V_61 ) ;
V_85 = V_59 -> V_88 |
( V_59 -> V_90 << V_91 ) ;
if ( V_3 -> V_92 == 1 )
V_85 |= V_59 -> V_93 << V_94 ;
if ( V_86 )
V_85 |= ( V_95 << V_96 ) ;
F_21 ( V_85 , V_87 + F_35 ( V_59 -> V_61 ) ) ;
if ( V_3 -> V_92 > 1 ) {
#ifdef F_29
V_85 = V_97 ;
#else
V_85 = V_98 ;
#endif
F_21 ( V_85 ,
V_87 + F_36 ( V_59 -> V_61 ) ) ;
switch ( V_3 -> V_99 ) {
case 32 :
V_85 = ( V_100 << V_101 ) ;
break;
case 36 :
V_85 = ( V_102 << V_101 ) ;
break;
case 39 :
V_85 = ( V_103 << V_101 ) ;
break;
case 42 :
V_85 = ( V_104 << V_101 ) ;
break;
case 44 :
V_85 = ( V_105 << V_101 ) ;
break;
case 48 :
V_85 = ( V_106 << V_101 ) ;
break;
}
switch ( V_3 -> V_107 ) {
case 32 :
V_85 |= ( V_100 << V_108 ) ;
break;
case 36 :
V_85 |= ( V_102 << V_108 ) ;
break;
case 39 :
V_85 |= ( V_103 << V_108 ) ;
break;
case 42 :
V_85 |= ( V_104 << V_108 ) ;
break;
case 44 :
V_85 |= ( V_105 << V_108 ) ;
break;
case 48 :
V_85 |= ( V_106 << V_108 ) ;
break;
}
if ( V_86 )
F_21 ( V_85 , V_60 + V_109 ) ;
}
V_85 = F_37 ( V_59 -> V_110 ) ;
#ifndef F_38
F_21 ( V_85 , V_60 + V_111 ) ;
V_85 = ( V_112 ) F_37 ( V_59 -> V_110 ) >> 32 ;
F_21 ( V_85 , V_60 + V_113 ) ;
#else
F_21 ( V_85 , V_60 + V_113 ) ;
V_85 = ( V_112 ) F_37 ( V_59 -> V_110 ) >> 32 ;
F_21 ( V_85 , V_60 + V_111 ) ;
#endif
if ( V_3 -> V_92 > 1 ) {
if ( V_114 == V_115 )
V_85 = V_116 ;
else
V_85 = V_117 ;
if ( ! V_86 ) {
switch ( V_3 -> V_118 ) {
case 32 :
V_85 |= ( V_100 << V_119 ) ;
break;
case 36 :
V_85 |= ( V_102 << V_119 ) ;
break;
case 40 :
V_85 |= ( V_103 << V_119 ) ;
break;
case 42 :
V_85 |= ( V_104 << V_119 ) ;
break;
case 44 :
V_85 |= ( V_105 << V_119 ) ;
break;
case 48 :
V_85 |= ( V_106 << V_119 ) ;
break;
}
} else {
V_85 |= ( 64 - V_3 -> V_107 ) << V_120 ;
}
} else {
V_85 = 0 ;
}
V_85 |= V_121 |
( V_122 << V_123 ) |
( V_124 << V_125 ) |
( V_124 << V_126 ) |
( V_127 << V_128 ) ;
F_21 ( V_85 , V_60 + V_129 ) ;
if ( V_86 ) {
V_85 = ( V_130 << F_39 ( V_131 ) ) |
( V_132 << F_39 ( V_133 ) ) |
( V_134 << F_39 ( V_135 ) ) ;
F_21 ( V_85 , V_60 + V_136 ) ;
}
F_21 ( V_59 -> V_90 , V_40 + V_137 ) ;
F_19 ( V_3 ) ;
V_85 = V_138 | V_139 | V_140 | V_141 | V_142 ;
if ( V_86 )
V_85 |= V_143 ;
#ifdef F_38
V_85 |= V_144 ;
#endif
F_31 ( V_85 , V_60 + V_145 ) ;
}
static int F_40 ( struct V_53 * V_54 ,
struct V_17 * V_18 )
{
int V_45 , V_47 , V_36 ;
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_58 * V_59 = & V_56 -> V_59 ;
struct V_2 * V_3 , * V_14 ;
V_14 = V_18 -> V_146 . V_147 ;
V_56 -> V_148 = - 1 ;
do {
V_3 = V_14 ;
V_56 -> V_148 &= ( 1ULL << V_3 -> V_118 ) - 1 ;
} while ( ( V_14 = F_9 ( V_3 ) ) );
if ( ! F_1 ( V_3 , V_18 -> V_10 ) ) {
F_7 ( V_18 , L_8 ) ;
return - V_149 ;
}
V_47 = F_14 ( V_3 -> V_150 , 0 , V_151 ) ;
if ( F_41 ( V_47 ) )
return V_47 ;
V_59 -> V_90 = V_47 ;
if ( V_3 -> V_152 & V_153 ) {
V_59 -> V_88 = V_154 ;
V_36 = V_3 -> V_155 ;
} else if ( V_3 -> V_152 & V_156 ) {
V_59 -> V_88 = V_89 ;
V_36 = 0 ;
} else {
V_59 -> V_88 = V_154 ;
V_36 = V_3 -> V_155 ;
}
V_47 = F_14 ( V_3 -> V_157 , V_36 ,
V_3 -> V_158 ) ;
if ( F_41 ( V_47 ) )
goto V_159;
V_59 -> V_61 = V_47 ;
if ( V_3 -> V_92 == 1 ) {
V_59 -> V_93 = F_42 ( & V_3 -> V_93 ) ;
V_59 -> V_93 %= V_3 -> V_160 ;
} else {
V_59 -> V_93 = V_59 -> V_61 ;
}
V_45 = V_3 -> V_161 [ V_3 -> V_162 + V_59 -> V_93 ] ;
V_47 = F_43 ( V_45 , F_26 , V_163 ,
L_9 , V_54 ) ;
if ( F_41 ( V_47 ) ) {
F_7 ( V_3 -> V_18 , L_10 ,
V_59 -> V_93 , V_45 ) ;
V_59 -> V_93 = - 1 ;
goto V_164;
}
V_59 -> V_3 = V_3 ;
F_33 ( V_56 ) ;
return V_47 ;
V_164:
F_17 ( V_3 -> V_157 , V_59 -> V_61 ) ;
V_159:
F_17 ( V_3 -> V_150 , V_59 -> V_90 ) ;
return V_47 ;
}
static void F_44 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_58 * V_59 = & V_56 -> V_59 ;
struct V_2 * V_3 = V_59 -> V_3 ;
int V_45 ;
if ( ! V_3 )
return;
if ( V_59 -> V_93 != - 1 ) {
V_45 = V_3 -> V_161 [ V_3 -> V_162 + V_59 -> V_93 ] ;
F_45 ( V_45 , V_54 ) ;
}
F_17 ( V_3 -> V_150 , V_59 -> V_90 ) ;
F_17 ( V_3 -> V_157 , V_59 -> V_61 ) ;
}
static int F_46 ( struct V_53 * V_54 )
{
struct V_55 * V_56 ;
T_4 * V_110 ;
V_56 = F_47 ( sizeof( * V_56 ) , V_28 ) ;
if ( ! V_56 )
return - V_29 ;
V_110 = F_47 ( V_165 * sizeof( T_4 ) , V_28 ) ;
if ( ! V_110 )
goto V_166;
V_56 -> V_59 . V_110 = V_110 ;
F_48 ( & V_56 -> V_167 ) ;
V_54 -> V_57 = V_56 ;
return 0 ;
V_166:
F_49 ( V_56 ) ;
return - V_29 ;
}
static void F_50 ( T_5 * V_168 )
{
T_6 V_169 = F_51 ( * V_168 ) ;
F_52 ( V_169 ) ;
F_53 ( V_169 ) ;
}
static void F_54 ( T_7 * V_170 )
{
int V_21 ;
T_5 * V_168 , * V_171 = F_55 ( V_170 , 0 ) ;
V_168 = V_171 ;
for ( V_21 = 0 ; V_21 < V_172 ; ++ V_21 ) {
if ( F_56 ( * V_168 ) )
continue;
F_50 ( V_168 ) ;
V_168 ++ ;
}
F_57 ( NULL , V_171 ) ;
}
static void F_58 ( T_4 * V_110 )
{
int V_21 ;
T_7 * V_170 , * V_173 = F_59 ( V_110 , 0 ) ;
V_170 = V_173 ;
for ( V_21 = 0 ; V_21 < V_174 ; ++ V_21 ) {
if ( F_60 ( * V_170 ) )
continue;
F_54 ( V_170 ) ;
V_170 ++ ;
}
F_61 ( NULL , V_173 ) ;
}
static void F_62 ( struct V_55 * V_56 )
{
int V_21 ;
struct V_58 * V_59 = & V_56 -> V_59 ;
T_4 * V_110 , * V_175 = V_59 -> V_110 ;
V_110 = V_175 ;
for ( V_21 = 0 ; V_21 < V_165 ; ++ V_21 ) {
if ( F_63 ( * V_110 ) )
continue;
F_58 ( V_110 ) ;
V_110 ++ ;
}
F_49 ( V_175 ) ;
}
static void F_64 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_54 -> V_57 ;
F_44 ( V_54 ) ;
F_62 ( V_56 ) ;
F_49 ( V_56 ) ;
}
static int F_65 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
int V_21 ;
struct V_176 * V_177 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
if ( ! ( V_3 -> V_152 & V_178 ) )
return 0 ;
if ( V_9 -> V_177 )
return - V_16 ;
V_177 = F_66 ( sizeof( * V_177 ) * V_9 -> V_30 , V_28 ) ;
if ( ! V_177 ) {
F_7 ( V_3 -> V_18 , L_11 ,
V_9 -> V_30 , V_9 -> V_10 -> V_23 ) ;
return - V_29 ;
}
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 ) {
int V_38 = F_14 ( V_3 -> V_179 , 0 ,
V_3 -> V_180 ) ;
if ( F_41 ( V_38 ) ) {
F_7 ( V_3 -> V_18 , L_12 ) ;
goto V_181;
}
V_177 [ V_21 ] = (struct V_176 ) {
. V_38 = V_38 ,
. V_182 = 0 ,
. V_183 = V_9 -> V_31 [ V_21 ] ,
} ;
}
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 ) {
T_3 V_85 = V_184 | V_177 [ V_21 ] . V_183 << V_185 |
V_177 [ V_21 ] . V_182 << V_186 ;
F_21 ( V_85 , V_40 + F_67 ( V_177 [ V_21 ] . V_38 ) ) ;
}
V_9 -> V_177 = V_177 ;
return 0 ;
V_181:
while ( -- V_21 >= 0 )
F_17 ( V_3 -> V_179 , V_177 [ V_21 ] . V_38 ) ;
F_49 ( V_177 ) ;
return - V_27 ;
}
static void F_68 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
int V_21 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
struct V_176 * V_177 = V_9 -> V_177 ;
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 ) {
T_8 V_38 = V_177 [ V_21 ] . V_38 ;
F_21 ( ~ V_184 , V_40 + F_67 ( V_38 ) ) ;
F_17 ( V_3 -> V_179 , V_38 ) ;
}
V_9 -> V_177 = NULL ;
F_49 ( V_177 ) ;
}
static void F_69 ( struct V_2 * V_3 ,
struct V_1 * V_9 )
{
int V_21 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 ) {
T_9 V_187 = V_9 -> V_31 [ V_21 ] ;
F_21 ( V_188 ,
V_40 + F_70 ( V_187 ) ) ;
}
}
static int F_71 ( struct V_55 * V_56 ,
struct V_1 * V_9 )
{
int V_21 , V_47 ;
struct V_2 * V_14 , * V_3 = V_56 -> V_59 . V_3 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
V_47 = F_65 ( V_3 , V_9 ) ;
if ( V_47 )
return V_47 ;
V_3 = V_56 -> V_189 ;
while ( ( V_14 = F_9 ( V_3 ) ) ) {
if ( V_3 -> V_152 & V_178 )
continue;
F_69 ( V_3 , V_9 ) ;
V_3 = V_14 ;
}
for ( V_21 = 0 ; V_21 < V_9 -> V_30 ; ++ V_21 ) {
T_3 V_38 , V_190 ;
V_38 = V_9 -> V_177 ? V_9 -> V_177 [ V_21 ] . V_38 : V_9 -> V_31 [ V_21 ] ;
V_190 = ( V_191 << V_192 ) |
( V_56 -> V_59 . V_61 << V_193 ) ;
F_21 ( V_190 , V_40 + F_70 ( V_38 ) ) ;
}
return 0 ;
}
static void F_72 ( struct V_55 * V_56 ,
struct V_1 * V_9 )
{
struct V_2 * V_3 = V_56 -> V_59 . V_3 ;
F_69 ( V_3 , V_9 ) ;
F_68 ( V_3 , V_9 ) ;
}
static int F_73 ( struct V_53 * V_54 , struct V_17 * V_18 )
{
int V_47 = - V_194 ;
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_2 * V_195 = V_18 -> V_146 . V_147 ;
struct V_1 * V_9 ;
if ( ! V_195 ) {
F_7 ( V_18 , L_13 ) ;
return - V_196 ;
}
F_10 ( & V_56 -> V_167 ) ;
if ( ! V_56 -> V_189 ) {
V_47 = F_40 ( V_54 , V_18 ) ;
if ( F_41 ( V_47 ) )
goto V_197;
V_56 -> V_189 = V_195 ;
} else if ( V_56 -> V_189 != V_195 ) {
F_7 ( V_18 ,
L_14 ,
F_74 ( V_56 -> V_189 -> V_18 ) ,
F_74 ( V_195 -> V_18 ) ) ;
goto V_197;
}
F_13 ( & V_56 -> V_167 ) ;
V_9 = F_1 ( V_56 -> V_189 , V_18 -> V_10 ) ;
if ( ! V_9 )
return - V_149 ;
return F_71 ( V_56 , V_9 ) ;
V_197:
F_13 ( & V_56 -> V_167 ) ;
return V_47 ;
}
static void F_75 ( struct V_53 * V_54 , struct V_17 * V_18 )
{
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_1 * V_9 ;
V_9 = F_1 ( V_56 -> V_189 , V_18 -> V_10 ) ;
if ( V_9 )
F_72 ( V_56 , V_9 ) ;
}
static void F_76 ( struct V_2 * V_3 , void * V_198 ,
T_10 V_199 )
{
unsigned long V_200 = ( unsigned long ) V_198 & ~ V_201 ;
if ( ! ( V_3 -> V_152 & V_202 ) )
F_77 ( V_3 -> V_18 , F_78 ( V_198 ) , V_200 , V_199 ,
V_203 ) ;
}
static bool F_79 ( unsigned long V_198 ,
unsigned long V_37 )
{
return ! ( V_198 & ~ V_204 ) &&
( V_198 + V_205 <= V_37 ) ;
}
static int F_80 ( struct V_2 * V_3 , T_5 * V_168 ,
unsigned long V_198 , unsigned long V_37 ,
unsigned long V_206 , int V_46 , int V_207 )
{
T_11 * V_208 , * V_36 ;
T_12 V_209 = V_210 | V_211 ;
if ( F_56 ( * V_168 ) ) {
T_6 V_169 = F_81 ( V_212 ) ;
if ( ! V_169 )
return - V_29 ;
F_76 ( V_3 , F_82 ( V_169 ) ,
V_213 ) ;
F_83 ( V_169 ) ;
F_84 ( NULL , V_168 , V_169 ) ;
F_76 ( V_3 , V_168 , sizeof( * V_168 ) ) ;
}
if ( V_207 == 1 ) {
V_209 |= V_214 ;
if ( ! ( V_46 & V_215 ) && ( V_46 & V_216 ) )
V_209 |= V_217 ;
if ( V_46 & V_218 )
V_209 |= ( V_133 <<
V_219 ) ;
} else {
V_209 |= V_220 ;
if ( V_46 & V_216 )
V_209 |= V_221 ;
if ( V_46 & V_215 )
V_209 |= V_222 ;
if ( V_46 & V_218 )
V_209 |= V_223 ;
else
V_209 |= V_224 ;
}
if ( ! ( V_46 & ( V_216 | V_215 ) ) )
V_209 &= ~ V_210 ;
V_209 |= V_225 ;
V_36 = F_85 ( * V_168 ) + F_86 ( V_198 ) ;
V_208 = V_36 ;
do {
int V_21 = 1 ;
V_209 &= ~ V_226 ;
if ( F_79 ( V_198 , V_37 ) ) {
V_21 = V_227 ;
V_209 |= V_226 ;
} else if ( F_87 ( * V_208 ) &
( V_226 | V_210 ) ) {
int V_228 ;
T_11 * V_229 ;
unsigned long V_38 = F_86 ( V_198 ) ;
V_38 &= ~ ( V_227 - 1 ) ;
V_229 = F_85 ( * V_168 ) + V_38 ;
for ( V_228 = 0 ; V_228 < V_227 ; ++ V_228 )
F_87 ( * ( V_229 + V_228 ) ) &= ~ V_226 ;
F_76 ( V_3 , V_229 ,
sizeof( * V_208 ) *
V_227 ) ;
}
do {
* V_208 = F_88 ( V_206 , F_89 ( V_209 ) ) ;
} while ( V_208 ++ , V_206 ++ , V_198 += V_114 , -- V_21 );
} while ( V_198 != V_37 );
F_76 ( V_3 , V_36 , sizeof( * V_208 ) * ( V_208 - V_36 ) ) ;
return 0 ;
}
static int F_90 ( struct V_2 * V_3 , T_7 * V_170 ,
unsigned long V_198 , unsigned long V_37 ,
V_112 V_230 , int V_46 , int V_207 )
{
int V_47 ;
T_5 * V_168 ;
unsigned long V_231 , V_206 = F_91 ( V_230 ) ;
#ifndef F_92
if ( F_60 ( * V_170 ) ) {
V_168 = F_93 ( NULL , V_198 ) ;
if ( ! V_168 )
return - V_29 ;
} else
#endif
V_168 = F_55 ( V_170 , V_198 ) ;
do {
V_231 = F_94 ( V_198 , V_37 ) ;
V_47 = F_80 ( V_3 , V_168 , V_198 , V_37 , V_206 ,
V_46 , V_207 ) ;
F_95 ( NULL , V_170 , V_168 ) ;
F_76 ( V_3 , V_170 , sizeof( * V_170 ) ) ;
V_230 += V_231 - V_198 ;
} while ( V_168 ++ , V_198 = V_231 , V_198 < V_37 );
return V_47 ;
}
static int F_96 ( struct V_2 * V_3 , T_4 * V_110 ,
unsigned long V_198 , unsigned long V_37 ,
V_112 V_230 , int V_46 , int V_207 )
{
int V_47 = 0 ;
T_7 * V_170 ;
unsigned long V_231 ;
#ifndef F_97
if ( F_63 ( * V_110 ) ) {
V_170 = F_98 ( NULL , V_198 ) ;
if ( ! V_170 )
return - V_29 ;
} else
#endif
V_170 = F_59 ( V_110 , V_198 ) ;
do {
V_231 = F_99 ( V_198 , V_37 ) ;
V_47 = F_90 ( V_3 , V_170 , V_198 , V_231 , V_230 ,
V_46 , V_207 ) ;
F_100 ( NULL , V_170 , V_110 ) ;
F_76 ( V_3 , V_110 , sizeof( * V_110 ) ) ;
V_230 += V_231 - V_198 ;
} while ( V_170 ++ , V_198 = V_231 , V_198 < V_37 );
return V_47 ;
}
static int F_101 ( struct V_55 * V_56 ,
unsigned long V_52 , V_112 V_232 ,
T_10 V_199 , int V_46 )
{
int V_47 , V_207 ;
unsigned long V_37 ;
V_112 V_233 , V_148 ;
struct V_58 * V_59 = & V_56 -> V_59 ;
T_4 * V_110 = V_59 -> V_110 ;
struct V_2 * V_3 = V_59 -> V_3 ;
if ( V_59 -> V_88 == V_89 ) {
V_207 = 2 ;
V_148 = ( 1ULL << V_3 -> V_118 ) - 1 ;
} else {
V_207 = 1 ;
V_148 = ( 1ULL << V_3 -> V_107 ) - 1 ;
}
if ( ! V_110 )
return - V_194 ;
if ( V_199 & ~ V_201 )
return - V_194 ;
V_233 = ( 1ULL << V_3 -> V_99 ) - 1 ;
if ( ( V_112 ) V_52 & ~ V_233 )
return - V_234 ;
if ( V_232 & ~ V_148 )
return - V_234 ;
F_10 ( & V_56 -> V_167 ) ;
V_110 += F_102 ( V_52 ) ;
V_37 = V_52 + V_199 ;
do {
unsigned long V_231 = F_103 ( V_52 , V_37 ) ;
V_47 = F_96 ( V_3 , V_110 , V_52 , V_231 , V_232 ,
V_46 , V_207 ) ;
if ( V_47 )
goto V_34;
V_232 += V_231 - V_52 ;
V_52 = V_231 ;
} while ( V_110 ++ , V_52 != V_37 );
V_34:
F_13 ( & V_56 -> V_167 ) ;
if ( V_3 -> V_152 & V_202 )
F_104 () ;
return V_47 ;
}
static int F_105 ( struct V_53 * V_54 , unsigned long V_52 ,
V_112 V_232 , T_10 V_199 , int V_46 )
{
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_2 * V_3 = V_56 -> V_189 ;
if ( ! V_56 || ! V_3 )
return - V_149 ;
if ( ( V_112 ) V_52 & ~ V_56 -> V_148 )
return - V_234 ;
return F_101 ( V_56 , V_52 , V_232 , V_199 , V_46 ) ;
}
static T_10 F_106 ( struct V_53 * V_54 , unsigned long V_52 ,
T_10 V_199 )
{
int V_47 ;
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_58 * V_59 = & V_56 -> V_59 ;
struct V_2 * V_3 = V_59 -> V_3 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
V_47 = F_101 ( V_56 , V_52 , 0 , V_199 , 0 ) ;
F_21 ( V_59 -> V_90 , V_40 + V_137 ) ;
F_19 ( V_3 ) ;
return V_47 ? V_47 : V_199 ;
}
static V_112 F_107 ( struct V_53 * V_54 ,
T_13 V_52 )
{
T_4 * V_110 ;
T_7 * V_170 ;
T_5 * V_168 ;
T_11 * V_208 ;
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_58 * V_59 = & V_56 -> V_59 ;
struct V_2 * V_3 = V_59 -> V_3 ;
F_10 ( & V_56 -> V_167 ) ;
V_110 = V_59 -> V_110 ;
if ( ! V_110 )
goto V_197;
V_110 += F_102 ( V_52 ) ;
if ( F_108 ( V_110 ) )
goto V_197;
V_170 = F_59 ( V_110 , V_52 ) ;
if ( F_109 ( V_170 ) )
goto V_197;
V_168 = F_55 ( V_170 , V_52 ) ;
if ( F_110 ( V_168 ) )
goto V_197;
V_208 = F_85 ( * V_168 ) + F_86 ( V_52 ) ;
if ( F_111 ( V_208 ) )
goto V_197;
F_13 ( & V_56 -> V_167 ) ;
return F_112 ( F_113 ( * V_208 ) ) | ( V_52 & ~ V_201 ) ;
V_197:
F_13 ( & V_56 -> V_167 ) ;
F_12 ( V_3 -> V_18 ,
L_15 ,
( unsigned long long ) V_52 ) ;
return - V_194 ;
}
static int F_114 ( struct V_53 * V_54 ,
unsigned long V_235 )
{
unsigned long V_236 = 0 ;
struct V_55 * V_56 = V_54 -> V_57 ;
if ( V_56 -> V_59 . V_3 -> V_152 & V_202 )
V_236 |= V_237 ;
return ! ! ( V_235 & V_236 ) ;
}
static int F_115 ( struct V_17 * V_18 )
{
struct V_2 * V_238 , * V_14 , * V_3 ;
struct V_1 * V_9 = NULL ;
F_10 ( & V_33 ) ;
F_11 (parent, &arm_smmu_devices, list) {
V_3 = V_14 ;
F_11 (child, &arm_smmu_devices, list) {
if ( V_238 -> V_32 == V_14 -> V_18 -> V_10 ) {
V_9 = F_1 ( V_238 , V_18 -> V_10 ) ;
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
return - V_149 ;
V_18 -> V_146 . V_147 = V_3 ;
return 0 ;
}
static void F_116 ( struct V_17 * V_18 )
{
V_18 -> V_146 . V_147 = NULL ;
}
static void F_117 ( struct V_2 * V_3 )
{
void T_1 * V_40 = F_20 ( V_3 ) ;
int V_21 = 0 ;
T_3 V_239 = F_22 ( V_40 + V_240 ) ;
for ( V_21 = 0 ; V_21 < V_3 -> V_180 ; ++ V_21 ) {
F_21 ( ~ V_184 , V_40 + F_67 ( V_21 ) ) ;
F_21 ( V_188 , V_40 + F_70 ( V_21 ) ) ;
}
F_21 ( 0 , V_40 + V_241 ) ;
F_21 ( 0 , V_40 + V_242 ) ;
F_21 ( 0 , V_40 + V_243 ) ;
V_239 |= ( V_244 | V_245 | V_246 | V_247 ) ;
V_239 |= ( V_248 | V_249 ) ;
V_239 &= ~ ( V_250 | V_251 ) ;
V_239 &= ~ V_252 ;
V_239 &= ~ ( V_253 << V_254 ) ;
F_19 ( V_3 ) ;
F_31 ( V_239 , V_40 + V_240 ) ;
}
static int F_118 ( int V_199 )
{
switch ( V_199 ) {
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
static int F_119 ( struct V_2 * V_3 )
{
unsigned long V_199 ;
void T_1 * V_40 = F_20 ( V_3 ) ;
T_3 V_183 ;
F_120 ( V_3 -> V_18 , L_16 ) ;
V_183 = F_22 ( V_40 + V_255 ) ;
V_3 -> V_92 = ( ( V_183 >> V_256 ) & V_257 ) + 1 ;
F_120 ( V_3 -> V_18 , L_17 , V_3 -> V_92 ) ;
V_183 = F_22 ( V_40 + V_258 ) ;
#ifndef F_29
if ( ( ( V_183 >> V_259 ) & V_260 ) == V_261 ) {
F_7 ( V_3 -> V_18 , L_18 ) ;
return - V_149 ;
}
#endif
if ( V_183 & V_262 ) {
V_3 -> V_152 |= V_263 ;
F_120 ( V_3 -> V_18 , L_19 ) ;
}
if ( V_183 & V_264 ) {
V_3 -> V_152 |= V_156 ;
F_120 ( V_3 -> V_18 , L_20 ) ;
}
if ( V_183 & V_265 ) {
V_3 -> V_152 |= V_153 ;
F_120 ( V_3 -> V_18 , L_21 ) ;
}
if ( ! ( V_3 -> V_152 &
( V_263 | V_156 |
V_153 ) ) ) {
F_7 ( V_3 -> V_18 , L_22 ) ;
return - V_149 ;
}
if ( V_183 & V_266 ) {
V_3 -> V_152 |= V_202 ;
F_120 ( V_3 -> V_18 , L_23 ) ;
}
if ( V_183 & V_267 ) {
T_3 V_268 , V_187 , V_182 ;
V_3 -> V_152 |= V_178 ;
V_3 -> V_180 = ( V_183 >> V_269 ) &
V_270 ;
if ( V_3 -> V_180 == 0 ) {
F_7 ( V_3 -> V_18 ,
L_24 ) ;
return - V_149 ;
}
V_268 = V_271 << V_186 ;
V_268 |= ( V_272 << V_185 ) ;
F_21 ( V_268 , V_40 + F_67 ( 0 ) ) ;
V_268 = F_22 ( V_40 + F_67 ( 0 ) ) ;
V_182 = ( V_268 >> V_186 ) & V_271 ;
V_187 = ( V_268 >> V_185 ) & V_272 ;
if ( ( V_182 & V_187 ) != V_187 ) {
F_7 ( V_3 -> V_18 ,
L_25 ,
V_182 , V_187 ) ;
return - V_149 ;
}
F_120 ( V_3 -> V_18 ,
L_26 ,
V_3 -> V_180 , V_182 ) ;
}
V_183 = F_22 ( V_40 + V_273 ) ;
V_3 -> V_274 = ( V_183 & V_275 ) ? V_276 : V_115 ;
V_199 = 1 << ( ( ( V_183 >> V_277 ) & V_278 ) + 1 ) ;
V_199 *= ( V_3 -> V_274 << 1 ) ;
if ( V_3 -> V_199 < V_199 )
F_12 ( V_3 -> V_18 ,
L_27 ,
V_199 , V_3 -> V_199 ) ;
V_3 -> V_155 = ( V_183 >> V_279 ) &
V_280 ;
V_3 -> V_158 = ( V_183 >> V_281 ) & V_282 ;
if ( V_3 -> V_155 > V_3 -> V_158 ) {
F_7 ( V_3 -> V_18 , L_28 ) ;
return - V_149 ;
}
F_120 ( V_3 -> V_18 , L_29 ,
V_3 -> V_158 , V_3 -> V_155 ) ;
V_183 = F_22 ( V_40 + V_283 ) ;
V_199 = F_118 ( ( V_183 >> V_284 ) & V_285 ) ;
#ifdef F_29
V_3 -> V_107 = F_121 ( 39UL , V_199 ) ;
#else
V_3 -> V_107 = F_121 ( 32UL , V_199 ) ;
#endif
V_199 = F_118 ( ( V_183 >> V_286 ) & V_287 ) ;
V_3 -> V_118 = F_121 ( ( unsigned long ) V_288 , V_199 ) ;
if ( V_3 -> V_92 == 1 ) {
V_3 -> V_99 = 32 ;
} else {
#ifdef F_29
V_199 = ( V_183 >> V_289 ) & V_290 ;
V_199 = F_121 ( 39 , F_118 ( V_199 ) ) ;
#else
V_199 = 32 ;
#endif
V_3 -> V_99 = V_199 ;
if ( ( V_114 == V_115 && ! ( V_183 & V_291 ) ) ||
( V_114 == V_276 && ! ( V_183 & V_292 ) ) ||
( V_114 != V_115 && V_114 != V_276 ) ) {
F_7 ( V_3 -> V_18 , L_30 ,
V_114 ) ;
return - V_149 ;
}
}
F_120 ( V_3 -> V_18 ,
L_31 ,
V_3 -> V_99 , V_3 -> V_107 , V_3 -> V_118 ) ;
return 0 ;
}
static int F_122 ( struct V_293 * V_294 )
{
struct V_295 * V_296 ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_17 * V_18 = & V_294 -> V_18 ;
struct V_6 * V_7 ;
struct V_19 V_20 ;
int V_297 , V_21 , V_298 ;
V_3 = F_8 ( V_18 , sizeof( * V_3 ) , V_28 ) ;
if ( ! V_3 ) {
F_7 ( V_18 , L_32 ) ;
return - V_29 ;
}
V_3 -> V_18 = V_18 ;
V_296 = F_123 ( V_294 , V_299 , 0 ) ;
if ( ! V_296 ) {
F_7 ( V_18 , L_33 ) ;
return - V_149 ;
}
V_3 -> V_199 = F_124 ( V_296 ) ;
V_3 -> V_300 = F_125 ( V_18 , V_296 ) ;
if ( ! V_3 -> V_300 )
return - V_301 ;
if ( F_126 ( V_18 -> V_10 , L_34 ,
& V_3 -> V_162 ) ) {
F_7 ( V_18 , L_35 ) ;
return - V_149 ;
}
V_297 = 0 ;
while ( ( V_296 = F_123 ( V_294 , V_302 , V_297 ) ) ) {
V_297 ++ ;
if ( V_297 > V_3 -> V_162 )
V_3 -> V_160 ++ ;
}
if ( V_297 < V_3 -> V_162 ) {
F_12 ( V_18 , L_36 ,
V_297 , V_3 -> V_162 ) ;
V_3 -> V_162 = V_297 ;
}
V_3 -> V_160 = V_297 - V_3 -> V_162 ;
V_3 -> V_161 = F_8 ( V_18 , sizeof( * V_3 -> V_161 ) * V_297 ,
V_28 ) ;
if ( ! V_3 -> V_161 ) {
F_7 ( V_18 , L_37 , V_297 ) ;
return - V_29 ;
}
for ( V_21 = 0 ; V_21 < V_297 ; ++ V_21 ) {
int V_45 = F_127 ( V_294 , V_21 ) ;
if ( V_45 < 0 ) {
F_7 ( V_18 , L_38 , V_21 ) ;
return - V_149 ;
}
V_3 -> V_161 [ V_21 ] = V_45 ;
}
V_21 = 0 ;
V_3 -> V_8 = V_303 ;
while ( ! F_128 ( V_18 -> V_10 , L_39 ,
L_40 , V_21 ,
& V_20 ) ) {
V_298 = F_6 ( V_3 , V_18 , & V_20 ) ;
if ( V_298 ) {
F_7 ( V_18 , L_41 ,
V_20 . V_22 -> V_23 ) ;
goto V_304;
}
V_21 ++ ;
}
F_120 ( V_18 , L_42 , V_21 ) ;
if ( ( V_5 = F_129 ( V_18 -> V_10 , L_43 , 0 ) ) )
V_3 -> V_32 = V_5 ;
V_298 = F_119 ( V_3 ) ;
if ( V_298 )
goto V_305;
if ( V_3 -> V_92 > 1 &&
V_3 -> V_158 != V_3 -> V_160 ) {
F_7 ( V_18 ,
L_44 ,
V_3 -> V_160 , V_3 -> V_158 ) ;
goto V_305;
}
F_117 ( V_3 ) ;
for ( V_21 = 0 ; V_21 < V_3 -> V_162 ; ++ V_21 ) {
V_298 = F_43 ( V_3 -> V_161 [ V_21 ] ,
F_32 ,
V_163 ,
L_45 ,
V_3 ) ;
if ( V_298 ) {
F_7 ( V_18 , L_46 ,
V_21 , V_3 -> V_161 [ V_21 ] ) ;
goto V_306;
}
}
F_130 ( & V_3 -> V_307 ) ;
F_10 ( & V_33 ) ;
F_131 ( & V_3 -> V_307 , & V_308 ) ;
F_13 ( & V_33 ) ;
return 0 ;
V_306:
while ( V_21 -- )
F_45 ( V_3 -> V_161 [ V_21 ] , V_3 ) ;
V_305:
if ( V_3 -> V_32 )
F_132 ( V_3 -> V_32 ) ;
V_304:
for ( V_7 = F_133 ( & V_3 -> V_8 ) ; V_7 ; V_7 = F_134 ( V_7 ) ) {
struct V_1 * V_9 ;
V_9 = F_2 ( V_7 , struct V_1 , V_7 ) ;
F_132 ( V_9 -> V_10 ) ;
}
return V_298 ;
}
static int F_135 ( struct V_293 * V_294 )
{
int V_21 ;
struct V_17 * V_18 = & V_294 -> V_18 ;
struct V_2 * V_309 , * V_3 = NULL ;
struct V_6 * V_7 ;
F_10 ( & V_33 ) ;
F_11 (curr, &arm_smmu_devices, list) {
if ( V_309 -> V_18 == V_18 ) {
V_3 = V_309 ;
F_136 ( & V_3 -> V_307 ) ;
break;
}
}
F_13 ( & V_33 ) ;
if ( ! V_3 )
return - V_149 ;
if ( V_3 -> V_32 )
F_132 ( V_3 -> V_32 ) ;
for ( V_7 = F_133 ( & V_3 -> V_8 ) ; V_7 ; V_7 = F_134 ( V_7 ) ) {
struct V_1 * V_9 ;
V_9 = F_2 ( V_7 , struct V_1 , V_7 ) ;
F_132 ( V_9 -> V_10 ) ;
}
if ( ! F_137 ( V_3 -> V_150 , V_151 ) )
F_7 ( V_18 , L_47 ) ;
for ( V_21 = 0 ; V_21 < V_3 -> V_162 ; ++ V_21 )
F_45 ( V_3 -> V_161 [ V_21 ] , V_3 ) ;
F_31 ( V_250 , F_20 ( V_3 ) + V_240 ) ;
return 0 ;
}
static int T_14 F_138 ( void )
{
int V_47 ;
V_47 = F_139 ( & V_310 ) ;
if ( V_47 )
return V_47 ;
if ( ! F_140 ( & V_311 ) ) ;
F_141 ( & V_311 , & V_312 ) ;
if ( ! F_140 ( & V_313 ) ) ;
F_141 ( & V_313 , & V_312 ) ;
return 0 ;
}
static void T_15 F_142 ( void )
{
return F_143 ( & V_310 ) ;
}

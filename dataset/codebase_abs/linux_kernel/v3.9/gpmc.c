static void F_1 ( int V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_3 + V_1 ) ;
}
static T_1 F_3 ( int V_1 )
{
return F_4 ( V_3 + V_1 ) ;
}
void F_5 ( int V_4 , int V_1 , T_1 V_2 )
{
void T_2 * V_5 ;
V_5 = V_3 + V_6 + ( V_4 * V_7 ) + V_1 ;
F_2 ( V_2 , V_5 ) ;
}
T_1 F_6 ( int V_4 , int V_1 )
{
void T_2 * V_5 ;
V_5 = V_3 + V_6 + ( V_4 * V_7 ) + V_1 ;
return F_4 ( V_5 ) ;
}
unsigned long F_7 ( void )
{
unsigned long V_8 = F_8 ( V_9 ) ;
if ( V_8 == 0 ) {
F_9 ( V_10 L_1 ) ;
return 0 ;
}
V_8 /= 1000 ;
V_8 = 1000000000 / V_8 ;
return V_8 ;
}
unsigned int F_10 ( unsigned int V_11 )
{
unsigned long V_12 ;
V_12 = F_7 () ;
return ( V_11 * 1000 + V_12 - 1 ) / V_12 ;
}
unsigned int F_11 ( unsigned int V_13 )
{
unsigned long V_12 ;
V_12 = F_7 () ;
return ( V_13 + V_12 - 1 ) / V_12 ;
}
unsigned int F_12 ( unsigned int V_14 )
{
return V_14 * F_7 () / 1000 ;
}
unsigned int F_13 ( unsigned int V_11 )
{
unsigned long V_14 = F_10 ( V_11 ) ;
return V_14 * F_7 () / 1000 ;
}
static unsigned int F_14 ( unsigned int V_14 )
{
return V_14 * F_7 () ;
}
static unsigned int F_15 ( unsigned int V_13 )
{
unsigned long V_14 = F_11 ( V_13 ) ;
return V_14 * F_7 () ;
}
static inline void F_16 ( int V_4 , int V_15 , T_1 V_16 , bool V_17 )
{
T_1 V_18 ;
V_18 = F_6 ( V_4 , V_15 ) ;
if ( V_17 )
V_18 |= V_16 ;
else
V_18 &= ~ V_16 ;
F_5 ( V_4 , V_15 , V_18 ) ;
}
static void F_17 ( int V_4 , const struct V_19 * V_20 )
{
F_16 ( V_4 , V_21 ,
V_22 ,
V_20 -> V_23 ) ;
F_16 ( V_4 , V_24 ,
V_25 , V_20 -> V_26 ) ;
F_16 ( V_4 , V_27 ,
V_28 , V_20 -> V_29 ) ;
F_16 ( V_4 , V_30 ,
V_31 , V_20 -> V_32 ) ;
F_16 ( V_4 , V_30 ,
V_31 , V_20 -> V_33 ) ;
F_16 ( V_4 , V_34 ,
V_35 ,
V_20 -> V_36 ) ;
F_16 ( V_4 , V_34 ,
V_37 ,
V_20 -> V_38 ) ;
}
int F_18 ( unsigned int V_39 )
{
int div ;
T_1 V_18 ;
V_18 = V_39 + ( F_7 () - 1 ) ;
div = V_18 / F_7 () ;
if ( div > 4 )
return - 1 ;
if ( div <= 0 )
div = 1 ;
return div ;
}
int F_19 ( int V_4 , const struct V_40 * V_41 )
{
int div ;
T_1 V_18 ;
div = F_18 ( V_41 -> V_39 ) ;
if ( div < 0 )
return div ;
F_20 ( V_24 , 0 , 3 , V_42 ) ;
F_20 ( V_24 , 8 , 12 , V_43 ) ;
F_20 ( V_24 , 16 , 20 , V_44 ) ;
F_20 ( V_27 , 0 , 3 , V_45 ) ;
F_20 ( V_27 , 8 , 12 , V_46 ) ;
F_20 ( V_27 , 16 , 20 , V_47 ) ;
F_20 ( V_30 , 0 , 3 , V_48 ) ;
F_20 ( V_30 , 8 , 12 , V_49 ) ;
F_20 ( V_30 , 16 , 19 , V_50 ) ;
F_20 ( V_30 , 24 , 28 , V_51 ) ;
F_20 ( V_52 , 0 , 4 , V_53 ) ;
F_20 ( V_52 , 8 , 12 , V_54 ) ;
F_20 ( V_52 , 16 , 20 , V_55 ) ;
F_20 ( V_52 , 24 , 27 , V_56 ) ;
F_20 ( V_34 , 0 , 3 , V_57 ) ;
F_20 ( V_34 , 8 , 11 , V_58 ) ;
F_20 ( V_21 , 18 , 19 , V_59 ) ;
F_20 ( V_21 , 25 , 26 , V_60 ) ;
if ( V_61 & V_62 )
F_20 ( V_34 , 16 , 19 , V_63 ) ;
if ( V_61 & V_64 )
F_20 ( V_34 , 24 , 28 , V_65 ) ;
V_18 = F_6 ( V_4 , V_21 ) ;
if ( V_18 & ( V_66 | V_67 ) ) {
#ifdef F_21
F_9 ( V_68 L_2 ,
V_4 , ( div * F_7 () ) / 1000 , div ) ;
#endif
V_18 &= ~ 0x03 ;
V_18 |= ( div - 1 ) ;
F_5 ( V_4 , V_21 , V_18 ) ;
}
F_17 ( V_4 , & V_41 -> V_69 ) ;
return 0 ;
}
static void F_22 ( int V_4 , T_1 V_70 , T_1 V_71 )
{
T_1 V_18 ;
T_1 V_16 ;
V_16 = ( 1 << V_72 ) - V_71 ;
V_18 = F_6 ( V_4 , V_73 ) ;
V_18 &= ~ 0x3f ;
V_18 = ( V_70 >> V_74 ) & 0x3f ;
V_18 &= ~ ( 0x0f << 8 ) ;
V_18 |= ( ( V_16 >> V_74 ) & 0x0f ) << 8 ;
V_18 |= V_75 ;
F_5 ( V_4 , V_73 , V_18 ) ;
}
static void F_23 ( int V_4 )
{
T_1 V_18 ;
V_18 = F_6 ( V_4 , V_73 ) ;
V_18 &= ~ V_75 ;
F_5 ( V_4 , V_73 , V_18 ) ;
}
static void F_24 ( int V_4 , T_1 * V_70 , T_1 * V_71 )
{
T_1 V_18 ;
T_1 V_16 ;
V_18 = F_6 ( V_4 , V_73 ) ;
* V_70 = ( V_18 & 0x3f ) << V_74 ;
V_16 = ( V_18 >> 8 ) & 0x0f ;
* V_71 = ( 1 << V_72 ) - ( V_16 << V_74 ) ;
}
static int F_25 ( int V_4 )
{
T_1 V_18 ;
V_18 = F_6 ( V_4 , V_73 ) ;
return V_18 & V_75 ;
}
int F_26 ( int V_4 , int V_76 )
{
if ( V_4 > V_77 )
return - V_78 ;
V_79 &= ~ ( 1 << V_4 ) ;
V_79 |= ( V_76 ? 1 : 0 ) << V_4 ;
return 0 ;
}
int F_27 ( int V_4 )
{
if ( V_4 > V_77 )
return - V_78 ;
return V_79 & ( 1 << V_4 ) ;
}
static unsigned long F_28 ( unsigned long V_71 )
{
int V_80 ;
V_71 = ( V_71 - 1 ) >> ( V_74 - 1 ) ;
V_80 = V_74 - 1 ;
do {
V_71 >>= 1 ;
V_80 ++ ;
} while ( V_71 );
V_71 = 1 << V_80 ;
return V_71 ;
}
static int F_29 ( int V_4 , unsigned long V_70 , unsigned long V_71 )
{
struct V_81 * V_82 = & V_83 [ V_4 ] ;
int V_84 ;
V_71 = F_28 ( V_71 ) ;
F_30 ( & V_85 ) ;
V_82 -> V_86 = V_70 ;
V_82 -> V_87 = V_70 + V_71 - 1 ;
V_84 = F_31 ( & V_88 , V_82 ) ;
F_32 ( & V_85 ) ;
return V_84 ;
}
static int F_33 ( int V_4 )
{
struct V_81 * V_82 = & V_83 [ V_4 ] ;
int V_84 ;
F_30 ( & V_85 ) ;
V_84 = F_34 ( & V_83 [ V_4 ] ) ;
V_82 -> V_86 = 0 ;
V_82 -> V_87 = 0 ;
F_32 ( & V_85 ) ;
return V_84 ;
}
int F_35 ( int V_4 , unsigned long V_71 , unsigned long * V_70 )
{
struct V_81 * V_82 = & V_83 [ V_4 ] ;
int V_84 = - 1 ;
if ( V_4 > V_77 )
return - V_78 ;
V_71 = F_28 ( V_71 ) ;
if ( V_71 > ( 1 << V_72 ) )
return - V_89 ;
F_30 ( & V_85 ) ;
if ( F_27 ( V_4 ) ) {
V_84 = - V_90 ;
goto V_91;
}
if ( F_25 ( V_4 ) )
V_84 = F_36 ( V_82 , V_82 -> V_86 & ~ ( V_71 - 1 ) , V_71 ) ;
if ( V_84 < 0 )
V_84 = F_37 ( & V_88 , V_82 , V_71 , 0 , ~ 0 ,
V_71 , NULL , NULL ) ;
if ( V_84 < 0 )
goto V_91;
F_22 ( V_4 , V_82 -> V_86 , F_38 ( V_82 ) ) ;
* V_70 = V_82 -> V_86 ;
F_26 ( V_4 , 1 ) ;
V_91:
F_32 ( & V_85 ) ;
return V_84 ;
}
void F_39 ( int V_4 )
{
F_30 ( & V_85 ) ;
if ( V_4 >= V_77 || V_4 < 0 || ! F_27 ( V_4 ) ) {
F_9 ( V_92 L_3 , V_4 ) ;
F_40 () ;
F_32 ( & V_85 ) ;
return;
}
F_23 ( V_4 ) ;
F_34 ( & V_83 [ V_4 ] ) ;
F_26 ( V_4 , 0 ) ;
F_32 ( & V_85 ) ;
}
int F_41 ( int V_4 , int V_93 , int V_94 )
{
int V_95 = 0 ;
T_1 V_96 = 0 ;
switch ( V_93 ) {
case V_97 :
F_1 ( V_98 , V_94 ) ;
break;
case V_99 :
F_1 ( V_100 , V_94 ) ;
break;
case V_101 :
V_96 = F_3 ( V_102 ) ;
if ( V_94 )
V_96 &= ~ V_103 ;
else
V_96 |= V_103 ;
F_1 ( V_102 , V_96 ) ;
break;
case V_104 :
V_96 = F_6 ( V_4 , V_21 ) ;
if ( V_94 )
V_96 |= V_105 ;
else
V_96 &= ~ V_105 ;
F_5 ( V_4 , V_21 , V_96 ) ;
break;
case V_106 :
V_96 = F_6 ( V_4 , V_21 ) ;
V_96 &= ~ F_42 ( 3 ) ;
V_96 |= F_42 ( V_94 ) ;
F_5 ( V_4 , V_21 , V_96 ) ;
break;
case V_107 :
V_96 = F_6 ( V_4 , V_21 ) ;
V_96 |= F_43 ( V_94 ) ;
if ( V_94 == V_108 )
V_96 |= V_109 ;
F_5 ( V_4 , V_21 , V_96 ) ;
break;
default:
F_9 ( V_92 L_4 ) ;
V_95 = - V_110 ;
}
return V_95 ;
}
void F_44 ( struct V_111 * V_15 , int V_4 )
{
int V_112 ;
V_15 -> V_113 = V_3 + V_114 ;
V_15 -> V_115 = V_3 + V_6 +
V_116 + V_7 * V_4 ;
V_15 -> V_117 = V_3 + V_6 +
V_118 + V_7 * V_4 ;
V_15 -> V_119 = V_3 + V_6 +
V_120 + V_7 * V_4 ;
V_15 -> V_121 = V_3 + V_122 ;
V_15 -> V_123 = V_3 + V_124 ;
V_15 -> V_125 = V_3 + V_126 ;
V_15 -> V_127 = V_3 + V_128 ;
V_15 -> V_129 = V_3 + V_130 ;
V_15 -> V_131 = V_3 + V_132 ;
V_15 -> V_133 = V_3 + V_134 ;
V_15 -> V_135 = V_3 + V_136 ;
for ( V_112 = 0 ; V_112 < V_137 ; V_112 ++ ) {
V_15 -> V_138 [ V_112 ] = V_3 + V_139 +
V_140 * V_112 ;
V_15 -> V_141 [ V_112 ] = V_3 + V_142 +
V_140 * V_112 ;
V_15 -> V_143 [ V_112 ] = V_3 + V_144 +
V_140 * V_112 ;
V_15 -> V_145 [ V_112 ] = V_3 + V_146 +
V_140 * V_112 ;
}
}
int F_45 ( unsigned V_147 )
{
int V_112 ;
if ( F_46 ( V_147 ) > 1 )
return 0 ;
for ( V_112 = 0 ; V_112 < V_148 ; V_112 ++ )
if ( V_149 [ V_112 ] . V_150 & V_147 )
return V_149 [ V_112 ] . V_151 ;
return 0 ;
}
static int F_47 ( unsigned V_151 , bool V_152 )
{
int V_112 ;
T_1 V_96 ;
for ( V_112 = 0 ; V_112 < V_148 ; V_112 ++ )
if ( V_151 == V_149 [ V_112 ] . V_151 ) {
V_96 = F_3 ( V_98 ) ;
if ( V_152 )
V_96 |= V_149 [ V_112 ] . V_150 ;
else
V_96 &= ~ V_149 [ V_112 ] . V_150 ;
F_1 ( V_98 , V_96 ) ;
break;
}
return 0 ;
}
static void F_48 ( struct V_153 * V_20 )
{
F_47 ( V_20 -> V_151 , false ) ;
}
static void F_49 ( struct V_153 * V_20 )
{
F_47 ( V_20 -> V_151 , true ) ;
}
static void F_50 ( struct V_153 * V_154 ) { }
static unsigned int F_51 ( struct V_153 * V_154 ) { return 0 ; }
static int F_52 ( void )
{
int V_112 ;
T_1 V_96 ;
if ( ! V_155 )
return - V_110 ;
V_156 = F_53 ( - 1 , 0 , V_148 , 0 ) ;
if ( F_54 ( V_156 ) ) {
F_55 ( L_5 ) ;
return V_156 ;
}
V_157 . V_158 = L_6 ;
V_157 . V_159 = F_51 ;
V_157 . V_160 = F_49 ;
V_157 . V_161 = F_48 ;
V_157 . V_162 = F_50 ;
V_157 . V_163 = F_50 ;
V_157 . V_164 = F_50 ;
V_157 . V_165 = F_50 ;
V_149 [ 0 ] . V_150 = V_166 ;
V_149 [ 1 ] . V_150 = V_167 ;
for ( V_112 = 0 ; V_112 < V_148 ; V_112 ++ ) {
V_149 [ V_112 ] . V_151 = V_156 + V_112 ;
F_56 ( V_149 [ V_112 ] . V_151 ,
& V_157 , V_168 ) ;
F_57 ( V_149 [ V_112 ] . V_151 ,
V_169 | V_170 ) ;
}
F_1 ( V_98 , 0 ) ;
V_96 = F_3 ( V_100 ) ;
F_1 ( V_100 , V_96 ) ;
return F_58 ( V_155 , V_171 , 0 , L_6 , NULL ) ;
}
static int F_59 ( void )
{
int V_112 ;
if ( V_155 )
F_60 ( V_155 , NULL ) ;
for ( V_112 = 0 ; V_112 < V_148 ; V_112 ++ ) {
F_61 ( V_149 [ V_112 ] . V_151 , NULL ) ;
F_62 ( V_149 [ V_112 ] . V_151 , & V_172 ) ;
F_63 ( V_149 [ V_112 ] . V_151 , 0 , 0 ) ;
}
F_64 ( V_156 , V_148 ) ;
return 0 ;
}
static void F_65 ( void )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_77 ; V_4 ++ ) {
if ( ! F_25 ( V_4 ) )
continue;
F_33 ( V_4 ) ;
}
}
static int F_66 ( void )
{
int V_4 , V_173 ;
unsigned long V_174 = 0 ;
V_174 = V_175 ;
V_88 . V_86 = V_176 + V_174 ;
V_88 . V_87 = V_177 ;
for ( V_4 = 0 ; V_4 < V_77 ; V_4 ++ ) {
T_1 V_70 , V_71 ;
if ( ! F_25 ( V_4 ) )
continue;
F_24 ( V_4 , & V_70 , & V_71 ) ;
V_173 = F_29 ( V_4 , V_70 , V_71 ) ;
if ( F_54 ( V_173 ) ) {
while ( -- V_4 >= 0 )
if ( F_25 ( V_4 ) )
F_33 ( V_4 ) ;
return V_173 ;
}
}
return 0 ;
}
static T_1 F_67 ( T_1 V_13 , T_1 V_39 )
{
T_1 V_178 ;
int div ;
div = F_18 ( V_39 ) ;
V_178 = F_11 ( V_13 ) ;
V_178 = ( V_178 + div - 1 ) / div ;
return F_14 ( V_178 * div ) ;
}
static int F_68 ( struct V_40 * V_179 ,
struct V_180 * V_181 )
{
bool V_182 = V_181 -> V_182 ;
T_1 V_178 ;
V_178 = V_181 -> V_183 ;
if ( V_182 ) {
V_178 = F_69 ( T_1 , V_178 , V_179 -> V_60 + V_181 -> V_184 ) ;
V_178 = F_69 ( T_1 , V_179 -> V_45 + F_14 ( 1 ) , V_178 ) ;
}
V_179 -> V_46 = F_15 ( V_178 ) ;
V_178 = V_181 -> V_185 ;
if ( V_182 ) {
V_178 = F_69 ( T_1 , V_178 , V_179 -> V_60 + V_181 -> V_186 ) ;
V_178 = F_69 ( T_1 , V_178 , V_179 -> V_46 +
F_14 ( V_181 -> V_187 ) ) ;
}
V_179 -> V_48 = F_15 ( V_178 ) ;
V_178 = F_69 ( T_1 , V_181 -> V_188 , V_181 -> V_189 * V_179 -> V_39 ) ;
V_178 += V_179 -> V_60 ;
if ( V_181 -> V_190 )
V_178 = F_69 ( T_1 , V_178 , V_179 -> V_48 +
F_14 ( V_181 -> V_190 ) ) ;
V_179 -> V_55 = F_15 ( V_178 ) ;
V_179 -> V_49 = V_179 -> V_55 + F_14 ( 1 ) ;
V_179 -> V_43 = V_179 -> V_49 ;
V_178 = F_69 ( T_1 , V_181 -> V_191 , V_181 -> V_192 ) ;
V_178 = F_67 ( V_178 , V_179 -> V_39 ) +
V_179 -> V_55 ;
if ( V_181 -> V_193 )
V_178 = F_69 ( T_1 , V_178 , V_179 -> V_43 + V_181 -> V_193 ) ;
V_179 -> V_53 = F_15 ( V_178 ) ;
return 0 ;
}
static int F_70 ( struct V_40 * V_179 ,
struct V_180 * V_181 )
{
bool V_182 = V_181 -> V_182 ;
T_1 V_178 ;
V_178 = V_181 -> V_194 ;
if ( V_182 ) {
V_178 = F_69 ( T_1 , V_178 ,
V_179 -> V_60 + V_181 -> V_184 ) ;
V_178 = F_69 ( T_1 , V_179 -> V_45 + F_14 ( 1 ) , V_178 ) ;
}
V_179 -> V_47 = F_15 ( V_178 ) ;
V_178 = F_69 ( T_1 , V_181 -> V_195 ,
V_179 -> V_60 + V_181 -> V_196 ) ;
if ( V_182 ) {
V_178 = F_69 ( T_1 , V_178 ,
V_179 -> V_47 + V_181 -> V_197 ) ;
V_178 = F_69 ( T_1 , V_178 , V_179 -> V_47 +
F_14 ( V_181 -> V_198 ) ) ;
}
V_179 -> V_63 = F_15 ( V_178 ) ;
if ( V_61 & V_62 )
V_179 -> V_50 = F_15 ( V_181 -> V_195 ) ;
else
V_179 -> V_50 = V_179 -> V_63 ;
V_179 -> V_65 = V_179 -> V_55 ;
V_178 = V_179 -> V_50 + V_181 -> V_199 ;
V_178 = F_69 ( T_1 , V_178 ,
V_179 -> V_65 + F_14 ( 1 ) ) ;
V_178 = F_69 ( T_1 , V_178 ,
V_179 -> V_50 + F_14 ( V_181 -> V_200 ) ) ;
V_179 -> V_51 = F_15 ( V_178 ) ;
V_179 -> V_44 = F_15 ( V_179 -> V_51 +
V_181 -> V_201 ) ;
V_178 = F_67 ( V_181 -> V_202 , V_179 -> V_39 ) ;
V_178 += V_179 -> V_65 ;
if ( V_181 -> V_193 )
V_178 = F_69 ( T_1 , V_178 ,
V_179 -> V_44 + V_181 -> V_193 ) ;
V_179 -> V_54 = F_15 ( V_178 ) ;
return 0 ;
}
static int F_71 ( struct V_40 * V_179 ,
struct V_180 * V_181 )
{
bool V_182 = V_181 -> V_182 ;
T_1 V_178 ;
V_178 = V_181 -> V_183 ;
if ( V_182 )
V_178 = F_69 ( T_1 , V_179 -> V_45 + F_14 ( 1 ) , V_178 ) ;
V_179 -> V_46 = F_15 ( V_178 ) ;
V_178 = V_181 -> V_185 ;
if ( V_182 )
V_178 = F_69 ( T_1 , V_178 ,
V_179 -> V_46 + V_181 -> V_197 ) ;
V_179 -> V_48 = F_15 ( V_178 ) ;
V_178 = F_69 ( T_1 , V_181 -> V_188 ,
V_179 -> V_48 + V_181 -> V_203 ) ;
V_178 = F_69 ( T_1 , V_178 ,
V_179 -> V_42 + V_181 -> V_204 ) ;
V_178 = F_69 ( T_1 , V_178 ,
V_179 -> V_45 + V_181 -> V_205 ) ;
V_179 -> V_55 = F_15 ( V_178 ) ;
V_179 -> V_49 = V_179 -> V_55 + F_14 ( 1 ) ;
V_179 -> V_43 = V_179 -> V_49 ;
V_178 = F_69 ( T_1 , V_181 -> V_206 ,
V_179 -> V_43 + V_181 -> V_191 ) ;
V_178 = F_69 ( T_1 , V_178 , V_179 -> V_49 + V_181 -> V_192 ) ;
V_179 -> V_53 = F_15 ( V_178 ) ;
return 0 ;
}
static int F_72 ( struct V_40 * V_179 ,
struct V_180 * V_181 )
{
bool V_182 = V_181 -> V_182 ;
T_1 V_178 ;
V_178 = V_181 -> V_194 ;
if ( V_182 )
V_178 = F_69 ( T_1 , V_179 -> V_45 + F_14 ( 1 ) , V_178 ) ;
V_179 -> V_47 = F_15 ( V_178 ) ;
V_178 = V_181 -> V_195 ;
if ( V_182 ) {
V_178 = F_69 ( T_1 , V_178 , V_179 -> V_47 + V_181 -> V_197 ) ;
V_178 = F_69 ( T_1 , V_178 , V_179 -> V_47 +
F_14 ( V_181 -> V_198 ) ) ;
}
V_179 -> V_63 = F_15 ( V_178 ) ;
if ( V_61 & V_62 )
V_179 -> V_50 = F_15 ( V_181 -> V_195 ) ;
else
V_179 -> V_50 = V_179 -> V_63 ;
V_178 = V_179 -> V_50 + V_181 -> V_199 ;
V_179 -> V_51 = F_15 ( V_178 ) ;
V_179 -> V_44 = F_15 ( V_179 -> V_51 +
V_181 -> V_201 ) ;
V_178 = F_69 ( T_1 , V_181 -> V_207 ,
V_179 -> V_44 + V_181 -> V_202 ) ;
V_179 -> V_54 = F_15 ( V_178 ) ;
return 0 ;
}
static int F_73 ( struct V_40 * V_179 ,
struct V_180 * V_181 )
{
T_1 V_178 ;
V_179 -> V_39 = F_18 ( V_181 -> V_208 ) *
F_7 () ;
V_179 -> V_56 = F_67 (
V_181 -> V_209 ,
V_179 -> V_39 ) ;
V_178 = F_69 ( T_1 , V_181 -> V_210 , V_181 -> V_211 ) ;
V_179 -> V_60 = F_15 ( V_178 ) ;
if ( F_18 ( V_179 -> V_39 ) != 1 )
return 0 ;
if ( V_181 -> V_212 )
V_179 -> V_69 . V_26 = true ;
if ( V_181 -> V_213 )
V_179 -> V_69 . V_29 = true ;
if ( V_181 -> V_214 )
V_179 -> V_69 . V_32 = true ;
if ( V_181 -> V_215 )
V_179 -> V_69 . V_33 = true ;
return 0 ;
}
static int F_74 ( struct V_40 * V_179 ,
struct V_180 * V_181 )
{
T_1 V_178 ;
V_179 -> V_42 = F_15 ( V_181 -> V_216 ) ;
V_178 = V_181 -> V_217 ;
if ( V_181 -> V_218 )
V_178 = F_69 ( T_1 , V_178 ,
V_179 -> V_42 + V_181 -> V_218 ) ;
V_179 -> V_45 = F_15 ( V_178 ) ;
if ( V_181 -> V_219 || V_181 -> V_220 )
F_73 ( V_179 , V_181 ) ;
return 0 ;
}
static void F_75 ( struct V_40 * V_41 )
{
V_41 -> V_42 /= 1000 ;
V_41 -> V_43 /= 1000 ;
V_41 -> V_44 /= 1000 ;
V_41 -> V_45 /= 1000 ;
V_41 -> V_46 /= 1000 ;
V_41 -> V_47 /= 1000 ;
V_41 -> V_50 /= 1000 ;
V_41 -> V_51 /= 1000 ;
V_41 -> V_48 /= 1000 ;
V_41 -> V_49 /= 1000 ;
V_41 -> V_56 /= 1000 ;
V_41 -> V_55 /= 1000 ;
V_41 -> V_53 /= 1000 ;
V_41 -> V_54 /= 1000 ;
V_41 -> V_57 /= 1000 ;
V_41 -> V_58 /= 1000 ;
V_41 -> V_59 /= 1000 ;
V_41 -> V_60 /= 1000 ;
V_41 -> V_65 /= 1000 ;
V_41 -> V_63 /= 1000 ;
}
int F_76 ( struct V_40 * V_179 ,
struct V_180 * V_181 )
{
memset ( V_179 , 0 , sizeof( * V_179 ) ) ;
F_74 ( V_179 , V_181 ) ;
if ( V_181 -> V_220 )
F_68 ( V_179 , V_181 ) ;
else
F_71 ( V_179 , V_181 ) ;
if ( V_181 -> V_219 )
F_70 ( V_179 , V_181 ) ;
else
F_72 ( V_179 , V_181 ) ;
F_75 ( V_179 ) ;
return 0 ;
}
static void T_3 F_77 ( struct V_221 * V_222 ,
struct V_40 * V_179 )
{
T_1 V_2 ;
memset ( V_179 , 0 , sizeof( * V_179 ) ) ;
if ( ! F_78 ( V_222 , L_7 , & V_2 ) )
V_179 -> V_39 = V_2 ;
if ( ! F_78 ( V_222 , L_8 , & V_2 ) )
V_179 -> V_42 = V_2 ;
if ( ! F_78 ( V_222 , L_9 , & V_2 ) )
V_179 -> V_43 = V_2 ;
if ( ! F_78 ( V_222 , L_10 , & V_2 ) )
V_179 -> V_44 = V_2 ;
if ( ! F_78 ( V_222 , L_11 , & V_2 ) )
V_179 -> V_45 = V_2 ;
if ( ! F_78 ( V_222 , L_12 , & V_2 ) )
V_179 -> V_46 = V_2 ;
if ( ! F_78 ( V_222 , L_13 , & V_2 ) )
V_179 -> V_47 = V_2 ;
if ( ! F_78 ( V_222 , L_14 , & V_2 ) )
V_179 -> V_50 = V_2 ;
if ( ! F_78 ( V_222 , L_15 , & V_2 ) )
V_179 -> V_51 = V_2 ;
if ( ! F_78 ( V_222 , L_16 , & V_2 ) )
V_179 -> V_48 = V_2 ;
if ( ! F_78 ( V_222 , L_17 , & V_2 ) )
V_179 -> V_49 = V_2 ;
if ( ! F_78 ( V_222 , L_18 , & V_2 ) )
V_179 -> V_56 = V_2 ;
if ( ! F_78 ( V_222 , L_19 , & V_2 ) )
V_179 -> V_55 = V_2 ;
if ( ! F_78 ( V_222 , L_20 , & V_2 ) )
V_179 -> V_53 = V_2 ;
if ( ! F_78 ( V_222 , L_21 , & V_2 ) )
V_179 -> V_54 = V_2 ;
if ( ! F_78 ( V_222 , L_22 , & V_2 ) )
V_179 -> V_65 = V_2 ;
if ( ! F_78 ( V_222 , L_23 , & V_2 ) )
V_179 -> V_63 = V_2 ;
}
static int F_79 ( struct V_223 * V_224 ,
struct V_221 * V_225 )
{
T_1 V_2 ;
const char * V_226 ;
struct V_40 V_179 ;
struct V_227 * V_119 ;
if ( F_78 ( V_225 , L_24 , & V_2 ) < 0 ) {
F_80 ( & V_224 -> V_228 , L_25 ,
V_225 -> V_229 ) ;
return - V_78 ;
}
V_119 = F_81 ( & V_224 -> V_228 , sizeof( * V_119 ) ,
V_230 ) ;
if ( ! V_119 )
return - V_89 ;
V_119 -> V_4 = V_2 ;
V_119 -> V_231 = V_225 ;
if ( ! F_82 ( V_225 , L_26 , & V_226 ) )
for ( V_2 = 0 ; V_2 < F_83 ( V_232 ) ; V_2 ++ )
if ( ! strcasecmp ( V_226 , V_232 [ V_2 ] ) ) {
V_119 -> V_233 = V_2 ;
break;
}
V_2 = F_84 ( V_225 ) ;
if ( V_2 == 16 )
V_119 -> V_234 = V_235 ;
F_77 ( V_225 , & V_179 ) ;
F_85 ( V_119 , & V_179 ) ;
return 0 ;
}
static int F_79 ( struct V_223 * V_224 ,
struct V_221 * V_225 )
{
return 0 ;
}
static int F_86 ( struct V_223 * V_224 ,
struct V_221 * V_225 )
{
T_1 V_2 ;
struct V_236 * V_237 ;
if ( F_78 ( V_225 , L_24 , & V_2 ) < 0 ) {
F_80 ( & V_224 -> V_228 , L_25 ,
V_225 -> V_229 ) ;
return - V_78 ;
}
V_237 = F_81 ( & V_224 -> V_228 , sizeof( * V_237 ) ,
V_230 ) ;
if ( ! V_237 )
return - V_89 ;
V_237 -> V_4 = V_2 ;
V_237 -> V_231 = V_225 ;
V_237 -> V_238 = - 1 ;
if ( ! F_78 ( V_225 , L_27 , & V_2 ) )
V_237 -> V_238 = V_2 ;
F_87 ( V_237 ) ;
return 0 ;
}
static int F_86 ( struct V_223 * V_224 ,
struct V_221 * V_225 )
{
return 0 ;
}
static int F_88 ( struct V_223 * V_224 )
{
int V_239 ;
struct V_221 * V_225 ;
const struct V_240 * V_241 =
F_89 ( V_242 , & V_224 -> V_228 ) ;
if ( ! V_241 )
return 0 ;
F_90 (child, L_28 ) {
V_239 = F_79 ( V_224 , V_225 ) ;
if ( V_239 < 0 ) {
F_91 ( V_225 ) ;
return V_239 ;
}
}
F_90 (child, L_29 ) {
V_239 = F_86 ( V_224 , V_225 ) ;
if ( V_239 < 0 ) {
F_91 ( V_225 ) ;
return V_239 ;
}
}
return 0 ;
}
static int F_88 ( struct V_223 * V_224 )
{
return 0 ;
}
static int F_92 ( struct V_223 * V_224 )
{
int V_173 ;
T_1 V_18 ;
struct V_81 * V_82 ;
V_82 = F_93 ( V_224 , V_243 , 0 ) ;
if ( V_82 == NULL )
return - V_244 ;
V_245 = V_82 -> V_86 ;
V_246 = F_38 ( V_82 ) ;
V_3 = F_94 ( & V_224 -> V_228 , V_82 ) ;
if ( F_95 ( V_3 ) )
return F_96 ( V_3 ) ;
V_82 = F_93 ( V_224 , V_247 , 0 ) ;
if ( V_82 == NULL )
F_97 ( & V_224 -> V_228 , L_30 ) ;
else
V_155 = V_82 -> V_86 ;
V_9 = F_98 ( & V_224 -> V_228 , L_31 ) ;
if ( F_95 ( V_9 ) ) {
F_80 ( & V_224 -> V_228 , L_32 ) ;
V_155 = 0 ;
return F_96 ( V_9 ) ;
}
F_99 ( V_9 ) ;
V_248 = & V_224 -> V_228 ;
V_18 = F_3 ( V_249 ) ;
if ( F_100 ( V_18 ) > 0x4 )
V_61 = V_64 | V_62 ;
F_101 ( V_248 , L_33 , F_100 ( V_18 ) ,
F_102 ( V_18 ) ) ;
V_173 = F_66 () ;
if ( F_54 ( V_173 ) ) {
F_103 ( V_9 ) ;
F_104 ( V_9 ) ;
F_80 ( V_248 , L_34 ) ;
return V_173 ;
}
if ( F_54 ( F_52 () ) )
F_97 ( V_248 , L_35 ) ;
V_79 = 0 ;
V_173 = F_88 ( V_224 ) ;
if ( V_173 < 0 ) {
F_103 ( V_9 ) ;
F_104 ( V_9 ) ;
F_80 ( V_248 , L_36 ) ;
return V_173 ;
}
return 0 ;
}
static int F_105 ( struct V_223 * V_224 )
{
F_59 () ;
F_65 () ;
V_248 = NULL ;
return 0 ;
}
static T_4 int F_106 ( void )
{
return F_107 ( & V_250 ) ;
}
static T_5 void F_108 ( void )
{
F_109 ( & V_250 ) ;
}
static int T_4 F_110 ( void )
{
struct V_251 * V_252 ;
struct V_223 * V_224 ;
char * V_253 = L_6 ;
if ( F_111 () )
return - V_78 ;
V_252 = F_112 ( V_253 ) ;
if ( ! V_252 ) {
F_55 ( L_37 , V_253 ) ;
return - V_78 ;
}
V_224 = F_113 ( V_254 , - 1 , V_252 , NULL , 0 ) ;
F_114 ( F_95 ( V_224 ) , L_38 , V_253 ) ;
return F_95 ( V_224 ) ? F_96 ( V_224 ) : 0 ;
}
static T_6 V_171 ( int V_151 , void * V_228 )
{
int V_112 ;
T_1 V_96 ;
V_96 = F_3 ( V_100 ) ;
if ( ! V_96 )
return V_255 ;
for ( V_112 = 0 ; V_112 < V_148 ; V_112 ++ )
if ( V_96 & V_149 [ V_112 ] . V_150 )
F_115 ( V_149 [ V_112 ] . V_151 ) ;
F_1 ( V_100 , V_96 ) ;
return V_256 ;
}
void F_116 ( void )
{
int V_112 ;
V_257 . V_258 = F_3 ( V_259 ) ;
V_257 . V_260 = F_3 ( V_98 ) ;
V_257 . V_261 = F_3 ( V_262 ) ;
V_257 . V_263 = F_3 ( V_102 ) ;
V_257 . V_264 = F_3 ( V_122 ) ;
V_257 . V_265 = F_3 ( V_124 ) ;
V_257 . V_266 = F_3 ( V_126 ) ;
for ( V_112 = 0 ; V_112 < V_77 ; V_112 ++ ) {
V_257 . V_267 [ V_112 ] . V_268 = F_25 ( V_112 ) ;
if ( V_257 . V_267 [ V_112 ] . V_268 ) {
V_257 . V_267 [ V_112 ] . V_269 =
F_6 ( V_112 , V_21 ) ;
V_257 . V_267 [ V_112 ] . V_270 =
F_6 ( V_112 , V_24 ) ;
V_257 . V_267 [ V_112 ] . V_271 =
F_6 ( V_112 , V_27 ) ;
V_257 . V_267 [ V_112 ] . V_272 =
F_6 ( V_112 , V_30 ) ;
V_257 . V_267 [ V_112 ] . V_273 =
F_6 ( V_112 , V_52 ) ;
V_257 . V_267 [ V_112 ] . V_274 =
F_6 ( V_112 , V_34 ) ;
V_257 . V_267 [ V_112 ] . V_275 =
F_6 ( V_112 , V_73 ) ;
}
}
}
void F_117 ( void )
{
int V_112 ;
F_1 ( V_259 , V_257 . V_258 ) ;
F_1 ( V_98 , V_257 . V_260 ) ;
F_1 ( V_262 , V_257 . V_261 ) ;
F_1 ( V_102 , V_257 . V_263 ) ;
F_1 ( V_122 , V_257 . V_264 ) ;
F_1 ( V_124 , V_257 . V_265 ) ;
F_1 ( V_126 , V_257 . V_266 ) ;
for ( V_112 = 0 ; V_112 < V_77 ; V_112 ++ ) {
if ( V_257 . V_267 [ V_112 ] . V_268 ) {
F_5 ( V_112 , V_21 ,
V_257 . V_267 [ V_112 ] . V_269 ) ;
F_5 ( V_112 , V_24 ,
V_257 . V_267 [ V_112 ] . V_270 ) ;
F_5 ( V_112 , V_27 ,
V_257 . V_267 [ V_112 ] . V_271 ) ;
F_5 ( V_112 , V_30 ,
V_257 . V_267 [ V_112 ] . V_272 ) ;
F_5 ( V_112 , V_52 ,
V_257 . V_267 [ V_112 ] . V_273 ) ;
F_5 ( V_112 , V_34 ,
V_257 . V_267 [ V_112 ] . V_274 ) ;
F_5 ( V_112 , V_73 ,
V_257 . V_267 [ V_112 ] . V_275 ) ;
}
}
}

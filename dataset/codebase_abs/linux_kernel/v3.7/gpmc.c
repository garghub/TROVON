static void F_1 ( int V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_3 + V_1 ) ;
}
static T_1 F_3 ( int V_1 )
{
return F_4 ( V_3 + V_1 ) ;
}
static void F_5 ( int V_4 , int V_1 , T_2 V_2 )
{
void T_3 * V_5 ;
V_5 = V_3 + V_6 + ( V_4 * V_7 ) + V_1 ;
F_6 ( V_2 , V_5 ) ;
}
static T_2 F_7 ( int V_4 , int V_1 )
{
void T_3 * V_5 ;
V_5 = V_3 + V_6 + ( V_4 * V_7 ) + V_1 ;
return F_8 ( V_5 ) ;
}
void F_9 ( int V_4 , int V_1 , T_1 V_2 )
{
void T_3 * V_5 ;
V_5 = V_3 + V_6 + ( V_4 * V_7 ) + V_1 ;
F_2 ( V_2 , V_5 ) ;
}
T_1 F_10 ( int V_4 , int V_1 )
{
void T_3 * V_5 ;
V_5 = V_3 + V_6 + ( V_4 * V_7 ) + V_1 ;
return F_4 ( V_5 ) ;
}
unsigned long F_11 ( void )
{
unsigned long V_8 = F_12 ( V_9 ) ;
if ( V_8 == 0 ) {
F_13 ( V_10 L_1 ) ;
return 0 ;
}
V_8 /= 1000 ;
V_8 = 1000000000 / V_8 ;
return V_8 ;
}
unsigned int F_14 ( unsigned int V_11 )
{
unsigned long V_12 ;
V_12 = F_11 () ;
return ( V_11 * 1000 + V_12 - 1 ) / V_12 ;
}
unsigned int F_15 ( unsigned int V_13 )
{
unsigned long V_12 ;
V_12 = F_11 () ;
return ( V_13 + V_12 - 1 ) / V_12 ;
}
unsigned int F_16 ( unsigned int V_14 )
{
return V_14 * F_11 () / 1000 ;
}
unsigned int F_17 ( unsigned int V_11 )
{
unsigned long V_14 = F_14 ( V_11 ) ;
return V_14 * F_11 () / 1000 ;
}
int F_18 ( int V_4 , unsigned int V_15 )
{
int div ;
T_1 V_16 ;
V_16 = V_15 + ( F_11 () - 1 ) ;
div = V_16 / F_11 () ;
if ( div > 4 )
return - 1 ;
if ( div <= 0 )
div = 1 ;
return div ;
}
int F_19 ( int V_4 , const struct V_17 * V_18 )
{
int div ;
T_1 V_16 ;
div = F_18 ( V_4 , V_18 -> V_15 ) ;
if ( div < 0 )
return div ;
F_20 ( V_19 , 0 , 3 , V_20 ) ;
F_20 ( V_19 , 8 , 12 , V_21 ) ;
F_20 ( V_19 , 16 , 20 , V_22 ) ;
F_20 ( V_23 , 0 , 3 , V_24 ) ;
F_20 ( V_23 , 8 , 12 , V_25 ) ;
F_20 ( V_23 , 16 , 20 , V_26 ) ;
F_20 ( V_27 , 0 , 3 , V_28 ) ;
F_20 ( V_27 , 8 , 12 , V_29 ) ;
F_20 ( V_27 , 16 , 19 , V_30 ) ;
F_20 ( V_27 , 24 , 28 , V_31 ) ;
F_20 ( V_32 , 0 , 4 , V_33 ) ;
F_20 ( V_32 , 8 , 12 , V_34 ) ;
F_20 ( V_32 , 16 , 20 , V_35 ) ;
F_20 ( V_32 , 24 , 27 , V_36 ) ;
if ( V_37 & V_38 )
F_20 ( V_39 , 16 , 19 , V_40 ) ;
if ( V_37 & V_41 )
F_20 ( V_39 , 24 , 28 , V_42 ) ;
V_16 = F_10 ( V_4 , V_43 ) ;
if ( V_16 & ( V_44 | V_45 ) ) {
#ifdef F_21
F_13 ( V_46 L_2 ,
V_4 , ( div * F_11 () ) / 1000 , div ) ;
#endif
V_16 &= ~ 0x03 ;
V_16 |= ( div - 1 ) ;
F_9 ( V_4 , V_43 , V_16 ) ;
}
return 0 ;
}
static void F_22 ( int V_4 , T_1 V_47 , T_1 V_48 )
{
T_1 V_16 ;
T_1 V_49 ;
V_49 = ( 1 << V_50 ) - V_48 ;
V_16 = F_10 ( V_4 , V_51 ) ;
V_16 &= ~ 0x3f ;
V_16 = ( V_47 >> V_52 ) & 0x3f ;
V_16 &= ~ ( 0x0f << 8 ) ;
V_16 |= ( ( V_49 >> V_52 ) & 0x0f ) << 8 ;
V_16 |= V_53 ;
F_9 ( V_4 , V_51 , V_16 ) ;
}
static void F_23 ( int V_4 )
{
T_1 V_16 ;
V_16 = F_10 ( V_4 , V_51 ) ;
V_16 &= ~ V_53 ;
F_9 ( V_4 , V_51 , V_16 ) ;
}
static void F_24 ( int V_4 , T_1 * V_47 , T_1 * V_48 )
{
T_1 V_16 ;
T_1 V_49 ;
V_16 = F_10 ( V_4 , V_51 ) ;
* V_47 = ( V_16 & 0x3f ) << V_52 ;
V_49 = ( V_16 >> 8 ) & 0x0f ;
* V_48 = ( 1 << V_50 ) - ( V_49 << V_52 ) ;
}
static int F_25 ( int V_4 )
{
T_1 V_16 ;
V_16 = F_10 ( V_4 , V_51 ) ;
return V_16 & V_53 ;
}
int F_26 ( int V_4 , int V_54 )
{
if ( V_4 > V_55 )
return - V_56 ;
V_57 &= ~ ( 1 << V_4 ) ;
V_57 |= ( V_54 ? 1 : 0 ) << V_4 ;
return 0 ;
}
int F_27 ( int V_4 )
{
if ( V_4 > V_55 )
return - V_56 ;
return V_57 & ( 1 << V_4 ) ;
}
static unsigned long F_28 ( unsigned long V_48 )
{
int V_58 ;
V_48 = ( V_48 - 1 ) >> ( V_52 - 1 ) ;
V_58 = V_52 - 1 ;
do {
V_48 >>= 1 ;
V_58 ++ ;
} while ( V_48 );
V_48 = 1 << V_58 ;
return V_48 ;
}
static int F_29 ( int V_4 , unsigned long V_47 , unsigned long V_48 )
{
struct V_59 * V_60 = & V_61 [ V_4 ] ;
int V_62 ;
V_48 = F_28 ( V_48 ) ;
F_30 ( & V_63 ) ;
V_60 -> V_64 = V_47 ;
V_60 -> V_65 = V_47 + V_48 - 1 ;
V_62 = F_31 ( & V_66 , V_60 ) ;
F_32 ( & V_63 ) ;
return V_62 ;
}
static int F_33 ( int V_4 )
{
struct V_59 * V_60 = & V_61 [ V_4 ] ;
int V_62 ;
F_30 ( & V_63 ) ;
V_62 = F_34 ( & V_61 [ V_4 ] ) ;
V_60 -> V_64 = 0 ;
V_60 -> V_65 = 0 ;
F_32 ( & V_63 ) ;
return V_62 ;
}
int F_35 ( int V_4 , unsigned long V_48 , unsigned long * V_47 )
{
struct V_59 * V_60 = & V_61 [ V_4 ] ;
int V_62 = - 1 ;
if ( V_4 > V_55 )
return - V_56 ;
V_48 = F_28 ( V_48 ) ;
if ( V_48 > ( 1 << V_50 ) )
return - V_67 ;
F_30 ( & V_63 ) ;
if ( F_27 ( V_4 ) ) {
V_62 = - V_68 ;
goto V_69;
}
if ( F_25 ( V_4 ) )
V_62 = F_36 ( V_60 , V_60 -> V_64 & ~ ( V_48 - 1 ) , V_48 ) ;
if ( V_62 < 0 )
V_62 = F_37 ( & V_66 , V_60 , V_48 , 0 , ~ 0 ,
V_48 , NULL , NULL ) ;
if ( V_62 < 0 )
goto V_69;
F_22 ( V_4 , V_60 -> V_64 , F_38 ( V_60 ) ) ;
* V_47 = V_60 -> V_64 ;
F_26 ( V_4 , 1 ) ;
V_69:
F_32 ( & V_63 ) ;
return V_62 ;
}
void F_39 ( int V_4 )
{
F_30 ( & V_63 ) ;
if ( V_4 >= V_55 || V_4 < 0 || ! F_27 ( V_4 ) ) {
F_13 ( V_70 L_3 , V_4 ) ;
F_40 () ;
F_32 ( & V_63 ) ;
return;
}
F_23 ( V_4 ) ;
F_34 ( & V_61 [ V_4 ] ) ;
F_26 ( V_4 , 0 ) ;
F_32 ( & V_63 ) ;
}
int F_41 ( int V_71 )
{
int V_72 = - V_73 ;
T_1 V_74 = 0 ;
switch ( V_71 ) {
case V_75 :
V_72 = F_3 ( V_76 ) ;
break;
case V_77 :
V_74 = F_3 ( V_78 ) ;
V_72 = F_42 ( V_74 ) ;
break;
case V_79 :
V_74 = F_3 ( V_78 ) ;
V_72 = F_43 ( V_74 ) ;
break;
case V_80 :
V_74 = F_3 ( V_81 ) ;
V_72 = V_74 & V_82 ;
break;
default:
F_13 ( V_70 L_4 ) ;
}
return V_72 ;
}
int F_44 ( int V_4 , int V_71 , int V_83 )
{
int V_84 = 0 ;
T_1 V_74 = 0 ;
switch ( V_71 ) {
case V_85 :
F_1 ( V_86 , V_83 ) ;
break;
case V_87 :
F_1 ( V_76 , V_83 ) ;
break;
case V_88 :
V_74 = F_3 ( V_89 ) ;
if ( V_83 )
V_74 &= ~ V_90 ;
else
V_74 |= V_90 ;
F_1 ( V_89 , V_74 ) ;
break;
case V_91 :
V_74 = F_10 ( V_4 , V_43 ) ;
if ( V_83 )
V_74 |= V_92 ;
else
V_74 &= ~ V_92 ;
F_9 ( V_4 , V_43 , V_74 ) ;
break;
case V_93 :
V_74 = F_10 ( V_4 , V_43 ) ;
V_74 &= ~ F_45 ( 3 ) ;
V_74 |= F_45 ( V_83 ) ;
F_9 ( V_4 , V_43 , V_74 ) ;
break;
case V_94 :
V_74 = F_10 ( V_4 , V_43 ) ;
V_74 |= F_46 ( V_83 ) ;
if ( V_83 == V_95 )
V_74 |= V_96 ;
F_9 ( V_4 , V_43 , V_74 ) ;
break;
default:
F_13 ( V_70 L_5 ) ;
V_84 = - V_73 ;
}
return V_84 ;
}
int F_47 ( int V_4 , int V_71 )
{
int V_97 = - V_73 ;
switch ( V_71 ) {
case V_98 :
V_97 = F_7 ( V_4 , V_99 ) ;
break;
default:
F_13 ( V_70 L_6 ) ;
}
return V_97 ;
}
int F_48 ( int V_4 , int V_71 , int V_83 )
{
int V_84 = 0 ;
switch ( V_71 ) {
case V_100 :
F_5 ( V_4 , V_101 , V_83 ) ;
break;
case V_102 :
F_5 ( V_4 , V_103 , V_83 ) ;
break;
case V_98 :
F_5 ( V_4 , V_99 , V_83 ) ;
default:
F_13 ( V_70 L_7 ) ;
V_84 = - V_73 ;
}
return V_84 ;
}
int F_49 ( int V_4 , int V_104 , int V_105 ,
unsigned int V_106 , int V_107 )
{
if ( V_104 > V_108 ) {
F_50 ( L_8 ) ;
return - 1 ;
} else if ( ! ( F_3 ( V_109 ) ) ) {
F_1 ( V_110 , V_106 ) ;
F_1 ( V_111 , ( ( V_4 << V_112 ) |
F_51 ( V_104 ) |
V_113 |
( V_105 << V_114 ) |
( 0x1 & V_107 ) ) ) ;
F_1 ( V_109 , 0x1 ) ;
} else {
return - V_68 ;
}
return 0 ;
}
int F_52 ( int V_4 )
{
T_1 V_115 ;
V_115 = F_3 ( V_111 ) ;
if ( ( ( V_115 >> V_112 ) & 0x7 ) != V_4 )
return - V_73 ;
F_1 ( V_109 , 0x0 ) ;
F_1 ( V_111 , 0x0 ) ;
return 0 ;
}
void F_53 ( struct V_116 * V_117 , int V_4 )
{
V_117 -> V_118 = V_3 + V_81 ;
V_117 -> V_119 = V_3 + V_6 +
V_101 + V_7 * V_4 ;
V_117 -> V_120 = V_3 + V_6 +
V_103 + V_7 * V_4 ;
V_117 -> V_121 = V_3 + V_6 +
V_99 + V_7 * V_4 ;
V_117 -> V_122 = V_3 + V_111 ;
V_117 -> V_123 = V_3 + V_110 ;
V_117 -> V_124 = V_3 + V_109 ;
V_117 -> V_125 = V_3 + V_78 ;
V_117 -> V_126 = V_3 + V_127 ;
V_117 -> V_128 = V_3 + V_129 ;
V_117 -> V_130 = V_3 + V_131 ;
V_117 -> V_132 = V_3 + V_133 ;
V_117 -> V_134 = V_3 + V_135 ;
}
int F_54 ( unsigned V_136 )
{
int V_137 ;
if ( F_55 ( V_136 ) > 1 )
return 0 ;
for ( V_137 = 0 ; V_137 < V_138 ; V_137 ++ )
if ( V_139 [ V_137 ] . V_140 & V_136 )
return V_139 [ V_137 ] . V_141 ;
return 0 ;
}
static int F_56 ( unsigned V_141 , bool V_142 )
{
int V_137 ;
T_1 V_74 ;
for ( V_137 = 0 ; V_137 < V_138 ; V_137 ++ )
if ( V_141 == V_139 [ V_137 ] . V_141 ) {
V_74 = F_3 ( V_86 ) ;
if ( V_142 )
V_74 |= V_139 [ V_137 ] . V_140 ;
else
V_74 &= ~ V_139 [ V_137 ] . V_140 ;
F_1 ( V_86 , V_74 ) ;
break;
}
return 0 ;
}
static void F_57 ( struct V_143 * V_144 )
{
F_56 ( V_144 -> V_141 , false ) ;
}
static void F_58 ( struct V_143 * V_144 )
{
F_56 ( V_144 -> V_141 , true ) ;
}
static void F_59 ( struct V_143 * V_145 ) { }
static unsigned int F_60 ( struct V_143 * V_145 ) { return 0 ; }
static int F_61 ( void )
{
int V_137 ;
T_1 V_74 ;
if ( ! V_146 )
return - V_73 ;
V_147 = F_62 ( - 1 , 0 , V_138 , 0 ) ;
if ( F_63 ( V_147 ) ) {
F_50 ( L_9 ) ;
return V_147 ;
}
V_148 . V_149 = L_10 ;
V_148 . V_150 = F_60 ;
V_148 . V_151 = F_58 ;
V_148 . V_152 = F_57 ;
V_148 . V_153 = F_59 ;
V_148 . V_154 = F_59 ;
V_148 . V_155 = F_59 ;
V_148 . V_156 = F_59 ;
V_139 [ 0 ] . V_140 = V_157 ;
V_139 [ 1 ] . V_140 = V_158 ;
for ( V_137 = 0 ; V_137 < V_138 ; V_137 ++ ) {
V_139 [ V_137 ] . V_141 = V_147 + V_137 ;
F_64 ( V_139 [ V_137 ] . V_141 ,
& V_148 , V_159 ) ;
F_65 ( V_139 [ V_137 ] . V_141 ,
V_160 | V_161 ) ;
}
F_1 ( V_86 , 0 ) ;
V_74 = F_3 ( V_76 ) ;
F_1 ( V_76 , V_74 ) ;
return F_66 ( V_146 , V_162 , 0 , L_10 , NULL ) ;
}
static T_4 int F_67 ( void )
{
int V_137 ;
if ( V_146 )
F_68 ( V_146 , NULL ) ;
for ( V_137 = 0 ; V_137 < V_138 ; V_137 ++ ) {
F_69 ( V_139 [ V_137 ] . V_141 , NULL ) ;
F_70 ( V_139 [ V_137 ] . V_141 , & V_163 ) ;
F_71 ( V_139 [ V_137 ] . V_141 , 0 , 0 ) ;
}
F_72 ( V_147 , V_138 ) ;
return 0 ;
}
static void T_4 F_73 ( void )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_55 ; V_4 ++ ) {
if ( ! F_25 ( V_4 ) )
continue;
F_33 ( V_4 ) ;
}
}
static int T_5 F_74 ( void )
{
int V_4 , V_164 ;
unsigned long V_165 = 0 ;
V_165 = V_166 ;
if ( F_75 () )
V_165 = 0 ;
V_66 . V_64 = V_167 + V_165 ;
V_66 . V_65 = V_168 ;
for ( V_4 = 0 ; V_4 < V_55 ; V_4 ++ ) {
T_1 V_47 , V_48 ;
if ( ! F_25 ( V_4 ) )
continue;
F_24 ( V_4 , & V_47 , & V_48 ) ;
V_164 = F_29 ( V_4 , V_47 , V_48 ) ;
if ( F_63 ( V_164 ) ) {
while ( -- V_4 >= 0 )
if ( F_25 ( V_4 ) )
F_33 ( V_4 ) ;
return V_164 ;
}
}
return 0 ;
}
static T_5 int F_76 ( struct V_169 * V_170 )
{
int V_164 ;
T_1 V_16 ;
struct V_59 * V_60 ;
V_60 = F_77 ( V_170 , V_171 , 0 ) ;
if ( V_60 == NULL )
return - V_172 ;
V_173 = V_60 -> V_64 ;
V_174 = F_38 ( V_60 ) ;
V_3 = F_78 ( & V_170 -> V_175 , V_60 ) ;
if ( ! V_3 ) {
F_79 ( & V_170 -> V_175 , L_11 ) ;
return - V_176 ;
}
V_60 = F_77 ( V_170 , V_177 , 0 ) ;
if ( V_60 == NULL )
F_80 ( & V_170 -> V_175 , L_12 ) ;
else
V_146 = V_60 -> V_64 ;
V_9 = F_81 ( & V_170 -> V_175 , L_13 ) ;
if ( F_82 ( V_9 ) ) {
F_79 ( & V_170 -> V_175 , L_14 ) ;
V_146 = 0 ;
return F_83 ( V_9 ) ;
}
F_84 ( V_9 ) ;
V_178 = & V_170 -> V_175 ;
V_16 = F_3 ( V_179 ) ;
if ( F_85 ( V_16 ) > 0x4 )
V_37 = V_41 | V_38 ;
F_86 ( V_178 , L_15 , F_85 ( V_16 ) ,
F_87 ( V_16 ) ) ;
V_164 = F_74 () ;
if ( F_63 ( V_164 ) ) {
F_88 ( V_9 ) ;
F_89 ( V_9 ) ;
F_79 ( V_178 , L_16 ) ;
return V_164 ;
}
if ( F_63 ( F_61 () ) )
F_80 ( V_178 , L_17 ) ;
return 0 ;
}
static T_4 int F_90 ( struct V_169 * V_170 )
{
F_67 () ;
F_73 () ;
V_178 = NULL ;
return 0 ;
}
static T_6 int F_91 ( void )
{
return F_92 ( & V_180 ) ;
}
static T_7 void F_93 ( void )
{
F_94 ( & V_180 ) ;
}
static int T_6 F_95 ( void )
{
struct V_181 * V_182 ;
struct V_169 * V_170 ;
char * V_183 = L_10 ;
V_182 = F_96 ( V_183 ) ;
if ( ! V_182 ) {
F_50 ( L_18 , V_183 ) ;
return - V_56 ;
}
V_170 = F_97 ( V_184 , - 1 , V_182 , NULL , 0 , NULL , 0 , 0 ) ;
F_98 ( F_82 ( V_170 ) , L_19 , V_183 ) ;
return F_82 ( V_170 ) ? F_83 ( V_170 ) : 0 ;
}
static T_8 V_162 ( int V_141 , void * V_175 )
{
int V_137 ;
T_1 V_74 ;
V_74 = F_3 ( V_76 ) ;
if ( ! V_74 )
return V_185 ;
for ( V_137 = 0 ; V_137 < V_138 ; V_137 ++ )
if ( V_74 & V_139 [ V_137 ] . V_140 )
F_99 ( V_139 [ V_137 ] . V_141 ) ;
F_1 ( V_76 , V_74 ) ;
return V_186 ;
}
void F_100 ( void )
{
int V_137 ;
V_187 . V_188 = F_3 ( V_189 ) ;
V_187 . V_190 = F_3 ( V_86 ) ;
V_187 . V_191 = F_3 ( V_192 ) ;
V_187 . V_193 = F_3 ( V_89 ) ;
V_187 . V_194 = F_3 ( V_111 ) ;
V_187 . V_195 = F_3 ( V_110 ) ;
V_187 . V_196 = F_3 ( V_109 ) ;
for ( V_137 = 0 ; V_137 < V_55 ; V_137 ++ ) {
V_187 . V_197 [ V_137 ] . V_198 = F_25 ( V_137 ) ;
if ( V_187 . V_197 [ V_137 ] . V_198 ) {
V_187 . V_197 [ V_137 ] . V_115 =
F_10 ( V_137 , V_43 ) ;
V_187 . V_197 [ V_137 ] . V_199 =
F_10 ( V_137 , V_19 ) ;
V_187 . V_197 [ V_137 ] . V_200 =
F_10 ( V_137 , V_23 ) ;
V_187 . V_197 [ V_137 ] . V_201 =
F_10 ( V_137 , V_27 ) ;
V_187 . V_197 [ V_137 ] . V_202 =
F_10 ( V_137 , V_32 ) ;
V_187 . V_197 [ V_137 ] . V_203 =
F_10 ( V_137 , V_39 ) ;
V_187 . V_197 [ V_137 ] . V_204 =
F_10 ( V_137 , V_51 ) ;
}
}
}
void F_101 ( void )
{
int V_137 ;
F_1 ( V_189 , V_187 . V_188 ) ;
F_1 ( V_86 , V_187 . V_190 ) ;
F_1 ( V_192 , V_187 . V_191 ) ;
F_1 ( V_89 , V_187 . V_193 ) ;
F_1 ( V_111 , V_187 . V_194 ) ;
F_1 ( V_110 , V_187 . V_195 ) ;
F_1 ( V_109 , V_187 . V_196 ) ;
for ( V_137 = 0 ; V_137 < V_55 ; V_137 ++ ) {
if ( V_187 . V_197 [ V_137 ] . V_198 ) {
F_9 ( V_137 , V_43 ,
V_187 . V_197 [ V_137 ] . V_115 ) ;
F_9 ( V_137 , V_19 ,
V_187 . V_197 [ V_137 ] . V_199 ) ;
F_9 ( V_137 , V_23 ,
V_187 . V_197 [ V_137 ] . V_200 ) ;
F_9 ( V_137 , V_27 ,
V_187 . V_197 [ V_137 ] . V_201 ) ;
F_9 ( V_137 , V_32 ,
V_187 . V_197 [ V_137 ] . V_202 ) ;
F_9 ( V_137 , V_39 ,
V_187 . V_197 [ V_137 ] . V_203 ) ;
F_9 ( V_137 , V_51 ,
V_187 . V_197 [ V_137 ] . V_204 ) ;
}
}
}
int F_102 ( int V_4 , int V_205 , int V_206 , int V_207 )
{
unsigned int V_2 ;
if ( V_208 != - V_73 )
return - V_73 ;
V_208 = V_4 ;
F_1 ( V_129 ,
V_209 |
V_210 ) ;
V_2 = ( ( ( ( V_207 >> 1 ) - 1 ) << 22 ) | ( 0x0000000F ) ) ;
F_1 ( V_131 , V_2 ) ;
switch ( V_205 ) {
case V_211 :
case V_212 :
F_1 ( V_129 ,
V_209 |
V_210 ) ;
break;
case V_213 :
F_1 ( V_129 ,
V_209 |
V_214 ) ;
break;
default:
F_13 ( V_46 L_20 , V_205 ) ;
break;
}
V_2 = ( V_206 << 7 ) | ( V_4 << 1 ) | ( 0x1 ) ;
F_1 ( V_127 , V_2 ) ;
return 0 ;
}
int F_103 ( int V_4 , const T_9 * V_215 , T_9 * V_216 )
{
unsigned int V_2 = 0x0 ;
if ( V_208 != V_4 )
return - V_73 ;
V_2 = F_3 ( V_133 ) ;
* V_216 ++ = V_2 ;
* V_216 ++ = V_2 >> 16 ;
* V_216 ++ = ( ( V_2 >> 8 ) & 0x0f ) | ( ( V_2 >> 20 ) & 0xf0 ) ;
V_208 = - V_73 ;
return 0 ;
}
int F_104 ( int V_4 , int V_217 , int V_218 )
{
if ( V_208 != - V_73 )
return - V_73 ;
if ( ! F_105 () ) {
F_13 ( V_70 L_21 ) ;
return - V_73 ;
}
if ( ( V_218 == 4 ) &&
( ! F_106 () || ( F_107 () == 0 ) ) ) {
F_13 ( V_70 L_22 ) ;
return - V_73 ;
}
if ( V_217 > 8 ) {
F_13 ( V_70 L_23 ,
V_217 ) ;
return - V_73 ;
}
return 0 ;
}
int F_108 ( int V_4 , int V_205 , int V_206 , int V_217 ,
int V_218 )
{
unsigned int V_2 ;
if ( V_208 != - V_73 )
return - V_73 ;
V_208 = V_4 ;
F_1 ( V_129 , 0x1 ) ;
F_1 ( V_131 , ( 32 << 22 ) | ( 0 << 12 ) ) ;
V_2 = ( ( 1 << 16 ) |
( ( ( V_218 == 8 ) ? 1 : 0 ) << 12 ) |
( 0x06 << 8 ) |
( V_206 << 7 ) |
( ( ( V_217 - 1 ) & 0x7 ) << 4 ) |
( V_4 << 1 ) |
( 0x1 ) ) ;
F_1 ( V_127 , V_2 ) ;
F_1 ( V_129 , 0x101 ) ;
return 0 ;
}
int F_109 ( int V_4 , const T_9 * V_215 , T_9 * V_219 )
{
int V_137 ;
unsigned long V_217 , V_117 , V_220 , V_221 ;
if ( V_208 != V_4 )
return - V_73 ;
V_217 = ( ( F_3 ( V_127 ) >> 4 ) & 0x7 ) + 1 ;
for ( V_137 = 0 ; V_137 < V_217 ; V_137 ++ ) {
V_117 = V_135 + 16 * V_137 ;
V_220 = F_3 ( V_117 + 0 ) ;
V_221 = F_3 ( V_117 + 4 ) ;
* V_219 ++ = 0x28 ^ ( ( V_221 >> 12 ) & 0xFF ) ;
* V_219 ++ = 0x13 ^ ( ( V_221 >> 4 ) & 0xFF ) ;
* V_219 ++ = 0xcc ^ ( ( ( V_221 & 0xF ) << 4 ) | ( ( V_220 >> 28 ) & 0xF ) ) ;
* V_219 ++ = 0x39 ^ ( ( V_220 >> 20 ) & 0xFF ) ;
* V_219 ++ = 0x96 ^ ( ( V_220 >> 12 ) & 0xFF ) ;
* V_219 ++ = 0xac ^ ( ( V_220 >> 4 ) & 0xFF ) ;
* V_219 ++ = 0x7f ^ ( ( V_220 & 0xF ) << 4 ) ;
}
V_208 = - V_73 ;
return 0 ;
}
int F_110 ( int V_4 , const T_9 * V_215 , T_9 * V_219 )
{
int V_137 ;
unsigned long V_217 , V_117 , V_220 , V_221 , V_222 , V_223 ;
if ( V_208 != V_4 )
return - V_73 ;
V_217 = ( ( F_3 ( V_127 ) >> 4 ) & 0x7 ) + 1 ;
for ( V_137 = 0 ; V_137 < V_217 ; V_137 ++ ) {
V_117 = V_135 + 16 * V_137 ;
V_220 = F_3 ( V_117 + 0 ) ;
V_221 = F_3 ( V_117 + 4 ) ;
V_222 = F_3 ( V_117 + 8 ) ;
V_223 = F_3 ( V_117 + 12 ) ;
* V_219 ++ = 0xef ^ ( V_223 & 0xFF ) ;
* V_219 ++ = 0x51 ^ ( ( V_222 >> 24 ) & 0xFF ) ;
* V_219 ++ = 0x2e ^ ( ( V_222 >> 16 ) & 0xFF ) ;
* V_219 ++ = 0x09 ^ ( ( V_222 >> 8 ) & 0xFF ) ;
* V_219 ++ = 0xed ^ ( V_222 & 0xFF ) ;
* V_219 ++ = 0x93 ^ ( ( V_221 >> 24 ) & 0xFF ) ;
* V_219 ++ = 0x9a ^ ( ( V_221 >> 16 ) & 0xFF ) ;
* V_219 ++ = 0xc2 ^ ( ( V_221 >> 8 ) & 0xFF ) ;
* V_219 ++ = 0x97 ^ ( V_221 & 0xFF ) ;
* V_219 ++ = 0x79 ^ ( ( V_220 >> 24 ) & 0xFF ) ;
* V_219 ++ = 0xe5 ^ ( ( V_220 >> 16 ) & 0xFF ) ;
* V_219 ++ = 0x24 ^ ( ( V_220 >> 8 ) & 0xFF ) ;
* V_219 ++ = 0xb5 ^ ( V_220 & 0xFF ) ;
}
V_208 = - V_73 ;
return 0 ;
}

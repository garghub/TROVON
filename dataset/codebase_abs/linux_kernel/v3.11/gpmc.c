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
static T_1 F_6 ( int V_4 , int V_1 )
{
void T_2 * V_5 ;
V_5 = V_3 + V_6 + ( V_4 * V_7 ) + V_1 ;
return F_4 ( V_5 ) ;
}
static unsigned long F_7 ( void )
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
static unsigned int F_10 ( unsigned int V_11 )
{
unsigned long V_12 ;
V_12 = F_7 () ;
return ( V_11 * 1000 + V_12 - 1 ) / V_12 ;
}
static unsigned int F_11 ( unsigned int V_13 )
{
unsigned long V_12 ;
V_12 = F_7 () ;
return ( V_13 + V_12 - 1 ) / V_12 ;
}
unsigned int F_12 ( unsigned int V_14 )
{
return V_14 * F_7 () / 1000 ;
}
static unsigned int F_13 ( unsigned int V_14 )
{
return V_14 * F_7 () ;
}
static unsigned int F_14 ( unsigned int V_13 )
{
unsigned long V_14 = F_11 ( V_13 ) ;
return V_14 * F_7 () ;
}
static inline void F_15 ( int V_4 , int V_15 , T_1 V_16 , bool V_17 )
{
T_1 V_18 ;
V_18 = F_6 ( V_4 , V_15 ) ;
if ( V_17 )
V_18 |= V_16 ;
else
V_18 &= ~ V_16 ;
F_5 ( V_4 , V_15 , V_18 ) ;
}
static void F_16 ( int V_4 , const struct V_19 * V_20 )
{
F_15 ( V_4 , V_21 ,
V_22 ,
V_20 -> V_23 ) ;
F_15 ( V_4 , V_24 ,
V_25 , V_20 -> V_26 ) ;
F_15 ( V_4 , V_27 ,
V_28 , V_20 -> V_29 ) ;
F_15 ( V_4 , V_30 ,
V_31 , V_20 -> V_32 ) ;
F_15 ( V_4 , V_30 ,
V_31 , V_20 -> V_33 ) ;
F_15 ( V_4 , V_34 ,
V_35 ,
V_20 -> V_36 ) ;
F_15 ( V_4 , V_34 ,
V_37 ,
V_20 -> V_38 ) ;
}
int F_17 ( unsigned int V_39 )
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
int F_18 ( int V_4 , const struct V_40 * V_41 )
{
int div ;
T_1 V_18 ;
div = F_17 ( V_41 -> V_39 ) ;
if ( div < 0 )
return div ;
F_19 ( V_24 , 0 , 3 , V_42 ) ;
F_19 ( V_24 , 8 , 12 , V_43 ) ;
F_19 ( V_24 , 16 , 20 , V_44 ) ;
F_19 ( V_27 , 0 , 3 , V_45 ) ;
F_19 ( V_27 , 8 , 12 , V_46 ) ;
F_19 ( V_27 , 16 , 20 , V_47 ) ;
F_19 ( V_30 , 0 , 3 , V_48 ) ;
F_19 ( V_30 , 8 , 12 , V_49 ) ;
F_19 ( V_30 , 16 , 19 , V_50 ) ;
F_19 ( V_30 , 24 , 28 , V_51 ) ;
F_19 ( V_52 , 0 , 4 , V_53 ) ;
F_19 ( V_52 , 8 , 12 , V_54 ) ;
F_19 ( V_52 , 16 , 20 , V_55 ) ;
F_19 ( V_52 , 24 , 27 , V_56 ) ;
F_19 ( V_34 , 0 , 3 , V_57 ) ;
F_19 ( V_34 , 8 , 11 , V_58 ) ;
F_19 ( V_21 , 18 , 19 , V_59 ) ;
F_19 ( V_21 , 25 , 26 , V_60 ) ;
if ( V_61 & V_62 )
F_19 ( V_34 , 16 , 19 , V_63 ) ;
if ( V_61 & V_64 )
F_19 ( V_34 , 24 , 28 , V_65 ) ;
V_18 = F_6 ( V_4 , V_21 ) ;
if ( V_18 & ( V_66 | V_67 ) ) {
#ifdef F_20
F_9 ( V_68 L_2 ,
V_4 , ( div * F_7 () ) / 1000 , div ) ;
#endif
V_18 &= ~ 0x03 ;
V_18 |= ( div - 1 ) ;
F_5 ( V_4 , V_21 , V_18 ) ;
}
F_16 ( V_4 , & V_41 -> V_69 ) ;
return 0 ;
}
static int F_21 ( int V_4 , T_1 V_70 , T_1 V_71 )
{
T_1 V_18 ;
T_1 V_16 ;
if ( V_70 & ( V_71 - 1 ) )
return - V_72 ;
V_16 = ( 1 << V_73 ) - V_71 ;
V_18 = F_6 ( V_4 , V_74 ) ;
V_18 &= ~ 0x3f ;
V_18 = ( V_70 >> V_75 ) & 0x3f ;
V_18 &= ~ ( 0x0f << 8 ) ;
V_18 |= ( ( V_16 >> V_75 ) & 0x0f ) << 8 ;
V_18 |= V_76 ;
F_5 ( V_4 , V_74 , V_18 ) ;
return 0 ;
}
static void F_22 ( int V_4 )
{
T_1 V_18 ;
V_18 = F_6 ( V_4 , V_74 ) ;
V_18 &= ~ V_76 ;
F_5 ( V_4 , V_74 , V_18 ) ;
}
static void F_23 ( int V_4 , T_1 * V_70 , T_1 * V_71 )
{
T_1 V_18 ;
T_1 V_16 ;
V_18 = F_6 ( V_4 , V_74 ) ;
* V_70 = ( V_18 & 0x3f ) << V_75 ;
V_16 = ( V_18 >> 8 ) & 0x0f ;
* V_71 = ( 1 << V_73 ) - ( V_16 << V_75 ) ;
}
static int F_24 ( int V_4 )
{
T_1 V_18 ;
V_18 = F_6 ( V_4 , V_74 ) ;
return V_18 & V_76 ;
}
static void F_25 ( int V_4 , int V_77 )
{
V_78 &= ~ ( 1 << V_4 ) ;
V_78 |= ( V_77 ? 1 : 0 ) << V_4 ;
}
static bool F_26 ( int V_4 )
{
return V_78 & ( 1 << V_4 ) ;
}
static unsigned long F_27 ( unsigned long V_71 )
{
int V_79 ;
V_71 = ( V_71 - 1 ) >> ( V_75 - 1 ) ;
V_79 = V_75 - 1 ;
do {
V_71 >>= 1 ;
V_79 ++ ;
} while ( V_71 );
V_71 = 1 << V_79 ;
return V_71 ;
}
static int F_28 ( int V_4 , unsigned long V_70 , unsigned long V_71 )
{
struct V_80 * V_81 = & V_82 [ V_4 ] ;
int V_83 ;
V_71 = F_27 ( V_71 ) ;
F_29 ( & V_84 ) ;
V_81 -> V_85 = V_70 ;
V_81 -> V_86 = V_70 + V_71 - 1 ;
V_83 = F_30 ( & V_87 , V_81 ) ;
F_31 ( & V_84 ) ;
return V_83 ;
}
static int F_32 ( int V_4 )
{
struct V_80 * V_81 = & V_82 [ V_4 ] ;
int V_83 ;
F_29 ( & V_84 ) ;
V_83 = F_33 ( & V_82 [ V_4 ] ) ;
V_81 -> V_85 = 0 ;
V_81 -> V_86 = 0 ;
F_31 ( & V_84 ) ;
return V_83 ;
}
static int F_34 ( int V_4 , T_1 V_70 )
{
int V_88 ;
T_1 V_89 , V_71 ;
if ( V_4 > V_90 ) {
F_35 ( L_3 , V_91 ) ;
return - V_92 ;
}
F_23 ( V_4 , & V_89 , & V_71 ) ;
if ( V_70 == V_89 )
return 0 ;
F_22 ( V_4 ) ;
V_88 = F_32 ( V_4 ) ;
if ( V_88 < 0 )
return V_88 ;
V_88 = F_28 ( V_4 , V_70 , V_71 ) ;
if ( V_88 < 0 )
return V_88 ;
V_88 = F_21 ( V_4 , V_70 , V_71 ) ;
if ( V_88 < 0 )
return V_88 ;
return 0 ;
}
int F_36 ( int V_4 , unsigned long V_71 , unsigned long * V_70 )
{
struct V_80 * V_81 = & V_82 [ V_4 ] ;
int V_83 = - 1 ;
if ( V_4 > V_90 ) {
F_35 ( L_3 , V_91 ) ;
return - V_92 ;
}
V_71 = F_27 ( V_71 ) ;
if ( V_71 > ( 1 << V_73 ) )
return - V_93 ;
F_29 ( & V_84 ) ;
if ( F_26 ( V_4 ) ) {
V_83 = - V_94 ;
goto V_95;
}
if ( F_24 ( V_4 ) )
V_83 = F_37 ( V_81 , V_81 -> V_85 & ~ ( V_71 - 1 ) , V_71 ) ;
if ( V_83 < 0 )
V_83 = F_38 ( & V_87 , V_81 , V_71 , 0 , ~ 0 ,
V_71 , NULL , NULL ) ;
if ( V_83 < 0 )
goto V_95;
V_83 = F_21 ( V_4 , V_81 -> V_85 , F_39 ( V_81 ) ) ;
if ( V_83 < 0 ) {
F_33 ( V_81 ) ;
goto V_95;
}
* V_70 = V_81 -> V_85 ;
F_25 ( V_4 , 1 ) ;
V_95:
F_31 ( & V_84 ) ;
return V_83 ;
}
void F_40 ( int V_4 )
{
F_29 ( & V_84 ) ;
if ( V_4 >= V_90 || V_4 < 0 || ! F_26 ( V_4 ) ) {
F_9 ( V_96 L_4 , V_4 ) ;
F_41 () ;
F_31 ( & V_84 ) ;
return;
}
F_22 ( V_4 ) ;
F_33 ( & V_82 [ V_4 ] ) ;
F_25 ( V_4 , 0 ) ;
F_31 ( & V_84 ) ;
}
int F_42 ( int V_97 , int V_98 )
{
T_1 V_99 ;
switch ( V_97 ) {
case V_100 :
F_1 ( V_101 , V_98 ) ;
break;
case V_102 :
F_1 ( V_103 , V_98 ) ;
break;
case V_104 :
V_99 = F_3 ( V_105 ) ;
if ( V_98 )
V_99 &= ~ V_106 ;
else
V_99 |= V_106 ;
F_1 ( V_105 , V_99 ) ;
break;
default:
F_35 ( L_5 , V_91 ) ;
return - V_72 ;
}
return 0 ;
}
void F_43 ( struct V_107 * V_15 , int V_4 )
{
int V_108 ;
V_15 -> V_109 = V_3 + V_110 ;
V_15 -> V_111 = V_3 + V_6 +
V_112 + V_7 * V_4 ;
V_15 -> V_113 = V_3 + V_6 +
V_114 + V_7 * V_4 ;
V_15 -> V_115 = V_3 + V_6 +
V_116 + V_7 * V_4 ;
V_15 -> V_117 = V_3 + V_118 ;
V_15 -> V_119 = V_3 + V_120 ;
V_15 -> V_121 = V_3 + V_122 ;
V_15 -> V_123 = V_3 + V_124 ;
V_15 -> V_125 = V_3 + V_126 ;
V_15 -> V_127 = V_3 + V_128 ;
V_15 -> V_129 = V_3 + V_130 ;
V_15 -> V_131 = V_3 + V_132 ;
for ( V_108 = 0 ; V_108 < V_133 ; V_108 ++ ) {
V_15 -> V_134 [ V_108 ] = V_3 + V_135 +
V_136 * V_108 ;
V_15 -> V_137 [ V_108 ] = V_3 + V_138 +
V_136 * V_108 ;
V_15 -> V_139 [ V_108 ] = V_3 + V_140 +
V_136 * V_108 ;
V_15 -> V_141 [ V_108 ] = V_3 + V_142 +
V_136 * V_108 ;
}
}
int F_44 ( unsigned V_143 )
{
int V_108 ;
if ( F_45 ( V_143 ) > 1 )
return 0 ;
for ( V_108 = 0 ; V_108 < V_144 ; V_108 ++ )
if ( V_145 [ V_108 ] . V_146 & V_143 )
return V_145 [ V_108 ] . V_147 ;
return 0 ;
}
static int F_46 ( unsigned V_147 , bool V_148 )
{
int V_108 ;
T_1 V_99 ;
for ( V_108 = 0 ; V_108 < V_144 ; V_108 ++ )
if ( V_147 == V_145 [ V_108 ] . V_147 ) {
V_99 = F_3 ( V_101 ) ;
if ( V_148 )
V_99 |= V_145 [ V_108 ] . V_146 ;
else
V_99 &= ~ V_145 [ V_108 ] . V_146 ;
F_1 ( V_101 , V_99 ) ;
break;
}
return 0 ;
}
static void F_47 ( struct V_149 * V_20 )
{
F_46 ( V_20 -> V_147 , false ) ;
}
static void F_48 ( struct V_149 * V_20 )
{
F_46 ( V_20 -> V_147 , true ) ;
}
static void F_49 ( struct V_149 * V_150 ) { }
static unsigned int F_50 ( struct V_149 * V_150 ) { return 0 ; }
static int F_51 ( void )
{
int V_108 ;
T_1 V_99 ;
if ( ! V_151 )
return - V_72 ;
V_152 = F_52 ( - 1 , 0 , V_144 , 0 ) ;
if ( V_152 < 0 ) {
F_35 ( L_6 ) ;
return V_152 ;
}
V_153 . V_154 = L_7 ;
V_153 . V_155 = F_50 ;
V_153 . V_156 = F_48 ;
V_153 . V_157 = F_47 ;
V_153 . V_158 = F_49 ;
V_153 . V_159 = F_49 ;
V_153 . V_160 = F_49 ;
V_153 . V_161 = F_49 ;
V_145 [ 0 ] . V_146 = V_162 ;
V_145 [ 1 ] . V_146 = V_163 ;
for ( V_108 = 0 ; V_108 < V_144 ; V_108 ++ ) {
V_145 [ V_108 ] . V_147 = V_152 + V_108 ;
F_53 ( V_145 [ V_108 ] . V_147 ,
& V_153 , V_164 ) ;
F_54 ( V_145 [ V_108 ] . V_147 ,
V_165 | V_166 ) ;
}
F_1 ( V_101 , 0 ) ;
V_99 = F_3 ( V_103 ) ;
F_1 ( V_103 , V_99 ) ;
return F_55 ( V_151 , V_167 , 0 , L_7 , NULL ) ;
}
static int F_56 ( void )
{
int V_108 ;
if ( V_151 )
F_57 ( V_151 , NULL ) ;
for ( V_108 = 0 ; V_108 < V_144 ; V_108 ++ ) {
F_58 ( V_145 [ V_108 ] . V_147 , NULL ) ;
F_59 ( V_145 [ V_108 ] . V_147 , & V_168 ) ;
F_60 ( V_145 [ V_108 ] . V_147 , 0 , 0 ) ;
}
F_61 ( V_152 , V_144 ) ;
return 0 ;
}
static void F_62 ( void )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_90 ; V_4 ++ ) {
if ( ! F_24 ( V_4 ) )
continue;
F_32 ( V_4 ) ;
}
}
static void F_63 ( void )
{
int V_4 ;
V_87 . V_85 = V_169 ;
V_87 . V_86 = V_170 ;
for ( V_4 = 0 ; V_4 < V_90 ; V_4 ++ ) {
T_1 V_70 , V_71 ;
if ( ! F_24 ( V_4 ) )
continue;
F_23 ( V_4 , & V_70 , & V_71 ) ;
if ( F_28 ( V_4 , V_70 , V_71 ) ) {
F_64 ( L_8 ,
V_91 , V_4 , V_70 , V_70 + V_71 ) ;
F_22 ( V_4 ) ;
}
}
}
static T_1 F_65 ( T_1 V_13 , T_1 V_39 )
{
T_1 V_171 ;
int div ;
div = F_17 ( V_39 ) ;
V_171 = F_11 ( V_13 ) ;
V_171 = ( V_171 + div - 1 ) / div ;
return F_13 ( V_171 * div ) ;
}
static int F_66 ( struct V_40 * V_172 ,
struct V_173 * V_174 ,
bool V_175 )
{
T_1 V_171 ;
V_171 = V_174 -> V_176 ;
if ( V_175 ) {
V_171 = F_67 ( T_1 , V_171 , V_172 -> V_60 + V_174 -> V_177 ) ;
V_171 = F_67 ( T_1 , V_172 -> V_45 + F_13 ( 1 ) , V_171 ) ;
}
V_172 -> V_46 = F_14 ( V_171 ) ;
V_171 = V_174 -> V_178 ;
if ( V_175 ) {
V_171 = F_67 ( T_1 , V_171 , V_172 -> V_60 + V_174 -> V_179 ) ;
V_171 = F_67 ( T_1 , V_171 , V_172 -> V_46 +
F_13 ( V_174 -> V_180 ) ) ;
}
V_172 -> V_48 = F_14 ( V_171 ) ;
V_171 = F_67 ( T_1 , V_174 -> V_181 , V_174 -> V_182 * V_172 -> V_39 ) ;
V_171 += V_172 -> V_60 ;
if ( V_174 -> V_183 )
V_171 = F_67 ( T_1 , V_171 , V_172 -> V_48 +
F_13 ( V_174 -> V_183 ) ) ;
V_172 -> V_55 = F_14 ( V_171 ) ;
V_172 -> V_49 = V_172 -> V_55 + F_13 ( 1 ) ;
V_172 -> V_43 = V_172 -> V_49 ;
V_171 = F_67 ( T_1 , V_174 -> V_184 , V_174 -> V_185 ) ;
V_171 = F_65 ( V_171 , V_172 -> V_39 ) +
V_172 -> V_55 ;
if ( V_174 -> V_186 )
V_171 = F_67 ( T_1 , V_171 , V_172 -> V_43 + V_174 -> V_186 ) ;
V_172 -> V_53 = F_14 ( V_171 ) ;
return 0 ;
}
static int F_68 ( struct V_40 * V_172 ,
struct V_173 * V_174 ,
bool V_175 )
{
T_1 V_171 ;
V_171 = V_174 -> V_187 ;
if ( V_175 ) {
V_171 = F_67 ( T_1 , V_171 ,
V_172 -> V_60 + V_174 -> V_177 ) ;
V_171 = F_67 ( T_1 , V_172 -> V_45 + F_13 ( 1 ) , V_171 ) ;
}
V_172 -> V_47 = F_14 ( V_171 ) ;
V_171 = F_67 ( T_1 , V_174 -> V_188 ,
V_172 -> V_60 + V_174 -> V_189 ) ;
if ( V_175 ) {
V_171 = F_67 ( T_1 , V_171 ,
V_172 -> V_47 + V_174 -> V_190 ) ;
V_171 = F_67 ( T_1 , V_171 , V_172 -> V_47 +
F_13 ( V_174 -> V_191 ) ) ;
}
V_172 -> V_63 = F_14 ( V_171 ) ;
if ( V_61 & V_62 )
V_172 -> V_50 = F_14 ( V_174 -> V_188 ) ;
else
V_172 -> V_50 = V_172 -> V_63 ;
V_172 -> V_65 = V_172 -> V_55 ;
V_171 = V_172 -> V_50 + V_174 -> V_192 ;
V_171 = F_67 ( T_1 , V_171 ,
V_172 -> V_65 + F_13 ( 1 ) ) ;
V_171 = F_67 ( T_1 , V_171 ,
V_172 -> V_50 + F_13 ( V_174 -> V_193 ) ) ;
V_172 -> V_51 = F_14 ( V_171 ) ;
V_172 -> V_44 = F_14 ( V_172 -> V_51 +
V_174 -> V_194 ) ;
V_171 = F_65 ( V_174 -> V_195 , V_172 -> V_39 ) ;
V_171 += V_172 -> V_65 ;
if ( V_174 -> V_186 )
V_171 = F_67 ( T_1 , V_171 ,
V_172 -> V_44 + V_174 -> V_186 ) ;
V_172 -> V_54 = F_14 ( V_171 ) ;
return 0 ;
}
static int F_69 ( struct V_40 * V_172 ,
struct V_173 * V_174 ,
bool V_175 )
{
T_1 V_171 ;
V_171 = V_174 -> V_176 ;
if ( V_175 )
V_171 = F_67 ( T_1 , V_172 -> V_45 + F_13 ( 1 ) , V_171 ) ;
V_172 -> V_46 = F_14 ( V_171 ) ;
V_171 = V_174 -> V_178 ;
if ( V_175 )
V_171 = F_67 ( T_1 , V_171 ,
V_172 -> V_46 + V_174 -> V_190 ) ;
V_172 -> V_48 = F_14 ( V_171 ) ;
V_171 = F_67 ( T_1 , V_174 -> V_181 ,
V_172 -> V_48 + V_174 -> V_196 ) ;
V_171 = F_67 ( T_1 , V_171 ,
V_172 -> V_42 + V_174 -> V_197 ) ;
V_171 = F_67 ( T_1 , V_171 ,
V_172 -> V_45 + V_174 -> V_198 ) ;
V_172 -> V_55 = F_14 ( V_171 ) ;
V_172 -> V_49 = V_172 -> V_55 + F_13 ( 1 ) ;
V_172 -> V_43 = V_172 -> V_49 ;
V_171 = F_67 ( T_1 , V_174 -> V_199 ,
V_172 -> V_43 + V_174 -> V_184 ) ;
V_171 = F_67 ( T_1 , V_171 , V_172 -> V_49 + V_174 -> V_185 ) ;
V_172 -> V_53 = F_14 ( V_171 ) ;
return 0 ;
}
static int F_70 ( struct V_40 * V_172 ,
struct V_173 * V_174 ,
bool V_175 )
{
T_1 V_171 ;
V_171 = V_174 -> V_187 ;
if ( V_175 )
V_171 = F_67 ( T_1 , V_172 -> V_45 + F_13 ( 1 ) , V_171 ) ;
V_172 -> V_47 = F_14 ( V_171 ) ;
V_171 = V_174 -> V_188 ;
if ( V_175 ) {
V_171 = F_67 ( T_1 , V_171 , V_172 -> V_47 + V_174 -> V_190 ) ;
V_171 = F_67 ( T_1 , V_171 , V_172 -> V_47 +
F_13 ( V_174 -> V_191 ) ) ;
}
V_172 -> V_63 = F_14 ( V_171 ) ;
if ( V_61 & V_62 )
V_172 -> V_50 = F_14 ( V_174 -> V_188 ) ;
else
V_172 -> V_50 = V_172 -> V_63 ;
V_171 = V_172 -> V_50 + V_174 -> V_192 ;
V_172 -> V_51 = F_14 ( V_171 ) ;
V_172 -> V_44 = F_14 ( V_172 -> V_51 +
V_174 -> V_194 ) ;
V_171 = F_67 ( T_1 , V_174 -> V_200 ,
V_172 -> V_44 + V_174 -> V_195 ) ;
V_172 -> V_54 = F_14 ( V_171 ) ;
return 0 ;
}
static int F_71 ( struct V_40 * V_172 ,
struct V_173 * V_174 )
{
T_1 V_171 ;
V_172 -> V_39 = F_17 ( V_174 -> V_201 ) *
F_7 () ;
V_172 -> V_56 = F_65 (
V_174 -> V_202 ,
V_172 -> V_39 ) ;
V_171 = F_67 ( T_1 , V_174 -> V_203 , V_174 -> V_204 ) ;
V_172 -> V_60 = F_14 ( V_171 ) ;
if ( F_17 ( V_172 -> V_39 ) != 1 )
return 0 ;
if ( V_174 -> V_205 )
V_172 -> V_69 . V_26 = true ;
if ( V_174 -> V_206 )
V_172 -> V_69 . V_29 = true ;
if ( V_174 -> V_207 )
V_172 -> V_69 . V_32 = true ;
if ( V_174 -> V_208 )
V_172 -> V_69 . V_33 = true ;
return 0 ;
}
static int F_72 ( struct V_40 * V_172 ,
struct V_173 * V_174 ,
bool V_209 )
{
T_1 V_171 ;
V_172 -> V_42 = F_14 ( V_174 -> V_210 ) ;
V_171 = V_174 -> V_211 ;
if ( V_174 -> V_212 )
V_171 = F_67 ( T_1 , V_171 ,
V_172 -> V_42 + V_174 -> V_212 ) ;
V_172 -> V_45 = F_14 ( V_171 ) ;
if ( V_209 )
F_71 ( V_172 , V_174 ) ;
return 0 ;
}
static void F_73 ( struct V_40 * V_41 )
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
int F_74 ( struct V_40 * V_172 ,
struct V_213 * V_214 ,
struct V_173 * V_174 )
{
bool V_175 = false , V_209 = false ;
if ( V_214 ) {
V_175 = V_214 -> V_215 ? true : false ;
V_209 = ( V_214 -> V_216 || V_214 -> V_217 ) ;
}
memset ( V_172 , 0 , sizeof( * V_172 ) ) ;
F_72 ( V_172 , V_174 , V_209 ) ;
if ( V_214 && V_214 -> V_216 )
F_66 ( V_172 , V_174 , V_175 ) ;
else
F_69 ( V_172 , V_174 , V_175 ) ;
if ( V_214 && V_214 -> V_217 )
F_68 ( V_172 , V_174 , V_175 ) ;
else
F_70 ( V_172 , V_174 , V_175 ) ;
F_73 ( V_172 ) ;
return 0 ;
}
int F_75 ( int V_4 , struct V_213 * V_20 )
{
T_1 V_218 ;
if ( ( ! V_20 -> V_219 ) || ( V_20 -> V_219 > V_220 ) ) {
F_35 ( L_9 , V_91 , V_20 -> V_219 ) ;
return - V_72 ;
}
if ( V_20 -> V_221 && V_20 -> V_215 ) {
F_35 ( L_10 , V_91 ) ;
return - V_72 ;
}
if ( ( V_20 -> V_215 > V_222 ) ||
( ( V_20 -> V_215 == V_223 ) &&
! ( V_61 & V_224 ) ) ) {
F_35 ( L_11 , V_91 ) ;
return - V_72 ;
}
if ( V_20 -> V_225 || V_20 -> V_226 ) {
switch ( V_20 -> V_227 ) {
case V_228 :
case V_229 :
case V_230 :
break;
default:
F_35 ( L_12 ,
V_91 , V_20 -> V_227 ) ;
return - V_72 ;
}
}
if ( ( V_20 -> V_231 || V_20 -> V_232 ) &&
( V_20 -> V_233 > V_234 ) ) {
F_35 ( L_13 , V_91 , V_20 -> V_233 ) ;
return - V_72 ;
}
V_218 = F_76 ( ( V_20 -> V_219 - 1 ) ) ;
if ( V_20 -> V_216 )
V_218 |= V_66 ;
if ( V_20 -> V_217 )
V_218 |= V_67 ;
if ( V_20 -> V_231 )
V_218 |= V_235 ;
if ( V_20 -> V_232 )
V_218 |= V_236 ;
if ( V_20 -> V_231 || V_20 -> V_232 )
V_218 |= F_77 ( V_20 -> V_233 ) ;
if ( V_20 -> V_221 )
V_218 |= F_78 ( V_237 ) ;
if ( V_20 -> V_215 )
V_218 |= F_79 ( V_20 -> V_215 ) ;
if ( V_20 -> V_225 )
V_218 |= V_238 ;
if ( V_20 -> V_226 )
V_218 |= V_239 ;
if ( V_20 -> V_225 || V_20 -> V_226 ) {
V_218 |= F_80 ( V_20 -> V_227 >> 3 ) ;
V_218 |= V_20 -> V_240 ? V_241 : 0 ;
}
F_5 ( V_4 , V_21 , V_218 ) ;
return 0 ;
}
void F_81 ( struct V_242 * V_243 , struct V_213 * V_20 )
{
memset ( V_20 , 0 , sizeof( struct V_213 ) ) ;
V_20 -> V_216 = F_82 ( V_243 , L_14 ) ;
V_20 -> V_217 = F_82 ( V_243 , L_15 ) ;
F_83 ( V_243 , L_16 , & V_20 -> V_219 ) ;
F_83 ( V_243 , L_17 , & V_20 -> V_215 ) ;
if ( ! F_83 ( V_243 , L_18 , & V_20 -> V_227 ) ) {
V_20 -> V_240 = F_82 ( V_243 , L_19 ) ;
V_20 -> V_225 = F_82 ( V_243 , L_20 ) ;
V_20 -> V_226 = F_82 ( V_243 , L_21 ) ;
if ( ! V_20 -> V_225 && ! V_20 -> V_226 )
F_64 ( L_22 ,
V_91 ) ;
}
if ( ! F_83 ( V_243 , L_23 , & V_20 -> V_233 ) ) {
V_20 -> V_231 = F_82 ( V_243 ,
L_24 ) ;
V_20 -> V_232 = F_82 ( V_243 ,
L_25 ) ;
if ( ! V_20 -> V_231 && ! V_20 -> V_232 )
F_64 ( L_26 ,
V_91 ) ;
}
}
static void T_3 F_84 ( struct V_242 * V_243 ,
struct V_40 * V_172 )
{
struct V_19 * V_20 ;
if ( ! V_243 || ! V_172 )
return;
memset ( V_172 , 0 , sizeof( * V_172 ) ) ;
F_83 ( V_243 , L_27 , & V_172 -> V_39 ) ;
F_83 ( V_243 , L_28 , & V_172 -> V_42 ) ;
F_83 ( V_243 , L_29 , & V_172 -> V_43 ) ;
F_83 ( V_243 , L_30 , & V_172 -> V_44 ) ;
F_83 ( V_243 , L_31 , & V_172 -> V_45 ) ;
F_83 ( V_243 , L_32 , & V_172 -> V_46 ) ;
F_83 ( V_243 , L_33 , & V_172 -> V_47 ) ;
F_83 ( V_243 , L_34 , & V_172 -> V_50 ) ;
F_83 ( V_243 , L_35 , & V_172 -> V_51 ) ;
F_83 ( V_243 , L_36 , & V_172 -> V_48 ) ;
F_83 ( V_243 , L_37 , & V_172 -> V_49 ) ;
F_83 ( V_243 , L_38 ,
& V_172 -> V_56 ) ;
F_83 ( V_243 , L_39 , & V_172 -> V_55 ) ;
F_83 ( V_243 , L_40 , & V_172 -> V_53 ) ;
F_83 ( V_243 , L_41 , & V_172 -> V_54 ) ;
F_83 ( V_243 , L_42 ,
& V_172 -> V_57 ) ;
F_83 ( V_243 , L_43 ,
& V_172 -> V_58 ) ;
F_83 ( V_243 , L_44 ,
& V_172 -> V_59 ) ;
F_83 ( V_243 , L_45 ,
& V_172 -> V_60 ) ;
F_83 ( V_243 , L_46 , & V_172 -> V_65 ) ;
F_83 ( V_243 , L_47 ,
& V_172 -> V_63 ) ;
V_20 = & V_172 -> V_69 ;
V_20 -> V_38 =
F_82 ( V_243 , L_48 ) ;
V_20 -> V_36 =
F_82 ( V_243 , L_49 ) ;
V_20 -> V_33 = F_82 ( V_243 , L_50 ) ;
V_20 -> V_32 = F_82 ( V_243 , L_51 ) ;
V_20 -> V_29 = F_82 ( V_243 , L_52 ) ;
V_20 -> V_26 = F_82 ( V_243 , L_53 ) ;
V_20 -> V_23 =
F_82 ( V_243 , L_54 ) ;
}
static int F_85 ( struct V_244 * V_245 ,
struct V_242 * V_246 )
{
T_1 V_2 ;
const char * V_247 ;
struct V_40 V_172 ;
struct V_248 * V_115 ;
if ( F_83 ( V_246 , L_55 , & V_2 ) < 0 ) {
F_86 ( & V_245 -> V_249 , L_56 ,
V_246 -> V_250 ) ;
return - V_92 ;
}
V_115 = F_87 ( & V_245 -> V_249 , sizeof( * V_115 ) ,
V_251 ) ;
if ( ! V_115 )
return - V_93 ;
V_115 -> V_4 = V_2 ;
V_115 -> V_252 = V_246 ;
if ( ! F_88 ( V_246 , L_57 , & V_247 ) )
for ( V_2 = 0 ; V_2 < F_89 ( V_253 ) ; V_2 ++ )
if ( ! strcasecmp ( V_247 , V_253 [ V_2 ] ) ) {
V_115 -> V_254 = V_2 ;
break;
}
if ( ! F_88 ( V_246 , L_58 , & V_247 ) )
for ( V_2 = 0 ; V_2 < F_89 ( V_255 ) ; V_2 ++ )
if ( ! strcasecmp ( V_247 , V_255 [ V_2 ] ) ) {
V_115 -> V_256 = V_2 ;
break;
}
V_2 = F_90 ( V_246 ) ;
if ( V_2 == 16 )
V_115 -> V_257 = V_258 ;
F_84 ( V_246 , & V_172 ) ;
F_91 ( V_115 , & V_172 ) ;
return 0 ;
}
static int F_85 ( struct V_244 * V_245 ,
struct V_242 * V_246 )
{
return 0 ;
}
static int F_92 ( struct V_244 * V_245 ,
struct V_242 * V_246 )
{
T_1 V_2 ;
struct V_259 * V_260 ;
if ( F_83 ( V_246 , L_55 , & V_2 ) < 0 ) {
F_86 ( & V_245 -> V_249 , L_56 ,
V_246 -> V_250 ) ;
return - V_92 ;
}
V_260 = F_87 ( & V_245 -> V_249 , sizeof( * V_260 ) ,
V_251 ) ;
if ( ! V_260 )
return - V_93 ;
V_260 -> V_4 = V_2 ;
V_260 -> V_252 = V_246 ;
V_260 -> V_261 = - 1 ;
if ( ! F_83 ( V_246 , L_59 , & V_2 ) )
V_260 -> V_261 = V_2 ;
F_93 ( V_260 ) ;
return 0 ;
}
static int F_92 ( struct V_244 * V_245 ,
struct V_242 * V_246 )
{
return 0 ;
}
static int F_94 ( struct V_244 * V_245 ,
struct V_242 * V_246 )
{
struct V_213 V_214 ;
struct V_40 V_172 ;
struct V_80 V_81 ;
unsigned long V_70 ;
int V_88 , V_4 ;
if ( F_83 ( V_246 , L_55 , & V_4 ) < 0 ) {
F_86 ( & V_245 -> V_249 , L_56 ,
V_246 -> V_250 ) ;
return - V_92 ;
}
if ( F_95 ( V_246 , 0 , & V_81 ) < 0 ) {
F_86 ( & V_245 -> V_249 , L_60 ,
V_246 -> V_250 ) ;
return - V_92 ;
}
V_88 = F_36 ( V_4 , F_39 ( & V_81 ) , & V_70 ) ;
if ( V_88 < 0 ) {
F_86 ( & V_245 -> V_249 , L_61 , V_4 ) ;
return V_88 ;
}
V_88 = F_34 ( V_4 , V_81 . V_85 ) ;
if ( V_88 < 0 ) {
F_86 ( & V_245 -> V_249 , L_62 ,
V_4 , V_81 . V_85 ) ;
goto V_262;
}
F_81 ( V_246 , & V_214 ) ;
V_88 = F_83 ( V_246 , L_63 , & V_214 . V_219 ) ;
if ( V_88 < 0 )
goto V_262;
V_88 = F_75 ( V_4 , & V_214 ) ;
if ( V_88 < 0 )
goto V_262;
F_84 ( V_246 , & V_172 ) ;
F_18 ( V_4 , & V_172 ) ;
if ( F_96 ( V_246 , NULL , & V_245 -> V_249 ) )
return 0 ;
F_86 ( & V_245 -> V_249 , L_64 , V_246 -> V_154 ) ;
V_88 = - V_92 ;
V_262:
F_40 ( V_4 ) ;
return V_88 ;
}
static int F_97 ( struct V_244 * V_245 )
{
int V_88 ;
struct V_242 * V_246 ;
const struct V_263 * V_264 =
F_98 ( V_265 , & V_245 -> V_249 ) ;
if ( ! V_264 )
return 0 ;
V_88 = F_83 ( V_245 -> V_249 . V_252 , L_65 ,
& V_90 ) ;
if ( V_88 < 0 ) {
F_35 ( L_66 , V_91 ) ;
return V_88 ;
} else if ( V_90 < 1 ) {
F_35 ( L_67 , V_91 ) ;
return - V_72 ;
} else if ( V_90 > V_266 ) {
F_35 ( L_68 ,
V_91 , V_266 ) ;
return - V_72 ;
}
V_88 = F_83 ( V_245 -> V_249 . V_252 , L_69 ,
& V_234 ) ;
if ( V_88 < 0 ) {
F_35 ( L_70 , V_91 ) ;
return V_88 ;
}
F_99 (pdev->dev.of_node, child) {
if ( ! V_246 -> V_154 )
continue;
if ( F_100 ( V_246 -> V_154 , L_71 ) == 0 )
V_88 = F_85 ( V_245 , V_246 ) ;
else if ( F_100 ( V_246 -> V_154 , L_72 ) == 0 )
V_88 = F_92 ( V_245 , V_246 ) ;
else if ( F_100 ( V_246 -> V_154 , L_73 ) == 0 ||
F_100 ( V_246 -> V_154 , L_74 ) == 0 )
V_88 = F_94 ( V_245 , V_246 ) ;
if ( F_101 ( V_88 < 0 , L_75 ,
V_91 , V_246 -> V_250 ) )
F_102 ( V_246 ) ;
}
return 0 ;
}
static int F_97 ( struct V_244 * V_245 )
{
return 0 ;
}
static int F_103 ( struct V_244 * V_245 )
{
int V_267 ;
T_1 V_18 ;
struct V_80 * V_81 ;
V_81 = F_104 ( V_245 , V_268 , 0 ) ;
if ( V_81 == NULL )
return - V_269 ;
V_270 = V_81 -> V_85 ;
V_271 = F_39 ( V_81 ) ;
V_3 = F_105 ( & V_245 -> V_249 , V_81 ) ;
if ( F_106 ( V_3 ) )
return F_107 ( V_3 ) ;
V_81 = F_104 ( V_245 , V_272 , 0 ) ;
if ( V_81 == NULL )
F_108 ( & V_245 -> V_249 , L_76 ) ;
else
V_151 = V_81 -> V_85 ;
V_9 = F_109 ( & V_245 -> V_249 , L_77 ) ;
if ( F_106 ( V_9 ) ) {
F_86 ( & V_245 -> V_249 , L_78 ) ;
V_151 = 0 ;
return F_107 ( V_9 ) ;
}
F_110 ( & V_245 -> V_249 ) ;
F_111 ( & V_245 -> V_249 ) ;
V_273 = & V_245 -> V_249 ;
V_18 = F_3 ( V_274 ) ;
if ( F_112 ( V_18 ) > 0x4 )
V_61 = V_64 | V_62 ;
if ( F_112 ( V_18 ) > 0x5 )
V_61 |= V_224 ;
F_113 ( V_273 , L_79 , F_112 ( V_18 ) ,
F_114 ( V_18 ) ) ;
F_63 () ;
if ( F_51 () < 0 )
F_108 ( V_273 , L_80 ) ;
V_78 = 0 ;
if ( ! V_245 -> V_249 . V_252 ) {
V_90 = V_266 ;
V_234 = V_275 ;
}
V_267 = F_97 ( V_245 ) ;
if ( V_267 < 0 ) {
F_115 ( & V_245 -> V_249 ) ;
F_116 ( V_9 ) ;
F_86 ( V_273 , L_81 ) ;
return V_267 ;
}
return 0 ;
}
static int F_117 ( struct V_244 * V_245 )
{
F_56 () ;
F_62 () ;
F_115 ( & V_245 -> V_249 ) ;
F_118 ( & V_245 -> V_249 ) ;
V_273 = NULL ;
return 0 ;
}
static int F_119 ( struct V_276 * V_249 )
{
F_120 () ;
F_115 ( V_249 ) ;
return 0 ;
}
static int F_121 ( struct V_276 * V_249 )
{
F_111 ( V_249 ) ;
F_122 () ;
return 0 ;
}
static T_4 int F_123 ( void )
{
return F_124 ( & V_277 ) ;
}
static T_5 void F_125 ( void )
{
F_126 ( & V_277 ) ;
}
static int T_4 F_127 ( void )
{
struct V_278 * V_279 ;
struct V_244 * V_245 ;
char * V_280 = L_7 ;
if ( F_128 () )
return - V_92 ;
V_279 = F_129 ( V_280 ) ;
if ( ! V_279 ) {
F_35 ( L_82 , V_280 ) ;
return - V_92 ;
}
V_245 = F_130 ( V_281 , - 1 , V_279 , NULL , 0 ) ;
F_101 ( F_106 ( V_245 ) , L_83 , V_280 ) ;
return F_131 ( V_245 ) ;
}
static T_6 V_167 ( int V_147 , void * V_249 )
{
int V_108 ;
T_1 V_99 ;
V_99 = F_3 ( V_103 ) ;
if ( ! V_99 )
return V_282 ;
for ( V_108 = 0 ; V_108 < V_144 ; V_108 ++ )
if ( V_99 & V_145 [ V_108 ] . V_146 )
F_132 ( V_145 [ V_108 ] . V_147 ) ;
F_1 ( V_103 , V_99 ) ;
return V_283 ;
}
void F_120 ( void )
{
int V_108 ;
V_284 . V_285 = F_3 ( V_286 ) ;
V_284 . V_287 = F_3 ( V_101 ) ;
V_284 . V_288 = F_3 ( V_289 ) ;
V_284 . V_290 = F_3 ( V_105 ) ;
V_284 . V_291 = F_3 ( V_118 ) ;
V_284 . V_292 = F_3 ( V_120 ) ;
V_284 . V_293 = F_3 ( V_122 ) ;
for ( V_108 = 0 ; V_108 < V_90 ; V_108 ++ ) {
V_284 . V_294 [ V_108 ] . V_295 = F_24 ( V_108 ) ;
if ( V_284 . V_294 [ V_108 ] . V_295 ) {
V_284 . V_294 [ V_108 ] . V_218 =
F_6 ( V_108 , V_21 ) ;
V_284 . V_294 [ V_108 ] . V_296 =
F_6 ( V_108 , V_24 ) ;
V_284 . V_294 [ V_108 ] . V_297 =
F_6 ( V_108 , V_27 ) ;
V_284 . V_294 [ V_108 ] . V_298 =
F_6 ( V_108 , V_30 ) ;
V_284 . V_294 [ V_108 ] . V_299 =
F_6 ( V_108 , V_52 ) ;
V_284 . V_294 [ V_108 ] . V_300 =
F_6 ( V_108 , V_34 ) ;
V_284 . V_294 [ V_108 ] . V_301 =
F_6 ( V_108 , V_74 ) ;
}
}
}
void F_122 ( void )
{
int V_108 ;
F_1 ( V_286 , V_284 . V_285 ) ;
F_1 ( V_101 , V_284 . V_287 ) ;
F_1 ( V_289 , V_284 . V_288 ) ;
F_1 ( V_105 , V_284 . V_290 ) ;
F_1 ( V_118 , V_284 . V_291 ) ;
F_1 ( V_120 , V_284 . V_292 ) ;
F_1 ( V_122 , V_284 . V_293 ) ;
for ( V_108 = 0 ; V_108 < V_90 ; V_108 ++ ) {
if ( V_284 . V_294 [ V_108 ] . V_295 ) {
F_5 ( V_108 , V_21 ,
V_284 . V_294 [ V_108 ] . V_218 ) ;
F_5 ( V_108 , V_24 ,
V_284 . V_294 [ V_108 ] . V_296 ) ;
F_5 ( V_108 , V_27 ,
V_284 . V_294 [ V_108 ] . V_297 ) ;
F_5 ( V_108 , V_30 ,
V_284 . V_294 [ V_108 ] . V_298 ) ;
F_5 ( V_108 , V_52 ,
V_284 . V_294 [ V_108 ] . V_299 ) ;
F_5 ( V_108 , V_34 ,
V_284 . V_294 [ V_108 ] . V_300 ) ;
F_5 ( V_108 , V_74 ,
V_284 . V_294 [ V_108 ] . V_301 ) ;
}
}
}

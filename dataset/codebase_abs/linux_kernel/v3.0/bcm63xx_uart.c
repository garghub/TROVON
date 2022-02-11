static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned int V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static unsigned int F_5 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_7 ) ;
return ( V_6 & F_6 ( V_8 ) ) ? 1 : 0 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned int V_9 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_10 ) ;
V_6 &= ~ ( V_11 | V_12 ) ;
if ( ! ( V_9 & V_13 ) )
V_6 |= V_11 ;
if ( ! ( V_9 & V_14 ) )
V_6 |= V_12 ;
F_3 ( V_2 , V_6 , V_10 ) ;
V_6 = F_1 ( V_2 , V_15 ) ;
if ( V_9 & V_16 )
V_6 |= V_17 ;
else
V_6 &= ~ V_17 ;
F_3 ( V_2 , V_6 , V_15 ) ;
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
unsigned int V_6 , V_9 ;
V_9 = 0 ;
V_6 = F_1 ( V_2 , V_18 ) ;
if ( V_6 & V_19 )
V_9 |= V_20 ;
if ( V_6 & V_21 )
V_9 |= V_22 ;
if ( V_6 & V_23 )
V_9 |= V_24 ;
if ( V_6 & V_25 )
V_9 |= V_26 ;
return V_9 ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_15 ) ;
V_6 &= ~ ( V_27 ) ;
F_3 ( V_2 , V_6 , V_15 ) ;
V_6 = F_1 ( V_2 , V_7 ) ;
V_6 &= ~ V_28 ;
F_3 ( V_2 , V_6 , V_7 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_7 ) ;
V_6 |= V_28 ;
F_3 ( V_2 , V_6 , V_7 ) ;
V_6 = F_1 ( V_2 , V_15 ) ;
V_6 |= V_27 ;
F_3 ( V_2 , V_6 , V_15 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_7 ) ;
V_6 &= ~ V_29 ;
F_3 ( V_2 , V_6 , V_7 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_7 ) ;
V_6 |= F_13 ( V_30 ) ;
F_3 ( V_2 , V_6 , V_7 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_31 )
{
unsigned long V_32 ;
unsigned int V_6 ;
F_15 ( & V_2 -> V_33 , V_32 ) ;
V_6 = F_1 ( V_2 , V_15 ) ;
if ( V_31 )
V_6 |= V_34 ;
else
V_6 &= ~ V_34 ;
F_3 ( V_2 , V_6 , V_15 ) ;
F_16 ( & V_2 -> V_33 , V_32 ) ;
}
static const char * F_17 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_35 ) ? L_1 : NULL ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
unsigned int V_38 ;
V_38 = 32 ;
V_37 = V_2 -> V_39 -> V_2 . V_37 ;
do {
unsigned int V_40 , V_41 , V_42 ;
char V_43 ;
V_40 = F_1 ( V_2 , V_7 ) ;
if ( F_19 ( V_40 & F_6 ( V_44 ) ) ) {
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_15 ) ;
V_6 |= V_45 ;
F_3 ( V_2 , V_6 , V_15 ) ;
V_2 -> V_46 . V_47 ++ ;
F_20 ( V_37 , 0 , V_48 ) ;
}
if ( ! ( V_40 & F_6 ( V_49 ) ) )
break;
V_42 = V_41 = F_1 ( V_2 , V_50 ) ;
V_2 -> V_46 . V_51 ++ ;
V_43 = V_52 ;
V_41 &= 0xff ;
if ( F_19 ( ( V_42 & V_53 ) ) ) {
if ( V_42 & V_54 ) {
V_2 -> V_46 . V_55 ++ ;
if ( F_21 ( V_2 ) )
continue;
}
if ( V_42 & V_56 )
V_2 -> V_46 . V_57 ++ ;
if ( V_42 & V_58 )
V_2 -> V_46 . V_59 ++ ;
V_42 &= V_2 -> V_60 ;
if ( V_42 & V_54 )
V_43 = V_61 ;
if ( V_42 & V_58 )
V_43 = V_62 ;
if ( V_42 & V_56 )
V_43 = V_63 ;
}
if ( F_22 ( V_2 , V_41 ) )
continue;
if ( ( V_42 & V_2 -> V_64 ) == 0 )
F_20 ( V_37 , V_41 , V_43 ) ;
} while ( -- V_38 );
F_23 ( V_37 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
unsigned int V_6 , V_38 ;
if ( V_2 -> V_67 ) {
F_3 ( V_2 , V_2 -> V_67 , V_50 ) ;
V_2 -> V_46 . V_68 ++ ;
V_2 -> V_67 = 0 ;
return;
}
if ( F_25 ( V_2 ) ) {
F_9 ( V_2 ) ;
return;
}
V_66 = & V_2 -> V_39 -> V_66 ;
if ( F_26 ( V_66 ) )
goto V_69;
V_6 = F_1 ( V_2 , V_10 ) ;
V_6 = ( V_6 & V_70 ) >> V_71 ;
V_38 = V_2 -> V_72 - V_6 ;
while ( V_38 -- ) {
unsigned int V_41 ;
V_41 = V_66 -> V_73 [ V_66 -> V_74 ] ;
F_3 ( V_2 , V_41 , V_50 ) ;
V_66 -> V_74 = ( V_66 -> V_74 + 1 ) & ( V_75 - 1 ) ;
V_2 -> V_46 . V_68 ++ ;
if ( F_26 ( V_66 ) )
break;
}
if ( F_27 ( V_66 ) < V_76 )
F_28 ( V_2 ) ;
if ( F_26 ( V_66 ) )
goto V_69;
return;
V_69:
V_6 = F_1 ( V_2 , V_7 ) ;
V_6 &= ~ V_28 ;
F_3 ( V_2 , V_6 , V_7 ) ;
return;
}
static T_1 F_29 ( int V_77 , void * V_78 )
{
struct V_1 * V_2 ;
unsigned int V_79 ;
V_2 = V_78 ;
F_30 ( & V_2 -> V_33 ) ;
V_79 = F_1 ( V_2 , V_7 ) ;
if ( V_79 & V_80 )
F_18 ( V_2 ) ;
if ( V_79 & V_81 )
F_24 ( V_2 ) ;
if ( V_79 & F_13 ( V_30 ) ) {
unsigned int V_82 ;
V_82 = F_1 ( V_2 , V_18 ) ;
if ( V_82 & F_31 ( V_83 ) )
F_32 ( V_2 ,
V_82 & V_21 ) ;
if ( V_82 & F_31 ( V_84 ) )
F_33 ( V_2 ,
V_82 & V_23 ) ;
}
F_34 ( & V_2 -> V_33 ) ;
return V_85 ;
}
static void F_35 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_15 ) ;
V_6 |= ( V_86 | V_27 | V_87 ) ;
F_3 ( V_2 , V_6 , V_15 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_15 ) ;
V_6 &= ~ ( V_86 | V_27 |
V_87 ) ;
F_3 ( V_2 , V_6 , V_15 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_15 ) ;
V_6 |= V_45 | V_88 ;
F_3 ( V_2 , V_6 , V_15 ) ;
( void ) F_1 ( V_2 , V_50 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
int V_89 ;
F_36 ( V_2 ) ;
F_3 ( V_2 , 0 , V_7 ) ;
F_37 ( V_2 ) ;
( void ) F_1 ( V_2 , V_18 ) ;
V_6 = F_1 ( V_2 , V_10 ) ;
V_6 &= ~ ( V_90 | V_91 ) ;
V_6 |= ( V_2 -> V_72 / 2 ) << V_92 ;
V_6 |= ( V_2 -> V_72 / 2 ) << V_93 ;
F_3 ( V_2 , V_6 , V_10 ) ;
V_6 = F_1 ( V_2 , V_15 ) ;
V_6 &= ~ V_94 ;
V_6 |= 1 << V_95 ;
F_3 ( V_2 , V_6 , V_15 ) ;
V_6 = V_96 ;
V_6 |= V_97 ;
V_6 |= V_98 ;
F_3 ( V_2 , V_6 , V_18 ) ;
V_89 = F_39 ( V_2 -> V_77 , F_29 , 0 ,
F_17 ( V_2 ) , V_2 ) ;
if ( V_89 )
return V_89 ;
F_3 ( V_2 , V_29 , V_7 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
unsigned long V_32 ;
F_15 ( & V_2 -> V_33 , V_32 ) ;
F_3 ( V_2 , 0 , V_7 ) ;
F_16 ( & V_2 -> V_33 , V_32 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_41 ( V_2 -> V_77 , V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_99 * V_100 ,
struct V_99 * V_101 )
{
unsigned int V_31 , V_102 , V_103 , V_104 ;
unsigned long V_32 ;
F_15 ( & V_2 -> V_33 , V_32 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
V_31 = F_1 ( V_2 , V_15 ) ;
V_31 &= ~ V_105 ;
switch ( V_100 -> V_106 & V_107 ) {
case V_108 :
V_31 |= ( 0 << V_109 ) ;
break;
case V_110 :
V_31 |= ( 1 << V_109 ) ;
break;
case V_111 :
V_31 |= ( 2 << V_109 ) ;
break;
default:
V_31 |= ( 3 << V_109 ) ;
break;
}
V_31 &= ~ V_112 ;
if ( V_100 -> V_106 & V_113 )
V_31 |= V_114 ;
else
V_31 |= V_115 ;
V_31 &= ~ ( V_116 | V_117 ) ;
if ( V_100 -> V_106 & V_118 )
V_31 |= ( V_116 | V_117 ) ;
V_31 &= ~ ( V_119 | V_120 ) ;
if ( V_100 -> V_106 & V_121 )
V_31 |= ( V_119 | V_120 ) ;
F_3 ( V_2 , V_31 , V_15 ) ;
V_102 = F_43 ( V_2 , V_100 , V_101 , 0 , V_2 -> V_122 / 16 ) ;
V_103 = F_44 ( V_2 , V_102 ) - 1 ;
F_3 ( V_2 , V_103 , V_123 ) ;
V_104 = F_1 ( V_2 , V_7 ) ;
V_104 &= ~ F_13 ( V_30 ) ;
if ( F_45 ( V_2 , V_100 -> V_106 ) )
V_104 |= F_13 ( V_30 ) ;
F_3 ( V_2 , V_104 , V_7 ) ;
V_2 -> V_60 = V_124 ;
if ( V_100 -> V_125 & V_126 ) {
V_2 -> V_60 |= V_58 ;
V_2 -> V_60 |= V_56 ;
}
if ( V_100 -> V_125 & ( V_127 ) )
V_2 -> V_60 |= V_54 ;
V_2 -> V_64 = 0 ;
if ( V_100 -> V_125 & V_128 )
V_2 -> V_64 |= V_56 ;
if ( V_100 -> V_125 & V_129 )
V_2 -> V_64 |= V_54 ;
if ( ! ( V_100 -> V_106 & V_130 ) )
V_2 -> V_64 |= V_124 ;
F_46 ( V_2 , V_100 -> V_106 , V_102 ) ;
F_35 ( V_2 ) ;
F_16 ( & V_2 -> V_33 , V_32 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
unsigned int V_131 ;
V_131 = V_132 ;
if ( ! F_48 ( V_2 -> V_133 , V_131 , L_2 ) ) {
F_49 ( V_2 -> V_134 , L_3 ) ;
return - V_135 ;
}
V_2 -> V_4 = F_50 ( V_2 -> V_133 , V_131 ) ;
if ( ! V_2 -> V_4 ) {
F_49 ( V_2 -> V_134 , L_4 ) ;
F_51 ( V_2 -> V_133 , V_131 ) ;
return - V_135 ;
}
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_51 ( V_2 -> V_133 , V_132 ) ;
F_53 ( V_2 -> V_4 ) ;
}
static void F_54 ( struct V_1 * V_2 , int V_32 )
{
if ( V_32 & V_136 ) {
if ( F_47 ( V_2 ) )
return;
V_2 -> type = V_35 ;
}
}
static int F_55 ( struct V_1 * V_2 ,
struct V_137 * V_138 )
{
if ( V_2 -> type != V_35 )
return - V_139 ;
if ( V_2 -> V_77 != V_138 -> V_77 )
return - V_139 ;
if ( V_2 -> V_140 != V_138 -> V_141 )
return - V_139 ;
if ( V_2 -> V_133 != ( unsigned long ) V_138 -> V_142 )
return - V_139 ;
return 0 ;
}
static inline void F_56 ( struct V_1 * V_2 )
{
unsigned int V_143 ;
V_143 = 10000 ;
while ( -- V_143 ) {
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_7 ) ;
if ( V_6 & F_6 ( V_8 ) )
break;
F_57 ( 1 ) ;
}
if ( V_2 -> V_32 & V_144 ) {
V_143 = 1000000 ;
while ( -- V_143 ) {
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_18 ) ;
if ( V_6 & V_21 )
break;
F_57 ( 1 ) ;
}
}
}
static void F_58 ( struct V_1 * V_2 , int V_145 )
{
F_56 ( V_2 ) ;
F_3 ( V_2 , V_145 , V_50 ) ;
}
static void F_59 ( struct V_146 * V_147 , const char * V_148 ,
unsigned int V_149 )
{
struct V_1 * V_2 ;
unsigned long V_32 ;
int V_150 ;
V_2 = & V_151 [ V_147 -> V_152 ] ;
F_60 ( V_32 ) ;
if ( V_2 -> V_153 ) {
V_150 = 0 ;
} else if ( V_154 ) {
V_150 = F_61 ( & V_2 -> V_33 ) ;
} else {
F_30 ( & V_2 -> V_33 ) ;
V_150 = 1 ;
}
F_62 ( V_2 , V_148 , V_149 , F_58 ) ;
F_56 ( V_2 ) ;
if ( V_150 )
F_34 ( & V_2 -> V_33 ) ;
F_63 ( V_32 ) ;
}
static int F_64 ( struct V_146 * V_147 , char * V_155 )
{
struct V_1 * V_2 ;
int V_102 = 9600 ;
int V_156 = 8 ;
int V_57 = 'n' ;
int V_157 = 'n' ;
if ( V_147 -> V_152 < 0 || V_147 -> V_152 >= V_158 )
return - V_139 ;
V_2 = & V_151 [ V_147 -> V_152 ] ;
if ( ! V_2 -> V_4 )
return - V_159 ;
if ( V_155 )
F_65 ( V_155 , & V_102 , & V_57 , & V_156 , & V_157 ) ;
return F_66 ( V_2 , V_147 , V_102 , V_57 , V_156 , V_157 ) ;
}
static int T_2 F_67 ( void )
{
F_68 ( & V_160 ) ;
return 0 ;
}
static int T_3 F_69 ( struct V_161 * V_162 )
{
struct V_163 * V_164 , * V_165 ;
struct V_1 * V_2 ;
struct V_166 * V_166 ;
int V_89 ;
if ( V_162 -> V_167 < 0 || V_162 -> V_167 >= V_158 )
return - V_139 ;
if ( V_151 [ V_162 -> V_167 ] . V_4 )
return - V_135 ;
V_164 = F_70 ( V_162 , V_168 , 0 ) ;
if ( ! V_164 )
return - V_159 ;
V_165 = F_70 ( V_162 , V_169 , 0 ) ;
if ( ! V_165 )
return - V_159 ;
V_166 = F_71 ( & V_162 -> V_134 , L_5 ) ;
if ( F_72 ( V_166 ) )
return - V_159 ;
V_2 = & V_151 [ V_162 -> V_167 ] ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_140 = V_170 ;
V_2 -> V_133 = V_164 -> V_171 ;
V_2 -> V_77 = V_165 -> V_171 ;
V_2 -> V_172 = & V_173 ;
V_2 -> V_32 = V_174 ;
V_2 -> V_134 = & V_162 -> V_134 ;
V_2 -> V_72 = 16 ;
V_2 -> V_122 = F_73 ( V_166 ) / 2 ;
V_2 -> line = V_162 -> V_167 ;
F_74 ( V_166 ) ;
V_89 = F_75 ( & V_175 , V_2 ) ;
if ( V_89 ) {
V_151 [ V_162 -> V_167 ] . V_4 = 0 ;
return V_89 ;
}
F_76 ( V_162 , V_2 ) ;
return 0 ;
}
static int T_4 F_77 ( struct V_161 * V_162 )
{
struct V_1 * V_2 ;
V_2 = F_78 ( V_162 ) ;
F_79 ( & V_175 , V_2 ) ;
F_76 ( V_162 , NULL ) ;
V_151 [ V_162 -> V_167 ] . V_4 = 0 ;
return 0 ;
}
static int T_2 F_80 ( void )
{
int V_89 ;
V_89 = F_81 ( & V_175 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_82 ( & V_176 ) ;
if ( V_89 )
F_83 ( & V_175 ) ;
return V_89 ;
}
static void T_5 F_84 ( void )
{
F_85 ( & V_176 ) ;
F_83 ( & V_175 ) ;
}

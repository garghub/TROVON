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
struct V_36 * V_36 = & V_2 -> V_37 -> V_2 ;
unsigned int V_38 ;
V_38 = 32 ;
do {
unsigned int V_39 , V_40 , V_41 ;
char V_42 ;
V_39 = F_1 ( V_2 , V_7 ) ;
if ( F_19 ( V_39 & F_6 ( V_43 ) ) ) {
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_15 ) ;
V_6 |= V_44 ;
F_3 ( V_2 , V_6 , V_15 ) ;
V_2 -> V_45 . V_46 ++ ;
F_20 ( V_36 , 0 , V_47 ) ;
}
if ( ! ( V_39 & F_6 ( V_48 ) ) )
break;
V_41 = V_40 = F_1 ( V_2 , V_49 ) ;
V_2 -> V_45 . V_50 ++ ;
V_42 = V_51 ;
V_40 &= 0xff ;
if ( F_19 ( ( V_41 & V_52 ) ) ) {
if ( V_41 & V_53 ) {
V_2 -> V_45 . V_54 ++ ;
if ( F_21 ( V_2 ) )
continue;
}
if ( V_41 & V_55 )
V_2 -> V_45 . V_56 ++ ;
if ( V_41 & V_57 )
V_2 -> V_45 . V_58 ++ ;
V_41 &= V_2 -> V_59 ;
if ( V_41 & V_53 )
V_42 = V_60 ;
if ( V_41 & V_57 )
V_42 = V_61 ;
if ( V_41 & V_55 )
V_42 = V_62 ;
}
if ( F_22 ( V_2 , V_40 ) )
continue;
if ( ( V_41 & V_2 -> V_63 ) == 0 )
F_20 ( V_36 , V_40 , V_42 ) ;
} while ( -- V_38 );
F_23 ( & V_2 -> V_33 ) ;
F_24 ( V_36 ) ;
F_25 ( & V_2 -> V_33 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
unsigned int V_6 , V_38 ;
if ( V_2 -> V_66 ) {
F_3 ( V_2 , V_2 -> V_66 , V_49 ) ;
V_2 -> V_45 . V_67 ++ ;
V_2 -> V_66 = 0 ;
return;
}
if ( F_27 ( V_2 ) ) {
F_9 ( V_2 ) ;
return;
}
V_65 = & V_2 -> V_37 -> V_65 ;
if ( F_28 ( V_65 ) )
goto V_68;
V_6 = F_1 ( V_2 , V_10 ) ;
V_6 = ( V_6 & V_69 ) >> V_70 ;
V_38 = V_2 -> V_71 - V_6 ;
while ( V_38 -- ) {
unsigned int V_40 ;
V_40 = V_65 -> V_72 [ V_65 -> V_73 ] ;
F_3 ( V_2 , V_40 , V_49 ) ;
V_65 -> V_73 = ( V_65 -> V_73 + 1 ) & ( V_74 - 1 ) ;
V_2 -> V_45 . V_67 ++ ;
if ( F_28 ( V_65 ) )
break;
}
if ( F_29 ( V_65 ) < V_75 )
F_30 ( V_2 ) ;
if ( F_28 ( V_65 ) )
goto V_68;
return;
V_68:
V_6 = F_1 ( V_2 , V_7 ) ;
V_6 &= ~ V_28 ;
F_3 ( V_2 , V_6 , V_7 ) ;
return;
}
static T_1 F_31 ( int V_76 , void * V_77 )
{
struct V_1 * V_2 ;
unsigned int V_78 ;
V_2 = V_77 ;
F_25 ( & V_2 -> V_33 ) ;
V_78 = F_1 ( V_2 , V_7 ) ;
if ( V_78 & V_79 )
F_18 ( V_2 ) ;
if ( V_78 & V_80 )
F_26 ( V_2 ) ;
if ( V_78 & F_13 ( V_30 ) ) {
unsigned int V_81 ;
V_81 = F_1 ( V_2 , V_18 ) ;
if ( V_81 & F_32 ( V_82 ) )
F_33 ( V_2 ,
V_81 & V_21 ) ;
if ( V_81 & F_32 ( V_83 ) )
F_34 ( V_2 ,
V_81 & V_23 ) ;
}
F_23 ( & V_2 -> V_33 ) ;
return V_84 ;
}
static void F_35 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_15 ) ;
V_6 |= ( V_85 | V_27 | V_86 ) ;
F_3 ( V_2 , V_6 , V_15 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_15 ) ;
V_6 &= ~ ( V_85 | V_27 |
V_86 ) ;
F_3 ( V_2 , V_6 , V_15 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_15 ) ;
V_6 |= V_44 | V_87 ;
F_3 ( V_2 , V_6 , V_15 ) ;
( void ) F_1 ( V_2 , V_49 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
int V_88 ;
F_36 ( V_2 ) ;
F_3 ( V_2 , 0 , V_7 ) ;
F_37 ( V_2 ) ;
( void ) F_1 ( V_2 , V_18 ) ;
V_6 = F_1 ( V_2 , V_10 ) ;
V_6 &= ~ ( V_89 | V_90 ) ;
V_6 |= ( V_2 -> V_71 / 2 ) << V_91 ;
V_6 |= ( V_2 -> V_71 / 2 ) << V_92 ;
F_3 ( V_2 , V_6 , V_10 ) ;
V_6 = F_1 ( V_2 , V_15 ) ;
V_6 &= ~ V_93 ;
V_6 |= 1 << V_94 ;
F_3 ( V_2 , V_6 , V_15 ) ;
V_6 = V_95 ;
V_6 |= V_96 ;
V_6 |= V_97 ;
F_3 ( V_2 , V_6 , V_18 ) ;
V_88 = F_39 ( V_2 -> V_76 , F_31 , 0 ,
F_17 ( V_2 ) , V_2 ) ;
if ( V_88 )
return V_88 ;
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
F_41 ( V_2 -> V_76 , V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_98 * V_99 ,
struct V_98 * V_100 )
{
unsigned int V_31 , V_101 , V_102 , V_103 ;
unsigned long V_32 ;
F_15 ( & V_2 -> V_33 , V_32 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
V_31 = F_1 ( V_2 , V_15 ) ;
V_31 &= ~ V_104 ;
switch ( V_99 -> V_105 & V_106 ) {
case V_107 :
V_31 |= ( 0 << V_108 ) ;
break;
case V_109 :
V_31 |= ( 1 << V_108 ) ;
break;
case V_110 :
V_31 |= ( 2 << V_108 ) ;
break;
default:
V_31 |= ( 3 << V_108 ) ;
break;
}
V_31 &= ~ V_111 ;
if ( V_99 -> V_105 & V_112 )
V_31 |= V_113 ;
else
V_31 |= V_114 ;
V_31 &= ~ ( V_115 | V_116 ) ;
if ( V_99 -> V_105 & V_117 )
V_31 |= ( V_115 | V_116 ) ;
V_31 &= ~ ( V_118 | V_119 ) ;
if ( V_99 -> V_105 & V_120 )
V_31 |= ( V_118 | V_119 ) ;
F_3 ( V_2 , V_31 , V_15 ) ;
V_101 = F_43 ( V_2 , V_99 , V_100 , 0 , V_2 -> V_121 / 16 ) ;
V_102 = F_44 ( V_2 , V_101 ) - 1 ;
F_3 ( V_2 , V_102 , V_122 ) ;
V_103 = F_1 ( V_2 , V_7 ) ;
V_103 &= ~ F_13 ( V_30 ) ;
if ( F_45 ( V_2 , V_99 -> V_105 ) )
V_103 |= F_13 ( V_30 ) ;
F_3 ( V_2 , V_103 , V_7 ) ;
V_2 -> V_59 = V_123 ;
if ( V_99 -> V_124 & V_125 ) {
V_2 -> V_59 |= V_57 ;
V_2 -> V_59 |= V_55 ;
}
if ( V_99 -> V_124 & ( V_126 | V_127 ) )
V_2 -> V_59 |= V_53 ;
V_2 -> V_63 = 0 ;
if ( V_99 -> V_124 & V_128 )
V_2 -> V_63 |= V_55 ;
if ( V_99 -> V_124 & V_126 )
V_2 -> V_63 |= V_53 ;
if ( ! ( V_99 -> V_105 & V_129 ) )
V_2 -> V_63 |= V_123 ;
F_46 ( V_2 , V_99 -> V_105 , V_101 ) ;
F_35 ( V_2 ) ;
F_16 ( & V_2 -> V_33 , V_32 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
}
static void F_49 ( struct V_1 * V_2 , int V_32 )
{
if ( V_32 & V_130 ) {
if ( F_47 ( V_2 ) )
return;
V_2 -> type = V_35 ;
}
}
static int F_50 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
if ( V_2 -> type != V_35 )
return - V_133 ;
if ( V_2 -> V_76 != V_132 -> V_76 )
return - V_133 ;
if ( V_2 -> V_134 != V_132 -> V_135 )
return - V_133 ;
if ( V_2 -> V_136 != ( unsigned long ) V_132 -> V_137 )
return - V_133 ;
return 0 ;
}
static inline void F_51 ( struct V_1 * V_2 )
{
unsigned int V_138 ;
V_138 = 10000 ;
while ( -- V_138 ) {
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_7 ) ;
if ( V_6 & F_6 ( V_8 ) )
break;
F_52 ( 1 ) ;
}
if ( V_2 -> V_32 & V_139 ) {
V_138 = 1000000 ;
while ( -- V_138 ) {
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_18 ) ;
if ( V_6 & V_21 )
break;
F_52 ( 1 ) ;
}
}
}
static void F_53 ( struct V_1 * V_2 , int V_140 )
{
F_51 ( V_2 ) ;
F_3 ( V_2 , V_140 , V_49 ) ;
}
static void F_54 ( struct V_141 * V_142 , const char * V_143 ,
unsigned int V_144 )
{
struct V_1 * V_2 ;
unsigned long V_32 ;
int V_145 ;
V_2 = & V_146 [ V_142 -> V_147 ] ;
F_55 ( V_32 ) ;
if ( V_2 -> V_148 ) {
V_145 = 0 ;
} else if ( V_149 ) {
V_145 = F_56 ( & V_2 -> V_33 ) ;
} else {
F_25 ( & V_2 -> V_33 ) ;
V_145 = 1 ;
}
F_57 ( V_2 , V_143 , V_144 , F_53 ) ;
F_51 ( V_2 ) ;
if ( V_145 )
F_23 ( & V_2 -> V_33 ) ;
F_58 ( V_32 ) ;
}
static int F_59 ( struct V_141 * V_142 , char * V_150 )
{
struct V_1 * V_2 ;
int V_101 = 9600 ;
int V_151 = 8 ;
int V_56 = 'n' ;
int V_152 = 'n' ;
if ( V_142 -> V_147 < 0 || V_142 -> V_147 >= V_153 )
return - V_133 ;
V_2 = & V_146 [ V_142 -> V_147 ] ;
if ( ! V_2 -> V_4 )
return - V_154 ;
if ( V_150 )
F_60 ( V_150 , & V_101 , & V_56 , & V_151 , & V_152 ) ;
return F_61 ( V_2 , V_142 , V_101 , V_56 , V_151 , V_152 ) ;
}
static int T_2 F_62 ( void )
{
F_63 ( & V_155 ) ;
return 0 ;
}
static void F_64 ( struct V_141 * V_156 , const char * V_143 , unsigned V_157 )
{
struct V_158 * V_159 = V_156 -> V_160 ;
F_57 ( & V_159 -> V_2 , V_143 , V_157 , F_53 ) ;
F_51 ( & V_159 -> V_2 ) ;
}
static int T_2 F_65 ( struct V_158 * V_161 ,
const char * V_162 )
{
if ( ! V_161 -> V_2 . V_4 )
return - V_154 ;
V_161 -> V_156 -> V_163 = F_64 ;
return 0 ;
}
static int F_66 ( struct V_164 * V_165 )
{
struct V_166 * V_167 , * V_168 ;
struct V_1 * V_2 ;
struct V_169 * V_169 ;
int V_88 ;
if ( V_165 -> V_159 . V_170 )
V_165 -> V_171 = F_67 ( V_165 -> V_159 . V_170 , L_2 ) ;
if ( V_165 -> V_171 < 0 || V_165 -> V_171 >= V_153 )
return - V_133 ;
V_2 = & V_146 [ V_165 -> V_171 ] ;
if ( V_2 -> V_4 )
return - V_172 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_167 = F_68 ( V_165 , V_173 , 0 ) ;
if ( ! V_167 )
return - V_154 ;
V_2 -> V_136 = V_167 -> V_174 ;
V_2 -> V_4 = F_69 ( & V_165 -> V_159 , V_167 ) ;
if ( F_70 ( V_2 -> V_4 ) )
return F_71 ( V_2 -> V_4 ) ;
V_168 = F_68 ( V_165 , V_175 , 0 ) ;
if ( ! V_168 )
return - V_154 ;
V_169 = V_165 -> V_159 . V_170 ? F_72 ( V_165 -> V_159 . V_170 , 0 ) :
F_73 ( & V_165 -> V_159 , L_3 ) ;
if ( F_70 ( V_169 ) )
return - V_154 ;
V_2 -> V_134 = V_176 ;
V_2 -> V_76 = V_168 -> V_174 ;
V_2 -> V_177 = & V_178 ;
V_2 -> V_32 = V_179 ;
V_2 -> V_159 = & V_165 -> V_159 ;
V_2 -> V_71 = 16 ;
V_2 -> V_121 = F_74 ( V_169 ) / 2 ;
V_2 -> line = V_165 -> V_171 ;
F_75 ( V_169 ) ;
V_88 = F_76 ( & V_180 , V_2 ) ;
if ( V_88 ) {
V_146 [ V_165 -> V_171 ] . V_4 = 0 ;
return V_88 ;
}
F_77 ( V_165 , V_2 ) ;
return 0 ;
}
static int F_78 ( struct V_164 * V_165 )
{
struct V_1 * V_2 ;
V_2 = F_79 ( V_165 ) ;
F_80 ( & V_180 , V_2 ) ;
V_146 [ V_165 -> V_171 ] . V_4 = 0 ;
return 0 ;
}
static int T_2 F_81 ( void )
{
int V_88 ;
V_88 = F_82 ( & V_180 ) ;
if ( V_88 )
return V_88 ;
V_88 = F_83 ( & V_181 ) ;
if ( V_88 )
F_84 ( & V_180 ) ;
return V_88 ;
}
static void T_3 F_85 ( void )
{
F_86 ( & V_181 ) ;
F_84 ( & V_180 ) ;
}

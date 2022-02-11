static void F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 &= ~ ( V_6 | V_7 ) ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_3 & ~ V_8 , V_2 -> V_4 + V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
}
static inline void F_6 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = & V_10 -> V_2 . V_13 -> V_12 ;
while ( ! F_7 ( V_12 ) &&
( F_2 ( V_10 -> V_2 . V_4 + V_14 ) < V_10 -> V_15 ) ) {
F_3 ( V_12 -> V_16 [ V_12 -> V_17 ] , V_10 -> V_2 . V_4 + V_18 ) ;
V_12 -> V_17 = ( V_12 -> V_17 + 1 ) & ( V_19 - 1 ) ;
V_10 -> V_2 . V_20 . V_21 ++ ;
}
if ( F_8 ( V_12 ) < V_22 )
F_9 ( & V_10 -> V_2 ) ;
if ( F_7 ( V_12 ) )
F_1 ( & V_10 -> V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_11 ( V_2 , struct V_9 , V_2 ) ;
unsigned char V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_3 | V_6 , V_2 -> V_4 + V_5 ) ;
if ( F_2 ( V_2 -> V_4 + V_23 ) & V_24 )
F_6 ( V_10 ) ;
}
static T_1 F_12 ( int V_25 , void * V_26 )
{
struct V_9 * V_10 = V_26 ;
struct V_11 * V_12 = & V_10 -> V_2 . V_13 -> V_12 ;
unsigned long V_27 ;
F_13 ( & V_10 -> V_2 . V_28 , V_27 ) ;
if ( V_10 -> V_2 . V_29 ) {
F_3 ( V_10 -> V_2 . V_29 , V_10 -> V_2 . V_4 + V_18 ) ;
goto V_30;
}
if ( F_7 ( V_12 ) || F_14 ( & V_10 -> V_2 ) ) {
F_1 ( & V_10 -> V_2 ) ;
goto V_30;
}
F_6 ( V_10 ) ;
if ( F_8 ( V_12 ) < V_22 )
F_9 ( & V_10 -> V_2 ) ;
V_30:
F_15 ( & V_10 -> V_2 . V_28 , V_27 ) ;
return V_31 ;
}
static T_1 F_16 ( int V_25 , void * V_26 )
{
struct V_9 * V_10 = V_26 ;
unsigned int V_32 , V_33 = 0 ;
struct V_34 * V_2 = & V_10 -> V_2 . V_13 -> V_2 ;
unsigned long V_27 ;
unsigned char V_35 , V_36 ;
F_13 ( & V_10 -> V_2 . V_28 , V_27 ) ;
while ( ! ( F_2 ( V_10 -> V_2 . V_4 + V_37 ) & V_38 ) ) {
V_32 = V_39 ;
V_10 -> V_2 . V_20 . V_35 ++ ;
V_36 = F_2 ( V_10 -> V_2 . V_4 + V_23 ) ;
V_35 = F_2 ( V_10 -> V_2 . V_4 + V_18 ) ;
if ( F_17 ( & V_10 -> V_2 , ( unsigned char ) V_35 ) )
continue;
if ( V_36 & ( V_40 | V_41 | V_42 ) ) {
if ( V_36 & V_40 )
V_10 -> V_2 . V_20 . V_43 ++ ;
else if ( V_36 & V_42 )
V_10 -> V_2 . V_20 . V_44 ++ ;
if ( V_36 & V_41 )
V_10 -> V_2 . V_20 . V_45 ++ ;
if ( V_36 & V_10 -> V_2 . V_46 ) {
if ( ++ V_33 > 100 )
goto V_30;
continue;
}
V_36 &= V_10 -> V_2 . V_47 ;
if ( V_36 & V_40 )
V_32 = V_48 ;
else if ( V_36 & V_42 )
V_32 = V_49 ;
if ( V_36 & V_41 )
V_32 = V_50 ;
#ifdef F_18
V_10 -> V_2 . V_51 = 0 ;
#endif
}
F_19 ( V_2 , V_35 , V_32 ) ;
}
V_30:
F_15 ( & V_10 -> V_2 . V_28 , V_27 ) ;
F_20 ( V_2 ) ;
return V_31 ;
}
static T_1 F_21 ( int V_25 , void * V_26 )
{
struct V_9 * V_10 = V_26 ;
unsigned char V_52 ;
V_52 = F_2 ( V_10 -> V_2 . V_4 + V_23 ) ;
if ( V_52 & V_53 )
F_16 ( V_25 , V_26 ) ;
if ( V_52 & V_24 &&
! ( F_2 ( V_10 -> V_2 . V_4 + V_54 ) & V_55 ) )
F_12 ( V_25 , V_26 ) ;
return V_31 ;
}
static unsigned int F_22 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 -> V_4 + V_23 ) & V_56 ) ?
V_57 : 0 ;
}
static unsigned int F_23 ( struct V_1 * V_2 )
{
unsigned int V_3 = 0 ;
unsigned char V_58 ;
V_58 = F_2 ( V_2 -> V_4 + V_59 ) ;
if ( V_58 & V_60 )
V_3 |= V_61 ;
if ( V_58 & V_62 )
V_3 |= V_63 ;
return V_3 ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_64 )
{
unsigned char V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_59 ) &
~ ( V_62 | V_60 ) ;
if ( V_64 & V_63 )
V_3 |= V_62 ;
if ( V_64 & V_61 )
V_3 |= V_60 ;
F_3 ( V_3 , V_2 -> V_4 + V_59 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_65 )
{
unsigned char V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) & ~ V_66 ;
if ( V_65 != 0 )
V_3 |= V_66 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static void F_26 ( struct V_9 * V_10 )
{
unsigned char V_67 , V_68 ;
unsigned char V_69 ;
V_68 = F_2 ( V_10 -> V_2 . V_4 + V_5 ) ;
V_69 = V_68 ;
V_68 &= ~ ( V_6 | V_7 | V_70 |
V_71 | V_8 ) ;
F_3 ( V_68 , V_10 -> V_2 . V_4 + V_5 ) ;
V_67 = F_2 ( V_10 -> V_2 . V_4 + V_72 ) ;
V_10 -> V_15 = 0x1 << ( ( ( V_67 >> V_73 ) &
V_74 ) + 1 ) ;
V_10 -> V_75 = 0x1 << ( ( ( V_67 >> V_76 ) &
V_74 ) + 1 ) ;
F_3 ( V_67 | V_77 | V_78 ,
V_10 -> V_2 . V_4 + V_72 ) ;
F_3 ( V_79 | V_80 ,
V_10 -> V_2 . V_4 + V_81 ) ;
F_3 ( 2 , V_10 -> V_2 . V_4 + V_82 ) ;
F_3 ( 1 , V_10 -> V_2 . V_4 + V_83 ) ;
F_3 ( V_69 , V_10 -> V_2 . V_4 + V_5 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_11 ( V_2 , struct V_9 , V_2 ) ;
int V_84 ;
unsigned long V_27 ;
unsigned char V_3 ;
V_84 = F_28 ( V_2 -> V_85 , V_2 -> V_25 , F_21 , 0 ,
V_86 , V_10 ) ;
if ( V_84 )
return V_84 ;
F_13 ( & V_10 -> V_2 . V_28 , V_27 ) ;
F_26 ( V_10 ) ;
V_3 = F_2 ( V_10 -> V_2 . V_4 + V_5 ) ;
V_3 |= ( V_71 | V_6 | V_8 | V_70 ) ;
F_3 ( V_3 , V_10 -> V_2 . V_4 + V_5 ) ;
F_15 ( & V_10 -> V_2 . V_28 , V_27 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_11 ( V_2 , struct V_9 , V_2 ) ;
unsigned char V_3 ;
unsigned long V_27 ;
F_13 ( & V_2 -> V_28 , V_27 ) ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 &= ~ ( V_70 | V_8 |
V_6 | V_7 | V_71 ) ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_15 ( & V_2 -> V_28 , V_27 ) ;
F_30 ( V_2 -> V_85 , V_2 -> V_25 , V_10 ) ;
}
static void
F_31 ( struct V_1 * V_2 , struct V_87 * V_88 ,
struct V_87 * V_89 )
{
struct V_9 * V_10 = F_11 ( V_2 , struct V_9 , V_2 ) ;
unsigned long V_27 ;
unsigned char V_90 , V_91 , V_92 , V_93 , V_94 , V_95 ;
unsigned int V_96 ;
unsigned int V_97 = V_89 ? V_89 -> V_98 & V_99 : V_100 ;
unsigned int V_101 , V_102 ;
V_90 = V_91 = F_2 ( V_10 -> V_2 . V_4 + V_103 ) ;
V_92 = F_2 ( V_10 -> V_2 . V_4 + V_5 ) ;
V_93 = F_2 ( V_10 -> V_2 . V_4 + V_104 ) ;
V_94 = F_2 ( V_10 -> V_2 . V_4 + V_105 ) ;
V_95 = F_2 ( V_10 -> V_2 . V_4 + V_59 ) ;
while ( ( V_88 -> V_98 & V_99 ) != V_100 &&
( V_88 -> V_98 & V_99 ) != V_106 ) {
V_88 -> V_98 &= ~ V_99 ;
V_88 -> V_98 |= V_97 ;
V_97 = V_100 ;
}
if ( ( V_88 -> V_98 & V_99 ) == V_100 ||
( V_88 -> V_98 & V_99 ) == V_106 )
V_90 = V_91 & ~ V_107 ;
if ( V_88 -> V_98 & V_108 ) {
if ( ( V_88 -> V_98 & V_99 ) != V_100 ) {
V_88 -> V_98 &= ~ V_99 ;
V_88 -> V_98 |= V_100 ;
}
V_90 |= V_107 ;
}
if ( V_88 -> V_98 & V_109 ) {
V_95 |= ( V_62 | V_60 ) ;
} else {
V_88 -> V_98 &= ~ V_109 ;
V_95 &= ~ ( V_62 | V_60 ) ;
}
if ( V_88 -> V_98 & V_110 )
V_88 -> V_98 &= ~ V_110 ;
if ( ( V_88 -> V_98 & V_99 ) == V_106 )
V_88 -> V_98 |= V_111 ;
if ( ( V_88 -> V_98 & V_111 ) ) {
if ( V_88 -> V_98 & V_108 ) {
V_90 &= ~ V_112 ;
V_90 |= V_107 ;
} else {
V_90 |= V_112 ;
if ( ( V_88 -> V_98 & V_99 ) == V_100 )
V_90 |= V_107 ;
if ( V_88 -> V_98 & V_113 )
V_90 |= V_114 ;
else
V_90 &= ~ V_114 ;
}
}
V_96 = F_32 ( V_2 , V_88 , V_89 , 50 , V_2 -> V_115 / 16 ) ;
F_13 ( & V_10 -> V_2 . V_28 , V_27 ) ;
V_10 -> V_2 . V_47 = 0 ;
if ( V_88 -> V_116 & V_117 )
V_10 -> V_2 . V_47 |= ( V_42 | V_40 ) ;
if ( V_88 -> V_116 & ( V_118 | V_119 ) )
V_10 -> V_2 . V_47 |= V_42 ;
V_10 -> V_2 . V_46 = 0 ;
if ( V_88 -> V_116 & V_120 )
V_10 -> V_2 . V_46 |= V_40 ;
if ( V_88 -> V_116 & V_121 ) {
V_10 -> V_2 . V_46 |= V_42 ;
if ( V_88 -> V_116 & V_120 )
V_10 -> V_2 . V_46 |= V_41 ;
}
F_33 ( V_2 , V_88 -> V_98 , V_96 ) ;
while ( ! ( F_2 ( V_10 -> V_2 . V_4 + V_23 ) & V_56 ) )
F_34 () ;
F_3 ( V_92 & ~ ( V_70 | V_8 ) ,
V_10 -> V_2 . V_4 + V_5 ) ;
V_101 = V_10 -> V_2 . V_115 / ( 16 * V_96 ) ;
V_102 = ( ( V_10 -> V_2 . V_115 - ( 16 * V_101 * V_96 ) ) * 2 ) / V_96 ;
V_94 &= ~ V_122 ;
V_94 |= ( V_101 >> 8 ) & 0x1F ;
V_93 &= ~ V_123 ;
V_102 &= V_123 ;
F_3 ( V_93 | V_102 , V_10 -> V_2 . V_4 + V_104 ) ;
F_3 ( V_94 , V_10 -> V_2 . V_4 + V_105 ) ;
F_3 ( V_101 & 0xFF , V_10 -> V_2 . V_4 + V_124 ) ;
F_3 ( V_90 , V_10 -> V_2 . V_4 + V_103 ) ;
F_3 ( V_95 , V_10 -> V_2 . V_4 + V_59 ) ;
F_3 ( V_92 , V_10 -> V_2 . V_4 + V_5 ) ;
F_15 ( & V_10 -> V_2 . V_28 , V_27 ) ;
}
static const char * F_35 ( struct V_1 * V_2 )
{
return L_1 ;
}
static void F_36 ( struct V_1 * V_2 )
{
}
static int F_37 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , int V_27 )
{
if ( V_27 & V_125 )
V_2 -> type = V_126 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_127 * V_128 )
{
int V_84 = 0 ;
if ( V_128 -> type != V_129 && V_128 -> type != V_126 )
V_84 = - V_130 ;
if ( V_2 -> V_25 != V_128 -> V_25 )
V_84 = - V_130 ;
if ( V_128 -> V_131 != V_132 )
V_84 = - V_130 ;
if ( V_2 -> V_115 / 16 != V_128 -> V_133 )
V_84 = - V_130 ;
if ( V_2 -> V_134 != V_128 -> V_2 )
V_84 = - V_130 ;
if ( V_128 -> V_135 != 0 )
V_84 = - V_130 ;
return V_84 ;
}
static void F_40 ( struct V_1 * V_2 , int V_136 )
{
while ( ! ( F_2 ( V_2 -> V_4 + V_23 ) & V_24 ) )
F_34 () ;
F_3 ( V_136 , V_2 -> V_4 + V_18 ) ;
}
static void
F_41 ( struct V_137 * V_138 , const char * V_139 , unsigned int V_140 )
{
struct V_9 * V_10 = V_141 [ V_138 -> V_142 ] ;
unsigned char V_92 , V_68 ;
V_68 = V_92 = F_2 ( V_10 -> V_2 . V_4 + V_5 ) ;
V_68 |= ( V_70 | V_8 ) ;
V_68 &= ~ ( V_6 | V_7 | V_71 ) ;
F_3 ( V_68 , V_10 -> V_2 . V_4 + V_5 ) ;
F_42 ( & V_10 -> V_2 , V_139 , V_140 , F_40 ) ;
while ( ! ( F_2 ( V_10 -> V_2 . V_4 + V_23 ) & V_56 ) )
F_34 () ;
F_3 ( V_92 , V_10 -> V_2 . V_4 + V_5 ) ;
}
static void T_2
F_43 ( struct V_9 * V_10 , int * V_96 ,
int * V_43 , int * V_143 )
{
unsigned char V_144 , V_94 , V_145 , V_102 ;
unsigned int V_101 , V_115 , V_146 ;
V_144 = F_2 ( V_10 -> V_2 . V_4 + V_5 ) ;
V_144 &= V_70 | V_8 ;
if ( ! V_144 )
return;
V_144 = F_2 ( V_10 -> V_2 . V_4 + V_103 ) ;
* V_43 = 'n' ;
if ( V_144 & V_112 ) {
if ( V_144 & V_114 )
* V_43 = 'o' ;
else
* V_43 = 'e' ;
}
if ( V_144 & V_107 )
* V_143 = 9 ;
else
* V_143 = 8 ;
V_94 = F_2 ( V_10 -> V_2 . V_4 + V_105 ) ;
V_94 &= V_122 ;
V_145 = F_2 ( V_10 -> V_2 . V_4 + V_124 ) ;
V_101 = V_94 ;
V_101 <<= 8 ;
V_101 |= V_145 ;
V_102 = F_2 ( V_10 -> V_2 . V_4 + V_104 ) ;
V_102 &= V_123 ;
V_115 = F_44 ( V_10 -> V_147 ) ;
V_146 = V_115 / ( 16 * ( V_101 + V_102 / 32 ) ) ;
if ( * V_96 != V_146 )
F_45 ( V_148 L_2
L_3 , V_146 , * V_96 ) ;
}
static int T_2 F_46 ( struct V_137 * V_138 , char * V_149 )
{
struct V_9 * V_10 ;
int V_96 = 115200 ;
int V_143 = 8 ;
int V_43 = 'n' ;
int V_150 = 'n' ;
if ( V_138 -> V_142 == - 1 || V_138 -> V_142 >= F_47 ( V_141 ) )
V_138 -> V_142 = 0 ;
V_10 = V_141 [ V_138 -> V_142 ] ;
if ( V_10 == NULL )
return - V_151 ;
if ( V_149 )
F_48 ( V_149 , & V_96 , & V_43 , & V_143 , & V_150 ) ;
else
F_43 ( V_10 , & V_96 , & V_43 , & V_143 ) ;
F_26 ( V_10 ) ;
return F_49 ( & V_10 -> V_2 , V_138 , V_96 , V_43 , V_143 , V_150 ) ;
}
static int F_50 ( struct V_152 * V_153 )
{
struct V_154 * V_155 = V_153 -> V_85 . V_156 ;
struct V_9 * V_10 ;
struct V_157 * V_158 ;
int V_84 ;
V_10 = F_51 ( & V_153 -> V_85 , sizeof( * V_10 ) , V_159 ) ;
if ( ! V_10 )
return - V_160 ;
V_153 -> V_85 . V_161 = 0 ;
V_84 = F_52 ( V_155 , L_4 ) ;
if ( V_84 < 0 ) {
F_53 ( & V_153 -> V_85 , L_5 , V_84 ) ;
return V_84 ;
}
V_10 -> V_2 . line = V_84 ;
V_158 = F_54 ( V_153 , V_162 , 0 ) ;
if ( ! V_158 )
return - V_151 ;
V_10 -> V_2 . V_163 = V_158 -> V_164 ;
V_10 -> V_2 . V_4 = F_55 ( & V_153 -> V_85 , V_158 ) ;
if ( F_56 ( V_10 -> V_2 . V_4 ) )
return F_57 ( V_10 -> V_2 . V_4 ) ;
V_10 -> V_2 . V_85 = & V_153 -> V_85 ;
V_10 -> V_2 . type = V_126 ;
V_10 -> V_2 . V_165 = V_132 ;
V_10 -> V_2 . V_25 = F_58 ( V_153 , 0 ) ;
V_10 -> V_2 . V_166 = & V_167 ;
V_10 -> V_2 . V_27 = V_168 ;
V_10 -> V_147 = F_59 ( & V_153 -> V_85 , L_6 ) ;
if ( F_56 ( V_10 -> V_147 ) ) {
V_84 = F_57 ( V_10 -> V_147 ) ;
F_53 ( & V_153 -> V_85 , L_7 , V_84 ) ;
return V_84 ;
}
V_84 = F_60 ( V_10 -> V_147 ) ;
if ( V_84 ) {
F_53 ( & V_153 -> V_85 , L_8 , V_84 ) ;
return V_84 ;
}
V_10 -> V_2 . V_115 = F_44 ( V_10 -> V_147 ) ;
V_141 [ V_10 -> V_2 . line ] = V_10 ;
F_61 ( V_153 , & V_10 -> V_2 ) ;
V_84 = F_62 ( & V_169 , & V_10 -> V_2 ) ;
if ( V_84 ) {
F_63 ( V_10 -> V_147 ) ;
return V_84 ;
}
return 0 ;
}
static int F_64 ( struct V_152 * V_153 )
{
struct V_9 * V_10 = F_65 ( V_153 ) ;
F_66 ( & V_169 , & V_10 -> V_2 ) ;
F_63 ( V_10 -> V_147 ) ;
return 0 ;
}
static int F_67 ( struct V_170 * V_85 )
{
struct V_9 * V_10 = F_68 ( V_85 ) ;
F_69 ( & V_169 , & V_10 -> V_2 ) ;
return 0 ;
}
static int F_70 ( struct V_170 * V_85 )
{
struct V_9 * V_10 = F_68 ( V_85 ) ;
F_71 ( & V_169 , & V_10 -> V_2 ) ;
return 0 ;
}
static int T_2 F_72 ( void )
{
int V_84 ;
F_73 ( L_9 ) ;
V_84 = F_74 ( & V_169 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_75 ( & V_171 ) ;
if ( V_84 )
F_76 ( & V_169 ) ;
return V_84 ;
}
static void T_3 F_77 ( void )
{
F_78 ( & V_171 ) ;
F_76 ( & V_169 ) ;
}

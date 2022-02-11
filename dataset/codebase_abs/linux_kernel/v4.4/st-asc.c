static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_2 * V_3 , T_1 V_4 )
{
#ifdef F_4
return F_4 ( V_3 -> V_5 + V_4 ) ;
#else
return F_5 ( V_3 -> V_5 + V_4 ) ;
#endif
}
static inline void F_6 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_6 )
{
#ifdef F_7
F_7 ( V_6 , V_3 -> V_5 + V_4 ) ;
#else
F_8 ( V_6 , V_3 -> V_5 + V_4 ) ;
#endif
}
static inline void F_9 ( struct V_2 * V_3 )
{
T_1 V_7 = F_3 ( V_3 , V_8 ) & ~ V_9 ;
F_6 ( V_3 , V_8 , V_7 ) ;
( void ) F_3 ( V_3 , V_8 ) ;
}
static inline void F_10 ( struct V_2 * V_3 )
{
T_1 V_7 = F_3 ( V_3 , V_8 ) | V_9 ;
F_6 ( V_3 , V_8 , V_7 ) ;
}
static inline void F_11 ( struct V_2 * V_3 )
{
T_1 V_7 = F_3 ( V_3 , V_8 ) & ~ V_10 ;
F_6 ( V_3 , V_8 , V_7 ) ;
( void ) F_3 ( V_3 , V_8 ) ;
}
static inline void F_12 ( struct V_2 * V_3 )
{
T_1 V_7 = F_3 ( V_3 , V_8 ) | V_10 ;
F_6 ( V_3 , V_8 , V_7 ) ;
}
static inline T_1 F_13 ( struct V_2 * V_3 )
{
return F_3 ( V_3 , V_11 ) & V_12 ;
}
static inline T_1 F_14 ( struct V_2 * V_3 )
{
return F_3 ( V_3 , V_11 ) & V_13 ;
}
static inline const char * F_15 ( struct V_2 * V_3 )
{
return F_16 ( V_3 -> V_14 ) -> V_15 ;
}
static inline unsigned F_17 ( struct V_2 * V_3 )
{
T_1 V_16 = F_3 ( V_3 , V_11 ) ;
if ( V_16 & V_13 )
return V_3 -> V_17 / 2 ;
else if ( ! ( V_16 & V_18 ) )
return 1 ;
return 0 ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = & V_3 -> V_21 -> V_20 ;
int V_22 ;
unsigned char V_23 ;
V_22 = F_17 ( V_3 ) ;
if ( ( V_22 != 0 ) && V_3 -> V_24 ) {
V_23 = V_3 -> V_24 ;
V_3 -> V_24 = 0 ;
F_6 ( V_3 , V_25 , V_23 ) ;
V_3 -> V_26 . V_27 ++ ;
V_22 = F_17 ( V_3 ) ;
}
if ( F_19 ( V_3 ) ) {
F_9 ( V_3 ) ;
return;
}
if ( F_20 ( V_20 ) ) {
F_9 ( V_3 ) ;
return;
}
if ( V_22 == 0 )
return;
do {
V_23 = V_20 -> V_28 [ V_20 -> V_29 ] ;
V_20 -> V_29 = ( V_20 -> V_29 + 1 ) & ( V_30 - 1 ) ;
F_6 ( V_3 , V_25 , V_23 ) ;
V_3 -> V_26 . V_27 ++ ;
V_22 -- ;
} while ( ( V_22 > 0 ) && ( ! F_20 ( V_20 ) ) );
if ( F_21 ( V_20 ) < V_31 )
F_22 ( V_3 ) ;
if ( F_20 ( V_20 ) )
F_9 ( V_3 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_32 * V_33 = & V_3 -> V_21 -> V_3 ;
unsigned long V_16 ;
unsigned long V_23 = 0 ;
char V_34 ;
if ( V_3 -> V_35 )
F_24 ( V_33 -> V_36 -> V_14 , 0 ) ;
while ( ( V_16 = F_3 ( V_3 , V_11 ) ) & V_37 ) {
V_23 = F_3 ( V_3 , V_38 ) | V_39 ;
V_34 = V_40 ;
V_3 -> V_26 . V_41 ++ ;
if ( ( V_23 & ( V_42 | V_43 ) ) ||
V_16 & V_44 ) {
if ( V_23 & V_42 ) {
if ( V_23 == ( V_42 | V_39 ) ) {
V_3 -> V_26 . V_45 ++ ;
if ( F_25 ( V_3 ) )
continue;
V_23 |= V_46 ;
} else {
V_3 -> V_26 . V_47 ++ ;
}
} else if ( V_23 & V_43 ) {
V_3 -> V_26 . V_48 ++ ;
}
if ( V_16 & V_44 ) {
V_3 -> V_26 . V_49 ++ ;
V_23 |= V_50 ;
}
V_23 &= V_3 -> V_51 ;
if ( V_23 & V_46 )
V_34 = V_52 ;
else if ( V_23 & V_43 )
V_34 = V_53 ;
else if ( V_23 & V_42 )
V_34 = V_54 ;
}
if ( F_26 ( V_3 , V_23 & 0xff ) )
continue;
F_27 ( V_3 , V_23 , V_50 , V_23 & 0xff , V_34 ) ;
}
F_28 ( V_33 ) ;
}
static T_2 F_29 ( int V_55 , void * V_56 )
{
struct V_2 * V_3 = V_56 ;
T_1 V_16 ;
F_30 ( & V_3 -> V_57 ) ;
V_16 = F_3 ( V_3 , V_11 ) ;
if ( V_16 & V_37 ) {
F_23 ( V_3 ) ;
}
if ( ( V_16 & V_13 ) &&
( F_3 ( V_3 , V_8 ) & V_9 ) ) {
F_18 ( V_3 ) ;
}
F_31 ( & V_3 -> V_57 ) ;
return V_58 ;
}
static unsigned int F_32 ( struct V_2 * V_3 )
{
return F_13 ( V_3 ) ? V_59 : 0 ;
}
static void F_33 ( struct V_2 * V_3 , unsigned int V_60 )
{
}
static unsigned int F_34 ( struct V_2 * V_3 )
{
return V_61 | V_62 | V_63 ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = & V_3 -> V_21 -> V_20 ;
if ( ! F_20 ( V_20 ) )
F_10 ( V_3 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
F_9 ( V_3 ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
F_11 ( V_3 ) ;
}
static void F_38 ( struct V_2 * V_3 , int V_64 )
{
}
static int F_39 ( struct V_2 * V_3 )
{
if ( F_40 ( V_3 -> V_55 , F_29 , 0 ,
F_15 ( V_3 ) , V_3 ) ) {
F_41 ( V_3 -> V_14 , L_1 ) ;
return - V_65 ;
}
F_18 ( V_3 ) ;
F_12 ( V_3 ) ;
return 0 ;
}
static void F_42 ( struct V_2 * V_3 )
{
F_9 ( V_3 ) ;
F_11 ( V_3 ) ;
F_43 ( V_3 -> V_55 , V_3 ) ;
}
static void F_44 ( struct V_2 * V_3 , unsigned int V_21 ,
unsigned int V_66 )
{
struct V_1 * V_67 = F_1 ( V_3 ) ;
unsigned long V_68 = 0 ;
T_1 V_69 ;
switch ( V_21 ) {
case V_70 :
F_45 ( V_67 -> V_71 ) ;
break;
case V_72 :
F_46 ( & V_3 -> V_57 , V_68 ) ;
V_69 = F_3 ( V_3 , V_73 ) & ~ V_74 ;
F_6 ( V_3 , V_73 , V_69 ) ;
F_47 ( & V_3 -> V_57 , V_68 ) ;
F_48 ( V_67 -> V_71 ) ;
break;
}
}
static void F_49 ( struct V_2 * V_3 , struct V_75 * V_76 ,
struct V_75 * V_77 )
{
struct V_1 * V_67 = F_1 ( V_3 ) ;
unsigned int V_78 ;
T_1 V_79 ;
T_3 V_80 ;
unsigned long V_68 ;
V_76 -> V_81 &= ~ ( V_82 |
( V_67 -> V_83 ? 0 : V_84 ) ) ;
V_3 -> V_85 = F_50 ( V_67 -> V_71 ) ;
V_78 = F_51 ( V_3 , V_76 , V_77 , 0 , V_3 -> V_85 / 16 ) ;
V_80 = V_76 -> V_81 ;
F_46 ( & V_3 -> V_57 , V_68 ) ;
V_79 = F_3 ( V_3 , V_73 ) ;
F_6 ( V_3 , V_73 , ( V_79 & ~ V_74 ) ) ;
V_79 = V_86 | V_87 ;
F_6 ( V_3 , V_88 , 1 ) ;
F_6 ( V_3 , V_89 , 1 ) ;
if ( ( V_80 & V_90 ) == V_91 ) {
V_79 |= V_92 ;
} else {
V_79 |= ( V_80 & V_93 ) ? V_94 :
V_95 ;
}
V_79 |= ( V_80 & V_96 ) ? V_97 : V_98 ;
if ( V_80 & V_99 )
V_79 |= V_100 ;
if ( ( V_80 & V_84 ) )
V_79 |= V_101 ;
if ( ( V_78 < 19200 ) && ! V_67 -> V_102 ) {
F_6 ( V_3 , V_103 , ( V_3 -> V_85 / ( 16 * V_78 ) ) ) ;
} else {
T_4 V_104 = ( T_4 ) V_78 * ( 1 << 16 ) ;
F_52 ( V_104 , V_3 -> V_85 / 16 ) ;
F_6 ( V_3 , V_103 , V_104 ) ;
V_79 |= V_105 ;
}
F_53 ( V_3 , V_80 , V_78 ) ;
V_67 -> V_3 . V_51 = V_50 ;
if ( V_76 -> V_106 & V_107 )
V_67 -> V_3 . V_51 |= V_42 | V_43 ;
if ( V_76 -> V_106 & ( V_108 | V_109 | V_110 ) )
V_67 -> V_3 . V_51 |= V_46 ;
V_67 -> V_3 . V_111 = 0 ;
if ( V_76 -> V_106 & V_112 )
V_67 -> V_3 . V_111 |= V_42 | V_43 ;
if ( V_76 -> V_106 & V_108 ) {
V_67 -> V_3 . V_111 |= V_46 ;
if ( V_76 -> V_106 & V_112 )
V_67 -> V_3 . V_111 |= V_50 ;
}
if ( ! ( V_76 -> V_81 & V_113 ) )
V_67 -> V_3 . V_111 |= V_39 ;
F_6 ( V_3 , V_114 , 20 ) ;
F_6 ( V_3 , V_73 , ( V_79 | V_74 ) ) ;
F_47 ( & V_3 -> V_57 , V_68 ) ;
}
static const char * F_54 ( struct V_2 * V_3 )
{
return ( V_3 -> type == V_115 ) ? V_116 : NULL ;
}
static void F_55 ( struct V_2 * V_3 )
{
}
static int F_56 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_57 ( struct V_2 * V_3 , int V_68 )
{
if ( ( V_68 & V_117 ) )
V_3 -> type = V_115 ;
}
static int
F_58 ( struct V_2 * V_3 , struct V_118 * V_119 )
{
return - V_120 ;
}
static int F_59 ( struct V_2 * V_3 )
{
if ( ! ( F_3 ( V_3 , V_11 ) & V_37 ) )
return V_121 ;
return F_3 ( V_3 , V_38 ) ;
}
static void F_60 ( struct V_2 * V_3 , unsigned char V_23 )
{
while ( ! F_14 ( V_3 ) )
F_61 () ;
F_6 ( V_3 , V_25 , V_23 ) ;
}
static int F_62 ( struct V_1 * V_67 ,
struct V_122 * V_123 )
{
struct V_2 * V_3 = & V_67 -> V_3 ;
struct V_124 * V_125 ;
V_3 -> V_126 = V_127 ;
V_3 -> V_68 = V_128 ;
V_3 -> V_129 = & V_130 ;
V_3 -> V_17 = V_131 ;
V_3 -> V_14 = & V_123 -> V_14 ;
V_3 -> V_55 = F_63 ( V_123 , 0 ) ;
V_125 = F_64 ( V_123 , V_132 , 0 ) ;
V_3 -> V_5 = F_65 ( & V_123 -> V_14 , V_125 ) ;
if ( F_66 ( V_3 -> V_5 ) )
return F_67 ( V_3 -> V_5 ) ;
V_3 -> V_133 = V_125 -> V_134 ;
F_68 ( & V_3 -> V_57 ) ;
V_67 -> V_71 = F_69 ( & V_123 -> V_14 , NULL ) ;
if ( F_70 ( F_66 ( V_67 -> V_71 ) ) )
return - V_120 ;
F_45 ( V_67 -> V_71 ) ;
V_67 -> V_3 . V_85 = F_50 ( V_67 -> V_71 ) ;
F_70 ( V_67 -> V_3 . V_85 == 0 ) ;
F_48 ( V_67 -> V_71 ) ;
return 0 ;
}
static struct V_1 * F_71 ( struct V_122 * V_123 )
{
struct V_135 * V_136 = V_123 -> V_14 . V_137 ;
int V_138 ;
if ( ! V_136 )
return NULL ;
V_138 = F_72 ( V_136 , V_139 ) ;
if ( V_138 < 0 )
V_138 = 0 ;
if ( F_70 ( V_138 >= V_140 ) )
return NULL ;
V_141 [ V_138 ] . V_83 = F_73 ( V_136 ,
L_2 ) ;
V_141 [ V_138 ] . V_102 = F_73 ( V_136 , L_3 ) ;
V_141 [ V_138 ] . V_3 . line = V_138 ;
return & V_141 [ V_138 ] ;
}
static int F_74 ( struct V_122 * V_123 )
{
int V_142 ;
struct V_1 * V_67 ;
V_67 = F_71 ( V_123 ) ;
if ( ! V_67 )
return - V_65 ;
V_142 = F_62 ( V_67 , V_123 ) ;
if ( V_142 )
return V_142 ;
V_142 = F_75 ( & V_143 , & V_67 -> V_3 ) ;
if ( V_142 )
return V_142 ;
F_76 ( V_123 , & V_67 -> V_3 ) ;
return 0 ;
}
static int F_77 ( struct V_122 * V_123 )
{
struct V_2 * V_3 = F_78 ( V_123 ) ;
return F_79 ( & V_143 , V_3 ) ;
}
static int F_80 ( struct V_144 * V_14 )
{
struct V_122 * V_123 = F_16 ( V_14 ) ;
struct V_2 * V_3 = F_78 ( V_123 ) ;
return F_81 ( & V_143 , V_3 ) ;
}
static int F_82 ( struct V_144 * V_14 )
{
struct V_122 * V_123 = F_16 ( V_14 ) ;
struct V_2 * V_3 = F_78 ( V_123 ) ;
return F_83 ( & V_143 , V_3 ) ;
}
static void F_84 ( struct V_2 * V_3 , int V_145 )
{
unsigned int V_146 = 1000000 ;
while ( -- V_146 && ! F_14 ( V_3 ) )
F_85 ( 1 ) ;
F_6 ( V_3 , V_25 , V_145 ) ;
}
static void F_86 ( struct V_147 * V_148 , const char * V_149 , unsigned V_150 )
{
struct V_2 * V_3 = & V_141 [ V_148 -> V_151 ] . V_3 ;
unsigned long V_68 ;
unsigned long V_146 = 1000000 ;
int V_152 = 1 ;
T_1 V_7 ;
F_87 ( V_68 ) ;
if ( V_3 -> V_153 )
V_152 = 0 ;
else if ( V_154 )
V_152 = F_88 ( & V_3 -> V_57 ) ;
else
F_30 ( & V_3 -> V_57 ) ;
V_7 = F_3 ( V_3 , V_8 ) ;
F_6 ( V_3 , V_8 , 0 ) ;
( void ) F_3 ( V_3 , V_8 ) ;
F_89 ( V_3 , V_149 , V_150 , F_84 ) ;
while ( -- V_146 && ! F_13 ( V_3 ) )
F_85 ( 1 ) ;
F_6 ( V_3 , V_8 , V_7 ) ;
if ( V_152 )
F_31 ( & V_3 -> V_57 ) ;
F_90 ( V_68 ) ;
}
static int F_91 ( struct V_147 * V_148 , char * V_155 )
{
struct V_1 * V_67 ;
int V_78 = 9600 ;
int V_156 = 8 ;
int V_48 = 'n' ;
int V_157 = 'n' ;
if ( V_148 -> V_151 >= V_140 )
return - V_65 ;
V_67 = & V_141 [ V_148 -> V_151 ] ;
if ( V_67 -> V_3 . V_133 == 0 || V_67 -> V_3 . V_5 == NULL )
return - V_158 ;
if ( V_155 )
F_92 ( V_155 , & V_78 , & V_48 , & V_156 , & V_157 ) ;
return F_93 ( & V_67 -> V_3 , V_148 , V_78 , V_48 , V_156 , V_157 ) ;
}
static int T_5 F_94 ( void )
{
int V_142 ;
static char V_159 [] V_160 =
V_161 L_4 ;
F_95 ( V_159 ) ;
V_142 = F_96 ( & V_143 ) ;
if ( V_142 )
return V_142 ;
V_142 = F_97 ( & V_162 ) ;
if ( V_142 )
F_98 ( & V_143 ) ;
return V_142 ;
}
static void T_6 F_99 ( void )
{
F_100 ( & V_162 ) ;
F_98 ( & V_143 ) ;
}

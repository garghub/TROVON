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
unsigned long V_16 , V_34 ;
unsigned long V_23 = 0 ;
char V_35 ;
bool V_36 = false ;
V_34 = F_3 ( V_3 , V_37 ) & V_38 ;
if ( V_34 == V_39 || V_34 == V_40 )
V_36 = true ;
if ( F_24 ( F_25 ( V_3 -> V_41 ) ) )
F_26 ( V_33 -> V_42 -> V_14 , 0 ) ;
while ( ( V_16 = F_3 ( V_3 , V_11 ) ) & V_43 ) {
V_23 = F_3 ( V_3 , V_44 ) | V_45 ;
V_35 = V_46 ;
V_3 -> V_26 . V_47 ++ ;
if ( V_16 & V_48 || V_23 & V_49 ||
( V_23 & V_50 && ! V_36 ) ) {
if ( V_23 & V_49 ) {
if ( V_23 == ( V_49 | V_45 ) ) {
V_3 -> V_26 . V_51 ++ ;
if ( F_27 ( V_3 ) )
continue;
V_23 |= V_52 ;
} else {
V_3 -> V_26 . V_53 ++ ;
}
} else if ( V_23 & V_50 ) {
V_3 -> V_26 . V_54 ++ ;
}
if ( V_16 & V_48 ) {
V_3 -> V_26 . V_55 ++ ;
V_23 |= V_56 ;
}
V_23 &= V_3 -> V_57 ;
if ( V_23 & V_52 )
V_35 = V_58 ;
else if ( V_23 & V_50 )
V_35 = V_59 ;
else if ( V_23 & V_49 )
V_35 = V_60 ;
}
if ( F_28 ( V_3 , V_23 & 0xff ) )
continue;
F_29 ( V_3 , V_23 , V_56 , V_23 & 0xff , V_35 ) ;
}
F_30 ( V_33 ) ;
}
static T_2 F_31 ( int V_41 , void * V_61 )
{
struct V_2 * V_3 = V_61 ;
T_1 V_16 ;
F_32 ( & V_3 -> V_62 ) ;
V_16 = F_3 ( V_3 , V_11 ) ;
if ( V_16 & V_43 ) {
F_23 ( V_3 ) ;
}
if ( ( V_16 & V_13 ) &&
( F_3 ( V_3 , V_8 ) & V_9 ) ) {
F_18 ( V_3 ) ;
}
F_33 ( & V_3 -> V_62 ) ;
return V_63 ;
}
static unsigned int F_34 ( struct V_2 * V_3 )
{
return F_13 ( V_3 ) ? V_64 : 0 ;
}
static void F_35 ( struct V_2 * V_3 , unsigned int V_65 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
if ( ! V_66 -> V_67 )
return;
if ( F_3 ( V_3 , V_37 ) & V_68 )
return;
F_36 ( V_66 -> V_67 , V_65 & V_69 ) ;
}
static unsigned int F_37 ( struct V_2 * V_3 )
{
return V_70 | V_71 | V_72 ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = & V_3 -> V_21 -> V_20 ;
if ( ! F_20 ( V_20 ) )
F_10 ( V_3 ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
F_9 ( V_3 ) ;
}
static void F_40 ( struct V_2 * V_3 )
{
F_11 ( V_3 ) ;
}
static void F_41 ( struct V_2 * V_3 , int V_73 )
{
}
static int F_42 ( struct V_2 * V_3 )
{
if ( F_43 ( V_3 -> V_41 , F_31 , 0 ,
F_15 ( V_3 ) , V_3 ) ) {
F_44 ( V_3 -> V_14 , L_1 ) ;
return - V_74 ;
}
F_18 ( V_3 ) ;
F_12 ( V_3 ) ;
return 0 ;
}
static void F_45 ( struct V_2 * V_3 )
{
F_9 ( V_3 ) ;
F_11 ( V_3 ) ;
F_46 ( V_3 -> V_41 , V_3 ) ;
}
static void F_47 ( struct V_2 * V_3 , unsigned int V_21 ,
unsigned int V_75 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
unsigned long V_76 = 0 ;
T_1 V_77 ;
switch ( V_21 ) {
case V_78 :
F_48 ( V_66 -> V_79 ) ;
break;
case V_80 :
F_49 ( & V_3 -> V_62 , V_76 ) ;
V_77 = F_3 ( V_3 , V_37 ) & ~ V_81 ;
F_6 ( V_3 , V_37 , V_77 ) ;
F_50 ( & V_3 -> V_62 , V_76 ) ;
F_51 ( V_66 -> V_79 ) ;
break;
}
}
static void F_52 ( struct V_2 * V_3 , struct V_82 * V_83 ,
struct V_82 * V_84 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
struct V_85 * V_86 = V_3 -> V_14 -> V_87 ;
struct V_88 * V_89 ;
unsigned int V_90 ;
T_1 V_91 ;
T_3 V_92 ;
unsigned long V_76 ;
V_83 -> V_93 &= ~ ( V_94 |
( V_66 -> V_95 ? 0 : V_96 ) ) ;
V_3 -> V_97 = F_53 ( V_66 -> V_79 ) ;
V_90 = F_54 ( V_3 , V_83 , V_84 , 0 , V_3 -> V_97 / 16 ) ;
V_92 = V_83 -> V_93 ;
F_49 ( & V_3 -> V_62 , V_76 ) ;
V_91 = F_3 ( V_3 , V_37 ) ;
F_6 ( V_3 , V_37 , ( V_91 & ~ V_81 ) ) ;
V_91 = V_98 | V_99 ;
F_6 ( V_3 , V_100 , 1 ) ;
F_6 ( V_3 , V_101 , 1 ) ;
if ( ( V_92 & V_102 ) == V_103 ) {
V_91 |= V_104 ;
} else {
V_91 |= ( V_92 & V_105 ) ? V_40 :
V_39 ;
}
V_91 |= ( V_92 & V_106 ) ? V_107 : V_108 ;
if ( V_92 & V_109 )
V_91 |= V_110 ;
if ( ( V_92 & V_96 ) ) {
V_91 |= V_68 ;
if ( V_66 -> V_67 ) {
F_55 ( V_3 -> V_14 , V_66 -> V_67 ) ;
V_66 -> V_67 = NULL ;
F_56 ( V_66 -> V_111 ,
V_66 -> V_112 [ DEFAULT ] ) ;
}
} else {
if ( ! V_66 -> V_67 && V_66 -> V_112 [ V_113 ] ) {
F_56 ( V_66 -> V_111 ,
V_66 -> V_112 [ V_113 ] ) ;
V_89 = F_57 ( V_3 -> V_14 ,
L_2 ,
& V_86 -> V_114 ,
V_115 ,
V_86 -> V_15 ) ;
if ( ! F_58 ( V_89 ) )
V_66 -> V_67 = V_89 ;
}
}
if ( ( V_90 < 19200 ) && ! V_66 -> V_116 ) {
F_6 ( V_3 , V_117 , ( V_3 -> V_97 / ( 16 * V_90 ) ) ) ;
} else {
T_4 V_118 = ( T_4 ) V_90 * ( 1 << 16 ) ;
F_59 ( V_118 , V_3 -> V_97 / 16 ) ;
F_6 ( V_3 , V_117 , V_118 ) ;
V_91 |= V_119 ;
}
F_60 ( V_3 , V_92 , V_90 ) ;
V_66 -> V_3 . V_57 = V_56 ;
if ( V_83 -> V_120 & V_121 )
V_66 -> V_3 . V_57 |= V_49 | V_50 ;
if ( V_83 -> V_120 & ( V_122 | V_123 | V_124 ) )
V_66 -> V_3 . V_57 |= V_52 ;
V_66 -> V_3 . V_125 = 0 ;
if ( V_83 -> V_120 & V_126 )
V_66 -> V_3 . V_125 |= V_49 | V_50 ;
if ( V_83 -> V_120 & V_122 ) {
V_66 -> V_3 . V_125 |= V_52 ;
if ( V_83 -> V_120 & V_126 )
V_66 -> V_3 . V_125 |= V_56 ;
}
if ( ! ( V_83 -> V_93 & V_127 ) )
V_66 -> V_3 . V_125 |= V_45 ;
F_6 ( V_3 , V_128 , 20 ) ;
F_6 ( V_3 , V_37 , ( V_91 | V_81 ) ) ;
F_50 ( & V_3 -> V_62 , V_76 ) ;
}
static const char * F_61 ( struct V_2 * V_3 )
{
return ( V_3 -> type == V_129 ) ? V_130 : NULL ;
}
static void F_62 ( struct V_2 * V_3 )
{
}
static int F_63 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_64 ( struct V_2 * V_3 , int V_76 )
{
if ( ( V_76 & V_131 ) )
V_3 -> type = V_129 ;
}
static int
F_65 ( struct V_2 * V_3 , struct V_132 * V_133 )
{
return - V_134 ;
}
static int F_66 ( struct V_2 * V_3 )
{
if ( ! ( F_3 ( V_3 , V_11 ) & V_43 ) )
return V_135 ;
return F_3 ( V_3 , V_44 ) ;
}
static void F_67 ( struct V_2 * V_3 , unsigned char V_23 )
{
while ( ! F_14 ( V_3 ) )
F_68 () ;
F_6 ( V_3 , V_25 , V_23 ) ;
}
static int F_69 ( struct V_1 * V_66 ,
struct V_136 * V_137 )
{
struct V_2 * V_3 = & V_66 -> V_3 ;
struct V_138 * V_139 ;
int V_140 ;
V_3 -> V_141 = V_142 ;
V_3 -> V_76 = V_143 ;
V_3 -> V_144 = & V_145 ;
V_3 -> V_17 = V_146 ;
V_3 -> V_14 = & V_137 -> V_14 ;
V_3 -> V_41 = F_70 ( V_137 , 0 ) ;
V_139 = F_71 ( V_137 , V_147 , 0 ) ;
V_3 -> V_5 = F_72 ( & V_137 -> V_14 , V_139 ) ;
if ( F_58 ( V_3 -> V_5 ) )
return F_73 ( V_3 -> V_5 ) ;
V_3 -> V_148 = V_139 -> V_149 ;
F_74 ( & V_3 -> V_62 ) ;
V_66 -> V_79 = F_75 ( & V_137 -> V_14 , NULL ) ;
if ( F_76 ( F_58 ( V_66 -> V_79 ) ) )
return - V_134 ;
F_48 ( V_66 -> V_79 ) ;
V_66 -> V_3 . V_97 = F_53 ( V_66 -> V_79 ) ;
F_76 ( V_66 -> V_3 . V_97 == 0 ) ;
F_51 ( V_66 -> V_79 ) ;
V_66 -> V_111 = F_77 ( & V_137 -> V_14 ) ;
if ( F_58 ( V_66 -> V_111 ) ) {
V_140 = F_73 ( V_66 -> V_111 ) ;
F_44 ( & V_137 -> V_14 , L_3 , V_140 ) ;
return V_140 ;
}
V_66 -> V_112 [ DEFAULT ] =
F_78 ( V_66 -> V_111 , L_4 ) ;
if ( F_58 ( V_66 -> V_112 [ DEFAULT ] ) ) {
V_140 = F_73 ( V_66 -> V_112 [ DEFAULT ] ) ;
F_44 ( & V_137 -> V_14 ,
L_5 , V_140 ) ;
return V_140 ;
}
V_66 -> V_112 [ V_113 ] =
F_78 ( V_66 -> V_111 , L_6 ) ;
if ( F_58 ( V_66 -> V_112 [ V_113 ] ) )
V_66 -> V_112 [ V_113 ] = NULL ;
return 0 ;
}
static struct V_1 * F_79 ( struct V_136 * V_137 )
{
struct V_85 * V_86 = V_137 -> V_14 . V_87 ;
int V_150 ;
if ( ! V_86 )
return NULL ;
V_150 = F_80 ( V_86 , V_151 ) ;
if ( V_150 < 0 )
V_150 = 0 ;
if ( F_76 ( V_150 >= V_152 ) )
return NULL ;
V_153 [ V_150 ] . V_95 = F_81 ( V_86 ,
L_7 ) ;
V_153 [ V_150 ] . V_116 = F_81 ( V_86 , L_8 ) ;
V_153 [ V_150 ] . V_3 . line = V_150 ;
V_153 [ V_150 ] . V_67 = NULL ;
return & V_153 [ V_150 ] ;
}
static int F_82 ( struct V_136 * V_137 )
{
int V_140 ;
struct V_1 * V_66 ;
V_66 = F_79 ( V_137 ) ;
if ( ! V_66 )
return - V_74 ;
V_140 = F_69 ( V_66 , V_137 ) ;
if ( V_140 )
return V_140 ;
V_140 = F_83 ( & V_154 , & V_66 -> V_3 ) ;
if ( V_140 )
return V_140 ;
F_84 ( V_137 , & V_66 -> V_3 ) ;
return 0 ;
}
static int F_85 ( struct V_136 * V_137 )
{
struct V_2 * V_3 = F_86 ( V_137 ) ;
return F_87 ( & V_154 , V_3 ) ;
}
static int F_88 ( struct V_155 * V_14 )
{
struct V_136 * V_137 = F_16 ( V_14 ) ;
struct V_2 * V_3 = F_86 ( V_137 ) ;
return F_89 ( & V_154 , V_3 ) ;
}
static int F_90 ( struct V_155 * V_14 )
{
struct V_136 * V_137 = F_16 ( V_14 ) ;
struct V_2 * V_3 = F_86 ( V_137 ) ;
return F_91 ( & V_154 , V_3 ) ;
}
static void F_92 ( struct V_2 * V_3 , int V_156 )
{
unsigned int V_157 = 1000000 ;
while ( -- V_157 && ! F_14 ( V_3 ) )
F_93 ( 1 ) ;
F_6 ( V_3 , V_25 , V_156 ) ;
}
static void F_94 ( struct V_158 * V_159 , const char * V_160 , unsigned V_161 )
{
struct V_2 * V_3 = & V_153 [ V_159 -> V_162 ] . V_3 ;
unsigned long V_76 ;
unsigned long V_157 = 1000000 ;
int V_163 = 1 ;
T_1 V_7 ;
if ( V_3 -> V_164 )
V_163 = 0 ;
else if ( V_165 )
V_163 = F_95 ( & V_3 -> V_62 , V_76 ) ;
else
F_49 ( & V_3 -> V_62 , V_76 ) ;
V_7 = F_3 ( V_3 , V_8 ) ;
F_6 ( V_3 , V_8 , 0 ) ;
( void ) F_3 ( V_3 , V_8 ) ;
F_96 ( V_3 , V_160 , V_161 , F_92 ) ;
while ( -- V_157 && ! F_13 ( V_3 ) )
F_93 ( 1 ) ;
F_6 ( V_3 , V_8 , V_7 ) ;
if ( V_163 )
F_50 ( & V_3 -> V_62 , V_76 ) ;
}
static int F_97 ( struct V_158 * V_159 , char * V_166 )
{
struct V_1 * V_66 ;
int V_90 = 115200 ;
int V_167 = 8 ;
int V_54 = 'n' ;
int V_168 = 'n' ;
if ( V_159 -> V_162 >= V_152 )
return - V_74 ;
V_66 = & V_153 [ V_159 -> V_162 ] ;
if ( V_66 -> V_3 . V_148 == 0 || V_66 -> V_3 . V_5 == NULL )
return - V_169 ;
if ( V_166 )
F_98 ( V_166 , & V_90 , & V_54 , & V_167 , & V_168 ) ;
return F_99 ( & V_66 -> V_3 , V_159 , V_90 , V_54 , V_167 , V_168 ) ;
}
static int T_5 F_100 ( void )
{
int V_140 ;
static const char V_170 [] V_171 =
V_172 L_9 ;
F_101 ( V_170 ) ;
V_140 = F_102 ( & V_154 ) ;
if ( V_140 )
return V_140 ;
V_140 = F_103 ( & V_173 ) ;
if ( V_140 )
F_104 ( & V_154 ) ;
return V_140 ;
}
static void T_6 F_105 ( void )
{
F_106 ( & V_173 ) ;
F_104 ( & V_154 ) ;
}

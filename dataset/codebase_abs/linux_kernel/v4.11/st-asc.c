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
if ( V_3 -> V_41 )
F_24 ( V_33 -> V_42 -> V_14 , 0 ) ;
while ( ( V_16 = F_3 ( V_3 , V_11 ) ) & V_43 ) {
V_23 = F_3 ( V_3 , V_44 ) | V_45 ;
V_35 = V_46 ;
V_3 -> V_26 . V_47 ++ ;
if ( V_16 & V_48 || V_23 & V_49 ||
( V_23 & V_50 && ! V_36 ) ) {
if ( V_23 & V_49 ) {
if ( V_23 == ( V_49 | V_45 ) ) {
V_3 -> V_26 . V_51 ++ ;
if ( F_25 ( V_3 ) )
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
if ( F_26 ( V_3 , V_23 & 0xff ) )
continue;
F_27 ( V_3 , V_23 , V_56 , V_23 & 0xff , V_35 ) ;
}
F_28 ( V_33 ) ;
}
static T_2 F_29 ( int V_61 , void * V_62 )
{
struct V_2 * V_3 = V_62 ;
T_1 V_16 ;
F_30 ( & V_3 -> V_63 ) ;
V_16 = F_3 ( V_3 , V_11 ) ;
if ( V_16 & V_43 ) {
F_23 ( V_3 ) ;
}
if ( ( V_16 & V_13 ) &&
( F_3 ( V_3 , V_8 ) & V_9 ) ) {
F_18 ( V_3 ) ;
}
F_31 ( & V_3 -> V_63 ) ;
return V_64 ;
}
static unsigned int F_32 ( struct V_2 * V_3 )
{
return F_13 ( V_3 ) ? V_65 : 0 ;
}
static void F_33 ( struct V_2 * V_3 , unsigned int V_66 )
{
struct V_1 * V_67 = F_1 ( V_3 ) ;
if ( ! V_67 -> V_68 )
return;
if ( F_3 ( V_3 , V_37 ) & V_69 )
return;
F_34 ( V_67 -> V_68 , V_66 & V_70 ) ;
}
static unsigned int F_35 ( struct V_2 * V_3 )
{
return V_71 | V_72 | V_73 ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = & V_3 -> V_21 -> V_20 ;
if ( ! F_20 ( V_20 ) )
F_10 ( V_3 ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
F_9 ( V_3 ) ;
}
static void F_38 ( struct V_2 * V_3 )
{
F_11 ( V_3 ) ;
}
static void F_39 ( struct V_2 * V_3 , int V_74 )
{
}
static int F_40 ( struct V_2 * V_3 )
{
if ( F_41 ( V_3 -> V_61 , F_29 , 0 ,
F_15 ( V_3 ) , V_3 ) ) {
F_42 ( V_3 -> V_14 , L_1 ) ;
return - V_75 ;
}
F_18 ( V_3 ) ;
F_12 ( V_3 ) ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 )
{
F_9 ( V_3 ) ;
F_11 ( V_3 ) ;
F_44 ( V_3 -> V_61 , V_3 ) ;
}
static void F_45 ( struct V_2 * V_3 , unsigned int V_21 ,
unsigned int V_76 )
{
struct V_1 * V_67 = F_1 ( V_3 ) ;
unsigned long V_77 = 0 ;
T_1 V_78 ;
switch ( V_21 ) {
case V_79 :
F_46 ( V_67 -> V_80 ) ;
break;
case V_81 :
F_47 ( & V_3 -> V_63 , V_77 ) ;
V_78 = F_3 ( V_3 , V_37 ) & ~ V_82 ;
F_6 ( V_3 , V_37 , V_78 ) ;
F_48 ( & V_3 -> V_63 , V_77 ) ;
F_49 ( V_67 -> V_80 ) ;
break;
}
}
static void F_50 ( struct V_2 * V_3 , struct V_83 * V_84 ,
struct V_83 * V_85 )
{
struct V_1 * V_67 = F_1 ( V_3 ) ;
struct V_86 * V_87 = V_3 -> V_14 -> V_88 ;
struct V_89 * V_90 ;
unsigned int V_91 ;
T_1 V_92 ;
T_3 V_93 ;
unsigned long V_77 ;
V_84 -> V_94 &= ~ ( V_95 |
( V_67 -> V_96 ? 0 : V_97 ) ) ;
V_3 -> V_98 = F_51 ( V_67 -> V_80 ) ;
V_91 = F_52 ( V_3 , V_84 , V_85 , 0 , V_3 -> V_98 / 16 ) ;
V_93 = V_84 -> V_94 ;
F_47 ( & V_3 -> V_63 , V_77 ) ;
V_92 = F_3 ( V_3 , V_37 ) ;
F_6 ( V_3 , V_37 , ( V_92 & ~ V_82 ) ) ;
V_92 = V_99 | V_100 ;
F_6 ( V_3 , V_101 , 1 ) ;
F_6 ( V_3 , V_102 , 1 ) ;
if ( ( V_93 & V_103 ) == V_104 ) {
V_92 |= V_105 ;
} else {
V_92 |= ( V_93 & V_106 ) ? V_40 :
V_39 ;
}
V_92 |= ( V_93 & V_107 ) ? V_108 : V_109 ;
if ( V_93 & V_110 )
V_92 |= V_111 ;
if ( ( V_93 & V_97 ) ) {
V_92 |= V_69 ;
if ( V_67 -> V_68 ) {
F_53 ( V_3 -> V_14 , V_67 -> V_68 ) ;
V_67 -> V_68 = NULL ;
F_54 ( V_67 -> V_112 ,
V_67 -> V_113 [ DEFAULT ] ) ;
}
} else {
if ( ! V_67 -> V_68 && V_67 -> V_113 [ V_114 ] ) {
F_54 ( V_67 -> V_112 ,
V_67 -> V_113 [ V_114 ] ) ;
V_90 = F_55 ( V_3 -> V_14 ,
L_2 ,
& V_87 -> V_115 ,
V_116 ,
V_87 -> V_15 ) ;
if ( ! F_56 ( V_90 ) )
V_67 -> V_68 = V_90 ;
}
}
if ( ( V_91 < 19200 ) && ! V_67 -> V_117 ) {
F_6 ( V_3 , V_118 , ( V_3 -> V_98 / ( 16 * V_91 ) ) ) ;
} else {
T_4 V_119 = ( T_4 ) V_91 * ( 1 << 16 ) ;
F_57 ( V_119 , V_3 -> V_98 / 16 ) ;
F_6 ( V_3 , V_118 , V_119 ) ;
V_92 |= V_120 ;
}
F_58 ( V_3 , V_93 , V_91 ) ;
V_67 -> V_3 . V_57 = V_56 ;
if ( V_84 -> V_121 & V_122 )
V_67 -> V_3 . V_57 |= V_49 | V_50 ;
if ( V_84 -> V_121 & ( V_123 | V_124 | V_125 ) )
V_67 -> V_3 . V_57 |= V_52 ;
V_67 -> V_3 . V_126 = 0 ;
if ( V_84 -> V_121 & V_127 )
V_67 -> V_3 . V_126 |= V_49 | V_50 ;
if ( V_84 -> V_121 & V_123 ) {
V_67 -> V_3 . V_126 |= V_52 ;
if ( V_84 -> V_121 & V_127 )
V_67 -> V_3 . V_126 |= V_56 ;
}
if ( ! ( V_84 -> V_94 & V_128 ) )
V_67 -> V_3 . V_126 |= V_45 ;
F_6 ( V_3 , V_129 , 20 ) ;
F_6 ( V_3 , V_37 , ( V_92 | V_82 ) ) ;
F_48 ( & V_3 -> V_63 , V_77 ) ;
}
static const char * F_59 ( struct V_2 * V_3 )
{
return ( V_3 -> type == V_130 ) ? V_131 : NULL ;
}
static void F_60 ( struct V_2 * V_3 )
{
}
static int F_61 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_62 ( struct V_2 * V_3 , int V_77 )
{
if ( ( V_77 & V_132 ) )
V_3 -> type = V_130 ;
}
static int
F_63 ( struct V_2 * V_3 , struct V_133 * V_134 )
{
return - V_135 ;
}
static int F_64 ( struct V_2 * V_3 )
{
if ( ! ( F_3 ( V_3 , V_11 ) & V_43 ) )
return V_136 ;
return F_3 ( V_3 , V_44 ) ;
}
static void F_65 ( struct V_2 * V_3 , unsigned char V_23 )
{
while ( ! F_14 ( V_3 ) )
F_66 () ;
F_6 ( V_3 , V_25 , V_23 ) ;
}
static int F_67 ( struct V_1 * V_67 ,
struct V_137 * V_138 )
{
struct V_2 * V_3 = & V_67 -> V_3 ;
struct V_139 * V_140 ;
int V_141 ;
V_3 -> V_142 = V_143 ;
V_3 -> V_77 = V_144 ;
V_3 -> V_145 = & V_146 ;
V_3 -> V_17 = V_147 ;
V_3 -> V_14 = & V_138 -> V_14 ;
V_3 -> V_61 = F_68 ( V_138 , 0 ) ;
V_140 = F_69 ( V_138 , V_148 , 0 ) ;
V_3 -> V_5 = F_70 ( & V_138 -> V_14 , V_140 ) ;
if ( F_56 ( V_3 -> V_5 ) )
return F_71 ( V_3 -> V_5 ) ;
V_3 -> V_149 = V_140 -> V_150 ;
F_72 ( & V_3 -> V_63 ) ;
V_67 -> V_80 = F_73 ( & V_138 -> V_14 , NULL ) ;
if ( F_74 ( F_56 ( V_67 -> V_80 ) ) )
return - V_135 ;
F_46 ( V_67 -> V_80 ) ;
V_67 -> V_3 . V_98 = F_51 ( V_67 -> V_80 ) ;
F_74 ( V_67 -> V_3 . V_98 == 0 ) ;
F_49 ( V_67 -> V_80 ) ;
V_67 -> V_112 = F_75 ( & V_138 -> V_14 ) ;
if ( F_56 ( V_67 -> V_112 ) ) {
V_141 = F_71 ( V_67 -> V_112 ) ;
F_42 ( & V_138 -> V_14 , L_3 , V_141 ) ;
}
V_67 -> V_113 [ DEFAULT ] =
F_76 ( V_67 -> V_112 , L_4 ) ;
if ( F_56 ( V_67 -> V_113 [ DEFAULT ] ) ) {
V_141 = F_71 ( V_67 -> V_113 [ DEFAULT ] ) ;
F_42 ( & V_138 -> V_14 ,
L_5 , V_141 ) ;
return V_141 ;
}
V_67 -> V_113 [ V_114 ] =
F_76 ( V_67 -> V_112 , L_6 ) ;
if ( F_56 ( V_67 -> V_113 [ V_114 ] ) )
V_67 -> V_113 [ V_114 ] = NULL ;
return 0 ;
}
static struct V_1 * F_77 ( struct V_137 * V_138 )
{
struct V_86 * V_87 = V_138 -> V_14 . V_88 ;
int V_151 ;
if ( ! V_87 )
return NULL ;
V_151 = F_78 ( V_87 , V_152 ) ;
if ( V_151 < 0 )
V_151 = 0 ;
if ( F_74 ( V_151 >= V_153 ) )
return NULL ;
V_154 [ V_151 ] . V_96 = F_79 ( V_87 ,
L_7 ) ;
V_154 [ V_151 ] . V_117 = F_79 ( V_87 , L_8 ) ;
V_154 [ V_151 ] . V_3 . line = V_151 ;
V_154 [ V_151 ] . V_68 = NULL ;
return & V_154 [ V_151 ] ;
}
static int F_80 ( struct V_137 * V_138 )
{
int V_141 ;
struct V_1 * V_67 ;
V_67 = F_77 ( V_138 ) ;
if ( ! V_67 )
return - V_75 ;
V_141 = F_67 ( V_67 , V_138 ) ;
if ( V_141 )
return V_141 ;
V_141 = F_81 ( & V_155 , & V_67 -> V_3 ) ;
if ( V_141 )
return V_141 ;
F_82 ( V_138 , & V_67 -> V_3 ) ;
return 0 ;
}
static int F_83 ( struct V_137 * V_138 )
{
struct V_2 * V_3 = F_84 ( V_138 ) ;
return F_85 ( & V_155 , V_3 ) ;
}
static int F_86 ( struct V_156 * V_14 )
{
struct V_137 * V_138 = F_16 ( V_14 ) ;
struct V_2 * V_3 = F_84 ( V_138 ) ;
return F_87 ( & V_155 , V_3 ) ;
}
static int F_88 ( struct V_156 * V_14 )
{
struct V_137 * V_138 = F_16 ( V_14 ) ;
struct V_2 * V_3 = F_84 ( V_138 ) ;
return F_89 ( & V_155 , V_3 ) ;
}
static void F_90 ( struct V_2 * V_3 , int V_157 )
{
unsigned int V_158 = 1000000 ;
while ( -- V_158 && ! F_14 ( V_3 ) )
F_91 ( 1 ) ;
F_6 ( V_3 , V_25 , V_157 ) ;
}
static void F_92 ( struct V_159 * V_160 , const char * V_161 , unsigned V_162 )
{
struct V_2 * V_3 = & V_154 [ V_160 -> V_163 ] . V_3 ;
unsigned long V_77 ;
unsigned long V_158 = 1000000 ;
int V_164 = 1 ;
T_1 V_7 ;
F_93 ( V_77 ) ;
if ( V_3 -> V_165 )
V_164 = 0 ;
else if ( V_166 )
V_164 = F_94 ( & V_3 -> V_63 ) ;
else
F_30 ( & V_3 -> V_63 ) ;
V_7 = F_3 ( V_3 , V_8 ) ;
F_6 ( V_3 , V_8 , 0 ) ;
( void ) F_3 ( V_3 , V_8 ) ;
F_95 ( V_3 , V_161 , V_162 , F_90 ) ;
while ( -- V_158 && ! F_13 ( V_3 ) )
F_91 ( 1 ) ;
F_6 ( V_3 , V_8 , V_7 ) ;
if ( V_164 )
F_31 ( & V_3 -> V_63 ) ;
F_96 ( V_77 ) ;
}
static int F_97 ( struct V_159 * V_160 , char * V_167 )
{
struct V_1 * V_67 ;
int V_91 = 9600 ;
int V_168 = 8 ;
int V_54 = 'n' ;
int V_169 = 'n' ;
if ( V_160 -> V_163 >= V_153 )
return - V_75 ;
V_67 = & V_154 [ V_160 -> V_163 ] ;
if ( V_67 -> V_3 . V_149 == 0 || V_67 -> V_3 . V_5 == NULL )
return - V_170 ;
if ( V_167 )
F_98 ( V_167 , & V_91 , & V_54 , & V_168 , & V_169 ) ;
return F_99 ( & V_67 -> V_3 , V_160 , V_91 , V_54 , V_168 , V_169 ) ;
}
static int T_5 F_100 ( void )
{
int V_141 ;
static char V_171 [] V_172 =
V_173 L_9 ;
F_101 ( V_171 ) ;
V_141 = F_102 ( & V_155 ) ;
if ( V_141 )
return V_141 ;
V_141 = F_103 ( & V_174 ) ;
if ( V_141 )
F_104 ( & V_155 ) ;
return V_141 ;
}
static void T_6 F_105 ( void )
{
F_106 ( & V_174 ) ;
F_104 ( & V_155 ) ;
}

static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_2 * V_3 , T_1 V_4 )
{
return F_4 ( V_3 -> V_5 + V_4 ) ;
}
static inline void F_5 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_6 )
{
F_6 ( V_6 , V_3 -> V_5 + V_4 ) ;
}
static inline void F_7 ( struct V_2 * V_3 )
{
T_1 V_7 = F_3 ( V_3 , V_8 ) & ~ V_9 ;
F_5 ( V_3 , V_8 , V_7 ) ;
( void ) F_3 ( V_3 , V_8 ) ;
}
static inline void F_8 ( struct V_2 * V_3 )
{
T_1 V_7 = F_3 ( V_3 , V_8 ) | V_9 ;
F_5 ( V_3 , V_8 , V_7 ) ;
}
static inline void F_9 ( struct V_2 * V_3 )
{
T_1 V_7 = F_3 ( V_3 , V_8 ) & ~ V_10 ;
F_5 ( V_3 , V_8 , V_7 ) ;
( void ) F_3 ( V_3 , V_8 ) ;
}
static inline void F_10 ( struct V_2 * V_3 )
{
T_1 V_7 = F_3 ( V_3 , V_8 ) | V_10 ;
F_5 ( V_3 , V_8 , V_7 ) ;
}
static inline T_1 F_11 ( struct V_2 * V_3 )
{
return F_3 ( V_3 , V_11 ) & V_12 ;
}
static inline T_1 F_12 ( struct V_2 * V_3 )
{
return F_3 ( V_3 , V_11 ) & V_13 ;
}
static inline const char * F_13 ( struct V_2 * V_3 )
{
return F_14 ( V_3 -> V_14 ) -> V_15 ;
}
static inline unsigned F_15 ( struct V_2 * V_3 )
{
T_1 V_16 = F_3 ( V_3 , V_11 ) ;
if ( V_16 & V_13 )
return V_3 -> V_17 / 2 ;
else if ( ! ( V_16 & V_18 ) )
return 1 ;
return 0 ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = & V_3 -> V_21 -> V_20 ;
int V_22 ;
unsigned char V_23 ;
V_22 = F_15 ( V_3 ) ;
if ( ( V_22 != 0 ) && V_3 -> V_24 ) {
V_23 = V_3 -> V_24 ;
V_3 -> V_24 = 0 ;
F_5 ( V_3 , V_25 , V_23 ) ;
V_3 -> V_26 . V_27 ++ ;
V_22 = F_15 ( V_3 ) ;
}
if ( F_17 ( V_3 ) ) {
F_7 ( V_3 ) ;
return;
}
if ( F_18 ( V_20 ) ) {
F_7 ( V_3 ) ;
return;
}
if ( V_22 == 0 )
return;
do {
V_23 = V_20 -> V_28 [ V_20 -> V_29 ] ;
V_20 -> V_29 = ( V_20 -> V_29 + 1 ) & ( V_30 - 1 ) ;
F_5 ( V_3 , V_25 , V_23 ) ;
V_3 -> V_26 . V_27 ++ ;
V_22 -- ;
} while ( ( V_22 > 0 ) && ( ! F_18 ( V_20 ) ) );
if ( F_19 ( V_20 ) < V_31 )
F_20 ( V_3 ) ;
if ( F_18 ( V_20 ) )
F_7 ( V_3 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_32 * V_33 = & V_3 -> V_21 -> V_3 ;
unsigned long V_16 ;
unsigned long V_23 = 0 ;
char V_34 ;
if ( V_3 -> V_35 )
F_22 ( V_33 -> V_36 -> V_14 , 0 ) ;
while ( ( V_16 = F_3 ( V_3 , V_11 ) ) & V_37 ) {
V_23 = F_3 ( V_3 , V_38 ) | V_39 ;
V_34 = V_40 ;
V_3 -> V_26 . V_41 ++ ;
if ( ( V_23 & ( V_42 | V_43 ) ) ||
V_16 & V_44 ) {
if ( V_23 & V_42 ) {
if ( V_23 == ( V_42 | V_39 ) ) {
V_3 -> V_26 . V_45 ++ ;
if ( F_23 ( V_3 ) )
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
if ( F_24 ( V_3 , V_23 & 0xff ) )
continue;
F_25 ( V_3 , V_23 , V_50 , V_23 & 0xff , V_34 ) ;
}
F_26 ( V_33 ) ;
}
static T_2 F_27 ( int V_55 , void * V_56 )
{
struct V_2 * V_3 = V_56 ;
T_1 V_16 ;
F_28 ( & V_3 -> V_57 ) ;
V_16 = F_3 ( V_3 , V_11 ) ;
if ( V_16 & V_37 ) {
F_21 ( V_3 ) ;
}
if ( ( V_16 & V_13 ) &&
( F_3 ( V_3 , V_8 ) & V_9 ) ) {
F_16 ( V_3 ) ;
}
F_29 ( & V_3 -> V_57 ) ;
return V_58 ;
}
static unsigned int F_30 ( struct V_2 * V_3 )
{
return F_11 ( V_3 ) ? V_59 : 0 ;
}
static void F_31 ( struct V_2 * V_3 , unsigned int V_60 )
{
}
static unsigned int F_32 ( struct V_2 * V_3 )
{
return V_61 | V_62 | V_63 ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = & V_3 -> V_21 -> V_20 ;
if ( ! F_18 ( V_20 ) )
F_8 ( V_3 ) ;
}
static void F_34 ( struct V_2 * V_3 )
{
F_7 ( V_3 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
F_9 ( V_3 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
}
static void F_37 ( struct V_2 * V_3 , int V_64 )
{
}
static int F_38 ( struct V_2 * V_3 )
{
if ( F_39 ( V_3 -> V_55 , F_27 , V_65 ,
F_13 ( V_3 ) , V_3 ) ) {
F_40 ( V_3 -> V_14 , L_1 ) ;
return - V_66 ;
}
F_16 ( V_3 ) ;
F_10 ( V_3 ) ;
return 0 ;
}
static void F_41 ( struct V_2 * V_3 )
{
F_7 ( V_3 ) ;
F_9 ( V_3 ) ;
F_42 ( V_3 -> V_55 , V_3 ) ;
}
static void F_43 ( struct V_2 * V_3 , unsigned int V_21 ,
unsigned int V_67 )
{
struct V_1 * V_68 = F_1 ( V_3 ) ;
unsigned long V_69 = 0 ;
T_1 V_70 ;
switch ( V_21 ) {
case V_71 :
F_44 ( V_68 -> V_72 ) ;
break;
case V_73 :
F_45 ( & V_3 -> V_57 , V_69 ) ;
V_70 = F_3 ( V_3 , V_74 ) & ~ V_75 ;
F_5 ( V_3 , V_74 , V_70 ) ;
F_46 ( & V_3 -> V_57 , V_69 ) ;
F_47 ( V_68 -> V_72 ) ;
break;
}
}
static void F_48 ( struct V_2 * V_3 , struct V_76 * V_77 ,
struct V_76 * V_78 )
{
struct V_1 * V_68 = F_1 ( V_3 ) ;
unsigned int V_79 ;
T_1 V_80 ;
T_3 V_81 ;
unsigned long V_69 ;
V_77 -> V_82 &= ~ ( V_83 |
( V_68 -> V_84 ? 0 : V_85 ) ) ;
V_3 -> V_86 = F_49 ( V_68 -> V_72 ) ;
V_79 = F_50 ( V_3 , V_77 , V_78 , 0 , V_3 -> V_86 / 16 ) ;
V_81 = V_77 -> V_82 ;
F_45 ( & V_3 -> V_57 , V_69 ) ;
V_80 = F_3 ( V_3 , V_74 ) ;
F_5 ( V_3 , V_74 , ( V_80 & ~ V_75 ) ) ;
V_80 = V_87 | V_88 ;
F_5 ( V_3 , V_89 , 1 ) ;
F_5 ( V_3 , V_90 , 1 ) ;
if ( ( V_81 & V_91 ) == V_92 ) {
V_80 |= V_93 ;
} else {
V_80 |= ( V_81 & V_94 ) ? V_95 :
V_96 ;
}
V_80 |= ( V_81 & V_97 ) ? V_98 : V_99 ;
if ( V_81 & V_100 )
V_80 |= V_101 ;
if ( ( V_81 & V_85 ) )
V_80 |= V_102 ;
if ( ( V_79 < 19200 ) && ! V_68 -> V_103 ) {
F_5 ( V_3 , V_104 , ( V_3 -> V_86 / ( 16 * V_79 ) ) ) ;
} else {
T_1 V_105 = ( V_79 * 16384 ) / ( ( V_3 -> V_86 / 64 ) + 1 ) ;
F_5 ( V_3 , V_104 , V_105 ) ;
V_80 |= V_106 ;
}
F_51 ( V_3 , V_81 , V_79 ) ;
V_68 -> V_3 . V_51 = V_50 ;
if ( V_77 -> V_107 & V_108 )
V_68 -> V_3 . V_51 |= V_42 | V_43 ;
if ( V_77 -> V_107 & ( V_109 | V_110 | V_111 ) )
V_68 -> V_3 . V_51 |= V_46 ;
V_68 -> V_3 . V_112 = 0 ;
if ( V_77 -> V_107 & V_113 )
V_68 -> V_3 . V_112 |= V_42 | V_43 ;
if ( V_77 -> V_107 & V_109 ) {
V_68 -> V_3 . V_112 |= V_46 ;
if ( V_77 -> V_107 & V_113 )
V_68 -> V_3 . V_112 |= V_50 ;
}
if ( ! ( V_77 -> V_82 & V_114 ) )
V_68 -> V_3 . V_112 |= V_39 ;
F_5 ( V_3 , V_115 , 20 ) ;
F_5 ( V_3 , V_74 , ( V_80 | V_75 ) ) ;
F_46 ( & V_3 -> V_57 , V_69 ) ;
}
static const char * F_52 ( struct V_2 * V_3 )
{
return ( V_3 -> type == V_116 ) ? V_117 : NULL ;
}
static void F_53 ( struct V_2 * V_3 )
{
}
static int F_54 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_55 ( struct V_2 * V_3 , int V_69 )
{
if ( ( V_69 & V_118 ) )
V_3 -> type = V_116 ;
}
static int
F_56 ( struct V_2 * V_3 , struct V_119 * V_120 )
{
return - V_121 ;
}
static int F_57 ( struct V_2 * V_3 )
{
if ( ! ( F_3 ( V_3 , V_11 ) & V_37 ) )
return V_122 ;
return F_3 ( V_3 , V_38 ) ;
}
static void F_58 ( struct V_2 * V_3 , unsigned char V_23 )
{
while ( ! F_12 ( V_3 ) )
F_59 () ;
F_5 ( V_3 , V_25 , V_23 ) ;
}
static int F_60 ( struct V_1 * V_68 ,
struct V_123 * V_124 )
{
struct V_2 * V_3 = & V_68 -> V_3 ;
struct V_125 * V_126 ;
V_3 -> V_127 = V_128 ;
V_3 -> V_69 = V_129 ;
V_3 -> V_130 = & V_131 ;
V_3 -> V_17 = V_132 ;
V_3 -> V_14 = & V_124 -> V_14 ;
V_3 -> V_55 = F_61 ( V_124 , 0 ) ;
V_126 = F_62 ( V_124 , V_133 , 0 ) ;
V_3 -> V_5 = F_63 ( & V_124 -> V_14 , V_126 ) ;
if ( F_64 ( V_3 -> V_5 ) )
return F_65 ( V_3 -> V_5 ) ;
V_3 -> V_134 = V_126 -> V_135 ;
F_66 ( & V_3 -> V_57 ) ;
V_68 -> V_72 = F_67 ( & V_124 -> V_14 , NULL ) ;
if ( F_68 ( F_64 ( V_68 -> V_72 ) ) )
return - V_121 ;
F_44 ( V_68 -> V_72 ) ;
V_68 -> V_3 . V_86 = F_49 ( V_68 -> V_72 ) ;
F_68 ( V_68 -> V_3 . V_86 == 0 ) ;
F_47 ( V_68 -> V_72 ) ;
return 0 ;
}
static struct V_1 * F_69 ( struct V_123 * V_124 )
{
struct V_136 * V_137 = V_124 -> V_14 . V_138 ;
int V_139 ;
if ( ! V_137 )
return NULL ;
V_139 = F_70 ( V_137 , V_140 ) ;
if ( V_139 < 0 )
V_139 = 0 ;
if ( F_68 ( V_139 >= V_141 ) )
return NULL ;
V_142 [ V_139 ] . V_84 = F_71 ( V_137 ,
L_2 ) ;
V_142 [ V_139 ] . V_103 = F_71 ( V_137 , L_3 ) ;
V_142 [ V_139 ] . V_3 . line = V_139 ;
return & V_142 [ V_139 ] ;
}
static int F_72 ( struct V_123 * V_124 )
{
int V_143 ;
struct V_1 * V_68 ;
V_68 = F_69 ( V_124 ) ;
if ( ! V_68 )
return - V_66 ;
V_143 = F_60 ( V_68 , V_124 ) ;
if ( V_143 )
return V_143 ;
V_143 = F_73 ( & V_144 , & V_68 -> V_3 ) ;
if ( V_143 )
return V_143 ;
F_74 ( V_124 , & V_68 -> V_3 ) ;
return 0 ;
}
static int F_75 ( struct V_123 * V_124 )
{
struct V_2 * V_3 = F_76 ( V_124 ) ;
return F_77 ( & V_144 , V_3 ) ;
}
static int F_78 ( struct V_145 * V_14 )
{
struct V_123 * V_124 = F_14 ( V_14 ) ;
struct V_2 * V_3 = F_76 ( V_124 ) ;
return F_79 ( & V_144 , V_3 ) ;
}
static int F_80 ( struct V_145 * V_14 )
{
struct V_123 * V_124 = F_14 ( V_14 ) ;
struct V_2 * V_3 = F_76 ( V_124 ) ;
return F_81 ( & V_144 , V_3 ) ;
}
static void F_82 ( struct V_2 * V_3 , int V_146 )
{
unsigned int V_147 = 1000000 ;
while ( -- V_147 && ! F_12 ( V_3 ) )
F_83 ( 1 ) ;
F_5 ( V_3 , V_25 , V_146 ) ;
}
static void F_84 ( struct V_148 * V_149 , const char * V_150 , unsigned V_151 )
{
struct V_2 * V_3 = & V_142 [ V_149 -> V_152 ] . V_3 ;
unsigned long V_69 ;
unsigned long V_147 = 1000000 ;
int V_153 = 1 ;
T_1 V_7 ;
F_85 ( V_69 ) ;
if ( V_3 -> V_154 )
V_153 = 0 ;
else if ( V_155 )
V_153 = F_86 ( & V_3 -> V_57 ) ;
else
F_28 ( & V_3 -> V_57 ) ;
V_7 = F_3 ( V_3 , V_8 ) ;
F_5 ( V_3 , V_8 , 0 ) ;
( void ) F_3 ( V_3 , V_8 ) ;
F_87 ( V_3 , V_150 , V_151 , F_82 ) ;
while ( -- V_147 && ! F_11 ( V_3 ) )
F_83 ( 1 ) ;
F_5 ( V_3 , V_8 , V_7 ) ;
if ( V_153 )
F_29 ( & V_3 -> V_57 ) ;
F_88 ( V_69 ) ;
}
static int F_89 ( struct V_148 * V_149 , char * V_156 )
{
struct V_1 * V_68 ;
int V_79 = 9600 ;
int V_157 = 8 ;
int V_48 = 'n' ;
int V_158 = 'n' ;
if ( V_149 -> V_152 >= V_141 )
return - V_66 ;
V_68 = & V_142 [ V_149 -> V_152 ] ;
F_90 ( V_68 -> V_3 . V_134 == 0 || V_68 -> V_3 . V_5 == NULL ) ;
if ( V_156 )
F_91 ( V_156 , & V_79 , & V_48 , & V_157 , & V_158 ) ;
return F_92 ( & V_68 -> V_3 , V_149 , V_79 , V_48 , V_157 , V_158 ) ;
}
static int T_4 F_93 ( void )
{
int V_143 ;
static char V_159 [] V_160 =
V_161 L_4 ;
F_94 ( V_159 ) ;
V_143 = F_95 ( & V_144 ) ;
if ( V_143 )
return V_143 ;
V_143 = F_96 ( & V_162 ) ;
if ( V_143 )
F_97 ( & V_144 ) ;
return V_143 ;
}
static void T_5 F_98 ( void )
{
F_99 ( & V_162 ) ;
F_97 ( & V_144 ) ;
}

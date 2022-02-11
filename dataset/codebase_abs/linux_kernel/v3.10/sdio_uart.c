static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = - V_5 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_7 ) ;
if ( F_4 ( & V_2 -> V_8 , V_9 , V_10 ) )
return - V_11 ;
F_5 ( & V_12 ) ;
for ( V_3 = 0 ; V_3 < V_13 ; V_3 ++ ) {
if ( ! V_14 [ V_3 ] ) {
V_2 -> V_3 = V_3 ;
V_14 [ V_3 ] = V_2 ;
V_4 = 0 ;
break;
}
}
F_6 ( & V_12 ) ;
return V_4 ;
}
static struct V_1 * F_7 ( unsigned V_3 )
{
struct V_1 * V_2 ;
if ( V_3 >= V_13 )
return NULL ;
F_5 ( & V_12 ) ;
V_2 = V_14 [ V_3 ] ;
if ( V_2 )
F_8 ( & V_2 -> V_2 ) ;
F_6 ( & V_12 ) ;
return V_2 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
F_12 ( V_14 [ V_2 -> V_3 ] != V_2 ) ;
F_5 ( & V_12 ) ;
V_14 [ V_2 -> V_3 ] = NULL ;
F_6 ( & V_12 ) ;
F_13 ( & V_2 -> V_2 . V_17 ) ;
F_13 ( & V_2 -> V_6 ) ;
V_16 = V_2 -> V_16 ;
F_14 ( V_16 ) ;
V_2 -> V_16 = NULL ;
F_15 ( & V_2 -> V_6 ) ;
F_16 ( & V_2 -> V_2 , false ) ;
F_15 ( & V_2 -> V_2 . V_17 ) ;
F_17 ( V_16 ) ;
F_18 ( V_16 ) ;
F_19 ( V_16 ) ;
F_9 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_6 ) ;
if ( F_21 ( ! V_2 -> V_16 ) ) {
F_15 ( & V_2 -> V_6 ) ;
return - V_18 ;
}
if ( F_22 ( V_2 -> V_19 != V_20 ) )
F_14 ( V_2 -> V_16 ) ;
F_15 ( & V_2 -> V_6 ) ;
return 0 ;
}
static inline void F_23 ( struct V_1 * V_2 )
{
if ( F_22 ( V_2 -> V_19 != V_20 ) )
F_19 ( V_2 -> V_16 ) ;
}
static inline unsigned int F_24 ( struct V_1 * V_2 , int V_21 )
{
unsigned char V_22 ;
V_22 = F_25 ( V_2 -> V_16 , V_2 -> V_23 + V_21 , NULL ) ;
return V_22 ;
}
static inline void F_26 ( struct V_1 * V_2 , int V_21 , int V_24 )
{
F_27 ( V_2 -> V_16 , V_24 , V_2 -> V_23 + V_21 , NULL ) ;
}
static unsigned int F_28 ( struct V_1 * V_2 )
{
unsigned char V_25 ;
unsigned int V_4 ;
V_25 = F_24 ( V_2 , V_26 ) ;
V_4 = 0 ;
if ( V_25 & V_27 )
V_4 |= V_28 ;
if ( V_25 & V_29 )
V_4 |= V_30 ;
if ( V_25 & V_31 )
V_4 |= V_32 ;
if ( V_25 & V_33 )
V_4 |= V_34 ;
return V_4 ;
}
static void F_29 ( struct V_1 * V_2 ,
unsigned int V_35 )
{
unsigned char V_36 = 0 ;
if ( V_35 & V_37 )
V_36 |= V_38 ;
if ( V_35 & V_39 )
V_36 |= V_40 ;
if ( V_35 & V_41 )
V_36 |= V_42 ;
if ( V_35 & V_43 )
V_36 |= V_44 ;
if ( V_35 & V_45 )
V_36 |= V_46 ;
F_26 ( V_2 , V_47 , V_36 ) ;
}
static inline void F_30 ( struct V_1 * V_2 ,
unsigned int V_48 , unsigned int V_49 )
{
unsigned int V_50 ;
V_50 = V_2 -> V_35 ;
V_2 -> V_35 = ( V_50 & ~ V_49 ) | V_48 ;
if ( V_50 != V_2 -> V_35 )
F_29 ( V_2 , V_2 -> V_35 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_51 * V_52 ,
struct V_51 * V_50 )
{
unsigned char V_53 , V_54 = 0 ;
unsigned int V_55 , V_56 ;
switch ( V_52 -> V_57 & V_58 ) {
case V_59 :
V_53 = V_60 ;
break;
case V_61 :
V_53 = V_62 ;
break;
case V_63 :
V_53 = V_64 ;
break;
default:
case V_65 :
V_53 = V_66 ;
break;
}
if ( V_52 -> V_57 & V_67 )
V_53 |= V_68 ;
if ( V_52 -> V_57 & V_69 )
V_53 |= V_70 ;
if ( ! ( V_52 -> V_57 & V_71 ) )
V_53 |= V_72 ;
for (; ; ) {
V_55 = F_32 ( V_52 ) ;
if ( V_55 == 0 )
V_55 = 9600 ;
if ( V_55 <= V_2 -> V_73 )
break;
V_52 -> V_57 &= ~ V_74 ;
if ( V_50 ) {
V_52 -> V_57 |= V_50 -> V_57 & V_74 ;
V_50 = NULL ;
} else
V_52 -> V_57 |= V_75 ;
}
V_56 = ( 2 * V_2 -> V_73 + V_55 ) / ( 2 * V_55 ) ;
if ( V_55 < 2400 )
V_54 = V_76 | V_77 ;
else
V_54 = V_76 | V_78 ;
V_2 -> V_79 = V_80 | V_81 | V_82 ;
if ( V_52 -> V_83 & V_84 )
V_2 -> V_79 |= V_85 | V_86 ;
if ( V_52 -> V_83 & ( V_87 | V_88 ) )
V_2 -> V_79 |= V_89 ;
V_2 -> V_90 = 0 ;
if ( V_52 -> V_83 & V_91 )
V_2 -> V_90 |= V_86 | V_85 ;
if ( V_52 -> V_83 & V_92 ) {
V_2 -> V_90 |= V_89 ;
if ( V_52 -> V_83 & V_91 )
V_2 -> V_90 |= V_80 ;
}
if ( ( V_52 -> V_57 & V_93 ) == 0 )
V_2 -> V_90 |= V_82 ;
V_2 -> V_94 &= ~ V_95 ;
if ( ( V_52 -> V_57 & V_96 ) || ! ( V_52 -> V_57 & V_97 ) )
V_2 -> V_94 |= V_95 ;
V_2 -> V_98 = V_53 ;
F_26 ( V_2 , V_99 , V_2 -> V_94 ) ;
F_26 ( V_2 , V_100 , V_53 | V_101 ) ;
F_26 ( V_2 , V_102 , V_56 & 0xff ) ;
F_26 ( V_2 , V_103 , V_56 >> 8 ) ;
F_26 ( V_2 , V_100 , V_53 ) ;
F_26 ( V_2 , V_104 , V_54 ) ;
F_29 ( V_2 , V_2 -> V_35 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_94 & V_105 ) ) {
V_2 -> V_94 |= V_105 ;
F_26 ( V_2 , V_99 , V_2 -> V_94 ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_94 & V_105 ) {
V_2 -> V_94 &= ~ V_105 ;
F_26 ( V_2 , V_99 , V_2 -> V_94 ) ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
V_2 -> V_94 &= ~ V_106 ;
V_2 -> V_79 &= ~ V_82 ;
F_26 ( V_2 , V_99 , V_2 -> V_94 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
unsigned int * V_25 )
{
unsigned int V_107 , V_108 ;
int V_109 = 256 ;
do {
V_107 = F_24 ( V_2 , V_110 ) ;
V_108 = V_111 ;
V_2 -> V_112 . V_113 ++ ;
if ( F_21 ( * V_25 & ( V_89 | V_86 |
V_85 | V_80 ) ) ) {
if ( * V_25 & V_89 ) {
* V_25 &= ~ ( V_85 | V_86 ) ;
V_2 -> V_112 . V_114 ++ ;
} else if ( * V_25 & V_86 )
V_2 -> V_112 . V_115 ++ ;
else if ( * V_25 & V_85 )
V_2 -> V_112 . V_116 ++ ;
if ( * V_25 & V_80 )
V_2 -> V_112 . V_117 ++ ;
* V_25 &= V_2 -> V_79 ;
if ( * V_25 & V_89 )
V_108 = V_118 ;
else if ( * V_25 & V_86 )
V_108 = V_119 ;
else if ( * V_25 & V_85 )
V_108 = V_120 ;
}
if ( ( * V_25 & V_2 -> V_90 & ~ V_80 ) == 0 )
F_37 ( & V_2 -> V_2 , V_107 , V_108 ) ;
if ( * V_25 & ~ V_2 -> V_90 & V_80 )
F_37 ( & V_2 -> V_2 , 0 , V_121 ) ;
* V_25 = F_24 ( V_2 , V_122 ) ;
} while ( ( * V_25 & V_82 ) && ( V_109 -- > 0 ) );
F_38 ( & V_2 -> V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_123 * V_124 = & V_2 -> V_8 ;
int V_125 ;
struct V_126 * V_127 ;
T_1 V_128 [ 16 ] ;
int V_129 ;
if ( V_2 -> V_130 ) {
F_26 ( V_2 , V_131 , V_2 -> V_130 ) ;
V_2 -> V_112 . V_132 ++ ;
V_2 -> V_130 = 0 ;
return;
}
V_127 = F_40 ( & V_2 -> V_2 ) ;
if ( V_127 == NULL || ! F_41 ( V_124 ) ||
V_127 -> V_133 || V_127 -> V_134 ) {
F_34 ( V_2 ) ;
F_42 ( V_127 ) ;
return;
}
V_129 = F_43 ( V_124 , V_128 , 16 , & V_2 -> V_7 ) ;
for ( V_125 = 0 ; V_125 < V_129 ; V_125 ++ ) {
F_26 ( V_2 , V_131 , V_128 [ V_125 ] ) ;
V_2 -> V_112 . V_132 ++ ;
}
V_129 = F_41 ( V_124 ) ;
if ( V_129 < V_135 ) {
F_44 ( V_127 ) ;
if ( V_129 == 0 )
F_34 ( V_2 ) ;
}
F_42 ( V_127 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_25 ;
struct V_126 * V_127 ;
V_25 = F_24 ( V_2 , V_26 ) ;
if ( ( V_25 & V_136 ) == 0 )
return;
if ( V_25 & V_137 )
V_2 -> V_112 . V_138 ++ ;
if ( V_25 & V_139 )
V_2 -> V_112 . V_140 ++ ;
if ( V_25 & V_141 ) {
V_2 -> V_112 . V_142 ++ ;
if ( V_25 & V_27 )
F_46 ( & V_2 -> V_2 . V_143 ) ;
else {
F_16 ( & V_2 -> V_2 , false ) ;
}
}
if ( V_25 & V_144 ) {
V_2 -> V_112 . V_145 ++ ;
V_127 = F_40 ( & V_2 -> V_2 ) ;
if ( V_127 && ( V_127 -> V_52 . V_57 & V_96 ) ) {
int V_145 = ( V_25 & V_33 ) ;
if ( V_127 -> V_134 ) {
if ( V_145 ) {
V_127 -> V_134 = 0 ;
F_33 ( V_2 ) ;
F_44 ( V_127 ) ;
}
} else {
if ( ! V_145 ) {
V_127 -> V_134 = 1 ;
F_34 ( V_2 ) ;
}
}
}
F_42 ( V_127 ) ;
}
}
static void F_47 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_48 ( V_16 ) ;
unsigned int V_146 , V_147 ;
if ( F_21 ( V_2 -> V_19 == V_20 ) )
return;
V_146 = F_24 ( V_2 , V_148 ) ;
if ( V_146 & V_149 )
return;
V_2 -> V_19 = V_20 ;
V_147 = F_24 ( V_2 , V_122 ) ;
if ( V_147 & V_82 )
F_36 ( V_2 , & V_147 ) ;
F_45 ( V_2 ) ;
if ( V_147 & V_81 )
F_39 ( V_2 ) ;
V_2 -> V_19 = NULL ;
}
static int F_49 ( struct V_150 * V_151 )
{
struct V_1 * V_2 =
F_50 ( V_151 , struct V_1 , V_2 ) ;
unsigned int V_4 = F_20 ( V_2 ) ;
if ( V_4 )
return 1 ;
V_4 = F_28 ( V_2 ) ;
F_23 ( V_2 ) ;
if ( V_4 & V_28 )
return 1 ;
return 0 ;
}
static void F_51 ( struct V_150 * V_151 , int V_152 )
{
struct V_1 * V_2 =
F_50 ( V_151 , struct V_1 , V_2 ) ;
int V_4 = F_20 ( V_2 ) ;
if ( V_4 )
return;
if ( V_152 == 0 )
F_52 ( V_2 , V_39 | V_37 ) ;
else
F_53 ( V_2 , V_39 | V_37 ) ;
F_23 ( V_2 ) ;
}
static int F_54 ( struct V_150 * V_151 , struct V_126 * V_127 )
{
struct V_1 * V_2 =
F_50 ( V_151 , struct V_1 , V_2 ) ;
int V_4 ;
F_55 ( V_153 , & V_127 -> V_154 ) ;
F_56 ( & V_2 -> V_8 ) ;
V_4 = F_20 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_57 ( V_2 -> V_16 ) ;
if ( V_4 )
goto V_155;
V_4 = F_58 ( V_2 -> V_16 , F_47 ) ;
if ( V_4 )
goto V_156;
F_26 ( V_2 , V_104 , V_76 ) ;
F_26 ( V_2 , V_104 , V_76 |
V_157 | V_158 ) ;
F_26 ( V_2 , V_104 , 0 ) ;
( void ) F_24 ( V_2 , V_122 ) ;
( void ) F_24 ( V_2 , V_110 ) ;
( void ) F_24 ( V_2 , V_148 ) ;
( void ) F_24 ( V_2 , V_26 ) ;
F_26 ( V_2 , V_100 , V_66 ) ;
V_2 -> V_94 = V_106 | V_159 | V_160 | V_161 ;
V_2 -> V_35 = V_43 ;
F_31 ( V_2 , & V_127 -> V_52 , NULL ) ;
if ( V_127 -> V_52 . V_57 & V_74 )
F_53 ( V_2 , V_37 | V_39 ) ;
if ( V_127 -> V_52 . V_57 & V_96 )
if ( ! ( F_28 ( V_2 ) & V_34 ) )
V_127 -> V_134 = 1 ;
F_59 ( V_153 , & V_127 -> V_154 ) ;
F_47 ( V_2 -> V_16 ) ;
F_23 ( V_2 ) ;
return 0 ;
V_156:
F_18 ( V_2 -> V_16 ) ;
V_155:
F_23 ( V_2 ) ;
return V_4 ;
}
static void F_60 ( struct V_150 * V_151 )
{
struct V_1 * V_2 =
F_50 ( V_151 , struct V_1 , V_2 ) ;
int V_4 ;
V_4 = F_20 ( V_2 ) ;
if ( V_4 )
return;
F_35 ( V_2 ) ;
F_17 ( V_2 -> V_16 ) ;
V_2 -> V_94 = 0 ;
F_26 ( V_2 , V_99 , 0 ) ;
F_52 ( V_2 , V_43 ) ;
V_2 -> V_98 &= ~ V_162 ;
F_26 ( V_2 , V_100 , V_2 -> V_98 ) ;
F_26 ( V_2 , V_104 , V_76 |
V_157 |
V_158 ) ;
F_26 ( V_2 , V_104 , 0 ) ;
F_18 ( V_2 -> V_16 ) ;
F_23 ( V_2 ) ;
}
static void F_61 ( struct V_150 * V_151 )
{
struct V_1 * V_2 =
F_50 ( V_151 , struct V_1 , V_2 ) ;
F_62 ( & V_2 -> V_8 ) ;
F_63 ( V_2 ) ;
}
static int F_64 ( struct V_163 * V_164 , struct V_126 * V_127 )
{
int V_165 = V_127 -> V_3 ;
struct V_1 * V_2 = F_7 ( V_165 ) ;
int V_4 = F_65 ( V_164 , V_127 ) ;
if ( V_4 == 0 )
V_127 -> V_166 = V_2 ;
else
F_9 ( V_2 ) ;
return V_4 ;
}
static void F_66 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
V_127 -> V_166 = NULL ;
F_9 ( V_2 ) ;
}
static int F_67 ( struct V_126 * V_127 , struct V_167 * V_168 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
return F_68 ( & V_2 -> V_2 , V_127 , V_168 ) ;
}
static void F_69 ( struct V_126 * V_127 , struct V_167 * V_168 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
F_70 ( & V_2 -> V_2 , V_127 , V_168 ) ;
}
static void F_71 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
F_72 ( & V_2 -> V_2 ) ;
}
static int F_73 ( struct V_126 * V_127 , const unsigned char * V_169 ,
int V_125 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
int V_4 ;
if ( ! V_2 -> V_16 )
return - V_18 ;
V_4 = F_74 ( & V_2 -> V_8 , V_169 , V_125 , & V_2 -> V_7 ) ;
if ( ! ( V_2 -> V_94 & V_105 ) ) {
int V_170 = F_20 ( V_2 ) ;
if ( ! V_170 ) {
F_33 ( V_2 ) ;
F_47 ( V_2 -> V_16 ) ;
F_23 ( V_2 ) ;
} else
V_4 = V_170 ;
}
return V_4 ;
}
static int F_75 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
return V_9 - F_41 ( & V_2 -> V_8 ) ;
}
static int F_76 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
return F_41 ( & V_2 -> V_8 ) ;
}
static void F_77 ( struct V_126 * V_127 , char V_107 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
V_2 -> V_130 = V_107 ;
if ( V_107 && ! ( V_2 -> V_94 & V_105 ) ) {
if ( F_20 ( V_2 ) != 0 )
return;
F_33 ( V_2 ) ;
F_47 ( V_2 -> V_16 ) ;
F_23 ( V_2 ) ;
}
}
static void F_78 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
if ( ! F_79 ( V_127 ) && ! ( V_127 -> V_52 . V_57 & V_96 ) )
return;
if ( F_20 ( V_2 ) != 0 )
return;
if ( F_79 ( V_127 ) ) {
V_2 -> V_130 = F_80 ( V_127 ) ;
F_33 ( V_2 ) ;
}
if ( V_127 -> V_52 . V_57 & V_96 )
F_52 ( V_2 , V_37 ) ;
F_47 ( V_2 -> V_16 ) ;
F_23 ( V_2 ) ;
}
static void F_81 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
if ( ! F_79 ( V_127 ) && ! ( V_127 -> V_52 . V_57 & V_96 ) )
return;
if ( F_20 ( V_2 ) != 0 )
return;
if ( F_79 ( V_127 ) ) {
if ( V_2 -> V_130 ) {
V_2 -> V_130 = 0 ;
} else {
V_2 -> V_130 = F_82 ( V_127 ) ;
F_33 ( V_2 ) ;
}
}
if ( V_127 -> V_52 . V_57 & V_96 )
F_53 ( V_2 , V_37 ) ;
F_47 ( V_2 -> V_16 ) ;
F_23 ( V_2 ) ;
}
static void F_83 ( struct V_126 * V_127 ,
struct V_51 * V_171 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
unsigned int V_172 = V_127 -> V_52 . V_57 ;
if ( F_20 ( V_2 ) != 0 )
return;
F_31 ( V_2 , & V_127 -> V_52 , V_171 ) ;
if ( ( V_171 -> V_57 & V_74 ) && ! ( V_172 & V_74 ) )
F_52 ( V_2 , V_37 | V_39 ) ;
if ( ! ( V_171 -> V_57 & V_74 ) && ( V_172 & V_74 ) ) {
unsigned int V_173 = V_39 ;
if ( ! ( V_172 & V_96 ) || ! F_84 ( V_174 , & V_127 -> V_154 ) )
V_173 |= V_37 ;
F_53 ( V_2 , V_173 ) ;
}
if ( ( V_171 -> V_57 & V_96 ) && ! ( V_172 & V_96 ) ) {
V_127 -> V_134 = 0 ;
F_33 ( V_2 ) ;
}
if ( ! ( V_171 -> V_57 & V_96 ) && ( V_172 & V_96 ) ) {
if ( ! ( F_28 ( V_2 ) & V_34 ) ) {
V_127 -> V_134 = 1 ;
F_34 ( V_2 ) ;
}
}
F_23 ( V_2 ) ;
}
static int F_85 ( struct V_126 * V_127 , int V_175 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
int V_176 ;
V_176 = F_20 ( V_2 ) ;
if ( V_176 != 0 )
return V_176 ;
if ( V_175 == - 1 )
V_2 -> V_98 |= V_162 ;
else
V_2 -> V_98 &= ~ V_162 ;
F_26 ( V_2 , V_100 , V_2 -> V_98 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_86 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
int V_176 ;
V_176 = F_20 ( V_2 ) ;
if ( ! V_176 ) {
V_176 = V_2 -> V_35 | F_28 ( V_2 ) ;
F_23 ( V_2 ) ;
}
return V_176 ;
}
static int F_87 ( struct V_126 * V_127 ,
unsigned int V_48 , unsigned int V_49 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
int V_176 ;
V_176 = F_20 ( V_2 ) ;
if ( ! V_176 ) {
F_30 ( V_2 , V_48 , V_49 ) ;
F_23 ( V_2 ) ;
}
return V_176 ;
}
static int F_88 ( struct V_177 * V_178 , void * V_179 )
{
int V_180 ;
F_89 ( V_178 , L_1 ,
L_2 , L_2 , L_2 ) ;
for ( V_180 = 0 ; V_180 < V_13 ; V_180 ++ ) {
struct V_1 * V_2 = F_7 ( V_180 ) ;
if ( V_2 ) {
F_89 ( V_178 , L_3 , V_180 ) ;
if ( F_90 ( V_181 ) ) {
F_89 ( V_178 , L_4 ,
V_2 -> V_112 . V_132 , V_2 -> V_112 . V_113 ) ;
if ( V_2 -> V_112 . V_116 )
F_89 ( V_178 , L_5 ,
V_2 -> V_112 . V_116 ) ;
if ( V_2 -> V_112 . V_115 )
F_89 ( V_178 , L_6 ,
V_2 -> V_112 . V_115 ) ;
if ( V_2 -> V_112 . V_114 )
F_89 ( V_178 , L_7 ,
V_2 -> V_112 . V_114 ) ;
if ( V_2 -> V_112 . V_117 )
F_89 ( V_178 , L_8 ,
V_2 -> V_112 . V_117 ) ;
if ( V_2 -> V_112 . V_145 )
F_89 ( V_178 , L_9 ,
V_2 -> V_112 . V_145 ) ;
if ( V_2 -> V_112 . V_140 )
F_89 ( V_178 , L_10 ,
V_2 -> V_112 . V_140 ) ;
if ( V_2 -> V_112 . V_138 )
F_89 ( V_178 , L_11 ,
V_2 -> V_112 . V_138 ) ;
if ( V_2 -> V_112 . V_142 )
F_89 ( V_178 , L_12 ,
V_2 -> V_112 . V_142 ) ;
}
F_9 ( V_2 ) ;
F_91 ( V_178 , '\n' ) ;
}
}
return 0 ;
}
static int F_92 ( struct V_182 * V_182 , struct V_167 * V_167 )
{
return F_93 ( V_167 , F_88 , NULL ) ;
}
static int F_94 ( struct V_15 * V_16 ,
const struct V_183 * V_184 )
{
struct V_1 * V_2 ;
int V_4 ;
V_2 = F_95 ( sizeof( struct V_1 ) , V_10 ) ;
if ( ! V_2 )
return - V_11 ;
if ( V_16 -> V_185 == V_186 ) {
F_96 ( L_13 ,
F_97 ( V_16 ) ) ;
F_63 ( V_2 ) ;
return - V_187 ;
} else if ( V_16 -> V_185 == V_188 ) {
struct V_189 * V_190 ;
for ( V_190 = V_16 -> V_191 ; V_190 ; V_190 = V_190 -> V_192 ) {
if ( V_190 -> V_193 != 0x91 )
continue;
if ( V_190 -> V_194 < 10 )
continue;
if ( V_190 -> V_195 [ 1 ] == 0 )
break;
}
if ( ! V_190 ) {
F_96 (
L_14 ,
F_97 ( V_16 ) ) ;
F_63 ( V_2 ) ;
return - V_196 ;
}
F_98 ( L_15 ,
F_97 ( V_16 ) , V_190 -> V_195 [ 2 ] , V_190 -> V_195 [ 3 ] ) ;
V_2 -> V_23 = ( V_190 -> V_195 [ 4 ] << 0 ) |
( V_190 -> V_195 [ 5 ] << 8 ) |
( V_190 -> V_195 [ 6 ] << 16 ) ;
F_98 ( L_16 ,
F_97 ( V_16 ) , V_2 -> V_23 ) ;
V_2 -> V_73 = V_190 -> V_195 [ 7 ] * 115200 ;
if ( V_2 -> V_73 == 0 )
V_2 -> V_73 = 115200 ;
F_98 ( L_17 ,
F_97 ( V_16 ) , V_2 -> V_73 ,
V_190 -> V_195 [ 7 ] , V_190 -> V_195 [ 8 ] | ( V_190 -> V_195 [ 9 ] << 8 ) ) ;
} else {
F_63 ( V_2 ) ;
return - V_196 ;
}
V_2 -> V_16 = V_16 ;
F_99 ( V_16 , V_2 ) ;
F_100 ( & V_2 -> V_2 ) ;
V_2 -> V_2 . V_197 = & V_198 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 ) {
F_63 ( V_2 ) ;
} else {
struct V_199 * V_200 ;
V_200 = F_101 ( & V_2 -> V_2 ,
V_201 , V_2 -> V_3 , & V_16 -> V_200 ) ;
if ( F_102 ( V_200 ) ) {
F_11 ( V_2 ) ;
V_4 = F_103 ( V_200 ) ;
}
}
return V_4 ;
}
static void F_104 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_48 ( V_16 ) ;
F_105 ( V_201 , V_2 -> V_3 ) ;
F_11 ( V_2 ) ;
}
static int T_2 F_106 ( void )
{
int V_4 ;
struct V_163 * V_202 ;
V_201 = V_202 = F_107 ( V_13 ) ;
if ( ! V_202 )
return - V_11 ;
V_202 -> V_203 = L_18 ;
V_202 -> V_204 = L_19 ;
V_202 -> V_205 = 0 ;
V_202 -> V_206 = 0 ;
V_202 -> type = V_207 ;
V_202 -> V_208 = V_209 ;
V_202 -> V_154 = V_210 | V_211 ;
V_202 -> V_212 = V_213 ;
V_202 -> V_212 . V_57 = V_214 | V_65 | V_93 | V_215 | V_97 ;
V_202 -> V_212 . V_216 = 4800 ;
V_202 -> V_212 . V_217 = 4800 ;
F_108 ( V_202 , & V_218 ) ;
V_4 = F_109 ( V_202 ) ;
if ( V_4 )
goto V_155;
V_4 = F_110 ( & V_219 ) ;
if ( V_4 )
goto V_156;
return 0 ;
V_156:
F_111 ( V_202 ) ;
V_155:
F_112 ( V_202 ) ;
return V_4 ;
}
static void T_3 F_113 ( void )
{
F_114 ( & V_219 ) ;
F_111 ( V_201 ) ;
F_112 ( V_201 ) ;
}

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
F_5 ( & V_12 ) ;
V_14 [ V_2 -> V_3 ] = NULL ;
F_6 ( & V_12 ) ;
F_12 ( & V_2 -> V_2 . V_17 ) ;
F_12 ( & V_2 -> V_6 ) ;
V_16 = V_2 -> V_16 ;
F_13 ( V_16 ) ;
V_2 -> V_16 = NULL ;
F_14 ( & V_2 -> V_6 ) ;
F_15 ( & V_2 -> V_2 , false ) ;
F_14 ( & V_2 -> V_2 . V_17 ) ;
F_16 ( V_16 ) ;
F_17 ( V_16 ) ;
F_18 ( V_16 ) ;
F_9 ( V_2 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_6 ) ;
if ( F_20 ( ! V_2 -> V_16 ) ) {
F_14 ( & V_2 -> V_6 ) ;
return - V_18 ;
}
if ( F_21 ( V_2 -> V_19 != V_20 ) )
F_13 ( V_2 -> V_16 ) ;
F_14 ( & V_2 -> V_6 ) ;
return 0 ;
}
static inline void F_22 ( struct V_1 * V_2 )
{
if ( F_21 ( V_2 -> V_19 != V_20 ) )
F_18 ( V_2 -> V_16 ) ;
}
static inline unsigned int F_23 ( struct V_1 * V_2 , int V_21 )
{
unsigned char V_22 ;
V_22 = F_24 ( V_2 -> V_16 , V_2 -> V_23 + V_21 , NULL ) ;
return V_22 ;
}
static inline void F_25 ( struct V_1 * V_2 , int V_21 , int V_24 )
{
F_26 ( V_2 -> V_16 , V_24 , V_2 -> V_23 + V_21 , NULL ) ;
}
static unsigned int F_27 ( struct V_1 * V_2 )
{
unsigned char V_25 ;
unsigned int V_4 ;
V_25 = F_23 ( V_2 , V_26 ) ;
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
static void F_28 ( struct V_1 * V_2 ,
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
F_25 ( V_2 , V_47 , V_36 ) ;
}
static inline void F_29 ( struct V_1 * V_2 ,
unsigned int V_48 , unsigned int V_49 )
{
unsigned int V_50 ;
V_50 = V_2 -> V_35 ;
V_2 -> V_35 = ( V_50 & ~ V_49 ) | V_48 ;
if ( V_50 != V_2 -> V_35 )
F_28 ( V_2 , V_2 -> V_35 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
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
V_55 = F_31 ( V_52 ) ;
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
F_25 ( V_2 , V_99 , V_2 -> V_94 ) ;
F_25 ( V_2 , V_100 , V_53 | V_101 ) ;
F_25 ( V_2 , V_102 , V_56 & 0xff ) ;
F_25 ( V_2 , V_103 , V_56 >> 8 ) ;
F_25 ( V_2 , V_100 , V_53 ) ;
F_25 ( V_2 , V_104 , V_54 ) ;
F_28 ( V_2 , V_2 -> V_35 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_94 & V_105 ) ) {
V_2 -> V_94 |= V_105 ;
F_25 ( V_2 , V_99 , V_2 -> V_94 ) ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_94 & V_105 ) {
V_2 -> V_94 &= ~ V_105 ;
F_25 ( V_2 , V_99 , V_2 -> V_94 ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
V_2 -> V_94 &= ~ V_106 ;
V_2 -> V_79 &= ~ V_82 ;
F_25 ( V_2 , V_99 , V_2 -> V_94 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
unsigned int * V_25 )
{
unsigned int V_107 , V_108 ;
int V_109 = 256 ;
do {
V_107 = F_23 ( V_2 , V_110 ) ;
V_108 = V_111 ;
V_2 -> V_112 . V_113 ++ ;
if ( F_20 ( * V_25 & ( V_89 | V_86 |
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
F_36 ( & V_2 -> V_2 , V_107 , V_108 ) ;
if ( * V_25 & ~ V_2 -> V_90 & V_80 )
F_36 ( & V_2 -> V_2 , 0 , V_121 ) ;
* V_25 = F_23 ( V_2 , V_122 ) ;
} while ( ( * V_25 & V_82 ) && ( V_109 -- > 0 ) );
F_37 ( & V_2 -> V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_123 * V_124 = & V_2 -> V_8 ;
int V_125 ;
struct V_126 * V_127 ;
T_1 V_128 [ 16 ] ;
int V_129 ;
if ( V_2 -> V_130 ) {
F_25 ( V_2 , V_131 , V_2 -> V_130 ) ;
V_2 -> V_112 . V_132 ++ ;
V_2 -> V_130 = 0 ;
return;
}
V_127 = F_39 ( & V_2 -> V_2 ) ;
if ( V_127 == NULL || ! F_40 ( V_124 ) ||
V_127 -> V_133 || V_127 -> V_134 ) {
F_33 ( V_2 ) ;
F_41 ( V_127 ) ;
return;
}
V_129 = F_42 ( V_124 , V_128 , 16 , & V_2 -> V_7 ) ;
for ( V_125 = 0 ; V_125 < V_129 ; V_125 ++ ) {
F_25 ( V_2 , V_131 , V_128 [ V_125 ] ) ;
V_2 -> V_112 . V_132 ++ ;
}
V_129 = F_40 ( V_124 ) ;
if ( V_129 < V_135 ) {
F_43 ( V_127 ) ;
if ( V_129 == 0 )
F_33 ( V_2 ) ;
}
F_41 ( V_127 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
int V_25 ;
struct V_126 * V_127 ;
V_25 = F_23 ( V_2 , V_26 ) ;
if ( ( V_25 & V_136 ) == 0 )
return;
if ( V_25 & V_137 )
V_2 -> V_112 . V_138 ++ ;
if ( V_25 & V_139 )
V_2 -> V_112 . V_140 ++ ;
if ( V_25 & V_141 ) {
V_2 -> V_112 . V_142 ++ ;
if ( V_25 & V_27 )
F_45 ( & V_2 -> V_2 . V_143 ) ;
else {
F_15 ( & V_2 -> V_2 , false ) ;
}
}
if ( V_25 & V_144 ) {
V_2 -> V_112 . V_145 ++ ;
V_127 = F_39 ( & V_2 -> V_2 ) ;
if ( V_127 && F_46 ( V_127 ) ) {
int V_145 = ( V_25 & V_33 ) ;
if ( V_127 -> V_134 ) {
if ( V_145 ) {
V_127 -> V_134 = 0 ;
F_32 ( V_2 ) ;
F_43 ( V_127 ) ;
}
} else {
if ( ! V_145 ) {
V_127 -> V_134 = 1 ;
F_33 ( V_2 ) ;
}
}
}
F_41 ( V_127 ) ;
}
}
static void F_47 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_48 ( V_16 ) ;
unsigned int V_146 , V_147 ;
if ( F_20 ( V_2 -> V_19 == V_20 ) )
return;
V_146 = F_23 ( V_2 , V_148 ) ;
if ( V_146 & V_149 )
return;
V_2 -> V_19 = V_20 ;
V_147 = F_23 ( V_2 , V_122 ) ;
if ( V_147 & V_82 )
F_35 ( V_2 , & V_147 ) ;
F_44 ( V_2 ) ;
if ( V_147 & V_81 )
F_38 ( V_2 ) ;
V_2 -> V_19 = NULL ;
}
static int F_49 ( struct V_150 * V_151 )
{
struct V_1 * V_2 =
F_50 ( V_151 , struct V_1 , V_2 ) ;
unsigned int V_4 = F_19 ( V_2 ) ;
if ( V_4 )
return 1 ;
V_4 = F_27 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( V_4 & V_28 )
return 1 ;
return 0 ;
}
static void F_51 ( struct V_150 * V_151 , int V_152 )
{
struct V_1 * V_2 =
F_50 ( V_151 , struct V_1 , V_2 ) ;
int V_4 = F_19 ( V_2 ) ;
if ( V_4 )
return;
if ( V_152 == 0 )
F_52 ( V_2 , V_39 | V_37 ) ;
else
F_53 ( V_2 , V_39 | V_37 ) ;
F_22 ( V_2 ) ;
}
static int F_54 ( struct V_150 * V_151 , struct V_126 * V_127 )
{
struct V_1 * V_2 =
F_50 ( V_151 , struct V_1 , V_2 ) ;
int V_4 ;
F_55 ( V_153 , & V_127 -> V_154 ) ;
F_56 ( & V_2 -> V_8 ) ;
V_4 = F_19 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_57 ( V_2 -> V_16 ) ;
if ( V_4 )
goto V_155;
V_4 = F_58 ( V_2 -> V_16 , F_47 ) ;
if ( V_4 )
goto V_156;
F_25 ( V_2 , V_104 , V_76 ) ;
F_25 ( V_2 , V_104 , V_76 |
V_157 | V_158 ) ;
F_25 ( V_2 , V_104 , 0 ) ;
( void ) F_23 ( V_2 , V_122 ) ;
( void ) F_23 ( V_2 , V_110 ) ;
( void ) F_23 ( V_2 , V_148 ) ;
( void ) F_23 ( V_2 , V_26 ) ;
F_25 ( V_2 , V_100 , V_66 ) ;
V_2 -> V_94 = V_106 | V_159 | V_160 | V_161 ;
V_2 -> V_35 = V_43 ;
F_30 ( V_2 , & V_127 -> V_52 , NULL ) ;
if ( F_59 ( V_127 ) )
F_53 ( V_2 , V_37 | V_39 ) ;
if ( F_46 ( V_127 ) )
if ( ! ( F_27 ( V_2 ) & V_34 ) )
V_127 -> V_134 = 1 ;
F_60 ( V_153 , & V_127 -> V_154 ) ;
F_47 ( V_2 -> V_16 ) ;
F_22 ( V_2 ) ;
return 0 ;
V_156:
F_17 ( V_2 -> V_16 ) ;
V_155:
F_22 ( V_2 ) ;
return V_4 ;
}
static void F_61 ( struct V_150 * V_151 )
{
struct V_1 * V_2 =
F_50 ( V_151 , struct V_1 , V_2 ) ;
int V_4 ;
V_4 = F_19 ( V_2 ) ;
if ( V_4 )
return;
F_34 ( V_2 ) ;
F_16 ( V_2 -> V_16 ) ;
V_2 -> V_94 = 0 ;
F_25 ( V_2 , V_99 , 0 ) ;
F_52 ( V_2 , V_43 ) ;
V_2 -> V_98 &= ~ V_162 ;
F_25 ( V_2 , V_100 , V_2 -> V_98 ) ;
F_25 ( V_2 , V_104 , V_76 |
V_157 |
V_158 ) ;
F_25 ( V_2 , V_104 , 0 ) ;
F_17 ( V_2 -> V_16 ) ;
F_22 ( V_2 ) ;
}
static void F_62 ( struct V_150 * V_151 )
{
struct V_1 * V_2 =
F_50 ( V_151 , struct V_1 , V_2 ) ;
F_63 ( & V_2 -> V_8 ) ;
F_64 ( V_2 ) ;
}
static int F_65 ( struct V_163 * V_164 , struct V_126 * V_127 )
{
int V_165 = V_127 -> V_3 ;
struct V_1 * V_2 = F_7 ( V_165 ) ;
int V_4 = F_66 ( V_164 , V_127 ) ;
if ( V_4 == 0 )
V_127 -> V_166 = V_2 ;
else
F_9 ( V_2 ) ;
return V_4 ;
}
static void F_67 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
V_127 -> V_166 = NULL ;
F_9 ( V_2 ) ;
}
static int F_68 ( struct V_126 * V_127 , struct V_167 * V_168 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
return F_69 ( & V_2 -> V_2 , V_127 , V_168 ) ;
}
static void F_70 ( struct V_126 * V_127 , struct V_167 * V_168 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
F_71 ( & V_2 -> V_2 , V_127 , V_168 ) ;
}
static void F_72 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
F_73 ( & V_2 -> V_2 ) ;
}
static int F_74 ( struct V_126 * V_127 , const unsigned char * V_169 ,
int V_125 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
int V_4 ;
if ( ! V_2 -> V_16 )
return - V_18 ;
V_4 = F_75 ( & V_2 -> V_8 , V_169 , V_125 , & V_2 -> V_7 ) ;
if ( ! ( V_2 -> V_94 & V_105 ) ) {
int V_170 = F_19 ( V_2 ) ;
if ( ! V_170 ) {
F_32 ( V_2 ) ;
F_47 ( V_2 -> V_16 ) ;
F_22 ( V_2 ) ;
} else
V_4 = V_170 ;
}
return V_4 ;
}
static int F_76 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
return V_9 - F_40 ( & V_2 -> V_8 ) ;
}
static int F_77 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
return F_40 ( & V_2 -> V_8 ) ;
}
static void F_78 ( struct V_126 * V_127 , char V_107 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
V_2 -> V_130 = V_107 ;
if ( V_107 && ! ( V_2 -> V_94 & V_105 ) ) {
if ( F_19 ( V_2 ) != 0 )
return;
F_32 ( V_2 ) ;
F_47 ( V_2 -> V_16 ) ;
F_22 ( V_2 ) ;
}
}
static void F_79 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
if ( ! F_80 ( V_127 ) && ! F_46 ( V_127 ) )
return;
if ( F_19 ( V_2 ) != 0 )
return;
if ( F_80 ( V_127 ) ) {
V_2 -> V_130 = F_81 ( V_127 ) ;
F_32 ( V_2 ) ;
}
if ( F_46 ( V_127 ) )
F_52 ( V_2 , V_37 ) ;
F_47 ( V_2 -> V_16 ) ;
F_22 ( V_2 ) ;
}
static void F_82 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
if ( ! F_80 ( V_127 ) && ! F_46 ( V_127 ) )
return;
if ( F_19 ( V_2 ) != 0 )
return;
if ( F_80 ( V_127 ) ) {
if ( V_2 -> V_130 ) {
V_2 -> V_130 = 0 ;
} else {
V_2 -> V_130 = F_83 ( V_127 ) ;
F_32 ( V_2 ) ;
}
}
if ( F_46 ( V_127 ) )
F_53 ( V_2 , V_37 ) ;
F_47 ( V_2 -> V_16 ) ;
F_22 ( V_2 ) ;
}
static void F_84 ( struct V_126 * V_127 ,
struct V_51 * V_171 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
unsigned int V_172 = V_127 -> V_52 . V_57 ;
if ( F_19 ( V_2 ) != 0 )
return;
F_30 ( V_2 , & V_127 -> V_52 , V_171 ) ;
if ( ( V_171 -> V_57 & V_74 ) && ! ( V_172 & V_74 ) )
F_52 ( V_2 , V_37 | V_39 ) ;
if ( ! ( V_171 -> V_57 & V_74 ) && ( V_172 & V_74 ) ) {
unsigned int V_173 = V_39 ;
if ( ! ( V_172 & V_96 ) || ! F_85 ( V_127 ) )
V_173 |= V_37 ;
F_53 ( V_2 , V_173 ) ;
}
if ( ( V_171 -> V_57 & V_96 ) && ! ( V_172 & V_96 ) ) {
V_127 -> V_134 = 0 ;
F_32 ( V_2 ) ;
}
if ( ! ( V_171 -> V_57 & V_96 ) && ( V_172 & V_96 ) ) {
if ( ! ( F_27 ( V_2 ) & V_34 ) ) {
V_127 -> V_134 = 1 ;
F_33 ( V_2 ) ;
}
}
F_22 ( V_2 ) ;
}
static int F_86 ( struct V_126 * V_127 , int V_174 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
int V_175 ;
V_175 = F_19 ( V_2 ) ;
if ( V_175 != 0 )
return V_175 ;
if ( V_174 == - 1 )
V_2 -> V_98 |= V_162 ;
else
V_2 -> V_98 &= ~ V_162 ;
F_25 ( V_2 , V_100 , V_2 -> V_98 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
int V_175 ;
V_175 = F_19 ( V_2 ) ;
if ( ! V_175 ) {
V_175 = V_2 -> V_35 | F_27 ( V_2 ) ;
F_22 ( V_2 ) ;
}
return V_175 ;
}
static int F_88 ( struct V_126 * V_127 ,
unsigned int V_48 , unsigned int V_49 )
{
struct V_1 * V_2 = V_127 -> V_166 ;
int V_175 ;
V_175 = F_19 ( V_2 ) ;
if ( ! V_175 ) {
F_29 ( V_2 , V_48 , V_49 ) ;
F_22 ( V_2 ) ;
}
return V_175 ;
}
static int F_89 ( struct V_176 * V_177 , void * V_178 )
{
int V_179 ;
F_90 ( V_177 , L_1 ,
L_2 , L_2 , L_2 ) ;
for ( V_179 = 0 ; V_179 < V_13 ; V_179 ++ ) {
struct V_1 * V_2 = F_7 ( V_179 ) ;
if ( V_2 ) {
F_90 ( V_177 , L_3 , V_179 ) ;
if ( F_91 ( V_180 ) ) {
F_90 ( V_177 , L_4 ,
V_2 -> V_112 . V_132 , V_2 -> V_112 . V_113 ) ;
if ( V_2 -> V_112 . V_116 )
F_90 ( V_177 , L_5 ,
V_2 -> V_112 . V_116 ) ;
if ( V_2 -> V_112 . V_115 )
F_90 ( V_177 , L_6 ,
V_2 -> V_112 . V_115 ) ;
if ( V_2 -> V_112 . V_114 )
F_90 ( V_177 , L_7 ,
V_2 -> V_112 . V_114 ) ;
if ( V_2 -> V_112 . V_117 )
F_90 ( V_177 , L_8 ,
V_2 -> V_112 . V_117 ) ;
if ( V_2 -> V_112 . V_145 )
F_90 ( V_177 , L_9 ,
V_2 -> V_112 . V_145 ) ;
if ( V_2 -> V_112 . V_140 )
F_90 ( V_177 , L_10 ,
V_2 -> V_112 . V_140 ) ;
if ( V_2 -> V_112 . V_138 )
F_90 ( V_177 , L_11 ,
V_2 -> V_112 . V_138 ) ;
if ( V_2 -> V_112 . V_142 )
F_90 ( V_177 , L_12 ,
V_2 -> V_112 . V_142 ) ;
}
F_9 ( V_2 ) ;
F_92 ( V_177 , '\n' ) ;
}
}
return 0 ;
}
static int F_93 ( struct V_181 * V_181 , struct V_167 * V_167 )
{
return F_94 ( V_167 , F_89 , NULL ) ;
}
static int F_95 ( struct V_15 * V_16 ,
const struct V_182 * V_183 )
{
struct V_1 * V_2 ;
int V_4 ;
V_2 = F_96 ( sizeof( struct V_1 ) , V_10 ) ;
if ( ! V_2 )
return - V_11 ;
if ( V_16 -> V_184 == V_185 ) {
F_97 ( L_13 ,
F_98 ( V_16 ) ) ;
F_64 ( V_2 ) ;
return - V_186 ;
} else if ( V_16 -> V_184 == V_187 ) {
struct V_188 * V_189 ;
for ( V_189 = V_16 -> V_190 ; V_189 ; V_189 = V_189 -> V_191 ) {
if ( V_189 -> V_192 != 0x91 )
continue;
if ( V_189 -> V_193 < 10 )
continue;
if ( V_189 -> V_194 [ 1 ] == 0 )
break;
}
if ( ! V_189 ) {
F_97 ( L_14 ,
F_98 ( V_16 ) ) ;
F_64 ( V_2 ) ;
return - V_195 ;
}
F_99 ( L_15 ,
F_98 ( V_16 ) , V_189 -> V_194 [ 2 ] , V_189 -> V_194 [ 3 ] ) ;
V_2 -> V_23 = ( V_189 -> V_194 [ 4 ] << 0 ) |
( V_189 -> V_194 [ 5 ] << 8 ) |
( V_189 -> V_194 [ 6 ] << 16 ) ;
F_99 ( L_16 ,
F_98 ( V_16 ) , V_2 -> V_23 ) ;
V_2 -> V_73 = V_189 -> V_194 [ 7 ] * 115200 ;
if ( V_2 -> V_73 == 0 )
V_2 -> V_73 = 115200 ;
F_99 ( L_17 ,
F_98 ( V_16 ) , V_2 -> V_73 ,
V_189 -> V_194 [ 7 ] , V_189 -> V_194 [ 8 ] | ( V_189 -> V_194 [ 9 ] << 8 ) ) ;
} else {
F_64 ( V_2 ) ;
return - V_195 ;
}
V_2 -> V_16 = V_16 ;
F_100 ( V_16 , V_2 ) ;
F_101 ( & V_2 -> V_2 ) ;
V_2 -> V_2 . V_196 = & V_197 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 ) {
F_64 ( V_2 ) ;
} else {
struct V_198 * V_199 ;
V_199 = F_102 ( & V_2 -> V_2 ,
V_200 , V_2 -> V_3 , & V_16 -> V_199 ) ;
if ( F_103 ( V_199 ) ) {
F_11 ( V_2 ) ;
V_4 = F_104 ( V_199 ) ;
}
}
return V_4 ;
}
static void F_105 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_48 ( V_16 ) ;
F_106 ( V_200 , V_2 -> V_3 ) ;
F_11 ( V_2 ) ;
}
static int T_2 F_107 ( void )
{
int V_4 ;
struct V_163 * V_201 ;
V_200 = V_201 = F_108 ( V_13 ) ;
if ( ! V_201 )
return - V_11 ;
V_201 -> V_202 = L_18 ;
V_201 -> V_203 = L_19 ;
V_201 -> V_204 = 0 ;
V_201 -> V_205 = 0 ;
V_201 -> type = V_206 ;
V_201 -> V_207 = V_208 ;
V_201 -> V_154 = V_209 | V_210 ;
V_201 -> V_211 = V_212 ;
V_201 -> V_211 . V_57 = V_213 | V_65 | V_93 | V_214 | V_97 ;
V_201 -> V_211 . V_215 = 4800 ;
V_201 -> V_211 . V_216 = 4800 ;
F_109 ( V_201 , & V_217 ) ;
V_4 = F_110 ( V_201 ) ;
if ( V_4 )
goto V_155;
V_4 = F_111 ( & V_218 ) ;
if ( V_4 )
goto V_156;
return 0 ;
V_156:
F_112 ( V_201 ) ;
V_155:
F_113 ( V_201 ) ;
return V_4 ;
}
static void T_3 F_114 ( void )
{
F_115 ( & V_218 ) ;
F_112 ( V_200 ) ;
F_113 ( V_200 ) ;
}

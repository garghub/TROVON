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
struct V_17 * V_18 ;
F_12 ( V_14 [ V_2 -> V_3 ] != V_2 ) ;
F_5 ( & V_12 ) ;
V_14 [ V_2 -> V_3 ] = NULL ;
F_6 ( & V_12 ) ;
F_13 ( & V_2 -> V_2 . V_19 ) ;
F_13 ( & V_2 -> V_6 ) ;
V_16 = V_2 -> V_16 ;
F_14 ( V_16 ) ;
V_2 -> V_16 = NULL ;
F_15 ( & V_2 -> V_6 ) ;
V_18 = F_16 ( & V_2 -> V_2 ) ;
if ( V_18 ) {
F_17 ( V_18 ) ;
F_18 ( V_18 ) ;
}
F_15 ( & V_2 -> V_2 . V_19 ) ;
F_19 ( V_16 ) ;
F_20 ( V_16 ) ;
F_21 ( V_16 ) ;
F_9 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_6 ) ;
if ( F_23 ( ! V_2 -> V_16 ) ) {
F_15 ( & V_2 -> V_6 ) ;
return - V_20 ;
}
if ( F_24 ( V_2 -> V_21 != V_22 ) )
F_14 ( V_2 -> V_16 ) ;
F_15 ( & V_2 -> V_6 ) ;
return 0 ;
}
static inline void F_25 ( struct V_1 * V_2 )
{
if ( F_24 ( V_2 -> V_21 != V_22 ) )
F_21 ( V_2 -> V_16 ) ;
}
static inline unsigned int F_26 ( struct V_1 * V_2 , int V_23 )
{
unsigned char V_24 ;
V_24 = F_27 ( V_2 -> V_16 , V_2 -> V_25 + V_23 , NULL ) ;
return V_24 ;
}
static inline void F_28 ( struct V_1 * V_2 , int V_23 , int V_26 )
{
F_29 ( V_2 -> V_16 , V_26 , V_2 -> V_25 + V_23 , NULL ) ;
}
static unsigned int F_30 ( struct V_1 * V_2 )
{
unsigned char V_27 ;
unsigned int V_4 ;
V_27 = F_26 ( V_2 , V_28 ) ;
V_4 = 0 ;
if ( V_27 & V_29 )
V_4 |= V_30 ;
if ( V_27 & V_31 )
V_4 |= V_32 ;
if ( V_27 & V_33 )
V_4 |= V_34 ;
if ( V_27 & V_35 )
V_4 |= V_36 ;
return V_4 ;
}
static void F_31 ( struct V_1 * V_2 ,
unsigned int V_37 )
{
unsigned char V_38 = 0 ;
if ( V_37 & V_39 )
V_38 |= V_40 ;
if ( V_37 & V_41 )
V_38 |= V_42 ;
if ( V_37 & V_43 )
V_38 |= V_44 ;
if ( V_37 & V_45 )
V_38 |= V_46 ;
if ( V_37 & V_47 )
V_38 |= V_48 ;
F_28 ( V_2 , V_49 , V_38 ) ;
}
static inline void F_32 ( struct V_1 * V_2 ,
unsigned int V_50 , unsigned int V_51 )
{
unsigned int V_52 ;
V_52 = V_2 -> V_37 ;
V_2 -> V_37 = ( V_52 & ~ V_51 ) | V_50 ;
if ( V_52 != V_2 -> V_37 )
F_31 ( V_2 , V_2 -> V_37 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_53 * V_54 ,
struct V_53 * V_52 )
{
unsigned char V_55 , V_56 = 0 ;
unsigned int V_57 , V_58 ;
switch ( V_54 -> V_59 & V_60 ) {
case V_61 :
V_55 = V_62 ;
break;
case V_63 :
V_55 = V_64 ;
break;
case V_65 :
V_55 = V_66 ;
break;
default:
case V_67 :
V_55 = V_68 ;
break;
}
if ( V_54 -> V_59 & V_69 )
V_55 |= V_70 ;
if ( V_54 -> V_59 & V_71 )
V_55 |= V_72 ;
if ( ! ( V_54 -> V_59 & V_73 ) )
V_55 |= V_74 ;
for (; ; ) {
V_57 = F_34 ( V_54 ) ;
if ( V_57 == 0 )
V_57 = 9600 ;
if ( V_57 <= V_2 -> V_75 )
break;
V_54 -> V_59 &= ~ V_76 ;
if ( V_52 ) {
V_54 -> V_59 |= V_52 -> V_59 & V_76 ;
V_52 = NULL ;
} else
V_54 -> V_59 |= V_77 ;
}
V_58 = ( 2 * V_2 -> V_75 + V_57 ) / ( 2 * V_57 ) ;
if ( V_57 < 2400 )
V_56 = V_78 | V_79 ;
else
V_56 = V_78 | V_80 ;
V_2 -> V_81 = V_82 | V_83 | V_84 ;
if ( V_54 -> V_85 & V_86 )
V_2 -> V_81 |= V_87 | V_88 ;
if ( V_54 -> V_85 & ( V_89 | V_90 ) )
V_2 -> V_81 |= V_91 ;
V_2 -> V_92 = 0 ;
if ( V_54 -> V_85 & V_93 )
V_2 -> V_92 |= V_88 | V_87 ;
if ( V_54 -> V_85 & V_94 ) {
V_2 -> V_92 |= V_91 ;
if ( V_54 -> V_85 & V_93 )
V_2 -> V_92 |= V_82 ;
}
if ( ( V_54 -> V_59 & V_95 ) == 0 )
V_2 -> V_92 |= V_84 ;
V_2 -> V_96 &= ~ V_97 ;
if ( ( V_54 -> V_59 & V_98 ) || ! ( V_54 -> V_59 & V_99 ) )
V_2 -> V_96 |= V_97 ;
V_2 -> V_100 = V_55 ;
F_28 ( V_2 , V_101 , V_2 -> V_96 ) ;
F_28 ( V_2 , V_102 , V_55 | V_103 ) ;
F_28 ( V_2 , V_104 , V_58 & 0xff ) ;
F_28 ( V_2 , V_105 , V_58 >> 8 ) ;
F_28 ( V_2 , V_102 , V_55 ) ;
F_28 ( V_2 , V_106 , V_56 ) ;
F_31 ( V_2 , V_2 -> V_37 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_96 & V_107 ) ) {
V_2 -> V_96 |= V_107 ;
F_28 ( V_2 , V_101 , V_2 -> V_96 ) ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_96 & V_107 ) {
V_2 -> V_96 &= ~ V_107 ;
F_28 ( V_2 , V_101 , V_2 -> V_96 ) ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
V_2 -> V_96 &= ~ V_108 ;
V_2 -> V_81 &= ~ V_84 ;
F_28 ( V_2 , V_101 , V_2 -> V_96 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
unsigned int * V_27 )
{
struct V_17 * V_18 = F_16 ( & V_2 -> V_2 ) ;
unsigned int V_109 , V_110 ;
int V_111 = 256 ;
do {
V_109 = F_26 ( V_2 , V_112 ) ;
V_110 = V_113 ;
V_2 -> V_114 . V_115 ++ ;
if ( F_23 ( * V_27 & ( V_91 | V_88 |
V_87 | V_82 ) ) ) {
if ( * V_27 & V_91 ) {
* V_27 &= ~ ( V_87 | V_88 ) ;
V_2 -> V_114 . V_116 ++ ;
} else if ( * V_27 & V_88 )
V_2 -> V_114 . V_117 ++ ;
else if ( * V_27 & V_87 )
V_2 -> V_114 . V_118 ++ ;
if ( * V_27 & V_82 )
V_2 -> V_114 . V_119 ++ ;
* V_27 &= V_2 -> V_81 ;
if ( * V_27 & V_91 )
V_110 = V_120 ;
else if ( * V_27 & V_88 )
V_110 = V_121 ;
else if ( * V_27 & V_87 )
V_110 = V_122 ;
}
if ( ( * V_27 & V_2 -> V_92 & ~ V_82 ) == 0 )
if ( V_18 )
F_39 ( V_18 , V_109 , V_110 ) ;
if ( * V_27 & ~ V_2 -> V_92 & V_82 )
if ( V_18 )
F_39 ( V_18 , 0 , V_123 ) ;
* V_27 = F_26 ( V_2 , V_124 ) ;
} while ( ( * V_27 & V_84 ) && ( V_111 -- > 0 ) );
if ( V_18 ) {
F_40 ( V_18 ) ;
F_18 ( V_18 ) ;
}
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_125 * V_126 = & V_2 -> V_8 ;
int V_127 ;
struct V_17 * V_18 ;
T_1 V_128 [ 16 ] ;
int V_129 ;
if ( V_2 -> V_130 ) {
F_28 ( V_2 , V_131 , V_2 -> V_130 ) ;
V_2 -> V_114 . V_132 ++ ;
V_2 -> V_130 = 0 ;
return;
}
V_18 = F_16 ( & V_2 -> V_2 ) ;
if ( V_18 == NULL || ! F_42 ( V_126 ) ||
V_18 -> V_133 || V_18 -> V_134 ) {
F_36 ( V_2 ) ;
F_18 ( V_18 ) ;
return;
}
V_129 = F_43 ( V_126 , V_128 , 16 , & V_2 -> V_7 ) ;
for ( V_127 = 0 ; V_127 < V_129 ; V_127 ++ ) {
F_28 ( V_2 , V_131 , V_128 [ V_127 ] ) ;
V_2 -> V_114 . V_132 ++ ;
}
V_129 = F_42 ( V_126 ) ;
if ( V_129 < V_135 ) {
F_44 ( V_18 ) ;
if ( V_129 == 0 )
F_36 ( V_2 ) ;
}
F_18 ( V_18 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_27 ;
struct V_17 * V_18 ;
V_27 = F_26 ( V_2 , V_28 ) ;
if ( ( V_27 & V_136 ) == 0 )
return;
if ( V_27 & V_137 )
V_2 -> V_114 . V_138 ++ ;
if ( V_27 & V_139 )
V_2 -> V_114 . V_140 ++ ;
if ( V_27 & V_141 ) {
V_2 -> V_114 . V_142 ++ ;
if ( V_27 & V_29 )
F_46 ( & V_2 -> V_2 . V_143 ) ;
else {
V_18 = F_16 ( & V_2 -> V_2 ) ;
if ( V_18 ) {
F_17 ( V_18 ) ;
F_18 ( V_18 ) ;
}
}
}
if ( V_27 & V_144 ) {
V_2 -> V_114 . V_145 ++ ;
V_18 = F_16 ( & V_2 -> V_2 ) ;
if ( V_18 && ( V_18 -> V_54 . V_59 & V_98 ) ) {
int V_145 = ( V_27 & V_35 ) ;
if ( V_18 -> V_134 ) {
if ( V_145 ) {
V_18 -> V_134 = 0 ;
F_35 ( V_2 ) ;
F_44 ( V_18 ) ;
}
} else {
if ( ! V_145 ) {
V_18 -> V_134 = 1 ;
F_36 ( V_2 ) ;
}
}
}
F_18 ( V_18 ) ;
}
}
static void F_47 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_48 ( V_16 ) ;
unsigned int V_146 , V_147 ;
if ( F_23 ( V_2 -> V_21 == V_22 ) )
return;
V_146 = F_26 ( V_2 , V_148 ) ;
if ( V_146 & V_149 )
return;
V_2 -> V_21 = V_22 ;
V_147 = F_26 ( V_2 , V_124 ) ;
if ( V_147 & V_84 )
F_38 ( V_2 , & V_147 ) ;
F_45 ( V_2 ) ;
if ( V_147 & V_83 )
F_41 ( V_2 ) ;
V_2 -> V_21 = NULL ;
}
static int F_49 ( struct V_150 * V_151 )
{
struct V_1 * V_2 =
F_50 ( V_151 , struct V_1 , V_2 ) ;
unsigned int V_4 = F_22 ( V_2 ) ;
if ( V_4 )
return 1 ;
V_4 = F_30 ( V_2 ) ;
F_25 ( V_2 ) ;
if ( V_4 & V_30 )
return 1 ;
return 0 ;
}
static void F_51 ( struct V_150 * V_151 , int V_152 )
{
struct V_1 * V_2 =
F_50 ( V_151 , struct V_1 , V_2 ) ;
int V_4 = F_22 ( V_2 ) ;
if ( V_4 )
return;
if ( V_152 == 0 )
F_52 ( V_2 , V_41 | V_39 ) ;
else
F_53 ( V_2 , V_41 | V_39 ) ;
F_25 ( V_2 ) ;
}
static int F_54 ( struct V_150 * V_151 , struct V_17 * V_18 )
{
struct V_1 * V_2 =
F_50 ( V_151 , struct V_1 , V_2 ) ;
int V_4 ;
F_55 ( V_153 , & V_18 -> V_154 ) ;
F_56 ( & V_2 -> V_8 ) ;
V_4 = F_22 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_57 ( V_2 -> V_16 ) ;
if ( V_4 )
goto V_155;
V_4 = F_58 ( V_2 -> V_16 , F_47 ) ;
if ( V_4 )
goto V_156;
F_28 ( V_2 , V_106 , V_78 ) ;
F_28 ( V_2 , V_106 , V_78 |
V_157 | V_158 ) ;
F_28 ( V_2 , V_106 , 0 ) ;
( void ) F_26 ( V_2 , V_124 ) ;
( void ) F_26 ( V_2 , V_112 ) ;
( void ) F_26 ( V_2 , V_148 ) ;
( void ) F_26 ( V_2 , V_28 ) ;
F_28 ( V_2 , V_102 , V_68 ) ;
V_2 -> V_96 = V_108 | V_159 | V_160 | V_161 ;
V_2 -> V_37 = V_45 ;
F_33 ( V_2 , & V_18 -> V_54 , NULL ) ;
if ( V_18 -> V_54 . V_59 & V_76 )
F_53 ( V_2 , V_39 | V_41 ) ;
if ( V_18 -> V_54 . V_59 & V_98 )
if ( ! ( F_30 ( V_2 ) & V_36 ) )
V_18 -> V_134 = 1 ;
F_59 ( V_153 , & V_18 -> V_154 ) ;
F_47 ( V_2 -> V_16 ) ;
F_25 ( V_2 ) ;
return 0 ;
V_156:
F_20 ( V_2 -> V_16 ) ;
V_155:
F_25 ( V_2 ) ;
return V_4 ;
}
static void F_60 ( struct V_150 * V_151 )
{
struct V_1 * V_2 =
F_50 ( V_151 , struct V_1 , V_2 ) ;
int V_4 ;
V_4 = F_22 ( V_2 ) ;
if ( V_4 )
return;
F_37 ( V_2 ) ;
F_19 ( V_2 -> V_16 ) ;
V_2 -> V_96 = 0 ;
F_28 ( V_2 , V_101 , 0 ) ;
F_52 ( V_2 , V_45 ) ;
V_2 -> V_100 &= ~ V_162 ;
F_28 ( V_2 , V_102 , V_2 -> V_100 ) ;
F_28 ( V_2 , V_106 , V_78 |
V_157 |
V_158 ) ;
F_28 ( V_2 , V_106 , 0 ) ;
F_20 ( V_2 -> V_16 ) ;
F_25 ( V_2 ) ;
}
static void F_61 ( struct V_150 * V_151 )
{
struct V_1 * V_2 =
F_50 ( V_151 , struct V_1 , V_2 ) ;
F_62 ( & V_2 -> V_8 ) ;
F_63 ( V_2 ) ;
}
static int F_64 ( struct V_163 * V_164 , struct V_17 * V_18 )
{
int V_165 = V_18 -> V_3 ;
struct V_1 * V_2 = F_7 ( V_165 ) ;
int V_4 = F_65 ( V_164 , V_18 ) ;
if ( V_4 == 0 )
V_18 -> V_166 = V_2 ;
else
F_9 ( V_2 ) ;
return V_4 ;
}
static void F_66 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_166 ;
V_18 -> V_166 = NULL ;
F_9 ( V_2 ) ;
}
static int F_67 ( struct V_17 * V_18 , struct V_167 * V_168 )
{
struct V_1 * V_2 = V_18 -> V_166 ;
return F_68 ( & V_2 -> V_2 , V_18 , V_168 ) ;
}
static void F_69 ( struct V_17 * V_18 , struct V_167 * V_168 )
{
struct V_1 * V_2 = V_18 -> V_166 ;
F_70 ( & V_2 -> V_2 , V_18 , V_168 ) ;
}
static void F_71 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_166 ;
F_72 ( & V_2 -> V_2 ) ;
}
static int F_73 ( struct V_17 * V_18 , const unsigned char * V_169 ,
int V_127 )
{
struct V_1 * V_2 = V_18 -> V_166 ;
int V_4 ;
if ( ! V_2 -> V_16 )
return - V_20 ;
V_4 = F_74 ( & V_2 -> V_8 , V_169 , V_127 , & V_2 -> V_7 ) ;
if ( ! ( V_2 -> V_96 & V_107 ) ) {
int V_170 = F_22 ( V_2 ) ;
if ( ! V_170 ) {
F_35 ( V_2 ) ;
F_47 ( V_2 -> V_16 ) ;
F_25 ( V_2 ) ;
} else
V_4 = V_170 ;
}
return V_4 ;
}
static int F_75 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_166 ;
return V_9 - F_42 ( & V_2 -> V_8 ) ;
}
static int F_76 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_166 ;
return F_42 ( & V_2 -> V_8 ) ;
}
static void F_77 ( struct V_17 * V_18 , char V_109 )
{
struct V_1 * V_2 = V_18 -> V_166 ;
V_2 -> V_130 = V_109 ;
if ( V_109 && ! ( V_2 -> V_96 & V_107 ) ) {
if ( F_22 ( V_2 ) != 0 )
return;
F_35 ( V_2 ) ;
F_47 ( V_2 -> V_16 ) ;
F_25 ( V_2 ) ;
}
}
static void F_78 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_166 ;
if ( ! F_79 ( V_18 ) && ! ( V_18 -> V_54 . V_59 & V_98 ) )
return;
if ( F_22 ( V_2 ) != 0 )
return;
if ( F_79 ( V_18 ) ) {
V_2 -> V_130 = F_80 ( V_18 ) ;
F_35 ( V_2 ) ;
}
if ( V_18 -> V_54 . V_59 & V_98 )
F_52 ( V_2 , V_39 ) ;
F_47 ( V_2 -> V_16 ) ;
F_25 ( V_2 ) ;
}
static void F_81 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_166 ;
if ( ! F_79 ( V_18 ) && ! ( V_18 -> V_54 . V_59 & V_98 ) )
return;
if ( F_22 ( V_2 ) != 0 )
return;
if ( F_79 ( V_18 ) ) {
if ( V_2 -> V_130 ) {
V_2 -> V_130 = 0 ;
} else {
V_2 -> V_130 = F_82 ( V_18 ) ;
F_35 ( V_2 ) ;
}
}
if ( V_18 -> V_54 . V_59 & V_98 )
F_53 ( V_2 , V_39 ) ;
F_47 ( V_2 -> V_16 ) ;
F_25 ( V_2 ) ;
}
static void F_83 ( struct V_17 * V_18 ,
struct V_53 * V_171 )
{
struct V_1 * V_2 = V_18 -> V_166 ;
unsigned int V_172 = V_18 -> V_54 . V_59 ;
if ( F_22 ( V_2 ) != 0 )
return;
F_33 ( V_2 , & V_18 -> V_54 , V_171 ) ;
if ( ( V_171 -> V_59 & V_76 ) && ! ( V_172 & V_76 ) )
F_52 ( V_2 , V_39 | V_41 ) ;
if ( ! ( V_171 -> V_59 & V_76 ) && ( V_172 & V_76 ) ) {
unsigned int V_173 = V_41 ;
if ( ! ( V_172 & V_98 ) || ! F_84 ( V_174 , & V_18 -> V_154 ) )
V_173 |= V_39 ;
F_53 ( V_2 , V_173 ) ;
}
if ( ( V_171 -> V_59 & V_98 ) && ! ( V_172 & V_98 ) ) {
V_18 -> V_134 = 0 ;
F_35 ( V_2 ) ;
}
if ( ! ( V_171 -> V_59 & V_98 ) && ( V_172 & V_98 ) ) {
if ( ! ( F_30 ( V_2 ) & V_36 ) ) {
V_18 -> V_134 = 1 ;
F_36 ( V_2 ) ;
}
}
F_25 ( V_2 ) ;
}
static int F_85 ( struct V_17 * V_18 , int V_175 )
{
struct V_1 * V_2 = V_18 -> V_166 ;
int V_176 ;
V_176 = F_22 ( V_2 ) ;
if ( V_176 != 0 )
return V_176 ;
if ( V_175 == - 1 )
V_2 -> V_100 |= V_162 ;
else
V_2 -> V_100 &= ~ V_162 ;
F_28 ( V_2 , V_102 , V_2 -> V_100 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_86 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_166 ;
int V_176 ;
V_176 = F_22 ( V_2 ) ;
if ( ! V_176 ) {
V_176 = V_2 -> V_37 | F_30 ( V_2 ) ;
F_25 ( V_2 ) ;
}
return V_176 ;
}
static int F_87 ( struct V_17 * V_18 ,
unsigned int V_50 , unsigned int V_51 )
{
struct V_1 * V_2 = V_18 -> V_166 ;
int V_176 ;
V_176 = F_22 ( V_2 ) ;
if ( ! V_176 ) {
F_32 ( V_2 , V_50 , V_51 ) ;
F_25 ( V_2 ) ;
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
V_2 -> V_114 . V_132 , V_2 -> V_114 . V_115 ) ;
if ( V_2 -> V_114 . V_118 )
F_89 ( V_178 , L_5 ,
V_2 -> V_114 . V_118 ) ;
if ( V_2 -> V_114 . V_117 )
F_89 ( V_178 , L_6 ,
V_2 -> V_114 . V_117 ) ;
if ( V_2 -> V_114 . V_116 )
F_89 ( V_178 , L_7 ,
V_2 -> V_114 . V_116 ) ;
if ( V_2 -> V_114 . V_119 )
F_89 ( V_178 , L_8 ,
V_2 -> V_114 . V_119 ) ;
if ( V_2 -> V_114 . V_145 )
F_89 ( V_178 , L_9 ,
V_2 -> V_114 . V_145 ) ;
if ( V_2 -> V_114 . V_140 )
F_89 ( V_178 , L_10 ,
V_2 -> V_114 . V_140 ) ;
if ( V_2 -> V_114 . V_138 )
F_89 ( V_178 , L_11 ,
V_2 -> V_114 . V_138 ) ;
if ( V_2 -> V_114 . V_142 )
F_89 ( V_178 , L_12 ,
V_2 -> V_114 . V_142 ) ;
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
V_2 -> V_25 = ( V_190 -> V_195 [ 4 ] << 0 ) |
( V_190 -> V_195 [ 5 ] << 8 ) |
( V_190 -> V_195 [ 6 ] << 16 ) ;
F_98 ( L_16 ,
F_97 ( V_16 ) , V_2 -> V_25 ) ;
V_2 -> V_75 = V_190 -> V_195 [ 7 ] * 115200 ;
if ( V_2 -> V_75 == 0 )
V_2 -> V_75 = 115200 ;
F_98 ( L_17 ,
F_97 ( V_16 ) , V_2 -> V_75 ,
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
V_202 -> V_212 . V_59 = V_214 | V_67 | V_95 | V_215 | V_99 ;
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

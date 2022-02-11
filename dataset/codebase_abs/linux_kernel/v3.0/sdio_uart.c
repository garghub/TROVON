static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = - V_5 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_8 ) ;
if ( F_5 ( & V_2 -> V_9 , V_10 , V_11 ) )
return - V_12 ;
F_6 ( & V_13 ) ;
for ( V_3 = 0 ; V_3 < V_14 ; V_3 ++ ) {
if ( ! V_15 [ V_3 ] ) {
V_2 -> V_3 = V_3 ;
V_15 [ V_3 ] = V_2 ;
V_4 = 0 ;
break;
}
}
F_7 ( & V_13 ) ;
return V_4 ;
}
static struct V_1 * F_8 ( unsigned V_3 )
{
struct V_1 * V_2 ;
if ( V_3 >= V_14 )
return NULL ;
F_6 ( & V_13 ) ;
V_2 = V_15 [ V_3 ] ;
if ( V_2 )
F_9 ( & V_2 -> V_6 ) ;
F_7 ( & V_13 ) ;
return V_2 ;
}
static void F_10 ( struct V_6 * V_6 )
{
struct V_1 * V_2 =
F_11 ( V_6 , struct V_1 , V_6 ) ;
F_12 ( & V_2 -> V_9 ) ;
F_13 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_6 , F_10 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 ;
F_17 ( V_15 [ V_2 -> V_3 ] != V_2 ) ;
F_6 ( & V_13 ) ;
V_15 [ V_2 -> V_3 ] = NULL ;
F_7 ( & V_13 ) ;
F_18 ( & V_2 -> V_2 . V_20 ) ;
F_18 ( & V_2 -> V_7 ) ;
V_17 = V_2 -> V_17 ;
F_19 ( V_17 ) ;
V_2 -> V_17 = NULL ;
F_20 ( & V_2 -> V_7 ) ;
V_19 = F_21 ( & V_2 -> V_2 ) ;
if ( V_19 ) {
F_22 ( V_19 ) ;
F_23 ( V_19 ) ;
}
F_20 ( & V_2 -> V_2 . V_20 ) ;
F_24 ( V_17 ) ;
F_25 ( V_17 ) ;
F_26 ( V_17 ) ;
F_14 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_7 ) ;
if ( F_28 ( ! V_2 -> V_17 ) ) {
F_20 ( & V_2 -> V_7 ) ;
return - V_21 ;
}
if ( F_29 ( V_2 -> V_22 != V_23 ) )
F_19 ( V_2 -> V_17 ) ;
F_20 ( & V_2 -> V_7 ) ;
return 0 ;
}
static inline void F_30 ( struct V_1 * V_2 )
{
if ( F_29 ( V_2 -> V_22 != V_23 ) )
F_26 ( V_2 -> V_17 ) ;
}
static inline unsigned int F_31 ( struct V_1 * V_2 , int V_24 )
{
unsigned char V_25 ;
V_25 = F_32 ( V_2 -> V_17 , V_2 -> V_26 + V_24 , NULL ) ;
return V_25 ;
}
static inline void F_33 ( struct V_1 * V_2 , int V_24 , int V_27 )
{
F_34 ( V_2 -> V_17 , V_27 , V_2 -> V_26 + V_24 , NULL ) ;
}
static unsigned int F_35 ( struct V_1 * V_2 )
{
unsigned char V_28 ;
unsigned int V_4 ;
V_28 = F_31 ( V_2 , V_29 ) ;
V_4 = 0 ;
if ( V_28 & V_30 )
V_4 |= V_31 ;
if ( V_28 & V_32 )
V_4 |= V_33 ;
if ( V_28 & V_34 )
V_4 |= V_35 ;
if ( V_28 & V_36 )
V_4 |= V_37 ;
return V_4 ;
}
static void F_36 ( struct V_1 * V_2 ,
unsigned int V_38 )
{
unsigned char V_39 = 0 ;
if ( V_38 & V_40 )
V_39 |= V_41 ;
if ( V_38 & V_42 )
V_39 |= V_43 ;
if ( V_38 & V_44 )
V_39 |= V_45 ;
if ( V_38 & V_46 )
V_39 |= V_47 ;
if ( V_38 & V_48 )
V_39 |= V_49 ;
F_33 ( V_2 , V_50 , V_39 ) ;
}
static inline void F_37 ( struct V_1 * V_2 ,
unsigned int V_51 , unsigned int V_52 )
{
unsigned int V_53 ;
V_53 = V_2 -> V_38 ;
V_2 -> V_38 = ( V_53 & ~ V_52 ) | V_51 ;
if ( V_53 != V_2 -> V_38 )
F_36 ( V_2 , V_2 -> V_38 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
struct V_54 * V_53 )
{
unsigned char V_56 , V_57 = 0 ;
unsigned int V_58 , V_59 ;
switch ( V_55 -> V_60 & V_61 ) {
case V_62 :
V_56 = V_63 ;
break;
case V_64 :
V_56 = V_65 ;
break;
case V_66 :
V_56 = V_67 ;
break;
default:
case V_68 :
V_56 = V_69 ;
break;
}
if ( V_55 -> V_60 & V_70 )
V_56 |= V_71 ;
if ( V_55 -> V_60 & V_72 )
V_56 |= V_73 ;
if ( ! ( V_55 -> V_60 & V_74 ) )
V_56 |= V_75 ;
for (; ; ) {
V_58 = F_39 ( V_55 ) ;
if ( V_58 == 0 )
V_58 = 9600 ;
if ( V_58 <= V_2 -> V_76 )
break;
V_55 -> V_60 &= ~ V_77 ;
if ( V_53 ) {
V_55 -> V_60 |= V_53 -> V_60 & V_77 ;
V_53 = NULL ;
} else
V_55 -> V_60 |= V_78 ;
}
V_59 = ( 2 * V_2 -> V_76 + V_58 ) / ( 2 * V_58 ) ;
if ( V_58 < 2400 )
V_57 = V_79 | V_80 ;
else
V_57 = V_79 | V_81 ;
V_2 -> V_82 = V_83 | V_84 | V_85 ;
if ( V_55 -> V_86 & V_87 )
V_2 -> V_82 |= V_88 | V_89 ;
if ( V_55 -> V_86 & ( V_90 | V_91 ) )
V_2 -> V_82 |= V_92 ;
V_2 -> V_93 = 0 ;
if ( V_55 -> V_86 & V_94 )
V_2 -> V_93 |= V_89 | V_88 ;
if ( V_55 -> V_86 & V_95 ) {
V_2 -> V_93 |= V_92 ;
if ( V_55 -> V_86 & V_94 )
V_2 -> V_93 |= V_83 ;
}
if ( ( V_55 -> V_60 & V_96 ) == 0 )
V_2 -> V_93 |= V_85 ;
V_2 -> V_97 &= ~ V_98 ;
if ( ( V_55 -> V_60 & V_99 ) || ! ( V_55 -> V_60 & V_100 ) )
V_2 -> V_97 |= V_98 ;
V_2 -> V_101 = V_56 ;
F_33 ( V_2 , V_102 , V_2 -> V_97 ) ;
F_33 ( V_2 , V_103 , V_56 | V_104 ) ;
F_33 ( V_2 , V_105 , V_59 & 0xff ) ;
F_33 ( V_2 , V_106 , V_59 >> 8 ) ;
F_33 ( V_2 , V_103 , V_56 ) ;
F_33 ( V_2 , V_107 , V_57 ) ;
F_36 ( V_2 , V_2 -> V_38 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_97 & V_108 ) ) {
V_2 -> V_97 |= V_108 ;
F_33 ( V_2 , V_102 , V_2 -> V_97 ) ;
}
}
static void F_41 ( struct V_1 * V_2 )
{
if ( V_2 -> V_97 & V_108 ) {
V_2 -> V_97 &= ~ V_108 ;
F_33 ( V_2 , V_102 , V_2 -> V_97 ) ;
}
}
static void F_42 ( struct V_1 * V_2 )
{
V_2 -> V_97 &= ~ V_109 ;
V_2 -> V_82 &= ~ V_85 ;
F_33 ( V_2 , V_102 , V_2 -> V_97 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
unsigned int * V_28 )
{
struct V_18 * V_19 = F_21 ( & V_2 -> V_2 ) ;
unsigned int V_110 , V_111 ;
int V_112 = 256 ;
do {
V_110 = F_31 ( V_2 , V_113 ) ;
V_111 = V_114 ;
V_2 -> V_115 . V_116 ++ ;
if ( F_28 ( * V_28 & ( V_92 | V_89 |
V_88 | V_83 ) ) ) {
if ( * V_28 & V_92 ) {
* V_28 &= ~ ( V_88 | V_89 ) ;
V_2 -> V_115 . V_117 ++ ;
} else if ( * V_28 & V_89 )
V_2 -> V_115 . V_118 ++ ;
else if ( * V_28 & V_88 )
V_2 -> V_115 . V_119 ++ ;
if ( * V_28 & V_83 )
V_2 -> V_115 . V_120 ++ ;
* V_28 &= V_2 -> V_82 ;
if ( * V_28 & V_92 )
V_111 = V_121 ;
else if ( * V_28 & V_89 )
V_111 = V_122 ;
else if ( * V_28 & V_88 )
V_111 = V_123 ;
}
if ( ( * V_28 & V_2 -> V_93 & ~ V_83 ) == 0 )
if ( V_19 )
F_44 ( V_19 , V_110 , V_111 ) ;
if ( * V_28 & ~ V_2 -> V_93 & V_83 )
if ( V_19 )
F_44 ( V_19 , 0 , V_124 ) ;
* V_28 = F_31 ( V_2 , V_125 ) ;
} while ( ( * V_28 & V_85 ) && ( V_112 -- > 0 ) );
if ( V_19 ) {
F_45 ( V_19 ) ;
F_23 ( V_19 ) ;
}
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_126 * V_127 = & V_2 -> V_9 ;
int V_128 ;
struct V_18 * V_19 ;
T_1 V_129 [ 16 ] ;
int V_130 ;
if ( V_2 -> V_131 ) {
F_33 ( V_2 , V_132 , V_2 -> V_131 ) ;
V_2 -> V_115 . V_133 ++ ;
V_2 -> V_131 = 0 ;
return;
}
V_19 = F_21 ( & V_2 -> V_2 ) ;
if ( V_19 == NULL || ! F_47 ( V_127 ) ||
V_19 -> V_134 || V_19 -> V_135 ) {
F_41 ( V_2 ) ;
F_23 ( V_19 ) ;
return;
}
V_130 = F_48 ( V_127 , V_129 , 16 , & V_2 -> V_8 ) ;
for ( V_128 = 0 ; V_128 < V_130 ; V_128 ++ ) {
F_33 ( V_2 , V_132 , V_129 [ V_128 ] ) ;
V_2 -> V_115 . V_133 ++ ;
}
V_130 = F_47 ( V_127 ) ;
if ( V_130 < V_136 ) {
F_49 ( V_19 ) ;
if ( V_130 == 0 )
F_41 ( V_2 ) ;
}
F_23 ( V_19 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
int V_28 ;
struct V_18 * V_19 ;
V_28 = F_31 ( V_2 , V_29 ) ;
if ( ( V_28 & V_137 ) == 0 )
return;
if ( V_28 & V_138 )
V_2 -> V_115 . V_139 ++ ;
if ( V_28 & V_140 )
V_2 -> V_115 . V_141 ++ ;
if ( V_28 & V_142 ) {
V_2 -> V_115 . V_143 ++ ;
if ( V_28 & V_30 )
F_51 ( & V_2 -> V_2 . V_144 ) ;
else {
V_19 = F_21 ( & V_2 -> V_2 ) ;
if ( V_19 ) {
F_22 ( V_19 ) ;
F_23 ( V_19 ) ;
}
}
}
if ( V_28 & V_145 ) {
V_2 -> V_115 . V_146 ++ ;
V_19 = F_21 ( & V_2 -> V_2 ) ;
if ( V_19 && ( V_19 -> V_55 -> V_60 & V_99 ) ) {
int V_146 = ( V_28 & V_36 ) ;
if ( V_19 -> V_135 ) {
if ( V_146 ) {
V_19 -> V_135 = 0 ;
F_40 ( V_2 ) ;
F_49 ( V_19 ) ;
}
} else {
if ( ! V_146 ) {
V_19 -> V_135 = 1 ;
F_41 ( V_2 ) ;
}
}
}
F_23 ( V_19 ) ;
}
}
static void F_52 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_53 ( V_17 ) ;
unsigned int V_147 , V_148 ;
if ( F_28 ( V_2 -> V_22 == V_23 ) )
return;
V_147 = F_31 ( V_2 , V_149 ) ;
if ( V_147 & V_150 )
return;
V_2 -> V_22 = V_23 ;
V_148 = F_31 ( V_2 , V_125 ) ;
if ( V_148 & V_85 )
F_43 ( V_2 , & V_148 ) ;
F_50 ( V_2 ) ;
if ( V_148 & V_84 )
F_46 ( V_2 ) ;
V_2 -> V_22 = NULL ;
}
static int F_54 ( struct V_151 * V_152 )
{
struct V_1 * V_2 =
F_11 ( V_152 , struct V_1 , V_2 ) ;
unsigned int V_4 = F_27 ( V_2 ) ;
if ( V_4 )
return 1 ;
V_4 = F_35 ( V_2 ) ;
F_30 ( V_2 ) ;
if ( V_4 & V_31 )
return 1 ;
return 0 ;
}
static void F_55 ( struct V_151 * V_152 , int V_153 )
{
struct V_1 * V_2 =
F_11 ( V_152 , struct V_1 , V_2 ) ;
int V_4 = F_27 ( V_2 ) ;
if ( V_4 )
return;
if ( V_153 == 0 )
F_56 ( V_2 , V_42 | V_40 ) ;
else
F_57 ( V_2 , V_42 | V_40 ) ;
F_30 ( V_2 ) ;
}
static int F_58 ( struct V_151 * V_152 , struct V_18 * V_19 )
{
struct V_1 * V_2 =
F_11 ( V_152 , struct V_1 , V_2 ) ;
int V_4 ;
F_59 ( V_154 , & V_19 -> V_155 ) ;
F_60 ( & V_2 -> V_9 ) ;
V_4 = F_27 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_61 ( V_2 -> V_17 ) ;
if ( V_4 )
goto V_156;
V_4 = F_62 ( V_2 -> V_17 , F_52 ) ;
if ( V_4 )
goto V_157;
F_33 ( V_2 , V_107 , V_79 ) ;
F_33 ( V_2 , V_107 , V_79 |
V_158 | V_159 ) ;
F_33 ( V_2 , V_107 , 0 ) ;
( void ) F_31 ( V_2 , V_125 ) ;
( void ) F_31 ( V_2 , V_113 ) ;
( void ) F_31 ( V_2 , V_149 ) ;
( void ) F_31 ( V_2 , V_29 ) ;
F_33 ( V_2 , V_103 , V_69 ) ;
V_2 -> V_97 = V_109 | V_160 | V_161 | V_162 ;
V_2 -> V_38 = V_46 ;
F_38 ( V_2 , V_19 -> V_55 , NULL ) ;
if ( V_19 -> V_55 -> V_60 & V_77 )
F_57 ( V_2 , V_40 | V_42 ) ;
if ( V_19 -> V_55 -> V_60 & V_99 )
if ( ! ( F_35 ( V_2 ) & V_37 ) )
V_19 -> V_135 = 1 ;
F_63 ( V_154 , & V_19 -> V_155 ) ;
F_52 ( V_2 -> V_17 ) ;
F_30 ( V_2 ) ;
return 0 ;
V_157:
F_25 ( V_2 -> V_17 ) ;
V_156:
F_30 ( V_2 ) ;
return V_4 ;
}
static void F_64 ( struct V_151 * V_152 )
{
struct V_1 * V_2 =
F_11 ( V_152 , struct V_1 , V_2 ) ;
int V_4 ;
V_4 = F_27 ( V_2 ) ;
if ( V_4 )
return;
F_42 ( V_2 ) ;
F_24 ( V_2 -> V_17 ) ;
V_2 -> V_97 = 0 ;
F_33 ( V_2 , V_102 , 0 ) ;
F_56 ( V_2 , V_46 ) ;
V_2 -> V_101 &= ~ V_163 ;
F_33 ( V_2 , V_103 , V_2 -> V_101 ) ;
F_33 ( V_2 , V_107 , V_79 |
V_158 |
V_159 ) ;
F_33 ( V_2 , V_107 , 0 ) ;
F_25 ( V_2 -> V_17 ) ;
F_30 ( V_2 ) ;
}
static int F_65 ( struct V_164 * V_165 , struct V_18 * V_19 )
{
int V_166 = V_19 -> V_3 ;
struct V_1 * V_2 = F_8 ( V_166 ) ;
int V_4 = F_66 ( V_19 ) ;
if ( V_4 == 0 ) {
F_67 ( V_165 ) ;
V_19 -> V_128 ++ ;
V_19 -> V_167 = V_2 ;
V_165 -> V_168 [ V_166 ] = V_19 ;
} else
F_14 ( V_2 ) ;
return V_4 ;
}
static void F_68 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_167 ;
V_19 -> V_167 = NULL ;
F_14 ( V_2 ) ;
}
static int F_69 ( struct V_18 * V_19 , struct V_169 * V_170 )
{
struct V_1 * V_2 = V_19 -> V_167 ;
return F_70 ( & V_2 -> V_2 , V_19 , V_170 ) ;
}
static void F_71 ( struct V_18 * V_19 , struct V_169 * V_170 )
{
struct V_1 * V_2 = V_19 -> V_167 ;
F_72 ( & V_2 -> V_2 , V_19 , V_170 ) ;
}
static void F_73 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_167 ;
F_74 ( & V_2 -> V_2 ) ;
}
static int F_75 ( struct V_18 * V_19 , const unsigned char * V_171 ,
int V_128 )
{
struct V_1 * V_2 = V_19 -> V_167 ;
int V_4 ;
if ( ! V_2 -> V_17 )
return - V_21 ;
V_4 = F_76 ( & V_2 -> V_9 , V_171 , V_128 , & V_2 -> V_8 ) ;
if ( ! ( V_2 -> V_97 & V_108 ) ) {
int V_172 = F_27 ( V_2 ) ;
if ( ! V_172 ) {
F_40 ( V_2 ) ;
F_52 ( V_2 -> V_17 ) ;
F_30 ( V_2 ) ;
} else
V_4 = V_172 ;
}
return V_4 ;
}
static int F_77 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_167 ;
return V_10 - F_47 ( & V_2 -> V_9 ) ;
}
static int F_78 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_167 ;
return F_47 ( & V_2 -> V_9 ) ;
}
static void F_79 ( struct V_18 * V_19 , char V_110 )
{
struct V_1 * V_2 = V_19 -> V_167 ;
V_2 -> V_131 = V_110 ;
if ( V_110 && ! ( V_2 -> V_97 & V_108 ) ) {
if ( F_27 ( V_2 ) != 0 )
return;
F_40 ( V_2 ) ;
F_52 ( V_2 -> V_17 ) ;
F_30 ( V_2 ) ;
}
}
static void F_80 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_167 ;
if ( ! F_81 ( V_19 ) && ! ( V_19 -> V_55 -> V_60 & V_99 ) )
return;
if ( F_27 ( V_2 ) != 0 )
return;
if ( F_81 ( V_19 ) ) {
V_2 -> V_131 = F_82 ( V_19 ) ;
F_40 ( V_2 ) ;
}
if ( V_19 -> V_55 -> V_60 & V_99 )
F_56 ( V_2 , V_40 ) ;
F_52 ( V_2 -> V_17 ) ;
F_30 ( V_2 ) ;
}
static void F_83 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_167 ;
if ( ! F_81 ( V_19 ) && ! ( V_19 -> V_55 -> V_60 & V_99 ) )
return;
if ( F_27 ( V_2 ) != 0 )
return;
if ( F_81 ( V_19 ) ) {
if ( V_2 -> V_131 ) {
V_2 -> V_131 = 0 ;
} else {
V_2 -> V_131 = F_84 ( V_19 ) ;
F_40 ( V_2 ) ;
}
}
if ( V_19 -> V_55 -> V_60 & V_99 )
F_57 ( V_2 , V_40 ) ;
F_52 ( V_2 -> V_17 ) ;
F_30 ( V_2 ) ;
}
static void F_85 ( struct V_18 * V_19 ,
struct V_54 * V_173 )
{
struct V_1 * V_2 = V_19 -> V_167 ;
unsigned int V_174 = V_19 -> V_55 -> V_60 ;
if ( F_27 ( V_2 ) != 0 )
return;
F_38 ( V_2 , V_19 -> V_55 , V_173 ) ;
if ( ( V_173 -> V_60 & V_77 ) && ! ( V_174 & V_77 ) )
F_56 ( V_2 , V_40 | V_42 ) ;
if ( ! ( V_173 -> V_60 & V_77 ) && ( V_174 & V_77 ) ) {
unsigned int V_175 = V_42 ;
if ( ! ( V_174 & V_99 ) || ! F_86 ( V_176 , & V_19 -> V_155 ) )
V_175 |= V_40 ;
F_57 ( V_2 , V_175 ) ;
}
if ( ( V_173 -> V_60 & V_99 ) && ! ( V_174 & V_99 ) ) {
V_19 -> V_135 = 0 ;
F_40 ( V_2 ) ;
}
if ( ! ( V_173 -> V_60 & V_99 ) && ( V_174 & V_99 ) ) {
if ( ! ( F_35 ( V_2 ) & V_37 ) ) {
V_19 -> V_135 = 1 ;
F_41 ( V_2 ) ;
}
}
F_30 ( V_2 ) ;
}
static int F_87 ( struct V_18 * V_19 , int V_177 )
{
struct V_1 * V_2 = V_19 -> V_167 ;
int V_178 ;
V_178 = F_27 ( V_2 ) ;
if ( V_178 != 0 )
return V_178 ;
if ( V_177 == - 1 )
V_2 -> V_101 |= V_163 ;
else
V_2 -> V_101 &= ~ V_163 ;
F_33 ( V_2 , V_103 , V_2 -> V_101 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
static int F_88 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_167 ;
int V_178 ;
V_178 = F_27 ( V_2 ) ;
if ( ! V_178 ) {
V_178 = V_2 -> V_38 | F_35 ( V_2 ) ;
F_30 ( V_2 ) ;
}
return V_178 ;
}
static int F_89 ( struct V_18 * V_19 ,
unsigned int V_51 , unsigned int V_52 )
{
struct V_1 * V_2 = V_19 -> V_167 ;
int V_178 ;
V_178 = F_27 ( V_2 ) ;
if ( ! V_178 ) {
F_37 ( V_2 , V_51 , V_52 ) ;
F_30 ( V_2 ) ;
}
return V_178 ;
}
static int F_90 ( struct V_179 * V_180 , void * V_181 )
{
int V_182 ;
F_91 ( V_180 , L_1 ,
L_2 , L_2 , L_2 ) ;
for ( V_182 = 0 ; V_182 < V_14 ; V_182 ++ ) {
struct V_1 * V_2 = F_8 ( V_182 ) ;
if ( V_2 ) {
F_91 ( V_180 , L_3 , V_182 ) ;
if ( F_92 ( V_183 ) ) {
F_91 ( V_180 , L_4 ,
V_2 -> V_115 . V_133 , V_2 -> V_115 . V_116 ) ;
if ( V_2 -> V_115 . V_119 )
F_91 ( V_180 , L_5 ,
V_2 -> V_115 . V_119 ) ;
if ( V_2 -> V_115 . V_118 )
F_91 ( V_180 , L_6 ,
V_2 -> V_115 . V_118 ) ;
if ( V_2 -> V_115 . V_117 )
F_91 ( V_180 , L_7 ,
V_2 -> V_115 . V_117 ) ;
if ( V_2 -> V_115 . V_120 )
F_91 ( V_180 , L_8 ,
V_2 -> V_115 . V_120 ) ;
if ( V_2 -> V_115 . V_146 )
F_91 ( V_180 , L_9 ,
V_2 -> V_115 . V_146 ) ;
if ( V_2 -> V_115 . V_141 )
F_91 ( V_180 , L_10 ,
V_2 -> V_115 . V_141 ) ;
if ( V_2 -> V_115 . V_139 )
F_91 ( V_180 , L_11 ,
V_2 -> V_115 . V_139 ) ;
if ( V_2 -> V_115 . V_143 )
F_91 ( V_180 , L_12 ,
V_2 -> V_115 . V_143 ) ;
}
F_14 ( V_2 ) ;
F_93 ( V_180 , '\n' ) ;
}
}
return 0 ;
}
static int F_94 ( struct V_184 * V_184 , struct V_169 * V_169 )
{
return F_95 ( V_169 , F_90 , NULL ) ;
}
static int F_96 ( struct V_16 * V_17 ,
const struct V_185 * V_186 )
{
struct V_1 * V_2 ;
int V_4 ;
V_2 = F_97 ( sizeof( struct V_1 ) , V_11 ) ;
if ( ! V_2 )
return - V_12 ;
if ( V_17 -> V_187 == V_188 ) {
F_98 ( V_189 L_13 ,
F_99 ( V_17 ) ) ;
F_13 ( V_2 ) ;
return - V_190 ;
} else if ( V_17 -> V_187 == V_191 ) {
struct V_192 * V_193 ;
for ( V_193 = V_17 -> V_194 ; V_193 ; V_193 = V_193 -> V_195 ) {
if ( V_193 -> V_196 != 0x91 )
continue;
if ( V_193 -> V_197 < 10 )
continue;
if ( V_193 -> V_198 [ 1 ] == 0 )
break;
}
if ( ! V_193 ) {
F_98 ( V_189
L_14 ,
F_99 ( V_17 ) ) ;
F_13 ( V_2 ) ;
return - V_199 ;
}
F_98 ( V_200 L_15 ,
F_99 ( V_17 ) , V_193 -> V_198 [ 2 ] , V_193 -> V_198 [ 3 ] ) ;
V_2 -> V_26 = ( V_193 -> V_198 [ 4 ] << 0 ) |
( V_193 -> V_198 [ 5 ] << 8 ) |
( V_193 -> V_198 [ 6 ] << 16 ) ;
F_98 ( V_200 L_16 ,
F_99 ( V_17 ) , V_2 -> V_26 ) ;
V_2 -> V_76 = V_193 -> V_198 [ 7 ] * 115200 ;
if ( V_2 -> V_76 == 0 )
V_2 -> V_76 = 115200 ;
F_98 ( V_200 L_17 ,
F_99 ( V_17 ) , V_2 -> V_76 ,
V_193 -> V_198 [ 7 ] , V_193 -> V_198 [ 8 ] | ( V_193 -> V_198 [ 9 ] << 8 ) ) ;
} else {
F_13 ( V_2 ) ;
return - V_199 ;
}
V_2 -> V_17 = V_17 ;
F_100 ( V_17 , V_2 ) ;
F_101 ( & V_2 -> V_2 ) ;
V_2 -> V_2 . V_201 = & V_202 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 ) {
F_13 ( V_2 ) ;
} else {
struct V_203 * V_204 ;
V_204 = F_102 ( V_205 ,
V_2 -> V_3 , & V_17 -> V_204 ) ;
if ( F_103 ( V_204 ) ) {
F_16 ( V_2 ) ;
V_4 = F_104 ( V_204 ) ;
}
}
return V_4 ;
}
static void F_105 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_53 ( V_17 ) ;
F_106 ( V_205 , V_2 -> V_3 ) ;
F_16 ( V_2 ) ;
}
static int T_2 F_107 ( void )
{
int V_4 ;
struct V_164 * V_206 ;
V_205 = V_206 = F_108 ( V_14 ) ;
if ( ! V_206 )
return - V_12 ;
V_206 -> V_207 = V_208 ;
V_206 -> V_209 = L_18 ;
V_206 -> V_210 = L_19 ;
V_206 -> V_211 = 0 ;
V_206 -> V_212 = 0 ;
V_206 -> type = V_213 ;
V_206 -> V_214 = V_215 ;
V_206 -> V_155 = V_216 | V_217 ;
V_206 -> V_218 = V_219 ;
V_206 -> V_218 . V_60 = V_220 | V_68 | V_96 | V_221 | V_100 ;
V_206 -> V_218 . V_222 = 4800 ;
V_206 -> V_218 . V_223 = 4800 ;
F_109 ( V_206 , & V_224 ) ;
V_4 = F_110 ( V_206 ) ;
if ( V_4 )
goto V_156;
V_4 = F_111 ( & V_225 ) ;
if ( V_4 )
goto V_157;
return 0 ;
V_157:
F_112 ( V_206 ) ;
V_156:
F_113 ( V_206 ) ;
return V_4 ;
}
static void T_3 F_114 ( void )
{
F_115 ( & V_225 ) ;
F_112 ( V_205 ) ;
F_113 ( V_205 ) ;
}

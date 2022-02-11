static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_5 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_6 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_7 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_8 ;
}
static unsigned int F_5 ( unsigned int V_9 ,
unsigned int V_10 , unsigned int V_11 , unsigned int * V_12 )
{
int V_13 ;
for ( V_13 = 2 ; V_13 < V_11 ; V_13 ++ )
if ( V_10 * V_14 [ V_13 ] >= V_9 )
break;
* V_12 = V_9 / V_14 [ V_13 ] ;
return V_13 ;
}
static unsigned int F_6 ( unsigned int V_9 ,
unsigned int V_10 , unsigned int * V_12 )
{
int V_13 , div = 4 ;
for ( V_13 = 0 ; V_13 < 7 ; V_13 ++ ) {
if ( V_10 * div >= V_9 )
goto V_15;
div <<= 1 ;
}
V_15:
* V_12 = V_9 / div ;
return V_13 ;
}
static int F_7 ( const int V_16 )
{
return F_8 ( V_16 , V_17 ) ;
}
static bool F_9 ( struct V_18 * V_19 , struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_1 * V_24 = F_10 ( V_19 ) ;
unsigned int V_25 , V_13 ;
if ( ! V_19 -> V_26 )
return false ;
V_25 = F_7 ( V_23 -> V_16 ) ;
if ( V_25 != 1 && V_25 != 2 && V_25 != 4 )
return false ;
for ( V_13 = V_24 -> V_3 -> V_27 / 2 ; V_13 > 0 ; V_13 -- ) {
if ( ! ( V_23 -> V_28 % ( V_13 * V_25 ) ) )
break;
}
if ( V_13 == 0 )
return false ;
V_24 -> V_29 = V_13 ;
V_24 -> V_30 = 0 ;
return true ;
}
static void F_11 ( struct V_1 * V_24 )
{
unsigned int V_31 = F_12 ( V_24 -> V_32 + V_33 ) ;
#ifdef F_13
unsigned int V_25 ;
#endif
if ( V_24 -> V_34 ) {
#ifdef F_13
V_25 = F_7 ( V_24 -> V_16 ) ;
if ( V_25 == 1 )
V_31 = F_14 ( V_31 ) ;
else if ( V_25 == 2 )
V_31 = ( V_31 << 16 ) | ( V_31 >> 16 ) ;
#endif
V_31 &= V_24 -> V_35 ;
* ( V_36 * ) V_24 -> V_34 = V_31 ;
V_24 -> V_34 += sizeof( V_36 ) ;
}
}
static void F_15 ( struct V_1 * V_24 )
{
unsigned int V_25 ;
V_25 = F_7 ( V_24 -> V_16 ) ;
if ( V_24 -> V_37 ) {
F_11 ( V_24 ) ;
return;
}
if ( V_25 == 1 )
F_16 ( V_24 ) ;
else if ( V_25 == 2 )
F_17 ( V_24 ) ;
}
static void F_18 ( struct V_1 * V_24 )
{
V_36 V_31 = 0 ;
#ifdef F_13
unsigned int V_25 ;
#endif
if ( V_24 -> V_38 ) {
V_31 = * ( V_36 * ) V_24 -> V_38 ;
V_31 &= V_24 -> V_35 ;
V_24 -> V_38 += sizeof( V_36 ) ;
}
V_24 -> V_39 -= sizeof( V_36 ) ;
#ifdef F_13
V_25 = F_7 ( V_24 -> V_16 ) ;
if ( V_25 == 1 )
V_31 = F_14 ( V_31 ) ;
else if ( V_25 == 2 )
V_31 = ( V_31 << 16 ) | ( V_31 >> 16 ) ;
#endif
F_19 ( V_31 , V_24 -> V_32 + V_40 ) ;
}
static void F_20 ( struct V_1 * V_24 )
{
V_36 V_41 , V_31 ;
unsigned int V_25 ;
if ( V_24 -> V_39 == V_24 -> V_42 ) {
V_41 = F_12 ( V_24 -> V_32 + V_43 ) ;
V_41 &= ~ V_44 ;
if ( V_24 -> V_39 > V_45 ) {
V_24 -> V_42 = V_24 -> V_39 %
V_45 ;
V_31 = V_45 * 8 - 1 ;
} else if ( V_24 -> V_39 >= sizeof( V_36 ) ) {
V_24 -> V_42 = V_24 -> V_39 % sizeof( V_36 ) ;
V_31 = ( V_24 -> V_39 - V_24 -> V_42 ) * 8 - 1 ;
} else {
V_24 -> V_42 = 0 ;
V_31 = V_24 -> V_16 - 1 ;
V_24 -> V_37 = 0 ;
}
V_41 |= ( V_31 << V_46 ) ;
F_19 ( V_41 , V_24 -> V_32 + V_43 ) ;
}
if ( V_24 -> V_39 >= sizeof( V_36 ) ) {
F_18 ( V_24 ) ;
return;
}
V_25 = F_7 ( V_24 -> V_16 ) ;
if ( V_25 == 1 )
F_21 ( V_24 ) ;
else if ( V_25 == 2 )
F_22 ( V_24 ) ;
}
static unsigned int F_23 ( struct V_1 * V_24 ,
unsigned int V_10 , unsigned int * V_12 )
{
unsigned int V_47 , V_48 ;
unsigned int V_9 = V_24 -> V_49 ;
if ( F_24 ( V_10 > V_9 ) )
return 0 ;
V_48 = F_25 ( V_9 ) - F_25 ( V_10 ) ;
if ( V_9 > V_10 << V_48 )
V_48 ++ ;
V_48 = V_11 ( 4U , V_48 ) - 4 ;
if ( F_24 ( V_48 > 0xf ) ) {
F_26 ( V_24 -> V_50 , L_1 ,
V_10 , V_9 ) ;
return 0xff ;
}
V_47 = F_8 ( V_9 , V_10 << V_48 ) - 1 ;
F_27 ( V_24 -> V_50 , L_2 ,
V_51 , V_9 , V_10 , V_48 , V_47 ) ;
* V_12 = ( V_9 / ( V_47 + 1 ) ) >> V_48 ;
return ( V_47 << V_52 ) |
( V_48 << V_53 ) ;
}
static void F_28 ( struct V_1 * V_24 , int V_54 )
{
unsigned V_31 = 0 ;
if ( V_54 & V_55 )
V_31 |= V_56 ;
if ( V_54 & V_57 )
V_31 |= V_58 ;
F_19 ( V_31 , V_24 -> V_32 + V_59 ) ;
}
static void F_29 ( struct V_1 * V_24 )
{
V_36 V_60 ;
V_60 = F_12 ( V_24 -> V_32 + V_43 ) ;
V_60 |= V_61 ;
F_19 ( V_60 , V_24 -> V_32 + V_43 ) ;
}
static int F_30 ( struct V_20 * V_21 )
{
struct V_1 * V_24 = F_10 ( V_21 -> V_19 ) ;
V_36 V_41 = V_62 ;
V_36 V_63 = V_24 -> V_64 , V_65 , V_60 ;
V_36 V_66 = F_12 ( V_24 -> V_32 + V_67 ) ;
V_41 |= V_68 ;
if ( V_21 -> V_69 & V_70 )
V_41 |= F_31 ( V_24 -> V_71 ) ;
V_41 |= F_23 ( V_24 , V_24 -> V_64 , & V_63 ) ;
V_24 -> V_72 = V_63 ;
V_41 |= F_32 ( V_21 -> V_73 ) ;
V_41 |= ( V_24 -> V_16 - 1 ) << V_46 ;
V_66 |= F_33 ( V_21 -> V_73 ) ;
if ( V_21 -> V_69 & V_74 )
V_66 |= F_34 ( V_21 -> V_73 ) ;
else
V_66 &= ~ F_34 ( V_21 -> V_73 ) ;
if ( V_21 -> V_69 & V_75 ) {
V_66 |= F_35 ( V_21 -> V_73 ) ;
V_66 |= F_36 ( V_21 -> V_73 ) ;
} else {
V_66 &= ~ F_35 ( V_21 -> V_73 ) ;
V_66 &= ~ F_36 ( V_21 -> V_73 ) ;
}
if ( V_21 -> V_69 & V_76 )
V_66 |= F_37 ( V_21 -> V_73 ) ;
else
V_66 &= ~ F_37 ( V_21 -> V_73 ) ;
if ( V_24 -> V_77 )
V_41 |= V_78 ;
F_19 ( V_41 , V_24 -> V_32 + V_43 ) ;
V_60 = F_12 ( V_24 -> V_32 + V_79 ) ;
if ( V_21 -> V_69 & V_80 )
V_60 |= V_81 ;
else
V_60 &= ~ V_81 ;
F_19 ( V_60 , V_24 -> V_32 + V_79 ) ;
F_19 ( V_66 , V_24 -> V_32 + V_67 ) ;
V_65 = ( 2 * 1000000 ) / V_63 ;
if ( F_38 ( V_65 < 10 ) )
F_39 ( V_65 ) ;
else
F_40 ( V_65 , V_65 + 10 ) ;
F_19 ( F_41 ( V_24 -> V_29 ) |
F_42 ( V_24 -> V_29 ) |
F_43 ( V_24 -> V_29 ) |
V_82 | V_83 |
V_84 , V_24 -> V_32 + V_85 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_24 )
{
return F_12 ( V_24 -> V_32 + V_86 ) & V_87 ;
}
static void F_45 ( struct V_1 * V_24 )
{
while ( F_44 ( V_24 ) )
F_12 ( V_24 -> V_32 + V_33 ) ;
}
static void F_46 ( struct V_1 * V_24 , int V_54 )
{
unsigned int V_31 = 0 ;
if ( V_54 & V_55 )
V_31 |= V_88 ;
if ( V_54 & V_57 )
V_31 |= V_89 ;
F_19 ( V_31 , V_24 -> V_32 + V_90 ) ;
}
static void F_47 ( struct V_1 * V_24 )
{
unsigned int V_60 ;
V_60 = F_12 ( V_24 -> V_32 + V_91 ) ;
V_60 |= V_92 ;
F_19 ( V_60 , V_24 -> V_32 + V_91 ) ;
}
static int F_48 ( struct V_20 * V_21 )
{
struct V_1 * V_24 = F_10 ( V_21 -> V_19 ) ;
unsigned int V_60 = V_93 | V_94 ;
unsigned int V_63 ;
V_60 |= F_6 ( V_24 -> V_49 , V_24 -> V_64 , & V_63 ) <<
V_95 ;
V_24 -> V_72 = V_63 ;
if ( F_2 ( V_24 ) ) {
V_60 |= ( V_24 -> V_16 - 1 ) << V_96 ;
V_60 |= V_97 ;
} else {
V_60 |= ( V_24 -> V_16 - 1 ) << V_98 ;
}
if ( V_21 -> V_69 & V_74 )
V_60 |= V_99 ;
if ( V_21 -> V_69 & V_75 )
V_60 |= V_100 ;
if ( V_21 -> V_69 & V_76 )
V_60 |= V_101 ;
if ( ! F_49 ( V_21 -> V_102 ) )
V_60 |= ( V_21 -> V_73 ) <<
( F_2 ( V_24 ) ? V_103 :
V_104 ) ;
if ( V_24 -> V_77 )
V_60 |= V_105 ;
F_19 ( V_60 , V_24 -> V_32 + V_91 ) ;
V_60 = F_12 ( V_24 -> V_32 + V_106 ) ;
if ( V_21 -> V_69 & V_80 )
V_60 |= V_107 ;
else
V_60 &= ~ V_107 ;
F_19 ( V_60 , V_24 -> V_32 + V_106 ) ;
if ( V_24 -> V_77 ) {
F_19 ( V_108 | V_109 ,
V_24 -> V_32 + V_110 ) ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_24 )
{
return F_12 ( V_24 -> V_32 + V_111 ) & V_112 ;
}
static void F_51 ( struct V_1 * V_24 )
{
while ( F_12 ( V_24 -> V_32 + V_111 ) & V_112 )
F_12 ( V_24 -> V_32 + V_33 ) ;
}
static void F_52 ( struct V_1 * V_24 , int V_54 )
{
unsigned int V_31 = 0 ;
if ( V_54 & V_55 )
V_31 |= V_113 ;
if ( V_54 & V_57 )
V_31 |= V_114 ;
F_19 ( V_31 , V_24 -> V_32 + V_90 ) ;
}
static void F_53 ( struct V_1 * V_24 )
{
unsigned int V_60 ;
V_60 = F_12 ( V_24 -> V_32 + V_91 ) ;
V_60 |= V_115 ;
F_19 ( V_60 , V_24 -> V_32 + V_91 ) ;
}
static int F_54 ( struct V_20 * V_21 )
{
struct V_1 * V_24 = F_10 ( V_21 -> V_19 ) ;
unsigned int V_60 = V_116 | V_117 ;
unsigned int V_11 = F_1 ( V_24 ) ? 16 : 18 ;
unsigned int V_63 ;
V_60 |= F_5 ( V_24 -> V_49 , V_24 -> V_64 , V_11 , & V_63 )
<< V_118 ;
V_24 -> V_72 = V_63 ;
V_60 |= V_24 -> V_16 - 1 ;
if ( V_21 -> V_69 & V_74 )
V_60 |= V_119 ;
if ( V_21 -> V_69 & V_75 )
V_60 |= V_120 ;
if ( V_21 -> V_69 & V_76 )
V_60 |= V_121 ;
if ( ! F_49 ( V_21 -> V_102 ) )
V_60 |= V_21 -> V_73 << V_122 ;
F_19 ( V_60 , V_24 -> V_32 + V_91 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_24 )
{
return F_12 ( V_24 -> V_32 + V_90 ) & V_123 ;
}
static void F_56 ( struct V_1 * V_24 )
{
F_19 ( 1 , V_24 -> V_32 + V_124 ) ;
}
static void F_57 ( struct V_1 * V_24 , int V_54 )
{
unsigned int V_31 = 0 ;
if ( V_54 & V_55 )
V_31 |= V_125 ;
if ( V_54 & V_57 )
V_31 |= V_126 ;
F_19 ( V_31 , V_24 -> V_32 + V_90 ) ;
}
static void F_58 ( struct V_1 * V_24 )
{
unsigned int V_60 ;
V_60 = F_12 ( V_24 -> V_32 + V_91 ) ;
V_60 |= V_127 ;
F_19 ( V_60 , V_24 -> V_32 + V_91 ) ;
}
static int F_59 ( struct V_20 * V_21 )
{
struct V_1 * V_24 = F_10 ( V_21 -> V_19 ) ;
unsigned int V_60 = V_128 | V_129 ;
unsigned int V_63 ;
V_60 |= F_6 ( V_24 -> V_49 , V_24 -> V_64 , & V_63 ) <<
V_130 ;
V_24 -> V_72 = V_63 ;
V_60 |= V_24 -> V_16 - 1 ;
if ( V_21 -> V_69 & V_74 )
V_60 |= V_131 ;
if ( V_21 -> V_69 & V_75 )
V_60 |= V_132 ;
F_19 ( V_60 , V_24 -> V_32 + V_91 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_24 )
{
return F_12 ( V_24 -> V_32 + V_90 ) & V_133 ;
}
static void F_61 ( struct V_1 * V_24 )
{
F_19 ( 1 , V_24 -> V_32 + V_124 ) ;
}
static void F_62 ( struct V_20 * V_21 , int V_134 )
{
int V_135 = V_134 != V_136 ;
int V_137 = ! ( V_21 -> V_69 & V_76 ) ;
if ( V_21 -> V_69 & V_138 )
return;
if ( ! F_49 ( V_21 -> V_102 ) )
return;
F_63 ( V_21 -> V_102 , V_137 ^ V_135 ) ;
}
static void F_64 ( struct V_1 * V_24 )
{
while ( V_24 -> V_139 < V_24 -> V_3 -> V_27 ) {
if ( ! V_24 -> V_39 )
break;
if ( V_24 -> V_139 && ( V_24 -> V_39 == V_24 -> V_42 ) )
break;
V_24 -> V_140 ( V_24 ) ;
V_24 -> V_139 ++ ;
}
V_24 -> V_3 -> V_141 ( V_24 ) ;
}
static T_1 F_65 ( int V_142 , void * V_143 )
{
struct V_1 * V_24 = V_143 ;
while ( V_24 -> V_3 -> V_144 ( V_24 ) ) {
V_24 -> V_145 ( V_24 ) ;
V_24 -> V_139 -- ;
}
if ( V_24 -> V_39 ) {
F_64 ( V_24 ) ;
return V_146 ;
}
if ( V_24 -> V_139 ) {
V_24 -> V_3 -> V_147 (
V_24 , V_57 ) ;
return V_146 ;
}
V_24 -> V_3 -> V_147 ( V_24 , 0 ) ;
F_66 ( & V_24 -> V_148 ) ;
return V_146 ;
}
static int F_67 ( struct V_18 * V_19 )
{
int V_149 ;
enum V_150 V_151 ;
struct V_152 V_145 = {} , V_140 = {} ;
struct V_1 * V_24 = F_10 ( V_19 ) ;
switch ( F_7 ( V_24 -> V_16 ) ) {
case 4 :
V_151 = V_153 ;
break;
case 2 :
V_151 = V_154 ;
break;
case 1 :
V_151 = V_155 ;
break;
default:
return - V_156 ;
}
V_140 . V_157 = V_158 ;
V_140 . V_159 = V_24 -> V_160 + V_40 ;
V_140 . V_161 = V_151 ;
V_140 . V_162 = V_24 -> V_29 ;
V_149 = F_68 ( V_19 -> V_163 , & V_140 ) ;
if ( V_149 ) {
F_26 ( V_24 -> V_50 , L_3 , V_149 ) ;
return V_149 ;
}
V_145 . V_157 = V_164 ;
V_145 . V_165 = V_24 -> V_160 + V_33 ;
V_145 . V_166 = V_151 ;
V_145 . V_167 = V_24 -> V_29 ;
V_149 = F_68 ( V_19 -> V_26 , & V_145 ) ;
if ( V_149 ) {
F_26 ( V_24 -> V_50 , L_4 , V_149 ) ;
return V_149 ;
}
return 0 ;
}
static int F_69 ( struct V_20 * V_21 ,
struct V_22 * V_168 )
{
struct V_1 * V_24 = F_10 ( V_21 -> V_19 ) ;
int V_149 ;
if ( ! V_168 )
return 0 ;
V_24 -> V_16 = V_168 -> V_16 ;
V_24 -> V_64 = V_168 -> V_64 ;
if ( V_24 -> V_3 -> V_30 ) {
V_36 V_169 ;
V_24 -> V_30 = 0 ;
V_24 -> V_42 = 0 ;
V_24 -> V_37 = 1 ;
V_169 = ( 1 << V_24 -> V_16 ) - 1 ;
V_24 -> V_145 = F_15 ;
V_24 -> V_140 = F_20 ;
V_24 -> V_30 = 1 ;
V_24 -> V_42 = V_168 -> V_28 ;
if ( V_24 -> V_16 <= 8 )
V_24 -> V_35 = V_169 << 24 | V_169 << 16
| V_169 << 8 | V_169 ;
else if ( V_24 -> V_16 <= 16 )
V_24 -> V_35 = V_169 << 16 | V_169 ;
else
V_24 -> V_35 = V_169 ;
} else {
if ( V_24 -> V_16 <= 8 ) {
V_24 -> V_145 = F_16 ;
V_24 -> V_140 = F_21 ;
} else if ( V_24 -> V_16 <= 16 ) {
V_24 -> V_145 = F_17 ;
V_24 -> V_140 = F_22 ;
} else {
V_24 -> V_145 = V_170 ;
V_24 -> V_140 = V_171 ;
}
}
if ( F_9 ( V_24 -> V_172 . V_19 , V_21 , V_168 ) )
V_24 -> V_77 = 1 ;
else
V_24 -> V_77 = 0 ;
if ( V_24 -> V_77 ) {
V_149 = F_67 ( V_21 -> V_19 ) ;
if ( V_149 )
return V_149 ;
}
V_24 -> V_3 -> V_173 ( V_21 ) ;
return 0 ;
}
static void F_70 ( struct V_1 * V_24 )
{
struct V_18 * V_19 = V_24 -> V_172 . V_19 ;
if ( V_19 -> V_26 ) {
F_71 ( V_19 -> V_26 ) ;
V_19 -> V_26 = NULL ;
}
if ( V_19 -> V_163 ) {
F_71 ( V_19 -> V_163 ) ;
V_19 -> V_163 = NULL ;
}
}
static int F_72 ( struct V_174 * V_50 , struct V_1 * V_24 ,
struct V_18 * V_19 )
{
int V_149 ;
if ( F_73 ( L_5 ) )
return 0 ;
V_24 -> V_29 = V_24 -> V_3 -> V_27 / 2 ;
V_19 -> V_163 = F_74 ( V_50 , L_6 ) ;
if ( F_75 ( V_19 -> V_163 ) ) {
V_149 = F_76 ( V_19 -> V_163 ) ;
F_27 ( V_50 , L_7 , V_149 ) ;
V_19 -> V_163 = NULL ;
goto V_175;
}
V_19 -> V_26 = F_74 ( V_50 , L_8 ) ;
if ( F_75 ( V_19 -> V_26 ) ) {
V_149 = F_76 ( V_19 -> V_26 ) ;
F_27 ( V_50 , L_9 , V_149 ) ;
V_19 -> V_26 = NULL ;
goto V_175;
}
F_77 ( & V_24 -> V_176 ) ;
F_77 ( & V_24 -> V_177 ) ;
V_19 -> V_178 = F_9 ;
V_19 -> V_179 = V_180 ;
V_24 -> V_172 . V_19 -> V_181 = V_182 |
V_183 ;
return 0 ;
V_175:
F_70 ( V_24 ) ;
return V_149 ;
}
static void F_78 ( void * V_184 )
{
struct V_1 * V_24 = (struct V_1 * ) V_184 ;
F_66 ( & V_24 -> V_176 ) ;
}
static void F_79 ( void * V_184 )
{
struct V_1 * V_24 = (struct V_1 * ) V_184 ;
F_66 ( & V_24 -> V_177 ) ;
}
static int F_80 ( struct V_1 * V_24 , int V_185 )
{
unsigned long V_186 = 0 ;
V_186 = ( 8 + 4 ) * V_185 / V_24 -> V_72 ;
V_186 += 1 ;
return F_81 ( 2 * V_186 * V_187 ) ;
}
static int F_82 ( struct V_1 * V_24 ,
struct V_22 * V_23 )
{
struct V_188 * V_189 , * V_190 ;
unsigned long V_191 ;
unsigned long V_186 ;
struct V_18 * V_19 = V_24 -> V_172 . V_19 ;
struct V_192 * V_140 = & V_23 -> V_193 , * V_145 = & V_23 -> V_194 ;
V_190 = F_83 ( V_19 -> V_26 ,
V_145 -> V_195 , V_145 -> V_196 , V_164 ,
V_197 | V_198 ) ;
if ( ! V_190 )
return - V_156 ;
V_190 -> V_199 = F_78 ;
V_190 -> V_200 = ( void * ) V_24 ;
F_84 ( V_190 ) ;
F_85 ( & V_24 -> V_176 ) ;
F_86 ( V_19 -> V_26 ) ;
V_189 = F_83 ( V_19 -> V_163 ,
V_140 -> V_195 , V_140 -> V_196 , V_158 ,
V_197 | V_198 ) ;
if ( ! V_189 ) {
F_87 ( V_19 -> V_163 ) ;
return - V_156 ;
}
V_189 -> V_199 = F_79 ;
V_189 -> V_200 = ( void * ) V_24 ;
F_84 ( V_189 ) ;
F_85 ( & V_24 -> V_177 ) ;
F_86 ( V_19 -> V_163 ) ;
V_191 = F_80 ( V_24 , V_23 -> V_28 ) ;
V_186 = F_88 ( & V_24 -> V_177 ,
V_191 ) ;
if ( ! V_186 ) {
F_26 ( V_24 -> V_50 , L_10 ) ;
F_87 ( V_19 -> V_163 ) ;
F_87 ( V_19 -> V_26 ) ;
return - V_201 ;
}
V_186 = F_88 ( & V_24 -> V_176 ,
V_191 ) ;
if ( ! V_186 ) {
F_26 ( & V_19 -> V_50 , L_11 ) ;
V_24 -> V_3 -> V_202 ( V_24 ) ;
F_87 ( V_19 -> V_26 ) ;
return - V_201 ;
}
return V_23 -> V_28 ;
}
static int F_89 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_1 * V_24 = F_10 ( V_21 -> V_19 ) ;
unsigned long V_191 ;
unsigned long V_186 ;
V_24 -> V_38 = V_23 -> V_38 ;
V_24 -> V_34 = V_23 -> V_34 ;
V_24 -> V_39 = V_23 -> V_28 ;
V_24 -> V_139 = 0 ;
F_85 ( & V_24 -> V_148 ) ;
F_64 ( V_24 ) ;
V_24 -> V_3 -> V_147 ( V_24 , V_55 ) ;
V_191 = F_80 ( V_24 , V_23 -> V_28 ) ;
V_186 = F_88 ( & V_24 -> V_148 ,
V_191 ) ;
if ( ! V_186 ) {
F_26 ( & V_21 -> V_50 , L_12 ) ;
V_24 -> V_3 -> V_202 ( V_24 ) ;
return - V_201 ;
}
return V_23 -> V_28 ;
}
static int F_90 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_1 * V_24 = F_10 ( V_21 -> V_19 ) ;
if ( V_24 -> V_77 )
return F_82 ( V_24 , V_23 ) ;
else
return F_89 ( V_21 , V_23 ) ;
}
static int F_91 ( struct V_20 * V_21 )
{
F_27 ( & V_21 -> V_50 , L_13 , V_51 ,
V_21 -> V_69 , V_21 -> V_16 , V_21 -> V_203 ) ;
if ( V_21 -> V_69 & V_138 )
return 0 ;
if ( F_49 ( V_21 -> V_102 ) )
F_92 ( V_21 -> V_102 ,
V_21 -> V_69 & V_76 ? 0 : 1 ) ;
F_62 ( V_21 , V_136 ) ;
return 0 ;
}
static void F_93 ( struct V_20 * V_21 )
{
}
static int
F_94 ( struct V_18 * V_19 , struct V_204 * V_205 )
{
struct V_1 * V_24 = F_10 ( V_19 ) ;
int V_149 ;
V_149 = F_95 ( V_24 -> V_206 ) ;
if ( V_149 )
return V_149 ;
V_149 = F_95 ( V_24 -> V_207 ) ;
if ( V_149 ) {
F_96 ( V_24 -> V_206 ) ;
return V_149 ;
}
return 0 ;
}
static int
F_97 ( struct V_18 * V_19 , struct V_204 * V_205 )
{
struct V_1 * V_24 = F_10 ( V_19 ) ;
F_96 ( V_24 -> V_207 ) ;
F_96 ( V_24 -> V_206 ) ;
return 0 ;
}
static int F_98 ( struct V_208 * V_209 )
{
struct V_210 * V_211 = V_209 -> V_50 . V_212 ;
const struct V_213 * V_214 =
F_99 ( V_215 , & V_209 -> V_50 ) ;
struct V_216 * V_217 =
F_100 ( & V_209 -> V_50 ) ;
struct V_18 * V_19 ;
struct V_1 * V_24 ;
struct V_218 * V_219 ;
int V_13 , V_149 , V_142 , V_71 ;
if ( ! V_211 && ! V_217 ) {
F_26 ( & V_209 -> V_50 , L_14 ) ;
return - V_156 ;
}
V_19 = F_101 ( & V_209 -> V_50 , sizeof( struct V_1 ) ) ;
if ( ! V_19 )
return - V_220 ;
V_149 = F_102 ( V_211 , L_15 , & V_71 ) ;
if ( ( V_149 < 0 ) || ( V_71 >= 0x3 ) ) {
V_71 = 0 ;
}
F_103 ( V_209 , V_19 ) ;
V_19 -> V_221 = F_104 ( 1 , 32 ) ;
V_19 -> V_222 = V_211 ? - 1 : V_209 -> V_223 ;
V_24 = F_10 ( V_19 ) ;
V_24 -> V_172 . V_19 = V_19 ;
V_24 -> V_50 = & V_209 -> V_50 ;
V_24 -> V_3 = V_214 ? V_214 -> V_224 :
(struct V_225 * ) V_209 -> V_226 -> V_227 ;
if ( V_217 ) {
V_19 -> V_228 = V_217 -> V_228 ;
V_19 -> V_229 = F_105 ( & V_19 -> V_50 ,
sizeof( int ) * V_19 -> V_228 , V_230 ) ;
if ( ! V_19 -> V_229 )
return - V_220 ;
for ( V_13 = 0 ; V_13 < V_19 -> V_228 ; V_13 ++ )
V_19 -> V_229 [ V_13 ] = V_217 -> V_231 [ V_13 ] ;
}
V_24 -> V_172 . V_231 = F_62 ;
V_24 -> V_172 . V_232 = F_69 ;
V_24 -> V_172 . V_233 = F_90 ;
V_24 -> V_172 . V_19 -> V_234 = F_91 ;
V_24 -> V_172 . V_19 -> V_235 = F_93 ;
V_24 -> V_172 . V_19 -> V_236 = F_94 ;
V_24 -> V_172 . V_19 -> V_237 = F_97 ;
V_24 -> V_172 . V_19 -> V_238 = V_75 | V_74 | V_76 \
| V_138 ;
if ( F_2 ( V_24 ) || F_3 ( V_24 ) ||
F_4 ( V_24 ) )
V_24 -> V_172 . V_19 -> V_238 |= V_80 | V_70 ;
V_24 -> V_71 = V_71 ;
F_77 ( & V_24 -> V_148 ) ;
V_219 = F_106 ( V_209 , V_239 , 0 ) ;
V_24 -> V_32 = F_107 ( & V_209 -> V_50 , V_219 ) ;
if ( F_75 ( V_24 -> V_32 ) ) {
V_149 = F_76 ( V_24 -> V_32 ) ;
goto V_240;
}
V_24 -> V_160 = V_219 -> V_241 ;
V_142 = F_108 ( V_209 , 0 ) ;
if ( V_142 < 0 ) {
V_149 = V_142 ;
goto V_240;
}
V_149 = F_109 ( & V_209 -> V_50 , V_142 , F_65 , 0 ,
F_110 ( & V_209 -> V_50 ) , V_24 ) ;
if ( V_149 ) {
F_26 ( & V_209 -> V_50 , L_16 , V_142 , V_149 ) ;
goto V_240;
}
V_24 -> V_207 = F_111 ( & V_209 -> V_50 , L_17 ) ;
if ( F_75 ( V_24 -> V_207 ) ) {
V_149 = F_76 ( V_24 -> V_207 ) ;
goto V_240;
}
V_24 -> V_206 = F_111 ( & V_209 -> V_50 , L_18 ) ;
if ( F_75 ( V_24 -> V_206 ) ) {
V_149 = F_76 ( V_24 -> V_206 ) ;
goto V_240;
}
V_149 = F_112 ( V_24 -> V_206 ) ;
if ( V_149 )
goto V_240;
V_149 = F_112 ( V_24 -> V_207 ) ;
if ( V_149 )
goto V_242;
V_24 -> V_49 = F_113 ( V_24 -> V_206 ) ;
if ( V_24 -> V_3 -> V_243 ) {
V_149 = F_72 ( & V_209 -> V_50 , V_24 , V_19 ) ;
if ( V_149 == - V_244 )
goto V_245;
if ( V_149 < 0 )
F_26 ( & V_209 -> V_50 , L_19 ,
V_149 ) ;
}
V_24 -> V_3 -> V_202 ( V_24 ) ;
V_24 -> V_3 -> V_147 ( V_24 , 0 ) ;
V_19 -> V_50 . V_212 = V_209 -> V_50 . V_212 ;
V_149 = F_114 ( & V_24 -> V_172 ) ;
if ( V_149 ) {
F_26 ( & V_209 -> V_50 , L_20 , V_149 ) ;
goto V_245;
}
if ( ! V_19 -> V_229 ) {
F_26 ( & V_209 -> V_50 , L_21 ) ;
V_149 = - V_156 ;
goto V_245;
}
for ( V_13 = 0 ; V_13 < V_19 -> V_228 ; V_13 ++ ) {
if ( ! F_49 ( V_19 -> V_229 [ V_13 ] ) )
continue;
V_149 = F_115 ( & V_209 -> V_50 , V_19 -> V_229 [ V_13 ] ,
V_246 ) ;
if ( V_149 ) {
F_26 ( & V_209 -> V_50 , L_22 ,
V_19 -> V_229 [ V_13 ] ) ;
goto V_245;
}
}
F_116 ( & V_209 -> V_50 , L_23 ) ;
F_96 ( V_24 -> V_207 ) ;
F_96 ( V_24 -> V_206 ) ;
return V_149 ;
V_245:
F_117 ( V_24 -> V_207 ) ;
V_242:
F_117 ( V_24 -> V_206 ) ;
V_240:
F_118 ( V_19 ) ;
return V_149 ;
}
static int F_119 ( struct V_208 * V_209 )
{
struct V_18 * V_19 = F_120 ( V_209 ) ;
struct V_1 * V_24 = F_10 ( V_19 ) ;
F_121 ( & V_24 -> V_172 ) ;
F_19 ( 0 , V_24 -> V_32 + V_91 ) ;
F_122 ( V_24 -> V_207 ) ;
F_122 ( V_24 -> V_206 ) ;
F_70 ( V_24 ) ;
F_118 ( V_19 ) ;
return 0 ;
}

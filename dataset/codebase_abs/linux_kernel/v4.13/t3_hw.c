int F_1 ( struct V_1 * V_1 , int V_2 , T_1 V_3 ,
int V_4 , int V_5 , int V_6 , T_1 * V_7 )
{
while ( 1 ) {
T_1 V_8 = F_2 ( V_1 , V_2 ) ;
if ( ! ! ( V_8 & V_3 ) == V_4 ) {
if ( V_7 )
* V_7 = V_8 ;
return 0 ;
}
if ( -- V_5 == 0 )
return - V_9 ;
if ( V_6 )
F_3 ( V_6 ) ;
}
}
void F_4 ( struct V_1 * V_1 , const struct V_10 * V_11 ,
int V_12 , unsigned int V_13 )
{
while ( V_12 -- ) {
F_5 ( V_1 , V_11 -> V_14 + V_13 , V_11 -> V_8 ) ;
V_11 ++ ;
}
}
void F_6 ( struct V_1 * V_1 , unsigned int V_15 , T_1 V_3 ,
T_1 V_8 )
{
T_1 V_16 = F_2 ( V_1 , V_15 ) & ~ V_3 ;
F_5 ( V_1 , V_15 , V_16 | V_8 ) ;
F_2 ( V_1 , V_15 ) ;
}
static void F_7 ( struct V_1 * V_17 , unsigned int V_18 ,
unsigned int V_19 , T_1 * V_20 ,
unsigned int V_21 , unsigned int V_22 )
{
while ( V_21 -- ) {
F_5 ( V_17 , V_18 , V_22 ) ;
* V_20 ++ = F_2 ( V_17 , V_19 ) ;
V_22 ++ ;
}
}
int F_8 ( struct V_23 * V_23 , unsigned int V_24 , unsigned int V_12 ,
T_2 * V_25 )
{
static const int V_26 [] = { 0 , 0 , 16 , 24 } ;
static const int V_27 [] = { 0 , 32 , 16 , 8 } ;
unsigned int V_28 = V_23 -> V_29 / 8 ;
struct V_1 * V_17 = V_23 -> V_1 ;
if ( V_24 >= V_28 || V_24 + V_12 > V_28 )
return - V_30 ;
V_24 *= ( 8 << V_23 -> V_31 ) ;
while ( V_12 -- ) {
int V_32 ;
T_2 V_33 = 0 ;
for ( V_32 = ( 1 << V_23 -> V_31 ) - 1 ; V_32 >= 0 ; -- V_32 ) {
int V_5 = 10 ;
T_1 V_8 ;
F_5 ( V_17 , V_23 -> V_13 + V_34 , V_24 ) ;
F_5 ( V_17 , V_23 -> V_13 + V_35 , 0 ) ;
V_8 = F_2 ( V_17 , V_23 -> V_13 + V_35 ) ;
while ( ( V_8 & V_36 ) && V_5 -- )
V_8 = F_2 ( V_17 ,
V_23 -> V_13 + V_35 ) ;
if ( V_8 & V_36 )
return - V_37 ;
V_8 = F_2 ( V_17 , V_23 -> V_13 + V_38 ) ;
if ( V_23 -> V_31 == 0 ) {
V_33 = F_2 ( V_17 ,
V_23 -> V_13 +
V_39 ) ;
V_33 |= ( T_2 ) V_8 << 32 ;
} else {
if ( V_23 -> V_31 > 1 )
V_8 >>= V_26 [ V_23 -> V_31 ] ;
V_33 |= ( T_2 ) V_8 << ( V_27 [ V_23 -> V_31 ] * V_32 ) ;
}
V_24 += 8 ;
}
* V_25 ++ = V_33 ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_17 , const struct V_40 * V_41 )
{
T_1 V_42 = V_17 -> V_43 . V_44 . V_45 / ( 2 * V_17 -> V_43 . V_44 . V_46 ) - 1 ;
T_1 V_8 = V_47 | F_10 ( V_42 ) ;
F_5 ( V_17 , V_48 , V_8 ) ;
}
static int F_11 ( struct V_49 * V_50 , int V_51 , int V_52 ,
T_3 V_14 )
{
struct V_53 * V_54 = F_12 ( V_50 ) ;
struct V_1 * V_1 = V_54 -> V_1 ;
int V_55 ;
T_1 V_15 = F_13 ( V_14 ) | F_14 ( V_51 ) ;
F_15 ( & V_1 -> V_56 ) ;
F_6 ( V_1 , V_48 , F_16 ( V_57 ) , F_16 ( 1 ) ) ;
F_5 ( V_1 , V_58 , V_15 ) ;
F_5 ( V_1 , V_59 , F_17 ( 2 ) ) ;
V_55 = F_18 ( V_1 , V_59 , V_36 , 0 , V_60 , 10 ) ;
if ( ! V_55 )
V_55 = F_2 ( V_1 , V_61 ) ;
F_19 ( & V_1 -> V_56 ) ;
return V_55 ;
}
static int F_20 ( struct V_49 * V_50 , int V_51 , int V_52 ,
T_3 V_14 , T_3 V_8 )
{
struct V_53 * V_54 = F_12 ( V_50 ) ;
struct V_1 * V_1 = V_54 -> V_1 ;
int V_55 ;
T_1 V_15 = F_13 ( V_14 ) | F_14 ( V_51 ) ;
F_15 ( & V_1 -> V_56 ) ;
F_6 ( V_1 , V_48 , F_16 ( V_57 ) , F_16 ( 1 ) ) ;
F_5 ( V_1 , V_58 , V_15 ) ;
F_5 ( V_1 , V_61 , V_8 ) ;
F_5 ( V_1 , V_59 , F_17 ( 1 ) ) ;
V_55 = F_18 ( V_1 , V_59 , V_36 , 0 , V_60 , 10 ) ;
F_19 ( & V_1 -> V_56 ) ;
return V_55 ;
}
static int F_21 ( struct V_1 * V_1 , int V_51 , int V_52 ,
int V_14 )
{
T_1 V_15 = F_13 ( V_52 ) | F_14 ( V_51 ) ;
F_6 ( V_1 , V_48 , F_16 ( V_57 ) , 0 ) ;
F_5 ( V_1 , V_58 , V_15 ) ;
F_5 ( V_1 , V_61 , V_14 ) ;
F_5 ( V_1 , V_59 , F_17 ( 0 ) ) ;
return F_18 ( V_1 , V_59 , V_36 , 0 ,
V_60 , 10 ) ;
}
static int F_22 ( struct V_49 * V_50 , int V_51 , int V_52 ,
T_3 V_14 )
{
struct V_53 * V_54 = F_12 ( V_50 ) ;
struct V_1 * V_1 = V_54 -> V_1 ;
int V_55 ;
F_15 ( & V_1 -> V_56 ) ;
V_55 = F_21 ( V_1 , V_51 , V_52 , V_14 ) ;
if ( ! V_55 ) {
F_5 ( V_1 , V_59 , F_17 ( 3 ) ) ;
V_55 = F_18 ( V_1 , V_59 , V_36 , 0 ,
V_60 , 10 ) ;
if ( ! V_55 )
V_55 = F_2 ( V_1 , V_61 ) ;
}
F_19 ( & V_1 -> V_56 ) ;
return V_55 ;
}
static int F_23 ( struct V_49 * V_50 , int V_51 , int V_52 ,
T_3 V_14 , T_3 V_8 )
{
struct V_53 * V_54 = F_12 ( V_50 ) ;
struct V_1 * V_1 = V_54 -> V_1 ;
int V_55 ;
F_15 ( & V_1 -> V_56 ) ;
V_55 = F_21 ( V_1 , V_51 , V_52 , V_14 ) ;
if ( ! V_55 ) {
F_5 ( V_1 , V_61 , V_8 ) ;
F_5 ( V_1 , V_59 , F_17 ( 1 ) ) ;
V_55 = F_18 ( V_1 , V_59 , V_36 , 0 ,
V_60 , 10 ) ;
}
F_19 ( & V_1 -> V_56 ) ;
return V_55 ;
}
int F_24 ( struct V_62 * V_63 , int V_64 , int V_2 , unsigned int V_65 ,
unsigned int V_66 )
{
int V_55 ;
unsigned int V_8 ;
V_55 = F_25 ( V_63 , V_64 , V_2 , & V_8 ) ;
if ( ! V_55 ) {
V_8 &= ~ V_65 ;
V_55 = F_26 ( V_63 , V_64 , V_2 , V_8 | V_66 ) ;
}
return V_55 ;
}
int F_27 ( struct V_62 * V_63 , int V_64 , int V_67 )
{
int V_68 ;
unsigned int V_69 ;
V_68 = F_24 ( V_63 , V_64 , V_70 , V_71 ,
V_72 ) ;
if ( V_68 || ! V_67 )
return V_68 ;
do {
V_68 = F_25 ( V_63 , V_64 , V_70 , & V_69 ) ;
if ( V_68 )
return V_68 ;
V_69 &= V_72 ;
if ( V_69 )
F_28 ( 1 ) ;
} while ( V_69 && -- V_67 );
return V_69 ? - 1 : 0 ;
}
int F_29 ( struct V_62 * V_63 , unsigned int V_73 )
{
int V_68 ;
unsigned int V_8 = 0 ;
V_68 = F_25 ( V_63 , V_74 , V_75 , & V_8 ) ;
if ( V_68 )
return V_68 ;
V_8 &= ~ ( V_76 | V_77 ) ;
if ( V_73 & V_78 )
V_8 |= V_76 ;
if ( V_73 & V_79 )
V_8 |= V_77 ;
V_68 = F_26 ( V_63 , V_74 , V_75 , V_8 ) ;
if ( V_68 )
return V_68 ;
V_8 = 1 ;
if ( V_73 & V_80 )
V_8 |= V_81 ;
if ( V_73 & V_82 )
V_8 |= V_83 ;
if ( V_73 & V_84 )
V_8 |= V_85 ;
if ( V_73 & V_86 )
V_8 |= V_87 ;
if ( V_73 & V_88 )
V_8 |= V_89 ;
if ( V_73 & V_90 )
V_8 |= V_91 ;
return F_26 ( V_63 , V_74 , V_92 , V_8 ) ;
}
int F_30 ( struct V_62 * V_63 , unsigned int V_73 )
{
unsigned int V_8 = 0 ;
if ( V_73 & V_78 )
V_8 |= V_93 ;
if ( V_73 & V_79 )
V_8 |= V_94 ;
if ( V_73 & V_88 )
V_8 |= V_95 ;
if ( V_73 & V_90 )
V_8 |= V_96 ;
return F_26 ( V_63 , V_74 , V_92 , V_8 ) ;
}
int F_31 ( struct V_62 * V_63 , int V_97 , int V_98 )
{
int V_68 ;
unsigned int V_69 ;
V_68 = F_25 ( V_63 , V_74 , V_99 , & V_69 ) ;
if ( V_68 )
return V_68 ;
if ( V_97 >= 0 ) {
V_69 &= ~ ( V_100 | V_101 | V_102 ) ;
if ( V_97 == V_103 )
V_69 |= V_100 ;
else if ( V_97 == V_104 )
V_69 |= V_101 ;
}
if ( V_98 >= 0 ) {
V_69 &= ~ ( V_105 | V_102 ) ;
if ( V_98 == V_106 )
V_69 |= V_105 ;
}
if ( V_69 & V_101 )
V_69 |= V_102 ;
return F_26 ( V_63 , V_74 , V_99 , V_69 ) ;
}
int F_32 ( struct V_62 * V_63 )
{
return F_26 ( V_63 , V_107 , V_108 ,
V_109 ) ;
}
int F_33 ( struct V_62 * V_63 )
{
return F_26 ( V_63 , V_107 , V_108 , 0 ) ;
}
int F_34 ( struct V_62 * V_63 )
{
T_1 V_8 ;
return F_25 ( V_63 , V_107 , V_110 , & V_8 ) ;
}
int F_35 ( struct V_62 * V_63 )
{
unsigned int V_111 ;
int V_68 = F_25 ( V_63 , V_107 , V_110 ,
& V_111 ) ;
if ( V_68 )
return V_68 ;
return ( V_111 & V_109 ) ? V_112 : 0 ;
}
const struct V_40 * F_36 ( unsigned int V_113 )
{
return V_113 < F_37 ( V_114 ) ? & V_114 [ V_113 ] : NULL ;
}
int F_38 ( struct V_1 * V_1 , T_1 V_15 , T_4 * V_115 )
{
T_3 V_8 ;
int V_5 = V_116 ;
T_1 V_16 ;
unsigned int V_117 = V_1 -> V_43 . V_118 . V_119 ;
if ( ( V_15 >= V_120 && V_15 != V_121 ) || ( V_15 & 3 ) )
return - V_30 ;
F_39 ( V_1 -> V_122 , V_117 + V_123 , V_15 ) ;
do {
F_3 ( 10 ) ;
F_40 ( V_1 -> V_122 , V_117 + V_123 , & V_8 ) ;
} while ( ! ( V_8 & V_124 ) && -- V_5 );
if ( ! ( V_8 & V_124 ) ) {
F_41 ( V_1 , L_1 , V_15 ) ;
return - V_37 ;
}
F_42 ( V_1 -> V_122 , V_117 + V_125 , & V_16 ) ;
* V_115 = F_43 ( V_16 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_1 , T_1 V_15 , T_4 V_115 )
{
T_3 V_8 ;
int V_5 = V_116 ;
unsigned int V_117 = V_1 -> V_43 . V_118 . V_119 ;
if ( ( V_15 >= V_120 && V_15 != V_121 ) || ( V_15 & 3 ) )
return - V_30 ;
F_45 ( V_1 -> V_122 , V_117 + V_125 ,
F_46 ( V_115 ) ) ;
F_39 ( V_1 -> V_122 , V_117 + V_123 ,
V_15 | V_124 ) ;
do {
F_28 ( 1 ) ;
F_40 ( V_1 -> V_122 , V_117 + V_123 , & V_8 ) ;
} while ( ( V_8 & V_124 ) && -- V_5 );
if ( V_8 & V_124 ) {
F_41 ( V_1 , L_2 , V_15 ) ;
return - V_37 ;
}
return 0 ;
}
int F_47 ( struct V_1 * V_1 , int V_126 )
{
return F_44 ( V_1 , V_121 , V_126 ? 0xc : 0 ) ;
}
static int F_48 ( char * V_127 , int V_128 , unsigned int V_117 , unsigned int * V_8 )
{
char V_129 [ V_128 + 1 ] ;
memcpy ( V_129 , V_127 , V_128 ) ;
V_129 [ V_128 ] = 0 ;
return F_49 ( F_50 ( V_129 ) , V_117 , V_8 ) ;
}
static int F_51 ( char * V_127 , int V_128 , unsigned int V_117 , T_3 * V_8 )
{
char V_129 [ V_128 + 1 ] ;
memcpy ( V_129 , V_127 , V_128 ) ;
V_129 [ V_128 ] = 0 ;
return F_52 ( F_50 ( V_129 ) , V_117 , V_8 ) ;
}
static int F_53 ( struct V_1 * V_1 , struct V_130 * V_11 )
{
int V_32 , V_15 , V_55 ;
struct V_131 V_44 ;
V_55 = F_38 ( V_1 , V_132 , ( T_4 * ) & V_44 ) ;
if ( V_55 )
return V_55 ;
V_15 = V_44 . V_133 == 0x82 ? V_132 : 0 ;
for ( V_32 = 0 ; V_32 < sizeof( V_44 ) ; V_32 += 4 ) {
V_55 = F_38 ( V_1 , V_15 + V_32 ,
( T_4 * ) ( ( V_134 * ) & V_44 + V_32 ) ) ;
if ( V_55 )
return V_55 ;
}
V_55 = F_48 ( V_44 . V_135 , V_44 . V_136 , 10 , & V_11 -> V_45 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_48 ( V_44 . V_137 , V_44 . V_138 , 10 , & V_11 -> V_139 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_48 ( V_44 . V_140 , V_44 . V_141 , 10 , & V_11 -> V_142 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_48 ( V_44 . V_143 , V_44 . V_144 , 10 , & V_11 -> V_46 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_48 ( V_44 . V_145 , V_44 . V_146 , 10 , & V_11 -> V_147 ) ;
if ( V_55 )
return V_55 ;
memcpy ( V_11 -> V_148 , V_44 . V_149 , V_150 ) ;
if ( V_1 -> V_43 . V_151 == 0 && ! V_44 . V_152 [ 0 ] ) {
V_11 -> V_153 [ 0 ] = F_54 ( V_1 ) ? 1 : 2 ;
V_11 -> V_153 [ 1 ] = F_54 ( V_1 ) ? 6 : 2 ;
} else {
V_11 -> V_153 [ 0 ] = F_55 ( V_44 . V_152 [ 0 ] ) ;
V_11 -> V_153 [ 1 ] = F_55 ( V_44 . V_154 [ 0 ] ) ;
V_55 = F_51 ( V_44 . V_155 , V_44 . V_156 , 16 ,
& V_11 -> V_157 [ 0 ] ) ;
if ( V_55 )
return V_55 ;
V_55 = F_51 ( V_44 . V_158 , V_44 . V_159 , 16 ,
& V_11 -> V_157 [ 1 ] ) ;
if ( V_55 )
return V_55 ;
}
V_55 = F_56 ( V_11 -> V_160 , V_44 . V_161 , 6 ) ;
if ( V_55 < 0 )
return - V_30 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_1 , unsigned int V_162 , int V_163 ,
T_1 * V_7 )
{
int V_55 ;
if ( ! V_162 || V_162 > 4 )
return - V_30 ;
if ( F_2 ( V_1 , V_164 ) & V_36 )
return - V_165 ;
F_5 ( V_1 , V_164 , F_58 ( V_163 ) | F_59 ( V_162 - 1 ) ) ;
V_55 = F_18 ( V_1 , V_164 , V_36 , 0 , V_166 , 10 ) ;
if ( ! V_55 )
* V_7 = F_2 ( V_1 , V_167 ) ;
return V_55 ;
}
static int F_60 ( struct V_1 * V_1 , unsigned int V_162 , int V_163 ,
T_1 V_8 )
{
if ( ! V_162 || V_162 > 4 )
return - V_30 ;
if ( F_2 ( V_1 , V_164 ) & V_36 )
return - V_165 ;
F_5 ( V_1 , V_167 , V_8 ) ;
F_5 ( V_1 , V_164 ,
F_58 ( V_163 ) | F_59 ( V_162 - 1 ) | F_61 ( 1 ) ) ;
return F_18 ( V_1 , V_164 , V_36 , 0 , V_166 , 10 ) ;
}
static int F_62 ( struct V_1 * V_1 , int V_5 , int V_6 )
{
int V_55 ;
T_1 V_111 ;
while ( 1 ) {
if ( ( V_55 = F_60 ( V_1 , 1 , 1 , V_168 ) ) != 0 ||
( V_55 = F_57 ( V_1 , 1 , 0 , & V_111 ) ) != 0 )
return V_55 ;
if ( ! ( V_111 & 1 ) )
return 0 ;
if ( -- V_5 == 0 )
return - V_9 ;
if ( V_6 )
F_28 ( V_6 ) ;
}
}
static int F_63 ( struct V_1 * V_1 , unsigned int V_15 ,
unsigned int V_169 , T_1 * V_115 , int V_170 )
{
int V_55 ;
if ( V_15 + V_169 * sizeof( T_1 ) > V_171 || ( V_15 & 3 ) )
return - V_30 ;
V_15 = F_64 ( V_15 ) | V_172 ;
if ( ( V_55 = F_60 ( V_1 , 4 , 1 , V_15 ) ) != 0 ||
( V_55 = F_57 ( V_1 , 1 , 1 , V_115 ) ) != 0 )
return V_55 ;
for (; V_169 ; V_169 -- , V_115 ++ ) {
V_55 = F_57 ( V_1 , 4 , V_169 > 1 , V_115 ) ;
if ( V_55 )
return V_55 ;
if ( V_170 )
* V_115 = F_65 ( * V_115 ) ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_1 , unsigned int V_15 ,
unsigned int V_12 , const V_134 * V_115 )
{
int V_55 ;
T_1 V_25 [ 64 ] ;
unsigned int V_32 , V_173 , V_174 , V_8 , V_13 = V_15 & 0xff ;
if ( V_15 + V_12 > V_171 || V_13 + V_12 > 256 )
return - V_30 ;
V_8 = F_64 ( V_15 ) | V_175 ;
if ( ( V_55 = F_60 ( V_1 , 1 , 0 , V_176 ) ) != 0 ||
( V_55 = F_60 ( V_1 , 4 , 1 , V_8 ) ) != 0 )
return V_55 ;
for ( V_174 = V_12 ; V_174 ; V_174 -= V_173 ) {
V_173 = F_67 ( V_174 , 4U ) ;
for ( V_8 = 0 , V_32 = 0 ; V_32 < V_173 ; ++ V_32 )
V_8 = ( V_8 << 8 ) + * V_115 ++ ;
V_55 = F_60 ( V_1 , V_173 , V_173 != V_174 , V_8 ) ;
if ( V_55 )
return V_55 ;
}
if ( ( V_55 = F_62 ( V_1 , 5 , 1 ) ) != 0 )
return V_55 ;
V_55 = F_63 ( V_1 , V_15 & ~ 0xff , F_37 ( V_25 ) , V_25 , 1 ) ;
if ( V_55 )
return V_55 ;
if ( memcmp ( V_115 - V_12 , ( V_134 * ) V_25 + V_13 , V_12 ) )
return - V_37 ;
return 0 ;
}
int F_68 ( struct V_1 * V_1 , T_1 * V_177 )
{
int V_55 ;
F_5 ( V_1 , V_178 , 0 ) ;
V_55 = F_18 ( V_1 , V_178 ,
1 , 1 , 5 , 1 ) ;
if ( V_55 )
return V_55 ;
* V_177 = F_2 ( V_1 , V_179 ) ;
return 0 ;
}
int F_69 ( struct V_1 * V_1 )
{
int V_55 ;
T_1 V_177 ;
unsigned int V_180 , V_181 ;
if ( V_1 -> V_43 . V_151 == V_182 )
return 0 ;
V_55 = F_68 ( V_1 , & V_177 ) ;
if ( V_55 )
return V_55 ;
V_180 = F_70 ( V_177 ) ;
V_181 = F_71 ( V_177 ) ;
if ( V_180 == V_183 && V_181 == V_184 )
return 0 ;
else {
F_41 ( V_1 , L_3
L_4 , V_180 , V_181 ,
V_183 , V_184 ) ;
}
return - V_30 ;
}
int F_72 ( struct V_1 * V_1 , const V_134 * V_185 ,
unsigned int V_29 )
{
T_1 V_186 ;
unsigned int V_32 ;
const T_5 * V_11 = ( const T_5 * ) V_185 ;
for ( V_186 = 0 , V_32 = 0 ; V_32 < V_29 / sizeof( V_186 ) ; V_32 ++ )
V_186 += F_73 ( V_11 [ V_32 ] ) ;
if ( V_186 != 0xffffffff ) {
F_41 ( V_1 , L_5 ,
V_186 ) ;
return - V_30 ;
}
return 0 ;
}
int F_74 ( struct V_1 * V_1 , T_1 * V_177 )
{
return F_63 ( V_1 , V_187 , 1 , V_177 , 0 ) ;
}
int F_75 ( struct V_1 * V_1 )
{
int V_55 ;
T_1 V_177 ;
unsigned int type , V_180 , V_181 ;
V_55 = F_74 ( V_1 , & V_177 ) ;
if ( V_55 )
return V_55 ;
type = F_76 ( V_177 ) ;
V_180 = F_77 ( V_177 ) ;
V_181 = F_78 ( V_177 ) ;
if ( type == V_188 && V_180 == V_189 &&
V_181 == V_190 )
return 0 ;
else if ( V_180 != V_189 || V_181 < V_190 )
F_79 ( V_1 , L_6
L_7 , V_180 , V_181 ,
V_189 , V_190 ) ;
else {
F_79 ( V_1 , L_8
L_7 , V_180 , V_181 ,
V_189 , V_190 ) ;
return 0 ;
}
return - V_30 ;
}
static int F_80 ( struct V_1 * V_1 , int V_24 , int V_191 )
{
while ( V_24 <= V_191 ) {
int V_55 ;
if ( ( V_55 = F_60 ( V_1 , 1 , 0 , V_176 ) ) != 0 ||
( V_55 = F_60 ( V_1 , 4 , 0 ,
V_192 | ( V_24 << 8 ) ) ) != 0 ||
( V_55 = F_62 ( V_1 , 5 , 500 ) ) != 0 )
return V_55 ;
V_24 ++ ;
}
return 0 ;
}
int F_81 ( struct V_1 * V_1 , const V_134 * V_193 , unsigned int V_29 )
{
T_1 V_186 ;
unsigned int V_32 ;
const T_5 * V_11 = ( const T_5 * ) V_193 ;
int V_55 , V_15 , V_194 = V_195 >> 16 ;
if ( ( V_29 & 3 ) || V_29 < V_196 )
return - V_30 ;
if ( V_29 > V_187 + 8 - V_195 )
return - V_197 ;
for ( V_186 = 0 , V_32 = 0 ; V_32 < V_29 / sizeof( V_186 ) ; V_32 ++ )
V_186 += F_73 ( V_11 [ V_32 ] ) ;
if ( V_186 != 0xffffffff ) {
F_41 ( V_1 , L_9 ,
V_186 ) ;
return - V_30 ;
}
V_55 = F_80 ( V_1 , V_194 , V_194 ) ;
if ( V_55 )
goto V_198;
V_29 -= 8 ;
for ( V_15 = V_195 ; V_29 ; ) {
unsigned int V_199 = F_67 ( V_29 , 256U ) ;
V_55 = F_66 ( V_1 , V_15 , V_199 , V_193 ) ;
if ( V_55 )
goto V_198;
V_15 += V_199 ;
V_193 += V_199 ;
V_29 -= V_199 ;
}
V_55 = F_66 ( V_1 , V_187 , 4 , V_193 ) ;
V_198:
if ( V_55 )
F_41 ( V_1 , L_10 , V_55 ) ;
return V_55 ;
}
int F_82 ( struct V_1 * V_17 , unsigned int V_15 ,
unsigned int V_12 , unsigned int * V_7 )
{
int V_55 = 0 ;
if ( F_2 ( V_17 , V_200 ) & V_201 )
return - V_165 ;
for ( ; ! V_55 && V_12 -- ; V_15 += 4 ) {
F_5 ( V_17 , V_200 , V_202 + V_15 ) ;
V_55 = F_18 ( V_17 , V_200 , V_201 ,
0 , 5 , 2 ) ;
if ( ! V_55 )
* V_7 ++ = F_2 ( V_17 , V_203 ) ;
}
return V_55 ;
}
static void F_83 ( struct V_204 * V_205 , T_1 * V_206 ,
T_1 * V_207 , T_1 * V_208 )
{
F_84 ( V_205 ) ;
* V_206 = F_2 ( V_205 -> V_1 , V_209 ) ;
F_6 ( V_205 -> V_1 , V_209 ,
V_210 | V_211 | V_212 ,
V_211 ) ;
* V_207 = F_2 ( V_205 -> V_1 , V_213 ) ;
F_5 ( V_205 -> V_1 , V_213 , 0 ) ;
* V_208 = F_2 ( V_205 -> V_1 , V_214 ) ;
F_5 ( V_205 -> V_1 , V_214 , 0 ) ;
F_28 ( 1 ) ;
}
static void F_85 ( struct V_204 * V_205 , T_1 V_206 ,
T_1 V_207 , T_1 V_208 )
{
F_86 ( V_205 ) ;
F_6 ( V_205 -> V_1 , V_209 ,
V_210 | V_211 | V_212 ,
V_206 ) ;
F_5 ( V_205 -> V_1 , V_213 , V_207 ) ;
F_5 ( V_205 -> V_1 , V_214 , V_208 ) ;
}
void F_87 ( struct V_1 * V_1 , int V_215 )
{
int V_216 , V_97 , V_98 , V_217 ;
struct V_53 * V_54 = F_88 ( V_1 , V_215 ) ;
struct V_62 * V_63 = & V_54 -> V_63 ;
struct V_204 * V_205 = & V_54 -> V_205 ;
struct V_218 * V_219 = & V_54 -> V_218 ;
V_63 -> V_220 -> V_221 ( V_63 , & V_216 , & V_97 , & V_98 , & V_217 ) ;
if ( ! V_219 -> V_216 && V_216 ) {
T_1 V_206 , V_207 , V_208 ;
T_1 V_111 ;
F_89 ( V_1 , V_215 ) ;
F_83 ( V_205 , & V_206 , & V_207 , & V_208 ) ;
F_5 ( V_1 , V_222 + V_205 -> V_13 , 0 ) ;
F_90 ( V_205 , V_223 ) ;
V_111 = F_2 ( V_1 , V_224 + V_205 -> V_13 ) ;
if ( V_111 & V_225 ) {
V_205 -> V_226 . V_227 ++ ;
V_54 -> V_228 = 1 ;
}
F_85 ( V_205 , V_206 , V_207 , V_208 ) ;
}
if ( V_219 -> V_229 & V_230 )
V_217 &= V_219 -> V_229 ;
else
V_217 = V_219 -> V_229 & ( V_231 | V_232 ) ;
if ( V_216 == V_219 -> V_216 && V_97 == V_219 -> V_97 &&
V_98 == V_219 -> V_98 && V_217 == V_219 -> V_217 )
return;
if ( V_216 != V_219 -> V_216 && V_1 -> V_43 . V_151 > 0 &&
F_54 ( V_1 ) ) {
if ( V_216 )
F_91 ( V_205 ) ;
F_5 ( V_1 , V_233 + V_205 -> V_13 ,
V_216 ? V_234 | V_235 : 0 ) ;
}
V_219 -> V_216 = V_216 ;
V_219 -> V_97 = V_97 < 0 ? V_236 : V_97 ;
V_219 -> V_98 = V_98 < 0 ? V_237 : V_98 ;
if ( V_216 && V_97 >= 0 && V_219 -> V_238 == V_239 ) {
F_92 ( V_205 , V_97 , V_98 , V_217 ) ;
V_219 -> V_217 = V_217 ;
}
F_93 ( V_1 , V_215 , V_216 && ! V_54 -> V_228 ,
V_97 , V_98 , V_217 ) ;
}
void F_94 ( struct V_1 * V_1 , int V_215 )
{
struct V_53 * V_54 = F_88 ( V_1 , V_215 ) ;
struct V_204 * V_205 = & V_54 -> V_205 ;
struct V_62 * V_63 = & V_54 -> V_63 ;
struct V_218 * V_219 = & V_54 -> V_218 ;
int V_216 , V_97 , V_98 , V_217 , V_228 ;
T_1 V_206 , V_207 , V_208 ;
F_83 ( V_205 , & V_206 , & V_207 , & V_208 ) ;
if ( V_1 -> V_43 . V_151 > 0 && F_54 ( V_1 ) )
F_5 ( V_1 , V_233 + V_205 -> V_13 , 0 ) ;
F_5 ( V_1 , V_222 + V_205 -> V_13 , 0 ) ;
F_90 ( V_205 , V_223 ) ;
F_85 ( V_205 , V_206 , V_207 , V_208 ) ;
V_228 = F_2 ( V_1 ,
V_224 + V_205 -> V_13 ) ;
V_228 &= V_225 ;
V_216 = V_219 -> V_216 ;
V_97 = V_219 -> V_97 ;
V_98 = V_219 -> V_98 ;
V_217 = V_219 -> V_217 ;
V_63 -> V_220 -> V_221 ( V_63 , & V_216 , & V_97 , & V_98 , & V_217 ) ;
if ( V_228 ) {
V_219 -> V_216 = 0 ;
V_219 -> V_97 = V_236 ;
V_219 -> V_98 = V_237 ;
F_95 ( V_1 , V_215 , 0 ) ;
if ( V_216 )
V_205 -> V_226 . V_227 ++ ;
} else {
if ( V_216 )
F_5 ( V_1 , V_233 + V_205 -> V_13 ,
V_234 | V_235 ) ;
V_54 -> V_228 = 0 ;
V_219 -> V_216 = ( unsigned char ) V_216 ;
V_219 -> V_97 = V_97 < 0 ? V_236 : V_97 ;
V_219 -> V_98 = V_98 < 0 ? V_237 : V_98 ;
F_95 ( V_1 , V_215 , V_216 ) ;
}
}
int F_96 ( struct V_62 * V_63 , struct V_204 * V_205 , struct V_218 * V_219 )
{
unsigned int V_217 = V_219 -> V_229 & ( V_231 | V_232 ) ;
V_219 -> V_216 = 0 ;
if ( V_219 -> V_240 & V_241 ) {
V_219 -> V_242 &= ~ ( V_90 | V_88 ) ;
if ( V_217 ) {
V_219 -> V_242 |= V_90 ;
if ( V_217 & V_231 )
V_219 -> V_242 |= V_88 ;
}
V_63 -> V_220 -> V_243 ( V_63 , V_219 -> V_242 ) ;
if ( V_219 -> V_238 == V_244 ) {
V_219 -> V_97 = V_219 -> V_245 ;
V_219 -> V_98 = V_219 -> V_246 ;
V_219 -> V_217 = ( unsigned char ) V_217 ;
F_92 ( V_205 , V_219 -> V_97 , V_219 -> V_98 ,
V_217 ) ;
V_63 -> V_220 -> V_247 ( V_63 , V_219 -> V_97 , V_219 -> V_98 ) ;
} else
V_63 -> V_220 -> V_248 ( V_63 ) ;
} else {
F_92 ( V_205 , - 1 , - 1 , V_217 ) ;
V_219 -> V_217 = ( unsigned char ) V_217 ;
V_63 -> V_220 -> V_249 ( V_63 , 0 ) ;
}
return 0 ;
}
void F_97 ( struct V_1 * V_1 , unsigned int V_250 , int V_251 )
{
F_6 ( V_1 , V_252 ,
V_250 << V_253 ,
V_251 ? ( V_250 << V_253 ) : 0 ) ;
}
static int F_98 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int V_3 ,
const struct V_254 * V_255 ,
unsigned long * V_226 )
{
int V_256 = 0 ;
unsigned int V_111 = F_2 ( V_1 , V_2 ) & V_3 ;
for (; V_255 -> V_3 ; ++ V_255 ) {
if ( ! ( V_111 & V_255 -> V_3 ) )
continue;
if ( V_255 -> V_256 ) {
V_256 ++ ;
F_99 ( V_1 , L_11 ,
V_255 -> V_257 , V_111 & V_255 -> V_3 ) ;
V_111 &= ~ V_255 -> V_3 ;
} else if ( V_255 -> V_257 )
F_79 ( V_1 , L_11 ,
V_255 -> V_257 , V_111 & V_255 -> V_3 ) ;
if ( V_255 -> V_258 >= 0 )
V_226 [ V_255 -> V_258 ] ++ ;
}
if ( V_111 )
F_5 ( V_1 , V_2 , V_111 ) ;
return V_256 ;
}
static void F_100 ( struct V_1 * V_1 )
{
static const struct V_254 V_259 [] = {
{ V_260 , L_12 , - 1 , 1 } ,
{ V_261 , L_13 , - 1 , 1 } ,
{ V_262 , L_14 , - 1 , 1 } ,
{ V_263 , L_15 , - 1 , 1 } ,
{ V_264 , L_16 , - 1 , 1 } ,
{ V_265 , L_17 , - 1 , 1 } ,
{ V_266 , L_18 , - 1 , 1 } ,
{ V_267 , L_19 , - 1 , 1 } ,
{ V_268 , L_20 , - 1 ,
1 } ,
{ V_269 , L_21 ,
V_270 , 0 } ,
{ V_271 , L_22 , - 1 , 1 } ,
{ V_272 , L_23 , - 1 , 1 } ,
{ F_101 ( V_273 ) , L_24 , - 1 ,
1 } ,
{ F_102 ( V_274 ) , L_25 , - 1 ,
1 } ,
{ F_103 ( V_275 ) , L_26 , - 1 ,
1 } ,
{ F_104 ( V_276 ) , L_27
L_28 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_98 ( V_1 , V_277 , V_278 ,
V_259 , V_1 -> V_279 ) )
F_105 ( V_1 ) ;
}
static void F_106 ( struct V_1 * V_1 )
{
static const struct V_254 V_280 [] = {
{ V_281 , L_29 , - 1 , 1 } ,
{ V_282 ,
L_30 , - 1 , 1 } ,
{ V_283 ,
L_31 , - 1 , 1 } ,
{ V_284 , L_23 , - 1 , 1 } ,
{ V_285 , L_24 , - 1 , 1 } ,
{ V_286 , L_25 , - 1 , 1 } ,
{ V_287 , L_26 , - 1 , 1 } ,
{ F_107 ( V_288 ) ,
L_32 , - 1 , 1 } ,
{ V_289 , L_33 , - 1 , 1 } ,
{ V_290 , L_34 , - 1 , 1 } ,
{ V_291 , L_35 , - 1 , 1 } ,
{ V_292 , L_36 , - 1 , 1 } ,
{ F_108 ( V_293 ) , L_37 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_2 ( V_1 , V_294 ) & V_281 )
F_99 ( V_1 , L_38 ,
F_2 ( V_1 , V_295 ) ) ;
if ( F_98 ( V_1 , V_294 , V_296 ,
V_280 , V_1 -> V_279 ) )
F_105 ( V_1 ) ;
}
static void F_109 ( struct V_1 * V_1 )
{
static const struct V_254 V_297 [] = {
{ 0xffffff , L_39 , - 1 , 1 } ,
{ 0x1000000 , L_40 , - 1 , 1 } ,
{ 0x2000000 , L_41 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_254 V_298 [] = {
{ 0x1fffffff , L_39 , - 1 , 1 } ,
{ V_299 , L_40 , - 1 , 1 } ,
{ V_300 , L_41 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_98 ( V_1 , V_301 , 0xffffffff ,
V_1 -> V_43 . V_151 < V_302 ?
V_297 : V_298 , NULL ) )
F_105 ( V_1 ) ;
}
static void F_110 ( struct V_1 * V_1 )
{
static const struct V_254 V_303 [] = {
{ V_304 , L_42 , - 1 , 1 } ,
{ V_305 , L_43 , - 1 , 1 } ,
{ V_306 , L_44 , - 1 , 1 } ,
{ V_307 , L_45 , - 1 , 1 } ,
{ V_308 , L_46 , - 1 , 1 } ,
{ V_309 , L_47 , - 1 , 1 } ,
{ V_310 , L_48 , - 1 , 1 } ,
{ V_311 , L_49 , - 1 , 1 } ,
{ V_312 , L_50 , - 1 , 1 } ,
{ V_313 , L_51 , - 1 , 1 } ,
{ V_314 , L_52 , - 1 , 1 } ,
{ V_315 , L_53 , - 1 , 1 } ,
{ V_316 , L_54 , - 1 , 1 } ,
{ V_317 , L_55 , - 1 , 1 } ,
{ V_318 , L_56 , - 1 , 1 } ,
{ V_319 , L_57 , - 1 , 1 } ,
{ V_320 , L_58 , - 1 , 1 } ,
{ V_321 , L_59 , - 1 , 1 } ,
{ V_322 , L_60 , - 1 , 1 } ,
{ V_323 , L_61 , - 1 , 1 } ,
{ V_324 , L_62 , - 1 , 1 } ,
{ V_325 , L_63 , - 1 , 1 } ,
{ V_326 , L_64 , - 1 , 1 } ,
{ V_327 , L_65 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_98 ( V_1 , V_328 , 0xffffffff ,
V_303 , NULL ) )
F_105 ( V_1 ) ;
}
static void F_111 ( struct V_1 * V_1 )
{
static const struct V_254 V_329 [] = {
{ V_330 , L_66 , - 1 , 1 } ,
{ V_331 , L_67 , - 1 , 1 } ,
{ V_332 , L_68 , - 1 , 1 } ,
{ V_333 , L_69 , - 1 , 1 } ,
{ V_334 , L_70 , - 1 , 1 } ,
{ V_335 , L_71 , - 1 , 1 } ,
{ V_336 , L_72 , - 1 , 1 } ,
{ V_337 , L_72 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_98 ( V_1 , V_338 , 0xffffffff ,
V_329 , NULL ) )
F_105 ( V_1 ) ;
}
static void F_112 ( struct V_1 * V_1 )
{
static const struct V_254 V_339 [] = {
{ V_340 , L_73 ,
V_341 , 0 } ,
{ V_342 , L_74 ,
V_343 , 0 } ,
{ 0xfc , L_75 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_98 ( V_1 , V_344 , 0xffffffff ,
V_339 , V_1 -> V_279 ) )
F_105 ( V_1 ) ;
}
static void F_113 ( struct V_1 * V_1 )
{
static const struct V_254 V_345 [] = {
{ V_346 , L_76 , - 1 , 1 } ,
{ V_347 , L_77 , - 1 , 1 } ,
{ V_348 , L_78 , - 1 , 1 } ,
{ F_114 ( V_349 ) ,
L_79 , - 1 , 1 } ,
{ F_115 ( V_350 ) ,
L_80 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_98 ( V_1 , V_351 , 0xffffffff ,
V_345 , NULL ) )
F_105 ( V_1 ) ;
}
static void F_116 ( struct V_1 * V_1 )
{
static const struct V_254 V_352 [] = {
{ V_353 , L_81 , - 1 , 1 } ,
{ V_354 , L_82 , - 1 , 1 } ,
{ V_355 , L_83 , - 1 , 1 } ,
{ F_117 ( V_356 ) ,
L_84 , - 1 , 1 } ,
{ F_118 ( V_357 ) ,
L_85 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_98 ( V_1 , V_358 , 0xffffffff ,
V_352 , NULL ) )
F_105 ( V_1 ) ;
}
static void F_119 ( struct V_1 * V_1 )
{
static const struct V_254 V_359 [] = {
{ V_360 , L_86 , - 1 , 1 } ,
{ V_361 , L_87 , - 1 , 1 } ,
{ V_362 , L_88 , - 1 , 1 } ,
{ V_363 , L_89 , - 1 , 1 } ,
{ V_364 , L_90 , - 1 , 1 } ,
{ V_365 , L_91 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_98 ( V_1 , V_366 , 0xffffffff ,
V_359 , NULL ) )
F_105 ( V_1 ) ;
}
static void F_120 ( struct V_1 * V_1 )
{
static const struct V_254 V_367 [] = {
{ 0x1ff , L_92 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_98 ( V_1 , V_368 , 0xffffffff ,
V_367 , NULL ) )
F_105 ( V_1 ) ;
}
static void F_121 ( struct V_23 * V_23 )
{
struct V_1 * V_1 = V_23 -> V_1 ;
T_1 V_369 = F_2 ( V_1 , V_23 -> V_13 + V_370 ) ;
if ( V_369 & V_371 ) {
V_23 -> V_226 . V_372 ++ ;
F_79 ( V_1 , L_93
L_94 , V_23 -> V_373 ,
F_2 ( V_1 , V_23 -> V_13 + V_374 ) ,
F_2 ( V_1 , V_23 -> V_13 + V_375 ) ,
F_2 ( V_1 , V_23 -> V_13 + V_376 ) ,
F_2 ( V_1 , V_23 -> V_13 + V_377 ) ) ;
}
if ( V_369 & V_378 ) {
V_23 -> V_226 . V_379 ++ ;
F_99 ( V_1 , L_95
L_94 , V_23 -> V_373 ,
F_2 ( V_1 , V_23 -> V_13 + V_380 ) ,
F_2 ( V_1 , V_23 -> V_13 + V_381 ) ,
F_2 ( V_1 , V_23 -> V_13 + V_382 ) ,
F_2 ( V_1 , V_23 -> V_13 + V_383 ) ) ;
}
if ( F_122 ( V_369 ) ) {
V_23 -> V_226 . V_384 ++ ;
F_99 ( V_1 , L_96 ,
V_23 -> V_373 , F_122 ( V_369 ) ) ;
}
if ( V_369 & V_385 ) {
T_1 V_15 = 0 ;
if ( V_1 -> V_43 . V_151 > 0 )
V_15 = F_2 ( V_1 ,
V_23 -> V_13 + V_386 ) ;
V_23 -> V_226 . V_387 ++ ;
F_99 ( V_1 , L_97 ,
V_23 -> V_373 , V_15 ) ;
}
if ( V_369 & V_388 )
F_105 ( V_1 ) ;
F_5 ( V_1 , V_23 -> V_13 + V_370 , V_369 ) ;
}
static int F_123 ( struct V_1 * V_17 , unsigned int V_389 )
{
struct V_204 * V_205 = & F_88 ( V_17 , V_389 ) -> V_205 ;
T_1 V_369 = F_2 ( V_17 , V_390 + V_205 -> V_13 ) &
~ V_391 ;
if ( V_369 & F_124 ( V_392 ) ) {
V_205 -> V_226 . V_393 ++ ;
F_99 ( V_17 , L_98 , V_389 ) ;
}
if ( V_369 & F_125 ( V_394 ) ) {
V_205 -> V_226 . V_395 ++ ;
F_99 ( V_17 , L_99 , V_389 ) ;
}
if ( V_369 & V_396 )
V_205 -> V_226 . V_397 ++ ;
if ( V_369 & V_391 )
V_205 -> V_226 . V_398 ++ ;
if ( V_369 & F_126 ( V_399 ) )
V_205 -> V_226 . V_400 ++ ;
if ( V_369 & V_401 )
V_205 -> V_226 . V_402 ++ ;
if ( V_369 & V_403 )
V_205 -> V_226 . V_404 ++ ;
if ( V_369 & V_405 ) {
F_6 ( V_17 ,
V_406 + V_205 -> V_13 ,
V_405 , 0 ) ;
V_205 -> V_226 . V_227 ++ ;
F_127 ( V_17 , V_389 ) ;
}
if ( V_369 & V_407 )
F_105 ( V_17 ) ;
F_5 ( V_17 , V_390 + V_205 -> V_13 , V_369 ) ;
return V_369 != 0 ;
}
int F_128 ( struct V_1 * V_1 )
{
T_1 V_32 , V_369 = F_2 ( V_1 , V_408 ) ;
F_129 (adapter, i) {
struct V_53 * V_11 = F_88 ( V_1 , V_32 ) ;
if ( ! ( V_11 -> V_63 . V_409 & V_410 ) )
continue;
if ( V_369 & ( 1 << V_40 ( V_1 ) -> V_411 [ V_32 ] ) ) {
int V_412 = V_11 -> V_63 . V_220 -> V_413 ( & V_11 -> V_63 ) ;
if ( V_412 & V_112 )
F_87 ( V_1 , V_32 ) ;
if ( V_412 & V_414 )
V_11 -> V_63 . V_415 ++ ;
if ( V_412 & V_416 )
F_130 ( V_1 , V_32 ) ;
}
}
F_5 ( V_1 , V_408 , V_369 ) ;
return 0 ;
}
int F_131 ( struct V_1 * V_1 )
{
T_1 V_369 = F_2 ( V_1 , V_417 ) ;
V_369 &= V_1 -> V_418 ;
if ( ! V_369 )
return 0 ;
if ( V_369 & V_419 ) {
if ( F_132 ( V_1 ) )
F_106 ( V_1 ) ;
else
F_100 ( V_1 ) ;
}
if ( V_369 & V_420 )
F_133 ( V_1 ) ;
if ( V_369 & V_421 )
F_121 ( & V_1 -> V_422 ) ;
if ( V_369 & V_423 )
F_121 ( & V_1 -> V_424 ) ;
if ( V_369 & V_425 )
F_121 ( & V_1 -> V_426 ) ;
if ( V_369 & V_427 )
F_110 ( V_1 ) ;
if ( V_369 & V_428 )
F_109 ( V_1 ) ;
if ( V_369 & V_429 )
F_111 ( V_1 ) ;
if ( V_369 & V_430 )
F_112 ( V_1 ) ;
if ( V_369 & V_431 )
F_116 ( V_1 ) ;
if ( V_369 & V_432 )
F_113 ( V_1 ) ;
if ( V_369 & V_433 )
F_119 ( V_1 ) ;
if ( V_369 & V_434 )
F_120 ( V_1 ) ;
if ( V_369 & V_435 )
F_134 ( & V_1 -> V_436 ) ;
if ( V_369 & V_437 )
F_123 ( V_1 , 0 ) ;
if ( V_369 & V_438 )
F_123 ( V_1 , 1 ) ;
if ( V_369 & V_439 )
F_135 ( V_1 ) ;
F_5 ( V_1 , V_417 , V_369 ) ;
F_2 ( V_1 , V_417 ) ;
return 1 ;
}
static unsigned int F_136 ( struct V_1 * V_17 )
{
unsigned int V_32 , V_440 = 0 ;
F_129 (adap, i)
if ( ( F_88 ( V_17 , V_32 ) -> V_63 . V_409 & V_410 ) &&
V_40 ( V_17 ) -> V_411 [ V_32 ] )
V_440 |= 1 << V_40 ( V_17 ) -> V_411 [ V_32 ] ;
return V_440 ;
}
void F_137 ( struct V_1 * V_1 )
{
static const struct V_10 V_441 [] = {
{ V_442 , V_443 } ,
{ V_444 , V_445 } ,
{ V_444 - V_446 + V_447 ,
V_445 } ,
{ V_444 - V_446 + V_448 ,
V_445 } ,
{ V_449 , V_450 } ,
{ V_451 , V_452 } ,
{ V_453 , V_454 } ,
{ V_455 , V_456 } ,
{ V_457 , V_458 } ,
{ V_459 , V_460 } ,
} ;
V_1 -> V_418 = V_461 ;
F_4 ( V_1 , V_441 , F_37 ( V_441 ) , 0 ) ;
F_5 ( V_1 , V_462 ,
V_1 -> V_43 . V_151 >= V_302 ? 0x2bfffff : 0x3bfffff ) ;
if ( V_1 -> V_43 . V_151 > 0 ) {
F_5 ( V_1 , V_463 ,
V_464 | V_361 ) ;
F_5 ( V_1 , V_465 ,
V_466 | V_340 |
V_342 ) ;
} else {
F_5 ( V_1 , V_463 , V_464 ) ;
F_5 ( V_1 , V_465 , V_466 ) ;
}
F_5 ( V_1 , V_467 , F_136 ( V_1 ) ) ;
if ( F_132 ( V_1 ) )
F_5 ( V_1 , V_468 , V_296 ) ;
else
F_5 ( V_1 , V_469 , V_278 ) ;
F_5 ( V_1 , V_470 , V_1 -> V_418 ) ;
F_2 ( V_1 , V_470 ) ;
}
void F_138 ( struct V_1 * V_1 )
{
F_5 ( V_1 , V_470 , 0 ) ;
F_2 ( V_1 , V_470 ) ;
V_1 -> V_418 = 0 ;
}
void F_139 ( struct V_1 * V_1 )
{
static const unsigned int V_471 [] = {
V_472 ,
V_473 ,
V_277 ,
V_370 ,
V_370 - V_446 + V_447 ,
V_370 - V_446 + V_448 ,
V_328 ,
V_301 ,
V_474 ,
V_338 ,
V_344 ,
V_366 ,
V_351 ,
V_358 ,
V_368 ,
V_408 ,
} ;
unsigned int V_32 ;
F_129 (adapter, i)
F_140 ( V_1 , V_32 ) ;
for ( V_32 = 0 ; V_32 < F_37 ( V_471 ) ; ++ V_32 )
F_5 ( V_1 , V_471 [ V_32 ] , 0xffffffff ) ;
if ( F_132 ( V_1 ) )
F_5 ( V_1 , V_295 , 0xffffffff ) ;
F_5 ( V_1 , V_417 , 0xffffffff ) ;
F_2 ( V_1 , V_417 ) ;
}
void F_89 ( struct V_1 * V_1 , int V_389 )
{
struct V_53 * V_54 = F_88 ( V_1 , V_389 ) ;
F_5 ( V_1 , V_475 + V_54 -> V_205 . V_13 ,
V_476 ) ;
}
void F_141 ( struct V_1 * V_1 , int V_389 )
{
struct V_53 * V_54 = F_88 ( V_1 , V_389 ) ;
F_5 ( V_1 , V_477 + V_54 -> V_205 . V_13 ,
0x7ff ) ;
}
void F_142 ( struct V_1 * V_1 , int V_389 )
{
struct V_62 * V_63 = & F_88 ( V_1 , V_389 ) -> V_63 ;
F_5 ( V_1 , F_143 ( V_406 , V_389 ) , V_478 ) ;
F_2 ( V_1 , F_143 ( V_406 , V_389 ) ) ;
V_63 -> V_220 -> V_479 ( V_63 ) ;
}
void F_144 ( struct V_1 * V_1 , int V_389 )
{
struct V_62 * V_63 = & F_88 ( V_1 , V_389 ) -> V_63 ;
F_5 ( V_1 , F_143 ( V_406 , V_389 ) , 0 ) ;
F_2 ( V_1 , F_143 ( V_406 , V_389 ) ) ;
V_63 -> V_220 -> V_480 ( V_63 ) ;
}
static void F_140 ( struct V_1 * V_1 , int V_389 )
{
struct V_62 * V_63 = & F_88 ( V_1 , V_389 ) -> V_63 ;
F_5 ( V_1 , F_143 ( V_390 , V_389 ) , 0xffffffff ) ;
F_2 ( V_1 , F_143 ( V_390 , V_389 ) ) ;
V_63 -> V_220 -> V_481 ( V_63 ) ;
}
static int F_145 ( struct V_1 * V_1 , unsigned int V_113 ,
unsigned int type )
{
if ( type == V_482 ) {
F_5 ( V_1 , V_483 , 0xffffffff ) ;
F_5 ( V_1 , V_484 , 0xffffffff ) ;
F_5 ( V_1 , V_485 , 0x17ffffff ) ;
F_5 ( V_1 , V_486 , 0xffffffff ) ;
} else {
F_5 ( V_1 , V_483 , 0xffffffff ) ;
F_5 ( V_1 , V_484 , 0xffffffff ) ;
F_5 ( V_1 , V_485 , 0xffffffff ) ;
F_5 ( V_1 , V_486 , 0xffffffff ) ;
}
F_5 ( V_1 , V_487 ,
F_146 ( 1 ) | type | F_147 ( V_113 ) ) ;
return F_18 ( V_1 , V_487 , V_488 ,
0 , V_489 , 1 ) ;
}
static int F_148 ( struct V_1 * V_17 , unsigned int V_113 ,
unsigned int type )
{
F_5 ( V_17 , V_490 , 0 ) ;
F_5 ( V_17 , V_491 , 0 ) ;
F_5 ( V_17 , V_492 , 0 ) ;
F_5 ( V_17 , V_493 , 0 ) ;
F_5 ( V_17 , V_483 , 0xffffffff ) ;
F_5 ( V_17 , V_484 , 0xffffffff ) ;
F_5 ( V_17 , V_485 , 0xffffffff ) ;
F_5 ( V_17 , V_486 , 0xffffffff ) ;
F_5 ( V_17 , V_487 ,
F_146 ( 1 ) | type | F_147 ( V_113 ) ) ;
return F_18 ( V_17 , V_487 , V_488 ,
0 , V_489 , 1 ) ;
}
int F_149 ( struct V_1 * V_1 , unsigned int V_113 , int V_494 ,
enum V_495 type , int V_496 , T_2 V_497 ,
unsigned int V_29 , unsigned int V_498 , int V_499 ,
unsigned int V_500 )
{
unsigned int V_501 = type == V_502 ? 0 : V_503 ;
if ( V_497 & 0xfff )
return - V_30 ;
if ( F_2 ( V_1 , V_487 ) & V_488 )
return - V_165 ;
V_497 >>= 12 ;
F_5 ( V_1 , V_490 , F_150 ( V_500 ) |
F_151 ( V_501 ) | F_152 ( V_494 ) ) ;
F_5 ( V_1 , V_491 , F_153 ( V_29 ) |
F_154 ( V_497 & 0xffff ) ) ;
V_497 >>= 16 ;
F_5 ( V_1 , V_492 , V_497 ) ;
V_497 >>= 32 ;
F_5 ( V_1 , V_493 ,
F_155 ( V_497 & 0xf ) | F_156 ( V_496 ) |
F_157 ( type ) | F_158 ( V_499 ) | F_159 ( V_498 ) |
V_504 ) ;
return F_145 ( V_1 , V_113 , V_505 ) ;
}
int F_160 ( struct V_1 * V_1 , unsigned int V_113 ,
int V_494 , T_2 V_497 , unsigned int V_29 ,
unsigned int V_506 , unsigned int V_507 , int V_499 ,
unsigned int V_500 )
{
if ( V_497 & 0xfff )
return - V_30 ;
if ( F_2 ( V_1 , V_487 ) & V_488 )
return - V_165 ;
V_497 >>= 12 ;
F_5 ( V_1 , V_490 , V_497 ) ;
V_497 >>= 32 ;
F_5 ( V_1 , V_491 ,
F_161 ( ( T_1 ) V_497 ) |
F_162 ( V_500 & V_508 ) ) ;
F_5 ( V_1 , V_492 , F_163 ( V_29 ) |
F_164 ( V_499 ) | F_165 ( V_500 >> 12 ) |
F_166 ( V_506 & V_509 ) ) ;
F_5 ( V_1 , V_493 ,
F_167 ( V_506 >> ( 32 - V_510 ) ) |
F_168 ( V_507 ) | F_169 ( V_494 ) ) ;
return F_145 ( V_1 , V_113 , V_511 ) ;
}
int F_170 ( struct V_1 * V_1 , unsigned int V_113 ,
int V_512 , T_2 V_497 , unsigned int V_29 ,
unsigned int V_513 , int V_499 , unsigned int V_500 )
{
unsigned int V_514 = 0 ;
if ( V_497 & 0xfff )
return - V_30 ;
if ( F_2 ( V_1 , V_487 ) & V_488 )
return - V_165 ;
V_497 >>= 12 ;
F_5 ( V_1 , V_490 , F_171 ( V_29 ) |
F_172 ( V_500 ) ) ;
F_5 ( V_1 , V_491 , V_497 ) ;
V_497 >>= 32 ;
if ( V_512 >= 0 )
V_514 = F_173 ( V_512 ) | V_515 ;
F_5 ( V_1 , V_492 ,
F_174 ( ( T_1 ) V_497 ) | V_514 | F_175 ( V_499 ) ) ;
F_5 ( V_1 , V_493 , V_513 ) ;
return F_145 ( V_1 , V_113 , V_482 ) ;
}
int F_176 ( struct V_1 * V_1 , unsigned int V_113 , T_2 V_497 ,
unsigned int V_29 , int V_516 , int V_517 ,
unsigned int V_501 , unsigned int V_518 )
{
if ( V_497 & 0xfff )
return - V_30 ;
if ( F_2 ( V_1 , V_487 ) & V_488 )
return - V_165 ;
V_497 >>= 12 ;
F_5 ( V_1 , V_490 , F_171 ( V_29 ) ) ;
F_5 ( V_1 , V_491 , V_497 ) ;
V_497 >>= 32 ;
F_5 ( V_1 , V_492 ,
F_174 ( ( T_1 ) V_497 ) | F_177 ( V_516 ) |
F_178 ( 1 ) | F_179 ( V_517 ) |
F_180 ( V_517 ) ) ;
F_5 ( V_1 , V_493 , F_181 ( V_501 ) |
F_182 ( V_518 ) ) ;
return F_145 ( V_1 , V_113 , V_519 ) ;
}
int F_183 ( struct V_1 * V_1 , unsigned int V_113 , int V_126 )
{
if ( F_2 ( V_1 , V_487 ) & V_488 )
return - V_165 ;
F_5 ( V_1 , V_483 , 0 ) ;
F_5 ( V_1 , V_484 , 0 ) ;
F_5 ( V_1 , V_485 , 0 ) ;
F_5 ( V_1 , V_486 , V_504 ) ;
F_5 ( V_1 , V_493 , F_184 ( V_126 ) ) ;
F_5 ( V_1 , V_487 ,
F_146 ( 1 ) | V_505 | F_147 ( V_113 ) ) ;
return F_18 ( V_1 , V_487 , V_488 ,
0 , V_489 , 1 ) ;
}
int F_185 ( struct V_1 * V_1 , unsigned int V_113 )
{
if ( F_2 ( V_1 , V_487 ) & V_488 )
return - V_165 ;
F_5 ( V_1 , V_483 , 0 ) ;
F_5 ( V_1 , V_484 , 0 ) ;
F_5 ( V_1 , V_485 , F_163 ( V_520 ) ) ;
F_5 ( V_1 , V_486 , 0 ) ;
F_5 ( V_1 , V_492 , 0 ) ;
F_5 ( V_1 , V_487 ,
F_146 ( 1 ) | V_511 | F_147 ( V_113 ) ) ;
return F_18 ( V_1 , V_487 , V_488 ,
0 , V_489 , 1 ) ;
}
int F_186 ( struct V_1 * V_1 , unsigned int V_113 )
{
if ( F_2 ( V_1 , V_487 ) & V_488 )
return - V_165 ;
F_5 ( V_1 , V_483 , F_171 ( V_521 ) ) ;
F_5 ( V_1 , V_484 , 0 ) ;
F_5 ( V_1 , V_485 , 0 ) ;
F_5 ( V_1 , V_486 , 0 ) ;
F_5 ( V_1 , V_490 , 0 ) ;
F_5 ( V_1 , V_487 ,
F_146 ( 1 ) | V_482 | F_147 ( V_113 ) ) ;
return F_18 ( V_1 , V_487 , V_488 ,
0 , V_489 , 1 ) ;
}
int F_187 ( struct V_1 * V_1 , unsigned int V_113 )
{
if ( F_2 ( V_1 , V_487 ) & V_488 )
return - V_165 ;
F_5 ( V_1 , V_483 , F_171 ( V_521 ) ) ;
F_5 ( V_1 , V_484 , 0 ) ;
F_5 ( V_1 , V_485 , 0 ) ;
F_5 ( V_1 , V_486 , 0 ) ;
F_5 ( V_1 , V_490 , 0 ) ;
F_5 ( V_1 , V_487 ,
F_146 ( 1 ) | V_519 | F_147 ( V_113 ) ) ;
return F_18 ( V_1 , V_487 , V_488 ,
0 , V_489 , 1 ) ;
}
int F_188 ( struct V_1 * V_1 , unsigned int V_113 , unsigned int V_522 ,
unsigned int V_501 )
{
T_1 V_8 ;
if ( F_2 ( V_1 , V_487 ) & V_488 )
return - V_165 ;
F_5 ( V_1 , V_490 , V_501 << 16 ) ;
F_5 ( V_1 , V_487 , F_146 ( V_522 ) |
F_147 ( V_113 ) | V_519 ) ;
if ( F_1 ( V_1 , V_487 , V_488 ,
0 , V_489 , 1 , & V_8 ) )
return - V_37 ;
if ( V_522 >= 2 && V_522 < 7 ) {
if ( V_1 -> V_43 . V_151 > 0 )
return F_189 ( V_8 ) ;
F_5 ( V_1 , V_487 ,
F_146 ( 0 ) | V_519 | F_147 ( V_113 ) ) ;
if ( F_18 ( V_1 , V_487 ,
V_488 , 0 ,
V_489 , 1 ) )
return - V_37 ;
return F_189 ( F_2 ( V_1 , V_490 ) ) ;
}
return 0 ;
}
void F_190 ( struct V_1 * V_1 , unsigned int V_523 ,
const V_134 * V_524 , const T_3 * V_516 )
{
int V_32 , V_525 , V_526 = 0 , V_527 = 0 ;
if ( V_524 )
for ( V_32 = 0 ; V_32 < V_528 ; ++ V_32 ) {
T_1 V_8 = V_32 << 16 ;
for ( V_525 = 0 ; V_525 < 2 ; ++ V_525 ) {
V_8 |= ( V_524 [ V_526 ++ ] & 0x3f ) << ( 8 * V_525 ) ;
if ( V_524 [ V_526 ] == 0xff )
V_526 = 0 ;
}
F_5 ( V_1 , V_529 , V_8 ) ;
}
if ( V_516 )
for ( V_32 = 0 ; V_32 < V_528 ; ++ V_32 ) {
F_5 ( V_1 , V_530 ,
( V_32 << 16 ) | V_516 [ V_527 ++ ] ) ;
if ( V_516 [ V_527 ] == 0xffff )
V_527 = 0 ;
}
F_5 ( V_1 , V_531 , V_523 ) ;
}
void F_191 ( struct V_1 * V_17 , int V_126 )
{
if ( F_192 ( V_17 ) || ! V_126 )
F_6 ( V_17 , V_532 , V_533 ,
F_193 ( ! V_126 ) ) ;
}
static inline unsigned int F_194 ( unsigned int V_534 ,
unsigned int V_535 )
{
unsigned int V_12 = V_534 / V_535 ;
return V_12 - V_12 % 24 ;
}
static void F_195 ( struct V_1 * V_17 , const struct V_536 * V_11 )
{
unsigned int V_537 , V_538 , V_539 = F_196 ( & V_17 -> V_436 ) ;
unsigned int V_540 = 0 , V_541 = 22 ;
if ( V_17 -> V_43 . V_151 > 0 ) {
if ( V_539 <= 16 * 1024 ) {
V_540 = 1 ;
V_541 = 16 ;
} else if ( V_539 <= 64 * 1024 ) {
V_540 = 2 ;
V_541 = 18 ;
} else if ( V_539 <= 256 * 1024 ) {
V_540 = 3 ;
V_541 = 20 ;
}
}
F_5 ( V_17 , V_542 ,
V_11 -> V_543 | ( V_11 -> V_544 >> 16 ) ) ;
F_5 ( V_17 , V_545 , 0 ) ;
F_5 ( V_17 , V_546 , V_11 -> V_547 ) ;
F_5 ( V_17 , V_548 , V_11 -> V_549 ) ;
F_6 ( V_17 , V_550 , F_197 ( V_551 ) ,
F_197 ( F_198 ( V_11 -> V_547 ) - 12 ) ) ;
F_5 ( V_17 , V_552 , 0 ) ;
F_5 ( V_17 , V_553 , V_11 -> V_554 ) ;
F_5 ( V_17 , V_555 , V_11 -> V_556 ) ;
V_538 = V_11 -> V_556 + V_11 -> V_549 ;
V_538 += 48 ;
V_538 -= V_538 % 24 ;
F_5 ( V_17 , V_557 , V_538 ) ;
V_537 = V_539 * V_558 ;
F_199 ( V_17 , V_537 , ( 64 << 10 ) * 64 , V_559 ) ;
F_199 ( V_17 , V_537 , ( 64 << 10 ) * 64 , V_560 ) ;
F_5 ( V_17 , V_561 , F_200 ( V_540 ) | V_537 ) ;
V_537 += ( ( V_11 -> V_562 - 1 ) << V_541 ) + ( 1 << 22 ) ;
F_199 ( V_17 , V_537 , V_538 * 64 , V_563 ) ;
F_199 ( V_17 , V_537 , 64 * ( V_538 / 24 ) , V_564 ) ;
F_199 ( V_17 , V_537 , 64 * ( V_11 -> V_556 / 24 ) , V_565 ) ;
F_199 ( V_17 , V_537 , 64 * ( V_11 -> V_549 / 24 ) , V_566 ) ;
V_537 = ( V_537 + 4095 ) & ~ 0xfff ;
F_5 ( V_17 , V_567 , V_537 ) ;
F_5 ( V_17 , V_568 , V_11 -> V_569 - V_537 ) ;
V_539 = ( V_11 -> V_569 - V_537 - ( 3 << 20 ) ) / 3072 - 32 ;
V_537 = F_196 ( & V_17 -> V_436 ) - V_17 -> V_43 . V_436 . V_570 -
V_17 -> V_43 . V_436 . V_571 - V_17 -> V_43 . V_436 . V_572 ;
if ( V_539 < V_537 )
V_17 -> V_43 . V_436 . V_570 += V_537 - V_539 ;
}
static inline void F_201 ( struct V_1 * V_17 , unsigned int V_15 ,
T_1 V_8 )
{
F_5 ( V_17 , V_573 , V_15 ) ;
F_5 ( V_17 , V_574 , V_8 ) ;
}
static void F_202 ( struct V_1 * V_17 , const struct V_536 * V_11 )
{
F_5 ( V_17 , V_575 , V_576 | V_577 |
V_578 | V_579 |
V_580 | F_203 ( 64 ) ) ;
F_5 ( V_17 , V_581 , F_204 ( 576 ) |
V_582 | F_205 ( 1 ) |
F_206 ( 1 ) | F_207 ( 1 ) | F_208 ( 1 ) ) ;
F_5 ( V_17 , V_583 , F_209 ( 1 ) |
F_210 ( 1 ) | F_211 ( 0 ) |
F_212 ( 26880 ) | F_213 ( 2 ) |
V_584 | V_585 | F_214 ( 1 ) ) ;
F_6 ( V_17 , V_532 , V_586 | V_587 ,
V_588 | V_533 ) ;
F_5 ( V_17 , V_589 , 0x18141814 ) ;
F_5 ( V_17 , V_590 , 0x5050105 ) ;
F_6 ( V_17 , V_591 , 0 ,
V_17 -> V_43 . V_151 > 0 ? V_592 :
V_593 ) ;
F_6 ( V_17 , V_594 ,
V_595 ,
V_596 | V_597 | V_598 |
V_599 | V_600 ) ;
F_6 ( V_17 , V_601 , V_602 ,
V_603 | V_604 |
V_605 | V_606 ) ;
F_5 ( V_17 , V_607 , 1080 ) ;
F_5 ( V_17 , V_607 , 1000 ) ;
if ( V_17 -> V_43 . V_151 > 0 ) {
F_201 ( V_17 , V_608 , V_609 ) ;
F_6 ( V_17 , V_550 , V_610 ,
V_610 ) ;
F_6 ( V_17 , V_594 , V_611 , V_611 ) ;
F_6 ( V_17 , V_550 , 0 , V_612 ) ;
} else
F_6 ( V_17 , V_550 , 0 , V_613 ) ;
if ( V_17 -> V_43 . V_151 == V_302 )
F_6 ( V_17 , V_594 ,
F_215 ( V_614 ) ,
F_215 ( 4 ) ) ;
F_5 ( V_17 , V_615 , 0 ) ;
F_5 ( V_17 , V_616 , 0 ) ;
F_5 ( V_17 , V_617 , 0 ) ;
F_5 ( V_17 , V_618 , 0xf2200000 ) ;
}
static void F_216 ( struct V_1 * V_17 , unsigned int V_619 )
{
unsigned int V_620 = F_198 ( V_619 / ( 1000000 / V_621 ) ) - 1 ;
unsigned int V_622 = F_198 ( V_619 / 5000 ) - 1 ;
unsigned int V_623 = F_198 ( V_619 / 1000 ) ;
unsigned int V_624 = V_619 >> V_620 ;
F_5 ( V_17 , V_625 , F_217 ( V_620 ) |
F_218 ( V_622 ) |
F_219 ( V_623 ) ) ;
F_5 ( V_17 , V_626 ,
( V_619 >> V_622 ) / ( 1000 / V_627 ) ) ;
F_5 ( V_17 , V_628 , 0x3020100 ) ;
F_5 ( V_17 , V_629 , 0x7060504 ) ;
F_5 ( V_17 , V_630 , 0xb0a0908 ) ;
F_5 ( V_17 , V_631 , 0xf0e0d0c ) ;
F_5 ( V_17 , V_632 , F_220 ( 6 ) |
F_221 ( 4 ) | F_222 ( 15 ) |
F_223 ( 8 ) | F_224 ( 8 ) |
F_225 ( 9 ) ) ;
#define F_226 * tps
F_5 ( V_17 , V_633 , V_17 -> V_43 . V_151 > 0 ? 0 : 2 F_226 ) ;
F_5 ( V_17 , V_634 , V_624 / ( 1000 / V_635 ) ) ;
F_5 ( V_17 , V_636 , 64 F_226 ) ;
F_5 ( V_17 , V_637 , 5 F_226 ) ;
F_5 ( V_17 , V_638 , 64 F_226 ) ;
F_5 ( V_17 , V_639 , 7200 F_226 ) ;
F_5 ( V_17 , V_640 , 75 F_226 ) ;
F_5 ( V_17 , V_641 , 3 F_226 ) ;
F_5 ( V_17 , V_642 , 600 F_226 ) ;
#undef F_226
}
static int F_227 ( struct V_1 * V_17 ,
unsigned int V_29 , int V_643 )
{
T_1 V_8 ;
if ( V_29 > V_644 )
return - V_30 ;
V_8 = F_2 ( V_17 , V_550 ) ;
V_8 &= ~ ( V_645 | V_646 ) ;
if ( V_29 ) {
V_8 |= V_645 ;
if ( V_643 )
V_8 |= V_646 ;
V_29 = F_67 ( V_644 , V_29 ) ;
F_5 ( V_17 , V_647 , F_228 ( V_29 ) |
F_229 ( V_644 ) ) ;
}
F_5 ( V_17 , V_550 , V_8 ) ;
return 0 ;
}
static void F_230 ( struct V_1 * V_17 , unsigned int V_29 )
{
F_5 ( V_17 , V_648 ,
F_231 ( V_29 ) | F_232 ( V_29 ) ) ;
}
static void F_233 ( unsigned short V_649 [] )
{
V_649 [ 0 ] = 88 ;
V_649 [ 1 ] = 88 ;
V_649 [ 2 ] = 256 ;
V_649 [ 3 ] = 512 ;
V_649 [ 4 ] = 576 ;
V_649 [ 5 ] = 1024 ;
V_649 [ 6 ] = 1280 ;
V_649 [ 7 ] = 1492 ;
V_649 [ 8 ] = 1500 ;
V_649 [ 9 ] = 2002 ;
V_649 [ 10 ] = 2048 ;
V_649 [ 11 ] = 4096 ;
V_649 [ 12 ] = 4352 ;
V_649 [ 13 ] = 8192 ;
V_649 [ 14 ] = 9000 ;
V_649 [ 15 ] = 9600 ;
}
static void F_234 ( unsigned short * V_650 , unsigned short * V_651 )
{
V_650 [ 0 ] = V_650 [ 1 ] = V_650 [ 2 ] = V_650 [ 3 ] = V_650 [ 4 ] = V_650 [ 5 ] = V_650 [ 6 ] = V_650 [ 7 ] = V_650 [ 8 ] = 1 ;
V_650 [ 9 ] = 2 ;
V_650 [ 10 ] = 3 ;
V_650 [ 11 ] = 4 ;
V_650 [ 12 ] = 5 ;
V_650 [ 13 ] = 6 ;
V_650 [ 14 ] = 7 ;
V_650 [ 15 ] = 8 ;
V_650 [ 16 ] = 9 ;
V_650 [ 17 ] = 10 ;
V_650 [ 18 ] = 14 ;
V_650 [ 19 ] = 17 ;
V_650 [ 20 ] = 21 ;
V_650 [ 21 ] = 25 ;
V_650 [ 22 ] = 30 ;
V_650 [ 23 ] = 35 ;
V_650 [ 24 ] = 45 ;
V_650 [ 25 ] = 60 ;
V_650 [ 26 ] = 80 ;
V_650 [ 27 ] = 100 ;
V_650 [ 28 ] = 200 ;
V_650 [ 29 ] = 300 ;
V_650 [ 30 ] = 400 ;
V_650 [ 31 ] = 500 ;
V_651 [ 0 ] = V_651 [ 1 ] = V_651 [ 2 ] = V_651 [ 3 ] = V_651 [ 4 ] = V_651 [ 5 ] = V_651 [ 6 ] = V_651 [ 7 ] = V_651 [ 8 ] = 0 ;
V_651 [ 9 ] = V_651 [ 10 ] = 1 ;
V_651 [ 11 ] = V_651 [ 12 ] = 2 ;
V_651 [ 13 ] = V_651 [ 14 ] = V_651 [ 15 ] = V_651 [ 16 ] = 3 ;
V_651 [ 17 ] = V_651 [ 18 ] = V_651 [ 19 ] = V_651 [ 20 ] = V_651 [ 21 ] = 4 ;
V_651 [ 22 ] = V_651 [ 23 ] = V_651 [ 24 ] = V_651 [ 25 ] = V_651 [ 26 ] = V_651 [ 27 ] = 5 ;
V_651 [ 28 ] = V_651 [ 29 ] = 6 ;
V_651 [ 30 ] = V_651 [ 31 ] = 7 ;
}
void F_235 ( struct V_1 * V_17 , unsigned short V_649 [ V_652 ] ,
unsigned short V_653 [ V_654 ] ,
unsigned short V_655 [ V_654 ] , unsigned short V_656 )
{
static const unsigned int V_657 [ V_654 ] = {
2 , 6 , 10 , 14 , 20 , 28 , 40 , 56 , 80 , 112 , 160 , 224 , 320 , 448 , 640 ,
896 , 1281 , 1792 , 2560 , 3584 , 5120 , 7168 , 10240 , 14336 , 20480 ,
28672 , 40960 , 57344 , 81920 , 114688 , 163840 , 229376
} ;
unsigned int V_32 , V_658 ;
for ( V_32 = 0 ; V_32 < V_652 ; ++ V_32 ) {
unsigned int V_659 = F_67 ( V_649 [ V_32 ] , V_656 ) ;
unsigned int V_660 = F_198 ( V_659 ) ;
if ( ! ( V_659 & ( ( 1 << V_660 ) >> 2 ) ) )
V_660 -- ;
F_5 ( V_17 , V_661 ,
( V_32 << 24 ) | ( V_660 << 16 ) | V_659 ) ;
for ( V_658 = 0 ; V_658 < V_654 ; ++ V_658 ) {
unsigned int V_662 ;
V_662 = F_236 ( ( ( V_659 - 40 ) * V_653 [ V_658 ] ) / V_657 [ V_658 ] ,
V_663 ) ;
F_5 ( V_17 , V_664 , ( V_32 << 21 ) |
( V_658 << 16 ) | ( V_655 [ V_658 ] << 13 ) | V_662 ) ;
}
}
}
void F_237 ( struct V_1 * V_17 , struct V_665 * V_624 )
{
F_7 ( V_17 , V_666 , V_667 , ( T_1 * ) V_624 ,
sizeof( * V_624 ) / sizeof( T_1 ) , 0 ) ;
}
static void F_238 ( struct V_1 * V_17 , const struct V_536 * V_11 )
{
unsigned int V_537 = V_11 -> V_543 ;
F_239 ( V_17 , V_668 , V_537 , V_11 -> V_543 / 8 ) ;
F_239 ( V_17 , V_669 , V_537 , V_11 -> V_543 / 8 ) ;
F_240 ( V_17 , V_670 , V_537 , V_11 -> V_543 / 4 ) ;
F_239 ( V_17 , V_671 , V_537 , V_11 -> V_543 / 4 ) ;
F_239 ( V_17 , V_672 , V_537 , V_11 -> V_543 / 4 ) ;
F_240 ( V_17 , V_673 , V_537 , V_11 -> V_543 / 4 ) ;
F_239 ( V_17 , V_673 , V_537 , V_11 -> V_543 / 4 ) ;
F_5 ( V_17 , V_674 , 0xffffffff ) ;
}
int F_241 ( struct V_1 * V_17 , const V_134 * V_115 )
{
int V_32 ;
const T_5 * V_25 = ( const T_5 * ) V_115 ;
for ( V_32 = 0 ; V_32 < V_675 ; V_32 ++ ) {
F_5 ( V_17 , V_676 , F_242 ( * V_25 ++ ) ) ;
F_5 ( V_17 , V_677 , F_242 ( * V_25 ++ ) ) ;
F_5 ( V_17 , V_678 , F_242 ( * V_25 ++ ) ) ;
F_5 ( V_17 , V_679 , F_242 ( * V_25 ++ ) ) ;
F_5 ( V_17 , V_179 , F_242 ( * V_25 ++ ) ) ;
F_5 ( V_17 , V_178 , V_32 << 1 | 1 << 31 ) ;
if ( F_18 ( V_17 , V_178 , 1 , 1 , 5 , 1 ) )
return - V_37 ;
}
F_5 ( V_17 , V_178 , 0 ) ;
return 0 ;
}
void F_243 ( struct V_1 * V_1 ,
const struct V_680 * V_681 , int V_682 ,
int V_683 , int V_126 )
{
T_1 V_15 , V_684 [ 4 ] , V_3 [ 4 ] ;
V_684 [ 0 ] = V_681 -> V_685 | ( V_681 -> V_686 << 16 ) ;
V_684 [ 1 ] = ( V_681 -> V_686 >> 16 ) | ( V_681 -> V_687 << 16 ) ;
V_684 [ 2 ] = V_681 -> V_688 ;
V_684 [ 3 ] = V_681 -> V_689 | ( V_681 -> V_690 << 8 ) | ( V_681 -> V_691 << 20 ) ;
V_3 [ 0 ] = V_681 -> V_692 | ( V_681 -> V_693 << 16 ) ;
V_3 [ 1 ] = ( V_681 -> V_693 >> 16 ) | ( V_681 -> V_694 << 16 ) ;
V_3 [ 2 ] = V_681 -> V_695 ;
V_3 [ 3 ] = V_681 -> V_696 | ( V_681 -> V_697 << 8 ) | ( V_681 -> V_698 << 20 ) ;
if ( V_683 )
V_684 [ 3 ] |= ( 1 << 29 ) ;
if ( V_126 )
V_684 [ 3 ] |= ( 1 << 28 ) ;
V_15 = V_682 ? V_699 : V_700 ;
F_201 ( V_1 , V_15 ++ , V_684 [ 0 ] ) ;
F_201 ( V_1 , V_15 ++ , V_3 [ 0 ] ) ;
F_201 ( V_1 , V_15 ++ , V_684 [ 1 ] ) ;
F_201 ( V_1 , V_15 ++ , V_3 [ 1 ] ) ;
F_201 ( V_1 , V_15 ++ , V_684 [ 2 ] ) ;
F_201 ( V_1 , V_15 ++ , V_3 [ 2 ] ) ;
F_201 ( V_1 , V_15 ++ , V_684 [ 3 ] ) ;
F_201 ( V_1 , V_15 , V_3 [ 3 ] ) ;
F_2 ( V_1 , V_574 ) ;
}
int F_244 ( struct V_1 * V_17 , unsigned int V_701 , int V_702 )
{
unsigned int V_16 , V_624 , V_703 , V_704 , V_705 , V_706 = ~ 0 ;
unsigned int V_707 = V_17 -> V_43 . V_44 . V_45 * 1000 ;
unsigned int V_708 = 0 , V_709 = 0 ;
if ( V_701 > 0 ) {
V_701 *= 125 ;
for ( V_703 = 1 ; V_703 <= 255 ; V_703 ++ ) {
V_624 = V_707 / V_703 ;
V_704 = ( V_701 + V_624 / 2 ) / V_624 ;
if ( V_704 > 0 && V_704 <= 255 ) {
V_16 = V_704 * V_624 ;
V_705 = V_16 >= V_701 ? V_16 - V_701 : V_701 - V_16 ;
if ( V_705 <= V_706 ) {
V_706 = V_705 ;
V_708 = V_703 ;
V_709 = V_704 ;
}
} else if ( V_708 )
break;
}
if ( ! V_708 )
return - V_30 ;
}
F_5 ( V_17 , V_710 ,
V_711 - V_702 / 2 ) ;
V_16 = F_2 ( V_17 , V_712 ) ;
if ( V_702 & 1 )
V_16 = ( V_16 & 0xffff ) | ( V_708 << 16 ) | ( V_709 << 24 ) ;
else
V_16 = ( V_16 & 0xffff0000 ) | V_708 | ( V_709 << 8 ) ;
F_5 ( V_17 , V_712 , V_16 ) ;
return 0 ;
}
static int F_245 ( struct V_1 * V_17 , const struct V_536 * V_11 )
{
int V_713 = 0 ;
F_202 ( V_17 , V_11 ) ;
F_97 ( V_17 , 3 , 0 ) ;
if ( F_192 ( V_17 ) ) {
F_216 ( V_17 , V_17 -> V_43 . V_44 . V_45 * 1000 ) ;
F_5 ( V_17 , V_714 , V_715 ) ;
V_713 = F_18 ( V_17 , V_714 , V_715 ,
0 , 1000 , 5 ) ;
if ( V_713 )
F_41 ( V_17 , L_100 ) ;
}
if ( ! V_713 )
F_5 ( V_17 , V_714 , V_716 ) ;
return V_713 ;
}
static void F_246 ( struct V_1 * V_17 , unsigned int V_717 )
{
int V_32 ;
if ( V_717 != 3 ) {
F_6 ( V_17 , V_718 , V_719 , 0 ) ;
F_6 ( V_17 , V_720 , V_721 , 0 ) ;
F_5 ( V_17 , V_722 , V_723 | V_724 |
( V_717 == 1 ? V_725 | V_726 :
V_727 | V_728 ) ) ;
F_5 ( V_17 , V_729 ,
V_717 == 1 ? 0xffffffff : 0 ) ;
} else {
F_6 ( V_17 , V_718 , 0 , V_719 ) ;
F_6 ( V_17 , V_720 , 0 , V_721 ) ;
F_5 ( V_17 , V_730 ,
F_247 ( 16 ) | F_248 ( 16 ) ) ;
F_5 ( V_17 , V_722 , V_725 | V_727 |
V_723 | V_726 | V_728 |
V_724 ) ;
F_5 ( V_17 , V_729 , 0x80008000 ) ;
F_6 ( V_17 , V_594 , 0 , V_731 ) ;
F_5 ( V_17 , V_732 ,
F_249 ( 0xaa ) ) ;
for ( V_32 = 0 ; V_32 < 16 ; V_32 ++ )
F_5 ( V_17 , V_733 ,
( V_32 << 16 ) | 0x1010 ) ;
}
}
static int F_250 ( struct V_1 * V_1 )
{
if ( F_54 ( V_1 ) ) {
unsigned int V_16 , V_32 ;
for ( V_32 = 0 ; V_32 < 5 ; ++ V_32 ) {
F_5 ( V_1 , V_734 , 0 ) ;
F_2 ( V_1 , V_734 ) ;
F_28 ( 1 ) ;
V_16 = F_2 ( V_1 , V_734 ) ;
if ( ! ( V_16 & ( V_735 | V_736 ) ) ) {
F_5 ( V_1 , V_734 ,
F_251 ( F_252 ( V_16 ) >> 2 ) ) ;
return 0 ;
}
}
F_41 ( V_1 , L_101 ) ;
return - 1 ;
} else {
F_5 ( V_1 , V_737 ,
F_253 ( 2 ) | F_254 ( 3 ) ) ;
F_6 ( V_1 , V_737 , V_738 ,
V_738 ) ;
}
return 0 ;
}
static void F_255 ( struct V_1 * V_1 )
{
if ( ! F_54 ( V_1 ) ) {
F_5 ( V_1 , V_737 , V_739 |
V_740 | F_253 ( 2 ) | F_254 ( 3 ) ) ;
F_6 ( V_1 , V_737 , V_739 , 0 ) ;
F_6 ( V_1 , V_737 , 0 ,
V_738 ) ;
F_6 ( V_1 , V_737 , V_738 ,
0 ) ;
F_6 ( V_1 , V_737 , V_740 , 0 ) ;
F_6 ( V_1 , V_737 , 0 , V_740 ) ;
}
}
static int F_256 ( struct V_1 * V_1 , unsigned int V_15 , T_1 V_8 )
{
F_5 ( V_1 , V_15 , V_8 ) ;
F_2 ( V_1 , V_15 ) ;
if ( ! ( F_2 ( V_1 , V_15 ) & V_36 ) )
return 0 ;
F_41 ( V_1 , L_102 , V_15 ) ;
return - V_37 ;
}
static int F_257 ( struct V_23 * V_23 , unsigned int V_741 , int V_742 )
{
static const unsigned int V_743 [] = {
0x632 , 0x642 , 0x652 , 0x432 , 0x442
} ;
static const struct V_744 V_745 [] = {
{ 12 , 3 , 4 , { 20 , 28 , 34 , 52 , 0 } , 15 , 6 , 4 } ,
{ 12 , 4 , 5 , { 20 , 28 , 34 , 52 , 0 } , 16 , 7 , 4 } ,
{ 12 , 5 , 6 , { 20 , 28 , 34 , 52 , 0 } , 17 , 8 , 4 } ,
{ 9 , 3 , 4 , { 15 , 21 , 26 , 39 , 0 } , 12 , 6 , 4 } ,
{ 9 , 4 , 5 , { 15 , 21 , 26 , 39 , 0 } , 13 , 7 , 4 }
} ;
T_1 V_8 ;
unsigned int V_31 , V_746 , V_747 , V_5 ;
struct V_1 * V_1 = V_23 -> V_1 ;
const struct V_744 * V_11 = & V_745 [ V_742 ] ;
if ( ! V_23 -> V_29 )
return 0 ;
V_8 = F_2 ( V_1 , V_23 -> V_13 + V_748 ) ;
V_747 = V_8 & V_749 ;
V_31 = F_258 ( V_8 ) ;
V_746 = F_259 ( V_8 ) ;
F_5 ( V_1 , V_23 -> V_13 + V_748 , V_8 | V_750 ) ;
V_8 = F_2 ( V_1 , V_23 -> V_13 + V_748 ) ;
F_28 ( 1 ) ;
if ( ! V_747 ) {
F_5 ( V_1 , V_23 -> V_13 + V_751 , V_752 ) ;
F_2 ( V_1 , V_23 -> V_13 + V_751 ) ;
F_28 ( 1 ) ;
if ( F_2 ( V_1 , V_23 -> V_13 + V_751 ) &
( V_36 | V_752 | V_753 ) ) {
F_41 ( V_1 , L_103 ,
V_23 -> V_373 ) ;
goto V_754;
}
}
F_5 ( V_1 , V_23 -> V_13 + V_755 ,
F_260 ( V_11 -> V_756 ) |
F_261 ( V_11 -> V_757 ) | F_262 ( V_11 -> V_758 ) |
F_263 ( V_11 -> V_759 [ V_746 ] ) | F_264 ( V_11 -> V_760 ) |
F_265 ( V_11 -> V_761 ) | F_266 ( V_11 -> V_762 ) ) ;
F_5 ( V_1 , V_23 -> V_13 + V_748 ,
V_8 | V_763 | V_764 ) ;
F_2 ( V_1 , V_23 -> V_13 + V_748 ) ;
if ( ! V_747 )
F_6 ( V_1 , V_23 -> V_13 + V_765 , V_766 ,
V_766 ) ;
F_3 ( 1 ) ;
V_8 = V_747 ? 3 : 6 ;
if ( F_256 ( V_1 , V_23 -> V_13 + V_767 , 0 ) ||
F_256 ( V_1 , V_23 -> V_13 + V_768 , 0 ) ||
F_256 ( V_1 , V_23 -> V_13 + V_769 , 0 ) ||
F_256 ( V_1 , V_23 -> V_13 + V_770 , V_8 ) )
goto V_754;
if ( ! V_747 ) {
F_5 ( V_1 , V_23 -> V_13 + V_771 , 0x100 ) ;
F_6 ( V_1 , V_23 -> V_13 + V_765 , V_772 , 0 ) ;
F_3 ( 5 ) ;
}
if ( F_256 ( V_1 , V_23 -> V_13 + V_767 , 0 ) ||
F_256 ( V_1 , V_23 -> V_13 + V_773 , 0 ) ||
F_256 ( V_1 , V_23 -> V_13 + V_773 , 0 ) ||
F_256 ( V_1 , V_23 -> V_13 + V_771 ,
V_743 [ V_742 ] ) ||
F_256 ( V_1 , V_23 -> V_13 + V_770 , V_8 | 0x380 ) ||
F_256 ( V_1 , V_23 -> V_13 + V_770 , V_8 ) )
goto V_754;
V_741 = V_741 * 7812 + V_741 / 2 ;
V_741 /= 1000000 ;
F_5 ( V_1 , V_23 -> V_13 + V_773 ,
V_774 | F_267 ( V_741 ) ) ;
F_2 ( V_1 , V_23 -> V_13 + V_773 ) ;
F_5 ( V_1 , V_23 -> V_13 + V_775 , V_776 | V_777 ) ;
F_5 ( V_1 , V_23 -> V_13 + V_778 , 0 ) ;
F_5 ( V_1 , V_23 -> V_13 + V_779 , 0 ) ;
F_5 ( V_1 , V_23 -> V_13 + V_780 ,
( V_23 -> V_29 << V_31 ) - 1 ) ;
F_5 ( V_1 , V_23 -> V_13 + V_781 , F_61 ( 1 ) ) ;
F_2 ( V_1 , V_23 -> V_13 + V_781 ) ;
V_5 = 50 ;
do {
F_28 ( 250 ) ;
V_8 = F_2 ( V_1 , V_23 -> V_13 + V_781 ) ;
} while ( ( V_8 & V_36 ) && -- V_5 );
if ( V_8 & V_36 ) {
F_41 ( V_1 , L_104 , V_23 -> V_373 ) ;
goto V_754;
}
F_6 ( V_1 , V_23 -> V_13 + V_748 , 0 , V_782 ) ;
return 0 ;
V_754:
return - 1 ;
}
static void F_268 ( struct V_1 * V_17 )
{
static const T_3 V_783 [ 4 ] [ 6 ] = {
{ 237 , 416 , 559 , 1071 , 2095 , 4143 } ,
{ 128 , 217 , 289 , 545 , 1057 , 2081 } ,
{ 73 , 118 , 154 , 282 , 538 , 1050 } ,
{ 67 , 107 , 86 , 150 , 278 , 534 }
} ;
static const T_3 V_784 [ 4 ] [ 6 ] = {
{ 711 , 1248 , 1677 , 3213 , 6285 , 12429 } ,
{ 384 , 651 , 867 , 1635 , 3171 , 6243 } ,
{ 219 , 354 , 462 , 846 , 1614 , 3150 } ,
{ 201 , 321 , 258 , 450 , 834 , 1602 }
} ;
T_3 V_8 , V_785 ;
unsigned int V_786 , V_787 ;
unsigned int V_788 , V_789 , V_790 , V_791 ;
F_269 ( V_17 -> V_122 , V_792 , & V_8 ) ;
V_787 = ( V_8 & V_793 ) >> 5 ;
F_40 ( V_17 -> V_122 , 0x2 , & V_785 ) ;
if ( V_785 == 0x37 ) {
F_270 ( V_17 -> V_122 , V_792 ,
V_8 & ~ V_794 &
~ V_793 ) ;
V_787 = 0 ;
}
F_269 ( V_17 -> V_122 , V_795 , & V_8 ) ;
V_789 = F_271 ( F_2 ( V_17 , V_796 ) ) ;
V_788 = V_17 -> V_43 . V_151 == 0 ? V_789 :
F_272 ( F_2 ( V_17 , V_797 ) ) ;
V_786 = F_198 ( V_17 -> V_43 . V_118 . V_31 ) - 1 ;
V_790 = V_783 [ V_786 ] [ V_787 ] ;
if ( V_8 & V_798 )
V_790 += V_789 * 4 ;
V_791 = V_784 [ V_786 ] [ V_787 ] + V_788 * 4 ;
if ( V_17 -> V_43 . V_151 == 0 )
F_6 ( V_17 , V_799 ,
F_273 ( V_800 ) ,
F_273 ( V_790 ) ) ;
else
F_6 ( V_17 , V_799 , F_274 ( V_801 ) ,
F_274 ( V_790 ) ) ;
F_6 ( V_17 , V_796 , F_275 ( V_802 ) ,
F_275 ( V_791 ) ) ;
F_5 ( V_17 , V_295 , 0xffffffff ) ;
F_6 ( V_17 , V_803 , 0 ,
V_804 | V_805 |
V_806 | V_807 ) ;
}
int F_276 ( struct V_1 * V_1 , T_1 V_808 )
{
int V_68 = - V_37 , V_5 , V_32 ;
const struct V_130 * V_44 = & V_1 -> V_43 . V_44 ;
if ( V_1 -> V_43 . V_151 > 0 )
F_255 ( V_1 ) ;
else if ( F_250 ( V_1 ) )
goto V_809;
if ( V_44 -> V_139 ) {
F_195 ( V_1 , & V_1 -> V_43 . V_681 ) ;
if ( F_257 ( & V_1 -> V_422 , V_44 -> V_139 , V_44 -> V_147 ) ||
F_257 ( & V_1 -> V_424 , V_44 -> V_139 , V_44 -> V_147 ) ||
F_257 ( & V_1 -> V_426 , V_44 -> V_139 , V_44 -> V_147 ) ||
F_277 ( & V_1 -> V_436 , V_1 -> V_43 . V_436 . V_570 ,
V_1 -> V_43 . V_436 . V_571 ,
V_1 -> V_43 . V_436 . V_572 ) )
goto V_809;
for ( V_32 = 0 ; V_32 < 32 ; V_32 ++ )
if ( F_148 ( V_1 , V_32 , V_519 ) )
goto V_809;
}
if ( F_245 ( V_1 , & V_1 -> V_43 . V_681 ) )
goto V_809;
F_227 ( V_1 ,
F_67 ( V_1 -> V_43 . V_810 . V_811 ,
V_644 ) , 1 ) ;
F_230 ( V_1 ,
F_67 ( V_1 -> V_43 . V_810 . V_811 , 16384U ) ) ;
F_238 ( V_1 , & V_1 -> V_43 . V_681 ) ;
if ( F_132 ( V_1 ) )
F_268 ( V_1 ) ;
else
F_6 ( V_1 , V_812 , 0 ,
V_813 | V_814 ) ;
if ( V_1 -> V_43 . V_151 == V_302 )
F_6 ( V_1 , V_720 , 0 ,
V_815 ) ;
F_5 ( V_1 , V_816 , 0xffffffff ) ;
F_5 ( V_1 , V_817 , 0 ) ;
F_5 ( V_1 , V_818 , 0 ) ;
F_246 ( V_1 , V_1 -> V_43 . V_717 ) ;
F_278 ( V_1 , & V_1 -> V_43 . V_810 ) ;
F_6 ( V_1 , V_819 , 0 , V_820 ) ;
F_5 ( V_1 , V_821 , F_136 ( V_1 ) ) ;
F_5 ( V_1 , V_203 , V_44 -> V_142 | V_808 ) ;
F_5 ( V_1 , V_822 ,
F_279 ( V_195 >> 2 ) ) ;
F_2 ( V_1 , V_822 ) ;
V_5 = 100 ;
do {
F_28 ( 20 ) ;
} while ( F_2 ( V_1 , V_203 ) && -- V_5 );
if ( ! V_5 ) {
F_41 ( V_1 , L_105 ) ;
goto V_809;
}
V_68 = 0 ;
V_809:
return V_68 ;
}
static void F_280 ( struct V_1 * V_1 , struct V_823 * V_11 )
{
static unsigned short V_824 [] = { 33 , 66 , 100 , 133 } ;
T_1 V_825 ;
if ( F_281 ( V_1 -> V_122 ) ) {
T_3 V_8 ;
V_11 -> V_826 = V_827 ;
F_269 ( V_1 -> V_122 , V_828 , & V_8 ) ;
V_11 -> V_31 = ( V_8 >> 4 ) & 0x3f ;
return;
}
V_825 = F_2 ( V_1 , V_829 ) ;
V_11 -> V_97 = V_824 [ F_282 ( V_825 ) ] ;
V_11 -> V_31 = ( V_825 & V_830 ) ? 64 : 32 ;
V_825 = F_283 ( V_825 ) ;
if ( V_825 == 0 )
V_11 -> V_826 = V_831 ;
else if ( V_825 < 4 )
V_11 -> V_826 = V_832 ;
else if ( V_825 < 8 )
V_11 -> V_826 = V_833 ;
else
V_11 -> V_826 = V_834 ;
}
static void F_284 ( struct V_218 * V_219 , unsigned int V_409 )
{
V_219 -> V_240 = V_409 ;
V_219 -> V_245 = V_219 -> V_97 = V_236 ;
V_219 -> V_246 = V_219 -> V_98 = V_237 ;
V_219 -> V_229 = V_219 -> V_217 = V_231 | V_232 ;
if ( V_219 -> V_240 & V_241 ) {
V_219 -> V_242 = V_219 -> V_240 ;
V_219 -> V_238 = V_239 ;
V_219 -> V_229 |= V_230 ;
} else {
V_219 -> V_242 = 0 ;
V_219 -> V_238 = V_244 ;
}
}
static unsigned int F_285 ( T_1 V_835 )
{
unsigned int V_31 = F_258 ( V_835 ) ;
unsigned int V_836 = ! ! ( V_835 & V_837 ) + 1 ;
unsigned int V_838 = ! ! ( V_835 & V_839 ) + 1 ;
unsigned int V_746 = F_259 ( V_835 ) ;
unsigned int V_840 = ( ( 256 << V_746 ) * V_836 ) / ( V_838 << V_31 ) ;
return V_840 << 20 ;
}
static void F_286 ( struct V_1 * V_1 , struct V_23 * V_23 ,
unsigned int V_497 , const char * V_373 )
{
T_1 V_835 ;
V_23 -> V_1 = V_1 ;
V_23 -> V_373 = V_373 ;
V_23 -> V_13 = V_497 - V_446 ;
V_835 = F_2 ( V_1 , V_23 -> V_13 + V_748 ) ;
V_23 -> V_29 = F_259 ( V_835 ) == V_841 ? 0 : F_285 ( V_835 ) ;
V_23 -> V_31 = F_258 ( V_835 ) ;
}
static void F_287 ( struct V_204 * V_205 , struct V_1 * V_1 , int V_842 )
{
T_3 V_785 ;
V_205 -> V_1 = V_1 ;
F_40 ( V_1 -> V_122 , 0x2 , & V_785 ) ;
if ( V_785 == 0x37 && ! V_1 -> V_43 . V_44 . V_157 [ 1 ] )
V_842 = 0 ;
V_205 -> V_13 = ( V_843 - V_844 ) * V_842 ;
V_205 -> V_845 = 1 ;
if ( V_1 -> V_43 . V_151 == 0 && F_54 ( V_1 ) ) {
F_5 ( V_1 , V_846 + V_205 -> V_13 ,
F_288 ( V_1 ) ? 0x2901c04 : 0x2301c04 ) ;
F_6 ( V_1 , V_847 + V_205 -> V_13 ,
V_848 , 0 ) ;
}
}
static void F_289 ( struct V_1 * V_1 ,
const struct V_40 * V_41 )
{
T_1 V_8 = F_290 ( F_288 ( V_1 ) ? 3 : 2 ) ;
F_9 ( V_1 , V_41 ) ;
F_5 ( V_1 , V_849 ,
F_291 ( V_1 -> V_43 . V_44 . V_45 / 80 - 1 ) ) ;
F_5 ( V_1 , V_850 ,
V_41 -> V_851 | V_852 | V_853 ) ;
F_5 ( V_1 , V_854 , 0 ) ;
F_5 ( V_1 , V_855 , F_292 ( 0xfff ) ) ;
if ( V_1 -> V_43 . V_151 == 0 || ! F_54 ( V_1 ) )
V_8 |= V_848 ;
F_5 ( V_1 , V_847 , V_8 ) ;
F_2 ( V_1 , V_847 ) ;
V_8 |= V_856 ;
F_5 ( V_1 , V_847 , V_8 ) ;
F_2 ( V_1 , V_847 ) ;
F_5 ( V_1 , F_143 ( V_847 , 1 ) , V_8 ) ;
F_2 ( V_1 , V_847 ) ;
}
int F_293 ( struct V_1 * V_1 )
{
int V_32 , V_857 =
V_1 -> V_43 . V_151 < V_858 && F_132 ( V_1 ) ;
T_6 V_785 = 0 ;
if ( V_857 )
F_294 ( V_1 -> V_122 ) ;
F_5 ( V_1 , V_819 , V_859 | V_860 ) ;
for ( V_32 = 0 ; V_32 < 10 ; V_32 ++ ) {
F_28 ( 50 ) ;
F_40 ( V_1 -> V_122 , 0x00 , & V_785 ) ;
if ( V_785 == 0x1425 )
break;
}
if ( V_785 != 0x1425 )
return - 1 ;
if ( V_857 )
F_295 ( V_1 -> V_122 ) ;
return 0 ;
}
static int F_296 ( struct V_1 * V_17 )
{
int V_32 , V_68 , V_15 ;
if ( F_2 ( V_17 , V_487 ) & V_488 )
return - V_165 ;
for ( V_68 = V_32 = 0 ; ! V_68 && V_32 < 16 ; V_32 ++ )
V_68 = F_148 ( V_17 , V_32 , V_505 ) ;
for ( V_32 = 0xfff0 ; ! V_68 && V_32 <= 0xffff ; V_32 ++ )
V_68 = F_148 ( V_17 , V_32 , V_505 ) ;
for ( V_32 = 0 ; ! V_68 && V_32 < V_861 ; V_32 ++ )
V_68 = F_148 ( V_17 , V_32 , V_482 ) ;
if ( V_68 )
return V_68 ;
F_5 ( V_17 , V_862 , 0 ) ;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ )
for ( V_15 = 0 ; V_15 <= V_863 ; V_15 ++ ) {
F_5 ( V_17 , V_864 , V_865 |
V_866 | F_297 ( V_32 ) |
F_298 ( V_15 ) ) ;
V_68 = F_18 ( V_17 , V_864 ,
V_867 , 0 , 2 , 1 ) ;
if ( V_68 )
return V_68 ;
}
return 0 ;
}
int F_299 ( struct V_1 * V_1 , const struct V_40 * V_41 ,
int V_249 )
{
int V_55 ;
unsigned int V_32 , V_525 = - 1 ;
F_280 ( V_1 , & V_1 -> V_43 . V_118 ) ;
V_1 -> V_43 . V_868 = V_41 ;
V_1 -> V_43 . V_869 = V_41 -> V_870 + V_41 -> V_871 ;
V_1 -> V_43 . V_717 = ( ! ! V_41 -> V_870 ) | ( ! ! V_41 -> V_871 << 1 ) ;
V_1 -> V_43 . V_151 = F_2 ( V_1 , V_872 ) ;
V_1 -> V_43 . V_873 = 10 ;
V_1 -> V_43 . V_874 = F_288 ( V_1 ) ?
V_875 : ( V_875 * 10 ) ;
V_1 -> V_43 . V_118 . V_119 =
F_300 ( V_1 -> V_122 , V_876 ) ;
V_55 = F_53 ( V_1 , & V_1 -> V_43 . V_44 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_249 && F_293 ( V_1 ) )
return - 1 ;
F_301 ( V_1 , & V_1 -> V_43 . V_810 ) ;
if ( V_1 -> V_43 . V_44 . V_139 ) {
struct V_536 * V_11 = & V_1 -> V_43 . V_681 ;
F_286 ( V_1 , & V_1 -> V_422 , V_446 , L_106 ) ;
F_286 ( V_1 , & V_1 -> V_424 , V_447 , L_107 ) ;
F_286 ( V_1 , & V_1 -> V_426 , V_448 , L_108 ) ;
V_11 -> V_877 = V_1 -> V_43 . V_717 == 3 ? 2 : 1 ;
V_11 -> V_878 = F_302 ( & V_1 -> V_422 ) ;
V_11 -> V_879 = F_302 ( & V_1 -> V_424 ) ;
V_11 -> V_569 = F_302 ( & V_1 -> V_426 ) ;
V_11 -> V_543 = V_11 -> V_878 / 2 ;
V_11 -> V_544 = V_11 -> V_879 / V_11 -> V_877 ;
V_11 -> V_554 = 64 * 1024 ;
V_11 -> V_547 = F_288 ( V_1 ) ? 64 * 1024 : 16 * 1024 ;
V_11 -> V_556 = F_194 ( V_11 -> V_543 , V_11 -> V_554 ) ;
V_11 -> V_549 = F_194 ( V_11 -> V_544 , V_11 -> V_547 ) ;
V_11 -> V_562 = V_11 -> V_569 >= ( 128 << 20 ) ||
V_1 -> V_43 . V_151 > 0 ? 12 : 6 ;
}
V_1 -> V_43 . V_880 = F_302 ( & V_1 -> V_422 ) &&
F_302 ( & V_1 -> V_424 ) &&
F_302 ( & V_1 -> V_426 ) ;
if ( F_192 ( V_1 ) ) {
V_1 -> V_43 . V_436 . V_570 = V_881 ;
V_1 -> V_43 . V_436 . V_571 = V_1 -> V_43 . V_151 > 0 ?
V_882 : 0 ;
V_1 -> V_43 . V_436 . V_572 = 0 ;
F_303 ( V_1 , & V_1 -> V_436 , V_883 ) ;
F_233 ( V_1 -> V_43 . V_649 ) ;
F_234 ( V_1 -> V_43 . V_884 , V_1 -> V_43 . V_885 ) ;
}
F_289 ( V_1 , V_41 ) ;
V_55 = F_296 ( V_1 ) ;
if ( V_55 )
return V_55 ;
F_129 (adapter, i) {
V_134 V_886 [ 6 ] ;
const struct V_887 * V_888 ;
struct V_53 * V_11 = F_88 ( V_1 , V_32 ) ;
while ( ! V_1 -> V_43 . V_44 . V_153 [ ++ V_525 ] )
;
V_888 = & V_889 [ V_1 -> V_43 . V_44 . V_153 [ V_525 ] ] ;
if ( ! V_888 -> V_890 ) {
F_99 ( V_1 , L_109 ,
V_1 -> V_43 . V_44 . V_153 [ V_525 ] ) ;
return - V_30 ;
}
V_11 -> V_63 . V_891 . V_50 = V_1 -> V_892 [ V_32 ] ;
V_55 = V_888 -> V_890 ( & V_11 -> V_63 , V_1 , V_41 -> V_893 + V_525 ,
V_41 -> V_894 ) ;
if ( V_55 )
return V_55 ;
F_287 ( & V_11 -> V_205 , V_1 , V_525 ) ;
memcpy ( V_886 , V_1 -> V_43 . V_44 . V_160 , 5 ) ;
V_886 [ 5 ] = V_1 -> V_43 . V_44 . V_160 [ 5 ] + V_32 ;
memcpy ( V_1 -> V_892 [ V_32 ] -> V_895 , V_886 ,
V_896 ) ;
F_284 ( & V_11 -> V_218 , V_11 -> V_63 . V_409 ) ;
V_11 -> V_63 . V_220 -> V_897 ( & V_11 -> V_63 , 1 ) ;
if ( ! ( V_11 -> V_63 . V_409 & V_410 ) &&
V_1 -> V_43 . V_873 > 10 )
V_1 -> V_43 . V_873 = 10 ;
}
return 0 ;
}
void F_304 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_850 , V_853 ,
V_853 ) ;
}
int F_305 ( struct V_1 * V_1 )
{
const struct V_40 * V_41 = V_1 -> V_43 . V_868 ;
unsigned int V_32 , V_525 = - 1 ;
int V_55 ;
F_289 ( V_1 , V_41 ) ;
V_55 = F_296 ( V_1 ) ;
if ( V_55 )
return V_55 ;
F_129 (adapter, i) {
const struct V_887 * V_888 ;
struct V_53 * V_11 = F_88 ( V_1 , V_32 ) ;
while ( ! V_1 -> V_43 . V_44 . V_153 [ ++ V_525 ] )
;
V_888 = & V_889 [ V_1 -> V_43 . V_44 . V_153 [ V_525 ] ] ;
V_55 = V_888 -> V_890 ( & V_11 -> V_63 , V_1 , V_11 -> V_63 . V_891 . V_898 , NULL ) ;
if ( V_55 )
return V_55 ;
V_11 -> V_63 . V_220 -> V_897 ( & V_11 -> V_63 , 1 ) ;
}
return 0 ;
}

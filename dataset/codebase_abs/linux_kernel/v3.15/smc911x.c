static void F_1 ( T_1 * V_1 , int V_2 )
{
int V_3 ;
int V_4 ;
int V_5 ;
V_5 = V_2 / 16 ;
V_4 = V_2 % 16 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
int V_6 ;
F_2 ( V_7 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) {
T_1 V_8 , V_9 ;
V_8 = * V_1 ++ ;
V_9 = * V_1 ++ ;
F_3 ( L_1 , V_8 , V_9 ) ;
}
F_3 ( L_2 ) ;
}
F_2 ( V_7 ) ;
for ( V_3 = 0 ; V_3 < V_4 / 2 ; V_3 ++ ) {
T_1 V_8 , V_9 ;
V_8 = * V_1 ++ ;
V_9 = * V_1 ++ ;
F_3 ( L_1 , V_8 , V_9 ) ;
}
F_3 ( L_2 ) ;
}
static void F_4 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_14 , V_15 = 0 , V_16 = 1 , V_17 ;
unsigned long V_18 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
if ( ( F_7 ( V_13 ) & V_21 ) == 0 ) {
F_8 ( V_13 , 0 ) ;
V_15 = 10 ;
do {
F_9 ( 10 ) ;
V_14 = F_7 ( V_13 ) & V_21 ;
} while ( -- V_15 && ! V_14 );
if ( V_15 == 0 ) {
F_10 ( V_11 , L_4 ) ;
return;
}
}
F_11 ( & V_13 -> V_22 , V_18 ) ;
F_12 ( V_13 , 0 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
while ( V_16 -- ) {
F_14 ( V_13 , V_23 ) ;
V_15 = 10 ;
do {
F_9 ( 10 ) ;
V_14 = F_15 ( V_13 ) ;
if ( V_14 & V_24 ) {
F_10 ( V_11 , L_5 ) ;
V_16 ++ ;
break;
}
} while ( -- V_15 && ( V_14 & V_23 ) );
}
if ( V_15 == 0 ) {
F_10 ( V_11 , L_6 ) ;
return;
}
V_15 = 1000 ;
while ( -- V_15 && ( F_16 ( V_13 ) & V_25 ) )
F_9 ( 10 ) ;
if ( V_15 == 0 ) {
F_10 ( V_11 , L_7 ) ;
return;
}
F_12 ( V_13 , 0 ) ;
F_17 ( V_13 , - 1 ) ;
F_14 ( V_13 , ( V_13 -> V_26 & 0xF ) << 16 ) ;
F_18 ( V_13 , V_27 | V_28 ) ;
F_19 ( V_13 , V_13 -> V_29 ) ;
F_20 ( V_13 , 0x70070000 ) ;
V_17 = ( 1 << 24 ) | V_30 | V_31 ;
#ifdef F_21
if ( V_13 -> V_32 . V_33 )
V_17 |= V_34 ;
#endif
F_22 ( V_13 , V_17 ) ;
if ( V_13 -> V_35 != NULL ) {
F_23 ( V_13 -> V_35 ) ;
V_13 -> V_35 = NULL ;
V_11 -> V_36 . V_37 ++ ;
V_11 -> V_36 . V_38 ++ ;
}
}
static void F_24 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned V_39 , V_32 , V_40 ;
unsigned long V_18 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
F_25 ( V_13 , V_11 -> V_41 ) ;
V_32 = F_15 ( V_13 ) ;
V_32 &= V_42 | 0xFFF ;
V_32 |= V_43 ;
F_14 ( V_13 , V_32 ) ;
F_26 ( V_13 , 0xFF ) ;
F_27 ( V_13 , 64 ) ;
F_28 ( V_13 , V_44 | 10000 ) ;
F_29 ( V_13 , V_40 ) ;
V_40 |= V_45 | V_46 ;
F_30 ( V_13 , V_40 ) ;
F_31 ( V_13 , V_47 ) ;
F_32 ( V_13 , ( 2 << 8 ) & V_48 ) ;
if ( V_40 & V_49 )
F_6 ( V_50 , V_11 , L_8 ) ;
F_30 ( V_13 , V_40 | V_49 ) ;
F_33 ( V_13 , 0x01 ) ;
F_34 ( V_13 , 0x00 ) ;
V_39 = V_51 | V_52 | V_53 |
V_54 | V_55 | V_56 |
V_57 ;
if ( F_35 ( V_13 -> V_58 ) )
V_39 |= V_59 ;
else {
V_39 |= V_60 ;
}
F_36 ( V_13 , V_39 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
}
static void F_37 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned V_40 ;
unsigned long V_18 ;
F_6 ( V_19 , V_11 , L_9 , V_61 , V_20 ) ;
F_12 ( V_13 , 0 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
F_29 ( V_13 , V_40 ) ;
V_40 &= ~ ( V_45 | V_49 | V_46 ) ;
F_30 ( V_13 , V_40 ) ;
F_31 ( V_13 , V_62 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
}
static inline void F_38 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_63 , V_15 , V_14 ;
F_6 ( V_19 | V_50 , V_11 , L_9 ,
V_61 , V_20 ) ;
V_63 = F_39 ( V_13 ) & 0xFFFF ;
if ( V_63 <= 4 ) {
while ( V_63 -- )
F_40 ( V_13 ) ;
} else {
F_41 ( V_13 , V_64 ) ;
V_15 = 50 ;
do {
F_9 ( 10 ) ;
V_14 = F_42 ( V_13 ) & V_64 ;
} while ( -- V_15 && V_14 );
if ( V_15 == 0 ) {
F_10 ( V_11 , L_10 ) ;
}
}
}
static inline void F_43 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_65 , V_66 ;
struct V_67 * V_68 ;
unsigned char * V_69 ;
F_6 ( V_19 | V_50 , V_11 , L_3 ,
V_20 ) ;
V_66 = F_44 ( V_13 ) ;
F_6 ( V_50 , V_11 , L_11 ,
( V_66 & 0x3fff0000 ) >> 16 , V_66 & 0xc000ffff ) ;
V_65 = ( V_66 & V_70 ) >> 16 ;
if ( V_66 & V_71 ) {
V_11 -> V_36 . V_72 ++ ;
if ( V_66 & V_73 )
V_11 -> V_36 . V_74 ++ ;
else {
if ( V_66 & V_75 )
V_11 -> V_36 . V_76 ++ ;
if ( V_66 & V_77 )
V_11 -> V_36 . V_78 ++ ;
}
F_38 ( V_11 ) ;
} else {
V_68 = F_45 ( V_11 , V_65 + 32 ) ;
if ( F_46 ( V_68 == NULL ) ) {
F_10 ( V_11 , L_12 ) ;
V_11 -> V_36 . V_79 ++ ;
F_38 ( V_11 ) ;
return;
}
V_69 = V_68 -> V_69 ;
F_47 ( V_68 , 2 ) ;
F_48 ( V_68 , V_65 - 4 ) ;
#ifdef F_49
{
unsigned int V_80 ;
V_80 = F_50 ( V_13 ) ;
if ( V_80 & 0xFF ) V_80 -- ;
F_6 ( V_50 , V_11 , L_13 ,
V_80 & 0xff ) ;
F_51 ( V_13 , V_80 ) ;
F_32 ( V_13 , V_81 | ( ( 2 << 8 ) & V_48 ) ) ;
V_13 -> V_82 = 1 ;
V_13 -> V_83 = V_68 ;
F_52 ( V_13 , V_69 , ( V_65 + 2 + 15 ) & ~ 15 ) ;
}
#else
F_32 ( V_13 , V_84 | ( ( 2 << 8 ) & V_48 ) ) ;
F_52 ( V_13 , V_69 , V_65 + 2 + 3 ) ;
F_6 ( V_85 , V_11 , L_14 ) ;
F_1 ( V_69 , ( ( V_65 - 4 ) <= 64 ) ? V_65 - 4 : 64 ) ;
V_68 -> V_86 = F_53 ( V_68 , V_11 ) ;
F_54 ( V_68 ) ;
V_11 -> V_36 . V_87 ++ ;
V_11 -> V_36 . V_88 += V_65 - 4 ;
#endif
}
}
static void F_55 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_67 * V_68 ;
unsigned int V_89 , V_90 , V_91 ;
unsigned char * V_1 ;
F_6 ( V_19 | V_92 , V_11 , L_3 , V_20 ) ;
F_56 ( V_13 -> V_35 == NULL ) ;
V_68 = V_13 -> V_35 ;
V_13 -> V_35 = NULL ;
#ifdef F_49
V_1 = ( char * ) ( ( V_93 ) ( V_68 -> V_69 ) & ~ 0xF ) ;
V_91 = ( V_68 -> V_91 + 0xF + ( ( V_93 ) V_68 -> V_69 & 0xF ) ) & ~ 0xF ;
V_89 = ( 1 << 24 ) | ( ( ( V_93 ) V_68 -> V_69 & 0xF ) << 16 ) |
V_94 | V_95 |
V_68 -> V_91 ;
#else
V_1 = ( char * ) ( ( V_93 ) V_68 -> V_69 & ~ 0x3 ) ;
V_91 = ( V_68 -> V_91 + 3 + ( ( V_93 ) V_68 -> V_69 & 3 ) ) & ~ 0x3 ;
V_89 = ( ( ( V_93 ) V_68 -> V_69 & 0x3 ) << 16 ) |
V_94 | V_95 |
V_68 -> V_91 ;
#endif
V_90 = ( V_68 -> V_91 << 16 ) | ( V_68 -> V_91 & 0x7FF ) ;
F_6 ( V_92 , V_11 , L_15 ,
V_91 , V_91 , V_1 , V_89 , V_90 ) ;
F_57 ( V_13 , V_89 ) ;
F_57 ( V_13 , V_90 ) ;
F_6 ( V_85 , V_11 , L_16 ) ;
F_1 ( V_1 , V_91 <= 64 ? V_91 : 64 ) ;
#ifdef F_49
V_13 -> V_96 = V_68 ;
F_58 ( V_13 , V_1 , V_91 ) ;
#else
F_58 ( V_13 , V_1 , V_91 ) ;
V_11 -> V_97 = V_98 ;
F_59 ( V_68 ) ;
#endif
if ( ! V_13 -> V_99 ) {
F_60 ( V_11 ) ;
}
F_36 ( V_13 , V_51 | V_52 ) ;
}
static int F_61 ( struct V_67 * V_68 , struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int free ;
unsigned long V_18 ;
F_6 ( V_19 | V_92 , V_11 , L_3 ,
V_20 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
F_56 ( V_13 -> V_35 != NULL ) ;
free = F_62 ( V_13 ) & V_100 ;
F_6 ( V_92 , V_11 , L_17 , free ) ;
if ( free <= V_101 ) {
F_6 ( V_92 , V_11 , L_18 ,
free ) ;
F_26 ( V_13 , ( V_101 ) / 64 ) ;
V_13 -> V_99 = 1 ;
F_63 ( V_11 ) ;
}
if ( F_46 ( free < ( V_68 -> V_91 + 8 + 15 + 15 ) ) ) {
F_64 ( V_11 , L_19 ,
free , V_68 -> V_91 ) ;
V_13 -> V_35 = NULL ;
V_11 -> V_36 . V_37 ++ ;
V_11 -> V_36 . V_102 ++ ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
F_65 ( V_68 ) ;
return V_103 ;
}
#ifdef F_49
{
if ( V_13 -> V_104 ) {
F_6 ( V_92 | V_105 , V_11 , L_20 ) ;
V_13 -> V_35 = V_68 ;
F_63 ( V_11 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
return V_103 ;
} else {
F_6 ( V_92 | V_105 , V_11 , L_21 ) ;
V_13 -> V_104 = 1 ;
}
}
#endif
V_13 -> V_35 = V_68 ;
F_55 ( V_11 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
return V_103 ;
}
static void F_66 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_106 ;
F_6 ( V_19 | V_92 , V_11 , L_3 ,
V_20 ) ;
while ( ( ( F_62 ( V_13 ) & V_107 ) >> 16 ) != 0 ) {
F_6 ( V_92 , V_11 , L_22 ,
( F_62 ( V_13 ) & V_107 ) >> 16 ) ;
V_106 = F_67 ( V_13 ) ;
V_11 -> V_36 . V_108 ++ ;
V_11 -> V_36 . V_109 += V_106 >> 16 ;
F_6 ( V_92 , V_11 , L_23 ,
( V_106 & 0xffff0000 ) >> 16 ,
V_106 & 0x0000ffff ) ;
if ( ( V_106 & V_110 ) && ! ( V_13 -> V_111 &&
! ( V_106 & 0x00000306 ) ) ) {
V_11 -> V_36 . V_37 ++ ;
}
if ( V_106 & V_112 ) {
V_11 -> V_36 . V_113 += 16 ;
V_11 -> V_36 . V_38 ++ ;
} else {
V_11 -> V_36 . V_113 += ( V_106 & V_114 ) >> 3 ;
}
if ( ( V_106 & ( V_115 | V_116 ) ) &&
! V_13 -> V_111 ) {
V_11 -> V_36 . V_117 ++ ;
}
if ( V_106 & V_118 ) {
V_11 -> V_36 . V_113 ++ ;
V_11 -> V_36 . V_38 ++ ;
}
}
}
static int F_68 ( struct V_10 * V_11 , int V_119 , int V_120 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_121 ;
F_69 ( V_13 , V_120 , V_119 , V_121 ) ;
F_6 ( V_122 , V_11 , L_24 ,
V_20 , V_119 , V_120 , V_121 ) ;
return V_121 ;
}
static void F_70 ( struct V_10 * V_11 , int V_119 , int V_120 ,
int V_121 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_6 ( V_122 , V_11 , L_25 ,
V_20 , V_119 , V_120 , V_121 ) ;
F_71 ( V_13 , V_120 , V_119 , V_121 ) ;
}
static void F_72 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_119 ;
unsigned int V_32 , V_123 , V_124 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
V_13 -> V_125 = 0 ;
switch( V_13 -> V_126 ) {
case V_127 :
case V_128 :
case V_129 :
case V_130 :
V_32 = F_15 ( V_13 ) ;
if ( V_32 & V_131 ) {
V_32 &= ~ V_132 ;
V_32 |= V_133 ;
F_14 ( V_13 , V_32 ) ;
F_9 ( 10 ) ;
V_32 |= V_134 ;
F_14 ( V_13 , V_32 ) ;
F_9 ( 10 ) ;
V_32 &= ~ V_132 ;
V_32 |= V_135 ;
F_14 ( V_13 , V_32 ) ;
F_9 ( 10 ) ;
V_32 |= V_136 ;
F_14 ( V_13 , V_32 ) ;
for ( V_119 = 1 ; V_119 < 32 ; ++ V_119 ) {
F_73 ( V_13 , V_119 & 31 , V_123 ) ;
F_74 ( V_13 , V_119 & 31 , V_124 ) ;
if ( V_123 != 0x0000 && V_123 != 0xffff &&
V_123 != 0x8000 && V_124 != 0x0000 &&
V_124 != 0xffff && V_124 != 0x8000 ) {
V_13 -> V_137 . V_138 = V_119 & 31 ;
V_13 -> V_125 = V_123 << 16 | V_124 ;
break;
}
}
if ( V_119 < 32 )
break;
}
default:
F_73 ( V_13 , 1 , V_123 ) ;
F_74 ( V_13 , 1 , V_124 ) ;
V_13 -> V_137 . V_138 = 1 ;
V_13 -> V_125 = V_123 << 16 | V_124 ;
}
F_6 ( V_122 , V_11 , L_26 ,
V_123 , V_124 , V_13 -> V_137 . V_138 ) ;
}
static int F_75 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_119 = V_13 -> V_137 . V_138 ;
int V_139 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_76 ( V_13 , V_119 , V_139 ) ;
V_139 |= V_140 ;
F_77 ( V_13 , V_119 , V_139 ) ;
V_139 &= ~ V_141 ;
if ( V_13 -> V_111 )
V_139 |= V_142 ;
if ( V_13 -> V_143 == 100 )
V_139 |= V_144 ;
F_77 ( V_13 , V_119 , V_139 ) ;
V_139 &= ~ V_140 ;
F_77 ( V_13 , V_119 , V_139 ) ;
return 1 ;
}
static int F_78 ( struct V_10 * V_11 , int V_145 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_15 ;
unsigned long V_18 ;
unsigned int V_14 ;
F_6 ( V_19 , V_11 , L_27 , V_20 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_14 = F_7 ( V_13 ) ;
V_14 &= ~ 0xfffff030 ;
V_14 |= V_146 ;
F_79 ( V_13 , V_14 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
for ( V_15 = 2 ; V_15 ; V_15 -- ) {
F_80 ( 50 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_14 = F_7 ( V_13 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
if ( ! ( V_14 & V_146 ) ) {
F_9 ( 500 ) ;
break;
}
}
return V_14 & V_146 ;
}
static void F_81 ( struct V_10 * V_11 , int V_145 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_139 ;
F_76 ( V_13 , V_145 , V_139 ) ;
V_139 |= V_140 ;
F_77 ( V_13 , V_145 , V_139 ) ;
}
static void F_82 ( struct V_10 * V_11 , int V_147 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_119 = V_13 -> V_137 . V_138 ;
unsigned int V_139 , V_40 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
if ( F_83 ( & V_13 -> V_137 , F_84 ( V_13 ) , V_147 ) ) {
F_76 ( V_13 , V_119 , V_139 ) ;
F_29 ( V_13 , V_40 ) ;
if ( V_13 -> V_137 . V_148 ) {
F_6 ( V_122 , V_11 , L_28 ) ;
V_139 |= V_142 ;
V_40 |= V_149 ;
} else {
F_6 ( V_122 , V_11 , L_29 ) ;
V_139 &= ~ V_142 ;
V_40 &= ~ V_149 ;
}
F_77 ( V_13 , V_119 , V_139 ) ;
F_30 ( V_13 , V_40 ) ;
}
}
static void F_85 ( struct V_150 * V_151 )
{
struct V_12 * V_13 = F_86 ( V_151 , struct V_12 ,
V_152 ) ;
struct V_10 * V_11 = V_13 -> V_153 ;
int V_119 = V_13 -> V_137 . V_138 ;
int V_154 ;
int V_155 ;
int V_66 ;
unsigned long V_18 ;
F_6 ( V_19 , V_11 , L_27 , V_20 ) ;
if ( V_13 -> V_125 == 0 )
return;
if ( F_78 ( V_11 , V_119 ) ) {
F_87 ( V_11 , L_30 ) ;
return;
}
F_11 ( & V_13 -> V_22 , V_18 ) ;
F_88 ( V_13 , V_119 , V_156 |
V_157 | V_158 |
V_159 ) ;
if ( V_13 -> V_137 . V_160 ) {
F_75 ( V_11 ) ;
goto V_161;
}
F_89 ( V_13 , V_119 , V_154 ) ;
if ( ! ( V_154 & V_162 ) ) {
F_87 ( V_11 , L_31 ) ;
F_75 ( V_11 ) ;
goto V_161;
}
V_155 = V_163 | V_164 | V_165 ;
if ( V_154 & V_166 )
V_155 |= V_167 ;
if ( V_154 & V_168 )
V_155 |= V_169 ;
if ( V_154 & V_170 )
V_155 |= V_171 ;
if ( V_154 & V_172 )
V_155 |= V_173 ;
if ( V_154 & V_174 )
V_155 |= V_175 ;
if ( V_13 -> V_143 != 100 )
V_155 &= ~ ( V_167 | V_169 | V_171 ) ;
if ( ! V_13 -> V_111 )
V_155 &= ~ ( V_169 | V_173 ) ;
F_90 ( V_13 , V_119 , V_155 ) ;
V_13 -> V_137 . V_176 = V_155 ;
F_9 ( 10 ) ;
F_91 ( V_13 , V_119 , V_66 ) ;
F_6 ( V_122 , V_11 , L_32 , V_154 ) ;
F_6 ( V_122 , V_11 , L_33 , V_155 ) ;
F_77 ( V_13 , V_119 , V_141 | V_177 ) ;
F_82 ( V_11 , 1 ) ;
V_161:
F_13 ( & V_13 -> V_22 , V_18 ) ;
}
static void F_92 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_119 = V_13 -> V_137 . V_138 ;
int V_66 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
if ( V_13 -> V_125 == 0 )
return;
F_82 ( V_11 , 0 ) ;
F_93 ( V_13 , V_119 , V_66 ) ;
F_6 ( V_122 , V_11 , L_34 ,
V_66 & 0xffff ) ;
F_6 ( V_122 , V_11 , L_35 ,
F_94 ( V_13 ) ) ;
}
static T_2 F_95 ( int V_178 , void * V_179 )
{
struct V_10 * V_11 = V_179 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_66 , V_39 , V_15 ;
unsigned int V_180 = 0 , V_40 , V_181 ;
unsigned long V_18 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
if ( ( F_96 ( V_13 ) & ( V_182 | V_30 ) ) !=
( V_182 | V_30 ) ) {
F_13 ( & V_13 -> V_22 , V_18 ) ;
return V_183 ;
}
V_39 = F_97 ( V_13 ) ;
F_12 ( V_13 , 0 ) ;
V_15 = 8 ;
do {
V_66 = F_98 ( V_13 ) ;
F_6 ( V_122 , V_11 , L_36 ,
V_66 , V_39 , V_66 & ~ V_39 ) ;
V_66 &= V_39 ;
if ( ! V_66 )
break;
if ( V_66 & V_184 ) {
F_17 ( V_13 , V_184 ) ;
V_39 &= ~ V_185 ;
}
if ( V_66 & V_186 ) {
F_17 ( V_13 , V_186 ) ;
V_11 -> V_36 . V_72 ++ ;
}
if ( V_66 & V_187 ) {
F_17 ( V_13 , V_187 ) ;
V_11 -> V_36 . V_79 += F_99 ( V_13 ) ;
}
if ( V_66 & V_188 ) {
F_17 ( V_13 , V_188 ) ;
}
if ( V_66 & V_189 ) {
if ( F_35 ( V_13 -> V_58 ) ) {
V_180 = 1 ;
F_29 ( V_13 , V_40 ) ;
V_40 &= ~ V_49 ;
F_30 ( V_13 , V_40 ) ;
F_6 ( V_50 , V_11 , L_37 ) ;
V_11 -> V_36 . V_72 ++ ;
V_11 -> V_36 . V_190 ++ ;
}
F_17 ( V_13 , V_189 ) ;
}
if ( V_66 & V_191 ) {
if ( ! F_35 ( V_13 -> V_58 ) ) {
F_29 ( V_13 , V_40 ) ;
V_40 &= ~ V_49 ;
F_30 ( V_13 , V_40 ) ;
V_180 = 1 ;
F_6 ( V_50 , V_11 , L_37 ) ;
V_11 -> V_36 . V_72 ++ ;
V_11 -> V_36 . V_190 ++ ;
}
F_17 ( V_13 , V_191 ) ;
}
if ( ( V_66 & V_192 ) || V_180 ) {
unsigned int V_80 ;
F_6 ( V_50 , V_11 , L_38 ) ;
V_80 = F_39 ( V_13 ) ;
V_181 = ( V_80 & V_193 ) >> 16 ;
F_6 ( V_50 , V_11 , L_39 ,
V_181 , V_80 & 0xFFFF ) ;
if ( V_181 != 0 ) {
#ifdef F_49
unsigned int V_80 ;
if ( V_13 -> V_82 ) {
F_6 ( V_50 | V_105 , V_11 ,
L_40 ) ;
V_80 = F_50 ( V_13 ) & ~ 0xFF ;
V_80 |= V_181 & 0xFF ;
F_6 ( V_50 , V_11 ,
L_13 ,
V_80 & 0xff ) ;
F_51 ( V_13 , V_80 ) ;
} else
#endif
F_43 ( V_11 ) ;
}
F_17 ( V_13 , V_192 ) ;
}
if ( V_66 & V_194 ) {
F_6 ( V_92 , V_11 , L_41 ) ;
F_26 ( V_13 , 0xFF ) ;
V_13 -> V_99 = 0 ;
#ifdef F_49
if ( ! V_13 -> V_104 )
#endif
F_60 ( V_11 ) ;
F_17 ( V_13 , V_194 ) ;
}
#if 1
if ( V_66 & ( V_195 | V_196 ) ) {
F_6 ( V_92 | V_122 , V_11 ,
L_42 ,
( F_50 ( V_13 ) & 0x00ff0000 ) >> 16 ) ;
F_66 ( V_11 ) ;
F_28 ( V_13 , V_44 | 10000 ) ;
F_17 ( V_13 , V_195 ) ;
F_17 ( V_13 , V_195 | V_196 ) ;
}
#else
if ( V_66 & V_195 ) {
F_6 ( V_92 , V_11 , L_43 , ? ) ;
F_66 ( V_11 ) ;
F_17 ( V_13 , V_195 ) ;
}
if ( V_66 & V_196 ) {
F_6 ( V_50 , V_11 , L_44 ,
F_96 ( V_13 ) ,
F_50 ( V_13 ) ,
F_100 ( V_13 ) ) ;
F_6 ( V_50 , V_11 , L_45 ,
( F_39 ( V_13 ) & 0x00ff0000 ) >> 16 ,
F_39 ( V_13 ) & 0xffff ,
F_101 ( V_13 ) ) ;
F_28 ( V_13 , V_44 | 10000 ) ;
F_17 ( V_13 , V_196 ) ;
}
#endif
if ( V_66 & V_197 ) {
F_6 ( V_122 , V_11 , L_46 ) ;
F_92 ( V_11 ) ;
F_17 ( V_13 , V_197 ) ;
}
} while ( -- V_15 );
F_12 ( V_13 , V_39 ) ;
F_6 ( V_122 , V_11 , L_47 ,
8 - V_15 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
return V_198 ;
}
static void
F_102 ( int V_199 , void * V_69 )
{
struct V_10 * V_11 = (struct V_10 * ) V_69 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_67 * V_68 = V_13 -> V_96 ;
unsigned long V_18 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_6 ( V_92 | V_105 , V_11 , L_48 ) ;
F_103 ( V_11 , V_199 ) ;
F_56 ( V_68 == NULL ) ;
F_104 ( NULL , V_200 , V_201 , V_202 ) ;
V_11 -> V_97 = V_98 ;
F_59 ( V_68 ) ;
V_13 -> V_96 = NULL ;
if ( V_13 -> V_35 != NULL )
F_55 ( V_11 ) ;
else {
F_6 ( V_92 | V_105 , V_11 ,
L_49 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_13 -> V_104 = 0 ;
if ( ! V_13 -> V_99 ) {
F_60 ( V_11 ) ;
}
F_13 ( & V_13 -> V_22 , V_18 ) ;
}
F_6 ( V_92 | V_105 , V_11 ,
L_50 ) ;
}
static void
F_105 ( int V_199 , void * V_69 )
{
struct V_10 * V_11 = (struct V_10 * ) V_69 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_67 * V_68 = V_13 -> V_83 ;
unsigned long V_18 ;
unsigned int V_181 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_6 ( V_50 | V_105 , V_11 , L_51 ) ;
F_103 ( V_11 , V_199 ) ;
F_104 ( NULL , V_203 , V_204 , V_205 ) ;
F_56 ( V_68 == NULL ) ;
V_13 -> V_83 = NULL ;
F_1 ( V_68 -> V_69 , V_68 -> V_91 ) ;
V_68 -> V_86 = F_53 ( V_68 , V_11 ) ;
V_11 -> V_36 . V_87 ++ ;
V_11 -> V_36 . V_88 += V_68 -> V_91 ;
F_54 ( V_68 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_181 = ( F_39 ( V_13 ) & V_193 ) >> 16 ;
if ( V_181 != 0 ) {
F_43 ( V_11 ) ;
} else {
V_13 -> V_82 = 0 ;
}
F_13 ( & V_13 -> V_22 , V_18 ) ;
F_6 ( V_50 | V_105 , V_11 ,
L_52 ,
V_181 ) ;
}
static void F_106 ( struct V_10 * V_11 )
{
F_107 ( V_11 -> V_178 ) ;
F_95 ( V_11 -> V_178 , V_11 ) ;
F_108 ( V_11 -> V_178 ) ;
}
static void F_109 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_66 , V_39 ;
unsigned long V_18 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_66 = F_98 ( V_13 ) ;
V_39 = F_97 ( V_13 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
F_6 ( V_122 , V_11 , L_53 ,
V_66 , V_39 ) ;
V_39 = F_110 ( V_13 ) ;
F_31 ( V_13 , V_39 | V_206 | V_207 ) ;
if ( V_13 -> V_125 != 0 )
F_111 ( & V_13 -> V_152 ) ;
V_11 -> V_97 = V_98 ;
F_60 ( V_11 ) ;
}
static void F_112 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_208 [ 2 ] ;
unsigned int V_209 , V_210 = 0 ;
unsigned long V_18 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
F_29 ( V_13 , V_209 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
if ( V_11 -> V_18 & V_211 ) {
F_6 ( V_122 , V_11 , L_54 ) ;
V_209 |= V_212 ;
}
else if ( V_11 -> V_18 & V_213 || F_113 ( V_11 ) > 16 ) {
F_6 ( V_122 , V_11 , L_55 ) ;
V_209 |= V_214 ;
}
else if ( ! F_114 ( V_11 ) ) {
struct V_215 * V_216 ;
V_209 |= V_217 ;
memset ( V_208 , 0 , sizeof( V_208 ) ) ;
F_115 (ha, dev) {
V_93 V_218 ;
V_218 = F_116 ( V_219 , V_216 -> V_220 ) >> 26 ;
V_208 [ V_218 >> 5 ] |= 1 << ( V_218 & 0x1f ) ;
}
V_209 &= ~ ( V_212 | V_214 ) ;
V_210 = 1 ;
} else {
F_6 ( V_122 , V_11 , L_56 ) ;
V_209 &= ~ ( V_212 | V_214 ) ;
memset ( V_208 , 0 , sizeof( V_208 ) ) ;
V_210 = 1 ;
}
F_11 ( & V_13 -> V_22 , V_18 ) ;
F_30 ( V_13 , V_209 ) ;
if ( V_210 ) {
F_6 ( V_122 , V_11 ,
L_57 ,
V_208 [ 0 ] , V_208 [ 1 ] ) ;
F_117 ( V_13 , V_208 [ 0 ] ) ;
F_118 ( V_13 , V_208 [ 1 ] ) ;
}
F_13 ( & V_13 -> V_22 , V_18 ) ;
}
static int
F_119 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_4 ( V_11 ) ;
F_85 ( & V_13 -> V_152 ) ;
F_24 ( V_11 ) ;
F_120 ( V_11 ) ;
return 0 ;
}
static int F_121 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_63 ( V_11 ) ;
F_122 ( V_11 ) ;
F_37 ( V_11 ) ;
if ( V_13 -> V_125 != 0 ) {
F_123 ( & V_13 -> V_152 ) ;
F_81 ( V_11 , V_13 -> V_137 . V_138 ) ;
}
if ( V_13 -> V_35 ) {
F_23 ( V_13 -> V_35 ) ;
V_13 -> V_35 = NULL ;
}
return 0 ;
}
static int
F_124 ( struct V_10 * V_11 , struct V_221 * V_222 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_223 , V_66 ;
unsigned long V_18 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
V_222 -> V_224 = 1 ;
V_222 -> V_225 = 1 ;
if ( V_13 -> V_125 != 0 ) {
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_223 = F_125 ( & V_13 -> V_137 , V_222 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
} else {
V_222 -> V_226 = V_227 |
V_228 |
V_229 | V_230 ;
if ( V_13 -> V_143 == 10 )
F_126 ( V_222 , V_231 ) ;
else if ( V_13 -> V_143 == 100 )
F_126 ( V_222 , V_232 ) ;
V_222 -> V_233 = V_234 ;
if ( V_13 -> V_137 . V_138 == 1 )
V_222 -> V_235 = V_236 ;
else
V_222 -> V_235 = V_237 ;
V_222 -> V_238 = 0 ;
F_127 ( V_13 , V_13 -> V_137 . V_138 , V_66 ) ;
V_222 -> V_239 =
( V_66 & ( V_240 | V_241 ) ) ?
V_242 : V_243 ;
V_223 = 0 ;
}
return V_223 ;
}
static int
F_128 ( struct V_10 * V_11 , struct V_221 * V_222 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_223 ;
unsigned long V_18 ;
if ( V_13 -> V_125 != 0 ) {
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_223 = F_129 ( & V_13 -> V_137 , V_222 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
} else {
if ( V_222 -> V_233 != V_234 ||
V_222 -> V_244 != V_231 ||
( V_222 -> V_239 != V_243 && V_222 -> V_239 != V_242 ) ||
( V_222 -> V_238 != V_245 && V_222 -> V_238 != V_246 ) )
return - V_247 ;
V_13 -> V_111 = V_222 -> V_239 == V_242 ;
V_223 = 0 ;
}
return V_223 ;
}
static void
F_130 ( struct V_10 * V_11 , struct V_248 * V_249 )
{
F_131 ( V_249 -> V_250 , V_61 , sizeof( V_249 -> V_250 ) ) ;
F_131 ( V_249 -> V_126 , V_126 , sizeof( V_249 -> V_126 ) ) ;
F_131 ( V_249 -> V_251 , F_132 ( V_11 -> V_11 . V_252 ) ,
sizeof( V_249 -> V_251 ) ) ;
}
static int F_133 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_223 = - V_247 ;
unsigned long V_18 ;
if ( V_13 -> V_125 != 0 ) {
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_223 = F_134 ( & V_13 -> V_137 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
}
return V_223 ;
}
static V_93 F_135 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
return V_13 -> V_253 ;
}
static void F_136 ( struct V_10 * V_11 , V_93 V_254 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
V_13 -> V_253 = V_254 ;
}
static int F_137 ( struct V_10 * V_11 )
{
return ( ( ( V_255 - V_256 ) / 4 + 1 ) +
( V_257 - V_258 ) + 1 + 32 ) * sizeof( V_93 ) ;
}
static void F_138 ( struct V_10 * V_11 ,
struct V_259 * V_260 , void * V_1 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned long V_18 ;
V_93 V_14 , V_3 , V_261 = 0 ;
V_93 * V_69 = ( V_93 * ) V_1 ;
V_260 -> V_126 = V_13 -> V_126 ;
for( V_3 = V_256 ; V_3 <= V_255 ; V_3 += 4 ) {
V_69 [ V_261 ++ ] = F_139 ( V_13 , V_3 ) ;
}
for( V_3 = V_258 ; V_3 <= V_257 ; V_3 ++ ) {
F_11 ( & V_13 -> V_22 , V_18 ) ;
F_140 ( V_13 , V_3 , V_14 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
V_69 [ V_261 ++ ] = V_14 ;
}
for( V_3 = 0 ; V_3 <= 31 ; V_3 ++ ) {
F_11 ( & V_13 -> V_22 , V_18 ) ;
F_69 ( V_13 , V_3 , V_13 -> V_137 . V_138 , V_14 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
V_69 [ V_261 ++ ] = V_14 & 0xFFFF ;
}
}
static int F_141 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_15 ;
int V_262 ;
V_262 = F_16 ( V_13 ) ;
for( V_15 = 10 ; ( V_262 & V_25 ) && V_15 ; V_15 -- ) {
if ( V_262 & V_263 ) {
F_10 ( V_11 , L_58 ,
V_20 ) ;
return - V_264 ;
}
F_142 ( 1 ) ;
V_262 = F_16 ( V_13 ) ;
}
if ( V_15 == 0 ) {
F_10 ( V_11 , L_59 ,
V_20 ) ;
return - V_265 ;
}
return 0 ;
}
static inline int F_143 ( struct V_10 * V_11 ,
int V_222 , int V_220 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_223 ;
if ( ( V_223 = F_141 ( V_11 ) ) != 0 )
return V_223 ;
F_144 ( V_13 , V_25 |
( ( V_222 ) & ( 0x7 << 28 ) ) |
( ( V_220 ) & 0xFF ) ) ;
return 0 ;
}
static inline int F_145 ( struct V_10 * V_11 ,
T_3 * V_69 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_223 ;
if ( ( V_223 = F_141 ( V_11 ) ) != 0 )
return V_223 ;
* V_69 = F_146 ( V_13 ) ;
return 0 ;
}
static inline int F_147 ( struct V_10 * V_11 ,
T_3 V_69 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_223 ;
if ( ( V_223 = F_141 ( V_11 ) ) != 0 )
return V_223 ;
F_148 ( V_13 , V_69 ) ;
return 0 ;
}
static int F_149 ( struct V_10 * V_11 ,
struct V_266 * V_267 , T_3 * V_69 )
{
T_3 V_268 [ V_269 ] ;
int V_3 , V_223 ;
for( V_3 = 0 ; V_3 < V_269 ; V_3 ++ ) {
if ( ( V_223 = F_143 ( V_11 , V_270 , V_3 ) ) != 0 )
return V_223 ;
if ( ( V_223 = F_145 ( V_11 , & V_268 [ V_3 ] ) ) != 0 )
return V_223 ;
}
memcpy ( V_69 , V_268 + V_267 -> V_271 , V_267 -> V_91 ) ;
return 0 ;
}
static int F_150 ( struct V_10 * V_11 ,
struct V_266 * V_267 , T_3 * V_69 )
{
int V_3 , V_223 ;
if ( ( V_223 = F_143 ( V_11 , V_272 , 0 ) ) != 0 )
return V_223 ;
for( V_3 = V_267 -> V_271 ; V_3 < ( V_267 -> V_271 + V_267 -> V_91 ) ; V_3 ++ ) {
if ( ( V_223 = F_143 ( V_11 , V_273 , V_3 ) ) != 0 )
return V_223 ;
if ( ( V_223 = F_147 ( V_11 , * V_69 ) ) != 0 )
return V_223 ;
if ( ( V_223 = F_143 ( V_11 , V_274 , V_3 ) ) != 0 )
return V_223 ;
}
return 0 ;
}
static int F_151 ( struct V_10 * V_11 )
{
return V_269 ;
}
static int F_152 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_15 = 20 ;
unsigned long V_275 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
V_275 = F_153 () ;
F_12 ( V_13 , V_185 ) ;
do {
int V_276 ;
F_9 ( 10 ) ;
V_276 = F_97 ( V_13 ) ;
if ( V_276 & V_185 )
break;
} while ( -- V_15 );
F_12 ( V_13 , 0 ) ;
return F_154 ( V_275 ) ;
}
static int F_155 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_3 , V_277 ;
unsigned int V_278 , V_279 , V_58 ;
const char * V_280 ;
unsigned long V_281 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
V_278 = F_156 ( V_13 ) ;
F_6 ( V_122 , V_11 , L_60 ,
V_61 , V_278 ) ;
if ( V_278 != 0x87654321 ) {
F_157 ( V_11 , L_61 , V_278 ) ;
V_277 = - V_282 ;
goto V_283;
}
V_279 = F_158 ( V_13 ) ;
F_6 ( V_122 , V_11 , L_62 ,
V_61 , V_279 ) ;
for( V_3 = 0 ; V_284 [ V_3 ] . V_285 != 0 ; V_3 ++ ) {
if ( V_284 [ V_3 ] . V_285 == V_279 ) break;
}
if ( ! V_284 [ V_3 ] . V_285 ) {
F_157 ( V_11 , L_63 , V_279 ) ;
V_277 = - V_282 ;
goto V_283;
}
V_280 = V_284 [ V_3 ] . V_286 ;
V_58 = F_159 ( V_13 ) ;
F_6 ( V_122 , V_11 , L_64 , V_61 , V_58 ) ;
F_6 ( V_122 , V_11 , L_65 ,
V_61 , V_284 [ V_3 ] . V_286 ) ;
if ( ( V_26 < 2 ) || ( V_26 > 14 ) ) {
F_157 ( V_11 , L_66 ,
V_26 ) ;
V_277 = - V_247 ;
goto V_283;
}
V_13 -> V_126 = V_284 [ V_3 ] . V_285 ;
V_13 -> V_58 = V_58 ;
V_13 -> V_26 = V_26 ;
V_13 -> V_287 = ( V_13 -> V_26 << 10 ) - 512 ;
V_13 -> V_288 = ( ( 0x4000 - 512 - V_13 -> V_287 ) / 16 ) * 15 ;
switch( V_13 -> V_26 ) {
case 2 :
V_13 -> V_29 = 0x008C46AF ; break;
case 3 :
V_13 -> V_29 = 0x0082419F ; break;
case 4 :
V_13 -> V_29 = 0x00783C9F ; break;
case 5 :
V_13 -> V_29 = 0x006E374F ; break;
case 6 :
V_13 -> V_29 = 0x0064328F ; break;
case 7 :
V_13 -> V_29 = 0x005A2D7F ; break;
case 8 :
V_13 -> V_29 = 0x0050287F ; break;
case 9 :
V_13 -> V_29 = 0x0046236F ; break;
case 10 :
V_13 -> V_29 = 0x003C1E6F ; break;
case 11 :
V_13 -> V_29 = 0x0032195F ; break;
case 12 :
V_13 -> V_29 = 0x0024124F ; break;
case 13 :
V_13 -> V_29 = 0x0015073F ; break;
case 14 :
V_13 -> V_29 = 0x0006032F ; break;
default:
F_10 ( V_11 , L_67 ) ;
break;
}
F_6 ( V_122 | V_92 | V_50 , V_11 ,
L_68 , V_61 ,
V_13 -> V_287 , V_13 -> V_288 , V_13 -> V_29 ) ;
F_160 ( & V_13 -> V_22 ) ;
F_161 ( V_13 , V_11 -> V_41 ) ;
F_4 ( V_11 ) ;
if ( V_11 -> V_178 < 1 ) {
int V_289 ;
V_289 = 3 ;
while ( V_289 -- ) {
V_11 -> V_178 = F_152 ( V_11 ) ;
if ( V_11 -> V_178 )
break;
F_4 ( V_11 ) ;
}
}
if ( V_11 -> V_178 == 0 ) {
F_64 ( V_11 , L_69 ) ;
V_277 = - V_282 ;
goto V_283;
}
V_11 -> V_178 = F_162 ( V_11 -> V_178 ) ;
F_163 ( V_11 ) ;
V_11 -> V_290 = & V_291 ;
V_11 -> V_292 = F_164 ( V_293 ) ;
V_11 -> V_294 = & V_295 ;
F_165 ( & V_13 -> V_152 , F_85 ) ;
V_13 -> V_137 . V_296 = 0x1f ;
V_13 -> V_137 . V_297 = 0x1f ;
V_13 -> V_137 . V_160 = 0 ;
V_13 -> V_137 . V_148 = 0 ;
V_13 -> V_137 . V_11 = V_11 ;
V_13 -> V_137 . V_298 = F_68 ;
V_13 -> V_137 . V_299 = F_70 ;
F_72 ( V_11 ) ;
V_13 -> V_253 = V_300 ;
V_13 -> V_111 = 1 ;
V_13 -> V_143 = 100 ;
#ifdef F_21
V_281 = V_13 -> V_32 . V_281 ;
#else
V_281 = V_301 | V_302 ;
#endif
V_277 = F_166 ( V_11 -> V_178 , F_95 ,
V_281 , V_11 -> V_286 , V_11 ) ;
if ( V_277 )
goto V_283;
#ifdef F_49
V_13 -> V_303 = F_167 ( V_11 , F_105 ) ;
V_13 -> V_304 = F_167 ( V_11 , F_102 ) ;
V_13 -> V_82 = 0 ;
V_13 -> V_104 = 0 ;
V_11 -> V_199 = V_13 -> V_303 ;
#endif
V_277 = F_168 ( V_11 ) ;
if ( V_277 == 0 ) {
F_87 ( V_11 , L_70 ,
V_280 , V_13 -> V_58 ,
V_11 -> V_305 , V_11 -> V_178 ) ;
#ifdef F_49
if ( V_13 -> V_303 != - 1 )
F_3 ( L_71 , V_13 -> V_303 ) ;
if ( V_13 -> V_304 != - 1 )
F_3 ( L_72 , V_13 -> V_304 ) ;
#endif
F_3 ( L_2 ) ;
if ( ! F_169 ( V_11 -> V_41 ) ) {
F_64 ( V_11 , L_73 ) ;
} else {
F_87 ( V_11 , L_74 ,
V_11 -> V_41 ) ;
}
if ( V_13 -> V_125 == 0 ) {
F_10 ( V_11 , L_75 ) ;
} else if ( ( V_13 -> V_125 & ~ 0xff ) == V_306 ) {
F_10 ( V_11 , L_76 ) ;
} else {
F_10 ( V_11 , L_77 , V_13 -> V_125 ) ;
}
}
V_283:
#ifdef F_49
if ( V_277 ) {
if ( V_13 -> V_303 != - 1 ) {
F_170 ( V_11 , V_13 -> V_303 ) ;
}
if ( V_13 -> V_304 != - 1 ) {
F_170 ( V_11 , V_13 -> V_304 ) ;
}
}
#endif
return V_277 ;
}
static int F_171 ( struct V_307 * V_308 )
{
struct V_10 * V_309 ;
struct V_310 * V_311 ;
struct V_12 * V_13 ;
void T_4 * V_220 ;
int V_223 ;
F_6 ( V_19 , L_3 , V_20 ) ;
V_311 = F_172 ( V_308 , V_312 , 0 ) ;
if ( ! V_311 ) {
V_223 = - V_282 ;
goto V_313;
}
if ( ! F_173 ( V_311 -> V_314 , V_315 , V_61 ) ) {
V_223 = - V_316 ;
goto V_313;
}
V_309 = F_174 ( sizeof( struct V_12 ) ) ;
if ( ! V_309 ) {
V_223 = - V_317 ;
goto V_318;
}
F_175 ( V_309 , & V_308 -> V_11 ) ;
V_309 -> V_199 = ( unsigned char ) - 1 ;
V_309 -> V_178 = F_176 ( V_308 , 0 ) ;
V_13 = F_5 ( V_309 ) ;
V_13 -> V_153 = V_309 ;
#ifdef F_21
{
struct V_319 * V_320 = F_177 ( & V_308 -> V_11 ) ;
if ( ! V_320 ) {
V_223 = - V_247 ;
goto V_321;
}
memcpy ( & V_13 -> V_32 , V_320 , sizeof( V_13 -> V_32 ) ) ;
}
#endif
V_220 = F_178 ( V_311 -> V_314 , V_315 ) ;
if ( ! V_220 ) {
V_223 = - V_317 ;
goto V_321;
}
F_179 ( V_308 , V_309 ) ;
V_13 -> V_322 = V_220 ;
V_309 -> V_305 = V_311 -> V_314 ;
V_223 = F_155 ( V_309 ) ;
if ( V_223 != 0 ) {
F_180 ( V_220 ) ;
V_321:
F_181 ( V_309 ) ;
V_318:
F_182 ( V_311 -> V_314 , V_315 ) ;
V_313:
F_183 ( L_78 , V_61 , V_223 ) ;
}
#ifdef F_49
else {
V_13 -> V_323 = V_311 -> V_314 ;
V_13 -> V_11 = & V_308 -> V_11 ;
}
#endif
return V_223 ;
}
static int F_184 ( struct V_307 * V_308 )
{
struct V_10 * V_309 = F_185 ( V_308 ) ;
struct V_12 * V_13 = F_5 ( V_309 ) ;
struct V_310 * V_311 ;
F_6 ( V_19 , V_309 , L_3 , V_20 ) ;
F_186 ( V_309 ) ;
F_187 ( V_309 -> V_178 , V_309 ) ;
#ifdef F_49
{
if ( V_13 -> V_303 != - 1 ) {
F_170 ( V_11 , V_13 -> V_303 ) ;
}
if ( V_13 -> V_304 != - 1 ) {
F_170 ( V_11 , V_13 -> V_304 ) ;
}
}
#endif
F_180 ( V_13 -> V_322 ) ;
V_311 = F_172 ( V_308 , V_312 , 0 ) ;
F_182 ( V_311 -> V_314 , V_315 ) ;
F_181 ( V_309 ) ;
return 0 ;
}
static int F_188 ( struct V_307 * V_11 , T_5 V_324 )
{
struct V_10 * V_309 = F_185 ( V_11 ) ;
struct V_12 * V_13 = F_5 ( V_309 ) ;
F_6 ( V_19 , V_309 , L_3 , V_20 ) ;
if ( V_309 ) {
if ( F_189 ( V_309 ) ) {
F_190 ( V_309 ) ;
F_37 ( V_309 ) ;
#if V_325
F_79 ( V_13 , 2 << 12 ) ;
#endif
}
}
return 0 ;
}
static int F_191 ( struct V_307 * V_11 )
{
struct V_10 * V_309 = F_185 ( V_11 ) ;
F_6 ( V_19 , V_309 , L_3 , V_20 ) ;
if ( V_309 ) {
struct V_12 * V_13 = F_5 ( V_309 ) ;
if ( F_189 ( V_309 ) ) {
F_4 ( V_309 ) ;
if ( V_13 -> V_125 != 0 )
F_85 ( & V_13 -> V_152 ) ;
F_24 ( V_309 ) ;
F_192 ( V_309 ) ;
}
}
return 0 ;
}

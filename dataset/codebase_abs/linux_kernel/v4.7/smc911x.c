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
F_59 ( V_11 ) ;
F_60 ( V_68 ) ;
#endif
if ( ! V_13 -> V_97 ) {
F_61 ( V_11 ) ;
}
F_36 ( V_13 , V_51 | V_52 ) ;
}
static int F_62 ( struct V_67 * V_68 , struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int free ;
unsigned long V_18 ;
F_6 ( V_19 | V_92 , V_11 , L_3 ,
V_20 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
F_56 ( V_13 -> V_35 != NULL ) ;
free = F_63 ( V_13 ) & V_98 ;
F_6 ( V_92 , V_11 , L_17 , free ) ;
if ( free <= V_99 ) {
F_6 ( V_92 , V_11 , L_18 ,
free ) ;
F_26 ( V_13 , ( V_99 ) / 64 ) ;
V_13 -> V_97 = 1 ;
F_64 ( V_11 ) ;
}
if ( F_46 ( free < ( V_68 -> V_91 + 8 + 15 + 15 ) ) ) {
F_65 ( V_11 , L_19 ,
free , V_68 -> V_91 ) ;
V_13 -> V_35 = NULL ;
V_11 -> V_36 . V_37 ++ ;
V_11 -> V_36 . V_100 ++ ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
F_66 ( V_68 ) ;
return V_101 ;
}
#ifdef F_49
{
if ( V_13 -> V_102 ) {
F_6 ( V_92 | V_103 , V_11 , L_20 ) ;
V_13 -> V_35 = V_68 ;
F_64 ( V_11 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
return V_101 ;
} else {
F_6 ( V_92 | V_103 , V_11 , L_21 ) ;
V_13 -> V_102 = 1 ;
}
}
#endif
V_13 -> V_35 = V_68 ;
F_55 ( V_11 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
return V_101 ;
}
static void F_67 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_104 ;
F_6 ( V_19 | V_92 , V_11 , L_3 ,
V_20 ) ;
while ( ( ( F_63 ( V_13 ) & V_105 ) >> 16 ) != 0 ) {
F_6 ( V_92 , V_11 , L_22 ,
( F_63 ( V_13 ) & V_105 ) >> 16 ) ;
V_104 = F_68 ( V_13 ) ;
V_11 -> V_36 . V_106 ++ ;
V_11 -> V_36 . V_107 += V_104 >> 16 ;
F_6 ( V_92 , V_11 , L_23 ,
( V_104 & 0xffff0000 ) >> 16 ,
V_104 & 0x0000ffff ) ;
if ( ( V_104 & V_108 ) && ! ( V_13 -> V_109 &&
! ( V_104 & 0x00000306 ) ) ) {
V_11 -> V_36 . V_37 ++ ;
}
if ( V_104 & V_110 ) {
V_11 -> V_36 . V_111 += 16 ;
V_11 -> V_36 . V_38 ++ ;
} else {
V_11 -> V_36 . V_111 += ( V_104 & V_112 ) >> 3 ;
}
if ( ( V_104 & ( V_113 | V_114 ) ) &&
! V_13 -> V_109 ) {
V_11 -> V_36 . V_115 ++ ;
}
if ( V_104 & V_116 ) {
V_11 -> V_36 . V_111 ++ ;
V_11 -> V_36 . V_38 ++ ;
}
}
}
static int F_69 ( struct V_10 * V_11 , int V_117 , int V_118 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_119 ;
F_70 ( V_13 , V_118 , V_117 , V_119 ) ;
F_6 ( V_120 , V_11 , L_24 ,
V_20 , V_117 , V_118 , V_119 ) ;
return V_119 ;
}
static void F_71 ( struct V_10 * V_11 , int V_117 , int V_118 ,
int V_119 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_6 ( V_120 , V_11 , L_25 ,
V_20 , V_117 , V_118 , V_119 ) ;
F_72 ( V_13 , V_118 , V_117 , V_119 ) ;
}
static void F_73 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_117 ;
unsigned int V_32 , V_121 , V_122 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
V_13 -> V_123 = 0 ;
switch( V_13 -> V_124 ) {
case V_125 :
case V_126 :
case V_127 :
case V_128 :
V_32 = F_15 ( V_13 ) ;
if ( V_32 & V_129 ) {
V_32 &= ~ V_130 ;
V_32 |= V_131 ;
F_14 ( V_13 , V_32 ) ;
F_9 ( 10 ) ;
V_32 |= V_132 ;
F_14 ( V_13 , V_32 ) ;
F_9 ( 10 ) ;
V_32 &= ~ V_130 ;
V_32 |= V_133 ;
F_14 ( V_13 , V_32 ) ;
F_9 ( 10 ) ;
V_32 |= V_134 ;
F_14 ( V_13 , V_32 ) ;
for ( V_117 = 1 ; V_117 < 32 ; ++ V_117 ) {
F_74 ( V_13 , V_117 & 31 , V_121 ) ;
F_75 ( V_13 , V_117 & 31 , V_122 ) ;
if ( V_121 != 0x0000 && V_121 != 0xffff &&
V_121 != 0x8000 && V_122 != 0x0000 &&
V_122 != 0xffff && V_122 != 0x8000 ) {
V_13 -> V_135 . V_136 = V_117 & 31 ;
V_13 -> V_123 = V_121 << 16 | V_122 ;
break;
}
}
if ( V_117 < 32 )
break;
}
default:
F_74 ( V_13 , 1 , V_121 ) ;
F_75 ( V_13 , 1 , V_122 ) ;
V_13 -> V_135 . V_136 = 1 ;
V_13 -> V_123 = V_121 << 16 | V_122 ;
}
F_6 ( V_120 , V_11 , L_26 ,
V_121 , V_122 , V_13 -> V_135 . V_136 ) ;
}
static int F_76 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_117 = V_13 -> V_135 . V_136 ;
int V_137 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_77 ( V_13 , V_117 , V_137 ) ;
V_137 |= V_138 ;
F_78 ( V_13 , V_117 , V_137 ) ;
V_137 &= ~ V_139 ;
if ( V_13 -> V_109 )
V_137 |= V_140 ;
if ( V_13 -> V_141 == 100 )
V_137 |= V_142 ;
F_78 ( V_13 , V_117 , V_137 ) ;
V_137 &= ~ V_138 ;
F_78 ( V_13 , V_117 , V_137 ) ;
return 1 ;
}
static int F_79 ( struct V_10 * V_11 , int V_143 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_15 ;
unsigned long V_18 ;
unsigned int V_14 ;
F_6 ( V_19 , V_11 , L_27 , V_20 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_14 = F_7 ( V_13 ) ;
V_14 &= ~ 0xfffff030 ;
V_14 |= V_144 ;
F_80 ( V_13 , V_14 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
for ( V_15 = 2 ; V_15 ; V_15 -- ) {
F_81 ( 50 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_14 = F_7 ( V_13 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
if ( ! ( V_14 & V_144 ) ) {
F_9 ( 500 ) ;
break;
}
}
return V_14 & V_144 ;
}
static void F_82 ( struct V_10 * V_11 , int V_143 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_137 ;
F_77 ( V_13 , V_143 , V_137 ) ;
V_137 |= V_138 ;
F_78 ( V_13 , V_143 , V_137 ) ;
}
static void F_83 ( struct V_10 * V_11 , int V_145 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_117 = V_13 -> V_135 . V_136 ;
unsigned int V_137 , V_40 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
if ( F_84 ( & V_13 -> V_135 , F_85 ( V_13 ) , V_145 ) ) {
F_77 ( V_13 , V_117 , V_137 ) ;
F_29 ( V_13 , V_40 ) ;
if ( V_13 -> V_135 . V_146 ) {
F_6 ( V_120 , V_11 , L_28 ) ;
V_137 |= V_140 ;
V_40 |= V_147 ;
} else {
F_6 ( V_120 , V_11 , L_29 ) ;
V_137 &= ~ V_140 ;
V_40 &= ~ V_147 ;
}
F_78 ( V_13 , V_117 , V_137 ) ;
F_30 ( V_13 , V_40 ) ;
}
}
static void F_86 ( struct V_148 * V_149 )
{
struct V_12 * V_13 = F_87 ( V_149 , struct V_12 ,
V_150 ) ;
struct V_10 * V_11 = V_13 -> V_151 ;
int V_117 = V_13 -> V_135 . V_136 ;
int V_152 ;
int V_153 ;
int V_66 ;
unsigned long V_18 ;
F_6 ( V_19 , V_11 , L_27 , V_20 ) ;
if ( V_13 -> V_123 == 0 )
return;
if ( F_79 ( V_11 , V_117 ) ) {
F_88 ( V_11 , L_30 ) ;
return;
}
F_11 ( & V_13 -> V_22 , V_18 ) ;
F_89 ( V_13 , V_117 , V_154 |
V_155 | V_156 |
V_157 ) ;
if ( V_13 -> V_135 . V_158 ) {
F_76 ( V_11 ) ;
goto V_159;
}
F_90 ( V_13 , V_117 , V_152 ) ;
if ( ! ( V_152 & V_160 ) ) {
F_88 ( V_11 , L_31 ) ;
F_76 ( V_11 ) ;
goto V_159;
}
V_153 = V_161 | V_162 | V_163 ;
if ( V_152 & V_164 )
V_153 |= V_165 ;
if ( V_152 & V_166 )
V_153 |= V_167 ;
if ( V_152 & V_168 )
V_153 |= V_169 ;
if ( V_152 & V_170 )
V_153 |= V_171 ;
if ( V_152 & V_172 )
V_153 |= V_173 ;
if ( V_13 -> V_141 != 100 )
V_153 &= ~ ( V_165 | V_167 | V_169 ) ;
if ( ! V_13 -> V_109 )
V_153 &= ~ ( V_167 | V_171 ) ;
F_91 ( V_13 , V_117 , V_153 ) ;
V_13 -> V_135 . V_174 = V_153 ;
F_9 ( 10 ) ;
F_92 ( V_13 , V_117 , V_66 ) ;
F_6 ( V_120 , V_11 , L_32 , V_152 ) ;
F_6 ( V_120 , V_11 , L_33 , V_153 ) ;
F_78 ( V_13 , V_117 , V_139 | V_175 ) ;
F_83 ( V_11 , 1 ) ;
V_159:
F_13 ( & V_13 -> V_22 , V_18 ) ;
}
static void F_93 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_117 = V_13 -> V_135 . V_136 ;
int V_66 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
if ( V_13 -> V_123 == 0 )
return;
F_83 ( V_11 , 0 ) ;
F_94 ( V_13 , V_117 , V_66 ) ;
F_6 ( V_120 , V_11 , L_34 ,
V_66 & 0xffff ) ;
F_6 ( V_120 , V_11 , L_35 ,
F_95 ( V_13 ) ) ;
}
static T_2 F_96 ( int V_176 , void * V_177 )
{
struct V_10 * V_11 = V_177 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_66 , V_39 , V_15 ;
unsigned int V_178 = 0 , V_40 , V_179 ;
unsigned long V_18 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
if ( ( F_97 ( V_13 ) & ( V_180 | V_30 ) ) !=
( V_180 | V_30 ) ) {
F_13 ( & V_13 -> V_22 , V_18 ) ;
return V_181 ;
}
V_39 = F_98 ( V_13 ) ;
F_12 ( V_13 , 0 ) ;
V_15 = 8 ;
do {
V_66 = F_99 ( V_13 ) ;
F_6 ( V_120 , V_11 , L_36 ,
V_66 , V_39 , V_66 & ~ V_39 ) ;
V_66 &= V_39 ;
if ( ! V_66 )
break;
if ( V_66 & V_182 ) {
F_17 ( V_13 , V_182 ) ;
V_39 &= ~ V_183 ;
}
if ( V_66 & V_184 ) {
F_17 ( V_13 , V_184 ) ;
V_11 -> V_36 . V_72 ++ ;
}
if ( V_66 & V_185 ) {
F_17 ( V_13 , V_185 ) ;
V_11 -> V_36 . V_79 += F_100 ( V_13 ) ;
}
if ( V_66 & V_186 ) {
F_17 ( V_13 , V_186 ) ;
}
if ( V_66 & V_187 ) {
if ( F_35 ( V_13 -> V_58 ) ) {
V_178 = 1 ;
F_29 ( V_13 , V_40 ) ;
V_40 &= ~ V_49 ;
F_30 ( V_13 , V_40 ) ;
F_6 ( V_50 , V_11 , L_37 ) ;
V_11 -> V_36 . V_72 ++ ;
V_11 -> V_36 . V_188 ++ ;
}
F_17 ( V_13 , V_187 ) ;
}
if ( V_66 & V_189 ) {
if ( ! F_35 ( V_13 -> V_58 ) ) {
F_29 ( V_13 , V_40 ) ;
V_40 &= ~ V_49 ;
F_30 ( V_13 , V_40 ) ;
V_178 = 1 ;
F_6 ( V_50 , V_11 , L_37 ) ;
V_11 -> V_36 . V_72 ++ ;
V_11 -> V_36 . V_188 ++ ;
}
F_17 ( V_13 , V_189 ) ;
}
if ( ( V_66 & V_190 ) || V_178 ) {
unsigned int V_80 ;
F_6 ( V_50 , V_11 , L_38 ) ;
V_80 = F_39 ( V_13 ) ;
V_179 = ( V_80 & V_191 ) >> 16 ;
F_6 ( V_50 , V_11 , L_39 ,
V_179 , V_80 & 0xFFFF ) ;
if ( V_179 != 0 ) {
#ifdef F_49
unsigned int V_80 ;
if ( V_13 -> V_82 ) {
F_6 ( V_50 | V_103 , V_11 ,
L_40 ) ;
V_80 = F_50 ( V_13 ) & ~ 0xFF ;
V_80 |= V_179 & 0xFF ;
F_6 ( V_50 , V_11 ,
L_13 ,
V_80 & 0xff ) ;
F_51 ( V_13 , V_80 ) ;
} else
#endif
F_43 ( V_11 ) ;
}
F_17 ( V_13 , V_190 ) ;
}
if ( V_66 & V_192 ) {
F_6 ( V_92 , V_11 , L_41 ) ;
F_26 ( V_13 , 0xFF ) ;
V_13 -> V_97 = 0 ;
#ifdef F_49
if ( ! V_13 -> V_102 )
#endif
F_61 ( V_11 ) ;
F_17 ( V_13 , V_192 ) ;
}
#if 1
if ( V_66 & ( V_193 | V_194 ) ) {
F_6 ( V_92 | V_120 , V_11 ,
L_42 ,
( F_50 ( V_13 ) & 0x00ff0000 ) >> 16 ) ;
F_67 ( V_11 ) ;
F_28 ( V_13 , V_44 | 10000 ) ;
F_17 ( V_13 , V_193 ) ;
F_17 ( V_13 , V_193 | V_194 ) ;
}
#else
if ( V_66 & V_193 ) {
F_6 ( V_92 , V_11 , L_43 , ? ) ;
F_67 ( V_11 ) ;
F_17 ( V_13 , V_193 ) ;
}
if ( V_66 & V_194 ) {
F_6 ( V_50 , V_11 , L_44 ,
F_97 ( V_13 ) ,
F_50 ( V_13 ) ,
F_101 ( V_13 ) ) ;
F_6 ( V_50 , V_11 , L_45 ,
( F_39 ( V_13 ) & 0x00ff0000 ) >> 16 ,
F_39 ( V_13 ) & 0xffff ,
F_102 ( V_13 ) ) ;
F_28 ( V_13 , V_44 | 10000 ) ;
F_17 ( V_13 , V_194 ) ;
}
#endif
if ( V_66 & V_195 ) {
F_6 ( V_120 , V_11 , L_46 ) ;
F_93 ( V_11 ) ;
F_17 ( V_13 , V_195 ) ;
}
} while ( -- V_15 );
F_12 ( V_13 , V_39 ) ;
F_6 ( V_120 , V_11 , L_47 ,
8 - V_15 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
return V_196 ;
}
static void
F_103 ( void * V_69 )
{
struct V_12 * V_13 = V_69 ;
struct V_10 * V_11 = V_13 -> V_151 ;
struct V_67 * V_68 = V_13 -> V_96 ;
unsigned long V_18 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_6 ( V_92 | V_103 , V_11 , L_48 ) ;
F_56 ( V_68 == NULL ) ;
F_104 ( NULL , V_197 , V_198 , V_199 ) ;
F_59 ( V_11 ) ;
F_60 ( V_68 ) ;
V_13 -> V_96 = NULL ;
if ( V_13 -> V_35 != NULL )
F_55 ( V_11 ) ;
else {
F_6 ( V_92 | V_103 , V_11 ,
L_49 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_13 -> V_102 = 0 ;
if ( ! V_13 -> V_97 ) {
F_61 ( V_11 ) ;
}
F_13 ( & V_13 -> V_22 , V_18 ) ;
}
F_6 ( V_92 | V_103 , V_11 ,
L_50 ) ;
}
static void
F_105 ( void * V_69 )
{
struct V_12 * V_13 = V_69 ;
struct V_10 * V_11 = V_13 -> V_151 ;
struct V_67 * V_68 = V_13 -> V_83 ;
unsigned long V_18 ;
unsigned int V_179 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_6 ( V_50 | V_103 , V_11 , L_51 ) ;
F_104 ( NULL , V_200 , V_201 , V_202 ) ;
F_56 ( V_68 == NULL ) ;
V_13 -> V_83 = NULL ;
F_1 ( V_68 -> V_69 , V_68 -> V_91 ) ;
V_68 -> V_86 = F_53 ( V_68 , V_11 ) ;
V_11 -> V_36 . V_87 ++ ;
V_11 -> V_36 . V_88 += V_68 -> V_91 ;
F_54 ( V_68 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_179 = ( F_39 ( V_13 ) & V_191 ) >> 16 ;
if ( V_179 != 0 ) {
F_43 ( V_11 ) ;
} else {
V_13 -> V_82 = 0 ;
}
F_13 ( & V_13 -> V_22 , V_18 ) ;
F_6 ( V_50 | V_103 , V_11 ,
L_52 ,
V_179 ) ;
}
static void F_106 ( struct V_10 * V_11 )
{
F_107 ( V_11 -> V_176 ) ;
F_96 ( V_11 -> V_176 , V_11 ) ;
F_108 ( V_11 -> V_176 ) ;
}
static void F_109 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_66 , V_39 ;
unsigned long V_18 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_66 = F_99 ( V_13 ) ;
V_39 = F_98 ( V_13 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
F_6 ( V_120 , V_11 , L_53 ,
V_66 , V_39 ) ;
V_39 = F_110 ( V_13 ) ;
F_31 ( V_13 , V_39 | V_203 | V_204 ) ;
if ( V_13 -> V_123 != 0 )
F_111 ( & V_13 -> V_150 ) ;
F_59 ( V_11 ) ;
F_61 ( V_11 ) ;
}
static void F_112 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_205 [ 2 ] ;
unsigned int V_206 , V_207 = 0 ;
unsigned long V_18 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_11 ( & V_13 -> V_22 , V_18 ) ;
F_29 ( V_13 , V_206 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
if ( V_11 -> V_18 & V_208 ) {
F_6 ( V_120 , V_11 , L_54 ) ;
V_206 |= V_209 ;
}
else if ( V_11 -> V_18 & V_210 || F_113 ( V_11 ) > 16 ) {
F_6 ( V_120 , V_11 , L_55 ) ;
V_206 |= V_211 ;
}
else if ( ! F_114 ( V_11 ) ) {
struct V_212 * V_213 ;
V_206 |= V_214 ;
memset ( V_205 , 0 , sizeof( V_205 ) ) ;
F_115 (ha, dev) {
V_93 V_215 ;
V_215 = F_116 ( V_216 , V_213 -> V_217 ) >> 26 ;
V_205 [ V_215 >> 5 ] |= 1 << ( V_215 & 0x1f ) ;
}
V_206 &= ~ ( V_209 | V_211 ) ;
V_207 = 1 ;
} else {
F_6 ( V_120 , V_11 , L_56 ) ;
V_206 &= ~ ( V_209 | V_211 ) ;
memset ( V_205 , 0 , sizeof( V_205 ) ) ;
V_207 = 1 ;
}
F_11 ( & V_13 -> V_22 , V_18 ) ;
F_30 ( V_13 , V_206 ) ;
if ( V_207 ) {
F_6 ( V_120 , V_11 ,
L_57 ,
V_205 [ 0 ] , V_205 [ 1 ] ) ;
F_117 ( V_13 , V_205 [ 0 ] ) ;
F_118 ( V_13 , V_205 [ 1 ] ) ;
}
F_13 ( & V_13 -> V_22 , V_18 ) ;
}
static int
F_119 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_4 ( V_11 ) ;
F_86 ( & V_13 -> V_150 ) ;
F_24 ( V_11 ) ;
F_120 ( V_11 ) ;
return 0 ;
}
static int F_121 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
F_64 ( V_11 ) ;
F_122 ( V_11 ) ;
F_37 ( V_11 ) ;
if ( V_13 -> V_123 != 0 ) {
F_123 ( & V_13 -> V_150 ) ;
F_82 ( V_11 , V_13 -> V_135 . V_136 ) ;
}
if ( V_13 -> V_35 ) {
F_23 ( V_13 -> V_35 ) ;
V_13 -> V_35 = NULL ;
}
return 0 ;
}
static int
F_124 ( struct V_10 * V_11 , struct V_218 * V_219 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_220 , V_66 ;
unsigned long V_18 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
V_219 -> V_221 = 1 ;
V_219 -> V_222 = 1 ;
if ( V_13 -> V_123 != 0 ) {
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_220 = F_125 ( & V_13 -> V_135 , V_219 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
} else {
V_219 -> V_223 = V_224 |
V_225 |
V_226 | V_227 ;
if ( V_13 -> V_141 == 10 )
F_126 ( V_219 , V_228 ) ;
else if ( V_13 -> V_141 == 100 )
F_126 ( V_219 , V_229 ) ;
V_219 -> V_230 = V_231 ;
if ( V_13 -> V_135 . V_136 == 1 )
V_219 -> V_232 = V_233 ;
else
V_219 -> V_232 = V_234 ;
V_219 -> V_235 = 0 ;
F_127 ( V_13 , V_13 -> V_135 . V_136 , V_66 ) ;
V_219 -> V_236 =
( V_66 & ( V_237 | V_238 ) ) ?
V_239 : V_240 ;
V_220 = 0 ;
}
return V_220 ;
}
static int
F_128 ( struct V_10 * V_11 , struct V_218 * V_219 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_220 ;
unsigned long V_18 ;
if ( V_13 -> V_123 != 0 ) {
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_220 = F_129 ( & V_13 -> V_135 , V_219 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
} else {
if ( V_219 -> V_230 != V_231 ||
V_219 -> V_241 != V_228 ||
( V_219 -> V_236 != V_240 && V_219 -> V_236 != V_239 ) ||
( V_219 -> V_235 != V_242 && V_219 -> V_235 != V_243 ) )
return - V_244 ;
V_13 -> V_109 = V_219 -> V_236 == V_239 ;
V_220 = 0 ;
}
return V_220 ;
}
static void
F_130 ( struct V_10 * V_11 , struct V_245 * V_246 )
{
F_131 ( V_246 -> V_247 , V_61 , sizeof( V_246 -> V_247 ) ) ;
F_131 ( V_246 -> V_124 , V_124 , sizeof( V_246 -> V_124 ) ) ;
F_131 ( V_246 -> V_248 , F_132 ( V_11 -> V_11 . V_249 ) ,
sizeof( V_246 -> V_248 ) ) ;
}
static int F_133 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_220 = - V_244 ;
unsigned long V_18 ;
if ( V_13 -> V_123 != 0 ) {
F_11 ( & V_13 -> V_22 , V_18 ) ;
V_220 = F_134 ( & V_13 -> V_135 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
}
return V_220 ;
}
static V_93 F_135 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
return V_13 -> V_250 ;
}
static void F_136 ( struct V_10 * V_11 , V_93 V_251 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
V_13 -> V_250 = V_251 ;
}
static int F_137 ( struct V_10 * V_11 )
{
return ( ( ( V_252 - V_253 ) / 4 + 1 ) +
( V_254 - V_255 ) + 1 + 32 ) * sizeof( V_93 ) ;
}
static void F_138 ( struct V_10 * V_11 ,
struct V_256 * V_257 , void * V_1 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned long V_18 ;
V_93 V_14 , V_3 , V_258 = 0 ;
V_93 * V_69 = ( V_93 * ) V_1 ;
V_257 -> V_124 = V_13 -> V_124 ;
for( V_3 = V_253 ; V_3 <= V_252 ; V_3 += 4 ) {
V_69 [ V_258 ++ ] = F_139 ( V_13 , V_3 ) ;
}
for( V_3 = V_255 ; V_3 <= V_254 ; V_3 ++ ) {
F_11 ( & V_13 -> V_22 , V_18 ) ;
F_140 ( V_13 , V_3 , V_14 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
V_69 [ V_258 ++ ] = V_14 ;
}
for( V_3 = 0 ; V_3 <= 31 ; V_3 ++ ) {
F_11 ( & V_13 -> V_22 , V_18 ) ;
F_70 ( V_13 , V_3 , V_13 -> V_135 . V_136 , V_14 ) ;
F_13 ( & V_13 -> V_22 , V_18 ) ;
V_69 [ V_258 ++ ] = V_14 & 0xFFFF ;
}
}
static int F_141 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_15 ;
int V_259 ;
V_259 = F_16 ( V_13 ) ;
for( V_15 = 10 ; ( V_259 & V_25 ) && V_15 ; V_15 -- ) {
if ( V_259 & V_260 ) {
F_10 ( V_11 , L_58 ,
V_20 ) ;
return - V_261 ;
}
F_142 ( 1 ) ;
V_259 = F_16 ( V_13 ) ;
}
if ( V_15 == 0 ) {
F_10 ( V_11 , L_59 ,
V_20 ) ;
return - V_262 ;
}
return 0 ;
}
static inline int F_143 ( struct V_10 * V_11 ,
int V_219 , int V_217 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_220 ;
if ( ( V_220 = F_141 ( V_11 ) ) != 0 )
return V_220 ;
F_144 ( V_13 , V_25 |
( ( V_219 ) & ( 0x7 << 28 ) ) |
( ( V_217 ) & 0xFF ) ) ;
return 0 ;
}
static inline int F_145 ( struct V_10 * V_11 ,
T_3 * V_69 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_220 ;
if ( ( V_220 = F_141 ( V_11 ) ) != 0 )
return V_220 ;
* V_69 = F_146 ( V_13 ) ;
return 0 ;
}
static inline int F_147 ( struct V_10 * V_11 ,
T_3 V_69 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_220 ;
if ( ( V_220 = F_141 ( V_11 ) ) != 0 )
return V_220 ;
F_148 ( V_13 , V_69 ) ;
return 0 ;
}
static int F_149 ( struct V_10 * V_11 ,
struct V_263 * V_264 , T_3 * V_69 )
{
T_3 V_265 [ V_266 ] ;
int V_3 , V_220 ;
for( V_3 = 0 ; V_3 < V_266 ; V_3 ++ ) {
if ( ( V_220 = F_143 ( V_11 , V_267 , V_3 ) ) != 0 )
return V_220 ;
if ( ( V_220 = F_145 ( V_11 , & V_265 [ V_3 ] ) ) != 0 )
return V_220 ;
}
memcpy ( V_69 , V_265 + V_264 -> V_268 , V_264 -> V_91 ) ;
return 0 ;
}
static int F_150 ( struct V_10 * V_11 ,
struct V_263 * V_264 , T_3 * V_69 )
{
int V_3 , V_220 ;
if ( ( V_220 = F_143 ( V_11 , V_269 , 0 ) ) != 0 )
return V_220 ;
for( V_3 = V_264 -> V_268 ; V_3 < ( V_264 -> V_268 + V_264 -> V_91 ) ; V_3 ++ ) {
if ( ( V_220 = F_143 ( V_11 , V_270 , V_3 ) ) != 0 )
return V_220 ;
if ( ( V_220 = F_147 ( V_11 , * V_69 ) ) != 0 )
return V_220 ;
if ( ( V_220 = F_143 ( V_11 , V_271 , V_3 ) ) != 0 )
return V_220 ;
}
return 0 ;
}
static int F_151 ( struct V_10 * V_11 )
{
return V_266 ;
}
static int F_152 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_15 = 20 ;
unsigned long V_272 ;
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
V_272 = F_153 () ;
F_12 ( V_13 , V_183 ) ;
do {
int V_273 ;
F_9 ( 10 ) ;
V_273 = F_98 ( V_13 ) ;
if ( V_273 & V_183 )
break;
} while ( -- V_15 );
F_12 ( V_13 , 0 ) ;
return F_154 ( V_272 ) ;
}
static int F_155 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_3 , V_274 ;
unsigned int V_275 , V_276 , V_58 ;
const char * V_277 ;
unsigned long V_278 ;
#ifdef F_49
struct V_279 V_280 ;
T_4 V_39 ;
struct V_281 V_282 ;
#endif
F_6 ( V_19 , V_11 , L_3 , V_20 ) ;
V_275 = F_156 ( V_13 ) ;
F_6 ( V_120 , V_11 , L_60 ,
V_61 , V_275 ) ;
if ( V_275 != 0x87654321 ) {
F_157 ( V_11 , L_61 , V_275 ) ;
V_274 = - V_283 ;
goto V_284;
}
V_276 = F_158 ( V_13 ) ;
F_6 ( V_120 , V_11 , L_62 ,
V_61 , V_276 ) ;
for( V_3 = 0 ; V_285 [ V_3 ] . V_286 != 0 ; V_3 ++ ) {
if ( V_285 [ V_3 ] . V_286 == V_276 ) break;
}
if ( ! V_285 [ V_3 ] . V_286 ) {
F_157 ( V_11 , L_63 , V_276 ) ;
V_274 = - V_283 ;
goto V_284;
}
V_277 = V_285 [ V_3 ] . V_287 ;
V_58 = F_159 ( V_13 ) ;
F_6 ( V_120 , V_11 , L_64 , V_61 , V_58 ) ;
F_6 ( V_120 , V_11 , L_65 ,
V_61 , V_285 [ V_3 ] . V_287 ) ;
if ( ( V_26 < 2 ) || ( V_26 > 14 ) ) {
F_157 ( V_11 , L_66 ,
V_26 ) ;
V_274 = - V_244 ;
goto V_284;
}
V_13 -> V_124 = V_285 [ V_3 ] . V_286 ;
V_13 -> V_58 = V_58 ;
V_13 -> V_26 = V_26 ;
V_13 -> V_288 = ( V_13 -> V_26 << 10 ) - 512 ;
V_13 -> V_289 = ( ( 0x4000 - 512 - V_13 -> V_288 ) / 16 ) * 15 ;
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
F_6 ( V_120 | V_92 | V_50 , V_11 ,
L_68 , V_61 ,
V_13 -> V_288 , V_13 -> V_289 , V_13 -> V_29 ) ;
F_160 ( & V_13 -> V_22 ) ;
F_161 ( V_13 , V_11 -> V_41 ) ;
F_4 ( V_11 ) ;
if ( V_11 -> V_176 < 1 ) {
int V_290 ;
V_290 = 3 ;
while ( V_290 -- ) {
V_11 -> V_176 = F_152 ( V_11 ) ;
if ( V_11 -> V_176 )
break;
F_4 ( V_11 ) ;
}
}
if ( V_11 -> V_176 == 0 ) {
F_65 ( V_11 , L_69 ) ;
V_274 = - V_283 ;
goto V_284;
}
V_11 -> V_176 = F_162 ( V_11 -> V_176 ) ;
V_11 -> V_291 = & V_292 ;
V_11 -> V_293 = F_163 ( V_294 ) ;
V_11 -> V_295 = & V_296 ;
F_164 ( & V_13 -> V_150 , F_86 ) ;
V_13 -> V_135 . V_297 = 0x1f ;
V_13 -> V_135 . V_298 = 0x1f ;
V_13 -> V_135 . V_158 = 0 ;
V_13 -> V_135 . V_146 = 0 ;
V_13 -> V_135 . V_11 = V_11 ;
V_13 -> V_135 . V_299 = F_69 ;
V_13 -> V_135 . V_300 = F_71 ;
F_73 ( V_11 ) ;
V_13 -> V_250 = V_301 ;
V_13 -> V_109 = 1 ;
V_13 -> V_141 = 100 ;
#ifdef F_21
V_278 = V_13 -> V_32 . V_278 ;
#else
V_278 = V_302 | V_303 ;
#endif
V_274 = F_165 ( V_11 -> V_176 , F_96 ,
V_278 , V_11 -> V_287 , V_11 ) ;
if ( V_274 )
goto V_284;
#ifdef F_49
F_166 ( V_39 ) ;
F_167 ( V_304 , V_39 ) ;
V_282 . V_305 = V_306 ;
V_282 . V_307 = - 1UL ;
V_13 -> V_308 =
F_168 ( V_39 , V_309 ,
& V_282 , & V_11 -> V_11 , L_70 ) ;
V_13 -> V_310 =
F_168 ( V_39 , V_309 ,
& V_282 , & V_11 -> V_11 , L_71 ) ;
V_13 -> V_82 = 0 ;
V_13 -> V_102 = 0 ;
memset ( & V_280 , 0 , sizeof( V_280 ) ) ;
V_280 . V_311 = V_312 ;
V_280 . V_313 = V_312 ;
V_280 . V_314 = V_13 -> V_315 + V_316 ;
V_280 . V_317 = V_13 -> V_315 + V_318 ;
V_280 . V_319 = 32 ;
V_280 . V_320 = 32 ;
V_274 = F_169 ( V_13 -> V_308 , & V_280 ) ;
if ( V_274 ) {
F_170 ( V_13 -> V_11 , L_72 ,
V_274 ) ;
goto V_284;
}
V_274 = F_169 ( V_13 -> V_310 , & V_280 ) ;
if ( V_274 ) {
F_170 ( V_13 -> V_11 , L_73 ,
V_274 ) ;
goto V_284;
}
#endif
V_274 = F_171 ( V_11 ) ;
if ( V_274 == 0 ) {
F_88 ( V_11 , L_74 ,
V_277 , V_13 -> V_58 ,
V_11 -> V_321 , V_11 -> V_176 ) ;
#ifdef F_49
if ( V_13 -> V_308 )
F_3 ( L_75 , V_13 -> V_308 ) ;
if ( V_13 -> V_310 )
F_3 ( L_76 , V_13 -> V_310 ) ;
#endif
F_3 ( L_2 ) ;
if ( ! F_172 ( V_11 -> V_41 ) ) {
F_65 ( V_11 , L_77 ) ;
} else {
F_88 ( V_11 , L_78 ,
V_11 -> V_41 ) ;
}
if ( V_13 -> V_123 == 0 ) {
F_10 ( V_11 , L_79 ) ;
} else if ( ( V_13 -> V_123 & ~ 0xff ) == V_322 ) {
F_10 ( V_11 , L_80 ) ;
} else {
F_10 ( V_11 , L_81 , V_13 -> V_123 ) ;
}
}
V_284:
#ifdef F_49
if ( V_274 ) {
if ( V_13 -> V_308 )
F_173 ( V_13 -> V_308 ) ;
if ( V_13 -> V_310 )
F_173 ( V_13 -> V_310 ) ;
}
#endif
return V_274 ;
}
static int F_174 ( struct V_323 * V_324 )
{
struct V_10 * V_325 ;
struct V_326 * V_327 ;
struct V_12 * V_13 ;
void T_5 * V_217 ;
int V_220 ;
F_6 ( V_19 , L_3 , V_20 ) ;
V_327 = F_175 ( V_324 , V_328 , 0 ) ;
if ( ! V_327 ) {
V_220 = - V_283 ;
goto V_329;
}
if ( ! F_176 ( V_327 -> V_330 , V_331 , V_61 ) ) {
V_220 = - V_332 ;
goto V_329;
}
V_325 = F_177 ( sizeof( struct V_12 ) ) ;
if ( ! V_325 ) {
V_220 = - V_333 ;
goto V_334;
}
F_178 ( V_325 , & V_324 -> V_11 ) ;
V_325 -> V_335 = ( unsigned char ) - 1 ;
V_325 -> V_176 = F_179 ( V_324 , 0 ) ;
V_13 = F_5 ( V_325 ) ;
V_13 -> V_151 = V_325 ;
#ifdef F_21
{
struct V_336 * V_337 = F_180 ( & V_324 -> V_11 ) ;
if ( ! V_337 ) {
V_220 = - V_244 ;
goto V_338;
}
memcpy ( & V_13 -> V_32 , V_337 , sizeof( V_13 -> V_32 ) ) ;
}
#endif
V_217 = F_181 ( V_327 -> V_330 , V_331 ) ;
if ( ! V_217 ) {
V_220 = - V_333 ;
goto V_338;
}
F_182 ( V_324 , V_325 ) ;
V_13 -> V_339 = V_217 ;
V_325 -> V_321 = V_327 -> V_330 ;
V_220 = F_155 ( V_325 ) ;
if ( V_220 != 0 ) {
F_183 ( V_217 ) ;
V_338:
F_184 ( V_325 ) ;
V_334:
F_185 ( V_327 -> V_330 , V_331 ) ;
V_329:
F_186 ( L_82 , V_61 , V_220 ) ;
}
#ifdef F_49
else {
V_13 -> V_315 = V_327 -> V_330 ;
V_13 -> V_11 = & V_324 -> V_11 ;
}
#endif
return V_220 ;
}
static int F_187 ( struct V_323 * V_324 )
{
struct V_10 * V_325 = F_188 ( V_324 ) ;
struct V_12 * V_13 = F_5 ( V_325 ) ;
struct V_326 * V_327 ;
F_6 ( V_19 , V_325 , L_3 , V_20 ) ;
F_189 ( V_325 ) ;
F_190 ( V_325 -> V_176 , V_325 ) ;
#ifdef F_49
{
if ( V_13 -> V_308 )
F_173 ( V_13 -> V_308 ) ;
if ( V_13 -> V_310 )
F_173 ( V_13 -> V_310 ) ;
}
#endif
F_183 ( V_13 -> V_339 ) ;
V_327 = F_175 ( V_324 , V_328 , 0 ) ;
F_185 ( V_327 -> V_330 , V_331 ) ;
F_184 ( V_325 ) ;
return 0 ;
}
static int F_191 ( struct V_323 * V_11 , T_6 V_340 )
{
struct V_10 * V_325 = F_188 ( V_11 ) ;
struct V_12 * V_13 = F_5 ( V_325 ) ;
F_6 ( V_19 , V_325 , L_3 , V_20 ) ;
if ( V_325 ) {
if ( F_192 ( V_325 ) ) {
F_193 ( V_325 ) ;
F_37 ( V_325 ) ;
#if V_341
F_80 ( V_13 , 2 << 12 ) ;
#endif
}
}
return 0 ;
}
static int F_194 ( struct V_323 * V_11 )
{
struct V_10 * V_325 = F_188 ( V_11 ) ;
F_6 ( V_19 , V_325 , L_3 , V_20 ) ;
if ( V_325 ) {
struct V_12 * V_13 = F_5 ( V_325 ) ;
if ( F_192 ( V_325 ) ) {
F_4 ( V_325 ) ;
if ( V_13 -> V_123 != 0 )
F_86 ( & V_13 -> V_150 ) ;
F_24 ( V_325 ) ;
F_195 ( V_325 ) ;
}
}
return 0 ;
}

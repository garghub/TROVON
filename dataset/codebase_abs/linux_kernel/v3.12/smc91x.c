static void F_1 ( T_1 * V_1 , int V_2 )
{
int V_3 ;
int V_4 ;
int V_5 ;
V_5 = V_2 / 16 ;
V_4 = V_2 % 16 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
int V_6 ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) {
T_1 V_7 , V_8 ;
V_7 = * V_1 ++ ;
V_8 = * V_1 ++ ;
F_2 ( L_1 , V_7 , V_8 ) ;
}
F_2 ( L_2 ) ;
}
for ( V_3 = 0 ; V_3 < V_4 / 2 ; V_3 ++ ) {
T_1 V_7 , V_8 ;
V_7 = * V_1 ++ ;
V_8 = * V_1 ++ ;
F_2 ( L_1 , V_7 , V_8 ) ;
}
F_2 ( L_2 ) ;
}
static void F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
unsigned int V_15 , V_16 ;
struct V_17 * V_18 ;
F_5 ( 2 , L_3 , V_10 -> V_19 , V_20 ) ;
F_6 ( & V_12 -> V_21 ) ;
F_7 ( V_12 , 2 ) ;
F_8 ( V_12 , 0 ) ;
V_18 = V_12 -> V_22 ;
V_12 -> V_22 = NULL ;
F_9 ( & V_12 -> V_21 ) ;
if ( V_18 ) {
F_10 ( V_18 ) ;
V_10 -> V_23 . V_24 ++ ;
V_10 -> V_23 . V_25 ++ ;
}
F_7 ( V_12 , 0 ) ;
F_11 ( V_12 , V_26 ) ;
F_7 ( V_12 , 1 ) ;
V_16 = V_27 ;
if ( V_12 -> V_16 . V_28 & V_29 )
V_16 |= V_30 ;
V_16 |= V_31 ;
F_12 ( V_12 , V_16 ) ;
F_13 ( 1 ) ;
F_7 ( V_12 , 0 ) ;
F_11 ( V_12 , V_32 ) ;
F_14 ( V_12 , V_33 ) ;
F_7 ( V_12 , 1 ) ;
V_15 = F_15 ( V_12 ) | V_34 ;
if( ! V_35 )
V_15 |= V_36 ;
else
V_15 &= ~ V_36 ;
F_16 ( V_12 , V_15 ) ;
F_7 ( V_12 , 2 ) ;
F_17 ( V_12 , V_37 ) ;
F_18 ( V_12 ) ;
}
static void F_19 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
int V_38 ;
F_5 ( 2 , L_3 , V_10 -> V_19 , V_20 ) ;
F_7 ( V_12 , 0 ) ;
F_14 ( V_12 , V_12 -> V_39 ) ;
F_11 ( V_12 , V_12 -> V_40 ) ;
F_7 ( V_12 , 1 ) ;
F_20 ( V_12 , V_10 -> V_41 ) ;
V_38 = V_42 | V_43 | V_44 ;
if ( V_12 -> V_45 >= ( V_46 << 4 ) )
V_38 |= V_47 ;
F_7 ( V_12 , 2 ) ;
F_8 ( V_12 , V_38 ) ;
}
static void F_21 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
struct V_17 * V_18 ;
F_5 ( 2 , L_3 , V_48 , V_20 ) ;
F_6 ( & V_12 -> V_21 ) ;
F_7 ( V_12 , 2 ) ;
F_8 ( V_12 , 0 ) ;
V_18 = V_12 -> V_22 ;
V_12 -> V_22 = NULL ;
F_9 ( & V_12 -> V_21 ) ;
if ( V_18 )
F_10 ( V_18 ) ;
F_7 ( V_12 , 0 ) ;
F_11 ( V_12 , V_32 ) ;
F_14 ( V_12 , V_33 ) ;
#ifdef F_22
F_7 ( V_12 , 1 ) ;
F_12 ( V_12 , F_23 ( V_12 ) & ~ V_31 ) ;
#endif
}
static inline void F_24 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
unsigned int V_49 , V_50 , V_51 ;
F_5 ( 3 , L_3 , V_10 -> V_19 , V_20 ) ;
V_49 = F_25 ( V_12 ) ;
if ( F_26 ( V_49 & V_52 ) ) {
F_27 ( L_4 , V_10 -> V_19 ) ;
return;
}
F_28 ( V_12 , V_53 | V_54 | V_55 ) ;
F_29 ( V_12 , V_50 , V_51 ) ;
V_51 &= 0x07ff ;
F_5 ( 2 , L_5 ,
V_10 -> V_19 , V_49 , V_50 ,
V_51 , V_51 ) ;
V_56:
if ( F_26 ( V_51 < 6 || V_50 & V_57 ) ) {
if ( V_50 & V_58 && V_51 <= ( 1514 + 4 + 6 ) ) {
V_50 &= ~ V_58 ;
goto V_56;
}
if ( V_51 < 6 ) {
F_2 ( V_59 L_6 ,
V_10 -> V_19 , V_51 , V_50 ) ;
V_50 |= V_60 ;
}
F_18 ( V_12 ) ;
F_17 ( V_12 , V_61 ) ;
V_10 -> V_23 . V_62 ++ ;
if ( V_50 & V_63 )
V_10 -> V_23 . V_64 ++ ;
if ( V_50 & ( V_60 | V_58 ) )
V_10 -> V_23 . V_65 ++ ;
if ( V_50 & V_66 )
V_10 -> V_23 . V_67 ++ ;
} else {
struct V_17 * V_68 ;
unsigned char * V_69 ;
unsigned int V_70 ;
if ( V_50 & V_71 )
V_10 -> V_23 . V_72 ++ ;
V_68 = F_30 ( V_10 , V_51 ) ;
if ( F_26 ( V_68 == NULL ) ) {
F_18 ( V_12 ) ;
F_17 ( V_12 , V_61 ) ;
V_10 -> V_23 . V_73 ++ ;
return;
}
F_31 ( V_68 , 2 ) ;
if ( V_12 -> V_45 == 0x90 )
V_50 |= V_74 ;
V_70 = V_51 - ( ( V_50 & V_74 ) ? 5 : 6 ) ;
V_69 = F_32 ( V_68 , V_70 ) ;
F_33 ( V_12 , V_69 , V_51 - 4 ) ;
F_18 ( V_12 ) ;
F_17 ( V_12 , V_61 ) ;
F_1 ( V_69 , V_51 - 4 ) ;
V_68 -> V_75 = F_34 ( V_68 , V_10 ) ;
F_35 ( V_68 ) ;
V_10 -> V_23 . V_76 ++ ;
V_10 -> V_23 . V_77 += V_70 ;
}
}
static void F_36 ( unsigned long V_69 )
{
struct V_9 * V_10 = (struct V_9 * ) V_69 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
struct V_17 * V_68 ;
unsigned int V_78 , V_79 ;
unsigned char * V_1 ;
unsigned long V_28 ;
F_5 ( 3 , L_3 , V_10 -> V_19 , V_20 ) ;
if ( ! F_37 ( & V_12 -> V_21 , V_28 ) ) {
F_38 ( V_10 ) ;
F_39 ( & V_12 -> V_80 ) ;
return;
}
V_68 = V_12 -> V_22 ;
if ( F_26 ( ! V_68 ) ) {
F_40 ( & V_12 -> V_21 , V_28 ) ;
return;
}
V_12 -> V_22 = NULL ;
V_78 = F_41 ( V_12 ) ;
if ( F_26 ( V_78 & V_81 ) ) {
F_2 ( L_7 , V_10 -> V_19 ) ;
V_10 -> V_23 . V_24 ++ ;
V_10 -> V_23 . V_82 ++ ;
F_40 ( & V_12 -> V_21 , V_28 ) ;
goto V_83;
}
F_42 ( V_12 , V_78 ) ;
F_28 ( V_12 , V_55 ) ;
V_1 = V_68 -> V_69 ;
V_79 = V_68 -> V_79 ;
F_5 ( 2 , L_8 ,
V_10 -> V_19 , V_78 , V_79 , V_79 , V_1 ) ;
F_1 ( V_1 , V_79 ) ;
F_43 ( V_12 , 0 , V_79 + 6 ) ;
F_44 ( V_12 , V_1 , V_79 & ~ 1 ) ;
F_45 ( ( ( V_79 & 1 ) ? ( 0x2000 | V_1 [ V_79 - 1 ] ) : 0 ) , V_13 , F_46 ( V_12 ) ) ;
if ( V_35 )
F_38 ( V_10 ) ;
F_17 ( V_12 , V_84 ) ;
F_40 ( & V_12 -> V_21 , V_28 ) ;
V_10 -> V_85 = V_86 ;
V_10 -> V_23 . V_87 ++ ;
V_10 -> V_23 . V_88 += V_79 ;
F_47 ( V_12 , V_89 | V_90 ) ;
V_83: if ( ! V_35 )
F_48 ( V_10 ) ;
F_10 ( V_68 ) ;
}
static int F_49 ( struct V_17 * V_68 , struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
unsigned int V_91 , V_92 , V_50 ;
unsigned long V_28 ;
F_5 ( 3 , L_3 , V_10 -> V_19 , V_20 ) ;
F_50 ( V_12 -> V_22 != NULL ) ;
V_91 = ( ( V_68 -> V_79 & ~ 1 ) + ( 6 - 1 ) ) >> 8 ;
if ( F_26 ( V_91 > 7 ) ) {
F_2 ( L_9 , V_10 -> V_19 ) ;
V_10 -> V_23 . V_24 ++ ;
V_10 -> V_23 . V_93 ++ ;
F_10 ( V_68 ) ;
return V_94 ;
}
F_51 ( & V_12 -> V_21 , V_28 ) ;
F_17 ( V_12 , V_95 | V_91 ) ;
V_92 = V_96 ;
do {
V_50 = F_52 ( V_12 ) ;
if ( V_50 & V_97 ) {
F_53 ( V_12 , V_97 ) ;
break;
}
} while ( -- V_92 );
F_40 ( & V_12 -> V_21 , V_28 ) ;
V_12 -> V_22 = V_68 ;
if ( ! V_92 ) {
F_38 ( V_10 ) ;
F_5 ( 2 , L_10 , V_10 -> V_19 ) ;
F_47 ( V_12 , V_97 ) ;
} else {
F_36 ( ( unsigned long ) V_10 ) ;
}
return V_94 ;
}
static void F_54 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
unsigned int V_98 , V_78 , V_99 , V_100 ;
F_5 ( 3 , L_3 , V_10 -> V_19 , V_20 ) ;
V_78 = F_55 ( V_12 ) ;
if ( F_26 ( V_78 & V_101 ) ) {
F_27 ( L_11 , V_10 -> V_19 ) ;
return;
}
V_98 = F_56 ( V_12 ) ;
F_42 ( V_12 , V_78 ) ;
F_28 ( V_12 , V_55 | V_53 ) ;
F_29 ( V_12 , V_99 , V_100 ) ;
F_5 ( 2 , L_12 ,
V_10 -> V_19 , V_99 , V_78 ) ;
if ( ! ( V_99 & V_102 ) )
V_10 -> V_23 . V_24 ++ ;
if ( V_99 & V_103 )
V_10 -> V_23 . V_104 ++ ;
if ( V_99 & ( V_105 | V_106 ) ) {
F_27 ( L_13 , V_10 -> V_19 ,
( V_99 & V_105 ) ?
L_14 : L_15 ) ;
V_10 -> V_23 . V_107 ++ ;
if ( ! ( V_10 -> V_23 . V_107 & 63 ) && F_57 () ) {
F_2 ( V_108 L_16
L_17
L_18 , V_10 -> V_19 ) ;
}
}
F_18 ( V_12 ) ;
F_17 ( V_12 , V_109 ) ;
F_18 ( V_12 ) ;
F_42 ( V_12 , V_98 ) ;
F_7 ( V_12 , 0 ) ;
F_14 ( V_12 , V_12 -> V_39 ) ;
F_7 ( V_12 , 2 ) ;
}
static void F_58 ( struct V_9 * V_10 , unsigned int V_110 , int V_111 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
unsigned int V_112 , V_38 ;
V_112 = F_59 ( V_12 ) & ~ ( V_113 | V_114 | V_115 ) ;
V_112 |= V_114 ;
for ( V_38 = 1 << ( V_111 - 1 ) ; V_38 ; V_38 >>= 1 ) {
if ( V_110 & V_38 )
V_112 |= V_115 ;
else
V_112 &= ~ V_115 ;
F_60 ( V_12 , V_112 ) ;
F_13 ( V_116 ) ;
F_60 ( V_12 , V_112 | V_113 ) ;
F_13 ( V_116 ) ;
}
}
static unsigned int F_61 ( struct V_9 * V_10 , int V_111 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
unsigned int V_112 , V_38 , V_110 ;
V_112 = F_59 ( V_12 ) & ~ ( V_113 | V_114 | V_115 ) ;
F_60 ( V_12 , V_112 ) ;
for ( V_38 = 1 << ( V_111 - 1 ) , V_110 = 0 ; V_38 ; V_38 >>= 1 ) {
if ( F_59 ( V_12 ) & V_117 )
V_110 |= V_38 ;
F_60 ( V_12 , V_112 ) ;
F_13 ( V_116 ) ;
F_60 ( V_12 , V_112 | V_113 ) ;
F_13 ( V_116 ) ;
}
return V_110 ;
}
static int F_62 ( struct V_9 * V_10 , int V_118 , int V_119 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
unsigned int V_120 ;
F_7 ( V_12 , 3 ) ;
F_58 ( V_10 , 0xffffffff , 32 ) ;
F_58 ( V_10 , 6 << 10 | V_118 << 5 | V_119 , 14 ) ;
V_120 = F_61 ( V_10 , 18 ) ;
F_60 ( V_12 , F_59 ( V_12 ) & ~ ( V_113 | V_114 | V_115 ) ) ;
F_5 ( 3 , L_19 ,
V_20 , V_118 , V_119 , V_120 ) ;
F_7 ( V_12 , 2 ) ;
return V_120 ;
}
static void F_63 ( struct V_9 * V_10 , int V_118 , int V_119 ,
int V_120 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
F_7 ( V_12 , 3 ) ;
F_58 ( V_10 , 0xffffffff , 32 ) ;
F_58 ( V_10 , 5 << 28 | V_118 << 23 | V_119 << 18 | 2 << 16 | V_120 , 32 ) ;
F_60 ( V_12 , F_59 ( V_12 ) & ~ ( V_113 | V_114 | V_115 ) ) ;
F_5 ( 3 , L_19 ,
V_20 , V_118 , V_119 , V_120 ) ;
F_7 ( V_12 , 2 ) ;
}
static void F_64 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
int V_118 ;
F_5 ( 2 , L_3 , V_10 -> V_19 , V_20 ) ;
V_12 -> V_121 = 0 ;
for ( V_118 = 1 ; V_118 < 33 ; ++ V_118 ) {
unsigned int V_122 , V_123 ;
V_122 = F_62 ( V_10 , V_118 & 31 , V_124 ) ;
V_123 = F_62 ( V_10 , V_118 & 31 , V_125 ) ;
F_5 ( 3 , L_20 ,
V_10 -> V_19 , V_122 , V_123 ) ;
if ( V_122 != 0x0000 && V_122 != 0xffff && V_122 != 0x8000 &&
V_123 != 0x0000 && V_123 != 0xffff && V_123 != 0x8000 ) {
V_12 -> V_126 . V_127 = V_118 & 31 ;
V_12 -> V_121 = V_122 << 16 | V_123 ;
break;
}
}
}
static int F_65 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
int V_118 = V_12 -> V_126 . V_127 ;
int V_128 , V_129 ;
F_5 ( 3 , L_3 , V_10 -> V_19 , V_20 ) ;
V_129 = F_62 ( V_10 , V_118 , V_130 ) ;
V_129 |= V_131 ;
F_63 ( V_10 , V_118 , V_130 , V_129 ) ;
V_128 = 0 ;
if ( V_12 -> V_132 )
V_128 |= V_133 ;
if ( V_12 -> V_134 == 100 )
V_128 |= V_135 ;
F_63 ( V_10 , V_118 , V_136 , V_128 ) ;
F_7 ( V_12 , 0 ) ;
F_66 ( V_12 , V_12 -> V_137 ) ;
F_7 ( V_12 , 2 ) ;
return 1 ;
}
static int F_67 ( struct V_9 * V_10 , int V_138 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
unsigned int V_128 ;
int V_139 ;
F_63 ( V_10 , V_138 , V_136 , V_140 ) ;
for ( V_139 = 2 ; V_139 ; V_139 -- ) {
F_9 ( & V_12 -> V_21 ) ;
F_68 ( 50 ) ;
F_6 ( & V_12 -> V_21 ) ;
V_128 = F_62 ( V_10 , V_138 , V_136 ) ;
if ( ! ( V_128 & V_140 ) )
break;
}
return V_128 & V_140 ;
}
static void F_69 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
unsigned int V_128 ;
int V_138 = V_12 -> V_126 . V_127 ;
if ( V_12 -> V_121 == 0 )
return;
F_70 ( & V_12 -> V_141 ) ;
V_128 = F_62 ( V_10 , V_138 , V_136 ) ;
F_63 ( V_10 , V_138 , V_136 , V_128 | V_142 ) ;
}
static void F_71 ( struct V_9 * V_10 , int V_143 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
if ( F_72 ( & V_12 -> V_126 , F_73 ( V_12 ) , V_143 ) ) {
if ( V_12 -> V_126 . V_144 ) {
V_12 -> V_39 |= V_145 ;
} else {
V_12 -> V_39 &= ~ V_145 ;
}
F_7 ( V_12 , 0 ) ;
F_14 ( V_12 , V_12 -> V_39 ) ;
}
}
static void F_74 ( struct V_146 * V_147 )
{
struct V_11 * V_12 =
F_75 ( V_147 , struct V_11 , V_141 ) ;
struct V_9 * V_10 = V_12 -> V_10 ;
void T_2 * V_13 = V_12 -> V_14 ;
int V_118 = V_12 -> V_126 . V_127 ;
int V_148 ;
int V_149 ;
int V_50 ;
F_5 ( 3 , L_21 , V_10 -> V_19 ) ;
F_6 ( & V_12 -> V_21 ) ;
if ( V_12 -> V_121 == 0 )
goto V_150;
if ( F_67 ( V_10 , V_118 ) ) {
F_2 ( L_22 , V_10 -> V_19 ) ;
goto V_150;
}
F_63 ( V_10 , V_118 , V_151 ,
V_152 | V_153 | V_154 |
V_155 | V_156 | V_157 |
V_158 | V_159 ) ;
F_7 ( V_12 , 0 ) ;
F_66 ( V_12 , V_12 -> V_137 ) ;
if ( V_12 -> V_126 . V_160 ) {
F_65 ( V_10 ) ;
goto V_150;
}
V_148 = F_62 ( V_10 , V_118 , V_161 ) ;
if ( ! ( V_148 & V_162 ) ) {
F_2 ( V_108 L_23 ) ;
F_65 ( V_10 ) ;
goto V_150;
}
V_149 = V_163 ;
if ( V_148 & V_164 )
V_149 |= V_165 ;
if ( V_148 & V_166 )
V_149 |= V_167 ;
if ( V_148 & V_168 )
V_149 |= V_169 ;
if ( V_148 & V_170 )
V_149 |= V_171 ;
if ( V_148 & V_172 )
V_149 |= V_173 ;
if ( V_12 -> V_134 != 100 )
V_149 &= ~ ( V_165 | V_167 | V_169 ) ;
if ( ! V_12 -> V_132 )
V_149 &= ~ ( V_167 | V_171 ) ;
F_63 ( V_10 , V_118 , V_174 , V_149 ) ;
V_12 -> V_126 . V_175 = V_149 ;
V_50 = F_62 ( V_10 , V_118 , V_174 ) ;
F_5 ( 2 , L_24 , V_10 -> V_19 , V_148 ) ;
F_5 ( 2 , L_25 , V_10 -> V_19 , V_149 ) ;
F_63 ( V_10 , V_118 , V_136 , V_176 | V_177 ) ;
F_71 ( V_10 , 1 ) ;
V_150:
F_7 ( V_12 , 2 ) ;
F_9 ( & V_12 -> V_21 ) ;
}
static void F_76 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
int V_118 = V_12 -> V_126 . V_127 ;
int V_178 ;
F_5 ( 2 , L_3 , V_10 -> V_19 , V_20 ) ;
if ( V_12 -> V_121 == 0 )
return;
for(; ; ) {
F_71 ( V_10 , 0 ) ;
V_178 = F_62 ( V_10 , V_118 , V_179 ) ;
if ( ( V_178 & V_180 ) == 0 )
break;
}
}
static void F_77 ( struct V_9 * V_10 , int V_143 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
unsigned int V_181 , V_182 ;
V_181 = F_78 ( V_10 ) ? 1 : 0 ;
F_7 ( V_12 , 0 ) ;
V_182 = ( F_79 ( V_12 ) & V_183 ) ? 1 : 0 ;
F_7 ( V_12 , 2 ) ;
if ( V_143 || ( V_181 != V_182 ) ) {
if ( ! V_182 ) {
F_80 ( V_10 ) ;
} else {
F_81 ( V_10 ) ;
}
if ( F_73 ( V_12 ) )
F_2 ( V_108 L_26 , V_10 -> V_19 ,
V_182 ? L_27 : L_28 ) ;
}
}
static void F_82 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
unsigned int V_15 ;
F_77 ( V_10 , 0 ) ;
F_7 ( V_12 , 1 ) ;
V_15 = F_15 ( V_12 ) ;
F_16 ( V_12 , V_15 & ~ V_34 ) ;
F_16 ( V_12 , V_15 ) ;
F_7 ( V_12 , 2 ) ;
}
static T_3 F_83 ( int V_184 , void * V_185 )
{
struct V_9 * V_10 = V_185 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
int V_50 , V_38 , V_139 , V_186 ;
int V_187 ;
F_5 ( 3 , L_3 , V_10 -> V_19 , V_20 ) ;
F_84 ( & V_12 -> V_21 ) ;
V_188 ;
V_187 = F_85 ( V_12 ) ;
V_38 = F_86 ( V_12 ) ;
F_8 ( V_12 , 0 ) ;
V_139 = V_189 ;
do {
V_50 = F_52 ( V_12 ) ;
F_5 ( 2 , L_29 ,
dev->name, status, mask,
({ int meminfo; SMC_SELECT_BANK(lp, 0);
meminfo = SMC_GET_MIR(lp);
SMC_SELECT_BANK(lp, 2); meminfo; }),
SMC_GET_FIFO(lp)) ;
V_50 &= V_38 ;
if ( ! V_50 )
break;
if ( V_50 & V_89 ) {
F_5 ( 3 , L_30 , V_10 -> V_19 ) ;
F_54 ( V_10 ) ;
F_53 ( V_12 , V_89 ) ;
if ( V_35 )
F_48 ( V_10 ) ;
} else if ( V_50 & V_44 ) {
F_5 ( 3 , L_31 , V_10 -> V_19 ) ;
F_24 ( V_10 ) ;
} else if ( V_50 & V_97 ) {
F_5 ( 3 , L_32 , V_10 -> V_19 ) ;
F_87 ( & V_12 -> V_80 ) ;
V_38 &= ~ V_97 ;
} else if ( V_50 & V_90 ) {
F_5 ( 3 , L_33 , V_10 -> V_19 ) ;
V_38 &= ~ V_90 ;
F_7 ( V_12 , 0 ) ;
V_186 = F_88 ( V_12 ) ;
F_7 ( V_12 , 2 ) ;
V_10 -> V_23 . V_190 += V_186 & 0xF ;
V_186 >>= 4 ;
V_10 -> V_23 . V_190 += V_186 & 0xF ;
} else if ( V_50 & V_43 ) {
F_5 ( 1 , L_34 , dev->name,
({ int eph_st; SMC_SELECT_BANK(lp, 0);
eph_st = SMC_GET_EPH_STATUS(lp);
SMC_SELECT_BANK(lp, 2); eph_st; })) ;
F_53 ( V_12 , V_43 ) ;
V_10 -> V_23 . V_62 ++ ;
V_10 -> V_23 . V_191 ++ ;
} else if ( V_50 & V_42 ) {
F_82 ( V_10 ) ;
} else if ( V_50 & V_47 ) {
F_53 ( V_12 , V_47 ) ;
F_76 ( V_10 ) ;
} else if ( V_50 & V_192 ) {
F_53 ( V_12 , V_192 ) ;
F_27 ( L_35 , V_10 -> V_19 ) ;
}
} while ( -- V_139 );
F_28 ( V_12 , V_187 ) ;
F_8 ( V_12 , V_38 ) ;
F_89 ( & V_12 -> V_21 ) ;
#ifndef F_90
if ( V_139 == V_189 )
F_27 ( L_36 ,
V_10 -> V_19 , V_38 ) ;
#endif
F_5 ( 3 , L_37 ,
V_10 -> V_19 , V_189 - V_139 ) ;
return V_193 ;
}
static void F_91 ( struct V_9 * V_10 )
{
F_92 ( V_10 -> V_184 ) ;
F_83 ( V_10 -> V_184 , V_10 ) ;
F_93 ( V_10 -> V_184 ) ;
}
static void F_94 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
int V_50 , V_38 , V_194 , V_195 , V_196 ;
F_5 ( 2 , L_3 , V_10 -> V_19 , V_20 ) ;
F_6 ( & V_12 -> V_21 ) ;
V_50 = F_52 ( V_12 ) ;
V_38 = F_86 ( V_12 ) ;
V_196 = F_95 ( V_12 ) ;
F_7 ( V_12 , 0 ) ;
V_194 = F_79 ( V_12 ) ;
V_195 = F_96 ( V_12 ) ;
F_7 ( V_12 , 2 ) ;
F_9 ( & V_12 -> V_21 ) ;
F_27 ( L_38
L_39 ,
V_10 -> V_19 , V_50 , V_38 , V_195 , V_196 , V_194 ) ;
F_3 ( V_10 ) ;
F_19 ( V_10 ) ;
if ( V_12 -> V_121 != 0 )
F_97 ( & V_12 -> V_141 ) ;
V_10 -> V_85 = V_86 ;
F_48 ( V_10 ) ;
}
static void F_98 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
unsigned char V_197 [ 8 ] ;
int V_198 = 0 ;
F_5 ( 2 , L_3 , V_10 -> V_19 , V_20 ) ;
if ( V_10 -> V_28 & V_199 ) {
F_5 ( 2 , L_40 , V_10 -> V_19 ) ;
V_12 -> V_40 |= V_200 ;
}
else if ( V_10 -> V_28 & V_201 || F_99 ( V_10 ) > 16 ) {
F_5 ( 2 , L_41 , V_10 -> V_19 ) ;
V_12 -> V_40 |= V_202 ;
}
else if ( ! F_100 ( V_10 ) ) {
struct V_203 * V_204 ;
static const unsigned char V_205 [] = { 0 , 4 , 2 , 6 , 1 , 5 , 3 , 7 } ;
memset ( V_197 , 0 , sizeof( V_197 ) ) ;
F_101 (ha, dev) {
int V_206 ;
V_206 = F_102 ( ~ 0 , V_204 -> V_207 , 6 ) & 0x3f ;
V_197 [ V_205 [ V_206 & 7 ] ] |=
( 1 << V_205 [ ( V_206 >> 3 ) & 7 ] ) ;
}
V_12 -> V_40 &= ~ ( V_200 | V_202 ) ;
V_198 = 1 ;
} else {
F_5 ( 2 , L_42 , V_10 -> V_19 ) ;
V_12 -> V_40 &= ~ ( V_200 | V_202 ) ;
memset ( V_197 , 0 , sizeof( V_197 ) ) ;
V_198 = 1 ;
}
F_6 ( & V_12 -> V_21 ) ;
F_7 ( V_12 , 0 ) ;
F_11 ( V_12 , V_12 -> V_40 ) ;
if ( V_198 ) {
F_7 ( V_12 , 3 ) ;
F_103 ( V_12 , V_197 ) ;
}
F_7 ( V_12 , 2 ) ;
F_9 ( & V_12 -> V_21 ) ;
}
static int
F_104 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
F_5 ( 2 , L_3 , V_10 -> V_19 , V_20 ) ;
V_12 -> V_39 = V_208 ;
V_12 -> V_40 = V_209 ;
V_12 -> V_137 = V_210 |
V_12 -> V_16 . V_211 << V_212 |
V_12 -> V_16 . V_213 << V_214 ;
if ( V_12 -> V_121 == 0 )
V_12 -> V_39 |= V_215 ;
F_3 ( V_10 ) ;
F_19 ( V_10 ) ;
if ( V_12 -> V_121 != 0 )
F_74 ( & V_12 -> V_141 ) ;
else {
F_6 ( & V_12 -> V_21 ) ;
F_77 ( V_10 , 1 ) ;
F_9 ( & V_12 -> V_21 ) ;
}
F_105 ( V_10 ) ;
return 0 ;
}
static int F_106 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
F_5 ( 2 , L_3 , V_10 -> V_19 , V_20 ) ;
F_38 ( V_10 ) ;
F_80 ( V_10 ) ;
F_21 ( V_10 ) ;
F_107 ( & V_12 -> V_80 ) ;
F_69 ( V_10 ) ;
return 0 ;
}
static int
F_108 ( struct V_9 * V_10 , struct V_216 * V_217 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
int V_218 ;
V_217 -> V_219 = 1 ;
V_217 -> V_220 = 1 ;
if ( V_12 -> V_121 != 0 ) {
F_6 ( & V_12 -> V_21 ) ;
V_218 = F_109 ( & V_12 -> V_126 , V_217 ) ;
F_9 ( & V_12 -> V_21 ) ;
} else {
V_217 -> V_221 = V_222 |
V_223 |
V_224 | V_225 ;
if ( V_12 -> V_134 == 10 )
F_110 ( V_217 , V_226 ) ;
else if ( V_12 -> V_134 == 100 )
F_110 ( V_217 , V_227 ) ;
V_217 -> V_228 = V_229 ;
V_217 -> V_230 = V_231 ;
V_217 -> V_232 = 0 ;
V_217 -> V_233 = V_12 -> V_39 & V_145 ? V_234 : V_235 ;
V_218 = 0 ;
}
return V_218 ;
}
static int
F_111 ( struct V_9 * V_10 , struct V_216 * V_217 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
int V_218 ;
if ( V_12 -> V_121 != 0 ) {
F_6 ( & V_12 -> V_21 ) ;
V_218 = F_112 ( & V_12 -> V_126 , V_217 ) ;
F_9 ( & V_12 -> V_21 ) ;
} else {
if ( V_217 -> V_228 != V_229 ||
V_217 -> V_236 != V_226 ||
( V_217 -> V_233 != V_235 && V_217 -> V_233 != V_234 ) ||
( V_217 -> V_232 != V_237 && V_217 -> V_232 != V_238 ) )
return - V_239 ;
V_12 -> V_132 = V_217 -> V_233 == V_234 ;
V_218 = 0 ;
}
return V_218 ;
}
static void
F_113 ( struct V_9 * V_10 , struct V_240 * V_241 )
{
F_114 ( V_241 -> V_242 , V_48 , sizeof( V_241 -> V_242 ) ) ;
F_114 ( V_241 -> V_45 , V_45 , sizeof( V_241 -> V_45 ) ) ;
F_114 ( V_241 -> V_243 , F_115 ( V_10 -> V_10 . V_244 ) ,
sizeof( V_241 -> V_243 ) ) ;
}
static int F_116 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
int V_218 = - V_239 ;
if ( V_12 -> V_121 != 0 ) {
F_6 ( & V_12 -> V_21 ) ;
V_218 = F_117 ( & V_12 -> V_126 ) ;
F_9 ( & V_12 -> V_21 ) ;
}
return V_218 ;
}
static T_4 F_118 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
return V_12 -> V_245 ;
}
static void F_119 ( struct V_9 * V_10 , T_4 V_246 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
V_12 -> V_245 = V_246 ;
}
static int F_120 ( struct V_9 * V_10 , T_5 V_207 , T_5 V_247 )
{
T_5 V_15 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
F_6 ( & V_12 -> V_21 ) ;
F_7 ( V_12 , 1 ) ;
F_121 ( V_12 , V_247 ) ;
F_7 ( V_12 , 2 ) ;
F_28 ( V_12 , V_207 ) ;
F_7 ( V_12 , 1 ) ;
V_15 = F_15 ( V_12 ) ;
F_16 ( V_12 , V_15 | ( V_248 | V_249 ) ) ;
do {
F_13 ( 1 ) ;
} while ( F_15 ( V_12 ) & V_249 );
F_16 ( V_12 , V_15 ) ;
F_7 ( V_12 , 2 ) ;
F_9 ( & V_12 -> V_21 ) ;
return 0 ;
}
static int F_122 ( struct V_9 * V_10 , T_5 V_207 , T_5 * V_247 )
{
T_5 V_15 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
void T_2 * V_13 = V_12 -> V_14 ;
F_6 ( & V_12 -> V_21 ) ;
F_7 ( V_12 , 2 ) ;
F_28 ( V_12 , V_207 | V_53 ) ;
F_7 ( V_12 , 1 ) ;
F_121 ( V_12 , 0xffff ) ;
V_15 = F_15 ( V_12 ) ;
F_16 ( V_12 , V_15 | ( V_248 | V_250 ) ) ;
do {
F_13 ( 1 ) ;
} while ( F_15 ( V_12 ) & V_250 );
* V_247 = F_123 ( V_12 ) ;
F_16 ( V_12 , V_15 ) ;
F_7 ( V_12 , 2 ) ;
F_9 ( & V_12 -> V_21 ) ;
return 0 ;
}
static int F_124 ( struct V_9 * V_10 )
{
return 0x23 * 2 ;
}
static int F_125 ( struct V_9 * V_10 ,
struct V_251 * V_252 , T_6 * V_69 )
{
int V_3 ;
int V_253 ;
F_5 ( 1 , L_43 ,
V_252 -> V_79 , V_252 -> V_254 , V_252 -> V_254 ) ;
V_253 = F_124 ( V_10 ) ;
for ( V_3 = 0 ; V_3 < V_252 -> V_79 ; V_3 += 2 ) {
int V_218 ;
T_5 V_255 ;
int V_254 = V_3 + V_252 -> V_254 ;
if ( V_254 > V_253 )
break;
V_218 = F_122 ( V_10 , V_254 >> 1 , & V_255 ) ;
if ( V_218 != 0 )
return V_218 ;
F_5 ( 2 , L_44 , V_255 , V_254 >> 1 ) ;
V_69 [ V_3 ] = ( V_255 >> 8 ) & 0xff ;
V_69 [ V_3 + 1 ] = V_255 & 0xff ;
}
return 0 ;
}
static int F_126 ( struct V_9 * V_10 ,
struct V_251 * V_252 , T_6 * V_69 )
{
int V_3 ;
int V_253 ;
F_5 ( 1 , L_45 ,
V_252 -> V_79 , V_252 -> V_254 , V_252 -> V_254 ) ;
V_253 = F_124 ( V_10 ) ;
for ( V_3 = 0 ; V_3 < V_252 -> V_79 ; V_3 += 2 ) {
int V_218 ;
T_5 V_255 ;
int V_254 = V_3 + V_252 -> V_254 ;
if ( V_254 > V_253 )
break;
V_255 = ( V_69 [ V_3 ] << 8 ) | V_69 [ V_3 + 1 ] ;
F_5 ( 2 , L_46 , V_255 , V_254 >> 1 ) ;
V_218 = F_120 ( V_10 , V_254 >> 1 , V_255 ) ;
if ( V_218 != 0 )
return V_218 ;
}
return 0 ;
}
static int F_127 ( struct V_11 * V_12 )
{
void T_2 * V_13 = V_12 -> V_14 ;
int V_139 = 20 ;
unsigned long V_256 ;
F_5 ( 2 , L_3 , V_48 , V_20 ) ;
V_256 = F_128 () ;
F_7 ( V_12 , 2 ) ;
F_8 ( V_12 , V_97 ) ;
F_17 ( V_12 , V_95 | 1 ) ;
do {
int V_257 ;
F_13 ( 10 ) ;
V_257 = F_52 ( V_12 ) ;
if ( V_257 & V_97 )
break;
} while ( -- V_139 );
F_8 ( V_12 , 0 ) ;
return F_129 ( V_256 ) ;
}
static int F_130 ( struct V_9 * V_10 , void T_2 * V_13 ,
unsigned long V_258 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
static int V_259 = 0 ;
int V_260 ;
unsigned int V_110 , V_261 ;
const char * V_262 ;
F_5 ( 2 , L_3 , V_48 , V_20 ) ;
V_110 = F_131 ( V_12 ) ;
F_5 ( 2 , L_47 , V_48 , V_110 ) ;
if ( ( V_110 & 0xFF00 ) != 0x3300 ) {
if ( ( V_110 & 0xFF ) == 0x33 ) {
F_2 ( V_263
L_48
L_49 , V_48 , V_13 ) ;
}
V_260 = - V_264 ;
goto V_265;
}
F_7 ( V_12 , 0 ) ;
V_110 = F_131 ( V_12 ) ;
if ( ( V_110 & 0xFF00 ) != 0x3300 ) {
V_260 = - V_264 ;
goto V_265;
}
F_7 ( V_12 , 1 ) ;
V_110 = F_132 ( V_12 ) ;
V_110 = ( ( V_110 & 0x1F00 ) >> 3 ) << V_266 ;
if ( ( ( unsigned int ) V_13 & ( 0x3e0 << V_266 ) ) != V_110 ) {
F_2 ( L_50 ,
V_48 , V_13 , V_110 ) ;
}
F_7 ( V_12 , 3 ) ;
V_261 = F_133 ( V_12 ) ;
F_5 ( 2 , L_51 , V_48 , V_261 ) ;
V_262 = V_267 [ ( V_261 >> 4 ) & 0xF ] ;
if ( ! V_262 || ( V_261 & 0xff00 ) != 0x3300 ) {
F_2 ( L_52
L_53 , V_48 ,
V_13 , V_261 ) ;
V_260 = - V_264 ;
goto V_265;
}
if ( V_259 ++ == 0 )
F_2 ( L_54 , V_45 ) ;
V_10 -> V_268 = ( unsigned long ) V_13 ;
V_12 -> V_14 = V_13 ;
V_12 -> V_45 = V_261 & 0xff ;
F_134 ( & V_12 -> V_21 ) ;
F_7 ( V_12 , 1 ) ;
F_135 ( V_12 , V_10 -> V_41 ) ;
F_3 ( V_10 ) ;
if ( V_10 -> V_184 < 1 ) {
int V_269 ;
V_269 = 3 ;
while ( V_269 -- ) {
V_10 -> V_184 = F_127 ( V_12 ) ;
if ( V_10 -> V_184 )
break;
F_3 ( V_10 ) ;
}
}
if ( V_10 -> V_184 == 0 ) {
F_2 ( L_55 ,
V_10 -> V_19 ) ;
V_260 = - V_264 ;
goto V_265;
}
V_10 -> V_184 = F_136 ( V_10 -> V_184 ) ;
F_137 ( V_10 ) ;
V_10 -> V_270 = F_138 ( V_271 ) ;
V_10 -> V_272 = & V_273 ;
V_10 -> V_274 = & V_275 ;
F_139 ( & V_12 -> V_80 , F_36 , ( unsigned long ) V_10 ) ;
F_140 ( & V_12 -> V_141 , F_74 ) ;
V_12 -> V_10 = V_10 ;
V_12 -> V_126 . V_276 = 0x1f ;
V_12 -> V_126 . V_277 = 0x1f ;
V_12 -> V_126 . V_160 = 0 ;
V_12 -> V_126 . V_144 = 0 ;
V_12 -> V_126 . V_10 = V_10 ;
V_12 -> V_126 . V_278 = F_62 ;
V_12 -> V_126 . V_279 = F_63 ;
if ( V_12 -> V_45 >= ( V_46 << 4 ) )
F_64 ( V_10 ) ;
F_21 ( V_10 ) ;
F_69 ( V_10 ) ;
V_12 -> V_245 = V_280 ;
V_12 -> V_132 = 0 ;
V_12 -> V_134 = 10 ;
if ( V_12 -> V_45 >= ( V_46 << 4 ) ) {
V_12 -> V_132 = 1 ;
V_12 -> V_134 = 100 ;
}
V_260 = F_141 ( V_10 -> V_184 , F_83 , V_258 , V_10 -> V_19 , V_10 ) ;
if ( V_260 )
goto V_265;
#ifdef F_142
# ifdef F_143
V_12 -> V_16 . V_28 |= V_281 ;
# endif
if ( V_12 -> V_16 . V_28 & V_281 ) {
int V_282 = F_144 ( V_10 -> V_19 , V_283 ,
V_284 , NULL ) ;
if ( V_282 >= 0 )
V_10 -> V_282 = V_282 ;
}
#endif
V_260 = F_145 ( V_10 ) ;
if ( V_260 == 0 ) {
F_2 ( L_56 ,
V_10 -> V_19 , V_262 , V_261 & 0x0f ,
V_12 -> V_14 , V_10 -> V_184 ) ;
if ( V_10 -> V_282 != ( unsigned char ) - 1 )
F_2 ( L_57 , V_10 -> V_282 ) ;
F_2 ( L_58 ,
V_12 -> V_16 . V_28 & V_29 ? L_59 : L_60 ,
V_35 ? L_61 : L_60 ) ;
if ( ! F_146 ( V_10 -> V_41 ) ) {
F_2 ( L_62
L_63 , V_10 -> V_19 ) ;
} else {
F_2 ( L_64 ,
V_10 -> V_19 , V_10 -> V_41 ) ;
}
if ( V_12 -> V_121 == 0 ) {
F_27 ( L_65 , V_10 -> V_19 ) ;
} else if ( ( V_12 -> V_121 & 0xfffffff0 ) == 0x0016f840 ) {
F_27 ( L_66 , V_10 -> V_19 ) ;
} else if ( ( V_12 -> V_121 & 0xfffffff0 ) == 0x02821c50 ) {
F_27 ( L_67 , V_10 -> V_19 ) ;
}
}
V_265:
#ifdef F_142
if ( V_260 && V_10 -> V_282 != ( unsigned char ) - 1 )
F_147 ( V_10 -> V_282 ) ;
#endif
return V_260 ;
}
static int F_148 ( struct V_285 * V_286 )
{
struct V_9 * V_287 = F_149 ( V_286 ) ;
struct V_11 * V_12 = F_4 ( V_287 ) ;
unsigned long V_28 ;
unsigned char V_288 , V_289 ;
void T_2 * V_207 ;
struct V_290 * V_291 ;
V_291 = F_150 ( V_286 , V_292 , L_68 ) ;
if ( ! V_291 )
return 0 ;
V_207 = F_151 ( V_291 -> V_293 , V_294 ) ;
if ( ! V_207 )
return - V_295 ;
F_152 ( V_28 ) ;
V_288 = F_153 ( V_207 + ( V_296 << V_266 ) ) & ~ V_297 ;
F_154 ( V_288 | V_297 , V_207 + ( V_296 << V_266 ) ) ;
F_153 ( V_207 + ( V_296 << V_266 ) ) ;
F_13 ( 100 ) ;
F_154 ( V_288 , V_207 + ( V_296 << V_266 ) ) ;
F_154 ( V_288 | V_298 , V_207 + ( V_296 << V_266 ) ) ;
V_289 = F_153 ( V_207 + ( V_299 << V_266 ) ) & ~ V_300 ;
if ( ! F_155 ( V_12 ) )
V_289 |= V_300 ;
F_154 ( V_289 , V_207 + ( V_299 << V_266 ) ) ;
F_156 ( V_28 ) ;
F_157 ( V_207 ) ;
F_68 ( 1 ) ;
return 0 ;
}
static int F_158 ( struct V_285 * V_286 ,
struct V_9 * V_287 )
{
struct V_290 * V_291 = F_150 ( V_286 , V_292 , L_68 ) ;
struct V_11 * V_12 V_301 = F_4 ( V_287 ) ;
if ( ! V_291 )
return 0 ;
if ( ! F_159 ( V_291 -> V_293 , V_294 , V_48 ) )
return - V_302 ;
return 0 ;
}
static void F_160 ( struct V_285 * V_286 ,
struct V_9 * V_287 )
{
struct V_290 * V_291 = F_150 ( V_286 , V_292 , L_68 ) ;
struct V_11 * V_12 V_301 = F_4 ( V_287 ) ;
if ( V_291 )
F_161 ( V_291 -> V_293 , V_294 ) ;
}
static inline void F_162 ( struct V_285 * V_286 , struct V_9 * V_287 )
{
if ( V_303 ) {
struct V_290 * V_291 = F_150 ( V_286 , V_292 , L_69 ) ;
struct V_11 * V_12 = F_4 ( V_287 ) ;
if ( ! V_291 )
return;
if( ! F_159 ( V_291 -> V_293 , V_304 , V_48 ) ) {
F_2 ( V_108 L_70 , V_48 ) ;
return;
}
V_12 -> V_305 = F_151 ( V_291 -> V_293 , V_304 ) ;
}
}
static void F_163 ( struct V_285 * V_286 , struct V_9 * V_287 )
{
if ( V_303 ) {
struct V_11 * V_12 = F_4 ( V_287 ) ;
struct V_290 * V_291 = F_150 ( V_286 , V_292 , L_69 ) ;
if ( V_12 -> V_305 )
F_157 ( V_12 -> V_305 ) ;
V_12 -> V_305 = NULL ;
if ( V_291 )
F_161 ( V_291 -> V_293 , V_304 ) ;
}
}
static int F_164 ( struct V_285 * V_286 )
{
struct V_306 * V_307 = F_165 ( & V_286 -> V_10 ) ;
struct V_11 * V_12 ;
struct V_9 * V_287 ;
struct V_290 * V_291 , * V_308 ;
unsigned int T_2 * V_207 ;
unsigned long V_258 = V_309 ;
int V_218 ;
V_287 = F_166 ( sizeof( struct V_11 ) ) ;
if ( ! V_287 ) {
V_218 = - V_295 ;
goto V_310;
}
F_167 ( V_287 , & V_286 -> V_10 ) ;
V_12 = F_4 ( V_287 ) ;
if ( V_307 ) {
memcpy ( & V_12 -> V_16 , V_307 , sizeof( V_12 -> V_16 ) ) ;
V_12 -> V_311 = F_168 ( V_12 -> V_16 . V_28 ) ;
} else {
V_12 -> V_16 . V_28 |= ( V_312 ) ? V_313 : 0 ;
V_12 -> V_16 . V_28 |= ( V_314 ) ? V_315 : 0 ;
V_12 -> V_16 . V_28 |= ( V_316 ) ? V_317 : 0 ;
V_12 -> V_16 . V_28 |= ( V_318 ) ? V_29 : 0 ;
}
if ( ! V_12 -> V_16 . V_211 && ! V_12 -> V_16 . V_213 ) {
V_12 -> V_16 . V_211 = V_319 ;
V_12 -> V_16 . V_213 = V_320 ;
}
V_287 -> V_282 = ( unsigned char ) - 1 ;
V_291 = F_150 ( V_286 , V_292 , L_71 ) ;
if ( ! V_291 )
V_291 = F_169 ( V_286 , V_292 , 0 ) ;
if ( ! V_291 ) {
V_218 = - V_264 ;
goto V_321;
}
if ( ! F_159 ( V_291 -> V_293 , V_322 , V_48 ) ) {
V_218 = - V_302 ;
goto V_321;
}
V_308 = F_169 ( V_286 , V_323 , 0 ) ;
if ( ! V_308 ) {
V_218 = - V_264 ;
goto V_324;
}
V_287 -> V_184 = V_308 -> V_293 ;
if ( V_258 == - 1 || V_308 -> V_28 & V_325 )
V_258 = V_308 -> V_28 & V_325 ;
V_218 = F_158 ( V_286 , V_287 ) ;
if ( V_218 )
goto V_324;
#if F_170 ( V_326 )
F_171 ( V_327 ) ;
#endif
F_172 ( V_286 , V_287 ) ;
V_218 = F_148 ( V_286 ) ;
if ( V_218 )
goto V_328;
V_207 = F_151 ( V_291 -> V_293 , V_322 ) ;
if ( ! V_207 ) {
V_218 = - V_295 ;
goto V_328;
}
#ifdef F_142
{
struct V_11 * V_12 = F_4 ( V_287 ) ;
V_12 -> V_329 = & V_286 -> V_10 ;
V_12 -> V_330 = V_291 -> V_293 ;
}
#endif
V_218 = F_130 ( V_287 , V_207 , V_258 ) ;
if ( V_218 != 0 )
goto V_331;
F_162 ( V_286 , V_287 ) ;
return 0 ;
V_331:
F_157 ( V_207 ) ;
V_328:
F_160 ( V_286 , V_287 ) ;
V_324:
F_161 ( V_291 -> V_293 , V_322 ) ;
V_321:
F_173 ( V_287 ) ;
V_310:
F_2 ( L_72 , V_48 , V_218 ) ;
return V_218 ;
}
static int F_174 ( struct V_285 * V_286 )
{
struct V_9 * V_287 = F_149 ( V_286 ) ;
struct V_11 * V_12 = F_4 ( V_287 ) ;
struct V_290 * V_291 ;
F_175 ( V_287 ) ;
F_176 ( V_287 -> V_184 , V_287 ) ;
#ifdef F_142
if ( V_287 -> V_282 != ( unsigned char ) - 1 )
F_147 ( V_287 -> V_282 ) ;
#endif
F_157 ( V_12 -> V_14 ) ;
F_163 ( V_286 , V_287 ) ;
F_160 ( V_286 , V_287 ) ;
V_291 = F_150 ( V_286 , V_292 , L_71 ) ;
if ( ! V_291 )
V_291 = F_169 ( V_286 , V_292 , 0 ) ;
F_161 ( V_291 -> V_293 , V_322 ) ;
F_173 ( V_287 ) ;
return 0 ;
}
static int F_177 ( struct V_329 * V_10 )
{
struct V_285 * V_286 = F_178 ( V_10 ) ;
struct V_9 * V_287 = F_149 ( V_286 ) ;
if ( V_287 ) {
if ( F_179 ( V_287 ) ) {
F_180 ( V_287 ) ;
F_21 ( V_287 ) ;
F_69 ( V_287 ) ;
}
}
return 0 ;
}
static int F_181 ( struct V_329 * V_10 )
{
struct V_285 * V_286 = F_178 ( V_10 ) ;
struct V_9 * V_287 = F_149 ( V_286 ) ;
if ( V_287 ) {
struct V_11 * V_12 = F_4 ( V_287 ) ;
F_148 ( V_286 ) ;
if ( F_179 ( V_287 ) ) {
F_3 ( V_287 ) ;
F_19 ( V_287 ) ;
if ( V_12 -> V_121 != 0 )
F_74 ( & V_12 -> V_141 ) ;
F_182 ( V_287 ) ;
}
}
return 0 ;
}

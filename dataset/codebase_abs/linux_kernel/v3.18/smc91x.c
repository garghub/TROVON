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
static inline void F_1 ( T_1 * V_1 , int V_2 ) { }
static void F_4 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
unsigned int V_16 , V_17 ;
struct V_18 * V_19 ;
F_6 ( 2 , V_11 , L_3 , V_20 ) ;
F_7 ( & V_13 -> V_21 ) ;
F_8 ( V_13 , 2 ) ;
F_9 ( V_13 , 0 ) ;
V_19 = V_13 -> V_22 ;
V_13 -> V_22 = NULL ;
F_10 ( & V_13 -> V_21 ) ;
if ( V_19 ) {
F_11 ( V_19 ) ;
V_11 -> V_23 . V_24 ++ ;
V_11 -> V_23 . V_25 ++ ;
}
F_8 ( V_13 , 0 ) ;
F_12 ( V_13 , V_26 ) ;
F_8 ( V_13 , 1 ) ;
V_17 = V_27 ;
if ( V_13 -> V_17 . V_28 & V_29 )
V_17 |= V_30 ;
V_17 |= V_31 ;
F_13 ( V_13 , V_17 ) ;
F_14 ( 1 ) ;
F_8 ( V_13 , 0 ) ;
F_12 ( V_13 , V_32 ) ;
F_15 ( V_13 , V_33 ) ;
F_8 ( V_13 , 1 ) ;
V_16 = F_16 ( V_13 ) | V_34 ;
if( ! V_35 )
V_16 |= V_36 ;
else
V_16 &= ~ V_36 ;
F_17 ( V_13 , V_16 ) ;
F_8 ( V_13 , 2 ) ;
F_18 ( V_13 , V_37 ) ;
F_19 ( V_13 ) ;
}
static void F_20 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
int V_38 ;
F_6 ( 2 , V_11 , L_3 , V_20 ) ;
F_8 ( V_13 , 0 ) ;
F_15 ( V_13 , V_13 -> V_39 ) ;
F_12 ( V_13 , V_13 -> V_40 ) ;
F_8 ( V_13 , 1 ) ;
F_21 ( V_13 , V_11 -> V_41 ) ;
V_38 = V_42 | V_43 | V_44 ;
if ( V_13 -> V_45 >= ( V_46 << 4 ) )
V_38 |= V_47 ;
F_8 ( V_13 , 2 ) ;
F_9 ( V_13 , V_38 ) ;
}
static void F_22 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
struct V_18 * V_19 ;
F_6 ( 2 , V_11 , L_4 , V_48 , V_20 ) ;
F_7 ( & V_13 -> V_21 ) ;
F_8 ( V_13 , 2 ) ;
F_9 ( V_13 , 0 ) ;
V_19 = V_13 -> V_22 ;
V_13 -> V_22 = NULL ;
F_10 ( & V_13 -> V_21 ) ;
if ( V_19 )
F_11 ( V_19 ) ;
F_8 ( V_13 , 0 ) ;
F_12 ( V_13 , V_32 ) ;
F_15 ( V_13 , V_33 ) ;
#ifdef F_23
F_8 ( V_13 , 1 ) ;
F_13 ( V_13 , F_24 ( V_13 ) & ~ V_31 ) ;
#endif
}
static inline void F_25 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
unsigned int V_49 , V_50 , V_51 ;
F_6 ( 3 , V_11 , L_3 , V_20 ) ;
V_49 = F_26 ( V_13 ) ;
if ( F_27 ( V_49 & V_52 ) ) {
F_28 ( V_11 , L_5 ) ;
return;
}
F_29 ( V_13 , V_53 | V_54 | V_55 ) ;
F_30 ( V_13 , V_50 , V_51 ) ;
V_51 &= 0x07ff ;
F_6 ( 2 , V_11 , L_6 ,
V_49 , V_50 , V_51 , V_51 ) ;
V_56:
if ( F_27 ( V_51 < 6 || V_50 & V_57 ) ) {
if ( V_50 & V_58 && V_51 <= ( 1514 + 4 + 6 ) ) {
V_50 &= ~ V_58 ;
goto V_56;
}
if ( V_51 < 6 ) {
F_31 ( V_11 , L_7 ,
V_51 , V_50 ) ;
V_50 |= V_59 ;
}
F_19 ( V_13 ) ;
F_18 ( V_13 , V_60 ) ;
V_11 -> V_23 . V_61 ++ ;
if ( V_50 & V_62 )
V_11 -> V_23 . V_63 ++ ;
if ( V_50 & ( V_59 | V_58 ) )
V_11 -> V_23 . V_64 ++ ;
if ( V_50 & V_65 )
V_11 -> V_23 . V_66 ++ ;
} else {
struct V_18 * V_67 ;
unsigned char * V_68 ;
unsigned int V_69 ;
if ( V_50 & V_70 )
V_11 -> V_23 . V_71 ++ ;
V_67 = F_32 ( V_11 , V_51 ) ;
if ( F_27 ( V_67 == NULL ) ) {
F_19 ( V_13 ) ;
F_18 ( V_13 , V_60 ) ;
V_11 -> V_23 . V_72 ++ ;
return;
}
F_33 ( V_67 , 2 ) ;
if ( V_13 -> V_45 == 0x90 )
V_50 |= V_73 ;
V_69 = V_51 - ( ( V_50 & V_73 ) ? 5 : 6 ) ;
V_68 = F_34 ( V_67 , V_69 ) ;
F_35 ( V_13 , V_68 , V_51 - 4 ) ;
F_19 ( V_13 ) ;
F_18 ( V_13 , V_60 ) ;
F_1 ( V_68 , V_51 - 4 ) ;
V_67 -> V_74 = F_36 ( V_67 , V_11 ) ;
F_37 ( V_67 ) ;
V_11 -> V_23 . V_75 ++ ;
V_11 -> V_23 . V_76 += V_69 ;
}
}
static void F_38 ( unsigned long V_68 )
{
struct V_10 * V_11 = (struct V_10 * ) V_68 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
struct V_18 * V_67 ;
unsigned int V_77 , V_78 ;
unsigned char * V_1 ;
unsigned long V_28 ;
F_6 ( 3 , V_11 , L_3 , V_20 ) ;
if ( ! F_39 ( & V_13 -> V_21 , V_28 ) ) {
F_40 ( V_11 ) ;
F_41 ( & V_13 -> V_79 ) ;
return;
}
V_67 = V_13 -> V_22 ;
if ( F_27 ( ! V_67 ) ) {
F_42 ( & V_13 -> V_21 , V_28 ) ;
return;
}
V_13 -> V_22 = NULL ;
V_77 = F_43 ( V_13 ) ;
if ( F_27 ( V_77 & V_80 ) ) {
F_31 ( V_11 , L_8 ) ;
V_11 -> V_23 . V_24 ++ ;
V_11 -> V_23 . V_81 ++ ;
F_42 ( & V_13 -> V_21 , V_28 ) ;
goto V_82;
}
F_44 ( V_13 , V_77 ) ;
F_29 ( V_13 , V_55 ) ;
V_1 = V_67 -> V_68 ;
V_78 = V_67 -> V_78 ;
F_6 ( 2 , V_11 , L_9 ,
V_77 , V_78 , V_78 , V_1 ) ;
F_1 ( V_1 , V_78 ) ;
F_45 ( V_13 , 0 , V_78 + 6 ) ;
F_46 ( V_13 , V_1 , V_78 & ~ 1 ) ;
F_47 ( ( ( V_78 & 1 ) ? ( 0x2000 | V_1 [ V_78 - 1 ] ) : 0 ) , V_14 , F_48 ( V_13 ) ) ;
if ( V_35 )
F_40 ( V_11 ) ;
F_18 ( V_13 , V_83 ) ;
F_42 ( & V_13 -> V_21 , V_28 ) ;
V_11 -> V_84 = V_85 ;
V_11 -> V_23 . V_86 ++ ;
V_11 -> V_23 . V_87 += V_78 ;
F_49 ( V_13 , V_88 | V_89 ) ;
V_82: if ( ! V_35 )
F_50 ( V_11 ) ;
F_51 ( V_67 ) ;
}
static int F_52 ( struct V_18 * V_67 , struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
unsigned int V_90 , V_91 , V_50 ;
unsigned long V_28 ;
F_6 ( 3 , V_11 , L_3 , V_20 ) ;
F_53 ( V_13 -> V_22 != NULL ) ;
V_90 = ( ( V_67 -> V_78 & ~ 1 ) + ( 6 - 1 ) ) >> 8 ;
if ( F_27 ( V_90 > 7 ) ) {
F_54 ( V_11 , L_10 ) ;
V_11 -> V_23 . V_24 ++ ;
V_11 -> V_23 . V_92 ++ ;
F_55 ( V_67 ) ;
return V_93 ;
}
F_56 ( & V_13 -> V_21 , V_28 ) ;
F_18 ( V_13 , V_94 | V_90 ) ;
V_91 = V_95 ;
do {
V_50 = F_57 ( V_13 ) ;
if ( V_50 & V_96 ) {
F_58 ( V_13 , V_96 ) ;
break;
}
} while ( -- V_91 );
F_42 ( & V_13 -> V_21 , V_28 ) ;
V_13 -> V_22 = V_67 ;
if ( ! V_91 ) {
F_40 ( V_11 ) ;
F_6 ( 2 , V_11 , L_11 ) ;
F_49 ( V_13 , V_96 ) ;
} else {
F_38 ( ( unsigned long ) V_11 ) ;
}
return V_93 ;
}
static void F_59 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
unsigned int V_97 , V_77 , V_98 , V_99 ;
F_6 ( 3 , V_11 , L_3 , V_20 ) ;
V_77 = F_60 ( V_13 ) ;
if ( F_27 ( V_77 & V_100 ) ) {
F_28 ( V_11 , L_12 ) ;
return;
}
V_97 = F_61 ( V_13 ) ;
F_44 ( V_13 , V_77 ) ;
F_29 ( V_13 , V_55 | V_53 ) ;
F_30 ( V_13 , V_98 , V_99 ) ;
F_6 ( 2 , V_11 , L_13 ,
V_98 , V_77 ) ;
if ( ! ( V_98 & V_101 ) )
V_11 -> V_23 . V_24 ++ ;
if ( V_98 & V_102 )
V_11 -> V_23 . V_103 ++ ;
if ( V_98 & ( V_104 | V_105 ) ) {
F_28 ( V_11 , L_14 ,
( V_98 & V_104 ) ?
L_15 : L_16 ) ;
V_11 -> V_23 . V_106 ++ ;
if ( ! ( V_11 -> V_23 . V_106 & 63 ) && F_62 () ) {
F_63 ( V_11 , L_17 ) ;
}
}
F_19 ( V_13 ) ;
F_18 ( V_13 , V_107 ) ;
F_19 ( V_13 ) ;
F_44 ( V_13 , V_97 ) ;
F_8 ( V_13 , 0 ) ;
F_15 ( V_13 , V_13 -> V_39 ) ;
F_8 ( V_13 , 2 ) ;
}
static void F_64 ( struct V_10 * V_11 , unsigned int V_108 , int V_109 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
unsigned int V_110 , V_38 ;
V_110 = F_65 ( V_13 ) & ~ ( V_111 | V_112 | V_113 ) ;
V_110 |= V_112 ;
for ( V_38 = 1 << ( V_109 - 1 ) ; V_38 ; V_38 >>= 1 ) {
if ( V_108 & V_38 )
V_110 |= V_113 ;
else
V_110 &= ~ V_113 ;
F_66 ( V_13 , V_110 ) ;
F_14 ( V_114 ) ;
F_66 ( V_13 , V_110 | V_111 ) ;
F_14 ( V_114 ) ;
}
}
static unsigned int F_67 ( struct V_10 * V_11 , int V_109 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
unsigned int V_110 , V_38 , V_108 ;
V_110 = F_65 ( V_13 ) & ~ ( V_111 | V_112 | V_113 ) ;
F_66 ( V_13 , V_110 ) ;
for ( V_38 = 1 << ( V_109 - 1 ) , V_108 = 0 ; V_38 ; V_38 >>= 1 ) {
if ( F_65 ( V_13 ) & V_115 )
V_108 |= V_38 ;
F_66 ( V_13 , V_110 ) ;
F_14 ( V_114 ) ;
F_66 ( V_13 , V_110 | V_111 ) ;
F_14 ( V_114 ) ;
}
return V_108 ;
}
static int F_68 ( struct V_10 * V_11 , int V_116 , int V_117 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
unsigned int V_118 ;
F_8 ( V_13 , 3 ) ;
F_64 ( V_11 , 0xffffffff , 32 ) ;
F_64 ( V_11 , 6 << 10 | V_116 << 5 | V_117 , 14 ) ;
V_118 = F_67 ( V_11 , 18 ) ;
F_66 ( V_13 , F_65 ( V_13 ) & ~ ( V_111 | V_112 | V_113 ) ) ;
F_6 ( 3 , V_11 , L_18 ,
V_20 , V_116 , V_117 , V_118 ) ;
F_8 ( V_13 , 2 ) ;
return V_118 ;
}
static void F_69 ( struct V_10 * V_11 , int V_116 , int V_117 ,
int V_118 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
F_8 ( V_13 , 3 ) ;
F_64 ( V_11 , 0xffffffff , 32 ) ;
F_64 ( V_11 , 5 << 28 | V_116 << 23 | V_117 << 18 | 2 << 16 | V_118 , 32 ) ;
F_66 ( V_13 , F_65 ( V_13 ) & ~ ( V_111 | V_112 | V_113 ) ) ;
F_6 ( 3 , V_11 , L_18 ,
V_20 , V_116 , V_117 , V_118 ) ;
F_8 ( V_13 , 2 ) ;
}
static void F_70 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_116 ;
F_6 ( 2 , V_11 , L_3 , V_20 ) ;
V_13 -> V_119 = 0 ;
for ( V_116 = 1 ; V_116 < 33 ; ++ V_116 ) {
unsigned int V_120 , V_121 ;
V_120 = F_68 ( V_11 , V_116 & 31 , V_122 ) ;
V_121 = F_68 ( V_11 , V_116 & 31 , V_123 ) ;
F_6 ( 3 , V_11 , L_19 ,
V_120 , V_121 ) ;
if ( V_120 != 0x0000 && V_120 != 0xffff && V_120 != 0x8000 &&
V_121 != 0x0000 && V_121 != 0xffff && V_121 != 0x8000 ) {
V_13 -> V_124 . V_125 = V_116 & 31 ;
V_13 -> V_119 = V_120 << 16 | V_121 ;
break;
}
}
}
static int F_71 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
int V_116 = V_13 -> V_124 . V_125 ;
int V_126 , V_127 ;
F_6 ( 3 , V_11 , L_3 , V_20 ) ;
V_127 = F_68 ( V_11 , V_116 , V_128 ) ;
V_127 |= V_129 ;
F_69 ( V_11 , V_116 , V_128 , V_127 ) ;
V_126 = 0 ;
if ( V_13 -> V_130 )
V_126 |= V_131 ;
if ( V_13 -> V_132 == 100 )
V_126 |= V_133 ;
F_69 ( V_11 , V_116 , V_134 , V_126 ) ;
F_8 ( V_13 , 0 ) ;
F_72 ( V_13 , V_13 -> V_135 ) ;
F_8 ( V_13 , 2 ) ;
return 1 ;
}
static int F_73 ( struct V_10 * V_11 , int V_136 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_126 ;
int V_137 ;
F_69 ( V_11 , V_136 , V_134 , V_138 ) ;
for ( V_137 = 2 ; V_137 ; V_137 -- ) {
F_10 ( & V_13 -> V_21 ) ;
F_74 ( 50 ) ;
F_7 ( & V_13 -> V_21 ) ;
V_126 = F_68 ( V_11 , V_136 , V_134 ) ;
if ( ! ( V_126 & V_138 ) )
break;
}
return V_126 & V_138 ;
}
static void F_75 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
unsigned int V_126 ;
int V_136 = V_13 -> V_124 . V_125 ;
if ( V_13 -> V_119 == 0 )
return;
F_76 ( & V_13 -> V_139 ) ;
V_126 = F_68 ( V_11 , V_136 , V_134 ) ;
F_69 ( V_11 , V_136 , V_134 , V_126 | V_140 ) ;
}
static void F_77 ( struct V_10 * V_11 , int V_141 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
if ( F_78 ( & V_13 -> V_124 , F_79 ( V_13 ) , V_141 ) ) {
if ( V_13 -> V_124 . V_142 ) {
V_13 -> V_39 |= V_143 ;
} else {
V_13 -> V_39 &= ~ V_143 ;
}
F_8 ( V_13 , 0 ) ;
F_15 ( V_13 , V_13 -> V_39 ) ;
}
}
static void F_80 ( struct V_144 * V_145 )
{
struct V_12 * V_13 =
F_81 ( V_145 , struct V_12 , V_139 ) ;
struct V_10 * V_11 = V_13 -> V_11 ;
void T_2 * V_14 = V_13 -> V_15 ;
int V_116 = V_13 -> V_124 . V_125 ;
int V_146 ;
int V_147 ;
int V_50 ;
F_6 ( 3 , V_11 , L_20 ) ;
F_7 ( & V_13 -> V_21 ) ;
if ( V_13 -> V_119 == 0 )
goto V_148;
if ( F_73 ( V_11 , V_116 ) ) {
F_63 ( V_11 , L_21 ) ;
goto V_148;
}
F_69 ( V_11 , V_116 , V_149 ,
V_150 | V_151 | V_152 |
V_153 | V_154 | V_155 |
V_156 | V_157 ) ;
F_8 ( V_13 , 0 ) ;
F_72 ( V_13 , V_13 -> V_135 ) ;
if ( V_13 -> V_124 . V_158 ) {
F_71 ( V_11 ) ;
goto V_148;
}
V_146 = F_68 ( V_11 , V_116 , V_159 ) ;
if ( ! ( V_146 & V_160 ) ) {
F_63 ( V_11 , L_22 ) ;
F_71 ( V_11 ) ;
goto V_148;
}
V_147 = V_161 ;
if ( V_146 & V_162 )
V_147 |= V_163 ;
if ( V_146 & V_164 )
V_147 |= V_165 ;
if ( V_146 & V_166 )
V_147 |= V_167 ;
if ( V_146 & V_168 )
V_147 |= V_169 ;
if ( V_146 & V_170 )
V_147 |= V_171 ;
if ( V_13 -> V_132 != 100 )
V_147 &= ~ ( V_163 | V_165 | V_167 ) ;
if ( ! V_13 -> V_130 )
V_147 &= ~ ( V_165 | V_169 ) ;
F_69 ( V_11 , V_116 , V_172 , V_147 ) ;
V_13 -> V_124 . V_173 = V_147 ;
V_50 = F_68 ( V_11 , V_116 , V_172 ) ;
F_6 ( 2 , V_11 , L_23 , V_146 ) ;
F_6 ( 2 , V_11 , L_24 , V_147 ) ;
F_69 ( V_11 , V_116 , V_134 , V_174 | V_175 ) ;
F_77 ( V_11 , 1 ) ;
V_148:
F_8 ( V_13 , 2 ) ;
F_10 ( & V_13 -> V_21 ) ;
}
static void F_82 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_116 = V_13 -> V_124 . V_125 ;
int V_176 ;
F_6 ( 2 , V_11 , L_3 , V_20 ) ;
if ( V_13 -> V_119 == 0 )
return;
for(; ; ) {
F_77 ( V_11 , 0 ) ;
V_176 = F_68 ( V_11 , V_116 , V_177 ) ;
if ( ( V_176 & V_178 ) == 0 )
break;
}
}
static void F_83 ( struct V_10 * V_11 , int V_141 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
unsigned int V_179 , V_180 ;
V_179 = F_84 ( V_11 ) ? 1 : 0 ;
F_8 ( V_13 , 0 ) ;
V_180 = ( F_85 ( V_13 ) & V_181 ) ? 1 : 0 ;
F_8 ( V_13 , 2 ) ;
if ( V_141 || ( V_179 != V_180 ) ) {
if ( ! V_180 ) {
F_86 ( V_11 ) ;
} else {
F_87 ( V_11 ) ;
}
if ( F_79 ( V_13 ) )
F_63 ( V_11 , L_25 ,
V_180 ? L_26 : L_27 ) ;
}
}
static void F_88 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
unsigned int V_16 ;
F_83 ( V_11 , 0 ) ;
F_8 ( V_13 , 1 ) ;
V_16 = F_16 ( V_13 ) ;
F_17 ( V_13 , V_16 & ~ V_34 ) ;
F_17 ( V_13 , V_16 ) ;
F_8 ( V_13 , 2 ) ;
}
static T_3 F_89 ( int V_182 , void * V_183 )
{
struct V_10 * V_11 = V_183 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
int V_50 , V_38 , V_137 , V_184 ;
int V_185 ;
F_6 ( 3 , V_11 , L_3 , V_20 ) ;
F_90 ( & V_13 -> V_21 ) ;
V_186 ;
V_185 = F_91 ( V_13 ) ;
V_38 = F_92 ( V_13 ) ;
F_9 ( V_13 , 0 ) ;
V_137 = V_187 ;
do {
V_50 = F_57 ( V_13 ) ;
F_6 ( 2 , dev, L_28 ,
status, mask,
({ int meminfo; SMC_SELECT_BANK(lp, 0);
meminfo = SMC_GET_MIR(lp);
SMC_SELECT_BANK(lp, 2); meminfo; }),
SMC_GET_FIFO(lp)) ;
V_50 &= V_38 ;
if ( ! V_50 )
break;
if ( V_50 & V_88 ) {
F_6 ( 3 , V_11 , L_29 ) ;
F_59 ( V_11 ) ;
F_58 ( V_13 , V_88 ) ;
if ( V_35 )
F_50 ( V_11 ) ;
} else if ( V_50 & V_44 ) {
F_6 ( 3 , V_11 , L_30 ) ;
F_25 ( V_11 ) ;
} else if ( V_50 & V_96 ) {
F_6 ( 3 , V_11 , L_31 ) ;
F_93 ( & V_13 -> V_79 ) ;
V_38 &= ~ V_96 ;
} else if ( V_50 & V_89 ) {
F_6 ( 3 , V_11 , L_32 ) ;
V_38 &= ~ V_89 ;
F_8 ( V_13 , 0 ) ;
V_184 = F_94 ( V_13 ) ;
F_8 ( V_13 , 2 ) ;
V_11 -> V_23 . V_188 += V_184 & 0xF ;
V_184 >>= 4 ;
V_11 -> V_23 . V_188 += V_184 & 0xF ;
} else if ( V_50 & V_43 ) {
F_6 ( 1 , dev, L_33 ,
({ int eph_st; SMC_SELECT_BANK(lp, 0);
eph_st = SMC_GET_EPH_STATUS(lp);
SMC_SELECT_BANK(lp, 2); eph_st; })) ;
F_58 ( V_13 , V_43 ) ;
V_11 -> V_23 . V_61 ++ ;
V_11 -> V_23 . V_189 ++ ;
} else if ( V_50 & V_42 ) {
F_88 ( V_11 ) ;
} else if ( V_50 & V_47 ) {
F_58 ( V_13 , V_47 ) ;
F_82 ( V_11 ) ;
} else if ( V_50 & V_190 ) {
F_58 ( V_13 , V_190 ) ;
F_28 ( V_11 , L_34 ) ;
}
} while ( -- V_137 );
F_29 ( V_13 , V_185 ) ;
F_9 ( V_13 , V_38 ) ;
F_95 ( & V_13 -> V_21 ) ;
#ifndef F_96
if ( V_137 == V_187 )
F_28 ( V_11 , L_35 ,
V_38 ) ;
#endif
F_6 ( 3 , V_11 , L_36 ,
V_187 - V_137 ) ;
return V_191 ;
}
static void F_97 ( struct V_10 * V_11 )
{
F_98 ( V_11 -> V_182 ) ;
F_89 ( V_11 -> V_182 , V_11 ) ;
F_99 ( V_11 -> V_182 ) ;
}
static void F_100 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
int V_50 , V_38 , V_192 , V_193 , V_194 ;
F_6 ( 2 , V_11 , L_3 , V_20 ) ;
F_7 ( & V_13 -> V_21 ) ;
V_50 = F_57 ( V_13 ) ;
V_38 = F_92 ( V_13 ) ;
V_194 = F_101 ( V_13 ) ;
F_8 ( V_13 , 0 ) ;
V_192 = F_85 ( V_13 ) ;
V_193 = F_102 ( V_13 ) ;
F_8 ( V_13 , 2 ) ;
F_10 ( & V_13 -> V_21 ) ;
F_28 ( V_11 , L_37 ,
V_50 , V_38 , V_193 , V_194 , V_192 ) ;
F_4 ( V_11 ) ;
F_20 ( V_11 ) ;
if ( V_13 -> V_119 != 0 )
F_103 ( & V_13 -> V_139 ) ;
V_11 -> V_84 = V_85 ;
F_50 ( V_11 ) ;
}
static void F_104 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
unsigned char V_195 [ 8 ] ;
int V_196 = 0 ;
F_6 ( 2 , V_11 , L_3 , V_20 ) ;
if ( V_11 -> V_28 & V_197 ) {
F_6 ( 2 , V_11 , L_38 ) ;
V_13 -> V_40 |= V_198 ;
}
else if ( V_11 -> V_28 & V_199 || F_105 ( V_11 ) > 16 ) {
F_6 ( 2 , V_11 , L_39 ) ;
V_13 -> V_40 |= V_200 ;
}
else if ( ! F_106 ( V_11 ) ) {
struct V_201 * V_202 ;
static const unsigned char V_203 [] = { 0 , 4 , 2 , 6 , 1 , 5 , 3 , 7 } ;
memset ( V_195 , 0 , sizeof( V_195 ) ) ;
F_107 (ha, dev) {
int V_204 ;
V_204 = F_108 ( ~ 0 , V_202 -> V_205 , 6 ) & 0x3f ;
V_195 [ V_203 [ V_204 & 7 ] ] |=
( 1 << V_203 [ ( V_204 >> 3 ) & 7 ] ) ;
}
V_13 -> V_40 &= ~ ( V_198 | V_200 ) ;
V_196 = 1 ;
} else {
F_6 ( 2 , V_11 , L_40 ) ;
V_13 -> V_40 &= ~ ( V_198 | V_200 ) ;
memset ( V_195 , 0 , sizeof( V_195 ) ) ;
V_196 = 1 ;
}
F_7 ( & V_13 -> V_21 ) ;
F_8 ( V_13 , 0 ) ;
F_12 ( V_13 , V_13 -> V_40 ) ;
if ( V_196 ) {
F_8 ( V_13 , 3 ) ;
F_109 ( V_13 , V_195 ) ;
}
F_8 ( V_13 , 2 ) ;
F_10 ( & V_13 -> V_21 ) ;
}
static int
F_110 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_6 ( 2 , V_11 , L_3 , V_20 ) ;
V_13 -> V_39 = V_206 ;
V_13 -> V_40 = V_207 ;
V_13 -> V_135 = V_208 |
V_13 -> V_17 . V_209 << V_210 |
V_13 -> V_17 . V_211 << V_212 ;
if ( V_13 -> V_119 == 0 )
V_13 -> V_39 |= V_213 ;
F_4 ( V_11 ) ;
F_20 ( V_11 ) ;
if ( V_13 -> V_119 != 0 )
F_80 ( & V_13 -> V_139 ) ;
else {
F_7 ( & V_13 -> V_21 ) ;
F_83 ( V_11 , 1 ) ;
F_10 ( & V_13 -> V_21 ) ;
}
F_111 ( V_11 ) ;
return 0 ;
}
static int F_112 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_6 ( 2 , V_11 , L_3 , V_20 ) ;
F_40 ( V_11 ) ;
F_86 ( V_11 ) ;
F_22 ( V_11 ) ;
F_113 ( & V_13 -> V_79 ) ;
F_75 ( V_11 ) ;
return 0 ;
}
static int
F_114 ( struct V_10 * V_11 , struct V_214 * V_215 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_216 ;
V_215 -> V_217 = 1 ;
V_215 -> V_218 = 1 ;
if ( V_13 -> V_119 != 0 ) {
F_7 ( & V_13 -> V_21 ) ;
V_216 = F_115 ( & V_13 -> V_124 , V_215 ) ;
F_10 ( & V_13 -> V_21 ) ;
} else {
V_215 -> V_219 = V_220 |
V_221 |
V_222 | V_223 ;
if ( V_13 -> V_132 == 10 )
F_116 ( V_215 , V_224 ) ;
else if ( V_13 -> V_132 == 100 )
F_116 ( V_215 , V_225 ) ;
V_215 -> V_226 = V_227 ;
V_215 -> V_228 = V_229 ;
V_215 -> V_230 = 0 ;
V_215 -> V_231 = V_13 -> V_39 & V_143 ? V_232 : V_233 ;
V_216 = 0 ;
}
return V_216 ;
}
static int
F_117 ( struct V_10 * V_11 , struct V_214 * V_215 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_216 ;
if ( V_13 -> V_119 != 0 ) {
F_7 ( & V_13 -> V_21 ) ;
V_216 = F_118 ( & V_13 -> V_124 , V_215 ) ;
F_10 ( & V_13 -> V_21 ) ;
} else {
if ( V_215 -> V_226 != V_227 ||
V_215 -> V_234 != V_224 ||
( V_215 -> V_231 != V_233 && V_215 -> V_231 != V_232 ) ||
( V_215 -> V_230 != V_235 && V_215 -> V_230 != V_236 ) )
return - V_237 ;
V_13 -> V_130 = V_215 -> V_231 == V_232 ;
V_216 = 0 ;
}
return V_216 ;
}
static void
F_119 ( struct V_10 * V_11 , struct V_238 * V_239 )
{
F_120 ( V_239 -> V_240 , V_48 , sizeof( V_239 -> V_240 ) ) ;
F_120 ( V_239 -> V_45 , V_45 , sizeof( V_239 -> V_45 ) ) ;
F_120 ( V_239 -> V_241 , F_121 ( V_11 -> V_11 . V_242 ) ,
sizeof( V_239 -> V_241 ) ) ;
}
static int F_122 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_216 = - V_237 ;
if ( V_13 -> V_119 != 0 ) {
F_7 ( & V_13 -> V_21 ) ;
V_216 = F_123 ( & V_13 -> V_124 ) ;
F_10 ( & V_13 -> V_21 ) ;
}
return V_216 ;
}
static T_4 F_124 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
return V_13 -> V_243 ;
}
static void F_125 ( struct V_10 * V_11 , T_4 V_244 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
V_13 -> V_243 = V_244 ;
}
static int F_126 ( struct V_10 * V_11 , T_5 V_205 , T_5 V_245 )
{
T_5 V_16 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
F_7 ( & V_13 -> V_21 ) ;
F_8 ( V_13 , 1 ) ;
F_127 ( V_13 , V_245 ) ;
F_8 ( V_13 , 2 ) ;
F_29 ( V_13 , V_205 ) ;
F_8 ( V_13 , 1 ) ;
V_16 = F_16 ( V_13 ) ;
F_17 ( V_13 , V_16 | ( V_246 | V_247 ) ) ;
do {
F_14 ( 1 ) ;
} while ( F_16 ( V_13 ) & V_247 );
F_17 ( V_13 , V_16 ) ;
F_8 ( V_13 , 2 ) ;
F_10 ( & V_13 -> V_21 ) ;
return 0 ;
}
static int F_128 ( struct V_10 * V_11 , T_5 V_205 , T_5 * V_245 )
{
T_5 V_16 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_2 * V_14 = V_13 -> V_15 ;
F_7 ( & V_13 -> V_21 ) ;
F_8 ( V_13 , 2 ) ;
F_29 ( V_13 , V_205 | V_53 ) ;
F_8 ( V_13 , 1 ) ;
F_127 ( V_13 , 0xffff ) ;
V_16 = F_16 ( V_13 ) ;
F_17 ( V_13 , V_16 | ( V_246 | V_248 ) ) ;
do {
F_14 ( 1 ) ;
} while ( F_16 ( V_13 ) & V_248 );
* V_245 = F_129 ( V_13 ) ;
F_17 ( V_13 , V_16 ) ;
F_8 ( V_13 , 2 ) ;
F_10 ( & V_13 -> V_21 ) ;
return 0 ;
}
static int F_130 ( struct V_10 * V_11 )
{
return 0x23 * 2 ;
}
static int F_131 ( struct V_10 * V_11 ,
struct V_249 * V_250 , T_6 * V_68 )
{
int V_3 ;
int V_251 ;
F_6 ( 1 , V_11 , L_41 ,
V_250 -> V_78 , V_250 -> V_252 , V_250 -> V_252 ) ;
V_251 = F_130 ( V_11 ) ;
for ( V_3 = 0 ; V_3 < V_250 -> V_78 ; V_3 += 2 ) {
int V_216 ;
T_5 V_253 ;
int V_252 = V_3 + V_250 -> V_252 ;
if ( V_252 > V_251 )
break;
V_216 = F_128 ( V_11 , V_252 >> 1 , & V_253 ) ;
if ( V_216 != 0 )
return V_216 ;
F_6 ( 2 , V_11 , L_42 , V_253 , V_252 >> 1 ) ;
V_68 [ V_3 ] = ( V_253 >> 8 ) & 0xff ;
V_68 [ V_3 + 1 ] = V_253 & 0xff ;
}
return 0 ;
}
static int F_132 ( struct V_10 * V_11 ,
struct V_249 * V_250 , T_6 * V_68 )
{
int V_3 ;
int V_251 ;
F_6 ( 1 , V_11 , L_43 ,
V_250 -> V_78 , V_250 -> V_252 , V_250 -> V_252 ) ;
V_251 = F_130 ( V_11 ) ;
for ( V_3 = 0 ; V_3 < V_250 -> V_78 ; V_3 += 2 ) {
int V_216 ;
T_5 V_253 ;
int V_252 = V_3 + V_250 -> V_252 ;
if ( V_252 > V_251 )
break;
V_253 = ( V_68 [ V_3 ] << 8 ) | V_68 [ V_3 + 1 ] ;
F_6 ( 2 , V_11 , L_44 , V_253 , V_252 >> 1 ) ;
V_216 = F_126 ( V_11 , V_252 >> 1 , V_253 ) ;
if ( V_216 != 0 )
return V_216 ;
}
return 0 ;
}
static int F_133 ( struct V_12 * V_13 )
{
void T_2 * V_14 = V_13 -> V_15 ;
int V_137 = 20 ;
unsigned long V_254 ;
F_6 ( 2 , V_13 -> V_11 , L_4 , V_48 , V_20 ) ;
V_254 = F_134 () ;
F_8 ( V_13 , 2 ) ;
F_9 ( V_13 , V_96 ) ;
F_18 ( V_13 , V_94 | 1 ) ;
do {
int V_255 ;
F_14 ( 10 ) ;
V_255 = F_57 ( V_13 ) ;
if ( V_255 & V_96 )
break;
} while ( -- V_137 );
F_9 ( V_13 , 0 ) ;
return F_135 ( V_254 ) ;
}
static int F_136 ( struct V_10 * V_11 , void T_2 * V_14 ,
unsigned long V_256 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_257 ;
unsigned int V_108 , V_258 ;
const char * V_259 ;
F_6 ( 2 , V_11 , L_4 , V_48 , V_20 ) ;
V_108 = F_137 ( V_13 ) ;
F_6 ( 2 , V_11 , L_45 ,
V_48 , V_108 ) ;
if ( ( V_108 & 0xFF00 ) != 0x3300 ) {
if ( ( V_108 & 0xFF ) == 0x33 ) {
F_54 ( V_11 ,
L_46 ,
V_48 , V_14 ) ;
}
V_257 = - V_260 ;
goto V_261;
}
F_8 ( V_13 , 0 ) ;
V_108 = F_137 ( V_13 ) ;
if ( ( V_108 & 0xFF00 ) != 0x3300 ) {
V_257 = - V_260 ;
goto V_261;
}
F_8 ( V_13 , 1 ) ;
V_108 = F_138 ( V_13 ) ;
V_108 = ( ( V_108 & 0x1F00 ) >> 3 ) << V_262 ;
if ( ( ( unsigned long ) V_14 & ( 0x3e0 << V_262 ) ) != V_108 ) {
F_54 ( V_11 , L_47 ,
V_48 , V_14 , V_108 ) ;
}
F_8 ( V_13 , 3 ) ;
V_258 = F_139 ( V_13 ) ;
F_6 ( 2 , V_11 , L_48 , V_48 , V_258 ) ;
V_259 = V_263 [ ( V_258 >> 4 ) & 0xF ] ;
if ( ! V_259 || ( V_258 & 0xff00 ) != 0x3300 ) {
F_54 ( V_11 , L_49 ,
V_48 , V_14 , V_258 ) ;
V_257 = - V_260 ;
goto V_261;
}
F_140 ( L_3 , V_45 ) ;
V_11 -> V_264 = ( unsigned long ) V_14 ;
V_13 -> V_15 = V_14 ;
V_13 -> V_45 = V_258 & 0xff ;
F_141 ( & V_13 -> V_21 ) ;
F_8 ( V_13 , 1 ) ;
F_142 ( V_13 , V_11 -> V_41 ) ;
F_4 ( V_11 ) ;
if ( V_11 -> V_182 < 1 ) {
int V_265 ;
V_265 = 3 ;
while ( V_265 -- ) {
V_11 -> V_182 = F_133 ( V_13 ) ;
if ( V_11 -> V_182 )
break;
F_4 ( V_11 ) ;
}
}
if ( V_11 -> V_182 == 0 ) {
F_54 ( V_11 , L_50 ) ;
V_257 = - V_260 ;
goto V_261;
}
V_11 -> V_182 = F_143 ( V_11 -> V_182 ) ;
V_11 -> V_266 = F_144 ( V_267 ) ;
V_11 -> V_268 = & V_269 ;
V_11 -> V_270 = & V_271 ;
F_145 ( & V_13 -> V_79 , F_38 , ( unsigned long ) V_11 ) ;
F_146 ( & V_13 -> V_139 , F_80 ) ;
V_13 -> V_11 = V_11 ;
V_13 -> V_124 . V_272 = 0x1f ;
V_13 -> V_124 . V_273 = 0x1f ;
V_13 -> V_124 . V_158 = 0 ;
V_13 -> V_124 . V_142 = 0 ;
V_13 -> V_124 . V_11 = V_11 ;
V_13 -> V_124 . V_274 = F_68 ;
V_13 -> V_124 . V_275 = F_69 ;
if ( V_13 -> V_45 >= ( V_46 << 4 ) )
F_70 ( V_11 ) ;
F_22 ( V_11 ) ;
F_75 ( V_11 ) ;
V_13 -> V_243 = V_276 ;
V_13 -> V_130 = 0 ;
V_13 -> V_132 = 10 ;
if ( V_13 -> V_45 >= ( V_46 << 4 ) ) {
V_13 -> V_130 = 1 ;
V_13 -> V_132 = 100 ;
}
V_257 = F_147 ( V_11 -> V_182 , F_89 , V_256 , V_11 -> V_277 , V_11 ) ;
if ( V_257 )
goto V_261;
#ifdef F_148
# ifdef F_149
V_13 -> V_17 . V_28 |= V_278 ;
# endif
if ( V_13 -> V_17 . V_28 & V_278 ) {
int V_279 = F_150 ( V_11 -> V_277 , V_280 ,
V_281 , NULL ) ;
if ( V_279 >= 0 )
V_11 -> V_279 = V_279 ;
}
#endif
V_257 = F_151 ( V_11 ) ;
if ( V_257 == 0 ) {
F_63 ( V_11 , L_51 ,
V_259 , V_258 & 0x0f ,
V_13 -> V_15 , V_11 -> V_182 ) ;
if ( V_11 -> V_279 != ( unsigned char ) - 1 )
F_3 ( L_52 , V_11 -> V_279 ) ;
F_3 ( L_53 ,
V_13 -> V_17 . V_28 & V_29 ? L_54 : L_55 ,
V_35 ? L_56 : L_55 ) ;
if ( ! F_152 ( V_11 -> V_41 ) ) {
F_54 ( V_11 , L_57 ) ;
} else {
F_63 ( V_11 , L_58 ,
V_11 -> V_41 ) ;
}
if ( V_13 -> V_119 == 0 ) {
F_28 ( V_11 , L_59 ) ;
} else if ( ( V_13 -> V_119 & 0xfffffff0 ) == 0x0016f840 ) {
F_28 ( V_11 , L_60 ) ;
} else if ( ( V_13 -> V_119 & 0xfffffff0 ) == 0x02821c50 ) {
F_28 ( V_11 , L_61 ) ;
}
}
V_261:
#ifdef F_148
if ( V_257 && V_11 -> V_279 != ( unsigned char ) - 1 )
F_153 ( V_11 -> V_279 ) ;
#endif
return V_257 ;
}
static int F_154 ( struct V_282 * V_283 )
{
struct V_10 * V_284 = F_155 ( V_283 ) ;
struct V_12 * V_13 = F_5 ( V_284 ) ;
unsigned long V_28 ;
unsigned char V_285 , V_286 ;
void T_2 * V_205 ;
struct V_287 * V_288 ;
V_288 = F_156 ( V_283 , V_289 , L_62 ) ;
if ( ! V_288 )
return 0 ;
V_205 = F_157 ( V_288 -> V_290 , V_291 ) ;
if ( ! V_205 )
return - V_292 ;
F_158 ( V_28 ) ;
V_285 = F_159 ( V_205 + ( V_293 << V_262 ) ) & ~ V_294 ;
F_160 ( V_285 | V_294 , V_205 + ( V_293 << V_262 ) ) ;
F_159 ( V_205 + ( V_293 << V_262 ) ) ;
F_14 ( 100 ) ;
F_160 ( V_285 , V_205 + ( V_293 << V_262 ) ) ;
F_160 ( V_285 | V_295 , V_205 + ( V_293 << V_262 ) ) ;
V_286 = F_159 ( V_205 + ( V_296 << V_262 ) ) & ~ V_297 ;
if ( ! F_161 ( V_13 ) )
V_286 |= V_297 ;
F_160 ( V_286 , V_205 + ( V_296 << V_262 ) ) ;
F_162 ( V_28 ) ;
F_163 ( V_205 ) ;
F_74 ( 1 ) ;
return 0 ;
}
static int F_164 ( struct V_282 * V_283 ,
struct V_10 * V_284 )
{
struct V_287 * V_288 = F_156 ( V_283 , V_289 , L_62 ) ;
struct V_12 * V_13 V_298 = F_5 ( V_284 ) ;
if ( ! V_288 )
return 0 ;
if ( ! F_165 ( V_288 -> V_290 , V_291 , V_48 ) )
return - V_299 ;
return 0 ;
}
static void F_166 ( struct V_282 * V_283 ,
struct V_10 * V_284 )
{
struct V_287 * V_288 = F_156 ( V_283 , V_289 , L_62 ) ;
struct V_12 * V_13 V_298 = F_5 ( V_284 ) ;
if ( V_288 )
F_167 ( V_288 -> V_290 , V_291 ) ;
}
static inline void F_168 ( struct V_282 * V_283 , struct V_10 * V_284 )
{
if ( V_300 ) {
struct V_287 * V_288 = F_156 ( V_283 , V_289 , L_63 ) ;
struct V_12 * V_13 = F_5 ( V_284 ) ;
if ( ! V_288 )
return;
if( ! F_165 ( V_288 -> V_290 , V_301 , V_48 ) ) {
F_63 ( V_284 , L_64 ,
V_48 ) ;
return;
}
V_13 -> V_302 = F_157 ( V_288 -> V_290 , V_301 ) ;
}
}
static void F_169 ( struct V_282 * V_283 , struct V_10 * V_284 )
{
if ( V_300 ) {
struct V_12 * V_13 = F_5 ( V_284 ) ;
struct V_287 * V_288 = F_156 ( V_283 , V_289 , L_63 ) ;
if ( V_13 -> V_302 )
F_163 ( V_13 -> V_302 ) ;
V_13 -> V_302 = NULL ;
if ( V_288 )
F_167 ( V_288 -> V_290 , V_301 ) ;
}
}
static int F_170 ( struct V_303 * V_11 ,
struct V_304 * * V_305 ,
const char * V_277 , int V_306 ,
int V_307 , unsigned int V_308 )
{
struct V_304 * V_309 = * V_305 ;
int V_288 ;
V_309 = F_171 ( V_11 , V_277 , V_306 ) ;
if ( F_172 ( V_309 ) ) {
if ( F_173 ( V_309 ) == - V_310 ) {
* V_305 = NULL ;
return 0 ;
}
return F_173 ( V_309 ) ;
}
V_288 = F_174 ( V_309 , ! V_307 ) ;
if ( V_288 ) {
F_175 ( V_11 , L_65 , V_277 , V_288 ) ;
F_176 ( V_11 , V_309 ) ;
V_309 = NULL ;
return V_288 ;
}
if ( V_308 )
F_177 ( V_308 , 2 * V_308 ) ;
F_178 ( V_309 , V_307 ) ;
* V_305 = V_309 ;
return 0 ;
}
static int F_179 ( struct V_282 * V_283 )
{
struct V_311 * V_312 = F_180 ( & V_283 -> V_11 ) ;
const struct V_313 * V_314 = NULL ;
struct V_12 * V_13 ;
struct V_10 * V_284 ;
struct V_287 * V_288 ;
unsigned int T_2 * V_205 ;
unsigned long V_256 = V_315 ;
unsigned long V_316 ;
int V_216 ;
V_284 = F_181 ( sizeof( struct V_12 ) ) ;
if ( ! V_284 ) {
V_216 = - V_292 ;
goto V_317;
}
F_182 ( V_284 , & V_283 -> V_11 ) ;
V_13 = F_5 ( V_284 ) ;
V_13 -> V_17 . V_28 = 0 ;
if ( V_312 ) {
memcpy ( & V_13 -> V_17 , V_312 , sizeof( V_13 -> V_17 ) ) ;
V_13 -> V_318 = F_183 ( V_13 -> V_17 . V_28 ) ;
}
#if F_184 ( V_319 )
V_314 = F_185 ( F_186 ( V_320 ) , & V_283 -> V_11 ) ;
if ( V_314 ) {
struct V_321 * V_322 = V_283 -> V_11 . V_323 ;
T_4 V_108 ;
V_216 = F_170 ( & V_283 -> V_11 , & V_13 -> V_324 ,
L_66 , 0 , 0 , 100 ) ;
if ( V_216 )
return V_216 ;
V_216 = F_170 ( & V_283 -> V_11 , & V_13 -> V_325 ,
L_67 , 0 , 0 , 100 ) ;
if ( V_216 )
return V_216 ;
if ( V_13 -> V_325 )
F_177 ( 750 , 1000 ) ;
if ( ! F_187 ( V_322 , L_68 , & V_108 ) ) {
if ( V_108 & 1 )
V_13 -> V_17 . V_28 |= V_326 ;
if ( ( V_108 == 0 ) || ( V_108 & 2 ) )
V_13 -> V_17 . V_28 |= V_327 ;
if ( V_108 & 4 )
V_13 -> V_17 . V_28 |= V_328 ;
} else {
V_13 -> V_17 . V_28 |= V_327 ;
}
}
#endif
if ( ! V_312 && ! V_314 ) {
V_13 -> V_17 . V_28 |= ( V_329 ) ? V_326 : 0 ;
V_13 -> V_17 . V_28 |= ( V_330 ) ? V_327 : 0 ;
V_13 -> V_17 . V_28 |= ( V_331 ) ? V_328 : 0 ;
V_13 -> V_17 . V_28 |= ( V_332 ) ? V_29 : 0 ;
}
if ( ! V_13 -> V_17 . V_209 && ! V_13 -> V_17 . V_211 ) {
V_13 -> V_17 . V_209 = V_333 ;
V_13 -> V_17 . V_211 = V_334 ;
}
V_284 -> V_279 = ( unsigned char ) - 1 ;
V_288 = F_156 ( V_283 , V_289 , L_69 ) ;
if ( ! V_288 )
V_288 = F_188 ( V_283 , V_289 , 0 ) ;
if ( ! V_288 ) {
V_216 = - V_260 ;
goto V_335;
}
if ( ! F_165 ( V_288 -> V_290 , V_336 , V_48 ) ) {
V_216 = - V_299 ;
goto V_335;
}
V_284 -> V_182 = F_189 ( V_283 , 0 ) ;
if ( V_284 -> V_182 <= 0 ) {
V_216 = - V_260 ;
goto V_337;
}
V_316 = F_190 ( F_191 ( V_284 -> V_182 ) ) ;
if ( V_256 == - 1 || V_316 & V_338 )
V_256 = V_316 & V_338 ;
V_216 = F_164 ( V_283 , V_284 ) ;
if ( V_216 )
goto V_337;
#if F_192 ( V_339 )
F_193 ( V_340 ) ;
#endif
F_194 ( V_283 , V_284 ) ;
V_216 = F_154 ( V_283 ) ;
if ( V_216 )
goto V_341;
V_205 = F_157 ( V_288 -> V_290 , V_336 ) ;
if ( ! V_205 ) {
V_216 = - V_292 ;
goto V_341;
}
#ifdef F_148
{
struct V_12 * V_13 = F_5 ( V_284 ) ;
V_13 -> V_303 = & V_283 -> V_11 ;
V_13 -> V_342 = V_288 -> V_290 ;
}
#endif
V_216 = F_136 ( V_284 , V_205 , V_256 ) ;
if ( V_216 != 0 )
goto V_343;
F_168 ( V_283 , V_284 ) ;
return 0 ;
V_343:
F_163 ( V_205 ) ;
V_341:
F_166 ( V_283 , V_284 ) ;
V_337:
F_167 ( V_288 -> V_290 , V_336 ) ;
V_335:
F_195 ( V_284 ) ;
V_317:
F_196 ( L_70 , V_48 , V_216 ) ;
return V_216 ;
}
static int F_197 ( struct V_282 * V_283 )
{
struct V_10 * V_284 = F_155 ( V_283 ) ;
struct V_12 * V_13 = F_5 ( V_284 ) ;
struct V_287 * V_288 ;
F_198 ( V_284 ) ;
F_199 ( V_284 -> V_182 , V_284 ) ;
#ifdef F_148
if ( V_284 -> V_279 != ( unsigned char ) - 1 )
F_153 ( V_284 -> V_279 ) ;
#endif
F_163 ( V_13 -> V_15 ) ;
F_169 ( V_283 , V_284 ) ;
F_166 ( V_283 , V_284 ) ;
V_288 = F_156 ( V_283 , V_289 , L_69 ) ;
if ( ! V_288 )
V_288 = F_188 ( V_283 , V_289 , 0 ) ;
F_167 ( V_288 -> V_290 , V_336 ) ;
F_195 ( V_284 ) ;
return 0 ;
}
static int F_200 ( struct V_303 * V_11 )
{
struct V_282 * V_283 = F_201 ( V_11 ) ;
struct V_10 * V_284 = F_155 ( V_283 ) ;
if ( V_284 ) {
if ( F_202 ( V_284 ) ) {
F_203 ( V_284 ) ;
F_22 ( V_284 ) ;
F_75 ( V_284 ) ;
}
}
return 0 ;
}
static int F_204 ( struct V_303 * V_11 )
{
struct V_282 * V_283 = F_201 ( V_11 ) ;
struct V_10 * V_284 = F_155 ( V_283 ) ;
if ( V_284 ) {
struct V_12 * V_13 = F_5 ( V_284 ) ;
F_154 ( V_283 ) ;
if ( F_202 ( V_284 ) ) {
F_4 ( V_284 ) ;
F_20 ( V_284 ) ;
if ( V_13 -> V_119 != 0 )
F_80 ( & V_13 -> V_139 ) ;
F_205 ( V_284 ) ;
}
}
return 0 ;
}

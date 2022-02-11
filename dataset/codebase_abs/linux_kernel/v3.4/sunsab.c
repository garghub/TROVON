static T_1 void F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 ;
while ( ( F_2 ( & V_2 -> V_5 -> V_6 . V_7 ) & V_8 ) && -- V_3 )
F_3 ( 1 ) ;
}
static T_1 void F_4 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_9 ;
while ( ( F_2 ( & V_2 -> V_5 -> V_6 . V_7 ) & V_10 ) && -- V_3 )
F_3 ( 1 ) ;
}
static struct V_11 *
F_5 ( struct V_1 * V_2 ,
union V_12 * V_13 )
{
struct V_11 * V_14 = NULL ;
unsigned char V_15 [ 32 ] ;
int V_16 = 0 ;
int V_17 = 0 ;
int V_18 = 0 ;
int V_19 ;
if ( V_2 -> V_20 . V_21 != NULL )
V_14 = V_2 -> V_20 . V_21 -> V_20 . V_14 ;
if ( V_13 -> V_22 . V_23 & V_24 ) {
V_18 = V_25 ;
V_17 ++ ;
}
if ( V_13 -> V_22 . V_23 & V_26 ) {
V_18 = F_2 ( & V_2 -> V_5 -> V_6 . V_27 ) & ( V_25 - 1 ) ;
V_17 ++ ;
}
if ( V_13 -> V_22 . V_23 & V_28 ) {
F_4 ( V_2 ) ;
F_6 ( V_29 , & V_2 -> V_5 -> V_30 . V_31 ) ;
return V_14 ;
}
if ( V_13 -> V_22 . V_23 & V_32 )
V_17 ++ ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ )
V_15 [ V_19 ] = F_2 ( & V_2 -> V_5 -> V_6 . V_33 [ V_19 ] ) ;
if ( V_17 ) {
F_4 ( V_2 ) ;
F_6 ( V_34 , & V_2 -> V_5 -> V_30 . V_31 ) ;
}
if ( ( V_13 -> V_22 . V_35 & V_36 ) &&
( V_2 -> V_20 . line == V_2 -> V_20 . V_37 -> V_38 ) )
V_16 = 1 ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
unsigned char V_39 = V_15 [ V_19 ] , V_40 ;
if ( V_14 == NULL ) {
F_7 ( & V_2 -> V_20 , V_39 ) ;
continue;
}
V_40 = V_41 ;
V_2 -> V_20 . V_42 . V_43 ++ ;
if ( F_8 ( V_13 -> V_22 . V_23 & ( V_44 |
V_45 |
V_32 ) ) ||
F_8 ( V_13 -> V_22 . V_35 & V_36 ) ) {
if ( V_13 -> V_22 . V_35 & V_36 ) {
V_13 -> V_22 . V_23 &= ~ ( V_44 |
V_45 ) ;
V_2 -> V_20 . V_42 . V_46 ++ ;
if ( F_9 ( & V_2 -> V_20 ) )
continue;
} else if ( V_13 -> V_22 . V_23 & V_44 )
V_2 -> V_20 . V_42 . V_47 ++ ;
else if ( V_13 -> V_22 . V_23 & V_45 )
V_2 -> V_20 . V_42 . V_48 ++ ;
if ( V_13 -> V_22 . V_23 & V_32 )
V_2 -> V_20 . V_42 . V_49 ++ ;
V_13 -> V_22 . V_23 &= ( V_2 -> V_20 . V_50 & 0xff ) ;
V_13 -> V_22 . V_35 &= ( ( V_2 -> V_20 . V_50 >> 8 ) & 0xff ) ;
if ( V_13 -> V_22 . V_35 & V_36 ) {
V_40 = V_51 ;
} else if ( V_13 -> V_22 . V_23 & V_44 )
V_40 = V_52 ;
else if ( V_13 -> V_22 . V_23 & V_45 )
V_40 = V_53 ;
}
if ( F_7 ( & V_2 -> V_20 , V_39 ) )
continue;
if ( ( V_13 -> V_22 . V_23 & ( V_2 -> V_20 . V_54 & 0xff ) ) == 0 &&
( V_13 -> V_22 . V_35 & ( ( V_2 -> V_20 . V_54 >> 8 ) & 0xff ) ) == 0 )
F_10 ( V_14 , V_39 , V_40 ) ;
if ( V_13 -> V_22 . V_23 & V_32 )
F_10 ( V_14 , 0 , V_55 ) ;
}
if ( V_16 )
F_11 () ;
return V_14 ;
}
static void F_12 ( struct V_1 * V_2 ,
union V_12 * V_13 )
{
struct V_56 * V_57 = & V_2 -> V_20 . V_21 -> V_57 ;
int V_19 ;
if ( V_13 -> V_22 . V_35 & V_58 ) {
V_2 -> V_59 |= V_60 ;
F_6 ( V_2 -> V_59 , & V_2 -> V_5 -> V_30 . V_61 ) ;
F_13 ( V_62 , & V_2 -> V_63 ) ;
}
#if 0
if (!(stat->sreg.isr1 & SAB82532_ISR1_XPR))
return;
#endif
if ( ! ( F_2 ( & V_2 -> V_5 -> V_6 . V_7 ) & V_64 ) )
return;
F_13 ( V_65 , & V_2 -> V_63 ) ;
F_14 ( V_2 ) ;
if ( F_15 ( V_57 ) || F_16 ( & V_2 -> V_20 ) ) {
V_2 -> V_59 |= V_66 ;
F_6 ( V_2 -> V_59 , & V_2 -> V_5 -> V_30 . V_61 ) ;
return;
}
V_2 -> V_59 &= ~ ( V_60 | V_66 ) ;
F_6 ( V_2 -> V_59 , & V_2 -> V_5 -> V_30 . V_61 ) ;
F_17 ( V_62 , & V_2 -> V_63 ) ;
F_17 ( V_65 , & V_2 -> V_63 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 . V_67 ; V_19 ++ ) {
F_6 ( V_57 -> V_15 [ V_57 -> V_68 ] ,
& V_2 -> V_5 -> V_30 . V_69 [ V_19 ] ) ;
V_57 -> V_68 = ( V_57 -> V_68 + 1 ) & ( V_70 - 1 ) ;
V_2 -> V_20 . V_42 . V_71 ++ ;
if ( F_15 ( V_57 ) )
break;
}
F_4 ( V_2 ) ;
F_6 ( V_72 , & V_2 -> V_5 -> V_30 . V_31 ) ;
if ( F_18 ( V_57 ) < V_73 )
F_19 ( & V_2 -> V_20 ) ;
if ( F_15 ( V_57 ) )
F_20 ( & V_2 -> V_20 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
union V_12 * V_13 )
{
if ( V_13 -> V_22 . V_23 & V_74 )
F_22 ( & V_2 -> V_20 ,
! ( F_2 ( & V_2 -> V_5 -> V_6 . V_75 ) & V_76 ) ) ;
if ( V_13 -> V_22 . V_35 & V_77 )
F_23 ( & V_2 -> V_20 ,
( F_2 ( & V_2 -> V_5 -> V_6 . V_7 ) & V_78 ) ) ;
if ( ( F_2 ( & V_2 -> V_5 -> V_6 . V_79 ) & V_2 -> V_80 ) ^ V_2 -> V_81 ) {
V_2 -> V_81 = ( F_2 ( & V_2 -> V_5 -> V_6 . V_79 ) & V_2 -> V_80 ) ? 0 : 1 ;
V_2 -> V_20 . V_42 . V_81 ++ ;
}
F_24 ( & V_2 -> V_20 . V_21 -> V_20 . V_82 ) ;
}
static T_2 F_25 ( int V_83 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
struct V_11 * V_14 ;
union V_12 V_85 ;
unsigned long V_86 ;
unsigned char V_87 ;
F_26 ( & V_2 -> V_20 . V_88 , V_86 ) ;
V_85 . V_13 = 0 ;
V_87 = F_2 ( & V_2 -> V_5 -> V_6 . V_87 ) >> V_2 -> V_89 ;
if ( V_87 & 1 )
V_85 . V_22 . V_23 = F_2 ( & V_2 -> V_5 -> V_6 . V_23 ) ;
if ( V_87 & 2 )
V_85 . V_22 . V_35 = F_2 ( & V_2 -> V_5 -> V_6 . V_35 ) ;
V_14 = NULL ;
if ( V_85 . V_13 ) {
if ( ( V_85 . V_22 . V_23 & ( V_26 | V_28 |
V_32 | V_24 ) ) ||
( V_85 . V_22 . V_35 & V_36 ) )
V_14 = F_5 ( V_2 , & V_85 ) ;
if ( ( V_85 . V_22 . V_23 & V_74 ) ||
( V_85 . V_22 . V_35 & V_77 ) )
F_21 ( V_2 , & V_85 ) ;
if ( V_85 . V_22 . V_35 & ( V_58 | V_90 ) )
F_12 ( V_2 , & V_85 ) ;
}
F_27 ( & V_2 -> V_20 . V_88 , V_86 ) ;
if ( V_14 )
F_28 ( V_14 ) ;
return V_91 ;
}
static unsigned int F_29 ( struct V_92 * V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
int V_93 ;
if ( F_30 ( V_62 , & V_2 -> V_63 ) )
V_93 = V_94 ;
else
V_93 = 0 ;
return V_93 ;
}
static void F_31 ( struct V_92 * V_20 , unsigned int V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
if ( V_95 & V_96 ) {
V_2 -> V_97 &= ~ V_98 ;
V_2 -> V_97 |= V_99 ;
} else {
V_2 -> V_97 |= ( V_98 |
V_99 ) ;
}
if ( V_95 & V_100 ) {
V_2 -> V_101 &= ~ ( V_2 -> V_102 ) ;
} else {
V_2 -> V_101 |= V_2 -> V_102 ;
}
F_13 ( V_103 , & V_2 -> V_63 ) ;
if ( F_30 ( V_65 , & V_2 -> V_63 ) )
F_14 ( V_2 ) ;
}
static unsigned int F_32 ( struct V_92 * V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
unsigned char V_104 ;
unsigned int V_105 ;
V_105 = 0 ;
V_104 = F_2 ( & V_2 -> V_5 -> V_6 . V_79 ) ;
V_105 |= ( V_104 & V_2 -> V_80 ) ? 0 : V_106 ;
V_104 = F_2 ( & V_2 -> V_5 -> V_6 . V_75 ) ;
V_105 |= ( V_104 & V_76 ) ? 0 : V_107 ;
V_104 = F_2 ( & V_2 -> V_5 -> V_6 . V_7 ) ;
V_105 |= ( V_104 & V_78 ) ? V_108 : 0 ;
return V_105 ;
}
static void F_20 ( struct V_92 * V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
V_2 -> V_59 |= V_66 ;
F_6 ( V_2 -> V_59 , & V_2 -> V_5 -> V_30 . V_61 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( F_30 ( V_103 , & V_2 -> V_63 ) ) {
T_3 V_109 ;
F_17 ( V_103 , & V_2 -> V_63 ) ;
F_6 ( V_2 -> V_97 , & V_2 -> V_5 -> V_110 . V_111 ) ;
F_6 ( V_2 -> V_101 , & V_2 -> V_5 -> V_110 . V_79 ) ;
F_6 ( V_2 -> V_112 , & V_2 -> V_5 -> V_30 . V_113 ) ;
F_6 ( V_2 -> V_114 & 0xff , & V_2 -> V_5 -> V_30 . V_115 ) ;
V_109 = F_2 ( & V_2 -> V_5 -> V_110 . V_116 ) ;
V_109 &= ~ 0xc0 ;
V_109 |= ( V_2 -> V_114 >> 2 ) & 0xc0 ;
F_6 ( V_109 , & V_2 -> V_5 -> V_110 . V_116 ) ;
}
}
static void F_33 ( struct V_92 * V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
struct V_56 * V_57 = & V_2 -> V_20 . V_21 -> V_57 ;
int V_19 ;
V_2 -> V_59 &= ~ ( V_60 | V_66 ) ;
F_6 ( V_2 -> V_59 , & V_2 -> V_5 -> V_30 . V_61 ) ;
if ( ! F_30 ( V_65 , & V_2 -> V_63 ) )
return;
F_17 ( V_62 , & V_2 -> V_63 ) ;
F_17 ( V_65 , & V_2 -> V_63 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 . V_67 ; V_19 ++ ) {
F_6 ( V_57 -> V_15 [ V_57 -> V_68 ] ,
& V_2 -> V_5 -> V_30 . V_69 [ V_19 ] ) ;
V_57 -> V_68 = ( V_57 -> V_68 + 1 ) & ( V_70 - 1 ) ;
V_2 -> V_20 . V_42 . V_71 ++ ;
if ( F_15 ( V_57 ) )
break;
}
F_4 ( V_2 ) ;
F_6 ( V_72 , & V_2 -> V_5 -> V_30 . V_31 ) ;
}
static void F_34 ( struct V_92 * V_20 , char V_39 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
unsigned long V_86 ;
F_26 ( & V_2 -> V_20 . V_88 , V_86 ) ;
F_1 ( V_2 ) ;
F_6 ( V_39 , & V_2 -> V_5 -> V_30 . V_117 ) ;
F_27 ( & V_2 -> V_20 . V_88 , V_86 ) ;
}
static void F_35 ( struct V_92 * V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
V_2 -> V_118 |= V_119 ;
F_6 ( V_2 -> V_59 , & V_2 -> V_5 -> V_30 . V_120 ) ;
}
static void F_36 ( struct V_92 * V_20 )
{
}
static void F_37 ( struct V_92 * V_20 , int V_121 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
unsigned long V_86 ;
unsigned char V_104 ;
F_26 ( & V_2 -> V_20 . V_88 , V_86 ) ;
V_104 = V_2 -> V_112 ;
if ( V_121 )
V_104 |= V_122 ;
else
V_104 &= ~ V_122 ;
V_2 -> V_112 = V_104 ;
F_13 ( V_103 , & V_2 -> V_63 ) ;
if ( F_30 ( V_65 , & V_2 -> V_63 ) )
F_14 ( V_2 ) ;
F_27 ( & V_2 -> V_20 . V_88 , V_86 ) ;
}
static int F_38 ( struct V_92 * V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
unsigned long V_86 ;
unsigned char V_109 ;
int V_123 = F_39 ( V_2 -> V_20 . V_83 , F_25 ,
V_124 , L_1 , V_2 ) ;
if ( V_123 )
return V_123 ;
F_26 ( & V_2 -> V_20 . V_88 , V_86 ) ;
F_4 ( V_2 ) ;
F_1 ( V_2 ) ;
F_6 ( V_125 , & V_2 -> V_5 -> V_30 . V_31 ) ;
F_4 ( V_2 ) ;
F_6 ( V_126 , & V_2 -> V_5 -> V_30 . V_31 ) ;
( void ) F_2 ( & V_2 -> V_5 -> V_6 . V_23 ) ;
( void ) F_2 ( & V_2 -> V_5 -> V_6 . V_35 ) ;
F_6 ( 0 , & V_2 -> V_5 -> V_30 . V_127 ) ;
F_6 ( V_128 | V_129 |
V_130 , & V_2 -> V_5 -> V_30 . V_127 ) ;
F_6 ( V_131 | V_132 | 7 , & V_2 -> V_5 -> V_30 . V_133 ) ;
F_6 ( V_134 | V_135 |
V_136 , & V_2 -> V_5 -> V_30 . V_116 ) ;
F_6 ( 0 , & V_2 -> V_5 -> V_30 . V_137 ) ;
F_6 ( V_138 | V_139 , & V_2 -> V_5 -> V_30 . V_140 ) ;
V_2 -> V_97 = ( V_99 | V_141 |
V_142 ) ;
F_6 ( V_2 -> V_97 , & V_2 -> V_5 -> V_30 . V_111 ) ;
F_6 ( V_143 | V_144 , & V_2 -> V_5 -> V_30 . V_145 ) ;
V_109 = F_2 ( & V_2 -> V_5 -> V_110 . V_127 ) ;
V_109 |= V_146 ;
F_6 ( V_109 , & V_2 -> V_5 -> V_110 . V_127 ) ;
V_2 -> V_118 = ( V_147 | V_148 |
V_149 ) ;
F_6 ( V_2 -> V_118 , & V_2 -> V_5 -> V_30 . V_120 ) ;
V_2 -> V_59 = ( V_150 | V_60 |
V_151 | V_152 |
V_153 | V_154 |
V_66 ) ;
F_6 ( V_2 -> V_59 , & V_2 -> V_5 -> V_30 . V_61 ) ;
F_13 ( V_62 , & V_2 -> V_63 ) ;
F_13 ( V_65 , & V_2 -> V_63 ) ;
F_27 ( & V_2 -> V_20 . V_88 , V_86 ) ;
return 0 ;
}
static void F_40 ( struct V_92 * V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
unsigned long V_86 ;
F_26 ( & V_2 -> V_20 . V_88 , V_86 ) ;
V_2 -> V_118 = 0xff ;
F_6 ( V_2 -> V_118 , & V_2 -> V_5 -> V_30 . V_120 ) ;
V_2 -> V_59 = 0xff ;
F_6 ( V_2 -> V_59 , & V_2 -> V_5 -> V_30 . V_61 ) ;
V_2 -> V_112 = F_2 ( & V_2 -> V_5 -> V_110 . V_113 ) ;
V_2 -> V_112 &= ~ V_122 ;
F_6 ( V_2 -> V_112 , & V_2 -> V_5 -> V_110 . V_113 ) ;
V_2 -> V_97 &= ~ V_142 ;
F_6 ( V_2 -> V_97 , & V_2 -> V_5 -> V_110 . V_111 ) ;
#if 0
tmp = readb(&up->regs->rw.ccr0);
tmp &= ~SAB82532_CCR0_PU;
writeb(tmp, &up->regs->rw.ccr0);
#endif
F_27 ( & V_2 -> V_20 . V_88 , V_86 ) ;
F_41 ( V_2 -> V_20 . V_83 , V_2 ) ;
}
static void F_42 ( int V_155 , int * V_156 , int * V_157 )
{
int V_158 , V_159 ;
if ( V_155 == 0 ) {
* V_156 = 0 ;
* V_157 = 0 ;
return;
}
V_158 = ( V_160 * 10 ) / V_155 ;
V_159 = 0 ;
while ( V_158 >= 640 ) {
V_158 = V_158 / 2 ;
V_159 ++ ;
}
V_158 = ( V_158 + 5 ) / 10 ;
if ( ( V_159 == 0 ) && ( ( V_158 & 1 ) == 0 ) ) {
V_158 = V_158 / 2 ;
V_159 ++ ;
}
* V_156 = V_158 - 1 ;
* V_157 = V_159 ;
}
static void F_43 ( struct V_1 * V_2 , unsigned int V_161 ,
unsigned int V_162 , unsigned int V_155 ,
unsigned int V_163 )
{
unsigned char V_113 ;
int V_164 , V_158 , V_159 ;
switch ( V_161 & V_165 ) {
case V_166 : V_113 = V_167 ; V_164 = 7 ; break;
case V_168 : V_113 = V_169 ; V_164 = 8 ; break;
case V_170 : V_113 = V_171 ; V_164 = 9 ; break;
case V_172 : V_113 = V_173 ; V_164 = 10 ; break;
default: V_113 = V_167 ; V_164 = 7 ; break;
}
if ( V_161 & V_174 ) {
V_113 |= V_175 ;
V_164 ++ ;
}
if ( V_161 & V_176 ) {
V_113 |= V_177 ;
V_164 ++ ;
}
if ( V_161 & V_178 ) {
V_113 |= V_179 ;
} else {
V_113 |= V_180 ;
}
V_2 -> V_112 = V_113 ;
F_42 ( V_155 , & V_158 , & V_159 ) ;
V_2 -> V_114 = V_158 | ( V_159 << 6 ) ;
V_2 -> V_4 = ( 10 * 1000000 ) / V_155 ;
V_2 -> V_9 = V_2 -> V_4 >> 2 ;
V_2 -> V_20 . V_50 = ( V_26 | V_28 |
V_32 | V_24 |
V_74 ) ;
V_2 -> V_20 . V_50 |= ( V_77 |
V_58 |
V_90 ) << 8 ;
if ( V_162 & V_181 )
V_2 -> V_20 . V_50 |= ( V_44 |
V_45 ) ;
if ( V_162 & ( V_182 | V_183 ) )
V_2 -> V_20 . V_50 |= ( V_36 << 8 ) ;
V_2 -> V_20 . V_54 = 0 ;
if ( V_162 & V_184 )
V_2 -> V_20 . V_54 |= ( V_44 |
V_45 ) ;
if ( V_162 & V_185 ) {
V_2 -> V_20 . V_54 |= ( V_36 << 8 ) ;
if ( V_162 & V_184 )
V_2 -> V_20 . V_54 |= V_32 ;
}
if ( ( V_161 & V_186 ) == 0 )
V_2 -> V_20 . V_54 |= ( V_24 |
V_26 ) ;
F_44 ( & V_2 -> V_20 , V_161 ,
( V_2 -> V_20 . V_187 / ( 16 * V_163 ) ) ) ;
V_2 -> V_97 |= V_142 ;
F_13 ( V_103 , & V_2 -> V_63 ) ;
if ( F_30 ( V_65 , & V_2 -> V_63 ) )
F_14 ( V_2 ) ;
}
static void F_45 ( struct V_92 * V_20 , struct V_188 * V_189 ,
struct V_188 * V_190 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
unsigned long V_86 ;
unsigned int V_155 = F_46 ( V_20 , V_189 , V_190 , 0 , 4000000 ) ;
unsigned int V_163 = F_47 ( V_20 , V_155 ) ;
F_26 ( & V_2 -> V_20 . V_88 , V_86 ) ;
F_43 ( V_2 , V_189 -> V_191 , V_189 -> V_192 , V_155 , V_163 ) ;
F_27 ( & V_2 -> V_20 . V_88 , V_86 ) ;
}
static const char * F_48 ( struct V_92 * V_20 )
{
struct V_1 * V_2 = ( void * ) V_20 ;
static char V_15 [ 36 ] ;
sprintf ( V_15 , L_2 , V_193 [ V_2 -> type ] ) ;
return V_15 ;
}
static void F_49 ( struct V_92 * V_20 )
{
}
static int F_50 ( struct V_92 * V_20 )
{
return 0 ;
}
static void F_51 ( struct V_92 * V_20 , int V_86 )
{
}
static int F_52 ( struct V_92 * V_20 , struct V_194 * V_195 )
{
return - V_196 ;
}
static void F_53 ( struct V_92 * V_20 , int V_197 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
F_1 ( V_2 ) ;
F_6 ( V_197 , & V_2 -> V_5 -> V_30 . V_117 ) ;
}
static void F_54 ( struct V_198 * V_199 , const char * V_200 , unsigned V_158 )
{
struct V_1 * V_2 = & V_201 [ V_199 -> V_38 ] ;
unsigned long V_86 ;
int V_202 = 1 ;
F_55 ( V_86 ) ;
if ( V_2 -> V_20 . V_203 ) {
V_202 = 0 ;
} else if ( V_204 ) {
V_202 = F_56 ( & V_2 -> V_20 . V_88 ) ;
} else
F_57 ( & V_2 -> V_20 . V_88 ) ;
F_58 ( & V_2 -> V_20 , V_200 , V_158 , F_53 ) ;
F_1 ( V_2 ) ;
if ( V_202 )
F_59 ( & V_2 -> V_20 . V_88 ) ;
F_60 ( V_86 ) ;
}
static int F_61 ( struct V_198 * V_199 , char * V_205 )
{
struct V_1 * V_2 = & V_201 [ V_199 -> V_38 ] ;
unsigned long V_86 ;
unsigned int V_155 , V_163 ;
if ( V_2 -> V_20 . type != V_206 )
return - 1 ;
F_62 ( L_3 ,
( V_207 . V_208 - 64 ) + V_199 -> V_38 ) ;
F_63 ( V_199 , V_2 -> V_20 . V_209 -> V_210 ) ;
switch ( V_199 -> V_161 & V_211 ) {
case V_212 : V_155 = 150 ; break;
case V_213 : V_155 = 300 ; break;
case V_214 : V_155 = 600 ; break;
case V_215 : V_155 = 1200 ; break;
case V_216 : V_155 = 2400 ; break;
case V_217 : V_155 = 4800 ; break;
default: case V_218 : V_155 = 9600 ; break;
case V_219 : V_155 = 19200 ; break;
case V_220 : V_155 = 38400 ; break;
case V_221 : V_155 = 57600 ; break;
case V_222 : V_155 = 115200 ; break;
case V_223 : V_155 = 230400 ; break;
case V_224 : V_155 = 460800 ; break;
} ;
F_64 ( & V_2 -> V_20 . V_88 ) ;
F_38 ( & V_2 -> V_20 ) ;
F_26 ( & V_2 -> V_20 . V_88 , V_86 ) ;
V_2 -> V_118 = V_147 | V_148 |
V_149 | V_225 ;
F_6 ( V_2 -> V_118 , & V_2 -> V_5 -> V_30 . V_120 ) ;
V_2 -> V_59 = V_150 | V_60 |
V_151 | V_152 |
V_153 | V_154 |
V_66 ;
F_6 ( V_2 -> V_59 , & V_2 -> V_5 -> V_30 . V_61 ) ;
V_163 = F_47 ( & V_2 -> V_20 , V_155 ) ;
F_43 ( V_2 , V_199 -> V_161 , 0 , V_155 , V_163 ) ;
F_31 ( & V_2 -> V_20 , V_100 | V_96 ) ;
F_27 ( & V_2 -> V_20 . V_88 , V_86 ) ;
return 0 ;
}
static inline struct V_198 * F_65 ( void )
{
return & V_226 ;
}
static int T_4 F_66 ( struct V_1 * V_2 ,
struct V_227 * V_228 ,
unsigned long V_229 ,
int line )
{
V_2 -> V_20 . line = line ;
V_2 -> V_20 . V_209 = & V_228 -> V_209 ;
V_2 -> V_20 . V_230 = V_228 -> V_231 [ 0 ] . V_232 + V_229 ;
V_2 -> V_20 . V_233 = F_67 ( & V_228 -> V_231 [ 0 ] , V_229 ,
sizeof( union V_234 ) ,
L_1 ) ;
if ( ! V_2 -> V_20 . V_233 )
return - V_235 ;
V_2 -> V_5 = (union V_234 V_236 * ) V_2 -> V_20 . V_233 ;
V_2 -> V_20 . V_83 = V_228 -> V_237 . V_238 [ 0 ] ;
V_2 -> V_20 . V_67 = V_239 ;
V_2 -> V_20 . V_240 = V_241 ;
F_6 ( V_242 , & V_2 -> V_5 -> V_30 . V_243 ) ;
V_2 -> V_20 . V_244 = & V_245 ;
V_2 -> V_20 . type = V_206 ;
V_2 -> V_20 . V_187 = V_160 ;
V_2 -> type = F_2 ( & V_2 -> V_5 -> V_6 . V_75 ) & 0x0f ;
F_6 ( ~ ( ( 1 << 1 ) | ( 1 << 2 ) | ( 1 << 4 ) ) , & V_2 -> V_5 -> V_30 . V_246 ) ;
F_6 ( 0xff , & V_2 -> V_5 -> V_30 . V_247 ) ;
if ( ( V_2 -> V_20 . line & 0x1 ) == 0 ) {
V_2 -> V_80 = ( 1 << 0 ) ;
V_2 -> V_102 = ( 1 << 1 ) ;
V_2 -> V_89 = 2 ;
} else {
V_2 -> V_80 = ( 1 << 3 ) ;
V_2 -> V_102 = ( 1 << 2 ) ;
V_2 -> V_89 = 0 ;
}
V_2 -> V_101 = ( 1 << 1 ) | ( 1 << 2 ) | ( 1 << 4 ) ;
F_6 ( V_2 -> V_101 , & V_2 -> V_5 -> V_30 . V_79 ) ;
V_2 -> V_97 = F_2 ( & V_2 -> V_5 -> V_110 . V_111 ) ;
V_2 -> V_97 |= V_98 ;
F_6 ( V_2 -> V_97 , & V_2 -> V_5 -> V_110 . V_111 ) ;
V_2 -> V_97 |= V_99 ;
F_6 ( V_2 -> V_97 , & V_2 -> V_5 -> V_110 . V_111 ) ;
V_2 -> V_4 = V_248 ;
V_2 -> V_9 = V_249 ;
return 0 ;
}
static int T_4 F_68 ( struct V_227 * V_228 )
{
static int V_250 ;
struct V_1 * V_2 ;
int V_123 ;
V_2 = & V_201 [ V_250 * 2 ] ;
V_123 = F_66 ( & V_2 [ 0 ] , V_228 ,
0 ,
( V_250 * 2 ) + 0 ) ;
if ( V_123 )
goto V_251;
V_123 = F_66 ( & V_2 [ 1 ] , V_228 ,
sizeof( union V_234 ) ,
( V_250 * 2 ) + 1 ) ;
if ( V_123 )
goto V_252;
F_69 ( F_65 () , V_228 -> V_209 . V_210 ,
& V_207 , V_2 [ 0 ] . V_20 . line ,
false ) ;
F_69 ( F_65 () , V_228 -> V_209 . V_210 ,
& V_207 , V_2 [ 1 ] . V_20 . line ,
false ) ;
V_123 = F_70 ( & V_207 , & V_2 [ 0 ] . V_20 ) ;
if ( V_123 )
goto V_253;
V_123 = F_70 ( & V_207 , & V_2 [ 1 ] . V_20 ) ;
if ( V_123 )
goto V_254;
F_71 ( & V_228 -> V_209 , & V_2 [ 0 ] ) ;
V_250 ++ ;
return 0 ;
V_254:
F_72 ( & V_207 , & V_2 [ 0 ] . V_20 ) ;
V_253:
F_73 ( & V_228 -> V_231 [ 0 ] ,
V_2 [ 1 ] . V_20 . V_233 ,
sizeof( union V_234 ) ) ;
V_252:
F_73 ( & V_228 -> V_231 [ 0 ] ,
V_2 [ 0 ] . V_20 . V_233 ,
sizeof( union V_234 ) ) ;
V_251:
return V_123 ;
}
static int T_5 F_74 ( struct V_227 * V_228 )
{
struct V_1 * V_2 = F_75 ( & V_228 -> V_209 ) ;
F_72 ( & V_207 , & V_2 [ 1 ] . V_20 ) ;
F_72 ( & V_207 , & V_2 [ 0 ] . V_20 ) ;
F_73 ( & V_228 -> V_231 [ 0 ] ,
V_2 [ 1 ] . V_20 . V_233 ,
sizeof( union V_234 ) ) ;
F_73 ( & V_228 -> V_231 [ 0 ] ,
V_2 [ 0 ] . V_20 . V_233 ,
sizeof( union V_234 ) ) ;
F_71 ( & V_228 -> V_209 , NULL ) ;
return 0 ;
}
static int T_6 F_76 ( void )
{
struct V_255 * V_256 ;
int V_123 ;
int V_257 = 0 ;
F_77 (dp, L_4 )
V_257 += 2 ;
F_77 (dp, L_5 ) {
if ( F_78 ( V_256 , L_6 ) )
V_257 += 2 ;
}
if ( V_257 ) {
V_201 = F_79 ( sizeof( struct V_1 ) *
V_257 , V_258 ) ;
if ( ! V_201 )
return - V_235 ;
V_123 = F_80 ( & V_207 , V_257 ) ;
if ( V_123 ) {
F_81 ( V_201 ) ;
V_201 = NULL ;
return V_123 ;
}
}
return F_82 ( & V_259 ) ;
}
static void T_7 F_83 ( void )
{
F_84 ( & V_259 ) ;
if ( V_207 . V_260 ) {
F_85 ( & V_207 , V_207 . V_260 ) ;
}
F_81 ( V_201 ) ;
V_201 = NULL ;
}

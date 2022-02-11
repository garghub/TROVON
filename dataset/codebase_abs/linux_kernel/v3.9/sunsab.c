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
if ( V_2 -> V_14 . V_20 != NULL )
V_14 = & V_2 -> V_14 . V_20 -> V_14 ;
if ( V_13 -> V_21 . V_22 & V_23 ) {
V_18 = V_24 ;
V_17 ++ ;
}
if ( V_13 -> V_21 . V_22 & V_25 ) {
V_18 = F_2 ( & V_2 -> V_5 -> V_6 . V_26 ) & ( V_24 - 1 ) ;
V_17 ++ ;
}
if ( V_13 -> V_21 . V_22 & V_27 ) {
F_4 ( V_2 ) ;
F_6 ( V_28 , & V_2 -> V_5 -> V_29 . V_30 ) ;
return V_14 ;
}
if ( V_13 -> V_21 . V_22 & V_31 )
V_17 ++ ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ )
V_15 [ V_19 ] = F_2 ( & V_2 -> V_5 -> V_6 . V_32 [ V_19 ] ) ;
if ( V_17 ) {
F_4 ( V_2 ) ;
F_6 ( V_33 , & V_2 -> V_5 -> V_29 . V_30 ) ;
}
if ( ( V_13 -> V_21 . V_34 & V_35 ) &&
( V_2 -> V_14 . line == V_2 -> V_14 . V_36 -> V_37 ) )
V_16 = 1 ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
unsigned char V_38 = V_15 [ V_19 ] , V_39 ;
V_39 = V_40 ;
V_2 -> V_14 . V_41 . V_42 ++ ;
if ( F_7 ( V_13 -> V_21 . V_22 & ( V_43 |
V_44 |
V_31 ) ) ||
F_7 ( V_13 -> V_21 . V_34 & V_35 ) ) {
if ( V_13 -> V_21 . V_34 & V_35 ) {
V_13 -> V_21 . V_22 &= ~ ( V_43 |
V_44 ) ;
V_2 -> V_14 . V_41 . V_45 ++ ;
if ( F_8 ( & V_2 -> V_14 ) )
continue;
} else if ( V_13 -> V_21 . V_22 & V_43 )
V_2 -> V_14 . V_41 . V_46 ++ ;
else if ( V_13 -> V_21 . V_22 & V_44 )
V_2 -> V_14 . V_41 . V_47 ++ ;
if ( V_13 -> V_21 . V_22 & V_31 )
V_2 -> V_14 . V_41 . V_48 ++ ;
V_13 -> V_21 . V_22 &= ( V_2 -> V_14 . V_49 & 0xff ) ;
V_13 -> V_21 . V_34 &= ( ( V_2 -> V_14 . V_49 >> 8 ) & 0xff ) ;
if ( V_13 -> V_21 . V_34 & V_35 ) {
V_39 = V_50 ;
} else if ( V_13 -> V_21 . V_22 & V_43 )
V_39 = V_51 ;
else if ( V_13 -> V_21 . V_22 & V_44 )
V_39 = V_52 ;
}
if ( F_9 ( & V_2 -> V_14 , V_38 ) )
continue;
if ( ( V_13 -> V_21 . V_22 & ( V_2 -> V_14 . V_53 & 0xff ) ) == 0 &&
( V_13 -> V_21 . V_34 & ( ( V_2 -> V_14 . V_53 >> 8 ) & 0xff ) ) == 0 )
F_10 ( V_14 , V_38 , V_39 ) ;
if ( V_13 -> V_21 . V_22 & V_31 )
F_10 ( V_14 , 0 , V_54 ) ;
}
if ( V_16 )
F_11 () ;
return V_14 ;
}
static void F_12 ( struct V_1 * V_2 ,
union V_12 * V_13 )
{
struct V_55 * V_56 = & V_2 -> V_14 . V_20 -> V_56 ;
int V_19 ;
if ( V_13 -> V_21 . V_34 & V_57 ) {
V_2 -> V_58 |= V_59 ;
F_6 ( V_2 -> V_58 , & V_2 -> V_5 -> V_29 . V_60 ) ;
F_13 ( V_61 , & V_2 -> V_62 ) ;
}
#if 0
if (!(stat->sreg.isr1 & SAB82532_ISR1_XPR))
return;
#endif
if ( ! ( F_2 ( & V_2 -> V_5 -> V_6 . V_7 ) & V_63 ) )
return;
F_13 ( V_64 , & V_2 -> V_62 ) ;
F_14 ( V_2 ) ;
if ( F_15 ( V_56 ) || F_16 ( & V_2 -> V_14 ) ) {
V_2 -> V_58 |= V_65 ;
F_6 ( V_2 -> V_58 , & V_2 -> V_5 -> V_29 . V_60 ) ;
return;
}
V_2 -> V_58 &= ~ ( V_59 | V_65 ) ;
F_6 ( V_2 -> V_58 , & V_2 -> V_5 -> V_29 . V_60 ) ;
F_17 ( V_61 , & V_2 -> V_62 ) ;
F_17 ( V_64 , & V_2 -> V_62 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_14 . V_66 ; V_19 ++ ) {
F_6 ( V_56 -> V_15 [ V_56 -> V_67 ] ,
& V_2 -> V_5 -> V_29 . V_68 [ V_19 ] ) ;
V_56 -> V_67 = ( V_56 -> V_67 + 1 ) & ( V_69 - 1 ) ;
V_2 -> V_14 . V_41 . V_70 ++ ;
if ( F_15 ( V_56 ) )
break;
}
F_4 ( V_2 ) ;
F_6 ( V_71 , & V_2 -> V_5 -> V_29 . V_30 ) ;
if ( F_18 ( V_56 ) < V_72 )
F_19 ( & V_2 -> V_14 ) ;
if ( F_15 ( V_56 ) )
F_20 ( & V_2 -> V_14 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
union V_12 * V_13 )
{
if ( V_13 -> V_21 . V_22 & V_73 )
F_22 ( & V_2 -> V_14 ,
! ( F_2 ( & V_2 -> V_5 -> V_6 . V_74 ) & V_75 ) ) ;
if ( V_13 -> V_21 . V_34 & V_76 )
F_23 ( & V_2 -> V_14 ,
( F_2 ( & V_2 -> V_5 -> V_6 . V_7 ) & V_77 ) ) ;
if ( ( F_2 ( & V_2 -> V_5 -> V_6 . V_78 ) & V_2 -> V_79 ) ^ V_2 -> V_80 ) {
V_2 -> V_80 = ( F_2 ( & V_2 -> V_5 -> V_6 . V_78 ) & V_2 -> V_79 ) ? 0 : 1 ;
V_2 -> V_14 . V_41 . V_80 ++ ;
}
F_24 ( & V_2 -> V_14 . V_20 -> V_14 . V_81 ) ;
}
static T_2 F_25 ( int V_82 , void * V_83 )
{
struct V_1 * V_2 = V_83 ;
struct V_11 * V_14 = NULL ;
union V_12 V_84 ;
unsigned long V_85 ;
unsigned char V_86 ;
F_26 ( & V_2 -> V_14 . V_87 , V_85 ) ;
V_84 . V_13 = 0 ;
V_86 = F_2 ( & V_2 -> V_5 -> V_6 . V_86 ) >> V_2 -> V_88 ;
if ( V_86 & 1 )
V_84 . V_21 . V_22 = F_2 ( & V_2 -> V_5 -> V_6 . V_22 ) ;
if ( V_86 & 2 )
V_84 . V_21 . V_34 = F_2 ( & V_2 -> V_5 -> V_6 . V_34 ) ;
if ( V_84 . V_13 ) {
if ( ( V_84 . V_21 . V_22 & ( V_25 | V_27 |
V_31 | V_23 ) ) ||
( V_84 . V_21 . V_34 & V_35 ) )
V_14 = F_5 ( V_2 , & V_84 ) ;
if ( ( V_84 . V_21 . V_22 & V_73 ) ||
( V_84 . V_21 . V_34 & V_76 ) )
F_21 ( V_2 , & V_84 ) ;
if ( V_84 . V_21 . V_34 & ( V_57 | V_89 ) )
F_12 ( V_2 , & V_84 ) ;
}
F_27 ( & V_2 -> V_14 . V_87 , V_85 ) ;
if ( V_14 )
F_28 ( V_14 ) ;
return V_90 ;
}
static unsigned int F_29 ( struct V_91 * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
int V_92 ;
if ( F_30 ( V_61 , & V_2 -> V_62 ) )
V_92 = V_93 ;
else
V_92 = 0 ;
return V_92 ;
}
static void F_31 ( struct V_91 * V_14 , unsigned int V_94 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
if ( V_94 & V_95 ) {
V_2 -> V_96 &= ~ V_97 ;
V_2 -> V_96 |= V_98 ;
} else {
V_2 -> V_96 |= ( V_97 |
V_98 ) ;
}
if ( V_94 & V_99 ) {
V_2 -> V_100 &= ~ ( V_2 -> V_101 ) ;
} else {
V_2 -> V_100 |= V_2 -> V_101 ;
}
F_13 ( V_102 , & V_2 -> V_62 ) ;
if ( F_30 ( V_64 , & V_2 -> V_62 ) )
F_14 ( V_2 ) ;
}
static unsigned int F_32 ( struct V_91 * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
unsigned char V_103 ;
unsigned int V_104 ;
V_104 = 0 ;
V_103 = F_2 ( & V_2 -> V_5 -> V_6 . V_78 ) ;
V_104 |= ( V_103 & V_2 -> V_79 ) ? 0 : V_105 ;
V_103 = F_2 ( & V_2 -> V_5 -> V_6 . V_74 ) ;
V_104 |= ( V_103 & V_75 ) ? 0 : V_106 ;
V_103 = F_2 ( & V_2 -> V_5 -> V_6 . V_7 ) ;
V_104 |= ( V_103 & V_77 ) ? V_107 : 0 ;
return V_104 ;
}
static void F_20 ( struct V_91 * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
V_2 -> V_58 |= V_65 ;
F_6 ( V_2 -> V_58 , & V_2 -> V_5 -> V_29 . V_60 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( F_30 ( V_102 , & V_2 -> V_62 ) ) {
T_3 V_108 ;
F_17 ( V_102 , & V_2 -> V_62 ) ;
F_6 ( V_2 -> V_96 , & V_2 -> V_5 -> V_109 . V_110 ) ;
F_6 ( V_2 -> V_100 , & V_2 -> V_5 -> V_109 . V_78 ) ;
F_6 ( V_2 -> V_111 , & V_2 -> V_5 -> V_29 . V_112 ) ;
F_6 ( V_2 -> V_113 & 0xff , & V_2 -> V_5 -> V_29 . V_114 ) ;
V_108 = F_2 ( & V_2 -> V_5 -> V_109 . V_115 ) ;
V_108 &= ~ 0xc0 ;
V_108 |= ( V_2 -> V_113 >> 2 ) & 0xc0 ;
F_6 ( V_108 , & V_2 -> V_5 -> V_109 . V_115 ) ;
}
}
static void F_33 ( struct V_91 * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
struct V_55 * V_56 = & V_2 -> V_14 . V_20 -> V_56 ;
int V_19 ;
V_2 -> V_58 &= ~ ( V_59 | V_65 ) ;
F_6 ( V_2 -> V_58 , & V_2 -> V_5 -> V_29 . V_60 ) ;
if ( ! F_30 ( V_64 , & V_2 -> V_62 ) )
return;
F_17 ( V_61 , & V_2 -> V_62 ) ;
F_17 ( V_64 , & V_2 -> V_62 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_14 . V_66 ; V_19 ++ ) {
F_6 ( V_56 -> V_15 [ V_56 -> V_67 ] ,
& V_2 -> V_5 -> V_29 . V_68 [ V_19 ] ) ;
V_56 -> V_67 = ( V_56 -> V_67 + 1 ) & ( V_69 - 1 ) ;
V_2 -> V_14 . V_41 . V_70 ++ ;
if ( F_15 ( V_56 ) )
break;
}
F_4 ( V_2 ) ;
F_6 ( V_71 , & V_2 -> V_5 -> V_29 . V_30 ) ;
}
static void F_34 ( struct V_91 * V_14 , char V_38 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
unsigned long V_85 ;
F_26 ( & V_2 -> V_14 . V_87 , V_85 ) ;
F_1 ( V_2 ) ;
F_6 ( V_38 , & V_2 -> V_5 -> V_29 . V_116 ) ;
F_27 ( & V_2 -> V_14 . V_87 , V_85 ) ;
}
static void F_35 ( struct V_91 * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
V_2 -> V_117 |= V_118 ;
F_6 ( V_2 -> V_58 , & V_2 -> V_5 -> V_29 . V_119 ) ;
}
static void F_36 ( struct V_91 * V_14 )
{
}
static void F_37 ( struct V_91 * V_14 , int V_120 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
unsigned long V_85 ;
unsigned char V_103 ;
F_26 ( & V_2 -> V_14 . V_87 , V_85 ) ;
V_103 = V_2 -> V_111 ;
if ( V_120 )
V_103 |= V_121 ;
else
V_103 &= ~ V_121 ;
V_2 -> V_111 = V_103 ;
F_13 ( V_102 , & V_2 -> V_62 ) ;
if ( F_30 ( V_64 , & V_2 -> V_62 ) )
F_14 ( V_2 ) ;
F_27 ( & V_2 -> V_14 . V_87 , V_85 ) ;
}
static int F_38 ( struct V_91 * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
unsigned long V_85 ;
unsigned char V_108 ;
int V_122 = F_39 ( V_2 -> V_14 . V_82 , F_25 ,
V_123 , L_1 , V_2 ) ;
if ( V_122 )
return V_122 ;
F_26 ( & V_2 -> V_14 . V_87 , V_85 ) ;
F_4 ( V_2 ) ;
F_1 ( V_2 ) ;
F_6 ( V_124 , & V_2 -> V_5 -> V_29 . V_30 ) ;
F_4 ( V_2 ) ;
F_6 ( V_125 , & V_2 -> V_5 -> V_29 . V_30 ) ;
( void ) F_2 ( & V_2 -> V_5 -> V_6 . V_22 ) ;
( void ) F_2 ( & V_2 -> V_5 -> V_6 . V_34 ) ;
F_6 ( 0 , & V_2 -> V_5 -> V_29 . V_126 ) ;
F_6 ( V_127 | V_128 |
V_129 , & V_2 -> V_5 -> V_29 . V_126 ) ;
F_6 ( V_130 | V_131 | 7 , & V_2 -> V_5 -> V_29 . V_132 ) ;
F_6 ( V_133 | V_134 |
V_135 , & V_2 -> V_5 -> V_29 . V_115 ) ;
F_6 ( 0 , & V_2 -> V_5 -> V_29 . V_136 ) ;
F_6 ( V_137 | V_138 , & V_2 -> V_5 -> V_29 . V_139 ) ;
V_2 -> V_96 = ( V_98 | V_140 |
V_141 ) ;
F_6 ( V_2 -> V_96 , & V_2 -> V_5 -> V_29 . V_110 ) ;
F_6 ( V_142 | V_143 , & V_2 -> V_5 -> V_29 . V_144 ) ;
V_108 = F_2 ( & V_2 -> V_5 -> V_109 . V_126 ) ;
V_108 |= V_145 ;
F_6 ( V_108 , & V_2 -> V_5 -> V_109 . V_126 ) ;
V_2 -> V_117 = ( V_146 | V_147 |
V_148 ) ;
F_6 ( V_2 -> V_117 , & V_2 -> V_5 -> V_29 . V_119 ) ;
V_2 -> V_58 = ( V_149 | V_59 |
V_150 | V_151 |
V_152 | V_153 |
V_65 ) ;
F_6 ( V_2 -> V_58 , & V_2 -> V_5 -> V_29 . V_60 ) ;
F_13 ( V_61 , & V_2 -> V_62 ) ;
F_13 ( V_64 , & V_2 -> V_62 ) ;
F_27 ( & V_2 -> V_14 . V_87 , V_85 ) ;
return 0 ;
}
static void F_40 ( struct V_91 * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
unsigned long V_85 ;
F_26 ( & V_2 -> V_14 . V_87 , V_85 ) ;
V_2 -> V_117 = 0xff ;
F_6 ( V_2 -> V_117 , & V_2 -> V_5 -> V_29 . V_119 ) ;
V_2 -> V_58 = 0xff ;
F_6 ( V_2 -> V_58 , & V_2 -> V_5 -> V_29 . V_60 ) ;
V_2 -> V_111 = F_2 ( & V_2 -> V_5 -> V_109 . V_112 ) ;
V_2 -> V_111 &= ~ V_121 ;
F_6 ( V_2 -> V_111 , & V_2 -> V_5 -> V_109 . V_112 ) ;
V_2 -> V_96 &= ~ V_141 ;
F_6 ( V_2 -> V_96 , & V_2 -> V_5 -> V_109 . V_110 ) ;
#if 0
tmp = readb(&up->regs->rw.ccr0);
tmp &= ~SAB82532_CCR0_PU;
writeb(tmp, &up->regs->rw.ccr0);
#endif
F_27 ( & V_2 -> V_14 . V_87 , V_85 ) ;
F_41 ( V_2 -> V_14 . V_82 , V_2 ) ;
}
static void F_42 ( int V_154 , int * V_155 , int * V_156 )
{
int V_157 , V_158 ;
if ( V_154 == 0 ) {
* V_155 = 0 ;
* V_156 = 0 ;
return;
}
V_157 = ( V_159 * 10 ) / V_154 ;
V_158 = 0 ;
while ( V_157 >= 640 ) {
V_157 = V_157 / 2 ;
V_158 ++ ;
}
V_157 = ( V_157 + 5 ) / 10 ;
if ( ( V_158 == 0 ) && ( ( V_157 & 1 ) == 0 ) ) {
V_157 = V_157 / 2 ;
V_158 ++ ;
}
* V_155 = V_157 - 1 ;
* V_156 = V_158 ;
}
static void F_43 ( struct V_1 * V_2 , unsigned int V_160 ,
unsigned int V_161 , unsigned int V_154 ,
unsigned int V_162 )
{
unsigned char V_112 ;
int V_163 , V_157 , V_158 ;
switch ( V_160 & V_164 ) {
case V_165 : V_112 = V_166 ; V_163 = 7 ; break;
case V_167 : V_112 = V_168 ; V_163 = 8 ; break;
case V_169 : V_112 = V_170 ; V_163 = 9 ; break;
case V_171 : V_112 = V_172 ; V_163 = 10 ; break;
default: V_112 = V_166 ; V_163 = 7 ; break;
}
if ( V_160 & V_173 ) {
V_112 |= V_174 ;
V_163 ++ ;
}
if ( V_160 & V_175 ) {
V_112 |= V_176 ;
V_163 ++ ;
}
if ( V_160 & V_177 ) {
V_112 |= V_178 ;
} else {
V_112 |= V_179 ;
}
V_2 -> V_111 = V_112 ;
F_42 ( V_154 , & V_157 , & V_158 ) ;
V_2 -> V_113 = V_157 | ( V_158 << 6 ) ;
V_2 -> V_4 = ( 10 * 1000000 ) / V_154 ;
V_2 -> V_9 = V_2 -> V_4 >> 2 ;
V_2 -> V_14 . V_49 = ( V_25 | V_27 |
V_31 | V_23 |
V_73 ) ;
V_2 -> V_14 . V_49 |= ( V_76 |
V_57 |
V_89 ) << 8 ;
if ( V_161 & V_180 )
V_2 -> V_14 . V_49 |= ( V_43 |
V_44 ) ;
if ( V_161 & ( V_181 | V_182 ) )
V_2 -> V_14 . V_49 |= ( V_35 << 8 ) ;
V_2 -> V_14 . V_53 = 0 ;
if ( V_161 & V_183 )
V_2 -> V_14 . V_53 |= ( V_43 |
V_44 ) ;
if ( V_161 & V_184 ) {
V_2 -> V_14 . V_53 |= ( V_35 << 8 ) ;
if ( V_161 & V_183 )
V_2 -> V_14 . V_53 |= V_31 ;
}
if ( ( V_160 & V_185 ) == 0 )
V_2 -> V_14 . V_53 |= ( V_23 |
V_25 ) ;
F_44 ( & V_2 -> V_14 , V_160 ,
( V_2 -> V_14 . V_186 / ( 16 * V_162 ) ) ) ;
V_2 -> V_96 |= V_141 ;
F_13 ( V_102 , & V_2 -> V_62 ) ;
if ( F_30 ( V_64 , & V_2 -> V_62 ) )
F_14 ( V_2 ) ;
}
static void F_45 ( struct V_91 * V_14 , struct V_187 * V_188 ,
struct V_187 * V_189 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
unsigned long V_85 ;
unsigned int V_154 = F_46 ( V_14 , V_188 , V_189 , 0 , 4000000 ) ;
unsigned int V_162 = F_47 ( V_14 , V_154 ) ;
F_26 ( & V_2 -> V_14 . V_87 , V_85 ) ;
F_43 ( V_2 , V_188 -> V_190 , V_188 -> V_191 , V_154 , V_162 ) ;
F_27 ( & V_2 -> V_14 . V_87 , V_85 ) ;
}
static const char * F_48 ( struct V_91 * V_14 )
{
struct V_1 * V_2 = ( void * ) V_14 ;
static char V_15 [ 36 ] ;
sprintf ( V_15 , L_2 , V_192 [ V_2 -> type ] ) ;
return V_15 ;
}
static void F_49 ( struct V_91 * V_14 )
{
}
static int F_50 ( struct V_91 * V_14 )
{
return 0 ;
}
static void F_51 ( struct V_91 * V_14 , int V_85 )
{
}
static int F_52 ( struct V_91 * V_14 , struct V_193 * V_194 )
{
return - V_195 ;
}
static void F_53 ( struct V_91 * V_14 , int V_196 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
F_1 ( V_2 ) ;
F_6 ( V_196 , & V_2 -> V_5 -> V_29 . V_116 ) ;
}
static void F_54 ( struct V_197 * V_198 , const char * V_199 , unsigned V_157 )
{
struct V_1 * V_2 = & V_200 [ V_198 -> V_37 ] ;
unsigned long V_85 ;
int V_201 = 1 ;
F_55 ( V_85 ) ;
if ( V_2 -> V_14 . V_202 ) {
V_201 = 0 ;
} else if ( V_203 ) {
V_201 = F_56 ( & V_2 -> V_14 . V_87 ) ;
} else
F_57 ( & V_2 -> V_14 . V_87 ) ;
F_58 ( & V_2 -> V_14 , V_199 , V_157 , F_53 ) ;
F_1 ( V_2 ) ;
if ( V_201 )
F_59 ( & V_2 -> V_14 . V_87 ) ;
F_60 ( V_85 ) ;
}
static int F_61 ( struct V_197 * V_198 , char * V_204 )
{
struct V_1 * V_2 = & V_200 [ V_198 -> V_37 ] ;
unsigned long V_85 ;
unsigned int V_154 , V_162 ;
if ( V_2 -> V_14 . type != V_205 )
return - 1 ;
F_62 ( L_3 ,
( V_206 . V_207 - 64 ) + V_198 -> V_37 ) ;
F_63 ( V_198 , V_2 -> V_14 . V_208 -> V_209 ) ;
switch ( V_198 -> V_160 & V_210 ) {
case V_211 : V_154 = 150 ; break;
case V_212 : V_154 = 300 ; break;
case V_213 : V_154 = 600 ; break;
case V_214 : V_154 = 1200 ; break;
case V_215 : V_154 = 2400 ; break;
case V_216 : V_154 = 4800 ; break;
default: case V_217 : V_154 = 9600 ; break;
case V_218 : V_154 = 19200 ; break;
case V_219 : V_154 = 38400 ; break;
case V_220 : V_154 = 57600 ; break;
case V_221 : V_154 = 115200 ; break;
case V_222 : V_154 = 230400 ; break;
case V_223 : V_154 = 460800 ; break;
} ;
F_64 ( & V_2 -> V_14 . V_87 ) ;
F_38 ( & V_2 -> V_14 ) ;
F_26 ( & V_2 -> V_14 . V_87 , V_85 ) ;
V_2 -> V_117 = V_146 | V_147 |
V_148 | V_224 ;
F_6 ( V_2 -> V_117 , & V_2 -> V_5 -> V_29 . V_119 ) ;
V_2 -> V_58 = V_149 | V_59 |
V_150 | V_151 |
V_152 | V_153 |
V_65 ;
F_6 ( V_2 -> V_58 , & V_2 -> V_5 -> V_29 . V_60 ) ;
V_162 = F_47 ( & V_2 -> V_14 , V_154 ) ;
F_43 ( V_2 , V_198 -> V_160 , 0 , V_154 , V_162 ) ;
F_31 ( & V_2 -> V_14 , V_99 | V_95 ) ;
F_27 ( & V_2 -> V_14 . V_87 , V_85 ) ;
return 0 ;
}
static inline struct V_197 * F_65 ( void )
{
return & V_225 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_226 * V_227 ,
unsigned long V_228 ,
int line )
{
V_2 -> V_14 . line = line ;
V_2 -> V_14 . V_208 = & V_227 -> V_208 ;
V_2 -> V_14 . V_229 = V_227 -> V_230 [ 0 ] . V_231 + V_228 ;
V_2 -> V_14 . V_232 = F_67 ( & V_227 -> V_230 [ 0 ] , V_228 ,
sizeof( union V_233 ) ,
L_1 ) ;
if ( ! V_2 -> V_14 . V_232 )
return - V_234 ;
V_2 -> V_5 = (union V_233 V_235 * ) V_2 -> V_14 . V_232 ;
V_2 -> V_14 . V_82 = V_227 -> V_236 . V_237 [ 0 ] ;
V_2 -> V_14 . V_66 = V_238 ;
V_2 -> V_14 . V_239 = V_240 ;
F_6 ( V_241 , & V_2 -> V_5 -> V_29 . V_242 ) ;
V_2 -> V_14 . V_243 = & V_244 ;
V_2 -> V_14 . type = V_205 ;
V_2 -> V_14 . V_186 = V_159 ;
V_2 -> type = F_2 ( & V_2 -> V_5 -> V_6 . V_74 ) & 0x0f ;
F_6 ( ~ ( ( 1 << 1 ) | ( 1 << 2 ) | ( 1 << 4 ) ) , & V_2 -> V_5 -> V_29 . V_245 ) ;
F_6 ( 0xff , & V_2 -> V_5 -> V_29 . V_246 ) ;
if ( ( V_2 -> V_14 . line & 0x1 ) == 0 ) {
V_2 -> V_79 = ( 1 << 0 ) ;
V_2 -> V_101 = ( 1 << 1 ) ;
V_2 -> V_88 = 2 ;
} else {
V_2 -> V_79 = ( 1 << 3 ) ;
V_2 -> V_101 = ( 1 << 2 ) ;
V_2 -> V_88 = 0 ;
}
V_2 -> V_100 = ( 1 << 1 ) | ( 1 << 2 ) | ( 1 << 4 ) ;
F_6 ( V_2 -> V_100 , & V_2 -> V_5 -> V_29 . V_78 ) ;
V_2 -> V_96 = F_2 ( & V_2 -> V_5 -> V_109 . V_110 ) ;
V_2 -> V_96 |= V_97 ;
F_6 ( V_2 -> V_96 , & V_2 -> V_5 -> V_109 . V_110 ) ;
V_2 -> V_96 |= V_98 ;
F_6 ( V_2 -> V_96 , & V_2 -> V_5 -> V_109 . V_110 ) ;
V_2 -> V_4 = V_247 ;
V_2 -> V_9 = V_248 ;
return 0 ;
}
static int F_68 ( struct V_226 * V_227 )
{
static int V_249 ;
struct V_1 * V_2 ;
int V_122 ;
V_2 = & V_200 [ V_249 * 2 ] ;
V_122 = F_66 ( & V_2 [ 0 ] , V_227 ,
0 ,
( V_249 * 2 ) + 0 ) ;
if ( V_122 )
goto V_250;
V_122 = F_66 ( & V_2 [ 1 ] , V_227 ,
sizeof( union V_233 ) ,
( V_249 * 2 ) + 1 ) ;
if ( V_122 )
goto V_251;
F_69 ( F_65 () , V_227 -> V_208 . V_209 ,
& V_206 , V_2 [ 0 ] . V_14 . line ,
false ) ;
F_69 ( F_65 () , V_227 -> V_208 . V_209 ,
& V_206 , V_2 [ 1 ] . V_14 . line ,
false ) ;
V_122 = F_70 ( & V_206 , & V_2 [ 0 ] . V_14 ) ;
if ( V_122 )
goto V_252;
V_122 = F_70 ( & V_206 , & V_2 [ 1 ] . V_14 ) ;
if ( V_122 )
goto V_253;
F_71 ( & V_227 -> V_208 , & V_2 [ 0 ] ) ;
V_249 ++ ;
return 0 ;
V_253:
F_72 ( & V_206 , & V_2 [ 0 ] . V_14 ) ;
V_252:
F_73 ( & V_227 -> V_230 [ 0 ] ,
V_2 [ 1 ] . V_14 . V_232 ,
sizeof( union V_233 ) ) ;
V_251:
F_73 ( & V_227 -> V_230 [ 0 ] ,
V_2 [ 0 ] . V_14 . V_232 ,
sizeof( union V_233 ) ) ;
V_250:
return V_122 ;
}
static int F_74 ( struct V_226 * V_227 )
{
struct V_1 * V_2 = F_75 ( & V_227 -> V_208 ) ;
F_72 ( & V_206 , & V_2 [ 1 ] . V_14 ) ;
F_72 ( & V_206 , & V_2 [ 0 ] . V_14 ) ;
F_73 ( & V_227 -> V_230 [ 0 ] ,
V_2 [ 1 ] . V_14 . V_232 ,
sizeof( union V_233 ) ) ;
F_73 ( & V_227 -> V_230 [ 0 ] ,
V_2 [ 0 ] . V_14 . V_232 ,
sizeof( union V_233 ) ) ;
F_71 ( & V_227 -> V_208 , NULL ) ;
return 0 ;
}
static int T_4 F_76 ( void )
{
struct V_254 * V_255 ;
int V_122 ;
int V_256 = 0 ;
F_77 (dp, L_4 )
V_256 += 2 ;
F_77 (dp, L_5 ) {
if ( F_78 ( V_255 , L_6 ) )
V_256 += 2 ;
}
if ( V_256 ) {
V_200 = F_79 ( sizeof( struct V_1 ) *
V_256 , V_257 ) ;
if ( ! V_200 )
return - V_234 ;
V_122 = F_80 ( & V_206 , V_256 ) ;
if ( V_122 ) {
F_81 ( V_200 ) ;
V_200 = NULL ;
return V_122 ;
}
}
return F_82 ( & V_258 ) ;
}
static void T_5 F_83 ( void )
{
F_84 ( & V_258 ) ;
if ( V_206 . V_259 ) {
F_85 ( & V_206 , V_206 . V_259 ) ;
}
F_81 ( V_200 ) ;
V_200 = NULL ;
}

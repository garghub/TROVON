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
if ( V_18 == 0 ) {
if ( F_7 ( V_13 -> V_21 . V_34 & V_35 ) ) {
V_13 -> V_21 . V_22 &= ~ ( V_38 |
V_39 ) ;
V_2 -> V_14 . V_40 . V_41 ++ ;
F_8 ( & V_2 -> V_14 ) ;
}
}
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
unsigned char V_42 = V_15 [ V_19 ] , V_43 ;
V_43 = V_44 ;
V_2 -> V_14 . V_40 . V_45 ++ ;
if ( F_7 ( V_13 -> V_21 . V_22 & ( V_38 |
V_39 |
V_31 ) ) ||
F_7 ( V_13 -> V_21 . V_34 & V_35 ) ) {
if ( V_13 -> V_21 . V_34 & V_35 ) {
V_13 -> V_21 . V_22 &= ~ ( V_38 |
V_39 ) ;
V_2 -> V_14 . V_40 . V_41 ++ ;
if ( F_8 ( & V_2 -> V_14 ) )
continue;
} else if ( V_13 -> V_21 . V_22 & V_38 )
V_2 -> V_14 . V_40 . V_46 ++ ;
else if ( V_13 -> V_21 . V_22 & V_39 )
V_2 -> V_14 . V_40 . V_47 ++ ;
if ( V_13 -> V_21 . V_22 & V_31 )
V_2 -> V_14 . V_40 . V_48 ++ ;
V_13 -> V_21 . V_22 &= ( V_2 -> V_14 . V_49 & 0xff ) ;
V_13 -> V_21 . V_34 &= ( ( V_2 -> V_14 . V_49 >> 8 ) & 0xff ) ;
if ( V_13 -> V_21 . V_34 & V_35 ) {
V_43 = V_50 ;
} else if ( V_13 -> V_21 . V_22 & V_38 )
V_43 = V_51 ;
else if ( V_13 -> V_21 . V_22 & V_39 )
V_43 = V_52 ;
}
if ( F_9 ( & V_2 -> V_14 , V_42 ) || ! V_14 )
continue;
if ( ( V_13 -> V_21 . V_22 & ( V_2 -> V_14 . V_53 & 0xff ) ) == 0 &&
( V_13 -> V_21 . V_34 & ( ( V_2 -> V_14 . V_53 >> 8 ) & 0xff ) ) == 0 )
F_10 ( V_14 , V_42 , V_43 ) ;
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
V_2 -> V_14 . V_40 . V_70 ++ ;
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
V_2 -> V_14 . V_40 . V_80 ++ ;
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
struct V_1 * V_2 =
F_30 ( V_14 , struct V_1 , V_14 ) ;
int V_92 ;
if ( F_31 ( V_61 , & V_2 -> V_62 ) )
V_92 = V_93 ;
else
V_92 = 0 ;
return V_92 ;
}
static void F_32 ( struct V_91 * V_14 , unsigned int V_94 )
{
struct V_1 * V_2 =
F_30 ( V_14 , struct V_1 , V_14 ) ;
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
if ( F_31 ( V_64 , & V_2 -> V_62 ) )
F_14 ( V_2 ) ;
}
static unsigned int F_33 ( struct V_91 * V_14 )
{
struct V_1 * V_2 =
F_30 ( V_14 , struct V_1 , V_14 ) ;
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
struct V_1 * V_2 =
F_30 ( V_14 , struct V_1 , V_14 ) ;
V_2 -> V_58 |= V_65 ;
F_6 ( V_2 -> V_58 , & V_2 -> V_5 -> V_29 . V_60 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( F_31 ( V_102 , & V_2 -> V_62 ) ) {
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
static void F_34 ( struct V_91 * V_14 )
{
struct V_1 * V_2 =
F_30 ( V_14 , struct V_1 , V_14 ) ;
struct V_55 * V_56 = & V_2 -> V_14 . V_20 -> V_56 ;
int V_19 ;
if ( F_15 ( V_56 ) || F_16 ( V_14 ) )
return;
V_2 -> V_58 &= ~ ( V_59 | V_65 ) ;
F_6 ( V_2 -> V_58 , & V_2 -> V_5 -> V_29 . V_60 ) ;
if ( ! F_31 ( V_64 , & V_2 -> V_62 ) )
return;
F_17 ( V_61 , & V_2 -> V_62 ) ;
F_17 ( V_64 , & V_2 -> V_62 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_14 . V_66 ; V_19 ++ ) {
F_6 ( V_56 -> V_15 [ V_56 -> V_67 ] ,
& V_2 -> V_5 -> V_29 . V_68 [ V_19 ] ) ;
V_56 -> V_67 = ( V_56 -> V_67 + 1 ) & ( V_69 - 1 ) ;
V_2 -> V_14 . V_40 . V_70 ++ ;
if ( F_15 ( V_56 ) )
break;
}
F_4 ( V_2 ) ;
F_6 ( V_71 , & V_2 -> V_5 -> V_29 . V_30 ) ;
}
static void F_35 ( struct V_91 * V_14 , char V_42 )
{
struct V_1 * V_2 =
F_30 ( V_14 , struct V_1 , V_14 ) ;
unsigned long V_85 ;
if ( V_42 == V_116 )
return;
F_26 ( & V_2 -> V_14 . V_87 , V_85 ) ;
F_1 ( V_2 ) ;
F_6 ( V_42 , & V_2 -> V_5 -> V_29 . V_117 ) ;
F_27 ( & V_2 -> V_14 . V_87 , V_85 ) ;
}
static void F_36 ( struct V_91 * V_14 )
{
struct V_1 * V_2 =
F_30 ( V_14 , struct V_1 , V_14 ) ;
V_2 -> V_118 |= V_119 ;
F_6 ( V_2 -> V_58 , & V_2 -> V_5 -> V_29 . V_120 ) ;
}
static void F_37 ( struct V_91 * V_14 , int V_121 )
{
struct V_1 * V_2 =
F_30 ( V_14 , struct V_1 , V_14 ) ;
unsigned long V_85 ;
unsigned char V_103 ;
F_26 ( & V_2 -> V_14 . V_87 , V_85 ) ;
V_103 = V_2 -> V_111 ;
if ( V_121 )
V_103 |= V_122 ;
else
V_103 &= ~ V_122 ;
V_2 -> V_111 = V_103 ;
F_13 ( V_102 , & V_2 -> V_62 ) ;
if ( F_31 ( V_64 , & V_2 -> V_62 ) )
F_14 ( V_2 ) ;
F_27 ( & V_2 -> V_14 . V_87 , V_85 ) ;
}
static int F_38 ( struct V_91 * V_14 )
{
struct V_1 * V_2 =
F_30 ( V_14 , struct V_1 , V_14 ) ;
unsigned long V_85 ;
unsigned char V_108 ;
int V_123 = F_39 ( V_2 -> V_14 . V_82 , F_25 ,
V_124 , L_1 , V_2 ) ;
if ( V_123 )
return V_123 ;
F_26 ( & V_2 -> V_14 . V_87 , V_85 ) ;
F_4 ( V_2 ) ;
F_1 ( V_2 ) ;
F_6 ( V_125 , & V_2 -> V_5 -> V_29 . V_30 ) ;
F_4 ( V_2 ) ;
F_6 ( V_126 , & V_2 -> V_5 -> V_29 . V_30 ) ;
( void ) F_2 ( & V_2 -> V_5 -> V_6 . V_22 ) ;
( void ) F_2 ( & V_2 -> V_5 -> V_6 . V_34 ) ;
F_6 ( 0 , & V_2 -> V_5 -> V_29 . V_127 ) ;
F_6 ( V_128 | V_129 |
V_130 , & V_2 -> V_5 -> V_29 . V_127 ) ;
F_6 ( V_131 | V_132 | 7 , & V_2 -> V_5 -> V_29 . V_133 ) ;
F_6 ( V_134 | V_135 |
V_136 , & V_2 -> V_5 -> V_29 . V_115 ) ;
F_6 ( 0 , & V_2 -> V_5 -> V_29 . V_137 ) ;
F_6 ( V_138 | V_139 , & V_2 -> V_5 -> V_29 . V_140 ) ;
V_2 -> V_96 = ( V_98 | V_141 |
V_142 ) ;
F_6 ( V_2 -> V_96 , & V_2 -> V_5 -> V_29 . V_110 ) ;
F_6 ( V_143 | V_144 , & V_2 -> V_5 -> V_29 . V_145 ) ;
V_108 = F_2 ( & V_2 -> V_5 -> V_109 . V_127 ) ;
V_108 |= V_146 ;
F_6 ( V_108 , & V_2 -> V_5 -> V_109 . V_127 ) ;
V_2 -> V_118 = ( V_147 | V_148 |
V_149 ) ;
F_6 ( V_2 -> V_118 , & V_2 -> V_5 -> V_29 . V_120 ) ;
V_2 -> V_58 = ( V_150 | V_59 |
V_151 | V_152 |
V_153 | V_154 |
V_65 ) ;
F_6 ( V_2 -> V_58 , & V_2 -> V_5 -> V_29 . V_60 ) ;
F_13 ( V_61 , & V_2 -> V_62 ) ;
F_13 ( V_64 , & V_2 -> V_62 ) ;
F_27 ( & V_2 -> V_14 . V_87 , V_85 ) ;
return 0 ;
}
static void F_40 ( struct V_91 * V_14 )
{
struct V_1 * V_2 =
F_30 ( V_14 , struct V_1 , V_14 ) ;
unsigned long V_85 ;
F_26 ( & V_2 -> V_14 . V_87 , V_85 ) ;
V_2 -> V_118 = 0xff ;
F_6 ( V_2 -> V_118 , & V_2 -> V_5 -> V_29 . V_120 ) ;
V_2 -> V_58 = 0xff ;
F_6 ( V_2 -> V_58 , & V_2 -> V_5 -> V_29 . V_60 ) ;
V_2 -> V_111 = F_2 ( & V_2 -> V_5 -> V_109 . V_112 ) ;
V_2 -> V_111 &= ~ V_122 ;
F_6 ( V_2 -> V_111 , & V_2 -> V_5 -> V_109 . V_112 ) ;
V_2 -> V_96 &= ~ V_142 ;
F_6 ( V_2 -> V_96 , & V_2 -> V_5 -> V_109 . V_110 ) ;
#if 0
tmp = readb(&up->regs->rw.ccr0);
tmp &= ~SAB82532_CCR0_PU;
writeb(tmp, &up->regs->rw.ccr0);
#endif
F_27 ( & V_2 -> V_14 . V_87 , V_85 ) ;
F_41 ( V_2 -> V_14 . V_82 , V_2 ) ;
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
unsigned char V_112 ;
int V_164 , V_158 , V_159 ;
switch ( V_161 & V_165 ) {
case V_166 : V_112 = V_167 ; V_164 = 7 ; break;
case V_168 : V_112 = V_169 ; V_164 = 8 ; break;
case V_170 : V_112 = V_171 ; V_164 = 9 ; break;
case V_172 : V_112 = V_173 ; V_164 = 10 ; break;
default: V_112 = V_167 ; V_164 = 7 ; break;
}
if ( V_161 & V_174 ) {
V_112 |= V_175 ;
V_164 ++ ;
}
if ( V_161 & V_176 ) {
V_112 |= V_177 ;
V_164 ++ ;
}
if ( V_161 & V_178 ) {
V_112 |= V_179 ;
} else {
V_112 |= V_180 ;
}
V_2 -> V_111 = V_112 ;
F_42 ( V_155 , & V_158 , & V_159 ) ;
V_2 -> V_113 = V_158 | ( V_159 << 6 ) ;
V_2 -> V_4 = ( 10 * 1000000 ) / V_155 ;
V_2 -> V_9 = V_2 -> V_4 >> 2 ;
V_2 -> V_14 . V_49 = ( V_25 | V_27 |
V_31 | V_23 |
V_73 ) ;
V_2 -> V_14 . V_49 |= ( V_76 |
V_57 |
V_89 ) << 8 ;
if ( V_162 & V_181 )
V_2 -> V_14 . V_49 |= ( V_38 |
V_39 ) ;
if ( V_162 & ( V_182 | V_183 | V_184 ) )
V_2 -> V_14 . V_49 |= ( V_35 << 8 ) ;
V_2 -> V_14 . V_53 = 0 ;
if ( V_162 & V_185 )
V_2 -> V_14 . V_53 |= ( V_38 |
V_39 ) ;
if ( V_162 & V_182 ) {
V_2 -> V_14 . V_53 |= ( V_35 << 8 ) ;
if ( V_162 & V_185 )
V_2 -> V_14 . V_53 |= V_31 ;
}
if ( ( V_161 & V_186 ) == 0 )
V_2 -> V_14 . V_53 |= ( V_23 |
V_25 ) ;
F_44 ( & V_2 -> V_14 , V_161 ,
( V_2 -> V_14 . V_187 / ( 16 * V_163 ) ) ) ;
V_2 -> V_96 |= V_142 ;
F_13 ( V_102 , & V_2 -> V_62 ) ;
if ( F_31 ( V_64 , & V_2 -> V_62 ) )
F_14 ( V_2 ) ;
}
static void F_45 ( struct V_91 * V_14 , struct V_188 * V_189 ,
struct V_188 * V_190 )
{
struct V_1 * V_2 =
F_30 ( V_14 , struct V_1 , V_14 ) ;
unsigned long V_85 ;
unsigned int V_155 = F_46 ( V_14 , V_189 , V_190 , 0 , 4000000 ) ;
unsigned int V_163 = F_47 ( V_14 , V_155 ) ;
F_26 ( & V_2 -> V_14 . V_87 , V_85 ) ;
F_43 ( V_2 , V_189 -> V_191 , V_189 -> V_192 , V_155 , V_163 ) ;
F_27 ( & V_2 -> V_14 . V_87 , V_85 ) ;
}
static const char * F_48 ( struct V_91 * V_14 )
{
struct V_1 * V_2 = ( void * ) V_14 ;
static char V_15 [ 36 ] ;
sprintf ( V_15 , L_2 , V_193 [ V_2 -> type ] ) ;
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
static int F_52 ( struct V_91 * V_14 , struct V_194 * V_195 )
{
return - V_196 ;
}
static void F_53 ( struct V_91 * V_14 , int V_197 )
{
struct V_1 * V_2 =
F_30 ( V_14 , struct V_1 , V_14 ) ;
F_1 ( V_2 ) ;
F_6 ( V_197 , & V_2 -> V_5 -> V_29 . V_117 ) ;
}
static void F_54 ( struct V_198 * V_199 , const char * V_200 , unsigned V_158 )
{
struct V_1 * V_2 = & V_201 [ V_199 -> V_37 ] ;
unsigned long V_85 ;
int V_202 = 1 ;
if ( V_2 -> V_14 . V_203 || V_204 )
V_202 = F_55 ( & V_2 -> V_14 . V_87 , V_85 ) ;
else
F_26 ( & V_2 -> V_14 . V_87 , V_85 ) ;
F_56 ( & V_2 -> V_14 , V_200 , V_158 , F_53 ) ;
F_1 ( V_2 ) ;
if ( V_202 )
F_27 ( & V_2 -> V_14 . V_87 , V_85 ) ;
}
static int F_57 ( struct V_198 * V_199 , char * V_205 )
{
struct V_1 * V_2 = & V_201 [ V_199 -> V_37 ] ;
unsigned long V_85 ;
unsigned int V_155 , V_163 ;
if ( V_2 -> V_14 . type != V_206 )
return - 1 ;
F_58 ( L_3 ,
( V_207 . V_208 - 64 ) + V_199 -> V_37 ) ;
F_59 ( V_199 , V_2 -> V_14 . V_209 -> V_210 ) ;
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
}
F_60 ( & V_2 -> V_14 . V_87 ) ;
F_38 ( & V_2 -> V_14 ) ;
F_26 ( & V_2 -> V_14 . V_87 , V_85 ) ;
V_2 -> V_118 = V_147 | V_148 |
V_149 | V_225 ;
F_6 ( V_2 -> V_118 , & V_2 -> V_5 -> V_29 . V_120 ) ;
V_2 -> V_58 = V_150 | V_59 |
V_151 | V_152 |
V_153 | V_154 |
V_65 ;
F_6 ( V_2 -> V_58 , & V_2 -> V_5 -> V_29 . V_60 ) ;
V_163 = F_47 ( & V_2 -> V_14 , V_155 ) ;
F_43 ( V_2 , V_199 -> V_161 , 0 , V_155 , V_163 ) ;
F_32 ( & V_2 -> V_14 , V_99 | V_95 ) ;
F_27 ( & V_2 -> V_14 . V_87 , V_85 ) ;
return 0 ;
}
static inline struct V_198 * F_61 ( void )
{
return & V_226 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_227 * V_228 ,
unsigned long V_229 ,
int line )
{
V_2 -> V_14 . line = line ;
V_2 -> V_14 . V_209 = & V_228 -> V_209 ;
V_2 -> V_14 . V_230 = V_228 -> V_231 [ 0 ] . V_232 + V_229 ;
V_2 -> V_14 . V_233 = F_63 ( & V_228 -> V_231 [ 0 ] , V_229 ,
sizeof( union V_234 ) ,
L_1 ) ;
if ( ! V_2 -> V_14 . V_233 )
return - V_235 ;
V_2 -> V_5 = (union V_234 V_236 * ) V_2 -> V_14 . V_233 ;
V_2 -> V_14 . V_82 = V_228 -> V_237 . V_238 [ 0 ] ;
V_2 -> V_14 . V_66 = V_239 ;
V_2 -> V_14 . V_240 = V_241 ;
F_6 ( V_242 , & V_2 -> V_5 -> V_29 . V_243 ) ;
V_2 -> V_14 . V_244 = & V_245 ;
V_2 -> V_14 . type = V_206 ;
V_2 -> V_14 . V_187 = V_160 ;
V_2 -> type = F_2 ( & V_2 -> V_5 -> V_6 . V_74 ) & 0x0f ;
F_6 ( ~ ( ( 1 << 1 ) | ( 1 << 2 ) | ( 1 << 4 ) ) , & V_2 -> V_5 -> V_29 . V_246 ) ;
F_6 ( 0xff , & V_2 -> V_5 -> V_29 . V_247 ) ;
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
V_2 -> V_4 = V_248 ;
V_2 -> V_9 = V_249 ;
return 0 ;
}
static int F_64 ( struct V_227 * V_228 )
{
static int V_250 ;
struct V_1 * V_2 ;
int V_123 ;
V_2 = & V_201 [ V_250 * 2 ] ;
V_123 = F_62 ( & V_2 [ 0 ] , V_228 ,
0 ,
( V_250 * 2 ) + 0 ) ;
if ( V_123 )
goto V_251;
V_123 = F_62 ( & V_2 [ 1 ] , V_228 ,
sizeof( union V_234 ) ,
( V_250 * 2 ) + 1 ) ;
if ( V_123 )
goto V_252;
F_65 ( F_61 () , V_228 -> V_209 . V_210 ,
& V_207 , V_2 [ 0 ] . V_14 . line ,
false ) ;
F_65 ( F_61 () , V_228 -> V_209 . V_210 ,
& V_207 , V_2 [ 1 ] . V_14 . line ,
false ) ;
V_123 = F_66 ( & V_207 , & V_2 [ 0 ] . V_14 ) ;
if ( V_123 )
goto V_253;
V_123 = F_66 ( & V_207 , & V_2 [ 1 ] . V_14 ) ;
if ( V_123 )
goto V_254;
F_67 ( V_228 , & V_2 [ 0 ] ) ;
V_250 ++ ;
return 0 ;
V_254:
F_68 ( & V_207 , & V_2 [ 0 ] . V_14 ) ;
V_253:
F_69 ( & V_228 -> V_231 [ 0 ] ,
V_2 [ 1 ] . V_14 . V_233 ,
sizeof( union V_234 ) ) ;
V_252:
F_69 ( & V_228 -> V_231 [ 0 ] ,
V_2 [ 0 ] . V_14 . V_233 ,
sizeof( union V_234 ) ) ;
V_251:
return V_123 ;
}
static int F_70 ( struct V_227 * V_228 )
{
struct V_1 * V_2 = F_71 ( V_228 ) ;
F_68 ( & V_207 , & V_2 [ 1 ] . V_14 ) ;
F_68 ( & V_207 , & V_2 [ 0 ] . V_14 ) ;
F_69 ( & V_228 -> V_231 [ 0 ] ,
V_2 [ 1 ] . V_14 . V_233 ,
sizeof( union V_234 ) ) ;
F_69 ( & V_228 -> V_231 [ 0 ] ,
V_2 [ 0 ] . V_14 . V_233 ,
sizeof( union V_234 ) ) ;
return 0 ;
}
static int T_4 F_72 ( void )
{
struct V_255 * V_256 ;
int V_123 ;
int V_257 = 0 ;
F_73 (dp, L_4 )
V_257 += 2 ;
F_73 (dp, L_5 ) {
if ( F_74 ( V_256 , L_6 ) )
V_257 += 2 ;
}
if ( V_257 ) {
V_201 = F_75 ( sizeof( struct V_1 ) *
V_257 , V_258 ) ;
if ( ! V_201 )
return - V_235 ;
V_123 = F_76 ( & V_207 , V_257 ) ;
if ( V_123 ) {
F_77 ( V_201 ) ;
V_201 = NULL ;
return V_123 ;
}
}
return F_78 ( & V_259 ) ;
}
static void T_5 F_79 ( void )
{
F_80 ( & V_259 ) ;
if ( V_207 . V_260 ) {
F_81 ( & V_207 , V_207 . V_260 ) ;
}
F_77 ( V_201 ) ;
V_201 = NULL ;
}

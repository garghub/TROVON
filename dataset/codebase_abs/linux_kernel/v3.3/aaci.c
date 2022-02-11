static void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
T_1 V_4 , V_5 = V_1 -> V_5 | F_2 ( V_3 -> V_6 ) ;
V_4 = F_3 ( V_1 -> V_7 + V_8 ) ;
if ( V_4 & V_9 )
F_3 ( V_1 -> V_7 + V_10 ) ;
if ( V_4 & V_11 )
F_3 ( V_1 -> V_7 + V_12 ) ;
if ( V_5 != F_3 ( V_1 -> V_7 + V_13 ) ) {
F_4 ( V_5 , V_1 -> V_7 + V_13 ) ;
F_3 ( V_1 -> V_7 + V_13 ) ;
F_5 ( 1 ) ;
}
}
static void F_6 ( struct V_2 * V_3 , unsigned short V_14 ,
unsigned short V_15 )
{
struct V_1 * V_1 = V_3 -> V_16 ;
int V_17 ;
T_1 V_4 ;
if ( V_3 -> V_6 >= 4 )
return;
F_7 ( & V_1 -> V_18 ) ;
F_1 ( V_1 , V_3 ) ;
F_4 ( V_15 << 4 , V_1 -> V_7 + V_19 ) ;
F_4 ( V_14 << 12 , V_1 -> V_7 + V_20 ) ;
F_5 ( V_21 ) ;
V_17 = V_21 * 8 ;
do {
F_5 ( 1 ) ;
V_4 = F_3 ( V_1 -> V_7 + V_8 ) ;
} while ( ( V_4 & ( V_22 | V_23 ) ) && -- V_17 );
if ( V_4 & ( V_22 | V_23 ) )
F_8 ( & V_1 -> V_24 -> V_24 ,
L_1 ) ;
F_9 ( & V_1 -> V_18 ) ;
}
static unsigned short F_10 ( struct V_2 * V_3 , unsigned short V_14 )
{
struct V_1 * V_1 = V_3 -> V_16 ;
int V_17 , V_25 = 10 ;
T_1 V_4 ;
if ( V_3 -> V_6 >= 4 )
return ~ 0 ;
F_7 ( & V_1 -> V_18 ) ;
F_1 ( V_1 , V_3 ) ;
F_4 ( ( V_14 << 12 ) | ( 1 << 19 ) , V_1 -> V_7 + V_20 ) ;
F_5 ( V_21 ) ;
V_17 = V_21 * 8 ;
do {
F_5 ( 1 ) ;
V_4 = F_3 ( V_1 -> V_7 + V_8 ) ;
} while ( ( V_4 & V_22 ) && -- V_17 );
if ( V_4 & V_22 ) {
F_8 ( & V_1 -> V_24 -> V_24 , L_2 ) ;
V_4 = ~ 0 ;
goto V_26;
}
F_5 ( V_21 ) ;
V_17 = V_21 * 8 ;
do {
F_5 ( 1 ) ;
F_11 () ;
V_4 = F_3 ( V_1 -> V_7 + V_8 ) & ( V_11 | V_9 ) ;
} while ( ( V_4 != ( V_11 | V_9 ) ) && -- V_17 );
if ( V_4 != ( V_11 | V_9 ) ) {
F_8 ( & V_1 -> V_24 -> V_24 , L_3 ) ;
V_4 = ~ 0 ;
goto V_26;
}
do {
V_4 = F_3 ( V_1 -> V_7 + V_12 ) >> 12 ;
if ( V_4 == V_14 ) {
V_4 = F_3 ( V_1 -> V_7 + V_10 ) >> 4 ;
break;
} else if ( -- V_25 ) {
F_12 ( & V_1 -> V_24 -> V_24 ,
L_4 ) ;
continue;
} else {
F_12 ( & V_1 -> V_24 -> V_24 ,
L_5 ,
V_4 , V_14 ) ;
V_4 = ~ 0 ;
}
} while ( V_25 );
V_26:
F_9 ( & V_1 -> V_18 ) ;
return V_4 ;
}
static inline void
F_13 ( struct V_27 * V_28 , unsigned long V_29 )
{
T_1 V_15 ;
int V_17 = 5000 ;
do {
F_5 ( 1 ) ;
V_15 = F_3 ( V_28 -> V_7 + V_30 ) ;
} while ( V_15 & V_29 && V_17 -- );
}
static void F_14 ( struct V_1 * V_1 , int V_31 , T_1 V_29 )
{
if ( V_29 & V_32 ) {
F_12 ( & V_1 -> V_24 -> V_24 , L_6 , V_31 ) ;
F_4 ( V_33 << V_31 , V_1 -> V_7 + V_34 ) ;
}
if ( V_29 & V_35 ) {
F_12 ( & V_1 -> V_24 -> V_24 , L_7 , V_31 ) ;
F_4 ( V_36 << V_31 , V_1 -> V_7 + V_34 ) ;
}
if ( V_29 & V_37 ) {
struct V_27 * V_28 = & V_1 -> V_38 ;
bool V_39 = false ;
void * V_40 ;
if ( ! V_28 -> V_41 || ! V_28 -> V_42 ) {
F_12 ( & V_1 -> V_24 -> V_24 , L_8 ) ;
F_4 ( 0 , V_28 -> V_7 + V_43 ) ;
return;
}
F_15 ( & V_28 -> V_44 ) ;
V_40 = V_28 -> V_40 ;
do {
unsigned int V_45 = V_28 -> V_46 ;
T_1 V_15 ;
if ( V_28 -> V_47 <= 0 ) {
V_28 -> V_47 += V_28 -> V_48 ;
V_39 = true ;
}
if ( ! ( V_28 -> V_49 & V_50 ) )
break;
V_15 = F_3 ( V_28 -> V_7 + V_30 ) ;
if ( ! ( V_15 & V_51 ) )
break;
if ( ! ( V_15 & V_52 ) )
V_45 >>= 1 ;
V_28 -> V_47 -= V_45 ;
for( ; V_45 > 0 ; V_45 -= 16 ) {
asm(
"ldmia %1, {r0, r1, r2, r3}\n\t"
"stmia %0!, {r0, r1, r2, r3}"
: "+r" (ptr)
: "r" (aacirun->fifo)
: "r0", "r1", "r2", "r3", "cc");
if ( V_40 >= V_28 -> V_53 )
V_40 = V_28 -> V_42 ;
}
} while( 1 );
V_28 -> V_40 = V_40 ;
F_16 ( & V_28 -> V_44 ) ;
if ( V_39 )
F_17 ( V_28 -> V_41 ) ;
}
if ( V_29 & V_54 ) {
F_18 ( & V_1 -> V_24 -> V_24 , L_9 , V_31 ) ;
F_4 ( V_55 << V_31 , V_1 -> V_7 + V_34 ) ;
}
if ( V_29 & V_56 ) {
struct V_27 * V_28 = & V_1 -> V_57 ;
bool V_39 = false ;
void * V_40 ;
if ( ! V_28 -> V_41 || ! V_28 -> V_42 ) {
F_12 ( & V_1 -> V_24 -> V_24 , L_10 ) ;
F_4 ( 0 , V_28 -> V_7 + V_43 ) ;
return;
}
F_15 ( & V_28 -> V_44 ) ;
V_40 = V_28 -> V_40 ;
do {
unsigned int V_45 = V_28 -> V_46 ;
T_1 V_15 ;
if ( V_28 -> V_47 <= 0 ) {
V_28 -> V_47 += V_28 -> V_48 ;
V_39 = true ;
}
if ( ! ( V_28 -> V_49 & V_50 ) )
break;
V_15 = F_3 ( V_28 -> V_7 + V_30 ) ;
if ( ! ( V_15 & V_58 ) )
break;
if ( ! ( V_15 & V_59 ) )
V_45 >>= 1 ;
V_28 -> V_47 -= V_45 ;
for ( ; V_45 > 0 ; V_45 -= 16 ) {
asm(
"ldmia %0!, {r0, r1, r2, r3}\n\t"
"stmia %1, {r0, r1, r2, r3}"
: "+r" (ptr)
: "r" (aacirun->fifo)
: "r0", "r1", "r2", "r3", "cc");
if ( V_40 >= V_28 -> V_53 )
V_40 = V_28 -> V_42 ;
}
} while ( 1 );
V_28 -> V_40 = V_40 ;
F_16 ( & V_28 -> V_44 ) ;
if ( V_39 )
F_17 ( V_28 -> V_41 ) ;
}
}
static T_2 F_19 ( int V_60 , void * V_61 )
{
struct V_1 * V_1 = V_61 ;
T_1 V_29 ;
int V_62 ;
V_29 = F_3 ( V_1 -> V_7 + V_63 ) ;
if ( V_29 ) {
T_1 V_64 = V_29 ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ , V_64 >>= 7 ) {
if ( V_64 & 0x7f ) {
F_14 ( V_1 , V_62 , V_64 ) ;
}
}
}
return V_29 ? V_65 : V_66 ;
}
static int F_20 ( struct V_67 * V_68 ,
struct V_69 * V_70 )
{
static unsigned int V_71 [] = { 2 , 4 , 6 } ;
struct V_1 * V_1 = V_70 -> V_72 ;
unsigned int V_29 = 1 << 0 , V_73 ;
V_73 = V_1 -> V_74 -> V_75 [ 0 ] . V_76 [ 0 ] . V_73 ;
if ( V_73 & ( 1 << V_77 ) ) {
V_29 |= 1 << 1 ;
if ( V_73 & ( 1 << V_78 ) )
V_29 |= 1 << 2 ;
}
return F_21 ( F_22 ( V_68 , V_70 -> V_79 ) ,
F_23 ( V_71 ) , V_71 , V_29 ) ;
}
static int F_24 ( struct V_80 * V_41 )
{
struct V_81 * V_82 = V_41 -> V_82 ;
struct V_1 * V_1 = V_41 -> V_16 ;
struct V_27 * V_28 ;
int V_83 = 0 ;
if ( V_41 -> V_84 == V_85 ) {
V_28 = & V_1 -> V_57 ;
} else {
V_28 = & V_1 -> V_38 ;
}
V_28 -> V_41 = V_41 ;
V_82 -> V_16 = V_28 ;
V_82 -> V_86 = V_87 ;
V_82 -> V_86 . V_88 = V_28 -> V_89 -> V_88 ;
F_25 ( V_82 ) ;
if ( V_41 -> V_84 == V_85 ) {
V_82 -> V_86 . V_90 = 6 ;
V_83 = F_26 ( V_41 -> V_82 , 0 ,
V_91 ,
F_20 , V_1 ,
V_91 , - 1 ) ;
if ( V_83 )
return V_83 ;
if ( V_28 -> V_89 -> V_76 [ 1 ] . V_73 )
F_27 ( V_82 ) ;
}
V_82 -> V_86 . V_92 = V_1 -> V_93 * 2 ;
F_7 ( & V_1 -> V_94 ) ;
if ( ! V_1 -> V_95 ++ ) {
V_83 = F_28 ( V_1 -> V_24 -> V_60 [ 0 ] , F_19 ,
V_96 , V_97 , V_1 ) ;
if ( V_83 != 0 )
V_1 -> V_95 -- ;
}
F_9 ( & V_1 -> V_94 ) ;
return V_83 ;
}
static int F_29 ( struct V_80 * V_41 )
{
struct V_1 * V_1 = V_41 -> V_16 ;
struct V_27 * V_28 = V_41 -> V_82 -> V_16 ;
F_30 ( V_28 -> V_49 & V_50 ) ;
V_28 -> V_41 = NULL ;
F_7 ( & V_1 -> V_94 ) ;
if ( ! -- V_1 -> V_95 )
F_31 ( V_1 -> V_24 -> V_60 [ 0 ] , V_1 ) ;
F_9 ( & V_1 -> V_94 ) ;
return 0 ;
}
static int F_32 ( struct V_80 * V_41 )
{
struct V_27 * V_28 = V_41 -> V_82 -> V_16 ;
F_30 ( V_28 -> V_49 & V_50 ) ;
if ( V_28 -> V_98 )
F_33 ( V_28 -> V_89 ) ;
V_28 -> V_98 = 0 ;
F_34 ( V_41 ) ;
return 0 ;
}
static int F_35 ( struct V_80 * V_41 ,
struct V_67 * V_99 )
{
struct V_27 * V_28 = V_41 -> V_82 -> V_16 ;
unsigned int V_100 = F_36 ( V_99 ) ;
unsigned int V_101 = F_37 ( V_99 ) ;
int V_102 = V_101 > 48000 ;
int V_103 ;
F_32 ( V_41 ) ;
if ( V_28 -> V_98 ) {
F_33 ( V_28 -> V_89 ) ;
V_28 -> V_98 = 0 ;
}
if ( V_102 && V_100 != 2 )
return - V_104 ;
V_103 = F_38 ( V_41 ,
F_39 ( V_99 ) ) ;
if ( V_103 >= 0 ) {
struct V_1 * V_1 = V_41 -> V_16 ;
V_103 = F_40 ( V_28 -> V_89 , V_101 , V_100 ,
V_28 -> V_89 -> V_76 [ V_102 ] . V_73 ) ;
V_28 -> V_98 = V_103 == 0 ;
V_28 -> V_49 = V_105 | V_106 | V_107 ;
V_28 -> V_49 |= V_108 [ V_100 + V_102 * 2 ] ;
V_28 -> V_46 = V_1 -> V_93 * 4 / 2 ;
}
return V_103 ;
}
static int F_41 ( struct V_80 * V_41 )
{
struct V_81 * V_82 = V_41 -> V_82 ;
struct V_27 * V_28 = V_82 -> V_16 ;
V_28 -> V_48 = F_42 ( V_41 ) ;
V_28 -> V_42 = V_82 -> V_109 ;
V_28 -> V_53 = V_28 -> V_42 + F_43 ( V_41 ) ;
V_28 -> V_40 = V_28 -> V_42 ;
V_28 -> V_47 = V_28 -> V_48 ;
return 0 ;
}
static T_3 F_44 ( struct V_80 * V_41 )
{
struct V_81 * V_82 = V_41 -> V_82 ;
struct V_27 * V_28 = V_82 -> V_16 ;
T_4 V_47 = V_28 -> V_40 - V_28 -> V_42 ;
return F_45 ( V_82 , V_47 ) ;
}
static void F_46 ( struct V_27 * V_28 )
{
T_1 V_110 ;
V_110 = F_3 ( V_28 -> V_7 + V_43 ) ;
V_110 &= ~ ( V_111 | V_112 ) ;
F_4 ( V_110 , V_28 -> V_7 + V_43 ) ;
V_28 -> V_49 &= ~ V_50 ;
F_13 ( V_28 , V_113 ) ;
F_4 ( V_28 -> V_49 , V_28 -> V_7 + V_114 ) ;
}
static void F_47 ( struct V_27 * V_28 )
{
T_1 V_110 ;
F_13 ( V_28 , V_113 ) ;
V_28 -> V_49 |= V_50 ;
V_110 = F_3 ( V_28 -> V_7 + V_43 ) ;
V_110 |= V_111 | V_112 ;
F_4 ( V_110 , V_28 -> V_7 + V_43 ) ;
F_4 ( V_28 -> V_49 , V_28 -> V_7 + V_114 ) ;
}
static int F_48 ( struct V_80 * V_41 , int V_115 )
{
struct V_27 * V_28 = V_41 -> V_82 -> V_16 ;
unsigned long V_116 ;
int V_83 = 0 ;
F_49 ( & V_28 -> V_44 , V_116 ) ;
switch ( V_115 ) {
case V_117 :
F_47 ( V_28 ) ;
break;
case V_118 :
F_47 ( V_28 ) ;
break;
case V_119 :
F_46 ( V_28 ) ;
break;
case V_120 :
F_46 ( V_28 ) ;
break;
case V_121 :
break;
case V_122 :
break;
default:
V_83 = - V_104 ;
}
F_50 ( & V_28 -> V_44 , V_116 ) ;
return V_83 ;
}
static void F_51 ( struct V_27 * V_28 )
{
T_1 V_110 ;
F_13 ( V_28 , V_123 ) ;
V_110 = F_3 ( V_28 -> V_7 + V_43 ) ;
V_110 &= ~ ( V_124 | V_125 ) ;
F_4 ( V_110 , V_28 -> V_7 + V_43 ) ;
V_28 -> V_49 &= ~ V_50 ;
F_4 ( V_28 -> V_49 , V_28 -> V_7 + V_126 ) ;
}
static void F_52 ( struct V_27 * V_28 )
{
T_1 V_110 ;
F_13 ( V_28 , V_123 ) ;
#ifdef F_53
V_28 -> V_49 |= 0xf << 17 ;
#endif
V_28 -> V_49 |= V_50 ;
F_4 ( V_28 -> V_49 , V_28 -> V_7 + V_126 ) ;
V_110 = F_3 ( V_28 -> V_7 + V_43 ) ;
V_110 |= V_124 | V_125 ;
F_4 ( V_110 , V_28 -> V_7 + V_43 ) ;
}
static int F_54 ( struct V_80 * V_41 , int V_115 )
{
struct V_27 * V_28 = V_41 -> V_82 -> V_16 ;
unsigned long V_116 ;
int V_83 = 0 ;
F_49 ( & V_28 -> V_44 , V_116 ) ;
switch ( V_115 ) {
case V_117 :
F_52 ( V_28 ) ;
break;
case V_118 :
F_52 ( V_28 ) ;
break;
case V_119 :
F_51 ( V_28 ) ;
break;
case V_120 :
F_51 ( V_28 ) ;
break;
case V_121 :
break;
case V_122 :
break;
default:
V_83 = - V_104 ;
}
F_50 ( & V_28 -> V_44 , V_116 ) ;
return V_83 ;
}
static int F_55 ( struct V_80 * V_41 )
{
struct V_81 * V_82 = V_41 -> V_82 ;
struct V_1 * V_1 = V_41 -> V_16 ;
F_41 ( V_41 ) ;
F_6 ( V_1 -> V_3 , V_127 , 0x0001 ) ;
F_6 ( V_1 -> V_3 , V_128 , V_82 -> V_101 ) ;
F_6 ( V_1 -> V_3 , V_129 , V_82 -> V_101 ) ;
F_6 ( V_1 -> V_3 , V_130 , 0x0404 ) ;
return 0 ;
}
static int F_56 ( struct V_131 * V_132 , unsigned int V_133 )
{
struct V_1 * V_1 = V_132 -> V_16 ;
F_57 ( V_132 , V_134 ) ;
F_58 ( V_1 -> V_89 ) ;
return 0 ;
}
static int F_59 ( struct V_131 * V_132 , unsigned int V_133 )
{
F_57 ( V_132 , V_135 ) ;
return 0 ;
}
static int F_60 ( struct V_136 * V_24 , T_5 V_133 )
{
struct V_131 * V_132 = F_61 ( V_24 ) ;
return V_132 ? F_56 ( V_132 ) : 0 ;
}
static int F_62 ( struct V_136 * V_24 )
{
struct V_131 * V_132 = F_61 ( V_24 ) ;
return V_132 ? F_59 ( V_132 ) : 0 ;
}
static int T_6 F_63 ( struct V_1 * V_1 )
{
struct V_137 V_138 ;
struct V_139 * V_74 ;
struct V_2 * V_3 ;
int V_83 ;
F_4 ( 0 , V_1 -> V_7 + V_140 ) ;
F_5 ( 2 ) ;
F_4 ( V_141 , V_1 -> V_7 + V_140 ) ;
F_5 ( V_21 * 2 ) ;
V_83 = V_139 ( V_1 -> V_132 , 0 , & V_142 , V_1 , & V_74 ) ;
if ( V_83 )
goto V_26;
V_74 -> clock = 48000 ;
V_1 -> V_74 = V_74 ;
memset ( & V_138 , 0 , sizeof( struct V_137 ) ) ;
V_138 . V_16 = V_1 ;
V_138 . V_6 = 0 ;
V_138 . V_143 = V_144 ;
V_83 = F_64 ( V_74 , & V_138 , & V_3 ) ;
if ( V_83 )
goto V_26;
V_1 -> V_3 = V_3 ;
if ( F_65 ( V_3 ) )
F_66 ( V_3 , V_145 , 0x801e ) ;
V_83 = F_67 ( V_74 , F_23 ( V_146 ) , V_146 ) ;
if ( V_83 )
goto V_26;
V_1 -> V_57 . V_89 = & V_74 -> V_75 [ 0 ] ;
V_1 -> V_38 . V_89 = & V_74 -> V_75 [ 1 ] ;
V_26:
return V_83 ;
}
static void F_68 ( struct V_131 * V_132 )
{
struct V_1 * V_1 = V_132 -> V_16 ;
if ( V_1 -> V_7 )
F_69 ( V_1 -> V_7 ) ;
}
static struct V_1 * T_6 F_70 ( struct V_136 * V_24 )
{
struct V_1 * V_1 ;
struct V_131 * V_132 ;
int V_103 ;
V_103 = F_71 ( V_147 , V_148 ,
V_149 , sizeof( struct V_1 ) , & V_132 ) ;
if ( V_103 < 0 )
return NULL ;
V_132 -> V_150 = F_68 ;
F_72 ( V_132 -> V_151 , V_97 , sizeof( V_132 -> V_151 ) ) ;
F_72 ( V_132 -> V_152 , L_11 , sizeof( V_132 -> V_152 ) ) ;
snprintf ( V_132 -> V_153 , sizeof( V_132 -> V_153 ) ,
L_12 ,
V_132 -> V_152 , F_73 ( V_24 ) , F_74 ( V_24 ) ,
( unsigned long long ) V_24 -> V_154 . V_42 , V_24 -> V_60 [ 0 ] ) ;
V_1 = V_132 -> V_16 ;
F_75 ( & V_1 -> V_18 ) ;
F_75 ( & V_1 -> V_94 ) ;
V_1 -> V_132 = V_132 ;
V_1 -> V_24 = V_24 ;
V_1 -> V_5 = V_155 | V_156 | V_157 |
V_158 | V_159 ;
return V_1 ;
}
static int T_6 F_76 ( struct V_1 * V_1 )
{
struct V_160 * V_89 ;
int V_83 ;
V_83 = F_77 ( V_1 -> V_132 , L_13 , 0 , 1 , 1 , & V_89 ) ;
if ( V_83 == 0 ) {
V_1 -> V_89 = V_89 ;
V_89 -> V_16 = V_1 ;
V_89 -> V_161 = 0 ;
F_72 ( V_89 -> V_162 , V_97 , sizeof( V_89 -> V_162 ) ) ;
F_78 ( V_89 , V_85 , & V_163 ) ;
F_78 ( V_89 , V_164 , & V_165 ) ;
F_79 ( V_89 , V_166 ,
NULL , 0 , 64 * 1024 ) ;
}
return V_83 ;
}
static unsigned int T_6 F_80 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = & V_1 -> V_57 ;
int V_62 ;
F_4 ( V_105 | V_107 | V_50 , V_28 -> V_7 + V_114 ) ;
for ( V_62 = 0 ; ! ( F_3 ( V_28 -> V_7 + V_30 ) & V_167 ) && V_62 < 4096 ; V_62 ++ )
F_4 ( 0 , V_28 -> V_168 ) ;
F_4 ( 0 , V_28 -> V_7 + V_114 ) ;
F_4 ( V_1 -> V_5 & ~ V_155 , V_1 -> V_7 + V_13 ) ;
F_3 ( V_1 -> V_7 + V_13 ) ;
F_5 ( 1 ) ;
F_4 ( V_1 -> V_5 , V_1 -> V_7 + V_13 ) ;
if ( V_62 == 4096 )
V_62 = 8 ;
return V_62 ;
}
static int T_6 F_81 ( struct V_136 * V_24 ,
const struct V_169 * V_170 )
{
struct V_1 * V_1 ;
int V_83 , V_62 ;
V_83 = F_82 ( V_24 , NULL ) ;
if ( V_83 )
return V_83 ;
V_1 = F_70 ( V_24 ) ;
if ( ! V_1 ) {
V_83 = - V_171 ;
goto V_26;
}
V_1 -> V_7 = F_83 ( V_24 -> V_154 . V_42 , F_84 ( & V_24 -> V_154 ) ) ;
if ( ! V_1 -> V_7 ) {
V_83 = - V_171 ;
goto V_26;
}
F_85 ( & V_1 -> V_57 . V_44 ) ;
V_1 -> V_57 . V_7 = V_1 -> V_7 + V_172 ;
V_1 -> V_57 . V_168 = V_1 -> V_7 + V_173 ;
F_85 ( & V_1 -> V_38 . V_44 ) ;
V_1 -> V_38 . V_7 = V_1 -> V_7 + V_172 ;
V_1 -> V_38 . V_168 = V_1 -> V_7 + V_173 ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
void T_7 * V_7 = V_1 -> V_7 + V_62 * 0x14 ;
F_4 ( 0 , V_7 + V_43 ) ;
F_4 ( 0 , V_7 + V_114 ) ;
F_4 ( 0 , V_7 + V_126 ) ;
}
F_4 ( 0x1fff , V_1 -> V_7 + V_34 ) ;
F_4 ( V_1 -> V_5 , V_1 -> V_7 + V_13 ) ;
F_3 ( V_1 -> V_7 + V_172 ) ;
V_83 = F_63 ( V_1 ) ;
if ( V_83 )
goto V_26;
V_1 -> V_93 = F_80 ( V_1 ) ;
if ( V_1 -> V_93 & 15 ) {
F_86 ( V_174 L_14 ,
V_1 -> V_93 ) ;
V_83 = - V_175 ;
goto V_26;
}
V_83 = F_76 ( V_1 ) ;
if ( V_83 )
goto V_26;
F_87 ( V_1 -> V_132 , & V_24 -> V_24 ) ;
V_83 = F_88 ( V_1 -> V_132 ) ;
if ( V_83 == 0 ) {
F_89 ( & V_24 -> V_24 , L_15 , V_1 -> V_132 -> V_153 ) ;
F_89 ( & V_24 -> V_24 , L_16 , V_1 -> V_93 ) ;
F_90 ( V_24 , V_1 -> V_132 ) ;
return V_83 ;
}
V_26:
if ( V_1 )
F_91 ( V_1 -> V_132 ) ;
F_92 ( V_24 ) ;
return V_83 ;
}
static int T_8 F_93 ( struct V_136 * V_24 )
{
struct V_131 * V_132 = F_61 ( V_24 ) ;
F_90 ( V_24 , NULL ) ;
if ( V_132 ) {
struct V_1 * V_1 = V_132 -> V_16 ;
F_4 ( 0 , V_1 -> V_7 + V_13 ) ;
F_91 ( V_132 ) ;
F_92 ( V_24 ) ;
}
return 0 ;
}
static int T_9 F_94 ( void )
{
return F_95 ( & V_176 ) ;
}
static void T_10 F_96 ( void )
{
F_97 ( & V_176 ) ;
}

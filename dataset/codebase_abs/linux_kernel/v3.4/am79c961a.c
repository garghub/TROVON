static void F_1 ( T_1 V_1 , T_2 V_2 , T_2 V_3 )
{
asm volatile(
"str%?h %1, [%2] @ NET_RAP\n\t"
"str%?h %0, [%2, #-4] @ NET_RDP"
:
: "r" (val), "r" (reg), "r" (ISAIO_BASE + 0x0464));
}
static inline unsigned short F_2 ( T_1 V_4 , T_2 V_2 )
{
unsigned short V_5 ;
asm volatile(
"str%?h %1, [%2] @ NET_RAP\n\t"
"ldr%?h %0, [%2, #-4] @ NET_RDP"
: "=r" (v)
: "r" (reg), "r" (ISAIO_BASE + 0x0464));
return V_5 ;
}
static inline void F_3 ( T_1 V_1 , T_2 V_2 , T_2 V_3 )
{
asm volatile(
"str%?h %1, [%2] @ NET_RAP\n\t"
"str%?h %0, [%2, #8] @ NET_IDP"
:
: "r" (val), "r" (reg), "r" (ISAIO_BASE + 0x0464));
}
static inline unsigned short F_4 ( T_1 V_4 , T_2 V_2 )
{
T_3 V_5 ;
asm volatile(
"str%?h %1, [%2] @ NAT_RAP\n\t"
"ldr%?h %0, [%2, #8] @ NET_IDP\n\t"
: "=r" (v)
: "r" (reg), "r" (ISAIO_BASE + 0x0464));
return V_5 ;
}
static void
F_5 ( struct V_6 * V_7 , T_2 V_8 , unsigned char * V_9 , unsigned int V_10 )
{
V_8 = V_11 + ( V_8 << 1 ) ;
V_10 = ( V_10 + 1 ) & ~ 1 ;
if ( ( int ) V_9 & 2 ) {
asm volatile("str%?h %2, [%0], #4"
: "=&r" (offset) : "0" (offset), "r" (buf[0] | (buf[1] << 8)));
V_9 += 2 ;
V_10 -= 2 ;
}
while ( V_10 > 8 ) {
register unsigned int T_4 V_12 ( L_1 ) , V_13 V_12 ( L_2 ) ;
asm volatile(
"ldm%?ia %0!, {%1, %2}"
: "+r" (buf), "=&r" (tmp), "=&r" (tmp2));
V_10 -= 8 ;
asm volatile(
"str%?h %1, [%0], #4\n\t"
"mov%? %1, %1, lsr #16\n\t"
"str%?h %1, [%0], #4\n\t"
"str%?h %2, [%0], #4\n\t"
"mov%? %2, %2, lsr #16\n\t"
"str%?h %2, [%0], #4"
: "+r" (offset), "=&r" (tmp), "=&r" (tmp2));
}
while ( V_10 > 0 ) {
asm volatile("str%?h %2, [%0], #4"
: "=&r" (offset) : "0" (offset), "r" (buf[0] | (buf[1] << 8)));
V_9 += 2 ;
V_10 -= 2 ;
}
}
static void
F_6 ( struct V_6 * V_7 , T_2 V_8 , unsigned char * V_9 , unsigned int V_10 )
{
V_8 = V_11 + ( V_8 << 1 ) ;
V_10 = ( V_10 + 1 ) & ~ 1 ;
if ( ( int ) V_9 & 2 ) {
unsigned int T_4 ;
asm volatile(
"ldr%?h %2, [%0], #4\n\t"
"str%?b %2, [%1], #1\n\t"
"mov%? %2, %2, lsr #8\n\t"
"str%?b %2, [%1], #1"
: "=&r" (offset), "=&r" (buf), "=r" (tmp): "0" (offset), "1" (buf));
V_10 -= 2 ;
}
while ( V_10 > 8 ) {
register unsigned int T_4 V_12 ( L_1 ) , V_13 V_12 ( L_2 ) , V_14 ;
asm volatile(
"ldr%?h %2, [%0], #4\n\t"
"ldr%?h %4, [%0], #4\n\t"
"ldr%?h %3, [%0], #4\n\t"
"orr%? %2, %2, %4, lsl #16\n\t"
"ldr%?h %4, [%0], #4\n\t"
"orr%? %3, %3, %4, lsl #16\n\t"
"stm%?ia %1!, {%2, %3}"
: "=&r" (offset), "=&r" (buf), "=r" (tmp), "=r" (tmp2), "=r" (tmp3)
: "0" (offset), "1" (buf));
V_10 -= 8 ;
}
while ( V_10 > 0 ) {
unsigned int T_4 ;
asm volatile(
"ldr%?h %2, [%0], #4\n\t"
"str%?b %2, [%1], #1\n\t"
"mov%? %2, %2, lsr #8\n\t"
"str%?b %2, [%1], #1"
: "=&r" (offset), "=&r" (buf), "=r" (tmp) : "0" (offset), "1" (buf));
V_10 -= 2 ;
}
}
static int
F_7 ( struct V_6 * V_7 , unsigned int V_3 )
{
unsigned char * V_15 = F_8 ( 65536 , V_16 ) ;
int V_17 , error = 0 , V_18 = 0 ;
if ( ! V_15 )
return 0 ;
memset ( V_15 , V_3 , 65536 ) ;
F_5 ( V_7 , 0 , V_15 , 65536 ) ;
memset ( V_15 , V_3 ^ 255 , 65536 ) ;
F_6 ( V_7 , 0 , V_15 , 65536 ) ;
for ( V_17 = 0 ; V_17 < 65536 ; V_17 ++ ) {
if ( V_15 [ V_17 ] != V_3 && ! error ) {
F_9 ( L_3 , V_7 -> V_19 , V_3 , V_15 [ V_17 ] , V_17 ) ;
error = 1 ;
V_18 ++ ;
} else if ( error && V_15 [ V_17 ] == V_3 ) {
F_9 ( L_4 , V_17 ) ;
error = 0 ;
}
}
if ( error )
F_9 ( L_5 ) ;
F_10 ( V_15 ) ;
return V_18 ;
}
static void F_11 ( char * V_20 , T_5 * V_21 )
{
int V_22 , V_23 ;
T_6 V_24 ;
V_24 = F_12 ( V_25 , V_20 ) ;
V_22 = V_24 >> 30 ;
V_23 = ( V_24 >> 26 ) & 15 ;
V_21 [ V_22 ] |= 1 << V_23 ;
}
static unsigned int F_13 ( struct V_6 * V_7 , T_5 * V_21 )
{
unsigned int V_26 = V_27 ;
if ( V_7 -> V_28 & V_29 ) {
V_26 |= V_30 ;
memset ( V_21 , 0xff , 4 * sizeof( * V_21 ) ) ;
} else if ( V_7 -> V_28 & V_31 ) {
memset ( V_21 , 0xff , 4 * sizeof( * V_21 ) ) ;
} else {
struct V_32 * V_33 ;
memset ( V_21 , 0 , 4 * sizeof( * V_21 ) ) ;
F_14 (ha, dev)
F_11 ( V_33 -> V_20 , V_21 ) ;
}
return V_26 ;
}
static void
F_15 ( struct V_6 * V_7 )
{
struct V_34 * V_35 = F_16 ( V_7 ) ;
unsigned long V_28 ;
unsigned char * V_36 ;
T_2 V_37 , V_38 ;
T_5 V_39 [ 4 ] , V_26 = F_13 ( V_7 , V_39 ) ;
int V_17 ;
F_17 ( & V_35 -> V_40 , V_28 ) ;
F_1 ( V_7 -> V_4 , V_41 , V_42 | V_43 | V_44 | V_45 | V_46 | V_47 | V_48 ) ;
F_18 ( & V_35 -> V_40 , V_28 ) ;
F_3 ( V_7 -> V_4 , 5 , 0x00a0 ) ;
F_3 ( V_7 -> V_4 , 6 , 0x0081 ) ;
F_3 ( V_7 -> V_4 , 7 , 0x0090 ) ;
F_3 ( V_7 -> V_4 , 2 , 0x0000 ) ;
for ( V_17 = V_49 ; V_17 <= V_50 ; V_17 ++ )
F_1 ( V_7 -> V_4 , V_17 , V_39 [ V_17 - V_49 ] ) ;
for ( V_17 = V_51 , V_36 = V_7 -> V_52 ; V_17 <= V_53 ; V_17 ++ , V_36 += 2 )
F_1 ( V_7 -> V_4 , V_17 , V_36 [ 0 ] | ( V_36 [ 1 ] << 8 ) ) ;
F_1 ( V_7 -> V_4 , V_54 , V_26 ) ;
F_1 ( V_7 -> V_4 , V_55 , 0 ) ;
F_1 ( V_7 -> V_4 , V_56 , - V_57 ) ;
F_1 ( V_7 -> V_4 , V_58 , - V_59 ) ;
V_38 = V_57 * 8 + V_59 * 8 + 16 ;
V_37 = 0 ;
V_35 -> V_60 = 0 ;
V_35 -> V_61 = 0 ;
V_35 -> V_62 = V_37 ;
for ( V_17 = 0 ; V_17 < V_57 ; V_17 ++ ) {
V_35 -> V_63 [ V_17 ] = V_38 ;
F_19 ( V_7 , V_37 , V_38 ) ;
F_19 ( V_7 , V_37 + 2 , V_64 ) ;
F_19 ( V_7 , V_37 + 4 , ( - 1600 ) ) ;
F_19 ( V_7 , V_37 + 6 , 0 ) ;
V_38 += 1600 ;
V_37 += 8 ;
}
V_35 -> V_65 = 0 ;
V_35 -> V_66 = 0 ;
V_35 -> V_67 = V_37 ;
for ( V_17 = 0 ; V_17 < V_59 ; V_17 ++ ) {
V_35 -> V_68 [ V_17 ] = V_38 ;
F_19 ( V_7 , V_37 , V_38 ) ;
F_19 ( V_7 , V_37 + 2 , V_69 | V_70 ) ;
F_19 ( V_7 , V_37 + 4 , 0xf000 ) ;
F_19 ( V_7 , V_37 + 6 , 0 ) ;
V_38 += 1600 ;
V_37 += 8 ;
}
F_1 ( V_7 -> V_4 , V_71 , V_35 -> V_62 ) ;
F_1 ( V_7 -> V_4 , V_72 , 0 ) ;
F_1 ( V_7 -> V_4 , V_73 , V_35 -> V_67 ) ;
F_1 ( V_7 -> V_4 , V_72 , 0 ) ;
F_1 ( V_7 -> V_4 , V_41 , V_48 ) ;
F_1 ( V_7 -> V_4 , V_74 , V_75 | V_76 | V_77 ) ;
F_1 ( V_7 -> V_4 , V_78 , V_79 | V_80 | V_81 | V_82 | V_83 ) ;
F_1 ( V_7 -> V_4 , V_41 , V_84 | V_85 ) ;
}
static void F_20 ( unsigned long V_86 )
{
struct V_6 * V_7 = (struct V_6 * ) V_86 ;
struct V_34 * V_35 = F_16 ( V_7 ) ;
unsigned int V_87 , V_88 ;
unsigned long V_28 ;
F_17 ( & V_35 -> V_40 , V_28 ) ;
V_87 = F_4 ( V_7 -> V_4 , V_89 ) & V_90 ;
F_18 ( & V_35 -> V_40 , V_28 ) ;
V_88 = F_21 ( V_7 ) ;
if ( V_87 && ! V_88 ) {
F_22 ( V_7 ) ;
F_9 ( L_6 , V_7 -> V_19 ) ;
} else if ( ! V_87 && V_88 ) {
F_23 ( V_7 ) ;
F_9 ( L_7 , V_7 -> V_19 ) ;
}
F_24 ( & V_35 -> V_91 , V_92 + F_25 ( 500 ) ) ;
}
static int
F_26 ( struct V_6 * V_7 )
{
struct V_34 * V_35 = F_16 ( V_7 ) ;
int V_93 ;
V_93 = F_27 ( V_7 -> V_94 , V_95 , 0 , V_7 -> V_19 , V_7 ) ;
if ( V_93 )
return V_93 ;
F_15 ( V_7 ) ;
F_23 ( V_7 ) ;
V_35 -> V_91 . V_96 = V_92 ;
F_28 ( & V_35 -> V_91 ) ;
F_29 ( V_7 ) ;
return 0 ;
}
static int
F_30 ( struct V_6 * V_7 )
{
struct V_34 * V_35 = F_16 ( V_7 ) ;
unsigned long V_28 ;
F_31 ( & V_35 -> V_91 ) ;
F_32 ( V_7 ) ;
F_23 ( V_7 ) ;
F_17 ( & V_35 -> V_40 , V_28 ) ;
F_1 ( V_7 -> V_4 , V_41 , V_48 ) ;
F_1 ( V_7 -> V_4 , V_74 , V_97 ) ;
F_18 ( & V_35 -> V_40 , V_28 ) ;
F_33 ( V_7 -> V_94 , V_7 ) ;
return 0 ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_34 * V_35 = F_16 ( V_7 ) ;
unsigned long V_28 ;
T_5 V_39 [ 4 ] , V_26 = F_13 ( V_7 , V_39 ) ;
int V_17 , V_98 ;
F_17 ( & V_35 -> V_40 , V_28 ) ;
V_98 = F_2 ( V_7 -> V_4 , V_41 ) & V_48 ;
if ( ! V_98 ) {
F_1 ( V_7 -> V_4 , V_99 , V_100 ) ;
while ( ( F_2 ( V_7 -> V_4 , V_99 ) & V_100 ) == 0 ) {
F_18 ( & V_35 -> V_40 , V_28 ) ;
F_35 () ;
F_17 ( & V_35 -> V_40 , V_28 ) ;
}
}
for ( V_17 = 0 ; V_17 < F_36 ( V_39 ) ; V_17 ++ )
F_1 ( V_7 -> V_4 , V_17 + V_49 , V_39 [ V_17 ] ) ;
F_1 ( V_7 -> V_4 , V_54 , V_26 ) ;
if ( ! V_98 ) {
F_1 ( V_7 -> V_4 , V_99 , 0 ) ;
}
F_18 ( & V_35 -> V_40 , V_28 ) ;
}
static void F_37 ( struct V_6 * V_7 )
{
F_9 ( V_101 L_8 ,
V_7 -> V_19 ) ;
F_38 ( V_7 ) ;
}
static int
F_39 ( struct V_102 * V_103 , struct V_6 * V_7 )
{
struct V_34 * V_35 = F_16 ( V_7 ) ;
unsigned int V_104 , V_105 ;
unsigned int V_106 ;
unsigned long V_28 ;
V_106 = V_35 -> V_65 ;
V_104 = V_35 -> V_67 + ( V_106 << 3 ) ;
V_105 = V_35 -> V_68 [ V_106 ] ;
V_106 += 1 ;
if ( V_106 >= V_59 )
V_106 = 0 ;
F_5 ( V_7 , V_105 , V_103 -> V_86 , V_103 -> V_107 ) ;
F_19 ( V_7 , V_104 + 4 , - V_103 -> V_107 ) ;
F_19 ( V_7 , V_104 + 2 , V_108 | V_69 | V_70 ) ;
V_35 -> V_65 = V_106 ;
F_17 ( & V_35 -> V_40 , V_28 ) ;
F_1 ( V_7 -> V_4 , V_41 , V_109 | V_84 ) ;
F_18 ( & V_35 -> V_40 , V_28 ) ;
if ( F_40 ( V_7 , V_35 -> V_67 + ( V_35 -> V_65 << 3 ) + 2 ) & V_108 )
F_32 ( V_7 ) ;
F_41 ( V_103 ) ;
return V_110 ;
}
static void
F_42 ( struct V_6 * V_7 , struct V_34 * V_35 )
{
do {
struct V_102 * V_103 ;
T_2 V_104 ;
T_2 V_111 ;
T_2 V_112 ;
int V_107 ;
V_104 = V_35 -> V_62 + ( V_35 -> V_61 << 3 ) ;
V_111 = V_35 -> V_63 [ V_35 -> V_61 ] ;
V_112 = F_40 ( V_7 , V_104 + 2 ) ;
if ( V_112 & V_64 )
break;
V_35 -> V_61 ++ ;
if ( V_35 -> V_61 >= V_57 )
V_35 -> V_61 = 0 ;
if ( ( V_112 & ( V_113 | V_114 | V_115 ) ) != ( V_114 | V_115 ) ) {
F_19 ( V_7 , V_104 + 2 , V_64 ) ;
V_7 -> V_116 . V_117 ++ ;
if ( V_112 & V_113 ) {
if ( V_112 & V_118 )
V_7 -> V_116 . V_119 ++ ;
if ( V_112 & V_120 )
V_7 -> V_116 . V_121 ++ ;
} else if ( V_112 & V_114 )
V_7 -> V_116 . V_122 ++ ;
continue;
}
V_107 = F_40 ( V_7 , V_104 + 6 ) ;
V_103 = F_43 ( V_7 , V_107 + 2 ) ;
if ( V_103 ) {
F_44 ( V_103 , 2 ) ;
F_6 ( V_7 , V_111 , F_45 ( V_103 , V_107 ) , V_107 ) ;
F_19 ( V_7 , V_104 + 2 , V_64 ) ;
V_103 -> V_123 = F_46 ( V_103 , V_7 ) ;
F_47 ( V_103 ) ;
V_7 -> V_116 . V_124 += V_107 ;
V_7 -> V_116 . V_125 ++ ;
} else {
F_19 ( V_7 , V_104 + 2 , V_64 ) ;
F_9 ( V_101 L_9 , V_7 -> V_19 ) ;
V_7 -> V_116 . V_126 ++ ;
break;
}
} while ( 1 );
}
static void
F_48 ( struct V_6 * V_7 , struct V_34 * V_35 )
{
do {
short V_107 ;
T_2 V_104 ;
T_2 V_112 ;
V_104 = V_35 -> V_67 + ( V_35 -> V_66 << 3 ) ;
V_112 = F_40 ( V_7 , V_104 + 2 ) ;
if ( V_112 & V_108 )
break;
V_35 -> V_66 ++ ;
if ( V_35 -> V_66 >= V_59 )
V_35 -> V_66 = 0 ;
if ( V_112 & V_127 ) {
T_2 V_128 ;
V_7 -> V_116 . V_129 ++ ;
V_128 = F_40 ( V_7 , V_104 + 6 ) ;
F_19 ( V_7 , V_104 + 6 , 0 ) ;
if ( V_128 & V_130 )
V_7 -> V_116 . V_131 += 16 ;
if ( V_128 & V_132 )
V_7 -> V_116 . V_133 ++ ;
if ( V_128 & V_134 )
V_7 -> V_116 . V_135 ++ ;
if ( V_128 & V_136 )
V_7 -> V_116 . V_137 ++ ;
continue;
}
V_7 -> V_116 . V_138 ++ ;
V_107 = F_40 ( V_7 , V_104 + 4 ) ;
V_7 -> V_116 . V_139 += - V_107 ;
} while ( V_35 -> V_66 != V_35 -> V_65 );
F_38 ( V_7 ) ;
}
static T_7
V_95 ( int V_94 , void * V_140 )
{
struct V_6 * V_7 = (struct V_6 * ) V_140 ;
struct V_34 * V_35 = F_16 ( V_7 ) ;
T_2 V_112 , V_141 = 100 ;
int V_142 = 0 ;
do {
V_112 = F_2 ( V_7 -> V_4 , V_41 ) ;
F_1 ( V_7 -> V_4 , V_41 , V_112 &
( V_84 | V_46 | V_47 |
V_45 | V_44 | V_43 | V_42 ) ) ;
if ( V_112 & V_47 ) {
V_142 = 1 ;
F_42 ( V_7 , V_35 ) ;
}
if ( V_112 & V_46 ) {
V_142 = 1 ;
F_48 ( V_7 , V_35 ) ;
}
if ( V_112 & V_44 ) {
V_142 = 1 ;
V_7 -> V_116 . V_126 ++ ;
}
if ( V_112 & V_43 ) {
V_142 = 1 ;
F_24 ( & V_35 -> V_91 , V_92 ) ;
}
} while ( -- V_141 && V_112 & ( V_47 | V_46 ) );
return F_49 ( V_142 ) ;
}
static void F_50 ( struct V_6 * V_7 )
{
unsigned long V_28 ;
F_51 ( V_28 ) ;
V_95 ( V_7 -> V_94 , V_7 ) ;
F_52 ( V_28 ) ;
}
static int
F_53 ( struct V_6 * V_7 )
{
struct V_34 * V_35 = F_16 ( V_7 ) ;
F_54 ( & V_35 -> V_40 ) ;
F_1 ( V_7 -> V_4 , V_41 , V_48 ) ;
F_1 ( V_7 -> V_4 , V_74 , V_97 ) ;
F_55 ( & V_35 -> V_40 ) ;
F_7 ( V_7 , 0x66 ) ;
F_7 ( V_7 , 0x99 ) ;
return 0 ;
}
static void T_8 F_56 ( void )
{
static unsigned V_143 ;
if ( V_144 && V_143 ++ == 0 )
F_9 ( V_145 L_10 , V_146 ) ;
}
static int T_9 F_57 ( struct V_147 * V_148 )
{
struct V_149 * V_150 ;
struct V_6 * V_7 ;
struct V_34 * V_35 ;
int V_17 , V_93 ;
V_150 = F_58 ( V_148 , V_151 , 0 ) ;
if ( ! V_150 )
return - V_152 ;
V_7 = F_59 ( sizeof( struct V_34 ) ) ;
V_93 = - V_153 ;
if ( ! V_7 )
goto V_154;
F_60 ( V_7 , & V_148 -> V_7 ) ;
V_35 = F_16 ( V_7 ) ;
V_7 -> V_4 = V_150 -> V_155 ;
V_93 = F_61 ( V_148 , 0 ) ;
if ( V_93 < 0 ) {
V_93 = - V_152 ;
goto V_156;
}
V_7 -> V_94 = V_93 ;
V_93 = - V_152 ;
if ( ! F_62 ( V_7 -> V_4 , 0x18 , V_7 -> V_19 ) )
goto V_156;
F_63 ( V_7 -> V_4 + V_157 ) ;
F_64 ( 5 ) ;
if ( F_63 ( V_7 -> V_4 ) != 0x08 ||
F_63 ( V_7 -> V_4 + 2 ) != 0x00 ||
F_63 ( V_7 -> V_4 + 4 ) != 0x2b )
goto V_158;
for ( V_17 = 0 ; V_17 < 6 ; V_17 ++ )
V_7 -> V_52 [ V_17 ] = F_63 ( V_7 -> V_4 + V_17 * 2 ) & 0xff ;
F_56 () ;
F_65 ( & V_35 -> V_40 ) ;
F_66 ( & V_35 -> V_91 ) ;
V_35 -> V_91 . V_86 = ( unsigned long ) V_7 ;
V_35 -> V_91 . V_159 = F_20 ;
if ( F_53 ( V_7 ) )
goto V_158;
V_7 -> V_160 = & V_161 ;
V_93 = F_67 ( V_7 ) ;
if ( V_93 == 0 ) {
F_9 ( V_145 L_11 ,
V_7 -> V_19 , V_7 -> V_52 ) ;
return 0 ;
}
V_158:
F_68 ( V_7 -> V_4 , 0x18 ) ;
V_156:
F_69 ( V_7 ) ;
V_154:
return V_93 ;
}
static int T_8 F_70 ( void )
{
return F_71 ( & V_162 ) ;
}

void T_1 F_1 ( void )
{
if ( V_1 ) {
extern T_2 * V_2 ;
__asm__ volatile ("movec %%vbr, %0" : "=r" (sun3x_prom_vbr));
}
__asm__ volatile ("movec %0,%%vbr" : : "r" ((void*)vectors));
if ( V_3 ) {
T_3 void V_4 ( void ) V_5 ( L_1 ) ;
V_6 [ V_7 ] = V_4 ;
}
V_6 [ V_8 ] = V_9 ;
V_6 [ V_10 ] = V_11 ;
V_6 [ V_12 ] = V_13 ;
}
void T_1 F_2 ( void )
{
int V_14 ;
for ( V_14 = V_15 ; V_14 <= V_16 ; V_14 ++ )
V_6 [ V_14 ] = V_17 ;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ )
if ( ! V_6 [ V_14 ] )
V_6 [ V_14 ] = V_11 ;
for ( V_14 = V_18 ; V_14 < 256 ; V_14 ++ )
V_6 [ V_14 ] = V_17 ;
#ifdef F_3
if ( V_19 )
V_6 [ V_20 ] = V_21 ;
#endif
if ( V_22 && ! V_19 ) {
T_3 void V_23 ( void ) V_5 ( L_2 ) ;
T_3 void V_24 ( void ) V_5 ( L_3 ) ;
T_3 void V_25 ( void ) V_5 ( L_4 ) ;
T_3 void V_26 ( void ) V_5 ( L_5 ) ;
T_3 void V_27 ( void ) V_5 ( L_6 ) ;
T_3 void V_28 ( void ) V_5 ( L_7 ) ;
T_3 void V_29 ( void ) V_5 ( L_8 ) ;
T_3 void V_30 ( void ) V_5 ( L_9 ) ;
T_3 void V_31 ( void ) V_5 ( L_10 ) ;
V_6 [ V_32 ] = V_23 ;
V_6 [ V_33 ] = V_24 ;
V_6 [ V_34 ] = V_25 ;
V_6 [ V_35 ] = V_26 ;
V_6 [ V_36 ] = V_27 ;
V_6 [ V_37 ] = V_28 ;
V_6 [ V_38 ] = V_29 ;
V_6 [ V_20 ] = V_30 ;
V_6 [ V_39 ] = V_31 ;
}
if ( V_3 && ! V_19 ) {
T_3 void V_40 ( void ) V_5 ( L_11 ) ;
T_3 void V_41 ( void ) V_5 ( L_12 ) ;
T_3 void V_42 ( void ) V_5 ( L_13 ) ;
T_3 void V_43 ( void ) V_5 ( L_14 ) ;
T_3 void V_44 ( void ) V_5 ( L_15 ) ;
T_3 void V_45 ( void ) V_5 ( L_16 ) ;
T_3 void V_46 ( void ) V_5 ( L_17 ) ;
T_3 void V_47 ( void ) V_5 ( L_18 ) ;
T_3 void V_48 ( void ) V_5 ( L_19 ) ;
V_6 [ V_36 ] = V_40 ;
V_6 [ V_37 ] = V_41 ;
V_6 [ V_34 ] = V_42 ;
V_6 [ V_35 ] = V_43 ;
V_6 [ V_32 ] = V_44 ;
V_6 [ V_33 ] = V_45 ;
V_6 [ V_20 ] = V_46 ;
V_6 [ V_39 ] = V_47 ;
V_6 [ V_49 ] = V_48 ;
}
if ( V_50 ) {
V_6 [ V_16 ] = V_51 ;
}
}
static inline void F_4 ( struct V_52 * V_53 )
{
unsigned long V_54 = V_53 -> V_55 . V_56 . V_57 ;
#ifdef F_5
F_6 ( L_20 , V_54 , V_53 -> V_55 . V_56 . V_58 ) ;
#endif
if ( V_54 & V_59 ) {
__asm__ __volatile__ ("movec %/cacr,%/d0\n\t"
"orl #0x00400000,%/d0\n\t"
"movec %/d0,%/cacr"
: : : "d0" );
if ( ! ( V_54 & V_60 ) && ! ( V_54 & V_61 ) )
return;
}
if ( V_54 & ( V_62 | V_63 | V_64 ) ) {
unsigned long V_65 ;
unsigned long V_66 = V_53 -> V_55 . V_56 . V_58 ;
if ( V_54 & V_67 )
V_66 = ( V_66 + V_68 - 1 ) & V_69 ;
V_65 = 1 ;
if ( V_54 & V_62 ) {
F_7 ( V_66 ) ;
V_65 = 0 ;
}
if ( V_54 & V_70 )
V_65 |= 2 ;
#ifdef F_5
F_6 ( L_21 , V_65 ) ;
#endif
F_8 ( & V_53 -> V_71 , V_66 , V_65 ) ;
} else if ( V_54 & ( V_61 ) ) {
F_9 ( & V_53 -> V_71 ) ;
} else if ( ! ( V_54 & ( V_72 | V_73 ) ) ||
F_9 ( & V_53 -> V_71 ) > 0 ) {
F_6 ( L_22 , V_53 -> V_71 . V_57 , V_53 -> V_55 . V_56 . V_58 ) ;
F_6 ( L_23 , V_54 ) ;
F_10 ( V_53 ) ;
}
}
static inline unsigned long F_11 ( int V_74 , unsigned long V_66 , int V_75 )
{
unsigned long V_76 ;
T_4 V_77 = F_12 () ;
F_13 ( F_14 ( V_75 ) ) ;
if ( V_74 )
asm volatile (".chip 68040; ptestw (%0); .chip 68k" : : "a" (addr));
else
asm volatile (".chip 68040; ptestr (%0); .chip 68k" : : "a" (addr));
asm volatile (".chip 68040; movec %%mmusr,%0; .chip 68k" : "=r" (mmusr));
F_13 ( V_77 ) ;
return V_76 ;
}
static inline int F_15 ( unsigned short V_75 , unsigned long V_78 ,
unsigned long V_79 )
{
int V_80 = 0 ;
T_4 V_77 = F_12 () ;
F_13 ( F_14 ( V_75 ) ) ;
switch ( V_75 & V_81 ) {
case V_82 :
V_80 = F_16 ( V_79 & 0xff , ( char V_83 * ) V_78 ) ;
break;
case V_84 :
V_80 = F_16 ( V_79 & 0xffff , ( short V_83 * ) V_78 ) ;
break;
case V_85 :
V_80 = F_16 ( V_79 , ( int V_83 * ) V_78 ) ;
break;
}
F_13 ( V_77 ) ;
#ifdef F_5
F_6 ( L_24 , V_80 ) ;
#endif
return V_80 ;
}
static inline void F_17 ( struct V_52 * V_53 , unsigned long V_78 , unsigned short V_75 )
{
V_53 -> V_55 . V_86 . V_87 = V_78 ;
V_53 -> V_55 . V_86 . V_88 = V_75 & 0xff ;
if ( V_78 != V_89 -> V_90 . V_87 )
V_53 -> V_55 . V_86 . V_88 |= V_91 ;
}
static inline void F_18 ( struct V_52 * V_53 )
{
int V_80 = 0 ;
#if 0
if (fp->un.fmt7.wb1s & WBV_040)
printk("access_error040: cannot handle 1st writeback. oops.\n");
#endif
if ( ( V_53 -> V_55 . V_86 . V_92 & V_93 ) &&
! ( V_53 -> V_55 . V_86 . V_92 & V_94 ) ) {
V_80 = F_15 ( V_53 -> V_55 . V_86 . V_92 , V_53 -> V_55 . V_86 . V_95 ,
V_53 -> V_55 . V_86 . V_96 ) ;
if ( V_80 )
F_17 ( V_53 , V_53 -> V_55 . V_86 . V_95 , V_53 -> V_55 . V_86 . V_92 ) ;
else
V_53 -> V_55 . V_86 . V_92 = 0 ;
}
if ( V_53 -> V_55 . V_86 . V_97 & V_93 && ( ! V_80 || V_53 -> V_55 . V_86 . V_97 & 4 ) ) {
V_80 = F_15 ( V_53 -> V_55 . V_86 . V_97 , V_53 -> V_55 . V_86 . V_98 ,
V_53 -> V_55 . V_86 . V_99 ) ;
if ( V_80 )
{
F_17 ( V_53 , V_53 -> V_55 . V_86 . V_98 , V_53 -> V_55 . V_86 . V_97 ) ;
V_53 -> V_55 . V_86 . V_92 = V_53 -> V_55 . V_86 . V_97 ;
V_53 -> V_55 . V_86 . V_97 &= ( ~ V_93 ) ;
V_53 -> V_55 . V_86 . V_95 = V_53 -> V_55 . V_86 . V_98 ;
V_53 -> V_55 . V_86 . V_96 = V_53 -> V_55 . V_86 . V_99 ;
}
else
V_53 -> V_55 . V_86 . V_97 = 0 ;
}
if ( V_80 )
F_9 ( & V_53 -> V_71 ) ;
}
T_3 void F_19 ( struct V_52 * V_53 )
{
V_53 -> V_55 . V_86 . V_92 &= ~ 4 ;
V_53 -> V_55 . V_86 . V_97 &= ~ 4 ;
F_18 ( V_53 ) ;
}
static inline void F_20 ( struct V_52 * V_53 )
{
unsigned short V_88 = V_53 -> V_55 . V_86 . V_88 ;
unsigned long V_76 ;
#ifdef F_5
F_6 ( L_25 , V_88 , V_53 -> V_55 . V_86 . V_87 ) ;
F_6 ( L_26 , V_53 -> V_55 . V_86 . V_100 ,
V_53 -> V_55 . V_86 . V_92 , V_53 -> V_55 . V_86 . V_97 ) ;
F_6 ( L_27 ,
V_53 -> V_55 . V_86 . V_95 , V_53 -> V_55 . V_86 . V_98 ,
V_53 -> V_55 . V_86 . V_96 , V_53 -> V_55 . V_86 . V_99 ) ;
#endif
if ( V_88 & V_101 ) {
unsigned long V_66 = V_53 -> V_55 . V_86 . V_87 ;
unsigned long V_65 ;
if ( V_88 & V_91 )
V_66 = ( V_66 + 7 ) & - 8 ;
V_76 = F_11 ( ! ( V_88 & V_102 ) , V_66 , V_88 ) ;
#ifdef F_5
F_6 ( L_28 , V_76 ) ;
#endif
V_65 = 1 ;
if ( ! ( V_76 & V_103 ) ) {
F_7 ( V_66 ) ;
V_65 = 0 ;
}
if ( ! ( V_88 & V_102 ) || ( V_88 & V_104 ) )
V_65 |= 2 ;
if ( F_8 ( & V_53 -> V_71 , V_66 , V_65 ) ) {
#ifdef F_5
F_6 ( L_29 ) ;
#endif
if ( F_21 ( & V_53 -> V_71 ) ) {
#ifdef F_5
F_6 ( L_30 ) ;
#endif
return;
}
V_105:
#ifdef F_5
F_6 ( L_31 ) ;
#endif
if ( V_53 -> V_55 . V_86 . V_95 == V_53 -> V_55 . V_86 . V_87 )
V_53 -> V_55 . V_86 . V_92 &= ~ V_93 ;
if ( V_53 -> V_55 . V_86 . V_98 == V_53 -> V_55 . V_86 . V_87 )
V_53 -> V_55 . V_86 . V_97 &= ~ V_93 ;
}
} else {
V_89 -> V_90 . V_106 = V_107 ;
V_89 -> V_90 . V_87 = V_53 -> V_55 . V_86 . V_87 ;
if ( F_9 ( & V_53 -> V_71 ) >= 0 )
F_6 ( L_32 , V_88 ,
V_53 -> V_55 . V_86 . V_87 ) ;
goto V_105;
}
F_18 ( V_53 ) ;
}
static inline void F_22 ( struct V_52 * V_53 )
{
unsigned char V_108 = F_23 () ;
unsigned long V_66 , V_65 ;
unsigned short V_88 = V_53 -> V_55 . V_109 . V_88 ;
extern unsigned long V_110 , V_111 ;
#ifdef F_5
if ( V_88 & ( V_112 | V_113 ) )
F_6 ( L_33 ,
V_88 & V_112 ?
V_53 -> V_71 . V_114 == 0xa ? V_53 -> V_71 . V_57 + 2 : V_53 -> V_55 . V_109 . V_115 - 2
:
V_53 -> V_71 . V_114 == 0xa ? V_53 -> V_71 . V_57 + 4 : V_53 -> V_55 . V_109 . V_115 ) ;
if ( V_88 & V_116 )
F_6 ( L_34 ,
V_88 & V_117 ? L_35 : L_36 ,
V_53 -> V_55 . V_109 . V_118 ,
V_119 [ V_88 & V_120 ] , V_53 -> V_71 . V_57 ) ;
#endif
if ( ( V_88 & V_116 )
&& ( V_108 & ( V_121 | V_122 ) ) ) {
if ( F_24 ( V_53 -> V_55 . V_109 . V_118 , V_88 & V_117 , 0 ) )
return;
}
if ( V_53 -> V_71 . V_123 & V_124 ) {
if ( ! ( ( V_88 & V_116 ) && ( ( V_88 & V_120 ) == V_125 ) ) ) {
if ( F_24 ( V_53 -> V_55 . V_109 . V_118 , V_88 & V_117 , 1 ) )
return;
if ( V_88 & ( V_112 | V_113 ) )
F_6 ( L_33 ,
V_53 -> V_71 . V_57 ) ;
if ( V_88 & V_116 ) {
if( ( V_53 -> V_71 . V_57 >= ( unsigned long ) & V_110 ) &&
( V_53 -> V_71 . V_57 <= ( unsigned long ) & V_111 ) ) {
F_9 ( & V_53 -> V_71 ) ;
return;
}
F_6 ( L_34 ,
V_88 & V_117 ? L_35 : L_36 ,
V_53 -> V_55 . V_109 . V_118 ,
V_119 [ V_88 & V_120 ] , V_53 -> V_71 . V_57 ) ;
}
F_6 ( L_37 ) ;
F_25 ( L_38 , & V_53 -> V_71 , 0 ) ;
F_26 ( V_126 , V_89 ) ;
return;
}
} else {
if ( ! ( V_88 & ( V_112 | V_113 ) ) && ! ( V_88 & V_116 ) )
F_27 ( L_39 ) ;
}
if ( V_88 & V_116 ) {
V_66 = V_53 -> V_55 . V_109 . V_118 ;
if ( V_108 & V_121 )
V_65 = 0x01 ;
else if ( V_108 & V_122 )
V_65 = 0x00 ;
else {
#ifdef F_5
F_6 ( L_40 , V_108 ) ;
F_6 ( L_41 ,
! ( V_88 & V_117 ) ? L_36 : L_35 , V_66 ,
V_53 -> V_71 . V_57 ) ;
#endif
F_25 ( L_38 , & V_53 -> V_71 , V_108 ) ;
F_26 ( V_107 , V_89 ) ;
return;
}
if ( ! ( V_88 & V_117 ) || V_88 & V_127 )
V_65 |= 0x02 ;
F_8 ( & V_53 -> V_71 , V_66 , V_65 ) ;
return;
}
if ( V_53 -> V_71 . V_114 == 0xA )
V_66 = V_53 -> V_71 . V_57 + 4 ;
else
V_66 = V_53 -> V_55 . V_109 . V_115 ;
if ( V_88 & V_112 )
V_66 -= 2 ;
if ( V_108 & V_122 ) {
if ( ! F_24 ( V_53 -> V_55 . V_109 . V_118 , 1 , 0 ) )
F_8 ( & V_53 -> V_71 , V_66 , 0 ) ;
} else {
#ifdef F_5
F_6 ( L_42 ) ;
#endif
F_26 ( V_128 , V_89 ) ;
}
}
static inline void F_22 ( struct V_52 * V_53 )
{
volatile unsigned short V_129 ;
unsigned short V_76 ;
unsigned long V_66 , V_65 ;
unsigned short V_88 = V_53 -> V_55 . V_109 . V_88 ;
#ifdef F_5
unsigned long V_130 ;
F_6 ( L_43 , V_89 -> V_131 ) ;
F_6 ( L_44 , V_88 ) ;
if ( V_88 & ( V_112 | V_113 ) )
F_6 ( L_33 ,
V_88 & V_112 ?
V_53 -> V_71 . V_114 == 0xa ? V_53 -> V_71 . V_57 + 2 : V_53 -> V_55 . V_109 . V_115 - 2
:
V_53 -> V_71 . V_114 == 0xa ? V_53 -> V_71 . V_57 + 4 : V_53 -> V_55 . V_109 . V_115 ) ;
if ( V_88 & V_116 )
F_6 ( L_34 ,
V_88 & V_117 ? L_35 : L_36 ,
V_53 -> V_55 . V_109 . V_118 ,
V_119 [ V_88 & V_120 ] , V_53 -> V_71 . V_57 ) ;
#endif
if ( V_88 & V_116 ) {
V_66 = V_53 -> V_55 . V_109 . V_118 ;
#ifdef F_5
asm volatile ("ptestr %3,%2@,#7,%0\n\t"
"pmove %%psr,%1@"
: "=a&" (desc)
: "a" (&temp), "a" (addr), "d" (ssw));
#else
asm volatile ("ptestr %2,%1@,#7\n\t"
"pmove %%psr,%0@"
: : "a" (&temp), "a" (addr), "d" (ssw));
#endif
V_76 = V_129 ;
#ifdef F_5
F_6 ( L_45 ,
V_76 , V_66 , V_89 ) ;
F_6 ( L_46 ,
F_28 ( V_130 ) , * ( unsigned long * ) F_28 ( V_130 ) ) ;
#endif
V_65 = ( V_76 & V_132 ) ? 0 : 1 ;
if ( ! ( V_88 & V_117 ) || ( V_88 & V_127 ) )
V_65 |= 2 ;
if ( V_76 & ( V_132 | V_133 ) ) {
if ( V_88 & 4 ) {
F_6 ( L_34 ,
V_88 & V_117 ? L_35 : L_36 ,
V_53 -> V_55 . V_109 . V_118 ,
V_119 [ V_88 & V_120 ] , V_53 -> V_71 . V_57 ) ;
goto V_9;
}
if ( F_8 ( & V_53 -> V_71 , V_66 , V_65 ) < 0 )
return;
} else if ( ! ( V_76 & V_132 ) ) {
if ( ! ( V_88 & V_127 ) && F_9 ( & V_53 -> V_71 ) > 0 )
F_6 ( L_47 , V_88 , V_76 ) ;
} else if ( V_76 & ( V_134 | V_135 | V_136 ) ) {
F_6 ( L_41 ,
! ( V_88 & V_117 ) ? L_36 : L_35 , V_66 ,
V_53 -> V_71 . V_57 ) ;
F_25 ( L_38 , & V_53 -> V_71 , V_76 ) ;
F_26 ( V_128 , V_89 ) ;
return;
} else {
#if 0
static volatile long tlong;
#endif
F_6 ( L_48 ,
! ( V_88 & V_117 ) ? L_36 : L_35 , V_66 ,
V_53 -> V_71 . V_57 , V_88 ) ;
asm volatile ("ptestr #1,%1@,#0\n\t"
"pmove %%psr,%0@"
:
: "a" (&temp), "a" (addr));
V_76 = V_129 ;
F_6 ( L_49 , V_76 ) ;
#if 0
asm volatile ("pmove %%tt0,%0@"
:
: "a" (&tlong));
printk("tt0 is %#lx, ", tlong);
asm volatile ("pmove %%tt1,%0@"
:
: "a" (&tlong));
printk("tt1 is %#lx\n", tlong);
#endif
#ifdef F_5
F_6 ( L_50 ) ;
#endif
F_25 ( L_38 , & V_53 -> V_71 , V_76 ) ;
F_26 ( V_128 , V_89 ) ;
return;
}
if ( ! ( V_88 & V_117 ) || ( V_88 & V_127 ) )
asm volatile ("ploadw %1,%0@" :
: "a" (addr), "d" (ssw));
else
asm volatile ("ploadr %1,%0@" :
: "a" (addr), "d" (ssw));
}
if ( ! ( V_88 & ( V_112 | V_113 ) ) )
return;
if ( V_53 -> V_71 . V_123 & V_124 ) {
F_6 ( L_33 ,
V_53 -> V_71 . V_57 ) ;
V_9:
F_6 ( L_37 ) ;
F_25 ( L_38 , & V_53 -> V_71 , 0 ) ;
F_26 ( V_126 , V_89 ) ;
return;
}
if ( V_53 -> V_71 . V_114 == 10 )
V_66 = V_53 -> V_71 . V_57 + 4 ;
else
V_66 = V_53 -> V_55 . V_109 . V_115 ;
if ( V_88 & V_112 )
V_66 -= 2 ;
if ( ( V_88 & V_116 ) && ( ( V_66 ^ V_53 -> V_55 . V_109 . V_118 ) & V_69 ) == 0 )
goto V_137;
#ifdef F_5
asm volatile ("ptestr #1,%2@,#7,%0\n\t"
"pmove %%psr,%1@"
: "=a&" (desc)
: "a" (&temp), "a" (addr));
#else
asm volatile ("ptestr #1,%1@,#7\n\t"
"pmove %%psr,%0@"
: : "a" (&temp), "a" (addr));
#endif
V_76 = V_129 ;
#ifdef F_5
F_6 ( L_45 ,
V_76 , V_66 , V_89 ) ;
F_6 ( L_46 ,
F_28 ( V_130 ) , * ( unsigned long * ) F_28 ( V_130 ) ) ;
#endif
if ( V_76 & V_132 )
F_8 ( & V_53 -> V_71 , V_66 , 0 ) ;
else if ( V_76 & ( V_134 | V_135 | V_136 ) ) {
F_6 ( L_51 ,
V_66 , V_53 -> V_71 . V_57 ) ;
#ifdef F_5
F_6 ( L_52 ) ;
#endif
F_25 ( L_38 , & V_53 -> V_71 , V_76 ) ;
F_26 ( V_128 , V_89 ) ;
return;
}
V_137:
asm volatile ("ploadr #2,%0@" :
: "a" (addr));
}
T_3 void F_29 ( struct V_52 * V_53 )
{
if ( F_21 ( & V_53 -> V_71 ) )
V_89 -> V_90 . V_138 = ( unsigned long ) V_53 ;
#ifdef F_5
F_6 ( L_53 , V_53 -> V_71 . V_114 ) ;
#endif
switch ( V_53 -> V_71 . V_114 ) {
#if F_30 ( V_139 )
case 4 :
F_4 ( V_53 ) ;
break;
#endif
#if F_30 ( V_140 )
case 0x7 :
F_20 ( V_53 ) ;
break;
#endif
#if F_30 ( V_141 )
case 0xa :
case 0xb :
F_22 ( V_53 ) ;
break;
#endif
default:
F_25 ( L_54 , & V_53 -> V_71 , 0 ) ;
#ifdef F_5
F_6 ( L_55 ) ;
#endif
F_26 ( V_128 , V_89 ) ;
}
}
void F_31 ( unsigned long * V_142 )
{
unsigned long * V_143 ;
unsigned long V_66 ;
int V_14 ;
F_6 ( L_56 ) ;
V_66 = ( unsigned long ) V_142 + V_144 - 1 ;
V_143 = ( unsigned long * ) ( V_66 & - V_144 ) ;
V_14 = 0 ;
while ( V_142 + 1 <= V_143 ) {
V_66 = * V_142 ++ ;
if ( F_32 ( V_66 ) ) {
#ifndef F_33
if ( V_14 % 5 == 0 )
F_6 ( L_57 ) ;
#endif
F_6 ( L_58 , V_66 , ( void * ) V_66 ) ;
V_14 ++ ;
}
}
F_6 ( L_59 ) ;
}
void F_34 ( struct V_145 * V_146 )
{
struct V_52 * V_53 = (struct V_52 * ) V_146 ;
T_4 V_77 = F_12 () ;
T_5 V_147 , * V_148 ;
unsigned long V_66 ;
int V_14 ;
F_35 () ;
F_6 ( L_60 , V_146 -> V_57 , ( void * ) V_146 -> V_57 ) ;
F_6 ( L_61 , V_146 -> V_123 , V_146 , V_146 -> V_149 ) ;
F_6 ( L_62 ,
V_146 -> V_150 , V_146 -> V_151 , V_146 -> V_152 , V_146 -> V_153 ) ;
F_6 ( L_63 ,
V_146 -> V_154 , V_146 -> V_155 , V_146 -> V_156 , V_146 -> V_157 ) ;
F_6 ( L_64 ,
V_89 -> V_158 , F_36 ( V_89 ) , V_89 ) ;
V_66 = ( unsigned long ) & V_53 -> V_55 ;
F_6 ( L_65 , V_146 -> V_114 ) ;
switch ( V_146 -> V_114 ) {
case 0x2 :
F_6 ( L_66 , V_53 -> V_55 . V_159 . V_160 ) ;
V_66 += sizeof( V_53 -> V_55 . V_159 ) ;
break;
case 0x3 :
F_6 ( L_67 , V_53 -> V_55 . V_161 . V_58 ) ;
V_66 += sizeof( V_53 -> V_55 . V_161 ) ;
break;
case 0x4 :
F_6 ( ( V_3 ? L_68
: L_69 ) ,
V_53 -> V_55 . V_56 . V_58 , V_53 -> V_55 . V_56 . V_57 ) ;
V_66 += sizeof( V_53 -> V_55 . V_56 ) ;
break;
case 0x7 :
F_6 ( L_70 ,
V_53 -> V_55 . V_86 . V_58 , V_53 -> V_55 . V_86 . V_88 , V_53 -> V_55 . V_86 . V_87 ) ;
F_6 ( L_71 ,
V_53 -> V_55 . V_86 . V_100 , V_53 -> V_55 . V_86 . V_162 , V_53 -> V_55 . V_86 . V_163 ) ;
F_6 ( L_72 ,
V_53 -> V_55 . V_86 . V_92 , V_53 -> V_55 . V_86 . V_95 , V_53 -> V_55 . V_86 . V_96 ) ;
F_6 ( L_73 ,
V_53 -> V_55 . V_86 . V_97 , V_53 -> V_55 . V_86 . V_98 , V_53 -> V_55 . V_86 . V_99 ) ;
F_6 ( L_74 ,
V_53 -> V_55 . V_86 . V_163 , V_53 -> V_55 . V_86 . V_164 , V_53 -> V_55 . V_86 . V_165 ,
V_53 -> V_55 . V_86 . V_166 ) ;
V_66 += sizeof( V_53 -> V_55 . V_86 ) ;
break;
case 0x9 :
F_6 ( L_66 , V_53 -> V_55 . V_167 . V_160 ) ;
V_66 += sizeof( V_53 -> V_55 . V_167 ) ;
break;
case 0xa :
F_6 ( L_75 ,
V_53 -> V_55 . V_168 . V_88 , V_53 -> V_55 . V_168 . V_169 , V_53 -> V_55 . V_168 . V_170 ,
V_53 -> V_55 . V_168 . V_118 , V_53 -> V_55 . V_168 . V_171 ) ;
V_66 += sizeof( V_53 -> V_55 . V_168 ) ;
break;
case 0xb :
F_6 ( L_75 ,
V_53 -> V_55 . V_109 . V_88 , V_53 -> V_55 . V_109 . V_169 , V_53 -> V_55 . V_109 . V_170 ,
V_53 -> V_55 . V_109 . V_118 , V_53 -> V_55 . V_109 . V_171 ) ;
F_6 ( L_76 ,
V_53 -> V_55 . V_109 . V_115 , V_53 -> V_55 . V_109 . V_172 , V_53 -> V_55 . V_109 . V_173 ) ;
V_66 += sizeof( V_53 -> V_55 . V_109 ) ;
break;
default:
F_6 ( L_59 ) ;
}
F_37 ( NULL , ( unsigned long * ) V_66 ) ;
F_6 ( L_77 ) ;
F_13 ( V_174 ) ;
V_148 = ( T_5 * ) V_146 -> V_57 ;
for ( V_14 = - 8 ; V_14 < 16 ; V_14 ++ ) {
if ( F_38 ( V_147 , V_148 + V_14 ) && V_14 >= 0 ) {
F_6 ( L_78 ) ;
break;
}
F_6 ( V_14 ? L_79 : L_80 , V_147 ) ;
}
F_13 ( V_77 ) ;
F_6 ( L_59 ) ;
}
void F_37 ( struct V_175 * V_176 , unsigned long * V_142 )
{
unsigned long * V_177 ;
unsigned long * V_143 ;
int V_14 ;
if ( ! V_142 ) {
if ( V_176 )
V_142 = ( unsigned long * ) V_176 -> V_90 . V_138 ;
else
V_142 = ( unsigned long * ) & V_142 ;
}
V_143 = ( unsigned long * ) ( ( ( unsigned long ) V_142 + V_144 - 1 ) & - V_144 ) ;
F_6 ( L_81 , ( unsigned long ) V_142 ) ;
V_177 = V_142 ;
for ( V_14 = 0 ; V_14 < V_178 ; V_14 ++ ) {
if ( V_177 + 1 > V_143 )
break;
if ( V_14 % 8 == 0 )
F_6 ( L_57 ) ;
F_6 ( L_82 , * V_177 ++ ) ;
}
F_6 ( L_59 ) ;
F_31 ( V_142 ) ;
}
void F_39 ( void )
{
unsigned long V_142 ;
F_31 ( & V_142 ) ;
}
void F_40 ( struct V_52 * V_53 )
{
F_41 () ;
if ( V_53 -> V_71 . V_179 < 4 * F_42 ( V_180 ) )
F_6 ( L_83 ,
V_180 [ ( V_53 -> V_71 . V_179 ) >> 2 ] ,
V_53 -> V_71 . V_114 ) ;
else
F_6 ( L_84 ,
( V_53 -> V_71 . V_179 ) >> 2 ,
V_53 -> V_71 . V_114 ) ;
if ( V_53 -> V_71 . V_179 >> 2 == V_181 && V_182 ) {
unsigned short V_88 = V_53 -> V_55 . V_109 . V_88 ;
F_6 ( L_44 , V_88 ) ;
if ( V_88 & V_183 )
F_6 ( L_85 ,
( V_53 -> V_71 . V_114 ) == 0xA ?
V_53 -> V_71 . V_57 + 2 : V_53 -> V_55 . V_109 . V_115 - 2 ) ;
if ( V_88 & V_184 )
F_6 ( L_86 ,
( V_53 -> V_71 . V_114 ) == 0xA ?
V_53 -> V_71 . V_57 + 4 : V_53 -> V_55 . V_109 . V_115 ) ;
if ( V_88 & V_116 )
F_6 ( L_34 ,
V_88 & V_117 ? L_35 : L_36 ,
V_53 -> V_55 . V_109 . V_118 , V_119 [ V_88 & V_120 ] ,
V_53 -> V_71 . V_57 ) ;
}
F_6 ( L_87 , F_36 ( V_89 ) ) ;
F_25 ( L_88 , & V_53 -> V_71 , 0 ) ;
}
T_3 void F_10 ( struct V_52 * V_53 )
{
int V_185 ;
T_6 V_186 ;
if ( V_53 -> V_71 . V_123 & V_124 ) {
if ( V_53 -> V_71 . V_179 == V_187 << 2 ) {
} else if ( ! F_43 ( & V_53 -> V_71 ) )
F_40 ( V_53 ) ;
return;
}
switch ( ( V_53 -> V_71 . V_179 ) >> 2 ) {
case V_181 :
V_186 . V_188 = V_189 ;
V_185 = V_107 ;
break;
case V_10 :
case V_190 :
case V_20 :
V_186 . V_188 = V_191 ;
V_185 = V_192 ;
break;
case V_193 :
V_186 . V_188 = V_194 ;
V_185 = V_192 ;
break;
case V_195 :
V_186 . V_188 = V_196 ;
V_185 = V_192 ;
break;
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
V_186 . V_188 = V_211 ;
V_185 = V_192 ;
break;
case V_38 :
case V_37 :
case V_36 :
V_186 . V_188 = V_212 ;
V_185 = V_213 ;
break;
case V_33 :
V_186 . V_188 = V_214 ;
V_185 = V_213 ;
break;
case V_32 :
V_186 . V_188 = V_215 ;
V_185 = V_213 ;
break;
case V_35 :
V_186 . V_188 = V_216 ;
V_185 = V_213 ;
break;
case V_34 :
V_186 . V_188 = V_217 ;
V_185 = V_213 ;
break;
case V_218 :
V_186 . V_188 = V_219 ;
V_185 = V_213 ;
break;
case V_220 :
case V_221 :
V_186 . V_188 = V_222 ;
V_185 = V_213 ;
break;
case V_187 :
V_186 . V_188 = V_223 ;
V_185 = V_224 ;
break;
case V_225 :
V_186 . V_188 = V_226 ;
V_185 = V_224 ;
break;
default:
V_186 . V_188 = V_191 ;
V_185 = V_192 ;
break;
}
V_186 . V_227 = V_185 ;
V_186 . V_228 = 0 ;
switch ( V_53 -> V_71 . V_114 ) {
default:
V_186 . V_229 = ( void * ) V_53 -> V_71 . V_57 ;
break;
case 2 :
V_186 . V_229 = ( void * ) V_53 -> V_55 . V_159 . V_160 ;
break;
case 7 :
V_186 . V_229 = ( void * ) V_53 -> V_55 . V_86 . V_58 ;
break;
case 9 :
V_186 . V_229 = ( void * ) V_53 -> V_55 . V_167 . V_160 ;
break;
case 10 :
V_186 . V_229 = ( void * ) V_53 -> V_55 . V_168 . V_118 ;
break;
case 11 :
V_186 . V_229 = ( void * ) V_53 -> V_55 . V_109 . V_118 ;
break;
}
F_44 ( V_185 , & V_186 , V_89 ) ;
}
void F_25 ( char * V_230 , struct V_145 * V_53 , int V_231 )
{
if ( ! ( V_53 -> V_123 & V_124 ) )
return;
F_41 () ;
F_6 ( L_89 , V_230 , V_231 ) ;
F_34 ( V_53 ) ;
F_45 ( V_232 ) ;
F_46 ( V_128 ) ;
}
T_3 void F_47 ( void )
{
F_46 ( V_128 ) ;
}
T_3 void F_48 ( int signal , int V_233 , void * V_66 )
{
T_6 V_186 ;
V_186 . V_227 = signal ;
V_186 . V_228 = 0 ;
V_186 . V_188 = V_233 ;
V_186 . V_229 = V_66 ;
F_44 ( signal , & V_186 , V_89 ) ;
}

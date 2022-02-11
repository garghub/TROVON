int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_1 * V_5 ;
V_4 = F_2 ( V_2 -> V_6 ) ;
if ( ! V_4 )
return 0 ;
V_2 -> V_7 = V_8 [ V_2 -> V_9 ] ;
V_5 = (struct V_1 * ) ( ( long ) V_2 + V_2 -> V_7 ) ;
V_5 -> V_10 = V_2 -> V_10 ;
V_5 -> V_9 = 0 ;
V_5 -> V_6 = V_4 -> V_4 ;
V_5 -> V_11 = V_2 -> V_11 ;
return 1 ;
}
T_1 int
F_3 ( int V_12 , int V_13 , T_2 V_14 )
{
V_14 &= V_15 ;
F_4 ( & V_16 -> V_17 -> V_18 ) ;
V_16 -> V_19 = V_16 -> V_20 ;
F_5 ( & V_16 -> V_20 , V_14 ) ;
F_6 () ;
F_7 ( & V_16 -> V_17 -> V_18 ) ;
V_16 -> V_21 = V_22 ;
F_8 () ;
F_9 () ;
return - V_23 ;
}
T_1 int
F_10 ( int V_24 , const struct V_25 T_3 * V_26 ,
struct V_25 T_3 * V_27 )
{
struct V_28 V_29 , V_30 ;
int V_31 ;
if ( V_26 ) {
T_2 V_14 ;
if ( ! F_11 ( V_32 , V_26 , sizeof( * V_26 ) ) ||
F_12 ( V_29 . V_33 . V_34 , & V_26 -> V_34 ) ||
F_12 ( V_29 . V_33 . V_35 , & V_26 -> V_35 ) ||
F_12 ( V_29 . V_33 . V_36 , & V_26 -> V_36 ) ||
F_12 ( V_14 , & V_26 -> V_37 ) )
return - V_38 ;
F_5 ( & V_29 . V_33 . V_37 , V_14 ) ;
}
V_31 = F_13 ( V_24 , V_26 ? & V_29 : NULL , V_27 ? & V_30 : NULL ) ;
if ( ! V_31 && V_27 ) {
if ( ! F_11 ( V_39 , V_27 , sizeof( * V_27 ) ) ||
F_14 ( V_30 . V_33 . V_34 , & V_27 -> V_34 ) ||
F_14 ( V_30 . V_33 . V_35 , & V_27 -> V_35 ) ||
F_14 ( V_30 . V_33 . V_36 , & V_27 -> V_36 ) ||
F_14 ( V_30 . V_33 . V_37 . V_24 [ 0 ] , & V_27 -> V_37 ) )
return - V_38 ;
}
return V_31 ;
}
T_1 int
F_15 ( const T_4 T_3 * V_40 , T_4 T_3 * V_41 )
{
return F_16 ( V_40 , V_41 , F_17 () ) ;
}
static inline int F_18 ( struct V_42 * V_43 )
{
int V_44 = 1 ;
if ( V_45 ) {
memcpy ( V_16 -> V_46 . V_47 , V_43 -> V_48 , 12 ) ;
memcpy ( V_16 -> V_46 . V_49 , V_43 -> V_50 , 24 ) ;
return 0 ;
}
if ( V_51 ? V_43 -> V_52 [ 2 ] : V_43 -> V_52 [ 0 ] ) {
if ( ! V_51 && ( V_43 -> V_52 [ 0 ] != V_53 ) )
goto V_54;
if ( V_55 ) {
if ( V_56 & V_57 &&
! ( V_43 -> V_52 [ 1 ] == 0x18 || V_43 -> V_52 [ 1 ] == 0xb4 ) )
goto V_54;
if ( V_56 & V_58 &&
! ( V_43 -> V_52 [ 1 ] == 0x38 || V_43 -> V_52 [ 1 ] == 0xd4 ) )
goto V_54;
} else if ( V_59 ) {
if ( ! ( V_43 -> V_52 [ 1 ] == 0x00 ||
V_43 -> V_52 [ 1 ] == 0x28 ||
V_43 -> V_52 [ 1 ] == 0x60 ) )
goto V_54;
} else if ( V_51 ) {
if ( ! ( V_43 -> V_52 [ 3 ] == 0x00 ||
V_43 -> V_52 [ 3 ] == 0x60 ||
V_43 -> V_52 [ 3 ] == 0xe0 ) )
goto V_54;
} else
goto V_54;
__asm__ volatile (".chip 68k/68881\n\t"
"fmovemx %0,%%fp0-%%fp1\n\t"
"fmoveml %1,%%fpcr/%%fpsr/%%fpiar\n\t"
".chip 68k"
:
: "m" (*sc->sc_fpregs), "m" (*sc->sc_fpcntl));
}
__asm__ volatile (".chip 68k/68881\n\t"
"frestore %0\n\t"
".chip 68k" : : "m" (*sc->sc_fpstate));
V_44 = 0 ;
V_54:
return V_44 ;
}
static inline int F_19 ( struct V_60 T_3 * V_61 )
{
unsigned char V_62 [ V_63 ] ;
int V_64 = V_51 ? 8 : 0 ;
T_5 V_65 ;
int V_44 = 1 ;
if ( V_45 ) {
if ( F_20 ( V_16 -> V_46 . V_47 ,
V_61 -> V_66 . V_65 . V_67 , 12 ) )
goto V_54;
if ( F_20 ( V_16 -> V_46 . V_49 ,
V_61 -> V_66 . V_65 . V_68 , 96 ) )
goto V_54;
return 0 ;
}
if ( F_12 ( * ( long * ) V_62 , ( long T_3 * ) & V_61 -> V_69 ) )
goto V_54;
if ( V_51 ? V_62 [ 2 ] : V_62 [ 0 ] ) {
if ( ! V_51 )
V_64 = V_62 [ 1 ] ;
if ( ! V_51 && ( V_62 [ 0 ] != V_53 ) )
goto V_54;
if ( V_55 ) {
if ( V_56 & V_57 &&
! ( V_64 == 0x18 || V_64 == 0xb4 ) )
goto V_54;
if ( V_56 & V_58 &&
! ( V_64 == 0x38 || V_64 == 0xd4 ) )
goto V_54;
} else if ( V_59 ) {
if ( ! ( V_64 == 0x00 ||
V_64 == 0x28 ||
V_64 == 0x60 ) )
goto V_54;
} else if ( V_51 ) {
if ( ! ( V_62 [ 3 ] == 0x00 ||
V_62 [ 3 ] == 0x60 ||
V_62 [ 3 ] == 0xe0 ) )
goto V_54;
} else
goto V_54;
if ( F_20 ( & V_65 , & V_61 -> V_66 . V_65 ,
sizeof( V_65 ) ) )
goto V_54;
__asm__ volatile (".chip 68k/68881\n\t"
"fmovemx %0,%%fp0-%%fp7\n\t"
"fmoveml %1,%%fpcr/%%fpsr/%%fpiar\n\t"
".chip 68k"
:
: "m" (*fpregs.f_fpregs),
"m" (*fpregs.f_fpcntl));
}
if ( V_64 &&
F_20 ( V_62 + 4 , ( long T_3 * ) & V_61 -> V_69 + 1 ,
V_64 ) )
goto V_54;
__asm__ volatile (".chip 68k/68881\n\t"
"frestore %0\n\t"
".chip 68k" : : "m" (*fpstate));
V_44 = 0 ;
V_54:
return V_44 ;
}
static int F_21 ( struct V_1 * V_2 , int V_70 ,
void T_3 * V_49 )
{
int V_71 = V_8 [ V_70 >> 12 ] ;
if ( V_71 < 0 ) {
#ifdef F_22
F_23 ( L_1 ) ;
#endif
return 1 ;
}
if ( ! V_71 ) {
V_2 -> V_9 = V_70 >> 12 ;
V_2 -> V_10 = V_70 & 0xfff ;
} else {
struct V_72 * V_73 = (struct V_72 * ) V_2 - 1 ;
unsigned long V_74 [ V_71 / 2 ] ;
if ( F_24 ( V_74 + V_71 / 4 , V_49 , V_71 ) )
return 1 ;
V_2 -> V_9 = V_70 >> 12 ;
V_2 -> V_10 = V_70 & 0xfff ;
#define F_25 (sizeof(struct pt_regs)+sizeof(struct switch_stack))
__asm__ __volatile__
(" movel %0,%/a0\n\t"
" subl %1,%/a0\n\t"
" movel %/a0,%/sp\n\t"
"1: movel %0@+,%/a0@+\n\t"
" dbra %2,1b\n\t"
" lea %/sp@(%c3),%/a0\n\t"
" lsrl #2,%1\n\t"
" subql #1,%1\n\t"
"2: movel %4@+,%/a0@+\n\t"
" dbra %1,2b\n\t"
" bral ret_from_signal\n"
:
: "a" (sw), "d" (fsize), "d" (frame_offset/4-1),
"n" (frame_offset), "a" (buf + fsize/4)
: "a0");
#undef F_25
}
return 0 ;
}
static inline int
F_26 ( struct V_1 * V_2 , struct V_42 T_3 * V_75 , void T_3 * V_49 )
{
int V_70 ;
struct V_42 V_76 ;
int V_44 ;
F_27 () -> V_77 . V_78 = V_79 ;
if ( F_24 ( & V_76 , V_75 , sizeof( V_76 ) ) )
goto V_80;
V_2 -> V_81 = V_76 . V_82 ;
V_2 -> V_83 = V_76 . V_84 ;
V_2 -> V_85 = V_76 . V_86 ;
V_2 -> V_87 = V_76 . V_88 ;
V_2 -> V_11 = ( V_2 -> V_11 & 0xff00 ) | ( V_76 . V_89 & 0xff ) ;
V_2 -> V_6 = V_76 . V_90 ;
V_2 -> V_91 = - 1 ;
F_28 ( V_76 . V_92 ) ;
V_70 = V_76 . V_93 ;
V_44 = F_18 ( & V_76 ) ;
if ( V_44 || F_21 ( V_2 , V_70 , V_49 ) )
goto V_80;
return 0 ;
V_80:
return 1 ;
}
static inline int
F_29 ( struct V_1 * V_2 , struct V_72 * V_73 ,
struct V_60 T_3 * V_61 )
{
int V_94 ;
T_6 T_3 * V_95 = V_61 -> V_66 . V_95 ;
unsigned long V_96 ;
int V_44 ;
F_27 () -> V_77 . V_78 = V_79 ;
V_44 = F_12 ( V_94 , & V_61 -> V_66 . V_97 ) ;
if ( V_94 != V_98 )
goto V_80;
V_44 |= F_12 ( V_2 -> V_81 , & V_95 [ 0 ] ) ;
V_44 |= F_12 ( V_2 -> V_83 , & V_95 [ 1 ] ) ;
V_44 |= F_12 ( V_2 -> V_99 , & V_95 [ 2 ] ) ;
V_44 |= F_12 ( V_2 -> V_100 , & V_95 [ 3 ] ) ;
V_44 |= F_12 ( V_2 -> V_101 , & V_95 [ 4 ] ) ;
V_44 |= F_12 ( V_2 -> V_102 , & V_95 [ 5 ] ) ;
V_44 |= F_12 ( V_73 -> V_103 , & V_95 [ 6 ] ) ;
V_44 |= F_12 ( V_73 -> V_104 , & V_95 [ 7 ] ) ;
V_44 |= F_12 ( V_2 -> V_85 , & V_95 [ 8 ] ) ;
V_44 |= F_12 ( V_2 -> V_87 , & V_95 [ 9 ] ) ;
V_44 |= F_12 ( V_2 -> V_105 , & V_95 [ 10 ] ) ;
V_44 |= F_12 ( V_73 -> V_106 , & V_95 [ 11 ] ) ;
V_44 |= F_12 ( V_73 -> V_107 , & V_95 [ 12 ] ) ;
V_44 |= F_12 ( V_73 -> V_108 , & V_95 [ 13 ] ) ;
V_44 |= F_12 ( V_73 -> V_109 , & V_95 [ 14 ] ) ;
V_44 |= F_12 ( V_96 , & V_95 [ 15 ] ) ;
F_28 ( V_96 ) ;
V_44 |= F_12 ( V_2 -> V_6 , & V_95 [ 16 ] ) ;
V_44 |= F_12 ( V_94 , & V_95 [ 17 ] ) ;
V_2 -> V_11 = ( V_2 -> V_11 & 0xff00 ) | ( V_94 & 0xff ) ;
V_2 -> V_91 = - 1 ;
V_44 |= F_12 ( V_94 , & V_61 -> V_110 ) ;
V_44 |= F_19 ( V_61 ) ;
if ( V_44 || F_16 ( & V_61 -> V_111 , NULL , V_96 ) == - V_38 )
goto V_80;
if ( F_21 ( V_2 , V_94 , & V_61 -> V_112 ) )
goto V_80;
return 0 ;
V_80:
return 1 ;
}
T_1 int F_30 ( unsigned long V_113 )
{
struct V_72 * V_73 = (struct V_72 * ) & V_113 ;
struct V_1 * V_2 = (struct V_1 * ) ( V_73 + 1 ) ;
unsigned long V_96 = F_17 () ;
struct V_114 T_3 * V_115 = (struct V_114 T_3 * ) ( V_96 - 4 ) ;
T_7 V_116 ;
if ( ! F_11 ( V_32 , V_115 , sizeof( * V_115 ) ) )
goto V_80;
if ( F_12 ( V_116 . V_24 [ 0 ] , & V_115 -> V_43 . V_117 ) ||
( V_118 > 1 &&
F_20 ( & V_116 . V_24 [ 1 ] , & V_115 -> V_119 ,
sizeof( V_115 -> V_119 ) ) ) )
goto V_80;
F_31 ( & V_116 , ~ V_15 ) ;
V_16 -> V_20 = V_116 ;
F_6 () ;
if ( F_26 ( V_2 , & V_115 -> V_43 , V_115 + 1 ) )
goto V_80;
return V_2 -> V_81 ;
V_80:
F_32 ( V_120 , V_16 ) ;
return 0 ;
}
T_1 int F_33 ( unsigned long V_113 )
{
struct V_72 * V_73 = (struct V_72 * ) & V_113 ;
struct V_1 * V_2 = (struct V_1 * ) ( V_73 + 1 ) ;
unsigned long V_96 = F_17 () ;
struct V_121 T_3 * V_115 = (struct V_121 T_3 * ) ( V_96 - 4 ) ;
T_7 V_116 ;
if ( ! F_11 ( V_32 , V_115 , sizeof( * V_115 ) ) )
goto V_80;
if ( F_20 ( & V_116 , & V_115 -> V_61 . V_122 , sizeof( V_116 ) ) )
goto V_80;
F_31 ( & V_116 , ~ V_15 ) ;
V_16 -> V_20 = V_116 ;
F_6 () ;
if ( F_29 ( V_2 , V_73 , & V_115 -> V_61 ) )
goto V_80;
return V_2 -> V_81 ;
V_80:
F_32 ( V_120 , V_16 ) ;
return 0 ;
}
static inline void F_34 ( struct V_42 * V_43 , struct V_1 * V_2 )
{
if ( V_45 ) {
memcpy ( V_43 -> V_48 , V_16 -> V_46 . V_47 , 12 ) ;
memcpy ( V_43 -> V_50 , V_16 -> V_46 . V_49 , 24 ) ;
return;
}
__asm__ volatile (".chip 68k/68881\n\t"
"fsave %0\n\t"
".chip 68k"
: : "m" (*sc->sc_fpstate) : "memory");
if ( V_51 ? V_43 -> V_52 [ 2 ] : V_43 -> V_52 [ 0 ] ) {
V_53 = V_43 -> V_52 [ 0 ] ;
if ( V_55 &&
V_2 -> V_10 >= ( V_123 * 4 ) &&
V_2 -> V_10 <= ( V_124 * 4 ) ) {
if ( * ( unsigned short * ) V_43 -> V_52 == 0x1f38 )
V_43 -> V_52 [ 0x38 ] |= 1 << 3 ;
}
__asm__ volatile (".chip 68k/68881\n\t"
"fmovemx %%fp0-%%fp1,%0\n\t"
"fmoveml %%fpcr/%%fpsr/%%fpiar,%1\n\t"
".chip 68k"
: "=m" (*sc->sc_fpregs),
"=m" (*sc->sc_fpcntl)
:
: "memory");
}
}
static inline int F_35 ( struct V_60 T_3 * V_61 , struct V_1 * V_2 )
{
unsigned char V_62 [ V_63 ] ;
int V_64 = V_51 ? 8 : 0 ;
int V_44 = 0 ;
if ( V_45 ) {
V_44 |= F_36 ( V_61 -> V_66 . V_65 . V_67 ,
V_16 -> V_46 . V_47 , 12 ) ;
V_44 |= F_36 ( V_61 -> V_66 . V_65 . V_68 ,
V_16 -> V_46 . V_49 , 96 ) ;
return V_44 ;
}
__asm__ volatile (".chip 68k/68881\n\t"
"fsave %0\n\t"
".chip 68k"
: : "m" (*fpstate) : "memory");
V_44 |= F_14 ( * ( long * ) V_62 , ( long T_3 * ) & V_61 -> V_69 ) ;
if ( V_51 ? V_62 [ 2 ] : V_62 [ 0 ] ) {
T_5 V_65 ;
if ( ! V_51 )
V_64 = V_62 [ 1 ] ;
V_53 = V_62 [ 0 ] ;
if ( V_55 &&
V_2 -> V_10 >= ( V_123 * 4 ) &&
V_2 -> V_10 <= ( V_124 * 4 ) ) {
if ( * ( unsigned short * ) V_62 == 0x1f38 )
V_62 [ 0x38 ] |= 1 << 3 ;
}
__asm__ volatile (".chip 68k/68881\n\t"
"fmovemx %%fp0-%%fp7,%0\n\t"
"fmoveml %%fpcr/%%fpsr/%%fpiar,%1\n\t"
".chip 68k"
: "=m" (*fpregs.f_fpregs),
"=m" (*fpregs.f_fpcntl)
:
: "memory");
V_44 |= F_36 ( & V_61 -> V_66 . V_65 , & V_65 ,
sizeof( V_65 ) ) ;
}
if ( V_64 )
V_44 |= F_36 ( ( long T_3 * ) & V_61 -> V_69 + 1 , V_62 + 4 ,
V_64 ) ;
return V_44 ;
}
static void F_37 ( struct V_42 * V_43 , struct V_1 * V_2 ,
unsigned long V_14 )
{
V_43 -> V_117 = V_14 ;
V_43 -> V_92 = F_17 () ;
V_43 -> V_82 = V_2 -> V_81 ;
V_43 -> V_84 = V_2 -> V_83 ;
V_43 -> V_86 = V_2 -> V_85 ;
V_43 -> V_88 = V_2 -> V_87 ;
V_43 -> V_89 = V_2 -> V_11 ;
V_43 -> V_90 = V_2 -> V_6 ;
V_43 -> V_93 = V_2 -> V_9 << 12 | V_2 -> V_10 ;
F_34 ( V_43 , V_2 ) ;
}
static inline int F_38 ( struct V_60 T_3 * V_61 , struct V_1 * V_2 )
{
struct V_72 * V_73 = (struct V_72 * ) V_2 - 1 ;
T_6 T_3 * V_95 = V_61 -> V_66 . V_95 ;
int V_44 = 0 ;
V_44 |= F_14 ( V_98 , & V_61 -> V_66 . V_97 ) ;
V_44 |= F_14 ( V_2 -> V_81 , & V_95 [ 0 ] ) ;
V_44 |= F_14 ( V_2 -> V_83 , & V_95 [ 1 ] ) ;
V_44 |= F_14 ( V_2 -> V_99 , & V_95 [ 2 ] ) ;
V_44 |= F_14 ( V_2 -> V_100 , & V_95 [ 3 ] ) ;
V_44 |= F_14 ( V_2 -> V_101 , & V_95 [ 4 ] ) ;
V_44 |= F_14 ( V_2 -> V_102 , & V_95 [ 5 ] ) ;
V_44 |= F_14 ( V_73 -> V_103 , & V_95 [ 6 ] ) ;
V_44 |= F_14 ( V_73 -> V_104 , & V_95 [ 7 ] ) ;
V_44 |= F_14 ( V_2 -> V_85 , & V_95 [ 8 ] ) ;
V_44 |= F_14 ( V_2 -> V_87 , & V_95 [ 9 ] ) ;
V_44 |= F_14 ( V_2 -> V_105 , & V_95 [ 10 ] ) ;
V_44 |= F_14 ( V_73 -> V_106 , & V_95 [ 11 ] ) ;
V_44 |= F_14 ( V_73 -> V_107 , & V_95 [ 12 ] ) ;
V_44 |= F_14 ( V_73 -> V_108 , & V_95 [ 13 ] ) ;
V_44 |= F_14 ( V_73 -> V_109 , & V_95 [ 14 ] ) ;
V_44 |= F_14 ( F_17 () , & V_95 [ 15 ] ) ;
V_44 |= F_14 ( V_2 -> V_6 , & V_95 [ 16 ] ) ;
V_44 |= F_14 ( V_2 -> V_11 , & V_95 [ 17 ] ) ;
V_44 |= F_14 ( ( V_2 -> V_9 << 12 ) | V_2 -> V_10 , & V_61 -> V_110 ) ;
V_44 |= F_35 ( V_61 , V_2 ) ;
return V_44 ;
}
static inline void F_39 ( unsigned long V_125 )
{
if ( V_59 ) {
unsigned long V_94 ;
__asm__ __volatile__ (".chip 68040\n\t"
"nop\n\t"
"ptestr (%1)\n\t"
"movec %%mmusr,%0\n\t"
".chip 68k"
: "=r" (temp)
: "a" (vaddr));
V_94 &= V_126 ;
V_94 |= V_125 & ~ V_126 ;
__asm__ __volatile__ (".chip 68040\n\t"
"nop\n\t"
"cpushl %%bc,(%0)\n\t"
".chip 68k"
: : "a" (temp));
}
else if ( V_51 ) {
unsigned long V_94 ;
__asm__ __volatile__ (".chip 68060\n\t"
"plpar (%0)\n\t"
".chip 68k"
: "=a" (temp)
: "0" (vaddr));
__asm__ __volatile__ (".chip 68060\n\t"
"cpushl %%bc,(%0)\n\t"
".chip 68k"
: : "a" (temp));
}
else {
unsigned long V_94 ;
asm volatile ("movec %%cacr,%0" : "=r" (temp));
V_94 += 4 ;
asm volatile ("movec %0,%%caar\n\t"
"movec %1,%%cacr"
: : "r" (vaddr), "r" (temp));
asm volatile ("movec %0,%%caar\n\t"
"movec %1,%%cacr"
: : "r" (vaddr + 4), "r" (temp));
}
}
static inline void T_3 *
F_40 ( struct V_28 * V_127 , struct V_1 * V_2 , T_8 V_128 )
{
unsigned long V_96 ;
V_96 = F_17 () ;
if ( V_127 -> V_33 . V_36 & V_129 ) {
if ( ! F_41 ( V_96 ) )
V_96 = V_16 -> V_130 + V_16 -> V_131 ;
}
return ( void T_3 * ) ( ( V_96 - V_128 ) & - 8UL ) ;
}
static int F_42 ( int V_24 , struct V_28 * V_127 ,
T_7 * V_116 , struct V_1 * V_2 )
{
struct V_114 T_3 * V_115 ;
int V_71 = V_8 [ V_2 -> V_9 ] ;
struct V_42 V_76 ;
int V_44 = 0 ;
if ( V_71 < 0 ) {
#ifdef F_22
F_23 ( L_2 ,
V_2 -> V_9 ) ;
#endif
goto V_132;
}
V_115 = F_40 ( V_127 , V_2 , sizeof( * V_115 ) + V_71 ) ;
if ( V_71 )
V_44 |= F_36 ( V_115 + 1 , V_2 + 1 , V_71 ) ;
V_44 |= F_14 ( ( F_27 () -> V_133
&& F_27 () -> V_133 -> V_134
&& V_24 < 32
? F_27 () -> V_133 -> V_134 [ V_24 ]
: V_24 ) ,
& V_115 -> V_24 ) ;
V_44 |= F_14 ( V_2 -> V_10 , & V_115 -> V_135 ) ;
V_44 |= F_14 ( & V_115 -> V_43 , & V_115 -> V_136 ) ;
if ( V_118 > 1 )
V_44 |= F_36 ( V_115 -> V_119 , & V_116 -> V_24 [ 1 ] ,
sizeof( V_115 -> V_119 ) ) ;
F_37 ( & V_76 , V_2 , V_116 -> V_24 [ 0 ] ) ;
V_44 |= F_36 ( & V_115 -> V_43 , & V_76 , sizeof( V_76 ) ) ;
V_44 |= F_14 ( V_115 -> V_137 , & V_115 -> V_138 ) ;
V_44 |= F_14 ( 0x70004e40 + ( V_139 << 16 ) ,
( long T_3 * ) ( V_115 -> V_137 ) ) ;
if ( V_44 )
goto V_132;
F_39 ( ( unsigned long ) & V_115 -> V_137 ) ;
F_28 ( ( unsigned long ) V_115 ) ;
V_2 -> V_6 = ( unsigned long ) V_127 -> V_33 . V_34 ;
if ( V_71 )
V_2 -> V_7 = V_71 ;
if ( V_2 -> V_7 ) {
struct V_1 * V_5 =
(struct V_1 * ) ( ( V_140 ) V_2 + V_2 -> V_7 ) ;
#ifdef F_22
F_23 ( L_3 , V_2 -> V_7 ) ;
#endif
V_5 -> V_10 = 0 ;
V_5 -> V_9 = 0 ;
V_5 -> V_6 = V_2 -> V_6 ;
V_5 -> V_11 = V_2 -> V_11 ;
}
return 0 ;
V_132:
F_43 ( V_24 , V_16 ) ;
return V_44 ;
}
static int F_44 ( int V_24 , struct V_28 * V_127 , T_9 * V_141 ,
T_7 * V_116 , struct V_1 * V_2 )
{
struct V_121 T_3 * V_115 ;
int V_71 = V_8 [ V_2 -> V_9 ] ;
int V_44 = 0 ;
if ( V_71 < 0 ) {
#ifdef F_22
F_23 ( L_2 ,
V_2 -> V_9 ) ;
#endif
goto V_132;
}
V_115 = F_40 ( V_127 , V_2 , sizeof( * V_115 ) ) ;
if ( V_71 )
V_44 |= F_36 ( & V_115 -> V_61 . V_112 , V_2 + 1 , V_71 ) ;
V_44 |= F_14 ( ( F_27 () -> V_133
&& F_27 () -> V_133 -> V_134
&& V_24 < 32
? F_27 () -> V_133 -> V_134 [ V_24 ]
: V_24 ) ,
& V_115 -> V_24 ) ;
V_44 |= F_14 ( & V_115 -> V_141 , & V_115 -> V_142 ) ;
V_44 |= F_14 ( & V_115 -> V_61 , & V_115 -> V_143 ) ;
V_44 |= F_45 ( & V_115 -> V_141 , V_141 ) ;
V_44 |= F_14 ( 0 , & V_115 -> V_61 . V_144 ) ;
V_44 |= F_14 ( NULL , & V_115 -> V_61 . V_145 ) ;
V_44 |= F_14 ( ( void T_3 * ) V_16 -> V_130 ,
& V_115 -> V_61 . V_111 . V_146 ) ;
V_44 |= F_14 ( F_41 ( F_17 () ) ,
& V_115 -> V_61 . V_111 . V_147 ) ;
V_44 |= F_14 ( V_16 -> V_131 , & V_115 -> V_61 . V_111 . V_148 ) ;
V_44 |= F_38 ( & V_115 -> V_61 , V_2 ) ;
V_44 |= F_36 ( & V_115 -> V_61 . V_122 , V_116 , sizeof( * V_116 ) ) ;
V_44 |= F_14 ( V_115 -> V_137 , & V_115 -> V_138 ) ;
#ifdef F_46
V_44 |= F_14 ( 0x203c0000 , ( long T_3 * ) ( V_115 -> V_137 + 0 ) ) ;
V_44 |= F_14 ( 0x00004e40 + ( V_149 << 16 ) ,
( long T_3 * ) ( V_115 -> V_137 + 4 ) ) ;
#else
V_44 |= F_14 ( 0x70004600 + ( ( V_149 ^ 0xff ) << 16 ) ,
( long T_3 * ) ( V_115 -> V_137 + 0 ) ) ;
V_44 |= F_14 ( 0x4e40 , ( short T_3 * ) ( V_115 -> V_137 + 4 ) ) ;
#endif
if ( V_44 )
goto V_132;
F_39 ( ( unsigned long ) & V_115 -> V_137 ) ;
F_28 ( ( unsigned long ) V_115 ) ;
V_2 -> V_6 = ( unsigned long ) V_127 -> V_33 . V_34 ;
if ( V_71 )
V_2 -> V_7 = V_71 ;
if ( V_2 -> V_7 ) {
struct V_1 * V_5 =
(struct V_1 * ) ( ( V_140 ) V_2 + V_2 -> V_7 ) ;
#ifdef F_22
F_23 ( L_3 , V_2 -> V_7 ) ;
#endif
V_5 -> V_10 = 0 ;
V_5 -> V_9 = 0 ;
V_5 -> V_6 = V_2 -> V_6 ;
V_5 -> V_11 = V_2 -> V_11 ;
}
return 0 ;
V_132:
F_43 ( V_24 , V_16 ) ;
return V_44 ;
}
static inline void
F_47 ( struct V_1 * V_2 , struct V_28 * V_127 , int V_150 )
{
switch ( V_2 -> V_81 ) {
case - V_23 :
if ( ! V_150 )
goto V_151;
V_2 -> V_81 = - V_152 ;
break;
case - V_153 :
if ( ! V_150 ) {
V_2 -> V_81 = V_154 ;
V_2 -> V_6 -= 2 ;
break;
}
V_2 -> V_81 = - V_152 ;
break;
case - V_155 :
if ( V_150 && ! ( V_127 -> V_33 . V_36 & V_156 ) ) {
V_2 -> V_81 = - V_152 ;
break;
}
case - V_157 :
V_151:
V_2 -> V_81 = V_2 -> V_91 ;
V_2 -> V_6 -= 2 ;
break;
}
}
void F_48 ( struct V_1 * V_2 , void * V_158 )
{
if ( V_2 -> V_91 < 0 )
return;
switch ( V_2 -> V_81 ) {
case - V_23 :
case - V_155 :
case - V_157 :
V_2 -> V_81 = V_2 -> V_91 ;
V_2 -> V_91 = - 1 ;
V_2 -> V_6 -= 2 ;
break;
}
}
static void
F_49 ( int V_24 , struct V_28 * V_127 , T_9 * V_141 ,
T_7 * V_159 , struct V_1 * V_2 )
{
int V_44 ;
if ( V_2 -> V_91 >= 0 )
F_47 ( V_2 , V_127 , 1 ) ;
if ( V_127 -> V_33 . V_36 & V_160 )
V_44 = F_44 ( V_24 , V_127 , V_141 , V_159 , V_2 ) ;
else
V_44 = F_42 ( V_24 , V_127 , V_159 , V_2 ) ;
if ( V_44 )
return;
F_50 ( & V_16 -> V_20 , & V_16 -> V_20 , & V_127 -> V_33 . V_37 ) ;
if ( ! ( V_127 -> V_33 . V_36 & V_161 ) )
F_51 ( & V_16 -> V_20 , V_24 ) ;
F_6 () ;
if ( F_52 ( V_162 ) ) {
V_2 -> V_11 &= ~ 0x8000 ;
F_53 ( V_163 , V_16 , 1 ) ;
}
F_54 ( V_164 ) ;
}
T_1 void F_55 ( struct V_1 * V_2 )
{
T_9 V_141 ;
struct V_28 V_127 ;
int V_165 ;
T_7 * V_159 ;
V_16 -> V_46 . V_166 = ( unsigned long ) V_2 ;
if ( F_52 ( V_164 ) )
V_159 = & V_16 -> V_19 ;
else
V_159 = & V_16 -> V_20 ;
V_165 = F_56 ( & V_141 , & V_127 , V_2 , NULL ) ;
if ( V_165 > 0 ) {
F_49 ( V_165 , & V_127 , & V_141 , V_159 , V_2 ) ;
return;
}
if ( V_2 -> V_91 >= 0 )
F_47 ( V_2 , NULL , 0 ) ;
if ( F_52 ( V_164 ) ) {
F_54 ( V_164 ) ;
F_57 ( V_167 , & V_16 -> V_19 , NULL ) ;
}
}

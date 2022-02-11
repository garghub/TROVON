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
#ifdef F_3
V_5 -> V_9 = 4 ;
#else
V_5 -> V_9 = 0 ;
#endif
V_5 -> V_6 = V_4 -> V_4 ;
V_5 -> V_11 = V_2 -> V_11 ;
return 1 ;
}
T_1 int
F_4 ( int V_12 , int V_13 , T_2 V_14 )
{
V_14 &= V_15 ;
F_5 ( & V_16 -> V_17 -> V_18 ) ;
V_16 -> V_19 = V_16 -> V_20 ;
F_6 ( & V_16 -> V_20 , V_14 ) ;
F_7 () ;
F_8 ( & V_16 -> V_17 -> V_18 ) ;
V_16 -> V_21 = V_22 ;
F_9 () ;
F_10 () ;
return - V_23 ;
}
T_1 int
F_11 ( int V_24 , const struct V_25 T_3 * V_26 ,
struct V_25 T_3 * V_27 )
{
struct V_28 V_29 , V_30 ;
int V_31 ;
if ( V_26 ) {
T_2 V_14 ;
if ( ! F_12 ( V_32 , V_26 , sizeof( * V_26 ) ) ||
F_13 ( V_29 . V_33 . V_34 , & V_26 -> V_34 ) ||
F_13 ( V_29 . V_33 . V_35 , & V_26 -> V_35 ) ||
F_13 ( V_29 . V_33 . V_36 , & V_26 -> V_36 ) ||
F_13 ( V_14 , & V_26 -> V_37 ) )
return - V_38 ;
F_6 ( & V_29 . V_33 . V_37 , V_14 ) ;
}
V_31 = F_14 ( V_24 , V_26 ? & V_29 : NULL , V_27 ? & V_30 : NULL ) ;
if ( ! V_31 && V_27 ) {
if ( ! F_12 ( V_39 , V_27 , sizeof( * V_27 ) ) ||
F_15 ( V_30 . V_33 . V_34 , & V_27 -> V_34 ) ||
F_15 ( V_30 . V_33 . V_35 , & V_27 -> V_35 ) ||
F_15 ( V_30 . V_33 . V_36 , & V_27 -> V_36 ) ||
F_15 ( V_30 . V_33 . V_37 . V_24 [ 0 ] , & V_27 -> V_37 ) )
return - V_38 ;
}
return V_31 ;
}
T_1 int
F_16 ( const T_4 T_3 * V_40 , T_4 T_3 * V_41 )
{
return F_17 ( V_40 , V_41 , F_18 () ) ;
}
static inline int F_19 ( struct V_42 * V_43 )
{
int V_44 = 1 ;
if ( V_45 ) {
memcpy ( V_16 -> V_46 . V_47 , V_43 -> V_48 , 12 ) ;
memcpy ( V_16 -> V_46 . V_49 , V_43 -> V_50 , 24 ) ;
return 0 ;
}
if ( V_51 ? V_43 -> V_52 [ 2 ] : V_43 -> V_52 [ 0 ] ) {
if ( ! ( V_51 || V_53 ) &&
( V_43 -> V_52 [ 0 ] != V_54 ) )
goto V_55;
if ( V_56 ) {
if ( V_57 & V_58 &&
! ( V_43 -> V_52 [ 1 ] == 0x18 || V_43 -> V_52 [ 1 ] == 0xb4 ) )
goto V_55;
if ( V_57 & V_59 &&
! ( V_43 -> V_52 [ 1 ] == 0x38 || V_43 -> V_52 [ 1 ] == 0xd4 ) )
goto V_55;
} else if ( V_60 ) {
if ( ! ( V_43 -> V_52 [ 1 ] == 0x00 ||
V_43 -> V_52 [ 1 ] == 0x28 ||
V_43 -> V_52 [ 1 ] == 0x60 ) )
goto V_55;
} else if ( V_51 ) {
if ( ! ( V_43 -> V_52 [ 3 ] == 0x00 ||
V_43 -> V_52 [ 3 ] == 0x60 ||
V_43 -> V_52 [ 3 ] == 0xe0 ) )
goto V_55;
} else if ( V_53 ) {
if ( ! ( V_43 -> V_52 [ 0 ] == 0x00 ||
V_43 -> V_52 [ 0 ] == 0x05 ||
V_43 -> V_52 [ 0 ] == 0xe5 ) )
goto V_55;
} else
goto V_55;
if ( V_53 ) {
__asm__ volatile ("fmovemd %0,%%fp0-%%fp1\n\t"
"fmovel %1,%%fpcr\n\t"
"fmovel %2,%%fpsr\n\t"
"fmovel %3,%%fpiar"
:
: "m" (sc->sc_fpregs[0]),
"m" (sc->sc_fpcntl[0]),
"m" (sc->sc_fpcntl[1]),
"m" (sc->sc_fpcntl[2]));
} else {
__asm__ volatile (".chip 68k/68881\n\t"
"fmovemx %0,%%fp0-%%fp1\n\t"
"fmoveml %1,%%fpcr/%%fpsr/%%fpiar\n\t"
".chip 68k"
:
: "m" (*sc->sc_fpregs),
"m" (*sc->sc_fpcntl));
}
}
if ( V_53 ) {
__asm__ volatile ("frestore %0" : : "m" (*sc->sc_fpstate));
} else {
__asm__ volatile (".chip 68k/68881\n\t"
"frestore %0\n\t"
".chip 68k"
: : "m" (*sc->sc_fpstate));
}
V_44 = 0 ;
V_55:
return V_44 ;
}
static inline int F_20 ( struct V_61 T_3 * V_62 )
{
unsigned char V_63 [ V_64 ] ;
int V_65 = V_51 ? 8 : ( V_53 ? 12 : 0 ) ;
T_5 V_66 ;
int V_44 = 1 ;
if ( V_45 ) {
if ( F_21 ( V_16 -> V_46 . V_47 ,
V_62 -> V_67 . V_66 . V_68 , 12 ) )
goto V_55;
if ( F_21 ( V_16 -> V_46 . V_49 ,
V_62 -> V_67 . V_66 . V_69 , 96 ) )
goto V_55;
return 0 ;
}
if ( F_13 ( * ( long * ) V_63 , ( long T_3 * ) & V_62 -> V_70 ) )
goto V_55;
if ( V_51 ? V_63 [ 2 ] : V_63 [ 0 ] ) {
if ( ! ( V_51 || V_53 ) )
V_65 = V_63 [ 1 ] ;
if ( ! ( V_51 || V_53 ) &&
( V_63 [ 0 ] != V_54 ) )
goto V_55;
if ( V_56 ) {
if ( V_57 & V_58 &&
! ( V_65 == 0x18 || V_65 == 0xb4 ) )
goto V_55;
if ( V_57 & V_59 &&
! ( V_65 == 0x38 || V_65 == 0xd4 ) )
goto V_55;
} else if ( V_60 ) {
if ( ! ( V_65 == 0x00 ||
V_65 == 0x28 ||
V_65 == 0x60 ) )
goto V_55;
} else if ( V_51 ) {
if ( ! ( V_63 [ 3 ] == 0x00 ||
V_63 [ 3 ] == 0x60 ||
V_63 [ 3 ] == 0xe0 ) )
goto V_55;
} else if ( V_53 ) {
if ( ! ( V_63 [ 3 ] == 0x00 ||
V_63 [ 3 ] == 0x05 ||
V_63 [ 3 ] == 0xe5 ) )
goto V_55;
} else
goto V_55;
if ( F_21 ( & V_66 , & V_62 -> V_67 . V_66 ,
sizeof( V_66 ) ) )
goto V_55;
if ( V_53 ) {
__asm__ volatile ("fmovemd %0,%%fp0-%%fp7\n\t"
"fmovel %1,%%fpcr\n\t"
"fmovel %2,%%fpsr\n\t"
"fmovel %3,%%fpiar"
:
: "m" (fpregs.f_fpregs[0]),
"m" (fpregs.f_fpcntl[0]),
"m" (fpregs.f_fpcntl[1]),
"m" (fpregs.f_fpcntl[2]));
} else {
__asm__ volatile (".chip 68k/68881\n\t"
"fmovemx %0,%%fp0-%%fp7\n\t"
"fmoveml %1,%%fpcr/%%fpsr/%%fpiar\n\t"
".chip 68k"
:
: "m" (*fpregs.f_fpregs),
"m" (*fpregs.f_fpcntl));
}
}
if ( V_65 &&
F_21 ( V_63 + 4 , ( long T_3 * ) & V_62 -> V_70 + 1 ,
V_65 ) )
goto V_55;
if ( V_53 ) {
__asm__ volatile ("frestore %0" : : "m" (*fpstate));
} else {
__asm__ volatile (".chip 68k/68881\n\t"
"frestore %0\n\t"
".chip 68k"
: : "m" (*fpstate));
}
V_44 = 0 ;
V_55:
return V_44 ;
}
static int F_22 ( struct V_1 * V_2 , int V_71 ,
void T_3 * V_49 )
{
int V_72 = V_8 [ V_71 >> 12 ] ;
if ( V_72 < 0 ) {
#ifdef F_23
F_24 ( L_1 ) ;
#endif
return 1 ;
}
if ( ! V_72 ) {
V_2 -> V_9 = V_71 >> 12 ;
V_2 -> V_10 = V_71 & 0xfff ;
} else {
struct V_73 * V_74 = (struct V_73 * ) V_2 - 1 ;
unsigned long V_75 [ V_72 / 2 ] ;
if ( F_25 ( V_75 + V_72 / 4 , V_49 , V_72 ) )
return 1 ;
V_2 -> V_9 = V_71 >> 12 ;
V_2 -> V_10 = V_71 & 0xfff ;
#define F_26 (sizeof(struct pt_regs)+sizeof(struct switch_stack))
__asm__ __volatile__ (
#ifdef F_3
" movel %0,%/sp\n\t"
" bra ret_from_signal\n"
#else
" movel %0,%/a0\n\t"
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
#endif
:
: "a" (sw), "d" (fsize), "d" (frame_offset/4-1),
"n" (frame_offset), "a" (buf + fsize/4)
: "a0");
#undef F_26
}
return 0 ;
}
static inline int
F_27 ( struct V_1 * V_2 , struct V_42 T_3 * V_76 , void T_3 * V_49 )
{
int V_71 ;
struct V_42 V_77 ;
int V_44 ;
F_28 () -> V_78 . V_79 = V_80 ;
if ( F_25 ( & V_77 , V_76 , sizeof( V_77 ) ) )
goto V_81;
V_2 -> V_82 = V_77 . V_83 ;
V_2 -> V_84 = V_77 . V_85 ;
V_2 -> V_86 = V_77 . V_87 ;
V_2 -> V_88 = V_77 . V_89 ;
V_2 -> V_11 = ( V_2 -> V_11 & 0xff00 ) | ( V_77 . V_90 & 0xff ) ;
V_2 -> V_6 = V_77 . V_91 ;
V_2 -> V_92 = - 1 ;
F_29 ( V_77 . V_93 ) ;
V_71 = V_77 . V_94 ;
V_44 = F_19 ( & V_77 ) ;
if ( V_44 || F_22 ( V_2 , V_71 , V_49 ) )
goto V_81;
return 0 ;
V_81:
return 1 ;
}
static inline int
F_30 ( struct V_1 * V_2 , struct V_73 * V_74 ,
struct V_61 T_3 * V_62 )
{
int V_95 ;
T_6 T_3 * V_96 = V_62 -> V_67 . V_96 ;
unsigned long V_97 ;
int V_44 ;
F_28 () -> V_78 . V_79 = V_80 ;
V_44 = F_13 ( V_95 , & V_62 -> V_67 . V_98 ) ;
if ( V_95 != V_99 )
goto V_81;
V_44 |= F_13 ( V_2 -> V_82 , & V_96 [ 0 ] ) ;
V_44 |= F_13 ( V_2 -> V_84 , & V_96 [ 1 ] ) ;
V_44 |= F_13 ( V_2 -> V_100 , & V_96 [ 2 ] ) ;
V_44 |= F_13 ( V_2 -> V_101 , & V_96 [ 3 ] ) ;
V_44 |= F_13 ( V_2 -> V_102 , & V_96 [ 4 ] ) ;
V_44 |= F_13 ( V_2 -> V_103 , & V_96 [ 5 ] ) ;
V_44 |= F_13 ( V_74 -> V_104 , & V_96 [ 6 ] ) ;
V_44 |= F_13 ( V_74 -> V_105 , & V_96 [ 7 ] ) ;
V_44 |= F_13 ( V_2 -> V_86 , & V_96 [ 8 ] ) ;
V_44 |= F_13 ( V_2 -> V_88 , & V_96 [ 9 ] ) ;
V_44 |= F_13 ( V_2 -> V_106 , & V_96 [ 10 ] ) ;
V_44 |= F_13 ( V_74 -> V_107 , & V_96 [ 11 ] ) ;
V_44 |= F_13 ( V_74 -> V_108 , & V_96 [ 12 ] ) ;
V_44 |= F_13 ( V_74 -> V_109 , & V_96 [ 13 ] ) ;
V_44 |= F_13 ( V_74 -> V_110 , & V_96 [ 14 ] ) ;
V_44 |= F_13 ( V_97 , & V_96 [ 15 ] ) ;
F_29 ( V_97 ) ;
V_44 |= F_13 ( V_2 -> V_6 , & V_96 [ 16 ] ) ;
V_44 |= F_13 ( V_95 , & V_96 [ 17 ] ) ;
V_2 -> V_11 = ( V_2 -> V_11 & 0xff00 ) | ( V_95 & 0xff ) ;
V_2 -> V_92 = - 1 ;
V_44 |= F_13 ( V_95 , & V_62 -> V_111 ) ;
V_44 |= F_20 ( V_62 ) ;
if ( V_44 || F_17 ( & V_62 -> V_112 , NULL , V_97 ) == - V_38 )
goto V_81;
if ( F_22 ( V_2 , V_95 , & V_62 -> V_113 ) )
goto V_81;
return 0 ;
V_81:
return 1 ;
}
T_1 int F_31 ( unsigned long V_114 )
{
struct V_73 * V_74 = (struct V_73 * ) & V_114 ;
struct V_1 * V_2 = (struct V_1 * ) ( V_74 + 1 ) ;
unsigned long V_97 = F_18 () ;
struct V_115 T_3 * V_116 = (struct V_115 T_3 * ) ( V_97 - 4 ) ;
T_7 V_117 ;
if ( ! F_12 ( V_32 , V_116 , sizeof( * V_116 ) ) )
goto V_81;
if ( F_13 ( V_117 . V_24 [ 0 ] , & V_116 -> V_43 . V_118 ) ||
( V_119 > 1 &&
F_21 ( & V_117 . V_24 [ 1 ] , & V_116 -> V_120 ,
sizeof( V_116 -> V_120 ) ) ) )
goto V_81;
F_32 ( & V_117 , ~ V_15 ) ;
V_16 -> V_20 = V_117 ;
F_7 () ;
if ( F_27 ( V_2 , & V_116 -> V_43 , V_116 + 1 ) )
goto V_81;
return V_2 -> V_82 ;
V_81:
F_33 ( V_121 , V_16 ) ;
return 0 ;
}
T_1 int F_34 ( unsigned long V_114 )
{
struct V_73 * V_74 = (struct V_73 * ) & V_114 ;
struct V_1 * V_2 = (struct V_1 * ) ( V_74 + 1 ) ;
unsigned long V_97 = F_18 () ;
struct V_122 T_3 * V_116 = (struct V_122 T_3 * ) ( V_97 - 4 ) ;
T_7 V_117 ;
if ( ! F_12 ( V_32 , V_116 , sizeof( * V_116 ) ) )
goto V_81;
if ( F_21 ( & V_117 , & V_116 -> V_62 . V_123 , sizeof( V_117 ) ) )
goto V_81;
F_32 ( & V_117 , ~ V_15 ) ;
V_16 -> V_20 = V_117 ;
F_7 () ;
if ( F_30 ( V_2 , V_74 , & V_116 -> V_62 ) )
goto V_81;
return V_2 -> V_82 ;
V_81:
F_33 ( V_121 , V_16 ) ;
return 0 ;
}
static inline void F_35 ( struct V_42 * V_43 , struct V_1 * V_2 )
{
if ( V_45 ) {
memcpy ( V_43 -> V_48 , V_16 -> V_46 . V_47 , 12 ) ;
memcpy ( V_43 -> V_50 , V_16 -> V_46 . V_49 , 24 ) ;
return;
}
if ( V_53 ) {
__asm__ volatile ("fsave %0"
: : "m" (*sc->sc_fpstate) : "memory");
} else {
__asm__ volatile (".chip 68k/68881\n\t"
"fsave %0\n\t"
".chip 68k"
: : "m" (*sc->sc_fpstate) : "memory");
}
if ( V_51 ? V_43 -> V_52 [ 2 ] : V_43 -> V_52 [ 0 ] ) {
V_54 = V_43 -> V_52 [ 0 ] ;
if ( V_56 &&
V_2 -> V_10 >= ( V_124 * 4 ) &&
V_2 -> V_10 <= ( V_125 * 4 ) ) {
if ( * ( unsigned short * ) V_43 -> V_52 == 0x1f38 )
V_43 -> V_52 [ 0x38 ] |= 1 << 3 ;
}
if ( V_53 ) {
__asm__ volatile ("fmovemd %%fp0-%%fp1,%0\n\t"
"fmovel %%fpcr,%1\n\t"
"fmovel %%fpsr,%2\n\t"
"fmovel %%fpiar,%3"
: "=m" (sc->sc_fpregs[0]),
"=m" (sc->sc_fpcntl[0]),
"=m" (sc->sc_fpcntl[1]),
"=m" (sc->sc_fpcntl[2])
:
: "memory");
} else {
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
}
static inline int F_36 ( struct V_61 T_3 * V_62 , struct V_1 * V_2 )
{
unsigned char V_63 [ V_64 ] ;
int V_65 = V_51 ? 8 : ( V_53 ? 12 : 0 ) ;
int V_44 = 0 ;
if ( V_45 ) {
V_44 |= F_37 ( V_62 -> V_67 . V_66 . V_68 ,
V_16 -> V_46 . V_47 , 12 ) ;
V_44 |= F_37 ( V_62 -> V_67 . V_66 . V_69 ,
V_16 -> V_46 . V_49 , 96 ) ;
return V_44 ;
}
if ( V_53 ) {
__asm__ volatile ("fsave %0" : : "m" (*fpstate) : "memory");
} else {
__asm__ volatile (".chip 68k/68881\n\t"
"fsave %0\n\t"
".chip 68k"
: : "m" (*fpstate) : "memory");
}
V_44 |= F_15 ( * ( long * ) V_63 , ( long T_3 * ) & V_62 -> V_70 ) ;
if ( V_51 ? V_63 [ 2 ] : V_63 [ 0 ] ) {
T_5 V_66 ;
if ( ! ( V_51 || V_53 ) )
V_65 = V_63 [ 1 ] ;
V_54 = V_63 [ 0 ] ;
if ( V_56 &&
V_2 -> V_10 >= ( V_124 * 4 ) &&
V_2 -> V_10 <= ( V_125 * 4 ) ) {
if ( * ( unsigned short * ) V_63 == 0x1f38 )
V_63 [ 0x38 ] |= 1 << 3 ;
}
if ( V_53 ) {
__asm__ volatile ("fmovemd %%fp0-%%fp7,%0\n\t"
"fmovel %%fpcr,%1\n\t"
"fmovel %%fpsr,%2\n\t"
"fmovel %%fpiar,%3"
: "=m" (fpregs.f_fpregs[0]),
"=m" (fpregs.f_fpcntl[0]),
"=m" (fpregs.f_fpcntl[1]),
"=m" (fpregs.f_fpcntl[2])
:
: "memory");
} else {
__asm__ volatile (".chip 68k/68881\n\t"
"fmovemx %%fp0-%%fp7,%0\n\t"
"fmoveml %%fpcr/%%fpsr/%%fpiar,%1\n\t"
".chip 68k"
: "=m" (*fpregs.f_fpregs),
"=m" (*fpregs.f_fpcntl)
:
: "memory");
}
V_44 |= F_37 ( & V_62 -> V_67 . V_66 , & V_66 ,
sizeof( V_66 ) ) ;
}
if ( V_65 )
V_44 |= F_37 ( ( long T_3 * ) & V_62 -> V_70 + 1 , V_63 + 4 ,
V_65 ) ;
return V_44 ;
}
static void F_38 ( struct V_42 * V_43 , struct V_1 * V_2 ,
unsigned long V_14 )
{
V_43 -> V_118 = V_14 ;
V_43 -> V_93 = F_18 () ;
V_43 -> V_83 = V_2 -> V_82 ;
V_43 -> V_85 = V_2 -> V_84 ;
V_43 -> V_87 = V_2 -> V_86 ;
V_43 -> V_89 = V_2 -> V_88 ;
V_43 -> V_90 = V_2 -> V_11 ;
V_43 -> V_91 = V_2 -> V_6 ;
V_43 -> V_94 = V_2 -> V_9 << 12 | V_2 -> V_10 ;
F_35 ( V_43 , V_2 ) ;
}
static inline int F_39 ( struct V_61 T_3 * V_62 , struct V_1 * V_2 )
{
struct V_73 * V_74 = (struct V_73 * ) V_2 - 1 ;
T_6 T_3 * V_96 = V_62 -> V_67 . V_96 ;
int V_44 = 0 ;
V_44 |= F_15 ( V_99 , & V_62 -> V_67 . V_98 ) ;
V_44 |= F_15 ( V_2 -> V_82 , & V_96 [ 0 ] ) ;
V_44 |= F_15 ( V_2 -> V_84 , & V_96 [ 1 ] ) ;
V_44 |= F_15 ( V_2 -> V_100 , & V_96 [ 2 ] ) ;
V_44 |= F_15 ( V_2 -> V_101 , & V_96 [ 3 ] ) ;
V_44 |= F_15 ( V_2 -> V_102 , & V_96 [ 4 ] ) ;
V_44 |= F_15 ( V_2 -> V_103 , & V_96 [ 5 ] ) ;
V_44 |= F_15 ( V_74 -> V_104 , & V_96 [ 6 ] ) ;
V_44 |= F_15 ( V_74 -> V_105 , & V_96 [ 7 ] ) ;
V_44 |= F_15 ( V_2 -> V_86 , & V_96 [ 8 ] ) ;
V_44 |= F_15 ( V_2 -> V_88 , & V_96 [ 9 ] ) ;
V_44 |= F_15 ( V_2 -> V_106 , & V_96 [ 10 ] ) ;
V_44 |= F_15 ( V_74 -> V_107 , & V_96 [ 11 ] ) ;
V_44 |= F_15 ( V_74 -> V_108 , & V_96 [ 12 ] ) ;
V_44 |= F_15 ( V_74 -> V_109 , & V_96 [ 13 ] ) ;
V_44 |= F_15 ( V_74 -> V_110 , & V_96 [ 14 ] ) ;
V_44 |= F_15 ( F_18 () , & V_96 [ 15 ] ) ;
V_44 |= F_15 ( V_2 -> V_6 , & V_96 [ 16 ] ) ;
V_44 |= F_15 ( V_2 -> V_11 , & V_96 [ 17 ] ) ;
V_44 |= F_15 ( ( V_2 -> V_9 << 12 ) | V_2 -> V_10 , & V_62 -> V_111 ) ;
V_44 |= F_36 ( V_62 , V_2 ) ;
return V_44 ;
}
static inline void F_40 ( unsigned long V_126 )
{
if ( V_60 ) {
unsigned long V_95 ;
__asm__ __volatile__ (".chip 68040\n\t"
"nop\n\t"
"ptestr (%1)\n\t"
"movec %%mmusr,%0\n\t"
".chip 68k"
: "=r" (temp)
: "a" (vaddr));
V_95 &= V_127 ;
V_95 |= V_126 & ~ V_127 ;
__asm__ __volatile__ (".chip 68040\n\t"
"nop\n\t"
"cpushl %%bc,(%0)\n\t"
".chip 68k"
: : "a" (temp));
}
else if ( V_51 ) {
unsigned long V_95 ;
__asm__ __volatile__ (".chip 68060\n\t"
"plpar (%0)\n\t"
".chip 68k"
: "=a" (temp)
: "0" (vaddr));
__asm__ __volatile__ (".chip 68060\n\t"
"cpushl %%bc,(%0)\n\t"
".chip 68k"
: : "a" (temp));
} else if ( ! V_53 ) {
unsigned long V_95 ;
asm volatile ("movec %%cacr,%0" : "=r" (temp));
V_95 += 4 ;
asm volatile ("movec %0,%%caar\n\t"
"movec %1,%%cacr"
: : "r" (vaddr), "r" (temp));
asm volatile ("movec %0,%%caar\n\t"
"movec %1,%%cacr"
: : "r" (vaddr + 4), "r" (temp));
}
}
static inline void T_3 *
F_41 ( struct V_28 * V_128 , struct V_1 * V_2 , T_8 V_129 )
{
unsigned long V_97 ;
V_97 = F_18 () ;
if ( V_128 -> V_33 . V_36 & V_130 ) {
if ( ! F_42 ( V_97 ) )
V_97 = V_16 -> V_131 + V_16 -> V_132 ;
}
return ( void T_3 * ) ( ( V_97 - V_129 ) & - 8UL ) ;
}
static int F_43 ( int V_24 , struct V_28 * V_128 ,
T_7 * V_117 , struct V_1 * V_2 )
{
struct V_115 T_3 * V_116 ;
int V_72 = V_8 [ V_2 -> V_9 ] ;
struct V_42 V_77 ;
int V_44 = 0 ;
if ( V_72 < 0 ) {
#ifdef F_23
F_24 ( L_2 ,
V_2 -> V_9 ) ;
#endif
goto V_133;
}
V_116 = F_41 ( V_128 , V_2 , sizeof( * V_116 ) + V_72 ) ;
if ( V_72 )
V_44 |= F_37 ( V_116 + 1 , V_2 + 1 , V_72 ) ;
V_44 |= F_15 ( ( F_28 () -> V_134
&& F_28 () -> V_134 -> V_135
&& V_24 < 32
? F_28 () -> V_134 -> V_135 [ V_24 ]
: V_24 ) ,
& V_116 -> V_24 ) ;
V_44 |= F_15 ( V_2 -> V_10 , & V_116 -> V_136 ) ;
V_44 |= F_15 ( & V_116 -> V_43 , & V_116 -> V_137 ) ;
if ( V_119 > 1 )
V_44 |= F_37 ( V_116 -> V_120 , & V_117 -> V_24 [ 1 ] ,
sizeof( V_116 -> V_120 ) ) ;
F_38 ( & V_77 , V_2 , V_117 -> V_24 [ 0 ] ) ;
V_44 |= F_37 ( & V_116 -> V_43 , & V_77 , sizeof( V_77 ) ) ;
V_44 |= F_15 ( V_116 -> V_138 , & V_116 -> V_139 ) ;
V_44 |= F_15 ( 0x70004e40 + ( V_140 << 16 ) ,
( long T_3 * ) ( V_116 -> V_138 ) ) ;
if ( V_44 )
goto V_133;
F_40 ( ( unsigned long ) & V_116 -> V_138 ) ;
F_29 ( ( unsigned long ) V_116 ) ;
V_2 -> V_6 = ( unsigned long ) V_128 -> V_33 . V_34 ;
if ( V_72 )
V_2 -> V_7 = V_72 ;
if ( V_2 -> V_7 ) {
struct V_1 * V_5 =
(struct V_1 * ) ( ( V_141 ) V_2 + V_2 -> V_7 ) ;
#ifdef F_23
F_24 ( L_3 , V_2 -> V_7 ) ;
#endif
V_5 -> V_10 = 0 ;
V_5 -> V_9 = 0 ;
V_5 -> V_6 = V_2 -> V_6 ;
V_5 -> V_11 = V_2 -> V_11 ;
}
return 0 ;
V_133:
F_44 ( V_24 , V_16 ) ;
return V_44 ;
}
static int F_45 ( int V_24 , struct V_28 * V_128 , T_9 * V_142 ,
T_7 * V_117 , struct V_1 * V_2 )
{
struct V_122 T_3 * V_116 ;
int V_72 = V_8 [ V_2 -> V_9 ] ;
int V_44 = 0 ;
if ( V_72 < 0 ) {
#ifdef F_23
F_24 ( L_2 ,
V_2 -> V_9 ) ;
#endif
goto V_133;
}
V_116 = F_41 ( V_128 , V_2 , sizeof( * V_116 ) ) ;
if ( V_72 )
V_44 |= F_37 ( & V_116 -> V_62 . V_113 , V_2 + 1 , V_72 ) ;
V_44 |= F_15 ( ( F_28 () -> V_134
&& F_28 () -> V_134 -> V_135
&& V_24 < 32
? F_28 () -> V_134 -> V_135 [ V_24 ]
: V_24 ) ,
& V_116 -> V_24 ) ;
V_44 |= F_15 ( & V_116 -> V_142 , & V_116 -> V_143 ) ;
V_44 |= F_15 ( & V_116 -> V_62 , & V_116 -> V_144 ) ;
V_44 |= F_46 ( & V_116 -> V_142 , V_142 ) ;
V_44 |= F_15 ( 0 , & V_116 -> V_62 . V_145 ) ;
V_44 |= F_15 ( NULL , & V_116 -> V_62 . V_146 ) ;
V_44 |= F_15 ( ( void T_3 * ) V_16 -> V_131 ,
& V_116 -> V_62 . V_112 . V_147 ) ;
V_44 |= F_15 ( F_42 ( F_18 () ) ,
& V_116 -> V_62 . V_112 . V_148 ) ;
V_44 |= F_15 ( V_16 -> V_132 , & V_116 -> V_62 . V_112 . V_149 ) ;
V_44 |= F_39 ( & V_116 -> V_62 , V_2 ) ;
V_44 |= F_37 ( & V_116 -> V_62 . V_123 , V_117 , sizeof( * V_117 ) ) ;
V_44 |= F_15 ( V_116 -> V_138 , & V_116 -> V_139 ) ;
#ifdef F_47
V_44 |= F_15 ( 0x203c0000 , ( long T_3 * ) ( V_116 -> V_138 + 0 ) ) ;
V_44 |= F_15 ( 0x00004e40 + ( V_150 << 16 ) ,
( long T_3 * ) ( V_116 -> V_138 + 4 ) ) ;
#else
V_44 |= F_15 ( 0x70004600 + ( ( V_150 ^ 0xff ) << 16 ) ,
( long T_3 * ) ( V_116 -> V_138 + 0 ) ) ;
V_44 |= F_15 ( 0x4e40 , ( short T_3 * ) ( V_116 -> V_138 + 4 ) ) ;
#endif
if ( V_44 )
goto V_133;
F_40 ( ( unsigned long ) & V_116 -> V_138 ) ;
F_29 ( ( unsigned long ) V_116 ) ;
V_2 -> V_6 = ( unsigned long ) V_128 -> V_33 . V_34 ;
if ( V_72 )
V_2 -> V_7 = V_72 ;
if ( V_2 -> V_7 ) {
struct V_1 * V_5 =
(struct V_1 * ) ( ( V_141 ) V_2 + V_2 -> V_7 ) ;
#ifdef F_23
F_24 ( L_3 , V_2 -> V_7 ) ;
#endif
V_5 -> V_10 = 0 ;
V_5 -> V_9 = 0 ;
V_5 -> V_6 = V_2 -> V_6 ;
V_5 -> V_11 = V_2 -> V_11 ;
}
return 0 ;
V_133:
F_44 ( V_24 , V_16 ) ;
return V_44 ;
}
static inline void
F_48 ( struct V_1 * V_2 , struct V_28 * V_128 , int V_151 )
{
switch ( V_2 -> V_82 ) {
case - V_23 :
if ( ! V_151 )
goto V_152;
V_2 -> V_82 = - V_153 ;
break;
case - V_154 :
if ( ! V_151 ) {
V_2 -> V_82 = V_155 ;
V_2 -> V_6 -= 2 ;
break;
}
V_2 -> V_82 = - V_153 ;
break;
case - V_156 :
if ( V_151 && ! ( V_128 -> V_33 . V_36 & V_157 ) ) {
V_2 -> V_82 = - V_153 ;
break;
}
case - V_158 :
V_152:
V_2 -> V_82 = V_2 -> V_92 ;
V_2 -> V_6 -= 2 ;
break;
}
}
void F_49 ( struct V_1 * V_2 , void * V_159 )
{
if ( V_2 -> V_92 < 0 )
return;
switch ( V_2 -> V_82 ) {
case - V_23 :
case - V_156 :
case - V_158 :
V_2 -> V_82 = V_2 -> V_92 ;
V_2 -> V_92 = - 1 ;
V_2 -> V_6 -= 2 ;
break;
}
}
static void
F_50 ( int V_24 , struct V_28 * V_128 , T_9 * V_142 ,
T_7 * V_160 , struct V_1 * V_2 )
{
int V_44 ;
if ( V_2 -> V_92 >= 0 )
F_48 ( V_2 , V_128 , 1 ) ;
if ( V_128 -> V_33 . V_36 & V_161 )
V_44 = F_45 ( V_24 , V_128 , V_142 , V_160 , V_2 ) ;
else
V_44 = F_43 ( V_24 , V_128 , V_160 , V_2 ) ;
if ( V_44 )
return;
F_51 ( & V_16 -> V_20 , & V_16 -> V_20 , & V_128 -> V_33 . V_37 ) ;
if ( ! ( V_128 -> V_33 . V_36 & V_162 ) )
F_52 ( & V_16 -> V_20 , V_24 ) ;
F_7 () ;
if ( F_53 ( V_163 ) ) {
V_2 -> V_11 &= ~ 0x8000 ;
F_54 ( V_164 , V_16 , 1 ) ;
}
F_55 ( V_165 ) ;
}
T_1 void F_56 ( struct V_1 * V_2 )
{
T_9 V_142 ;
struct V_28 V_128 ;
int V_166 ;
T_7 * V_160 ;
V_16 -> V_46 . V_167 = ( unsigned long ) V_2 ;
if ( F_53 ( V_165 ) )
V_160 = & V_16 -> V_19 ;
else
V_160 = & V_16 -> V_20 ;
V_166 = F_57 ( & V_142 , & V_128 , V_2 , NULL ) ;
if ( V_166 > 0 ) {
F_50 ( V_166 , & V_128 , & V_142 , V_160 , V_2 ) ;
return;
}
if ( V_2 -> V_92 >= 0 )
F_48 ( V_2 , NULL , 0 ) ;
if ( F_53 ( V_165 ) ) {
F_55 ( V_165 ) ;
F_58 ( V_168 , & V_16 -> V_19 , NULL ) ;
}
}

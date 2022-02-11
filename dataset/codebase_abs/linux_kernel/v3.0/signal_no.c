T_1 int
F_1 ( int V_1 , int V_2 , T_2 V_3 )
{
V_3 &= V_4 ;
F_2 ( & V_5 -> V_6 -> V_7 ) ;
V_5 -> V_8 = V_5 -> V_9 ;
F_3 ( & V_5 -> V_9 , V_3 ) ;
F_4 () ;
F_5 ( & V_5 -> V_6 -> V_7 ) ;
V_5 -> V_10 = V_11 ;
F_6 () ;
F_7 () ;
return - V_12 ;
}
T_1 int
F_8 ( int V_13 , const struct V_14 T_3 * V_15 ,
struct V_14 T_3 * V_16 )
{
struct V_17 V_18 , V_19 ;
int V_20 ;
if ( V_15 ) {
T_2 V_3 ;
if ( ! F_9 ( V_21 , V_15 , sizeof( * V_15 ) ) ||
F_10 ( V_18 . V_22 . V_23 , & V_15 -> V_23 ) ||
F_10 ( V_18 . V_22 . V_24 , & V_15 -> V_24 ) ||
F_10 ( V_18 . V_22 . V_25 , & V_15 -> V_25 ) ||
F_10 ( V_3 , & V_15 -> V_26 ) )
return - V_27 ;
F_3 ( & V_18 . V_22 . V_26 , V_3 ) ;
}
V_20 = F_11 ( V_13 , V_15 ? & V_18 : NULL , V_16 ? & V_19 : NULL ) ;
if ( ! V_20 && V_16 ) {
if ( ! F_9 ( V_28 , V_16 , sizeof( * V_16 ) ) ||
F_12 ( V_19 . V_22 . V_23 , & V_16 -> V_23 ) ||
F_12 ( V_19 . V_22 . V_24 , & V_16 -> V_24 ) ||
F_12 ( V_19 . V_22 . V_25 , & V_16 -> V_25 ) ||
F_12 ( V_19 . V_22 . V_26 . V_13 [ 0 ] , & V_16 -> V_26 ) )
return - V_27 ;
}
return V_20 ;
}
T_1 int
F_13 ( const T_4 T_3 * V_29 , T_4 T_3 * V_30 )
{
return F_14 ( V_29 , V_30 , F_15 () ) ;
}
static inline int F_16 ( struct V_31 * V_32 )
{
int V_33 = 1 ;
if ( V_34 ) {
memcpy ( V_5 -> V_35 . V_36 , V_32 -> V_37 , 12 ) ;
memcpy ( V_5 -> V_35 . V_38 , V_32 -> V_39 , 24 ) ;
return 0 ;
}
if ( V_32 -> V_40 [ 0 ] ) {
if ( V_32 -> V_40 [ 0 ] != V_41 )
goto V_42;
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
V_33 = 0 ;
V_42:
return V_33 ;
}
static inline int F_17 ( struct V_43 T_3 * V_44 )
{
unsigned char V_45 [ V_46 ] ;
int V_47 = 0 ;
T_5 V_48 ;
int V_33 = 1 ;
if ( V_34 ) {
if ( F_18 ( V_5 -> V_35 . V_36 ,
V_44 -> V_49 . V_48 . V_50 , 12 ) )
goto V_42;
if ( F_18 ( V_5 -> V_35 . V_38 ,
V_44 -> V_49 . V_48 . V_51 , 96 ) )
goto V_42;
return 0 ;
}
if ( F_10 ( * ( long * ) V_45 , ( long T_3 * ) & V_44 -> V_52 ) )
goto V_42;
if ( V_45 [ 0 ] ) {
V_47 = V_45 [ 1 ] ;
if ( V_45 [ 0 ] != V_41 )
goto V_42;
if ( F_18 ( & V_48 , & V_44 -> V_49 . V_48 ,
sizeof( V_48 ) ) )
goto V_42;
__asm__ volatile (".chip 68k/68881\n\t"
"fmovemx %0,%%fp0-%%fp7\n\t"
"fmoveml %1,%%fpcr/%%fpsr/%%fpiar\n\t"
".chip 68k"
:
: "m" (*fpregs.f_fpregs),
"m" (*fpregs.f_fpcntl));
}
if ( V_47 &&
F_18 ( V_45 + 4 , ( long T_3 * ) & V_44 -> V_52 + 1 ,
V_47 ) )
goto V_42;
__asm__ volatile (".chip 68k/68881\n\t"
"frestore %0\n\t"
".chip 68k" : : "m" (*fpstate));
V_33 = 0 ;
V_42:
return V_33 ;
}
static inline int
F_19 ( struct V_53 * V_54 , struct V_31 T_3 * V_55 , void T_3 * V_38 ,
int * V_56 )
{
int V_57 ;
struct V_31 V_58 ;
int V_33 = 0 ;
F_20 () -> V_59 . V_60 = V_61 ;
if ( F_21 ( & V_58 , V_55 , sizeof( V_58 ) ) )
goto V_62;
V_54 -> V_63 = V_58 . V_64 ;
V_54 -> V_65 = V_58 . V_66 ;
V_54 -> V_67 = V_58 . V_68 ;
( (struct V_69 * ) V_54 - 1 ) -> V_70 = V_58 . V_71 ;
V_54 -> V_72 = ( V_54 -> V_72 & 0xff00 ) | ( V_58 . V_73 & 0xff ) ;
V_54 -> V_74 = V_58 . V_75 ;
V_54 -> V_76 = - 1 ;
F_22 ( V_58 . V_77 ) ;
V_57 = V_58 . V_78 ;
V_54 -> V_79 = V_57 >> 12 ;
V_54 -> V_80 = V_57 & 0xfff ;
#ifdef F_23
V_33 = F_16 ( & V_58 ) ;
#endif
* V_56 = V_58 . V_81 ;
return V_33 ;
V_62:
return 1 ;
}
static inline int
F_24 ( struct V_53 * V_54 , struct V_69 * V_82 ,
struct V_43 T_3 * V_44 , int * V_56 )
{
int V_83 ;
T_6 T_3 * V_84 = V_44 -> V_49 . V_84 ;
unsigned long V_85 ;
int V_33 ;
F_20 () -> V_59 . V_60 = V_61 ;
V_33 = F_10 ( V_83 , & V_44 -> V_49 . V_86 ) ;
if ( V_83 != V_87 )
goto V_62;
V_33 |= F_10 ( V_54 -> V_88 , & V_84 [ 0 ] ) ;
V_33 |= F_10 ( V_54 -> V_63 , & V_84 [ 1 ] ) ;
V_33 |= F_10 ( V_54 -> V_89 , & V_84 [ 2 ] ) ;
V_33 |= F_10 ( V_54 -> V_90 , & V_84 [ 3 ] ) ;
V_33 |= F_10 ( V_54 -> V_91 , & V_84 [ 4 ] ) ;
V_33 |= F_10 ( V_54 -> V_92 , & V_84 [ 5 ] ) ;
V_33 |= F_10 ( V_82 -> V_93 , & V_84 [ 6 ] ) ;
V_33 |= F_10 ( V_82 -> V_94 , & V_84 [ 7 ] ) ;
V_33 |= F_10 ( V_54 -> V_65 , & V_84 [ 8 ] ) ;
V_33 |= F_10 ( V_54 -> V_67 , & V_84 [ 9 ] ) ;
V_33 |= F_10 ( V_54 -> V_95 , & V_84 [ 10 ] ) ;
V_33 |= F_10 ( V_82 -> V_96 , & V_84 [ 11 ] ) ;
V_33 |= F_10 ( V_82 -> V_97 , & V_84 [ 12 ] ) ;
V_33 |= F_10 ( V_82 -> V_70 , & V_84 [ 13 ] ) ;
V_33 |= F_10 ( V_82 -> V_98 , & V_84 [ 14 ] ) ;
V_33 |= F_10 ( V_85 , & V_84 [ 15 ] ) ;
F_22 ( V_85 ) ;
V_33 |= F_10 ( V_54 -> V_74 , & V_84 [ 16 ] ) ;
V_33 |= F_10 ( V_83 , & V_84 [ 17 ] ) ;
V_54 -> V_72 = ( V_54 -> V_72 & 0xff00 ) | ( V_83 & 0xff ) ;
V_54 -> V_76 = - 1 ;
V_54 -> V_79 = V_83 >> 12 ;
V_54 -> V_80 = V_83 & 0xfff ;
if ( F_14 ( & V_44 -> V_99 , NULL , V_85 ) == - V_27 )
goto V_62;
* V_56 = V_54 -> V_88 ;
return V_33 ;
V_62:
return 1 ;
}
T_1 int F_25 ( unsigned long V_100 )
{
struct V_69 * V_82 = (struct V_69 * ) & V_100 ;
struct V_53 * V_54 = (struct V_53 * ) ( V_82 + 1 ) ;
unsigned long V_85 = F_15 () ;
struct V_101 T_3 * V_102 = (struct V_101 T_3 * ) ( V_85 - 4 ) ;
T_7 V_103 ;
int V_88 ;
if ( ! F_9 ( V_21 , V_102 , sizeof( * V_102 ) ) )
goto V_62;
if ( F_10 ( V_103 . V_13 [ 0 ] , & V_102 -> V_32 . V_104 ) ||
( V_105 > 1 &&
F_18 ( & V_103 . V_13 [ 1 ] , & V_102 -> V_106 ,
sizeof( V_102 -> V_106 ) ) ) )
goto V_62;
F_26 ( & V_103 , ~ V_4 ) ;
F_2 ( & V_5 -> V_6 -> V_7 ) ;
V_5 -> V_9 = V_103 ;
F_4 () ;
F_5 ( & V_5 -> V_6 -> V_7 ) ;
if ( F_19 ( V_54 , & V_102 -> V_32 , V_102 + 1 , & V_88 ) )
goto V_62;
return V_88 ;
V_62:
F_27 ( V_107 , V_5 ) ;
return 0 ;
}
T_1 int F_28 ( unsigned long V_100 )
{
struct V_69 * V_82 = (struct V_69 * ) & V_100 ;
struct V_53 * V_54 = (struct V_53 * ) ( V_82 + 1 ) ;
unsigned long V_85 = F_15 () ;
struct V_108 T_3 * V_102 = (struct V_108 T_3 * ) ( V_85 - 4 ) ;
T_7 V_103 ;
int V_88 ;
if ( ! F_9 ( V_21 , V_102 , sizeof( * V_102 ) ) )
goto V_62;
if ( F_18 ( & V_103 , & V_102 -> V_44 . V_109 , sizeof( V_103 ) ) )
goto V_62;
F_26 ( & V_103 , ~ V_4 ) ;
F_2 ( & V_5 -> V_6 -> V_7 ) ;
V_5 -> V_9 = V_103 ;
F_4 () ;
F_5 ( & V_5 -> V_6 -> V_7 ) ;
if ( F_24 ( V_54 , V_82 , & V_102 -> V_44 , & V_88 ) )
goto V_62;
return V_88 ;
V_62:
F_27 ( V_107 , V_5 ) ;
return 0 ;
}
static inline void F_29 ( struct V_31 * V_32 , struct V_53 * V_54 )
{
if ( V_34 ) {
memcpy ( V_32 -> V_37 , V_5 -> V_35 . V_36 , 12 ) ;
memcpy ( V_32 -> V_39 , V_5 -> V_35 . V_38 , 24 ) ;
return;
}
__asm__ volatile (".chip 68k/68881\n\t"
"fsave %0\n\t"
".chip 68k"
: : "m" (*sc->sc_fpstate) : "memory");
if ( V_32 -> V_40 [ 0 ] ) {
V_41 = V_32 -> V_40 [ 0 ] ;
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
static inline int F_30 ( struct V_43 T_3 * V_44 , struct V_53 * V_54 )
{
unsigned char V_45 [ V_46 ] ;
int V_47 = 0 ;
int V_33 = 0 ;
if ( V_34 ) {
V_33 |= F_31 ( V_44 -> V_49 . V_48 . V_110 ,
V_5 -> V_35 . V_36 , 12 ) ;
V_33 |= F_31 ( V_44 -> V_49 . V_48 . V_51 ,
V_5 -> V_35 . V_38 , 96 ) ;
return V_33 ;
}
__asm__ volatile (".chip 68k/68881\n\t"
"fsave %0\n\t"
".chip 68k"
: : "m" (*fpstate) : "memory");
V_33 |= F_12 ( * ( long * ) V_45 , ( long T_3 * ) & V_44 -> V_52 ) ;
if ( V_45 [ 0 ] ) {
T_5 V_48 ;
V_47 = V_45 [ 1 ] ;
V_41 = V_45 [ 0 ] ;
__asm__ volatile (".chip 68k/68881\n\t"
"fmovemx %%fp0-%%fp7,%0\n\t"
"fmoveml %%fpcr/%%fpsr/%%fpiar,%1\n\t"
".chip 68k"
: "=m" (*fpregs.f_fpregs),
"=m" (*fpregs.f_fpcntl)
:
: "memory");
V_33 |= F_31 ( & V_44 -> V_49 . V_48 , & V_48 ,
sizeof( V_48 ) ) ;
}
if ( V_47 )
V_33 |= F_31 ( ( long T_3 * ) & V_44 -> V_52 + 1 , V_45 + 4 ,
V_47 ) ;
return V_33 ;
}
static void F_32 ( struct V_31 * V_32 , struct V_53 * V_54 ,
unsigned long V_3 )
{
V_32 -> V_104 = V_3 ;
V_32 -> V_77 = F_15 () ;
V_32 -> V_81 = V_54 -> V_88 ;
V_32 -> V_64 = V_54 -> V_63 ;
V_32 -> V_66 = V_54 -> V_65 ;
V_32 -> V_68 = V_54 -> V_67 ;
V_32 -> V_71 = ( (struct V_69 * ) V_54 - 1 ) -> V_70 ;
V_32 -> V_73 = V_54 -> V_72 ;
V_32 -> V_75 = V_54 -> V_74 ;
V_32 -> V_78 = V_54 -> V_79 << 12 | V_54 -> V_80 ;
#ifdef F_23
F_29 ( V_32 , V_54 ) ;
#endif
}
static inline int F_33 ( struct V_43 T_3 * V_44 , struct V_53 * V_54 )
{
struct V_69 * V_82 = (struct V_69 * ) V_54 - 1 ;
T_6 T_3 * V_84 = V_44 -> V_49 . V_84 ;
int V_33 = 0 ;
V_33 |= F_12 ( V_87 , & V_44 -> V_49 . V_86 ) ;
V_33 |= F_12 ( V_54 -> V_88 , & V_84 [ 0 ] ) ;
V_33 |= F_12 ( V_54 -> V_63 , & V_84 [ 1 ] ) ;
V_33 |= F_12 ( V_54 -> V_89 , & V_84 [ 2 ] ) ;
V_33 |= F_12 ( V_54 -> V_90 , & V_84 [ 3 ] ) ;
V_33 |= F_12 ( V_54 -> V_91 , & V_84 [ 4 ] ) ;
V_33 |= F_12 ( V_54 -> V_92 , & V_84 [ 5 ] ) ;
V_33 |= F_12 ( V_82 -> V_93 , & V_84 [ 6 ] ) ;
V_33 |= F_12 ( V_82 -> V_94 , & V_84 [ 7 ] ) ;
V_33 |= F_12 ( V_54 -> V_65 , & V_84 [ 8 ] ) ;
V_33 |= F_12 ( V_54 -> V_67 , & V_84 [ 9 ] ) ;
V_33 |= F_12 ( V_54 -> V_95 , & V_84 [ 10 ] ) ;
V_33 |= F_12 ( V_82 -> V_96 , & V_84 [ 11 ] ) ;
V_33 |= F_12 ( V_82 -> V_97 , & V_84 [ 12 ] ) ;
V_33 |= F_12 ( V_82 -> V_70 , & V_84 [ 13 ] ) ;
V_33 |= F_12 ( V_82 -> V_98 , & V_84 [ 14 ] ) ;
V_33 |= F_12 ( F_15 () , & V_84 [ 15 ] ) ;
V_33 |= F_12 ( V_54 -> V_74 , & V_84 [ 16 ] ) ;
V_33 |= F_12 ( V_54 -> V_72 , & V_84 [ 17 ] ) ;
#ifdef F_23
V_33 |= F_30 ( V_44 , V_54 ) ;
#endif
return V_33 ;
}
static inline void T_3 *
F_34 ( struct V_17 * V_111 , struct V_53 * V_54 , T_8 V_112 )
{
unsigned long V_85 ;
V_85 = F_15 () ;
if ( V_111 -> V_22 . V_25 & V_113 ) {
if ( ! F_35 ( V_85 ) )
V_85 = V_5 -> V_114 + V_5 -> V_115 ;
}
return ( void T_3 * ) ( ( V_85 - V_112 ) & - 8UL ) ;
}
static int F_36 ( int V_13 , struct V_17 * V_111 ,
T_7 * V_103 , struct V_53 * V_54 )
{
struct V_101 T_3 * V_102 ;
struct V_31 V_58 ;
int V_33 = 0 ;
V_102 = F_34 ( V_111 , V_54 , sizeof( * V_102 ) ) ;
V_33 |= F_12 ( ( F_20 () -> V_116
&& F_20 () -> V_116 -> V_117
&& V_13 < 32
? F_20 () -> V_116 -> V_117 [ V_13 ]
: V_13 ) ,
& V_102 -> V_13 ) ;
V_33 |= F_12 ( V_54 -> V_80 , & V_102 -> V_118 ) ;
V_33 |= F_12 ( & V_102 -> V_32 , & V_102 -> V_119 ) ;
if ( V_105 > 1 )
V_33 |= F_31 ( V_102 -> V_106 , & V_103 -> V_13 [ 1 ] ,
sizeof( V_102 -> V_106 ) ) ;
F_32 ( & V_58 , V_54 , V_103 -> V_13 [ 0 ] ) ;
V_33 |= F_31 ( & V_102 -> V_32 , & V_58 , sizeof( V_58 ) ) ;
V_33 |= F_12 ( ( void * ) V_120 , & V_102 -> V_121 ) ;
if ( V_33 )
goto V_122;
F_22 ( ( unsigned long ) V_102 ) ;
V_54 -> V_74 = ( unsigned long ) V_111 -> V_22 . V_23 ;
( (struct V_69 * ) V_54 - 1 ) -> V_70 = V_5 -> V_123 -> V_124 ;
V_54 -> V_79 = 0x4 ;
V_125:
if ( V_54 -> V_126 ) {
struct V_53 * V_127 =
(struct V_53 * ) ( ( V_128 ) V_54 + V_54 -> V_126 ) ;
#if F_37 ( V_129 )
F_38 ( V_130 L_1 , V_54 -> V_126 ) ;
#endif
V_127 -> V_80 = 0 ;
V_127 -> V_79 = 0 ;
V_127 -> V_74 = V_54 -> V_74 ;
V_127 -> V_72 = V_54 -> V_72 ;
}
return V_33 ;
V_122:
F_39 ( V_13 , V_5 ) ;
goto V_125;
}
static int F_40 ( int V_13 , struct V_17 * V_111 , T_9 * V_131 ,
T_7 * V_103 , struct V_53 * V_54 )
{
struct V_108 T_3 * V_102 ;
int V_33 = 0 ;
V_102 = F_34 ( V_111 , V_54 , sizeof( * V_102 ) ) ;
V_33 |= F_12 ( ( F_20 () -> V_116
&& F_20 () -> V_116 -> V_117
&& V_13 < 32
? F_20 () -> V_116 -> V_117 [ V_13 ]
: V_13 ) ,
& V_102 -> V_13 ) ;
V_33 |= F_12 ( & V_102 -> V_131 , & V_102 -> V_132 ) ;
V_33 |= F_12 ( & V_102 -> V_44 , & V_102 -> V_133 ) ;
V_33 |= F_41 ( & V_102 -> V_131 , V_131 ) ;
V_33 |= F_12 ( 0 , & V_102 -> V_44 . V_134 ) ;
V_33 |= F_12 ( NULL , & V_102 -> V_44 . V_135 ) ;
V_33 |= F_12 ( ( void T_3 * ) V_5 -> V_114 ,
& V_102 -> V_44 . V_99 . V_136 ) ;
V_33 |= F_12 ( F_35 ( F_15 () ) ,
& V_102 -> V_44 . V_99 . V_137 ) ;
V_33 |= F_12 ( V_5 -> V_115 , & V_102 -> V_44 . V_99 . V_138 ) ;
V_33 |= F_33 ( & V_102 -> V_44 , V_54 ) ;
V_33 |= F_31 ( & V_102 -> V_44 . V_109 , V_103 , sizeof( * V_103 ) ) ;
V_33 |= F_12 ( ( void * ) V_139 , & V_102 -> V_121 ) ;
if ( V_33 )
goto V_122;
F_22 ( ( unsigned long ) V_102 ) ;
V_54 -> V_74 = ( unsigned long ) V_111 -> V_22 . V_23 ;
( (struct V_69 * ) V_54 - 1 ) -> V_70 = V_5 -> V_123 -> V_124 ;
V_54 -> V_79 = 0x4 ;
V_125:
if ( V_54 -> V_126 ) {
struct V_53 * V_127 =
(struct V_53 * ) ( ( V_128 ) V_54 + V_54 -> V_126 ) ;
#if F_37 ( V_129 )
F_38 ( V_130 L_1 , V_54 -> V_126 ) ;
#endif
V_127 -> V_80 = 0 ;
V_127 -> V_79 = 0 ;
V_127 -> V_74 = V_54 -> V_74 ;
V_127 -> V_72 = V_54 -> V_72 ;
}
return V_33 ;
V_122:
F_39 ( V_13 , V_5 ) ;
goto V_125;
}
static inline void
F_42 ( struct V_53 * V_54 , struct V_17 * V_111 , int V_140 )
{
switch ( V_54 -> V_88 ) {
case - V_12 :
if ( ! V_140 )
goto V_141;
V_54 -> V_88 = - V_142 ;
break;
case - V_143 :
if ( ! V_140 ) {
V_54 -> V_88 = V_144 ;
V_54 -> V_74 -= 2 ;
break;
}
V_54 -> V_88 = - V_142 ;
break;
case - V_145 :
if ( V_140 && ! ( V_111 -> V_22 . V_25 & V_146 ) ) {
V_54 -> V_88 = - V_142 ;
break;
}
case - V_147 :
V_141:
V_54 -> V_88 = V_54 -> V_76 ;
V_54 -> V_74 -= 2 ;
break;
}
}
static void
F_43 ( int V_13 , struct V_17 * V_111 , T_9 * V_131 ,
T_7 * V_148 , struct V_53 * V_54 )
{
int V_33 ;
if ( V_54 -> V_76 >= 0 )
F_42 ( V_54 , V_111 , 1 ) ;
if ( V_111 -> V_22 . V_25 & V_149 )
V_33 = F_40 ( V_13 , V_111 , V_131 , V_148 , V_54 ) ;
else
V_33 = F_36 ( V_13 , V_111 , V_148 , V_54 ) ;
if ( V_33 )
return;
F_2 ( & V_5 -> V_6 -> V_7 ) ;
F_44 ( & V_5 -> V_9 , & V_5 -> V_9 , & V_111 -> V_22 . V_26 ) ;
if ( ! ( V_111 -> V_22 . V_25 & V_150 ) )
F_45 ( & V_5 -> V_9 , V_13 ) ;
F_4 () ;
F_5 ( & V_5 -> V_6 -> V_7 ) ;
F_46 ( V_151 ) ;
}
T_1 void F_47 ( struct V_53 * V_54 )
{
struct V_17 V_111 ;
T_9 V_131 ;
int V_152 ;
T_7 * V_148 ;
if ( ! F_48 ( V_54 ) )
return;
if ( F_49 ( V_151 ) )
V_148 = & V_5 -> V_8 ;
else
V_148 = & V_5 -> V_9 ;
V_152 = F_50 ( & V_131 , & V_111 , V_54 , NULL ) ;
if ( V_152 > 0 ) {
F_43 ( V_152 , & V_111 , & V_131 , V_148 , V_54 ) ;
return;
}
if ( V_54 -> V_76 >= 0 ) {
F_42 ( V_54 , NULL , 0 ) ;
}
if ( F_49 ( V_151 ) ) {
F_46 ( V_151 ) ;
F_51 ( V_153 , & V_5 -> V_8 , NULL ) ;
}
}

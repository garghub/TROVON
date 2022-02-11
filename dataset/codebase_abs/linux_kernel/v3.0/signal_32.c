T_1 int
F_1 ( T_2 V_1 ,
unsigned long V_2 , unsigned long V_3 , unsigned long V_4 ,
struct V_5 V_6 )
{
V_1 &= V_7 ;
F_2 ( & V_8 -> V_9 -> V_10 ) ;
V_8 -> V_11 = V_8 -> V_12 ;
F_3 ( & V_8 -> V_12 , V_1 ) ;
F_4 () ;
F_5 ( & V_8 -> V_9 -> V_10 ) ;
V_8 -> V_13 = V_14 ;
F_6 () ;
F_7 () ;
return - V_15 ;
}
T_1 int
F_8 ( int V_16 , const struct V_17 T_3 * V_18 ,
struct V_17 T_3 * V_19 )
{
struct V_20 V_21 , V_22 ;
int V_23 ;
if ( V_18 ) {
T_2 V_1 ;
if ( ! F_9 ( V_24 , V_18 , sizeof( * V_18 ) ) ||
F_10 ( V_21 . V_25 . V_26 , & V_18 -> V_26 ) ||
F_10 ( V_21 . V_25 . V_27 , & V_18 -> V_27 ) )
return - V_28 ;
F_10 ( V_21 . V_25 . V_29 , & V_18 -> V_29 ) ;
F_10 ( V_1 , & V_18 -> V_30 ) ;
F_3 ( & V_21 . V_25 . V_30 , V_1 ) ;
}
V_23 = F_11 ( V_16 , V_18 ? & V_21 : NULL , V_19 ? & V_22 : NULL ) ;
if ( ! V_23 && V_19 ) {
if ( ! F_9 ( V_31 , V_19 , sizeof( * V_19 ) ) ||
F_12 ( V_22 . V_25 . V_26 , & V_19 -> V_26 ) ||
F_12 ( V_22 . V_25 . V_27 , & V_19 -> V_27 ) )
return - V_28 ;
F_12 ( V_22 . V_25 . V_29 , & V_19 -> V_29 ) ;
F_12 ( V_22 . V_25 . V_30 . V_16 [ 0 ] , & V_19 -> V_30 ) ;
}
return V_23 ;
}
T_1 int
F_13 ( const T_4 T_3 * V_32 , T_4 T_3 * V_33 ,
unsigned long V_3 , unsigned long V_4 ,
struct V_5 V_6 )
{
struct V_5 * V_34 = F_14 ( & V_6 , 0 ) ;
return F_15 ( V_32 , V_33 , V_34 -> V_34 [ 15 ] ) ;
}
static inline int F_16 ( struct V_35 T_3 * V_36 )
{
struct V_37 * V_38 = V_8 ;
if ( ! ( V_39 . V_40 & V_41 ) )
return 0 ;
F_17 () ;
return F_18 ( & V_38 -> V_42 . V_43 -> V_44 , & V_36 -> V_45 [ 0 ] ,
sizeof( long ) * ( 16 * 2 + 2 ) ) ;
}
static inline int F_19 ( struct V_35 T_3 * V_36 ,
struct V_5 * V_34 )
{
struct V_37 * V_38 = V_8 ;
if ( ! ( V_39 . V_40 & V_41 ) )
return 0 ;
if ( ! F_20 () ) {
F_12 ( 0 , & V_36 -> V_46 ) ;
return 0 ;
}
F_12 ( 1 , & V_36 -> V_46 ) ;
F_21 () ;
F_22 ( V_38 , V_34 ) ;
return F_23 ( & V_36 -> V_45 [ 0 ] , & V_38 -> V_42 . V_43 -> V_44 ,
sizeof( long ) * ( 16 * 2 + 2 ) ) ;
}
static int
F_24 ( struct V_5 * V_34 , struct V_35 T_3 * V_36 , int * V_47 )
{
unsigned int V_48 = 0 ;
#define F_25 ( T_5 ) err |= __get_user(regs->x, &sc->sc_##x)
F_25 ( V_34 [ 1 ] ) ;
F_25 ( V_34 [ 2 ] ) ; F_25 ( V_34 [ 3 ] ) ;
F_25 ( V_34 [ 4 ] ) ; F_25 ( V_34 [ 5 ] ) ;
F_25 ( V_34 [ 6 ] ) ; F_25 ( V_34 [ 7 ] ) ;
F_25 ( V_34 [ 8 ] ) ; F_25 ( V_34 [ 9 ] ) ;
F_25 ( V_34 [ 10 ] ) ; F_25 ( V_34 [ 11 ] ) ;
F_25 ( V_34 [ 12 ] ) ; F_25 ( V_34 [ 13 ] ) ;
F_25 ( V_34 [ 14 ] ) ; F_25 ( V_34 [ 15 ] ) ;
F_25 ( V_49 ) ; F_25 ( V_50 ) ;
F_25 ( V_51 ) ; F_25 ( V_52 ) ;
F_25 ( V_53 ) ; F_25 ( V_54 ) ;
#undef F_25
#ifdef F_26
if ( V_39 . V_40 & V_41 ) {
int V_55 ;
struct V_37 * V_38 = V_8 ;
V_34 -> V_53 |= V_56 ;
F_27 ( V_38 , V_34 ) ;
F_21 () ;
F_10 ( V_55 , & V_36 -> V_46 ) ;
if ( V_55 )
V_48 |= F_16 ( V_36 ) ;
}
#endif
V_34 -> V_57 = - 1 ;
V_48 |= F_10 ( * V_47 , & V_36 -> V_58 [ 0 ] ) ;
return V_48 ;
}
T_1 int F_28 ( unsigned long V_59 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 ,
struct V_5 V_6 )
{
struct V_5 * V_34 = F_14 ( & V_6 , 0 ) ;
struct V_60 T_3 * V_61 = (struct V_60 T_3 * ) V_34 -> V_34 [ 15 ] ;
T_6 V_62 ;
int V_63 ;
F_29 () -> V_64 . V_65 = V_66 ;
if ( ! F_9 ( V_24 , V_61 , sizeof( * V_61 ) ) )
goto V_67;
if ( F_10 ( V_62 . V_16 [ 0 ] , & V_61 -> V_36 . V_68 )
|| ( V_69 > 1
&& F_18 ( & V_62 . V_16 [ 1 ] , & V_61 -> V_70 ,
sizeof( V_61 -> V_70 ) ) ) )
goto V_67;
F_30 ( & V_62 , ~ V_7 ) ;
F_2 ( & V_8 -> V_9 -> V_10 ) ;
V_8 -> V_12 = V_62 ;
F_4 () ;
F_5 ( & V_8 -> V_9 -> V_10 ) ;
if ( F_24 ( V_34 , & V_61 -> V_36 , & V_63 ) )
goto V_67;
return V_63 ;
V_67:
F_31 ( V_71 , V_8 ) ;
return 0 ;
}
T_1 int F_32 ( unsigned long V_59 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 ,
struct V_5 V_6 )
{
struct V_5 * V_34 = F_14 ( & V_6 , 0 ) ;
struct V_72 T_3 * V_61 = (struct V_72 T_3 * ) V_34 -> V_34 [ 15 ] ;
T_6 V_62 ;
int V_63 ;
F_29 () -> V_64 . V_65 = V_66 ;
if ( ! F_9 ( V_24 , V_61 , sizeof( * V_61 ) ) )
goto V_67;
if ( F_18 ( & V_62 , & V_61 -> V_73 . V_74 , sizeof( V_62 ) ) )
goto V_67;
F_30 ( & V_62 , ~ V_7 ) ;
F_2 ( & V_8 -> V_9 -> V_10 ) ;
V_8 -> V_12 = V_62 ;
F_4 () ;
F_5 ( & V_8 -> V_9 -> V_10 ) ;
if ( F_24 ( V_34 , & V_61 -> V_73 . V_75 , & V_63 ) )
goto V_67;
if ( F_15 ( & V_61 -> V_73 . V_76 , NULL ,
V_34 -> V_34 [ 15 ] ) == - V_28 )
goto V_67;
return V_63 ;
V_67:
F_31 ( V_71 , V_8 ) ;
return 0 ;
}
static int
F_33 ( struct V_35 T_3 * V_36 , struct V_5 * V_34 ,
unsigned long V_1 )
{
int V_48 = 0 ;
#define F_25 ( T_5 ) err |= __put_user(regs->x, &sc->sc_##x)
F_25 ( V_34 [ 0 ] ) ; F_25 ( V_34 [ 1 ] ) ;
F_25 ( V_34 [ 2 ] ) ; F_25 ( V_34 [ 3 ] ) ;
F_25 ( V_34 [ 4 ] ) ; F_25 ( V_34 [ 5 ] ) ;
F_25 ( V_34 [ 6 ] ) ; F_25 ( V_34 [ 7 ] ) ;
F_25 ( V_34 [ 8 ] ) ; F_25 ( V_34 [ 9 ] ) ;
F_25 ( V_34 [ 10 ] ) ; F_25 ( V_34 [ 11 ] ) ;
F_25 ( V_34 [ 12 ] ) ; F_25 ( V_34 [ 13 ] ) ;
F_25 ( V_34 [ 14 ] ) ; F_25 ( V_34 [ 15 ] ) ;
F_25 ( V_49 ) ; F_25 ( V_50 ) ;
F_25 ( V_51 ) ; F_25 ( V_52 ) ;
F_25 ( V_53 ) ; F_25 ( V_54 ) ;
#undef F_25
#ifdef F_26
V_48 |= F_19 ( V_36 , V_34 ) ;
#endif
V_48 |= F_12 ( V_1 , & V_36 -> V_68 ) ;
return V_48 ;
}
static inline void T_3 *
F_34 ( struct V_20 * V_77 , unsigned long V_78 , T_7 V_79 )
{
if ( V_77 -> V_25 . V_29 & V_80 ) {
if ( F_35 ( V_78 ) == 0 )
V_78 = V_8 -> V_81 + V_8 -> V_82 ;
}
return ( void T_3 * ) ( ( V_78 - ( V_79 + V_83 ) ) & - 8ul ) ;
}
static int F_36 ( int V_16 , struct V_20 * V_77 ,
T_6 * V_62 , struct V_5 * V_34 )
{
struct V_60 T_3 * V_61 ;
int V_48 = 0 ;
int signal ;
V_61 = F_34 ( V_77 , V_34 -> V_34 [ 15 ] , sizeof( * V_61 ) ) ;
if ( ! F_9 ( V_31 , V_61 , sizeof( * V_61 ) ) )
goto V_84;
signal = F_29 () -> V_85
&& F_29 () -> V_85 -> V_86
&& V_16 < 32
? F_29 () -> V_85 -> V_86 [ V_16 ]
: V_16 ;
V_48 |= F_33 ( & V_61 -> V_36 , V_34 , V_62 -> V_16 [ 0 ] ) ;
if ( V_69 > 1 )
V_48 |= F_23 ( V_61 -> V_70 , & V_62 -> V_16 [ 1 ] ,
sizeof( V_61 -> V_70 ) ) ;
if ( V_77 -> V_25 . V_29 & V_87 ) {
V_34 -> V_52 = ( unsigned long ) V_77 -> V_25 . V_27 ;
#ifdef F_37
} else if ( F_38 ( V_8 -> V_88 -> V_89 . V_90 ) ) {
V_34 -> V_52 = F_39 ( & V_91 ) ;
#endif
} else {
V_48 |= F_12 ( F_40 ( 7 ) , & V_61 -> V_92 [ 0 ] ) ;
V_48 |= F_12 ( V_93 , & V_61 -> V_92 [ 1 ] ) ;
V_48 |= F_12 ( V_94 , & V_61 -> V_92 [ 2 ] ) ;
V_48 |= F_12 ( V_94 , & V_61 -> V_92 [ 3 ] ) ;
V_48 |= F_12 ( V_94 , & V_61 -> V_92 [ 4 ] ) ;
V_48 |= F_12 ( V_94 , & V_61 -> V_92 [ 5 ] ) ;
V_48 |= F_12 ( V_94 , & V_61 -> V_92 [ 6 ] ) ;
V_48 |= F_12 ( ( V_95 ) , & V_61 -> V_92 [ 7 ] ) ;
V_34 -> V_52 = ( unsigned long ) V_61 -> V_92 ;
F_41 ( V_34 -> V_52 , V_34 -> V_52 + sizeof( V_61 -> V_92 ) ) ;
}
if ( V_48 )
goto V_84;
V_34 -> V_34 [ 15 ] = ( unsigned long ) V_61 ;
V_34 -> V_34 [ 4 ] = signal ;
V_34 -> V_34 [ 5 ] = 0 ;
V_34 -> V_34 [ 6 ] = ( unsigned long ) & V_61 -> V_36 ;
if ( V_8 -> V_96 & V_97 ) {
struct V_98 T_3 * V_99 =
(struct V_98 T_3 * ) V_77 -> V_25 . V_26 ;
F_10 ( V_34 -> V_54 , & V_99 -> V_100 ) ;
F_10 ( V_34 -> V_34 [ 12 ] , & V_99 -> V_101 ) ;
} else
V_34 -> V_54 = ( unsigned long ) V_77 -> V_25 . V_26 ;
F_42 ( V_102 ) ;
F_43 ( L_1 ,
V_8 -> V_103 , F_44 ( V_8 ) , V_61 , V_34 -> V_54 , V_34 -> V_52 ) ;
return 0 ;
V_84:
F_45 ( V_16 , V_8 ) ;
return - V_28 ;
}
static int F_46 ( int V_16 , struct V_20 * V_77 , T_8 * V_104 ,
T_6 * V_62 , struct V_5 * V_34 )
{
struct V_72 T_3 * V_61 ;
int V_48 = 0 ;
int signal ;
V_61 = F_34 ( V_77 , V_34 -> V_34 [ 15 ] , sizeof( * V_61 ) ) ;
if ( ! F_9 ( V_31 , V_61 , sizeof( * V_61 ) ) )
goto V_84;
signal = F_29 () -> V_85
&& F_29 () -> V_85 -> V_86
&& V_16 < 32
? F_29 () -> V_85 -> V_86 [ V_16 ]
: V_16 ;
V_48 |= F_47 ( & V_61 -> V_104 , V_104 ) ;
V_48 |= F_12 ( 0 , & V_61 -> V_73 . V_105 ) ;
V_48 |= F_12 ( NULL , & V_61 -> V_73 . V_106 ) ;
V_48 |= F_12 ( ( void * ) V_8 -> V_81 ,
& V_61 -> V_73 . V_76 . V_107 ) ;
V_48 |= F_12 ( F_35 ( V_34 -> V_34 [ 15 ] ) ,
& V_61 -> V_73 . V_76 . V_108 ) ;
V_48 |= F_12 ( V_8 -> V_82 , & V_61 -> V_73 . V_76 . V_109 ) ;
V_48 |= F_33 ( & V_61 -> V_73 . V_75 ,
V_34 , V_62 -> V_16 [ 0 ] ) ;
V_48 |= F_23 ( & V_61 -> V_73 . V_74 , V_62 , sizeof( * V_62 ) ) ;
if ( V_77 -> V_25 . V_29 & V_87 ) {
V_34 -> V_52 = ( unsigned long ) V_77 -> V_25 . V_27 ;
#ifdef F_37
} else if ( F_38 ( V_8 -> V_88 -> V_89 . V_90 ) ) {
V_34 -> V_52 = F_39 ( & V_110 ) ;
#endif
} else {
V_48 |= F_12 ( F_40 ( 7 ) , & V_61 -> V_92 [ 0 ] ) ;
V_48 |= F_12 ( V_93 , & V_61 -> V_92 [ 1 ] ) ;
V_48 |= F_12 ( V_94 , & V_61 -> V_92 [ 2 ] ) ;
V_48 |= F_12 ( V_94 , & V_61 -> V_92 [ 3 ] ) ;
V_48 |= F_12 ( V_94 , & V_61 -> V_92 [ 4 ] ) ;
V_48 |= F_12 ( V_94 , & V_61 -> V_92 [ 5 ] ) ;
V_48 |= F_12 ( V_94 , & V_61 -> V_92 [ 6 ] ) ;
V_48 |= F_12 ( ( V_111 ) , & V_61 -> V_92 [ 7 ] ) ;
V_34 -> V_52 = ( unsigned long ) V_61 -> V_92 ;
F_41 ( V_34 -> V_52 , V_34 -> V_52 + sizeof( V_61 -> V_92 ) ) ;
}
if ( V_48 )
goto V_84;
V_34 -> V_34 [ 15 ] = ( unsigned long ) V_61 ;
V_34 -> V_34 [ 4 ] = signal ;
V_34 -> V_34 [ 5 ] = ( unsigned long ) & V_61 -> V_104 ;
V_34 -> V_34 [ 6 ] = ( unsigned long ) & V_61 -> V_73 ;
if ( V_8 -> V_96 & V_97 ) {
struct V_98 T_3 * V_99 =
(struct V_98 T_3 * ) V_77 -> V_25 . V_26 ;
F_10 ( V_34 -> V_54 , & V_99 -> V_100 ) ;
F_10 ( V_34 -> V_34 [ 12 ] , & V_99 -> V_101 ) ;
} else
V_34 -> V_54 = ( unsigned long ) V_77 -> V_25 . V_26 ;
F_42 ( V_102 ) ;
F_43 ( L_1 ,
V_8 -> V_103 , F_44 ( V_8 ) , V_61 , V_34 -> V_54 , V_34 -> V_52 ) ;
return 0 ;
V_84:
F_45 ( V_16 , V_8 ) ;
return - V_28 ;
}
static inline void
F_48 ( unsigned long V_112 , struct V_5 * V_34 ,
struct V_113 * V_25 )
{
if ( V_34 -> V_57 < 0 )
return;
switch ( V_34 -> V_34 [ 0 ] ) {
case - V_114 :
case - V_15 :
V_115:
V_34 -> V_34 [ 0 ] = - V_116 ;
break;
case - V_117 :
if ( ! ( V_25 -> V_29 & V_118 ) )
goto V_115;
case - V_119 :
V_34 -> V_34 [ 0 ] = V_112 ;
V_34 -> V_54 -= F_49 ( F_50 ( V_34 -> V_54 - 4 ) ) ;
break;
}
}
static int
F_51 ( unsigned long V_16 , struct V_20 * V_77 , T_8 * V_104 ,
T_6 * V_120 , struct V_5 * V_34 , unsigned int V_112 )
{
int V_23 ;
if ( V_77 -> V_25 . V_29 & V_121 )
V_23 = F_46 ( V_16 , V_77 , V_104 , V_120 , V_34 ) ;
else
V_23 = F_36 ( V_16 , V_77 , V_120 , V_34 ) ;
if ( V_77 -> V_25 . V_29 & V_122 )
V_77 -> V_25 . V_26 = V_123 ;
if ( V_23 == 0 ) {
F_2 ( & V_8 -> V_9 -> V_10 ) ;
F_52 ( & V_8 -> V_12 , & V_8 -> V_12 , & V_77 -> V_25 . V_30 ) ;
if ( ! ( V_77 -> V_25 . V_29 & V_124 ) )
F_53 ( & V_8 -> V_12 , V_16 ) ;
F_4 () ;
F_5 ( & V_8 -> V_9 -> V_10 ) ;
}
return V_23 ;
}
static void F_54 ( struct V_5 * V_34 , unsigned int V_112 )
{
T_8 V_104 ;
int V_125 ;
struct V_20 V_77 ;
T_6 * V_120 ;
if ( ! F_55 ( V_34 ) )
return;
if ( F_56 () )
goto V_126;
if ( F_29 () -> V_127 & V_128 )
V_120 = & V_8 -> V_11 ;
else
V_120 = & V_8 -> V_12 ;
V_125 = F_57 ( & V_104 , & V_77 , V_34 , NULL ) ;
if ( V_125 > 0 ) {
F_48 ( V_112 , V_34 , & V_77 . V_25 ) ;
if ( F_51 ( V_125 , & V_77 , & V_104 , V_120 ,
V_34 , V_112 ) == 0 ) {
F_29 () -> V_127 &= ~ V_128 ;
F_58 ( V_125 , & V_104 , & V_77 , V_34 ,
F_59 ( V_129 ) ) ;
}
return;
}
V_126:
if ( V_34 -> V_57 >= 0 ) {
if ( V_34 -> V_34 [ 0 ] == - V_15 ||
V_34 -> V_34 [ 0 ] == - V_117 ||
V_34 -> V_34 [ 0 ] == - V_119 ) {
V_34 -> V_34 [ 0 ] = V_112 ;
V_34 -> V_54 -= F_49 ( F_50 ( V_34 -> V_54 - 4 ) ) ;
} else if ( V_34 -> V_34 [ 0 ] == - V_114 ) {
V_34 -> V_54 -= F_49 ( F_50 ( V_34 -> V_54 - 4 ) ) ;
V_34 -> V_34 [ 3 ] = V_130 ;
}
}
if ( F_29 () -> V_127 & V_128 ) {
F_29 () -> V_127 &= ~ V_128 ;
F_60 ( V_131 , & V_8 -> V_11 , NULL ) ;
}
}
T_1 void F_61 ( struct V_5 * V_34 , unsigned int V_112 ,
unsigned long V_132 )
{
if ( V_132 & V_133 )
F_54 ( V_34 , V_112 ) ;
if ( V_132 & V_134 ) {
F_62 ( V_135 ) ;
F_63 ( V_34 ) ;
if ( V_8 -> V_136 )
F_64 () ;
}
}

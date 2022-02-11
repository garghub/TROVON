T_1 int
F_1 ( T_2 V_1 ,
unsigned long V_2 , unsigned long V_3 , unsigned long V_4 ,
struct V_5 V_6 )
{
T_3 V_7 ;
V_8 -> V_9 = V_8 -> V_7 ;
V_1 &= V_10 ;
F_2 ( & V_7 , V_1 ) ;
F_3 ( & V_7 ) ;
V_8 -> V_11 = V_12 ;
F_4 () ;
F_5 () ;
return - V_13 ;
}
T_1 int
F_6 ( int V_14 , const struct V_15 T_4 * V_16 ,
struct V_15 T_4 * V_17 )
{
struct V_18 V_19 , V_20 ;
int V_21 ;
if ( V_16 ) {
T_2 V_1 ;
if ( ! F_7 ( V_22 , V_16 , sizeof( * V_16 ) ) ||
F_8 ( V_19 . V_23 . V_24 , & V_16 -> V_24 ) ||
F_8 ( V_19 . V_23 . V_25 , & V_16 -> V_25 ) )
return - V_26 ;
F_8 ( V_19 . V_23 . V_27 , & V_16 -> V_27 ) ;
F_8 ( V_1 , & V_16 -> V_28 ) ;
F_2 ( & V_19 . V_23 . V_28 , V_1 ) ;
}
V_21 = F_9 ( V_14 , V_16 ? & V_19 : NULL , V_17 ? & V_20 : NULL ) ;
if ( ! V_21 && V_17 ) {
if ( ! F_7 ( V_29 , V_17 , sizeof( * V_17 ) ) ||
F_10 ( V_20 . V_23 . V_24 , & V_17 -> V_24 ) ||
F_10 ( V_20 . V_23 . V_25 , & V_17 -> V_25 ) )
return - V_26 ;
F_10 ( V_20 . V_23 . V_27 , & V_17 -> V_27 ) ;
F_10 ( V_20 . V_23 . V_28 . V_14 [ 0 ] , & V_17 -> V_28 ) ;
}
return V_21 ;
}
T_1 int
F_11 ( const T_5 T_4 * V_30 , T_5 T_4 * V_31 ,
unsigned long V_3 , unsigned long V_4 ,
struct V_5 V_6 )
{
struct V_5 * V_32 = F_12 ( & V_6 , 0 ) ;
return F_13 ( V_30 , V_31 , V_32 -> V_32 [ 15 ] ) ;
}
static inline int F_14 ( struct V_33 T_4 * V_34 )
{
struct V_35 * V_36 = V_8 ;
if ( ! ( V_37 . V_38 & V_39 ) )
return 0 ;
F_15 () ;
return F_16 ( & V_36 -> V_40 . V_41 -> V_42 , & V_34 -> V_43 [ 0 ] ,
sizeof( long ) * ( 16 * 2 + 2 ) ) ;
}
static inline int F_17 ( struct V_33 T_4 * V_34 ,
struct V_5 * V_32 )
{
struct V_35 * V_36 = V_8 ;
if ( ! ( V_37 . V_38 & V_39 ) )
return 0 ;
if ( ! F_18 () ) {
F_10 ( 0 , & V_34 -> V_44 ) ;
return 0 ;
}
F_10 ( 1 , & V_34 -> V_44 ) ;
F_19 () ;
F_20 ( V_36 , V_32 ) ;
return F_21 ( & V_34 -> V_43 [ 0 ] , & V_36 -> V_40 . V_41 -> V_42 ,
sizeof( long ) * ( 16 * 2 + 2 ) ) ;
}
static int
F_22 ( struct V_5 * V_32 , struct V_33 T_4 * V_34 , int * V_45 )
{
unsigned int V_46 = 0 ;
#define F_23 ( T_6 ) err |= __get_user(regs->x, &sc->sc_##x)
F_23 ( V_32 [ 1 ] ) ;
F_23 ( V_32 [ 2 ] ) ; F_23 ( V_32 [ 3 ] ) ;
F_23 ( V_32 [ 4 ] ) ; F_23 ( V_32 [ 5 ] ) ;
F_23 ( V_32 [ 6 ] ) ; F_23 ( V_32 [ 7 ] ) ;
F_23 ( V_32 [ 8 ] ) ; F_23 ( V_32 [ 9 ] ) ;
F_23 ( V_32 [ 10 ] ) ; F_23 ( V_32 [ 11 ] ) ;
F_23 ( V_32 [ 12 ] ) ; F_23 ( V_32 [ 13 ] ) ;
F_23 ( V_32 [ 14 ] ) ; F_23 ( V_32 [ 15 ] ) ;
F_23 ( V_47 ) ; F_23 ( V_48 ) ;
F_23 ( V_49 ) ; F_23 ( V_50 ) ;
F_23 ( V_51 ) ; F_23 ( V_52 ) ;
#undef F_23
#ifdef F_24
if ( V_37 . V_38 & V_39 ) {
int V_53 ;
struct V_35 * V_36 = V_8 ;
V_32 -> V_51 |= V_54 ;
F_25 ( V_36 , V_32 ) ;
F_19 () ;
F_8 ( V_53 , & V_34 -> V_44 ) ;
if ( V_53 )
V_46 |= F_14 ( V_34 ) ;
}
#endif
V_32 -> V_55 = - 1 ;
V_46 |= F_8 ( * V_45 , & V_34 -> V_56 [ 0 ] ) ;
return V_46 ;
}
T_1 int F_26 ( unsigned long V_57 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 ,
struct V_5 V_6 )
{
struct V_5 * V_32 = F_12 ( & V_6 , 0 ) ;
struct V_58 T_4 * V_59 = (struct V_58 T_4 * ) V_32 -> V_32 [ 15 ] ;
T_3 V_60 ;
int V_61 ;
F_27 () -> V_62 . V_63 = V_64 ;
if ( ! F_7 ( V_22 , V_59 , sizeof( * V_59 ) ) )
goto V_65;
if ( F_8 ( V_60 . V_14 [ 0 ] , & V_59 -> V_34 . V_66 )
|| ( V_67 > 1
&& F_16 ( & V_60 . V_14 [ 1 ] , & V_59 -> V_68 ,
sizeof( V_59 -> V_68 ) ) ) )
goto V_65;
F_28 ( & V_60 , ~ V_10 ) ;
F_3 ( & V_60 ) ;
if ( F_22 ( V_32 , & V_59 -> V_34 , & V_61 ) )
goto V_65;
return V_61 ;
V_65:
F_29 ( V_69 , V_8 ) ;
return 0 ;
}
T_1 int F_30 ( unsigned long V_57 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 ,
struct V_5 V_6 )
{
struct V_5 * V_32 = F_12 ( & V_6 , 0 ) ;
struct V_70 T_4 * V_59 = (struct V_70 T_4 * ) V_32 -> V_32 [ 15 ] ;
T_3 V_60 ;
int V_61 ;
F_27 () -> V_62 . V_63 = V_64 ;
if ( ! F_7 ( V_22 , V_59 , sizeof( * V_59 ) ) )
goto V_65;
if ( F_16 ( & V_60 , & V_59 -> V_71 . V_72 , sizeof( V_60 ) ) )
goto V_65;
F_28 ( & V_60 , ~ V_10 ) ;
F_3 ( & V_60 ) ;
if ( F_22 ( V_32 , & V_59 -> V_71 . V_73 , & V_61 ) )
goto V_65;
if ( F_13 ( & V_59 -> V_71 . V_74 , NULL ,
V_32 -> V_32 [ 15 ] ) == - V_26 )
goto V_65;
return V_61 ;
V_65:
F_29 ( V_69 , V_8 ) ;
return 0 ;
}
static int
F_31 ( struct V_33 T_4 * V_34 , struct V_5 * V_32 ,
unsigned long V_1 )
{
int V_46 = 0 ;
#define F_23 ( T_6 ) err |= __put_user(regs->x, &sc->sc_##x)
F_23 ( V_32 [ 0 ] ) ; F_23 ( V_32 [ 1 ] ) ;
F_23 ( V_32 [ 2 ] ) ; F_23 ( V_32 [ 3 ] ) ;
F_23 ( V_32 [ 4 ] ) ; F_23 ( V_32 [ 5 ] ) ;
F_23 ( V_32 [ 6 ] ) ; F_23 ( V_32 [ 7 ] ) ;
F_23 ( V_32 [ 8 ] ) ; F_23 ( V_32 [ 9 ] ) ;
F_23 ( V_32 [ 10 ] ) ; F_23 ( V_32 [ 11 ] ) ;
F_23 ( V_32 [ 12 ] ) ; F_23 ( V_32 [ 13 ] ) ;
F_23 ( V_32 [ 14 ] ) ; F_23 ( V_32 [ 15 ] ) ;
F_23 ( V_47 ) ; F_23 ( V_48 ) ;
F_23 ( V_49 ) ; F_23 ( V_50 ) ;
F_23 ( V_51 ) ; F_23 ( V_52 ) ;
#undef F_23
#ifdef F_24
V_46 |= F_17 ( V_34 , V_32 ) ;
#endif
V_46 |= F_10 ( V_1 , & V_34 -> V_66 ) ;
return V_46 ;
}
static inline void T_4 *
F_32 ( struct V_18 * V_75 , unsigned long V_76 , T_7 V_77 )
{
if ( V_75 -> V_23 . V_27 & V_78 ) {
if ( F_33 ( V_76 ) == 0 )
V_76 = V_8 -> V_79 + V_8 -> V_80 ;
}
return ( void T_4 * ) ( ( V_76 - ( V_77 + V_81 ) ) & - 8ul ) ;
}
static int F_34 ( int V_14 , struct V_18 * V_75 ,
T_3 * V_60 , struct V_5 * V_32 )
{
struct V_58 T_4 * V_59 ;
int V_46 = 0 ;
int signal ;
V_59 = F_32 ( V_75 , V_32 -> V_32 [ 15 ] , sizeof( * V_59 ) ) ;
if ( ! F_7 ( V_29 , V_59 , sizeof( * V_59 ) ) )
goto V_82;
signal = F_27 () -> V_83
&& F_27 () -> V_83 -> V_84
&& V_14 < 32
? F_27 () -> V_83 -> V_84 [ V_14 ]
: V_14 ;
V_46 |= F_31 ( & V_59 -> V_34 , V_32 , V_60 -> V_14 [ 0 ] ) ;
if ( V_67 > 1 )
V_46 |= F_21 ( V_59 -> V_68 , & V_60 -> V_14 [ 1 ] ,
sizeof( V_59 -> V_68 ) ) ;
if ( V_75 -> V_23 . V_27 & V_85 ) {
V_32 -> V_50 = ( unsigned long ) V_75 -> V_23 . V_25 ;
#ifdef F_35
} else if ( F_36 ( V_8 -> V_86 -> V_87 . V_88 ) ) {
V_32 -> V_50 = F_37 ( & V_89 ) ;
#endif
} else {
V_46 |= F_10 ( F_38 ( 7 ) , & V_59 -> V_90 [ 0 ] ) ;
V_46 |= F_10 ( V_91 , & V_59 -> V_90 [ 1 ] ) ;
V_46 |= F_10 ( V_92 , & V_59 -> V_90 [ 2 ] ) ;
V_46 |= F_10 ( V_92 , & V_59 -> V_90 [ 3 ] ) ;
V_46 |= F_10 ( V_92 , & V_59 -> V_90 [ 4 ] ) ;
V_46 |= F_10 ( V_92 , & V_59 -> V_90 [ 5 ] ) ;
V_46 |= F_10 ( V_92 , & V_59 -> V_90 [ 6 ] ) ;
V_46 |= F_10 ( ( V_93 ) , & V_59 -> V_90 [ 7 ] ) ;
V_32 -> V_50 = ( unsigned long ) V_59 -> V_90 ;
F_39 ( V_32 -> V_50 , V_32 -> V_50 + sizeof( V_59 -> V_90 ) ) ;
}
if ( V_46 )
goto V_82;
V_32 -> V_32 [ 15 ] = ( unsigned long ) V_59 ;
V_32 -> V_32 [ 4 ] = signal ;
V_32 -> V_32 [ 5 ] = 0 ;
V_32 -> V_32 [ 6 ] = ( unsigned long ) & V_59 -> V_34 ;
if ( V_8 -> V_94 & V_95 ) {
struct V_96 T_4 * V_97 =
(struct V_96 T_4 * ) V_75 -> V_23 . V_24 ;
F_8 ( V_32 -> V_52 , & V_97 -> V_98 ) ;
F_8 ( V_32 -> V_32 [ 12 ] , & V_97 -> V_99 ) ;
} else
V_32 -> V_52 = ( unsigned long ) V_75 -> V_23 . V_24 ;
F_40 ( V_100 ) ;
F_41 ( L_1 ,
V_8 -> V_101 , F_42 ( V_8 ) , V_59 , V_32 -> V_52 , V_32 -> V_50 ) ;
return 0 ;
V_82:
F_43 ( V_14 , V_8 ) ;
return - V_26 ;
}
static int F_44 ( int V_14 , struct V_18 * V_75 , T_8 * V_102 ,
T_3 * V_60 , struct V_5 * V_32 )
{
struct V_70 T_4 * V_59 ;
int V_46 = 0 ;
int signal ;
V_59 = F_32 ( V_75 , V_32 -> V_32 [ 15 ] , sizeof( * V_59 ) ) ;
if ( ! F_7 ( V_29 , V_59 , sizeof( * V_59 ) ) )
goto V_82;
signal = F_27 () -> V_83
&& F_27 () -> V_83 -> V_84
&& V_14 < 32
? F_27 () -> V_83 -> V_84 [ V_14 ]
: V_14 ;
V_46 |= F_45 ( & V_59 -> V_102 , V_102 ) ;
V_46 |= F_10 ( 0 , & V_59 -> V_71 . V_103 ) ;
V_46 |= F_10 ( NULL , & V_59 -> V_71 . V_104 ) ;
V_46 |= F_10 ( ( void * ) V_8 -> V_79 ,
& V_59 -> V_71 . V_74 . V_105 ) ;
V_46 |= F_10 ( F_33 ( V_32 -> V_32 [ 15 ] ) ,
& V_59 -> V_71 . V_74 . V_106 ) ;
V_46 |= F_10 ( V_8 -> V_80 , & V_59 -> V_71 . V_74 . V_107 ) ;
V_46 |= F_31 ( & V_59 -> V_71 . V_73 ,
V_32 , V_60 -> V_14 [ 0 ] ) ;
V_46 |= F_21 ( & V_59 -> V_71 . V_72 , V_60 , sizeof( * V_60 ) ) ;
if ( V_75 -> V_23 . V_27 & V_85 ) {
V_32 -> V_50 = ( unsigned long ) V_75 -> V_23 . V_25 ;
#ifdef F_35
} else if ( F_36 ( V_8 -> V_86 -> V_87 . V_88 ) ) {
V_32 -> V_50 = F_37 ( & V_108 ) ;
#endif
} else {
V_46 |= F_10 ( F_38 ( 7 ) , & V_59 -> V_90 [ 0 ] ) ;
V_46 |= F_10 ( V_91 , & V_59 -> V_90 [ 1 ] ) ;
V_46 |= F_10 ( V_92 , & V_59 -> V_90 [ 2 ] ) ;
V_46 |= F_10 ( V_92 , & V_59 -> V_90 [ 3 ] ) ;
V_46 |= F_10 ( V_92 , & V_59 -> V_90 [ 4 ] ) ;
V_46 |= F_10 ( V_92 , & V_59 -> V_90 [ 5 ] ) ;
V_46 |= F_10 ( V_92 , & V_59 -> V_90 [ 6 ] ) ;
V_46 |= F_10 ( ( V_109 ) , & V_59 -> V_90 [ 7 ] ) ;
V_32 -> V_50 = ( unsigned long ) V_59 -> V_90 ;
F_39 ( V_32 -> V_50 , V_32 -> V_50 + sizeof( V_59 -> V_90 ) ) ;
}
if ( V_46 )
goto V_82;
V_32 -> V_32 [ 15 ] = ( unsigned long ) V_59 ;
V_32 -> V_32 [ 4 ] = signal ;
V_32 -> V_32 [ 5 ] = ( unsigned long ) & V_59 -> V_102 ;
V_32 -> V_32 [ 6 ] = ( unsigned long ) & V_59 -> V_71 ;
if ( V_8 -> V_94 & V_95 ) {
struct V_96 T_4 * V_97 =
(struct V_96 T_4 * ) V_75 -> V_23 . V_24 ;
F_8 ( V_32 -> V_52 , & V_97 -> V_98 ) ;
F_8 ( V_32 -> V_32 [ 12 ] , & V_97 -> V_99 ) ;
} else
V_32 -> V_52 = ( unsigned long ) V_75 -> V_23 . V_24 ;
F_40 ( V_100 ) ;
F_41 ( L_1 ,
V_8 -> V_101 , F_42 ( V_8 ) , V_59 , V_32 -> V_52 , V_32 -> V_50 ) ;
return 0 ;
V_82:
F_43 ( V_14 , V_8 ) ;
return - V_26 ;
}
static inline void
F_46 ( unsigned long V_110 , struct V_5 * V_32 ,
struct V_111 * V_23 )
{
if ( V_32 -> V_55 < 0 )
return;
switch ( V_32 -> V_32 [ 0 ] ) {
case - V_112 :
case - V_13 :
V_113:
V_32 -> V_32 [ 0 ] = - V_114 ;
break;
case - V_115 :
if ( ! ( V_23 -> V_27 & V_116 ) )
goto V_113;
case - V_117 :
V_32 -> V_32 [ 0 ] = V_110 ;
V_32 -> V_52 -= F_47 ( F_48 ( V_32 -> V_52 - 4 ) ) ;
break;
}
}
static int
F_49 ( unsigned long V_14 , struct V_18 * V_75 , T_8 * V_102 ,
T_3 * V_118 , struct V_5 * V_32 , unsigned int V_110 )
{
int V_21 ;
if ( V_75 -> V_23 . V_27 & V_119 )
V_21 = F_44 ( V_14 , V_75 , V_102 , V_118 , V_32 ) ;
else
V_21 = F_34 ( V_14 , V_75 , V_118 , V_32 ) ;
if ( V_21 == 0 )
F_50 ( V_75 , V_14 ) ;
return V_21 ;
}
static void F_51 ( struct V_5 * V_32 , unsigned int V_110 )
{
T_8 V_102 ;
int V_120 ;
struct V_18 V_75 ;
T_3 * V_118 ;
if ( ! F_52 ( V_32 ) )
return;
if ( F_27 () -> V_121 & V_122 )
V_118 = & V_8 -> V_9 ;
else
V_118 = & V_8 -> V_7 ;
V_120 = F_53 ( & V_102 , & V_75 , V_32 , NULL ) ;
if ( V_120 > 0 ) {
F_46 ( V_110 , V_32 , & V_75 . V_23 ) ;
if ( F_49 ( V_120 , & V_75 , & V_102 , V_118 ,
V_32 , V_110 ) == 0 ) {
F_27 () -> V_121 &= ~ V_122 ;
F_54 ( V_120 , & V_102 , & V_75 , V_32 ,
F_55 ( V_123 ) ) ;
}
return;
}
if ( V_32 -> V_55 >= 0 ) {
if ( V_32 -> V_32 [ 0 ] == - V_13 ||
V_32 -> V_32 [ 0 ] == - V_115 ||
V_32 -> V_32 [ 0 ] == - V_117 ) {
V_32 -> V_32 [ 0 ] = V_110 ;
V_32 -> V_52 -= F_47 ( F_48 ( V_32 -> V_52 - 4 ) ) ;
} else if ( V_32 -> V_32 [ 0 ] == - V_112 ) {
V_32 -> V_52 -= F_47 ( F_48 ( V_32 -> V_52 - 4 ) ) ;
V_32 -> V_32 [ 3 ] = V_124 ;
}
}
if ( F_27 () -> V_121 & V_122 ) {
F_27 () -> V_121 &= ~ V_122 ;
F_56 ( V_125 , & V_8 -> V_9 , NULL ) ;
}
}
T_1 void F_57 ( struct V_5 * V_32 , unsigned int V_110 ,
unsigned long V_126 )
{
if ( V_126 & V_127 )
F_51 ( V_32 , V_110 ) ;
if ( V_126 & V_128 ) {
F_58 ( V_129 ) ;
F_59 ( V_32 ) ;
if ( V_8 -> V_130 )
F_60 () ;
}
}

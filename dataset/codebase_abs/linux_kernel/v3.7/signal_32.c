T_1 int
F_1 ( T_2 V_1 )
{
T_3 V_2 ;
F_2 ( & V_2 , V_1 ) ;
return F_3 ( & V_2 ) ;
}
T_1 int
F_4 ( int V_3 , const struct V_4 T_4 * V_5 ,
struct V_4 T_4 * V_6 )
{
struct V_7 V_8 , V_9 ;
int V_10 ;
if ( V_5 ) {
T_2 V_1 ;
if ( ! F_5 ( V_11 , V_5 , sizeof( * V_5 ) ) ||
F_6 ( V_8 . V_12 . V_13 , & V_5 -> V_13 ) ||
F_6 ( V_8 . V_12 . V_14 , & V_5 -> V_14 ) ||
F_6 ( V_8 . V_12 . V_15 , & V_5 -> V_15 ) ||
F_6 ( V_1 , & V_5 -> V_16 ) )
return - V_17 ;
F_2 ( & V_8 . V_12 . V_16 , V_1 ) ;
}
V_10 = F_7 ( V_3 , V_5 ? & V_8 : NULL , V_6 ? & V_9 : NULL ) ;
if ( ! V_10 && V_6 ) {
if ( ! F_5 ( V_18 , V_6 , sizeof( * V_6 ) ) ||
F_8 ( V_9 . V_12 . V_13 , & V_6 -> V_13 ) ||
F_8 ( V_9 . V_12 . V_14 , & V_6 -> V_14 ) ||
F_8 ( V_9 . V_12 . V_15 , & V_6 -> V_15 ) ||
F_8 ( V_9 . V_12 . V_16 . V_3 [ 0 ] , & V_6 -> V_16 ) )
return - V_17 ;
}
return V_10 ;
}
T_1 int
F_9 ( const T_5 T_4 * V_19 , T_5 T_4 * V_20 ,
unsigned long V_21 , unsigned long V_22 ,
struct V_23 V_24 )
{
struct V_23 * V_25 = F_10 ( & V_24 , 0 ) ;
return F_11 ( V_19 , V_20 , V_25 -> V_25 [ 15 ] ) ;
}
static inline int F_12 ( struct V_26 T_4 * V_27 )
{
struct V_28 * V_29 = V_30 ;
if ( ! ( V_31 . V_32 & V_33 ) )
return 0 ;
F_13 () ;
return F_14 ( & V_29 -> V_34 . V_35 -> V_36 , & V_27 -> V_37 [ 0 ] ,
sizeof( long ) * ( 16 * 2 + 2 ) ) ;
}
static inline int F_15 ( struct V_26 T_4 * V_27 ,
struct V_23 * V_25 )
{
struct V_28 * V_29 = V_30 ;
if ( ! ( V_31 . V_32 & V_33 ) )
return 0 ;
if ( ! F_16 () )
return F_8 ( 0 , & V_27 -> V_38 ) ;
if ( F_8 ( 1 , & V_27 -> V_38 ) )
return - V_17 ;
F_17 () ;
F_18 ( V_29 , V_25 ) ;
return F_19 ( & V_27 -> V_37 [ 0 ] , & V_29 -> V_34 . V_35 -> V_36 ,
sizeof( long ) * ( 16 * 2 + 2 ) ) ;
}
static int
F_20 ( struct V_23 * V_25 , struct V_26 T_4 * V_27 , int * V_39 )
{
unsigned int V_40 = 0 ;
#define F_21 ( T_6 ) err |= __get_user(regs->x, &sc->sc_##x)
F_21 ( V_25 [ 1 ] ) ;
F_21 ( V_25 [ 2 ] ) ; F_21 ( V_25 [ 3 ] ) ;
F_21 ( V_25 [ 4 ] ) ; F_21 ( V_25 [ 5 ] ) ;
F_21 ( V_25 [ 6 ] ) ; F_21 ( V_25 [ 7 ] ) ;
F_21 ( V_25 [ 8 ] ) ; F_21 ( V_25 [ 9 ] ) ;
F_21 ( V_25 [ 10 ] ) ; F_21 ( V_25 [ 11 ] ) ;
F_21 ( V_25 [ 12 ] ) ; F_21 ( V_25 [ 13 ] ) ;
F_21 ( V_25 [ 14 ] ) ; F_21 ( V_25 [ 15 ] ) ;
F_21 ( V_41 ) ; F_21 ( V_42 ) ;
F_21 ( V_43 ) ; F_21 ( V_44 ) ;
F_21 ( V_45 ) ; F_21 ( V_46 ) ;
#undef F_21
#ifdef F_22
if ( V_31 . V_32 & V_33 ) {
int V_47 ;
struct V_28 * V_29 = V_30 ;
V_25 -> V_45 |= V_48 ;
F_23 ( V_29 , V_25 ) ;
F_17 () ;
V_40 |= F_6 ( V_47 , & V_27 -> V_38 ) ;
if ( V_47 )
V_40 |= F_12 ( V_27 ) ;
}
#endif
V_25 -> V_49 = - 1 ;
V_40 |= F_6 ( * V_39 , & V_27 -> V_50 [ 0 ] ) ;
return V_40 ;
}
T_1 int F_24 ( unsigned long V_51 , unsigned long V_52 ,
unsigned long V_21 , unsigned long V_22 ,
struct V_23 V_24 )
{
struct V_23 * V_25 = F_10 ( & V_24 , 0 ) ;
struct V_53 T_4 * V_54 = (struct V_53 T_4 * ) V_25 -> V_25 [ 15 ] ;
T_3 V_55 ;
int V_56 ;
F_25 () -> V_57 . V_58 = V_59 ;
if ( ! F_5 ( V_11 , V_54 , sizeof( * V_54 ) ) )
goto V_60;
if ( F_6 ( V_55 . V_3 [ 0 ] , & V_54 -> V_27 . V_61 )
|| ( V_62 > 1
&& F_14 ( & V_55 . V_3 [ 1 ] , & V_54 -> V_63 ,
sizeof( V_54 -> V_63 ) ) ) )
goto V_60;
F_26 ( & V_55 ) ;
if ( F_20 ( V_25 , & V_54 -> V_27 , & V_56 ) )
goto V_60;
return V_56 ;
V_60:
F_27 ( V_64 , V_30 ) ;
return 0 ;
}
T_1 int F_28 ( unsigned long V_51 , unsigned long V_52 ,
unsigned long V_21 , unsigned long V_22 ,
struct V_23 V_24 )
{
struct V_23 * V_25 = F_10 ( & V_24 , 0 ) ;
struct V_65 T_4 * V_54 = (struct V_65 T_4 * ) V_25 -> V_25 [ 15 ] ;
T_3 V_55 ;
int V_56 ;
F_25 () -> V_57 . V_58 = V_59 ;
if ( ! F_5 ( V_11 , V_54 , sizeof( * V_54 ) ) )
goto V_60;
if ( F_14 ( & V_55 , & V_54 -> V_66 . V_67 , sizeof( V_55 ) ) )
goto V_60;
F_26 ( & V_55 ) ;
if ( F_20 ( V_25 , & V_54 -> V_66 . V_68 , & V_56 ) )
goto V_60;
if ( F_11 ( & V_54 -> V_66 . V_69 , NULL ,
V_25 -> V_25 [ 15 ] ) == - V_17 )
goto V_60;
return V_56 ;
V_60:
F_27 ( V_64 , V_30 ) ;
return 0 ;
}
static int
F_29 ( struct V_26 T_4 * V_27 , struct V_23 * V_25 ,
unsigned long V_1 )
{
int V_40 = 0 ;
#define F_21 ( T_6 ) err |= __put_user(regs->x, &sc->sc_##x)
F_21 ( V_25 [ 0 ] ) ; F_21 ( V_25 [ 1 ] ) ;
F_21 ( V_25 [ 2 ] ) ; F_21 ( V_25 [ 3 ] ) ;
F_21 ( V_25 [ 4 ] ) ; F_21 ( V_25 [ 5 ] ) ;
F_21 ( V_25 [ 6 ] ) ; F_21 ( V_25 [ 7 ] ) ;
F_21 ( V_25 [ 8 ] ) ; F_21 ( V_25 [ 9 ] ) ;
F_21 ( V_25 [ 10 ] ) ; F_21 ( V_25 [ 11 ] ) ;
F_21 ( V_25 [ 12 ] ) ; F_21 ( V_25 [ 13 ] ) ;
F_21 ( V_25 [ 14 ] ) ; F_21 ( V_25 [ 15 ] ) ;
F_21 ( V_41 ) ; F_21 ( V_42 ) ;
F_21 ( V_43 ) ; F_21 ( V_44 ) ;
F_21 ( V_45 ) ; F_21 ( V_46 ) ;
#undef F_21
#ifdef F_22
V_40 |= F_15 ( V_27 , V_25 ) ;
#endif
V_40 |= F_8 ( V_1 , & V_27 -> V_61 ) ;
return V_40 ;
}
static inline void T_4 *
F_30 ( struct V_7 * V_70 , unsigned long V_71 , T_7 V_72 )
{
if ( V_70 -> V_12 . V_15 & V_73 ) {
if ( F_31 ( V_71 ) == 0 )
V_71 = V_30 -> V_74 + V_30 -> V_75 ;
}
return ( void T_4 * ) ( ( V_71 - ( V_72 + V_76 ) ) & - 8ul ) ;
}
static int F_32 ( int V_3 , struct V_7 * V_70 ,
T_3 * V_55 , struct V_23 * V_25 )
{
struct V_53 T_4 * V_54 ;
int V_40 = 0 ;
int signal ;
V_54 = F_30 ( V_70 , V_25 -> V_25 [ 15 ] , sizeof( * V_54 ) ) ;
if ( ! F_5 ( V_18 , V_54 , sizeof( * V_54 ) ) )
goto V_77;
signal = F_25 () -> V_78
&& F_25 () -> V_78 -> V_79
&& V_3 < 32
? F_25 () -> V_78 -> V_79 [ V_3 ]
: V_3 ;
V_40 |= F_29 ( & V_54 -> V_27 , V_25 , V_55 -> V_3 [ 0 ] ) ;
if ( V_62 > 1 )
V_40 |= F_19 ( V_54 -> V_63 , & V_55 -> V_3 [ 1 ] ,
sizeof( V_54 -> V_63 ) ) ;
if ( V_70 -> V_12 . V_15 & V_80 ) {
V_25 -> V_44 = ( unsigned long ) V_70 -> V_12 . V_14 ;
#ifdef F_33
} else if ( F_34 ( V_30 -> V_81 -> V_82 . V_83 ) ) {
V_25 -> V_44 = F_35 ( & V_84 ) ;
#endif
} else {
V_40 |= F_8 ( F_36 ( 7 ) , & V_54 -> V_85 [ 0 ] ) ;
V_40 |= F_8 ( V_86 , & V_54 -> V_85 [ 1 ] ) ;
V_40 |= F_8 ( V_87 , & V_54 -> V_85 [ 2 ] ) ;
V_40 |= F_8 ( V_87 , & V_54 -> V_85 [ 3 ] ) ;
V_40 |= F_8 ( V_87 , & V_54 -> V_85 [ 4 ] ) ;
V_40 |= F_8 ( V_87 , & V_54 -> V_85 [ 5 ] ) ;
V_40 |= F_8 ( V_87 , & V_54 -> V_85 [ 6 ] ) ;
V_40 |= F_8 ( ( V_88 ) , & V_54 -> V_85 [ 7 ] ) ;
V_25 -> V_44 = ( unsigned long ) V_54 -> V_85 ;
F_37 ( V_25 -> V_44 , V_25 -> V_44 + sizeof( V_54 -> V_85 ) ) ;
}
if ( V_40 )
goto V_77;
V_25 -> V_25 [ 15 ] = ( unsigned long ) V_54 ;
V_25 -> V_25 [ 4 ] = signal ;
V_25 -> V_25 [ 5 ] = 0 ;
V_25 -> V_25 [ 6 ] = ( unsigned long ) & V_54 -> V_27 ;
if ( V_30 -> V_89 & V_90 ) {
struct V_91 T_4 * V_92 =
(struct V_91 T_4 * ) V_70 -> V_12 . V_13 ;
V_40 |= F_6 ( V_25 -> V_46 , & V_92 -> V_93 ) ;
V_40 |= F_6 ( V_25 -> V_25 [ 12 ] , & V_92 -> V_94 ) ;
} else
V_25 -> V_46 = ( unsigned long ) V_70 -> V_12 . V_13 ;
if ( V_40 )
goto V_77;
F_38 ( V_95 ) ;
F_39 ( L_1 ,
V_30 -> V_96 , F_40 ( V_30 ) , V_54 , V_25 -> V_46 , V_25 -> V_44 ) ;
return 0 ;
V_77:
F_41 ( V_3 , V_30 ) ;
return - V_17 ;
}
static int F_42 ( int V_3 , struct V_7 * V_70 , T_8 * V_97 ,
T_3 * V_55 , struct V_23 * V_25 )
{
struct V_65 T_4 * V_54 ;
int V_40 = 0 ;
int signal ;
V_54 = F_30 ( V_70 , V_25 -> V_25 [ 15 ] , sizeof( * V_54 ) ) ;
if ( ! F_5 ( V_18 , V_54 , sizeof( * V_54 ) ) )
goto V_77;
signal = F_25 () -> V_78
&& F_25 () -> V_78 -> V_79
&& V_3 < 32
? F_25 () -> V_78 -> V_79 [ V_3 ]
: V_3 ;
V_40 |= F_43 ( & V_54 -> V_97 , V_97 ) ;
V_40 |= F_8 ( 0 , & V_54 -> V_66 . V_98 ) ;
V_40 |= F_8 ( NULL , & V_54 -> V_66 . V_99 ) ;
V_40 |= F_8 ( ( void * ) V_30 -> V_74 ,
& V_54 -> V_66 . V_69 . V_100 ) ;
V_40 |= F_8 ( F_31 ( V_25 -> V_25 [ 15 ] ) ,
& V_54 -> V_66 . V_69 . V_101 ) ;
V_40 |= F_8 ( V_30 -> V_75 , & V_54 -> V_66 . V_69 . V_102 ) ;
V_40 |= F_29 ( & V_54 -> V_66 . V_68 ,
V_25 , V_55 -> V_3 [ 0 ] ) ;
V_40 |= F_19 ( & V_54 -> V_66 . V_67 , V_55 , sizeof( * V_55 ) ) ;
if ( V_70 -> V_12 . V_15 & V_80 ) {
V_25 -> V_44 = ( unsigned long ) V_70 -> V_12 . V_14 ;
#ifdef F_33
} else if ( F_34 ( V_30 -> V_81 -> V_82 . V_83 ) ) {
V_25 -> V_44 = F_35 ( & V_103 ) ;
#endif
} else {
V_40 |= F_8 ( F_36 ( 7 ) , & V_54 -> V_85 [ 0 ] ) ;
V_40 |= F_8 ( V_86 , & V_54 -> V_85 [ 1 ] ) ;
V_40 |= F_8 ( V_87 , & V_54 -> V_85 [ 2 ] ) ;
V_40 |= F_8 ( V_87 , & V_54 -> V_85 [ 3 ] ) ;
V_40 |= F_8 ( V_87 , & V_54 -> V_85 [ 4 ] ) ;
V_40 |= F_8 ( V_87 , & V_54 -> V_85 [ 5 ] ) ;
V_40 |= F_8 ( V_87 , & V_54 -> V_85 [ 6 ] ) ;
V_40 |= F_8 ( ( V_104 ) , & V_54 -> V_85 [ 7 ] ) ;
V_25 -> V_44 = ( unsigned long ) V_54 -> V_85 ;
F_37 ( V_25 -> V_44 , V_25 -> V_44 + sizeof( V_54 -> V_85 ) ) ;
}
if ( V_40 )
goto V_77;
V_25 -> V_25 [ 15 ] = ( unsigned long ) V_54 ;
V_25 -> V_25 [ 4 ] = signal ;
V_25 -> V_25 [ 5 ] = ( unsigned long ) & V_54 -> V_97 ;
V_25 -> V_25 [ 6 ] = ( unsigned long ) & V_54 -> V_66 ;
if ( V_30 -> V_89 & V_90 ) {
struct V_91 T_4 * V_92 =
(struct V_91 T_4 * ) V_70 -> V_12 . V_13 ;
V_40 |= F_6 ( V_25 -> V_46 , & V_92 -> V_93 ) ;
V_40 |= F_6 ( V_25 -> V_25 [ 12 ] , & V_92 -> V_94 ) ;
} else
V_25 -> V_46 = ( unsigned long ) V_70 -> V_12 . V_13 ;
if ( V_40 )
goto V_77;
F_38 ( V_95 ) ;
F_39 ( L_1 ,
V_30 -> V_96 , F_40 ( V_30 ) , V_54 , V_25 -> V_46 , V_25 -> V_44 ) ;
return 0 ;
V_77:
F_41 ( V_3 , V_30 ) ;
return - V_17 ;
}
static inline void
F_44 ( unsigned long V_105 , struct V_23 * V_25 ,
struct V_106 * V_12 )
{
if ( V_25 -> V_49 < 0 )
return;
switch ( V_25 -> V_25 [ 0 ] ) {
case - V_107 :
case - V_108 :
V_109:
V_25 -> V_25 [ 0 ] = - V_110 ;
break;
case - V_111 :
if ( ! ( V_12 -> V_15 & V_112 ) )
goto V_109;
case - V_113 :
V_25 -> V_25 [ 0 ] = V_105 ;
V_25 -> V_46 -= F_45 ( F_46 ( V_25 -> V_46 - 4 ) ) ;
break;
}
}
static void
F_47 ( unsigned long V_3 , struct V_7 * V_70 , T_8 * V_97 ,
struct V_23 * V_25 , unsigned int V_105 )
{
T_3 * V_114 = F_48 () ;
int V_10 ;
if ( V_70 -> V_12 . V_15 & V_115 )
V_10 = F_42 ( V_3 , V_70 , V_97 , V_114 , V_25 ) ;
else
V_10 = F_32 ( V_3 , V_70 , V_114 , V_25 ) ;
if ( V_10 )
return;
F_49 ( V_3 , V_97 , V_70 , V_25 ,
F_50 ( V_116 ) ) ;
}
static void F_51 ( struct V_23 * V_25 , unsigned int V_105 )
{
T_8 V_97 ;
int V_117 ;
struct V_7 V_70 ;
if ( ! F_52 ( V_25 ) )
return;
V_117 = F_53 ( & V_97 , & V_70 , V_25 , NULL ) ;
if ( V_117 > 0 ) {
F_44 ( V_105 , V_25 , & V_70 . V_12 ) ;
F_47 ( V_117 , & V_70 , & V_97 , V_25 , V_105 ) ;
return;
}
if ( V_25 -> V_49 >= 0 ) {
if ( V_25 -> V_25 [ 0 ] == - V_108 ||
V_25 -> V_25 [ 0 ] == - V_111 ||
V_25 -> V_25 [ 0 ] == - V_113 ) {
V_25 -> V_25 [ 0 ] = V_105 ;
V_25 -> V_46 -= F_45 ( F_46 ( V_25 -> V_46 - 4 ) ) ;
} else if ( V_25 -> V_25 [ 0 ] == - V_107 ) {
V_25 -> V_46 -= F_45 ( F_46 ( V_25 -> V_46 - 4 ) ) ;
V_25 -> V_25 [ 3 ] = V_118 ;
}
}
F_54 () ;
}
T_1 void F_55 ( struct V_23 * V_25 , unsigned int V_105 ,
unsigned long V_119 )
{
if ( V_119 & V_120 )
F_51 ( V_25 , V_105 ) ;
if ( V_119 & V_121 ) {
F_56 ( V_122 ) ;
F_57 ( V_25 ) ;
}
}

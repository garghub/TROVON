static inline int F_1 ( struct V_1 T_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
if ( ! ( V_6 . V_7 & V_8 ) )
return 0 ;
F_2 () ;
return F_3 ( & V_4 -> V_9 . V_10 -> V_11 , & V_2 -> V_12 [ 0 ] ,
sizeof( long ) * ( 16 * 2 + 2 ) ) ;
}
static inline int F_4 ( struct V_1 T_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_3 * V_4 = V_5 ;
if ( ! ( V_6 . V_7 & V_8 ) )
return 0 ;
if ( ! F_5 () )
return F_6 ( 0 , & V_2 -> V_15 ) ;
if ( F_6 ( 1 , & V_2 -> V_15 ) )
return - V_16 ;
F_7 () ;
F_8 ( V_4 , V_14 ) ;
return F_9 ( & V_2 -> V_12 [ 0 ] , & V_4 -> V_9 . V_10 -> V_11 ,
sizeof( long ) * ( 16 * 2 + 2 ) ) ;
}
static int
F_10 ( struct V_13 * V_14 , struct V_1 T_1 * V_2 , int * V_17 )
{
unsigned int V_18 = 0 ;
#define F_11 ( T_2 ) err |= __get_user(regs->x, &sc->sc_##x)
F_11 ( V_14 [ 1 ] ) ;
F_11 ( V_14 [ 2 ] ) ; F_11 ( V_14 [ 3 ] ) ;
F_11 ( V_14 [ 4 ] ) ; F_11 ( V_14 [ 5 ] ) ;
F_11 ( V_14 [ 6 ] ) ; F_11 ( V_14 [ 7 ] ) ;
F_11 ( V_14 [ 8 ] ) ; F_11 ( V_14 [ 9 ] ) ;
F_11 ( V_14 [ 10 ] ) ; F_11 ( V_14 [ 11 ] ) ;
F_11 ( V_14 [ 12 ] ) ; F_11 ( V_14 [ 13 ] ) ;
F_11 ( V_14 [ 14 ] ) ; F_11 ( V_14 [ 15 ] ) ;
F_11 ( V_19 ) ; F_11 ( V_20 ) ;
F_11 ( V_21 ) ; F_11 ( V_22 ) ;
F_11 ( V_23 ) ; F_11 ( V_24 ) ;
#undef F_11
#ifdef F_12
if ( V_6 . V_7 & V_8 ) {
int V_25 ;
struct V_3 * V_4 = V_5 ;
V_14 -> V_23 |= V_26 ;
F_13 ( V_4 , V_14 ) ;
F_7 () ;
V_18 |= F_14 ( V_25 , & V_2 -> V_15 ) ;
if ( V_25 )
V_18 |= F_1 ( V_2 ) ;
}
#endif
V_14 -> V_27 = - 1 ;
V_18 |= F_14 ( * V_17 , & V_2 -> V_28 [ 0 ] ) ;
return V_18 ;
}
T_3 int F_15 ( unsigned long V_29 , unsigned long V_30 ,
unsigned long V_31 , unsigned long V_32 ,
struct V_13 V_33 )
{
struct V_13 * V_14 = F_16 ( & V_33 , 0 ) ;
struct V_34 T_1 * V_35 = (struct V_34 T_1 * ) V_14 -> V_14 [ 15 ] ;
T_4 V_36 ;
int V_37 ;
F_17 () -> V_38 . V_39 = V_40 ;
if ( ! F_18 ( V_41 , V_35 , sizeof( * V_35 ) ) )
goto V_42;
if ( F_14 ( V_36 . V_43 [ 0 ] , & V_35 -> V_2 . V_44 )
|| ( V_45 > 1
&& F_3 ( & V_36 . V_43 [ 1 ] , & V_35 -> V_46 ,
sizeof( V_35 -> V_46 ) ) ) )
goto V_42;
F_19 ( & V_36 ) ;
if ( F_10 ( V_14 , & V_35 -> V_2 , & V_37 ) )
goto V_42;
return V_37 ;
V_42:
F_20 ( V_47 , V_5 ) ;
return 0 ;
}
T_3 int F_21 ( unsigned long V_29 , unsigned long V_30 ,
unsigned long V_31 , unsigned long V_32 ,
struct V_13 V_33 )
{
struct V_13 * V_14 = F_16 ( & V_33 , 0 ) ;
struct V_48 T_1 * V_35 = (struct V_48 T_1 * ) V_14 -> V_14 [ 15 ] ;
T_4 V_36 ;
int V_37 ;
F_17 () -> V_38 . V_39 = V_40 ;
if ( ! F_18 ( V_41 , V_35 , sizeof( * V_35 ) ) )
goto V_42;
if ( F_3 ( & V_36 , & V_35 -> V_49 . V_50 , sizeof( V_36 ) ) )
goto V_42;
F_19 ( & V_36 ) ;
if ( F_10 ( V_14 , & V_35 -> V_49 . V_51 , & V_37 ) )
goto V_42;
if ( F_22 ( & V_35 -> V_49 . V_52 ) )
goto V_42;
return V_37 ;
V_42:
F_20 ( V_47 , V_5 ) ;
return 0 ;
}
static int
F_23 ( struct V_1 T_1 * V_2 , struct V_13 * V_14 ,
unsigned long V_53 )
{
int V_18 = 0 ;
#define F_11 ( T_2 ) err |= __put_user(regs->x, &sc->sc_##x)
F_11 ( V_14 [ 0 ] ) ; F_11 ( V_14 [ 1 ] ) ;
F_11 ( V_14 [ 2 ] ) ; F_11 ( V_14 [ 3 ] ) ;
F_11 ( V_14 [ 4 ] ) ; F_11 ( V_14 [ 5 ] ) ;
F_11 ( V_14 [ 6 ] ) ; F_11 ( V_14 [ 7 ] ) ;
F_11 ( V_14 [ 8 ] ) ; F_11 ( V_14 [ 9 ] ) ;
F_11 ( V_14 [ 10 ] ) ; F_11 ( V_14 [ 11 ] ) ;
F_11 ( V_14 [ 12 ] ) ; F_11 ( V_14 [ 13 ] ) ;
F_11 ( V_14 [ 14 ] ) ; F_11 ( V_14 [ 15 ] ) ;
F_11 ( V_19 ) ; F_11 ( V_20 ) ;
F_11 ( V_21 ) ; F_11 ( V_22 ) ;
F_11 ( V_23 ) ; F_11 ( V_24 ) ;
#undef F_11
#ifdef F_12
V_18 |= F_4 ( V_2 , V_14 ) ;
#endif
V_18 |= F_6 ( V_53 , & V_2 -> V_44 ) ;
return V_18 ;
}
static inline void T_1 *
F_24 ( struct V_54 * V_55 , unsigned long V_56 , T_5 V_57 )
{
if ( V_55 -> V_58 . V_59 & V_60 ) {
if ( F_25 ( V_56 ) == 0 )
V_56 = V_5 -> V_61 + V_5 -> V_62 ;
}
return ( void T_1 * ) ( ( V_56 - ( V_57 + V_63 ) ) & - 8ul ) ;
}
static int F_26 ( int V_43 , struct V_54 * V_55 ,
T_4 * V_36 , struct V_13 * V_14 )
{
struct V_34 T_1 * V_35 ;
int V_18 = 0 ;
int signal ;
V_35 = F_24 ( V_55 , V_14 -> V_14 [ 15 ] , sizeof( * V_35 ) ) ;
if ( ! F_18 ( V_64 , V_35 , sizeof( * V_35 ) ) )
goto V_65;
signal = F_17 () -> V_66
&& F_17 () -> V_66 -> V_67
&& V_43 < 32
? F_17 () -> V_66 -> V_67 [ V_43 ]
: V_43 ;
V_18 |= F_23 ( & V_35 -> V_2 , V_14 , V_36 -> V_43 [ 0 ] ) ;
if ( V_45 > 1 )
V_18 |= F_9 ( V_35 -> V_46 , & V_36 -> V_43 [ 1 ] ,
sizeof( V_35 -> V_46 ) ) ;
if ( V_55 -> V_58 . V_59 & V_68 ) {
V_14 -> V_22 = ( unsigned long ) V_55 -> V_58 . V_69 ;
#ifdef F_27
} else if ( F_28 ( V_5 -> V_70 -> V_71 . V_72 ) ) {
V_14 -> V_22 = F_29 ( & V_73 ) ;
#endif
} else {
V_18 |= F_6 ( F_30 ( 7 ) , & V_35 -> V_74 [ 0 ] ) ;
V_18 |= F_6 ( V_75 , & V_35 -> V_74 [ 1 ] ) ;
V_18 |= F_6 ( V_76 , & V_35 -> V_74 [ 2 ] ) ;
V_18 |= F_6 ( V_76 , & V_35 -> V_74 [ 3 ] ) ;
V_18 |= F_6 ( V_76 , & V_35 -> V_74 [ 4 ] ) ;
V_18 |= F_6 ( V_76 , & V_35 -> V_74 [ 5 ] ) ;
V_18 |= F_6 ( V_76 , & V_35 -> V_74 [ 6 ] ) ;
V_18 |= F_6 ( ( V_77 ) , & V_35 -> V_74 [ 7 ] ) ;
V_14 -> V_22 = ( unsigned long ) V_35 -> V_74 ;
F_31 ( V_14 -> V_22 , V_14 -> V_22 + sizeof( V_35 -> V_74 ) ) ;
}
if ( V_18 )
goto V_65;
V_14 -> V_14 [ 15 ] = ( unsigned long ) V_35 ;
V_14 -> V_14 [ 4 ] = signal ;
V_14 -> V_14 [ 5 ] = 0 ;
V_14 -> V_14 [ 6 ] = ( unsigned long ) & V_35 -> V_2 ;
if ( V_5 -> V_78 & V_79 ) {
struct V_80 T_1 * V_81 =
(struct V_80 T_1 * ) V_55 -> V_58 . V_82 ;
V_18 |= F_14 ( V_14 -> V_24 , & V_81 -> V_83 ) ;
V_18 |= F_14 ( V_14 -> V_14 [ 12 ] , & V_81 -> V_84 ) ;
} else
V_14 -> V_24 = ( unsigned long ) V_55 -> V_58 . V_82 ;
if ( V_18 )
goto V_65;
F_32 ( V_85 ) ;
F_33 ( L_1 ,
V_5 -> V_86 , F_34 ( V_5 ) , V_35 , V_14 -> V_24 , V_14 -> V_22 ) ;
return 0 ;
V_65:
F_35 ( V_43 , V_5 ) ;
return - V_16 ;
}
static int F_36 ( int V_43 , struct V_54 * V_55 , T_6 * V_87 ,
T_4 * V_36 , struct V_13 * V_14 )
{
struct V_48 T_1 * V_35 ;
int V_18 = 0 ;
int signal ;
V_35 = F_24 ( V_55 , V_14 -> V_14 [ 15 ] , sizeof( * V_35 ) ) ;
if ( ! F_18 ( V_64 , V_35 , sizeof( * V_35 ) ) )
goto V_65;
signal = F_17 () -> V_66
&& F_17 () -> V_66 -> V_67
&& V_43 < 32
? F_17 () -> V_66 -> V_67 [ V_43 ]
: V_43 ;
V_18 |= F_37 ( & V_35 -> V_87 , V_87 ) ;
V_18 |= F_6 ( 0 , & V_35 -> V_49 . V_88 ) ;
V_18 |= F_6 ( NULL , & V_35 -> V_49 . V_89 ) ;
V_18 |= F_38 ( & V_35 -> V_49 . V_52 , V_14 -> V_14 [ 15 ] ) ;
V_18 |= F_23 ( & V_35 -> V_49 . V_51 ,
V_14 , V_36 -> V_43 [ 0 ] ) ;
V_18 |= F_9 ( & V_35 -> V_49 . V_50 , V_36 , sizeof( * V_36 ) ) ;
if ( V_55 -> V_58 . V_59 & V_68 ) {
V_14 -> V_22 = ( unsigned long ) V_55 -> V_58 . V_69 ;
#ifdef F_27
} else if ( F_28 ( V_5 -> V_70 -> V_71 . V_72 ) ) {
V_14 -> V_22 = F_29 ( & V_90 ) ;
#endif
} else {
V_18 |= F_6 ( F_30 ( 7 ) , & V_35 -> V_74 [ 0 ] ) ;
V_18 |= F_6 ( V_75 , & V_35 -> V_74 [ 1 ] ) ;
V_18 |= F_6 ( V_76 , & V_35 -> V_74 [ 2 ] ) ;
V_18 |= F_6 ( V_76 , & V_35 -> V_74 [ 3 ] ) ;
V_18 |= F_6 ( V_76 , & V_35 -> V_74 [ 4 ] ) ;
V_18 |= F_6 ( V_76 , & V_35 -> V_74 [ 5 ] ) ;
V_18 |= F_6 ( V_76 , & V_35 -> V_74 [ 6 ] ) ;
V_18 |= F_6 ( ( V_91 ) , & V_35 -> V_74 [ 7 ] ) ;
V_14 -> V_22 = ( unsigned long ) V_35 -> V_74 ;
F_31 ( V_14 -> V_22 , V_14 -> V_22 + sizeof( V_35 -> V_74 ) ) ;
}
if ( V_18 )
goto V_65;
V_14 -> V_14 [ 15 ] = ( unsigned long ) V_35 ;
V_14 -> V_14 [ 4 ] = signal ;
V_14 -> V_14 [ 5 ] = ( unsigned long ) & V_35 -> V_87 ;
V_14 -> V_14 [ 6 ] = ( unsigned long ) & V_35 -> V_49 ;
if ( V_5 -> V_78 & V_79 ) {
struct V_80 T_1 * V_81 =
(struct V_80 T_1 * ) V_55 -> V_58 . V_82 ;
V_18 |= F_14 ( V_14 -> V_24 , & V_81 -> V_83 ) ;
V_18 |= F_14 ( V_14 -> V_14 [ 12 ] , & V_81 -> V_84 ) ;
} else
V_14 -> V_24 = ( unsigned long ) V_55 -> V_58 . V_82 ;
if ( V_18 )
goto V_65;
F_32 ( V_85 ) ;
F_33 ( L_1 ,
V_5 -> V_86 , F_34 ( V_5 ) , V_35 , V_14 -> V_24 , V_14 -> V_22 ) ;
return 0 ;
V_65:
F_35 ( V_43 , V_5 ) ;
return - V_16 ;
}
static inline void
F_39 ( unsigned long V_92 , struct V_13 * V_14 ,
struct V_93 * V_58 )
{
if ( V_14 -> V_27 < 0 )
return;
switch ( V_14 -> V_14 [ 0 ] ) {
case - V_94 :
case - V_95 :
V_96:
V_14 -> V_14 [ 0 ] = - V_97 ;
break;
case - V_98 :
if ( ! ( V_58 -> V_59 & V_99 ) )
goto V_96;
case - V_100 :
V_14 -> V_14 [ 0 ] = V_92 ;
V_14 -> V_24 -= F_40 ( F_41 ( V_14 -> V_24 - 4 ) ) ;
break;
}
}
static void
F_42 ( unsigned long V_43 , struct V_54 * V_55 , T_6 * V_87 ,
struct V_13 * V_14 , unsigned int V_92 )
{
T_4 * V_101 = F_43 () ;
int V_102 ;
if ( V_55 -> V_58 . V_59 & V_103 )
V_102 = F_36 ( V_43 , V_55 , V_87 , V_101 , V_14 ) ;
else
V_102 = F_26 ( V_43 , V_55 , V_101 , V_14 ) ;
if ( V_102 )
return;
F_44 ( V_43 , V_87 , V_55 , V_14 ,
F_45 ( V_104 ) ) ;
}
static void F_46 ( struct V_13 * V_14 , unsigned int V_92 )
{
T_6 V_87 ;
int V_105 ;
struct V_54 V_55 ;
if ( ! F_47 ( V_14 ) )
return;
V_105 = F_48 ( & V_87 , & V_55 , V_14 , NULL ) ;
if ( V_105 > 0 ) {
F_39 ( V_92 , V_14 , & V_55 . V_58 ) ;
F_42 ( V_105 , & V_55 , & V_87 , V_14 , V_92 ) ;
return;
}
if ( V_14 -> V_27 >= 0 ) {
if ( V_14 -> V_14 [ 0 ] == - V_95 ||
V_14 -> V_14 [ 0 ] == - V_98 ||
V_14 -> V_14 [ 0 ] == - V_100 ) {
V_14 -> V_14 [ 0 ] = V_92 ;
V_14 -> V_24 -= F_40 ( F_41 ( V_14 -> V_24 - 4 ) ) ;
} else if ( V_14 -> V_14 [ 0 ] == - V_94 ) {
V_14 -> V_24 -= F_40 ( F_41 ( V_14 -> V_24 - 4 ) ) ;
V_14 -> V_14 [ 3 ] = V_106 ;
}
}
F_49 () ;
}
T_3 void F_50 ( struct V_13 * V_14 , unsigned int V_92 ,
unsigned long V_107 )
{
if ( V_107 & V_108 )
F_46 ( V_14 , V_92 ) ;
if ( V_107 & V_109 ) {
F_51 ( V_110 ) ;
F_52 ( V_14 ) ;
}
}

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
T_3 int F_15 ( void )
{
struct V_13 * V_14 = F_16 () ;
struct V_29 T_1 * V_30 = (struct V_29 T_1 * ) V_14 -> V_14 [ 15 ] ;
T_4 V_31 ;
int V_32 ;
F_17 () -> V_33 . V_34 = V_35 ;
if ( ! F_18 ( V_36 , V_30 , sizeof( * V_30 ) ) )
goto V_37;
if ( F_14 ( V_31 . V_38 [ 0 ] , & V_30 -> V_2 . V_39 )
|| ( V_40 > 1
&& F_3 ( & V_31 . V_38 [ 1 ] , & V_30 -> V_41 ,
sizeof( V_30 -> V_41 ) ) ) )
goto V_37;
F_19 ( & V_31 ) ;
if ( F_10 ( V_14 , & V_30 -> V_2 , & V_32 ) )
goto V_37;
return V_32 ;
V_37:
F_20 ( V_42 , V_5 ) ;
return 0 ;
}
T_3 int F_21 ( void )
{
struct V_13 * V_14 = F_16 () ;
struct V_43 T_1 * V_30 = (struct V_43 T_1 * ) V_14 -> V_14 [ 15 ] ;
T_4 V_31 ;
int V_32 ;
F_17 () -> V_33 . V_34 = V_35 ;
if ( ! F_18 ( V_36 , V_30 , sizeof( * V_30 ) ) )
goto V_37;
if ( F_3 ( & V_31 , & V_30 -> V_44 . V_45 , sizeof( V_31 ) ) )
goto V_37;
F_19 ( & V_31 ) ;
if ( F_10 ( V_14 , & V_30 -> V_44 . V_46 , & V_32 ) )
goto V_37;
if ( F_22 ( & V_30 -> V_44 . V_47 ) )
goto V_37;
return V_32 ;
V_37:
F_20 ( V_42 , V_5 ) ;
return 0 ;
}
static int
F_23 ( struct V_1 T_1 * V_2 , struct V_13 * V_14 ,
unsigned long V_48 )
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
V_18 |= F_6 ( V_48 , & V_2 -> V_39 ) ;
return V_18 ;
}
static inline void T_1 *
F_24 ( struct V_49 * V_50 , unsigned long V_51 , T_5 V_52 )
{
if ( V_50 -> V_53 . V_54 & V_55 ) {
if ( F_25 ( V_51 ) == 0 )
V_51 = V_5 -> V_56 + V_5 -> V_57 ;
}
return ( void T_1 * ) ( ( V_51 - ( V_52 + V_58 ) ) & - 8ul ) ;
}
static int F_26 ( int V_38 , struct V_49 * V_50 ,
T_4 * V_31 , struct V_13 * V_14 )
{
struct V_29 T_1 * V_30 ;
int V_18 = 0 ;
int signal ;
V_30 = F_24 ( V_50 , V_14 -> V_14 [ 15 ] , sizeof( * V_30 ) ) ;
if ( ! F_18 ( V_59 , V_30 , sizeof( * V_30 ) ) )
goto V_60;
signal = F_17 () -> V_61
&& F_17 () -> V_61 -> V_62
&& V_38 < 32
? F_17 () -> V_61 -> V_62 [ V_38 ]
: V_38 ;
V_18 |= F_23 ( & V_30 -> V_2 , V_14 , V_31 -> V_38 [ 0 ] ) ;
if ( V_40 > 1 )
V_18 |= F_9 ( V_30 -> V_41 , & V_31 -> V_38 [ 1 ] ,
sizeof( V_30 -> V_41 ) ) ;
if ( V_50 -> V_53 . V_54 & V_63 ) {
V_14 -> V_22 = ( unsigned long ) V_50 -> V_53 . V_64 ;
#ifdef F_27
} else if ( F_28 ( V_5 -> V_65 -> V_66 . V_67 ) ) {
V_14 -> V_22 = F_29 ( & V_68 ) ;
#endif
} else {
V_18 |= F_6 ( F_30 ( 7 ) , & V_30 -> V_69 [ 0 ] ) ;
V_18 |= F_6 ( V_70 , & V_30 -> V_69 [ 1 ] ) ;
V_18 |= F_6 ( V_71 , & V_30 -> V_69 [ 2 ] ) ;
V_18 |= F_6 ( V_71 , & V_30 -> V_69 [ 3 ] ) ;
V_18 |= F_6 ( V_71 , & V_30 -> V_69 [ 4 ] ) ;
V_18 |= F_6 ( V_71 , & V_30 -> V_69 [ 5 ] ) ;
V_18 |= F_6 ( V_71 , & V_30 -> V_69 [ 6 ] ) ;
V_18 |= F_6 ( ( V_72 ) , & V_30 -> V_69 [ 7 ] ) ;
V_14 -> V_22 = ( unsigned long ) V_30 -> V_69 ;
F_31 ( V_14 -> V_22 , V_14 -> V_22 + sizeof( V_30 -> V_69 ) ) ;
}
if ( V_18 )
goto V_60;
V_14 -> V_14 [ 15 ] = ( unsigned long ) V_30 ;
V_14 -> V_14 [ 4 ] = signal ;
V_14 -> V_14 [ 5 ] = 0 ;
V_14 -> V_14 [ 6 ] = ( unsigned long ) & V_30 -> V_2 ;
if ( V_5 -> V_73 & V_74 ) {
struct V_75 T_1 * V_76 =
(struct V_75 T_1 * ) V_50 -> V_53 . V_77 ;
V_18 |= F_14 ( V_14 -> V_24 , & V_76 -> V_78 ) ;
V_18 |= F_14 ( V_14 -> V_14 [ 12 ] , & V_76 -> V_79 ) ;
} else
V_14 -> V_24 = ( unsigned long ) V_50 -> V_53 . V_77 ;
if ( V_18 )
goto V_60;
F_32 ( V_80 ) ;
F_33 ( L_1 ,
V_5 -> V_81 , F_34 ( V_5 ) , V_30 , V_14 -> V_24 , V_14 -> V_22 ) ;
return 0 ;
V_60:
F_35 ( V_38 , V_5 ) ;
return - V_16 ;
}
static int F_36 ( int V_38 , struct V_49 * V_50 , T_6 * V_82 ,
T_4 * V_31 , struct V_13 * V_14 )
{
struct V_43 T_1 * V_30 ;
int V_18 = 0 ;
int signal ;
V_30 = F_24 ( V_50 , V_14 -> V_14 [ 15 ] , sizeof( * V_30 ) ) ;
if ( ! F_18 ( V_59 , V_30 , sizeof( * V_30 ) ) )
goto V_60;
signal = F_17 () -> V_61
&& F_17 () -> V_61 -> V_62
&& V_38 < 32
? F_17 () -> V_61 -> V_62 [ V_38 ]
: V_38 ;
V_18 |= F_37 ( & V_30 -> V_82 , V_82 ) ;
V_18 |= F_6 ( 0 , & V_30 -> V_44 . V_83 ) ;
V_18 |= F_6 ( NULL , & V_30 -> V_44 . V_84 ) ;
V_18 |= F_38 ( & V_30 -> V_44 . V_47 , V_14 -> V_14 [ 15 ] ) ;
V_18 |= F_23 ( & V_30 -> V_44 . V_46 ,
V_14 , V_31 -> V_38 [ 0 ] ) ;
V_18 |= F_9 ( & V_30 -> V_44 . V_45 , V_31 , sizeof( * V_31 ) ) ;
if ( V_50 -> V_53 . V_54 & V_63 ) {
V_14 -> V_22 = ( unsigned long ) V_50 -> V_53 . V_64 ;
#ifdef F_27
} else if ( F_28 ( V_5 -> V_65 -> V_66 . V_67 ) ) {
V_14 -> V_22 = F_29 ( & V_85 ) ;
#endif
} else {
V_18 |= F_6 ( F_30 ( 7 ) , & V_30 -> V_69 [ 0 ] ) ;
V_18 |= F_6 ( V_70 , & V_30 -> V_69 [ 1 ] ) ;
V_18 |= F_6 ( V_71 , & V_30 -> V_69 [ 2 ] ) ;
V_18 |= F_6 ( V_71 , & V_30 -> V_69 [ 3 ] ) ;
V_18 |= F_6 ( V_71 , & V_30 -> V_69 [ 4 ] ) ;
V_18 |= F_6 ( V_71 , & V_30 -> V_69 [ 5 ] ) ;
V_18 |= F_6 ( V_71 , & V_30 -> V_69 [ 6 ] ) ;
V_18 |= F_6 ( ( V_86 ) , & V_30 -> V_69 [ 7 ] ) ;
V_14 -> V_22 = ( unsigned long ) V_30 -> V_69 ;
F_31 ( V_14 -> V_22 , V_14 -> V_22 + sizeof( V_30 -> V_69 ) ) ;
}
if ( V_18 )
goto V_60;
V_14 -> V_14 [ 15 ] = ( unsigned long ) V_30 ;
V_14 -> V_14 [ 4 ] = signal ;
V_14 -> V_14 [ 5 ] = ( unsigned long ) & V_30 -> V_82 ;
V_14 -> V_14 [ 6 ] = ( unsigned long ) & V_30 -> V_44 ;
if ( V_5 -> V_73 & V_74 ) {
struct V_75 T_1 * V_76 =
(struct V_75 T_1 * ) V_50 -> V_53 . V_77 ;
V_18 |= F_14 ( V_14 -> V_24 , & V_76 -> V_78 ) ;
V_18 |= F_14 ( V_14 -> V_14 [ 12 ] , & V_76 -> V_79 ) ;
} else
V_14 -> V_24 = ( unsigned long ) V_50 -> V_53 . V_77 ;
if ( V_18 )
goto V_60;
F_32 ( V_80 ) ;
F_33 ( L_1 ,
V_5 -> V_81 , F_34 ( V_5 ) , V_30 , V_14 -> V_24 , V_14 -> V_22 ) ;
return 0 ;
V_60:
F_35 ( V_38 , V_5 ) ;
return - V_16 ;
}
static inline void
F_39 ( unsigned long V_87 , struct V_13 * V_14 ,
struct V_88 * V_53 )
{
if ( V_14 -> V_27 < 0 )
return;
switch ( V_14 -> V_14 [ 0 ] ) {
case - V_89 :
case - V_90 :
V_91:
V_14 -> V_14 [ 0 ] = - V_92 ;
break;
case - V_93 :
if ( ! ( V_53 -> V_54 & V_94 ) )
goto V_91;
case - V_95 :
V_14 -> V_14 [ 0 ] = V_87 ;
V_14 -> V_24 -= F_40 ( F_41 ( V_14 -> V_24 - 4 ) ) ;
break;
}
}
static void
F_42 ( unsigned long V_38 , struct V_49 * V_50 , T_6 * V_82 ,
struct V_13 * V_14 , unsigned int V_87 )
{
T_4 * V_96 = F_43 () ;
int V_97 ;
if ( V_50 -> V_53 . V_54 & V_98 )
V_97 = F_36 ( V_38 , V_50 , V_82 , V_96 , V_14 ) ;
else
V_97 = F_26 ( V_38 , V_50 , V_96 , V_14 ) ;
if ( V_97 )
return;
F_44 ( V_38 , V_82 , V_50 , V_14 ,
F_45 ( V_99 ) ) ;
}
static void F_46 ( struct V_13 * V_14 , unsigned int V_87 )
{
T_6 V_82 ;
int V_100 ;
struct V_49 V_50 ;
if ( ! F_47 ( V_14 ) )
return;
V_100 = F_48 ( & V_82 , & V_50 , V_14 , NULL ) ;
if ( V_100 > 0 ) {
F_39 ( V_87 , V_14 , & V_50 . V_53 ) ;
F_42 ( V_100 , & V_50 , & V_82 , V_14 , V_87 ) ;
return;
}
if ( V_14 -> V_27 >= 0 ) {
if ( V_14 -> V_14 [ 0 ] == - V_90 ||
V_14 -> V_14 [ 0 ] == - V_93 ||
V_14 -> V_14 [ 0 ] == - V_95 ) {
V_14 -> V_14 [ 0 ] = V_87 ;
V_14 -> V_24 -= F_40 ( F_41 ( V_14 -> V_24 - 4 ) ) ;
} else if ( V_14 -> V_14 [ 0 ] == - V_89 ) {
V_14 -> V_24 -= F_40 ( F_41 ( V_14 -> V_24 - 4 ) ) ;
V_14 -> V_14 [ 3 ] = V_101 ;
}
}
F_49 () ;
}
T_3 void F_50 ( struct V_13 * V_14 , unsigned int V_87 ,
unsigned long V_102 )
{
if ( V_102 & V_103 )
F_46 ( V_14 , V_87 ) ;
if ( V_102 & V_104 ) {
F_51 ( V_105 ) ;
F_52 ( V_14 ) ;
}
}

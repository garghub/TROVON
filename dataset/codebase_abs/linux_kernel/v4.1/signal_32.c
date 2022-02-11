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
V_5 -> V_33 . V_34 = V_35 ;
if ( ! F_17 ( V_36 , V_30 , sizeof( * V_30 ) ) )
goto V_37;
if ( F_14 ( V_31 . V_38 [ 0 ] , & V_30 -> V_2 . V_39 )
|| ( V_40 > 1
&& F_3 ( & V_31 . V_38 [ 1 ] , & V_30 -> V_41 ,
sizeof( V_30 -> V_41 ) ) ) )
goto V_37;
F_18 ( & V_31 ) ;
if ( F_10 ( V_14 , & V_30 -> V_2 , & V_32 ) )
goto V_37;
return V_32 ;
V_37:
F_19 ( V_42 , V_5 ) ;
return 0 ;
}
T_3 int F_20 ( void )
{
struct V_13 * V_14 = F_16 () ;
struct V_43 T_1 * V_30 = (struct V_43 T_1 * ) V_14 -> V_14 [ 15 ] ;
T_4 V_31 ;
int V_32 ;
V_5 -> V_33 . V_34 = V_35 ;
if ( ! F_17 ( V_36 , V_30 , sizeof( * V_30 ) ) )
goto V_37;
if ( F_3 ( & V_31 , & V_30 -> V_44 . V_45 , sizeof( V_31 ) ) )
goto V_37;
F_18 ( & V_31 ) ;
if ( F_10 ( V_14 , & V_30 -> V_44 . V_46 , & V_32 ) )
goto V_37;
if ( F_21 ( & V_30 -> V_44 . V_47 ) )
goto V_37;
return V_32 ;
V_37:
F_19 ( V_42 , V_5 ) ;
return 0 ;
}
static int
F_22 ( struct V_1 T_1 * V_2 , struct V_13 * V_14 ,
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
F_23 ( struct V_49 * V_50 , unsigned long V_51 , T_5 V_52 )
{
if ( V_50 -> V_53 . V_54 & V_55 ) {
if ( F_24 ( V_51 ) == 0 )
V_51 = V_5 -> V_56 + V_5 -> V_57 ;
}
return ( void T_1 * ) ( ( V_51 - ( V_52 + V_58 ) ) & - 8ul ) ;
}
static int F_25 ( struct V_59 * V_60 , T_4 * V_31 ,
struct V_13 * V_14 )
{
struct V_29 T_1 * V_30 ;
int V_18 = 0 , V_38 = V_60 -> V_38 ;
V_30 = F_23 ( & V_60 -> V_50 , V_14 -> V_14 [ 15 ] , sizeof( * V_30 ) ) ;
if ( ! F_17 ( V_61 , V_30 , sizeof( * V_30 ) ) )
return - V_16 ;
V_18 |= F_22 ( & V_30 -> V_2 , V_14 , V_31 -> V_38 [ 0 ] ) ;
if ( V_40 > 1 )
V_18 |= F_9 ( V_30 -> V_41 , & V_31 -> V_38 [ 1 ] ,
sizeof( V_30 -> V_41 ) ) ;
if ( V_60 -> V_50 . V_53 . V_54 & V_62 ) {
V_14 -> V_22 = ( unsigned long ) V_60 -> V_50 . V_53 . V_63 ;
#ifdef F_26
} else if ( F_27 ( V_5 -> V_64 -> V_65 . V_66 ) ) {
V_14 -> V_22 = F_28 ( & V_67 ) ;
#endif
} else {
V_18 |= F_6 ( F_29 ( 7 ) , & V_30 -> V_68 [ 0 ] ) ;
V_18 |= F_6 ( V_69 , & V_30 -> V_68 [ 1 ] ) ;
V_18 |= F_6 ( V_70 , & V_30 -> V_68 [ 2 ] ) ;
V_18 |= F_6 ( V_70 , & V_30 -> V_68 [ 3 ] ) ;
V_18 |= F_6 ( V_70 , & V_30 -> V_68 [ 4 ] ) ;
V_18 |= F_6 ( V_70 , & V_30 -> V_68 [ 5 ] ) ;
V_18 |= F_6 ( V_70 , & V_30 -> V_68 [ 6 ] ) ;
V_18 |= F_6 ( ( V_71 ) , & V_30 -> V_68 [ 7 ] ) ;
V_14 -> V_22 = ( unsigned long ) V_30 -> V_68 ;
F_30 ( V_14 -> V_22 , V_14 -> V_22 + sizeof( V_30 -> V_68 ) ) ;
}
if ( V_18 )
return - V_16 ;
V_14 -> V_14 [ 15 ] = ( unsigned long ) V_30 ;
V_14 -> V_14 [ 4 ] = V_38 ;
V_14 -> V_14 [ 5 ] = 0 ;
V_14 -> V_14 [ 6 ] = ( unsigned long ) & V_30 -> V_2 ;
if ( V_5 -> V_72 & V_73 ) {
struct V_74 T_1 * V_75 =
(struct V_74 T_1 * ) V_60 -> V_50 . V_53 . V_76 ;
V_18 |= F_14 ( V_14 -> V_24 , & V_75 -> V_77 ) ;
V_18 |= F_14 ( V_14 -> V_14 [ 12 ] , & V_75 -> V_78 ) ;
} else
V_14 -> V_24 = ( unsigned long ) V_60 -> V_50 . V_53 . V_76 ;
if ( V_18 )
return - V_16 ;
F_31 ( L_1 ,
V_5 -> V_79 , F_32 ( V_5 ) , V_30 , V_14 -> V_24 , V_14 -> V_22 ) ;
return 0 ;
}
static int F_33 ( struct V_59 * V_60 , T_4 * V_31 ,
struct V_13 * V_14 )
{
struct V_43 T_1 * V_30 ;
int V_18 = 0 , V_38 = V_60 -> V_38 ;
V_30 = F_23 ( & V_60 -> V_50 , V_14 -> V_14 [ 15 ] , sizeof( * V_30 ) ) ;
if ( ! F_17 ( V_61 , V_30 , sizeof( * V_30 ) ) )
return - V_16 ;
V_18 |= F_34 ( & V_30 -> V_80 , & V_60 -> V_80 ) ;
V_18 |= F_6 ( 0 , & V_30 -> V_44 . V_81 ) ;
V_18 |= F_6 ( NULL , & V_30 -> V_44 . V_82 ) ;
V_18 |= F_35 ( & V_30 -> V_44 . V_47 , V_14 -> V_14 [ 15 ] ) ;
V_18 |= F_22 ( & V_30 -> V_44 . V_46 ,
V_14 , V_31 -> V_38 [ 0 ] ) ;
V_18 |= F_9 ( & V_30 -> V_44 . V_45 , V_31 , sizeof( * V_31 ) ) ;
if ( V_60 -> V_50 . V_53 . V_54 & V_62 ) {
V_14 -> V_22 = ( unsigned long ) V_60 -> V_50 . V_53 . V_63 ;
#ifdef F_26
} else if ( F_27 ( V_5 -> V_64 -> V_65 . V_66 ) ) {
V_14 -> V_22 = F_28 ( & V_83 ) ;
#endif
} else {
V_18 |= F_6 ( F_29 ( 7 ) , & V_30 -> V_68 [ 0 ] ) ;
V_18 |= F_6 ( V_69 , & V_30 -> V_68 [ 1 ] ) ;
V_18 |= F_6 ( V_70 , & V_30 -> V_68 [ 2 ] ) ;
V_18 |= F_6 ( V_70 , & V_30 -> V_68 [ 3 ] ) ;
V_18 |= F_6 ( V_70 , & V_30 -> V_68 [ 4 ] ) ;
V_18 |= F_6 ( V_70 , & V_30 -> V_68 [ 5 ] ) ;
V_18 |= F_6 ( V_70 , & V_30 -> V_68 [ 6 ] ) ;
V_18 |= F_6 ( ( V_84 ) , & V_30 -> V_68 [ 7 ] ) ;
V_14 -> V_22 = ( unsigned long ) V_30 -> V_68 ;
F_30 ( V_14 -> V_22 , V_14 -> V_22 + sizeof( V_30 -> V_68 ) ) ;
}
if ( V_18 )
return - V_16 ;
V_14 -> V_14 [ 15 ] = ( unsigned long ) V_30 ;
V_14 -> V_14 [ 4 ] = V_38 ;
V_14 -> V_14 [ 5 ] = ( unsigned long ) & V_30 -> V_80 ;
V_14 -> V_14 [ 6 ] = ( unsigned long ) & V_30 -> V_44 ;
if ( V_5 -> V_72 & V_73 ) {
struct V_74 T_1 * V_75 =
(struct V_74 T_1 * ) V_60 -> V_50 . V_53 . V_76 ;
V_18 |= F_14 ( V_14 -> V_24 , & V_75 -> V_77 ) ;
V_18 |= F_14 ( V_14 -> V_14 [ 12 ] , & V_75 -> V_78 ) ;
} else
V_14 -> V_24 = ( unsigned long ) V_60 -> V_50 . V_53 . V_76 ;
if ( V_18 )
return - V_16 ;
F_31 ( L_1 ,
V_5 -> V_79 , F_32 ( V_5 ) , V_30 , V_14 -> V_24 , V_14 -> V_22 ) ;
return 0 ;
}
static inline void
F_36 ( unsigned long V_85 , struct V_13 * V_14 ,
struct V_86 * V_53 )
{
if ( V_14 -> V_27 < 0 )
return;
switch ( V_14 -> V_14 [ 0 ] ) {
case - V_87 :
case - V_88 :
V_89:
V_14 -> V_14 [ 0 ] = - V_90 ;
break;
case - V_91 :
if ( ! ( V_53 -> V_54 & V_92 ) )
goto V_89;
case - V_93 :
V_14 -> V_14 [ 0 ] = V_85 ;
V_14 -> V_24 -= F_37 ( F_38 ( V_14 -> V_24 - 4 ) ) ;
break;
}
}
static void
F_39 ( struct V_59 * V_60 , struct V_13 * V_14 , unsigned int V_85 )
{
T_4 * V_94 = F_40 () ;
int V_95 ;
if ( V_60 -> V_50 . V_53 . V_54 & V_96 )
V_95 = F_33 ( V_60 , V_94 , V_14 ) ;
else
V_95 = F_25 ( V_60 , V_94 , V_14 ) ;
F_41 ( V_95 , V_60 , F_42 ( V_97 ) ) ;
}
static void F_43 ( struct V_13 * V_14 , unsigned int V_85 )
{
struct V_59 V_60 ;
if ( ! F_44 ( V_14 ) )
return;
if ( F_45 ( & V_60 ) ) {
F_36 ( V_85 , V_14 , & V_60 . V_50 . V_53 ) ;
F_39 ( & V_60 , V_14 , V_85 ) ;
return;
}
if ( V_14 -> V_27 >= 0 ) {
if ( V_14 -> V_14 [ 0 ] == - V_88 ||
V_14 -> V_14 [ 0 ] == - V_91 ||
V_14 -> V_14 [ 0 ] == - V_93 ) {
V_14 -> V_14 [ 0 ] = V_85 ;
V_14 -> V_24 -= F_37 ( F_38 ( V_14 -> V_24 - 4 ) ) ;
} else if ( V_14 -> V_14 [ 0 ] == - V_87 ) {
V_14 -> V_24 -= F_37 ( F_38 ( V_14 -> V_24 - 4 ) ) ;
V_14 -> V_14 [ 3 ] = V_98 ;
}
}
F_46 () ;
}
T_3 void F_47 ( struct V_13 * V_14 , unsigned int V_85 ,
unsigned long V_99 )
{
if ( V_99 & V_100 )
F_43 ( V_14 , V_85 ) ;
if ( V_99 & V_101 ) {
F_48 ( V_102 ) ;
F_49 ( V_14 ) ;
}
}

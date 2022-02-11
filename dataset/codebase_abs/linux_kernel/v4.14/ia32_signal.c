static int F_1 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
unsigned int V_5 , V_6 = 0 ;
void T_1 * V_7 ;
T_2 V_8 ;
V_9 -> V_10 . V_11 = V_12 ;
F_2 {
F_3 ( V_13 ) ;
F_3 ( V_14 ) ;
F_3 ( V_15 ) ;
F_3 ( V_16 ) ;
F_4 ( V_17 ) ; F_4 ( V_18 ) ; F_4 ( V_19 ) ; F_4 ( V_20 ) ; F_4 ( V_21 ) ;
F_4 ( V_22 ) ; F_4 ( V_23 ) ; F_4 ( V_24 ) ; F_4 ( V_25 ) ;
F_5 ( V_26 ) ;
F_5 ( V_27 ) ;
F_6 ( V_5 , & V_4 -> V_28 ) ;
V_2 -> V_28 = ( V_2 -> V_28 & ~ V_29 ) | ( V_5 & V_29 ) ;
V_2 -> V_30 = - 1 ;
F_6 ( V_8 , & V_4 -> V_31 ) ;
V_7 = F_7 ( V_8 ) ;
} F_8 ( V_6 ) ;
V_6 |= F_9 ( V_7 , 1 ) ;
F_10 () ;
return V_6 ;
}
T_3 long F_11 ( void )
{
struct V_1 * V_2 = F_12 () ;
struct V_32 T_1 * V_33 = (struct V_32 T_1 * ) ( V_2 -> V_20 - 8 ) ;
T_4 V_34 ;
if ( ! F_13 ( V_35 , V_33 , sizeof( * V_33 ) ) )
goto V_36;
if ( F_14 ( V_34 . V_37 [ 0 ] , & V_33 -> V_4 . V_38 )
|| ( V_39 > 1
&& F_15 ( ( ( ( char * ) & V_34 . V_37 ) + 4 ) ,
& V_33 -> V_40 ,
sizeof( V_33 -> V_40 ) ) ) )
goto V_36;
F_16 ( & V_34 ) ;
if ( F_1 ( V_2 , & V_33 -> V_4 ) )
goto V_36;
return V_2 -> V_25 ;
V_36:
F_17 ( V_2 , V_33 , L_1 ) ;
return 0 ;
}
T_3 long F_18 ( void )
{
struct V_1 * V_2 = F_12 () ;
struct V_41 T_1 * V_33 ;
T_4 V_34 ;
V_33 = (struct V_41 T_1 * ) ( V_2 -> V_20 - 4 ) ;
if ( ! F_13 ( V_35 , V_33 , sizeof( * V_33 ) ) )
goto V_36;
if ( F_15 ( & V_34 , & V_33 -> V_42 . V_43 , sizeof( V_34 ) ) )
goto V_36;
F_16 ( & V_34 ) ;
if ( F_1 ( V_2 , & V_33 -> V_42 . V_44 ) )
goto V_36;
if ( F_19 ( & V_33 -> V_42 . V_45 ) )
goto V_36;
return V_2 -> V_25 ;
V_36:
F_17 ( V_2 , V_33 , L_2 ) ;
return 0 ;
}
static int F_20 ( struct V_3 T_1 * V_4 ,
void T_1 * V_31 ,
struct V_1 * V_2 , unsigned int V_46 )
{
int V_6 = 0 ;
F_21 {
F_22 ( F_23 ( V_13 ) , ( unsigned int T_1 * ) & V_4 -> V_13 ) ;
F_22 ( F_23 ( V_14 ) , ( unsigned int T_1 * ) & V_4 -> V_14 ) ;
F_22 ( F_23 ( V_15 ) , ( unsigned int T_1 * ) & V_4 -> V_15 ) ;
F_22 ( F_23 ( V_16 ) , ( unsigned int T_1 * ) & V_4 -> V_16 ) ;
F_22 ( V_2 -> V_17 , & V_4 -> V_17 ) ;
F_22 ( V_2 -> V_18 , & V_4 -> V_18 ) ;
F_22 ( V_2 -> V_19 , & V_4 -> V_19 ) ;
F_22 ( V_2 -> V_20 , & V_4 -> V_20 ) ;
F_22 ( V_2 -> V_21 , & V_4 -> V_21 ) ;
F_22 ( V_2 -> V_22 , & V_4 -> V_22 ) ;
F_22 ( V_2 -> V_23 , & V_4 -> V_23 ) ;
F_22 ( V_2 -> V_25 , & V_4 -> V_25 ) ;
F_22 ( V_9 -> V_47 . V_48 , & V_4 -> V_49 ) ;
F_22 ( V_9 -> V_47 . V_50 , & V_4 -> V_6 ) ;
F_22 ( V_2 -> V_24 , & V_4 -> V_24 ) ;
F_22 ( V_2 -> V_26 , ( unsigned int T_1 * ) & V_4 -> V_26 ) ;
F_22 ( V_2 -> V_28 , & V_4 -> V_28 ) ;
F_22 ( V_2 -> V_20 , & V_4 -> V_51 ) ;
F_22 ( V_2 -> V_27 , ( unsigned int T_1 * ) & V_4 -> V_27 ) ;
F_22 ( F_24 ( V_31 ) , & V_4 -> V_31 ) ;
F_22 ( V_46 , & V_4 -> V_38 ) ;
F_22 ( V_9 -> V_47 . V_52 , & V_4 -> V_52 ) ;
} F_25 ( V_6 ) ;
return V_6 ;
}
static void T_1 * F_26 ( struct V_53 * V_54 , struct V_1 * V_2 ,
T_5 V_55 ,
void T_1 * * V_31 )
{
struct V_56 * V_56 = & V_9 -> V_47 . V_56 ;
unsigned long V_20 ;
V_20 = V_2 -> V_20 ;
if ( V_54 -> V_57 . V_58 . V_59 & V_60 )
V_20 = F_27 ( V_20 , V_54 ) ;
else if ( V_2 -> V_27 != V_61 &&
! ( V_54 -> V_57 . V_58 . V_59 & V_62 ) &&
V_54 -> V_57 . V_58 . V_63 )
V_20 = ( unsigned long ) V_54 -> V_57 . V_58 . V_63 ;
if ( V_56 -> V_64 ) {
unsigned long V_65 , V_66 ;
V_20 = F_28 ( V_20 , 1 , & V_65 , & V_66 ) ;
* V_31 = (struct V_67 T_1 * ) V_20 ;
if ( F_29 ( * V_31 , ( void T_1 * ) V_65 ,
V_66 ) < 0 )
return ( void T_1 * ) - 1L ;
}
V_20 -= V_55 ;
V_20 = ( ( V_20 + 4 ) & - 16ul ) - 4 ;
return ( void T_1 * ) V_20 ;
}
int F_30 ( int V_37 , struct V_53 * V_54 ,
T_6 * V_34 , struct V_1 * V_2 )
{
struct V_32 T_1 * V_33 ;
void T_1 * V_68 ;
int V_6 = 0 ;
void T_1 * V_31 = NULL ;
static const struct {
T_7 V_69 ;
T_2 V_70 ;
T_7 V_71 ;
} V_72 ( ( V_73 ) ) V_74 = {
0xb858 ,
V_75 ,
0x80cd ,
} ;
V_33 = F_26 ( V_54 , V_2 , sizeof( * V_33 ) , & V_31 ) ;
if ( ! F_13 ( V_76 , V_33 , sizeof( * V_33 ) ) )
return - V_77 ;
if ( F_31 ( V_37 , & V_33 -> V_37 ) )
return - V_77 ;
if ( F_20 ( & V_33 -> V_4 , V_31 , V_2 , V_34 -> V_37 [ 0 ] ) )
return - V_77 ;
if ( V_39 > 1 ) {
if ( F_32 ( V_33 -> V_40 , & V_34 -> V_37 [ 1 ] ,
sizeof( V_33 -> V_40 ) ) )
return - V_77 ;
}
if ( V_54 -> V_57 . V_58 . V_59 & V_62 ) {
V_68 = V_54 -> V_57 . V_58 . V_63 ;
} else {
if ( V_9 -> V_78 -> V_79 . V_80 )
V_68 = V_9 -> V_78 -> V_79 . V_80 +
V_81 . V_82 ;
else
V_68 = & V_33 -> V_83 ;
}
F_21 {
F_22 ( F_24 ( V_68 ) , & V_33 -> V_84 ) ;
F_22 ( * ( ( V_85 * ) & V_74 ) , ( V_85 T_1 * ) V_33 -> V_83 ) ;
} F_25 ( V_6 ) ;
if ( V_6 )
return - V_77 ;
V_2 -> V_20 = ( unsigned long ) V_33 ;
V_2 -> V_24 = ( unsigned long ) V_54 -> V_57 . V_58 . V_86 ;
V_2 -> V_25 = V_37 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 = 0 ;
F_33 ( V_15 , V_61 ) ;
F_33 ( V_16 , V_61 ) ;
V_2 -> V_26 = V_87 ;
V_2 -> V_27 = V_61 ;
return 0 ;
}
int F_34 ( int V_37 , struct V_53 * V_54 ,
T_6 * V_34 , struct V_1 * V_2 )
{
struct V_41 T_1 * V_33 ;
void T_1 * V_68 ;
int V_6 = 0 ;
void T_1 * V_31 = NULL ;
static const struct {
T_8 V_88 ;
T_2 V_70 ;
T_7 V_71 ;
T_8 V_89 ;
} V_72 ( ( V_73 ) ) V_74 = {
0xb8 ,
V_90 ,
0x80cd ,
0 ,
} ;
V_33 = F_26 ( V_54 , V_2 , sizeof( * V_33 ) , & V_31 ) ;
if ( ! F_13 ( V_76 , V_33 , sizeof( * V_33 ) ) )
return - V_77 ;
F_21 {
F_22 ( V_37 , & V_33 -> V_37 ) ;
F_22 ( F_24 ( & V_33 -> V_91 ) , & V_33 -> V_92 ) ;
F_22 ( F_24 ( & V_33 -> V_42 ) , & V_33 -> V_93 ) ;
if ( F_35 ( V_94 ) )
F_22 ( V_95 , & V_33 -> V_42 . V_96 ) ;
else
F_22 ( 0 , & V_33 -> V_42 . V_96 ) ;
F_22 ( 0 , & V_33 -> V_42 . V_97 ) ;
F_36 ( & V_33 -> V_42 . V_45 , V_2 -> V_20 ) ;
if ( V_54 -> V_57 . V_58 . V_59 & V_62 )
V_68 = V_54 -> V_57 . V_58 . V_63 ;
else
V_68 = V_9 -> V_78 -> V_79 . V_80 +
V_81 . V_98 ;
F_22 ( F_24 ( V_68 ) , & V_33 -> V_84 ) ;
F_22 ( * ( ( V_85 * ) & V_74 ) , ( V_85 T_1 * ) V_33 -> V_83 ) ;
} F_25 ( V_6 ) ;
V_6 |= F_37 ( & V_33 -> V_91 , & V_54 -> V_91 , false ) ;
V_6 |= F_20 ( & V_33 -> V_42 . V_44 , V_31 ,
V_2 , V_34 -> V_37 [ 0 ] ) ;
V_6 |= F_32 ( & V_33 -> V_42 . V_43 , V_34 , sizeof( * V_34 ) ) ;
if ( V_6 )
return - V_77 ;
V_2 -> V_20 = ( unsigned long ) V_33 ;
V_2 -> V_24 = ( unsigned long ) V_54 -> V_57 . V_58 . V_86 ;
V_2 -> V_25 = V_37 ;
V_2 -> V_22 = ( unsigned long ) & V_33 -> V_91 ;
V_2 -> V_23 = ( unsigned long ) & V_33 -> V_42 ;
F_33 ( V_15 , V_61 ) ;
F_33 ( V_16 , V_61 ) ;
V_2 -> V_26 = V_87 ;
V_2 -> V_27 = V_61 ;
return 0 ;
}

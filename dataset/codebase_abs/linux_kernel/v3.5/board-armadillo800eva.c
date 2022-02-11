static int F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static void F_2 ( struct V_1 * V_2 ,
void T_1 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_5 ) {
F_4 ( V_7 -> V_8 ) ;
F_4 ( V_7 -> V_9 ) ;
F_4 ( V_7 -> V_10 ) ;
F_4 ( V_7 -> V_11 ) ;
F_4 ( V_7 -> V_12 ) ;
F_5 ( 0xd750 , V_13 ) ;
F_6 ( 1 ) ;
F_7 ( 0x0000000c , V_7 -> V_14 + V_15 ) ;
F_7 ( 0x00000008 , V_7 -> V_14 + V_15 ) ;
F_6 ( 10 ) ;
F_5 ( 0xd770 , V_13 ) ;
F_5 ( 0x4000 , V_4 + 0x102 ) ;
} else {
F_7 ( 0x0000010f , V_7 -> V_14 + V_15 ) ;
F_5 ( 0xd7c0 , V_13 ) ;
F_8 ( V_7 -> V_12 ) ;
F_8 ( V_7 -> V_11 ) ;
F_8 ( V_7 -> V_10 ) ;
F_8 ( V_7 -> V_9 ) ;
F_8 ( V_7 -> V_8 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( ! F_10 ( V_7 -> V_12 ) )
F_11 ( V_7 -> V_12 ) ;
if ( ! F_10 ( V_7 -> V_8 ) )
F_11 ( V_7 -> V_8 ) ;
if ( ! F_10 ( V_7 -> V_9 ) )
F_11 ( V_7 -> V_9 ) ;
if ( ! F_10 ( V_7 -> V_10 ) )
F_11 ( V_7 -> V_10 ) ;
if ( ! F_10 ( V_7 -> V_11 ) )
F_11 ( V_7 -> V_11 ) ;
if ( V_7 -> V_14 )
F_12 ( V_7 -> V_14 ) ;
V_7 -> V_12 = NULL ;
V_7 -> V_8 = NULL ;
V_7 -> V_9 = NULL ;
V_7 -> V_10 = NULL ;
V_7 -> V_11 = NULL ;
V_7 -> V_14 = NULL ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
V_7 -> V_12 = F_14 ( & V_2 -> V_16 , L_1 ) ;
V_7 -> V_8 = F_14 ( & V_2 -> V_16 , L_2 ) ;
V_7 -> V_9 = F_14 ( & V_2 -> V_16 , L_3 ) ;
V_7 -> V_11 = F_14 ( & V_2 -> V_16 , L_4 ) ;
V_7 -> V_10 = F_14 ( & V_2 -> V_16 , L_5 ) ;
V_7 -> V_14 = F_15 ( V_17 , 0x20000 ) ;
if ( F_10 ( V_7 -> V_12 ) ||
F_10 ( V_7 -> V_8 ) ||
F_10 ( V_7 -> V_9 ) ||
F_10 ( V_7 -> V_10 ) ||
F_10 ( V_7 -> V_11 ) ||
! V_7 -> V_14 ) {
F_16 ( & V_2 -> V_16 , L_6 ) ;
F_9 ( V_2 ) ;
return - V_18 ;
}
F_17 ( V_7 -> V_8 ,
F_18 ( F_19 ( V_7 -> V_8 ) ) ) ;
return 0 ;
}
static void T_2 F_20 ( void )
{
struct V_19 * system = F_14 ( NULL , L_7 ) ;
struct V_19 * V_20 = F_14 ( NULL , L_8 ) ;
struct V_19 * V_21 = F_14 ( NULL , L_9 ) ;
if ( F_10 ( system ) ||
F_10 ( V_20 ) ||
F_10 ( V_21 ) ) {
F_21 ( L_10 ) ;
goto V_22;
}
F_17 ( V_20 , 24000000 ) ;
F_22 ( V_21 , system ) ;
V_22:
if ( ! F_10 ( system ) )
F_11 ( system ) ;
if ( ! F_10 ( V_20 ) )
F_11 ( V_20 ) ;
if ( ! F_10 ( V_21 ) )
F_11 ( V_21 ) ;
}
static void T_2 F_23 ( void )
{
F_20 () ;
F_24 () ;
F_25 ( V_23 , NULL ) ;
F_25 ( V_24 , NULL ) ;
F_25 ( V_25 , NULL ) ;
F_25 ( V_26 , NULL ) ;
F_25 ( V_27 , NULL ) ;
F_25 ( V_28 , NULL ) ;
F_25 ( V_29 , NULL ) ;
F_25 ( V_30 , NULL ) ;
F_25 ( V_31 , NULL ) ;
F_25 ( V_32 , NULL ) ;
F_25 ( V_33 , NULL ) ;
F_25 ( V_34 , NULL ) ;
F_25 ( V_35 , NULL ) ;
F_25 ( V_36 , NULL ) ;
F_25 ( V_37 , NULL ) ;
F_25 ( V_38 , NULL ) ;
F_25 ( V_39 , NULL ) ;
F_25 ( V_40 , NULL ) ;
F_25 ( V_41 , NULL ) ;
F_25 ( V_42 , NULL ) ;
F_25 ( V_43 , NULL ) ;
F_25 ( V_44 , NULL ) ;
F_25 ( V_45 , NULL ) ;
F_25 ( V_46 , NULL ) ;
F_25 ( V_47 , NULL ) ;
F_25 ( V_48 , NULL ) ;
F_25 ( V_49 , NULL ) ;
F_25 ( V_50 , NULL ) ;
F_25 ( V_51 , NULL ) ;
F_25 ( V_52 , NULL ) ;
F_25 ( V_53 , NULL ) ;
F_25 ( V_54 , NULL ) ;
F_25 ( V_55 , NULL ) ;
F_26 ( V_55 , 1 ) ;
F_25 ( V_56 , NULL ) ;
F_26 ( V_56 , 0 ) ;
F_25 ( V_57 , NULL ) ;
F_25 ( V_58 , NULL ) ;
F_26 ( V_58 , 1 ) ;
F_25 ( V_59 , NULL ) ;
F_25 ( V_60 , NULL ) ;
F_25 ( V_61 , NULL ) ;
F_25 ( V_62 , NULL ) ;
F_25 ( V_63 , NULL ) ;
F_25 ( V_64 , NULL ) ;
F_25 ( V_65 , NULL ) ;
F_25 ( V_66 , NULL ) ;
F_25 ( V_67 , NULL ) ;
F_25 ( V_68 , NULL ) ;
F_25 ( V_69 , NULL ) ;
F_25 ( V_70 , NULL ) ;
F_25 ( V_71 , NULL ) ;
F_25 ( V_72 , NULL ) ;
F_25 ( V_73 , NULL ) ;
F_25 ( V_74 , NULL ) ;
F_25 ( V_75 , NULL ) ;
F_25 ( V_76 , NULL ) ;
F_25 ( V_77 , NULL ) ;
F_25 ( V_78 , NULL ) ;
F_26 ( V_78 , 1 ) ;
F_25 ( V_79 , NULL ) ;
F_27 ( V_79 ) ;
if ( F_28 ( V_79 ) ) {
} else {
F_25 ( V_80 , NULL ) ;
F_29 ( & V_81 ) ;
}
F_25 ( V_82 , NULL ) ;
F_25 ( V_83 , NULL ) ;
F_25 ( V_84 , NULL ) ;
F_25 ( V_85 , NULL ) ;
F_25 ( V_86 , NULL ) ;
F_25 ( V_87 , NULL ) ;
F_25 ( V_88 , NULL ) ;
F_25 ( V_89 , NULL ) ;
F_25 ( V_90 , NULL ) ;
F_25 ( V_91 , NULL ) ;
F_26 ( V_89 , 0 ) ;
F_26 ( V_90 , 1 ) ;
F_26 ( V_91 , 1 ) ;
F_25 ( V_92 , NULL ) ;
F_25 ( V_93 , NULL ) ;
F_25 ( V_94 , NULL ) ;
F_25 ( V_95 , NULL ) ;
F_25 ( V_96 , NULL ) ;
F_25 ( V_97 , NULL ) ;
F_25 ( V_98 , NULL ) ;
F_25 ( V_99 , NULL ) ;
F_25 ( V_100 , NULL ) ;
F_25 ( V_101 , NULL ) ;
F_25 ( V_102 , NULL ) ;
F_26 ( V_102 , 1 ) ;
F_25 ( V_103 , NULL ) ;
F_27 ( V_103 ) ;
if ( F_28 ( V_103 ) ) {
} else {
F_25 ( V_104 , NULL ) ;
F_25 ( V_105 , NULL ) ;
F_25 ( V_106 , NULL ) ;
F_25 ( V_107 , NULL ) ;
F_25 ( V_108 , NULL ) ;
F_25 ( V_109 , NULL ) ;
F_25 ( V_110 , NULL ) ;
F_25 ( V_111 , NULL ) ;
F_25 ( V_112 , NULL ) ;
F_26 ( V_112 , 1 ) ;
F_29 ( & V_113 ) ;
}
#ifdef F_30
F_31 ( F_32 ( 0xf0002000 ) , 0x40440000 , 0x82000fff ) ;
#endif
F_33 ( 0 , V_114 , F_34 ( V_114 ) ) ;
F_35 () ;
F_36 ( V_115 ,
F_34 ( V_115 ) ) ;
}
static void T_2 F_37 ( void )
{
F_38 ( V_116 | V_117 ) ;
F_39 () ;
}
static void T_2 F_40 ( void )
{
F_41 () ;
V_118 . V_119 = F_37 ;
}

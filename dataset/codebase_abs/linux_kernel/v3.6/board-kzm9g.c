static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return ! ( ( 1 << 7 ) & F_3 ( V_4 -> V_5 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( 0x8a0a , V_4 -> V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
return V_6 ;
}
static T_1 F_7 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_8 ( V_2 ) ;
F_5 ( F_3 ( V_4 -> V_9 ) | V_10 , V_4 -> V_9 ) ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_12 ;
F_5 ( V_13 | V_10 , V_4 -> V_9 ) ;
V_12 = F_10 ( V_14 , F_7 , V_15 ,
F_11 ( & V_2 -> V_16 ) , V_2 ) ;
if ( V_12 ) {
F_12 ( & V_2 -> V_16 , L_1 ) ;
return V_12 ;
}
F_5 ( V_13 | V_17 , V_4 -> V_9 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_13 | V_10 , V_4 -> V_9 ) ;
F_14 ( V_14 , V_2 ) ;
}
static int T_2 F_15 ( void )
{
struct V_18 * V_19 = F_16 ( 0 ) ;
struct V_20 V_21 ;
int V_22 , V_12 ;
T_3 V_23 [] = {
0x40 , 0x2a ,
0x43 , 0x3c ,
0x44 , 0x3c ,
0x45 , 0x3c ,
0x54 , 0x03 ,
0x51 , 0x00 ,
0x51 , 0x01 ,
0xff , 0x00 ,
0x43 , 0xf0 ,
0x44 , 0xf0 ,
0x45 , 0xf0 ,
} ;
if ( ! F_17 () )
return 0 ;
if ( ! V_19 )
return 0 ;
V_21 . V_24 = 0x40 ;
V_21 . V_25 = 2 ;
V_21 . V_26 = 0 ;
for ( V_22 = 0 ; V_22 < F_18 ( V_23 ) ; V_22 += 2 ) {
V_21 . V_27 = V_23 + V_22 ;
if ( 0xff == V_21 . V_27 [ 0 ] ) {
F_19 ( 500 ) ;
continue;
}
V_12 = F_20 ( V_19 , & V_21 , 1 ) ;
if ( V_12 < 0 ) {
F_21 ( L_2 ) ;
break;
}
}
return 0 ;
}
static void T_2 F_22 ( void )
{
F_23 ( 0 , L_3 , V_28 ,
F_18 ( V_28 ) , 1800000 ) ;
F_23 ( 1 , L_4 , V_29 ,
F_18 ( V_29 ) , 2800000 ) ;
F_24 ( 2 , V_30 , F_18 ( V_30 ) ) ;
F_25 () ;
F_26 ( V_31 , NULL ) ;
F_26 ( V_32 , NULL ) ;
F_26 ( V_33 , NULL ) ;
F_26 ( V_34 , NULL ) ;
F_26 ( V_35 , NULL ) ;
F_26 ( V_36 , NULL ) ;
F_27 ( V_36 ) ;
F_26 ( V_37 , NULL ) ;
F_26 ( V_38 , NULL ) ;
F_26 ( V_39 , NULL ) ;
F_26 ( V_40 , NULL ) ;
F_26 ( V_41 , NULL ) ;
F_26 ( V_42 , NULL ) ;
F_26 ( V_43 , NULL ) ;
F_26 ( V_44 , NULL ) ;
F_26 ( V_45 , NULL ) ;
F_26 ( V_46 , NULL ) ;
F_26 ( V_47 , NULL ) ;
F_26 ( V_48 , NULL ) ;
F_26 ( V_49 , NULL ) ;
F_26 ( V_50 , NULL ) ;
F_26 ( V_51 , NULL ) ;
F_26 ( V_52 , NULL ) ;
F_26 ( V_53 , NULL ) ;
F_26 ( V_54 , NULL ) ;
F_26 ( V_55 , NULL ) ;
F_26 ( V_56 , NULL ) ;
F_26 ( V_57 , NULL ) ;
F_26 ( V_58 , NULL ) ;
F_26 ( V_59 , NULL ) ;
F_26 ( V_60 , NULL ) ;
F_26 ( V_61 , NULL ) ;
F_26 ( V_62 , NULL ) ;
F_26 ( V_63 , NULL ) ;
F_26 ( V_64 , NULL ) ;
F_28 ( V_63 , 1 ) ;
F_28 ( V_64 , 1 ) ;
F_26 ( V_65 , NULL ) ;
F_27 ( V_65 ) ;
F_26 ( V_66 , NULL ) ;
F_26 ( V_67 , NULL ) ;
F_26 ( V_68 , NULL ) ;
F_26 ( V_69 , NULL ) ;
F_26 ( V_70 , NULL ) ;
F_26 ( V_71 , NULL ) ;
F_26 ( V_72 , NULL ) ;
F_26 ( V_73 , NULL ) ;
F_26 ( V_74 , NULL ) ;
F_26 ( V_75 , NULL ) ;
F_26 ( V_76 , NULL ) ;
F_26 ( V_77 , NULL ) ;
F_26 ( V_78 , NULL ) ;
F_26 ( V_79 , NULL ) ;
F_26 ( V_80 , NULL ) ;
F_26 ( V_81 , NULL ) ;
F_26 ( V_82 , NULL ) ;
F_26 ( V_83 , NULL ) ;
F_26 ( V_84 , NULL ) ;
F_26 ( V_85 , NULL ) ;
F_28 ( V_85 , 1 ) ;
F_26 ( V_86 , NULL ) ;
F_26 ( V_87 , NULL ) ;
F_26 ( V_88 , NULL ) ;
F_26 ( V_89 , NULL ) ;
F_26 ( V_90 , NULL ) ;
F_26 ( V_91 , NULL ) ;
F_26 ( V_92 , NULL ) ;
F_28 ( V_92 , 1 ) ;
F_26 ( V_93 , NULL ) ;
F_26 ( V_94 , NULL ) ;
F_26 ( V_95 , NULL ) ;
F_26 ( V_96 , NULL ) ;
F_26 ( V_97 , NULL ) ;
F_26 ( V_98 , NULL ) ;
F_26 ( V_99 , NULL ) ;
F_26 ( V_100 , NULL ) ;
#ifdef F_29
F_30 ( F_31 ( 0xf0100000 ) , 0x40460000 , 0x82000fff ) ;
#endif
F_32 ( 0 , V_101 , F_18 ( V_101 ) ) ;
F_32 ( 1 , V_102 , F_18 ( V_102 ) ) ;
F_32 ( 3 , V_103 , F_18 ( V_103 ) ) ;
F_33 () ;
F_34 ( V_104 , F_18 ( V_104 ) ) ;
}

static void F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 V_4 ;
int V_5 ;
V_2 = F_2 ( 1 ) ;
for ( V_5 = 0 ; V_2 && V_5 < 3 ; V_5 ++ ) {
V_4 . V_6 = 0x6d ;
V_4 . V_7 = & V_8 [ V_5 ] [ 0 ] ;
V_4 . V_9 = 2 ;
V_4 . V_10 = 0 ;
if ( F_3 ( V_2 , & V_4 , 1 ) != 1 )
break;
}
}
static void F_4 ( void )
{
F_5 ( V_11 , 0 ) ;
F_6 ( 24 ) ;
F_5 ( V_11 , 1 ) ;
}
static int F_7 ( struct V_12 * V_13 ,
void T_1 * V_14 ,
int V_15 )
{
struct V_16 * V_17 , * V_18 ;
int V_19 ;
V_17 = F_8 ( & V_13 -> V_20 , L_1 ) ;
if ( F_9 ( V_17 ) ) {
V_19 = F_10 ( V_17 ) ;
goto V_21;
}
V_18 = F_8 ( & V_13 -> V_20 , L_2 ) ;
if ( F_9 ( V_18 ) ) {
V_19 = F_10 ( V_18 ) ;
goto V_22;
}
if ( V_15 ) {
F_11 ( V_17 , F_12 ( V_17 , 24000000 ) ) ;
F_11 ( V_18 , F_12 ( V_17 , 510000000 ) ) ;
F_13 ( V_17 ) ;
F_13 ( V_18 ) ;
} else {
F_14 ( V_17 ) ;
F_14 ( V_18 ) ;
}
V_19 = 0 ;
F_15 ( V_18 ) ;
V_22:
F_15 ( V_17 ) ;
V_21:
return V_19 ;
}
static void F_16 ( struct V_12 * V_13 , int V_23 )
{
static int V_24 = - V_25 ;
if ( V_24 < 0 ) {
int V_19 = F_17 ( V_26 , L_3 ) ;
if ( ! V_19 ) {
V_24 = V_26 ;
F_18 ( V_24 , 0 ) ;
}
}
F_5 ( V_26 , V_23 ) ;
}
static void T_2 F_19 ( void )
{
F_20 ( 0 , L_4 , V_27 ,
F_21 ( V_27 ) , 1800000 ) ;
F_20 ( 1 , L_5 , V_28 ,
F_21 ( V_28 ) , 3300000 ) ;
F_22 ( 3 , V_29 , F_21 ( V_29 ) ) ;
F_23 () ;
F_17 ( V_30 , NULL ) ;
F_17 ( V_31 , NULL ) ;
F_17 ( V_32 , NULL ) ;
F_17 ( V_33 , NULL ) ;
F_17 ( V_34 , NULL ) ;
F_17 ( V_35 , NULL ) ;
F_17 ( V_36 , NULL ) ;
F_17 ( V_37 , NULL ) ;
F_17 ( V_38 , NULL ) ;
F_17 ( V_39 , NULL ) ;
F_17 ( V_40 , NULL ) ;
F_17 ( V_41 , NULL ) ;
F_17 ( V_42 , NULL ) ;
F_17 ( V_43 , NULL ) ;
F_17 ( V_44 , NULL ) ;
F_17 ( V_45 , NULL ) ;
F_17 ( V_46 , NULL ) ;
F_17 ( V_47 , NULL ) ;
F_17 ( V_48 , NULL ) ;
F_17 ( V_49 , NULL ) ;
F_17 ( V_50 , NULL ) ;
F_17 ( V_51 , NULL ) ;
F_17 ( V_52 , NULL ) ;
F_17 ( V_53 , NULL ) ;
F_17 ( V_54 , NULL ) ;
F_17 ( V_55 , NULL ) ;
F_17 ( V_56 , NULL ) ;
F_17 ( V_57 , NULL ) ;
F_17 ( V_58 , NULL ) ;
F_17 ( V_59 , NULL ) ;
F_17 ( V_60 , NULL ) ;
F_17 ( V_61 , NULL ) ;
F_17 ( V_62 , NULL ) ;
F_17 ( V_63 , NULL ) ;
F_17 ( V_64 , NULL ) ;
F_17 ( V_65 , NULL ) ;
F_17 ( V_66 , NULL ) ;
F_18 ( V_66 , 1 ) ;
F_17 ( V_67 , NULL ) ;
F_24 ( V_67 ) ;
F_17 ( V_68 , NULL ) ;
F_18 ( V_68 , 1 ) ;
F_17 ( V_69 , NULL ) ;
F_17 ( V_70 , NULL ) ;
F_17 ( V_71 , NULL ) ;
F_17 ( V_72 , NULL ) ;
F_17 ( V_73 , NULL ) ;
F_17 ( V_74 , NULL ) ;
F_17 ( V_75 , NULL ) ;
F_17 ( V_76 , NULL ) ;
F_17 ( V_77 , NULL ) ;
F_18 ( V_77 , 0 ) ;
F_6 ( 1 ) ;
F_5 ( V_77 , 1 ) ;
F_6 ( 100 ) ;
F_17 ( V_11 , NULL ) ;
F_18 ( V_11 , 0 ) ;
F_4 () ;
F_17 ( V_78 , NULL ) ;
F_17 ( V_79 , NULL ) ;
F_17 ( V_80 , NULL ) ;
F_17 ( V_81 , NULL ) ;
F_17 ( V_82 , NULL ) ;
F_17 ( V_83 , NULL ) ;
F_17 ( V_84 , NULL ) ;
F_17 ( V_85 , NULL ) ;
F_17 ( V_86 , NULL ) ;
F_17 ( V_87 , NULL ) ;
F_17 ( V_88 , NULL ) ;
F_17 ( V_89 , NULL ) ;
F_17 ( V_90 , NULL ) ;
#ifdef F_25
F_26 ( F_27 ( 0xf0100000 ) , 0x00460000 , 0xc2000fff ) ;
#endif
F_28 () ;
F_29 ( V_91 , F_21 ( V_91 ) ) ;
}

static int F_1 ( struct V_1 * V_2 ,
void T_1 * V_3 ,
int V_4 )
{
struct V_5 * V_6 , * V_7 ;
int V_8 ;
V_6 = F_2 ( & V_2 -> V_9 , L_1 ) ;
if ( F_3 ( V_6 ) ) {
V_8 = F_4 ( V_6 ) ;
goto V_10;
}
V_7 = F_2 ( & V_2 -> V_9 , L_2 ) ;
if ( F_3 ( V_7 ) ) {
V_8 = F_4 ( V_7 ) ;
goto V_11;
}
if ( V_4 ) {
F_5 ( V_6 , F_6 ( V_6 , 24000000 ) ) ;
F_5 ( V_7 , F_6 ( V_6 , 510000000 ) ) ;
F_7 ( V_6 ) ;
F_7 ( V_7 ) ;
} else {
F_8 ( V_6 ) ;
F_8 ( V_7 ) ;
}
V_8 = 0 ;
F_9 ( V_7 ) ;
V_11:
F_9 ( V_6 ) ;
V_10:
return V_8 ;
}
static int F_10 ( int V_12 )
{
struct V_13 * V_14 ;
struct V_15 V_16 ;
unsigned int V_17 ;
int V_8 ;
if ( V_12 == 0 ) {
F_11 ( V_18 , 0 ) ;
F_12 ( 24 ) ;
F_11 ( V_18 , 1 ) ;
return 0 ;
}
V_14 = F_13 ( 1 ) ;
if ( V_14 == NULL )
return - V_19 ;
for ( V_17 = 0 ; V_17 < F_14 ( V_20 ) ; V_17 ++ ) {
V_16 . V_21 = 0x6d ;
V_16 . V_22 = & V_20 [ V_17 ] [ 0 ] ;
V_16 . V_23 = 2 ;
V_16 . V_24 = 0 ;
V_8 = F_15 ( V_14 , & V_16 , 1 ) ;
if ( V_8 < 0 )
break;
}
F_16 ( V_14 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
static void F_17 ( struct V_1 * V_2 , int V_25 )
{
static int V_26 = - V_27 ;
if ( V_26 < 0 ) {
int V_8 = F_18 ( V_28 , V_29 ,
L_3 ) ;
if ( ! V_8 )
V_26 = V_28 ;
}
F_11 ( V_28 , V_25 ) ;
}
static void T_2 F_19 ( void )
{
F_20 ( 0 , L_4 , V_30 ,
F_14 ( V_30 ) , 1800000 ) ;
F_20 ( 1 , L_5 , V_31 ,
F_14 ( V_31 ) , 3300000 ) ;
F_21 ( 3 , V_32 , F_14 ( V_32 ) ) ;
F_22 () ;
F_23 ( V_33 , NULL ) ;
F_23 ( V_34 , NULL ) ;
F_23 ( V_35 , NULL ) ;
F_23 ( V_36 , NULL ) ;
F_23 ( V_37 , NULL ) ;
F_23 ( V_38 , NULL ) ;
F_23 ( V_39 , NULL ) ;
F_23 ( V_40 , NULL ) ;
F_23 ( V_41 , NULL ) ;
F_23 ( V_42 , NULL ) ;
F_23 ( V_43 , NULL ) ;
F_23 ( V_44 , NULL ) ;
F_23 ( V_45 , NULL ) ;
F_23 ( V_46 , NULL ) ;
F_23 ( V_47 , NULL ) ;
F_23 ( V_48 , NULL ) ;
F_23 ( V_49 , NULL ) ;
F_23 ( V_50 , NULL ) ;
F_23 ( V_51 , NULL ) ;
F_23 ( V_52 , NULL ) ;
F_23 ( V_53 , NULL ) ;
F_23 ( V_54 , NULL ) ;
F_23 ( V_55 , NULL ) ;
F_23 ( V_56 , NULL ) ;
F_23 ( V_57 , NULL ) ;
F_23 ( V_58 , NULL ) ;
F_23 ( V_59 , NULL ) ;
F_23 ( V_60 , NULL ) ;
F_23 ( V_61 , NULL ) ;
F_23 ( V_62 , NULL ) ;
F_23 ( V_63 , NULL ) ;
F_23 ( V_64 , NULL ) ;
F_23 ( V_65 , NULL ) ;
F_23 ( V_66 , NULL ) ;
F_23 ( V_67 , NULL ) ;
F_23 ( V_68 , NULL ) ;
F_18 ( V_69 , V_70 , NULL ) ;
F_18 ( V_71 , V_72 , NULL ) ;
F_18 ( V_73 , V_70 , NULL ) ;
F_23 ( V_74 , NULL ) ;
F_23 ( V_75 , NULL ) ;
F_23 ( V_76 , NULL ) ;
F_23 ( V_77 , NULL ) ;
F_23 ( V_78 , NULL ) ;
F_23 ( V_79 , NULL ) ;
F_23 ( V_80 , NULL ) ;
F_23 ( V_81 , NULL ) ;
F_18 ( V_82 , V_29 , NULL ) ;
F_12 ( 1 ) ;
F_11 ( V_82 , 1 ) ;
F_12 ( 100 ) ;
F_18 ( V_18 , V_29 , NULL ) ;
F_10 ( 0 ) ;
F_23 ( V_83 , NULL ) ;
F_23 ( V_84 , NULL ) ;
F_23 ( V_85 , NULL ) ;
F_23 ( V_86 , NULL ) ;
F_23 ( V_87 , NULL ) ;
F_23 ( V_88 , NULL ) ;
F_23 ( V_89 , NULL ) ;
F_23 ( V_90 , NULL ) ;
F_23 ( V_91 , NULL ) ;
F_23 ( V_92 , NULL ) ;
F_23 ( V_93 , NULL ) ;
F_23 ( V_94 , NULL ) ;
F_23 ( V_95 , NULL ) ;
#ifdef F_24
F_25 ( F_26 ( 0xf0100000 ) , 0x00460000 , 0xc2000fff ) ;
#endif
F_27 () ;
F_28 ( V_96 , F_14 ( V_96 ) ) ;
}

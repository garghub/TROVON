static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_1 F_3 ( void )
{
F_4 (
(struct V_2 * ) & V_3 ) ;
}
static inline void F_5 ( void )
{
F_6 ( V_4 , F_7 ( V_4 ) , L_1 ) ;
F_8 ( & V_5 ) ;
}
static void F_9 ( T_2 V_6 , struct V_7 * V_8 )
{
T_2 V_9 ;
T_2 V_10 ;
T_2 V_11 ;
V_9 = F_10 ( V_12 ) ;
V_10 = F_10 ( V_13 ) & V_9 ;
V_11 = V_14 ;
for (; V_10 != 0 ; V_10 >>= 1 , V_11 ++ ) {
if ( ( V_10 & 1 ) == 0 )
continue;
F_11 ( V_11 ) ;
}
}
static void F_12 ( struct V_15 * V_16 )
{
T_2 V_17 = F_13 ( V_16 -> V_6 ) ;
F_14 ( 1 << V_17 , V_18 ) ;
F_10 ( V_18 ) ;
}
static void F_15 ( struct V_15 * V_16 )
{
T_2 V_17 = F_13 ( V_16 -> V_6 ) ;
F_14 ( 1 << V_17 , V_13 ) ;
}
static void F_16 ( struct V_15 * V_16 )
{
T_2 V_17 = F_13 ( V_16 -> V_6 ) ;
F_14 ( 1 << V_17 , V_12 ) ;
}
static void T_1 F_17 ( void )
{
int V_19 ;
F_18 ( V_20 L_2 ) ;
F_19 ( F_20 ( V_21 , V_22 ) , L_3 ) ;
F_14 ( 0xFFFF , V_18 ) ;
F_14 ( 0xFFFF , V_13 ) ;
for ( V_19 = V_14 ; V_19 < ( V_14 + V_23 ) ;
V_19 ++ ) {
F_21 ( V_19 , & V_24 , V_25 ) ;
F_22 ( V_19 , V_26 ) ;
}
F_23 ( V_27 , V_28 ) ;
F_24 ( V_27 , F_9 ) ;
}
static int F_25 ( struct V_29 * V_29 )
{
F_26 ( V_29 , 0 , V_30 ,
V_31 , V_32 ,
V_33 , V_34 ,
V_35 ) ;
F_26 ( V_29 , 3 , V_30 ,
V_36 , V_37 ,
V_38 , V_34 ,
V_35 ) ;
F_26 ( V_29 , 4 , V_30 ,
V_39 , V_37 ,
V_38 , V_34 ,
V_40 ) ;
F_26 ( V_29 , 7 , V_30 ,
V_41 , V_37 ,
V_38 , V_34 ,
V_40 ) ;
F_26 ( V_29 , 6 , V_42 ,
V_43 , V_37 ,
V_44 , V_34 ,
V_40 ) ;
F_26 ( V_29 , 8 , V_42 ,
V_45 , V_32 ,
V_44 , V_34 ,
V_40 ) ;
F_26 ( V_29 , 9 , V_42 ,
V_46 , V_32 ,
V_44 , V_34 ,
V_40 ) ;
F_27 ( V_29 , V_47 , & V_48 ) ;
F_27 ( V_29 , V_49 , & V_50 ) ;
F_27 ( V_29 , V_51 , & V_52 ) ;
F_27 ( V_29 , V_53 , & V_54 ) ;
F_27 ( V_29 , V_55 , & V_56 ) ;
F_27 ( V_29 , V_57 , & V_58 ) ;
F_27 ( V_29 , V_59 , & V_60 ) ;
F_27 ( V_29 , V_61 , & V_62 ) ;
F_28 ( V_29 , V_63 , 1 , 1 ,
V_64 ) ;
F_29 ( V_29 , V_65 ,
V_66 ,
V_67 ,
V_68 ,
V_69 ,
V_70 ,
V_71 ) ;
F_30 ( V_29 , V_63 ,
V_72 ,
V_73 ,
V_74 ,
V_75 ) ;
F_31 ( V_29 , 0 , V_63 , V_65 ,
& V_76 ) ;
V_29 -> V_77 . V_78 = & V_79 ;
F_32 () ;
return 0 ;
}
static void T_1 F_33 ( void )
{
F_34 ( 1 , V_80 ,
F_7 ( V_80 ) ) ;
F_35 ( F_20 ( V_81 , V_82 ) ) ;
F_35 ( F_20 ( V_83 , V_82 ) ) ;
F_36 ( NULL ) ;
}
static void T_1 F_37 ( void )
{
F_38 ( 0 , NULL ) ;
F_6 ( V_84 , F_7 ( V_84 ) , L_4 ) ;
}
static void T_1 F_39 ( void )
{
F_40 () ;
F_41 ( V_85 , F_7 ( V_85 ) ) ;
}
static void T_1 F_42 ( void )
{
F_43 () ;
F_17 () ;
}
static void T_1 F_44 ( void )
{
F_45 () ;
F_1 () ;
F_5 () ;
F_33 () ;
F_37 () ;
F_3 () ;
}
static void T_1 F_46 ( void )
{
F_47 ( 26000000 ) ;
}

static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_2 -> V_2 . V_4 = F_2 ( & V_2 -> V_5 -> V_5 ,
V_6 , & V_3 , V_7 ) ;
if ( ! V_2 -> V_2 . V_4 ) {
F_3 ( V_8 L_1 ) ;
return - V_9 ;
}
V_2 -> V_2 . V_10 . V_11 = V_3 ;
V_2 -> V_2 . V_10 . V_12 = V_6 ;
V_2 -> V_13 = & V_14 ;
if ( F_4 ( V_15 , L_2 ) )
F_3 ( V_8 L_3 ,
V_15 ) ;
else if ( F_5 ( V_15 , 1 ) )
F_3 ( V_8 L_4 ,
V_15 ) ;
if ( F_4 ( V_16 , L_5 ) )
F_3 ( V_8 L_3 ,
V_16 ) ;
else if ( F_5 ( V_16 , 1 ) )
F_3 ( V_8 L_4 ,
V_16 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
return F_7 ( & V_2 -> V_5 -> V_5 , V_18 ,
V_2 -> V_2 . V_4 , V_2 -> V_2 . V_10 . V_11 ,
V_2 -> V_2 . V_10 . V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_5 -> V_5 , V_2 -> V_2 . V_10 . V_12 ,
V_2 -> V_2 . V_4 , V_2 -> V_2 . V_10 . V_11 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_16 , 0 ) ;
F_11 ( V_15 , 0 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_11 ( V_16 , 1 ) ;
F_11 ( V_15 , 1 ) ;
}
static void F_13 ( T_2 V_19 )
{
F_11 ( V_20 , ( int ) V_19 ) ;
}
static int T_3 F_14 ( void )
{
#if F_15 ( V_21 ) || F_15 ( V_22 )
static struct V_23 V_24 [] = {
{
. V_25 = L_6 ,
. V_26 = 5000000 ,
. V_27 = 0 ,
. V_28 = 0 ,
. V_29 = & V_30 ,
} ,
} ;
#else
static struct V_31 V_32 = {
. V_33 = L_7 ,
. V_34 = 0x8000 ,
. V_35 = 64 ,
. V_36 = V_37 ,
} ;
static struct V_23 V_24 [] = {
{
. V_25 = L_8 ,
. V_26 = 5000000 ,
. V_27 = 0 ,
. V_28 = 0 ,
. V_38 = V_39 ,
. V_40 = & V_32 ,
. V_29 = & V_30 ,
} ,
} ;
#endif
return F_16 ( V_24 , F_17 ( V_24 ) ) ;
}
static void T_3 F_18 ( void )
{
T_2 V_41 ;
F_19 ( V_42 ,
V_43 ) ;
V_41 = F_20 ( V_44 ) &
~ ( V_45 |
V_46 ) ;
V_41 |= V_47 ;
F_19 ( V_41 , V_44 ) ;
V_41 = F_20 ( V_48 ) ;
V_41 |= V_49 |
V_50 ;
F_19 ( V_41 , V_48 ) ;
V_41 = F_20 ( V_51 ) ;
V_41 |= V_52 |
V_53 ;
F_19 ( V_41 , V_51 ) ;
V_41 = F_20 ( V_54 ) ;
V_41 |= V_55 ;
F_19 ( V_41 , V_54 ) ;
V_41 = F_20 ( V_56 ) ;
V_41 = V_57 ;
F_19 ( V_41 , V_56 ) ;
F_21 () ;
V_41 = F_20 ( V_44 ) ;
F_19 ( ( V_41 | V_58 ) ,
V_44 ) ;
V_41 = F_20 ( V_59 ) ;
F_19 ( ( V_41 | V_60 ) ,
V_59 ) ;
V_41 = F_20 ( V_61 ) ;
F_19 ( ( V_41 | V_62 ) ,
V_61 ) ;
F_19 ( V_63 |
V_64 ,
V_65 ) ;
F_22 ( NULL , V_66 ,
V_67 , NULL ) ;
if ( F_4 ( V_20 , L_9 ) )
F_3 ( V_8 L_3 ,
V_20 ) ;
else if ( F_5 ( V_20 , 1 ) )
F_3 ( V_8 L_4 ,
V_20 ) ;
}

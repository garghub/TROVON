static bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
return V_5 -> V_6 == V_2 -> V_7 -> V_8 ;
}
static int F_2 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_12 * V_6 ;
struct V_13 * V_14 , * V_15 ;
T_1 V_16 ;
V_6 = F_3 ( V_17 , 0x0827 , NULL ) ;
if ( ! V_6 )
return - V_18 ;
V_5 -> V_6 = & V_6 -> V_8 ;
F_4 ( V_16 ) ;
F_5 ( V_19 , V_16 ) ;
V_5 -> V_20 = F_6 ( V_16 , F_1 , V_5 ) ;
if ( ! V_5 -> V_20 )
goto V_21;
V_14 = & V_10 -> V_22 ;
V_14 -> V_23 = V_24 ;
V_14 -> V_25 = V_26 ;
V_5 -> V_20 -> V_27 = V_14 ;
V_5 -> V_28 = F_6 ( V_16 , F_1 , V_5 ) ;
if ( ! V_5 -> V_28 )
goto V_29;
V_15 = & V_10 -> V_30 ;
V_15 -> V_23 = V_24 ;
V_15 -> V_25 = V_31 ;
V_5 -> V_28 -> V_27 = V_15 ;
V_5 -> V_32 = 1 ;
return 0 ;
V_29:
F_7 ( V_5 -> V_20 ) ;
V_21:
return - V_33 ;
}
static void F_8 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_32 )
return;
F_9 ( V_5 -> V_28 ) ;
F_7 ( V_5 -> V_28 ) ;
F_9 ( V_5 -> V_20 ) ;
F_7 ( V_5 -> V_20 ) ;
}
static void F_10 ( void * V_34 )
{
struct V_4 * V_5 = V_34 ;
if ( ++ V_5 -> V_35 != 2 )
return;
F_11 ( V_5 ) ;
}
static int F_12 ( struct V_4 * V_5 , int V_36 )
{
struct V_37 * V_38 , * V_39 ;
struct V_40 V_41 , V_42 ;
T_2 V_43 = 0 ;
if ( V_36 ) {
F_13 ( V_5 , 0 ) ;
F_14 ( V_5 , V_44 , 0xf ) ;
F_14 ( V_5 , V_45 , 0x10 ) ;
if ( V_5 -> V_46 )
V_43 |= V_47 ;
if ( V_5 -> V_48 )
V_43 |= V_49 ;
F_14 ( V_5 , V_50 , V_43 ) ;
F_13 ( V_5 , 1 ) ;
}
V_5 -> V_35 = 0 ;
V_41 . V_51 = V_52 ;
V_41 . V_53 = V_5 -> V_54 ;
V_41 . V_55 = V_56 ;
V_41 . V_57 = V_58 ;
V_41 . V_59 = V_5 -> V_60 ;
V_41 . V_61 = false ;
F_15 ( V_5 -> V_28 , & V_41 ) ;
memset ( & V_5 -> V_62 , 0 , sizeof( V_5 -> V_62 ) ) ;
V_5 -> V_62 . V_63 = V_5 -> V_46 ;
V_5 -> V_62 . V_64 = V_5 -> V_65 ;
V_38 = F_16 ( V_5 -> V_28 ,
& V_5 -> V_62 ,
1 ,
V_52 ,
V_66 | V_67 ) ;
V_38 -> V_68 = F_10 ;
V_38 -> V_69 = V_5 ;
V_42 . V_51 = V_70 ;
V_42 . V_71 = V_5 -> V_54 ;
V_42 . V_72 = V_56 ;
V_42 . V_59 = V_58 ;
V_42 . V_57 = V_5 -> V_60 ;
V_42 . V_61 = false ;
F_15 ( V_5 -> V_20 , & V_42 ) ;
memset ( & V_5 -> V_73 , 0 , sizeof( V_5 -> V_73 ) ) ;
V_5 -> V_73 . V_63 = V_5 -> V_48 ;
V_5 -> V_73 . V_64 = V_5 -> V_65 ;
V_39 = F_16 ( V_5 -> V_20 ,
& V_5 -> V_73 ,
1 ,
V_70 ,
V_66 | V_67 ) ;
V_39 -> V_68 = F_10 ;
V_39 -> V_69 = V_5 ;
F_17 ( V_39 ) ;
F_18 ( V_5 -> V_20 ) ;
F_17 ( V_38 ) ;
F_18 ( V_5 -> V_28 ) ;
return 0 ;
}
int F_19 ( struct V_4 * V_5 )
{
void T_3 * V_74 ;
T_4 V_75 ;
V_74 = F_20 ( V_76 , 16 ) ;
if ( ! V_74 )
return - V_77 ;
V_75 = ( F_21 ( V_74 ) & V_78 ) >> V_79 ;
V_5 -> V_80 = V_81 / ( V_75 + 1 ) ;
F_22 ( V_74 ) ;
V_5 -> V_82 = 16 ;
V_5 -> V_83 = 40 ;
#ifdef F_23
V_5 -> V_11 = F_24 ( sizeof( struct V_9 ) , V_84 ) ;
if ( ! V_5 -> V_11 )
return - V_77 ;
V_5 -> V_85 = & V_86 ;
#endif
return 0 ;
}

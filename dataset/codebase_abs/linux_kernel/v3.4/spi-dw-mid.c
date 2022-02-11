static bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
return V_5 -> V_6 && ( & V_5 -> V_6 -> V_7 == V_2 -> V_8 -> V_7 ) ;
}
static int F_2 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_12 * V_13 , * V_14 ;
T_1 V_15 ;
V_5 -> V_6 = F_3 ( V_16 , 0x0813 , NULL ) ;
if ( ! V_5 -> V_6 )
V_5 -> V_6 = F_3 ( V_16 , 0x0827 , NULL ) ;
F_4 ( V_15 ) ;
F_5 ( V_17 , V_15 ) ;
V_5 -> V_18 = F_6 ( V_15 , F_1 , V_5 ) ;
if ( ! V_5 -> V_18 )
goto V_19;
V_13 = & V_10 -> V_20 ;
V_13 -> V_21 = V_22 ;
V_13 -> V_23 = V_24 ;
V_5 -> V_18 -> V_25 = V_13 ;
V_5 -> V_26 = F_6 ( V_15 , F_1 , V_5 ) ;
if ( ! V_5 -> V_26 )
goto V_27;
V_14 = & V_10 -> V_28 ;
V_14 -> V_21 = V_22 ;
V_14 -> V_23 = V_29 ;
V_5 -> V_26 -> V_25 = V_14 ;
V_5 -> V_30 = 1 ;
return 0 ;
V_27:
F_7 ( V_5 -> V_18 ) ;
V_19:
return - 1 ;
}
static void F_8 ( struct V_4 * V_5 )
{
F_7 ( V_5 -> V_26 ) ;
F_7 ( V_5 -> V_18 ) ;
}
static void F_9 ( void * V_31 )
{
struct V_4 * V_5 = V_31 ;
if ( ++ V_5 -> V_32 != 2 )
return;
F_10 ( V_5 ) ;
}
static int F_11 ( struct V_4 * V_5 , int V_33 )
{
struct V_34 * V_35 = NULL , * V_36 = NULL ;
struct V_1 * V_26 , * V_18 ;
struct V_37 V_38 , V_39 ;
T_2 V_40 = 0 ;
if ( V_33 ) {
F_12 ( V_5 , 0 ) ;
F_13 ( V_5 , V_41 , 0xf ) ;
F_13 ( V_5 , V_42 , 0x10 ) ;
if ( V_5 -> V_43 )
V_40 |= 0x2 ;
if ( V_5 -> V_44 )
V_40 |= 0x1 ;
F_13 ( V_5 , V_45 , V_40 ) ;
F_12 ( V_5 , 1 ) ;
}
V_5 -> V_32 = 0 ;
V_26 = V_5 -> V_26 ;
V_18 = V_5 -> V_18 ;
V_38 . V_46 = V_47 ;
V_38 . V_48 = V_5 -> V_49 ;
V_38 . V_50 = V_51 ;
V_38 . V_52 = V_53 ;
V_38 . V_54 = V_55 ;
V_38 . V_56 = false ;
V_26 -> V_8 -> V_57 ( V_26 , V_58 ,
( unsigned long ) & V_38 ) ;
memset ( & V_5 -> V_59 , 0 , sizeof( V_5 -> V_59 ) ) ;
V_5 -> V_59 . V_60 = V_5 -> V_43 ;
V_5 -> V_59 . V_61 = V_5 -> V_62 ;
V_35 = F_14 ( V_26 ,
& V_5 -> V_59 ,
1 ,
V_47 ,
V_63 | V_64 ) ;
V_35 -> V_65 = F_9 ;
V_35 -> V_66 = V_5 ;
V_39 . V_46 = V_67 ;
V_39 . V_68 = V_5 -> V_49 ;
V_39 . V_69 = V_51 ;
V_39 . V_54 = V_53 ;
V_39 . V_52 = V_55 ;
V_39 . V_56 = false ;
V_18 -> V_8 -> V_57 ( V_18 , V_58 ,
( unsigned long ) & V_39 ) ;
memset ( & V_5 -> V_70 , 0 , sizeof( V_5 -> V_70 ) ) ;
V_5 -> V_70 . V_60 = V_5 -> V_44 ;
V_5 -> V_70 . V_61 = V_5 -> V_62 ;
V_36 = F_14 ( V_18 ,
& V_5 -> V_70 ,
1 ,
V_67 ,
V_63 | V_64 ) ;
V_36 -> V_65 = F_9 ;
V_36 -> V_66 = V_5 ;
V_36 -> V_71 ( V_36 ) ;
V_35 -> V_71 ( V_35 ) ;
return 0 ;
}
int F_15 ( struct V_4 * V_5 )
{
void T_3 * V_72 ;
T_4 V_73 ;
V_72 = F_16 ( V_74 , 16 ) ;
if ( ! V_72 )
return - V_75 ;
V_73 = ( F_17 ( V_72 ) & V_76 ) >> V_77 ;
V_5 -> V_78 = V_79 / ( V_73 + 1 ) ;
F_18 ( V_72 ) ;
V_5 -> V_80 = 16 ;
V_5 -> V_81 = 40 ;
#ifdef F_19
V_5 -> V_11 = F_20 ( sizeof( struct V_9 ) , V_82 ) ;
if ( ! V_5 -> V_11 )
return - V_75 ;
V_5 -> V_83 = & V_84 ;
#endif
return 0 ;
}

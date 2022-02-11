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
if ( F_11 ( V_35 , & V_5 -> V_36 ) & F_12 ( V_37 ) )
return;
F_13 ( V_5 ) ;
}
static struct V_38 * F_14 ( struct V_4 * V_5 )
{
struct V_39 V_40 ;
struct V_38 * V_41 ;
if ( ! V_5 -> V_42 )
return NULL ;
V_40 . V_43 = V_44 ;
V_40 . V_45 = V_5 -> V_46 ;
V_40 . V_47 = V_48 ;
V_40 . V_49 = V_50 ;
V_40 . V_51 = V_5 -> V_52 ;
V_40 . V_53 = false ;
F_15 ( V_5 -> V_28 , & V_40 ) ;
memset ( & V_5 -> V_54 , 0 , sizeof( V_5 -> V_54 ) ) ;
V_5 -> V_54 . V_55 = V_5 -> V_42 ;
V_5 -> V_54 . V_56 = V_5 -> V_57 ;
V_41 = F_16 ( V_5 -> V_28 ,
& V_5 -> V_54 ,
1 ,
V_44 ,
V_58 | V_59 ) ;
V_41 -> V_60 = F_10 ;
V_41 -> V_61 = V_5 ;
return V_41 ;
}
static void F_17 ( void * V_34 )
{
struct V_4 * V_5 = V_34 ;
if ( F_11 ( V_37 , & V_5 -> V_36 ) & F_12 ( V_35 ) )
return;
F_13 ( V_5 ) ;
}
static struct V_38 * F_18 ( struct V_4 * V_5 )
{
struct V_39 V_62 ;
struct V_38 * V_63 ;
if ( ! V_5 -> V_64 )
return NULL ;
V_62 . V_43 = V_65 ;
V_62 . V_66 = V_5 -> V_46 ;
V_62 . V_67 = V_48 ;
V_62 . V_51 = V_50 ;
V_62 . V_49 = V_5 -> V_52 ;
V_62 . V_53 = false ;
F_15 ( V_5 -> V_20 , & V_62 ) ;
memset ( & V_5 -> V_68 , 0 , sizeof( V_5 -> V_68 ) ) ;
V_5 -> V_68 . V_55 = V_5 -> V_64 ;
V_5 -> V_68 . V_56 = V_5 -> V_57 ;
V_63 = F_16 ( V_5 -> V_20 ,
& V_5 -> V_68 ,
1 ,
V_65 ,
V_58 | V_59 ) ;
V_63 -> V_60 = F_17 ;
V_63 -> V_61 = V_5 ;
return V_63 ;
}
static void F_19 ( struct V_4 * V_5 )
{
T_2 V_69 = 0 ;
F_20 ( V_5 , 0 ) ;
F_21 ( V_5 , V_70 , 0xf ) ;
F_21 ( V_5 , V_71 , 0x10 ) ;
if ( V_5 -> V_42 )
V_69 |= V_72 ;
if ( V_5 -> V_64 )
V_69 |= V_73 ;
F_21 ( V_5 , V_74 , V_69 ) ;
F_20 ( V_5 , 1 ) ;
}
static int F_22 ( struct V_4 * V_5 , int V_75 )
{
struct V_38 * V_41 , * V_63 ;
if ( V_75 )
F_19 ( V_5 ) ;
V_41 = F_14 ( V_5 ) ;
V_63 = F_18 ( V_5 ) ;
if ( V_63 ) {
F_23 ( V_37 , & V_5 -> V_36 ) ;
F_24 ( V_63 ) ;
F_25 ( V_5 -> V_20 ) ;
}
if ( V_41 ) {
F_23 ( V_35 , & V_5 -> V_36 ) ;
F_24 ( V_41 ) ;
F_25 ( V_5 -> V_28 ) ;
}
return 0 ;
}
int F_26 ( struct V_4 * V_5 )
{
void T_3 * V_76 ;
T_4 V_77 ;
V_76 = F_27 ( V_78 , 16 ) ;
if ( ! V_76 )
return - V_79 ;
V_77 = ( F_28 ( V_76 ) & V_80 ) >> V_81 ;
V_5 -> V_82 = V_83 / ( V_77 + 1 ) ;
F_29 ( V_76 ) ;
V_5 -> V_84 = 16 ;
#ifdef F_30
V_5 -> V_11 = F_31 ( sizeof( struct V_9 ) , V_85 ) ;
if ( ! V_5 -> V_11 )
return - V_79 ;
V_5 -> V_86 = & V_87 ;
#endif
return 0 ;
}

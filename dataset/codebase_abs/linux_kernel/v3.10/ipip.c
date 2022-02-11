static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = F_3 ( V_4 , V_8 ) ;
const struct V_9 * V_10 = ( const struct V_9 * ) V_2 -> V_11 ;
struct V_12 * V_13 ;
int V_14 ;
const int type = F_4 ( V_2 ) -> type ;
const int V_15 = F_4 ( V_2 ) -> V_15 ;
V_14 = - V_16 ;
V_13 = F_5 ( V_7 , V_2 -> V_5 -> V_17 , V_18 ,
V_10 -> V_19 , V_10 -> V_20 , 0 ) ;
if ( V_13 == NULL )
goto V_21;
if ( type == V_22 && V_15 == V_23 ) {
F_6 ( V_2 , F_2 ( V_2 -> V_5 ) , V_3 ,
V_13 -> V_5 -> V_17 , 0 , V_24 , 0 ) ;
V_14 = 0 ;
goto V_21;
}
if ( type == V_25 ) {
F_7 ( V_2 , F_2 ( V_2 -> V_5 ) , V_13 -> V_5 -> V_17 , 0 ,
V_24 , 0 ) ;
V_14 = 0 ;
goto V_21;
}
if ( V_13 -> V_26 . V_10 . V_19 == 0 )
goto V_21;
V_14 = 0 ;
if ( V_13 -> V_26 . V_10 . V_27 == 0 && type == V_28 )
goto V_21;
if ( F_8 ( V_29 , V_13 -> V_30 + V_31 ) )
V_13 -> V_32 ++ ;
else
V_13 -> V_32 = 1 ;
V_13 -> V_30 = V_29 ;
V_21:
return V_14 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = F_3 ( V_4 , V_8 ) ;
struct V_12 * V_33 ;
const struct V_9 * V_10 = F_10 ( V_2 ) ;
V_33 = F_5 ( V_7 , V_2 -> V_5 -> V_17 , V_18 ,
V_10 -> V_20 , V_10 -> V_19 , 0 ) ;
if ( V_33 ) {
if ( ! F_11 ( NULL , V_34 , V_2 ) )
goto V_35;
return F_12 ( V_33 , V_2 , & V_36 , V_37 ) ;
}
return - 1 ;
V_35:
F_13 ( V_2 ) ;
return 0 ;
}
static T_2 F_14 ( struct V_1 * V_2 , struct V_38 * V_5 )
{
struct V_12 * V_33 = F_15 ( V_5 ) ;
const struct V_9 * V_39 = & V_33 -> V_26 . V_10 ;
if ( F_16 ( V_2 -> V_40 != F_17 ( V_41 ) ) )
goto V_42;
if ( F_18 ( ! V_2 -> V_43 ) ) {
F_19 ( V_2 ) ;
V_2 -> V_43 = 1 ;
}
F_20 ( V_2 , V_5 , V_39 ) ;
return V_44 ;
V_42:
V_5 -> V_45 . V_46 ++ ;
F_21 ( V_2 ) ;
return V_44 ;
}
static int
F_22 ( struct V_38 * V_5 , struct V_47 * V_48 , int V_49 )
{
int V_14 = 0 ;
struct V_50 V_51 ;
if ( F_23 ( & V_51 , V_48 -> V_52 . V_53 , sizeof( V_51 ) ) )
return - V_54 ;
if ( V_51 . V_10 . V_55 != 4 || V_51 . V_10 . V_40 != V_24 ||
V_51 . V_10 . V_56 != 5 || ( V_51 . V_10 . V_57 & F_17 ( ~ V_58 ) ) )
return - V_59 ;
if ( V_51 . V_60 || V_51 . V_61 || V_51 . V_62 || V_51 . V_63 )
return - V_59 ;
if ( V_51 . V_10 . V_27 )
V_51 . V_10 . V_57 |= F_17 ( V_58 ) ;
V_14 = F_24 ( V_5 , & V_51 , V_49 ) ;
if ( V_14 )
return V_14 ;
if ( F_25 ( V_48 -> V_52 . V_53 , & V_51 , sizeof( V_51 ) ) )
return - V_54 ;
return 0 ;
}
static void F_26 ( struct V_38 * V_5 )
{
V_5 -> V_64 = & V_65 ;
V_5 -> type = V_66 ;
V_5 -> V_67 = V_68 ;
V_5 -> V_69 = 0 ;
V_5 -> V_70 = 4 ;
V_5 -> V_71 |= V_72 ;
V_5 -> V_71 |= V_73 ;
V_5 -> V_74 &= ~ V_75 ;
V_5 -> V_71 |= V_76 ;
V_5 -> V_77 |= V_76 ;
F_27 ( V_5 , V_8 ) ;
}
static int F_28 ( struct V_38 * V_5 )
{
struct V_12 * V_33 = F_15 ( V_5 ) ;
memcpy ( V_5 -> V_78 , & V_33 -> V_26 . V_10 . V_20 , 4 ) ;
memcpy ( V_5 -> V_79 , & V_33 -> V_26 . V_10 . V_19 , 4 ) ;
V_33 -> V_80 = 0 ;
V_33 -> V_26 . V_10 . V_40 = V_24 ;
return F_29 ( V_5 ) ;
}
static void F_30 ( struct V_81 * V_11 [] ,
struct V_50 * V_26 )
{
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
V_26 -> V_10 . V_55 = 4 ;
V_26 -> V_10 . V_40 = V_24 ;
V_26 -> V_10 . V_56 = 5 ;
if ( ! V_11 )
return;
if ( V_11 [ V_82 ] )
V_26 -> V_83 = F_31 ( V_11 [ V_82 ] ) ;
if ( V_11 [ V_84 ] )
V_26 -> V_10 . V_20 = F_32 ( V_11 [ V_84 ] ) ;
if ( V_11 [ V_85 ] )
V_26 -> V_10 . V_19 = F_32 ( V_11 [ V_85 ] ) ;
if ( V_11 [ V_86 ] ) {
V_26 -> V_10 . V_27 = F_33 ( V_11 [ V_86 ] ) ;
if ( V_26 -> V_10 . V_27 )
V_26 -> V_10 . V_57 = F_17 ( V_58 ) ;
}
if ( V_11 [ V_87 ] )
V_26 -> V_10 . V_88 = F_33 ( V_11 [ V_87 ] ) ;
if ( ! V_11 [ V_89 ] || F_33 ( V_11 [ V_89 ] ) )
V_26 -> V_10 . V_57 = F_17 ( V_58 ) ;
}
static int F_34 ( struct V_4 * V_90 , struct V_38 * V_5 ,
struct V_81 * V_91 [] , struct V_81 * V_11 [] )
{
struct V_50 V_51 ;
F_30 ( V_11 , & V_51 ) ;
return F_35 ( V_5 , V_91 , & V_51 ) ;
}
static int F_36 ( struct V_38 * V_5 , struct V_81 * V_91 [] ,
struct V_81 * V_11 [] )
{
struct V_50 V_51 ;
F_30 ( V_11 , & V_51 ) ;
if ( ( ( V_5 -> V_67 & V_92 ) && ! V_51 . V_10 . V_19 ) ||
( ! ( V_5 -> V_67 & V_92 ) && V_51 . V_10 . V_19 ) )
return - V_59 ;
return F_37 ( V_5 , V_91 , & V_51 ) ;
}
static T_3 F_38 ( const struct V_38 * V_5 )
{
return
F_39 ( 4 ) +
F_39 ( 4 ) +
F_39 ( 4 ) +
F_39 ( 1 ) +
F_39 ( 1 ) +
F_39 ( 1 ) +
0 ;
}
static int F_40 ( struct V_1 * V_2 , const struct V_38 * V_5 )
{
struct V_12 * V_33 = F_15 ( V_5 ) ;
struct V_50 * V_93 = & V_33 -> V_26 ;
if ( F_41 ( V_2 , V_82 , V_93 -> V_83 ) ||
F_42 ( V_2 , V_84 , V_93 -> V_10 . V_20 ) ||
F_42 ( V_2 , V_85 , V_93 -> V_10 . V_19 ) ||
F_43 ( V_2 , V_86 , V_93 -> V_10 . V_27 ) ||
F_43 ( V_2 , V_87 , V_93 -> V_10 . V_88 ) ||
F_43 ( V_2 , V_89 ,
! ! ( V_93 -> V_10 . V_57 & F_17 ( V_58 ) ) ) )
goto V_94;
return 0 ;
V_94:
return - V_95 ;
}
static int T_4 F_44 ( struct V_4 * V_4 )
{
return F_45 ( V_4 , V_8 , & V_96 , L_1 ) ;
}
static void T_5 F_46 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 , V_8 ) ;
F_47 ( V_7 ) ;
}
static int T_6 F_48 ( void )
{
int V_14 ;
F_49 ( L_2 ) ;
V_14 = F_50 ( & V_97 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_51 ( & V_98 , V_99 ) ;
if ( V_14 < 0 ) {
F_49 ( L_3 , V_100 ) ;
goto V_101;
}
V_14 = F_52 ( & V_96 ) ;
if ( V_14 < 0 )
goto V_102;
V_21:
return V_14 ;
V_102:
F_53 ( & V_98 , V_99 ) ;
V_101:
F_54 ( & V_97 ) ;
goto V_21;
}
static void T_7 F_55 ( void )
{
F_56 ( & V_96 ) ;
if ( F_53 ( & V_98 , V_99 ) )
F_49 ( L_4 , V_100 ) ;
F_54 ( & V_97 ) ;
}

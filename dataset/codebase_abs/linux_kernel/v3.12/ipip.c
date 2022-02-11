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
const struct V_9 * V_10 ;
V_10 = F_10 ( V_2 ) ;
V_33 = F_5 ( V_7 , V_2 -> V_5 -> V_17 , V_18 ,
V_10 -> V_20 , V_10 -> V_19 , 0 ) ;
if ( V_33 ) {
if ( ! F_11 ( NULL , V_34 , V_2 ) )
goto V_35;
if ( F_12 ( V_2 , 0 , V_36 . V_37 ) )
goto V_35;
return F_13 ( V_33 , V_2 , & V_36 , V_38 ) ;
}
return - 1 ;
V_35:
F_14 ( V_2 ) ;
return 0 ;
}
static T_2 F_15 ( struct V_1 * V_2 , struct V_39 * V_5 )
{
struct V_12 * V_33 = F_16 ( V_5 ) ;
const struct V_9 * V_40 = & V_33 -> V_26 . V_10 ;
if ( F_17 ( V_2 -> V_41 != F_18 ( V_42 ) ) )
goto V_43;
if ( F_19 ( ! V_2 -> V_44 ) ) {
F_20 ( V_2 ) ;
V_2 -> V_44 = 1 ;
}
F_21 ( V_2 , V_5 , V_40 , V_40 -> V_41 ) ;
return V_45 ;
V_43:
V_5 -> V_46 . V_47 ++ ;
F_22 ( V_2 ) ;
return V_45 ;
}
static int
F_23 ( struct V_39 * V_5 , struct V_48 * V_49 , int V_50 )
{
int V_14 = 0 ;
struct V_51 V_52 ;
if ( F_24 ( & V_52 , V_49 -> V_53 . V_54 , sizeof( V_52 ) ) )
return - V_55 ;
if ( V_50 == V_56 || V_50 == V_57 ) {
if ( V_52 . V_10 . V_58 != 4 || V_52 . V_10 . V_41 != V_24 ||
V_52 . V_10 . V_59 != 5 || ( V_52 . V_10 . V_60 & F_18 ( ~ V_61 ) ) )
return - V_62 ;
}
V_52 . V_63 = V_52 . V_64 = V_52 . V_65 = V_52 . V_66 = 0 ;
if ( V_52 . V_10 . V_27 )
V_52 . V_10 . V_60 |= F_18 ( V_61 ) ;
V_14 = F_25 ( V_5 , & V_52 , V_50 ) ;
if ( V_14 )
return V_14 ;
if ( F_26 ( V_49 -> V_53 . V_54 , & V_52 , sizeof( V_52 ) ) )
return - V_55 ;
return 0 ;
}
static void F_27 ( struct V_39 * V_5 )
{
V_5 -> V_67 = & V_68 ;
V_5 -> type = V_69 ;
V_5 -> V_70 = V_71 ;
V_5 -> V_72 = 0 ;
V_5 -> V_73 = 4 ;
V_5 -> V_74 |= V_75 ;
V_5 -> V_76 &= ~ V_77 ;
V_5 -> V_74 |= V_78 ;
V_5 -> V_79 |= V_78 ;
F_28 ( V_5 , V_8 ) ;
}
static int F_29 ( struct V_39 * V_5 )
{
struct V_12 * V_33 = F_16 ( V_5 ) ;
memcpy ( V_5 -> V_80 , & V_33 -> V_26 . V_10 . V_20 , 4 ) ;
memcpy ( V_5 -> V_81 , & V_33 -> V_26 . V_10 . V_19 , 4 ) ;
V_33 -> V_82 = 0 ;
V_33 -> V_26 . V_10 . V_41 = V_24 ;
return F_30 ( V_5 ) ;
}
static void F_31 ( struct V_83 * V_11 [] ,
struct V_51 * V_26 )
{
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
V_26 -> V_10 . V_58 = 4 ;
V_26 -> V_10 . V_41 = V_24 ;
V_26 -> V_10 . V_59 = 5 ;
if ( ! V_11 )
return;
if ( V_11 [ V_84 ] )
V_26 -> V_85 = F_32 ( V_11 [ V_84 ] ) ;
if ( V_11 [ V_86 ] )
V_26 -> V_10 . V_20 = F_33 ( V_11 [ V_86 ] ) ;
if ( V_11 [ V_87 ] )
V_26 -> V_10 . V_19 = F_33 ( V_11 [ V_87 ] ) ;
if ( V_11 [ V_88 ] ) {
V_26 -> V_10 . V_27 = F_34 ( V_11 [ V_88 ] ) ;
if ( V_26 -> V_10 . V_27 )
V_26 -> V_10 . V_60 = F_18 ( V_61 ) ;
}
if ( V_11 [ V_89 ] )
V_26 -> V_10 . V_90 = F_34 ( V_11 [ V_89 ] ) ;
if ( ! V_11 [ V_91 ] || F_34 ( V_11 [ V_91 ] ) )
V_26 -> V_10 . V_60 = F_18 ( V_61 ) ;
}
static int F_35 ( struct V_4 * V_92 , struct V_39 * V_5 ,
struct V_83 * V_93 [] , struct V_83 * V_11 [] )
{
struct V_51 V_52 ;
F_31 ( V_11 , & V_52 ) ;
return F_36 ( V_5 , V_93 , & V_52 ) ;
}
static int F_37 ( struct V_39 * V_5 , struct V_83 * V_93 [] ,
struct V_83 * V_11 [] )
{
struct V_51 V_52 ;
F_31 ( V_11 , & V_52 ) ;
if ( ( ( V_5 -> V_70 & V_94 ) && ! V_52 . V_10 . V_19 ) ||
( ! ( V_5 -> V_70 & V_94 ) && V_52 . V_10 . V_19 ) )
return - V_62 ;
return F_38 ( V_5 , V_93 , & V_52 ) ;
}
static T_3 F_39 ( const struct V_39 * V_5 )
{
return
F_40 ( 4 ) +
F_40 ( 4 ) +
F_40 ( 4 ) +
F_40 ( 1 ) +
F_40 ( 1 ) +
F_40 ( 1 ) +
0 ;
}
static int F_41 ( struct V_1 * V_2 , const struct V_39 * V_5 )
{
struct V_12 * V_33 = F_16 ( V_5 ) ;
struct V_51 * V_95 = & V_33 -> V_26 ;
if ( F_42 ( V_2 , V_84 , V_95 -> V_85 ) ||
F_43 ( V_2 , V_86 , V_95 -> V_10 . V_20 ) ||
F_43 ( V_2 , V_87 , V_95 -> V_10 . V_19 ) ||
F_44 ( V_2 , V_88 , V_95 -> V_10 . V_27 ) ||
F_44 ( V_2 , V_89 , V_95 -> V_10 . V_90 ) ||
F_44 ( V_2 , V_91 ,
! ! ( V_95 -> V_10 . V_60 & F_18 ( V_61 ) ) ) )
goto V_96;
return 0 ;
V_96:
return - V_97 ;
}
static int T_4 F_45 ( struct V_4 * V_4 )
{
return F_46 ( V_4 , V_8 , & V_98 , L_1 ) ;
}
static void T_5 F_47 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 , V_8 ) ;
F_48 ( V_7 , & V_98 ) ;
}
static int T_6 F_49 ( void )
{
int V_14 ;
F_50 ( L_2 ) ;
V_14 = F_51 ( & V_99 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_52 ( & V_100 , V_101 ) ;
if ( V_14 < 0 ) {
F_50 ( L_3 , V_102 ) ;
goto V_103;
}
V_14 = F_53 ( & V_98 ) ;
if ( V_14 < 0 )
goto V_104;
V_21:
return V_14 ;
V_104:
F_54 ( & V_100 , V_101 ) ;
V_103:
F_55 ( & V_99 ) ;
goto V_21;
}
static void T_7 F_56 ( void )
{
F_57 ( & V_98 ) ;
if ( F_54 ( & V_100 , V_101 ) )
F_50 ( L_4 , V_102 ) ;
F_55 ( & V_99 ) ;
}

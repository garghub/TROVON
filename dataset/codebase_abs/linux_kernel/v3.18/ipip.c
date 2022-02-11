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
V_13 -> V_24 . V_25 , 0 , V_26 , 0 ) ;
V_14 = 0 ;
goto V_21;
}
if ( type == V_27 ) {
F_7 ( V_2 , F_2 ( V_2 -> V_5 ) , V_13 -> V_24 . V_25 , 0 ,
V_26 , 0 ) ;
V_14 = 0 ;
goto V_21;
}
if ( V_13 -> V_24 . V_10 . V_19 == 0 )
goto V_21;
V_14 = 0 ;
if ( V_13 -> V_24 . V_10 . V_28 == 0 && type == V_29 )
goto V_21;
if ( F_8 ( V_30 , V_13 -> V_31 + V_32 ) )
V_13 -> V_33 ++ ;
else
V_13 -> V_33 = 1 ;
V_13 -> V_31 = V_30 ;
V_21:
return V_14 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = F_3 ( V_4 , V_8 ) ;
struct V_12 * V_34 ;
const struct V_9 * V_10 ;
V_10 = F_10 ( V_2 ) ;
V_34 = F_5 ( V_7 , V_2 -> V_5 -> V_17 , V_18 ,
V_10 -> V_20 , V_10 -> V_19 , 0 ) ;
if ( V_34 ) {
if ( ! F_11 ( NULL , V_35 , V_2 ) )
goto V_36;
if ( F_12 ( V_2 , 0 , V_37 . V_38 ) )
goto V_36;
return F_13 ( V_34 , V_2 , & V_37 , V_39 ) ;
}
return - 1 ;
V_36:
F_14 ( V_2 ) ;
return 0 ;
}
static T_2 F_15 ( struct V_1 * V_2 , struct V_40 * V_5 )
{
struct V_12 * V_34 = F_16 ( V_5 ) ;
const struct V_9 * V_41 = & V_34 -> V_24 . V_10 ;
if ( F_17 ( V_2 -> V_42 != F_18 ( V_43 ) ) )
goto V_44;
V_2 = F_19 ( V_2 , false , V_45 ) ;
if ( F_20 ( V_2 ) )
goto V_21;
F_21 ( V_2 , V_26 ) ;
F_22 ( V_2 , V_5 , V_41 , V_41 -> V_42 ) ;
return V_46 ;
V_44:
F_14 ( V_2 ) ;
V_21:
V_5 -> V_47 . V_48 ++ ;
return V_46 ;
}
static int
F_23 ( struct V_40 * V_5 , struct V_49 * V_50 , int V_51 )
{
int V_14 = 0 ;
struct V_52 V_53 ;
if ( F_24 ( & V_53 , V_50 -> V_54 . V_55 , sizeof( V_53 ) ) )
return - V_56 ;
if ( V_51 == V_57 || V_51 == V_58 ) {
if ( V_53 . V_10 . V_59 != 4 || V_53 . V_10 . V_42 != V_26 ||
V_53 . V_10 . V_60 != 5 || ( V_53 . V_10 . V_61 & F_18 ( ~ V_62 ) ) )
return - V_63 ;
}
V_53 . V_64 = V_53 . V_65 = V_53 . V_66 = V_53 . V_67 = 0 ;
if ( V_53 . V_10 . V_28 )
V_53 . V_10 . V_61 |= F_18 ( V_62 ) ;
V_14 = F_25 ( V_5 , & V_53 , V_51 ) ;
if ( V_14 )
return V_14 ;
if ( F_26 ( V_50 -> V_54 . V_55 , & V_53 , sizeof( V_53 ) ) )
return - V_56 ;
return 0 ;
}
static void F_27 ( struct V_40 * V_5 )
{
V_5 -> V_68 = & V_69 ;
V_5 -> type = V_70 ;
V_5 -> V_71 = V_72 ;
V_5 -> V_73 = 0 ;
V_5 -> V_74 = 4 ;
V_5 -> V_75 |= V_76 ;
F_28 ( V_5 ) ;
V_5 -> V_75 |= V_77 ;
V_5 -> V_78 |= V_77 ;
F_29 ( V_5 , V_8 ) ;
}
static int F_30 ( struct V_40 * V_5 )
{
struct V_12 * V_34 = F_16 ( V_5 ) ;
memcpy ( V_5 -> V_79 , & V_34 -> V_24 . V_10 . V_20 , 4 ) ;
memcpy ( V_5 -> V_80 , & V_34 -> V_24 . V_10 . V_19 , 4 ) ;
V_34 -> V_81 = 0 ;
V_34 -> V_82 = V_34 -> V_81 + V_34 -> V_83 ;
V_34 -> V_24 . V_10 . V_42 = V_26 ;
return F_31 ( V_5 ) ;
}
static void F_32 ( struct V_84 * V_11 [] ,
struct V_52 * V_24 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_24 -> V_10 . V_59 = 4 ;
V_24 -> V_10 . V_42 = V_26 ;
V_24 -> V_10 . V_60 = 5 ;
if ( ! V_11 )
return;
if ( V_11 [ V_85 ] )
V_24 -> V_25 = F_33 ( V_11 [ V_85 ] ) ;
if ( V_11 [ V_86 ] )
V_24 -> V_10 . V_20 = F_34 ( V_11 [ V_86 ] ) ;
if ( V_11 [ V_87 ] )
V_24 -> V_10 . V_19 = F_34 ( V_11 [ V_87 ] ) ;
if ( V_11 [ V_88 ] ) {
V_24 -> V_10 . V_28 = F_35 ( V_11 [ V_88 ] ) ;
if ( V_24 -> V_10 . V_28 )
V_24 -> V_10 . V_61 = F_18 ( V_62 ) ;
}
if ( V_11 [ V_89 ] )
V_24 -> V_10 . V_90 = F_35 ( V_11 [ V_89 ] ) ;
if ( ! V_11 [ V_91 ] || F_35 ( V_11 [ V_91 ] ) )
V_24 -> V_10 . V_61 = F_18 ( V_62 ) ;
}
static bool F_36 ( struct V_84 * V_11 [] ,
struct V_92 * V_93 )
{
bool V_94 = false ;
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
if ( ! V_11 )
return V_94 ;
if ( V_11 [ V_95 ] ) {
V_94 = true ;
V_93 -> type = F_37 ( V_11 [ V_95 ] ) ;
}
if ( V_11 [ V_96 ] ) {
V_94 = true ;
V_93 -> V_71 = F_37 ( V_11 [ V_96 ] ) ;
}
if ( V_11 [ V_97 ] ) {
V_94 = true ;
V_93 -> V_98 = F_37 ( V_11 [ V_97 ] ) ;
}
if ( V_11 [ V_99 ] ) {
V_94 = true ;
V_93 -> V_100 = F_37 ( V_11 [ V_99 ] ) ;
}
return V_94 ;
}
static int F_38 ( struct V_4 * V_101 , struct V_40 * V_5 ,
struct V_84 * V_102 [] , struct V_84 * V_11 [] )
{
struct V_52 V_53 ;
struct V_92 V_93 ;
if ( F_36 ( V_11 , & V_93 ) ) {
struct V_12 * V_13 = F_16 ( V_5 ) ;
int V_14 = F_39 ( V_13 , & V_93 ) ;
if ( V_14 < 0 )
return V_14 ;
}
F_32 ( V_11 , & V_53 ) ;
return F_40 ( V_5 , V_102 , & V_53 ) ;
}
static int F_41 ( struct V_40 * V_5 , struct V_84 * V_102 [] ,
struct V_84 * V_11 [] )
{
struct V_52 V_53 ;
struct V_92 V_93 ;
if ( F_36 ( V_11 , & V_93 ) ) {
struct V_12 * V_13 = F_16 ( V_5 ) ;
int V_14 = F_39 ( V_13 , & V_93 ) ;
if ( V_14 < 0 )
return V_14 ;
}
F_32 ( V_11 , & V_53 ) ;
if ( ( ( V_5 -> V_71 & V_103 ) && ! V_53 . V_10 . V_19 ) ||
( ! ( V_5 -> V_71 & V_103 ) && V_53 . V_10 . V_19 ) )
return - V_63 ;
return F_42 ( V_5 , V_102 , & V_53 ) ;
}
static T_3 F_43 ( const struct V_40 * V_5 )
{
return
F_44 ( 4 ) +
F_44 ( 4 ) +
F_44 ( 4 ) +
F_44 ( 1 ) +
F_44 ( 1 ) +
F_44 ( 1 ) +
F_44 ( 2 ) +
F_44 ( 2 ) +
F_44 ( 2 ) +
F_44 ( 2 ) +
0 ;
}
static int F_45 ( struct V_1 * V_2 , const struct V_40 * V_5 )
{
struct V_12 * V_34 = F_16 ( V_5 ) ;
struct V_52 * V_104 = & V_34 -> V_24 ;
if ( F_46 ( V_2 , V_85 , V_104 -> V_25 ) ||
F_47 ( V_2 , V_86 , V_104 -> V_10 . V_20 ) ||
F_47 ( V_2 , V_87 , V_104 -> V_10 . V_19 ) ||
F_48 ( V_2 , V_88 , V_104 -> V_10 . V_28 ) ||
F_48 ( V_2 , V_89 , V_104 -> V_10 . V_90 ) ||
F_48 ( V_2 , V_91 ,
! ! ( V_104 -> V_10 . V_61 & F_18 ( V_62 ) ) ) )
goto V_105;
if ( F_49 ( V_2 , V_95 ,
V_34 -> V_106 . type ) ||
F_49 ( V_2 , V_97 ,
V_34 -> V_106 . V_98 ) ||
F_49 ( V_2 , V_99 ,
V_34 -> V_106 . V_100 ) ||
F_49 ( V_2 , V_96 ,
V_34 -> V_106 . V_100 ) )
goto V_105;
return 0 ;
V_105:
return - V_107 ;
}
static int T_4 F_50 ( struct V_4 * V_4 )
{
return F_51 ( V_4 , V_8 , & V_108 , L_1 ) ;
}
static void T_5 F_52 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 , V_8 ) ;
F_53 ( V_7 , & V_108 ) ;
}
static int T_6 F_54 ( void )
{
int V_14 ;
F_55 ( L_2 ) ;
V_14 = F_56 ( & V_109 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_57 ( & V_110 , V_111 ) ;
if ( V_14 < 0 ) {
F_55 ( L_3 , V_112 ) ;
goto V_113;
}
V_14 = F_58 ( & V_108 ) ;
if ( V_14 < 0 )
goto V_114;
V_21:
return V_14 ;
V_114:
F_59 ( & V_110 , V_111 ) ;
V_113:
F_60 ( & V_109 ) ;
goto V_21;
}
static void T_7 F_61 ( void )
{
F_62 ( & V_108 ) ;
if ( F_59 ( & V_110 , V_111 ) )
F_55 ( L_4 , V_112 ) ;
F_60 ( & V_109 ) ;
}

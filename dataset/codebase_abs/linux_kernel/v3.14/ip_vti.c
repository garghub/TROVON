static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_7 = F_3 ( V_2 -> V_8 ) ;
struct V_9 * V_10 = F_4 ( V_7 , V_11 ) ;
V_4 = F_5 ( V_10 , V_2 -> V_8 -> V_12 , V_13 ,
V_6 -> V_14 , V_6 -> V_15 , 0 ) ;
if ( V_4 != NULL ) {
struct V_16 * V_17 ;
T_1 V_18 = V_2 -> V_19 ;
int V_20 ;
V_2 -> V_19 = F_6 ( V_4 -> V_21 . V_22 ) ;
V_20 = F_7 ( NULL , V_23 , V_2 ) ;
V_2 -> V_19 = V_18 ;
if ( ! V_20 )
return - 1 ;
V_17 = F_8 ( V_4 -> V_8 -> V_17 ) ;
F_9 ( & V_17 -> V_24 ) ;
V_17 -> V_25 ++ ;
V_17 -> V_26 += V_2 -> V_27 ;
F_10 ( & V_17 -> V_24 ) ;
F_11 ( V_2 ) ;
V_2 -> V_8 = V_4 -> V_8 ;
return 1 ;
}
return - 1 ;
}
static T_2 F_12 ( struct V_1 * V_2 , struct V_28 * V_8 )
{
struct V_3 * V_4 = F_13 ( V_8 ) ;
struct V_5 * V_29 = & V_4 -> V_21 . V_6 ;
T_3 V_30 ;
struct V_31 * V_32 ;
struct V_28 * V_33 ;
struct V_5 * V_34 = F_2 ( V_2 ) ;
T_4 V_35 = V_29 -> V_15 ;
struct V_36 V_37 ;
int V_38 ;
if ( V_2 -> V_39 != F_14 ( V_40 ) )
goto V_41;
V_30 = V_34 -> V_30 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
F_15 ( & V_37 , V_4 -> V_21 . V_42 ,
F_6 ( V_4 -> V_21 . V_22 ) , F_16 ( V_30 ) ,
V_43 ,
V_44 , 0 ,
V_35 , V_29 -> V_14 , 0 , 0 ) ;
V_32 = F_17 ( F_3 ( V_8 ) , & V_37 ) ;
if ( F_18 ( V_32 ) ) {
V_8 -> V_45 . V_46 ++ ;
goto V_47;
}
if ( ! V_32 -> V_35 . V_48 ||
V_32 -> V_35 . V_48 -> V_49 . V_50 != V_51 ) {
V_8 -> V_45 . V_46 ++ ;
F_19 ( V_32 ) ;
goto V_47;
}
V_33 = V_32 -> V_35 . V_8 ;
if ( V_33 == V_8 ) {
F_19 ( V_32 ) ;
V_8 -> V_45 . V_52 ++ ;
goto V_41;
}
if ( V_4 -> V_53 > 0 ) {
if ( F_20 ( V_54 ,
V_4 -> V_55 + V_56 ) ) {
V_4 -> V_53 -- ;
F_21 ( V_2 ) ;
} else
V_4 -> V_53 = 0 ;
}
memset ( F_22 ( V_2 ) , 0 , sizeof( * F_22 ( V_2 ) ) ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 , & V_32 -> V_35 ) ;
F_25 ( V_2 ) ;
V_2 -> V_8 = F_26 ( V_2 ) -> V_8 ;
V_38 = F_27 ( V_2 ) ;
if ( F_28 ( V_38 ) == 0 )
V_38 = V_2 -> V_27 ;
F_29 ( V_38 , & V_8 -> V_45 , V_8 -> V_17 ) ;
return V_57 ;
V_47:
F_21 ( V_2 ) ;
V_41:
V_8 -> V_45 . V_58 ++ ;
F_30 ( V_2 ) ;
return V_57 ;
}
static int
F_31 ( struct V_28 * V_8 , struct V_59 * V_60 , int V_61 )
{
int V_38 = 0 ;
struct V_62 V_63 ;
if ( F_32 ( & V_63 , V_60 -> V_64 . V_65 , sizeof( V_63 ) ) )
return - V_66 ;
if ( V_61 == V_67 || V_61 == V_68 ) {
if ( V_63 . V_6 . V_69 != 4 || V_63 . V_6 . V_39 != V_44 ||
V_63 . V_6 . V_70 != 5 )
return - V_71 ;
}
V_38 = F_33 ( V_8 , & V_63 , V_61 ) ;
if ( V_38 )
return V_38 ;
if ( V_61 != V_72 ) {
V_63 . V_73 |= V_74 | V_75 ;
V_63 . V_76 |= V_74 ;
}
if ( F_34 ( V_60 -> V_64 . V_65 , & V_63 , sizeof( V_63 ) ) )
return - V_66 ;
return 0 ;
}
static void F_35 ( struct V_28 * V_8 )
{
V_8 -> V_77 = & V_78 ;
F_36 ( V_8 , V_11 ) ;
}
static int F_37 ( struct V_28 * V_8 )
{
struct V_3 * V_4 = F_13 ( V_8 ) ;
struct V_5 * V_6 = & V_4 -> V_21 . V_6 ;
memcpy ( V_8 -> V_79 , & V_6 -> V_14 , 4 ) ;
memcpy ( V_8 -> V_80 , & V_6 -> V_15 , 4 ) ;
V_8 -> type = V_81 ;
V_8 -> V_82 = V_83 + sizeof( struct V_5 ) ;
V_8 -> V_84 = V_85 ;
V_8 -> V_86 = V_87 ;
V_8 -> V_88 = 0 ;
V_8 -> V_89 = 4 ;
V_8 -> V_90 |= V_91 ;
V_8 -> V_90 |= V_92 ;
V_8 -> V_93 &= ~ V_94 ;
return F_38 ( V_8 ) ;
}
static void T_5 F_39 ( struct V_28 * V_8 )
{
struct V_3 * V_4 = F_13 ( V_8 ) ;
struct V_5 * V_6 = & V_4 -> V_21 . V_6 ;
V_6 -> V_69 = 4 ;
V_6 -> V_39 = V_44 ;
V_6 -> V_70 = 5 ;
}
static int T_5 F_40 ( struct V_7 * V_7 )
{
int V_38 ;
struct V_9 * V_10 ;
V_38 = F_41 ( V_7 , V_11 , & V_95 , L_1 ) ;
if ( V_38 )
return V_38 ;
V_10 = F_4 ( V_7 , V_11 ) ;
F_39 ( V_10 -> V_96 ) ;
return 0 ;
}
static void T_6 F_42 ( struct V_7 * V_7 )
{
struct V_9 * V_10 = F_4 ( V_7 , V_11 ) ;
F_43 ( V_10 , & V_95 ) ;
}
static int F_44 ( struct V_97 * V_98 [] , struct V_97 * V_99 [] )
{
return 0 ;
}
static void F_45 ( struct V_97 * V_99 [] ,
struct V_62 * V_21 )
{
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_6 . V_39 = V_44 ;
if ( ! V_99 )
return;
if ( V_99 [ V_100 ] )
V_21 -> V_42 = F_46 ( V_99 [ V_100 ] ) ;
if ( V_99 [ V_101 ] )
V_21 -> V_102 = F_47 ( V_99 [ V_101 ] ) ;
if ( V_99 [ V_103 ] )
V_21 -> V_22 = F_47 ( V_99 [ V_103 ] ) ;
if ( V_99 [ V_104 ] )
V_21 -> V_6 . V_14 = F_47 ( V_99 [ V_104 ] ) ;
if ( V_99 [ V_105 ] )
V_21 -> V_6 . V_15 = F_47 ( V_99 [ V_105 ] ) ;
}
static int F_48 ( struct V_7 * V_106 , struct V_28 * V_8 ,
struct V_97 * V_98 [] , struct V_97 * V_99 [] )
{
struct V_62 V_21 ;
F_45 ( V_99 , & V_21 ) ;
return F_49 ( V_8 , V_98 , & V_21 ) ;
}
static int F_50 ( struct V_28 * V_8 , struct V_97 * V_98 [] ,
struct V_97 * V_99 [] )
{
struct V_62 V_63 ;
F_45 ( V_99 , & V_63 ) ;
return F_51 ( V_8 , V_98 , & V_63 ) ;
}
static T_7 F_52 ( const struct V_28 * V_8 )
{
return
F_53 ( 4 ) +
F_53 ( 4 ) +
F_53 ( 4 ) +
F_53 ( 4 ) +
F_53 ( 4 ) +
0 ;
}
static int F_54 ( struct V_1 * V_2 , const struct V_28 * V_8 )
{
struct V_3 * V_107 = F_13 ( V_8 ) ;
struct V_62 * V_63 = & V_107 -> V_21 ;
F_55 ( V_2 , V_100 , V_63 -> V_42 ) ;
F_56 ( V_2 , V_101 , V_63 -> V_102 ) ;
F_56 ( V_2 , V_103 , V_63 -> V_22 ) ;
F_56 ( V_2 , V_104 , V_63 -> V_6 . V_14 ) ;
F_56 ( V_2 , V_105 , V_63 -> V_6 . V_15 ) ;
return 0 ;
}
static int T_8 F_57 ( void )
{
int V_38 ;
F_58 ( L_2 ) ;
V_38 = F_59 ( & V_108 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_60 ( & V_109 ) ;
if ( V_38 < 0 ) {
F_61 ( & V_108 ) ;
F_58 ( L_3 ) ;
}
V_38 = F_62 ( & V_95 ) ;
if ( V_38 < 0 )
goto V_110;
return V_38 ;
V_110:
F_63 ( & V_109 ) ;
F_61 ( & V_108 ) ;
return V_38 ;
}
static void T_9 F_64 ( void )
{
F_65 ( & V_95 ) ;
if ( F_63 ( & V_109 ) )
F_58 ( L_4 ) ;
F_61 ( & V_108 ) ;
}

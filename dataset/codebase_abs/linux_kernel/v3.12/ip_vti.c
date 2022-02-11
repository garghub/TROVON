static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = F_3 ( V_4 , V_8 ) ;
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
const int type = F_4 ( V_2 ) -> type ;
const int V_12 = F_4 ( V_2 ) -> V_12 ;
struct V_13 * V_14 ;
int V_15 ;
switch ( type ) {
default:
case V_16 :
return 0 ;
case V_17 :
switch ( V_12 ) {
case V_18 :
case V_19 :
return 0 ;
default:
break;
}
break;
case V_20 :
if ( V_12 != V_21 )
return 0 ;
break;
}
V_15 = - V_22 ;
V_14 = F_5 ( V_7 , V_2 -> V_5 -> V_23 , V_24 ,
V_10 -> V_25 , V_10 -> V_26 , 0 ) ;
if ( V_14 == NULL )
goto V_27;
if ( type == V_17 && V_12 == V_28 ) {
F_6 ( V_2 , F_2 ( V_2 -> V_5 ) , V_3 ,
V_14 -> V_29 . V_30 , 0 , V_31 , 0 ) ;
V_15 = 0 ;
goto V_27;
}
V_15 = 0 ;
if ( V_14 -> V_29 . V_10 . V_32 == 0 && type == V_20 )
goto V_27;
if ( F_7 ( V_33 , V_14 -> V_34 + V_35 ) )
V_14 -> V_36 ++ ;
else
V_14 -> V_36 = 1 ;
V_14 -> V_34 = V_33 ;
V_27:
return V_15 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_13 * V_37 ;
const struct V_9 * V_10 = F_9 ( V_2 ) ;
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = F_3 ( V_4 , V_8 ) ;
V_37 = F_5 ( V_7 , V_2 -> V_5 -> V_23 , V_24 ,
V_10 -> V_26 , V_10 -> V_25 , 0 ) ;
if ( V_37 != NULL ) {
struct V_38 * V_39 ;
T_1 V_40 = V_2 -> V_41 ;
int V_42 ;
V_2 -> V_41 = F_10 ( V_37 -> V_29 . V_43 ) ;
V_42 = F_11 ( NULL , V_44 , V_2 ) ;
V_2 -> V_41 = V_40 ;
if ( ! V_42 )
return - 1 ;
V_39 = F_12 ( V_37 -> V_5 -> V_39 ) ;
F_13 ( & V_39 -> V_45 ) ;
V_39 -> V_46 ++ ;
V_39 -> V_47 += V_2 -> V_48 ;
F_14 ( & V_39 -> V_45 ) ;
F_15 ( V_2 ) ;
V_2 -> V_5 = V_37 -> V_5 ;
return 1 ;
}
return - 1 ;
}
static T_2 F_16 ( struct V_1 * V_2 , struct V_49 * V_5 )
{
struct V_13 * V_37 = F_17 ( V_5 ) ;
struct V_9 * V_50 = & V_37 -> V_29 . V_10 ;
T_3 V_51 ;
struct V_52 * V_53 ;
struct V_49 * V_54 ;
struct V_9 * V_55 = F_9 ( V_2 ) ;
T_4 V_56 = V_50 -> V_25 ;
struct V_57 V_58 ;
int V_15 ;
if ( V_2 -> V_59 != F_18 ( V_60 ) )
goto V_61;
V_51 = V_55 -> V_51 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
F_19 ( & V_58 , V_37 -> V_29 . V_30 ,
F_10 ( V_37 -> V_29 . V_43 ) , F_20 ( V_51 ) ,
V_62 ,
V_31 , 0 ,
V_56 , V_50 -> V_26 , 0 , 0 ) ;
V_53 = F_21 ( F_2 ( V_5 ) , & V_58 ) ;
if ( F_22 ( V_53 ) ) {
V_5 -> V_63 . V_64 ++ ;
goto V_65;
}
if ( ! V_53 -> V_56 . V_66 ||
V_53 -> V_56 . V_66 -> V_67 . V_68 != V_69 ) {
V_5 -> V_63 . V_64 ++ ;
goto V_65;
}
V_54 = V_53 -> V_56 . V_5 ;
if ( V_54 == V_5 ) {
F_23 ( V_53 ) ;
V_5 -> V_63 . V_70 ++ ;
goto V_61;
}
if ( V_37 -> V_36 > 0 ) {
if ( F_7 ( V_33 ,
V_37 -> V_34 + V_35 ) ) {
V_37 -> V_36 -- ;
F_24 ( V_2 ) ;
} else
V_37 -> V_36 = 0 ;
}
memset ( F_25 ( V_2 ) , 0 , sizeof( * F_25 ( V_2 ) ) ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 , & V_53 -> V_56 ) ;
F_28 ( V_2 ) ;
V_2 -> V_5 = F_29 ( V_2 ) -> V_5 ;
V_15 = F_30 ( V_2 ) ;
if ( F_31 ( V_15 ) == 0 )
V_15 = V_2 -> V_48 ;
F_32 ( V_15 , & V_5 -> V_63 , V_5 -> V_39 ) ;
return V_71 ;
V_65:
F_24 ( V_2 ) ;
V_61:
V_5 -> V_63 . V_72 ++ ;
F_33 ( V_2 ) ;
return V_71 ;
}
static int
F_34 ( struct V_49 * V_5 , struct V_73 * V_74 , int V_75 )
{
int V_15 = 0 ;
struct V_76 V_77 ;
if ( F_35 ( & V_77 , V_74 -> V_78 . V_79 , sizeof( V_77 ) ) )
return - V_80 ;
if ( V_75 == V_81 || V_75 == V_82 ) {
if ( V_77 . V_10 . V_83 != 4 || V_77 . V_10 . V_59 != V_31 ||
V_77 . V_10 . V_84 != 5 )
return - V_85 ;
}
V_15 = F_36 ( V_5 , & V_77 , V_75 ) ;
if ( V_15 )
return V_15 ;
if ( V_75 != V_86 ) {
V_77 . V_87 |= V_88 | V_89 ;
V_77 . V_90 |= V_88 ;
}
if ( F_37 ( V_74 -> V_78 . V_79 , & V_77 , sizeof( V_77 ) ) )
return - V_80 ;
return 0 ;
}
static void F_38 ( struct V_49 * V_5 )
{
V_5 -> V_91 = & V_92 ;
F_39 ( V_5 , V_8 ) ;
}
static int F_40 ( struct V_49 * V_5 )
{
struct V_13 * V_37 = F_17 ( V_5 ) ;
struct V_9 * V_10 = & V_37 -> V_29 . V_10 ;
memcpy ( V_5 -> V_93 , & V_10 -> V_26 , 4 ) ;
memcpy ( V_5 -> V_94 , & V_10 -> V_25 , 4 ) ;
V_5 -> type = V_95 ;
V_5 -> V_96 = V_97 + sizeof( struct V_9 ) ;
V_5 -> V_98 = V_99 ;
V_5 -> V_100 = V_101 ;
V_5 -> V_102 = 0 ;
V_5 -> V_103 = 4 ;
V_5 -> V_104 |= V_105 ;
V_5 -> V_104 |= V_106 ;
V_5 -> V_107 &= ~ V_108 ;
return F_41 ( V_5 ) ;
}
static void T_5 F_42 ( struct V_49 * V_5 )
{
struct V_13 * V_37 = F_17 ( V_5 ) ;
struct V_9 * V_10 = & V_37 -> V_29 . V_10 ;
V_10 -> V_83 = 4 ;
V_10 -> V_59 = V_31 ;
V_10 -> V_84 = 5 ;
}
static int T_5 F_43 ( struct V_4 * V_4 )
{
int V_15 ;
struct V_6 * V_7 ;
V_15 = F_44 ( V_4 , V_8 , & V_109 , L_1 ) ;
if ( V_15 )
return V_15 ;
V_7 = F_3 ( V_4 , V_8 ) ;
F_42 ( V_7 -> V_110 ) ;
return 0 ;
}
static void T_6 F_45 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 , V_8 ) ;
F_46 ( V_7 , & V_109 ) ;
}
static int F_47 ( struct V_111 * V_112 [] , struct V_111 * V_11 [] )
{
return 0 ;
}
static void F_48 ( struct V_111 * V_11 [] ,
struct V_76 * V_29 )
{
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_10 . V_59 = V_31 ;
if ( ! V_11 )
return;
if ( V_11 [ V_113 ] )
V_29 -> V_30 = F_49 ( V_11 [ V_113 ] ) ;
if ( V_11 [ V_114 ] )
V_29 -> V_115 = F_50 ( V_11 [ V_114 ] ) ;
if ( V_11 [ V_116 ] )
V_29 -> V_43 = F_50 ( V_11 [ V_116 ] ) ;
if ( V_11 [ V_117 ] )
V_29 -> V_10 . V_26 = F_50 ( V_11 [ V_117 ] ) ;
if ( V_11 [ V_118 ] )
V_29 -> V_10 . V_25 = F_50 ( V_11 [ V_118 ] ) ;
}
static int F_51 ( struct V_4 * V_119 , struct V_49 * V_5 ,
struct V_111 * V_112 [] , struct V_111 * V_11 [] )
{
struct V_76 V_29 ;
F_48 ( V_11 , & V_29 ) ;
return F_52 ( V_5 , V_112 , & V_29 ) ;
}
static int F_53 ( struct V_49 * V_5 , struct V_111 * V_112 [] ,
struct V_111 * V_11 [] )
{
struct V_76 V_77 ;
F_48 ( V_11 , & V_77 ) ;
return F_54 ( V_5 , V_112 , & V_77 ) ;
}
static T_7 F_55 ( const struct V_49 * V_5 )
{
return
F_56 ( 4 ) +
F_56 ( 4 ) +
F_56 ( 4 ) +
F_56 ( 4 ) +
F_56 ( 4 ) +
0 ;
}
static int F_57 ( struct V_1 * V_2 , const struct V_49 * V_5 )
{
struct V_13 * V_14 = F_17 ( V_5 ) ;
struct V_76 * V_77 = & V_14 -> V_29 ;
F_58 ( V_2 , V_113 , V_77 -> V_30 ) ;
F_59 ( V_2 , V_114 , V_77 -> V_115 ) ;
F_59 ( V_2 , V_116 , V_77 -> V_43 ) ;
F_59 ( V_2 , V_117 , V_77 -> V_10 . V_26 ) ;
F_59 ( V_2 , V_118 , V_77 -> V_10 . V_25 ) ;
return 0 ;
}
static int T_8 F_60 ( void )
{
int V_15 ;
F_61 ( L_2 ) ;
V_15 = F_62 ( & V_120 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_63 ( & V_121 ) ;
if ( V_15 < 0 ) {
F_64 ( & V_120 ) ;
F_61 ( L_3 ) ;
}
V_15 = F_65 ( & V_109 ) ;
if ( V_15 < 0 )
goto V_122;
return V_15 ;
V_122:
F_66 ( & V_121 ) ;
F_64 ( & V_120 ) ;
return V_15 ;
}
static void T_9 F_67 ( void )
{
F_68 ( & V_109 ) ;
if ( F_66 ( & V_121 ) )
F_61 ( L_4 ) ;
F_64 ( & V_120 ) ;
}

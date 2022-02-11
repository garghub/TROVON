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
if ( ! V_13 )
goto V_21;
if ( type == V_22 && V_15 == V_23 ) {
F_6 ( V_2 , F_2 ( V_2 -> V_5 ) , V_3 ,
V_13 -> V_24 . V_25 , 0 , V_10 -> V_26 , 0 ) ;
V_14 = 0 ;
goto V_21;
}
if ( type == V_27 ) {
F_7 ( V_2 , F_2 ( V_2 -> V_5 ) , V_13 -> V_24 . V_25 , 0 ,
V_10 -> V_26 , 0 ) ;
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
static int F_9 ( struct V_1 * V_2 , T_2 V_34 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = F_3 ( V_4 , V_8 ) ;
struct V_35 * V_36 = NULL ;
struct V_12 * V_37 ;
const struct V_9 * V_10 ;
V_10 = F_10 ( V_2 ) ;
V_37 = F_5 ( V_7 , V_2 -> V_5 -> V_17 , V_18 ,
V_10 -> V_20 , V_10 -> V_19 , 0 ) ;
if ( V_37 ) {
const struct V_38 * V_39 ;
if ( V_37 -> V_24 . V_10 . V_26 != V_34 &&
V_37 -> V_24 . V_10 . V_26 != 0 )
goto V_40;
if ( ! F_11 ( NULL , V_41 , V_2 ) )
goto V_40;
#if F_12 ( V_42 )
if ( V_34 == V_43 )
V_39 = & V_44 ;
else
#endif
V_39 = & V_45 ;
if ( F_13 ( V_2 , 0 , V_39 -> V_46 , false ) )
goto V_40;
if ( V_37 -> V_47 ) {
V_36 = F_14 ( V_2 , 0 , 0 , 0 ) ;
if ( ! V_36 )
return 0 ;
}
return F_15 ( V_37 , V_2 , V_39 , V_36 , V_48 ) ;
}
return - 1 ;
V_40:
F_16 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , V_49 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , V_43 ) ;
}
static T_3 F_19 ( struct V_1 * V_2 ,
struct V_50 * V_5 )
{
struct V_12 * V_37 = F_20 ( V_5 ) ;
const struct V_9 * V_51 = & V_37 -> V_24 . V_10 ;
T_2 V_34 ;
switch ( V_2 -> V_26 ) {
case F_21 ( V_52 ) :
V_34 = V_49 ;
break;
#if F_12 ( V_42 )
case F_21 ( V_53 ) :
V_34 = V_43 ;
break;
#endif
default:
goto V_54;
}
if ( V_51 -> V_26 != V_34 && V_51 -> V_26 != 0 )
goto V_54;
if ( F_22 ( V_2 , V_55 ) )
goto V_54;
F_23 ( V_2 , V_34 ) ;
if ( V_37 -> V_47 )
F_24 ( V_2 , V_5 , V_34 ) ;
else
F_25 ( V_2 , V_5 , V_51 , V_34 ) ;
return V_56 ;
V_54:
F_16 ( V_2 ) ;
V_5 -> V_57 . V_58 ++ ;
return V_56 ;
}
static bool F_26 ( T_2 V_34 )
{
switch ( V_34 ) {
case 0 :
case V_49 :
#if F_12 ( V_42 )
case V_43 :
#endif
return true ;
}
return false ;
}
static int
F_27 ( struct V_50 * V_5 , struct V_59 * V_60 , int V_61 )
{
int V_14 = 0 ;
struct V_62 V_63 ;
if ( F_28 ( & V_63 , V_60 -> V_64 . V_65 , sizeof( V_63 ) ) )
return - V_66 ;
if ( V_61 == V_67 || V_61 == V_68 ) {
if ( V_63 . V_10 . V_69 != 4 ||
! F_26 ( V_63 . V_10 . V_26 ) ||
V_63 . V_10 . V_70 != 5 || ( V_63 . V_10 . V_71 & F_21 ( ~ V_72 ) ) )
return - V_73 ;
}
V_63 . V_74 = V_63 . V_75 = 0 ;
V_63 . V_76 = V_63 . V_77 = 0 ;
V_14 = F_29 ( V_5 , & V_63 , V_61 ) ;
if ( V_14 )
return V_14 ;
if ( F_30 ( V_60 -> V_64 . V_65 , & V_63 , sizeof( V_63 ) ) )
return - V_66 ;
return 0 ;
}
static void F_31 ( struct V_50 * V_5 )
{
V_5 -> V_78 = & V_79 ;
V_5 -> type = V_80 ;
V_5 -> V_81 = V_82 ;
V_5 -> V_83 = 4 ;
V_5 -> V_84 |= V_85 ;
F_32 ( V_5 ) ;
V_5 -> V_84 |= V_86 ;
V_5 -> V_87 |= V_86 ;
F_33 ( V_5 , V_8 ) ;
}
static int F_34 ( struct V_50 * V_5 )
{
struct V_12 * V_37 = F_20 ( V_5 ) ;
memcpy ( V_5 -> V_88 , & V_37 -> V_24 . V_10 . V_20 , 4 ) ;
memcpy ( V_5 -> V_89 , & V_37 -> V_24 . V_10 . V_19 , 4 ) ;
V_37 -> V_90 = 0 ;
V_37 -> V_91 = V_37 -> V_90 + V_37 -> V_92 ;
return F_35 ( V_5 ) ;
}
static int F_36 ( struct V_93 * V_94 [] , struct V_93 * V_11 [] )
{
T_2 V_46 ;
if ( ! V_11 || ! V_11 [ V_95 ] )
return 0 ;
V_46 = F_37 ( V_11 [ V_95 ] ) ;
if ( V_46 != V_49 && V_46 != V_43 && V_46 != 0 )
return - V_73 ;
return 0 ;
}
static void F_38 ( struct V_93 * V_11 [] ,
struct V_62 * V_24 , bool * V_47 ,
T_4 * V_96 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_24 -> V_10 . V_69 = 4 ;
V_24 -> V_10 . V_26 = V_49 ;
V_24 -> V_10 . V_70 = 5 ;
* V_47 = false ;
if ( ! V_11 )
return;
if ( V_11 [ V_97 ] )
V_24 -> V_25 = F_39 ( V_11 [ V_97 ] ) ;
if ( V_11 [ V_98 ] )
V_24 -> V_10 . V_20 = F_40 ( V_11 [ V_98 ] ) ;
if ( V_11 [ V_99 ] )
V_24 -> V_10 . V_19 = F_40 ( V_11 [ V_99 ] ) ;
if ( V_11 [ V_100 ] ) {
V_24 -> V_10 . V_28 = F_37 ( V_11 [ V_100 ] ) ;
if ( V_24 -> V_10 . V_28 )
V_24 -> V_10 . V_71 = F_21 ( V_72 ) ;
}
if ( V_11 [ V_101 ] )
V_24 -> V_10 . V_102 = F_37 ( V_11 [ V_101 ] ) ;
if ( V_11 [ V_95 ] )
V_24 -> V_10 . V_26 = F_37 ( V_11 [ V_95 ] ) ;
if ( ! V_11 [ V_103 ] || F_37 ( V_11 [ V_103 ] ) )
V_24 -> V_10 . V_71 = F_21 ( V_72 ) ;
if ( V_11 [ V_104 ] )
* V_47 = true ;
if ( V_11 [ V_105 ] )
* V_96 = F_39 ( V_11 [ V_105 ] ) ;
}
static bool F_41 ( struct V_93 * V_11 [] ,
struct V_106 * V_107 )
{
bool V_108 = false ;
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
if ( ! V_11 )
return V_108 ;
if ( V_11 [ V_109 ] ) {
V_108 = true ;
V_107 -> type = F_42 ( V_11 [ V_109 ] ) ;
}
if ( V_11 [ V_110 ] ) {
V_108 = true ;
V_107 -> V_81 = F_42 ( V_11 [ V_110 ] ) ;
}
if ( V_11 [ V_111 ] ) {
V_108 = true ;
V_107 -> V_112 = F_43 ( V_11 [ V_111 ] ) ;
}
if ( V_11 [ V_113 ] ) {
V_108 = true ;
V_107 -> V_114 = F_43 ( V_11 [ V_113 ] ) ;
}
return V_108 ;
}
static int F_44 ( struct V_4 * V_115 , struct V_50 * V_5 ,
struct V_93 * V_94 [] , struct V_93 * V_11 [] )
{
struct V_12 * V_13 = F_20 ( V_5 ) ;
struct V_62 V_63 ;
struct V_106 V_107 ;
T_4 V_96 = 0 ;
if ( F_41 ( V_11 , & V_107 ) ) {
int V_14 = F_45 ( V_13 , & V_107 ) ;
if ( V_14 < 0 )
return V_14 ;
}
F_38 ( V_11 , & V_63 , & V_13 -> V_47 , & V_96 ) ;
return F_46 ( V_5 , V_94 , & V_63 , V_96 ) ;
}
static int F_47 ( struct V_50 * V_5 , struct V_93 * V_94 [] ,
struct V_93 * V_11 [] )
{
struct V_12 * V_13 = F_20 ( V_5 ) ;
struct V_62 V_63 ;
struct V_106 V_107 ;
bool V_47 ;
T_4 V_96 = V_13 -> V_96 ;
if ( F_41 ( V_11 , & V_107 ) ) {
int V_14 = F_45 ( V_13 , & V_107 ) ;
if ( V_14 < 0 )
return V_14 ;
}
F_38 ( V_11 , & V_63 , & V_47 , & V_96 ) ;
if ( V_47 )
return - V_73 ;
if ( ( ( V_5 -> V_81 & V_116 ) && ! V_63 . V_10 . V_19 ) ||
( ! ( V_5 -> V_81 & V_116 ) && V_63 . V_10 . V_19 ) )
return - V_73 ;
return F_48 ( V_5 , V_94 , & V_63 , V_96 ) ;
}
static T_5 F_49 ( const struct V_50 * V_5 )
{
return
F_50 ( 4 ) +
F_50 ( 4 ) +
F_50 ( 4 ) +
F_50 ( 1 ) +
F_50 ( 1 ) +
F_50 ( 1 ) +
F_50 ( 1 ) +
F_50 ( 2 ) +
F_50 ( 2 ) +
F_50 ( 2 ) +
F_50 ( 2 ) +
F_50 ( 0 ) +
F_50 ( 4 ) +
0 ;
}
static int F_51 ( struct V_1 * V_2 , const struct V_50 * V_5 )
{
struct V_12 * V_37 = F_20 ( V_5 ) ;
struct V_62 * V_117 = & V_37 -> V_24 ;
if ( F_52 ( V_2 , V_97 , V_117 -> V_25 ) ||
F_53 ( V_2 , V_98 , V_117 -> V_10 . V_20 ) ||
F_53 ( V_2 , V_99 , V_117 -> V_10 . V_19 ) ||
F_54 ( V_2 , V_100 , V_117 -> V_10 . V_28 ) ||
F_54 ( V_2 , V_101 , V_117 -> V_10 . V_102 ) ||
F_54 ( V_2 , V_95 , V_117 -> V_10 . V_26 ) ||
F_54 ( V_2 , V_103 ,
! ! ( V_117 -> V_10 . V_71 & F_21 ( V_72 ) ) ) ||
F_52 ( V_2 , V_105 , V_37 -> V_96 ) )
goto V_118;
if ( F_55 ( V_2 , V_109 ,
V_37 -> V_119 . type ) ||
F_56 ( V_2 , V_111 ,
V_37 -> V_119 . V_112 ) ||
F_56 ( V_2 , V_113 ,
V_37 -> V_119 . V_114 ) ||
F_55 ( V_2 , V_110 ,
V_37 -> V_119 . V_81 ) )
goto V_118;
if ( V_37 -> V_47 )
if ( F_57 ( V_2 , V_104 ) )
goto V_118;
return 0 ;
V_118:
return - V_120 ;
}
static int T_6 F_58 ( struct V_4 * V_4 )
{
return F_59 ( V_4 , V_8 , & V_121 , L_1 ) ;
}
static void T_7 F_60 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 , V_8 ) ;
F_61 ( V_7 , & V_121 ) ;
}
static int T_8 F_62 ( void )
{
int V_14 ;
F_63 ( L_2 ) ;
V_14 = F_64 ( & V_122 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_65 ( & V_123 , V_124 ) ;
if ( V_14 < 0 ) {
F_63 ( L_3 , V_125 ) ;
goto V_126;
}
#if F_12 ( V_42 )
V_14 = F_65 ( & V_127 , V_128 ) ;
if ( V_14 < 0 ) {
F_63 ( L_3 , V_125 ) ;
goto V_129;
}
#endif
V_14 = F_66 ( & V_121 ) ;
if ( V_14 < 0 )
goto V_130;
V_21:
return V_14 ;
V_130:
#if F_12 ( V_42 )
F_67 ( & V_127 , V_124 ) ;
V_129:
#endif
F_67 ( & V_123 , V_124 ) ;
V_126:
F_68 ( & V_122 ) ;
goto V_21;
}
static void T_9 F_69 ( void )
{
F_70 ( & V_121 ) ;
if ( F_67 ( & V_123 , V_124 ) )
F_63 ( L_4 , V_125 ) ;
#if F_12 ( V_42 )
if ( F_67 ( & V_127 , V_128 ) )
F_63 ( L_4 , V_125 ) ;
#endif
F_68 ( & V_122 ) ;
}

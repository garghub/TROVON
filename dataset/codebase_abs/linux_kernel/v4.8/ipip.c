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
struct V_12 * V_35 ;
const struct V_9 * V_10 ;
V_10 = F_10 ( V_2 ) ;
V_35 = F_5 ( V_7 , V_2 -> V_5 -> V_17 , V_18 ,
V_10 -> V_20 , V_10 -> V_19 , 0 ) ;
if ( V_35 ) {
const struct V_36 * V_37 ;
if ( V_35 -> V_24 . V_10 . V_26 != V_34 &&
V_35 -> V_24 . V_10 . V_26 != 0 )
goto V_38;
if ( ! F_11 ( NULL , V_39 , V_2 ) )
goto V_38;
#if F_12 ( V_40 )
if ( V_34 == V_41 )
V_37 = & V_42 ;
else
#endif
V_37 = & V_43 ;
if ( F_13 ( V_2 , 0 , V_37 -> V_44 , false ) )
goto V_38;
return F_14 ( V_35 , V_2 , V_37 , NULL , V_45 ) ;
}
return - 1 ;
V_38:
F_15 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , V_46 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , V_41 ) ;
}
static T_3 F_18 ( struct V_1 * V_2 ,
struct V_47 * V_5 )
{
struct V_12 * V_35 = F_19 ( V_5 ) ;
const struct V_9 * V_48 = & V_35 -> V_24 . V_10 ;
T_2 V_34 ;
switch ( V_2 -> V_26 ) {
case F_20 ( V_49 ) :
V_34 = V_46 ;
break;
#if F_12 ( V_40 )
case F_20 ( V_50 ) :
V_34 = V_41 ;
break;
#endif
default:
goto V_51;
}
if ( V_48 -> V_26 != V_34 && V_48 -> V_26 != 0 )
goto V_51;
if ( F_21 ( V_2 , V_52 ) )
goto V_51;
F_22 ( V_2 , V_34 ) ;
F_23 ( V_2 , V_5 , V_48 , V_34 ) ;
return V_53 ;
V_51:
F_15 ( V_2 ) ;
V_5 -> V_54 . V_55 ++ ;
return V_53 ;
}
static bool F_24 ( T_2 V_34 )
{
switch ( V_34 ) {
case 0 :
case V_46 :
#if F_12 ( V_40 )
case V_41 :
#endif
return true ;
}
return false ;
}
static int
F_25 ( struct V_47 * V_5 , struct V_56 * V_57 , int V_58 )
{
int V_14 = 0 ;
struct V_59 V_60 ;
if ( F_26 ( & V_60 , V_57 -> V_61 . V_62 , sizeof( V_60 ) ) )
return - V_63 ;
if ( V_58 == V_64 || V_58 == V_65 ) {
if ( V_60 . V_10 . V_66 != 4 ||
! F_24 ( V_60 . V_10 . V_26 ) ||
V_60 . V_10 . V_67 != 5 || ( V_60 . V_10 . V_68 & F_20 ( ~ V_69 ) ) )
return - V_70 ;
}
V_60 . V_71 = V_60 . V_72 = 0 ;
V_60 . V_73 = V_60 . V_74 = 0 ;
V_14 = F_27 ( V_5 , & V_60 , V_58 ) ;
if ( V_14 )
return V_14 ;
if ( F_28 ( V_57 -> V_61 . V_62 , & V_60 , sizeof( V_60 ) ) )
return - V_63 ;
return 0 ;
}
static void F_29 ( struct V_47 * V_5 )
{
V_5 -> V_75 = & V_76 ;
V_5 -> type = V_77 ;
V_5 -> V_78 = V_79 ;
V_5 -> V_80 = 4 ;
V_5 -> V_81 |= V_82 ;
F_30 ( V_5 ) ;
V_5 -> V_81 |= V_83 ;
V_5 -> V_84 |= V_83 ;
F_31 ( V_5 , V_8 ) ;
}
static int F_32 ( struct V_47 * V_5 )
{
struct V_12 * V_35 = F_19 ( V_5 ) ;
memcpy ( V_5 -> V_85 , & V_35 -> V_24 . V_10 . V_20 , 4 ) ;
memcpy ( V_5 -> V_86 , & V_35 -> V_24 . V_10 . V_19 , 4 ) ;
V_35 -> V_87 = 0 ;
V_35 -> V_88 = V_35 -> V_87 + V_35 -> V_89 ;
return F_33 ( V_5 ) ;
}
static int F_34 ( struct V_90 * V_91 [] , struct V_90 * V_11 [] )
{
T_2 V_44 ;
if ( ! V_11 || ! V_11 [ V_92 ] )
return 0 ;
V_44 = F_35 ( V_11 [ V_92 ] ) ;
if ( V_44 != V_46 && V_44 != V_41 && V_44 != 0 )
return - V_70 ;
return 0 ;
}
static void F_36 ( struct V_90 * V_11 [] ,
struct V_59 * V_24 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_24 -> V_10 . V_66 = 4 ;
V_24 -> V_10 . V_26 = V_46 ;
V_24 -> V_10 . V_67 = 5 ;
if ( ! V_11 )
return;
if ( V_11 [ V_93 ] )
V_24 -> V_25 = F_37 ( V_11 [ V_93 ] ) ;
if ( V_11 [ V_94 ] )
V_24 -> V_10 . V_20 = F_38 ( V_11 [ V_94 ] ) ;
if ( V_11 [ V_95 ] )
V_24 -> V_10 . V_19 = F_38 ( V_11 [ V_95 ] ) ;
if ( V_11 [ V_96 ] ) {
V_24 -> V_10 . V_28 = F_35 ( V_11 [ V_96 ] ) ;
if ( V_24 -> V_10 . V_28 )
V_24 -> V_10 . V_68 = F_20 ( V_69 ) ;
}
if ( V_11 [ V_97 ] )
V_24 -> V_10 . V_98 = F_35 ( V_11 [ V_97 ] ) ;
if ( V_11 [ V_92 ] )
V_24 -> V_10 . V_26 = F_35 ( V_11 [ V_92 ] ) ;
if ( ! V_11 [ V_99 ] || F_35 ( V_11 [ V_99 ] ) )
V_24 -> V_10 . V_68 = F_20 ( V_69 ) ;
}
static bool F_39 ( struct V_90 * V_11 [] ,
struct V_100 * V_101 )
{
bool V_102 = false ;
memset ( V_101 , 0 , sizeof( * V_101 ) ) ;
if ( ! V_11 )
return V_102 ;
if ( V_11 [ V_103 ] ) {
V_102 = true ;
V_101 -> type = F_40 ( V_11 [ V_103 ] ) ;
}
if ( V_11 [ V_104 ] ) {
V_102 = true ;
V_101 -> V_78 = F_40 ( V_11 [ V_104 ] ) ;
}
if ( V_11 [ V_105 ] ) {
V_102 = true ;
V_101 -> V_106 = F_41 ( V_11 [ V_105 ] ) ;
}
if ( V_11 [ V_107 ] ) {
V_102 = true ;
V_101 -> V_108 = F_41 ( V_11 [ V_107 ] ) ;
}
return V_102 ;
}
static int F_42 ( struct V_4 * V_109 , struct V_47 * V_5 ,
struct V_90 * V_91 [] , struct V_90 * V_11 [] )
{
struct V_59 V_60 ;
struct V_100 V_101 ;
if ( F_39 ( V_11 , & V_101 ) ) {
struct V_12 * V_13 = F_19 ( V_5 ) ;
int V_14 = F_43 ( V_13 , & V_101 ) ;
if ( V_14 < 0 )
return V_14 ;
}
F_36 ( V_11 , & V_60 ) ;
return F_44 ( V_5 , V_91 , & V_60 ) ;
}
static int F_45 ( struct V_47 * V_5 , struct V_90 * V_91 [] ,
struct V_90 * V_11 [] )
{
struct V_59 V_60 ;
struct V_100 V_101 ;
if ( F_39 ( V_11 , & V_101 ) ) {
struct V_12 * V_13 = F_19 ( V_5 ) ;
int V_14 = F_43 ( V_13 , & V_101 ) ;
if ( V_14 < 0 )
return V_14 ;
}
F_36 ( V_11 , & V_60 ) ;
if ( ( ( V_5 -> V_78 & V_110 ) && ! V_60 . V_10 . V_19 ) ||
( ! ( V_5 -> V_78 & V_110 ) && V_60 . V_10 . V_19 ) )
return - V_70 ;
return F_46 ( V_5 , V_91 , & V_60 ) ;
}
static T_4 F_47 ( const struct V_47 * V_5 )
{
return
F_48 ( 4 ) +
F_48 ( 4 ) +
F_48 ( 4 ) +
F_48 ( 1 ) +
F_48 ( 1 ) +
F_48 ( 1 ) +
F_48 ( 1 ) +
F_48 ( 2 ) +
F_48 ( 2 ) +
F_48 ( 2 ) +
F_48 ( 2 ) +
0 ;
}
static int F_49 ( struct V_1 * V_2 , const struct V_47 * V_5 )
{
struct V_12 * V_35 = F_19 ( V_5 ) ;
struct V_59 * V_111 = & V_35 -> V_24 ;
if ( F_50 ( V_2 , V_93 , V_111 -> V_25 ) ||
F_51 ( V_2 , V_94 , V_111 -> V_10 . V_20 ) ||
F_51 ( V_2 , V_95 , V_111 -> V_10 . V_19 ) ||
F_52 ( V_2 , V_96 , V_111 -> V_10 . V_28 ) ||
F_52 ( V_2 , V_97 , V_111 -> V_10 . V_98 ) ||
F_52 ( V_2 , V_92 , V_111 -> V_10 . V_26 ) ||
F_52 ( V_2 , V_99 ,
! ! ( V_111 -> V_10 . V_68 & F_20 ( V_69 ) ) ) )
goto V_112;
if ( F_53 ( V_2 , V_103 ,
V_35 -> V_113 . type ) ||
F_54 ( V_2 , V_105 ,
V_35 -> V_113 . V_106 ) ||
F_54 ( V_2 , V_107 ,
V_35 -> V_113 . V_108 ) ||
F_53 ( V_2 , V_104 ,
V_35 -> V_113 . V_78 ) )
goto V_112;
return 0 ;
V_112:
return - V_114 ;
}
static int T_5 F_55 ( struct V_4 * V_4 )
{
return F_56 ( V_4 , V_8 , & V_115 , L_1 ) ;
}
static void T_6 F_57 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 , V_8 ) ;
F_58 ( V_7 , & V_115 ) ;
}
static int T_7 F_59 ( void )
{
int V_14 ;
F_60 ( L_2 ) ;
V_14 = F_61 ( & V_116 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_62 ( & V_117 , V_118 ) ;
if ( V_14 < 0 ) {
F_60 ( L_3 , V_119 ) ;
goto V_120;
}
#if F_12 ( V_40 )
V_14 = F_62 ( & V_121 , V_122 ) ;
if ( V_14 < 0 ) {
F_60 ( L_3 , V_119 ) ;
goto V_123;
}
#endif
V_14 = F_63 ( & V_115 ) ;
if ( V_14 < 0 )
goto V_124;
V_21:
return V_14 ;
V_124:
#if F_12 ( V_40 )
F_64 ( & V_121 , V_118 ) ;
V_123:
#endif
F_64 ( & V_117 , V_118 ) ;
V_120:
F_65 ( & V_116 ) ;
goto V_21;
}
static void T_8 F_66 ( void )
{
F_67 ( & V_115 ) ;
if ( F_64 ( & V_117 , V_118 ) )
F_60 ( L_4 , V_119 ) ;
#if F_12 ( V_40 )
if ( F_64 ( & V_121 , V_122 ) )
F_60 ( L_4 , V_119 ) ;
#endif
F_65 ( & V_116 ) ;
}

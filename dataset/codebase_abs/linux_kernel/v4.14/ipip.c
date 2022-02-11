static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = F_3 ( V_4 , V_8 ) ;
const struct V_9 * V_10 = ( const struct V_9 * ) V_2 -> V_11 ;
const int type = F_4 ( V_2 ) -> type ;
const int V_12 = F_4 ( V_2 ) -> V_12 ;
struct V_13 * V_14 ;
int V_15 = 0 ;
switch ( type ) {
case V_16 :
switch ( V_12 ) {
case V_17 :
goto V_18;
default:
break;
}
break;
case V_19 :
if ( V_12 != V_20 )
goto V_18;
break;
case V_21 :
break;
default:
goto V_18;
}
V_14 = F_5 ( V_7 , V_2 -> V_5 -> V_22 , V_23 ,
V_10 -> V_24 , V_10 -> V_25 , 0 ) ;
if ( ! V_14 ) {
V_15 = - V_26 ;
goto V_18;
}
if ( type == V_16 && V_12 == V_27 ) {
F_6 ( V_2 , V_4 , V_3 , V_14 -> V_28 . V_29 , 0 ,
V_10 -> V_30 , 0 ) ;
goto V_18;
}
if ( type == V_21 ) {
F_7 ( V_2 , V_4 , V_14 -> V_28 . V_29 , 0 , V_10 -> V_30 , 0 ) ;
goto V_18;
}
if ( V_14 -> V_28 . V_10 . V_24 == 0 ) {
V_15 = - V_26 ;
goto V_18;
}
if ( V_14 -> V_28 . V_10 . V_31 == 0 && type == V_19 )
goto V_18;
if ( F_8 ( V_32 , V_14 -> V_33 + V_34 ) )
V_14 -> V_35 ++ ;
else
V_14 -> V_35 = 1 ;
V_14 -> V_33 = V_32 ;
V_18:
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_36 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = F_3 ( V_4 , V_8 ) ;
struct V_37 * V_38 = NULL ;
struct V_13 * V_39 ;
const struct V_9 * V_10 ;
V_10 = F_10 ( V_2 ) ;
V_39 = F_5 ( V_7 , V_2 -> V_5 -> V_22 , V_23 ,
V_10 -> V_25 , V_10 -> V_24 , 0 ) ;
if ( V_39 ) {
const struct V_40 * V_41 ;
if ( V_39 -> V_28 . V_10 . V_30 != V_36 &&
V_39 -> V_28 . V_10 . V_30 != 0 )
goto V_42;
if ( ! F_11 ( NULL , V_43 , V_2 ) )
goto V_42;
#if F_12 ( V_44 )
if ( V_36 == V_45 )
V_41 = & V_46 ;
else
#endif
V_41 = & V_47 ;
if ( F_13 ( V_2 , 0 , V_41 -> V_48 , false ) )
goto V_42;
if ( V_39 -> V_49 ) {
V_38 = F_14 ( V_2 , 0 , 0 , 0 ) ;
if ( ! V_38 )
return 0 ;
}
return F_15 ( V_39 , V_2 , V_41 , V_38 , V_50 ) ;
}
return - 1 ;
V_42:
F_16 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , V_51 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , V_45 ) ;
}
static T_3 F_19 ( struct V_1 * V_2 ,
struct V_52 * V_5 )
{
struct V_13 * V_39 = F_20 ( V_5 ) ;
const struct V_9 * V_53 = & V_39 -> V_28 . V_10 ;
T_2 V_36 ;
switch ( V_2 -> V_30 ) {
case F_21 ( V_54 ) :
V_36 = V_51 ;
break;
#if F_12 ( V_44 )
case F_21 ( V_55 ) :
V_36 = V_45 ;
break;
#endif
default:
goto V_56;
}
if ( V_53 -> V_30 != V_36 && V_53 -> V_30 != 0 )
goto V_56;
if ( F_22 ( V_2 , V_57 ) )
goto V_56;
F_23 ( V_2 , V_36 ) ;
if ( V_39 -> V_49 )
F_24 ( V_2 , V_5 , V_36 ) ;
else
F_25 ( V_2 , V_5 , V_53 , V_36 ) ;
return V_58 ;
V_56:
F_16 ( V_2 ) ;
V_5 -> V_59 . V_60 ++ ;
return V_58 ;
}
static bool F_26 ( T_2 V_36 )
{
switch ( V_36 ) {
case 0 :
case V_51 :
#if F_12 ( V_44 )
case V_45 :
#endif
return true ;
}
return false ;
}
static int
F_27 ( struct V_52 * V_5 , struct V_61 * V_62 , int V_63 )
{
int V_15 = 0 ;
struct V_64 V_65 ;
if ( F_28 ( & V_65 , V_62 -> V_66 . V_67 , sizeof( V_65 ) ) )
return - V_68 ;
if ( V_63 == V_69 || V_63 == V_70 ) {
if ( V_65 . V_10 . V_71 != 4 ||
! F_26 ( V_65 . V_10 . V_30 ) ||
V_65 . V_10 . V_72 != 5 || ( V_65 . V_10 . V_73 & F_21 ( ~ V_74 ) ) )
return - V_75 ;
}
V_65 . V_76 = V_65 . V_77 = 0 ;
V_65 . V_78 = V_65 . V_79 = 0 ;
V_15 = F_29 ( V_5 , & V_65 , V_63 ) ;
if ( V_15 )
return V_15 ;
if ( F_30 ( V_62 -> V_66 . V_67 , & V_65 , sizeof( V_65 ) ) )
return - V_68 ;
return 0 ;
}
static void F_31 ( struct V_52 * V_5 )
{
V_5 -> V_80 = & V_81 ;
V_5 -> type = V_82 ;
V_5 -> V_83 = V_84 ;
V_5 -> V_85 = 4 ;
V_5 -> V_86 |= V_87 ;
F_32 ( V_5 ) ;
V_5 -> V_86 |= V_88 ;
V_5 -> V_89 |= V_88 ;
F_33 ( V_5 , V_8 ) ;
}
static int F_34 ( struct V_52 * V_5 )
{
struct V_13 * V_39 = F_20 ( V_5 ) ;
memcpy ( V_5 -> V_90 , & V_39 -> V_28 . V_10 . V_25 , 4 ) ;
memcpy ( V_5 -> V_91 , & V_39 -> V_28 . V_10 . V_24 , 4 ) ;
V_39 -> V_92 = 0 ;
V_39 -> V_93 = V_39 -> V_92 + V_39 -> V_94 ;
return F_35 ( V_5 ) ;
}
static int F_36 ( struct V_95 * V_96 [] , struct V_95 * V_11 [] ,
struct V_97 * V_98 )
{
T_2 V_48 ;
if ( ! V_11 || ! V_11 [ V_99 ] )
return 0 ;
V_48 = F_37 ( V_11 [ V_99 ] ) ;
if ( V_48 != V_51 && V_48 != V_45 && V_48 != 0 )
return - V_75 ;
return 0 ;
}
static void F_38 ( struct V_95 * V_11 [] ,
struct V_64 * V_28 , bool * V_49 ,
T_4 * V_100 )
{
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_10 . V_71 = 4 ;
V_28 -> V_10 . V_30 = V_51 ;
V_28 -> V_10 . V_72 = 5 ;
* V_49 = false ;
if ( ! V_11 )
return;
if ( V_11 [ V_101 ] )
V_28 -> V_29 = F_39 ( V_11 [ V_101 ] ) ;
if ( V_11 [ V_102 ] )
V_28 -> V_10 . V_25 = F_40 ( V_11 [ V_102 ] ) ;
if ( V_11 [ V_103 ] )
V_28 -> V_10 . V_24 = F_40 ( V_11 [ V_103 ] ) ;
if ( V_11 [ V_104 ] ) {
V_28 -> V_10 . V_31 = F_37 ( V_11 [ V_104 ] ) ;
if ( V_28 -> V_10 . V_31 )
V_28 -> V_10 . V_73 = F_21 ( V_74 ) ;
}
if ( V_11 [ V_105 ] )
V_28 -> V_10 . V_106 = F_37 ( V_11 [ V_105 ] ) ;
if ( V_11 [ V_99 ] )
V_28 -> V_10 . V_30 = F_37 ( V_11 [ V_99 ] ) ;
if ( ! V_11 [ V_107 ] || F_37 ( V_11 [ V_107 ] ) )
V_28 -> V_10 . V_73 = F_21 ( V_74 ) ;
if ( V_11 [ V_108 ] )
* V_49 = true ;
if ( V_11 [ V_109 ] )
* V_100 = F_39 ( V_11 [ V_109 ] ) ;
}
static bool F_41 ( struct V_95 * V_11 [] ,
struct V_110 * V_111 )
{
bool V_112 = false ;
memset ( V_111 , 0 , sizeof( * V_111 ) ) ;
if ( ! V_11 )
return V_112 ;
if ( V_11 [ V_113 ] ) {
V_112 = true ;
V_111 -> type = F_42 ( V_11 [ V_113 ] ) ;
}
if ( V_11 [ V_114 ] ) {
V_112 = true ;
V_111 -> V_83 = F_42 ( V_11 [ V_114 ] ) ;
}
if ( V_11 [ V_115 ] ) {
V_112 = true ;
V_111 -> V_116 = F_43 ( V_11 [ V_115 ] ) ;
}
if ( V_11 [ V_117 ] ) {
V_112 = true ;
V_111 -> V_118 = F_43 ( V_11 [ V_117 ] ) ;
}
return V_112 ;
}
static int F_44 ( struct V_4 * V_119 , struct V_52 * V_5 ,
struct V_95 * V_96 [] , struct V_95 * V_11 [] ,
struct V_97 * V_98 )
{
struct V_13 * V_14 = F_20 ( V_5 ) ;
struct V_64 V_65 ;
struct V_110 V_111 ;
T_4 V_100 = 0 ;
if ( F_41 ( V_11 , & V_111 ) ) {
int V_15 = F_45 ( V_14 , & V_111 ) ;
if ( V_15 < 0 )
return V_15 ;
}
F_38 ( V_11 , & V_65 , & V_14 -> V_49 , & V_100 ) ;
return F_46 ( V_5 , V_96 , & V_65 , V_100 ) ;
}
static int F_47 ( struct V_52 * V_5 , struct V_95 * V_96 [] ,
struct V_95 * V_11 [] ,
struct V_97 * V_98 )
{
struct V_13 * V_14 = F_20 ( V_5 ) ;
struct V_64 V_65 ;
struct V_110 V_111 ;
bool V_49 ;
T_4 V_100 = V_14 -> V_100 ;
if ( F_41 ( V_11 , & V_111 ) ) {
int V_15 = F_45 ( V_14 , & V_111 ) ;
if ( V_15 < 0 )
return V_15 ;
}
F_38 ( V_11 , & V_65 , & V_49 , & V_100 ) ;
if ( V_49 )
return - V_75 ;
if ( ( ( V_5 -> V_83 & V_120 ) && ! V_65 . V_10 . V_24 ) ||
( ! ( V_5 -> V_83 & V_120 ) && V_65 . V_10 . V_24 ) )
return - V_75 ;
return F_48 ( V_5 , V_96 , & V_65 , V_100 ) ;
}
static T_5 F_49 ( const struct V_52 * V_5 )
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
static int F_51 ( struct V_1 * V_2 , const struct V_52 * V_5 )
{
struct V_13 * V_39 = F_20 ( V_5 ) ;
struct V_64 * V_121 = & V_39 -> V_28 ;
if ( F_52 ( V_2 , V_101 , V_121 -> V_29 ) ||
F_53 ( V_2 , V_102 , V_121 -> V_10 . V_25 ) ||
F_53 ( V_2 , V_103 , V_121 -> V_10 . V_24 ) ||
F_54 ( V_2 , V_104 , V_121 -> V_10 . V_31 ) ||
F_54 ( V_2 , V_105 , V_121 -> V_10 . V_106 ) ||
F_54 ( V_2 , V_99 , V_121 -> V_10 . V_30 ) ||
F_54 ( V_2 , V_107 ,
! ! ( V_121 -> V_10 . V_73 & F_21 ( V_74 ) ) ) ||
F_52 ( V_2 , V_109 , V_39 -> V_100 ) )
goto V_122;
if ( F_55 ( V_2 , V_113 ,
V_39 -> V_123 . type ) ||
F_56 ( V_2 , V_115 ,
V_39 -> V_123 . V_116 ) ||
F_56 ( V_2 , V_117 ,
V_39 -> V_123 . V_118 ) ||
F_55 ( V_2 , V_114 ,
V_39 -> V_123 . V_83 ) )
goto V_122;
if ( V_39 -> V_49 )
if ( F_57 ( V_2 , V_108 ) )
goto V_122;
return 0 ;
V_122:
return - V_124 ;
}
static int T_6 F_58 ( struct V_4 * V_4 )
{
return F_59 ( V_4 , V_8 , & V_125 , L_1 ) ;
}
static void T_7 F_60 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 , V_8 ) ;
F_61 ( V_7 , & V_125 ) ;
}
static int T_8 F_62 ( void )
{
int V_15 ;
F_63 ( L_2 ) ;
V_15 = F_64 ( & V_126 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_65 ( & V_127 , V_128 ) ;
if ( V_15 < 0 ) {
F_63 ( L_3 , V_129 ) ;
goto V_130;
}
#if F_12 ( V_44 )
V_15 = F_65 ( & V_131 , V_132 ) ;
if ( V_15 < 0 ) {
F_63 ( L_3 , V_129 ) ;
goto V_133;
}
#endif
V_15 = F_66 ( & V_125 ) ;
if ( V_15 < 0 )
goto V_134;
V_18:
return V_15 ;
V_134:
#if F_12 ( V_44 )
F_67 ( & V_131 , V_128 ) ;
V_133:
#endif
F_67 ( & V_127 , V_128 ) ;
V_130:
F_68 ( & V_126 ) ;
goto V_18;
}
static void T_9 F_69 ( void )
{
F_70 ( & V_125 ) ;
if ( F_67 ( & V_127 , V_128 ) )
F_63 ( L_4 , V_129 ) ;
#if F_12 ( V_44 )
if ( F_67 ( & V_131 , V_132 ) )
F_63 ( L_4 , V_129 ) ;
#endif
F_68 ( & V_126 ) ;
}

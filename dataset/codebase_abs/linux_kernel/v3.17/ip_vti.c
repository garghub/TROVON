static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 ,
int V_5 )
{
struct V_6 * V_7 ;
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_10 = F_3 ( V_2 -> V_11 ) ;
struct V_12 * V_13 = F_4 ( V_10 , V_14 ) ;
V_7 = F_5 ( V_13 , V_2 -> V_11 -> V_15 , V_16 ,
V_9 -> V_17 , V_9 -> V_18 , 0 ) ;
if ( V_7 != NULL ) {
if ( ! F_6 ( NULL , V_19 , V_2 ) )
goto V_20;
F_7 ( V_2 ) -> V_7 . V_21 = V_7 ;
V_2 -> V_22 = F_8 ( V_7 -> V_23 . V_24 ) ;
return F_9 ( V_2 , V_3 , V_4 , V_5 ) ;
}
return - V_25 ;
V_20:
F_10 ( V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) -> V_26 = V_27 ;
F_12 ( V_2 ) -> V_28 = F_13 ( struct V_8 , V_18 ) ;
return F_1 ( V_2 , F_2 ( V_2 ) -> V_29 , 0 , 0 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_30 )
{
unsigned short V_26 ;
struct V_31 * V_11 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_6 * V_7 = F_7 ( V_2 ) -> V_7 . V_21 ;
if ( ! V_7 )
return 1 ;
V_11 = V_7 -> V_11 ;
if ( V_30 ) {
V_11 -> V_36 . V_37 ++ ;
V_11 -> V_36 . V_38 ++ ;
return 0 ;
}
V_35 = F_15 ( V_2 ) ;
V_26 = V_35 -> V_39 -> V_40 -> V_26 ;
if ( ! F_16 ( NULL , V_19 , V_2 , V_26 ) )
return - V_41 ;
F_17 ( V_2 , ! F_18 ( V_7 -> V_10 , F_3 ( V_2 -> V_11 ) ) ) ;
V_2 -> V_11 = V_11 ;
V_33 = F_19 ( V_11 -> V_33 ) ;
F_20 ( & V_33 -> V_42 ) ;
V_33 -> V_43 ++ ;
V_33 -> V_44 += V_2 -> V_45 ;
F_21 ( & V_33 -> V_42 ) ;
return 0 ;
}
static bool F_22 ( const struct V_34 * V_35 , T_1 V_46 , T_1 V_47 )
{
T_2 * V_18 = ( T_2 * ) & V_46 ;
T_2 * V_17 = ( T_2 * ) & V_47 ;
if ( ! V_35 || V_35 -> V_48 . V_49 != V_50 ||
V_35 -> V_48 . V_26 != V_27 )
return false ;
if ( ! V_46 )
return F_23 ( V_17 , & V_35 -> V_48 . V_17 , V_27 ) ;
if ( ! F_24 ( V_35 , V_18 , V_17 , V_27 ) )
return false ;
return true ;
}
static T_3 F_25 ( struct V_1 * V_2 , struct V_31 * V_11 ,
struct V_51 * V_52 )
{
struct V_6 * V_7 = F_26 ( V_11 ) ;
struct V_53 * V_23 = & V_7 -> V_23 ;
struct V_54 * V_46 = F_27 ( V_2 ) ;
struct V_31 * V_55 ;
int V_30 ;
if ( ! V_46 ) {
V_11 -> V_36 . V_56 ++ ;
goto V_57;
}
F_28 ( V_46 ) ;
V_46 = F_29 ( V_7 -> V_10 , V_46 , V_52 , NULL , 0 ) ;
if ( F_30 ( V_46 ) ) {
V_11 -> V_36 . V_56 ++ ;
goto V_57;
}
if ( ! F_22 ( V_46 -> V_58 , V_23 -> V_9 . V_18 , V_23 -> V_9 . V_17 ) ) {
V_11 -> V_36 . V_56 ++ ;
F_31 ( V_46 ) ;
goto V_57;
}
V_55 = V_46 -> V_11 ;
if ( V_55 == V_11 ) {
F_31 ( V_46 ) ;
V_11 -> V_36 . V_59 ++ ;
goto V_60;
}
if ( V_7 -> V_61 > 0 ) {
if ( F_32 ( V_62 ,
V_7 -> V_63 + V_64 ) ) {
V_7 -> V_61 -- ;
F_33 ( V_2 ) ;
} else
V_7 -> V_61 = 0 ;
}
F_17 ( V_2 , ! F_18 ( V_7 -> V_10 , F_3 ( V_11 ) ) ) ;
F_34 ( V_2 , V_46 ) ;
V_2 -> V_11 = F_27 ( V_2 ) -> V_11 ;
V_30 = F_35 ( V_2 ) ;
if ( F_36 ( V_30 ) == 0 )
V_30 = V_2 -> V_45 ;
F_37 ( V_30 , & V_11 -> V_36 , V_11 -> V_33 ) ;
return V_65 ;
V_57:
F_33 ( V_2 ) ;
V_60:
V_11 -> V_36 . V_66 ++ ;
F_10 ( V_2 ) ;
return V_65 ;
}
static T_3 F_38 ( struct V_1 * V_2 , struct V_31 * V_11 )
{
struct V_6 * V_7 = F_26 ( V_11 ) ;
struct V_51 V_52 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_2 -> V_22 = F_8 ( V_7 -> V_23 . V_67 ) ;
switch ( V_2 -> V_29 ) {
case F_39 ( V_68 ) :
F_40 ( V_2 , & V_52 , V_27 ) ;
memset ( F_41 ( V_2 ) , 0 , sizeof( * F_41 ( V_2 ) ) ) ;
break;
case F_39 ( V_69 ) :
F_40 ( V_2 , & V_52 , V_70 ) ;
memset ( F_42 ( V_2 ) , 0 , sizeof( * F_42 ( V_2 ) ) ) ;
break;
default:
V_11 -> V_36 . V_66 ++ ;
F_43 ( V_2 ) ;
return V_65 ;
}
return F_25 ( V_2 , V_11 , & V_52 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_4 V_71 )
{
T_1 V_4 ;
T_5 V_22 ;
struct V_34 * V_35 ;
struct V_6 * V_7 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
struct V_10 * V_10 = F_3 ( V_2 -> V_11 ) ;
const struct V_8 * V_9 = ( const struct V_8 * ) V_2 -> V_78 ;
int V_29 = V_9 -> V_29 ;
struct V_12 * V_13 = F_4 ( V_10 , V_14 ) ;
V_7 = F_5 ( V_13 , V_2 -> V_11 -> V_15 , V_16 ,
V_9 -> V_18 , V_9 -> V_17 , 0 ) ;
if ( ! V_7 )
return - 1 ;
V_22 = F_8 ( V_7 -> V_23 . V_67 ) ;
switch ( V_29 ) {
case V_79 :
V_73 = (struct V_72 * ) ( V_2 -> V_78 + ( V_9 -> V_80 << 2 ) ) ;
V_4 = V_73 -> V_4 ;
break;
case V_81 :
V_75 = (struct V_74 * ) ( V_2 -> V_78 + ( V_9 -> V_80 << 2 ) ) ;
V_4 = V_75 -> V_4 ;
break;
case V_82 :
V_77 = (struct V_76 * ) ( V_2 -> V_78 + ( V_9 -> V_80 << 2 ) ) ;
V_4 = F_45 ( F_46 ( V_77 -> V_83 ) ) ;
break;
default:
return 0 ;
}
switch ( F_47 ( V_2 ) -> type ) {
case V_84 :
if ( F_47 ( V_2 ) -> V_85 != V_86 )
return 0 ;
case V_87 :
break;
default:
return 0 ;
}
V_35 = F_48 ( V_10 , V_22 , ( const T_2 * ) & V_9 -> V_18 ,
V_4 , V_29 , V_27 ) ;
if ( ! V_35 )
return 0 ;
if ( F_47 ( V_2 ) -> type == V_84 )
F_49 ( V_2 , V_10 , V_71 , 0 , 0 , V_29 , 0 ) ;
else
F_50 ( V_2 , V_10 , 0 , 0 , V_29 , 0 ) ;
F_51 ( V_35 ) ;
return 0 ;
}
static int
F_52 ( struct V_31 * V_11 , struct V_88 * V_89 , int V_90 )
{
int V_30 = 0 ;
struct V_53 V_91 ;
if ( F_53 ( & V_91 , V_89 -> V_92 . V_93 , sizeof( V_91 ) ) )
return - V_94 ;
if ( V_90 == V_95 || V_90 == V_96 ) {
if ( V_91 . V_9 . V_97 != 4 || V_91 . V_9 . V_29 != V_98 ||
V_91 . V_9 . V_80 != 5 )
return - V_25 ;
}
if ( ! ( V_91 . V_99 & V_100 ) )
V_91 . V_24 = 0 ;
if ( ! ( V_91 . V_101 & V_100 ) )
V_91 . V_67 = 0 ;
V_91 . V_99 = V_102 ;
V_30 = F_54 ( V_11 , & V_91 , V_90 ) ;
if ( V_30 )
return V_30 ;
if ( V_90 != V_103 ) {
V_91 . V_99 |= V_100 ;
V_91 . V_101 |= V_100 ;
}
if ( F_55 ( V_89 -> V_92 . V_93 , & V_91 , sizeof( V_91 ) ) )
return - V_94 ;
return 0 ;
}
static void F_56 ( struct V_31 * V_11 )
{
V_11 -> V_104 = & V_105 ;
V_11 -> type = V_106 ;
F_57 ( V_11 , V_14 ) ;
}
static int F_58 ( struct V_31 * V_11 )
{
struct V_6 * V_7 = F_26 ( V_11 ) ;
struct V_8 * V_9 = & V_7 -> V_23 . V_9 ;
memcpy ( V_11 -> V_107 , & V_9 -> V_17 , 4 ) ;
memcpy ( V_11 -> V_108 , & V_9 -> V_18 , 4 ) ;
V_11 -> V_109 = V_110 + sizeof( struct V_8 ) ;
V_11 -> V_111 = V_112 ;
V_11 -> V_113 = V_114 ;
V_11 -> V_115 = 0 ;
V_11 -> V_116 = 4 ;
V_11 -> V_117 |= V_118 ;
V_11 -> V_119 &= ~ V_120 ;
return F_59 ( V_11 ) ;
}
static void T_6 F_60 ( struct V_31 * V_11 )
{
struct V_6 * V_7 = F_26 ( V_11 ) ;
struct V_8 * V_9 = & V_7 -> V_23 . V_9 ;
V_9 -> V_97 = 4 ;
V_9 -> V_29 = V_98 ;
V_9 -> V_80 = 5 ;
}
static int T_6 F_61 ( struct V_10 * V_10 )
{
int V_30 ;
struct V_12 * V_13 ;
V_30 = F_62 ( V_10 , V_14 , & V_121 , L_1 ) ;
if ( V_30 )
return V_30 ;
V_13 = F_4 ( V_10 , V_14 ) ;
F_60 ( V_13 -> V_122 ) ;
return 0 ;
}
static void T_7 F_63 ( struct V_10 * V_10 )
{
struct V_12 * V_13 = F_4 ( V_10 , V_14 ) ;
F_64 ( V_13 , & V_121 ) ;
}
static int F_65 ( struct V_123 * V_124 [] , struct V_123 * V_78 [] )
{
return 0 ;
}
static void F_66 ( struct V_123 * V_78 [] ,
struct V_53 * V_23 )
{
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_9 . V_29 = V_98 ;
if ( ! V_78 )
return;
V_23 -> V_99 = V_102 ;
if ( V_78 [ V_125 ] )
V_23 -> V_126 = F_67 ( V_78 [ V_125 ] ) ;
if ( V_78 [ V_127 ] )
V_23 -> V_24 = F_68 ( V_78 [ V_127 ] ) ;
if ( V_78 [ V_128 ] )
V_23 -> V_67 = F_68 ( V_78 [ V_128 ] ) ;
if ( V_78 [ V_129 ] )
V_23 -> V_9 . V_17 = F_68 ( V_78 [ V_129 ] ) ;
if ( V_78 [ V_130 ] )
V_23 -> V_9 . V_18 = F_68 ( V_78 [ V_130 ] ) ;
}
static int F_69 ( struct V_10 * V_131 , struct V_31 * V_11 ,
struct V_123 * V_124 [] , struct V_123 * V_78 [] )
{
struct V_53 V_23 ;
F_66 ( V_78 , & V_23 ) ;
return F_70 ( V_11 , V_124 , & V_23 ) ;
}
static int F_71 ( struct V_31 * V_11 , struct V_123 * V_124 [] ,
struct V_123 * V_78 [] )
{
struct V_53 V_91 ;
F_66 ( V_78 , & V_91 ) ;
return F_72 ( V_11 , V_124 , & V_91 ) ;
}
static T_8 F_73 ( const struct V_31 * V_11 )
{
return
F_74 ( 4 ) +
F_74 ( 4 ) +
F_74 ( 4 ) +
F_74 ( 4 ) +
F_74 ( 4 ) +
0 ;
}
static int F_75 ( struct V_1 * V_2 , const struct V_31 * V_11 )
{
struct V_6 * V_132 = F_26 ( V_11 ) ;
struct V_53 * V_91 = & V_132 -> V_23 ;
F_76 ( V_2 , V_125 , V_91 -> V_126 ) ;
F_77 ( V_2 , V_127 , V_91 -> V_24 ) ;
F_77 ( V_2 , V_128 , V_91 -> V_67 ) ;
F_77 ( V_2 , V_129 , V_91 -> V_9 . V_17 ) ;
F_77 ( V_2 , V_130 , V_91 -> V_9 . V_18 ) ;
return 0 ;
}
static int T_9 F_78 ( void )
{
const char * V_133 ;
int V_30 ;
F_79 ( L_2 ) ;
V_133 = L_3 ;
V_30 = F_80 ( & V_134 ) ;
if ( V_30 < 0 )
goto V_135;
V_133 = L_4 ;
V_30 = F_81 ( & V_136 , V_79 ) ;
if ( V_30 < 0 )
goto V_137;
V_30 = F_81 ( & V_138 , V_81 ) ;
if ( V_30 < 0 )
goto V_139;
V_30 = F_81 ( & V_140 , V_82 ) ;
if ( V_30 < 0 )
goto V_141;
V_133 = L_5 ;
V_30 = F_82 ( & V_121 ) ;
if ( V_30 < 0 )
goto V_142;
return V_30 ;
V_142:
F_83 ( & V_140 , V_82 ) ;
V_141:
F_83 ( & V_138 , V_81 ) ;
V_139:
F_83 ( & V_136 , V_79 ) ;
V_137:
F_84 ( & V_134 ) ;
V_135:
F_85 ( L_6 , V_133 ) ;
return V_30 ;
}
static void T_10 F_86 ( void )
{
F_87 ( & V_121 ) ;
F_83 ( & V_140 , V_82 ) ;
F_83 ( & V_138 , V_81 ) ;
F_83 ( & V_136 , V_79 ) ;
F_84 ( & V_134 ) ;
}

static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 ,
int V_5 )
{
struct V_6 * V_7 ;
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_10 = F_3 ( V_2 -> V_11 ) ;
struct V_12 * V_13 = F_4 ( V_10 , V_14 ) ;
V_7 = F_5 ( V_13 , V_2 -> V_11 -> V_15 , V_16 ,
V_9 -> V_17 , V_9 -> V_18 , 0 ) ;
if ( V_7 ) {
if ( ! F_6 ( NULL , V_19 , V_2 ) )
goto V_20;
F_7 ( V_2 ) -> V_7 . V_21 = V_7 ;
return F_8 ( V_2 , V_3 , V_4 , V_5 ) ;
}
return - V_22 ;
V_20:
F_9 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) -> V_23 = V_24 ;
F_11 ( V_2 ) -> V_25 = F_12 ( struct V_8 , V_18 ) ;
return F_1 ( V_2 , F_2 ( V_2 ) -> V_26 , 0 , 0 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_27 )
{
unsigned short V_23 ;
struct V_28 * V_11 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_6 * V_7 = F_7 ( V_2 ) -> V_7 . V_21 ;
T_2 V_33 = V_2 -> V_34 ;
int V_35 ;
if ( ! V_7 )
return 1 ;
V_11 = V_7 -> V_11 ;
if ( V_27 ) {
V_11 -> V_36 . V_37 ++ ;
V_11 -> V_36 . V_38 ++ ;
return 0 ;
}
V_32 = F_14 ( V_2 ) ;
V_23 = V_32 -> V_39 -> V_40 -> V_23 ;
V_2 -> V_34 = F_15 ( V_7 -> V_41 . V_42 ) ;
V_35 = F_16 ( NULL , V_19 , V_2 , V_23 ) ;
V_2 -> V_34 = V_33 ;
if ( ! V_35 )
return - V_43 ;
F_17 ( V_2 , ! F_18 ( V_7 -> V_10 , F_3 ( V_2 -> V_11 ) ) ) ;
V_2 -> V_11 = V_11 ;
V_30 = F_19 ( V_11 -> V_30 ) ;
F_20 ( & V_30 -> V_44 ) ;
V_30 -> V_45 ++ ;
V_30 -> V_46 += V_2 -> V_47 ;
F_21 ( & V_30 -> V_44 ) ;
return 0 ;
}
static bool F_22 ( const struct V_31 * V_32 , T_1 V_48 , T_1 V_49 )
{
T_3 * V_18 = ( T_3 * ) & V_48 ;
T_3 * V_17 = ( T_3 * ) & V_49 ;
if ( ! V_32 || V_32 -> V_50 . V_51 != V_52 ||
V_32 -> V_50 . V_23 != V_24 )
return false ;
if ( ! V_48 )
return F_23 ( V_17 , & V_32 -> V_50 . V_17 , V_24 ) ;
if ( ! F_24 ( V_32 , V_18 , V_17 , V_24 ) )
return false ;
return true ;
}
static T_4 F_25 ( struct V_1 * V_2 , struct V_28 * V_11 ,
struct V_53 * V_54 )
{
struct V_6 * V_7 = F_26 ( V_11 ) ;
struct V_55 * V_41 = & V_7 -> V_41 ;
struct V_56 * V_48 = F_27 ( V_2 ) ;
struct V_28 * V_57 ;
int V_27 ;
if ( ! V_48 ) {
V_11 -> V_36 . V_58 ++ ;
goto V_59;
}
F_28 ( V_48 ) ;
V_48 = F_29 ( V_7 -> V_10 , V_48 , V_54 , NULL , 0 ) ;
if ( F_30 ( V_48 ) ) {
V_11 -> V_36 . V_58 ++ ;
goto V_59;
}
if ( ! F_22 ( V_48 -> V_60 , V_41 -> V_9 . V_18 , V_41 -> V_9 . V_17 ) ) {
V_11 -> V_36 . V_58 ++ ;
F_31 ( V_48 ) ;
goto V_59;
}
V_57 = V_48 -> V_11 ;
if ( V_57 == V_11 ) {
F_31 ( V_48 ) ;
V_11 -> V_36 . V_61 ++ ;
goto V_62;
}
if ( V_7 -> V_63 > 0 ) {
if ( F_32 ( V_64 ,
V_7 -> V_65 + V_66 ) ) {
V_7 -> V_63 -- ;
F_33 ( V_2 ) ;
} else
V_7 -> V_63 = 0 ;
}
F_17 ( V_2 , ! F_18 ( V_7 -> V_10 , F_3 ( V_11 ) ) ) ;
F_34 ( V_2 , V_48 ) ;
V_2 -> V_11 = F_27 ( V_2 ) -> V_11 ;
V_27 = F_35 ( V_2 ) ;
if ( F_36 ( V_27 ) == 0 )
V_27 = V_2 -> V_47 ;
F_37 ( V_27 , & V_11 -> V_36 , V_11 -> V_30 ) ;
return V_67 ;
V_59:
F_33 ( V_2 ) ;
V_62:
V_11 -> V_36 . V_68 ++ ;
F_9 ( V_2 ) ;
return V_67 ;
}
static T_4 F_38 ( struct V_1 * V_2 , struct V_28 * V_11 )
{
struct V_6 * V_7 = F_26 ( V_11 ) ;
struct V_53 V_54 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
switch ( V_2 -> V_26 ) {
case F_39 ( V_69 ) :
F_40 ( V_2 , & V_54 , V_24 ) ;
memset ( F_41 ( V_2 ) , 0 , sizeof( * F_41 ( V_2 ) ) ) ;
break;
case F_39 ( V_70 ) :
F_40 ( V_2 , & V_54 , V_71 ) ;
memset ( F_42 ( V_2 ) , 0 , sizeof( * F_42 ( V_2 ) ) ) ;
break;
default:
V_11 -> V_36 . V_68 ++ ;
F_43 ( V_2 ) ;
return V_67 ;
}
V_54 . V_72 = F_15 ( V_7 -> V_41 . V_73 ) ;
return F_25 ( V_2 , V_11 , & V_54 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_2 V_74 )
{
T_1 V_4 ;
T_5 V_34 ;
struct V_31 * V_32 ;
struct V_6 * V_7 ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
struct V_10 * V_10 = F_3 ( V_2 -> V_11 ) ;
const struct V_8 * V_9 = ( const struct V_8 * ) V_2 -> V_81 ;
int V_26 = V_9 -> V_26 ;
struct V_12 * V_13 = F_4 ( V_10 , V_14 ) ;
V_7 = F_5 ( V_13 , V_2 -> V_11 -> V_15 , V_16 ,
V_9 -> V_18 , V_9 -> V_17 , 0 ) ;
if ( ! V_7 )
return - 1 ;
V_34 = F_15 ( V_7 -> V_41 . V_73 ) ;
switch ( V_26 ) {
case V_82 :
V_76 = (struct V_75 * ) ( V_2 -> V_81 + ( V_9 -> V_83 << 2 ) ) ;
V_4 = V_76 -> V_4 ;
break;
case V_84 :
V_78 = (struct V_77 * ) ( V_2 -> V_81 + ( V_9 -> V_83 << 2 ) ) ;
V_4 = V_78 -> V_4 ;
break;
case V_85 :
V_80 = (struct V_79 * ) ( V_2 -> V_81 + ( V_9 -> V_83 << 2 ) ) ;
V_4 = F_45 ( F_46 ( V_80 -> V_86 ) ) ;
break;
default:
return 0 ;
}
switch ( F_47 ( V_2 ) -> type ) {
case V_87 :
if ( F_47 ( V_2 ) -> V_88 != V_89 )
return 0 ;
case V_90 :
break;
default:
return 0 ;
}
V_32 = F_48 ( V_10 , V_34 , ( const T_3 * ) & V_9 -> V_18 ,
V_4 , V_26 , V_24 ) ;
if ( ! V_32 )
return 0 ;
if ( F_47 ( V_2 ) -> type == V_87 )
F_49 ( V_2 , V_10 , V_74 , 0 , 0 , V_26 , 0 ) ;
else
F_50 ( V_2 , V_10 , 0 , 0 , V_26 , 0 ) ;
F_51 ( V_32 ) ;
return 0 ;
}
static int
F_52 ( struct V_28 * V_11 , struct V_91 * V_92 , int V_93 )
{
int V_27 = 0 ;
struct V_55 V_94 ;
if ( F_53 ( & V_94 , V_92 -> V_95 . V_96 , sizeof( V_94 ) ) )
return - V_97 ;
if ( V_93 == V_98 || V_93 == V_99 ) {
if ( V_94 . V_9 . V_100 != 4 || V_94 . V_9 . V_26 != V_101 ||
V_94 . V_9 . V_83 != 5 )
return - V_22 ;
}
if ( ! ( V_94 . V_102 & V_103 ) )
V_94 . V_42 = 0 ;
if ( ! ( V_94 . V_104 & V_103 ) )
V_94 . V_73 = 0 ;
V_94 . V_102 = V_105 ;
V_27 = F_54 ( V_11 , & V_94 , V_93 ) ;
if ( V_27 )
return V_27 ;
if ( V_93 != V_106 ) {
V_94 . V_102 |= V_103 ;
V_94 . V_104 |= V_103 ;
}
if ( F_55 ( V_92 -> V_95 . V_96 , & V_94 , sizeof( V_94 ) ) )
return - V_97 ;
return 0 ;
}
static void F_56 ( struct V_28 * V_11 )
{
V_11 -> V_107 = & V_108 ;
V_11 -> type = V_109 ;
F_57 ( V_11 , V_14 ) ;
}
static int F_58 ( struct V_28 * V_11 )
{
struct V_6 * V_7 = F_26 ( V_11 ) ;
struct V_8 * V_9 = & V_7 -> V_41 . V_9 ;
memcpy ( V_11 -> V_110 , & V_9 -> V_17 , 4 ) ;
memcpy ( V_11 -> V_111 , & V_9 -> V_18 , 4 ) ;
V_11 -> V_112 = V_113 + sizeof( struct V_8 ) ;
V_11 -> V_114 = V_115 ;
V_11 -> V_116 = V_117 ;
V_11 -> V_118 = 4 ;
V_11 -> V_119 |= V_120 ;
F_59 ( V_11 ) ;
return F_60 ( V_11 ) ;
}
static void T_6 F_61 ( struct V_28 * V_11 )
{
struct V_6 * V_7 = F_26 ( V_11 ) ;
struct V_8 * V_9 = & V_7 -> V_41 . V_9 ;
V_9 -> V_100 = 4 ;
V_9 -> V_26 = V_101 ;
V_9 -> V_83 = 5 ;
}
static int T_6 F_62 ( struct V_10 * V_10 )
{
int V_27 ;
struct V_12 * V_13 ;
V_27 = F_63 ( V_10 , V_14 , & V_121 , L_1 ) ;
if ( V_27 )
return V_27 ;
V_13 = F_4 ( V_10 , V_14 ) ;
F_61 ( V_13 -> V_122 ) ;
return 0 ;
}
static void T_7 F_64 ( struct V_10 * V_10 )
{
struct V_12 * V_13 = F_4 ( V_10 , V_14 ) ;
F_65 ( V_13 , & V_121 ) ;
}
static int F_66 ( struct V_123 * V_124 [] , struct V_123 * V_81 [] )
{
return 0 ;
}
static void F_67 ( struct V_123 * V_81 [] ,
struct V_55 * V_41 )
{
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_9 . V_26 = V_101 ;
if ( ! V_81 )
return;
V_41 -> V_102 = V_105 ;
if ( V_81 [ V_125 ] )
V_41 -> V_126 = F_68 ( V_81 [ V_125 ] ) ;
if ( V_81 [ V_127 ] )
V_41 -> V_42 = F_69 ( V_81 [ V_127 ] ) ;
if ( V_81 [ V_128 ] )
V_41 -> V_73 = F_69 ( V_81 [ V_128 ] ) ;
if ( V_81 [ V_129 ] )
V_41 -> V_9 . V_17 = F_70 ( V_81 [ V_129 ] ) ;
if ( V_81 [ V_130 ] )
V_41 -> V_9 . V_18 = F_70 ( V_81 [ V_130 ] ) ;
}
static int F_71 ( struct V_10 * V_131 , struct V_28 * V_11 ,
struct V_123 * V_124 [] , struct V_123 * V_81 [] )
{
struct V_55 V_41 ;
F_67 ( V_81 , & V_41 ) ;
return F_72 ( V_11 , V_124 , & V_41 ) ;
}
static int F_73 ( struct V_28 * V_11 , struct V_123 * V_124 [] ,
struct V_123 * V_81 [] )
{
struct V_55 V_94 ;
F_67 ( V_81 , & V_94 ) ;
return F_74 ( V_11 , V_124 , & V_94 ) ;
}
static T_8 F_75 ( const struct V_28 * V_11 )
{
return
F_76 ( 4 ) +
F_76 ( 4 ) +
F_76 ( 4 ) +
F_76 ( 4 ) +
F_76 ( 4 ) +
0 ;
}
static int F_77 ( struct V_1 * V_2 , const struct V_28 * V_11 )
{
struct V_6 * V_132 = F_26 ( V_11 ) ;
struct V_55 * V_94 = & V_132 -> V_41 ;
F_78 ( V_2 , V_125 , V_94 -> V_126 ) ;
F_79 ( V_2 , V_127 , V_94 -> V_42 ) ;
F_79 ( V_2 , V_128 , V_94 -> V_73 ) ;
F_80 ( V_2 , V_129 , V_94 -> V_9 . V_17 ) ;
F_80 ( V_2 , V_130 , V_94 -> V_9 . V_18 ) ;
return 0 ;
}
static int T_9 F_81 ( void )
{
const char * V_133 ;
int V_27 ;
F_82 ( L_2 ) ;
V_133 = L_3 ;
V_27 = F_83 ( & V_134 ) ;
if ( V_27 < 0 )
goto V_135;
V_133 = L_4 ;
V_27 = F_84 ( & V_136 , V_82 ) ;
if ( V_27 < 0 )
goto V_137;
V_27 = F_84 ( & V_138 , V_84 ) ;
if ( V_27 < 0 )
goto V_139;
V_27 = F_84 ( & V_140 , V_85 ) ;
if ( V_27 < 0 )
goto V_141;
V_133 = L_5 ;
V_27 = F_85 ( & V_121 ) ;
if ( V_27 < 0 )
goto V_142;
return V_27 ;
V_142:
F_86 ( & V_140 , V_85 ) ;
V_141:
F_86 ( & V_138 , V_84 ) ;
V_139:
F_86 ( & V_136 , V_82 ) ;
V_137:
F_87 ( & V_134 ) ;
V_135:
F_88 ( L_6 , V_133 ) ;
return V_27 ;
}
static void T_10 F_89 ( void )
{
F_90 ( & V_121 ) ;
F_86 ( & V_140 , V_85 ) ;
F_86 ( & V_138 , V_84 ) ;
F_86 ( & V_136 , V_82 ) ;
F_87 ( & V_134 ) ;
}

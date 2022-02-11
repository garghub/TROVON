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
V_27 = F_35 ( V_7 -> V_10 , V_2 -> V_67 , V_2 ) ;
if ( F_36 ( V_27 ) == 0 )
V_27 = V_2 -> V_47 ;
F_37 ( V_27 , & V_11 -> V_36 , V_11 -> V_30 ) ;
return V_68 ;
V_59:
F_33 ( V_2 ) ;
V_62:
V_11 -> V_36 . V_69 ++ ;
F_9 ( V_2 ) ;
return V_68 ;
}
static T_4 F_38 ( struct V_1 * V_2 , struct V_28 * V_11 )
{
struct V_6 * V_7 = F_26 ( V_11 ) ;
struct V_53 V_54 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
switch ( V_2 -> V_26 ) {
case F_39 ( V_70 ) :
F_40 ( V_2 , & V_54 , V_24 ) ;
memset ( F_41 ( V_2 ) , 0 , sizeof( * F_41 ( V_2 ) ) ) ;
break;
case F_39 ( V_71 ) :
F_40 ( V_2 , & V_54 , V_72 ) ;
memset ( F_42 ( V_2 ) , 0 , sizeof( * F_42 ( V_2 ) ) ) ;
break;
default:
V_11 -> V_36 . V_69 ++ ;
F_43 ( V_2 ) ;
return V_68 ;
}
V_54 . V_73 = F_15 ( V_7 -> V_41 . V_74 ) ;
return F_25 ( V_2 , V_11 , & V_54 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_2 V_75 )
{
T_1 V_4 ;
T_5 V_34 ;
struct V_31 * V_32 ;
struct V_6 * V_7 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_10 * V_10 = F_3 ( V_2 -> V_11 ) ;
const struct V_8 * V_9 = ( const struct V_8 * ) V_2 -> V_82 ;
int V_26 = V_9 -> V_26 ;
struct V_12 * V_13 = F_4 ( V_10 , V_14 ) ;
V_7 = F_5 ( V_13 , V_2 -> V_11 -> V_15 , V_16 ,
V_9 -> V_18 , V_9 -> V_17 , 0 ) ;
if ( ! V_7 )
return - 1 ;
V_34 = F_15 ( V_7 -> V_41 . V_74 ) ;
switch ( V_26 ) {
case V_83 :
V_77 = (struct V_76 * ) ( V_2 -> V_82 + ( V_9 -> V_84 << 2 ) ) ;
V_4 = V_77 -> V_4 ;
break;
case V_85 :
V_79 = (struct V_78 * ) ( V_2 -> V_82 + ( V_9 -> V_84 << 2 ) ) ;
V_4 = V_79 -> V_4 ;
break;
case V_86 :
V_81 = (struct V_80 * ) ( V_2 -> V_82 + ( V_9 -> V_84 << 2 ) ) ;
V_4 = F_45 ( F_46 ( V_81 -> V_87 ) ) ;
break;
default:
return 0 ;
}
switch ( F_47 ( V_2 ) -> type ) {
case V_88 :
if ( F_47 ( V_2 ) -> V_89 != V_90 )
return 0 ;
case V_91 :
break;
default:
return 0 ;
}
V_32 = F_48 ( V_10 , V_34 , ( const T_3 * ) & V_9 -> V_18 ,
V_4 , V_26 , V_24 ) ;
if ( ! V_32 )
return 0 ;
if ( F_47 ( V_2 ) -> type == V_88 )
F_49 ( V_2 , V_10 , V_75 , 0 , 0 , V_26 , 0 ) ;
else
F_50 ( V_2 , V_10 , 0 , 0 , V_26 , 0 ) ;
F_51 ( V_32 ) ;
return 0 ;
}
static int
F_52 ( struct V_28 * V_11 , struct V_92 * V_93 , int V_94 )
{
int V_27 = 0 ;
struct V_55 V_95 ;
if ( F_53 ( & V_95 , V_93 -> V_96 . V_97 , sizeof( V_95 ) ) )
return - V_98 ;
if ( V_94 == V_99 || V_94 == V_100 ) {
if ( V_95 . V_9 . V_101 != 4 || V_95 . V_9 . V_26 != V_102 ||
V_95 . V_9 . V_84 != 5 )
return - V_22 ;
}
if ( ! ( V_95 . V_103 & V_104 ) )
V_95 . V_42 = 0 ;
if ( ! ( V_95 . V_105 & V_104 ) )
V_95 . V_74 = 0 ;
V_95 . V_103 = V_106 ;
V_27 = F_54 ( V_11 , & V_95 , V_94 ) ;
if ( V_27 )
return V_27 ;
if ( V_94 != V_107 ) {
V_95 . V_103 |= V_104 ;
V_95 . V_105 |= V_104 ;
}
if ( F_55 ( V_93 -> V_96 . V_97 , & V_95 , sizeof( V_95 ) ) )
return - V_98 ;
return 0 ;
}
static void F_56 ( struct V_28 * V_11 )
{
V_11 -> V_108 = & V_109 ;
V_11 -> type = V_110 ;
F_57 ( V_11 , V_14 ) ;
}
static int F_58 ( struct V_28 * V_11 )
{
struct V_6 * V_7 = F_26 ( V_11 ) ;
struct V_8 * V_9 = & V_7 -> V_41 . V_9 ;
memcpy ( V_11 -> V_111 , & V_9 -> V_17 , 4 ) ;
memcpy ( V_11 -> V_112 , & V_9 -> V_18 , 4 ) ;
V_11 -> V_113 = V_114 + sizeof( struct V_8 ) ;
V_11 -> V_115 = V_116 ;
V_11 -> V_117 = V_118 ;
V_11 -> V_119 = 4 ;
V_11 -> V_120 |= V_121 ;
F_59 ( V_11 ) ;
return F_60 ( V_11 ) ;
}
static void T_6 F_61 ( struct V_28 * V_11 )
{
struct V_6 * V_7 = F_26 ( V_11 ) ;
struct V_8 * V_9 = & V_7 -> V_41 . V_9 ;
V_9 -> V_101 = 4 ;
V_9 -> V_26 = V_102 ;
V_9 -> V_84 = 5 ;
}
static int T_6 F_62 ( struct V_10 * V_10 )
{
int V_27 ;
struct V_12 * V_13 ;
V_27 = F_63 ( V_10 , V_14 , & V_122 , L_1 ) ;
if ( V_27 )
return V_27 ;
V_13 = F_4 ( V_10 , V_14 ) ;
F_61 ( V_13 -> V_123 ) ;
return 0 ;
}
static void T_7 F_64 ( struct V_10 * V_10 )
{
struct V_12 * V_13 = F_4 ( V_10 , V_14 ) ;
F_65 ( V_13 , & V_122 ) ;
}
static int F_66 ( struct V_124 * V_125 [] , struct V_124 * V_82 [] )
{
return 0 ;
}
static void F_67 ( struct V_124 * V_82 [] ,
struct V_55 * V_41 )
{
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_9 . V_26 = V_102 ;
if ( ! V_82 )
return;
V_41 -> V_103 = V_106 ;
if ( V_82 [ V_126 ] )
V_41 -> V_127 = F_68 ( V_82 [ V_126 ] ) ;
if ( V_82 [ V_128 ] )
V_41 -> V_42 = F_69 ( V_82 [ V_128 ] ) ;
if ( V_82 [ V_129 ] )
V_41 -> V_74 = F_69 ( V_82 [ V_129 ] ) ;
if ( V_82 [ V_130 ] )
V_41 -> V_9 . V_17 = F_70 ( V_82 [ V_130 ] ) ;
if ( V_82 [ V_131 ] )
V_41 -> V_9 . V_18 = F_70 ( V_82 [ V_131 ] ) ;
}
static int F_71 ( struct V_10 * V_132 , struct V_28 * V_11 ,
struct V_124 * V_125 [] , struct V_124 * V_82 [] )
{
struct V_55 V_41 ;
F_67 ( V_82 , & V_41 ) ;
return F_72 ( V_11 , V_125 , & V_41 ) ;
}
static int F_73 ( struct V_28 * V_11 , struct V_124 * V_125 [] ,
struct V_124 * V_82 [] )
{
struct V_55 V_95 ;
F_67 ( V_82 , & V_95 ) ;
return F_74 ( V_11 , V_125 , & V_95 ) ;
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
struct V_6 * V_133 = F_26 ( V_11 ) ;
struct V_55 * V_95 = & V_133 -> V_41 ;
F_78 ( V_2 , V_126 , V_95 -> V_127 ) ;
F_79 ( V_2 , V_128 , V_95 -> V_42 ) ;
F_79 ( V_2 , V_129 , V_95 -> V_74 ) ;
F_80 ( V_2 , V_130 , V_95 -> V_9 . V_17 ) ;
F_80 ( V_2 , V_131 , V_95 -> V_9 . V_18 ) ;
return 0 ;
}
static int T_9 F_81 ( void )
{
const char * V_134 ;
int V_27 ;
F_82 ( L_2 ) ;
V_134 = L_3 ;
V_27 = F_83 ( & V_135 ) ;
if ( V_27 < 0 )
goto V_136;
V_134 = L_4 ;
V_27 = F_84 ( & V_137 , V_83 ) ;
if ( V_27 < 0 )
goto V_138;
V_27 = F_84 ( & V_139 , V_85 ) ;
if ( V_27 < 0 )
goto V_140;
V_27 = F_84 ( & V_141 , V_86 ) ;
if ( V_27 < 0 )
goto V_142;
V_134 = L_5 ;
V_27 = F_85 ( & V_122 ) ;
if ( V_27 < 0 )
goto V_143;
return V_27 ;
V_143:
F_86 ( & V_141 , V_86 ) ;
V_142:
F_86 ( & V_139 , V_85 ) ;
V_140:
F_86 ( & V_137 , V_83 ) ;
V_138:
F_87 ( & V_135 ) ;
V_136:
F_88 ( L_6 , V_134 ) ;
return V_27 ;
}
static void T_10 F_89 ( void )
{
F_90 ( & V_122 ) ;
F_86 ( & V_141 , V_86 ) ;
F_86 ( & V_139 , V_85 ) ;
F_86 ( & V_137 , V_83 ) ;
F_87 ( & V_135 ) ;
}

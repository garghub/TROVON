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
int V_58 ;
if ( ! V_48 ) {
V_11 -> V_36 . V_59 ++ ;
goto V_60;
}
F_28 ( V_48 ) ;
V_48 = F_29 ( V_7 -> V_10 , V_48 , V_54 , NULL , 0 ) ;
if ( F_30 ( V_48 ) ) {
V_11 -> V_36 . V_59 ++ ;
goto V_60;
}
if ( ! F_22 ( V_48 -> V_61 , V_41 -> V_9 . V_18 , V_41 -> V_9 . V_17 ) ) {
V_11 -> V_36 . V_59 ++ ;
F_31 ( V_48 ) ;
goto V_60;
}
V_57 = V_48 -> V_11 ;
if ( V_57 == V_11 ) {
F_31 ( V_48 ) ;
V_11 -> V_36 . V_62 ++ ;
goto V_63;
}
if ( V_7 -> V_64 > 0 ) {
if ( F_32 ( V_65 ,
V_7 -> V_66 + V_67 ) ) {
V_7 -> V_64 -- ;
F_33 ( V_2 ) ;
} else
V_7 -> V_64 = 0 ;
}
V_58 = F_34 ( V_48 ) ;
if ( V_2 -> V_47 > V_58 ) {
F_27 ( V_2 ) -> V_68 -> V_69 ( F_27 ( V_2 ) , NULL , V_2 , V_58 ) ;
if ( V_2 -> V_26 == F_35 ( V_70 ) ) {
F_36 ( V_2 , V_71 , V_72 ,
F_37 ( V_58 ) ) ;
} else {
if ( V_58 < V_73 )
V_58 = V_73 ;
F_38 ( V_2 , V_74 , 0 , V_58 ) ;
}
F_31 ( V_48 ) ;
goto V_63;
}
F_17 ( V_2 , ! F_18 ( V_7 -> V_10 , F_3 ( V_11 ) ) ) ;
F_39 ( V_2 , V_48 ) ;
V_2 -> V_11 = F_27 ( V_2 ) -> V_11 ;
V_27 = F_40 ( V_7 -> V_10 , V_2 -> V_75 , V_2 ) ;
if ( F_41 ( V_27 ) == 0 )
V_27 = V_2 -> V_47 ;
F_42 ( V_11 , V_27 ) ;
return V_76 ;
V_60:
F_33 ( V_2 ) ;
V_63:
V_11 -> V_36 . V_77 ++ ;
F_9 ( V_2 ) ;
return V_76 ;
}
static T_4 F_43 ( struct V_1 * V_2 , struct V_28 * V_11 )
{
struct V_6 * V_7 = F_26 ( V_11 ) ;
struct V_53 V_54 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
switch ( V_2 -> V_26 ) {
case F_35 ( V_70 ) :
F_44 ( V_2 , & V_54 , V_24 ) ;
memset ( F_45 ( V_2 ) , 0 , sizeof( * F_45 ( V_2 ) ) ) ;
break;
case F_35 ( V_78 ) :
F_44 ( V_2 , & V_54 , V_79 ) ;
memset ( F_46 ( V_2 ) , 0 , sizeof( * F_46 ( V_2 ) ) ) ;
break;
default:
V_11 -> V_36 . V_77 ++ ;
F_47 ( V_2 ) ;
return V_76 ;
}
V_54 . V_80 = F_15 ( V_7 -> V_41 . V_81 ) ;
return F_25 ( V_2 , V_11 , & V_54 ) ;
}
static int F_48 ( struct V_1 * V_2 , T_2 V_82 )
{
T_1 V_4 ;
T_5 V_34 ;
struct V_31 * V_32 ;
struct V_6 * V_7 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
struct V_10 * V_10 = F_3 ( V_2 -> V_11 ) ;
const struct V_8 * V_9 = ( const struct V_8 * ) V_2 -> V_89 ;
int V_26 = V_9 -> V_26 ;
struct V_12 * V_13 = F_4 ( V_10 , V_14 ) ;
V_7 = F_5 ( V_13 , V_2 -> V_11 -> V_15 , V_16 ,
V_9 -> V_18 , V_9 -> V_17 , 0 ) ;
if ( ! V_7 )
return - 1 ;
V_34 = F_15 ( V_7 -> V_41 . V_81 ) ;
switch ( V_26 ) {
case V_90 :
V_84 = (struct V_83 * ) ( V_2 -> V_89 + ( V_9 -> V_91 << 2 ) ) ;
V_4 = V_84 -> V_4 ;
break;
case V_92 :
V_86 = (struct V_85 * ) ( V_2 -> V_89 + ( V_9 -> V_91 << 2 ) ) ;
V_4 = V_86 -> V_4 ;
break;
case V_93 :
V_88 = (struct V_87 * ) ( V_2 -> V_89 + ( V_9 -> V_91 << 2 ) ) ;
V_4 = F_37 ( F_49 ( V_88 -> V_94 ) ) ;
break;
default:
return 0 ;
}
switch ( F_50 ( V_2 ) -> type ) {
case V_71 :
if ( F_50 ( V_2 ) -> V_95 != V_72 )
return 0 ;
case V_96 :
break;
default:
return 0 ;
}
V_32 = F_51 ( V_10 , V_34 , ( const T_3 * ) & V_9 -> V_18 ,
V_4 , V_26 , V_24 ) ;
if ( ! V_32 )
return 0 ;
if ( F_50 ( V_2 ) -> type == V_71 )
F_52 ( V_2 , V_10 , V_82 , 0 , 0 , V_26 , 0 ) ;
else
F_53 ( V_2 , V_10 , 0 , 0 , V_26 , 0 ) ;
F_54 ( V_32 ) ;
return 0 ;
}
static int
F_55 ( struct V_28 * V_11 , struct V_97 * V_98 , int V_99 )
{
int V_27 = 0 ;
struct V_55 V_100 ;
if ( F_56 ( & V_100 , V_98 -> V_101 . V_102 , sizeof( V_100 ) ) )
return - V_103 ;
if ( V_99 == V_104 || V_99 == V_105 ) {
if ( V_100 . V_9 . V_106 != 4 || V_100 . V_9 . V_26 != V_107 ||
V_100 . V_9 . V_91 != 5 )
return - V_22 ;
}
if ( ! ( V_100 . V_108 & V_109 ) )
V_100 . V_42 = 0 ;
if ( ! ( V_100 . V_110 & V_109 ) )
V_100 . V_81 = 0 ;
V_100 . V_108 = V_111 ;
V_27 = F_57 ( V_11 , & V_100 , V_99 ) ;
if ( V_27 )
return V_27 ;
if ( V_99 != V_112 ) {
V_100 . V_108 |= V_109 ;
V_100 . V_110 |= V_109 ;
}
if ( F_58 ( V_98 -> V_101 . V_102 , & V_100 , sizeof( V_100 ) ) )
return - V_103 ;
return 0 ;
}
static void F_59 ( struct V_28 * V_11 )
{
V_11 -> V_113 = & V_114 ;
V_11 -> type = V_115 ;
F_60 ( V_11 , V_14 ) ;
}
static int F_61 ( struct V_28 * V_11 )
{
struct V_6 * V_7 = F_26 ( V_11 ) ;
struct V_8 * V_9 = & V_7 -> V_41 . V_9 ;
memcpy ( V_11 -> V_116 , & V_9 -> V_17 , 4 ) ;
memcpy ( V_11 -> V_117 , & V_9 -> V_18 , 4 ) ;
V_11 -> V_118 = V_119 + sizeof( struct V_8 ) ;
V_11 -> V_58 = V_120 ;
V_11 -> V_121 = V_122 ;
V_11 -> V_123 = 4 ;
V_11 -> V_124 |= V_125 ;
F_62 ( V_11 ) ;
return F_63 ( V_11 ) ;
}
static void T_6 F_64 ( struct V_28 * V_11 )
{
struct V_6 * V_7 = F_26 ( V_11 ) ;
struct V_8 * V_9 = & V_7 -> V_41 . V_9 ;
V_9 -> V_106 = 4 ;
V_9 -> V_26 = V_107 ;
V_9 -> V_91 = 5 ;
}
static int T_6 F_65 ( struct V_10 * V_10 )
{
int V_27 ;
struct V_12 * V_13 ;
V_27 = F_66 ( V_10 , V_14 , & V_126 , L_1 ) ;
if ( V_27 )
return V_27 ;
V_13 = F_4 ( V_10 , V_14 ) ;
F_64 ( V_13 -> V_127 ) ;
return 0 ;
}
static void T_7 F_67 ( struct V_10 * V_10 )
{
struct V_12 * V_13 = F_4 ( V_10 , V_14 ) ;
F_68 ( V_13 , & V_126 ) ;
}
static int F_69 ( struct V_128 * V_129 [] , struct V_128 * V_89 [] )
{
return 0 ;
}
static void F_70 ( struct V_128 * V_89 [] ,
struct V_55 * V_41 )
{
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_9 . V_26 = V_107 ;
if ( ! V_89 )
return;
V_41 -> V_108 = V_111 ;
if ( V_89 [ V_130 ] )
V_41 -> V_131 = F_71 ( V_89 [ V_130 ] ) ;
if ( V_89 [ V_132 ] )
V_41 -> V_42 = F_72 ( V_89 [ V_132 ] ) ;
if ( V_89 [ V_133 ] )
V_41 -> V_81 = F_72 ( V_89 [ V_133 ] ) ;
if ( V_89 [ V_134 ] )
V_41 -> V_9 . V_17 = F_73 ( V_89 [ V_134 ] ) ;
if ( V_89 [ V_135 ] )
V_41 -> V_9 . V_18 = F_73 ( V_89 [ V_135 ] ) ;
}
static int F_74 ( struct V_10 * V_136 , struct V_28 * V_11 ,
struct V_128 * V_129 [] , struct V_128 * V_89 [] )
{
struct V_55 V_41 ;
F_70 ( V_89 , & V_41 ) ;
return F_75 ( V_11 , V_129 , & V_41 ) ;
}
static int F_76 ( struct V_28 * V_11 , struct V_128 * V_129 [] ,
struct V_128 * V_89 [] )
{
struct V_55 V_100 ;
F_70 ( V_89 , & V_100 ) ;
return F_77 ( V_11 , V_129 , & V_100 ) ;
}
static T_8 F_78 ( const struct V_28 * V_11 )
{
return
F_79 ( 4 ) +
F_79 ( 4 ) +
F_79 ( 4 ) +
F_79 ( 4 ) +
F_79 ( 4 ) +
0 ;
}
static int F_80 ( struct V_1 * V_2 , const struct V_28 * V_11 )
{
struct V_6 * V_137 = F_26 ( V_11 ) ;
struct V_55 * V_100 = & V_137 -> V_41 ;
F_81 ( V_2 , V_130 , V_100 -> V_131 ) ;
F_82 ( V_2 , V_132 , V_100 -> V_42 ) ;
F_82 ( V_2 , V_133 , V_100 -> V_81 ) ;
F_83 ( V_2 , V_134 , V_100 -> V_9 . V_17 ) ;
F_83 ( V_2 , V_135 , V_100 -> V_9 . V_18 ) ;
return 0 ;
}
static int T_9 F_84 ( void )
{
const char * V_138 ;
int V_27 ;
F_85 ( L_2 ) ;
V_138 = L_3 ;
V_27 = F_86 ( & V_139 ) ;
if ( V_27 < 0 )
goto V_140;
V_138 = L_4 ;
V_27 = F_87 ( & V_141 , V_90 ) ;
if ( V_27 < 0 )
goto V_142;
V_27 = F_87 ( & V_143 , V_92 ) ;
if ( V_27 < 0 )
goto V_144;
V_27 = F_87 ( & V_145 , V_93 ) ;
if ( V_27 < 0 )
goto V_146;
V_138 = L_5 ;
V_27 = F_88 ( & V_126 ) ;
if ( V_27 < 0 )
goto V_147;
return V_27 ;
V_147:
F_89 ( & V_145 , V_93 ) ;
V_146:
F_89 ( & V_143 , V_92 ) ;
V_144:
F_89 ( & V_141 , V_90 ) ;
V_142:
F_90 ( & V_139 ) ;
V_140:
F_91 ( L_6 , V_138 ) ;
return V_27 ;
}
static void T_10 F_92 ( void )
{
F_93 ( & V_126 ) ;
F_89 ( & V_145 , V_93 ) ;
F_89 ( & V_143 , V_92 ) ;
F_89 ( & V_141 , V_90 ) ;
F_90 ( & V_139 ) ;
}

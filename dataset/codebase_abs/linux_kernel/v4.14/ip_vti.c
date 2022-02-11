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
struct V_33 * V_34 ;
struct V_6 * V_7 = F_7 ( V_2 ) -> V_7 . V_21 ;
T_2 V_35 = V_2 -> V_36 ;
int V_37 ;
if ( ! V_7 )
return 1 ;
V_11 = V_7 -> V_11 ;
if ( V_27 ) {
V_11 -> V_38 . V_39 ++ ;
V_11 -> V_38 . V_40 ++ ;
return 0 ;
}
V_32 = F_14 ( V_2 ) ;
V_34 = V_32 -> V_34 ;
if ( V_32 -> V_41 . V_23 == V_42 ) {
V_34 = F_15 ( V_32 , F_16 ( V_2 ) -> V_26 ) ;
if ( V_34 == NULL ) {
F_17 ( F_3 ( V_2 -> V_11 ) ,
V_43 ) ;
return - V_22 ;
}
}
V_23 = V_34 -> V_44 -> V_23 ;
V_2 -> V_36 = F_18 ( V_7 -> V_45 . V_46 ) ;
V_37 = F_19 ( NULL , V_19 , V_2 , V_23 ) ;
V_2 -> V_36 = V_35 ;
if ( ! V_37 )
return - V_47 ;
F_20 ( V_2 , ! F_21 ( V_7 -> V_10 , F_3 ( V_2 -> V_11 ) ) ) ;
V_2 -> V_11 = V_11 ;
V_30 = F_22 ( V_11 -> V_30 ) ;
F_23 ( & V_30 -> V_48 ) ;
V_30 -> V_49 ++ ;
V_30 -> V_50 += V_2 -> V_51 ;
F_24 ( & V_30 -> V_48 ) ;
return 0 ;
}
static bool F_25 ( const struct V_31 * V_32 , T_1 V_52 , T_1 V_53 )
{
T_3 * V_18 = ( T_3 * ) & V_52 ;
T_3 * V_17 = ( T_3 * ) & V_53 ;
if ( ! V_32 || V_32 -> V_54 . V_55 != V_56 ||
V_32 -> V_54 . V_23 != V_24 )
return false ;
if ( ! V_52 )
return F_26 ( V_17 , & V_32 -> V_54 . V_17 , V_24 ) ;
if ( ! F_27 ( V_32 , V_18 , V_17 , V_24 ) )
return false ;
return true ;
}
static T_4 F_28 ( struct V_1 * V_2 , struct V_28 * V_11 ,
struct V_57 * V_58 )
{
struct V_6 * V_7 = F_29 ( V_11 ) ;
struct V_59 * V_45 = & V_7 -> V_45 ;
struct V_60 * V_52 = F_30 ( V_2 ) ;
struct V_28 * V_61 ;
int V_62 = V_2 -> V_51 ;
int V_27 ;
int V_63 ;
if ( ! V_52 ) {
V_11 -> V_38 . V_64 ++ ;
goto V_65;
}
F_31 ( V_52 ) ;
V_52 = F_32 ( V_7 -> V_10 , V_52 , V_58 , NULL , 0 ) ;
if ( F_33 ( V_52 ) ) {
V_11 -> V_38 . V_64 ++ ;
goto V_65;
}
if ( ! F_25 ( V_52 -> V_66 , V_45 -> V_9 . V_18 , V_45 -> V_9 . V_17 ) ) {
V_11 -> V_38 . V_64 ++ ;
F_34 ( V_52 ) ;
goto V_65;
}
V_61 = V_52 -> V_11 ;
if ( V_61 == V_11 ) {
F_34 ( V_52 ) ;
V_11 -> V_38 . V_67 ++ ;
goto V_68;
}
if ( V_7 -> V_69 > 0 ) {
if ( F_35 ( V_70 ,
V_7 -> V_71 + V_72 ) ) {
V_7 -> V_69 -- ;
F_36 ( V_2 ) ;
} else
V_7 -> V_69 = 0 ;
}
V_63 = F_37 ( V_52 ) ;
if ( V_2 -> V_51 > V_63 ) {
F_30 ( V_2 ) -> V_73 -> V_74 ( F_30 ( V_2 ) , NULL , V_2 , V_63 ) ;
if ( V_2 -> V_26 == F_38 ( V_75 ) ) {
F_39 ( V_2 , V_76 , V_77 ,
F_40 ( V_63 ) ) ;
} else {
if ( V_63 < V_78 )
V_63 = V_78 ;
F_41 ( V_2 , V_79 , 0 , V_63 ) ;
}
F_34 ( V_52 ) ;
goto V_68;
}
F_20 ( V_2 , ! F_21 ( V_7 -> V_10 , F_3 ( V_11 ) ) ) ;
F_42 ( V_2 , V_52 ) ;
V_2 -> V_11 = F_30 ( V_2 ) -> V_11 ;
V_27 = F_43 ( V_7 -> V_10 , V_2 -> V_80 , V_2 ) ;
if ( F_44 ( V_27 ) == 0 )
V_27 = V_62 ;
F_45 ( V_11 , V_27 ) ;
return V_81 ;
V_65:
F_36 ( V_2 ) ;
V_68:
V_11 -> V_38 . V_82 ++ ;
F_9 ( V_2 ) ;
return V_81 ;
}
static T_4 F_46 ( struct V_1 * V_2 , struct V_28 * V_11 )
{
struct V_6 * V_7 = F_29 ( V_11 ) ;
struct V_57 V_58 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
switch ( V_2 -> V_26 ) {
case F_38 ( V_75 ) :
F_47 ( V_2 , & V_58 , V_24 ) ;
memset ( F_48 ( V_2 ) , 0 , sizeof( * F_48 ( V_2 ) ) ) ;
break;
case F_38 ( V_83 ) :
F_47 ( V_2 , & V_58 , V_84 ) ;
memset ( F_49 ( V_2 ) , 0 , sizeof( * F_49 ( V_2 ) ) ) ;
break;
default:
V_11 -> V_38 . V_82 ++ ;
F_50 ( V_2 ) ;
return V_81 ;
}
V_58 . V_85 = F_18 ( V_7 -> V_45 . V_86 ) ;
return F_28 ( V_2 , V_11 , & V_58 ) ;
}
static int F_51 ( struct V_1 * V_2 , T_2 V_87 )
{
T_1 V_4 ;
T_5 V_36 ;
struct V_31 * V_32 ;
struct V_6 * V_7 ;
struct V_88 * V_89 ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_10 * V_10 = F_3 ( V_2 -> V_11 ) ;
const struct V_8 * V_9 = ( const struct V_8 * ) V_2 -> V_94 ;
int V_26 = V_9 -> V_26 ;
struct V_12 * V_13 = F_4 ( V_10 , V_14 ) ;
V_7 = F_5 ( V_13 , V_2 -> V_11 -> V_15 , V_16 ,
V_9 -> V_18 , V_9 -> V_17 , 0 ) ;
if ( ! V_7 )
return - 1 ;
V_36 = F_18 ( V_7 -> V_45 . V_86 ) ;
switch ( V_26 ) {
case V_95 :
V_89 = (struct V_88 * ) ( V_2 -> V_94 + ( V_9 -> V_96 << 2 ) ) ;
V_4 = V_89 -> V_4 ;
break;
case V_97 :
V_91 = (struct V_90 * ) ( V_2 -> V_94 + ( V_9 -> V_96 << 2 ) ) ;
V_4 = V_91 -> V_4 ;
break;
case V_98 :
V_93 = (struct V_92 * ) ( V_2 -> V_94 + ( V_9 -> V_96 << 2 ) ) ;
V_4 = F_40 ( F_52 ( V_93 -> V_99 ) ) ;
break;
default:
return 0 ;
}
switch ( F_53 ( V_2 ) -> type ) {
case V_76 :
if ( F_53 ( V_2 ) -> V_100 != V_77 )
return 0 ;
case V_101 :
break;
default:
return 0 ;
}
V_32 = F_54 ( V_10 , V_36 , ( const T_3 * ) & V_9 -> V_18 ,
V_4 , V_26 , V_24 ) ;
if ( ! V_32 )
return 0 ;
if ( F_53 ( V_2 ) -> type == V_76 )
F_55 ( V_2 , V_10 , V_87 , 0 , 0 , V_26 , 0 ) ;
else
F_56 ( V_2 , V_10 , 0 , 0 , V_26 , 0 ) ;
F_57 ( V_32 ) ;
return 0 ;
}
static int
F_58 ( struct V_28 * V_11 , struct V_102 * V_103 , int V_104 )
{
int V_27 = 0 ;
struct V_59 V_105 ;
if ( F_59 ( & V_105 , V_103 -> V_106 . V_107 , sizeof( V_105 ) ) )
return - V_108 ;
if ( V_104 == V_109 || V_104 == V_110 ) {
if ( V_105 . V_9 . V_111 != 4 || V_105 . V_9 . V_26 != V_112 ||
V_105 . V_9 . V_96 != 5 )
return - V_22 ;
}
if ( ! ( V_105 . V_113 & V_114 ) )
V_105 . V_46 = 0 ;
if ( ! ( V_105 . V_115 & V_114 ) )
V_105 . V_86 = 0 ;
V_105 . V_113 = V_116 ;
V_27 = F_60 ( V_11 , & V_105 , V_104 ) ;
if ( V_27 )
return V_27 ;
if ( V_104 != V_117 ) {
V_105 . V_113 |= V_114 ;
V_105 . V_115 |= V_114 ;
}
if ( F_61 ( V_103 -> V_106 . V_107 , & V_105 , sizeof( V_105 ) ) )
return - V_108 ;
return 0 ;
}
static void F_62 ( struct V_28 * V_11 )
{
V_11 -> V_118 = & V_119 ;
V_11 -> type = V_120 ;
F_63 ( V_11 , V_14 ) ;
}
static int F_64 ( struct V_28 * V_11 )
{
struct V_6 * V_7 = F_29 ( V_11 ) ;
struct V_8 * V_9 = & V_7 -> V_45 . V_9 ;
memcpy ( V_11 -> V_121 , & V_9 -> V_17 , 4 ) ;
memcpy ( V_11 -> V_122 , & V_9 -> V_18 , 4 ) ;
V_11 -> V_123 = V_124 + sizeof( struct V_8 ) ;
V_11 -> V_63 = V_125 ;
V_11 -> V_126 = V_127 ;
V_11 -> V_128 = 4 ;
V_11 -> V_129 |= V_130 ;
F_65 ( V_11 ) ;
return F_66 ( V_11 ) ;
}
static void T_6 F_67 ( struct V_28 * V_11 )
{
struct V_6 * V_7 = F_29 ( V_11 ) ;
struct V_8 * V_9 = & V_7 -> V_45 . V_9 ;
V_9 -> V_111 = 4 ;
V_9 -> V_26 = V_112 ;
V_9 -> V_96 = 5 ;
}
static int T_6 F_68 ( struct V_10 * V_10 )
{
int V_27 ;
struct V_12 * V_13 ;
V_27 = F_69 ( V_10 , V_14 , & V_131 , L_1 ) ;
if ( V_27 )
return V_27 ;
V_13 = F_4 ( V_10 , V_14 ) ;
F_67 ( V_13 -> V_132 ) ;
return 0 ;
}
static void T_7 F_70 ( struct V_10 * V_10 )
{
struct V_12 * V_13 = F_4 ( V_10 , V_14 ) ;
F_71 ( V_13 , & V_131 ) ;
}
static int F_72 ( struct V_133 * V_134 [] , struct V_133 * V_94 [] ,
struct V_135 * V_136 )
{
return 0 ;
}
static void F_73 ( struct V_133 * V_94 [] ,
struct V_59 * V_45 ,
T_5 * V_137 )
{
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_9 . V_26 = V_112 ;
if ( ! V_94 )
return;
V_45 -> V_113 = V_116 ;
if ( V_94 [ V_138 ] )
V_45 -> V_139 = F_74 ( V_94 [ V_138 ] ) ;
if ( V_94 [ V_140 ] )
V_45 -> V_46 = F_75 ( V_94 [ V_140 ] ) ;
if ( V_94 [ V_141 ] )
V_45 -> V_86 = F_75 ( V_94 [ V_141 ] ) ;
if ( V_94 [ V_142 ] )
V_45 -> V_9 . V_17 = F_76 ( V_94 [ V_142 ] ) ;
if ( V_94 [ V_143 ] )
V_45 -> V_9 . V_18 = F_76 ( V_94 [ V_143 ] ) ;
if ( V_94 [ V_144 ] )
* V_137 = F_74 ( V_94 [ V_144 ] ) ;
}
static int F_77 ( struct V_10 * V_145 , struct V_28 * V_11 ,
struct V_133 * V_134 [] , struct V_133 * V_94 [] ,
struct V_135 * V_136 )
{
struct V_59 V_45 ;
T_5 V_137 = 0 ;
F_73 ( V_94 , & V_45 , & V_137 ) ;
return F_78 ( V_11 , V_134 , & V_45 , V_137 ) ;
}
static int F_79 ( struct V_28 * V_11 , struct V_133 * V_134 [] ,
struct V_133 * V_94 [] ,
struct V_135 * V_136 )
{
struct V_6 * V_146 = F_29 ( V_11 ) ;
T_5 V_137 = V_146 -> V_137 ;
struct V_59 V_105 ;
F_73 ( V_94 , & V_105 , & V_137 ) ;
return F_80 ( V_11 , V_134 , & V_105 , V_137 ) ;
}
static T_8 F_81 ( const struct V_28 * V_11 )
{
return
F_82 ( 4 ) +
F_82 ( 4 ) +
F_82 ( 4 ) +
F_82 ( 4 ) +
F_82 ( 4 ) +
F_82 ( 4 ) +
0 ;
}
static int F_83 ( struct V_1 * V_2 , const struct V_28 * V_11 )
{
struct V_6 * V_146 = F_29 ( V_11 ) ;
struct V_59 * V_105 = & V_146 -> V_45 ;
if ( F_84 ( V_2 , V_138 , V_105 -> V_139 ) ||
F_85 ( V_2 , V_140 , V_105 -> V_46 ) ||
F_85 ( V_2 , V_141 , V_105 -> V_86 ) ||
F_86 ( V_2 , V_142 , V_105 -> V_9 . V_17 ) ||
F_86 ( V_2 , V_143 , V_105 -> V_9 . V_18 ) ||
F_84 ( V_2 , V_144 , V_146 -> V_137 ) )
return - V_147 ;
return 0 ;
}
static int T_9 F_87 ( void )
{
const char * V_148 ;
int V_27 ;
F_88 ( L_2 ) ;
V_148 = L_3 ;
V_27 = F_89 ( & V_149 ) ;
if ( V_27 < 0 )
goto V_150;
V_148 = L_4 ;
V_27 = F_90 ( & V_151 , V_95 ) ;
if ( V_27 < 0 )
goto V_152;
V_27 = F_90 ( & V_153 , V_97 ) ;
if ( V_27 < 0 )
goto V_154;
V_27 = F_90 ( & V_155 , V_98 ) ;
if ( V_27 < 0 )
goto V_156;
V_148 = L_5 ;
V_27 = F_91 ( & V_131 ) ;
if ( V_27 < 0 )
goto V_157;
return V_27 ;
V_157:
F_92 ( & V_155 , V_98 ) ;
V_156:
F_92 ( & V_153 , V_97 ) ;
V_154:
F_92 ( & V_151 , V_95 ) ;
V_152:
F_93 ( & V_149 ) ;
V_150:
F_94 ( L_6 , V_148 ) ;
return V_27 ;
}
static void T_10 F_95 ( void )
{
F_96 ( & V_131 ) ;
F_92 ( & V_155 , V_98 ) ;
F_92 ( & V_153 , V_97 ) ;
F_92 ( & V_151 , V_95 ) ;
F_93 ( & V_149 ) ;
}

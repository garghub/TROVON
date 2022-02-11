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
int V_27 ;
int V_62 ;
if ( ! V_52 ) {
V_11 -> V_38 . V_63 ++ ;
goto V_64;
}
F_31 ( V_52 ) ;
V_52 = F_32 ( V_7 -> V_10 , V_52 , V_58 , NULL , 0 ) ;
if ( F_33 ( V_52 ) ) {
V_11 -> V_38 . V_63 ++ ;
goto V_64;
}
if ( ! F_25 ( V_52 -> V_65 , V_45 -> V_9 . V_18 , V_45 -> V_9 . V_17 ) ) {
V_11 -> V_38 . V_63 ++ ;
F_34 ( V_52 ) ;
goto V_64;
}
V_61 = V_52 -> V_11 ;
if ( V_61 == V_11 ) {
F_34 ( V_52 ) ;
V_11 -> V_38 . V_66 ++ ;
goto V_67;
}
if ( V_7 -> V_68 > 0 ) {
if ( F_35 ( V_69 ,
V_7 -> V_70 + V_71 ) ) {
V_7 -> V_68 -- ;
F_36 ( V_2 ) ;
} else
V_7 -> V_68 = 0 ;
}
V_62 = F_37 ( V_52 ) ;
if ( V_2 -> V_51 > V_62 ) {
F_30 ( V_2 ) -> V_72 -> V_73 ( F_30 ( V_2 ) , NULL , V_2 , V_62 ) ;
if ( V_2 -> V_26 == F_38 ( V_74 ) ) {
F_39 ( V_2 , V_75 , V_76 ,
F_40 ( V_62 ) ) ;
} else {
if ( V_62 < V_77 )
V_62 = V_77 ;
F_41 ( V_2 , V_78 , 0 , V_62 ) ;
}
F_34 ( V_52 ) ;
goto V_67;
}
F_20 ( V_2 , ! F_21 ( V_7 -> V_10 , F_3 ( V_11 ) ) ) ;
F_42 ( V_2 , V_52 ) ;
V_2 -> V_11 = F_30 ( V_2 ) -> V_11 ;
V_27 = F_43 ( V_7 -> V_10 , V_2 -> V_79 , V_2 ) ;
if ( F_44 ( V_27 ) == 0 )
V_27 = V_2 -> V_51 ;
F_45 ( V_11 , V_27 ) ;
return V_80 ;
V_64:
F_36 ( V_2 ) ;
V_67:
V_11 -> V_38 . V_81 ++ ;
F_9 ( V_2 ) ;
return V_80 ;
}
static T_4 F_46 ( struct V_1 * V_2 , struct V_28 * V_11 )
{
struct V_6 * V_7 = F_29 ( V_11 ) ;
struct V_57 V_58 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
switch ( V_2 -> V_26 ) {
case F_38 ( V_74 ) :
F_47 ( V_2 , & V_58 , V_24 ) ;
memset ( F_48 ( V_2 ) , 0 , sizeof( * F_48 ( V_2 ) ) ) ;
break;
case F_38 ( V_82 ) :
F_47 ( V_2 , & V_58 , V_83 ) ;
memset ( F_49 ( V_2 ) , 0 , sizeof( * F_49 ( V_2 ) ) ) ;
break;
default:
V_11 -> V_38 . V_81 ++ ;
F_50 ( V_2 ) ;
return V_80 ;
}
V_58 . V_84 = F_18 ( V_7 -> V_45 . V_85 ) ;
return F_28 ( V_2 , V_11 , & V_58 ) ;
}
static int F_51 ( struct V_1 * V_2 , T_2 V_86 )
{
T_1 V_4 ;
T_5 V_36 ;
struct V_31 * V_32 ;
struct V_6 * V_7 ;
struct V_87 * V_88 ;
struct V_89 * V_90 ;
struct V_91 * V_92 ;
struct V_10 * V_10 = F_3 ( V_2 -> V_11 ) ;
const struct V_8 * V_9 = ( const struct V_8 * ) V_2 -> V_93 ;
int V_26 = V_9 -> V_26 ;
struct V_12 * V_13 = F_4 ( V_10 , V_14 ) ;
V_7 = F_5 ( V_13 , V_2 -> V_11 -> V_15 , V_16 ,
V_9 -> V_18 , V_9 -> V_17 , 0 ) ;
if ( ! V_7 )
return - 1 ;
V_36 = F_18 ( V_7 -> V_45 . V_85 ) ;
switch ( V_26 ) {
case V_94 :
V_88 = (struct V_87 * ) ( V_2 -> V_93 + ( V_9 -> V_95 << 2 ) ) ;
V_4 = V_88 -> V_4 ;
break;
case V_96 :
V_90 = (struct V_89 * ) ( V_2 -> V_93 + ( V_9 -> V_95 << 2 ) ) ;
V_4 = V_90 -> V_4 ;
break;
case V_97 :
V_92 = (struct V_91 * ) ( V_2 -> V_93 + ( V_9 -> V_95 << 2 ) ) ;
V_4 = F_40 ( F_52 ( V_92 -> V_98 ) ) ;
break;
default:
return 0 ;
}
switch ( F_53 ( V_2 ) -> type ) {
case V_75 :
if ( F_53 ( V_2 ) -> V_99 != V_76 )
return 0 ;
case V_100 :
break;
default:
return 0 ;
}
V_32 = F_54 ( V_10 , V_36 , ( const T_3 * ) & V_9 -> V_18 ,
V_4 , V_26 , V_24 ) ;
if ( ! V_32 )
return 0 ;
if ( F_53 ( V_2 ) -> type == V_75 )
F_55 ( V_2 , V_10 , V_86 , 0 , 0 , V_26 , 0 ) ;
else
F_56 ( V_2 , V_10 , 0 , 0 , V_26 , 0 ) ;
F_57 ( V_32 ) ;
return 0 ;
}
static int
F_58 ( struct V_28 * V_11 , struct V_101 * V_102 , int V_103 )
{
int V_27 = 0 ;
struct V_59 V_104 ;
if ( F_59 ( & V_104 , V_102 -> V_105 . V_106 , sizeof( V_104 ) ) )
return - V_107 ;
if ( V_103 == V_108 || V_103 == V_109 ) {
if ( V_104 . V_9 . V_110 != 4 || V_104 . V_9 . V_26 != V_111 ||
V_104 . V_9 . V_95 != 5 )
return - V_22 ;
}
if ( ! ( V_104 . V_112 & V_113 ) )
V_104 . V_46 = 0 ;
if ( ! ( V_104 . V_114 & V_113 ) )
V_104 . V_85 = 0 ;
V_104 . V_112 = V_115 ;
V_27 = F_60 ( V_11 , & V_104 , V_103 ) ;
if ( V_27 )
return V_27 ;
if ( V_103 != V_116 ) {
V_104 . V_112 |= V_113 ;
V_104 . V_114 |= V_113 ;
}
if ( F_61 ( V_102 -> V_105 . V_106 , & V_104 , sizeof( V_104 ) ) )
return - V_107 ;
return 0 ;
}
static void F_62 ( struct V_28 * V_11 )
{
V_11 -> V_117 = & V_118 ;
V_11 -> type = V_119 ;
F_63 ( V_11 , V_14 ) ;
}
static int F_64 ( struct V_28 * V_11 )
{
struct V_6 * V_7 = F_29 ( V_11 ) ;
struct V_8 * V_9 = & V_7 -> V_45 . V_9 ;
memcpy ( V_11 -> V_120 , & V_9 -> V_17 , 4 ) ;
memcpy ( V_11 -> V_121 , & V_9 -> V_18 , 4 ) ;
V_11 -> V_122 = V_123 + sizeof( struct V_8 ) ;
V_11 -> V_62 = V_124 ;
V_11 -> V_125 = V_126 ;
V_11 -> V_127 = 4 ;
V_11 -> V_128 |= V_129 ;
F_65 ( V_11 ) ;
return F_66 ( V_11 ) ;
}
static void T_6 F_67 ( struct V_28 * V_11 )
{
struct V_6 * V_7 = F_29 ( V_11 ) ;
struct V_8 * V_9 = & V_7 -> V_45 . V_9 ;
V_9 -> V_110 = 4 ;
V_9 -> V_26 = V_111 ;
V_9 -> V_95 = 5 ;
}
static int T_6 F_68 ( struct V_10 * V_10 )
{
int V_27 ;
struct V_12 * V_13 ;
V_27 = F_69 ( V_10 , V_14 , & V_130 , L_1 ) ;
if ( V_27 )
return V_27 ;
V_13 = F_4 ( V_10 , V_14 ) ;
F_67 ( V_13 -> V_131 ) ;
return 0 ;
}
static void T_7 F_70 ( struct V_10 * V_10 )
{
struct V_12 * V_13 = F_4 ( V_10 , V_14 ) ;
F_71 ( V_13 , & V_130 ) ;
}
static int F_72 ( struct V_132 * V_133 [] , struct V_132 * V_93 [] )
{
return 0 ;
}
static void F_73 ( struct V_132 * V_93 [] ,
struct V_59 * V_45 ,
T_5 * V_134 )
{
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_9 . V_26 = V_111 ;
if ( ! V_93 )
return;
V_45 -> V_112 = V_115 ;
if ( V_93 [ V_135 ] )
V_45 -> V_136 = F_74 ( V_93 [ V_135 ] ) ;
if ( V_93 [ V_137 ] )
V_45 -> V_46 = F_75 ( V_93 [ V_137 ] ) ;
if ( V_93 [ V_138 ] )
V_45 -> V_85 = F_75 ( V_93 [ V_138 ] ) ;
if ( V_93 [ V_139 ] )
V_45 -> V_9 . V_17 = F_76 ( V_93 [ V_139 ] ) ;
if ( V_93 [ V_140 ] )
V_45 -> V_9 . V_18 = F_76 ( V_93 [ V_140 ] ) ;
if ( V_93 [ V_141 ] )
* V_134 = F_74 ( V_93 [ V_141 ] ) ;
}
static int F_77 ( struct V_10 * V_142 , struct V_28 * V_11 ,
struct V_132 * V_133 [] , struct V_132 * V_93 [] )
{
struct V_59 V_45 ;
T_5 V_134 = 0 ;
F_73 ( V_93 , & V_45 , & V_134 ) ;
return F_78 ( V_11 , V_133 , & V_45 , V_134 ) ;
}
static int F_79 ( struct V_28 * V_11 , struct V_132 * V_133 [] ,
struct V_132 * V_93 [] )
{
struct V_6 * V_143 = F_29 ( V_11 ) ;
T_5 V_134 = V_143 -> V_134 ;
struct V_59 V_104 ;
F_73 ( V_93 , & V_104 , & V_134 ) ;
return F_80 ( V_11 , V_133 , & V_104 , V_134 ) ;
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
struct V_6 * V_143 = F_29 ( V_11 ) ;
struct V_59 * V_104 = & V_143 -> V_45 ;
if ( F_84 ( V_2 , V_135 , V_104 -> V_136 ) ||
F_85 ( V_2 , V_137 , V_104 -> V_46 ) ||
F_85 ( V_2 , V_138 , V_104 -> V_85 ) ||
F_86 ( V_2 , V_139 , V_104 -> V_9 . V_17 ) ||
F_86 ( V_2 , V_140 , V_104 -> V_9 . V_18 ) ||
F_84 ( V_2 , V_141 , V_143 -> V_134 ) )
return - V_144 ;
return 0 ;
}
static bool F_87 ( const struct V_28 * V_11 )
{
return V_11 -> V_117 == & V_118 ;
}
static int F_88 ( struct V_145 * V_146 ,
unsigned long V_147 , void * V_148 )
{
struct V_28 * V_11 = F_89 ( V_148 ) ;
struct V_6 * V_7 = F_29 ( V_11 ) ;
if ( ! F_87 ( V_11 ) )
return V_149 ;
switch ( V_147 ) {
case V_150 :
if ( ! F_21 ( V_7 -> V_10 , F_3 ( V_11 ) ) )
F_90 ( V_7 -> V_10 ) ;
break;
}
return V_149 ;
}
static int T_9 F_91 ( void )
{
const char * V_151 ;
int V_27 ;
F_92 ( L_2 ) ;
F_93 ( & V_152 ) ;
V_151 = L_3 ;
V_27 = F_94 ( & V_153 ) ;
if ( V_27 < 0 )
goto V_154;
V_151 = L_4 ;
V_27 = F_95 ( & V_155 , V_94 ) ;
if ( V_27 < 0 )
goto V_156;
V_27 = F_95 ( & V_157 , V_96 ) ;
if ( V_27 < 0 )
goto V_158;
V_27 = F_95 ( & V_159 , V_97 ) ;
if ( V_27 < 0 )
goto V_160;
V_151 = L_5 ;
V_27 = F_96 ( & V_130 ) ;
if ( V_27 < 0 )
goto V_161;
return V_27 ;
V_161:
F_97 ( & V_159 , V_97 ) ;
V_160:
F_97 ( & V_157 , V_96 ) ;
V_158:
F_97 ( & V_155 , V_94 ) ;
V_156:
F_98 ( & V_153 ) ;
V_154:
F_99 ( & V_152 ) ;
F_100 ( L_6 , V_151 ) ;
return V_27 ;
}
static void T_10 F_101 ( void )
{
F_102 ( & V_130 ) ;
F_97 ( & V_159 , V_97 ) ;
F_97 ( & V_157 , V_96 ) ;
F_97 ( & V_155 , V_94 ) ;
F_98 ( & V_153 ) ;
F_99 ( & V_152 ) ;
}

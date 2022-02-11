static struct V_1 * F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_2 ;
}
static int F_2 ( struct V_4 * V_5 )
{
return F_3 ( V_5 ) ;
}
static unsigned int F_4 ( const struct V_1 * V_2 )
{
return V_2 -> V_6 -> V_7 ;
}
static void F_5 ( struct V_1 * V_2 )
{
}
static unsigned int F_6 ( const struct V_1 * V_2 )
{
return 65535 - 40 ;
}
static bool F_7 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_8 ) {
case F_8 ( V_9 ) :
case F_8 ( V_10 ) :
return true ;
}
return false ;
}
static void F_9 ( struct V_11 * V_12 , struct V_4 * V_5 )
{
V_12 -> V_13 . V_14 ++ ;
F_10 ( V_5 ) ;
}
static T_2 F_11 ( struct V_4 * * V_15 )
{
struct V_4 * V_5 = * V_15 ;
if ( F_7 ( V_5 ) ) {
struct V_11 * V_6 = F_12 ( V_5 -> V_6 ) ;
struct V_16 * V_17 = F_13 ( V_6 -> V_17 ) ;
F_14 ( & V_17 -> V_18 ) ;
V_17 -> V_19 ++ ;
V_17 -> V_20 += V_5 -> V_21 ;
F_15 ( & V_17 -> V_18 ) ;
V_5 -> V_6 = V_6 ;
return V_22 ;
}
return V_23 ;
}
static struct V_24 * F_16 ( struct V_11 * V_6 ,
struct V_24 * V_13 )
{
int V_25 ;
F_17 (i) {
const struct V_16 * V_17 ;
T_3 V_26 , V_27 , V_28 , V_29 , V_30 ;
unsigned int V_31 ;
V_17 = F_18 ( V_6 -> V_17 , V_25 ) ;
do {
V_31 = F_19 ( & V_17 -> V_18 ) ;
V_26 = V_17 -> V_32 ;
V_27 = V_17 -> V_33 ;
V_28 = V_17 -> V_34 ;
V_29 = V_17 -> V_20 ;
V_30 = V_17 -> V_19 ;
} while ( F_20 ( & V_17 -> V_18 , V_31 ) );
V_13 -> V_32 += V_26 ;
V_13 -> V_35 += V_27 ;
V_13 -> V_36 += V_28 ;
V_13 -> V_20 += V_29 ;
V_13 -> V_37 += V_30 ;
}
return V_13 ;
}
static T_4 F_21 ( struct V_4 * V_5 ,
struct V_11 * V_6 )
{
F_9 ( V_6 , V_5 ) ;
return V_38 ;
}
static int F_22 ( struct V_4 * V_5 , struct V_39 * V_40 ,
struct V_11 * V_12 )
{
struct V_41 * V_42 ;
int V_43 = 1 ;
V_42 = F_23 ( F_24 ( V_12 ) , V_40 , NULL ) ;
if ( F_25 ( V_42 ) )
goto V_44;
if ( V_42 -> V_45 != V_46 && V_42 -> V_45 != V_47 ) {
F_26 ( V_42 ) ;
goto V_44;
}
F_27 ( V_5 ) ;
F_28 ( V_5 , & V_42 -> V_2 ) ;
V_43 = 0 ;
V_44:
return V_43 ;
}
static T_4 F_29 ( struct V_4 * V_5 ,
struct V_11 * V_12 )
{
struct V_48 * V_49 = F_30 ( V_5 ) ;
int V_50 = V_38 ;
struct V_39 V_40 = {
. V_51 = V_12 -> V_52 ,
. V_53 = V_54 ,
. V_55 = F_31 ( V_49 -> V_56 ) ,
. V_57 = V_58 | V_59 |
V_60 ,
. V_61 = V_49 -> V_61 ,
} ;
if ( F_22 ( V_5 , & V_40 , V_12 ) )
goto V_43;
if ( ! V_49 -> V_62 ) {
V_49 -> V_62 = F_32 ( F_33 ( V_5 ) -> V_6 , 0 ,
V_63 ) ;
}
V_50 = F_3 ( V_5 ) ;
if ( F_34 ( F_35 ( V_50 ) ) )
V_12 -> V_13 . V_14 ++ ;
else
V_50 = V_64 ;
V_44:
return V_50 ;
V_43:
F_9 ( V_12 , V_5 ) ;
goto V_44;
}
static T_4 F_36 ( struct V_4 * V_5 , struct V_11 * V_6 )
{
F_37 ( V_5 , F_38 ( V_5 ) ) ;
switch ( V_5 -> V_8 ) {
case F_8 ( V_9 ) :
return F_29 ( V_5 , V_6 ) ;
case F_8 ( V_10 ) :
return F_21 ( V_5 , V_6 ) ;
default:
F_9 ( V_6 , V_5 ) ;
return V_38 ;
}
}
static T_4 F_39 ( struct V_4 * V_5 , struct V_11 * V_6 )
{
T_4 V_50 = F_36 ( V_5 , V_6 ) ;
if ( F_40 ( V_50 == V_64 || V_50 == V_65 ) ) {
struct V_16 * V_17 = F_13 ( V_6 -> V_17 ) ;
F_14 ( & V_17 -> V_18 ) ;
V_17 -> V_33 ++ ;
V_17 -> V_32 += V_5 -> V_21 ;
F_15 ( & V_17 -> V_18 ) ;
} else {
F_41 ( V_6 -> V_17 -> V_34 ) ;
}
return V_50 ;
}
static int F_42 ( struct V_66 * V_67 , struct V_4 * V_5 )
{
struct V_1 * V_2 = F_33 ( V_5 ) ;
struct V_41 * V_42 = (struct V_41 * ) V_2 ;
struct V_11 * V_6 = V_2 -> V_6 ;
unsigned int V_68 = F_43 ( V_6 ) ;
struct V_69 * V_70 ;
T_1 V_71 ;
int V_50 = - V_72 ;
if ( F_34 ( F_44 ( V_5 ) < V_68 && V_6 -> V_73 ) ) {
struct V_4 * V_74 ;
V_74 = F_45 ( V_5 , F_43 ( V_6 ) ) ;
if ( ! V_74 ) {
V_50 = - V_75 ;
goto V_43;
}
if ( V_5 -> V_67 )
F_46 ( V_74 , V_5 -> V_67 ) ;
F_47 ( V_5 ) ;
V_5 = V_74 ;
}
F_48 () ;
V_71 = ( V_76 T_1 ) F_49 ( V_42 , F_30 ( V_5 ) -> V_61 ) ;
V_70 = F_50 ( V_6 , V_71 ) ;
if ( F_34 ( ! V_70 ) )
V_70 = F_51 ( & V_77 , & V_71 , V_6 , false ) ;
if ( ! F_25 ( V_70 ) )
V_50 = F_52 ( V_2 , V_70 , V_5 ) ;
F_53 () ;
V_43:
if ( F_34 ( V_50 < 0 ) )
F_9 ( V_5 -> V_6 , V_5 ) ;
return V_50 ;
}
static int F_54 ( struct V_66 * V_67 , struct V_4 * V_5 )
{
struct V_11 * V_6 = F_33 ( V_5 ) -> V_6 ;
F_55 ( F_24 ( V_6 ) , V_78 , V_5 -> V_21 ) ;
V_5 -> V_6 = V_6 ;
V_5 -> V_8 = F_8 ( V_9 ) ;
return F_56 ( V_79 , V_80 , V_67 , V_5 ,
NULL , V_6 ,
F_42 ,
! ( F_57 ( V_5 ) -> V_81 & V_82 ) ) ;
}
static void F_58 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = (struct V_1 * ) V_84 -> V_85 ;
F_59 ( V_2 ) ;
V_84 -> V_85 = NULL ;
}
static struct V_41 * F_60 ( struct V_11 * V_6 )
{
struct V_41 * V_85 ;
V_85 = F_61 ( & V_86 , V_6 , 2 ,
V_87 ,
( V_88 | V_89 | V_90 ) ) ;
if ( V_85 ) {
V_85 -> V_2 . V_91 = F_54 ;
V_85 -> V_92 = F_62 ( F_24 ( V_6 ) ) ;
V_85 -> V_93 = 0 ;
V_85 -> V_45 = V_46 ;
V_85 -> V_94 = 0 ;
V_85 -> V_95 = 0 ;
V_85 -> V_96 = 0 ;
V_85 -> V_97 = 0 ;
V_85 -> V_98 = 0 ;
F_63 ( & V_85 -> V_99 ) ;
V_85 -> V_100 = NULL ;
}
return V_85 ;
}
static void F_64 ( struct V_11 * V_6 )
{
unsigned int V_81 = V_6 -> V_81 ;
int V_50 ;
if ( ! F_65 ( V_6 ) )
return;
V_50 = F_66 ( V_6 , V_81 & ~ V_101 ) ;
if ( V_50 >= 0 )
V_50 = F_66 ( V_6 , V_81 ) ;
if ( V_50 < 0 ) {
F_67 ( V_6 ,
L_1 ,
V_6 -> V_102 ) ;
}
}
static struct V_103 * F_68 ( struct V_104 * V_105 ,
struct V_11 * V_6 )
{
struct V_106 * V_107 = & V_105 -> V_108 ;
struct V_103 * V_103 ;
F_69 (slave, head, list) {
if ( V_103 -> V_6 == V_6 )
return V_103 ;
}
return NULL ;
}
static void F_70 ( struct V_104 * V_105 , struct V_103 * V_103 )
{
F_71 ( & V_103 -> V_109 ) ;
}
static void F_72 ( struct V_104 * V_105 , struct V_103 * V_103 )
{
F_73 ( & V_103 -> V_109 , & V_105 -> V_108 ) ;
}
static int F_74 ( struct V_11 * V_6 , struct V_11 * V_110 )
{
struct V_111 * V_112 = F_75 ( sizeof( * V_112 ) , V_113 ) ;
struct V_103 * V_103 = F_76 ( sizeof( * V_103 ) , V_113 ) ;
struct V_83 * V_84 = F_77 ( V_6 ) ;
struct V_104 * V_105 = & V_84 -> V_105 ;
int V_50 = - V_75 ;
if ( ! V_103 || ! V_112 )
goto V_114;
V_103 -> V_6 = V_110 ;
V_112 -> V_52 = V_6 -> V_52 ;
V_112 -> V_115 = V_84 -> V_115 ;
V_50 = F_78 ( V_110 , F_11 , V_6 ) ;
if ( V_50 ) {
F_67 ( V_110 ,
L_2 ,
V_110 -> V_102 ) ;
goto V_114;
}
V_50 = F_79 ( V_110 , V_6 ) ;
if ( V_50 < 0 )
goto V_116;
V_110 -> V_81 |= V_117 ;
F_72 ( V_105 , V_103 ) ;
F_80 ( V_110 -> V_112 , V_112 ) ;
F_64 ( V_110 ) ;
return 0 ;
V_116:
F_81 ( V_110 ) ;
V_114:
F_82 ( V_112 ) ;
F_82 ( V_103 ) ;
return V_50 ;
}
static int F_83 ( struct V_11 * V_6 , struct V_11 * V_110 )
{
if ( F_84 ( V_110 ) || F_85 ( V_110 ) )
return - V_72 ;
return F_74 ( V_6 , V_110 ) ;
}
static int F_86 ( struct V_11 * V_6 , struct V_11 * V_110 )
{
struct V_111 * V_112 = F_87 ( V_110 -> V_112 ) ;
struct V_83 * V_84 = F_77 ( V_6 ) ;
struct V_104 * V_105 = & V_84 -> V_105 ;
struct V_103 * V_103 ;
F_88 ( V_110 -> V_112 , NULL ) ;
F_89 ( V_110 , V_6 ) ;
V_110 -> V_81 &= ~ V_117 ;
F_81 ( V_110 ) ;
F_82 ( V_112 ) ;
F_64 ( V_110 ) ;
V_103 = F_68 ( V_105 , V_110 ) ;
if ( V_103 )
F_70 ( V_105 , V_103 ) ;
F_82 ( V_103 ) ;
return 0 ;
}
static int F_90 ( struct V_11 * V_6 , struct V_11 * V_110 )
{
return F_86 ( V_6 , V_110 ) ;
}
static void F_91 ( struct V_11 * V_6 )
{
struct V_83 * V_84 = F_77 ( V_6 ) ;
struct V_104 * V_105 = & V_84 -> V_105 ;
struct V_106 * V_107 = & V_105 -> V_108 ;
struct V_103 * V_103 , * V_118 ;
F_58 ( V_84 ) ;
F_92 (slave, next, head, list)
F_90 ( V_6 , V_103 -> V_6 ) ;
F_93 ( V_6 -> V_17 ) ;
V_6 -> V_17 = NULL ;
}
static int F_94 ( struct V_11 * V_6 )
{
struct V_83 * V_84 = F_77 ( V_6 ) ;
F_63 ( & V_84 -> V_105 . V_108 ) ;
V_6 -> V_17 = F_95 ( struct V_16 ) ;
if ( ! V_6 -> V_17 )
goto V_119;
V_84 -> V_85 = F_60 ( V_6 ) ;
if ( ! V_84 -> V_85 )
goto V_120;
V_6 -> V_81 = V_121 | V_122 ;
return 0 ;
V_120:
F_93 ( V_6 -> V_17 ) ;
V_6 -> V_17 = NULL ;
V_119:
return - V_75 ;
}
static void F_96 ( struct V_11 * V_6 ,
struct V_123 * V_124 )
{
F_97 ( V_124 -> V_125 , V_126 , sizeof( V_124 -> V_125 ) ) ;
F_97 ( V_124 -> V_127 , V_128 , sizeof( V_124 -> V_127 ) ) ;
}
static void F_98 ( struct V_11 * V_6 )
{
F_99 ( V_6 ) ;
V_6 -> V_129 = & V_130 ;
V_6 -> V_131 = & V_132 ;
V_6 -> V_133 = V_134 ;
F_100 ( V_6 ) ;
V_6 -> V_135 |= V_136 ;
V_6 -> V_135 |= V_137 ;
}
static int F_101 ( struct V_138 * V_139 [] , struct V_138 * V_140 [] )
{
if ( V_139 [ V_141 ] ) {
if ( F_102 ( V_139 [ V_141 ] ) != V_142 )
return - V_72 ;
if ( ! F_103 ( F_104 ( V_139 [ V_141 ] ) ) )
return - V_143 ;
}
return 0 ;
}
static void F_105 ( struct V_11 * V_6 , struct V_106 * V_107 )
{
struct V_111 * V_112 = F_87 ( V_6 -> V_112 ) ;
F_88 ( V_6 -> V_112 , NULL ) ;
F_106 ( V_112 , V_144 ) ;
F_107 ( V_6 , V_107 ) ;
}
static int F_108 ( struct V_145 * V_146 , struct V_11 * V_6 ,
struct V_138 * V_139 [] , struct V_138 * V_140 [] )
{
struct V_83 * V_84 = F_77 ( V_6 ) ;
struct V_111 * V_112 ;
int V_43 ;
if ( ! V_140 || ! V_140 [ V_147 ] )
return - V_72 ;
V_84 -> V_115 = F_109 ( V_140 [ V_147 ] ) ;
V_6 -> V_148 |= V_149 ;
V_43 = - V_75 ;
V_112 = F_75 ( sizeof( * V_6 -> V_112 ) , V_113 ) ;
if ( ! V_112 )
goto V_114;
V_112 -> V_52 = V_6 -> V_52 ;
V_112 -> V_115 = V_84 -> V_115 ;
V_43 = F_110 ( V_6 ) ;
if ( V_43 < 0 )
goto V_114;
F_80 ( V_6 -> V_112 , V_112 ) ;
return 0 ;
V_114:
F_82 ( V_112 ) ;
V_134 ( V_6 ) ;
return V_43 ;
}
static T_5 F_111 ( const struct V_11 * V_6 )
{
return F_112 ( sizeof( T_1 ) ) ;
}
static int F_113 ( struct V_4 * V_5 ,
const struct V_11 * V_6 )
{
struct V_83 * V_84 = F_77 ( V_6 ) ;
return F_114 ( V_5 , V_147 , V_84 -> V_115 ) ;
}
static int F_115 ( struct V_150 * V_151 ,
unsigned long V_152 , void * V_153 )
{
struct V_11 * V_6 = F_116 ( V_153 ) ;
if ( V_152 == V_154 ) {
struct V_111 * V_112 = F_87 ( V_6 -> V_112 ) ;
struct V_11 * V_12 ;
if ( ! V_112 || F_84 ( V_6 ) )
goto V_44;
V_12 = F_117 ( V_6 ) ;
F_90 ( V_12 , V_6 ) ;
}
V_44:
return V_155 ;
}
static int T_6 F_118 ( void )
{
int V_156 ;
V_86 . V_157 =
F_119 ( L_3 ,
sizeof( struct V_41 ) , 0 ,
V_158 ,
NULL ) ;
if ( ! V_86 . V_157 )
return - V_75 ;
F_120 ( & V_159 ) ;
V_156 = F_121 ( & V_160 ) ;
if ( V_156 < 0 )
goto error;
return 0 ;
error:
F_122 ( & V_159 ) ;
F_123 ( V_86 . V_157 ) ;
return V_156 ;
}
static void T_7 F_124 ( void )
{
F_125 ( & V_160 ) ;
F_122 ( & V_159 ) ;
F_123 ( V_86 . V_157 ) ;
}

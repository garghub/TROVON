static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_5 ) ;
F_3 ( & V_5 -> V_6 ) ;
V_5 -> V_7 ++ ;
V_5 -> V_8 += V_3 ;
F_4 ( & V_5 -> V_6 ) ;
}
static void F_5 ( struct V_1 * V_9 , struct V_10 * V_11 )
{
V_9 -> V_12 . V_13 ++ ;
F_6 ( V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_14 * V_12 )
{
int V_15 ;
F_8 (i) {
const struct V_4 * V_5 ;
T_1 V_16 , V_17 , V_18 , V_19 , V_20 ;
unsigned int V_21 ;
V_5 = F_9 ( V_2 -> V_5 , V_15 ) ;
do {
V_21 = F_10 ( & V_5 -> V_6 ) ;
V_16 = V_5 -> V_22 ;
V_17 = V_5 -> V_23 ;
V_18 = V_5 -> V_24 ;
V_19 = V_5 -> V_8 ;
V_20 = V_5 -> V_7 ;
} while ( F_11 ( & V_5 -> V_6 , V_21 ) );
V_12 -> V_22 += V_16 ;
V_12 -> V_25 += V_17 ;
V_12 -> V_26 += V_18 ;
V_12 -> V_8 += V_19 ;
V_12 -> V_27 += V_20 ;
}
}
static bool F_12 ( const struct V_1 * V_2 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
if ( V_2 -> V_32 > 1 )
return false ;
V_29 = F_13 ( V_2 , 0 ) ;
V_31 = F_14 ( V_29 -> V_31 ) ;
return ! V_31 -> V_33 ;
}
static int F_15 ( struct V_10 * V_11 , struct V_1 * V_2 ,
struct V_34 * V_35 )
{
int V_3 = V_11 -> V_3 ;
F_16 ( V_11 ) ;
F_17 ( V_11 , V_35 ) ;
F_18 ( V_11 ) ;
V_11 -> V_36 = V_37 ;
V_11 -> V_38 = F_19 ( V_11 , V_2 ) ;
if ( F_20 ( F_21 ( V_11 ) == V_39 ) )
F_1 ( V_2 , V_3 ) ;
else
F_22 ( V_2 -> V_5 -> V_40 ) ;
return V_41 ;
}
static int F_23 ( struct V_42 * V_42 , struct V_43 * V_44 ,
struct V_10 * V_11 )
{
int V_45 ;
V_45 = F_24 ( V_46 , V_47 , V_42 ,
V_44 , V_11 , NULL , F_25 ( V_11 ) -> V_2 , V_48 ) ;
if ( F_20 ( V_45 == 1 ) )
V_45 = V_48 ( V_42 , V_44 , V_11 ) ;
return V_45 ;
}
static T_2 F_26 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
const struct V_49 * V_50 = F_27 ( V_11 ) ;
struct V_42 * V_42 = F_28 ( V_11 -> V_2 ) ;
struct V_51 V_52 = {
. V_53 = V_2 -> V_54 ,
. V_55 = V_56 ,
. V_57 = V_50 -> V_57 ,
. V_58 = V_50 -> V_58 ,
. V_59 = F_29 ( V_50 ) ,
. V_60 = V_11 -> V_61 ,
. V_62 = V_50 -> V_63 ,
. V_64 = V_65 ,
} ;
int V_66 = V_67 ;
struct V_34 * V_35 ;
struct V_34 * V_68 = & V_42 -> V_69 . V_70 -> V_35 ;
V_35 = F_30 ( V_42 , NULL , & V_52 ) ;
if ( V_35 == V_68 )
goto V_45;
F_31 ( V_11 ) ;
if ( V_35 -> V_2 == V_2 )
return F_15 ( V_11 , V_2 , V_35 ) ;
F_17 ( V_11 , V_35 ) ;
F_32 ( V_11 , F_33 ( V_11 ) ) ;
V_66 = F_23 ( V_42 , V_11 -> V_44 , V_11 ) ;
if ( F_34 ( F_35 ( V_66 ) ) )
V_2 -> V_12 . V_13 ++ ;
else
V_66 = V_71 ;
return V_66 ;
V_45:
F_5 ( V_2 , V_11 ) ;
return V_67 ;
}
static T_2 F_26 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
F_5 ( V_2 , V_11 ) ;
return V_67 ;
}
static int F_36 ( struct V_42 * V_42 , struct V_43 * V_44 ,
struct V_10 * V_11 )
{
int V_45 ;
V_45 = F_24 ( V_72 , V_47 , V_42 , V_44 ,
V_11 , NULL , F_25 ( V_11 ) -> V_2 , V_48 ) ;
if ( F_20 ( V_45 == 1 ) )
V_45 = V_48 ( V_42 , V_44 , V_11 ) ;
return V_45 ;
}
static T_2 F_37 ( struct V_10 * V_11 ,
struct V_1 * V_9 )
{
struct V_73 * V_74 = F_38 ( V_11 ) ;
int V_66 = V_67 ;
struct V_75 V_76 = {
. V_77 = V_9 -> V_54 ,
. V_78 = V_56 ,
. V_79 = F_39 ( V_74 -> V_80 ) ,
. V_81 = V_82 | V_65 ,
. V_83 = V_74 -> V_38 ,
. V_57 = V_74 -> V_57 ,
. V_58 = V_74 -> V_58 ,
} ;
struct V_42 * V_42 = F_28 ( V_9 ) ;
struct V_84 * V_85 ;
V_85 = F_40 ( V_42 , & V_76 , NULL ) ;
if ( F_41 ( V_85 ) )
goto V_45;
F_31 ( V_11 ) ;
if ( V_85 -> V_35 . V_2 == V_9 )
return F_15 ( V_11 , V_9 , & V_85 -> V_35 ) ;
F_17 ( V_11 , & V_85 -> V_35 ) ;
F_32 ( V_11 , F_33 ( V_11 ) ) ;
if ( ! V_74 -> V_58 ) {
V_74 -> V_58 = F_42 ( F_25 ( V_11 ) -> V_2 , 0 ,
V_86 ) ;
}
V_66 = F_36 ( F_28 ( F_25 ( V_11 ) -> V_2 ) , V_11 -> V_44 , V_11 ) ;
if ( F_34 ( F_35 ( V_66 ) ) )
V_9 -> V_12 . V_13 ++ ;
else
V_66 = V_71 ;
V_87:
return V_66 ;
V_45:
F_5 ( V_9 , V_11 ) ;
goto V_87;
}
static T_2 F_43 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
switch ( V_11 -> V_38 ) {
case F_44 ( V_88 ) :
return F_37 ( V_11 , V_2 ) ;
case F_44 ( V_89 ) :
return F_26 ( V_11 , V_2 ) ;
default:
F_5 ( V_2 , V_11 ) ;
return V_67 ;
}
}
static T_2 F_45 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
int V_3 = V_11 -> V_3 ;
T_2 V_66 = F_43 ( V_11 , V_2 ) ;
if ( F_20 ( V_66 == V_71 || V_66 == V_90 ) ) {
struct V_4 * V_5 = F_2 ( V_2 -> V_5 ) ;
F_3 ( & V_5 -> V_6 ) ;
V_5 -> V_23 ++ ;
V_5 -> V_22 += V_3 ;
F_4 ( & V_5 -> V_6 ) ;
} else {
F_22 ( V_2 -> V_5 -> V_24 ) ;
}
return V_66 ;
}
static int F_46 ( struct V_42 * V_42 , struct V_43 * V_44 ,
struct V_10 * V_11 )
{
struct V_1 * V_9 = V_11 -> V_2 ;
if ( ! F_47 ( & V_9 -> V_91 ) &&
F_20 ( F_48 ( V_11 ) >= V_92 ) ) {
struct V_93 * V_94 = F_49 ( V_11 , V_92 ) ;
F_50 ( V_94 -> V_95 , V_9 -> V_96 ) ;
F_51 ( V_94 -> V_97 ) ;
V_94 -> V_98 = V_11 -> V_38 ;
F_52 () ;
F_53 ( V_11 , V_9 ) ;
F_54 () ;
F_55 ( V_11 , V_92 ) ;
}
return 1 ;
}
static int F_56 ( struct V_42 * V_42 , struct V_43 * V_44 ,
struct V_10 * V_11 )
{
struct V_34 * V_35 = F_25 ( V_11 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
int V_66 ;
F_57 ( V_11 ) ;
V_11 -> V_38 = F_44 ( V_89 ) ;
V_11 -> V_2 = V_2 ;
F_52 () ;
V_102 = F_58 ( (struct V_103 * ) V_35 , & F_27 ( V_11 ) -> V_57 ) ;
V_100 = F_59 ( V_35 -> V_2 , V_102 ) ;
if ( F_34 ( ! V_100 ) )
V_100 = F_60 ( & V_104 , V_102 , V_35 -> V_2 , false ) ;
if ( ! F_41 ( V_100 ) ) {
F_61 ( V_11 , V_100 ) ;
V_66 = F_62 ( V_100 , V_11 ) ;
F_54 () ;
return V_66 ;
}
F_54 () ;
F_63 ( F_28 ( V_35 -> V_2 ) ,
F_64 ( V_35 ) , V_105 ) ;
F_6 ( V_11 ) ;
return - V_106 ;
}
static int F_65 ( struct V_42 * V_42 , struct V_43 * V_44 , struct V_10 * V_11 )
{
return F_66 ( V_46 , V_107 ,
V_42 , V_44 , V_11 , NULL , F_25 ( V_11 ) -> V_2 ,
F_56 ,
! ( F_67 ( V_11 ) -> V_108 & V_109 ) ) ;
}
static struct V_10 * F_68 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
struct V_110 * V_111 = F_69 ( V_9 ) ;
struct V_34 * V_35 = NULL ;
struct V_103 * V_112 ;
F_70 () ;
V_112 = F_71 ( V_111 -> V_112 ) ;
if ( F_20 ( V_112 ) ) {
V_35 = & V_112 -> V_35 ;
F_72 ( V_35 ) ;
}
F_73 () ;
if ( F_34 ( ! V_35 ) ) {
F_5 ( V_9 , V_11 ) ;
return NULL ;
}
F_31 ( V_11 ) ;
F_17 ( V_11 , V_35 ) ;
return V_11 ;
}
static int F_74 ( struct V_42 * V_42 , struct V_43 * V_44 ,
struct V_10 * V_11 )
{
V_11 -> V_38 = F_44 ( V_89 ) ;
return F_66 ( V_46 , V_107 ,
V_42 , V_44 , V_11 , NULL , V_11 -> V_2 ,
F_46 ,
! ( F_75 ( V_11 ) -> V_108 & V_113 ) ) ;
}
static struct V_10 * F_76 ( struct V_1 * V_9 ,
struct V_43 * V_44 ,
struct V_10 * V_11 )
{
struct V_42 * V_42 = F_28 ( V_9 ) ;
int V_45 ;
V_11 -> V_2 = V_9 ;
V_45 = F_24 ( V_46 , V_47 , V_42 , V_44 ,
V_11 , NULL , V_9 , F_74 ) ;
if ( F_20 ( V_45 == 1 ) )
V_45 = F_74 ( V_42 , V_44 , V_11 ) ;
if ( F_20 ( V_45 == 1 ) )
F_57 ( V_11 ) ;
else
V_11 = NULL ;
return V_11 ;
}
static struct V_10 * F_77 ( struct V_1 * V_9 ,
struct V_43 * V_44 ,
struct V_10 * V_11 )
{
if ( F_78 ( & F_27 ( V_11 ) -> V_57 ) )
return V_11 ;
if ( F_12 ( V_9 ) )
return F_76 ( V_9 , V_44 , V_11 ) ;
return F_68 ( V_9 , V_11 ) ;
}
static void F_79 ( struct V_1 * V_2 , struct V_110 * V_111 )
{
struct V_103 * V_112 = F_80 ( V_111 -> V_112 ) ;
struct V_42 * V_42 = F_28 ( V_2 ) ;
struct V_34 * V_35 ;
F_81 ( V_111 -> V_112 , NULL ) ;
F_82 () ;
if ( V_112 ) {
V_35 = & V_112 -> V_35 ;
F_83 ( V_35 -> V_2 ) ;
V_35 -> V_2 = V_42 -> V_114 ;
F_84 ( V_35 -> V_2 ) ;
F_85 ( V_35 ) ;
}
}
static int F_86 ( struct V_1 * V_2 )
{
int V_108 = V_115 | V_116 | V_117 ;
struct V_110 * V_111 = F_69 ( V_2 ) ;
struct V_42 * V_42 = F_28 ( V_2 ) ;
struct V_118 * V_119 ;
struct V_103 * V_112 ;
int V_120 = - V_121 ;
if ( ! F_87 () )
return 0 ;
V_119 = F_88 ( V_42 , V_111 -> V_122 ) ;
if ( ! V_119 )
goto V_87;
V_112 = F_89 ( V_42 , V_2 , V_108 ) ;
if ( ! V_112 )
goto V_87;
V_112 -> V_119 = V_119 ;
V_112 -> V_35 . V_123 = F_65 ;
F_90 ( V_111 -> V_112 , V_112 ) ;
V_120 = 0 ;
V_87:
return V_120 ;
}
static struct V_10 * F_77 ( struct V_1 * V_9 ,
struct V_43 * V_44 ,
struct V_10 * V_11 )
{
return V_11 ;
}
static void F_79 ( struct V_1 * V_2 , struct V_110 * V_111 )
{
}
static int F_86 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_91 ( struct V_42 * V_42 , struct V_43 * V_44 , struct V_10 * V_11 )
{
struct V_34 * V_35 = F_25 ( V_11 ) ;
struct V_84 * V_85 = (struct V_84 * ) V_35 ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned int V_124 = F_92 ( V_2 ) ;
struct V_99 * V_100 ;
T_3 V_102 ;
int V_66 = - V_106 ;
F_57 ( V_11 ) ;
if ( F_34 ( F_48 ( V_11 ) < V_124 && V_2 -> V_125 ) ) {
struct V_10 * V_126 ;
V_126 = F_93 ( V_11 , F_92 ( V_2 ) ) ;
if ( ! V_126 ) {
V_66 = - V_121 ;
goto V_45;
}
if ( V_11 -> V_44 )
F_94 ( V_126 , V_11 -> V_44 ) ;
F_95 ( V_11 ) ;
V_11 = V_126 ;
}
F_52 () ;
V_102 = ( V_127 T_3 ) F_96 ( V_85 , F_38 ( V_11 ) -> V_57 ) ;
V_100 = F_97 ( V_2 , V_102 ) ;
if ( F_34 ( ! V_100 ) )
V_100 = F_60 ( & V_128 , & V_102 , V_2 , false ) ;
if ( ! F_41 ( V_100 ) ) {
F_61 ( V_11 , V_100 ) ;
V_66 = F_62 ( V_100 , V_11 ) ;
}
F_54 () ;
V_45:
if ( F_34 ( V_66 < 0 ) )
F_5 ( V_11 -> V_2 , V_11 ) ;
return V_66 ;
}
static int F_98 ( struct V_42 * V_42 , struct V_43 * V_44 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_25 ( V_11 ) -> V_2 ;
F_99 ( V_42 , V_129 , V_11 -> V_3 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_38 = F_44 ( V_88 ) ;
return F_66 ( V_72 , V_107 ,
V_42 , V_44 , V_11 , NULL , V_2 ,
F_91 ,
! ( F_75 ( V_11 ) -> V_108 & V_113 ) ) ;
}
static struct V_10 * F_100 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
struct V_110 * V_111 = F_69 ( V_9 ) ;
struct V_34 * V_35 = NULL ;
struct V_84 * V_130 ;
F_70 () ;
V_130 = F_71 ( V_111 -> V_130 ) ;
if ( F_20 ( V_130 ) ) {
V_35 = & V_130 -> V_35 ;
F_72 ( V_35 ) ;
}
F_73 () ;
if ( F_34 ( ! V_35 ) ) {
F_5 ( V_9 , V_11 ) ;
return NULL ;
}
F_31 ( V_11 ) ;
F_17 ( V_11 , V_35 ) ;
return V_11 ;
}
static int F_101 ( struct V_42 * V_42 , struct V_43 * V_44 ,
struct V_10 * V_11 )
{
V_11 -> V_38 = F_44 ( V_88 ) ;
return F_66 ( V_72 , V_107 ,
V_42 , V_44 , V_11 , NULL , V_11 -> V_2 ,
F_46 ,
! ( F_75 ( V_11 ) -> V_108 & V_113 ) ) ;
}
static struct V_10 * F_102 ( struct V_1 * V_9 ,
struct V_43 * V_44 ,
struct V_10 * V_11 )
{
struct V_42 * V_42 = F_28 ( V_9 ) ;
int V_45 ;
V_11 -> V_2 = V_9 ;
V_45 = F_24 ( V_72 , V_47 , V_42 , V_44 ,
V_11 , NULL , V_9 , F_101 ) ;
if ( F_20 ( V_45 == 1 ) )
V_45 = F_101 ( V_42 , V_44 , V_11 ) ;
if ( F_20 ( V_45 == 1 ) )
F_57 ( V_11 ) ;
else
V_11 = NULL ;
return V_11 ;
}
static struct V_10 * F_103 ( struct V_1 * V_9 ,
struct V_43 * V_44 ,
struct V_10 * V_11 )
{
if ( F_104 ( F_38 ( V_11 ) -> V_57 ) )
return V_11 ;
if ( F_12 ( V_9 ) )
return F_102 ( V_9 , V_44 , V_11 ) ;
return F_100 ( V_9 , V_11 ) ;
}
static struct V_10 * F_105 ( struct V_1 * V_9 ,
struct V_43 * V_44 ,
struct V_10 * V_11 ,
T_4 V_131 )
{
switch ( V_131 ) {
case V_132 :
return F_103 ( V_9 , V_44 , V_11 ) ;
case V_133 :
return F_77 ( V_9 , V_44 , V_11 ) ;
}
return V_11 ;
}
static void F_106 ( struct V_1 * V_2 , struct V_110 * V_111 )
{
struct V_84 * V_130 = F_80 ( V_111 -> V_130 ) ;
struct V_42 * V_42 = F_28 ( V_2 ) ;
struct V_34 * V_35 ;
F_81 ( V_111 -> V_130 , NULL ) ;
F_82 () ;
if ( V_130 ) {
V_35 = & V_130 -> V_35 ;
F_83 ( V_35 -> V_2 ) ;
V_35 -> V_2 = V_42 -> V_114 ;
F_84 ( V_35 -> V_2 ) ;
F_85 ( V_35 ) ;
}
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = F_69 ( V_2 ) ;
struct V_84 * V_130 ;
if ( ! F_108 ( F_28 ( V_2 ) , V_111 -> V_122 ) )
return - V_121 ;
V_130 = F_109 ( V_2 , 0 , V_134 , 1 , 1 , 0 ) ;
if ( ! V_130 )
return - V_121 ;
V_130 -> V_35 . V_123 = F_98 ;
V_130 -> V_135 = V_111 -> V_122 ;
F_90 ( V_111 -> V_130 , V_130 ) ;
return 0 ;
}
static void F_110 ( struct V_1 * V_2 )
{
unsigned int V_108 = V_2 -> V_108 ;
int V_66 ;
if ( ! F_111 ( V_2 ) )
return;
V_66 = F_112 ( V_2 , V_108 & ~ V_136 ) ;
if ( V_66 >= 0 )
V_66 = F_112 ( V_2 , V_108 ) ;
if ( V_66 < 0 ) {
F_113 ( V_2 ,
L_1 ,
V_2 -> V_137 ) ;
}
}
static int F_114 ( struct V_1 * V_2 , struct V_1 * V_138 )
{
int V_66 ;
if ( V_138 == F_28 ( V_2 ) -> V_114 )
return - V_139 ;
V_138 -> V_140 |= V_141 ;
V_66 = F_115 ( V_138 , V_2 , NULL , NULL ) ;
if ( V_66 < 0 )
goto V_45;
F_110 ( V_138 ) ;
return 0 ;
V_45:
V_138 -> V_140 &= ~ V_141 ;
return V_66 ;
}
static int F_116 ( struct V_1 * V_2 , struct V_1 * V_138 )
{
if ( F_117 ( V_138 ) || F_118 ( V_138 ) )
return - V_106 ;
return F_114 ( V_2 , V_138 ) ;
}
static int F_119 ( struct V_1 * V_2 , struct V_1 * V_138 )
{
F_120 ( V_138 , V_2 ) ;
V_138 -> V_140 &= ~ V_141 ;
F_110 ( V_138 ) ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 , struct V_1 * V_138 )
{
return F_119 ( V_2 , V_138 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = F_69 ( V_2 ) ;
F_106 ( V_2 , V_111 ) ;
F_79 ( V_2 , V_111 ) ;
F_123 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static int F_124 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = F_69 ( V_2 ) ;
V_2 -> V_5 = F_125 ( struct V_4 ) ;
if ( ! V_2 -> V_5 )
goto V_142;
if ( F_107 ( V_2 ) != 0 )
goto V_143;
if ( F_86 ( V_2 ) != 0 )
goto V_144;
V_2 -> V_108 = V_145 | V_146 ;
V_2 -> V_147 = 64 * 1024 ;
V_2 -> V_148 = V_149 ;
F_126 ( V_2 ) ;
return 0 ;
V_144:
F_106 ( V_2 , V_111 ) ;
V_143:
F_123 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_142:
return - V_121 ;
}
static T_3 F_127 ( const struct V_1 * V_2 )
{
struct V_110 * V_111 = F_69 ( V_2 ) ;
return V_111 -> V_122 ;
}
static int F_128 ( struct V_42 * V_42 , struct V_43 * V_44 , struct V_10 * V_11 )
{
F_6 ( V_11 ) ;
return 0 ;
}
static struct V_10 * F_129 ( T_5 V_150 , unsigned int V_151 ,
struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_42 * V_42 = F_28 ( V_2 ) ;
if ( F_24 ( V_150 , V_151 , V_42 , NULL , V_11 , V_2 , NULL , F_128 ) != 1 )
V_11 = NULL ;
return V_11 ;
}
static bool F_130 ( const struct V_10 * V_11 )
{
const struct V_49 * V_50 = F_27 ( V_11 ) ;
bool V_120 = false ;
if ( V_50 -> V_63 == V_152 ) {
const struct V_153 * V_154 ;
struct V_153 V_155 ;
V_154 = F_131 ( V_11 , sizeof( * V_50 ) ,
sizeof( V_155 ) , & V_155 ) ;
if ( ! V_154 )
goto V_87;
switch ( V_154 -> V_156 ) {
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
V_120 = true ;
break;
}
}
V_87:
return V_120 ;
}
static struct V_103 * F_132 ( struct V_42 * V_42 ,
const struct V_1 * V_2 ,
struct V_51 * V_52 ,
int V_54 ,
int V_108 )
{
struct V_110 * V_111 = F_69 ( V_2 ) ;
struct V_118 * V_162 = NULL ;
struct V_103 * V_112 ;
F_70 () ;
V_112 = F_71 ( V_111 -> V_112 ) ;
if ( F_20 ( V_112 ) )
V_162 = V_112 -> V_119 ;
F_73 () ;
if ( ! V_162 )
return NULL ;
return F_133 ( V_42 , V_162 , V_54 , V_52 , V_108 ) ;
}
static void F_134 ( struct V_10 * V_11 , struct V_1 * V_9 ,
int V_54 )
{
const struct V_49 * V_50 = F_27 ( V_11 ) ;
struct V_51 V_52 = {
. V_55 = V_54 ,
. V_60 = V_11 -> V_61 ,
. V_62 = V_50 -> V_63 ,
. V_57 = V_50 -> V_57 ,
. V_58 = V_50 -> V_58 ,
. V_59 = F_29 ( V_50 ) ,
} ;
struct V_42 * V_42 = F_28 ( V_9 ) ;
struct V_103 * V_112 ;
V_112 = F_132 ( V_42 , V_9 , & V_52 , V_54 ,
V_163 | V_164 ) ;
if ( F_34 ( ! V_112 ) )
return;
if ( F_34 ( & V_112 -> V_35 == & V_42 -> V_69 . V_70 -> V_35 ) )
return;
F_17 ( V_11 , & V_112 -> V_35 ) ;
}
static struct V_10 * F_135 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
int V_165 = V_11 -> V_166 ;
bool V_167 ;
if ( V_11 -> V_36 == V_37 ) {
V_11 -> V_2 = V_9 ;
V_11 -> V_166 = V_9 -> V_54 ;
F_67 ( V_11 ) -> V_108 |= V_168 ;
V_11 -> V_36 = V_169 ;
goto V_87;
}
V_167 = F_78 ( & F_27 ( V_11 ) -> V_57 ) ;
if ( ! F_130 ( V_11 ) && ! V_167 ) {
F_1 ( V_9 , V_11 -> V_3 ) ;
V_11 -> V_2 = V_9 ;
V_11 -> V_166 = V_9 -> V_54 ;
if ( ! F_47 ( & V_9 -> V_91 ) ) {
F_49 ( V_11 , V_11 -> V_170 ) ;
F_53 ( V_11 , V_9 ) ;
F_55 ( V_11 , V_11 -> V_170 ) ;
}
F_67 ( V_11 ) -> V_108 |= V_168 ;
}
if ( V_167 )
F_134 ( V_11 , V_9 , V_165 ) ;
V_11 = F_129 ( V_46 , V_171 , V_11 , V_9 ) ;
V_87:
return V_11 ;
}
static struct V_10 * F_135 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
return V_11 ;
}
static struct V_10 * F_136 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
V_11 -> V_2 = V_9 ;
V_11 -> V_166 = V_9 -> V_54 ;
F_75 ( V_11 ) -> V_108 |= V_172 ;
if ( F_104 ( F_38 ( V_11 ) -> V_57 ) )
goto V_87;
if ( V_11 -> V_36 == V_37 ) {
V_11 -> V_36 = V_169 ;
goto V_87;
}
F_1 ( V_9 , V_11 -> V_3 ) ;
if ( ! F_47 ( & V_9 -> V_91 ) ) {
F_49 ( V_11 , V_11 -> V_170 ) ;
F_53 ( V_11 , V_9 ) ;
F_55 ( V_11 , V_11 -> V_170 ) ;
}
V_11 = F_129 ( V_72 , V_171 , V_11 , V_9 ) ;
V_87:
return V_11 ;
}
static struct V_10 * F_137 ( struct V_1 * V_9 ,
struct V_10 * V_11 ,
T_4 V_131 )
{
switch ( V_131 ) {
case V_132 :
return F_136 ( V_9 , V_11 ) ;
case V_133 :
return F_135 ( V_9 , V_11 ) ;
}
return V_11 ;
}
static struct V_34 * F_138 ( const struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_42 * V_42 = F_28 ( V_2 ) ;
int V_108 = V_164 ;
struct V_34 * V_35 = NULL ;
struct V_103 * V_85 ;
if ( V_52 -> V_53 == V_2 -> V_54 ) {
V_35 = & V_42 -> V_69 . V_70 -> V_35 ;
F_72 ( V_35 ) ;
return V_35 ;
}
if ( ! F_139 ( & V_52 -> V_58 ) )
V_108 |= V_163 ;
V_85 = F_132 ( V_42 , V_2 , V_52 , V_52 -> V_53 , V_108 ) ;
if ( V_85 )
V_35 = & V_85 -> V_35 ;
return V_35 ;
}
static void F_140 ( struct V_1 * V_2 ,
struct V_173 * V_174 )
{
F_141 ( V_174 -> V_175 , V_176 , sizeof( V_174 -> V_175 ) ) ;
F_141 ( V_174 -> V_177 , V_178 , sizeof( V_174 -> V_177 ) ) ;
}
static inline T_6 F_142 ( void )
{
T_6 V_179 ;
V_179 = F_143 ( sizeof( struct V_180 ) ) ;
V_179 += F_144 ( sizeof( T_5 ) ) ;
V_179 += F_144 ( sizeof( T_3 ) ) ;
return V_179 ;
}
static int F_145 ( const struct V_1 * V_2 , T_7 V_181 , bool V_182 )
{
struct V_180 * V_183 ;
struct V_184 * V_185 ;
struct V_10 * V_11 ;
int V_45 ;
if ( V_181 == V_133 && ! F_87 () )
return 0 ;
V_11 = F_146 ( F_142 () , V_186 ) ;
if ( ! V_11 )
return - V_121 ;
V_185 = F_147 ( V_11 , 0 , 0 , 0 , sizeof( * V_183 ) , 0 ) ;
if ( ! V_185 )
goto V_187;
V_185 -> V_188 |= V_189 ;
V_183 = F_148 ( V_185 ) ;
memset ( V_183 , 0 , sizeof( * V_183 ) ) ;
V_183 -> V_181 = V_181 ;
V_183 -> V_190 = V_191 ;
if ( F_149 ( V_11 , V_192 , 1 ) )
goto V_187;
if ( F_150 ( V_11 , V_193 , V_194 ) )
goto V_187;
F_151 ( V_11 , V_185 ) ;
V_11 -> V_44 = F_28 ( V_2 ) -> V_195 ;
if ( V_182 ) {
V_45 = F_152 ( V_11 , V_185 , NULL ) ;
if ( V_45 == - V_196 )
V_45 = 0 ;
} else {
V_45 = F_153 ( V_11 , V_185 , NULL ) ;
if ( V_45 == - V_197 )
V_45 = 0 ;
}
F_154 ( V_11 ) ;
return V_45 ;
V_187:
F_154 ( V_11 ) ;
return - V_198 ;
}
static int F_155 ( const struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_145 ( V_2 , V_132 , true ) ;
if ( V_45 < 0 )
goto V_199;
V_45 = F_145 ( V_2 , V_133 , true ) ;
if ( V_45 < 0 )
goto V_200;
#if F_156 ( V_201 )
V_45 = F_145 ( V_2 , V_202 , true ) ;
if ( V_45 < 0 )
goto V_203;
#endif
return 0 ;
#if F_156 ( V_201 )
V_203:
F_145 ( V_2 , V_133 , false ) ;
#endif
V_200:
F_145 ( V_2 , V_132 , false ) ;
V_199:
F_113 ( V_2 , L_2 ) ;
return V_45 ;
}
static void F_157 ( struct V_1 * V_2 )
{
F_158 ( V_2 ) ;
V_2 -> V_204 = & V_205 ;
V_2 -> V_206 = & V_207 ;
V_2 -> V_208 = & V_209 ;
V_2 -> V_210 = true ;
F_159 ( V_2 ) ;
V_2 -> V_211 |= V_212 ;
V_2 -> V_211 |= V_213 ;
V_2 -> V_211 |= V_214 ;
V_2 -> V_211 |= V_215 ;
V_2 -> V_211 |= V_216 | V_217 ;
V_2 -> V_211 |= V_218 | V_219 | V_220 ;
V_2 -> V_221 = V_2 -> V_211 ;
V_2 -> V_222 = V_2 -> V_211 ;
V_2 -> V_140 |= V_223 ;
}
static int F_160 ( struct V_224 * V_225 [] , struct V_224 * V_226 [] ,
struct V_227 * V_228 )
{
if ( V_225 [ V_229 ] ) {
if ( F_161 ( V_225 [ V_229 ] ) != V_230 ) {
F_162 ( V_228 , L_3 ) ;
return - V_106 ;
}
if ( ! F_163 ( F_164 ( V_225 [ V_229 ] ) ) ) {
F_162 ( V_228 , L_3 ) ;
return - V_231 ;
}
}
return 0 ;
}
static void F_165 ( struct V_1 * V_2 , struct V_232 * V_233 )
{
struct V_1 * V_138 ;
struct V_232 * V_234 ;
F_166 (dev, port_dev, iter)
F_121 ( V_2 , V_138 ) ;
F_167 ( V_2 , V_233 ) ;
}
static int F_168 ( struct V_42 * V_235 , struct V_1 * V_2 ,
struct V_224 * V_225 [] , struct V_224 * V_226 [] ,
struct V_227 * V_228 )
{
struct V_110 * V_111 = F_69 ( V_2 ) ;
bool * V_236 ;
struct V_42 * V_42 ;
int V_45 ;
if ( ! V_226 || ! V_226 [ V_237 ] ) {
F_162 ( V_228 , L_4 ) ;
return - V_106 ;
}
V_111 -> V_122 = F_169 ( V_226 [ V_237 ] ) ;
if ( V_111 -> V_122 == V_238 ) {
F_170 ( V_228 , V_226 [ V_237 ] ,
L_5 ) ;
return - V_106 ;
}
V_2 -> V_140 |= V_239 ;
V_45 = F_171 ( V_2 ) ;
if ( V_45 )
goto V_87;
V_42 = F_28 ( V_2 ) ;
V_236 = F_172 ( V_42 , V_240 ) ;
if ( * V_236 ) {
V_45 = F_155 ( V_2 ) ;
if ( V_45 ) {
F_173 ( V_2 ) ;
goto V_87;
}
* V_236 = false ;
}
V_87:
return V_45 ;
}
static T_6 F_174 ( const struct V_1 * V_2 )
{
return F_144 ( sizeof( T_3 ) ) ;
}
static int F_175 ( struct V_10 * V_11 ,
const struct V_1 * V_2 )
{
struct V_110 * V_111 = F_69 ( V_2 ) ;
return F_150 ( V_11 , V_237 , V_111 -> V_122 ) ;
}
static T_6 F_176 ( const struct V_1 * V_241 ,
const struct V_1 * V_242 )
{
return F_144 ( sizeof( T_3 ) ) ;
}
static int F_177 ( struct V_10 * V_11 ,
const struct V_1 * V_9 ,
const struct V_1 * V_242 )
{
struct V_110 * V_111 = F_69 ( V_9 ) ;
if ( F_150 ( V_11 , V_243 , V_111 -> V_122 ) )
return - V_198 ;
return 0 ;
}
static int F_178 ( struct V_244 * V_245 ,
unsigned long V_246 , void * V_247 )
{
struct V_1 * V_2 = F_179 ( V_247 ) ;
if ( V_246 == V_248 ) {
struct V_1 * V_9 ;
if ( ! F_118 ( V_2 ) )
goto V_87;
V_9 = F_180 ( V_2 ) ;
F_121 ( V_9 , V_2 ) ;
}
V_87:
return V_249 ;
}
static int T_8 F_181 ( struct V_42 * V_42 )
{
bool * V_236 = F_172 ( V_42 , V_240 ) ;
* V_236 = true ;
return 0 ;
}
static int T_9 F_182 ( void )
{
int V_120 ;
F_183 ( & V_250 ) ;
V_120 = F_184 ( & V_251 ) ;
if ( V_120 < 0 )
goto error;
V_120 = F_185 ( & V_252 ) ;
if ( V_120 < 0 ) {
F_186 ( & V_251 ) ;
goto error;
}
return 0 ;
error:
F_187 ( & V_250 ) ;
return V_120 ;
}

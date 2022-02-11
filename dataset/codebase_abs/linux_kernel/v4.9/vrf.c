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
static struct V_14 * F_7 ( struct V_1 * V_2 ,
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
return V_12 ;
}
static int F_12 ( struct V_10 * V_11 , struct V_1 * V_2 ,
struct V_28 * V_29 )
{
int V_3 = V_11 -> V_3 ;
F_13 ( V_11 ) ;
F_14 ( V_11 , V_29 ) ;
F_15 ( V_11 ) ;
V_11 -> V_30 = V_31 ;
V_11 -> V_32 = F_16 ( V_11 , V_2 ) ;
if ( F_17 ( F_18 ( V_11 ) == V_33 ) )
F_1 ( V_2 , V_3 ) ;
else
F_19 ( V_2 -> V_5 -> V_34 ) ;
return V_35 ;
}
static int F_20 ( struct V_36 * V_36 , struct V_37 * V_38 ,
struct V_10 * V_11 )
{
int V_39 ;
V_39 = F_21 ( V_40 , V_41 , V_36 ,
V_38 , V_11 , NULL , F_22 ( V_11 ) -> V_2 , V_42 ) ;
if ( F_17 ( V_39 == 1 ) )
V_39 = V_42 ( V_36 , V_38 , V_11 ) ;
return V_39 ;
}
static T_2 F_23 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
const struct V_43 * V_44 = F_24 ( V_11 ) ;
struct V_36 * V_36 = F_25 ( V_11 -> V_2 ) ;
struct V_45 V_46 = {
. V_47 = V_2 -> V_48 ,
. V_49 = V_50 ,
. V_51 = V_44 -> V_51 ,
. V_52 = V_44 -> V_52 ,
. V_53 = F_26 ( V_44 ) ,
. V_54 = V_11 -> V_55 ,
. V_56 = V_44 -> V_57 ,
. V_58 = V_59 ,
} ;
int V_60 = V_61 ;
struct V_28 * V_29 ;
struct V_28 * V_62 = & V_36 -> V_63 . V_64 -> V_29 ;
V_29 = F_27 ( V_36 , NULL , & V_46 ) ;
if ( V_29 == V_62 )
goto V_39;
F_28 ( V_11 ) ;
if ( V_29 -> V_2 == V_36 -> V_65 || V_29 -> V_2 == V_2 ) {
struct V_66 * V_67 = F_29 ( V_2 ) ;
struct V_68 * V_69 ;
F_30 ( V_29 ) ;
F_31 () ;
V_69 = F_32 ( V_67 -> V_69 ) ;
if ( F_33 ( ! V_69 ) ) {
F_34 () ;
goto V_39;
}
if ( F_33 ( ! V_69 -> V_70 ) ) {
V_69 -> V_70 = F_35 ( V_2 ) ;
if ( ! V_69 -> V_70 ) {
F_34 () ;
goto V_39;
}
}
V_29 = & V_69 -> V_29 ;
F_36 ( V_29 ) ;
F_34 () ;
return F_12 ( V_11 , V_2 , & V_69 -> V_29 ) ;
}
F_14 ( V_11 , V_29 ) ;
F_37 ( V_11 , F_38 ( V_11 ) ) ;
V_60 = F_20 ( V_36 , V_11 -> V_38 , V_11 ) ;
if ( F_33 ( F_39 ( V_60 ) ) )
V_2 -> V_12 . V_13 ++ ;
else
V_60 = V_71 ;
return V_60 ;
V_39:
F_5 ( V_2 , V_11 ) ;
return V_61 ;
}
static T_2 F_23 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
F_5 ( V_2 , V_11 ) ;
return V_61 ;
}
static int F_40 ( struct V_36 * V_36 , struct V_37 * V_38 ,
struct V_10 * V_11 )
{
int V_39 ;
V_39 = F_21 ( V_72 , V_41 , V_36 , V_38 ,
V_11 , NULL , F_22 ( V_11 ) -> V_2 , V_42 ) ;
if ( F_17 ( V_39 == 1 ) )
V_39 = V_42 ( V_36 , V_38 , V_11 ) ;
return V_39 ;
}
static T_2 F_41 ( struct V_10 * V_11 ,
struct V_1 * V_9 )
{
struct V_73 * V_74 = F_42 ( V_11 ) ;
int V_60 = V_61 ;
struct V_75 V_76 = {
. V_77 = V_9 -> V_48 ,
. V_78 = V_50 ,
. V_79 = F_43 ( V_74 -> V_80 ) ,
. V_81 = V_82 | V_59 ,
. V_51 = V_74 -> V_51 ,
} ;
struct V_36 * V_36 = F_25 ( V_9 ) ;
struct V_83 * V_84 ;
V_84 = F_44 ( V_36 , & V_76 , NULL ) ;
if ( F_45 ( V_84 ) )
goto V_39;
if ( V_84 -> V_85 != V_86 && V_84 -> V_85 != V_87 ) {
F_46 ( V_84 ) ;
goto V_39;
}
F_28 ( V_11 ) ;
if ( V_84 -> V_29 . V_2 == V_36 -> V_65 || V_84 -> V_29 . V_2 == V_9 ) {
struct V_66 * V_67 = F_29 ( V_9 ) ;
struct V_83 * V_88 ;
struct V_28 * V_29 = NULL ;
F_46 ( V_84 ) ;
F_31 () ;
V_88 = F_32 ( V_67 -> V_88 ) ;
if ( F_17 ( V_88 ) ) {
V_29 = & V_88 -> V_29 ;
F_36 ( V_29 ) ;
}
F_34 () ;
if ( F_33 ( ! V_29 ) )
goto V_39;
return F_12 ( V_11 , V_9 , V_29 ) ;
}
F_14 ( V_11 , & V_84 -> V_29 ) ;
F_37 ( V_11 , F_38 ( V_11 ) ) ;
if ( ! V_74 -> V_52 ) {
V_74 -> V_52 = F_47 ( F_22 ( V_11 ) -> V_2 , 0 ,
V_89 ) ;
}
V_60 = F_40 ( F_25 ( F_22 ( V_11 ) -> V_2 ) , V_11 -> V_38 , V_11 ) ;
if ( F_33 ( F_39 ( V_60 ) ) )
V_9 -> V_12 . V_13 ++ ;
else
V_60 = V_71 ;
V_90:
return V_60 ;
V_39:
F_5 ( V_9 , V_11 ) ;
goto V_90;
}
static T_2 F_48 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
switch ( V_11 -> V_32 ) {
case F_49 ( V_91 ) :
return F_41 ( V_11 , V_2 ) ;
case F_49 ( V_92 ) :
return F_23 ( V_11 , V_2 ) ;
default:
F_5 ( V_2 , V_11 ) ;
return V_61 ;
}
}
static T_2 F_50 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
T_2 V_60 = F_48 ( V_11 , V_2 ) ;
if ( F_17 ( V_60 == V_71 || V_60 == V_93 ) ) {
struct V_4 * V_5 = F_2 ( V_2 -> V_5 ) ;
F_3 ( & V_5 -> V_6 ) ;
V_5 -> V_23 ++ ;
V_5 -> V_22 += V_11 -> V_3 ;
F_4 ( & V_5 -> V_6 ) ;
} else {
F_19 ( V_2 -> V_5 -> V_24 ) ;
}
return V_60 ;
}
static int F_51 ( struct V_36 * V_36 , struct V_37 * V_38 ,
struct V_10 * V_11 )
{
struct V_28 * V_29 = F_22 ( V_11 ) ;
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
int V_60 ;
V_11 -> V_32 = F_49 ( V_92 ) ;
V_11 -> V_2 = V_2 ;
F_52 () ;
V_97 = F_53 ( (struct V_68 * ) V_29 , & F_24 ( V_11 ) -> V_51 ) ;
V_95 = F_54 ( V_29 -> V_2 , V_97 ) ;
if ( F_33 ( ! V_95 ) )
V_95 = F_55 ( & V_98 , V_97 , V_29 -> V_2 , false ) ;
if ( ! F_45 ( V_95 ) ) {
V_60 = F_56 ( V_29 , V_95 , V_11 ) ;
F_57 () ;
return V_60 ;
}
F_57 () ;
F_58 ( F_25 ( V_29 -> V_2 ) ,
F_59 ( V_29 ) , V_99 ) ;
F_6 ( V_11 ) ;
return - V_100 ;
}
static int F_60 ( struct V_36 * V_36 , struct V_37 * V_38 , struct V_10 * V_11 )
{
return F_61 ( V_40 , V_101 ,
V_36 , V_38 , V_11 , NULL , F_22 ( V_11 ) -> V_2 ,
F_51 ,
! ( F_62 ( V_11 ) -> V_102 & V_103 ) ) ;
}
static struct V_10 * F_63 ( struct V_1 * V_9 ,
struct V_37 * V_38 ,
struct V_10 * V_11 )
{
struct V_66 * V_67 = F_29 ( V_9 ) ;
struct V_28 * V_29 = NULL ;
struct V_68 * V_104 ;
if ( F_64 ( & F_24 ( V_11 ) -> V_51 ) )
return V_11 ;
F_31 () ;
V_104 = F_32 ( V_67 -> V_104 ) ;
if ( F_17 ( V_104 ) ) {
V_29 = & V_104 -> V_29 ;
F_36 ( V_29 ) ;
}
F_34 () ;
if ( F_33 ( ! V_29 ) ) {
F_5 ( V_9 , V_11 ) ;
return NULL ;
}
F_28 ( V_11 ) ;
F_14 ( V_11 , V_29 ) ;
return V_11 ;
}
static void F_65 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_68 * V_104 = F_66 ( V_67 -> V_104 ) ;
struct V_68 * V_69 = F_66 ( V_67 -> V_69 ) ;
struct V_36 * V_36 = F_25 ( V_2 ) ;
struct V_28 * V_29 ;
F_67 ( V_67 -> V_104 , NULL ) ;
F_67 ( V_67 -> V_69 , NULL ) ;
F_68 () ;
if ( V_104 ) {
V_29 = & V_104 -> V_29 ;
F_69 ( V_29 -> V_2 ) ;
V_29 -> V_2 = V_36 -> V_65 ;
F_70 ( V_29 -> V_2 ) ;
F_30 ( V_29 ) ;
}
if ( V_69 ) {
if ( V_69 -> V_70 )
F_71 ( V_69 -> V_70 ) ;
V_29 = & V_69 -> V_29 ;
F_69 ( V_29 -> V_2 ) ;
V_29 -> V_2 = V_36 -> V_65 ;
F_70 ( V_29 -> V_2 ) ;
F_30 ( V_29 ) ;
}
}
static int F_72 ( struct V_1 * V_2 )
{
int V_102 = V_105 | V_106 | V_107 | V_108 ;
struct V_66 * V_67 = F_29 ( V_2 ) ;
struct V_36 * V_36 = F_25 ( V_2 ) ;
struct V_109 * V_110 ;
struct V_68 * V_104 , * V_69 ;
int V_111 = - V_112 ;
if ( ! F_73 () )
return 0 ;
V_110 = F_74 ( V_36 , V_67 -> V_113 ) ;
if ( ! V_110 )
goto V_90;
V_104 = F_75 ( V_36 , V_2 , V_102 ) ;
if ( ! V_104 )
goto V_90;
F_36 ( & V_104 -> V_29 ) ;
V_104 -> V_110 = V_110 ;
V_104 -> V_29 . V_114 = F_60 ;
V_69 = F_75 ( V_36 , V_2 , V_102 ) ;
if ( ! V_69 ) {
F_30 ( & V_104 -> V_29 ) ;
goto V_90;
}
F_36 ( & V_69 -> V_29 ) ;
V_69 -> V_70 = F_35 ( V_2 ) ;
V_69 -> V_115 = V_116 | V_117 | V_118 ;
V_69 -> V_110 = V_110 ;
V_69 -> V_29 . V_119 = V_120 ;
F_76 ( V_67 -> V_104 , V_104 ) ;
F_76 ( V_67 -> V_69 , V_69 ) ;
V_111 = 0 ;
V_90:
return V_111 ;
}
static struct V_10 * F_63 ( struct V_1 * V_9 ,
struct V_37 * V_38 ,
struct V_10 * V_11 )
{
return V_11 ;
}
static void F_65 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
}
static int F_72 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_77 ( struct V_36 * V_36 , struct V_37 * V_38 , struct V_10 * V_11 )
{
struct V_28 * V_29 = F_22 ( V_11 ) ;
struct V_83 * V_84 = (struct V_83 * ) V_29 ;
struct V_1 * V_2 = V_29 -> V_2 ;
unsigned int V_121 = F_78 ( V_2 ) ;
struct V_94 * V_95 ;
T_3 V_97 ;
int V_60 = - V_100 ;
if ( F_33 ( F_79 ( V_11 ) < V_121 && V_2 -> V_122 ) ) {
struct V_10 * V_123 ;
V_123 = F_80 ( V_11 , F_78 ( V_2 ) ) ;
if ( ! V_123 ) {
V_60 = - V_112 ;
goto V_39;
}
if ( V_11 -> V_38 )
F_81 ( V_123 , V_11 -> V_38 ) ;
F_82 ( V_11 ) ;
V_11 = V_123 ;
}
F_52 () ;
V_97 = ( V_124 T_3 ) F_83 ( V_84 , F_42 ( V_11 ) -> V_51 ) ;
V_95 = F_84 ( V_2 , V_97 ) ;
if ( F_33 ( ! V_95 ) )
V_95 = F_55 ( & V_125 , & V_97 , V_2 , false ) ;
if ( ! F_45 ( V_95 ) )
V_60 = F_56 ( V_29 , V_95 , V_11 ) ;
F_57 () ;
V_39:
if ( F_33 ( V_60 < 0 ) )
F_5 ( V_11 -> V_2 , V_11 ) ;
return V_60 ;
}
static int F_85 ( struct V_36 * V_36 , struct V_37 * V_38 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_22 ( V_11 ) -> V_2 ;
F_86 ( V_36 , V_126 , V_11 -> V_3 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_32 = F_49 ( V_91 ) ;
return F_61 ( V_72 , V_101 ,
V_36 , V_38 , V_11 , NULL , V_2 ,
F_77 ,
! ( F_87 ( V_11 ) -> V_102 & V_127 ) ) ;
}
static struct V_10 * F_88 ( struct V_1 * V_9 ,
struct V_37 * V_38 ,
struct V_10 * V_11 )
{
struct V_66 * V_67 = F_29 ( V_9 ) ;
struct V_28 * V_29 = NULL ;
struct V_83 * V_128 ;
F_31 () ;
V_128 = F_32 ( V_67 -> V_128 ) ;
if ( F_17 ( V_128 ) ) {
V_29 = & V_128 -> V_29 ;
F_36 ( V_29 ) ;
}
F_34 () ;
if ( F_33 ( ! V_29 ) ) {
F_5 ( V_9 , V_11 ) ;
return NULL ;
}
F_28 ( V_11 ) ;
F_14 ( V_11 , V_29 ) ;
return V_11 ;
}
static struct V_10 * F_89 ( struct V_1 * V_9 ,
struct V_37 * V_38 ,
struct V_10 * V_11 ,
T_4 V_129 )
{
switch ( V_129 ) {
case V_130 :
return F_88 ( V_9 , V_38 , V_11 ) ;
case V_131 :
return F_63 ( V_9 , V_38 , V_11 ) ;
}
return V_11 ;
}
static void F_90 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_83 * V_128 = F_66 ( V_67 -> V_128 ) ;
struct V_83 * V_88 = F_66 ( V_67 -> V_88 ) ;
struct V_36 * V_36 = F_25 ( V_2 ) ;
struct V_28 * V_29 ;
F_67 ( V_67 -> V_128 , NULL ) ;
F_67 ( V_67 -> V_88 , NULL ) ;
F_68 () ;
if ( V_128 ) {
V_29 = & V_128 -> V_29 ;
F_69 ( V_29 -> V_2 ) ;
V_29 -> V_2 = V_36 -> V_65 ;
F_70 ( V_29 -> V_2 ) ;
F_30 ( V_29 ) ;
}
if ( V_88 ) {
V_29 = & V_88 -> V_29 ;
F_69 ( V_29 -> V_2 ) ;
V_29 -> V_2 = V_36 -> V_65 ;
F_70 ( V_29 -> V_2 ) ;
F_30 ( V_29 ) ;
}
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = F_29 ( V_2 ) ;
struct V_83 * V_128 , * V_88 ;
if ( ! F_92 ( F_25 ( V_2 ) , V_67 -> V_113 ) )
return - V_112 ;
V_128 = F_93 ( V_2 , 0 , V_86 , 1 , 1 , 0 ) ;
if ( ! V_128 )
return - V_112 ;
V_88 = F_93 ( V_2 , V_132 , V_87 , 1 , 1 , 0 ) ;
if ( ! V_88 ) {
F_30 ( & V_128 -> V_29 ) ;
return - V_112 ;
}
V_128 -> V_29 . V_114 = F_85 ;
V_128 -> V_133 = V_67 -> V_113 ;
V_88 -> V_133 = V_67 -> V_113 ;
F_76 ( V_67 -> V_128 , V_128 ) ;
F_76 ( V_67 -> V_88 , V_88 ) ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 )
{
unsigned int V_102 = V_2 -> V_102 ;
int V_60 ;
if ( ! F_95 ( V_2 ) )
return;
V_60 = F_96 ( V_2 , V_102 & ~ V_134 ) ;
if ( V_60 >= 0 )
V_60 = F_96 ( V_2 , V_102 ) ;
if ( V_60 < 0 ) {
F_97 ( V_2 ,
L_1 ,
V_2 -> V_135 ) ;
}
}
static int F_98 ( struct V_1 * V_2 , struct V_1 * V_136 )
{
int V_60 ;
V_60 = F_99 ( V_136 , V_2 , NULL , NULL ) ;
if ( V_60 < 0 )
return V_60 ;
V_136 -> V_137 |= V_138 ;
F_94 ( V_136 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , struct V_1 * V_136 )
{
if ( F_101 ( V_136 ) || F_102 ( V_136 ) )
return - V_100 ;
return F_98 ( V_2 , V_136 ) ;
}
static int F_103 ( struct V_1 * V_2 , struct V_1 * V_136 )
{
F_104 ( V_136 , V_2 ) ;
V_136 -> V_137 &= ~ V_138 ;
F_94 ( V_136 ) ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 , struct V_1 * V_136 )
{
return F_103 ( V_2 , V_136 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = F_29 ( V_2 ) ;
struct V_1 * V_136 ;
struct V_139 * V_140 ;
F_90 ( V_2 , V_67 ) ;
F_65 ( V_2 , V_67 ) ;
F_107 (dev, port_dev, iter)
F_105 ( V_2 , V_136 ) ;
F_108 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = F_29 ( V_2 ) ;
V_2 -> V_5 = F_110 ( struct V_4 ) ;
if ( ! V_2 -> V_5 )
goto V_141;
if ( F_91 ( V_2 ) != 0 )
goto V_142;
if ( F_72 ( V_2 ) != 0 )
goto V_143;
V_2 -> V_102 = V_144 | V_145 ;
V_2 -> V_146 = 64 * 1024 ;
V_2 -> V_147 = V_148 ;
F_111 ( V_2 ) ;
return 0 ;
V_143:
F_90 ( V_2 , V_67 ) ;
V_142:
F_108 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_141:
return - V_112 ;
}
static T_3 F_112 ( const struct V_1 * V_2 )
{
struct V_66 * V_67 = F_29 ( V_2 ) ;
return V_67 -> V_113 ;
}
static int F_113 ( struct V_36 * V_36 , struct V_37 * V_38 , struct V_10 * V_11 )
{
return 0 ;
}
static struct V_10 * F_114 ( T_5 V_149 , unsigned int V_150 ,
struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_36 * V_36 = F_25 ( V_2 ) ;
F_115 ( V_11 ) ;
if ( F_116 ( V_149 , V_150 , V_36 , NULL , V_11 , V_2 , NULL , F_113 ) < 0 )
V_11 = NULL ;
return V_11 ;
}
static bool F_117 ( const struct V_10 * V_11 )
{
const struct V_43 * V_44 = F_24 ( V_11 ) ;
bool V_111 = false ;
if ( V_44 -> V_57 == V_151 ) {
const struct V_152 * V_153 ;
struct V_152 V_154 ;
V_153 = F_118 ( V_11 , sizeof( * V_44 ) ,
sizeof( V_154 ) , & V_154 ) ;
if ( ! V_153 )
goto V_90;
switch ( V_153 -> V_155 ) {
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
V_111 = true ;
break;
}
}
V_90:
return V_111 ;
}
static struct V_68 * F_119 ( struct V_36 * V_36 ,
const struct V_1 * V_2 ,
struct V_45 * V_46 ,
int V_48 ,
int V_102 )
{
struct V_66 * V_67 = F_29 ( V_2 ) ;
struct V_109 * V_161 = NULL ;
struct V_68 * V_104 ;
F_31 () ;
V_104 = F_32 ( V_67 -> V_104 ) ;
if ( F_17 ( V_104 ) )
V_161 = V_104 -> V_110 ;
F_34 () ;
if ( ! V_161 )
return NULL ;
return F_120 ( V_36 , V_161 , V_48 , V_46 , V_102 ) ;
}
static void F_121 ( struct V_10 * V_11 , struct V_1 * V_9 ,
int V_48 )
{
const struct V_43 * V_44 = F_24 ( V_11 ) ;
struct V_45 V_46 = {
. V_51 = V_44 -> V_51 ,
. V_52 = V_44 -> V_52 ,
. V_53 = F_26 ( V_44 ) ,
. V_54 = V_11 -> V_55 ,
. V_56 = V_44 -> V_57 ,
. V_49 = V_48 ,
} ;
struct V_36 * V_36 = F_25 ( V_9 ) ;
struct V_68 * V_104 ;
V_104 = F_119 ( V_36 , V_9 , & V_46 , V_48 ,
V_162 | V_163 ) ;
if ( F_33 ( ! V_104 ) )
return;
if ( F_33 ( & V_104 -> V_29 == & V_36 -> V_63 . V_64 -> V_29 ) )
return;
F_14 ( V_11 , & V_104 -> V_29 ) ;
}
static struct V_10 * F_122 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
int V_164 = V_11 -> V_165 ;
bool V_166 ;
if ( V_11 -> V_30 == V_31 ) {
V_11 -> V_2 = V_9 ;
V_11 -> V_165 = V_9 -> V_48 ;
F_62 ( V_11 ) -> V_102 |= V_167 ;
V_11 -> V_30 = V_168 ;
goto V_90;
}
V_166 = F_64 ( & F_24 ( V_11 ) -> V_51 ) ;
if ( ! F_117 ( V_11 ) && ! V_166 ) {
V_11 -> V_2 = V_9 ;
V_11 -> V_165 = V_9 -> V_48 ;
F_123 ( V_11 , V_11 -> V_169 ) ;
F_124 ( V_11 , V_9 ) ;
F_125 ( V_11 , V_11 -> V_169 ) ;
F_62 ( V_11 ) -> V_102 |= V_167 ;
}
if ( V_166 )
F_121 ( V_11 , V_9 , V_164 ) ;
V_11 = F_114 ( V_40 , V_170 , V_11 , V_9 ) ;
V_90:
return V_11 ;
}
static struct V_10 * F_122 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
return V_11 ;
}
static struct V_10 * F_126 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
V_11 -> V_2 = V_9 ;
V_11 -> V_165 = V_9 -> V_48 ;
F_87 ( V_11 ) -> V_102 |= V_171 ;
if ( V_11 -> V_30 == V_31 ) {
V_11 -> V_30 = V_168 ;
goto V_90;
}
F_123 ( V_11 , V_11 -> V_169 ) ;
F_124 ( V_11 , V_9 ) ;
F_125 ( V_11 , V_11 -> V_169 ) ;
V_11 = F_114 ( V_72 , V_170 , V_11 , V_9 ) ;
V_90:
return V_11 ;
}
static struct V_10 * F_127 ( struct V_1 * V_9 ,
struct V_10 * V_11 ,
T_4 V_129 )
{
switch ( V_129 ) {
case V_130 :
return F_126 ( V_9 , V_11 ) ;
case V_131 :
return F_122 ( V_9 , V_11 ) ;
}
return V_11 ;
}
static struct V_28 * F_128 ( const struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_36 * V_36 = F_25 ( V_2 ) ;
int V_102 = V_163 ;
struct V_28 * V_29 = NULL ;
struct V_68 * V_84 ;
if ( V_46 -> V_47 == V_2 -> V_48 ) {
V_29 = & V_36 -> V_63 . V_64 -> V_29 ;
F_36 ( V_29 ) ;
return V_29 ;
}
if ( ! F_129 ( & V_46 -> V_52 ) )
V_102 |= V_162 ;
V_84 = F_119 ( V_36 , V_2 , V_46 , V_46 -> V_47 , V_102 ) ;
if ( V_84 )
V_29 = & V_84 -> V_29 ;
return V_29 ;
}
static void F_130 ( struct V_1 * V_2 ,
struct V_172 * V_173 )
{
F_131 ( V_173 -> V_174 , V_175 , sizeof( V_173 -> V_174 ) ) ;
F_131 ( V_173 -> V_176 , V_177 , sizeof( V_173 -> V_176 ) ) ;
}
static inline T_6 F_132 ( void )
{
T_6 V_178 ;
V_178 = F_133 ( sizeof( struct V_179 ) ) ;
V_178 += F_134 ( sizeof( T_5 ) ) ;
V_178 += F_134 ( sizeof( T_3 ) ) ;
return V_178 ;
}
static int F_135 ( const struct V_1 * V_2 , T_7 V_180 , bool V_181 )
{
struct V_179 * V_182 ;
struct V_183 * V_184 ;
struct V_10 * V_11 ;
int V_39 ;
if ( V_180 == V_131 && ! F_73 () )
return 0 ;
V_11 = F_136 ( F_132 () , V_185 ) ;
if ( ! V_11 )
return - V_112 ;
V_184 = F_137 ( V_11 , 0 , 0 , 0 , sizeof( * V_182 ) , 0 ) ;
if ( ! V_184 )
goto V_186;
V_184 -> V_187 &= V_188 ;
V_182 = F_138 ( V_184 ) ;
memset ( V_182 , 0 , sizeof( * V_182 ) ) ;
V_182 -> V_180 = V_180 ;
V_182 -> V_189 = V_190 ;
if ( F_139 ( V_11 , V_191 , 1 ) )
goto V_186;
if ( F_139 ( V_11 , V_192 , V_193 ) )
goto V_186;
F_140 ( V_11 , V_184 ) ;
V_11 -> V_38 = F_25 ( V_2 ) -> V_194 ;
if ( V_181 ) {
V_39 = F_141 ( V_11 , V_184 ) ;
if ( V_39 == - V_195 )
V_39 = 0 ;
} else {
V_39 = F_142 ( V_11 , V_184 ) ;
if ( V_39 == - V_196 )
V_39 = 0 ;
}
F_143 ( V_11 ) ;
return V_39 ;
V_186:
F_143 ( V_11 ) ;
return - V_197 ;
}
static int F_144 ( const struct V_1 * V_2 )
{
int V_39 ;
V_39 = F_135 ( V_2 , V_130 , true ) ;
if ( V_39 < 0 )
goto V_198;
V_39 = F_135 ( V_2 , V_131 , true ) ;
if ( V_39 < 0 )
goto V_199;
return 0 ;
V_199:
F_135 ( V_2 , V_130 , false ) ;
V_198:
F_97 ( V_2 , L_2 ) ;
return V_39 ;
}
static void F_145 ( struct V_1 * V_2 )
{
F_146 ( V_2 ) ;
V_2 -> V_200 = & V_201 ;
V_2 -> V_202 = & V_203 ;
V_2 -> V_204 = & V_205 ;
V_2 -> V_206 = V_207 ;
F_147 ( V_2 ) ;
V_2 -> V_208 |= V_209 ;
V_2 -> V_208 |= V_210 ;
V_2 -> V_208 |= V_211 ;
V_2 -> V_208 |= V_212 ;
V_2 -> V_208 |= V_213 | V_214 ;
V_2 -> V_208 |= V_215 | V_216 | V_217 ;
V_2 -> V_218 = V_2 -> V_208 ;
V_2 -> V_219 = V_2 -> V_208 ;
V_2 -> V_137 |= V_220 ;
}
static int F_148 ( struct V_221 * V_222 [] , struct V_221 * V_223 [] )
{
if ( V_222 [ V_224 ] ) {
if ( F_149 ( V_222 [ V_224 ] ) != V_225 )
return - V_100 ;
if ( ! F_150 ( F_151 ( V_222 [ V_224 ] ) ) )
return - V_226 ;
}
return 0 ;
}
static void F_152 ( struct V_1 * V_2 , struct V_139 * V_227 )
{
F_153 ( V_2 , V_227 ) ;
}
static int F_154 ( struct V_36 * V_228 , struct V_1 * V_2 ,
struct V_221 * V_222 [] , struct V_221 * V_223 [] )
{
struct V_66 * V_67 = F_29 ( V_2 ) ;
int V_39 ;
if ( ! V_223 || ! V_223 [ V_229 ] )
return - V_100 ;
V_67 -> V_113 = F_155 ( V_223 [ V_229 ] ) ;
V_2 -> V_137 |= V_230 ;
V_39 = F_156 ( V_2 ) ;
if ( V_39 )
goto V_90;
if ( V_231 ) {
V_39 = F_144 ( V_2 ) ;
if ( V_39 ) {
F_157 ( V_2 ) ;
goto V_90;
}
V_231 = false ;
}
V_90:
return V_39 ;
}
static T_6 F_158 ( const struct V_1 * V_2 )
{
return F_134 ( sizeof( T_3 ) ) ;
}
static int F_159 ( struct V_10 * V_11 ,
const struct V_1 * V_2 )
{
struct V_66 * V_67 = F_29 ( V_2 ) ;
return F_139 ( V_11 , V_229 , V_67 -> V_113 ) ;
}
static T_6 F_160 ( const struct V_1 * V_232 ,
const struct V_1 * V_233 )
{
return F_134 ( sizeof( T_3 ) ) ;
}
static int F_161 ( struct V_10 * V_11 ,
const struct V_1 * V_9 ,
const struct V_1 * V_233 )
{
struct V_66 * V_67 = F_29 ( V_9 ) ;
if ( F_139 ( V_11 , V_234 , V_67 -> V_113 ) )
return - V_197 ;
return 0 ;
}
static int F_162 ( struct V_235 * V_236 ,
unsigned long V_237 , void * V_238 )
{
struct V_1 * V_2 = F_163 ( V_238 ) ;
if ( V_237 == V_239 ) {
struct V_1 * V_9 ;
if ( ! F_102 ( V_2 ) )
goto V_90;
V_9 = F_164 ( V_2 ) ;
F_105 ( V_9 , V_2 ) ;
}
V_90:
return V_240 ;
}
static int T_8 F_165 ( void )
{
int V_111 ;
F_166 ( & V_241 ) ;
V_111 = F_167 ( & V_242 ) ;
if ( V_111 < 0 )
goto error;
return 0 ;
error:
F_168 ( & V_241 ) ;
return V_111 ;
}

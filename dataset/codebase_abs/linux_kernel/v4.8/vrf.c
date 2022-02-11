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
static T_2 F_20 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
const struct V_36 * V_37 = F_21 ( V_11 ) ;
struct V_38 * V_38 = F_22 ( V_11 -> V_2 ) ;
struct V_39 V_40 = {
. V_41 = V_2 -> V_42 ,
. V_43 = V_44 ,
. V_45 = V_37 -> V_45 ,
. V_46 = V_37 -> V_46 ,
. V_47 = F_23 ( V_37 ) ,
. V_48 = V_11 -> V_49 ,
. V_50 = V_37 -> V_51 ,
. V_52 = V_53 | V_54 ,
} ;
int V_55 = V_56 ;
struct V_28 * V_29 ;
struct V_28 * V_57 = & V_38 -> V_58 . V_59 -> V_29 ;
V_29 = F_24 ( V_38 , NULL , & V_40 ) ;
if ( V_29 == V_57 )
goto V_60;
F_25 ( V_11 ) ;
if ( V_29 -> V_2 == V_38 -> V_61 || V_29 -> V_2 == V_2 ) {
struct V_62 * V_63 = F_26 ( V_2 ) ;
struct V_64 * V_65 ;
F_27 ( V_29 ) ;
F_28 () ;
V_65 = F_29 ( V_63 -> V_65 ) ;
if ( F_30 ( ! V_65 ) ) {
F_31 () ;
goto V_60;
}
if ( F_30 ( ! V_65 -> V_66 ) ) {
V_65 -> V_66 = F_32 ( V_2 ) ;
if ( ! V_65 -> V_66 ) {
F_31 () ;
goto V_60;
}
}
V_29 = & V_65 -> V_29 ;
F_33 ( V_29 ) ;
F_31 () ;
return F_12 ( V_11 , V_2 , & V_65 -> V_29 ) ;
}
F_14 ( V_11 , V_29 ) ;
F_34 ( V_11 , F_35 ( V_11 ) ) ;
V_55 = F_36 ( V_38 , V_11 -> V_67 , V_11 ) ;
if ( F_30 ( F_37 ( V_55 ) ) )
V_2 -> V_12 . V_13 ++ ;
else
V_55 = V_68 ;
return V_55 ;
V_60:
F_5 ( V_2 , V_11 ) ;
return V_56 ;
}
static T_2 F_20 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
F_5 ( V_2 , V_11 ) ;
return V_56 ;
}
static T_2 F_38 ( struct V_10 * V_11 ,
struct V_1 * V_9 )
{
struct V_69 * V_70 = F_39 ( V_11 ) ;
int V_55 = V_56 ;
struct V_71 V_72 = {
. V_73 = V_9 -> V_42 ,
. V_74 = V_44 ,
. V_75 = F_40 ( V_70 -> V_76 ) ,
. V_77 = V_78 | V_53 |
V_54 ,
. V_45 = V_70 -> V_45 ,
} ;
struct V_38 * V_38 = F_22 ( V_9 ) ;
struct V_79 * V_80 ;
V_80 = F_41 ( V_38 , & V_72 , NULL ) ;
if ( F_42 ( V_80 ) )
goto V_60;
if ( V_80 -> V_81 != V_82 && V_80 -> V_81 != V_83 ) {
F_43 ( V_80 ) ;
goto V_60;
}
F_25 ( V_11 ) ;
if ( V_80 -> V_29 . V_2 == V_38 -> V_61 || V_80 -> V_29 . V_2 == V_9 ) {
struct V_62 * V_63 = F_26 ( V_9 ) ;
struct V_79 * V_84 ;
struct V_28 * V_29 = NULL ;
F_43 ( V_80 ) ;
F_28 () ;
V_84 = F_29 ( V_63 -> V_84 ) ;
if ( F_17 ( V_84 ) ) {
V_29 = & V_84 -> V_29 ;
F_33 ( V_29 ) ;
}
F_31 () ;
if ( F_30 ( ! V_29 ) )
goto V_60;
return F_12 ( V_11 , V_9 , V_29 ) ;
}
F_14 ( V_11 , & V_80 -> V_29 ) ;
F_34 ( V_11 , F_35 ( V_11 ) ) ;
if ( ! V_70 -> V_46 ) {
V_70 -> V_46 = F_44 ( F_45 ( V_11 ) -> V_2 , 0 ,
V_85 ) ;
}
V_55 = F_46 ( F_22 ( F_45 ( V_11 ) -> V_2 ) , V_11 -> V_67 , V_11 ) ;
if ( F_30 ( F_37 ( V_55 ) ) )
V_9 -> V_12 . V_13 ++ ;
else
V_55 = V_68 ;
V_86:
return V_55 ;
V_60:
F_5 ( V_9 , V_11 ) ;
goto V_86;
}
static T_2 F_47 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
switch ( V_11 -> V_32 ) {
case F_48 ( V_87 ) :
return F_38 ( V_11 , V_2 ) ;
case F_48 ( V_88 ) :
return F_20 ( V_11 , V_2 ) ;
default:
F_5 ( V_2 , V_11 ) ;
return V_56 ;
}
}
static T_2 F_49 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
T_2 V_55 = F_47 ( V_11 , V_2 ) ;
if ( F_17 ( V_55 == V_68 || V_55 == V_89 ) ) {
struct V_4 * V_5 = F_2 ( V_2 -> V_5 ) ;
F_3 ( & V_5 -> V_6 ) ;
V_5 -> V_23 ++ ;
V_5 -> V_22 += V_11 -> V_3 ;
F_4 ( & V_5 -> V_6 ) ;
} else {
F_19 ( V_2 -> V_5 -> V_24 ) ;
}
return V_55 ;
}
static int F_50 ( struct V_38 * V_38 , struct V_90 * V_67 ,
struct V_10 * V_11 )
{
struct V_28 * V_29 = F_45 ( V_11 ) ;
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
int V_55 ;
V_11 -> V_32 = F_48 ( V_88 ) ;
V_11 -> V_2 = V_2 ;
F_51 () ;
V_94 = F_52 ( (struct V_64 * ) V_29 , & F_21 ( V_11 ) -> V_45 ) ;
V_92 = F_53 ( V_29 -> V_2 , V_94 ) ;
if ( F_30 ( ! V_92 ) )
V_92 = F_54 ( & V_95 , V_94 , V_29 -> V_2 , false ) ;
if ( ! F_42 ( V_92 ) ) {
V_55 = F_55 ( V_29 , V_92 , V_11 ) ;
F_56 () ;
return V_55 ;
}
F_56 () ;
F_57 ( F_22 ( V_29 -> V_2 ) ,
F_58 ( V_29 ) , V_96 ) ;
F_6 ( V_11 ) ;
return - V_97 ;
}
static int F_59 ( struct V_38 * V_38 , struct V_90 * V_67 , struct V_10 * V_11 )
{
return F_60 ( V_98 , V_99 ,
V_38 , V_67 , V_11 , NULL , F_45 ( V_11 ) -> V_2 ,
F_50 ,
! ( F_61 ( V_11 ) -> V_100 & V_101 ) ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
struct V_64 * V_102 = F_63 ( V_63 -> V_102 ) ;
struct V_64 * V_65 = F_63 ( V_63 -> V_65 ) ;
struct V_38 * V_38 = F_22 ( V_2 ) ;
struct V_28 * V_29 ;
F_64 ( V_63 -> V_102 , NULL ) ;
F_64 ( V_63 -> V_65 , NULL ) ;
F_65 () ;
if ( V_102 ) {
V_29 = & V_102 -> V_29 ;
F_66 ( V_29 -> V_2 ) ;
V_29 -> V_2 = V_38 -> V_61 ;
F_67 ( V_29 -> V_2 ) ;
F_27 ( V_29 ) ;
}
if ( V_65 ) {
if ( V_65 -> V_66 )
F_68 ( V_65 -> V_66 ) ;
V_29 = & V_65 -> V_29 ;
F_66 ( V_29 -> V_2 ) ;
V_29 -> V_2 = V_38 -> V_61 ;
F_67 ( V_29 -> V_2 ) ;
F_27 ( V_29 ) ;
}
}
static int F_69 ( struct V_1 * V_2 )
{
int V_100 = V_103 | V_104 | V_105 | V_106 ;
struct V_62 * V_63 = F_26 ( V_2 ) ;
struct V_38 * V_38 = F_22 ( V_2 ) ;
struct V_107 * V_108 ;
struct V_64 * V_102 , * V_65 ;
int V_109 = - V_110 ;
if ( ! F_70 () )
return 0 ;
V_108 = F_71 ( V_38 , V_63 -> V_111 ) ;
if ( ! V_108 )
goto V_86;
V_102 = F_72 ( V_38 , V_2 , V_100 ) ;
if ( ! V_102 )
goto V_86;
F_33 ( & V_102 -> V_29 ) ;
V_102 -> V_108 = V_108 ;
V_102 -> V_29 . V_112 = F_59 ;
V_65 = F_72 ( V_38 , V_2 , V_100 ) ;
if ( ! V_65 ) {
F_27 ( & V_102 -> V_29 ) ;
goto V_86;
}
F_33 ( & V_65 -> V_29 ) ;
V_65 -> V_66 = F_32 ( V_2 ) ;
V_65 -> V_113 = V_114 | V_115 | V_116 ;
V_65 -> V_108 = V_108 ;
V_65 -> V_29 . V_117 = V_118 ;
F_73 ( V_63 -> V_102 , V_102 ) ;
F_73 ( V_63 -> V_65 , V_65 ) ;
V_109 = 0 ;
V_86:
return V_109 ;
}
static void F_62 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
}
static int F_69 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_74 ( struct V_38 * V_38 , struct V_90 * V_67 , struct V_10 * V_11 )
{
struct V_28 * V_29 = F_45 ( V_11 ) ;
struct V_79 * V_80 = (struct V_79 * ) V_29 ;
struct V_1 * V_2 = V_29 -> V_2 ;
unsigned int V_119 = F_75 ( V_2 ) ;
struct V_91 * V_92 ;
T_3 V_94 ;
int V_55 = - V_97 ;
if ( F_30 ( F_76 ( V_11 ) < V_119 && V_2 -> V_120 ) ) {
struct V_10 * V_121 ;
V_121 = F_77 ( V_11 , F_75 ( V_2 ) ) ;
if ( ! V_121 ) {
V_55 = - V_110 ;
goto V_60;
}
if ( V_11 -> V_67 )
F_78 ( V_121 , V_11 -> V_67 ) ;
F_79 ( V_11 ) ;
V_11 = V_121 ;
}
F_51 () ;
V_94 = ( V_122 T_3 ) F_80 ( V_80 , F_39 ( V_11 ) -> V_45 ) ;
V_92 = F_81 ( V_2 , V_94 ) ;
if ( F_30 ( ! V_92 ) )
V_92 = F_54 ( & V_123 , & V_94 , V_2 , false ) ;
if ( ! F_42 ( V_92 ) )
V_55 = F_55 ( V_29 , V_92 , V_11 ) ;
F_56 () ;
V_60:
if ( F_30 ( V_55 < 0 ) )
F_5 ( V_11 -> V_2 , V_11 ) ;
return V_55 ;
}
static int F_82 ( struct V_38 * V_38 , struct V_90 * V_67 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_45 ( V_11 ) -> V_2 ;
F_83 ( V_38 , V_124 , V_11 -> V_3 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_32 = F_48 ( V_87 ) ;
return F_60 ( V_125 , V_99 ,
V_38 , V_67 , V_11 , NULL , V_2 ,
F_74 ,
! ( F_84 ( V_11 ) -> V_100 & V_126 ) ) ;
}
static void F_85 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
struct V_79 * V_127 = F_63 ( V_63 -> V_127 ) ;
struct V_79 * V_84 = F_63 ( V_63 -> V_84 ) ;
struct V_38 * V_38 = F_22 ( V_2 ) ;
struct V_28 * V_29 ;
F_64 ( V_63 -> V_127 , NULL ) ;
F_64 ( V_63 -> V_84 , NULL ) ;
F_65 () ;
if ( V_127 ) {
V_29 = & V_127 -> V_29 ;
F_66 ( V_29 -> V_2 ) ;
V_29 -> V_2 = V_38 -> V_61 ;
F_67 ( V_29 -> V_2 ) ;
F_27 ( V_29 ) ;
}
if ( V_84 ) {
V_29 = & V_84 -> V_29 ;
F_66 ( V_29 -> V_2 ) ;
V_29 -> V_2 = V_38 -> V_61 ;
F_67 ( V_29 -> V_2 ) ;
F_27 ( V_29 ) ;
}
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = F_26 ( V_2 ) ;
struct V_79 * V_127 , * V_84 ;
if ( ! F_87 ( F_22 ( V_2 ) , V_63 -> V_111 ) )
return - V_110 ;
V_127 = F_88 ( V_2 , 0 , V_82 , 1 , 1 , 0 ) ;
if ( ! V_127 )
return - V_110 ;
V_84 = F_88 ( V_2 , V_128 , V_83 , 1 , 1 , 0 ) ;
if ( ! V_84 ) {
F_27 ( & V_127 -> V_29 ) ;
return - V_110 ;
}
V_127 -> V_29 . V_112 = F_82 ;
V_127 -> V_129 = V_63 -> V_111 ;
V_84 -> V_129 = V_63 -> V_111 ;
F_73 ( V_63 -> V_127 , V_127 ) ;
F_73 ( V_63 -> V_84 , V_84 ) ;
return 0 ;
}
static void F_89 ( struct V_1 * V_2 )
{
unsigned int V_100 = V_2 -> V_100 ;
int V_55 ;
if ( ! F_90 ( V_2 ) )
return;
V_55 = F_91 ( V_2 , V_100 & ~ V_130 ) ;
if ( V_55 >= 0 )
V_55 = F_91 ( V_2 , V_100 ) ;
if ( V_55 < 0 ) {
F_92 ( V_2 ,
L_1 ,
V_2 -> V_131 ) ;
}
}
static int F_93 ( struct V_1 * V_2 , struct V_1 * V_132 )
{
int V_55 ;
V_55 = F_94 ( V_132 , V_2 , NULL , NULL ) ;
if ( V_55 < 0 )
return V_55 ;
V_132 -> V_133 |= V_134 ;
F_89 ( V_132 ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , struct V_1 * V_132 )
{
if ( F_96 ( V_132 ) || F_97 ( V_132 ) )
return - V_97 ;
return F_93 ( V_2 , V_132 ) ;
}
static int F_98 ( struct V_1 * V_2 , struct V_1 * V_132 )
{
F_99 ( V_132 , V_2 ) ;
V_132 -> V_133 &= ~ V_134 ;
F_89 ( V_132 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , struct V_1 * V_132 )
{
return F_98 ( V_2 , V_132 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = F_26 ( V_2 ) ;
struct V_1 * V_132 ;
struct V_135 * V_136 ;
F_85 ( V_2 , V_63 ) ;
F_62 ( V_2 , V_63 ) ;
F_102 (dev, port_dev, iter)
F_100 ( V_2 , V_132 ) ;
F_103 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = F_26 ( V_2 ) ;
V_2 -> V_5 = F_105 ( struct V_4 ) ;
if ( ! V_2 -> V_5 )
goto V_137;
if ( F_86 ( V_2 ) != 0 )
goto V_138;
if ( F_69 ( V_2 ) != 0 )
goto V_139;
V_2 -> V_100 = V_140 | V_141 ;
V_2 -> V_142 = 64 * 1024 ;
V_2 -> V_143 = V_144 ;
F_106 ( V_2 ) ;
return 0 ;
V_139:
F_85 ( V_2 , V_63 ) ;
V_138:
F_103 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_137:
return - V_110 ;
}
static T_3 F_107 ( const struct V_1 * V_2 )
{
struct V_62 * V_63 = F_26 ( V_2 ) ;
return V_63 -> V_111 ;
}
static struct V_79 * F_108 ( const struct V_1 * V_2 ,
const struct V_71 * V_72 )
{
struct V_79 * V_127 = NULL ;
if ( ! ( V_72 -> V_77 & V_53 ) ) {
struct V_62 * V_63 = F_26 ( V_2 ) ;
F_28 () ;
V_127 = F_29 ( V_63 -> V_127 ) ;
if ( F_17 ( V_127 ) )
F_33 ( & V_127 -> V_29 ) ;
F_31 () ;
}
return V_127 ;
}
static int F_109 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
struct V_145 V_146 = { . V_147 = 0 } ;
struct V_38 * V_38 = F_22 ( V_2 ) ;
T_3 V_148 = V_72 -> V_75 ;
T_4 V_100 = V_72 -> V_77 ;
T_4 V_149 = V_72 -> V_150 ;
T_4 V_76 = F_110 ( V_72 ) ;
int V_109 ;
if ( F_30 ( ! V_72 -> V_45 ) )
return 0 ;
V_72 -> V_77 |= V_54 ;
V_72 -> V_74 = V_44 ;
V_72 -> V_73 = V_2 -> V_42 ;
V_72 -> V_75 = V_76 & V_151 ;
V_72 -> V_150 = ( ( V_76 & V_152 ) ?
V_85 : V_153 ) ;
V_109 = F_111 ( V_38 , V_72 , & V_146 , 0 ) ;
if ( ! V_109 ) {
if ( V_146 . type == V_83 )
V_72 -> V_46 = V_146 . V_154 -> V_155 ? : V_72 -> V_45 ;
else
F_112 ( V_38 , & V_146 , V_72 , - 1 ) ;
}
V_72 -> V_77 = V_100 ;
V_72 -> V_75 = V_148 ;
V_72 -> V_150 = V_149 ;
return V_109 ;
}
static int F_113 ( struct V_38 * V_38 , struct V_90 * V_67 , struct V_10 * V_11 )
{
return 0 ;
}
static struct V_10 * F_114 ( T_4 V_156 , unsigned int V_157 ,
struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_38 * V_38 = F_22 ( V_2 ) ;
F_115 ( V_11 ) ;
if ( F_116 ( V_156 , V_157 , V_38 , NULL , V_11 , V_2 , NULL , F_113 ) < 0 )
V_11 = NULL ;
return V_11 ;
}
static bool F_117 ( const struct V_10 * V_11 )
{
const struct V_36 * V_37 = F_21 ( V_11 ) ;
bool V_109 = false ;
if ( V_37 -> V_51 == V_158 ) {
const struct V_159 * V_160 ;
struct V_159 V_161 ;
V_160 = F_118 ( V_11 , sizeof( * V_37 ) ,
sizeof( V_161 ) , & V_161 ) ;
if ( ! V_160 )
goto V_86;
switch ( V_160 -> V_162 ) {
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
V_109 = true ;
break;
}
}
V_86:
return V_109 ;
}
static struct V_64 * F_119 ( struct V_38 * V_38 ,
const struct V_1 * V_2 ,
struct V_39 * V_40 ,
int V_42 ,
int V_100 )
{
struct V_62 * V_63 = F_26 ( V_2 ) ;
struct V_107 * V_168 = NULL ;
struct V_64 * V_102 ;
F_28 () ;
V_102 = F_29 ( V_63 -> V_102 ) ;
if ( F_17 ( V_102 ) )
V_168 = V_102 -> V_108 ;
F_31 () ;
if ( ! V_168 )
return NULL ;
return F_120 ( V_38 , V_168 , V_42 , V_40 , V_100 ) ;
}
static void F_121 ( struct V_10 * V_11 , struct V_1 * V_9 ,
int V_42 )
{
const struct V_36 * V_37 = F_21 ( V_11 ) ;
struct V_39 V_40 = {
. V_45 = V_37 -> V_45 ,
. V_46 = V_37 -> V_46 ,
. V_47 = F_23 ( V_37 ) ,
. V_48 = V_11 -> V_49 ,
. V_50 = V_37 -> V_51 ,
. V_43 = V_42 ,
} ;
struct V_38 * V_38 = F_22 ( V_9 ) ;
struct V_64 * V_102 ;
V_102 = F_119 ( V_38 , V_9 , & V_40 , V_42 ,
V_169 | V_170 ) ;
if ( F_30 ( ! V_102 ) )
return;
if ( F_30 ( & V_102 -> V_29 == & V_38 -> V_58 . V_59 -> V_29 ) )
return;
F_14 ( V_11 , & V_102 -> V_29 ) ;
}
static struct V_10 * F_122 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
int V_171 = V_11 -> V_172 ;
bool V_173 ;
if ( V_11 -> V_30 == V_31 ) {
V_11 -> V_2 = V_9 ;
V_11 -> V_172 = V_9 -> V_42 ;
V_11 -> V_30 = V_174 ;
goto V_86;
}
V_173 = F_123 ( & F_21 ( V_11 ) -> V_45 ) ;
if ( ! F_117 ( V_11 ) && ! V_173 ) {
V_11 -> V_2 = V_9 ;
V_11 -> V_172 = V_9 -> V_42 ;
F_124 ( V_11 , V_11 -> V_175 ) ;
F_125 ( V_11 , V_9 ) ;
F_126 ( V_11 , V_11 -> V_175 ) ;
F_61 ( V_11 ) -> V_100 |= V_176 ;
}
if ( V_173 )
F_121 ( V_11 , V_9 , V_171 ) ;
V_11 = F_114 ( V_98 , V_177 , V_11 , V_9 ) ;
V_86:
return V_11 ;
}
static struct V_10 * F_122 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
return V_11 ;
}
static struct V_10 * F_127 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
V_11 -> V_2 = V_9 ;
V_11 -> V_172 = V_9 -> V_42 ;
if ( V_11 -> V_30 == V_31 ) {
V_11 -> V_30 = V_174 ;
goto V_86;
}
F_124 ( V_11 , V_11 -> V_175 ) ;
F_125 ( V_11 , V_9 ) ;
F_126 ( V_11 , V_11 -> V_175 ) ;
V_11 = F_114 ( V_125 , V_177 , V_11 , V_9 ) ;
V_86:
return V_11 ;
}
static struct V_10 * F_128 ( struct V_1 * V_9 ,
struct V_10 * V_11 ,
T_5 V_178 )
{
switch ( V_178 ) {
case V_179 :
return F_127 ( V_9 , V_11 ) ;
case V_180 :
return F_122 ( V_9 , V_11 ) ;
}
return V_11 ;
}
static struct V_28 * F_129 ( const struct V_1 * V_2 ,
struct V_39 * V_40 )
{
bool V_173 = F_123 ( & V_40 -> V_45 ) ;
struct V_62 * V_63 = F_26 ( V_2 ) ;
struct V_38 * V_38 = F_22 ( V_2 ) ;
struct V_28 * V_29 = NULL ;
struct V_64 * V_80 ;
if ( V_173 ) {
int V_100 = V_170 ;
if ( V_40 -> V_41 == V_2 -> V_42 ) {
struct V_28 * V_29 = & V_38 -> V_58 . V_59 -> V_29 ;
F_33 ( V_29 ) ;
return V_29 ;
}
if ( ! F_130 ( & V_40 -> V_46 ) )
V_100 |= V_169 ;
V_80 = F_119 ( V_38 , V_2 , V_40 , V_40 -> V_41 , V_100 ) ;
if ( V_80 )
V_29 = & V_80 -> V_29 ;
} else if ( ! ( V_40 -> V_52 & V_53 ) ) {
F_28 () ;
V_80 = F_29 ( V_63 -> V_102 ) ;
if ( F_17 ( V_80 ) ) {
V_29 = & V_80 -> V_29 ;
F_33 ( V_29 ) ;
}
F_31 () ;
}
if ( ! V_173 )
V_40 -> V_41 = V_2 -> V_42 ;
return V_29 ;
}
static int F_131 ( struct V_1 * V_2 , const struct V_90 * V_67 ,
struct V_39 * V_40 )
{
struct V_38 * V_38 = F_22 ( V_2 ) ;
struct V_28 * V_29 ;
struct V_64 * V_80 ;
int V_60 ;
if ( F_123 ( & V_40 -> V_45 ) ) {
V_80 = F_119 ( V_38 , V_2 , V_40 , V_40 -> V_41 ,
V_170 ) ;
if ( F_30 ( ! V_80 ) )
return 0 ;
V_29 = & V_80 -> V_29 ;
} else {
T_6 V_100 = V_40 -> V_52 ;
V_40 -> V_52 |= V_53 ;
V_40 -> V_52 |= V_54 ;
V_29 = F_24 ( V_38 , V_67 , V_40 ) ;
V_80 = (struct V_64 * ) V_29 ;
V_40 -> V_52 = V_100 ;
}
V_60 = V_29 -> error ;
if ( ! V_60 ) {
V_60 = F_132 ( V_38 , V_80 , & V_40 -> V_45 ,
V_67 ? F_133 ( V_67 ) -> V_181 : 0 ,
& V_40 -> V_46 ) ;
}
F_27 ( V_29 ) ;
return V_60 ;
}
static void F_134 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
F_135 ( V_183 -> V_184 , V_185 , sizeof( V_183 -> V_184 ) ) ;
F_135 ( V_183 -> V_186 , V_187 , sizeof( V_183 -> V_186 ) ) ;
}
static inline T_7 F_136 ( void )
{
T_7 V_188 ;
V_188 = F_137 ( sizeof( struct V_189 ) ) ;
V_188 += F_138 ( sizeof( T_4 ) ) ;
V_188 += F_138 ( sizeof( T_3 ) ) ;
return V_188 ;
}
static int F_139 ( const struct V_1 * V_2 , T_6 V_190 , bool V_191 )
{
struct V_189 * V_192 ;
struct V_193 * V_194 ;
struct V_10 * V_11 ;
int V_60 ;
if ( V_190 == V_180 && ! F_70 () )
return 0 ;
V_11 = F_140 ( F_136 () , V_195 ) ;
if ( ! V_11 )
return - V_110 ;
V_194 = F_141 ( V_11 , 0 , 0 , 0 , sizeof( * V_192 ) , 0 ) ;
if ( ! V_194 )
goto V_196;
V_194 -> V_197 &= V_198 ;
V_192 = F_142 ( V_194 ) ;
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
V_192 -> V_190 = V_190 ;
V_192 -> V_199 = V_200 ;
if ( F_143 ( V_11 , V_201 , 1 ) )
goto V_196;
if ( F_143 ( V_11 , V_202 , V_203 ) )
goto V_196;
F_144 ( V_11 , V_194 ) ;
V_11 -> V_67 = F_22 ( V_2 ) -> V_204 ;
if ( V_191 ) {
V_60 = F_145 ( V_11 , V_194 ) ;
if ( V_60 == - V_205 )
V_60 = 0 ;
} else {
V_60 = F_146 ( V_11 , V_194 ) ;
if ( V_60 == - V_206 )
V_60 = 0 ;
}
F_147 ( V_11 ) ;
return V_60 ;
V_196:
F_147 ( V_11 ) ;
return - V_207 ;
}
static int F_148 ( const struct V_1 * V_2 )
{
int V_60 ;
V_60 = F_139 ( V_2 , V_179 , true ) ;
if ( V_60 < 0 )
goto V_208;
V_60 = F_139 ( V_2 , V_180 , true ) ;
if ( V_60 < 0 )
goto V_209;
return 0 ;
V_209:
F_139 ( V_2 , V_179 , false ) ;
V_208:
F_92 ( V_2 , L_2 ) ;
return V_60 ;
}
static void F_149 ( struct V_1 * V_2 )
{
F_150 ( V_2 ) ;
V_2 -> V_210 = & V_211 ;
V_2 -> V_212 = & V_213 ;
V_2 -> V_214 = & V_215 ;
V_2 -> V_216 = V_217 ;
F_151 ( V_2 ) ;
V_2 -> V_218 |= V_219 ;
V_2 -> V_218 |= V_220 ;
V_2 -> V_218 |= V_221 ;
V_2 -> V_218 |= V_222 ;
V_2 -> V_218 |= V_223 | V_224 ;
V_2 -> V_218 |= V_225 | V_226 | V_227 ;
V_2 -> V_228 = V_2 -> V_218 ;
V_2 -> V_229 = V_2 -> V_218 ;
V_2 -> V_133 |= V_230 ;
}
static int F_152 ( struct V_231 * V_232 [] , struct V_231 * V_233 [] )
{
if ( V_232 [ V_234 ] ) {
if ( F_153 ( V_232 [ V_234 ] ) != V_235 )
return - V_97 ;
if ( ! F_154 ( F_155 ( V_232 [ V_234 ] ) ) )
return - V_236 ;
}
return 0 ;
}
static void F_156 ( struct V_1 * V_2 , struct V_135 * V_237 )
{
F_157 ( V_2 , V_237 ) ;
}
static int F_158 ( struct V_38 * V_238 , struct V_1 * V_2 ,
struct V_231 * V_232 [] , struct V_231 * V_233 [] )
{
struct V_62 * V_63 = F_26 ( V_2 ) ;
int V_60 ;
if ( ! V_233 || ! V_233 [ V_239 ] )
return - V_97 ;
V_63 -> V_111 = F_159 ( V_233 [ V_239 ] ) ;
V_2 -> V_133 |= V_240 ;
V_60 = F_160 ( V_2 ) ;
if ( V_60 )
goto V_86;
if ( V_241 ) {
V_60 = F_148 ( V_2 ) ;
if ( V_60 ) {
F_161 ( V_2 ) ;
goto V_86;
}
V_241 = false ;
}
V_86:
return V_60 ;
}
static T_7 F_162 ( const struct V_1 * V_2 )
{
return F_138 ( sizeof( T_3 ) ) ;
}
static int F_163 ( struct V_10 * V_11 ,
const struct V_1 * V_2 )
{
struct V_62 * V_63 = F_26 ( V_2 ) ;
return F_143 ( V_11 , V_239 , V_63 -> V_111 ) ;
}
static T_7 F_164 ( const struct V_1 * V_242 ,
const struct V_1 * V_243 )
{
return F_138 ( sizeof( T_3 ) ) ;
}
static int F_165 ( struct V_10 * V_11 ,
const struct V_1 * V_9 ,
const struct V_1 * V_243 )
{
struct V_62 * V_63 = F_26 ( V_9 ) ;
if ( F_143 ( V_11 , V_244 , V_63 -> V_111 ) )
return - V_207 ;
return 0 ;
}
static int F_166 ( struct V_245 * V_246 ,
unsigned long V_247 , void * V_248 )
{
struct V_1 * V_2 = F_167 ( V_248 ) ;
if ( V_247 == V_249 ) {
struct V_1 * V_9 ;
if ( ! F_97 ( V_2 ) )
goto V_86;
V_9 = F_168 ( V_2 ) ;
F_100 ( V_9 , V_2 ) ;
}
V_86:
return V_250 ;
}
static int T_8 F_169 ( void )
{
int V_109 ;
F_170 ( & V_251 ) ;
V_109 = F_171 ( & V_252 ) ;
if ( V_109 < 0 )
goto error;
return 0 ;
error:
F_172 ( & V_251 ) ;
return V_109 ;
}

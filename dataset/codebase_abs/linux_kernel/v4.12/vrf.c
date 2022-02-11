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
if ( V_35 -> V_2 == V_42 -> V_71 || V_35 -> V_2 == V_2 ) {
struct V_72 * V_73 = F_32 ( V_2 ) ;
struct V_74 * V_75 ;
F_33 ( V_35 ) ;
F_34 () ;
V_75 = F_35 ( V_73 -> V_75 ) ;
if ( F_36 ( ! V_75 ) ) {
F_37 () ;
goto V_45;
}
if ( F_36 ( ! V_75 -> V_76 ) ) {
V_75 -> V_76 = F_38 ( V_2 ) ;
if ( ! V_75 -> V_76 ) {
F_37 () ;
goto V_45;
}
}
V_35 = & V_75 -> V_35 ;
F_39 ( V_35 ) ;
F_37 () ;
return F_15 ( V_11 , V_2 , & V_75 -> V_35 ) ;
}
F_17 ( V_11 , V_35 ) ;
F_40 ( V_11 , F_41 ( V_11 ) ) ;
V_66 = F_23 ( V_42 , V_11 -> V_44 , V_11 ) ;
if ( F_36 ( F_42 ( V_66 ) ) )
V_2 -> V_12 . V_13 ++ ;
else
V_66 = V_77 ;
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
static int F_43 ( struct V_42 * V_42 , struct V_43 * V_44 ,
struct V_10 * V_11 )
{
int V_45 ;
V_45 = F_24 ( V_78 , V_47 , V_42 , V_44 ,
V_11 , NULL , F_25 ( V_11 ) -> V_2 , V_48 ) ;
if ( F_20 ( V_45 == 1 ) )
V_45 = V_48 ( V_42 , V_44 , V_11 ) ;
return V_45 ;
}
static T_2 F_44 ( struct V_10 * V_11 ,
struct V_1 * V_9 )
{
struct V_79 * V_80 = F_45 ( V_11 ) ;
int V_66 = V_67 ;
struct V_81 V_82 = {
. V_83 = V_9 -> V_54 ,
. V_84 = V_56 ,
. V_85 = F_46 ( V_80 -> V_86 ) ,
. V_87 = V_88 | V_65 ,
. V_89 = V_80 -> V_38 ,
. V_57 = V_80 -> V_57 ,
. V_58 = V_80 -> V_58 ,
} ;
struct V_42 * V_42 = F_28 ( V_9 ) ;
struct V_90 * V_91 ;
V_91 = F_47 ( V_42 , & V_82 , NULL ) ;
if ( F_48 ( V_91 ) )
goto V_45;
F_31 ( V_11 ) ;
if ( V_91 -> V_35 . V_2 == V_42 -> V_71 || V_91 -> V_35 . V_2 == V_9 ) {
struct V_72 * V_73 = F_32 ( V_9 ) ;
struct V_90 * V_92 ;
struct V_34 * V_35 = NULL ;
F_49 ( V_91 ) ;
F_34 () ;
V_92 = F_35 ( V_73 -> V_92 ) ;
if ( F_20 ( V_92 ) ) {
V_35 = & V_92 -> V_35 ;
F_39 ( V_35 ) ;
}
F_37 () ;
if ( F_36 ( ! V_35 ) )
goto V_45;
return F_15 ( V_11 , V_9 , V_35 ) ;
}
F_17 ( V_11 , & V_91 -> V_35 ) ;
F_40 ( V_11 , F_41 ( V_11 ) ) ;
if ( ! V_80 -> V_58 ) {
V_80 -> V_58 = F_50 ( F_25 ( V_11 ) -> V_2 , 0 ,
V_93 ) ;
}
V_66 = F_43 ( F_28 ( F_25 ( V_11 ) -> V_2 ) , V_11 -> V_44 , V_11 ) ;
if ( F_36 ( F_42 ( V_66 ) ) )
V_9 -> V_12 . V_13 ++ ;
else
V_66 = V_77 ;
V_94:
return V_66 ;
V_45:
F_5 ( V_9 , V_11 ) ;
goto V_94;
}
static T_2 F_51 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
switch ( V_11 -> V_38 ) {
case F_52 ( V_95 ) :
return F_44 ( V_11 , V_2 ) ;
case F_52 ( V_96 ) :
return F_26 ( V_11 , V_2 ) ;
default:
F_5 ( V_2 , V_11 ) ;
return V_67 ;
}
}
static T_2 F_53 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
int V_3 = V_11 -> V_3 ;
T_2 V_66 = F_51 ( V_11 , V_2 ) ;
if ( F_20 ( V_66 == V_77 || V_66 == V_97 ) ) {
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
static int F_54 ( struct V_42 * V_42 , struct V_43 * V_44 ,
struct V_10 * V_11 )
{
struct V_1 * V_9 = V_11 -> V_2 ;
if ( ! F_55 ( & V_9 -> V_98 ) &&
F_20 ( F_56 ( V_11 ) >= V_99 ) ) {
struct V_100 * V_101 = (struct V_100 * ) F_57 ( V_11 , V_99 ) ;
F_58 ( V_101 -> V_102 , V_9 -> V_103 ) ;
F_59 ( V_101 -> V_104 ) ;
V_101 -> V_105 = V_11 -> V_38 ;
F_60 () ;
F_61 ( V_11 , V_9 ) ;
F_62 () ;
F_63 ( V_11 , V_99 ) ;
}
return 1 ;
}
static int F_64 ( struct V_42 * V_42 , struct V_43 * V_44 ,
struct V_10 * V_11 )
{
struct V_34 * V_35 = F_25 ( V_11 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_106 * V_107 ;
struct V_108 * V_109 ;
int V_66 ;
F_65 ( V_11 ) ;
V_11 -> V_38 = F_52 ( V_96 ) ;
V_11 -> V_2 = V_2 ;
F_60 () ;
V_109 = F_66 ( (struct V_74 * ) V_35 , & F_27 ( V_11 ) -> V_57 ) ;
V_107 = F_67 ( V_35 -> V_2 , V_109 ) ;
if ( F_36 ( ! V_107 ) )
V_107 = F_68 ( & V_110 , V_109 , V_35 -> V_2 , false ) ;
if ( ! F_48 ( V_107 ) ) {
F_69 ( V_11 , V_107 ) ;
V_66 = F_70 ( V_107 , V_11 ) ;
F_62 () ;
return V_66 ;
}
F_62 () ;
F_71 ( F_28 ( V_35 -> V_2 ) ,
F_72 ( V_35 ) , V_111 ) ;
F_6 ( V_11 ) ;
return - V_112 ;
}
static int F_73 ( struct V_42 * V_42 , struct V_43 * V_44 , struct V_10 * V_11 )
{
return F_74 ( V_46 , V_113 ,
V_42 , V_44 , V_11 , NULL , F_25 ( V_11 ) -> V_2 ,
F_64 ,
! ( F_75 ( V_11 ) -> V_114 & V_115 ) ) ;
}
static struct V_10 * F_76 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
struct V_72 * V_73 = F_32 ( V_9 ) ;
struct V_34 * V_35 = NULL ;
struct V_74 * V_116 ;
F_34 () ;
V_116 = F_35 ( V_73 -> V_116 ) ;
if ( F_20 ( V_116 ) ) {
V_35 = & V_116 -> V_35 ;
F_39 ( V_35 ) ;
}
F_37 () ;
if ( F_36 ( ! V_35 ) ) {
F_5 ( V_9 , V_11 ) ;
return NULL ;
}
F_31 ( V_11 ) ;
F_17 ( V_11 , V_35 ) ;
return V_11 ;
}
static int F_77 ( struct V_42 * V_42 , struct V_43 * V_44 ,
struct V_10 * V_11 )
{
V_11 -> V_38 = F_52 ( V_96 ) ;
return F_74 ( V_46 , V_113 ,
V_42 , V_44 , V_11 , NULL , V_11 -> V_2 ,
F_54 ,
! ( F_78 ( V_11 ) -> V_114 & V_117 ) ) ;
}
static struct V_10 * F_79 ( struct V_1 * V_9 ,
struct V_43 * V_44 ,
struct V_10 * V_11 )
{
struct V_42 * V_42 = F_28 ( V_9 ) ;
int V_45 ;
V_11 -> V_2 = V_9 ;
V_45 = F_24 ( V_46 , V_47 , V_42 , V_44 ,
V_11 , NULL , V_9 , F_77 ) ;
if ( F_20 ( V_45 == 1 ) )
V_45 = F_77 ( V_42 , V_44 , V_11 ) ;
if ( F_20 ( V_45 == 1 ) )
F_65 ( V_11 ) ;
else
V_11 = NULL ;
return V_11 ;
}
static struct V_10 * F_80 ( struct V_1 * V_9 ,
struct V_43 * V_44 ,
struct V_10 * V_11 )
{
if ( F_81 ( & F_27 ( V_11 ) -> V_57 ) )
return V_11 ;
if ( F_12 ( V_9 ) )
return F_79 ( V_9 , V_44 , V_11 ) ;
return F_76 ( V_9 , V_11 ) ;
}
static void F_82 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
struct V_74 * V_116 = F_83 ( V_73 -> V_116 ) ;
struct V_74 * V_75 = F_83 ( V_73 -> V_75 ) ;
struct V_42 * V_42 = F_28 ( V_2 ) ;
struct V_34 * V_35 ;
F_84 ( V_73 -> V_116 , NULL ) ;
F_84 ( V_73 -> V_75 , NULL ) ;
F_85 () ;
if ( V_116 ) {
V_35 = & V_116 -> V_35 ;
F_86 ( V_35 -> V_2 ) ;
V_35 -> V_2 = V_42 -> V_71 ;
F_87 ( V_35 -> V_2 ) ;
F_33 ( V_35 ) ;
}
if ( V_75 ) {
if ( V_75 -> V_76 ) {
F_88 ( V_75 -> V_76 ) ;
V_75 -> V_76 = NULL ;
}
V_35 = & V_75 -> V_35 ;
F_86 ( V_35 -> V_2 ) ;
V_35 -> V_2 = V_42 -> V_71 ;
F_87 ( V_35 -> V_2 ) ;
F_33 ( V_35 ) ;
}
}
static int F_89 ( struct V_1 * V_2 )
{
int V_114 = V_118 | V_119 | V_120 | V_121 ;
struct V_72 * V_73 = F_32 ( V_2 ) ;
struct V_42 * V_42 = F_28 ( V_2 ) ;
struct V_122 * V_123 ;
struct V_74 * V_116 , * V_75 ;
int V_124 = - V_125 ;
if ( ! F_90 () )
return 0 ;
V_123 = F_91 ( V_42 , V_73 -> V_126 ) ;
if ( ! V_123 )
goto V_94;
V_116 = F_92 ( V_42 , V_2 , V_114 ) ;
if ( ! V_116 )
goto V_94;
F_39 ( & V_116 -> V_35 ) ;
V_116 -> V_123 = V_123 ;
V_116 -> V_35 . V_127 = F_73 ;
V_75 = F_92 ( V_42 , V_2 , V_114 ) ;
if ( ! V_75 ) {
F_33 ( & V_116 -> V_35 ) ;
goto V_94;
}
F_39 ( & V_75 -> V_35 ) ;
V_75 -> V_76 = F_38 ( V_2 ) ;
V_75 -> V_128 = V_129 | V_130 | V_131 ;
V_75 -> V_123 = V_123 ;
V_75 -> V_35 . V_132 = V_133 ;
F_93 ( V_73 -> V_116 , V_116 ) ;
F_93 ( V_73 -> V_75 , V_75 ) ;
V_124 = 0 ;
V_94:
return V_124 ;
}
static struct V_10 * F_80 ( struct V_1 * V_9 ,
struct V_43 * V_44 ,
struct V_10 * V_11 )
{
return V_11 ;
}
static void F_82 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
}
static int F_89 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_94 ( struct V_42 * V_42 , struct V_43 * V_44 , struct V_10 * V_11 )
{
struct V_34 * V_35 = F_25 ( V_11 ) ;
struct V_90 * V_91 = (struct V_90 * ) V_35 ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned int V_134 = F_95 ( V_2 ) ;
struct V_106 * V_107 ;
T_3 V_109 ;
int V_66 = - V_112 ;
F_65 ( V_11 ) ;
if ( F_36 ( F_56 ( V_11 ) < V_134 && V_2 -> V_135 ) ) {
struct V_10 * V_136 ;
V_136 = F_96 ( V_11 , F_95 ( V_2 ) ) ;
if ( ! V_136 ) {
V_66 = - V_125 ;
goto V_45;
}
if ( V_11 -> V_44 )
F_97 ( V_136 , V_11 -> V_44 ) ;
F_98 ( V_11 ) ;
V_11 = V_136 ;
}
F_60 () ;
V_109 = ( V_137 T_3 ) F_99 ( V_91 , F_45 ( V_11 ) -> V_57 ) ;
V_107 = F_100 ( V_2 , V_109 ) ;
if ( F_36 ( ! V_107 ) )
V_107 = F_68 ( & V_138 , & V_109 , V_2 , false ) ;
if ( ! F_48 ( V_107 ) ) {
F_69 ( V_11 , V_107 ) ;
V_66 = F_70 ( V_107 , V_11 ) ;
}
F_62 () ;
V_45:
if ( F_36 ( V_66 < 0 ) )
F_5 ( V_11 -> V_2 , V_11 ) ;
return V_66 ;
}
static int F_101 ( struct V_42 * V_42 , struct V_43 * V_44 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_25 ( V_11 ) -> V_2 ;
F_102 ( V_42 , V_139 , V_11 -> V_3 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_38 = F_52 ( V_95 ) ;
return F_74 ( V_78 , V_113 ,
V_42 , V_44 , V_11 , NULL , V_2 ,
F_94 ,
! ( F_78 ( V_11 ) -> V_114 & V_117 ) ) ;
}
static struct V_10 * F_103 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
struct V_72 * V_73 = F_32 ( V_9 ) ;
struct V_34 * V_35 = NULL ;
struct V_90 * V_140 ;
F_34 () ;
V_140 = F_35 ( V_73 -> V_140 ) ;
if ( F_20 ( V_140 ) ) {
V_35 = & V_140 -> V_35 ;
F_39 ( V_35 ) ;
}
F_37 () ;
if ( F_36 ( ! V_35 ) ) {
F_5 ( V_9 , V_11 ) ;
return NULL ;
}
F_31 ( V_11 ) ;
F_17 ( V_11 , V_35 ) ;
return V_11 ;
}
static int F_104 ( struct V_42 * V_42 , struct V_43 * V_44 ,
struct V_10 * V_11 )
{
V_11 -> V_38 = F_52 ( V_95 ) ;
return F_74 ( V_78 , V_113 ,
V_42 , V_44 , V_11 , NULL , V_11 -> V_2 ,
F_54 ,
! ( F_78 ( V_11 ) -> V_114 & V_117 ) ) ;
}
static struct V_10 * F_105 ( struct V_1 * V_9 ,
struct V_43 * V_44 ,
struct V_10 * V_11 )
{
struct V_42 * V_42 = F_28 ( V_9 ) ;
int V_45 ;
V_11 -> V_2 = V_9 ;
V_45 = F_24 ( V_78 , V_47 , V_42 , V_44 ,
V_11 , NULL , V_9 , F_104 ) ;
if ( F_20 ( V_45 == 1 ) )
V_45 = F_104 ( V_42 , V_44 , V_11 ) ;
if ( F_20 ( V_45 == 1 ) )
F_65 ( V_11 ) ;
else
V_11 = NULL ;
return V_11 ;
}
static struct V_10 * F_106 ( struct V_1 * V_9 ,
struct V_43 * V_44 ,
struct V_10 * V_11 )
{
if ( F_107 ( F_45 ( V_11 ) -> V_57 ) )
return V_11 ;
if ( F_12 ( V_9 ) )
return F_105 ( V_9 , V_44 , V_11 ) ;
return F_103 ( V_9 , V_11 ) ;
}
static struct V_10 * F_108 ( struct V_1 * V_9 ,
struct V_43 * V_44 ,
struct V_10 * V_11 ,
T_4 V_141 )
{
switch ( V_141 ) {
case V_142 :
return F_106 ( V_9 , V_44 , V_11 ) ;
case V_143 :
return F_80 ( V_9 , V_44 , V_11 ) ;
}
return V_11 ;
}
static void F_109 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
struct V_90 * V_140 = F_83 ( V_73 -> V_140 ) ;
struct V_90 * V_92 = F_83 ( V_73 -> V_92 ) ;
struct V_42 * V_42 = F_28 ( V_2 ) ;
struct V_34 * V_35 ;
F_84 ( V_73 -> V_140 , NULL ) ;
F_84 ( V_73 -> V_92 , NULL ) ;
F_85 () ;
if ( V_140 ) {
V_35 = & V_140 -> V_35 ;
F_86 ( V_35 -> V_2 ) ;
V_35 -> V_2 = V_42 -> V_71 ;
F_87 ( V_35 -> V_2 ) ;
F_33 ( V_35 ) ;
}
if ( V_92 ) {
V_35 = & V_92 -> V_35 ;
F_86 ( V_35 -> V_2 ) ;
V_35 -> V_2 = V_42 -> V_71 ;
F_87 ( V_35 -> V_2 ) ;
F_33 ( V_35 ) ;
}
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = F_32 ( V_2 ) ;
struct V_90 * V_140 , * V_92 ;
if ( ! F_111 ( F_28 ( V_2 ) , V_73 -> V_126 ) )
return - V_125 ;
V_140 = F_112 ( V_2 , 0 , V_144 , 1 , 1 , 0 ) ;
if ( ! V_140 )
return - V_125 ;
V_92 = F_112 ( V_2 , V_145 , V_146 , 1 , 1 , 0 ) ;
if ( ! V_92 ) {
F_33 ( & V_140 -> V_35 ) ;
return - V_125 ;
}
V_140 -> V_35 . V_127 = F_101 ;
V_140 -> V_147 = V_73 -> V_126 ;
V_92 -> V_147 = V_73 -> V_126 ;
F_93 ( V_73 -> V_140 , V_140 ) ;
F_93 ( V_73 -> V_92 , V_92 ) ;
return 0 ;
}
static void F_113 ( struct V_1 * V_2 )
{
unsigned int V_114 = V_2 -> V_114 ;
int V_66 ;
if ( ! F_114 ( V_2 ) )
return;
V_66 = F_115 ( V_2 , V_114 & ~ V_148 ) ;
if ( V_66 >= 0 )
V_66 = F_115 ( V_2 , V_114 ) ;
if ( V_66 < 0 ) {
F_116 ( V_2 ,
L_1 ,
V_2 -> V_149 ) ;
}
}
static int F_117 ( struct V_1 * V_2 , struct V_1 * V_150 )
{
int V_66 ;
if ( V_150 == F_28 ( V_2 ) -> V_71 )
return - V_151 ;
V_150 -> V_152 |= V_153 ;
V_66 = F_118 ( V_150 , V_2 , NULL , NULL ) ;
if ( V_66 < 0 )
goto V_45;
F_113 ( V_150 ) ;
return 0 ;
V_45:
V_150 -> V_152 &= ~ V_153 ;
return V_66 ;
}
static int F_119 ( struct V_1 * V_2 , struct V_1 * V_150 )
{
if ( F_120 ( V_150 ) || F_121 ( V_150 ) )
return - V_112 ;
return F_117 ( V_2 , V_150 ) ;
}
static int F_122 ( struct V_1 * V_2 , struct V_1 * V_150 )
{
F_123 ( V_150 , V_2 ) ;
V_150 -> V_152 &= ~ V_153 ;
F_113 ( V_150 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 , struct V_1 * V_150 )
{
return F_122 ( V_2 , V_150 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = F_32 ( V_2 ) ;
struct V_1 * V_150 ;
struct V_154 * V_155 ;
F_109 ( V_2 , V_73 ) ;
F_82 ( V_2 , V_73 ) ;
F_126 (dev, port_dev, iter)
F_124 ( V_2 , V_150 ) ;
F_127 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static int F_128 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = F_32 ( V_2 ) ;
V_2 -> V_5 = F_129 ( struct V_4 ) ;
if ( ! V_2 -> V_5 )
goto V_156;
if ( F_110 ( V_2 ) != 0 )
goto V_157;
if ( F_89 ( V_2 ) != 0 )
goto V_158;
V_2 -> V_114 = V_159 | V_160 ;
V_2 -> V_161 = 64 * 1024 ;
V_2 -> V_162 = V_163 ;
F_130 ( V_2 ) ;
return 0 ;
V_158:
F_109 ( V_2 , V_73 ) ;
V_157:
F_127 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_156:
return - V_125 ;
}
static T_3 F_131 ( const struct V_1 * V_2 )
{
struct V_72 * V_73 = F_32 ( V_2 ) ;
return V_73 -> V_126 ;
}
static int F_132 ( struct V_42 * V_42 , struct V_43 * V_44 , struct V_10 * V_11 )
{
F_6 ( V_11 ) ;
return 0 ;
}
static struct V_10 * F_133 ( T_5 V_164 , unsigned int V_165 ,
struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_42 * V_42 = F_28 ( V_2 ) ;
if ( F_24 ( V_164 , V_165 , V_42 , NULL , V_11 , V_2 , NULL , F_132 ) != 1 )
V_11 = NULL ;
return V_11 ;
}
static bool F_134 ( const struct V_10 * V_11 )
{
const struct V_49 * V_50 = F_27 ( V_11 ) ;
bool V_124 = false ;
if ( V_50 -> V_63 == V_166 ) {
const struct V_167 * V_168 ;
struct V_167 V_169 ;
V_168 = F_135 ( V_11 , sizeof( * V_50 ) ,
sizeof( V_169 ) , & V_169 ) ;
if ( ! V_168 )
goto V_94;
switch ( V_168 -> V_170 ) {
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
V_124 = true ;
break;
}
}
V_94:
return V_124 ;
}
static struct V_74 * F_136 ( struct V_42 * V_42 ,
const struct V_1 * V_2 ,
struct V_51 * V_52 ,
int V_54 ,
int V_114 )
{
struct V_72 * V_73 = F_32 ( V_2 ) ;
struct V_122 * V_176 = NULL ;
struct V_74 * V_116 ;
F_34 () ;
V_116 = F_35 ( V_73 -> V_116 ) ;
if ( F_20 ( V_116 ) )
V_176 = V_116 -> V_123 ;
F_37 () ;
if ( ! V_176 )
return NULL ;
return F_137 ( V_42 , V_176 , V_54 , V_52 , V_114 ) ;
}
static void F_138 ( struct V_10 * V_11 , struct V_1 * V_9 ,
int V_54 )
{
const struct V_49 * V_50 = F_27 ( V_11 ) ;
struct V_51 V_52 = {
. V_57 = V_50 -> V_57 ,
. V_58 = V_50 -> V_58 ,
. V_59 = F_29 ( V_50 ) ,
. V_60 = V_11 -> V_61 ,
. V_62 = V_50 -> V_63 ,
. V_55 = V_54 ,
} ;
struct V_42 * V_42 = F_28 ( V_9 ) ;
struct V_74 * V_116 ;
V_116 = F_136 ( V_42 , V_9 , & V_52 , V_54 ,
V_177 | V_178 ) ;
if ( F_36 ( ! V_116 ) )
return;
if ( F_36 ( & V_116 -> V_35 == & V_42 -> V_69 . V_70 -> V_35 ) )
return;
F_17 ( V_11 , & V_116 -> V_35 ) ;
}
static struct V_10 * F_139 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
int V_179 = V_11 -> V_180 ;
bool V_181 ;
if ( V_11 -> V_36 == V_37 ) {
V_11 -> V_2 = V_9 ;
V_11 -> V_180 = V_9 -> V_54 ;
F_75 ( V_11 ) -> V_114 |= V_182 ;
V_11 -> V_36 = V_183 ;
goto V_94;
}
V_181 = F_81 ( & F_27 ( V_11 ) -> V_57 ) ;
if ( ! F_134 ( V_11 ) && ! V_181 ) {
F_1 ( V_9 , V_11 -> V_3 ) ;
V_11 -> V_2 = V_9 ;
V_11 -> V_180 = V_9 -> V_54 ;
if ( ! F_55 ( & V_9 -> V_98 ) ) {
F_57 ( V_11 , V_11 -> V_184 ) ;
F_61 ( V_11 , V_9 ) ;
F_63 ( V_11 , V_11 -> V_184 ) ;
}
F_75 ( V_11 ) -> V_114 |= V_182 ;
}
if ( V_181 )
F_138 ( V_11 , V_9 , V_179 ) ;
V_11 = F_133 ( V_46 , V_185 , V_11 , V_9 ) ;
V_94:
return V_11 ;
}
static struct V_10 * F_139 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
return V_11 ;
}
static struct V_10 * F_140 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
V_11 -> V_2 = V_9 ;
V_11 -> V_180 = V_9 -> V_54 ;
F_78 ( V_11 ) -> V_114 |= V_186 ;
if ( F_107 ( F_45 ( V_11 ) -> V_57 ) )
goto V_94;
if ( V_11 -> V_36 == V_37 ) {
V_11 -> V_36 = V_183 ;
goto V_94;
}
F_1 ( V_9 , V_11 -> V_3 ) ;
if ( ! F_55 ( & V_9 -> V_98 ) ) {
F_57 ( V_11 , V_11 -> V_184 ) ;
F_61 ( V_11 , V_9 ) ;
F_63 ( V_11 , V_11 -> V_184 ) ;
}
V_11 = F_133 ( V_78 , V_185 , V_11 , V_9 ) ;
V_94:
return V_11 ;
}
static struct V_10 * F_141 ( struct V_1 * V_9 ,
struct V_10 * V_11 ,
T_4 V_141 )
{
switch ( V_141 ) {
case V_142 :
return F_140 ( V_9 , V_11 ) ;
case V_143 :
return F_139 ( V_9 , V_11 ) ;
}
return V_11 ;
}
static struct V_34 * F_142 ( const struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_42 * V_42 = F_28 ( V_2 ) ;
int V_114 = V_178 ;
struct V_34 * V_35 = NULL ;
struct V_74 * V_91 ;
if ( V_52 -> V_53 == V_2 -> V_54 ) {
V_35 = & V_42 -> V_69 . V_70 -> V_35 ;
F_39 ( V_35 ) ;
return V_35 ;
}
if ( ! F_143 ( & V_52 -> V_58 ) )
V_114 |= V_177 ;
V_91 = F_136 ( V_42 , V_2 , V_52 , V_52 -> V_53 , V_114 ) ;
if ( V_91 )
V_35 = & V_91 -> V_35 ;
return V_35 ;
}
static void F_144 ( struct V_1 * V_2 ,
struct V_187 * V_188 )
{
F_145 ( V_188 -> V_189 , V_190 , sizeof( V_188 -> V_189 ) ) ;
F_145 ( V_188 -> V_191 , V_192 , sizeof( V_188 -> V_191 ) ) ;
}
static inline T_6 F_146 ( void )
{
T_6 V_193 ;
V_193 = F_147 ( sizeof( struct V_194 ) ) ;
V_193 += F_148 ( sizeof( T_5 ) ) ;
V_193 += F_148 ( sizeof( T_3 ) ) ;
return V_193 ;
}
static int F_149 ( const struct V_1 * V_2 , T_7 V_195 , bool V_196 )
{
struct V_194 * V_197 ;
struct V_198 * V_199 ;
struct V_10 * V_11 ;
int V_45 ;
if ( V_195 == V_143 && ! F_90 () )
return 0 ;
V_11 = F_150 ( F_146 () , V_200 ) ;
if ( ! V_11 )
return - V_125 ;
V_199 = F_151 ( V_11 , 0 , 0 , 0 , sizeof( * V_197 ) , 0 ) ;
if ( ! V_199 )
goto V_201;
V_199 -> V_202 |= V_203 ;
V_197 = F_152 ( V_199 ) ;
memset ( V_197 , 0 , sizeof( * V_197 ) ) ;
V_197 -> V_195 = V_195 ;
V_197 -> V_204 = V_205 ;
if ( F_153 ( V_11 , V_206 , 1 ) )
goto V_201;
if ( F_153 ( V_11 , V_207 , V_208 ) )
goto V_201;
F_154 ( V_11 , V_199 ) ;
V_11 -> V_44 = F_28 ( V_2 ) -> V_209 ;
if ( V_196 ) {
V_45 = F_155 ( V_11 , V_199 , NULL ) ;
if ( V_45 == - V_210 )
V_45 = 0 ;
} else {
V_45 = F_156 ( V_11 , V_199 , NULL ) ;
if ( V_45 == - V_211 )
V_45 = 0 ;
}
F_157 ( V_11 ) ;
return V_45 ;
V_201:
F_157 ( V_11 ) ;
return - V_212 ;
}
static int F_158 ( const struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_149 ( V_2 , V_142 , true ) ;
if ( V_45 < 0 )
goto V_213;
V_45 = F_149 ( V_2 , V_143 , true ) ;
if ( V_45 < 0 )
goto V_214;
#if F_159 ( V_215 )
V_45 = F_149 ( V_2 , V_216 , true ) ;
if ( V_45 < 0 )
goto V_217;
#endif
return 0 ;
#if F_159 ( V_215 )
V_217:
F_149 ( V_2 , V_143 , false ) ;
#endif
V_214:
F_149 ( V_2 , V_142 , false ) ;
V_213:
F_116 ( V_2 , L_2 ) ;
return V_45 ;
}
static void F_160 ( struct V_1 * V_2 )
{
F_161 ( V_2 ) ;
V_2 -> V_218 = & V_219 ;
V_2 -> V_220 = & V_221 ;
V_2 -> V_222 = & V_223 ;
V_2 -> V_224 = true ;
F_162 ( V_2 ) ;
V_2 -> V_225 |= V_226 ;
V_2 -> V_225 |= V_227 ;
V_2 -> V_225 |= V_228 ;
V_2 -> V_225 |= V_229 ;
V_2 -> V_225 |= V_230 | V_231 ;
V_2 -> V_225 |= V_232 | V_233 | V_234 ;
V_2 -> V_235 = V_2 -> V_225 ;
V_2 -> V_236 = V_2 -> V_225 ;
V_2 -> V_152 |= V_237 ;
}
static int F_163 ( struct V_238 * V_239 [] , struct V_238 * V_240 [] )
{
if ( V_239 [ V_241 ] ) {
if ( F_164 ( V_239 [ V_241 ] ) != V_242 )
return - V_112 ;
if ( ! F_165 ( F_166 ( V_239 [ V_241 ] ) ) )
return - V_243 ;
}
return 0 ;
}
static void F_167 ( struct V_1 * V_2 , struct V_154 * V_244 )
{
F_168 ( V_2 , V_244 ) ;
}
static int F_169 ( struct V_42 * V_245 , struct V_1 * V_2 ,
struct V_238 * V_239 [] , struct V_238 * V_240 [] )
{
struct V_72 * V_73 = F_32 ( V_2 ) ;
bool * V_246 ;
struct V_42 * V_42 ;
int V_45 ;
if ( ! V_240 || ! V_240 [ V_247 ] )
return - V_112 ;
V_73 -> V_126 = F_170 ( V_240 [ V_247 ] ) ;
if ( V_73 -> V_126 == V_248 )
return - V_112 ;
V_2 -> V_152 |= V_249 ;
V_45 = F_171 ( V_2 ) ;
if ( V_45 )
goto V_94;
V_42 = F_28 ( V_2 ) ;
V_246 = F_172 ( V_42 , V_250 ) ;
if ( * V_246 ) {
V_45 = F_158 ( V_2 ) ;
if ( V_45 ) {
F_173 ( V_2 ) ;
goto V_94;
}
* V_246 = false ;
}
V_94:
return V_45 ;
}
static T_6 F_174 ( const struct V_1 * V_2 )
{
return F_148 ( sizeof( T_3 ) ) ;
}
static int F_175 ( struct V_10 * V_11 ,
const struct V_1 * V_2 )
{
struct V_72 * V_73 = F_32 ( V_2 ) ;
return F_153 ( V_11 , V_247 , V_73 -> V_126 ) ;
}
static T_6 F_176 ( const struct V_1 * V_251 ,
const struct V_1 * V_252 )
{
return F_148 ( sizeof( T_3 ) ) ;
}
static int F_177 ( struct V_10 * V_11 ,
const struct V_1 * V_9 ,
const struct V_1 * V_252 )
{
struct V_72 * V_73 = F_32 ( V_9 ) ;
if ( F_153 ( V_11 , V_253 , V_73 -> V_126 ) )
return - V_212 ;
return 0 ;
}
static int F_178 ( struct V_254 * V_255 ,
unsigned long V_256 , void * V_257 )
{
struct V_1 * V_2 = F_179 ( V_257 ) ;
if ( V_256 == V_258 ) {
struct V_1 * V_9 ;
if ( ! F_121 ( V_2 ) )
goto V_94;
V_9 = F_180 ( V_2 ) ;
F_124 ( V_9 , V_2 ) ;
}
V_94:
return V_259 ;
}
static int T_8 F_181 ( struct V_42 * V_42 )
{
bool * V_246 = F_172 ( V_42 , V_250 ) ;
* V_246 = true ;
return 0 ;
}
static int T_9 F_182 ( void )
{
int V_124 ;
F_183 ( & V_260 ) ;
V_124 = F_184 ( & V_261 ) ;
if ( V_124 < 0 )
goto error;
V_124 = F_185 ( & V_262 ) ;
if ( V_124 < 0 ) {
F_186 ( & V_261 ) ;
goto error;
}
return 0 ;
error:
F_187 ( & V_260 ) ;
return V_124 ;
}

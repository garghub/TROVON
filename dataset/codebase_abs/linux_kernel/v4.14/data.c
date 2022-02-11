static bool F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
struct V_4 * V_4 ;
struct V_5 * V_6 ;
if ( ! V_3 )
return false ;
V_4 = V_3 -> V_7 ;
V_6 = F_2 ( V_4 ) ;
if ( V_4 -> V_8 == F_3 ( V_6 ) ||
V_4 -> V_8 == F_4 ( V_6 ) ||
F_5 ( V_4 -> V_9 ) ||
F_6 ( V_1 ) )
return true ;
return false ;
}
static void F_7 ( struct V_10 * V_10 )
{
struct V_11 * V_12 ;
int V_13 ;
#ifdef F_8
if ( F_9 ( F_10 ( V_10 -> V_14 -> V_15 ) , V_16 ) ) {
F_11 ( V_16 ) ;
V_10 -> V_17 = V_18 ;
}
#endif
if ( F_12 ( V_10 ) ) {
if ( V_10 -> V_17 ) {
F_13 ( V_10 -> V_19 ) ;
} else {
F_14 ( V_10 -> V_19 , V_10 ) ;
return;
}
}
F_15 (bvec, bio, i) {
struct V_1 * V_1 = V_12 -> V_15 ;
if ( ! V_10 -> V_17 ) {
if ( ! F_16 ( V_1 ) )
F_17 ( V_1 ) ;
} else {
F_18 ( V_1 ) ;
F_19 ( V_1 ) ;
}
F_20 ( V_1 ) ;
}
F_21 ( V_10 ) ;
}
static void F_22 ( struct V_10 * V_10 )
{
struct V_5 * V_6 = V_10 -> V_19 ;
struct V_11 * V_12 ;
int V_13 ;
F_15 (bvec, bio, i) {
struct V_1 * V_1 = V_12 -> V_15 ;
enum V_20 type = F_23 ( V_1 ) ;
if ( F_24 ( V_1 ) ) {
F_25 ( V_1 , ( unsigned long ) NULL ) ;
F_26 ( V_1 ) ;
F_20 ( V_1 ) ;
F_27 ( V_1 , V_6 -> V_21 ) ;
if ( F_28 ( V_10 -> V_17 ) )
F_29 ( V_6 , true ) ;
continue;
}
F_30 ( & V_1 , true ) ;
if ( F_28 ( V_10 -> V_17 ) ) {
F_31 ( V_1 -> V_3 , - V_22 ) ;
F_29 ( V_6 , true ) ;
}
F_32 ( V_6 , type ) ;
F_33 ( V_1 ) ;
F_34 ( V_1 ) ;
}
if ( ! F_35 ( V_6 , V_23 ) &&
F_36 ( & V_6 -> V_24 ) )
F_37 ( & V_6 -> V_24 ) ;
F_21 ( V_10 ) ;
}
struct V_25 * F_38 ( struct V_5 * V_6 ,
T_1 V_26 , struct V_10 * V_10 )
{
struct V_25 * V_27 = V_6 -> V_28 -> V_29 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_30 ; V_13 ++ ) {
if ( F_39 ( V_13 ) . V_31 <= V_26 &&
F_39 ( V_13 ) . V_32 >= V_26 ) {
V_26 -= F_39 ( V_13 ) . V_31 ;
V_27 = F_39 ( V_13 ) . V_27 ;
break;
}
}
if ( V_10 ) {
F_40 ( V_10 , V_27 ) ;
V_10 -> V_33 . V_34 = F_41 ( V_26 ) ;
}
return V_27 ;
}
int F_42 ( struct V_5 * V_6 , T_1 V_35 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_30 ; V_13 ++ )
if ( F_39 ( V_13 ) . V_31 <= V_35 && F_39 ( V_13 ) . V_32 >= V_35 )
return V_13 ;
return 0 ;
}
static bool F_43 ( struct V_5 * V_6 ,
T_1 V_26 , struct V_10 * V_10 )
{
struct V_25 * V_36 = F_38 ( V_6 , V_26 , NULL ) ;
return V_10 -> V_37 == V_36 -> V_38 && V_10 -> V_39 == V_36 -> V_40 ;
}
static struct V_10 * F_44 ( struct V_5 * V_6 , T_1 V_26 ,
int V_41 , bool V_42 )
{
struct V_10 * V_10 ;
V_10 = F_45 ( V_41 ) ;
F_38 ( V_6 , V_26 , V_10 ) ;
V_10 -> V_43 = V_42 ? F_7 : F_22 ;
V_10 -> V_19 = V_42 ? NULL : V_6 ;
return V_10 ;
}
static inline void F_46 ( struct V_5 * V_6 ,
struct V_10 * V_10 , enum V_44 type )
{
if ( ! F_47 ( F_48 ( V_10 ) ) ) {
unsigned int V_45 ;
if ( F_49 ( V_6 -> V_28 ) &&
V_46 -> V_47 && ( type == V_48 || type == V_49 ) )
F_50 ( V_46 -> V_47 ) ;
if ( type != V_48 && type != V_49 )
goto V_50;
V_45 = V_10 -> V_33 . V_51 >> V_52 ;
V_45 %= F_51 ( V_6 ) ;
if ( V_45 == 0 )
goto V_50;
for (; V_45 < F_51 ( V_6 ) ; V_45 ++ ) {
struct V_1 * V_1 =
F_52 ( V_6 -> V_21 ,
V_53 | V_54 | V_55 ) ;
F_53 ( V_6 , ! V_1 ) ;
F_54 ( V_1 ) ;
F_25 ( V_1 , ( unsigned long ) V_56 ) ;
F_55 ( V_1 ) ;
if ( F_56 ( V_10 , V_1 , V_57 , 0 ) < V_57 )
F_53 ( V_6 , 1 ) ;
}
if ( type == V_49 )
F_57 ( V_6 , V_58 ) ;
}
V_50:
if ( F_47 ( F_48 ( V_10 ) ) )
F_58 ( V_6 -> V_28 , type , V_10 ) ;
else
F_59 ( V_6 -> V_28 , type , V_10 ) ;
F_60 ( V_10 ) ;
}
static void F_61 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = & V_60 -> V_62 ;
if ( ! V_60 -> V_10 )
return;
F_62 ( V_60 -> V_10 , V_62 -> V_63 , V_62 -> V_64 ) ;
if ( F_47 ( V_62 -> V_63 ) )
F_63 ( V_60 -> V_6 -> V_28 , V_62 -> type , V_60 -> V_10 ) ;
else
F_64 ( V_60 -> V_6 -> V_28 , V_62 -> type , V_60 -> V_10 ) ;
F_46 ( V_60 -> V_6 , V_60 -> V_10 , V_62 -> type ) ;
V_60 -> V_10 = NULL ;
}
static bool F_65 ( struct V_59 * V_60 ,
struct V_4 * V_4 , T_2 V_65 , T_3 V_66 )
{
struct V_11 * V_12 ;
struct V_1 * V_67 ;
int V_13 ;
if ( ! V_60 -> V_10 )
return false ;
if ( ! V_4 && ! V_65 )
return true ;
F_15 (bvec, io->bio, i) {
if ( V_12 -> V_15 -> V_3 )
V_67 = V_12 -> V_15 ;
else
V_67 = F_66 ( V_12 -> V_15 ) ;
if ( V_66 != V_67 -> V_68 )
continue;
if ( V_4 && V_4 == V_67 -> V_3 -> V_7 )
return true ;
if ( V_65 && V_65 == F_67 ( V_67 ) )
return true ;
}
return false ;
}
static bool F_68 ( struct V_5 * V_6 , struct V_4 * V_4 ,
T_2 V_65 , T_3 V_66 , enum V_44 type )
{
enum V_44 V_69 = F_69 ( type ) ;
enum V_70 V_71 ;
struct V_59 * V_60 ;
bool V_72 = false ;
for ( V_71 = V_73 ; V_71 < V_74 ; V_71 ++ ) {
V_60 = V_6 -> V_75 [ V_69 ] + V_71 ;
F_70 ( & V_60 -> V_76 ) ;
V_72 = F_65 ( V_60 , V_4 , V_65 , V_66 ) ;
F_71 ( & V_60 -> V_76 ) ;
if ( V_72 || V_69 == V_77 )
break;
}
return V_72 ;
}
static void F_72 ( struct V_5 * V_6 ,
enum V_44 type , enum V_70 V_71 )
{
enum V_44 V_69 = F_69 ( type ) ;
struct V_59 * V_60 = V_6 -> V_75 [ V_69 ] + V_71 ;
F_73 ( & V_60 -> V_76 ) ;
if ( type >= V_78 ) {
V_60 -> V_62 . type = V_78 ;
V_60 -> V_62 . V_63 = V_79 ;
V_60 -> V_62 . V_64 = V_80 | V_81 | V_82 ;
if ( ! F_74 ( V_6 , V_83 ) )
V_60 -> V_62 . V_64 |= V_84 | V_85 ;
}
F_61 ( V_60 ) ;
F_75 ( & V_60 -> V_76 ) ;
}
static void F_76 ( struct V_5 * V_6 ,
struct V_4 * V_4 , T_2 V_65 , T_3 V_66 ,
enum V_44 type , bool V_86 )
{
enum V_70 V_71 ;
if ( ! V_86 && ! F_68 ( V_6 , V_4 , V_65 , V_66 , type ) )
return;
for ( V_71 = V_73 ; V_71 < V_74 ; V_71 ++ ) {
F_72 ( V_6 , type , V_71 ) ;
if ( type >= V_77 )
break;
}
}
void F_77 ( struct V_5 * V_6 , enum V_44 type )
{
F_76 ( V_6 , NULL , 0 , 0 , type , true ) ;
}
void F_78 ( struct V_5 * V_6 ,
struct V_4 * V_4 , T_2 V_65 , T_3 V_66 ,
enum V_44 type )
{
F_76 ( V_6 , V_4 , V_65 , V_66 , type , false ) ;
}
void F_79 ( struct V_5 * V_6 )
{
F_77 ( V_6 , V_48 ) ;
F_77 ( V_6 , V_49 ) ;
F_77 ( V_6 , V_77 ) ;
}
int F_80 ( struct V_61 * V_62 )
{
struct V_10 * V_10 ;
struct V_1 * V_1 = V_62 -> V_87 ?
V_62 -> V_87 : V_62 -> V_1 ;
F_81 ( V_1 , V_62 ) ;
F_82 ( V_62 , 0 ) ;
V_10 = F_44 ( V_62 -> V_6 , V_62 -> V_88 , 1 , F_47 ( V_62 -> V_63 ) ) ;
if ( F_56 ( V_10 , V_1 , V_57 , 0 ) < V_57 ) {
F_21 ( V_10 ) ;
return - V_89 ;
}
F_62 ( V_10 , V_62 -> V_63 , V_62 -> V_64 ) ;
F_46 ( V_62 -> V_6 , V_10 , V_62 -> type ) ;
if ( ! F_47 ( V_62 -> V_63 ) )
F_83 ( V_62 -> V_6 , F_23 ( V_62 -> V_1 ) ) ;
return 0 ;
}
int F_84 ( struct V_61 * V_62 )
{
struct V_5 * V_6 = V_62 -> V_6 ;
enum V_44 V_69 = F_69 ( V_62 -> type ) ;
struct V_59 * V_60 = V_6 -> V_75 [ V_69 ] + V_62 -> V_71 ;
struct V_1 * V_90 ;
int V_91 = 0 ;
F_53 ( V_6 , F_47 ( V_62 -> V_63 ) ) ;
F_73 ( & V_60 -> V_76 ) ;
V_92:
if ( V_62 -> V_93 ) {
F_85 ( & V_60 -> V_94 ) ;
if ( F_86 ( & V_60 -> V_95 ) ) {
F_87 ( & V_60 -> V_94 ) ;
goto V_96;
}
V_62 = F_88 ( & V_60 -> V_95 ,
struct V_61 , V_97 ) ;
F_89 ( & V_62 -> V_97 ) ;
F_87 ( & V_60 -> V_94 ) ;
}
if ( V_62 -> V_98 != V_99 )
F_90 ( V_6 , V_62 -> V_98 ) ;
F_90 ( V_6 , V_62 -> V_88 ) ;
V_90 = V_62 -> V_87 ? V_62 -> V_87 : V_62 -> V_1 ;
V_62 -> V_100 = 1 ;
F_83 ( V_6 , F_23 ( V_90 ) ) ;
if ( V_60 -> V_10 && ( V_60 -> V_101 != V_62 -> V_88 - 1 ||
( V_60 -> V_62 . V_63 != V_62 -> V_63 || V_60 -> V_62 . V_64 != V_62 -> V_64 ) ||
! F_43 ( V_6 , V_62 -> V_88 , V_60 -> V_10 ) ) )
F_61 ( V_60 ) ;
V_102:
if ( V_60 -> V_10 == NULL ) {
if ( ( V_62 -> type == V_48 || V_62 -> type == V_49 ) &&
V_62 -> V_88 & F_91 ( V_6 ) ) {
V_91 = - V_103 ;
F_32 ( V_6 , F_23 ( V_90 ) ) ;
goto V_96;
}
V_60 -> V_10 = F_44 ( V_6 , V_62 -> V_88 ,
V_104 , false ) ;
V_60 -> V_62 = * V_62 ;
}
if ( F_56 ( V_60 -> V_10 , V_90 , V_57 , 0 ) < V_57 ) {
F_61 ( V_60 ) ;
goto V_102;
}
V_60 -> V_101 = V_62 -> V_88 ;
F_82 ( V_62 , 0 ) ;
F_92 ( V_62 -> V_1 , V_62 ) ;
if ( V_62 -> V_93 )
goto V_92;
V_96:
F_75 ( & V_60 -> V_76 ) ;
return V_91 ;
}
static struct V_10 * F_93 ( struct V_4 * V_4 , T_1 V_35 ,
unsigned V_105 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_106 * V_107 = NULL ;
struct V_10 * V_10 ;
if ( F_94 ( V_4 ) ) {
V_107 = F_95 ( V_4 , V_108 ) ;
if ( F_96 ( V_107 ) )
return F_97 ( V_107 ) ;
F_98 ( V_6 , V_35 ) ;
}
V_10 = F_99 ( V_109 , F_100 ( int , V_105 , V_104 ) ) ;
if ( ! V_10 ) {
if ( V_107 )
F_13 ( V_107 ) ;
return F_101 ( - V_110 ) ;
}
F_38 ( V_6 , V_35 , V_10 ) ;
V_10 -> V_43 = F_7 ;
V_10 -> V_19 = V_107 ;
F_62 ( V_10 , V_111 , 0 ) ;
return V_10 ;
}
static int F_102 ( struct V_4 * V_4 , struct V_1 * V_1 ,
T_1 V_35 )
{
struct V_10 * V_10 = F_93 ( V_4 , V_35 , 1 ) ;
if ( F_96 ( V_10 ) )
return F_103 ( V_10 ) ;
if ( F_56 ( V_10 , V_1 , V_57 , 0 ) < V_57 ) {
F_21 ( V_10 ) ;
return - V_89 ;
}
F_46 ( F_2 ( V_4 ) , V_10 , V_48 ) ;
return 0 ;
}
static void F_104 ( struct V_112 * V_113 )
{
struct V_114 * V_115 = F_105 ( V_113 -> V_116 ) ;
T_4 * V_117 ;
int V_118 = 0 ;
if ( F_106 ( V_113 -> V_116 ) && F_107 ( V_113 -> V_4 ) )
V_118 = F_108 ( V_113 -> V_4 ) ;
V_117 = F_109 ( V_115 ) ;
V_117 [ V_118 + V_113 -> V_119 ] = F_110 ( V_113 -> V_120 ) ;
}
void F_111 ( struct V_112 * V_113 )
{
F_112 ( V_113 -> V_116 , V_49 , true ) ;
F_104 ( V_113 ) ;
if ( F_113 ( V_113 -> V_116 ) )
V_113 -> V_121 = true ;
}
void F_114 ( struct V_112 * V_113 , T_1 V_35 )
{
V_113 -> V_120 = V_35 ;
F_111 ( V_113 ) ;
F_115 ( V_113 ) ;
}
int F_116 ( struct V_112 * V_113 , T_5 V_122 )
{
struct V_5 * V_6 = F_2 ( V_113 -> V_4 ) ;
int V_91 ;
if ( ! V_122 )
return 0 ;
if ( F_28 ( F_117 ( V_113 -> V_4 , V_123 ) ) )
return - V_124 ;
if ( F_28 ( ( V_91 = F_118 ( V_6 , V_113 -> V_4 , & V_122 ) ) ) )
return V_91 ;
F_119 ( V_113 -> V_4 , V_113 -> V_125 ,
V_113 -> V_119 , V_122 ) ;
F_112 ( V_113 -> V_116 , V_49 , true ) ;
for (; V_122 > 0 ; V_113 -> V_119 ++ ) {
T_1 V_35 = F_120 ( V_113 -> V_4 ,
V_113 -> V_116 , V_113 -> V_119 ) ;
if ( V_35 == V_126 ) {
V_113 -> V_120 = V_99 ;
F_104 ( V_113 ) ;
V_122 -- ;
}
}
if ( F_113 ( V_113 -> V_116 ) )
V_113 -> V_121 = true ;
return 0 ;
}
int F_121 ( struct V_112 * V_113 )
{
unsigned int V_119 = V_113 -> V_119 ;
int V_72 ;
V_72 = F_116 ( V_113 , 1 ) ;
V_113 -> V_119 = V_119 ;
return V_72 ;
}
int F_122 ( struct V_112 * V_113 , T_3 V_68 )
{
bool V_127 = V_113 -> V_128 ? false : true ;
int V_91 ;
V_91 = F_123 ( V_113 , V_68 , V_129 ) ;
if ( V_91 )
return V_91 ;
if ( V_113 -> V_120 == V_126 )
V_91 = F_121 ( V_113 ) ;
if ( V_91 || V_127 )
F_124 ( V_113 ) ;
return V_91 ;
}
int F_125 ( struct V_112 * V_113 , T_3 V_68 )
{
struct V_130 V_131 = { 0 , 0 , 0 } ;
struct V_4 * V_4 = V_113 -> V_4 ;
if ( F_126 ( V_4 , V_68 , & V_131 ) ) {
V_113 -> V_120 = V_131 . V_132 + V_68 - V_131 . V_133 ;
return 0 ;
}
return F_122 ( V_113 , V_68 ) ;
}
struct V_1 * F_127 ( struct V_4 * V_4 , T_3 V_68 ,
int V_64 , bool V_134 )
{
struct V_2 * V_3 = V_4 -> V_135 ;
struct V_112 V_113 ;
struct V_1 * V_1 ;
struct V_130 V_131 = { 0 , 0 , 0 } ;
int V_91 ;
V_1 = F_128 ( V_3 , V_68 , V_134 ) ;
if ( ! V_1 )
return F_101 ( - V_110 ) ;
if ( F_126 ( V_4 , V_68 , & V_131 ) ) {
V_113 . V_120 = V_131 . V_132 + V_68 - V_131 . V_133 ;
goto V_136;
}
F_129 ( & V_113 , V_4 , NULL , NULL , 0 ) ;
V_91 = F_123 ( & V_113 , V_68 , V_137 ) ;
if ( V_91 )
goto V_138;
F_124 ( & V_113 ) ;
if ( F_28 ( V_113 . V_120 == V_126 ) ) {
V_91 = - V_139 ;
goto V_138;
}
V_136:
if ( F_16 ( V_1 ) ) {
F_20 ( V_1 ) ;
return V_1 ;
}
if ( V_113 . V_120 == V_99 ) {
F_130 ( V_1 , 0 , V_57 ) ;
if ( ! F_16 ( V_1 ) )
F_17 ( V_1 ) ;
F_20 ( V_1 ) ;
return V_1 ;
}
V_91 = F_102 ( V_4 , V_1 , V_113 . V_120 ) ;
if ( V_91 )
goto V_138;
return V_1 ;
V_138:
F_131 ( V_1 , 1 ) ;
return F_101 ( V_91 ) ;
}
struct V_1 * F_132 ( struct V_4 * V_4 , T_3 V_68 )
{
struct V_2 * V_3 = V_4 -> V_135 ;
struct V_1 * V_1 ;
V_1 = F_133 ( V_3 , V_68 ) ;
if ( V_1 && F_16 ( V_1 ) )
return V_1 ;
F_131 ( V_1 , 0 ) ;
V_1 = F_127 ( V_4 , V_68 , 0 , false ) ;
if ( F_96 ( V_1 ) )
return V_1 ;
if ( F_16 ( V_1 ) )
return V_1 ;
F_134 ( V_1 ) ;
if ( F_28 ( ! F_16 ( V_1 ) ) ) {
F_131 ( V_1 , 0 ) ;
return F_101 ( - V_22 ) ;
}
return V_1 ;
}
struct V_1 * F_135 ( struct V_4 * V_4 , T_3 V_68 ,
bool V_134 )
{
struct V_2 * V_3 = V_4 -> V_135 ;
struct V_1 * V_1 ;
V_140:
V_1 = F_127 ( V_4 , V_68 , 0 , V_134 ) ;
if ( F_96 ( V_1 ) )
return V_1 ;
F_55 ( V_1 ) ;
if ( F_28 ( V_1 -> V_3 != V_3 ) ) {
F_131 ( V_1 , 1 ) ;
goto V_140;
}
if ( F_28 ( ! F_16 ( V_1 ) ) ) {
F_131 ( V_1 , 1 ) ;
return F_101 ( - V_22 ) ;
}
return V_1 ;
}
struct V_1 * F_136 ( struct V_4 * V_4 ,
struct V_1 * V_141 , T_3 V_68 , bool V_142 )
{
struct V_2 * V_3 = V_4 -> V_135 ;
struct V_1 * V_1 ;
struct V_112 V_113 ;
int V_91 ;
V_1 = F_128 ( V_3 , V_68 , true ) ;
if ( ! V_1 ) {
F_131 ( V_141 , 1 ) ;
return F_101 ( - V_110 ) ;
}
F_129 ( & V_113 , V_4 , V_141 , NULL , 0 ) ;
V_91 = F_122 ( & V_113 , V_68 ) ;
if ( V_91 ) {
F_131 ( V_1 , 1 ) ;
return F_101 ( V_91 ) ;
}
if ( ! V_141 )
F_124 ( & V_113 ) ;
if ( F_16 ( V_1 ) )
goto V_136;
if ( V_113 . V_120 == V_99 ) {
F_130 ( V_1 , 0 , V_57 ) ;
if ( ! F_16 ( V_1 ) )
F_17 ( V_1 ) ;
} else {
F_131 ( V_1 , 1 ) ;
F_53 ( F_2 ( V_4 ) , V_141 ) ;
V_1 = F_135 ( V_4 , V_68 , true ) ;
if ( F_96 ( V_1 ) )
return V_1 ;
}
V_136:
if ( V_142 && F_137 ( V_4 ) <
( ( V_143 ) ( V_68 + 1 ) << V_144 ) )
F_138 ( V_4 , ( ( V_143 ) ( V_68 + 1 ) << V_144 ) ) ;
return V_1 ;
}
static int F_139 ( struct V_112 * V_113 )
{
struct V_5 * V_6 = F_2 ( V_113 -> V_4 ) ;
struct V_145 V_146 ;
struct V_147 V_148 ;
T_3 V_133 ;
T_5 V_122 = 1 ;
int V_91 ;
if ( F_28 ( F_117 ( V_113 -> V_4 , V_123 ) ) )
return - V_124 ;
V_113 -> V_120 = F_120 ( V_113 -> V_4 ,
V_113 -> V_116 , V_113 -> V_119 ) ;
if ( V_113 -> V_120 == V_99 )
goto V_149;
if ( F_28 ( ( V_91 = F_118 ( V_6 , V_113 -> V_4 , & V_122 ) ) ) )
return V_91 ;
V_149:
F_140 ( V_6 , V_113 -> V_125 , & V_148 ) ;
F_141 ( & V_146 , V_113 -> V_125 , V_113 -> V_119 , V_148 . V_150 ) ;
F_142 ( V_6 , NULL , V_113 -> V_120 , & V_113 -> V_120 ,
& V_146 , V_151 , NULL , false ) ;
F_111 ( V_113 ) ;
V_133 = F_143 ( F_144 ( V_113 -> V_116 ) , V_113 -> V_4 ) +
V_113 -> V_119 ;
if ( F_137 ( V_113 -> V_4 ) < ( ( V_143 ) ( V_133 + 1 ) << V_144 ) )
F_138 ( V_113 -> V_4 ,
( ( V_143 ) ( V_133 + 1 ) << V_144 ) ) ;
return 0 ;
}
static inline bool F_145 ( struct V_4 * V_4 , int V_152 )
{
return ( F_94 ( V_4 ) ||
( V_152 == V_153 && F_74 ( F_2 ( V_4 ) , V_154 ) ) ||
F_2 ( V_4 ) -> V_30 ) ;
}
int F_146 ( struct V_155 * V_156 , struct V_157 * V_158 )
{
struct V_4 * V_4 = F_147 ( V_156 -> V_159 ) ;
struct V_160 V_161 ;
int V_91 = 0 ;
if ( F_117 ( V_4 , V_162 ) )
return 0 ;
V_161 . V_163 = F_148 ( V_156 -> V_164 ) ;
V_161 . V_165 = F_149 ( V_156 -> V_164 + F_150 ( V_158 ) ) ;
if ( V_161 . V_165 > V_161 . V_163 )
V_161 . V_165 -= V_161 . V_163 ;
else
V_161 . V_165 = 0 ;
V_161 . V_166 = NULL ;
if ( V_156 -> V_167 & V_168 ) {
V_91 = F_151 ( V_4 ) ;
if ( V_91 )
return V_91 ;
return V_160 ( V_4 , & V_161 , 1 ,
F_145 ( V_4 , V_153 ) ?
V_169 :
V_170 ) ;
}
if ( V_156 -> V_164 + F_150 ( V_158 ) > F_152 ( V_4 ) ) {
V_91 = F_151 ( V_4 ) ;
if ( V_91 )
return V_91 ;
}
if ( ! F_153 ( V_4 ) )
return V_160 ( V_4 , & V_161 , 1 , V_169 ) ;
return V_91 ;
}
static inline void F_154 ( struct V_5 * V_6 , int V_171 , bool V_172 )
{
if ( V_171 == V_169 ) {
if ( V_172 )
F_70 ( & V_6 -> V_173 ) ;
else
F_71 ( & V_6 -> V_173 ) ;
} else {
if ( V_172 )
F_155 ( V_6 ) ;
else
F_156 ( V_6 ) ;
}
}
int V_160 ( struct V_4 * V_4 , struct V_160 * V_161 ,
int V_174 , int V_171 )
{
unsigned int V_175 = V_161 -> V_165 ;
struct V_112 V_113 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_176 = V_174 ? V_129 : V_137 ;
T_3 V_177 , V_178 , V_179 ;
int V_91 = 0 , V_180 = 1 ;
unsigned int V_119 , V_181 ;
T_5 V_182 ;
struct V_130 V_131 = { 0 , 0 , 0 } ;
T_1 V_35 ;
if ( ! V_175 )
return 0 ;
V_161 -> V_165 = 0 ;
V_161 -> V_183 = 0 ;
V_177 = ( T_3 ) V_161 -> V_163 ;
V_179 = V_177 + V_175 ;
if ( ! V_174 && F_126 ( V_4 , V_177 , & V_131 ) ) {
V_161 -> V_184 = V_131 . V_132 + V_177 - V_131 . V_133 ;
V_161 -> V_165 = F_157 ( ( T_3 ) V_175 , V_131 . V_133 + V_131 . V_185 - V_177 ) ;
V_161 -> V_183 = V_186 ;
goto V_187;
}
V_188:
if ( V_174 )
F_154 ( V_6 , V_171 , true ) ;
F_129 ( & V_113 , V_4 , NULL , NULL , 0 ) ;
V_91 = F_123 ( & V_113 , V_177 , V_176 ) ;
if ( V_91 ) {
if ( V_171 == V_189 )
V_161 -> V_184 = 0 ;
if ( V_91 == - V_139 ) {
V_91 = 0 ;
if ( V_161 -> V_166 )
* V_161 -> V_166 =
F_158 ( & V_113 , V_177 ) ;
}
goto V_190;
}
V_182 = 0 ;
V_181 = V_119 = V_113 . V_119 ;
V_178 = F_159 ( V_113 . V_116 , V_4 ) ;
V_191:
V_35 = F_120 ( V_113 . V_4 , V_113 . V_116 , V_113 . V_119 ) ;
if ( V_35 == V_99 || V_35 == V_126 ) {
if ( V_174 ) {
if ( F_28 ( F_160 ( V_6 ) ) ) {
V_91 = - V_22 ;
goto V_192;
}
if ( V_171 == V_169 ) {
if ( V_35 == V_126 ) {
V_182 ++ ;
V_181 = V_113 . V_119 ;
}
} else {
V_91 = F_139 ( & V_113 ) ;
if ( ! V_91 )
F_161 ( V_4 , V_193 ) ;
}
if ( V_91 )
goto V_192;
V_161 -> V_183 |= V_194 ;
V_35 = V_113 . V_120 ;
} else {
if ( V_171 == V_189 ) {
V_161 -> V_184 = 0 ;
goto V_192;
}
if ( V_171 == V_195 &&
V_35 == V_126 ) {
if ( V_161 -> V_166 )
* V_161 -> V_166 = V_177 + 1 ;
}
if ( V_171 != V_195 ||
V_35 != V_99 )
goto V_192;
}
}
if ( V_171 == V_169 )
goto V_196;
if ( V_161 -> V_165 == 0 ) {
if ( V_35 == V_99 )
V_161 -> V_183 |= V_197 ;
V_161 -> V_183 |= V_186 ;
V_161 -> V_184 = V_35 ;
V_161 -> V_165 = 1 ;
} else if ( ( V_161 -> V_184 != V_99 &&
V_35 == ( V_161 -> V_184 + V_180 ) ) ||
( V_161 -> V_184 == V_99 && V_35 == V_99 ) ||
V_171 == V_170 ) {
V_180 ++ ;
V_161 -> V_165 ++ ;
} else {
goto V_192;
}
V_196:
V_113 . V_119 ++ ;
V_177 ++ ;
if ( V_171 == V_169 &&
( V_177 == V_179 || V_113 . V_119 == V_178 ) ) {
V_113 . V_119 = V_119 ;
V_91 = F_116 ( & V_113 , V_182 ) ;
if ( V_91 )
goto V_192;
V_161 -> V_165 += V_113 . V_119 - V_119 ;
if ( V_182 && V_113 . V_119 != V_181 + 1 ) {
V_91 = - V_198 ;
goto V_192;
}
V_113 . V_119 = V_178 ;
}
if ( V_177 >= V_179 )
goto V_192;
else if ( V_113 . V_119 < V_178 )
goto V_191;
F_124 ( & V_113 ) ;
if ( V_174 ) {
F_154 ( V_6 , V_171 , false ) ;
F_162 ( V_6 , V_113 . V_121 ) ;
}
goto V_188;
V_192:
F_124 ( & V_113 ) ;
V_190:
if ( V_174 ) {
F_154 ( V_6 , V_171 , false ) ;
F_162 ( V_6 , V_113 . V_121 ) ;
}
V_187:
F_163 ( V_4 , V_161 , V_91 ) ;
return V_91 ;
}
static int F_164 ( struct V_4 * V_4 , T_6 V_199 ,
struct V_200 * V_201 , int V_174 , int V_171 ,
T_3 * V_202 )
{
struct V_160 V_161 ;
int V_91 ;
V_161 . V_163 = V_199 ;
V_161 . V_165 = V_201 -> V_203 >> V_4 -> V_204 ;
V_161 . V_166 = V_202 ;
V_91 = V_160 ( V_4 , & V_161 , V_174 , V_171 ) ;
if ( ! V_91 ) {
F_165 ( V_201 , V_4 -> V_205 , V_161 . V_184 ) ;
V_201 -> V_206 = ( V_201 -> V_206 & ~ V_207 ) | V_161 . V_183 ;
V_201 -> V_203 = ( V_208 ) V_161 . V_165 << V_4 -> V_204 ;
}
return V_91 ;
}
static int F_166 ( struct V_4 * V_4 , T_6 V_199 ,
struct V_200 * V_209 , int V_174 , int V_171 ,
T_3 * V_202 )
{
return F_164 ( V_4 , V_199 , V_209 , V_174 ,
V_171 , V_202 ) ;
}
static int F_167 ( struct V_4 * V_4 , T_6 V_199 ,
struct V_200 * V_209 , int V_174 )
{
return F_164 ( V_4 , V_199 , V_209 , V_174 ,
V_210 , NULL ) ;
}
static int F_168 ( struct V_4 * V_4 , T_6 V_199 ,
struct V_200 * V_209 , int V_174 )
{
if ( F_28 ( V_199 >= F_2 ( V_4 ) -> V_211 ) )
return - V_212 ;
return F_164 ( V_4 , V_199 , V_209 , V_174 ,
V_189 , NULL ) ;
}
static inline T_6 F_169 ( struct V_4 * V_4 , V_143 V_213 )
{
return ( V_213 >> V_4 -> V_204 ) ;
}
static inline V_143 F_170 ( struct V_4 * V_4 , T_6 V_132 )
{
return ( V_132 << V_4 -> V_204 ) ;
}
int F_171 ( struct V_4 * V_4 , struct V_214 * V_215 ,
V_208 V_45 , V_208 V_185 )
{
struct V_200 F_165 ;
T_6 V_31 , V_216 ;
T_3 V_202 ;
V_208 V_217 = 0 , V_218 = 0 , V_219 = 0 ;
T_7 V_220 = 0 ;
int V_72 = 0 ;
V_72 = F_172 ( V_215 , V_221 ) ;
if ( V_72 )
return V_72 ;
if ( F_153 ( V_4 ) ) {
V_72 = F_173 ( V_4 , V_215 , V_45 , V_185 ) ;
if ( V_72 != - V_103 )
return V_72 ;
}
F_174 ( V_4 ) ;
if ( F_169 ( V_4 , V_185 ) == 0 )
V_185 = F_170 ( V_4 , 1 ) ;
V_31 = F_169 ( V_4 , V_45 ) ;
V_216 = F_169 ( V_4 , V_45 + V_185 - 1 ) ;
V_92:
memset ( & F_165 , 0 , sizeof( struct V_200 ) ) ;
F_165 . V_203 = V_185 ;
V_72 = F_166 ( V_4 , V_31 , & F_165 , 0 ,
V_195 , & V_202 ) ;
if ( V_72 )
goto V_187;
if ( ! F_175 ( & F_165 ) ) {
V_31 = V_202 ;
if ( F_170 ( V_4 , V_31 ) < F_170 ( V_4 ,
F_2 ( V_4 ) -> V_211 ) )
goto V_222;
V_220 |= V_223 ;
}
if ( V_219 ) {
if ( F_176 ( V_4 ) )
V_220 |= V_224 ;
V_72 = F_177 ( V_215 , V_217 ,
V_218 , V_219 , V_220 ) ;
}
if ( V_31 > V_216 || V_72 )
goto V_187;
V_217 = F_170 ( V_4 , V_31 ) ;
V_218 = F_170 ( V_4 , F_165 . V_225 ) ;
V_219 = F_165 . V_203 ;
V_220 = 0 ;
if ( F_178 ( & F_165 ) )
V_220 = V_226 ;
V_31 += F_169 ( V_4 , V_219 ) ;
V_222:
F_179 () ;
if ( F_180 ( V_46 ) )
V_72 = - V_227 ;
else
goto V_92;
V_187:
if ( V_72 == 1 )
V_72 = 0 ;
F_181 ( V_4 ) ;
return V_72 ;
}
static int F_182 ( struct V_2 * V_3 ,
struct V_228 * V_229 , struct V_1 * V_1 ,
unsigned V_105 )
{
struct V_10 * V_10 = NULL ;
unsigned V_230 ;
T_6 V_101 = 0 ;
struct V_4 * V_4 = V_3 -> V_7 ;
const unsigned V_231 = V_4 -> V_204 ;
const unsigned V_232 = 1 << V_231 ;
T_6 V_233 ;
T_6 V_234 ;
T_6 V_235 ;
T_6 V_236 ;
struct V_160 V_161 ;
V_161 . V_184 = 0 ;
V_161 . V_163 = 0 ;
V_161 . V_165 = 0 ;
V_161 . V_183 = 0 ;
V_161 . V_166 = NULL ;
for ( V_230 = 0 ; V_105 ; V_230 ++ , V_105 -- ) {
if ( V_229 ) {
V_1 = F_183 ( V_229 , struct V_1 , V_237 ) ;
F_184 ( & V_1 -> V_220 ) ;
F_89 ( & V_1 -> V_237 ) ;
if ( F_185 ( V_1 , V_3 ,
V_1 -> V_68 ,
F_186 ( V_3 ) ) )
goto V_238;
}
V_233 = ( T_6 ) V_1 -> V_68 ;
V_234 = V_233 + V_105 ;
V_235 = ( F_137 ( V_4 ) + V_232 - 1 ) >>
V_231 ;
if ( V_234 > V_235 )
V_234 = V_235 ;
if ( ( V_161 . V_183 & V_186 ) &&
V_233 > V_161 . V_163 &&
V_233 < ( V_161 . V_163 + V_161 . V_165 ) )
goto V_136;
V_161 . V_183 = 0 ;
if ( V_233 < V_234 ) {
V_161 . V_163 = V_233 ;
V_161 . V_165 = V_234 - V_233 ;
if ( V_160 ( V_4 , & V_161 , 0 ,
V_210 ) )
goto V_239;
}
V_136:
if ( ( V_161 . V_183 & V_186 ) ) {
V_236 = V_161 . V_184 + V_233 - V_161 . V_163 ;
F_187 ( V_1 ) ;
if ( ! F_16 ( V_1 ) && ! F_188 ( V_1 ) ) {
F_17 ( V_1 ) ;
goto V_240;
}
} else {
F_130 ( V_1 , 0 , V_57 ) ;
if ( ! F_16 ( V_1 ) )
F_17 ( V_1 ) ;
F_20 ( V_1 ) ;
goto V_238;
}
if ( V_10 && ( V_101 != V_236 - 1 ||
! F_43 ( F_2 ( V_4 ) , V_236 , V_10 ) ) ) {
V_241:
F_46 ( F_2 ( V_4 ) , V_10 , V_48 ) ;
V_10 = NULL ;
}
if ( V_10 == NULL ) {
V_10 = F_93 ( V_4 , V_236 , V_105 ) ;
if ( F_96 ( V_10 ) ) {
V_10 = NULL ;
goto V_239;
}
}
if ( F_56 ( V_10 , V_1 , V_232 , 0 ) < V_232 )
goto V_241;
V_101 = V_236 ;
goto V_238;
V_239:
F_19 ( V_1 ) ;
F_130 ( V_1 , 0 , V_57 ) ;
F_20 ( V_1 ) ;
goto V_238;
V_240:
if ( V_10 ) {
F_46 ( F_2 ( V_4 ) , V_10 , V_48 ) ;
V_10 = NULL ;
}
F_20 ( V_1 ) ;
V_238:
if ( V_229 )
F_189 ( V_1 ) ;
}
F_190 ( V_229 && ! F_86 ( V_229 ) ) ;
if ( V_10 )
F_46 ( F_2 ( V_4 ) , V_10 , V_48 ) ;
return 0 ;
}
static int F_191 ( struct V_242 * V_242 , struct V_1 * V_1 )
{
struct V_4 * V_4 = V_1 -> V_3 -> V_7 ;
int V_72 = - V_103 ;
F_192 ( V_1 , V_48 ) ;
if ( F_153 ( V_4 ) )
V_72 = F_193 ( V_4 , V_1 ) ;
if ( V_72 == - V_103 )
V_72 = F_182 ( V_1 -> V_3 , NULL , V_1 , 1 ) ;
return V_72 ;
}
static int F_194 ( struct V_242 * V_242 ,
struct V_2 * V_3 ,
struct V_228 * V_229 , unsigned V_105 )
{
struct V_4 * V_4 = V_242 -> V_243 -> V_7 ;
struct V_1 * V_1 = F_183 ( V_229 , struct V_1 , V_237 ) ;
F_195 ( V_4 , V_1 , V_105 ) ;
if ( F_153 ( V_4 ) )
return 0 ;
return F_182 ( V_3 , V_229 , NULL , V_105 ) ;
}
static int F_196 ( struct V_61 * V_62 )
{
struct V_4 * V_4 = V_62 -> V_1 -> V_3 -> V_7 ;
T_8 V_244 = V_108 ;
if ( ! F_94 ( V_4 ) )
return 0 ;
F_98 ( V_62 -> V_6 , V_62 -> V_98 ) ;
V_245:
V_62 -> V_87 = F_197 ( V_4 , V_62 -> V_1 ,
V_57 , 0 , V_62 -> V_1 -> V_68 , V_244 ) ;
if ( ! F_96 ( V_62 -> V_87 ) )
return 0 ;
if ( F_103 ( V_62 -> V_87 ) == - V_110 ) {
F_79 ( V_62 -> V_6 ) ;
F_198 ( V_246 , V_247 / 50 ) ;
V_244 |= V_55 ;
goto V_245;
}
return F_103 ( V_62 -> V_87 ) ;
}
static inline bool F_199 ( struct V_61 * V_62 )
{
struct V_4 * V_4 = V_62 -> V_1 -> V_3 -> V_7 ;
if ( F_5 ( V_4 -> V_9 ) || F_200 ( V_4 ) )
return false ;
if ( F_6 ( V_62 -> V_1 ) )
return false ;
if ( F_201 ( V_62 -> V_1 ) )
return false ;
return F_202 ( V_4 , V_62 ) ;
}
static inline bool F_203 ( struct V_61 * V_62 )
{
if ( V_62 -> V_98 == V_99 )
return false ;
if ( V_62 -> V_98 == V_126 )
return false ;
return true ;
}
int F_204 ( struct V_61 * V_62 )
{
struct V_1 * V_1 = V_62 -> V_1 ;
struct V_4 * V_4 = V_1 -> V_3 -> V_7 ;
struct V_112 V_113 ;
struct V_130 V_131 = { 0 , 0 , 0 } ;
bool V_248 = false ;
int V_91 = 0 ;
F_129 ( & V_113 , V_4 , NULL , NULL , 0 ) ;
if ( F_199 ( V_62 ) &&
F_126 ( V_4 , V_1 -> V_68 , & V_131 ) ) {
V_62 -> V_98 = V_131 . V_132 + V_1 -> V_68 - V_131 . V_133 ;
if ( F_203 ( V_62 ) ) {
V_248 = true ;
V_62 -> V_249 = V_250 ;
goto V_136;
}
}
if ( V_62 -> V_249 == V_251 && ! F_205 ( V_62 -> V_6 ) )
return - V_103 ;
V_91 = F_123 ( & V_113 , V_1 -> V_68 , V_137 ) ;
if ( V_91 )
goto V_187;
V_62 -> V_98 = V_113 . V_120 ;
if ( V_62 -> V_98 == V_126 ) {
F_18 ( V_1 ) ;
goto V_252;
}
V_136:
if ( V_248 || ( F_203 ( V_62 ) && F_199 ( V_62 ) ) ) {
V_91 = F_196 ( V_62 ) ;
if ( V_91 )
goto V_252;
F_206 ( V_1 ) ;
F_124 ( & V_113 ) ;
if ( V_62 -> V_249 == V_251 )
F_156 ( V_62 -> V_6 ) ;
V_91 = F_207 ( V_62 ) ;
F_208 ( V_62 -> V_1 , V_253 ) ;
F_161 ( V_4 , V_254 ) ;
return V_91 ;
}
if ( V_62 -> V_249 == V_255 ) {
if ( ! F_205 ( V_62 -> V_6 ) ) {
V_91 = - V_103 ;
goto V_252;
}
V_62 -> V_249 = V_251 ;
}
V_91 = F_196 ( V_62 ) ;
if ( V_91 )
goto V_252;
F_206 ( V_1 ) ;
F_209 ( & V_113 , V_62 ) ;
F_208 ( V_1 , V_256 ) ;
F_161 ( V_4 , V_193 ) ;
if ( V_1 -> V_68 == 0 )
F_161 ( V_4 , V_257 ) ;
V_252:
F_124 ( & V_113 ) ;
V_187:
if ( V_62 -> V_249 == V_251 )
F_156 ( V_62 -> V_6 ) ;
return V_91 ;
}
static int F_210 ( struct V_1 * V_1 , bool * V_100 ,
struct V_258 * V_259 ,
enum V_260 V_261 )
{
struct V_4 * V_4 = V_1 -> V_3 -> V_7 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_143 V_262 = F_137 ( V_4 ) ;
const T_3 V_263 = ( ( unsigned long long ) V_262 )
>> V_144 ;
V_143 V_264 = ( V_1 -> V_68 + 1 ) << V_144 ;
unsigned V_213 = 0 ;
bool V_265 = false ;
int V_91 = 0 ;
struct V_61 V_62 = {
. V_6 = V_6 ,
. type = V_48 ,
. V_63 = V_79 ,
. V_64 = F_211 ( V_259 ) ,
. V_98 = V_126 ,
. V_1 = V_1 ,
. V_87 = NULL ,
. V_100 = false ,
. V_249 = V_255 ,
. V_261 = V_261 ,
} ;
F_212 ( V_1 , V_48 ) ;
if ( F_28 ( F_213 ( V_6 , V_266 ) ) )
goto V_267;
if ( V_1 -> V_68 < V_263 )
goto V_268;
V_213 = V_262 & ( V_57 - 1 ) ;
if ( ( V_1 -> V_68 >= V_263 + 1 ) || ! V_213 )
goto V_187;
F_130 ( V_1 , V_213 , V_57 ) ;
V_268:
if ( F_214 ( V_4 ) )
goto V_187;
if ( F_215 ( V_4 ) && ( ! V_1 -> V_68 ||
( ! V_259 -> V_269 &&
F_216 ( V_6 , V_270 ) ) ) )
goto V_267;
if ( F_28 ( F_160 ( V_6 ) ) ) {
F_31 ( V_1 -> V_3 , - V_22 ) ;
goto V_187;
}
if ( F_5 ( V_4 -> V_9 ) ) {
V_62 . V_249 = V_250 ;
V_91 = F_204 ( & V_62 ) ;
goto V_271;
}
if ( ! V_259 -> V_269 )
V_265 = true ;
else if ( F_217 ( V_6 , 0 , 0 ) )
goto V_267;
else
F_161 ( V_4 , V_272 ) ;
V_91 = - V_103 ;
if ( F_153 ( V_4 ) ) {
V_91 = F_218 ( V_4 , V_1 ) ;
if ( ! V_91 )
goto V_187;
}
if ( V_91 == - V_103 ) {
V_91 = F_204 ( & V_62 ) ;
if ( V_91 == - V_103 ) {
V_62 . V_249 = V_251 ;
V_91 = F_204 ( & V_62 ) ;
}
}
if ( F_219 ( V_4 ) -> V_273 < V_264 )
F_219 ( V_4 ) -> V_273 = V_264 ;
V_271:
if ( V_91 && V_91 != - V_139 )
goto V_267;
V_187:
F_220 ( V_4 ) ;
if ( V_91 )
F_18 ( V_1 ) ;
if ( V_259 -> V_269 ) {
F_78 ( V_6 , V_4 , 0 , V_1 -> V_68 , V_48 ) ;
F_221 ( V_4 , V_272 ) ;
F_222 ( V_4 ) ;
V_100 = NULL ;
}
F_20 ( V_1 ) ;
if ( ! F_5 ( V_4 -> V_9 ) )
F_162 ( V_6 , V_265 ) ;
if ( F_28 ( F_160 ( V_6 ) ) ) {
F_77 ( V_6 , V_48 ) ;
V_100 = NULL ;
}
if ( V_100 )
* V_100 = V_62 . V_100 ;
return 0 ;
V_267:
F_223 ( V_259 , V_1 ) ;
if ( ! V_91 )
return V_274 ;
F_20 ( V_1 ) ;
return V_91 ;
}
static int F_224 ( struct V_1 * V_1 ,
struct V_258 * V_259 )
{
return F_210 ( V_1 , NULL , V_259 , V_275 ) ;
}
static int F_225 ( struct V_2 * V_3 ,
struct V_258 * V_259 ,
enum V_260 V_261 )
{
int V_72 = 0 ;
int V_271 = 0 ;
struct V_276 V_277 ;
int V_105 ;
T_3 V_278 ( V_279 ) ;
T_3 V_68 ;
T_3 V_179 ;
T_3 V_280 ;
T_3 V_281 = V_282 ;
int V_283 ;
int V_284 = 0 ;
int V_285 ;
F_226 ( & V_277 , 0 ) ;
if ( F_227 ( V_3 -> V_7 ) <=
F_228 ( F_229 ( V_3 ) ) -> V_286 )
F_161 ( V_3 -> V_7 , V_272 ) ;
else
F_221 ( V_3 -> V_7 , V_272 ) ;
if ( V_259 -> V_287 ) {
V_279 = V_3 -> V_279 ;
V_68 = V_279 ;
if ( V_68 == 0 )
V_283 = 1 ;
else
V_283 = 0 ;
V_179 = - 1 ;
} else {
V_68 = V_259 -> V_288 >> V_144 ;
V_179 = V_259 -> V_289 >> V_144 ;
if ( V_259 -> V_288 == 0 && V_259 -> V_289 == V_290 )
V_284 = 1 ;
V_283 = 1 ;
}
if ( V_259 -> V_291 == V_292 || V_259 -> V_293 )
V_285 = V_294 ;
else
V_285 = V_295 ;
V_296:
if ( V_259 -> V_291 == V_292 || V_259 -> V_293 )
F_230 ( V_3 , V_68 , V_179 ) ;
V_280 = V_68 ;
while ( ! V_271 && ( V_68 <= V_179 ) ) {
int V_13 ;
V_105 = F_231 ( & V_277 , V_3 , & V_68 , V_285 ,
F_157 ( V_179 - V_68 , ( T_3 ) V_297 - 1 ) + 1 ) ;
if ( V_105 == 0 )
break;
for ( V_13 = 0 ; V_13 < V_105 ; V_13 ++ ) {
struct V_1 * V_1 = V_277 . V_229 [ V_13 ] ;
bool V_100 = false ;
if ( V_1 -> V_68 > V_179 ) {
V_271 = 1 ;
break;
}
V_280 = V_1 -> V_68 ;
V_298:
F_55 ( V_1 ) ;
if ( F_28 ( V_1 -> V_3 != V_3 ) ) {
V_299:
F_20 ( V_1 ) ;
continue;
}
if ( ! F_232 ( V_1 ) ) {
goto V_299;
}
if ( F_233 ( V_1 ) ) {
if ( V_259 -> V_291 != V_300 )
F_112 ( V_1 ,
V_48 , true ) ;
else
goto V_299;
}
F_190 ( F_233 ( V_1 ) ) ;
if ( ! F_234 ( V_1 ) )
goto V_299;
V_72 = F_210 ( V_1 , & V_100 , V_259 , V_261 ) ;
if ( F_28 ( V_72 ) ) {
if ( V_72 == V_274 ) {
F_20 ( V_1 ) ;
V_72 = 0 ;
continue;
} else if ( V_72 == - V_103 ) {
V_72 = 0 ;
if ( V_259 -> V_291 == V_292 ) {
F_179 () ;
F_198 ( V_246 ,
V_247 / 50 ) ;
goto V_298;
}
continue;
}
V_280 = V_1 -> V_68 + 1 ;
V_271 = 1 ;
break;
} else if ( V_100 ) {
V_281 = V_1 -> V_68 ;
}
if ( ( F_235 ( & F_229 ( V_3 ) -> V_301 ) ||
-- V_259 -> V_302 <= 0 ) &&
V_259 -> V_291 == V_300 ) {
V_271 = 1 ;
break;
}
}
F_236 ( & V_277 ) ;
F_179 () ;
}
if ( ! V_283 && ! V_271 ) {
V_283 = 1 ;
V_68 = 0 ;
V_179 = V_279 - 1 ;
goto V_296;
}
if ( V_259 -> V_287 || ( V_284 && V_259 -> V_302 > 0 ) )
V_3 -> V_279 = V_280 ;
if ( V_281 != V_282 )
F_78 ( F_229 ( V_3 ) , V_3 -> V_7 ,
0 , V_281 , V_48 ) ;
return V_72 ;
}
int F_237 ( struct V_2 * V_3 ,
struct V_258 * V_259 ,
enum V_260 V_261 )
{
struct V_4 * V_4 = V_3 -> V_7 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_303 V_47 ;
int V_72 ;
if ( ! V_3 -> V_304 -> V_305 )
return 0 ;
if ( ! F_227 ( V_4 ) && V_259 -> V_291 == V_300 )
return 0 ;
if ( F_28 ( F_213 ( V_6 , V_266 ) ) )
goto V_306;
if ( F_5 ( V_4 -> V_9 ) && V_259 -> V_291 == V_300 &&
F_227 ( V_4 ) < F_238 ( V_6 , V_48 ) &&
F_216 ( V_6 , V_307 ) )
goto V_306;
if ( F_117 ( V_4 , V_308 ) )
goto V_306;
F_239 ( V_3 -> V_7 , V_259 , V_48 ) ;
if ( V_259 -> V_291 == V_292 )
F_240 ( & V_6 -> V_301 ) ;
else if ( F_235 ( & V_6 -> V_301 ) )
goto V_306;
F_241 ( & V_47 ) ;
V_72 = F_225 ( V_3 , V_259 , V_261 ) ;
F_50 ( & V_47 ) ;
if ( V_259 -> V_291 == V_292 )
F_242 ( & V_6 -> V_301 ) ;
F_222 ( V_4 ) ;
return V_72 ;
V_306:
V_259 -> V_309 += F_227 ( V_4 ) ;
F_239 ( V_3 -> V_7 , V_259 , V_48 ) ;
return 0 ;
}
static int F_243 ( struct V_2 * V_3 ,
struct V_258 * V_259 )
{
struct V_4 * V_4 = V_3 -> V_7 ;
return F_237 ( V_3 , V_259 ,
F_219 ( V_4 ) -> V_310 == V_46 ?
V_311 : V_275 ) ;
}
static void F_244 ( struct V_2 * V_3 , V_143 V_312 )
{
struct V_4 * V_4 = V_3 -> V_7 ;
V_143 V_262 = F_137 ( V_4 ) ;
if ( V_312 > V_262 ) {
F_73 ( & F_219 ( V_4 ) -> V_313 ) ;
F_245 ( V_4 , V_262 ) ;
F_246 ( V_4 , V_262 , true ) ;
F_75 ( & F_219 ( V_4 ) -> V_313 ) ;
}
}
static int F_247 ( struct V_5 * V_6 ,
struct V_1 * V_1 , V_143 V_314 , unsigned V_185 ,
T_1 * V_26 , bool * V_121 )
{
struct V_4 * V_4 = V_1 -> V_3 -> V_7 ;
T_3 V_68 = V_1 -> V_68 ;
struct V_112 V_113 ;
struct V_1 * V_141 ;
bool V_315 = false ;
struct V_130 V_131 = { 0 , 0 , 0 } ;
int V_91 = 0 ;
if ( ! F_153 ( V_4 ) && V_185 == V_57 &&
! F_117 ( V_4 , V_162 ) )
return 0 ;
if ( F_153 ( V_4 ) ||
( V_314 & V_316 ) >= F_137 ( V_4 ) ) {
F_154 ( V_6 , V_169 , true ) ;
V_315 = true ;
}
V_317:
V_141 = F_248 ( V_6 , V_4 -> V_8 ) ;
if ( F_96 ( V_141 ) ) {
V_91 = F_103 ( V_141 ) ;
goto V_190;
}
F_129 ( & V_113 , V_4 , V_141 , V_141 , 0 ) ;
if ( F_153 ( V_4 ) ) {
if ( V_314 + V_185 <= F_152 ( V_4 ) ) {
F_249 ( V_1 , V_141 ) ;
F_161 ( V_4 , V_318 ) ;
if ( V_4 -> V_319 )
F_250 ( V_141 ) ;
} else {
V_91 = F_251 ( & V_113 , V_1 ) ;
if ( V_91 )
goto V_187;
if ( V_113 . V_120 == V_126 )
V_91 = F_125 ( & V_113 , V_68 ) ;
}
} else if ( V_315 ) {
V_91 = F_125 ( & V_113 , V_68 ) ;
} else {
if ( F_126 ( V_4 , V_68 , & V_131 ) ) {
V_113 . V_120 = V_131 . V_132 + V_68 - V_131 . V_133 ;
} else {
V_91 = F_123 ( & V_113 , V_68 , V_137 ) ;
if ( V_91 || V_113 . V_120 == V_126 ) {
F_124 ( & V_113 ) ;
F_154 ( V_6 , V_169 ,
true ) ;
V_315 = true ;
goto V_317;
}
}
}
* V_26 = V_113 . V_120 ;
* V_121 = V_113 . V_121 ;
V_187:
F_124 ( & V_113 ) ;
V_190:
if ( V_315 )
F_154 ( V_6 , V_169 , false ) ;
return V_91 ;
}
static int F_252 ( struct V_242 * V_242 , struct V_2 * V_3 ,
V_143 V_314 , unsigned V_185 , unsigned V_220 ,
struct V_1 * * V_320 , void * * V_321 )
{
struct V_4 * V_4 = V_3 -> V_7 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_1 = NULL ;
T_3 V_68 = ( ( unsigned long long ) V_314 ) >> V_144 ;
bool V_322 = false ;
T_1 V_35 = V_126 ;
int V_91 = 0 ;
F_253 ( V_4 , V_314 , V_185 , V_220 ) ;
if ( V_68 != 0 ) {
V_91 = F_151 ( V_4 ) ;
if ( V_91 )
goto V_323;
}
V_140:
V_1 = F_254 ( V_3 , V_68 ,
V_324 | V_325 | V_326 , V_108 ) ;
if ( ! V_1 ) {
V_91 = - V_110 ;
goto V_323;
}
* V_320 = V_1 ;
V_91 = F_247 ( V_6 , V_1 , V_314 , V_185 ,
& V_35 , & V_322 ) ;
if ( V_91 )
goto V_323;
if ( V_322 && F_217 ( V_6 , 0 , 0 ) ) {
F_20 ( V_1 ) ;
F_162 ( V_6 , true ) ;
F_55 ( V_1 ) ;
if ( V_1 -> V_3 != V_3 ) {
F_131 ( V_1 , 1 ) ;
goto V_140;
}
}
F_112 ( V_1 , V_48 , false ) ;
if ( F_94 ( V_4 ) )
F_98 ( V_6 , V_35 ) ;
if ( V_185 == V_57 || F_16 ( V_1 ) )
return 0 ;
if ( ! ( V_314 & ( V_57 - 1 ) ) && ( V_314 + V_185 ) >= F_137 ( V_4 ) ) {
F_130 ( V_1 , V_185 , V_57 ) ;
return 0 ;
}
if ( V_35 == V_99 ) {
F_130 ( V_1 , 0 , V_57 ) ;
F_17 ( V_1 ) ;
} else {
V_91 = F_102 ( V_4 , V_1 , V_35 ) ;
if ( V_91 )
goto V_323;
F_55 ( V_1 ) ;
if ( F_28 ( V_1 -> V_3 != V_3 ) ) {
F_131 ( V_1 , 1 ) ;
goto V_140;
}
if ( F_28 ( ! F_16 ( V_1 ) ) ) {
V_91 = - V_22 ;
goto V_323;
}
}
return 0 ;
V_323:
F_131 ( V_1 , 1 ) ;
F_244 ( V_3 , V_314 + V_185 ) ;
return V_91 ;
}
static int F_255 ( struct V_242 * V_242 ,
struct V_2 * V_3 ,
V_143 V_314 , unsigned V_185 , unsigned V_327 ,
struct V_1 * V_1 , void * V_321 )
{
struct V_4 * V_4 = V_1 -> V_3 -> V_7 ;
F_256 ( V_4 , V_314 , V_185 , V_327 ) ;
if ( ! F_16 ( V_1 ) ) {
if ( F_28 ( V_327 != V_185 ) )
V_327 = 0 ;
else
F_17 ( V_1 ) ;
}
if ( ! V_327 )
goto V_190;
F_113 ( V_1 ) ;
if ( V_314 + V_327 > F_137 ( V_4 ) )
F_138 ( V_4 , V_314 + V_327 ) ;
V_190:
F_131 ( V_1 , 1 ) ;
F_257 ( F_2 ( V_4 ) , V_328 ) ;
return V_327 ;
}
static int F_258 ( struct V_4 * V_4 , struct V_157 * V_329 ,
V_143 V_213 )
{
unsigned V_330 = V_4 -> V_205 -> V_331 - 1 ;
if ( V_213 & V_330 )
return - V_332 ;
if ( F_259 ( V_329 ) & V_330 )
return - V_332 ;
return 0 ;
}
static T_9 F_260 ( struct V_155 * V_156 , struct V_157 * V_329 )
{
struct V_2 * V_3 = V_156 -> V_159 -> V_243 ;
struct V_4 * V_4 = V_3 -> V_7 ;
T_10 V_122 = F_150 ( V_329 ) ;
V_143 V_213 = V_156 -> V_164 ;
int V_152 = F_261 ( V_329 ) ;
int V_91 ;
V_91 = F_258 ( V_4 , V_329 , V_213 ) ;
if ( V_91 )
return V_91 ;
if ( F_145 ( V_4 , V_152 ) )
return 0 ;
F_262 ( V_4 , V_213 , V_122 , V_152 ) ;
F_70 ( & F_219 ( V_4 ) -> V_333 [ V_152 ] ) ;
V_91 = F_263 ( V_156 , V_4 , V_329 , F_167 ) ;
F_71 ( & F_219 ( V_4 ) -> V_333 [ V_152 ] ) ;
if ( V_152 == V_153 ) {
if ( V_91 > 0 ) {
F_264 ( F_2 ( V_4 ) , V_334 ,
V_91 ) ;
F_161 ( V_4 , V_254 ) ;
} else if ( V_91 < 0 ) {
F_244 ( V_3 , V_213 + V_122 ) ;
}
}
F_265 ( V_4 , V_213 , V_122 , V_152 , V_91 ) ;
return V_91 ;
}
void F_266 ( struct V_1 * V_1 , unsigned int V_213 ,
unsigned int V_335 )
{
struct V_4 * V_4 = V_1 -> V_3 -> V_7 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_4 -> V_8 >= F_267 ( V_6 ) &&
( V_213 % V_57 || V_335 != V_57 ) )
return;
if ( F_232 ( V_1 ) ) {
if ( V_4 -> V_8 == F_3 ( V_6 ) ) {
F_32 ( V_6 , V_336 ) ;
} else if ( V_4 -> V_8 == F_4 ( V_6 ) ) {
F_32 ( V_6 , V_337 ) ;
} else {
F_220 ( V_4 ) ;
F_222 ( V_4 ) ;
}
}
if ( F_201 ( V_1 ) )
return F_268 ( V_4 , V_1 ) ;
F_25 ( V_1 , 0 ) ;
F_26 ( V_1 ) ;
}
int F_269 ( struct V_1 * V_1 , T_8 V_338 )
{
if ( F_232 ( V_1 ) )
return 0 ;
if ( F_201 ( V_1 ) )
return 0 ;
F_25 ( V_1 , 0 ) ;
F_26 ( V_1 ) ;
return 1 ;
}
void F_270 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
unsigned long V_220 ;
if ( F_28 ( ! V_3 ) )
return;
F_85 ( & V_3 -> V_339 ) ;
F_271 ( V_1 ) ;
F_272 ( V_1 ) ;
F_87 ( & V_3 -> V_339 ) ;
F_273 ( & V_3 -> V_340 , V_220 ) ;
F_274 ( ! F_16 ( V_1 ) ) ;
F_275 ( V_1 , V_3 ) ;
F_276 ( & V_3 -> V_341 ,
F_277 ( V_1 ) , V_295 ) ;
F_278 ( & V_3 -> V_340 , V_220 ) ;
F_279 ( V_1 ) ;
F_280 ( V_3 -> V_7 , V_342 ) ;
return;
}
static int F_281 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
struct V_4 * V_4 = V_3 -> V_7 ;
F_282 ( V_1 , V_48 ) ;
if ( ! F_16 ( V_1 ) )
F_17 ( V_1 ) ;
if ( F_200 ( V_4 ) && ! F_283 ( V_4 ) ) {
if ( ! F_201 ( V_1 ) ) {
F_284 ( V_4 , V_1 ) ;
return 1 ;
}
return 0 ;
}
if ( ! F_232 ( V_1 ) ) {
F_270 ( V_1 ) ;
F_285 ( V_4 , V_1 ) ;
return 1 ;
}
return 0 ;
}
static T_6 F_286 ( struct V_2 * V_3 , T_6 V_343 )
{
struct V_4 * V_4 = V_3 -> V_7 ;
if ( F_153 ( V_4 ) )
return 0 ;
if ( F_287 ( V_3 , V_295 ) )
F_288 ( V_3 ) ;
return F_289 ( V_3 , V_343 , F_168 ) ;
}
int F_290 ( struct V_2 * V_3 ,
struct V_1 * V_344 , struct V_1 * V_1 , enum V_345 V_176 )
{
int V_346 , V_347 ;
struct V_348 * V_349 = F_219 ( V_3 -> V_7 ) ;
bool V_350 = F_201 ( V_1 ) ;
F_190 ( F_233 ( V_1 ) ) ;
if ( V_350 ) {
if ( V_176 != V_351 )
return - V_352 ;
if ( ! F_291 ( & V_349 -> V_353 ) )
return - V_103 ;
}
V_347 = ( V_350 ? 1 : 0 ) - F_292 ( V_1 ) ;
V_346 = F_293 ( V_3 , V_344 ,
V_1 , NULL , V_176 , V_347 ) ;
if ( V_346 != V_354 ) {
if ( V_350 )
F_294 ( & V_349 -> V_353 ) ;
return V_346 ;
}
if ( V_350 ) {
struct V_355 * V_356 ;
F_295 (cur, &fi->inmem_pages, list)
if ( V_356 -> V_1 == V_1 ) {
V_356 -> V_1 = V_344 ;
break;
}
F_294 ( & V_349 -> V_353 ) ;
F_189 ( V_1 ) ;
F_296 ( V_344 ) ;
}
if ( F_297 ( V_1 ) )
F_54 ( V_344 ) ;
F_25 ( V_344 , F_298 ( V_1 ) ) ;
if ( V_176 != V_357 )
F_299 ( V_344 , V_1 ) ;
else
F_300 ( V_344 , V_1 ) ;
return V_354 ;
}

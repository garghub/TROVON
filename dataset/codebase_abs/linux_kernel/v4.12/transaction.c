void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( & V_2 -> V_3 ) == 0 ) ;
if ( F_4 ( & V_2 -> V_3 ) ) {
F_5 ( ! F_6 ( & V_2 -> V_4 ) ) ;
F_2 ( ! F_7 ( & V_2 -> V_5 . V_6 ) ) ;
if ( V_2 -> V_5 . V_7 )
F_8 ( V_2 -> V_8 ,
L_1 ,
V_2 -> V_5 . V_7 ) ;
while ( ! F_6 ( & V_2 -> V_9 ) ) {
struct V_10 * V_11 ;
V_11 = F_9 ( & V_2 -> V_9 ,
struct V_10 , V_4 ) ;
F_10 ( & V_11 -> V_4 ) ;
F_11 ( V_11 ) ;
}
while ( ! F_6 ( & V_2 -> V_12 ) ) {
struct V_13 * V_14 ;
V_14 = F_9 ( & V_2 -> V_12 ,
struct V_13 ,
V_15 ) ;
F_10 ( & V_14 -> V_15 ) ;
F_12 ( V_14 ) ;
F_13 ( V_14 ) ;
}
F_14 ( V_16 , V_2 ) ;
}
}
static void F_15 ( struct V_17 * V_18 )
{
F_16 ( & V_18 -> V_19 ) ;
F_17 () ;
while ( ! F_7 ( & V_18 -> V_20 ) ) {
struct V_21 * V_22 ;
struct V_23 * V_20 ;
V_22 = F_18 ( & V_18 -> V_20 ) ;
V_20 = F_19 ( V_22 , struct V_23 , V_21 ) ;
F_20 ( & V_20 -> V_21 , & V_18 -> V_20 ) ;
F_21 ( & V_20 -> V_21 ) ;
ASSERT ( ! F_22 ( & V_20 -> V_24 ) ) ;
F_23 ( V_20 ) ;
F_24 ( & V_18 -> V_19 ) ;
}
F_25 ( & V_18 -> V_19 ) ;
}
static T_1 void F_26 ( struct V_1 * V_25 ,
struct V_26 * V_8 )
{
struct V_27 * V_28 , * V_29 ;
F_27 ( & V_8 -> V_30 ) ;
F_28 (root, tmp, &trans->switch_commits,
dirty_list) {
F_10 ( & V_28 -> V_31 ) ;
F_29 ( V_28 -> V_32 ) ;
V_28 -> V_32 = F_30 ( V_28 ) ;
if ( F_31 ( V_28 -> V_33 ) )
F_32 ( V_28 ) ;
F_15 ( & V_28 -> V_34 ) ;
}
F_16 ( & V_25 -> V_35 ) ;
while ( ! F_6 ( & V_25 -> V_36 ) ) {
V_28 = F_9 ( & V_25 -> V_36 ,
struct V_27 , V_37 ) ;
F_10 ( & V_28 -> V_37 ) ;
F_25 ( & V_25 -> V_35 ) ;
F_33 ( V_8 , V_28 ) ;
F_16 ( & V_25 -> V_35 ) ;
}
F_25 ( & V_25 -> V_35 ) ;
F_34 ( & V_8 -> V_30 ) ;
}
static inline void F_35 ( struct V_1 * V_25 ,
unsigned int type )
{
if ( type & V_38 )
F_36 ( & V_25 -> V_39 ) ;
}
static inline void F_37 ( struct V_1 * V_25 ,
unsigned int type )
{
if ( type & V_38 )
F_38 ( & V_25 -> V_39 ) ;
}
static inline void F_39 ( struct V_1 * V_25 ,
unsigned int type )
{
F_40 ( & V_25 -> V_39 , ( ( type & V_38 ) ? 1 : 0 ) ) ;
}
static inline int F_41 ( struct V_1 * V_25 )
{
return F_42 ( & V_25 -> V_39 ) ;
}
static T_1 int F_43 ( struct V_26 * V_8 ,
unsigned int type )
{
struct V_1 * V_40 ;
F_16 ( & V_8 -> V_41 ) ;
V_42:
if ( F_44 ( V_43 , & V_8 -> V_44 ) ) {
F_25 ( & V_8 -> V_41 ) ;
return - V_45 ;
}
V_40 = V_8 -> V_46 ;
if ( V_40 ) {
if ( V_40 -> V_47 ) {
F_25 ( & V_8 -> V_41 ) ;
return V_40 -> V_47 ;
}
if ( V_48 [ V_40 -> V_20 ] & type ) {
F_25 ( & V_8 -> V_41 ) ;
return - V_49 ;
}
F_45 ( & V_40 -> V_3 ) ;
F_36 ( & V_40 -> V_50 ) ;
F_35 ( V_40 , type ) ;
F_25 ( & V_8 -> V_41 ) ;
return 0 ;
}
F_25 ( & V_8 -> V_41 ) ;
if ( type == V_51 )
return - V_52 ;
F_5 ( type == V_53 ) ;
V_40 = F_46 ( V_16 , V_54 ) ;
if ( ! V_40 )
return - V_55 ;
F_16 ( & V_8 -> V_41 ) ;
if ( V_8 -> V_46 ) {
F_14 ( V_16 , V_40 ) ;
goto V_42;
} else if ( F_44 ( V_43 , & V_8 -> V_44 ) ) {
F_25 ( & V_8 -> V_41 ) ;
F_14 ( V_16 , V_40 ) ;
return - V_45 ;
}
V_40 -> V_8 = V_8 ;
F_40 ( & V_40 -> V_50 , 1 ) ;
F_39 ( V_40 , type ) ;
F_47 ( & V_40 -> V_56 ) ;
F_47 ( & V_40 -> V_57 ) ;
F_47 ( & V_40 -> V_58 ) ;
V_40 -> V_20 = V_59 ;
F_48 ( & V_40 -> V_3 , 2 ) ;
F_40 ( & V_40 -> V_60 , 0 ) ;
V_40 -> V_61 = 0 ;
V_40 -> V_62 = F_49 () ;
memset ( & V_40 -> V_5 , 0 , sizeof( V_40 -> V_5 ) ) ;
V_40 -> V_5 . V_6 = V_63 ;
V_40 -> V_5 . V_64 = V_63 ;
F_40 ( & V_40 -> V_5 . V_65 , 0 ) ;
F_17 () ;
if ( ! F_6 ( & V_8 -> V_66 ) )
F_50 ( 1 , V_67 L_2 ) ;
if ( ! F_7 ( & V_8 -> V_68 ) )
F_50 ( 1 , V_67 L_3 ) ;
F_51 ( & V_8 -> V_69 , 0 ) ;
F_52 ( & V_40 -> V_5 . V_19 ) ;
F_53 ( & V_40 -> V_70 ) ;
F_53 ( & V_40 -> V_9 ) ;
F_53 ( & V_40 -> V_71 ) ;
F_53 ( & V_40 -> V_72 ) ;
F_53 ( & V_40 -> V_73 ) ;
F_53 ( & V_40 -> V_36 ) ;
F_54 ( & V_40 -> V_74 ) ;
V_40 -> V_75 = 0 ;
F_52 ( & V_40 -> V_76 ) ;
F_53 ( & V_40 -> V_12 ) ;
F_52 ( & V_40 -> V_35 ) ;
F_55 ( & V_40 -> V_4 , & V_8 -> V_77 ) ;
F_56 ( & V_40 -> V_78 ,
V_8 -> V_79 -> V_80 ) ;
V_8 -> V_81 ++ ;
V_40 -> V_82 = V_8 -> V_81 ;
V_8 -> V_46 = V_40 ;
V_40 -> V_47 = 0 ;
F_25 ( & V_8 -> V_41 ) ;
return 0 ;
}
static int F_57 ( struct V_83 * V_25 ,
struct V_27 * V_28 ,
int V_84 )
{
struct V_26 * V_8 = V_28 -> V_8 ;
if ( ( F_44 ( V_85 , & V_28 -> V_20 ) &&
V_28 -> V_86 < V_25 -> V_82 ) || V_84 ) {
F_2 ( V_28 == V_8 -> V_87 ) ;
F_2 ( V_28 -> V_32 != V_28 -> V_22 ) ;
F_58 ( V_88 , & V_28 -> V_20 ) ;
F_59 () ;
F_16 ( & V_8 -> V_89 ) ;
if ( V_28 -> V_86 == V_25 -> V_82 && ! V_84 ) {
F_25 ( & V_8 -> V_89 ) ;
return 0 ;
}
F_60 ( & V_8 -> V_90 ,
( unsigned long ) V_28 -> V_91 . V_33 ,
V_92 ) ;
F_25 ( & V_8 -> V_89 ) ;
V_28 -> V_86 = V_25 -> V_82 ;
F_61 ( V_25 , V_28 ) ;
F_62 () ;
F_63 ( V_88 , & V_28 -> V_20 ) ;
}
return 0 ;
}
void F_64 ( struct V_83 * V_25 ,
struct V_27 * V_28 )
{
struct V_26 * V_8 = V_28 -> V_8 ;
struct V_1 * V_40 = V_25 -> V_2 ;
F_16 ( & V_40 -> V_35 ) ;
F_55 ( & V_28 -> V_37 , & V_40 -> V_36 ) ;
F_25 ( & V_40 -> V_35 ) ;
F_16 ( & V_8 -> V_89 ) ;
F_65 ( & V_8 -> V_90 ,
( unsigned long ) V_28 -> V_91 . V_33 ,
V_92 ) ;
F_25 ( & V_8 -> V_89 ) ;
}
int F_66 ( struct V_83 * V_25 ,
struct V_27 * V_28 )
{
struct V_26 * V_8 = V_28 -> V_8 ;
if ( ! F_44 ( V_85 , & V_28 -> V_20 ) )
return 0 ;
F_67 () ;
if ( V_28 -> V_86 == V_25 -> V_82 &&
! F_44 ( V_88 , & V_28 -> V_20 ) )
return 0 ;
F_68 ( & V_8 -> V_93 ) ;
F_57 ( V_25 , V_28 , 0 ) ;
F_69 ( & V_8 -> V_93 ) ;
return 0 ;
}
static inline int F_70 ( struct V_1 * V_25 )
{
return ( V_25 -> V_20 >= V_94 &&
V_25 -> V_20 < V_95 &&
! V_25 -> V_47 ) ;
}
static void F_71 ( struct V_26 * V_8 )
{
struct V_1 * V_40 ;
F_16 ( & V_8 -> V_41 ) ;
V_40 = V_8 -> V_46 ;
if ( V_40 && F_70 ( V_40 ) ) {
F_45 ( & V_40 -> V_3 ) ;
F_25 ( & V_8 -> V_41 ) ;
F_72 ( V_8 -> V_96 ,
V_40 -> V_20 >= V_95 ||
V_40 -> V_47 ) ;
F_1 ( V_40 ) ;
} else {
F_25 ( & V_8 -> V_41 ) ;
}
}
static int F_73 ( struct V_26 * V_8 , int type )
{
if ( F_44 ( V_97 , & V_8 -> V_61 ) )
return 0 ;
if ( type == V_98 )
return 1 ;
if ( type == V_99 &&
! F_42 ( & V_8 -> V_100 ) )
return 1 ;
return 0 ;
}
static inline bool F_74 ( struct V_27 * V_28 )
{
struct V_26 * V_8 = V_28 -> V_8 ;
if ( ! V_8 -> V_101 ||
! F_44 ( V_85 , & V_28 -> V_20 ) ||
V_28 -> V_91 . V_33 == V_102 ||
V_28 -> V_103 )
return false ;
return true ;
}
static struct V_83 *
F_75 ( struct V_27 * V_28 , unsigned int V_104 ,
unsigned int type , enum V_105 V_106 ,
bool V_107 )
{
struct V_26 * V_8 = V_28 -> V_8 ;
struct V_83 * V_108 ;
struct V_1 * V_40 ;
T_2 V_109 = 0 ;
T_2 V_110 = 0 ;
bool V_111 = false ;
int V_112 ;
ASSERT ( V_113 -> V_114 != V_115 ) ;
if ( F_44 ( V_43 , & V_8 -> V_44 ) )
return F_76 ( - V_45 ) ;
if ( V_113 -> V_114 ) {
F_2 ( type & V_38 ) ;
V_108 = V_113 -> V_114 ;
V_108 -> V_3 ++ ;
F_2 ( V_108 -> V_3 > 2 ) ;
V_108 -> V_116 = V_108 -> V_117 ;
V_108 -> V_117 = NULL ;
goto V_118;
}
if ( V_104 && V_28 != V_8 -> V_119 ) {
V_110 = V_104 * V_8 -> V_120 ;
V_112 = F_77 ( V_28 , V_110 ,
V_107 ) ;
if ( V_112 )
return F_76 ( V_112 ) ;
V_109 = F_78 ( V_8 , V_104 ) ;
if ( F_74 ( V_28 ) ) {
V_109 += V_8 -> V_120 ;
V_111 = true ;
}
V_112 = F_79 ( V_28 , & V_8 -> V_121 ,
V_109 , V_106 ) ;
if ( V_112 )
goto V_122;
}
V_123:
V_108 = F_80 ( V_124 , V_54 ) ;
if ( ! V_108 ) {
V_112 = - V_55 ;
goto V_125;
}
if ( type & V_126 )
F_81 ( V_8 -> V_127 ) ;
if ( F_73 ( V_8 , type ) )
F_71 ( V_8 ) ;
do {
V_112 = F_43 ( V_8 , type ) ;
if ( V_112 == - V_49 ) {
F_71 ( V_8 ) ;
if ( F_82 ( type == V_51 ) )
V_112 = - V_52 ;
}
} while ( V_112 == - V_49 );
if ( V_112 < 0 )
goto V_128;
V_40 = V_8 -> V_46 ;
V_108 -> V_82 = V_40 -> V_82 ;
V_108 -> V_2 = V_40 ;
V_108 -> V_28 = V_28 ;
V_108 -> V_3 = 1 ;
V_108 -> V_8 = V_28 -> V_8 ;
V_108 -> type = type ;
V_108 -> V_129 = true ;
F_53 ( & V_108 -> V_130 ) ;
F_17 () ;
if ( V_40 -> V_20 >= V_94 &&
F_73 ( V_8 , type ) ) {
V_113 -> V_114 = V_108 ;
F_83 ( V_108 ) ;
goto V_123;
}
if ( V_109 ) {
F_84 ( V_8 , L_4 ,
V_108 -> V_82 , V_109 , 1 ) ;
V_108 -> V_117 = & V_8 -> V_121 ;
V_108 -> V_131 = V_109 ;
V_108 -> V_111 = V_111 ;
}
V_118:
F_66 ( V_108 , V_28 ) ;
if ( ! V_113 -> V_114 && type != V_98 )
V_113 -> V_114 = V_108 ;
return V_108 ;
V_128:
if ( type & V_126 )
F_85 ( V_8 -> V_127 ) ;
F_14 ( V_124 , V_108 ) ;
V_125:
if ( V_109 )
F_86 ( V_8 , & V_8 -> V_121 ,
V_109 ) ;
V_122:
F_87 ( V_28 , V_110 ) ;
return F_76 ( V_112 ) ;
}
struct V_83 * F_88 ( struct V_27 * V_28 ,
unsigned int V_104 )
{
return F_75 ( V_28 , V_104 , V_99 ,
V_132 , true ) ;
}
struct V_83 * F_89 (
struct V_27 * V_28 ,
unsigned int V_104 ,
int V_133 )
{
struct V_26 * V_8 = V_28 -> V_8 ;
struct V_83 * V_25 ;
T_2 V_109 ;
int V_112 ;
V_25 = F_75 ( V_28 , V_104 , V_99 ,
V_132 , false ) ;
if ( ! F_90 ( V_25 ) || F_91 ( V_25 ) != - V_134 )
return V_25 ;
V_25 = F_88 ( V_28 , 0 ) ;
if ( F_90 ( V_25 ) )
return V_25 ;
V_109 = F_78 ( V_8 , V_104 ) ;
V_112 = F_92 ( V_8 , & V_8 -> V_121 ,
V_109 , V_133 ) ;
if ( V_112 ) {
F_93 ( V_25 ) ;
return F_76 ( V_112 ) ;
}
V_25 -> V_117 = & V_8 -> V_121 ;
V_25 -> V_131 = V_109 ;
F_84 ( V_8 , L_4 ,
V_25 -> V_82 , V_109 , 1 ) ;
return V_25 ;
}
struct V_83 * F_94 (
struct V_27 * V_28 ,
unsigned int V_104 )
{
return F_75 ( V_28 , V_104 , V_99 ,
V_135 , true ) ;
}
struct V_83 * F_95 ( struct V_27 * V_28 )
{
return F_75 ( V_28 , 0 , V_136 , V_137 ,
true ) ;
}
struct V_83 * F_96 ( struct V_27 * V_28 )
{
return F_75 ( V_28 , 0 , V_53 ,
V_137 , true ) ;
}
struct V_83 * F_97 ( struct V_27 * V_28 )
{
return F_75 ( V_28 , 0 , V_98 ,
V_137 , true ) ;
}
struct V_83 * F_98 ( struct V_27 * V_28 )
{
return F_75 ( V_28 , 0 , V_51 ,
V_137 , true ) ;
}
struct V_83 *
F_99 ( struct V_27 * V_28 )
{
struct V_83 * V_25 ;
V_25 = F_75 ( V_28 , 0 , V_51 ,
V_137 , true ) ;
if ( F_90 ( V_25 ) && F_91 ( V_25 ) == - V_52 )
F_100 ( V_28 -> V_8 , 0 ) ;
return V_25 ;
}
static T_1 void F_101 ( struct V_1 * V_138 )
{
F_72 ( V_138 -> V_57 , V_138 -> V_20 == V_139 ) ;
}
int F_100 ( struct V_26 * V_8 , T_2 V_82 )
{
struct V_1 * V_40 = NULL , * V_140 ;
int V_112 = 0 ;
if ( V_82 ) {
if ( V_82 <= V_8 -> V_141 )
goto V_142;
F_16 ( & V_8 -> V_41 ) ;
F_102 (t, &fs_info->trans_list, list) {
if ( V_140 -> V_82 == V_82 ) {
V_40 = V_140 ;
F_45 ( & V_40 -> V_3 ) ;
V_112 = 0 ;
break;
}
if ( V_140 -> V_82 > V_82 ) {
V_112 = 0 ;
break;
}
}
F_25 ( & V_8 -> V_41 ) ;
if ( ! V_40 ) {
if ( V_82 > V_8 -> V_141 )
V_112 = - V_143 ;
goto V_142;
}
} else {
F_16 ( & V_8 -> V_41 ) ;
F_103 (t, &fs_info->trans_list,
list) {
if ( V_140 -> V_20 >= V_144 ) {
if ( V_140 -> V_20 == V_139 )
break;
V_40 = V_140 ;
F_45 ( & V_40 -> V_3 ) ;
break;
}
}
F_25 ( & V_8 -> V_41 ) ;
if ( ! V_40 )
goto V_142;
}
F_101 ( V_40 ) ;
F_1 ( V_40 ) ;
V_142:
return V_112 ;
}
void F_104 ( struct V_26 * V_8 )
{
if ( ! F_42 ( & V_8 -> V_100 ) )
F_71 ( V_8 ) ;
}
static int F_105 ( struct V_83 * V_25 )
{
struct V_26 * V_8 = V_25 -> V_8 ;
if ( V_8 -> V_145 . V_146 -> V_147 &&
F_106 ( V_25 , V_8 ) )
return 1 ;
return ! ! F_107 ( & V_8 -> V_145 , 5 ) ;
}
int F_108 ( struct V_83 * V_25 )
{
struct V_1 * V_40 = V_25 -> V_2 ;
struct V_26 * V_8 = V_25 -> V_8 ;
int V_148 ;
int V_149 ;
F_17 () ;
if ( V_40 -> V_20 >= V_94 ||
V_40 -> V_5 . V_150 )
return 1 ;
V_148 = V_25 -> V_151 ;
V_25 -> V_151 = 0 ;
if ( V_148 ) {
V_149 = F_109 ( V_25 , V_8 , V_148 * 2 ) ;
if ( V_149 )
return V_149 ;
}
return F_105 ( V_25 ) ;
}
static int F_110 ( struct V_83 * V_25 ,
int V_152 )
{
struct V_26 * V_153 = V_25 -> V_8 ;
struct V_1 * V_40 = V_25 -> V_2 ;
T_2 V_82 = V_25 -> V_82 ;
unsigned long V_154 = V_25 -> V_151 ;
int V_19 = ( V_25 -> type != V_53 ) ;
int V_149 = 0 ;
int V_155 = 0 ;
if ( V_25 -> V_3 > 1 ) {
V_25 -> V_3 -- ;
V_25 -> V_117 = V_25 -> V_116 ;
return 0 ;
}
F_111 ( V_25 , V_153 ) ;
V_25 -> V_117 = NULL ;
if ( ! F_6 ( & V_25 -> V_130 ) )
F_112 ( V_25 , V_153 ) ;
V_25 -> V_151 = 0 ;
if ( ! V_25 -> V_156 ) {
V_155 =
F_113 ( V_25 , V_153 ) ;
V_154 = F_114 (unsigned long, cur, 32 ) ;
if ( V_155 == 1 &&
( V_25 -> type & ( V_157 | V_158 ) ) )
V_155 = 2 ;
}
F_111 ( V_25 , V_153 ) ;
V_25 -> V_117 = NULL ;
if ( ! F_6 ( & V_25 -> V_130 ) )
F_112 ( V_25 , V_153 ) ;
F_115 ( V_25 ) ;
if ( V_19 && ! F_42 ( & V_153 -> V_100 ) &&
F_105 ( V_25 ) &&
F_116 ( V_40 -> V_20 ) == V_59 ) {
F_16 ( & V_153 -> V_41 ) ;
if ( V_40 -> V_20 == V_59 )
V_40 -> V_20 = V_94 ;
F_25 ( & V_153 -> V_41 ) ;
}
if ( V_19 && F_116 ( V_40 -> V_20 ) == V_94 ) {
if ( V_152 )
return F_83 ( V_25 ) ;
else
F_117 ( V_153 -> V_159 ) ;
}
if ( V_25 -> type & V_126 )
F_85 ( V_153 -> V_127 ) ;
F_2 ( V_40 != V_153 -> V_46 ) ;
F_2 ( F_42 ( & V_40 -> V_50 ) < 1 ) ;
F_38 ( & V_40 -> V_50 ) ;
F_37 ( V_40 , V_25 -> type ) ;
F_17 () ;
if ( F_22 ( & V_40 -> V_56 ) )
F_118 ( & V_40 -> V_56 ) ;
F_1 ( V_40 ) ;
if ( V_113 -> V_114 == V_25 )
V_113 -> V_114 = NULL ;
if ( V_152 )
F_119 ( V_153 ) ;
if ( V_25 -> V_47 ||
F_44 ( V_43 , & V_153 -> V_44 ) ) {
F_117 ( V_153 -> V_159 ) ;
V_149 = - V_160 ;
}
F_14 ( V_124 , V_25 ) ;
if ( V_155 ) {
F_120 ( V_153 , V_154 , V_82 ,
V_155 == 1 ) ;
}
return V_149 ;
}
int F_93 ( struct V_83 * V_25 )
{
return F_110 ( V_25 , 0 ) ;
}
int F_121 ( struct V_83 * V_25 )
{
return F_110 ( V_25 , 1 ) ;
}
int F_122 ( struct V_26 * V_8 ,
struct V_17 * V_78 , int V_161 )
{
int V_149 = 0 ;
int V_162 = 0 ;
struct V_163 * V_164 = V_8 -> V_79 -> V_80 ;
struct V_23 * V_165 = NULL ;
T_2 V_166 = 0 ;
T_2 V_167 ;
while ( ! F_123 ( V_78 , V_166 , & V_166 , & V_167 ,
V_161 , & V_165 ) ) {
bool V_168 = false ;
V_149 = F_124 ( V_78 , V_166 , V_167 ,
V_169 ,
V_161 , & V_165 ) ;
if ( V_149 == - V_55 ) {
V_149 = 0 ;
V_168 = true ;
}
if ( ! V_149 )
V_149 = F_125 ( V_164 , V_166 , V_167 ) ;
if ( V_149 )
V_162 = V_149 ;
else if ( V_168 )
V_162 = F_126 ( V_164 , V_166 , V_167 ) ;
F_23 ( V_165 ) ;
V_165 = NULL ;
F_127 () ;
V_166 = V_167 + 1 ;
}
return V_162 ;
}
static int F_128 ( struct V_26 * V_8 ,
struct V_17 * V_78 )
{
int V_149 = 0 ;
int V_162 = 0 ;
struct V_163 * V_164 = V_8 -> V_79 -> V_80 ;
struct V_23 * V_165 = NULL ;
T_2 V_166 = 0 ;
T_2 V_167 ;
while ( ! F_123 ( V_78 , V_166 , & V_166 , & V_167 ,
V_169 , & V_165 ) ) {
V_149 = F_129 ( V_78 , V_166 , V_167 ,
V_169 ,
0 , 0 , & V_165 , V_54 ) ;
if ( V_149 == - V_55 )
V_149 = 0 ;
if ( ! V_149 )
V_149 = F_126 ( V_164 , V_166 , V_167 ) ;
if ( V_149 )
V_162 = V_149 ;
F_23 ( V_165 ) ;
V_165 = NULL ;
F_127 () ;
V_166 = V_167 + 1 ;
}
if ( V_149 )
V_162 = V_149 ;
return V_162 ;
}
int F_130 ( struct V_26 * V_8 ,
struct V_17 * V_78 )
{
bool V_170 = false ;
int V_149 ;
V_149 = F_128 ( V_8 , V_78 ) ;
if ( F_131 ( V_171 , & V_8 -> V_61 ) )
V_170 = true ;
if ( V_170 && ! V_149 )
V_149 = - V_160 ;
return V_149 ;
}
int F_132 ( struct V_27 * V_172 , int V_161 )
{
struct V_26 * V_8 = V_172 -> V_8 ;
struct V_17 * V_78 = & V_172 -> V_34 ;
bool V_170 = false ;
int V_149 ;
ASSERT ( V_172 -> V_91 . V_33 == V_173 ) ;
V_149 = F_128 ( V_8 , V_78 ) ;
if ( ( V_161 & V_174 ) &&
F_131 ( V_175 , & V_8 -> V_61 ) )
V_170 = true ;
if ( ( V_161 & V_176 ) &&
F_131 ( V_177 , & V_8 -> V_61 ) )
V_170 = true ;
if ( V_170 && ! V_149 )
V_149 = - V_160 ;
return V_149 ;
}
static int F_133 ( struct V_26 * V_8 ,
struct V_17 * V_78 , int V_161 )
{
int V_112 ;
int V_178 ;
struct V_179 V_180 ;
F_134 ( & V_180 ) ;
V_112 = F_122 ( V_8 , V_78 , V_161 ) ;
F_135 ( & V_180 ) ;
V_178 = F_130 ( V_8 , V_78 ) ;
if ( V_112 )
return V_112 ;
if ( V_178 )
return V_178 ;
return 0 ;
}
static int F_136 ( struct V_83 * V_25 ,
struct V_26 * V_8 )
{
int V_112 ;
V_112 = F_133 ( V_8 ,
& V_25 -> V_2 -> V_78 ,
V_174 ) ;
F_15 ( & V_25 -> V_2 -> V_78 ) ;
return V_112 ;
}
static int F_137 ( struct V_83 * V_25 ,
struct V_27 * V_28 )
{
int V_112 ;
T_2 V_181 ;
T_2 V_182 ;
struct V_26 * V_8 = V_28 -> V_8 ;
struct V_27 * V_183 = V_8 -> V_183 ;
V_182 = F_138 ( & V_28 -> V_184 ) ;
while ( 1 ) {
V_181 = F_139 ( & V_28 -> V_184 ) ;
if ( V_181 == V_28 -> V_22 -> V_166 &&
V_182 == F_138 ( & V_28 -> V_184 ) )
break;
F_140 ( & V_28 -> V_184 , V_28 -> V_22 ) ;
V_112 = F_141 ( V_25 , V_183 ,
& V_28 -> V_91 ,
& V_28 -> V_184 ) ;
if ( V_112 )
return V_112 ;
V_182 = F_138 ( & V_28 -> V_184 ) ;
}
return 0 ;
}
static T_1 int F_142 ( struct V_83 * V_25 ,
struct V_26 * V_8 )
{
struct V_185 * V_72 = & V_25 -> V_2 -> V_72 ;
struct V_185 * V_73 = & V_25 -> V_2 -> V_73 ;
struct V_185 * V_186 ;
struct V_187 * V_188 ;
int V_112 ;
V_188 = F_143 ( V_8 -> V_183 ) ;
V_112 = F_144 ( V_25 , V_8 -> V_183 , V_188 , NULL ,
0 , & V_188 ) ;
F_145 ( V_188 ) ;
F_29 ( V_188 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_109 ( V_25 , V_8 , ( unsigned long ) - 1 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_146 ( V_25 , V_8 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_147 ( V_25 , V_8 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_148 ( V_25 , V_8 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_149 ( V_25 , V_8 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_109 ( V_25 , V_8 , ( unsigned long ) - 1 ) ;
if ( V_112 )
return V_112 ;
V_123:
while ( ! F_6 ( & V_8 -> V_189 ) ) {
struct V_27 * V_28 ;
V_186 = V_8 -> V_189 . V_186 ;
F_10 ( V_186 ) ;
V_28 = F_150 ( V_186 , struct V_27 , V_31 ) ;
F_63 ( V_190 , & V_28 -> V_20 ) ;
if ( V_28 != V_8 -> V_87 )
F_55 ( & V_28 -> V_31 ,
& V_25 -> V_2 -> V_71 ) ;
V_112 = F_137 ( V_25 , V_28 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_109 ( V_25 , V_8 , ( unsigned long ) - 1 ) ;
if ( V_112 )
return V_112 ;
}
while ( ! F_6 ( V_72 ) || ! F_6 ( V_73 ) ) {
V_112 = F_151 ( V_25 , V_8 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_109 ( V_25 , V_8 , ( unsigned long ) - 1 ) ;
if ( V_112 )
return V_112 ;
}
if ( ! F_6 ( & V_8 -> V_189 ) )
goto V_123;
F_55 ( & V_8 -> V_87 -> V_31 ,
& V_25 -> V_2 -> V_71 ) ;
F_152 ( V_8 ) ;
return 0 ;
}
void F_153 ( struct V_27 * V_28 )
{
struct V_26 * V_8 = V_28 -> V_8 ;
F_16 ( & V_8 -> V_41 ) ;
if ( F_6 ( & V_28 -> V_37 ) )
F_55 ( & V_28 -> V_37 , & V_8 -> V_191 ) ;
F_25 ( & V_8 -> V_41 ) ;
}
static T_1 int F_154 ( struct V_83 * V_25 ,
struct V_26 * V_8 )
{
struct V_27 * V_192 [ 8 ] ;
int V_193 ;
int V_112 ;
int V_149 = 0 ;
F_16 ( & V_8 -> V_89 ) ;
while ( 1 ) {
V_112 = F_155 ( & V_8 -> V_90 ,
( void * * ) V_192 , 0 ,
F_156 ( V_192 ) ,
V_92 ) ;
if ( V_112 == 0 )
break;
for ( V_193 = 0 ; V_193 < V_112 ; V_193 ++ ) {
struct V_27 * V_28 = V_192 [ V_193 ] ;
F_65 ( & V_8 -> V_90 ,
( unsigned long ) V_28 -> V_91 . V_33 ,
V_92 ) ;
F_25 ( & V_8 -> V_89 ) ;
F_157 ( V_25 , V_28 ) ;
F_158 ( V_25 , V_28 ) ;
F_159 ( V_25 , V_28 ) ;
F_160 ( V_28 , V_25 ) ;
F_63 ( V_194 , & V_28 -> V_20 ) ;
F_161 () ;
if ( V_28 -> V_32 != V_28 -> V_22 ) {
F_55 ( & V_28 -> V_31 ,
& V_25 -> V_2 -> V_71 ) ;
F_140 ( & V_28 -> V_184 ,
V_28 -> V_22 ) ;
}
V_149 = F_141 ( V_25 , V_8 -> V_183 ,
& V_28 -> V_91 ,
& V_28 -> V_184 ) ;
F_16 ( & V_8 -> V_89 ) ;
if ( V_149 )
break;
F_162 ( V_28 ) ;
}
}
F_25 ( & V_8 -> V_89 ) ;
return V_149 ;
}
int F_163 ( struct V_27 * V_28 )
{
struct V_26 * V_153 = V_28 -> V_8 ;
struct V_83 * V_25 ;
int V_112 ;
if ( F_164 ( V_195 , & V_28 -> V_20 ) )
return 0 ;
while ( 1 ) {
V_25 = F_88 ( V_28 , 0 ) ;
if ( F_90 ( V_25 ) )
return F_91 ( V_25 ) ;
V_112 = F_165 ( V_25 , V_28 ) ;
F_93 ( V_25 ) ;
F_166 ( V_153 ) ;
F_127 () ;
if ( F_167 ( V_153 ) || V_112 != - V_196 )
break;
if ( F_168 ( V_153 ) ) {
F_169 ( V_153 , L_5 ) ;
V_112 = - V_196 ;
break;
}
}
F_63 ( V_195 , & V_28 -> V_20 ) ;
return V_112 ;
}
static int F_170 ( struct V_83 * V_25 ,
struct V_27 * V_197 ,
struct V_27 * V_198 ,
struct V_199 * V_200 ,
T_2 V_201 )
{
struct V_26 * V_8 = V_197 -> V_8 ;
int V_112 ;
if ( ! F_44 ( V_202 , & V_8 -> V_61 ) )
return 0 ;
F_68 ( & V_8 -> V_203 ) ;
V_112 = F_154 ( V_25 , V_8 ) ;
if ( V_112 )
goto V_142;
V_112 = F_171 ( V_25 , V_8 ) ;
if ( V_112 < 0 )
goto V_142;
V_112 = F_172 ( V_25 , V_8 ) ;
if ( V_112 < 0 )
goto V_142;
V_112 = V_199 ( V_25 , V_8 ,
V_197 -> V_91 . V_33 , V_201 ,
V_200 ) ;
if ( V_112 < 0 )
goto V_142;
V_112 = F_142 ( V_25 , V_8 ) ;
if ( V_112 )
goto V_142;
F_26 ( V_25 -> V_2 , V_8 ) ;
V_112 = F_136 ( V_25 , V_8 ) ;
if ( V_112 )
F_173 ( V_8 , V_112 ,
L_6 ) ;
V_142:
F_69 ( & V_8 -> V_203 ) ;
if ( ! V_112 )
F_57 ( V_25 , V_198 , 1 ) ;
return V_112 ;
}
static T_1 int F_174 ( struct V_83 * V_25 ,
struct V_26 * V_8 ,
struct V_204 * V_205 )
{
struct V_206 V_207 ;
struct V_208 * V_209 ;
struct V_27 * V_183 = V_8 -> V_183 ;
struct V_27 * V_28 = V_205 -> V_28 ;
struct V_27 * V_210 ;
struct V_211 * V_212 ;
struct V_213 * V_214 ;
struct V_215 * V_216 ;
struct V_217 * V_218 ;
struct V_219 * V_219 ;
struct V_187 * V_29 ;
struct V_187 * V_220 ;
struct V_221 V_222 ;
int V_112 = 0 ;
T_2 V_223 = 0 ;
T_2 V_224 = 0 ;
T_2 V_33 ;
T_2 V_225 ;
T_3 V_226 ;
ASSERT ( V_205 -> V_216 ) ;
V_216 = V_205 -> V_216 ;
ASSERT ( V_205 -> V_184 ) ;
V_209 = V_205 -> V_184 ;
V_205 -> error = F_175 ( V_183 , & V_33 ) ;
if ( V_205 -> error )
goto V_227;
F_176 ( V_25 , V_33 ) ;
F_177 ( V_205 , & V_223 ) ;
if ( V_223 > 0 ) {
V_205 -> error = F_79 ( V_28 ,
& V_205 -> V_117 ,
V_223 ,
V_137 ) ;
if ( V_205 -> error )
goto V_228;
}
V_207 . V_33 = V_33 ;
V_207 . V_229 = ( T_2 ) - 1 ;
V_207 . type = V_230 ;
V_212 = V_25 -> V_117 ;
V_25 -> V_117 = & V_205 -> V_117 ;
V_25 -> V_131 = V_25 -> V_117 -> V_231 ;
F_84 ( V_8 , L_4 ,
V_25 -> V_82 ,
V_25 -> V_131 , 1 ) ;
V_219 = V_205 -> V_219 ;
V_214 = V_205 -> V_232 ;
V_210 = F_178 ( V_214 ) -> V_28 ;
F_57 ( V_25 , V_210 , 0 ) ;
V_222 = F_179 ( V_214 ) ;
V_112 = F_180 ( F_178 ( V_214 ) , & V_224 ) ;
F_5 ( V_112 ) ;
V_218 = F_181 ( NULL , V_210 , V_216 ,
F_182 ( F_178 ( V_214 ) ) ,
V_219 -> V_233 . V_234 ,
V_219 -> V_233 . V_235 , 0 ) ;
if ( V_218 != NULL && ! F_90 ( V_218 ) ) {
V_205 -> error = - V_236 ;
goto V_237;
} else if ( F_90 ( V_218 ) ) {
V_112 = F_91 ( V_218 ) ;
F_183 ( V_25 , V_112 ) ;
goto V_238;
}
F_184 ( V_216 ) ;
V_112 = F_185 ( V_25 , V_8 ) ;
if ( V_112 ) {
F_183 ( V_25 , V_112 ) ;
goto V_238;
}
F_57 ( V_25 , V_28 , 0 ) ;
F_186 ( & V_28 -> V_184 , V_25 -> V_82 ) ;
memcpy ( V_209 , & V_28 -> V_184 , sizeof( * V_209 ) ) ;
F_187 ( V_209 ) ;
V_225 = F_188 ( V_209 ) ;
if ( V_205 -> V_239 )
V_225 |= V_240 ;
else
V_225 &= ~ V_240 ;
F_189 ( V_209 , V_225 ) ;
F_190 ( V_209 ,
V_25 -> V_82 ) ;
F_191 ( & V_226 ) ;
memcpy ( V_209 -> V_241 , V_226 . V_242 , V_243 ) ;
memcpy ( V_209 -> V_244 , V_28 -> V_184 . V_241 ,
V_243 ) ;
if ( ! ( V_225 & V_240 ) ) {
memset ( V_209 -> V_245 , 0 ,
sizeof( V_209 -> V_245 ) ) ;
memset ( & V_209 -> V_246 , 0 , sizeof( V_209 -> V_246 ) ) ;
memset ( & V_209 -> V_247 , 0 , sizeof( V_209 -> V_247 ) ) ;
F_192 ( V_209 , 0 ) ;
F_193 ( V_209 , 0 ) ;
}
F_194 ( & V_209 -> V_248 , V_222 . V_249 ) ;
F_195 ( & V_209 -> V_248 , V_222 . V_250 ) ;
F_196 ( V_209 , V_25 -> V_82 ) ;
V_220 = F_143 ( V_28 ) ;
V_112 = F_144 ( V_25 , V_28 , V_220 , NULL , 0 , & V_220 ) ;
if ( V_112 ) {
F_145 ( V_220 ) ;
F_29 ( V_220 ) ;
F_183 ( V_25 , V_112 ) ;
goto V_238;
}
F_197 ( V_220 ) ;
V_112 = F_198 ( V_25 , V_28 , V_220 , & V_29 , V_33 ) ;
F_145 ( V_220 ) ;
F_29 ( V_220 ) ;
if ( V_112 ) {
F_183 ( V_25 , V_112 ) ;
goto V_238;
}
F_58 ( V_194 , & V_28 -> V_20 ) ;
F_59 () ;
F_140 ( V_209 , V_29 ) ;
V_207 . V_229 = V_25 -> V_82 ;
V_112 = F_199 ( V_25 , V_183 , & V_207 , V_209 ) ;
F_145 ( V_29 ) ;
F_29 ( V_29 ) ;
if ( V_112 ) {
F_183 ( V_25 , V_112 ) ;
goto V_238;
}
V_112 = F_200 ( V_25 , V_8 , V_33 ,
V_210 -> V_91 . V_33 ,
F_182 ( F_178 ( V_214 ) ) , V_224 ,
V_219 -> V_233 . V_234 , V_219 -> V_233 . V_235 ) ;
if ( V_112 ) {
F_183 ( V_25 , V_112 ) ;
goto V_238;
}
V_207 . V_229 = ( T_2 ) - 1 ;
V_205 -> V_251 = F_201 ( V_8 , & V_207 ) ;
if ( F_90 ( V_205 -> V_251 ) ) {
V_112 = F_91 ( V_205 -> V_251 ) ;
F_183 ( V_25 , V_112 ) ;
goto V_238;
}
V_112 = F_202 ( V_25 , V_205 ) ;
if ( V_112 ) {
F_183 ( V_25 , V_112 ) ;
goto V_238;
}
V_112 = F_109 ( V_25 , V_8 , ( unsigned long ) - 1 ) ;
if ( V_112 ) {
F_183 ( V_25 , V_112 ) ;
goto V_238;
}
V_112 = F_170 ( V_25 , V_28 , V_210 ,
V_205 -> V_200 , V_33 ) ;
if ( V_112 < 0 )
goto V_238;
V_112 = F_203 ( V_25 , V_210 ,
V_219 -> V_233 . V_234 , V_219 -> V_233 . V_235 ,
F_178 ( V_214 ) , & V_207 ,
V_252 , V_224 ) ;
F_5 ( V_112 == - V_236 || V_112 == - V_253 ) ;
if ( V_112 ) {
F_183 ( V_25 , V_112 ) ;
goto V_238;
}
F_204 ( F_178 ( V_214 ) , V_214 -> V_254 +
V_219 -> V_233 . V_235 * 2 ) ;
V_214 -> V_255 = V_214 -> V_256 =
F_179 ( V_214 ) ;
V_112 = F_205 ( V_25 , V_210 , V_214 ) ;
if ( V_112 ) {
F_183 ( V_25 , V_112 ) ;
goto V_238;
}
V_112 = F_206 ( V_25 , V_8 , V_226 . V_242 ,
V_257 , V_33 ) ;
if ( V_112 ) {
F_183 ( V_25 , V_112 ) ;
goto V_238;
}
if ( ! F_207 ( V_209 -> V_245 ) ) {
V_112 = F_206 ( V_25 , V_8 ,
V_209 -> V_245 ,
V_258 ,
V_33 ) ;
if ( V_112 && V_112 != - V_236 ) {
F_183 ( V_25 , V_112 ) ;
goto V_238;
}
}
V_112 = F_109 ( V_25 , V_8 , ( unsigned long ) - 1 ) ;
if ( V_112 ) {
F_183 ( V_25 , V_112 ) ;
goto V_238;
}
V_238:
V_205 -> error = V_112 ;
V_237:
V_25 -> V_117 = V_212 ;
V_25 -> V_131 = 0 ;
V_228:
F_208 ( V_25 ) ;
V_227:
F_209 ( V_209 ) ;
V_205 -> V_184 = NULL ;
F_210 ( V_216 ) ;
V_205 -> V_216 = NULL ;
return V_112 ;
}
static T_1 int F_211 ( struct V_83 * V_25 ,
struct V_26 * V_8 )
{
struct V_204 * V_205 , * V_186 ;
struct V_185 * V_259 = & V_25 -> V_2 -> V_70 ;
int V_112 = 0 ;
F_28 (pending, next, head, list) {
F_212 ( & V_205 -> V_4 ) ;
V_112 = F_174 ( V_25 , V_8 , V_205 ) ;
if ( V_112 )
break;
}
return V_112 ;
}
static void F_213 ( struct V_26 * V_8 )
{
struct V_208 * V_184 ;
struct V_260 * V_261 ;
V_261 = V_8 -> V_262 ;
V_184 = & V_8 -> V_119 -> V_184 ;
V_261 -> V_119 = V_184 -> V_263 ;
V_261 -> V_264 = V_184 -> V_81 ;
V_261 -> V_265 = V_184 -> V_266 ;
V_184 = & V_8 -> V_183 -> V_184 ;
V_261 -> V_28 = V_184 -> V_263 ;
V_261 -> V_81 = V_184 -> V_81 ;
V_261 -> V_267 = V_184 -> V_266 ;
if ( F_214 ( V_8 , V_268 ) )
V_261 -> V_269 = V_184 -> V_81 ;
if ( F_44 ( V_270 , & V_8 -> V_61 ) )
V_261 -> V_271 = V_184 -> V_81 ;
}
int F_215 ( struct V_26 * V_153 )
{
struct V_1 * V_25 ;
int V_112 = 0 ;
F_16 ( & V_153 -> V_41 ) ;
V_25 = V_153 -> V_46 ;
if ( V_25 )
V_112 = ( V_25 -> V_20 >= V_144 ) ;
F_25 ( & V_153 -> V_41 ) ;
return V_112 ;
}
int F_216 ( struct V_26 * V_153 )
{
struct V_1 * V_25 ;
int V_112 = 0 ;
F_16 ( & V_153 -> V_41 ) ;
V_25 = V_153 -> V_46 ;
if ( V_25 )
V_112 = F_70 ( V_25 ) ;
F_25 ( & V_153 -> V_41 ) ;
return V_112 ;
}
static void F_217 ( struct V_26 * V_8 ,
struct V_1 * V_25 )
{
F_72 ( V_8 -> V_272 ,
V_25 -> V_20 >= V_144 || V_25 -> V_47 ) ;
}
static void F_218 (
struct V_26 * V_8 ,
struct V_1 * V_25 )
{
F_72 ( V_8 -> V_96 ,
V_25 -> V_20 >= V_95 || V_25 -> V_47 ) ;
}
static void F_219 ( struct V_273 * V_274 )
{
struct V_275 * V_276 =
F_220 ( V_274 , struct V_275 , V_274 ) ;
if ( V_276 -> V_277 -> type & V_126 )
F_221 ( V_276 -> V_277 -> V_8 -> V_127 , V_278 ) ;
V_113 -> V_114 = V_276 -> V_277 ;
F_83 ( V_276 -> V_277 ) ;
F_209 ( V_276 ) ;
}
int F_222 ( struct V_83 * V_25 ,
int V_279 )
{
struct V_26 * V_8 = V_25 -> V_8 ;
struct V_275 * V_276 ;
struct V_1 * V_40 ;
V_276 = F_223 ( sizeof( * V_276 ) , V_54 ) ;
if ( ! V_276 )
return - V_55 ;
F_224 ( & V_276 -> V_274 , F_219 ) ;
V_276 -> V_277 = F_95 ( V_25 -> V_28 ) ;
if ( F_90 ( V_276 -> V_277 ) ) {
int V_149 = F_91 ( V_276 -> V_277 ) ;
F_209 ( V_276 ) ;
return V_149 ;
}
V_40 = V_25 -> V_2 ;
F_45 ( & V_40 -> V_3 ) ;
F_93 ( V_25 ) ;
if ( V_276 -> V_277 -> type & V_126 )
F_225 ( V_8 -> V_127 , V_278 ) ;
F_226 ( & V_276 -> V_274 ) ;
if ( V_279 )
F_218 ( V_8 , V_40 ) ;
else
F_217 ( V_8 , V_40 ) ;
if ( V_113 -> V_114 == V_25 )
V_113 -> V_114 = NULL ;
F_1 ( V_40 ) ;
return 0 ;
}
static void F_227 ( struct V_83 * V_25 ,
struct V_27 * V_28 , int V_149 )
{
struct V_26 * V_8 = V_28 -> V_8 ;
struct V_1 * V_40 = V_25 -> V_2 ;
F_228 ( V_280 ) ;
F_2 ( V_25 -> V_3 > 1 ) ;
F_183 ( V_25 , V_149 ) ;
F_16 ( & V_8 -> V_41 ) ;
F_5 ( F_6 ( & V_40 -> V_4 ) ) ;
F_10 ( & V_40 -> V_4 ) ;
if ( V_40 == V_8 -> V_46 ) {
V_40 -> V_20 = V_281 ;
F_25 ( & V_8 -> V_41 ) ;
F_72 ( V_40 -> V_56 ,
F_42 ( & V_40 -> V_50 ) == 1 ) ;
F_16 ( & V_8 -> V_41 ) ;
}
F_25 ( & V_8 -> V_41 ) ;
F_229 ( V_25 -> V_2 , V_8 ) ;
F_16 ( & V_8 -> V_41 ) ;
if ( V_40 == V_8 -> V_46 )
V_8 -> V_46 = NULL ;
F_25 ( & V_8 -> V_41 ) ;
if ( V_25 -> type & V_126 )
F_85 ( V_8 -> V_127 ) ;
F_1 ( V_40 ) ;
F_1 ( V_40 ) ;
F_230 ( V_28 ) ;
if ( V_113 -> V_114 == V_25 )
V_113 -> V_114 = NULL ;
F_231 ( V_8 ) ;
F_14 ( V_124 , V_25 ) ;
}
static inline int F_232 ( struct V_26 * V_8 )
{
if ( F_214 ( V_8 , V_282 ) )
return F_233 ( V_8 , 1 , - 1 ) ;
return 0 ;
}
static inline void F_234 ( struct V_26 * V_8 )
{
if ( F_214 ( V_8 , V_282 ) )
F_235 ( V_8 , - 1 , 0 , ( T_2 ) - 1 ) ;
}
static inline void
F_236 ( struct V_1 * V_40 )
{
F_72 ( V_40 -> V_58 ,
F_42 ( & V_40 -> V_60 ) == 0 ) ;
}
int F_83 ( struct V_83 * V_25 )
{
struct V_26 * V_8 = V_25 -> V_8 ;
struct V_1 * V_40 = V_25 -> V_2 ;
struct V_1 * V_283 = NULL ;
int V_112 ;
if ( F_82 ( F_116 ( V_40 -> V_47 ) ) ) {
V_112 = V_40 -> V_47 ;
F_93 ( V_25 ) ;
return V_112 ;
}
V_112 = F_109 ( V_25 , V_8 , 0 ) ;
if ( V_112 ) {
F_93 ( V_25 ) ;
return V_112 ;
}
F_111 ( V_25 , V_8 ) ;
V_25 -> V_117 = NULL ;
V_40 = V_25 -> V_2 ;
V_40 -> V_5 . V_150 = 1 ;
F_59 () ;
if ( ! F_6 ( & V_25 -> V_130 ) )
F_112 ( V_25 , V_8 ) ;
V_112 = F_109 ( V_25 , V_8 , 0 ) ;
if ( V_112 ) {
F_93 ( V_25 ) ;
return V_112 ;
}
if ( ! F_44 ( V_284 , & V_40 -> V_61 ) ) {
int V_285 = 0 ;
F_68 ( & V_8 -> V_286 ) ;
if ( ! F_164 ( V_284 ,
& V_40 -> V_61 ) )
V_285 = 1 ;
F_69 ( & V_8 -> V_286 ) ;
if ( V_285 )
V_112 = F_237 ( V_25 , V_8 ) ;
}
if ( V_112 ) {
F_93 ( V_25 ) ;
return V_112 ;
}
F_16 ( & V_8 -> V_41 ) ;
if ( V_40 -> V_20 >= V_144 ) {
F_25 ( & V_8 -> V_41 ) ;
F_45 ( & V_40 -> V_3 ) ;
V_112 = F_93 ( V_25 ) ;
F_101 ( V_40 ) ;
if ( F_82 ( V_40 -> V_47 ) )
V_112 = V_40 -> V_47 ;
F_1 ( V_40 ) ;
return V_112 ;
}
V_40 -> V_20 = V_144 ;
F_118 ( & V_8 -> V_272 ) ;
if ( V_40 -> V_4 . V_287 != & V_8 -> V_77 ) {
V_283 = F_150 ( V_40 -> V_4 . V_287 ,
struct V_1 , V_4 ) ;
if ( V_283 -> V_20 != V_139 ) {
F_45 ( & V_283 -> V_3 ) ;
F_25 ( & V_8 -> V_41 ) ;
F_101 ( V_283 ) ;
V_112 = V_283 -> V_47 ;
F_1 ( V_283 ) ;
if ( V_112 )
goto F_227;
} else {
F_25 ( & V_8 -> V_41 ) ;
}
} else {
F_25 ( & V_8 -> V_41 ) ;
}
F_37 ( V_40 , V_25 -> type ) ;
V_112 = F_232 ( V_8 ) ;
if ( V_112 )
goto F_227;
V_112 = F_185 ( V_25 , V_8 ) ;
if ( V_112 )
goto F_227;
F_72 ( V_40 -> V_56 ,
F_41 ( V_40 ) == 0 ) ;
V_112 = F_185 ( V_25 , V_8 ) ;
if ( V_112 )
goto F_227;
F_234 ( V_8 ) ;
F_236 ( V_40 ) ;
F_238 ( V_8 ) ;
F_16 ( & V_8 -> V_41 ) ;
V_40 -> V_20 = V_281 ;
F_25 ( & V_8 -> V_41 ) ;
F_72 ( V_40 -> V_56 ,
F_42 ( & V_40 -> V_50 ) == 1 ) ;
if ( F_82 ( F_116 ( V_40 -> V_47 ) ) ) {
V_112 = V_40 -> V_47 ;
goto V_288;
}
F_68 ( & V_8 -> V_93 ) ;
V_112 = F_211 ( V_25 , V_8 ) ;
if ( V_112 ) {
F_69 ( & V_8 -> V_93 ) ;
goto V_288;
}
V_112 = F_185 ( V_25 , V_8 ) ;
if ( V_112 ) {
F_69 ( & V_8 -> V_93 ) ;
goto V_288;
}
V_112 = F_109 ( V_25 , V_8 , ( unsigned long ) - 1 ) ;
if ( V_112 ) {
F_69 ( & V_8 -> V_93 ) ;
goto V_288;
}
F_239 ( V_8 ) ;
F_2 ( V_40 != V_25 -> V_2 ) ;
F_68 ( & V_8 -> V_203 ) ;
V_112 = F_154 ( V_25 , V_8 ) ;
if ( V_112 ) {
F_69 ( & V_8 -> V_203 ) ;
F_69 ( & V_8 -> V_93 ) ;
goto V_288;
}
F_240 ( V_8 ) ;
F_241 ( V_25 , V_8 ) ;
V_112 = F_109 ( V_25 , V_8 , ( unsigned long ) - 1 ) ;
if ( V_112 ) {
F_69 ( & V_8 -> V_203 ) ;
F_69 ( & V_8 -> V_93 ) ;
goto V_288;
}
V_112 = F_171 ( V_25 , V_8 ) ;
if ( V_112 ) {
F_69 ( & V_8 -> V_203 ) ;
F_69 ( & V_8 -> V_93 ) ;
goto V_288;
}
V_112 = F_172 ( V_25 , V_8 ) ;
if ( V_112 < 0 ) {
F_69 ( & V_8 -> V_203 ) ;
F_69 ( & V_8 -> V_93 ) ;
goto V_288;
}
V_112 = F_142 ( V_25 , V_8 ) ;
if ( V_112 ) {
F_69 ( & V_8 -> V_203 ) ;
F_69 ( & V_8 -> V_93 ) ;
goto V_288;
}
if ( F_82 ( F_116 ( V_40 -> V_47 ) ) ) {
V_112 = V_40 -> V_47 ;
F_69 ( & V_8 -> V_203 ) ;
F_69 ( & V_8 -> V_93 ) ;
goto V_288;
}
F_242 ( V_8 ) ;
V_40 = V_8 -> V_46 ;
F_140 ( & V_8 -> V_183 -> V_184 ,
V_8 -> V_183 -> V_22 ) ;
F_55 ( & V_8 -> V_183 -> V_31 ,
& V_40 -> V_71 ) ;
F_140 ( & V_8 -> V_119 -> V_184 ,
V_8 -> V_119 -> V_22 ) ;
F_55 ( & V_8 -> V_119 -> V_31 ,
& V_40 -> V_71 ) ;
F_26 ( V_40 , V_8 ) ;
ASSERT ( F_6 ( & V_40 -> V_72 ) ) ;
ASSERT ( F_6 ( & V_40 -> V_73 ) ) ;
F_213 ( V_8 ) ;
F_243 ( V_8 -> V_262 , 0 ) ;
F_244 ( V_8 -> V_262 , 0 ) ;
memcpy ( V_8 -> V_289 , V_8 -> V_262 ,
sizeof( * V_8 -> V_262 ) ) ;
F_245 ( V_8 ) ;
F_246 ( V_8 , V_40 ) ;
F_63 ( V_175 , & V_8 -> V_61 ) ;
F_63 ( V_177 , & V_8 -> V_61 ) ;
F_115 ( V_25 ) ;
F_16 ( & V_8 -> V_41 ) ;
V_40 -> V_20 = V_95 ;
V_8 -> V_46 = NULL ;
F_25 ( & V_8 -> V_41 ) ;
F_69 ( & V_8 -> V_93 ) ;
F_118 ( & V_8 -> V_96 ) ;
V_112 = F_136 ( V_25 , V_8 ) ;
if ( V_112 ) {
F_173 ( V_8 , V_112 ,
L_7 ) ;
F_69 ( & V_8 -> V_203 ) ;
goto V_288;
}
V_112 = F_247 ( V_8 , 0 ) ;
if ( V_112 ) {
F_69 ( & V_8 -> V_203 ) ;
goto V_288;
}
F_69 ( & V_8 -> V_203 ) ;
F_248 ( V_25 , V_8 ) ;
if ( F_44 ( V_290 , & V_40 -> V_61 ) )
F_249 ( V_8 ) ;
V_8 -> V_141 = V_40 -> V_82 ;
V_40 -> V_20 = V_139 ;
F_118 ( & V_40 -> V_57 ) ;
F_16 ( & V_8 -> V_41 ) ;
F_10 ( & V_40 -> V_4 ) ;
F_25 ( & V_8 -> V_41 ) ;
F_1 ( V_40 ) ;
F_1 ( V_40 ) ;
if ( V_25 -> type & V_126 )
F_85 ( V_8 -> V_127 ) ;
F_230 ( V_25 -> V_28 ) ;
F_250 ( V_8 ) ;
if ( V_113 -> V_114 == V_25 )
V_113 -> V_114 = NULL ;
F_14 ( V_124 , V_25 ) ;
if ( V_113 != V_8 -> V_159 &&
V_113 != V_8 -> V_291 && ! V_8 -> V_292 )
F_119 ( V_8 ) ;
return V_112 ;
V_288:
F_250 ( V_8 ) ;
F_227:
F_111 ( V_25 , V_8 ) ;
F_115 ( V_25 ) ;
V_25 -> V_117 = NULL ;
F_251 ( V_8 , L_8 ) ;
if ( V_113 -> V_114 == V_25 )
V_113 -> V_114 = NULL ;
F_227 ( V_25 , V_25 -> V_28 , V_112 ) ;
return V_112 ;
}
int F_252 ( struct V_27 * V_28 )
{
int V_112 ;
struct V_26 * V_8 = V_28 -> V_8 ;
F_16 ( & V_8 -> V_41 ) ;
if ( F_6 ( & V_8 -> V_191 ) ) {
F_25 ( & V_8 -> V_41 ) ;
return 0 ;
}
V_28 = F_9 ( & V_8 -> V_191 ,
struct V_27 , V_37 ) ;
F_10 ( & V_28 -> V_37 ) ;
F_25 ( & V_8 -> V_41 ) ;
F_169 ( V_8 , L_9 , V_28 -> V_33 ) ;
F_253 ( V_28 ) ;
if ( F_254 ( V_28 -> V_22 ) <
V_293 )
V_112 = F_255 ( V_28 , NULL , 0 , 0 ) ;
else
V_112 = F_255 ( V_28 , NULL , 1 , 0 ) ;
return ( V_112 < 0 ) ? 0 : 1 ;
}
void F_240 ( struct V_26 * V_8 )
{
unsigned long V_287 ;
unsigned long V_294 ;
V_287 = F_256 ( & V_8 -> V_295 , 0 ) ;
if ( ! V_287 )
return;
V_294 = 1 << V_296 ;
if ( V_287 & V_294 )
F_257 ( V_8 -> V_297 , V_298 ) ;
V_287 &= ~ V_294 ;
V_294 = 1 << V_299 ;
if ( V_287 & V_294 )
F_258 ( V_8 -> V_297 , V_298 ) ;
V_287 &= ~ V_294 ;
V_294 = 1 << V_300 ;
if ( V_287 & V_294 )
F_169 ( V_8 , L_10 ) ;
V_287 &= ~ V_294 ;
if ( V_287 )
F_251 ( V_8 ,
L_11 , V_287 ) ;
}

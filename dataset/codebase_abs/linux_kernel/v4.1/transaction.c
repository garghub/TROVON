void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( & V_2 -> V_3 ) == 0 ) ;
if ( F_4 ( & V_2 -> V_3 ) ) {
F_5 ( ! F_6 ( & V_2 -> V_4 ) ) ;
F_2 ( ! F_7 ( & V_2 -> V_5 . V_6 ) ) ;
if ( V_2 -> V_5 . V_7 )
F_8 ( V_8 L_1 ,
V_2 -> V_5 . V_7 ) ;
while ( ! F_6 ( & V_2 -> V_9 ) ) {
struct V_10 * V_11 ;
V_11 = F_9 ( & V_2 -> V_9 ,
struct V_10 , V_4 ) ;
F_10 ( & V_11 -> V_4 ) ;
F_11 ( V_11 ) ;
}
F_12 ( V_12 , V_2 ) ;
}
}
static void F_13 ( struct V_13 * V_14 )
{
F_14 ( & V_14 -> V_15 ) ;
while ( ! F_7 ( & V_14 -> V_16 ) ) {
struct V_17 * V_18 ;
struct V_19 * V_16 ;
V_18 = F_15 ( & V_14 -> V_16 ) ;
V_16 = F_16 ( V_18 , struct V_19 , V_17 ) ;
F_17 ( & V_16 -> V_17 , & V_14 -> V_16 ) ;
F_18 ( & V_16 -> V_17 ) ;
ASSERT ( ! F_19 ( & V_16 -> V_20 ) ) ;
F_20 ( V_16 ) ;
F_21 ( & V_14 -> V_15 ) ;
}
F_22 ( & V_14 -> V_15 ) ;
}
static T_1 void F_23 ( struct V_1 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 , * V_26 ;
F_24 ( & V_23 -> V_27 ) ;
F_25 (root, tmp, &trans->switch_commits,
dirty_list) {
F_10 ( & V_25 -> V_28 ) ;
F_26 ( V_25 -> V_29 ) ;
V_25 -> V_29 = F_27 ( V_25 ) ;
if ( F_28 ( V_25 -> V_30 ) )
F_29 ( V_25 ) ;
F_13 ( & V_25 -> V_31 ) ;
}
F_30 ( & V_23 -> V_27 ) ;
}
static inline void F_31 ( struct V_1 * V_21 ,
unsigned int type )
{
if ( type & V_32 )
F_32 ( & V_21 -> V_33 ) ;
}
static inline void F_33 ( struct V_1 * V_21 ,
unsigned int type )
{
if ( type & V_32 )
F_34 ( & V_21 -> V_33 ) ;
}
static inline void F_35 ( struct V_1 * V_21 ,
unsigned int type )
{
F_36 ( & V_21 -> V_33 , ( ( type & V_32 ) ? 1 : 0 ) ) ;
}
static inline int F_37 ( struct V_1 * V_21 )
{
return F_3 ( & V_21 -> V_33 ) ;
}
static T_1 int F_38 ( struct V_24 * V_25 , unsigned int type )
{
struct V_1 * V_34 ;
struct V_22 * V_23 = V_25 -> V_23 ;
F_14 ( & V_23 -> V_35 ) ;
V_36:
if ( F_39 ( V_37 , & V_23 -> V_38 ) ) {
F_22 ( & V_23 -> V_35 ) ;
return - V_39 ;
}
V_34 = V_23 -> V_40 ;
if ( V_34 ) {
if ( V_34 -> V_41 ) {
F_22 ( & V_23 -> V_35 ) ;
return V_34 -> V_41 ;
}
if ( V_42 [ V_34 -> V_16 ] & type ) {
F_22 ( & V_23 -> V_35 ) ;
return - V_43 ;
}
F_32 ( & V_34 -> V_3 ) ;
F_32 ( & V_34 -> V_44 ) ;
F_31 ( V_34 , type ) ;
F_22 ( & V_23 -> V_35 ) ;
return 0 ;
}
F_22 ( & V_23 -> V_35 ) ;
if ( type == V_45 )
return - V_46 ;
F_5 ( type == V_47 ) ;
V_34 = F_40 ( V_12 , V_48 ) ;
if ( ! V_34 )
return - V_49 ;
F_14 ( & V_23 -> V_35 ) ;
if ( V_23 -> V_40 ) {
F_12 ( V_12 , V_34 ) ;
goto V_36;
} else if ( F_39 ( V_37 , & V_23 -> V_38 ) ) {
F_22 ( & V_23 -> V_35 ) ;
F_12 ( V_12 , V_34 ) ;
return - V_39 ;
}
F_36 ( & V_34 -> V_44 , 1 ) ;
F_35 ( V_34 , type ) ;
F_41 ( & V_34 -> V_50 ) ;
F_41 ( & V_34 -> V_51 ) ;
V_34 -> V_16 = V_52 ;
F_36 ( & V_34 -> V_3 , 2 ) ;
V_34 -> V_53 = 0 ;
V_34 -> V_54 = F_42 () ;
V_34 -> V_55 = 0 ;
V_34 -> V_5 . V_6 = V_56 ;
F_36 ( & V_34 -> V_5 . V_57 , 0 ) ;
V_34 -> V_5 . V_58 = 0 ;
V_34 -> V_5 . V_7 = 0 ;
V_34 -> V_5 . V_59 = 0 ;
V_34 -> V_5 . V_60 = 0 ;
V_34 -> V_5 . V_61 = 0 ;
F_43 () ;
if ( ! F_6 ( & V_23 -> V_62 ) )
F_44 ( 1 , V_8 L_2
L_3 ) ;
if ( ! F_7 ( & V_23 -> V_63 ) )
F_44 ( 1 , V_8 L_4
L_3 ) ;
F_45 ( & V_23 -> V_64 , 0 ) ;
F_46 ( & V_34 -> V_5 . V_15 ) ;
F_47 ( & V_34 -> V_65 ) ;
F_47 ( & V_34 -> V_9 ) ;
F_47 ( & V_34 -> V_66 ) ;
F_47 ( & V_34 -> V_67 ) ;
F_47 ( & V_34 -> V_68 ) ;
F_47 ( & V_34 -> V_69 ) ;
F_48 ( & V_34 -> V_70 ) ;
V_34 -> V_71 = 0 ;
F_46 ( & V_34 -> V_72 ) ;
F_49 ( & V_34 -> V_4 , & V_23 -> V_73 ) ;
F_50 ( & V_34 -> V_74 ,
V_23 -> V_75 -> V_76 ) ;
V_23 -> V_77 ++ ;
V_34 -> V_78 = V_23 -> V_77 ;
V_23 -> V_40 = V_34 ;
V_34 -> V_41 = 0 ;
F_22 ( & V_23 -> V_35 ) ;
return 0 ;
}
static int F_51 ( struct V_79 * V_21 ,
struct V_24 * V_25 )
{
if ( F_39 ( V_80 , & V_25 -> V_16 ) &&
V_25 -> V_81 < V_21 -> V_78 ) {
F_2 ( V_25 == V_25 -> V_23 -> V_82 ) ;
F_2 ( V_25 -> V_29 != V_25 -> V_18 ) ;
F_52 ( V_83 , & V_25 -> V_16 ) ;
F_53 () ;
F_14 ( & V_25 -> V_23 -> V_84 ) ;
if ( V_25 -> V_81 == V_21 -> V_78 ) {
F_22 ( & V_25 -> V_23 -> V_84 ) ;
return 0 ;
}
F_54 ( & V_25 -> V_23 -> V_85 ,
( unsigned long ) V_25 -> V_86 . V_30 ,
V_87 ) ;
F_22 ( & V_25 -> V_23 -> V_84 ) ;
V_25 -> V_81 = V_21 -> V_78 ;
F_55 ( V_21 , V_25 ) ;
F_56 () ;
F_57 ( V_83 , & V_25 -> V_16 ) ;
}
return 0 ;
}
int F_58 ( struct V_79 * V_21 ,
struct V_24 * V_25 )
{
if ( ! F_39 ( V_80 , & V_25 -> V_16 ) )
return 0 ;
F_59 () ;
if ( V_25 -> V_81 == V_21 -> V_78 &&
! F_39 ( V_83 , & V_25 -> V_16 ) )
return 0 ;
F_60 ( & V_25 -> V_23 -> V_88 ) ;
F_51 ( V_21 , V_25 ) ;
F_61 ( & V_25 -> V_23 -> V_88 ) ;
return 0 ;
}
static inline int F_62 ( struct V_1 * V_21 )
{
return ( V_21 -> V_16 >= V_89 &&
V_21 -> V_16 < V_90 &&
! V_21 -> V_41 ) ;
}
static void F_63 ( struct V_24 * V_25 )
{
struct V_1 * V_34 ;
F_14 ( & V_25 -> V_23 -> V_35 ) ;
V_34 = V_25 -> V_23 -> V_40 ;
if ( V_34 && F_62 ( V_34 ) ) {
F_32 ( & V_34 -> V_3 ) ;
F_22 ( & V_25 -> V_23 -> V_35 ) ;
F_64 ( V_25 -> V_23 -> V_91 ,
V_34 -> V_16 >= V_90 ||
V_34 -> V_41 ) ;
F_1 ( V_34 ) ;
} else {
F_22 ( & V_25 -> V_23 -> V_35 ) ;
}
}
static int F_65 ( struct V_24 * V_25 , int type )
{
if ( V_25 -> V_23 -> V_92 )
return 0 ;
if ( type == V_93 )
return 1 ;
if ( type == V_94 &&
! F_3 ( & V_25 -> V_23 -> V_95 ) )
return 1 ;
return 0 ;
}
static inline bool F_66 ( struct V_24 * V_25 )
{
if ( ! V_25 -> V_23 -> V_96 ||
! F_39 ( V_80 , & V_25 -> V_16 ) ||
V_25 -> V_86 . V_30 == V_97 ||
V_25 -> V_98 )
return false ;
return true ;
}
static struct V_79 *
F_67 ( struct V_24 * V_25 , T_2 V_99 , unsigned int type ,
enum V_100 V_101 )
{
struct V_79 * V_102 ;
struct V_1 * V_34 ;
T_2 V_103 = 0 ;
T_2 V_104 = 0 ;
bool V_105 = false ;
int V_106 ;
ASSERT ( V_107 -> V_108 != V_109 ) ;
if ( F_39 ( V_37 , & V_25 -> V_23 -> V_38 ) )
return F_68 ( - V_39 ) ;
if ( V_107 -> V_108 ) {
F_2 ( type & V_32 ) ;
V_102 = V_107 -> V_108 ;
V_102 -> V_3 ++ ;
F_2 ( V_102 -> V_3 > 2 ) ;
V_102 -> V_110 = V_102 -> V_111 ;
V_102 -> V_111 = NULL ;
goto V_112;
}
if ( V_99 > 0 && V_25 != V_25 -> V_23 -> V_113 ) {
if ( V_25 -> V_23 -> V_114 &&
F_28 ( V_25 -> V_86 . V_30 ) ) {
V_104 = V_99 * V_25 -> V_115 ;
V_106 = F_69 ( V_25 , V_104 ) ;
if ( V_106 )
return F_68 ( V_106 ) ;
}
V_103 = F_70 ( V_25 , V_99 ) ;
if ( F_66 ( V_25 ) ) {
V_103 += V_25 -> V_115 ;
V_105 = true ;
}
V_106 = F_71 ( V_25 ,
& V_25 -> V_23 -> V_116 ,
V_103 , V_101 ) ;
if ( V_106 )
goto V_117;
}
V_118:
V_102 = F_40 ( V_119 , V_48 ) ;
if ( ! V_102 ) {
V_106 = - V_49 ;
goto V_120;
}
if ( type & V_121 )
F_72 ( V_25 -> V_23 -> V_122 ) ;
if ( F_65 ( V_25 , type ) )
F_63 ( V_25 ) ;
do {
V_106 = F_38 ( V_25 , type ) ;
if ( V_106 == - V_43 ) {
F_63 ( V_25 ) ;
if ( F_73 ( type == V_45 ) )
V_106 = - V_46 ;
}
} while ( V_106 == - V_43 );
if ( V_106 < 0 ) {
F_5 ( type == V_47 ) ;
goto V_123;
}
V_34 = V_25 -> V_23 -> V_40 ;
V_102 -> V_78 = V_34 -> V_78 ;
V_102 -> V_2 = V_34 ;
V_102 -> V_124 = 0 ;
V_102 -> V_125 = 0 ;
V_102 -> V_25 = V_25 ;
V_102 -> V_126 = 0 ;
V_102 -> V_3 = 1 ;
V_102 -> V_127 = 0 ;
V_102 -> V_111 = NULL ;
V_102 -> V_110 = NULL ;
V_102 -> V_41 = 0 ;
V_102 -> V_104 = 0 ;
V_102 -> V_128 . V_129 = 0 ;
V_102 -> type = type ;
V_102 -> V_130 = false ;
V_102 -> V_105 = false ;
V_102 -> V_131 = false ;
F_47 ( & V_102 -> V_132 ) ;
F_47 ( & V_102 -> V_133 ) ;
F_47 ( & V_102 -> V_134 ) ;
F_43 () ;
if ( V_34 -> V_16 >= V_89 &&
F_65 ( V_25 , type ) ) {
V_107 -> V_108 = V_102 ;
F_74 ( V_102 , V_25 ) ;
goto V_118;
}
if ( V_103 ) {
F_75 ( V_25 -> V_23 , L_5 ,
V_102 -> V_78 , V_103 , 1 ) ;
V_102 -> V_111 = & V_25 -> V_23 -> V_116 ;
V_102 -> V_125 = V_103 ;
V_102 -> V_105 = V_105 ;
}
V_102 -> V_104 = V_104 ;
V_112:
F_58 ( V_102 , V_25 ) ;
if ( ! V_107 -> V_108 && type != V_93 )
V_107 -> V_108 = V_102 ;
return V_102 ;
V_123:
if ( type & V_121 )
F_76 ( V_25 -> V_23 -> V_122 ) ;
F_12 ( V_119 , V_102 ) ;
V_120:
if ( V_103 )
F_77 ( V_25 , & V_25 -> V_23 -> V_116 ,
V_103 ) ;
V_117:
if ( V_104 )
F_78 ( V_25 , V_104 ) ;
return F_68 ( V_106 ) ;
}
struct V_79 * F_79 ( struct V_24 * V_25 ,
int V_99 )
{
return F_67 ( V_25 , V_99 , V_94 ,
V_135 ) ;
}
struct V_79 * F_80 (
struct V_24 * V_25 , int V_99 )
{
return F_67 ( V_25 , V_99 , V_94 ,
V_136 ) ;
}
struct V_79 * F_81 ( struct V_24 * V_25 )
{
return F_67 ( V_25 , 0 , V_137 , 0 ) ;
}
struct V_79 * F_82 ( struct V_24 * V_25 )
{
return F_67 ( V_25 , 0 , V_47 , 0 ) ;
}
struct V_79 * F_83 ( struct V_24 * V_25 )
{
return F_67 ( V_25 , 0 , V_93 , 0 ) ;
}
struct V_79 * F_84 ( struct V_24 * V_25 )
{
return F_67 ( V_25 , 0 , V_45 , 0 ) ;
}
struct V_79 *
F_85 ( struct V_24 * V_25 )
{
struct V_79 * V_21 ;
V_21 = F_67 ( V_25 , 0 , V_45 , 0 ) ;
if ( F_86 ( V_21 ) && F_87 ( V_21 ) == - V_46 )
F_88 ( V_25 , 0 ) ;
return V_21 ;
}
static T_1 void F_89 ( struct V_24 * V_25 ,
struct V_1 * V_138 )
{
F_64 ( V_138 -> V_51 , V_138 -> V_16 == V_139 ) ;
}
int F_88 ( struct V_24 * V_25 , T_2 V_78 )
{
struct V_1 * V_34 = NULL , * V_140 ;
int V_106 = 0 ;
if ( V_78 ) {
if ( V_78 <= V_25 -> V_23 -> V_141 )
goto V_142;
F_14 ( & V_25 -> V_23 -> V_35 ) ;
F_90 (t, &root->fs_info->trans_list, list) {
if ( V_140 -> V_78 == V_78 ) {
V_34 = V_140 ;
F_32 ( & V_34 -> V_3 ) ;
V_106 = 0 ;
break;
}
if ( V_140 -> V_78 > V_78 ) {
V_106 = 0 ;
break;
}
}
F_22 ( & V_25 -> V_23 -> V_35 ) ;
if ( ! V_34 ) {
if ( V_78 > V_25 -> V_23 -> V_141 )
V_106 = - V_143 ;
goto V_142;
}
} else {
F_14 ( & V_25 -> V_23 -> V_35 ) ;
F_91 (t, &root->fs_info->trans_list,
list) {
if ( V_140 -> V_16 >= V_144 ) {
if ( V_140 -> V_16 == V_139 )
break;
V_34 = V_140 ;
F_32 ( & V_34 -> V_3 ) ;
break;
}
}
F_22 ( & V_25 -> V_23 -> V_35 ) ;
if ( ! V_34 )
goto V_142;
}
F_89 ( V_25 , V_34 ) ;
F_1 ( V_34 ) ;
V_142:
return V_106 ;
}
void F_92 ( struct V_24 * V_25 )
{
if ( ! F_3 ( & V_25 -> V_23 -> V_95 ) )
F_63 ( V_25 ) ;
}
static int F_93 ( struct V_79 * V_21 ,
struct V_24 * V_25 )
{
if ( V_25 -> V_23 -> V_145 . V_146 -> V_147 &&
F_94 ( V_21 , V_25 ) )
return 1 ;
return ! ! F_95 ( V_25 , & V_25 -> V_23 -> V_145 , 5 ) ;
}
int F_96 ( struct V_79 * V_21 ,
struct V_24 * V_25 )
{
struct V_1 * V_34 = V_21 -> V_2 ;
int V_148 ;
int V_149 ;
F_43 () ;
if ( V_34 -> V_16 >= V_89 ||
V_34 -> V_5 . V_60 )
return 1 ;
V_148 = V_21 -> V_126 ;
V_21 -> V_126 = 0 ;
if ( V_148 ) {
V_149 = F_97 ( V_21 , V_25 , V_148 * 2 ) ;
if ( V_149 )
return V_149 ;
}
return F_93 ( V_21 , V_25 ) ;
}
static int F_98 ( struct V_79 * V_21 ,
struct V_24 * V_25 , int V_150 )
{
struct V_1 * V_34 = V_21 -> V_2 ;
struct V_22 * V_151 = V_25 -> V_23 ;
unsigned long V_152 = V_21 -> V_126 ;
int V_15 = ( V_21 -> type != V_47 ) ;
int V_149 = 0 ;
int V_153 = 0 ;
if ( V_21 -> V_3 > 1 ) {
V_21 -> V_3 -- ;
V_21 -> V_111 = V_21 -> V_110 ;
return 0 ;
}
F_99 ( V_21 , V_25 ) ;
V_21 -> V_111 = NULL ;
if ( ! F_6 ( & V_21 -> V_133 ) )
F_100 ( V_21 , V_25 ) ;
if ( ! F_6 ( & V_21 -> V_134 ) ) {
F_14 ( & V_151 -> V_35 ) ;
F_101 ( & V_21 -> V_134 , & V_34 -> V_67 ) ;
F_22 ( & V_151 -> V_35 ) ;
}
V_21 -> V_126 = 0 ;
if ( ! V_21 -> V_131 ) {
V_153 =
F_102 ( V_21 , V_25 ) ;
V_152 = F_103 (unsigned long, cur, 32 ) ;
if ( V_153 == 1 &&
( V_21 -> type & ( V_154 | V_155 ) ) )
V_153 = 2 ;
}
if ( V_21 -> V_104 ) {
F_78 ( V_21 -> V_25 , V_21 -> V_104 ) ;
V_21 -> V_104 = 0 ;
}
F_99 ( V_21 , V_25 ) ;
V_21 -> V_111 = NULL ;
if ( ! F_6 ( & V_21 -> V_133 ) )
F_100 ( V_21 , V_25 ) ;
if ( V_15 && ! F_3 ( & V_25 -> V_23 -> V_95 ) &&
F_93 ( V_21 , V_25 ) &&
F_104 ( V_34 -> V_16 ) == V_52 ) {
F_14 ( & V_151 -> V_35 ) ;
if ( V_34 -> V_16 == V_52 )
V_34 -> V_16 = V_89 ;
F_22 ( & V_151 -> V_35 ) ;
}
if ( V_15 && F_104 ( V_34 -> V_16 ) == V_89 ) {
if ( V_150 )
return F_74 ( V_21 , V_25 ) ;
else
F_105 ( V_151 -> V_156 ) ;
}
if ( V_21 -> type & V_121 )
F_76 ( V_25 -> V_23 -> V_122 ) ;
F_2 ( V_34 != V_151 -> V_40 ) ;
F_2 ( F_3 ( & V_34 -> V_44 ) < 1 ) ;
F_34 ( & V_34 -> V_44 ) ;
F_33 ( V_34 , V_21 -> type ) ;
F_43 () ;
if ( F_19 ( & V_34 -> V_50 ) )
F_106 ( & V_34 -> V_50 ) ;
F_1 ( V_34 ) ;
if ( V_107 -> V_108 == V_21 )
V_107 -> V_108 = NULL ;
if ( V_150 )
F_107 ( V_25 ) ;
if ( V_21 -> V_41 ||
F_39 ( V_37 , & V_25 -> V_23 -> V_38 ) ) {
F_105 ( V_151 -> V_156 ) ;
V_149 = - V_157 ;
}
F_108 ( V_21 ) ;
F_12 ( V_119 , V_21 ) ;
if ( V_153 ) {
F_109 ( V_25 , V_152 ,
V_153 == 1 ) ;
}
return V_149 ;
}
int F_110 ( struct V_79 * V_21 ,
struct V_24 * V_25 )
{
return F_98 ( V_21 , V_25 , 0 ) ;
}
int F_111 ( struct V_79 * V_21 ,
struct V_24 * V_25 )
{
return F_98 ( V_21 , V_25 , 1 ) ;
}
int F_112 ( struct V_24 * V_25 ,
struct V_13 * V_74 , int V_158 )
{
int V_149 = 0 ;
int V_159 = 0 ;
struct V_160 * V_161 = V_25 -> V_23 -> V_75 -> V_76 ;
struct V_19 * V_162 = NULL ;
T_2 V_163 = 0 ;
T_2 V_164 ;
while ( ! F_113 ( V_74 , V_163 , & V_163 , & V_164 ,
V_158 , & V_162 ) ) {
bool V_165 = false ;
V_149 = F_114 ( V_74 , V_163 , V_164 ,
V_166 ,
V_158 , & V_162 , V_48 ) ;
if ( V_149 == - V_49 ) {
V_149 = 0 ;
V_165 = true ;
}
if ( ! V_149 )
V_149 = F_115 ( V_161 , V_163 , V_164 ) ;
if ( V_149 )
V_159 = V_149 ;
else if ( V_165 )
V_159 = F_116 ( V_161 , V_163 , V_164 ) ;
F_20 ( V_162 ) ;
V_162 = NULL ;
F_117 () ;
V_163 = V_164 + 1 ;
}
return V_159 ;
}
int F_118 ( struct V_24 * V_25 ,
struct V_13 * V_74 , int V_158 )
{
int V_149 = 0 ;
int V_159 = 0 ;
struct V_160 * V_161 = V_25 -> V_23 -> V_75 -> V_76 ;
struct V_19 * V_162 = NULL ;
T_2 V_163 = 0 ;
T_2 V_164 ;
struct V_167 * V_168 = F_119 ( V_25 -> V_23 -> V_75 ) ;
bool V_169 = false ;
while ( ! F_113 ( V_74 , V_163 , & V_163 , & V_164 ,
V_166 , & V_162 ) ) {
V_149 = F_120 ( V_74 , V_163 , V_164 ,
V_166 ,
0 , 0 , & V_162 , V_48 ) ;
if ( V_149 == - V_49 )
V_149 = 0 ;
if ( ! V_149 )
V_149 = F_116 ( V_161 , V_163 , V_164 ) ;
if ( V_149 )
V_159 = V_149 ;
F_20 ( V_162 ) ;
V_162 = NULL ;
F_117 () ;
V_163 = V_164 + 1 ;
}
if ( V_149 )
V_159 = V_149 ;
if ( V_25 -> V_86 . V_30 == V_170 ) {
if ( ( V_158 & V_171 ) &&
F_121 ( V_172 ,
& V_168 -> V_173 ) )
V_169 = true ;
if ( ( V_158 & V_174 ) &&
F_121 ( V_175 ,
& V_168 -> V_173 ) )
V_169 = true ;
} else {
if ( F_121 ( V_176 ,
& V_168 -> V_173 ) )
V_169 = true ;
}
if ( V_169 && ! V_159 )
V_159 = - V_157 ;
return V_159 ;
}
static int F_122 ( struct V_24 * V_25 ,
struct V_13 * V_74 , int V_158 )
{
int V_106 ;
int V_177 ;
struct V_178 V_179 ;
F_123 ( & V_179 ) ;
V_106 = F_112 ( V_25 , V_74 , V_158 ) ;
F_124 ( & V_179 ) ;
V_177 = F_118 ( V_25 , V_74 , V_158 ) ;
if ( V_106 )
return V_106 ;
if ( V_177 )
return V_177 ;
return 0 ;
}
static int F_125 ( struct V_79 * V_21 ,
struct V_24 * V_25 )
{
int V_106 ;
V_106 = F_122 ( V_25 ,
& V_21 -> V_2 -> V_74 ,
V_171 ) ;
F_13 ( & V_21 -> V_2 -> V_74 ) ;
return V_106 ;
}
static int F_126 ( struct V_79 * V_21 ,
struct V_24 * V_25 )
{
int V_106 ;
T_2 V_180 ;
T_2 V_181 ;
struct V_24 * V_182 = V_25 -> V_23 -> V_182 ;
V_181 = F_127 ( & V_25 -> V_183 ) ;
while ( 1 ) {
V_180 = F_128 ( & V_25 -> V_183 ) ;
if ( V_180 == V_25 -> V_18 -> V_163 &&
V_181 == F_127 ( & V_25 -> V_183 ) )
break;
F_129 ( & V_25 -> V_183 , V_25 -> V_18 ) ;
V_106 = F_130 ( V_21 , V_182 ,
& V_25 -> V_86 ,
& V_25 -> V_183 ) ;
if ( V_106 )
return V_106 ;
V_181 = F_127 ( & V_25 -> V_183 ) ;
}
return 0 ;
}
static T_1 int F_131 ( struct V_79 * V_21 ,
struct V_24 * V_25 )
{
struct V_22 * V_23 = V_25 -> V_23 ;
struct V_184 * V_68 = & V_21 -> V_2 -> V_68 ;
struct V_184 * V_69 = & V_21 -> V_2 -> V_69 ;
struct V_184 * V_185 ;
struct V_186 * V_187 ;
int V_106 ;
V_187 = F_132 ( V_23 -> V_182 ) ;
V_106 = F_133 ( V_21 , V_23 -> V_182 , V_187 , NULL ,
0 , & V_187 ) ;
F_134 ( V_187 ) ;
F_26 ( V_187 ) ;
if ( V_106 )
return V_106 ;
V_106 = F_97 ( V_21 , V_25 , ( unsigned long ) - 1 ) ;
if ( V_106 )
return V_106 ;
V_106 = F_135 ( V_21 , V_25 -> V_23 ) ;
if ( V_106 )
return V_106 ;
V_106 = F_136 ( V_21 , V_25 -> V_23 ) ;
if ( V_106 )
return V_106 ;
V_106 = F_137 ( V_21 , V_25 -> V_23 ) ;
if ( V_106 )
return V_106 ;
V_106 = F_138 ( V_21 , V_25 ) ;
if ( V_106 )
return V_106 ;
V_106 = F_97 ( V_21 , V_25 , ( unsigned long ) - 1 ) ;
if ( V_106 )
return V_106 ;
V_118:
while ( ! F_6 ( & V_23 -> V_188 ) ) {
V_185 = V_23 -> V_188 . V_185 ;
F_10 ( V_185 ) ;
V_25 = F_139 ( V_185 , struct V_24 , V_28 ) ;
F_57 ( V_189 , & V_25 -> V_16 ) ;
if ( V_25 != V_23 -> V_82 )
F_49 ( & V_25 -> V_28 ,
& V_21 -> V_2 -> V_66 ) ;
V_106 = F_126 ( V_21 , V_25 ) ;
if ( V_106 )
return V_106 ;
V_106 = F_97 ( V_21 , V_25 , ( unsigned long ) - 1 ) ;
if ( V_106 )
return V_106 ;
}
while ( ! F_6 ( V_68 ) || ! F_6 ( V_69 ) ) {
V_106 = F_140 ( V_21 , V_25 ) ;
if ( V_106 )
return V_106 ;
V_106 = F_97 ( V_21 , V_25 , ( unsigned long ) - 1 ) ;
if ( V_106 )
return V_106 ;
}
if ( ! F_6 ( & V_23 -> V_188 ) )
goto V_118;
F_49 ( & V_23 -> V_82 -> V_28 ,
& V_21 -> V_2 -> V_66 ) ;
F_141 ( V_23 ) ;
return 0 ;
}
void F_142 ( struct V_24 * V_25 )
{
F_14 ( & V_25 -> V_23 -> V_35 ) ;
if ( F_6 ( & V_25 -> V_190 ) )
F_49 ( & V_25 -> V_190 , & V_25 -> V_23 -> V_191 ) ;
F_22 ( & V_25 -> V_23 -> V_35 ) ;
}
static T_1 int F_143 ( struct V_79 * V_21 ,
struct V_24 * V_25 )
{
struct V_24 * V_192 [ 8 ] ;
struct V_22 * V_23 = V_25 -> V_23 ;
int V_193 ;
int V_106 ;
int V_149 = 0 ;
F_14 ( & V_23 -> V_84 ) ;
while ( 1 ) {
V_106 = F_144 ( & V_23 -> V_85 ,
( void * * ) V_192 , 0 ,
F_145 ( V_192 ) ,
V_87 ) ;
if ( V_106 == 0 )
break;
for ( V_193 = 0 ; V_193 < V_106 ; V_193 ++ ) {
V_25 = V_192 [ V_193 ] ;
F_146 ( & V_23 -> V_85 ,
( unsigned long ) V_25 -> V_86 . V_30 ,
V_87 ) ;
F_22 ( & V_23 -> V_84 ) ;
F_147 ( V_21 , V_25 ) ;
F_148 ( V_21 , V_25 ) ;
F_149 ( V_21 , V_25 ) ;
F_150 ( V_25 , V_21 ) ;
F_57 ( V_194 , & V_25 -> V_16 ) ;
F_151 () ;
if ( V_25 -> V_29 != V_25 -> V_18 ) {
F_49 ( & V_25 -> V_28 ,
& V_21 -> V_2 -> V_66 ) ;
F_129 ( & V_25 -> V_183 ,
V_25 -> V_18 ) ;
}
V_149 = F_130 ( V_21 , V_23 -> V_182 ,
& V_25 -> V_86 ,
& V_25 -> V_183 ) ;
F_14 ( & V_23 -> V_84 ) ;
if ( V_149 )
break;
}
}
F_22 ( & V_23 -> V_84 ) ;
return V_149 ;
}
int F_152 ( struct V_24 * V_25 )
{
struct V_22 * V_151 = V_25 -> V_23 ;
struct V_79 * V_21 ;
int V_106 ;
if ( F_153 ( V_195 , & V_25 -> V_16 ) )
return 0 ;
while ( 1 ) {
V_21 = F_79 ( V_25 , 0 ) ;
if ( F_86 ( V_21 ) )
return F_87 ( V_21 ) ;
V_106 = F_154 ( V_21 , V_25 ) ;
F_110 ( V_21 , V_25 ) ;
F_155 ( V_151 -> V_182 ) ;
F_117 () ;
if ( F_156 ( V_25 -> V_23 ) || V_106 != - V_196 )
break;
if ( F_157 ( V_25 -> V_23 ) ) {
F_158 ( L_6 ) ;
V_106 = - V_196 ;
break;
}
}
F_57 ( V_195 , & V_25 -> V_16 ) ;
return V_106 ;
}
static T_1 int F_159 ( struct V_79 * V_21 ,
struct V_22 * V_23 ,
struct V_197 * V_198 )
{
struct V_199 V_200 ;
struct V_201 * V_202 ;
struct V_24 * V_182 = V_23 -> V_182 ;
struct V_24 * V_25 = V_198 -> V_25 ;
struct V_24 * V_203 ;
struct V_204 * V_205 ;
struct V_206 * V_207 ;
struct V_208 * V_209 ;
struct V_210 * V_211 ;
struct V_212 * V_212 ;
struct V_186 * V_26 ;
struct V_186 * V_213 ;
struct V_214 V_215 = V_216 ;
int V_106 = 0 ;
T_2 V_217 = 0 ;
T_2 V_218 = 0 ;
T_2 V_30 ;
T_2 V_219 ;
T_3 V_220 ;
V_209 = F_160 () ;
if ( ! V_209 ) {
V_198 -> error = - V_49 ;
return 0 ;
}
V_202 = F_161 ( sizeof( * V_202 ) , V_48 ) ;
if ( ! V_202 ) {
V_198 -> error = - V_49 ;
goto V_221;
}
V_198 -> error = F_162 ( V_182 , & V_30 ) ;
if ( V_198 -> error )
goto V_222;
F_163 ( V_21 , V_198 , & V_217 ) ;
if ( V_217 > 0 ) {
V_198 -> error = F_71 ( V_25 ,
& V_198 -> V_111 ,
V_217 ,
V_223 ) ;
if ( V_198 -> error )
goto V_222;
}
V_200 . V_30 = V_30 ;
V_200 . V_224 = ( T_2 ) - 1 ;
V_200 . type = V_225 ;
V_205 = V_21 -> V_111 ;
V_21 -> V_111 = & V_198 -> V_111 ;
V_21 -> V_125 = V_21 -> V_111 -> V_226 ;
V_212 = V_198 -> V_212 ;
V_207 = V_198 -> V_227 ;
V_203 = F_119 ( V_207 ) -> V_25 ;
F_51 ( V_21 , V_203 ) ;
V_106 = F_164 ( V_207 , & V_218 ) ;
F_5 ( V_106 ) ;
V_211 = F_165 ( NULL , V_203 , V_209 ,
F_166 ( V_207 ) ,
V_212 -> V_228 . V_229 ,
V_212 -> V_228 . V_230 , 0 ) ;
if ( V_211 != NULL && ! F_86 ( V_211 ) ) {
V_198 -> error = - V_231 ;
goto V_232;
} else if ( F_86 ( V_211 ) ) {
V_106 = F_87 ( V_211 ) ;
F_167 ( V_21 , V_25 , V_106 ) ;
goto V_233;
}
F_168 ( V_209 ) ;
V_106 = F_169 ( V_21 , V_25 ) ;
if ( V_106 ) {
F_167 ( V_21 , V_25 , V_106 ) ;
goto V_233;
}
F_51 ( V_21 , V_25 ) ;
F_170 ( & V_25 -> V_183 , V_21 -> V_78 ) ;
memcpy ( V_202 , & V_25 -> V_183 , sizeof( * V_202 ) ) ;
F_171 ( V_202 ) ;
V_219 = F_172 ( V_202 ) ;
if ( V_198 -> V_234 )
V_219 |= V_235 ;
else
V_219 &= ~ V_235 ;
F_173 ( V_202 , V_219 ) ;
F_174 ( V_202 ,
V_21 -> V_78 ) ;
F_175 ( & V_220 ) ;
memcpy ( V_202 -> V_236 , V_220 . V_237 , V_238 ) ;
memcpy ( V_202 -> V_239 , V_25 -> V_183 . V_236 ,
V_238 ) ;
if ( ! ( V_219 & V_235 ) ) {
memset ( V_202 -> V_240 , 0 ,
sizeof( V_202 -> V_240 ) ) ;
memset ( & V_202 -> V_241 , 0 , sizeof( V_202 -> V_241 ) ) ;
memset ( & V_202 -> V_242 , 0 , sizeof( V_202 -> V_242 ) ) ;
F_176 ( V_202 , 0 ) ;
F_177 ( V_202 , 0 ) ;
}
F_178 ( & V_202 -> V_243 , V_215 . V_244 ) ;
F_179 ( & V_202 -> V_243 , V_215 . V_245 ) ;
F_180 ( V_202 , V_21 -> V_78 ) ;
V_213 = F_132 ( V_25 ) ;
V_106 = F_133 ( V_21 , V_25 , V_213 , NULL , 0 , & V_213 ) ;
if ( V_106 ) {
F_134 ( V_213 ) ;
F_26 ( V_213 ) ;
F_167 ( V_21 , V_25 , V_106 ) ;
goto V_233;
}
F_181 ( V_213 ) ;
V_106 = F_182 ( V_21 , V_25 , V_213 , & V_26 , V_30 ) ;
F_134 ( V_213 ) ;
F_26 ( V_213 ) ;
if ( V_106 ) {
F_167 ( V_21 , V_25 , V_106 ) ;
goto V_233;
}
V_106 = F_97 ( V_21 , V_25 , ( unsigned long ) - 1 ) ;
if ( V_106 ) {
F_167 ( V_21 , V_25 , V_106 ) ;
goto V_233;
}
V_106 = F_183 ( V_21 , V_23 ,
V_25 -> V_86 . V_30 ,
V_30 , V_198 -> V_246 ) ;
if ( V_106 ) {
F_167 ( V_21 , V_25 , V_106 ) ;
goto V_233;
}
F_52 ( V_194 , & V_25 -> V_16 ) ;
F_53 () ;
F_129 ( V_202 , V_26 ) ;
V_200 . V_224 = V_21 -> V_78 ;
V_106 = F_184 ( V_21 , V_182 , & V_200 , V_202 ) ;
F_134 ( V_26 ) ;
F_26 ( V_26 ) ;
if ( V_106 ) {
F_167 ( V_21 , V_25 , V_106 ) ;
goto V_233;
}
V_106 = F_185 ( V_21 , V_182 , V_30 ,
V_203 -> V_86 . V_30 ,
F_166 ( V_207 ) , V_218 ,
V_212 -> V_228 . V_229 , V_212 -> V_228 . V_230 ) ;
if ( V_106 ) {
F_167 ( V_21 , V_25 , V_106 ) ;
goto V_233;
}
V_200 . V_224 = ( T_2 ) - 1 ;
V_198 -> V_247 = F_186 ( V_25 -> V_23 , & V_200 ) ;
if ( F_86 ( V_198 -> V_247 ) ) {
V_106 = F_87 ( V_198 -> V_247 ) ;
F_167 ( V_21 , V_25 , V_106 ) ;
goto V_233;
}
V_106 = F_187 ( V_21 , V_198 ) ;
if ( V_106 ) {
F_167 ( V_21 , V_25 , V_106 ) ;
goto V_233;
}
V_106 = F_97 ( V_21 , V_25 , ( unsigned long ) - 1 ) ;
if ( V_106 ) {
F_167 ( V_21 , V_25 , V_106 ) ;
goto V_233;
}
V_106 = F_188 ( V_21 , V_203 ,
V_212 -> V_228 . V_229 , V_212 -> V_228 . V_230 ,
V_207 , & V_200 ,
V_248 , V_218 ) ;
F_5 ( V_106 == - V_231 || V_106 == - V_249 ) ;
if ( V_106 ) {
F_167 ( V_21 , V_25 , V_106 ) ;
goto V_233;
}
F_189 ( V_207 , V_207 -> V_250 +
V_212 -> V_228 . V_230 * 2 ) ;
V_207 -> V_251 = V_207 -> V_252 = V_216 ;
V_106 = F_190 ( V_21 , V_203 , V_207 ) ;
if ( V_106 ) {
F_167 ( V_21 , V_25 , V_106 ) ;
goto V_233;
}
V_106 = F_191 ( V_21 , V_23 -> V_253 , V_220 . V_237 ,
V_254 , V_30 ) ;
if ( V_106 ) {
F_167 ( V_21 , V_25 , V_106 ) ;
goto V_233;
}
if ( ! F_192 ( V_202 -> V_240 ) ) {
V_106 = F_191 ( V_21 , V_23 -> V_253 ,
V_202 -> V_240 ,
V_255 ,
V_30 ) ;
if ( V_106 && V_106 != - V_231 ) {
F_167 ( V_21 , V_25 , V_106 ) ;
goto V_233;
}
}
V_233:
V_198 -> error = V_106 ;
V_232:
V_21 -> V_111 = V_205 ;
V_21 -> V_125 = 0 ;
V_222:
F_193 ( V_202 ) ;
V_221:
F_194 ( V_209 ) ;
return V_106 ;
}
static T_1 int F_195 ( struct V_79 * V_21 ,
struct V_22 * V_23 )
{
struct V_197 * V_198 , * V_185 ;
struct V_184 * V_256 = & V_21 -> V_2 -> V_65 ;
int V_106 = 0 ;
F_25 (pending, next, head, list) {
F_196 ( & V_198 -> V_4 ) ;
V_106 = F_159 ( V_21 , V_23 , V_198 ) ;
if ( V_106 )
break;
}
return V_106 ;
}
static void F_197 ( struct V_24 * V_25 )
{
struct V_201 * V_183 ;
struct V_257 * V_258 ;
V_258 = V_25 -> V_23 -> V_259 ;
V_183 = & V_25 -> V_23 -> V_113 -> V_183 ;
V_258 -> V_113 = V_183 -> V_260 ;
V_258 -> V_261 = V_183 -> V_77 ;
V_258 -> V_262 = V_183 -> V_263 ;
V_183 = & V_25 -> V_23 -> V_182 -> V_183 ;
V_258 -> V_25 = V_183 -> V_260 ;
V_258 -> V_77 = V_183 -> V_77 ;
V_258 -> V_264 = V_183 -> V_263 ;
if ( F_198 ( V_25 , V_265 ) )
V_258 -> V_266 = V_183 -> V_77 ;
if ( V_25 -> V_23 -> V_267 )
V_258 -> V_268 = V_183 -> V_77 ;
}
int F_199 ( struct V_22 * V_151 )
{
struct V_1 * V_21 ;
int V_106 = 0 ;
F_14 ( & V_151 -> V_35 ) ;
V_21 = V_151 -> V_40 ;
if ( V_21 )
V_106 = ( V_21 -> V_16 >= V_144 ) ;
F_22 ( & V_151 -> V_35 ) ;
return V_106 ;
}
int F_200 ( struct V_22 * V_151 )
{
struct V_1 * V_21 ;
int V_106 = 0 ;
F_14 ( & V_151 -> V_35 ) ;
V_21 = V_151 -> V_40 ;
if ( V_21 )
V_106 = F_62 ( V_21 ) ;
F_22 ( & V_151 -> V_35 ) ;
return V_106 ;
}
static void F_201 ( struct V_24 * V_25 ,
struct V_1 * V_21 )
{
F_64 ( V_25 -> V_23 -> V_269 ,
V_21 -> V_16 >= V_144 ||
V_21 -> V_41 ) ;
}
static void F_202 ( struct V_24 * V_25 ,
struct V_1 * V_21 )
{
F_64 ( V_25 -> V_23 -> V_91 ,
V_21 -> V_16 >= V_90 ||
V_21 -> V_41 ) ;
}
static void F_203 ( struct V_270 * V_271 )
{
struct V_272 * V_273 =
F_204 ( V_271 , struct V_272 , V_271 ) ;
if ( V_273 -> V_274 -> type & V_121 )
F_205 (
& V_273 -> V_25 -> V_23 -> V_122 -> V_275 . V_276 [ V_277 - 1 ] ,
0 , 1 , V_278 ) ;
V_107 -> V_108 = V_273 -> V_274 ;
F_74 ( V_273 -> V_274 , V_273 -> V_25 ) ;
F_193 ( V_273 ) ;
}
int F_206 ( struct V_79 * V_21 ,
struct V_24 * V_25 ,
int V_279 )
{
struct V_272 * V_273 ;
struct V_1 * V_34 ;
V_273 = F_161 ( sizeof( * V_273 ) , V_48 ) ;
if ( ! V_273 )
return - V_49 ;
F_207 ( & V_273 -> V_271 , F_203 ) ;
V_273 -> V_25 = V_25 ;
V_273 -> V_274 = F_81 ( V_25 ) ;
if ( F_86 ( V_273 -> V_274 ) ) {
int V_149 = F_87 ( V_273 -> V_274 ) ;
F_193 ( V_273 ) ;
return V_149 ;
}
V_34 = V_21 -> V_2 ;
F_32 ( & V_34 -> V_3 ) ;
F_110 ( V_21 , V_25 ) ;
if ( V_273 -> V_274 -> type & V_121 )
F_208 (
& V_25 -> V_23 -> V_122 -> V_275 . V_276 [ V_277 - 1 ] ,
1 , V_278 ) ;
F_209 ( & V_273 -> V_271 ) ;
if ( V_279 )
F_202 ( V_25 , V_34 ) ;
else
F_201 ( V_25 , V_34 ) ;
if ( V_107 -> V_108 == V_21 )
V_107 -> V_108 = NULL ;
F_1 ( V_34 ) ;
return 0 ;
}
static void F_210 ( struct V_79 * V_21 ,
struct V_24 * V_25 , int V_149 )
{
struct V_1 * V_34 = V_21 -> V_2 ;
F_211 ( V_280 ) ;
F_2 ( V_21 -> V_3 > 1 ) ;
F_167 ( V_21 , V_25 , V_149 ) ;
F_14 ( & V_25 -> V_23 -> V_35 ) ;
F_5 ( F_6 ( & V_34 -> V_4 ) ) ;
F_10 ( & V_34 -> V_4 ) ;
if ( V_34 == V_25 -> V_23 -> V_40 ) {
V_34 -> V_16 = V_281 ;
F_22 ( & V_25 -> V_23 -> V_35 ) ;
F_64 ( V_34 -> V_50 ,
F_3 ( & V_34 -> V_44 ) == 1 ) ;
F_14 ( & V_25 -> V_23 -> V_35 ) ;
}
F_22 ( & V_25 -> V_23 -> V_35 ) ;
F_212 ( V_21 -> V_2 , V_25 ) ;
F_14 ( & V_25 -> V_23 -> V_35 ) ;
if ( V_34 == V_25 -> V_23 -> V_40 )
V_25 -> V_23 -> V_40 = NULL ;
F_22 ( & V_25 -> V_23 -> V_35 ) ;
if ( V_21 -> type & V_121 )
F_76 ( V_25 -> V_23 -> V_122 ) ;
F_1 ( V_34 ) ;
F_1 ( V_34 ) ;
F_213 ( V_25 ) ;
if ( V_107 -> V_108 == V_21 )
V_107 -> V_108 = NULL ;
F_214 ( V_25 -> V_23 ) ;
F_12 ( V_119 , V_21 ) ;
}
static inline int F_215 ( struct V_22 * V_23 )
{
if ( F_198 ( V_23 -> V_182 , V_282 ) )
return F_216 ( V_23 , 1 , - 1 ) ;
return 0 ;
}
static inline void F_217 ( struct V_22 * V_23 )
{
if ( F_198 ( V_23 -> V_182 , V_282 ) )
F_218 ( V_23 , - 1 ) ;
}
static inline void
F_219 ( struct V_1 * V_34 ,
struct V_22 * V_23 )
{
struct V_283 * V_134 ;
F_14 ( & V_23 -> V_35 ) ;
while ( ! F_6 ( & V_34 -> V_67 ) ) {
V_134 = F_9 ( & V_34 -> V_67 ,
struct V_283 ,
V_73 ) ;
F_10 ( & V_134 -> V_73 ) ;
F_22 ( & V_23 -> V_35 ) ;
F_64 ( V_134 -> V_280 , F_39 ( V_284 ,
& V_134 -> V_285 ) ) ;
F_220 ( V_134 ) ;
F_14 ( & V_23 -> V_35 ) ;
}
F_22 ( & V_23 -> V_35 ) ;
}
int F_74 ( struct V_79 * V_21 ,
struct V_24 * V_25 )
{
struct V_1 * V_34 = V_21 -> V_2 ;
struct V_1 * V_286 = NULL ;
struct V_167 * V_168 = F_119 ( V_25 -> V_23 -> V_75 ) ;
int V_106 ;
if ( F_73 ( F_104 ( V_34 -> V_41 ) ) ) {
V_106 = V_34 -> V_41 ;
F_110 ( V_21 , V_25 ) ;
return V_106 ;
}
V_106 = F_97 ( V_21 , V_25 , 0 ) ;
if ( V_106 ) {
F_110 ( V_21 , V_25 ) ;
return V_106 ;
}
F_99 ( V_21 , V_25 ) ;
V_21 -> V_111 = NULL ;
if ( V_21 -> V_104 ) {
F_78 ( V_25 , V_21 -> V_104 ) ;
V_21 -> V_104 = 0 ;
}
V_34 = V_21 -> V_2 ;
V_34 -> V_5 . V_60 = 1 ;
F_53 () ;
if ( ! F_6 ( & V_21 -> V_133 ) )
F_100 ( V_21 , V_25 ) ;
V_106 = F_97 ( V_21 , V_25 , 0 ) ;
if ( V_106 ) {
F_110 ( V_21 , V_25 ) ;
return V_106 ;
}
if ( ! V_34 -> V_55 ) {
int V_287 = 0 ;
F_60 ( & V_25 -> V_23 -> V_288 ) ;
if ( ! V_34 -> V_55 ) {
V_287 = 1 ;
V_34 -> V_55 = 1 ;
}
F_61 ( & V_25 -> V_23 -> V_288 ) ;
if ( V_287 )
V_106 = F_221 ( V_21 , V_25 ) ;
}
if ( V_106 ) {
F_110 ( V_21 , V_25 ) ;
return V_106 ;
}
F_14 ( & V_25 -> V_23 -> V_35 ) ;
F_101 ( & V_21 -> V_134 , & V_34 -> V_67 ) ;
if ( V_34 -> V_16 >= V_144 ) {
F_22 ( & V_25 -> V_23 -> V_35 ) ;
F_32 ( & V_34 -> V_3 ) ;
V_106 = F_110 ( V_21 , V_25 ) ;
F_89 ( V_25 , V_34 ) ;
if ( F_73 ( V_34 -> V_41 ) )
V_106 = V_34 -> V_41 ;
F_1 ( V_34 ) ;
return V_106 ;
}
V_34 -> V_16 = V_144 ;
F_106 ( & V_25 -> V_23 -> V_269 ) ;
if ( V_34 -> V_4 . V_289 != & V_25 -> V_23 -> V_73 ) {
V_286 = F_139 ( V_34 -> V_4 . V_289 ,
struct V_1 , V_4 ) ;
if ( V_286 -> V_16 != V_139 ) {
F_32 ( & V_286 -> V_3 ) ;
F_22 ( & V_25 -> V_23 -> V_35 ) ;
F_89 ( V_25 , V_286 ) ;
F_1 ( V_286 ) ;
} else {
F_22 ( & V_25 -> V_23 -> V_35 ) ;
}
} else {
F_22 ( & V_25 -> V_23 -> V_35 ) ;
}
F_33 ( V_34 , V_21 -> type ) ;
V_106 = F_215 ( V_25 -> V_23 ) ;
if ( V_106 )
goto F_210;
V_106 = F_169 ( V_21 , V_25 ) ;
if ( V_106 )
goto F_210;
F_64 ( V_34 -> V_50 ,
F_37 ( V_34 ) == 0 ) ;
V_106 = F_169 ( V_21 , V_25 ) ;
if ( V_106 )
goto F_210;
F_217 ( V_25 -> V_23 ) ;
F_219 ( V_34 , V_25 -> V_23 ) ;
F_222 ( V_25 ) ;
F_14 ( & V_25 -> V_23 -> V_35 ) ;
V_34 -> V_16 = V_281 ;
F_22 ( & V_25 -> V_23 -> V_35 ) ;
F_64 ( V_34 -> V_50 ,
F_3 ( & V_34 -> V_44 ) == 1 ) ;
if ( F_73 ( F_104 ( V_34 -> V_41 ) ) ) {
V_106 = V_34 -> V_41 ;
goto V_290;
}
F_60 ( & V_25 -> V_23 -> V_88 ) ;
V_106 = F_195 ( V_21 , V_25 -> V_23 ) ;
if ( V_106 ) {
F_61 ( & V_25 -> V_23 -> V_88 ) ;
goto V_290;
}
V_106 = F_169 ( V_21 , V_25 ) ;
if ( V_106 ) {
F_61 ( & V_25 -> V_23 -> V_88 ) ;
goto V_290;
}
V_106 = F_97 ( V_21 , V_25 , ( unsigned long ) - 1 ) ;
if ( V_106 ) {
F_61 ( & V_25 -> V_23 -> V_88 ) ;
goto V_290;
}
F_223 ( V_25 ) ;
F_2 ( V_34 != V_21 -> V_2 ) ;
F_60 ( & V_25 -> V_23 -> V_291 ) ;
V_106 = F_143 ( V_21 , V_25 ) ;
if ( V_106 ) {
F_61 ( & V_25 -> V_23 -> V_291 ) ;
F_61 ( & V_25 -> V_23 -> V_88 ) ;
goto V_290;
}
F_224 ( V_25 -> V_23 ) ;
F_225 ( V_21 , V_25 -> V_23 ) ;
V_106 = F_131 ( V_21 , V_25 ) ;
if ( V_106 ) {
F_61 ( & V_25 -> V_23 -> V_291 ) ;
F_61 ( & V_25 -> V_23 -> V_88 ) ;
goto V_290;
}
if ( F_73 ( F_104 ( V_34 -> V_41 ) ) ) {
V_106 = V_34 -> V_41 ;
F_61 ( & V_25 -> V_23 -> V_291 ) ;
F_61 ( & V_25 -> V_23 -> V_88 ) ;
goto V_290;
}
F_226 ( V_21 , V_25 ) ;
V_34 = V_25 -> V_23 -> V_40 ;
F_129 ( & V_25 -> V_23 -> V_182 -> V_183 ,
V_25 -> V_23 -> V_182 -> V_18 ) ;
F_49 ( & V_25 -> V_23 -> V_182 -> V_28 ,
& V_34 -> V_66 ) ;
F_129 ( & V_25 -> V_23 -> V_113 -> V_183 ,
V_25 -> V_23 -> V_113 -> V_18 ) ;
F_49 ( & V_25 -> V_23 -> V_113 -> V_28 ,
& V_34 -> V_66 ) ;
F_23 ( V_34 , V_25 -> V_23 ) ;
F_108 ( V_21 ) ;
ASSERT ( F_6 ( & V_34 -> V_68 ) ) ;
ASSERT ( F_6 ( & V_34 -> V_69 ) ) ;
F_197 ( V_25 ) ;
F_227 ( V_25 -> V_23 -> V_259 , 0 ) ;
F_228 ( V_25 -> V_23 -> V_259 , 0 ) ;
memcpy ( V_25 -> V_23 -> V_292 , V_25 -> V_23 -> V_259 ,
sizeof( * V_25 -> V_23 -> V_259 ) ) ;
F_229 ( V_25 -> V_23 ) ;
F_230 ( V_25 , V_34 ) ;
F_57 ( V_172 , & V_168 -> V_173 ) ;
F_57 ( V_175 , & V_168 -> V_173 ) ;
F_14 ( & V_25 -> V_23 -> V_35 ) ;
V_34 -> V_16 = V_90 ;
V_25 -> V_23 -> V_40 = NULL ;
F_22 ( & V_25 -> V_23 -> V_35 ) ;
F_61 ( & V_25 -> V_23 -> V_88 ) ;
F_106 ( & V_25 -> V_23 -> V_91 ) ;
V_106 = F_125 ( V_21 , V_25 ) ;
if ( V_106 ) {
F_231 ( V_25 -> V_23 , V_106 ,
L_7 ) ;
F_61 ( & V_25 -> V_23 -> V_291 ) ;
goto V_290;
}
V_106 = F_232 ( V_21 , V_25 , 0 ) ;
if ( V_106 ) {
F_61 ( & V_25 -> V_23 -> V_291 ) ;
goto V_290;
}
F_61 ( & V_25 -> V_23 -> V_291 ) ;
F_233 ( V_21 , V_25 ) ;
if ( V_34 -> V_53 )
F_234 ( V_25 -> V_23 ) ;
V_25 -> V_23 -> V_141 = V_34 -> V_78 ;
V_34 -> V_16 = V_139 ;
F_106 ( & V_34 -> V_51 ) ;
F_14 ( & V_25 -> V_23 -> V_35 ) ;
F_10 ( & V_34 -> V_4 ) ;
F_22 ( & V_25 -> V_23 -> V_35 ) ;
F_1 ( V_34 ) ;
F_1 ( V_34 ) ;
if ( V_21 -> type & V_121 )
F_76 ( V_25 -> V_23 -> V_122 ) ;
F_213 ( V_25 ) ;
F_235 ( V_25 ) ;
if ( V_107 -> V_108 == V_21 )
V_107 -> V_108 = NULL ;
F_12 ( V_119 , V_21 ) ;
if ( V_107 != V_25 -> V_23 -> V_156 )
F_107 ( V_25 ) ;
return V_106 ;
V_290:
F_235 ( V_25 ) ;
F_210:
F_99 ( V_21 , V_25 ) ;
V_21 -> V_111 = NULL ;
if ( V_21 -> V_104 ) {
F_78 ( V_25 , V_21 -> V_104 ) ;
V_21 -> V_104 = 0 ;
}
F_236 ( V_25 -> V_23 , L_8 ) ;
if ( V_107 -> V_108 == V_21 )
V_107 -> V_108 = NULL ;
F_210 ( V_21 , V_25 , V_106 ) ;
return V_106 ;
}
int F_237 ( struct V_24 * V_25 )
{
int V_106 ;
struct V_22 * V_23 = V_25 -> V_23 ;
F_14 ( & V_23 -> V_35 ) ;
if ( F_6 ( & V_23 -> V_191 ) ) {
F_22 ( & V_23 -> V_35 ) ;
return 0 ;
}
V_25 = F_9 ( & V_23 -> V_191 ,
struct V_24 , V_190 ) ;
F_10 ( & V_25 -> V_190 ) ;
F_22 ( & V_23 -> V_35 ) ;
F_158 ( L_9 , V_25 -> V_30 ) ;
F_238 ( V_25 ) ;
if ( F_239 ( V_25 -> V_18 ) <
V_293 )
V_106 = F_240 ( V_25 , NULL , 0 , 0 ) ;
else
V_106 = F_240 ( V_25 , NULL , 1 , 0 ) ;
return ( V_106 < 0 ) ? 0 : 1 ;
}
void F_224 ( struct V_22 * V_23 )
{
unsigned long V_289 ;
unsigned long V_294 ;
V_289 = F_241 ( & V_23 -> V_295 , 0 ) ;
if ( ! V_289 )
return;
V_294 = 1 << V_296 ;
if ( V_289 & V_294 )
F_242 ( V_23 -> V_297 , V_298 ) ;
V_289 &= ~ V_294 ;
V_294 = 1 << V_299 ;
if ( V_289 & V_294 )
F_243 ( V_23 -> V_297 , V_298 ) ;
V_289 &= ~ V_294 ;
V_294 = 1 << V_300 ;
if ( V_289 & V_294 )
F_244 ( V_23 , L_10 ) ;
V_289 &= ~ V_294 ;
if ( V_289 )
F_236 ( V_23 ,
L_11 , V_289 ) ;
}

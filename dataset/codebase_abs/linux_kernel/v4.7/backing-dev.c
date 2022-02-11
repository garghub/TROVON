static void F_1 ( void )
{
V_1 = F_2 ( L_1 , NULL ) ;
}
static int F_3 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_9 ;
unsigned long V_10 ;
unsigned long V_11 ;
unsigned long V_12 ;
unsigned long V_13 , V_14 , V_15 , V_16 ;
struct V_17 * V_17 ;
V_13 = V_14 = V_15 = V_16 = 0 ;
F_4 ( & V_9 -> V_18 ) ;
F_5 (inode, &wb->b_dirty, i_io_list)
V_13 ++ ;
F_5 (inode, &wb->b_io, i_io_list)
V_14 ++ ;
F_5 (inode, &wb->b_more_io, i_io_list)
V_15 ++ ;
F_5 (inode, &wb->b_dirty_time, i_io_list)
if ( V_17 -> V_19 & V_20 )
V_16 ++ ;
F_6 ( & V_9 -> V_18 ) ;
F_7 ( & V_10 , & V_11 ) ;
V_12 = F_8 ( V_9 , V_11 ) ;
#define F_9 ( T_1 ) ((x) << (PAGE_SHIFT - 10))
F_10 ( V_3 ,
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11
L_12
L_13
L_14
L_15 ,
( unsigned long ) F_9 ( F_11 ( V_9 , V_21 ) ) ,
( unsigned long ) F_9 ( F_11 ( V_9 , V_22 ) ) ,
F_9 ( V_12 ) ,
F_9 ( V_11 ) ,
F_9 ( V_10 ) ,
( unsigned long ) F_9 ( F_11 ( V_9 , V_23 ) ) ,
( unsigned long ) F_9 ( F_11 ( V_9 , V_24 ) ) ,
( unsigned long ) F_9 ( V_9 -> V_25 ) ,
V_13 ,
V_14 ,
V_15 ,
V_16 ,
! F_12 ( & V_6 -> V_26 ) , V_6 -> V_9 . V_27 ) ;
#undef F_9
return 0 ;
}
static int F_13 ( struct V_17 * V_17 , struct V_28 * V_28 )
{
return F_14 ( V_28 , F_3 , V_17 -> V_29 ) ;
}
static void F_15 ( struct V_5 * V_6 , const char * V_30 )
{
V_6 -> V_31 = F_2 ( V_30 , V_1 ) ;
V_6 -> V_32 = F_16 ( L_16 , 0444 , V_6 -> V_31 ,
V_6 , & V_33 ) ;
}
static void F_17 ( struct V_5 * V_6 )
{
F_18 ( V_6 -> V_32 ) ;
F_18 ( V_6 -> V_31 ) ;
}
static inline void F_1 ( void )
{
}
static inline void F_15 ( struct V_5 * V_6 ,
const char * V_30 )
{
}
static inline void F_17 ( struct V_5 * V_6 )
{
}
static T_2 F_19 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const char * V_38 , T_3 V_39 )
{
struct V_5 * V_6 = F_20 ( V_35 ) ;
unsigned long V_40 ;
T_2 V_41 ;
V_41 = F_21 ( V_38 , 10 , & V_40 ) ;
if ( V_41 < 0 )
return V_41 ;
V_6 -> V_42 = V_40 >> ( V_43 - 10 ) ;
return V_39 ;
}
static T_2 F_22 ( struct V_34 * V_35 ,
struct V_36 * V_37 , const char * V_38 , T_3 V_39 )
{
struct V_5 * V_6 = F_20 ( V_35 ) ;
unsigned int V_44 ;
T_2 V_41 ;
V_41 = F_23 ( V_38 , 10 , & V_44 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_24 ( V_6 , V_44 ) ;
if ( ! V_41 )
V_41 = V_39 ;
return V_41 ;
}
static T_2 F_25 ( struct V_34 * V_35 ,
struct V_36 * V_37 , const char * V_38 , T_3 V_39 )
{
struct V_5 * V_6 = F_20 ( V_35 ) ;
unsigned int V_44 ;
T_2 V_41 ;
V_41 = F_23 ( V_38 , 10 , & V_44 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_26 ( V_6 , V_44 ) ;
if ( ! V_41 )
V_41 = V_39 ;
return V_41 ;
}
static T_2 F_27 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_45 )
{
struct V_5 * V_6 = F_20 ( V_35 ) ;
return snprintf ( V_45 , V_46 - 1 , L_17 ,
F_28 ( V_6 ) ? 1 : 0 ) ;
}
static T_4 int F_29 ( void )
{
V_47 = F_30 ( V_48 , L_1 ) ;
if ( F_31 ( V_47 ) )
return F_32 ( V_47 ) ;
V_47 -> V_49 = V_50 ;
F_1 () ;
return 0 ;
}
static int T_4 F_33 ( void )
{
int V_51 ;
V_52 = F_34 ( L_18 , V_53 | V_54 |
V_55 | V_56 , 0 ) ;
if ( ! V_52 )
return - V_57 ;
V_51 = F_35 ( & V_58 ) ;
return V_51 ;
}
void F_36 ( struct V_8 * V_9 )
{
unsigned long V_59 ;
V_59 = F_37 ( V_60 * 10 ) ;
F_38 ( & V_9 -> V_61 ) ;
if ( F_39 ( V_62 , & V_9 -> V_27 ) )
F_40 ( V_52 , & V_9 -> V_63 , V_59 ) ;
F_41 ( & V_9 -> V_61 ) ;
}
static int F_42 ( struct V_8 * V_9 , struct V_5 * V_6 ,
int V_64 , T_5 V_65 )
{
int V_66 , V_51 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_6 = V_6 ;
V_9 -> V_67 = V_68 ;
F_43 ( & V_9 -> V_69 ) ;
F_43 ( & V_9 -> V_70 ) ;
F_43 ( & V_9 -> V_71 ) ;
F_43 ( & V_9 -> V_72 ) ;
F_44 ( & V_9 -> V_18 ) ;
V_9 -> V_73 = V_68 ;
V_9 -> V_74 = V_75 ;
V_9 -> V_76 = V_75 ;
V_9 -> V_25 = V_75 ;
V_9 -> V_77 = V_75 ;
F_44 ( & V_9 -> V_61 ) ;
F_43 ( & V_9 -> V_78 ) ;
F_45 ( & V_9 -> V_63 , V_79 ) ;
V_9 -> V_80 = F_46 ( V_6 , V_64 , V_65 ) ;
if ( ! V_9 -> V_80 )
return - V_57 ;
V_51 = F_47 ( & V_9 -> V_81 , V_65 ) ;
if ( V_51 )
goto V_82;
for ( V_66 = 0 ; V_66 < V_83 ; V_66 ++ ) {
V_51 = F_48 ( & V_9 -> V_84 [ V_66 ] , 0 , V_65 ) ;
if ( V_51 )
goto V_85;
}
return 0 ;
V_85:
while ( V_66 -- )
F_49 ( & V_9 -> V_84 [ V_66 ] ) ;
F_50 ( & V_9 -> V_81 ) ;
V_82:
F_51 ( V_9 -> V_80 ) ;
return V_51 ;
}
static void F_52 ( struct V_8 * V_9 )
{
F_38 ( & V_9 -> V_61 ) ;
if ( ! F_53 ( V_62 , & V_9 -> V_27 ) ) {
F_41 ( & V_9 -> V_61 ) ;
return;
}
F_41 ( & V_9 -> V_61 ) ;
F_54 ( V_52 , & V_9 -> V_63 , 0 ) ;
F_55 ( & V_9 -> V_63 ) ;
F_56 ( ! F_12 ( & V_9 -> V_78 ) ) ;
}
static void F_57 ( struct V_8 * V_9 )
{
int V_66 ;
F_56 ( F_58 ( & V_9 -> V_63 ) ) ;
for ( V_66 = 0 ; V_66 < V_83 ; V_66 ++ )
F_49 ( & V_9 -> V_84 [ V_66 ] ) ;
F_50 ( & V_9 -> V_81 ) ;
F_51 ( V_9 -> V_80 ) ;
}
struct V_86 *
F_46 ( struct V_5 * V_6 , int V_64 , T_5 V_65 )
{
struct V_86 * V_87 = NULL , * V_80 ;
struct V_88 * * V_89 , * V_90 ;
unsigned long V_91 ;
V_92:
F_59 ( & V_93 , V_91 ) ;
V_89 = & V_6 -> V_94 . V_88 ;
V_90 = NULL ;
while ( * V_89 != NULL ) {
V_90 = * V_89 ;
V_80 = F_60 ( V_90 , struct V_86 ,
V_88 ) ;
if ( V_80 -> V_64 < V_64 )
V_89 = & V_90 -> V_95 ;
else if ( V_80 -> V_64 > V_64 )
V_89 = & V_90 -> V_96 ;
else
goto V_97;
}
if ( V_87 ) {
V_80 = V_87 ;
V_87 = NULL ;
F_61 ( & V_80 -> V_88 , V_90 , V_89 ) ;
F_62 ( & V_80 -> V_88 , & V_6 -> V_94 ) ;
goto V_97;
}
F_63 ( & V_93 , V_91 ) ;
V_87 = F_64 ( sizeof( * V_87 ) , V_65 ) ;
if ( ! V_87 )
return NULL ;
F_65 ( & V_87 -> V_98 , 0 ) ;
V_87 -> V_6 = V_6 ;
V_87 -> V_64 = V_64 ;
goto V_92;
V_97:
F_66 ( & V_80 -> V_98 ) ;
F_63 ( & V_93 , V_91 ) ;
F_67 ( V_87 ) ;
return V_80 ;
}
void F_51 ( struct V_86 * V_80 )
{
unsigned long V_91 ;
F_68 ( V_91 ) ;
if ( ! F_69 ( & V_80 -> V_98 , & V_93 ) ) {
F_70 ( V_91 ) ;
return;
}
if ( V_80 -> V_6 ) {
F_71 ( & V_80 -> V_88 ,
& V_80 -> V_6 -> V_94 ) ;
V_80 -> V_6 = NULL ;
}
F_63 ( & V_93 , V_91 ) ;
F_67 ( V_80 ) ;
}
static void F_72 ( struct V_99 * V_100 )
{
struct V_8 * V_9 = F_60 ( V_100 , struct V_8 ,
V_101 ) ;
struct V_5 * V_6 = V_9 -> V_6 ;
F_73 ( & V_93 ) ;
F_74 ( & V_9 -> V_102 ) ;
F_75 ( & V_93 ) ;
F_52 ( V_9 ) ;
F_76 ( V_9 -> V_103 ) ;
F_76 ( V_9 -> V_104 ) ;
F_50 ( & V_9 -> V_105 ) ;
F_77 ( & V_9 -> V_98 ) ;
F_57 ( V_9 ) ;
F_78 ( V_9 , V_106 ) ;
if ( F_79 ( & V_6 -> V_107 ) )
F_80 ( & V_108 ) ;
}
static void F_81 ( struct V_109 * V_98 )
{
struct V_8 * V_9 = F_60 ( V_98 , struct V_8 ,
V_98 ) ;
F_82 ( & V_9 -> V_101 ) ;
}
static void F_83 ( struct V_8 * V_9 )
{
F_84 ( & V_93 ) ;
F_56 ( ! F_85 ( & V_9 -> V_6 -> V_110 , V_9 -> V_103 -> V_111 ) ) ;
F_86 ( & V_9 -> V_112 ) ;
F_86 ( & V_9 -> V_113 ) ;
F_87 ( & V_9 -> V_98 ) ;
}
static int F_88 ( struct V_5 * V_6 ,
struct V_114 * V_103 , T_5 V_65 )
{
struct V_115 * V_116 ;
struct V_114 * V_104 ;
struct V_117 * V_117 ;
struct V_118 * V_119 , * V_120 ;
struct V_8 * V_9 ;
unsigned long V_91 ;
int V_41 = 0 ;
V_116 = F_89 ( V_103 ) ;
V_104 = F_90 ( V_103 -> V_121 , & V_122 ) ;
V_117 = F_91 ( V_104 ) ;
V_119 = F_92 ( V_116 ) ;
V_120 = & V_117 -> V_123 ;
F_59 ( & V_93 , V_91 ) ;
V_9 = F_93 ( & V_6 -> V_110 , V_103 -> V_111 ) ;
if ( V_9 && V_9 -> V_104 != V_104 ) {
F_83 ( V_9 ) ;
V_9 = NULL ;
}
F_63 ( & V_93 , V_91 ) ;
if ( V_9 )
goto V_124;
V_9 = F_94 ( sizeof( * V_9 ) , V_65 ) ;
if ( ! V_9 )
return - V_57 ;
V_41 = F_42 ( V_9 , V_6 , V_104 -> V_111 , V_65 ) ;
if ( V_41 )
goto V_125;
V_41 = F_95 ( & V_9 -> V_98 , F_81 , 0 , V_65 ) ;
if ( V_41 )
goto V_126;
V_41 = F_47 ( & V_9 -> V_105 , V_65 ) ;
if ( V_41 )
goto V_127;
V_9 -> V_103 = V_103 ;
V_9 -> V_104 = V_104 ;
F_96 ( & V_9 -> V_101 , F_72 ) ;
F_97 ( V_62 , & V_9 -> V_27 ) ;
V_41 = - V_128 ;
F_59 ( & V_93 , V_91 ) ;
if ( F_39 ( V_62 , & V_6 -> V_9 . V_27 ) &&
V_120 -> V_129 && V_119 -> V_129 ) {
V_41 = F_98 ( & V_6 -> V_110 , V_103 -> V_111 , V_9 ) ;
if ( ! V_41 ) {
F_66 ( & V_6 -> V_107 ) ;
F_99 ( & V_9 -> V_102 , & V_6 -> V_130 ) ;
F_100 ( & V_9 -> V_112 , V_119 ) ;
F_100 ( & V_9 -> V_113 , V_120 ) ;
F_101 ( V_103 ) ;
F_101 ( V_104 ) ;
}
}
F_63 ( & V_93 , V_91 ) ;
if ( V_41 ) {
if ( V_41 == - V_131 )
V_41 = 0 ;
goto V_132;
}
goto V_124;
V_132:
F_50 ( & V_9 -> V_105 ) ;
V_127:
F_77 ( & V_9 -> V_98 ) ;
V_126:
F_57 ( V_9 ) ;
V_125:
F_67 ( V_9 ) ;
V_124:
F_76 ( V_104 ) ;
return V_41 ;
}
struct V_8 * F_102 ( struct V_5 * V_6 ,
struct V_114 * V_103 ,
T_5 V_65 )
{
struct V_8 * V_9 ;
F_103 ( F_104 ( V_65 ) ) ;
if ( ! V_103 -> V_90 )
return & V_6 -> V_9 ;
do {
F_105 () ;
V_9 = F_93 ( & V_6 -> V_110 , V_103 -> V_111 ) ;
if ( V_9 ) {
struct V_114 * V_104 ;
V_104 = F_90 ( V_103 -> V_121 ,
& V_122 ) ;
if ( F_106 ( V_9 -> V_104 != V_104 ||
! F_107 ( V_9 ) ) )
V_9 = NULL ;
F_76 ( V_104 ) ;
}
F_108 () ;
} while ( ! V_9 && ! F_88 ( V_6 , V_103 , V_65 ) );
return V_9 ;
}
static int F_109 ( struct V_5 * V_6 )
{
int V_41 ;
F_110 ( & V_6 -> V_110 , V_133 ) ;
V_6 -> V_94 = V_134 ;
F_65 ( & V_6 -> V_107 , 1 ) ;
V_41 = F_42 ( & V_6 -> V_9 , V_6 , 1 , V_135 ) ;
if ( ! V_41 ) {
V_6 -> V_9 . V_103 = & V_136 -> V_137 ;
V_6 -> V_9 . V_104 = V_138 ;
}
return V_41 ;
}
static void F_111 ( struct V_5 * V_6 )
{
struct V_139 V_140 ;
struct V_88 * V_141 ;
void * * V_142 ;
F_56 ( F_39 ( V_62 , & V_6 -> V_9 . V_27 ) ) ;
F_73 ( & V_93 ) ;
F_112 (slot, &bdi->cgwb_tree, &iter, 0 )
F_83 ( * V_142 ) ;
while ( ( V_141 = F_113 ( & V_6 -> V_94 ) ) ) {
struct V_86 * V_80 =
F_114 ( V_141 , struct V_86 , V_88 ) ;
F_71 ( V_141 , & V_6 -> V_94 ) ;
V_80 -> V_6 = NULL ;
}
F_75 ( & V_93 ) ;
F_115 ( & V_6 -> V_107 ) ;
F_116 ( V_108 , ! F_117 ( & V_6 -> V_107 ) ) ;
}
void F_118 ( struct V_115 * V_116 )
{
F_119 ( V_143 ) ;
struct V_118 * V_119 = F_92 ( V_116 ) ;
struct V_8 * V_9 , * V_129 ;
F_73 ( & V_93 ) ;
F_120 (wb, next, memcg_cgwb_list, memcg_node)
F_83 ( V_9 ) ;
V_119 -> V_129 = NULL ;
F_75 ( & V_93 ) ;
}
void F_121 ( struct V_117 * V_117 )
{
F_119 ( V_143 ) ;
struct V_8 * V_9 , * V_129 ;
F_73 ( & V_93 ) ;
F_120 (wb, next, &blkcg->cgwb_list, blkcg_node)
F_83 ( V_9 ) ;
V_117 -> V_123 . V_129 = NULL ;
F_75 ( & V_93 ) ;
}
static int F_109 ( struct V_5 * V_6 )
{
int V_51 ;
V_6 -> V_144 = F_64 ( sizeof( * V_6 -> V_144 ) , V_135 ) ;
if ( ! V_6 -> V_144 )
return - V_57 ;
V_51 = F_42 ( & V_6 -> V_9 , V_6 , 1 , V_135 ) ;
if ( V_51 ) {
F_67 ( V_6 -> V_144 ) ;
return V_51 ;
}
return 0 ;
}
static void F_111 ( struct V_5 * V_6 ) { }
int F_35 ( struct V_5 * V_6 )
{
int V_41 ;
V_6 -> V_35 = NULL ;
V_6 -> V_145 = 0 ;
V_6 -> V_146 = 100 ;
V_6 -> V_147 = V_148 ;
F_43 ( & V_6 -> V_26 ) ;
F_43 ( & V_6 -> V_130 ) ;
F_122 ( & V_6 -> V_149 ) ;
V_41 = F_109 ( V_6 ) ;
F_99 ( & V_6 -> V_9 . V_102 , & V_6 -> V_130 ) ;
return V_41 ;
}
int F_123 ( struct V_5 * V_6 , struct V_34 * V_90 ,
const char * V_150 , ... )
{
T_6 args ;
struct V_34 * V_35 ;
if ( V_6 -> V_35 )
return 0 ;
va_start ( args , V_150 ) ;
V_35 = F_124 ( V_47 , V_90 , F_125 ( 0 , 0 ) , V_6 , V_150 , args ) ;
va_end ( args ) ;
if ( F_31 ( V_35 ) )
return F_32 ( V_35 ) ;
V_6 -> V_35 = V_35 ;
F_15 ( V_6 , F_126 ( V_35 ) ) ;
F_97 ( V_62 , & V_6 -> V_9 . V_27 ) ;
F_38 ( & V_151 ) ;
F_99 ( & V_6 -> V_26 , & V_26 ) ;
F_41 ( & V_151 ) ;
F_127 ( V_6 ) ;
return 0 ;
}
int F_128 ( struct V_5 * V_6 , T_7 V_35 )
{
return F_123 ( V_6 , NULL , L_19 , F_129 ( V_35 ) , F_130 ( V_35 ) ) ;
}
static void F_131 ( struct V_5 * V_6 )
{
F_38 ( & V_151 ) ;
F_74 ( & V_6 -> V_26 ) ;
F_41 ( & V_151 ) ;
F_132 () ;
}
void F_133 ( struct V_5 * V_6 )
{
F_131 ( V_6 ) ;
F_52 ( & V_6 -> V_9 ) ;
F_111 ( V_6 ) ;
if ( V_6 -> V_35 ) {
F_17 ( V_6 ) ;
F_134 ( V_6 -> V_35 ) ;
V_6 -> V_35 = NULL ;
}
}
void F_135 ( struct V_5 * V_6 )
{
F_136 ( V_6 -> V_35 ) ;
F_57 ( & V_6 -> V_9 ) ;
}
void F_137 ( struct V_5 * V_6 )
{
F_133 ( V_6 ) ;
F_135 ( V_6 ) ;
}
int F_138 ( struct V_5 * V_6 , char * V_30 )
{
int V_51 ;
V_6 -> V_30 = V_30 ;
V_6 -> V_152 = 0 ;
V_51 = F_35 ( V_6 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_123 ( V_6 , NULL , L_20 , V_30 ,
F_139 ( & V_153 ) ) ;
if ( V_51 ) {
F_137 ( V_6 ) ;
return V_51 ;
}
return 0 ;
}
void F_140 ( struct V_86 * V_80 , int V_154 )
{
T_8 * V_155 = & V_156 [ V_154 ] ;
enum V_157 V_158 ;
V_158 = V_154 ? V_159 : V_160 ;
if ( F_53 ( V_158 , & V_80 -> V_27 ) )
F_115 ( & V_161 [ V_154 ] ) ;
F_141 () ;
if ( F_142 ( V_155 ) )
F_143 ( V_155 ) ;
}
void F_144 ( struct V_86 * V_80 , int V_154 )
{
enum V_157 V_158 ;
V_158 = V_154 ? V_159 : V_160 ;
if ( ! F_145 ( V_158 , & V_80 -> V_27 ) )
F_66 ( & V_161 [ V_154 ] ) ;
}
long F_146 ( int V_154 , long V_59 )
{
long V_41 ;
unsigned long V_162 = V_68 ;
F_147 ( V_163 ) ;
T_8 * V_155 = & V_156 [ V_154 ] ;
F_148 ( V_155 , & V_163 , V_164 ) ;
V_41 = F_149 ( V_59 ) ;
F_150 ( V_155 , & V_163 ) ;
F_151 ( F_152 ( V_59 ) ,
F_152 ( V_68 - V_162 ) ) ;
return V_41 ;
}
long F_153 ( struct V_165 * V_165 , int V_154 , long V_59 )
{
long V_41 ;
unsigned long V_162 = V_68 ;
F_147 ( V_163 ) ;
T_8 * V_155 = & V_156 [ V_154 ] ;
if ( F_117 ( & V_161 [ V_154 ] ) == 0 ||
! F_39 ( V_166 , & V_165 -> V_91 ) ) {
F_154 () ;
V_41 = V_59 - ( V_68 - V_162 ) ;
if ( V_41 < 0 )
V_41 = 0 ;
goto V_167;
}
F_148 ( V_155 , & V_163 , V_164 ) ;
V_41 = F_149 ( V_59 ) ;
F_150 ( V_155 , & V_163 ) ;
V_167:
F_155 ( F_152 ( V_59 ) ,
F_152 ( V_68 - V_162 ) ) ;
return V_41 ;
}
int F_156 ( struct V_168 * V_169 , int V_170 ,
void T_9 * V_171 , T_3 * V_172 , T_10 * V_173 )
{
char V_174 [] = L_21 ;
if ( * V_173 || * V_172 < sizeof( V_174 ) ) {
* V_172 = 0 ;
return 0 ;
}
if ( F_157 ( V_171 , V_174 , sizeof( V_174 ) ) )
return - V_175 ;
F_158 ( L_22 ,
V_169 -> V_176 ) ;
* V_172 = 2 ;
* V_173 += * V_172 ;
return 2 ;
}

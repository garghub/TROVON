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
if ( V_9 != & V_6 -> V_9 )
F_43 ( V_6 ) ;
V_9 -> V_6 = V_6 ;
V_9 -> V_67 = V_68 ;
F_44 ( & V_9 -> V_69 ) ;
F_44 ( & V_9 -> V_70 ) ;
F_44 ( & V_9 -> V_71 ) ;
F_44 ( & V_9 -> V_72 ) ;
F_45 ( & V_9 -> V_18 ) ;
V_9 -> V_73 = V_68 ;
V_9 -> V_74 = V_75 ;
V_9 -> V_76 = V_75 ;
V_9 -> V_25 = V_75 ;
V_9 -> V_77 = V_75 ;
F_45 ( & V_9 -> V_61 ) ;
F_44 ( & V_9 -> V_78 ) ;
F_46 ( & V_9 -> V_63 , V_79 ) ;
V_9 -> V_80 = V_68 ;
V_9 -> V_81 = F_47 ( V_6 , V_64 , V_65 ) ;
if ( ! V_9 -> V_81 ) {
V_51 = - V_57 ;
goto V_82;
}
V_51 = F_48 ( & V_9 -> V_83 , V_65 ) ;
if ( V_51 )
goto V_84;
for ( V_66 = 0 ; V_66 < V_85 ; V_66 ++ ) {
V_51 = F_49 ( & V_9 -> V_86 [ V_66 ] , 0 , V_65 ) ;
if ( V_51 )
goto V_87;
}
return 0 ;
V_87:
while ( V_66 -- )
F_50 ( & V_9 -> V_86 [ V_66 ] ) ;
F_51 ( & V_9 -> V_83 ) ;
V_84:
F_52 ( V_9 -> V_81 ) ;
V_82:
if ( V_9 != & V_6 -> V_9 )
F_53 ( V_6 ) ;
return V_51 ;
}
static void F_54 ( struct V_8 * V_9 )
{
F_38 ( & V_9 -> V_61 ) ;
if ( ! F_55 ( V_62 , & V_9 -> V_27 ) ) {
F_41 ( & V_9 -> V_61 ) ;
F_56 ( & V_9 -> V_27 , V_88 , V_89 ) ;
return;
}
F_57 ( V_88 , & V_9 -> V_27 ) ;
F_41 ( & V_9 -> V_61 ) ;
F_58 ( V_9 ) ;
F_59 ( V_52 , & V_9 -> V_63 , 0 ) ;
F_60 ( & V_9 -> V_63 ) ;
F_61 ( ! F_12 ( & V_9 -> V_78 ) ) ;
F_62 () ;
F_63 ( V_88 , & V_9 -> V_27 ) ;
}
static void F_64 ( struct V_8 * V_9 )
{
int V_66 ;
F_61 ( F_65 ( & V_9 -> V_63 ) ) ;
for ( V_66 = 0 ; V_66 < V_85 ; V_66 ++ )
F_50 ( & V_9 -> V_86 [ V_66 ] ) ;
F_51 ( & V_9 -> V_83 ) ;
F_52 ( V_9 -> V_81 ) ;
if ( V_9 != & V_9 -> V_6 -> V_9 )
F_53 ( V_9 -> V_6 ) ;
}
struct V_90 *
F_47 ( struct V_5 * V_6 , int V_64 , T_5 V_65 )
{
struct V_90 * V_91 = NULL , * V_81 ;
struct V_92 * * V_93 , * V_94 ;
unsigned long V_95 ;
V_96:
F_66 ( & V_97 , V_95 ) ;
V_93 = & V_6 -> V_98 . V_92 ;
V_94 = NULL ;
while ( * V_93 != NULL ) {
V_94 = * V_93 ;
V_81 = F_67 ( V_94 , struct V_90 ,
V_92 ) ;
if ( V_81 -> V_64 < V_64 )
V_93 = & V_94 -> V_99 ;
else if ( V_81 -> V_64 > V_64 )
V_93 = & V_94 -> V_100 ;
else
goto V_101;
}
if ( V_91 ) {
V_81 = V_91 ;
V_91 = NULL ;
F_68 ( & V_81 -> V_92 , V_94 , V_93 ) ;
F_69 ( & V_81 -> V_92 , & V_6 -> V_98 ) ;
goto V_101;
}
F_70 ( & V_97 , V_95 ) ;
V_91 = F_71 ( sizeof( * V_91 ) , V_65 ) ;
if ( ! V_91 )
return NULL ;
F_72 ( & V_91 -> V_102 , 0 ) ;
V_91 -> V_103 = V_6 ;
V_91 -> V_64 = V_64 ;
goto V_96;
V_101:
F_73 ( & V_81 -> V_102 ) ;
F_70 ( & V_97 , V_95 ) ;
F_74 ( V_91 ) ;
return V_81 ;
}
void F_52 ( struct V_90 * V_81 )
{
unsigned long V_95 ;
F_75 ( V_95 ) ;
if ( ! F_76 ( & V_81 -> V_102 , & V_97 ) ) {
F_77 ( V_95 ) ;
return;
}
if ( V_81 -> V_103 ) {
F_78 ( & V_81 -> V_92 ,
& V_81 -> V_103 -> V_98 ) ;
V_81 -> V_103 = NULL ;
}
F_70 ( & V_97 , V_95 ) ;
F_74 ( V_81 ) ;
}
static void F_79 ( struct V_104 * V_105 )
{
struct V_8 * V_9 = F_80 ( V_105 , struct V_8 ,
V_106 ) ;
F_54 ( V_9 ) ;
F_81 ( V_9 -> V_107 ) ;
F_81 ( V_9 -> V_108 ) ;
F_51 ( & V_9 -> V_109 ) ;
F_82 ( & V_9 -> V_102 ) ;
F_64 ( V_9 ) ;
F_83 ( V_9 , V_110 ) ;
}
static void F_84 ( struct V_111 * V_102 )
{
struct V_8 * V_9 = F_80 ( V_102 , struct V_8 ,
V_102 ) ;
F_85 ( & V_9 -> V_106 ) ;
}
static void F_86 ( struct V_8 * V_9 )
{
F_87 ( & V_97 ) ;
F_61 ( ! F_88 ( & V_9 -> V_6 -> V_112 , V_9 -> V_107 -> V_113 ) ) ;
F_89 ( & V_9 -> V_114 ) ;
F_89 ( & V_9 -> V_115 ) ;
F_90 ( & V_9 -> V_102 ) ;
}
static void F_58 ( struct V_8 * V_9 )
{
F_91 ( & V_97 ) ;
F_92 ( & V_9 -> V_116 ) ;
F_93 ( & V_97 ) ;
}
static int F_94 ( struct V_5 * V_6 ,
struct V_117 * V_107 , T_5 V_65 )
{
struct V_118 * V_119 ;
struct V_117 * V_108 ;
struct V_120 * V_120 ;
struct V_121 * V_122 , * V_123 ;
struct V_8 * V_9 ;
unsigned long V_95 ;
int V_41 = 0 ;
V_119 = F_95 ( V_107 ) ;
V_108 = F_96 ( V_107 -> V_124 , & V_125 ) ;
V_120 = F_97 ( V_108 ) ;
V_122 = F_98 ( V_119 ) ;
V_123 = & V_120 -> V_126 ;
F_66 ( & V_97 , V_95 ) ;
V_9 = F_99 ( & V_6 -> V_112 , V_107 -> V_113 ) ;
if ( V_9 && V_9 -> V_108 != V_108 ) {
F_86 ( V_9 ) ;
V_9 = NULL ;
}
F_70 ( & V_97 , V_95 ) ;
if ( V_9 )
goto V_127;
V_9 = F_100 ( sizeof( * V_9 ) , V_65 ) ;
if ( ! V_9 )
return - V_57 ;
V_41 = F_42 ( V_9 , V_6 , V_108 -> V_113 , V_65 ) ;
if ( V_41 )
goto V_128;
V_41 = F_101 ( & V_9 -> V_102 , F_84 , 0 , V_65 ) ;
if ( V_41 )
goto V_129;
V_41 = F_48 ( & V_9 -> V_109 , V_65 ) ;
if ( V_41 )
goto V_130;
V_9 -> V_107 = V_107 ;
V_9 -> V_108 = V_108 ;
F_102 ( & V_9 -> V_106 , F_79 ) ;
F_57 ( V_62 , & V_9 -> V_27 ) ;
V_41 = - V_131 ;
F_66 ( & V_97 , V_95 ) ;
if ( F_39 ( V_62 , & V_6 -> V_9 . V_27 ) &&
V_123 -> V_132 && V_122 -> V_132 ) {
V_41 = F_103 ( & V_6 -> V_112 , V_107 -> V_113 , V_9 ) ;
if ( ! V_41 ) {
F_104 ( & V_9 -> V_116 , & V_6 -> V_133 ) ;
F_105 ( & V_9 -> V_114 , V_122 ) ;
F_105 ( & V_9 -> V_115 , V_123 ) ;
F_106 ( V_107 ) ;
F_106 ( V_108 ) ;
}
}
F_70 ( & V_97 , V_95 ) ;
if ( V_41 ) {
if ( V_41 == - V_134 )
V_41 = 0 ;
goto V_135;
}
goto V_127;
V_135:
F_51 ( & V_9 -> V_109 ) ;
V_130:
F_82 ( & V_9 -> V_102 ) ;
V_129:
F_64 ( V_9 ) ;
V_128:
F_74 ( V_9 ) ;
V_127:
F_81 ( V_108 ) ;
return V_41 ;
}
struct V_8 * F_107 ( struct V_5 * V_6 ,
struct V_117 * V_107 ,
T_5 V_65 )
{
struct V_8 * V_9 ;
F_108 ( F_109 ( V_65 ) ) ;
if ( ! V_107 -> V_94 )
return & V_6 -> V_9 ;
do {
F_110 () ;
V_9 = F_99 ( & V_6 -> V_112 , V_107 -> V_113 ) ;
if ( V_9 ) {
struct V_117 * V_108 ;
V_108 = F_96 ( V_107 -> V_124 ,
& V_125 ) ;
if ( F_111 ( V_9 -> V_108 != V_108 ||
! F_112 ( V_9 ) ) )
V_9 = NULL ;
F_81 ( V_108 ) ;
}
F_113 () ;
} while ( ! V_9 && ! F_94 ( V_6 , V_107 , V_65 ) );
return V_9 ;
}
static int F_114 ( struct V_5 * V_6 )
{
int V_41 ;
F_115 ( & V_6 -> V_112 , V_136 ) ;
V_6 -> V_98 = V_137 ;
V_41 = F_42 ( & V_6 -> V_9 , V_6 , 1 , V_138 ) ;
if ( ! V_41 ) {
V_6 -> V_9 . V_107 = & V_139 -> V_140 ;
V_6 -> V_9 . V_108 = V_141 ;
}
return V_41 ;
}
static void F_116 ( struct V_5 * V_6 )
{
struct V_142 V_143 ;
void * * V_144 ;
struct V_8 * V_9 ;
F_61 ( F_39 ( V_62 , & V_6 -> V_9 . V_27 ) ) ;
F_91 ( & V_97 ) ;
F_117 (slot, &bdi->cgwb_tree, &iter, 0 )
F_86 ( * V_144 ) ;
while ( ! F_12 ( & V_6 -> V_133 ) ) {
V_9 = F_118 ( & V_6 -> V_133 , struct V_8 ,
V_116 ) ;
F_93 ( & V_97 ) ;
F_54 ( V_9 ) ;
F_91 ( & V_97 ) ;
}
F_93 ( & V_97 ) ;
}
void F_119 ( struct V_118 * V_119 )
{
F_120 ( V_145 ) ;
struct V_121 * V_122 = F_98 ( V_119 ) ;
struct V_8 * V_9 , * V_132 ;
F_91 ( & V_97 ) ;
F_121 (wb, next, memcg_cgwb_list, memcg_node)
F_86 ( V_9 ) ;
V_122 -> V_132 = NULL ;
F_93 ( & V_97 ) ;
}
void F_122 ( struct V_120 * V_120 )
{
F_120 ( V_145 ) ;
struct V_8 * V_9 , * V_132 ;
F_91 ( & V_97 ) ;
F_121 (wb, next, &blkcg->cgwb_list, blkcg_node)
F_86 ( V_9 ) ;
V_120 -> V_126 . V_132 = NULL ;
F_93 ( & V_97 ) ;
}
static void F_123 ( struct V_5 * V_6 )
{
struct V_92 * V_146 ;
F_91 ( & V_97 ) ;
while ( ( V_146 = F_124 ( & V_6 -> V_98 ) ) ) {
struct V_90 * V_81 =
F_67 ( V_146 , struct V_90 , V_92 ) ;
F_78 ( V_146 , & V_6 -> V_98 ) ;
V_81 -> V_103 = NULL ;
}
F_93 ( & V_97 ) ;
}
static void F_125 ( struct V_5 * V_6 )
{
F_91 ( & V_97 ) ;
F_104 ( & V_6 -> V_9 . V_116 , & V_6 -> V_133 ) ;
F_93 ( & V_97 ) ;
}
static int F_114 ( struct V_5 * V_6 )
{
int V_51 ;
V_6 -> V_147 = F_71 ( sizeof( * V_6 -> V_147 ) , V_138 ) ;
if ( ! V_6 -> V_147 )
return - V_57 ;
F_72 ( & V_6 -> V_147 -> V_102 , 1 ) ;
V_51 = F_42 ( & V_6 -> V_9 , V_6 , 1 , V_138 ) ;
if ( V_51 ) {
F_52 ( V_6 -> V_147 ) ;
return V_51 ;
}
return 0 ;
}
static void F_116 ( struct V_5 * V_6 ) { }
static void F_123 ( struct V_5 * V_6 )
{
F_52 ( V_6 -> V_147 ) ;
}
static void F_125 ( struct V_5 * V_6 )
{
F_104 ( & V_6 -> V_9 . V_116 , & V_6 -> V_133 ) ;
}
static void F_58 ( struct V_8 * V_9 )
{
F_92 ( & V_9 -> V_116 ) ;
}
static int F_35 ( struct V_5 * V_6 )
{
int V_41 ;
V_6 -> V_35 = NULL ;
F_126 ( & V_6 -> V_102 ) ;
V_6 -> V_148 = 0 ;
V_6 -> V_149 = 100 ;
V_6 -> V_150 = V_151 ;
F_44 ( & V_6 -> V_26 ) ;
F_44 ( & V_6 -> V_133 ) ;
F_127 ( & V_6 -> V_152 ) ;
V_41 = F_114 ( V_6 ) ;
return V_41 ;
}
struct V_5 * F_128 ( T_5 V_153 , int V_154 )
{
struct V_5 * V_6 ;
V_6 = F_129 ( sizeof( struct V_5 ) ,
V_153 | V_155 , V_154 ) ;
if ( ! V_6 )
return NULL ;
if ( F_35 ( V_6 ) ) {
F_74 ( V_6 ) ;
return NULL ;
}
return V_6 ;
}
int F_130 ( struct V_5 * V_6 , const char * V_156 , T_6 args )
{
struct V_34 * V_35 ;
if ( V_6 -> V_35 )
return 0 ;
V_35 = F_131 ( V_47 , NULL , F_132 ( 0 , 0 ) , V_6 , V_156 , args ) ;
if ( F_31 ( V_35 ) )
return F_32 ( V_35 ) ;
F_125 ( V_6 ) ;
V_6 -> V_35 = V_35 ;
F_15 ( V_6 , F_133 ( V_35 ) ) ;
F_57 ( V_62 , & V_6 -> V_9 . V_27 ) ;
F_38 ( & V_157 ) ;
F_104 ( & V_6 -> V_26 , & V_26 ) ;
F_41 ( & V_157 ) ;
F_134 ( V_6 ) ;
return 0 ;
}
int F_135 ( struct V_5 * V_6 , const char * V_156 , ... )
{
T_6 args ;
int V_41 ;
va_start ( args , V_156 ) ;
V_41 = F_130 ( V_6 , V_156 , args ) ;
va_end ( args ) ;
return V_41 ;
}
int F_136 ( struct V_5 * V_6 , struct V_34 * V_158 )
{
int V_159 ;
V_159 = F_135 ( V_6 , L_19 , F_137 ( V_158 -> V_160 ) , F_138 ( V_158 -> V_160 ) ) ;
if ( V_159 )
return V_159 ;
F_61 ( V_6 -> V_158 ) ;
V_6 -> V_158 = V_158 ;
F_139 ( V_158 ) ;
return 0 ;
}
static void F_140 ( struct V_5 * V_6 )
{
F_38 ( & V_157 ) ;
F_92 ( & V_6 -> V_26 ) ;
F_41 ( & V_157 ) ;
F_141 () ;
}
void F_142 ( struct V_5 * V_6 )
{
F_140 ( V_6 ) ;
F_54 ( & V_6 -> V_9 ) ;
F_116 ( V_6 ) ;
if ( V_6 -> V_35 ) {
F_17 ( V_6 ) ;
F_143 ( V_6 -> V_35 ) ;
V_6 -> V_35 = NULL ;
}
if ( V_6 -> V_158 ) {
F_144 ( V_6 -> V_158 ) ;
V_6 -> V_158 = NULL ;
}
}
static void F_145 ( struct V_161 * V_162 )
{
struct V_5 * V_6 =
F_80 ( V_162 , struct V_5 , V_102 ) ;
if ( F_39 ( V_62 , & V_6 -> V_9 . V_27 ) )
F_142 ( V_6 ) ;
F_146 ( V_6 -> V_35 ) ;
F_64 ( & V_6 -> V_9 ) ;
F_123 ( V_6 ) ;
F_74 ( V_6 ) ;
}
void F_53 ( struct V_5 * V_6 )
{
F_147 ( & V_6 -> V_102 , F_145 ) ;
}
void F_148 ( struct V_90 * V_81 , int V_163 )
{
T_7 * V_164 = & V_165 [ V_163 ] ;
enum V_166 V_167 ;
V_167 = V_163 ? V_168 : V_169 ;
if ( F_55 ( V_167 , & V_81 -> V_27 ) )
F_149 ( & V_170 [ V_163 ] ) ;
F_150 () ;
if ( F_151 ( V_164 ) )
F_152 ( V_164 ) ;
}
void F_153 ( struct V_90 * V_81 , int V_163 )
{
enum V_166 V_167 ;
V_167 = V_163 ? V_168 : V_169 ;
if ( ! F_154 ( V_167 , & V_81 -> V_27 ) )
F_73 ( & V_170 [ V_163 ] ) ;
}
long F_155 ( int V_163 , long V_59 )
{
long V_41 ;
unsigned long V_171 = V_68 ;
F_156 ( V_172 ) ;
T_7 * V_164 = & V_165 [ V_163 ] ;
F_157 ( V_164 , & V_172 , V_89 ) ;
V_41 = F_158 ( V_59 ) ;
F_159 ( V_164 , & V_172 ) ;
F_160 ( F_161 ( V_59 ) ,
F_161 ( V_68 - V_171 ) ) ;
return V_41 ;
}
long F_162 ( struct V_173 * V_174 , int V_163 , long V_59 )
{
long V_41 ;
unsigned long V_171 = V_68 ;
F_156 ( V_172 ) ;
T_7 * V_164 = & V_165 [ V_163 ] ;
if ( F_163 ( & V_170 [ V_163 ] ) == 0 ||
! F_39 ( V_175 , & V_174 -> V_95 ) ) {
F_164 () ;
V_41 = V_59 - ( V_68 - V_171 ) ;
if ( V_41 < 0 )
V_41 = 0 ;
goto V_176;
}
F_157 ( V_164 , & V_172 , V_89 ) ;
V_41 = F_158 ( V_59 ) ;
F_159 ( V_164 , & V_172 ) ;
V_176:
F_165 ( F_161 ( V_59 ) ,
F_161 ( V_68 - V_171 ) ) ;
return V_41 ;
}
int F_166 ( struct V_177 * V_178 , int V_179 ,
void T_8 * V_180 , T_3 * V_181 , T_9 * V_182 )
{
char V_183 [] = L_20 ;
if ( * V_182 || * V_181 < sizeof( V_183 ) ) {
* V_181 = 0 ;
return 0 ;
}
if ( F_167 ( V_180 , V_183 , sizeof( V_183 ) ) )
return - V_184 ;
F_168 ( L_21 ,
V_178 -> V_185 ) ;
* V_181 = 2 ;
* V_182 += * V_181 ;
return 2 ;
}

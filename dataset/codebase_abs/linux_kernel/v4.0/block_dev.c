static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , struct V_1 , V_3 ) ;
}
inline struct V_4 * F_3 ( struct V_2 * V_2 )
{
return & F_1 ( V_2 ) -> V_5 ;
}
static void F_4 ( struct V_2 * V_2 )
{
F_5 ( & V_2 -> V_6 ) ;
while ( V_2 -> V_7 & V_8 ) {
F_6 ( & V_2 -> V_6 ) ;
F_7 ( F_8 ( V_2 , true ) ) ;
F_5 ( & V_2 -> V_6 ) ;
}
F_6 ( & V_2 -> V_6 ) ;
}
void F_9 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 -> V_12 ;
if ( V_10 -> V_13 == 0 && V_10 -> V_14 == 0 )
return;
F_10 () ;
F_11 ( V_10 , 0 ) ;
}
void F_12 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 -> V_12 ;
if ( V_10 -> V_13 == 0 )
return;
F_10 () ;
F_13 () ;
F_14 ( V_10 , 0 , - 1 ) ;
F_15 ( V_10 ) ;
}
int F_16 ( struct V_4 * V_5 , int V_15 )
{
if ( V_15 > V_16 || V_15 < 512 || ! F_17 ( V_15 ) )
return - V_17 ;
if ( V_15 < F_18 ( V_5 ) )
return - V_17 ;
if ( V_5 -> V_18 != V_15 ) {
F_19 ( V_5 ) ;
V_5 -> V_18 = V_15 ;
V_5 -> V_11 -> V_19 = F_20 ( V_15 ) ;
F_9 ( V_5 ) ;
}
return 0 ;
}
int F_21 ( struct V_20 * V_21 , int V_15 )
{
if ( F_16 ( V_21 -> V_22 , V_15 ) )
return 0 ;
V_21 -> V_23 = V_15 ;
V_21 -> V_24 = F_20 ( V_15 ) ;
return V_21 -> V_23 ;
}
int F_22 ( struct V_20 * V_21 , int V_15 )
{
int V_25 = F_18 ( V_21 -> V_22 ) ;
if ( V_15 < V_25 )
V_15 = V_25 ;
return F_21 ( V_21 , V_15 ) ;
}
static int
F_23 ( struct V_2 * V_2 , T_1 V_26 ,
struct V_27 * V_28 , int V_29 )
{
V_28 -> V_30 = F_3 ( V_2 ) ;
V_28 -> V_31 = V_26 ;
F_24 ( V_28 ) ;
return 0 ;
}
static T_2
F_25 ( int V_32 , struct V_33 * V_34 , struct V_35 * V_36 ,
T_3 V_37 )
{
struct V_38 * V_38 = V_34 -> V_39 ;
struct V_2 * V_2 = V_38 -> V_40 -> V_41 ;
return F_26 ( V_32 , V_34 , V_2 , F_3 ( V_2 ) , V_36 ,
V_37 , F_23 ,
NULL , NULL , 0 ) ;
}
int F_27 ( struct V_4 * V_5 , int V_42 )
{
if ( ! V_5 )
return 0 ;
if ( ! V_42 )
return F_28 ( V_5 -> V_11 -> V_12 ) ;
return F_29 ( V_5 -> V_11 -> V_12 ) ;
}
int F_19 ( struct V_4 * V_5 )
{
return F_27 ( V_5 , 1 ) ;
}
int F_30 ( struct V_4 * V_5 )
{
struct V_20 * V_21 = F_31 ( V_5 ) ;
if ( V_21 ) {
int V_43 = F_32 ( V_21 ) ;
F_33 ( V_21 ) ;
return V_43 ;
}
return F_19 ( V_5 ) ;
}
struct V_20 * F_34 ( struct V_4 * V_5 )
{
struct V_20 * V_21 ;
int error = 0 ;
F_35 ( & V_5 -> V_44 ) ;
if ( ++ V_5 -> V_45 > 1 ) {
V_21 = F_31 ( V_5 ) ;
F_33 ( V_21 ) ;
F_36 ( & V_5 -> V_44 ) ;
return V_21 ;
}
V_21 = F_37 ( V_5 ) ;
if ( ! V_21 )
goto V_46;
if ( V_21 -> V_47 -> V_48 )
error = V_21 -> V_47 -> V_48 ( V_21 ) ;
else
error = V_48 ( V_21 ) ;
if ( error ) {
F_38 ( V_21 ) ;
V_5 -> V_45 -- ;
F_36 ( & V_5 -> V_44 ) ;
return F_39 ( error ) ;
}
F_38 ( V_21 ) ;
V_46:
F_19 ( V_5 ) ;
F_36 ( & V_5 -> V_44 ) ;
return V_21 ;
}
int F_40 ( struct V_4 * V_5 , struct V_20 * V_21 )
{
int error = - V_17 ;
F_35 ( & V_5 -> V_44 ) ;
if ( ! V_5 -> V_45 )
goto V_46;
error = 0 ;
if ( -- V_5 -> V_45 > 0 )
goto V_46;
if ( ! V_21 )
goto V_46;
if ( V_21 -> V_47 -> V_49 )
error = V_21 -> V_47 -> V_49 ( V_21 ) ;
else
error = V_49 ( V_21 ) ;
if ( error ) {
V_5 -> V_45 ++ ;
F_36 ( & V_5 -> V_44 ) ;
return error ;
}
V_46:
F_36 ( & V_5 -> V_44 ) ;
return 0 ;
}
static int F_41 ( struct V_50 * V_50 , struct V_51 * V_52 )
{
return F_42 ( V_50 , F_23 , V_52 ) ;
}
static int F_43 ( struct V_38 * V_38 , struct V_50 * V_50 )
{
return F_44 ( V_50 , F_23 ) ;
}
static int F_45 ( struct V_38 * V_38 , struct V_9 * V_10 ,
struct V_53 * V_54 , unsigned V_55 )
{
return F_46 ( V_10 , V_54 , V_55 , F_23 ) ;
}
static int F_47 ( struct V_38 * V_38 , struct V_9 * V_10 ,
T_3 V_56 , unsigned V_57 , unsigned V_58 ,
struct V_50 * * V_59 , void * * V_60 )
{
return F_48 ( V_10 , V_56 , V_57 , V_58 , V_59 ,
F_23 ) ;
}
static int F_49 ( struct V_38 * V_38 , struct V_9 * V_10 ,
T_3 V_56 , unsigned V_57 , unsigned V_61 ,
struct V_50 * V_50 , void * V_60 )
{
int V_62 ;
V_62 = F_50 ( V_38 , V_10 , V_56 , V_57 , V_61 , V_50 , V_60 ) ;
F_51 ( V_50 ) ;
F_52 ( V_50 ) ;
return V_62 ;
}
static T_3 F_53 ( struct V_38 * V_38 , T_3 V_37 , int V_63 )
{
struct V_2 * V_11 = V_38 -> V_40 -> V_41 ;
T_3 V_64 ;
F_35 ( & V_11 -> V_65 ) ;
V_64 = F_54 ( V_38 , V_37 , V_63 , F_55 ( V_11 ) ) ;
F_36 ( & V_11 -> V_65 ) ;
return V_64 ;
}
int F_56 ( struct V_38 * V_66 , T_3 V_67 , T_3 V_68 , int V_69 )
{
struct V_2 * V_11 = V_66 -> V_40 -> V_41 ;
struct V_4 * V_5 = F_3 ( V_11 ) ;
int error ;
error = F_57 ( V_66 -> V_40 , V_67 , V_68 ) ;
if ( error )
return error ;
error = F_58 ( V_5 , V_70 , NULL ) ;
if ( error == - V_71 )
error = 0 ;
return error ;
}
int F_59 ( struct V_4 * V_5 , T_1 V_72 ,
struct V_50 * V_50 )
{
const struct V_73 * V_74 = V_5 -> V_75 -> V_76 ;
if ( ! V_74 -> V_77 )
return - V_71 ;
return V_74 -> V_77 ( V_5 , V_72 + F_60 ( V_5 ) , V_50 , V_78 ) ;
}
int F_61 ( struct V_4 * V_5 , T_1 V_72 ,
struct V_50 * V_50 , struct V_51 * V_52 )
{
int V_79 ;
int V_32 = ( V_52 -> V_80 == V_81 ) ? V_82 : V_83 ;
const struct V_73 * V_74 = V_5 -> V_75 -> V_76 ;
if ( ! V_74 -> V_77 )
return - V_71 ;
F_62 ( V_50 ) ;
V_79 = V_74 -> V_77 ( V_5 , V_72 + F_60 ( V_5 ) , V_50 , V_32 ) ;
if ( V_79 )
F_63 ( V_50 ) ;
else
F_51 ( V_50 ) ;
return V_79 ;
}
long F_64 ( struct V_4 * V_5 , T_1 V_72 ,
void * * V_84 , unsigned long * V_85 , long V_15 )
{
long V_86 ;
const struct V_73 * V_74 = V_5 -> V_75 -> V_76 ;
if ( V_15 < 0 )
return V_15 ;
if ( ! V_74 -> V_87 )
return - V_71 ;
if ( ( V_72 + F_65 ( V_15 , 512 ) ) >
F_66 ( V_5 -> V_88 ) )
return - V_89 ;
V_72 += F_60 ( V_5 ) ;
if ( V_72 % ( V_16 / 512 ) )
return - V_17 ;
V_86 = V_74 -> V_87 ( V_5 , V_72 , V_84 , V_85 , V_15 ) ;
if ( ! V_86 )
return - V_89 ;
return F_67 ( V_86 , V_15 ) ;
}
static struct V_2 * F_68 ( struct V_20 * V_21 )
{
struct V_1 * V_90 = F_69 ( V_91 , V_70 ) ;
if ( ! V_90 )
return NULL ;
return & V_90 -> V_3 ;
}
static void F_70 ( struct V_92 * V_93 )
{
struct V_2 * V_2 = F_2 ( V_93 , struct V_2 , V_94 ) ;
struct V_1 * V_95 = F_1 ( V_2 ) ;
F_71 ( V_91 , V_95 ) ;
}
static void F_72 ( struct V_2 * V_2 )
{
F_73 ( & V_2 -> V_94 , F_70 ) ;
}
static void F_74 ( void * V_96 )
{
struct V_1 * V_90 = (struct V_1 * ) V_96 ;
struct V_4 * V_5 = & V_90 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_75 ( & V_5 -> V_97 ) ;
F_76 ( & V_5 -> V_98 ) ;
F_76 ( & V_5 -> V_99 ) ;
#ifdef F_77
F_76 ( & V_5 -> V_100 ) ;
#endif
F_78 ( & V_90 -> V_3 ) ;
F_75 ( & V_5 -> V_44 ) ;
}
static inline void F_79 ( struct V_2 * V_2 )
{
F_80 ( & V_2 -> V_101 ) ;
V_2 -> V_102 = NULL ;
V_2 -> V_12 = & V_2 -> V_103 ;
}
static void F_81 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
struct V_53 * V_104 ;
F_82 ( & V_2 -> V_103 ) ;
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
F_5 ( & V_105 ) ;
while ( ( V_104 = V_5 -> V_98 . V_106 ) != & V_5 -> V_98 ) {
F_79 ( F_85 ( V_104 , struct V_2 , V_101 ) ) ;
}
F_80 ( & V_5 -> V_99 ) ;
F_6 ( & V_105 ) ;
}
static struct V_107 * F_86 ( struct V_108 * V_109 ,
int V_58 , const char * V_110 , void * V_111 )
{
return F_87 ( V_109 , L_1 , & V_112 , NULL , V_113 ) ;
}
void T_4 F_88 ( void )
{
int V_114 ;
static struct V_115 * V_116 ;
V_91 = F_89 ( L_2 , sizeof( struct V_1 ) ,
0 , ( V_117 | V_118 |
V_119 | V_120 ) ,
F_74 ) ;
V_114 = F_90 ( & V_121 ) ;
if ( V_114 )
F_91 ( L_3 ) ;
V_116 = F_92 ( & V_121 ) ;
if ( F_93 ( V_116 ) )
F_91 ( L_4 ) ;
V_122 = V_116 -> V_123 ;
}
static inline unsigned long F_94 ( T_5 V_124 )
{
return F_95 ( V_124 ) + F_96 ( V_124 ) ;
}
static int F_97 ( struct V_2 * V_2 , void * V_111 )
{
return F_1 ( V_2 ) -> V_5 . V_125 == * ( T_5 * ) V_111 ;
}
static int F_98 ( struct V_2 * V_2 , void * V_111 )
{
F_1 ( V_2 ) -> V_5 . V_125 = * ( T_5 * ) V_111 ;
return 0 ;
}
struct V_4 * F_99 ( T_5 V_124 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_100 ( V_122 , F_94 ( V_124 ) ,
F_97 , F_98 , & V_124 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_7 & V_126 ) {
V_5 -> V_127 = NULL ;
V_5 -> V_128 = NULL ;
V_5 -> V_11 = V_2 ;
V_5 -> V_18 = ( 1 << V_2 -> V_19 ) ;
V_5 -> V_129 = 0 ;
V_5 -> V_130 = 0 ;
V_2 -> V_131 = V_132 ;
V_2 -> V_133 = V_124 ;
V_2 -> V_102 = V_5 ;
V_2 -> V_103 . V_134 = & V_135 ;
F_101 ( & V_2 -> V_103 , V_136 ) ;
F_5 ( & V_105 ) ;
F_102 ( & V_5 -> V_99 , & V_137 ) ;
F_6 ( & V_105 ) ;
F_103 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_104 ( struct V_4 * V_5 )
{
F_105 ( V_5 -> V_11 ) ;
return V_5 ;
}
long F_106 ( void )
{
struct V_4 * V_5 ;
long V_62 = 0 ;
F_5 ( & V_105 ) ;
F_107 (bdev, &all_bdevs, bd_list) {
V_62 += V_5 -> V_11 -> V_12 -> V_13 ;
}
F_6 ( & V_105 ) ;
return V_62 ;
}
void F_108 ( struct V_4 * V_5 )
{
F_109 ( V_5 -> V_11 ) ;
}
static struct V_4 * F_110 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_5 ( & V_105 ) ;
V_5 = V_2 -> V_102 ;
if ( V_5 ) {
F_105 ( V_5 -> V_11 ) ;
F_6 ( & V_105 ) ;
return V_5 ;
}
F_6 ( & V_105 ) ;
V_5 = F_99 ( V_2 -> V_133 ) ;
if ( V_5 ) {
F_5 ( & V_105 ) ;
if ( ! V_2 -> V_102 ) {
F_105 ( V_5 -> V_11 ) ;
V_2 -> V_102 = V_5 ;
V_2 -> V_12 = V_5 -> V_11 -> V_12 ;
F_102 ( & V_2 -> V_101 , & V_5 -> V_98 ) ;
}
F_6 ( & V_105 ) ;
}
return V_5 ;
}
int F_111 ( struct V_20 * V_21 )
{
return V_21 == V_122 ;
}
void F_112 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_5 ( & V_105 ) ;
if ( ! F_111 ( V_2 -> V_138 ) )
V_5 = V_2 -> V_102 ;
F_79 ( V_2 ) ;
F_6 ( & V_105 ) ;
if ( V_5 )
F_109 ( V_5 -> V_11 ) ;
}
static bool F_113 ( struct V_4 * V_5 , struct V_4 * V_139 ,
void * V_140 )
{
if ( V_5 -> V_141 == V_140 )
return true ;
else if ( V_5 -> V_141 != NULL )
return false ;
else if ( V_5 -> V_127 == V_5 )
return true ;
else if ( V_139 -> V_141 == F_113 )
return true ;
else if ( V_139 -> V_141 != NULL )
return false ;
else
return true ;
}
static int F_114 ( struct V_4 * V_5 ,
struct V_4 * V_139 , void * V_140 )
{
V_142:
if ( ! F_113 ( V_5 , V_139 , V_140 ) )
return - V_143 ;
if ( V_139 -> V_144 ) {
T_6 * V_145 = F_115 ( & V_139 -> V_144 , 0 ) ;
F_116 ( V_42 ) ;
F_117 ( V_145 , & V_42 , V_146 ) ;
F_6 ( & V_105 ) ;
F_118 () ;
F_119 ( V_145 , & V_42 ) ;
F_5 ( & V_105 ) ;
goto V_142;
}
return 0 ;
}
static struct V_4 * F_120 ( struct V_4 * V_5 ,
void * V_140 )
{
struct V_147 * V_148 ;
struct V_4 * V_139 ;
int V_149 , V_114 ;
F_121 () ;
V_148 = F_122 ( V_5 -> V_125 , & V_149 ) ;
if ( ! V_148 )
return F_39 ( - V_150 ) ;
if ( V_149 )
V_139 = F_123 ( V_148 , 0 ) ;
else
V_139 = F_104 ( V_5 ) ;
F_124 ( V_148 -> V_76 -> V_151 ) ;
F_125 ( V_148 ) ;
if ( ! V_139 )
return F_39 ( - V_152 ) ;
F_5 ( & V_105 ) ;
V_114 = F_114 ( V_5 , V_139 , V_140 ) ;
if ( V_114 == 0 ) {
V_139 -> V_144 = V_140 ;
F_6 ( & V_105 ) ;
return V_139 ;
} else {
F_6 ( & V_105 ) ;
F_108 ( V_139 ) ;
return F_39 ( V_114 ) ;
}
}
static struct V_153 * F_126 ( struct V_4 * V_5 ,
struct V_147 * V_148 )
{
struct V_153 * V_140 ;
F_107 (holder, &bdev->bd_holder_disks, list)
if ( V_140 -> V_148 == V_148 )
return V_140 ;
return NULL ;
}
static int F_127 ( struct V_154 * V_155 , struct V_154 * V_156 )
{
return F_128 ( V_155 , V_156 , F_129 ( V_156 ) ) ;
}
static void F_130 ( struct V_154 * V_155 , struct V_154 * V_156 )
{
F_131 ( V_155 , F_129 ( V_156 ) ) ;
}
int F_132 ( struct V_4 * V_5 , struct V_147 * V_148 )
{
struct V_153 * V_140 ;
int V_62 = 0 ;
F_35 ( & V_5 -> V_97 ) ;
F_7 ( ! V_5 -> V_141 ) ;
if ( F_133 ( ! V_148 -> V_157 || ! V_5 -> V_88 -> V_158 ) )
goto V_159;
V_140 = F_126 ( V_5 , V_148 ) ;
if ( V_140 ) {
V_140 -> V_160 ++ ;
goto V_159;
}
V_140 = F_134 ( sizeof( * V_140 ) , V_70 ) ;
if ( ! V_140 ) {
V_62 = - V_152 ;
goto V_159;
}
F_76 ( & V_140 -> V_161 ) ;
V_140 -> V_148 = V_148 ;
V_140 -> V_160 = 1 ;
V_62 = F_127 ( V_148 -> V_157 , & F_135 ( V_5 -> V_88 ) -> V_162 ) ;
if ( V_62 )
goto V_163;
V_62 = F_127 ( V_5 -> V_88 -> V_158 , & F_136 ( V_148 ) -> V_162 ) ;
if ( V_62 )
goto V_164;
F_137 ( V_5 -> V_88 -> V_158 ) ;
F_102 ( & V_140 -> V_161 , & V_5 -> V_100 ) ;
goto V_159;
V_164:
F_130 ( V_148 -> V_157 , & F_135 ( V_5 -> V_88 ) -> V_162 ) ;
V_163:
F_138 ( V_140 ) ;
V_159:
F_36 ( & V_5 -> V_97 ) ;
return V_62 ;
}
void F_139 ( struct V_4 * V_5 , struct V_147 * V_148 )
{
struct V_153 * V_140 ;
F_35 ( & V_5 -> V_97 ) ;
V_140 = F_126 ( V_5 , V_148 ) ;
if ( ! F_7 ( V_140 == NULL ) && ! -- V_140 -> V_160 ) {
F_130 ( V_148 -> V_157 , & F_135 ( V_5 -> V_88 ) -> V_162 ) ;
F_130 ( V_5 -> V_88 -> V_158 ,
& F_136 ( V_148 ) -> V_162 ) ;
F_140 ( V_5 -> V_88 -> V_158 ) ;
F_80 ( & V_140 -> V_161 ) ;
F_138 ( V_140 ) ;
}
F_36 ( & V_5 -> V_97 ) ;
}
static void F_141 ( struct V_4 * V_5 , bool V_165 )
{
if ( F_142 ( V_5 , V_165 ) ) {
char V_166 [ V_167 ] = L_5 ;
if ( V_5 -> V_75 )
F_143 ( V_5 -> V_75 , 0 , V_166 ) ;
F_144 ( V_168 L_6
L_7 , V_166 ) ;
}
if ( ! V_5 -> V_75 )
return;
if ( F_145 ( V_5 -> V_75 ) )
V_5 -> V_130 = 1 ;
}
void F_146 ( struct V_147 * V_148 , struct V_4 * V_5 )
{
T_3 V_169 , V_170 ;
V_169 = ( T_3 ) F_147 ( V_148 ) << 9 ;
V_170 = F_55 ( V_5 -> V_11 ) ;
if ( V_169 != V_170 ) {
char V_166 [ V_167 ] ;
F_143 ( V_148 , 0 , V_166 ) ;
F_144 ( V_171
L_8 ,
V_166 , V_170 , V_169 ) ;
F_148 ( V_5 -> V_11 , V_169 ) ;
F_141 ( V_5 , false ) ;
}
}
int F_149 ( struct V_147 * V_148 )
{
struct V_4 * V_5 ;
int V_62 = 0 ;
if ( V_148 -> V_76 -> F_149 )
V_62 = V_148 -> V_76 -> F_149 ( V_148 ) ;
V_5 = F_123 ( V_148 , 0 ) ;
if ( ! V_5 )
return V_62 ;
F_35 ( & V_5 -> V_97 ) ;
F_146 ( V_148 , V_5 ) ;
V_5 -> V_130 = 0 ;
F_36 ( & V_5 -> V_97 ) ;
F_108 ( V_5 ) ;
return V_62 ;
}
int F_150 ( struct V_4 * V_5 )
{
struct V_147 * V_148 = V_5 -> V_75 ;
const struct V_73 * V_172 = V_148 -> V_76 ;
unsigned int V_173 ;
V_173 = F_151 ( V_148 , V_174 |
V_175 ) ;
if ( ! ( V_173 & V_174 ) )
return 0 ;
F_141 ( V_5 , true ) ;
if ( V_172 -> F_149 )
V_172 -> F_149 ( V_5 -> V_75 ) ;
return 1 ;
}
void F_152 ( struct V_4 * V_5 , T_3 V_15 )
{
unsigned V_176 = F_18 ( V_5 ) ;
F_35 ( & V_5 -> V_11 -> V_65 ) ;
F_148 ( V_5 -> V_11 , V_15 ) ;
F_36 ( & V_5 -> V_11 -> V_65 ) ;
while ( V_176 < V_177 ) {
if ( V_15 & V_176 )
break;
V_176 <<= 1 ;
}
V_5 -> V_18 = V_176 ;
V_5 -> V_11 -> V_19 = F_20 ( V_176 ) ;
}
static int F_153 ( struct V_4 * V_5 , T_7 V_178 , int V_179 )
{
struct V_147 * V_148 ;
struct V_180 * V_151 ;
int V_62 ;
int V_149 ;
int V_181 = 0 ;
if ( V_178 & V_182 )
V_181 |= V_183 ;
if ( V_178 & V_184 )
V_181 |= V_185 ;
if ( ! V_179 ) {
V_62 = F_154 ( V_5 -> V_11 , V_181 ) ;
if ( V_62 != 0 ) {
F_108 ( V_5 ) ;
return V_62 ;
}
}
V_186:
V_62 = - V_150 ;
V_148 = F_122 ( V_5 -> V_125 , & V_149 ) ;
if ( ! V_148 )
goto V_46;
V_151 = V_148 -> V_76 -> V_151 ;
F_155 ( V_148 ) ;
F_156 ( & V_5 -> V_97 , V_179 ) ;
if ( ! V_5 -> V_187 ) {
V_5 -> V_75 = V_148 ;
V_5 -> V_188 = V_148 -> V_189 ;
V_5 -> V_127 = V_5 ;
if ( ! V_149 ) {
V_62 = - V_150 ;
V_5 -> V_88 = F_157 ( V_148 , V_149 ) ;
if ( ! V_5 -> V_88 )
goto V_190;
V_62 = 0 ;
if ( V_148 -> V_76 -> V_191 ) {
V_62 = V_148 -> V_76 -> V_191 ( V_5 , V_178 ) ;
if ( V_62 == - V_192 ) {
F_158 ( V_5 -> V_88 ) ;
V_5 -> V_88 = NULL ;
V_5 -> V_75 = NULL ;
V_5 -> V_188 = NULL ;
F_36 ( & V_5 -> V_97 ) ;
F_159 ( V_148 ) ;
F_125 ( V_148 ) ;
F_124 ( V_151 ) ;
goto V_186;
}
}
if ( ! V_62 )
F_152 ( V_5 , ( T_3 ) F_147 ( V_148 ) << 9 ) ;
if ( V_5 -> V_130 ) {
if ( ! V_62 )
F_160 ( V_148 , V_5 ) ;
else if ( V_62 == - V_193 )
F_161 ( V_148 , V_5 ) ;
}
if ( V_62 )
goto V_190;
} else {
struct V_4 * V_139 ;
V_139 = F_123 ( V_148 , 0 ) ;
V_62 = - V_152 ;
if ( ! V_139 )
goto V_190;
F_162 ( V_179 ) ;
V_62 = F_153 ( V_139 , V_178 , 1 ) ;
if ( V_62 )
goto V_190;
V_5 -> V_127 = V_139 ;
V_5 -> V_88 = F_157 ( V_148 , V_149 ) ;
if ( ! ( V_148 -> V_58 & V_194 ) ||
! V_5 -> V_88 || ! V_5 -> V_88 -> V_195 ) {
V_62 = - V_150 ;
goto V_190;
}
F_152 ( V_5 , ( T_3 ) V_5 -> V_88 -> V_195 << 9 ) ;
}
} else {
if ( V_5 -> V_127 == V_5 ) {
V_62 = 0 ;
if ( V_5 -> V_75 -> V_76 -> V_191 )
V_62 = V_5 -> V_75 -> V_76 -> V_191 ( V_5 , V_178 ) ;
if ( V_5 -> V_130 ) {
if ( ! V_62 )
F_160 ( V_5 -> V_75 , V_5 ) ;
else if ( V_62 == - V_193 )
F_161 ( V_5 -> V_75 , V_5 ) ;
}
if ( V_62 )
goto V_196;
}
F_125 ( V_148 ) ;
F_124 ( V_151 ) ;
}
V_5 -> V_187 ++ ;
if ( V_179 )
V_5 -> V_129 ++ ;
F_36 ( & V_5 -> V_97 ) ;
F_159 ( V_148 ) ;
return 0 ;
V_190:
F_158 ( V_5 -> V_88 ) ;
V_5 -> V_75 = NULL ;
V_5 -> V_88 = NULL ;
V_5 -> V_188 = NULL ;
if ( V_5 != V_5 -> V_127 )
F_163 ( V_5 -> V_127 , V_178 , 1 ) ;
V_5 -> V_127 = NULL ;
V_196:
F_36 ( & V_5 -> V_97 ) ;
F_159 ( V_148 ) ;
F_125 ( V_148 ) ;
F_124 ( V_151 ) ;
V_46:
F_108 ( V_5 ) ;
return V_62 ;
}
int F_164 ( struct V_4 * V_5 , T_7 V_178 , void * V_140 )
{
struct V_4 * V_139 = NULL ;
int V_43 ;
F_7 ( ( V_178 & V_197 ) && ! V_140 ) ;
if ( ( V_178 & V_197 ) && V_140 ) {
V_139 = F_120 ( V_5 , V_140 ) ;
if ( F_93 ( V_139 ) ) {
F_108 ( V_5 ) ;
return F_165 ( V_139 ) ;
}
}
V_43 = F_153 ( V_5 , V_178 , 0 ) ;
if ( V_139 ) {
struct V_147 * V_148 = V_139 -> V_75 ;
F_35 ( & V_5 -> V_97 ) ;
F_5 ( & V_105 ) ;
if ( ! V_43 ) {
F_162 ( ! F_113 ( V_5 , V_139 , V_140 ) ) ;
V_139 -> V_198 ++ ;
V_139 -> V_141 = F_113 ;
V_5 -> V_198 ++ ;
V_5 -> V_141 = V_140 ;
}
F_162 ( V_139 -> V_144 != V_140 ) ;
V_139 -> V_144 = NULL ;
F_166 ( & V_139 -> V_144 , 0 ) ;
F_6 ( & V_105 ) ;
if ( ! V_43 && ( V_178 & V_184 ) && ! V_5 -> V_199 &&
( V_148 -> V_58 & V_200 ) ) {
V_5 -> V_199 = true ;
F_155 ( V_148 ) ;
}
F_36 ( & V_5 -> V_97 ) ;
F_108 ( V_139 ) ;
}
return V_43 ;
}
struct V_4 * F_167 ( const char * V_201 , T_7 V_178 ,
void * V_140 )
{
struct V_4 * V_5 ;
int V_114 ;
V_5 = F_168 ( V_201 ) ;
if ( F_93 ( V_5 ) )
return V_5 ;
V_114 = F_164 ( V_5 , V_178 , V_140 ) ;
if ( V_114 )
return F_39 ( V_114 ) ;
if ( ( V_178 & V_184 ) && F_169 ( V_5 ) ) {
F_170 ( V_5 , V_178 ) ;
return F_39 ( - V_202 ) ;
}
return V_5 ;
}
struct V_4 * F_171 ( T_5 V_124 , T_7 V_178 , void * V_140 )
{
struct V_4 * V_5 ;
int V_114 ;
V_5 = F_99 ( V_124 ) ;
if ( ! V_5 )
return F_39 ( - V_152 ) ;
V_114 = F_164 ( V_5 , V_178 , V_140 ) ;
if ( V_114 )
return F_39 ( V_114 ) ;
return V_5 ;
}
static int F_172 ( struct V_2 * V_2 , struct V_38 * V_66 )
{
struct V_4 * V_5 ;
V_66 -> V_203 |= V_204 ;
if ( V_66 -> V_203 & V_205 )
V_66 -> V_206 |= V_207 ;
if ( V_66 -> V_203 & V_208 )
V_66 -> V_206 |= V_197 ;
if ( ( V_66 -> V_203 & V_209 ) == 3 )
V_66 -> V_206 |= V_210 ;
V_5 = F_110 ( V_2 ) ;
if ( V_5 == NULL )
return - V_152 ;
V_66 -> V_40 = V_5 -> V_11 -> V_12 ;
return F_164 ( V_5 , V_66 -> V_206 , V_66 ) ;
}
static void F_163 ( struct V_4 * V_5 , T_7 V_178 , int V_179 )
{
struct V_147 * V_148 = V_5 -> V_75 ;
struct V_4 * V_211 = NULL ;
F_156 ( & V_5 -> V_97 , V_179 ) ;
if ( V_179 )
V_5 -> V_129 -- ;
if ( ! -- V_5 -> V_187 ) {
F_7 ( V_5 -> V_198 ) ;
F_19 ( V_5 ) ;
F_9 ( V_5 ) ;
F_4 ( V_5 -> V_11 ) ;
}
if ( V_5 -> V_127 == V_5 ) {
if ( V_148 -> V_76 -> V_212 )
V_148 -> V_76 -> V_212 ( V_148 , V_178 ) ;
}
if ( ! V_5 -> V_187 ) {
struct V_180 * V_151 = V_148 -> V_76 -> V_151 ;
F_158 ( V_5 -> V_88 ) ;
V_5 -> V_88 = NULL ;
V_5 -> V_75 = NULL ;
if ( V_5 != V_5 -> V_127 )
V_211 = V_5 -> V_127 ;
V_5 -> V_127 = NULL ;
F_125 ( V_148 ) ;
F_124 ( V_151 ) ;
}
F_36 ( & V_5 -> V_97 ) ;
F_108 ( V_5 ) ;
if ( V_211 )
F_163 ( V_211 , V_178 , 1 ) ;
}
void F_170 ( struct V_4 * V_5 , T_7 V_178 )
{
F_35 ( & V_5 -> V_97 ) ;
if ( V_178 & V_197 ) {
bool V_213 ;
F_5 ( & V_105 ) ;
F_7 ( -- V_5 -> V_198 < 0 ) ;
F_7 ( -- V_5 -> V_127 -> V_198 < 0 ) ;
if ( ( V_213 = ! V_5 -> V_198 ) )
V_5 -> V_141 = NULL ;
if ( ! V_5 -> V_127 -> V_198 )
V_5 -> V_127 -> V_141 = NULL ;
F_6 ( & V_105 ) ;
if ( V_213 && V_5 -> V_199 ) {
F_159 ( V_5 -> V_75 ) ;
V_5 -> V_199 = false ;
}
}
F_173 ( V_5 -> V_75 , V_174 ) ;
F_36 ( & V_5 -> V_97 ) ;
F_163 ( V_5 , V_178 , 0 ) ;
}
static int F_174 ( struct V_2 * V_2 , struct V_38 * V_66 )
{
struct V_4 * V_5 = F_3 ( V_66 -> V_40 -> V_41 ) ;
F_170 ( V_5 , V_66 -> V_206 ) ;
return 0 ;
}
static long F_175 ( struct V_38 * V_38 , unsigned V_214 , unsigned long V_215 )
{
struct V_4 * V_5 = F_3 ( V_38 -> V_40 -> V_41 ) ;
T_7 V_178 = V_38 -> V_206 ;
if ( V_38 -> V_203 & V_205 )
V_178 |= V_207 ;
else
V_178 &= ~ V_207 ;
return F_176 ( V_5 , V_178 , V_214 , V_215 ) ;
}
T_2 F_177 ( struct V_33 * V_34 , struct V_35 * V_155 )
{
struct V_38 * V_38 = V_34 -> V_39 ;
struct V_216 V_217 ;
T_2 V_62 ;
F_178 ( & V_217 ) ;
V_62 = F_179 ( V_34 , V_155 ) ;
if ( V_62 > 0 ) {
T_2 V_114 ;
V_114 = F_180 ( V_38 , V_34 -> V_218 - V_62 , V_62 ) ;
if ( V_114 < 0 )
V_62 = V_114 ;
}
F_181 ( & V_217 ) ;
return V_62 ;
}
T_2 F_182 ( struct V_33 * V_34 , struct V_35 * V_156 )
{
struct V_38 * V_38 = V_34 -> V_39 ;
struct V_2 * V_11 = V_38 -> V_40 -> V_41 ;
T_3 V_15 = F_55 ( V_11 ) ;
T_3 V_56 = V_34 -> V_218 ;
if ( V_56 >= V_15 )
return 0 ;
V_15 -= V_56 ;
F_183 ( V_156 , V_15 ) ;
return F_184 ( V_34 , V_156 ) ;
}
static int F_185 ( struct V_50 * V_50 , T_8 V_42 )
{
struct V_20 * V_219 = F_1 ( V_50 -> V_10 -> V_41 ) -> V_5 . V_128 ;
if ( V_219 && V_219 -> V_47 -> V_220 )
return V_219 -> V_47 -> V_220 ( V_219 , V_50 , V_42 ) ;
return F_186 ( V_50 ) ;
}
int F_187 ( struct V_4 * V_5 , unsigned V_214 , unsigned long V_215 )
{
int V_43 ;
T_9 V_221 = F_188 () ;
F_189 ( V_222 ) ;
V_43 = F_176 ( V_5 , 0 , V_214 , V_215 ) ;
F_189 ( V_221 ) ;
return V_43 ;
}
struct V_4 * F_168 ( const char * V_223 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_201 V_201 ;
int error ;
if ( ! V_223 || ! * V_223 )
return F_39 ( - V_17 ) ;
error = F_190 ( V_223 , V_224 , & V_201 ) ;
if ( error )
return F_39 ( error ) ;
V_2 = V_201 . V_107 -> V_225 ;
error = - V_226 ;
if ( ! F_191 ( V_2 -> V_131 ) )
goto V_227;
error = - V_202 ;
if ( V_201 . V_228 -> V_229 & V_230 )
goto V_227;
error = - V_152 ;
V_5 = F_110 ( V_2 ) ;
if ( ! V_5 )
goto V_227;
V_46:
F_192 ( & V_201 ) ;
return V_5 ;
V_227:
V_5 = F_39 ( error ) ;
goto V_46;
}
int F_142 ( struct V_4 * V_5 , bool V_165 )
{
struct V_20 * V_21 = F_31 ( V_5 ) ;
int V_43 = 0 ;
if ( V_21 ) {
F_193 ( V_21 ) ;
V_43 = F_194 ( V_21 , V_165 ) ;
F_33 ( V_21 ) ;
}
F_12 ( V_5 ) ;
return V_43 ;
}
void F_195 ( void (* F_196)( struct V_4 * , void * ) , void * V_215 )
{
struct V_2 * V_2 , * V_231 = NULL ;
F_5 ( & V_232 ) ;
F_107 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_9 * V_10 = V_2 -> V_12 ;
F_5 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_7 & ( V_233 | V_234 | V_126 ) ||
V_10 -> V_13 == 0 ) {
F_6 ( & V_2 -> V_6 ) ;
continue;
}
F_197 ( V_2 ) ;
F_6 ( & V_2 -> V_6 ) ;
F_6 ( & V_232 ) ;
F_109 ( V_231 ) ;
V_231 = V_2 ;
F_196 ( F_3 ( V_2 ) , V_215 ) ;
F_5 ( & V_232 ) ;
}
F_6 ( & V_232 ) ;
F_109 ( V_231 ) ;
}

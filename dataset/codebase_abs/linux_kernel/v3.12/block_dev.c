static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , struct V_1 , V_3 ) ;
}
inline struct V_4 * F_3 ( struct V_2 * V_2 )
{
return & F_1 ( V_2 ) -> V_5 ;
}
static void F_4 ( struct V_2 * V_2 ,
struct V_6 * V_7 )
{
struct V_6 * V_8 = V_2 -> V_9 . V_6 ;
bool V_10 = false ;
if ( F_5 ( V_7 == V_8 ) )
return;
F_6 ( & V_8 -> V_11 , & V_7 -> V_11 ) ;
F_7 ( & V_2 -> V_12 ) ;
V_2 -> V_9 . V_6 = V_7 ;
if ( V_2 -> V_13 & V_14 ) {
if ( F_8 ( V_7 ) && ! F_9 ( & V_7 -> V_11 ) )
V_10 = true ;
F_10 ( & V_2 -> V_15 , & V_7 -> V_11 . V_16 ) ;
}
F_11 ( & V_2 -> V_12 ) ;
F_11 ( & V_8 -> V_11 . V_17 ) ;
F_11 ( & V_7 -> V_11 . V_17 ) ;
if ( V_10 )
F_12 ( V_7 ) ;
}
void F_13 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 -> V_21 ;
if ( V_19 -> V_22 == 0 )
return;
F_14 () ;
F_15 ( V_19 , 0 ) ;
}
void F_16 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 -> V_21 ;
if ( V_19 -> V_22 == 0 )
return;
F_14 () ;
F_17 () ;
F_18 ( V_19 , 0 , - 1 ) ;
F_19 ( V_19 ) ;
}
int F_20 ( struct V_4 * V_5 , int V_23 )
{
if ( V_23 > V_24 || V_23 < 512 || ! F_21 ( V_23 ) )
return - V_25 ;
if ( V_23 < F_22 ( V_5 ) )
return - V_25 ;
if ( V_5 -> V_26 != V_23 ) {
F_23 ( V_5 ) ;
V_5 -> V_26 = V_23 ;
V_5 -> V_20 -> V_27 = F_24 ( V_23 ) ;
F_13 ( V_5 ) ;
}
return 0 ;
}
int F_25 ( struct V_28 * V_29 , int V_23 )
{
if ( F_20 ( V_29 -> V_30 , V_23 ) )
return 0 ;
V_29 -> V_31 = V_23 ;
V_29 -> V_32 = F_24 ( V_23 ) ;
return V_29 -> V_31 ;
}
int F_26 ( struct V_28 * V_29 , int V_23 )
{
int V_33 = F_22 ( V_29 -> V_30 ) ;
if ( V_23 < V_33 )
V_23 = V_33 ;
return F_25 ( V_29 , V_23 ) ;
}
static int
F_27 ( struct V_2 * V_2 , T_1 V_34 ,
struct V_35 * V_36 , int V_37 )
{
V_36 -> V_38 = F_3 ( V_2 ) ;
V_36 -> V_39 = V_34 ;
F_28 ( V_36 ) ;
return 0 ;
}
static T_2
F_29 ( int V_40 , struct V_41 * V_42 , const struct V_43 * V_44 ,
T_3 V_45 , unsigned long V_46 )
{
struct V_47 * V_47 = V_42 -> V_48 ;
struct V_2 * V_2 = V_47 -> V_49 -> V_50 ;
return F_30 ( V_40 , V_42 , V_2 , F_3 ( V_2 ) , V_44 , V_45 ,
V_46 , F_27 , NULL , NULL , 0 ) ;
}
int F_31 ( struct V_4 * V_5 , int V_51 )
{
if ( ! V_5 )
return 0 ;
if ( ! V_51 )
return F_32 ( V_5 -> V_20 -> V_21 ) ;
return F_33 ( V_5 -> V_20 -> V_21 ) ;
}
int F_23 ( struct V_4 * V_5 )
{
return F_31 ( V_5 , 1 ) ;
}
int F_34 ( struct V_4 * V_5 )
{
struct V_28 * V_29 = F_35 ( V_5 ) ;
if ( V_29 ) {
int V_52 = F_36 ( V_29 ) ;
F_37 ( V_29 ) ;
return V_52 ;
}
return F_23 ( V_5 ) ;
}
struct V_28 * F_38 ( struct V_4 * V_5 )
{
struct V_28 * V_29 ;
int error = 0 ;
F_39 ( & V_5 -> V_53 ) ;
if ( ++ V_5 -> V_54 > 1 ) {
V_29 = F_35 ( V_5 ) ;
F_37 ( V_29 ) ;
F_40 ( & V_5 -> V_53 ) ;
return V_29 ;
}
V_29 = F_41 ( V_5 ) ;
if ( ! V_29 )
goto V_55;
error = F_42 ( V_29 ) ;
if ( error ) {
F_43 ( V_29 ) ;
V_5 -> V_54 -- ;
F_40 ( & V_5 -> V_53 ) ;
return F_44 ( error ) ;
}
F_43 ( V_29 ) ;
V_55:
F_23 ( V_5 ) ;
F_40 ( & V_5 -> V_53 ) ;
return V_29 ;
}
int F_45 ( struct V_4 * V_5 , struct V_28 * V_29 )
{
int error = - V_25 ;
F_39 ( & V_5 -> V_53 ) ;
if ( ! V_5 -> V_54 )
goto V_55;
error = 0 ;
if ( -- V_5 -> V_54 > 0 )
goto V_55;
if ( ! V_29 )
goto V_55;
error = F_46 ( V_29 ) ;
if ( error ) {
V_5 -> V_54 ++ ;
F_40 ( & V_5 -> V_53 ) ;
return error ;
}
V_55:
F_40 ( & V_5 -> V_53 ) ;
return 0 ;
}
static int F_47 ( struct V_56 * V_56 , struct V_57 * V_58 )
{
return F_48 ( V_56 , F_27 , V_58 ) ;
}
static int F_49 ( struct V_47 * V_47 , struct V_56 * V_56 )
{
return F_50 ( V_56 , F_27 ) ;
}
static int F_51 ( struct V_47 * V_47 , struct V_18 * V_19 ,
T_3 V_59 , unsigned V_60 , unsigned V_61 ,
struct V_56 * * V_62 , void * * V_63 )
{
return F_52 ( V_19 , V_59 , V_60 , V_61 , V_62 ,
F_27 ) ;
}
static int F_53 ( struct V_47 * V_47 , struct V_18 * V_19 ,
T_3 V_59 , unsigned V_60 , unsigned V_64 ,
struct V_56 * V_56 , void * V_63 )
{
int V_65 ;
V_65 = F_54 ( V_47 , V_19 , V_59 , V_60 , V_64 , V_56 , V_63 ) ;
F_55 ( V_56 ) ;
F_56 ( V_56 ) ;
return V_65 ;
}
static T_3 F_57 ( struct V_47 * V_47 , T_3 V_45 , int V_66 )
{
struct V_2 * V_20 = V_47 -> V_49 -> V_50 ;
T_3 V_67 ;
F_39 ( & V_20 -> V_68 ) ;
V_67 = F_58 ( V_47 , V_45 , V_66 , F_59 ( V_20 ) ) ;
F_40 ( & V_20 -> V_68 ) ;
return V_67 ;
}
int F_60 ( struct V_47 * V_69 , T_3 V_70 , T_3 V_71 , int V_72 )
{
struct V_2 * V_20 = V_69 -> V_49 -> V_50 ;
struct V_4 * V_5 = F_3 ( V_20 ) ;
int error ;
error = F_61 ( V_69 -> V_49 , V_70 , V_71 ) ;
if ( error )
return error ;
error = F_62 ( V_5 , V_73 , NULL ) ;
if ( error == - V_74 )
error = 0 ;
return error ;
}
static struct V_2 * F_63 ( struct V_28 * V_29 )
{
struct V_1 * V_75 = F_64 ( V_76 , V_73 ) ;
if ( ! V_75 )
return NULL ;
return & V_75 -> V_3 ;
}
static void F_65 ( struct V_77 * V_78 )
{
struct V_2 * V_2 = F_2 ( V_78 , struct V_2 , V_79 ) ;
struct V_1 * V_80 = F_1 ( V_2 ) ;
F_66 ( V_76 , V_80 ) ;
}
static void F_67 ( struct V_2 * V_2 )
{
F_68 ( & V_2 -> V_79 , F_65 ) ;
}
static void F_69 ( void * V_81 )
{
struct V_1 * V_75 = (struct V_1 * ) V_81 ;
struct V_4 * V_5 = & V_75 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_70 ( & V_5 -> V_82 ) ;
F_71 ( & V_5 -> V_83 ) ;
F_71 ( & V_5 -> V_84 ) ;
#ifdef F_72
F_71 ( & V_5 -> V_85 ) ;
#endif
F_73 ( & V_75 -> V_3 ) ;
F_70 ( & V_5 -> V_53 ) ;
}
static inline void F_74 ( struct V_2 * V_2 )
{
F_75 ( & V_2 -> V_86 ) ;
V_2 -> V_87 = NULL ;
V_2 -> V_21 = & V_2 -> V_9 ;
}
static void F_76 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
struct V_88 * V_89 ;
F_15 ( & V_2 -> V_9 , 0 ) ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
F_7 ( & V_90 ) ;
while ( ( V_89 = V_5 -> V_83 . V_91 ) != & V_5 -> V_83 ) {
F_74 ( F_79 ( V_89 , struct V_2 , V_86 ) ) ;
}
F_75 ( & V_5 -> V_84 ) ;
F_11 ( & V_90 ) ;
}
static struct V_92 * F_80 ( struct V_93 * V_94 ,
int V_61 , const char * V_95 , void * V_96 )
{
return F_81 ( V_94 , L_1 , & V_97 , NULL , V_98 ) ;
}
void T_4 F_82 ( void )
{
int V_99 ;
static struct V_100 * V_101 ;
V_76 = F_83 ( L_2 , sizeof( struct V_1 ) ,
0 , ( V_102 | V_103 |
V_104 | V_105 ) ,
F_69 ) ;
V_99 = F_84 ( & V_106 ) ;
if ( V_99 )
F_85 ( L_3 ) ;
V_101 = F_86 ( & V_106 ) ;
if ( F_87 ( V_101 ) )
F_85 ( L_4 ) ;
V_107 = V_101 -> V_108 ;
}
static inline unsigned long F_88 ( T_5 V_109 )
{
return F_89 ( V_109 ) + F_90 ( V_109 ) ;
}
static int F_91 ( struct V_2 * V_2 , void * V_96 )
{
return F_1 ( V_2 ) -> V_5 . V_110 == * ( T_5 * ) V_96 ;
}
static int F_92 ( struct V_2 * V_2 , void * V_96 )
{
F_1 ( V_2 ) -> V_5 . V_110 = * ( T_5 * ) V_96 ;
return 0 ;
}
struct V_4 * F_93 ( T_5 V_109 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_94 ( V_107 , F_88 ( V_109 ) ,
F_91 , F_92 , & V_109 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_13 & V_111 ) {
V_5 -> V_112 = NULL ;
V_5 -> V_113 = NULL ;
V_5 -> V_20 = V_2 ;
V_5 -> V_26 = ( 1 << V_2 -> V_27 ) ;
V_5 -> V_114 = 0 ;
V_5 -> V_115 = 0 ;
V_2 -> V_116 = V_117 ;
V_2 -> V_118 = V_109 ;
V_2 -> V_87 = V_5 ;
V_2 -> V_9 . V_119 = & V_120 ;
F_95 ( & V_2 -> V_9 , V_121 ) ;
V_2 -> V_9 . V_6 = & V_122 ;
F_7 ( & V_90 ) ;
F_96 ( & V_5 -> V_84 , & V_123 ) ;
F_11 ( & V_90 ) ;
F_97 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_98 ( struct V_4 * V_5 )
{
F_99 ( V_5 -> V_20 ) ;
return V_5 ;
}
long F_100 ( void )
{
struct V_4 * V_5 ;
long V_65 = 0 ;
F_7 ( & V_90 ) ;
F_101 (bdev, &all_bdevs, bd_list) {
V_65 += V_5 -> V_20 -> V_21 -> V_22 ;
}
F_11 ( & V_90 ) ;
return V_65 ;
}
void F_102 ( struct V_4 * V_5 )
{
F_103 ( V_5 -> V_20 ) ;
}
static struct V_4 * F_104 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_7 ( & V_90 ) ;
V_5 = V_2 -> V_87 ;
if ( V_5 ) {
F_99 ( V_5 -> V_20 ) ;
F_11 ( & V_90 ) ;
return V_5 ;
}
F_11 ( & V_90 ) ;
V_5 = F_93 ( V_2 -> V_118 ) ;
if ( V_5 ) {
F_7 ( & V_90 ) ;
if ( ! V_2 -> V_87 ) {
F_99 ( V_5 -> V_20 ) ;
V_2 -> V_87 = V_5 ;
V_2 -> V_21 = V_5 -> V_20 -> V_21 ;
F_96 ( & V_2 -> V_86 , & V_5 -> V_83 ) ;
}
F_11 ( & V_90 ) ;
}
return V_5 ;
}
int F_105 ( struct V_28 * V_29 )
{
return V_29 == V_107 ;
}
void F_106 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_7 ( & V_90 ) ;
if ( ! F_105 ( V_2 -> V_124 ) )
V_5 = V_2 -> V_87 ;
F_74 ( V_2 ) ;
F_11 ( & V_90 ) ;
if ( V_5 )
F_103 ( V_5 -> V_20 ) ;
}
static bool F_107 ( struct V_4 * V_5 , struct V_4 * V_125 ,
void * V_126 )
{
if ( V_5 -> V_127 == V_126 )
return true ;
else if ( V_5 -> V_127 != NULL )
return false ;
else if ( V_5 -> V_112 == V_5 )
return true ;
else if ( V_125 -> V_127 == F_107 )
return true ;
else if ( V_125 -> V_127 != NULL )
return false ;
else
return true ;
}
static int F_108 ( struct V_4 * V_5 ,
struct V_4 * V_125 , void * V_126 )
{
V_128:
if ( ! F_107 ( V_5 , V_125 , V_126 ) )
return - V_129 ;
if ( V_125 -> V_130 ) {
T_6 * V_131 = F_109 ( & V_125 -> V_130 , 0 ) ;
F_110 ( V_51 ) ;
F_111 ( V_131 , & V_51 , V_132 ) ;
F_11 ( & V_90 ) ;
F_112 () ;
F_113 ( V_131 , & V_51 ) ;
F_7 ( & V_90 ) ;
goto V_128;
}
return 0 ;
}
static struct V_4 * F_114 ( struct V_4 * V_5 ,
void * V_126 )
{
struct V_133 * V_134 ;
struct V_4 * V_125 ;
int V_135 , V_99 ;
F_115 () ;
V_134 = F_116 ( V_5 -> V_110 , & V_135 ) ;
if ( ! V_134 )
return F_44 ( - V_136 ) ;
if ( V_135 )
V_125 = F_117 ( V_134 , 0 ) ;
else
V_125 = F_98 ( V_5 ) ;
F_118 ( V_134 -> V_137 -> V_138 ) ;
F_119 ( V_134 ) ;
if ( ! V_125 )
return F_44 ( - V_139 ) ;
F_7 ( & V_90 ) ;
V_99 = F_108 ( V_5 , V_125 , V_126 ) ;
if ( V_99 == 0 ) {
V_125 -> V_130 = V_126 ;
F_11 ( & V_90 ) ;
return V_125 ;
} else {
F_11 ( & V_90 ) ;
F_102 ( V_125 ) ;
return F_44 ( V_99 ) ;
}
}
static struct V_140 * F_120 ( struct V_4 * V_5 ,
struct V_133 * V_134 )
{
struct V_140 * V_126 ;
F_101 (holder, &bdev->bd_holder_disks, list)
if ( V_126 -> V_134 == V_134 )
return V_126 ;
return NULL ;
}
static int F_121 ( struct V_141 * V_142 , struct V_141 * V_143 )
{
return F_122 ( V_142 , V_143 , F_123 ( V_143 ) ) ;
}
static void F_124 ( struct V_141 * V_142 , struct V_141 * V_143 )
{
F_125 ( V_142 , F_123 ( V_143 ) ) ;
}
int F_126 ( struct V_4 * V_5 , struct V_133 * V_134 )
{
struct V_140 * V_126 ;
int V_65 = 0 ;
F_39 ( & V_5 -> V_82 ) ;
F_127 ( ! V_5 -> V_127 ) ;
if ( F_128 ( ! V_134 -> V_144 || ! V_5 -> V_145 -> V_146 ) )
goto V_147;
V_126 = F_120 ( V_5 , V_134 ) ;
if ( V_126 ) {
V_126 -> V_148 ++ ;
goto V_147;
}
V_126 = F_129 ( sizeof( * V_126 ) , V_73 ) ;
if ( ! V_126 ) {
V_65 = - V_139 ;
goto V_147;
}
F_71 ( & V_126 -> V_149 ) ;
V_126 -> V_134 = V_134 ;
V_126 -> V_148 = 1 ;
V_65 = F_121 ( V_134 -> V_144 , & F_130 ( V_5 -> V_145 ) -> V_150 ) ;
if ( V_65 )
goto V_151;
V_65 = F_121 ( V_5 -> V_145 -> V_146 , & F_131 ( V_134 ) -> V_150 ) ;
if ( V_65 )
goto V_152;
F_132 ( V_5 -> V_145 -> V_146 ) ;
F_96 ( & V_126 -> V_149 , & V_5 -> V_85 ) ;
goto V_147;
V_152:
F_124 ( V_134 -> V_144 , & F_130 ( V_5 -> V_145 ) -> V_150 ) ;
V_151:
F_133 ( V_126 ) ;
V_147:
F_40 ( & V_5 -> V_82 ) ;
return V_65 ;
}
void F_134 ( struct V_4 * V_5 , struct V_133 * V_134 )
{
struct V_140 * V_126 ;
F_39 ( & V_5 -> V_82 ) ;
V_126 = F_120 ( V_5 , V_134 ) ;
if ( ! F_127 ( V_126 == NULL ) && ! -- V_126 -> V_148 ) {
F_124 ( V_134 -> V_144 , & F_130 ( V_5 -> V_145 ) -> V_150 ) ;
F_124 ( V_5 -> V_145 -> V_146 ,
& F_131 ( V_134 ) -> V_150 ) ;
F_135 ( V_5 -> V_145 -> V_146 ) ;
F_75 ( & V_126 -> V_149 ) ;
F_133 ( V_126 ) ;
}
F_40 ( & V_5 -> V_82 ) ;
}
static void F_136 ( struct V_4 * V_5 , bool V_153 )
{
if ( F_137 ( V_5 , V_153 ) ) {
char V_154 [ V_155 ] = L_5 ;
if ( V_5 -> V_156 )
F_138 ( V_5 -> V_156 , 0 , V_154 ) ;
F_139 ( V_157 L_6
L_7 , V_154 ) ;
}
if ( ! V_5 -> V_156 )
return;
if ( F_140 ( V_5 -> V_156 ) )
V_5 -> V_115 = 1 ;
}
void F_141 ( struct V_133 * V_134 , struct V_4 * V_5 )
{
T_3 V_158 , V_159 ;
V_158 = ( T_3 ) F_142 ( V_134 ) << 9 ;
V_159 = F_59 ( V_5 -> V_20 ) ;
if ( V_158 != V_159 ) {
char V_154 [ V_155 ] ;
F_138 ( V_134 , 0 , V_154 ) ;
F_139 ( V_160
L_8 ,
V_154 , V_159 , V_158 ) ;
F_143 ( V_5 -> V_20 , V_158 ) ;
F_136 ( V_5 , false ) ;
}
}
int F_144 ( struct V_133 * V_134 )
{
struct V_4 * V_5 ;
int V_65 = 0 ;
if ( V_134 -> V_137 -> F_144 )
V_65 = V_134 -> V_137 -> F_144 ( V_134 ) ;
V_5 = F_117 ( V_134 , 0 ) ;
if ( ! V_5 )
return V_65 ;
F_39 ( & V_5 -> V_82 ) ;
F_141 ( V_134 , V_5 ) ;
V_5 -> V_115 = 0 ;
F_40 ( & V_5 -> V_82 ) ;
F_102 ( V_5 ) ;
return V_65 ;
}
int F_145 ( struct V_4 * V_5 )
{
struct V_133 * V_134 = V_5 -> V_156 ;
const struct V_161 * V_162 = V_134 -> V_137 ;
unsigned int V_163 ;
V_163 = F_146 ( V_134 , V_164 |
V_165 ) ;
if ( ! ( V_163 & V_164 ) )
return 0 ;
F_136 ( V_5 , true ) ;
if ( V_162 -> F_144 )
V_162 -> F_144 ( V_5 -> V_156 ) ;
return 1 ;
}
void F_147 ( struct V_4 * V_5 , T_3 V_23 )
{
unsigned V_166 = F_22 ( V_5 ) ;
F_39 ( & V_5 -> V_20 -> V_68 ) ;
F_143 ( V_5 -> V_20 , V_23 ) ;
F_40 ( & V_5 -> V_20 -> V_68 ) ;
while ( V_166 < V_167 ) {
if ( V_23 & V_166 )
break;
V_166 <<= 1 ;
}
V_5 -> V_26 = V_166 ;
V_5 -> V_20 -> V_27 = F_24 ( V_166 ) ;
}
static int F_148 ( struct V_4 * V_5 , T_7 V_168 , int V_169 )
{
struct V_133 * V_134 ;
struct V_170 * V_138 ;
int V_65 ;
int V_135 ;
int V_171 = 0 ;
if ( V_168 & V_172 )
V_171 |= V_173 ;
if ( V_168 & V_174 )
V_171 |= V_175 ;
if ( ! V_169 ) {
V_65 = F_149 ( V_5 -> V_20 , V_171 ) ;
if ( V_65 != 0 ) {
F_102 ( V_5 ) ;
return V_65 ;
}
}
V_176:
V_65 = - V_136 ;
V_134 = F_116 ( V_5 -> V_110 , & V_135 ) ;
if ( ! V_134 )
goto V_55;
V_138 = V_134 -> V_137 -> V_138 ;
F_150 ( V_134 ) ;
F_151 ( & V_5 -> V_82 , V_169 ) ;
if ( ! V_5 -> V_177 ) {
V_5 -> V_156 = V_134 ;
V_5 -> V_178 = V_134 -> V_179 ;
V_5 -> V_112 = V_5 ;
if ( ! V_135 ) {
struct V_6 * V_80 ;
V_65 = - V_136 ;
V_5 -> V_145 = F_152 ( V_134 , V_135 ) ;
if ( ! V_5 -> V_145 )
goto V_180;
V_65 = 0 ;
if ( V_134 -> V_137 -> V_181 ) {
V_65 = V_134 -> V_137 -> V_181 ( V_5 , V_168 ) ;
if ( V_65 == - V_182 ) {
F_153 ( V_5 -> V_145 ) ;
V_5 -> V_145 = NULL ;
V_5 -> V_156 = NULL ;
V_5 -> V_178 = NULL ;
F_40 ( & V_5 -> V_82 ) ;
F_154 ( V_134 ) ;
F_119 ( V_134 ) ;
F_118 ( V_138 ) ;
goto V_176;
}
}
if ( ! V_65 ) {
F_147 ( V_5 , ( T_3 ) F_142 ( V_134 ) << 9 ) ;
V_80 = F_155 ( V_5 ) ;
if ( V_80 == NULL )
V_80 = & V_122 ;
F_4 ( V_5 -> V_20 , V_80 ) ;
}
if ( V_5 -> V_115 ) {
if ( ! V_65 )
F_156 ( V_134 , V_5 ) ;
else if ( V_65 == - V_183 )
F_157 ( V_134 , V_5 ) ;
}
if ( V_65 )
goto V_180;
} else {
struct V_4 * V_125 ;
V_125 = F_117 ( V_134 , 0 ) ;
V_65 = - V_139 ;
if ( ! V_125 )
goto V_180;
F_158 ( V_169 ) ;
V_65 = F_148 ( V_125 , V_168 , 1 ) ;
if ( V_65 )
goto V_180;
V_5 -> V_112 = V_125 ;
F_4 ( V_5 -> V_20 ,
V_125 -> V_20 -> V_9 . V_6 ) ;
V_5 -> V_145 = F_152 ( V_134 , V_135 ) ;
if ( ! ( V_134 -> V_61 & V_184 ) ||
! V_5 -> V_145 || ! V_5 -> V_145 -> V_185 ) {
V_65 = - V_136 ;
goto V_180;
}
F_147 ( V_5 , ( T_3 ) V_5 -> V_145 -> V_185 << 9 ) ;
}
} else {
if ( V_5 -> V_112 == V_5 ) {
V_65 = 0 ;
if ( V_5 -> V_156 -> V_137 -> V_181 )
V_65 = V_5 -> V_156 -> V_137 -> V_181 ( V_5 , V_168 ) ;
if ( V_5 -> V_115 ) {
if ( ! V_65 )
F_156 ( V_5 -> V_156 , V_5 ) ;
else if ( V_65 == - V_183 )
F_157 ( V_5 -> V_156 , V_5 ) ;
}
if ( V_65 )
goto V_186;
}
F_119 ( V_134 ) ;
F_118 ( V_138 ) ;
}
V_5 -> V_177 ++ ;
if ( V_169 )
V_5 -> V_114 ++ ;
F_40 ( & V_5 -> V_82 ) ;
F_154 ( V_134 ) ;
return 0 ;
V_180:
F_153 ( V_5 -> V_145 ) ;
V_5 -> V_156 = NULL ;
V_5 -> V_145 = NULL ;
V_5 -> V_178 = NULL ;
F_4 ( V_5 -> V_20 , & V_122 ) ;
if ( V_5 != V_5 -> V_112 )
F_159 ( V_5 -> V_112 , V_168 , 1 ) ;
V_5 -> V_112 = NULL ;
V_186:
F_40 ( & V_5 -> V_82 ) ;
F_154 ( V_134 ) ;
F_119 ( V_134 ) ;
F_118 ( V_138 ) ;
V_55:
F_102 ( V_5 ) ;
return V_65 ;
}
int F_160 ( struct V_4 * V_5 , T_7 V_168 , void * V_126 )
{
struct V_4 * V_125 = NULL ;
int V_52 ;
F_127 ( ( V_168 & V_187 ) && ! V_126 ) ;
if ( ( V_168 & V_187 ) && V_126 ) {
V_125 = F_114 ( V_5 , V_126 ) ;
if ( F_87 ( V_125 ) ) {
F_102 ( V_5 ) ;
return F_161 ( V_125 ) ;
}
}
V_52 = F_148 ( V_5 , V_168 , 0 ) ;
if ( V_125 ) {
struct V_133 * V_134 = V_125 -> V_156 ;
F_39 ( & V_5 -> V_82 ) ;
F_7 ( & V_90 ) ;
if ( ! V_52 ) {
F_158 ( ! F_107 ( V_5 , V_125 , V_126 ) ) ;
V_125 -> V_188 ++ ;
V_125 -> V_127 = F_107 ;
V_5 -> V_188 ++ ;
V_5 -> V_127 = V_126 ;
}
F_158 ( V_125 -> V_130 != V_126 ) ;
V_125 -> V_130 = NULL ;
F_162 ( & V_125 -> V_130 , 0 ) ;
F_11 ( & V_90 ) ;
if ( ! V_52 && ( V_168 & V_174 ) && ! V_5 -> V_189 &&
( V_134 -> V_61 & V_190 ) ) {
V_5 -> V_189 = true ;
F_150 ( V_134 ) ;
}
F_40 ( & V_5 -> V_82 ) ;
F_102 ( V_125 ) ;
}
return V_52 ;
}
struct V_4 * F_163 ( const char * V_191 , T_7 V_168 ,
void * V_126 )
{
struct V_4 * V_5 ;
int V_99 ;
V_5 = F_164 ( V_191 ) ;
if ( F_87 ( V_5 ) )
return V_5 ;
V_99 = F_160 ( V_5 , V_168 , V_126 ) ;
if ( V_99 )
return F_44 ( V_99 ) ;
if ( ( V_168 & V_174 ) && F_165 ( V_5 ) ) {
F_166 ( V_5 , V_168 ) ;
return F_44 ( - V_192 ) ;
}
return V_5 ;
}
struct V_4 * F_167 ( T_5 V_109 , T_7 V_168 , void * V_126 )
{
struct V_4 * V_5 ;
int V_99 ;
V_5 = F_93 ( V_109 ) ;
if ( ! V_5 )
return F_44 ( - V_139 ) ;
V_99 = F_160 ( V_5 , V_168 , V_126 ) ;
if ( V_99 )
return F_44 ( V_99 ) ;
return V_5 ;
}
static int F_168 ( struct V_2 * V_2 , struct V_47 * V_69 )
{
struct V_4 * V_5 ;
V_69 -> V_193 |= V_194 ;
if ( V_69 -> V_193 & V_195 )
V_69 -> V_196 |= V_197 ;
if ( V_69 -> V_193 & V_198 )
V_69 -> V_196 |= V_187 ;
if ( ( V_69 -> V_193 & V_199 ) == 3 )
V_69 -> V_196 |= V_200 ;
V_5 = F_104 ( V_2 ) ;
if ( V_5 == NULL )
return - V_139 ;
V_69 -> V_49 = V_5 -> V_20 -> V_21 ;
return F_160 ( V_5 , V_69 -> V_196 , V_69 ) ;
}
static void F_159 ( struct V_4 * V_5 , T_7 V_168 , int V_169 )
{
struct V_133 * V_134 = V_5 -> V_156 ;
struct V_4 * V_201 = NULL ;
F_151 ( & V_5 -> V_82 , V_169 ) ;
if ( V_169 )
V_5 -> V_114 -- ;
if ( ! -- V_5 -> V_177 ) {
F_127 ( V_5 -> V_188 ) ;
F_23 ( V_5 ) ;
F_13 ( V_5 ) ;
F_4 ( V_5 -> V_20 ,
& V_122 ) ;
}
if ( V_5 -> V_112 == V_5 ) {
if ( V_134 -> V_137 -> V_202 )
V_134 -> V_137 -> V_202 ( V_134 , V_168 ) ;
}
if ( ! V_5 -> V_177 ) {
struct V_170 * V_138 = V_134 -> V_137 -> V_138 ;
F_153 ( V_5 -> V_145 ) ;
V_5 -> V_145 = NULL ;
V_5 -> V_156 = NULL ;
if ( V_5 != V_5 -> V_112 )
V_201 = V_5 -> V_112 ;
V_5 -> V_112 = NULL ;
F_119 ( V_134 ) ;
F_118 ( V_138 ) ;
}
F_40 ( & V_5 -> V_82 ) ;
F_102 ( V_5 ) ;
if ( V_201 )
F_159 ( V_201 , V_168 , 1 ) ;
}
void F_166 ( struct V_4 * V_5 , T_7 V_168 )
{
F_39 ( & V_5 -> V_82 ) ;
if ( V_168 & V_187 ) {
bool V_203 ;
F_7 ( & V_90 ) ;
F_127 ( -- V_5 -> V_188 < 0 ) ;
F_127 ( -- V_5 -> V_112 -> V_188 < 0 ) ;
if ( ( V_203 = ! V_5 -> V_188 ) )
V_5 -> V_127 = NULL ;
if ( ! V_5 -> V_112 -> V_188 )
V_5 -> V_112 -> V_127 = NULL ;
F_11 ( & V_90 ) ;
if ( V_203 && V_5 -> V_189 ) {
F_154 ( V_5 -> V_156 ) ;
V_5 -> V_189 = false ;
}
}
F_169 ( V_5 -> V_156 , V_164 ) ;
F_40 ( & V_5 -> V_82 ) ;
F_159 ( V_5 , V_168 , 0 ) ;
}
static int F_170 ( struct V_2 * V_2 , struct V_47 * V_69 )
{
struct V_4 * V_5 = F_3 ( V_69 -> V_49 -> V_50 ) ;
F_166 ( V_5 , V_69 -> V_196 ) ;
return 0 ;
}
static long F_171 ( struct V_47 * V_47 , unsigned V_204 , unsigned long V_205 )
{
struct V_4 * V_5 = F_3 ( V_47 -> V_49 -> V_50 ) ;
T_7 V_168 = V_47 -> V_196 ;
if ( V_47 -> V_193 & V_195 )
V_168 |= V_197 ;
else
V_168 &= ~ V_197 ;
return F_172 ( V_5 , V_168 , V_204 , V_205 ) ;
}
T_2 F_173 ( struct V_41 * V_42 , const struct V_43 * V_44 ,
unsigned long V_46 , T_3 V_59 )
{
struct V_47 * V_47 = V_42 -> V_48 ;
struct V_206 V_207 ;
T_2 V_65 ;
F_158 ( V_42 -> V_208 != V_59 ) ;
F_174 ( & V_207 ) ;
V_65 = F_175 ( V_42 , V_44 , V_46 , & V_42 -> V_208 ) ;
if ( V_65 > 0 ) {
T_2 V_99 ;
V_99 = F_176 ( V_47 , V_59 , V_65 ) ;
if ( V_99 < 0 && V_65 > 0 )
V_65 = V_99 ;
}
F_177 ( & V_207 ) ;
return V_65 ;
}
static T_2 F_178 ( struct V_41 * V_42 , const struct V_43 * V_44 ,
unsigned long V_46 , T_3 V_59 )
{
struct V_47 * V_47 = V_42 -> V_48 ;
struct V_2 * V_20 = V_47 -> V_49 -> V_50 ;
T_3 V_23 = F_59 ( V_20 ) ;
if ( V_59 >= V_23 )
return 0 ;
V_23 -= V_59 ;
if ( V_23 < V_42 -> V_209 )
V_46 = F_179 ( (struct V_43 * ) V_44 , V_46 , V_23 ) ;
return F_180 ( V_42 , V_44 , V_46 , V_59 ) ;
}
static int F_181 ( struct V_56 * V_56 , T_8 V_51 )
{
struct V_28 * V_210 = F_1 ( V_56 -> V_19 -> V_50 ) -> V_5 . V_113 ;
if ( V_210 && V_210 -> V_211 -> V_212 )
return V_210 -> V_211 -> V_212 ( V_210 , V_56 , V_51 ) ;
return F_182 ( V_56 ) ;
}
int F_183 ( struct V_4 * V_5 , unsigned V_204 , unsigned long V_205 )
{
int V_52 ;
T_9 V_213 = F_184 () ;
F_185 ( V_214 ) ;
V_52 = F_172 ( V_5 , 0 , V_204 , V_205 ) ;
F_185 ( V_213 ) ;
return V_52 ;
}
struct V_4 * F_164 ( const char * V_215 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_191 V_191 ;
int error ;
if ( ! V_215 || ! * V_215 )
return F_44 ( - V_25 ) ;
error = F_186 ( V_215 , V_216 , & V_191 ) ;
if ( error )
return F_44 ( error ) ;
V_2 = V_191 . V_92 -> V_217 ;
error = - V_218 ;
if ( ! F_187 ( V_2 -> V_116 ) )
goto V_219;
error = - V_192 ;
if ( V_191 . V_220 -> V_221 & V_222 )
goto V_219;
error = - V_139 ;
V_5 = F_104 ( V_2 ) ;
if ( ! V_5 )
goto V_219;
V_55:
F_188 ( & V_191 ) ;
return V_5 ;
V_219:
V_5 = F_44 ( error ) ;
goto V_55;
}
int F_137 ( struct V_4 * V_5 , bool V_153 )
{
struct V_28 * V_29 = F_35 ( V_5 ) ;
int V_52 = 0 ;
if ( V_29 ) {
F_189 ( V_29 ) ;
V_52 = F_190 ( V_29 , V_153 ) ;
F_37 ( V_29 ) ;
}
F_16 ( V_5 ) ;
return V_52 ;
}
void F_191 ( void (* F_192)( struct V_4 * , void * ) , void * V_205 )
{
struct V_2 * V_2 , * V_223 = NULL ;
F_7 ( & V_224 ) ;
F_101 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_18 * V_19 = V_2 -> V_21 ;
F_7 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 & ( V_225 | V_226 | V_111 ) ||
V_19 -> V_22 == 0 ) {
F_11 ( & V_2 -> V_12 ) ;
continue;
}
F_193 ( V_2 ) ;
F_11 ( & V_2 -> V_12 ) ;
F_11 ( & V_224 ) ;
F_103 ( V_223 ) ;
V_223 = V_2 ;
F_192 ( F_3 ( V_2 ) , V_205 ) ;
F_7 ( & V_224 ) ;
}
F_11 ( & V_224 ) ;
F_103 ( V_223 ) ;
}

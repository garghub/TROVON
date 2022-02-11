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
while ( true ) {
F_5 ( & V_2 -> V_8 ) ;
if ( ! ( V_2 -> V_9 & V_10 ) ) {
V_2 -> V_11 . V_6 = V_7 ;
F_6 ( & V_2 -> V_8 ) ;
return;
}
F_6 ( & V_2 -> V_8 ) ;
F_7 ( F_8 ( V_2 , true ) ) ;
}
}
void F_9 ( struct V_4 * V_5 )
{
struct V_12 * V_13 = V_5 -> V_14 -> V_15 ;
if ( V_13 -> V_16 == 0 && V_13 -> V_17 == 0 )
return;
F_10 () ;
F_11 ( V_13 , 0 ) ;
}
void F_12 ( struct V_4 * V_5 )
{
struct V_12 * V_13 = V_5 -> V_14 -> V_15 ;
if ( V_13 -> V_16 == 0 )
return;
F_10 () ;
F_13 () ;
F_14 ( V_13 , 0 , - 1 ) ;
F_15 ( V_13 ) ;
}
int F_16 ( struct V_4 * V_5 , int V_18 )
{
if ( V_18 > V_19 || V_18 < 512 || ! F_17 ( V_18 ) )
return - V_20 ;
if ( V_18 < F_18 ( V_5 ) )
return - V_20 ;
if ( V_5 -> V_21 != V_18 ) {
F_19 ( V_5 ) ;
V_5 -> V_21 = V_18 ;
V_5 -> V_14 -> V_22 = F_20 ( V_18 ) ;
F_9 ( V_5 ) ;
}
return 0 ;
}
int F_21 ( struct V_23 * V_24 , int V_18 )
{
if ( F_16 ( V_24 -> V_25 , V_18 ) )
return 0 ;
V_24 -> V_26 = V_18 ;
V_24 -> V_27 = F_20 ( V_18 ) ;
return V_24 -> V_26 ;
}
int F_22 ( struct V_23 * V_24 , int V_18 )
{
int V_28 = F_18 ( V_24 -> V_25 ) ;
if ( V_18 < V_28 )
V_18 = V_28 ;
return F_21 ( V_24 , V_18 ) ;
}
static int
F_23 ( struct V_2 * V_2 , T_1 V_29 ,
struct V_30 * V_31 , int V_32 )
{
V_31 -> V_33 = F_3 ( V_2 ) ;
V_31 -> V_34 = V_29 ;
F_24 ( V_31 ) ;
return 0 ;
}
static T_2
F_25 ( int V_35 , struct V_36 * V_37 , struct V_38 * V_39 ,
T_3 V_40 )
{
struct V_41 * V_41 = V_37 -> V_42 ;
struct V_2 * V_2 = V_41 -> V_43 -> V_44 ;
return F_26 ( V_35 , V_37 , V_2 , F_3 ( V_2 ) , V_39 ,
V_40 , F_23 ,
NULL , NULL , 0 ) ;
}
int F_27 ( struct V_4 * V_5 , int V_45 )
{
if ( ! V_5 )
return 0 ;
if ( ! V_45 )
return F_28 ( V_5 -> V_14 -> V_15 ) ;
return F_29 ( V_5 -> V_14 -> V_15 ) ;
}
int F_19 ( struct V_4 * V_5 )
{
return F_27 ( V_5 , 1 ) ;
}
int F_30 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = F_31 ( V_5 ) ;
if ( V_24 ) {
int V_46 = F_32 ( V_24 ) ;
F_33 ( V_24 ) ;
return V_46 ;
}
return F_19 ( V_5 ) ;
}
struct V_23 * F_34 ( struct V_4 * V_5 )
{
struct V_23 * V_24 ;
int error = 0 ;
F_35 ( & V_5 -> V_47 ) ;
if ( ++ V_5 -> V_48 > 1 ) {
V_24 = F_31 ( V_5 ) ;
F_33 ( V_24 ) ;
F_36 ( & V_5 -> V_47 ) ;
return V_24 ;
}
V_24 = F_37 ( V_5 ) ;
if ( ! V_24 )
goto V_49;
error = F_38 ( V_24 ) ;
if ( error ) {
F_39 ( V_24 ) ;
V_5 -> V_48 -- ;
F_36 ( & V_5 -> V_47 ) ;
return F_40 ( error ) ;
}
F_39 ( V_24 ) ;
V_49:
F_19 ( V_5 ) ;
F_36 ( & V_5 -> V_47 ) ;
return V_24 ;
}
int F_41 ( struct V_4 * V_5 , struct V_23 * V_24 )
{
int error = - V_20 ;
F_35 ( & V_5 -> V_47 ) ;
if ( ! V_5 -> V_48 )
goto V_49;
error = 0 ;
if ( -- V_5 -> V_48 > 0 )
goto V_49;
if ( ! V_24 )
goto V_49;
error = F_42 ( V_24 ) ;
if ( error ) {
V_5 -> V_48 ++ ;
F_36 ( & V_5 -> V_47 ) ;
return error ;
}
V_49:
F_36 ( & V_5 -> V_47 ) ;
return 0 ;
}
static int F_43 ( struct V_50 * V_50 , struct V_51 * V_52 )
{
return F_44 ( V_50 , F_23 , V_52 ) ;
}
static int F_45 ( struct V_41 * V_41 , struct V_50 * V_50 )
{
return F_46 ( V_50 , F_23 ) ;
}
static int F_47 ( struct V_41 * V_41 , struct V_12 * V_13 ,
struct V_53 * V_54 , unsigned V_55 )
{
return F_48 ( V_13 , V_54 , V_55 , F_23 ) ;
}
static int F_49 ( struct V_41 * V_41 , struct V_12 * V_13 ,
T_3 V_56 , unsigned V_57 , unsigned V_58 ,
struct V_50 * * V_59 , void * * V_60 )
{
return F_50 ( V_13 , V_56 , V_57 , V_58 , V_59 ,
F_23 ) ;
}
static int F_51 ( struct V_41 * V_41 , struct V_12 * V_13 ,
T_3 V_56 , unsigned V_57 , unsigned V_61 ,
struct V_50 * V_50 , void * V_60 )
{
int V_62 ;
V_62 = F_52 ( V_41 , V_13 , V_56 , V_57 , V_61 , V_50 , V_60 ) ;
F_53 ( V_50 ) ;
F_54 ( V_50 ) ;
return V_62 ;
}
static T_3 F_55 ( struct V_41 * V_41 , T_3 V_40 , int V_63 )
{
struct V_2 * V_14 = V_41 -> V_43 -> V_44 ;
T_3 V_64 ;
F_35 ( & V_14 -> V_65 ) ;
V_64 = F_56 ( V_41 , V_40 , V_63 , F_57 ( V_14 ) ) ;
F_36 ( & V_14 -> V_65 ) ;
return V_64 ;
}
int F_58 ( struct V_41 * V_66 , T_3 V_67 , T_3 V_68 , int V_69 )
{
struct V_2 * V_14 = V_66 -> V_43 -> V_44 ;
struct V_4 * V_5 = F_3 ( V_14 ) ;
int error ;
error = F_59 ( V_66 -> V_43 , V_67 , V_68 ) ;
if ( error )
return error ;
error = F_60 ( V_5 , V_70 , NULL ) ;
if ( error == - V_71 )
error = 0 ;
return error ;
}
int F_61 ( struct V_4 * V_5 , T_1 V_72 ,
struct V_50 * V_50 )
{
const struct V_73 * V_74 = V_5 -> V_75 -> V_76 ;
if ( ! V_74 -> V_77 )
return - V_71 ;
return V_74 -> V_77 ( V_5 , V_72 + F_62 ( V_5 ) , V_50 , V_78 ) ;
}
int F_63 ( struct V_4 * V_5 , T_1 V_72 ,
struct V_50 * V_50 , struct V_51 * V_52 )
{
int V_79 ;
int V_35 = ( V_52 -> V_80 == V_81 ) ? V_82 : V_83 ;
const struct V_73 * V_74 = V_5 -> V_75 -> V_76 ;
if ( ! V_74 -> V_77 )
return - V_71 ;
F_64 ( V_50 ) ;
V_79 = V_74 -> V_77 ( V_5 , V_72 + F_62 ( V_5 ) , V_50 , V_35 ) ;
if ( V_79 )
F_65 ( V_50 ) ;
else
F_53 ( V_50 ) ;
return V_79 ;
}
static struct V_2 * F_66 ( struct V_23 * V_24 )
{
struct V_1 * V_84 = F_67 ( V_85 , V_70 ) ;
if ( ! V_84 )
return NULL ;
return & V_84 -> V_3 ;
}
static void F_68 ( struct V_86 * V_87 )
{
struct V_2 * V_2 = F_2 ( V_87 , struct V_2 , V_88 ) ;
struct V_1 * V_89 = F_1 ( V_2 ) ;
F_69 ( V_85 , V_89 ) ;
}
static void F_70 ( struct V_2 * V_2 )
{
F_71 ( & V_2 -> V_88 , F_68 ) ;
}
static void F_72 ( void * V_90 )
{
struct V_1 * V_84 = (struct V_1 * ) V_90 ;
struct V_4 * V_5 = & V_84 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_73 ( & V_5 -> V_91 ) ;
F_74 ( & V_5 -> V_92 ) ;
F_74 ( & V_5 -> V_93 ) ;
#ifdef F_75
F_74 ( & V_5 -> V_94 ) ;
#endif
F_76 ( & V_84 -> V_3 ) ;
F_73 ( & V_5 -> V_47 ) ;
}
static inline void F_77 ( struct V_2 * V_2 )
{
F_78 ( & V_2 -> V_95 ) ;
V_2 -> V_96 = NULL ;
V_2 -> V_15 = & V_2 -> V_11 ;
}
static void F_79 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
struct V_53 * V_97 ;
F_80 ( & V_2 -> V_11 ) ;
F_81 ( V_2 ) ;
F_82 ( V_2 ) ;
F_5 ( & V_98 ) ;
while ( ( V_97 = V_5 -> V_92 . V_99 ) != & V_5 -> V_92 ) {
F_77 ( F_83 ( V_97 , struct V_2 , V_95 ) ) ;
}
F_78 ( & V_5 -> V_93 ) ;
F_6 ( & V_98 ) ;
}
static struct V_100 * F_84 ( struct V_101 * V_102 ,
int V_58 , const char * V_103 , void * V_104 )
{
return F_85 ( V_102 , L_1 , & V_105 , NULL , V_106 ) ;
}
void T_4 F_86 ( void )
{
int V_107 ;
static struct V_108 * V_109 ;
V_85 = F_87 ( L_2 , sizeof( struct V_1 ) ,
0 , ( V_110 | V_111 |
V_112 | V_113 ) ,
F_72 ) ;
V_107 = F_88 ( & V_114 ) ;
if ( V_107 )
F_89 ( L_3 ) ;
V_109 = F_90 ( & V_114 ) ;
if ( F_91 ( V_109 ) )
F_89 ( L_4 ) ;
V_115 = V_109 -> V_116 ;
}
static inline unsigned long F_92 ( T_5 V_117 )
{
return F_93 ( V_117 ) + F_94 ( V_117 ) ;
}
static int F_95 ( struct V_2 * V_2 , void * V_104 )
{
return F_1 ( V_2 ) -> V_5 . V_118 == * ( T_5 * ) V_104 ;
}
static int F_96 ( struct V_2 * V_2 , void * V_104 )
{
F_1 ( V_2 ) -> V_5 . V_118 = * ( T_5 * ) V_104 ;
return 0 ;
}
struct V_4 * F_97 ( T_5 V_117 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_98 ( V_115 , F_92 ( V_117 ) ,
F_95 , F_96 , & V_117 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_9 & V_119 ) {
V_5 -> V_120 = NULL ;
V_5 -> V_121 = NULL ;
V_5 -> V_14 = V_2 ;
V_5 -> V_21 = ( 1 << V_2 -> V_22 ) ;
V_5 -> V_122 = 0 ;
V_5 -> V_123 = 0 ;
V_2 -> V_124 = V_125 ;
V_2 -> V_126 = V_117 ;
V_2 -> V_96 = V_5 ;
V_2 -> V_11 . V_127 = & V_128 ;
F_99 ( & V_2 -> V_11 , V_129 ) ;
V_2 -> V_11 . V_6 = & V_130 ;
F_5 ( & V_98 ) ;
F_100 ( & V_5 -> V_93 , & V_131 ) ;
F_6 ( & V_98 ) ;
F_101 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_102 ( struct V_4 * V_5 )
{
F_103 ( V_5 -> V_14 ) ;
return V_5 ;
}
long F_104 ( void )
{
struct V_4 * V_5 ;
long V_62 = 0 ;
F_5 ( & V_98 ) ;
F_105 (bdev, &all_bdevs, bd_list) {
V_62 += V_5 -> V_14 -> V_15 -> V_16 ;
}
F_6 ( & V_98 ) ;
return V_62 ;
}
void F_106 ( struct V_4 * V_5 )
{
F_107 ( V_5 -> V_14 ) ;
}
static struct V_4 * F_108 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_5 ( & V_98 ) ;
V_5 = V_2 -> V_96 ;
if ( V_5 ) {
F_103 ( V_5 -> V_14 ) ;
F_6 ( & V_98 ) ;
return V_5 ;
}
F_6 ( & V_98 ) ;
V_5 = F_97 ( V_2 -> V_126 ) ;
if ( V_5 ) {
F_5 ( & V_98 ) ;
if ( ! V_2 -> V_96 ) {
F_103 ( V_5 -> V_14 ) ;
V_2 -> V_96 = V_5 ;
V_2 -> V_15 = V_5 -> V_14 -> V_15 ;
F_100 ( & V_2 -> V_95 , & V_5 -> V_92 ) ;
}
F_6 ( & V_98 ) ;
}
return V_5 ;
}
int F_109 ( struct V_23 * V_24 )
{
return V_24 == V_115 ;
}
void F_110 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_5 ( & V_98 ) ;
if ( ! F_109 ( V_2 -> V_132 ) )
V_5 = V_2 -> V_96 ;
F_77 ( V_2 ) ;
F_6 ( & V_98 ) ;
if ( V_5 )
F_107 ( V_5 -> V_14 ) ;
}
static bool F_111 ( struct V_4 * V_5 , struct V_4 * V_133 ,
void * V_134 )
{
if ( V_5 -> V_135 == V_134 )
return true ;
else if ( V_5 -> V_135 != NULL )
return false ;
else if ( V_5 -> V_120 == V_5 )
return true ;
else if ( V_133 -> V_135 == F_111 )
return true ;
else if ( V_133 -> V_135 != NULL )
return false ;
else
return true ;
}
static int F_112 ( struct V_4 * V_5 ,
struct V_4 * V_133 , void * V_134 )
{
V_136:
if ( ! F_111 ( V_5 , V_133 , V_134 ) )
return - V_137 ;
if ( V_133 -> V_138 ) {
T_6 * V_139 = F_113 ( & V_133 -> V_138 , 0 ) ;
F_114 ( V_45 ) ;
F_115 ( V_139 , & V_45 , V_140 ) ;
F_6 ( & V_98 ) ;
F_116 () ;
F_117 ( V_139 , & V_45 ) ;
F_5 ( & V_98 ) ;
goto V_136;
}
return 0 ;
}
static struct V_4 * F_118 ( struct V_4 * V_5 ,
void * V_134 )
{
struct V_141 * V_142 ;
struct V_4 * V_133 ;
int V_143 , V_107 ;
F_119 () ;
V_142 = F_120 ( V_5 -> V_118 , & V_143 ) ;
if ( ! V_142 )
return F_40 ( - V_144 ) ;
if ( V_143 )
V_133 = F_121 ( V_142 , 0 ) ;
else
V_133 = F_102 ( V_5 ) ;
F_122 ( V_142 -> V_76 -> V_145 ) ;
F_123 ( V_142 ) ;
if ( ! V_133 )
return F_40 ( - V_146 ) ;
F_5 ( & V_98 ) ;
V_107 = F_112 ( V_5 , V_133 , V_134 ) ;
if ( V_107 == 0 ) {
V_133 -> V_138 = V_134 ;
F_6 ( & V_98 ) ;
return V_133 ;
} else {
F_6 ( & V_98 ) ;
F_106 ( V_133 ) ;
return F_40 ( V_107 ) ;
}
}
static struct V_147 * F_124 ( struct V_4 * V_5 ,
struct V_141 * V_142 )
{
struct V_147 * V_134 ;
F_105 (holder, &bdev->bd_holder_disks, list)
if ( V_134 -> V_142 == V_142 )
return V_134 ;
return NULL ;
}
static int F_125 ( struct V_148 * V_149 , struct V_148 * V_150 )
{
return F_126 ( V_149 , V_150 , F_127 ( V_150 ) ) ;
}
static void F_128 ( struct V_148 * V_149 , struct V_148 * V_150 )
{
F_129 ( V_149 , F_127 ( V_150 ) ) ;
}
int F_130 ( struct V_4 * V_5 , struct V_141 * V_142 )
{
struct V_147 * V_134 ;
int V_62 = 0 ;
F_35 ( & V_5 -> V_91 ) ;
F_7 ( ! V_5 -> V_135 ) ;
if ( F_131 ( ! V_142 -> V_151 || ! V_5 -> V_152 -> V_153 ) )
goto V_154;
V_134 = F_124 ( V_5 , V_142 ) ;
if ( V_134 ) {
V_134 -> V_155 ++ ;
goto V_154;
}
V_134 = F_132 ( sizeof( * V_134 ) , V_70 ) ;
if ( ! V_134 ) {
V_62 = - V_146 ;
goto V_154;
}
F_74 ( & V_134 -> V_156 ) ;
V_134 -> V_142 = V_142 ;
V_134 -> V_155 = 1 ;
V_62 = F_125 ( V_142 -> V_151 , & F_133 ( V_5 -> V_152 ) -> V_157 ) ;
if ( V_62 )
goto V_158;
V_62 = F_125 ( V_5 -> V_152 -> V_153 , & F_134 ( V_142 ) -> V_157 ) ;
if ( V_62 )
goto V_159;
F_135 ( V_5 -> V_152 -> V_153 ) ;
F_100 ( & V_134 -> V_156 , & V_5 -> V_94 ) ;
goto V_154;
V_159:
F_128 ( V_142 -> V_151 , & F_133 ( V_5 -> V_152 ) -> V_157 ) ;
V_158:
F_136 ( V_134 ) ;
V_154:
F_36 ( & V_5 -> V_91 ) ;
return V_62 ;
}
void F_137 ( struct V_4 * V_5 , struct V_141 * V_142 )
{
struct V_147 * V_134 ;
F_35 ( & V_5 -> V_91 ) ;
V_134 = F_124 ( V_5 , V_142 ) ;
if ( ! F_7 ( V_134 == NULL ) && ! -- V_134 -> V_155 ) {
F_128 ( V_142 -> V_151 , & F_133 ( V_5 -> V_152 ) -> V_157 ) ;
F_128 ( V_5 -> V_152 -> V_153 ,
& F_134 ( V_142 ) -> V_157 ) ;
F_138 ( V_5 -> V_152 -> V_153 ) ;
F_78 ( & V_134 -> V_156 ) ;
F_136 ( V_134 ) ;
}
F_36 ( & V_5 -> V_91 ) ;
}
static void F_139 ( struct V_4 * V_5 , bool V_160 )
{
if ( F_140 ( V_5 , V_160 ) ) {
char V_161 [ V_162 ] = L_5 ;
if ( V_5 -> V_75 )
F_141 ( V_5 -> V_75 , 0 , V_161 ) ;
F_142 ( V_163 L_6
L_7 , V_161 ) ;
}
if ( ! V_5 -> V_75 )
return;
if ( F_143 ( V_5 -> V_75 ) )
V_5 -> V_123 = 1 ;
}
void F_144 ( struct V_141 * V_142 , struct V_4 * V_5 )
{
T_3 V_164 , V_165 ;
V_164 = ( T_3 ) F_145 ( V_142 ) << 9 ;
V_165 = F_57 ( V_5 -> V_14 ) ;
if ( V_164 != V_165 ) {
char V_161 [ V_162 ] ;
F_141 ( V_142 , 0 , V_161 ) ;
F_142 ( V_166
L_8 ,
V_161 , V_165 , V_164 ) ;
F_146 ( V_5 -> V_14 , V_164 ) ;
F_139 ( V_5 , false ) ;
}
}
int F_147 ( struct V_141 * V_142 )
{
struct V_4 * V_5 ;
int V_62 = 0 ;
if ( V_142 -> V_76 -> F_147 )
V_62 = V_142 -> V_76 -> F_147 ( V_142 ) ;
V_5 = F_121 ( V_142 , 0 ) ;
if ( ! V_5 )
return V_62 ;
F_35 ( & V_5 -> V_91 ) ;
F_144 ( V_142 , V_5 ) ;
V_5 -> V_123 = 0 ;
F_36 ( & V_5 -> V_91 ) ;
F_106 ( V_5 ) ;
return V_62 ;
}
int F_148 ( struct V_4 * V_5 )
{
struct V_141 * V_142 = V_5 -> V_75 ;
const struct V_73 * V_167 = V_142 -> V_76 ;
unsigned int V_168 ;
V_168 = F_149 ( V_142 , V_169 |
V_170 ) ;
if ( ! ( V_168 & V_169 ) )
return 0 ;
F_139 ( V_5 , true ) ;
if ( V_167 -> F_147 )
V_167 -> F_147 ( V_5 -> V_75 ) ;
return 1 ;
}
void F_150 ( struct V_4 * V_5 , T_3 V_18 )
{
unsigned V_171 = F_18 ( V_5 ) ;
F_35 ( & V_5 -> V_14 -> V_65 ) ;
F_146 ( V_5 -> V_14 , V_18 ) ;
F_36 ( & V_5 -> V_14 -> V_65 ) ;
while ( V_171 < V_172 ) {
if ( V_18 & V_171 )
break;
V_171 <<= 1 ;
}
V_5 -> V_21 = V_171 ;
V_5 -> V_14 -> V_22 = F_20 ( V_171 ) ;
}
static int F_151 ( struct V_4 * V_5 , T_7 V_173 , int V_174 )
{
struct V_141 * V_142 ;
struct V_175 * V_145 ;
int V_62 ;
int V_143 ;
int V_176 = 0 ;
if ( V_173 & V_177 )
V_176 |= V_178 ;
if ( V_173 & V_179 )
V_176 |= V_180 ;
if ( ! V_174 ) {
V_62 = F_152 ( V_5 -> V_14 , V_176 ) ;
if ( V_62 != 0 ) {
F_106 ( V_5 ) ;
return V_62 ;
}
}
V_181:
V_62 = - V_144 ;
V_142 = F_120 ( V_5 -> V_118 , & V_143 ) ;
if ( ! V_142 )
goto V_49;
V_145 = V_142 -> V_76 -> V_145 ;
F_153 ( V_142 ) ;
F_154 ( & V_5 -> V_91 , V_174 ) ;
if ( ! V_5 -> V_182 ) {
V_5 -> V_75 = V_142 ;
V_5 -> V_183 = V_142 -> V_184 ;
V_5 -> V_120 = V_5 ;
if ( ! V_143 ) {
struct V_6 * V_89 ;
V_62 = - V_144 ;
V_5 -> V_152 = F_155 ( V_142 , V_143 ) ;
if ( ! V_5 -> V_152 )
goto V_185;
V_62 = 0 ;
if ( V_142 -> V_76 -> V_186 ) {
V_62 = V_142 -> V_76 -> V_186 ( V_5 , V_173 ) ;
if ( V_62 == - V_187 ) {
F_156 ( V_5 -> V_152 ) ;
V_5 -> V_152 = NULL ;
V_5 -> V_75 = NULL ;
V_5 -> V_183 = NULL ;
F_36 ( & V_5 -> V_91 ) ;
F_157 ( V_142 ) ;
F_123 ( V_142 ) ;
F_122 ( V_145 ) ;
goto V_181;
}
}
if ( ! V_62 ) {
F_150 ( V_5 , ( T_3 ) F_145 ( V_142 ) << 9 ) ;
V_89 = F_158 ( V_5 ) ;
F_4 ( V_5 -> V_14 , V_89 ) ;
}
if ( V_5 -> V_123 ) {
if ( ! V_62 )
F_159 ( V_142 , V_5 ) ;
else if ( V_62 == - V_188 )
F_160 ( V_142 , V_5 ) ;
}
if ( V_62 )
goto V_185;
} else {
struct V_4 * V_133 ;
V_133 = F_121 ( V_142 , 0 ) ;
V_62 = - V_146 ;
if ( ! V_133 )
goto V_185;
F_161 ( V_174 ) ;
V_62 = F_151 ( V_133 , V_173 , 1 ) ;
if ( V_62 )
goto V_185;
V_5 -> V_120 = V_133 ;
F_4 ( V_5 -> V_14 ,
V_133 -> V_14 -> V_11 . V_6 ) ;
V_5 -> V_152 = F_155 ( V_142 , V_143 ) ;
if ( ! ( V_142 -> V_58 & V_189 ) ||
! V_5 -> V_152 || ! V_5 -> V_152 -> V_190 ) {
V_62 = - V_144 ;
goto V_185;
}
F_150 ( V_5 , ( T_3 ) V_5 -> V_152 -> V_190 << 9 ) ;
}
} else {
if ( V_5 -> V_120 == V_5 ) {
V_62 = 0 ;
if ( V_5 -> V_75 -> V_76 -> V_186 )
V_62 = V_5 -> V_75 -> V_76 -> V_186 ( V_5 , V_173 ) ;
if ( V_5 -> V_123 ) {
if ( ! V_62 )
F_159 ( V_5 -> V_75 , V_5 ) ;
else if ( V_62 == - V_188 )
F_160 ( V_5 -> V_75 , V_5 ) ;
}
if ( V_62 )
goto V_191;
}
F_123 ( V_142 ) ;
F_122 ( V_145 ) ;
}
V_5 -> V_182 ++ ;
if ( V_174 )
V_5 -> V_122 ++ ;
F_36 ( & V_5 -> V_91 ) ;
F_157 ( V_142 ) ;
return 0 ;
V_185:
F_156 ( V_5 -> V_152 ) ;
V_5 -> V_75 = NULL ;
V_5 -> V_152 = NULL ;
V_5 -> V_183 = NULL ;
F_4 ( V_5 -> V_14 , & V_130 ) ;
if ( V_5 != V_5 -> V_120 )
F_162 ( V_5 -> V_120 , V_173 , 1 ) ;
V_5 -> V_120 = NULL ;
V_191:
F_36 ( & V_5 -> V_91 ) ;
F_157 ( V_142 ) ;
F_123 ( V_142 ) ;
F_122 ( V_145 ) ;
V_49:
F_106 ( V_5 ) ;
return V_62 ;
}
int F_163 ( struct V_4 * V_5 , T_7 V_173 , void * V_134 )
{
struct V_4 * V_133 = NULL ;
int V_46 ;
F_7 ( ( V_173 & V_192 ) && ! V_134 ) ;
if ( ( V_173 & V_192 ) && V_134 ) {
V_133 = F_118 ( V_5 , V_134 ) ;
if ( F_91 ( V_133 ) ) {
F_106 ( V_5 ) ;
return F_164 ( V_133 ) ;
}
}
V_46 = F_151 ( V_5 , V_173 , 0 ) ;
if ( V_133 ) {
struct V_141 * V_142 = V_133 -> V_75 ;
F_35 ( & V_5 -> V_91 ) ;
F_5 ( & V_98 ) ;
if ( ! V_46 ) {
F_161 ( ! F_111 ( V_5 , V_133 , V_134 ) ) ;
V_133 -> V_193 ++ ;
V_133 -> V_135 = F_111 ;
V_5 -> V_193 ++ ;
V_5 -> V_135 = V_134 ;
}
F_161 ( V_133 -> V_138 != V_134 ) ;
V_133 -> V_138 = NULL ;
F_165 ( & V_133 -> V_138 , 0 ) ;
F_6 ( & V_98 ) ;
if ( ! V_46 && ( V_173 & V_179 ) && ! V_5 -> V_194 &&
( V_142 -> V_58 & V_195 ) ) {
V_5 -> V_194 = true ;
F_153 ( V_142 ) ;
}
F_36 ( & V_5 -> V_91 ) ;
F_106 ( V_133 ) ;
}
return V_46 ;
}
struct V_4 * F_166 ( const char * V_196 , T_7 V_173 ,
void * V_134 )
{
struct V_4 * V_5 ;
int V_107 ;
V_5 = F_167 ( V_196 ) ;
if ( F_91 ( V_5 ) )
return V_5 ;
V_107 = F_163 ( V_5 , V_173 , V_134 ) ;
if ( V_107 )
return F_40 ( V_107 ) ;
if ( ( V_173 & V_179 ) && F_168 ( V_5 ) ) {
F_169 ( V_5 , V_173 ) ;
return F_40 ( - V_197 ) ;
}
return V_5 ;
}
struct V_4 * F_170 ( T_5 V_117 , T_7 V_173 , void * V_134 )
{
struct V_4 * V_5 ;
int V_107 ;
V_5 = F_97 ( V_117 ) ;
if ( ! V_5 )
return F_40 ( - V_146 ) ;
V_107 = F_163 ( V_5 , V_173 , V_134 ) ;
if ( V_107 )
return F_40 ( V_107 ) ;
return V_5 ;
}
static int F_171 ( struct V_2 * V_2 , struct V_41 * V_66 )
{
struct V_4 * V_5 ;
V_66 -> V_198 |= V_199 ;
if ( V_66 -> V_198 & V_200 )
V_66 -> V_201 |= V_202 ;
if ( V_66 -> V_198 & V_203 )
V_66 -> V_201 |= V_192 ;
if ( ( V_66 -> V_198 & V_204 ) == 3 )
V_66 -> V_201 |= V_205 ;
V_5 = F_108 ( V_2 ) ;
if ( V_5 == NULL )
return - V_146 ;
V_66 -> V_43 = V_5 -> V_14 -> V_15 ;
return F_163 ( V_5 , V_66 -> V_201 , V_66 ) ;
}
static void F_162 ( struct V_4 * V_5 , T_7 V_173 , int V_174 )
{
struct V_141 * V_142 = V_5 -> V_75 ;
struct V_4 * V_206 = NULL ;
F_154 ( & V_5 -> V_91 , V_174 ) ;
if ( V_174 )
V_5 -> V_122 -- ;
if ( ! -- V_5 -> V_182 ) {
F_7 ( V_5 -> V_193 ) ;
F_19 ( V_5 ) ;
F_9 ( V_5 ) ;
F_4 ( V_5 -> V_14 ,
& V_130 ) ;
}
if ( V_5 -> V_120 == V_5 ) {
if ( V_142 -> V_76 -> V_207 )
V_142 -> V_76 -> V_207 ( V_142 , V_173 ) ;
}
if ( ! V_5 -> V_182 ) {
struct V_175 * V_145 = V_142 -> V_76 -> V_145 ;
F_156 ( V_5 -> V_152 ) ;
V_5 -> V_152 = NULL ;
V_5 -> V_75 = NULL ;
if ( V_5 != V_5 -> V_120 )
V_206 = V_5 -> V_120 ;
V_5 -> V_120 = NULL ;
F_123 ( V_142 ) ;
F_122 ( V_145 ) ;
}
F_36 ( & V_5 -> V_91 ) ;
F_106 ( V_5 ) ;
if ( V_206 )
F_162 ( V_206 , V_173 , 1 ) ;
}
void F_169 ( struct V_4 * V_5 , T_7 V_173 )
{
F_35 ( & V_5 -> V_91 ) ;
if ( V_173 & V_192 ) {
bool V_208 ;
F_5 ( & V_98 ) ;
F_7 ( -- V_5 -> V_193 < 0 ) ;
F_7 ( -- V_5 -> V_120 -> V_193 < 0 ) ;
if ( ( V_208 = ! V_5 -> V_193 ) )
V_5 -> V_135 = NULL ;
if ( ! V_5 -> V_120 -> V_193 )
V_5 -> V_120 -> V_135 = NULL ;
F_6 ( & V_98 ) ;
if ( V_208 && V_5 -> V_194 ) {
F_157 ( V_5 -> V_75 ) ;
V_5 -> V_194 = false ;
}
}
F_172 ( V_5 -> V_75 , V_169 ) ;
F_36 ( & V_5 -> V_91 ) ;
F_162 ( V_5 , V_173 , 0 ) ;
}
static int F_173 ( struct V_2 * V_2 , struct V_41 * V_66 )
{
struct V_4 * V_5 = F_3 ( V_66 -> V_43 -> V_44 ) ;
F_169 ( V_5 , V_66 -> V_201 ) ;
return 0 ;
}
static long F_174 ( struct V_41 * V_41 , unsigned V_209 , unsigned long V_210 )
{
struct V_4 * V_5 = F_3 ( V_41 -> V_43 -> V_44 ) ;
T_7 V_173 = V_41 -> V_201 ;
if ( V_41 -> V_198 & V_200 )
V_173 |= V_202 ;
else
V_173 &= ~ V_202 ;
return F_175 ( V_5 , V_173 , V_209 , V_210 ) ;
}
T_2 F_176 ( struct V_36 * V_37 , struct V_38 * V_149 )
{
struct V_41 * V_41 = V_37 -> V_42 ;
struct V_211 V_212 ;
T_2 V_62 ;
F_177 ( & V_212 ) ;
V_62 = F_178 ( V_37 , V_149 ) ;
if ( V_62 > 0 ) {
T_2 V_107 ;
V_107 = F_179 ( V_41 , V_37 -> V_213 - V_62 , V_62 ) ;
if ( V_107 < 0 )
V_62 = V_107 ;
}
F_180 ( & V_212 ) ;
return V_62 ;
}
T_2 F_181 ( struct V_36 * V_37 , struct V_38 * V_150 )
{
struct V_41 * V_41 = V_37 -> V_42 ;
struct V_2 * V_14 = V_41 -> V_43 -> V_44 ;
T_3 V_18 = F_57 ( V_14 ) ;
T_3 V_56 = V_37 -> V_213 ;
if ( V_56 >= V_18 )
return 0 ;
V_18 -= V_56 ;
F_182 ( V_150 , V_18 ) ;
return F_183 ( V_37 , V_150 ) ;
}
static int F_184 ( struct V_50 * V_50 , T_8 V_45 )
{
struct V_23 * V_214 = F_1 ( V_50 -> V_13 -> V_44 ) -> V_5 . V_121 ;
if ( V_214 && V_214 -> V_215 -> V_216 )
return V_214 -> V_215 -> V_216 ( V_214 , V_50 , V_45 ) ;
return F_185 ( V_50 ) ;
}
int F_186 ( struct V_4 * V_5 , unsigned V_209 , unsigned long V_210 )
{
int V_46 ;
T_9 V_217 = F_187 () ;
F_188 ( V_218 ) ;
V_46 = F_175 ( V_5 , 0 , V_209 , V_210 ) ;
F_188 ( V_217 ) ;
return V_46 ;
}
struct V_4 * F_167 ( const char * V_219 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_196 V_196 ;
int error ;
if ( ! V_219 || ! * V_219 )
return F_40 ( - V_20 ) ;
error = F_189 ( V_219 , V_220 , & V_196 ) ;
if ( error )
return F_40 ( error ) ;
V_2 = V_196 . V_100 -> V_221 ;
error = - V_222 ;
if ( ! F_190 ( V_2 -> V_124 ) )
goto V_223;
error = - V_197 ;
if ( V_196 . V_224 -> V_225 & V_226 )
goto V_223;
error = - V_146 ;
V_5 = F_108 ( V_2 ) ;
if ( ! V_5 )
goto V_223;
V_49:
F_191 ( & V_196 ) ;
return V_5 ;
V_223:
V_5 = F_40 ( error ) ;
goto V_49;
}
int F_140 ( struct V_4 * V_5 , bool V_160 )
{
struct V_23 * V_24 = F_31 ( V_5 ) ;
int V_46 = 0 ;
if ( V_24 ) {
F_192 ( V_24 ) ;
V_46 = F_193 ( V_24 , V_160 ) ;
F_33 ( V_24 ) ;
}
F_12 ( V_5 ) ;
return V_46 ;
}
void F_194 ( void (* F_195)( struct V_4 * , void * ) , void * V_210 )
{
struct V_2 * V_2 , * V_227 = NULL ;
F_5 ( & V_228 ) ;
F_105 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_12 * V_13 = V_2 -> V_15 ;
F_5 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_9 & ( V_229 | V_230 | V_119 ) ||
V_13 -> V_16 == 0 ) {
F_6 ( & V_2 -> V_8 ) ;
continue;
}
F_196 ( V_2 ) ;
F_6 ( & V_2 -> V_8 ) ;
F_6 ( & V_228 ) ;
F_107 ( V_227 ) ;
V_227 = V_2 ;
F_195 ( F_3 ( V_2 ) , V_210 ) ;
F_5 ( & V_228 ) ;
}
F_6 ( & V_228 ) ;
F_107 ( V_227 ) ;
}

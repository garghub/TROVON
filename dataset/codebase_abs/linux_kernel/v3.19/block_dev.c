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
if ( V_24 -> V_50 -> V_51 )
error = V_24 -> V_50 -> V_51 ( V_24 ) ;
else
error = V_51 ( V_24 ) ;
if ( error ) {
F_38 ( V_24 ) ;
V_5 -> V_48 -- ;
F_36 ( & V_5 -> V_47 ) ;
return F_39 ( error ) ;
}
F_38 ( V_24 ) ;
V_49:
F_19 ( V_5 ) ;
F_36 ( & V_5 -> V_47 ) ;
return V_24 ;
}
int F_40 ( struct V_4 * V_5 , struct V_23 * V_24 )
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
if ( V_24 -> V_50 -> V_52 )
error = V_24 -> V_50 -> V_52 ( V_24 ) ;
else
error = V_52 ( V_24 ) ;
if ( error ) {
V_5 -> V_48 ++ ;
F_36 ( & V_5 -> V_47 ) ;
return error ;
}
V_49:
F_36 ( & V_5 -> V_47 ) ;
return 0 ;
}
static int F_41 ( struct V_53 * V_53 , struct V_54 * V_55 )
{
return F_42 ( V_53 , F_23 , V_55 ) ;
}
static int F_43 ( struct V_41 * V_41 , struct V_53 * V_53 )
{
return F_44 ( V_53 , F_23 ) ;
}
static int F_45 ( struct V_41 * V_41 , struct V_12 * V_13 ,
struct V_56 * V_57 , unsigned V_58 )
{
return F_46 ( V_13 , V_57 , V_58 , F_23 ) ;
}
static int F_47 ( struct V_41 * V_41 , struct V_12 * V_13 ,
T_3 V_59 , unsigned V_60 , unsigned V_61 ,
struct V_53 * * V_62 , void * * V_63 )
{
return F_48 ( V_13 , V_59 , V_60 , V_61 , V_62 ,
F_23 ) ;
}
static int F_49 ( struct V_41 * V_41 , struct V_12 * V_13 ,
T_3 V_59 , unsigned V_60 , unsigned V_64 ,
struct V_53 * V_53 , void * V_63 )
{
int V_65 ;
V_65 = F_50 ( V_41 , V_13 , V_59 , V_60 , V_64 , V_53 , V_63 ) ;
F_51 ( V_53 ) ;
F_52 ( V_53 ) ;
return V_65 ;
}
static T_3 F_53 ( struct V_41 * V_41 , T_3 V_40 , int V_66 )
{
struct V_2 * V_14 = V_41 -> V_43 -> V_44 ;
T_3 V_67 ;
F_35 ( & V_14 -> V_68 ) ;
V_67 = F_54 ( V_41 , V_40 , V_66 , F_55 ( V_14 ) ) ;
F_36 ( & V_14 -> V_68 ) ;
return V_67 ;
}
int F_56 ( struct V_41 * V_69 , T_3 V_70 , T_3 V_71 , int V_72 )
{
struct V_2 * V_14 = V_69 -> V_43 -> V_44 ;
struct V_4 * V_5 = F_3 ( V_14 ) ;
int error ;
error = F_57 ( V_69 -> V_43 , V_70 , V_71 ) ;
if ( error )
return error ;
error = F_58 ( V_5 , V_73 , NULL ) ;
if ( error == - V_74 )
error = 0 ;
return error ;
}
int F_59 ( struct V_4 * V_5 , T_1 V_75 ,
struct V_53 * V_53 )
{
const struct V_76 * V_77 = V_5 -> V_78 -> V_79 ;
if ( ! V_77 -> V_80 )
return - V_74 ;
return V_77 -> V_80 ( V_5 , V_75 + F_60 ( V_5 ) , V_53 , V_81 ) ;
}
int F_61 ( struct V_4 * V_5 , T_1 V_75 ,
struct V_53 * V_53 , struct V_54 * V_55 )
{
int V_82 ;
int V_35 = ( V_55 -> V_83 == V_84 ) ? V_85 : V_86 ;
const struct V_76 * V_77 = V_5 -> V_78 -> V_79 ;
if ( ! V_77 -> V_80 )
return - V_74 ;
F_62 ( V_53 ) ;
V_82 = V_77 -> V_80 ( V_5 , V_75 + F_60 ( V_5 ) , V_53 , V_35 ) ;
if ( V_82 )
F_63 ( V_53 ) ;
else
F_51 ( V_53 ) ;
return V_82 ;
}
static struct V_2 * F_64 ( struct V_23 * V_24 )
{
struct V_1 * V_87 = F_65 ( V_88 , V_73 ) ;
if ( ! V_87 )
return NULL ;
return & V_87 -> V_3 ;
}
static void F_66 ( struct V_89 * V_90 )
{
struct V_2 * V_2 = F_2 ( V_90 , struct V_2 , V_91 ) ;
struct V_1 * V_92 = F_1 ( V_2 ) ;
F_67 ( V_88 , V_92 ) ;
}
static void F_68 ( struct V_2 * V_2 )
{
F_69 ( & V_2 -> V_91 , F_66 ) ;
}
static void F_70 ( void * V_93 )
{
struct V_1 * V_87 = (struct V_1 * ) V_93 ;
struct V_4 * V_5 = & V_87 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_71 ( & V_5 -> V_94 ) ;
F_72 ( & V_5 -> V_95 ) ;
F_72 ( & V_5 -> V_96 ) ;
#ifdef F_73
F_72 ( & V_5 -> V_97 ) ;
#endif
F_74 ( & V_87 -> V_3 ) ;
F_71 ( & V_5 -> V_47 ) ;
}
static inline void F_75 ( struct V_2 * V_2 )
{
F_76 ( & V_2 -> V_98 ) ;
V_2 -> V_99 = NULL ;
V_2 -> V_15 = & V_2 -> V_11 ;
}
static void F_77 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
struct V_56 * V_100 ;
F_78 ( & V_2 -> V_11 ) ;
F_79 ( V_2 ) ;
F_80 ( V_2 ) ;
F_5 ( & V_101 ) ;
while ( ( V_100 = V_5 -> V_95 . V_102 ) != & V_5 -> V_95 ) {
F_75 ( F_81 ( V_100 , struct V_2 , V_98 ) ) ;
}
F_76 ( & V_5 -> V_96 ) ;
F_6 ( & V_101 ) ;
}
static struct V_103 * F_82 ( struct V_104 * V_105 ,
int V_61 , const char * V_106 , void * V_107 )
{
return F_83 ( V_105 , L_1 , & V_108 , NULL , V_109 ) ;
}
void T_4 F_84 ( void )
{
int V_110 ;
static struct V_111 * V_112 ;
V_88 = F_85 ( L_2 , sizeof( struct V_1 ) ,
0 , ( V_113 | V_114 |
V_115 | V_116 ) ,
F_70 ) ;
V_110 = F_86 ( & V_117 ) ;
if ( V_110 )
F_87 ( L_3 ) ;
V_112 = F_88 ( & V_117 ) ;
if ( F_89 ( V_112 ) )
F_87 ( L_4 ) ;
V_118 = V_112 -> V_119 ;
}
static inline unsigned long F_90 ( T_5 V_120 )
{
return F_91 ( V_120 ) + F_92 ( V_120 ) ;
}
static int F_93 ( struct V_2 * V_2 , void * V_107 )
{
return F_1 ( V_2 ) -> V_5 . V_121 == * ( T_5 * ) V_107 ;
}
static int F_94 ( struct V_2 * V_2 , void * V_107 )
{
F_1 ( V_2 ) -> V_5 . V_121 = * ( T_5 * ) V_107 ;
return 0 ;
}
struct V_4 * F_95 ( T_5 V_120 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_96 ( V_118 , F_90 ( V_120 ) ,
F_93 , F_94 , & V_120 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_9 & V_122 ) {
V_5 -> V_123 = NULL ;
V_5 -> V_124 = NULL ;
V_5 -> V_14 = V_2 ;
V_5 -> V_21 = ( 1 << V_2 -> V_22 ) ;
V_5 -> V_125 = 0 ;
V_5 -> V_126 = 0 ;
V_2 -> V_127 = V_128 ;
V_2 -> V_129 = V_120 ;
V_2 -> V_99 = V_5 ;
V_2 -> V_11 . V_130 = & V_131 ;
F_97 ( & V_2 -> V_11 , V_132 ) ;
V_2 -> V_11 . V_6 = & V_133 ;
F_5 ( & V_101 ) ;
F_98 ( & V_5 -> V_96 , & V_134 ) ;
F_6 ( & V_101 ) ;
F_99 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_100 ( struct V_4 * V_5 )
{
F_101 ( V_5 -> V_14 ) ;
return V_5 ;
}
long F_102 ( void )
{
struct V_4 * V_5 ;
long V_65 = 0 ;
F_5 ( & V_101 ) ;
F_103 (bdev, &all_bdevs, bd_list) {
V_65 += V_5 -> V_14 -> V_15 -> V_16 ;
}
F_6 ( & V_101 ) ;
return V_65 ;
}
void F_104 ( struct V_4 * V_5 )
{
F_105 ( V_5 -> V_14 ) ;
}
static struct V_4 * F_106 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_5 ( & V_101 ) ;
V_5 = V_2 -> V_99 ;
if ( V_5 ) {
F_101 ( V_5 -> V_14 ) ;
F_6 ( & V_101 ) ;
return V_5 ;
}
F_6 ( & V_101 ) ;
V_5 = F_95 ( V_2 -> V_129 ) ;
if ( V_5 ) {
F_5 ( & V_101 ) ;
if ( ! V_2 -> V_99 ) {
F_101 ( V_5 -> V_14 ) ;
V_2 -> V_99 = V_5 ;
V_2 -> V_15 = V_5 -> V_14 -> V_15 ;
F_98 ( & V_2 -> V_98 , & V_5 -> V_95 ) ;
}
F_6 ( & V_101 ) ;
}
return V_5 ;
}
int F_107 ( struct V_23 * V_24 )
{
return V_24 == V_118 ;
}
void F_108 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_5 ( & V_101 ) ;
if ( ! F_107 ( V_2 -> V_135 ) )
V_5 = V_2 -> V_99 ;
F_75 ( V_2 ) ;
F_6 ( & V_101 ) ;
if ( V_5 )
F_105 ( V_5 -> V_14 ) ;
}
static bool F_109 ( struct V_4 * V_5 , struct V_4 * V_136 ,
void * V_137 )
{
if ( V_5 -> V_138 == V_137 )
return true ;
else if ( V_5 -> V_138 != NULL )
return false ;
else if ( V_5 -> V_123 == V_5 )
return true ;
else if ( V_136 -> V_138 == F_109 )
return true ;
else if ( V_136 -> V_138 != NULL )
return false ;
else
return true ;
}
static int F_110 ( struct V_4 * V_5 ,
struct V_4 * V_136 , void * V_137 )
{
V_139:
if ( ! F_109 ( V_5 , V_136 , V_137 ) )
return - V_140 ;
if ( V_136 -> V_141 ) {
T_6 * V_142 = F_111 ( & V_136 -> V_141 , 0 ) ;
F_112 ( V_45 ) ;
F_113 ( V_142 , & V_45 , V_143 ) ;
F_6 ( & V_101 ) ;
F_114 () ;
F_115 ( V_142 , & V_45 ) ;
F_5 ( & V_101 ) ;
goto V_139;
}
return 0 ;
}
static struct V_4 * F_116 ( struct V_4 * V_5 ,
void * V_137 )
{
struct V_144 * V_145 ;
struct V_4 * V_136 ;
int V_146 , V_110 ;
F_117 () ;
V_145 = F_118 ( V_5 -> V_121 , & V_146 ) ;
if ( ! V_145 )
return F_39 ( - V_147 ) ;
if ( V_146 )
V_136 = F_119 ( V_145 , 0 ) ;
else
V_136 = F_100 ( V_5 ) ;
F_120 ( V_145 -> V_79 -> V_148 ) ;
F_121 ( V_145 ) ;
if ( ! V_136 )
return F_39 ( - V_149 ) ;
F_5 ( & V_101 ) ;
V_110 = F_110 ( V_5 , V_136 , V_137 ) ;
if ( V_110 == 0 ) {
V_136 -> V_141 = V_137 ;
F_6 ( & V_101 ) ;
return V_136 ;
} else {
F_6 ( & V_101 ) ;
F_104 ( V_136 ) ;
return F_39 ( V_110 ) ;
}
}
static struct V_150 * F_122 ( struct V_4 * V_5 ,
struct V_144 * V_145 )
{
struct V_150 * V_137 ;
F_103 (holder, &bdev->bd_holder_disks, list)
if ( V_137 -> V_145 == V_145 )
return V_137 ;
return NULL ;
}
static int F_123 ( struct V_151 * V_152 , struct V_151 * V_153 )
{
return F_124 ( V_152 , V_153 , F_125 ( V_153 ) ) ;
}
static void F_126 ( struct V_151 * V_152 , struct V_151 * V_153 )
{
F_127 ( V_152 , F_125 ( V_153 ) ) ;
}
int F_128 ( struct V_4 * V_5 , struct V_144 * V_145 )
{
struct V_150 * V_137 ;
int V_65 = 0 ;
F_35 ( & V_5 -> V_94 ) ;
F_7 ( ! V_5 -> V_138 ) ;
if ( F_129 ( ! V_145 -> V_154 || ! V_5 -> V_155 -> V_156 ) )
goto V_157;
V_137 = F_122 ( V_5 , V_145 ) ;
if ( V_137 ) {
V_137 -> V_158 ++ ;
goto V_157;
}
V_137 = F_130 ( sizeof( * V_137 ) , V_73 ) ;
if ( ! V_137 ) {
V_65 = - V_149 ;
goto V_157;
}
F_72 ( & V_137 -> V_159 ) ;
V_137 -> V_145 = V_145 ;
V_137 -> V_158 = 1 ;
V_65 = F_123 ( V_145 -> V_154 , & F_131 ( V_5 -> V_155 ) -> V_160 ) ;
if ( V_65 )
goto V_161;
V_65 = F_123 ( V_5 -> V_155 -> V_156 , & F_132 ( V_145 ) -> V_160 ) ;
if ( V_65 )
goto V_162;
F_133 ( V_5 -> V_155 -> V_156 ) ;
F_98 ( & V_137 -> V_159 , & V_5 -> V_97 ) ;
goto V_157;
V_162:
F_126 ( V_145 -> V_154 , & F_131 ( V_5 -> V_155 ) -> V_160 ) ;
V_161:
F_134 ( V_137 ) ;
V_157:
F_36 ( & V_5 -> V_94 ) ;
return V_65 ;
}
void F_135 ( struct V_4 * V_5 , struct V_144 * V_145 )
{
struct V_150 * V_137 ;
F_35 ( & V_5 -> V_94 ) ;
V_137 = F_122 ( V_5 , V_145 ) ;
if ( ! F_7 ( V_137 == NULL ) && ! -- V_137 -> V_158 ) {
F_126 ( V_145 -> V_154 , & F_131 ( V_5 -> V_155 ) -> V_160 ) ;
F_126 ( V_5 -> V_155 -> V_156 ,
& F_132 ( V_145 ) -> V_160 ) ;
F_136 ( V_5 -> V_155 -> V_156 ) ;
F_76 ( & V_137 -> V_159 ) ;
F_134 ( V_137 ) ;
}
F_36 ( & V_5 -> V_94 ) ;
}
static void F_137 ( struct V_4 * V_5 , bool V_163 )
{
if ( F_138 ( V_5 , V_163 ) ) {
char V_164 [ V_165 ] = L_5 ;
if ( V_5 -> V_78 )
F_139 ( V_5 -> V_78 , 0 , V_164 ) ;
F_140 ( V_166 L_6
L_7 , V_164 ) ;
}
if ( ! V_5 -> V_78 )
return;
if ( F_141 ( V_5 -> V_78 ) )
V_5 -> V_126 = 1 ;
}
void F_142 ( struct V_144 * V_145 , struct V_4 * V_5 )
{
T_3 V_167 , V_168 ;
V_167 = ( T_3 ) F_143 ( V_145 ) << 9 ;
V_168 = F_55 ( V_5 -> V_14 ) ;
if ( V_167 != V_168 ) {
char V_164 [ V_165 ] ;
F_139 ( V_145 , 0 , V_164 ) ;
F_140 ( V_169
L_8 ,
V_164 , V_168 , V_167 ) ;
F_144 ( V_5 -> V_14 , V_167 ) ;
F_137 ( V_5 , false ) ;
}
}
int F_145 ( struct V_144 * V_145 )
{
struct V_4 * V_5 ;
int V_65 = 0 ;
if ( V_145 -> V_79 -> F_145 )
V_65 = V_145 -> V_79 -> F_145 ( V_145 ) ;
V_5 = F_119 ( V_145 , 0 ) ;
if ( ! V_5 )
return V_65 ;
F_35 ( & V_5 -> V_94 ) ;
F_142 ( V_145 , V_5 ) ;
V_5 -> V_126 = 0 ;
F_36 ( & V_5 -> V_94 ) ;
F_104 ( V_5 ) ;
return V_65 ;
}
int F_146 ( struct V_4 * V_5 )
{
struct V_144 * V_145 = V_5 -> V_78 ;
const struct V_76 * V_170 = V_145 -> V_79 ;
unsigned int V_171 ;
V_171 = F_147 ( V_145 , V_172 |
V_173 ) ;
if ( ! ( V_171 & V_172 ) )
return 0 ;
F_137 ( V_5 , true ) ;
if ( V_170 -> F_145 )
V_170 -> F_145 ( V_5 -> V_78 ) ;
return 1 ;
}
void F_148 ( struct V_4 * V_5 , T_3 V_18 )
{
unsigned V_174 = F_18 ( V_5 ) ;
F_35 ( & V_5 -> V_14 -> V_68 ) ;
F_144 ( V_5 -> V_14 , V_18 ) ;
F_36 ( & V_5 -> V_14 -> V_68 ) ;
while ( V_174 < V_175 ) {
if ( V_18 & V_174 )
break;
V_174 <<= 1 ;
}
V_5 -> V_21 = V_174 ;
V_5 -> V_14 -> V_22 = F_20 ( V_174 ) ;
}
static int F_149 ( struct V_4 * V_5 , T_7 V_176 , int V_177 )
{
struct V_144 * V_145 ;
struct V_178 * V_148 ;
int V_65 ;
int V_146 ;
int V_179 = 0 ;
if ( V_176 & V_180 )
V_179 |= V_181 ;
if ( V_176 & V_182 )
V_179 |= V_183 ;
if ( ! V_177 ) {
V_65 = F_150 ( V_5 -> V_14 , V_179 ) ;
if ( V_65 != 0 ) {
F_104 ( V_5 ) ;
return V_65 ;
}
}
V_184:
V_65 = - V_147 ;
V_145 = F_118 ( V_5 -> V_121 , & V_146 ) ;
if ( ! V_145 )
goto V_49;
V_148 = V_145 -> V_79 -> V_148 ;
F_151 ( V_145 ) ;
F_152 ( & V_5 -> V_94 , V_177 ) ;
if ( ! V_5 -> V_185 ) {
V_5 -> V_78 = V_145 ;
V_5 -> V_186 = V_145 -> V_187 ;
V_5 -> V_123 = V_5 ;
if ( ! V_146 ) {
struct V_6 * V_92 ;
V_65 = - V_147 ;
V_5 -> V_155 = F_153 ( V_145 , V_146 ) ;
if ( ! V_5 -> V_155 )
goto V_188;
V_65 = 0 ;
if ( V_145 -> V_79 -> V_189 ) {
V_65 = V_145 -> V_79 -> V_189 ( V_5 , V_176 ) ;
if ( V_65 == - V_190 ) {
F_154 ( V_5 -> V_155 ) ;
V_5 -> V_155 = NULL ;
V_5 -> V_78 = NULL ;
V_5 -> V_186 = NULL ;
F_36 ( & V_5 -> V_94 ) ;
F_155 ( V_145 ) ;
F_121 ( V_145 ) ;
F_120 ( V_148 ) ;
goto V_184;
}
}
if ( ! V_65 ) {
F_148 ( V_5 , ( T_3 ) F_143 ( V_145 ) << 9 ) ;
V_92 = F_156 ( V_5 ) ;
F_4 ( V_5 -> V_14 , V_92 ) ;
}
if ( V_5 -> V_126 ) {
if ( ! V_65 )
F_157 ( V_145 , V_5 ) ;
else if ( V_65 == - V_191 )
F_158 ( V_145 , V_5 ) ;
}
if ( V_65 )
goto V_188;
} else {
struct V_4 * V_136 ;
V_136 = F_119 ( V_145 , 0 ) ;
V_65 = - V_149 ;
if ( ! V_136 )
goto V_188;
F_159 ( V_177 ) ;
V_65 = F_149 ( V_136 , V_176 , 1 ) ;
if ( V_65 )
goto V_188;
V_5 -> V_123 = V_136 ;
F_4 ( V_5 -> V_14 ,
V_136 -> V_14 -> V_11 . V_6 ) ;
V_5 -> V_155 = F_153 ( V_145 , V_146 ) ;
if ( ! ( V_145 -> V_61 & V_192 ) ||
! V_5 -> V_155 || ! V_5 -> V_155 -> V_193 ) {
V_65 = - V_147 ;
goto V_188;
}
F_148 ( V_5 , ( T_3 ) V_5 -> V_155 -> V_193 << 9 ) ;
}
} else {
if ( V_5 -> V_123 == V_5 ) {
V_65 = 0 ;
if ( V_5 -> V_78 -> V_79 -> V_189 )
V_65 = V_5 -> V_78 -> V_79 -> V_189 ( V_5 , V_176 ) ;
if ( V_5 -> V_126 ) {
if ( ! V_65 )
F_157 ( V_5 -> V_78 , V_5 ) ;
else if ( V_65 == - V_191 )
F_158 ( V_5 -> V_78 , V_5 ) ;
}
if ( V_65 )
goto V_194;
}
F_121 ( V_145 ) ;
F_120 ( V_148 ) ;
}
V_5 -> V_185 ++ ;
if ( V_177 )
V_5 -> V_125 ++ ;
F_36 ( & V_5 -> V_94 ) ;
F_155 ( V_145 ) ;
return 0 ;
V_188:
F_154 ( V_5 -> V_155 ) ;
V_5 -> V_78 = NULL ;
V_5 -> V_155 = NULL ;
V_5 -> V_186 = NULL ;
F_4 ( V_5 -> V_14 , & V_133 ) ;
if ( V_5 != V_5 -> V_123 )
F_160 ( V_5 -> V_123 , V_176 , 1 ) ;
V_5 -> V_123 = NULL ;
V_194:
F_36 ( & V_5 -> V_94 ) ;
F_155 ( V_145 ) ;
F_121 ( V_145 ) ;
F_120 ( V_148 ) ;
V_49:
F_104 ( V_5 ) ;
return V_65 ;
}
int F_161 ( struct V_4 * V_5 , T_7 V_176 , void * V_137 )
{
struct V_4 * V_136 = NULL ;
int V_46 ;
F_7 ( ( V_176 & V_195 ) && ! V_137 ) ;
if ( ( V_176 & V_195 ) && V_137 ) {
V_136 = F_116 ( V_5 , V_137 ) ;
if ( F_89 ( V_136 ) ) {
F_104 ( V_5 ) ;
return F_162 ( V_136 ) ;
}
}
V_46 = F_149 ( V_5 , V_176 , 0 ) ;
if ( V_136 ) {
struct V_144 * V_145 = V_136 -> V_78 ;
F_35 ( & V_5 -> V_94 ) ;
F_5 ( & V_101 ) ;
if ( ! V_46 ) {
F_159 ( ! F_109 ( V_5 , V_136 , V_137 ) ) ;
V_136 -> V_196 ++ ;
V_136 -> V_138 = F_109 ;
V_5 -> V_196 ++ ;
V_5 -> V_138 = V_137 ;
}
F_159 ( V_136 -> V_141 != V_137 ) ;
V_136 -> V_141 = NULL ;
F_163 ( & V_136 -> V_141 , 0 ) ;
F_6 ( & V_101 ) ;
if ( ! V_46 && ( V_176 & V_182 ) && ! V_5 -> V_197 &&
( V_145 -> V_61 & V_198 ) ) {
V_5 -> V_197 = true ;
F_151 ( V_145 ) ;
}
F_36 ( & V_5 -> V_94 ) ;
F_104 ( V_136 ) ;
}
return V_46 ;
}
struct V_4 * F_164 ( const char * V_199 , T_7 V_176 ,
void * V_137 )
{
struct V_4 * V_5 ;
int V_110 ;
V_5 = F_165 ( V_199 ) ;
if ( F_89 ( V_5 ) )
return V_5 ;
V_110 = F_161 ( V_5 , V_176 , V_137 ) ;
if ( V_110 )
return F_39 ( V_110 ) ;
if ( ( V_176 & V_182 ) && F_166 ( V_5 ) ) {
F_167 ( V_5 , V_176 ) ;
return F_39 ( - V_200 ) ;
}
return V_5 ;
}
struct V_4 * F_168 ( T_5 V_120 , T_7 V_176 , void * V_137 )
{
struct V_4 * V_5 ;
int V_110 ;
V_5 = F_95 ( V_120 ) ;
if ( ! V_5 )
return F_39 ( - V_149 ) ;
V_110 = F_161 ( V_5 , V_176 , V_137 ) ;
if ( V_110 )
return F_39 ( V_110 ) ;
return V_5 ;
}
static int F_169 ( struct V_2 * V_2 , struct V_41 * V_69 )
{
struct V_4 * V_5 ;
V_69 -> V_201 |= V_202 ;
if ( V_69 -> V_201 & V_203 )
V_69 -> V_204 |= V_205 ;
if ( V_69 -> V_201 & V_206 )
V_69 -> V_204 |= V_195 ;
if ( ( V_69 -> V_201 & V_207 ) == 3 )
V_69 -> V_204 |= V_208 ;
V_5 = F_106 ( V_2 ) ;
if ( V_5 == NULL )
return - V_149 ;
V_69 -> V_43 = V_5 -> V_14 -> V_15 ;
return F_161 ( V_5 , V_69 -> V_204 , V_69 ) ;
}
static void F_160 ( struct V_4 * V_5 , T_7 V_176 , int V_177 )
{
struct V_144 * V_145 = V_5 -> V_78 ;
struct V_4 * V_209 = NULL ;
F_152 ( & V_5 -> V_94 , V_177 ) ;
if ( V_177 )
V_5 -> V_125 -- ;
if ( ! -- V_5 -> V_185 ) {
F_7 ( V_5 -> V_196 ) ;
F_19 ( V_5 ) ;
F_9 ( V_5 ) ;
F_4 ( V_5 -> V_14 ,
& V_133 ) ;
}
if ( V_5 -> V_123 == V_5 ) {
if ( V_145 -> V_79 -> V_210 )
V_145 -> V_79 -> V_210 ( V_145 , V_176 ) ;
}
if ( ! V_5 -> V_185 ) {
struct V_178 * V_148 = V_145 -> V_79 -> V_148 ;
F_154 ( V_5 -> V_155 ) ;
V_5 -> V_155 = NULL ;
V_5 -> V_78 = NULL ;
if ( V_5 != V_5 -> V_123 )
V_209 = V_5 -> V_123 ;
V_5 -> V_123 = NULL ;
F_121 ( V_145 ) ;
F_120 ( V_148 ) ;
}
F_36 ( & V_5 -> V_94 ) ;
F_104 ( V_5 ) ;
if ( V_209 )
F_160 ( V_209 , V_176 , 1 ) ;
}
void F_167 ( struct V_4 * V_5 , T_7 V_176 )
{
F_35 ( & V_5 -> V_94 ) ;
if ( V_176 & V_195 ) {
bool V_211 ;
F_5 ( & V_101 ) ;
F_7 ( -- V_5 -> V_196 < 0 ) ;
F_7 ( -- V_5 -> V_123 -> V_196 < 0 ) ;
if ( ( V_211 = ! V_5 -> V_196 ) )
V_5 -> V_138 = NULL ;
if ( ! V_5 -> V_123 -> V_196 )
V_5 -> V_123 -> V_138 = NULL ;
F_6 ( & V_101 ) ;
if ( V_211 && V_5 -> V_197 ) {
F_155 ( V_5 -> V_78 ) ;
V_5 -> V_197 = false ;
}
}
F_170 ( V_5 -> V_78 , V_172 ) ;
F_36 ( & V_5 -> V_94 ) ;
F_160 ( V_5 , V_176 , 0 ) ;
}
static int F_171 ( struct V_2 * V_2 , struct V_41 * V_69 )
{
struct V_4 * V_5 = F_3 ( V_69 -> V_43 -> V_44 ) ;
F_167 ( V_5 , V_69 -> V_204 ) ;
return 0 ;
}
static long F_172 ( struct V_41 * V_41 , unsigned V_212 , unsigned long V_213 )
{
struct V_4 * V_5 = F_3 ( V_41 -> V_43 -> V_44 ) ;
T_7 V_176 = V_41 -> V_204 ;
if ( V_41 -> V_201 & V_203 )
V_176 |= V_205 ;
else
V_176 &= ~ V_205 ;
return F_173 ( V_5 , V_176 , V_212 , V_213 ) ;
}
T_2 F_174 ( struct V_36 * V_37 , struct V_38 * V_152 )
{
struct V_41 * V_41 = V_37 -> V_42 ;
struct V_214 V_215 ;
T_2 V_65 ;
F_175 ( & V_215 ) ;
V_65 = F_176 ( V_37 , V_152 ) ;
if ( V_65 > 0 ) {
T_2 V_110 ;
V_110 = F_177 ( V_41 , V_37 -> V_216 - V_65 , V_65 ) ;
if ( V_110 < 0 )
V_65 = V_110 ;
}
F_178 ( & V_215 ) ;
return V_65 ;
}
T_2 F_179 ( struct V_36 * V_37 , struct V_38 * V_153 )
{
struct V_41 * V_41 = V_37 -> V_42 ;
struct V_2 * V_14 = V_41 -> V_43 -> V_44 ;
T_3 V_18 = F_55 ( V_14 ) ;
T_3 V_59 = V_37 -> V_216 ;
if ( V_59 >= V_18 )
return 0 ;
V_18 -= V_59 ;
F_180 ( V_153 , V_18 ) ;
return F_181 ( V_37 , V_153 ) ;
}
static int F_182 ( struct V_53 * V_53 , T_8 V_45 )
{
struct V_23 * V_217 = F_1 ( V_53 -> V_13 -> V_44 ) -> V_5 . V_124 ;
if ( V_217 && V_217 -> V_50 -> V_218 )
return V_217 -> V_50 -> V_218 ( V_217 , V_53 , V_45 ) ;
return F_183 ( V_53 ) ;
}
int F_184 ( struct V_4 * V_5 , unsigned V_212 , unsigned long V_213 )
{
int V_46 ;
T_9 V_219 = F_185 () ;
F_186 ( V_220 ) ;
V_46 = F_173 ( V_5 , 0 , V_212 , V_213 ) ;
F_186 ( V_219 ) ;
return V_46 ;
}
struct V_4 * F_165 ( const char * V_221 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_199 V_199 ;
int error ;
if ( ! V_221 || ! * V_221 )
return F_39 ( - V_20 ) ;
error = F_187 ( V_221 , V_222 , & V_199 ) ;
if ( error )
return F_39 ( error ) ;
V_2 = V_199 . V_103 -> V_223 ;
error = - V_224 ;
if ( ! F_188 ( V_2 -> V_127 ) )
goto V_225;
error = - V_200 ;
if ( V_199 . V_226 -> V_227 & V_228 )
goto V_225;
error = - V_149 ;
V_5 = F_106 ( V_2 ) ;
if ( ! V_5 )
goto V_225;
V_49:
F_189 ( & V_199 ) ;
return V_5 ;
V_225:
V_5 = F_39 ( error ) ;
goto V_49;
}
int F_138 ( struct V_4 * V_5 , bool V_163 )
{
struct V_23 * V_24 = F_31 ( V_5 ) ;
int V_46 = 0 ;
if ( V_24 ) {
F_190 ( V_24 ) ;
V_46 = F_191 ( V_24 , V_163 ) ;
F_33 ( V_24 ) ;
}
F_12 ( V_5 ) ;
return V_46 ;
}
void F_192 ( void (* F_193)( struct V_4 * , void * ) , void * V_213 )
{
struct V_2 * V_2 , * V_229 = NULL ;
F_5 ( & V_230 ) ;
F_103 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_12 * V_13 = V_2 -> V_15 ;
F_5 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_9 & ( V_231 | V_232 | V_122 ) ||
V_13 -> V_16 == 0 ) {
F_6 ( & V_2 -> V_8 ) ;
continue;
}
F_194 ( V_2 ) ;
F_6 ( & V_2 -> V_8 ) ;
F_6 ( & V_230 ) ;
F_105 ( V_229 ) ;
V_229 = V_2 ;
F_193 ( F_3 ( V_2 ) , V_213 ) ;
F_5 ( & V_230 ) ;
}
F_6 ( & V_230 ) ;
F_105 ( V_229 ) ;
}

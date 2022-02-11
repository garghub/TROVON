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
if ( V_19 -> V_22 == 0 && V_19 -> V_23 == 0 )
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
int F_20 ( struct V_4 * V_5 , int V_24 )
{
if ( V_24 > V_25 || V_24 < 512 || ! F_21 ( V_24 ) )
return - V_26 ;
if ( V_24 < F_22 ( V_5 ) )
return - V_26 ;
if ( V_5 -> V_27 != V_24 ) {
F_23 ( V_5 ) ;
V_5 -> V_27 = V_24 ;
V_5 -> V_20 -> V_28 = F_24 ( V_24 ) ;
F_13 ( V_5 ) ;
}
return 0 ;
}
int F_25 ( struct V_29 * V_30 , int V_24 )
{
if ( F_20 ( V_30 -> V_31 , V_24 ) )
return 0 ;
V_30 -> V_32 = V_24 ;
V_30 -> V_33 = F_24 ( V_24 ) ;
return V_30 -> V_32 ;
}
int F_26 ( struct V_29 * V_30 , int V_24 )
{
int V_34 = F_22 ( V_30 -> V_31 ) ;
if ( V_24 < V_34 )
V_24 = V_34 ;
return F_25 ( V_30 , V_24 ) ;
}
static int
F_27 ( struct V_2 * V_2 , T_1 V_35 ,
struct V_36 * V_37 , int V_38 )
{
V_37 -> V_39 = F_3 ( V_2 ) ;
V_37 -> V_40 = V_35 ;
F_28 ( V_37 ) ;
return 0 ;
}
static T_2
F_29 ( int V_41 , struct V_42 * V_43 , struct V_44 * V_45 ,
T_3 V_46 )
{
struct V_47 * V_47 = V_43 -> V_48 ;
struct V_2 * V_2 = V_47 -> V_49 -> V_50 ;
return F_30 ( V_41 , V_43 , V_2 , F_3 ( V_2 ) , V_45 ,
V_46 , F_27 ,
NULL , NULL , 0 ) ;
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
struct V_29 * V_30 = F_35 ( V_5 ) ;
if ( V_30 ) {
int V_52 = F_36 ( V_30 ) ;
F_37 ( V_30 ) ;
return V_52 ;
}
return F_23 ( V_5 ) ;
}
struct V_29 * F_38 ( struct V_4 * V_5 )
{
struct V_29 * V_30 ;
int error = 0 ;
F_39 ( & V_5 -> V_53 ) ;
if ( ++ V_5 -> V_54 > 1 ) {
V_30 = F_35 ( V_5 ) ;
F_37 ( V_30 ) ;
F_40 ( & V_5 -> V_53 ) ;
return V_30 ;
}
V_30 = F_41 ( V_5 ) ;
if ( ! V_30 )
goto V_55;
error = F_42 ( V_30 ) ;
if ( error ) {
F_43 ( V_30 ) ;
V_5 -> V_54 -- ;
F_40 ( & V_5 -> V_53 ) ;
return F_44 ( error ) ;
}
F_43 ( V_30 ) ;
V_55:
F_23 ( V_5 ) ;
F_40 ( & V_5 -> V_53 ) ;
return V_30 ;
}
int F_45 ( struct V_4 * V_5 , struct V_29 * V_30 )
{
int error = - V_26 ;
F_39 ( & V_5 -> V_53 ) ;
if ( ! V_5 -> V_54 )
goto V_55;
error = 0 ;
if ( -- V_5 -> V_54 > 0 )
goto V_55;
if ( ! V_30 )
goto V_55;
error = F_46 ( V_30 ) ;
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
static T_3 F_57 ( struct V_47 * V_47 , T_3 V_46 , int V_66 )
{
struct V_2 * V_20 = V_47 -> V_49 -> V_50 ;
T_3 V_67 ;
F_39 ( & V_20 -> V_68 ) ;
V_67 = F_58 ( V_47 , V_46 , V_66 , F_59 ( V_20 ) ) ;
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
int F_63 ( struct V_4 * V_5 , T_1 V_75 ,
struct V_56 * V_56 )
{
const struct V_76 * V_77 = V_5 -> V_78 -> V_79 ;
if ( ! V_77 -> V_80 )
return - V_74 ;
return V_77 -> V_80 ( V_5 , V_75 + F_64 ( V_5 ) , V_56 , V_81 ) ;
}
int F_65 ( struct V_4 * V_5 , T_1 V_75 ,
struct V_56 * V_56 , struct V_57 * V_58 )
{
int V_82 ;
int V_41 = ( V_58 -> V_83 == V_84 ) ? V_85 : V_86 ;
const struct V_76 * V_77 = V_5 -> V_78 -> V_79 ;
if ( ! V_77 -> V_80 )
return - V_74 ;
F_66 ( V_56 ) ;
V_82 = V_77 -> V_80 ( V_5 , V_75 + F_64 ( V_5 ) , V_56 , V_41 ) ;
if ( V_82 )
F_67 ( V_56 ) ;
else
F_55 ( V_56 ) ;
return V_82 ;
}
static struct V_2 * F_68 ( struct V_29 * V_30 )
{
struct V_1 * V_87 = F_69 ( V_88 , V_73 ) ;
if ( ! V_87 )
return NULL ;
return & V_87 -> V_3 ;
}
static void F_70 ( struct V_89 * V_90 )
{
struct V_2 * V_2 = F_2 ( V_90 , struct V_2 , V_91 ) ;
struct V_1 * V_92 = F_1 ( V_2 ) ;
F_71 ( V_88 , V_92 ) ;
}
static void F_72 ( struct V_2 * V_2 )
{
F_73 ( & V_2 -> V_91 , F_70 ) ;
}
static void F_74 ( void * V_93 )
{
struct V_1 * V_87 = (struct V_1 * ) V_93 ;
struct V_4 * V_5 = & V_87 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_75 ( & V_5 -> V_94 ) ;
F_76 ( & V_5 -> V_95 ) ;
F_76 ( & V_5 -> V_96 ) ;
#ifdef F_77
F_76 ( & V_5 -> V_97 ) ;
#endif
F_78 ( & V_87 -> V_3 ) ;
F_75 ( & V_5 -> V_53 ) ;
}
static inline void F_79 ( struct V_2 * V_2 )
{
F_80 ( & V_2 -> V_98 ) ;
V_2 -> V_99 = NULL ;
V_2 -> V_21 = & V_2 -> V_9 ;
}
static void F_81 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
struct V_100 * V_101 ;
F_82 ( & V_2 -> V_9 ) ;
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
F_7 ( & V_102 ) ;
while ( ( V_101 = V_5 -> V_95 . V_103 ) != & V_5 -> V_95 ) {
F_79 ( F_85 ( V_101 , struct V_2 , V_98 ) ) ;
}
F_80 ( & V_5 -> V_96 ) ;
F_11 ( & V_102 ) ;
}
static struct V_104 * F_86 ( struct V_105 * V_106 ,
int V_61 , const char * V_107 , void * V_108 )
{
return F_87 ( V_106 , L_1 , & V_109 , NULL , V_110 ) ;
}
void T_4 F_88 ( void )
{
int V_111 ;
static struct V_112 * V_113 ;
V_88 = F_89 ( L_2 , sizeof( struct V_1 ) ,
0 , ( V_114 | V_115 |
V_116 | V_117 ) ,
F_74 ) ;
V_111 = F_90 ( & V_118 ) ;
if ( V_111 )
F_91 ( L_3 ) ;
V_113 = F_92 ( & V_118 ) ;
if ( F_93 ( V_113 ) )
F_91 ( L_4 ) ;
V_119 = V_113 -> V_120 ;
}
static inline unsigned long F_94 ( T_5 V_121 )
{
return F_95 ( V_121 ) + F_96 ( V_121 ) ;
}
static int F_97 ( struct V_2 * V_2 , void * V_108 )
{
return F_1 ( V_2 ) -> V_5 . V_122 == * ( T_5 * ) V_108 ;
}
static int F_98 ( struct V_2 * V_2 , void * V_108 )
{
F_1 ( V_2 ) -> V_5 . V_122 = * ( T_5 * ) V_108 ;
return 0 ;
}
struct V_4 * F_99 ( T_5 V_121 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_100 ( V_119 , F_94 ( V_121 ) ,
F_97 , F_98 , & V_121 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_13 & V_123 ) {
V_5 -> V_124 = NULL ;
V_5 -> V_125 = NULL ;
V_5 -> V_20 = V_2 ;
V_5 -> V_27 = ( 1 << V_2 -> V_28 ) ;
V_5 -> V_126 = 0 ;
V_5 -> V_127 = 0 ;
V_2 -> V_128 = V_129 ;
V_2 -> V_130 = V_121 ;
V_2 -> V_99 = V_5 ;
V_2 -> V_9 . V_131 = & V_132 ;
F_101 ( & V_2 -> V_9 , V_133 ) ;
V_2 -> V_9 . V_6 = & V_134 ;
F_7 ( & V_102 ) ;
F_102 ( & V_5 -> V_96 , & V_135 ) ;
F_11 ( & V_102 ) ;
F_103 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_104 ( struct V_4 * V_5 )
{
F_105 ( V_5 -> V_20 ) ;
return V_5 ;
}
long F_106 ( void )
{
struct V_4 * V_5 ;
long V_65 = 0 ;
F_7 ( & V_102 ) ;
F_107 (bdev, &all_bdevs, bd_list) {
V_65 += V_5 -> V_20 -> V_21 -> V_22 ;
}
F_11 ( & V_102 ) ;
return V_65 ;
}
void F_108 ( struct V_4 * V_5 )
{
F_109 ( V_5 -> V_20 ) ;
}
static struct V_4 * F_110 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_7 ( & V_102 ) ;
V_5 = V_2 -> V_99 ;
if ( V_5 ) {
F_105 ( V_5 -> V_20 ) ;
F_11 ( & V_102 ) ;
return V_5 ;
}
F_11 ( & V_102 ) ;
V_5 = F_99 ( V_2 -> V_130 ) ;
if ( V_5 ) {
F_7 ( & V_102 ) ;
if ( ! V_2 -> V_99 ) {
F_105 ( V_5 -> V_20 ) ;
V_2 -> V_99 = V_5 ;
V_2 -> V_21 = V_5 -> V_20 -> V_21 ;
F_102 ( & V_2 -> V_98 , & V_5 -> V_95 ) ;
}
F_11 ( & V_102 ) ;
}
return V_5 ;
}
int F_111 ( struct V_29 * V_30 )
{
return V_30 == V_119 ;
}
void F_112 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_7 ( & V_102 ) ;
if ( ! F_111 ( V_2 -> V_136 ) )
V_5 = V_2 -> V_99 ;
F_79 ( V_2 ) ;
F_11 ( & V_102 ) ;
if ( V_5 )
F_109 ( V_5 -> V_20 ) ;
}
static bool F_113 ( struct V_4 * V_5 , struct V_4 * V_137 ,
void * V_138 )
{
if ( V_5 -> V_139 == V_138 )
return true ;
else if ( V_5 -> V_139 != NULL )
return false ;
else if ( V_5 -> V_124 == V_5 )
return true ;
else if ( V_137 -> V_139 == F_113 )
return true ;
else if ( V_137 -> V_139 != NULL )
return false ;
else
return true ;
}
static int F_114 ( struct V_4 * V_5 ,
struct V_4 * V_137 , void * V_138 )
{
V_140:
if ( ! F_113 ( V_5 , V_137 , V_138 ) )
return - V_141 ;
if ( V_137 -> V_142 ) {
T_6 * V_143 = F_115 ( & V_137 -> V_142 , 0 ) ;
F_116 ( V_51 ) ;
F_117 ( V_143 , & V_51 , V_144 ) ;
F_11 ( & V_102 ) ;
F_118 () ;
F_119 ( V_143 , & V_51 ) ;
F_7 ( & V_102 ) ;
goto V_140;
}
return 0 ;
}
static struct V_4 * F_120 ( struct V_4 * V_5 ,
void * V_138 )
{
struct V_145 * V_146 ;
struct V_4 * V_137 ;
int V_147 , V_111 ;
F_121 () ;
V_146 = F_122 ( V_5 -> V_122 , & V_147 ) ;
if ( ! V_146 )
return F_44 ( - V_148 ) ;
if ( V_147 )
V_137 = F_123 ( V_146 , 0 ) ;
else
V_137 = F_104 ( V_5 ) ;
F_124 ( V_146 -> V_79 -> V_149 ) ;
F_125 ( V_146 ) ;
if ( ! V_137 )
return F_44 ( - V_150 ) ;
F_7 ( & V_102 ) ;
V_111 = F_114 ( V_5 , V_137 , V_138 ) ;
if ( V_111 == 0 ) {
V_137 -> V_142 = V_138 ;
F_11 ( & V_102 ) ;
return V_137 ;
} else {
F_11 ( & V_102 ) ;
F_108 ( V_137 ) ;
return F_44 ( V_111 ) ;
}
}
static struct V_151 * F_126 ( struct V_4 * V_5 ,
struct V_145 * V_146 )
{
struct V_151 * V_138 ;
F_107 (holder, &bdev->bd_holder_disks, list)
if ( V_138 -> V_146 == V_146 )
return V_138 ;
return NULL ;
}
static int F_127 ( struct V_152 * V_153 , struct V_152 * V_154 )
{
return F_128 ( V_153 , V_154 , F_129 ( V_154 ) ) ;
}
static void F_130 ( struct V_152 * V_153 , struct V_152 * V_154 )
{
F_131 ( V_153 , F_129 ( V_154 ) ) ;
}
int F_132 ( struct V_4 * V_5 , struct V_145 * V_146 )
{
struct V_151 * V_138 ;
int V_65 = 0 ;
F_39 ( & V_5 -> V_94 ) ;
F_133 ( ! V_5 -> V_139 ) ;
if ( F_134 ( ! V_146 -> V_155 || ! V_5 -> V_156 -> V_157 ) )
goto V_158;
V_138 = F_126 ( V_5 , V_146 ) ;
if ( V_138 ) {
V_138 -> V_159 ++ ;
goto V_158;
}
V_138 = F_135 ( sizeof( * V_138 ) , V_73 ) ;
if ( ! V_138 ) {
V_65 = - V_150 ;
goto V_158;
}
F_76 ( & V_138 -> V_160 ) ;
V_138 -> V_146 = V_146 ;
V_138 -> V_159 = 1 ;
V_65 = F_127 ( V_146 -> V_155 , & F_136 ( V_5 -> V_156 ) -> V_161 ) ;
if ( V_65 )
goto V_162;
V_65 = F_127 ( V_5 -> V_156 -> V_157 , & F_137 ( V_146 ) -> V_161 ) ;
if ( V_65 )
goto V_163;
F_138 ( V_5 -> V_156 -> V_157 ) ;
F_102 ( & V_138 -> V_160 , & V_5 -> V_97 ) ;
goto V_158;
V_163:
F_130 ( V_146 -> V_155 , & F_136 ( V_5 -> V_156 ) -> V_161 ) ;
V_162:
F_139 ( V_138 ) ;
V_158:
F_40 ( & V_5 -> V_94 ) ;
return V_65 ;
}
void F_140 ( struct V_4 * V_5 , struct V_145 * V_146 )
{
struct V_151 * V_138 ;
F_39 ( & V_5 -> V_94 ) ;
V_138 = F_126 ( V_5 , V_146 ) ;
if ( ! F_133 ( V_138 == NULL ) && ! -- V_138 -> V_159 ) {
F_130 ( V_146 -> V_155 , & F_136 ( V_5 -> V_156 ) -> V_161 ) ;
F_130 ( V_5 -> V_156 -> V_157 ,
& F_137 ( V_146 ) -> V_161 ) ;
F_141 ( V_5 -> V_156 -> V_157 ) ;
F_80 ( & V_138 -> V_160 ) ;
F_139 ( V_138 ) ;
}
F_40 ( & V_5 -> V_94 ) ;
}
static void F_142 ( struct V_4 * V_5 , bool V_164 )
{
if ( F_143 ( V_5 , V_164 ) ) {
char V_165 [ V_166 ] = L_5 ;
if ( V_5 -> V_78 )
F_144 ( V_5 -> V_78 , 0 , V_165 ) ;
F_145 ( V_167 L_6
L_7 , V_165 ) ;
}
if ( ! V_5 -> V_78 )
return;
if ( F_146 ( V_5 -> V_78 ) )
V_5 -> V_127 = 1 ;
}
void F_147 ( struct V_145 * V_146 , struct V_4 * V_5 )
{
T_3 V_168 , V_169 ;
V_168 = ( T_3 ) F_148 ( V_146 ) << 9 ;
V_169 = F_59 ( V_5 -> V_20 ) ;
if ( V_168 != V_169 ) {
char V_165 [ V_166 ] ;
F_144 ( V_146 , 0 , V_165 ) ;
F_145 ( V_170
L_8 ,
V_165 , V_169 , V_168 ) ;
F_149 ( V_5 -> V_20 , V_168 ) ;
F_142 ( V_5 , false ) ;
}
}
int F_150 ( struct V_145 * V_146 )
{
struct V_4 * V_5 ;
int V_65 = 0 ;
if ( V_146 -> V_79 -> F_150 )
V_65 = V_146 -> V_79 -> F_150 ( V_146 ) ;
V_5 = F_123 ( V_146 , 0 ) ;
if ( ! V_5 )
return V_65 ;
F_39 ( & V_5 -> V_94 ) ;
F_147 ( V_146 , V_5 ) ;
V_5 -> V_127 = 0 ;
F_40 ( & V_5 -> V_94 ) ;
F_108 ( V_5 ) ;
return V_65 ;
}
int F_151 ( struct V_4 * V_5 )
{
struct V_145 * V_146 = V_5 -> V_78 ;
const struct V_76 * V_171 = V_146 -> V_79 ;
unsigned int V_172 ;
V_172 = F_152 ( V_146 , V_173 |
V_174 ) ;
if ( ! ( V_172 & V_173 ) )
return 0 ;
F_142 ( V_5 , true ) ;
if ( V_171 -> F_150 )
V_171 -> F_150 ( V_5 -> V_78 ) ;
return 1 ;
}
void F_153 ( struct V_4 * V_5 , T_3 V_24 )
{
unsigned V_175 = F_22 ( V_5 ) ;
F_39 ( & V_5 -> V_20 -> V_68 ) ;
F_149 ( V_5 -> V_20 , V_24 ) ;
F_40 ( & V_5 -> V_20 -> V_68 ) ;
while ( V_175 < V_176 ) {
if ( V_24 & V_175 )
break;
V_175 <<= 1 ;
}
V_5 -> V_27 = V_175 ;
V_5 -> V_20 -> V_28 = F_24 ( V_175 ) ;
}
static int F_154 ( struct V_4 * V_5 , T_7 V_177 , int V_178 )
{
struct V_145 * V_146 ;
struct V_179 * V_149 ;
int V_65 ;
int V_147 ;
int V_180 = 0 ;
if ( V_177 & V_181 )
V_180 |= V_182 ;
if ( V_177 & V_183 )
V_180 |= V_184 ;
if ( ! V_178 ) {
V_65 = F_155 ( V_5 -> V_20 , V_180 ) ;
if ( V_65 != 0 ) {
F_108 ( V_5 ) ;
return V_65 ;
}
}
V_185:
V_65 = - V_148 ;
V_146 = F_122 ( V_5 -> V_122 , & V_147 ) ;
if ( ! V_146 )
goto V_55;
V_149 = V_146 -> V_79 -> V_149 ;
F_156 ( V_146 ) ;
F_157 ( & V_5 -> V_94 , V_178 ) ;
if ( ! V_5 -> V_186 ) {
V_5 -> V_78 = V_146 ;
V_5 -> V_187 = V_146 -> V_188 ;
V_5 -> V_124 = V_5 ;
if ( ! V_147 ) {
struct V_6 * V_92 ;
V_65 = - V_148 ;
V_5 -> V_156 = F_158 ( V_146 , V_147 ) ;
if ( ! V_5 -> V_156 )
goto V_189;
V_65 = 0 ;
if ( V_146 -> V_79 -> V_190 ) {
V_65 = V_146 -> V_79 -> V_190 ( V_5 , V_177 ) ;
if ( V_65 == - V_191 ) {
F_159 ( V_5 -> V_156 ) ;
V_5 -> V_156 = NULL ;
V_5 -> V_78 = NULL ;
V_5 -> V_187 = NULL ;
F_40 ( & V_5 -> V_94 ) ;
F_160 ( V_146 ) ;
F_125 ( V_146 ) ;
F_124 ( V_149 ) ;
goto V_185;
}
}
if ( ! V_65 ) {
F_153 ( V_5 , ( T_3 ) F_148 ( V_146 ) << 9 ) ;
V_92 = F_161 ( V_5 ) ;
if ( V_92 == NULL )
V_92 = & V_134 ;
F_4 ( V_5 -> V_20 , V_92 ) ;
}
if ( V_5 -> V_127 ) {
if ( ! V_65 )
F_162 ( V_146 , V_5 ) ;
else if ( V_65 == - V_192 )
F_163 ( V_146 , V_5 ) ;
}
if ( V_65 )
goto V_189;
} else {
struct V_4 * V_137 ;
V_137 = F_123 ( V_146 , 0 ) ;
V_65 = - V_150 ;
if ( ! V_137 )
goto V_189;
F_164 ( V_178 ) ;
V_65 = F_154 ( V_137 , V_177 , 1 ) ;
if ( V_65 )
goto V_189;
V_5 -> V_124 = V_137 ;
F_4 ( V_5 -> V_20 ,
V_137 -> V_20 -> V_9 . V_6 ) ;
V_5 -> V_156 = F_158 ( V_146 , V_147 ) ;
if ( ! ( V_146 -> V_61 & V_193 ) ||
! V_5 -> V_156 || ! V_5 -> V_156 -> V_194 ) {
V_65 = - V_148 ;
goto V_189;
}
F_153 ( V_5 , ( T_3 ) V_5 -> V_156 -> V_194 << 9 ) ;
}
} else {
if ( V_5 -> V_124 == V_5 ) {
V_65 = 0 ;
if ( V_5 -> V_78 -> V_79 -> V_190 )
V_65 = V_5 -> V_78 -> V_79 -> V_190 ( V_5 , V_177 ) ;
if ( V_5 -> V_127 ) {
if ( ! V_65 )
F_162 ( V_5 -> V_78 , V_5 ) ;
else if ( V_65 == - V_192 )
F_163 ( V_5 -> V_78 , V_5 ) ;
}
if ( V_65 )
goto V_195;
}
F_125 ( V_146 ) ;
F_124 ( V_149 ) ;
}
V_5 -> V_186 ++ ;
if ( V_178 )
V_5 -> V_126 ++ ;
F_40 ( & V_5 -> V_94 ) ;
F_160 ( V_146 ) ;
return 0 ;
V_189:
F_159 ( V_5 -> V_156 ) ;
V_5 -> V_78 = NULL ;
V_5 -> V_156 = NULL ;
V_5 -> V_187 = NULL ;
F_4 ( V_5 -> V_20 , & V_134 ) ;
if ( V_5 != V_5 -> V_124 )
F_165 ( V_5 -> V_124 , V_177 , 1 ) ;
V_5 -> V_124 = NULL ;
V_195:
F_40 ( & V_5 -> V_94 ) ;
F_160 ( V_146 ) ;
F_125 ( V_146 ) ;
F_124 ( V_149 ) ;
V_55:
F_108 ( V_5 ) ;
return V_65 ;
}
int F_166 ( struct V_4 * V_5 , T_7 V_177 , void * V_138 )
{
struct V_4 * V_137 = NULL ;
int V_52 ;
F_133 ( ( V_177 & V_196 ) && ! V_138 ) ;
if ( ( V_177 & V_196 ) && V_138 ) {
V_137 = F_120 ( V_5 , V_138 ) ;
if ( F_93 ( V_137 ) ) {
F_108 ( V_5 ) ;
return F_167 ( V_137 ) ;
}
}
V_52 = F_154 ( V_5 , V_177 , 0 ) ;
if ( V_137 ) {
struct V_145 * V_146 = V_137 -> V_78 ;
F_39 ( & V_5 -> V_94 ) ;
F_7 ( & V_102 ) ;
if ( ! V_52 ) {
F_164 ( ! F_113 ( V_5 , V_137 , V_138 ) ) ;
V_137 -> V_197 ++ ;
V_137 -> V_139 = F_113 ;
V_5 -> V_197 ++ ;
V_5 -> V_139 = V_138 ;
}
F_164 ( V_137 -> V_142 != V_138 ) ;
V_137 -> V_142 = NULL ;
F_168 ( & V_137 -> V_142 , 0 ) ;
F_11 ( & V_102 ) ;
if ( ! V_52 && ( V_177 & V_183 ) && ! V_5 -> V_198 &&
( V_146 -> V_61 & V_199 ) ) {
V_5 -> V_198 = true ;
F_156 ( V_146 ) ;
}
F_40 ( & V_5 -> V_94 ) ;
F_108 ( V_137 ) ;
}
return V_52 ;
}
struct V_4 * F_169 ( const char * V_200 , T_7 V_177 ,
void * V_138 )
{
struct V_4 * V_5 ;
int V_111 ;
V_5 = F_170 ( V_200 ) ;
if ( F_93 ( V_5 ) )
return V_5 ;
V_111 = F_166 ( V_5 , V_177 , V_138 ) ;
if ( V_111 )
return F_44 ( V_111 ) ;
if ( ( V_177 & V_183 ) && F_171 ( V_5 ) ) {
F_172 ( V_5 , V_177 ) ;
return F_44 ( - V_201 ) ;
}
return V_5 ;
}
struct V_4 * F_173 ( T_5 V_121 , T_7 V_177 , void * V_138 )
{
struct V_4 * V_5 ;
int V_111 ;
V_5 = F_99 ( V_121 ) ;
if ( ! V_5 )
return F_44 ( - V_150 ) ;
V_111 = F_166 ( V_5 , V_177 , V_138 ) ;
if ( V_111 )
return F_44 ( V_111 ) ;
return V_5 ;
}
static int F_174 ( struct V_2 * V_2 , struct V_47 * V_69 )
{
struct V_4 * V_5 ;
V_69 -> V_202 |= V_203 ;
if ( V_69 -> V_202 & V_204 )
V_69 -> V_205 |= V_206 ;
if ( V_69 -> V_202 & V_207 )
V_69 -> V_205 |= V_196 ;
if ( ( V_69 -> V_202 & V_208 ) == 3 )
V_69 -> V_205 |= V_209 ;
V_5 = F_110 ( V_2 ) ;
if ( V_5 == NULL )
return - V_150 ;
V_69 -> V_49 = V_5 -> V_20 -> V_21 ;
return F_166 ( V_5 , V_69 -> V_205 , V_69 ) ;
}
static void F_165 ( struct V_4 * V_5 , T_7 V_177 , int V_178 )
{
struct V_145 * V_146 = V_5 -> V_78 ;
struct V_4 * V_210 = NULL ;
F_157 ( & V_5 -> V_94 , V_178 ) ;
if ( V_178 )
V_5 -> V_126 -- ;
if ( ! -- V_5 -> V_186 ) {
F_133 ( V_5 -> V_197 ) ;
F_23 ( V_5 ) ;
F_13 ( V_5 ) ;
F_4 ( V_5 -> V_20 ,
& V_134 ) ;
}
if ( V_5 -> V_124 == V_5 ) {
if ( V_146 -> V_79 -> V_211 )
V_146 -> V_79 -> V_211 ( V_146 , V_177 ) ;
}
if ( ! V_5 -> V_186 ) {
struct V_179 * V_149 = V_146 -> V_79 -> V_149 ;
F_159 ( V_5 -> V_156 ) ;
V_5 -> V_156 = NULL ;
V_5 -> V_78 = NULL ;
if ( V_5 != V_5 -> V_124 )
V_210 = V_5 -> V_124 ;
V_5 -> V_124 = NULL ;
F_125 ( V_146 ) ;
F_124 ( V_149 ) ;
}
F_40 ( & V_5 -> V_94 ) ;
F_108 ( V_5 ) ;
if ( V_210 )
F_165 ( V_210 , V_177 , 1 ) ;
}
void F_172 ( struct V_4 * V_5 , T_7 V_177 )
{
F_39 ( & V_5 -> V_94 ) ;
if ( V_177 & V_196 ) {
bool V_212 ;
F_7 ( & V_102 ) ;
F_133 ( -- V_5 -> V_197 < 0 ) ;
F_133 ( -- V_5 -> V_124 -> V_197 < 0 ) ;
if ( ( V_212 = ! V_5 -> V_197 ) )
V_5 -> V_139 = NULL ;
if ( ! V_5 -> V_124 -> V_197 )
V_5 -> V_124 -> V_139 = NULL ;
F_11 ( & V_102 ) ;
if ( V_212 && V_5 -> V_198 ) {
F_160 ( V_5 -> V_78 ) ;
V_5 -> V_198 = false ;
}
}
F_175 ( V_5 -> V_78 , V_173 ) ;
F_40 ( & V_5 -> V_94 ) ;
F_165 ( V_5 , V_177 , 0 ) ;
}
static int F_176 ( struct V_2 * V_2 , struct V_47 * V_69 )
{
struct V_4 * V_5 = F_3 ( V_69 -> V_49 -> V_50 ) ;
F_172 ( V_5 , V_69 -> V_205 ) ;
return 0 ;
}
static long F_177 ( struct V_47 * V_47 , unsigned V_213 , unsigned long V_214 )
{
struct V_4 * V_5 = F_3 ( V_47 -> V_49 -> V_50 ) ;
T_7 V_177 = V_47 -> V_205 ;
if ( V_47 -> V_202 & V_204 )
V_177 |= V_206 ;
else
V_177 &= ~ V_206 ;
return F_178 ( V_5 , V_177 , V_213 , V_214 ) ;
}
T_2 F_179 ( struct V_42 * V_43 , struct V_44 * V_153 )
{
struct V_47 * V_47 = V_43 -> V_48 ;
struct V_215 V_216 ;
T_2 V_65 ;
F_180 ( & V_216 ) ;
V_65 = F_181 ( V_43 , V_153 ) ;
if ( V_65 > 0 ) {
T_2 V_111 ;
V_111 = F_182 ( V_47 , V_43 -> V_217 - V_65 , V_65 ) ;
if ( V_111 < 0 )
V_65 = V_111 ;
}
F_183 ( & V_216 ) ;
return V_65 ;
}
static T_2 F_184 ( struct V_42 * V_43 , struct V_44 * V_154 )
{
struct V_47 * V_47 = V_43 -> V_48 ;
struct V_2 * V_20 = V_47 -> V_49 -> V_50 ;
T_3 V_24 = F_59 ( V_20 ) ;
T_3 V_59 = V_43 -> V_217 ;
if ( V_59 >= V_24 )
return 0 ;
V_24 -= V_59 ;
F_185 ( V_154 , V_24 ) ;
return F_186 ( V_43 , V_154 ) ;
}
static int F_187 ( struct V_56 * V_56 , T_8 V_51 )
{
struct V_29 * V_218 = F_1 ( V_56 -> V_19 -> V_50 ) -> V_5 . V_125 ;
if ( V_218 && V_218 -> V_219 -> V_220 )
return V_218 -> V_219 -> V_220 ( V_218 , V_56 , V_51 ) ;
return F_188 ( V_56 ) ;
}
int F_189 ( struct V_4 * V_5 , unsigned V_213 , unsigned long V_214 )
{
int V_52 ;
T_9 V_221 = F_190 () ;
F_191 ( V_222 ) ;
V_52 = F_178 ( V_5 , 0 , V_213 , V_214 ) ;
F_191 ( V_221 ) ;
return V_52 ;
}
struct V_4 * F_170 ( const char * V_223 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_200 V_200 ;
int error ;
if ( ! V_223 || ! * V_223 )
return F_44 ( - V_26 ) ;
error = F_192 ( V_223 , V_224 , & V_200 ) ;
if ( error )
return F_44 ( error ) ;
V_2 = V_200 . V_104 -> V_225 ;
error = - V_226 ;
if ( ! F_193 ( V_2 -> V_128 ) )
goto V_227;
error = - V_201 ;
if ( V_200 . V_228 -> V_229 & V_230 )
goto V_227;
error = - V_150 ;
V_5 = F_110 ( V_2 ) ;
if ( ! V_5 )
goto V_227;
V_55:
F_194 ( & V_200 ) ;
return V_5 ;
V_227:
V_5 = F_44 ( error ) ;
goto V_55;
}
int F_143 ( struct V_4 * V_5 , bool V_164 )
{
struct V_29 * V_30 = F_35 ( V_5 ) ;
int V_52 = 0 ;
if ( V_30 ) {
F_195 ( V_30 ) ;
V_52 = F_196 ( V_30 , V_164 ) ;
F_37 ( V_30 ) ;
}
F_16 ( V_5 ) ;
return V_52 ;
}
void F_197 ( void (* F_198)( struct V_4 * , void * ) , void * V_214 )
{
struct V_2 * V_2 , * V_231 = NULL ;
F_7 ( & V_232 ) ;
F_107 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_18 * V_19 = V_2 -> V_21 ;
F_7 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 & ( V_233 | V_234 | V_123 ) ||
V_19 -> V_22 == 0 ) {
F_11 ( & V_2 -> V_12 ) ;
continue;
}
F_199 ( V_2 ) ;
F_11 ( & V_2 -> V_12 ) ;
F_11 ( & V_232 ) ;
F_109 ( V_231 ) ;
V_231 = V_2 ;
F_198 ( F_3 ( V_2 ) , V_214 ) ;
F_7 ( & V_232 ) ;
}
F_11 ( & V_232 ) ;
F_109 ( V_231 ) ;
}

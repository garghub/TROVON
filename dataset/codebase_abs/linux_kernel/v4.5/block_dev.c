static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , struct V_1 , V_3 ) ;
}
struct V_4 * F_3 ( struct V_2 * V_2 )
{
return & F_1 ( V_2 ) -> V_5 ;
}
static void F_4 ( struct V_4 * V_5 )
{
struct V_2 * V_2 = V_5 -> V_6 ;
int V_7 ;
F_5 ( & V_2 -> V_8 ) ;
while ( V_2 -> V_9 & V_10 ) {
F_6 ( & V_2 -> V_8 ) ;
V_7 = F_7 ( V_2 , true ) ;
if ( V_7 ) {
char V_11 [ V_12 ] ;
F_8 ( L_1
L_2 ,
F_9 ( V_5 , V_11 ) , V_7 ) ;
}
F_5 ( & V_2 -> V_8 ) ;
}
F_6 ( & V_2 -> V_8 ) ;
}
void F_10 ( struct V_4 * V_5 )
{
struct V_13 * V_14 = V_5 -> V_6 -> V_15 ;
if ( V_14 -> V_16 == 0 && V_14 -> V_17 == 0 )
return;
F_11 () ;
F_12 ( V_14 , 0 ) ;
}
void F_13 ( struct V_4 * V_5 )
{
struct V_13 * V_14 = V_5 -> V_6 -> V_15 ;
if ( V_14 -> V_16 == 0 )
return;
F_11 () ;
F_14 () ;
F_15 ( V_14 , 0 , - 1 ) ;
F_16 ( V_14 ) ;
}
int F_17 ( struct V_4 * V_5 , int V_18 )
{
if ( V_18 > V_19 || V_18 < 512 || ! F_18 ( V_18 ) )
return - V_20 ;
if ( V_18 < F_19 ( V_5 ) )
return - V_20 ;
if ( V_5 -> V_21 != V_18 ) {
F_20 ( V_5 ) ;
V_5 -> V_21 = V_18 ;
V_5 -> V_6 -> V_22 = F_21 ( V_18 ) ;
F_10 ( V_5 ) ;
}
return 0 ;
}
int F_22 ( struct V_23 * V_24 , int V_18 )
{
if ( F_17 ( V_24 -> V_25 , V_18 ) )
return 0 ;
V_24 -> V_26 = V_18 ;
V_24 -> V_27 = F_21 ( V_18 ) ;
return V_24 -> V_26 ;
}
int F_23 ( struct V_23 * V_24 , int V_18 )
{
int V_28 = F_19 ( V_24 -> V_25 ) ;
if ( V_18 < V_28 )
V_18 = V_28 ;
return F_22 ( V_24 , V_18 ) ;
}
static int
F_24 ( struct V_2 * V_2 , T_1 V_29 ,
struct V_30 * V_31 , int V_32 )
{
V_31 -> V_33 = F_3 ( V_2 ) ;
V_31 -> V_34 = V_29 ;
F_25 ( V_31 ) ;
return 0 ;
}
static struct V_2 * F_26 ( struct V_35 * V_35 )
{
return V_35 -> V_36 -> V_37 ;
}
static T_2
F_27 ( struct V_38 * V_39 , struct V_40 * V_41 , T_3 V_42 )
{
struct V_35 * V_35 = V_39 -> V_43 ;
struct V_2 * V_2 = F_26 ( V_35 ) ;
if ( F_28 ( V_2 ) )
return F_29 ( V_39 , V_2 , V_41 , V_42 , F_24 ,
NULL , V_44 ) ;
return F_30 ( V_39 , V_2 , F_3 ( V_2 ) , V_41 , V_42 ,
F_24 , NULL , NULL ,
V_44 ) ;
}
int F_31 ( struct V_4 * V_5 , int V_45 )
{
if ( ! V_5 )
return 0 ;
if ( ! V_45 )
return F_32 ( V_5 -> V_6 -> V_15 ) ;
return F_33 ( V_5 -> V_6 -> V_15 ) ;
}
int F_20 ( struct V_4 * V_5 )
{
return F_31 ( V_5 , 1 ) ;
}
int F_34 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = F_35 ( V_5 ) ;
if ( V_24 ) {
int V_46 = F_36 ( V_24 ) ;
F_37 ( V_24 ) ;
return V_46 ;
}
return F_20 ( V_5 ) ;
}
struct V_23 * F_38 ( struct V_4 * V_5 )
{
struct V_23 * V_24 ;
int error = 0 ;
F_39 ( & V_5 -> V_47 ) ;
if ( ++ V_5 -> V_48 > 1 ) {
V_24 = F_35 ( V_5 ) ;
F_37 ( V_24 ) ;
F_40 ( & V_5 -> V_47 ) ;
return V_24 ;
}
V_24 = F_41 ( V_5 ) ;
if ( ! V_24 )
goto V_49;
if ( V_24 -> V_50 -> V_51 )
error = V_24 -> V_50 -> V_51 ( V_24 ) ;
else
error = V_51 ( V_24 ) ;
if ( error ) {
F_42 ( V_24 ) ;
V_5 -> V_48 -- ;
F_40 ( & V_5 -> V_47 ) ;
return F_43 ( error ) ;
}
F_42 ( V_24 ) ;
V_49:
F_20 ( V_5 ) ;
F_40 ( & V_5 -> V_47 ) ;
return V_24 ;
}
int F_44 ( struct V_4 * V_5 , struct V_23 * V_24 )
{
int error = - V_20 ;
F_39 ( & V_5 -> V_47 ) ;
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
F_40 ( & V_5 -> V_47 ) ;
return error ;
}
V_49:
F_40 ( & V_5 -> V_47 ) ;
return 0 ;
}
static int F_45 ( struct V_53 * V_53 , struct V_54 * V_55 )
{
return F_46 ( V_53 , F_24 , V_55 ) ;
}
static int F_47 ( struct V_35 * V_35 , struct V_53 * V_53 )
{
return F_48 ( V_53 , F_24 ) ;
}
static int F_49 ( struct V_35 * V_35 , struct V_13 * V_14 ,
struct V_56 * V_57 , unsigned V_58 )
{
return F_50 ( V_14 , V_57 , V_58 , F_24 ) ;
}
static int F_51 ( struct V_35 * V_35 , struct V_13 * V_14 ,
T_3 V_59 , unsigned V_60 , unsigned V_61 ,
struct V_53 * * V_62 , void * * V_63 )
{
return F_52 ( V_14 , V_59 , V_60 , V_61 , V_62 ,
F_24 ) ;
}
static int F_53 ( struct V_35 * V_35 , struct V_13 * V_14 ,
T_3 V_59 , unsigned V_60 , unsigned V_64 ,
struct V_53 * V_53 , void * V_63 )
{
int V_7 ;
V_7 = F_54 ( V_35 , V_14 , V_59 , V_60 , V_64 , V_53 , V_63 ) ;
F_55 ( V_53 ) ;
F_56 ( V_53 ) ;
return V_7 ;
}
static T_3 F_57 ( struct V_35 * V_35 , T_3 V_42 , int V_65 )
{
struct V_2 * V_6 = F_26 ( V_35 ) ;
T_3 V_66 ;
F_58 ( V_6 ) ;
V_66 = F_59 ( V_35 , V_42 , V_65 , F_60 ( V_6 ) ) ;
F_61 ( V_6 ) ;
return V_66 ;
}
int F_62 ( struct V_35 * V_67 , T_3 V_68 , T_3 V_69 , int V_70 )
{
struct V_2 * V_6 = F_26 ( V_67 ) ;
struct V_4 * V_5 = F_3 ( V_6 ) ;
int error ;
error = F_63 ( V_67 -> V_36 , V_68 , V_69 ) ;
if ( error )
return error ;
error = F_64 ( V_5 , V_71 , NULL ) ;
if ( error == - V_72 )
error = 0 ;
return error ;
}
int F_65 ( struct V_4 * V_5 , T_1 V_73 ,
struct V_53 * V_53 )
{
const struct V_74 * V_75 = V_5 -> V_76 -> V_77 ;
int V_78 = - V_72 ;
if ( ! V_75 -> V_79 || F_66 ( V_5 ) )
return V_78 ;
V_78 = F_67 ( V_5 -> V_80 , false ) ;
if ( V_78 )
return V_78 ;
V_78 = V_75 -> V_79 ( V_5 , V_73 + F_68 ( V_5 ) , V_53 , V_81 ) ;
F_69 ( V_5 -> V_80 ) ;
return V_78 ;
}
int F_70 ( struct V_4 * V_5 , T_1 V_73 ,
struct V_53 * V_53 , struct V_54 * V_55 )
{
int V_78 ;
int V_82 = ( V_55 -> V_83 == V_84 ) ? V_85 : V_86 ;
const struct V_74 * V_75 = V_5 -> V_76 -> V_77 ;
if ( ! V_75 -> V_79 || F_66 ( V_5 ) )
return - V_72 ;
V_78 = F_67 ( V_5 -> V_80 , false ) ;
if ( V_78 )
return V_78 ;
F_71 ( V_53 ) ;
V_78 = V_75 -> V_79 ( V_5 , V_73 + F_68 ( V_5 ) , V_53 , V_82 ) ;
if ( V_78 )
F_72 ( V_53 ) ;
else
F_55 ( V_53 ) ;
F_69 ( V_5 -> V_80 ) ;
return V_78 ;
}
long F_73 ( struct V_4 * V_5 , struct V_87 * V_88 )
{
T_1 V_73 = V_88 -> V_73 ;
long V_89 , V_18 = V_88 -> V_18 ;
const struct V_74 * V_75 = V_5 -> V_76 -> V_77 ;
F_74 () ;
if ( V_18 < 0 )
return V_18 ;
if ( ! V_75 -> V_90 )
return - V_72 ;
if ( ( V_73 + F_75 ( V_18 , 512 ) ) >
F_76 ( V_5 -> V_91 ) )
return - V_92 ;
V_73 += F_68 ( V_5 ) ;
if ( V_73 % ( V_19 / 512 ) )
return - V_20 ;
V_89 = V_75 -> V_90 ( V_5 , V_73 , & V_88 -> V_93 , & V_88 -> V_94 ) ;
if ( ! V_89 )
return - V_92 ;
if ( V_89 > 0 && V_89 & ~ V_95 )
return - V_96 ;
return F_77 ( V_89 , V_18 ) ;
}
static struct V_2 * F_78 ( struct V_23 * V_24 )
{
struct V_1 * V_97 = F_79 ( V_98 , V_71 ) ;
if ( ! V_97 )
return NULL ;
return & V_97 -> V_3 ;
}
static void F_80 ( struct V_99 * V_100 )
{
struct V_2 * V_2 = F_2 ( V_100 , struct V_2 , V_101 ) ;
struct V_1 * V_102 = F_1 ( V_2 ) ;
F_81 ( V_98 , V_102 ) ;
}
static void F_82 ( struct V_2 * V_2 )
{
F_83 ( & V_2 -> V_101 , F_80 ) ;
}
static void F_84 ( void * V_103 )
{
struct V_1 * V_97 = (struct V_1 * ) V_103 ;
struct V_4 * V_5 = & V_97 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_85 ( & V_5 -> V_104 ) ;
F_86 ( & V_5 -> V_105 ) ;
F_86 ( & V_5 -> V_106 ) ;
#ifdef F_87
F_86 ( & V_5 -> V_107 ) ;
#endif
F_88 ( & V_97 -> V_3 ) ;
F_85 ( & V_5 -> V_47 ) ;
}
static inline void F_89 ( struct V_2 * V_2 )
{
F_90 ( & V_2 -> V_108 ) ;
V_2 -> V_109 = NULL ;
V_2 -> V_15 = & V_2 -> V_110 ;
}
static void F_91 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
struct V_56 * V_111 ;
F_92 ( & V_2 -> V_110 ) ;
F_93 ( V_2 ) ;
F_94 ( V_2 ) ;
F_5 ( & V_112 ) ;
while ( ( V_111 = V_5 -> V_105 . V_113 ) != & V_5 -> V_105 ) {
F_89 ( F_95 ( V_111 , struct V_2 , V_108 ) ) ;
}
F_90 ( & V_5 -> V_106 ) ;
F_6 ( & V_112 ) ;
}
static struct V_114 * F_96 ( struct V_115 * V_116 ,
int V_61 , const char * V_117 , void * V_118 )
{
return F_97 ( V_116 , L_3 , & V_119 , NULL , V_120 ) ;
}
void T_4 F_98 ( void )
{
int V_121 ;
static struct V_122 * V_123 ;
V_98 = F_99 ( L_4 , sizeof( struct V_1 ) ,
0 , ( V_124 | V_125 |
V_126 | V_127 | V_128 ) ,
F_84 ) ;
V_121 = F_100 ( & V_129 ) ;
if ( V_121 )
F_101 ( L_5 ) ;
V_123 = F_102 ( & V_129 ) ;
if ( F_103 ( V_123 ) )
F_101 ( L_6 ) ;
V_130 = V_123 -> V_131 ;
}
static inline unsigned long F_104 ( T_5 V_132 )
{
return F_105 ( V_132 ) + F_106 ( V_132 ) ;
}
static int F_107 ( struct V_2 * V_2 , void * V_118 )
{
return F_1 ( V_2 ) -> V_5 . V_133 == * ( T_5 * ) V_118 ;
}
static int F_108 ( struct V_2 * V_2 , void * V_118 )
{
F_1 ( V_2 ) -> V_5 . V_133 = * ( T_5 * ) V_118 ;
return 0 ;
}
struct V_4 * F_109 ( T_5 V_132 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_110 ( V_130 , F_104 ( V_132 ) ,
F_107 , F_108 , & V_132 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_9 & V_134 ) {
V_5 -> V_135 = NULL ;
V_5 -> V_136 = NULL ;
V_5 -> V_6 = V_2 ;
V_5 -> V_21 = ( 1 << V_2 -> V_22 ) ;
V_5 -> V_137 = 0 ;
V_5 -> V_138 = 0 ;
V_2 -> V_139 = V_140 ;
V_2 -> V_141 = V_132 ;
V_2 -> V_109 = V_5 ;
V_2 -> V_110 . V_142 = & V_143 ;
F_111 ( & V_2 -> V_110 , V_144 ) ;
F_5 ( & V_112 ) ;
F_112 ( & V_5 -> V_106 , & V_145 ) ;
F_6 ( & V_112 ) ;
F_113 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_114 ( struct V_4 * V_5 )
{
F_115 ( V_5 -> V_6 ) ;
return V_5 ;
}
long F_116 ( void )
{
struct V_4 * V_5 ;
long V_7 = 0 ;
F_5 ( & V_112 ) ;
F_117 (bdev, &all_bdevs, bd_list) {
V_7 += V_5 -> V_6 -> V_15 -> V_16 ;
}
F_6 ( & V_112 ) ;
return V_7 ;
}
void F_118 ( struct V_4 * V_5 )
{
F_119 ( V_5 -> V_6 ) ;
}
static struct V_4 * F_120 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_5 ( & V_112 ) ;
V_5 = V_2 -> V_109 ;
if ( V_5 ) {
F_114 ( V_5 ) ;
F_6 ( & V_112 ) ;
return V_5 ;
}
F_6 ( & V_112 ) ;
V_5 = F_109 ( V_2 -> V_141 ) ;
if ( V_5 ) {
F_5 ( & V_112 ) ;
if ( ! V_2 -> V_109 ) {
F_114 ( V_5 ) ;
V_2 -> V_109 = V_5 ;
V_2 -> V_15 = V_5 -> V_6 -> V_15 ;
F_112 ( & V_2 -> V_108 , & V_5 -> V_105 ) ;
}
F_6 ( & V_112 ) ;
}
return V_5 ;
}
void F_121 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_5 ( & V_112 ) ;
if ( ! F_122 ( V_2 -> V_146 ) )
V_5 = V_2 -> V_109 ;
F_89 ( V_2 ) ;
F_6 ( & V_112 ) ;
if ( V_5 )
F_118 ( V_5 ) ;
}
static bool F_123 ( struct V_4 * V_5 , struct V_4 * V_147 ,
void * V_148 )
{
if ( V_5 -> V_149 == V_148 )
return true ;
else if ( V_5 -> V_149 != NULL )
return false ;
else if ( V_5 -> V_135 == V_5 )
return true ;
else if ( V_147 -> V_149 == F_123 )
return true ;
else if ( V_147 -> V_149 != NULL )
return false ;
else
return true ;
}
static int F_124 ( struct V_4 * V_5 ,
struct V_4 * V_147 , void * V_148 )
{
V_150:
if ( ! F_123 ( V_5 , V_147 , V_148 ) )
return - V_151 ;
if ( V_147 -> V_152 ) {
T_6 * V_153 = F_125 ( & V_147 -> V_152 , 0 ) ;
F_126 ( V_45 ) ;
F_127 ( V_153 , & V_45 , V_154 ) ;
F_6 ( & V_112 ) ;
F_128 () ;
F_129 ( V_153 , & V_45 ) ;
F_5 ( & V_112 ) ;
goto V_150;
}
return 0 ;
}
static struct V_4 * F_130 ( struct V_4 * V_5 ,
void * V_148 )
{
struct V_155 * V_156 ;
struct V_4 * V_147 ;
int V_157 , V_121 ;
F_74 () ;
V_156 = F_131 ( V_5 -> V_133 , & V_157 ) ;
if ( ! V_156 )
return F_43 ( - V_96 ) ;
if ( V_157 )
V_147 = F_132 ( V_156 , 0 ) ;
else
V_147 = F_114 ( V_5 ) ;
F_133 ( V_156 -> V_77 -> V_158 ) ;
F_134 ( V_156 ) ;
if ( ! V_147 )
return F_43 ( - V_159 ) ;
F_5 ( & V_112 ) ;
V_121 = F_124 ( V_5 , V_147 , V_148 ) ;
if ( V_121 == 0 ) {
V_147 -> V_152 = V_148 ;
F_6 ( & V_112 ) ;
return V_147 ;
} else {
F_6 ( & V_112 ) ;
F_118 ( V_147 ) ;
return F_43 ( V_121 ) ;
}
}
static struct V_160 * F_135 ( struct V_4 * V_5 ,
struct V_155 * V_156 )
{
struct V_160 * V_148 ;
F_117 (holder, &bdev->bd_holder_disks, list)
if ( V_148 -> V_156 == V_156 )
return V_148 ;
return NULL ;
}
static int F_136 ( struct V_161 * V_162 , struct V_161 * V_163 )
{
return F_137 ( V_162 , V_163 , F_138 ( V_163 ) ) ;
}
static void F_139 ( struct V_161 * V_162 , struct V_161 * V_163 )
{
F_140 ( V_162 , F_138 ( V_163 ) ) ;
}
int F_141 ( struct V_4 * V_5 , struct V_155 * V_156 )
{
struct V_160 * V_148 ;
int V_7 = 0 ;
F_39 ( & V_5 -> V_104 ) ;
F_142 ( ! V_5 -> V_149 ) ;
if ( F_143 ( ! V_156 -> V_164 || ! V_5 -> V_91 -> V_165 ) )
goto V_166;
V_148 = F_135 ( V_5 , V_156 ) ;
if ( V_148 ) {
V_148 -> V_167 ++ ;
goto V_166;
}
V_148 = F_144 ( sizeof( * V_148 ) , V_71 ) ;
if ( ! V_148 ) {
V_7 = - V_159 ;
goto V_166;
}
F_86 ( & V_148 -> V_168 ) ;
V_148 -> V_156 = V_156 ;
V_148 -> V_167 = 1 ;
V_7 = F_136 ( V_156 -> V_164 , & F_145 ( V_5 -> V_91 ) -> V_169 ) ;
if ( V_7 )
goto V_170;
V_7 = F_136 ( V_5 -> V_91 -> V_165 , & F_146 ( V_156 ) -> V_169 ) ;
if ( V_7 )
goto V_171;
F_147 ( V_5 -> V_91 -> V_165 ) ;
F_112 ( & V_148 -> V_168 , & V_5 -> V_107 ) ;
goto V_166;
V_171:
F_139 ( V_156 -> V_164 , & F_145 ( V_5 -> V_91 ) -> V_169 ) ;
V_170:
F_148 ( V_148 ) ;
V_166:
F_40 ( & V_5 -> V_104 ) ;
return V_7 ;
}
void F_149 ( struct V_4 * V_5 , struct V_155 * V_156 )
{
struct V_160 * V_148 ;
F_39 ( & V_5 -> V_104 ) ;
V_148 = F_135 ( V_5 , V_156 ) ;
if ( ! F_142 ( V_148 == NULL ) && ! -- V_148 -> V_167 ) {
F_139 ( V_156 -> V_164 , & F_145 ( V_5 -> V_91 ) -> V_169 ) ;
F_139 ( V_5 -> V_91 -> V_165 ,
& F_146 ( V_156 ) -> V_169 ) ;
F_150 ( V_5 -> V_91 -> V_165 ) ;
F_90 ( & V_148 -> V_168 ) ;
F_148 ( V_148 ) ;
}
F_40 ( & V_5 -> V_104 ) ;
}
static void F_151 ( struct V_4 * V_5 , bool V_172 )
{
if ( F_152 ( V_5 , V_172 ) ) {
F_153 ( V_173 L_7
L_8 ,
V_5 -> V_76 ? V_5 -> V_76 -> V_174 : L_9 ) ;
}
if ( ! V_5 -> V_76 )
return;
if ( F_154 ( V_5 -> V_76 ) )
V_5 -> V_138 = 1 ;
}
void F_155 ( struct V_155 * V_156 , struct V_4 * V_5 )
{
T_3 V_175 , V_176 ;
V_175 = ( T_3 ) F_156 ( V_156 ) << 9 ;
V_176 = F_60 ( V_5 -> V_6 ) ;
if ( V_175 != V_176 ) {
F_153 ( V_177
L_10 ,
V_156 -> V_174 , V_176 , V_175 ) ;
F_157 ( V_5 -> V_6 , V_175 ) ;
F_151 ( V_5 , false ) ;
}
}
int F_158 ( struct V_155 * V_156 )
{
struct V_4 * V_5 ;
int V_7 = 0 ;
if ( V_156 -> V_77 -> F_158 )
V_7 = V_156 -> V_77 -> F_158 ( V_156 ) ;
F_159 ( V_156 ) ;
V_5 = F_132 ( V_156 , 0 ) ;
if ( ! V_5 )
return V_7 ;
F_39 ( & V_5 -> V_104 ) ;
F_155 ( V_156 , V_5 ) ;
V_5 -> V_138 = 0 ;
F_40 ( & V_5 -> V_104 ) ;
F_118 ( V_5 ) ;
return V_7 ;
}
int F_160 ( struct V_4 * V_5 )
{
struct V_155 * V_156 = V_5 -> V_76 ;
const struct V_74 * V_178 = V_156 -> V_77 ;
unsigned int V_179 ;
V_179 = F_161 ( V_156 , V_180 |
V_181 ) ;
if ( ! ( V_179 & V_180 ) )
return 0 ;
F_151 ( V_5 , true ) ;
if ( V_178 -> F_158 )
V_178 -> F_158 ( V_5 -> V_76 ) ;
return 1 ;
}
void F_162 ( struct V_4 * V_5 , T_3 V_18 )
{
unsigned V_182 = F_19 ( V_5 ) ;
F_58 ( V_5 -> V_6 ) ;
F_157 ( V_5 -> V_6 , V_18 ) ;
F_61 ( V_5 -> V_6 ) ;
while ( V_182 < V_183 ) {
if ( V_18 & V_182 )
break;
V_182 <<= 1 ;
}
V_5 -> V_21 = V_182 ;
V_5 -> V_6 -> V_22 = F_21 ( V_182 ) ;
}
static int F_163 ( struct V_4 * V_5 , T_7 V_184 , int V_185 )
{
struct V_155 * V_156 ;
struct V_186 * V_158 ;
int V_7 ;
int V_157 ;
int V_187 = 0 ;
if ( V_184 & V_188 )
V_187 |= V_189 ;
if ( V_184 & V_190 )
V_187 |= V_191 ;
if ( ! V_185 ) {
V_7 = F_164 ( V_5 -> V_6 , V_187 ) ;
if ( V_7 != 0 ) {
F_118 ( V_5 ) ;
return V_7 ;
}
}
V_192:
V_7 = - V_96 ;
V_156 = F_131 ( V_5 -> V_133 , & V_157 ) ;
if ( ! V_156 )
goto V_49;
V_158 = V_156 -> V_77 -> V_158 ;
F_165 ( V_156 ) ;
F_166 ( & V_5 -> V_104 , V_185 ) ;
if ( ! V_5 -> V_193 ) {
V_5 -> V_76 = V_156 ;
V_5 -> V_80 = V_156 -> V_194 ;
V_5 -> V_135 = V_5 ;
if ( F_167 ( V_195 ) && V_156 -> V_77 -> V_90 )
V_5 -> V_6 -> V_196 = V_197 ;
else
V_5 -> V_6 -> V_196 = 0 ;
if ( ! V_157 ) {
V_7 = - V_96 ;
V_5 -> V_91 = F_168 ( V_156 , V_157 ) ;
if ( ! V_5 -> V_91 )
goto V_198;
V_7 = 0 ;
if ( V_156 -> V_77 -> V_199 ) {
V_7 = V_156 -> V_77 -> V_199 ( V_5 , V_184 ) ;
if ( V_7 == - V_200 ) {
F_169 ( V_5 -> V_91 ) ;
V_5 -> V_91 = NULL ;
V_5 -> V_76 = NULL ;
V_5 -> V_80 = NULL ;
F_40 ( & V_5 -> V_104 ) ;
F_170 ( V_156 ) ;
F_134 ( V_156 ) ;
F_133 ( V_158 ) ;
goto V_192;
}
}
if ( ! V_7 ) {
F_162 ( V_5 , ( T_3 ) F_156 ( V_156 ) << 9 ) ;
if ( ! F_171 ( V_5 ) )
V_5 -> V_6 -> V_196 &= ~ V_197 ;
}
if ( V_5 -> V_138 ) {
if ( ! V_7 )
F_172 ( V_156 , V_5 ) ;
else if ( V_7 == - V_201 )
F_173 ( V_156 , V_5 ) ;
}
if ( V_7 )
goto V_198;
} else {
struct V_4 * V_147 ;
V_147 = F_132 ( V_156 , 0 ) ;
V_7 = - V_159 ;
if ( ! V_147 )
goto V_198;
F_174 ( V_185 ) ;
V_7 = F_163 ( V_147 , V_184 , 1 ) ;
if ( V_7 )
goto V_198;
V_5 -> V_135 = V_147 ;
V_5 -> V_91 = F_168 ( V_156 , V_157 ) ;
if ( ! ( V_156 -> V_61 & V_202 ) ||
! V_5 -> V_91 || ! V_5 -> V_91 -> V_203 ) {
V_7 = - V_96 ;
goto V_198;
}
F_162 ( V_5 , ( T_3 ) V_5 -> V_91 -> V_203 << 9 ) ;
if ( ! F_171 ( V_5 ) )
V_5 -> V_6 -> V_196 &= ~ V_197 ;
}
} else {
if ( V_5 -> V_135 == V_5 ) {
V_7 = 0 ;
if ( V_5 -> V_76 -> V_77 -> V_199 )
V_7 = V_5 -> V_76 -> V_77 -> V_199 ( V_5 , V_184 ) ;
if ( V_5 -> V_138 ) {
if ( ! V_7 )
F_172 ( V_5 -> V_76 , V_5 ) ;
else if ( V_7 == - V_201 )
F_173 ( V_5 -> V_76 , V_5 ) ;
}
if ( V_7 )
goto V_204;
}
F_134 ( V_156 ) ;
F_133 ( V_158 ) ;
}
V_5 -> V_193 ++ ;
if ( V_185 )
V_5 -> V_137 ++ ;
F_40 ( & V_5 -> V_104 ) ;
F_170 ( V_156 ) ;
return 0 ;
V_198:
F_169 ( V_5 -> V_91 ) ;
V_5 -> V_76 = NULL ;
V_5 -> V_91 = NULL ;
V_5 -> V_80 = NULL ;
if ( V_5 != V_5 -> V_135 )
F_175 ( V_5 -> V_135 , V_184 , 1 ) ;
V_5 -> V_135 = NULL ;
V_204:
F_40 ( & V_5 -> V_104 ) ;
F_170 ( V_156 ) ;
F_134 ( V_156 ) ;
F_133 ( V_158 ) ;
V_49:
F_118 ( V_5 ) ;
return V_7 ;
}
int F_176 ( struct V_4 * V_5 , T_7 V_184 , void * V_148 )
{
struct V_4 * V_147 = NULL ;
int V_46 ;
F_142 ( ( V_184 & V_205 ) && ! V_148 ) ;
if ( ( V_184 & V_205 ) && V_148 ) {
V_147 = F_130 ( V_5 , V_148 ) ;
if ( F_103 ( V_147 ) ) {
F_118 ( V_5 ) ;
return F_177 ( V_147 ) ;
}
}
V_46 = F_163 ( V_5 , V_184 , 0 ) ;
if ( V_147 ) {
struct V_155 * V_156 = V_147 -> V_76 ;
F_39 ( & V_5 -> V_104 ) ;
F_5 ( & V_112 ) ;
if ( ! V_46 ) {
F_174 ( ! F_123 ( V_5 , V_147 , V_148 ) ) ;
V_147 -> V_206 ++ ;
V_147 -> V_149 = F_123 ;
V_5 -> V_206 ++ ;
V_5 -> V_149 = V_148 ;
}
F_174 ( V_147 -> V_152 != V_148 ) ;
V_147 -> V_152 = NULL ;
F_178 ( & V_147 -> V_152 , 0 ) ;
F_6 ( & V_112 ) ;
if ( ! V_46 && ( V_184 & V_190 ) && ! V_5 -> V_207 &&
( V_156 -> V_61 & V_208 ) ) {
V_5 -> V_207 = true ;
F_165 ( V_156 ) ;
}
F_40 ( & V_5 -> V_104 ) ;
F_118 ( V_147 ) ;
}
return V_46 ;
}
struct V_4 * F_179 ( const char * V_209 , T_7 V_184 ,
void * V_148 )
{
struct V_4 * V_5 ;
int V_121 ;
V_5 = F_180 ( V_209 ) ;
if ( F_103 ( V_5 ) )
return V_5 ;
V_121 = F_176 ( V_5 , V_184 , V_148 ) ;
if ( V_121 )
return F_43 ( V_121 ) ;
if ( ( V_184 & V_190 ) && F_181 ( V_5 ) ) {
F_182 ( V_5 , V_184 ) ;
return F_43 ( - V_210 ) ;
}
return V_5 ;
}
struct V_4 * F_183 ( T_5 V_132 , T_7 V_184 , void * V_148 )
{
struct V_4 * V_5 ;
int V_121 ;
V_5 = F_109 ( V_132 ) ;
if ( ! V_5 )
return F_43 ( - V_159 ) ;
V_121 = F_176 ( V_5 , V_184 , V_148 ) ;
if ( V_121 )
return F_43 ( V_121 ) ;
return V_5 ;
}
static int F_184 ( struct V_2 * V_2 , struct V_35 * V_67 )
{
struct V_4 * V_5 ;
V_67 -> V_211 |= V_212 ;
if ( V_67 -> V_211 & V_213 )
V_67 -> V_214 |= V_215 ;
if ( V_67 -> V_211 & V_216 )
V_67 -> V_214 |= V_205 ;
if ( ( V_67 -> V_211 & V_217 ) == 3 )
V_67 -> V_214 |= V_218 ;
V_5 = F_120 ( V_2 ) ;
if ( V_5 == NULL )
return - V_159 ;
V_67 -> V_36 = V_5 -> V_6 -> V_15 ;
return F_176 ( V_5 , V_67 -> V_214 , V_67 ) ;
}
static void F_175 ( struct V_4 * V_5 , T_7 V_184 , int V_185 )
{
struct V_155 * V_156 = V_5 -> V_76 ;
struct V_4 * V_219 = NULL ;
F_166 ( & V_5 -> V_104 , V_185 ) ;
if ( V_185 )
V_5 -> V_137 -- ;
if ( ! -- V_5 -> V_193 ) {
F_142 ( V_5 -> V_206 ) ;
F_20 ( V_5 ) ;
F_10 ( V_5 ) ;
F_4 ( V_5 ) ;
F_185 ( V_5 -> V_6 ) ;
}
if ( V_5 -> V_135 == V_5 ) {
if ( V_156 -> V_77 -> V_220 )
V_156 -> V_77 -> V_220 ( V_156 , V_184 ) ;
}
if ( ! V_5 -> V_193 ) {
struct V_186 * V_158 = V_156 -> V_77 -> V_158 ;
F_169 ( V_5 -> V_91 ) ;
V_5 -> V_91 = NULL ;
V_5 -> V_76 = NULL ;
if ( V_5 != V_5 -> V_135 )
V_219 = V_5 -> V_135 ;
V_5 -> V_135 = NULL ;
F_134 ( V_156 ) ;
F_133 ( V_158 ) ;
}
F_40 ( & V_5 -> V_104 ) ;
F_118 ( V_5 ) ;
if ( V_219 )
F_175 ( V_219 , V_184 , 1 ) ;
}
void F_182 ( struct V_4 * V_5 , T_7 V_184 )
{
F_39 ( & V_5 -> V_104 ) ;
if ( V_184 & V_205 ) {
bool V_221 ;
F_5 ( & V_112 ) ;
F_142 ( -- V_5 -> V_206 < 0 ) ;
F_142 ( -- V_5 -> V_135 -> V_206 < 0 ) ;
if ( ( V_221 = ! V_5 -> V_206 ) )
V_5 -> V_149 = NULL ;
if ( ! V_5 -> V_135 -> V_206 )
V_5 -> V_135 -> V_149 = NULL ;
F_6 ( & V_112 ) ;
if ( V_221 && V_5 -> V_207 ) {
F_170 ( V_5 -> V_76 ) ;
V_5 -> V_207 = false ;
}
}
F_186 ( V_5 -> V_76 , V_180 ) ;
F_40 ( & V_5 -> V_104 ) ;
F_175 ( V_5 , V_184 , 0 ) ;
}
static int F_187 ( struct V_2 * V_2 , struct V_35 * V_67 )
{
struct V_4 * V_5 = F_3 ( F_26 ( V_67 ) ) ;
F_182 ( V_5 , V_67 -> V_214 ) ;
return 0 ;
}
static long F_188 ( struct V_35 * V_35 , unsigned V_222 , unsigned long V_223 )
{
struct V_4 * V_5 = F_3 ( F_26 ( V_35 ) ) ;
T_7 V_184 = V_35 -> V_214 ;
if ( V_35 -> V_211 & V_213 )
V_184 |= V_215 ;
else
V_184 &= ~ V_215 ;
return F_189 ( V_5 , V_184 , V_222 , V_223 ) ;
}
T_2 F_190 ( struct V_38 * V_39 , struct V_40 * V_162 )
{
struct V_35 * V_35 = V_39 -> V_43 ;
struct V_2 * V_6 = F_26 ( V_35 ) ;
T_3 V_18 = F_60 ( V_6 ) ;
struct V_224 V_225 ;
T_2 V_7 ;
if ( F_181 ( F_3 ( V_6 ) ) )
return - V_226 ;
if ( ! F_191 ( V_162 ) )
return 0 ;
if ( V_39 -> V_227 >= V_18 )
return - V_228 ;
F_192 ( V_162 , V_18 - V_39 -> V_227 ) ;
F_193 ( & V_225 ) ;
V_7 = F_194 ( V_39 , V_162 ) ;
if ( V_7 > 0 ) {
T_2 V_121 ;
V_121 = F_195 ( V_35 , V_39 -> V_227 - V_7 , V_7 ) ;
if ( V_121 < 0 )
V_7 = V_121 ;
}
F_196 ( & V_225 ) ;
return V_7 ;
}
T_2 F_197 ( struct V_38 * V_39 , struct V_40 * V_163 )
{
struct V_35 * V_35 = V_39 -> V_43 ;
struct V_2 * V_6 = F_26 ( V_35 ) ;
T_3 V_18 = F_60 ( V_6 ) ;
T_3 V_59 = V_39 -> V_227 ;
if ( V_59 >= V_18 )
return 0 ;
V_18 -= V_59 ;
F_192 ( V_163 , V_18 ) ;
return F_198 ( V_39 , V_163 ) ;
}
static int F_199 ( struct V_53 * V_53 , T_8 V_45 )
{
struct V_23 * V_229 = F_1 ( V_53 -> V_14 -> V_37 ) -> V_5 . V_136 ;
if ( V_229 && V_229 -> V_50 -> V_230 )
return V_229 -> V_50 -> V_230 ( V_229 , V_53 , V_45 ) ;
return F_200 ( V_53 ) ;
}
static int F_201 ( struct V_13 * V_14 ,
struct V_54 * V_55 )
{
if ( F_202 ( V_14 ) ) {
struct V_4 * V_5 = F_3 ( V_14 -> V_37 ) ;
return F_203 ( V_14 , V_5 , V_55 ) ;
}
return F_204 ( V_14 , V_55 ) ;
}
static int F_205 ( struct V_231 * V_232 , struct V_233 * V_234 )
{
return F_206 ( V_232 , V_234 , F_24 , NULL ) ;
}
static int F_207 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
return F_208 ( V_232 , V_234 ) ;
}
static int F_209 ( struct V_231 * V_232 , unsigned long V_93 ,
T_9 * V_235 , unsigned int V_61 )
{
return F_210 ( V_232 , V_93 , V_235 , V_61 , F_24 , NULL ) ;
}
static int F_211 ( struct V_35 * V_35 , struct V_231 * V_232 )
{
struct V_2 * V_6 = F_26 ( V_35 ) ;
F_212 ( V_35 ) ;
if ( F_28 ( V_6 ) ) {
V_232 -> V_236 = & V_237 ;
V_232 -> V_238 |= V_239 | V_240 ;
} else {
V_232 -> V_236 = & V_241 ;
}
return 0 ;
}
int F_213 ( struct V_4 * V_5 , unsigned V_222 , unsigned long V_223 )
{
int V_46 ;
T_10 V_242 = F_214 () ;
F_215 ( V_243 ) ;
V_46 = F_189 ( V_5 , 0 , V_222 , V_223 ) ;
F_215 ( V_242 ) ;
return V_46 ;
}
struct V_4 * F_180 ( const char * V_244 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_209 V_209 ;
int error ;
if ( ! V_244 || ! * V_244 )
return F_43 ( - V_20 ) ;
error = F_216 ( V_244 , V_245 , & V_209 ) ;
if ( error )
return F_43 ( error ) ;
V_2 = F_217 ( V_209 . V_114 ) ;
error = - V_246 ;
if ( ! F_218 ( V_2 -> V_139 ) )
goto V_247;
error = - V_210 ;
if ( V_209 . V_248 -> V_249 & V_250 )
goto V_247;
error = - V_159 ;
V_5 = F_120 ( V_2 ) ;
if ( ! V_5 )
goto V_247;
V_49:
F_219 ( & V_209 ) ;
return V_5 ;
V_247:
V_5 = F_43 ( error ) ;
goto V_49;
}
int F_152 ( struct V_4 * V_5 , bool V_172 )
{
struct V_23 * V_24 = F_35 ( V_5 ) ;
int V_46 = 0 ;
if ( V_24 ) {
F_220 ( V_24 ) ;
V_46 = F_221 ( V_24 , V_172 ) ;
F_37 ( V_24 ) ;
}
F_13 ( V_5 ) ;
return V_46 ;
}
void F_222 ( void (* F_223)( struct V_4 * , void * ) , void * V_223 )
{
struct V_2 * V_2 , * V_251 = NULL ;
F_5 ( & V_130 -> V_252 ) ;
F_117 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_13 * V_14 = V_2 -> V_15 ;
F_5 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_9 & ( V_253 | V_254 | V_134 ) ||
V_14 -> V_16 == 0 ) {
F_6 ( & V_2 -> V_8 ) ;
continue;
}
F_224 ( V_2 ) ;
F_6 ( & V_2 -> V_8 ) ;
F_6 ( & V_130 -> V_252 ) ;
F_119 ( V_251 ) ;
V_251 = V_2 ;
F_223 ( F_3 ( V_2 ) , V_223 ) ;
F_5 ( & V_130 -> V_252 ) ;
}
F_6 ( & V_130 -> V_252 ) ;
F_119 ( V_251 ) ;
}

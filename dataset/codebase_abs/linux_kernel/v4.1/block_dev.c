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
F_25 ( struct V_32 * V_33 , struct V_34 * V_35 , T_3 V_36 )
{
struct V_37 * V_37 = V_33 -> V_38 ;
struct V_2 * V_2 = V_37 -> V_39 -> V_40 ;
return F_26 ( V_33 , V_2 , F_3 ( V_2 ) , V_35 , V_36 ,
F_23 , NULL , NULL ,
V_41 ) ;
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
static int F_43 ( struct V_37 * V_37 , struct V_50 * V_50 )
{
return F_44 ( V_50 , F_23 ) ;
}
static int F_45 ( struct V_37 * V_37 , struct V_9 * V_10 ,
struct V_53 * V_54 , unsigned V_55 )
{
return F_46 ( V_10 , V_54 , V_55 , F_23 ) ;
}
static int F_47 ( struct V_37 * V_37 , struct V_9 * V_10 ,
T_3 V_56 , unsigned V_57 , unsigned V_58 ,
struct V_50 * * V_59 , void * * V_60 )
{
return F_48 ( V_10 , V_56 , V_57 , V_58 , V_59 ,
F_23 ) ;
}
static int F_49 ( struct V_37 * V_37 , struct V_9 * V_10 ,
T_3 V_56 , unsigned V_57 , unsigned V_61 ,
struct V_50 * V_50 , void * V_60 )
{
int V_62 ;
V_62 = F_50 ( V_37 , V_10 , V_56 , V_57 , V_61 , V_50 , V_60 ) ;
F_51 ( V_50 ) ;
F_52 ( V_50 ) ;
return V_62 ;
}
static T_3 F_53 ( struct V_37 * V_37 , T_3 V_36 , int V_63 )
{
struct V_2 * V_11 = V_37 -> V_39 -> V_40 ;
T_3 V_64 ;
F_35 ( & V_11 -> V_65 ) ;
V_64 = F_54 ( V_37 , V_36 , V_63 , F_55 ( V_11 ) ) ;
F_36 ( & V_11 -> V_65 ) ;
return V_64 ;
}
int F_56 ( struct V_37 * V_66 , T_3 V_67 , T_3 V_68 , int V_69 )
{
struct V_2 * V_11 = V_66 -> V_39 -> V_40 ;
struct V_4 * V_5 = F_3 ( V_11 ) ;
int error ;
error = F_57 ( V_66 -> V_39 , V_67 , V_68 ) ;
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
int V_80 = ( V_52 -> V_81 == V_82 ) ? V_83 : V_84 ;
const struct V_73 * V_74 = V_5 -> V_75 -> V_76 ;
if ( ! V_74 -> V_77 )
return - V_71 ;
F_62 ( V_50 ) ;
V_79 = V_74 -> V_77 ( V_5 , V_72 + F_60 ( V_5 ) , V_50 , V_80 ) ;
if ( V_79 )
F_63 ( V_50 ) ;
else
F_51 ( V_50 ) ;
return V_79 ;
}
long F_64 ( struct V_4 * V_5 , T_1 V_72 ,
void * * V_85 , unsigned long * V_86 , long V_15 )
{
long V_87 ;
const struct V_73 * V_74 = V_5 -> V_75 -> V_76 ;
if ( V_15 < 0 )
return V_15 ;
if ( ! V_74 -> V_88 )
return - V_71 ;
if ( ( V_72 + F_65 ( V_15 , 512 ) ) >
F_66 ( V_5 -> V_89 ) )
return - V_90 ;
V_72 += F_60 ( V_5 ) ;
if ( V_72 % ( V_16 / 512 ) )
return - V_17 ;
V_87 = V_74 -> V_88 ( V_5 , V_72 , V_85 , V_86 , V_15 ) ;
if ( ! V_87 )
return - V_90 ;
return F_67 ( V_87 , V_15 ) ;
}
static struct V_2 * F_68 ( struct V_20 * V_21 )
{
struct V_1 * V_91 = F_69 ( V_92 , V_70 ) ;
if ( ! V_91 )
return NULL ;
return & V_91 -> V_3 ;
}
static void F_70 ( struct V_93 * V_94 )
{
struct V_2 * V_2 = F_2 ( V_94 , struct V_2 , V_95 ) ;
struct V_1 * V_96 = F_1 ( V_2 ) ;
F_71 ( V_92 , V_96 ) ;
}
static void F_72 ( struct V_2 * V_2 )
{
F_73 ( & V_2 -> V_95 , F_70 ) ;
}
static void F_74 ( void * V_97 )
{
struct V_1 * V_91 = (struct V_1 * ) V_97 ;
struct V_4 * V_5 = & V_91 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_75 ( & V_5 -> V_98 ) ;
F_76 ( & V_5 -> V_99 ) ;
F_76 ( & V_5 -> V_100 ) ;
#ifdef F_77
F_76 ( & V_5 -> V_101 ) ;
#endif
F_78 ( & V_91 -> V_3 ) ;
F_75 ( & V_5 -> V_44 ) ;
}
static inline void F_79 ( struct V_2 * V_2 )
{
F_80 ( & V_2 -> V_102 ) ;
V_2 -> V_103 = NULL ;
V_2 -> V_12 = & V_2 -> V_104 ;
}
static void F_81 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
struct V_53 * V_105 ;
F_82 ( & V_2 -> V_104 ) ;
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
F_5 ( & V_106 ) ;
while ( ( V_105 = V_5 -> V_99 . V_107 ) != & V_5 -> V_99 ) {
F_79 ( F_85 ( V_105 , struct V_2 , V_102 ) ) ;
}
F_80 ( & V_5 -> V_100 ) ;
F_6 ( & V_106 ) ;
}
static struct V_108 * F_86 ( struct V_109 * V_110 ,
int V_58 , const char * V_111 , void * V_112 )
{
return F_87 ( V_110 , L_1 , & V_113 , NULL , V_114 ) ;
}
void T_4 F_88 ( void )
{
int V_115 ;
static struct V_116 * V_117 ;
V_92 = F_89 ( L_2 , sizeof( struct V_1 ) ,
0 , ( V_118 | V_119 |
V_120 | V_121 ) ,
F_74 ) ;
V_115 = F_90 ( & V_122 ) ;
if ( V_115 )
F_91 ( L_3 ) ;
V_117 = F_92 ( & V_122 ) ;
if ( F_93 ( V_117 ) )
F_91 ( L_4 ) ;
V_123 = V_117 -> V_124 ;
}
static inline unsigned long F_94 ( T_5 V_125 )
{
return F_95 ( V_125 ) + F_96 ( V_125 ) ;
}
static int F_97 ( struct V_2 * V_2 , void * V_112 )
{
return F_1 ( V_2 ) -> V_5 . V_126 == * ( T_5 * ) V_112 ;
}
static int F_98 ( struct V_2 * V_2 , void * V_112 )
{
F_1 ( V_2 ) -> V_5 . V_126 = * ( T_5 * ) V_112 ;
return 0 ;
}
struct V_4 * F_99 ( T_5 V_125 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_100 ( V_123 , F_94 ( V_125 ) ,
F_97 , F_98 , & V_125 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_7 & V_127 ) {
V_5 -> V_128 = NULL ;
V_5 -> V_129 = NULL ;
V_5 -> V_11 = V_2 ;
V_5 -> V_18 = ( 1 << V_2 -> V_19 ) ;
V_5 -> V_130 = 0 ;
V_5 -> V_131 = 0 ;
V_2 -> V_132 = V_133 ;
V_2 -> V_134 = V_125 ;
V_2 -> V_103 = V_5 ;
V_2 -> V_104 . V_135 = & V_136 ;
F_101 ( & V_2 -> V_104 , V_137 ) ;
F_5 ( & V_106 ) ;
F_102 ( & V_5 -> V_100 , & V_138 ) ;
F_6 ( & V_106 ) ;
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
F_5 ( & V_106 ) ;
F_107 (bdev, &all_bdevs, bd_list) {
V_62 += V_5 -> V_11 -> V_12 -> V_13 ;
}
F_6 ( & V_106 ) ;
return V_62 ;
}
void F_108 ( struct V_4 * V_5 )
{
F_109 ( V_5 -> V_11 ) ;
}
static struct V_4 * F_110 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_5 ( & V_106 ) ;
V_5 = V_2 -> V_103 ;
if ( V_5 ) {
F_105 ( V_5 -> V_11 ) ;
F_6 ( & V_106 ) ;
return V_5 ;
}
F_6 ( & V_106 ) ;
V_5 = F_99 ( V_2 -> V_134 ) ;
if ( V_5 ) {
F_5 ( & V_106 ) ;
if ( ! V_2 -> V_103 ) {
F_105 ( V_5 -> V_11 ) ;
V_2 -> V_103 = V_5 ;
V_2 -> V_12 = V_5 -> V_11 -> V_12 ;
F_102 ( & V_2 -> V_102 , & V_5 -> V_99 ) ;
}
F_6 ( & V_106 ) ;
}
return V_5 ;
}
int F_111 ( struct V_20 * V_21 )
{
return V_21 == V_123 ;
}
void F_112 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_5 ( & V_106 ) ;
if ( ! F_111 ( V_2 -> V_139 ) )
V_5 = V_2 -> V_103 ;
F_79 ( V_2 ) ;
F_6 ( & V_106 ) ;
if ( V_5 )
F_109 ( V_5 -> V_11 ) ;
}
static bool F_113 ( struct V_4 * V_5 , struct V_4 * V_140 ,
void * V_141 )
{
if ( V_5 -> V_142 == V_141 )
return true ;
else if ( V_5 -> V_142 != NULL )
return false ;
else if ( V_5 -> V_128 == V_5 )
return true ;
else if ( V_140 -> V_142 == F_113 )
return true ;
else if ( V_140 -> V_142 != NULL )
return false ;
else
return true ;
}
static int F_114 ( struct V_4 * V_5 ,
struct V_4 * V_140 , void * V_141 )
{
V_143:
if ( ! F_113 ( V_5 , V_140 , V_141 ) )
return - V_144 ;
if ( V_140 -> V_145 ) {
T_6 * V_146 = F_115 ( & V_140 -> V_145 , 0 ) ;
F_116 ( V_42 ) ;
F_117 ( V_146 , & V_42 , V_147 ) ;
F_6 ( & V_106 ) ;
F_118 () ;
F_119 ( V_146 , & V_42 ) ;
F_5 ( & V_106 ) ;
goto V_143;
}
return 0 ;
}
static struct V_4 * F_120 ( struct V_4 * V_5 ,
void * V_141 )
{
struct V_148 * V_149 ;
struct V_4 * V_140 ;
int V_150 , V_115 ;
F_121 () ;
V_149 = F_122 ( V_5 -> V_126 , & V_150 ) ;
if ( ! V_149 )
return F_39 ( - V_151 ) ;
if ( V_150 )
V_140 = F_123 ( V_149 , 0 ) ;
else
V_140 = F_104 ( V_5 ) ;
F_124 ( V_149 -> V_76 -> V_152 ) ;
F_125 ( V_149 ) ;
if ( ! V_140 )
return F_39 ( - V_153 ) ;
F_5 ( & V_106 ) ;
V_115 = F_114 ( V_5 , V_140 , V_141 ) ;
if ( V_115 == 0 ) {
V_140 -> V_145 = V_141 ;
F_6 ( & V_106 ) ;
return V_140 ;
} else {
F_6 ( & V_106 ) ;
F_108 ( V_140 ) ;
return F_39 ( V_115 ) ;
}
}
static struct V_154 * F_126 ( struct V_4 * V_5 ,
struct V_148 * V_149 )
{
struct V_154 * V_141 ;
F_107 (holder, &bdev->bd_holder_disks, list)
if ( V_141 -> V_149 == V_149 )
return V_141 ;
return NULL ;
}
static int F_127 ( struct V_155 * V_156 , struct V_155 * V_157 )
{
return F_128 ( V_156 , V_157 , F_129 ( V_157 ) ) ;
}
static void F_130 ( struct V_155 * V_156 , struct V_155 * V_157 )
{
F_131 ( V_156 , F_129 ( V_157 ) ) ;
}
int F_132 ( struct V_4 * V_5 , struct V_148 * V_149 )
{
struct V_154 * V_141 ;
int V_62 = 0 ;
F_35 ( & V_5 -> V_98 ) ;
F_7 ( ! V_5 -> V_142 ) ;
if ( F_133 ( ! V_149 -> V_158 || ! V_5 -> V_89 -> V_159 ) )
goto V_160;
V_141 = F_126 ( V_5 , V_149 ) ;
if ( V_141 ) {
V_141 -> V_161 ++ ;
goto V_160;
}
V_141 = F_134 ( sizeof( * V_141 ) , V_70 ) ;
if ( ! V_141 ) {
V_62 = - V_153 ;
goto V_160;
}
F_76 ( & V_141 -> V_162 ) ;
V_141 -> V_149 = V_149 ;
V_141 -> V_161 = 1 ;
V_62 = F_127 ( V_149 -> V_158 , & F_135 ( V_5 -> V_89 ) -> V_163 ) ;
if ( V_62 )
goto V_164;
V_62 = F_127 ( V_5 -> V_89 -> V_159 , & F_136 ( V_149 ) -> V_163 ) ;
if ( V_62 )
goto V_165;
F_137 ( V_5 -> V_89 -> V_159 ) ;
F_102 ( & V_141 -> V_162 , & V_5 -> V_101 ) ;
goto V_160;
V_165:
F_130 ( V_149 -> V_158 , & F_135 ( V_5 -> V_89 ) -> V_163 ) ;
V_164:
F_138 ( V_141 ) ;
V_160:
F_36 ( & V_5 -> V_98 ) ;
return V_62 ;
}
void F_139 ( struct V_4 * V_5 , struct V_148 * V_149 )
{
struct V_154 * V_141 ;
F_35 ( & V_5 -> V_98 ) ;
V_141 = F_126 ( V_5 , V_149 ) ;
if ( ! F_7 ( V_141 == NULL ) && ! -- V_141 -> V_161 ) {
F_130 ( V_149 -> V_158 , & F_135 ( V_5 -> V_89 ) -> V_163 ) ;
F_130 ( V_5 -> V_89 -> V_159 ,
& F_136 ( V_149 ) -> V_163 ) ;
F_140 ( V_5 -> V_89 -> V_159 ) ;
F_80 ( & V_141 -> V_162 ) ;
F_138 ( V_141 ) ;
}
F_36 ( & V_5 -> V_98 ) ;
}
static void F_141 ( struct V_4 * V_5 , bool V_166 )
{
if ( F_142 ( V_5 , V_166 ) ) {
char V_167 [ V_168 ] = L_5 ;
if ( V_5 -> V_75 )
F_143 ( V_5 -> V_75 , 0 , V_167 ) ;
F_144 ( V_169 L_6
L_7 , V_167 ) ;
}
if ( ! V_5 -> V_75 )
return;
if ( F_145 ( V_5 -> V_75 ) )
V_5 -> V_131 = 1 ;
}
void F_146 ( struct V_148 * V_149 , struct V_4 * V_5 )
{
T_3 V_170 , V_171 ;
V_170 = ( T_3 ) F_147 ( V_149 ) << 9 ;
V_171 = F_55 ( V_5 -> V_11 ) ;
if ( V_170 != V_171 ) {
char V_167 [ V_168 ] ;
F_143 ( V_149 , 0 , V_167 ) ;
F_144 ( V_172
L_8 ,
V_167 , V_171 , V_170 ) ;
F_148 ( V_5 -> V_11 , V_170 ) ;
F_141 ( V_5 , false ) ;
}
}
int F_149 ( struct V_148 * V_149 )
{
struct V_4 * V_5 ;
int V_62 = 0 ;
if ( V_149 -> V_76 -> F_149 )
V_62 = V_149 -> V_76 -> F_149 ( V_149 ) ;
V_5 = F_123 ( V_149 , 0 ) ;
if ( ! V_5 )
return V_62 ;
F_35 ( & V_5 -> V_98 ) ;
F_146 ( V_149 , V_5 ) ;
V_5 -> V_131 = 0 ;
F_36 ( & V_5 -> V_98 ) ;
F_108 ( V_5 ) ;
return V_62 ;
}
int F_150 ( struct V_4 * V_5 )
{
struct V_148 * V_149 = V_5 -> V_75 ;
const struct V_73 * V_173 = V_149 -> V_76 ;
unsigned int V_174 ;
V_174 = F_151 ( V_149 , V_175 |
V_176 ) ;
if ( ! ( V_174 & V_175 ) )
return 0 ;
F_141 ( V_5 , true ) ;
if ( V_173 -> F_149 )
V_173 -> F_149 ( V_5 -> V_75 ) ;
return 1 ;
}
void F_152 ( struct V_4 * V_5 , T_3 V_15 )
{
unsigned V_177 = F_18 ( V_5 ) ;
F_35 ( & V_5 -> V_11 -> V_65 ) ;
F_148 ( V_5 -> V_11 , V_15 ) ;
F_36 ( & V_5 -> V_11 -> V_65 ) ;
while ( V_177 < V_178 ) {
if ( V_15 & V_177 )
break;
V_177 <<= 1 ;
}
V_5 -> V_18 = V_177 ;
V_5 -> V_11 -> V_19 = F_20 ( V_177 ) ;
}
static int F_153 ( struct V_4 * V_5 , T_7 V_179 , int V_180 )
{
struct V_148 * V_149 ;
struct V_181 * V_152 ;
int V_62 ;
int V_150 ;
int V_182 = 0 ;
if ( V_179 & V_183 )
V_182 |= V_184 ;
if ( V_179 & V_185 )
V_182 |= V_186 ;
if ( ! V_180 ) {
V_62 = F_154 ( V_5 -> V_11 , V_182 ) ;
if ( V_62 != 0 ) {
F_108 ( V_5 ) ;
return V_62 ;
}
}
V_187:
V_62 = - V_151 ;
V_149 = F_122 ( V_5 -> V_126 , & V_150 ) ;
if ( ! V_149 )
goto V_46;
V_152 = V_149 -> V_76 -> V_152 ;
F_155 ( V_149 ) ;
F_156 ( & V_5 -> V_98 , V_180 ) ;
if ( ! V_5 -> V_188 ) {
V_5 -> V_75 = V_149 ;
V_5 -> V_189 = V_149 -> V_190 ;
V_5 -> V_128 = V_5 ;
if ( ! V_150 ) {
V_62 = - V_151 ;
V_5 -> V_89 = F_157 ( V_149 , V_150 ) ;
if ( ! V_5 -> V_89 )
goto V_191;
V_62 = 0 ;
if ( V_149 -> V_76 -> V_192 ) {
V_62 = V_149 -> V_76 -> V_192 ( V_5 , V_179 ) ;
if ( V_62 == - V_193 ) {
F_158 ( V_5 -> V_89 ) ;
V_5 -> V_89 = NULL ;
V_5 -> V_75 = NULL ;
V_5 -> V_189 = NULL ;
F_36 ( & V_5 -> V_98 ) ;
F_159 ( V_149 ) ;
F_125 ( V_149 ) ;
F_124 ( V_152 ) ;
goto V_187;
}
}
if ( ! V_62 )
F_152 ( V_5 , ( T_3 ) F_147 ( V_149 ) << 9 ) ;
if ( V_5 -> V_131 ) {
if ( ! V_62 )
F_160 ( V_149 , V_5 ) ;
else if ( V_62 == - V_194 )
F_161 ( V_149 , V_5 ) ;
}
if ( V_62 )
goto V_191;
} else {
struct V_4 * V_140 ;
V_140 = F_123 ( V_149 , 0 ) ;
V_62 = - V_153 ;
if ( ! V_140 )
goto V_191;
F_162 ( V_180 ) ;
V_62 = F_153 ( V_140 , V_179 , 1 ) ;
if ( V_62 )
goto V_191;
V_5 -> V_128 = V_140 ;
V_5 -> V_89 = F_157 ( V_149 , V_150 ) ;
if ( ! ( V_149 -> V_58 & V_195 ) ||
! V_5 -> V_89 || ! V_5 -> V_89 -> V_196 ) {
V_62 = - V_151 ;
goto V_191;
}
F_152 ( V_5 , ( T_3 ) V_5 -> V_89 -> V_196 << 9 ) ;
}
} else {
if ( V_5 -> V_128 == V_5 ) {
V_62 = 0 ;
if ( V_5 -> V_75 -> V_76 -> V_192 )
V_62 = V_5 -> V_75 -> V_76 -> V_192 ( V_5 , V_179 ) ;
if ( V_5 -> V_131 ) {
if ( ! V_62 )
F_160 ( V_5 -> V_75 , V_5 ) ;
else if ( V_62 == - V_194 )
F_161 ( V_5 -> V_75 , V_5 ) ;
}
if ( V_62 )
goto V_197;
}
F_125 ( V_149 ) ;
F_124 ( V_152 ) ;
}
V_5 -> V_188 ++ ;
if ( V_180 )
V_5 -> V_130 ++ ;
F_36 ( & V_5 -> V_98 ) ;
F_159 ( V_149 ) ;
return 0 ;
V_191:
F_158 ( V_5 -> V_89 ) ;
V_5 -> V_75 = NULL ;
V_5 -> V_89 = NULL ;
V_5 -> V_189 = NULL ;
if ( V_5 != V_5 -> V_128 )
F_163 ( V_5 -> V_128 , V_179 , 1 ) ;
V_5 -> V_128 = NULL ;
V_197:
F_36 ( & V_5 -> V_98 ) ;
F_159 ( V_149 ) ;
F_125 ( V_149 ) ;
F_124 ( V_152 ) ;
V_46:
F_108 ( V_5 ) ;
return V_62 ;
}
int F_164 ( struct V_4 * V_5 , T_7 V_179 , void * V_141 )
{
struct V_4 * V_140 = NULL ;
int V_43 ;
F_7 ( ( V_179 & V_198 ) && ! V_141 ) ;
if ( ( V_179 & V_198 ) && V_141 ) {
V_140 = F_120 ( V_5 , V_141 ) ;
if ( F_93 ( V_140 ) ) {
F_108 ( V_5 ) ;
return F_165 ( V_140 ) ;
}
}
V_43 = F_153 ( V_5 , V_179 , 0 ) ;
if ( V_140 ) {
struct V_148 * V_149 = V_140 -> V_75 ;
F_35 ( & V_5 -> V_98 ) ;
F_5 ( & V_106 ) ;
if ( ! V_43 ) {
F_162 ( ! F_113 ( V_5 , V_140 , V_141 ) ) ;
V_140 -> V_199 ++ ;
V_140 -> V_142 = F_113 ;
V_5 -> V_199 ++ ;
V_5 -> V_142 = V_141 ;
}
F_162 ( V_140 -> V_145 != V_141 ) ;
V_140 -> V_145 = NULL ;
F_166 ( & V_140 -> V_145 , 0 ) ;
F_6 ( & V_106 ) ;
if ( ! V_43 && ( V_179 & V_185 ) && ! V_5 -> V_200 &&
( V_149 -> V_58 & V_201 ) ) {
V_5 -> V_200 = true ;
F_155 ( V_149 ) ;
}
F_36 ( & V_5 -> V_98 ) ;
F_108 ( V_140 ) ;
}
return V_43 ;
}
struct V_4 * F_167 ( const char * V_202 , T_7 V_179 ,
void * V_141 )
{
struct V_4 * V_5 ;
int V_115 ;
V_5 = F_168 ( V_202 ) ;
if ( F_93 ( V_5 ) )
return V_5 ;
V_115 = F_164 ( V_5 , V_179 , V_141 ) ;
if ( V_115 )
return F_39 ( V_115 ) ;
if ( ( V_179 & V_185 ) && F_169 ( V_5 ) ) {
F_170 ( V_5 , V_179 ) ;
return F_39 ( - V_203 ) ;
}
return V_5 ;
}
struct V_4 * F_171 ( T_5 V_125 , T_7 V_179 , void * V_141 )
{
struct V_4 * V_5 ;
int V_115 ;
V_5 = F_99 ( V_125 ) ;
if ( ! V_5 )
return F_39 ( - V_153 ) ;
V_115 = F_164 ( V_5 , V_179 , V_141 ) ;
if ( V_115 )
return F_39 ( V_115 ) ;
return V_5 ;
}
static int F_172 ( struct V_2 * V_2 , struct V_37 * V_66 )
{
struct V_4 * V_5 ;
V_66 -> V_204 |= V_205 ;
if ( V_66 -> V_204 & V_206 )
V_66 -> V_207 |= V_208 ;
if ( V_66 -> V_204 & V_209 )
V_66 -> V_207 |= V_198 ;
if ( ( V_66 -> V_204 & V_210 ) == 3 )
V_66 -> V_207 |= V_211 ;
V_5 = F_110 ( V_2 ) ;
if ( V_5 == NULL )
return - V_153 ;
V_66 -> V_39 = V_5 -> V_11 -> V_12 ;
return F_164 ( V_5 , V_66 -> V_207 , V_66 ) ;
}
static void F_163 ( struct V_4 * V_5 , T_7 V_179 , int V_180 )
{
struct V_148 * V_149 = V_5 -> V_75 ;
struct V_4 * V_212 = NULL ;
F_156 ( & V_5 -> V_98 , V_180 ) ;
if ( V_180 )
V_5 -> V_130 -- ;
if ( ! -- V_5 -> V_188 ) {
F_7 ( V_5 -> V_199 ) ;
F_19 ( V_5 ) ;
F_9 ( V_5 ) ;
F_4 ( V_5 -> V_11 ) ;
}
if ( V_5 -> V_128 == V_5 ) {
if ( V_149 -> V_76 -> V_213 )
V_149 -> V_76 -> V_213 ( V_149 , V_179 ) ;
}
if ( ! V_5 -> V_188 ) {
struct V_181 * V_152 = V_149 -> V_76 -> V_152 ;
F_158 ( V_5 -> V_89 ) ;
V_5 -> V_89 = NULL ;
V_5 -> V_75 = NULL ;
if ( V_5 != V_5 -> V_128 )
V_212 = V_5 -> V_128 ;
V_5 -> V_128 = NULL ;
F_125 ( V_149 ) ;
F_124 ( V_152 ) ;
}
F_36 ( & V_5 -> V_98 ) ;
F_108 ( V_5 ) ;
if ( V_212 )
F_163 ( V_212 , V_179 , 1 ) ;
}
void F_170 ( struct V_4 * V_5 , T_7 V_179 )
{
F_35 ( & V_5 -> V_98 ) ;
if ( V_179 & V_198 ) {
bool V_214 ;
F_5 ( & V_106 ) ;
F_7 ( -- V_5 -> V_199 < 0 ) ;
F_7 ( -- V_5 -> V_128 -> V_199 < 0 ) ;
if ( ( V_214 = ! V_5 -> V_199 ) )
V_5 -> V_142 = NULL ;
if ( ! V_5 -> V_128 -> V_199 )
V_5 -> V_128 -> V_142 = NULL ;
F_6 ( & V_106 ) ;
if ( V_214 && V_5 -> V_200 ) {
F_159 ( V_5 -> V_75 ) ;
V_5 -> V_200 = false ;
}
}
F_173 ( V_5 -> V_75 , V_175 ) ;
F_36 ( & V_5 -> V_98 ) ;
F_163 ( V_5 , V_179 , 0 ) ;
}
static int F_174 ( struct V_2 * V_2 , struct V_37 * V_66 )
{
struct V_4 * V_5 = F_3 ( V_66 -> V_39 -> V_40 ) ;
F_170 ( V_5 , V_66 -> V_207 ) ;
return 0 ;
}
static long F_175 ( struct V_37 * V_37 , unsigned V_215 , unsigned long V_216 )
{
struct V_4 * V_5 = F_3 ( V_37 -> V_39 -> V_40 ) ;
T_7 V_179 = V_37 -> V_207 ;
if ( V_37 -> V_204 & V_206 )
V_179 |= V_208 ;
else
V_179 &= ~ V_208 ;
return F_176 ( V_5 , V_179 , V_215 , V_216 ) ;
}
T_2 F_177 ( struct V_32 * V_33 , struct V_34 * V_156 )
{
struct V_37 * V_37 = V_33 -> V_38 ;
struct V_2 * V_11 = V_37 -> V_39 -> V_40 ;
T_3 V_15 = F_55 ( V_11 ) ;
struct V_217 V_218 ;
T_2 V_62 ;
if ( F_169 ( F_3 ( V_11 ) ) )
return - V_219 ;
if ( ! F_178 ( V_156 ) )
return 0 ;
if ( V_33 -> V_220 >= V_15 )
return - V_221 ;
F_179 ( V_156 , V_15 - V_33 -> V_220 ) ;
F_180 ( & V_218 ) ;
V_62 = F_181 ( V_33 , V_156 ) ;
if ( V_62 > 0 ) {
T_2 V_115 ;
V_115 = F_182 ( V_37 , V_33 -> V_220 - V_62 , V_62 ) ;
if ( V_115 < 0 )
V_62 = V_115 ;
}
F_183 ( & V_218 ) ;
return V_62 ;
}
T_2 F_184 ( struct V_32 * V_33 , struct V_34 * V_157 )
{
struct V_37 * V_37 = V_33 -> V_38 ;
struct V_2 * V_11 = V_37 -> V_39 -> V_40 ;
T_3 V_15 = F_55 ( V_11 ) ;
T_3 V_56 = V_33 -> V_220 ;
if ( V_56 >= V_15 )
return 0 ;
V_15 -= V_56 ;
F_179 ( V_157 , V_15 ) ;
return F_185 ( V_33 , V_157 ) ;
}
static int F_186 ( struct V_50 * V_50 , T_8 V_42 )
{
struct V_20 * V_222 = F_1 ( V_50 -> V_10 -> V_40 ) -> V_5 . V_129 ;
if ( V_222 && V_222 -> V_47 -> V_223 )
return V_222 -> V_47 -> V_223 ( V_222 , V_50 , V_42 ) ;
return F_187 ( V_50 ) ;
}
int F_188 ( struct V_4 * V_5 , unsigned V_215 , unsigned long V_216 )
{
int V_43 ;
T_9 V_224 = F_189 () ;
F_190 ( V_225 ) ;
V_43 = F_176 ( V_5 , 0 , V_215 , V_216 ) ;
F_190 ( V_224 ) ;
return V_43 ;
}
struct V_4 * F_168 ( const char * V_226 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_202 V_202 ;
int error ;
if ( ! V_226 || ! * V_226 )
return F_39 ( - V_17 ) ;
error = F_191 ( V_226 , V_227 , & V_202 ) ;
if ( error )
return F_39 ( error ) ;
V_2 = F_192 ( V_202 . V_108 ) ;
error = - V_228 ;
if ( ! F_193 ( V_2 -> V_132 ) )
goto V_229;
error = - V_203 ;
if ( V_202 . V_230 -> V_231 & V_232 )
goto V_229;
error = - V_153 ;
V_5 = F_110 ( V_2 ) ;
if ( ! V_5 )
goto V_229;
V_46:
F_194 ( & V_202 ) ;
return V_5 ;
V_229:
V_5 = F_39 ( error ) ;
goto V_46;
}
int F_142 ( struct V_4 * V_5 , bool V_166 )
{
struct V_20 * V_21 = F_31 ( V_5 ) ;
int V_43 = 0 ;
if ( V_21 ) {
F_195 ( V_21 ) ;
V_43 = F_196 ( V_21 , V_166 ) ;
F_33 ( V_21 ) ;
}
F_12 ( V_5 ) ;
return V_43 ;
}
void F_197 ( void (* F_198)( struct V_4 * , void * ) , void * V_216 )
{
struct V_2 * V_2 , * V_233 = NULL ;
F_5 ( & V_234 ) ;
F_107 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_9 * V_10 = V_2 -> V_12 ;
F_5 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_7 & ( V_235 | V_236 | V_127 ) ||
V_10 -> V_13 == 0 ) {
F_6 ( & V_2 -> V_6 ) ;
continue;
}
F_199 ( V_2 ) ;
F_6 ( & V_2 -> V_6 ) ;
F_6 ( & V_234 ) ;
F_109 ( V_233 ) ;
V_233 = V_2 ;
F_198 ( F_3 ( V_2 ) , V_216 ) ;
F_5 ( & V_234 ) ;
}
F_6 ( & V_234 ) ;
F_109 ( V_233 ) ;
}

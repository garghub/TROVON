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
F_29 ( int V_41 , struct V_42 * V_43 , const struct V_44 * V_45 ,
T_3 V_46 , unsigned long V_47 )
{
struct V_48 * V_48 = V_43 -> V_49 ;
struct V_2 * V_2 = V_48 -> V_50 -> V_51 ;
return F_30 ( V_41 , V_43 , V_2 , F_3 ( V_2 ) , V_45 , V_46 ,
V_47 , F_27 , NULL , NULL , 0 ) ;
}
int F_31 ( struct V_4 * V_5 , int V_52 )
{
if ( ! V_5 )
return 0 ;
if ( ! V_52 )
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
int V_53 = F_36 ( V_30 ) ;
F_37 ( V_30 ) ;
return V_53 ;
}
return F_23 ( V_5 ) ;
}
struct V_29 * F_38 ( struct V_4 * V_5 )
{
struct V_29 * V_30 ;
int error = 0 ;
F_39 ( & V_5 -> V_54 ) ;
if ( ++ V_5 -> V_55 > 1 ) {
V_30 = F_35 ( V_5 ) ;
F_37 ( V_30 ) ;
F_40 ( & V_5 -> V_54 ) ;
return V_30 ;
}
V_30 = F_41 ( V_5 ) ;
if ( ! V_30 )
goto V_56;
error = F_42 ( V_30 ) ;
if ( error ) {
F_43 ( V_30 ) ;
V_5 -> V_55 -- ;
F_40 ( & V_5 -> V_54 ) ;
return F_44 ( error ) ;
}
F_43 ( V_30 ) ;
V_56:
F_23 ( V_5 ) ;
F_40 ( & V_5 -> V_54 ) ;
return V_30 ;
}
int F_45 ( struct V_4 * V_5 , struct V_29 * V_30 )
{
int error = - V_26 ;
F_39 ( & V_5 -> V_54 ) ;
if ( ! V_5 -> V_55 )
goto V_56;
error = 0 ;
if ( -- V_5 -> V_55 > 0 )
goto V_56;
if ( ! V_30 )
goto V_56;
error = F_46 ( V_30 ) ;
if ( error ) {
V_5 -> V_55 ++ ;
F_40 ( & V_5 -> V_54 ) ;
return error ;
}
V_56:
F_40 ( & V_5 -> V_54 ) ;
return 0 ;
}
static int F_47 ( struct V_57 * V_57 , struct V_58 * V_59 )
{
return F_48 ( V_57 , F_27 , V_59 ) ;
}
static int F_49 ( struct V_48 * V_48 , struct V_57 * V_57 )
{
return F_50 ( V_57 , F_27 ) ;
}
static int F_51 ( struct V_48 * V_48 , struct V_18 * V_19 ,
T_3 V_60 , unsigned V_61 , unsigned V_62 ,
struct V_57 * * V_63 , void * * V_64 )
{
return F_52 ( V_19 , V_60 , V_61 , V_62 , V_63 ,
F_27 ) ;
}
static int F_53 ( struct V_48 * V_48 , struct V_18 * V_19 ,
T_3 V_60 , unsigned V_61 , unsigned V_65 ,
struct V_57 * V_57 , void * V_64 )
{
int V_66 ;
V_66 = F_54 ( V_48 , V_19 , V_60 , V_61 , V_65 , V_57 , V_64 ) ;
F_55 ( V_57 ) ;
F_56 ( V_57 ) ;
return V_66 ;
}
static T_3 F_57 ( struct V_48 * V_48 , T_3 V_46 , int V_67 )
{
struct V_2 * V_20 = V_48 -> V_50 -> V_51 ;
T_3 V_68 ;
F_39 ( & V_20 -> V_69 ) ;
V_68 = F_58 ( V_48 , V_46 , V_67 , F_59 ( V_20 ) ) ;
F_40 ( & V_20 -> V_69 ) ;
return V_68 ;
}
int F_60 ( struct V_48 * V_70 , T_3 V_71 , T_3 V_72 , int V_73 )
{
struct V_2 * V_20 = V_70 -> V_50 -> V_51 ;
struct V_4 * V_5 = F_3 ( V_20 ) ;
int error ;
error = F_61 ( V_70 -> V_50 , V_71 , V_72 ) ;
if ( error )
return error ;
error = F_62 ( V_5 , V_74 , NULL ) ;
if ( error == - V_75 )
error = 0 ;
return error ;
}
static struct V_2 * F_63 ( struct V_29 * V_30 )
{
struct V_1 * V_76 = F_64 ( V_77 , V_74 ) ;
if ( ! V_76 )
return NULL ;
return & V_76 -> V_3 ;
}
static void F_65 ( struct V_78 * V_79 )
{
struct V_2 * V_2 = F_2 ( V_79 , struct V_2 , V_80 ) ;
struct V_1 * V_81 = F_1 ( V_2 ) ;
F_66 ( V_77 , V_81 ) ;
}
static void F_67 ( struct V_2 * V_2 )
{
F_68 ( & V_2 -> V_80 , F_65 ) ;
}
static void F_69 ( void * V_82 )
{
struct V_1 * V_76 = (struct V_1 * ) V_82 ;
struct V_4 * V_5 = & V_76 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_70 ( & V_5 -> V_83 ) ;
F_71 ( & V_5 -> V_84 ) ;
F_71 ( & V_5 -> V_85 ) ;
#ifdef F_72
F_71 ( & V_5 -> V_86 ) ;
#endif
F_73 ( & V_76 -> V_3 ) ;
F_70 ( & V_5 -> V_54 ) ;
}
static inline void F_74 ( struct V_2 * V_2 )
{
F_75 ( & V_2 -> V_87 ) ;
V_2 -> V_88 = NULL ;
V_2 -> V_21 = & V_2 -> V_9 ;
}
static void F_76 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
struct V_89 * V_90 ;
F_77 ( & V_2 -> V_9 ) ;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
F_7 ( & V_91 ) ;
while ( ( V_90 = V_5 -> V_84 . V_92 ) != & V_5 -> V_84 ) {
F_74 ( F_80 ( V_90 , struct V_2 , V_87 ) ) ;
}
F_75 ( & V_5 -> V_85 ) ;
F_11 ( & V_91 ) ;
}
static struct V_93 * F_81 ( struct V_94 * V_95 ,
int V_62 , const char * V_96 , void * V_97 )
{
return F_82 ( V_95 , L_1 , & V_98 , NULL , V_99 ) ;
}
void T_4 F_83 ( void )
{
int V_100 ;
static struct V_101 * V_102 ;
V_77 = F_84 ( L_2 , sizeof( struct V_1 ) ,
0 , ( V_103 | V_104 |
V_105 | V_106 ) ,
F_69 ) ;
V_100 = F_85 ( & V_107 ) ;
if ( V_100 )
F_86 ( L_3 ) ;
V_102 = F_87 ( & V_107 ) ;
if ( F_88 ( V_102 ) )
F_86 ( L_4 ) ;
V_108 = V_102 -> V_109 ;
}
static inline unsigned long F_89 ( T_5 V_110 )
{
return F_90 ( V_110 ) + F_91 ( V_110 ) ;
}
static int F_92 ( struct V_2 * V_2 , void * V_97 )
{
return F_1 ( V_2 ) -> V_5 . V_111 == * ( T_5 * ) V_97 ;
}
static int F_93 ( struct V_2 * V_2 , void * V_97 )
{
F_1 ( V_2 ) -> V_5 . V_111 = * ( T_5 * ) V_97 ;
return 0 ;
}
struct V_4 * F_94 ( T_5 V_110 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_95 ( V_108 , F_89 ( V_110 ) ,
F_92 , F_93 , & V_110 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_13 & V_112 ) {
V_5 -> V_113 = NULL ;
V_5 -> V_114 = NULL ;
V_5 -> V_20 = V_2 ;
V_5 -> V_27 = ( 1 << V_2 -> V_28 ) ;
V_5 -> V_115 = 0 ;
V_5 -> V_116 = 0 ;
V_2 -> V_117 = V_118 ;
V_2 -> V_119 = V_110 ;
V_2 -> V_88 = V_5 ;
V_2 -> V_9 . V_120 = & V_121 ;
F_96 ( & V_2 -> V_9 , V_122 ) ;
V_2 -> V_9 . V_6 = & V_123 ;
F_7 ( & V_91 ) ;
F_97 ( & V_5 -> V_85 , & V_124 ) ;
F_11 ( & V_91 ) ;
F_98 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_99 ( struct V_4 * V_5 )
{
F_100 ( V_5 -> V_20 ) ;
return V_5 ;
}
long F_101 ( void )
{
struct V_4 * V_5 ;
long V_66 = 0 ;
F_7 ( & V_91 ) ;
F_102 (bdev, &all_bdevs, bd_list) {
V_66 += V_5 -> V_20 -> V_21 -> V_22 ;
}
F_11 ( & V_91 ) ;
return V_66 ;
}
void F_103 ( struct V_4 * V_5 )
{
F_104 ( V_5 -> V_20 ) ;
}
static struct V_4 * F_105 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_7 ( & V_91 ) ;
V_5 = V_2 -> V_88 ;
if ( V_5 ) {
F_100 ( V_5 -> V_20 ) ;
F_11 ( & V_91 ) ;
return V_5 ;
}
F_11 ( & V_91 ) ;
V_5 = F_94 ( V_2 -> V_119 ) ;
if ( V_5 ) {
F_7 ( & V_91 ) ;
if ( ! V_2 -> V_88 ) {
F_100 ( V_5 -> V_20 ) ;
V_2 -> V_88 = V_5 ;
V_2 -> V_21 = V_5 -> V_20 -> V_21 ;
F_97 ( & V_2 -> V_87 , & V_5 -> V_84 ) ;
}
F_11 ( & V_91 ) ;
}
return V_5 ;
}
int F_106 ( struct V_29 * V_30 )
{
return V_30 == V_108 ;
}
void F_107 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_7 ( & V_91 ) ;
if ( ! F_106 ( V_2 -> V_125 ) )
V_5 = V_2 -> V_88 ;
F_74 ( V_2 ) ;
F_11 ( & V_91 ) ;
if ( V_5 )
F_104 ( V_5 -> V_20 ) ;
}
static bool F_108 ( struct V_4 * V_5 , struct V_4 * V_126 ,
void * V_127 )
{
if ( V_5 -> V_128 == V_127 )
return true ;
else if ( V_5 -> V_128 != NULL )
return false ;
else if ( V_5 -> V_113 == V_5 )
return true ;
else if ( V_126 -> V_128 == F_108 )
return true ;
else if ( V_126 -> V_128 != NULL )
return false ;
else
return true ;
}
static int F_109 ( struct V_4 * V_5 ,
struct V_4 * V_126 , void * V_127 )
{
V_129:
if ( ! F_108 ( V_5 , V_126 , V_127 ) )
return - V_130 ;
if ( V_126 -> V_131 ) {
T_6 * V_132 = F_110 ( & V_126 -> V_131 , 0 ) ;
F_111 ( V_52 ) ;
F_112 ( V_132 , & V_52 , V_133 ) ;
F_11 ( & V_91 ) ;
F_113 () ;
F_114 ( V_132 , & V_52 ) ;
F_7 ( & V_91 ) ;
goto V_129;
}
return 0 ;
}
static struct V_4 * F_115 ( struct V_4 * V_5 ,
void * V_127 )
{
struct V_134 * V_135 ;
struct V_4 * V_126 ;
int V_136 , V_100 ;
F_116 () ;
V_135 = F_117 ( V_5 -> V_111 , & V_136 ) ;
if ( ! V_135 )
return F_44 ( - V_137 ) ;
if ( V_136 )
V_126 = F_118 ( V_135 , 0 ) ;
else
V_126 = F_99 ( V_5 ) ;
F_119 ( V_135 -> V_138 -> V_139 ) ;
F_120 ( V_135 ) ;
if ( ! V_126 )
return F_44 ( - V_140 ) ;
F_7 ( & V_91 ) ;
V_100 = F_109 ( V_5 , V_126 , V_127 ) ;
if ( V_100 == 0 ) {
V_126 -> V_131 = V_127 ;
F_11 ( & V_91 ) ;
return V_126 ;
} else {
F_11 ( & V_91 ) ;
F_103 ( V_126 ) ;
return F_44 ( V_100 ) ;
}
}
static struct V_141 * F_121 ( struct V_4 * V_5 ,
struct V_134 * V_135 )
{
struct V_141 * V_127 ;
F_102 (holder, &bdev->bd_holder_disks, list)
if ( V_127 -> V_135 == V_135 )
return V_127 ;
return NULL ;
}
static int F_122 ( struct V_142 * V_143 , struct V_142 * V_144 )
{
return F_123 ( V_143 , V_144 , F_124 ( V_144 ) ) ;
}
static void F_125 ( struct V_142 * V_143 , struct V_142 * V_144 )
{
F_126 ( V_143 , F_124 ( V_144 ) ) ;
}
int F_127 ( struct V_4 * V_5 , struct V_134 * V_135 )
{
struct V_141 * V_127 ;
int V_66 = 0 ;
F_39 ( & V_5 -> V_83 ) ;
F_128 ( ! V_5 -> V_128 ) ;
if ( F_129 ( ! V_135 -> V_145 || ! V_5 -> V_146 -> V_147 ) )
goto V_148;
V_127 = F_121 ( V_5 , V_135 ) ;
if ( V_127 ) {
V_127 -> V_149 ++ ;
goto V_148;
}
V_127 = F_130 ( sizeof( * V_127 ) , V_74 ) ;
if ( ! V_127 ) {
V_66 = - V_140 ;
goto V_148;
}
F_71 ( & V_127 -> V_150 ) ;
V_127 -> V_135 = V_135 ;
V_127 -> V_149 = 1 ;
V_66 = F_122 ( V_135 -> V_145 , & F_131 ( V_5 -> V_146 ) -> V_151 ) ;
if ( V_66 )
goto V_152;
V_66 = F_122 ( V_5 -> V_146 -> V_147 , & F_132 ( V_135 ) -> V_151 ) ;
if ( V_66 )
goto V_153;
F_133 ( V_5 -> V_146 -> V_147 ) ;
F_97 ( & V_127 -> V_150 , & V_5 -> V_86 ) ;
goto V_148;
V_153:
F_125 ( V_135 -> V_145 , & F_131 ( V_5 -> V_146 ) -> V_151 ) ;
V_152:
F_134 ( V_127 ) ;
V_148:
F_40 ( & V_5 -> V_83 ) ;
return V_66 ;
}
void F_135 ( struct V_4 * V_5 , struct V_134 * V_135 )
{
struct V_141 * V_127 ;
F_39 ( & V_5 -> V_83 ) ;
V_127 = F_121 ( V_5 , V_135 ) ;
if ( ! F_128 ( V_127 == NULL ) && ! -- V_127 -> V_149 ) {
F_125 ( V_135 -> V_145 , & F_131 ( V_5 -> V_146 ) -> V_151 ) ;
F_125 ( V_5 -> V_146 -> V_147 ,
& F_132 ( V_135 ) -> V_151 ) ;
F_136 ( V_5 -> V_146 -> V_147 ) ;
F_75 ( & V_127 -> V_150 ) ;
F_134 ( V_127 ) ;
}
F_40 ( & V_5 -> V_83 ) ;
}
static void F_137 ( struct V_4 * V_5 , bool V_154 )
{
if ( F_138 ( V_5 , V_154 ) ) {
char V_155 [ V_156 ] = L_5 ;
if ( V_5 -> V_157 )
F_139 ( V_5 -> V_157 , 0 , V_155 ) ;
F_140 ( V_158 L_6
L_7 , V_155 ) ;
}
if ( ! V_5 -> V_157 )
return;
if ( F_141 ( V_5 -> V_157 ) )
V_5 -> V_116 = 1 ;
}
void F_142 ( struct V_134 * V_135 , struct V_4 * V_5 )
{
T_3 V_159 , V_160 ;
V_159 = ( T_3 ) F_143 ( V_135 ) << 9 ;
V_160 = F_59 ( V_5 -> V_20 ) ;
if ( V_159 != V_160 ) {
char V_155 [ V_156 ] ;
F_139 ( V_135 , 0 , V_155 ) ;
F_140 ( V_161
L_8 ,
V_155 , V_160 , V_159 ) ;
F_144 ( V_5 -> V_20 , V_159 ) ;
F_137 ( V_5 , false ) ;
}
}
int F_145 ( struct V_134 * V_135 )
{
struct V_4 * V_5 ;
int V_66 = 0 ;
if ( V_135 -> V_138 -> F_145 )
V_66 = V_135 -> V_138 -> F_145 ( V_135 ) ;
V_5 = F_118 ( V_135 , 0 ) ;
if ( ! V_5 )
return V_66 ;
F_39 ( & V_5 -> V_83 ) ;
F_142 ( V_135 , V_5 ) ;
V_5 -> V_116 = 0 ;
F_40 ( & V_5 -> V_83 ) ;
F_103 ( V_5 ) ;
return V_66 ;
}
int F_146 ( struct V_4 * V_5 )
{
struct V_134 * V_135 = V_5 -> V_157 ;
const struct V_162 * V_163 = V_135 -> V_138 ;
unsigned int V_164 ;
V_164 = F_147 ( V_135 , V_165 |
V_166 ) ;
if ( ! ( V_164 & V_165 ) )
return 0 ;
F_137 ( V_5 , true ) ;
if ( V_163 -> F_145 )
V_163 -> F_145 ( V_5 -> V_157 ) ;
return 1 ;
}
void F_148 ( struct V_4 * V_5 , T_3 V_24 )
{
unsigned V_167 = F_22 ( V_5 ) ;
F_39 ( & V_5 -> V_20 -> V_69 ) ;
F_144 ( V_5 -> V_20 , V_24 ) ;
F_40 ( & V_5 -> V_20 -> V_69 ) ;
while ( V_167 < V_168 ) {
if ( V_24 & V_167 )
break;
V_167 <<= 1 ;
}
V_5 -> V_27 = V_167 ;
V_5 -> V_20 -> V_28 = F_24 ( V_167 ) ;
}
static int F_149 ( struct V_4 * V_5 , T_7 V_169 , int V_170 )
{
struct V_134 * V_135 ;
struct V_171 * V_139 ;
int V_66 ;
int V_136 ;
int V_172 = 0 ;
if ( V_169 & V_173 )
V_172 |= V_174 ;
if ( V_169 & V_175 )
V_172 |= V_176 ;
if ( ! V_170 ) {
V_66 = F_150 ( V_5 -> V_20 , V_172 ) ;
if ( V_66 != 0 ) {
F_103 ( V_5 ) ;
return V_66 ;
}
}
V_177:
V_66 = - V_137 ;
V_135 = F_117 ( V_5 -> V_111 , & V_136 ) ;
if ( ! V_135 )
goto V_56;
V_139 = V_135 -> V_138 -> V_139 ;
F_151 ( V_135 ) ;
F_152 ( & V_5 -> V_83 , V_170 ) ;
if ( ! V_5 -> V_178 ) {
V_5 -> V_157 = V_135 ;
V_5 -> V_179 = V_135 -> V_180 ;
V_5 -> V_113 = V_5 ;
if ( ! V_136 ) {
struct V_6 * V_81 ;
V_66 = - V_137 ;
V_5 -> V_146 = F_153 ( V_135 , V_136 ) ;
if ( ! V_5 -> V_146 )
goto V_181;
V_66 = 0 ;
if ( V_135 -> V_138 -> V_182 ) {
V_66 = V_135 -> V_138 -> V_182 ( V_5 , V_169 ) ;
if ( V_66 == - V_183 ) {
F_154 ( V_5 -> V_146 ) ;
V_5 -> V_146 = NULL ;
V_5 -> V_157 = NULL ;
V_5 -> V_179 = NULL ;
F_40 ( & V_5 -> V_83 ) ;
F_155 ( V_135 ) ;
F_120 ( V_135 ) ;
F_119 ( V_139 ) ;
goto V_177;
}
}
if ( ! V_66 ) {
F_148 ( V_5 , ( T_3 ) F_143 ( V_135 ) << 9 ) ;
V_81 = F_156 ( V_5 ) ;
if ( V_81 == NULL )
V_81 = & V_123 ;
F_4 ( V_5 -> V_20 , V_81 ) ;
}
if ( V_5 -> V_116 ) {
if ( ! V_66 )
F_157 ( V_135 , V_5 ) ;
else if ( V_66 == - V_184 )
F_158 ( V_135 , V_5 ) ;
}
if ( V_66 )
goto V_181;
} else {
struct V_4 * V_126 ;
V_126 = F_118 ( V_135 , 0 ) ;
V_66 = - V_140 ;
if ( ! V_126 )
goto V_181;
F_159 ( V_170 ) ;
V_66 = F_149 ( V_126 , V_169 , 1 ) ;
if ( V_66 )
goto V_181;
V_5 -> V_113 = V_126 ;
F_4 ( V_5 -> V_20 ,
V_126 -> V_20 -> V_9 . V_6 ) ;
V_5 -> V_146 = F_153 ( V_135 , V_136 ) ;
if ( ! ( V_135 -> V_62 & V_185 ) ||
! V_5 -> V_146 || ! V_5 -> V_146 -> V_186 ) {
V_66 = - V_137 ;
goto V_181;
}
F_148 ( V_5 , ( T_3 ) V_5 -> V_146 -> V_186 << 9 ) ;
}
} else {
if ( V_5 -> V_113 == V_5 ) {
V_66 = 0 ;
if ( V_5 -> V_157 -> V_138 -> V_182 )
V_66 = V_5 -> V_157 -> V_138 -> V_182 ( V_5 , V_169 ) ;
if ( V_5 -> V_116 ) {
if ( ! V_66 )
F_157 ( V_5 -> V_157 , V_5 ) ;
else if ( V_66 == - V_184 )
F_158 ( V_5 -> V_157 , V_5 ) ;
}
if ( V_66 )
goto V_187;
}
F_120 ( V_135 ) ;
F_119 ( V_139 ) ;
}
V_5 -> V_178 ++ ;
if ( V_170 )
V_5 -> V_115 ++ ;
F_40 ( & V_5 -> V_83 ) ;
F_155 ( V_135 ) ;
return 0 ;
V_181:
F_154 ( V_5 -> V_146 ) ;
V_5 -> V_157 = NULL ;
V_5 -> V_146 = NULL ;
V_5 -> V_179 = NULL ;
F_4 ( V_5 -> V_20 , & V_123 ) ;
if ( V_5 != V_5 -> V_113 )
F_160 ( V_5 -> V_113 , V_169 , 1 ) ;
V_5 -> V_113 = NULL ;
V_187:
F_40 ( & V_5 -> V_83 ) ;
F_155 ( V_135 ) ;
F_120 ( V_135 ) ;
F_119 ( V_139 ) ;
V_56:
F_103 ( V_5 ) ;
return V_66 ;
}
int F_161 ( struct V_4 * V_5 , T_7 V_169 , void * V_127 )
{
struct V_4 * V_126 = NULL ;
int V_53 ;
F_128 ( ( V_169 & V_188 ) && ! V_127 ) ;
if ( ( V_169 & V_188 ) && V_127 ) {
V_126 = F_115 ( V_5 , V_127 ) ;
if ( F_88 ( V_126 ) ) {
F_103 ( V_5 ) ;
return F_162 ( V_126 ) ;
}
}
V_53 = F_149 ( V_5 , V_169 , 0 ) ;
if ( V_126 ) {
struct V_134 * V_135 = V_126 -> V_157 ;
F_39 ( & V_5 -> V_83 ) ;
F_7 ( & V_91 ) ;
if ( ! V_53 ) {
F_159 ( ! F_108 ( V_5 , V_126 , V_127 ) ) ;
V_126 -> V_189 ++ ;
V_126 -> V_128 = F_108 ;
V_5 -> V_189 ++ ;
V_5 -> V_128 = V_127 ;
}
F_159 ( V_126 -> V_131 != V_127 ) ;
V_126 -> V_131 = NULL ;
F_163 ( & V_126 -> V_131 , 0 ) ;
F_11 ( & V_91 ) ;
if ( ! V_53 && ( V_169 & V_175 ) && ! V_5 -> V_190 &&
( V_135 -> V_62 & V_191 ) ) {
V_5 -> V_190 = true ;
F_151 ( V_135 ) ;
}
F_40 ( & V_5 -> V_83 ) ;
F_103 ( V_126 ) ;
}
return V_53 ;
}
struct V_4 * F_164 ( const char * V_192 , T_7 V_169 ,
void * V_127 )
{
struct V_4 * V_5 ;
int V_100 ;
V_5 = F_165 ( V_192 ) ;
if ( F_88 ( V_5 ) )
return V_5 ;
V_100 = F_161 ( V_5 , V_169 , V_127 ) ;
if ( V_100 )
return F_44 ( V_100 ) ;
if ( ( V_169 & V_175 ) && F_166 ( V_5 ) ) {
F_167 ( V_5 , V_169 ) ;
return F_44 ( - V_193 ) ;
}
return V_5 ;
}
struct V_4 * F_168 ( T_5 V_110 , T_7 V_169 , void * V_127 )
{
struct V_4 * V_5 ;
int V_100 ;
V_5 = F_94 ( V_110 ) ;
if ( ! V_5 )
return F_44 ( - V_140 ) ;
V_100 = F_161 ( V_5 , V_169 , V_127 ) ;
if ( V_100 )
return F_44 ( V_100 ) ;
return V_5 ;
}
static int F_169 ( struct V_2 * V_2 , struct V_48 * V_70 )
{
struct V_4 * V_5 ;
V_70 -> V_194 |= V_195 ;
if ( V_70 -> V_194 & V_196 )
V_70 -> V_197 |= V_198 ;
if ( V_70 -> V_194 & V_199 )
V_70 -> V_197 |= V_188 ;
if ( ( V_70 -> V_194 & V_200 ) == 3 )
V_70 -> V_197 |= V_201 ;
V_5 = F_105 ( V_2 ) ;
if ( V_5 == NULL )
return - V_140 ;
V_70 -> V_50 = V_5 -> V_20 -> V_21 ;
return F_161 ( V_5 , V_70 -> V_197 , V_70 ) ;
}
static void F_160 ( struct V_4 * V_5 , T_7 V_169 , int V_170 )
{
struct V_134 * V_135 = V_5 -> V_157 ;
struct V_4 * V_202 = NULL ;
F_152 ( & V_5 -> V_83 , V_170 ) ;
if ( V_170 )
V_5 -> V_115 -- ;
if ( ! -- V_5 -> V_178 ) {
F_128 ( V_5 -> V_189 ) ;
F_23 ( V_5 ) ;
F_13 ( V_5 ) ;
F_4 ( V_5 -> V_20 ,
& V_123 ) ;
}
if ( V_5 -> V_113 == V_5 ) {
if ( V_135 -> V_138 -> V_203 )
V_135 -> V_138 -> V_203 ( V_135 , V_169 ) ;
}
if ( ! V_5 -> V_178 ) {
struct V_171 * V_139 = V_135 -> V_138 -> V_139 ;
F_154 ( V_5 -> V_146 ) ;
V_5 -> V_146 = NULL ;
V_5 -> V_157 = NULL ;
if ( V_5 != V_5 -> V_113 )
V_202 = V_5 -> V_113 ;
V_5 -> V_113 = NULL ;
F_120 ( V_135 ) ;
F_119 ( V_139 ) ;
}
F_40 ( & V_5 -> V_83 ) ;
F_103 ( V_5 ) ;
if ( V_202 )
F_160 ( V_202 , V_169 , 1 ) ;
}
void F_167 ( struct V_4 * V_5 , T_7 V_169 )
{
F_39 ( & V_5 -> V_83 ) ;
if ( V_169 & V_188 ) {
bool V_204 ;
F_7 ( & V_91 ) ;
F_128 ( -- V_5 -> V_189 < 0 ) ;
F_128 ( -- V_5 -> V_113 -> V_189 < 0 ) ;
if ( ( V_204 = ! V_5 -> V_189 ) )
V_5 -> V_128 = NULL ;
if ( ! V_5 -> V_113 -> V_189 )
V_5 -> V_113 -> V_128 = NULL ;
F_11 ( & V_91 ) ;
if ( V_204 && V_5 -> V_190 ) {
F_155 ( V_5 -> V_157 ) ;
V_5 -> V_190 = false ;
}
}
F_170 ( V_5 -> V_157 , V_165 ) ;
F_40 ( & V_5 -> V_83 ) ;
F_160 ( V_5 , V_169 , 0 ) ;
}
static int F_171 ( struct V_2 * V_2 , struct V_48 * V_70 )
{
struct V_4 * V_5 = F_3 ( V_70 -> V_50 -> V_51 ) ;
F_167 ( V_5 , V_70 -> V_197 ) ;
return 0 ;
}
static long F_172 ( struct V_48 * V_48 , unsigned V_205 , unsigned long V_206 )
{
struct V_4 * V_5 = F_3 ( V_48 -> V_50 -> V_51 ) ;
T_7 V_169 = V_48 -> V_197 ;
if ( V_48 -> V_194 & V_196 )
V_169 |= V_198 ;
else
V_169 &= ~ V_198 ;
return F_173 ( V_5 , V_169 , V_205 , V_206 ) ;
}
T_2 F_174 ( struct V_42 * V_43 , const struct V_44 * V_45 ,
unsigned long V_47 , T_3 V_60 )
{
struct V_48 * V_48 = V_43 -> V_49 ;
struct V_207 V_208 ;
T_2 V_66 ;
F_159 ( V_43 -> V_209 != V_60 ) ;
F_175 ( & V_208 ) ;
V_66 = F_176 ( V_43 , V_45 , V_47 ) ;
if ( V_66 > 0 ) {
T_2 V_100 ;
V_100 = F_177 ( V_48 , V_60 , V_66 ) ;
if ( V_100 < 0 )
V_66 = V_100 ;
}
F_178 ( & V_208 ) ;
return V_66 ;
}
static T_2 F_179 ( struct V_42 * V_43 , const struct V_44 * V_45 ,
unsigned long V_47 , T_3 V_60 )
{
struct V_48 * V_48 = V_43 -> V_49 ;
struct V_2 * V_20 = V_48 -> V_50 -> V_51 ;
T_3 V_24 = F_59 ( V_20 ) ;
if ( V_60 >= V_24 )
return 0 ;
V_24 -= V_60 ;
if ( V_24 < V_43 -> V_210 )
V_47 = F_180 ( (struct V_44 * ) V_45 , V_47 , V_24 ) ;
return F_181 ( V_43 , V_45 , V_47 , V_60 ) ;
}
static int F_182 ( struct V_57 * V_57 , T_8 V_52 )
{
struct V_29 * V_211 = F_1 ( V_57 -> V_19 -> V_51 ) -> V_5 . V_114 ;
if ( V_211 && V_211 -> V_212 -> V_213 )
return V_211 -> V_212 -> V_213 ( V_211 , V_57 , V_52 ) ;
return F_183 ( V_57 ) ;
}
int F_184 ( struct V_4 * V_5 , unsigned V_205 , unsigned long V_206 )
{
int V_53 ;
T_9 V_214 = F_185 () ;
F_186 ( V_215 ) ;
V_53 = F_173 ( V_5 , 0 , V_205 , V_206 ) ;
F_186 ( V_214 ) ;
return V_53 ;
}
struct V_4 * F_165 ( const char * V_216 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_192 V_192 ;
int error ;
if ( ! V_216 || ! * V_216 )
return F_44 ( - V_26 ) ;
error = F_187 ( V_216 , V_217 , & V_192 ) ;
if ( error )
return F_44 ( error ) ;
V_2 = V_192 . V_93 -> V_218 ;
error = - V_219 ;
if ( ! F_188 ( V_2 -> V_117 ) )
goto V_220;
error = - V_193 ;
if ( V_192 . V_221 -> V_222 & V_223 )
goto V_220;
error = - V_140 ;
V_5 = F_105 ( V_2 ) ;
if ( ! V_5 )
goto V_220;
V_56:
F_189 ( & V_192 ) ;
return V_5 ;
V_220:
V_5 = F_44 ( error ) ;
goto V_56;
}
int F_138 ( struct V_4 * V_5 , bool V_154 )
{
struct V_29 * V_30 = F_35 ( V_5 ) ;
int V_53 = 0 ;
if ( V_30 ) {
F_190 ( V_30 ) ;
V_53 = F_191 ( V_30 , V_154 ) ;
F_37 ( V_30 ) ;
}
F_16 ( V_5 ) ;
return V_53 ;
}
void F_192 ( void (* F_193)( struct V_4 * , void * ) , void * V_206 )
{
struct V_2 * V_2 , * V_224 = NULL ;
F_7 ( & V_225 ) ;
F_102 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_18 * V_19 = V_2 -> V_21 ;
F_7 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 & ( V_226 | V_227 | V_112 ) ||
V_19 -> V_22 == 0 ) {
F_11 ( & V_2 -> V_12 ) ;
continue;
}
F_194 ( V_2 ) ;
F_11 ( & V_2 -> V_12 ) ;
F_11 ( & V_225 ) ;
F_104 ( V_224 ) ;
V_224 = V_2 ;
F_193 ( F_3 ( V_2 ) , V_206 ) ;
F_7 ( & V_225 ) ;
}
F_11 ( & V_225 ) ;
F_104 ( V_224 ) ;
}

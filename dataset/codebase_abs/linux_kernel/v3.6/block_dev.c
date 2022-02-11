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
if ( F_5 ( V_7 == V_8 ) )
return;
F_6 ( & V_8 -> V_10 , & V_7 -> V_10 ) ;
F_7 ( & V_2 -> V_11 ) ;
V_2 -> V_9 . V_6 = V_7 ;
if ( V_2 -> V_12 & V_13 )
F_8 ( & V_2 -> V_14 , & V_7 -> V_10 . V_15 ) ;
F_9 ( & V_2 -> V_11 ) ;
F_9 ( & V_8 -> V_10 . V_16 ) ;
F_9 ( & V_7 -> V_10 . V_16 ) ;
}
T_1 F_10 ( struct V_4 * V_5 )
{
T_1 V_17 = ~ ( ( T_1 ) 0 ) ;
T_2 V_18 = F_11 ( V_5 -> V_19 ) ;
if ( V_18 ) {
unsigned int V_20 = F_12 ( V_5 ) ;
unsigned int V_21 = F_13 ( V_20 ) ;
V_17 = ( V_18 >> V_21 ) ;
}
return V_17 ;
}
void F_14 ( struct V_4 * V_5 )
{
struct V_22 * V_23 = V_5 -> V_19 -> V_24 ;
if ( V_23 -> V_25 == 0 )
return;
F_15 () ;
F_16 ( V_23 , 0 ) ;
}
void F_17 ( struct V_4 * V_5 )
{
struct V_22 * V_23 = V_5 -> V_19 -> V_24 ;
if ( V_23 -> V_25 == 0 )
return;
F_15 () ;
F_18 () ;
F_19 ( V_23 , 0 , - 1 ) ;
F_20 ( V_23 ) ;
}
int F_21 ( struct V_4 * V_5 , int V_20 )
{
if ( V_20 > V_26 || V_20 < 512 || ! F_22 ( V_20 ) )
return - V_27 ;
if ( V_20 < F_23 ( V_5 ) )
return - V_27 ;
if ( V_5 -> V_28 != V_20 ) {
F_24 ( V_5 ) ;
V_5 -> V_28 = V_20 ;
V_5 -> V_19 -> V_29 = F_13 ( V_20 ) ;
F_14 ( V_5 ) ;
}
return 0 ;
}
int F_25 ( struct V_30 * V_31 , int V_20 )
{
if ( F_21 ( V_31 -> V_32 , V_20 ) )
return 0 ;
V_31 -> V_33 = V_20 ;
V_31 -> V_34 = F_13 ( V_20 ) ;
return V_31 -> V_33 ;
}
int F_26 ( struct V_30 * V_31 , int V_20 )
{
int V_35 = F_23 ( V_31 -> V_32 ) ;
if ( V_20 < V_35 )
V_20 = V_35 ;
return F_25 ( V_31 , V_20 ) ;
}
static int
F_27 ( struct V_2 * V_2 , T_1 V_36 ,
struct V_37 * V_38 , int V_39 )
{
if ( V_36 >= F_10 ( F_3 ( V_2 ) ) ) {
if ( V_39 )
return - V_40 ;
return 0 ;
}
V_38 -> V_41 = F_3 ( V_2 ) ;
V_38 -> V_42 = V_36 ;
F_28 ( V_38 ) ;
return 0 ;
}
static int
F_29 ( struct V_2 * V_2 , T_1 V_36 ,
struct V_37 * V_38 , int V_39 )
{
T_1 V_43 = F_10 ( F_3 ( V_2 ) ) ;
unsigned long V_44 = V_38 -> V_45 >> V_2 -> V_29 ;
if ( ( V_36 + V_44 ) > V_43 ) {
V_44 = V_43 - V_36 ;
if ( ( long ) V_44 <= 0 ) {
if ( V_39 )
return - V_40 ;
V_44 = 0 ;
}
}
V_38 -> V_41 = F_3 ( V_2 ) ;
V_38 -> V_42 = V_36 ;
V_38 -> V_45 = V_44 << V_2 -> V_29 ;
if ( V_44 )
F_28 ( V_38 ) ;
return 0 ;
}
static T_3
F_30 ( int V_46 , struct V_47 * V_48 , const struct V_49 * V_50 ,
T_2 V_51 , unsigned long V_52 )
{
struct V_53 * V_53 = V_48 -> V_54 ;
struct V_2 * V_2 = V_53 -> V_55 -> V_56 ;
return F_31 ( V_46 , V_48 , V_2 , F_3 ( V_2 ) , V_50 , V_51 ,
V_52 , F_29 , NULL , NULL , 0 ) ;
}
int F_32 ( struct V_4 * V_5 , int V_57 )
{
if ( ! V_5 )
return 0 ;
if ( ! V_57 )
return F_33 ( V_5 -> V_19 -> V_24 ) ;
return F_34 ( V_5 -> V_19 -> V_24 ) ;
}
int F_24 ( struct V_4 * V_5 )
{
return F_32 ( V_5 , 1 ) ;
}
int F_35 ( struct V_4 * V_5 )
{
struct V_30 * V_31 = F_36 ( V_5 ) ;
if ( V_31 ) {
int V_58 = F_37 ( V_31 ) ;
F_38 ( V_31 ) ;
return V_58 ;
}
return F_24 ( V_5 ) ;
}
struct V_30 * F_39 ( struct V_4 * V_5 )
{
struct V_30 * V_31 ;
int error = 0 ;
F_40 ( & V_5 -> V_59 ) ;
if ( ++ V_5 -> V_60 > 1 ) {
V_31 = F_36 ( V_5 ) ;
F_38 ( V_31 ) ;
F_41 ( & V_5 -> V_59 ) ;
return V_31 ;
}
V_31 = F_42 ( V_5 ) ;
if ( ! V_31 )
goto V_61;
error = F_43 ( V_31 ) ;
if ( error ) {
F_44 ( V_31 ) ;
V_5 -> V_60 -- ;
F_41 ( & V_5 -> V_59 ) ;
return F_45 ( error ) ;
}
F_44 ( V_31 ) ;
V_61:
F_24 ( V_5 ) ;
F_41 ( & V_5 -> V_59 ) ;
return V_31 ;
}
int F_46 ( struct V_4 * V_5 , struct V_30 * V_31 )
{
int error = - V_27 ;
F_40 ( & V_5 -> V_59 ) ;
if ( ! V_5 -> V_60 )
goto V_61;
error = 0 ;
if ( -- V_5 -> V_60 > 0 )
goto V_61;
if ( ! V_31 )
goto V_61;
error = F_47 ( V_31 ) ;
if ( error ) {
V_5 -> V_60 ++ ;
F_41 ( & V_5 -> V_59 ) ;
return error ;
}
V_61:
F_41 ( & V_5 -> V_59 ) ;
return 0 ;
}
static int F_48 ( struct V_62 * V_62 , struct V_63 * V_64 )
{
return F_49 ( V_62 , F_27 , V_64 ) ;
}
static int F_50 ( struct V_53 * V_53 , struct V_62 * V_62 )
{
return F_51 ( V_62 , F_27 ) ;
}
static int F_52 ( struct V_53 * V_53 , struct V_22 * V_23 ,
T_2 V_65 , unsigned V_66 , unsigned V_67 ,
struct V_62 * * V_68 , void * * V_69 )
{
return F_53 ( V_23 , V_65 , V_66 , V_67 , V_68 ,
F_27 ) ;
}
static int F_54 ( struct V_53 * V_53 , struct V_22 * V_23 ,
T_2 V_65 , unsigned V_66 , unsigned V_70 ,
struct V_62 * V_62 , void * V_69 )
{
int V_71 ;
V_71 = F_55 ( V_53 , V_23 , V_65 , V_66 , V_70 , V_62 , V_69 ) ;
F_56 ( V_62 ) ;
F_57 ( V_62 ) ;
return V_71 ;
}
static T_2 F_58 ( struct V_53 * V_53 , T_2 V_51 , int V_72 )
{
struct V_2 * V_19 = V_53 -> V_55 -> V_56 ;
T_2 V_20 ;
T_2 V_17 ;
F_40 ( & V_19 -> V_73 ) ;
V_20 = F_11 ( V_19 ) ;
V_17 = - V_27 ;
switch ( V_72 ) {
case V_74 :
V_51 += V_20 ;
break;
case V_75 :
V_51 += V_53 -> V_76 ;
case V_77 :
break;
default:
goto V_61;
}
if ( V_51 >= 0 && V_51 <= V_20 ) {
if ( V_51 != V_53 -> V_76 ) {
V_53 -> V_76 = V_51 ;
}
V_17 = V_51 ;
}
V_61:
F_41 ( & V_19 -> V_73 ) ;
return V_17 ;
}
int F_59 ( struct V_53 * V_78 , T_2 V_79 , T_2 V_80 , int V_81 )
{
struct V_2 * V_19 = V_78 -> V_55 -> V_56 ;
struct V_4 * V_5 = F_3 ( V_19 ) ;
int error ;
error = F_60 ( V_78 -> V_55 , V_79 , V_80 ) ;
if ( error )
return error ;
error = F_61 ( V_5 , V_82 , NULL ) ;
if ( error == - V_83 )
error = 0 ;
return error ;
}
static struct V_2 * F_62 ( struct V_30 * V_31 )
{
struct V_1 * V_84 = F_63 ( V_85 , V_82 ) ;
if ( ! V_84 )
return NULL ;
return & V_84 -> V_3 ;
}
static void F_64 ( struct V_86 * V_87 )
{
struct V_2 * V_2 = F_2 ( V_87 , struct V_2 , V_88 ) ;
struct V_1 * V_89 = F_1 ( V_2 ) ;
F_65 ( V_85 , V_89 ) ;
}
static void F_66 ( struct V_2 * V_2 )
{
F_67 ( & V_2 -> V_88 , F_64 ) ;
}
static void F_68 ( void * V_90 )
{
struct V_1 * V_84 = (struct V_1 * ) V_90 ;
struct V_4 * V_5 = & V_84 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_69 ( & V_5 -> V_91 ) ;
F_70 ( & V_5 -> V_92 ) ;
F_70 ( & V_5 -> V_93 ) ;
#ifdef F_71
F_70 ( & V_5 -> V_94 ) ;
#endif
F_72 ( & V_84 -> V_3 ) ;
F_69 ( & V_5 -> V_59 ) ;
}
static inline void F_73 ( struct V_2 * V_2 )
{
F_74 ( & V_2 -> V_95 ) ;
V_2 -> V_96 = NULL ;
V_2 -> V_24 = & V_2 -> V_9 ;
}
static void F_75 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
struct V_97 * V_98 ;
F_16 ( & V_2 -> V_9 , 0 ) ;
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
F_7 ( & V_99 ) ;
while ( ( V_98 = V_5 -> V_92 . V_100 ) != & V_5 -> V_92 ) {
F_73 ( F_78 ( V_98 , struct V_2 , V_95 ) ) ;
}
F_74 ( & V_5 -> V_93 ) ;
F_9 ( & V_99 ) ;
}
static struct V_101 * F_79 ( struct V_102 * V_103 ,
int V_67 , const char * V_104 , void * V_105 )
{
return F_80 ( V_103 , L_1 , & V_106 , NULL , V_107 ) ;
}
void T_4 F_81 ( void )
{
int V_108 ;
static struct V_109 * V_110 ;
V_85 = F_82 ( L_2 , sizeof( struct V_1 ) ,
0 , ( V_111 | V_112 |
V_113 | V_114 ) ,
F_68 ) ;
V_108 = F_83 ( & V_115 ) ;
if ( V_108 )
F_84 ( L_3 ) ;
V_110 = F_85 ( & V_115 ) ;
if ( F_86 ( V_110 ) )
F_84 ( L_4 ) ;
V_116 = V_110 -> V_117 ;
}
static inline unsigned long F_87 ( T_5 V_118 )
{
return F_88 ( V_118 ) + F_89 ( V_118 ) ;
}
static int F_90 ( struct V_2 * V_2 , void * V_105 )
{
return F_1 ( V_2 ) -> V_5 . V_119 == * ( T_5 * ) V_105 ;
}
static int F_91 ( struct V_2 * V_2 , void * V_105 )
{
F_1 ( V_2 ) -> V_5 . V_119 = * ( T_5 * ) V_105 ;
return 0 ;
}
struct V_4 * F_92 ( T_5 V_118 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_93 ( V_116 , F_87 ( V_118 ) ,
F_90 , F_91 , & V_118 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_12 & V_120 ) {
V_5 -> V_121 = NULL ;
V_5 -> V_122 = NULL ;
V_5 -> V_19 = V_2 ;
V_5 -> V_28 = ( 1 << V_2 -> V_29 ) ;
V_5 -> V_123 = 0 ;
V_5 -> V_124 = 0 ;
V_2 -> V_125 = V_126 ;
V_2 -> V_127 = V_118 ;
V_2 -> V_96 = V_5 ;
V_2 -> V_9 . V_128 = & V_129 ;
F_94 ( & V_2 -> V_9 , V_130 ) ;
V_2 -> V_9 . V_6 = & V_131 ;
F_7 ( & V_99 ) ;
F_95 ( & V_5 -> V_93 , & V_132 ) ;
F_9 ( & V_99 ) ;
F_96 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_97 ( struct V_4 * V_5 )
{
F_98 ( V_5 -> V_19 ) ;
return V_5 ;
}
long F_99 ( void )
{
struct V_4 * V_5 ;
long V_71 = 0 ;
F_7 ( & V_99 ) ;
F_100 (bdev, &all_bdevs, bd_list) {
V_71 += V_5 -> V_19 -> V_24 -> V_25 ;
}
F_9 ( & V_99 ) ;
return V_71 ;
}
void F_101 ( struct V_4 * V_5 )
{
F_102 ( V_5 -> V_19 ) ;
}
static struct V_4 * F_103 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_7 ( & V_99 ) ;
V_5 = V_2 -> V_96 ;
if ( V_5 ) {
F_98 ( V_5 -> V_19 ) ;
F_9 ( & V_99 ) ;
return V_5 ;
}
F_9 ( & V_99 ) ;
V_5 = F_92 ( V_2 -> V_127 ) ;
if ( V_5 ) {
F_7 ( & V_99 ) ;
if ( ! V_2 -> V_96 ) {
F_98 ( V_5 -> V_19 ) ;
V_2 -> V_96 = V_5 ;
V_2 -> V_24 = V_5 -> V_19 -> V_24 ;
F_95 ( & V_2 -> V_95 , & V_5 -> V_92 ) ;
}
F_9 ( & V_99 ) ;
}
return V_5 ;
}
static inline int F_104 ( struct V_30 * V_31 )
{
return V_31 == V_116 ;
}
void F_105 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_7 ( & V_99 ) ;
if ( V_2 -> V_96 ) {
if ( ! F_104 ( V_2 -> V_133 ) )
V_5 = V_2 -> V_96 ;
F_73 ( V_2 ) ;
}
F_9 ( & V_99 ) ;
if ( V_5 )
F_102 ( V_5 -> V_19 ) ;
}
static bool F_106 ( struct V_4 * V_5 , struct V_4 * V_134 ,
void * V_135 )
{
if ( V_5 -> V_136 == V_135 )
return true ;
else if ( V_5 -> V_136 != NULL )
return false ;
else if ( V_5 -> V_121 == V_5 )
return true ;
else if ( V_134 -> V_136 == F_106 )
return true ;
else if ( V_134 -> V_136 != NULL )
return false ;
else
return true ;
}
static int F_107 ( struct V_4 * V_5 ,
struct V_4 * V_134 , void * V_135 )
{
V_137:
if ( ! F_106 ( V_5 , V_134 , V_135 ) )
return - V_138 ;
if ( V_134 -> V_139 ) {
T_6 * V_140 = F_108 ( & V_134 -> V_139 , 0 ) ;
F_109 ( V_57 ) ;
F_110 ( V_140 , & V_57 , V_141 ) ;
F_9 ( & V_99 ) ;
F_111 () ;
F_112 ( V_140 , & V_57 ) ;
F_7 ( & V_99 ) ;
goto V_137;
}
return 0 ;
}
static struct V_4 * F_113 ( struct V_4 * V_5 ,
void * V_135 )
{
struct V_142 * V_143 ;
struct V_4 * V_134 ;
int V_144 , V_108 ;
F_114 () ;
V_143 = F_115 ( V_5 -> V_119 , & V_144 ) ;
if ( ! V_143 )
return F_45 ( - V_145 ) ;
if ( V_144 )
V_134 = F_116 ( V_143 , 0 ) ;
else
V_134 = F_97 ( V_5 ) ;
F_117 ( V_143 -> V_146 -> V_147 ) ;
F_118 ( V_143 ) ;
if ( ! V_134 )
return F_45 ( - V_148 ) ;
F_7 ( & V_99 ) ;
V_108 = F_107 ( V_5 , V_134 , V_135 ) ;
if ( V_108 == 0 ) {
V_134 -> V_139 = V_135 ;
F_9 ( & V_99 ) ;
return V_134 ;
} else {
F_9 ( & V_99 ) ;
F_101 ( V_134 ) ;
return F_45 ( V_108 ) ;
}
}
static struct V_149 * F_119 ( struct V_4 * V_5 ,
struct V_142 * V_143 )
{
struct V_149 * V_135 ;
F_100 (holder, &bdev->bd_holder_disks, list)
if ( V_135 -> V_143 == V_143 )
return V_135 ;
return NULL ;
}
static int F_120 ( struct V_150 * V_151 , struct V_150 * V_152 )
{
return F_121 ( V_151 , V_152 , F_122 ( V_152 ) ) ;
}
static void F_123 ( struct V_150 * V_151 , struct V_150 * V_152 )
{
F_124 ( V_151 , F_122 ( V_152 ) ) ;
}
int F_125 ( struct V_4 * V_5 , struct V_142 * V_143 )
{
struct V_149 * V_135 ;
int V_71 = 0 ;
F_40 ( & V_5 -> V_91 ) ;
F_126 ( ! V_5 -> V_136 ) ;
if ( F_127 ( ! V_143 -> V_153 || ! V_5 -> V_154 -> V_155 ) )
goto V_156;
V_135 = F_119 ( V_5 , V_143 ) ;
if ( V_135 ) {
V_135 -> V_157 ++ ;
goto V_156;
}
V_135 = F_128 ( sizeof( * V_135 ) , V_82 ) ;
if ( ! V_135 ) {
V_71 = - V_148 ;
goto V_156;
}
F_70 ( & V_135 -> V_158 ) ;
V_135 -> V_143 = V_143 ;
V_135 -> V_157 = 1 ;
V_71 = F_120 ( V_143 -> V_153 , & F_129 ( V_5 -> V_154 ) -> V_159 ) ;
if ( V_71 )
goto V_160;
V_71 = F_120 ( V_5 -> V_154 -> V_155 , & F_130 ( V_143 ) -> V_159 ) ;
if ( V_71 )
goto V_161;
F_131 ( V_5 -> V_154 -> V_155 ) ;
F_95 ( & V_135 -> V_158 , & V_5 -> V_94 ) ;
goto V_156;
V_161:
F_123 ( V_143 -> V_153 , & F_129 ( V_5 -> V_154 ) -> V_159 ) ;
V_160:
F_132 ( V_135 ) ;
V_156:
F_41 ( & V_5 -> V_91 ) ;
return V_71 ;
}
void F_133 ( struct V_4 * V_5 , struct V_142 * V_143 )
{
struct V_149 * V_135 ;
F_40 ( & V_5 -> V_91 ) ;
V_135 = F_119 ( V_5 , V_143 ) ;
if ( ! F_126 ( V_135 == NULL ) && ! -- V_135 -> V_157 ) {
F_123 ( V_143 -> V_153 , & F_129 ( V_5 -> V_154 ) -> V_159 ) ;
F_123 ( V_5 -> V_154 -> V_155 ,
& F_130 ( V_143 ) -> V_159 ) ;
F_134 ( V_5 -> V_154 -> V_155 ) ;
F_74 ( & V_135 -> V_158 ) ;
F_132 ( V_135 ) ;
}
F_41 ( & V_5 -> V_91 ) ;
}
static void F_135 ( struct V_4 * V_5 , bool V_162 )
{
if ( F_136 ( V_5 , V_162 ) ) {
char V_163 [ V_164 ] = L_5 ;
if ( V_5 -> V_165 )
F_137 ( V_5 -> V_165 , 0 , V_163 ) ;
F_138 ( V_166 L_6
L_7 , V_163 ) ;
}
if ( ! V_5 -> V_165 )
return;
if ( F_139 ( V_5 -> V_165 ) )
V_5 -> V_124 = 1 ;
}
void F_140 ( struct V_142 * V_143 , struct V_4 * V_5 )
{
T_2 V_167 , V_168 ;
V_167 = ( T_2 ) F_141 ( V_143 ) << 9 ;
V_168 = F_11 ( V_5 -> V_19 ) ;
if ( V_167 != V_168 ) {
char V_163 [ V_164 ] ;
F_137 ( V_143 , 0 , V_163 ) ;
F_138 ( V_169
L_8 ,
V_163 , V_168 , V_167 ) ;
F_142 ( V_5 -> V_19 , V_167 ) ;
F_135 ( V_5 , false ) ;
}
}
int F_143 ( struct V_142 * V_143 )
{
struct V_4 * V_5 ;
int V_71 = 0 ;
if ( V_143 -> V_146 -> F_143 )
V_71 = V_143 -> V_146 -> F_143 ( V_143 ) ;
V_5 = F_116 ( V_143 , 0 ) ;
if ( ! V_5 )
return V_71 ;
F_40 ( & V_5 -> V_91 ) ;
F_140 ( V_143 , V_5 ) ;
F_41 ( & V_5 -> V_91 ) ;
F_101 ( V_5 ) ;
return V_71 ;
}
int F_144 ( struct V_4 * V_5 )
{
struct V_142 * V_143 = V_5 -> V_165 ;
const struct V_170 * V_171 = V_143 -> V_146 ;
unsigned int V_172 ;
V_172 = F_145 ( V_143 , V_173 |
V_174 ) ;
if ( ! ( V_172 & V_173 ) )
return 0 ;
F_135 ( V_5 , true ) ;
if ( V_171 -> F_143 )
V_171 -> F_143 ( V_5 -> V_165 ) ;
return 1 ;
}
void F_146 ( struct V_4 * V_5 , T_2 V_20 )
{
unsigned V_175 = F_23 ( V_5 ) ;
V_5 -> V_19 -> V_176 = V_20 ;
while ( V_175 < V_177 ) {
if ( V_20 & V_175 )
break;
V_175 <<= 1 ;
}
V_5 -> V_28 = V_175 ;
V_5 -> V_19 -> V_29 = F_13 ( V_175 ) ;
}
static int F_147 ( struct V_4 * V_5 , T_7 V_178 , int V_179 )
{
struct V_142 * V_143 ;
struct V_180 * V_147 ;
int V_71 ;
int V_144 ;
int V_181 = 0 ;
if ( V_178 & V_182 )
V_181 |= V_183 ;
if ( V_178 & V_184 )
V_181 |= V_185 ;
if ( ! V_179 ) {
V_71 = F_148 ( V_5 -> V_19 , V_181 ) ;
if ( V_71 != 0 ) {
F_101 ( V_5 ) ;
return V_71 ;
}
}
V_186:
V_71 = - V_145 ;
V_143 = F_115 ( V_5 -> V_119 , & V_144 ) ;
if ( ! V_143 )
goto V_61;
V_147 = V_143 -> V_146 -> V_147 ;
F_149 ( V_143 ) ;
F_150 ( & V_5 -> V_91 , V_179 ) ;
if ( ! V_5 -> V_187 ) {
V_5 -> V_165 = V_143 ;
V_5 -> V_188 = V_143 -> V_189 ;
V_5 -> V_121 = V_5 ;
if ( ! V_144 ) {
struct V_6 * V_89 ;
V_71 = - V_145 ;
V_5 -> V_154 = F_151 ( V_143 , V_144 ) ;
if ( ! V_5 -> V_154 )
goto V_190;
V_71 = 0 ;
if ( V_143 -> V_146 -> V_191 ) {
V_71 = V_143 -> V_146 -> V_191 ( V_5 , V_178 ) ;
if ( V_71 == - V_192 ) {
F_152 ( V_5 -> V_154 ) ;
V_5 -> V_154 = NULL ;
V_5 -> V_165 = NULL ;
V_5 -> V_188 = NULL ;
F_41 ( & V_5 -> V_91 ) ;
F_153 ( V_143 ) ;
F_118 ( V_143 ) ;
F_117 ( V_147 ) ;
goto V_186;
}
}
if ( ! V_71 && ! V_5 -> V_187 ) {
F_146 ( V_5 , ( T_2 ) F_141 ( V_143 ) << 9 ) ;
V_89 = F_154 ( V_5 ) ;
if ( V_89 == NULL )
V_89 = & V_131 ;
F_4 ( V_5 -> V_19 , V_89 ) ;
}
if ( V_5 -> V_124 ) {
if ( ! V_71 )
F_155 ( V_143 , V_5 ) ;
else if ( V_71 == - V_193 )
F_156 ( V_143 , V_5 ) ;
}
if ( V_71 )
goto V_190;
} else {
struct V_4 * V_134 ;
V_134 = F_116 ( V_143 , 0 ) ;
V_71 = - V_148 ;
if ( ! V_134 )
goto V_190;
F_157 ( V_179 ) ;
V_71 = F_147 ( V_134 , V_178 , 1 ) ;
if ( V_71 )
goto V_190;
V_5 -> V_121 = V_134 ;
F_4 ( V_5 -> V_19 ,
V_134 -> V_19 -> V_9 . V_6 ) ;
V_5 -> V_154 = F_151 ( V_143 , V_144 ) ;
if ( ! ( V_143 -> V_67 & V_194 ) ||
! V_5 -> V_154 || ! V_5 -> V_154 -> V_195 ) {
V_71 = - V_145 ;
goto V_190;
}
F_146 ( V_5 , ( T_2 ) V_5 -> V_154 -> V_195 << 9 ) ;
}
} else {
if ( V_5 -> V_121 == V_5 ) {
V_71 = 0 ;
if ( V_5 -> V_165 -> V_146 -> V_191 )
V_71 = V_5 -> V_165 -> V_146 -> V_191 ( V_5 , V_178 ) ;
if ( V_5 -> V_124 ) {
if ( ! V_71 )
F_155 ( V_5 -> V_165 , V_5 ) ;
else if ( V_71 == - V_193 )
F_156 ( V_5 -> V_165 , V_5 ) ;
}
if ( V_71 )
goto V_196;
}
F_118 ( V_143 ) ;
F_117 ( V_147 ) ;
}
V_5 -> V_187 ++ ;
if ( V_179 )
V_5 -> V_123 ++ ;
F_41 ( & V_5 -> V_91 ) ;
F_153 ( V_143 ) ;
return 0 ;
V_190:
F_152 ( V_5 -> V_154 ) ;
V_5 -> V_165 = NULL ;
V_5 -> V_154 = NULL ;
V_5 -> V_188 = NULL ;
F_4 ( V_5 -> V_19 , & V_131 ) ;
if ( V_5 != V_5 -> V_121 )
F_158 ( V_5 -> V_121 , V_178 , 1 ) ;
V_5 -> V_121 = NULL ;
V_196:
F_41 ( & V_5 -> V_91 ) ;
F_153 ( V_143 ) ;
F_118 ( V_143 ) ;
F_117 ( V_147 ) ;
V_61:
F_101 ( V_5 ) ;
return V_71 ;
}
int F_159 ( struct V_4 * V_5 , T_7 V_178 , void * V_135 )
{
struct V_4 * V_134 = NULL ;
int V_58 ;
F_126 ( ( V_178 & V_197 ) && ! V_135 ) ;
if ( ( V_178 & V_197 ) && V_135 ) {
V_134 = F_113 ( V_5 , V_135 ) ;
if ( F_86 ( V_134 ) ) {
F_101 ( V_5 ) ;
return F_160 ( V_134 ) ;
}
}
V_58 = F_147 ( V_5 , V_178 , 0 ) ;
if ( V_134 ) {
struct V_142 * V_143 = V_134 -> V_165 ;
F_40 ( & V_5 -> V_91 ) ;
F_7 ( & V_99 ) ;
if ( ! V_58 ) {
F_157 ( ! F_106 ( V_5 , V_134 , V_135 ) ) ;
V_134 -> V_198 ++ ;
V_134 -> V_136 = F_106 ;
V_5 -> V_198 ++ ;
V_5 -> V_136 = V_135 ;
}
F_157 ( V_134 -> V_139 != V_135 ) ;
V_134 -> V_139 = NULL ;
F_161 ( & V_134 -> V_139 , 0 ) ;
F_9 ( & V_99 ) ;
if ( ! V_58 && ( V_178 & V_184 ) && ! V_5 -> V_199 &&
( V_143 -> V_67 & V_200 ) ) {
V_5 -> V_199 = true ;
F_149 ( V_143 ) ;
}
F_41 ( & V_5 -> V_91 ) ;
F_101 ( V_134 ) ;
}
return V_58 ;
}
struct V_4 * F_162 ( const char * V_201 , T_7 V_178 ,
void * V_135 )
{
struct V_4 * V_5 ;
int V_108 ;
V_5 = F_163 ( V_201 ) ;
if ( F_86 ( V_5 ) )
return V_5 ;
V_108 = F_159 ( V_5 , V_178 , V_135 ) ;
if ( V_108 )
return F_45 ( V_108 ) ;
if ( ( V_178 & V_184 ) && F_164 ( V_5 ) ) {
F_165 ( V_5 , V_178 ) ;
return F_45 ( - V_202 ) ;
}
return V_5 ;
}
struct V_4 * F_166 ( T_5 V_118 , T_7 V_178 , void * V_135 )
{
struct V_4 * V_5 ;
int V_108 ;
V_5 = F_92 ( V_118 ) ;
if ( ! V_5 )
return F_45 ( - V_148 ) ;
V_108 = F_159 ( V_5 , V_178 , V_135 ) ;
if ( V_108 )
return F_45 ( V_108 ) ;
return V_5 ;
}
static int F_167 ( struct V_2 * V_2 , struct V_53 * V_78 )
{
struct V_4 * V_5 ;
V_78 -> V_203 |= V_204 ;
if ( V_78 -> V_203 & V_205 )
V_78 -> V_206 |= V_207 ;
if ( V_78 -> V_203 & V_208 )
V_78 -> V_206 |= V_197 ;
if ( ( V_78 -> V_203 & V_209 ) == 3 )
V_78 -> V_206 |= V_210 ;
V_5 = F_103 ( V_2 ) ;
if ( V_5 == NULL )
return - V_148 ;
V_78 -> V_55 = V_5 -> V_19 -> V_24 ;
return F_159 ( V_5 , V_78 -> V_206 , V_78 ) ;
}
static int F_158 ( struct V_4 * V_5 , T_7 V_178 , int V_179 )
{
int V_71 = 0 ;
struct V_142 * V_143 = V_5 -> V_165 ;
struct V_4 * V_211 = NULL ;
F_150 ( & V_5 -> V_91 , V_179 ) ;
if ( V_179 )
V_5 -> V_123 -- ;
if ( ! -- V_5 -> V_187 ) {
F_126 ( V_5 -> V_198 ) ;
F_24 ( V_5 ) ;
F_14 ( V_5 ) ;
F_4 ( V_5 -> V_19 ,
& V_131 ) ;
}
if ( V_5 -> V_121 == V_5 ) {
if ( V_143 -> V_146 -> V_212 )
V_71 = V_143 -> V_146 -> V_212 ( V_143 , V_178 ) ;
}
if ( ! V_5 -> V_187 ) {
struct V_180 * V_147 = V_143 -> V_146 -> V_147 ;
F_152 ( V_5 -> V_154 ) ;
V_5 -> V_154 = NULL ;
V_5 -> V_165 = NULL ;
if ( V_5 != V_5 -> V_121 )
V_211 = V_5 -> V_121 ;
V_5 -> V_121 = NULL ;
F_118 ( V_143 ) ;
F_117 ( V_147 ) ;
}
F_41 ( & V_5 -> V_91 ) ;
F_101 ( V_5 ) ;
if ( V_211 )
F_158 ( V_211 , V_178 , 1 ) ;
return V_71 ;
}
int F_165 ( struct V_4 * V_5 , T_7 V_178 )
{
F_40 ( & V_5 -> V_91 ) ;
if ( V_178 & V_197 ) {
bool V_213 ;
F_7 ( & V_99 ) ;
F_126 ( -- V_5 -> V_198 < 0 ) ;
F_126 ( -- V_5 -> V_121 -> V_198 < 0 ) ;
if ( ( V_213 = ! V_5 -> V_198 ) )
V_5 -> V_136 = NULL ;
if ( ! V_5 -> V_121 -> V_198 )
V_5 -> V_121 -> V_136 = NULL ;
F_9 ( & V_99 ) ;
if ( V_213 && V_5 -> V_199 ) {
F_153 ( V_5 -> V_165 ) ;
V_5 -> V_199 = false ;
}
}
F_168 ( V_5 -> V_165 , V_173 ) ;
F_41 ( & V_5 -> V_91 ) ;
return F_158 ( V_5 , V_178 , 0 ) ;
}
static int F_169 ( struct V_2 * V_2 , struct V_53 * V_78 )
{
struct V_4 * V_5 = F_3 ( V_78 -> V_55 -> V_56 ) ;
return F_165 ( V_5 , V_78 -> V_206 ) ;
}
static long F_170 ( struct V_53 * V_53 , unsigned V_214 , unsigned long V_215 )
{
struct V_4 * V_5 = F_3 ( V_53 -> V_55 -> V_56 ) ;
T_7 V_178 = V_53 -> V_206 ;
if ( V_53 -> V_203 & V_205 )
V_178 |= V_207 ;
else
V_178 &= ~ V_207 ;
return F_171 ( V_5 , V_178 , V_214 , V_215 ) ;
}
T_3 F_172 ( struct V_47 * V_48 , const struct V_49 * V_50 ,
unsigned long V_52 , T_2 V_65 )
{
struct V_53 * V_53 = V_48 -> V_54 ;
struct V_216 V_217 ;
T_3 V_71 ;
F_157 ( V_48 -> V_218 != V_65 ) ;
F_173 ( & V_217 ) ;
V_71 = F_174 ( V_48 , V_50 , V_52 , & V_48 -> V_218 ) ;
if ( V_71 > 0 || V_71 == - V_219 ) {
T_3 V_108 ;
V_108 = F_175 ( V_53 , V_65 , V_71 ) ;
if ( V_108 < 0 && V_71 > 0 )
V_71 = V_108 ;
}
F_176 ( & V_217 ) ;
return V_71 ;
}
static int F_177 ( struct V_62 * V_62 , T_8 V_57 )
{
struct V_30 * V_220 = F_1 ( V_62 -> V_23 -> V_56 ) -> V_5 . V_122 ;
if ( V_220 && V_220 -> V_221 -> V_222 )
return V_220 -> V_221 -> V_222 ( V_220 , V_62 , V_57 ) ;
return F_178 ( V_62 ) ;
}
int F_179 ( struct V_4 * V_5 , unsigned V_214 , unsigned long V_215 )
{
int V_58 ;
T_9 V_223 = F_180 () ;
F_181 ( V_224 ) ;
V_58 = F_171 ( V_5 , 0 , V_214 , V_215 ) ;
F_181 ( V_223 ) ;
return V_58 ;
}
struct V_4 * F_163 ( const char * V_225 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_201 V_201 ;
int error ;
if ( ! V_225 || ! * V_225 )
return F_45 ( - V_27 ) ;
error = F_182 ( V_225 , V_226 , & V_201 ) ;
if ( error )
return F_45 ( error ) ;
V_2 = V_201 . V_101 -> V_227 ;
error = - V_228 ;
if ( ! F_183 ( V_2 -> V_125 ) )
goto V_229;
error = - V_202 ;
if ( V_201 . V_230 -> V_231 & V_232 )
goto V_229;
error = - V_148 ;
V_5 = F_103 ( V_2 ) ;
if ( ! V_5 )
goto V_229;
V_61:
F_184 ( & V_201 ) ;
return V_5 ;
V_229:
V_5 = F_45 ( error ) ;
goto V_61;
}
int F_136 ( struct V_4 * V_5 , bool V_162 )
{
struct V_30 * V_31 = F_36 ( V_5 ) ;
int V_58 = 0 ;
if ( V_31 ) {
F_185 ( V_31 ) ;
V_58 = F_186 ( V_31 , V_162 ) ;
F_38 ( V_31 ) ;
}
F_17 ( V_5 ) ;
return V_58 ;
}
void F_187 ( void (* F_188)( struct V_4 * , void * ) , void * V_215 )
{
struct V_2 * V_2 , * V_233 = NULL ;
F_7 ( & V_234 ) ;
F_100 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_22 * V_23 = V_2 -> V_24 ;
F_7 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_12 & ( V_235 | V_236 | V_120 ) ||
V_23 -> V_25 == 0 ) {
F_9 ( & V_2 -> V_11 ) ;
continue;
}
F_189 ( V_2 ) ;
F_9 ( & V_2 -> V_11 ) ;
F_9 ( & V_234 ) ;
F_102 ( V_233 ) ;
V_233 = V_2 ;
F_188 ( F_3 ( V_2 ) , V_215 ) ;
F_7 ( & V_234 ) ;
}
F_9 ( & V_234 ) ;
F_102 ( V_233 ) ;
}

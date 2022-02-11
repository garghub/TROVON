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
static T_1 F_10 ( struct V_4 * V_5 )
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
static void F_14 ( struct V_4 * V_5 )
{
if ( V_5 -> V_19 -> V_22 -> V_23 == 0 )
return;
F_15 () ;
F_16 ( V_5 -> V_19 -> V_22 , 0 ) ;
}
int F_17 ( struct V_4 * V_5 , int V_20 )
{
if ( V_20 > V_24 || V_20 < 512 || ! F_18 ( V_20 ) )
return - V_25 ;
if ( V_20 < F_19 ( V_5 ) )
return - V_25 ;
if ( V_5 -> V_26 != V_20 ) {
F_20 ( V_5 ) ;
V_5 -> V_26 = V_20 ;
V_5 -> V_19 -> V_27 = F_13 ( V_20 ) ;
F_14 ( V_5 ) ;
}
return 0 ;
}
int F_21 ( struct V_28 * V_29 , int V_20 )
{
if ( F_17 ( V_29 -> V_30 , V_20 ) )
return 0 ;
V_29 -> V_31 = V_20 ;
V_29 -> V_32 = F_13 ( V_20 ) ;
return V_29 -> V_31 ;
}
int F_22 ( struct V_28 * V_29 , int V_20 )
{
int V_33 = F_19 ( V_29 -> V_30 ) ;
if ( V_20 < V_33 )
V_20 = V_33 ;
return F_21 ( V_29 , V_20 ) ;
}
static int
F_23 ( struct V_2 * V_2 , T_1 V_34 ,
struct V_35 * V_36 , int V_37 )
{
if ( V_34 >= F_10 ( F_3 ( V_2 ) ) ) {
if ( V_37 )
return - V_38 ;
return 0 ;
}
V_36 -> V_39 = F_3 ( V_2 ) ;
V_36 -> V_40 = V_34 ;
F_24 ( V_36 ) ;
return 0 ;
}
static int
F_25 ( struct V_2 * V_2 , T_1 V_34 ,
struct V_35 * V_36 , int V_37 )
{
T_1 V_41 = F_10 ( F_3 ( V_2 ) ) ;
unsigned long V_42 = V_36 -> V_43 >> V_2 -> V_27 ;
if ( ( V_34 + V_42 ) > V_41 ) {
V_42 = V_41 - V_34 ;
if ( ( long ) V_42 <= 0 ) {
if ( V_37 )
return - V_38 ;
V_42 = 0 ;
}
}
V_36 -> V_39 = F_3 ( V_2 ) ;
V_36 -> V_40 = V_34 ;
V_36 -> V_43 = V_42 << V_2 -> V_27 ;
if ( V_42 )
F_24 ( V_36 ) ;
return 0 ;
}
static T_3
F_26 ( int V_44 , struct V_45 * V_46 , const struct V_47 * V_48 ,
T_2 V_49 , unsigned long V_50 )
{
struct V_51 * V_51 = V_46 -> V_52 ;
struct V_2 * V_2 = V_51 -> V_53 -> V_54 ;
return F_27 ( V_44 , V_46 , V_2 , F_3 ( V_2 ) , V_48 , V_49 ,
V_50 , F_25 , NULL , NULL , 0 ) ;
}
int F_28 ( struct V_4 * V_5 , int V_55 )
{
if ( ! V_5 )
return 0 ;
if ( ! V_55 )
return F_29 ( V_5 -> V_19 -> V_22 ) ;
return F_30 ( V_5 -> V_19 -> V_22 ) ;
}
int F_20 ( struct V_4 * V_5 )
{
return F_28 ( V_5 , 1 ) ;
}
int F_31 ( struct V_4 * V_5 )
{
struct V_28 * V_29 = F_32 ( V_5 ) ;
if ( V_29 ) {
int V_56 = F_33 ( V_29 ) ;
F_34 ( V_29 ) ;
return V_56 ;
}
return F_20 ( V_5 ) ;
}
struct V_28 * F_35 ( struct V_4 * V_5 )
{
struct V_28 * V_29 ;
int error = 0 ;
F_36 ( & V_5 -> V_57 ) ;
if ( ++ V_5 -> V_58 > 1 ) {
V_29 = F_32 ( V_5 ) ;
F_34 ( V_29 ) ;
F_37 ( & V_5 -> V_57 ) ;
return V_29 ;
}
V_29 = F_38 ( V_5 ) ;
if ( ! V_29 )
goto V_59;
error = F_39 ( V_29 ) ;
if ( error ) {
F_40 ( V_29 ) ;
V_5 -> V_58 -- ;
F_37 ( & V_5 -> V_57 ) ;
return F_41 ( error ) ;
}
F_40 ( V_29 ) ;
V_59:
F_20 ( V_5 ) ;
F_37 ( & V_5 -> V_57 ) ;
return V_29 ;
}
int F_42 ( struct V_4 * V_5 , struct V_28 * V_29 )
{
int error = - V_25 ;
F_36 ( & V_5 -> V_57 ) ;
if ( ! V_5 -> V_58 )
goto V_59;
error = 0 ;
if ( -- V_5 -> V_58 > 0 )
goto V_59;
if ( ! V_29 )
goto V_59;
error = F_43 ( V_29 ) ;
if ( error ) {
V_5 -> V_58 ++ ;
F_37 ( & V_5 -> V_57 ) ;
return error ;
}
V_59:
F_37 ( & V_5 -> V_57 ) ;
return 0 ;
}
static int F_44 ( struct V_60 * V_60 , struct V_61 * V_62 )
{
return F_45 ( V_60 , F_23 , V_62 ) ;
}
static int F_46 ( struct V_51 * V_51 , struct V_60 * V_60 )
{
return F_47 ( V_60 , F_23 ) ;
}
static int F_48 ( struct V_51 * V_51 , struct V_63 * V_64 ,
T_2 V_65 , unsigned V_66 , unsigned V_67 ,
struct V_60 * * V_68 , void * * V_69 )
{
return F_49 ( V_64 , V_65 , V_66 , V_67 , V_68 ,
F_23 ) ;
}
static int F_50 ( struct V_51 * V_51 , struct V_63 * V_64 ,
T_2 V_65 , unsigned V_66 , unsigned V_70 ,
struct V_60 * V_60 , void * V_69 )
{
int V_71 ;
V_71 = F_51 ( V_51 , V_64 , V_65 , V_66 , V_70 , V_60 , V_69 ) ;
F_52 ( V_60 ) ;
F_53 ( V_60 ) ;
return V_71 ;
}
static T_2 F_54 ( struct V_51 * V_51 , T_2 V_49 , int V_72 )
{
struct V_2 * V_19 = V_51 -> V_53 -> V_54 ;
T_2 V_20 ;
T_2 V_17 ;
F_36 ( & V_19 -> V_73 ) ;
V_20 = F_11 ( V_19 ) ;
V_17 = - V_25 ;
switch ( V_72 ) {
case V_74 :
V_49 += V_20 ;
break;
case V_75 :
V_49 += V_51 -> V_76 ;
case V_77 :
break;
default:
goto V_59;
}
if ( V_49 >= 0 && V_49 <= V_20 ) {
if ( V_49 != V_51 -> V_76 ) {
V_51 -> V_76 = V_49 ;
}
V_17 = V_49 ;
}
V_59:
F_37 ( & V_19 -> V_73 ) ;
return V_17 ;
}
int F_55 ( struct V_51 * V_78 , T_2 V_79 , T_2 V_80 , int V_81 )
{
struct V_2 * V_19 = V_78 -> V_53 -> V_54 ;
struct V_4 * V_5 = F_3 ( V_19 ) ;
int error ;
error = F_56 ( V_78 -> V_53 , V_79 , V_80 ) ;
if ( error )
return error ;
error = F_57 ( V_5 , V_82 , NULL ) ;
if ( error == - V_83 )
error = 0 ;
return error ;
}
static struct V_2 * F_58 ( struct V_28 * V_29 )
{
struct V_1 * V_84 = F_59 ( V_85 , V_82 ) ;
if ( ! V_84 )
return NULL ;
return & V_84 -> V_3 ;
}
static void F_60 ( struct V_86 * V_87 )
{
struct V_2 * V_2 = F_2 ( V_87 , struct V_2 , V_88 ) ;
struct V_1 * V_89 = F_1 ( V_2 ) ;
F_61 ( & V_2 -> V_90 ) ;
F_62 ( V_85 , V_89 ) ;
}
static void F_63 ( struct V_2 * V_2 )
{
F_64 ( & V_2 -> V_88 , F_60 ) ;
}
static void F_65 ( void * V_91 )
{
struct V_1 * V_84 = (struct V_1 * ) V_91 ;
struct V_4 * V_5 = & V_84 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_66 ( & V_5 -> V_92 ) ;
F_61 ( & V_5 -> V_93 ) ;
F_61 ( & V_5 -> V_94 ) ;
#ifdef F_67
F_61 ( & V_5 -> V_95 ) ;
#endif
F_68 ( & V_84 -> V_3 ) ;
F_66 ( & V_5 -> V_57 ) ;
}
static inline void F_69 ( struct V_2 * V_2 )
{
F_70 ( & V_2 -> V_96 ) ;
V_2 -> V_97 = NULL ;
V_2 -> V_22 = & V_2 -> V_9 ;
}
static void F_71 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
struct V_98 * V_99 ;
F_16 ( & V_2 -> V_9 , 0 ) ;
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
F_7 ( & V_100 ) ;
while ( ( V_99 = V_5 -> V_93 . V_101 ) != & V_5 -> V_93 ) {
F_69 ( F_74 ( V_99 , struct V_2 , V_96 ) ) ;
}
F_70 ( & V_5 -> V_94 ) ;
F_9 ( & V_100 ) ;
}
static struct V_102 * F_75 ( struct V_103 * V_104 ,
int V_67 , const char * V_105 , void * V_106 )
{
return F_76 ( V_104 , L_1 , & V_107 , NULL , 0x62646576 ) ;
}
void T_4 F_77 ( void )
{
int V_108 ;
struct V_109 * V_110 ;
V_85 = F_78 ( L_2 , sizeof( struct V_1 ) ,
0 , ( V_111 | V_112 |
V_113 | V_114 ) ,
F_65 ) ;
V_108 = F_79 ( & V_115 ) ;
if ( V_108 )
F_80 ( L_3 ) ;
V_110 = F_81 ( & V_115 ) ;
if ( F_82 ( V_110 ) )
F_80 ( L_4 ) ;
F_83 ( V_110 ) ;
V_116 = V_110 -> V_117 ;
}
static inline unsigned long F_84 ( T_5 V_118 )
{
return F_85 ( V_118 ) + F_86 ( V_118 ) ;
}
static int F_87 ( struct V_2 * V_2 , void * V_106 )
{
return F_1 ( V_2 ) -> V_5 . V_119 == * ( T_5 * ) V_106 ;
}
static int F_88 ( struct V_2 * V_2 , void * V_106 )
{
F_1 ( V_2 ) -> V_5 . V_119 = * ( T_5 * ) V_106 ;
return 0 ;
}
struct V_4 * F_89 ( T_5 V_118 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_90 ( V_116 , F_84 ( V_118 ) ,
F_87 , F_88 , & V_118 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_12 & V_120 ) {
V_5 -> V_121 = NULL ;
V_5 -> V_122 = NULL ;
V_5 -> V_19 = V_2 ;
V_5 -> V_26 = ( 1 << V_2 -> V_27 ) ;
V_5 -> V_123 = 0 ;
V_5 -> V_124 = 0 ;
V_2 -> V_125 = V_126 ;
V_2 -> V_127 = V_118 ;
V_2 -> V_97 = V_5 ;
V_2 -> V_9 . V_128 = & V_129 ;
F_91 ( & V_2 -> V_9 , V_130 ) ;
V_2 -> V_9 . V_6 = & V_131 ;
F_7 ( & V_100 ) ;
F_92 ( & V_5 -> V_94 , & V_132 ) ;
F_9 ( & V_100 ) ;
F_93 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_94 ( struct V_4 * V_5 )
{
F_95 ( V_5 -> V_19 ) ;
return V_5 ;
}
long F_96 ( void )
{
struct V_4 * V_5 ;
long V_71 = 0 ;
F_7 ( & V_100 ) ;
F_97 (bdev, &all_bdevs, bd_list) {
V_71 += V_5 -> V_19 -> V_22 -> V_23 ;
}
F_9 ( & V_100 ) ;
return V_71 ;
}
void F_98 ( struct V_4 * V_5 )
{
F_99 ( V_5 -> V_19 ) ;
}
static struct V_4 * F_100 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_7 ( & V_100 ) ;
V_5 = V_2 -> V_97 ;
if ( V_5 ) {
F_95 ( V_5 -> V_19 ) ;
F_9 ( & V_100 ) ;
return V_5 ;
}
F_9 ( & V_100 ) ;
V_5 = F_89 ( V_2 -> V_127 ) ;
if ( V_5 ) {
F_7 ( & V_100 ) ;
if ( ! V_2 -> V_97 ) {
F_95 ( V_5 -> V_19 ) ;
V_2 -> V_97 = V_5 ;
V_2 -> V_22 = V_5 -> V_19 -> V_22 ;
F_92 ( & V_2 -> V_96 , & V_5 -> V_93 ) ;
}
F_9 ( & V_100 ) ;
}
return V_5 ;
}
void F_101 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_7 ( & V_100 ) ;
if ( V_2 -> V_97 ) {
if ( ! F_102 ( V_2 -> V_133 ) )
V_5 = V_2 -> V_97 ;
F_69 ( V_2 ) ;
}
F_9 ( & V_100 ) ;
if ( V_5 )
F_99 ( V_5 -> V_19 ) ;
}
static bool F_103 ( struct V_4 * V_5 , struct V_4 * V_134 ,
void * V_135 )
{
if ( V_5 -> V_136 == V_135 )
return true ;
else if ( V_5 -> V_136 != NULL )
return false ;
else if ( V_5 -> V_121 == V_5 )
return true ;
else if ( V_134 -> V_136 == F_103 )
return true ;
else if ( V_134 -> V_136 != NULL )
return false ;
else
return true ;
}
static int F_104 ( struct V_4 * V_5 ,
struct V_4 * V_134 , void * V_135 )
{
V_137:
if ( ! F_103 ( V_5 , V_134 , V_135 ) )
return - V_138 ;
if ( V_134 -> V_139 ) {
T_6 * V_140 = F_105 ( & V_134 -> V_139 , 0 ) ;
F_106 ( V_55 ) ;
F_107 ( V_140 , & V_55 , V_141 ) ;
F_9 ( & V_100 ) ;
F_108 () ;
F_109 ( V_140 , & V_55 ) ;
F_7 ( & V_100 ) ;
goto V_137;
}
return 0 ;
}
static struct V_4 * F_110 ( struct V_4 * V_5 ,
void * V_135 )
{
struct V_142 * V_143 ;
struct V_4 * V_134 ;
int V_144 , V_108 ;
F_111 () ;
V_143 = F_112 ( V_5 -> V_119 , & V_144 ) ;
if ( ! V_143 )
return F_41 ( - V_145 ) ;
if ( V_144 )
V_134 = F_113 ( V_143 , 0 ) ;
else
V_134 = F_94 ( V_5 ) ;
F_114 ( V_143 -> V_146 -> V_147 ) ;
F_115 ( V_143 ) ;
if ( ! V_134 )
return F_41 ( - V_148 ) ;
F_7 ( & V_100 ) ;
V_108 = F_104 ( V_5 , V_134 , V_135 ) ;
if ( V_108 == 0 ) {
V_134 -> V_139 = V_135 ;
F_9 ( & V_100 ) ;
return V_134 ;
} else {
F_9 ( & V_100 ) ;
F_98 ( V_134 ) ;
return F_41 ( V_108 ) ;
}
}
static struct V_149 * F_116 ( struct V_4 * V_5 ,
struct V_142 * V_143 )
{
struct V_149 * V_135 ;
F_97 (holder, &bdev->bd_holder_disks, list)
if ( V_135 -> V_143 == V_143 )
return V_135 ;
return NULL ;
}
static int F_117 ( struct V_150 * V_151 , struct V_150 * V_152 )
{
return F_118 ( V_151 , V_152 , F_119 ( V_152 ) ) ;
}
static void F_120 ( struct V_150 * V_151 , struct V_150 * V_152 )
{
F_121 ( V_151 , F_119 ( V_152 ) ) ;
}
int F_122 ( struct V_4 * V_5 , struct V_142 * V_143 )
{
struct V_149 * V_135 ;
int V_71 = 0 ;
F_36 ( & V_5 -> V_92 ) ;
F_123 ( ! V_5 -> V_136 ) ;
if ( F_124 ( ! V_143 -> V_153 || ! V_5 -> V_154 -> V_155 ) )
goto V_156;
V_135 = F_116 ( V_5 , V_143 ) ;
if ( V_135 ) {
V_135 -> V_157 ++ ;
goto V_156;
}
V_135 = F_125 ( sizeof( * V_135 ) , V_82 ) ;
if ( ! V_135 ) {
V_71 = - V_148 ;
goto V_156;
}
F_61 ( & V_135 -> V_158 ) ;
V_135 -> V_143 = V_143 ;
V_135 -> V_157 = 1 ;
V_71 = F_117 ( V_143 -> V_153 , & F_126 ( V_5 -> V_154 ) -> V_159 ) ;
if ( V_71 )
goto V_160;
V_71 = F_117 ( V_5 -> V_154 -> V_155 , & F_127 ( V_143 ) -> V_159 ) ;
if ( V_71 )
goto V_161;
F_128 ( V_5 -> V_154 -> V_155 ) ;
F_92 ( & V_135 -> V_158 , & V_5 -> V_95 ) ;
goto V_156;
V_161:
F_120 ( V_143 -> V_153 , & F_126 ( V_5 -> V_154 ) -> V_159 ) ;
V_160:
F_129 ( V_135 ) ;
V_156:
F_37 ( & V_5 -> V_92 ) ;
return V_71 ;
}
void F_130 ( struct V_4 * V_5 , struct V_142 * V_143 )
{
struct V_149 * V_135 ;
F_36 ( & V_5 -> V_92 ) ;
V_135 = F_116 ( V_5 , V_143 ) ;
if ( ! F_123 ( V_135 == NULL ) && ! -- V_135 -> V_157 ) {
F_120 ( V_143 -> V_153 , & F_126 ( V_5 -> V_154 ) -> V_159 ) ;
F_120 ( V_5 -> V_154 -> V_155 ,
& F_127 ( V_143 ) -> V_159 ) ;
F_131 ( V_5 -> V_154 -> V_155 ) ;
F_70 ( & V_135 -> V_158 ) ;
F_129 ( V_135 ) ;
}
F_37 ( & V_5 -> V_92 ) ;
}
static void F_132 ( struct V_4 * V_5 , bool V_162 )
{
if ( F_133 ( V_5 , V_162 ) ) {
char V_163 [ V_164 ] = L_5 ;
if ( V_5 -> V_165 )
F_134 ( V_5 -> V_165 , 0 , V_163 ) ;
F_135 ( V_166 L_6
L_7 , V_163 ) ;
}
if ( ! V_5 -> V_165 )
return;
if ( F_136 ( V_5 -> V_165 ) )
V_5 -> V_124 = 1 ;
}
void F_137 ( struct V_142 * V_143 , struct V_4 * V_5 )
{
T_2 V_167 , V_168 ;
V_167 = ( T_2 ) F_138 ( V_143 ) << 9 ;
V_168 = F_11 ( V_5 -> V_19 ) ;
if ( V_167 != V_168 ) {
char V_163 [ V_164 ] ;
F_134 ( V_143 , 0 , V_163 ) ;
F_135 ( V_169
L_8 ,
V_163 , V_168 , V_167 ) ;
F_139 ( V_5 -> V_19 , V_167 ) ;
F_132 ( V_5 , false ) ;
}
}
int F_140 ( struct V_142 * V_143 )
{
struct V_4 * V_5 ;
int V_71 = 0 ;
if ( V_143 -> V_146 -> F_140 )
V_71 = V_143 -> V_146 -> F_140 ( V_143 ) ;
V_5 = F_113 ( V_143 , 0 ) ;
if ( ! V_5 )
return V_71 ;
F_36 ( & V_5 -> V_92 ) ;
F_137 ( V_143 , V_5 ) ;
F_37 ( & V_5 -> V_92 ) ;
F_98 ( V_5 ) ;
return V_71 ;
}
int F_141 ( struct V_4 * V_5 )
{
struct V_142 * V_143 = V_5 -> V_165 ;
const struct V_170 * V_171 = V_143 -> V_146 ;
unsigned int V_172 ;
V_172 = F_142 ( V_143 , V_173 |
V_174 ) ;
if ( ! ( V_172 & V_173 ) )
return 0 ;
F_132 ( V_5 , true ) ;
if ( V_171 -> F_140 )
V_171 -> F_140 ( V_5 -> V_165 ) ;
return 1 ;
}
void F_143 ( struct V_4 * V_5 , T_2 V_20 )
{
unsigned V_175 = F_19 ( V_5 ) ;
V_5 -> V_19 -> V_176 = V_20 ;
while ( V_175 < V_177 ) {
if ( V_20 & V_175 )
break;
V_175 <<= 1 ;
}
V_5 -> V_26 = V_175 ;
V_5 -> V_19 -> V_27 = F_13 ( V_175 ) ;
}
static int F_144 ( struct V_4 * V_5 , T_7 V_178 , int V_179 )
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
V_71 = F_145 ( V_5 -> V_19 , V_181 ) ;
if ( V_71 != 0 ) {
F_98 ( V_5 ) ;
return V_71 ;
}
}
V_186:
V_71 = - V_145 ;
V_143 = F_112 ( V_5 -> V_119 , & V_144 ) ;
if ( ! V_143 )
goto V_59;
V_147 = V_143 -> V_146 -> V_147 ;
F_146 ( V_143 ) ;
F_147 ( & V_5 -> V_92 , V_179 ) ;
if ( ! V_5 -> V_187 ) {
V_5 -> V_165 = V_143 ;
V_5 -> V_121 = V_5 ;
if ( ! V_144 ) {
struct V_6 * V_89 ;
V_71 = - V_145 ;
V_5 -> V_154 = F_148 ( V_143 , V_144 ) ;
if ( ! V_5 -> V_154 )
goto V_188;
V_71 = 0 ;
if ( V_143 -> V_146 -> V_189 ) {
V_71 = V_143 -> V_146 -> V_189 ( V_5 , V_178 ) ;
if ( V_71 == - V_190 ) {
F_149 ( V_5 -> V_154 ) ;
V_5 -> V_154 = NULL ;
V_5 -> V_165 = NULL ;
F_37 ( & V_5 -> V_92 ) ;
F_150 ( V_143 ) ;
F_115 ( V_143 ) ;
F_114 ( V_147 ) ;
goto V_186;
}
}
if ( ! V_71 && ! V_5 -> V_187 ) {
F_143 ( V_5 , ( T_2 ) F_138 ( V_143 ) << 9 ) ;
V_89 = F_151 ( V_5 ) ;
if ( V_89 == NULL )
V_89 = & V_131 ;
F_4 ( V_5 -> V_19 , V_89 ) ;
}
if ( V_5 -> V_124 && ( ! V_71 || V_71 == - V_191 ) )
F_152 ( V_143 , V_5 ) ;
if ( V_71 )
goto V_188;
} else {
struct V_4 * V_134 ;
V_134 = F_113 ( V_143 , 0 ) ;
V_71 = - V_148 ;
if ( ! V_134 )
goto V_188;
F_153 ( V_179 ) ;
V_71 = F_144 ( V_134 , V_178 , 1 ) ;
if ( V_71 )
goto V_188;
V_5 -> V_121 = V_134 ;
F_4 ( V_5 -> V_19 ,
V_134 -> V_19 -> V_9 . V_6 ) ;
V_5 -> V_154 = F_148 ( V_143 , V_144 ) ;
if ( ! ( V_143 -> V_67 & V_192 ) ||
! V_5 -> V_154 || ! V_5 -> V_154 -> V_193 ) {
V_71 = - V_145 ;
goto V_188;
}
F_143 ( V_5 , ( T_2 ) V_5 -> V_154 -> V_193 << 9 ) ;
}
} else {
if ( V_5 -> V_121 == V_5 ) {
V_71 = 0 ;
if ( V_5 -> V_165 -> V_146 -> V_189 )
V_71 = V_5 -> V_165 -> V_146 -> V_189 ( V_5 , V_178 ) ;
if ( V_5 -> V_124 && ( ! V_71 || V_71 == - V_191 ) )
F_152 ( V_5 -> V_165 , V_5 ) ;
if ( V_71 )
goto V_194;
}
F_115 ( V_143 ) ;
F_114 ( V_147 ) ;
}
V_5 -> V_187 ++ ;
if ( V_179 )
V_5 -> V_123 ++ ;
F_37 ( & V_5 -> V_92 ) ;
F_150 ( V_143 ) ;
return 0 ;
V_188:
F_149 ( V_5 -> V_154 ) ;
V_5 -> V_165 = NULL ;
V_5 -> V_154 = NULL ;
F_4 ( V_5 -> V_19 , & V_131 ) ;
if ( V_5 != V_5 -> V_121 )
F_154 ( V_5 -> V_121 , V_178 , 1 ) ;
V_5 -> V_121 = NULL ;
V_194:
F_37 ( & V_5 -> V_92 ) ;
F_150 ( V_143 ) ;
F_115 ( V_143 ) ;
F_114 ( V_147 ) ;
V_59:
F_98 ( V_5 ) ;
return V_71 ;
}
int F_155 ( struct V_4 * V_5 , T_7 V_178 , void * V_135 )
{
struct V_4 * V_134 = NULL ;
int V_56 ;
F_123 ( ( V_178 & V_195 ) && ! V_135 ) ;
if ( ( V_178 & V_195 ) && V_135 ) {
V_134 = F_110 ( V_5 , V_135 ) ;
if ( F_82 ( V_134 ) ) {
F_98 ( V_5 ) ;
return F_156 ( V_134 ) ;
}
}
V_56 = F_144 ( V_5 , V_178 , 0 ) ;
if ( V_134 ) {
struct V_142 * V_143 = V_134 -> V_165 ;
F_36 ( & V_5 -> V_92 ) ;
F_7 ( & V_100 ) ;
if ( ! V_56 ) {
F_153 ( ! F_103 ( V_5 , V_134 , V_135 ) ) ;
V_134 -> V_196 ++ ;
V_134 -> V_136 = F_103 ;
V_5 -> V_196 ++ ;
V_5 -> V_136 = V_135 ;
}
F_153 ( V_134 -> V_139 != V_135 ) ;
V_134 -> V_139 = NULL ;
F_157 ( & V_134 -> V_139 , 0 ) ;
F_9 ( & V_100 ) ;
if ( ! V_56 && ( V_178 & V_184 ) && ! V_5 -> V_197 &&
( V_143 -> V_67 & V_198 ) ) {
V_5 -> V_197 = true ;
F_146 ( V_143 ) ;
}
F_37 ( & V_5 -> V_92 ) ;
F_98 ( V_134 ) ;
}
return V_56 ;
}
struct V_4 * F_158 ( const char * V_199 , T_7 V_178 ,
void * V_135 )
{
struct V_4 * V_5 ;
int V_108 ;
V_5 = F_159 ( V_199 ) ;
if ( F_82 ( V_5 ) )
return V_5 ;
V_108 = F_155 ( V_5 , V_178 , V_135 ) ;
if ( V_108 )
return F_41 ( V_108 ) ;
if ( ( V_178 & V_184 ) && F_160 ( V_5 ) ) {
F_161 ( V_5 , V_178 ) ;
return F_41 ( - V_200 ) ;
}
return V_5 ;
}
struct V_4 * F_162 ( T_5 V_118 , T_7 V_178 , void * V_135 )
{
struct V_4 * V_5 ;
int V_108 ;
V_5 = F_89 ( V_118 ) ;
if ( ! V_5 )
return F_41 ( - V_148 ) ;
V_108 = F_155 ( V_5 , V_178 , V_135 ) ;
if ( V_108 )
return F_41 ( V_108 ) ;
return V_5 ;
}
static int F_163 ( struct V_2 * V_2 , struct V_51 * V_78 )
{
struct V_4 * V_5 ;
V_78 -> V_201 |= V_202 ;
if ( V_78 -> V_201 & V_203 )
V_78 -> V_204 |= V_205 ;
if ( V_78 -> V_201 & V_206 )
V_78 -> V_204 |= V_195 ;
if ( ( V_78 -> V_201 & V_207 ) == 3 )
V_78 -> V_204 |= V_208 ;
V_5 = F_100 ( V_2 ) ;
if ( V_5 == NULL )
return - V_148 ;
V_78 -> V_53 = V_5 -> V_19 -> V_22 ;
return F_155 ( V_5 , V_78 -> V_204 , V_78 ) ;
}
static int F_154 ( struct V_4 * V_5 , T_7 V_178 , int V_179 )
{
int V_71 = 0 ;
struct V_142 * V_143 = V_5 -> V_165 ;
struct V_4 * V_209 = NULL ;
F_147 ( & V_5 -> V_92 , V_179 ) ;
if ( V_179 )
V_5 -> V_123 -- ;
if ( ! -- V_5 -> V_187 ) {
F_123 ( V_5 -> V_196 ) ;
F_20 ( V_5 ) ;
F_14 ( V_5 ) ;
F_4 ( V_5 -> V_19 ,
& V_131 ) ;
}
if ( V_5 -> V_121 == V_5 ) {
if ( V_143 -> V_146 -> V_210 )
V_71 = V_143 -> V_146 -> V_210 ( V_143 , V_178 ) ;
}
if ( ! V_5 -> V_187 ) {
struct V_180 * V_147 = V_143 -> V_146 -> V_147 ;
F_149 ( V_5 -> V_154 ) ;
V_5 -> V_154 = NULL ;
V_5 -> V_165 = NULL ;
if ( V_5 != V_5 -> V_121 )
V_209 = V_5 -> V_121 ;
V_5 -> V_121 = NULL ;
F_115 ( V_143 ) ;
F_114 ( V_147 ) ;
}
F_37 ( & V_5 -> V_92 ) ;
F_98 ( V_5 ) ;
if ( V_209 )
F_154 ( V_209 , V_178 , 1 ) ;
return V_71 ;
}
int F_161 ( struct V_4 * V_5 , T_7 V_178 )
{
F_36 ( & V_5 -> V_92 ) ;
if ( V_178 & V_195 ) {
bool V_211 ;
F_7 ( & V_100 ) ;
F_123 ( -- V_5 -> V_196 < 0 ) ;
F_123 ( -- V_5 -> V_121 -> V_196 < 0 ) ;
if ( ( V_211 = ! V_5 -> V_196 ) )
V_5 -> V_136 = NULL ;
if ( ! V_5 -> V_121 -> V_196 )
V_5 -> V_121 -> V_136 = NULL ;
F_9 ( & V_100 ) ;
if ( V_211 && V_5 -> V_197 ) {
F_150 ( V_5 -> V_165 ) ;
V_5 -> V_197 = false ;
}
}
F_164 ( V_5 -> V_165 , V_173 ) ;
F_37 ( & V_5 -> V_92 ) ;
return F_154 ( V_5 , V_178 , 0 ) ;
}
static int F_165 ( struct V_2 * V_2 , struct V_51 * V_78 )
{
struct V_4 * V_5 = F_3 ( V_78 -> V_53 -> V_54 ) ;
return F_161 ( V_5 , V_78 -> V_204 ) ;
}
static long F_166 ( struct V_51 * V_51 , unsigned V_212 , unsigned long V_213 )
{
struct V_4 * V_5 = F_3 ( V_51 -> V_53 -> V_54 ) ;
T_7 V_178 = V_51 -> V_204 ;
if ( V_51 -> V_201 & V_203 )
V_178 |= V_205 ;
else
V_178 &= ~ V_205 ;
return F_167 ( V_5 , V_178 , V_212 , V_213 ) ;
}
T_3 F_168 ( struct V_45 * V_46 , const struct V_47 * V_48 ,
unsigned long V_50 , T_2 V_65 )
{
struct V_51 * V_51 = V_46 -> V_52 ;
T_3 V_71 ;
F_153 ( V_46 -> V_214 != V_65 ) ;
V_71 = F_169 ( V_46 , V_48 , V_50 , & V_46 -> V_214 ) ;
if ( V_71 > 0 || V_71 == - V_215 ) {
T_3 V_108 ;
V_108 = F_170 ( V_51 , V_65 , V_71 ) ;
if ( V_108 < 0 && V_71 > 0 )
V_71 = V_108 ;
}
return V_71 ;
}
static int F_171 ( struct V_60 * V_60 , T_8 V_55 )
{
struct V_28 * V_216 = F_1 ( V_60 -> V_64 -> V_54 ) -> V_5 . V_122 ;
if ( V_216 && V_216 -> V_217 -> V_218 )
return V_216 -> V_217 -> V_218 ( V_216 , V_60 , V_55 ) ;
return F_172 ( V_60 ) ;
}
int F_173 ( struct V_4 * V_5 , unsigned V_212 , unsigned long V_213 )
{
int V_56 ;
T_9 V_219 = F_174 () ;
F_175 ( V_220 ) ;
V_56 = F_167 ( V_5 , 0 , V_212 , V_213 ) ;
F_175 ( V_219 ) ;
return V_56 ;
}
struct V_4 * F_159 ( const char * V_221 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_199 V_199 ;
int error ;
if ( ! V_221 || ! * V_221 )
return F_41 ( - V_25 ) ;
error = F_176 ( V_221 , V_222 , & V_199 ) ;
if ( error )
return F_41 ( error ) ;
V_2 = V_199 . V_102 -> V_223 ;
error = - V_224 ;
if ( ! F_177 ( V_2 -> V_125 ) )
goto V_225;
error = - V_200 ;
if ( V_199 . V_226 -> V_227 & V_228 )
goto V_225;
error = - V_148 ;
V_5 = F_100 ( V_2 ) ;
if ( ! V_5 )
goto V_225;
V_59:
F_178 ( & V_199 ) ;
return V_5 ;
V_225:
V_5 = F_41 ( error ) ;
goto V_59;
}
int F_133 ( struct V_4 * V_5 , bool V_162 )
{
struct V_28 * V_29 = F_32 ( V_5 ) ;
int V_56 = 0 ;
if ( V_29 ) {
F_179 ( V_29 ) ;
V_56 = F_180 ( V_29 , V_162 ) ;
F_34 ( V_29 ) ;
}
F_181 ( V_5 ) ;
return V_56 ;
}

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
F_5 ( & V_8 ) ;
F_5 ( & V_2 -> V_9 ) ;
V_2 -> V_10 . V_6 = V_7 ;
if ( V_2 -> V_11 & V_12 )
F_6 ( & V_2 -> V_13 , & V_7 -> V_14 . V_15 ) ;
F_7 ( & V_2 -> V_9 ) ;
F_7 ( & V_8 ) ;
}
static T_1 F_8 ( struct V_4 * V_5 )
{
T_1 V_16 = ~ ( ( T_1 ) 0 ) ;
T_2 V_17 = F_9 ( V_5 -> V_18 ) ;
if ( V_17 ) {
unsigned int V_19 = F_10 ( V_5 ) ;
unsigned int V_20 = F_11 ( V_19 ) ;
V_16 = ( V_17 >> V_20 ) ;
}
return V_16 ;
}
static void F_12 ( struct V_4 * V_5 )
{
if ( V_5 -> V_18 -> V_21 -> V_22 == 0 )
return;
F_13 () ;
F_14 ( V_5 -> V_18 -> V_21 , 0 ) ;
}
int F_15 ( struct V_4 * V_5 , int V_19 )
{
if ( V_19 > V_23 || V_19 < 512 || ! F_16 ( V_19 ) )
return - V_24 ;
if ( V_19 < F_17 ( V_5 ) )
return - V_24 ;
if ( V_5 -> V_25 != V_19 ) {
F_18 ( V_5 ) ;
V_5 -> V_25 = V_19 ;
V_5 -> V_18 -> V_26 = F_11 ( V_19 ) ;
F_12 ( V_5 ) ;
}
return 0 ;
}
int F_19 ( struct V_27 * V_28 , int V_19 )
{
if ( F_15 ( V_28 -> V_29 , V_19 ) )
return 0 ;
V_28 -> V_30 = V_19 ;
V_28 -> V_31 = F_11 ( V_19 ) ;
return V_28 -> V_30 ;
}
int F_20 ( struct V_27 * V_28 , int V_19 )
{
int V_32 = F_17 ( V_28 -> V_29 ) ;
if ( V_19 < V_32 )
V_19 = V_32 ;
return F_19 ( V_28 , V_19 ) ;
}
static int
F_21 ( struct V_2 * V_2 , T_1 V_33 ,
struct V_34 * V_35 , int V_36 )
{
if ( V_33 >= F_8 ( F_3 ( V_2 ) ) ) {
if ( V_36 )
return - V_37 ;
return 0 ;
}
V_35 -> V_38 = F_3 ( V_2 ) ;
V_35 -> V_39 = V_33 ;
F_22 ( V_35 ) ;
return 0 ;
}
static int
F_23 ( struct V_2 * V_2 , T_1 V_33 ,
struct V_34 * V_35 , int V_36 )
{
T_1 V_40 = F_8 ( F_3 ( V_2 ) ) ;
unsigned long V_41 = V_35 -> V_42 >> V_2 -> V_26 ;
if ( ( V_33 + V_41 ) > V_40 ) {
V_41 = V_40 - V_33 ;
if ( ( long ) V_41 <= 0 ) {
if ( V_36 )
return - V_37 ;
V_41 = 0 ;
}
}
V_35 -> V_38 = F_3 ( V_2 ) ;
V_35 -> V_39 = V_33 ;
V_35 -> V_42 = V_41 << V_2 -> V_26 ;
if ( V_41 )
F_22 ( V_35 ) ;
return 0 ;
}
static T_3
F_24 ( int V_43 , struct V_44 * V_45 , const struct V_46 * V_47 ,
T_2 V_48 , unsigned long V_49 )
{
struct V_50 * V_50 = V_45 -> V_51 ;
struct V_2 * V_2 = V_50 -> V_52 -> V_53 ;
return F_25 ( V_43 , V_45 , V_2 , F_3 ( V_2 ) , V_47 , V_48 ,
V_49 , F_23 , NULL , NULL , 0 ) ;
}
int F_26 ( struct V_4 * V_5 , int V_54 )
{
if ( ! V_5 )
return 0 ;
if ( ! V_54 )
return F_27 ( V_5 -> V_18 -> V_21 ) ;
return F_28 ( V_5 -> V_18 -> V_21 ) ;
}
int F_18 ( struct V_4 * V_5 )
{
return F_26 ( V_5 , 1 ) ;
}
int F_29 ( struct V_4 * V_5 )
{
struct V_27 * V_28 = F_30 ( V_5 ) ;
if ( V_28 ) {
int V_55 = F_31 ( V_28 ) ;
F_32 ( V_28 ) ;
return V_55 ;
}
return F_18 ( V_5 ) ;
}
struct V_27 * F_33 ( struct V_4 * V_5 )
{
struct V_27 * V_28 ;
int error = 0 ;
F_34 ( & V_5 -> V_56 ) ;
if ( ++ V_5 -> V_57 > 1 ) {
V_28 = F_30 ( V_5 ) ;
F_32 ( V_28 ) ;
F_35 ( & V_5 -> V_56 ) ;
return V_28 ;
}
V_28 = F_36 ( V_5 ) ;
if ( ! V_28 )
goto V_58;
error = F_37 ( V_28 ) ;
if ( error ) {
F_38 ( V_28 ) ;
V_5 -> V_57 -- ;
F_35 ( & V_5 -> V_56 ) ;
return F_39 ( error ) ;
}
F_38 ( V_28 ) ;
V_58:
F_18 ( V_5 ) ;
F_35 ( & V_5 -> V_56 ) ;
return V_28 ;
}
int F_40 ( struct V_4 * V_5 , struct V_27 * V_28 )
{
int error = - V_24 ;
F_34 ( & V_5 -> V_56 ) ;
if ( ! V_5 -> V_57 )
goto V_58;
error = 0 ;
if ( -- V_5 -> V_57 > 0 )
goto V_58;
if ( ! V_28 )
goto V_58;
error = F_41 ( V_28 ) ;
if ( error ) {
V_5 -> V_57 ++ ;
F_35 ( & V_5 -> V_56 ) ;
return error ;
}
V_58:
F_35 ( & V_5 -> V_56 ) ;
return 0 ;
}
static int F_42 ( struct V_59 * V_59 , struct V_60 * V_61 )
{
return F_43 ( V_59 , F_21 , V_61 ) ;
}
static int F_44 ( struct V_50 * V_50 , struct V_59 * V_59 )
{
return F_45 ( V_59 , F_21 ) ;
}
static int F_46 ( struct V_50 * V_50 , struct V_62 * V_63 ,
T_2 V_64 , unsigned V_65 , unsigned V_66 ,
struct V_59 * * V_67 , void * * V_68 )
{
return F_47 ( V_63 , V_64 , V_65 , V_66 , V_67 ,
F_21 ) ;
}
static int F_48 ( struct V_50 * V_50 , struct V_62 * V_63 ,
T_2 V_64 , unsigned V_65 , unsigned V_69 ,
struct V_59 * V_59 , void * V_68 )
{
int V_70 ;
V_70 = F_49 ( V_50 , V_63 , V_64 , V_65 , V_69 , V_59 , V_68 ) ;
F_50 ( V_59 ) ;
F_51 ( V_59 ) ;
return V_70 ;
}
static T_2 F_52 ( struct V_50 * V_50 , T_2 V_48 , int V_71 )
{
struct V_2 * V_18 = V_50 -> V_52 -> V_53 ;
T_2 V_19 ;
T_2 V_16 ;
F_34 ( & V_18 -> V_72 ) ;
V_19 = F_9 ( V_18 ) ;
switch ( V_71 ) {
case 2 :
V_48 += V_19 ;
break;
case 1 :
V_48 += V_50 -> V_73 ;
}
V_16 = - V_24 ;
if ( V_48 >= 0 && V_48 <= V_19 ) {
if ( V_48 != V_50 -> V_73 ) {
V_50 -> V_73 = V_48 ;
}
V_16 = V_48 ;
}
F_35 ( & V_18 -> V_72 ) ;
return V_16 ;
}
int F_53 ( struct V_50 * V_74 , int V_75 )
{
struct V_2 * V_18 = V_74 -> V_52 -> V_53 ;
struct V_4 * V_5 = F_3 ( V_18 ) ;
int error ;
F_35 ( & V_18 -> V_72 ) ;
error = F_54 ( V_5 , V_76 , NULL ) ;
if ( error == - V_77 )
error = 0 ;
F_34 ( & V_18 -> V_72 ) ;
return error ;
}
static struct V_2 * F_55 ( struct V_27 * V_28 )
{
struct V_1 * V_78 = F_56 ( V_79 , V_76 ) ;
if ( ! V_78 )
return NULL ;
return & V_78 -> V_3 ;
}
static void F_57 ( struct V_80 * V_81 )
{
struct V_2 * V_2 = F_2 ( V_81 , struct V_2 , V_82 ) ;
struct V_1 * V_83 = F_1 ( V_2 ) ;
F_58 ( & V_2 -> V_84 ) ;
F_59 ( V_79 , V_83 ) ;
}
static void F_60 ( struct V_2 * V_2 )
{
F_61 ( & V_2 -> V_82 , F_57 ) ;
}
static void F_62 ( void * V_85 )
{
struct V_1 * V_78 = (struct V_1 * ) V_85 ;
struct V_4 * V_5 = & V_78 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_63 ( & V_5 -> V_86 ) ;
F_58 ( & V_5 -> V_87 ) ;
F_58 ( & V_5 -> V_88 ) ;
#ifdef F_64
F_58 ( & V_5 -> V_89 ) ;
#endif
F_65 ( & V_78 -> V_3 ) ;
F_63 ( & V_5 -> V_56 ) ;
}
static inline void F_66 ( struct V_2 * V_2 )
{
F_67 ( & V_2 -> V_90 ) ;
V_2 -> V_91 = NULL ;
V_2 -> V_21 = & V_2 -> V_10 ;
}
static void F_68 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
struct V_92 * V_93 ;
F_14 ( & V_2 -> V_10 , 0 ) ;
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
F_5 ( & V_94 ) ;
while ( ( V_93 = V_5 -> V_87 . V_95 ) != & V_5 -> V_87 ) {
F_66 ( F_71 ( V_93 , struct V_2 , V_90 ) ) ;
}
F_67 ( & V_5 -> V_88 ) ;
F_7 ( & V_94 ) ;
}
static struct V_96 * F_72 ( struct V_97 * V_98 ,
int V_66 , const char * V_99 , void * V_100 )
{
return F_73 ( V_98 , L_1 , & V_101 , NULL , 0x62646576 ) ;
}
void T_4 F_74 ( void )
{
int V_102 ;
struct V_103 * V_104 ;
V_79 = F_75 ( L_2 , sizeof( struct V_1 ) ,
0 , ( V_105 | V_106 |
V_107 | V_108 ) ,
F_62 ) ;
V_102 = F_76 ( & V_109 ) ;
if ( V_102 )
F_77 ( L_3 ) ;
V_104 = F_78 ( & V_109 ) ;
if ( F_79 ( V_104 ) )
F_77 ( L_4 ) ;
F_80 ( V_104 ) ;
V_110 = V_104 -> V_111 ;
}
static inline unsigned long F_81 ( T_5 V_112 )
{
return F_82 ( V_112 ) + F_83 ( V_112 ) ;
}
static int F_84 ( struct V_2 * V_2 , void * V_100 )
{
return F_1 ( V_2 ) -> V_5 . V_113 == * ( T_5 * ) V_100 ;
}
static int F_85 ( struct V_2 * V_2 , void * V_100 )
{
F_1 ( V_2 ) -> V_5 . V_113 = * ( T_5 * ) V_100 ;
return 0 ;
}
struct V_4 * F_86 ( T_5 V_112 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_87 ( V_110 , F_81 ( V_112 ) ,
F_84 , F_85 , & V_112 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_11 & V_114 ) {
V_5 -> V_115 = NULL ;
V_5 -> V_18 = V_2 ;
V_5 -> V_25 = ( 1 << V_2 -> V_26 ) ;
V_5 -> V_116 = 0 ;
V_5 -> V_117 = 0 ;
V_2 -> V_118 = V_119 ;
V_2 -> V_120 = V_112 ;
V_2 -> V_91 = V_5 ;
V_2 -> V_10 . V_121 = & V_122 ;
F_88 ( & V_2 -> V_10 , V_123 ) ;
V_2 -> V_10 . V_6 = & V_124 ;
F_5 ( & V_94 ) ;
F_89 ( & V_5 -> V_88 , & V_125 ) ;
F_7 ( & V_94 ) ;
F_90 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_91 ( struct V_4 * V_5 )
{
F_92 ( V_5 -> V_18 ) ;
return V_5 ;
}
long F_93 ( void )
{
struct V_4 * V_5 ;
long V_70 = 0 ;
F_5 ( & V_94 ) ;
F_94 (bdev, &all_bdevs, bd_list) {
V_70 += V_5 -> V_18 -> V_21 -> V_22 ;
}
F_7 ( & V_94 ) ;
return V_70 ;
}
void F_95 ( struct V_4 * V_5 )
{
F_96 ( V_5 -> V_18 ) ;
}
static struct V_4 * F_97 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_5 ( & V_94 ) ;
V_5 = V_2 -> V_91 ;
if ( V_5 ) {
F_92 ( V_5 -> V_18 ) ;
F_7 ( & V_94 ) ;
return V_5 ;
}
F_7 ( & V_94 ) ;
V_5 = F_86 ( V_2 -> V_120 ) ;
if ( V_5 ) {
F_5 ( & V_94 ) ;
if ( ! V_2 -> V_91 ) {
F_92 ( V_5 -> V_18 ) ;
V_2 -> V_91 = V_5 ;
V_2 -> V_21 = V_5 -> V_18 -> V_21 ;
F_89 ( & V_2 -> V_90 , & V_5 -> V_87 ) ;
}
F_7 ( & V_94 ) ;
}
return V_5 ;
}
void F_98 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_5 ( & V_94 ) ;
if ( V_2 -> V_91 ) {
if ( ! F_99 ( V_2 -> V_126 ) )
V_5 = V_2 -> V_91 ;
F_66 ( V_2 ) ;
}
F_7 ( & V_94 ) ;
if ( V_5 )
F_96 ( V_5 -> V_18 ) ;
}
static bool F_100 ( struct V_4 * V_5 , struct V_4 * V_127 ,
void * V_128 )
{
if ( V_5 -> V_129 == V_128 )
return true ;
else if ( V_5 -> V_129 != NULL )
return false ;
else if ( V_5 -> V_115 == V_5 )
return true ;
else if ( V_127 -> V_129 == F_100 )
return true ;
else if ( V_127 -> V_129 != NULL )
return false ;
else
return true ;
}
static int F_101 ( struct V_4 * V_5 ,
struct V_4 * V_127 , void * V_128 )
{
V_130:
if ( ! F_100 ( V_5 , V_127 , V_128 ) )
return - V_131 ;
if ( V_127 -> V_132 ) {
T_6 * V_133 = F_102 ( & V_127 -> V_132 , 0 ) ;
F_103 ( V_54 ) ;
F_104 ( V_133 , & V_54 , V_134 ) ;
F_7 ( & V_94 ) ;
F_105 () ;
F_106 ( V_133 , & V_54 ) ;
F_5 ( & V_94 ) ;
goto V_130;
}
return 0 ;
}
static struct V_4 * F_107 ( struct V_4 * V_5 ,
void * V_128 )
{
struct V_135 * V_136 ;
struct V_4 * V_127 ;
int V_137 , V_102 ;
F_108 () ;
V_136 = F_109 ( V_5 -> V_113 , & V_137 ) ;
if ( ! V_136 )
return F_39 ( - V_138 ) ;
if ( V_137 )
V_127 = F_110 ( V_136 , 0 ) ;
else
V_127 = F_91 ( V_5 ) ;
F_111 ( V_136 -> V_139 -> V_140 ) ;
F_112 ( V_136 ) ;
if ( ! V_127 )
return F_39 ( - V_141 ) ;
F_5 ( & V_94 ) ;
V_102 = F_101 ( V_5 , V_127 , V_128 ) ;
if ( V_102 == 0 ) {
V_127 -> V_132 = V_128 ;
F_7 ( & V_94 ) ;
return V_127 ;
} else {
F_7 ( & V_94 ) ;
F_95 ( V_127 ) ;
return F_39 ( V_102 ) ;
}
}
static struct V_142 * F_113 ( struct V_4 * V_5 ,
struct V_135 * V_136 )
{
struct V_142 * V_128 ;
F_94 (holder, &bdev->bd_holder_disks, list)
if ( V_128 -> V_136 == V_136 )
return V_128 ;
return NULL ;
}
static int F_114 ( struct V_143 * V_144 , struct V_143 * V_145 )
{
return F_115 ( V_144 , V_145 , F_116 ( V_145 ) ) ;
}
static void F_117 ( struct V_143 * V_144 , struct V_143 * V_145 )
{
F_118 ( V_144 , F_116 ( V_145 ) ) ;
}
int F_119 ( struct V_4 * V_5 , struct V_135 * V_136 )
{
struct V_142 * V_128 ;
int V_70 = 0 ;
F_34 ( & V_5 -> V_86 ) ;
F_120 ( ! V_5 -> V_129 ) ;
if ( F_121 ( ! V_136 -> V_146 || ! V_5 -> V_147 -> V_148 ) )
goto V_149;
V_128 = F_113 ( V_5 , V_136 ) ;
if ( V_128 ) {
V_128 -> V_150 ++ ;
goto V_149;
}
V_128 = F_122 ( sizeof( * V_128 ) , V_76 ) ;
if ( ! V_128 ) {
V_70 = - V_141 ;
goto V_149;
}
F_58 ( & V_128 -> V_151 ) ;
V_128 -> V_136 = V_136 ;
V_128 -> V_150 = 1 ;
V_70 = F_114 ( V_136 -> V_146 , & F_123 ( V_5 -> V_147 ) -> V_152 ) ;
if ( V_70 )
goto V_153;
V_70 = F_114 ( V_5 -> V_147 -> V_148 , & F_124 ( V_136 ) -> V_152 ) ;
if ( V_70 )
goto V_154;
F_125 ( V_5 -> V_147 -> V_148 ) ;
F_89 ( & V_128 -> V_151 , & V_5 -> V_89 ) ;
goto V_149;
V_154:
F_117 ( V_136 -> V_146 , & F_123 ( V_5 -> V_147 ) -> V_152 ) ;
V_153:
F_126 ( V_128 ) ;
V_149:
F_35 ( & V_5 -> V_86 ) ;
return V_70 ;
}
void F_127 ( struct V_4 * V_5 , struct V_135 * V_136 )
{
struct V_142 * V_128 ;
F_34 ( & V_5 -> V_86 ) ;
V_128 = F_113 ( V_5 , V_136 ) ;
if ( ! F_120 ( V_128 == NULL ) && ! -- V_128 -> V_150 ) {
F_117 ( V_136 -> V_146 , & F_123 ( V_5 -> V_147 ) -> V_152 ) ;
F_117 ( V_5 -> V_147 -> V_148 ,
& F_124 ( V_136 ) -> V_152 ) ;
F_128 ( V_5 -> V_147 -> V_148 ) ;
F_67 ( & V_128 -> V_151 ) ;
F_126 ( V_128 ) ;
}
F_35 ( & V_5 -> V_86 ) ;
}
static void F_129 ( struct V_4 * V_5 , bool V_155 )
{
if ( F_130 ( V_5 , V_155 ) ) {
char V_156 [ V_157 ] = L_5 ;
if ( V_5 -> V_158 )
F_131 ( V_5 -> V_158 , 0 , V_156 ) ;
F_132 ( V_159 L_6
L_7 , V_156 ) ;
}
if ( ! V_5 -> V_158 )
return;
if ( F_133 ( V_5 -> V_158 ) )
V_5 -> V_117 = 1 ;
}
void F_134 ( struct V_135 * V_136 , struct V_4 * V_5 )
{
T_2 V_160 , V_161 ;
V_160 = ( T_2 ) F_135 ( V_136 ) << 9 ;
V_161 = F_9 ( V_5 -> V_18 ) ;
if ( V_160 != V_161 ) {
char V_156 [ V_157 ] ;
F_131 ( V_136 , 0 , V_156 ) ;
F_132 ( V_162
L_8 ,
V_156 , V_161 , V_160 ) ;
F_136 ( V_5 -> V_18 , V_160 ) ;
F_129 ( V_5 , false ) ;
}
}
int F_137 ( struct V_135 * V_136 )
{
struct V_4 * V_5 ;
int V_70 = 0 ;
if ( V_136 -> V_139 -> F_137 )
V_70 = V_136 -> V_139 -> F_137 ( V_136 ) ;
V_5 = F_110 ( V_136 , 0 ) ;
if ( ! V_5 )
return V_70 ;
F_34 ( & V_5 -> V_86 ) ;
F_134 ( V_136 , V_5 ) ;
F_35 ( & V_5 -> V_86 ) ;
F_95 ( V_5 ) ;
return V_70 ;
}
int F_138 ( struct V_4 * V_5 )
{
struct V_135 * V_136 = V_5 -> V_158 ;
const struct V_163 * V_164 = V_136 -> V_139 ;
unsigned int V_165 ;
V_165 = F_139 ( V_136 , V_166 |
V_167 ) ;
if ( ! ( V_165 & V_166 ) )
return 0 ;
F_129 ( V_5 , true ) ;
if ( V_164 -> F_137 )
V_164 -> F_137 ( V_5 -> V_158 ) ;
return 1 ;
}
void F_140 ( struct V_4 * V_5 , T_2 V_19 )
{
unsigned V_168 = F_17 ( V_5 ) ;
V_5 -> V_18 -> V_169 = V_19 ;
while ( V_168 < V_170 ) {
if ( V_19 & V_168 )
break;
V_168 <<= 1 ;
}
V_5 -> V_25 = V_168 ;
V_5 -> V_18 -> V_26 = F_11 ( V_168 ) ;
}
static int F_141 ( struct V_4 * V_5 , T_7 V_171 , int V_172 )
{
struct V_135 * V_136 ;
int V_70 ;
int V_137 ;
int V_173 = 0 ;
if ( V_171 & V_174 )
V_173 |= V_175 ;
if ( V_171 & V_176 )
V_173 |= V_177 ;
if ( ! V_172 ) {
V_70 = F_142 ( V_5 -> V_18 , V_173 ) ;
if ( V_70 != 0 ) {
F_95 ( V_5 ) ;
return V_70 ;
}
}
V_178:
V_70 = - V_138 ;
V_136 = F_109 ( V_5 -> V_113 , & V_137 ) ;
if ( ! V_136 )
goto V_58;
F_143 ( V_136 ) ;
F_144 ( & V_5 -> V_86 , V_172 ) ;
if ( ! V_5 -> V_179 ) {
V_5 -> V_158 = V_136 ;
V_5 -> V_115 = V_5 ;
if ( ! V_137 ) {
struct V_6 * V_83 ;
V_70 = - V_138 ;
V_5 -> V_147 = F_145 ( V_136 , V_137 ) ;
if ( ! V_5 -> V_147 )
goto V_180;
V_70 = 0 ;
if ( V_136 -> V_139 -> V_181 ) {
V_70 = V_136 -> V_139 -> V_181 ( V_5 , V_171 ) ;
if ( V_70 == - V_182 ) {
F_146 ( V_5 -> V_147 ) ;
V_5 -> V_147 = NULL ;
V_5 -> V_158 = NULL ;
F_35 ( & V_5 -> V_86 ) ;
F_147 ( V_136 ) ;
F_111 ( V_136 -> V_139 -> V_140 ) ;
F_112 ( V_136 ) ;
goto V_178;
}
}
if ( ! V_70 && ! V_5 -> V_179 ) {
F_140 ( V_5 , ( T_2 ) F_135 ( V_136 ) << 9 ) ;
V_83 = F_148 ( V_5 ) ;
if ( V_83 == NULL )
V_83 = & V_124 ;
F_4 ( V_5 -> V_18 , V_83 ) ;
}
if ( V_5 -> V_117 && ( ! V_70 || V_70 == - V_183 ) )
F_149 ( V_136 , V_5 ) ;
if ( V_70 )
goto V_180;
} else {
struct V_4 * V_127 ;
V_127 = F_110 ( V_136 , 0 ) ;
V_70 = - V_141 ;
if ( ! V_127 )
goto V_180;
F_150 ( V_172 ) ;
V_70 = F_141 ( V_127 , V_171 , 1 ) ;
if ( V_70 )
goto V_180;
V_5 -> V_115 = V_127 ;
F_4 ( V_5 -> V_18 ,
V_127 -> V_18 -> V_10 . V_6 ) ;
V_5 -> V_147 = F_145 ( V_136 , V_137 ) ;
if ( ! ( V_136 -> V_66 & V_184 ) ||
! V_5 -> V_147 || ! V_5 -> V_147 -> V_185 ) {
V_70 = - V_138 ;
goto V_180;
}
F_140 ( V_5 , ( T_2 ) V_5 -> V_147 -> V_185 << 9 ) ;
}
} else {
if ( V_5 -> V_115 == V_5 ) {
V_70 = 0 ;
if ( V_5 -> V_158 -> V_139 -> V_181 )
V_70 = V_5 -> V_158 -> V_139 -> V_181 ( V_5 , V_171 ) ;
if ( V_5 -> V_117 && ( ! V_70 || V_70 == - V_183 ) )
F_149 ( V_5 -> V_158 , V_5 ) ;
if ( V_70 )
goto V_186;
}
F_111 ( V_136 -> V_139 -> V_140 ) ;
F_112 ( V_136 ) ;
}
V_5 -> V_179 ++ ;
if ( V_172 )
V_5 -> V_116 ++ ;
F_35 ( & V_5 -> V_86 ) ;
F_147 ( V_136 ) ;
return 0 ;
V_180:
F_146 ( V_5 -> V_147 ) ;
V_5 -> V_158 = NULL ;
V_5 -> V_147 = NULL ;
F_4 ( V_5 -> V_18 , & V_124 ) ;
if ( V_5 != V_5 -> V_115 )
F_151 ( V_5 -> V_115 , V_171 , 1 ) ;
V_5 -> V_115 = NULL ;
V_186:
F_35 ( & V_5 -> V_86 ) ;
F_147 ( V_136 ) ;
F_111 ( V_136 -> V_139 -> V_140 ) ;
F_112 ( V_136 ) ;
V_58:
F_95 ( V_5 ) ;
return V_70 ;
}
int F_152 ( struct V_4 * V_5 , T_7 V_171 , void * V_128 )
{
struct V_4 * V_127 = NULL ;
int V_55 ;
F_120 ( ( V_171 & V_187 ) && ! V_128 ) ;
if ( ( V_171 & V_187 ) && V_128 ) {
V_127 = F_107 ( V_5 , V_128 ) ;
if ( F_79 ( V_127 ) ) {
F_95 ( V_5 ) ;
return F_153 ( V_127 ) ;
}
}
V_55 = F_141 ( V_5 , V_171 , 0 ) ;
if ( V_127 ) {
struct V_135 * V_136 = V_127 -> V_158 ;
F_34 ( & V_5 -> V_86 ) ;
F_5 ( & V_94 ) ;
if ( ! V_55 ) {
F_150 ( ! F_100 ( V_5 , V_127 , V_128 ) ) ;
V_127 -> V_188 ++ ;
V_127 -> V_129 = F_100 ;
V_5 -> V_188 ++ ;
V_5 -> V_129 = V_128 ;
}
F_150 ( V_127 -> V_132 != V_128 ) ;
V_127 -> V_132 = NULL ;
F_154 ( & V_127 -> V_132 , 0 ) ;
F_7 ( & V_94 ) ;
if ( ! V_55 && ( V_171 & V_176 ) && ! V_5 -> V_189 &&
( V_136 -> V_66 & V_190 ) ) {
V_5 -> V_189 = true ;
F_143 ( V_136 ) ;
}
F_35 ( & V_5 -> V_86 ) ;
F_95 ( V_127 ) ;
}
return V_55 ;
}
struct V_4 * F_155 ( const char * V_191 , T_7 V_171 ,
void * V_128 )
{
struct V_4 * V_5 ;
int V_102 ;
V_5 = F_156 ( V_191 ) ;
if ( F_79 ( V_5 ) )
return V_5 ;
V_102 = F_152 ( V_5 , V_171 , V_128 ) ;
if ( V_102 )
return F_39 ( V_102 ) ;
if ( ( V_171 & V_176 ) && F_157 ( V_5 ) ) {
F_158 ( V_5 , V_171 ) ;
return F_39 ( - V_192 ) ;
}
return V_5 ;
}
struct V_4 * F_159 ( T_5 V_112 , T_7 V_171 , void * V_128 )
{
struct V_4 * V_5 ;
int V_102 ;
V_5 = F_86 ( V_112 ) ;
if ( ! V_5 )
return F_39 ( - V_141 ) ;
V_102 = F_152 ( V_5 , V_171 , V_128 ) ;
if ( V_102 )
return F_39 ( V_102 ) ;
return V_5 ;
}
static int F_160 ( struct V_2 * V_2 , struct V_50 * V_74 )
{
struct V_4 * V_5 ;
V_74 -> V_193 |= V_194 ;
if ( V_74 -> V_193 & V_195 )
V_74 -> V_196 |= V_197 ;
if ( V_74 -> V_193 & V_198 )
V_74 -> V_196 |= V_187 ;
if ( ( V_74 -> V_193 & V_199 ) == 3 )
V_74 -> V_196 |= V_200 ;
V_5 = F_97 ( V_2 ) ;
if ( V_5 == NULL )
return - V_141 ;
V_74 -> V_52 = V_5 -> V_18 -> V_21 ;
return F_152 ( V_5 , V_74 -> V_196 , V_74 ) ;
}
static int F_151 ( struct V_4 * V_5 , T_7 V_171 , int V_172 )
{
int V_70 = 0 ;
struct V_135 * V_136 = V_5 -> V_158 ;
struct V_4 * V_201 = NULL ;
F_144 ( & V_5 -> V_86 , V_172 ) ;
if ( V_172 )
V_5 -> V_116 -- ;
if ( ! -- V_5 -> V_179 ) {
F_120 ( V_5 -> V_188 ) ;
F_18 ( V_5 ) ;
F_12 ( V_5 ) ;
}
if ( V_5 -> V_115 == V_5 ) {
if ( V_136 -> V_139 -> V_202 )
V_70 = V_136 -> V_139 -> V_202 ( V_136 , V_171 ) ;
}
if ( ! V_5 -> V_179 ) {
struct V_203 * V_140 = V_136 -> V_139 -> V_140 ;
F_112 ( V_136 ) ;
F_111 ( V_140 ) ;
F_146 ( V_5 -> V_147 ) ;
V_5 -> V_147 = NULL ;
V_5 -> V_158 = NULL ;
F_4 ( V_5 -> V_18 ,
& V_124 ) ;
if ( V_5 != V_5 -> V_115 )
V_201 = V_5 -> V_115 ;
V_5 -> V_115 = NULL ;
}
F_35 ( & V_5 -> V_86 ) ;
F_95 ( V_5 ) ;
if ( V_201 )
F_151 ( V_201 , V_171 , 1 ) ;
return V_70 ;
}
int F_158 ( struct V_4 * V_5 , T_7 V_171 )
{
if ( V_171 & V_187 ) {
bool V_204 ;
F_34 ( & V_5 -> V_86 ) ;
F_5 ( & V_94 ) ;
F_120 ( -- V_5 -> V_188 < 0 ) ;
F_120 ( -- V_5 -> V_115 -> V_188 < 0 ) ;
if ( ( V_204 = ! V_5 -> V_188 ) )
V_5 -> V_129 = NULL ;
if ( ! V_5 -> V_115 -> V_188 )
V_5 -> V_115 -> V_129 = NULL ;
F_7 ( & V_94 ) ;
if ( V_204 ) {
if ( V_5 -> V_189 ) {
F_147 ( V_5 -> V_158 ) ;
F_161 ( V_5 -> V_158 ) ;
V_5 -> V_189 = false ;
}
}
F_35 ( & V_5 -> V_86 ) ;
}
return F_151 ( V_5 , V_171 , 0 ) ;
}
static int F_162 ( struct V_2 * V_2 , struct V_50 * V_74 )
{
struct V_4 * V_5 = F_3 ( V_74 -> V_52 -> V_53 ) ;
return F_158 ( V_5 , V_74 -> V_196 ) ;
}
static long F_163 ( struct V_50 * V_50 , unsigned V_205 , unsigned long V_206 )
{
struct V_4 * V_5 = F_3 ( V_50 -> V_52 -> V_53 ) ;
T_7 V_171 = V_50 -> V_196 ;
if ( V_50 -> V_193 & V_195 )
V_171 |= V_197 ;
else
V_171 &= ~ V_197 ;
return F_164 ( V_5 , V_171 , V_205 , V_206 ) ;
}
T_3 F_165 ( struct V_44 * V_45 , const struct V_46 * V_47 ,
unsigned long V_49 , T_2 V_64 )
{
struct V_50 * V_50 = V_45 -> V_51 ;
T_3 V_70 ;
F_150 ( V_45 -> V_207 != V_64 ) ;
V_70 = F_166 ( V_45 , V_47 , V_49 , & V_45 -> V_207 ) ;
if ( V_70 > 0 || V_70 == - V_208 ) {
T_3 V_102 ;
V_102 = F_167 ( V_50 , V_64 , V_70 ) ;
if ( V_102 < 0 && V_70 > 0 )
V_70 = V_102 ;
}
return V_70 ;
}
static int F_168 ( struct V_59 * V_59 , T_8 V_54 )
{
struct V_27 * V_209 = F_1 ( V_59 -> V_63 -> V_53 ) -> V_5 . V_210 ;
if ( V_209 && V_209 -> V_211 -> V_212 )
return V_209 -> V_211 -> V_212 ( V_209 , V_59 , V_54 ) ;
return F_169 ( V_59 ) ;
}
int F_170 ( struct V_4 * V_5 , unsigned V_205 , unsigned long V_206 )
{
int V_55 ;
T_9 V_213 = F_171 () ;
F_172 ( V_214 ) ;
V_55 = F_164 ( V_5 , 0 , V_205 , V_206 ) ;
F_172 ( V_213 ) ;
return V_55 ;
}
struct V_4 * F_156 ( const char * V_215 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_191 V_191 ;
int error ;
if ( ! V_215 || ! * V_215 )
return F_39 ( - V_24 ) ;
error = F_173 ( V_215 , V_216 , & V_191 ) ;
if ( error )
return F_39 ( error ) ;
V_2 = V_191 . V_96 -> V_217 ;
error = - V_218 ;
if ( ! F_174 ( V_2 -> V_118 ) )
goto V_219;
error = - V_192 ;
if ( V_191 . V_220 -> V_221 & V_222 )
goto V_219;
error = - V_141 ;
V_5 = F_97 ( V_2 ) ;
if ( ! V_5 )
goto V_219;
V_58:
F_175 ( & V_191 ) ;
return V_5 ;
V_219:
V_5 = F_39 ( error ) ;
goto V_58;
}
int F_130 ( struct V_4 * V_5 , bool V_155 )
{
struct V_27 * V_28 = F_30 ( V_5 ) ;
int V_55 = 0 ;
if ( V_28 ) {
F_176 ( V_28 ) ;
V_55 = F_177 ( V_28 , V_155 ) ;
F_32 ( V_28 ) ;
}
F_178 ( V_5 ) ;
return V_55 ;
}

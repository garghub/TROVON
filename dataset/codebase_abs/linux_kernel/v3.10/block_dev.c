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
void F_10 ( struct V_4 * V_5 )
{
struct V_17 * V_18 = V_5 -> V_19 -> V_20 ;
if ( V_18 -> V_21 == 0 )
return;
F_11 () ;
F_12 ( V_18 , 0 ) ;
}
void F_13 ( struct V_4 * V_5 )
{
struct V_17 * V_18 = V_5 -> V_19 -> V_20 ;
if ( V_18 -> V_21 == 0 )
return;
F_11 () ;
F_14 () ;
F_15 ( V_18 , 0 , - 1 ) ;
F_16 ( V_18 ) ;
}
int F_17 ( struct V_4 * V_5 , int V_22 )
{
if ( V_22 > V_23 || V_22 < 512 || ! F_18 ( V_22 ) )
return - V_24 ;
if ( V_22 < F_19 ( V_5 ) )
return - V_24 ;
if ( V_5 -> V_25 != V_22 ) {
F_20 ( V_5 ) ;
V_5 -> V_25 = V_22 ;
V_5 -> V_19 -> V_26 = F_21 ( V_22 ) ;
F_10 ( V_5 ) ;
}
return 0 ;
}
int F_22 ( struct V_27 * V_28 , int V_22 )
{
if ( F_17 ( V_28 -> V_29 , V_22 ) )
return 0 ;
V_28 -> V_30 = V_22 ;
V_28 -> V_31 = F_21 ( V_22 ) ;
return V_28 -> V_30 ;
}
int F_23 ( struct V_27 * V_28 , int V_22 )
{
int V_32 = F_19 ( V_28 -> V_29 ) ;
if ( V_22 < V_32 )
V_22 = V_32 ;
return F_22 ( V_28 , V_22 ) ;
}
static int
F_24 ( struct V_2 * V_2 , T_1 V_33 ,
struct V_34 * V_35 , int V_36 )
{
V_35 -> V_37 = F_3 ( V_2 ) ;
V_35 -> V_38 = V_33 ;
F_25 ( V_35 ) ;
return 0 ;
}
static T_2
F_26 ( int V_39 , struct V_40 * V_41 , const struct V_42 * V_43 ,
T_3 V_44 , unsigned long V_45 )
{
struct V_46 * V_46 = V_41 -> V_47 ;
struct V_2 * V_2 = V_46 -> V_48 -> V_49 ;
return F_27 ( V_39 , V_41 , V_2 , F_3 ( V_2 ) , V_43 , V_44 ,
V_45 , F_24 , NULL , NULL , 0 ) ;
}
int F_28 ( struct V_4 * V_5 , int V_50 )
{
if ( ! V_5 )
return 0 ;
if ( ! V_50 )
return F_29 ( V_5 -> V_19 -> V_20 ) ;
return F_30 ( V_5 -> V_19 -> V_20 ) ;
}
int F_20 ( struct V_4 * V_5 )
{
return F_28 ( V_5 , 1 ) ;
}
int F_31 ( struct V_4 * V_5 )
{
struct V_27 * V_28 = F_32 ( V_5 ) ;
if ( V_28 ) {
int V_51 = F_33 ( V_28 ) ;
F_34 ( V_28 ) ;
return V_51 ;
}
return F_20 ( V_5 ) ;
}
struct V_27 * F_35 ( struct V_4 * V_5 )
{
struct V_27 * V_28 ;
int error = 0 ;
F_36 ( & V_5 -> V_52 ) ;
if ( ++ V_5 -> V_53 > 1 ) {
V_28 = F_32 ( V_5 ) ;
F_34 ( V_28 ) ;
F_37 ( & V_5 -> V_52 ) ;
return V_28 ;
}
V_28 = F_38 ( V_5 ) ;
if ( ! V_28 )
goto V_54;
error = F_39 ( V_28 ) ;
if ( error ) {
F_40 ( V_28 ) ;
V_5 -> V_53 -- ;
F_37 ( & V_5 -> V_52 ) ;
return F_41 ( error ) ;
}
F_40 ( V_28 ) ;
V_54:
F_20 ( V_5 ) ;
F_37 ( & V_5 -> V_52 ) ;
return V_28 ;
}
int F_42 ( struct V_4 * V_5 , struct V_27 * V_28 )
{
int error = - V_24 ;
F_36 ( & V_5 -> V_52 ) ;
if ( ! V_5 -> V_53 )
goto V_54;
error = 0 ;
if ( -- V_5 -> V_53 > 0 )
goto V_54;
if ( ! V_28 )
goto V_54;
error = F_43 ( V_28 ) ;
if ( error ) {
V_5 -> V_53 ++ ;
F_37 ( & V_5 -> V_52 ) ;
return error ;
}
V_54:
F_37 ( & V_5 -> V_52 ) ;
return 0 ;
}
static int F_44 ( struct V_55 * V_55 , struct V_56 * V_57 )
{
return F_45 ( V_55 , F_24 , V_57 ) ;
}
static int F_46 ( struct V_46 * V_46 , struct V_55 * V_55 )
{
return F_47 ( V_55 , F_24 ) ;
}
static int F_48 ( struct V_46 * V_46 , struct V_17 * V_18 ,
T_3 V_58 , unsigned V_59 , unsigned V_60 ,
struct V_55 * * V_61 , void * * V_62 )
{
return F_49 ( V_18 , V_58 , V_59 , V_60 , V_61 ,
F_24 ) ;
}
static int F_50 ( struct V_46 * V_46 , struct V_17 * V_18 ,
T_3 V_58 , unsigned V_59 , unsigned V_63 ,
struct V_55 * V_55 , void * V_62 )
{
int V_64 ;
V_64 = F_51 ( V_46 , V_18 , V_58 , V_59 , V_63 , V_55 , V_62 ) ;
F_52 ( V_55 ) ;
F_53 ( V_55 ) ;
return V_64 ;
}
static T_3 F_54 ( struct V_46 * V_46 , T_3 V_44 , int V_65 )
{
struct V_2 * V_19 = V_46 -> V_48 -> V_49 ;
T_3 V_22 ;
T_3 V_66 ;
F_36 ( & V_19 -> V_67 ) ;
V_22 = F_55 ( V_19 ) ;
V_66 = - V_24 ;
switch ( V_65 ) {
case V_68 :
V_44 += V_22 ;
break;
case V_69 :
V_44 += V_46 -> V_70 ;
case V_71 :
break;
default:
goto V_54;
}
if ( V_44 >= 0 && V_44 <= V_22 ) {
if ( V_44 != V_46 -> V_70 ) {
V_46 -> V_70 = V_44 ;
}
V_66 = V_44 ;
}
V_54:
F_37 ( & V_19 -> V_67 ) ;
return V_66 ;
}
int F_56 ( struct V_46 * V_72 , T_3 V_73 , T_3 V_74 , int V_75 )
{
struct V_2 * V_19 = V_72 -> V_48 -> V_49 ;
struct V_4 * V_5 = F_3 ( V_19 ) ;
int error ;
error = F_57 ( V_72 -> V_48 , V_73 , V_74 ) ;
if ( error )
return error ;
error = F_58 ( V_5 , V_76 , NULL ) ;
if ( error == - V_77 )
error = 0 ;
return error ;
}
static struct V_2 * F_59 ( struct V_27 * V_28 )
{
struct V_1 * V_78 = F_60 ( V_79 , V_76 ) ;
if ( ! V_78 )
return NULL ;
return & V_78 -> V_3 ;
}
static void F_61 ( struct V_80 * V_81 )
{
struct V_2 * V_2 = F_2 ( V_81 , struct V_2 , V_82 ) ;
struct V_1 * V_83 = F_1 ( V_2 ) ;
F_62 ( V_79 , V_83 ) ;
}
static void F_63 ( struct V_2 * V_2 )
{
F_64 ( & V_2 -> V_82 , F_61 ) ;
}
static void F_65 ( void * V_84 )
{
struct V_1 * V_78 = (struct V_1 * ) V_84 ;
struct V_4 * V_5 = & V_78 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_66 ( & V_5 -> V_85 ) ;
F_67 ( & V_5 -> V_86 ) ;
F_67 ( & V_5 -> V_87 ) ;
#ifdef F_68
F_67 ( & V_5 -> V_88 ) ;
#endif
F_69 ( & V_78 -> V_3 ) ;
F_66 ( & V_5 -> V_52 ) ;
}
static inline void F_70 ( struct V_2 * V_2 )
{
F_71 ( & V_2 -> V_89 ) ;
V_2 -> V_90 = NULL ;
V_2 -> V_20 = & V_2 -> V_9 ;
}
static void F_72 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
struct V_91 * V_92 ;
F_12 ( & V_2 -> V_9 , 0 ) ;
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
F_7 ( & V_93 ) ;
while ( ( V_92 = V_5 -> V_86 . V_94 ) != & V_5 -> V_86 ) {
F_70 ( F_75 ( V_92 , struct V_2 , V_89 ) ) ;
}
F_71 ( & V_5 -> V_87 ) ;
F_9 ( & V_93 ) ;
}
static struct V_95 * F_76 ( struct V_96 * V_97 ,
int V_60 , const char * V_98 , void * V_99 )
{
return F_77 ( V_97 , L_1 , & V_100 , NULL , V_101 ) ;
}
void T_4 F_78 ( void )
{
int V_102 ;
static struct V_103 * V_104 ;
V_79 = F_79 ( L_2 , sizeof( struct V_1 ) ,
0 , ( V_105 | V_106 |
V_107 | V_108 ) ,
F_65 ) ;
V_102 = F_80 ( & V_109 ) ;
if ( V_102 )
F_81 ( L_3 ) ;
V_104 = F_82 ( & V_109 ) ;
if ( F_83 ( V_104 ) )
F_81 ( L_4 ) ;
V_110 = V_104 -> V_111 ;
}
static inline unsigned long F_84 ( T_5 V_112 )
{
return F_85 ( V_112 ) + F_86 ( V_112 ) ;
}
static int F_87 ( struct V_2 * V_2 , void * V_99 )
{
return F_1 ( V_2 ) -> V_5 . V_113 == * ( T_5 * ) V_99 ;
}
static int F_88 ( struct V_2 * V_2 , void * V_99 )
{
F_1 ( V_2 ) -> V_5 . V_113 = * ( T_5 * ) V_99 ;
return 0 ;
}
struct V_4 * F_89 ( T_5 V_112 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_90 ( V_110 , F_84 ( V_112 ) ,
F_87 , F_88 , & V_112 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_12 & V_114 ) {
V_5 -> V_115 = NULL ;
V_5 -> V_116 = NULL ;
V_5 -> V_19 = V_2 ;
V_5 -> V_25 = ( 1 << V_2 -> V_26 ) ;
V_5 -> V_117 = 0 ;
V_5 -> V_118 = 0 ;
V_2 -> V_119 = V_120 ;
V_2 -> V_121 = V_112 ;
V_2 -> V_90 = V_5 ;
V_2 -> V_9 . V_122 = & V_123 ;
F_91 ( & V_2 -> V_9 , V_124 ) ;
V_2 -> V_9 . V_6 = & V_125 ;
F_7 ( & V_93 ) ;
F_92 ( & V_5 -> V_87 , & V_126 ) ;
F_9 ( & V_93 ) ;
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
long V_64 = 0 ;
F_7 ( & V_93 ) ;
F_97 (bdev, &all_bdevs, bd_list) {
V_64 += V_5 -> V_19 -> V_20 -> V_21 ;
}
F_9 ( & V_93 ) ;
return V_64 ;
}
void F_98 ( struct V_4 * V_5 )
{
F_99 ( V_5 -> V_19 ) ;
}
static struct V_4 * F_100 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_7 ( & V_93 ) ;
V_5 = V_2 -> V_90 ;
if ( V_5 ) {
F_95 ( V_5 -> V_19 ) ;
F_9 ( & V_93 ) ;
return V_5 ;
}
F_9 ( & V_93 ) ;
V_5 = F_89 ( V_2 -> V_121 ) ;
if ( V_5 ) {
F_7 ( & V_93 ) ;
if ( ! V_2 -> V_90 ) {
F_95 ( V_5 -> V_19 ) ;
V_2 -> V_90 = V_5 ;
V_2 -> V_20 = V_5 -> V_19 -> V_20 ;
F_92 ( & V_2 -> V_89 , & V_5 -> V_86 ) ;
}
F_9 ( & V_93 ) ;
}
return V_5 ;
}
static inline int F_101 ( struct V_27 * V_28 )
{
return V_28 == V_110 ;
}
void F_102 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_7 ( & V_93 ) ;
if ( ! F_101 ( V_2 -> V_127 ) )
V_5 = V_2 -> V_90 ;
F_70 ( V_2 ) ;
F_9 ( & V_93 ) ;
if ( V_5 )
F_99 ( V_5 -> V_19 ) ;
}
static bool F_103 ( struct V_4 * V_5 , struct V_4 * V_128 ,
void * V_129 )
{
if ( V_5 -> V_130 == V_129 )
return true ;
else if ( V_5 -> V_130 != NULL )
return false ;
else if ( V_5 -> V_115 == V_5 )
return true ;
else if ( V_128 -> V_130 == F_103 )
return true ;
else if ( V_128 -> V_130 != NULL )
return false ;
else
return true ;
}
static int F_104 ( struct V_4 * V_5 ,
struct V_4 * V_128 , void * V_129 )
{
V_131:
if ( ! F_103 ( V_5 , V_128 , V_129 ) )
return - V_132 ;
if ( V_128 -> V_133 ) {
T_6 * V_134 = F_105 ( & V_128 -> V_133 , 0 ) ;
F_106 ( V_50 ) ;
F_107 ( V_134 , & V_50 , V_135 ) ;
F_9 ( & V_93 ) ;
F_108 () ;
F_109 ( V_134 , & V_50 ) ;
F_7 ( & V_93 ) ;
goto V_131;
}
return 0 ;
}
static struct V_4 * F_110 ( struct V_4 * V_5 ,
void * V_129 )
{
struct V_136 * V_137 ;
struct V_4 * V_128 ;
int V_138 , V_102 ;
F_111 () ;
V_137 = F_112 ( V_5 -> V_113 , & V_138 ) ;
if ( ! V_137 )
return F_41 ( - V_139 ) ;
if ( V_138 )
V_128 = F_113 ( V_137 , 0 ) ;
else
V_128 = F_94 ( V_5 ) ;
F_114 ( V_137 -> V_140 -> V_141 ) ;
F_115 ( V_137 ) ;
if ( ! V_128 )
return F_41 ( - V_142 ) ;
F_7 ( & V_93 ) ;
V_102 = F_104 ( V_5 , V_128 , V_129 ) ;
if ( V_102 == 0 ) {
V_128 -> V_133 = V_129 ;
F_9 ( & V_93 ) ;
return V_128 ;
} else {
F_9 ( & V_93 ) ;
F_98 ( V_128 ) ;
return F_41 ( V_102 ) ;
}
}
static struct V_143 * F_116 ( struct V_4 * V_5 ,
struct V_136 * V_137 )
{
struct V_143 * V_129 ;
F_97 (holder, &bdev->bd_holder_disks, list)
if ( V_129 -> V_137 == V_137 )
return V_129 ;
return NULL ;
}
static int F_117 ( struct V_144 * V_145 , struct V_144 * V_146 )
{
return F_118 ( V_145 , V_146 , F_119 ( V_146 ) ) ;
}
static void F_120 ( struct V_144 * V_145 , struct V_144 * V_146 )
{
F_121 ( V_145 , F_119 ( V_146 ) ) ;
}
int F_122 ( struct V_4 * V_5 , struct V_136 * V_137 )
{
struct V_143 * V_129 ;
int V_64 = 0 ;
F_36 ( & V_5 -> V_85 ) ;
F_123 ( ! V_5 -> V_130 ) ;
if ( F_124 ( ! V_137 -> V_147 || ! V_5 -> V_148 -> V_149 ) )
goto V_150;
V_129 = F_116 ( V_5 , V_137 ) ;
if ( V_129 ) {
V_129 -> V_151 ++ ;
goto V_150;
}
V_129 = F_125 ( sizeof( * V_129 ) , V_76 ) ;
if ( ! V_129 ) {
V_64 = - V_142 ;
goto V_150;
}
F_67 ( & V_129 -> V_152 ) ;
V_129 -> V_137 = V_137 ;
V_129 -> V_151 = 1 ;
V_64 = F_117 ( V_137 -> V_147 , & F_126 ( V_5 -> V_148 ) -> V_153 ) ;
if ( V_64 )
goto V_154;
V_64 = F_117 ( V_5 -> V_148 -> V_149 , & F_127 ( V_137 ) -> V_153 ) ;
if ( V_64 )
goto V_155;
F_128 ( V_5 -> V_148 -> V_149 ) ;
F_92 ( & V_129 -> V_152 , & V_5 -> V_88 ) ;
goto V_150;
V_155:
F_120 ( V_137 -> V_147 , & F_126 ( V_5 -> V_148 ) -> V_153 ) ;
V_154:
F_129 ( V_129 ) ;
V_150:
F_37 ( & V_5 -> V_85 ) ;
return V_64 ;
}
void F_130 ( struct V_4 * V_5 , struct V_136 * V_137 )
{
struct V_143 * V_129 ;
F_36 ( & V_5 -> V_85 ) ;
V_129 = F_116 ( V_5 , V_137 ) ;
if ( ! F_123 ( V_129 == NULL ) && ! -- V_129 -> V_151 ) {
F_120 ( V_137 -> V_147 , & F_126 ( V_5 -> V_148 ) -> V_153 ) ;
F_120 ( V_5 -> V_148 -> V_149 ,
& F_127 ( V_137 ) -> V_153 ) ;
F_131 ( V_5 -> V_148 -> V_149 ) ;
F_71 ( & V_129 -> V_152 ) ;
F_129 ( V_129 ) ;
}
F_37 ( & V_5 -> V_85 ) ;
}
static void F_132 ( struct V_4 * V_5 , bool V_156 )
{
if ( F_133 ( V_5 , V_156 ) ) {
char V_157 [ V_158 ] = L_5 ;
if ( V_5 -> V_159 )
F_134 ( V_5 -> V_159 , 0 , V_157 ) ;
F_135 ( V_160 L_6
L_7 , V_157 ) ;
}
if ( ! V_5 -> V_159 )
return;
if ( F_136 ( V_5 -> V_159 ) )
V_5 -> V_118 = 1 ;
}
void F_137 ( struct V_136 * V_137 , struct V_4 * V_5 )
{
T_3 V_161 , V_162 ;
V_161 = ( T_3 ) F_138 ( V_137 ) << 9 ;
V_162 = F_55 ( V_5 -> V_19 ) ;
if ( V_161 != V_162 ) {
char V_157 [ V_158 ] ;
F_134 ( V_137 , 0 , V_157 ) ;
F_135 ( V_163
L_8 ,
V_157 , V_162 , V_161 ) ;
F_139 ( V_5 -> V_19 , V_161 ) ;
F_132 ( V_5 , false ) ;
}
}
int F_140 ( struct V_136 * V_137 )
{
struct V_4 * V_5 ;
int V_64 = 0 ;
if ( V_137 -> V_140 -> F_140 )
V_64 = V_137 -> V_140 -> F_140 ( V_137 ) ;
V_5 = F_113 ( V_137 , 0 ) ;
if ( ! V_5 )
return V_64 ;
F_36 ( & V_5 -> V_85 ) ;
F_137 ( V_137 , V_5 ) ;
V_5 -> V_118 = 0 ;
F_37 ( & V_5 -> V_85 ) ;
F_98 ( V_5 ) ;
return V_64 ;
}
int F_141 ( struct V_4 * V_5 )
{
struct V_136 * V_137 = V_5 -> V_159 ;
const struct V_164 * V_165 = V_137 -> V_140 ;
unsigned int V_166 ;
V_166 = F_142 ( V_137 , V_167 |
V_168 ) ;
if ( ! ( V_166 & V_167 ) )
return 0 ;
F_132 ( V_5 , true ) ;
if ( V_165 -> F_140 )
V_165 -> F_140 ( V_5 -> V_159 ) ;
return 1 ;
}
void F_143 ( struct V_4 * V_5 , T_3 V_22 )
{
unsigned V_169 = F_19 ( V_5 ) ;
F_36 ( & V_5 -> V_19 -> V_67 ) ;
F_139 ( V_5 -> V_19 , V_22 ) ;
F_37 ( & V_5 -> V_19 -> V_67 ) ;
while ( V_169 < V_170 ) {
if ( V_22 & V_169 )
break;
V_169 <<= 1 ;
}
V_5 -> V_25 = V_169 ;
V_5 -> V_19 -> V_26 = F_21 ( V_169 ) ;
}
static int F_144 ( struct V_4 * V_5 , T_7 V_171 , int V_172 )
{
struct V_136 * V_137 ;
struct V_173 * V_141 ;
int V_64 ;
int V_138 ;
int V_174 = 0 ;
if ( V_171 & V_175 )
V_174 |= V_176 ;
if ( V_171 & V_177 )
V_174 |= V_178 ;
if ( ! V_172 ) {
V_64 = F_145 ( V_5 -> V_19 , V_174 ) ;
if ( V_64 != 0 ) {
F_98 ( V_5 ) ;
return V_64 ;
}
}
V_179:
V_64 = - V_139 ;
V_137 = F_112 ( V_5 -> V_113 , & V_138 ) ;
if ( ! V_137 )
goto V_54;
V_141 = V_137 -> V_140 -> V_141 ;
F_146 ( V_137 ) ;
F_147 ( & V_5 -> V_85 , V_172 ) ;
if ( ! V_5 -> V_180 ) {
V_5 -> V_159 = V_137 ;
V_5 -> V_181 = V_137 -> V_182 ;
V_5 -> V_115 = V_5 ;
if ( ! V_138 ) {
struct V_6 * V_83 ;
V_64 = - V_139 ;
V_5 -> V_148 = F_148 ( V_137 , V_138 ) ;
if ( ! V_5 -> V_148 )
goto V_183;
V_64 = 0 ;
if ( V_137 -> V_140 -> V_184 ) {
V_64 = V_137 -> V_140 -> V_184 ( V_5 , V_171 ) ;
if ( V_64 == - V_185 ) {
F_149 ( V_5 -> V_148 ) ;
V_5 -> V_148 = NULL ;
V_5 -> V_159 = NULL ;
V_5 -> V_181 = NULL ;
F_37 ( & V_5 -> V_85 ) ;
F_150 ( V_137 ) ;
F_115 ( V_137 ) ;
F_114 ( V_141 ) ;
goto V_179;
}
}
if ( ! V_64 ) {
F_143 ( V_5 , ( T_3 ) F_138 ( V_137 ) << 9 ) ;
V_83 = F_151 ( V_5 ) ;
if ( V_83 == NULL )
V_83 = & V_125 ;
F_4 ( V_5 -> V_19 , V_83 ) ;
}
if ( V_5 -> V_118 ) {
if ( ! V_64 )
F_152 ( V_137 , V_5 ) ;
else if ( V_64 == - V_186 )
F_153 ( V_137 , V_5 ) ;
}
if ( V_64 )
goto V_183;
} else {
struct V_4 * V_128 ;
V_128 = F_113 ( V_137 , 0 ) ;
V_64 = - V_142 ;
if ( ! V_128 )
goto V_183;
F_154 ( V_172 ) ;
V_64 = F_144 ( V_128 , V_171 , 1 ) ;
if ( V_64 )
goto V_183;
V_5 -> V_115 = V_128 ;
F_4 ( V_5 -> V_19 ,
V_128 -> V_19 -> V_9 . V_6 ) ;
V_5 -> V_148 = F_148 ( V_137 , V_138 ) ;
if ( ! ( V_137 -> V_60 & V_187 ) ||
! V_5 -> V_148 || ! V_5 -> V_148 -> V_188 ) {
V_64 = - V_139 ;
goto V_183;
}
F_143 ( V_5 , ( T_3 ) V_5 -> V_148 -> V_188 << 9 ) ;
}
} else {
if ( V_5 -> V_115 == V_5 ) {
V_64 = 0 ;
if ( V_5 -> V_159 -> V_140 -> V_184 )
V_64 = V_5 -> V_159 -> V_140 -> V_184 ( V_5 , V_171 ) ;
if ( V_5 -> V_118 ) {
if ( ! V_64 )
F_152 ( V_5 -> V_159 , V_5 ) ;
else if ( V_64 == - V_186 )
F_153 ( V_5 -> V_159 , V_5 ) ;
}
if ( V_64 )
goto V_189;
}
F_115 ( V_137 ) ;
F_114 ( V_141 ) ;
}
V_5 -> V_180 ++ ;
if ( V_172 )
V_5 -> V_117 ++ ;
F_37 ( & V_5 -> V_85 ) ;
F_150 ( V_137 ) ;
return 0 ;
V_183:
F_149 ( V_5 -> V_148 ) ;
V_5 -> V_159 = NULL ;
V_5 -> V_148 = NULL ;
V_5 -> V_181 = NULL ;
F_4 ( V_5 -> V_19 , & V_125 ) ;
if ( V_5 != V_5 -> V_115 )
F_155 ( V_5 -> V_115 , V_171 , 1 ) ;
V_5 -> V_115 = NULL ;
V_189:
F_37 ( & V_5 -> V_85 ) ;
F_150 ( V_137 ) ;
F_115 ( V_137 ) ;
F_114 ( V_141 ) ;
V_54:
F_98 ( V_5 ) ;
return V_64 ;
}
int F_156 ( struct V_4 * V_5 , T_7 V_171 , void * V_129 )
{
struct V_4 * V_128 = NULL ;
int V_51 ;
F_123 ( ( V_171 & V_190 ) && ! V_129 ) ;
if ( ( V_171 & V_190 ) && V_129 ) {
V_128 = F_110 ( V_5 , V_129 ) ;
if ( F_83 ( V_128 ) ) {
F_98 ( V_5 ) ;
return F_157 ( V_128 ) ;
}
}
V_51 = F_144 ( V_5 , V_171 , 0 ) ;
if ( V_128 ) {
struct V_136 * V_137 = V_128 -> V_159 ;
F_36 ( & V_5 -> V_85 ) ;
F_7 ( & V_93 ) ;
if ( ! V_51 ) {
F_154 ( ! F_103 ( V_5 , V_128 , V_129 ) ) ;
V_128 -> V_191 ++ ;
V_128 -> V_130 = F_103 ;
V_5 -> V_191 ++ ;
V_5 -> V_130 = V_129 ;
}
F_154 ( V_128 -> V_133 != V_129 ) ;
V_128 -> V_133 = NULL ;
F_158 ( & V_128 -> V_133 , 0 ) ;
F_9 ( & V_93 ) ;
if ( ! V_51 && ( V_171 & V_177 ) && ! V_5 -> V_192 &&
( V_137 -> V_60 & V_193 ) ) {
V_5 -> V_192 = true ;
F_146 ( V_137 ) ;
}
F_37 ( & V_5 -> V_85 ) ;
F_98 ( V_128 ) ;
}
return V_51 ;
}
struct V_4 * F_159 ( const char * V_194 , T_7 V_171 ,
void * V_129 )
{
struct V_4 * V_5 ;
int V_102 ;
V_5 = F_160 ( V_194 ) ;
if ( F_83 ( V_5 ) )
return V_5 ;
V_102 = F_156 ( V_5 , V_171 , V_129 ) ;
if ( V_102 )
return F_41 ( V_102 ) ;
if ( ( V_171 & V_177 ) && F_161 ( V_5 ) ) {
F_162 ( V_5 , V_171 ) ;
return F_41 ( - V_195 ) ;
}
return V_5 ;
}
struct V_4 * F_163 ( T_5 V_112 , T_7 V_171 , void * V_129 )
{
struct V_4 * V_5 ;
int V_102 ;
V_5 = F_89 ( V_112 ) ;
if ( ! V_5 )
return F_41 ( - V_142 ) ;
V_102 = F_156 ( V_5 , V_171 , V_129 ) ;
if ( V_102 )
return F_41 ( V_102 ) ;
return V_5 ;
}
static int F_164 ( struct V_2 * V_2 , struct V_46 * V_72 )
{
struct V_4 * V_5 ;
V_72 -> V_196 |= V_197 ;
if ( V_72 -> V_196 & V_198 )
V_72 -> V_199 |= V_200 ;
if ( V_72 -> V_196 & V_201 )
V_72 -> V_199 |= V_190 ;
if ( ( V_72 -> V_196 & V_202 ) == 3 )
V_72 -> V_199 |= V_203 ;
V_5 = F_100 ( V_2 ) ;
if ( V_5 == NULL )
return - V_142 ;
V_72 -> V_48 = V_5 -> V_19 -> V_20 ;
return F_156 ( V_5 , V_72 -> V_199 , V_72 ) ;
}
static void F_155 ( struct V_4 * V_5 , T_7 V_171 , int V_172 )
{
struct V_136 * V_137 = V_5 -> V_159 ;
struct V_4 * V_204 = NULL ;
F_147 ( & V_5 -> V_85 , V_172 ) ;
if ( V_172 )
V_5 -> V_117 -- ;
if ( ! -- V_5 -> V_180 ) {
F_123 ( V_5 -> V_191 ) ;
F_20 ( V_5 ) ;
F_10 ( V_5 ) ;
F_4 ( V_5 -> V_19 ,
& V_125 ) ;
}
if ( V_5 -> V_115 == V_5 ) {
if ( V_137 -> V_140 -> V_205 )
V_137 -> V_140 -> V_205 ( V_137 , V_171 ) ;
}
if ( ! V_5 -> V_180 ) {
struct V_173 * V_141 = V_137 -> V_140 -> V_141 ;
F_149 ( V_5 -> V_148 ) ;
V_5 -> V_148 = NULL ;
V_5 -> V_159 = NULL ;
if ( V_5 != V_5 -> V_115 )
V_204 = V_5 -> V_115 ;
V_5 -> V_115 = NULL ;
F_115 ( V_137 ) ;
F_114 ( V_141 ) ;
}
F_37 ( & V_5 -> V_85 ) ;
F_98 ( V_5 ) ;
if ( V_204 )
F_155 ( V_204 , V_171 , 1 ) ;
}
void F_162 ( struct V_4 * V_5 , T_7 V_171 )
{
F_36 ( & V_5 -> V_85 ) ;
if ( V_171 & V_190 ) {
bool V_206 ;
F_7 ( & V_93 ) ;
F_123 ( -- V_5 -> V_191 < 0 ) ;
F_123 ( -- V_5 -> V_115 -> V_191 < 0 ) ;
if ( ( V_206 = ! V_5 -> V_191 ) )
V_5 -> V_130 = NULL ;
if ( ! V_5 -> V_115 -> V_191 )
V_5 -> V_115 -> V_130 = NULL ;
F_9 ( & V_93 ) ;
if ( V_206 && V_5 -> V_192 ) {
F_150 ( V_5 -> V_159 ) ;
V_5 -> V_192 = false ;
}
}
F_165 ( V_5 -> V_159 , V_167 ) ;
F_37 ( & V_5 -> V_85 ) ;
F_155 ( V_5 , V_171 , 0 ) ;
}
static int F_166 ( struct V_2 * V_2 , struct V_46 * V_72 )
{
struct V_4 * V_5 = F_3 ( V_72 -> V_48 -> V_49 ) ;
F_162 ( V_5 , V_72 -> V_199 ) ;
return 0 ;
}
static long F_167 ( struct V_46 * V_46 , unsigned V_207 , unsigned long V_208 )
{
struct V_4 * V_5 = F_3 ( V_46 -> V_48 -> V_49 ) ;
T_7 V_171 = V_46 -> V_199 ;
if ( V_46 -> V_196 & V_198 )
V_171 |= V_200 ;
else
V_171 &= ~ V_200 ;
return F_168 ( V_5 , V_171 , V_207 , V_208 ) ;
}
T_2 F_169 ( struct V_40 * V_41 , const struct V_42 * V_43 ,
unsigned long V_45 , T_3 V_58 )
{
struct V_46 * V_46 = V_41 -> V_47 ;
struct V_209 V_210 ;
T_2 V_64 ;
F_154 ( V_41 -> V_211 != V_58 ) ;
F_170 ( & V_210 ) ;
V_64 = F_171 ( V_41 , V_43 , V_45 , & V_41 -> V_211 ) ;
if ( V_64 > 0 || V_64 == - V_212 ) {
T_2 V_102 ;
V_102 = F_172 ( V_46 , V_58 , V_64 ) ;
if ( V_102 < 0 && V_64 > 0 )
V_64 = V_102 ;
}
F_173 ( & V_210 ) ;
return V_64 ;
}
static T_2 F_174 ( struct V_40 * V_41 , const struct V_42 * V_43 ,
unsigned long V_45 , T_3 V_58 )
{
struct V_46 * V_46 = V_41 -> V_47 ;
struct V_2 * V_19 = V_46 -> V_48 -> V_49 ;
T_3 V_22 = F_55 ( V_19 ) ;
if ( V_58 >= V_22 )
return 0 ;
V_22 -= V_58 ;
if ( V_22 < V_41 -> V_213 )
V_45 = F_175 ( (struct V_42 * ) V_43 , V_45 , V_22 ) ;
return F_176 ( V_41 , V_43 , V_45 , V_58 ) ;
}
static int F_177 ( struct V_55 * V_55 , T_8 V_50 )
{
struct V_27 * V_214 = F_1 ( V_55 -> V_18 -> V_49 ) -> V_5 . V_116 ;
if ( V_214 && V_214 -> V_215 -> V_216 )
return V_214 -> V_215 -> V_216 ( V_214 , V_55 , V_50 ) ;
return F_178 ( V_55 ) ;
}
int F_179 ( struct V_4 * V_5 , unsigned V_207 , unsigned long V_208 )
{
int V_51 ;
T_9 V_217 = F_180 () ;
F_181 ( V_218 ) ;
V_51 = F_168 ( V_5 , 0 , V_207 , V_208 ) ;
F_181 ( V_217 ) ;
return V_51 ;
}
struct V_4 * F_160 ( const char * V_219 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_194 V_194 ;
int error ;
if ( ! V_219 || ! * V_219 )
return F_41 ( - V_24 ) ;
error = F_182 ( V_219 , V_220 , & V_194 ) ;
if ( error )
return F_41 ( error ) ;
V_2 = V_194 . V_95 -> V_221 ;
error = - V_222 ;
if ( ! F_183 ( V_2 -> V_119 ) )
goto V_223;
error = - V_195 ;
if ( V_194 . V_224 -> V_225 & V_226 )
goto V_223;
error = - V_142 ;
V_5 = F_100 ( V_2 ) ;
if ( ! V_5 )
goto V_223;
V_54:
F_184 ( & V_194 ) ;
return V_5 ;
V_223:
V_5 = F_41 ( error ) ;
goto V_54;
}
int F_133 ( struct V_4 * V_5 , bool V_156 )
{
struct V_27 * V_28 = F_32 ( V_5 ) ;
int V_51 = 0 ;
if ( V_28 ) {
F_185 ( V_28 ) ;
V_51 = F_186 ( V_28 , V_156 ) ;
F_34 ( V_28 ) ;
}
F_13 ( V_5 ) ;
return V_51 ;
}
void F_187 ( void (* F_188)( struct V_4 * , void * ) , void * V_208 )
{
struct V_2 * V_2 , * V_227 = NULL ;
F_7 ( & V_228 ) ;
F_97 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_17 * V_18 = V_2 -> V_20 ;
F_7 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_12 & ( V_229 | V_230 | V_114 ) ||
V_18 -> V_21 == 0 ) {
F_9 ( & V_2 -> V_11 ) ;
continue;
}
F_189 ( V_2 ) ;
F_9 ( & V_2 -> V_11 ) ;
F_9 ( & V_228 ) ;
F_99 ( V_227 ) ;
V_227 = V_2 ;
F_188 ( F_3 ( V_2 ) , V_208 ) ;
F_7 ( & V_228 ) ;
}
F_9 ( & V_228 ) ;
F_99 ( V_227 ) ;
}

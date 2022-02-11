int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
return F_2 ( & F_3 ( V_2 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_16 ) {
V_14 -> V_15 . V_17 |= V_18 ;
F_6 ( & F_3 ( V_2 ) , & V_14 -> V_15 ) ;
F_7 ( V_14 ) ;
} else
F_8 ( V_2 , V_14 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 , & F_3 ( V_2 ) , F_4 ) ;
F_11 ( & V_2 -> V_19 [ V_20 ] . V_21 ) ;
F_12 ( & V_2 -> V_19 [ V_20 ] . V_22 ) ;
}
static int T_1 F_13 ( void )
{
const int V_23 = F_1 ( & V_24 ) ;
F_14 ( V_23 , L_1 , V_23 ) ;
return V_23 ;
}
void T_1 F_15 ( void )
{
F_16 ( L_2 ,
#if V_25 <= 32
L_3 ,
#else
L_4 ,
#endif
V_20 , V_26 ) ;
}
static inline struct V_13 * F_17 ( struct V_1 * V_2 , int V_27 )
{
struct V_11 * V_12 = F_18 ( & F_3 ( V_2 ) , V_27 ) ;
if ( F_19 ( V_12 ) )
return F_20 ( V_12 ) ;
return F_5 ( V_12 , struct V_13 , V_15 ) ;
}
static inline struct V_13 * F_21 ( struct V_1 * V_2 , int V_27 )
{
struct V_11 * V_12 = F_22 ( & F_3 ( V_2 ) , V_27 ) ;
if ( F_19 ( V_12 ) )
return F_20 ( V_12 ) ;
return F_5 ( V_12 , struct V_13 , V_15 ) ;
}
static inline struct V_13 * F_23 ( struct V_1 * V_2 , int V_27 )
{
struct V_11 * V_12 = F_24 ( & F_3 ( V_2 ) , V_27 ) ;
if ( F_19 ( V_12 ) )
return ( void * ) V_12 ;
return F_5 ( V_12 , struct V_13 , V_15 ) ;
}
static inline void F_25 ( struct V_13 * V_12 )
{
F_26 () ;
F_27 ( & V_12 -> V_15 ) ;
}
static void F_28 ( struct V_28 * V_29 )
{
struct V_11 * V_30 = F_5 ( V_29 , struct V_11 ,
V_31 ) ;
struct V_13 * V_14 = F_5 ( V_30 , struct V_13 ,
V_15 ) ;
F_29 ( V_14 ) ;
F_30 ( V_14 ) ;
}
static inline void F_31 ( struct V_1 * V_2 , struct V_13 * V_32 )
{
F_32 ( & V_32 -> V_33 ) ;
F_33 ( & F_3 ( V_2 ) , & V_32 -> V_15 ) ;
}
static int F_34 ( struct V_34 * V_35 )
{
struct V_36 * V_36 = V_35 -> V_37 ;
struct V_38 * V_39 = V_38 ( V_36 ) ;
struct V_13 * V_14 ;
V_14 = F_23 ( V_39 -> V_2 , V_39 -> V_27 ) ;
if ( F_19 ( V_14 ) )
return F_35 ( V_14 ) ;
V_14 -> V_40 = F_36 () ;
V_14 -> V_41 = F_37 ( V_42 ) ;
V_14 -> V_16 ++ ;
F_7 ( V_14 ) ;
return 0 ;
}
static void F_38 ( struct V_34 * V_35 )
{
int V_23 = F_34 ( V_35 ) ;
F_39 ( V_23 ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_36 * V_43 ;
V_43 = V_14 -> V_43 ;
V_14 -> V_43 = NULL ;
V_2 -> V_10 -= ( V_14 -> V_44 + V_45 - 1 ) >> V_46 ;
F_31 ( V_2 , V_14 ) ;
F_7 ( V_14 ) ;
if ( ! F_40 ( V_43 ) )
F_41 ( V_43 , 0 , V_14 -> V_47 ) ;
else if ( V_14 -> V_47 )
F_42 ( F_43 ( F_44 ( V_43 ) ) ,
V_14 -> V_47 ) ;
F_45 ( V_43 ) ;
F_46 ( & V_14 -> V_15 , F_28 ) ;
}
static bool F_47 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
return ( V_14 -> V_16 == 0 ) &&
( V_2 -> V_9 ||
( V_14 -> V_15 . V_17 & V_18 ) ) ;
}
static void F_48 ( struct V_34 * V_35 )
{
struct V_36 * V_36 = V_35 -> V_37 ;
struct V_38 * V_39 = V_38 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_1 * V_2 = V_39 -> V_2 ;
F_49 ( & F_3 ( V_2 ) . V_48 ) ;
V_14 = F_23 ( V_2 , V_39 -> V_27 ) ;
if ( F_39 ( F_19 ( V_14 ) ) )
goto V_49;
V_14 -> V_41 = F_37 ( V_42 ) ;
V_14 -> V_50 = F_36 () ;
V_14 -> V_16 -- ;
if ( F_47 ( V_2 , V_14 ) )
F_8 ( V_2 , V_14 ) ;
else
F_7 ( V_14 ) ;
V_49:
F_50 ( & F_3 ( V_2 ) . V_48 ) ;
}
static int F_51 ( int V_27 , void * V_51 , void * V_52 )
{
struct V_1 * V_2 = V_52 ;
struct V_11 * V_12 = V_51 ;
struct V_13 * V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_53 != NULL )
return 0 ;
if ( F_47 ( V_2 , V_14 ) ) {
F_25 ( V_14 ) ;
F_8 ( V_2 , V_14 ) ;
}
return 0 ;
}
void F_52 ( struct V_1 * V_2 )
{
F_49 ( & F_3 ( V_2 ) . V_48 ) ;
if ( F_3 ( V_2 ) . V_54 )
F_53 ( & F_3 ( V_2 ) . V_21 , & F_51 , V_2 ) ;
F_50 ( & F_3 ( V_2 ) . V_48 ) ;
}
void F_54 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_57 -> V_58 ;
struct V_13 * V_14 , * V_59 ;
if ( F_55 ( & V_56 -> V_60 . V_33 ) )
return;
if ( ! V_2 -> V_9 ) {
F_56 ( & F_3 ( V_2 ) . V_48 ) ;
F_57 (shp, &task->sysvshm.shm_clist, shm_clist)
V_14 -> V_53 = NULL ;
F_32 ( & V_56 -> V_60 . V_33 ) ;
F_58 ( & F_3 ( V_2 ) . V_48 ) ;
return;
}
F_49 ( & F_3 ( V_2 ) . V_48 ) ;
F_59 (shp, n, &task->sysvshm.shm_clist, shm_clist) {
V_14 -> V_53 = NULL ;
if ( F_47 ( V_2 , V_14 ) ) {
F_25 ( V_14 ) ;
F_8 ( V_2 , V_14 ) ;
}
}
F_32 ( & V_56 -> V_60 . V_33 ) ;
F_50 ( & F_3 ( V_2 ) . V_48 ) ;
}
static int F_60 ( struct V_61 * V_62 )
{
struct V_36 * V_36 = V_62 -> V_35 -> V_37 ;
struct V_38 * V_39 = V_38 ( V_36 ) ;
return V_39 -> V_63 -> V_64 ( V_62 ) ;
}
static int F_61 ( struct V_34 * V_35 , struct V_65 * V_66 )
{
struct V_36 * V_36 = V_35 -> V_37 ;
struct V_38 * V_39 = V_38 ( V_36 ) ;
int V_23 = 0 ;
if ( V_39 -> V_63 -> V_67 )
V_23 = V_39 -> V_63 -> V_67 ( V_35 , V_66 ) ;
return V_23 ;
}
static struct V_65 * F_62 ( struct V_34 * V_35 ,
unsigned long V_68 )
{
struct V_36 * V_36 = V_35 -> V_37 ;
struct V_38 * V_39 = V_38 ( V_36 ) ;
struct V_65 * V_69 = NULL ;
if ( V_39 -> V_63 -> V_70 )
V_69 = V_39 -> V_63 -> V_70 ( V_35 , V_68 ) ;
else if ( V_35 -> V_71 )
V_69 = V_35 -> V_71 ;
return V_69 ;
}
static int F_63 ( struct V_36 * V_36 , struct V_34 * V_35 )
{
struct V_38 * V_39 = V_38 ( V_36 ) ;
int V_72 ;
V_72 = F_34 ( V_35 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_64 ( V_39 -> V_36 , V_35 ) ;
if ( V_72 ) {
F_48 ( V_35 ) ;
return V_72 ;
}
V_39 -> V_63 = V_35 -> V_63 ;
#ifdef F_65
F_66 ( ! V_39 -> V_63 -> V_64 ) ;
#endif
V_35 -> V_63 = & V_73 ;
return 0 ;
}
static int F_67 ( struct V_74 * V_75 , struct V_36 * V_36 )
{
struct V_38 * V_39 = V_38 ( V_36 ) ;
F_68 ( V_39 -> V_2 ) ;
V_38 ( V_36 ) = NULL ;
F_69 ( V_39 ) ;
return 0 ;
}
static int F_70 ( struct V_36 * V_36 , T_2 V_76 , T_2 V_77 , int V_78 )
{
struct V_38 * V_39 = V_38 ( V_36 ) ;
if ( ! V_39 -> V_36 -> V_79 -> V_80 )
return - V_81 ;
return V_39 -> V_36 -> V_79 -> V_80 ( V_39 -> V_36 , V_76 , V_77 , V_78 ) ;
}
static long F_71 ( struct V_36 * V_36 , int V_17 , T_2 V_82 ,
T_2 V_83 )
{
struct V_38 * V_39 = V_38 ( V_36 ) ;
if ( ! V_39 -> V_36 -> V_79 -> V_84 )
return - V_85 ;
return V_39 -> V_36 -> V_79 -> V_84 ( V_36 , V_17 , V_82 , V_83 ) ;
}
static unsigned long F_72 ( struct V_36 * V_36 ,
unsigned long V_68 , unsigned long V_83 , unsigned long V_86 ,
unsigned long V_87 )
{
struct V_38 * V_39 = V_38 ( V_36 ) ;
return V_39 -> V_36 -> V_79 -> V_88 ( V_39 -> V_36 , V_68 , V_83 ,
V_86 , V_87 ) ;
}
bool F_73 ( struct V_36 * V_36 )
{
return V_36 -> V_79 == & V_89 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
T_3 V_92 = V_91 -> V_92 ;
int V_93 = V_91 -> V_94 ;
T_4 V_95 = V_91 -> V_96 . V_95 ;
int error ;
struct V_13 * V_14 ;
T_4 V_97 = ( V_95 + V_45 - 1 ) >> V_46 ;
struct V_36 * V_36 ;
char V_98 [ 13 ] ;
T_5 V_99 = 0 ;
if ( V_95 < V_100 || V_95 > V_2 -> V_3 )
return - V_81 ;
if ( V_97 << V_46 < V_95 )
return - V_101 ;
if ( V_2 -> V_10 + V_97 < V_2 -> V_10 ||
V_2 -> V_10 + V_97 > V_2 -> V_5 )
return - V_101 ;
V_14 = F_75 ( sizeof( * V_14 ) , V_102 ) ;
if ( F_76 ( ! V_14 ) )
return - V_103 ;
V_14 -> V_15 . V_92 = V_92 ;
V_14 -> V_15 . V_17 = ( V_93 & V_104 ) ;
V_14 -> V_47 = NULL ;
V_14 -> V_15 . V_105 = NULL ;
error = F_77 ( V_14 ) ;
if ( error ) {
F_30 ( V_14 ) ;
return error ;
}
sprintf ( V_98 , L_5 , V_92 ) ;
if ( V_93 & V_106 ) {
struct V_107 * V_108 ;
T_4 V_109 ;
V_108 = F_78 ( ( V_93 >> V_110 ) & V_111 ) ;
if ( ! V_108 ) {
error = - V_81 ;
goto V_112;
}
V_109 = F_79 ( V_95 , F_80 ( V_108 ) ) ;
if ( V_93 & V_113 )
V_99 = V_114 ;
V_36 = F_81 ( V_98 , V_109 , V_99 ,
& V_14 -> V_47 , V_115 ,
( V_93 >> V_110 ) & V_111 ) ;
} else {
if ( ( V_93 & V_113 ) &&
V_116 != V_117 )
V_99 = V_114 ;
V_36 = F_82 ( V_98 , V_95 , V_99 ) ;
}
error = F_35 ( V_36 ) ;
if ( F_19 ( V_36 ) )
goto V_112;
V_14 -> V_118 = F_37 ( V_42 ) ;
V_14 -> V_41 = 0 ;
V_14 -> V_40 = V_14 -> V_50 = 0 ;
V_14 -> V_119 = F_36 () ;
V_14 -> V_44 = V_95 ;
V_14 -> V_16 = 0 ;
V_14 -> V_43 = V_36 ;
V_14 -> V_53 = V_42 ;
error = F_83 ( & F_3 ( V_2 ) , & V_14 -> V_15 , V_2 -> V_7 ) ;
if ( error < 0 )
goto V_120;
F_84 ( & V_14 -> V_33 , & V_42 -> V_60 . V_33 ) ;
F_44 ( V_36 ) -> V_121 = V_14 -> V_15 . V_27 ;
V_2 -> V_10 += V_97 ;
error = V_14 -> V_15 . V_27 ;
F_85 ( & V_14 -> V_15 ) ;
F_86 () ;
return error ;
V_120:
if ( F_40 ( V_36 ) && V_14 -> V_47 )
F_42 ( V_95 , V_14 -> V_47 ) ;
F_45 ( V_36 ) ;
V_112:
F_87 ( & V_14 -> V_15 . V_31 , F_28 ) ;
return error ;
}
static inline int F_88 ( struct V_11 * V_12 , int V_93 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
return F_89 ( V_14 , V_93 ) ;
}
static inline int F_90 ( struct V_11 * V_12 ,
struct V_90 * V_91 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_44 < V_91 -> V_96 . V_95 )
return - V_81 ;
return 0 ;
}
static inline unsigned long F_91 ( void T_6 * V_122 , struct V_123 * V_124 , int V_125 )
{
switch ( V_125 ) {
case V_126 :
return F_92 ( V_122 , V_124 , sizeof( * V_124 ) ) ;
case V_127 :
{
struct V_128 V_129 ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
F_93 ( & V_124 -> V_15 , & V_129 . V_15 ) ;
V_129 . V_44 = V_124 -> V_44 ;
V_129 . V_130 = V_124 -> V_130 ;
V_129 . V_131 = V_124 -> V_131 ;
V_129 . V_132 = V_124 -> V_132 ;
V_129 . V_133 = V_124 -> V_133 ;
V_129 . V_134 = V_124 -> V_134 ;
V_129 . V_16 = V_124 -> V_16 ;
return F_92 ( V_122 , & V_129 , sizeof( V_129 ) ) ;
}
default:
return - V_81 ;
}
}
static inline unsigned long
F_94 ( struct V_123 * V_129 , void T_6 * V_122 , int V_125 )
{
switch ( V_125 ) {
case V_126 :
if ( F_95 ( V_129 , V_122 , sizeof( * V_129 ) ) )
return - V_135 ;
return 0 ;
case V_127 :
{
struct V_128 V_136 ;
if ( F_95 ( & V_136 , V_122 , sizeof( V_136 ) ) )
return - V_135 ;
V_129 -> V_15 . V_137 = V_136 . V_15 . V_137 ;
V_129 -> V_15 . V_138 = V_136 . V_15 . V_138 ;
V_129 -> V_15 . V_17 = V_136 . V_15 . V_17 ;
return 0 ;
}
default:
return - V_81 ;
}
}
static inline unsigned long F_96 ( void T_6 * V_122 , struct V_139 * V_124 , int V_125 )
{
switch ( V_125 ) {
case V_126 :
return F_92 ( V_122 , V_124 , sizeof( * V_124 ) ) ;
case V_127 :
{
struct V_140 V_129 ;
if ( V_124 -> V_141 > V_142 )
V_129 . V_141 = V_142 ;
else
V_129 . V_141 = ( int ) V_124 -> V_141 ;
V_129 . V_143 = V_124 -> V_143 ;
V_129 . V_144 = V_124 -> V_144 ;
V_129 . V_145 = V_124 -> V_145 ;
V_129 . V_146 = V_124 -> V_146 ;
return F_92 ( V_122 , & V_129 , sizeof( V_129 ) ) ;
}
default:
return - V_81 ;
}
}
static void F_97 ( struct V_13 * V_14 ,
unsigned long * V_147 , unsigned long * V_148 )
{
struct V_74 * V_74 ;
V_74 = F_44 ( V_14 -> V_43 ) ;
if ( F_40 ( V_14 -> V_43 ) ) {
struct V_149 * V_150 = V_74 -> V_151 ;
struct V_107 * V_152 = F_98 ( V_14 -> V_43 ) ;
* V_147 += F_99 ( V_152 ) * V_150 -> V_153 ;
} else {
#ifdef F_100
struct V_154 * V_155 = F_101 ( V_74 ) ;
F_102 ( & V_155 -> V_156 ) ;
* V_147 += V_74 -> V_151 -> V_153 ;
* V_148 += V_155 -> V_157 ;
F_103 ( & V_155 -> V_156 ) ;
#else
* V_147 += V_74 -> V_151 -> V_153 ;
#endif
}
}
static void F_104 ( struct V_1 * V_2 , unsigned long * V_158 ,
unsigned long * V_159 )
{
int V_160 ;
int V_161 , V_54 ;
* V_158 = 0 ;
* V_159 = 0 ;
V_54 = F_3 ( V_2 ) . V_54 ;
for ( V_161 = 0 , V_160 = 0 ; V_161 < V_54 ; V_160 ++ ) {
struct V_11 * V_162 ;
struct V_13 * V_14 ;
V_162 = F_105 ( & F_3 ( V_2 ) . V_21 , V_160 ) ;
if ( V_162 == NULL )
continue;
V_14 = F_5 ( V_162 , struct V_13 , V_15 ) ;
F_97 ( V_14 , V_158 , V_159 ) ;
V_161 ++ ;
}
}
static int F_106 ( struct V_1 * V_2 , int V_163 , int V_164 ,
struct V_123 * V_165 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_23 ;
F_49 ( & F_3 ( V_2 ) . V_48 ) ;
F_26 () ;
V_12 = F_107 ( V_2 , & F_3 ( V_2 ) , V_163 , V_164 ,
& V_165 -> V_15 , 0 ) ;
if ( F_19 ( V_12 ) ) {
V_23 = F_35 ( V_12 ) ;
goto V_166;
}
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
V_23 = F_108 ( V_14 , V_164 ) ;
if ( V_23 )
goto V_166;
switch ( V_164 ) {
case V_167 :
F_27 ( & V_14 -> V_15 ) ;
F_4 ( V_2 , V_12 ) ;
goto V_168;
case V_169 :
F_27 ( & V_14 -> V_15 ) ;
V_23 = F_109 ( & V_165 -> V_15 , V_12 ) ;
if ( V_23 )
goto V_170;
V_14 -> V_119 = F_36 () ;
break;
default:
V_23 = - V_81 ;
goto V_166;
}
V_170:
F_85 ( & V_14 -> V_15 ) ;
V_166:
F_86 () ;
V_168:
F_50 ( & F_3 ( V_2 ) . V_48 ) ;
return V_23 ;
}
static int F_110 ( struct V_1 * V_2 ,
struct V_139 * V_140 )
{
int V_23 = F_108 ( NULL , V_171 ) ;
if ( ! V_23 ) {
memset ( V_140 , 0 , sizeof( * V_140 ) ) ;
V_140 -> V_144 = V_140 -> V_145 = V_2 -> V_7 ;
V_140 -> V_141 = V_2 -> V_3 ;
V_140 -> V_146 = V_2 -> V_5 ;
V_140 -> V_143 = V_100 ;
F_56 ( & F_3 ( V_2 ) . V_48 ) ;
V_23 = F_111 ( & F_3 ( V_2 ) ) ;
F_58 ( & F_3 ( V_2 ) . V_48 ) ;
if ( V_23 < 0 )
V_23 = 0 ;
}
return V_23 ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_172 * V_172 )
{
int V_23 = F_108 ( NULL , V_173 ) ;
if ( ! V_23 ) {
memset ( V_172 , 0 , sizeof( * V_172 ) ) ;
F_56 ( & F_3 ( V_2 ) . V_48 ) ;
V_172 -> V_174 = F_3 ( V_2 ) . V_54 ;
F_104 ( V_2 , & V_172 -> V_175 , & V_172 -> V_176 ) ;
V_172 -> V_10 = V_2 -> V_10 ;
V_172 -> V_177 = 0 ;
V_172 -> V_178 = 0 ;
V_23 = F_111 ( & F_3 ( V_2 ) ) ;
F_58 ( & F_3 ( V_2 ) . V_48 ) ;
if ( V_23 < 0 )
V_23 = 0 ;
}
return V_23 ;
}
static int F_113 ( struct V_1 * V_2 , int V_163 ,
int V_164 , struct V_123 * V_179 )
{
struct V_13 * V_14 ;
int V_180 ;
int V_23 ;
F_26 () ;
if ( V_164 == V_181 ) {
V_14 = F_17 ( V_2 , V_163 ) ;
if ( F_19 ( V_14 ) ) {
V_23 = F_35 ( V_14 ) ;
goto V_182;
}
V_180 = V_14 -> V_15 . V_27 ;
} else {
V_14 = F_21 ( V_2 , V_163 ) ;
if ( F_19 ( V_14 ) ) {
V_23 = F_35 ( V_14 ) ;
goto V_182;
}
V_180 = 0 ;
}
V_23 = - V_183 ;
if ( F_114 ( V_2 , & V_14 -> V_15 , V_184 ) )
goto V_182;
V_23 = F_108 ( V_14 , V_164 ) ;
if ( V_23 )
goto V_182;
memset ( V_179 , 0 , sizeof( * V_179 ) ) ;
F_115 ( & V_14 -> V_15 , & V_179 -> V_15 ) ;
V_179 -> V_44 = V_14 -> V_44 ;
V_179 -> V_130 = V_14 -> V_40 ;
V_179 -> V_131 = V_14 -> V_50 ;
V_179 -> V_132 = V_14 -> V_119 ;
V_179 -> V_133 = V_14 -> V_118 ;
V_179 -> V_134 = V_14 -> V_41 ;
V_179 -> V_16 = V_14 -> V_16 ;
F_86 () ;
return V_180 ;
V_182:
F_86 () ;
return V_23 ;
}
static int F_116 ( struct V_1 * V_2 , int V_163 , int V_164 )
{
struct V_13 * V_14 ;
struct V_36 * V_43 ;
int V_23 ;
F_26 () ;
V_14 = F_21 ( V_2 , V_163 ) ;
if ( F_19 ( V_14 ) ) {
V_23 = F_35 ( V_14 ) ;
goto V_166;
}
F_117 ( & ( V_14 -> V_15 ) ) ;
V_23 = F_108 ( V_14 , V_164 ) ;
if ( V_23 )
goto V_166;
F_27 ( & V_14 -> V_15 ) ;
if ( ! F_118 ( & V_14 -> V_15 ) ) {
V_23 = - V_185 ;
goto V_170;
}
if ( ! F_119 ( V_2 -> V_186 , V_187 ) ) {
T_7 V_188 = F_120 () ;
if ( ! F_121 ( V_188 , V_14 -> V_15 . V_137 ) &&
! F_121 ( V_188 , V_14 -> V_15 . V_189 ) ) {
V_23 = - V_190 ;
goto V_170;
}
if ( V_164 == V_191 && ! F_122 ( V_192 ) ) {
V_23 = - V_190 ;
goto V_170;
}
}
V_43 = V_14 -> V_43 ;
if ( F_40 ( V_43 ) )
goto V_170;
if ( V_164 == V_191 ) {
struct V_193 * V_194 = F_123 () ;
V_23 = F_41 ( V_43 , 1 , V_194 ) ;
if ( ! V_23 && ! ( V_14 -> V_15 . V_17 & V_195 ) ) {
V_14 -> V_15 . V_17 |= V_195 ;
V_14 -> V_47 = V_194 ;
}
goto V_170;
}
if ( ! ( V_14 -> V_15 . V_17 & V_195 ) )
goto V_170;
F_41 ( V_43 , 0 , V_14 -> V_47 ) ;
V_14 -> V_15 . V_17 &= ~ V_195 ;
V_14 -> V_47 = NULL ;
F_124 ( V_43 ) ;
F_85 ( & V_14 -> V_15 ) ;
F_86 () ;
F_125 ( V_43 -> V_196 ) ;
F_45 ( V_43 ) ;
return V_23 ;
V_170:
F_85 ( & V_14 -> V_15 ) ;
V_166:
F_86 () ;
return V_23 ;
}
static int F_126 ( void T_6 * V_122 , struct V_139 * V_124 ,
int V_125 )
{
if ( V_124 -> V_141 > V_142 )
V_124 -> V_141 = V_142 ;
if ( V_125 == V_126 ) {
struct V_197 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_141 = V_124 -> V_141 ;
V_155 . V_143 = V_124 -> V_143 ;
V_155 . V_144 = V_124 -> V_144 ;
V_155 . V_145 = V_124 -> V_145 ;
V_155 . V_146 = V_124 -> V_146 ;
return F_92 ( V_122 , & V_155 , sizeof( V_155 ) ) ;
} else {
struct V_140 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_141 = V_124 -> V_141 ;
V_155 . V_143 = V_124 -> V_143 ;
V_155 . V_144 = V_124 -> V_144 ;
V_155 . V_145 = V_124 -> V_145 ;
V_155 . V_146 = V_124 -> V_146 ;
return F_92 ( V_122 , & V_155 , sizeof( V_155 ) ) ;
}
}
static int F_127 ( struct V_172 * V_198 ,
struct V_199 T_6 * V_200 )
{
struct V_199 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_174 = V_198 -> V_174 ;
V_155 . V_10 = V_198 -> V_10 ;
V_155 . V_175 = V_198 -> V_175 ;
V_155 . V_176 = V_198 -> V_176 ;
V_155 . V_177 = V_198 -> V_177 ;
V_155 . V_178 = V_198 -> V_178 ;
return F_92 ( V_200 , & V_155 , sizeof( V_155 ) ) ;
}
static int F_128 ( void T_6 * V_122 , struct V_123 * V_124 ,
int V_125 )
{
if ( V_125 == V_126 ) {
struct V_201 V_202 ;
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
F_129 ( & V_202 . V_15 , & V_124 -> V_15 ) ;
V_202 . V_130 = V_124 -> V_130 ;
V_202 . V_131 = V_124 -> V_131 ;
V_202 . V_132 = V_124 -> V_132 ;
V_202 . V_44 = V_124 -> V_44 ;
V_202 . V_16 = V_124 -> V_16 ;
V_202 . V_133 = V_124 -> V_133 ;
V_202 . V_134 = V_124 -> V_134 ;
return F_92 ( V_122 , & V_202 , sizeof( V_202 ) ) ;
} else {
struct V_203 V_202 ;
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
F_130 ( & V_202 . V_15 , & V_124 -> V_15 ) ;
V_202 . V_15 . V_92 = V_124 -> V_15 . V_92 ;
V_202 . V_130 = V_124 -> V_130 ;
V_202 . V_131 = V_124 -> V_131 ;
V_202 . V_132 = V_124 -> V_132 ;
V_202 . V_44 = V_124 -> V_44 ;
V_202 . V_16 = V_124 -> V_16 ;
V_202 . V_133 = V_124 -> V_133 ;
V_202 . V_134 = V_124 -> V_134 ;
return F_92 ( V_122 , & V_202 , sizeof( V_202 ) ) ;
}
}
static int F_131 ( struct V_123 * V_129 , void T_6 * V_122 ,
int V_125 )
{
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
if ( V_125 == V_126 ) {
struct V_201 * V_51 = V_122 ;
return F_132 ( & V_129 -> V_15 , & V_51 -> V_15 ) ;
} else {
struct V_203 * V_51 = V_122 ;
return F_133 ( & V_129 -> V_15 , & V_51 -> V_15 ) ;
}
}
long F_134 ( int V_163 , char T_6 * V_204 , int V_93 ,
T_8 * V_205 , unsigned long V_206 )
{
struct V_13 * V_14 ;
unsigned long V_68 = ( unsigned long ) V_204 ;
unsigned long V_95 ;
struct V_36 * V_36 ;
int V_23 ;
unsigned long V_87 = V_207 ;
unsigned long V_208 ;
int V_209 ;
struct V_1 * V_2 ;
struct V_38 * V_39 ;
struct V_210 V_210 ;
T_9 V_211 ;
unsigned long V_212 = 0 ;
V_23 = - V_81 ;
if ( V_163 < 0 )
goto V_129;
if ( V_68 ) {
if ( V_68 & ( V_206 - 1 ) ) {
if ( ( V_93 & V_213 ) && V_68 >= V_206 )
V_68 &= ~ ( V_206 - 1 ) ;
else
#ifndef F_135
if ( V_68 & ~ V_214 )
#endif
goto V_129;
}
V_87 |= V_215 ;
} else if ( ( V_93 & V_216 ) )
goto V_129;
if ( V_93 & V_217 ) {
V_208 = V_218 ;
V_209 = V_184 ;
V_211 = V_219 ;
} else {
V_208 = V_218 | V_220 ;
V_209 = V_184 | V_221 ;
V_211 = V_219 | V_222 ;
}
if ( V_93 & V_223 ) {
V_208 |= V_224 ;
V_209 |= V_225 ;
}
V_2 = V_42 -> V_57 -> V_58 ;
F_26 () ;
V_14 = F_21 ( V_2 , V_163 ) ;
if ( F_19 ( V_14 ) ) {
V_23 = F_35 ( V_14 ) ;
goto V_182;
}
V_23 = - V_183 ;
if ( F_114 ( V_2 , & V_14 -> V_15 , V_209 ) )
goto V_182;
V_23 = F_136 ( V_14 , V_204 , V_93 ) ;
if ( V_23 )
goto V_182;
F_27 ( & V_14 -> V_15 ) ;
if ( ! F_118 ( & V_14 -> V_15 ) ) {
F_85 ( & V_14 -> V_15 ) ;
V_23 = - V_185 ;
goto V_182;
}
V_210 = V_14 -> V_43 -> V_226 ;
F_137 ( & V_210 ) ;
V_14 -> V_16 ++ ;
V_95 = F_43 ( F_138 ( V_210 . V_227 ) ) ;
F_85 ( & V_14 -> V_15 ) ;
F_86 () ;
V_23 = - V_103 ;
V_39 = F_139 ( sizeof( * V_39 ) , V_102 ) ;
if ( ! V_39 ) {
F_140 ( & V_210 ) ;
goto V_228;
}
V_36 = F_141 ( & V_210 , V_211 ,
F_40 ( V_14 -> V_43 ) ?
& V_89 :
& V_229 ) ;
V_23 = F_35 ( V_36 ) ;
if ( F_19 ( V_36 ) ) {
F_69 ( V_39 ) ;
F_140 ( & V_210 ) ;
goto V_228;
}
V_36 -> V_230 = V_39 ;
V_36 -> V_196 = V_14 -> V_43 -> V_196 ;
V_39 -> V_27 = V_14 -> V_15 . V_27 ;
V_39 -> V_2 = F_142 ( V_2 ) ;
V_39 -> V_36 = V_14 -> V_43 ;
V_39 -> V_63 = NULL ;
V_23 = F_143 ( V_36 , V_208 , V_87 ) ;
if ( V_23 )
goto V_231;
if ( F_144 ( & V_42 -> V_232 -> V_233 ) ) {
V_23 = - V_234 ;
goto V_231;
}
if ( V_68 && ! ( V_93 & V_216 ) ) {
V_23 = - V_81 ;
if ( V_68 + V_95 < V_68 )
goto V_235;
if ( F_145 ( V_42 -> V_232 , V_68 , V_68 + V_95 ) )
goto V_235;
}
V_68 = F_146 ( V_36 , V_68 , V_95 , V_208 , V_87 , 0 , & V_212 , NULL ) ;
* V_205 = V_68 ;
V_23 = 0 ;
if ( F_147 ( V_68 ) )
V_23 = ( long ) V_68 ;
V_235:
F_50 ( & V_42 -> V_232 -> V_233 ) ;
if ( V_212 )
F_148 ( V_68 , V_212 ) ;
V_231:
F_45 ( V_36 ) ;
V_228:
F_49 ( & F_3 ( V_2 ) . V_48 ) ;
V_14 = F_23 ( V_2 , V_163 ) ;
V_14 -> V_16 -- ;
if ( F_47 ( V_2 , V_14 ) )
F_8 ( V_2 , V_14 ) ;
else
F_7 ( V_14 ) ;
F_50 ( & F_3 ( V_2 ) . V_48 ) ;
return V_23 ;
V_182:
F_86 () ;
V_129:
return V_23 ;
}
static int V_26 ( struct V_236 * V_32 , void * V_237 )
{
struct V_238 * V_186 = F_149 ( V_32 ) ;
struct V_11 * V_12 = V_237 ;
struct V_13 * V_14 ;
unsigned long V_158 = 0 , V_159 = 0 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
F_97 ( V_14 , & V_158 , & V_159 ) ;
#if V_25 <= 32
#define F_150 "%10lu"
#else
#define F_150 "%21lu"
#endif
F_151 ( V_32 ,
L_6 F_150 L_7
L_8
F_150 L_9 F_150 L_10 ,
V_14 -> V_15 . V_92 ,
V_14 -> V_15 . V_27 ,
V_14 -> V_15 . V_17 ,
V_14 -> V_44 ,
V_14 -> V_118 ,
V_14 -> V_41 ,
V_14 -> V_16 ,
F_152 ( V_186 , V_14 -> V_15 . V_137 ) ,
F_153 ( V_186 , V_14 -> V_15 . V_138 ) ,
F_152 ( V_186 , V_14 -> V_15 . V_189 ) ,
F_153 ( V_186 , V_14 -> V_15 . V_239 ) ,
V_14 -> V_40 ,
V_14 -> V_50 ,
V_14 -> V_119 ,
V_158 * V_45 ,
V_159 * V_45 ) ;
return 0 ;
}

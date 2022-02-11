void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
F_2 ( & F_3 ( V_2 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_16 ) {
V_14 -> V_15 . V_17 |= V_18 ;
V_14 -> V_15 . V_19 = V_20 ;
F_6 ( V_14 ) ;
} else
F_7 ( V_2 , V_14 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 , & F_3 ( V_2 ) , F_4 ) ;
F_10 ( & V_2 -> V_21 [ V_22 ] . V_23 ) ;
}
static int T_1 F_11 ( void )
{
F_1 ( & V_24 ) ;
return 0 ;
}
void T_1 F_12 ( void )
{
F_13 ( L_1 ,
#if V_25 <= 32
L_2 ,
#else
L_3 ,
#endif
V_22 , V_26 ) ;
}
static inline struct V_13 * F_14 ( struct V_1 * V_2 , int V_27 )
{
struct V_11 * V_12 = F_15 ( & F_3 ( V_2 ) , V_27 ) ;
if ( F_16 ( V_12 ) )
return F_17 ( V_12 ) ;
return F_5 ( V_12 , struct V_13 , V_15 ) ;
}
static inline struct V_13 * F_18 ( struct V_1 * V_2 , int V_27 )
{
struct V_11 * V_12 = F_19 ( & F_3 ( V_2 ) , V_27 ) ;
if ( F_16 ( V_12 ) )
return F_17 ( V_12 ) ;
return F_5 ( V_12 , struct V_13 , V_15 ) ;
}
static inline struct V_13 * F_20 ( struct V_1 * V_2 , int V_27 )
{
struct V_11 * V_12 = F_21 ( & F_3 ( V_2 ) , V_27 ) ;
if ( F_16 ( V_12 ) )
return ( void * ) V_12 ;
return F_5 ( V_12 , struct V_13 , V_15 ) ;
}
static inline void F_22 ( struct V_13 * V_12 )
{
F_23 () ;
F_24 ( & V_12 -> V_15 ) ;
}
static void F_25 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_5 ( V_29 , struct V_30 , V_32 ) ;
struct V_13 * V_14 = F_26 ( V_31 ) ;
F_27 ( V_14 ) ;
F_28 ( V_29 ) ;
}
static inline void F_29 ( struct V_1 * V_2 , struct V_13 * V_33 )
{
F_30 ( & V_33 -> V_34 ) ;
F_31 ( & F_3 ( V_2 ) , & V_33 -> V_15 ) ;
}
static int F_32 ( struct V_35 * V_36 )
{
struct V_37 * V_37 = V_36 -> V_38 ;
struct V_39 * V_40 = V_39 ( V_37 ) ;
struct V_13 * V_14 ;
V_14 = F_20 ( V_40 -> V_2 , V_40 -> V_27 ) ;
if ( F_16 ( V_14 ) )
return F_33 ( V_14 ) ;
V_14 -> V_41 = F_34 () ;
V_14 -> V_42 = F_35 ( V_43 ) ;
V_14 -> V_16 ++ ;
F_6 ( V_14 ) ;
return 0 ;
}
static void F_36 ( struct V_35 * V_36 )
{
int V_44 = F_32 ( V_36 ) ;
F_37 ( V_44 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_37 * V_45 ;
V_45 = V_14 -> V_45 ;
V_14 -> V_45 = NULL ;
V_2 -> V_10 -= ( V_14 -> V_46 + V_47 - 1 ) >> V_48 ;
F_29 ( V_2 , V_14 ) ;
F_6 ( V_14 ) ;
if ( ! F_38 ( V_45 ) )
F_39 ( V_45 , 0 , V_14 -> V_49 ) ;
else if ( V_14 -> V_49 )
F_40 ( F_41 ( F_42 ( V_45 ) ) ,
V_14 -> V_49 ) ;
F_43 ( V_45 ) ;
F_44 ( V_14 , F_25 ) ;
}
static bool F_45 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
return ( V_14 -> V_16 == 0 ) &&
( V_2 -> V_9 ||
( V_14 -> V_15 . V_17 & V_18 ) ) ;
}
static void F_46 ( struct V_35 * V_36 )
{
struct V_37 * V_37 = V_36 -> V_38 ;
struct V_39 * V_40 = V_39 ( V_37 ) ;
struct V_13 * V_14 ;
struct V_1 * V_2 = V_40 -> V_2 ;
F_47 ( & F_3 ( V_2 ) . V_50 ) ;
V_14 = F_20 ( V_2 , V_40 -> V_27 ) ;
if ( F_37 ( F_16 ( V_14 ) ) )
goto V_51;
V_14 -> V_42 = F_35 ( V_43 ) ;
V_14 -> V_52 = F_34 () ;
V_14 -> V_16 -- ;
if ( F_45 ( V_2 , V_14 ) )
F_7 ( V_2 , V_14 ) ;
else
F_6 ( V_14 ) ;
V_51:
F_48 ( & F_3 ( V_2 ) . V_50 ) ;
}
static int F_49 ( int V_27 , void * V_31 , void * V_53 )
{
struct V_1 * V_2 = V_53 ;
struct V_11 * V_12 = V_31 ;
struct V_13 * V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_54 != NULL )
return 0 ;
if ( F_45 ( V_2 , V_14 ) ) {
F_22 ( V_14 ) ;
F_7 ( V_2 , V_14 ) ;
}
return 0 ;
}
void F_50 ( struct V_1 * V_2 )
{
F_47 ( & F_3 ( V_2 ) . V_50 ) ;
if ( F_3 ( V_2 ) . V_55 )
F_51 ( & F_3 ( V_2 ) . V_23 , & F_49 , V_2 ) ;
F_48 ( & F_3 ( V_2 ) . V_50 ) ;
}
void F_52 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_58 -> V_59 ;
struct V_13 * V_14 , * V_60 ;
if ( F_53 ( & V_57 -> V_61 . V_34 ) )
return;
if ( ! V_2 -> V_9 ) {
F_54 ( & F_3 ( V_2 ) . V_50 ) ;
F_55 (shp, &task->sysvshm.shm_clist, shm_clist)
V_14 -> V_54 = NULL ;
F_30 ( & V_57 -> V_61 . V_34 ) ;
F_56 ( & F_3 ( V_2 ) . V_50 ) ;
return;
}
F_47 ( & F_3 ( V_2 ) . V_50 ) ;
F_57 (shp, n, &task->sysvshm.shm_clist, shm_clist) {
V_14 -> V_54 = NULL ;
if ( F_45 ( V_2 , V_14 ) ) {
F_22 ( V_14 ) ;
F_7 ( V_2 , V_14 ) ;
}
}
F_30 ( & V_57 -> V_61 . V_34 ) ;
F_48 ( & F_3 ( V_2 ) . V_50 ) ;
}
static int F_58 ( struct V_62 * V_63 )
{
struct V_37 * V_37 = V_63 -> V_36 -> V_38 ;
struct V_39 * V_40 = V_39 ( V_37 ) ;
return V_40 -> V_64 -> V_65 ( V_63 ) ;
}
static int F_59 ( struct V_35 * V_36 , struct V_66 * V_67 )
{
struct V_37 * V_37 = V_36 -> V_38 ;
struct V_39 * V_40 = V_39 ( V_37 ) ;
int V_44 = 0 ;
if ( V_40 -> V_64 -> V_68 )
V_44 = V_40 -> V_64 -> V_68 ( V_36 , V_67 ) ;
return V_44 ;
}
static struct V_66 * F_60 ( struct V_35 * V_36 ,
unsigned long V_69 )
{
struct V_37 * V_37 = V_36 -> V_38 ;
struct V_39 * V_40 = V_39 ( V_37 ) ;
struct V_66 * V_70 = NULL ;
if ( V_40 -> V_64 -> V_71 )
V_70 = V_40 -> V_64 -> V_71 ( V_36 , V_69 ) ;
else if ( V_36 -> V_72 )
V_70 = V_36 -> V_72 ;
return V_70 ;
}
static int F_61 ( struct V_37 * V_37 , struct V_35 * V_36 )
{
struct V_39 * V_40 = V_39 ( V_37 ) ;
int V_73 ;
V_73 = F_32 ( V_36 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_62 ( V_40 -> V_37 , V_36 ) ;
if ( V_73 ) {
F_46 ( V_36 ) ;
return V_73 ;
}
V_40 -> V_64 = V_36 -> V_64 ;
#ifdef F_63
F_64 ( ! V_40 -> V_64 -> V_65 ) ;
#endif
V_36 -> V_64 = & V_74 ;
return 0 ;
}
static int F_65 ( struct V_75 * V_76 , struct V_37 * V_37 )
{
struct V_39 * V_40 = V_39 ( V_37 ) ;
F_66 ( V_40 -> V_2 ) ;
V_39 ( V_37 ) = NULL ;
F_67 ( V_40 ) ;
return 0 ;
}
static int F_68 ( struct V_37 * V_37 , T_2 V_77 , T_2 V_78 , int V_79 )
{
struct V_39 * V_40 = V_39 ( V_37 ) ;
if ( ! V_40 -> V_37 -> V_80 -> V_81 )
return - V_82 ;
return F_69 ( V_40 -> V_37 , V_77 , V_78 , V_79 ) ;
}
static long F_70 ( struct V_37 * V_37 , int V_17 , T_2 V_83 ,
T_2 V_84 )
{
struct V_39 * V_40 = V_39 ( V_37 ) ;
if ( ! V_40 -> V_37 -> V_80 -> V_85 )
return - V_86 ;
return V_40 -> V_37 -> V_80 -> V_85 ( V_37 , V_17 , V_83 , V_84 ) ;
}
static unsigned long F_71 ( struct V_37 * V_37 ,
unsigned long V_69 , unsigned long V_84 , unsigned long V_87 ,
unsigned long V_88 )
{
struct V_39 * V_40 = V_39 ( V_37 ) ;
return V_40 -> V_37 -> V_80 -> V_89 ( V_40 -> V_37 , V_69 , V_84 ,
V_87 , V_88 ) ;
}
bool F_72 ( struct V_37 * V_37 )
{
return V_37 -> V_80 == & V_90 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
T_3 V_19 = V_92 -> V_19 ;
int V_93 = V_92 -> V_94 ;
T_4 V_95 = V_92 -> V_96 . V_95 ;
int error ;
struct V_13 * V_14 ;
T_4 V_97 = ( V_95 + V_47 - 1 ) >> V_48 ;
struct V_37 * V_37 ;
char V_98 [ 13 ] ;
int V_27 ;
T_5 V_99 = 0 ;
if ( V_95 < V_100 || V_95 > V_2 -> V_3 )
return - V_82 ;
if ( V_97 << V_48 < V_95 )
return - V_101 ;
if ( V_2 -> V_10 + V_97 < V_2 -> V_10 ||
V_2 -> V_10 + V_97 > V_2 -> V_5 )
return - V_101 ;
V_14 = F_74 ( sizeof( * V_14 ) ) ;
if ( ! V_14 )
return - V_102 ;
V_14 -> V_15 . V_19 = V_19 ;
V_14 -> V_15 . V_17 = ( V_93 & V_103 ) ;
V_14 -> V_49 = NULL ;
V_14 -> V_15 . V_104 = NULL ;
error = F_75 ( V_14 ) ;
if ( error ) {
F_44 ( V_14 , F_28 ) ;
return error ;
}
sprintf ( V_98 , L_4 , V_19 ) ;
if ( V_93 & V_105 ) {
struct V_106 * V_107 ;
T_4 V_108 ;
V_107 = F_76 ( ( V_93 >> V_109 ) & V_110 ) ;
if ( ! V_107 ) {
error = - V_82 ;
goto V_111;
}
V_108 = F_77 ( V_95 , F_78 ( V_107 ) ) ;
if ( V_93 & V_112 )
V_99 = V_113 ;
V_37 = F_79 ( V_98 , V_108 , V_99 ,
& V_14 -> V_49 , V_114 ,
( V_93 >> V_109 ) & V_110 ) ;
} else {
if ( ( V_93 & V_112 ) &&
V_115 != V_116 )
V_99 = V_113 ;
V_37 = F_80 ( V_98 , V_95 , V_99 ) ;
}
error = F_33 ( V_37 ) ;
if ( F_16 ( V_37 ) )
goto V_111;
V_14 -> V_117 = F_35 ( V_43 ) ;
V_14 -> V_42 = 0 ;
V_14 -> V_41 = V_14 -> V_52 = 0 ;
V_14 -> V_118 = F_34 () ;
V_14 -> V_46 = V_95 ;
V_14 -> V_16 = 0 ;
V_14 -> V_45 = V_37 ;
V_14 -> V_54 = V_43 ;
V_27 = F_81 ( & F_3 ( V_2 ) , & V_14 -> V_15 , V_2 -> V_7 ) ;
if ( V_27 < 0 ) {
error = V_27 ;
goto V_119;
}
F_82 ( & V_14 -> V_34 , & V_43 -> V_61 . V_34 ) ;
F_42 ( V_37 ) -> V_120 = V_14 -> V_15 . V_27 ;
V_2 -> V_10 += V_97 ;
error = V_14 -> V_15 . V_27 ;
F_83 ( & V_14 -> V_15 ) ;
F_84 () ;
return error ;
V_119:
if ( F_38 ( V_37 ) && V_14 -> V_49 )
F_40 ( V_95 , V_14 -> V_49 ) ;
F_43 ( V_37 ) ;
V_111:
F_44 ( V_14 , F_25 ) ;
return error ;
}
static inline int F_85 ( struct V_11 * V_12 , int V_93 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
return F_86 ( V_14 , V_93 ) ;
}
static inline int F_87 ( struct V_11 * V_12 ,
struct V_91 * V_92 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_46 < V_92 -> V_96 . V_95 )
return - V_82 ;
return 0 ;
}
static inline unsigned long F_88 ( void T_6 * V_121 , struct V_122 * V_123 , int V_124 )
{
switch ( V_124 ) {
case V_125 :
return F_89 ( V_121 , V_123 , sizeof( * V_123 ) ) ;
case V_126 :
{
struct V_127 V_128 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
F_90 ( & V_123 -> V_15 , & V_128 . V_15 ) ;
V_128 . V_46 = V_123 -> V_46 ;
V_128 . V_129 = V_123 -> V_129 ;
V_128 . V_130 = V_123 -> V_130 ;
V_128 . V_131 = V_123 -> V_131 ;
V_128 . V_132 = V_123 -> V_132 ;
V_128 . V_133 = V_123 -> V_133 ;
V_128 . V_16 = V_123 -> V_16 ;
return F_89 ( V_121 , & V_128 , sizeof( V_128 ) ) ;
}
default:
return - V_82 ;
}
}
static inline unsigned long
F_91 ( struct V_122 * V_128 , void T_6 * V_121 , int V_124 )
{
switch ( V_124 ) {
case V_125 :
if ( F_92 ( V_128 , V_121 , sizeof( * V_128 ) ) )
return - V_134 ;
return 0 ;
case V_126 :
{
struct V_127 V_135 ;
if ( F_92 ( & V_135 , V_121 , sizeof( V_135 ) ) )
return - V_134 ;
V_128 -> V_15 . V_136 = V_135 . V_15 . V_136 ;
V_128 -> V_15 . V_137 = V_135 . V_15 . V_137 ;
V_128 -> V_15 . V_17 = V_135 . V_15 . V_17 ;
return 0 ;
}
default:
return - V_82 ;
}
}
static inline unsigned long F_93 ( void T_6 * V_121 , struct V_138 * V_123 , int V_124 )
{
switch ( V_124 ) {
case V_125 :
return F_89 ( V_121 , V_123 , sizeof( * V_123 ) ) ;
case V_126 :
{
struct V_139 V_128 ;
if ( V_123 -> V_140 > V_141 )
V_128 . V_140 = V_141 ;
else
V_128 . V_140 = ( int ) V_123 -> V_140 ;
V_128 . V_142 = V_123 -> V_142 ;
V_128 . V_143 = V_123 -> V_143 ;
V_128 . V_144 = V_123 -> V_144 ;
V_128 . V_145 = V_123 -> V_145 ;
return F_89 ( V_121 , & V_128 , sizeof( V_128 ) ) ;
}
default:
return - V_82 ;
}
}
static void F_94 ( struct V_13 * V_14 ,
unsigned long * V_146 , unsigned long * V_147 )
{
struct V_75 * V_75 ;
V_75 = F_42 ( V_14 -> V_45 ) ;
if ( F_38 ( V_14 -> V_45 ) ) {
struct V_148 * V_149 = V_75 -> V_150 ;
struct V_106 * V_151 = F_95 ( V_14 -> V_45 ) ;
* V_146 += F_96 ( V_151 ) * V_149 -> V_152 ;
} else {
#ifdef F_97
struct V_153 * V_154 = F_98 ( V_75 ) ;
F_99 ( & V_154 -> V_155 ) ;
* V_146 += V_75 -> V_150 -> V_152 ;
* V_147 += V_154 -> V_156 ;
F_100 ( & V_154 -> V_155 ) ;
#else
* V_146 += V_75 -> V_150 -> V_152 ;
#endif
}
}
static void F_101 ( struct V_1 * V_2 , unsigned long * V_157 ,
unsigned long * V_158 )
{
int V_159 ;
int V_160 , V_55 ;
* V_157 = 0 ;
* V_158 = 0 ;
V_55 = F_3 ( V_2 ) . V_55 ;
for ( V_160 = 0 , V_159 = 0 ; V_160 < V_55 ; V_159 ++ ) {
struct V_11 * V_161 ;
struct V_13 * V_14 ;
V_161 = F_102 ( & F_3 ( V_2 ) . V_23 , V_159 ) ;
if ( V_161 == NULL )
continue;
V_14 = F_5 ( V_161 , struct V_13 , V_15 ) ;
F_94 ( V_14 , V_157 , V_158 ) ;
V_160 ++ ;
}
}
static int F_103 ( struct V_1 * V_2 , int V_162 , int V_163 ,
struct V_127 T_6 * V_121 , int V_124 )
{
struct V_11 * V_12 ;
struct V_122 V_164 ;
struct V_13 * V_14 ;
int V_44 ;
if ( V_163 == V_165 ) {
if ( F_91 ( & V_164 , V_121 , V_124 ) )
return - V_134 ;
}
F_47 ( & F_3 ( V_2 ) . V_50 ) ;
F_23 () ;
V_12 = F_104 ( V_2 , & F_3 ( V_2 ) , V_162 , V_163 ,
& V_164 . V_15 , 0 ) ;
if ( F_16 ( V_12 ) ) {
V_44 = F_33 ( V_12 ) ;
goto V_166;
}
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
V_44 = F_105 ( V_14 , V_163 ) ;
if ( V_44 )
goto V_166;
switch ( V_163 ) {
case V_167 :
F_24 ( & V_14 -> V_15 ) ;
F_4 ( V_2 , V_12 ) ;
goto V_168;
case V_165 :
F_24 ( & V_14 -> V_15 ) ;
V_44 = F_106 ( & V_164 . V_15 , V_12 ) ;
if ( V_44 )
goto V_169;
V_14 -> V_118 = F_34 () ;
break;
default:
V_44 = - V_82 ;
goto V_166;
}
V_169:
F_83 ( & V_14 -> V_15 ) ;
V_166:
F_84 () ;
V_168:
F_48 ( & F_3 ( V_2 ) . V_50 ) ;
return V_44 ;
}
static int F_107 ( struct V_1 * V_2 , int V_162 ,
int V_163 , int V_124 , void T_6 * V_121 )
{
int V_44 ;
struct V_13 * V_14 ;
if ( V_163 == V_170 || V_163 == V_171 ) {
V_44 = F_105 ( NULL , V_163 ) ;
if ( V_44 )
return V_44 ;
}
switch ( V_163 ) {
case V_170 :
{
struct V_138 V_139 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_143 = V_139 . V_144 = V_2 -> V_7 ;
V_139 . V_140 = V_2 -> V_3 ;
V_139 . V_145 = V_2 -> V_5 ;
V_139 . V_142 = V_100 ;
if ( F_93 ( V_121 , & V_139 , V_124 ) )
return - V_134 ;
F_54 ( & F_3 ( V_2 ) . V_50 ) ;
V_44 = F_108 ( & F_3 ( V_2 ) ) ;
F_56 ( & F_3 ( V_2 ) . V_50 ) ;
if ( V_44 < 0 )
V_44 = 0 ;
goto V_128;
}
case V_171 :
{
struct V_172 V_172 ;
memset ( & V_172 , 0 , sizeof( V_172 ) ) ;
F_54 ( & F_3 ( V_2 ) . V_50 ) ;
V_172 . V_173 = F_3 ( V_2 ) . V_55 ;
F_101 ( V_2 , & V_172 . V_174 , & V_172 . V_175 ) ;
V_172 . V_10 = V_2 -> V_10 ;
V_172 . V_176 = 0 ;
V_172 . V_177 = 0 ;
V_44 = F_108 ( & F_3 ( V_2 ) ) ;
F_56 ( & F_3 ( V_2 ) . V_50 ) ;
if ( F_89 ( V_121 , & V_172 , sizeof( V_172 ) ) ) {
V_44 = - V_134 ;
goto V_128;
}
V_44 = V_44 < 0 ? 0 : V_44 ;
goto V_128;
}
case V_178 :
case V_179 :
{
struct V_122 V_180 ;
int V_181 ;
F_23 () ;
if ( V_163 == V_178 ) {
V_14 = F_14 ( V_2 , V_162 ) ;
if ( F_16 ( V_14 ) ) {
V_44 = F_33 ( V_14 ) ;
goto V_182;
}
V_181 = V_14 -> V_15 . V_27 ;
} else {
V_14 = F_18 ( V_2 , V_162 ) ;
if ( F_16 ( V_14 ) ) {
V_44 = F_33 ( V_14 ) ;
goto V_182;
}
V_181 = 0 ;
}
V_44 = - V_183 ;
if ( F_109 ( V_2 , & V_14 -> V_15 , V_184 ) )
goto V_182;
V_44 = F_105 ( V_14 , V_163 ) ;
if ( V_44 )
goto V_182;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
F_110 ( & V_14 -> V_15 , & V_180 . V_15 ) ;
V_180 . V_46 = V_14 -> V_46 ;
V_180 . V_129 = V_14 -> V_41 ;
V_180 . V_130 = V_14 -> V_52 ;
V_180 . V_131 = V_14 -> V_118 ;
V_180 . V_132 = V_14 -> V_117 ;
V_180 . V_133 = V_14 -> V_42 ;
V_180 . V_16 = V_14 -> V_16 ;
F_84 () ;
if ( F_88 ( V_121 , & V_180 , V_124 ) )
V_44 = - V_134 ;
else
V_44 = V_181 ;
goto V_128;
}
default:
return - V_82 ;
}
V_182:
F_84 () ;
V_128:
return V_44 ;
}
long F_111 ( int V_162 , char T_6 * V_185 , int V_93 ,
T_7 * V_186 , unsigned long V_187 )
{
struct V_13 * V_14 ;
unsigned long V_69 = ( unsigned long ) V_185 ;
unsigned long V_95 ;
struct V_37 * V_37 ;
int V_44 ;
unsigned long V_88 = V_188 ;
unsigned long V_189 ;
int V_190 ;
struct V_1 * V_2 ;
struct V_39 * V_40 ;
struct V_191 V_191 ;
T_8 V_192 ;
unsigned long V_193 = 0 ;
V_44 = - V_82 ;
if ( V_162 < 0 )
goto V_128;
if ( V_69 ) {
if ( V_69 & ( V_187 - 1 ) ) {
if ( ( V_93 & V_194 ) && V_69 >= V_187 )
V_69 &= ~ ( V_187 - 1 ) ;
else
#ifndef F_112
if ( V_69 & ~ V_195 )
#endif
goto V_128;
}
V_88 |= V_196 ;
} else if ( ( V_93 & V_197 ) )
goto V_128;
if ( V_93 & V_198 ) {
V_189 = V_199 ;
V_190 = V_184 ;
V_192 = V_200 ;
} else {
V_189 = V_199 | V_201 ;
V_190 = V_184 | V_202 ;
V_192 = V_200 | V_203 ;
}
if ( V_93 & V_204 ) {
V_189 |= V_205 ;
V_190 |= V_206 ;
}
V_2 = V_43 -> V_58 -> V_59 ;
F_23 () ;
V_14 = F_18 ( V_2 , V_162 ) ;
if ( F_16 ( V_14 ) ) {
V_44 = F_33 ( V_14 ) ;
goto V_182;
}
V_44 = - V_183 ;
if ( F_109 ( V_2 , & V_14 -> V_15 , V_190 ) )
goto V_182;
V_44 = F_113 ( V_14 , V_185 , V_93 ) ;
if ( V_44 )
goto V_182;
F_24 ( & V_14 -> V_15 ) ;
if ( ! F_114 ( & V_14 -> V_15 ) ) {
F_83 ( & V_14 -> V_15 ) ;
V_44 = - V_207 ;
goto V_182;
}
V_191 = V_14 -> V_45 -> V_208 ;
F_115 ( & V_191 ) ;
V_14 -> V_16 ++ ;
V_95 = F_41 ( F_116 ( V_191 . V_209 ) ) ;
F_83 ( & V_14 -> V_15 ) ;
F_84 () ;
V_44 = - V_102 ;
V_40 = F_117 ( sizeof( * V_40 ) , V_210 ) ;
if ( ! V_40 ) {
F_118 ( & V_191 ) ;
goto V_211;
}
V_37 = F_119 ( & V_191 , V_192 ,
F_38 ( V_14 -> V_45 ) ?
& V_90 :
& V_212 ) ;
V_44 = F_33 ( V_37 ) ;
if ( F_16 ( V_37 ) ) {
F_67 ( V_40 ) ;
F_118 ( & V_191 ) ;
goto V_211;
}
V_37 -> V_213 = V_40 ;
V_37 -> V_214 = V_14 -> V_45 -> V_214 ;
V_40 -> V_27 = V_14 -> V_15 . V_27 ;
V_40 -> V_2 = F_120 ( V_2 ) ;
V_40 -> V_37 = V_14 -> V_45 ;
V_40 -> V_64 = NULL ;
V_44 = F_121 ( V_37 , V_189 , V_88 ) ;
if ( V_44 )
goto V_215;
if ( F_122 ( & V_43 -> V_216 -> V_217 ) ) {
V_44 = - V_218 ;
goto V_215;
}
if ( V_69 && ! ( V_93 & V_197 ) ) {
V_44 = - V_82 ;
if ( V_69 + V_95 < V_69 )
goto V_219;
if ( F_123 ( V_43 -> V_216 , V_69 , V_69 + V_95 ) )
goto V_219;
}
V_69 = F_124 ( V_37 , V_69 , V_95 , V_189 , V_88 , 0 , & V_193 , NULL ) ;
* V_186 = V_69 ;
V_44 = 0 ;
if ( F_125 ( V_69 ) )
V_44 = ( long ) V_69 ;
V_219:
F_48 ( & V_43 -> V_216 -> V_217 ) ;
if ( V_193 )
F_126 ( V_69 , V_193 ) ;
V_215:
F_43 ( V_37 ) ;
V_211:
F_47 ( & F_3 ( V_2 ) . V_50 ) ;
V_14 = F_20 ( V_2 , V_162 ) ;
V_14 -> V_16 -- ;
if ( F_45 ( V_2 , V_14 ) )
F_7 ( V_2 , V_14 ) ;
else
F_6 ( V_14 ) ;
F_48 ( & F_3 ( V_2 ) . V_50 ) ;
return V_44 ;
V_182:
F_84 () ;
V_128:
return V_44 ;
}
static int V_26 ( struct V_220 * V_33 , void * V_221 )
{
struct V_222 * V_223 = F_127 ( V_33 ) ;
struct V_13 * V_14 = V_221 ;
unsigned long V_157 = 0 , V_158 = 0 ;
F_94 ( V_14 , & V_157 , & V_158 ) ;
#if V_25 <= 32
#define F_128 "%10lu"
#else
#define F_128 "%21lu"
#endif
F_129 ( V_33 ,
L_5 F_128 L_6
L_7
F_128 L_8 F_128 L_9 ,
V_14 -> V_15 . V_19 ,
V_14 -> V_15 . V_27 ,
V_14 -> V_15 . V_17 ,
V_14 -> V_46 ,
V_14 -> V_117 ,
V_14 -> V_42 ,
V_14 -> V_16 ,
F_130 ( V_223 , V_14 -> V_15 . V_136 ) ,
F_131 ( V_223 , V_14 -> V_15 . V_137 ) ,
F_130 ( V_223 , V_14 -> V_15 . V_224 ) ,
F_131 ( V_223 , V_14 -> V_15 . V_225 ) ,
V_14 -> V_41 ,
V_14 -> V_52 ,
V_14 -> V_118 ,
V_157 * V_47 ,
V_158 * V_47 ) ;
return 0 ;
}

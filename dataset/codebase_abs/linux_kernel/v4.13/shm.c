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
struct V_11 * V_30 = F_5 ( V_29 , struct V_11 ,
V_31 ) ;
struct V_13 * V_14 = F_5 ( V_30 , struct V_13 ,
V_15 ) ;
F_26 ( V_14 ) ;
F_27 ( V_14 ) ;
}
static inline void F_28 ( struct V_1 * V_2 , struct V_13 * V_32 )
{
F_29 ( & V_32 -> V_33 ) ;
F_30 ( & F_3 ( V_2 ) , & V_32 -> V_15 ) ;
}
static int F_31 ( struct V_34 * V_35 )
{
struct V_36 * V_36 = V_35 -> V_37 ;
struct V_38 * V_39 = V_38 ( V_36 ) ;
struct V_13 * V_14 ;
V_14 = F_20 ( V_39 -> V_2 , V_39 -> V_27 ) ;
if ( F_16 ( V_14 ) )
return F_32 ( V_14 ) ;
V_14 -> V_40 = F_33 () ;
V_14 -> V_41 = F_34 ( V_42 ) ;
V_14 -> V_16 ++ ;
F_6 ( V_14 ) ;
return 0 ;
}
static void F_35 ( struct V_34 * V_35 )
{
int V_43 = F_31 ( V_35 ) ;
F_36 ( V_43 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_36 * V_44 ;
V_44 = V_14 -> V_44 ;
V_14 -> V_44 = NULL ;
V_2 -> V_10 -= ( V_14 -> V_45 + V_46 - 1 ) >> V_47 ;
F_28 ( V_2 , V_14 ) ;
F_6 ( V_14 ) ;
if ( ! F_37 ( V_44 ) )
F_38 ( V_44 , 0 , V_14 -> V_48 ) ;
else if ( V_14 -> V_48 )
F_39 ( F_40 ( F_41 ( V_44 ) ) ,
V_14 -> V_48 ) ;
F_42 ( V_44 ) ;
F_43 ( & V_14 -> V_15 , F_25 ) ;
}
static bool F_44 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
return ( V_14 -> V_16 == 0 ) &&
( V_2 -> V_9 ||
( V_14 -> V_15 . V_17 & V_18 ) ) ;
}
static void F_45 ( struct V_34 * V_35 )
{
struct V_36 * V_36 = V_35 -> V_37 ;
struct V_38 * V_39 = V_38 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_1 * V_2 = V_39 -> V_2 ;
F_46 ( & F_3 ( V_2 ) . V_49 ) ;
V_14 = F_20 ( V_2 , V_39 -> V_27 ) ;
if ( F_36 ( F_16 ( V_14 ) ) )
goto V_50;
V_14 -> V_41 = F_34 ( V_42 ) ;
V_14 -> V_51 = F_33 () ;
V_14 -> V_16 -- ;
if ( F_44 ( V_2 , V_14 ) )
F_7 ( V_2 , V_14 ) ;
else
F_6 ( V_14 ) ;
V_50:
F_47 ( & F_3 ( V_2 ) . V_49 ) ;
}
static int F_48 ( int V_27 , void * V_52 , void * V_53 )
{
struct V_1 * V_2 = V_53 ;
struct V_11 * V_12 = V_52 ;
struct V_13 * V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_54 != NULL )
return 0 ;
if ( F_44 ( V_2 , V_14 ) ) {
F_22 ( V_14 ) ;
F_7 ( V_2 , V_14 ) ;
}
return 0 ;
}
void F_49 ( struct V_1 * V_2 )
{
F_46 ( & F_3 ( V_2 ) . V_49 ) ;
if ( F_3 ( V_2 ) . V_55 )
F_50 ( & F_3 ( V_2 ) . V_23 , & F_48 , V_2 ) ;
F_47 ( & F_3 ( V_2 ) . V_49 ) ;
}
void F_51 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_58 -> V_59 ;
struct V_13 * V_14 , * V_60 ;
if ( F_52 ( & V_57 -> V_61 . V_33 ) )
return;
if ( ! V_2 -> V_9 ) {
F_53 ( & F_3 ( V_2 ) . V_49 ) ;
F_54 (shp, &task->sysvshm.shm_clist, shm_clist)
V_14 -> V_54 = NULL ;
F_29 ( & V_57 -> V_61 . V_33 ) ;
F_55 ( & F_3 ( V_2 ) . V_49 ) ;
return;
}
F_46 ( & F_3 ( V_2 ) . V_49 ) ;
F_56 (shp, n, &task->sysvshm.shm_clist, shm_clist) {
V_14 -> V_54 = NULL ;
if ( F_44 ( V_2 , V_14 ) ) {
F_22 ( V_14 ) ;
F_7 ( V_2 , V_14 ) ;
}
}
F_29 ( & V_57 -> V_61 . V_33 ) ;
F_47 ( & F_3 ( V_2 ) . V_49 ) ;
}
static int F_57 ( struct V_62 * V_63 )
{
struct V_36 * V_36 = V_63 -> V_35 -> V_37 ;
struct V_38 * V_39 = V_38 ( V_36 ) ;
return V_39 -> V_64 -> V_65 ( V_63 ) ;
}
static int F_58 ( struct V_34 * V_35 , struct V_66 * V_67 )
{
struct V_36 * V_36 = V_35 -> V_37 ;
struct V_38 * V_39 = V_38 ( V_36 ) ;
int V_43 = 0 ;
if ( V_39 -> V_64 -> V_68 )
V_43 = V_39 -> V_64 -> V_68 ( V_35 , V_67 ) ;
return V_43 ;
}
static struct V_66 * F_59 ( struct V_34 * V_35 ,
unsigned long V_69 )
{
struct V_36 * V_36 = V_35 -> V_37 ;
struct V_38 * V_39 = V_38 ( V_36 ) ;
struct V_66 * V_70 = NULL ;
if ( V_39 -> V_64 -> V_71 )
V_70 = V_39 -> V_64 -> V_71 ( V_35 , V_69 ) ;
else if ( V_35 -> V_72 )
V_70 = V_35 -> V_72 ;
return V_70 ;
}
static int F_60 ( struct V_36 * V_36 , struct V_34 * V_35 )
{
struct V_38 * V_39 = V_38 ( V_36 ) ;
int V_73 ;
V_73 = F_31 ( V_35 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_61 ( V_39 -> V_36 , V_35 ) ;
if ( V_73 ) {
F_45 ( V_35 ) ;
return V_73 ;
}
V_39 -> V_64 = V_35 -> V_64 ;
#ifdef F_62
F_63 ( ! V_39 -> V_64 -> V_65 ) ;
#endif
V_35 -> V_64 = & V_74 ;
return 0 ;
}
static int F_64 ( struct V_75 * V_76 , struct V_36 * V_36 )
{
struct V_38 * V_39 = V_38 ( V_36 ) ;
F_65 ( V_39 -> V_2 ) ;
V_38 ( V_36 ) = NULL ;
F_66 ( V_39 ) ;
return 0 ;
}
static int F_67 ( struct V_36 * V_36 , T_2 V_77 , T_2 V_78 , int V_79 )
{
struct V_38 * V_39 = V_38 ( V_36 ) ;
if ( ! V_39 -> V_36 -> V_80 -> V_81 )
return - V_82 ;
return V_39 -> V_36 -> V_80 -> V_81 ( V_39 -> V_36 , V_77 , V_78 , V_79 ) ;
}
static long F_68 ( struct V_36 * V_36 , int V_17 , T_2 V_83 ,
T_2 V_84 )
{
struct V_38 * V_39 = V_38 ( V_36 ) ;
if ( ! V_39 -> V_36 -> V_80 -> V_85 )
return - V_86 ;
return V_39 -> V_36 -> V_80 -> V_85 ( V_36 , V_17 , V_83 , V_84 ) ;
}
static unsigned long F_69 ( struct V_36 * V_36 ,
unsigned long V_69 , unsigned long V_84 , unsigned long V_87 ,
unsigned long V_88 )
{
struct V_38 * V_39 = V_38 ( V_36 ) ;
return V_39 -> V_36 -> V_80 -> V_89 ( V_39 -> V_36 , V_69 , V_84 ,
V_87 , V_88 ) ;
}
bool F_70 ( struct V_36 * V_36 )
{
return V_36 -> V_80 == & V_90 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
T_3 V_19 = V_92 -> V_19 ;
int V_93 = V_92 -> V_94 ;
T_4 V_95 = V_92 -> V_96 . V_95 ;
int error ;
struct V_13 * V_14 ;
T_4 V_97 = ( V_95 + V_46 - 1 ) >> V_47 ;
struct V_36 * V_36 ;
char V_98 [ 13 ] ;
T_5 V_99 = 0 ;
if ( V_95 < V_100 || V_95 > V_2 -> V_3 )
return - V_82 ;
if ( V_97 << V_47 < V_95 )
return - V_101 ;
if ( V_2 -> V_10 + V_97 < V_2 -> V_10 ||
V_2 -> V_10 + V_97 > V_2 -> V_5 )
return - V_101 ;
V_14 = F_72 ( sizeof( * V_14 ) , V_102 ) ;
if ( F_73 ( ! V_14 ) )
return - V_103 ;
V_14 -> V_15 . V_19 = V_19 ;
V_14 -> V_15 . V_17 = ( V_93 & V_104 ) ;
V_14 -> V_48 = NULL ;
V_14 -> V_15 . V_105 = NULL ;
error = F_74 ( V_14 ) ;
if ( error ) {
F_27 ( V_14 ) ;
return error ;
}
sprintf ( V_98 , L_4 , V_19 ) ;
if ( V_93 & V_106 ) {
struct V_107 * V_108 ;
T_4 V_109 ;
V_108 = F_75 ( ( V_93 >> V_110 ) & V_111 ) ;
if ( ! V_108 ) {
error = - V_82 ;
goto V_112;
}
V_109 = F_76 ( V_95 , F_77 ( V_108 ) ) ;
if ( V_93 & V_113 )
V_99 = V_114 ;
V_36 = F_78 ( V_98 , V_109 , V_99 ,
& V_14 -> V_48 , V_115 ,
( V_93 >> V_110 ) & V_111 ) ;
} else {
if ( ( V_93 & V_113 ) &&
V_116 != V_117 )
V_99 = V_114 ;
V_36 = F_79 ( V_98 , V_95 , V_99 ) ;
}
error = F_32 ( V_36 ) ;
if ( F_16 ( V_36 ) )
goto V_112;
V_14 -> V_118 = F_34 ( V_42 ) ;
V_14 -> V_41 = 0 ;
V_14 -> V_40 = V_14 -> V_51 = 0 ;
V_14 -> V_119 = F_33 () ;
V_14 -> V_45 = V_95 ;
V_14 -> V_16 = 0 ;
V_14 -> V_44 = V_36 ;
V_14 -> V_54 = V_42 ;
error = F_80 ( & F_3 ( V_2 ) , & V_14 -> V_15 , V_2 -> V_7 ) ;
if ( error < 0 )
goto V_120;
F_81 ( & V_14 -> V_33 , & V_42 -> V_61 . V_33 ) ;
F_41 ( V_36 ) -> V_121 = V_14 -> V_15 . V_27 ;
V_2 -> V_10 += V_97 ;
error = V_14 -> V_15 . V_27 ;
F_82 ( & V_14 -> V_15 ) ;
F_83 () ;
return error ;
V_120:
if ( F_37 ( V_36 ) && V_14 -> V_48 )
F_39 ( V_95 , V_14 -> V_48 ) ;
F_42 ( V_36 ) ;
V_112:
F_84 ( & V_14 -> V_15 . V_31 , F_25 ) ;
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
if ( V_14 -> V_45 < V_92 -> V_96 . V_95 )
return - V_82 ;
return 0 ;
}
static inline unsigned long F_88 ( void T_6 * V_122 , struct V_123 * V_124 , int V_125 )
{
switch ( V_125 ) {
case V_126 :
return F_89 ( V_122 , V_124 , sizeof( * V_124 ) ) ;
case V_127 :
{
struct V_128 V_129 ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
F_90 ( & V_124 -> V_15 , & V_129 . V_15 ) ;
V_129 . V_45 = V_124 -> V_45 ;
V_129 . V_130 = V_124 -> V_130 ;
V_129 . V_131 = V_124 -> V_131 ;
V_129 . V_132 = V_124 -> V_132 ;
V_129 . V_133 = V_124 -> V_133 ;
V_129 . V_134 = V_124 -> V_134 ;
V_129 . V_16 = V_124 -> V_16 ;
return F_89 ( V_122 , & V_129 , sizeof( V_129 ) ) ;
}
default:
return - V_82 ;
}
}
static inline unsigned long
F_91 ( struct V_123 * V_129 , void T_6 * V_122 , int V_125 )
{
switch ( V_125 ) {
case V_126 :
if ( F_92 ( V_129 , V_122 , sizeof( * V_129 ) ) )
return - V_135 ;
return 0 ;
case V_127 :
{
struct V_128 V_136 ;
if ( F_92 ( & V_136 , V_122 , sizeof( V_136 ) ) )
return - V_135 ;
V_129 -> V_15 . V_137 = V_136 . V_15 . V_137 ;
V_129 -> V_15 . V_138 = V_136 . V_15 . V_138 ;
V_129 -> V_15 . V_17 = V_136 . V_15 . V_17 ;
return 0 ;
}
default:
return - V_82 ;
}
}
static inline unsigned long F_93 ( void T_6 * V_122 , struct V_139 * V_124 , int V_125 )
{
switch ( V_125 ) {
case V_126 :
return F_89 ( V_122 , V_124 , sizeof( * V_124 ) ) ;
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
return F_89 ( V_122 , & V_129 , sizeof( V_129 ) ) ;
}
default:
return - V_82 ;
}
}
static void F_94 ( struct V_13 * V_14 ,
unsigned long * V_147 , unsigned long * V_148 )
{
struct V_75 * V_75 ;
V_75 = F_41 ( V_14 -> V_44 ) ;
if ( F_37 ( V_14 -> V_44 ) ) {
struct V_149 * V_150 = V_75 -> V_151 ;
struct V_107 * V_152 = F_95 ( V_14 -> V_44 ) ;
* V_147 += F_96 ( V_152 ) * V_150 -> V_153 ;
} else {
#ifdef F_97
struct V_154 * V_155 = F_98 ( V_75 ) ;
F_99 ( & V_155 -> V_156 ) ;
* V_147 += V_75 -> V_151 -> V_153 ;
* V_148 += V_155 -> V_157 ;
F_100 ( & V_155 -> V_156 ) ;
#else
* V_147 += V_75 -> V_151 -> V_153 ;
#endif
}
}
static void F_101 ( struct V_1 * V_2 , unsigned long * V_158 ,
unsigned long * V_159 )
{
int V_160 ;
int V_161 , V_55 ;
* V_158 = 0 ;
* V_159 = 0 ;
V_55 = F_3 ( V_2 ) . V_55 ;
for ( V_161 = 0 , V_160 = 0 ; V_161 < V_55 ; V_160 ++ ) {
struct V_11 * V_162 ;
struct V_13 * V_14 ;
V_162 = F_102 ( & F_3 ( V_2 ) . V_23 , V_160 ) ;
if ( V_162 == NULL )
continue;
V_14 = F_5 ( V_162 , struct V_13 , V_15 ) ;
F_94 ( V_14 , V_158 , V_159 ) ;
V_161 ++ ;
}
}
static int F_103 ( struct V_1 * V_2 , int V_163 , int V_164 ,
struct V_128 T_6 * V_122 , int V_125 )
{
struct V_11 * V_12 ;
struct V_123 V_165 ;
struct V_13 * V_14 ;
int V_43 ;
if ( V_164 == V_166 ) {
if ( F_91 ( & V_165 , V_122 , V_125 ) )
return - V_135 ;
}
F_46 ( & F_3 ( V_2 ) . V_49 ) ;
F_23 () ;
V_12 = F_104 ( V_2 , & F_3 ( V_2 ) , V_163 , V_164 ,
& V_165 . V_15 , 0 ) ;
if ( F_16 ( V_12 ) ) {
V_43 = F_32 ( V_12 ) ;
goto V_167;
}
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
V_43 = F_105 ( V_14 , V_164 ) ;
if ( V_43 )
goto V_167;
switch ( V_164 ) {
case V_168 :
F_24 ( & V_14 -> V_15 ) ;
F_4 ( V_2 , V_12 ) ;
goto V_169;
case V_166 :
F_24 ( & V_14 -> V_15 ) ;
V_43 = F_106 ( & V_165 . V_15 , V_12 ) ;
if ( V_43 )
goto V_170;
V_14 -> V_119 = F_33 () ;
break;
default:
V_43 = - V_82 ;
goto V_167;
}
V_170:
F_82 ( & V_14 -> V_15 ) ;
V_167:
F_83 () ;
V_169:
F_47 ( & F_3 ( V_2 ) . V_49 ) ;
return V_43 ;
}
static int F_107 ( struct V_1 * V_2 , int V_163 ,
int V_164 , int V_125 , void T_6 * V_122 )
{
int V_43 ;
struct V_13 * V_14 ;
if ( V_164 == V_171 || V_164 == V_172 ) {
V_43 = F_105 ( NULL , V_164 ) ;
if ( V_43 )
return V_43 ;
}
switch ( V_164 ) {
case V_171 :
{
struct V_139 V_140 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_144 = V_140 . V_145 = V_2 -> V_7 ;
V_140 . V_141 = V_2 -> V_3 ;
V_140 . V_146 = V_2 -> V_5 ;
V_140 . V_143 = V_100 ;
if ( F_93 ( V_122 , & V_140 , V_125 ) )
return - V_135 ;
F_53 ( & F_3 ( V_2 ) . V_49 ) ;
V_43 = F_108 ( & F_3 ( V_2 ) ) ;
F_55 ( & F_3 ( V_2 ) . V_49 ) ;
if ( V_43 < 0 )
V_43 = 0 ;
goto V_129;
}
case V_172 :
{
struct V_173 V_173 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
F_53 ( & F_3 ( V_2 ) . V_49 ) ;
V_173 . V_174 = F_3 ( V_2 ) . V_55 ;
F_101 ( V_2 , & V_173 . V_175 , & V_173 . V_176 ) ;
V_173 . V_10 = V_2 -> V_10 ;
V_173 . V_177 = 0 ;
V_173 . V_178 = 0 ;
V_43 = F_108 ( & F_3 ( V_2 ) ) ;
F_55 ( & F_3 ( V_2 ) . V_49 ) ;
if ( F_89 ( V_122 , & V_173 , sizeof( V_173 ) ) ) {
V_43 = - V_135 ;
goto V_129;
}
V_43 = V_43 < 0 ? 0 : V_43 ;
goto V_129;
}
case V_179 :
case V_180 :
{
struct V_123 V_181 ;
int V_182 ;
F_23 () ;
if ( V_164 == V_179 ) {
V_14 = F_14 ( V_2 , V_163 ) ;
if ( F_16 ( V_14 ) ) {
V_43 = F_32 ( V_14 ) ;
goto V_183;
}
V_182 = V_14 -> V_15 . V_27 ;
} else {
V_14 = F_18 ( V_2 , V_163 ) ;
if ( F_16 ( V_14 ) ) {
V_43 = F_32 ( V_14 ) ;
goto V_183;
}
V_182 = 0 ;
}
V_43 = - V_184 ;
if ( F_109 ( V_2 , & V_14 -> V_15 , V_185 ) )
goto V_183;
V_43 = F_105 ( V_14 , V_164 ) ;
if ( V_43 )
goto V_183;
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
F_110 ( & V_14 -> V_15 , & V_181 . V_15 ) ;
V_181 . V_45 = V_14 -> V_45 ;
V_181 . V_130 = V_14 -> V_40 ;
V_181 . V_131 = V_14 -> V_51 ;
V_181 . V_132 = V_14 -> V_119 ;
V_181 . V_133 = V_14 -> V_118 ;
V_181 . V_134 = V_14 -> V_41 ;
V_181 . V_16 = V_14 -> V_16 ;
F_83 () ;
if ( F_88 ( V_122 , & V_181 , V_125 ) )
V_43 = - V_135 ;
else
V_43 = V_182 ;
goto V_129;
}
default:
return - V_82 ;
}
V_183:
F_83 () ;
V_129:
return V_43 ;
}
long F_111 ( int V_163 , char T_6 * V_186 , int V_93 ,
T_7 * V_187 , unsigned long V_188 )
{
struct V_13 * V_14 ;
unsigned long V_69 = ( unsigned long ) V_186 ;
unsigned long V_95 ;
struct V_36 * V_36 ;
int V_43 ;
unsigned long V_88 = V_189 ;
unsigned long V_190 ;
int V_191 ;
struct V_1 * V_2 ;
struct V_38 * V_39 ;
struct V_192 V_192 ;
T_8 V_193 ;
unsigned long V_194 = 0 ;
V_43 = - V_82 ;
if ( V_163 < 0 )
goto V_129;
if ( V_69 ) {
if ( V_69 & ( V_188 - 1 ) ) {
if ( ( V_93 & V_195 ) && V_69 >= V_188 )
V_69 &= ~ ( V_188 - 1 ) ;
else
#ifndef F_112
if ( V_69 & ~ V_196 )
#endif
goto V_129;
}
V_88 |= V_197 ;
} else if ( ( V_93 & V_198 ) )
goto V_129;
if ( V_93 & V_199 ) {
V_190 = V_200 ;
V_191 = V_185 ;
V_193 = V_201 ;
} else {
V_190 = V_200 | V_202 ;
V_191 = V_185 | V_203 ;
V_193 = V_201 | V_204 ;
}
if ( V_93 & V_205 ) {
V_190 |= V_206 ;
V_191 |= V_207 ;
}
V_2 = V_42 -> V_58 -> V_59 ;
F_23 () ;
V_14 = F_18 ( V_2 , V_163 ) ;
if ( F_16 ( V_14 ) ) {
V_43 = F_32 ( V_14 ) ;
goto V_183;
}
V_43 = - V_184 ;
if ( F_109 ( V_2 , & V_14 -> V_15 , V_191 ) )
goto V_183;
V_43 = F_113 ( V_14 , V_186 , V_93 ) ;
if ( V_43 )
goto V_183;
F_24 ( & V_14 -> V_15 ) ;
if ( ! F_114 ( & V_14 -> V_15 ) ) {
F_82 ( & V_14 -> V_15 ) ;
V_43 = - V_208 ;
goto V_183;
}
V_192 = V_14 -> V_44 -> V_209 ;
F_115 ( & V_192 ) ;
V_14 -> V_16 ++ ;
V_95 = F_40 ( F_116 ( V_192 . V_210 ) ) ;
F_82 ( & V_14 -> V_15 ) ;
F_83 () ;
V_43 = - V_103 ;
V_39 = F_117 ( sizeof( * V_39 ) , V_102 ) ;
if ( ! V_39 ) {
F_118 ( & V_192 ) ;
goto V_211;
}
V_36 = F_119 ( & V_192 , V_193 ,
F_37 ( V_14 -> V_44 ) ?
& V_90 :
& V_212 ) ;
V_43 = F_32 ( V_36 ) ;
if ( F_16 ( V_36 ) ) {
F_66 ( V_39 ) ;
F_118 ( & V_192 ) ;
goto V_211;
}
V_36 -> V_213 = V_39 ;
V_36 -> V_214 = V_14 -> V_44 -> V_214 ;
V_39 -> V_27 = V_14 -> V_15 . V_27 ;
V_39 -> V_2 = F_120 ( V_2 ) ;
V_39 -> V_36 = V_14 -> V_44 ;
V_39 -> V_64 = NULL ;
V_43 = F_121 ( V_36 , V_190 , V_88 ) ;
if ( V_43 )
goto V_215;
if ( F_122 ( & V_42 -> V_216 -> V_217 ) ) {
V_43 = - V_218 ;
goto V_215;
}
if ( V_69 && ! ( V_93 & V_198 ) ) {
V_43 = - V_82 ;
if ( V_69 + V_95 < V_69 )
goto V_219;
if ( F_123 ( V_42 -> V_216 , V_69 , V_69 + V_95 ) )
goto V_219;
}
V_69 = F_124 ( V_36 , V_69 , V_95 , V_190 , V_88 , 0 , & V_194 , NULL ) ;
* V_187 = V_69 ;
V_43 = 0 ;
if ( F_125 ( V_69 ) )
V_43 = ( long ) V_69 ;
V_219:
F_47 ( & V_42 -> V_216 -> V_217 ) ;
if ( V_194 )
F_126 ( V_69 , V_194 ) ;
V_215:
F_42 ( V_36 ) ;
V_211:
F_46 ( & F_3 ( V_2 ) . V_49 ) ;
V_14 = F_20 ( V_2 , V_163 ) ;
V_14 -> V_16 -- ;
if ( F_44 ( V_2 , V_14 ) )
F_7 ( V_2 , V_14 ) ;
else
F_6 ( V_14 ) ;
F_47 ( & F_3 ( V_2 ) . V_49 ) ;
return V_43 ;
V_183:
F_83 () ;
V_129:
return V_43 ;
}
static int V_26 ( struct V_220 * V_32 , void * V_221 )
{
struct V_222 * V_223 = F_127 ( V_32 ) ;
struct V_11 * V_12 = V_221 ;
struct V_13 * V_14 ;
unsigned long V_158 = 0 , V_159 = 0 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
F_94 ( V_14 , & V_158 , & V_159 ) ;
#if V_25 <= 32
#define F_128 "%10lu"
#else
#define F_128 "%21lu"
#endif
F_129 ( V_32 ,
L_5 F_128 L_6
L_7
F_128 L_8 F_128 L_9 ,
V_14 -> V_15 . V_19 ,
V_14 -> V_15 . V_27 ,
V_14 -> V_15 . V_17 ,
V_14 -> V_45 ,
V_14 -> V_118 ,
V_14 -> V_41 ,
V_14 -> V_16 ,
F_130 ( V_223 , V_14 -> V_15 . V_137 ) ,
F_131 ( V_223 , V_14 -> V_15 . V_138 ) ,
F_130 ( V_223 , V_14 -> V_15 . V_224 ) ,
F_131 ( V_223 , V_14 -> V_15 . V_225 ) ,
V_14 -> V_40 ,
V_14 -> V_51 ,
V_14 -> V_119 ,
V_158 * V_46 ,
V_159 * V_46 ) ;
return 0 ;
}

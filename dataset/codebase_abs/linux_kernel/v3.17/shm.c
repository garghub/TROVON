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
return (struct V_13 * ) V_12 ;
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
static void F_32 ( struct V_35 * V_36 )
{
struct V_37 * V_37 = V_36 -> V_38 ;
struct V_39 * V_40 = V_39 ( V_37 ) ;
struct V_13 * V_14 ;
V_14 = F_20 ( V_40 -> V_2 , V_40 -> V_27 ) ;
F_33 ( F_16 ( V_14 ) ) ;
V_14 -> V_41 = F_34 () ;
V_14 -> V_42 = F_35 ( V_43 ) ;
V_14 -> V_16 ++ ;
F_6 ( V_14 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_37 * V_44 ;
V_44 = V_14 -> V_44 ;
V_14 -> V_44 = NULL ;
V_2 -> V_10 -= ( V_14 -> V_45 + V_46 - 1 ) >> V_47 ;
F_29 ( V_2 , V_14 ) ;
F_6 ( V_14 ) ;
if ( ! F_36 ( V_44 ) )
F_37 ( V_44 , 0 , V_14 -> V_48 ) ;
else if ( V_14 -> V_48 )
F_38 ( F_39 ( V_44 ) -> V_49 , V_14 -> V_48 ) ;
F_40 ( V_44 ) ;
F_41 ( V_14 , F_25 ) ;
}
static bool F_42 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
return ( V_14 -> V_16 == 0 ) &&
( V_2 -> V_9 ||
( V_14 -> V_15 . V_17 & V_18 ) ) ;
}
static void F_43 ( struct V_35 * V_36 )
{
struct V_37 * V_37 = V_36 -> V_38 ;
struct V_39 * V_40 = V_39 ( V_37 ) ;
struct V_13 * V_14 ;
struct V_1 * V_2 = V_40 -> V_2 ;
F_44 ( & F_3 ( V_2 ) . V_50 ) ;
V_14 = F_20 ( V_2 , V_40 -> V_27 ) ;
F_33 ( F_16 ( V_14 ) ) ;
V_14 -> V_42 = F_35 ( V_43 ) ;
V_14 -> V_51 = F_34 () ;
V_14 -> V_16 -- ;
if ( F_42 ( V_2 , V_14 ) )
F_7 ( V_2 , V_14 ) ;
else
F_6 ( V_14 ) ;
F_45 ( & F_3 ( V_2 ) . V_50 ) ;
}
static int F_46 ( int V_27 , void * V_31 , void * V_52 )
{
struct V_1 * V_2 = V_52 ;
struct V_11 * V_12 = V_31 ;
struct V_13 * V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_53 != NULL )
return 0 ;
if ( F_42 ( V_2 , V_14 ) ) {
F_22 ( V_14 ) ;
F_7 ( V_2 , V_14 ) ;
}
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
F_44 ( & F_3 ( V_2 ) . V_50 ) ;
if ( F_3 ( V_2 ) . V_54 )
F_48 ( & F_3 ( V_2 ) . V_23 , & F_46 , V_2 ) ;
F_45 ( & F_3 ( V_2 ) . V_50 ) ;
}
void F_49 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_57 -> V_58 ;
struct V_13 * V_14 , * V_59 ;
if ( F_50 ( & V_56 -> V_60 . V_34 ) )
return;
if ( ! V_2 -> V_9 ) {
F_51 ( & F_3 ( V_2 ) . V_50 ) ;
F_52 (shp, &task->sysvshm.shm_clist, shm_clist)
V_14 -> V_53 = NULL ;
F_30 ( & V_56 -> V_60 . V_34 ) ;
F_53 ( & F_3 ( V_2 ) . V_50 ) ;
return;
}
F_44 ( & F_3 ( V_2 ) . V_50 ) ;
F_54 (shp, n, &task->sysvshm.shm_clist, shm_clist) {
V_14 -> V_53 = NULL ;
if ( F_42 ( V_2 , V_14 ) ) {
F_22 ( V_14 ) ;
F_7 ( V_2 , V_14 ) ;
}
}
F_30 ( & V_56 -> V_60 . V_34 ) ;
F_45 ( & F_3 ( V_2 ) . V_50 ) ;
}
static int F_55 ( struct V_35 * V_36 , struct V_61 * V_62 )
{
struct V_37 * V_37 = V_36 -> V_38 ;
struct V_39 * V_40 = V_39 ( V_37 ) ;
return V_40 -> V_63 -> V_64 ( V_36 , V_62 ) ;
}
static int F_56 ( struct V_35 * V_36 , struct V_65 * V_66 )
{
struct V_37 * V_37 = V_36 -> V_38 ;
struct V_39 * V_40 = V_39 ( V_37 ) ;
int V_67 = 0 ;
if ( V_40 -> V_63 -> V_68 )
V_67 = V_40 -> V_63 -> V_68 ( V_36 , V_66 ) ;
return V_67 ;
}
static struct V_65 * F_57 ( struct V_35 * V_36 ,
unsigned long V_69 )
{
struct V_37 * V_37 = V_36 -> V_38 ;
struct V_39 * V_40 = V_39 ( V_37 ) ;
struct V_65 * V_70 = NULL ;
if ( V_40 -> V_63 -> V_71 )
V_70 = V_40 -> V_63 -> V_71 ( V_36 , V_69 ) ;
else if ( V_36 -> V_72 )
V_70 = V_36 -> V_72 ;
return V_70 ;
}
static int F_58 ( struct V_37 * V_37 , struct V_35 * V_36 )
{
struct V_39 * V_40 = V_39 ( V_37 ) ;
int V_73 ;
V_73 = V_40 -> V_37 -> V_74 -> V_75 ( V_40 -> V_37 , V_36 ) ;
if ( V_73 != 0 )
return V_73 ;
V_40 -> V_63 = V_36 -> V_63 ;
#ifdef F_59
F_33 ( ! V_40 -> V_63 -> V_64 ) ;
#endif
V_36 -> V_63 = & V_76 ;
F_32 ( V_36 ) ;
return V_73 ;
}
static int F_60 ( struct V_77 * V_78 , struct V_37 * V_37 )
{
struct V_39 * V_40 = V_39 ( V_37 ) ;
F_61 ( V_40 -> V_2 ) ;
V_39 ( V_37 ) = NULL ;
F_62 ( V_40 ) ;
return 0 ;
}
static int F_63 ( struct V_37 * V_37 , T_2 V_79 , T_2 V_80 , int V_81 )
{
struct V_39 * V_40 = V_39 ( V_37 ) ;
if ( ! V_40 -> V_37 -> V_74 -> V_82 )
return - V_83 ;
return V_40 -> V_37 -> V_74 -> V_82 ( V_40 -> V_37 , V_79 , V_80 , V_81 ) ;
}
static long F_64 ( struct V_37 * V_37 , int V_17 , T_2 V_84 ,
T_2 V_85 )
{
struct V_39 * V_40 = V_39 ( V_37 ) ;
if ( ! V_40 -> V_37 -> V_74 -> V_86 )
return - V_87 ;
return V_40 -> V_37 -> V_74 -> V_86 ( V_37 , V_17 , V_84 , V_85 ) ;
}
static unsigned long F_65 ( struct V_37 * V_37 ,
unsigned long V_69 , unsigned long V_85 , unsigned long V_88 ,
unsigned long V_89 )
{
struct V_39 * V_40 = V_39 ( V_37 ) ;
return V_40 -> V_37 -> V_74 -> V_90 ( V_40 -> V_37 , V_69 , V_85 ,
V_88 , V_89 ) ;
}
int F_66 ( struct V_37 * V_37 )
{
return V_37 -> V_74 == & V_91 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
T_3 V_19 = V_93 -> V_19 ;
int V_94 = V_93 -> V_95 ;
T_4 V_96 = V_93 -> V_97 . V_96 ;
int error ;
struct V_13 * V_14 ;
T_4 V_98 = ( V_96 + V_46 - 1 ) >> V_47 ;
struct V_37 * V_37 ;
char V_99 [ 13 ] ;
int V_27 ;
T_5 V_100 = 0 ;
if ( V_96 < V_101 || V_96 > V_2 -> V_3 )
return - V_83 ;
if ( V_98 << V_47 < V_96 )
return - V_102 ;
if ( V_2 -> V_10 + V_98 < V_2 -> V_10 ||
V_2 -> V_10 + V_98 > V_2 -> V_5 )
return - V_102 ;
V_14 = F_68 ( sizeof( * V_14 ) ) ;
if ( ! V_14 )
return - V_103 ;
V_14 -> V_15 . V_19 = V_19 ;
V_14 -> V_15 . V_17 = ( V_94 & V_104 ) ;
V_14 -> V_48 = NULL ;
V_14 -> V_15 . V_105 = NULL ;
error = F_69 ( V_14 ) ;
if ( error ) {
F_41 ( V_14 , F_28 ) ;
return error ;
}
sprintf ( V_99 , L_4 , V_19 ) ;
if ( V_94 & V_106 ) {
struct V_107 * V_108 ;
T_4 V_109 ;
V_108 = F_70 ( ( V_94 >> V_110 ) & V_111 ) ;
if ( ! V_108 ) {
error = - V_83 ;
goto V_112;
}
V_109 = F_71 ( V_96 , F_72 ( V_108 ) ) ;
if ( V_94 & V_113 )
V_100 = V_114 ;
V_37 = F_73 ( V_99 , V_109 , V_100 ,
& V_14 -> V_48 , V_115 ,
( V_94 >> V_110 ) & V_111 ) ;
} else {
if ( ( V_94 & V_113 ) &&
V_116 != V_117 )
V_100 = V_114 ;
V_37 = F_74 ( V_99 , V_96 , V_100 ) ;
}
error = F_75 ( V_37 ) ;
if ( F_16 ( V_37 ) )
goto V_112;
V_27 = F_76 ( & F_3 ( V_2 ) , & V_14 -> V_15 , V_2 -> V_7 ) ;
if ( V_27 < 0 ) {
error = V_27 ;
goto V_118;
}
V_14 -> V_119 = F_35 ( V_43 ) ;
V_14 -> V_42 = 0 ;
V_14 -> V_41 = V_14 -> V_51 = 0 ;
V_14 -> V_120 = F_34 () ;
V_14 -> V_45 = V_96 ;
V_14 -> V_16 = 0 ;
V_14 -> V_44 = V_37 ;
V_14 -> V_53 = V_43 ;
F_77 ( & V_14 -> V_34 , & V_43 -> V_60 . V_34 ) ;
F_39 ( V_37 ) -> V_121 = V_14 -> V_15 . V_27 ;
V_2 -> V_10 += V_98 ;
error = V_14 -> V_15 . V_27 ;
F_78 ( & V_14 -> V_15 ) ;
F_79 () ;
return error ;
V_118:
if ( F_36 ( V_37 ) && V_14 -> V_48 )
F_38 ( V_96 , V_14 -> V_48 ) ;
F_40 ( V_37 ) ;
V_112:
F_41 ( V_14 , F_25 ) ;
return error ;
}
static inline int F_80 ( struct V_11 * V_12 , int V_94 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
return F_81 ( V_14 , V_94 ) ;
}
static inline int F_82 ( struct V_11 * V_12 ,
struct V_92 * V_93 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_45 < V_93 -> V_97 . V_96 )
return - V_83 ;
return 0 ;
}
static inline unsigned long F_83 ( void T_6 * V_122 , struct V_123 * V_124 , int V_125 )
{
switch ( V_125 ) {
case V_126 :
return F_84 ( V_122 , V_124 , sizeof( * V_124 ) ) ;
case V_127 :
{
struct V_128 V_129 ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
F_85 ( & V_124 -> V_15 , & V_129 . V_15 ) ;
V_129 . V_45 = V_124 -> V_45 ;
V_129 . V_130 = V_124 -> V_130 ;
V_129 . V_131 = V_124 -> V_131 ;
V_129 . V_132 = V_124 -> V_132 ;
V_129 . V_133 = V_124 -> V_133 ;
V_129 . V_134 = V_124 -> V_134 ;
V_129 . V_16 = V_124 -> V_16 ;
return F_84 ( V_122 , & V_129 , sizeof( V_129 ) ) ;
}
default:
return - V_83 ;
}
}
static inline unsigned long
F_86 ( struct V_123 * V_129 , void T_6 * V_122 , int V_125 )
{
switch ( V_125 ) {
case V_126 :
if ( F_87 ( V_129 , V_122 , sizeof( * V_129 ) ) )
return - V_135 ;
return 0 ;
case V_127 :
{
struct V_128 V_136 ;
if ( F_87 ( & V_136 , V_122 , sizeof( V_136 ) ) )
return - V_135 ;
V_129 -> V_15 . V_137 = V_136 . V_15 . V_137 ;
V_129 -> V_15 . V_138 = V_136 . V_15 . V_138 ;
V_129 -> V_15 . V_17 = V_136 . V_15 . V_17 ;
return 0 ;
}
default:
return - V_83 ;
}
}
static inline unsigned long F_88 ( void T_6 * V_122 , struct V_139 * V_124 , int V_125 )
{
switch ( V_125 ) {
case V_126 :
return F_84 ( V_122 , V_124 , sizeof( * V_124 ) ) ;
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
return F_84 ( V_122 , & V_129 , sizeof( V_129 ) ) ;
}
default:
return - V_83 ;
}
}
static void F_89 ( struct V_13 * V_14 ,
unsigned long * V_147 , unsigned long * V_148 )
{
struct V_77 * V_77 ;
V_77 = F_39 ( V_14 -> V_44 ) ;
if ( F_36 ( V_14 -> V_44 ) ) {
struct V_149 * V_150 = V_77 -> V_151 ;
struct V_107 * V_152 = F_90 ( V_14 -> V_44 ) ;
* V_147 += F_91 ( V_152 ) * V_150 -> V_153 ;
} else {
#ifdef F_92
struct V_154 * V_155 = F_93 ( V_77 ) ;
F_94 ( & V_155 -> V_156 ) ;
* V_147 += V_77 -> V_151 -> V_153 ;
* V_148 += V_155 -> V_157 ;
F_95 ( & V_155 -> V_156 ) ;
#else
* V_147 += V_77 -> V_151 -> V_153 ;
#endif
}
}
static void F_96 ( struct V_1 * V_2 , unsigned long * V_158 ,
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
V_162 = F_97 ( & F_3 ( V_2 ) . V_23 , V_160 ) ;
if ( V_162 == NULL )
continue;
V_14 = F_5 ( V_162 , struct V_13 , V_15 ) ;
F_89 ( V_14 , V_158 , V_159 ) ;
V_161 ++ ;
}
}
static int F_98 ( struct V_1 * V_2 , int V_163 , int V_164 ,
struct V_128 T_6 * V_122 , int V_125 )
{
struct V_11 * V_12 ;
struct V_123 V_165 ;
struct V_13 * V_14 ;
int V_67 ;
if ( V_164 == V_166 ) {
if ( F_86 ( & V_165 , V_122 , V_125 ) )
return - V_135 ;
}
F_44 ( & F_3 ( V_2 ) . V_50 ) ;
F_23 () ;
V_12 = F_99 ( V_2 , & F_3 ( V_2 ) , V_163 , V_164 ,
& V_165 . V_15 , 0 ) ;
if ( F_16 ( V_12 ) ) {
V_67 = F_75 ( V_12 ) ;
goto V_167;
}
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
V_67 = F_100 ( V_14 , V_164 ) ;
if ( V_67 )
goto V_167;
switch ( V_164 ) {
case V_168 :
F_24 ( & V_14 -> V_15 ) ;
F_4 ( V_2 , V_12 ) ;
goto V_169;
case V_166 :
F_24 ( & V_14 -> V_15 ) ;
V_67 = F_101 ( & V_165 . V_15 , V_12 ) ;
if ( V_67 )
goto V_170;
V_14 -> V_120 = F_34 () ;
break;
default:
V_67 = - V_83 ;
goto V_167;
}
V_170:
F_78 ( & V_14 -> V_15 ) ;
V_167:
F_79 () ;
V_169:
F_45 ( & F_3 ( V_2 ) . V_50 ) ;
return V_67 ;
}
static int F_102 ( struct V_1 * V_2 , int V_163 ,
int V_164 , int V_125 , void T_6 * V_122 )
{
int V_67 ;
struct V_13 * V_14 ;
if ( V_164 == V_171 || V_164 == V_172 ) {
V_67 = F_100 ( NULL , V_164 ) ;
if ( V_67 )
return V_67 ;
}
switch ( V_164 ) {
case V_171 :
{
struct V_139 V_140 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_144 = V_140 . V_145 = V_2 -> V_7 ;
V_140 . V_141 = V_2 -> V_3 ;
V_140 . V_146 = V_2 -> V_5 ;
V_140 . V_143 = V_101 ;
if ( F_88 ( V_122 , & V_140 , V_125 ) )
return - V_135 ;
F_51 ( & F_3 ( V_2 ) . V_50 ) ;
V_67 = F_103 ( & F_3 ( V_2 ) ) ;
F_53 ( & F_3 ( V_2 ) . V_50 ) ;
if ( V_67 < 0 )
V_67 = 0 ;
goto V_129;
}
case V_172 :
{
struct V_173 V_173 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
F_51 ( & F_3 ( V_2 ) . V_50 ) ;
V_173 . V_174 = F_3 ( V_2 ) . V_54 ;
F_96 ( V_2 , & V_173 . V_175 , & V_173 . V_176 ) ;
V_173 . V_10 = V_2 -> V_10 ;
V_173 . V_177 = 0 ;
V_173 . V_178 = 0 ;
V_67 = F_103 ( & F_3 ( V_2 ) ) ;
F_53 ( & F_3 ( V_2 ) . V_50 ) ;
if ( F_84 ( V_122 , & V_173 , sizeof( V_173 ) ) ) {
V_67 = - V_135 ;
goto V_129;
}
V_67 = V_67 < 0 ? 0 : V_67 ;
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
V_67 = F_75 ( V_14 ) ;
goto V_183;
}
V_182 = V_14 -> V_15 . V_27 ;
} else {
V_14 = F_18 ( V_2 , V_163 ) ;
if ( F_16 ( V_14 ) ) {
V_67 = F_75 ( V_14 ) ;
goto V_183;
}
V_182 = 0 ;
}
V_67 = - V_184 ;
if ( F_104 ( V_2 , & V_14 -> V_15 , V_185 ) )
goto V_183;
V_67 = F_100 ( V_14 , V_164 ) ;
if ( V_67 )
goto V_183;
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
F_105 ( & V_14 -> V_15 , & V_181 . V_15 ) ;
V_181 . V_45 = V_14 -> V_45 ;
V_181 . V_130 = V_14 -> V_41 ;
V_181 . V_131 = V_14 -> V_51 ;
V_181 . V_132 = V_14 -> V_120 ;
V_181 . V_133 = V_14 -> V_119 ;
V_181 . V_134 = V_14 -> V_42 ;
V_181 . V_16 = V_14 -> V_16 ;
F_79 () ;
if ( F_83 ( V_122 , & V_181 , V_125 ) )
V_67 = - V_135 ;
else
V_67 = V_182 ;
goto V_129;
}
default:
return - V_83 ;
}
V_183:
F_79 () ;
V_129:
return V_67 ;
}
long F_106 ( int V_163 , char T_6 * V_186 , int V_94 , T_7 * V_187 ,
unsigned long V_188 )
{
struct V_13 * V_14 ;
unsigned long V_69 ;
unsigned long V_96 ;
struct V_37 * V_37 ;
int V_67 ;
unsigned long V_89 ;
unsigned long V_189 ;
int V_190 ;
struct V_1 * V_2 ;
struct V_39 * V_40 ;
struct V_191 V_191 ;
T_8 V_192 ;
unsigned long V_193 = 0 ;
V_67 = - V_83 ;
if ( V_163 < 0 )
goto V_129;
else if ( ( V_69 = ( T_7 ) V_186 ) ) {
if ( V_69 & ( V_188 - 1 ) ) {
if ( V_94 & V_194 )
V_69 &= ~ ( V_188 - 1 ) ;
else
#ifndef F_107
if ( V_69 & ~ V_195 )
#endif
goto V_129;
}
V_89 = V_196 | V_197 ;
} else {
if ( ( V_94 & V_198 ) )
goto V_129;
V_89 = V_196 ;
}
if ( V_94 & V_199 ) {
V_189 = V_200 ;
V_190 = V_185 ;
V_192 = V_201 ;
} else {
V_189 = V_200 | V_202 ;
V_190 = V_185 | V_203 ;
V_192 = V_201 | V_204 ;
}
if ( V_94 & V_205 ) {
V_189 |= V_206 ;
V_190 |= V_207 ;
}
V_2 = V_43 -> V_57 -> V_58 ;
F_23 () ;
V_14 = F_18 ( V_2 , V_163 ) ;
if ( F_16 ( V_14 ) ) {
V_67 = F_75 ( V_14 ) ;
goto V_183;
}
V_67 = - V_184 ;
if ( F_104 ( V_2 , & V_14 -> V_15 , V_190 ) )
goto V_183;
V_67 = F_108 ( V_14 , V_186 , V_94 ) ;
if ( V_67 )
goto V_183;
F_24 ( & V_14 -> V_15 ) ;
if ( ! F_109 ( & V_14 -> V_15 ) ) {
F_78 ( & V_14 -> V_15 ) ;
V_67 = - V_208 ;
goto V_183;
}
V_191 = V_14 -> V_44 -> V_209 ;
F_110 ( & V_191 ) ;
V_14 -> V_16 ++ ;
V_96 = F_111 ( V_191 . V_210 -> V_211 ) ;
F_78 ( & V_14 -> V_15 ) ;
F_79 () ;
V_67 = - V_103 ;
V_40 = F_112 ( sizeof( * V_40 ) , V_212 ) ;
if ( ! V_40 ) {
F_113 ( & V_191 ) ;
goto V_213;
}
V_37 = F_114 ( & V_191 , V_192 ,
F_36 ( V_14 -> V_44 ) ?
& V_91 :
& V_214 ) ;
V_67 = F_75 ( V_37 ) ;
if ( F_16 ( V_37 ) ) {
F_62 ( V_40 ) ;
F_113 ( & V_191 ) ;
goto V_213;
}
V_37 -> V_215 = V_40 ;
V_37 -> V_216 = V_14 -> V_44 -> V_216 ;
V_40 -> V_27 = V_14 -> V_15 . V_27 ;
V_40 -> V_2 = F_115 ( V_2 ) ;
V_40 -> V_37 = V_14 -> V_44 ;
V_40 -> V_63 = NULL ;
V_67 = F_116 ( V_37 , V_189 , V_89 ) ;
if ( V_67 )
goto V_217;
F_44 ( & V_43 -> V_218 -> V_219 ) ;
if ( V_69 && ! ( V_94 & V_198 ) ) {
V_67 = - V_83 ;
if ( V_69 + V_96 < V_69 )
goto V_220;
if ( F_117 ( V_43 -> V_218 , V_69 , V_69 + V_96 ) )
goto V_220;
if ( V_69 < V_43 -> V_218 -> V_221 &&
V_69 > V_43 -> V_218 -> V_221 - V_96 - V_46 * 5 )
goto V_220;
}
V_69 = F_118 ( V_37 , V_69 , V_96 , V_189 , V_89 , 0 , & V_193 ) ;
* V_187 = V_69 ;
V_67 = 0 ;
if ( F_119 ( V_69 ) )
V_67 = ( long ) V_69 ;
V_220:
F_45 ( & V_43 -> V_218 -> V_219 ) ;
if ( V_193 )
F_120 ( V_69 , V_193 ) ;
V_217:
F_40 ( V_37 ) ;
V_213:
F_44 ( & F_3 ( V_2 ) . V_50 ) ;
V_14 = F_20 ( V_2 , V_163 ) ;
F_33 ( F_16 ( V_14 ) ) ;
V_14 -> V_16 -- ;
if ( F_42 ( V_2 , V_14 ) )
F_7 ( V_2 , V_14 ) ;
else
F_6 ( V_14 ) ;
F_45 ( & F_3 ( V_2 ) . V_50 ) ;
return V_67 ;
V_183:
F_79 () ;
V_129:
return V_67 ;
}
static int V_26 ( struct V_222 * V_33 , void * V_223 )
{
struct V_224 * V_225 = F_121 ( V_33 ) ;
struct V_13 * V_14 = V_223 ;
unsigned long V_158 = 0 , V_159 = 0 ;
F_89 ( V_14 , & V_158 , & V_159 ) ;
#if V_25 <= 32
#define F_122 "%10lu"
#else
#define F_122 "%21lu"
#endif
return F_123 ( V_33 ,
L_5 F_122 L_6
L_7
F_122 L_8 F_122 L_9 ,
V_14 -> V_15 . V_19 ,
V_14 -> V_15 . V_27 ,
V_14 -> V_15 . V_17 ,
V_14 -> V_45 ,
V_14 -> V_119 ,
V_14 -> V_42 ,
V_14 -> V_16 ,
F_124 ( V_225 , V_14 -> V_15 . V_137 ) ,
F_125 ( V_225 , V_14 -> V_15 . V_138 ) ,
F_124 ( V_225 , V_14 -> V_15 . V_226 ) ,
F_125 ( V_225 , V_14 -> V_15 . V_227 ) ,
V_14 -> V_41 ,
V_14 -> V_51 ,
V_14 -> V_120 ,
V_158 * V_46 ,
V_159 * V_46 ) ;
}

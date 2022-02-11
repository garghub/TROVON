static bool F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
return F_2 ( V_2 ) || V_4 != V_5 ;
}
static bool F_3 ( struct V_6 * V_7 )
{
if ( ! F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) )
return true ;
return V_7 -> V_10 ;
}
static inline void F_4 ( struct V_6 * V_7 )
{
if ( V_7 -> V_11 )
F_5 ( V_7 ) ;
V_7 -> V_12 = false ;
V_7 -> V_13 = V_14 ;
}
static void F_6 ( struct V_15 * V_16 ,
T_1 V_17 )
{
F_7 ( & V_16 -> V_18 . V_19 ) ;
V_16 -> V_18 . V_20 ++ ;
V_16 -> V_18 . V_21 += V_17 ;
F_8 ( & V_16 -> V_18 . V_19 ) ;
}
static void F_9 ( struct V_15 * V_16 ,
T_1 V_17 )
{
F_7 ( & V_16 -> V_18 . V_19 ) ;
V_16 -> V_18 . V_20 -- ;
V_16 -> V_18 . V_21 -= V_17 ;
F_8 ( & V_16 -> V_18 . V_19 ) ;
}
static int
F_10 ( struct V_22 * error )
{
int V_23 ;
#define F_11 (!i915_reset_in_progress(error) || \
i915_terminally_wedged(error))
if ( F_11 )
return 0 ;
V_23 = F_12 ( error -> V_24 ,
F_11 ,
10 * V_25 ) ;
if ( V_23 == 0 ) {
F_13 ( L_1 ) ;
return - V_26 ;
} else if ( V_23 < 0 ) {
return V_23 ;
}
#undef F_11
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
V_23 = F_10 ( & V_16 -> V_28 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_15 ( & V_2 -> V_29 ) ;
if ( V_23 )
return V_23 ;
F_16 ( F_17 ( V_2 ) ) ;
return 0 ;
}
static inline bool
F_18 ( struct V_6 * V_7 )
{
return F_19 ( V_7 ) && ! V_7 -> V_30 ;
}
int
F_20 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_34 * args = V_31 ;
if ( F_21 ( V_2 , V_35 ) )
return - V_36 ;
if ( args -> V_37 >= args -> V_38 ||
( args -> V_38 | args -> V_37 ) & ( V_39 - 1 ) )
return - V_40 ;
if ( F_22 ( V_2 ) -> V_41 >= 5 )
return - V_36 ;
F_23 ( & V_2 -> V_29 ) ;
F_24 ( V_2 , args -> V_37 , args -> V_38 ,
args -> V_38 ) ;
V_16 -> V_42 . V_43 = args -> V_38 ;
F_25 ( & V_2 -> V_29 ) ;
return 0 ;
}
int
F_26 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_44 * args = V_31 ;
struct V_6 * V_7 ;
T_1 V_45 ;
V_45 = 0 ;
F_23 ( & V_2 -> V_29 ) ;
F_27 (obj, &dev_priv->mm.bound_list, global_list)
if ( V_7 -> V_46 )
V_45 += F_28 ( V_7 ) ;
F_25 ( & V_2 -> V_29 ) ;
args -> V_47 = V_16 -> V_42 . V_8 . V_48 ;
args -> V_49 = args -> V_47 - V_45 ;
return 0 ;
}
void * F_29 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
return F_30 ( V_16 -> V_50 , V_51 ) ;
}
void F_31 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
F_32 ( V_16 -> V_50 , V_7 ) ;
}
static int
F_33 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_2 V_17 ,
T_3 * V_52 )
{
struct V_6 * V_7 ;
int V_23 ;
T_4 V_53 ;
V_17 = F_34 ( V_17 , V_39 ) ;
if ( V_17 == 0 )
return - V_40 ;
V_7 = F_35 ( V_2 , V_17 ) ;
if ( V_7 == NULL )
return - V_54 ;
V_23 = F_36 ( V_33 , & V_7 -> V_8 , & V_53 ) ;
F_37 ( & V_7 -> V_8 ) ;
if ( V_23 )
return V_23 ;
* V_52 = V_53 ;
return 0 ;
}
int
F_38 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
struct V_55 * args )
{
args -> V_56 = F_39 ( args -> V_57 * F_40 ( args -> V_58 , 8 ) , 64 ) ;
args -> V_17 = args -> V_56 * args -> V_59 ;
return F_33 ( V_33 , V_2 ,
args -> V_17 , & args -> V_53 ) ;
}
int
F_41 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_60 * args = V_31 ;
return F_33 ( V_33 , V_2 ,
args -> V_17 , & args -> V_53 ) ;
}
static inline int
F_42 ( char T_5 * V_61 ,
const char * V_62 , int V_63 ,
int V_64 )
{
int V_23 , V_65 = 0 ;
while ( V_64 > 0 ) {
int V_66 = F_39 ( V_63 + 1 , 64 ) ;
int V_67 = F_43 ( V_66 - V_63 , V_64 ) ;
int V_68 = V_63 ^ 64 ;
V_23 = F_44 ( V_61 + V_65 ,
V_62 + V_68 ,
V_67 ) ;
if ( V_23 )
return V_23 + V_64 ;
V_65 += V_67 ;
V_63 += V_67 ;
V_64 -= V_67 ;
}
return 0 ;
}
static inline int
F_45 ( char * V_62 , int V_63 ,
const char T_5 * V_61 ,
int V_64 )
{
int V_23 , V_65 = 0 ;
while ( V_64 > 0 ) {
int V_66 = F_39 ( V_63 + 1 , 64 ) ;
int V_67 = F_43 ( V_66 - V_63 , V_64 ) ;
int V_68 = V_63 ^ 64 ;
V_23 = F_46 ( V_62 + V_68 ,
V_61 + V_65 ,
V_67 ) ;
if ( V_23 )
return V_23 + V_64 ;
V_65 += V_67 ;
V_63 += V_67 ;
V_64 -= V_67 ;
}
return 0 ;
}
static int
F_47 ( struct V_69 * V_69 , int V_70 , int V_71 ,
char T_5 * V_72 ,
bool V_73 , bool V_74 )
{
char * V_75 ;
int V_23 ;
if ( F_48 ( V_73 ) )
return - V_40 ;
V_75 = F_49 ( V_69 ) ;
if ( V_74 )
F_50 ( V_75 + V_70 ,
V_71 ) ;
V_23 = F_51 ( V_72 ,
V_75 + V_70 ,
V_71 ) ;
F_52 ( V_75 ) ;
return V_23 ? - V_76 : 0 ;
}
static void
F_53 ( char * V_77 , unsigned long V_64 ,
bool V_78 )
{
if ( F_48 ( V_78 ) ) {
unsigned long V_79 = ( unsigned long ) V_77 ;
unsigned long V_80 = ( unsigned long ) V_77 + V_64 ;
V_79 = F_54 ( V_79 , 128 ) ;
V_80 = F_55 ( V_80 , 128 ) ;
F_50 ( ( void * ) V_79 , V_80 - V_79 ) ;
} else {
F_50 ( V_77 , V_64 ) ;
}
}
static int
F_56 ( struct V_69 * V_69 , int V_70 , int V_71 ,
char T_5 * V_72 ,
bool V_73 , bool V_74 )
{
char * V_75 ;
int V_23 ;
V_75 = F_57 ( V_69 ) ;
if ( V_74 )
F_53 ( V_75 + V_70 ,
V_71 ,
V_73 ) ;
if ( V_73 )
V_23 = F_42 ( V_72 ,
V_75 , V_70 ,
V_71 ) ;
else
V_23 = F_44 ( V_72 ,
V_75 + V_70 ,
V_71 ) ;
F_58 ( V_69 ) ;
return V_23 ? - V_76 : 0 ;
}
static int
F_59 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_81 * args ,
struct V_32 * V_33 )
{
char T_5 * V_72 ;
T_6 V_82 ;
T_7 V_83 ;
int V_70 , V_71 , V_23 = 0 ;
int V_84 , V_73 ;
int V_85 = 0 ;
int V_74 = 0 ;
struct V_86 V_87 ;
V_72 = F_60 ( args -> V_88 ) ;
V_82 = args -> V_17 ;
V_84 = F_61 ( V_7 ) ;
if ( ! ( V_7 -> V_8 . V_89 & V_90 ) ) {
V_74 = ! F_1 ( V_2 , V_7 -> V_9 ) ;
V_23 = F_62 ( V_7 , true ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_63 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_64 ( V_7 ) ;
V_83 = args -> V_83 ;
F_65 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_69 * V_69 = F_66 ( & V_87 ) ;
if ( V_82 <= 0 )
break;
V_70 = F_67 ( V_83 ) ;
V_71 = V_82 ;
if ( ( V_70 + V_71 ) > V_39 )
V_71 = V_39 - V_70 ;
V_73 = V_84 &&
( F_68 ( V_69 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_47 ( V_69 , V_70 , V_71 ,
V_72 , V_73 ,
V_74 ) ;
if ( V_23 == 0 )
goto V_91;
F_25 ( & V_2 -> V_29 ) ;
if ( F_69 ( ! V_92 ) && ! V_85 ) {
V_23 = F_70 ( V_72 , V_82 ) ;
( void ) V_23 ;
V_85 = 1 ;
}
V_23 = F_56 ( V_69 , V_70 , V_71 ,
V_72 , V_73 ,
V_74 ) ;
F_23 ( & V_2 -> V_29 ) ;
V_91:
F_71 ( V_69 ) ;
if ( V_23 )
goto V_93;
V_82 -= V_71 ;
V_72 += V_71 ;
V_83 += V_71 ;
}
V_93:
F_72 ( V_7 ) ;
return V_23 ;
}
int
F_73 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_81 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_74 ( V_94 ,
F_60 ( args -> V_88 ) ,
args -> V_17 ) )
return - V_76 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( args -> V_83 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_83 ) {
V_23 = - V_40 ;
goto V_93;
}
if ( ! V_7 -> V_8 . V_97 ) {
V_23 = - V_40 ;
goto V_93;
}
F_77 ( V_7 , args -> V_83 , args -> V_17 ) ;
V_23 = F_59 ( V_2 , V_7 , args , V_33 ) ;
V_93:
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static inline int
F_79 ( struct V_98 * V_99 ,
T_7 V_100 , int V_101 ,
char T_5 * V_72 ,
int V_64 )
{
void T_8 * V_102 ;
void * V_75 ;
unsigned long V_103 ;
V_102 = F_80 ( V_99 , V_100 ) ;
V_75 = ( void V_104 * ) V_102 + V_101 ;
V_103 = F_81 ( V_75 ,
V_72 , V_64 ) ;
F_82 ( V_102 ) ;
return V_103 ;
}
static int
F_83 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_105 * args ,
struct V_32 * V_33 )
{
T_9 * V_16 = V_2 -> V_27 ;
T_6 V_82 ;
T_7 V_83 , V_100 ;
char T_5 * V_72 ;
int V_101 , V_71 , V_23 ;
V_23 = F_84 ( V_7 , 0 , true , true ) ;
if ( V_23 )
goto V_93;
V_23 = F_85 ( V_7 , true ) ;
if ( V_23 )
goto V_106;
V_23 = F_86 ( V_7 ) ;
if ( V_23 )
goto V_106;
V_72 = F_60 ( args -> V_88 ) ;
V_82 = args -> V_17 ;
V_83 = F_87 ( V_7 ) + args -> V_83 ;
while ( V_82 > 0 ) {
V_100 = V_83 & V_107 ;
V_101 = F_67 ( V_83 ) ;
V_71 = V_82 ;
if ( ( V_101 + V_82 ) > V_39 )
V_71 = V_39 - V_101 ;
if ( F_79 ( V_16 -> V_42 . V_108 , V_100 ,
V_101 , V_72 , V_71 ) ) {
V_23 = - V_76 ;
goto V_106;
}
V_82 -= V_71 ;
V_72 += V_71 ;
V_83 += V_71 ;
}
V_106:
F_88 ( V_7 ) ;
V_93:
return V_23 ;
}
static int
F_89 ( struct V_69 * V_69 , int V_70 , int V_71 ,
char T_5 * V_72 ,
bool V_73 ,
bool V_109 ,
bool V_110 )
{
char * V_75 ;
int V_23 ;
if ( F_48 ( V_73 ) )
return - V_40 ;
V_75 = F_49 ( V_69 ) ;
if ( V_109 )
F_50 ( V_75 + V_70 ,
V_71 ) ;
V_23 = F_81 ( V_75 + V_70 ,
V_72 ,
V_71 ) ;
if ( V_110 )
F_50 ( V_75 + V_70 ,
V_71 ) ;
F_52 ( V_75 ) ;
return V_23 ? - V_76 : 0 ;
}
static int
F_90 ( struct V_69 * V_69 , int V_70 , int V_71 ,
char T_5 * V_72 ,
bool V_73 ,
bool V_109 ,
bool V_110 )
{
char * V_75 ;
int V_23 ;
V_75 = F_57 ( V_69 ) ;
if ( F_48 ( V_109 || V_73 ) )
F_53 ( V_75 + V_70 ,
V_71 ,
V_73 ) ;
if ( V_73 )
V_23 = F_45 ( V_75 , V_70 ,
V_72 ,
V_71 ) ;
else
V_23 = F_46 ( V_75 + V_70 ,
V_72 ,
V_71 ) ;
if ( V_110 )
F_53 ( V_75 + V_70 ,
V_71 ,
V_73 ) ;
F_58 ( V_69 ) ;
return V_23 ? - V_76 : 0 ;
}
static int
F_91 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_105 * args ,
struct V_32 * V_33 )
{
T_6 V_82 ;
T_7 V_83 ;
char T_5 * V_72 ;
int V_70 , V_71 , V_23 = 0 ;
int V_84 , V_73 ;
int V_111 = 0 ;
int V_110 = 0 ;
int V_109 = 0 ;
struct V_86 V_87 ;
V_72 = F_60 ( args -> V_88 ) ;
V_82 = args -> V_17 ;
V_84 = F_61 ( V_7 ) ;
if ( V_7 -> V_8 . V_112 != V_90 ) {
V_110 = F_3 ( V_7 ) ;
V_23 = F_62 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
}
if ( ( V_7 -> V_8 . V_89 & V_90 ) == 0 )
V_109 =
! F_1 ( V_2 , V_7 -> V_9 ) ;
V_23 = F_63 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_64 ( V_7 ) ;
V_83 = args -> V_83 ;
V_7 -> V_113 = 1 ;
F_65 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_69 * V_69 = F_66 ( & V_87 ) ;
int V_114 ;
if ( V_82 <= 0 )
break;
V_70 = F_67 ( V_83 ) ;
V_71 = V_82 ;
if ( ( V_70 + V_71 ) > V_39 )
V_71 = V_39 - V_70 ;
V_114 = V_109 &&
( ( V_70 | V_71 )
& ( V_115 . V_116 - 1 ) ) ;
V_73 = V_84 &&
( F_68 ( V_69 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_89 ( V_69 , V_70 , V_71 ,
V_72 , V_73 ,
V_114 ,
V_110 ) ;
if ( V_23 == 0 )
goto V_91;
V_111 = 1 ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_90 ( V_69 , V_70 , V_71 ,
V_72 , V_73 ,
V_114 ,
V_110 ) ;
F_23 ( & V_2 -> V_29 ) ;
V_91:
F_92 ( V_69 ) ;
F_71 ( V_69 ) ;
if ( V_23 )
goto V_93;
V_82 -= V_71 ;
V_72 += V_71 ;
V_83 += V_71 ;
}
V_93:
F_72 ( V_7 ) ;
if ( V_111 ) {
if ( ! V_110 &&
V_7 -> V_8 . V_112 != V_90 ) {
if ( F_93 ( V_7 , V_7 -> V_10 ) )
F_94 ( V_2 ) ;
}
}
if ( V_110 )
F_94 ( V_2 ) ;
return V_23 ;
}
int
F_95 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_105 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_74 ( V_117 ,
F_60 ( args -> V_88 ) ,
args -> V_17 ) )
return - V_76 ;
if ( F_69 ( ! V_92 ) ) {
V_23 = F_96 ( F_60 ( args -> V_88 ) ,
args -> V_17 ) ;
if ( V_23 )
return - V_76 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( args -> V_83 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_83 ) {
V_23 = - V_40 ;
goto V_93;
}
if ( ! V_7 -> V_8 . V_97 ) {
V_23 = - V_40 ;
goto V_93;
}
F_97 ( V_7 , args -> V_83 , args -> V_17 ) ;
V_23 = - V_76 ;
if ( V_7 -> V_118 ) {
V_23 = F_98 ( V_2 , V_7 , args , V_33 ) ;
goto V_93;
}
if ( V_7 -> V_11 == V_119 &&
V_7 -> V_8 . V_112 != V_90 &&
F_3 ( V_7 ) ) {
V_23 = F_83 ( V_2 , V_7 , args , V_33 ) ;
}
if ( V_23 == - V_76 || V_23 == - V_120 )
V_23 = F_91 ( V_2 , V_7 , args , V_33 ) ;
V_93:
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_99 ( struct V_22 * error ,
bool V_121 )
{
if ( F_100 ( error ) ) {
if ( ! V_121 )
return - V_26 ;
if ( F_101 ( error ) )
return - V_26 ;
return - V_122 ;
}
return 0 ;
}
static int
F_102 ( struct V_123 * V_124 , T_4 V_125 )
{
int V_23 ;
F_103 ( ! F_104 ( & V_124 -> V_2 -> V_29 ) ) ;
V_23 = 0 ;
if ( V_125 == V_124 -> V_126 )
V_23 = F_105 ( V_124 , NULL ) ;
return V_23 ;
}
static void F_106 ( unsigned long V_31 )
{
F_107 ( (struct V_127 * ) V_31 ) ;
}
static bool F_108 ( struct V_15 * V_16 ,
struct V_123 * V_124 )
{
return F_109 ( V_124 -> V_128 , & V_16 -> V_28 . V_129 ) ;
}
static bool F_110 ( struct V_130 * V_131 )
{
if ( V_131 == NULL )
return true ;
return ! F_111 ( & V_131 -> V_132 , true ) ;
}
static int F_112 ( struct V_123 * V_124 , T_4 V_125 ,
unsigned V_133 ,
bool V_121 ,
struct V_134 * V_135 ,
struct V_130 * V_131 )
{
T_9 * V_16 = V_124 -> V_2 -> V_27 ;
struct V_134 V_136 , V_137 ;
F_113 ( V_138 ) ;
long V_139 ;
int V_23 ;
F_114 ( V_16 -> V_140 . V_141 , L_2 ) ;
if ( F_115 ( V_124 -> V_142 ( V_124 , true ) , V_125 ) )
return 0 ;
V_139 = V_135 ? F_116 ( V_135 ) : 1 ;
if ( V_16 -> V_143 -> V_41 >= 6 && F_110 ( V_131 ) ) {
F_117 ( V_16 ) ;
if ( V_131 )
F_118 ( V_16 -> V_144 ,
& V_131 -> V_18 . V_145 ,
F_119 ( 100 ) ) ;
}
if ( ! ( V_16 -> V_28 . V_146 & F_120 ( V_124 ) ) &&
F_16 ( ! V_124 -> V_147 ( V_124 ) ) )
return - V_36 ;
F_121 ( V_124 , V_125 ) ;
F_122 ( & V_136 ) ;
for (; ; ) {
struct V_148 V_149 ;
unsigned long V_150 ;
F_123 ( & V_124 -> V_151 , & V_138 ,
V_121 ? V_152 : V_153 ) ;
if ( V_133 != F_124 ( & V_16 -> V_28 . V_133 ) ) {
V_23 = F_99 ( & V_16 -> V_28 , V_121 ) ;
if ( V_23 == 0 )
V_23 = - V_122 ;
break;
}
if ( F_115 ( V_124 -> V_142 ( V_124 , false ) , V_125 ) ) {
V_23 = 0 ;
break;
}
if ( V_121 && F_125 ( V_154 ) ) {
V_23 = - V_155 ;
break;
}
if ( V_139 <= 0 ) {
V_23 = - V_156 ;
break;
}
V_149 . V_157 = NULL ;
if ( V_135 || F_108 ( V_16 , V_124 ) ) {
F_126 ( & V_149 , F_106 , ( unsigned long ) V_154 ) ;
V_150 = V_158 + ( F_108 ( V_16 , V_124 ) ? 1 : V_139 ) ;
F_127 ( & V_149 , V_150 ) ;
}
F_128 () ;
if ( V_135 )
V_139 = V_150 - V_158 ;
if ( V_149 . V_157 ) {
F_129 ( & V_149 ) ;
F_130 ( & V_149 ) ;
}
}
F_122 ( & V_137 ) ;
F_131 ( V_124 , V_125 ) ;
V_124 -> V_159 ( V_124 ) ;
F_132 ( & V_124 -> V_151 , & V_138 ) ;
if ( V_135 ) {
struct V_134 V_160 = F_133 ( V_137 , V_136 ) ;
* V_135 = F_133 ( * V_135 , V_160 ) ;
if ( ! F_134 ( V_135 ) )
F_135 ( V_135 , 0 , 0 ) ;
}
return V_23 ;
}
int
F_136 ( struct V_123 * V_124 , T_3 V_125 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_121 = V_16 -> V_18 . V_121 ;
int V_23 ;
F_103 ( ! F_104 ( & V_2 -> V_29 ) ) ;
F_103 ( V_125 == 0 ) ;
V_23 = F_99 ( & V_16 -> V_28 , V_121 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_102 ( V_124 , V_125 ) ;
if ( V_23 )
return V_23 ;
return F_112 ( V_124 , V_125 ,
F_124 ( & V_16 -> V_28 . V_133 ) ,
V_121 , NULL , NULL ) ;
}
static int
F_137 ( struct V_6 * V_7 ,
struct V_123 * V_124 )
{
F_138 ( V_124 ) ;
V_7 -> V_161 = 0 ;
V_7 -> V_8 . V_112 &= ~ V_162 ;
return 0 ;
}
static T_10 int
F_62 ( struct V_6 * V_7 ,
bool V_163 )
{
struct V_123 * V_124 = V_7 -> V_124 ;
T_4 V_125 ;
int V_23 ;
V_125 = V_163 ? V_7 -> V_161 : V_7 -> V_164 ;
if ( V_125 == 0 )
return 0 ;
V_23 = F_136 ( V_124 , V_125 ) ;
if ( V_23 )
return V_23 ;
return F_137 ( V_7 , V_124 ) ;
}
static T_10 int
F_139 ( struct V_6 * V_7 ,
struct V_32 * V_33 ,
bool V_163 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 = V_7 -> V_124 ;
unsigned V_133 ;
T_4 V_125 ;
int V_23 ;
F_103 ( ! F_104 ( & V_2 -> V_29 ) ) ;
F_103 ( ! V_16 -> V_18 . V_121 ) ;
V_125 = V_163 ? V_7 -> V_161 : V_7 -> V_164 ;
if ( V_125 == 0 )
return 0 ;
V_23 = F_99 ( & V_16 -> V_28 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = F_102 ( V_124 , V_125 ) ;
if ( V_23 )
return V_23 ;
V_133 = F_124 ( & V_16 -> V_28 . V_133 ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_112 ( V_124 , V_125 , V_133 , true , NULL , V_33 -> V_165 ) ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_23 )
return V_23 ;
return F_137 ( V_7 , V_124 ) ;
}
int
F_140 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_166 * args = V_31 ;
struct V_6 * V_7 ;
T_3 V_89 = args -> V_89 ;
T_3 V_112 = args -> V_112 ;
int V_23 ;
if ( V_112 & V_162 )
return - V_40 ;
if ( V_89 & V_162 )
return - V_40 ;
if ( V_112 != 0 && V_89 != V_112 )
return - V_40 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
V_23 = F_139 ( V_7 , V_33 , ! V_112 ) ;
if ( V_23 )
goto V_167;
if ( V_89 & V_168 ) {
V_23 = F_85 ( V_7 , V_112 != 0 ) ;
if ( V_23 == - V_40 )
V_23 = 0 ;
} else {
V_23 = F_141 ( V_7 , V_112 != 0 ) ;
}
V_167:
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_142 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_169 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( V_7 -> V_10 )
F_143 ( V_7 , true ) ;
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_144 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_170 * args = V_31 ;
struct V_171 * V_7 ;
unsigned long V_77 ;
V_7 = F_76 ( V_2 , V_33 , args -> V_53 ) ;
if ( V_7 == NULL )
return - V_95 ;
if ( ! V_7 -> V_97 ) {
F_37 ( V_7 ) ;
return - V_40 ;
}
V_77 = F_145 ( V_7 -> V_97 , 0 , args -> V_17 ,
V_172 | V_173 , V_174 ,
args -> V_83 ) ;
F_37 ( V_7 ) ;
if ( F_146 ( ( void * ) V_77 ) )
return V_77 ;
args -> V_175 = ( T_2 ) V_77 ;
return 0 ;
}
int F_147 ( struct V_176 * V_177 , struct V_178 * V_179 )
{
struct V_6 * V_7 = F_75 ( V_177 -> V_180 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
T_9 * V_16 = V_2 -> V_27 ;
T_11 V_101 ;
unsigned long V_181 ;
int V_23 = 0 ;
bool V_182 = ! ! ( V_179 -> V_183 & V_184 ) ;
V_101 = ( ( unsigned long ) V_179 -> V_185 - V_177 -> V_186 ) >>
V_187 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
goto V_93;
F_148 ( V_7 , V_101 , true , V_182 ) ;
if ( V_7 -> V_9 != V_5 && ! F_2 ( V_2 ) ) {
V_23 = - V_40 ;
goto V_96;
}
V_23 = F_84 ( V_7 , 0 , true , false ) ;
if ( V_23 )
goto V_96;
V_23 = F_85 ( V_7 , V_182 ) ;
if ( V_23 )
goto V_188;
V_23 = F_149 ( V_7 ) ;
if ( V_23 )
goto V_188;
V_7 -> V_189 = true ;
V_181 = V_16 -> V_42 . V_190 + F_87 ( V_7 ) ;
V_181 >>= V_187 ;
V_181 += V_101 ;
V_23 = F_150 ( V_177 , ( unsigned long ) V_179 -> V_185 , V_181 ) ;
V_188:
F_88 ( V_7 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
V_93:
switch ( V_23 ) {
case - V_26 :
if ( F_101 ( & V_16 -> V_28 ) )
return V_191 ;
case - V_122 :
case 0 :
case - V_155 :
case - V_192 :
case - V_193 :
return V_194 ;
case - V_54 :
return V_195 ;
case - V_120 :
return V_191 ;
default:
F_151 ( V_23 , L_3 , V_23 ) ;
return V_191 ;
}
}
void
F_5 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_189 )
return;
F_152 ( & V_7 -> V_8 . V_196 , V_7 -> V_8 . V_2 -> V_197 ) ;
V_7 -> V_189 = false ;
}
T_3
F_153 ( struct V_1 * V_2 , T_3 V_17 , int V_11 )
{
T_3 V_198 ;
if ( F_22 ( V_2 ) -> V_41 >= 4 ||
V_11 == V_119 )
return V_17 ;
if ( F_22 ( V_2 ) -> V_41 == 3 )
V_198 = 1024 * 1024 ;
else
V_198 = 512 * 1024 ;
while ( V_198 < V_17 )
V_198 <<= 1 ;
return V_198 ;
}
T_3
F_154 ( struct V_1 * V_2 , T_3 V_17 ,
int V_11 , bool V_199 )
{
if ( F_22 ( V_2 ) -> V_41 >= 4 || ( ! V_199 && F_155 ( V_2 ) ) ||
V_11 == V_119 )
return 4096 ;
return F_153 ( V_2 , V_17 , V_11 ) ;
}
static int F_156 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_157 ( & V_7 -> V_8 . V_196 ) )
return 0 ;
V_16 -> V_18 . V_200 = true ;
V_23 = F_158 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_120 )
goto V_93;
F_159 ( V_16 , V_7 -> V_8 . V_17 >> V_187 ) ;
V_23 = F_158 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_120 )
goto V_93;
F_160 ( V_16 ) ;
V_23 = F_158 ( & V_7 -> V_8 ) ;
V_93:
V_16 -> V_18 . V_200 = false ;
return V_23 ;
}
static void F_161 ( struct V_6 * V_7 )
{
F_162 ( & V_7 -> V_8 ) ;
}
int
F_163 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_3 V_53 ,
T_2 * V_83 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( V_7 -> V_8 . V_17 > V_16 -> V_42 . V_43 ) {
V_23 = - V_201 ;
goto V_93;
}
if ( V_7 -> V_202 != V_203 ) {
F_13 ( L_4 ) ;
V_23 = - V_40 ;
goto V_93;
}
V_23 = F_156 ( V_7 ) ;
if ( V_23 )
goto V_93;
* V_83 = F_164 ( & V_7 -> V_8 . V_196 ) ;
V_93:
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_165 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_204 * args = V_31 ;
return F_163 ( V_33 , V_2 , args -> V_53 , & args -> V_83 ) ;
}
static void
F_166 ( struct V_6 * V_7 )
{
struct V_205 * V_205 ;
F_161 ( V_7 ) ;
if ( V_7 -> V_8 . V_97 == NULL )
return;
V_205 = F_167 ( V_7 -> V_8 . V_97 ) ;
F_168 ( V_205 , 0 , ( T_7 ) - 1 ) ;
V_7 -> V_202 = V_206 ;
}
static inline int
F_169 ( struct V_6 * V_7 )
{
return V_7 -> V_202 == V_207 ;
}
static void
F_170 ( struct V_6 * V_7 )
{
struct V_86 V_87 ;
int V_23 ;
F_103 ( V_7 -> V_202 == V_206 ) ;
V_23 = F_141 ( V_7 , true ) ;
if ( V_23 ) {
F_16 ( V_23 != - V_26 ) ;
F_93 ( V_7 , true ) ;
V_7 -> V_8 . V_89 = V_7 -> V_8 . V_112 = V_90 ;
}
if ( F_61 ( V_7 ) )
F_171 ( V_7 ) ;
if ( V_7 -> V_202 == V_207 )
V_7 -> V_113 = 0 ;
F_65 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_69 * V_69 = F_66 ( & V_87 ) ;
if ( V_7 -> V_113 )
F_92 ( V_69 ) ;
if ( V_7 -> V_202 == V_203 )
F_71 ( V_69 ) ;
F_172 ( V_69 ) ;
}
V_7 -> V_113 = 0 ;
F_173 ( V_7 -> V_208 ) ;
F_174 ( V_7 -> V_208 ) ;
}
int
F_175 ( struct V_6 * V_7 )
{
const struct V_209 * V_210 = V_7 -> V_210 ;
if ( V_7 -> V_208 == NULL )
return 0 ;
if ( V_7 -> V_211 )
return - V_193 ;
F_103 ( F_19 ( V_7 ) ) ;
F_176 ( & V_7 -> V_212 ) ;
V_210 -> V_213 ( V_7 ) ;
V_7 -> V_208 = NULL ;
if ( F_169 ( V_7 ) )
F_166 ( V_7 ) ;
return 0 ;
}
static unsigned long
F_177 ( struct V_15 * V_16 , long V_214 ,
bool V_215 )
{
struct V_216 V_217 ;
struct V_6 * V_7 , * V_218 ;
unsigned long V_219 = 0 ;
F_178 (obj, next,
&dev_priv->mm.unbound_list,
global_list) {
if ( ( F_169 ( V_7 ) || ! V_215 ) &&
F_175 ( V_7 ) == 0 ) {
V_219 += V_7 -> V_8 . V_17 >> V_187 ;
if ( V_219 >= V_214 )
return V_219 ;
}
}
F_179 ( & V_217 ) ;
while ( V_219 < V_214 && ! F_180 ( & V_16 -> V_18 . V_220 ) ) {
struct V_221 * V_177 , * V_222 ;
V_7 = F_181 ( & V_16 -> V_18 . V_220 ,
F_182 ( * V_7 ) , V_212 ) ;
F_183 ( & V_7 -> V_212 , & V_217 ) ;
if ( ! F_169 ( V_7 ) && V_215 )
continue;
F_184 ( & V_7 -> V_8 ) ;
F_178 (vma, v, &obj->vma_list, vma_link)
if ( F_185 ( V_177 ) )
break;
if ( F_175 ( V_7 ) == 0 )
V_219 += V_7 -> V_8 . V_17 >> V_187 ;
F_78 ( & V_7 -> V_8 ) ;
}
F_186 ( & V_217 , & V_16 -> V_18 . V_220 ) ;
return V_219 ;
}
static unsigned long
F_159 ( struct V_15 * V_16 , long V_214 )
{
return F_177 ( V_16 , V_214 , true ) ;
}
static unsigned long
F_160 ( struct V_15 * V_16 )
{
struct V_6 * V_7 , * V_218 ;
long V_223 = 0 ;
F_187 ( V_16 -> V_2 ) ;
F_178 (obj, next, &dev_priv->mm.unbound_list,
global_list) {
if ( F_175 ( V_7 ) == 0 )
V_223 += V_7 -> V_8 . V_17 >> V_187 ;
}
return V_223 ;
}
static int
F_188 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_224 , V_225 ;
struct V_226 * V_99 ;
struct V_227 * V_228 ;
struct V_229 * V_230 ;
struct V_86 V_87 ;
struct V_69 * V_69 ;
unsigned long V_231 = 0 ;
T_12 V_232 ;
F_103 ( V_7 -> V_8 . V_89 & V_162 ) ;
F_103 ( V_7 -> V_8 . V_112 & V_162 ) ;
V_228 = F_189 ( sizeof( * V_228 ) , V_51 ) ;
if ( V_228 == NULL )
return - V_54 ;
V_224 = V_7 -> V_8 . V_17 / V_39 ;
if ( F_190 ( V_228 , V_224 , V_51 ) ) {
F_174 ( V_228 ) ;
return - V_54 ;
}
V_99 = F_167 ( V_7 -> V_8 . V_97 ) -> V_233 ;
V_232 = F_191 ( V_99 ) ;
V_232 |= V_234 | V_235 | V_236 ;
V_232 &= ~ ( V_237 | V_238 ) ;
V_230 = V_228 -> V_239 ;
V_228 -> V_240 = 0 ;
for ( V_225 = 0 ; V_225 < V_224 ; V_225 ++ ) {
V_69 = F_192 ( V_99 , V_225 , V_232 ) ;
if ( F_146 ( V_69 ) ) {
F_159 ( V_16 , V_224 ) ;
V_69 = F_192 ( V_99 , V_225 , V_232 ) ;
}
if ( F_146 ( V_69 ) ) {
V_232 &= ~ ( V_234 | V_235 | V_236 ) ;
V_232 |= V_237 | V_238 ;
F_160 ( V_16 ) ;
V_69 = F_192 ( V_99 , V_225 , V_232 ) ;
if ( F_146 ( V_69 ) )
goto V_241;
V_232 |= V_234 | V_235 | V_236 ;
V_232 &= ~ ( V_237 | V_238 ) ;
}
#ifdef F_193
if ( F_194 () ) {
V_228 -> V_240 ++ ;
F_195 ( V_230 , V_69 , V_39 , 0 ) ;
V_230 = F_196 ( V_230 ) ;
continue;
}
#endif
if ( ! V_225 || F_197 ( V_69 ) != V_231 + 1 ) {
if ( V_225 )
V_230 = F_196 ( V_230 ) ;
V_228 -> V_240 ++ ;
F_195 ( V_230 , V_69 , V_39 , 0 ) ;
} else {
V_230 -> V_64 += V_39 ;
}
V_231 = F_197 ( V_69 ) ;
F_16 ( ( V_232 & V_242 ) && ( V_231 >= 0x00100000UL ) ) ;
}
#ifdef F_193
if ( ! F_194 () )
#endif
F_198 ( V_230 ) ;
V_7 -> V_208 = V_228 ;
if ( F_61 ( V_7 ) )
F_199 ( V_7 ) ;
return 0 ;
V_241:
F_198 ( V_230 ) ;
F_65 (st->sgl, &sg_iter, st->nents, 0 )
F_172 ( F_66 ( & V_87 ) ) ;
F_173 ( V_228 ) ;
F_174 ( V_228 ) ;
return F_200 ( V_69 ) ;
}
int
F_63 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
const struct V_209 * V_210 = V_7 -> V_210 ;
int V_23 ;
if ( V_7 -> V_208 )
return 0 ;
if ( V_7 -> V_202 != V_203 ) {
F_13 ( L_5 ) ;
return - V_40 ;
}
F_103 ( V_7 -> V_211 ) ;
V_23 = V_210 -> V_243 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_201 ( & V_7 -> V_212 , & V_16 -> V_18 . V_244 ) ;
return 0 ;
}
static void
F_202 ( struct V_6 * V_7 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_4 V_125 = F_203 ( V_124 ) ;
F_103 ( V_124 == NULL ) ;
if ( V_7 -> V_124 != V_124 && V_7 -> V_161 ) {
V_7 -> V_161 = V_125 ;
}
V_7 -> V_124 = V_124 ;
if ( ! V_7 -> V_30 ) {
F_184 ( & V_7 -> V_8 ) ;
V_7 -> V_30 = 1 ;
}
F_183 ( & V_7 -> V_245 , & V_124 -> V_246 ) ;
V_7 -> V_164 = V_125 ;
if ( V_7 -> V_247 ) {
V_7 -> V_248 = V_125 ;
if ( V_7 -> V_13 != V_14 ) {
struct V_249 * V_250 ;
V_250 = & V_16 -> V_251 [ V_7 -> V_13 ] ;
F_183 ( & V_250 -> V_252 ,
& V_16 -> V_18 . V_253 ) ;
}
}
}
void F_204 ( struct V_221 * V_177 ,
struct V_123 * V_124 )
{
F_183 ( & V_177 -> V_254 , & V_177 -> V_255 -> V_246 ) ;
return F_202 ( V_177 -> V_7 , V_124 ) ;
}
static void
F_205 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_256 * V_257 = & V_16 -> V_42 . V_8 ;
struct V_221 * V_177 = F_206 ( V_7 , V_257 ) ;
F_103 ( V_7 -> V_8 . V_112 & ~ V_162 ) ;
F_103 ( ! V_7 -> V_30 ) ;
F_183 ( & V_177 -> V_254 , & V_257 -> V_258 ) ;
F_207 ( & V_7 -> V_245 ) ;
V_7 -> V_124 = NULL ;
V_7 -> V_164 = 0 ;
V_7 -> V_161 = 0 ;
V_7 -> V_8 . V_112 = 0 ;
V_7 -> V_248 = 0 ;
V_7 -> V_247 = false ;
V_7 -> V_30 = 0 ;
F_78 ( & V_7 -> V_8 ) ;
F_16 ( F_17 ( V_2 ) ) ;
}
static int
F_208 ( struct V_1 * V_2 , T_4 V_125 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 ;
int V_23 , V_225 , V_259 ;
F_209 (ring, dev_priv, i) {
V_23 = F_210 ( V_124 ) ;
if ( V_23 )
return V_23 ;
}
F_211 ( V_2 ) ;
F_209 (ring, dev_priv, i) {
F_212 ( V_124 , V_125 ) ;
for ( V_259 = 0 ; V_259 < F_213 ( V_124 -> V_260 ) ; V_259 ++ )
V_124 -> V_260 [ V_259 ] = 0 ;
}
return 0 ;
}
int F_214 ( struct V_1 * V_2 , T_4 V_125 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( V_125 == 0 )
return - V_40 ;
V_23 = F_208 ( V_2 , V_125 - 1 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_261 = V_125 ;
V_16 -> V_262 = V_125 - 1 ;
if ( V_16 -> V_262 == 0 )
V_16 -> V_262 -- ;
return 0 ;
}
int
F_215 ( struct V_1 * V_2 , T_4 * V_125 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( V_16 -> V_261 == 0 ) {
int V_23 = F_208 ( V_2 , 0 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_261 = 1 ;
}
* V_125 = V_16 -> V_262 = V_16 -> V_261 ++ ;
return 0 ;
}
int F_216 ( struct V_123 * V_124 ,
struct V_32 * V_33 ,
struct V_6 * V_7 ,
T_4 * V_263 )
{
T_9 * V_16 = V_124 -> V_2 -> V_27 ;
struct V_264 * V_265 ;
T_4 V_266 , V_267 ;
int V_268 ;
int V_23 ;
V_267 = F_217 ( V_124 ) ;
V_23 = F_218 ( V_124 ) ;
if ( V_23 )
return V_23 ;
V_265 = V_124 -> V_269 ;
if ( F_16 ( V_265 == NULL ) )
return - V_54 ;
V_266 = F_217 ( V_124 ) ;
V_23 = V_124 -> V_270 ( V_124 ) ;
if ( V_23 )
return V_23 ;
V_265 -> V_125 = F_203 ( V_124 ) ;
V_265 -> V_124 = V_124 ;
V_265 -> V_271 = V_267 ;
V_265 -> V_272 = V_266 ;
V_265 -> V_273 = V_7 ;
V_265 -> V_274 = V_124 -> V_275 ;
if ( V_265 -> V_274 )
F_219 ( V_265 -> V_274 ) ;
V_265 -> V_276 = V_158 ;
V_268 = F_180 ( & V_124 -> V_277 ) ;
F_201 ( & V_265 -> V_278 , & V_124 -> V_277 ) ;
V_265 -> V_131 = NULL ;
if ( V_33 ) {
struct V_130 * V_131 = V_33 -> V_165 ;
F_7 ( & V_131 -> V_18 . V_279 ) ;
V_265 -> V_131 = V_131 ;
F_201 ( & V_265 -> V_280 ,
& V_131 -> V_18 . V_277 ) ;
F_8 ( & V_131 -> V_18 . V_279 ) ;
}
F_220 ( V_124 , V_265 -> V_125 ) ;
V_124 -> V_126 = 0 ;
V_124 -> V_269 = NULL ;
if ( ! V_16 -> V_281 . V_282 ) {
F_221 ( V_124 -> V_2 ) ;
if ( V_268 ) {
F_222 ( & V_16 -> V_18 . V_145 ) ;
F_223 ( V_16 -> V_144 ,
& V_16 -> V_18 . V_283 ,
F_224 ( V_25 ) ) ;
F_225 ( V_16 -> V_2 ) ;
}
}
if ( V_263 )
* V_263 = V_265 -> V_125 ;
return 0 ;
}
static inline void
F_226 ( struct V_264 * V_265 )
{
struct V_130 * V_131 = V_265 -> V_131 ;
if ( ! V_131 )
return;
F_7 ( & V_131 -> V_18 . V_279 ) ;
F_176 ( & V_265 -> V_280 ) ;
V_265 -> V_131 = NULL ;
F_8 ( & V_131 -> V_18 . V_279 ) ;
}
static bool F_227 ( T_4 V_284 , struct V_6 * V_7 ,
struct V_256 * V_255 )
{
if ( V_284 >= F_228 ( V_7 , V_255 ) &&
V_284 < F_228 ( V_7 , V_255 ) + V_7 -> V_8 . V_17 )
return true ;
return false ;
}
static bool F_229 ( const T_4 V_285 ,
const T_4 V_267 ,
const T_4 V_286 )
{
const T_4 V_284 = V_285 & V_287 ;
if ( V_267 < V_286 ) {
if ( V_284 >= V_267 && V_284 < V_286 )
return true ;
} else if ( V_267 > V_286 ) {
if ( V_284 >= V_267 || V_284 < V_286 )
return true ;
}
return false ;
}
static struct V_256 *
F_230 ( struct V_264 * V_265 )
{
struct V_15 * V_16 = V_265 -> V_124 -> V_2 -> V_27 ;
struct V_256 * V_255 ;
V_255 = & V_16 -> V_42 . V_8 ;
return V_255 ;
}
static bool F_231 ( struct V_264 * V_265 ,
const T_4 V_284 , bool * V_288 )
{
if ( V_265 -> V_273 ) {
if ( F_227 ( V_284 , V_265 -> V_273 ,
F_230 ( V_265 ) ) ) {
* V_288 = true ;
return true ;
}
}
if ( F_229 ( V_284 , V_265 -> V_271 , V_265 -> V_272 ) ) {
* V_288 = false ;
return true ;
}
return false ;
}
static bool F_232 ( const struct V_289 * V_290 )
{
const unsigned long V_291 = F_233 () - V_290 -> V_292 ;
if ( V_290 -> V_293 )
return true ;
if ( V_291 <= V_294 ) {
F_13 ( L_6 ) ;
return true ;
}
return false ;
}
static void F_234 ( struct V_123 * V_124 ,
struct V_264 * V_265 ,
T_4 V_284 )
{
struct V_289 * V_290 = NULL ;
bool V_288 , V_295 ;
unsigned long V_83 = 0 ;
V_295 = false ;
if ( V_265 -> V_273 )
V_83 = F_228 ( V_265 -> V_273 ,
F_230 ( V_265 ) ) ;
if ( V_124 -> V_296 . V_297 != V_298 &&
F_231 ( V_265 , V_284 , & V_288 ) ) {
F_13 ( L_7 ,
V_124 -> V_299 ,
V_288 ? L_8 : L_9 ,
V_83 ,
V_265 -> V_274 ? V_265 -> V_274 -> V_128 : 0 ,
V_284 ) ;
V_295 = true ;
}
if ( V_265 -> V_274 && V_265 -> V_274 -> V_128 != V_300 )
V_290 = & V_265 -> V_274 -> V_301 ;
else if ( V_265 -> V_131 )
V_290 = & V_265 -> V_131 -> V_301 ;
if ( V_290 ) {
if ( V_295 ) {
V_290 -> V_293 = F_232 ( V_290 ) ;
V_290 -> V_302 ++ ;
V_290 -> V_292 = F_233 () ;
} else {
V_290 -> V_303 ++ ;
}
}
}
static void F_235 ( struct V_264 * V_265 )
{
F_176 ( & V_265 -> V_278 ) ;
F_226 ( V_265 ) ;
if ( V_265 -> V_274 )
F_236 ( V_265 -> V_274 ) ;
F_174 ( V_265 ) ;
}
static void F_237 ( struct V_15 * V_16 ,
struct V_123 * V_124 )
{
T_4 V_304 = V_124 -> V_142 ( V_124 , false ) ;
T_4 V_284 = F_238 ( V_124 ) ;
struct V_264 * V_265 ;
F_27 (request, &ring->request_list, list) {
if ( F_115 ( V_304 , V_265 -> V_125 ) )
continue;
F_234 ( V_124 , V_265 , V_284 ) ;
}
}
static void F_239 ( struct V_15 * V_16 ,
struct V_123 * V_124 )
{
while ( ! F_180 ( & V_124 -> V_277 ) ) {
struct V_264 * V_265 ;
V_265 = F_181 ( & V_124 -> V_277 ,
struct V_264 ,
V_278 ) ;
F_235 ( V_265 ) ;
}
while ( ! F_180 ( & V_124 -> V_246 ) ) {
struct V_6 * V_7 ;
V_7 = F_181 ( & V_124 -> V_246 ,
struct V_6 ,
V_245 ) ;
F_205 ( V_7 ) ;
}
}
void F_240 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_225 ;
for ( V_225 = 0 ; V_225 < V_16 -> V_305 ; V_225 ++ ) {
struct V_249 * V_250 = & V_16 -> V_251 [ V_225 ] ;
if ( V_250 -> V_7 ) {
F_241 ( V_250 -> V_7 , V_250 ,
V_250 -> V_7 -> V_11 ) ;
} else {
F_242 ( V_2 , V_225 , NULL ) ;
}
}
}
void F_243 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 ;
int V_225 ;
F_209 (ring, dev_priv, i)
F_237 ( V_16 , V_124 ) ;
F_209 (ring, dev_priv, i)
F_239 ( V_16 , V_124 ) ;
F_244 ( V_2 ) ;
F_240 ( V_2 ) ;
}
void
F_138 ( struct V_123 * V_124 )
{
T_3 V_125 ;
if ( F_180 ( & V_124 -> V_277 ) )
return;
F_16 ( F_17 ( V_124 -> V_2 ) ) ;
V_125 = V_124 -> V_142 ( V_124 , true ) ;
while ( ! F_180 ( & V_124 -> V_277 ) ) {
struct V_264 * V_265 ;
V_265 = F_181 ( & V_124 -> V_277 ,
struct V_264 ,
V_278 ) ;
if ( ! F_115 ( V_125 , V_265 -> V_125 ) )
break;
F_245 ( V_124 , V_265 -> V_125 ) ;
V_124 -> V_306 = V_265 -> V_272 ;
F_235 ( V_265 ) ;
}
while ( ! F_180 ( & V_124 -> V_246 ) ) {
struct V_6 * V_7 ;
V_7 = F_181 ( & V_124 -> V_246 ,
struct V_6 ,
V_245 ) ;
if ( ! F_115 ( V_125 , V_7 -> V_164 ) )
break;
F_205 ( V_7 ) ;
}
if ( F_48 ( V_124 -> V_307 &&
F_115 ( V_125 , V_124 -> V_307 ) ) ) {
V_124 -> V_159 ( V_124 ) ;
V_124 -> V_307 = 0 ;
}
F_16 ( F_17 ( V_124 -> V_2 ) ) ;
}
bool
F_211 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 ;
bool V_308 = true ;
int V_225 ;
F_209 (ring, dev_priv, i) {
F_138 ( V_124 ) ;
V_308 &= F_180 ( & V_124 -> V_277 ) ;
}
if ( V_308 )
F_118 ( V_16 -> V_144 ,
& V_16 -> V_18 . V_145 ,
F_119 ( 100 ) ) ;
return V_308 ;
}
static void
F_246 ( struct V_309 * V_310 )
{
struct V_15 * V_16 =
F_247 ( V_310 , F_182 ( * V_16 ) , V_18 . V_283 . V_310 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_308 ;
V_308 = false ;
if ( F_248 ( & V_2 -> V_29 ) ) {
V_308 = F_211 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
}
if ( ! V_308 )
F_223 ( V_16 -> V_144 , & V_16 -> V_18 . V_283 ,
F_224 ( V_25 ) ) ;
}
static void
F_249 ( struct V_309 * V_310 )
{
struct V_15 * V_16 =
F_247 ( V_310 , F_182 ( * V_16 ) , V_18 . V_145 . V_310 ) ;
F_250 ( V_16 -> V_2 ) ;
}
static int
F_251 ( struct V_6 * V_7 )
{
int V_23 ;
if ( V_7 -> V_30 ) {
V_23 = F_102 ( V_7 -> V_124 , V_7 -> V_164 ) ;
if ( V_23 )
return V_23 ;
F_138 ( V_7 -> V_124 ) ;
}
return 0 ;
}
int
F_252 ( struct V_1 * V_2 , void * V_31 , struct V_32 * V_33 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_311 * args = V_31 ;
struct V_6 * V_7 ;
struct V_123 * V_124 = NULL ;
struct V_134 V_312 , * V_135 = NULL ;
unsigned V_133 ;
T_4 V_125 = 0 ;
int V_23 = 0 ;
if ( args -> V_313 >= 0 ) {
V_312 = F_253 ( args -> V_313 ) ;
V_135 = & V_312 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_314 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_25 ( & V_2 -> V_29 ) ;
return - V_95 ;
}
V_23 = F_251 ( V_7 ) ;
if ( V_23 )
goto V_93;
if ( V_7 -> V_30 ) {
V_125 = V_7 -> V_164 ;
V_124 = V_7 -> V_124 ;
}
if ( V_125 == 0 )
goto V_93;
if ( ! args -> V_313 ) {
V_23 = - V_156 ;
goto V_93;
}
F_78 ( & V_7 -> V_8 ) ;
V_133 = F_124 ( & V_16 -> V_28 . V_133 ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_112 ( V_124 , V_125 , V_133 , true , V_135 , V_33 -> V_165 ) ;
if ( V_135 )
args -> V_313 = F_254 ( V_135 ) ;
return V_23 ;
V_93:
F_78 ( & V_7 -> V_8 ) ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_255 ( struct V_6 * V_7 ,
struct V_123 * V_315 )
{
struct V_123 * V_316 = V_7 -> V_124 ;
T_4 V_125 ;
int V_23 , V_317 ;
if ( V_316 == NULL || V_315 == V_316 )
return 0 ;
if ( V_315 == NULL || ! F_256 ( V_7 -> V_8 . V_2 ) )
return F_62 ( V_7 , false ) ;
V_317 = F_257 ( V_316 , V_315 ) ;
V_125 = V_7 -> V_164 ;
if ( V_125 <= V_316 -> V_260 [ V_317 ] )
return 0 ;
V_23 = F_102 ( V_7 -> V_124 , V_125 ) ;
if ( V_23 )
return V_23 ;
F_258 ( V_316 , V_315 , V_125 ) ;
V_23 = V_315 -> V_318 ( V_315 , V_316 , V_125 ) ;
if ( ! V_23 )
V_316 -> V_260 [ V_317 ] = V_7 -> V_164 ;
return V_23 ;
}
static void F_259 ( struct V_6 * V_7 )
{
T_4 V_319 , V_320 ;
F_5 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_89 & V_168 ) == 0 )
return;
F_260 () ;
V_320 = V_7 -> V_8 . V_89 ;
V_319 = V_7 -> V_8 . V_112 ;
V_7 -> V_8 . V_89 &= ~ V_168 ;
V_7 -> V_8 . V_112 &= ~ V_168 ;
F_261 ( V_7 ,
V_320 ,
V_319 ) ;
}
int F_185 ( struct V_221 * V_177 )
{
struct V_6 * V_7 = V_177 -> V_7 ;
T_9 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
F_16 ( ! F_262 ( & V_7 -> V_321 ) ) ;
if ( F_180 ( & V_177 -> V_322 ) )
return 0 ;
if ( ! F_263 ( & V_177 -> V_323 ) ) {
F_264 ( V_177 ) ;
return 0 ;
}
if ( V_7 -> V_46 )
return - V_193 ;
F_103 ( V_7 -> V_208 == NULL ) ;
V_23 = F_265 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_259 ( V_7 ) ;
V_23 = F_86 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_266 ( V_177 ) ;
if ( V_7 -> V_324 )
F_267 ( V_7 ) ;
if ( V_7 -> V_325 ) {
F_268 ( V_16 -> V_18 . V_326 , V_7 ) ;
V_7 -> V_325 = 0 ;
}
F_269 ( V_7 ) ;
F_72 ( V_7 ) ;
F_176 ( & V_177 -> V_254 ) ;
if ( F_270 ( V_177 -> V_255 ) )
V_7 -> V_327 = true ;
F_271 ( & V_177 -> V_323 ) ;
F_264 ( V_177 ) ;
if ( F_180 ( & V_7 -> V_321 ) )
F_183 ( & V_7 -> V_212 , & V_16 -> V_18 . V_244 ) ;
return 0 ;
}
int
F_272 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_256 * V_328 = & V_16 -> V_42 . V_8 ;
if ( ! F_273 ( V_7 ) )
return 0 ;
if ( V_7 -> V_46 )
return - V_193 ;
F_103 ( V_7 -> V_208 == NULL ) ;
return F_185 ( F_206 ( V_7 , V_328 ) ) ;
}
int F_274 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 ;
int V_23 , V_225 ;
F_209 (ring, dev_priv, i) {
V_23 = F_275 ( V_124 , NULL , V_300 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_210 ( V_124 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static void F_276 ( struct V_1 * V_2 , int V_250 ,
struct V_6 * V_7 )
{
T_9 * V_16 = V_2 -> V_27 ;
int V_13 ;
int V_329 ;
if ( F_22 ( V_2 ) -> V_41 >= 6 ) {
V_13 = V_330 ;
V_329 = V_331 ;
} else {
V_13 = V_332 ;
V_329 = V_333 ;
}
V_13 += V_250 * 8 ;
F_277 ( V_13 , 0 ) ;
F_278 ( V_13 ) ;
if ( V_7 ) {
T_4 V_17 = F_28 ( V_7 ) ;
T_2 V_334 ;
V_334 = ( T_2 ) ( ( F_87 ( V_7 ) + V_17 - 4096 ) &
0xfffff000 ) << 32 ;
V_334 |= F_87 ( V_7 ) & 0xfffff000 ;
V_334 |= ( T_2 ) ( ( V_7 -> V_335 / 128 ) - 1 ) << V_329 ;
if ( V_7 -> V_11 == V_336 )
V_334 |= 1 << V_337 ;
V_334 |= V_338 ;
F_277 ( V_13 + 4 , V_334 >> 32 ) ;
F_278 ( V_13 + 4 ) ;
F_277 ( V_13 + 0 , V_334 ) ;
F_278 ( V_13 ) ;
} else {
F_277 ( V_13 + 4 , 0 ) ;
F_278 ( V_13 + 4 ) ;
}
}
static void F_279 ( struct V_1 * V_2 , int V_250 ,
struct V_6 * V_7 )
{
T_9 * V_16 = V_2 -> V_27 ;
T_4 V_334 ;
if ( V_7 ) {
T_4 V_17 = F_28 ( V_7 ) ;
int V_339 ;
int V_340 ;
F_114 ( ( F_87 ( V_7 ) & ~ V_341 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_87 ( V_7 ) & ( V_17 - 1 ) ) ,
L_10 ,
F_87 ( V_7 ) , V_7 -> V_327 , V_17 ) ;
if ( V_7 -> V_11 == V_336 && F_280 ( V_2 ) )
V_340 = 128 ;
else
V_340 = 512 ;
V_339 = V_7 -> V_335 / V_340 ;
V_339 = F_281 ( V_339 ) - 1 ;
V_334 = F_87 ( V_7 ) ;
if ( V_7 -> V_11 == V_336 )
V_334 |= 1 << V_342 ;
V_334 |= F_282 ( V_17 ) ;
V_334 |= V_339 << V_343 ;
V_334 |= V_344 ;
} else
V_334 = 0 ;
if ( V_250 < 8 )
V_250 = V_345 + V_250 * 4 ;
else
V_250 = V_346 + ( V_250 - 8 ) * 4 ;
F_277 ( V_250 , V_334 ) ;
F_278 ( V_250 ) ;
}
static void F_283 ( struct V_1 * V_2 , int V_250 ,
struct V_6 * V_7 )
{
T_9 * V_16 = V_2 -> V_27 ;
T_3 V_334 ;
if ( V_7 ) {
T_4 V_17 = F_28 ( V_7 ) ;
T_3 V_339 ;
F_114 ( ( F_87 ( V_7 ) & ~ V_347 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_87 ( V_7 ) & ( V_17 - 1 ) ) ,
L_11 ,
F_87 ( V_7 ) , V_17 ) ;
V_339 = V_7 -> V_335 / 128 ;
V_339 = F_281 ( V_339 ) - 1 ;
V_334 = F_87 ( V_7 ) ;
if ( V_7 -> V_11 == V_336 )
V_334 |= 1 << V_342 ;
V_334 |= F_284 ( V_17 ) ;
V_334 |= V_339 << V_343 ;
V_334 |= V_344 ;
} else
V_334 = 0 ;
F_277 ( V_345 + V_250 * 4 , V_334 ) ;
F_278 ( V_345 + V_250 * 4 ) ;
}
inline static bool F_285 ( struct V_6 * V_7 )
{
return V_7 && V_7 -> V_8 . V_89 & V_168 ;
}
static void F_242 ( struct V_1 * V_2 , int V_250 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_285 ( V_16 -> V_251 [ V_250 ] . V_7 ) )
F_260 () ;
F_114 ( V_7 && ( ! V_7 -> V_335 || ! V_7 -> V_11 ) ,
L_12 ,
V_7 -> V_335 , V_7 -> V_11 ) ;
switch ( F_22 ( V_2 ) -> V_41 ) {
case 8 :
case 7 :
case 6 :
case 5 :
case 4 : F_276 ( V_2 , V_250 , V_7 ) ; break;
case 3 : F_279 ( V_2 , V_250 , V_7 ) ; break;
case 2 : F_283 ( V_2 , V_250 , V_7 ) ; break;
default: F_286 () ;
}
if ( F_285 ( V_7 ) )
F_260 () ;
}
static inline int F_287 ( struct V_15 * V_16 ,
struct V_249 * V_348 )
{
return V_348 - V_16 -> V_251 ;
}
static void F_241 ( struct V_6 * V_7 ,
struct V_249 * V_348 ,
bool V_349 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_250 = F_287 ( V_16 , V_348 ) ;
F_242 ( V_7 -> V_8 . V_2 , V_250 , V_349 ? V_7 : NULL ) ;
if ( V_349 ) {
V_7 -> V_13 = V_250 ;
V_348 -> V_7 = V_7 ;
F_183 ( & V_348 -> V_252 , & V_16 -> V_18 . V_253 ) ;
} else {
V_7 -> V_13 = V_14 ;
V_348 -> V_7 = NULL ;
F_207 ( & V_348 -> V_252 ) ;
}
V_7 -> V_12 = false ;
}
static int
F_288 ( struct V_6 * V_7 )
{
if ( V_7 -> V_248 ) {
int V_23 = F_136 ( V_7 -> V_124 , V_7 -> V_248 ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_248 = 0 ;
}
V_7 -> V_247 = false ;
return 0 ;
}
int
F_86 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_249 * V_348 ;
int V_23 ;
V_23 = F_288 ( V_7 ) ;
if ( V_23 )
return V_23 ;
if ( V_7 -> V_13 == V_14 )
return 0 ;
V_348 = & V_16 -> V_251 [ V_7 -> V_13 ] ;
F_4 ( V_7 ) ;
F_241 ( V_7 , V_348 , false ) ;
return 0 ;
}
static struct V_249 *
F_289 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_249 * V_250 , * V_350 ;
int V_225 ;
V_350 = NULL ;
for ( V_225 = V_16 -> V_351 ; V_225 < V_16 -> V_305 ; V_225 ++ ) {
V_250 = & V_16 -> V_251 [ V_225 ] ;
if ( ! V_250 -> V_7 )
return V_250 ;
if ( ! V_250 -> V_46 )
V_350 = V_250 ;
}
if ( V_350 == NULL )
return NULL ;
F_27 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_250 -> V_46 )
continue;
return V_250 ;
}
return NULL ;
}
int
F_149 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_349 = V_7 -> V_11 != V_119 ;
struct V_249 * V_250 ;
int V_23 ;
if ( V_7 -> V_12 ) {
V_23 = F_288 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_7 -> V_13 != V_14 ) {
V_250 = & V_16 -> V_251 [ V_7 -> V_13 ] ;
if ( ! V_7 -> V_12 ) {
F_183 ( & V_250 -> V_252 ,
& V_16 -> V_18 . V_253 ) ;
return 0 ;
}
} else if ( V_349 ) {
V_250 = F_289 ( V_2 ) ;
if ( V_250 == NULL )
return - V_352 ;
if ( V_250 -> V_7 ) {
struct V_6 * V_353 = V_250 -> V_7 ;
V_23 = F_288 ( V_353 ) ;
if ( V_23 )
return V_23 ;
F_4 ( V_353 ) ;
}
} else
return 0 ;
F_241 ( V_7 , V_250 , V_349 ) ;
return 0 ;
}
static bool F_290 ( struct V_1 * V_2 ,
struct V_354 * V_355 ,
unsigned long V_9 )
{
struct V_354 * V_356 ;
if ( F_2 ( V_2 ) )
return true ;
if ( ! F_263 ( V_355 ) )
return true ;
if ( F_180 ( & V_355 -> V_357 ) )
return true ;
V_356 = F_291 ( V_355 -> V_357 . V_358 , struct V_354 , V_357 ) ;
if ( V_356 -> V_359 && ! V_356 -> V_360 && V_356 -> V_361 != V_9 )
return false ;
V_356 = F_291 ( V_355 -> V_357 . V_218 , struct V_354 , V_357 ) ;
if ( V_356 -> V_359 && ! V_355 -> V_360 && V_356 -> V_361 != V_9 )
return false ;
return true ;
}
static void F_292 ( struct V_1 * V_2 )
{
#if V_362
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_6 * V_7 ;
int V_363 = 0 ;
F_27 (obj, &dev_priv->mm.gtt_list, global_list) {
if ( V_7 -> V_355 == NULL ) {
F_293 ( V_364 L_13 ) ;
V_363 ++ ;
continue;
}
if ( V_7 -> V_9 != V_7 -> V_355 -> V_361 ) {
F_293 ( V_364 L_14 ,
F_87 ( V_7 ) ,
F_87 ( V_7 ) + F_28 ( V_7 ) ,
V_7 -> V_9 ,
V_7 -> V_355 -> V_361 ) ;
V_363 ++ ;
continue;
}
if ( ! F_290 ( V_2 ,
V_7 -> V_355 ,
V_7 -> V_9 ) ) {
F_293 ( V_364 L_15 ,
F_87 ( V_7 ) ,
F_87 ( V_7 ) + F_28 ( V_7 ) ,
V_7 -> V_9 ) ;
V_363 ++ ;
continue;
}
}
F_16 ( V_363 ) ;
#endif
}
static int
F_294 ( struct V_6 * V_7 ,
struct V_256 * V_255 ,
unsigned V_365 ,
bool V_327 ,
bool V_366 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
T_9 * V_16 = V_2 -> V_27 ;
T_4 V_17 , V_367 , V_368 , V_369 ;
T_1 V_370 =
V_327 ? V_16 -> V_42 . V_43 : V_255 -> V_48 ;
struct V_221 * V_177 ;
int V_23 ;
V_367 = F_153 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ) ;
V_368 = F_154 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , true ) ;
V_369 =
F_154 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , false ) ;
if ( V_365 == 0 )
V_365 = V_327 ? V_368 :
V_369 ;
if ( V_327 && V_365 & ( V_368 - 1 ) ) {
F_13 ( L_16 , V_365 ) ;
return - V_40 ;
}
V_17 = V_327 ? V_367 : V_7 -> V_8 . V_17 ;
if ( V_7 -> V_8 . V_17 > V_370 ) {
F_13 ( L_17 ,
V_7 -> V_8 . V_17 ,
V_327 ? L_18 : L_19 ,
V_370 ) ;
return - V_201 ;
}
V_23 = F_63 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_64 ( V_7 ) ;
F_103 ( ! F_270 ( V_255 ) ) ;
V_177 = F_295 ( V_7 , V_255 ) ;
if ( F_146 ( V_177 ) ) {
V_23 = F_200 ( V_177 ) ;
goto V_371;
}
F_16 ( ! F_262 ( & V_7 -> V_321 ) ) ;
V_372:
V_23 = F_296 ( & V_255 -> V_18 , & V_177 -> V_323 ,
V_17 , V_365 ,
V_7 -> V_9 , 0 , V_370 ,
V_373 ) ;
if ( V_23 ) {
V_23 = F_297 ( V_2 , V_255 , V_17 , V_365 ,
V_7 -> V_9 ,
V_327 ,
V_366 ) ;
if ( V_23 == 0 )
goto V_372;
goto V_374;
}
if ( F_16 ( ! F_290 ( V_2 , & V_177 -> V_323 ,
V_7 -> V_9 ) ) ) {
V_23 = - V_40 ;
goto V_375;
}
V_23 = F_298 ( V_7 ) ;
if ( V_23 )
goto V_375;
F_183 ( & V_7 -> V_212 , & V_16 -> V_18 . V_220 ) ;
F_201 ( & V_177 -> V_254 , & V_255 -> V_258 ) ;
if ( F_270 ( V_255 ) ) {
bool V_108 , V_376 ;
V_376 = ( V_177 -> V_323 . V_17 == V_367 &&
( V_177 -> V_323 . V_79 & ( V_368 - 1 ) ) == 0 ) ;
V_108 = ( V_177 -> V_323 . V_79 + V_7 -> V_8 . V_17 <=
V_16 -> V_42 . V_43 ) ;
V_7 -> V_327 = V_108 && V_376 ;
}
F_16 ( V_327 && ! V_7 -> V_327 ) ;
F_299 ( V_177 , V_327 ) ;
F_292 ( V_2 ) ;
return 0 ;
V_375:
F_271 ( & V_177 -> V_323 ) ;
V_374:
F_264 ( V_177 ) ;
V_371:
F_72 ( V_7 ) ;
return V_23 ;
}
bool
F_93 ( struct V_6 * V_7 ,
bool V_377 )
{
if ( V_7 -> V_208 == NULL )
return false ;
if ( V_7 -> V_378 )
return false ;
if ( ! V_377 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) )
return false ;
F_300 ( V_7 ) ;
F_301 ( V_7 -> V_208 ) ;
return true ;
}
static void
F_302 ( struct V_6 * V_7 )
{
T_3 V_319 ;
if ( V_7 -> V_8 . V_112 != V_168 )
return;
F_303 () ;
V_319 = V_7 -> V_8 . V_112 ;
V_7 -> V_8 . V_112 = 0 ;
F_261 ( V_7 ,
V_7 -> V_8 . V_89 ,
V_319 ) ;
}
static void
F_143 ( struct V_6 * V_7 ,
bool V_377 )
{
T_3 V_319 ;
if ( V_7 -> V_8 . V_112 != V_90 )
return;
if ( F_93 ( V_7 , V_377 ) )
F_94 ( V_7 -> V_8 . V_2 ) ;
V_319 = V_7 -> V_8 . V_112 ;
V_7 -> V_8 . V_112 = 0 ;
F_261 ( V_7 ,
V_7 -> V_8 . V_89 ,
V_319 ) ;
}
int
F_85 ( struct V_6 * V_7 , bool V_182 )
{
T_9 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
T_3 V_319 , V_320 ;
int V_23 ;
if ( ! F_19 ( V_7 ) )
return - V_40 ;
if ( V_7 -> V_8 . V_112 == V_168 )
return 0 ;
V_23 = F_62 ( V_7 , ! V_182 ) ;
if ( V_23 )
return V_23 ;
F_143 ( V_7 , false ) ;
if ( ( V_7 -> V_8 . V_89 & V_168 ) == 0 )
F_260 () ;
V_319 = V_7 -> V_8 . V_112 ;
V_320 = V_7 -> V_8 . V_89 ;
F_103 ( ( V_7 -> V_8 . V_112 & ~ V_168 ) != 0 ) ;
V_7 -> V_8 . V_89 |= V_168 ;
if ( V_182 ) {
V_7 -> V_8 . V_89 = V_168 ;
V_7 -> V_8 . V_112 = V_168 ;
V_7 -> V_113 = 1 ;
}
F_261 ( V_7 ,
V_320 ,
V_319 ) ;
if ( F_18 ( V_7 ) ) {
struct V_221 * V_177 = F_304 ( V_7 ) ;
if ( V_177 )
F_183 ( & V_177 -> V_254 ,
& V_16 -> V_42 . V_8 . V_258 ) ;
}
return 0 ;
}
int F_305 ( struct V_6 * V_7 ,
enum V_3 V_9 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
T_9 * V_16 = V_2 -> V_27 ;
struct V_221 * V_177 ;
int V_23 ;
if ( V_7 -> V_9 == V_9 )
return 0 ;
if ( V_7 -> V_46 ) {
F_306 ( L_20 ) ;
return - V_193 ;
}
F_27 (vma, &obj->vma_list, vma_link) {
if ( ! F_290 ( V_2 , & V_177 -> V_323 , V_9 ) ) {
V_23 = F_185 ( V_177 ) ;
if ( V_23 )
return V_23 ;
break;
}
}
if ( F_19 ( V_7 ) ) {
V_23 = F_265 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_259 ( V_7 ) ;
if ( F_22 ( V_2 ) -> V_41 < 6 ) {
V_23 = F_86 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_7 -> V_324 )
F_307 ( V_7 , V_9 ) ;
if ( V_7 -> V_325 )
F_308 ( V_16 -> V_18 . V_326 ,
V_7 , V_9 ) ;
}
F_27 (vma, &obj->vma_list, vma_link)
V_177 -> V_323 . V_361 = V_9 ;
V_7 -> V_9 = V_9 ;
if ( F_3 ( V_7 ) ) {
T_4 V_320 , V_319 ;
F_16 ( V_7 -> V_8 . V_112 & ~ V_90 ) ;
V_320 = V_7 -> V_8 . V_89 ;
V_319 = V_7 -> V_8 . V_112 ;
V_7 -> V_8 . V_89 = V_90 ;
V_7 -> V_8 . V_112 = V_90 ;
F_261 ( V_7 ,
V_320 ,
V_319 ) ;
}
F_292 ( V_2 ) ;
return 0 ;
}
int F_309 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_379 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
switch ( V_7 -> V_9 ) {
case V_380 :
case V_381 :
args -> V_382 = V_383 ;
break;
case V_384 :
args -> V_382 = V_385 ;
break;
default:
args -> V_382 = V_386 ;
break;
}
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_310 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_379 * args = V_31 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_23 ;
switch ( args -> V_382 ) {
case V_386 :
V_4 = V_5 ;
break;
case V_383 :
V_4 = V_380 ;
break;
case V_385 :
V_4 = F_311 ( V_2 ) ? V_384 : V_5 ;
break;
default:
return - V_40 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
V_23 = F_305 ( V_7 , V_4 ) ;
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static bool F_312 ( struct V_6 * V_7 )
{
return V_7 -> V_46 - ! ! V_7 -> V_387 ;
}
int
F_313 ( struct V_6 * V_7 ,
T_4 V_365 ,
struct V_123 * V_388 )
{
T_4 V_320 , V_319 ;
int V_23 ;
if ( V_388 != V_7 -> V_124 ) {
V_23 = F_255 ( V_7 , V_388 ) ;
if ( V_23 )
return V_23 ;
}
V_7 -> V_10 = true ;
V_23 = F_305 ( V_7 ,
F_311 ( V_7 -> V_8 . V_2 ) ? V_384 : V_5 ) ;
if ( V_23 )
goto V_389;
V_23 = F_84 ( V_7 , V_365 , true , false ) ;
if ( V_23 )
goto V_389;
F_143 ( V_7 , true ) ;
V_319 = V_7 -> V_8 . V_112 ;
V_320 = V_7 -> V_8 . V_89 ;
V_7 -> V_8 . V_112 = 0 ;
V_7 -> V_8 . V_89 |= V_168 ;
F_261 ( V_7 ,
V_320 ,
V_319 ) ;
return 0 ;
V_389:
V_7 -> V_10 = F_312 ( V_7 ) ;
return V_23 ;
}
void
F_314 ( struct V_6 * V_7 )
{
F_88 ( V_7 ) ;
V_7 -> V_10 = F_312 ( V_7 ) ;
}
int
F_265 ( struct V_6 * V_7 )
{
int V_23 ;
if ( ( V_7 -> V_8 . V_89 & V_162 ) == 0 )
return 0 ;
V_23 = F_62 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_8 . V_89 &= ~ V_162 ;
return 0 ;
}
int
F_141 ( struct V_6 * V_7 , bool V_182 )
{
T_3 V_319 , V_320 ;
int V_23 ;
if ( V_7 -> V_8 . V_112 == V_90 )
return 0 ;
V_23 = F_62 ( V_7 , ! V_182 ) ;
if ( V_23 )
return V_23 ;
F_302 ( V_7 ) ;
V_319 = V_7 -> V_8 . V_112 ;
V_320 = V_7 -> V_8 . V_89 ;
if ( ( V_7 -> V_8 . V_89 & V_90 ) == 0 ) {
F_93 ( V_7 , false ) ;
V_7 -> V_8 . V_89 |= V_90 ;
}
F_103 ( ( V_7 -> V_8 . V_112 & ~ V_90 ) != 0 ) ;
if ( V_182 ) {
V_7 -> V_8 . V_89 = V_90 ;
V_7 -> V_8 . V_112 = V_90 ;
}
F_261 ( V_7 ,
V_320 ,
V_319 ) ;
return 0 ;
}
static int
F_315 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_130 * V_131 = V_33 -> V_165 ;
unsigned long V_390 = V_158 - F_119 ( 20 ) ;
struct V_264 * V_265 ;
struct V_123 * V_124 = NULL ;
unsigned V_133 ;
T_4 V_125 = 0 ;
int V_23 ;
V_23 = F_10 ( & V_16 -> V_28 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_99 ( & V_16 -> V_28 , false ) ;
if ( V_23 )
return V_23 ;
F_7 ( & V_131 -> V_18 . V_279 ) ;
F_27 (request, &file_priv->mm.request_list, client_list) {
if ( F_316 ( V_265 -> V_276 , V_390 ) )
break;
V_124 = V_265 -> V_124 ;
V_125 = V_265 -> V_125 ;
}
V_133 = F_124 ( & V_16 -> V_28 . V_133 ) ;
F_8 ( & V_131 -> V_18 . V_279 ) ;
if ( V_125 == 0 )
return 0 ;
V_23 = F_112 ( V_124 , V_125 , V_133 , true , NULL , NULL ) ;
if ( V_23 == 0 )
F_223 ( V_16 -> V_144 , & V_16 -> V_18 . V_283 , 0 ) ;
return V_23 ;
}
int
F_317 ( struct V_6 * V_7 ,
struct V_256 * V_255 ,
T_3 V_365 ,
bool V_327 ,
bool V_366 )
{
struct V_221 * V_177 ;
int V_23 ;
if ( F_16 ( V_7 -> V_46 == V_391 ) )
return - V_193 ;
F_16 ( V_327 && ! F_270 ( V_255 ) ) ;
V_177 = F_206 ( V_7 , V_255 ) ;
if ( V_177 ) {
if ( ( V_365 &&
V_177 -> V_323 . V_79 & ( V_365 - 1 ) ) ||
( V_327 && ! V_7 -> V_327 ) ) {
F_114 ( V_7 -> V_46 ,
L_21
L_22
L_23 ,
F_228 ( V_7 , V_255 ) , V_365 ,
V_327 ,
V_7 -> V_327 ) ;
V_23 = F_185 ( V_177 ) ;
if ( V_23 )
return V_23 ;
}
}
if ( ! F_318 ( V_7 , V_255 ) ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
V_23 = F_294 ( V_7 , V_255 , V_365 ,
V_327 ,
V_366 ) ;
if ( V_23 )
return V_23 ;
if ( ! V_16 -> V_18 . V_326 )
F_307 ( V_7 , V_7 -> V_9 ) ;
}
if ( ! V_7 -> V_324 && V_327 )
F_307 ( V_7 , V_7 -> V_9 ) ;
V_7 -> V_46 ++ ;
V_7 -> V_392 |= V_327 ;
return 0 ;
}
void
F_88 ( struct V_6 * V_7 )
{
F_103 ( V_7 -> V_46 == 0 ) ;
F_103 ( ! F_19 ( V_7 ) ) ;
if ( -- V_7 -> V_46 == 0 )
V_7 -> V_392 = false ;
}
int
F_319 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_393 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( V_7 -> V_202 != V_203 ) {
F_13 ( L_24 ) ;
V_23 = - V_40 ;
goto V_93;
}
if ( V_7 -> V_394 != NULL && V_7 -> V_394 != V_33 ) {
F_13 ( L_25 ,
args -> V_53 ) ;
V_23 = - V_40 ;
goto V_93;
}
if ( V_7 -> V_387 == V_395 ) {
V_23 = - V_193 ;
goto V_93;
}
if ( V_7 -> V_387 == 0 ) {
V_23 = F_84 ( V_7 , args -> V_365 , true , false ) ;
if ( V_23 )
goto V_93;
}
V_7 -> V_387 ++ ;
V_7 -> V_394 = V_33 ;
args -> V_83 = F_87 ( V_7 ) ;
V_93:
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_320 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_393 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( V_7 -> V_394 != V_33 ) {
F_13 ( L_26 ,
args -> V_53 ) ;
V_23 = - V_40 ;
goto V_93;
}
V_7 -> V_387 -- ;
if ( V_7 -> V_387 == 0 ) {
V_7 -> V_394 = NULL ;
F_88 ( V_7 ) ;
}
V_93:
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_321 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_396 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
V_23 = F_251 ( V_7 ) ;
args -> V_397 = V_7 -> V_30 ;
if ( V_7 -> V_124 ) {
F_322 ( V_398 > 16 ) ;
args -> V_397 |= F_120 ( V_7 -> V_124 ) << 16 ;
}
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_323 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_131 )
{
return F_315 ( V_2 , V_131 ) ;
}
int
F_324 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_131 )
{
struct V_399 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
switch ( args -> V_202 ) {
case V_207 :
case V_203 :
break;
default:
return - V_40 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_131 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( V_7 -> V_46 ) {
V_23 = - V_40 ;
goto V_93;
}
if ( V_7 -> V_202 != V_206 )
V_7 -> V_202 = args -> V_202 ;
if ( F_169 ( V_7 ) && V_7 -> V_208 == NULL )
F_166 ( V_7 ) ;
args -> V_400 = V_7 -> V_202 != V_206 ;
V_93:
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void F_325 ( struct V_6 * V_7 ,
const struct V_209 * V_210 )
{
F_179 ( & V_7 -> V_212 ) ;
F_179 ( & V_7 -> V_245 ) ;
F_179 ( & V_7 -> V_401 ) ;
F_179 ( & V_7 -> V_321 ) ;
V_7 -> V_210 = V_210 ;
V_7 -> V_13 = V_14 ;
V_7 -> V_202 = V_203 ;
V_7 -> V_327 = true ;
F_6 ( V_7 -> V_8 . V_2 -> V_27 , V_7 -> V_8 . V_17 ) ;
}
struct V_6 * F_35 ( struct V_1 * V_2 ,
T_1 V_17 )
{
struct V_6 * V_7 ;
struct V_226 * V_99 ;
T_12 V_402 ;
V_7 = F_29 ( V_2 ) ;
if ( V_7 == NULL )
return NULL ;
if ( F_326 ( V_2 , & V_7 -> V_8 , V_17 ) != 0 ) {
F_31 ( V_7 ) ;
return NULL ;
}
V_402 = V_403 | V_404 ;
if ( F_327 ( V_2 ) || F_328 ( V_2 ) ) {
V_402 &= ~ V_405 ;
V_402 |= V_242 ;
}
V_99 = F_167 ( V_7 -> V_8 . V_97 ) -> V_233 ;
F_329 ( V_99 , V_402 ) ;
F_325 ( V_7 , & V_406 ) ;
V_7 -> V_8 . V_112 = V_90 ;
V_7 -> V_8 . V_89 = V_90 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_9 = V_380 ;
} else
V_7 -> V_9 = V_5 ;
F_330 ( V_7 ) ;
return V_7 ;
}
void F_331 ( struct V_171 * V_407 )
{
struct V_6 * V_7 = F_75 ( V_407 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
T_9 * V_16 = V_2 -> V_27 ;
struct V_221 * V_177 , * V_218 ;
F_332 ( V_7 ) ;
if ( V_7 -> V_118 )
F_333 ( V_2 , V_7 ) ;
V_7 -> V_46 = 0 ;
F_16 ( ! F_180 ( & V_7 -> V_321 ) &&
! F_262 ( & V_7 -> V_321 ) ) ;
F_178 (vma, next, &obj->vma_list, vma_link) {
int V_23 = F_185 ( V_177 ) ;
if ( F_16 ( V_23 == - V_155 ) ) {
bool V_408 ;
V_408 = V_16 -> V_18 . V_121 ;
V_16 -> V_18 . V_121 = false ;
F_16 ( F_185 ( V_177 ) ) ;
V_16 -> V_18 . V_121 = V_408 ;
}
}
if ( V_7 -> V_378 )
F_72 ( V_7 ) ;
if ( F_16 ( V_7 -> V_211 ) )
V_7 -> V_211 = 0 ;
F_175 ( V_7 ) ;
F_161 ( V_7 ) ;
F_334 ( V_7 ) ;
F_103 ( V_7 -> V_208 ) ;
if ( V_7 -> V_8 . V_409 )
F_335 ( & V_7 -> V_8 , NULL ) ;
F_336 ( & V_7 -> V_8 ) ;
F_9 ( V_16 , V_7 -> V_8 . V_17 ) ;
F_174 ( V_7 -> V_410 ) ;
F_31 ( V_7 ) ;
}
struct V_221 * F_206 ( struct V_6 * V_7 ,
struct V_256 * V_255 )
{
struct V_221 * V_177 ;
F_27 (vma, &obj->vma_list, vma_link)
if ( V_177 -> V_255 == V_255 )
return V_177 ;
return NULL ;
}
static struct V_221 * F_337 ( struct V_6 * V_7 ,
struct V_256 * V_255 )
{
struct V_221 * V_177 = F_338 ( sizeof( * V_177 ) , V_51 ) ;
if ( V_177 == NULL )
return F_339 ( - V_54 ) ;
F_179 ( & V_177 -> V_322 ) ;
F_179 ( & V_177 -> V_254 ) ;
F_179 ( & V_177 -> V_411 ) ;
V_177 -> V_255 = V_255 ;
V_177 -> V_7 = V_7 ;
if ( F_270 ( V_255 ) )
F_340 ( & V_177 -> V_322 , & V_7 -> V_321 ) ;
else
F_201 ( & V_177 -> V_322 , & V_7 -> V_321 ) ;
return V_177 ;
}
struct V_221 *
F_295 ( struct V_6 * V_7 ,
struct V_256 * V_255 )
{
struct V_221 * V_177 ;
V_177 = F_206 ( V_7 , V_255 ) ;
if ( ! V_177 )
V_177 = F_337 ( V_7 , V_255 ) ;
return V_177 ;
}
void F_264 ( struct V_221 * V_177 )
{
F_16 ( V_177 -> V_323 . V_359 ) ;
if ( ! F_180 ( & V_177 -> V_411 ) )
return;
F_176 ( & V_177 -> V_322 ) ;
F_174 ( V_177 ) ;
}
int
F_341 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
int V_23 = 0 ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_16 -> V_281 . V_282 )
goto V_363;
V_23 = F_274 ( V_2 ) ;
if ( V_23 )
goto V_363;
F_211 ( V_2 ) ;
if ( ! F_21 ( V_2 , V_35 ) )
F_187 ( V_2 ) ;
F_342 ( V_2 ) ;
F_244 ( V_2 ) ;
V_16 -> V_281 . V_282 = ! F_21 ( V_2 ,
V_35 ) ;
F_25 ( & V_2 -> V_29 ) ;
F_343 ( & V_16 -> V_28 . V_412 ) ;
F_222 ( & V_16 -> V_18 . V_283 ) ;
F_222 ( & V_16 -> V_18 . V_145 ) ;
return 0 ;
V_363:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_344 ( struct V_123 * V_124 , int V_413 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
T_9 * V_16 = V_2 -> V_27 ;
T_4 V_414 = V_415 + ( V_413 * 0x200 ) ;
T_4 * V_416 = V_16 -> V_417 . V_416 [ V_413 ] ;
int V_225 , V_23 ;
if ( ! F_345 ( V_2 ) || ! V_416 )
return 0 ;
V_23 = F_346 ( V_124 , V_418 / 4 * 3 ) ;
if ( V_23 )
return V_23 ;
for ( V_225 = 0 ; V_225 < V_418 ; V_225 += 4 ) {
F_347 ( V_124 , F_348 ( 1 ) ) ;
F_347 ( V_124 , V_414 + V_225 ) ;
F_347 ( V_124 , V_416 [ V_225 / 4 ] ) ;
}
F_349 ( V_124 ) ;
return V_23 ;
}
void F_350 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
if ( F_22 ( V_2 ) -> V_41 < 5 ||
V_16 -> V_18 . V_419 == V_420 )
return;
F_277 ( V_421 , F_351 ( V_421 ) |
V_422 ) ;
if ( F_352 ( V_2 ) )
return;
F_277 ( V_423 , F_351 ( V_423 ) | V_424 ) ;
if ( F_353 ( V_2 ) )
F_277 ( V_425 , F_354 ( V_426 ) ) ;
else if ( F_355 ( V_2 ) )
F_277 ( V_425 , F_354 ( V_427 ) ) ;
else if ( F_356 ( V_2 ) )
F_277 ( V_428 , F_354 ( V_429 ) ) ;
else
F_286 () ;
}
static bool
F_357 ( struct V_1 * V_2 )
{
if ( ! F_358 ( V_2 ) )
return false ;
if ( F_353 ( V_2 ) && V_2 -> V_430 -> V_431 < 8 ) {
F_359 ( L_27
L_28 ) ;
return false ;
}
return true ;
}
static int F_360 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
V_23 = F_361 ( V_2 ) ;
if ( V_23 )
return V_23 ;
if ( F_362 ( V_2 ) ) {
V_23 = F_363 ( V_2 ) ;
if ( V_23 )
goto V_432;
}
if ( F_357 ( V_2 ) ) {
V_23 = F_364 ( V_2 ) ;
if ( V_23 )
goto V_433;
}
if ( F_365 ( V_2 ) ) {
V_23 = F_366 ( V_2 ) ;
if ( V_23 )
goto V_434;
}
V_23 = F_214 ( V_2 , ( ( T_4 ) ~ 0 - 0x1000 ) ) ;
if ( V_23 )
goto V_435;
return 0 ;
V_435:
F_367 ( & V_16 -> V_124 [ V_436 ] ) ;
V_434:
F_367 ( & V_16 -> V_124 [ V_437 ] ) ;
V_433:
F_367 ( & V_16 -> V_124 [ V_438 ] ) ;
V_432:
F_367 ( & V_16 -> V_124 [ V_439 ] ) ;
return V_23 ;
}
int
F_368 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
int V_23 , V_225 ;
if ( F_22 ( V_2 ) -> V_41 < 6 && ! F_369 () )
return - V_26 ;
if ( V_16 -> V_440 )
F_277 ( V_441 , F_351 ( V_441 ) | F_370 ( 0xf ) ) ;
if ( F_371 ( V_2 ) )
F_277 ( V_442 , F_372 ( V_2 ) ?
V_443 : V_444 ) ;
if ( F_373 ( V_2 ) ) {
T_4 V_445 = F_351 ( V_446 ) ;
V_445 &= ~ ( V_447 | V_448 ) ;
F_277 ( V_446 , V_445 ) ;
}
F_350 ( V_2 ) ;
V_23 = F_360 ( V_2 ) ;
if ( V_23 )
return V_23 ;
for ( V_225 = 0 ; V_225 < F_374 ( V_2 ) ; V_225 ++ )
F_344 ( & V_16 -> V_124 [ V_439 ] , V_225 ) ;
F_375 ( V_2 ) ;
if ( V_16 -> V_18 . V_326 ) {
V_23 = V_16 -> V_18 . V_326 -> V_349 ( V_2 ) ;
if ( V_23 ) {
F_376 ( V_2 ) ;
F_359 ( L_29 ) ;
}
}
return 0 ;
}
int F_377 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
F_23 ( & V_2 -> V_29 ) ;
if ( F_378 ( V_2 ) ) {
F_277 ( V_449 , 1 ) ;
if ( F_379 ( ( F_351 ( V_450 ) & 1 ) == 1 , 10 ) )
F_380 ( L_30 ) ;
}
F_381 ( V_2 ) ;
V_23 = F_368 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
if ( V_23 ) {
F_376 ( V_2 ) ;
return V_23 ;
}
if ( ! F_21 ( V_2 , V_35 ) )
V_16 -> V_451 . V_452 = 1 ;
return 0 ;
}
void
F_244 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 ;
int V_225 ;
F_209 (ring, dev_priv, i)
F_367 ( V_124 ) ;
}
int
F_382 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_131 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( F_21 ( V_2 , V_35 ) )
return 0 ;
if ( F_100 ( & V_16 -> V_28 ) ) {
F_13 ( L_31 ) ;
F_383 ( & V_16 -> V_28 . V_133 , 0 ) ;
}
F_23 ( & V_2 -> V_29 ) ;
V_16 -> V_281 . V_282 = 0 ;
V_23 = F_368 ( V_2 ) ;
if ( V_23 != 0 ) {
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
F_103 ( ! F_180 ( & V_16 -> V_42 . V_8 . V_246 ) ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_384 ( V_2 ) ;
if ( V_23 )
goto V_453;
return 0 ;
V_453:
F_23 ( & V_2 -> V_29 ) ;
F_244 ( V_2 ) ;
V_16 -> V_281 . V_282 = 1 ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_385 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_131 )
{
if ( F_21 ( V_2 , V_35 ) )
return 0 ;
F_386 ( V_2 ) ;
return F_341 ( V_2 ) ;
}
void
F_387 ( struct V_1 * V_2 )
{
int V_23 ;
if ( F_21 ( V_2 , V_35 ) )
return;
V_23 = F_341 ( V_2 ) ;
if ( V_23 )
F_13 ( L_32 , V_23 ) ;
}
static void
F_388 ( struct V_123 * V_124 )
{
F_179 ( & V_124 -> V_246 ) ;
F_179 ( & V_124 -> V_277 ) ;
}
static void F_389 ( struct V_15 * V_16 ,
struct V_256 * V_255 )
{
V_255 -> V_2 = V_16 -> V_2 ;
F_179 ( & V_255 -> V_246 ) ;
F_179 ( & V_255 -> V_258 ) ;
F_179 ( & V_255 -> V_454 ) ;
F_340 ( & V_255 -> V_454 , & V_16 -> V_455 ) ;
}
void
F_390 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
int V_225 ;
V_16 -> V_50 =
F_391 ( L_33 ,
sizeof( struct V_6 ) , 0 ,
V_456 ,
NULL ) ;
F_179 ( & V_16 -> V_455 ) ;
F_389 ( V_16 , & V_16 -> V_42 . V_8 ) ;
F_179 ( & V_16 -> V_457 ) ;
F_179 ( & V_16 -> V_18 . V_244 ) ;
F_179 ( & V_16 -> V_18 . V_220 ) ;
F_179 ( & V_16 -> V_18 . V_253 ) ;
for ( V_225 = 0 ; V_225 < V_398 ; V_225 ++ )
F_388 ( & V_16 -> V_124 [ V_225 ] ) ;
for ( V_225 = 0 ; V_225 < V_458 ; V_225 ++ )
F_179 ( & V_16 -> V_251 [ V_225 ] . V_252 ) ;
F_392 ( & V_16 -> V_18 . V_283 ,
F_246 ) ;
F_392 ( & V_16 -> V_18 . V_145 ,
F_249 ) ;
F_393 ( & V_16 -> V_28 . V_24 ) ;
if ( F_394 ( V_2 ) ) {
F_277 ( V_459 ,
F_354 ( V_460 ) ) ;
}
V_16 -> V_461 = V_462 ;
if ( ! F_21 ( V_2 , V_35 ) )
V_16 -> V_351 = 3 ;
if ( F_22 ( V_2 ) -> V_41 >= 7 && ! F_378 ( V_2 ) )
V_16 -> V_305 = 32 ;
else if ( F_22 ( V_2 ) -> V_41 >= 4 || F_395 ( V_2 ) || F_396 ( V_2 ) || F_155 ( V_2 ) )
V_16 -> V_305 = 16 ;
else
V_16 -> V_305 = 8 ;
F_179 ( & V_16 -> V_18 . V_253 ) ;
F_240 ( V_2 ) ;
F_397 ( V_2 ) ;
F_393 ( & V_16 -> V_463 ) ;
V_16 -> V_18 . V_121 = true ;
V_16 -> V_18 . V_464 . V_465 = V_466 ;
V_16 -> V_18 . V_464 . V_467 = V_468 ;
V_16 -> V_18 . V_464 . V_469 = V_470 ;
F_398 ( & V_16 -> V_18 . V_464 ) ;
}
static int F_399 ( struct V_1 * V_2 ,
int V_128 , int V_17 , int V_471 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_472 * V_118 ;
int V_23 ;
if ( V_16 -> V_18 . V_473 [ V_128 - 1 ] || ! V_17 )
return 0 ;
V_118 = F_338 ( sizeof( * V_118 ) , V_51 ) ;
if ( ! V_118 )
return - V_54 ;
V_118 -> V_128 = V_128 ;
V_118 -> V_53 = F_400 ( V_2 , V_17 , V_471 ) ;
if ( ! V_118 -> V_53 ) {
V_23 = - V_54 ;
goto V_474;
}
#ifdef F_401
F_402 ( ( unsigned long ) V_118 -> V_53 -> V_75 , V_118 -> V_53 -> V_17 / V_39 ) ;
#endif
V_16 -> V_18 . V_473 [ V_128 - 1 ] = V_118 ;
return 0 ;
V_474:
F_174 ( V_118 ) ;
return V_23 ;
}
static void F_403 ( struct V_1 * V_2 , int V_128 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_472 * V_118 ;
if ( ! V_16 -> V_18 . V_473 [ V_128 - 1 ] )
return;
V_118 = V_16 -> V_18 . V_473 [ V_128 - 1 ] ;
if ( V_118 -> V_475 ) {
F_333 ( V_2 , V_118 -> V_475 ) ;
}
#ifdef F_401
F_404 ( ( unsigned long ) V_118 -> V_53 -> V_75 , V_118 -> V_53 -> V_17 / V_39 ) ;
#endif
F_405 ( V_2 , V_118 -> V_53 ) ;
F_174 ( V_118 ) ;
V_16 -> V_18 . V_473 [ V_128 - 1 ] = NULL ;
}
void F_406 ( struct V_1 * V_2 )
{
int V_225 ;
for ( V_225 = V_476 ; V_225 <= V_477 ; V_225 ++ )
F_403 ( V_2 , V_225 ) ;
}
void F_333 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_226 * V_99 = F_167 ( V_7 -> V_8 . V_97 ) -> V_233 ;
char * V_75 ;
int V_225 ;
int V_224 ;
if ( ! V_7 -> V_118 )
return;
V_75 = V_7 -> V_118 -> V_53 -> V_75 ;
V_224 = V_7 -> V_8 . V_17 / V_39 ;
for ( V_225 = 0 ; V_225 < V_224 ; V_225 ++ ) {
struct V_69 * V_69 = F_407 ( V_99 , V_225 ) ;
if ( ! F_146 ( V_69 ) ) {
char * V_478 = F_49 ( V_69 ) ;
memcpy ( V_478 , V_75 + V_225 * V_39 , V_39 ) ;
F_52 ( V_478 ) ;
F_408 ( & V_69 , 1 ) ;
F_92 ( V_69 ) ;
F_71 ( V_69 ) ;
F_172 ( V_69 ) ;
}
}
F_94 ( V_2 ) ;
V_7 -> V_118 -> V_475 = NULL ;
V_7 -> V_118 = NULL ;
}
int
F_409 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_128 ,
int V_471 )
{
struct V_226 * V_99 = F_167 ( V_7 -> V_8 . V_97 ) -> V_233 ;
T_9 * V_16 = V_2 -> V_27 ;
int V_23 = 0 ;
int V_224 ;
int V_225 ;
if ( V_128 > V_477 )
return - V_40 ;
if ( V_7 -> V_118 ) {
if ( V_7 -> V_118 -> V_128 == V_128 )
return 0 ;
F_333 ( V_2 , V_7 ) ;
}
if ( ! V_16 -> V_18 . V_473 [ V_128 - 1 ] ) {
V_23 = F_399 ( V_2 , V_128 ,
V_7 -> V_8 . V_17 , V_471 ) ;
if ( V_23 ) {
F_13 ( L_34 ,
V_128 , V_7 -> V_8 . V_17 ) ;
return V_23 ;
}
}
V_7 -> V_118 = V_16 -> V_18 . V_473 [ V_128 - 1 ] ;
V_7 -> V_118 -> V_475 = V_7 ;
V_224 = V_7 -> V_8 . V_17 / V_39 ;
for ( V_225 = 0 ; V_225 < V_224 ; V_225 ++ ) {
struct V_69 * V_69 ;
char * V_478 , * V_479 ;
V_69 = F_407 ( V_99 , V_225 ) ;
if ( F_146 ( V_69 ) )
return F_200 ( V_69 ) ;
V_479 = F_49 ( V_69 ) ;
V_478 = V_7 -> V_118 -> V_53 -> V_75 + ( V_225 * V_39 ) ;
memcpy ( V_478 , V_479 , V_39 ) ;
F_52 ( V_479 ) ;
F_71 ( V_69 ) ;
F_172 ( V_69 ) ;
}
return 0 ;
}
static int
F_98 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_105 * args ,
struct V_32 * V_131 )
{
void * V_75 = V_7 -> V_118 -> V_53 -> V_75 + args -> V_83 ;
char T_5 * V_72 = F_60 ( args -> V_88 ) ;
if ( F_81 ( V_75 , V_72 , args -> V_17 ) ) {
unsigned long V_103 ;
F_25 ( & V_2 -> V_29 ) ;
V_103 = F_410 ( V_75 , V_72 , args -> V_17 ) ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_103 )
return - V_76 ;
}
F_94 ( V_2 ) ;
return 0 ;
}
void F_411 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_130 * V_131 = V_33 -> V_165 ;
F_222 ( & V_131 -> V_18 . V_145 ) ;
F_7 ( & V_131 -> V_18 . V_279 ) ;
while ( ! F_180 ( & V_131 -> V_18 . V_277 ) ) {
struct V_264 * V_265 ;
V_265 = F_181 ( & V_131 -> V_18 . V_277 ,
struct V_264 ,
V_280 ) ;
F_176 ( & V_265 -> V_280 ) ;
V_265 -> V_131 = NULL ;
}
F_8 ( & V_131 -> V_18 . V_279 ) ;
}
static void
F_412 ( struct V_309 * V_310 )
{
struct V_130 * V_131 =
F_247 ( V_310 , F_182 ( * V_131 ) , V_18 . V_145 . V_310 ) ;
F_383 ( & V_131 -> V_132 , false ) ;
}
int F_413 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_130 * V_131 ;
F_380 ( L_35 ) ;
V_131 = F_338 ( sizeof( * V_131 ) , V_51 ) ;
if ( ! V_131 )
return - V_54 ;
V_33 -> V_165 = V_131 ;
V_131 -> V_16 = V_2 -> V_27 ;
F_414 ( & V_131 -> V_18 . V_279 ) ;
F_179 ( & V_131 -> V_18 . V_277 ) ;
F_392 ( & V_131 -> V_18 . V_145 ,
F_412 ) ;
F_415 ( & V_131 -> V_480 ) ;
return 0 ;
}
static bool F_416 ( struct V_481 * V_481 , struct V_127 * V_482 )
{
if ( ! F_104 ( V_481 ) )
return false ;
#if F_417 ( V_483 ) || F_417 ( V_484 )
return V_481 -> V_485 == V_482 ;
#else
return false ;
#endif
}
static unsigned long
V_468 ( struct V_486 * V_486 , struct V_487 * V_488 )
{
struct V_15 * V_16 =
F_247 ( V_486 ,
struct V_15 ,
V_18 . V_464 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_6 * V_7 ;
bool V_96 = true ;
unsigned long V_219 ;
if ( ! F_248 ( & V_2 -> V_29 ) ) {
if ( ! F_416 ( & V_2 -> V_29 , V_154 ) )
return 0 ;
if ( V_16 -> V_18 . V_200 )
return 0 ;
V_96 = false ;
}
V_219 = 0 ;
F_27 (obj, &dev_priv->mm.unbound_list, global_list)
if ( V_7 -> V_211 == 0 )
V_219 += V_7 -> V_8 . V_17 >> V_187 ;
F_27 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_7 -> V_30 )
continue;
if ( V_7 -> V_46 == 0 && V_7 -> V_211 == 0 )
V_219 += V_7 -> V_8 . V_17 >> V_187 ;
}
if ( V_96 )
F_25 ( & V_2 -> V_29 ) ;
return V_219 ;
}
unsigned long F_228 ( struct V_6 * V_489 ,
struct V_256 * V_255 )
{
struct V_15 * V_16 = V_489 -> V_8 . V_2 -> V_27 ;
struct V_221 * V_177 ;
if ( V_255 == & V_16 -> V_18 . V_326 -> V_8 )
V_255 = & V_16 -> V_42 . V_8 ;
F_103 ( F_180 ( & V_489 -> V_321 ) ) ;
F_27 (vma, &o->vma_list, vma_link) {
if ( V_177 -> V_255 == V_255 )
return V_177 -> V_323 . V_79 ;
}
return - 1 ;
}
bool F_318 ( struct V_6 * V_489 ,
struct V_256 * V_255 )
{
struct V_221 * V_177 ;
F_27 (vma, &o->vma_list, vma_link)
if ( V_177 -> V_255 == V_255 && F_263 ( & V_177 -> V_323 ) )
return true ;
return false ;
}
bool F_19 ( struct V_6 * V_489 )
{
struct V_221 * V_177 ;
F_27 (vma, &o->vma_list, vma_link)
if ( F_263 ( & V_177 -> V_323 ) )
return true ;
return false ;
}
unsigned long F_418 ( struct V_6 * V_489 ,
struct V_256 * V_255 )
{
struct V_15 * V_16 = V_489 -> V_8 . V_2 -> V_27 ;
struct V_221 * V_177 ;
if ( V_255 == & V_16 -> V_18 . V_326 -> V_8 )
V_255 = & V_16 -> V_42 . V_8 ;
F_103 ( F_180 ( & V_489 -> V_321 ) ) ;
F_27 (vma, &o->vma_list, vma_link)
if ( V_177 -> V_255 == V_255 )
return V_177 -> V_323 . V_17 ;
return 0 ;
}
static unsigned long
V_466 ( struct V_486 * V_486 , struct V_487 * V_488 )
{
struct V_15 * V_16 =
F_247 ( V_486 ,
struct V_15 ,
V_18 . V_464 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_223 ;
bool V_96 = true ;
if ( ! F_248 ( & V_2 -> V_29 ) ) {
if ( ! F_416 ( & V_2 -> V_29 , V_154 ) )
return V_490 ;
if ( V_16 -> V_18 . V_200 )
return V_490 ;
V_96 = false ;
}
V_223 = F_159 ( V_16 , V_488 -> V_491 ) ;
if ( V_223 < V_488 -> V_491 )
V_223 += F_177 ( V_16 ,
V_488 -> V_491 - V_223 ,
false ) ;
if ( V_223 < V_488 -> V_491 )
V_223 += F_160 ( V_16 ) ;
if ( V_96 )
F_25 ( & V_2 -> V_29 ) ;
return V_223 ;
}
struct V_221 * F_304 ( struct V_6 * V_7 )
{
struct V_221 * V_177 ;
if ( F_16 ( F_180 ( & V_7 -> V_321 ) ) )
return NULL ;
V_177 = F_181 ( & V_7 -> V_321 , F_182 ( * V_177 ) , V_322 ) ;
if ( F_16 ( V_177 -> V_255 != F_419 ( V_7 ) ) )
return NULL ;
return V_177 ;
}

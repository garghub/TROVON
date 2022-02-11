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
args -> V_56 = F_39 ( args -> V_57 * ( ( args -> V_58 + 7 ) / 8 ) , 64 ) ;
args -> V_17 = args -> V_56 * args -> V_59 ;
return F_33 ( V_33 , V_2 ,
args -> V_17 , & args -> V_53 ) ;
}
int
F_40 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_60 * args = V_31 ;
return F_33 ( V_33 , V_2 ,
args -> V_17 , & args -> V_53 ) ;
}
static inline int
F_41 ( char T_5 * V_61 ,
const char * V_62 , int V_63 ,
int V_64 )
{
int V_23 , V_65 = 0 ;
while ( V_64 > 0 ) {
int V_66 = F_39 ( V_63 + 1 , 64 ) ;
int V_67 = F_42 ( V_66 - V_63 , V_64 ) ;
int V_68 = V_63 ^ 64 ;
V_23 = F_43 ( V_61 + V_65 ,
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
F_44 ( char * V_62 , int V_63 ,
const char T_5 * V_61 ,
int V_64 )
{
int V_23 , V_65 = 0 ;
while ( V_64 > 0 ) {
int V_66 = F_39 ( V_63 + 1 , 64 ) ;
int V_67 = F_42 ( V_66 - V_63 , V_64 ) ;
int V_68 = V_63 ^ 64 ;
V_23 = F_45 ( V_62 + V_68 ,
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
F_46 ( struct V_69 * V_69 , int V_70 , int V_71 ,
char T_5 * V_72 ,
bool V_73 , bool V_74 )
{
char * V_75 ;
int V_23 ;
if ( F_47 ( V_73 ) )
return - V_40 ;
V_75 = F_48 ( V_69 ) ;
if ( V_74 )
F_49 ( V_75 + V_70 ,
V_71 ) ;
V_23 = F_50 ( V_72 ,
V_75 + V_70 ,
V_71 ) ;
F_51 ( V_75 ) ;
return V_23 ? - V_76 : 0 ;
}
static void
F_52 ( char * V_77 , unsigned long V_64 ,
bool V_78 )
{
if ( F_47 ( V_78 ) ) {
unsigned long V_79 = ( unsigned long ) V_77 ;
unsigned long V_80 = ( unsigned long ) V_77 + V_64 ;
V_79 = F_53 ( V_79 , 128 ) ;
V_80 = F_54 ( V_80 , 128 ) ;
F_49 ( ( void * ) V_79 , V_80 - V_79 ) ;
} else {
F_49 ( V_77 , V_64 ) ;
}
}
static int
F_55 ( struct V_69 * V_69 , int V_70 , int V_71 ,
char T_5 * V_72 ,
bool V_73 , bool V_74 )
{
char * V_75 ;
int V_23 ;
V_75 = F_56 ( V_69 ) ;
if ( V_74 )
F_52 ( V_75 + V_70 ,
V_71 ,
V_73 ) ;
if ( V_73 )
V_23 = F_41 ( V_72 ,
V_75 , V_70 ,
V_71 ) ;
else
V_23 = F_43 ( V_72 ,
V_75 + V_70 ,
V_71 ) ;
F_57 ( V_69 ) ;
return V_23 ? - V_76 : 0 ;
}
static int
F_58 ( struct V_1 * V_2 ,
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
V_72 = F_59 ( args -> V_88 ) ;
V_82 = args -> V_17 ;
V_84 = F_60 ( V_7 ) ;
if ( ! ( V_7 -> V_8 . V_89 & V_90 ) ) {
V_74 = ! F_1 ( V_2 , V_7 -> V_9 ) ;
if ( F_19 ( V_7 ) ) {
V_23 = F_61 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
}
}
V_23 = F_62 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_63 ( V_7 ) ;
V_83 = args -> V_83 ;
F_64 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_69 * V_69 = F_65 ( & V_87 ) ;
if ( V_82 <= 0 )
break;
V_70 = F_66 ( V_83 ) ;
V_71 = V_82 ;
if ( ( V_70 + V_71 ) > V_39 )
V_71 = V_39 - V_70 ;
V_73 = V_84 &&
( F_67 ( V_69 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_46 ( V_69 , V_70 , V_71 ,
V_72 , V_73 ,
V_74 ) ;
if ( V_23 == 0 )
goto V_91;
F_25 ( & V_2 -> V_29 ) ;
if ( F_68 ( ! V_92 ) && ! V_85 ) {
V_23 = F_69 ( V_72 , V_82 ) ;
( void ) V_23 ;
V_85 = 1 ;
}
V_23 = F_55 ( V_69 , V_70 , V_71 ,
V_72 , V_73 ,
V_74 ) ;
F_23 ( & V_2 -> V_29 ) ;
V_91:
F_70 ( V_69 ) ;
if ( V_23 )
goto V_93;
V_82 -= V_71 ;
V_72 += V_71 ;
V_83 += V_71 ;
}
V_93:
F_71 ( V_7 ) ;
return V_23 ;
}
int
F_72 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_81 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_73 ( V_94 ,
F_59 ( args -> V_88 ) ,
args -> V_17 ) )
return - V_76 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_74 ( F_75 ( V_2 , V_33 , args -> V_53 ) ) ;
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
F_76 ( V_7 , args -> V_83 , args -> V_17 ) ;
V_23 = F_58 ( V_2 , V_7 , args , V_33 ) ;
V_93:
F_77 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static inline int
F_78 ( struct V_98 * V_99 ,
T_7 V_100 , int V_101 ,
char T_5 * V_72 ,
int V_64 )
{
void T_8 * V_102 ;
void * V_75 ;
unsigned long V_103 ;
V_102 = F_79 ( V_99 , V_100 ) ;
V_75 = ( void V_104 * ) V_102 + V_101 ;
V_103 = F_80 ( V_75 ,
V_72 , V_64 ) ;
F_81 ( V_102 ) ;
return V_103 ;
}
static int
F_82 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_105 * args ,
struct V_32 * V_33 )
{
T_9 * V_16 = V_2 -> V_27 ;
T_6 V_82 ;
T_7 V_83 , V_100 ;
char T_5 * V_72 ;
int V_101 , V_71 , V_23 ;
V_23 = F_83 ( V_7 , 0 , true , true ) ;
if ( V_23 )
goto V_93;
V_23 = F_61 ( V_7 , true ) ;
if ( V_23 )
goto V_106;
V_23 = F_84 ( V_7 ) ;
if ( V_23 )
goto V_106;
V_72 = F_59 ( args -> V_88 ) ;
V_82 = args -> V_17 ;
V_83 = F_85 ( V_7 ) + args -> V_83 ;
while ( V_82 > 0 ) {
V_100 = V_83 & V_107 ;
V_101 = F_66 ( V_83 ) ;
V_71 = V_82 ;
if ( ( V_101 + V_82 ) > V_39 )
V_71 = V_39 - V_101 ;
if ( F_78 ( V_16 -> V_42 . V_108 , V_100 ,
V_101 , V_72 , V_71 ) ) {
V_23 = - V_76 ;
goto V_106;
}
V_82 -= V_71 ;
V_72 += V_71 ;
V_83 += V_71 ;
}
V_106:
F_86 ( V_7 ) ;
V_93:
return V_23 ;
}
static int
F_87 ( struct V_69 * V_69 , int V_70 , int V_71 ,
char T_5 * V_72 ,
bool V_73 ,
bool V_109 ,
bool V_110 )
{
char * V_75 ;
int V_23 ;
if ( F_47 ( V_73 ) )
return - V_40 ;
V_75 = F_48 ( V_69 ) ;
if ( V_109 )
F_49 ( V_75 + V_70 ,
V_71 ) ;
V_23 = F_80 ( V_75 + V_70 ,
V_72 ,
V_71 ) ;
if ( V_110 )
F_49 ( V_75 + V_70 ,
V_71 ) ;
F_51 ( V_75 ) ;
return V_23 ? - V_76 : 0 ;
}
static int
F_88 ( struct V_69 * V_69 , int V_70 , int V_71 ,
char T_5 * V_72 ,
bool V_73 ,
bool V_109 ,
bool V_110 )
{
char * V_75 ;
int V_23 ;
V_75 = F_56 ( V_69 ) ;
if ( F_47 ( V_109 || V_73 ) )
F_52 ( V_75 + V_70 ,
V_71 ,
V_73 ) ;
if ( V_73 )
V_23 = F_44 ( V_75 , V_70 ,
V_72 ,
V_71 ) ;
else
V_23 = F_45 ( V_75 + V_70 ,
V_72 ,
V_71 ) ;
if ( V_110 )
F_52 ( V_75 + V_70 ,
V_71 ,
V_73 ) ;
F_57 ( V_69 ) ;
return V_23 ? - V_76 : 0 ;
}
static int
F_89 ( struct V_1 * V_2 ,
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
V_72 = F_59 ( args -> V_88 ) ;
V_82 = args -> V_17 ;
V_84 = F_60 ( V_7 ) ;
if ( V_7 -> V_8 . V_112 != V_90 ) {
V_110 = F_3 ( V_7 ) ;
if ( F_19 ( V_7 ) ) {
V_23 = F_61 ( V_7 , true ) ;
if ( V_23 )
return V_23 ;
}
}
if ( ( V_7 -> V_8 . V_89 & V_90 ) == 0 )
V_109 =
! F_1 ( V_2 , V_7 -> V_9 ) ;
V_23 = F_62 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_63 ( V_7 ) ;
V_83 = args -> V_83 ;
V_7 -> V_113 = 1 ;
F_64 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_69 * V_69 = F_65 ( & V_87 ) ;
int V_114 ;
if ( V_82 <= 0 )
break;
V_70 = F_66 ( V_83 ) ;
V_71 = V_82 ;
if ( ( V_70 + V_71 ) > V_39 )
V_71 = V_39 - V_70 ;
V_114 = V_109 &&
( ( V_70 | V_71 )
& ( V_115 . V_116 - 1 ) ) ;
V_73 = V_84 &&
( F_67 ( V_69 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_87 ( V_69 , V_70 , V_71 ,
V_72 , V_73 ,
V_114 ,
V_110 ) ;
if ( V_23 == 0 )
goto V_91;
V_111 = 1 ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_88 ( V_69 , V_70 , V_71 ,
V_72 , V_73 ,
V_114 ,
V_110 ) ;
F_23 ( & V_2 -> V_29 ) ;
V_91:
F_90 ( V_69 ) ;
F_70 ( V_69 ) ;
if ( V_23 )
goto V_93;
V_82 -= V_71 ;
V_72 += V_71 ;
V_83 += V_71 ;
}
V_93:
F_71 ( V_7 ) ;
if ( V_111 ) {
if ( ! V_110 &&
V_7 -> V_8 . V_112 != V_90 ) {
if ( F_91 ( V_7 , V_7 -> V_10 ) )
F_92 ( V_2 ) ;
}
}
if ( V_110 )
F_92 ( V_2 ) ;
return V_23 ;
}
int
F_93 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_105 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_73 ( V_117 ,
F_59 ( args -> V_88 ) ,
args -> V_17 ) )
return - V_76 ;
if ( F_68 ( ! V_92 ) ) {
V_23 = F_94 ( F_59 ( args -> V_88 ) ,
args -> V_17 ) ;
if ( V_23 )
return - V_76 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_74 ( F_75 ( V_2 , V_33 , args -> V_53 ) ) ;
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
F_95 ( V_7 , args -> V_83 , args -> V_17 ) ;
V_23 = - V_76 ;
if ( V_7 -> V_118 ) {
V_23 = F_96 ( V_2 , V_7 , args , V_33 ) ;
goto V_93;
}
if ( V_7 -> V_11 == V_119 &&
V_7 -> V_8 . V_112 != V_90 &&
F_3 ( V_7 ) ) {
V_23 = F_82 ( V_2 , V_7 , args , V_33 ) ;
}
if ( V_23 == - V_76 || V_23 == - V_120 )
V_23 = F_89 ( V_2 , V_7 , args , V_33 ) ;
V_93:
F_77 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_97 ( struct V_22 * error ,
bool V_121 )
{
if ( F_98 ( error ) ) {
if ( ! V_121 )
return - V_26 ;
if ( F_99 ( error ) )
return - V_26 ;
return - V_122 ;
}
return 0 ;
}
static int
F_100 ( struct V_123 * V_124 , T_4 V_125 )
{
int V_23 ;
F_101 ( ! F_102 ( & V_124 -> V_2 -> V_29 ) ) ;
V_23 = 0 ;
if ( V_125 == V_124 -> V_126 )
V_23 = F_103 ( V_124 , NULL ) ;
return V_23 ;
}
static int F_104 ( struct V_123 * V_124 , T_4 V_125 ,
unsigned V_127 ,
bool V_121 , struct V_128 * V_129 )
{
T_9 * V_16 = V_124 -> V_2 -> V_27 ;
struct V_128 V_130 , V_131 , V_132 = { 1 , 0 } ;
unsigned long V_133 ;
long V_80 ;
bool V_134 = true ;
int V_23 ;
F_105 ( V_16 -> V_135 . V_136 , L_2 ) ;
if ( F_106 ( V_124 -> V_137 ( V_124 , true ) , V_125 ) )
return 0 ;
F_107 ( V_124 , V_125 ) ;
if ( V_129 != NULL ) {
V_132 = * V_129 ;
V_134 = false ;
}
V_133 = F_108 ( & V_132 ) ;
if ( F_16 ( ! V_124 -> V_138 ( V_124 ) ) )
return - V_36 ;
F_109 ( & V_130 ) ;
#define F_11 \
(i915_seqno_passed(ring->get_seqno(ring, false), seqno) || \
i915_reset_in_progress(&dev_priv->gpu_error) || \
reset_counter != atomic_read(&dev_priv->gpu_error.reset_counter))
do {
if ( V_121 )
V_80 = F_12 ( V_124 -> V_139 ,
F_11 ,
V_133 ) ;
else
V_80 = F_110 ( V_124 -> V_139 , F_11 ,
V_133 ) ;
if ( V_127 != F_111 ( & V_16 -> V_28 . V_127 ) )
V_80 = - V_122 ;
V_23 = F_97 ( & V_16 -> V_28 , V_121 ) ;
if ( V_23 )
V_80 = V_23 ;
} while ( V_80 == 0 && V_134 );
F_109 ( & V_131 ) ;
V_124 -> V_140 ( V_124 ) ;
F_112 ( V_124 , V_125 ) ;
#undef F_11
if ( V_129 ) {
struct V_128 V_141 = F_113 ( V_131 , V_130 ) ;
* V_129 = F_113 ( * V_129 , V_141 ) ;
if ( ! F_114 ( V_129 ) )
F_115 ( V_129 , 0 , 0 ) ;
}
switch ( V_80 ) {
case - V_26 :
case - V_122 :
case - V_142 :
return ( int ) V_80 ;
case 0 :
return - V_143 ;
default:
F_16 ( V_80 < 0 ) ;
return 0 ;
}
}
int
F_116 ( struct V_123 * V_124 , T_3 V_125 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_121 = V_16 -> V_18 . V_121 ;
int V_23 ;
F_101 ( ! F_102 ( & V_2 -> V_29 ) ) ;
F_101 ( V_125 == 0 ) ;
V_23 = F_97 ( & V_16 -> V_28 , V_121 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_100 ( V_124 , V_125 ) ;
if ( V_23 )
return V_23 ;
return F_104 ( V_124 , V_125 ,
F_111 ( & V_16 -> V_28 . V_127 ) ,
V_121 , NULL ) ;
}
static int
F_117 ( struct V_6 * V_7 ,
struct V_123 * V_124 )
{
F_118 ( V_124 ) ;
V_7 -> V_144 = 0 ;
V_7 -> V_8 . V_112 &= ~ V_145 ;
return 0 ;
}
static T_10 int
F_119 ( struct V_6 * V_7 ,
bool V_146 )
{
struct V_123 * V_124 = V_7 -> V_124 ;
T_4 V_125 ;
int V_23 ;
V_125 = V_146 ? V_7 -> V_144 : V_7 -> V_147 ;
if ( V_125 == 0 )
return 0 ;
V_23 = F_116 ( V_124 , V_125 ) ;
if ( V_23 )
return V_23 ;
return F_117 ( V_7 , V_124 ) ;
}
static T_10 int
F_120 ( struct V_6 * V_7 ,
bool V_146 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 = V_7 -> V_124 ;
unsigned V_127 ;
T_4 V_125 ;
int V_23 ;
F_101 ( ! F_102 ( & V_2 -> V_29 ) ) ;
F_101 ( ! V_16 -> V_18 . V_121 ) ;
V_125 = V_146 ? V_7 -> V_144 : V_7 -> V_147 ;
if ( V_125 == 0 )
return 0 ;
V_23 = F_97 ( & V_16 -> V_28 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = F_100 ( V_124 , V_125 ) ;
if ( V_23 )
return V_23 ;
V_127 = F_111 ( & V_16 -> V_28 . V_127 ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_104 ( V_124 , V_125 , V_127 , true , NULL ) ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_23 )
return V_23 ;
return F_117 ( V_7 , V_124 ) ;
}
int
F_121 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_148 * args = V_31 ;
struct V_6 * V_7 ;
T_3 V_89 = args -> V_89 ;
T_3 V_112 = args -> V_112 ;
int V_23 ;
if ( V_112 & V_145 )
return - V_40 ;
if ( V_89 & V_145 )
return - V_40 ;
if ( V_112 != 0 && V_89 != V_112 )
return - V_40 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_74 ( F_75 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
V_23 = F_120 ( V_7 , ! V_112 ) ;
if ( V_23 )
goto V_149;
if ( V_89 & V_150 ) {
V_23 = F_61 ( V_7 , V_112 != 0 ) ;
if ( V_23 == - V_40 )
V_23 = 0 ;
} else {
V_23 = F_122 ( V_7 , V_112 != 0 ) ;
}
V_149:
F_77 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_123 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_151 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_74 ( F_75 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( V_7 -> V_10 )
F_124 ( V_7 , true ) ;
F_77 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_125 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_152 * args = V_31 ;
struct V_153 * V_7 ;
unsigned long V_77 ;
V_7 = F_75 ( V_2 , V_33 , args -> V_53 ) ;
if ( V_7 == NULL )
return - V_95 ;
if ( ! V_7 -> V_97 ) {
F_37 ( V_7 ) ;
return - V_40 ;
}
V_77 = F_126 ( V_7 -> V_97 , 0 , args -> V_17 ,
V_154 | V_155 , V_156 ,
args -> V_83 ) ;
F_37 ( V_7 ) ;
if ( F_127 ( ( void * ) V_77 ) )
return V_77 ;
args -> V_157 = ( T_2 ) V_77 ;
return 0 ;
}
int F_128 ( struct V_158 * V_159 , struct V_160 * V_161 )
{
struct V_6 * V_7 = F_74 ( V_159 -> V_162 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
T_9 * V_16 = V_2 -> V_27 ;
T_11 V_101 ;
unsigned long V_163 ;
int V_23 = 0 ;
bool V_164 = ! ! ( V_161 -> V_165 & V_166 ) ;
V_101 = ( ( unsigned long ) V_161 -> V_167 - V_159 -> V_168 ) >>
V_169 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
goto V_93;
F_129 ( V_7 , V_101 , true , V_164 ) ;
if ( V_7 -> V_9 != V_5 && ! F_2 ( V_2 ) ) {
V_23 = - V_40 ;
goto V_96;
}
V_23 = F_83 ( V_7 , 0 , true , false ) ;
if ( V_23 )
goto V_96;
V_23 = F_61 ( V_7 , V_164 ) ;
if ( V_23 )
goto V_170;
V_23 = F_130 ( V_7 ) ;
if ( V_23 )
goto V_170;
V_7 -> V_171 = true ;
V_163 = V_16 -> V_42 . V_172 + F_85 ( V_7 ) ;
V_163 >>= V_169 ;
V_163 += V_101 ;
V_23 = F_131 ( V_159 , ( unsigned long ) V_161 -> V_167 , V_163 ) ;
V_170:
F_86 ( V_7 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
V_93:
switch ( V_23 ) {
case - V_26 :
if ( F_99 ( & V_16 -> V_28 ) )
return V_173 ;
case - V_122 :
case 0 :
case - V_142 :
case - V_174 :
case - V_175 :
return V_176 ;
case - V_54 :
return V_177 ;
case - V_120 :
return V_173 ;
default:
F_132 ( V_23 , L_3 , V_23 ) ;
return V_173 ;
}
}
void
F_5 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_171 )
return;
F_133 ( & V_7 -> V_8 . V_178 , V_7 -> V_8 . V_2 -> V_179 ) ;
V_7 -> V_171 = false ;
}
T_3
F_134 ( struct V_1 * V_2 , T_3 V_17 , int V_11 )
{
T_3 V_180 ;
if ( F_22 ( V_2 ) -> V_41 >= 4 ||
V_11 == V_119 )
return V_17 ;
if ( F_22 ( V_2 ) -> V_41 == 3 )
V_180 = 1024 * 1024 ;
else
V_180 = 512 * 1024 ;
while ( V_180 < V_17 )
V_180 <<= 1 ;
return V_180 ;
}
T_3
F_135 ( struct V_1 * V_2 , T_3 V_17 ,
int V_11 , bool V_181 )
{
if ( F_22 ( V_2 ) -> V_41 >= 4 || ( ! V_181 && F_136 ( V_2 ) ) ||
V_11 == V_119 )
return 4096 ;
return F_134 ( V_2 , V_17 , V_11 ) ;
}
static int F_137 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_138 ( & V_7 -> V_8 . V_178 ) )
return 0 ;
V_16 -> V_18 . V_182 = true ;
V_23 = F_139 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_120 )
goto V_93;
F_140 ( V_16 , V_7 -> V_8 . V_17 >> V_169 ) ;
V_23 = F_139 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_120 )
goto V_93;
F_141 ( V_16 ) ;
V_23 = F_139 ( & V_7 -> V_8 ) ;
V_93:
V_16 -> V_18 . V_182 = false ;
return V_23 ;
}
static void F_142 ( struct V_6 * V_7 )
{
F_143 ( & V_7 -> V_8 ) ;
}
int
F_144 ( struct V_32 * V_33 ,
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
V_7 = F_74 ( F_75 ( V_2 , V_33 , V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( V_7 -> V_8 . V_17 > V_16 -> V_42 . V_43 ) {
V_23 = - V_183 ;
goto V_93;
}
if ( V_7 -> V_184 != V_185 ) {
F_13 ( L_4 ) ;
V_23 = - V_40 ;
goto V_93;
}
V_23 = F_137 ( V_7 ) ;
if ( V_23 )
goto V_93;
* V_83 = F_145 ( & V_7 -> V_8 . V_178 ) ;
V_93:
F_77 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_146 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_186 * args = V_31 ;
return F_144 ( V_33 , V_2 , args -> V_53 , & args -> V_83 ) ;
}
static void
F_147 ( struct V_6 * V_7 )
{
struct V_187 * V_187 ;
F_142 ( V_7 ) ;
if ( V_7 -> V_8 . V_97 == NULL )
return;
V_187 = F_148 ( V_7 -> V_8 . V_97 ) ;
F_149 ( V_187 , 0 , ( T_7 ) - 1 ) ;
V_7 -> V_184 = V_188 ;
}
static inline int
F_150 ( struct V_6 * V_7 )
{
return V_7 -> V_184 == V_189 ;
}
static void
F_151 ( struct V_6 * V_7 )
{
struct V_86 V_87 ;
int V_23 ;
F_101 ( V_7 -> V_184 == V_188 ) ;
V_23 = F_122 ( V_7 , true ) ;
if ( V_23 ) {
F_16 ( V_23 != - V_26 ) ;
F_91 ( V_7 , true ) ;
V_7 -> V_8 . V_89 = V_7 -> V_8 . V_112 = V_90 ;
}
if ( F_60 ( V_7 ) )
F_152 ( V_7 ) ;
if ( V_7 -> V_184 == V_189 )
V_7 -> V_113 = 0 ;
F_64 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_69 * V_69 = F_65 ( & V_87 ) ;
if ( V_7 -> V_113 )
F_90 ( V_69 ) ;
if ( V_7 -> V_184 == V_185 )
F_70 ( V_69 ) ;
F_153 ( V_69 ) ;
}
V_7 -> V_113 = 0 ;
F_154 ( V_7 -> V_190 ) ;
F_155 ( V_7 -> V_190 ) ;
}
int
F_156 ( struct V_6 * V_7 )
{
const struct V_191 * V_192 = V_7 -> V_192 ;
if ( V_7 -> V_190 == NULL )
return 0 ;
if ( V_7 -> V_193 )
return - V_175 ;
F_101 ( F_19 ( V_7 ) ) ;
F_157 ( & V_7 -> V_194 ) ;
V_192 -> V_195 ( V_7 ) ;
V_7 -> V_190 = NULL ;
if ( F_150 ( V_7 ) )
F_147 ( V_7 ) ;
return 0 ;
}
static long
F_158 ( struct V_15 * V_16 , long V_196 ,
bool V_197 )
{
struct V_198 V_199 ;
struct V_6 * V_7 , * V_200 ;
long V_201 = 0 ;
F_159 (obj, next,
&dev_priv->mm.unbound_list,
global_list) {
if ( ( F_150 ( V_7 ) || ! V_197 ) &&
F_156 ( V_7 ) == 0 ) {
V_201 += V_7 -> V_8 . V_17 >> V_169 ;
if ( V_201 >= V_196 )
return V_201 ;
}
}
F_160 ( & V_199 ) ;
while ( V_201 < V_196 && ! F_161 ( & V_16 -> V_18 . V_202 ) ) {
struct V_203 * V_159 , * V_204 ;
V_7 = F_162 ( & V_16 -> V_18 . V_202 ,
F_163 ( * V_7 ) , V_194 ) ;
F_164 ( & V_7 -> V_194 , & V_199 ) ;
if ( ! F_150 ( V_7 ) && V_197 )
continue;
F_165 ( & V_7 -> V_8 ) ;
F_159 (vma, v, &obj->vma_list, vma_link)
if ( F_166 ( V_159 ) )
break;
if ( F_156 ( V_7 ) == 0 )
V_201 += V_7 -> V_8 . V_17 >> V_169 ;
F_77 ( & V_7 -> V_8 ) ;
}
F_167 ( & V_199 , & V_16 -> V_18 . V_202 ) ;
return V_201 ;
}
static long
F_140 ( struct V_15 * V_16 , long V_196 )
{
return F_158 ( V_16 , V_196 , true ) ;
}
static long
F_141 ( struct V_15 * V_16 )
{
struct V_6 * V_7 , * V_200 ;
long V_205 = 0 ;
F_168 ( V_16 -> V_2 ) ;
F_159 (obj, next, &dev_priv->mm.unbound_list,
global_list) {
if ( V_7 -> V_193 == 0 )
V_205 += V_7 -> V_8 . V_17 >> V_169 ;
F_156 ( V_7 ) ;
}
return V_205 ;
}
static int
F_169 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_206 , V_207 ;
struct V_208 * V_99 ;
struct V_209 * V_210 ;
struct V_211 * V_212 ;
struct V_86 V_87 ;
struct V_69 * V_69 ;
unsigned long V_213 = 0 ;
T_12 V_214 ;
F_101 ( V_7 -> V_8 . V_89 & V_145 ) ;
F_101 ( V_7 -> V_8 . V_112 & V_145 ) ;
V_210 = F_170 ( sizeof( * V_210 ) , V_51 ) ;
if ( V_210 == NULL )
return - V_54 ;
V_206 = V_7 -> V_8 . V_17 / V_39 ;
if ( F_171 ( V_210 , V_206 , V_51 ) ) {
F_155 ( V_210 ) ;
return - V_54 ;
}
V_99 = F_148 ( V_7 -> V_8 . V_97 ) -> V_215 ;
V_214 = F_172 ( V_99 ) ;
V_214 |= V_216 | V_217 | V_218 ;
V_214 &= ~ ( V_219 | V_220 ) ;
V_212 = V_210 -> V_221 ;
V_210 -> V_222 = 0 ;
for ( V_207 = 0 ; V_207 < V_206 ; V_207 ++ ) {
V_69 = F_173 ( V_99 , V_207 , V_214 ) ;
if ( F_127 ( V_69 ) ) {
F_140 ( V_16 , V_206 ) ;
V_69 = F_173 ( V_99 , V_207 , V_214 ) ;
}
if ( F_127 ( V_69 ) ) {
V_214 &= ~ ( V_216 | V_217 | V_218 ) ;
V_214 |= V_219 | V_220 ;
F_141 ( V_16 ) ;
V_69 = F_173 ( V_99 , V_207 , V_214 ) ;
if ( F_127 ( V_69 ) )
goto V_223;
V_214 |= V_216 | V_217 | V_218 ;
V_214 &= ~ ( V_219 | V_220 ) ;
}
#ifdef F_174
if ( F_175 () ) {
V_210 -> V_222 ++ ;
F_176 ( V_212 , V_69 , V_39 , 0 ) ;
V_212 = F_177 ( V_212 ) ;
continue;
}
#endif
if ( ! V_207 || F_178 ( V_69 ) != V_213 + 1 ) {
if ( V_207 )
V_212 = F_177 ( V_212 ) ;
V_210 -> V_222 ++ ;
F_176 ( V_212 , V_69 , V_39 , 0 ) ;
} else {
V_212 -> V_64 += V_39 ;
}
V_213 = F_178 ( V_69 ) ;
}
#ifdef F_174
if ( ! F_175 () )
#endif
F_179 ( V_212 ) ;
V_7 -> V_190 = V_210 ;
if ( F_60 ( V_7 ) )
F_180 ( V_7 ) ;
return 0 ;
V_223:
F_179 ( V_212 ) ;
F_64 (st->sgl, &sg_iter, st->nents, 0 )
F_153 ( F_65 ( & V_87 ) ) ;
F_154 ( V_210 ) ;
F_155 ( V_210 ) ;
return F_181 ( V_69 ) ;
}
int
F_62 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
const struct V_191 * V_192 = V_7 -> V_192 ;
int V_23 ;
if ( V_7 -> V_190 )
return 0 ;
if ( V_7 -> V_184 != V_185 ) {
F_13 ( L_5 ) ;
return - V_40 ;
}
F_101 ( V_7 -> V_193 ) ;
V_23 = V_192 -> V_224 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_182 ( & V_7 -> V_194 , & V_16 -> V_18 . V_225 ) ;
return 0 ;
}
void
F_183 ( struct V_6 * V_7 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_4 V_125 = F_184 ( V_124 ) ;
F_101 ( V_124 == NULL ) ;
if ( V_7 -> V_124 != V_124 && V_7 -> V_144 ) {
V_7 -> V_144 = V_125 ;
}
V_7 -> V_124 = V_124 ;
if ( ! V_7 -> V_30 ) {
F_165 ( & V_7 -> V_8 ) ;
V_7 -> V_30 = 1 ;
}
F_164 ( & V_7 -> V_226 , & V_124 -> V_227 ) ;
V_7 -> V_147 = V_125 ;
if ( V_7 -> V_228 ) {
V_7 -> V_229 = V_125 ;
if ( V_7 -> V_13 != V_14 ) {
struct V_230 * V_231 ;
V_231 = & V_16 -> V_232 [ V_7 -> V_13 ] ;
F_164 ( & V_231 -> V_233 ,
& V_16 -> V_18 . V_234 ) ;
}
}
}
static void
F_185 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_235 * V_236 = & V_16 -> V_42 . V_8 ;
struct V_203 * V_159 = F_186 ( V_7 , V_236 ) ;
F_101 ( V_7 -> V_8 . V_112 & ~ V_145 ) ;
F_101 ( ! V_7 -> V_30 ) ;
F_164 ( & V_159 -> V_237 , & V_236 -> V_238 ) ;
F_187 ( & V_7 -> V_226 ) ;
V_7 -> V_124 = NULL ;
V_7 -> V_147 = 0 ;
V_7 -> V_144 = 0 ;
V_7 -> V_8 . V_112 = 0 ;
V_7 -> V_229 = 0 ;
V_7 -> V_228 = false ;
V_7 -> V_30 = 0 ;
F_77 ( & V_7 -> V_8 ) ;
F_16 ( F_17 ( V_2 ) ) ;
}
static int
F_188 ( struct V_1 * V_2 , T_4 V_125 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 ;
int V_23 , V_207 , V_239 ;
F_189 (ring, dev_priv, i) {
V_23 = F_190 ( V_124 ) ;
if ( V_23 )
return V_23 ;
}
F_191 ( V_2 ) ;
F_189 (ring, dev_priv, i) {
F_192 ( V_124 , V_125 ) ;
for ( V_239 = 0 ; V_239 < F_193 ( V_124 -> V_240 ) ; V_239 ++ )
V_124 -> V_240 [ V_239 ] = 0 ;
}
return 0 ;
}
int F_194 ( struct V_1 * V_2 , T_4 V_125 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( V_125 == 0 )
return - V_40 ;
V_23 = F_188 ( V_2 , V_125 - 1 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_241 = V_125 ;
V_16 -> V_242 = V_125 - 1 ;
if ( V_16 -> V_242 == 0 )
V_16 -> V_242 -- ;
return 0 ;
}
int
F_195 ( struct V_1 * V_2 , T_4 * V_125 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( V_16 -> V_241 == 0 ) {
int V_23 = F_188 ( V_2 , 0 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_241 = 1 ;
}
* V_125 = V_16 -> V_242 = V_16 -> V_241 ++ ;
return 0 ;
}
int F_196 ( struct V_123 * V_124 ,
struct V_32 * V_33 ,
struct V_6 * V_7 ,
T_4 * V_243 )
{
T_9 * V_16 = V_124 -> V_2 -> V_27 ;
struct V_244 * V_245 ;
T_4 V_246 , V_247 ;
int V_248 ;
int V_23 ;
V_247 = F_197 ( V_124 ) ;
V_23 = F_198 ( V_124 ) ;
if ( V_23 )
return V_23 ;
V_245 = F_170 ( sizeof( * V_245 ) , V_51 ) ;
if ( V_245 == NULL )
return - V_54 ;
V_246 = F_197 ( V_124 ) ;
V_23 = V_124 -> V_249 ( V_124 ) ;
if ( V_23 ) {
F_155 ( V_245 ) ;
return V_23 ;
}
V_245 -> V_125 = F_184 ( V_124 ) ;
V_245 -> V_124 = V_124 ;
V_245 -> V_250 = V_247 ;
V_245 -> V_251 = V_246 ;
V_245 -> V_252 = V_124 -> V_253 ;
V_245 -> V_254 = V_7 ;
if ( V_245 -> V_252 )
F_199 ( V_245 -> V_252 ) ;
V_245 -> V_255 = V_256 ;
V_248 = F_161 ( & V_124 -> V_257 ) ;
F_182 ( & V_245 -> V_258 , & V_124 -> V_257 ) ;
V_245 -> V_259 = NULL ;
if ( V_33 ) {
struct V_260 * V_259 = V_33 -> V_261 ;
F_7 ( & V_259 -> V_18 . V_262 ) ;
V_245 -> V_259 = V_259 ;
F_182 ( & V_245 -> V_263 ,
& V_259 -> V_18 . V_257 ) ;
F_8 ( & V_259 -> V_18 . V_262 ) ;
}
F_200 ( V_124 , V_245 -> V_125 ) ;
V_124 -> V_126 = 0 ;
if ( ! V_16 -> V_264 . V_265 ) {
F_201 ( V_124 -> V_2 ) ;
if ( V_248 ) {
F_202 ( V_16 -> V_266 ,
& V_16 -> V_18 . V_267 ,
F_203 ( V_25 ) ) ;
F_204 ( V_16 -> V_2 ) ;
}
}
if ( V_243 )
* V_243 = V_245 -> V_125 ;
return 0 ;
}
static inline void
F_205 ( struct V_244 * V_245 )
{
struct V_260 * V_259 = V_245 -> V_259 ;
if ( ! V_259 )
return;
F_7 ( & V_259 -> V_18 . V_262 ) ;
if ( V_245 -> V_259 ) {
F_157 ( & V_245 -> V_263 ) ;
V_245 -> V_259 = NULL ;
}
F_8 ( & V_259 -> V_18 . V_262 ) ;
}
static bool F_206 ( T_4 V_268 , struct V_6 * V_7 ,
struct V_235 * V_269 )
{
if ( V_268 >= F_207 ( V_7 , V_269 ) &&
V_268 < F_207 ( V_7 , V_269 ) + V_7 -> V_8 . V_17 )
return true ;
return false ;
}
static bool F_208 ( const T_4 V_270 ,
const T_4 V_247 ,
const T_4 V_271 )
{
const T_4 V_268 = V_270 & V_272 ;
if ( V_247 < V_271 ) {
if ( V_268 >= V_247 && V_268 < V_271 )
return true ;
} else if ( V_247 > V_271 ) {
if ( V_268 >= V_247 || V_268 < V_271 )
return true ;
}
return false ;
}
static struct V_235 *
F_209 ( struct V_244 * V_245 )
{
struct V_15 * V_16 = V_245 -> V_124 -> V_2 -> V_27 ;
struct V_235 * V_269 ;
V_269 = & V_16 -> V_42 . V_8 ;
return V_269 ;
}
static bool F_210 ( struct V_244 * V_245 ,
const T_4 V_268 , bool * V_273 )
{
if ( V_245 -> V_254 ) {
if ( F_206 ( V_268 , V_245 -> V_254 ,
F_209 ( V_245 ) ) ) {
* V_273 = true ;
return true ;
}
}
if ( F_208 ( V_268 , V_245 -> V_250 , V_245 -> V_251 ) ) {
* V_273 = false ;
return true ;
}
return false ;
}
static void F_211 ( struct V_123 * V_124 ,
struct V_244 * V_245 ,
T_4 V_268 )
{
struct V_274 * V_275 = NULL ;
bool V_273 , V_276 ;
unsigned long V_83 = 0 ;
V_276 = false ;
if ( V_245 -> V_254 )
V_83 = F_207 ( V_245 -> V_254 ,
F_209 ( V_245 ) ) ;
if ( V_124 -> V_277 . V_278 != V_279 &&
F_210 ( V_245 , V_268 , & V_273 ) ) {
F_13 ( L_6 ,
V_124 -> V_280 ,
V_273 ? L_7 : L_8 ,
V_83 ,
V_245 -> V_252 ? V_245 -> V_252 -> V_281 : 0 ,
V_268 ) ;
V_276 = true ;
}
if ( V_245 -> V_252 && V_245 -> V_252 -> V_281 != V_282 )
V_275 = & V_245 -> V_252 -> V_283 ;
else if ( V_245 -> V_259 )
V_275 = & V_245 -> V_259 -> V_283 ;
if ( V_275 ) {
if ( V_276 )
V_275 -> V_284 ++ ;
else
V_275 -> V_285 ++ ;
}
}
static void F_212 ( struct V_244 * V_245 )
{
F_157 ( & V_245 -> V_258 ) ;
F_205 ( V_245 ) ;
if ( V_245 -> V_252 )
F_213 ( V_245 -> V_252 ) ;
F_155 ( V_245 ) ;
}
static void F_214 ( struct V_15 * V_16 ,
struct V_123 * V_124 )
{
T_4 V_286 ;
T_4 V_268 ;
V_268 = F_215 ( V_124 ) ;
V_286 = V_124 -> V_137 ( V_124 , false ) ;
while ( ! F_161 ( & V_124 -> V_257 ) ) {
struct V_244 * V_245 ;
V_245 = F_162 ( & V_124 -> V_257 ,
struct V_244 ,
V_258 ) ;
if ( V_245 -> V_125 > V_286 )
F_211 ( V_124 , V_245 , V_268 ) ;
F_212 ( V_245 ) ;
}
while ( ! F_161 ( & V_124 -> V_227 ) ) {
struct V_6 * V_7 ;
V_7 = F_162 ( & V_124 -> V_227 ,
struct V_6 ,
V_226 ) ;
F_185 ( V_7 ) ;
}
}
void F_216 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_207 ;
for ( V_207 = 0 ; V_207 < V_16 -> V_287 ; V_207 ++ ) {
struct V_230 * V_231 = & V_16 -> V_232 [ V_207 ] ;
if ( V_231 -> V_7 ) {
F_217 ( V_231 -> V_7 , V_231 ,
V_231 -> V_7 -> V_11 ) ;
} else {
F_218 ( V_2 , V_207 , NULL ) ;
}
}
}
void F_219 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 ;
int V_207 ;
F_189 (ring, dev_priv, i)
F_214 ( V_16 , V_124 ) ;
F_216 ( V_2 ) ;
}
void
F_118 ( struct V_123 * V_124 )
{
T_3 V_125 ;
if ( F_161 ( & V_124 -> V_257 ) )
return;
F_16 ( F_17 ( V_124 -> V_2 ) ) ;
V_125 = V_124 -> V_137 ( V_124 , true ) ;
while ( ! F_161 ( & V_124 -> V_257 ) ) {
struct V_244 * V_245 ;
V_245 = F_162 ( & V_124 -> V_257 ,
struct V_244 ,
V_258 ) ;
if ( ! F_106 ( V_125 , V_245 -> V_125 ) )
break;
F_220 ( V_124 , V_245 -> V_125 ) ;
V_124 -> V_288 = V_245 -> V_251 ;
F_212 ( V_245 ) ;
}
while ( ! F_161 ( & V_124 -> V_227 ) ) {
struct V_6 * V_7 ;
V_7 = F_162 ( & V_124 -> V_227 ,
struct V_6 ,
V_226 ) ;
if ( ! F_106 ( V_125 , V_7 -> V_147 ) )
break;
F_185 ( V_7 ) ;
}
if ( F_47 ( V_124 -> V_289 &&
F_106 ( V_125 , V_124 -> V_289 ) ) ) {
V_124 -> V_140 ( V_124 ) ;
V_124 -> V_289 = 0 ;
}
F_16 ( F_17 ( V_124 -> V_2 ) ) ;
}
void
F_191 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 ;
int V_207 ;
F_189 (ring, dev_priv, i)
F_118 ( V_124 ) ;
}
static void
F_221 ( struct V_290 * V_291 )
{
T_9 * V_16 ;
struct V_1 * V_2 ;
struct V_123 * V_124 ;
bool V_292 ;
int V_207 ;
V_16 = F_222 ( V_291 , T_9 ,
V_18 . V_267 . V_291 ) ;
V_2 = V_16 -> V_2 ;
if ( ! F_223 ( & V_2 -> V_29 ) ) {
F_202 ( V_16 -> V_266 , & V_16 -> V_18 . V_267 ,
F_203 ( V_25 ) ) ;
return;
}
F_191 ( V_2 ) ;
V_292 = true ;
F_189 (ring, dev_priv, i) {
if ( V_124 -> V_293 )
F_103 ( V_124 , NULL ) ;
V_292 &= F_161 ( & V_124 -> V_257 ) ;
}
if ( ! V_16 -> V_264 . V_265 && ! V_292 )
F_202 ( V_16 -> V_266 , & V_16 -> V_18 . V_267 ,
F_203 ( V_25 ) ) ;
if ( V_292 )
F_224 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
}
static int
F_225 ( struct V_6 * V_7 )
{
int V_23 ;
if ( V_7 -> V_30 ) {
V_23 = F_100 ( V_7 -> V_124 , V_7 -> V_147 ) ;
if ( V_23 )
return V_23 ;
F_118 ( V_7 -> V_124 ) ;
}
return 0 ;
}
int
F_226 ( struct V_1 * V_2 , void * V_31 , struct V_32 * V_33 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_294 * args = V_31 ;
struct V_6 * V_7 ;
struct V_123 * V_124 = NULL ;
struct V_128 V_295 , * V_129 = NULL ;
unsigned V_127 ;
T_4 V_125 = 0 ;
int V_23 = 0 ;
if ( args -> V_296 >= 0 ) {
V_295 = F_227 ( args -> V_296 ) ;
V_129 = & V_295 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_74 ( F_75 ( V_2 , V_33 , args -> V_297 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_25 ( & V_2 -> V_29 ) ;
return - V_95 ;
}
V_23 = F_225 ( V_7 ) ;
if ( V_23 )
goto V_93;
if ( V_7 -> V_30 ) {
V_125 = V_7 -> V_147 ;
V_124 = V_7 -> V_124 ;
}
if ( V_125 == 0 )
goto V_93;
if ( ! args -> V_296 ) {
V_23 = - V_143 ;
goto V_93;
}
F_77 ( & V_7 -> V_8 ) ;
V_127 = F_111 ( & V_16 -> V_28 . V_127 ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_104 ( V_124 , V_125 , V_127 , true , V_129 ) ;
if ( V_129 )
args -> V_296 = F_228 ( V_129 ) ;
return V_23 ;
V_93:
F_77 ( & V_7 -> V_8 ) ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_229 ( struct V_6 * V_7 ,
struct V_123 * V_298 )
{
struct V_123 * V_299 = V_7 -> V_124 ;
T_4 V_125 ;
int V_23 , V_300 ;
if ( V_299 == NULL || V_298 == V_299 )
return 0 ;
if ( V_298 == NULL || ! F_230 ( V_7 -> V_8 . V_2 ) )
return F_119 ( V_7 , false ) ;
V_300 = F_231 ( V_299 , V_298 ) ;
V_125 = V_7 -> V_147 ;
if ( V_125 <= V_299 -> V_240 [ V_300 ] )
return 0 ;
V_23 = F_100 ( V_7 -> V_124 , V_125 ) ;
if ( V_23 )
return V_23 ;
V_23 = V_298 -> V_301 ( V_298 , V_299 , V_125 ) ;
if ( ! V_23 )
V_299 -> V_240 [ V_300 ] = V_7 -> V_147 ;
return V_23 ;
}
static void F_232 ( struct V_6 * V_7 )
{
T_4 V_302 , V_303 ;
F_5 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_89 & V_150 ) == 0 )
return;
F_233 () ;
V_303 = V_7 -> V_8 . V_89 ;
V_302 = V_7 -> V_8 . V_112 ;
V_7 -> V_8 . V_89 &= ~ V_150 ;
V_7 -> V_8 . V_112 &= ~ V_150 ;
F_234 ( V_7 ,
V_303 ,
V_302 ) ;
}
int F_166 ( struct V_203 * V_159 )
{
struct V_6 * V_7 = V_159 -> V_7 ;
T_9 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_161 ( & V_159 -> V_304 ) )
return 0 ;
if ( ! F_235 ( & V_159 -> V_305 ) )
goto V_306;
if ( V_7 -> V_46 )
return - V_175 ;
F_101 ( V_7 -> V_190 == NULL ) ;
V_23 = F_236 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_232 ( V_7 ) ;
V_23 = F_84 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_237 ( V_159 ) ;
if ( V_7 -> V_307 )
F_238 ( V_7 ) ;
if ( V_7 -> V_308 ) {
F_239 ( V_16 -> V_18 . V_309 , V_7 ) ;
V_7 -> V_308 = 0 ;
}
F_240 ( V_7 ) ;
F_71 ( V_7 ) ;
F_157 ( & V_159 -> V_237 ) ;
if ( F_241 ( V_159 -> V_269 ) )
V_7 -> V_310 = true ;
F_242 ( & V_159 -> V_305 ) ;
V_306:
F_243 ( V_159 ) ;
F_16 ( ! F_161 ( & V_7 -> V_311 ) ) ;
if ( F_161 ( & V_7 -> V_311 ) )
F_164 ( & V_7 -> V_194 , & V_16 -> V_18 . V_225 ) ;
return 0 ;
}
int
F_244 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_235 * V_312 = & V_16 -> V_42 . V_8 ;
if ( ! F_245 ( V_7 ) )
return 0 ;
if ( V_7 -> V_46 )
return - V_175 ;
F_101 ( V_7 -> V_190 == NULL ) ;
return F_166 ( F_186 ( V_7 , V_312 ) ) ;
}
int F_246 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 ;
int V_23 , V_207 ;
F_189 (ring, dev_priv, i) {
V_23 = F_247 ( V_124 , NULL , V_282 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_190 ( V_124 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static void F_248 ( struct V_1 * V_2 , int V_231 ,
struct V_6 * V_7 )
{
T_9 * V_16 = V_2 -> V_27 ;
int V_13 ;
int V_313 ;
if ( F_22 ( V_2 ) -> V_41 >= 6 ) {
V_13 = V_314 ;
V_313 = V_315 ;
} else {
V_13 = V_316 ;
V_313 = V_317 ;
}
V_13 += V_231 * 8 ;
F_249 ( V_13 , 0 ) ;
F_250 ( V_13 ) ;
if ( V_7 ) {
T_4 V_17 = F_28 ( V_7 ) ;
T_2 V_318 ;
V_318 = ( T_2 ) ( ( F_85 ( V_7 ) + V_17 - 4096 ) &
0xfffff000 ) << 32 ;
V_318 |= F_85 ( V_7 ) & 0xfffff000 ;
V_318 |= ( T_2 ) ( ( V_7 -> V_319 / 128 ) - 1 ) << V_313 ;
if ( V_7 -> V_11 == V_320 )
V_318 |= 1 << V_321 ;
V_318 |= V_322 ;
F_249 ( V_13 + 4 , V_318 >> 32 ) ;
F_250 ( V_13 + 4 ) ;
F_249 ( V_13 + 0 , V_318 ) ;
F_250 ( V_13 ) ;
} else {
F_249 ( V_13 + 4 , 0 ) ;
F_250 ( V_13 + 4 ) ;
}
}
static void F_251 ( struct V_1 * V_2 , int V_231 ,
struct V_6 * V_7 )
{
T_9 * V_16 = V_2 -> V_27 ;
T_4 V_318 ;
if ( V_7 ) {
T_4 V_17 = F_28 ( V_7 ) ;
int V_323 ;
int V_324 ;
F_105 ( ( F_85 ( V_7 ) & ~ V_325 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_85 ( V_7 ) & ( V_17 - 1 ) ) ,
L_9 ,
F_85 ( V_7 ) , V_7 -> V_310 , V_17 ) ;
if ( V_7 -> V_11 == V_320 && F_252 ( V_2 ) )
V_324 = 128 ;
else
V_324 = 512 ;
V_323 = V_7 -> V_319 / V_324 ;
V_323 = F_253 ( V_323 ) - 1 ;
V_318 = F_85 ( V_7 ) ;
if ( V_7 -> V_11 == V_320 )
V_318 |= 1 << V_326 ;
V_318 |= F_254 ( V_17 ) ;
V_318 |= V_323 << V_327 ;
V_318 |= V_328 ;
} else
V_318 = 0 ;
if ( V_231 < 8 )
V_231 = V_329 + V_231 * 4 ;
else
V_231 = V_330 + ( V_231 - 8 ) * 4 ;
F_249 ( V_231 , V_318 ) ;
F_250 ( V_231 ) ;
}
static void F_255 ( struct V_1 * V_2 , int V_231 ,
struct V_6 * V_7 )
{
T_9 * V_16 = V_2 -> V_27 ;
T_3 V_318 ;
if ( V_7 ) {
T_4 V_17 = F_28 ( V_7 ) ;
T_3 V_323 ;
F_105 ( ( F_85 ( V_7 ) & ~ V_331 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_85 ( V_7 ) & ( V_17 - 1 ) ) ,
L_10 ,
F_85 ( V_7 ) , V_17 ) ;
V_323 = V_7 -> V_319 / 128 ;
V_323 = F_253 ( V_323 ) - 1 ;
V_318 = F_85 ( V_7 ) ;
if ( V_7 -> V_11 == V_320 )
V_318 |= 1 << V_326 ;
V_318 |= F_256 ( V_17 ) ;
V_318 |= V_323 << V_327 ;
V_318 |= V_328 ;
} else
V_318 = 0 ;
F_249 ( V_329 + V_231 * 4 , V_318 ) ;
F_250 ( V_329 + V_231 * 4 ) ;
}
inline static bool F_257 ( struct V_6 * V_7 )
{
return V_7 && V_7 -> V_8 . V_89 & V_150 ;
}
static void F_218 ( struct V_1 * V_2 , int V_231 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_257 ( V_16 -> V_232 [ V_231 ] . V_7 ) )
F_233 () ;
F_105 ( V_7 && ( ! V_7 -> V_319 || ! V_7 -> V_11 ) ,
L_11 ,
V_7 -> V_319 , V_7 -> V_11 ) ;
switch ( F_22 ( V_2 ) -> V_41 ) {
case 7 :
case 6 :
case 5 :
case 4 : F_248 ( V_2 , V_231 , V_7 ) ; break;
case 3 : F_251 ( V_2 , V_231 , V_7 ) ; break;
case 2 : F_255 ( V_2 , V_231 , V_7 ) ; break;
default: F_258 () ;
}
if ( F_257 ( V_7 ) )
F_233 () ;
}
static inline int F_259 ( struct V_15 * V_16 ,
struct V_230 * V_332 )
{
return V_332 - V_16 -> V_232 ;
}
static void F_217 ( struct V_6 * V_7 ,
struct V_230 * V_332 ,
bool V_333 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_231 = F_259 ( V_16 , V_332 ) ;
F_218 ( V_7 -> V_8 . V_2 , V_231 , V_333 ? V_7 : NULL ) ;
if ( V_333 ) {
V_7 -> V_13 = V_231 ;
V_332 -> V_7 = V_7 ;
F_164 ( & V_332 -> V_233 , & V_16 -> V_18 . V_234 ) ;
} else {
V_7 -> V_13 = V_14 ;
V_332 -> V_7 = NULL ;
F_187 ( & V_332 -> V_233 ) ;
}
V_7 -> V_12 = false ;
}
static int
F_260 ( struct V_6 * V_7 )
{
if ( V_7 -> V_229 ) {
int V_23 = F_116 ( V_7 -> V_124 , V_7 -> V_229 ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_229 = 0 ;
}
V_7 -> V_228 = false ;
return 0 ;
}
int
F_84 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_230 * V_332 ;
int V_23 ;
V_23 = F_260 ( V_7 ) ;
if ( V_23 )
return V_23 ;
if ( V_7 -> V_13 == V_14 )
return 0 ;
V_332 = & V_16 -> V_232 [ V_7 -> V_13 ] ;
F_4 ( V_7 ) ;
F_217 ( V_7 , V_332 , false ) ;
return 0 ;
}
static struct V_230 *
F_261 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_230 * V_231 , * V_334 ;
int V_207 ;
V_334 = NULL ;
for ( V_207 = V_16 -> V_335 ; V_207 < V_16 -> V_287 ; V_207 ++ ) {
V_231 = & V_16 -> V_232 [ V_207 ] ;
if ( ! V_231 -> V_7 )
return V_231 ;
if ( ! V_231 -> V_46 )
V_334 = V_231 ;
}
if ( V_334 == NULL )
return NULL ;
F_27 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_231 -> V_46 )
continue;
return V_231 ;
}
return NULL ;
}
int
F_130 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_333 = V_7 -> V_11 != V_119 ;
struct V_230 * V_231 ;
int V_23 ;
if ( V_7 -> V_12 ) {
V_23 = F_260 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_7 -> V_13 != V_14 ) {
V_231 = & V_16 -> V_232 [ V_7 -> V_13 ] ;
if ( ! V_7 -> V_12 ) {
F_164 ( & V_231 -> V_233 ,
& V_16 -> V_18 . V_234 ) ;
return 0 ;
}
} else if ( V_333 ) {
V_231 = F_261 ( V_2 ) ;
if ( V_231 == NULL )
return - V_336 ;
if ( V_231 -> V_7 ) {
struct V_6 * V_337 = V_231 -> V_7 ;
V_23 = F_260 ( V_337 ) ;
if ( V_23 )
return V_23 ;
F_4 ( V_337 ) ;
}
} else
return 0 ;
F_217 ( V_7 , V_231 , V_333 ) ;
return 0 ;
}
static bool F_262 ( struct V_1 * V_2 ,
struct V_338 * V_339 ,
unsigned long V_9 )
{
struct V_338 * V_340 ;
if ( F_2 ( V_2 ) )
return true ;
if ( ! F_235 ( V_339 ) )
return true ;
if ( F_161 ( & V_339 -> V_341 ) )
return true ;
V_340 = F_263 ( V_339 -> V_341 . V_342 , struct V_338 , V_341 ) ;
if ( V_340 -> V_343 && ! V_340 -> V_344 && V_340 -> V_345 != V_9 )
return false ;
V_340 = F_263 ( V_339 -> V_341 . V_200 , struct V_338 , V_341 ) ;
if ( V_340 -> V_343 && ! V_339 -> V_344 && V_340 -> V_345 != V_9 )
return false ;
return true ;
}
static void F_264 ( struct V_1 * V_2 )
{
#if V_346
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_6 * V_7 ;
int V_347 = 0 ;
F_27 (obj, &dev_priv->mm.gtt_list, global_list) {
if ( V_7 -> V_339 == NULL ) {
F_265 ( V_348 L_12 ) ;
V_347 ++ ;
continue;
}
if ( V_7 -> V_9 != V_7 -> V_339 -> V_345 ) {
F_265 ( V_348 L_13 ,
F_85 ( V_7 ) ,
F_85 ( V_7 ) + F_28 ( V_7 ) ,
V_7 -> V_9 ,
V_7 -> V_339 -> V_345 ) ;
V_347 ++ ;
continue;
}
if ( ! F_262 ( V_2 ,
V_7 -> V_339 ,
V_7 -> V_9 ) ) {
F_265 ( V_348 L_14 ,
F_85 ( V_7 ) ,
F_85 ( V_7 ) + F_28 ( V_7 ) ,
V_7 -> V_9 ) ;
V_347 ++ ;
continue;
}
}
F_16 ( V_347 ) ;
#endif
}
static int
F_266 ( struct V_6 * V_7 ,
struct V_235 * V_269 ,
unsigned V_349 ,
bool V_310 ,
bool V_350 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
T_9 * V_16 = V_2 -> V_27 ;
T_4 V_17 , V_351 , V_352 , V_353 ;
T_1 V_354 =
V_310 ? V_16 -> V_42 . V_43 : V_269 -> V_48 ;
struct V_203 * V_159 ;
int V_23 ;
V_351 = F_134 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ) ;
V_352 = F_135 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , true ) ;
V_353 =
F_135 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , false ) ;
if ( V_349 == 0 )
V_349 = V_310 ? V_352 :
V_353 ;
if ( V_310 && V_349 & ( V_352 - 1 ) ) {
F_13 ( L_15 , V_349 ) ;
return - V_40 ;
}
V_17 = V_310 ? V_351 : V_7 -> V_8 . V_17 ;
if ( V_7 -> V_8 . V_17 > V_354 ) {
F_13 ( L_16 ,
V_7 -> V_8 . V_17 ,
V_310 ? L_17 : L_18 ,
V_354 ) ;
return - V_183 ;
}
V_23 = F_62 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_63 ( V_7 ) ;
F_101 ( ! F_241 ( V_269 ) ) ;
V_159 = F_267 ( V_7 , V_269 ) ;
if ( F_127 ( V_159 ) ) {
V_23 = F_181 ( V_159 ) ;
goto V_355;
}
F_16 ( ! F_268 ( & V_7 -> V_311 ) ) ;
V_356:
V_23 = F_269 ( & V_269 -> V_18 , & V_159 -> V_305 ,
V_17 , V_349 ,
V_7 -> V_9 , 0 , V_354 ,
V_357 ) ;
if ( V_23 ) {
V_23 = F_270 ( V_2 , V_269 , V_17 , V_349 ,
V_7 -> V_9 ,
V_310 ,
V_350 ) ;
if ( V_23 == 0 )
goto V_356;
goto V_358;
}
if ( F_16 ( ! F_262 ( V_2 , & V_159 -> V_305 ,
V_7 -> V_9 ) ) ) {
V_23 = - V_40 ;
goto V_359;
}
V_23 = F_271 ( V_7 ) ;
if ( V_23 )
goto V_359;
F_164 ( & V_7 -> V_194 , & V_16 -> V_18 . V_202 ) ;
F_182 ( & V_159 -> V_237 , & V_269 -> V_238 ) ;
if ( F_241 ( V_269 ) ) {
bool V_108 , V_360 ;
V_360 = ( V_159 -> V_305 . V_17 == V_351 &&
( V_159 -> V_305 . V_79 & ( V_352 - 1 ) ) == 0 ) ;
V_108 = ( V_159 -> V_305 . V_79 + V_7 -> V_8 . V_17 <=
V_16 -> V_42 . V_43 ) ;
V_7 -> V_310 = V_108 && V_360 ;
}
F_16 ( V_310 && ! V_7 -> V_310 ) ;
F_272 ( V_159 , V_310 ) ;
F_264 ( V_2 ) ;
return 0 ;
V_359:
F_242 ( & V_159 -> V_305 ) ;
V_358:
F_243 ( V_159 ) ;
V_355:
F_71 ( V_7 ) ;
return V_23 ;
}
bool
F_91 ( struct V_6 * V_7 ,
bool V_361 )
{
if ( V_7 -> V_190 == NULL )
return false ;
if ( V_7 -> V_362 )
return false ;
if ( ! V_361 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) )
return false ;
F_273 ( V_7 ) ;
F_274 ( V_7 -> V_190 ) ;
return true ;
}
static void
F_275 ( struct V_6 * V_7 )
{
T_3 V_302 ;
if ( V_7 -> V_8 . V_112 != V_150 )
return;
F_276 () ;
V_302 = V_7 -> V_8 . V_112 ;
V_7 -> V_8 . V_112 = 0 ;
F_234 ( V_7 ,
V_7 -> V_8 . V_89 ,
V_302 ) ;
}
static void
F_124 ( struct V_6 * V_7 ,
bool V_361 )
{
T_3 V_302 ;
if ( V_7 -> V_8 . V_112 != V_90 )
return;
if ( F_91 ( V_7 , V_361 ) )
F_92 ( V_7 -> V_8 . V_2 ) ;
V_302 = V_7 -> V_8 . V_112 ;
V_7 -> V_8 . V_112 = 0 ;
F_234 ( V_7 ,
V_7 -> V_8 . V_89 ,
V_302 ) ;
}
int
F_61 ( struct V_6 * V_7 , bool V_164 )
{
T_9 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
T_3 V_302 , V_303 ;
int V_23 ;
if ( ! F_19 ( V_7 ) )
return - V_40 ;
if ( V_7 -> V_8 . V_112 == V_150 )
return 0 ;
V_23 = F_119 ( V_7 , ! V_164 ) ;
if ( V_23 )
return V_23 ;
F_124 ( V_7 , false ) ;
if ( ( V_7 -> V_8 . V_89 & V_150 ) == 0 )
F_233 () ;
V_302 = V_7 -> V_8 . V_112 ;
V_303 = V_7 -> V_8 . V_89 ;
F_101 ( ( V_7 -> V_8 . V_112 & ~ V_150 ) != 0 ) ;
V_7 -> V_8 . V_89 |= V_150 ;
if ( V_164 ) {
V_7 -> V_8 . V_89 = V_150 ;
V_7 -> V_8 . V_112 = V_150 ;
V_7 -> V_113 = 1 ;
}
F_234 ( V_7 ,
V_303 ,
V_302 ) ;
if ( F_18 ( V_7 ) ) {
struct V_203 * V_159 = F_186 ( V_7 ,
& V_16 -> V_42 . V_8 ) ;
if ( V_159 )
F_164 ( & V_159 -> V_237 ,
& V_16 -> V_42 . V_8 . V_238 ) ;
}
return 0 ;
}
int F_277 ( struct V_6 * V_7 ,
enum V_3 V_9 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
T_9 * V_16 = V_2 -> V_27 ;
struct V_203 * V_159 ;
int V_23 ;
if ( V_7 -> V_9 == V_9 )
return 0 ;
if ( V_7 -> V_46 ) {
F_278 ( L_19 ) ;
return - V_175 ;
}
F_27 (vma, &obj->vma_list, vma_link) {
if ( ! F_262 ( V_2 , & V_159 -> V_305 , V_9 ) ) {
V_23 = F_166 ( V_159 ) ;
if ( V_23 )
return V_23 ;
break;
}
}
if ( F_19 ( V_7 ) ) {
V_23 = F_236 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_232 ( V_7 ) ;
if ( F_22 ( V_2 ) -> V_41 < 6 ) {
V_23 = F_84 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_7 -> V_307 )
F_279 ( V_7 , V_9 ) ;
if ( V_7 -> V_308 )
F_280 ( V_16 -> V_18 . V_309 ,
V_7 , V_9 ) ;
}
F_27 (vma, &obj->vma_list, vma_link)
V_159 -> V_305 . V_345 = V_9 ;
V_7 -> V_9 = V_9 ;
if ( F_3 ( V_7 ) ) {
T_4 V_303 , V_302 ;
F_16 ( V_7 -> V_8 . V_112 & ~ V_90 ) ;
V_303 = V_7 -> V_8 . V_89 ;
V_302 = V_7 -> V_8 . V_112 ;
V_7 -> V_8 . V_89 = V_90 ;
V_7 -> V_8 . V_112 = V_90 ;
F_234 ( V_7 ,
V_303 ,
V_302 ) ;
}
F_264 ( V_2 ) ;
return 0 ;
}
int F_281 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_363 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_74 ( F_75 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
switch ( V_7 -> V_9 ) {
case V_364 :
case V_365 :
args -> V_366 = V_367 ;
break;
case V_368 :
args -> V_366 = V_369 ;
break;
default:
args -> V_366 = V_370 ;
break;
}
F_77 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_282 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_363 * args = V_31 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_23 ;
switch ( args -> V_366 ) {
case V_370 :
V_4 = V_5 ;
break;
case V_367 :
V_4 = V_364 ;
break;
case V_369 :
V_4 = F_283 ( V_2 ) ? V_368 : V_5 ;
break;
default:
return - V_40 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_74 ( F_75 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
V_23 = F_277 ( V_7 , V_4 ) ;
F_77 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static bool F_284 ( struct V_6 * V_7 )
{
return V_7 -> V_46 - ! ! V_7 -> V_371 ;
}
int
F_285 ( struct V_6 * V_7 ,
T_4 V_349 ,
struct V_123 * V_372 )
{
T_4 V_303 , V_302 ;
int V_23 ;
if ( V_372 != V_7 -> V_124 ) {
V_23 = F_229 ( V_7 , V_372 ) ;
if ( V_23 )
return V_23 ;
}
V_7 -> V_10 = true ;
V_23 = F_277 ( V_7 ,
F_283 ( V_7 -> V_8 . V_2 ) ? V_368 : V_5 ) ;
if ( V_23 )
goto V_373;
V_23 = F_83 ( V_7 , V_349 , true , false ) ;
if ( V_23 )
goto V_373;
F_124 ( V_7 , true ) ;
V_302 = V_7 -> V_8 . V_112 ;
V_303 = V_7 -> V_8 . V_89 ;
V_7 -> V_8 . V_112 = 0 ;
V_7 -> V_8 . V_89 |= V_150 ;
F_234 ( V_7 ,
V_303 ,
V_302 ) ;
return 0 ;
V_373:
V_7 -> V_10 = F_284 ( V_7 ) ;
return V_23 ;
}
void
F_286 ( struct V_6 * V_7 )
{
F_86 ( V_7 ) ;
V_7 -> V_10 = F_284 ( V_7 ) ;
}
int
F_236 ( struct V_6 * V_7 )
{
int V_23 ;
if ( ( V_7 -> V_8 . V_89 & V_145 ) == 0 )
return 0 ;
V_23 = F_119 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_8 . V_89 &= ~ V_145 ;
return 0 ;
}
int
F_122 ( struct V_6 * V_7 , bool V_164 )
{
T_3 V_302 , V_303 ;
int V_23 ;
if ( V_7 -> V_8 . V_112 == V_90 )
return 0 ;
V_23 = F_119 ( V_7 , ! V_164 ) ;
if ( V_23 )
return V_23 ;
F_275 ( V_7 ) ;
V_302 = V_7 -> V_8 . V_112 ;
V_303 = V_7 -> V_8 . V_89 ;
if ( ( V_7 -> V_8 . V_89 & V_90 ) == 0 ) {
F_91 ( V_7 , false ) ;
V_7 -> V_8 . V_89 |= V_90 ;
}
F_101 ( ( V_7 -> V_8 . V_112 & ~ V_90 ) != 0 ) ;
if ( V_164 ) {
V_7 -> V_8 . V_89 = V_90 ;
V_7 -> V_8 . V_112 = V_90 ;
}
F_234 ( V_7 ,
V_303 ,
V_302 ) ;
return 0 ;
}
static int
F_287 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_260 * V_259 = V_33 -> V_261 ;
unsigned long V_374 = V_256 - F_288 ( 20 ) ;
struct V_244 * V_245 ;
struct V_123 * V_124 = NULL ;
unsigned V_127 ;
T_4 V_125 = 0 ;
int V_23 ;
V_23 = F_10 ( & V_16 -> V_28 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_97 ( & V_16 -> V_28 , false ) ;
if ( V_23 )
return V_23 ;
F_7 ( & V_259 -> V_18 . V_262 ) ;
F_27 (request, &file_priv->mm.request_list, client_list) {
if ( F_289 ( V_245 -> V_255 , V_374 ) )
break;
V_124 = V_245 -> V_124 ;
V_125 = V_245 -> V_125 ;
}
V_127 = F_111 ( & V_16 -> V_28 . V_127 ) ;
F_8 ( & V_259 -> V_18 . V_262 ) ;
if ( V_125 == 0 )
return 0 ;
V_23 = F_104 ( V_124 , V_125 , V_127 , true , NULL ) ;
if ( V_23 == 0 )
F_202 ( V_16 -> V_266 , & V_16 -> V_18 . V_267 , 0 ) ;
return V_23 ;
}
int
F_290 ( struct V_6 * V_7 ,
struct V_235 * V_269 ,
T_3 V_349 ,
bool V_310 ,
bool V_350 )
{
struct V_203 * V_159 ;
int V_23 ;
if ( F_16 ( V_7 -> V_46 == V_375 ) )
return - V_175 ;
F_16 ( V_310 && ! F_241 ( V_269 ) ) ;
V_159 = F_186 ( V_7 , V_269 ) ;
if ( V_159 ) {
if ( ( V_349 &&
V_159 -> V_305 . V_79 & ( V_349 - 1 ) ) ||
( V_310 && ! V_7 -> V_310 ) ) {
F_105 ( V_7 -> V_46 ,
L_20
L_21
L_22 ,
F_207 ( V_7 , V_269 ) , V_349 ,
V_310 ,
V_7 -> V_310 ) ;
V_23 = F_166 ( V_159 ) ;
if ( V_23 )
return V_23 ;
}
}
if ( ! F_291 ( V_7 , V_269 ) ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
V_23 = F_266 ( V_7 , V_269 , V_349 ,
V_310 ,
V_350 ) ;
if ( V_23 )
return V_23 ;
if ( ! V_16 -> V_18 . V_309 )
F_279 ( V_7 , V_7 -> V_9 ) ;
}
if ( ! V_7 -> V_307 && V_310 )
F_279 ( V_7 , V_7 -> V_9 ) ;
V_7 -> V_46 ++ ;
V_7 -> V_376 |= V_310 ;
return 0 ;
}
void
F_86 ( struct V_6 * V_7 )
{
F_101 ( V_7 -> V_46 == 0 ) ;
F_101 ( ! F_19 ( V_7 ) ) ;
if ( -- V_7 -> V_46 == 0 )
V_7 -> V_376 = false ;
}
int
F_292 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_377 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_74 ( F_75 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( V_7 -> V_184 != V_185 ) {
F_13 ( L_23 ) ;
V_23 = - V_40 ;
goto V_93;
}
if ( V_7 -> V_378 != NULL && V_7 -> V_378 != V_33 ) {
F_13 ( L_24 ,
args -> V_53 ) ;
V_23 = - V_40 ;
goto V_93;
}
if ( V_7 -> V_371 == 0 ) {
V_23 = F_83 ( V_7 , args -> V_349 , true , false ) ;
if ( V_23 )
goto V_93;
}
V_7 -> V_371 ++ ;
V_7 -> V_378 = V_33 ;
args -> V_83 = F_85 ( V_7 ) ;
V_93:
F_77 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_293 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_377 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_74 ( F_75 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( V_7 -> V_378 != V_33 ) {
F_13 ( L_25 ,
args -> V_53 ) ;
V_23 = - V_40 ;
goto V_93;
}
V_7 -> V_371 -- ;
if ( V_7 -> V_371 == 0 ) {
V_7 -> V_378 = NULL ;
F_86 ( V_7 ) ;
}
V_93:
F_77 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_294 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_379 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_74 ( F_75 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
V_23 = F_225 ( V_7 ) ;
args -> V_380 = V_7 -> V_30 ;
if ( V_7 -> V_124 ) {
F_295 ( V_381 > 16 ) ;
args -> V_380 |= F_296 ( V_7 -> V_124 ) << 16 ;
}
F_77 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_297 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_259 )
{
return F_287 ( V_2 , V_259 ) ;
}
int
F_298 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_259 )
{
struct V_382 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
switch ( args -> V_184 ) {
case V_189 :
case V_185 :
break;
default:
return - V_40 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_74 ( F_75 ( V_2 , V_259 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( V_7 -> V_46 ) {
V_23 = - V_40 ;
goto V_93;
}
if ( V_7 -> V_184 != V_188 )
V_7 -> V_184 = args -> V_184 ;
if ( F_150 ( V_7 ) && V_7 -> V_190 == NULL )
F_147 ( V_7 ) ;
args -> V_383 = V_7 -> V_184 != V_188 ;
V_93:
F_77 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void F_299 ( struct V_6 * V_7 ,
const struct V_191 * V_192 )
{
F_160 ( & V_7 -> V_194 ) ;
F_160 ( & V_7 -> V_226 ) ;
F_160 ( & V_7 -> V_384 ) ;
F_160 ( & V_7 -> V_385 ) ;
F_160 ( & V_7 -> V_311 ) ;
V_7 -> V_192 = V_192 ;
V_7 -> V_13 = V_14 ;
V_7 -> V_184 = V_185 ;
V_7 -> V_310 = true ;
F_6 ( V_7 -> V_8 . V_2 -> V_27 , V_7 -> V_8 . V_17 ) ;
}
struct V_6 * F_35 ( struct V_1 * V_2 ,
T_1 V_17 )
{
struct V_6 * V_7 ;
struct V_208 * V_99 ;
T_12 V_386 ;
V_7 = F_29 ( V_2 ) ;
if ( V_7 == NULL )
return NULL ;
if ( F_300 ( V_2 , & V_7 -> V_8 , V_17 ) != 0 ) {
F_31 ( V_7 ) ;
return NULL ;
}
V_386 = V_387 | V_388 ;
if ( F_301 ( V_2 ) || F_302 ( V_2 ) ) {
V_386 &= ~ V_389 ;
V_386 |= V_390 ;
}
V_99 = F_148 ( V_7 -> V_8 . V_97 ) -> V_215 ;
F_303 ( V_99 , V_386 ) ;
F_299 ( V_7 , & V_391 ) ;
V_7 -> V_8 . V_112 = V_90 ;
V_7 -> V_8 . V_89 = V_90 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_9 = V_364 ;
} else
V_7 -> V_9 = V_5 ;
F_304 ( V_7 ) ;
return V_7 ;
}
int F_305 ( struct V_153 * V_7 )
{
F_258 () ;
return 0 ;
}
void F_306 ( struct V_153 * V_392 )
{
struct V_6 * V_7 = F_74 ( V_392 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
T_9 * V_16 = V_2 -> V_27 ;
struct V_203 * V_159 , * V_200 ;
F_307 ( V_7 ) ;
if ( V_7 -> V_118 )
F_308 ( V_2 , V_7 ) ;
V_7 -> V_46 = 0 ;
F_16 ( ! F_161 ( & V_7 -> V_311 ) &&
! F_268 ( & V_7 -> V_311 ) ) ;
F_159 (vma, next, &obj->vma_list, vma_link) {
int V_23 = F_166 ( V_159 ) ;
if ( F_16 ( V_23 == - V_142 ) ) {
bool V_393 ;
V_393 = V_16 -> V_18 . V_121 ;
V_16 -> V_18 . V_121 = false ;
F_16 ( F_166 ( V_159 ) ) ;
V_16 -> V_18 . V_121 = V_393 ;
}
}
if ( V_7 -> V_362 )
F_71 ( V_7 ) ;
if ( F_16 ( V_7 -> V_193 ) )
V_7 -> V_193 = 0 ;
F_156 ( V_7 ) ;
F_142 ( V_7 ) ;
F_309 ( V_7 ) ;
F_101 ( V_7 -> V_190 ) ;
if ( V_7 -> V_8 . V_394 )
F_310 ( & V_7 -> V_8 , NULL ) ;
F_311 ( & V_7 -> V_8 ) ;
F_9 ( V_16 , V_7 -> V_8 . V_17 ) ;
F_155 ( V_7 -> V_395 ) ;
F_31 ( V_7 ) ;
}
struct V_203 * F_312 ( struct V_6 * V_7 ,
struct V_235 * V_269 )
{
struct V_203 * V_159 = F_313 ( sizeof( * V_159 ) , V_51 ) ;
if ( V_159 == NULL )
return F_314 ( - V_54 ) ;
F_160 ( & V_159 -> V_304 ) ;
F_160 ( & V_159 -> V_237 ) ;
F_160 ( & V_159 -> V_384 ) ;
V_159 -> V_269 = V_269 ;
V_159 -> V_7 = V_7 ;
if ( F_241 ( V_269 ) )
F_315 ( & V_159 -> V_304 , & V_7 -> V_311 ) ;
else
F_182 ( & V_159 -> V_304 , & V_7 -> V_311 ) ;
return V_159 ;
}
void F_243 ( struct V_203 * V_159 )
{
F_16 ( V_159 -> V_305 . V_343 ) ;
F_157 ( & V_159 -> V_304 ) ;
F_155 ( V_159 ) ;
}
int
F_316 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( V_16 -> V_264 . V_265 ) {
F_25 ( & V_2 -> V_29 ) ;
return 0 ;
}
V_23 = F_246 ( V_2 ) ;
if ( V_23 ) {
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
F_191 ( V_2 ) ;
if ( ! F_21 ( V_2 , V_35 ) )
F_168 ( V_2 ) ;
F_317 ( & V_16 -> V_28 . V_396 ) ;
F_318 ( V_2 ) ;
F_319 ( V_2 ) ;
F_320 ( & V_16 -> V_18 . V_267 ) ;
return 0 ;
}
void F_321 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
T_4 V_397 ;
int V_207 ;
if ( ! F_322 ( V_2 ) )
return;
if ( ! V_16 -> V_398 . V_399 )
return;
V_397 = F_323 ( V_400 ) ;
F_249 ( V_400 , V_397 & ~ V_401 ) ;
F_250 ( V_400 ) ;
for ( V_207 = 0 ; V_207 < V_402 ; V_207 += 4 ) {
T_4 V_403 = F_323 ( V_404 + V_207 ) ;
if ( V_403 && V_403 != V_16 -> V_398 . V_399 [ V_207 / 4 ] )
F_278 ( L_26 ,
V_404 + V_207 , V_403 ) ;
if ( V_403 && ! V_16 -> V_398 . V_399 [ V_207 / 4 ] )
F_324 ( L_27 ) ;
F_249 ( V_404 + V_207 , V_16 -> V_398 . V_399 [ V_207 / 4 ] ) ;
}
F_250 ( V_404 ) ;
F_249 ( V_400 , V_397 ) ;
}
void F_325 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
if ( F_22 ( V_2 ) -> V_41 < 5 ||
V_16 -> V_18 . V_405 == V_406 )
return;
F_249 ( V_407 , F_323 ( V_407 ) |
V_408 ) ;
if ( F_326 ( V_2 ) )
return;
F_249 ( V_409 , F_323 ( V_409 ) | V_410 ) ;
if ( F_327 ( V_2 ) )
F_249 ( V_411 , F_328 ( V_412 ) ) ;
else if ( F_329 ( V_2 ) )
F_249 ( V_411 , F_328 ( V_413 ) ) ;
else
F_258 () ;
}
static bool
F_330 ( struct V_1 * V_2 )
{
if ( ! F_331 ( V_2 ) )
return false ;
if ( F_327 ( V_2 ) && V_2 -> V_414 -> V_415 < 8 ) {
F_332 ( L_28
L_29 ) ;
return false ;
}
return true ;
}
static int F_333 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
V_23 = F_334 ( V_2 ) ;
if ( V_23 )
return V_23 ;
if ( F_335 ( V_2 ) ) {
V_23 = F_336 ( V_2 ) ;
if ( V_23 )
goto V_416;
}
if ( F_330 ( V_2 ) ) {
V_23 = F_337 ( V_2 ) ;
if ( V_23 )
goto V_417;
}
if ( F_338 ( V_2 ) ) {
V_23 = F_339 ( V_2 ) ;
if ( V_23 )
goto V_418;
}
V_23 = F_194 ( V_2 , ( ( T_4 ) ~ 0 - 0x1000 ) ) ;
if ( V_23 )
goto V_419;
return 0 ;
V_419:
F_340 ( & V_16 -> V_124 [ V_420 ] ) ;
V_418:
F_340 ( & V_16 -> V_124 [ V_421 ] ) ;
V_417:
F_340 ( & V_16 -> V_124 [ V_422 ] ) ;
V_416:
F_340 ( & V_16 -> V_124 [ V_423 ] ) ;
return V_23 ;
}
int
F_341 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( F_22 ( V_2 ) -> V_41 < 6 && ! F_342 () )
return - V_26 ;
if ( V_16 -> V_424 )
F_249 ( V_425 , F_323 ( V_425 ) | F_343 ( 0xf ) ) ;
if ( F_344 ( V_2 ) ) {
T_4 V_426 = F_323 ( V_427 ) ;
V_426 &= ~ ( V_428 | V_429 ) ;
F_249 ( V_427 , V_426 ) ;
}
F_321 ( V_2 ) ;
F_325 ( V_2 ) ;
V_23 = F_333 ( V_2 ) ;
if ( V_23 )
return V_23 ;
F_345 ( V_2 ) ;
if ( V_16 -> V_18 . V_309 ) {
V_23 = V_16 -> V_18 . V_309 -> V_333 ( V_2 ) ;
if ( V_23 ) {
F_346 ( V_2 ) ;
F_332 ( L_30 ) ;
}
}
return 0 ;
}
int F_347 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
F_23 ( & V_2 -> V_29 ) ;
if ( F_348 ( V_2 ) ) {
F_249 ( V_430 , 1 ) ;
if ( F_349 ( ( F_323 ( V_431 ) & 1 ) == 1 , 10 ) )
F_324 ( L_31 ) ;
}
F_350 ( V_2 ) ;
V_23 = F_341 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
if ( V_23 ) {
F_346 ( V_2 ) ;
return V_23 ;
}
if ( ! F_21 ( V_2 , V_35 ) )
V_16 -> V_432 . V_433 = 1 ;
return 0 ;
}
void
F_319 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 ;
int V_207 ;
F_189 (ring, dev_priv, i)
F_340 ( V_124 ) ;
}
int
F_351 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_259 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( F_21 ( V_2 , V_35 ) )
return 0 ;
if ( F_98 ( & V_16 -> V_28 ) ) {
F_13 ( L_32 ) ;
F_352 ( & V_16 -> V_28 . V_127 , 0 ) ;
}
F_23 ( & V_2 -> V_29 ) ;
V_16 -> V_264 . V_265 = 0 ;
V_23 = F_341 ( V_2 ) ;
if ( V_23 != 0 ) {
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
F_101 ( ! F_161 ( & V_16 -> V_42 . V_8 . V_227 ) ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_353 ( V_2 ) ;
if ( V_23 )
goto V_434;
return 0 ;
V_434:
F_23 ( & V_2 -> V_29 ) ;
F_319 ( V_2 ) ;
V_16 -> V_264 . V_265 = 1 ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_354 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_259 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( F_21 ( V_2 , V_35 ) )
return 0 ;
F_355 ( V_2 ) ;
F_23 ( & V_2 -> V_29 ) ;
V_23 = F_316 ( V_2 ) ;
if ( V_23 != 0 )
V_16 -> V_264 . V_265 = 1 ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void
F_356 ( struct V_1 * V_2 )
{
int V_23 ;
if ( F_21 ( V_2 , V_35 ) )
return;
F_23 ( & V_2 -> V_29 ) ;
V_23 = F_316 ( V_2 ) ;
if ( V_23 )
F_13 ( L_33 , V_23 ) ;
F_25 ( & V_2 -> V_29 ) ;
}
static void
F_357 ( struct V_123 * V_124 )
{
F_160 ( & V_124 -> V_227 ) ;
F_160 ( & V_124 -> V_257 ) ;
}
static void F_358 ( struct V_15 * V_16 ,
struct V_235 * V_269 )
{
V_269 -> V_2 = V_16 -> V_2 ;
F_160 ( & V_269 -> V_227 ) ;
F_160 ( & V_269 -> V_238 ) ;
F_160 ( & V_269 -> V_435 ) ;
F_315 ( & V_269 -> V_435 , & V_16 -> V_436 ) ;
}
void
F_359 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
int V_207 ;
V_16 -> V_50 =
F_360 ( L_34 ,
sizeof( struct V_6 ) , 0 ,
V_437 ,
NULL ) ;
F_160 ( & V_16 -> V_436 ) ;
F_358 ( V_16 , & V_16 -> V_42 . V_8 ) ;
F_160 ( & V_16 -> V_18 . V_225 ) ;
F_160 ( & V_16 -> V_18 . V_202 ) ;
F_160 ( & V_16 -> V_18 . V_234 ) ;
for ( V_207 = 0 ; V_207 < V_381 ; V_207 ++ )
F_357 ( & V_16 -> V_124 [ V_207 ] ) ;
for ( V_207 = 0 ; V_207 < V_438 ; V_207 ++ )
F_160 ( & V_16 -> V_232 [ V_207 ] . V_233 ) ;
F_361 ( & V_16 -> V_18 . V_267 ,
F_221 ) ;
F_362 ( & V_16 -> V_28 . V_24 ) ;
if ( F_363 ( V_2 ) ) {
F_249 ( V_439 ,
F_328 ( V_440 ) ) ;
}
V_16 -> V_441 = V_442 ;
if ( ! F_21 ( V_2 , V_35 ) )
V_16 -> V_335 = 3 ;
if ( F_22 ( V_2 ) -> V_41 >= 7 && ! F_348 ( V_2 ) )
V_16 -> V_287 = 32 ;
else if ( F_22 ( V_2 ) -> V_41 >= 4 || F_364 ( V_2 ) || F_365 ( V_2 ) || F_136 ( V_2 ) )
V_16 -> V_287 = 16 ;
else
V_16 -> V_287 = 8 ;
F_160 ( & V_16 -> V_18 . V_234 ) ;
F_216 ( V_2 ) ;
F_366 ( V_2 ) ;
F_362 ( & V_16 -> V_443 ) ;
V_16 -> V_18 . V_121 = true ;
V_16 -> V_18 . V_444 . V_445 = V_446 ;
V_16 -> V_18 . V_444 . V_447 = V_448 ;
V_16 -> V_18 . V_444 . V_449 = V_450 ;
F_367 ( & V_16 -> V_18 . V_444 ) ;
}
static int F_368 ( struct V_1 * V_2 ,
int V_281 , int V_17 , int V_451 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_452 * V_118 ;
int V_23 ;
if ( V_16 -> V_18 . V_453 [ V_281 - 1 ] || ! V_17 )
return 0 ;
V_118 = F_313 ( sizeof( struct V_452 ) , V_51 ) ;
if ( ! V_118 )
return - V_54 ;
V_118 -> V_281 = V_281 ;
V_118 -> V_53 = F_369 ( V_2 , V_17 , V_451 ) ;
if ( ! V_118 -> V_53 ) {
V_23 = - V_54 ;
goto V_454;
}
#ifdef F_370
F_371 ( ( unsigned long ) V_118 -> V_53 -> V_75 , V_118 -> V_53 -> V_17 / V_39 ) ;
#endif
V_16 -> V_18 . V_453 [ V_281 - 1 ] = V_118 ;
return 0 ;
V_454:
F_155 ( V_118 ) ;
return V_23 ;
}
static void F_372 ( struct V_1 * V_2 , int V_281 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_452 * V_118 ;
if ( ! V_16 -> V_18 . V_453 [ V_281 - 1 ] )
return;
V_118 = V_16 -> V_18 . V_453 [ V_281 - 1 ] ;
if ( V_118 -> V_455 ) {
F_308 ( V_2 , V_118 -> V_455 ) ;
}
#ifdef F_370
F_373 ( ( unsigned long ) V_118 -> V_53 -> V_75 , V_118 -> V_53 -> V_17 / V_39 ) ;
#endif
F_374 ( V_2 , V_118 -> V_53 ) ;
F_155 ( V_118 ) ;
V_16 -> V_18 . V_453 [ V_281 - 1 ] = NULL ;
}
void F_375 ( struct V_1 * V_2 )
{
int V_207 ;
for ( V_207 = V_456 ; V_207 <= V_457 ; V_207 ++ )
F_372 ( V_2 , V_207 ) ;
}
void F_308 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_208 * V_99 = F_148 ( V_7 -> V_8 . V_97 ) -> V_215 ;
char * V_75 ;
int V_207 ;
int V_206 ;
if ( ! V_7 -> V_118 )
return;
V_75 = V_7 -> V_118 -> V_53 -> V_75 ;
V_206 = V_7 -> V_8 . V_17 / V_39 ;
for ( V_207 = 0 ; V_207 < V_206 ; V_207 ++ ) {
struct V_69 * V_69 = F_376 ( V_99 , V_207 ) ;
if ( ! F_127 ( V_69 ) ) {
char * V_458 = F_48 ( V_69 ) ;
memcpy ( V_458 , V_75 + V_207 * V_39 , V_39 ) ;
F_51 ( V_458 ) ;
F_377 ( & V_69 , 1 ) ;
F_90 ( V_69 ) ;
F_70 ( V_69 ) ;
F_153 ( V_69 ) ;
}
}
F_92 ( V_2 ) ;
V_7 -> V_118 -> V_455 = NULL ;
V_7 -> V_118 = NULL ;
}
int
F_378 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_281 ,
int V_451 )
{
struct V_208 * V_99 = F_148 ( V_7 -> V_8 . V_97 ) -> V_215 ;
T_9 * V_16 = V_2 -> V_27 ;
int V_23 = 0 ;
int V_206 ;
int V_207 ;
if ( V_281 > V_457 )
return - V_40 ;
if ( V_7 -> V_118 ) {
if ( V_7 -> V_118 -> V_281 == V_281 )
return 0 ;
F_308 ( V_2 , V_7 ) ;
}
if ( ! V_16 -> V_18 . V_453 [ V_281 - 1 ] ) {
V_23 = F_368 ( V_2 , V_281 ,
V_7 -> V_8 . V_17 , V_451 ) ;
if ( V_23 ) {
F_13 ( L_35 ,
V_281 , V_7 -> V_8 . V_17 ) ;
return V_23 ;
}
}
V_7 -> V_118 = V_16 -> V_18 . V_453 [ V_281 - 1 ] ;
V_7 -> V_118 -> V_455 = V_7 ;
V_206 = V_7 -> V_8 . V_17 / V_39 ;
for ( V_207 = 0 ; V_207 < V_206 ; V_207 ++ ) {
struct V_69 * V_69 ;
char * V_458 , * V_459 ;
V_69 = F_376 ( V_99 , V_207 ) ;
if ( F_127 ( V_69 ) )
return F_181 ( V_69 ) ;
V_459 = F_48 ( V_69 ) ;
V_458 = V_7 -> V_118 -> V_53 -> V_75 + ( V_207 * V_39 ) ;
memcpy ( V_458 , V_459 , V_39 ) ;
F_51 ( V_459 ) ;
F_70 ( V_69 ) ;
F_153 ( V_69 ) ;
}
return 0 ;
}
static int
F_96 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_105 * args ,
struct V_32 * V_259 )
{
void * V_75 = V_7 -> V_118 -> V_53 -> V_75 + args -> V_83 ;
char T_5 * V_72 = F_59 ( args -> V_88 ) ;
if ( F_80 ( V_75 , V_72 , args -> V_17 ) ) {
unsigned long V_103 ;
F_25 ( & V_2 -> V_29 ) ;
V_103 = F_379 ( V_75 , V_72 , args -> V_17 ) ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_103 )
return - V_76 ;
}
F_92 ( V_2 ) ;
return 0 ;
}
void F_380 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_260 * V_259 = V_33 -> V_261 ;
F_7 ( & V_259 -> V_18 . V_262 ) ;
while ( ! F_161 ( & V_259 -> V_18 . V_257 ) ) {
struct V_244 * V_245 ;
V_245 = F_162 ( & V_259 -> V_18 . V_257 ,
struct V_244 ,
V_263 ) ;
F_157 ( & V_245 -> V_263 ) ;
V_245 -> V_259 = NULL ;
}
F_8 ( & V_259 -> V_18 . V_262 ) ;
}
static bool F_381 ( struct V_460 * V_460 , struct V_461 * V_462 )
{
if ( ! F_102 ( V_460 ) )
return false ;
#if F_382 ( V_463 ) || F_382 ( V_464 )
return V_460 -> V_465 == V_462 ;
#else
return false ;
#endif
}
static unsigned long
V_448 ( struct V_466 * V_466 , struct V_467 * V_468 )
{
struct V_15 * V_16 =
F_222 ( V_466 ,
struct V_15 ,
V_18 . V_444 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_6 * V_7 ;
bool V_96 = true ;
unsigned long V_201 ;
if ( ! F_223 ( & V_2 -> V_29 ) ) {
if ( ! F_381 ( & V_2 -> V_29 , V_469 ) )
return 0 ;
if ( V_16 -> V_18 . V_182 )
return 0 ;
V_96 = false ;
}
V_201 = 0 ;
F_27 (obj, &dev_priv->mm.unbound_list, global_list)
if ( V_7 -> V_193 == 0 )
V_201 += V_7 -> V_8 . V_17 >> V_169 ;
F_27 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_7 -> V_30 )
continue;
if ( V_7 -> V_46 == 0 && V_7 -> V_193 == 0 )
V_201 += V_7 -> V_8 . V_17 >> V_169 ;
}
if ( V_96 )
F_25 ( & V_2 -> V_29 ) ;
return V_201 ;
}
unsigned long F_207 ( struct V_6 * V_470 ,
struct V_235 * V_269 )
{
struct V_15 * V_16 = V_470 -> V_8 . V_2 -> V_27 ;
struct V_203 * V_159 ;
if ( V_269 == & V_16 -> V_18 . V_309 -> V_8 )
V_269 = & V_16 -> V_42 . V_8 ;
F_101 ( F_161 ( & V_470 -> V_311 ) ) ;
F_27 (vma, &o->vma_list, vma_link) {
if ( V_159 -> V_269 == V_269 )
return V_159 -> V_305 . V_79 ;
}
return - 1 ;
}
bool F_291 ( struct V_6 * V_470 ,
struct V_235 * V_269 )
{
struct V_203 * V_159 ;
F_27 (vma, &o->vma_list, vma_link)
if ( V_159 -> V_269 == V_269 && F_235 ( & V_159 -> V_305 ) )
return true ;
return false ;
}
bool F_19 ( struct V_6 * V_470 )
{
struct V_15 * V_16 = V_470 -> V_8 . V_2 -> V_27 ;
struct V_235 * V_269 ;
F_27 (vm, &dev_priv->vm_list, global_link)
if ( F_291 ( V_470 , V_269 ) )
return true ;
return false ;
}
unsigned long F_383 ( struct V_6 * V_470 ,
struct V_235 * V_269 )
{
struct V_15 * V_16 = V_470 -> V_8 . V_2 -> V_27 ;
struct V_203 * V_159 ;
if ( V_269 == & V_16 -> V_18 . V_309 -> V_8 )
V_269 = & V_16 -> V_42 . V_8 ;
F_101 ( F_161 ( & V_470 -> V_311 ) ) ;
F_27 (vma, &o->vma_list, vma_link)
if ( V_159 -> V_269 == V_269 )
return V_159 -> V_305 . V_17 ;
return 0 ;
}
static unsigned long
V_446 ( struct V_466 * V_466 , struct V_467 * V_468 )
{
struct V_15 * V_16 =
F_222 ( V_466 ,
struct V_15 ,
V_18 . V_444 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
int V_471 = V_468 -> V_471 ;
unsigned long V_205 ;
bool V_96 = true ;
if ( ! F_223 ( & V_2 -> V_29 ) ) {
if ( ! F_381 ( & V_2 -> V_29 , V_469 ) )
return V_472 ;
if ( V_16 -> V_18 . V_182 )
return V_472 ;
V_96 = false ;
}
V_205 = F_140 ( V_16 , V_471 ) ;
if ( V_205 < V_471 )
V_205 += F_158 ( V_16 , V_471 ,
false ) ;
if ( V_205 < V_471 )
V_205 += F_141 ( V_16 ) ;
if ( V_96 )
F_25 ( & V_2 -> V_29 ) ;
return V_205 ;
}
struct V_203 * F_186 ( struct V_6 * V_7 ,
struct V_235 * V_269 )
{
struct V_203 * V_159 ;
F_27 (vma, &obj->vma_list, vma_link)
if ( V_159 -> V_269 == V_269 )
return V_159 ;
return NULL ;
}
struct V_203 *
F_267 ( struct V_6 * V_7 ,
struct V_235 * V_269 )
{
struct V_203 * V_159 ;
V_159 = F_186 ( V_7 , V_269 ) ;
if ( ! V_159 )
V_159 = F_312 ( V_7 , V_269 ) ;
return V_159 ;
}

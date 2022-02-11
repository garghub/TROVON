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
static void F_4 ( struct V_11 * V_12 ,
T_1 V_13 )
{
F_5 ( & V_12 -> V_14 . V_15 ) ;
V_12 -> V_14 . V_16 ++ ;
V_12 -> V_14 . V_17 += V_13 ;
F_6 ( & V_12 -> V_14 . V_15 ) ;
}
static void F_7 ( struct V_11 * V_12 ,
T_1 V_13 )
{
F_5 ( & V_12 -> V_14 . V_15 ) ;
V_12 -> V_14 . V_16 -- ;
V_12 -> V_14 . V_17 -= V_13 ;
F_6 ( & V_12 -> V_14 . V_15 ) ;
}
static int
F_8 ( struct V_18 * error )
{
int V_19 ;
#define F_9 (!i915_reset_in_progress(error) || \
i915_terminally_wedged(error))
if ( F_9 )
return 0 ;
V_19 = F_10 ( error -> V_20 ,
F_9 ,
10 * V_21 ) ;
if ( V_19 == 0 ) {
F_11 ( L_1 ) ;
return - V_22 ;
} else if ( V_19 < 0 ) {
return V_19 ;
}
#undef F_9
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 ;
V_19 = F_8 ( & V_12 -> V_24 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_13 ( & V_2 -> V_25 ) ;
if ( V_19 )
return V_19 ;
F_14 ( F_15 ( V_2 ) ) ;
return 0 ;
}
int
F_16 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_29 * args = V_26 ;
struct V_30 * V_31 = & V_12 -> V_32 ;
struct V_33 * V_34 ;
T_1 V_35 ;
V_35 = 0 ;
F_17 ( & V_2 -> V_25 ) ;
F_18 (vma, &ggtt->base.active_list, mm_list)
if ( V_34 -> V_36 )
V_35 += V_34 -> V_37 . V_13 ;
F_18 (vma, &ggtt->base.inactive_list, mm_list)
if ( V_34 -> V_36 )
V_35 += V_34 -> V_37 . V_13 ;
F_19 ( & V_2 -> V_25 ) ;
args -> V_38 = V_12 -> V_32 . V_8 . V_39 ;
args -> V_40 = args -> V_38 - V_35 ;
return 0 ;
}
static int
F_20 ( struct V_6 * V_7 )
{
struct V_41 * V_42 = F_21 ( V_7 -> V_8 . V_43 ) -> V_44 ;
char * V_45 = V_7 -> V_46 -> V_45 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
int V_51 ;
if ( F_14 ( F_22 ( V_7 ) ) )
return - V_52 ;
for ( V_51 = 0 ; V_51 < V_7 -> V_8 . V_13 / V_53 ; V_51 ++ ) {
struct V_54 * V_54 ;
char * V_55 ;
V_54 = F_23 ( V_42 , V_51 ) ;
if ( F_24 ( V_54 ) )
return F_25 ( V_54 ) ;
V_55 = F_26 ( V_54 ) ;
memcpy ( V_45 , V_55 , V_53 ) ;
F_27 ( V_45 , V_53 ) ;
F_28 ( V_55 ) ;
F_29 ( V_54 ) ;
V_45 += V_53 ;
}
F_30 ( V_7 -> V_8 . V_2 ) ;
V_48 = F_31 ( sizeof( * V_48 ) , V_56 ) ;
if ( V_48 == NULL )
return - V_57 ;
if ( F_32 ( V_48 , 1 , V_56 ) ) {
F_33 ( V_48 ) ;
return - V_57 ;
}
V_50 = V_48 -> V_58 ;
V_50 -> V_59 = 0 ;
V_50 -> V_60 = V_7 -> V_8 . V_13 ;
F_34 ( V_50 ) = V_7 -> V_46 -> V_61 ;
F_35 ( V_50 ) = V_7 -> V_8 . V_13 ;
V_7 -> V_62 = V_48 ;
return 0 ;
}
static void
F_36 ( struct V_6 * V_7 )
{
int V_19 ;
F_37 ( V_7 -> V_63 == V_64 ) ;
V_19 = F_38 ( V_7 , true ) ;
if ( V_19 ) {
F_14 ( V_19 != - V_22 ) ;
V_7 -> V_8 . V_65 = V_7 -> V_8 . V_66 = V_67 ;
}
if ( V_7 -> V_63 == V_68 )
V_7 -> V_69 = 0 ;
if ( V_7 -> V_69 ) {
struct V_41 * V_42 = F_21 ( V_7 -> V_8 . V_43 ) -> V_44 ;
char * V_45 = V_7 -> V_46 -> V_45 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_7 -> V_8 . V_13 / V_53 ; V_51 ++ ) {
struct V_54 * V_54 ;
char * V_70 ;
V_54 = F_23 ( V_42 , V_51 ) ;
if ( F_24 ( V_54 ) )
continue;
V_70 = F_26 ( V_54 ) ;
F_27 ( V_45 , V_53 ) ;
memcpy ( V_70 , V_45 , V_53 ) ;
F_28 ( V_70 ) ;
F_39 ( V_54 ) ;
if ( V_7 -> V_63 == V_71 )
F_40 ( V_54 ) ;
F_29 ( V_54 ) ;
V_45 += V_53 ;
}
V_7 -> V_69 = 0 ;
}
F_41 ( V_7 -> V_62 ) ;
F_33 ( V_7 -> V_62 ) ;
}
static void
F_42 ( struct V_6 * V_7 )
{
F_43 ( V_7 -> V_8 . V_2 , V_7 -> V_46 ) ;
}
static int
F_44 ( struct V_6 * V_7 )
{
struct V_33 * V_34 , * V_72 ;
int V_19 ;
F_45 ( & V_7 -> V_8 ) ;
F_46 (vma, next, &obj->vma_list, vma_link)
if ( F_47 ( V_34 ) )
break;
V_19 = F_48 ( V_7 ) ;
F_49 ( & V_7 -> V_8 ) ;
return V_19 ;
}
int
F_50 ( struct V_6 * V_7 ,
int V_73 )
{
T_2 * V_74 ;
int V_19 ;
if ( V_7 -> V_46 ) {
if ( ( unsigned long ) V_7 -> V_46 -> V_45 & ( V_73 - 1 ) )
return - V_75 ;
return 0 ;
}
if ( V_7 -> V_63 != V_71 )
return - V_76 ;
if ( V_7 -> V_8 . V_43 == NULL )
return - V_52 ;
V_19 = F_44 ( V_7 ) ;
if ( V_19 )
return V_19 ;
V_74 = F_51 ( V_7 -> V_8 . V_2 , V_7 -> V_8 . V_13 , V_73 ) ;
if ( ! V_74 )
return - V_57 ;
V_7 -> V_46 = V_74 ;
V_7 -> V_77 = & V_78 ;
return F_52 ( V_7 ) ;
}
static int
F_53 ( struct V_6 * V_7 ,
struct V_79 * args ,
struct V_27 * V_80 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
void * V_45 = V_7 -> V_46 -> V_45 + args -> V_59 ;
char T_3 * V_81 = F_54 ( args -> V_82 ) ;
int V_19 = 0 ;
V_19 = F_55 ( V_7 , false ) ;
if ( V_19 )
return V_19 ;
F_56 ( V_7 , V_83 ) ;
if ( F_57 ( V_45 , V_81 , args -> V_13 ) ) {
unsigned long V_84 ;
F_19 ( & V_2 -> V_25 ) ;
V_84 = F_58 ( V_45 , V_81 , args -> V_13 ) ;
F_17 ( & V_2 -> V_25 ) ;
if ( V_84 ) {
V_19 = - V_76 ;
goto V_85;
}
}
F_27 ( V_45 , args -> V_13 ) ;
F_30 ( V_2 ) ;
V_85:
F_59 ( V_7 , false , V_83 ) ;
return V_19 ;
}
void * F_60 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
return F_61 ( V_12 -> V_86 , V_56 ) ;
}
void F_62 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
F_63 ( V_12 -> V_86 , V_7 ) ;
}
static int
F_64 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
T_4 V_13 ,
T_5 * V_87 )
{
struct V_6 * V_7 ;
int V_19 ;
T_6 V_88 ;
V_13 = F_65 ( V_13 , V_53 ) ;
if ( V_13 == 0 )
return - V_52 ;
V_7 = F_66 ( V_2 , V_13 ) ;
if ( V_7 == NULL )
return - V_57 ;
V_19 = F_67 ( V_28 , & V_7 -> V_8 , & V_88 ) ;
F_68 ( & V_7 -> V_8 ) ;
if ( V_19 )
return V_19 ;
* V_87 = V_88 ;
return 0 ;
}
int
F_69 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_89 * args )
{
args -> V_90 = F_70 ( args -> V_91 * F_71 ( args -> V_92 , 8 ) , 64 ) ;
args -> V_13 = args -> V_90 * args -> V_93 ;
return F_64 ( V_28 , V_2 ,
args -> V_13 , & args -> V_88 ) ;
}
int
F_72 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_94 * args = V_26 ;
return F_64 ( V_28 , V_2 ,
args -> V_13 , & args -> V_88 ) ;
}
static inline int
F_73 ( char T_3 * V_95 ,
const char * V_96 , int V_97 ,
int V_60 )
{
int V_19 , V_98 = 0 ;
while ( V_60 > 0 ) {
int V_99 = F_70 ( V_97 + 1 , 64 ) ;
int V_100 = F_74 ( V_99 - V_97 , V_60 ) ;
int V_101 = V_97 ^ 64 ;
V_19 = F_75 ( V_95 + V_98 ,
V_96 + V_101 ,
V_100 ) ;
if ( V_19 )
return V_19 + V_60 ;
V_98 += V_100 ;
V_97 += V_100 ;
V_60 -= V_100 ;
}
return 0 ;
}
static inline int
F_76 ( char * V_96 , int V_97 ,
const char T_3 * V_95 ,
int V_60 )
{
int V_19 , V_98 = 0 ;
while ( V_60 > 0 ) {
int V_99 = F_70 ( V_97 + 1 , 64 ) ;
int V_100 = F_74 ( V_99 - V_97 , V_60 ) ;
int V_101 = V_97 ^ 64 ;
V_19 = F_77 ( V_96 + V_101 ,
V_95 + V_98 ,
V_100 ) ;
if ( V_19 )
return V_19 + V_60 ;
V_98 += V_100 ;
V_97 += V_100 ;
V_60 -= V_100 ;
}
return 0 ;
}
int F_78 ( struct V_6 * V_7 ,
int * V_102 )
{
int V_19 ;
* V_102 = 0 ;
if ( ! V_7 -> V_8 . V_43 )
return - V_52 ;
if ( ! ( V_7 -> V_8 . V_65 & V_67 ) ) {
* V_102 = ! F_1 ( V_7 -> V_8 . V_2 ,
V_7 -> V_9 ) ;
V_19 = F_55 ( V_7 , true ) ;
if ( V_19 )
return V_19 ;
}
V_19 = F_52 ( V_7 ) ;
if ( V_19 )
return V_19 ;
F_79 ( V_7 ) ;
return V_19 ;
}
static int
F_80 ( struct V_54 * V_54 , int V_103 , int V_104 ,
char T_3 * V_81 ,
bool V_105 , bool V_102 )
{
char * V_45 ;
int V_19 ;
if ( F_81 ( V_105 ) )
return - V_52 ;
V_45 = F_26 ( V_54 ) ;
if ( V_102 )
F_27 ( V_45 + V_103 ,
V_104 ) ;
V_19 = F_82 ( V_81 ,
V_45 + V_103 ,
V_104 ) ;
F_28 ( V_45 ) ;
return V_19 ? - V_76 : 0 ;
}
static void
F_83 ( char * V_106 , unsigned long V_60 ,
bool V_107 )
{
if ( F_81 ( V_107 ) ) {
unsigned long V_108 = ( unsigned long ) V_106 ;
unsigned long V_109 = ( unsigned long ) V_106 + V_60 ;
V_108 = F_84 ( V_108 , 128 ) ;
V_109 = F_85 ( V_109 , 128 ) ;
F_27 ( ( void * ) V_108 , V_109 - V_108 ) ;
} else {
F_27 ( V_106 , V_60 ) ;
}
}
static int
F_86 ( struct V_54 * V_54 , int V_103 , int V_104 ,
char T_3 * V_81 ,
bool V_105 , bool V_102 )
{
char * V_45 ;
int V_19 ;
V_45 = F_87 ( V_54 ) ;
if ( V_102 )
F_83 ( V_45 + V_103 ,
V_104 ,
V_105 ) ;
if ( V_105 )
V_19 = F_73 ( V_81 ,
V_45 , V_103 ,
V_104 ) ;
else
V_19 = F_75 ( V_81 ,
V_45 + V_103 ,
V_104 ) ;
F_88 ( V_54 ) ;
return V_19 ? - V_76 : 0 ;
}
static int
F_89 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_110 * args ,
struct V_27 * V_28 )
{
char T_3 * V_81 ;
T_7 V_111 ;
T_8 V_59 ;
int V_103 , V_104 , V_19 = 0 ;
int V_112 , V_105 ;
int V_113 = 0 ;
int V_102 = 0 ;
struct V_114 V_115 ;
V_81 = F_54 ( args -> V_82 ) ;
V_111 = args -> V_13 ;
V_112 = F_22 ( V_7 ) ;
V_19 = F_78 ( V_7 , & V_102 ) ;
if ( V_19 )
return V_19 ;
V_59 = args -> V_59 ;
F_90 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_54 * V_54 = F_91 ( & V_115 ) ;
if ( V_111 <= 0 )
break;
V_103 = F_92 ( V_59 ) ;
V_104 = V_111 ;
if ( ( V_103 + V_104 ) > V_53 )
V_104 = V_53 - V_103 ;
V_105 = V_112 &&
( F_93 ( V_54 ) & ( 1 << 17 ) ) != 0 ;
V_19 = F_80 ( V_54 , V_103 , V_104 ,
V_81 , V_105 ,
V_102 ) ;
if ( V_19 == 0 )
goto V_116;
F_19 ( & V_2 -> V_25 ) ;
if ( F_94 ( ! V_117 . V_118 ) && ! V_113 ) {
V_19 = F_95 ( V_81 , V_111 ) ;
( void ) V_19 ;
V_113 = 1 ;
}
V_19 = F_86 ( V_54 , V_103 , V_104 ,
V_81 , V_105 ,
V_102 ) ;
F_17 ( & V_2 -> V_25 ) ;
if ( V_19 )
goto V_85;
V_116:
V_111 -= V_104 ;
V_81 += V_104 ;
V_59 += V_104 ;
}
V_85:
F_96 ( V_7 ) ;
return V_19 ;
}
int
F_97 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_110 * args = V_26 ;
struct V_6 * V_7 ;
int V_19 = 0 ;
if ( args -> V_13 == 0 )
return 0 ;
if ( ! F_98 ( V_119 ,
F_54 ( args -> V_82 ) ,
args -> V_13 ) )
return - V_76 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_120 ;
goto V_121;
}
if ( args -> V_59 > V_7 -> V_8 . V_13 ||
args -> V_13 > V_7 -> V_8 . V_13 - args -> V_59 ) {
V_19 = - V_52 ;
goto V_85;
}
if ( ! V_7 -> V_8 . V_43 ) {
V_19 = - V_52 ;
goto V_85;
}
F_101 ( V_7 , args -> V_59 , args -> V_13 ) ;
V_19 = F_89 ( V_2 , V_7 , args , V_28 ) ;
V_85:
F_49 ( & V_7 -> V_8 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
static inline int
F_102 ( struct V_122 * V_42 ,
T_8 V_123 , int V_124 ,
char T_3 * V_81 ,
int V_60 )
{
void T_9 * V_125 ;
void * V_45 ;
unsigned long V_84 ;
V_125 = F_103 ( V_42 , V_123 ) ;
V_45 = ( void V_126 * ) V_125 + V_124 ;
V_84 = F_57 ( V_45 ,
V_81 , V_60 ) ;
F_104 ( V_125 ) ;
return V_84 ;
}
static int
F_105 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_79 * args ,
struct V_27 * V_28 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
T_7 V_111 ;
T_8 V_59 , V_123 ;
char T_3 * V_81 ;
int V_124 , V_104 , V_19 ;
V_19 = F_106 ( V_7 , 0 , V_127 | V_128 ) ;
if ( V_19 )
goto V_85;
V_19 = F_107 ( V_7 , true ) ;
if ( V_19 )
goto V_129;
V_19 = F_108 ( V_7 ) ;
if ( V_19 )
goto V_129;
V_81 = F_54 ( args -> V_82 ) ;
V_111 = args -> V_13 ;
V_59 = F_109 ( V_7 ) + args -> V_59 ;
F_56 ( V_7 , V_130 ) ;
while ( V_111 > 0 ) {
V_123 = V_59 & V_131 ;
V_124 = F_92 ( V_59 ) ;
V_104 = V_111 ;
if ( ( V_124 + V_111 ) > V_53 )
V_104 = V_53 - V_124 ;
if ( F_102 ( V_12 -> V_32 . V_132 , V_123 ,
V_124 , V_81 , V_104 ) ) {
V_19 = - V_76 ;
goto V_133;
}
V_111 -= V_104 ;
V_81 += V_104 ;
V_59 += V_104 ;
}
V_133:
F_59 ( V_7 , false , V_130 ) ;
V_129:
F_110 ( V_7 ) ;
V_85:
return V_19 ;
}
static int
F_111 ( struct V_54 * V_54 , int V_103 , int V_104 ,
char T_3 * V_81 ,
bool V_105 ,
bool V_134 ,
bool V_135 )
{
char * V_45 ;
int V_19 ;
if ( F_81 ( V_105 ) )
return - V_52 ;
V_45 = F_26 ( V_54 ) ;
if ( V_134 )
F_27 ( V_45 + V_103 ,
V_104 ) ;
V_19 = F_112 ( V_45 + V_103 ,
V_81 , V_104 ) ;
if ( V_135 )
F_27 ( V_45 + V_103 ,
V_104 ) ;
F_28 ( V_45 ) ;
return V_19 ? - V_76 : 0 ;
}
static int
F_113 ( struct V_54 * V_54 , int V_103 , int V_104 ,
char T_3 * V_81 ,
bool V_105 ,
bool V_134 ,
bool V_135 )
{
char * V_45 ;
int V_19 ;
V_45 = F_87 ( V_54 ) ;
if ( F_81 ( V_134 || V_105 ) )
F_83 ( V_45 + V_103 ,
V_104 ,
V_105 ) ;
if ( V_105 )
V_19 = F_76 ( V_45 , V_103 ,
V_81 ,
V_104 ) ;
else
V_19 = F_77 ( V_45 + V_103 ,
V_81 ,
V_104 ) ;
if ( V_135 )
F_83 ( V_45 + V_103 ,
V_104 ,
V_105 ) ;
F_88 ( V_54 ) ;
return V_19 ? - V_76 : 0 ;
}
static int
F_114 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_79 * args ,
struct V_27 * V_28 )
{
T_7 V_111 ;
T_8 V_59 ;
char T_3 * V_81 ;
int V_103 , V_104 , V_19 = 0 ;
int V_112 , V_105 ;
int V_136 = 0 ;
int V_135 = 0 ;
int V_134 = 0 ;
struct V_114 V_115 ;
V_81 = F_54 ( args -> V_82 ) ;
V_111 = args -> V_13 ;
V_112 = F_22 ( V_7 ) ;
if ( V_7 -> V_8 . V_66 != V_67 ) {
V_135 = F_3 ( V_7 ) ;
V_19 = F_55 ( V_7 , false ) ;
if ( V_19 )
return V_19 ;
}
if ( ( V_7 -> V_8 . V_65 & V_67 ) == 0 )
V_134 =
! F_1 ( V_2 , V_7 -> V_9 ) ;
V_19 = F_52 ( V_7 ) ;
if ( V_19 )
return V_19 ;
F_56 ( V_7 , V_83 ) ;
F_79 ( V_7 ) ;
V_59 = args -> V_59 ;
V_7 -> V_69 = 1 ;
F_90 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_54 * V_54 = F_91 ( & V_115 ) ;
int V_137 ;
if ( V_111 <= 0 )
break;
V_103 = F_92 ( V_59 ) ;
V_104 = V_111 ;
if ( ( V_103 + V_104 ) > V_53 )
V_104 = V_53 - V_103 ;
V_137 = V_134 &&
( ( V_103 | V_104 )
& ( V_138 . V_139 - 1 ) ) ;
V_105 = V_112 &&
( F_93 ( V_54 ) & ( 1 << 17 ) ) != 0 ;
V_19 = F_111 ( V_54 , V_103 , V_104 ,
V_81 , V_105 ,
V_137 ,
V_135 ) ;
if ( V_19 == 0 )
goto V_116;
V_136 = 1 ;
F_19 ( & V_2 -> V_25 ) ;
V_19 = F_113 ( V_54 , V_103 , V_104 ,
V_81 , V_105 ,
V_137 ,
V_135 ) ;
F_17 ( & V_2 -> V_25 ) ;
if ( V_19 )
goto V_85;
V_116:
V_111 -= V_104 ;
V_81 += V_104 ;
V_59 += V_104 ;
}
V_85:
F_96 ( V_7 ) ;
if ( V_136 ) {
if ( ! V_135 &&
V_7 -> V_8 . V_66 != V_67 ) {
if ( F_115 ( V_7 , V_7 -> V_10 ) )
F_30 ( V_2 ) ;
}
}
if ( V_135 )
F_30 ( V_2 ) ;
F_59 ( V_7 , false , V_83 ) ;
return V_19 ;
}
int
F_116 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_79 * args = V_26 ;
struct V_6 * V_7 ;
int V_19 ;
if ( args -> V_13 == 0 )
return 0 ;
if ( ! F_98 ( V_140 ,
F_54 ( args -> V_82 ) ,
args -> V_13 ) )
return - V_76 ;
if ( F_94 ( ! V_117 . V_118 ) ) {
V_19 = F_117 ( F_54 ( args -> V_82 ) ,
args -> V_13 ) ;
if ( V_19 )
return - V_76 ;
}
F_118 ( V_12 ) ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
goto V_141;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_120 ;
goto V_121;
}
if ( args -> V_59 > V_7 -> V_8 . V_13 ||
args -> V_13 > V_7 -> V_8 . V_13 - args -> V_59 ) {
V_19 = - V_52 ;
goto V_85;
}
if ( ! V_7 -> V_8 . V_43 ) {
V_19 = - V_52 ;
goto V_85;
}
F_119 ( V_7 , args -> V_59 , args -> V_13 ) ;
V_19 = - V_76 ;
if ( V_7 -> V_142 == V_143 &&
V_7 -> V_8 . V_66 != V_67 &&
F_3 ( V_7 ) ) {
V_19 = F_105 ( V_2 , V_7 , args , V_28 ) ;
}
if ( V_19 == - V_76 || V_19 == - V_144 ) {
if ( V_7 -> V_46 )
V_19 = F_53 ( V_7 , args , V_28 ) ;
else
V_19 = F_114 ( V_2 , V_7 , args , V_28 ) ;
}
V_85:
F_49 ( & V_7 -> V_8 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
V_141:
F_120 ( V_12 ) ;
return V_19 ;
}
int
F_121 ( struct V_18 * error ,
bool V_145 )
{
if ( F_122 ( error ) ) {
if ( ! V_145 )
return - V_22 ;
if ( F_123 ( error ) )
return - V_22 ;
if ( ! error -> V_146 )
return - V_147 ;
}
return 0 ;
}
static void F_124 ( unsigned long V_26 )
{
F_125 ( (struct V_148 * ) V_26 ) ;
}
static bool F_126 ( struct V_11 * V_12 ,
struct V_149 * V_150 )
{
return F_127 ( V_150 -> V_151 , & V_12 -> V_24 . V_152 ) ;
}
static int F_128 ( struct V_153 * V_154 )
{
unsigned long V_155 ;
if ( F_129 ( V_154 ) -> V_156 )
return - V_75 ;
V_155 = V_157 + 1 ;
while ( ! F_130 () ) {
if ( F_131 ( V_154 , true ) )
return 0 ;
if ( F_132 ( V_157 , V_155 ) )
break;
F_133 () ;
}
if ( F_131 ( V_154 , false ) )
return 0 ;
return - V_147 ;
}
int F_134 ( struct V_153 * V_154 ,
unsigned V_158 ,
bool V_145 ,
T_10 * V_155 ,
struct V_159 * V_160 )
{
struct V_149 * V_150 = F_129 ( V_154 ) ;
struct V_1 * V_2 = V_150 -> V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
const bool V_161 =
F_135 ( V_12 -> V_24 . V_162 ) & F_136 ( V_150 ) ;
F_137 ( V_163 ) ;
unsigned long V_164 ;
T_10 V_165 , V_166 ;
int V_19 ;
F_138 ( ! F_139 ( V_12 ) , L_2 ) ;
if ( F_140 ( & V_154 -> V_167 ) )
return 0 ;
if ( F_131 ( V_154 , true ) )
return 0 ;
V_164 = V_155 ?
V_157 + F_141 ( ( V_168 ) * V_155 ) : 0 ;
if ( F_142 ( V_12 ) -> V_169 >= 6 )
F_143 ( V_12 , V_160 , V_154 -> V_170 ) ;
F_144 ( V_154 ) ;
V_165 = F_145 () ;
V_19 = F_128 ( V_154 ) ;
if ( V_19 == 0 )
goto V_85;
if ( ! V_161 && F_14 ( ! V_150 -> V_171 ( V_150 ) ) ) {
V_19 = - V_172 ;
goto V_85;
}
for (; ; ) {
struct V_173 V_174 ;
F_146 ( & V_150 -> V_175 , & V_163 ,
V_145 ? V_176 : V_177 ) ;
if ( V_158 != F_147 ( & V_12 -> V_24 . V_158 ) ) {
V_19 = F_121 ( & V_12 -> V_24 , V_145 ) ;
if ( V_19 == 0 )
V_19 = - V_147 ;
break;
}
if ( F_131 ( V_154 , false ) ) {
V_19 = 0 ;
break;
}
if ( V_145 && F_148 ( V_178 ) ) {
V_19 = - V_179 ;
break;
}
if ( V_155 && F_132 ( V_157 , V_164 ) ) {
V_19 = - V_180 ;
break;
}
V_174 . V_181 = NULL ;
if ( V_155 || F_126 ( V_12 , V_150 ) ) {
unsigned long V_182 ;
F_149 ( & V_174 , F_124 , ( unsigned long ) V_178 ) ;
V_182 = F_126 ( V_12 , V_150 ) ? V_157 + 1 : V_164 ;
F_150 ( & V_174 , V_182 ) ;
}
F_151 () ;
if ( V_174 . V_181 ) {
F_152 ( & V_174 ) ;
F_153 ( & V_174 ) ;
}
}
if ( ! V_161 )
V_150 -> V_183 ( V_150 ) ;
F_154 ( & V_150 -> V_175 , & V_163 ) ;
V_85:
V_166 = F_145 () ;
F_155 ( V_154 ) ;
if ( V_155 ) {
T_10 V_184 = * V_155 - ( V_166 - V_165 ) ;
* V_155 = V_184 < 0 ? 0 : V_184 ;
if ( V_19 == - V_180 && * V_155 < F_156 ( 1 ) * 1000 )
* V_155 = 0 ;
}
return V_19 ;
}
int F_157 ( struct V_153 * V_154 ,
struct V_27 * V_28 )
{
struct V_11 * V_23 ;
struct V_185 * V_80 ;
F_14 ( ! V_154 || ! V_28 || V_154 -> V_80 ) ;
if ( ! V_154 || ! V_28 )
return - V_52 ;
if ( V_154 -> V_80 )
return - V_52 ;
V_23 = V_154 -> V_150 -> V_2 -> V_23 ;
V_80 = V_28 -> V_186 ;
F_5 ( & V_80 -> V_14 . V_187 ) ;
V_154 -> V_80 = V_80 ;
F_158 ( & V_154 -> V_188 , & V_80 -> V_14 . V_189 ) ;
F_6 ( & V_80 -> V_14 . V_187 ) ;
V_154 -> V_190 = F_159 ( F_160 ( V_178 ) ) ;
return 0 ;
}
static inline void
F_161 ( struct V_153 * V_191 )
{
struct V_185 * V_80 = V_191 -> V_80 ;
if ( ! V_80 )
return;
F_5 ( & V_80 -> V_14 . V_187 ) ;
F_162 ( & V_191 -> V_188 ) ;
V_191 -> V_80 = NULL ;
F_6 ( & V_80 -> V_14 . V_187 ) ;
F_163 ( V_191 -> V_190 ) ;
V_191 -> V_190 = NULL ;
}
static void F_164 ( struct V_153 * V_191 )
{
F_165 ( V_191 ) ;
V_191 -> V_192 -> V_193 = V_191 -> V_194 ;
F_166 ( & V_191 -> V_167 ) ;
F_161 ( V_191 ) ;
F_167 ( V_191 ) ;
}
static void
F_168 ( struct V_153 * V_154 )
{
struct V_149 * V_195 = V_154 -> V_150 ;
struct V_153 * V_196 ;
F_169 ( & V_195 -> V_2 -> V_25 ) ;
if ( F_140 ( & V_154 -> V_167 ) )
return;
do {
V_196 = F_170 ( & V_195 -> V_189 ,
F_171 ( * V_196 ) , V_167 ) ;
F_164 ( V_196 ) ;
} while ( V_196 != V_154 );
F_14 ( F_15 ( V_195 -> V_2 ) ) ;
}
int
F_172 ( struct V_153 * V_154 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
bool V_145 ;
int V_19 ;
F_37 ( V_154 == NULL ) ;
V_2 = V_154 -> V_150 -> V_2 ;
V_12 = V_2 -> V_23 ;
V_145 = V_12 -> V_14 . V_145 ;
F_37 ( ! F_173 ( & V_2 -> V_25 ) ) ;
V_19 = F_121 ( & V_12 -> V_24 , V_145 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_134 ( V_154 ,
F_147 ( & V_12 -> V_24 . V_158 ) ,
V_145 , NULL , NULL ) ;
if ( V_19 )
return V_19 ;
F_168 ( V_154 ) ;
return 0 ;
}
int
F_55 ( struct V_6 * V_7 ,
bool V_197 )
{
int V_19 , V_51 ;
if ( ! V_7 -> V_198 )
return 0 ;
if ( V_197 ) {
if ( V_7 -> V_199 != NULL ) {
V_19 = F_172 ( V_7 -> V_199 ) ;
if ( V_19 )
return V_19 ;
V_51 = V_7 -> V_199 -> V_150 -> V_151 ;
if ( V_7 -> V_200 [ V_51 ] == V_7 -> V_199 )
F_174 ( V_7 , V_51 ) ;
else
F_175 ( V_7 ) ;
}
} else {
for ( V_51 = 0 ; V_51 < V_201 ; V_51 ++ ) {
if ( V_7 -> V_200 [ V_51 ] == NULL )
continue;
V_19 = F_172 ( V_7 -> V_200 [ V_51 ] ) ;
if ( V_19 )
return V_19 ;
F_174 ( V_7 , V_51 ) ;
}
F_176 ( V_7 -> V_198 ) ;
}
return 0 ;
}
static void
F_177 ( struct V_6 * V_7 ,
struct V_153 * V_154 )
{
int V_150 = V_154 -> V_150 -> V_151 ;
if ( V_7 -> V_200 [ V_150 ] == V_154 )
F_174 ( V_7 , V_150 ) ;
else if ( V_7 -> V_199 == V_154 )
F_175 ( V_7 ) ;
F_168 ( V_154 ) ;
}
static T_11 int
F_178 ( struct V_6 * V_7 ,
struct V_159 * V_160 ,
bool V_197 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_153 * V_202 [ V_201 ] ;
unsigned V_158 ;
int V_19 , V_51 , V_203 = 0 ;
F_37 ( ! F_173 ( & V_2 -> V_25 ) ) ;
F_37 ( ! V_12 -> V_14 . V_145 ) ;
if ( ! V_7 -> V_198 )
return 0 ;
V_19 = F_121 ( & V_12 -> V_24 , true ) ;
if ( V_19 )
return V_19 ;
V_158 = F_147 ( & V_12 -> V_24 . V_158 ) ;
if ( V_197 ) {
struct V_153 * V_154 ;
V_154 = V_7 -> V_199 ;
if ( V_154 == NULL )
return 0 ;
V_202 [ V_203 ++ ] = F_179 ( V_154 ) ;
} else {
for ( V_51 = 0 ; V_51 < V_201 ; V_51 ++ ) {
struct V_153 * V_154 ;
V_154 = V_7 -> V_200 [ V_51 ] ;
if ( V_154 == NULL )
continue;
V_202 [ V_203 ++ ] = F_179 ( V_154 ) ;
}
}
F_19 ( & V_2 -> V_25 ) ;
for ( V_51 = 0 ; V_19 == 0 && V_51 < V_203 ; V_51 ++ )
V_19 = F_134 ( V_202 [ V_51 ] , V_158 , true ,
NULL , V_160 ) ;
F_17 ( & V_2 -> V_25 ) ;
for ( V_51 = 0 ; V_51 < V_203 ; V_51 ++ ) {
if ( V_19 == 0 )
F_177 ( V_7 , V_202 [ V_51 ] ) ;
F_167 ( V_202 [ V_51 ] ) ;
}
return V_19 ;
}
static struct V_159 * F_180 ( struct V_27 * V_28 )
{
struct V_185 * V_204 = V_28 -> V_186 ;
return & V_204 -> V_160 ;
}
int
F_181 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_205 * args = V_26 ;
struct V_6 * V_7 ;
T_5 V_65 = args -> V_65 ;
T_5 V_66 = args -> V_66 ;
int V_19 ;
if ( V_66 & V_206 )
return - V_52 ;
if ( V_65 & V_206 )
return - V_52 ;
if ( V_66 != 0 && V_65 != V_66 )
return - V_52 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_120 ;
goto V_121;
}
V_19 = F_178 ( V_7 ,
F_180 ( V_28 ) ,
! V_66 ) ;
if ( V_19 )
goto V_207;
if ( V_65 & V_208 )
V_19 = F_107 ( V_7 , V_66 != 0 ) ;
else
V_19 = F_38 ( V_7 , V_66 != 0 ) ;
if ( V_66 != 0 )
F_56 ( V_7 ,
V_66 == V_208 ?
V_130 : V_83 ) ;
V_207:
F_49 ( & V_7 -> V_8 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_182 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_209 * args = V_26 ;
struct V_6 * V_7 ;
int V_19 = 0 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_120 ;
goto V_121;
}
if ( V_7 -> V_10 )
F_183 ( V_7 ) ;
F_49 ( & V_7 -> V_8 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_184 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_210 * args = V_26 ;
struct V_211 * V_7 ;
unsigned long V_106 ;
if ( args -> V_212 & ~ ( V_213 ) )
return - V_52 ;
if ( args -> V_212 & V_213 && ! V_214 )
return - V_172 ;
V_7 = F_100 ( V_2 , V_28 , args -> V_88 ) ;
if ( V_7 == NULL )
return - V_120 ;
if ( ! V_7 -> V_43 ) {
F_68 ( V_7 ) ;
return - V_52 ;
}
V_106 = F_185 ( V_7 -> V_43 , 0 , args -> V_13 ,
V_215 | V_216 , V_217 ,
args -> V_59 ) ;
if ( args -> V_212 & V_213 ) {
struct V_218 * V_14 = V_178 -> V_14 ;
struct V_219 * V_34 ;
F_186 ( & V_14 -> V_220 ) ;
V_34 = F_187 ( V_14 , V_106 ) ;
if ( V_34 )
V_34 -> V_221 =
F_188 ( F_189 ( V_34 -> V_222 ) ) ;
else
V_106 = - V_57 ;
F_190 ( & V_14 -> V_220 ) ;
}
F_68 ( V_7 ) ;
if ( F_24 ( ( void * ) V_106 ) )
return V_106 ;
args -> V_223 = ( T_4 ) V_106 ;
return 0 ;
}
int F_191 ( struct V_219 * V_34 , struct V_224 * V_225 )
{
struct V_6 * V_7 = F_99 ( V_34 -> V_226 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_227 V_228 = V_229 ;
T_12 V_124 ;
unsigned long V_230 ;
int V_19 = 0 ;
bool V_231 = ! ! ( V_225 -> V_212 & V_232 ) ;
F_118 ( V_12 ) ;
V_124 = ( ( unsigned long ) V_225 -> V_233 - V_34 -> V_234 ) >>
V_235 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
goto V_85;
F_192 ( V_7 , V_124 , true , V_231 ) ;
V_19 = F_178 ( V_7 , NULL , ! V_231 ) ;
if ( V_19 )
goto V_121;
if ( V_7 -> V_9 != V_5 && ! F_2 ( V_2 ) ) {
V_19 = - V_76 ;
goto V_121;
}
if ( V_7 -> V_8 . V_13 >= V_12 -> V_32 . V_236 &&
V_7 -> V_142 == V_143 ) {
static const unsigned int V_237 = 256 ;
memset ( & V_228 , 0 , sizeof( V_228 ) ) ;
V_228 . type = V_238 ;
V_228 . V_239 . V_240 . V_59 = F_193 ( V_124 , V_237 ) ;
V_228 . V_239 . V_240 . V_13 =
F_194 (unsigned int,
chunk_size,
(vma->vm_end - vma->vm_start)/PAGE_SIZE -
view.params.partial.offset) ;
}
V_19 = F_195 ( V_7 , & V_228 , 0 , V_127 ) ;
if ( V_19 )
goto V_121;
V_19 = F_107 ( V_7 , V_231 ) ;
if ( V_19 )
goto V_241;
V_19 = F_196 ( V_7 ) ;
if ( V_19 )
goto V_241;
V_230 = V_12 -> V_32 . V_242 +
F_197 ( V_7 , & V_228 ) ;
V_230 >>= V_235 ;
if ( F_81 ( V_228 . type == V_238 ) ) {
unsigned long V_8 = V_34 -> V_234 +
( V_228 . V_239 . V_240 . V_59 << V_235 ) ;
unsigned int V_51 ;
for ( V_51 = 0 ; V_51 < V_228 . V_239 . V_240 . V_13 ; V_51 ++ ) {
V_19 = F_198 ( V_34 , V_8 + V_51 * V_53 , V_230 + V_51 ) ;
if ( V_19 )
break;
}
V_7 -> V_243 = true ;
} else {
if ( ! V_7 -> V_243 ) {
unsigned long V_13 = F_194 (unsigned long,
vma->vm_end - vma->vm_start,
obj->base.size) ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_13 > > V_235 ; V_51 ++ ) {
V_19 = F_198 ( V_34 ,
( unsigned long ) V_34 -> V_234 + V_51 * V_53 ,
V_230 + V_51 ) ;
if ( V_19 )
break;
}
V_7 -> V_243 = true ;
} else
V_19 = F_198 ( V_34 ,
( unsigned long ) V_225 -> V_233 ,
V_230 + V_124 ) ;
}
V_241:
F_199 ( V_7 , & V_228 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
V_85:
switch ( V_19 ) {
case - V_22 :
if ( ! F_123 ( & V_12 -> V_24 ) ) {
V_19 = V_244 ;
break;
}
case - V_147 :
case 0 :
case - V_179 :
case - V_245 :
case - V_75 :
V_19 = V_246 ;
break;
case - V_57 :
V_19 = V_247 ;
break;
case - V_144 :
case - V_76 :
V_19 = V_244 ;
break;
default:
F_200 ( V_19 , L_3 , V_19 ) ;
V_19 = V_244 ;
break;
}
F_120 ( V_12 ) ;
return V_19 ;
}
void
F_201 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_243 )
return;
F_202 ( & V_7 -> V_8 . V_248 ,
V_7 -> V_8 . V_2 -> V_249 -> V_44 ) ;
V_7 -> V_243 = false ;
}
void
F_203 ( struct V_11 * V_12 )
{
struct V_6 * V_7 ;
F_18 (obj, &dev_priv->mm.bound_list, global_list)
F_201 ( V_7 ) ;
}
T_5
F_204 ( struct V_1 * V_2 , T_5 V_13 , int V_142 )
{
T_5 V_250 ;
if ( F_142 ( V_2 ) -> V_169 >= 4 ||
V_142 == V_143 )
return V_13 ;
if ( F_142 ( V_2 ) -> V_169 == 3 )
V_250 = 1024 * 1024 ;
else
V_250 = 512 * 1024 ;
while ( V_250 < V_13 )
V_250 <<= 1 ;
return V_250 ;
}
T_5
F_205 ( struct V_1 * V_2 , T_5 V_13 ,
int V_142 , bool V_251 )
{
if ( F_142 ( V_2 ) -> V_169 >= 4 || ( ! V_251 && F_206 ( V_2 ) ) ||
V_142 == V_143 )
return 4096 ;
return F_204 ( V_2 , V_13 , V_142 ) ;
}
static int F_207 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
int V_19 ;
if ( F_208 ( & V_7 -> V_8 . V_248 ) )
return 0 ;
V_12 -> V_14 . V_252 = true ;
V_19 = F_209 ( & V_7 -> V_8 ) ;
if ( V_19 != - V_144 )
goto V_85;
F_210 ( V_12 ,
V_7 -> V_8 . V_13 >> V_235 ,
V_253 |
V_254 |
V_255 ) ;
V_19 = F_209 ( & V_7 -> V_8 ) ;
if ( V_19 != - V_144 )
goto V_85;
F_211 ( V_12 ) ;
V_19 = F_209 ( & V_7 -> V_8 ) ;
V_85:
V_12 -> V_14 . V_252 = false ;
return V_19 ;
}
static void F_212 ( struct V_6 * V_7 )
{
F_213 ( & V_7 -> V_8 ) ;
}
int
F_214 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
T_5 V_88 ,
T_4 * V_59 )
{
struct V_6 * V_7 ;
int V_19 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_99 ( F_100 ( V_2 , V_28 , V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_120 ;
goto V_121;
}
if ( V_7 -> V_63 != V_71 ) {
F_215 ( L_4 ) ;
V_19 = - V_76 ;
goto V_85;
}
V_19 = F_207 ( V_7 ) ;
if ( V_19 )
goto V_85;
* V_59 = F_216 ( & V_7 -> V_8 . V_248 ) ;
V_85:
F_49 ( & V_7 -> V_8 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_217 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_256 * args = V_26 ;
return F_214 ( V_28 , V_2 , args -> V_88 , & args -> V_59 ) ;
}
static void
F_218 ( struct V_6 * V_7 )
{
F_212 ( V_7 ) ;
if ( V_7 -> V_8 . V_43 == NULL )
return;
F_219 ( F_21 ( V_7 -> V_8 . V_43 ) , 0 , ( T_8 ) - 1 ) ;
V_7 -> V_63 = V_64 ;
}
static void
F_220 ( struct V_6 * V_7 )
{
struct V_41 * V_42 ;
switch ( V_7 -> V_63 ) {
case V_68 :
F_218 ( V_7 ) ;
case V_64 :
return;
}
if ( V_7 -> V_8 . V_43 == NULL )
return;
V_42 = F_21 ( V_7 -> V_8 . V_43 ) -> V_44 ,
F_221 ( V_42 , 0 , ( T_8 ) - 1 ) ;
}
static void
F_222 ( struct V_6 * V_7 )
{
struct V_114 V_115 ;
int V_19 ;
F_37 ( V_7 -> V_63 == V_64 ) ;
V_19 = F_38 ( V_7 , true ) ;
if ( V_19 ) {
F_14 ( V_19 != - V_22 ) ;
F_115 ( V_7 , true ) ;
V_7 -> V_8 . V_65 = V_7 -> V_8 . V_66 = V_67 ;
}
F_223 ( V_7 ) ;
if ( F_22 ( V_7 ) )
F_224 ( V_7 ) ;
if ( V_7 -> V_63 == V_68 )
V_7 -> V_69 = 0 ;
F_90 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_54 * V_54 = F_91 ( & V_115 ) ;
if ( V_7 -> V_69 )
F_39 ( V_54 ) ;
if ( V_7 -> V_63 == V_71 )
F_40 ( V_54 ) ;
F_29 ( V_54 ) ;
}
V_7 -> V_69 = 0 ;
F_41 ( V_7 -> V_62 ) ;
F_33 ( V_7 -> V_62 ) ;
}
int
F_48 ( struct V_6 * V_7 )
{
const struct V_257 * V_77 = V_7 -> V_77 ;
if ( V_7 -> V_62 == NULL )
return 0 ;
if ( V_7 -> V_258 )
return - V_75 ;
F_37 ( F_225 ( V_7 ) ) ;
F_162 ( & V_7 -> V_259 ) ;
V_77 -> V_260 ( V_7 ) ;
V_7 -> V_62 = NULL ;
F_220 ( V_7 ) ;
return 0 ;
}
static int
F_226 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
int V_261 , V_51 ;
struct V_41 * V_42 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_114 V_115 ;
struct V_54 * V_54 ;
unsigned long V_262 = 0 ;
int V_19 ;
T_13 V_263 ;
F_37 ( V_7 -> V_8 . V_65 & V_206 ) ;
F_37 ( V_7 -> V_8 . V_66 & V_206 ) ;
V_48 = F_31 ( sizeof( * V_48 ) , V_56 ) ;
if ( V_48 == NULL )
return - V_57 ;
V_261 = V_7 -> V_8 . V_13 / V_53 ;
if ( F_32 ( V_48 , V_261 , V_56 ) ) {
F_33 ( V_48 ) ;
return - V_57 ;
}
V_42 = F_21 ( V_7 -> V_8 . V_43 ) -> V_44 ;
V_263 = F_227 ( V_42 ) ;
V_263 |= V_264 | V_265 | V_266 ;
V_263 &= ~ ( V_267 | V_268 ) ;
V_50 = V_48 -> V_58 ;
V_48 -> V_269 = 0 ;
for ( V_51 = 0 ; V_51 < V_261 ; V_51 ++ ) {
V_54 = F_228 ( V_42 , V_51 , V_263 ) ;
if ( F_24 ( V_54 ) ) {
F_210 ( V_12 ,
V_261 ,
V_253 |
V_254 |
V_255 ) ;
V_54 = F_228 ( V_42 , V_51 , V_263 ) ;
}
if ( F_24 ( V_54 ) ) {
F_211 ( V_12 ) ;
V_54 = F_23 ( V_42 , V_51 ) ;
if ( F_24 ( V_54 ) ) {
V_19 = F_25 ( V_54 ) ;
goto V_270;
}
}
#ifdef F_229
if ( F_230 () ) {
V_48 -> V_269 ++ ;
F_231 ( V_50 , V_54 , V_53 , 0 ) ;
V_50 = F_232 ( V_50 ) ;
continue;
}
#endif
if ( ! V_51 || F_233 ( V_54 ) != V_262 + 1 ) {
if ( V_51 )
V_50 = F_232 ( V_50 ) ;
V_48 -> V_269 ++ ;
F_231 ( V_50 , V_54 , V_53 , 0 ) ;
} else {
V_50 -> V_60 += V_53 ;
}
V_262 = F_233 ( V_54 ) ;
F_14 ( ( V_263 & V_271 ) && ( V_262 >= 0x00100000UL ) ) ;
}
#ifdef F_229
if ( ! F_230 () )
#endif
F_234 ( V_50 ) ;
V_7 -> V_62 = V_48 ;
V_19 = F_235 ( V_7 ) ;
if ( V_19 )
goto V_270;
if ( F_22 ( V_7 ) )
F_236 ( V_7 ) ;
if ( V_7 -> V_142 != V_143 &&
V_12 -> V_272 & V_273 )
F_79 ( V_7 ) ;
return 0 ;
V_270:
F_234 ( V_50 ) ;
F_90 (st->sgl, &sg_iter, st->nents, 0 )
F_29 ( F_91 ( & V_115 ) ) ;
F_41 ( V_48 ) ;
F_33 ( V_48 ) ;
if ( V_19 == - V_144 )
V_19 = - V_57 ;
return V_19 ;
}
int
F_52 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
const struct V_257 * V_77 = V_7 -> V_77 ;
int V_19 ;
if ( V_7 -> V_62 )
return 0 ;
if ( V_7 -> V_63 != V_71 ) {
F_215 ( L_5 ) ;
return - V_76 ;
}
F_37 ( V_7 -> V_258 ) ;
V_19 = V_77 -> V_274 ( V_7 ) ;
if ( V_19 )
return V_19 ;
F_158 ( & V_7 -> V_259 , & V_12 -> V_14 . V_275 ) ;
V_7 -> V_276 . V_50 = V_7 -> V_62 -> V_58 ;
V_7 -> V_276 . V_277 = 0 ;
return 0 ;
}
void F_237 ( struct V_33 * V_34 ,
struct V_153 * V_154 )
{
struct V_6 * V_7 = V_34 -> V_7 ;
struct V_149 * V_150 ;
V_150 = F_129 ( V_154 ) ;
if ( V_7 -> V_198 == 0 )
F_45 ( & V_7 -> V_8 ) ;
V_7 -> V_198 |= F_136 ( V_150 ) ;
F_238 ( & V_7 -> V_278 [ V_150 -> V_151 ] , & V_150 -> V_279 ) ;
F_239 ( & V_7 -> V_200 [ V_150 -> V_151 ] , V_154 ) ;
F_238 ( & V_34 -> V_280 , & V_34 -> V_281 -> V_279 ) ;
}
static void
F_175 ( struct V_6 * V_7 )
{
F_176 ( V_7 -> V_199 == NULL ) ;
F_176 ( ! ( V_7 -> V_198 & F_136 ( V_7 -> V_199 -> V_150 ) ) ) ;
F_239 ( & V_7 -> V_199 , NULL ) ;
F_59 ( V_7 , true , V_282 ) ;
}
static void
F_174 ( struct V_6 * V_7 , int V_150 )
{
struct V_33 * V_34 ;
F_176 ( V_7 -> V_200 [ V_150 ] == NULL ) ;
F_176 ( ! ( V_7 -> V_198 & ( 1 << V_150 ) ) ) ;
F_166 ( & V_7 -> V_278 [ V_150 ] ) ;
F_239 ( & V_7 -> V_200 [ V_150 ] , NULL ) ;
if ( V_7 -> V_199 && V_7 -> V_199 -> V_150 -> V_151 == V_150 )
F_175 ( V_7 ) ;
V_7 -> V_198 &= ~ ( 1 << V_150 ) ;
if ( V_7 -> V_198 )
return;
F_238 ( & V_7 -> V_259 ,
& F_240 ( V_7 -> V_8 . V_2 ) -> V_14 . V_283 ) ;
F_18 (vma, &obj->vma_list, vma_link) {
if ( ! F_140 ( & V_34 -> V_280 ) )
F_238 ( & V_34 -> V_280 , & V_34 -> V_281 -> V_284 ) ;
}
F_239 ( & V_7 -> V_285 , NULL ) ;
F_49 ( & V_7 -> V_8 ) ;
}
static int
F_241 ( struct V_1 * V_2 , T_6 V_286 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_149 * V_150 ;
int V_19 , V_51 , V_287 ;
F_242 (ring, dev_priv, i) {
V_19 = F_243 ( V_150 ) ;
if ( V_19 )
return V_19 ;
}
F_244 ( V_2 ) ;
F_242 (ring, dev_priv, i) {
F_245 ( V_150 , V_286 ) ;
for ( V_287 = 0 ; V_287 < F_246 ( V_150 -> V_288 . V_289 ) ; V_287 ++ )
V_150 -> V_288 . V_289 [ V_287 ] = 0 ;
}
return 0 ;
}
int F_247 ( struct V_1 * V_2 , T_6 V_286 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 ;
if ( V_286 == 0 )
return - V_52 ;
V_19 = F_241 ( V_2 , V_286 - 1 ) ;
if ( V_19 )
return V_19 ;
V_12 -> V_290 = V_286 ;
V_12 -> V_291 = V_286 - 1 ;
if ( V_12 -> V_291 == 0 )
V_12 -> V_291 -- ;
return 0 ;
}
int
F_248 ( struct V_1 * V_2 , T_6 * V_286 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
if ( V_12 -> V_290 == 0 ) {
int V_19 = F_241 ( V_2 , 0 ) ;
if ( V_19 )
return V_19 ;
V_12 -> V_290 = 1 ;
}
* V_286 = V_12 -> V_291 = V_12 -> V_290 ++ ;
return 0 ;
}
void F_249 ( struct V_153 * V_191 ,
struct V_6 * V_7 ,
bool V_292 )
{
struct V_149 * V_150 ;
struct V_11 * V_12 ;
struct V_293 * V_192 ;
T_6 V_294 ;
int V_19 ;
if ( F_14 ( V_191 == NULL ) )
return;
V_150 = V_191 -> V_150 ;
V_12 = V_150 -> V_2 -> V_23 ;
V_192 = V_191 -> V_192 ;
F_250 ( V_192 ) ;
V_294 = F_251 ( V_192 ) ;
if ( V_292 ) {
if ( V_117 . V_295 )
V_19 = F_252 ( V_191 ) ;
else
V_19 = F_253 ( V_191 ) ;
F_138 ( V_19 , L_6 , V_19 ) ;
}
V_191 -> V_194 = F_251 ( V_192 ) ;
if ( V_117 . V_295 )
V_19 = V_150 -> V_296 ( V_191 ) ;
else {
V_19 = V_150 -> V_297 ( V_191 ) ;
V_191 -> V_298 = F_251 ( V_192 ) ;
}
F_138 ( V_19 , L_7 , V_19 ) ;
V_191 -> V_299 = V_294 ;
V_191 -> V_300 = V_7 ;
V_191 -> V_170 = V_157 ;
V_150 -> V_301 = V_191 -> V_286 ;
F_158 ( & V_191 -> V_167 , & V_150 -> V_189 ) ;
F_254 ( V_191 ) ;
F_255 ( V_150 -> V_2 ) ;
F_256 ( V_12 -> V_302 ,
& V_12 -> V_14 . V_303 ,
F_257 ( V_21 ) ) ;
F_258 ( V_12 -> V_2 ) ;
F_259 ( V_192 ) ;
}
static bool F_260 ( struct V_11 * V_12 ,
const struct V_304 * V_305 )
{
unsigned long V_306 ;
V_306 = F_261 () - V_305 -> V_307 . V_308 ;
if ( V_305 -> V_307 . V_309 )
return true ;
if ( V_305 -> V_307 . V_310 &&
V_306 <= V_305 -> V_307 . V_310 ) {
if ( ! F_262 ( V_305 ) ) {
F_215 ( L_8 ) ;
return true ;
} else if ( F_263 ( V_12 ) ) {
if ( F_264 ( V_12 ) )
F_11 ( L_9 ) ;
return true ;
}
}
return false ;
}
static void F_265 ( struct V_11 * V_12 ,
struct V_304 * V_305 ,
const bool V_311 )
{
struct V_312 * V_313 ;
if ( F_14 ( ! V_305 ) )
return;
V_313 = & V_305 -> V_307 ;
if ( V_311 ) {
V_313 -> V_309 = F_260 ( V_12 , V_305 ) ;
V_313 -> V_314 ++ ;
V_313 -> V_308 = F_261 () ;
} else {
V_313 -> V_315 ++ ;
}
}
void F_266 ( struct V_316 * V_317 )
{
struct V_153 * V_154 = F_267 ( V_317 ,
F_171 ( * V_154 ) , V_318 ) ;
struct V_304 * V_305 = V_154 -> V_305 ;
if ( V_154 -> V_80 )
F_161 ( V_154 ) ;
if ( V_305 ) {
if ( V_117 . V_295 ) {
if ( V_305 != V_154 -> V_150 -> V_319 )
F_268 ( V_154 ) ;
}
F_269 ( V_305 ) ;
}
F_63 ( V_154 -> V_117 -> V_202 , V_154 ) ;
}
int F_270 ( struct V_149 * V_150 ,
struct V_304 * V_305 ,
struct V_153 * * V_320 )
{
struct V_11 * V_12 = F_240 ( V_150 -> V_2 ) ;
struct V_153 * V_154 ;
int V_19 ;
if ( ! V_320 )
return - V_52 ;
* V_320 = NULL ;
V_154 = F_61 ( V_12 -> V_202 , V_56 ) ;
if ( V_154 == NULL )
return - V_57 ;
V_19 = F_248 ( V_150 -> V_2 , & V_154 -> V_286 ) ;
if ( V_19 )
goto V_321;
F_271 ( & V_154 -> V_318 ) ;
V_154 -> V_117 = V_12 ;
V_154 -> V_150 = V_150 ;
V_154 -> V_305 = V_305 ;
F_272 ( V_154 -> V_305 ) ;
if ( V_117 . V_295 )
V_19 = F_273 ( V_154 ) ;
else
V_19 = F_274 ( V_154 ) ;
if ( V_19 ) {
F_269 ( V_154 -> V_305 ) ;
goto V_321;
}
if ( V_117 . V_295 )
V_19 = F_275 ( V_154 ) ;
else
V_19 = F_276 ( V_154 ) ;
if ( V_19 ) {
F_277 ( V_154 ) ;
return V_19 ;
}
* V_320 = V_154 ;
return 0 ;
V_321:
F_63 ( V_12 -> V_202 , V_154 ) ;
return V_19 ;
}
void F_277 ( struct V_153 * V_154 )
{
F_278 ( V_154 -> V_192 ) ;
F_167 ( V_154 ) ;
}
struct V_153 *
F_279 ( struct V_149 * V_150 )
{
struct V_153 * V_191 ;
F_18 (request, &ring->request_list, list) {
if ( F_131 ( V_191 , false ) )
continue;
return V_191 ;
}
return NULL ;
}
static void F_280 ( struct V_11 * V_12 ,
struct V_149 * V_150 )
{
struct V_153 * V_191 ;
bool V_322 ;
V_191 = F_279 ( V_150 ) ;
if ( V_191 == NULL )
return;
V_322 = V_150 -> V_323 . V_324 >= V_325 ;
F_265 ( V_12 , V_191 -> V_305 , V_322 ) ;
F_281 (request, &ring->request_list, list)
F_265 ( V_12 , V_191 -> V_305 , false ) ;
}
static void F_282 ( struct V_11 * V_12 ,
struct V_149 * V_150 )
{
while ( ! F_140 ( & V_150 -> V_279 ) ) {
struct V_6 * V_7 ;
V_7 = F_170 ( & V_150 -> V_279 ,
struct V_6 ,
V_278 [ V_150 -> V_151 ] ) ;
F_174 ( V_7 , V_150 -> V_151 ) ;
}
while ( ! F_140 ( & V_150 -> V_326 ) ) {
struct V_153 * V_327 ;
V_327 = F_170 ( & V_150 -> V_326 ,
struct V_153 ,
V_328 ) ;
F_162 ( & V_327 -> V_328 ) ;
if ( V_327 -> V_305 != V_150 -> V_319 )
F_268 ( V_327 ) ;
F_167 ( V_327 ) ;
}
while ( ! F_140 ( & V_150 -> V_189 ) ) {
struct V_153 * V_191 ;
V_191 = F_170 ( & V_150 -> V_189 ,
struct V_153 ,
V_167 ) ;
F_164 ( V_191 ) ;
}
}
void F_283 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_149 * V_150 ;
int V_51 ;
F_242 (ring, dev_priv, i)
F_280 ( V_12 , V_150 ) ;
F_242 (ring, dev_priv, i)
F_282 ( V_12 , V_150 ) ;
F_284 ( V_2 ) ;
F_285 ( V_2 ) ;
F_14 ( F_15 ( V_2 ) ) ;
}
void
F_286 ( struct V_149 * V_150 )
{
F_14 ( F_15 ( V_150 -> V_2 ) ) ;
while ( ! F_140 ( & V_150 -> V_189 ) ) {
struct V_153 * V_191 ;
V_191 = F_170 ( & V_150 -> V_189 ,
struct V_153 ,
V_167 ) ;
if ( ! F_131 ( V_191 , true ) )
break;
F_164 ( V_191 ) ;
}
while ( ! F_140 ( & V_150 -> V_279 ) ) {
struct V_6 * V_7 ;
V_7 = F_170 ( & V_150 -> V_279 ,
struct V_6 ,
V_278 [ V_150 -> V_151 ] ) ;
if ( ! F_140 ( & V_7 -> V_200 [ V_150 -> V_151 ] -> V_167 ) )
break;
F_174 ( V_7 , V_150 -> V_151 ) ;
}
if ( F_81 ( V_150 -> V_329 &&
F_131 ( V_150 -> V_329 , true ) ) ) {
V_150 -> V_183 ( V_150 ) ;
F_239 ( & V_150 -> V_329 , NULL ) ;
}
F_14 ( F_15 ( V_150 -> V_2 ) ) ;
}
bool
F_244 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_149 * V_150 ;
bool V_330 = true ;
int V_51 ;
F_242 (ring, dev_priv, i) {
F_286 ( V_150 ) ;
V_330 &= F_140 ( & V_150 -> V_189 ) ;
if ( V_117 . V_295 ) {
unsigned long V_212 ;
F_287 ( & V_150 -> V_331 , V_212 ) ;
V_330 &= F_140 ( & V_150 -> V_326 ) ;
F_288 ( & V_150 -> V_331 , V_212 ) ;
F_289 ( V_150 ) ;
}
}
if ( V_330 )
F_290 ( V_12 -> V_302 ,
& V_12 -> V_14 . V_332 ,
F_291 ( 100 ) ) ;
return V_330 ;
}
static void
F_292 ( struct V_333 * V_334 )
{
struct V_11 * V_12 =
F_267 ( V_334 , F_171 ( * V_12 ) , V_14 . V_303 . V_334 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
bool V_330 ;
V_330 = false ;
if ( F_293 ( & V_2 -> V_25 ) ) {
V_330 = F_244 ( V_2 ) ;
F_19 ( & V_2 -> V_25 ) ;
}
if ( ! V_330 )
F_256 ( V_12 -> V_302 , & V_12 -> V_14 . V_303 ,
F_257 ( V_21 ) ) ;
}
static void
F_294 ( struct V_333 * V_334 )
{
struct V_11 * V_12 =
F_267 ( V_334 , F_171 ( * V_12 ) , V_14 . V_332 . V_334 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_149 * V_150 ;
int V_51 ;
F_242 (ring, dev_priv, i)
if ( ! F_140 ( & V_150 -> V_189 ) )
return;
F_295 ( V_2 ) ;
if ( F_293 ( & V_2 -> V_25 ) ) {
struct V_149 * V_150 ;
int V_51 ;
F_242 (ring, dev_priv, i)
F_296 ( & V_150 -> V_335 ) ;
F_19 ( & V_2 -> V_25 ) ;
}
}
static int
F_297 ( struct V_6 * V_7 )
{
int V_51 ;
if ( ! V_7 -> V_198 )
return 0 ;
for ( V_51 = 0 ; V_51 < V_201 ; V_51 ++ ) {
struct V_153 * V_154 ;
V_154 = V_7 -> V_200 [ V_51 ] ;
if ( V_154 == NULL )
continue;
if ( F_140 ( & V_154 -> V_167 ) )
goto V_336;
if ( F_131 ( V_154 , true ) ) {
F_168 ( V_154 ) ;
V_336:
F_174 ( V_7 , V_51 ) ;
}
}
return 0 ;
}
int
F_298 ( struct V_1 * V_2 , void * V_26 , struct V_27 * V_28 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_337 * args = V_26 ;
struct V_6 * V_7 ;
struct V_153 * V_154 [ V_201 ] ;
unsigned V_158 ;
int V_51 , V_203 = 0 ;
int V_19 ;
if ( args -> V_212 != 0 )
return - V_52 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_338 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_19 ( & V_2 -> V_25 ) ;
return - V_120 ;
}
V_19 = F_297 ( V_7 ) ;
if ( V_19 )
goto V_85;
if ( ! V_7 -> V_198 )
goto V_85;
if ( args -> V_339 == 0 ) {
V_19 = - V_180 ;
goto V_85;
}
F_49 ( & V_7 -> V_8 ) ;
V_158 = F_147 ( & V_12 -> V_24 . V_158 ) ;
for ( V_51 = 0 ; V_51 < V_201 ; V_51 ++ ) {
if ( V_7 -> V_200 [ V_51 ] == NULL )
continue;
V_154 [ V_203 ++ ] = F_179 ( V_7 -> V_200 [ V_51 ] ) ;
}
F_19 ( & V_2 -> V_25 ) ;
for ( V_51 = 0 ; V_51 < V_203 ; V_51 ++ ) {
if ( V_19 == 0 )
V_19 = F_134 ( V_154 [ V_51 ] , V_158 , true ,
args -> V_339 > 0 ? & args -> V_339 : NULL ,
V_28 -> V_186 ) ;
F_299 ( V_154 [ V_51 ] ) ;
}
return V_19 ;
V_85:
F_49 ( & V_7 -> V_8 ) ;
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
static int
F_300 ( struct V_6 * V_7 ,
struct V_149 * V_340 ,
struct V_153 * V_341 ,
struct V_153 * * V_342 )
{
struct V_149 * V_343 ;
int V_19 ;
V_343 = F_129 ( V_341 ) ;
if ( V_340 == V_343 )
return 0 ;
if ( F_131 ( V_341 , true ) )
return 0 ;
if ( ! F_301 ( V_7 -> V_8 . V_2 ) ) {
struct V_11 * V_117 = F_240 ( V_7 -> V_8 . V_2 ) ;
V_19 = F_134 ( V_341 ,
F_147 ( & V_117 -> V_24 . V_158 ) ,
V_117 -> V_14 . V_145 ,
NULL ,
& V_117 -> V_160 . V_344 ) ;
if ( V_19 )
return V_19 ;
F_177 ( V_7 , V_341 ) ;
} else {
int V_345 = F_302 ( V_343 , V_340 ) ;
T_6 V_286 = F_303 ( V_341 ) ;
F_14 ( ! V_342 ) ;
if ( V_286 <= V_343 -> V_288 . V_289 [ V_345 ] )
return 0 ;
if ( * V_342 == NULL ) {
V_19 = F_270 ( V_340 , V_340 -> V_319 , V_342 ) ;
if ( V_19 )
return V_19 ;
}
F_304 ( * V_342 , V_343 , V_341 ) ;
V_19 = V_340 -> V_288 . V_346 ( * V_342 , V_343 , V_286 ) ;
if ( V_19 )
return V_19 ;
V_343 -> V_288 . V_289 [ V_345 ] =
F_303 ( V_7 -> V_200 [ V_343 -> V_151 ] ) ;
}
return 0 ;
}
int
F_305 ( struct V_6 * V_7 ,
struct V_149 * V_340 ,
struct V_153 * * V_342 )
{
const bool V_197 = V_7 -> V_8 . V_347 == 0 ;
struct V_153 * V_154 [ V_201 ] ;
int V_19 , V_51 , V_203 ;
if ( ! V_7 -> V_198 )
return 0 ;
if ( V_340 == NULL )
return F_55 ( V_7 , V_197 ) ;
V_203 = 0 ;
if ( V_197 ) {
if ( V_7 -> V_199 )
V_154 [ V_203 ++ ] = V_7 -> V_199 ;
} else {
for ( V_51 = 0 ; V_51 < V_201 ; V_51 ++ )
if ( V_7 -> V_200 [ V_51 ] )
V_154 [ V_203 ++ ] = V_7 -> V_200 [ V_51 ] ;
}
for ( V_51 = 0 ; V_51 < V_203 ; V_51 ++ ) {
V_19 = F_300 ( V_7 , V_340 , V_154 [ V_51 ] , V_342 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static void F_306 ( struct V_6 * V_7 )
{
T_6 V_348 , V_349 ;
F_201 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_65 & V_208 ) == 0 )
return;
F_307 () ;
V_349 = V_7 -> V_8 . V_65 ;
V_348 = V_7 -> V_8 . V_66 ;
V_7 -> V_8 . V_65 &= ~ V_208 ;
V_7 -> V_8 . V_66 &= ~ V_208 ;
F_308 ( V_7 ,
V_349 ,
V_348 ) ;
}
int F_47 ( struct V_33 * V_34 )
{
struct V_6 * V_7 = V_34 -> V_7 ;
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
int V_19 ;
if ( F_140 ( & V_34 -> V_350 ) )
return 0 ;
if ( ! F_309 ( & V_34 -> V_37 ) ) {
F_310 ( V_34 ) ;
return 0 ;
}
if ( V_34 -> V_36 )
return - V_75 ;
F_37 ( V_7 -> V_62 == NULL ) ;
V_19 = F_55 ( V_7 , false ) ;
if ( V_19 )
return V_19 ;
if ( F_311 ( V_34 -> V_281 ) &&
V_34 -> V_351 . type == V_352 ) {
F_306 ( V_7 ) ;
V_19 = F_108 ( V_7 ) ;
if ( V_19 )
return V_19 ;
}
F_312 ( V_34 ) ;
V_34 -> V_281 -> V_353 ( V_34 ) ;
V_34 -> V_354 = 0 ;
F_166 ( & V_34 -> V_280 ) ;
if ( F_311 ( V_34 -> V_281 ) ) {
if ( V_34 -> V_351 . type == V_352 ) {
V_7 -> V_355 = false ;
} else if ( V_34 -> V_351 . V_62 ) {
F_41 ( V_34 -> V_351 . V_62 ) ;
F_33 ( V_34 -> V_351 . V_62 ) ;
}
V_34 -> V_351 . V_62 = NULL ;
}
F_313 ( & V_34 -> V_37 ) ;
F_310 ( V_34 ) ;
if ( F_140 ( & V_7 -> V_356 ) )
F_238 ( & V_7 -> V_259 , & V_12 -> V_14 . V_275 ) ;
F_96 ( V_7 ) ;
return 0 ;
}
int F_314 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_149 * V_150 ;
int V_19 , V_51 ;
F_242 (ring, dev_priv, i) {
if ( ! V_117 . V_295 ) {
struct V_153 * V_154 ;
V_19 = F_270 ( V_150 , V_150 -> V_319 , & V_154 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_315 ( V_154 ) ;
if ( V_19 ) {
F_277 ( V_154 ) ;
return V_19 ;
}
F_316 ( V_154 ) ;
}
V_19 = F_243 ( V_150 ) ;
if ( V_19 )
return V_19 ;
}
F_14 ( F_15 ( V_2 ) ) ;
return 0 ;
}
static bool F_317 ( struct V_33 * V_34 ,
unsigned long V_9 )
{
struct V_357 * V_358 = & V_34 -> V_37 ;
struct V_357 * V_359 ;
if ( V_34 -> V_281 -> V_14 . V_360 == NULL )
return true ;
if ( ! F_309 ( V_358 ) )
return true ;
if ( F_140 ( & V_358 -> V_361 ) )
return true ;
V_359 = F_318 ( V_358 -> V_361 . V_362 , struct V_357 , V_361 ) ;
if ( V_359 -> V_363 && ! V_359 -> V_364 && V_359 -> V_365 != V_9 )
return false ;
V_359 = F_318 ( V_358 -> V_361 . V_72 , struct V_357 , V_361 ) ;
if ( V_359 -> V_363 && ! V_358 -> V_364 && V_359 -> V_365 != V_9 )
return false ;
return true ;
}
static struct V_33 *
F_319 ( struct V_6 * V_7 ,
struct V_366 * V_281 ,
const struct V_227 * V_351 ,
unsigned V_367 ,
T_4 V_212 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
T_6 V_13 , V_368 , V_369 , V_370 ;
V_168 V_108 =
V_212 & V_371 ? V_212 & V_372 : 0 ;
V_168 V_109 =
V_212 & V_127 ? V_12 -> V_32 . V_236 : V_281 -> V_39 ;
struct V_33 * V_34 ;
int V_19 ;
if ( F_311 ( V_281 ) ) {
T_6 V_373 ;
if ( F_14 ( ! V_351 ) )
return F_320 ( - V_52 ) ;
V_373 = F_321 ( V_7 , V_351 ) ;
V_368 = F_204 ( V_2 ,
V_373 ,
V_7 -> V_142 ) ;
V_369 = F_205 ( V_2 ,
V_373 ,
V_7 -> V_142 ,
true ) ;
V_370 = F_205 ( V_2 ,
V_373 ,
V_7 -> V_142 ,
false ) ;
V_13 = V_212 & V_127 ? V_368 : V_373 ;
} else {
V_368 = F_204 ( V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_142 ) ;
V_369 = F_205 ( V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_142 ,
true ) ;
V_370 =
F_205 ( V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_142 ,
false ) ;
V_13 = V_212 & V_127 ? V_368 : V_7 -> V_8 . V_13 ;
}
if ( V_367 == 0 )
V_367 = V_212 & V_127 ? V_369 :
V_370 ;
if ( V_212 & V_127 && V_367 & ( V_369 - 1 ) ) {
F_215 ( L_10 ,
V_351 ? V_351 -> type : 0 ,
V_367 ) ;
return F_320 ( - V_52 ) ;
}
if ( V_13 > V_109 ) {
F_215 ( L_11 ,
V_351 ? V_351 -> type : 0 ,
V_13 ,
V_212 & V_127 ? L_12 : L_13 ,
V_109 ) ;
return F_320 ( - V_374 ) ;
}
V_19 = F_52 ( V_7 ) ;
if ( V_19 )
return F_320 ( V_19 ) ;
F_79 ( V_7 ) ;
V_34 = V_351 ? F_322 ( V_7 , V_351 ) :
F_323 ( V_7 , V_281 ) ;
if ( F_24 ( V_34 ) )
goto V_375;
V_376:
V_19 = F_324 ( & V_281 -> V_14 , & V_34 -> V_37 ,
V_13 , V_367 ,
V_7 -> V_9 ,
V_108 , V_109 ,
V_377 ,
V_378 ) ;
if ( V_19 ) {
V_19 = F_325 ( V_2 , V_281 , V_13 , V_367 ,
V_7 -> V_9 ,
V_108 , V_109 ,
V_212 ) ;
if ( V_19 == 0 )
goto V_376;
goto V_379;
}
if ( F_14 ( ! F_317 ( V_34 , V_7 -> V_9 ) ) ) {
V_19 = - V_52 ;
goto V_380;
}
F_326 ( V_34 , V_212 ) ;
V_19 = F_327 ( V_34 , V_7 -> V_9 , V_212 ) ;
if ( V_19 )
goto V_380;
F_238 ( & V_7 -> V_259 , & V_12 -> V_14 . V_283 ) ;
F_158 ( & V_34 -> V_280 , & V_281 -> V_284 ) ;
return V_34 ;
V_380:
F_313 ( & V_34 -> V_37 ) ;
V_379:
F_310 ( V_34 ) ;
V_34 = F_320 ( V_19 ) ;
V_375:
F_96 ( V_7 ) ;
return V_34 ;
}
bool
F_115 ( struct V_6 * V_7 ,
bool V_381 )
{
if ( V_7 -> V_62 == NULL )
return false ;
if ( V_7 -> V_382 || V_7 -> V_46 )
return false ;
if ( ! V_381 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) ) {
V_7 -> V_383 = true ;
return false ;
}
F_328 ( V_7 ) ;
F_329 ( V_7 -> V_62 ) ;
V_7 -> V_383 = false ;
return true ;
}
static void
F_330 ( struct V_6 * V_7 )
{
T_5 V_348 ;
if ( V_7 -> V_8 . V_66 != V_208 )
return;
F_331 () ;
V_348 = V_7 -> V_8 . V_66 ;
V_7 -> V_8 . V_66 = 0 ;
F_59 ( V_7 , false , V_130 ) ;
F_308 ( V_7 ,
V_7 -> V_8 . V_65 ,
V_348 ) ;
}
static void
F_183 ( struct V_6 * V_7 )
{
T_5 V_348 ;
if ( V_7 -> V_8 . V_66 != V_67 )
return;
if ( F_115 ( V_7 , V_7 -> V_10 ) )
F_30 ( V_7 -> V_8 . V_2 ) ;
V_348 = V_7 -> V_8 . V_66 ;
V_7 -> V_8 . V_66 = 0 ;
F_59 ( V_7 , false , V_83 ) ;
F_308 ( V_7 ,
V_7 -> V_8 . V_65 ,
V_348 ) ;
}
int
F_107 ( struct V_6 * V_7 , bool V_231 )
{
T_5 V_348 , V_349 ;
struct V_33 * V_34 ;
int V_19 ;
if ( V_7 -> V_8 . V_66 == V_208 )
return 0 ;
V_19 = F_55 ( V_7 , ! V_231 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_52 ( V_7 ) ;
if ( V_19 )
return V_19 ;
F_183 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_65 & V_208 ) == 0 )
F_307 () ;
V_348 = V_7 -> V_8 . V_66 ;
V_349 = V_7 -> V_8 . V_65 ;
F_37 ( ( V_7 -> V_8 . V_66 & ~ V_208 ) != 0 ) ;
V_7 -> V_8 . V_65 |= V_208 ;
if ( V_231 ) {
V_7 -> V_8 . V_65 = V_208 ;
V_7 -> V_8 . V_66 = V_208 ;
V_7 -> V_69 = 1 ;
}
F_308 ( V_7 ,
V_349 ,
V_348 ) ;
V_34 = F_332 ( V_7 ) ;
if ( V_34 && F_309 ( & V_34 -> V_37 ) && ! V_7 -> V_198 )
F_238 ( & V_34 -> V_280 ,
& F_240 ( V_7 -> V_8 . V_2 ) -> V_32 . V_8 . V_284 ) ;
return 0 ;
}
int F_333 ( struct V_6 * V_7 ,
enum V_3 V_9 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_33 * V_34 , * V_72 ;
int V_19 ;
if ( V_7 -> V_9 == V_9 )
return 0 ;
if ( F_334 ( V_7 ) ) {
F_215 ( L_14 ) ;
return - V_75 ;
}
F_46 (vma, next, &obj->vma_list, vma_link) {
if ( ! F_317 ( V_34 , V_9 ) ) {
V_19 = F_47 ( V_34 ) ;
if ( V_19 )
return V_19 ;
}
}
if ( F_225 ( V_7 ) ) {
V_19 = F_55 ( V_7 , false ) ;
if ( V_19 )
return V_19 ;
F_306 ( V_7 ) ;
if ( F_142 ( V_2 ) -> V_169 < 6 ) {
V_19 = F_108 ( V_7 ) ;
if ( V_19 )
return V_19 ;
}
F_18 (vma, &obj->vma_list, vma_link)
if ( F_309 ( & V_34 -> V_37 ) ) {
V_19 = F_327 ( V_34 , V_9 ,
V_384 ) ;
if ( V_19 )
return V_19 ;
}
}
F_18 (vma, &obj->vma_list, vma_link)
V_34 -> V_37 . V_365 = V_9 ;
V_7 -> V_9 = V_9 ;
if ( V_7 -> V_383 &&
V_7 -> V_8 . V_66 != V_67 &&
F_3 ( V_7 ) ) {
if ( F_115 ( V_7 , true ) )
F_30 ( V_7 -> V_8 . V_2 ) ;
}
return 0 ;
}
int F_335 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_385 * args = V_26 ;
struct V_6 * V_7 ;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL )
return - V_120 ;
switch ( V_7 -> V_9 ) {
case V_386 :
case V_387 :
args -> V_388 = V_389 ;
break;
case V_390 :
args -> V_388 = V_391 ;
break;
default:
args -> V_388 = V_392 ;
break;
}
F_68 ( & V_7 -> V_8 ) ;
return 0 ;
}
int F_336 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_385 * args = V_26 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_19 ;
switch ( args -> V_388 ) {
case V_392 :
V_4 = V_5 ;
break;
case V_389 :
V_4 = V_386 ;
break;
case V_391 :
V_4 = F_337 ( V_2 ) ? V_390 : V_5 ;
break;
default:
return - V_52 ;
}
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_120 ;
goto V_121;
}
V_19 = F_333 ( V_7 , V_4 ) ;
F_49 ( & V_7 -> V_8 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_338 ( struct V_6 * V_7 ,
T_6 V_367 ,
struct V_149 * V_393 ,
struct V_153 * * V_394 ,
const struct V_227 * V_228 )
{
T_6 V_349 , V_348 ;
int V_19 ;
V_19 = F_305 ( V_7 , V_393 , V_394 ) ;
if ( V_19 )
return V_19 ;
V_7 -> V_10 ++ ;
V_19 = F_333 ( V_7 ,
F_337 ( V_7 -> V_8 . V_2 ) ? V_390 : V_5 ) ;
if ( V_19 )
goto V_395;
V_19 = F_195 ( V_7 , V_228 , V_367 ,
V_228 -> type == V_352 ?
V_127 : 0 ) ;
if ( V_19 )
goto V_395;
F_183 ( V_7 ) ;
V_348 = V_7 -> V_8 . V_66 ;
V_349 = V_7 -> V_8 . V_65 ;
V_7 -> V_8 . V_66 = 0 ;
V_7 -> V_8 . V_65 |= V_208 ;
F_308 ( V_7 ,
V_349 ,
V_348 ) ;
return 0 ;
V_395:
V_7 -> V_10 -- ;
return V_19 ;
}
void
F_339 ( struct V_6 * V_7 ,
const struct V_227 * V_228 )
{
if ( F_14 ( V_7 -> V_10 == 0 ) )
return;
F_199 ( V_7 , V_228 ) ;
V_7 -> V_10 -- ;
}
int
F_38 ( struct V_6 * V_7 , bool V_231 )
{
T_5 V_348 , V_349 ;
int V_19 ;
if ( V_7 -> V_8 . V_66 == V_67 )
return 0 ;
V_19 = F_55 ( V_7 , ! V_231 ) ;
if ( V_19 )
return V_19 ;
F_330 ( V_7 ) ;
V_348 = V_7 -> V_8 . V_66 ;
V_349 = V_7 -> V_8 . V_65 ;
if ( ( V_7 -> V_8 . V_65 & V_67 ) == 0 ) {
F_115 ( V_7 , false ) ;
V_7 -> V_8 . V_65 |= V_67 ;
}
F_37 ( ( V_7 -> V_8 . V_66 & ~ V_67 ) != 0 ) ;
if ( V_231 ) {
V_7 -> V_8 . V_65 = V_67 ;
V_7 -> V_8 . V_66 = V_67 ;
}
F_308 ( V_7 ,
V_349 ,
V_348 ) ;
return 0 ;
}
static int
F_340 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_185 * V_80 = V_28 -> V_186 ;
unsigned long V_396 = V_157 - V_397 ;
struct V_153 * V_191 , * V_398 = NULL ;
unsigned V_158 ;
int V_19 ;
V_19 = F_8 ( & V_12 -> V_24 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_121 ( & V_12 -> V_24 , false ) ;
if ( V_19 )
return V_19 ;
F_5 ( & V_80 -> V_14 . V_187 ) ;
F_18 (request, &file_priv->mm.request_list, client_list) {
if ( F_132 ( V_191 -> V_170 , V_396 ) )
break;
if ( ! V_191 -> V_170 )
continue;
V_398 = V_191 ;
}
V_158 = F_147 ( & V_12 -> V_24 . V_158 ) ;
if ( V_398 )
F_179 ( V_398 ) ;
F_6 ( & V_80 -> V_14 . V_187 ) ;
if ( V_398 == NULL )
return 0 ;
V_19 = F_134 ( V_398 , V_158 , true , NULL , NULL ) ;
if ( V_19 == 0 )
F_256 ( V_12 -> V_302 , & V_12 -> V_14 . V_303 , 0 ) ;
F_299 ( V_398 ) ;
return V_19 ;
}
static bool
F_341 ( struct V_33 * V_34 , T_5 V_367 , T_4 V_212 )
{
struct V_6 * V_7 = V_34 -> V_7 ;
if ( V_367 &&
V_34 -> V_37 . V_108 & ( V_367 - 1 ) )
return true ;
if ( V_212 & V_127 && ! V_7 -> V_355 )
return true ;
if ( V_212 & V_371 &&
V_34 -> V_37 . V_108 < ( V_212 & V_372 ) )
return true ;
return false ;
}
static int
F_342 ( struct V_6 * V_7 ,
struct V_366 * V_281 ,
const struct V_227 * V_351 ,
T_5 V_367 ,
T_4 V_212 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
struct V_33 * V_34 ;
unsigned V_354 ;
int V_19 ;
if ( F_14 ( V_281 == & V_12 -> V_14 . V_399 -> V_8 ) )
return - V_172 ;
if ( F_14 ( V_212 & ( V_400 | V_127 ) && ! F_311 ( V_281 ) ) )
return - V_52 ;
if ( F_14 ( ( V_212 & ( V_127 | V_400 ) ) == V_127 ) )
return - V_52 ;
if ( F_14 ( F_311 ( V_281 ) != ! ! V_351 ) )
return - V_52 ;
V_34 = V_351 ? F_343 ( V_7 , V_351 ) :
F_344 ( V_7 , V_281 ) ;
if ( F_24 ( V_34 ) )
return F_25 ( V_34 ) ;
if ( V_34 ) {
if ( F_14 ( V_34 -> V_36 == V_401 ) )
return - V_75 ;
if ( F_341 ( V_34 , V_367 , V_212 ) ) {
unsigned long V_59 ;
V_59 = V_351 ? F_197 ( V_7 , V_351 ) :
F_345 ( V_7 , V_281 ) ;
F_138 ( V_34 -> V_36 ,
L_15
L_16
L_17 ,
V_351 ? L_18 : L_19 ,
V_59 ,
V_367 ,
! ! ( V_212 & V_127 ) ,
V_7 -> V_355 ) ;
V_19 = F_47 ( V_34 ) ;
if ( V_19 )
return V_19 ;
V_34 = NULL ;
}
}
V_354 = V_34 ? V_34 -> V_354 : 0 ;
if ( V_34 == NULL || ! F_309 ( & V_34 -> V_37 ) ) {
V_34 = F_319 ( V_7 , V_281 , V_351 , V_367 ,
V_212 ) ;
if ( F_24 ( V_34 ) )
return F_25 ( V_34 ) ;
} else {
V_19 = F_327 ( V_34 , V_7 -> V_9 , V_212 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_351 && V_351 -> type == V_352 &&
( V_354 ^ V_34 -> V_354 ) & V_402 ) {
bool V_132 , V_403 ;
T_6 V_368 , V_369 ;
V_368 = F_204 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_142 ) ;
V_369 = F_205 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_142 ,
true ) ;
V_403 = ( V_34 -> V_37 . V_13 == V_368 &&
( V_34 -> V_37 . V_108 & ( V_369 - 1 ) ) == 0 ) ;
V_132 = ( V_34 -> V_37 . V_108 + V_368 <=
V_12 -> V_32 . V_236 ) ;
V_7 -> V_355 = V_132 && V_403 ;
F_14 ( V_212 & V_127 && ! V_7 -> V_355 ) ;
}
V_34 -> V_36 ++ ;
return 0 ;
}
int
F_346 ( struct V_6 * V_7 ,
struct V_366 * V_281 ,
T_5 V_367 ,
T_4 V_212 )
{
return F_342 ( V_7 , V_281 ,
F_311 ( V_281 ) ? & V_229 : NULL ,
V_367 , V_212 ) ;
}
int
F_195 ( struct V_6 * V_7 ,
const struct V_227 * V_228 ,
T_5 V_367 ,
T_4 V_212 )
{
if ( F_200 ( ! V_228 , L_20 ) )
return - V_52 ;
return F_342 ( V_7 , F_347 ( V_7 ) , V_228 ,
V_367 , V_212 | V_400 ) ;
}
void
F_199 ( struct V_6 * V_7 ,
const struct V_227 * V_228 )
{
struct V_33 * V_34 = F_343 ( V_7 , V_228 ) ;
F_37 ( ! V_34 ) ;
F_14 ( V_34 -> V_36 == 0 ) ;
F_14 ( ! F_348 ( V_7 , V_228 ) ) ;
-- V_34 -> V_36 ;
}
int
F_349 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_404 * args = V_26 ;
struct V_6 * V_7 ;
int V_19 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_120 ;
goto V_121;
}
V_19 = F_297 ( V_7 ) ;
if ( V_19 )
goto V_207;
F_350 ( V_201 > 16 ) ;
args -> V_405 = V_7 -> V_198 << 16 ;
if ( V_7 -> V_199 )
args -> V_405 |= V_7 -> V_199 -> V_150 -> V_151 ;
V_207:
F_49 ( & V_7 -> V_8 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_351 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_80 )
{
return F_340 ( V_2 , V_80 ) ;
}
int
F_352 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_80 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_406 * args = V_26 ;
struct V_6 * V_7 ;
int V_19 ;
switch ( args -> V_63 ) {
case V_68 :
case V_71 :
break;
default:
return - V_52 ;
}
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_99 ( F_100 ( V_2 , V_80 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_120 ;
goto V_121;
}
if ( F_334 ( V_7 ) ) {
V_19 = - V_52 ;
goto V_85;
}
if ( V_7 -> V_62 &&
V_7 -> V_142 != V_143 &&
V_12 -> V_272 & V_273 ) {
if ( V_7 -> V_63 == V_71 )
F_96 ( V_7 ) ;
if ( args -> V_63 == V_71 )
F_79 ( V_7 ) ;
}
if ( V_7 -> V_63 != V_64 )
V_7 -> V_63 = args -> V_63 ;
if ( V_7 -> V_63 == V_68 && V_7 -> V_62 == NULL )
F_218 ( V_7 ) ;
args -> V_407 = V_7 -> V_63 != V_64 ;
V_85:
F_49 ( & V_7 -> V_8 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
void F_353 ( struct V_6 * V_7 ,
const struct V_257 * V_77 )
{
int V_51 ;
F_354 ( & V_7 -> V_259 ) ;
for ( V_51 = 0 ; V_51 < V_201 ; V_51 ++ )
F_354 ( & V_7 -> V_278 [ V_51 ] ) ;
F_354 ( & V_7 -> V_408 ) ;
F_354 ( & V_7 -> V_356 ) ;
F_354 ( & V_7 -> V_409 ) ;
V_7 -> V_77 = V_77 ;
V_7 -> V_410 = V_411 ;
V_7 -> V_63 = V_71 ;
F_4 ( V_7 -> V_8 . V_2 -> V_23 , V_7 -> V_8 . V_13 ) ;
}
struct V_6 * F_66 ( struct V_1 * V_2 ,
T_1 V_13 )
{
struct V_6 * V_7 ;
struct V_41 * V_42 ;
T_13 V_412 ;
V_7 = F_60 ( V_2 ) ;
if ( V_7 == NULL )
return NULL ;
if ( F_355 ( V_2 , & V_7 -> V_8 , V_13 ) != 0 ) {
F_62 ( V_7 ) ;
return NULL ;
}
V_412 = V_413 | V_414 ;
if ( F_356 ( V_2 ) || F_357 ( V_2 ) ) {
V_412 &= ~ V_415 ;
V_412 |= V_271 ;
}
V_42 = F_21 ( V_7 -> V_8 . V_43 ) -> V_44 ;
F_358 ( V_42 , V_412 ) ;
F_353 ( V_7 , & V_416 ) ;
V_7 -> V_8 . V_66 = V_67 ;
V_7 -> V_8 . V_65 = V_67 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_9 = V_386 ;
} else
V_7 -> V_9 = V_5 ;
F_359 ( V_7 ) ;
return V_7 ;
}
static bool F_360 ( struct V_6 * V_7 )
{
if ( V_7 -> V_63 != V_71 )
return false ;
if ( V_7 -> V_8 . V_43 == NULL )
return true ;
return F_361 ( & V_7 -> V_8 . V_43 -> V_417 ) == 1 ;
}
void F_362 ( struct V_211 * V_418 )
{
struct V_6 * V_7 = F_99 ( V_418 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_33 * V_34 , * V_72 ;
F_118 ( V_12 ) ;
F_363 ( V_7 ) ;
F_46 (vma, next, &obj->vma_list, vma_link) {
int V_19 ;
V_34 -> V_36 = 0 ;
V_19 = F_47 ( V_34 ) ;
if ( F_14 ( V_19 == - V_179 ) ) {
bool V_419 ;
V_419 = V_12 -> V_14 . V_145 ;
V_12 -> V_14 . V_145 = false ;
F_14 ( F_47 ( V_34 ) ) ;
V_12 -> V_14 . V_145 = V_419 ;
}
}
if ( V_7 -> V_382 )
F_96 ( V_7 ) ;
F_14 ( V_7 -> V_420 ) ;
if ( V_7 -> V_62 && V_7 -> V_63 == V_71 &&
V_12 -> V_272 & V_273 &&
V_7 -> V_142 != V_143 )
F_96 ( V_7 ) ;
if ( F_14 ( V_7 -> V_258 ) )
V_7 -> V_258 = 0 ;
if ( F_360 ( V_7 ) )
V_7 -> V_63 = V_68 ;
F_48 ( V_7 ) ;
F_212 ( V_7 ) ;
F_37 ( V_7 -> V_62 ) ;
if ( V_7 -> V_8 . V_421 )
F_364 ( & V_7 -> V_8 , NULL ) ;
if ( V_7 -> V_77 -> V_422 )
V_7 -> V_77 -> V_422 ( V_7 ) ;
F_365 ( & V_7 -> V_8 ) ;
F_7 ( V_12 , V_7 -> V_8 . V_13 ) ;
F_33 ( V_7 -> V_423 ) ;
F_62 ( V_7 ) ;
F_120 ( V_12 ) ;
}
struct V_33 * F_344 ( struct V_6 * V_7 ,
struct V_366 * V_281 )
{
struct V_33 * V_34 ;
F_18 (vma, &obj->vma_list, vma_link) {
if ( F_311 ( V_34 -> V_281 ) &&
V_34 -> V_351 . type != V_352 )
continue;
if ( V_34 -> V_281 == V_281 )
return V_34 ;
}
return NULL ;
}
struct V_33 * F_343 ( struct V_6 * V_7 ,
const struct V_227 * V_228 )
{
struct V_366 * V_31 = F_347 ( V_7 ) ;
struct V_33 * V_34 ;
if ( F_200 ( ! V_228 , L_20 ) )
return F_320 ( - V_52 ) ;
F_18 (vma, &obj->vma_list, vma_link)
if ( V_34 -> V_281 == V_31 &&
F_366 ( & V_34 -> V_351 , V_228 ) )
return V_34 ;
return NULL ;
}
void F_310 ( struct V_33 * V_34 )
{
struct V_366 * V_281 = NULL ;
F_14 ( V_34 -> V_37 . V_363 ) ;
if ( ! F_140 ( & V_34 -> V_424 ) )
return;
V_281 = V_34 -> V_281 ;
if ( ! F_311 ( V_281 ) )
F_367 ( F_368 ( V_281 ) ) ;
F_162 ( & V_34 -> V_350 ) ;
F_63 ( F_240 ( V_34 -> V_7 -> V_8 . V_2 ) -> V_425 , V_34 ) ;
}
static void
F_369 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_149 * V_150 ;
int V_51 ;
F_242 (ring, dev_priv, i)
V_12 -> V_426 . V_427 ( V_150 ) ;
}
int
F_370 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 = 0 ;
F_17 ( & V_2 -> V_25 ) ;
V_19 = F_314 ( V_2 ) ;
if ( V_19 )
goto V_321;
F_244 ( V_2 ) ;
F_369 ( V_2 ) ;
F_19 ( & V_2 -> V_25 ) ;
F_371 ( & V_12 -> V_24 . V_428 ) ;
F_371 ( & V_12 -> V_14 . V_303 ) ;
F_372 ( & V_12 -> V_14 . V_332 ) ;
F_14 ( V_12 -> V_14 . V_405 ) ;
return 0 ;
V_321:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int F_373 ( struct V_153 * V_154 , int V_429 )
{
struct V_149 * V_150 = V_154 -> V_150 ;
struct V_1 * V_2 = V_150 -> V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
T_6 V_430 = V_431 + ( V_429 * 0x200 ) ;
T_6 * V_432 = V_12 -> V_433 . V_432 [ V_429 ] ;
int V_51 , V_19 ;
if ( ! F_374 ( V_2 ) || ! V_432 )
return 0 ;
V_19 = F_375 ( V_154 , V_434 / 4 * 3 ) ;
if ( V_19 )
return V_19 ;
for ( V_51 = 0 ; V_51 < V_434 ; V_51 += 4 ) {
F_376 ( V_150 , F_377 ( 1 ) ) ;
F_376 ( V_150 , V_430 + V_51 ) ;
F_376 ( V_150 , V_432 [ V_51 / 4 ] ) ;
}
F_378 ( V_150 ) ;
return V_19 ;
}
void F_379 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
if ( F_142 ( V_2 ) -> V_169 < 5 ||
V_12 -> V_14 . V_435 == V_436 )
return;
F_380 ( V_437 , F_381 ( V_437 ) |
V_438 ) ;
if ( F_382 ( V_2 ) )
return;
F_380 ( V_439 , F_381 ( V_439 ) | V_440 ) ;
if ( F_383 ( V_2 ) )
F_380 ( V_441 , F_384 ( V_442 ) ) ;
else if ( F_385 ( V_2 ) )
F_380 ( V_441 , F_384 ( V_443 ) ) ;
else if ( F_386 ( V_2 ) )
F_380 ( V_444 , F_384 ( V_445 ) ) ;
else
F_387 () ;
}
static bool
F_388 ( struct V_1 * V_2 )
{
if ( ! F_389 ( V_2 ) )
return false ;
if ( F_383 ( V_2 ) && V_2 -> V_446 -> V_447 < 8 ) {
F_390 ( L_21
L_22 ) ;
return false ;
}
return true ;
}
static void F_391 ( struct V_1 * V_2 , T_6 V_8 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
F_380 ( F_392 ( V_8 ) , 0 ) ;
F_380 ( F_393 ( V_8 ) , 0 ) ;
F_380 ( F_394 ( V_8 ) , 0 ) ;
F_380 ( F_395 ( V_8 ) , 0 ) ;
}
static void F_396 ( struct V_1 * V_2 )
{
if ( F_397 ( V_2 ) ) {
F_391 ( V_2 , V_448 ) ;
F_391 ( V_2 , V_449 ) ;
F_391 ( V_2 , V_450 ) ;
F_391 ( V_2 , V_451 ) ;
F_391 ( V_2 , V_452 ) ;
} else if ( F_398 ( V_2 ) ) {
F_391 ( V_2 , V_449 ) ;
F_391 ( V_2 , V_450 ) ;
} else if ( F_399 ( V_2 ) ) {
F_391 ( V_2 , V_448 ) ;
F_391 ( V_2 , V_453 ) ;
}
}
int F_400 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 ;
V_19 = F_401 ( V_2 ) ;
if ( V_19 )
return V_19 ;
if ( F_402 ( V_2 ) ) {
V_19 = F_403 ( V_2 ) ;
if ( V_19 )
goto V_454;
}
if ( F_388 ( V_2 ) ) {
V_19 = F_404 ( V_2 ) ;
if ( V_19 )
goto V_455;
}
if ( F_405 ( V_2 ) ) {
V_19 = F_406 ( V_2 ) ;
if ( V_19 )
goto V_456;
}
if ( F_407 ( V_2 ) ) {
V_19 = F_408 ( V_2 ) ;
if ( V_19 )
goto V_457;
}
V_19 = F_247 ( V_2 , ( ( T_6 ) ~ 0 - 0x1000 ) ) ;
if ( V_19 )
goto V_458;
return 0 ;
V_458:
F_409 ( & V_12 -> V_150 [ V_459 ] ) ;
V_457:
F_409 ( & V_12 -> V_150 [ V_460 ] ) ;
V_456:
F_409 ( & V_12 -> V_150 [ V_461 ] ) ;
V_455:
F_409 ( & V_12 -> V_150 [ V_462 ] ) ;
V_454:
F_409 ( & V_12 -> V_150 [ V_463 ] ) ;
return V_19 ;
}
int
F_410 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_149 * V_150 ;
int V_19 , V_51 , V_287 ;
if ( F_142 ( V_2 ) -> V_169 < 6 && ! F_411 () )
return - V_22 ;
F_412 ( V_12 , V_464 ) ;
if ( V_12 -> V_465 )
F_380 ( V_466 , F_381 ( V_466 ) | F_413 ( 0xf ) ) ;
if ( F_414 ( V_2 ) )
F_380 ( V_467 , F_415 ( V_2 ) ?
V_468 : V_469 ) ;
if ( F_416 ( V_2 ) ) {
if ( F_417 ( V_2 ) ) {
T_6 V_470 = F_381 ( V_471 ) ;
V_470 &= ~ ( V_472 | V_473 ) ;
F_380 ( V_471 , V_470 ) ;
} else if ( F_142 ( V_2 ) -> V_169 >= 7 ) {
T_6 V_470 = F_381 ( V_474 ) ;
V_470 &= ~ V_475 ;
F_380 ( V_474 , V_470 ) ;
}
}
F_379 ( V_2 ) ;
F_396 ( V_2 ) ;
F_37 ( ! V_12 -> V_150 [ V_463 ] . V_319 ) ;
V_19 = F_418 ( V_2 ) ;
if ( V_19 ) {
F_11 ( L_23 , V_19 ) ;
goto V_85;
}
F_242 (ring, dev_priv, i) {
V_19 = V_150 -> V_476 ( V_150 ) ;
if ( V_19 )
goto V_85;
}
F_242 (ring, dev_priv, i) {
struct V_153 * V_154 ;
F_14 ( ! V_150 -> V_319 ) ;
V_19 = F_270 ( V_150 , V_150 -> V_319 , & V_154 ) ;
if ( V_19 ) {
F_419 ( V_2 ) ;
goto V_85;
}
if ( V_150 -> V_151 == V_463 ) {
for ( V_287 = 0 ; V_287 < F_420 ( V_2 ) ; V_287 ++ )
F_373 ( V_154 , V_287 ) ;
}
V_19 = F_421 ( V_154 ) ;
if ( V_19 && V_19 != - V_22 ) {
F_11 ( L_24 , V_51 , V_19 ) ;
F_277 ( V_154 ) ;
F_419 ( V_2 ) ;
goto V_85;
}
V_19 = F_422 ( V_154 ) ;
if ( V_19 && V_19 != - V_22 ) {
F_11 ( L_25 , V_51 , V_19 ) ;
F_277 ( V_154 ) ;
F_419 ( V_2 ) ;
goto V_85;
}
F_316 ( V_154 ) ;
}
V_85:
F_423 ( V_12 , V_464 ) ;
return V_19 ;
}
int F_424 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 ;
V_117 . V_295 = F_425 ( V_2 ,
V_117 . V_295 ) ;
F_17 ( & V_2 -> V_25 ) ;
if ( F_426 ( V_2 ) ) {
F_380 ( V_477 , V_478 ) ;
if ( F_427 ( ( F_381 ( V_479 ) &
V_480 ) , 10 ) )
F_428 ( L_26 ) ;
}
if ( ! V_117 . V_295 ) {
V_12 -> V_426 . V_481 = V_482 ;
V_12 -> V_426 . V_483 = F_400 ;
V_12 -> V_426 . V_484 = F_409 ;
V_12 -> V_426 . V_427 = V_485 ;
} else {
V_12 -> V_426 . V_481 = V_486 ;
V_12 -> V_426 . V_483 = V_487 ;
V_12 -> V_426 . V_484 = V_488 ;
V_12 -> V_426 . V_427 = V_489 ;
}
F_412 ( V_12 , V_464 ) ;
V_19 = F_429 ( V_2 ) ;
if ( V_19 )
goto V_490;
F_430 ( V_2 ) ;
V_19 = F_431 ( V_2 ) ;
if ( V_19 )
goto V_490;
V_19 = V_12 -> V_426 . V_483 ( V_2 ) ;
if ( V_19 )
goto V_490;
V_19 = F_410 ( V_2 ) ;
if ( V_19 == - V_22 ) {
F_11 ( L_27 ) ;
F_432 ( V_491 , & V_12 -> V_24 . V_158 ) ;
V_19 = 0 ;
}
V_490:
F_423 ( V_12 , V_464 ) ;
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
void
F_419 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_149 * V_150 ;
int V_51 ;
F_242 (ring, dev_priv, i)
V_12 -> V_426 . V_484 ( V_150 ) ;
if ( V_117 . V_295 )
F_433 ( V_2 ) ;
}
static void
F_434 ( struct V_149 * V_150 )
{
F_354 ( & V_150 -> V_279 ) ;
F_354 ( & V_150 -> V_189 ) ;
}
void F_435 ( struct V_11 * V_12 ,
struct V_366 * V_281 )
{
if ( ! F_311 ( V_281 ) )
F_436 ( & V_281 -> V_14 , V_281 -> V_108 , V_281 -> V_39 ) ;
V_281 -> V_2 = V_12 -> V_2 ;
F_354 ( & V_281 -> V_279 ) ;
F_354 ( & V_281 -> V_284 ) ;
F_354 ( & V_281 -> V_492 ) ;
F_158 ( & V_281 -> V_492 , & V_12 -> V_493 ) ;
}
void
F_437 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_51 ;
V_12 -> V_86 =
F_438 ( L_28 ,
sizeof( struct V_6 ) , 0 ,
V_494 ,
NULL ) ;
V_12 -> V_425 =
F_438 ( L_29 ,
sizeof( struct V_33 ) , 0 ,
V_494 ,
NULL ) ;
V_12 -> V_202 =
F_438 ( L_30 ,
sizeof( struct V_153 ) , 0 ,
V_494 ,
NULL ) ;
F_354 ( & V_12 -> V_493 ) ;
F_435 ( V_12 , & V_12 -> V_32 . V_8 ) ;
F_354 ( & V_12 -> V_495 ) ;
F_354 ( & V_12 -> V_14 . V_275 ) ;
F_354 ( & V_12 -> V_14 . V_283 ) ;
F_354 ( & V_12 -> V_14 . V_496 ) ;
for ( V_51 = 0 ; V_51 < V_201 ; V_51 ++ )
F_434 ( & V_12 -> V_150 [ V_51 ] ) ;
for ( V_51 = 0 ; V_51 < V_497 ; V_51 ++ )
F_354 ( & V_12 -> V_498 [ V_51 ] . V_499 ) ;
F_439 ( & V_12 -> V_14 . V_303 ,
F_292 ) ;
F_439 ( & V_12 -> V_14 . V_332 ,
F_294 ) ;
F_440 ( & V_12 -> V_24 . V_20 ) ;
V_12 -> V_500 = V_501 ;
if ( F_142 ( V_2 ) -> V_169 >= 7 && ! F_426 ( V_2 ) )
V_12 -> V_502 = 32 ;
else if ( F_142 ( V_2 ) -> V_169 >= 4 || F_441 ( V_2 ) || F_442 ( V_2 ) || F_206 ( V_2 ) )
V_12 -> V_502 = 16 ;
else
V_12 -> V_502 = 8 ;
if ( F_443 ( V_2 ) )
V_12 -> V_502 =
F_381 ( F_444 ( V_503 . V_504 ) ) ;
F_354 ( & V_12 -> V_14 . V_496 ) ;
F_285 ( V_2 ) ;
F_445 ( V_2 ) ;
F_440 ( & V_12 -> V_505 ) ;
V_12 -> V_14 . V_145 = true ;
F_446 ( V_12 ) ;
F_447 ( & V_12 -> V_506 . V_187 ) ;
}
void F_448 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_185 * V_80 = V_28 -> V_186 ;
F_5 ( & V_80 -> V_14 . V_187 ) ;
while ( ! F_140 ( & V_80 -> V_14 . V_189 ) ) {
struct V_153 * V_191 ;
V_191 = F_170 ( & V_80 -> V_14 . V_189 ,
struct V_153 ,
V_188 ) ;
F_162 ( & V_191 -> V_188 ) ;
V_191 -> V_80 = NULL ;
}
F_6 ( & V_80 -> V_14 . V_187 ) ;
if ( ! F_140 ( & V_80 -> V_160 . V_507 ) ) {
F_5 ( & F_240 ( V_2 ) -> V_160 . V_508 ) ;
F_162 ( & V_80 -> V_160 . V_507 ) ;
F_6 ( & F_240 ( V_2 ) -> V_160 . V_508 ) ;
}
}
int F_449 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_185 * V_80 ;
int V_19 ;
F_428 ( L_31 ) ;
V_80 = F_450 ( sizeof( * V_80 ) , V_56 ) ;
if ( ! V_80 )
return - V_57 ;
V_28 -> V_186 = V_80 ;
V_80 -> V_12 = V_2 -> V_23 ;
V_80 -> V_28 = V_28 ;
F_354 ( & V_80 -> V_160 . V_507 ) ;
F_451 ( & V_80 -> V_14 . V_187 ) ;
F_354 ( & V_80 -> V_14 . V_189 ) ;
V_19 = F_452 ( V_2 , V_28 ) ;
if ( V_19 )
F_33 ( V_80 ) ;
return V_19 ;
}
void F_453 ( struct V_6 * V_509 ,
struct V_6 * V_510 ,
unsigned V_420 )
{
if ( V_509 ) {
F_14 ( ! F_173 ( & V_509 -> V_8 . V_2 -> V_25 ) ) ;
F_14 ( ! ( V_509 -> V_420 & V_420 ) ) ;
V_509 -> V_420 &= ~ V_420 ;
}
if ( V_510 ) {
F_14 ( ! F_173 ( & V_510 -> V_8 . V_2 -> V_25 ) ) ;
F_14 ( V_510 -> V_420 & V_420 ) ;
V_510 -> V_420 |= V_420 ;
}
}
unsigned long
F_345 ( struct V_6 * V_511 ,
struct V_366 * V_281 )
{
struct V_11 * V_12 = V_511 -> V_8 . V_2 -> V_23 ;
struct V_33 * V_34 ;
F_14 ( V_281 == & V_12 -> V_14 . V_399 -> V_8 ) ;
F_18 (vma, &o->vma_list, vma_link) {
if ( F_311 ( V_34 -> V_281 ) &&
V_34 -> V_351 . type != V_352 )
continue;
if ( V_34 -> V_281 == V_281 )
return V_34 -> V_37 . V_108 ;
}
F_138 ( 1 , L_32 ,
F_311 ( V_281 ) ? L_33 : L_19 ) ;
return - 1 ;
}
unsigned long
F_197 ( struct V_6 * V_511 ,
const struct V_227 * V_228 )
{
struct V_366 * V_31 = F_347 ( V_511 ) ;
struct V_33 * V_34 ;
F_18 (vma, &o->vma_list, vma_link)
if ( V_34 -> V_281 == V_31 &&
F_366 ( & V_34 -> V_351 , V_228 ) )
return V_34 -> V_37 . V_108 ;
F_138 ( 1 , L_34 , V_228 -> type ) ;
return - 1 ;
}
bool F_454 ( struct V_6 * V_511 ,
struct V_366 * V_281 )
{
struct V_33 * V_34 ;
F_18 (vma, &o->vma_list, vma_link) {
if ( F_311 ( V_34 -> V_281 ) &&
V_34 -> V_351 . type != V_352 )
continue;
if ( V_34 -> V_281 == V_281 && F_309 ( & V_34 -> V_37 ) )
return true ;
}
return false ;
}
bool F_348 ( struct V_6 * V_511 ,
const struct V_227 * V_228 )
{
struct V_366 * V_31 = F_347 ( V_511 ) ;
struct V_33 * V_34 ;
F_18 (vma, &o->vma_list, vma_link)
if ( V_34 -> V_281 == V_31 &&
F_366 ( & V_34 -> V_351 , V_228 ) &&
F_309 ( & V_34 -> V_37 ) )
return true ;
return false ;
}
bool F_225 ( struct V_6 * V_511 )
{
struct V_33 * V_34 ;
F_18 (vma, &o->vma_list, vma_link)
if ( F_309 ( & V_34 -> V_37 ) )
return true ;
return false ;
}
unsigned long F_455 ( struct V_6 * V_511 ,
struct V_366 * V_281 )
{
struct V_11 * V_12 = V_511 -> V_8 . V_2 -> V_23 ;
struct V_33 * V_34 ;
F_14 ( V_281 == & V_12 -> V_14 . V_399 -> V_8 ) ;
F_37 ( F_140 ( & V_511 -> V_356 ) ) ;
F_18 (vma, &o->vma_list, vma_link) {
if ( F_311 ( V_34 -> V_281 ) &&
V_34 -> V_351 . type != V_352 )
continue;
if ( V_34 -> V_281 == V_281 )
return V_34 -> V_37 . V_13 ;
}
return 0 ;
}
bool F_334 ( struct V_6 * V_7 )
{
struct V_33 * V_34 ;
F_18 (vma, &obj->vma_list, vma_link)
if ( V_34 -> V_36 > 0 )
return true ;
return false ;
}
struct V_6 *
F_456 ( struct V_1 * V_2 ,
const void * V_26 , T_1 V_13 )
{
struct V_6 * V_7 ;
struct V_47 * V_50 ;
T_1 V_512 ;
int V_19 ;
V_7 = F_66 ( V_2 , F_85 ( V_13 , V_53 ) ) ;
if ( F_457 ( V_7 ) )
return V_7 ;
V_19 = F_38 ( V_7 , true ) ;
if ( V_19 )
goto V_513;
V_19 = F_52 ( V_7 ) ;
if ( V_19 )
goto V_513;
F_79 ( V_7 ) ;
V_50 = V_7 -> V_62 ;
V_512 = F_458 ( V_50 -> V_58 , V_50 -> V_269 , ( void * ) V_26 , V_13 ) ;
F_96 ( V_7 ) ;
if ( F_14 ( V_512 != V_13 ) ) {
F_11 ( L_35 , V_512 , V_13 ) ;
V_19 = - V_76 ;
goto V_513;
}
return V_7 ;
V_513:
F_49 ( & V_7 -> V_8 ) ;
return F_320 ( V_19 ) ;
}

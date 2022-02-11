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
V_135 = true ;
}
}
if ( V_135 )
F_30 ( V_2 ) ;
else
V_7 -> V_140 = true ;
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
if ( ! F_98 ( V_141 ,
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
goto V_142;
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
if ( V_7 -> V_143 == V_144 &&
V_7 -> V_8 . V_66 != V_67 &&
F_3 ( V_7 ) ) {
V_19 = F_105 ( V_2 , V_7 , args , V_28 ) ;
}
if ( V_19 == - V_76 || V_19 == - V_145 ) {
if ( V_7 -> V_46 )
V_19 = F_53 ( V_7 , args , V_28 ) ;
else
V_19 = F_114 ( V_2 , V_7 , args , V_28 ) ;
}
V_85:
F_49 ( & V_7 -> V_8 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
V_142:
F_120 ( V_12 ) ;
return V_19 ;
}
int
F_121 ( struct V_18 * error ,
bool V_146 )
{
if ( F_122 ( error ) ) {
if ( ! V_146 )
return - V_22 ;
if ( F_123 ( error ) )
return - V_22 ;
if ( ! error -> V_147 )
return - V_148 ;
}
return 0 ;
}
static void F_124 ( unsigned long V_26 )
{
F_125 ( (struct V_149 * ) V_26 ) ;
}
static bool F_126 ( struct V_11 * V_12 ,
struct V_150 * V_151 )
{
return F_127 ( V_151 -> V_152 , & V_12 -> V_24 . V_153 ) ;
}
static unsigned long F_128 ( unsigned * V_154 )
{
unsigned long V_155 ;
* V_154 = F_129 () ;
V_155 = F_130 () >> 10 ;
F_131 () ;
return V_155 ;
}
static bool F_132 ( unsigned long V_156 , unsigned V_154 )
{
unsigned V_157 ;
if ( F_133 ( F_128 ( & V_157 ) , V_156 ) )
return true ;
return V_157 != V_154 ;
}
static int F_134 ( struct V_158 * V_159 , int V_160 )
{
unsigned long V_156 ;
unsigned V_154 ;
if ( V_159 -> V_151 -> V_161 )
return - V_75 ;
if ( ! F_135 ( V_159 , true ) )
return - V_148 ;
V_156 = F_128 ( & V_154 ) + 5 ;
while ( ! F_136 () ) {
if ( F_137 ( V_159 , true ) )
return 0 ;
if ( F_138 ( V_160 , V_162 ) )
break;
if ( F_132 ( V_156 , V_154 ) )
break;
F_139 () ;
}
if ( F_137 ( V_159 , false ) )
return 0 ;
return - V_148 ;
}
int F_140 ( struct V_158 * V_159 ,
unsigned V_163 ,
bool V_146 ,
T_10 * V_156 ,
struct V_164 * V_165 )
{
struct V_150 * V_151 = F_141 ( V_159 ) ;
struct V_1 * V_2 = V_151 -> V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
const bool V_166 =
F_142 ( V_12 -> V_24 . V_167 ) & F_143 ( V_151 ) ;
int V_160 = V_146 ? V_168 : V_169 ;
F_144 ( V_170 ) ;
unsigned long V_171 ;
T_10 V_172 , V_173 ;
int V_19 ;
F_145 ( ! F_146 ( V_12 ) , L_2 ) ;
if ( F_147 ( & V_159 -> V_174 ) )
return 0 ;
if ( F_137 ( V_159 , true ) )
return 0 ;
V_171 = 0 ;
if ( V_156 ) {
if ( F_14 ( * V_156 < 0 ) )
return - V_52 ;
if ( * V_156 == 0 )
return - V_175 ;
V_171 = V_176 + F_148 ( * V_156 ) ;
}
if ( F_149 ( V_12 ) -> V_177 >= 6 )
F_150 ( V_12 , V_165 , V_159 -> V_178 ) ;
F_151 ( V_159 ) ;
V_172 = F_152 () ;
V_19 = F_134 ( V_159 , V_160 ) ;
if ( V_19 == 0 )
goto V_85;
if ( ! V_166 && F_14 ( ! V_151 -> V_179 ( V_151 ) ) ) {
V_19 = - V_180 ;
goto V_85;
}
for (; ; ) {
struct V_181 V_182 ;
F_153 ( & V_151 -> V_183 , & V_170 , V_160 ) ;
if ( V_163 != F_154 ( & V_12 -> V_24 . V_163 ) ) {
V_19 = F_121 ( & V_12 -> V_24 , V_146 ) ;
if ( V_19 == 0 )
V_19 = - V_148 ;
break;
}
if ( F_137 ( V_159 , false ) ) {
V_19 = 0 ;
break;
}
if ( F_138 ( V_160 , V_162 ) ) {
V_19 = - V_184 ;
break;
}
if ( V_156 && F_155 ( V_176 , V_171 ) ) {
V_19 = - V_175 ;
break;
}
V_182 . V_185 = NULL ;
if ( V_156 || F_126 ( V_12 , V_151 ) ) {
unsigned long V_186 ;
F_156 ( & V_182 , F_124 , ( unsigned long ) V_162 ) ;
V_186 = F_126 ( V_12 , V_151 ) ? V_176 + 1 : V_171 ;
F_157 ( & V_182 , V_186 ) ;
}
F_158 () ;
if ( V_182 . V_185 ) {
F_159 ( & V_182 ) ;
F_160 ( & V_182 ) ;
}
}
if ( ! V_166 )
V_151 -> V_187 ( V_151 ) ;
F_161 ( & V_151 -> V_183 , & V_170 ) ;
V_85:
V_173 = F_152 () ;
F_162 ( V_159 ) ;
if ( V_156 ) {
T_10 V_188 = * V_156 - ( V_173 - V_172 ) ;
* V_156 = V_188 < 0 ? 0 : V_188 ;
if ( V_19 == - V_175 && * V_156 < F_163 ( 1 ) * 1000 )
* V_156 = 0 ;
}
return V_19 ;
}
int F_164 ( struct V_158 * V_159 ,
struct V_27 * V_28 )
{
struct V_11 * V_23 ;
struct V_189 * V_80 ;
F_14 ( ! V_159 || ! V_28 || V_159 -> V_80 ) ;
if ( ! V_159 || ! V_28 )
return - V_52 ;
if ( V_159 -> V_80 )
return - V_52 ;
V_23 = V_159 -> V_151 -> V_2 -> V_23 ;
V_80 = V_28 -> V_190 ;
F_5 ( & V_80 -> V_14 . V_191 ) ;
V_159 -> V_80 = V_80 ;
F_165 ( & V_159 -> V_192 , & V_80 -> V_14 . V_193 ) ;
F_6 ( & V_80 -> V_14 . V_191 ) ;
V_159 -> V_194 = F_166 ( F_167 ( V_162 ) ) ;
return 0 ;
}
static inline void
F_168 ( struct V_158 * V_195 )
{
struct V_189 * V_80 = V_195 -> V_80 ;
if ( ! V_80 )
return;
F_5 ( & V_80 -> V_14 . V_191 ) ;
F_169 ( & V_195 -> V_192 ) ;
V_195 -> V_80 = NULL ;
F_6 ( & V_80 -> V_14 . V_191 ) ;
F_170 ( V_195 -> V_194 ) ;
V_195 -> V_194 = NULL ;
}
static void F_171 ( struct V_158 * V_195 )
{
F_172 ( V_195 ) ;
V_195 -> V_196 -> V_197 = V_195 -> V_198 ;
F_173 ( & V_195 -> V_174 ) ;
F_168 ( V_195 ) ;
F_174 ( V_195 ) ;
}
static void
F_175 ( struct V_158 * V_159 )
{
struct V_150 * V_199 = V_159 -> V_151 ;
struct V_158 * V_200 ;
F_176 ( & V_199 -> V_2 -> V_25 ) ;
if ( F_147 ( & V_159 -> V_174 ) )
return;
do {
V_200 = F_177 ( & V_199 -> V_193 ,
F_178 ( * V_200 ) , V_174 ) ;
F_171 ( V_200 ) ;
} while ( V_200 != V_159 );
F_14 ( F_15 ( V_199 -> V_2 ) ) ;
}
int
F_179 ( struct V_158 * V_159 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
bool V_146 ;
int V_19 ;
F_37 ( V_159 == NULL ) ;
V_2 = V_159 -> V_151 -> V_2 ;
V_12 = V_2 -> V_23 ;
V_146 = V_12 -> V_14 . V_146 ;
F_37 ( ! F_180 ( & V_2 -> V_25 ) ) ;
V_19 = F_121 ( & V_12 -> V_24 , V_146 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_140 ( V_159 ,
F_154 ( & V_12 -> V_24 . V_163 ) ,
V_146 , NULL , NULL ) ;
if ( V_19 )
return V_19 ;
F_175 ( V_159 ) ;
return 0 ;
}
int
F_55 ( struct V_6 * V_7 ,
bool V_201 )
{
int V_19 , V_51 ;
if ( ! V_7 -> V_202 )
return 0 ;
if ( V_201 ) {
if ( V_7 -> V_203 != NULL ) {
V_19 = F_179 ( V_7 -> V_203 ) ;
if ( V_19 )
return V_19 ;
V_51 = V_7 -> V_203 -> V_151 -> V_152 ;
if ( V_7 -> V_204 [ V_51 ] == V_7 -> V_203 )
F_181 ( V_7 , V_51 ) ;
else
F_182 ( V_7 ) ;
}
} else {
for ( V_51 = 0 ; V_51 < V_205 ; V_51 ++ ) {
if ( V_7 -> V_204 [ V_51 ] == NULL )
continue;
V_19 = F_179 ( V_7 -> V_204 [ V_51 ] ) ;
if ( V_19 )
return V_19 ;
F_181 ( V_7 , V_51 ) ;
}
F_183 ( V_7 -> V_202 ) ;
}
return 0 ;
}
static void
F_184 ( struct V_6 * V_7 ,
struct V_158 * V_159 )
{
int V_151 = V_159 -> V_151 -> V_152 ;
if ( V_7 -> V_204 [ V_151 ] == V_159 )
F_181 ( V_7 , V_151 ) ;
else if ( V_7 -> V_203 == V_159 )
F_182 ( V_7 ) ;
F_175 ( V_159 ) ;
}
static T_11 int
F_185 ( struct V_6 * V_7 ,
struct V_164 * V_165 ,
bool V_201 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_158 * V_206 [ V_205 ] ;
unsigned V_163 ;
int V_19 , V_51 , V_207 = 0 ;
F_37 ( ! F_180 ( & V_2 -> V_25 ) ) ;
F_37 ( ! V_12 -> V_14 . V_146 ) ;
if ( ! V_7 -> V_202 )
return 0 ;
V_19 = F_121 ( & V_12 -> V_24 , true ) ;
if ( V_19 )
return V_19 ;
V_163 = F_154 ( & V_12 -> V_24 . V_163 ) ;
if ( V_201 ) {
struct V_158 * V_159 ;
V_159 = V_7 -> V_203 ;
if ( V_159 == NULL )
return 0 ;
V_206 [ V_207 ++ ] = F_186 ( V_159 ) ;
} else {
for ( V_51 = 0 ; V_51 < V_205 ; V_51 ++ ) {
struct V_158 * V_159 ;
V_159 = V_7 -> V_204 [ V_51 ] ;
if ( V_159 == NULL )
continue;
V_206 [ V_207 ++ ] = F_186 ( V_159 ) ;
}
}
F_19 ( & V_2 -> V_25 ) ;
for ( V_51 = 0 ; V_19 == 0 && V_51 < V_207 ; V_51 ++ )
V_19 = F_140 ( V_206 [ V_51 ] , V_163 , true ,
NULL , V_165 ) ;
F_17 ( & V_2 -> V_25 ) ;
for ( V_51 = 0 ; V_51 < V_207 ; V_51 ++ ) {
if ( V_19 == 0 )
F_184 ( V_7 , V_206 [ V_51 ] ) ;
F_174 ( V_206 [ V_51 ] ) ;
}
return V_19 ;
}
static struct V_164 * F_187 ( struct V_27 * V_28 )
{
struct V_189 * V_208 = V_28 -> V_190 ;
return & V_208 -> V_165 ;
}
int
F_188 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_209 * args = V_26 ;
struct V_6 * V_7 ;
T_5 V_65 = args -> V_65 ;
T_5 V_66 = args -> V_66 ;
int V_19 ;
if ( V_66 & V_210 )
return - V_52 ;
if ( V_65 & V_210 )
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
V_19 = F_185 ( V_7 ,
F_187 ( V_28 ) ,
! V_66 ) ;
if ( V_19 )
goto V_211;
if ( V_65 & V_212 )
V_19 = F_107 ( V_7 , V_66 != 0 ) ;
else
V_19 = F_38 ( V_7 , V_66 != 0 ) ;
if ( V_66 != 0 )
F_56 ( V_7 ,
V_66 == V_212 ?
V_130 : V_83 ) ;
V_211:
F_49 ( & V_7 -> V_8 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_189 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_213 * args = V_26 ;
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
F_190 ( V_7 ) ;
F_49 ( & V_7 -> V_8 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_191 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_214 * args = V_26 ;
struct V_215 * V_7 ;
unsigned long V_106 ;
if ( args -> V_216 & ~ ( V_217 ) )
return - V_52 ;
if ( args -> V_216 & V_217 && ! V_218 )
return - V_180 ;
V_7 = F_100 ( V_2 , V_28 , args -> V_88 ) ;
if ( V_7 == NULL )
return - V_120 ;
if ( ! V_7 -> V_43 ) {
F_68 ( V_7 ) ;
return - V_52 ;
}
V_106 = F_192 ( V_7 -> V_43 , 0 , args -> V_13 ,
V_219 | V_220 , V_221 ,
args -> V_59 ) ;
if ( args -> V_216 & V_217 ) {
struct V_222 * V_14 = V_162 -> V_14 ;
struct V_223 * V_34 ;
F_193 ( & V_14 -> V_224 ) ;
V_34 = F_194 ( V_14 , V_106 ) ;
if ( V_34 )
V_34 -> V_225 =
F_195 ( F_196 ( V_34 -> V_226 ) ) ;
else
V_106 = - V_57 ;
F_197 ( & V_14 -> V_224 ) ;
}
F_68 ( V_7 ) ;
if ( F_24 ( ( void * ) V_106 ) )
return V_106 ;
args -> V_227 = ( T_4 ) V_106 ;
return 0 ;
}
int F_198 ( struct V_223 * V_34 , struct V_228 * V_229 )
{
struct V_6 * V_7 = F_99 ( V_34 -> V_230 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_231 V_232 = V_233 ;
T_12 V_124 ;
unsigned long V_234 ;
int V_19 = 0 ;
bool V_235 = ! ! ( V_229 -> V_216 & V_236 ) ;
F_118 ( V_12 ) ;
V_124 = ( ( unsigned long ) V_229 -> V_237 - V_34 -> V_238 ) >>
V_239 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
goto V_85;
F_199 ( V_7 , V_124 , true , V_235 ) ;
V_19 = F_185 ( V_7 , NULL , ! V_235 ) ;
if ( V_19 )
goto V_121;
if ( V_7 -> V_9 != V_5 && ! F_2 ( V_2 ) ) {
V_19 = - V_76 ;
goto V_121;
}
if ( V_7 -> V_8 . V_13 >= V_12 -> V_32 . V_240 &&
V_7 -> V_143 == V_144 ) {
static const unsigned int V_241 = 256 ;
memset ( & V_232 , 0 , sizeof( V_232 ) ) ;
V_232 . type = V_242 ;
V_232 . V_243 . V_244 . V_59 = F_200 ( V_124 , V_241 ) ;
V_232 . V_243 . V_244 . V_13 =
F_201 (unsigned int,
chunk_size,
(vma->vm_end - vma->vm_start)/PAGE_SIZE -
view.params.partial.offset) ;
}
V_19 = F_202 ( V_7 , & V_232 , 0 , V_127 ) ;
if ( V_19 )
goto V_121;
V_19 = F_107 ( V_7 , V_235 ) ;
if ( V_19 )
goto V_245;
V_19 = F_203 ( V_7 ) ;
if ( V_19 )
goto V_245;
V_234 = V_12 -> V_32 . V_246 +
F_204 ( V_7 , & V_232 ) ;
V_234 >>= V_239 ;
if ( F_81 ( V_232 . type == V_242 ) ) {
unsigned long V_8 = V_34 -> V_238 +
( V_232 . V_243 . V_244 . V_59 << V_239 ) ;
unsigned int V_51 ;
for ( V_51 = 0 ; V_51 < V_232 . V_243 . V_244 . V_13 ; V_51 ++ ) {
V_19 = F_205 ( V_34 , V_8 + V_51 * V_53 , V_234 + V_51 ) ;
if ( V_19 )
break;
}
V_7 -> V_247 = true ;
} else {
if ( ! V_7 -> V_247 ) {
unsigned long V_13 = F_201 (unsigned long,
vma->vm_end - vma->vm_start,
obj->base.size) ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_13 > > V_239 ; V_51 ++ ) {
V_19 = F_205 ( V_34 ,
( unsigned long ) V_34 -> V_238 + V_51 * V_53 ,
V_234 + V_51 ) ;
if ( V_19 )
break;
}
V_7 -> V_247 = true ;
} else
V_19 = F_205 ( V_34 ,
( unsigned long ) V_229 -> V_237 ,
V_234 + V_124 ) ;
}
V_245:
F_206 ( V_7 , & V_232 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
V_85:
switch ( V_19 ) {
case - V_22 :
if ( ! F_123 ( & V_12 -> V_24 ) ) {
V_19 = V_248 ;
break;
}
case - V_148 :
case 0 :
case - V_184 :
case - V_249 :
case - V_75 :
V_19 = V_250 ;
break;
case - V_57 :
V_19 = V_251 ;
break;
case - V_145 :
case - V_76 :
V_19 = V_248 ;
break;
default:
F_207 ( V_19 , L_3 , V_19 ) ;
V_19 = V_248 ;
break;
}
F_120 ( V_12 ) ;
return V_19 ;
}
void
F_208 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_247 )
return;
F_209 ( & V_7 -> V_8 . V_252 ,
V_7 -> V_8 . V_2 -> V_253 -> V_44 ) ;
V_7 -> V_247 = false ;
}
void
F_210 ( struct V_11 * V_12 )
{
struct V_6 * V_7 ;
F_18 (obj, &dev_priv->mm.bound_list, global_list)
F_208 ( V_7 ) ;
}
T_5
F_211 ( struct V_1 * V_2 , T_5 V_13 , int V_143 )
{
T_5 V_254 ;
if ( F_149 ( V_2 ) -> V_177 >= 4 ||
V_143 == V_144 )
return V_13 ;
if ( F_149 ( V_2 ) -> V_177 == 3 )
V_254 = 1024 * 1024 ;
else
V_254 = 512 * 1024 ;
while ( V_254 < V_13 )
V_254 <<= 1 ;
return V_254 ;
}
T_5
F_212 ( struct V_1 * V_2 , T_5 V_13 ,
int V_143 , bool V_255 )
{
if ( F_149 ( V_2 ) -> V_177 >= 4 || ( ! V_255 && F_213 ( V_2 ) ) ||
V_143 == V_144 )
return 4096 ;
return F_211 ( V_2 , V_13 , V_143 ) ;
}
static int F_214 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
int V_19 ;
if ( F_215 ( & V_7 -> V_8 . V_252 ) )
return 0 ;
V_12 -> V_14 . V_256 = true ;
V_19 = F_216 ( & V_7 -> V_8 ) ;
if ( V_19 != - V_145 )
goto V_85;
F_217 ( V_12 ,
V_7 -> V_8 . V_13 >> V_239 ,
V_257 |
V_258 |
V_259 ) ;
V_19 = F_216 ( & V_7 -> V_8 ) ;
if ( V_19 != - V_145 )
goto V_85;
F_218 ( V_12 ) ;
V_19 = F_216 ( & V_7 -> V_8 ) ;
V_85:
V_12 -> V_14 . V_256 = false ;
return V_19 ;
}
static void F_219 ( struct V_6 * V_7 )
{
F_220 ( & V_7 -> V_8 ) ;
}
int
F_221 ( struct V_27 * V_28 ,
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
F_222 ( L_4 ) ;
V_19 = - V_76 ;
goto V_85;
}
V_19 = F_214 ( V_7 ) ;
if ( V_19 )
goto V_85;
* V_59 = F_223 ( & V_7 -> V_8 . V_252 ) ;
V_85:
F_49 ( & V_7 -> V_8 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_224 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_260 * args = V_26 ;
return F_221 ( V_28 , V_2 , args -> V_88 , & args -> V_59 ) ;
}
static void
F_225 ( struct V_6 * V_7 )
{
F_219 ( V_7 ) ;
if ( V_7 -> V_8 . V_43 == NULL )
return;
F_226 ( F_21 ( V_7 -> V_8 . V_43 ) , 0 , ( T_8 ) - 1 ) ;
V_7 -> V_63 = V_64 ;
}
static void
F_227 ( struct V_6 * V_7 )
{
struct V_41 * V_42 ;
switch ( V_7 -> V_63 ) {
case V_68 :
F_225 ( V_7 ) ;
case V_64 :
return;
}
if ( V_7 -> V_8 . V_43 == NULL )
return;
V_42 = F_21 ( V_7 -> V_8 . V_43 ) -> V_44 ,
F_228 ( V_42 , 0 , ( T_8 ) - 1 ) ;
}
static void
F_229 ( struct V_6 * V_7 )
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
F_230 ( V_7 ) ;
if ( F_22 ( V_7 ) )
F_231 ( V_7 ) ;
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
const struct V_261 * V_77 = V_7 -> V_77 ;
if ( V_7 -> V_62 == NULL )
return 0 ;
if ( V_7 -> V_262 )
return - V_75 ;
F_37 ( F_232 ( V_7 ) ) ;
F_169 ( & V_7 -> V_263 ) ;
V_77 -> V_264 ( V_7 ) ;
V_7 -> V_62 = NULL ;
F_227 ( V_7 ) ;
return 0 ;
}
static int
F_233 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
int V_265 , V_51 ;
struct V_41 * V_42 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_114 V_115 ;
struct V_54 * V_54 ;
unsigned long V_266 = 0 ;
int V_19 ;
T_13 V_267 ;
F_37 ( V_7 -> V_8 . V_65 & V_210 ) ;
F_37 ( V_7 -> V_8 . V_66 & V_210 ) ;
V_48 = F_31 ( sizeof( * V_48 ) , V_56 ) ;
if ( V_48 == NULL )
return - V_57 ;
V_265 = V_7 -> V_8 . V_13 / V_53 ;
if ( F_32 ( V_48 , V_265 , V_56 ) ) {
F_33 ( V_48 ) ;
return - V_57 ;
}
V_42 = F_21 ( V_7 -> V_8 . V_43 ) -> V_44 ;
V_267 = F_234 ( V_42 , ~ ( V_268 | V_269 ) ) ;
V_267 |= V_270 | V_271 ;
V_50 = V_48 -> V_58 ;
V_48 -> V_272 = 0 ;
for ( V_51 = 0 ; V_51 < V_265 ; V_51 ++ ) {
V_54 = F_235 ( V_42 , V_51 , V_267 ) ;
if ( F_24 ( V_54 ) ) {
F_217 ( V_12 ,
V_265 ,
V_257 |
V_258 |
V_259 ) ;
V_54 = F_235 ( V_42 , V_51 , V_267 ) ;
}
if ( F_24 ( V_54 ) ) {
F_218 ( V_12 ) ;
V_54 = F_23 ( V_42 , V_51 ) ;
if ( F_24 ( V_54 ) ) {
V_19 = F_25 ( V_54 ) ;
goto V_273;
}
}
#ifdef F_236
if ( F_237 () ) {
V_48 -> V_272 ++ ;
F_238 ( V_50 , V_54 , V_53 , 0 ) ;
V_50 = F_239 ( V_50 ) ;
continue;
}
#endif
if ( ! V_51 || F_240 ( V_54 ) != V_266 + 1 ) {
if ( V_51 )
V_50 = F_239 ( V_50 ) ;
V_48 -> V_272 ++ ;
F_238 ( V_50 , V_54 , V_53 , 0 ) ;
} else {
V_50 -> V_60 += V_53 ;
}
V_266 = F_240 ( V_54 ) ;
F_14 ( ( V_267 & V_274 ) && ( V_266 >= 0x00100000UL ) ) ;
}
#ifdef F_236
if ( ! F_237 () )
#endif
F_241 ( V_50 ) ;
V_7 -> V_62 = V_48 ;
V_19 = F_242 ( V_7 ) ;
if ( V_19 )
goto V_273;
if ( F_22 ( V_7 ) )
F_243 ( V_7 ) ;
if ( V_7 -> V_143 != V_144 &&
V_12 -> V_275 & V_276 )
F_79 ( V_7 ) ;
return 0 ;
V_273:
F_241 ( V_50 ) ;
F_90 (st->sgl, &sg_iter, st->nents, 0 )
F_29 ( F_91 ( & V_115 ) ) ;
F_41 ( V_48 ) ;
F_33 ( V_48 ) ;
if ( V_19 == - V_145 )
V_19 = - V_57 ;
return V_19 ;
}
int
F_52 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
const struct V_261 * V_77 = V_7 -> V_77 ;
int V_19 ;
if ( V_7 -> V_62 )
return 0 ;
if ( V_7 -> V_63 != V_71 ) {
F_222 ( L_5 ) ;
return - V_76 ;
}
F_37 ( V_7 -> V_262 ) ;
V_19 = V_77 -> V_277 ( V_7 ) ;
if ( V_19 )
return V_19 ;
F_165 ( & V_7 -> V_263 , & V_12 -> V_14 . V_278 ) ;
V_7 -> V_279 . V_50 = V_7 -> V_62 -> V_58 ;
V_7 -> V_279 . V_280 = 0 ;
return 0 ;
}
void F_244 ( struct V_33 * V_34 ,
struct V_158 * V_159 )
{
struct V_6 * V_7 = V_34 -> V_7 ;
struct V_150 * V_151 ;
V_151 = F_141 ( V_159 ) ;
if ( V_7 -> V_202 == 0 )
F_45 ( & V_7 -> V_8 ) ;
V_7 -> V_202 |= F_143 ( V_151 ) ;
F_245 ( & V_7 -> V_281 [ V_151 -> V_152 ] , & V_151 -> V_282 ) ;
F_246 ( & V_7 -> V_204 [ V_151 -> V_152 ] , V_159 ) ;
F_245 ( & V_34 -> V_283 , & V_34 -> V_284 -> V_282 ) ;
}
static void
F_182 ( struct V_6 * V_7 )
{
F_183 ( V_7 -> V_203 == NULL ) ;
F_183 ( ! ( V_7 -> V_202 & F_143 ( V_7 -> V_203 -> V_151 ) ) ) ;
F_246 ( & V_7 -> V_203 , NULL ) ;
F_59 ( V_7 , true , V_285 ) ;
}
static void
F_181 ( struct V_6 * V_7 , int V_151 )
{
struct V_33 * V_34 ;
F_183 ( V_7 -> V_204 [ V_151 ] == NULL ) ;
F_183 ( ! ( V_7 -> V_202 & ( 1 << V_151 ) ) ) ;
F_173 ( & V_7 -> V_281 [ V_151 ] ) ;
F_246 ( & V_7 -> V_204 [ V_151 ] , NULL ) ;
if ( V_7 -> V_203 && V_7 -> V_203 -> V_151 -> V_152 == V_151 )
F_182 ( V_7 ) ;
V_7 -> V_202 &= ~ ( 1 << V_151 ) ;
if ( V_7 -> V_202 )
return;
F_245 ( & V_7 -> V_263 ,
& F_247 ( V_7 -> V_8 . V_2 ) -> V_14 . V_286 ) ;
F_18 (vma, &obj->vma_list, vma_link) {
if ( ! F_147 ( & V_34 -> V_283 ) )
F_245 ( & V_34 -> V_283 , & V_34 -> V_284 -> V_287 ) ;
}
F_246 ( & V_7 -> V_288 , NULL ) ;
F_49 ( & V_7 -> V_8 ) ;
}
static int
F_248 ( struct V_1 * V_2 , T_6 V_289 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_150 * V_151 ;
int V_19 , V_51 , V_290 ;
F_249 (ring, dev_priv, i) {
V_19 = F_250 ( V_151 ) ;
if ( V_19 )
return V_19 ;
}
F_251 ( V_2 ) ;
F_249 (ring, dev_priv, i) {
F_252 ( V_151 , V_289 ) ;
for ( V_290 = 0 ; V_290 < F_253 ( V_151 -> V_291 . V_292 ) ; V_290 ++ )
V_151 -> V_291 . V_292 [ V_290 ] = 0 ;
}
return 0 ;
}
int F_254 ( struct V_1 * V_2 , T_6 V_289 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 ;
if ( V_289 == 0 )
return - V_52 ;
V_19 = F_248 ( V_2 , V_289 - 1 ) ;
if ( V_19 )
return V_19 ;
V_12 -> V_293 = V_289 ;
V_12 -> V_294 = V_289 - 1 ;
if ( V_12 -> V_294 == 0 )
V_12 -> V_294 -- ;
return 0 ;
}
int
F_255 ( struct V_1 * V_2 , T_6 * V_289 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
if ( V_12 -> V_293 == 0 ) {
int V_19 = F_248 ( V_2 , 0 ) ;
if ( V_19 )
return V_19 ;
V_12 -> V_293 = 1 ;
}
* V_289 = V_12 -> V_294 = V_12 -> V_293 ++ ;
return 0 ;
}
void F_256 ( struct V_158 * V_195 ,
struct V_6 * V_7 ,
bool V_295 )
{
struct V_150 * V_151 ;
struct V_11 * V_12 ;
struct V_296 * V_196 ;
T_6 V_297 ;
int V_19 ;
if ( F_14 ( V_195 == NULL ) )
return;
V_151 = V_195 -> V_151 ;
V_12 = V_151 -> V_2 -> V_23 ;
V_196 = V_195 -> V_196 ;
F_257 ( V_196 ) ;
V_297 = F_258 ( V_196 ) ;
if ( V_295 ) {
if ( V_117 . V_298 )
V_19 = F_259 ( V_195 ) ;
else
V_19 = F_260 ( V_195 ) ;
F_145 ( V_19 , L_6 , V_19 ) ;
}
V_195 -> V_198 = F_258 ( V_196 ) ;
if ( V_117 . V_298 )
V_19 = V_151 -> V_299 ( V_195 ) ;
else {
V_19 = V_151 -> V_300 ( V_195 ) ;
V_195 -> V_301 = F_258 ( V_196 ) ;
}
F_145 ( V_19 , L_7 , V_19 ) ;
V_195 -> V_302 = V_297 ;
V_195 -> V_303 = V_7 ;
V_195 -> V_178 = V_176 ;
V_195 -> V_304 = V_151 -> V_305 ;
V_151 -> V_305 = V_195 -> V_289 ;
F_165 ( & V_195 -> V_174 , & V_151 -> V_193 ) ;
F_261 ( V_195 ) ;
F_262 ( V_151 -> V_2 ) ;
F_263 ( V_12 -> V_306 ,
& V_12 -> V_14 . V_307 ,
F_264 ( V_21 ) ) ;
F_265 ( V_12 -> V_2 ) ;
F_266 ( V_196 ) ;
}
static bool F_267 ( struct V_11 * V_12 ,
const struct V_308 * V_309 )
{
unsigned long V_310 ;
V_310 = F_268 () - V_309 -> V_311 . V_312 ;
if ( V_309 -> V_311 . V_313 )
return true ;
if ( V_309 -> V_311 . V_314 &&
V_310 <= V_309 -> V_311 . V_314 ) {
if ( ! F_269 ( V_309 ) ) {
F_222 ( L_8 ) ;
return true ;
} else if ( F_270 ( V_12 ) ) {
if ( F_271 ( V_12 ) )
F_11 ( L_9 ) ;
return true ;
}
}
return false ;
}
static void F_272 ( struct V_11 * V_12 ,
struct V_308 * V_309 ,
const bool V_315 )
{
struct V_316 * V_317 ;
if ( F_14 ( ! V_309 ) )
return;
V_317 = & V_309 -> V_311 ;
if ( V_315 ) {
V_317 -> V_313 = F_267 ( V_12 , V_309 ) ;
V_317 -> V_318 ++ ;
V_317 -> V_312 = F_268 () ;
} else {
V_317 -> V_319 ++ ;
}
}
void F_273 ( struct V_320 * V_321 )
{
struct V_158 * V_159 = F_274 ( V_321 ,
F_178 ( * V_159 ) , V_322 ) ;
struct V_308 * V_309 = V_159 -> V_309 ;
if ( V_159 -> V_80 )
F_168 ( V_159 ) ;
if ( V_309 ) {
if ( V_117 . V_298 ) {
if ( V_309 != V_159 -> V_151 -> V_323 )
F_275 ( V_159 ) ;
}
F_276 ( V_309 ) ;
}
F_63 ( V_159 -> V_117 -> V_206 , V_159 ) ;
}
int F_277 ( struct V_150 * V_151 ,
struct V_308 * V_309 ,
struct V_158 * * V_324 )
{
struct V_11 * V_12 = F_247 ( V_151 -> V_2 ) ;
struct V_158 * V_159 ;
int V_19 ;
if ( ! V_324 )
return - V_52 ;
* V_324 = NULL ;
V_159 = F_61 ( V_12 -> V_206 , V_56 ) ;
if ( V_159 == NULL )
return - V_57 ;
V_19 = F_255 ( V_151 -> V_2 , & V_159 -> V_289 ) ;
if ( V_19 )
goto V_325;
F_278 ( & V_159 -> V_322 ) ;
V_159 -> V_117 = V_12 ;
V_159 -> V_151 = V_151 ;
V_159 -> V_309 = V_309 ;
F_279 ( V_159 -> V_309 ) ;
if ( V_117 . V_298 )
V_19 = F_280 ( V_159 ) ;
else
V_19 = F_281 ( V_159 ) ;
if ( V_19 ) {
F_276 ( V_159 -> V_309 ) ;
goto V_325;
}
if ( V_117 . V_298 )
V_19 = F_282 ( V_159 ) ;
else
V_19 = F_283 ( V_159 ) ;
if ( V_19 ) {
F_284 ( V_159 ) ;
return V_19 ;
}
* V_324 = V_159 ;
return 0 ;
V_325:
F_63 ( V_12 -> V_206 , V_159 ) ;
return V_19 ;
}
void F_284 ( struct V_158 * V_159 )
{
F_285 ( V_159 -> V_196 ) ;
F_174 ( V_159 ) ;
}
struct V_158 *
F_286 ( struct V_150 * V_151 )
{
struct V_158 * V_195 ;
F_18 (request, &ring->request_list, list) {
if ( F_137 ( V_195 , false ) )
continue;
return V_195 ;
}
return NULL ;
}
static void F_287 ( struct V_11 * V_12 ,
struct V_150 * V_151 )
{
struct V_158 * V_195 ;
bool V_326 ;
V_195 = F_286 ( V_151 ) ;
if ( V_195 == NULL )
return;
V_326 = V_151 -> V_327 . V_328 >= V_329 ;
F_272 ( V_12 , V_195 -> V_309 , V_326 ) ;
F_288 (request, &ring->request_list, list)
F_272 ( V_12 , V_195 -> V_309 , false ) ;
}
static void F_289 ( struct V_11 * V_12 ,
struct V_150 * V_151 )
{
while ( ! F_147 ( & V_151 -> V_282 ) ) {
struct V_6 * V_7 ;
V_7 = F_177 ( & V_151 -> V_282 ,
struct V_6 ,
V_281 [ V_151 -> V_152 ] ) ;
F_181 ( V_7 , V_151 -> V_152 ) ;
}
while ( ! F_147 ( & V_151 -> V_330 ) ) {
struct V_158 * V_331 ;
V_331 = F_177 ( & V_151 -> V_330 ,
struct V_158 ,
V_332 ) ;
F_169 ( & V_331 -> V_332 ) ;
if ( V_331 -> V_309 != V_151 -> V_323 )
F_275 ( V_331 ) ;
F_174 ( V_331 ) ;
}
while ( ! F_147 ( & V_151 -> V_193 ) ) {
struct V_158 * V_195 ;
V_195 = F_177 ( & V_151 -> V_193 ,
struct V_158 ,
V_174 ) ;
F_171 ( V_195 ) ;
}
}
void F_290 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_150 * V_151 ;
int V_51 ;
F_249 (ring, dev_priv, i)
F_287 ( V_12 , V_151 ) ;
F_249 (ring, dev_priv, i)
F_289 ( V_12 , V_151 ) ;
F_291 ( V_2 ) ;
F_292 ( V_2 ) ;
F_14 ( F_15 ( V_2 ) ) ;
}
void
F_293 ( struct V_150 * V_151 )
{
F_14 ( F_15 ( V_151 -> V_2 ) ) ;
while ( ! F_147 ( & V_151 -> V_193 ) ) {
struct V_158 * V_195 ;
V_195 = F_177 ( & V_151 -> V_193 ,
struct V_158 ,
V_174 ) ;
if ( ! F_137 ( V_195 , true ) )
break;
F_171 ( V_195 ) ;
}
while ( ! F_147 ( & V_151 -> V_282 ) ) {
struct V_6 * V_7 ;
V_7 = F_177 ( & V_151 -> V_282 ,
struct V_6 ,
V_281 [ V_151 -> V_152 ] ) ;
if ( ! F_147 ( & V_7 -> V_204 [ V_151 -> V_152 ] -> V_174 ) )
break;
F_181 ( V_7 , V_151 -> V_152 ) ;
}
if ( F_81 ( V_151 -> V_333 &&
F_137 ( V_151 -> V_333 , true ) ) ) {
V_151 -> V_187 ( V_151 ) ;
F_246 ( & V_151 -> V_333 , NULL ) ;
}
F_14 ( F_15 ( V_151 -> V_2 ) ) ;
}
bool
F_251 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_150 * V_151 ;
bool V_334 = true ;
int V_51 ;
F_249 (ring, dev_priv, i) {
F_293 ( V_151 ) ;
V_334 &= F_147 ( & V_151 -> V_193 ) ;
if ( V_117 . V_298 ) {
unsigned long V_216 ;
F_294 ( & V_151 -> V_335 , V_216 ) ;
V_334 &= F_147 ( & V_151 -> V_330 ) ;
F_295 ( & V_151 -> V_335 , V_216 ) ;
F_296 ( V_151 ) ;
}
}
if ( V_334 )
F_297 ( V_12 -> V_306 ,
& V_12 -> V_14 . V_336 ,
F_298 ( 100 ) ) ;
return V_334 ;
}
static void
F_299 ( struct V_337 * V_338 )
{
struct V_11 * V_12 =
F_274 ( V_338 , F_178 ( * V_12 ) , V_14 . V_307 . V_338 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
bool V_334 ;
V_334 = false ;
if ( F_300 ( & V_2 -> V_25 ) ) {
V_334 = F_251 ( V_2 ) ;
F_19 ( & V_2 -> V_25 ) ;
}
if ( ! V_334 )
F_263 ( V_12 -> V_306 , & V_12 -> V_14 . V_307 ,
F_264 ( V_21 ) ) ;
}
static void
F_301 ( struct V_337 * V_338 )
{
struct V_11 * V_12 =
F_274 ( V_338 , F_178 ( * V_12 ) , V_14 . V_336 . V_338 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_150 * V_151 ;
int V_51 ;
F_249 (ring, dev_priv, i)
if ( ! F_147 ( & V_151 -> V_193 ) )
return;
F_302 ( V_2 ) ;
if ( F_300 ( & V_2 -> V_25 ) ) {
struct V_150 * V_151 ;
int V_51 ;
F_249 (ring, dev_priv, i)
F_303 ( & V_151 -> V_339 ) ;
F_19 ( & V_2 -> V_25 ) ;
}
}
static int
F_304 ( struct V_6 * V_7 )
{
int V_51 ;
if ( ! V_7 -> V_202 )
return 0 ;
for ( V_51 = 0 ; V_51 < V_205 ; V_51 ++ ) {
struct V_158 * V_159 ;
V_159 = V_7 -> V_204 [ V_51 ] ;
if ( V_159 == NULL )
continue;
if ( F_147 ( & V_159 -> V_174 ) )
goto V_340;
if ( F_137 ( V_159 , true ) ) {
F_175 ( V_159 ) ;
V_340:
F_181 ( V_7 , V_51 ) ;
}
}
return 0 ;
}
int
F_305 ( struct V_1 * V_2 , void * V_26 , struct V_27 * V_28 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_341 * args = V_26 ;
struct V_6 * V_7 ;
struct V_158 * V_159 [ V_205 ] ;
unsigned V_163 ;
int V_51 , V_207 = 0 ;
int V_19 ;
if ( args -> V_216 != 0 )
return - V_52 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_342 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_19 ( & V_2 -> V_25 ) ;
return - V_120 ;
}
V_19 = F_304 ( V_7 ) ;
if ( V_19 )
goto V_85;
if ( ! V_7 -> V_202 )
goto V_85;
if ( args -> V_343 == 0 ) {
V_19 = - V_175 ;
goto V_85;
}
F_49 ( & V_7 -> V_8 ) ;
V_163 = F_154 ( & V_12 -> V_24 . V_163 ) ;
for ( V_51 = 0 ; V_51 < V_205 ; V_51 ++ ) {
if ( V_7 -> V_204 [ V_51 ] == NULL )
continue;
V_159 [ V_207 ++ ] = F_186 ( V_7 -> V_204 [ V_51 ] ) ;
}
F_19 ( & V_2 -> V_25 ) ;
for ( V_51 = 0 ; V_51 < V_207 ; V_51 ++ ) {
if ( V_19 == 0 )
V_19 = F_140 ( V_159 [ V_51 ] , V_163 , true ,
args -> V_343 > 0 ? & args -> V_343 : NULL ,
V_28 -> V_190 ) ;
F_306 ( V_159 [ V_51 ] ) ;
}
return V_19 ;
V_85:
F_49 ( & V_7 -> V_8 ) ;
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
static int
F_307 ( struct V_6 * V_7 ,
struct V_150 * V_344 ,
struct V_158 * V_345 ,
struct V_158 * * V_346 )
{
struct V_150 * V_347 ;
int V_19 ;
V_347 = F_141 ( V_345 ) ;
if ( V_344 == V_347 )
return 0 ;
if ( F_137 ( V_345 , true ) )
return 0 ;
if ( ! F_308 ( V_7 -> V_8 . V_2 ) ) {
struct V_11 * V_117 = F_247 ( V_7 -> V_8 . V_2 ) ;
V_19 = F_140 ( V_345 ,
F_154 ( & V_117 -> V_24 . V_163 ) ,
V_117 -> V_14 . V_146 ,
NULL ,
& V_117 -> V_165 . V_348 ) ;
if ( V_19 )
return V_19 ;
F_184 ( V_7 , V_345 ) ;
} else {
int V_349 = F_309 ( V_347 , V_344 ) ;
T_6 V_289 = F_310 ( V_345 ) ;
F_14 ( ! V_346 ) ;
if ( V_289 <= V_347 -> V_291 . V_292 [ V_349 ] )
return 0 ;
if ( * V_346 == NULL ) {
V_19 = F_277 ( V_344 , V_344 -> V_323 , V_346 ) ;
if ( V_19 )
return V_19 ;
}
F_311 ( * V_346 , V_347 , V_345 ) ;
V_19 = V_344 -> V_291 . V_350 ( * V_346 , V_347 , V_289 ) ;
if ( V_19 )
return V_19 ;
V_347 -> V_291 . V_292 [ V_349 ] =
F_310 ( V_7 -> V_204 [ V_347 -> V_152 ] ) ;
}
return 0 ;
}
int
F_312 ( struct V_6 * V_7 ,
struct V_150 * V_344 ,
struct V_158 * * V_346 )
{
const bool V_201 = V_7 -> V_8 . V_351 == 0 ;
struct V_158 * V_159 [ V_205 ] ;
int V_19 , V_51 , V_207 ;
if ( ! V_7 -> V_202 )
return 0 ;
if ( V_344 == NULL )
return F_55 ( V_7 , V_201 ) ;
V_207 = 0 ;
if ( V_201 ) {
if ( V_7 -> V_203 )
V_159 [ V_207 ++ ] = V_7 -> V_203 ;
} else {
for ( V_51 = 0 ; V_51 < V_205 ; V_51 ++ )
if ( V_7 -> V_204 [ V_51 ] )
V_159 [ V_207 ++ ] = V_7 -> V_204 [ V_51 ] ;
}
for ( V_51 = 0 ; V_51 < V_207 ; V_51 ++ ) {
V_19 = F_307 ( V_7 , V_344 , V_159 [ V_51 ] , V_346 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static void F_313 ( struct V_6 * V_7 )
{
T_6 V_352 , V_353 ;
F_208 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_65 & V_212 ) == 0 )
return;
F_314 () ;
V_353 = V_7 -> V_8 . V_65 ;
V_352 = V_7 -> V_8 . V_66 ;
V_7 -> V_8 . V_65 &= ~ V_212 ;
V_7 -> V_8 . V_66 &= ~ V_212 ;
F_315 ( V_7 ,
V_353 ,
V_352 ) ;
}
static int F_316 ( struct V_33 * V_34 , bool V_170 )
{
struct V_6 * V_7 = V_34 -> V_7 ;
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
int V_19 ;
if ( F_147 ( & V_34 -> V_354 ) )
return 0 ;
if ( ! F_317 ( & V_34 -> V_37 ) ) {
F_318 ( V_34 ) ;
return 0 ;
}
if ( V_34 -> V_36 )
return - V_75 ;
F_37 ( V_7 -> V_62 == NULL ) ;
if ( V_170 ) {
V_19 = F_55 ( V_7 , false ) ;
if ( V_19 )
return V_19 ;
}
if ( F_319 ( V_34 -> V_284 ) &&
V_34 -> V_355 . type == V_356 ) {
F_313 ( V_7 ) ;
V_19 = F_108 ( V_7 ) ;
if ( V_19 )
return V_19 ;
}
F_320 ( V_34 ) ;
V_34 -> V_284 -> V_357 ( V_34 ) ;
V_34 -> V_358 = 0 ;
F_173 ( & V_34 -> V_283 ) ;
if ( F_319 ( V_34 -> V_284 ) ) {
if ( V_34 -> V_355 . type == V_356 ) {
V_7 -> V_359 = false ;
} else if ( V_34 -> V_355 . V_62 ) {
F_41 ( V_34 -> V_355 . V_62 ) ;
F_33 ( V_34 -> V_355 . V_62 ) ;
}
V_34 -> V_355 . V_62 = NULL ;
}
F_321 ( & V_34 -> V_37 ) ;
F_318 ( V_34 ) ;
if ( F_147 ( & V_7 -> V_360 ) )
F_245 ( & V_7 -> V_263 , & V_12 -> V_14 . V_278 ) ;
F_96 ( V_7 ) ;
return 0 ;
}
int F_47 ( struct V_33 * V_34 )
{
return F_316 ( V_34 , true ) ;
}
int F_322 ( struct V_33 * V_34 )
{
return F_316 ( V_34 , false ) ;
}
int F_323 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_150 * V_151 ;
int V_19 , V_51 ;
F_249 (ring, dev_priv, i) {
if ( ! V_117 . V_298 ) {
struct V_158 * V_159 ;
V_19 = F_277 ( V_151 , V_151 -> V_323 , & V_159 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_324 ( V_159 ) ;
if ( V_19 ) {
F_284 ( V_159 ) ;
return V_19 ;
}
F_325 ( V_159 ) ;
}
V_19 = F_250 ( V_151 ) ;
if ( V_19 )
return V_19 ;
}
F_14 ( F_15 ( V_2 ) ) ;
return 0 ;
}
static bool F_326 ( struct V_33 * V_34 ,
unsigned long V_9 )
{
struct V_361 * V_362 = & V_34 -> V_37 ;
struct V_361 * V_363 ;
if ( V_34 -> V_284 -> V_14 . V_364 == NULL )
return true ;
if ( ! F_317 ( V_362 ) )
return true ;
if ( F_147 ( & V_362 -> V_365 ) )
return true ;
V_363 = F_327 ( V_362 -> V_365 . V_366 , struct V_361 , V_365 ) ;
if ( V_363 -> V_367 && ! V_363 -> V_368 && V_363 -> V_369 != V_9 )
return false ;
V_363 = F_327 ( V_362 -> V_365 . V_72 , struct V_361 , V_365 ) ;
if ( V_363 -> V_367 && ! V_362 -> V_368 && V_363 -> V_369 != V_9 )
return false ;
return true ;
}
static struct V_33 *
F_328 ( struct V_6 * V_7 ,
struct V_370 * V_284 ,
const struct V_231 * V_355 ,
unsigned V_371 ,
T_4 V_216 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
T_6 V_372 , V_373 ;
T_6 V_374 , V_375 ;
T_14 V_108 , V_109 ;
T_14 V_13 , V_376 ;
struct V_33 * V_34 ;
int V_19 ;
if ( F_319 ( V_284 ) ) {
T_6 V_377 ;
if ( F_14 ( ! V_355 ) )
return F_329 ( - V_52 ) ;
V_377 = F_330 ( V_7 , V_355 ) ;
V_376 = F_211 ( V_2 ,
V_377 ,
V_7 -> V_143 ) ;
V_372 = F_212 ( V_2 ,
V_377 ,
V_7 -> V_143 ,
true ) ;
V_373 = F_212 ( V_2 ,
V_377 ,
V_7 -> V_143 ,
false ) ;
V_13 = V_216 & V_127 ? V_376 : V_377 ;
} else {
V_376 = F_211 ( V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_143 ) ;
V_372 = F_212 ( V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_143 ,
true ) ;
V_373 =
F_212 ( V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_143 ,
false ) ;
V_13 = V_216 & V_127 ? V_376 : V_7 -> V_8 . V_13 ;
}
V_108 = V_216 & V_378 ? V_216 & V_379 : 0 ;
V_109 = V_284 -> V_39 ;
if ( V_216 & V_127 )
V_109 = F_201 ( T_14 , V_109 , V_12 -> V_32 . V_240 ) ;
if ( V_216 & V_380 )
V_109 = F_201 ( T_14 , V_109 , ( 1ULL << 32 ) ) ;
if ( V_371 == 0 )
V_371 = V_216 & V_127 ? V_372 :
V_373 ;
if ( V_216 & V_127 && V_371 & ( V_372 - 1 ) ) {
F_222 ( L_10 ,
V_355 ? V_355 -> type : 0 ,
V_371 ) ;
return F_329 ( - V_52 ) ;
}
if ( V_13 > V_109 ) {
F_222 ( L_11 ,
V_355 ? V_355 -> type : 0 ,
V_13 ,
V_216 & V_127 ? L_12 : L_13 ,
V_109 ) ;
return F_329 ( - V_381 ) ;
}
V_19 = F_52 ( V_7 ) ;
if ( V_19 )
return F_329 ( V_19 ) ;
F_79 ( V_7 ) ;
V_34 = V_355 ? F_331 ( V_7 , V_355 ) :
F_332 ( V_7 , V_284 ) ;
if ( F_24 ( V_34 ) )
goto V_382;
if ( V_216 & V_383 ) {
V_374 = V_384 ;
V_375 = V_385 ;
} else {
V_374 = V_386 ;
V_375 = V_387 ;
}
V_388:
V_19 = F_333 ( & V_284 -> V_14 , & V_34 -> V_37 ,
V_13 , V_371 ,
V_7 -> V_9 ,
V_108 , V_109 ,
V_374 ,
V_375 ) ;
if ( V_19 ) {
V_19 = F_334 ( V_2 , V_284 , V_13 , V_371 ,
V_7 -> V_9 ,
V_108 , V_109 ,
V_216 ) ;
if ( V_19 == 0 )
goto V_388;
goto V_389;
}
if ( F_14 ( ! F_326 ( V_34 , V_7 -> V_9 ) ) ) {
V_19 = - V_52 ;
goto V_390;
}
F_335 ( V_34 , V_216 ) ;
V_19 = F_336 ( V_34 , V_7 -> V_9 , V_216 ) ;
if ( V_19 )
goto V_390;
F_245 ( & V_7 -> V_263 , & V_12 -> V_14 . V_286 ) ;
F_165 ( & V_34 -> V_283 , & V_284 -> V_287 ) ;
return V_34 ;
V_390:
F_321 ( & V_34 -> V_37 ) ;
V_389:
F_318 ( V_34 ) ;
V_34 = F_329 ( V_19 ) ;
V_382:
F_96 ( V_7 ) ;
return V_34 ;
}
bool
F_115 ( struct V_6 * V_7 ,
bool V_391 )
{
if ( V_7 -> V_62 == NULL )
return false ;
if ( V_7 -> V_392 || V_7 -> V_46 )
return false ;
if ( ! V_391 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) ) {
V_7 -> V_140 = true ;
return false ;
}
F_337 ( V_7 ) ;
F_338 ( V_7 -> V_62 ) ;
V_7 -> V_140 = false ;
return true ;
}
static void
F_339 ( struct V_6 * V_7 )
{
T_5 V_352 ;
if ( V_7 -> V_8 . V_66 != V_212 )
return;
F_340 () ;
V_352 = V_7 -> V_8 . V_66 ;
V_7 -> V_8 . V_66 = 0 ;
F_59 ( V_7 , false , V_130 ) ;
F_315 ( V_7 ,
V_7 -> V_8 . V_65 ,
V_352 ) ;
}
static void
F_190 ( struct V_6 * V_7 )
{
T_5 V_352 ;
if ( V_7 -> V_8 . V_66 != V_67 )
return;
if ( F_115 ( V_7 , V_7 -> V_10 ) )
F_30 ( V_7 -> V_8 . V_2 ) ;
V_352 = V_7 -> V_8 . V_66 ;
V_7 -> V_8 . V_66 = 0 ;
F_59 ( V_7 , false , V_83 ) ;
F_315 ( V_7 ,
V_7 -> V_8 . V_65 ,
V_352 ) ;
}
int
F_107 ( struct V_6 * V_7 , bool V_235 )
{
T_5 V_352 , V_353 ;
struct V_33 * V_34 ;
int V_19 ;
if ( V_7 -> V_8 . V_66 == V_212 )
return 0 ;
V_19 = F_55 ( V_7 , ! V_235 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_52 ( V_7 ) ;
if ( V_19 )
return V_19 ;
F_190 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_65 & V_212 ) == 0 )
F_314 () ;
V_352 = V_7 -> V_8 . V_66 ;
V_353 = V_7 -> V_8 . V_65 ;
F_37 ( ( V_7 -> V_8 . V_66 & ~ V_212 ) != 0 ) ;
V_7 -> V_8 . V_65 |= V_212 ;
if ( V_235 ) {
V_7 -> V_8 . V_65 = V_212 ;
V_7 -> V_8 . V_66 = V_212 ;
V_7 -> V_69 = 1 ;
}
F_315 ( V_7 ,
V_353 ,
V_352 ) ;
V_34 = F_341 ( V_7 ) ;
if ( V_34 && F_317 ( & V_34 -> V_37 ) && ! V_7 -> V_202 )
F_245 ( & V_34 -> V_283 ,
& F_247 ( V_7 -> V_8 . V_2 ) -> V_32 . V_8 . V_287 ) ;
return 0 ;
}
int F_342 ( struct V_6 * V_7 ,
enum V_3 V_9 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_33 * V_34 , * V_72 ;
bool V_358 = false ;
int V_19 = 0 ;
if ( V_7 -> V_9 == V_9 )
goto V_85;
F_46 (vma, next, &obj->vma_list, vma_link) {
if ( ! F_317 ( & V_34 -> V_37 ) )
continue;
if ( V_34 -> V_36 ) {
F_222 ( L_14 ) ;
return - V_75 ;
}
if ( ! F_326 ( V_34 , V_9 ) ) {
V_19 = F_47 ( V_34 ) ;
if ( V_19 )
return V_19 ;
} else
V_358 = true ;
}
if ( V_358 ) {
V_19 = F_55 ( V_7 , false ) ;
if ( V_19 )
return V_19 ;
if ( ! F_2 ( V_2 ) && V_9 != V_5 ) {
F_208 ( V_7 ) ;
V_19 = F_108 ( V_7 ) ;
if ( V_19 )
return V_19 ;
} else {
}
F_18 (vma, &obj->vma_list, vma_link) {
if ( ! F_317 ( & V_34 -> V_37 ) )
continue;
V_19 = F_336 ( V_34 , V_9 , V_393 ) ;
if ( V_19 )
return V_19 ;
}
}
F_18 (vma, &obj->vma_list, vma_link)
V_34 -> V_37 . V_369 = V_9 ;
V_7 -> V_9 = V_9 ;
V_85:
if ( V_7 -> V_140 &&
V_7 -> V_8 . V_66 != V_67 &&
F_3 ( V_7 ) ) {
if ( F_115 ( V_7 , true ) )
F_30 ( V_7 -> V_8 . V_2 ) ;
}
return 0 ;
}
int F_343 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_394 * args = V_26 ;
struct V_6 * V_7 ;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL )
return - V_120 ;
switch ( V_7 -> V_9 ) {
case V_395 :
case V_396 :
args -> V_397 = V_398 ;
break;
case V_399 :
args -> V_397 = V_400 ;
break;
default:
args -> V_397 = V_401 ;
break;
}
F_68 ( & V_7 -> V_8 ) ;
return 0 ;
}
int F_344 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_394 * args = V_26 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_19 ;
switch ( args -> V_397 ) {
case V_401 :
V_4 = V_5 ;
break;
case V_398 :
if ( F_345 ( V_2 ) && F_346 ( V_2 ) < V_402 )
return - V_180 ;
V_4 = V_395 ;
break;
case V_400 :
V_4 = F_347 ( V_2 ) ? V_399 : V_5 ;
break;
default:
return - V_52 ;
}
F_118 ( V_12 ) ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
goto V_403;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_120 ;
goto V_121;
}
V_19 = F_342 ( V_7 , V_4 ) ;
F_49 ( & V_7 -> V_8 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
V_403:
F_120 ( V_12 ) ;
return V_19 ;
}
int
F_348 ( struct V_6 * V_7 ,
T_6 V_371 ,
struct V_150 * V_404 ,
struct V_158 * * V_405 ,
const struct V_231 * V_232 )
{
T_6 V_353 , V_352 ;
int V_19 ;
V_19 = F_312 ( V_7 , V_404 , V_405 ) ;
if ( V_19 )
return V_19 ;
V_7 -> V_10 ++ ;
V_19 = F_342 ( V_7 ,
F_347 ( V_7 -> V_8 . V_2 ) ? V_399 : V_5 ) ;
if ( V_19 )
goto V_406;
V_19 = F_202 ( V_7 , V_232 , V_371 ,
V_232 -> type == V_356 ?
V_127 : 0 ) ;
if ( V_19 )
goto V_406;
F_190 ( V_7 ) ;
V_352 = V_7 -> V_8 . V_66 ;
V_353 = V_7 -> V_8 . V_65 ;
V_7 -> V_8 . V_66 = 0 ;
V_7 -> V_8 . V_65 |= V_212 ;
F_315 ( V_7 ,
V_353 ,
V_352 ) ;
return 0 ;
V_406:
V_7 -> V_10 -- ;
return V_19 ;
}
void
F_349 ( struct V_6 * V_7 ,
const struct V_231 * V_232 )
{
if ( F_14 ( V_7 -> V_10 == 0 ) )
return;
F_206 ( V_7 , V_232 ) ;
V_7 -> V_10 -- ;
}
int
F_38 ( struct V_6 * V_7 , bool V_235 )
{
T_5 V_352 , V_353 ;
int V_19 ;
if ( V_7 -> V_8 . V_66 == V_67 )
return 0 ;
V_19 = F_55 ( V_7 , ! V_235 ) ;
if ( V_19 )
return V_19 ;
F_339 ( V_7 ) ;
V_352 = V_7 -> V_8 . V_66 ;
V_353 = V_7 -> V_8 . V_65 ;
if ( ( V_7 -> V_8 . V_65 & V_67 ) == 0 ) {
F_115 ( V_7 , false ) ;
V_7 -> V_8 . V_65 |= V_67 ;
}
F_37 ( ( V_7 -> V_8 . V_66 & ~ V_67 ) != 0 ) ;
if ( V_235 ) {
V_7 -> V_8 . V_65 = V_67 ;
V_7 -> V_8 . V_66 = V_67 ;
}
F_315 ( V_7 ,
V_353 ,
V_352 ) ;
return 0 ;
}
static int
F_350 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_189 * V_80 = V_28 -> V_190 ;
unsigned long V_407 = V_176 - V_408 ;
struct V_158 * V_195 , * V_409 = NULL ;
unsigned V_163 ;
int V_19 ;
V_19 = F_8 ( & V_12 -> V_24 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_121 ( & V_12 -> V_24 , false ) ;
if ( V_19 )
return V_19 ;
F_5 ( & V_80 -> V_14 . V_191 ) ;
F_18 (request, &file_priv->mm.request_list, client_list) {
if ( F_155 ( V_195 -> V_178 , V_407 ) )
break;
if ( ! V_195 -> V_178 )
continue;
V_409 = V_195 ;
}
V_163 = F_154 ( & V_12 -> V_24 . V_163 ) ;
if ( V_409 )
F_186 ( V_409 ) ;
F_6 ( & V_80 -> V_14 . V_191 ) ;
if ( V_409 == NULL )
return 0 ;
V_19 = F_140 ( V_409 , V_163 , true , NULL , NULL ) ;
if ( V_19 == 0 )
F_263 ( V_12 -> V_306 , & V_12 -> V_14 . V_307 , 0 ) ;
F_306 ( V_409 ) ;
return V_19 ;
}
static bool
F_351 ( struct V_33 * V_34 , T_5 V_371 , T_4 V_216 )
{
struct V_6 * V_7 = V_34 -> V_7 ;
if ( V_371 &&
V_34 -> V_37 . V_108 & ( V_371 - 1 ) )
return true ;
if ( V_216 & V_127 && ! V_7 -> V_359 )
return true ;
if ( V_216 & V_378 &&
V_34 -> V_37 . V_108 < ( V_216 & V_379 ) )
return true ;
return false ;
}
void F_352 ( struct V_33 * V_34 )
{
struct V_6 * V_7 = V_34 -> V_7 ;
bool V_132 , V_410 ;
T_6 V_376 , V_372 ;
V_376 = F_211 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_143 ) ;
V_372 = F_212 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_143 ,
true ) ;
V_410 = ( V_34 -> V_37 . V_13 == V_376 &&
( V_34 -> V_37 . V_108 & ( V_372 - 1 ) ) == 0 ) ;
V_132 = ( V_34 -> V_37 . V_108 + V_376 <=
F_247 ( V_7 -> V_8 . V_2 ) -> V_32 . V_240 ) ;
V_7 -> V_359 = V_132 && V_410 ;
}
static int
F_353 ( struct V_6 * V_7 ,
struct V_370 * V_284 ,
const struct V_231 * V_355 ,
T_5 V_371 ,
T_4 V_216 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
struct V_33 * V_34 ;
unsigned V_358 ;
int V_19 ;
if ( F_14 ( V_284 == & V_12 -> V_14 . V_411 -> V_8 ) )
return - V_180 ;
if ( F_14 ( V_216 & ( V_412 | V_127 ) && ! F_319 ( V_284 ) ) )
return - V_52 ;
if ( F_14 ( ( V_216 & ( V_127 | V_412 ) ) == V_127 ) )
return - V_52 ;
if ( F_14 ( F_319 ( V_284 ) != ! ! V_355 ) )
return - V_52 ;
V_34 = V_355 ? F_354 ( V_7 , V_355 ) :
F_355 ( V_7 , V_284 ) ;
if ( F_24 ( V_34 ) )
return F_25 ( V_34 ) ;
if ( V_34 ) {
if ( F_14 ( V_34 -> V_36 == V_413 ) )
return - V_75 ;
if ( F_351 ( V_34 , V_371 , V_216 ) ) {
F_145 ( V_34 -> V_36 ,
L_15
L_16
L_17 ,
V_355 ? L_18 : L_19 ,
F_356 ( V_34 -> V_37 . V_108 ) ,
F_357 ( V_34 -> V_37 . V_108 ) ,
V_371 ,
! ! ( V_216 & V_127 ) ,
V_7 -> V_359 ) ;
V_19 = F_47 ( V_34 ) ;
if ( V_19 )
return V_19 ;
V_34 = NULL ;
}
}
V_358 = V_34 ? V_34 -> V_358 : 0 ;
if ( V_34 == NULL || ! F_317 ( & V_34 -> V_37 ) ) {
V_34 = F_328 ( V_7 , V_284 , V_355 , V_371 ,
V_216 ) ;
if ( F_24 ( V_34 ) )
return F_25 ( V_34 ) ;
} else {
V_19 = F_336 ( V_34 , V_7 -> V_9 , V_216 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_355 && V_355 -> type == V_356 &&
( V_358 ^ V_34 -> V_358 ) & V_414 ) {
F_352 ( V_34 ) ;
F_14 ( V_216 & V_127 && ! V_7 -> V_359 ) ;
}
V_34 -> V_36 ++ ;
return 0 ;
}
int
F_358 ( struct V_6 * V_7 ,
struct V_370 * V_284 ,
T_5 V_371 ,
T_4 V_216 )
{
return F_353 ( V_7 , V_284 ,
F_319 ( V_284 ) ? & V_233 : NULL ,
V_371 , V_216 ) ;
}
int
F_202 ( struct V_6 * V_7 ,
const struct V_231 * V_232 ,
T_5 V_371 ,
T_4 V_216 )
{
if ( F_207 ( ! V_232 , L_20 ) )
return - V_52 ;
return F_353 ( V_7 , F_359 ( V_7 ) , V_232 ,
V_371 , V_216 | V_412 ) ;
}
void
F_206 ( struct V_6 * V_7 ,
const struct V_231 * V_232 )
{
struct V_33 * V_34 = F_354 ( V_7 , V_232 ) ;
F_37 ( ! V_34 ) ;
F_14 ( V_34 -> V_36 == 0 ) ;
F_14 ( ! F_360 ( V_7 , V_232 ) ) ;
-- V_34 -> V_36 ;
}
int
F_361 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_415 * args = V_26 ;
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
V_19 = F_304 ( V_7 ) ;
if ( V_19 )
goto V_211;
F_362 ( V_205 > 16 ) ;
args -> V_416 = V_7 -> V_202 << 16 ;
if ( V_7 -> V_203 )
args -> V_416 |= V_7 -> V_203 -> V_151 -> V_152 ;
V_211:
F_49 ( & V_7 -> V_8 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_363 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_80 )
{
return F_350 ( V_2 , V_80 ) ;
}
int
F_364 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_80 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_417 * args = V_26 ;
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
if ( F_365 ( V_7 ) ) {
V_19 = - V_52 ;
goto V_85;
}
if ( V_7 -> V_62 &&
V_7 -> V_143 != V_144 &&
V_12 -> V_275 & V_276 ) {
if ( V_7 -> V_63 == V_71 )
F_96 ( V_7 ) ;
if ( args -> V_63 == V_71 )
F_79 ( V_7 ) ;
}
if ( V_7 -> V_63 != V_64 )
V_7 -> V_63 = args -> V_63 ;
if ( V_7 -> V_63 == V_68 && V_7 -> V_62 == NULL )
F_225 ( V_7 ) ;
args -> V_418 = V_7 -> V_63 != V_64 ;
V_85:
F_49 ( & V_7 -> V_8 ) ;
V_121:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
void F_366 ( struct V_6 * V_7 ,
const struct V_261 * V_77 )
{
int V_51 ;
F_367 ( & V_7 -> V_263 ) ;
for ( V_51 = 0 ; V_51 < V_205 ; V_51 ++ )
F_367 ( & V_7 -> V_281 [ V_51 ] ) ;
F_367 ( & V_7 -> V_419 ) ;
F_367 ( & V_7 -> V_360 ) ;
F_367 ( & V_7 -> V_420 ) ;
V_7 -> V_77 = V_77 ;
V_7 -> V_421 = V_422 ;
V_7 -> V_63 = V_71 ;
F_4 ( V_7 -> V_8 . V_2 -> V_23 , V_7 -> V_8 . V_13 ) ;
}
struct V_6 * F_66 ( struct V_1 * V_2 ,
T_1 V_13 )
{
struct V_6 * V_7 ;
struct V_41 * V_42 ;
T_13 V_423 ;
V_7 = F_60 ( V_2 ) ;
if ( V_7 == NULL )
return NULL ;
if ( F_368 ( V_2 , & V_7 -> V_8 , V_13 ) != 0 ) {
F_62 ( V_7 ) ;
return NULL ;
}
V_423 = V_424 | V_425 ;
if ( F_369 ( V_2 ) || F_370 ( V_2 ) ) {
V_423 &= ~ V_426 ;
V_423 |= V_274 ;
}
V_42 = F_21 ( V_7 -> V_8 . V_43 ) -> V_44 ;
F_371 ( V_42 , V_423 ) ;
F_366 ( V_7 , & V_427 ) ;
V_7 -> V_8 . V_66 = V_67 ;
V_7 -> V_8 . V_65 = V_67 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_9 = V_395 ;
} else
V_7 -> V_9 = V_5 ;
F_372 ( V_7 ) ;
return V_7 ;
}
static bool F_373 ( struct V_6 * V_7 )
{
if ( V_7 -> V_63 != V_71 )
return false ;
if ( V_7 -> V_8 . V_43 == NULL )
return true ;
return F_374 ( & V_7 -> V_8 . V_43 -> V_428 ) == 1 ;
}
void F_375 ( struct V_215 * V_429 )
{
struct V_6 * V_7 = F_99 ( V_429 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_33 * V_34 , * V_72 ;
F_118 ( V_12 ) ;
F_376 ( V_7 ) ;
F_46 (vma, next, &obj->vma_list, vma_link) {
int V_19 ;
V_34 -> V_36 = 0 ;
V_19 = F_47 ( V_34 ) ;
if ( F_14 ( V_19 == - V_184 ) ) {
bool V_430 ;
V_430 = V_12 -> V_14 . V_146 ;
V_12 -> V_14 . V_146 = false ;
F_14 ( F_47 ( V_34 ) ) ;
V_12 -> V_14 . V_146 = V_430 ;
}
}
if ( V_7 -> V_392 )
F_96 ( V_7 ) ;
F_14 ( V_7 -> V_431 ) ;
if ( V_7 -> V_62 && V_7 -> V_63 == V_71 &&
V_12 -> V_275 & V_276 &&
V_7 -> V_143 != V_144 )
F_96 ( V_7 ) ;
if ( F_14 ( V_7 -> V_262 ) )
V_7 -> V_262 = 0 ;
if ( F_373 ( V_7 ) )
V_7 -> V_63 = V_68 ;
F_48 ( V_7 ) ;
F_219 ( V_7 ) ;
F_37 ( V_7 -> V_62 ) ;
if ( V_7 -> V_8 . V_432 )
F_377 ( & V_7 -> V_8 , NULL ) ;
if ( V_7 -> V_77 -> V_433 )
V_7 -> V_77 -> V_433 ( V_7 ) ;
F_378 ( & V_7 -> V_8 ) ;
F_7 ( V_12 , V_7 -> V_8 . V_13 ) ;
F_33 ( V_7 -> V_434 ) ;
F_62 ( V_7 ) ;
F_120 ( V_12 ) ;
}
struct V_33 * F_355 ( struct V_6 * V_7 ,
struct V_370 * V_284 )
{
struct V_33 * V_34 ;
F_18 (vma, &obj->vma_list, vma_link) {
if ( F_319 ( V_34 -> V_284 ) &&
V_34 -> V_355 . type != V_356 )
continue;
if ( V_34 -> V_284 == V_284 )
return V_34 ;
}
return NULL ;
}
struct V_33 * F_354 ( struct V_6 * V_7 ,
const struct V_231 * V_232 )
{
struct V_370 * V_31 = F_359 ( V_7 ) ;
struct V_33 * V_34 ;
if ( F_207 ( ! V_232 , L_20 ) )
return F_329 ( - V_52 ) ;
F_18 (vma, &obj->vma_list, vma_link)
if ( V_34 -> V_284 == V_31 &&
F_379 ( & V_34 -> V_355 , V_232 ) )
return V_34 ;
return NULL ;
}
void F_318 ( struct V_33 * V_34 )
{
struct V_370 * V_284 = NULL ;
F_14 ( V_34 -> V_37 . V_367 ) ;
if ( ! F_147 ( & V_34 -> V_435 ) )
return;
V_284 = V_34 -> V_284 ;
if ( ! F_319 ( V_284 ) )
F_380 ( F_381 ( V_284 ) ) ;
F_169 ( & V_34 -> V_354 ) ;
F_63 ( F_247 ( V_34 -> V_7 -> V_8 . V_2 ) -> V_436 , V_34 ) ;
}
static void
F_382 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_150 * V_151 ;
int V_51 ;
F_249 (ring, dev_priv, i)
V_12 -> V_437 . V_438 ( V_151 ) ;
}
int
F_383 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 = 0 ;
F_17 ( & V_2 -> V_25 ) ;
V_19 = F_323 ( V_2 ) ;
if ( V_19 )
goto V_325;
F_251 ( V_2 ) ;
F_382 ( V_2 ) ;
F_19 ( & V_2 -> V_25 ) ;
F_384 ( & V_12 -> V_24 . V_439 ) ;
F_384 ( & V_12 -> V_14 . V_307 ) ;
F_385 ( & V_12 -> V_14 . V_336 ) ;
F_14 ( V_12 -> V_14 . V_416 ) ;
return 0 ;
V_325:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int F_386 ( struct V_158 * V_159 , int V_440 )
{
struct V_150 * V_151 = V_159 -> V_151 ;
struct V_1 * V_2 = V_151 -> V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
T_6 V_441 = V_442 + ( V_440 * 0x200 ) ;
T_6 * V_443 = V_12 -> V_444 . V_443 [ V_440 ] ;
int V_51 , V_19 ;
if ( ! F_387 ( V_2 ) || ! V_443 )
return 0 ;
V_19 = F_388 ( V_159 , V_445 / 4 * 3 ) ;
if ( V_19 )
return V_19 ;
for ( V_51 = 0 ; V_51 < V_445 ; V_51 += 4 ) {
F_389 ( V_151 , F_390 ( 1 ) ) ;
F_389 ( V_151 , V_441 + V_51 ) ;
F_389 ( V_151 , V_443 [ V_51 / 4 ] ) ;
}
F_391 ( V_151 ) ;
return V_19 ;
}
void F_392 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
if ( F_149 ( V_2 ) -> V_177 < 5 ||
V_12 -> V_14 . V_446 == V_447 )
return;
F_393 ( V_448 , F_394 ( V_448 ) |
V_449 ) ;
if ( F_395 ( V_2 ) )
return;
F_393 ( V_450 , F_394 ( V_450 ) | V_451 ) ;
if ( F_396 ( V_2 ) )
F_393 ( V_452 , F_397 ( V_453 ) ) ;
else if ( F_398 ( V_2 ) )
F_393 ( V_452 , F_397 ( V_454 ) ) ;
else if ( F_399 ( V_2 ) )
F_393 ( V_455 , F_397 ( V_456 ) ) ;
else
F_400 () ;
}
static void F_401 ( struct V_1 * V_2 , T_6 V_8 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
F_393 ( F_402 ( V_8 ) , 0 ) ;
F_393 ( F_403 ( V_8 ) , 0 ) ;
F_393 ( F_404 ( V_8 ) , 0 ) ;
F_393 ( F_405 ( V_8 ) , 0 ) ;
}
static void F_406 ( struct V_1 * V_2 )
{
if ( F_407 ( V_2 ) ) {
F_401 ( V_2 , V_457 ) ;
F_401 ( V_2 , V_458 ) ;
F_401 ( V_2 , V_459 ) ;
F_401 ( V_2 , V_460 ) ;
F_401 ( V_2 , V_461 ) ;
} else if ( F_408 ( V_2 ) ) {
F_401 ( V_2 , V_458 ) ;
F_401 ( V_2 , V_459 ) ;
} else if ( F_409 ( V_2 ) ) {
F_401 ( V_2 , V_457 ) ;
F_401 ( V_2 , V_462 ) ;
}
}
int F_410 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 ;
V_19 = F_411 ( V_2 ) ;
if ( V_19 )
return V_19 ;
if ( F_412 ( V_2 ) ) {
V_19 = F_413 ( V_2 ) ;
if ( V_19 )
goto V_463;
}
if ( F_414 ( V_2 ) ) {
V_19 = F_415 ( V_2 ) ;
if ( V_19 )
goto V_464;
}
if ( F_416 ( V_2 ) ) {
V_19 = F_417 ( V_2 ) ;
if ( V_19 )
goto V_465;
}
if ( F_418 ( V_2 ) ) {
V_19 = F_419 ( V_2 ) ;
if ( V_19 )
goto V_466;
}
return 0 ;
V_466:
F_420 ( & V_12 -> V_151 [ V_467 ] ) ;
V_465:
F_420 ( & V_12 -> V_151 [ V_468 ] ) ;
V_464:
F_420 ( & V_12 -> V_151 [ V_469 ] ) ;
V_463:
F_420 ( & V_12 -> V_151 [ V_470 ] ) ;
return V_19 ;
}
int
F_421 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_150 * V_151 ;
int V_19 , V_51 , V_290 ;
if ( F_149 ( V_2 ) -> V_177 < 6 && ! F_422 () )
return - V_22 ;
F_423 ( V_12 , V_471 ) ;
if ( V_12 -> V_472 )
F_393 ( V_473 , F_394 ( V_473 ) | F_424 ( 0xf ) ) ;
if ( F_425 ( V_2 ) )
F_393 ( V_474 , F_426 ( V_2 ) ?
V_475 : V_476 ) ;
if ( F_427 ( V_2 ) ) {
if ( F_428 ( V_2 ) ) {
T_6 V_477 = F_394 ( V_478 ) ;
V_477 &= ~ ( V_479 | V_480 ) ;
F_393 ( V_478 , V_477 ) ;
} else if ( F_149 ( V_2 ) -> V_177 >= 7 ) {
T_6 V_477 = F_394 ( V_481 ) ;
V_477 &= ~ V_482 ;
F_393 ( V_481 , V_477 ) ;
}
}
F_392 ( V_2 ) ;
F_406 ( V_2 ) ;
F_37 ( ! V_12 -> V_151 [ V_470 ] . V_323 ) ;
V_19 = F_429 ( V_2 ) ;
if ( V_19 ) {
F_11 ( L_21 , V_19 ) ;
goto V_85;
}
F_249 (ring, dev_priv, i) {
V_19 = V_151 -> V_483 ( V_151 ) ;
if ( V_19 )
goto V_85;
}
if ( F_430 ( V_2 ) ) {
V_19 = F_431 ( V_2 ) ;
if ( V_19 ) {
F_11 ( L_22 , V_19 ,
V_117 . V_484 ? L_23 :
L_24 ) ;
V_19 = V_117 . V_484 ? - V_22 : 0 ;
if ( V_19 )
goto V_85;
}
}
V_19 = F_254 ( V_2 , V_12 -> V_293 + 0x100 ) ;
if ( V_19 )
goto V_85;
F_249 (ring, dev_priv, i) {
struct V_158 * V_159 ;
F_14 ( ! V_151 -> V_323 ) ;
V_19 = F_277 ( V_151 , V_151 -> V_323 , & V_159 ) ;
if ( V_19 ) {
F_432 ( V_2 ) ;
goto V_85;
}
if ( V_151 -> V_152 == V_470 ) {
for ( V_290 = 0 ; V_290 < F_433 ( V_2 ) ; V_290 ++ )
F_386 ( V_159 , V_290 ) ;
}
V_19 = F_434 ( V_159 ) ;
if ( V_19 && V_19 != - V_22 ) {
F_11 ( L_25 , V_51 , V_19 ) ;
F_284 ( V_159 ) ;
F_432 ( V_2 ) ;
goto V_85;
}
V_19 = F_435 ( V_159 ) ;
if ( V_19 && V_19 != - V_22 ) {
F_11 ( L_26 , V_51 , V_19 ) ;
F_284 ( V_159 ) ;
F_432 ( V_2 ) ;
goto V_85;
}
F_325 ( V_159 ) ;
}
V_85:
F_436 ( V_12 , V_471 ) ;
return V_19 ;
}
int F_437 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 ;
V_117 . V_298 = F_438 ( V_2 ,
V_117 . V_298 ) ;
F_17 ( & V_2 -> V_25 ) ;
if ( F_439 ( V_2 ) ) {
F_393 ( V_485 , V_486 ) ;
if ( F_440 ( ( F_394 ( V_487 ) &
V_488 ) , 10 ) )
F_441 ( L_27 ) ;
}
if ( ! V_117 . V_298 ) {
V_12 -> V_437 . V_489 = V_490 ;
V_12 -> V_437 . V_491 = F_410 ;
V_12 -> V_437 . V_492 = F_420 ;
V_12 -> V_437 . V_438 = V_493 ;
} else {
V_12 -> V_437 . V_489 = V_494 ;
V_12 -> V_437 . V_491 = V_495 ;
V_12 -> V_437 . V_492 = V_496 ;
V_12 -> V_437 . V_438 = V_497 ;
}
F_423 ( V_12 , V_471 ) ;
V_19 = F_442 ( V_2 ) ;
if ( V_19 )
goto V_498;
F_443 ( V_2 ) ;
V_19 = F_444 ( V_2 ) ;
if ( V_19 )
goto V_498;
V_19 = V_12 -> V_437 . V_491 ( V_2 ) ;
if ( V_19 )
goto V_498;
V_19 = F_421 ( V_2 ) ;
if ( V_19 == - V_22 ) {
F_11 ( L_28 ) ;
F_445 ( V_499 , & V_12 -> V_24 . V_163 ) ;
V_19 = 0 ;
}
V_498:
F_436 ( V_12 , V_471 ) ;
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
void
F_432 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_150 * V_151 ;
int V_51 ;
F_249 (ring, dev_priv, i)
V_12 -> V_437 . V_492 ( V_151 ) ;
if ( V_117 . V_298 )
F_446 ( V_2 ) ;
}
static void
F_447 ( struct V_150 * V_151 )
{
F_367 ( & V_151 -> V_282 ) ;
F_367 ( & V_151 -> V_193 ) ;
}
void
F_448 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_51 ;
V_12 -> V_86 =
F_449 ( L_29 ,
sizeof( struct V_6 ) , 0 ,
V_500 ,
NULL ) ;
V_12 -> V_436 =
F_449 ( L_30 ,
sizeof( struct V_33 ) , 0 ,
V_500 ,
NULL ) ;
V_12 -> V_206 =
F_449 ( L_31 ,
sizeof( struct V_158 ) , 0 ,
V_500 ,
NULL ) ;
F_367 ( & V_12 -> V_501 ) ;
F_367 ( & V_12 -> V_502 ) ;
F_367 ( & V_12 -> V_14 . V_278 ) ;
F_367 ( & V_12 -> V_14 . V_286 ) ;
F_367 ( & V_12 -> V_14 . V_503 ) ;
for ( V_51 = 0 ; V_51 < V_205 ; V_51 ++ )
F_447 ( & V_12 -> V_151 [ V_51 ] ) ;
for ( V_51 = 0 ; V_51 < V_504 ; V_51 ++ )
F_367 ( & V_12 -> V_505 [ V_51 ] . V_506 ) ;
F_450 ( & V_12 -> V_14 . V_307 ,
F_299 ) ;
F_450 ( & V_12 -> V_14 . V_336 ,
F_301 ) ;
F_451 ( & V_12 -> V_24 . V_20 ) ;
V_12 -> V_507 = V_508 ;
if ( F_149 ( V_2 ) -> V_177 >= 7 && ! F_439 ( V_2 ) )
V_12 -> V_509 = 32 ;
else if ( F_149 ( V_2 ) -> V_177 >= 4 || F_452 ( V_2 ) || F_453 ( V_2 ) || F_213 ( V_2 ) )
V_12 -> V_509 = 16 ;
else
V_12 -> V_509 = 8 ;
if ( F_454 ( V_2 ) )
V_12 -> V_509 =
F_394 ( F_455 ( V_510 . V_511 ) ) ;
V_12 -> V_293 = ( ( T_6 ) ~ 0 - 0x1100 ) ;
V_12 -> V_294 = ( ( T_6 ) ~ 0 - 0x1101 ) ;
F_367 ( & V_12 -> V_14 . V_503 ) ;
F_292 ( V_2 ) ;
F_456 ( V_2 ) ;
F_451 ( & V_12 -> V_512 ) ;
V_12 -> V_14 . V_146 = true ;
F_457 ( V_12 ) ;
F_458 ( & V_12 -> V_513 . V_191 ) ;
}
void F_459 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_189 * V_80 = V_28 -> V_190 ;
F_5 ( & V_80 -> V_14 . V_191 ) ;
while ( ! F_147 ( & V_80 -> V_14 . V_193 ) ) {
struct V_158 * V_195 ;
V_195 = F_177 ( & V_80 -> V_14 . V_193 ,
struct V_158 ,
V_192 ) ;
F_169 ( & V_195 -> V_192 ) ;
V_195 -> V_80 = NULL ;
}
F_6 ( & V_80 -> V_14 . V_191 ) ;
if ( ! F_147 ( & V_80 -> V_165 . V_514 ) ) {
F_5 ( & F_247 ( V_2 ) -> V_165 . V_515 ) ;
F_169 ( & V_80 -> V_165 . V_514 ) ;
F_6 ( & F_247 ( V_2 ) -> V_165 . V_515 ) ;
}
}
int F_460 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_189 * V_80 ;
int V_19 ;
F_441 ( L_32 ) ;
V_80 = F_461 ( sizeof( * V_80 ) , V_56 ) ;
if ( ! V_80 )
return - V_57 ;
V_28 -> V_190 = V_80 ;
V_80 -> V_12 = V_2 -> V_23 ;
V_80 -> V_28 = V_28 ;
F_367 ( & V_80 -> V_165 . V_514 ) ;
F_462 ( & V_80 -> V_14 . V_191 ) ;
F_367 ( & V_80 -> V_14 . V_193 ) ;
V_19 = F_463 ( V_2 , V_28 ) ;
if ( V_19 )
F_33 ( V_80 ) ;
return V_19 ;
}
void F_464 ( struct V_6 * V_516 ,
struct V_6 * V_517 ,
unsigned V_431 )
{
if ( V_516 ) {
F_14 ( ! F_180 ( & V_516 -> V_8 . V_2 -> V_25 ) ) ;
F_14 ( ! ( V_516 -> V_431 & V_431 ) ) ;
V_516 -> V_431 &= ~ V_431 ;
}
if ( V_517 ) {
F_14 ( ! F_180 ( & V_517 -> V_8 . V_2 -> V_25 ) ) ;
F_14 ( V_517 -> V_431 & V_431 ) ;
V_517 -> V_431 |= V_431 ;
}
}
T_14 F_465 ( struct V_6 * V_518 ,
struct V_370 * V_284 )
{
struct V_11 * V_12 = V_518 -> V_8 . V_2 -> V_23 ;
struct V_33 * V_34 ;
F_14 ( V_284 == & V_12 -> V_14 . V_411 -> V_8 ) ;
F_18 (vma, &o->vma_list, vma_link) {
if ( F_319 ( V_34 -> V_284 ) &&
V_34 -> V_355 . type != V_356 )
continue;
if ( V_34 -> V_284 == V_284 )
return V_34 -> V_37 . V_108 ;
}
F_145 ( 1 , L_33 ,
F_319 ( V_284 ) ? L_34 : L_19 ) ;
return - 1 ;
}
T_14 F_204 ( struct V_6 * V_518 ,
const struct V_231 * V_232 )
{
struct V_370 * V_31 = F_359 ( V_518 ) ;
struct V_33 * V_34 ;
F_18 (vma, &o->vma_list, vma_link)
if ( V_34 -> V_284 == V_31 &&
F_379 ( & V_34 -> V_355 , V_232 ) )
return V_34 -> V_37 . V_108 ;
F_145 ( 1 , L_35 , V_232 -> type ) ;
return - 1 ;
}
bool F_466 ( struct V_6 * V_518 ,
struct V_370 * V_284 )
{
struct V_33 * V_34 ;
F_18 (vma, &o->vma_list, vma_link) {
if ( F_319 ( V_34 -> V_284 ) &&
V_34 -> V_355 . type != V_356 )
continue;
if ( V_34 -> V_284 == V_284 && F_317 ( & V_34 -> V_37 ) )
return true ;
}
return false ;
}
bool F_360 ( struct V_6 * V_518 ,
const struct V_231 * V_232 )
{
struct V_370 * V_31 = F_359 ( V_518 ) ;
struct V_33 * V_34 ;
F_18 (vma, &o->vma_list, vma_link)
if ( V_34 -> V_284 == V_31 &&
F_379 ( & V_34 -> V_355 , V_232 ) &&
F_317 ( & V_34 -> V_37 ) )
return true ;
return false ;
}
bool F_232 ( struct V_6 * V_518 )
{
struct V_33 * V_34 ;
F_18 (vma, &o->vma_list, vma_link)
if ( F_317 ( & V_34 -> V_37 ) )
return true ;
return false ;
}
unsigned long F_467 ( struct V_6 * V_518 ,
struct V_370 * V_284 )
{
struct V_11 * V_12 = V_518 -> V_8 . V_2 -> V_23 ;
struct V_33 * V_34 ;
F_14 ( V_284 == & V_12 -> V_14 . V_411 -> V_8 ) ;
F_37 ( F_147 ( & V_518 -> V_360 ) ) ;
F_18 (vma, &o->vma_list, vma_link) {
if ( F_319 ( V_34 -> V_284 ) &&
V_34 -> V_355 . type != V_356 )
continue;
if ( V_34 -> V_284 == V_284 )
return V_34 -> V_37 . V_13 ;
}
return 0 ;
}
bool F_365 ( struct V_6 * V_7 )
{
struct V_33 * V_34 ;
F_18 (vma, &obj->vma_list, vma_link)
if ( V_34 -> V_36 > 0 )
return true ;
return false ;
}
struct V_6 *
F_468 ( struct V_1 * V_2 ,
const void * V_26 , T_1 V_13 )
{
struct V_6 * V_7 ;
struct V_47 * V_50 ;
T_1 V_519 ;
int V_19 ;
V_7 = F_66 ( V_2 , F_85 ( V_13 , V_53 ) ) ;
if ( F_469 ( V_7 ) )
return V_7 ;
V_19 = F_38 ( V_7 , true ) ;
if ( V_19 )
goto V_520;
V_19 = F_52 ( V_7 ) ;
if ( V_19 )
goto V_520;
F_79 ( V_7 ) ;
V_50 = V_7 -> V_62 ;
V_519 = F_470 ( V_50 -> V_58 , V_50 -> V_272 , ( void * ) V_26 , V_13 ) ;
F_96 ( V_7 ) ;
if ( F_14 ( V_519 != V_13 ) ) {
F_11 ( L_36 , V_519 , V_13 ) ;
V_19 = - V_76 ;
goto V_520;
}
return V_7 ;
V_520:
F_49 ( & V_7 -> V_8 ) ;
return F_329 ( V_19 ) ;
}

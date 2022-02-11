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
F_18 (vma, &ggtt->base.active_list, vm_link)
if ( V_34 -> V_36 )
V_35 += V_34 -> V_37 . V_13 ;
F_18 (vma, &ggtt->base.inactive_list, vm_link)
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
F_46 (vma, next, &obj->vma_list, obj_link)
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
if ( F_14 ( ( V_7 -> V_77 -> V_103 & V_104 ) == 0 ) )
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
F_80 ( struct V_54 * V_54 , int V_105 , int V_106 ,
char T_3 * V_81 ,
bool V_107 , bool V_102 )
{
char * V_45 ;
int V_19 ;
if ( F_81 ( V_107 ) )
return - V_52 ;
V_45 = F_26 ( V_54 ) ;
if ( V_102 )
F_27 ( V_45 + V_105 ,
V_106 ) ;
V_19 = F_82 ( V_81 ,
V_45 + V_105 ,
V_106 ) ;
F_28 ( V_45 ) ;
return V_19 ? - V_76 : 0 ;
}
static void
F_83 ( char * V_108 , unsigned long V_60 ,
bool V_109 )
{
if ( F_81 ( V_109 ) ) {
unsigned long V_110 = ( unsigned long ) V_108 ;
unsigned long V_111 = ( unsigned long ) V_108 + V_60 ;
V_110 = F_84 ( V_110 , 128 ) ;
V_111 = F_85 ( V_111 , 128 ) ;
F_27 ( ( void * ) V_110 , V_111 - V_110 ) ;
} else {
F_27 ( V_108 , V_60 ) ;
}
}
static int
F_86 ( struct V_54 * V_54 , int V_105 , int V_106 ,
char T_3 * V_81 ,
bool V_107 , bool V_102 )
{
char * V_45 ;
int V_19 ;
V_45 = F_87 ( V_54 ) ;
if ( V_102 )
F_83 ( V_45 + V_105 ,
V_106 ,
V_107 ) ;
if ( V_107 )
V_19 = F_73 ( V_81 ,
V_45 , V_105 ,
V_106 ) ;
else
V_19 = F_75 ( V_81 ,
V_45 + V_105 ,
V_106 ) ;
F_88 ( V_54 ) ;
return V_19 ? - V_76 : 0 ;
}
static int
F_89 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_112 * args ,
struct V_27 * V_28 )
{
char T_3 * V_81 ;
T_7 V_113 ;
T_8 V_59 ;
int V_105 , V_106 , V_19 = 0 ;
int V_114 , V_107 ;
int V_115 = 0 ;
int V_102 = 0 ;
struct V_116 V_117 ;
V_81 = F_54 ( args -> V_82 ) ;
V_113 = args -> V_13 ;
V_114 = F_22 ( V_7 ) ;
V_19 = F_78 ( V_7 , & V_102 ) ;
if ( V_19 )
return V_19 ;
V_59 = args -> V_59 ;
F_90 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_54 * V_54 = F_91 ( & V_117 ) ;
if ( V_113 <= 0 )
break;
V_105 = F_92 ( V_59 ) ;
V_106 = V_113 ;
if ( ( V_105 + V_106 ) > V_53 )
V_106 = V_53 - V_105 ;
V_107 = V_114 &&
( F_93 ( V_54 ) & ( 1 << 17 ) ) != 0 ;
V_19 = F_80 ( V_54 , V_105 , V_106 ,
V_81 , V_107 ,
V_102 ) ;
if ( V_19 == 0 )
goto V_118;
F_19 ( & V_2 -> V_25 ) ;
if ( F_94 ( ! V_119 . V_120 ) && ! V_115 ) {
V_19 = F_95 ( V_81 , V_113 ) ;
( void ) V_19 ;
V_115 = 1 ;
}
V_19 = F_86 ( V_54 , V_105 , V_106 ,
V_81 , V_107 ,
V_102 ) ;
F_17 ( & V_2 -> V_25 ) ;
if ( V_19 )
goto V_85;
V_118:
V_113 -= V_106 ;
V_81 += V_106 ;
V_59 += V_106 ;
}
V_85:
F_96 ( V_7 ) ;
return V_19 ;
}
int
F_97 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_112 * args = V_26 ;
struct V_6 * V_7 ;
int V_19 = 0 ;
if ( args -> V_13 == 0 )
return 0 ;
if ( ! F_98 ( V_121 ,
F_54 ( args -> V_82 ) ,
args -> V_13 ) )
return - V_76 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_122 ;
goto V_123;
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
V_123:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
static inline int
F_102 ( struct V_124 * V_42 ,
T_8 V_125 , int V_126 ,
char T_3 * V_81 ,
int V_60 )
{
void T_9 * V_127 ;
void * V_45 ;
unsigned long V_84 ;
V_127 = F_103 ( V_42 , V_125 ) ;
V_45 = ( void V_128 * ) V_127 + V_126 ;
V_84 = F_57 ( V_45 ,
V_81 , V_60 ) ;
F_104 ( V_127 ) ;
return V_84 ;
}
static int
F_105 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_79 * args ,
struct V_27 * V_28 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
T_7 V_113 ;
T_8 V_59 , V_125 ;
char T_3 * V_81 ;
int V_126 , V_106 , V_19 ;
V_19 = F_106 ( V_7 , 0 , V_129 | V_130 ) ;
if ( V_19 )
goto V_85;
V_19 = F_107 ( V_7 , true ) ;
if ( V_19 )
goto V_131;
V_19 = F_108 ( V_7 ) ;
if ( V_19 )
goto V_131;
V_81 = F_54 ( args -> V_82 ) ;
V_113 = args -> V_13 ;
V_59 = F_109 ( V_7 ) + args -> V_59 ;
F_56 ( V_7 , V_132 ) ;
while ( V_113 > 0 ) {
V_125 = V_59 & V_133 ;
V_126 = F_92 ( V_59 ) ;
V_106 = V_113 ;
if ( ( V_126 + V_113 ) > V_53 )
V_106 = V_53 - V_126 ;
if ( F_102 ( V_12 -> V_32 . V_134 , V_125 ,
V_126 , V_81 , V_106 ) ) {
V_19 = - V_76 ;
goto V_135;
}
V_113 -= V_106 ;
V_81 += V_106 ;
V_59 += V_106 ;
}
V_135:
F_59 ( V_7 , false , V_132 ) ;
V_131:
F_110 ( V_7 ) ;
V_85:
return V_19 ;
}
static int
F_111 ( struct V_54 * V_54 , int V_105 , int V_106 ,
char T_3 * V_81 ,
bool V_107 ,
bool V_136 ,
bool V_137 )
{
char * V_45 ;
int V_19 ;
if ( F_81 ( V_107 ) )
return - V_52 ;
V_45 = F_26 ( V_54 ) ;
if ( V_136 )
F_27 ( V_45 + V_105 ,
V_106 ) ;
V_19 = F_112 ( V_45 + V_105 ,
V_81 , V_106 ) ;
if ( V_137 )
F_27 ( V_45 + V_105 ,
V_106 ) ;
F_28 ( V_45 ) ;
return V_19 ? - V_76 : 0 ;
}
static int
F_113 ( struct V_54 * V_54 , int V_105 , int V_106 ,
char T_3 * V_81 ,
bool V_107 ,
bool V_136 ,
bool V_137 )
{
char * V_45 ;
int V_19 ;
V_45 = F_87 ( V_54 ) ;
if ( F_81 ( V_136 || V_107 ) )
F_83 ( V_45 + V_105 ,
V_106 ,
V_107 ) ;
if ( V_107 )
V_19 = F_76 ( V_45 , V_105 ,
V_81 ,
V_106 ) ;
else
V_19 = F_77 ( V_45 + V_105 ,
V_81 ,
V_106 ) ;
if ( V_137 )
F_83 ( V_45 + V_105 ,
V_106 ,
V_107 ) ;
F_88 ( V_54 ) ;
return V_19 ? - V_76 : 0 ;
}
static int
F_114 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_79 * args ,
struct V_27 * V_28 )
{
T_7 V_113 ;
T_8 V_59 ;
char T_3 * V_81 ;
int V_105 , V_106 , V_19 = 0 ;
int V_114 , V_107 ;
int V_138 = 0 ;
int V_137 = 0 ;
int V_136 = 0 ;
struct V_116 V_117 ;
V_81 = F_54 ( args -> V_82 ) ;
V_113 = args -> V_13 ;
V_114 = F_22 ( V_7 ) ;
if ( V_7 -> V_8 . V_66 != V_67 ) {
V_137 = F_3 ( V_7 ) ;
V_19 = F_55 ( V_7 , false ) ;
if ( V_19 )
return V_19 ;
}
if ( ( V_7 -> V_8 . V_65 & V_67 ) == 0 )
V_136 =
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
struct V_54 * V_54 = F_91 ( & V_117 ) ;
int V_139 ;
if ( V_113 <= 0 )
break;
V_105 = F_92 ( V_59 ) ;
V_106 = V_113 ;
if ( ( V_105 + V_106 ) > V_53 )
V_106 = V_53 - V_105 ;
V_139 = V_136 &&
( ( V_105 | V_106 )
& ( V_140 . V_141 - 1 ) ) ;
V_107 = V_114 &&
( F_93 ( V_54 ) & ( 1 << 17 ) ) != 0 ;
V_19 = F_111 ( V_54 , V_105 , V_106 ,
V_81 , V_107 ,
V_139 ,
V_137 ) ;
if ( V_19 == 0 )
goto V_118;
V_138 = 1 ;
F_19 ( & V_2 -> V_25 ) ;
V_19 = F_113 ( V_54 , V_105 , V_106 ,
V_81 , V_107 ,
V_139 ,
V_137 ) ;
F_17 ( & V_2 -> V_25 ) ;
if ( V_19 )
goto V_85;
V_118:
V_113 -= V_106 ;
V_81 += V_106 ;
V_59 += V_106 ;
}
V_85:
F_96 ( V_7 ) ;
if ( V_138 ) {
if ( ! V_137 &&
V_7 -> V_8 . V_66 != V_67 ) {
if ( F_115 ( V_7 , V_7 -> V_10 ) )
V_137 = true ;
}
}
if ( V_137 )
F_30 ( V_2 ) ;
else
V_7 -> V_142 = true ;
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
if ( ! F_98 ( V_143 ,
F_54 ( args -> V_82 ) ,
args -> V_13 ) )
return - V_76 ;
if ( F_94 ( ! V_119 . V_120 ) ) {
V_19 = F_117 ( F_54 ( args -> V_82 ) ,
args -> V_13 ) ;
if ( V_19 )
return - V_76 ;
}
F_118 ( V_12 ) ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
goto V_144;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_122 ;
goto V_123;
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
if ( V_7 -> V_145 == V_146 &&
V_7 -> V_8 . V_66 != V_67 &&
F_3 ( V_7 ) ) {
V_19 = F_105 ( V_2 , V_7 , args , V_28 ) ;
}
if ( V_19 == - V_76 || V_19 == - V_147 ) {
if ( V_7 -> V_46 )
V_19 = F_53 ( V_7 , args , V_28 ) ;
else
V_19 = F_114 ( V_2 , V_7 , args , V_28 ) ;
}
V_85:
F_49 ( & V_7 -> V_8 ) ;
V_123:
F_19 ( & V_2 -> V_25 ) ;
V_144:
F_120 ( V_12 ) ;
return V_19 ;
}
int
F_121 ( struct V_18 * error ,
bool V_148 )
{
if ( F_122 ( error ) ) {
if ( ! V_148 )
return - V_22 ;
if ( F_123 ( error ) )
return - V_22 ;
if ( ! error -> V_149 )
return - V_150 ;
}
return 0 ;
}
static void F_124 ( unsigned long V_26 )
{
F_125 ( (struct V_151 * ) V_26 ) ;
}
static bool F_126 ( struct V_11 * V_12 ,
struct V_152 * V_153 )
{
return F_127 ( V_153 -> V_154 , & V_12 -> V_24 . V_155 ) ;
}
static unsigned long F_128 ( unsigned * V_156 )
{
unsigned long V_157 ;
* V_156 = F_129 () ;
V_157 = F_130 () >> 10 ;
F_131 () ;
return V_157 ;
}
static bool F_132 ( unsigned long V_158 , unsigned V_156 )
{
unsigned V_159 ;
if ( F_133 ( F_128 ( & V_159 ) , V_158 ) )
return true ;
return V_159 != V_156 ;
}
static int F_134 ( struct V_160 * V_161 , int V_162 )
{
unsigned long V_158 ;
unsigned V_156 ;
if ( V_161 -> V_153 -> V_163 )
return - V_75 ;
if ( ! F_135 ( V_161 , true ) )
return - V_150 ;
V_158 = F_128 ( & V_156 ) + 5 ;
while ( ! F_136 () ) {
if ( F_137 ( V_161 , true ) )
return 0 ;
if ( F_138 ( V_162 , V_164 ) )
break;
if ( F_132 ( V_158 , V_156 ) )
break;
F_139 () ;
}
if ( F_137 ( V_161 , false ) )
return 0 ;
return - V_150 ;
}
int F_140 ( struct V_160 * V_161 ,
unsigned V_165 ,
bool V_148 ,
T_10 * V_158 ,
struct V_166 * V_167 )
{
struct V_152 * V_153 = F_141 ( V_161 ) ;
struct V_1 * V_2 = V_153 -> V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
const bool V_168 =
F_142 ( V_12 -> V_24 . V_169 ) & F_143 ( V_153 ) ;
int V_162 = V_148 ? V_170 : V_171 ;
F_144 ( V_172 ) ;
unsigned long V_173 ;
T_10 V_174 = 0 ;
int V_19 ;
F_145 ( ! F_146 ( V_12 ) , L_2 ) ;
if ( F_147 ( & V_161 -> V_175 ) )
return 0 ;
if ( F_137 ( V_161 , true ) )
return 0 ;
V_173 = 0 ;
if ( V_158 ) {
if ( F_14 ( * V_158 < 0 ) )
return - V_52 ;
if ( * V_158 == 0 )
return - V_176 ;
V_173 = V_177 + F_148 ( * V_158 ) ;
V_174 = F_149 () ;
}
if ( F_150 ( V_12 ) -> V_178 >= 6 )
F_151 ( V_12 , V_167 , V_161 -> V_179 ) ;
F_152 ( V_161 ) ;
V_19 = F_134 ( V_161 , V_162 ) ;
if ( V_19 == 0 )
goto V_85;
if ( ! V_168 && F_14 ( ! V_153 -> V_180 ( V_153 ) ) ) {
V_19 = - V_181 ;
goto V_85;
}
for (; ; ) {
struct V_182 V_183 ;
F_153 ( & V_153 -> V_184 , & V_172 , V_162 ) ;
if ( V_165 != F_154 ( & V_12 -> V_24 . V_165 ) ) {
V_19 = F_121 ( & V_12 -> V_24 , V_148 ) ;
if ( V_19 == 0 )
V_19 = - V_150 ;
break;
}
if ( F_137 ( V_161 , false ) ) {
V_19 = 0 ;
break;
}
if ( F_138 ( V_162 , V_164 ) ) {
V_19 = - V_185 ;
break;
}
if ( V_158 && F_155 ( V_177 , V_173 ) ) {
V_19 = - V_176 ;
break;
}
V_183 . V_186 = NULL ;
if ( V_158 || F_126 ( V_12 , V_153 ) ) {
unsigned long V_187 ;
F_156 ( & V_183 , F_124 , ( unsigned long ) V_164 ) ;
V_187 = F_126 ( V_12 , V_153 ) ? V_177 + 1 : V_173 ;
F_157 ( & V_183 , V_187 ) ;
}
F_158 () ;
if ( V_183 . V_186 ) {
F_159 ( & V_183 ) ;
F_160 ( & V_183 ) ;
}
}
if ( ! V_168 )
V_153 -> V_188 ( V_153 ) ;
F_161 ( & V_153 -> V_184 , & V_172 ) ;
V_85:
F_162 ( V_161 ) ;
if ( V_158 ) {
T_10 V_189 = * V_158 - ( F_149 () - V_174 ) ;
* V_158 = V_189 < 0 ? 0 : V_189 ;
if ( V_19 == - V_176 && * V_158 < F_163 ( 1 ) * 1000 )
* V_158 = 0 ;
}
return V_19 ;
}
int F_164 ( struct V_160 * V_161 ,
struct V_27 * V_28 )
{
struct V_11 * V_23 ;
struct V_190 * V_80 ;
F_14 ( ! V_161 || ! V_28 || V_161 -> V_80 ) ;
if ( ! V_161 || ! V_28 )
return - V_52 ;
if ( V_161 -> V_80 )
return - V_52 ;
V_23 = V_161 -> V_153 -> V_2 -> V_23 ;
V_80 = V_28 -> V_191 ;
F_5 ( & V_80 -> V_14 . V_192 ) ;
V_161 -> V_80 = V_80 ;
F_165 ( & V_161 -> V_193 , & V_80 -> V_14 . V_194 ) ;
F_6 ( & V_80 -> V_14 . V_192 ) ;
V_161 -> V_195 = F_166 ( F_167 ( V_164 ) ) ;
return 0 ;
}
static inline void
F_168 ( struct V_160 * V_196 )
{
struct V_190 * V_80 = V_196 -> V_80 ;
if ( ! V_80 )
return;
F_5 ( & V_80 -> V_14 . V_192 ) ;
F_169 ( & V_196 -> V_193 ) ;
V_196 -> V_80 = NULL ;
F_6 ( & V_80 -> V_14 . V_192 ) ;
F_170 ( V_196 -> V_195 ) ;
V_196 -> V_195 = NULL ;
}
static void F_171 ( struct V_160 * V_196 )
{
F_172 ( V_196 ) ;
V_196 -> V_197 -> V_198 = V_196 -> V_199 ;
F_173 ( & V_196 -> V_175 ) ;
F_168 ( V_196 ) ;
F_174 ( V_196 ) ;
}
static void
F_175 ( struct V_160 * V_161 )
{
struct V_152 * V_200 = V_161 -> V_153 ;
struct V_160 * V_201 ;
F_176 ( & V_200 -> V_2 -> V_25 ) ;
if ( F_147 ( & V_161 -> V_175 ) )
return;
do {
V_201 = F_177 ( & V_200 -> V_194 ,
F_178 ( * V_201 ) , V_175 ) ;
F_171 ( V_201 ) ;
} while ( V_201 != V_161 );
F_14 ( F_15 ( V_200 -> V_2 ) ) ;
}
int
F_179 ( struct V_160 * V_161 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
bool V_148 ;
int V_19 ;
F_37 ( V_161 == NULL ) ;
V_2 = V_161 -> V_153 -> V_2 ;
V_12 = V_2 -> V_23 ;
V_148 = V_12 -> V_14 . V_148 ;
F_37 ( ! F_180 ( & V_2 -> V_25 ) ) ;
V_19 = F_121 ( & V_12 -> V_24 , V_148 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_140 ( V_161 ,
F_154 ( & V_12 -> V_24 . V_165 ) ,
V_148 , NULL , NULL ) ;
if ( V_19 )
return V_19 ;
F_175 ( V_161 ) ;
return 0 ;
}
int
F_55 ( struct V_6 * V_7 ,
bool V_202 )
{
int V_19 , V_51 ;
if ( ! V_7 -> V_203 )
return 0 ;
if ( V_202 ) {
if ( V_7 -> V_204 != NULL ) {
V_19 = F_179 ( V_7 -> V_204 ) ;
if ( V_19 )
return V_19 ;
V_51 = V_7 -> V_204 -> V_153 -> V_154 ;
if ( V_7 -> V_205 [ V_51 ] == V_7 -> V_204 )
F_181 ( V_7 , V_51 ) ;
else
F_182 ( V_7 ) ;
}
} else {
for ( V_51 = 0 ; V_51 < V_206 ; V_51 ++ ) {
if ( V_7 -> V_205 [ V_51 ] == NULL )
continue;
V_19 = F_179 ( V_7 -> V_205 [ V_51 ] ) ;
if ( V_19 )
return V_19 ;
F_181 ( V_7 , V_51 ) ;
}
F_183 ( V_7 -> V_203 ) ;
}
return 0 ;
}
static void
F_184 ( struct V_6 * V_7 ,
struct V_160 * V_161 )
{
int V_153 = V_161 -> V_153 -> V_154 ;
if ( V_7 -> V_205 [ V_153 ] == V_161 )
F_181 ( V_7 , V_153 ) ;
else if ( V_7 -> V_204 == V_161 )
F_182 ( V_7 ) ;
F_175 ( V_161 ) ;
}
static T_11 int
F_185 ( struct V_6 * V_7 ,
struct V_166 * V_167 ,
bool V_202 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_160 * V_207 [ V_206 ] ;
unsigned V_165 ;
int V_19 , V_51 , V_208 = 0 ;
F_37 ( ! F_180 ( & V_2 -> V_25 ) ) ;
F_37 ( ! V_12 -> V_14 . V_148 ) ;
if ( ! V_7 -> V_203 )
return 0 ;
V_19 = F_121 ( & V_12 -> V_24 , true ) ;
if ( V_19 )
return V_19 ;
V_165 = F_154 ( & V_12 -> V_24 . V_165 ) ;
if ( V_202 ) {
struct V_160 * V_161 ;
V_161 = V_7 -> V_204 ;
if ( V_161 == NULL )
return 0 ;
V_207 [ V_208 ++ ] = F_186 ( V_161 ) ;
} else {
for ( V_51 = 0 ; V_51 < V_206 ; V_51 ++ ) {
struct V_160 * V_161 ;
V_161 = V_7 -> V_205 [ V_51 ] ;
if ( V_161 == NULL )
continue;
V_207 [ V_208 ++ ] = F_186 ( V_161 ) ;
}
}
F_19 ( & V_2 -> V_25 ) ;
for ( V_51 = 0 ; V_19 == 0 && V_51 < V_208 ; V_51 ++ )
V_19 = F_140 ( V_207 [ V_51 ] , V_165 , true ,
NULL , V_167 ) ;
F_17 ( & V_2 -> V_25 ) ;
for ( V_51 = 0 ; V_51 < V_208 ; V_51 ++ ) {
if ( V_19 == 0 )
F_184 ( V_7 , V_207 [ V_51 ] ) ;
F_174 ( V_207 [ V_51 ] ) ;
}
return V_19 ;
}
static struct V_166 * F_187 ( struct V_27 * V_28 )
{
struct V_190 * V_209 = V_28 -> V_191 ;
return & V_209 -> V_167 ;
}
int
F_188 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_210 * args = V_26 ;
struct V_6 * V_7 ;
T_5 V_65 = args -> V_65 ;
T_5 V_66 = args -> V_66 ;
int V_19 ;
if ( V_66 & V_211 )
return - V_52 ;
if ( V_65 & V_211 )
return - V_52 ;
if ( V_66 != 0 && V_65 != V_66 )
return - V_52 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_122 ;
goto V_123;
}
V_19 = F_185 ( V_7 ,
F_187 ( V_28 ) ,
! V_66 ) ;
if ( V_19 )
goto V_212;
if ( V_65 & V_213 )
V_19 = F_107 ( V_7 , V_66 != 0 ) ;
else
V_19 = F_38 ( V_7 , V_66 != 0 ) ;
if ( V_66 != 0 )
F_56 ( V_7 ,
V_66 == V_213 ?
V_132 : V_83 ) ;
V_212:
F_49 ( & V_7 -> V_8 ) ;
V_123:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_189 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_214 * args = V_26 ;
struct V_6 * V_7 ;
int V_19 = 0 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_122 ;
goto V_123;
}
if ( V_7 -> V_10 )
F_190 ( V_7 ) ;
F_49 ( & V_7 -> V_8 ) ;
V_123:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_191 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_215 * args = V_26 ;
struct V_216 * V_7 ;
unsigned long V_108 ;
if ( args -> V_103 & ~ ( V_217 ) )
return - V_52 ;
if ( args -> V_103 & V_217 && ! V_218 )
return - V_181 ;
V_7 = F_100 ( V_2 , V_28 , args -> V_88 ) ;
if ( V_7 == NULL )
return - V_122 ;
if ( ! V_7 -> V_43 ) {
F_68 ( V_7 ) ;
return - V_52 ;
}
V_108 = F_192 ( V_7 -> V_43 , 0 , args -> V_13 ,
V_219 | V_220 , V_221 ,
args -> V_59 ) ;
if ( args -> V_103 & V_217 ) {
struct V_222 * V_14 = V_164 -> V_14 ;
struct V_223 * V_34 ;
F_193 ( & V_14 -> V_224 ) ;
V_34 = F_194 ( V_14 , V_108 ) ;
if ( V_34 )
V_34 -> V_225 =
F_195 ( F_196 ( V_34 -> V_226 ) ) ;
else
V_108 = - V_57 ;
F_197 ( & V_14 -> V_224 ) ;
}
F_68 ( V_7 ) ;
if ( F_24 ( ( void * ) V_108 ) )
return V_108 ;
args -> V_227 = ( T_4 ) V_108 ;
return 0 ;
}
int F_198 ( struct V_223 * V_34 , struct V_228 * V_229 )
{
struct V_6 * V_7 = F_99 ( V_34 -> V_230 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_231 V_232 = V_233 ;
T_12 V_126 ;
unsigned long V_234 ;
int V_19 = 0 ;
bool V_235 = ! ! ( V_229 -> V_103 & V_236 ) ;
F_118 ( V_12 ) ;
V_126 = ( ( unsigned long ) V_229 -> V_237 - V_34 -> V_238 ) >>
V_239 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
goto V_85;
F_199 ( V_7 , V_126 , true , V_235 ) ;
V_19 = F_185 ( V_7 , NULL , ! V_235 ) ;
if ( V_19 )
goto V_123;
if ( V_7 -> V_9 != V_5 && ! F_2 ( V_2 ) ) {
V_19 = - V_76 ;
goto V_123;
}
if ( V_7 -> V_8 . V_13 >= V_12 -> V_32 . V_240 &&
V_7 -> V_145 == V_146 ) {
static const unsigned int V_241 = 256 ;
memset ( & V_232 , 0 , sizeof( V_232 ) ) ;
V_232 . type = V_242 ;
V_232 . V_243 . V_244 . V_59 = F_200 ( V_126 , V_241 ) ;
V_232 . V_243 . V_244 . V_13 =
F_201 (unsigned int,
chunk_size,
(vma->vm_end - vma->vm_start)/PAGE_SIZE -
view.params.partial.offset) ;
}
V_19 = F_202 ( V_7 , & V_232 , 0 , V_129 ) ;
if ( V_19 )
goto V_123;
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
V_234 + V_126 ) ;
}
V_245:
F_206 ( V_7 , & V_232 ) ;
V_123:
F_19 ( & V_2 -> V_25 ) ;
V_85:
switch ( V_19 ) {
case - V_22 :
if ( ! F_123 ( & V_12 -> V_24 ) ) {
V_19 = V_248 ;
break;
}
case - V_150 :
case 0 :
case - V_185 :
case - V_249 :
case - V_75 :
V_19 = V_250 ;
break;
case - V_57 :
V_19 = V_251 ;
break;
case - V_147 :
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
F_211 ( struct V_1 * V_2 , T_5 V_13 , int V_145 )
{
T_5 V_254 ;
if ( F_150 ( V_2 ) -> V_178 >= 4 ||
V_145 == V_146 )
return V_13 ;
if ( F_150 ( V_2 ) -> V_178 == 3 )
V_254 = 1024 * 1024 ;
else
V_254 = 512 * 1024 ;
while ( V_254 < V_13 )
V_254 <<= 1 ;
return V_254 ;
}
T_5
F_212 ( struct V_1 * V_2 , T_5 V_13 ,
int V_145 , bool V_255 )
{
if ( F_150 ( V_2 ) -> V_178 >= 4 || ( ! V_255 && F_213 ( V_2 ) ) ||
V_145 == V_146 )
return 4096 ;
return F_211 ( V_2 , V_13 , V_145 ) ;
}
static int F_214 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
int V_19 ;
if ( F_215 ( & V_7 -> V_8 . V_252 ) )
return 0 ;
V_12 -> V_14 . V_256 = true ;
V_19 = F_216 ( & V_7 -> V_8 ) ;
if ( V_19 != - V_147 )
goto V_85;
F_217 ( V_12 ,
V_7 -> V_8 . V_13 >> V_239 ,
V_257 |
V_258 |
V_259 ) ;
V_19 = F_216 ( & V_7 -> V_8 ) ;
if ( V_19 != - V_147 )
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
V_19 = - V_122 ;
goto V_123;
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
V_123:
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
struct V_116 V_117 ;
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
struct V_54 * V_54 = F_91 ( & V_117 ) ;
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
struct V_116 V_117 ;
struct V_54 * V_54 ;
unsigned long V_266 = 0 ;
int V_19 ;
T_13 V_267 ;
F_37 ( V_7 -> V_8 . V_65 & V_211 ) ;
F_37 ( V_7 -> V_8 . V_66 & V_211 ) ;
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
if ( V_7 -> V_145 != V_146 &&
V_12 -> V_275 & V_276 )
F_79 ( V_7 ) ;
return 0 ;
V_273:
F_241 ( V_50 ) ;
F_90 (st->sgl, &sg_iter, st->nents, 0 )
F_29 ( F_91 ( & V_117 ) ) ;
F_41 ( V_48 ) ;
F_33 ( V_48 ) ;
if ( V_19 == - V_147 )
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
struct V_160 * V_161 )
{
struct V_6 * V_7 = V_34 -> V_7 ;
struct V_152 * V_153 ;
V_153 = F_141 ( V_161 ) ;
if ( V_7 -> V_203 == 0 )
F_45 ( & V_7 -> V_8 ) ;
V_7 -> V_203 |= F_143 ( V_153 ) ;
F_245 ( & V_7 -> V_281 [ V_153 -> V_154 ] , & V_153 -> V_282 ) ;
F_246 ( & V_7 -> V_205 [ V_153 -> V_154 ] , V_161 ) ;
F_245 ( & V_34 -> V_283 , & V_34 -> V_284 -> V_282 ) ;
}
static void
F_182 ( struct V_6 * V_7 )
{
F_183 ( V_7 -> V_204 == NULL ) ;
F_183 ( ! ( V_7 -> V_203 & F_143 ( V_7 -> V_204 -> V_153 ) ) ) ;
F_246 ( & V_7 -> V_204 , NULL ) ;
F_59 ( V_7 , true , V_285 ) ;
}
static void
F_181 ( struct V_6 * V_7 , int V_153 )
{
struct V_33 * V_34 ;
F_183 ( V_7 -> V_205 [ V_153 ] == NULL ) ;
F_183 ( ! ( V_7 -> V_203 & ( 1 << V_153 ) ) ) ;
F_173 ( & V_7 -> V_281 [ V_153 ] ) ;
F_246 ( & V_7 -> V_205 [ V_153 ] , NULL ) ;
if ( V_7 -> V_204 && V_7 -> V_204 -> V_153 -> V_154 == V_153 )
F_182 ( V_7 ) ;
V_7 -> V_203 &= ~ ( 1 << V_153 ) ;
if ( V_7 -> V_203 )
return;
F_245 ( & V_7 -> V_263 ,
& F_247 ( V_7 -> V_8 . V_2 ) -> V_14 . V_286 ) ;
F_18 (vma, &obj->vma_list, obj_link) {
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
struct V_152 * V_153 ;
int V_19 , V_51 , V_290 ;
F_249 (ring, dev_priv, i) {
V_19 = F_250 ( V_153 ) ;
if ( V_19 )
return V_19 ;
}
F_251 ( V_2 ) ;
F_249 (ring, dev_priv, i) {
F_252 ( V_153 , V_289 ) ;
for ( V_290 = 0 ; V_290 < F_253 ( V_153 -> V_291 . V_292 ) ; V_290 ++ )
V_153 -> V_291 . V_292 [ V_290 ] = 0 ;
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
void F_256 ( struct V_160 * V_196 ,
struct V_6 * V_7 ,
bool V_295 )
{
struct V_152 * V_153 ;
struct V_11 * V_12 ;
struct V_296 * V_197 ;
T_6 V_297 ;
int V_19 ;
if ( F_14 ( V_196 == NULL ) )
return;
V_153 = V_196 -> V_153 ;
V_12 = V_153 -> V_2 -> V_23 ;
V_197 = V_196 -> V_197 ;
F_257 ( V_197 ) ;
V_297 = F_258 ( V_197 ) ;
if ( V_295 ) {
if ( V_119 . V_298 )
V_19 = F_259 ( V_196 ) ;
else
V_19 = F_260 ( V_196 ) ;
F_145 ( V_19 , L_6 , V_19 ) ;
}
V_196 -> V_199 = F_258 ( V_197 ) ;
if ( V_119 . V_298 )
V_19 = V_153 -> V_299 ( V_196 ) ;
else {
V_19 = V_153 -> V_300 ( V_196 ) ;
V_196 -> V_301 = F_258 ( V_197 ) ;
}
F_145 ( V_19 , L_7 , V_19 ) ;
V_196 -> V_302 = V_297 ;
V_196 -> V_303 = V_7 ;
V_196 -> V_179 = V_177 ;
V_196 -> V_304 = V_153 -> V_305 ;
V_153 -> V_305 = V_196 -> V_289 ;
F_165 ( & V_196 -> V_175 , & V_153 -> V_194 ) ;
F_261 ( V_196 ) ;
F_262 ( V_153 -> V_2 ) ;
F_263 ( V_12 -> V_306 ,
& V_12 -> V_14 . V_307 ,
F_264 ( V_21 ) ) ;
F_265 ( V_12 -> V_2 ) ;
F_266 ( V_197 ) ;
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
struct V_160 * V_161 = F_274 ( V_321 ,
F_178 ( * V_161 ) , V_322 ) ;
struct V_308 * V_309 = V_161 -> V_309 ;
if ( V_161 -> V_80 )
F_168 ( V_161 ) ;
if ( V_309 ) {
if ( V_119 . V_298 && V_309 != V_161 -> V_119 -> V_323 )
F_275 ( V_309 , V_161 -> V_153 ) ;
F_276 ( V_309 ) ;
}
F_63 ( V_161 -> V_119 -> V_207 , V_161 ) ;
}
static inline int
F_277 ( struct V_152 * V_153 ,
struct V_308 * V_309 ,
struct V_160 * * V_324 )
{
struct V_11 * V_12 = F_247 ( V_153 -> V_2 ) ;
struct V_160 * V_161 ;
int V_19 ;
if ( ! V_324 )
return - V_52 ;
* V_324 = NULL ;
V_161 = F_61 ( V_12 -> V_207 , V_56 ) ;
if ( V_161 == NULL )
return - V_57 ;
V_19 = F_255 ( V_153 -> V_2 , & V_161 -> V_289 ) ;
if ( V_19 )
goto V_325;
F_278 ( & V_161 -> V_322 ) ;
V_161 -> V_119 = V_12 ;
V_161 -> V_153 = V_153 ;
V_161 -> V_309 = V_309 ;
F_279 ( V_161 -> V_309 ) ;
if ( V_119 . V_298 )
V_19 = F_280 ( V_161 ) ;
else
V_19 = F_281 ( V_161 ) ;
if ( V_19 ) {
F_276 ( V_161 -> V_309 ) ;
goto V_325;
}
if ( V_119 . V_298 )
V_19 = F_282 ( V_161 ) ;
else
V_19 = F_283 ( V_161 ) ;
if ( V_19 ) {
F_284 ( V_161 ) ;
return V_19 ;
}
* V_324 = V_161 ;
return 0 ;
V_325:
F_63 ( V_12 -> V_207 , V_161 ) ;
return V_19 ;
}
struct V_160 *
F_285 ( struct V_152 * V_200 ,
struct V_308 * V_309 )
{
struct V_160 * V_161 ;
int V_325 ;
if ( V_309 == NULL )
V_309 = F_247 ( V_200 -> V_2 ) -> V_323 ;
V_325 = F_277 ( V_200 , V_309 , & V_161 ) ;
return V_325 ? F_286 ( V_325 ) : V_161 ;
}
void F_284 ( struct V_160 * V_161 )
{
F_287 ( V_161 -> V_197 ) ;
F_174 ( V_161 ) ;
}
struct V_160 *
F_288 ( struct V_152 * V_153 )
{
struct V_160 * V_196 ;
F_18 (request, &ring->request_list, list) {
if ( F_137 ( V_196 , false ) )
continue;
return V_196 ;
}
return NULL ;
}
static void F_289 ( struct V_11 * V_12 ,
struct V_152 * V_153 )
{
struct V_160 * V_196 ;
bool V_326 ;
V_196 = F_288 ( V_153 ) ;
if ( V_196 == NULL )
return;
V_326 = V_153 -> V_327 . V_328 >= V_329 ;
F_272 ( V_12 , V_196 -> V_309 , V_326 ) ;
F_290 (request, &ring->request_list, list)
F_272 ( V_12 , V_196 -> V_309 , false ) ;
}
static void F_291 ( struct V_11 * V_12 ,
struct V_152 * V_153 )
{
struct V_296 * V_330 ;
while ( ! F_147 ( & V_153 -> V_282 ) ) {
struct V_6 * V_7 ;
V_7 = F_177 ( & V_153 -> V_282 ,
struct V_6 ,
V_281 [ V_153 -> V_154 ] ) ;
F_181 ( V_7 , V_153 -> V_154 ) ;
}
if ( V_119 . V_298 ) {
F_292 ( & V_153 -> V_331 ) ;
F_293 ( & V_153 -> V_332 ,
& V_153 -> V_333 ) ;
F_294 ( & V_153 -> V_331 ) ;
F_295 ( V_153 ) ;
}
while ( ! F_147 ( & V_153 -> V_194 ) ) {
struct V_160 * V_196 ;
V_196 = F_177 ( & V_153 -> V_194 ,
struct V_160 ,
V_175 ) ;
F_171 ( V_196 ) ;
}
F_18 (buffer, &ring->buffers, link) {
V_330 -> V_198 = V_330 -> V_301 ;
F_296 ( V_330 ) ;
}
}
void F_297 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_152 * V_153 ;
int V_51 ;
F_249 (ring, dev_priv, i)
F_289 ( V_12 , V_153 ) ;
F_249 (ring, dev_priv, i)
F_291 ( V_12 , V_153 ) ;
F_298 ( V_2 ) ;
F_299 ( V_2 ) ;
F_14 ( F_15 ( V_2 ) ) ;
}
void
F_300 ( struct V_152 * V_153 )
{
F_14 ( F_15 ( V_153 -> V_2 ) ) ;
while ( ! F_147 ( & V_153 -> V_194 ) ) {
struct V_160 * V_196 ;
V_196 = F_177 ( & V_153 -> V_194 ,
struct V_160 ,
V_175 ) ;
if ( ! F_137 ( V_196 , true ) )
break;
F_171 ( V_196 ) ;
}
while ( ! F_147 ( & V_153 -> V_282 ) ) {
struct V_6 * V_7 ;
V_7 = F_177 ( & V_153 -> V_282 ,
struct V_6 ,
V_281 [ V_153 -> V_154 ] ) ;
if ( ! F_147 ( & V_7 -> V_205 [ V_153 -> V_154 ] -> V_175 ) )
break;
F_181 ( V_7 , V_153 -> V_154 ) ;
}
if ( F_81 ( V_153 -> V_334 &&
F_137 ( V_153 -> V_334 , true ) ) ) {
V_153 -> V_188 ( V_153 ) ;
F_246 ( & V_153 -> V_334 , NULL ) ;
}
F_14 ( F_15 ( V_153 -> V_2 ) ) ;
}
bool
F_251 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_152 * V_153 ;
bool V_335 = true ;
int V_51 ;
F_249 (ring, dev_priv, i) {
F_300 ( V_153 ) ;
V_335 &= F_147 ( & V_153 -> V_194 ) ;
if ( V_119 . V_298 ) {
F_292 ( & V_153 -> V_331 ) ;
V_335 &= F_147 ( & V_153 -> V_332 ) ;
F_294 ( & V_153 -> V_331 ) ;
F_295 ( V_153 ) ;
}
}
if ( V_335 )
F_301 ( V_12 -> V_306 ,
& V_12 -> V_14 . V_336 ,
F_302 ( 100 ) ) ;
return V_335 ;
}
static void
F_303 ( struct V_337 * V_338 )
{
struct V_11 * V_12 =
F_274 ( V_338 , F_178 ( * V_12 ) , V_14 . V_307 . V_338 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
bool V_335 ;
V_335 = false ;
if ( F_304 ( & V_2 -> V_25 ) ) {
V_335 = F_251 ( V_2 ) ;
F_19 ( & V_2 -> V_25 ) ;
}
if ( ! V_335 )
F_263 ( V_12 -> V_306 , & V_12 -> V_14 . V_307 ,
F_264 ( V_21 ) ) ;
}
static void
F_305 ( struct V_337 * V_338 )
{
struct V_11 * V_12 =
F_274 ( V_338 , F_178 ( * V_12 ) , V_14 . V_336 . V_338 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_152 * V_153 ;
int V_51 ;
F_249 (ring, dev_priv, i)
if ( ! F_147 ( & V_153 -> V_194 ) )
return;
F_306 ( V_2 ) ;
if ( F_304 ( & V_2 -> V_25 ) ) {
struct V_152 * V_153 ;
int V_51 ;
F_249 (ring, dev_priv, i)
F_307 ( & V_153 -> V_339 ) ;
F_19 ( & V_2 -> V_25 ) ;
}
}
static int
F_308 ( struct V_6 * V_7 )
{
int V_51 ;
if ( ! V_7 -> V_203 )
return 0 ;
for ( V_51 = 0 ; V_51 < V_206 ; V_51 ++ ) {
struct V_160 * V_161 ;
V_161 = V_7 -> V_205 [ V_51 ] ;
if ( V_161 == NULL )
continue;
if ( F_147 ( & V_161 -> V_175 ) )
goto V_340;
if ( F_137 ( V_161 , true ) ) {
F_175 ( V_161 ) ;
V_340:
F_181 ( V_7 , V_51 ) ;
}
}
return 0 ;
}
int
F_309 ( struct V_1 * V_2 , void * V_26 , struct V_27 * V_28 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_341 * args = V_26 ;
struct V_6 * V_7 ;
struct V_160 * V_161 [ V_206 ] ;
unsigned V_165 ;
int V_51 , V_208 = 0 ;
int V_19 ;
if ( args -> V_103 != 0 )
return - V_52 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_342 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_19 ( & V_2 -> V_25 ) ;
return - V_122 ;
}
V_19 = F_308 ( V_7 ) ;
if ( V_19 )
goto V_85;
if ( ! V_7 -> V_203 )
goto V_85;
if ( args -> V_343 == 0 ) {
V_19 = - V_176 ;
goto V_85;
}
F_49 ( & V_7 -> V_8 ) ;
V_165 = F_154 ( & V_12 -> V_24 . V_165 ) ;
for ( V_51 = 0 ; V_51 < V_206 ; V_51 ++ ) {
if ( V_7 -> V_205 [ V_51 ] == NULL )
continue;
V_161 [ V_208 ++ ] = F_186 ( V_7 -> V_205 [ V_51 ] ) ;
}
F_19 ( & V_2 -> V_25 ) ;
for ( V_51 = 0 ; V_51 < V_208 ; V_51 ++ ) {
if ( V_19 == 0 )
V_19 = F_140 ( V_161 [ V_51 ] , V_165 , true ,
args -> V_343 > 0 ? & args -> V_343 : NULL ,
F_187 ( V_28 ) ) ;
F_310 ( V_161 [ V_51 ] ) ;
}
return V_19 ;
V_85:
F_49 ( & V_7 -> V_8 ) ;
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
static int
F_311 ( struct V_6 * V_7 ,
struct V_152 * V_344 ,
struct V_160 * V_345 ,
struct V_160 * * V_346 )
{
struct V_152 * V_347 ;
int V_19 ;
V_347 = F_141 ( V_345 ) ;
if ( V_344 == V_347 )
return 0 ;
if ( F_137 ( V_345 , true ) )
return 0 ;
if ( ! F_312 ( V_7 -> V_8 . V_2 ) ) {
struct V_11 * V_119 = F_247 ( V_7 -> V_8 . V_2 ) ;
V_19 = F_140 ( V_345 ,
F_154 ( & V_119 -> V_24 . V_165 ) ,
V_119 -> V_14 . V_148 ,
NULL ,
& V_119 -> V_167 . V_348 ) ;
if ( V_19 )
return V_19 ;
F_184 ( V_7 , V_345 ) ;
} else {
int V_349 = F_313 ( V_347 , V_344 ) ;
T_6 V_289 = F_314 ( V_345 ) ;
F_14 ( ! V_346 ) ;
if ( V_289 <= V_347 -> V_291 . V_292 [ V_349 ] )
return 0 ;
if ( * V_346 == NULL ) {
struct V_160 * V_161 ;
V_161 = F_285 ( V_344 , NULL ) ;
if ( F_24 ( V_161 ) )
return F_25 ( V_161 ) ;
* V_346 = V_161 ;
}
F_315 ( * V_346 , V_347 , V_345 ) ;
V_19 = V_344 -> V_291 . V_350 ( * V_346 , V_347 , V_289 ) ;
if ( V_19 )
return V_19 ;
V_347 -> V_291 . V_292 [ V_349 ] =
F_314 ( V_7 -> V_205 [ V_347 -> V_154 ] ) ;
}
return 0 ;
}
int
F_316 ( struct V_6 * V_7 ,
struct V_152 * V_344 ,
struct V_160 * * V_346 )
{
const bool V_202 = V_7 -> V_8 . V_351 == 0 ;
struct V_160 * V_161 [ V_206 ] ;
int V_19 , V_51 , V_208 ;
if ( ! V_7 -> V_203 )
return 0 ;
if ( V_344 == NULL )
return F_55 ( V_7 , V_202 ) ;
V_208 = 0 ;
if ( V_202 ) {
if ( V_7 -> V_204 )
V_161 [ V_208 ++ ] = V_7 -> V_204 ;
} else {
for ( V_51 = 0 ; V_51 < V_206 ; V_51 ++ )
if ( V_7 -> V_205 [ V_51 ] )
V_161 [ V_208 ++ ] = V_7 -> V_205 [ V_51 ] ;
}
for ( V_51 = 0 ; V_51 < V_208 ; V_51 ++ ) {
V_19 = F_311 ( V_7 , V_344 , V_161 [ V_51 ] , V_346 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static void F_317 ( struct V_6 * V_7 )
{
T_6 V_352 , V_353 ;
F_208 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_65 & V_213 ) == 0 )
return;
F_318 () ;
V_353 = V_7 -> V_8 . V_65 ;
V_352 = V_7 -> V_8 . V_66 ;
V_7 -> V_8 . V_65 &= ~ V_213 ;
V_7 -> V_8 . V_66 &= ~ V_213 ;
F_319 ( V_7 ,
V_353 ,
V_352 ) ;
}
static int F_320 ( struct V_33 * V_34 , bool V_172 )
{
struct V_6 * V_7 = V_34 -> V_7 ;
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
int V_19 ;
if ( F_147 ( & V_34 -> V_354 ) )
return 0 ;
if ( ! F_321 ( & V_34 -> V_37 ) ) {
F_322 ( V_34 ) ;
return 0 ;
}
if ( V_34 -> V_36 )
return - V_75 ;
F_37 ( V_7 -> V_62 == NULL ) ;
if ( V_172 ) {
V_19 = F_55 ( V_7 , false ) ;
if ( V_19 )
return V_19 ;
}
if ( V_34 -> V_355 && V_34 -> V_356 . type == V_357 ) {
F_317 ( V_7 ) ;
V_19 = F_108 ( V_7 ) ;
if ( V_19 )
return V_19 ;
}
F_323 ( V_34 ) ;
V_34 -> V_284 -> V_358 ( V_34 ) ;
V_34 -> V_359 = 0 ;
F_173 ( & V_34 -> V_283 ) ;
if ( V_34 -> V_355 ) {
if ( V_34 -> V_356 . type == V_357 ) {
V_7 -> V_360 = false ;
} else if ( V_34 -> V_356 . V_62 ) {
F_41 ( V_34 -> V_356 . V_62 ) ;
F_33 ( V_34 -> V_356 . V_62 ) ;
}
V_34 -> V_356 . V_62 = NULL ;
}
F_324 ( & V_34 -> V_37 ) ;
F_322 ( V_34 ) ;
if ( F_147 ( & V_7 -> V_361 ) )
F_245 ( & V_7 -> V_263 , & V_12 -> V_14 . V_278 ) ;
F_96 ( V_7 ) ;
return 0 ;
}
int F_47 ( struct V_33 * V_34 )
{
return F_320 ( V_34 , true ) ;
}
int F_325 ( struct V_33 * V_34 )
{
return F_320 ( V_34 , false ) ;
}
int F_326 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_152 * V_153 ;
int V_19 , V_51 ;
F_249 (ring, dev_priv, i) {
if ( ! V_119 . V_298 ) {
struct V_160 * V_161 ;
V_161 = F_285 ( V_153 , NULL ) ;
if ( F_24 ( V_161 ) )
return F_25 ( V_161 ) ;
V_19 = F_327 ( V_161 ) ;
if ( V_19 ) {
F_284 ( V_161 ) ;
return V_19 ;
}
F_328 ( V_161 ) ;
}
V_19 = F_250 ( V_153 ) ;
if ( V_19 )
return V_19 ;
}
F_14 ( F_15 ( V_2 ) ) ;
return 0 ;
}
static bool F_329 ( struct V_33 * V_34 ,
unsigned long V_9 )
{
struct V_362 * V_363 = & V_34 -> V_37 ;
struct V_362 * V_364 ;
if ( V_34 -> V_284 -> V_14 . V_365 == NULL )
return true ;
if ( ! F_321 ( V_363 ) )
return true ;
if ( F_147 ( & V_363 -> V_366 ) )
return true ;
V_364 = F_330 ( V_363 -> V_366 . V_367 , struct V_362 , V_366 ) ;
if ( V_364 -> V_368 && ! V_364 -> V_369 && V_364 -> V_370 != V_9 )
return false ;
V_364 = F_330 ( V_363 -> V_366 . V_72 , struct V_362 , V_366 ) ;
if ( V_364 -> V_368 && ! V_363 -> V_369 && V_364 -> V_370 != V_9 )
return false ;
return true ;
}
static struct V_33 *
F_331 ( struct V_6 * V_7 ,
struct V_371 * V_284 ,
const struct V_231 * V_356 ,
unsigned V_372 ,
T_4 V_103 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
T_6 V_373 , V_374 ;
T_6 V_375 , V_376 ;
T_14 V_110 , V_111 ;
T_14 V_13 , V_377 ;
struct V_33 * V_34 ;
int V_19 ;
if ( F_332 ( V_284 ) ) {
T_6 V_378 ;
if ( F_14 ( ! V_356 ) )
return F_286 ( - V_52 ) ;
V_378 = F_333 ( V_7 , V_356 ) ;
V_377 = F_211 ( V_2 ,
V_378 ,
V_7 -> V_145 ) ;
V_373 = F_212 ( V_2 ,
V_378 ,
V_7 -> V_145 ,
true ) ;
V_374 = F_212 ( V_2 ,
V_378 ,
V_7 -> V_145 ,
false ) ;
V_13 = V_103 & V_129 ? V_377 : V_378 ;
} else {
V_377 = F_211 ( V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_145 ) ;
V_373 = F_212 ( V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_145 ,
true ) ;
V_374 =
F_212 ( V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_145 ,
false ) ;
V_13 = V_103 & V_129 ? V_377 : V_7 -> V_8 . V_13 ;
}
V_110 = V_103 & V_379 ? V_103 & V_380 : 0 ;
V_111 = V_284 -> V_39 ;
if ( V_103 & V_129 )
V_111 = F_201 ( T_14 , V_111 , V_12 -> V_32 . V_240 ) ;
if ( V_103 & V_381 )
V_111 = F_201 ( T_14 , V_111 , ( 1ULL << 32 ) - V_53 ) ;
if ( V_372 == 0 )
V_372 = V_103 & V_129 ? V_373 :
V_374 ;
if ( V_103 & V_129 && V_372 & ( V_373 - 1 ) ) {
F_222 ( L_10 ,
V_356 ? V_356 -> type : 0 ,
V_372 ) ;
return F_286 ( - V_52 ) ;
}
if ( V_13 > V_111 ) {
F_222 ( L_11 ,
V_356 ? V_356 -> type : 0 ,
V_13 ,
V_103 & V_129 ? L_12 : L_13 ,
V_111 ) ;
return F_286 ( - V_382 ) ;
}
V_19 = F_52 ( V_7 ) ;
if ( V_19 )
return F_286 ( V_19 ) ;
F_79 ( V_7 ) ;
V_34 = V_356 ? F_334 ( V_7 , V_356 ) :
F_335 ( V_7 , V_284 ) ;
if ( F_24 ( V_34 ) )
goto V_383;
if ( V_103 & V_384 ) {
T_4 V_59 = V_103 & V_380 ;
if ( V_59 & ( V_372 - 1 ) || V_59 + V_13 > V_111 ) {
V_19 = - V_52 ;
goto V_385;
}
V_34 -> V_37 . V_110 = V_59 ;
V_34 -> V_37 . V_13 = V_13 ;
V_34 -> V_37 . V_370 = V_7 -> V_9 ;
V_19 = F_336 ( & V_284 -> V_14 , & V_34 -> V_37 ) ;
if ( V_19 ) {
V_19 = F_337 ( V_34 ) ;
if ( V_19 == 0 )
V_19 = F_336 ( & V_284 -> V_14 , & V_34 -> V_37 ) ;
}
if ( V_19 )
goto V_385;
} else {
if ( V_103 & V_386 ) {
V_375 = V_387 ;
V_376 = V_388 ;
} else {
V_375 = V_389 ;
V_376 = V_390 ;
}
V_391:
V_19 = F_338 ( & V_284 -> V_14 , & V_34 -> V_37 ,
V_13 , V_372 ,
V_7 -> V_9 ,
V_110 , V_111 ,
V_375 ,
V_376 ) ;
if ( V_19 ) {
V_19 = F_339 ( V_2 , V_284 , V_13 , V_372 ,
V_7 -> V_9 ,
V_110 , V_111 ,
V_103 ) ;
if ( V_19 == 0 )
goto V_391;
goto V_385;
}
}
if ( F_14 ( ! F_329 ( V_34 , V_7 -> V_9 ) ) ) {
V_19 = - V_52 ;
goto V_392;
}
F_340 ( V_34 , V_103 ) ;
V_19 = F_341 ( V_34 , V_7 -> V_9 , V_103 ) ;
if ( V_19 )
goto V_392;
F_245 ( & V_7 -> V_263 , & V_12 -> V_14 . V_286 ) ;
F_165 ( & V_34 -> V_283 , & V_284 -> V_287 ) ;
return V_34 ;
V_392:
F_324 ( & V_34 -> V_37 ) ;
V_385:
F_322 ( V_34 ) ;
V_34 = F_286 ( V_19 ) ;
V_383:
F_96 ( V_7 ) ;
return V_34 ;
}
bool
F_115 ( struct V_6 * V_7 ,
bool V_393 )
{
if ( V_7 -> V_62 == NULL )
return false ;
if ( V_7 -> V_394 || V_7 -> V_46 )
return false ;
if ( ! V_393 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) ) {
V_7 -> V_142 = true ;
return false ;
}
F_342 ( V_7 ) ;
F_343 ( V_7 -> V_62 ) ;
V_7 -> V_142 = false ;
return true ;
}
static void
F_344 ( struct V_6 * V_7 )
{
T_5 V_352 ;
if ( V_7 -> V_8 . V_66 != V_213 )
return;
F_345 () ;
V_352 = V_7 -> V_8 . V_66 ;
V_7 -> V_8 . V_66 = 0 ;
F_59 ( V_7 , false , V_132 ) ;
F_319 ( V_7 ,
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
F_319 ( V_7 ,
V_7 -> V_8 . V_65 ,
V_352 ) ;
}
int
F_107 ( struct V_6 * V_7 , bool V_235 )
{
T_5 V_352 , V_353 ;
struct V_33 * V_34 ;
int V_19 ;
if ( V_7 -> V_8 . V_66 == V_213 )
return 0 ;
V_19 = F_55 ( V_7 , ! V_235 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_52 ( V_7 ) ;
if ( V_19 )
return V_19 ;
F_190 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_65 & V_213 ) == 0 )
F_318 () ;
V_352 = V_7 -> V_8 . V_66 ;
V_353 = V_7 -> V_8 . V_65 ;
F_37 ( ( V_7 -> V_8 . V_66 & ~ V_213 ) != 0 ) ;
V_7 -> V_8 . V_65 |= V_213 ;
if ( V_235 ) {
V_7 -> V_8 . V_65 = V_213 ;
V_7 -> V_8 . V_66 = V_213 ;
V_7 -> V_69 = 1 ;
}
F_319 ( V_7 ,
V_353 ,
V_352 ) ;
V_34 = F_346 ( V_7 ) ;
if ( V_34 && F_321 ( & V_34 -> V_37 ) && ! V_7 -> V_203 )
F_245 ( & V_34 -> V_283 ,
& F_247 ( V_7 -> V_8 . V_2 ) -> V_32 . V_8 . V_287 ) ;
return 0 ;
}
int F_347 ( struct V_6 * V_7 ,
enum V_3 V_9 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_33 * V_34 , * V_72 ;
bool V_359 = false ;
int V_19 = 0 ;
if ( V_7 -> V_9 == V_9 )
goto V_85;
F_46 (vma, next, &obj->vma_list, obj_link) {
if ( ! F_321 ( & V_34 -> V_37 ) )
continue;
if ( V_34 -> V_36 ) {
F_222 ( L_14 ) ;
return - V_75 ;
}
if ( ! F_329 ( V_34 , V_9 ) ) {
V_19 = F_47 ( V_34 ) ;
if ( V_19 )
return V_19 ;
} else
V_359 = true ;
}
if ( V_359 ) {
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
F_18 (vma, &obj->vma_list, obj_link) {
if ( ! F_321 ( & V_34 -> V_37 ) )
continue;
V_19 = F_341 ( V_34 , V_9 , V_395 ) ;
if ( V_19 )
return V_19 ;
}
}
F_18 (vma, &obj->vma_list, obj_link)
V_34 -> V_37 . V_370 = V_9 ;
V_7 -> V_9 = V_9 ;
V_85:
if ( V_7 -> V_142 &&
V_7 -> V_8 . V_66 != V_67 &&
F_3 ( V_7 ) ) {
if ( F_115 ( V_7 , true ) )
F_30 ( V_7 -> V_8 . V_2 ) ;
}
return 0 ;
}
int F_348 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_396 * args = V_26 ;
struct V_6 * V_7 ;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL )
return - V_122 ;
switch ( V_7 -> V_9 ) {
case V_397 :
case V_398 :
args -> V_399 = V_400 ;
break;
case V_401 :
args -> V_399 = V_402 ;
break;
default:
args -> V_399 = V_403 ;
break;
}
F_68 ( & V_7 -> V_8 ) ;
return 0 ;
}
int F_349 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_396 * args = V_26 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_19 ;
switch ( args -> V_399 ) {
case V_403 :
V_4 = V_5 ;
break;
case V_400 :
if ( F_350 ( V_2 , 0 , V_404 ) )
return - V_181 ;
V_4 = V_397 ;
break;
case V_402 :
V_4 = F_351 ( V_2 ) ? V_401 : V_5 ;
break;
default:
return - V_52 ;
}
F_118 ( V_12 ) ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
goto V_405;
V_7 = F_99 ( F_100 ( V_2 , V_28 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_122 ;
goto V_123;
}
V_19 = F_347 ( V_7 , V_4 ) ;
F_49 ( & V_7 -> V_8 ) ;
V_123:
F_19 ( & V_2 -> V_25 ) ;
V_405:
F_120 ( V_12 ) ;
return V_19 ;
}
int
F_352 ( struct V_6 * V_7 ,
T_6 V_372 ,
const struct V_231 * V_232 )
{
T_6 V_353 , V_352 ;
int V_19 ;
V_7 -> V_10 ++ ;
V_19 = F_347 ( V_7 ,
F_351 ( V_7 -> V_8 . V_2 ) ? V_401 : V_5 ) ;
if ( V_19 )
goto V_406;
V_19 = F_202 ( V_7 , V_232 , V_372 ,
V_232 -> type == V_357 ?
V_129 : 0 ) ;
if ( V_19 )
goto V_406;
F_190 ( V_7 ) ;
V_352 = V_7 -> V_8 . V_66 ;
V_353 = V_7 -> V_8 . V_65 ;
V_7 -> V_8 . V_66 = 0 ;
V_7 -> V_8 . V_65 |= V_213 ;
F_319 ( V_7 ,
V_353 ,
V_352 ) ;
return 0 ;
V_406:
V_7 -> V_10 -- ;
return V_19 ;
}
void
F_353 ( struct V_6 * V_7 ,
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
F_344 ( V_7 ) ;
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
F_319 ( V_7 ,
V_353 ,
V_352 ) ;
return 0 ;
}
static int
F_354 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_190 * V_80 = V_28 -> V_191 ;
unsigned long V_407 = V_177 - V_408 ;
struct V_160 * V_196 , * V_409 = NULL ;
unsigned V_165 ;
int V_19 ;
V_19 = F_8 ( & V_12 -> V_24 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_121 ( & V_12 -> V_24 , false ) ;
if ( V_19 )
return V_19 ;
F_5 ( & V_80 -> V_14 . V_192 ) ;
F_18 (request, &file_priv->mm.request_list, client_list) {
if ( F_155 ( V_196 -> V_179 , V_407 ) )
break;
if ( ! V_196 -> V_179 )
continue;
V_409 = V_196 ;
}
V_165 = F_154 ( & V_12 -> V_24 . V_165 ) ;
if ( V_409 )
F_186 ( V_409 ) ;
F_6 ( & V_80 -> V_14 . V_192 ) ;
if ( V_409 == NULL )
return 0 ;
V_19 = F_140 ( V_409 , V_165 , true , NULL , NULL ) ;
if ( V_19 == 0 )
F_263 ( V_12 -> V_306 , & V_12 -> V_14 . V_307 , 0 ) ;
F_310 ( V_409 ) ;
return V_19 ;
}
static bool
F_355 ( struct V_33 * V_34 , T_5 V_372 , T_4 V_103 )
{
struct V_6 * V_7 = V_34 -> V_7 ;
if ( V_372 &&
V_34 -> V_37 . V_110 & ( V_372 - 1 ) )
return true ;
if ( V_103 & V_129 && ! V_7 -> V_360 )
return true ;
if ( V_103 & V_379 &&
V_34 -> V_37 . V_110 < ( V_103 & V_380 ) )
return true ;
if ( V_103 & V_384 &&
V_34 -> V_37 . V_110 != ( V_103 & V_380 ) )
return true ;
return false ;
}
void F_356 ( struct V_33 * V_34 )
{
struct V_6 * V_7 = V_34 -> V_7 ;
bool V_134 , V_410 ;
T_6 V_377 , V_373 ;
V_377 = F_211 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_145 ) ;
V_373 = F_212 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_145 ,
true ) ;
V_410 = ( V_34 -> V_37 . V_13 == V_377 &&
( V_34 -> V_37 . V_110 & ( V_373 - 1 ) ) == 0 ) ;
V_134 = ( V_34 -> V_37 . V_110 + V_377 <=
F_247 ( V_7 -> V_8 . V_2 ) -> V_32 . V_240 ) ;
V_7 -> V_360 = V_134 && V_410 ;
}
static int
F_357 ( struct V_6 * V_7 ,
struct V_371 * V_284 ,
const struct V_231 * V_356 ,
T_5 V_372 ,
T_4 V_103 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
struct V_33 * V_34 ;
unsigned V_359 ;
int V_19 ;
if ( F_14 ( V_284 == & V_12 -> V_14 . V_411 -> V_8 ) )
return - V_181 ;
if ( F_14 ( V_103 & ( V_412 | V_129 ) && ! F_332 ( V_284 ) ) )
return - V_52 ;
if ( F_14 ( ( V_103 & ( V_129 | V_412 ) ) == V_129 ) )
return - V_52 ;
if ( F_14 ( F_332 ( V_284 ) != ! ! V_356 ) )
return - V_52 ;
V_34 = V_356 ? F_358 ( V_7 , V_356 ) :
F_359 ( V_7 , V_284 ) ;
if ( F_24 ( V_34 ) )
return F_25 ( V_34 ) ;
if ( V_34 ) {
if ( F_14 ( V_34 -> V_36 == V_413 ) )
return - V_75 ;
if ( F_355 ( V_34 , V_372 , V_103 ) ) {
F_145 ( V_34 -> V_36 ,
L_15
L_16
L_17 ,
V_356 ? L_18 : L_19 ,
F_360 ( V_34 -> V_37 . V_110 ) ,
F_361 ( V_34 -> V_37 . V_110 ) ,
V_372 ,
! ! ( V_103 & V_129 ) ,
V_7 -> V_360 ) ;
V_19 = F_47 ( V_34 ) ;
if ( V_19 )
return V_19 ;
V_34 = NULL ;
}
}
V_359 = V_34 ? V_34 -> V_359 : 0 ;
if ( V_34 == NULL || ! F_321 ( & V_34 -> V_37 ) ) {
V_34 = F_331 ( V_7 , V_284 , V_356 , V_372 ,
V_103 ) ;
if ( F_24 ( V_34 ) )
return F_25 ( V_34 ) ;
} else {
V_19 = F_341 ( V_34 , V_7 -> V_9 , V_103 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_356 && V_356 -> type == V_357 &&
( V_359 ^ V_34 -> V_359 ) & V_414 ) {
F_356 ( V_34 ) ;
F_14 ( V_103 & V_129 && ! V_7 -> V_360 ) ;
}
V_34 -> V_36 ++ ;
return 0 ;
}
int
F_362 ( struct V_6 * V_7 ,
struct V_371 * V_284 ,
T_5 V_372 ,
T_4 V_103 )
{
return F_357 ( V_7 , V_284 ,
F_332 ( V_284 ) ? & V_233 : NULL ,
V_372 , V_103 ) ;
}
int
F_202 ( struct V_6 * V_7 ,
const struct V_231 * V_232 ,
T_5 V_372 ,
T_4 V_103 )
{
if ( F_207 ( ! V_232 , L_20 ) )
return - V_52 ;
return F_357 ( V_7 , F_363 ( V_7 ) , V_232 ,
V_372 , V_103 | V_412 ) ;
}
void
F_206 ( struct V_6 * V_7 ,
const struct V_231 * V_232 )
{
struct V_33 * V_34 = F_358 ( V_7 , V_232 ) ;
F_37 ( ! V_34 ) ;
F_14 ( V_34 -> V_36 == 0 ) ;
F_14 ( ! F_364 ( V_7 , V_232 ) ) ;
-- V_34 -> V_36 ;
}
int
F_365 ( struct V_1 * V_2 , void * V_26 ,
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
V_19 = - V_122 ;
goto V_123;
}
V_19 = F_308 ( V_7 ) ;
if ( V_19 )
goto V_212;
args -> V_416 = 0 ;
if ( V_7 -> V_203 ) {
int V_51 ;
for ( V_51 = 0 ; V_51 < V_206 ; V_51 ++ ) {
struct V_160 * V_161 ;
V_161 = V_7 -> V_205 [ V_51 ] ;
if ( V_161 )
args -> V_416 |= 1 << ( 16 + V_161 -> V_153 -> V_417 ) ;
}
if ( V_7 -> V_204 )
args -> V_416 |= V_7 -> V_204 -> V_153 -> V_417 ;
}
V_212:
F_49 ( & V_7 -> V_8 ) ;
V_123:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_366 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_80 )
{
return F_354 ( V_2 , V_80 ) ;
}
int
F_367 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_80 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_418 * args = V_26 ;
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
V_19 = - V_122 ;
goto V_123;
}
if ( F_368 ( V_7 ) ) {
V_19 = - V_52 ;
goto V_85;
}
if ( V_7 -> V_62 &&
V_7 -> V_145 != V_146 &&
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
args -> V_419 = V_7 -> V_63 != V_64 ;
V_85:
F_49 ( & V_7 -> V_8 ) ;
V_123:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
void F_369 ( struct V_6 * V_7 ,
const struct V_261 * V_77 )
{
int V_51 ;
F_370 ( & V_7 -> V_263 ) ;
for ( V_51 = 0 ; V_51 < V_206 ; V_51 ++ )
F_370 ( & V_7 -> V_281 [ V_51 ] ) ;
F_370 ( & V_7 -> V_420 ) ;
F_370 ( & V_7 -> V_361 ) ;
F_370 ( & V_7 -> V_421 ) ;
V_7 -> V_77 = V_77 ;
V_7 -> V_422 = V_423 ;
V_7 -> V_63 = V_71 ;
F_4 ( V_7 -> V_8 . V_2 -> V_23 , V_7 -> V_8 . V_13 ) ;
}
struct V_6 * F_66 ( struct V_1 * V_2 ,
T_1 V_13 )
{
struct V_6 * V_7 ;
struct V_41 * V_42 ;
T_13 V_424 ;
V_7 = F_60 ( V_2 ) ;
if ( V_7 == NULL )
return NULL ;
if ( F_371 ( V_2 , & V_7 -> V_8 , V_13 ) != 0 ) {
F_62 ( V_7 ) ;
return NULL ;
}
V_424 = V_425 | V_426 ;
if ( F_372 ( V_2 ) || F_373 ( V_2 ) ) {
V_424 &= ~ V_427 ;
V_424 |= V_274 ;
}
V_42 = F_21 ( V_7 -> V_8 . V_43 ) -> V_44 ;
F_374 ( V_42 , V_424 ) ;
F_369 ( V_7 , & V_428 ) ;
V_7 -> V_8 . V_66 = V_67 ;
V_7 -> V_8 . V_65 = V_67 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_9 = V_397 ;
} else
V_7 -> V_9 = V_5 ;
F_375 ( V_7 ) ;
return V_7 ;
}
static bool F_376 ( struct V_6 * V_7 )
{
if ( V_7 -> V_63 != V_71 )
return false ;
if ( V_7 -> V_8 . V_43 == NULL )
return true ;
return F_377 ( & V_7 -> V_8 . V_43 -> V_429 ) == 1 ;
}
void F_378 ( struct V_216 * V_430 )
{
struct V_6 * V_7 = F_99 ( V_430 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_33 * V_34 , * V_72 ;
F_118 ( V_12 ) ;
F_379 ( V_7 ) ;
F_46 (vma, next, &obj->vma_list, obj_link) {
int V_19 ;
V_34 -> V_36 = 0 ;
V_19 = F_47 ( V_34 ) ;
if ( F_14 ( V_19 == - V_185 ) ) {
bool V_431 ;
V_431 = V_12 -> V_14 . V_148 ;
V_12 -> V_14 . V_148 = false ;
F_14 ( F_47 ( V_34 ) ) ;
V_12 -> V_14 . V_148 = V_431 ;
}
}
if ( V_7 -> V_394 )
F_96 ( V_7 ) ;
F_14 ( V_7 -> V_432 ) ;
if ( V_7 -> V_62 && V_7 -> V_63 == V_71 &&
V_12 -> V_275 & V_276 &&
V_7 -> V_145 != V_146 )
F_96 ( V_7 ) ;
if ( F_14 ( V_7 -> V_262 ) )
V_7 -> V_262 = 0 ;
if ( F_376 ( V_7 ) )
V_7 -> V_63 = V_68 ;
F_48 ( V_7 ) ;
F_219 ( V_7 ) ;
F_37 ( V_7 -> V_62 ) ;
if ( V_7 -> V_8 . V_433 )
F_380 ( & V_7 -> V_8 , NULL ) ;
if ( V_7 -> V_77 -> V_434 )
V_7 -> V_77 -> V_434 ( V_7 ) ;
F_381 ( & V_7 -> V_8 ) ;
F_7 ( V_12 , V_7 -> V_8 . V_13 ) ;
F_33 ( V_7 -> V_435 ) ;
F_62 ( V_7 ) ;
F_120 ( V_12 ) ;
}
struct V_33 * F_359 ( struct V_6 * V_7 ,
struct V_371 * V_284 )
{
struct V_33 * V_34 ;
F_18 (vma, &obj->vma_list, obj_link) {
if ( V_34 -> V_356 . type == V_357 &&
V_34 -> V_284 == V_284 )
return V_34 ;
}
return NULL ;
}
struct V_33 * F_358 ( struct V_6 * V_7 ,
const struct V_231 * V_232 )
{
struct V_371 * V_31 = F_363 ( V_7 ) ;
struct V_33 * V_34 ;
if ( F_207 ( ! V_232 , L_20 ) )
return F_286 ( - V_52 ) ;
F_18 (vma, &obj->vma_list, obj_link)
if ( V_34 -> V_284 == V_31 &&
F_382 ( & V_34 -> V_356 , V_232 ) )
return V_34 ;
return NULL ;
}
void F_322 ( struct V_33 * V_34 )
{
F_14 ( V_34 -> V_37 . V_368 ) ;
if ( ! F_147 ( & V_34 -> V_436 ) )
return;
if ( ! V_34 -> V_355 )
F_383 ( F_384 ( V_34 -> V_284 ) ) ;
F_169 ( & V_34 -> V_354 ) ;
F_63 ( F_247 ( V_34 -> V_7 -> V_8 . V_2 ) -> V_437 , V_34 ) ;
}
static void
F_385 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_152 * V_153 ;
int V_51 ;
F_249 (ring, dev_priv, i)
V_12 -> V_438 . V_439 ( V_153 ) ;
}
int
F_386 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 = 0 ;
F_17 ( & V_2 -> V_25 ) ;
V_19 = F_326 ( V_2 ) ;
if ( V_19 )
goto V_325;
F_251 ( V_2 ) ;
F_385 ( V_2 ) ;
F_19 ( & V_2 -> V_25 ) ;
F_387 ( & V_12 -> V_24 . V_440 ) ;
F_387 ( & V_12 -> V_14 . V_307 ) ;
F_388 ( & V_12 -> V_14 . V_336 ) ;
F_14 ( V_12 -> V_14 . V_416 ) ;
return 0 ;
V_325:
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int F_389 ( struct V_160 * V_161 , int V_441 )
{
struct V_152 * V_153 = V_161 -> V_153 ;
struct V_1 * V_2 = V_153 -> V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
T_6 * V_442 = V_12 -> V_443 . V_442 [ V_441 ] ;
int V_51 , V_19 ;
if ( ! F_390 ( V_2 ) || ! V_442 )
return 0 ;
V_19 = F_391 ( V_161 , V_444 / 4 * 3 ) ;
if ( V_19 )
return V_19 ;
for ( V_51 = 0 ; V_51 < V_444 / 4 ; V_51 ++ ) {
F_392 ( V_153 , F_393 ( 1 ) ) ;
F_394 ( V_153 , F_395 ( V_441 , V_51 ) ) ;
F_392 ( V_153 , V_442 [ V_51 ] ) ;
}
F_396 ( V_153 ) ;
return V_19 ;
}
void F_397 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
if ( F_150 ( V_2 ) -> V_178 < 5 ||
V_12 -> V_14 . V_445 == V_446 )
return;
F_398 ( V_447 , F_399 ( V_447 ) |
V_448 ) ;
if ( F_400 ( V_2 ) )
return;
F_398 ( V_449 , F_399 ( V_449 ) | V_450 ) ;
if ( F_401 ( V_2 ) )
F_398 ( V_451 , F_402 ( V_452 ) ) ;
else if ( F_403 ( V_2 ) )
F_398 ( V_451 , F_402 ( V_453 ) ) ;
else if ( F_404 ( V_2 ) )
F_398 ( V_454 , F_402 ( V_455 ) ) ;
else
F_405 () ;
}
static void F_406 ( struct V_1 * V_2 , T_6 V_8 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
F_398 ( F_407 ( V_8 ) , 0 ) ;
F_398 ( F_408 ( V_8 ) , 0 ) ;
F_398 ( F_409 ( V_8 ) , 0 ) ;
F_398 ( F_410 ( V_8 ) , 0 ) ;
}
static void F_411 ( struct V_1 * V_2 )
{
if ( F_412 ( V_2 ) ) {
F_406 ( V_2 , V_456 ) ;
F_406 ( V_2 , V_457 ) ;
F_406 ( V_2 , V_458 ) ;
F_406 ( V_2 , V_459 ) ;
F_406 ( V_2 , V_460 ) ;
} else if ( F_413 ( V_2 ) ) {
F_406 ( V_2 , V_457 ) ;
F_406 ( V_2 , V_458 ) ;
} else if ( F_414 ( V_2 ) ) {
F_406 ( V_2 , V_456 ) ;
F_406 ( V_2 , V_461 ) ;
}
}
int F_415 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 ;
V_19 = F_416 ( V_2 ) ;
if ( V_19 )
return V_19 ;
if ( F_417 ( V_2 ) ) {
V_19 = F_418 ( V_2 ) ;
if ( V_19 )
goto V_462;
}
if ( F_419 ( V_2 ) ) {
V_19 = F_420 ( V_2 ) ;
if ( V_19 )
goto V_463;
}
if ( F_421 ( V_2 ) ) {
V_19 = F_422 ( V_2 ) ;
if ( V_19 )
goto V_464;
}
if ( F_423 ( V_2 ) ) {
V_19 = F_424 ( V_2 ) ;
if ( V_19 )
goto V_465;
}
return 0 ;
V_465:
F_425 ( & V_12 -> V_153 [ V_466 ] ) ;
V_464:
F_425 ( & V_12 -> V_153 [ V_467 ] ) ;
V_463:
F_425 ( & V_12 -> V_153 [ V_468 ] ) ;
V_462:
F_425 ( & V_12 -> V_153 [ V_469 ] ) ;
return V_19 ;
}
int
F_426 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_152 * V_153 ;
int V_19 , V_51 , V_290 ;
if ( F_150 ( V_2 ) -> V_178 < 6 && ! F_427 () )
return - V_22 ;
F_428 ( V_12 , V_470 ) ;
if ( V_12 -> V_471 )
F_398 ( V_472 , F_399 ( V_472 ) | F_429 ( 0xf ) ) ;
if ( F_430 ( V_2 ) )
F_398 ( V_473 , F_431 ( V_2 ) ?
V_474 : V_475 ) ;
if ( F_432 ( V_2 ) ) {
if ( F_433 ( V_2 ) ) {
T_6 V_476 = F_399 ( V_477 ) ;
V_476 &= ~ ( V_478 | V_479 ) ;
F_398 ( V_477 , V_476 ) ;
} else if ( F_150 ( V_2 ) -> V_178 >= 7 ) {
T_6 V_476 = F_399 ( V_480 ) ;
V_476 &= ~ V_481 ;
F_398 ( V_480 , V_476 ) ;
}
}
F_397 ( V_2 ) ;
F_411 ( V_2 ) ;
F_37 ( ! V_12 -> V_323 ) ;
V_19 = F_434 ( V_2 ) ;
if ( V_19 ) {
F_11 ( L_21 , V_19 ) ;
goto V_85;
}
F_249 (ring, dev_priv, i) {
V_19 = V_153 -> V_482 ( V_153 ) ;
if ( V_19 )
goto V_85;
}
if ( F_435 ( V_2 ) ) {
V_19 = F_436 ( V_2 ) ;
if ( V_19 ) {
F_11 ( L_22 , V_19 ) ;
V_19 = - V_22 ;
goto V_85;
}
}
V_19 = F_254 ( V_2 , V_12 -> V_293 + 0x100 ) ;
if ( V_19 )
goto V_85;
F_249 (ring, dev_priv, i) {
struct V_160 * V_161 ;
V_161 = F_285 ( V_153 , NULL ) ;
if ( F_24 ( V_161 ) ) {
V_19 = F_25 ( V_161 ) ;
F_437 ( V_2 ) ;
goto V_85;
}
if ( V_153 -> V_154 == V_469 ) {
for ( V_290 = 0 ; V_290 < F_438 ( V_2 ) ; V_290 ++ )
F_389 ( V_161 , V_290 ) ;
}
V_19 = F_439 ( V_161 ) ;
if ( V_19 && V_19 != - V_22 ) {
F_11 ( L_23 , V_51 , V_19 ) ;
F_284 ( V_161 ) ;
F_437 ( V_2 ) ;
goto V_85;
}
V_19 = F_440 ( V_161 ) ;
if ( V_19 && V_19 != - V_22 ) {
F_11 ( L_24 , V_51 , V_19 ) ;
F_284 ( V_161 ) ;
F_437 ( V_2 ) ;
goto V_85;
}
F_328 ( V_161 ) ;
}
V_85:
F_441 ( V_12 , V_470 ) ;
return V_19 ;
}
int F_442 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 ;
V_119 . V_298 = F_443 ( V_2 ,
V_119 . V_298 ) ;
F_17 ( & V_2 -> V_25 ) ;
if ( ! V_119 . V_298 ) {
V_12 -> V_438 . V_483 = V_484 ;
V_12 -> V_438 . V_485 = F_415 ;
V_12 -> V_438 . V_486 = F_425 ;
V_12 -> V_438 . V_439 = V_487 ;
} else {
V_12 -> V_438 . V_483 = V_488 ;
V_12 -> V_438 . V_485 = V_489 ;
V_12 -> V_438 . V_486 = V_490 ;
V_12 -> V_438 . V_439 = V_491 ;
}
F_428 ( V_12 , V_470 ) ;
V_19 = F_444 ( V_2 ) ;
if ( V_19 )
goto V_492;
F_445 ( V_2 ) ;
V_19 = F_446 ( V_2 ) ;
if ( V_19 )
goto V_492;
V_19 = V_12 -> V_438 . V_485 ( V_2 ) ;
if ( V_19 )
goto V_492;
V_19 = F_426 ( V_2 ) ;
if ( V_19 == - V_22 ) {
F_11 ( L_25 ) ;
F_447 ( V_493 , & V_12 -> V_24 . V_165 ) ;
V_19 = 0 ;
}
V_492:
F_441 ( V_12 , V_470 ) ;
F_19 ( & V_2 -> V_25 ) ;
return V_19 ;
}
void
F_437 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_152 * V_153 ;
int V_51 ;
F_249 (ring, dev_priv, i)
V_12 -> V_438 . V_486 ( V_153 ) ;
if ( V_119 . V_298 )
F_448 ( V_2 ) ;
}
static void
F_449 ( struct V_152 * V_153 )
{
F_370 ( & V_153 -> V_282 ) ;
F_370 ( & V_153 -> V_194 ) ;
}
void
F_450 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_51 ;
V_12 -> V_86 =
F_451 ( L_26 ,
sizeof( struct V_6 ) , 0 ,
V_494 ,
NULL ) ;
V_12 -> V_437 =
F_451 ( L_27 ,
sizeof( struct V_33 ) , 0 ,
V_494 ,
NULL ) ;
V_12 -> V_207 =
F_451 ( L_28 ,
sizeof( struct V_160 ) , 0 ,
V_494 ,
NULL ) ;
F_370 ( & V_12 -> V_495 ) ;
F_370 ( & V_12 -> V_496 ) ;
F_370 ( & V_12 -> V_14 . V_278 ) ;
F_370 ( & V_12 -> V_14 . V_286 ) ;
F_370 ( & V_12 -> V_14 . V_497 ) ;
for ( V_51 = 0 ; V_51 < V_206 ; V_51 ++ )
F_449 ( & V_12 -> V_153 [ V_51 ] ) ;
for ( V_51 = 0 ; V_51 < V_498 ; V_51 ++ )
F_370 ( & V_12 -> V_499 [ V_51 ] . V_500 ) ;
F_452 ( & V_12 -> V_14 . V_307 ,
F_303 ) ;
F_452 ( & V_12 -> V_14 . V_336 ,
F_305 ) ;
F_453 ( & V_12 -> V_24 . V_20 ) ;
V_12 -> V_501 = V_502 ;
if ( F_150 ( V_2 ) -> V_178 >= 7 && ! F_454 ( V_2 ) && ! F_455 ( V_2 ) )
V_12 -> V_503 = 32 ;
else if ( F_150 ( V_2 ) -> V_178 >= 4 || F_456 ( V_2 ) || F_457 ( V_2 ) || F_213 ( V_2 ) )
V_12 -> V_503 = 16 ;
else
V_12 -> V_503 = 8 ;
if ( F_458 ( V_2 ) )
V_12 -> V_503 =
F_399 ( F_459 ( V_504 . V_505 ) ) ;
V_12 -> V_293 = ( ( T_6 ) ~ 0 - 0x1100 ) ;
V_12 -> V_294 = ( ( T_6 ) ~ 0 - 0x1101 ) ;
F_370 ( & V_12 -> V_14 . V_497 ) ;
F_299 ( V_2 ) ;
F_460 ( V_2 ) ;
F_453 ( & V_12 -> V_506 ) ;
V_12 -> V_14 . V_148 = true ;
F_461 ( & V_12 -> V_507 . V_192 ) ;
}
void F_462 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_247 ( V_2 ) ;
F_463 ( V_12 -> V_207 ) ;
F_463 ( V_12 -> V_437 ) ;
F_463 ( V_12 -> V_86 ) ;
}
void F_464 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_190 * V_80 = V_28 -> V_191 ;
F_5 ( & V_80 -> V_14 . V_192 ) ;
while ( ! F_147 ( & V_80 -> V_14 . V_194 ) ) {
struct V_160 * V_196 ;
V_196 = F_177 ( & V_80 -> V_14 . V_194 ,
struct V_160 ,
V_193 ) ;
F_169 ( & V_196 -> V_193 ) ;
V_196 -> V_80 = NULL ;
}
F_6 ( & V_80 -> V_14 . V_192 ) ;
if ( ! F_147 ( & V_80 -> V_167 . V_508 ) ) {
F_5 ( & F_247 ( V_2 ) -> V_167 . V_509 ) ;
F_169 ( & V_80 -> V_167 . V_508 ) ;
F_6 ( & F_247 ( V_2 ) -> V_167 . V_509 ) ;
}
}
int F_465 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_190 * V_80 ;
int V_19 ;
F_466 ( L_29 ) ;
V_80 = F_467 ( sizeof( * V_80 ) , V_56 ) ;
if ( ! V_80 )
return - V_57 ;
V_28 -> V_191 = V_80 ;
V_80 -> V_12 = V_2 -> V_23 ;
V_80 -> V_28 = V_28 ;
F_370 ( & V_80 -> V_167 . V_508 ) ;
F_468 ( & V_80 -> V_14 . V_192 ) ;
F_370 ( & V_80 -> V_14 . V_194 ) ;
V_80 -> V_510 = - 1 ;
V_19 = F_469 ( V_2 , V_28 ) ;
if ( V_19 )
F_33 ( V_80 ) ;
return V_19 ;
}
void F_470 ( struct V_6 * V_511 ,
struct V_6 * V_512 ,
unsigned V_432 )
{
if ( V_511 ) {
F_14 ( ! F_180 ( & V_511 -> V_8 . V_2 -> V_25 ) ) ;
F_14 ( ! ( V_511 -> V_432 & V_432 ) ) ;
V_511 -> V_432 &= ~ V_432 ;
}
if ( V_512 ) {
F_14 ( ! F_180 ( & V_512 -> V_8 . V_2 -> V_25 ) ) ;
F_14 ( V_512 -> V_432 & V_432 ) ;
V_512 -> V_432 |= V_432 ;
}
}
T_14 F_471 ( struct V_6 * V_513 ,
struct V_371 * V_284 )
{
struct V_11 * V_12 = V_513 -> V_8 . V_2 -> V_23 ;
struct V_33 * V_34 ;
F_14 ( V_284 == & V_12 -> V_14 . V_411 -> V_8 ) ;
F_18 (vma, &o->vma_list, obj_link) {
if ( V_34 -> V_355 &&
V_34 -> V_356 . type != V_357 )
continue;
if ( V_34 -> V_284 == V_284 )
return V_34 -> V_37 . V_110 ;
}
F_145 ( 1 , L_30 ,
F_332 ( V_284 ) ? L_31 : L_19 ) ;
return - 1 ;
}
T_14 F_204 ( struct V_6 * V_513 ,
const struct V_231 * V_232 )
{
struct V_371 * V_31 = F_363 ( V_513 ) ;
struct V_33 * V_34 ;
F_18 (vma, &o->vma_list, obj_link)
if ( V_34 -> V_284 == V_31 &&
F_382 ( & V_34 -> V_356 , V_232 ) )
return V_34 -> V_37 . V_110 ;
F_145 ( 1 , L_32 , V_232 -> type ) ;
return - 1 ;
}
bool F_472 ( struct V_6 * V_513 ,
struct V_371 * V_284 )
{
struct V_33 * V_34 ;
F_18 (vma, &o->vma_list, obj_link) {
if ( V_34 -> V_355 &&
V_34 -> V_356 . type != V_357 )
continue;
if ( V_34 -> V_284 == V_284 && F_321 ( & V_34 -> V_37 ) )
return true ;
}
return false ;
}
bool F_364 ( struct V_6 * V_513 ,
const struct V_231 * V_232 )
{
struct V_371 * V_31 = F_363 ( V_513 ) ;
struct V_33 * V_34 ;
F_18 (vma, &o->vma_list, obj_link)
if ( V_34 -> V_284 == V_31 &&
F_382 ( & V_34 -> V_356 , V_232 ) &&
F_321 ( & V_34 -> V_37 ) )
return true ;
return false ;
}
bool F_232 ( struct V_6 * V_513 )
{
struct V_33 * V_34 ;
F_18 (vma, &o->vma_list, obj_link)
if ( F_321 ( & V_34 -> V_37 ) )
return true ;
return false ;
}
unsigned long F_473 ( struct V_6 * V_513 ,
struct V_371 * V_284 )
{
struct V_11 * V_12 = V_513 -> V_8 . V_2 -> V_23 ;
struct V_33 * V_34 ;
F_14 ( V_284 == & V_12 -> V_14 . V_411 -> V_8 ) ;
F_37 ( F_147 ( & V_513 -> V_361 ) ) ;
F_18 (vma, &o->vma_list, obj_link) {
if ( V_34 -> V_355 &&
V_34 -> V_356 . type != V_357 )
continue;
if ( V_34 -> V_284 == V_284 )
return V_34 -> V_37 . V_13 ;
}
return 0 ;
}
bool F_368 ( struct V_6 * V_7 )
{
struct V_33 * V_34 ;
F_18 (vma, &obj->vma_list, obj_link)
if ( V_34 -> V_36 > 0 )
return true ;
return false ;
}
struct V_54 *
F_474 ( struct V_6 * V_7 , int V_208 )
{
struct V_54 * V_54 ;
if ( F_14 ( ( V_7 -> V_77 -> V_103 & V_104 ) == 0 ) )
return NULL ;
V_54 = F_475 ( V_7 , V_208 ) ;
F_39 ( V_54 ) ;
return V_54 ;
}
struct V_6 *
F_476 ( struct V_1 * V_2 ,
const void * V_26 , T_1 V_13 )
{
struct V_6 * V_7 ;
struct V_47 * V_50 ;
T_1 V_514 ;
int V_19 ;
V_7 = F_66 ( V_2 , F_85 ( V_13 , V_53 ) ) ;
if ( F_477 ( V_7 ) )
return V_7 ;
V_19 = F_38 ( V_7 , true ) ;
if ( V_19 )
goto V_515;
V_19 = F_52 ( V_7 ) ;
if ( V_19 )
goto V_515;
F_79 ( V_7 ) ;
V_50 = V_7 -> V_62 ;
V_514 = F_478 ( V_50 -> V_58 , V_50 -> V_272 , ( void * ) V_26 , V_13 ) ;
V_7 -> V_69 = 1 ;
F_96 ( V_7 ) ;
if ( F_14 ( V_514 != V_13 ) ) {
F_11 ( L_33 , V_514 , V_13 ) ;
V_19 = - V_76 ;
goto V_515;
}
return V_7 ;
V_515:
F_49 ( & V_7 -> V_8 ) ;
return F_286 ( V_19 ) ;
}

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
int
F_18 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_33 * args = V_30 ;
struct V_6 * V_7 ;
T_1 V_34 ;
V_34 = 0 ;
F_19 ( & V_2 -> V_29 ) ;
F_20 (obj, &dev_priv->mm.bound_list, global_list)
if ( F_21 ( V_7 ) )
V_34 += F_22 ( V_7 ) ;
F_23 ( & V_2 -> V_29 ) ;
args -> V_35 = V_16 -> V_36 . V_8 . V_37 ;
args -> V_38 = args -> V_35 - V_34 ;
return 0 ;
}
static int
F_24 ( struct V_6 * V_7 )
{
struct V_39 * V_40 = F_25 ( V_7 -> V_8 . V_41 ) -> V_42 ;
char * V_43 = V_7 -> V_44 -> V_43 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
int V_49 ;
if ( F_16 ( F_26 ( V_7 ) ) )
return - V_50 ;
for ( V_49 = 0 ; V_49 < V_7 -> V_8 . V_17 / V_51 ; V_49 ++ ) {
struct V_52 * V_52 ;
char * V_53 ;
V_52 = F_27 ( V_40 , V_49 ) ;
if ( F_28 ( V_52 ) )
return F_29 ( V_52 ) ;
V_53 = F_30 ( V_52 ) ;
memcpy ( V_43 , V_53 , V_51 ) ;
F_31 ( V_43 , V_51 ) ;
F_32 ( V_53 ) ;
F_33 ( V_52 ) ;
V_43 += V_51 ;
}
F_34 ( V_7 -> V_8 . V_2 ) ;
V_46 = F_35 ( sizeof( * V_46 ) , V_54 ) ;
if ( V_46 == NULL )
return - V_55 ;
if ( F_36 ( V_46 , 1 , V_54 ) ) {
F_37 ( V_46 ) ;
return - V_55 ;
}
V_48 = V_46 -> V_56 ;
V_48 -> V_57 = 0 ;
V_48 -> V_58 = V_7 -> V_8 . V_17 ;
F_38 ( V_48 ) = V_7 -> V_44 -> V_59 ;
F_39 ( V_48 ) = V_7 -> V_8 . V_17 ;
V_7 -> V_60 = V_46 ;
return 0 ;
}
static void
F_40 ( struct V_6 * V_7 )
{
int V_23 ;
F_41 ( V_7 -> V_61 == V_62 ) ;
V_23 = F_42 ( V_7 , true ) ;
if ( V_23 ) {
F_16 ( V_23 != - V_26 ) ;
V_7 -> V_8 . V_63 = V_7 -> V_8 . V_64 = V_65 ;
}
if ( V_7 -> V_61 == V_66 )
V_7 -> V_67 = 0 ;
if ( V_7 -> V_67 ) {
struct V_39 * V_40 = F_25 ( V_7 -> V_8 . V_41 ) -> V_42 ;
char * V_43 = V_7 -> V_44 -> V_43 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_7 -> V_8 . V_17 / V_51 ; V_49 ++ ) {
struct V_52 * V_52 ;
char * V_68 ;
V_52 = F_27 ( V_40 , V_49 ) ;
if ( F_28 ( V_52 ) )
continue;
V_68 = F_30 ( V_52 ) ;
F_31 ( V_43 , V_51 ) ;
memcpy ( V_68 , V_43 , V_51 ) ;
F_32 ( V_68 ) ;
F_43 ( V_52 ) ;
if ( V_7 -> V_61 == V_69 )
F_44 ( V_52 ) ;
F_33 ( V_52 ) ;
V_43 += V_51 ;
}
V_7 -> V_67 = 0 ;
}
F_45 ( V_7 -> V_60 ) ;
F_37 ( V_7 -> V_60 ) ;
}
static void
F_46 ( struct V_6 * V_7 )
{
F_47 ( V_7 -> V_8 . V_2 , V_7 -> V_44 ) ;
}
static int
F_48 ( struct V_6 * V_7 )
{
struct V_70 * V_71 , * V_72 ;
int V_23 ;
F_49 ( & V_7 -> V_8 ) ;
F_50 (vma, next, &obj->vma_list, vma_link)
if ( F_51 ( V_71 ) )
break;
V_23 = F_52 ( V_7 ) ;
F_53 ( & V_7 -> V_8 ) ;
return V_23 ;
}
int
F_54 ( struct V_6 * V_7 ,
int V_73 )
{
T_2 * V_74 ;
int V_23 ;
if ( V_7 -> V_44 ) {
if ( ( unsigned long ) V_7 -> V_44 -> V_43 & ( V_73 - 1 ) )
return - V_75 ;
return 0 ;
}
if ( V_7 -> V_61 != V_69 )
return - V_76 ;
if ( V_7 -> V_8 . V_41 == NULL )
return - V_50 ;
V_23 = F_48 ( V_7 ) ;
if ( V_23 )
return V_23 ;
V_74 = F_55 ( V_7 -> V_8 . V_2 , V_7 -> V_8 . V_17 , V_73 ) ;
if ( ! V_74 )
return - V_55 ;
V_7 -> V_44 = V_74 ;
V_7 -> V_77 = & V_78 ;
return F_56 ( V_7 ) ;
}
static int
F_57 ( struct V_6 * V_7 ,
struct V_79 * args ,
struct V_31 * V_80 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
void * V_43 = V_7 -> V_44 -> V_43 + args -> V_57 ;
char T_3 * V_81 = F_58 ( args -> V_82 ) ;
int V_23 = 0 ;
V_23 = F_59 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
F_60 ( V_7 , NULL , V_83 ) ;
if ( F_61 ( V_43 , V_81 , args -> V_17 ) ) {
unsigned long V_84 ;
F_23 ( & V_2 -> V_29 ) ;
V_84 = F_62 ( V_43 , V_81 , args -> V_17 ) ;
F_19 ( & V_2 -> V_29 ) ;
if ( V_84 ) {
V_23 = - V_76 ;
goto V_85;
}
}
F_31 ( V_43 , args -> V_17 ) ;
F_34 ( V_2 ) ;
V_85:
F_63 ( V_7 , false ) ;
return V_23 ;
}
void * F_64 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
return F_65 ( V_16 -> V_86 , V_54 ) ;
}
void F_66 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
F_67 ( V_16 -> V_86 , V_7 ) ;
}
static int
F_68 ( struct V_31 * V_32 ,
struct V_1 * V_2 ,
T_4 V_17 ,
T_5 * V_87 )
{
struct V_6 * V_7 ;
int V_23 ;
T_6 V_88 ;
V_17 = F_69 ( V_17 , V_51 ) ;
if ( V_17 == 0 )
return - V_50 ;
V_7 = F_70 ( V_2 , V_17 ) ;
if ( V_7 == NULL )
return - V_55 ;
V_23 = F_71 ( V_32 , & V_7 -> V_8 , & V_88 ) ;
F_72 ( & V_7 -> V_8 ) ;
if ( V_23 )
return V_23 ;
* V_87 = V_88 ;
return 0 ;
}
int
F_73 ( struct V_31 * V_32 ,
struct V_1 * V_2 ,
struct V_89 * args )
{
args -> V_90 = F_74 ( args -> V_91 * F_75 ( args -> V_92 , 8 ) , 64 ) ;
args -> V_17 = args -> V_90 * args -> V_93 ;
return F_68 ( V_32 , V_2 ,
args -> V_17 , & args -> V_88 ) ;
}
int
F_76 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_94 * args = V_30 ;
return F_68 ( V_32 , V_2 ,
args -> V_17 , & args -> V_88 ) ;
}
static inline int
F_77 ( char T_3 * V_95 ,
const char * V_96 , int V_97 ,
int V_58 )
{
int V_23 , V_98 = 0 ;
while ( V_58 > 0 ) {
int V_99 = F_74 ( V_97 + 1 , 64 ) ;
int V_100 = F_78 ( V_99 - V_97 , V_58 ) ;
int V_101 = V_97 ^ 64 ;
V_23 = F_79 ( V_95 + V_98 ,
V_96 + V_101 ,
V_100 ) ;
if ( V_23 )
return V_23 + V_58 ;
V_98 += V_100 ;
V_97 += V_100 ;
V_58 -= V_100 ;
}
return 0 ;
}
static inline int
F_80 ( char * V_96 , int V_97 ,
const char T_3 * V_95 ,
int V_58 )
{
int V_23 , V_98 = 0 ;
while ( V_58 > 0 ) {
int V_99 = F_74 ( V_97 + 1 , 64 ) ;
int V_100 = F_78 ( V_99 - V_97 , V_58 ) ;
int V_101 = V_97 ^ 64 ;
V_23 = F_81 ( V_96 + V_101 ,
V_95 + V_98 ,
V_100 ) ;
if ( V_23 )
return V_23 + V_58 ;
V_98 += V_100 ;
V_97 += V_100 ;
V_58 -= V_100 ;
}
return 0 ;
}
int F_82 ( struct V_6 * V_7 ,
int * V_102 )
{
int V_23 ;
* V_102 = 0 ;
if ( ! V_7 -> V_8 . V_41 )
return - V_50 ;
if ( ! ( V_7 -> V_8 . V_63 & V_65 ) ) {
* V_102 = ! F_1 ( V_7 -> V_8 . V_2 ,
V_7 -> V_9 ) ;
V_23 = F_59 ( V_7 , true ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_56 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_83 ( V_7 ) ;
return V_23 ;
}
static int
F_84 ( struct V_52 * V_52 , int V_103 , int V_104 ,
char T_3 * V_81 ,
bool V_105 , bool V_102 )
{
char * V_43 ;
int V_23 ;
if ( F_85 ( V_105 ) )
return - V_50 ;
V_43 = F_30 ( V_52 ) ;
if ( V_102 )
F_31 ( V_43 + V_103 ,
V_104 ) ;
V_23 = F_86 ( V_81 ,
V_43 + V_103 ,
V_104 ) ;
F_32 ( V_43 ) ;
return V_23 ? - V_76 : 0 ;
}
static void
F_87 ( char * V_106 , unsigned long V_58 ,
bool V_107 )
{
if ( F_85 ( V_107 ) ) {
unsigned long V_108 = ( unsigned long ) V_106 ;
unsigned long V_109 = ( unsigned long ) V_106 + V_58 ;
V_108 = F_88 ( V_108 , 128 ) ;
V_109 = F_89 ( V_109 , 128 ) ;
F_31 ( ( void * ) V_108 , V_109 - V_108 ) ;
} else {
F_31 ( V_106 , V_58 ) ;
}
}
static int
F_90 ( struct V_52 * V_52 , int V_103 , int V_104 ,
char T_3 * V_81 ,
bool V_105 , bool V_102 )
{
char * V_43 ;
int V_23 ;
V_43 = F_91 ( V_52 ) ;
if ( V_102 )
F_87 ( V_43 + V_103 ,
V_104 ,
V_105 ) ;
if ( V_105 )
V_23 = F_77 ( V_81 ,
V_43 , V_103 ,
V_104 ) ;
else
V_23 = F_79 ( V_81 ,
V_43 + V_103 ,
V_104 ) ;
F_92 ( V_52 ) ;
return V_23 ? - V_76 : 0 ;
}
static int
F_93 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_110 * args ,
struct V_31 * V_32 )
{
char T_3 * V_81 ;
T_7 V_111 ;
T_8 V_57 ;
int V_103 , V_104 , V_23 = 0 ;
int V_112 , V_105 ;
int V_113 = 0 ;
int V_102 = 0 ;
struct V_114 V_115 ;
V_81 = F_58 ( args -> V_82 ) ;
V_111 = args -> V_17 ;
V_112 = F_26 ( V_7 ) ;
V_23 = F_82 ( V_7 , & V_102 ) ;
if ( V_23 )
return V_23 ;
V_57 = args -> V_57 ;
F_94 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_52 * V_52 = F_95 ( & V_115 ) ;
if ( V_111 <= 0 )
break;
V_103 = F_96 ( V_57 ) ;
V_104 = V_111 ;
if ( ( V_103 + V_104 ) > V_51 )
V_104 = V_51 - V_103 ;
V_105 = V_112 &&
( F_97 ( V_52 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_84 ( V_52 , V_103 , V_104 ,
V_81 , V_105 ,
V_102 ) ;
if ( V_23 == 0 )
goto V_116;
F_23 ( & V_2 -> V_29 ) ;
if ( F_98 ( ! V_117 . V_118 ) && ! V_113 ) {
V_23 = F_99 ( V_81 , V_111 ) ;
( void ) V_23 ;
V_113 = 1 ;
}
V_23 = F_90 ( V_52 , V_103 , V_104 ,
V_81 , V_105 ,
V_102 ) ;
F_19 ( & V_2 -> V_29 ) ;
if ( V_23 )
goto V_85;
V_116:
V_111 -= V_104 ;
V_81 += V_104 ;
V_57 += V_104 ;
}
V_85:
F_100 ( V_7 ) ;
return V_23 ;
}
int
F_101 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_110 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_102 ( V_119 ,
F_58 ( args -> V_82 ) ,
args -> V_17 ) )
return - V_76 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_103 ( F_104 ( V_2 , V_32 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
if ( args -> V_57 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_57 ) {
V_23 = - V_50 ;
goto V_85;
}
if ( ! V_7 -> V_8 . V_41 ) {
V_23 = - V_50 ;
goto V_85;
}
F_105 ( V_7 , args -> V_57 , args -> V_17 ) ;
V_23 = F_93 ( V_2 , V_7 , args , V_32 ) ;
V_85:
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static inline int
F_106 ( struct V_122 * V_40 ,
T_8 V_123 , int V_124 ,
char T_3 * V_81 ,
int V_58 )
{
void T_9 * V_125 ;
void * V_43 ;
unsigned long V_84 ;
V_125 = F_107 ( V_40 , V_123 ) ;
V_43 = ( void V_126 * ) V_125 + V_124 ;
V_84 = F_61 ( V_43 ,
V_81 , V_58 ) ;
F_108 ( V_125 ) ;
return V_84 ;
}
static int
F_109 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_79 * args ,
struct V_31 * V_32 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_7 V_111 ;
T_8 V_57 , V_123 ;
char T_3 * V_81 ;
int V_124 , V_104 , V_23 ;
V_23 = F_110 ( V_7 , 0 , V_127 | V_128 ) ;
if ( V_23 )
goto V_85;
V_23 = F_111 ( V_7 , true ) ;
if ( V_23 )
goto V_129;
V_23 = F_112 ( V_7 ) ;
if ( V_23 )
goto V_129;
V_81 = F_58 ( args -> V_82 ) ;
V_111 = args -> V_17 ;
V_57 = F_113 ( V_7 ) + args -> V_57 ;
F_60 ( V_7 , NULL , V_130 ) ;
while ( V_111 > 0 ) {
V_123 = V_57 & V_131 ;
V_124 = F_96 ( V_57 ) ;
V_104 = V_111 ;
if ( ( V_124 + V_111 ) > V_51 )
V_104 = V_51 - V_124 ;
if ( F_106 ( V_16 -> V_36 . V_132 , V_123 ,
V_124 , V_81 , V_104 ) ) {
V_23 = - V_76 ;
goto V_133;
}
V_111 -= V_104 ;
V_81 += V_104 ;
V_57 += V_104 ;
}
V_133:
F_63 ( V_7 , false ) ;
V_129:
F_114 ( V_7 ) ;
V_85:
return V_23 ;
}
static int
F_115 ( struct V_52 * V_52 , int V_103 , int V_104 ,
char T_3 * V_81 ,
bool V_105 ,
bool V_134 ,
bool V_135 )
{
char * V_43 ;
int V_23 ;
if ( F_85 ( V_105 ) )
return - V_50 ;
V_43 = F_30 ( V_52 ) ;
if ( V_134 )
F_31 ( V_43 + V_103 ,
V_104 ) ;
V_23 = F_116 ( V_43 + V_103 ,
V_81 , V_104 ) ;
if ( V_135 )
F_31 ( V_43 + V_103 ,
V_104 ) ;
F_32 ( V_43 ) ;
return V_23 ? - V_76 : 0 ;
}
static int
F_117 ( struct V_52 * V_52 , int V_103 , int V_104 ,
char T_3 * V_81 ,
bool V_105 ,
bool V_134 ,
bool V_135 )
{
char * V_43 ;
int V_23 ;
V_43 = F_91 ( V_52 ) ;
if ( F_85 ( V_134 || V_105 ) )
F_87 ( V_43 + V_103 ,
V_104 ,
V_105 ) ;
if ( V_105 )
V_23 = F_80 ( V_43 , V_103 ,
V_81 ,
V_104 ) ;
else
V_23 = F_81 ( V_43 + V_103 ,
V_81 ,
V_104 ) ;
if ( V_135 )
F_87 ( V_43 + V_103 ,
V_104 ,
V_105 ) ;
F_92 ( V_52 ) ;
return V_23 ? - V_76 : 0 ;
}
static int
F_118 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_79 * args ,
struct V_31 * V_32 )
{
T_7 V_111 ;
T_8 V_57 ;
char T_3 * V_81 ;
int V_103 , V_104 , V_23 = 0 ;
int V_112 , V_105 ;
int V_136 = 0 ;
int V_135 = 0 ;
int V_134 = 0 ;
struct V_114 V_115 ;
V_81 = F_58 ( args -> V_82 ) ;
V_111 = args -> V_17 ;
V_112 = F_26 ( V_7 ) ;
if ( V_7 -> V_8 . V_64 != V_65 ) {
V_135 = F_3 ( V_7 ) ;
V_23 = F_59 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
}
if ( ( V_7 -> V_8 . V_63 & V_65 ) == 0 )
V_134 =
! F_1 ( V_2 , V_7 -> V_9 ) ;
V_23 = F_56 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_60 ( V_7 , NULL , V_83 ) ;
F_83 ( V_7 ) ;
V_57 = args -> V_57 ;
V_7 -> V_67 = 1 ;
F_94 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_52 * V_52 = F_95 ( & V_115 ) ;
int V_137 ;
if ( V_111 <= 0 )
break;
V_103 = F_96 ( V_57 ) ;
V_104 = V_111 ;
if ( ( V_103 + V_104 ) > V_51 )
V_104 = V_51 - V_103 ;
V_137 = V_134 &&
( ( V_103 | V_104 )
& ( V_138 . V_139 - 1 ) ) ;
V_105 = V_112 &&
( F_97 ( V_52 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_115 ( V_52 , V_103 , V_104 ,
V_81 , V_105 ,
V_137 ,
V_135 ) ;
if ( V_23 == 0 )
goto V_116;
V_136 = 1 ;
F_23 ( & V_2 -> V_29 ) ;
V_23 = F_117 ( V_52 , V_103 , V_104 ,
V_81 , V_105 ,
V_137 ,
V_135 ) ;
F_19 ( & V_2 -> V_29 ) ;
if ( V_23 )
goto V_85;
V_116:
V_111 -= V_104 ;
V_81 += V_104 ;
V_57 += V_104 ;
}
V_85:
F_100 ( V_7 ) ;
if ( V_136 ) {
if ( ! V_135 &&
V_7 -> V_8 . V_64 != V_65 ) {
if ( F_119 ( V_7 , V_7 -> V_10 ) )
F_34 ( V_2 ) ;
}
}
if ( V_135 )
F_34 ( V_2 ) ;
F_63 ( V_7 , false ) ;
return V_23 ;
}
int
F_120 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_79 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_102 ( V_140 ,
F_58 ( args -> V_82 ) ,
args -> V_17 ) )
return - V_76 ;
if ( F_98 ( ! V_117 . V_118 ) ) {
V_23 = F_121 ( F_58 ( args -> V_82 ) ,
args -> V_17 ) ;
if ( V_23 )
return - V_76 ;
}
F_122 ( V_16 ) ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
goto V_141;
V_7 = F_103 ( F_104 ( V_2 , V_32 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
if ( args -> V_57 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_57 ) {
V_23 = - V_50 ;
goto V_85;
}
if ( ! V_7 -> V_8 . V_41 ) {
V_23 = - V_50 ;
goto V_85;
}
F_123 ( V_7 , args -> V_57 , args -> V_17 ) ;
V_23 = - V_76 ;
if ( V_7 -> V_11 == V_142 &&
V_7 -> V_8 . V_64 != V_65 &&
F_3 ( V_7 ) ) {
V_23 = F_109 ( V_2 , V_7 , args , V_32 ) ;
}
if ( V_23 == - V_76 || V_23 == - V_143 ) {
if ( V_7 -> V_44 )
V_23 = F_57 ( V_7 , args , V_32 ) ;
else
V_23 = F_118 ( V_2 , V_7 , args , V_32 ) ;
}
V_85:
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
V_141:
F_124 ( V_16 ) ;
return V_23 ;
}
int
F_125 ( struct V_22 * error ,
bool V_144 )
{
if ( F_126 ( error ) ) {
if ( ! V_144 )
return - V_26 ;
if ( F_127 ( error ) )
return - V_26 ;
if ( ! error -> V_145 )
return - V_146 ;
}
return 0 ;
}
int
F_128 ( struct V_147 * V_148 )
{
int V_23 ;
F_16 ( ! F_129 ( & V_148 -> V_149 -> V_2 -> V_29 ) ) ;
V_23 = 0 ;
if ( V_148 == V_148 -> V_149 -> V_150 )
V_23 = F_130 ( V_148 -> V_149 ) ;
return V_23 ;
}
static void F_131 ( unsigned long V_30 )
{
F_132 ( (struct V_151 * ) V_30 ) ;
}
static bool F_133 ( struct V_15 * V_16 ,
struct V_152 * V_149 )
{
return F_134 ( V_149 -> V_153 , & V_16 -> V_28 . V_154 ) ;
}
static int F_135 ( struct V_147 * V_148 )
{
unsigned long V_155 ;
if ( F_136 ( V_148 ) -> V_156 )
return - V_75 ;
V_155 = V_157 + 1 ;
while ( ! F_137 () ) {
if ( F_138 ( V_148 , true ) )
return 0 ;
if ( F_139 ( V_157 , V_155 ) )
break;
F_140 () ;
}
if ( F_138 ( V_148 , false ) )
return 0 ;
return - V_146 ;
}
int F_141 ( struct V_147 * V_148 ,
unsigned V_158 ,
bool V_144 ,
T_10 * V_155 ,
struct V_159 * V_160 )
{
struct V_152 * V_149 = F_136 ( V_148 ) ;
struct V_1 * V_2 = V_149 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
const bool V_161 =
F_142 ( V_16 -> V_28 . V_162 ) & F_143 ( V_149 ) ;
F_144 ( V_163 ) ;
unsigned long V_164 ;
T_10 V_165 , V_166 ;
int V_23 ;
F_145 ( ! F_146 ( V_16 ) , L_2 ) ;
if ( F_147 ( & V_148 -> V_167 ) )
return 0 ;
if ( F_138 ( V_148 , true ) )
return 0 ;
V_164 = V_155 ?
V_157 + F_148 ( ( V_168 ) * V_155 ) : 0 ;
if ( F_149 ( V_16 ) -> V_169 >= 6 )
F_150 ( V_16 , V_160 , V_148 -> V_170 ) ;
F_151 ( V_148 ) ;
V_165 = F_152 () ;
V_23 = F_135 ( V_148 ) ;
if ( V_23 == 0 )
goto V_85;
if ( ! V_161 && F_16 ( ! V_149 -> V_171 ( V_149 ) ) ) {
V_23 = - V_172 ;
goto V_85;
}
for (; ; ) {
struct V_173 V_174 ;
F_153 ( & V_149 -> V_175 , & V_163 ,
V_144 ? V_176 : V_177 ) ;
if ( V_158 != F_154 ( & V_16 -> V_28 . V_158 ) ) {
V_23 = F_125 ( & V_16 -> V_28 , V_144 ) ;
if ( V_23 == 0 )
V_23 = - V_146 ;
break;
}
if ( F_138 ( V_148 , false ) ) {
V_23 = 0 ;
break;
}
if ( V_144 && F_155 ( V_178 ) ) {
V_23 = - V_179 ;
break;
}
if ( V_155 && F_139 ( V_157 , V_164 ) ) {
V_23 = - V_180 ;
break;
}
V_174 . V_181 = NULL ;
if ( V_155 || F_133 ( V_16 , V_149 ) ) {
unsigned long V_182 ;
F_156 ( & V_174 , F_131 , ( unsigned long ) V_178 ) ;
V_182 = F_133 ( V_16 , V_149 ) ? V_157 + 1 : V_164 ;
F_157 ( & V_174 , V_182 ) ;
}
F_158 () ;
if ( V_174 . V_181 ) {
F_159 ( & V_174 ) ;
F_160 ( & V_174 ) ;
}
}
if ( ! V_161 )
V_149 -> V_183 ( V_149 ) ;
F_161 ( & V_149 -> V_175 , & V_163 ) ;
V_85:
V_166 = F_152 () ;
F_162 ( V_148 ) ;
if ( V_155 ) {
T_10 V_184 = * V_155 - ( V_166 - V_165 ) ;
* V_155 = V_184 < 0 ? 0 : V_184 ;
if ( V_23 == - V_180 && * V_155 < F_163 ( 1 ) * 1000 )
* V_155 = 0 ;
}
return V_23 ;
}
static inline void
F_164 ( struct V_147 * V_185 )
{
struct V_186 * V_80 = V_185 -> V_80 ;
if ( ! V_80 )
return;
F_7 ( & V_80 -> V_18 . V_187 ) ;
F_165 ( & V_185 -> V_188 ) ;
V_185 -> V_80 = NULL ;
F_8 ( & V_80 -> V_18 . V_187 ) ;
}
static void F_166 ( struct V_147 * V_185 )
{
F_167 ( V_185 ) ;
V_185 -> V_189 -> V_190 = V_185 -> V_191 ;
F_168 ( & V_185 -> V_167 ) ;
F_164 ( V_185 ) ;
F_169 ( V_185 -> V_192 ) ;
F_170 ( V_185 ) ;
}
static void
F_171 ( struct V_147 * V_148 )
{
struct V_152 * V_193 = V_148 -> V_149 ;
struct V_147 * V_194 ;
F_172 ( & V_193 -> V_2 -> V_29 ) ;
if ( F_147 ( & V_148 -> V_167 ) )
return;
do {
V_194 = F_173 ( & V_193 -> V_195 ,
F_174 ( * V_194 ) , V_167 ) ;
F_166 ( V_194 ) ;
} while ( V_194 != V_148 );
F_16 ( F_17 ( V_193 -> V_2 ) ) ;
}
int
F_175 ( struct V_147 * V_148 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
bool V_144 ;
int V_23 ;
F_41 ( V_148 == NULL ) ;
V_2 = V_148 -> V_149 -> V_2 ;
V_16 = V_2 -> V_27 ;
V_144 = V_16 -> V_18 . V_144 ;
F_41 ( ! F_129 ( & V_2 -> V_29 ) ) ;
V_23 = F_125 ( & V_16 -> V_28 , V_144 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_128 ( V_148 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_141 ( V_148 ,
F_154 ( & V_16 -> V_28 . V_158 ) ,
V_144 , NULL , NULL ) ;
if ( V_23 )
return V_23 ;
F_171 ( V_148 ) ;
return 0 ;
}
int
F_59 ( struct V_6 * V_7 ,
bool V_196 )
{
int V_23 , V_49 ;
if ( ! V_7 -> V_197 )
return 0 ;
if ( V_196 ) {
if ( V_7 -> V_198 != NULL ) {
V_23 = F_175 ( V_7 -> V_198 ) ;
if ( V_23 )
return V_23 ;
V_49 = V_7 -> V_198 -> V_149 -> V_153 ;
if ( V_7 -> V_199 [ V_49 ] == V_7 -> V_198 )
F_176 ( V_7 , V_49 ) ;
else
F_177 ( V_7 ) ;
}
} else {
for ( V_49 = 0 ; V_49 < V_200 ; V_49 ++ ) {
if ( V_7 -> V_199 [ V_49 ] == NULL )
continue;
V_23 = F_175 ( V_7 -> V_199 [ V_49 ] ) ;
if ( V_23 )
return V_23 ;
F_176 ( V_7 , V_49 ) ;
}
F_178 ( V_7 -> V_197 ) ;
}
return 0 ;
}
static void
F_179 ( struct V_6 * V_7 ,
struct V_147 * V_148 )
{
int V_149 = V_148 -> V_149 -> V_153 ;
if ( V_7 -> V_199 [ V_149 ] == V_148 )
F_176 ( V_7 , V_149 ) ;
else if ( V_7 -> V_198 == V_148 )
F_177 ( V_7 ) ;
F_171 ( V_148 ) ;
}
static T_11 int
F_180 ( struct V_6 * V_7 ,
struct V_159 * V_160 ,
bool V_196 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_147 * V_201 [ V_200 ] ;
unsigned V_158 ;
int V_23 , V_49 , V_202 = 0 ;
F_41 ( ! F_129 ( & V_2 -> V_29 ) ) ;
F_41 ( ! V_16 -> V_18 . V_144 ) ;
if ( ! V_7 -> V_197 )
return 0 ;
V_23 = F_125 ( & V_16 -> V_28 , true ) ;
if ( V_23 )
return V_23 ;
V_158 = F_154 ( & V_16 -> V_28 . V_158 ) ;
if ( V_196 ) {
struct V_147 * V_148 ;
V_148 = V_7 -> V_198 ;
if ( V_148 == NULL )
return 0 ;
V_23 = F_128 ( V_148 ) ;
if ( V_23 )
goto V_203;
V_201 [ V_202 ++ ] = F_181 ( V_148 ) ;
} else {
for ( V_49 = 0 ; V_49 < V_200 ; V_49 ++ ) {
struct V_147 * V_148 ;
V_148 = V_7 -> V_199 [ V_49 ] ;
if ( V_148 == NULL )
continue;
V_23 = F_128 ( V_148 ) ;
if ( V_23 )
goto V_203;
V_201 [ V_202 ++ ] = F_181 ( V_148 ) ;
}
}
F_23 ( & V_2 -> V_29 ) ;
for ( V_49 = 0 ; V_23 == 0 && V_49 < V_202 ; V_49 ++ )
V_23 = F_141 ( V_201 [ V_49 ] , V_158 , true ,
NULL , V_160 ) ;
F_19 ( & V_2 -> V_29 ) ;
V_203:
for ( V_49 = 0 ; V_49 < V_202 ; V_49 ++ ) {
if ( V_23 == 0 )
F_179 ( V_7 , V_201 [ V_49 ] ) ;
F_170 ( V_201 [ V_49 ] ) ;
}
return V_23 ;
}
static struct V_159 * F_182 ( struct V_31 * V_32 )
{
struct V_186 * V_204 = V_32 -> V_205 ;
return & V_204 -> V_160 ;
}
int
F_183 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_206 * args = V_30 ;
struct V_6 * V_7 ;
T_5 V_63 = args -> V_63 ;
T_5 V_64 = args -> V_64 ;
int V_23 ;
if ( V_64 & V_207 )
return - V_50 ;
if ( V_63 & V_207 )
return - V_50 ;
if ( V_64 != 0 && V_63 != V_64 )
return - V_50 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_103 ( F_104 ( V_2 , V_32 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
V_23 = F_180 ( V_7 ,
F_182 ( V_32 ) ,
! V_64 ) ;
if ( V_23 )
goto V_208;
if ( V_63 & V_209 )
V_23 = F_111 ( V_7 , V_64 != 0 ) ;
else
V_23 = F_42 ( V_7 , V_64 != 0 ) ;
V_208:
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_184 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_210 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_103 ( F_104 ( V_2 , V_32 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
if ( V_7 -> V_10 )
F_185 ( V_7 ) ;
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_186 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_211 * args = V_30 ;
struct V_212 * V_7 ;
unsigned long V_106 ;
if ( args -> V_213 & ~ ( V_214 ) )
return - V_50 ;
if ( args -> V_213 & V_214 && ! V_215 )
return - V_172 ;
V_7 = F_104 ( V_2 , V_32 , args -> V_88 ) ;
if ( V_7 == NULL )
return - V_120 ;
if ( ! V_7 -> V_41 ) {
F_72 ( V_7 ) ;
return - V_50 ;
}
V_106 = F_187 ( V_7 -> V_41 , 0 , args -> V_17 ,
V_216 | V_217 , V_218 ,
args -> V_57 ) ;
if ( args -> V_213 & V_214 ) {
struct V_219 * V_18 = V_178 -> V_18 ;
struct V_220 * V_71 ;
F_188 ( & V_18 -> V_221 ) ;
V_71 = F_189 ( V_18 , V_106 ) ;
if ( V_71 )
V_71 -> V_222 =
F_190 ( F_191 ( V_71 -> V_223 ) ) ;
else
V_106 = - V_55 ;
F_192 ( & V_18 -> V_221 ) ;
}
F_72 ( V_7 ) ;
if ( F_28 ( ( void * ) V_106 ) )
return V_106 ;
args -> V_224 = ( T_4 ) V_106 ;
return 0 ;
}
int F_193 ( struct V_220 * V_71 , struct V_225 * V_226 )
{
struct V_6 * V_7 = F_103 ( V_71 -> V_227 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_228 V_229 = V_230 ;
T_12 V_124 ;
unsigned long V_231 ;
int V_23 = 0 ;
bool V_232 = ! ! ( V_226 -> V_213 & V_233 ) ;
F_122 ( V_16 ) ;
V_124 = ( ( unsigned long ) V_226 -> V_234 - V_71 -> V_235 ) >>
V_236 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
goto V_85;
F_194 ( V_7 , V_124 , true , V_232 ) ;
V_23 = F_180 ( V_7 , NULL , ! V_232 ) ;
if ( V_23 )
goto V_121;
if ( V_7 -> V_9 != V_5 && ! F_2 ( V_2 ) ) {
V_23 = - V_76 ;
goto V_121;
}
if ( V_7 -> V_8 . V_17 >= V_16 -> V_36 . V_237 &&
V_7 -> V_11 == V_142 ) {
static const unsigned int V_238 = 256 ;
memset ( & V_229 , 0 , sizeof( V_229 ) ) ;
V_229 . type = V_239 ;
V_229 . V_240 . V_241 . V_57 = F_195 ( V_124 , V_238 ) ;
V_229 . V_240 . V_241 . V_17 =
F_196 (unsigned int,
chunk_size,
(vma->vm_end - vma->vm_start)/PAGE_SIZE -
view.params.partial.offset) ;
}
V_23 = F_197 ( V_7 , & V_229 , 0 , V_127 ) ;
if ( V_23 )
goto V_121;
V_23 = F_111 ( V_7 , V_232 ) ;
if ( V_23 )
goto V_242;
V_23 = F_198 ( V_7 ) ;
if ( V_23 )
goto V_242;
V_231 = V_16 -> V_36 . V_243 +
F_199 ( V_7 , & V_229 ) ;
V_231 >>= V_236 ;
if ( F_85 ( V_229 . type == V_239 ) ) {
unsigned long V_8 = V_71 -> V_235 +
( V_229 . V_240 . V_241 . V_57 << V_236 ) ;
unsigned int V_49 ;
for ( V_49 = 0 ; V_49 < V_229 . V_240 . V_241 . V_17 ; V_49 ++ ) {
V_23 = F_200 ( V_71 , V_8 + V_49 * V_51 , V_231 + V_49 ) ;
if ( V_23 )
break;
}
V_7 -> V_244 = true ;
} else {
if ( ! V_7 -> V_244 ) {
unsigned long V_17 = F_196 (unsigned long,
vma->vm_end - vma->vm_start,
obj->base.size) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_17 > > V_236 ; V_49 ++ ) {
V_23 = F_200 ( V_71 ,
( unsigned long ) V_71 -> V_235 + V_49 * V_51 ,
V_231 + V_49 ) ;
if ( V_23 )
break;
}
V_7 -> V_244 = true ;
} else
V_23 = F_200 ( V_71 ,
( unsigned long ) V_226 -> V_234 ,
V_231 + V_124 ) ;
}
V_242:
F_201 ( V_7 , & V_229 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
V_85:
switch ( V_23 ) {
case - V_26 :
if ( ! F_127 ( & V_16 -> V_28 ) ) {
V_23 = V_245 ;
break;
}
case - V_146 :
case 0 :
case - V_179 :
case - V_246 :
case - V_75 :
V_23 = V_247 ;
break;
case - V_55 :
V_23 = V_248 ;
break;
case - V_143 :
case - V_76 :
V_23 = V_245 ;
break;
default:
F_202 ( V_23 , L_3 , V_23 ) ;
V_23 = V_245 ;
break;
}
F_124 ( V_16 ) ;
return V_23 ;
}
void
F_5 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_244 )
return;
F_203 ( & V_7 -> V_8 . V_249 ,
V_7 -> V_8 . V_2 -> V_250 -> V_42 ) ;
V_7 -> V_244 = false ;
}
void
F_204 ( struct V_15 * V_16 )
{
struct V_6 * V_7 ;
F_20 (obj, &dev_priv->mm.bound_list, global_list)
F_5 ( V_7 ) ;
}
T_5
F_205 ( struct V_1 * V_2 , T_5 V_17 , int V_11 )
{
T_5 V_251 ;
if ( F_149 ( V_2 ) -> V_169 >= 4 ||
V_11 == V_142 )
return V_17 ;
if ( F_149 ( V_2 ) -> V_169 == 3 )
V_251 = 1024 * 1024 ;
else
V_251 = 512 * 1024 ;
while ( V_251 < V_17 )
V_251 <<= 1 ;
return V_251 ;
}
T_5
F_206 ( struct V_1 * V_2 , T_5 V_17 ,
int V_11 , bool V_252 )
{
if ( F_149 ( V_2 ) -> V_169 >= 4 || ( ! V_252 && F_207 ( V_2 ) ) ||
V_11 == V_142 )
return 4096 ;
return F_205 ( V_2 , V_17 , V_11 ) ;
}
static int F_208 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_209 ( & V_7 -> V_8 . V_249 ) )
return 0 ;
V_16 -> V_18 . V_253 = true ;
V_23 = F_210 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_143 )
goto V_85;
F_211 ( V_16 ,
V_7 -> V_8 . V_17 >> V_236 ,
V_254 |
V_255 |
V_256 ) ;
V_23 = F_210 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_143 )
goto V_85;
F_212 ( V_16 ) ;
V_23 = F_210 ( & V_7 -> V_8 ) ;
V_85:
V_16 -> V_18 . V_253 = false ;
return V_23 ;
}
static void F_213 ( struct V_6 * V_7 )
{
F_214 ( & V_7 -> V_8 ) ;
}
int
F_215 ( struct V_31 * V_32 ,
struct V_1 * V_2 ,
T_5 V_88 ,
T_4 * V_57 )
{
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_103 ( F_104 ( V_2 , V_32 , V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
if ( V_7 -> V_61 != V_69 ) {
F_216 ( L_4 ) ;
V_23 = - V_76 ;
goto V_85;
}
V_23 = F_208 ( V_7 ) ;
if ( V_23 )
goto V_85;
* V_57 = F_217 ( & V_7 -> V_8 . V_249 ) ;
V_85:
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_218 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_257 * args = V_30 ;
return F_215 ( V_32 , V_2 , args -> V_88 , & args -> V_57 ) ;
}
static void
F_219 ( struct V_6 * V_7 )
{
F_213 ( V_7 ) ;
if ( V_7 -> V_8 . V_41 == NULL )
return;
F_220 ( F_25 ( V_7 -> V_8 . V_41 ) , 0 , ( T_8 ) - 1 ) ;
V_7 -> V_61 = V_62 ;
}
static void
F_221 ( struct V_6 * V_7 )
{
struct V_39 * V_40 ;
switch ( V_7 -> V_61 ) {
case V_66 :
F_219 ( V_7 ) ;
case V_62 :
return;
}
if ( V_7 -> V_8 . V_41 == NULL )
return;
V_40 = F_25 ( V_7 -> V_8 . V_41 ) -> V_42 ,
F_222 ( V_40 , 0 , ( T_8 ) - 1 ) ;
}
static void
F_223 ( struct V_6 * V_7 )
{
struct V_114 V_115 ;
int V_23 ;
F_41 ( V_7 -> V_61 == V_62 ) ;
V_23 = F_42 ( V_7 , true ) ;
if ( V_23 ) {
F_16 ( V_23 != - V_26 ) ;
F_119 ( V_7 , true ) ;
V_7 -> V_8 . V_63 = V_7 -> V_8 . V_64 = V_65 ;
}
F_224 ( V_7 ) ;
if ( F_26 ( V_7 ) )
F_225 ( V_7 ) ;
if ( V_7 -> V_61 == V_66 )
V_7 -> V_67 = 0 ;
F_94 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_52 * V_52 = F_95 ( & V_115 ) ;
if ( V_7 -> V_67 )
F_43 ( V_52 ) ;
if ( V_7 -> V_61 == V_69 )
F_44 ( V_52 ) ;
F_33 ( V_52 ) ;
}
V_7 -> V_67 = 0 ;
F_45 ( V_7 -> V_60 ) ;
F_37 ( V_7 -> V_60 ) ;
}
int
F_52 ( struct V_6 * V_7 )
{
const struct V_258 * V_77 = V_7 -> V_77 ;
if ( V_7 -> V_60 == NULL )
return 0 ;
if ( V_7 -> V_259 )
return - V_75 ;
F_41 ( F_226 ( V_7 ) ) ;
F_165 ( & V_7 -> V_260 ) ;
V_77 -> V_261 ( V_7 ) ;
V_7 -> V_60 = NULL ;
F_221 ( V_7 ) ;
return 0 ;
}
static int
F_227 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_262 , V_49 ;
struct V_39 * V_40 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_114 V_115 ;
struct V_52 * V_52 ;
unsigned long V_263 = 0 ;
int V_23 ;
T_13 V_264 ;
F_41 ( V_7 -> V_8 . V_63 & V_207 ) ;
F_41 ( V_7 -> V_8 . V_64 & V_207 ) ;
V_46 = F_35 ( sizeof( * V_46 ) , V_54 ) ;
if ( V_46 == NULL )
return - V_55 ;
V_262 = V_7 -> V_8 . V_17 / V_51 ;
if ( F_36 ( V_46 , V_262 , V_54 ) ) {
F_37 ( V_46 ) ;
return - V_55 ;
}
V_40 = F_25 ( V_7 -> V_8 . V_41 ) -> V_42 ;
V_264 = F_228 ( V_40 ) ;
V_264 |= V_265 | V_266 | V_267 ;
V_264 &= ~ ( V_268 | V_269 ) ;
V_48 = V_46 -> V_56 ;
V_46 -> V_270 = 0 ;
for ( V_49 = 0 ; V_49 < V_262 ; V_49 ++ ) {
V_52 = F_229 ( V_40 , V_49 , V_264 ) ;
if ( F_28 ( V_52 ) ) {
F_211 ( V_16 ,
V_262 ,
V_254 |
V_255 |
V_256 ) ;
V_52 = F_229 ( V_40 , V_49 , V_264 ) ;
}
if ( F_28 ( V_52 ) ) {
F_212 ( V_16 ) ;
V_52 = F_27 ( V_40 , V_49 ) ;
if ( F_28 ( V_52 ) ) {
V_23 = F_29 ( V_52 ) ;
goto V_271;
}
}
#ifdef F_230
if ( F_231 () ) {
V_46 -> V_270 ++ ;
F_232 ( V_48 , V_52 , V_51 , 0 ) ;
V_48 = F_233 ( V_48 ) ;
continue;
}
#endif
if ( ! V_49 || F_234 ( V_52 ) != V_263 + 1 ) {
if ( V_49 )
V_48 = F_233 ( V_48 ) ;
V_46 -> V_270 ++ ;
F_232 ( V_48 , V_52 , V_51 , 0 ) ;
} else {
V_48 -> V_58 += V_51 ;
}
V_263 = F_234 ( V_52 ) ;
F_16 ( ( V_264 & V_272 ) && ( V_263 >= 0x00100000UL ) ) ;
}
#ifdef F_230
if ( ! F_231 () )
#endif
F_235 ( V_48 ) ;
V_7 -> V_60 = V_46 ;
V_23 = F_236 ( V_7 ) ;
if ( V_23 )
goto V_271;
if ( F_26 ( V_7 ) )
F_237 ( V_7 ) ;
if ( V_7 -> V_11 != V_142 &&
V_16 -> V_273 & V_274 )
F_83 ( V_7 ) ;
return 0 ;
V_271:
F_235 ( V_48 ) ;
F_94 (st->sgl, &sg_iter, st->nents, 0 )
F_33 ( F_95 ( & V_115 ) ) ;
F_45 ( V_46 ) ;
F_37 ( V_46 ) ;
if ( V_23 == - V_143 )
V_23 = - V_55 ;
return V_23 ;
}
int
F_56 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
const struct V_258 * V_77 = V_7 -> V_77 ;
int V_23 ;
if ( V_7 -> V_60 )
return 0 ;
if ( V_7 -> V_61 != V_69 ) {
F_216 ( L_5 ) ;
return - V_76 ;
}
F_41 ( V_7 -> V_259 ) ;
V_23 = V_77 -> V_275 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_238 ( & V_7 -> V_260 , & V_16 -> V_18 . V_276 ) ;
V_7 -> V_277 . V_48 = V_7 -> V_60 -> V_56 ;
V_7 -> V_277 . V_278 = 0 ;
return 0 ;
}
void F_239 ( struct V_70 * V_71 ,
struct V_152 * V_149 )
{
struct V_6 * V_7 = V_71 -> V_7 ;
if ( V_7 -> V_197 == 0 )
F_49 ( & V_7 -> V_8 ) ;
V_7 -> V_197 |= F_143 ( V_149 ) ;
F_240 ( & V_7 -> V_279 [ V_149 -> V_153 ] , & V_149 -> V_280 ) ;
F_241 ( & V_7 -> V_199 [ V_149 -> V_153 ] ,
F_242 ( V_149 ) ) ;
F_240 ( & V_71 -> V_281 , & V_71 -> V_282 -> V_280 ) ;
}
static void
F_177 ( struct V_6 * V_7 )
{
F_178 ( V_7 -> V_198 == NULL ) ;
F_178 ( ! ( V_7 -> V_197 & F_143 ( V_7 -> V_198 -> V_149 ) ) ) ;
F_241 ( & V_7 -> V_198 , NULL ) ;
F_63 ( V_7 , true ) ;
}
static void
F_176 ( struct V_6 * V_7 , int V_149 )
{
struct V_70 * V_71 ;
F_178 ( V_7 -> V_199 [ V_149 ] == NULL ) ;
F_178 ( ! ( V_7 -> V_197 & ( 1 << V_149 ) ) ) ;
F_168 ( & V_7 -> V_279 [ V_149 ] ) ;
F_241 ( & V_7 -> V_199 [ V_149 ] , NULL ) ;
if ( V_7 -> V_198 && V_7 -> V_198 -> V_149 -> V_153 == V_149 )
F_177 ( V_7 ) ;
V_7 -> V_197 &= ~ ( 1 << V_149 ) ;
if ( V_7 -> V_197 )
return;
F_20 (vma, &obj->vma_list, vma_link) {
if ( ! F_147 ( & V_71 -> V_281 ) )
F_240 ( & V_71 -> V_281 , & V_71 -> V_282 -> V_283 ) ;
}
F_241 ( & V_7 -> V_284 , NULL ) ;
F_53 ( & V_7 -> V_8 ) ;
}
static int
F_243 ( struct V_1 * V_2 , T_6 V_285 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_152 * V_149 ;
int V_23 , V_49 , V_286 ;
F_244 (ring, dev_priv, i) {
V_23 = F_245 ( V_149 ) ;
if ( V_23 )
return V_23 ;
}
F_246 ( V_2 ) ;
F_244 (ring, dev_priv, i) {
F_247 ( V_149 , V_285 ) ;
for ( V_286 = 0 ; V_286 < F_248 ( V_149 -> V_287 . V_288 ) ; V_286 ++ )
V_149 -> V_287 . V_288 [ V_286 ] = 0 ;
}
return 0 ;
}
int F_249 ( struct V_1 * V_2 , T_6 V_285 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( V_285 == 0 )
return - V_50 ;
V_23 = F_243 ( V_2 , V_285 - 1 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_289 = V_285 ;
V_16 -> V_290 = V_285 - 1 ;
if ( V_16 -> V_290 == 0 )
V_16 -> V_290 -- ;
return 0 ;
}
int
F_250 ( struct V_1 * V_2 , T_6 * V_285 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( V_16 -> V_289 == 0 ) {
int V_23 = F_243 ( V_2 , 0 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_289 = 1 ;
}
* V_285 = V_16 -> V_290 = V_16 -> V_289 ++ ;
return 0 ;
}
int F_251 ( struct V_152 * V_149 ,
struct V_31 * V_32 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_149 -> V_2 -> V_27 ;
struct V_147 * V_185 ;
struct V_291 * V_189 ;
T_6 V_292 ;
int V_23 ;
V_185 = V_149 -> V_150 ;
if ( F_16 ( V_185 == NULL ) )
return - V_55 ;
if ( V_117 . V_293 ) {
V_189 = V_185 -> V_294 -> V_193 [ V_149 -> V_153 ] . V_189 ;
} else
V_189 = V_149 -> V_295 ;
V_292 = F_252 ( V_189 ) ;
if ( V_117 . V_293 ) {
V_23 = F_253 ( V_189 , V_185 -> V_294 ) ;
if ( V_23 )
return V_23 ;
} else {
V_23 = F_254 ( V_149 ) ;
if ( V_23 )
return V_23 ;
}
V_185 -> V_191 = F_252 ( V_189 ) ;
if ( V_117 . V_293 ) {
V_23 = V_149 -> V_296 ( V_189 , V_185 ) ;
if ( V_23 )
return V_23 ;
} else {
V_23 = V_149 -> V_297 ( V_149 ) ;
if ( V_23 )
return V_23 ;
V_185 -> V_298 = F_252 ( V_189 ) ;
}
V_185 -> V_299 = V_292 ;
V_185 -> V_300 = V_7 ;
if ( ! V_117 . V_293 ) {
V_185 -> V_294 = V_149 -> V_301 ;
if ( V_185 -> V_294 )
F_255 ( V_185 -> V_294 ) ;
}
V_185 -> V_170 = V_157 ;
V_149 -> V_302 = V_185 -> V_285 ;
F_238 ( & V_185 -> V_167 , & V_149 -> V_195 ) ;
V_185 -> V_80 = NULL ;
if ( V_32 ) {
struct V_186 * V_80 = V_32 -> V_205 ;
F_7 ( & V_80 -> V_18 . V_187 ) ;
V_185 -> V_80 = V_80 ;
F_238 ( & V_185 -> V_188 ,
& V_80 -> V_18 . V_195 ) ;
F_8 ( & V_80 -> V_18 . V_187 ) ;
V_185 -> V_192 = F_256 ( F_257 ( V_178 ) ) ;
}
F_258 ( V_185 ) ;
V_149 -> V_150 = NULL ;
F_259 ( V_149 -> V_2 ) ;
F_260 ( V_16 -> V_303 ,
& V_16 -> V_18 . V_304 ,
F_261 ( V_25 ) ) ;
F_262 ( V_16 -> V_2 ) ;
return 0 ;
}
static bool F_263 ( struct V_15 * V_16 ,
const struct V_305 * V_294 )
{
unsigned long V_306 ;
V_306 = F_264 () - V_294 -> V_307 . V_308 ;
if ( V_294 -> V_307 . V_309 )
return true ;
if ( V_294 -> V_307 . V_310 &&
V_306 <= V_294 -> V_307 . V_310 ) {
if ( ! F_265 ( V_294 ) ) {
F_216 ( L_6 ) ;
return true ;
} else if ( F_266 ( V_16 ) ) {
if ( F_267 ( V_16 ) )
F_13 ( L_7 ) ;
return true ;
}
}
return false ;
}
static void F_268 ( struct V_15 * V_16 ,
struct V_305 * V_294 ,
const bool V_311 )
{
struct V_312 * V_313 ;
if ( F_16 ( ! V_294 ) )
return;
V_313 = & V_294 -> V_307 ;
if ( V_311 ) {
V_313 -> V_309 = F_263 ( V_16 , V_294 ) ;
V_313 -> V_314 ++ ;
V_313 -> V_308 = F_264 () ;
} else {
V_313 -> V_315 ++ ;
}
}
void F_269 ( struct V_316 * V_317 )
{
struct V_147 * V_148 = F_270 ( V_317 ,
F_174 ( * V_148 ) , V_318 ) ;
struct V_305 * V_294 = V_148 -> V_294 ;
if ( V_294 ) {
if ( V_117 . V_293 ) {
struct V_152 * V_149 = V_148 -> V_149 ;
if ( V_294 != V_149 -> V_319 )
F_271 ( V_149 , V_294 ) ;
}
F_272 ( V_294 ) ;
}
F_67 ( V_148 -> V_117 -> V_201 , V_148 ) ;
}
int F_273 ( struct V_152 * V_149 ,
struct V_305 * V_294 )
{
struct V_15 * V_16 = F_274 ( V_149 -> V_2 ) ;
struct V_147 * V_148 ;
int V_23 ;
if ( V_149 -> V_150 )
return 0 ;
V_148 = F_65 ( V_16 -> V_201 , V_54 ) ;
if ( V_148 == NULL )
return - V_55 ;
F_275 ( & V_148 -> V_318 ) ;
V_148 -> V_117 = V_16 ;
V_23 = F_250 ( V_149 -> V_2 , & V_148 -> V_285 ) ;
if ( V_23 )
goto V_203;
V_148 -> V_149 = V_149 ;
if ( V_117 . V_293 )
V_23 = F_276 ( V_148 , V_294 ) ;
else
V_23 = F_277 ( V_148 ) ;
if ( V_23 )
goto V_203;
V_149 -> V_150 = V_148 ;
return 0 ;
V_203:
F_67 ( V_16 -> V_201 , V_148 ) ;
return V_23 ;
}
struct V_147 *
F_278 ( struct V_152 * V_149 )
{
struct V_147 * V_185 ;
F_20 (request, &ring->request_list, list) {
if ( F_138 ( V_185 , false ) )
continue;
return V_185 ;
}
return NULL ;
}
static void F_279 ( struct V_15 * V_16 ,
struct V_152 * V_149 )
{
struct V_147 * V_185 ;
bool V_320 ;
V_185 = F_278 ( V_149 ) ;
if ( V_185 == NULL )
return;
V_320 = V_149 -> V_321 . V_322 >= V_323 ;
F_268 ( V_16 , V_185 -> V_294 , V_320 ) ;
F_280 (request, &ring->request_list, list)
F_268 ( V_16 , V_185 -> V_294 , false ) ;
}
static void F_281 ( struct V_15 * V_16 ,
struct V_152 * V_149 )
{
while ( ! F_147 ( & V_149 -> V_280 ) ) {
struct V_6 * V_7 ;
V_7 = F_173 ( & V_149 -> V_280 ,
struct V_6 ,
V_279 [ V_149 -> V_153 ] ) ;
F_176 ( V_7 , V_149 -> V_153 ) ;
}
while ( ! F_147 ( & V_149 -> V_324 ) ) {
struct V_147 * V_325 ;
V_325 = F_173 ( & V_149 -> V_324 ,
struct V_147 ,
V_326 ) ;
F_165 ( & V_325 -> V_326 ) ;
if ( V_325 -> V_294 != V_149 -> V_319 )
F_271 ( V_149 , V_325 -> V_294 ) ;
F_170 ( V_325 ) ;
}
while ( ! F_147 ( & V_149 -> V_195 ) ) {
struct V_147 * V_185 ;
V_185 = F_173 ( & V_149 -> V_195 ,
struct V_147 ,
V_167 ) ;
F_166 ( V_185 ) ;
}
F_241 ( & V_149 -> V_150 , NULL ) ;
}
void F_282 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_16 -> V_327 ; V_49 ++ ) {
struct V_328 * V_329 = & V_16 -> V_330 [ V_49 ] ;
if ( V_329 -> V_7 ) {
F_283 ( V_329 -> V_7 , V_329 ,
V_329 -> V_7 -> V_11 ) ;
} else {
F_284 ( V_2 , V_49 , NULL ) ;
}
}
}
void F_285 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_152 * V_149 ;
int V_49 ;
F_244 (ring, dev_priv, i)
F_279 ( V_16 , V_149 ) ;
F_244 (ring, dev_priv, i)
F_281 ( V_16 , V_149 ) ;
F_286 ( V_2 ) ;
F_282 ( V_2 ) ;
F_16 ( F_17 ( V_2 ) ) ;
}
void
F_287 ( struct V_152 * V_149 )
{
F_16 ( F_17 ( V_149 -> V_2 ) ) ;
while ( ! F_147 ( & V_149 -> V_195 ) ) {
struct V_147 * V_185 ;
V_185 = F_173 ( & V_149 -> V_195 ,
struct V_147 ,
V_167 ) ;
if ( ! F_138 ( V_185 , true ) )
break;
F_166 ( V_185 ) ;
}
while ( ! F_147 ( & V_149 -> V_280 ) ) {
struct V_6 * V_7 ;
V_7 = F_173 ( & V_149 -> V_280 ,
struct V_6 ,
V_279 [ V_149 -> V_153 ] ) ;
if ( ! F_147 ( & V_7 -> V_199 [ V_149 -> V_153 ] -> V_167 ) )
break;
F_176 ( V_7 , V_149 -> V_153 ) ;
}
if ( F_85 ( V_149 -> V_331 &&
F_138 ( V_149 -> V_331 , true ) ) ) {
V_149 -> V_183 ( V_149 ) ;
F_241 ( & V_149 -> V_331 , NULL ) ;
}
F_16 ( F_17 ( V_149 -> V_2 ) ) ;
}
bool
F_246 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_152 * V_149 ;
bool V_332 = true ;
int V_49 ;
F_244 (ring, dev_priv, i) {
F_287 ( V_149 ) ;
V_332 &= F_147 ( & V_149 -> V_195 ) ;
if ( V_117 . V_293 ) {
unsigned long V_213 ;
F_288 ( & V_149 -> V_333 , V_213 ) ;
V_332 &= F_147 ( & V_149 -> V_324 ) ;
F_289 ( & V_149 -> V_333 , V_213 ) ;
F_290 ( V_149 ) ;
}
}
if ( V_332 )
F_291 ( V_16 -> V_303 ,
& V_16 -> V_18 . V_334 ,
F_292 ( 100 ) ) ;
return V_332 ;
}
static void
F_293 ( struct V_335 * V_336 )
{
struct V_15 * V_16 =
F_270 ( V_336 , F_174 ( * V_16 ) , V_18 . V_304 . V_336 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_332 ;
V_332 = false ;
if ( F_294 ( & V_2 -> V_29 ) ) {
V_332 = F_246 ( V_2 ) ;
F_23 ( & V_2 -> V_29 ) ;
}
if ( ! V_332 )
F_260 ( V_16 -> V_303 , & V_16 -> V_18 . V_304 ,
F_261 ( V_25 ) ) ;
}
static void
F_295 ( struct V_335 * V_336 )
{
struct V_15 * V_16 =
F_270 ( V_336 , F_174 ( * V_16 ) , V_18 . V_334 . V_336 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_152 * V_149 ;
int V_49 ;
F_244 (ring, dev_priv, i)
if ( ! F_147 ( & V_149 -> V_195 ) )
return;
F_296 ( V_2 ) ;
if ( F_294 ( & V_2 -> V_29 ) ) {
struct V_152 * V_149 ;
int V_49 ;
F_244 (ring, dev_priv, i)
F_297 ( & V_149 -> V_337 ) ;
F_23 ( & V_2 -> V_29 ) ;
}
}
static int
F_298 ( struct V_6 * V_7 )
{
int V_23 , V_49 ;
if ( ! V_7 -> V_197 )
return 0 ;
for ( V_49 = 0 ; V_49 < V_200 ; V_49 ++ ) {
struct V_147 * V_148 ;
V_148 = V_7 -> V_199 [ V_49 ] ;
if ( V_148 == NULL )
continue;
if ( F_147 ( & V_148 -> V_167 ) )
goto V_338;
V_23 = F_128 ( V_148 ) ;
if ( V_23 )
return V_23 ;
if ( F_138 ( V_148 , true ) ) {
F_171 ( V_148 ) ;
V_338:
F_176 ( V_7 , V_49 ) ;
}
}
return 0 ;
}
int
F_299 ( struct V_1 * V_2 , void * V_30 , struct V_31 * V_32 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_339 * args = V_30 ;
struct V_6 * V_7 ;
struct V_147 * V_148 [ V_200 ] ;
unsigned V_158 ;
int V_49 , V_202 = 0 ;
int V_23 ;
if ( args -> V_213 != 0 )
return - V_50 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_103 ( F_104 ( V_2 , V_32 , args -> V_340 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_23 ( & V_2 -> V_29 ) ;
return - V_120 ;
}
V_23 = F_298 ( V_7 ) ;
if ( V_23 )
goto V_85;
if ( ! V_7 -> V_197 )
goto V_85;
if ( args -> V_341 == 0 ) {
V_23 = - V_180 ;
goto V_85;
}
F_53 ( & V_7 -> V_8 ) ;
V_158 = F_154 ( & V_16 -> V_28 . V_158 ) ;
for ( V_49 = 0 ; V_49 < V_200 ; V_49 ++ ) {
if ( V_7 -> V_199 [ V_49 ] == NULL )
continue;
V_148 [ V_202 ++ ] = F_181 ( V_7 -> V_199 [ V_49 ] ) ;
}
F_23 ( & V_2 -> V_29 ) ;
for ( V_49 = 0 ; V_49 < V_202 ; V_49 ++ ) {
if ( V_23 == 0 )
V_23 = F_141 ( V_148 [ V_49 ] , V_158 , true ,
args -> V_341 > 0 ? & args -> V_341 : NULL ,
V_32 -> V_205 ) ;
F_300 ( V_148 [ V_49 ] ) ;
}
return V_23 ;
V_85:
F_53 ( & V_7 -> V_8 ) ;
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static int
F_301 ( struct V_6 * V_7 ,
struct V_152 * V_342 ,
struct V_147 * V_148 )
{
struct V_152 * V_343 ;
int V_23 ;
V_343 = F_136 ( V_148 ) ;
if ( V_342 == V_343 )
return 0 ;
if ( F_138 ( V_148 , true ) )
return 0 ;
V_23 = F_128 ( V_148 ) ;
if ( V_23 )
return V_23 ;
if ( ! F_302 ( V_7 -> V_8 . V_2 ) ) {
struct V_15 * V_117 = F_274 ( V_7 -> V_8 . V_2 ) ;
V_23 = F_141 ( V_148 ,
F_154 ( & V_117 -> V_28 . V_158 ) ,
V_117 -> V_18 . V_144 ,
NULL ,
& V_117 -> V_160 . V_344 ) ;
if ( V_23 )
return V_23 ;
F_179 ( V_7 , V_148 ) ;
} else {
int V_345 = F_303 ( V_343 , V_342 ) ;
T_6 V_285 = F_304 ( V_148 ) ;
if ( V_285 <= V_343 -> V_287 . V_288 [ V_345 ] )
return 0 ;
F_305 ( V_343 , V_342 , V_148 ) ;
V_23 = V_342 -> V_287 . V_346 ( V_342 , V_343 , V_285 ) ;
if ( V_23 )
return V_23 ;
V_343 -> V_287 . V_288 [ V_345 ] =
F_304 ( V_7 -> V_199 [ V_343 -> V_153 ] ) ;
}
return 0 ;
}
int
F_306 ( struct V_6 * V_7 ,
struct V_152 * V_342 )
{
const bool V_196 = V_7 -> V_8 . V_347 == 0 ;
struct V_147 * V_148 [ V_200 ] ;
int V_23 , V_49 , V_202 ;
if ( ! V_7 -> V_197 )
return 0 ;
if ( V_342 == NULL )
return F_59 ( V_7 , V_196 ) ;
V_202 = 0 ;
if ( V_196 ) {
if ( V_7 -> V_198 )
V_148 [ V_202 ++ ] = V_7 -> V_198 ;
} else {
for ( V_49 = 0 ; V_49 < V_200 ; V_49 ++ )
if ( V_7 -> V_199 [ V_49 ] )
V_148 [ V_202 ++ ] = V_7 -> V_199 [ V_49 ] ;
}
for ( V_49 = 0 ; V_49 < V_202 ; V_49 ++ ) {
V_23 = F_301 ( V_7 , V_342 , V_148 [ V_49 ] ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static void F_307 ( struct V_6 * V_7 )
{
T_6 V_348 , V_349 ;
F_5 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_63 & V_209 ) == 0 )
return;
F_308 () ;
V_349 = V_7 -> V_8 . V_63 ;
V_348 = V_7 -> V_8 . V_64 ;
V_7 -> V_8 . V_63 &= ~ V_209 ;
V_7 -> V_8 . V_64 &= ~ V_209 ;
F_309 ( V_7 ,
V_349 ,
V_348 ) ;
}
int F_51 ( struct V_70 * V_71 )
{
struct V_6 * V_7 = V_71 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_147 ( & V_71 -> V_350 ) )
return 0 ;
if ( ! F_310 ( & V_71 -> V_351 ) ) {
F_311 ( V_71 ) ;
return 0 ;
}
if ( V_71 -> V_352 )
return - V_75 ;
F_41 ( V_7 -> V_60 == NULL ) ;
V_23 = F_59 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
if ( F_312 ( V_71 -> V_282 ) &&
V_71 -> V_353 . type == V_354 ) {
F_307 ( V_7 ) ;
V_23 = F_112 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
F_313 ( V_71 ) ;
V_71 -> V_282 -> V_355 ( V_71 ) ;
V_71 -> V_356 = 0 ;
F_168 ( & V_71 -> V_281 ) ;
if ( F_312 ( V_71 -> V_282 ) ) {
if ( V_71 -> V_353 . type == V_354 ) {
V_7 -> V_357 = false ;
} else if ( V_71 -> V_353 . V_60 ) {
F_45 ( V_71 -> V_353 . V_60 ) ;
F_37 ( V_71 -> V_353 . V_60 ) ;
}
V_71 -> V_353 . V_60 = NULL ;
}
F_314 ( & V_71 -> V_351 ) ;
F_311 ( V_71 ) ;
if ( F_147 ( & V_7 -> V_358 ) )
F_240 ( & V_7 -> V_260 , & V_16 -> V_18 . V_276 ) ;
F_100 ( V_7 ) ;
return 0 ;
}
int F_315 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_152 * V_149 ;
int V_23 , V_49 ;
F_244 (ring, dev_priv, i) {
if ( ! V_117 . V_293 ) {
V_23 = F_316 ( V_149 , V_149 -> V_319 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_245 ( V_149 ) ;
if ( V_23 )
return V_23 ;
}
F_16 ( F_17 ( V_2 ) ) ;
return 0 ;
}
static void F_317 ( struct V_1 * V_2 , int V_329 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_13 ;
int V_359 ;
if ( F_149 ( V_2 ) -> V_169 >= 6 ) {
V_13 = V_360 ;
V_359 = V_361 ;
} else {
V_13 = V_362 ;
V_359 = V_363 ;
}
V_13 += V_329 * 8 ;
F_318 ( V_13 , 0 ) ;
F_319 ( V_13 ) ;
if ( V_7 ) {
T_6 V_17 = F_22 ( V_7 ) ;
T_4 V_364 ;
if ( V_7 -> V_11 != V_142 ) {
T_5 V_365 = V_7 -> V_366 *
( V_7 -> V_11 == V_367 ? 32 : 8 ) ;
V_17 = ( V_17 / V_365 ) * V_365 ;
}
V_364 = ( T_4 ) ( ( F_113 ( V_7 ) + V_17 - 4096 ) &
0xfffff000 ) << 32 ;
V_364 |= F_113 ( V_7 ) & 0xfffff000 ;
V_364 |= ( T_4 ) ( ( V_7 -> V_366 / 128 ) - 1 ) << V_359 ;
if ( V_7 -> V_11 == V_367 )
V_364 |= 1 << V_368 ;
V_364 |= V_369 ;
F_318 ( V_13 + 4 , V_364 >> 32 ) ;
F_319 ( V_13 + 4 ) ;
F_318 ( V_13 + 0 , V_364 ) ;
F_319 ( V_13 ) ;
} else {
F_318 ( V_13 + 4 , 0 ) ;
F_319 ( V_13 + 4 ) ;
}
}
static void F_320 ( struct V_1 * V_2 , int V_329 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_364 ;
if ( V_7 ) {
T_6 V_17 = F_22 ( V_7 ) ;
int V_370 ;
int V_371 ;
F_145 ( ( F_113 ( V_7 ) & ~ V_372 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_113 ( V_7 ) & ( V_17 - 1 ) ) ,
L_8 ,
F_113 ( V_7 ) , V_7 -> V_357 , V_17 ) ;
if ( V_7 -> V_11 == V_367 && F_321 ( V_2 ) )
V_371 = 128 ;
else
V_371 = 512 ;
V_370 = V_7 -> V_366 / V_371 ;
V_370 = F_322 ( V_370 ) - 1 ;
V_364 = F_113 ( V_7 ) ;
if ( V_7 -> V_11 == V_367 )
V_364 |= 1 << V_373 ;
V_364 |= F_323 ( V_17 ) ;
V_364 |= V_370 << V_374 ;
V_364 |= V_375 ;
} else
V_364 = 0 ;
if ( V_329 < 8 )
V_329 = V_376 + V_329 * 4 ;
else
V_329 = V_377 + ( V_329 - 8 ) * 4 ;
F_318 ( V_329 , V_364 ) ;
F_319 ( V_329 ) ;
}
static void F_324 ( struct V_1 * V_2 , int V_329 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_5 V_364 ;
if ( V_7 ) {
T_6 V_17 = F_22 ( V_7 ) ;
T_5 V_370 ;
F_145 ( ( F_113 ( V_7 ) & ~ V_378 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_113 ( V_7 ) & ( V_17 - 1 ) ) ,
L_9 ,
F_113 ( V_7 ) , V_17 ) ;
V_370 = V_7 -> V_366 / 128 ;
V_370 = F_322 ( V_370 ) - 1 ;
V_364 = F_113 ( V_7 ) ;
if ( V_7 -> V_11 == V_367 )
V_364 |= 1 << V_373 ;
V_364 |= F_325 ( V_17 ) ;
V_364 |= V_370 << V_374 ;
V_364 |= V_375 ;
} else
V_364 = 0 ;
F_318 ( V_376 + V_329 * 4 , V_364 ) ;
F_319 ( V_376 + V_329 * 4 ) ;
}
inline static bool F_326 ( struct V_6 * V_7 )
{
return V_7 && V_7 -> V_8 . V_63 & V_209 ;
}
static void F_284 ( struct V_1 * V_2 , int V_329 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_326 ( V_16 -> V_330 [ V_329 ] . V_7 ) )
F_308 () ;
F_145 ( V_7 && ( ! V_7 -> V_366 || ! V_7 -> V_11 ) ,
L_10 ,
V_7 -> V_366 , V_7 -> V_11 ) ;
if ( F_327 ( V_2 ) )
F_324 ( V_2 , V_329 , V_7 ) ;
else if ( F_328 ( V_2 ) )
F_320 ( V_2 , V_329 , V_7 ) ;
else if ( F_149 ( V_2 ) -> V_169 >= 4 )
F_317 ( V_2 , V_329 , V_7 ) ;
if ( F_326 ( V_7 ) )
F_308 () ;
}
static inline int F_329 ( struct V_15 * V_16 ,
struct V_328 * V_379 )
{
return V_379 - V_16 -> V_330 ;
}
static void F_283 ( struct V_6 * V_7 ,
struct V_328 * V_379 ,
bool V_380 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_329 = F_329 ( V_16 , V_379 ) ;
F_284 ( V_7 -> V_8 . V_2 , V_329 , V_380 ? V_7 : NULL ) ;
if ( V_380 ) {
V_7 -> V_13 = V_329 ;
V_379 -> V_7 = V_7 ;
F_240 ( & V_379 -> V_381 , & V_16 -> V_18 . V_382 ) ;
} else {
V_7 -> V_13 = V_14 ;
V_379 -> V_7 = NULL ;
F_168 ( & V_379 -> V_381 ) ;
}
V_7 -> V_12 = false ;
}
static int
F_330 ( struct V_6 * V_7 )
{
if ( V_7 -> V_284 ) {
int V_23 = F_175 ( V_7 -> V_284 ) ;
if ( V_23 )
return V_23 ;
F_241 ( & V_7 -> V_284 , NULL ) ;
}
return 0 ;
}
int
F_112 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_328 * V_379 ;
int V_23 ;
V_23 = F_330 ( V_7 ) ;
if ( V_23 )
return V_23 ;
if ( V_7 -> V_13 == V_14 )
return 0 ;
V_379 = & V_16 -> V_330 [ V_7 -> V_13 ] ;
if ( F_16 ( V_379 -> V_352 ) )
return - V_75 ;
F_4 ( V_7 ) ;
F_283 ( V_7 , V_379 , false ) ;
return 0 ;
}
static struct V_328 *
F_331 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_328 * V_329 , * V_383 ;
int V_49 ;
V_383 = NULL ;
for ( V_49 = V_16 -> V_384 ; V_49 < V_16 -> V_327 ; V_49 ++ ) {
V_329 = & V_16 -> V_330 [ V_49 ] ;
if ( ! V_329 -> V_7 )
return V_329 ;
if ( ! V_329 -> V_352 )
V_383 = V_329 ;
}
if ( V_383 == NULL )
goto V_385;
F_20 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_329 -> V_352 )
continue;
return V_329 ;
}
V_385:
if ( F_332 ( V_2 ) )
return F_333 ( - V_146 ) ;
return F_333 ( - V_386 ) ;
}
int
F_198 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_380 = V_7 -> V_11 != V_142 ;
struct V_328 * V_329 ;
int V_23 ;
if ( V_7 -> V_12 ) {
V_23 = F_330 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_7 -> V_13 != V_14 ) {
V_329 = & V_16 -> V_330 [ V_7 -> V_13 ] ;
if ( ! V_7 -> V_12 ) {
F_240 ( & V_329 -> V_381 ,
& V_16 -> V_18 . V_382 ) ;
return 0 ;
}
} else if ( V_380 ) {
if ( F_16 ( ! V_7 -> V_357 ) )
return - V_50 ;
V_329 = F_331 ( V_2 ) ;
if ( F_28 ( V_329 ) )
return F_29 ( V_329 ) ;
if ( V_329 -> V_7 ) {
struct V_6 * V_387 = V_329 -> V_7 ;
V_23 = F_330 ( V_387 ) ;
if ( V_23 )
return V_23 ;
F_4 ( V_387 ) ;
}
} else
return 0 ;
F_283 ( V_7 , V_329 , V_380 ) ;
return 0 ;
}
static bool F_334 ( struct V_70 * V_71 ,
unsigned long V_9 )
{
struct V_388 * V_389 = & V_71 -> V_351 ;
struct V_388 * V_390 ;
if ( V_71 -> V_282 -> V_18 . V_391 == NULL )
return true ;
if ( ! F_310 ( V_389 ) )
return true ;
if ( F_147 ( & V_389 -> V_392 ) )
return true ;
V_390 = F_335 ( V_389 -> V_392 . V_393 , struct V_388 , V_392 ) ;
if ( V_390 -> V_394 && ! V_390 -> V_395 && V_390 -> V_396 != V_9 )
return false ;
V_390 = F_335 ( V_389 -> V_392 . V_72 , struct V_388 , V_392 ) ;
if ( V_390 -> V_394 && ! V_389 -> V_395 && V_390 -> V_396 != V_9 )
return false ;
return true ;
}
static struct V_70 *
F_336 ( struct V_6 * V_7 ,
struct V_397 * V_282 ,
const struct V_228 * V_353 ,
unsigned V_398 ,
T_4 V_213 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_17 , V_399 , V_400 , V_401 ;
unsigned long V_108 =
V_213 & V_402 ? V_213 & V_403 : 0 ;
unsigned long V_109 =
V_213 & V_127 ? V_16 -> V_36 . V_237 : V_282 -> V_37 ;
struct V_70 * V_71 ;
int V_23 ;
if ( F_312 ( V_282 ) ) {
T_6 V_404 ;
if ( F_16 ( ! V_353 ) )
return F_333 ( - V_50 ) ;
V_404 = F_337 ( V_7 , V_353 ) ;
V_399 = F_205 ( V_2 ,
V_404 ,
V_7 -> V_11 ) ;
V_400 = F_206 ( V_2 ,
V_404 ,
V_7 -> V_11 ,
true ) ;
V_401 = F_206 ( V_2 ,
V_404 ,
V_7 -> V_11 ,
false ) ;
V_17 = V_213 & V_127 ? V_399 : V_404 ;
} else {
V_399 = F_205 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ) ;
V_400 = F_206 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ,
true ) ;
V_401 =
F_206 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ,
false ) ;
V_17 = V_213 & V_127 ? V_399 : V_7 -> V_8 . V_17 ;
}
if ( V_398 == 0 )
V_398 = V_213 & V_127 ? V_400 :
V_401 ;
if ( V_213 & V_127 && V_398 & ( V_400 - 1 ) ) {
F_216 ( L_11 ,
V_353 ? V_353 -> type : 0 ,
V_398 ) ;
return F_333 ( - V_50 ) ;
}
if ( V_17 > V_109 ) {
F_216 ( L_12 ,
V_353 ? V_353 -> type : 0 ,
V_17 ,
V_213 & V_127 ? L_13 : L_14 ,
V_109 ) ;
return F_333 ( - V_405 ) ;
}
V_23 = F_56 ( V_7 ) ;
if ( V_23 )
return F_333 ( V_23 ) ;
F_83 ( V_7 ) ;
V_71 = V_353 ? F_338 ( V_7 , V_353 ) :
F_339 ( V_7 , V_282 ) ;
if ( F_28 ( V_71 ) )
goto V_406;
V_407:
V_23 = F_340 ( & V_282 -> V_18 , & V_71 -> V_351 ,
V_17 , V_398 ,
V_7 -> V_9 ,
V_108 , V_109 ,
V_408 ,
V_409 ) ;
if ( V_23 ) {
V_23 = F_341 ( V_2 , V_282 , V_17 , V_398 ,
V_7 -> V_9 ,
V_108 , V_109 ,
V_213 ) ;
if ( V_23 == 0 )
goto V_407;
goto V_410;
}
if ( F_16 ( ! F_334 ( V_71 , V_7 -> V_9 ) ) ) {
V_23 = - V_50 ;
goto V_411;
}
F_342 ( V_71 , V_213 ) ;
V_23 = F_343 ( V_71 , V_7 -> V_9 , V_213 ) ;
if ( V_23 )
goto V_411;
F_240 ( & V_7 -> V_260 , & V_16 -> V_18 . V_412 ) ;
F_238 ( & V_71 -> V_281 , & V_282 -> V_283 ) ;
return V_71 ;
V_411:
F_314 ( & V_71 -> V_351 ) ;
V_410:
F_311 ( V_71 ) ;
V_71 = F_333 ( V_23 ) ;
V_406:
F_100 ( V_7 ) ;
return V_71 ;
}
bool
F_119 ( struct V_6 * V_7 ,
bool V_413 )
{
if ( V_7 -> V_60 == NULL )
return false ;
if ( V_7 -> V_414 || V_7 -> V_44 )
return false ;
if ( ! V_413 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) ) {
V_7 -> V_415 = true ;
return false ;
}
F_344 ( V_7 ) ;
F_345 ( V_7 -> V_60 ) ;
V_7 -> V_415 = false ;
return true ;
}
static void
F_346 ( struct V_6 * V_7 )
{
T_5 V_348 ;
if ( V_7 -> V_8 . V_64 != V_209 )
return;
F_347 () ;
V_348 = V_7 -> V_8 . V_64 ;
V_7 -> V_8 . V_64 = 0 ;
F_63 ( V_7 , false ) ;
F_309 ( V_7 ,
V_7 -> V_8 . V_63 ,
V_348 ) ;
}
static void
F_185 ( struct V_6 * V_7 )
{
T_5 V_348 ;
if ( V_7 -> V_8 . V_64 != V_65 )
return;
if ( F_119 ( V_7 , V_7 -> V_10 ) )
F_34 ( V_7 -> V_8 . V_2 ) ;
V_348 = V_7 -> V_8 . V_64 ;
V_7 -> V_8 . V_64 = 0 ;
F_63 ( V_7 , false ) ;
F_309 ( V_7 ,
V_7 -> V_8 . V_63 ,
V_348 ) ;
}
int
F_111 ( struct V_6 * V_7 , bool V_232 )
{
T_5 V_348 , V_349 ;
struct V_70 * V_71 ;
int V_23 ;
if ( V_7 -> V_8 . V_64 == V_209 )
return 0 ;
V_23 = F_59 ( V_7 , ! V_232 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_56 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_185 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_63 & V_209 ) == 0 )
F_308 () ;
V_348 = V_7 -> V_8 . V_64 ;
V_349 = V_7 -> V_8 . V_63 ;
F_41 ( ( V_7 -> V_8 . V_64 & ~ V_209 ) != 0 ) ;
V_7 -> V_8 . V_63 |= V_209 ;
if ( V_232 ) {
V_7 -> V_8 . V_63 = V_209 ;
V_7 -> V_8 . V_64 = V_209 ;
V_7 -> V_67 = 1 ;
}
if ( V_232 )
F_60 ( V_7 , NULL , V_130 ) ;
F_309 ( V_7 ,
V_349 ,
V_348 ) ;
V_71 = F_348 ( V_7 ) ;
if ( V_71 && F_310 ( & V_71 -> V_351 ) && ! V_7 -> V_197 )
F_240 ( & V_71 -> V_281 ,
& F_274 ( V_7 -> V_8 . V_2 ) -> V_36 . V_8 . V_283 ) ;
return 0 ;
}
int F_349 ( struct V_6 * V_7 ,
enum V_3 V_9 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_70 * V_71 , * V_72 ;
int V_23 ;
if ( V_7 -> V_9 == V_9 )
return 0 ;
if ( F_21 ( V_7 ) ) {
F_216 ( L_15 ) ;
return - V_75 ;
}
F_50 (vma, next, &obj->vma_list, vma_link) {
if ( ! F_334 ( V_71 , V_9 ) ) {
V_23 = F_51 ( V_71 ) ;
if ( V_23 )
return V_23 ;
}
}
if ( F_226 ( V_7 ) ) {
V_23 = F_59 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
F_307 ( V_7 ) ;
if ( F_149 ( V_2 ) -> V_169 < 6 ) {
V_23 = F_112 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
F_20 (vma, &obj->vma_list, vma_link)
if ( F_310 ( & V_71 -> V_351 ) ) {
V_23 = F_343 ( V_71 , V_9 ,
V_416 ) ;
if ( V_23 )
return V_23 ;
}
}
F_20 (vma, &obj->vma_list, vma_link)
V_71 -> V_351 . V_396 = V_9 ;
V_7 -> V_9 = V_9 ;
if ( V_7 -> V_415 &&
V_7 -> V_8 . V_64 != V_65 &&
F_3 ( V_7 ) ) {
if ( F_119 ( V_7 , true ) )
F_34 ( V_7 -> V_8 . V_2 ) ;
}
return 0 ;
}
int F_350 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_417 * args = V_30 ;
struct V_6 * V_7 ;
V_7 = F_103 ( F_104 ( V_2 , V_32 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL )
return - V_120 ;
switch ( V_7 -> V_9 ) {
case V_418 :
case V_419 :
args -> V_420 = V_421 ;
break;
case V_422 :
args -> V_420 = V_423 ;
break;
default:
args -> V_420 = V_424 ;
break;
}
F_72 ( & V_7 -> V_8 ) ;
return 0 ;
}
int F_351 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_417 * args = V_30 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_23 ;
switch ( args -> V_420 ) {
case V_424 :
V_4 = V_5 ;
break;
case V_421 :
V_4 = V_418 ;
break;
case V_423 :
V_4 = F_352 ( V_2 ) ? V_422 : V_5 ;
break;
default:
return - V_50 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_103 ( F_104 ( V_2 , V_32 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
V_23 = F_349 ( V_7 , V_4 ) ;
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_353 ( struct V_6 * V_7 ,
T_6 V_398 ,
struct V_152 * V_425 ,
const struct V_228 * V_229 )
{
T_6 V_349 , V_348 ;
int V_23 ;
V_23 = F_306 ( V_7 , V_425 ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_10 ++ ;
V_23 = F_349 ( V_7 ,
F_352 ( V_7 -> V_8 . V_2 ) ? V_422 : V_5 ) ;
if ( V_23 )
goto V_426;
V_23 = F_197 ( V_7 , V_229 , V_398 ,
V_229 -> type == V_354 ?
V_127 : 0 ) ;
if ( V_23 )
goto V_426;
F_185 ( V_7 ) ;
V_348 = V_7 -> V_8 . V_64 ;
V_349 = V_7 -> V_8 . V_63 ;
V_7 -> V_8 . V_64 = 0 ;
V_7 -> V_8 . V_63 |= V_209 ;
F_309 ( V_7 ,
V_349 ,
V_348 ) ;
return 0 ;
V_426:
V_7 -> V_10 -- ;
return V_23 ;
}
void
F_354 ( struct V_6 * V_7 ,
const struct V_228 * V_229 )
{
if ( F_16 ( V_7 -> V_10 == 0 ) )
return;
F_201 ( V_7 , V_229 ) ;
V_7 -> V_10 -- ;
}
int
F_42 ( struct V_6 * V_7 , bool V_232 )
{
T_5 V_348 , V_349 ;
int V_23 ;
if ( V_7 -> V_8 . V_64 == V_65 )
return 0 ;
V_23 = F_59 ( V_7 , ! V_232 ) ;
if ( V_23 )
return V_23 ;
F_346 ( V_7 ) ;
V_348 = V_7 -> V_8 . V_64 ;
V_349 = V_7 -> V_8 . V_63 ;
if ( ( V_7 -> V_8 . V_63 & V_65 ) == 0 ) {
F_119 ( V_7 , false ) ;
V_7 -> V_8 . V_63 |= V_65 ;
}
F_41 ( ( V_7 -> V_8 . V_64 & ~ V_65 ) != 0 ) ;
if ( V_232 ) {
V_7 -> V_8 . V_63 = V_65 ;
V_7 -> V_8 . V_64 = V_65 ;
}
if ( V_232 )
F_60 ( V_7 , NULL , V_83 ) ;
F_309 ( V_7 ,
V_349 ,
V_348 ) ;
return 0 ;
}
static int
F_355 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_186 * V_80 = V_32 -> V_205 ;
unsigned long V_427 = V_157 - V_428 ;
struct V_147 * V_185 , * V_429 = NULL ;
unsigned V_158 ;
int V_23 ;
V_23 = F_10 ( & V_16 -> V_28 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_125 ( & V_16 -> V_28 , false ) ;
if ( V_23 )
return V_23 ;
F_7 ( & V_80 -> V_18 . V_187 ) ;
F_20 (request, &file_priv->mm.request_list, client_list) {
if ( F_139 ( V_185 -> V_170 , V_427 ) )
break;
V_429 = V_185 ;
}
V_158 = F_154 ( & V_16 -> V_28 . V_158 ) ;
if ( V_429 )
F_181 ( V_429 ) ;
F_8 ( & V_80 -> V_18 . V_187 ) ;
if ( V_429 == NULL )
return 0 ;
V_23 = F_141 ( V_429 , V_158 , true , NULL , NULL ) ;
if ( V_23 == 0 )
F_260 ( V_16 -> V_303 , & V_16 -> V_18 . V_304 , 0 ) ;
F_300 ( V_429 ) ;
return V_23 ;
}
static bool
F_356 ( struct V_70 * V_71 , T_5 V_398 , T_4 V_213 )
{
struct V_6 * V_7 = V_71 -> V_7 ;
if ( V_398 &&
V_71 -> V_351 . V_108 & ( V_398 - 1 ) )
return true ;
if ( V_213 & V_127 && ! V_7 -> V_357 )
return true ;
if ( V_213 & V_402 &&
V_71 -> V_351 . V_108 < ( V_213 & V_403 ) )
return true ;
return false ;
}
static int
F_357 ( struct V_6 * V_7 ,
struct V_397 * V_282 ,
const struct V_228 * V_353 ,
T_5 V_398 ,
T_4 V_213 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_70 * V_71 ;
unsigned V_356 ;
int V_23 ;
if ( F_16 ( V_282 == & V_16 -> V_18 . V_430 -> V_8 ) )
return - V_172 ;
if ( F_16 ( V_213 & ( V_431 | V_127 ) && ! F_312 ( V_282 ) ) )
return - V_50 ;
if ( F_16 ( ( V_213 & ( V_127 | V_431 ) ) == V_127 ) )
return - V_50 ;
if ( F_16 ( F_312 ( V_282 ) != ! ! V_353 ) )
return - V_50 ;
V_71 = V_353 ? F_358 ( V_7 , V_353 ) :
F_359 ( V_7 , V_282 ) ;
if ( F_28 ( V_71 ) )
return F_29 ( V_71 ) ;
if ( V_71 ) {
if ( F_16 ( V_71 -> V_352 == V_432 ) )
return - V_75 ;
if ( F_356 ( V_71 , V_398 , V_213 ) ) {
unsigned long V_57 ;
V_57 = V_353 ? F_199 ( V_7 , V_353 ) :
F_360 ( V_7 , V_282 ) ;
F_145 ( V_71 -> V_352 ,
L_16
L_17
L_18 ,
V_353 ? L_19 : L_20 ,
V_57 ,
V_398 ,
! ! ( V_213 & V_127 ) ,
V_7 -> V_357 ) ;
V_23 = F_51 ( V_71 ) ;
if ( V_23 )
return V_23 ;
V_71 = NULL ;
}
}
V_356 = V_71 ? V_71 -> V_356 : 0 ;
if ( V_71 == NULL || ! F_310 ( & V_71 -> V_351 ) ) {
V_71 = F_336 ( V_7 , V_282 , V_353 , V_398 ,
V_213 ) ;
if ( F_28 ( V_71 ) )
return F_29 ( V_71 ) ;
} else {
V_23 = F_343 ( V_71 , V_7 -> V_9 , V_213 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_353 && V_353 -> type == V_354 &&
( V_356 ^ V_71 -> V_356 ) & V_433 ) {
bool V_132 , V_434 ;
T_6 V_399 , V_400 ;
V_399 = F_205 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ) ;
V_400 = F_206 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ,
true ) ;
V_434 = ( V_71 -> V_351 . V_17 == V_399 &&
( V_71 -> V_351 . V_108 & ( V_400 - 1 ) ) == 0 ) ;
V_132 = ( V_71 -> V_351 . V_108 + V_399 <=
V_16 -> V_36 . V_237 ) ;
V_7 -> V_357 = V_132 && V_434 ;
F_16 ( V_213 & V_127 && ! V_7 -> V_357 ) ;
}
V_71 -> V_352 ++ ;
return 0 ;
}
int
F_361 ( struct V_6 * V_7 ,
struct V_397 * V_282 ,
T_5 V_398 ,
T_4 V_213 )
{
return F_357 ( V_7 , V_282 ,
F_312 ( V_282 ) ? & V_230 : NULL ,
V_398 , V_213 ) ;
}
int
F_197 ( struct V_6 * V_7 ,
const struct V_228 * V_229 ,
T_5 V_398 ,
T_4 V_213 )
{
if ( F_202 ( ! V_229 , L_21 ) )
return - V_50 ;
return F_357 ( V_7 , F_362 ( V_7 ) , V_229 ,
V_398 , V_213 | V_431 ) ;
}
void
F_201 ( struct V_6 * V_7 ,
const struct V_228 * V_229 )
{
struct V_70 * V_71 = F_358 ( V_7 , V_229 ) ;
F_41 ( ! V_71 ) ;
F_16 ( V_71 -> V_352 == 0 ) ;
F_16 ( ! F_363 ( V_7 , V_229 ) ) ;
-- V_71 -> V_352 ;
}
bool
F_364 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 != V_14 ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_70 * V_435 = F_348 ( V_7 ) ;
F_16 ( ! V_435 ||
V_16 -> V_330 [ V_7 -> V_13 ] . V_352 >
V_435 -> V_352 ) ;
V_16 -> V_330 [ V_7 -> V_13 ] . V_352 ++ ;
return true ;
} else
return false ;
}
void
F_365 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 != V_14 ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
F_16 ( V_16 -> V_330 [ V_7 -> V_13 ] . V_352 <= 0 ) ;
V_16 -> V_330 [ V_7 -> V_13 ] . V_352 -- ;
}
}
int
F_366 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_436 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_103 ( F_104 ( V_2 , V_32 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
V_23 = F_298 ( V_7 ) ;
if ( V_23 )
goto V_208;
F_367 ( V_200 > 16 ) ;
args -> V_437 = V_7 -> V_197 << 16 ;
if ( V_7 -> V_198 )
args -> V_437 |= V_7 -> V_198 -> V_149 -> V_153 ;
V_208:
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_368 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_80 )
{
return F_355 ( V_2 , V_80 ) ;
}
int
F_369 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_80 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_438 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 ;
switch ( args -> V_61 ) {
case V_66 :
case V_69 :
break;
default:
return - V_50 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_103 ( F_104 ( V_2 , V_80 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
if ( F_21 ( V_7 ) ) {
V_23 = - V_50 ;
goto V_85;
}
if ( V_7 -> V_60 &&
V_7 -> V_11 != V_142 &&
V_16 -> V_273 & V_274 ) {
if ( V_7 -> V_61 == V_69 )
F_100 ( V_7 ) ;
if ( args -> V_61 == V_69 )
F_83 ( V_7 ) ;
}
if ( V_7 -> V_61 != V_62 )
V_7 -> V_61 = args -> V_61 ;
if ( V_7 -> V_61 == V_66 && V_7 -> V_60 == NULL )
F_219 ( V_7 ) ;
args -> V_439 = V_7 -> V_61 != V_62 ;
V_85:
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void F_370 ( struct V_6 * V_7 ,
const struct V_258 * V_77 )
{
int V_49 ;
F_371 ( & V_7 -> V_260 ) ;
for ( V_49 = 0 ; V_49 < V_200 ; V_49 ++ )
F_371 ( & V_7 -> V_279 [ V_49 ] ) ;
F_371 ( & V_7 -> V_440 ) ;
F_371 ( & V_7 -> V_358 ) ;
F_371 ( & V_7 -> V_441 ) ;
V_7 -> V_77 = V_77 ;
V_7 -> V_13 = V_14 ;
V_7 -> V_61 = V_69 ;
F_6 ( V_7 -> V_8 . V_2 -> V_27 , V_7 -> V_8 . V_17 ) ;
}
struct V_6 * F_70 ( struct V_1 * V_2 ,
T_1 V_17 )
{
struct V_6 * V_7 ;
struct V_39 * V_40 ;
T_13 V_442 ;
V_7 = F_64 ( V_2 ) ;
if ( V_7 == NULL )
return NULL ;
if ( F_372 ( V_2 , & V_7 -> V_8 , V_17 ) != 0 ) {
F_66 ( V_7 ) ;
return NULL ;
}
V_442 = V_443 | V_444 ;
if ( F_373 ( V_2 ) || F_374 ( V_2 ) ) {
V_442 &= ~ V_445 ;
V_442 |= V_272 ;
}
V_40 = F_25 ( V_7 -> V_8 . V_41 ) -> V_42 ;
F_375 ( V_40 , V_442 ) ;
F_370 ( V_7 , & V_446 ) ;
V_7 -> V_8 . V_64 = V_65 ;
V_7 -> V_8 . V_63 = V_65 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_9 = V_418 ;
} else
V_7 -> V_9 = V_5 ;
F_376 ( V_7 ) ;
return V_7 ;
}
static bool F_377 ( struct V_6 * V_7 )
{
if ( V_7 -> V_61 != V_69 )
return false ;
if ( V_7 -> V_8 . V_41 == NULL )
return true ;
return F_378 ( & V_7 -> V_8 . V_41 -> V_447 ) == 1 ;
}
void F_379 ( struct V_212 * V_448 )
{
struct V_6 * V_7 = F_103 ( V_448 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_70 * V_71 , * V_72 ;
F_122 ( V_16 ) ;
F_380 ( V_7 ) ;
F_50 (vma, next, &obj->vma_list, vma_link) {
int V_23 ;
V_71 -> V_352 = 0 ;
V_23 = F_51 ( V_71 ) ;
if ( F_16 ( V_23 == - V_179 ) ) {
bool V_449 ;
V_449 = V_16 -> V_18 . V_144 ;
V_16 -> V_18 . V_144 = false ;
F_16 ( F_51 ( V_71 ) ) ;
V_16 -> V_18 . V_144 = V_449 ;
}
}
if ( V_7 -> V_414 )
F_100 ( V_7 ) ;
F_16 ( V_7 -> V_450 ) ;
if ( V_7 -> V_60 && V_7 -> V_61 == V_69 &&
V_16 -> V_273 & V_274 &&
V_7 -> V_11 != V_142 )
F_100 ( V_7 ) ;
if ( F_16 ( V_7 -> V_259 ) )
V_7 -> V_259 = 0 ;
if ( F_377 ( V_7 ) )
V_7 -> V_61 = V_66 ;
F_52 ( V_7 ) ;
F_213 ( V_7 ) ;
F_41 ( V_7 -> V_60 ) ;
if ( V_7 -> V_8 . V_451 )
F_381 ( & V_7 -> V_8 , NULL ) ;
if ( V_7 -> V_77 -> V_452 )
V_7 -> V_77 -> V_452 ( V_7 ) ;
F_382 ( & V_7 -> V_8 ) ;
F_9 ( V_16 , V_7 -> V_8 . V_17 ) ;
F_37 ( V_7 -> V_453 ) ;
F_66 ( V_7 ) ;
F_124 ( V_16 ) ;
}
struct V_70 * F_359 ( struct V_6 * V_7 ,
struct V_397 * V_282 )
{
struct V_70 * V_71 ;
F_20 (vma, &obj->vma_list, vma_link) {
if ( F_312 ( V_71 -> V_282 ) &&
V_71 -> V_353 . type != V_354 )
continue;
if ( V_71 -> V_282 == V_282 )
return V_71 ;
}
return NULL ;
}
struct V_70 * F_358 ( struct V_6 * V_7 ,
const struct V_228 * V_229 )
{
struct V_397 * V_454 = F_362 ( V_7 ) ;
struct V_70 * V_71 ;
if ( F_202 ( ! V_229 , L_21 ) )
return F_333 ( - V_50 ) ;
F_20 (vma, &obj->vma_list, vma_link)
if ( V_71 -> V_282 == V_454 &&
F_383 ( & V_71 -> V_353 , V_229 ) )
return V_71 ;
return NULL ;
}
void F_311 ( struct V_70 * V_71 )
{
struct V_397 * V_282 = NULL ;
F_16 ( V_71 -> V_351 . V_394 ) ;
if ( ! F_147 ( & V_71 -> V_455 ) )
return;
V_282 = V_71 -> V_282 ;
if ( ! F_312 ( V_282 ) )
F_384 ( F_385 ( V_282 ) ) ;
F_165 ( & V_71 -> V_350 ) ;
F_67 ( F_274 ( V_71 -> V_7 -> V_8 . V_2 ) -> V_456 , V_71 ) ;
}
static void
F_386 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_152 * V_149 ;
int V_49 ;
F_244 (ring, dev_priv, i)
V_16 -> V_457 . V_458 ( V_149 ) ;
}
int
F_387 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 = 0 ;
F_19 ( & V_2 -> V_29 ) ;
V_23 = F_315 ( V_2 ) ;
if ( V_23 )
goto V_203;
F_246 ( V_2 ) ;
F_386 ( V_2 ) ;
F_23 ( & V_2 -> V_29 ) ;
F_388 ( & V_16 -> V_28 . V_459 ) ;
F_388 ( & V_16 -> V_18 . V_304 ) ;
F_389 ( & V_16 -> V_18 . V_334 ) ;
F_16 ( V_16 -> V_18 . V_437 ) ;
return 0 ;
V_203:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_390 ( struct V_152 * V_149 , int V_460 )
{
struct V_1 * V_2 = V_149 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_461 = V_462 + ( V_460 * 0x200 ) ;
T_6 * V_463 = V_16 -> V_464 . V_463 [ V_460 ] ;
int V_49 , V_23 ;
if ( ! F_391 ( V_2 ) || ! V_463 )
return 0 ;
V_23 = F_392 ( V_149 , V_465 / 4 * 3 ) ;
if ( V_23 )
return V_23 ;
for ( V_49 = 0 ; V_49 < V_465 ; V_49 += 4 ) {
F_393 ( V_149 , F_394 ( 1 ) ) ;
F_393 ( V_149 , V_461 + V_49 ) ;
F_393 ( V_149 , V_463 [ V_49 / 4 ] ) ;
}
F_395 ( V_149 ) ;
return V_23 ;
}
void F_396 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_149 ( V_2 ) -> V_169 < 5 ||
V_16 -> V_18 . V_466 == V_467 )
return;
F_318 ( V_468 , F_397 ( V_468 ) |
V_469 ) ;
if ( F_398 ( V_2 ) )
return;
F_318 ( V_470 , F_397 ( V_470 ) | V_471 ) ;
if ( F_399 ( V_2 ) )
F_318 ( V_472 , F_400 ( V_473 ) ) ;
else if ( F_401 ( V_2 ) )
F_318 ( V_472 , F_400 ( V_474 ) ) ;
else if ( F_402 ( V_2 ) )
F_318 ( V_475 , F_400 ( V_476 ) ) ;
else
F_403 () ;
}
static bool
F_404 ( struct V_1 * V_2 )
{
if ( ! F_405 ( V_2 ) )
return false ;
if ( F_399 ( V_2 ) && V_2 -> V_477 -> V_478 < 8 ) {
F_406 ( L_22
L_23 ) ;
return false ;
}
return true ;
}
static void F_407 ( struct V_1 * V_2 , T_6 V_8 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
F_318 ( F_408 ( V_8 ) , 0 ) ;
F_318 ( F_409 ( V_8 ) , 0 ) ;
F_318 ( F_410 ( V_8 ) , 0 ) ;
F_318 ( F_411 ( V_8 ) , 0 ) ;
}
static void F_412 ( struct V_1 * V_2 )
{
if ( F_413 ( V_2 ) ) {
F_407 ( V_2 , V_479 ) ;
F_407 ( V_2 , V_480 ) ;
F_407 ( V_2 , V_481 ) ;
F_407 ( V_2 , V_482 ) ;
F_407 ( V_2 , V_483 ) ;
} else if ( F_327 ( V_2 ) ) {
F_407 ( V_2 , V_480 ) ;
F_407 ( V_2 , V_481 ) ;
} else if ( F_328 ( V_2 ) ) {
F_407 ( V_2 , V_479 ) ;
F_407 ( V_2 , V_484 ) ;
}
}
int F_414 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
V_23 = F_415 ( V_2 ) ;
if ( V_23 )
return V_23 ;
if ( F_416 ( V_2 ) ) {
V_23 = F_417 ( V_2 ) ;
if ( V_23 )
goto V_485;
}
if ( F_404 ( V_2 ) ) {
V_23 = F_418 ( V_2 ) ;
if ( V_23 )
goto V_486;
}
if ( F_419 ( V_2 ) ) {
V_23 = F_420 ( V_2 ) ;
if ( V_23 )
goto V_487;
}
if ( F_421 ( V_2 ) ) {
V_23 = F_422 ( V_2 ) ;
if ( V_23 )
goto V_488;
}
V_23 = F_249 ( V_2 , ( ( T_6 ) ~ 0 - 0x1000 ) ) ;
if ( V_23 )
goto V_489;
return 0 ;
V_489:
F_423 ( & V_16 -> V_149 [ V_490 ] ) ;
V_488:
F_423 ( & V_16 -> V_149 [ V_491 ] ) ;
V_487:
F_423 ( & V_16 -> V_149 [ V_492 ] ) ;
V_486:
F_423 ( & V_16 -> V_149 [ V_493 ] ) ;
V_485:
F_423 ( & V_16 -> V_149 [ V_494 ] ) ;
return V_23 ;
}
int
F_424 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_152 * V_149 ;
int V_23 , V_49 ;
if ( F_149 ( V_2 ) -> V_169 < 6 && ! F_425 () )
return - V_26 ;
F_426 ( V_16 , V_495 ) ;
if ( V_16 -> V_496 )
F_318 ( V_497 , F_397 ( V_497 ) | F_427 ( 0xf ) ) ;
if ( F_428 ( V_2 ) )
F_318 ( V_498 , F_429 ( V_2 ) ?
V_499 : V_500 ) ;
if ( F_430 ( V_2 ) ) {
if ( F_431 ( V_2 ) ) {
T_6 V_501 = F_397 ( V_502 ) ;
V_501 &= ~ ( V_503 | V_504 ) ;
F_318 ( V_502 , V_501 ) ;
} else if ( F_149 ( V_2 ) -> V_169 >= 7 ) {
T_6 V_501 = F_397 ( V_505 ) ;
V_501 &= ~ V_506 ;
F_318 ( V_505 , V_501 ) ;
}
}
F_396 ( V_2 ) ;
F_412 ( V_2 ) ;
F_244 (ring, dev_priv, i) {
V_23 = V_149 -> V_507 ( V_149 ) ;
if ( V_23 )
goto V_85;
}
for ( V_49 = 0 ; V_49 < F_432 ( V_2 ) ; V_49 ++ )
F_390 ( & V_16 -> V_149 [ V_494 ] , V_49 ) ;
V_23 = F_433 ( V_2 ) ;
if ( V_23 && V_23 != - V_26 ) {
F_13 ( L_24 , V_23 ) ;
F_434 ( V_2 ) ;
}
V_23 = F_435 ( V_16 ) ;
if ( V_23 && V_23 != - V_26 ) {
F_13 ( L_25 , V_23 ) ;
F_434 ( V_2 ) ;
goto V_85;
}
V_85:
F_436 ( V_16 , V_495 ) ;
return V_23 ;
}
int F_437 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
V_117 . V_293 = F_438 ( V_2 ,
V_117 . V_293 ) ;
F_19 ( & V_2 -> V_29 ) ;
if ( F_439 ( V_2 ) ) {
F_318 ( V_508 , V_509 ) ;
if ( F_440 ( ( F_397 ( V_510 ) &
V_511 ) , 10 ) )
F_441 ( L_26 ) ;
}
if ( ! V_117 . V_293 ) {
V_16 -> V_457 . V_512 = V_513 ;
V_16 -> V_457 . V_514 = F_414 ;
V_16 -> V_457 . V_515 = F_423 ;
V_16 -> V_457 . V_458 = V_516 ;
} else {
V_16 -> V_457 . V_512 = V_517 ;
V_16 -> V_457 . V_514 = V_518 ;
V_16 -> V_457 . V_515 = V_519 ;
V_16 -> V_457 . V_458 = V_520 ;
}
F_426 ( V_16 , V_495 ) ;
V_23 = F_442 ( V_2 ) ;
if ( V_23 )
goto V_521;
F_443 ( V_2 ) ;
V_23 = F_444 ( V_2 ) ;
if ( V_23 )
goto V_521;
V_23 = V_16 -> V_457 . V_514 ( V_2 ) ;
if ( V_23 )
goto V_521;
V_23 = F_424 ( V_2 ) ;
if ( V_23 == - V_26 ) {
F_13 ( L_27 ) ;
F_445 ( V_522 , & V_16 -> V_28 . V_158 ) ;
V_23 = 0 ;
}
V_521:
F_436 ( V_16 , V_495 ) ;
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void
F_434 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_152 * V_149 ;
int V_49 ;
F_244 (ring, dev_priv, i)
V_16 -> V_457 . V_515 ( V_149 ) ;
}
static void
F_446 ( struct V_152 * V_149 )
{
F_371 ( & V_149 -> V_280 ) ;
F_371 ( & V_149 -> V_195 ) ;
}
void F_447 ( struct V_15 * V_16 ,
struct V_397 * V_282 )
{
if ( ! F_312 ( V_282 ) )
F_448 ( & V_282 -> V_18 , V_282 -> V_108 , V_282 -> V_37 ) ;
V_282 -> V_2 = V_16 -> V_2 ;
F_371 ( & V_282 -> V_280 ) ;
F_371 ( & V_282 -> V_283 ) ;
F_371 ( & V_282 -> V_523 ) ;
F_238 ( & V_282 -> V_523 , & V_16 -> V_524 ) ;
}
void
F_449 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_49 ;
V_16 -> V_86 =
F_450 ( L_28 ,
sizeof( struct V_6 ) , 0 ,
V_525 ,
NULL ) ;
V_16 -> V_456 =
F_450 ( L_29 ,
sizeof( struct V_70 ) , 0 ,
V_525 ,
NULL ) ;
V_16 -> V_201 =
F_450 ( L_30 ,
sizeof( struct V_147 ) , 0 ,
V_525 ,
NULL ) ;
F_371 ( & V_16 -> V_524 ) ;
F_447 ( V_16 , & V_16 -> V_36 . V_8 ) ;
F_371 ( & V_16 -> V_526 ) ;
F_371 ( & V_16 -> V_18 . V_276 ) ;
F_371 ( & V_16 -> V_18 . V_412 ) ;
F_371 ( & V_16 -> V_18 . V_382 ) ;
for ( V_49 = 0 ; V_49 < V_200 ; V_49 ++ )
F_446 ( & V_16 -> V_149 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_527 ; V_49 ++ )
F_371 ( & V_16 -> V_330 [ V_49 ] . V_381 ) ;
F_451 ( & V_16 -> V_18 . V_304 ,
F_293 ) ;
F_451 ( & V_16 -> V_18 . V_334 ,
F_295 ) ;
F_452 ( & V_16 -> V_28 . V_24 ) ;
V_16 -> V_528 = V_529 ;
if ( F_149 ( V_2 ) -> V_169 >= 7 && ! F_439 ( V_2 ) )
V_16 -> V_327 = 32 ;
else if ( F_149 ( V_2 ) -> V_169 >= 4 || F_453 ( V_2 ) || F_454 ( V_2 ) || F_207 ( V_2 ) )
V_16 -> V_327 = 16 ;
else
V_16 -> V_327 = 8 ;
if ( F_455 ( V_2 ) )
V_16 -> V_327 =
F_397 ( F_456 ( V_530 . V_531 ) ) ;
F_371 ( & V_16 -> V_18 . V_382 ) ;
F_282 ( V_2 ) ;
F_457 ( V_2 ) ;
F_452 ( & V_16 -> V_532 ) ;
V_16 -> V_18 . V_144 = true ;
F_458 ( V_16 ) ;
F_459 ( & V_16 -> V_533 . V_187 ) ;
}
void F_460 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_186 * V_80 = V_32 -> V_205 ;
F_7 ( & V_80 -> V_18 . V_187 ) ;
while ( ! F_147 ( & V_80 -> V_18 . V_195 ) ) {
struct V_147 * V_185 ;
V_185 = F_173 ( & V_80 -> V_18 . V_195 ,
struct V_147 ,
V_188 ) ;
F_165 ( & V_185 -> V_188 ) ;
V_185 -> V_80 = NULL ;
}
F_8 ( & V_80 -> V_18 . V_187 ) ;
if ( ! F_147 ( & V_80 -> V_160 . V_534 ) ) {
F_7 ( & F_274 ( V_2 ) -> V_160 . V_535 ) ;
F_165 ( & V_80 -> V_160 . V_534 ) ;
F_8 ( & F_274 ( V_2 ) -> V_160 . V_535 ) ;
}
}
int F_461 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_186 * V_80 ;
int V_23 ;
F_441 ( L_31 ) ;
V_80 = F_462 ( sizeof( * V_80 ) , V_54 ) ;
if ( ! V_80 )
return - V_55 ;
V_32 -> V_205 = V_80 ;
V_80 -> V_16 = V_2 -> V_27 ;
V_80 -> V_32 = V_32 ;
F_371 ( & V_80 -> V_160 . V_534 ) ;
F_463 ( & V_80 -> V_18 . V_187 ) ;
F_371 ( & V_80 -> V_18 . V_195 ) ;
V_23 = F_464 ( V_2 , V_32 ) ;
if ( V_23 )
F_37 ( V_80 ) ;
return V_23 ;
}
void F_465 ( struct V_6 * V_387 ,
struct V_6 * V_536 ,
unsigned V_450 )
{
if ( V_387 ) {
F_16 ( ! F_129 ( & V_387 -> V_8 . V_2 -> V_29 ) ) ;
F_16 ( ! ( V_387 -> V_450 & V_450 ) ) ;
V_387 -> V_450 &= ~ V_450 ;
}
if ( V_536 ) {
F_16 ( ! F_129 ( & V_536 -> V_8 . V_2 -> V_29 ) ) ;
F_16 ( V_536 -> V_450 & V_450 ) ;
V_536 -> V_450 |= V_450 ;
}
}
unsigned long
F_360 ( struct V_6 * V_537 ,
struct V_397 * V_282 )
{
struct V_15 * V_16 = V_537 -> V_8 . V_2 -> V_27 ;
struct V_70 * V_71 ;
F_16 ( V_282 == & V_16 -> V_18 . V_430 -> V_8 ) ;
F_20 (vma, &o->vma_list, vma_link) {
if ( F_312 ( V_71 -> V_282 ) &&
V_71 -> V_353 . type != V_354 )
continue;
if ( V_71 -> V_282 == V_282 )
return V_71 -> V_351 . V_108 ;
}
F_145 ( 1 , L_32 ,
F_312 ( V_282 ) ? L_33 : L_20 ) ;
return - 1 ;
}
unsigned long
F_199 ( struct V_6 * V_537 ,
const struct V_228 * V_229 )
{
struct V_397 * V_454 = F_362 ( V_537 ) ;
struct V_70 * V_71 ;
F_20 (vma, &o->vma_list, vma_link)
if ( V_71 -> V_282 == V_454 &&
F_383 ( & V_71 -> V_353 , V_229 ) )
return V_71 -> V_351 . V_108 ;
F_145 ( 1 , L_34 , V_229 -> type ) ;
return - 1 ;
}
bool F_466 ( struct V_6 * V_537 ,
struct V_397 * V_282 )
{
struct V_70 * V_71 ;
F_20 (vma, &o->vma_list, vma_link) {
if ( F_312 ( V_71 -> V_282 ) &&
V_71 -> V_353 . type != V_354 )
continue;
if ( V_71 -> V_282 == V_282 && F_310 ( & V_71 -> V_351 ) )
return true ;
}
return false ;
}
bool F_363 ( struct V_6 * V_537 ,
const struct V_228 * V_229 )
{
struct V_397 * V_454 = F_362 ( V_537 ) ;
struct V_70 * V_71 ;
F_20 (vma, &o->vma_list, vma_link)
if ( V_71 -> V_282 == V_454 &&
F_383 ( & V_71 -> V_353 , V_229 ) &&
F_310 ( & V_71 -> V_351 ) )
return true ;
return false ;
}
bool F_226 ( struct V_6 * V_537 )
{
struct V_70 * V_71 ;
F_20 (vma, &o->vma_list, vma_link)
if ( F_310 ( & V_71 -> V_351 ) )
return true ;
return false ;
}
unsigned long F_467 ( struct V_6 * V_537 ,
struct V_397 * V_282 )
{
struct V_15 * V_16 = V_537 -> V_8 . V_2 -> V_27 ;
struct V_70 * V_71 ;
F_16 ( V_282 == & V_16 -> V_18 . V_430 -> V_8 ) ;
F_41 ( F_147 ( & V_537 -> V_358 ) ) ;
F_20 (vma, &o->vma_list, vma_link) {
if ( F_312 ( V_71 -> V_282 ) &&
V_71 -> V_353 . type != V_354 )
continue;
if ( V_71 -> V_282 == V_282 )
return V_71 -> V_351 . V_17 ;
}
return 0 ;
}
bool F_21 ( struct V_6 * V_7 )
{
struct V_70 * V_71 ;
F_20 (vma, &obj->vma_list, vma_link)
if ( V_71 -> V_352 > 0 )
return true ;
return false ;
}

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
V_7 -> V_61 = true ;
return 0 ;
}
static void
F_40 ( struct V_6 * V_7 )
{
int V_23 ;
F_41 ( V_7 -> V_62 == V_63 ) ;
V_23 = F_42 ( V_7 , true ) ;
if ( V_23 ) {
F_16 ( V_23 != - V_26 ) ;
V_7 -> V_8 . V_64 = V_7 -> V_8 . V_65 = V_66 ;
}
if ( V_7 -> V_62 == V_67 )
V_7 -> V_68 = 0 ;
if ( V_7 -> V_68 ) {
struct V_39 * V_40 = F_25 ( V_7 -> V_8 . V_41 ) -> V_42 ;
char * V_43 = V_7 -> V_44 -> V_43 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_7 -> V_8 . V_17 / V_51 ; V_49 ++ ) {
struct V_52 * V_52 ;
char * V_69 ;
V_52 = F_27 ( V_40 , V_49 ) ;
if ( F_28 ( V_52 ) )
continue;
V_69 = F_30 ( V_52 ) ;
F_31 ( V_43 , V_51 ) ;
memcpy ( V_69 , V_43 , V_51 ) ;
F_32 ( V_69 ) ;
F_43 ( V_52 ) ;
if ( V_7 -> V_62 == V_70 )
F_44 ( V_52 ) ;
F_33 ( V_52 ) ;
V_43 += V_51 ;
}
V_7 -> V_68 = 0 ;
}
F_45 ( V_7 -> V_60 ) ;
F_37 ( V_7 -> V_60 ) ;
V_7 -> V_61 = false ;
}
static void
F_46 ( struct V_6 * V_7 )
{
F_47 ( V_7 -> V_8 . V_2 , V_7 -> V_44 ) ;
}
static int
F_48 ( struct V_6 * V_7 )
{
struct V_71 * V_72 , * V_73 ;
int V_23 ;
F_49 ( & V_7 -> V_8 ) ;
F_50 (vma, next, &obj->vma_list, vma_link)
if ( F_51 ( V_72 ) )
break;
V_23 = F_52 ( V_7 ) ;
F_53 ( & V_7 -> V_8 ) ;
return V_23 ;
}
int
F_54 ( struct V_6 * V_7 ,
int V_74 )
{
T_2 * V_75 ;
int V_23 ;
if ( V_7 -> V_44 ) {
if ( ( unsigned long ) V_7 -> V_44 -> V_43 & ( V_74 - 1 ) )
return - V_76 ;
return 0 ;
}
if ( V_7 -> V_62 != V_70 )
return - V_77 ;
if ( V_7 -> V_8 . V_41 == NULL )
return - V_50 ;
V_23 = F_48 ( V_7 ) ;
if ( V_23 )
return V_23 ;
V_75 = F_55 ( V_7 -> V_8 . V_2 , V_7 -> V_8 . V_17 , V_74 ) ;
if ( ! V_75 )
return - V_55 ;
V_7 -> V_44 = V_75 ;
V_7 -> V_78 = & V_79 ;
return F_56 ( V_7 ) ;
}
static int
F_57 ( struct V_6 * V_7 ,
struct V_80 * args ,
struct V_31 * V_81 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
void * V_43 = V_7 -> V_44 -> V_43 + args -> V_57 ;
char T_3 * V_82 = F_58 ( args -> V_83 ) ;
int V_23 ;
V_23 = F_59 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
if ( F_60 ( V_43 , V_82 , args -> V_17 ) ) {
unsigned long V_84 ;
F_23 ( & V_2 -> V_29 ) ;
V_84 = F_61 ( V_43 , V_82 , args -> V_17 ) ;
F_19 ( & V_2 -> V_29 ) ;
if ( V_84 )
return - V_77 ;
}
F_31 ( V_43 , args -> V_17 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
void * F_62 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
return F_63 ( V_16 -> V_85 , V_54 ) ;
}
void F_64 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
F_65 ( V_16 -> V_85 , V_7 ) ;
}
static int
F_66 ( struct V_31 * V_32 ,
struct V_1 * V_2 ,
T_4 V_17 ,
T_5 * V_86 )
{
struct V_6 * V_7 ;
int V_23 ;
T_6 V_87 ;
V_17 = F_67 ( V_17 , V_51 ) ;
if ( V_17 == 0 )
return - V_50 ;
V_7 = F_68 ( V_2 , V_17 ) ;
if ( V_7 == NULL )
return - V_55 ;
V_23 = F_69 ( V_32 , & V_7 -> V_8 , & V_87 ) ;
F_70 ( & V_7 -> V_8 ) ;
if ( V_23 )
return V_23 ;
* V_86 = V_87 ;
return 0 ;
}
int
F_71 ( struct V_31 * V_32 ,
struct V_1 * V_2 ,
struct V_88 * args )
{
args -> V_89 = F_72 ( args -> V_90 * F_73 ( args -> V_91 , 8 ) , 64 ) ;
args -> V_17 = args -> V_89 * args -> V_92 ;
return F_66 ( V_32 , V_2 ,
args -> V_17 , & args -> V_87 ) ;
}
int
F_74 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_93 * args = V_30 ;
return F_66 ( V_32 , V_2 ,
args -> V_17 , & args -> V_87 ) ;
}
static inline int
F_75 ( char T_3 * V_94 ,
const char * V_95 , int V_96 ,
int V_58 )
{
int V_23 , V_97 = 0 ;
while ( V_58 > 0 ) {
int V_98 = F_72 ( V_96 + 1 , 64 ) ;
int V_99 = F_76 ( V_98 - V_96 , V_58 ) ;
int V_100 = V_96 ^ 64 ;
V_23 = F_77 ( V_94 + V_97 ,
V_95 + V_100 ,
V_99 ) ;
if ( V_23 )
return V_23 + V_58 ;
V_97 += V_99 ;
V_96 += V_99 ;
V_58 -= V_99 ;
}
return 0 ;
}
static inline int
F_78 ( char * V_95 , int V_96 ,
const char T_3 * V_94 ,
int V_58 )
{
int V_23 , V_97 = 0 ;
while ( V_58 > 0 ) {
int V_98 = F_72 ( V_96 + 1 , 64 ) ;
int V_99 = F_76 ( V_98 - V_96 , V_58 ) ;
int V_100 = V_96 ^ 64 ;
V_23 = F_79 ( V_95 + V_100 ,
V_94 + V_97 ,
V_99 ) ;
if ( V_23 )
return V_23 + V_58 ;
V_97 += V_99 ;
V_96 += V_99 ;
V_58 -= V_99 ;
}
return 0 ;
}
int F_80 ( struct V_6 * V_7 ,
int * V_101 )
{
int V_23 ;
* V_101 = 0 ;
if ( ! V_7 -> V_8 . V_41 )
return - V_50 ;
if ( ! ( V_7 -> V_8 . V_64 & V_66 ) ) {
* V_101 = ! F_1 ( V_7 -> V_8 . V_2 ,
V_7 -> V_9 ) ;
V_23 = F_59 ( V_7 , true ) ;
if ( V_23 )
return V_23 ;
F_81 ( V_7 ) ;
}
V_23 = F_56 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_82 ( V_7 ) ;
return V_23 ;
}
static int
F_83 ( struct V_52 * V_52 , int V_102 , int V_103 ,
char T_3 * V_82 ,
bool V_104 , bool V_101 )
{
char * V_43 ;
int V_23 ;
if ( F_84 ( V_104 ) )
return - V_50 ;
V_43 = F_30 ( V_52 ) ;
if ( V_101 )
F_31 ( V_43 + V_102 ,
V_103 ) ;
V_23 = F_85 ( V_82 ,
V_43 + V_102 ,
V_103 ) ;
F_32 ( V_43 ) ;
return V_23 ? - V_77 : 0 ;
}
static void
F_86 ( char * V_105 , unsigned long V_58 ,
bool V_106 )
{
if ( F_84 ( V_106 ) ) {
unsigned long V_107 = ( unsigned long ) V_105 ;
unsigned long V_108 = ( unsigned long ) V_105 + V_58 ;
V_107 = F_87 ( V_107 , 128 ) ;
V_108 = F_88 ( V_108 , 128 ) ;
F_31 ( ( void * ) V_107 , V_108 - V_107 ) ;
} else {
F_31 ( V_105 , V_58 ) ;
}
}
static int
F_89 ( struct V_52 * V_52 , int V_102 , int V_103 ,
char T_3 * V_82 ,
bool V_104 , bool V_101 )
{
char * V_43 ;
int V_23 ;
V_43 = F_90 ( V_52 ) ;
if ( V_101 )
F_86 ( V_43 + V_102 ,
V_103 ,
V_104 ) ;
if ( V_104 )
V_23 = F_75 ( V_82 ,
V_43 , V_102 ,
V_103 ) ;
else
V_23 = F_77 ( V_82 ,
V_43 + V_102 ,
V_103 ) ;
F_91 ( V_52 ) ;
return V_23 ? - V_77 : 0 ;
}
static int
F_92 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_109 * args ,
struct V_31 * V_32 )
{
char T_3 * V_82 ;
T_7 V_110 ;
T_8 V_57 ;
int V_102 , V_103 , V_23 = 0 ;
int V_111 , V_104 ;
int V_112 = 0 ;
int V_101 = 0 ;
struct V_113 V_114 ;
V_82 = F_58 ( args -> V_83 ) ;
V_110 = args -> V_17 ;
V_111 = F_26 ( V_7 ) ;
V_23 = F_80 ( V_7 , & V_101 ) ;
if ( V_23 )
return V_23 ;
V_57 = args -> V_57 ;
F_93 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_52 * V_52 = F_94 ( & V_114 ) ;
if ( V_110 <= 0 )
break;
V_102 = F_95 ( V_57 ) ;
V_103 = V_110 ;
if ( ( V_102 + V_103 ) > V_51 )
V_103 = V_51 - V_102 ;
V_104 = V_111 &&
( F_96 ( V_52 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_83 ( V_52 , V_102 , V_103 ,
V_82 , V_104 ,
V_101 ) ;
if ( V_23 == 0 )
goto V_115;
F_23 ( & V_2 -> V_29 ) ;
if ( F_97 ( ! V_116 . V_117 ) && ! V_112 ) {
V_23 = F_98 ( V_82 , V_110 ) ;
( void ) V_23 ;
V_112 = 1 ;
}
V_23 = F_89 ( V_52 , V_102 , V_103 ,
V_82 , V_104 ,
V_101 ) ;
F_19 ( & V_2 -> V_29 ) ;
if ( V_23 )
goto V_118;
V_115:
V_110 -= V_103 ;
V_82 += V_103 ;
V_57 += V_103 ;
}
V_118:
F_99 ( V_7 ) ;
return V_23 ;
}
int
F_100 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_109 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_101 ( V_119 ,
F_58 ( args -> V_83 ) ,
args -> V_17 ) )
return - V_77 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_102 ( F_103 ( V_2 , V_32 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
if ( args -> V_57 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_57 ) {
V_23 = - V_50 ;
goto V_118;
}
if ( ! V_7 -> V_8 . V_41 ) {
V_23 = - V_50 ;
goto V_118;
}
F_104 ( V_7 , args -> V_57 , args -> V_17 ) ;
V_23 = F_92 ( V_2 , V_7 , args , V_32 ) ;
V_118:
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static inline int
F_105 ( struct V_122 * V_40 ,
T_8 V_123 , int V_124 ,
char T_3 * V_82 ,
int V_58 )
{
void T_9 * V_125 ;
void * V_43 ;
unsigned long V_84 ;
V_125 = F_106 ( V_40 , V_123 ) ;
V_43 = ( void V_126 * ) V_125 + V_124 ;
V_84 = F_60 ( V_43 ,
V_82 , V_58 ) ;
F_107 ( V_125 ) ;
return V_84 ;
}
static int
F_108 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_80 * args ,
struct V_31 * V_32 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_7 V_110 ;
T_8 V_57 , V_123 ;
char T_3 * V_82 ;
int V_124 , V_103 , V_23 ;
V_23 = F_109 ( V_7 , 0 , V_127 | V_128 ) ;
if ( V_23 )
goto V_118;
V_23 = F_110 ( V_7 , true ) ;
if ( V_23 )
goto V_129;
V_23 = F_111 ( V_7 ) ;
if ( V_23 )
goto V_129;
V_82 = F_58 ( args -> V_83 ) ;
V_110 = args -> V_17 ;
V_57 = F_112 ( V_7 ) + args -> V_57 ;
while ( V_110 > 0 ) {
V_123 = V_57 & V_130 ;
V_124 = F_95 ( V_57 ) ;
V_103 = V_110 ;
if ( ( V_124 + V_110 ) > V_51 )
V_103 = V_51 - V_124 ;
if ( F_105 ( V_16 -> V_36 . V_131 , V_123 ,
V_124 , V_82 , V_103 ) ) {
V_23 = - V_77 ;
goto V_129;
}
V_110 -= V_103 ;
V_82 += V_103 ;
V_57 += V_103 ;
}
V_129:
F_113 ( V_7 ) ;
V_118:
return V_23 ;
}
static int
F_114 ( struct V_52 * V_52 , int V_102 , int V_103 ,
char T_3 * V_82 ,
bool V_104 ,
bool V_132 ,
bool V_133 )
{
char * V_43 ;
int V_23 ;
if ( F_84 ( V_104 ) )
return - V_50 ;
V_43 = F_30 ( V_52 ) ;
if ( V_132 )
F_31 ( V_43 + V_102 ,
V_103 ) ;
V_23 = F_115 ( V_43 + V_102 ,
V_82 , V_103 ) ;
if ( V_133 )
F_31 ( V_43 + V_102 ,
V_103 ) ;
F_32 ( V_43 ) ;
return V_23 ? - V_77 : 0 ;
}
static int
F_116 ( struct V_52 * V_52 , int V_102 , int V_103 ,
char T_3 * V_82 ,
bool V_104 ,
bool V_132 ,
bool V_133 )
{
char * V_43 ;
int V_23 ;
V_43 = F_90 ( V_52 ) ;
if ( F_84 ( V_132 || V_104 ) )
F_86 ( V_43 + V_102 ,
V_103 ,
V_104 ) ;
if ( V_104 )
V_23 = F_78 ( V_43 , V_102 ,
V_82 ,
V_103 ) ;
else
V_23 = F_79 ( V_43 + V_102 ,
V_82 ,
V_103 ) ;
if ( V_133 )
F_86 ( V_43 + V_102 ,
V_103 ,
V_104 ) ;
F_91 ( V_52 ) ;
return V_23 ? - V_77 : 0 ;
}
static int
F_117 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_80 * args ,
struct V_31 * V_32 )
{
T_7 V_110 ;
T_8 V_57 ;
char T_3 * V_82 ;
int V_102 , V_103 , V_23 = 0 ;
int V_111 , V_104 ;
int V_134 = 0 ;
int V_133 = 0 ;
int V_132 = 0 ;
struct V_113 V_114 ;
V_82 = F_58 ( args -> V_83 ) ;
V_110 = args -> V_17 ;
V_111 = F_26 ( V_7 ) ;
if ( V_7 -> V_8 . V_65 != V_66 ) {
V_133 = F_3 ( V_7 ) ;
V_23 = F_59 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
F_81 ( V_7 ) ;
}
if ( ( V_7 -> V_8 . V_64 & V_66 ) == 0 )
V_132 =
! F_1 ( V_2 , V_7 -> V_9 ) ;
V_23 = F_56 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_82 ( V_7 ) ;
V_57 = args -> V_57 ;
V_7 -> V_68 = 1 ;
F_93 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_52 * V_52 = F_94 ( & V_114 ) ;
int V_135 ;
if ( V_110 <= 0 )
break;
V_102 = F_95 ( V_57 ) ;
V_103 = V_110 ;
if ( ( V_102 + V_103 ) > V_51 )
V_103 = V_51 - V_102 ;
V_135 = V_132 &&
( ( V_102 | V_103 )
& ( V_136 . V_137 - 1 ) ) ;
V_104 = V_111 &&
( F_96 ( V_52 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_114 ( V_52 , V_102 , V_103 ,
V_82 , V_104 ,
V_135 ,
V_133 ) ;
if ( V_23 == 0 )
goto V_115;
V_134 = 1 ;
F_23 ( & V_2 -> V_29 ) ;
V_23 = F_116 ( V_52 , V_102 , V_103 ,
V_82 , V_104 ,
V_135 ,
V_133 ) ;
F_19 ( & V_2 -> V_29 ) ;
if ( V_23 )
goto V_118;
V_115:
V_110 -= V_103 ;
V_82 += V_103 ;
V_57 += V_103 ;
}
V_118:
F_99 ( V_7 ) ;
if ( V_134 ) {
if ( ! V_133 &&
V_7 -> V_8 . V_65 != V_66 ) {
if ( F_118 ( V_7 , V_7 -> V_10 ) )
F_34 ( V_2 ) ;
}
}
if ( V_133 )
F_34 ( V_2 ) ;
return V_23 ;
}
int
F_119 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_80 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_101 ( V_138 ,
F_58 ( args -> V_83 ) ,
args -> V_17 ) )
return - V_77 ;
if ( F_97 ( ! V_116 . V_117 ) ) {
V_23 = F_120 ( F_58 ( args -> V_83 ) ,
args -> V_17 ) ;
if ( V_23 )
return - V_77 ;
}
F_121 ( V_16 ) ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
goto V_139;
V_7 = F_102 ( F_103 ( V_2 , V_32 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
if ( args -> V_57 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_57 ) {
V_23 = - V_50 ;
goto V_118;
}
if ( ! V_7 -> V_8 . V_41 ) {
V_23 = - V_50 ;
goto V_118;
}
F_122 ( V_7 , args -> V_57 , args -> V_17 ) ;
V_23 = - V_77 ;
if ( V_7 -> V_11 == V_140 &&
V_7 -> V_8 . V_65 != V_66 &&
F_3 ( V_7 ) ) {
V_23 = F_108 ( V_2 , V_7 , args , V_32 ) ;
}
if ( V_23 == - V_77 || V_23 == - V_141 ) {
if ( V_7 -> V_44 )
V_23 = F_57 ( V_7 , args , V_32 ) ;
else
V_23 = F_117 ( V_2 , V_7 , args , V_32 ) ;
}
V_118:
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
V_139:
F_123 ( V_16 ) ;
return V_23 ;
}
int
F_124 ( struct V_22 * error ,
bool V_142 )
{
if ( F_125 ( error ) ) {
if ( ! V_142 )
return - V_26 ;
if ( F_126 ( error ) )
return - V_26 ;
if ( ! error -> V_143 )
return - V_144 ;
}
return 0 ;
}
int
F_127 ( struct V_145 * V_146 )
{
int V_23 ;
F_16 ( ! F_128 ( & V_146 -> V_147 -> V_2 -> V_29 ) ) ;
V_23 = 0 ;
if ( V_146 == V_146 -> V_147 -> V_148 )
V_23 = F_129 ( V_146 -> V_147 ) ;
return V_23 ;
}
static void F_130 ( unsigned long V_30 )
{
F_131 ( (struct V_149 * ) V_30 ) ;
}
static bool F_132 ( struct V_15 * V_16 ,
struct V_150 * V_147 )
{
return F_133 ( V_147 -> V_151 , & V_16 -> V_28 . V_152 ) ;
}
static bool F_134 ( struct V_153 * V_81 )
{
if ( V_81 == NULL )
return true ;
return ! F_135 ( & V_81 -> V_154 , true ) ;
}
int F_136 ( struct V_145 * V_146 ,
unsigned V_155 ,
bool V_142 ,
T_10 * V_156 ,
struct V_153 * V_81 )
{
struct V_150 * V_147 = F_137 ( V_146 ) ;
struct V_1 * V_2 = V_147 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
const bool V_157 =
F_138 ( V_16 -> V_28 . V_158 ) & F_139 ( V_147 ) ;
F_140 ( V_159 ) ;
unsigned long V_160 ;
T_10 V_161 , V_162 ;
int V_23 ;
F_141 ( ! F_142 ( V_16 ) , L_2 ) ;
if ( F_143 ( V_146 , true ) )
return 0 ;
V_160 = V_156 ?
V_163 + F_144 ( ( V_164 ) * V_156 ) : 0 ;
if ( F_145 ( V_2 ) -> V_165 >= 6 && V_147 -> V_151 == V_166 && F_134 ( V_81 ) ) {
F_146 ( V_16 ) ;
if ( V_81 )
F_147 ( V_16 -> V_167 ,
& V_81 -> V_18 . V_168 ,
F_148 ( 100 ) ) ;
}
if ( ! V_157 && F_16 ( ! V_147 -> V_169 ( V_147 ) ) )
return - V_170 ;
F_149 ( V_146 ) ;
V_161 = F_150 () ;
for (; ; ) {
struct V_171 V_172 ;
F_151 ( & V_147 -> V_173 , & V_159 ,
V_142 ? V_174 : V_175 ) ;
if ( V_155 != F_152 ( & V_16 -> V_28 . V_155 ) ) {
V_23 = F_124 ( & V_16 -> V_28 , V_142 ) ;
if ( V_23 == 0 )
V_23 = - V_144 ;
break;
}
if ( F_143 ( V_146 , false ) ) {
V_23 = 0 ;
break;
}
if ( V_142 && F_153 ( V_176 ) ) {
V_23 = - V_177 ;
break;
}
if ( V_156 && F_154 ( V_163 , V_160 ) ) {
V_23 = - V_178 ;
break;
}
V_172 . V_179 = NULL ;
if ( V_156 || F_132 ( V_16 , V_147 ) ) {
unsigned long V_180 ;
F_155 ( & V_172 , F_130 , ( unsigned long ) V_176 ) ;
V_180 = F_132 ( V_16 , V_147 ) ? V_163 + 1 : V_160 ;
F_156 ( & V_172 , V_180 ) ;
}
F_157 () ;
if ( V_172 . V_179 ) {
F_158 ( & V_172 ) ;
F_159 ( & V_172 ) ;
}
}
V_162 = F_150 () ;
F_160 ( V_146 ) ;
if ( ! V_157 )
V_147 -> V_181 ( V_147 ) ;
F_161 ( & V_147 -> V_173 , & V_159 ) ;
if ( V_156 ) {
T_10 V_182 = * V_156 - ( V_162 - V_161 ) ;
* V_156 = V_182 < 0 ? 0 : V_182 ;
if ( V_23 == - V_178 && * V_156 < F_162 ( 1 ) * 1000 )
* V_156 = 0 ;
}
return V_23 ;
}
int
F_163 ( struct V_145 * V_146 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
bool V_142 ;
unsigned V_155 ;
int V_23 ;
F_41 ( V_146 == NULL ) ;
V_2 = V_146 -> V_147 -> V_2 ;
V_16 = V_2 -> V_27 ;
V_142 = V_16 -> V_18 . V_142 ;
F_41 ( ! F_128 ( & V_2 -> V_29 ) ) ;
V_23 = F_124 ( & V_16 -> V_28 , V_142 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_127 ( V_146 ) ;
if ( V_23 )
return V_23 ;
V_155 = F_152 ( & V_16 -> V_28 . V_155 ) ;
F_164 ( V_146 ) ;
V_23 = F_136 ( V_146 , V_155 ,
V_142 , NULL , NULL ) ;
F_165 ( V_146 ) ;
return V_23 ;
}
static int
F_166 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_183 )
return 0 ;
F_167 ( & V_7 -> V_184 , NULL ) ;
return 0 ;
}
static T_11 int
F_59 ( struct V_6 * V_7 ,
bool V_185 )
{
struct V_145 * V_146 ;
int V_23 ;
V_146 = V_185 ? V_7 -> V_184 : V_7 -> V_186 ;
if ( ! V_146 )
return 0 ;
V_23 = F_163 ( V_146 ) ;
if ( V_23 )
return V_23 ;
return F_166 ( V_7 ) ;
}
static T_11 int
F_168 ( struct V_6 * V_7 ,
struct V_153 * V_81 ,
bool V_185 )
{
struct V_145 * V_146 ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
unsigned V_155 ;
int V_23 ;
F_41 ( ! F_128 ( & V_2 -> V_29 ) ) ;
F_41 ( ! V_16 -> V_18 . V_142 ) ;
V_146 = V_185 ? V_7 -> V_184 : V_7 -> V_186 ;
if ( ! V_146 )
return 0 ;
V_23 = F_124 ( & V_16 -> V_28 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = F_127 ( V_146 ) ;
if ( V_23 )
return V_23 ;
V_155 = F_152 ( & V_16 -> V_28 . V_155 ) ;
F_164 ( V_146 ) ;
F_23 ( & V_2 -> V_29 ) ;
V_23 = F_136 ( V_146 , V_155 , true , NULL , V_81 ) ;
F_19 ( & V_2 -> V_29 ) ;
F_165 ( V_146 ) ;
if ( V_23 )
return V_23 ;
return F_166 ( V_7 ) ;
}
int
F_169 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_187 * args = V_30 ;
struct V_6 * V_7 ;
T_5 V_64 = args -> V_64 ;
T_5 V_65 = args -> V_65 ;
int V_23 ;
if ( V_65 & V_188 )
return - V_50 ;
if ( V_64 & V_188 )
return - V_50 ;
if ( V_65 != 0 && V_64 != V_65 )
return - V_50 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_102 ( F_103 ( V_2 , V_32 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
V_23 = F_168 ( V_7 ,
V_32 -> V_189 ,
! V_65 ) ;
if ( V_23 )
goto V_190;
if ( V_64 & V_191 )
V_23 = F_110 ( V_7 , V_65 != 0 ) ;
else
V_23 = F_42 ( V_7 , V_65 != 0 ) ;
V_190:
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_170 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_192 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_102 ( F_103 ( V_2 , V_32 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
if ( V_7 -> V_10 )
F_171 ( V_7 ) ;
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_172 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_193 * args = V_30 ;
struct V_194 * V_7 ;
unsigned long V_105 ;
if ( args -> V_195 & ~ ( V_196 ) )
return - V_50 ;
if ( args -> V_195 & V_196 && ! V_197 )
return - V_170 ;
V_7 = F_103 ( V_2 , V_32 , args -> V_87 ) ;
if ( V_7 == NULL )
return - V_120 ;
if ( ! V_7 -> V_41 ) {
F_70 ( V_7 ) ;
return - V_50 ;
}
V_105 = F_173 ( V_7 -> V_41 , 0 , args -> V_17 ,
V_198 | V_199 , V_200 ,
args -> V_57 ) ;
if ( args -> V_195 & V_196 ) {
struct V_201 * V_18 = V_176 -> V_18 ;
struct V_202 * V_72 ;
F_174 ( & V_18 -> V_203 ) ;
V_72 = F_175 ( V_18 , V_105 ) ;
if ( V_72 )
V_72 -> V_204 =
F_176 ( F_177 ( V_72 -> V_205 ) ) ;
else
V_105 = - V_55 ;
F_178 ( & V_18 -> V_203 ) ;
}
F_70 ( V_7 ) ;
if ( F_28 ( ( void * ) V_105 ) )
return V_105 ;
args -> V_206 = ( T_4 ) V_105 ;
return 0 ;
}
int F_179 ( struct V_202 * V_72 , struct V_207 * V_208 )
{
struct V_6 * V_7 = F_102 ( V_72 -> V_209 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_12 V_124 ;
unsigned long V_210 ;
int V_23 = 0 ;
bool V_211 = ! ! ( V_208 -> V_195 & V_212 ) ;
F_121 ( V_16 ) ;
V_124 = ( ( unsigned long ) V_208 -> V_213 - V_72 -> V_214 ) >>
V_215 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
goto V_118;
F_180 ( V_7 , V_124 , true , V_211 ) ;
V_23 = F_168 ( V_7 , NULL , ! V_211 ) ;
if ( V_23 )
goto V_121;
if ( V_7 -> V_9 != V_5 && ! F_2 ( V_2 ) ) {
V_23 = - V_77 ;
goto V_121;
}
V_23 = F_109 ( V_7 , 0 , V_127 ) ;
if ( V_23 )
goto V_121;
V_23 = F_110 ( V_7 , V_211 ) ;
if ( V_23 )
goto V_216;
V_23 = F_181 ( V_7 ) ;
if ( V_23 )
goto V_216;
V_210 = V_16 -> V_36 . V_217 + F_112 ( V_7 ) ;
V_210 >>= V_215 ;
if ( ! V_7 -> V_218 ) {
unsigned long V_17 = F_182 (unsigned long,
vma->vm_end - vma->vm_start,
obj->base.size) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_17 > > V_215 ; V_49 ++ ) {
V_23 = F_183 ( V_72 ,
( unsigned long ) V_72 -> V_214 + V_49 * V_51 ,
V_210 + V_49 ) ;
if ( V_23 )
break;
}
V_7 -> V_218 = true ;
} else
V_23 = F_183 ( V_72 ,
( unsigned long ) V_208 -> V_213 ,
V_210 + V_124 ) ;
V_216:
F_113 ( V_7 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
V_118:
switch ( V_23 ) {
case - V_26 :
if ( ! F_126 ( & V_16 -> V_28 ) ) {
V_23 = V_219 ;
break;
}
case - V_144 :
case 0 :
case - V_177 :
case - V_220 :
case - V_76 :
V_23 = V_221 ;
break;
case - V_55 :
V_23 = V_222 ;
break;
case - V_141 :
case - V_77 :
V_23 = V_219 ;
break;
default:
F_184 ( V_23 , L_3 , V_23 ) ;
V_23 = V_219 ;
break;
}
F_123 ( V_16 ) ;
return V_23 ;
}
void
F_5 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_218 )
return;
F_185 ( & V_7 -> V_8 . V_223 ,
V_7 -> V_8 . V_2 -> V_224 -> V_42 ) ;
V_7 -> V_218 = false ;
}
void
F_186 ( struct V_15 * V_16 )
{
struct V_6 * V_7 ;
F_20 (obj, &dev_priv->mm.bound_list, global_list)
F_5 ( V_7 ) ;
}
T_5
F_187 ( struct V_1 * V_2 , T_5 V_17 , int V_11 )
{
T_5 V_225 ;
if ( F_145 ( V_2 ) -> V_165 >= 4 ||
V_11 == V_140 )
return V_17 ;
if ( F_145 ( V_2 ) -> V_165 == 3 )
V_225 = 1024 * 1024 ;
else
V_225 = 512 * 1024 ;
while ( V_225 < V_17 )
V_225 <<= 1 ;
return V_225 ;
}
T_5
F_188 ( struct V_1 * V_2 , T_5 V_17 ,
int V_11 , bool V_226 )
{
if ( F_145 ( V_2 ) -> V_165 >= 4 || ( ! V_226 && F_189 ( V_2 ) ) ||
V_11 == V_140 )
return 4096 ;
return F_187 ( V_2 , V_17 , V_11 ) ;
}
static int F_190 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_191 ( & V_7 -> V_8 . V_223 ) )
return 0 ;
V_16 -> V_18 . V_227 = true ;
V_23 = F_192 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_141 )
goto V_118;
F_193 ( V_16 ,
V_7 -> V_8 . V_17 >> V_215 ,
V_228 |
V_229 |
V_230 ) ;
V_23 = F_192 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_141 )
goto V_118;
F_194 ( V_16 ) ;
V_23 = F_192 ( & V_7 -> V_8 ) ;
V_118:
V_16 -> V_18 . V_227 = false ;
return V_23 ;
}
static void F_195 ( struct V_6 * V_7 )
{
F_196 ( & V_7 -> V_8 ) ;
}
int
F_197 ( struct V_31 * V_32 ,
struct V_1 * V_2 ,
T_5 V_87 ,
T_4 * V_57 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_102 ( F_103 ( V_2 , V_32 , V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
if ( V_7 -> V_8 . V_17 > V_16 -> V_36 . V_231 ) {
V_23 = - V_232 ;
goto V_118;
}
if ( V_7 -> V_62 != V_70 ) {
F_198 ( L_4 ) ;
V_23 = - V_77 ;
goto V_118;
}
V_23 = F_190 ( V_7 ) ;
if ( V_23 )
goto V_118;
* V_57 = F_199 ( & V_7 -> V_8 . V_223 ) ;
V_118:
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_200 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_233 * args = V_30 ;
return F_197 ( V_32 , V_2 , args -> V_87 , & args -> V_57 ) ;
}
static inline int
F_201 ( struct V_6 * V_7 )
{
return V_7 -> V_62 == V_67 ;
}
static void
F_202 ( struct V_6 * V_7 )
{
F_195 ( V_7 ) ;
if ( V_7 -> V_8 . V_41 == NULL )
return;
F_203 ( F_25 ( V_7 -> V_8 . V_41 ) , 0 , ( T_8 ) - 1 ) ;
V_7 -> V_62 = V_63 ;
}
static void
F_204 ( struct V_6 * V_7 )
{
struct V_39 * V_40 ;
switch ( V_7 -> V_62 ) {
case V_67 :
F_202 ( V_7 ) ;
case V_63 :
return;
}
if ( V_7 -> V_8 . V_41 == NULL )
return;
V_40 = F_25 ( V_7 -> V_8 . V_41 ) -> V_42 ,
F_205 ( V_40 , 0 , ( T_8 ) - 1 ) ;
}
static void
F_206 ( struct V_6 * V_7 )
{
struct V_113 V_114 ;
int V_23 ;
F_41 ( V_7 -> V_62 == V_63 ) ;
V_23 = F_42 ( V_7 , true ) ;
if ( V_23 ) {
F_16 ( V_23 != - V_26 ) ;
F_118 ( V_7 , true ) ;
V_7 -> V_8 . V_64 = V_7 -> V_8 . V_65 = V_66 ;
}
if ( F_26 ( V_7 ) )
F_207 ( V_7 ) ;
if ( V_7 -> V_62 == V_67 )
V_7 -> V_68 = 0 ;
F_93 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_52 * V_52 = F_94 ( & V_114 ) ;
if ( V_7 -> V_68 )
F_43 ( V_52 ) ;
if ( V_7 -> V_62 == V_70 )
F_44 ( V_52 ) ;
F_33 ( V_52 ) ;
}
V_7 -> V_68 = 0 ;
F_45 ( V_7 -> V_60 ) ;
F_37 ( V_7 -> V_60 ) ;
}
int
F_52 ( struct V_6 * V_7 )
{
const struct V_234 * V_78 = V_7 -> V_78 ;
if ( V_7 -> V_60 == NULL )
return 0 ;
if ( V_7 -> V_235 )
return - V_76 ;
F_41 ( F_208 ( V_7 ) ) ;
F_209 ( & V_7 -> V_236 ) ;
V_78 -> V_237 ( V_7 ) ;
V_7 -> V_60 = NULL ;
F_204 ( V_7 ) ;
return 0 ;
}
unsigned long
F_193 ( struct V_15 * V_16 ,
long V_238 , unsigned V_195 )
{
const struct {
struct V_239 * V_240 ;
unsigned int V_241 ;
} V_242 [] = {
{ & V_16 -> V_18 . V_243 , V_229 } ,
{ & V_16 -> V_18 . V_244 , V_228 } ,
{ NULL , 0 } ,
} , * V_245 ;
unsigned long V_246 = 0 ;
for ( V_245 = V_242 ; V_245 -> V_240 ; V_245 ++ ) {
struct V_239 V_247 ;
if ( ( V_195 & V_245 -> V_241 ) == 0 )
continue;
F_210 ( & V_247 ) ;
while ( V_246 < V_238 && ! F_211 ( V_245 -> V_240 ) ) {
struct V_6 * V_7 ;
struct V_71 * V_72 , * V_248 ;
V_7 = F_212 ( V_245 -> V_240 ,
F_213 ( * V_7 ) , V_236 ) ;
F_214 ( & V_7 -> V_236 , & V_247 ) ;
if ( V_195 & V_230 &&
! F_201 ( V_7 ) )
continue;
F_49 ( & V_7 -> V_8 ) ;
F_50 (vma, v,
&obj->vma_list, vma_link)
if ( F_51 ( V_72 ) )
break;
if ( F_52 ( V_7 ) == 0 )
V_246 += V_7 -> V_8 . V_17 >> V_215 ;
F_53 ( & V_7 -> V_8 ) ;
}
F_215 ( & V_247 , V_245 -> V_240 ) ;
}
return V_246 ;
}
static unsigned long
F_194 ( struct V_15 * V_16 )
{
F_216 ( V_16 -> V_2 ) ;
return F_193 ( V_16 , V_249 ,
V_228 | V_229 ) ;
}
static int
F_217 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_250 , V_49 ;
struct V_39 * V_40 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_113 V_114 ;
struct V_52 * V_52 ;
unsigned long V_251 = 0 ;
T_13 V_252 ;
F_41 ( V_7 -> V_8 . V_64 & V_188 ) ;
F_41 ( V_7 -> V_8 . V_65 & V_188 ) ;
V_46 = F_35 ( sizeof( * V_46 ) , V_54 ) ;
if ( V_46 == NULL )
return - V_55 ;
V_250 = V_7 -> V_8 . V_17 / V_51 ;
if ( F_36 ( V_46 , V_250 , V_54 ) ) {
F_37 ( V_46 ) ;
return - V_55 ;
}
V_40 = F_25 ( V_7 -> V_8 . V_41 ) -> V_42 ;
V_252 = F_218 ( V_40 ) ;
V_252 |= V_253 | V_254 | V_255 ;
V_252 &= ~ ( V_256 | V_257 ) ;
V_48 = V_46 -> V_56 ;
V_46 -> V_258 = 0 ;
for ( V_49 = 0 ; V_49 < V_250 ; V_49 ++ ) {
V_52 = F_219 ( V_40 , V_49 , V_252 ) ;
if ( F_28 ( V_52 ) ) {
F_193 ( V_16 ,
V_250 ,
V_228 |
V_229 |
V_230 ) ;
V_52 = F_219 ( V_40 , V_49 , V_252 ) ;
}
if ( F_28 ( V_52 ) ) {
F_194 ( V_16 ) ;
V_52 = F_27 ( V_40 , V_49 ) ;
if ( F_28 ( V_52 ) )
goto V_259;
}
#ifdef F_220
if ( F_221 () ) {
V_46 -> V_258 ++ ;
F_222 ( V_48 , V_52 , V_51 , 0 ) ;
V_48 = F_223 ( V_48 ) ;
continue;
}
#endif
if ( ! V_49 || F_224 ( V_52 ) != V_251 + 1 ) {
if ( V_49 )
V_48 = F_223 ( V_48 ) ;
V_46 -> V_258 ++ ;
F_222 ( V_48 , V_52 , V_51 , 0 ) ;
} else {
V_48 -> V_58 += V_51 ;
}
V_251 = F_224 ( V_52 ) ;
F_16 ( ( V_252 & V_260 ) && ( V_251 >= 0x00100000UL ) ) ;
}
#ifdef F_220
if ( ! F_221 () )
#endif
F_225 ( V_48 ) ;
V_7 -> V_60 = V_46 ;
if ( F_26 ( V_7 ) )
F_226 ( V_7 ) ;
if ( V_7 -> V_11 != V_140 &&
V_16 -> V_261 & V_262 )
F_82 ( V_7 ) ;
return 0 ;
V_259:
F_225 ( V_48 ) ;
F_93 (st->sgl, &sg_iter, st->nents, 0 )
F_33 ( F_94 ( & V_114 ) ) ;
F_45 ( V_46 ) ;
F_37 ( V_46 ) ;
if ( F_29 ( V_52 ) == - V_141 )
return - V_55 ;
else
return F_29 ( V_52 ) ;
}
int
F_56 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
const struct V_234 * V_78 = V_7 -> V_78 ;
int V_23 ;
if ( V_7 -> V_60 )
return 0 ;
if ( V_7 -> V_62 != V_70 ) {
F_198 ( L_5 ) ;
return - V_77 ;
}
F_41 ( V_7 -> V_235 ) ;
V_23 = V_78 -> V_263 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_227 ( & V_7 -> V_236 , & V_16 -> V_18 . V_243 ) ;
return 0 ;
}
static void
F_228 ( struct V_6 * V_7 ,
struct V_150 * V_147 )
{
struct V_145 * V_146 ;
struct V_150 * V_264 ;
F_41 ( V_147 == NULL ) ;
V_146 = F_229 ( V_147 ) ;
V_264 = F_137 ( V_7 -> V_186 ) ;
if ( V_264 != V_147 && V_7 -> V_184 ) {
F_167 ( & V_7 -> V_184 , V_146 ) ;
}
if ( ! V_7 -> V_183 ) {
F_49 ( & V_7 -> V_8 ) ;
V_7 -> V_183 = 1 ;
}
F_214 ( & V_7 -> V_265 , & V_147 -> V_266 ) ;
F_167 ( & V_7 -> V_186 , V_146 ) ;
}
void F_230 ( struct V_71 * V_72 ,
struct V_150 * V_147 )
{
F_214 ( & V_72 -> V_267 , & V_72 -> V_268 -> V_266 ) ;
return F_228 ( V_72 -> V_7 , V_147 ) ;
}
static void
F_231 ( struct V_6 * V_7 )
{
struct V_71 * V_72 ;
F_41 ( V_7 -> V_8 . V_65 & ~ V_188 ) ;
F_41 ( ! V_7 -> V_183 ) ;
F_20 (vma, &obj->vma_list, vma_link) {
if ( ! F_211 ( & V_72 -> V_267 ) )
F_214 ( & V_72 -> V_267 , & V_72 -> V_268 -> V_269 ) ;
}
F_232 ( V_7 , true ) ;
F_233 ( & V_7 -> V_265 ) ;
F_167 ( & V_7 -> V_186 , NULL ) ;
F_167 ( & V_7 -> V_184 , NULL ) ;
V_7 -> V_8 . V_65 = 0 ;
F_167 ( & V_7 -> V_270 , NULL ) ;
V_7 -> V_183 = 0 ;
F_53 ( & V_7 -> V_8 ) ;
F_16 ( F_17 ( V_2 ) ) ;
}
static void
F_81 ( struct V_6 * V_7 )
{
if ( V_7 -> V_186 == NULL )
return;
if ( F_143 ( V_7 -> V_186 , true ) )
F_231 ( V_7 ) ;
}
static int
F_234 ( struct V_1 * V_2 , T_6 V_271 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_150 * V_147 ;
int V_23 , V_49 , V_272 ;
F_235 (ring, dev_priv, i) {
V_23 = F_236 ( V_147 ) ;
if ( V_23 )
return V_23 ;
}
F_237 ( V_2 ) ;
F_235 (ring, dev_priv, i) {
F_238 ( V_147 , V_271 ) ;
for ( V_272 = 0 ; V_272 < F_239 ( V_147 -> V_273 . V_274 ) ; V_272 ++ )
V_147 -> V_273 . V_274 [ V_272 ] = 0 ;
}
return 0 ;
}
int F_240 ( struct V_1 * V_2 , T_6 V_271 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( V_271 == 0 )
return - V_50 ;
V_23 = F_234 ( V_2 , V_271 - 1 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_275 = V_271 ;
V_16 -> V_276 = V_271 - 1 ;
if ( V_16 -> V_276 == 0 )
V_16 -> V_276 -- ;
return 0 ;
}
int
F_241 ( struct V_1 * V_2 , T_6 * V_271 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( V_16 -> V_275 == 0 ) {
int V_23 = F_234 ( V_2 , 0 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_275 = 1 ;
}
* V_271 = V_16 -> V_276 = V_16 -> V_275 ++ ;
return 0 ;
}
int F_242 ( struct V_150 * V_147 ,
struct V_31 * V_32 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_147 -> V_2 -> V_27 ;
struct V_145 * V_277 ;
struct V_278 * V_279 ;
T_6 V_280 ;
int V_23 ;
V_277 = V_147 -> V_148 ;
if ( F_16 ( V_277 == NULL ) )
return - V_55 ;
if ( V_116 . V_281 ) {
V_279 = V_277 -> V_282 -> V_283 [ V_147 -> V_151 ] . V_279 ;
} else
V_279 = V_147 -> V_284 ;
V_280 = F_243 ( V_279 ) ;
if ( V_116 . V_281 ) {
V_23 = F_244 ( V_279 , V_277 -> V_282 ) ;
if ( V_23 )
return V_23 ;
} else {
V_23 = F_245 ( V_147 ) ;
if ( V_23 )
return V_23 ;
}
V_277 -> V_285 = F_243 ( V_279 ) ;
if ( V_116 . V_281 ) {
V_23 = V_147 -> V_286 ( V_279 , V_277 ) ;
if ( V_23 )
return V_23 ;
} else {
V_23 = V_147 -> V_287 ( V_147 ) ;
if ( V_23 )
return V_23 ;
}
V_277 -> V_288 = V_280 ;
V_277 -> V_289 = F_243 ( V_279 ) ;
V_277 -> V_290 = V_7 ;
if ( ! V_116 . V_281 ) {
V_277 -> V_282 = V_147 -> V_291 ;
if ( V_277 -> V_282 )
F_246 ( V_277 -> V_282 ) ;
}
V_277 -> V_292 = V_163 ;
F_227 ( & V_277 -> V_240 , & V_147 -> V_293 ) ;
V_277 -> V_81 = NULL ;
if ( V_32 ) {
struct V_153 * V_81 = V_32 -> V_189 ;
F_7 ( & V_81 -> V_18 . V_294 ) ;
V_277 -> V_81 = V_81 ;
F_227 ( & V_277 -> V_295 ,
& V_81 -> V_18 . V_293 ) ;
F_8 ( & V_81 -> V_18 . V_294 ) ;
}
F_247 ( V_277 ) ;
V_147 -> V_148 = NULL ;
F_248 ( V_147 -> V_2 ) ;
F_249 ( & V_16 -> V_18 . V_168 ) ;
F_250 ( V_16 -> V_167 ,
& V_16 -> V_18 . V_296 ,
F_251 ( V_25 ) ) ;
F_252 ( V_16 -> V_2 ) ;
return 0 ;
}
static inline void
F_253 ( struct V_145 * V_277 )
{
struct V_153 * V_81 = V_277 -> V_81 ;
if ( ! V_81 )
return;
F_7 ( & V_81 -> V_18 . V_294 ) ;
F_209 ( & V_277 -> V_295 ) ;
V_277 -> V_81 = NULL ;
F_8 ( & V_81 -> V_18 . V_294 ) ;
}
static bool F_254 ( struct V_15 * V_16 ,
const struct V_297 * V_282 )
{
unsigned long V_298 ;
V_298 = F_255 () - V_282 -> V_299 . V_300 ;
if ( V_282 -> V_299 . V_301 )
return true ;
if ( V_282 -> V_299 . V_302 &&
V_298 <= V_282 -> V_299 . V_302 ) {
if ( ! F_256 ( V_282 ) ) {
F_198 ( L_6 ) ;
return true ;
} else if ( F_257 ( V_16 ) ) {
if ( F_258 ( V_16 ) )
F_13 ( L_7 ) ;
return true ;
}
}
return false ;
}
static void F_259 ( struct V_15 * V_16 ,
struct V_297 * V_282 ,
const bool V_303 )
{
struct V_304 * V_305 ;
if ( F_16 ( ! V_282 ) )
return;
V_305 = & V_282 -> V_299 ;
if ( V_303 ) {
V_305 -> V_301 = F_254 ( V_16 , V_282 ) ;
V_305 -> V_306 ++ ;
V_305 -> V_300 = F_255 () ;
} else {
V_305 -> V_307 ++ ;
}
}
static void F_260 ( struct V_145 * V_277 )
{
F_209 ( & V_277 -> V_240 ) ;
F_253 ( V_277 ) ;
F_165 ( V_277 ) ;
}
void F_261 ( struct V_308 * V_309 )
{
struct V_145 * V_146 = F_262 ( V_309 ,
F_213 ( * V_146 ) , V_310 ) ;
struct V_297 * V_282 = V_146 -> V_282 ;
if ( V_282 ) {
if ( V_116 . V_281 ) {
struct V_150 * V_147 = V_146 -> V_147 ;
if ( V_282 != V_147 -> V_311 )
F_263 ( V_147 , V_282 ) ;
}
F_264 ( V_282 ) ;
}
F_37 ( V_146 ) ;
}
struct V_145 *
F_265 ( struct V_150 * V_147 )
{
struct V_145 * V_277 ;
F_20 (request, &ring->request_list, list) {
if ( F_143 ( V_277 , false ) )
continue;
return V_277 ;
}
return NULL ;
}
static void F_266 ( struct V_15 * V_16 ,
struct V_150 * V_147 )
{
struct V_145 * V_277 ;
bool V_312 ;
V_277 = F_265 ( V_147 ) ;
if ( V_277 == NULL )
return;
V_312 = V_147 -> V_313 . V_314 >= V_315 ;
F_259 ( V_16 , V_277 -> V_282 , V_312 ) ;
F_267 (request, &ring->request_list, list)
F_259 ( V_16 , V_277 -> V_282 , false ) ;
}
static void F_268 ( struct V_15 * V_16 ,
struct V_150 * V_147 )
{
while ( ! F_211 ( & V_147 -> V_266 ) ) {
struct V_6 * V_7 ;
V_7 = F_212 ( & V_147 -> V_266 ,
struct V_6 ,
V_265 ) ;
F_231 ( V_7 ) ;
}
while ( ! F_211 ( & V_147 -> V_316 ) ) {
struct V_145 * V_317 ;
V_317 = F_212 ( & V_147 -> V_316 ,
struct V_145 ,
V_318 ) ;
F_209 ( & V_317 -> V_318 ) ;
F_123 ( V_16 ) ;
if ( V_317 -> V_282 != V_147 -> V_311 )
F_263 ( V_147 , V_317 -> V_282 ) ;
F_165 ( V_317 ) ;
}
while ( ! F_211 ( & V_147 -> V_293 ) ) {
struct V_145 * V_277 ;
V_277 = F_212 ( & V_147 -> V_293 ,
struct V_145 ,
V_240 ) ;
F_260 ( V_277 ) ;
}
F_167 ( & V_147 -> V_148 , NULL ) ;
}
void F_269 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_16 -> V_319 ; V_49 ++ ) {
struct V_320 * V_321 = & V_16 -> V_322 [ V_49 ] ;
if ( V_321 -> V_7 ) {
F_270 ( V_321 -> V_7 , V_321 ,
V_321 -> V_7 -> V_11 ) ;
} else {
F_271 ( V_2 , V_49 , NULL ) ;
}
}
}
void F_272 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_150 * V_147 ;
int V_49 ;
F_235 (ring, dev_priv, i)
F_266 ( V_16 , V_147 ) ;
F_235 (ring, dev_priv, i)
F_268 ( V_16 , V_147 ) ;
F_273 ( V_2 ) ;
F_269 ( V_2 ) ;
}
void
F_274 ( struct V_150 * V_147 )
{
if ( F_211 ( & V_147 -> V_293 ) )
return;
F_16 ( F_17 ( V_147 -> V_2 ) ) ;
while ( ! F_211 ( & V_147 -> V_293 ) ) {
struct V_145 * V_277 ;
struct V_278 * V_279 ;
V_277 = F_212 ( & V_147 -> V_293 ,
struct V_145 ,
V_240 ) ;
if ( ! F_143 ( V_277 , true ) )
break;
F_275 ( V_277 ) ;
if ( V_116 . V_281 ) {
struct V_297 * V_282 = V_277 -> V_282 ;
V_279 = V_282 -> V_283 [ V_147 -> V_151 ] . V_279 ;
} else
V_279 = V_147 -> V_284 ;
V_279 -> V_323 = V_277 -> V_285 ;
F_260 ( V_277 ) ;
}
while ( ! F_211 ( & V_147 -> V_266 ) ) {
struct V_6 * V_7 ;
V_7 = F_212 ( & V_147 -> V_266 ,
struct V_6 ,
V_265 ) ;
if ( ! F_143 ( V_7 -> V_186 , true ) )
break;
F_231 ( V_7 ) ;
}
if ( F_84 ( V_147 -> V_324 &&
F_143 ( V_147 -> V_324 , true ) ) ) {
V_147 -> V_181 ( V_147 ) ;
F_167 ( & V_147 -> V_324 , NULL ) ;
}
F_16 ( F_17 ( V_147 -> V_2 ) ) ;
}
bool
F_237 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_150 * V_147 ;
bool V_325 = true ;
int V_49 ;
F_235 (ring, dev_priv, i) {
F_274 ( V_147 ) ;
V_325 &= F_211 ( & V_147 -> V_293 ) ;
if ( V_116 . V_281 ) {
unsigned long V_195 ;
F_276 ( & V_147 -> V_326 , V_195 ) ;
V_325 &= F_211 ( & V_147 -> V_316 ) ;
F_277 ( & V_147 -> V_326 , V_195 ) ;
F_278 ( V_147 ) ;
}
}
if ( V_325 )
F_147 ( V_16 -> V_167 ,
& V_16 -> V_18 . V_168 ,
F_148 ( 100 ) ) ;
return V_325 ;
}
static void
F_279 ( struct V_327 * V_328 )
{
struct V_15 * V_16 =
F_262 ( V_328 , F_213 ( * V_16 ) , V_18 . V_296 . V_328 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_325 ;
V_325 = false ;
if ( F_280 ( & V_2 -> V_29 ) ) {
V_325 = F_237 ( V_2 ) ;
F_23 ( & V_2 -> V_29 ) ;
}
if ( ! V_325 )
F_250 ( V_16 -> V_167 , & V_16 -> V_18 . V_296 ,
F_251 ( V_25 ) ) ;
}
static void
F_281 ( struct V_327 * V_328 )
{
struct V_15 * V_16 =
F_262 ( V_328 , F_213 ( * V_16 ) , V_18 . V_168 . V_328 ) ;
F_282 ( V_16 -> V_2 ) ;
}
static int
F_283 ( struct V_6 * V_7 )
{
struct V_150 * V_147 ;
int V_23 ;
if ( V_7 -> V_183 ) {
V_147 = F_137 ( V_7 -> V_186 ) ;
V_23 = F_127 ( V_7 -> V_186 ) ;
if ( V_23 )
return V_23 ;
F_274 ( V_147 ) ;
}
return 0 ;
}
int
F_284 ( struct V_1 * V_2 , void * V_30 , struct V_31 * V_32 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_329 * args = V_30 ;
struct V_6 * V_7 ;
struct V_145 * V_146 ;
unsigned V_155 ;
int V_23 = 0 ;
if ( args -> V_195 != 0 )
return - V_50 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_102 ( F_103 ( V_2 , V_32 , args -> V_330 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_23 ( & V_2 -> V_29 ) ;
return - V_120 ;
}
V_23 = F_283 ( V_7 ) ;
if ( V_23 )
goto V_118;
if ( ! V_7 -> V_183 || ! V_7 -> V_186 )
goto V_118;
V_146 = V_7 -> V_186 ;
if ( args -> V_331 == 0 ) {
V_23 = - V_178 ;
goto V_118;
}
F_53 ( & V_7 -> V_8 ) ;
V_155 = F_152 ( & V_16 -> V_28 . V_155 ) ;
F_164 ( V_146 ) ;
F_23 ( & V_2 -> V_29 ) ;
V_23 = F_136 ( V_146 , V_155 , true ,
args -> V_331 > 0 ? & args -> V_331 : NULL ,
V_32 -> V_189 ) ;
F_19 ( & V_2 -> V_29 ) ;
F_165 ( V_146 ) ;
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
V_118:
F_53 ( & V_7 -> V_8 ) ;
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_285 ( struct V_6 * V_7 ,
struct V_150 * V_332 )
{
struct V_150 * V_333 ;
T_6 V_271 ;
int V_23 , V_334 ;
V_333 = F_137 ( V_7 -> V_186 ) ;
if ( V_333 == NULL || V_332 == V_333 )
return 0 ;
if ( V_332 == NULL || ! F_286 ( V_7 -> V_8 . V_2 ) )
return F_59 ( V_7 , false ) ;
V_334 = F_287 ( V_333 , V_332 ) ;
V_271 = F_288 ( V_7 -> V_186 ) ;
if ( V_271 <= V_333 -> V_273 . V_274 [ V_334 ] )
return 0 ;
V_23 = F_127 ( V_7 -> V_186 ) ;
if ( V_23 )
return V_23 ;
F_289 ( V_333 , V_332 , V_7 -> V_186 ) ;
V_23 = V_332 -> V_273 . V_335 ( V_332 , V_333 , V_271 ) ;
if ( ! V_23 )
V_333 -> V_273 . V_274 [ V_334 ] =
F_288 ( V_7 -> V_186 ) ;
return V_23 ;
}
static void F_290 ( struct V_6 * V_7 )
{
T_6 V_336 , V_337 ;
F_5 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_64 & V_191 ) == 0 )
return;
F_291 () ;
V_337 = V_7 -> V_8 . V_64 ;
V_336 = V_7 -> V_8 . V_65 ;
V_7 -> V_8 . V_64 &= ~ V_191 ;
V_7 -> V_8 . V_65 &= ~ V_191 ;
F_292 ( V_7 ,
V_337 ,
V_336 ) ;
}
int F_51 ( struct V_71 * V_72 )
{
struct V_6 * V_7 = V_72 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_211 ( & V_72 -> V_338 ) )
return 0 ;
if ( ! F_293 ( & V_72 -> V_339 ) ) {
F_294 ( V_72 ) ;
return 0 ;
}
if ( V_72 -> V_340 )
return - V_76 ;
F_41 ( V_7 -> V_60 == NULL ) ;
V_23 = F_295 ( V_7 ) ;
if ( V_23 )
return V_23 ;
if ( F_296 ( V_72 -> V_268 ) &&
V_72 -> V_341 . type == V_342 ) {
F_290 ( V_7 ) ;
V_23 = F_111 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
F_297 ( V_72 ) ;
V_72 -> V_343 ( V_72 ) ;
F_233 ( & V_72 -> V_267 ) ;
if ( F_296 ( V_72 -> V_268 ) ) {
if ( V_72 -> V_341 . type == V_342 ) {
V_7 -> V_344 = false ;
} else if ( V_72 -> V_341 . V_60 ) {
F_45 ( V_72 -> V_341 . V_60 ) ;
F_37 ( V_72 -> V_341 . V_60 ) ;
V_72 -> V_341 . V_60 = NULL ;
}
}
F_298 ( & V_72 -> V_339 ) ;
F_294 ( V_72 ) ;
if ( F_211 ( & V_7 -> V_345 ) ) {
F_81 ( V_7 ) ;
F_299 ( V_7 ) ;
F_214 ( & V_7 -> V_236 , & V_16 -> V_18 . V_243 ) ;
}
F_99 ( V_7 ) ;
return 0 ;
}
int F_300 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_150 * V_147 ;
int V_23 , V_49 ;
F_235 (ring, dev_priv, i) {
if ( ! V_116 . V_281 ) {
V_23 = F_301 ( V_147 , V_147 -> V_311 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_236 ( V_147 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static void F_302 ( struct V_1 * V_2 , int V_321 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_13 ;
int V_346 ;
if ( F_145 ( V_2 ) -> V_165 >= 6 ) {
V_13 = V_347 ;
V_346 = V_348 ;
} else {
V_13 = V_349 ;
V_346 = V_350 ;
}
V_13 += V_321 * 8 ;
F_303 ( V_13 , 0 ) ;
F_304 ( V_13 ) ;
if ( V_7 ) {
T_6 V_17 = F_22 ( V_7 ) ;
T_4 V_351 ;
if ( V_7 -> V_11 != V_140 ) {
T_5 V_352 = V_7 -> V_353 *
( V_7 -> V_11 == V_354 ? 32 : 8 ) ;
V_17 = ( V_17 / V_352 ) * V_352 ;
}
V_351 = ( T_4 ) ( ( F_112 ( V_7 ) + V_17 - 4096 ) &
0xfffff000 ) << 32 ;
V_351 |= F_112 ( V_7 ) & 0xfffff000 ;
V_351 |= ( T_4 ) ( ( V_7 -> V_353 / 128 ) - 1 ) << V_346 ;
if ( V_7 -> V_11 == V_354 )
V_351 |= 1 << V_355 ;
V_351 |= V_356 ;
F_303 ( V_13 + 4 , V_351 >> 32 ) ;
F_304 ( V_13 + 4 ) ;
F_303 ( V_13 + 0 , V_351 ) ;
F_304 ( V_13 ) ;
} else {
F_303 ( V_13 + 4 , 0 ) ;
F_304 ( V_13 + 4 ) ;
}
}
static void F_305 ( struct V_1 * V_2 , int V_321 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_351 ;
if ( V_7 ) {
T_6 V_17 = F_22 ( V_7 ) ;
int V_357 ;
int V_358 ;
F_141 ( ( F_112 ( V_7 ) & ~ V_359 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_112 ( V_7 ) & ( V_17 - 1 ) ) ,
L_8 ,
F_112 ( V_7 ) , V_7 -> V_344 , V_17 ) ;
if ( V_7 -> V_11 == V_354 && F_306 ( V_2 ) )
V_358 = 128 ;
else
V_358 = 512 ;
V_357 = V_7 -> V_353 / V_358 ;
V_357 = F_307 ( V_357 ) - 1 ;
V_351 = F_112 ( V_7 ) ;
if ( V_7 -> V_11 == V_354 )
V_351 |= 1 << V_360 ;
V_351 |= F_308 ( V_17 ) ;
V_351 |= V_357 << V_361 ;
V_351 |= V_362 ;
} else
V_351 = 0 ;
if ( V_321 < 8 )
V_321 = V_363 + V_321 * 4 ;
else
V_321 = V_364 + ( V_321 - 8 ) * 4 ;
F_303 ( V_321 , V_351 ) ;
F_304 ( V_321 ) ;
}
static void F_309 ( struct V_1 * V_2 , int V_321 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_5 V_351 ;
if ( V_7 ) {
T_6 V_17 = F_22 ( V_7 ) ;
T_5 V_357 ;
F_141 ( ( F_112 ( V_7 ) & ~ V_365 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_112 ( V_7 ) & ( V_17 - 1 ) ) ,
L_9 ,
F_112 ( V_7 ) , V_17 ) ;
V_357 = V_7 -> V_353 / 128 ;
V_357 = F_307 ( V_357 ) - 1 ;
V_351 = F_112 ( V_7 ) ;
if ( V_7 -> V_11 == V_354 )
V_351 |= 1 << V_360 ;
V_351 |= F_310 ( V_17 ) ;
V_351 |= V_357 << V_361 ;
V_351 |= V_362 ;
} else
V_351 = 0 ;
F_303 ( V_363 + V_321 * 4 , V_351 ) ;
F_304 ( V_363 + V_321 * 4 ) ;
}
inline static bool F_311 ( struct V_6 * V_7 )
{
return V_7 && V_7 -> V_8 . V_64 & V_191 ;
}
static void F_271 ( struct V_1 * V_2 , int V_321 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_311 ( V_16 -> V_322 [ V_321 ] . V_7 ) )
F_291 () ;
F_141 ( V_7 && ( ! V_7 -> V_353 || ! V_7 -> V_11 ) ,
L_10 ,
V_7 -> V_353 , V_7 -> V_11 ) ;
if ( F_312 ( V_2 ) )
F_309 ( V_2 , V_321 , V_7 ) ;
else if ( F_313 ( V_2 ) )
F_305 ( V_2 , V_321 , V_7 ) ;
else if ( F_145 ( V_2 ) -> V_165 >= 4 )
F_302 ( V_2 , V_321 , V_7 ) ;
if ( F_311 ( V_7 ) )
F_291 () ;
}
static inline int F_314 ( struct V_15 * V_16 ,
struct V_320 * V_366 )
{
return V_366 - V_16 -> V_322 ;
}
static void F_270 ( struct V_6 * V_7 ,
struct V_320 * V_366 ,
bool V_367 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_321 = F_314 ( V_16 , V_366 ) ;
F_271 ( V_7 -> V_8 . V_2 , V_321 , V_367 ? V_7 : NULL ) ;
if ( V_367 ) {
V_7 -> V_13 = V_321 ;
V_366 -> V_7 = V_7 ;
F_214 ( & V_366 -> V_368 , & V_16 -> V_18 . V_369 ) ;
} else {
V_7 -> V_13 = V_14 ;
V_366 -> V_7 = NULL ;
F_233 ( & V_366 -> V_368 ) ;
}
V_7 -> V_12 = false ;
}
static int
F_315 ( struct V_6 * V_7 )
{
if ( V_7 -> V_270 ) {
int V_23 = F_163 ( V_7 -> V_270 ) ;
if ( V_23 )
return V_23 ;
F_167 ( & V_7 -> V_270 , NULL ) ;
}
return 0 ;
}
int
F_111 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_320 * V_366 ;
int V_23 ;
V_23 = F_315 ( V_7 ) ;
if ( V_23 )
return V_23 ;
if ( V_7 -> V_13 == V_14 )
return 0 ;
V_366 = & V_16 -> V_322 [ V_7 -> V_13 ] ;
if ( F_16 ( V_366 -> V_340 ) )
return - V_76 ;
F_4 ( V_7 ) ;
F_270 ( V_7 , V_366 , false ) ;
return 0 ;
}
static struct V_320 *
F_316 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_320 * V_321 , * V_370 ;
int V_49 ;
V_370 = NULL ;
for ( V_49 = V_16 -> V_371 ; V_49 < V_16 -> V_319 ; V_49 ++ ) {
V_321 = & V_16 -> V_322 [ V_49 ] ;
if ( ! V_321 -> V_7 )
return V_321 ;
if ( ! V_321 -> V_340 )
V_370 = V_321 ;
}
if ( V_370 == NULL )
goto V_372;
F_20 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_321 -> V_340 )
continue;
return V_321 ;
}
V_372:
if ( F_317 ( V_2 ) )
return F_318 ( - V_144 ) ;
return F_318 ( - V_373 ) ;
}
int
F_181 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_367 = V_7 -> V_11 != V_140 ;
struct V_320 * V_321 ;
int V_23 ;
if ( V_7 -> V_12 ) {
V_23 = F_315 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_7 -> V_13 != V_14 ) {
V_321 = & V_16 -> V_322 [ V_7 -> V_13 ] ;
if ( ! V_7 -> V_12 ) {
F_214 ( & V_321 -> V_368 ,
& V_16 -> V_18 . V_369 ) ;
return 0 ;
}
} else if ( V_367 ) {
if ( F_16 ( ! V_7 -> V_344 ) )
return - V_50 ;
V_321 = F_316 ( V_2 ) ;
if ( F_28 ( V_321 ) )
return F_29 ( V_321 ) ;
if ( V_321 -> V_7 ) {
struct V_6 * V_374 = V_321 -> V_7 ;
V_23 = F_315 ( V_374 ) ;
if ( V_23 )
return V_23 ;
F_4 ( V_374 ) ;
}
} else
return 0 ;
F_270 ( V_7 , V_321 , V_367 ) ;
return 0 ;
}
static bool F_319 ( struct V_71 * V_72 ,
unsigned long V_9 )
{
struct V_375 * V_376 = & V_72 -> V_339 ;
struct V_375 * V_377 ;
if ( V_72 -> V_268 -> V_18 . V_378 == NULL )
return true ;
if ( ! F_293 ( V_376 ) )
return true ;
if ( F_211 ( & V_376 -> V_379 ) )
return true ;
V_377 = F_320 ( V_376 -> V_379 . V_380 , struct V_375 , V_379 ) ;
if ( V_377 -> V_381 && ! V_377 -> V_382 && V_377 -> V_383 != V_9 )
return false ;
V_377 = F_320 ( V_376 -> V_379 . V_73 , struct V_375 , V_379 ) ;
if ( V_377 -> V_381 && ! V_376 -> V_382 && V_377 -> V_383 != V_9 )
return false ;
return true ;
}
static struct V_71 *
F_321 ( struct V_6 * V_7 ,
struct V_384 * V_268 ,
unsigned V_385 ,
T_4 V_195 ,
const struct V_386 * V_387 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_17 , V_388 , V_389 , V_390 ;
unsigned long V_107 =
V_195 & V_391 ? V_195 & V_392 : 0 ;
unsigned long V_108 =
V_195 & V_127 ? V_16 -> V_36 . V_231 : V_268 -> V_37 ;
struct V_71 * V_72 ;
int V_23 ;
V_388 = F_187 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ) ;
V_389 = F_188 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , true ) ;
V_390 =
F_188 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , false ) ;
if ( V_385 == 0 )
V_385 = V_195 & V_127 ? V_389 :
V_390 ;
if ( V_195 & V_127 && V_385 & ( V_389 - 1 ) ) {
F_198 ( L_11 , V_385 ) ;
return F_318 ( - V_50 ) ;
}
V_17 = V_195 & V_127 ? V_388 : V_7 -> V_8 . V_17 ;
if ( V_7 -> V_8 . V_17 > V_108 ) {
F_198 ( L_12 ,
V_7 -> V_8 . V_17 ,
V_195 & V_127 ? L_13 : L_14 ,
V_108 ) ;
return F_318 ( - V_232 ) ;
}
V_23 = F_56 ( V_7 ) ;
if ( V_23 )
return F_318 ( V_23 ) ;
F_82 ( V_7 ) ;
V_72 = F_322 ( V_7 , V_268 , V_387 ) ;
if ( F_28 ( V_72 ) )
goto V_393;
V_394:
V_23 = F_323 ( & V_268 -> V_18 , & V_72 -> V_339 ,
V_17 , V_385 ,
V_7 -> V_9 ,
V_107 , V_108 ,
V_395 ,
V_396 ) ;
if ( V_23 ) {
V_23 = F_324 ( V_2 , V_268 , V_17 , V_385 ,
V_7 -> V_9 ,
V_107 , V_108 ,
V_195 ) ;
if ( V_23 == 0 )
goto V_394;
goto V_397;
}
if ( F_16 ( ! F_319 ( V_72 , V_7 -> V_9 ) ) ) {
V_23 = - V_50 ;
goto V_398;
}
V_23 = F_325 ( V_7 ) ;
if ( V_23 )
goto V_398;
F_326 ( V_72 , V_195 ) ;
V_23 = F_327 ( V_72 , V_7 -> V_9 ,
V_195 & V_399 ? V_400 : 0 ) ;
if ( V_23 )
goto V_401;
F_214 ( & V_7 -> V_236 , & V_16 -> V_18 . V_244 ) ;
F_227 ( & V_72 -> V_267 , & V_268 -> V_269 ) ;
return V_72 ;
V_401:
F_299 ( V_7 ) ;
V_398:
F_298 ( & V_72 -> V_339 ) ;
V_397:
F_294 ( V_72 ) ;
V_72 = F_318 ( V_23 ) ;
V_393:
F_99 ( V_7 ) ;
return V_72 ;
}
bool
F_118 ( struct V_6 * V_7 ,
bool V_402 )
{
if ( V_7 -> V_60 == NULL )
return false ;
if ( V_7 -> V_403 || V_7 -> V_44 )
return false ;
if ( ! V_402 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) ) {
V_7 -> V_404 = true ;
return false ;
}
F_328 ( V_7 ) ;
F_329 ( V_7 -> V_60 ) ;
V_7 -> V_404 = false ;
return true ;
}
static void
F_330 ( struct V_6 * V_7 )
{
T_5 V_336 ;
if ( V_7 -> V_8 . V_65 != V_191 )
return;
F_331 () ;
V_336 = V_7 -> V_8 . V_65 ;
V_7 -> V_8 . V_65 = 0 ;
F_232 ( V_7 , false ) ;
F_292 ( V_7 ,
V_7 -> V_8 . V_64 ,
V_336 ) ;
}
static void
F_171 ( struct V_6 * V_7 )
{
T_5 V_336 ;
if ( V_7 -> V_8 . V_65 != V_66 )
return;
if ( F_118 ( V_7 , V_7 -> V_10 ) )
F_34 ( V_7 -> V_8 . V_2 ) ;
V_336 = V_7 -> V_8 . V_65 ;
V_7 -> V_8 . V_65 = 0 ;
F_232 ( V_7 , false ) ;
F_292 ( V_7 ,
V_7 -> V_8 . V_64 ,
V_336 ) ;
}
int
F_110 ( struct V_6 * V_7 , bool V_211 )
{
T_5 V_336 , V_337 ;
struct V_71 * V_72 ;
int V_23 ;
if ( V_7 -> V_8 . V_65 == V_191 )
return 0 ;
V_23 = F_59 ( V_7 , ! V_211 ) ;
if ( V_23 )
return V_23 ;
F_81 ( V_7 ) ;
V_23 = F_56 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_171 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_64 & V_191 ) == 0 )
F_291 () ;
V_336 = V_7 -> V_8 . V_65 ;
V_337 = V_7 -> V_8 . V_64 ;
F_41 ( ( V_7 -> V_8 . V_65 & ~ V_191 ) != 0 ) ;
V_7 -> V_8 . V_64 |= V_191 ;
if ( V_211 ) {
V_7 -> V_8 . V_64 = V_191 ;
V_7 -> V_8 . V_65 = V_191 ;
V_7 -> V_68 = 1 ;
}
if ( V_211 )
F_332 ( V_7 , NULL ) ;
F_292 ( V_7 ,
V_337 ,
V_336 ) ;
V_72 = F_333 ( V_7 ) ;
if ( V_72 && F_293 ( & V_72 -> V_339 ) && ! V_7 -> V_183 )
F_214 ( & V_72 -> V_267 ,
& F_334 ( V_7 -> V_8 . V_2 ) -> V_36 . V_8 . V_269 ) ;
return 0 ;
}
int F_335 ( struct V_6 * V_7 ,
enum V_3 V_9 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_71 * V_72 , * V_73 ;
int V_23 ;
if ( V_7 -> V_9 == V_9 )
return 0 ;
if ( F_21 ( V_7 ) ) {
F_198 ( L_15 ) ;
return - V_76 ;
}
F_50 (vma, next, &obj->vma_list, vma_link) {
if ( ! F_319 ( V_72 , V_9 ) ) {
V_23 = F_51 ( V_72 ) ;
if ( V_23 )
return V_23 ;
}
}
if ( F_208 ( V_7 ) ) {
V_23 = F_295 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_290 ( V_7 ) ;
if ( F_145 ( V_2 ) -> V_165 < 6 ) {
V_23 = F_111 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
F_20 (vma, &obj->vma_list, vma_link)
if ( F_293 ( & V_72 -> V_339 ) ) {
V_23 = F_327 ( V_72 , V_9 ,
V_72 -> V_405 & V_400 ) ;
if ( V_23 )
return V_23 ;
}
}
F_20 (vma, &obj->vma_list, vma_link)
V_72 -> V_339 . V_383 = V_9 ;
V_7 -> V_9 = V_9 ;
if ( V_7 -> V_404 &&
V_7 -> V_8 . V_65 != V_66 &&
F_3 ( V_7 ) ) {
if ( F_118 ( V_7 , true ) )
F_34 ( V_7 -> V_8 . V_2 ) ;
}
return 0 ;
}
int F_336 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_406 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_102 ( F_103 ( V_2 , V_32 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
switch ( V_7 -> V_9 ) {
case V_407 :
case V_408 :
args -> V_409 = V_410 ;
break;
case V_411 :
args -> V_409 = V_412 ;
break;
default:
args -> V_409 = V_413 ;
break;
}
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_337 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_406 * args = V_30 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_23 ;
switch ( args -> V_409 ) {
case V_413 :
V_4 = V_5 ;
break;
case V_410 :
V_4 = V_407 ;
break;
case V_412 :
V_4 = F_338 ( V_2 ) ? V_411 : V_5 ;
break;
default:
return - V_50 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_102 ( F_103 ( V_2 , V_32 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
V_23 = F_335 ( V_7 , V_4 ) ;
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static bool F_339 ( struct V_6 * V_7 )
{
struct V_71 * V_72 ;
V_72 = F_333 ( V_7 ) ;
if ( ! V_72 )
return false ;
return V_72 -> V_340 ;
}
int
F_340 ( struct V_6 * V_7 ,
T_6 V_385 ,
struct V_150 * V_414 )
{
T_6 V_337 , V_336 ;
bool V_415 ;
int V_23 ;
if ( V_414 != F_137 ( V_7 -> V_186 ) ) {
V_23 = F_285 ( V_7 , V_414 ) ;
if ( V_23 )
return V_23 ;
}
V_415 = V_7 -> V_10 ;
V_7 -> V_10 = true ;
V_23 = F_335 ( V_7 ,
F_338 ( V_7 -> V_8 . V_2 ) ? V_411 : V_5 ) ;
if ( V_23 )
goto V_416;
V_23 = F_109 ( V_7 , V_385 , V_127 ) ;
if ( V_23 )
goto V_416;
F_171 ( V_7 ) ;
V_336 = V_7 -> V_8 . V_65 ;
V_337 = V_7 -> V_8 . V_64 ;
V_7 -> V_8 . V_65 = 0 ;
V_7 -> V_8 . V_64 |= V_191 ;
F_292 ( V_7 ,
V_337 ,
V_336 ) ;
return 0 ;
V_416:
F_16 ( V_415 != F_339 ( V_7 ) ) ;
V_7 -> V_10 = V_415 ;
return V_23 ;
}
void
F_341 ( struct V_6 * V_7 )
{
F_113 ( V_7 ) ;
V_7 -> V_10 = F_339 ( V_7 ) ;
}
int
F_295 ( struct V_6 * V_7 )
{
int V_23 ;
if ( ( V_7 -> V_8 . V_64 & V_188 ) == 0 )
return 0 ;
V_23 = F_59 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_8 . V_64 &= ~ V_188 ;
return 0 ;
}
int
F_42 ( struct V_6 * V_7 , bool V_211 )
{
T_5 V_336 , V_337 ;
int V_23 ;
if ( V_7 -> V_8 . V_65 == V_66 )
return 0 ;
V_23 = F_59 ( V_7 , ! V_211 ) ;
if ( V_23 )
return V_23 ;
F_81 ( V_7 ) ;
F_330 ( V_7 ) ;
V_336 = V_7 -> V_8 . V_65 ;
V_337 = V_7 -> V_8 . V_64 ;
if ( ( V_7 -> V_8 . V_64 & V_66 ) == 0 ) {
F_118 ( V_7 , false ) ;
V_7 -> V_8 . V_64 |= V_66 ;
}
F_41 ( ( V_7 -> V_8 . V_65 & ~ V_66 ) != 0 ) ;
if ( V_211 ) {
V_7 -> V_8 . V_64 = V_66 ;
V_7 -> V_8 . V_65 = V_66 ;
}
if ( V_211 )
F_332 ( V_7 , NULL ) ;
F_292 ( V_7 ,
V_337 ,
V_336 ) ;
return 0 ;
}
static int
F_342 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_153 * V_81 = V_32 -> V_189 ;
unsigned long V_417 = V_163 - F_148 ( 20 ) ;
struct V_145 * V_277 , * V_238 = NULL ;
unsigned V_155 ;
int V_23 ;
V_23 = F_10 ( & V_16 -> V_28 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_124 ( & V_16 -> V_28 , false ) ;
if ( V_23 )
return V_23 ;
F_7 ( & V_81 -> V_18 . V_294 ) ;
F_20 (request, &file_priv->mm.request_list, client_list) {
if ( F_154 ( V_277 -> V_292 , V_417 ) )
break;
V_238 = V_277 ;
}
V_155 = F_152 ( & V_16 -> V_28 . V_155 ) ;
if ( V_238 )
F_164 ( V_238 ) ;
F_8 ( & V_81 -> V_18 . V_294 ) ;
if ( V_238 == NULL )
return 0 ;
V_23 = F_136 ( V_238 , V_155 , true , NULL , NULL ) ;
if ( V_23 == 0 )
F_250 ( V_16 -> V_167 , & V_16 -> V_18 . V_296 , 0 ) ;
F_19 ( & V_2 -> V_29 ) ;
F_165 ( V_238 ) ;
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static bool
F_343 ( struct V_71 * V_72 , T_5 V_385 , T_4 V_195 )
{
struct V_6 * V_7 = V_72 -> V_7 ;
if ( V_385 &&
V_72 -> V_339 . V_107 & ( V_385 - 1 ) )
return true ;
if ( V_195 & V_127 && ! V_7 -> V_344 )
return true ;
if ( V_195 & V_391 &&
V_72 -> V_339 . V_107 < ( V_195 & V_392 ) )
return true ;
return false ;
}
int
F_344 ( struct V_6 * V_7 ,
struct V_384 * V_268 ,
T_5 V_385 ,
T_4 V_195 ,
const struct V_386 * V_387 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_71 * V_72 ;
unsigned V_405 ;
int V_23 ;
if ( F_16 ( V_268 == & V_16 -> V_18 . V_418 -> V_8 ) )
return - V_170 ;
if ( F_16 ( V_195 & ( V_399 | V_127 ) && ! F_296 ( V_268 ) ) )
return - V_50 ;
if ( F_16 ( ( V_195 & ( V_127 | V_399 ) ) == V_127 ) )
return - V_50 ;
V_72 = F_345 ( V_7 , V_268 , V_387 ) ;
if ( V_72 ) {
if ( F_16 ( V_72 -> V_340 == V_419 ) )
return - V_76 ;
if ( F_343 ( V_72 , V_385 , V_195 ) ) {
F_141 ( V_72 -> V_340 ,
L_16
L_17
L_18 ,
F_346 ( V_7 , V_268 , V_387 -> type ) ,
V_385 ,
! ! ( V_195 & V_127 ) ,
V_7 -> V_344 ) ;
V_23 = F_51 ( V_72 ) ;
if ( V_23 )
return V_23 ;
V_72 = NULL ;
}
}
V_405 = V_72 ? V_72 -> V_405 : 0 ;
if ( V_72 == NULL || ! F_293 ( & V_72 -> V_339 ) ) {
V_72 = F_321 ( V_7 , V_268 , V_385 ,
V_195 , V_387 ) ;
if ( F_28 ( V_72 ) )
return F_29 ( V_72 ) ;
}
if ( V_195 & V_399 && ! ( V_72 -> V_405 & V_400 ) ) {
V_23 = F_327 ( V_72 , V_7 -> V_9 , V_400 ) ;
if ( V_23 )
return V_23 ;
}
if ( ( V_405 ^ V_72 -> V_405 ) & V_400 ) {
bool V_131 , V_420 ;
T_6 V_388 , V_389 ;
V_388 = F_187 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ) ;
V_389 = F_188 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ,
true ) ;
V_420 = ( V_72 -> V_339 . V_17 == V_388 &&
( V_72 -> V_339 . V_107 & ( V_389 - 1 ) ) == 0 ) ;
V_131 = ( V_72 -> V_339 . V_107 + V_7 -> V_8 . V_17 <=
V_16 -> V_36 . V_231 ) ;
V_7 -> V_344 = V_131 && V_420 ;
}
F_16 ( V_195 & V_127 && ! V_7 -> V_344 ) ;
V_72 -> V_340 ++ ;
if ( V_195 & V_127 )
V_7 -> V_421 |= true ;
return 0 ;
}
void
F_113 ( struct V_6 * V_7 )
{
struct V_71 * V_72 = F_333 ( V_7 ) ;
F_41 ( ! V_72 ) ;
F_41 ( V_72 -> V_340 == 0 ) ;
F_41 ( ! F_347 ( V_7 ) ) ;
if ( -- V_72 -> V_340 == 0 )
V_7 -> V_421 = false ;
}
bool
F_348 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 != V_14 ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_71 * V_422 = F_333 ( V_7 ) ;
F_16 ( ! V_422 ||
V_16 -> V_322 [ V_7 -> V_13 ] . V_340 >
V_422 -> V_340 ) ;
V_16 -> V_322 [ V_7 -> V_13 ] . V_340 ++ ;
return true ;
} else
return false ;
}
void
F_349 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 != V_14 ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
F_16 ( V_16 -> V_322 [ V_7 -> V_13 ] . V_340 <= 0 ) ;
V_16 -> V_322 [ V_7 -> V_13 ] . V_340 -- ;
}
}
int
F_350 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_423 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_102 ( F_103 ( V_2 , V_32 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
V_23 = F_283 ( V_7 ) ;
args -> V_424 = V_7 -> V_183 ;
if ( V_7 -> V_186 ) {
struct V_150 * V_147 ;
F_351 ( V_425 > 16 ) ;
V_147 = F_137 ( V_7 -> V_186 ) ;
args -> V_424 |= F_139 ( V_147 ) << 16 ;
}
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_352 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_81 )
{
return F_342 ( V_2 , V_81 ) ;
}
int
F_353 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_81 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_426 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 ;
switch ( args -> V_62 ) {
case V_67 :
case V_70 :
break;
default:
return - V_50 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_102 ( F_103 ( V_2 , V_81 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_120 ;
goto V_121;
}
if ( F_21 ( V_7 ) ) {
V_23 = - V_50 ;
goto V_118;
}
if ( V_7 -> V_60 &&
V_7 -> V_11 != V_140 &&
V_16 -> V_261 & V_262 ) {
if ( V_7 -> V_62 == V_70 )
F_99 ( V_7 ) ;
if ( args -> V_62 == V_70 )
F_82 ( V_7 ) ;
}
if ( V_7 -> V_62 != V_63 )
V_7 -> V_62 = args -> V_62 ;
if ( F_201 ( V_7 ) && V_7 -> V_60 == NULL )
F_202 ( V_7 ) ;
args -> V_427 = V_7 -> V_62 != V_63 ;
V_118:
F_53 ( & V_7 -> V_8 ) ;
V_121:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void F_354 ( struct V_6 * V_7 ,
const struct V_234 * V_78 )
{
F_210 ( & V_7 -> V_236 ) ;
F_210 ( & V_7 -> V_265 ) ;
F_210 ( & V_7 -> V_428 ) ;
F_210 ( & V_7 -> V_345 ) ;
F_210 ( & V_7 -> V_429 ) ;
V_7 -> V_78 = V_78 ;
V_7 -> V_13 = V_14 ;
V_7 -> V_62 = V_70 ;
F_6 ( V_7 -> V_8 . V_2 -> V_27 , V_7 -> V_8 . V_17 ) ;
}
struct V_6 * F_68 ( struct V_1 * V_2 ,
T_1 V_17 )
{
struct V_6 * V_7 ;
struct V_39 * V_40 ;
T_13 V_430 ;
V_7 = F_62 ( V_2 ) ;
if ( V_7 == NULL )
return NULL ;
if ( F_355 ( V_2 , & V_7 -> V_8 , V_17 ) != 0 ) {
F_64 ( V_7 ) ;
return NULL ;
}
V_430 = V_431 | V_432 ;
if ( F_356 ( V_2 ) || F_357 ( V_2 ) ) {
V_430 &= ~ V_433 ;
V_430 |= V_260 ;
}
V_40 = F_25 ( V_7 -> V_8 . V_41 ) -> V_42 ;
F_358 ( V_40 , V_430 ) ;
F_354 ( V_7 , & V_434 ) ;
V_7 -> V_8 . V_65 = V_66 ;
V_7 -> V_8 . V_64 = V_66 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_9 = V_407 ;
} else
V_7 -> V_9 = V_5 ;
F_359 ( V_7 ) ;
return V_7 ;
}
static bool F_360 ( struct V_6 * V_7 )
{
if ( V_7 -> V_62 != V_70 )
return false ;
if ( V_7 -> V_8 . V_41 == NULL )
return true ;
return F_361 ( & V_7 -> V_8 . V_41 -> V_435 ) == 1 ;
}
void F_362 ( struct V_194 * V_436 )
{
struct V_6 * V_7 = F_102 ( V_436 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_71 * V_72 , * V_73 ;
F_121 ( V_16 ) ;
F_363 ( V_7 ) ;
F_50 (vma, next, &obj->vma_list, vma_link) {
int V_23 ;
V_72 -> V_340 = 0 ;
V_23 = F_51 ( V_72 ) ;
if ( F_16 ( V_23 == - V_177 ) ) {
bool V_437 ;
V_437 = V_16 -> V_18 . V_142 ;
V_16 -> V_18 . V_142 = false ;
F_16 ( F_51 ( V_72 ) ) ;
V_16 -> V_18 . V_142 = V_437 ;
}
}
if ( V_7 -> V_403 )
F_99 ( V_7 ) ;
F_16 ( V_7 -> V_438 ) ;
if ( V_7 -> V_60 && V_7 -> V_62 == V_70 &&
V_16 -> V_261 & V_262 &&
V_7 -> V_11 != V_140 )
F_99 ( V_7 ) ;
if ( F_16 ( V_7 -> V_235 ) )
V_7 -> V_235 = 0 ;
if ( F_360 ( V_7 ) )
V_7 -> V_62 = V_67 ;
F_52 ( V_7 ) ;
F_195 ( V_7 ) ;
F_41 ( V_7 -> V_60 ) ;
if ( V_7 -> V_8 . V_439 )
F_364 ( & V_7 -> V_8 , NULL ) ;
if ( V_7 -> V_78 -> V_440 )
V_7 -> V_78 -> V_440 ( V_7 ) ;
F_365 ( & V_7 -> V_8 ) ;
F_9 ( V_16 , V_7 -> V_8 . V_17 ) ;
F_37 ( V_7 -> V_441 ) ;
F_64 ( V_7 ) ;
F_123 ( V_16 ) ;
}
struct V_71 * F_345 ( struct V_6 * V_7 ,
struct V_384 * V_268 ,
const struct V_386 * V_387 )
{
struct V_71 * V_72 ;
F_20 (vma, &obj->vma_list, vma_link)
if ( V_72 -> V_268 == V_268 && V_72 -> V_341 . type == V_387 -> type )
return V_72 ;
return NULL ;
}
void F_294 ( struct V_71 * V_72 )
{
struct V_384 * V_268 = NULL ;
F_16 ( V_72 -> V_339 . V_381 ) ;
if ( ! F_211 ( & V_72 -> V_442 ) )
return;
V_268 = V_72 -> V_268 ;
if ( ! F_296 ( V_268 ) )
F_366 ( F_367 ( V_268 ) ) ;
F_209 ( & V_72 -> V_338 ) ;
F_37 ( V_72 ) ;
}
static void
F_368 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_150 * V_147 ;
int V_49 ;
F_235 (ring, dev_priv, i)
V_16 -> V_443 . V_444 ( V_147 ) ;
}
int
F_369 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 = 0 ;
F_19 ( & V_2 -> V_29 ) ;
V_23 = F_300 ( V_2 ) ;
if ( V_23 )
goto V_445;
F_237 ( V_2 ) ;
if ( ! F_370 ( V_2 , V_446 ) )
F_216 ( V_2 ) ;
F_368 ( V_2 ) ;
F_23 ( & V_2 -> V_29 ) ;
F_249 ( & V_16 -> V_28 . V_447 ) ;
F_249 ( & V_16 -> V_18 . V_296 ) ;
F_371 ( & V_16 -> V_18 . V_168 ) ;
F_16 ( V_16 -> V_18 . V_424 ) ;
return 0 ;
V_445:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_372 ( struct V_150 * V_147 , int V_448 )
{
struct V_1 * V_2 = V_147 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_449 = V_450 + ( V_448 * 0x200 ) ;
T_6 * V_451 = V_16 -> V_452 . V_451 [ V_448 ] ;
int V_49 , V_23 ;
if ( ! F_373 ( V_2 ) || ! V_451 )
return 0 ;
V_23 = F_374 ( V_147 , V_453 / 4 * 3 ) ;
if ( V_23 )
return V_23 ;
for ( V_49 = 0 ; V_49 < V_453 ; V_49 += 4 ) {
F_375 ( V_147 , F_376 ( 1 ) ) ;
F_375 ( V_147 , V_449 + V_49 ) ;
F_375 ( V_147 , V_451 [ V_49 / 4 ] ) ;
}
F_377 ( V_147 ) ;
return V_23 ;
}
void F_378 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_145 ( V_2 ) -> V_165 < 5 ||
V_16 -> V_18 . V_454 == V_455 )
return;
F_303 ( V_456 , F_379 ( V_456 ) |
V_457 ) ;
if ( F_380 ( V_2 ) )
return;
F_303 ( V_458 , F_379 ( V_458 ) | V_459 ) ;
if ( F_381 ( V_2 ) )
F_303 ( V_460 , F_382 ( V_461 ) ) ;
else if ( F_383 ( V_2 ) )
F_303 ( V_460 , F_382 ( V_462 ) ) ;
else if ( F_384 ( V_2 ) )
F_303 ( V_463 , F_382 ( V_464 ) ) ;
else
F_385 () ;
}
static bool
F_386 ( struct V_1 * V_2 )
{
if ( ! F_387 ( V_2 ) )
return false ;
if ( F_381 ( V_2 ) && V_2 -> V_465 -> V_466 < 8 ) {
F_388 ( L_19
L_20 ) ;
return false ;
}
return true ;
}
static void F_389 ( struct V_1 * V_2 , T_6 V_8 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
F_303 ( F_390 ( V_8 ) , 0 ) ;
F_303 ( F_391 ( V_8 ) , 0 ) ;
F_303 ( F_392 ( V_8 ) , 0 ) ;
F_303 ( F_393 ( V_8 ) , 0 ) ;
}
static void F_394 ( struct V_1 * V_2 )
{
if ( F_395 ( V_2 ) ) {
F_389 ( V_2 , V_467 ) ;
F_389 ( V_2 , V_468 ) ;
F_389 ( V_2 , V_469 ) ;
F_389 ( V_2 , V_470 ) ;
F_389 ( V_2 , V_471 ) ;
} else if ( F_312 ( V_2 ) ) {
F_389 ( V_2 , V_468 ) ;
F_389 ( V_2 , V_469 ) ;
} else if ( F_313 ( V_2 ) ) {
F_389 ( V_2 , V_467 ) ;
F_389 ( V_2 , V_472 ) ;
}
}
int F_396 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
V_23 = F_397 ( V_2 ) ;
if ( V_23 )
return V_23 ;
if ( F_398 ( V_2 ) ) {
V_23 = F_399 ( V_2 ) ;
if ( V_23 )
goto V_473;
}
if ( F_386 ( V_2 ) ) {
V_23 = F_400 ( V_2 ) ;
if ( V_23 )
goto V_474;
}
if ( F_401 ( V_2 ) ) {
V_23 = F_402 ( V_2 ) ;
if ( V_23 )
goto V_475;
}
if ( F_403 ( V_2 ) ) {
V_23 = F_404 ( V_2 ) ;
if ( V_23 )
goto V_476;
}
V_23 = F_240 ( V_2 , ( ( T_6 ) ~ 0 - 0x1000 ) ) ;
if ( V_23 )
goto V_477;
return 0 ;
V_477:
F_405 ( & V_16 -> V_147 [ V_478 ] ) ;
V_476:
F_405 ( & V_16 -> V_147 [ V_479 ] ) ;
V_475:
F_405 ( & V_16 -> V_147 [ V_480 ] ) ;
V_474:
F_405 ( & V_16 -> V_147 [ V_481 ] ) ;
V_473:
F_405 ( & V_16 -> V_147 [ V_166 ] ) ;
return V_23 ;
}
int
F_406 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_150 * V_147 ;
int V_23 , V_49 ;
if ( F_145 ( V_2 ) -> V_165 < 6 && ! F_407 () )
return - V_26 ;
F_408 ( V_16 , V_482 ) ;
if ( V_16 -> V_483 )
F_303 ( V_484 , F_379 ( V_484 ) | F_409 ( 0xf ) ) ;
if ( F_410 ( V_2 ) )
F_303 ( V_485 , F_411 ( V_2 ) ?
V_486 : V_487 ) ;
if ( F_412 ( V_2 ) ) {
if ( F_413 ( V_2 ) ) {
T_6 V_488 = F_379 ( V_489 ) ;
V_488 &= ~ ( V_490 | V_491 ) ;
F_303 ( V_489 , V_488 ) ;
} else if ( F_145 ( V_2 ) -> V_165 >= 7 ) {
T_6 V_488 = F_379 ( V_492 ) ;
V_488 &= ~ V_493 ;
F_303 ( V_492 , V_488 ) ;
}
}
F_378 ( V_2 ) ;
F_394 ( V_2 ) ;
F_235 (ring, dev_priv, i) {
V_23 = V_147 -> V_494 ( V_147 ) ;
if ( V_23 )
goto V_118;
}
for ( V_49 = 0 ; V_49 < F_414 ( V_2 ) ; V_49 ++ )
F_372 ( & V_16 -> V_147 [ V_166 ] , V_49 ) ;
V_23 = F_415 ( V_2 ) ;
if ( V_23 && V_23 != - V_26 ) {
F_13 ( L_21 , V_23 ) ;
F_416 ( V_2 ) ;
}
V_23 = F_417 ( V_16 ) ;
if ( V_23 && V_23 != - V_26 ) {
F_13 ( L_22 , V_23 ) ;
F_416 ( V_2 ) ;
goto V_118;
}
V_118:
F_418 ( V_16 , V_482 ) ;
return V_23 ;
}
int F_419 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
V_116 . V_281 = F_420 ( V_2 ,
V_116 . V_281 ) ;
F_19 ( & V_2 -> V_29 ) ;
if ( F_421 ( V_2 ) ) {
F_303 ( V_495 , V_496 ) ;
if ( F_422 ( ( F_379 ( V_497 ) &
V_498 ) , 10 ) )
F_423 ( L_23 ) ;
}
if ( ! V_116 . V_281 ) {
V_16 -> V_443 . V_499 = V_500 ;
V_16 -> V_443 . V_501 = F_396 ;
V_16 -> V_443 . V_502 = F_405 ;
V_16 -> V_443 . V_444 = V_503 ;
} else {
V_16 -> V_443 . V_499 = V_504 ;
V_16 -> V_443 . V_501 = V_505 ;
V_16 -> V_443 . V_502 = V_506 ;
V_16 -> V_443 . V_444 = V_507 ;
}
F_408 ( V_16 , V_482 ) ;
V_23 = F_424 ( V_2 ) ;
if ( V_23 )
goto V_508;
F_425 ( V_2 ) ;
V_23 = F_426 ( V_2 ) ;
if ( V_23 )
goto V_508;
V_23 = V_16 -> V_443 . V_501 ( V_2 ) ;
if ( V_23 )
goto V_508;
V_23 = F_406 ( V_2 ) ;
if ( V_23 == - V_26 ) {
F_13 ( L_24 ) ;
F_427 ( V_509 , & V_16 -> V_28 . V_155 ) ;
V_23 = 0 ;
}
V_508:
F_418 ( V_16 , V_482 ) ;
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void
F_416 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_150 * V_147 ;
int V_49 ;
F_235 (ring, dev_priv, i)
V_16 -> V_443 . V_502 ( V_147 ) ;
}
static void
F_428 ( struct V_150 * V_147 )
{
F_210 ( & V_147 -> V_266 ) ;
F_210 ( & V_147 -> V_293 ) ;
}
void F_429 ( struct V_15 * V_16 ,
struct V_384 * V_268 )
{
if ( ! F_296 ( V_268 ) )
F_430 ( & V_268 -> V_18 , V_268 -> V_107 , V_268 -> V_37 ) ;
V_268 -> V_2 = V_16 -> V_2 ;
F_210 ( & V_268 -> V_266 ) ;
F_210 ( & V_268 -> V_269 ) ;
F_210 ( & V_268 -> V_510 ) ;
F_227 ( & V_268 -> V_510 , & V_16 -> V_511 ) ;
}
void
F_431 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_49 ;
V_16 -> V_85 =
F_432 ( L_25 ,
sizeof( struct V_6 ) , 0 ,
V_512 ,
NULL ) ;
F_210 ( & V_16 -> V_511 ) ;
F_429 ( V_16 , & V_16 -> V_36 . V_8 ) ;
F_210 ( & V_16 -> V_513 ) ;
F_210 ( & V_16 -> V_18 . V_243 ) ;
F_210 ( & V_16 -> V_18 . V_244 ) ;
F_210 ( & V_16 -> V_18 . V_369 ) ;
for ( V_49 = 0 ; V_49 < V_425 ; V_49 ++ )
F_428 ( & V_16 -> V_147 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_514 ; V_49 ++ )
F_210 ( & V_16 -> V_322 [ V_49 ] . V_368 ) ;
F_433 ( & V_16 -> V_18 . V_296 ,
F_279 ) ;
F_433 ( & V_16 -> V_18 . V_168 ,
F_281 ) ;
F_434 ( & V_16 -> V_28 . V_24 ) ;
if ( ! F_370 ( V_2 , V_446 ) && F_313 ( V_2 ) ) {
F_303 ( V_515 ,
F_382 ( V_516 ) ) ;
}
V_16 -> V_517 = V_518 ;
if ( ! F_370 ( V_2 , V_446 ) )
V_16 -> V_371 = 3 ;
if ( F_145 ( V_2 ) -> V_165 >= 7 && ! F_421 ( V_2 ) )
V_16 -> V_319 = 32 ;
else if ( F_145 ( V_2 ) -> V_165 >= 4 || F_435 ( V_2 ) || F_436 ( V_2 ) || F_189 ( V_2 ) )
V_16 -> V_319 = 16 ;
else
V_16 -> V_319 = 8 ;
F_210 ( & V_16 -> V_18 . V_369 ) ;
F_269 ( V_2 ) ;
F_437 ( V_2 ) ;
F_434 ( & V_16 -> V_519 ) ;
V_16 -> V_18 . V_142 = true ;
V_16 -> V_18 . V_520 . V_521 = V_522 ;
V_16 -> V_18 . V_520 . V_523 = V_524 ;
V_16 -> V_18 . V_520 . V_525 = V_526 ;
F_438 ( & V_16 -> V_18 . V_520 ) ;
V_16 -> V_18 . V_527 . V_528 = V_529 ;
F_439 ( & V_16 -> V_18 . V_527 ) ;
F_440 ( V_2 , & V_16 -> V_18 . V_530 ) ;
F_441 ( & V_16 -> V_531 . V_294 ) ;
}
void F_442 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_153 * V_81 = V_32 -> V_189 ;
F_249 ( & V_81 -> V_18 . V_168 ) ;
F_7 ( & V_81 -> V_18 . V_294 ) ;
while ( ! F_211 ( & V_81 -> V_18 . V_293 ) ) {
struct V_145 * V_277 ;
V_277 = F_212 ( & V_81 -> V_18 . V_293 ,
struct V_145 ,
V_295 ) ;
F_209 ( & V_277 -> V_295 ) ;
V_277 -> V_81 = NULL ;
}
F_8 ( & V_81 -> V_18 . V_294 ) ;
}
static void
F_443 ( struct V_327 * V_328 )
{
struct V_153 * V_81 =
F_262 ( V_328 , F_213 ( * V_81 ) , V_18 . V_168 . V_328 ) ;
F_444 ( & V_81 -> V_154 , false ) ;
}
int F_445 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_153 * V_81 ;
int V_23 ;
F_423 ( L_26 ) ;
V_81 = F_446 ( sizeof( * V_81 ) , V_54 ) ;
if ( ! V_81 )
return - V_55 ;
V_32 -> V_189 = V_81 ;
V_81 -> V_16 = V_2 -> V_27 ;
V_81 -> V_32 = V_32 ;
F_447 ( & V_81 -> V_18 . V_294 ) ;
F_210 ( & V_81 -> V_18 . V_293 ) ;
F_433 ( & V_81 -> V_18 . V_168 ,
F_443 ) ;
V_23 = F_448 ( V_2 , V_32 ) ;
if ( V_23 )
F_37 ( V_81 ) ;
return V_23 ;
}
void F_449 ( struct V_6 * V_374 ,
struct V_6 * V_532 ,
unsigned V_438 )
{
if ( V_374 ) {
F_16 ( ! F_128 ( & V_374 -> V_8 . V_2 -> V_29 ) ) ;
F_16 ( ! ( V_374 -> V_438 & V_438 ) ) ;
V_374 -> V_438 &= ~ V_438 ;
}
if ( V_532 ) {
F_16 ( ! F_128 ( & V_532 -> V_8 . V_2 -> V_29 ) ) ;
F_16 ( V_532 -> V_438 & V_438 ) ;
V_532 -> V_438 |= V_438 ;
}
}
static bool F_450 ( struct V_533 * V_533 , struct V_149 * V_534 )
{
if ( ! F_128 ( V_533 ) )
return false ;
#if F_451 ( V_535 ) || F_451 ( V_536 )
return V_533 -> V_537 == V_534 ;
#else
return false ;
#endif
}
static bool F_452 ( struct V_1 * V_2 , bool * V_121 )
{
if ( ! F_280 ( & V_2 -> V_29 ) ) {
if ( ! F_450 ( & V_2 -> V_29 , V_176 ) )
return false ;
if ( F_334 ( V_2 ) -> V_18 . V_227 )
return false ;
* V_121 = false ;
} else
* V_121 = true ;
return true ;
}
static int F_453 ( struct V_6 * V_7 )
{
struct V_71 * V_72 ;
int V_246 = 0 ;
F_20 (vma, &obj->vma_list, vma_link)
if ( F_293 ( & V_72 -> V_339 ) )
V_246 ++ ;
return V_246 ;
}
static unsigned long
V_524 ( struct V_520 * V_520 , struct V_538 * V_539 )
{
struct V_15 * V_16 =
F_262 ( V_520 , struct V_15 , V_18 . V_520 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_6 * V_7 ;
unsigned long V_246 ;
bool V_121 ;
if ( ! F_452 ( V_2 , & V_121 ) )
return 0 ;
V_246 = 0 ;
F_20 (obj, &dev_priv->mm.unbound_list, global_list)
if ( V_7 -> V_235 == 0 )
V_246 += V_7 -> V_8 . V_17 >> V_215 ;
F_20 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_21 ( V_7 ) &&
V_7 -> V_235 == F_453 ( V_7 ) )
V_246 += V_7 -> V_8 . V_17 >> V_215 ;
}
if ( V_121 )
F_23 ( & V_2 -> V_29 ) ;
return V_246 ;
}
unsigned long F_346 ( struct V_6 * V_540 ,
struct V_384 * V_268 ,
enum V_541 V_387 )
{
struct V_15 * V_16 = V_540 -> V_8 . V_2 -> V_27 ;
struct V_71 * V_72 ;
F_16 ( V_268 == & V_16 -> V_18 . V_418 -> V_8 ) ;
F_20 (vma, &o->vma_list, vma_link) {
if ( V_72 -> V_268 == V_268 && V_72 -> V_341 . type == V_387 )
return V_72 -> V_339 . V_107 ;
}
F_141 ( 1 , L_27 ,
F_296 ( V_268 ) ? L_28 : L_29 ) ;
return - 1 ;
}
bool F_454 ( struct V_6 * V_540 ,
struct V_384 * V_268 ,
enum V_541 V_387 )
{
struct V_71 * V_72 ;
F_20 (vma, &o->vma_list, vma_link)
if ( V_72 -> V_268 == V_268 &&
V_72 -> V_341 . type == V_387 &&
F_293 ( & V_72 -> V_339 ) )
return true ;
return false ;
}
bool F_208 ( struct V_6 * V_540 )
{
struct V_71 * V_72 ;
F_20 (vma, &o->vma_list, vma_link)
if ( F_293 ( & V_72 -> V_339 ) )
return true ;
return false ;
}
unsigned long F_455 ( struct V_6 * V_540 ,
struct V_384 * V_268 )
{
struct V_15 * V_16 = V_540 -> V_8 . V_2 -> V_27 ;
struct V_71 * V_72 ;
F_16 ( V_268 == & V_16 -> V_18 . V_418 -> V_8 ) ;
F_41 ( F_211 ( & V_540 -> V_345 ) ) ;
F_20 (vma, &o->vma_list, vma_link)
if ( V_72 -> V_268 == V_268 )
return V_72 -> V_339 . V_17 ;
return 0 ;
}
static unsigned long
V_522 ( struct V_520 * V_520 , struct V_538 * V_539 )
{
struct V_15 * V_16 =
F_262 ( V_520 , struct V_15 , V_18 . V_520 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_542 ;
bool V_121 ;
if ( ! F_452 ( V_2 , & V_121 ) )
return V_543 ;
V_542 = F_193 ( V_16 ,
V_539 -> V_544 ,
V_228 |
V_229 |
V_230 ) ;
if ( V_542 < V_539 -> V_544 )
V_542 += F_193 ( V_16 ,
V_539 -> V_544 - V_542 ,
V_228 |
V_229 ) ;
if ( V_121 )
F_23 ( & V_2 -> V_29 ) ;
return V_542 ;
}
static int
V_529 ( struct V_545 * V_546 , unsigned long V_547 , void * V_548 )
{
struct V_15 * V_16 =
F_262 ( V_546 , struct V_15 , V_18 . V_527 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_6 * V_7 ;
unsigned long V_156 = F_148 ( 5000 ) + 1 ;
unsigned long V_34 , V_405 , V_549 , V_550 ;
bool V_437 ;
bool V_121 ;
while ( ! F_452 ( V_2 , & V_121 ) && -- V_156 ) {
F_456 ( 1 ) ;
if ( F_457 ( V_176 ) )
return V_551 ;
}
if ( V_156 == 0 ) {
F_458 ( L_30 ) ;
return V_551 ;
}
V_437 = V_16 -> V_18 . V_142 ;
V_16 -> V_18 . V_142 = false ;
V_550 = F_194 ( V_16 ) ;
V_16 -> V_18 . V_142 = V_437 ;
V_549 = V_405 = V_34 = 0 ;
F_20 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( ! V_7 -> V_8 . V_41 )
continue;
if ( V_7 -> V_235 )
V_34 += V_7 -> V_8 . V_17 ;
else
V_549 += V_7 -> V_8 . V_17 ;
}
F_20 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! V_7 -> V_8 . V_41 )
continue;
if ( V_7 -> V_235 )
V_34 += V_7 -> V_8 . V_17 ;
else
V_405 += V_7 -> V_8 . V_17 ;
}
if ( V_121 )
F_23 ( & V_2 -> V_29 ) ;
if ( V_550 || V_549 || V_405 )
F_459 ( L_31 ,
V_550 << V_215 , V_34 ) ;
if ( V_549 || V_405 )
F_458 ( L_32
L_33 ,
V_405 , V_549 ) ;
* ( unsigned long * ) V_548 += V_550 ;
return V_551 ;
}
struct V_71 * F_333 ( struct V_6 * V_7 )
{
struct V_384 * V_552 = F_460 ( V_7 ) ;
struct V_71 * V_72 ;
F_20 (vma, &obj->vma_list, vma_link)
if ( V_72 -> V_268 == V_552 &&
V_72 -> V_341 . type == V_342 )
return V_72 ;
return NULL ;
}

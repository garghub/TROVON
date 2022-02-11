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
int V_23 = 0 ;
V_23 = F_59 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
F_60 ( V_7 , NULL , V_84 ) ;
if ( F_61 ( V_43 , V_82 , args -> V_17 ) ) {
unsigned long V_85 ;
F_23 ( & V_2 -> V_29 ) ;
V_85 = F_62 ( V_43 , V_82 , args -> V_17 ) ;
F_19 ( & V_2 -> V_29 ) ;
if ( V_85 ) {
V_23 = - V_77 ;
goto V_86;
}
}
F_31 ( V_43 , args -> V_17 ) ;
F_34 ( V_2 ) ;
V_86:
F_63 ( V_7 , false ) ;
return V_23 ;
}
void * F_64 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
return F_65 ( V_16 -> V_87 , V_54 ) ;
}
void F_66 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
F_67 ( V_16 -> V_87 , V_7 ) ;
}
static int
F_68 ( struct V_31 * V_32 ,
struct V_1 * V_2 ,
T_4 V_17 ,
T_5 * V_88 )
{
struct V_6 * V_7 ;
int V_23 ;
T_6 V_89 ;
V_17 = F_69 ( V_17 , V_51 ) ;
if ( V_17 == 0 )
return - V_50 ;
V_7 = F_70 ( V_2 , V_17 ) ;
if ( V_7 == NULL )
return - V_55 ;
V_23 = F_71 ( V_32 , & V_7 -> V_8 , & V_89 ) ;
F_72 ( & V_7 -> V_8 ) ;
if ( V_23 )
return V_23 ;
* V_88 = V_89 ;
return 0 ;
}
int
F_73 ( struct V_31 * V_32 ,
struct V_1 * V_2 ,
struct V_90 * args )
{
args -> V_91 = F_74 ( args -> V_92 * F_75 ( args -> V_93 , 8 ) , 64 ) ;
args -> V_17 = args -> V_91 * args -> V_94 ;
return F_68 ( V_32 , V_2 ,
args -> V_17 , & args -> V_89 ) ;
}
int
F_76 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_95 * args = V_30 ;
return F_68 ( V_32 , V_2 ,
args -> V_17 , & args -> V_89 ) ;
}
static inline int
F_77 ( char T_3 * V_96 ,
const char * V_97 , int V_98 ,
int V_58 )
{
int V_23 , V_99 = 0 ;
while ( V_58 > 0 ) {
int V_100 = F_74 ( V_98 + 1 , 64 ) ;
int V_101 = F_78 ( V_100 - V_98 , V_58 ) ;
int V_102 = V_98 ^ 64 ;
V_23 = F_79 ( V_96 + V_99 ,
V_97 + V_102 ,
V_101 ) ;
if ( V_23 )
return V_23 + V_58 ;
V_99 += V_101 ;
V_98 += V_101 ;
V_58 -= V_101 ;
}
return 0 ;
}
static inline int
F_80 ( char * V_97 , int V_98 ,
const char T_3 * V_96 ,
int V_58 )
{
int V_23 , V_99 = 0 ;
while ( V_58 > 0 ) {
int V_100 = F_74 ( V_98 + 1 , 64 ) ;
int V_101 = F_78 ( V_100 - V_98 , V_58 ) ;
int V_102 = V_98 ^ 64 ;
V_23 = F_81 ( V_97 + V_102 ,
V_96 + V_99 ,
V_101 ) ;
if ( V_23 )
return V_23 + V_58 ;
V_99 += V_101 ;
V_98 += V_101 ;
V_58 -= V_101 ;
}
return 0 ;
}
int F_82 ( struct V_6 * V_7 ,
int * V_103 )
{
int V_23 ;
* V_103 = 0 ;
if ( ! V_7 -> V_8 . V_41 )
return - V_50 ;
if ( ! ( V_7 -> V_8 . V_64 & V_66 ) ) {
* V_103 = ! F_1 ( V_7 -> V_8 . V_2 ,
V_7 -> V_9 ) ;
V_23 = F_59 ( V_7 , true ) ;
if ( V_23 )
return V_23 ;
F_83 ( V_7 ) ;
}
V_23 = F_56 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_84 ( V_7 ) ;
return V_23 ;
}
static int
F_85 ( struct V_52 * V_52 , int V_104 , int V_105 ,
char T_3 * V_82 ,
bool V_106 , bool V_103 )
{
char * V_43 ;
int V_23 ;
if ( F_86 ( V_106 ) )
return - V_50 ;
V_43 = F_30 ( V_52 ) ;
if ( V_103 )
F_31 ( V_43 + V_104 ,
V_105 ) ;
V_23 = F_87 ( V_82 ,
V_43 + V_104 ,
V_105 ) ;
F_32 ( V_43 ) ;
return V_23 ? - V_77 : 0 ;
}
static void
F_88 ( char * V_107 , unsigned long V_58 ,
bool V_108 )
{
if ( F_86 ( V_108 ) ) {
unsigned long V_109 = ( unsigned long ) V_107 ;
unsigned long V_110 = ( unsigned long ) V_107 + V_58 ;
V_109 = F_89 ( V_109 , 128 ) ;
V_110 = F_90 ( V_110 , 128 ) ;
F_31 ( ( void * ) V_109 , V_110 - V_109 ) ;
} else {
F_31 ( V_107 , V_58 ) ;
}
}
static int
F_91 ( struct V_52 * V_52 , int V_104 , int V_105 ,
char T_3 * V_82 ,
bool V_106 , bool V_103 )
{
char * V_43 ;
int V_23 ;
V_43 = F_92 ( V_52 ) ;
if ( V_103 )
F_88 ( V_43 + V_104 ,
V_105 ,
V_106 ) ;
if ( V_106 )
V_23 = F_77 ( V_82 ,
V_43 , V_104 ,
V_105 ) ;
else
V_23 = F_79 ( V_82 ,
V_43 + V_104 ,
V_105 ) ;
F_93 ( V_52 ) ;
return V_23 ? - V_77 : 0 ;
}
static int
F_94 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_111 * args ,
struct V_31 * V_32 )
{
char T_3 * V_82 ;
T_7 V_112 ;
T_8 V_57 ;
int V_104 , V_105 , V_23 = 0 ;
int V_113 , V_106 ;
int V_114 = 0 ;
int V_103 = 0 ;
struct V_115 V_116 ;
V_82 = F_58 ( args -> V_83 ) ;
V_112 = args -> V_17 ;
V_113 = F_26 ( V_7 ) ;
V_23 = F_82 ( V_7 , & V_103 ) ;
if ( V_23 )
return V_23 ;
V_57 = args -> V_57 ;
F_95 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_52 * V_52 = F_96 ( & V_116 ) ;
if ( V_112 <= 0 )
break;
V_104 = F_97 ( V_57 ) ;
V_105 = V_112 ;
if ( ( V_104 + V_105 ) > V_51 )
V_105 = V_51 - V_104 ;
V_106 = V_113 &&
( F_98 ( V_52 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_85 ( V_52 , V_104 , V_105 ,
V_82 , V_106 ,
V_103 ) ;
if ( V_23 == 0 )
goto V_117;
F_23 ( & V_2 -> V_29 ) ;
if ( F_99 ( ! V_118 . V_119 ) && ! V_114 ) {
V_23 = F_100 ( V_82 , V_112 ) ;
( void ) V_23 ;
V_114 = 1 ;
}
V_23 = F_91 ( V_52 , V_104 , V_105 ,
V_82 , V_106 ,
V_103 ) ;
F_19 ( & V_2 -> V_29 ) ;
if ( V_23 )
goto V_86;
V_117:
V_112 -= V_105 ;
V_82 += V_105 ;
V_57 += V_105 ;
}
V_86:
F_101 ( V_7 ) ;
return V_23 ;
}
int
F_102 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_111 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_103 ( V_120 ,
F_58 ( args -> V_83 ) ,
args -> V_17 ) )
return - V_77 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_32 , args -> V_89 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
if ( args -> V_57 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_57 ) {
V_23 = - V_50 ;
goto V_86;
}
if ( ! V_7 -> V_8 . V_41 ) {
V_23 = - V_50 ;
goto V_86;
}
F_106 ( V_7 , args -> V_57 , args -> V_17 ) ;
V_23 = F_94 ( V_2 , V_7 , args , V_32 ) ;
V_86:
F_53 ( & V_7 -> V_8 ) ;
V_122:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static inline int
F_107 ( struct V_123 * V_40 ,
T_8 V_124 , int V_125 ,
char T_3 * V_82 ,
int V_58 )
{
void T_9 * V_126 ;
void * V_43 ;
unsigned long V_85 ;
V_126 = F_108 ( V_40 , V_124 ) ;
V_43 = ( void V_127 * ) V_126 + V_125 ;
V_85 = F_61 ( V_43 ,
V_82 , V_58 ) ;
F_109 ( V_126 ) ;
return V_85 ;
}
static int
F_110 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_80 * args ,
struct V_31 * V_32 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_7 V_112 ;
T_8 V_57 , V_124 ;
char T_3 * V_82 ;
int V_125 , V_105 , V_23 ;
V_23 = F_111 ( V_7 , 0 , V_128 | V_129 ) ;
if ( V_23 )
goto V_86;
V_23 = F_112 ( V_7 , true ) ;
if ( V_23 )
goto V_130;
V_23 = F_113 ( V_7 ) ;
if ( V_23 )
goto V_130;
V_82 = F_58 ( args -> V_83 ) ;
V_112 = args -> V_17 ;
V_57 = F_114 ( V_7 ) + args -> V_57 ;
F_60 ( V_7 , NULL , V_131 ) ;
while ( V_112 > 0 ) {
V_124 = V_57 & V_132 ;
V_125 = F_97 ( V_57 ) ;
V_105 = V_112 ;
if ( ( V_125 + V_112 ) > V_51 )
V_105 = V_51 - V_125 ;
if ( F_107 ( V_16 -> V_36 . V_133 , V_124 ,
V_125 , V_82 , V_105 ) ) {
V_23 = - V_77 ;
goto V_134;
}
V_112 -= V_105 ;
V_82 += V_105 ;
V_57 += V_105 ;
}
V_134:
F_63 ( V_7 , false ) ;
V_130:
F_115 ( V_7 ) ;
V_86:
return V_23 ;
}
static int
F_116 ( struct V_52 * V_52 , int V_104 , int V_105 ,
char T_3 * V_82 ,
bool V_106 ,
bool V_135 ,
bool V_136 )
{
char * V_43 ;
int V_23 ;
if ( F_86 ( V_106 ) )
return - V_50 ;
V_43 = F_30 ( V_52 ) ;
if ( V_135 )
F_31 ( V_43 + V_104 ,
V_105 ) ;
V_23 = F_117 ( V_43 + V_104 ,
V_82 , V_105 ) ;
if ( V_136 )
F_31 ( V_43 + V_104 ,
V_105 ) ;
F_32 ( V_43 ) ;
return V_23 ? - V_77 : 0 ;
}
static int
F_118 ( struct V_52 * V_52 , int V_104 , int V_105 ,
char T_3 * V_82 ,
bool V_106 ,
bool V_135 ,
bool V_136 )
{
char * V_43 ;
int V_23 ;
V_43 = F_92 ( V_52 ) ;
if ( F_86 ( V_135 || V_106 ) )
F_88 ( V_43 + V_104 ,
V_105 ,
V_106 ) ;
if ( V_106 )
V_23 = F_80 ( V_43 , V_104 ,
V_82 ,
V_105 ) ;
else
V_23 = F_81 ( V_43 + V_104 ,
V_82 ,
V_105 ) ;
if ( V_136 )
F_88 ( V_43 + V_104 ,
V_105 ,
V_106 ) ;
F_93 ( V_52 ) ;
return V_23 ? - V_77 : 0 ;
}
static int
F_119 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_80 * args ,
struct V_31 * V_32 )
{
T_7 V_112 ;
T_8 V_57 ;
char T_3 * V_82 ;
int V_104 , V_105 , V_23 = 0 ;
int V_113 , V_106 ;
int V_137 = 0 ;
int V_136 = 0 ;
int V_135 = 0 ;
struct V_115 V_116 ;
V_82 = F_58 ( args -> V_83 ) ;
V_112 = args -> V_17 ;
V_113 = F_26 ( V_7 ) ;
if ( V_7 -> V_8 . V_65 != V_66 ) {
V_136 = F_3 ( V_7 ) ;
V_23 = F_59 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
F_83 ( V_7 ) ;
}
if ( ( V_7 -> V_8 . V_64 & V_66 ) == 0 )
V_135 =
! F_1 ( V_2 , V_7 -> V_9 ) ;
V_23 = F_56 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_60 ( V_7 , NULL , V_84 ) ;
F_84 ( V_7 ) ;
V_57 = args -> V_57 ;
V_7 -> V_68 = 1 ;
F_95 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_52 * V_52 = F_96 ( & V_116 ) ;
int V_138 ;
if ( V_112 <= 0 )
break;
V_104 = F_97 ( V_57 ) ;
V_105 = V_112 ;
if ( ( V_104 + V_105 ) > V_51 )
V_105 = V_51 - V_104 ;
V_138 = V_135 &&
( ( V_104 | V_105 )
& ( V_139 . V_140 - 1 ) ) ;
V_106 = V_113 &&
( F_98 ( V_52 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_116 ( V_52 , V_104 , V_105 ,
V_82 , V_106 ,
V_138 ,
V_136 ) ;
if ( V_23 == 0 )
goto V_117;
V_137 = 1 ;
F_23 ( & V_2 -> V_29 ) ;
V_23 = F_118 ( V_52 , V_104 , V_105 ,
V_82 , V_106 ,
V_138 ,
V_136 ) ;
F_19 ( & V_2 -> V_29 ) ;
if ( V_23 )
goto V_86;
V_117:
V_112 -= V_105 ;
V_82 += V_105 ;
V_57 += V_105 ;
}
V_86:
F_101 ( V_7 ) ;
if ( V_137 ) {
if ( ! V_136 &&
V_7 -> V_8 . V_65 != V_66 ) {
if ( F_120 ( V_7 , V_7 -> V_10 ) )
F_34 ( V_2 ) ;
}
}
if ( V_136 )
F_34 ( V_2 ) ;
F_63 ( V_7 , false ) ;
return V_23 ;
}
int
F_121 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_80 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_103 ( V_141 ,
F_58 ( args -> V_83 ) ,
args -> V_17 ) )
return - V_77 ;
if ( F_99 ( ! V_118 . V_119 ) ) {
V_23 = F_122 ( F_58 ( args -> V_83 ) ,
args -> V_17 ) ;
if ( V_23 )
return - V_77 ;
}
F_123 ( V_16 ) ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
goto V_142;
V_7 = F_104 ( F_105 ( V_2 , V_32 , args -> V_89 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
if ( args -> V_57 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_57 ) {
V_23 = - V_50 ;
goto V_86;
}
if ( ! V_7 -> V_8 . V_41 ) {
V_23 = - V_50 ;
goto V_86;
}
F_124 ( V_7 , args -> V_57 , args -> V_17 ) ;
V_23 = - V_77 ;
if ( V_7 -> V_11 == V_143 &&
V_7 -> V_8 . V_65 != V_66 &&
F_3 ( V_7 ) ) {
V_23 = F_110 ( V_2 , V_7 , args , V_32 ) ;
}
if ( V_23 == - V_77 || V_23 == - V_144 ) {
if ( V_7 -> V_44 )
V_23 = F_57 ( V_7 , args , V_32 ) ;
else
V_23 = F_119 ( V_2 , V_7 , args , V_32 ) ;
}
V_86:
F_53 ( & V_7 -> V_8 ) ;
V_122:
F_23 ( & V_2 -> V_29 ) ;
V_142:
F_125 ( V_16 ) ;
return V_23 ;
}
int
F_126 ( struct V_22 * error ,
bool V_145 )
{
if ( F_127 ( error ) ) {
if ( ! V_145 )
return - V_26 ;
if ( F_128 ( error ) )
return - V_26 ;
if ( ! error -> V_146 )
return - V_147 ;
}
return 0 ;
}
int
F_129 ( struct V_148 * V_149 )
{
int V_23 ;
F_16 ( ! F_130 ( & V_149 -> V_150 -> V_2 -> V_29 ) ) ;
V_23 = 0 ;
if ( V_149 == V_149 -> V_150 -> V_151 )
V_23 = F_131 ( V_149 -> V_150 ) ;
return V_23 ;
}
static void F_132 ( unsigned long V_30 )
{
F_133 ( (struct V_152 * ) V_30 ) ;
}
static bool F_134 ( struct V_15 * V_16 ,
struct V_153 * V_150 )
{
return F_135 ( V_150 -> V_154 , & V_16 -> V_28 . V_155 ) ;
}
static bool F_136 ( struct V_156 * V_81 )
{
if ( V_81 == NULL )
return true ;
return ! F_137 ( & V_81 -> V_157 , true ) ;
}
int F_138 ( struct V_148 * V_149 ,
unsigned V_158 ,
bool V_145 ,
T_10 * V_159 ,
struct V_156 * V_81 )
{
struct V_153 * V_150 = F_139 ( V_149 ) ;
struct V_1 * V_2 = V_150 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
const bool V_160 =
F_140 ( V_16 -> V_28 . V_161 ) & F_141 ( V_150 ) ;
F_142 ( V_162 ) ;
unsigned long V_163 ;
T_10 V_164 , V_165 ;
int V_23 ;
F_143 ( ! F_144 ( V_16 ) , L_2 ) ;
if ( F_145 ( V_149 , true ) )
return 0 ;
V_163 = V_159 ?
V_166 + F_146 ( ( V_167 ) * V_159 ) : 0 ;
if ( F_147 ( V_2 ) -> V_168 >= 6 && V_150 -> V_154 == V_169 && F_136 ( V_81 ) ) {
F_148 ( V_16 ) ;
if ( V_81 )
F_149 ( V_16 -> V_170 ,
& V_81 -> V_18 . V_171 ,
F_150 ( 100 ) ) ;
}
if ( ! V_160 && F_16 ( ! V_150 -> V_172 ( V_150 ) ) )
return - V_173 ;
F_151 ( V_149 ) ;
V_164 = F_152 () ;
for (; ; ) {
struct V_174 V_175 ;
F_153 ( & V_150 -> V_176 , & V_162 ,
V_145 ? V_177 : V_178 ) ;
if ( V_158 != F_154 ( & V_16 -> V_28 . V_158 ) ) {
V_23 = F_126 ( & V_16 -> V_28 , V_145 ) ;
if ( V_23 == 0 )
V_23 = - V_147 ;
break;
}
if ( F_145 ( V_149 , false ) ) {
V_23 = 0 ;
break;
}
if ( V_145 && F_155 ( V_179 ) ) {
V_23 = - V_180 ;
break;
}
if ( V_159 && F_156 ( V_166 , V_163 ) ) {
V_23 = - V_181 ;
break;
}
V_175 . V_182 = NULL ;
if ( V_159 || F_134 ( V_16 , V_150 ) ) {
unsigned long V_183 ;
F_157 ( & V_175 , F_132 , ( unsigned long ) V_179 ) ;
V_183 = F_134 ( V_16 , V_150 ) ? V_166 + 1 : V_163 ;
F_158 ( & V_175 , V_183 ) ;
}
F_159 () ;
if ( V_175 . V_182 ) {
F_160 ( & V_175 ) ;
F_161 ( & V_175 ) ;
}
}
V_165 = F_152 () ;
F_162 ( V_149 ) ;
if ( ! V_160 )
V_150 -> V_184 ( V_150 ) ;
F_163 ( & V_150 -> V_176 , & V_162 ) ;
if ( V_159 ) {
T_10 V_185 = * V_159 - ( V_165 - V_164 ) ;
* V_159 = V_185 < 0 ? 0 : V_185 ;
if ( V_23 == - V_181 && * V_159 < F_164 ( 1 ) * 1000 )
* V_159 = 0 ;
}
return V_23 ;
}
int
F_165 ( struct V_148 * V_149 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
bool V_145 ;
unsigned V_158 ;
int V_23 ;
F_41 ( V_149 == NULL ) ;
V_2 = V_149 -> V_150 -> V_2 ;
V_16 = V_2 -> V_27 ;
V_145 = V_16 -> V_18 . V_145 ;
F_41 ( ! F_130 ( & V_2 -> V_29 ) ) ;
V_23 = F_126 ( & V_16 -> V_28 , V_145 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_129 ( V_149 ) ;
if ( V_23 )
return V_23 ;
V_158 = F_154 ( & V_16 -> V_28 . V_158 ) ;
F_166 ( V_149 ) ;
V_23 = F_138 ( V_149 , V_158 ,
V_145 , NULL , NULL ) ;
F_167 ( V_149 ) ;
return V_23 ;
}
static int
F_168 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_186 )
return 0 ;
F_169 ( & V_7 -> V_187 , NULL ) ;
return 0 ;
}
static T_11 int
F_59 ( struct V_6 * V_7 ,
bool V_188 )
{
struct V_148 * V_149 ;
int V_23 ;
V_149 = V_188 ? V_7 -> V_187 : V_7 -> V_189 ;
if ( ! V_149 )
return 0 ;
V_23 = F_165 ( V_149 ) ;
if ( V_23 )
return V_23 ;
return F_168 ( V_7 ) ;
}
static T_11 int
F_170 ( struct V_6 * V_7 ,
struct V_156 * V_81 ,
bool V_188 )
{
struct V_148 * V_149 ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
unsigned V_158 ;
int V_23 ;
F_41 ( ! F_130 ( & V_2 -> V_29 ) ) ;
F_41 ( ! V_16 -> V_18 . V_145 ) ;
V_149 = V_188 ? V_7 -> V_187 : V_7 -> V_189 ;
if ( ! V_149 )
return 0 ;
V_23 = F_126 ( & V_16 -> V_28 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = F_129 ( V_149 ) ;
if ( V_23 )
return V_23 ;
V_158 = F_154 ( & V_16 -> V_28 . V_158 ) ;
F_166 ( V_149 ) ;
F_23 ( & V_2 -> V_29 ) ;
V_23 = F_138 ( V_149 , V_158 , true , NULL , V_81 ) ;
F_19 ( & V_2 -> V_29 ) ;
F_167 ( V_149 ) ;
if ( V_23 )
return V_23 ;
return F_168 ( V_7 ) ;
}
int
F_171 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_190 * args = V_30 ;
struct V_6 * V_7 ;
T_5 V_64 = args -> V_64 ;
T_5 V_65 = args -> V_65 ;
int V_23 ;
if ( V_65 & V_191 )
return - V_50 ;
if ( V_64 & V_191 )
return - V_50 ;
if ( V_65 != 0 && V_64 != V_65 )
return - V_50 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_32 , args -> V_89 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
V_23 = F_170 ( V_7 ,
V_32 -> V_192 ,
! V_65 ) ;
if ( V_23 )
goto V_193;
if ( V_64 & V_194 )
V_23 = F_112 ( V_7 , V_65 != 0 ) ;
else
V_23 = F_42 ( V_7 , V_65 != 0 ) ;
V_193:
F_53 ( & V_7 -> V_8 ) ;
V_122:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_172 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_195 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_32 , args -> V_89 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
if ( V_7 -> V_10 )
F_173 ( V_7 ) ;
F_53 ( & V_7 -> V_8 ) ;
V_122:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_174 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_196 * args = V_30 ;
struct V_197 * V_7 ;
unsigned long V_107 ;
if ( args -> V_198 & ~ ( V_199 ) )
return - V_50 ;
if ( args -> V_198 & V_199 && ! V_200 )
return - V_173 ;
V_7 = F_105 ( V_2 , V_32 , args -> V_89 ) ;
if ( V_7 == NULL )
return - V_121 ;
if ( ! V_7 -> V_41 ) {
F_72 ( V_7 ) ;
return - V_50 ;
}
V_107 = F_175 ( V_7 -> V_41 , 0 , args -> V_17 ,
V_201 | V_202 , V_203 ,
args -> V_57 ) ;
if ( args -> V_198 & V_199 ) {
struct V_204 * V_18 = V_179 -> V_18 ;
struct V_205 * V_72 ;
F_176 ( & V_18 -> V_206 ) ;
V_72 = F_177 ( V_18 , V_107 ) ;
if ( V_72 )
V_72 -> V_207 =
F_178 ( F_179 ( V_72 -> V_208 ) ) ;
else
V_107 = - V_55 ;
F_180 ( & V_18 -> V_206 ) ;
}
F_72 ( V_7 ) ;
if ( F_28 ( ( void * ) V_107 ) )
return V_107 ;
args -> V_209 = ( T_4 ) V_107 ;
return 0 ;
}
int F_181 ( struct V_205 * V_72 , struct V_210 * V_211 )
{
struct V_6 * V_7 = F_104 ( V_72 -> V_212 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_12 V_125 ;
unsigned long V_213 ;
int V_23 = 0 ;
bool V_214 = ! ! ( V_211 -> V_198 & V_215 ) ;
F_123 ( V_16 ) ;
V_125 = ( ( unsigned long ) V_211 -> V_216 - V_72 -> V_217 ) >>
V_218 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
goto V_86;
F_182 ( V_7 , V_125 , true , V_214 ) ;
V_23 = F_170 ( V_7 , NULL , ! V_214 ) ;
if ( V_23 )
goto V_122;
if ( V_7 -> V_9 != V_5 && ! F_2 ( V_2 ) ) {
V_23 = - V_77 ;
goto V_122;
}
V_23 = F_111 ( V_7 , 0 , V_128 ) ;
if ( V_23 )
goto V_122;
V_23 = F_112 ( V_7 , V_214 ) ;
if ( V_23 )
goto V_219;
V_23 = F_183 ( V_7 ) ;
if ( V_23 )
goto V_219;
V_213 = V_16 -> V_36 . V_220 + F_114 ( V_7 ) ;
V_213 >>= V_218 ;
if ( ! V_7 -> V_221 ) {
unsigned long V_17 = F_184 (unsigned long,
vma->vm_end - vma->vm_start,
obj->base.size) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_17 > > V_218 ; V_49 ++ ) {
V_23 = F_185 ( V_72 ,
( unsigned long ) V_72 -> V_217 + V_49 * V_51 ,
V_213 + V_49 ) ;
if ( V_23 )
break;
}
V_7 -> V_221 = true ;
} else
V_23 = F_185 ( V_72 ,
( unsigned long ) V_211 -> V_216 ,
V_213 + V_125 ) ;
V_219:
F_115 ( V_7 ) ;
V_122:
F_23 ( & V_2 -> V_29 ) ;
V_86:
switch ( V_23 ) {
case - V_26 :
if ( ! F_128 ( & V_16 -> V_28 ) ) {
V_23 = V_222 ;
break;
}
case - V_147 :
case 0 :
case - V_180 :
case - V_223 :
case - V_76 :
V_23 = V_224 ;
break;
case - V_55 :
V_23 = V_225 ;
break;
case - V_144 :
case - V_77 :
V_23 = V_222 ;
break;
default:
F_186 ( V_23 , L_3 , V_23 ) ;
V_23 = V_222 ;
break;
}
F_125 ( V_16 ) ;
return V_23 ;
}
void
F_5 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_221 )
return;
F_187 ( & V_7 -> V_8 . V_226 ,
V_7 -> V_8 . V_2 -> V_227 -> V_42 ) ;
V_7 -> V_221 = false ;
}
void
F_188 ( struct V_15 * V_16 )
{
struct V_6 * V_7 ;
F_20 (obj, &dev_priv->mm.bound_list, global_list)
F_5 ( V_7 ) ;
}
T_5
F_189 ( struct V_1 * V_2 , T_5 V_17 , int V_11 )
{
T_5 V_228 ;
if ( F_147 ( V_2 ) -> V_168 >= 4 ||
V_11 == V_143 )
return V_17 ;
if ( F_147 ( V_2 ) -> V_168 == 3 )
V_228 = 1024 * 1024 ;
else
V_228 = 512 * 1024 ;
while ( V_228 < V_17 )
V_228 <<= 1 ;
return V_228 ;
}
T_5
F_190 ( struct V_1 * V_2 , T_5 V_17 ,
int V_11 , bool V_229 )
{
if ( F_147 ( V_2 ) -> V_168 >= 4 || ( ! V_229 && F_191 ( V_2 ) ) ||
V_11 == V_143 )
return 4096 ;
return F_189 ( V_2 , V_17 , V_11 ) ;
}
static int F_192 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_193 ( & V_7 -> V_8 . V_226 ) )
return 0 ;
V_16 -> V_18 . V_230 = true ;
V_23 = F_194 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_144 )
goto V_86;
F_195 ( V_16 ,
V_7 -> V_8 . V_17 >> V_218 ,
V_231 |
V_232 |
V_233 ) ;
V_23 = F_194 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_144 )
goto V_86;
F_196 ( V_16 ) ;
V_23 = F_194 ( & V_7 -> V_8 ) ;
V_86:
V_16 -> V_18 . V_230 = false ;
return V_23 ;
}
static void F_197 ( struct V_6 * V_7 )
{
F_198 ( & V_7 -> V_8 ) ;
}
int
F_199 ( struct V_31 * V_32 ,
struct V_1 * V_2 ,
T_5 V_89 ,
T_4 * V_57 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_32 , V_89 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
if ( V_7 -> V_8 . V_17 > V_16 -> V_36 . V_234 ) {
V_23 = - V_235 ;
goto V_86;
}
if ( V_7 -> V_62 != V_70 ) {
F_200 ( L_4 ) ;
V_23 = - V_77 ;
goto V_86;
}
V_23 = F_192 ( V_7 ) ;
if ( V_23 )
goto V_86;
* V_57 = F_201 ( & V_7 -> V_8 . V_226 ) ;
V_86:
F_53 ( & V_7 -> V_8 ) ;
V_122:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_202 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_236 * args = V_30 ;
return F_199 ( V_32 , V_2 , args -> V_89 , & args -> V_57 ) ;
}
static void
F_203 ( struct V_6 * V_7 )
{
F_197 ( V_7 ) ;
if ( V_7 -> V_8 . V_41 == NULL )
return;
F_204 ( F_25 ( V_7 -> V_8 . V_41 ) , 0 , ( T_8 ) - 1 ) ;
V_7 -> V_62 = V_63 ;
}
static void
F_205 ( struct V_6 * V_7 )
{
struct V_39 * V_40 ;
switch ( V_7 -> V_62 ) {
case V_67 :
F_203 ( V_7 ) ;
case V_63 :
return;
}
if ( V_7 -> V_8 . V_41 == NULL )
return;
V_40 = F_25 ( V_7 -> V_8 . V_41 ) -> V_42 ,
F_206 ( V_40 , 0 , ( T_8 ) - 1 ) ;
}
static void
F_207 ( struct V_6 * V_7 )
{
struct V_115 V_116 ;
int V_23 ;
F_41 ( V_7 -> V_62 == V_63 ) ;
V_23 = F_42 ( V_7 , true ) ;
if ( V_23 ) {
F_16 ( V_23 != - V_26 ) ;
F_120 ( V_7 , true ) ;
V_7 -> V_8 . V_64 = V_7 -> V_8 . V_65 = V_66 ;
}
if ( F_26 ( V_7 ) )
F_208 ( V_7 ) ;
if ( V_7 -> V_62 == V_67 )
V_7 -> V_68 = 0 ;
F_95 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_52 * V_52 = F_96 ( & V_116 ) ;
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
const struct V_237 * V_78 = V_7 -> V_78 ;
if ( V_7 -> V_60 == NULL )
return 0 ;
if ( V_7 -> V_238 )
return - V_76 ;
F_41 ( F_209 ( V_7 ) ) ;
F_210 ( & V_7 -> V_239 ) ;
V_78 -> V_240 ( V_7 ) ;
V_7 -> V_60 = NULL ;
F_205 ( V_7 ) ;
return 0 ;
}
static int
F_211 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_241 , V_49 ;
struct V_39 * V_40 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_115 V_116 ;
struct V_52 * V_52 ;
unsigned long V_242 = 0 ;
T_13 V_243 ;
F_41 ( V_7 -> V_8 . V_64 & V_191 ) ;
F_41 ( V_7 -> V_8 . V_65 & V_191 ) ;
V_46 = F_35 ( sizeof( * V_46 ) , V_54 ) ;
if ( V_46 == NULL )
return - V_55 ;
V_241 = V_7 -> V_8 . V_17 / V_51 ;
if ( F_36 ( V_46 , V_241 , V_54 ) ) {
F_37 ( V_46 ) ;
return - V_55 ;
}
V_40 = F_25 ( V_7 -> V_8 . V_41 ) -> V_42 ;
V_243 = F_212 ( V_40 ) ;
V_243 |= V_244 | V_245 | V_246 ;
V_243 &= ~ ( V_247 | V_248 ) ;
V_48 = V_46 -> V_56 ;
V_46 -> V_249 = 0 ;
for ( V_49 = 0 ; V_49 < V_241 ; V_49 ++ ) {
V_52 = F_213 ( V_40 , V_49 , V_243 ) ;
if ( F_28 ( V_52 ) ) {
F_195 ( V_16 ,
V_241 ,
V_231 |
V_232 |
V_233 ) ;
V_52 = F_213 ( V_40 , V_49 , V_243 ) ;
}
if ( F_28 ( V_52 ) ) {
F_196 ( V_16 ) ;
V_52 = F_27 ( V_40 , V_49 ) ;
if ( F_28 ( V_52 ) )
goto V_250;
}
#ifdef F_214
if ( F_215 () ) {
V_46 -> V_249 ++ ;
F_216 ( V_48 , V_52 , V_51 , 0 ) ;
V_48 = F_217 ( V_48 ) ;
continue;
}
#endif
if ( ! V_49 || F_218 ( V_52 ) != V_242 + 1 ) {
if ( V_49 )
V_48 = F_217 ( V_48 ) ;
V_46 -> V_249 ++ ;
F_216 ( V_48 , V_52 , V_51 , 0 ) ;
} else {
V_48 -> V_58 += V_51 ;
}
V_242 = F_218 ( V_52 ) ;
F_16 ( ( V_243 & V_251 ) && ( V_242 >= 0x00100000UL ) ) ;
}
#ifdef F_214
if ( ! F_215 () )
#endif
F_219 ( V_48 ) ;
V_7 -> V_60 = V_46 ;
if ( F_26 ( V_7 ) )
F_220 ( V_7 ) ;
if ( V_7 -> V_11 != V_143 &&
V_16 -> V_252 & V_253 )
F_84 ( V_7 ) ;
return 0 ;
V_250:
F_219 ( V_48 ) ;
F_95 (st->sgl, &sg_iter, st->nents, 0 )
F_33 ( F_96 ( & V_116 ) ) ;
F_45 ( V_46 ) ;
F_37 ( V_46 ) ;
if ( F_29 ( V_52 ) == - V_144 )
return - V_55 ;
else
return F_29 ( V_52 ) ;
}
int
F_56 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
const struct V_237 * V_78 = V_7 -> V_78 ;
int V_23 ;
if ( V_7 -> V_60 )
return 0 ;
if ( V_7 -> V_62 != V_70 ) {
F_200 ( L_5 ) ;
return - V_77 ;
}
F_41 ( V_7 -> V_238 ) ;
V_23 = V_78 -> V_254 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_221 ( & V_7 -> V_239 , & V_16 -> V_18 . V_255 ) ;
return 0 ;
}
static void
F_222 ( struct V_6 * V_7 ,
struct V_153 * V_150 )
{
struct V_148 * V_149 ;
struct V_153 * V_256 ;
F_41 ( V_150 == NULL ) ;
V_149 = F_223 ( V_150 ) ;
V_256 = F_139 ( V_7 -> V_189 ) ;
if ( V_256 != V_150 && V_7 -> V_187 ) {
F_169 ( & V_7 -> V_187 , V_149 ) ;
}
if ( ! V_7 -> V_186 ) {
F_49 ( & V_7 -> V_8 ) ;
V_7 -> V_186 = 1 ;
}
F_224 ( & V_7 -> V_257 , & V_150 -> V_258 ) ;
F_169 ( & V_7 -> V_189 , V_149 ) ;
}
void F_225 ( struct V_71 * V_72 ,
struct V_153 * V_150 )
{
F_224 ( & V_72 -> V_259 , & V_72 -> V_260 -> V_258 ) ;
return F_222 ( V_72 -> V_7 , V_150 ) ;
}
static void
F_226 ( struct V_6 * V_7 )
{
struct V_71 * V_72 ;
F_41 ( V_7 -> V_8 . V_65 & ~ V_191 ) ;
F_41 ( ! V_7 -> V_186 ) ;
F_20 (vma, &obj->vma_list, vma_link) {
if ( ! F_227 ( & V_72 -> V_259 ) )
F_224 ( & V_72 -> V_259 , & V_72 -> V_260 -> V_261 ) ;
}
F_63 ( V_7 , true ) ;
F_228 ( & V_7 -> V_257 ) ;
F_169 ( & V_7 -> V_189 , NULL ) ;
F_169 ( & V_7 -> V_187 , NULL ) ;
V_7 -> V_8 . V_65 = 0 ;
F_169 ( & V_7 -> V_262 , NULL ) ;
V_7 -> V_186 = 0 ;
F_53 ( & V_7 -> V_8 ) ;
F_16 ( F_17 ( V_2 ) ) ;
}
static void
F_83 ( struct V_6 * V_7 )
{
if ( V_7 -> V_189 == NULL )
return;
if ( F_145 ( V_7 -> V_189 , true ) )
F_226 ( V_7 ) ;
}
static int
F_229 ( struct V_1 * V_2 , T_6 V_263 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_153 * V_150 ;
int V_23 , V_49 , V_264 ;
F_230 (ring, dev_priv, i) {
V_23 = F_231 ( V_150 ) ;
if ( V_23 )
return V_23 ;
}
F_232 ( V_2 ) ;
F_230 (ring, dev_priv, i) {
F_233 ( V_150 , V_263 ) ;
for ( V_264 = 0 ; V_264 < F_234 ( V_150 -> V_265 . V_266 ) ; V_264 ++ )
V_150 -> V_265 . V_266 [ V_264 ] = 0 ;
}
return 0 ;
}
int F_235 ( struct V_1 * V_2 , T_6 V_263 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( V_263 == 0 )
return - V_50 ;
V_23 = F_229 ( V_2 , V_263 - 1 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_267 = V_263 ;
V_16 -> V_268 = V_263 - 1 ;
if ( V_16 -> V_268 == 0 )
V_16 -> V_268 -- ;
return 0 ;
}
int
F_236 ( struct V_1 * V_2 , T_6 * V_263 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( V_16 -> V_267 == 0 ) {
int V_23 = F_229 ( V_2 , 0 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_267 = 1 ;
}
* V_263 = V_16 -> V_268 = V_16 -> V_267 ++ ;
return 0 ;
}
int F_237 ( struct V_153 * V_150 ,
struct V_31 * V_32 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_150 -> V_2 -> V_27 ;
struct V_148 * V_269 ;
struct V_270 * V_271 ;
T_6 V_272 ;
int V_23 ;
V_269 = V_150 -> V_151 ;
if ( F_16 ( V_269 == NULL ) )
return - V_55 ;
if ( V_118 . V_273 ) {
V_271 = V_269 -> V_274 -> V_275 [ V_150 -> V_154 ] . V_271 ;
} else
V_271 = V_150 -> V_276 ;
V_272 = F_238 ( V_271 ) ;
if ( V_118 . V_273 ) {
V_23 = F_239 ( V_271 , V_269 -> V_274 ) ;
if ( V_23 )
return V_23 ;
} else {
V_23 = F_240 ( V_150 ) ;
if ( V_23 )
return V_23 ;
}
V_269 -> V_277 = F_238 ( V_271 ) ;
if ( V_118 . V_273 ) {
V_23 = V_150 -> V_278 ( V_271 , V_269 ) ;
if ( V_23 )
return V_23 ;
} else {
V_23 = V_150 -> V_279 ( V_150 ) ;
if ( V_23 )
return V_23 ;
V_269 -> V_280 = F_238 ( V_271 ) ;
}
V_269 -> V_281 = V_272 ;
V_269 -> V_282 = V_7 ;
if ( ! V_118 . V_273 ) {
V_269 -> V_274 = V_150 -> V_283 ;
if ( V_269 -> V_274 )
F_241 ( V_269 -> V_274 ) ;
}
V_269 -> V_284 = V_166 ;
F_221 ( & V_269 -> V_285 , & V_150 -> V_286 ) ;
V_269 -> V_81 = NULL ;
if ( V_32 ) {
struct V_156 * V_81 = V_32 -> V_192 ;
F_7 ( & V_81 -> V_18 . V_287 ) ;
V_269 -> V_81 = V_81 ;
F_221 ( & V_269 -> V_288 ,
& V_81 -> V_18 . V_286 ) ;
F_8 ( & V_81 -> V_18 . V_287 ) ;
V_269 -> V_289 = F_242 ( F_243 ( V_179 ) ) ;
}
F_244 ( V_269 ) ;
V_150 -> V_151 = NULL ;
F_245 ( V_150 -> V_2 ) ;
F_246 ( & V_16 -> V_18 . V_171 ) ;
F_247 ( V_16 -> V_170 ,
& V_16 -> V_18 . V_290 ,
F_248 ( V_25 ) ) ;
F_249 ( V_16 -> V_2 ) ;
return 0 ;
}
static inline void
F_250 ( struct V_148 * V_269 )
{
struct V_156 * V_81 = V_269 -> V_81 ;
if ( ! V_81 )
return;
F_7 ( & V_81 -> V_18 . V_287 ) ;
F_210 ( & V_269 -> V_288 ) ;
V_269 -> V_81 = NULL ;
F_8 ( & V_81 -> V_18 . V_287 ) ;
}
static bool F_251 ( struct V_15 * V_16 ,
const struct V_291 * V_274 )
{
unsigned long V_292 ;
V_292 = F_252 () - V_274 -> V_293 . V_294 ;
if ( V_274 -> V_293 . V_295 )
return true ;
if ( V_274 -> V_293 . V_296 &&
V_292 <= V_274 -> V_293 . V_296 ) {
if ( ! F_253 ( V_274 ) ) {
F_200 ( L_6 ) ;
return true ;
} else if ( F_254 ( V_16 ) ) {
if ( F_255 ( V_16 ) )
F_13 ( L_7 ) ;
return true ;
}
}
return false ;
}
static void F_256 ( struct V_15 * V_16 ,
struct V_291 * V_274 ,
const bool V_297 )
{
struct V_298 * V_299 ;
if ( F_16 ( ! V_274 ) )
return;
V_299 = & V_274 -> V_293 ;
if ( V_297 ) {
V_299 -> V_295 = F_251 ( V_16 , V_274 ) ;
V_299 -> V_300 ++ ;
V_299 -> V_294 = F_252 () ;
} else {
V_299 -> V_301 ++ ;
}
}
static void F_257 ( struct V_148 * V_269 )
{
F_210 ( & V_269 -> V_285 ) ;
F_250 ( V_269 ) ;
F_258 ( V_269 -> V_289 ) ;
F_167 ( V_269 ) ;
}
void F_259 ( struct V_302 * V_303 )
{
struct V_148 * V_149 = F_260 ( V_303 ,
F_261 ( * V_149 ) , V_304 ) ;
struct V_291 * V_274 = V_149 -> V_274 ;
if ( V_274 ) {
if ( V_118 . V_273 ) {
struct V_153 * V_150 = V_149 -> V_150 ;
if ( V_274 != V_150 -> V_305 )
F_262 ( V_150 , V_274 ) ;
}
F_263 ( V_274 ) ;
}
F_37 ( V_149 ) ;
}
struct V_148 *
F_264 ( struct V_153 * V_150 )
{
struct V_148 * V_269 ;
F_20 (request, &ring->request_list, list) {
if ( F_145 ( V_269 , false ) )
continue;
return V_269 ;
}
return NULL ;
}
static void F_265 ( struct V_15 * V_16 ,
struct V_153 * V_150 )
{
struct V_148 * V_269 ;
bool V_306 ;
V_269 = F_264 ( V_150 ) ;
if ( V_269 == NULL )
return;
V_306 = V_150 -> V_307 . V_308 >= V_309 ;
F_256 ( V_16 , V_269 -> V_274 , V_306 ) ;
F_266 (request, &ring->request_list, list)
F_256 ( V_16 , V_269 -> V_274 , false ) ;
}
static void F_267 ( struct V_15 * V_16 ,
struct V_153 * V_150 )
{
while ( ! F_227 ( & V_150 -> V_258 ) ) {
struct V_6 * V_7 ;
V_7 = F_268 ( & V_150 -> V_258 ,
struct V_6 ,
V_257 ) ;
F_226 ( V_7 ) ;
}
while ( ! F_227 ( & V_150 -> V_310 ) ) {
struct V_148 * V_311 ;
V_311 = F_268 ( & V_150 -> V_310 ,
struct V_148 ,
V_312 ) ;
F_210 ( & V_311 -> V_312 ) ;
F_125 ( V_16 ) ;
if ( V_311 -> V_274 != V_150 -> V_305 )
F_262 ( V_150 , V_311 -> V_274 ) ;
F_167 ( V_311 ) ;
}
while ( ! F_227 ( & V_150 -> V_286 ) ) {
struct V_148 * V_269 ;
V_269 = F_268 ( & V_150 -> V_286 ,
struct V_148 ,
V_285 ) ;
F_257 ( V_269 ) ;
}
F_169 ( & V_150 -> V_151 , NULL ) ;
}
void F_269 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_16 -> V_313 ; V_49 ++ ) {
struct V_314 * V_315 = & V_16 -> V_316 [ V_49 ] ;
if ( V_315 -> V_7 ) {
F_270 ( V_315 -> V_7 , V_315 ,
V_315 -> V_7 -> V_11 ) ;
} else {
F_271 ( V_2 , V_49 , NULL ) ;
}
}
}
void F_272 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_153 * V_150 ;
int V_49 ;
F_230 (ring, dev_priv, i)
F_265 ( V_16 , V_150 ) ;
F_230 (ring, dev_priv, i)
F_267 ( V_16 , V_150 ) ;
F_273 ( V_2 ) ;
F_269 ( V_2 ) ;
}
void
F_274 ( struct V_153 * V_150 )
{
if ( F_227 ( & V_150 -> V_286 ) )
return;
F_16 ( F_17 ( V_150 -> V_2 ) ) ;
while ( ! F_227 ( & V_150 -> V_286 ) ) {
struct V_148 * V_269 ;
V_269 = F_268 ( & V_150 -> V_286 ,
struct V_148 ,
V_285 ) ;
if ( ! F_145 ( V_269 , true ) )
break;
F_275 ( V_269 ) ;
V_269 -> V_271 -> V_317 = V_269 -> V_277 ;
F_257 ( V_269 ) ;
}
while ( ! F_227 ( & V_150 -> V_258 ) ) {
struct V_6 * V_7 ;
V_7 = F_268 ( & V_150 -> V_258 ,
struct V_6 ,
V_257 ) ;
if ( ! F_145 ( V_7 -> V_189 , true ) )
break;
F_226 ( V_7 ) ;
}
if ( F_86 ( V_150 -> V_318 &&
F_145 ( V_150 -> V_318 , true ) ) ) {
V_150 -> V_184 ( V_150 ) ;
F_169 ( & V_150 -> V_318 , NULL ) ;
}
F_16 ( F_17 ( V_150 -> V_2 ) ) ;
}
bool
F_232 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_153 * V_150 ;
bool V_319 = true ;
int V_49 ;
F_230 (ring, dev_priv, i) {
F_274 ( V_150 ) ;
V_319 &= F_227 ( & V_150 -> V_286 ) ;
if ( V_118 . V_273 ) {
unsigned long V_198 ;
F_276 ( & V_150 -> V_320 , V_198 ) ;
V_319 &= F_227 ( & V_150 -> V_310 ) ;
F_277 ( & V_150 -> V_320 , V_198 ) ;
F_278 ( V_150 ) ;
}
}
if ( V_319 )
F_149 ( V_16 -> V_170 ,
& V_16 -> V_18 . V_171 ,
F_150 ( 100 ) ) ;
return V_319 ;
}
static void
F_279 ( struct V_321 * V_322 )
{
struct V_15 * V_16 =
F_260 ( V_322 , F_261 ( * V_16 ) , V_18 . V_290 . V_322 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_319 ;
V_319 = false ;
if ( F_280 ( & V_2 -> V_29 ) ) {
V_319 = F_232 ( V_2 ) ;
F_23 ( & V_2 -> V_29 ) ;
}
if ( ! V_319 )
F_247 ( V_16 -> V_170 , & V_16 -> V_18 . V_290 ,
F_248 ( V_25 ) ) ;
}
static void
F_281 ( struct V_321 * V_322 )
{
struct V_15 * V_16 =
F_260 ( V_322 , F_261 ( * V_16 ) , V_18 . V_171 . V_322 ) ;
F_282 ( V_16 -> V_2 ) ;
}
static int
F_283 ( struct V_6 * V_7 )
{
struct V_153 * V_150 ;
int V_23 ;
if ( V_7 -> V_186 ) {
V_150 = F_139 ( V_7 -> V_189 ) ;
V_23 = F_129 ( V_7 -> V_189 ) ;
if ( V_23 )
return V_23 ;
F_274 ( V_150 ) ;
}
return 0 ;
}
int
F_284 ( struct V_1 * V_2 , void * V_30 , struct V_31 * V_32 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_323 * args = V_30 ;
struct V_6 * V_7 ;
struct V_148 * V_149 ;
unsigned V_158 ;
int V_23 = 0 ;
if ( args -> V_198 != 0 )
return - V_50 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_32 , args -> V_324 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_23 ( & V_2 -> V_29 ) ;
return - V_121 ;
}
V_23 = F_283 ( V_7 ) ;
if ( V_23 )
goto V_86;
if ( ! V_7 -> V_186 || ! V_7 -> V_189 )
goto V_86;
V_149 = V_7 -> V_189 ;
if ( args -> V_325 == 0 ) {
V_23 = - V_181 ;
goto V_86;
}
F_53 ( & V_7 -> V_8 ) ;
V_158 = F_154 ( & V_16 -> V_28 . V_158 ) ;
F_166 ( V_149 ) ;
F_23 ( & V_2 -> V_29 ) ;
V_23 = F_138 ( V_149 , V_158 , true ,
args -> V_325 > 0 ? & args -> V_325 : NULL ,
V_32 -> V_192 ) ;
F_19 ( & V_2 -> V_29 ) ;
F_167 ( V_149 ) ;
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
V_86:
F_53 ( & V_7 -> V_8 ) ;
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_285 ( struct V_6 * V_7 ,
struct V_153 * V_326 )
{
struct V_153 * V_327 ;
T_6 V_263 ;
int V_23 , V_328 ;
V_327 = F_139 ( V_7 -> V_189 ) ;
if ( V_327 == NULL || V_326 == V_327 )
return 0 ;
if ( V_326 == NULL || ! F_286 ( V_7 -> V_8 . V_2 ) )
return F_59 ( V_7 , false ) ;
V_328 = F_287 ( V_327 , V_326 ) ;
V_263 = F_288 ( V_7 -> V_189 ) ;
if ( V_263 <= V_327 -> V_265 . V_266 [ V_328 ] )
return 0 ;
V_23 = F_129 ( V_7 -> V_189 ) ;
if ( V_23 )
return V_23 ;
F_289 ( V_327 , V_326 , V_7 -> V_189 ) ;
V_23 = V_326 -> V_265 . V_329 ( V_326 , V_327 , V_263 ) ;
if ( ! V_23 )
V_327 -> V_265 . V_266 [ V_328 ] =
F_288 ( V_7 -> V_189 ) ;
return V_23 ;
}
static void F_290 ( struct V_6 * V_7 )
{
T_6 V_330 , V_331 ;
F_5 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_64 & V_194 ) == 0 )
return;
F_291 () ;
V_331 = V_7 -> V_8 . V_64 ;
V_330 = V_7 -> V_8 . V_65 ;
V_7 -> V_8 . V_64 &= ~ V_194 ;
V_7 -> V_8 . V_65 &= ~ V_194 ;
F_292 ( V_7 ,
V_331 ,
V_330 ) ;
}
int F_51 ( struct V_71 * V_72 )
{
struct V_6 * V_7 = V_72 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_227 ( & V_72 -> V_332 ) )
return 0 ;
if ( ! F_293 ( & V_72 -> V_333 ) ) {
F_294 ( V_72 ) ;
return 0 ;
}
if ( V_72 -> V_334 )
return - V_76 ;
F_41 ( V_7 -> V_60 == NULL ) ;
V_23 = F_295 ( V_7 ) ;
if ( V_23 )
return V_23 ;
if ( F_296 ( V_72 -> V_260 ) &&
V_72 -> V_335 . type == V_336 ) {
F_290 ( V_7 ) ;
V_23 = F_113 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
F_297 ( V_72 ) ;
V_72 -> V_337 ( V_72 ) ;
F_228 ( & V_72 -> V_259 ) ;
if ( F_296 ( V_72 -> V_260 ) ) {
if ( V_72 -> V_335 . type == V_336 ) {
V_7 -> V_338 = false ;
} else if ( V_72 -> V_335 . V_60 ) {
F_45 ( V_72 -> V_335 . V_60 ) ;
F_37 ( V_72 -> V_335 . V_60 ) ;
}
V_72 -> V_335 . V_60 = NULL ;
}
F_298 ( & V_72 -> V_333 ) ;
F_294 ( V_72 ) ;
if ( F_227 ( & V_7 -> V_339 ) ) {
F_83 ( V_7 ) ;
F_299 ( V_7 ) ;
F_224 ( & V_7 -> V_239 , & V_16 -> V_18 . V_255 ) ;
}
F_101 ( V_7 ) ;
return 0 ;
}
int F_300 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_153 * V_150 ;
int V_23 , V_49 ;
F_230 (ring, dev_priv, i) {
if ( ! V_118 . V_273 ) {
V_23 = F_301 ( V_150 , V_150 -> V_305 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_231 ( V_150 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static void F_302 ( struct V_1 * V_2 , int V_315 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_13 ;
int V_340 ;
if ( F_147 ( V_2 ) -> V_168 >= 6 ) {
V_13 = V_341 ;
V_340 = V_342 ;
} else {
V_13 = V_343 ;
V_340 = V_344 ;
}
V_13 += V_315 * 8 ;
F_303 ( V_13 , 0 ) ;
F_304 ( V_13 ) ;
if ( V_7 ) {
T_6 V_17 = F_22 ( V_7 ) ;
T_4 V_345 ;
if ( V_7 -> V_11 != V_143 ) {
T_5 V_346 = V_7 -> V_347 *
( V_7 -> V_11 == V_348 ? 32 : 8 ) ;
V_17 = ( V_17 / V_346 ) * V_346 ;
}
V_345 = ( T_4 ) ( ( F_114 ( V_7 ) + V_17 - 4096 ) &
0xfffff000 ) << 32 ;
V_345 |= F_114 ( V_7 ) & 0xfffff000 ;
V_345 |= ( T_4 ) ( ( V_7 -> V_347 / 128 ) - 1 ) << V_340 ;
if ( V_7 -> V_11 == V_348 )
V_345 |= 1 << V_349 ;
V_345 |= V_350 ;
F_303 ( V_13 + 4 , V_345 >> 32 ) ;
F_304 ( V_13 + 4 ) ;
F_303 ( V_13 + 0 , V_345 ) ;
F_304 ( V_13 ) ;
} else {
F_303 ( V_13 + 4 , 0 ) ;
F_304 ( V_13 + 4 ) ;
}
}
static void F_305 ( struct V_1 * V_2 , int V_315 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_345 ;
if ( V_7 ) {
T_6 V_17 = F_22 ( V_7 ) ;
int V_351 ;
int V_352 ;
F_143 ( ( F_114 ( V_7 ) & ~ V_353 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_114 ( V_7 ) & ( V_17 - 1 ) ) ,
L_8 ,
F_114 ( V_7 ) , V_7 -> V_338 , V_17 ) ;
if ( V_7 -> V_11 == V_348 && F_306 ( V_2 ) )
V_352 = 128 ;
else
V_352 = 512 ;
V_351 = V_7 -> V_347 / V_352 ;
V_351 = F_307 ( V_351 ) - 1 ;
V_345 = F_114 ( V_7 ) ;
if ( V_7 -> V_11 == V_348 )
V_345 |= 1 << V_354 ;
V_345 |= F_308 ( V_17 ) ;
V_345 |= V_351 << V_355 ;
V_345 |= V_356 ;
} else
V_345 = 0 ;
if ( V_315 < 8 )
V_315 = V_357 + V_315 * 4 ;
else
V_315 = V_358 + ( V_315 - 8 ) * 4 ;
F_303 ( V_315 , V_345 ) ;
F_304 ( V_315 ) ;
}
static void F_309 ( struct V_1 * V_2 , int V_315 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_5 V_345 ;
if ( V_7 ) {
T_6 V_17 = F_22 ( V_7 ) ;
T_5 V_351 ;
F_143 ( ( F_114 ( V_7 ) & ~ V_359 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_114 ( V_7 ) & ( V_17 - 1 ) ) ,
L_9 ,
F_114 ( V_7 ) , V_17 ) ;
V_351 = V_7 -> V_347 / 128 ;
V_351 = F_307 ( V_351 ) - 1 ;
V_345 = F_114 ( V_7 ) ;
if ( V_7 -> V_11 == V_348 )
V_345 |= 1 << V_354 ;
V_345 |= F_310 ( V_17 ) ;
V_345 |= V_351 << V_355 ;
V_345 |= V_356 ;
} else
V_345 = 0 ;
F_303 ( V_357 + V_315 * 4 , V_345 ) ;
F_304 ( V_357 + V_315 * 4 ) ;
}
inline static bool F_311 ( struct V_6 * V_7 )
{
return V_7 && V_7 -> V_8 . V_64 & V_194 ;
}
static void F_271 ( struct V_1 * V_2 , int V_315 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_311 ( V_16 -> V_316 [ V_315 ] . V_7 ) )
F_291 () ;
F_143 ( V_7 && ( ! V_7 -> V_347 || ! V_7 -> V_11 ) ,
L_10 ,
V_7 -> V_347 , V_7 -> V_11 ) ;
if ( F_312 ( V_2 ) )
F_309 ( V_2 , V_315 , V_7 ) ;
else if ( F_313 ( V_2 ) )
F_305 ( V_2 , V_315 , V_7 ) ;
else if ( F_147 ( V_2 ) -> V_168 >= 4 )
F_302 ( V_2 , V_315 , V_7 ) ;
if ( F_311 ( V_7 ) )
F_291 () ;
}
static inline int F_314 ( struct V_15 * V_16 ,
struct V_314 * V_360 )
{
return V_360 - V_16 -> V_316 ;
}
static void F_270 ( struct V_6 * V_7 ,
struct V_314 * V_360 ,
bool V_361 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_315 = F_314 ( V_16 , V_360 ) ;
F_271 ( V_7 -> V_8 . V_2 , V_315 , V_361 ? V_7 : NULL ) ;
if ( V_361 ) {
V_7 -> V_13 = V_315 ;
V_360 -> V_7 = V_7 ;
F_224 ( & V_360 -> V_362 , & V_16 -> V_18 . V_363 ) ;
} else {
V_7 -> V_13 = V_14 ;
V_360 -> V_7 = NULL ;
F_228 ( & V_360 -> V_362 ) ;
}
V_7 -> V_12 = false ;
}
static int
F_315 ( struct V_6 * V_7 )
{
if ( V_7 -> V_262 ) {
int V_23 = F_165 ( V_7 -> V_262 ) ;
if ( V_23 )
return V_23 ;
F_169 ( & V_7 -> V_262 , NULL ) ;
}
return 0 ;
}
int
F_113 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_314 * V_360 ;
int V_23 ;
V_23 = F_315 ( V_7 ) ;
if ( V_23 )
return V_23 ;
if ( V_7 -> V_13 == V_14 )
return 0 ;
V_360 = & V_16 -> V_316 [ V_7 -> V_13 ] ;
if ( F_16 ( V_360 -> V_334 ) )
return - V_76 ;
F_4 ( V_7 ) ;
F_270 ( V_7 , V_360 , false ) ;
return 0 ;
}
static struct V_314 *
F_316 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_314 * V_315 , * V_364 ;
int V_49 ;
V_364 = NULL ;
for ( V_49 = V_16 -> V_365 ; V_49 < V_16 -> V_313 ; V_49 ++ ) {
V_315 = & V_16 -> V_316 [ V_49 ] ;
if ( ! V_315 -> V_7 )
return V_315 ;
if ( ! V_315 -> V_334 )
V_364 = V_315 ;
}
if ( V_364 == NULL )
goto V_366;
F_20 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_315 -> V_334 )
continue;
return V_315 ;
}
V_366:
if ( F_317 ( V_2 ) )
return F_318 ( - V_147 ) ;
return F_318 ( - V_367 ) ;
}
int
F_183 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_361 = V_7 -> V_11 != V_143 ;
struct V_314 * V_315 ;
int V_23 ;
if ( V_7 -> V_12 ) {
V_23 = F_315 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_7 -> V_13 != V_14 ) {
V_315 = & V_16 -> V_316 [ V_7 -> V_13 ] ;
if ( ! V_7 -> V_12 ) {
F_224 ( & V_315 -> V_362 ,
& V_16 -> V_18 . V_363 ) ;
return 0 ;
}
} else if ( V_361 ) {
if ( F_16 ( ! V_7 -> V_338 ) )
return - V_50 ;
V_315 = F_316 ( V_2 ) ;
if ( F_28 ( V_315 ) )
return F_29 ( V_315 ) ;
if ( V_315 -> V_7 ) {
struct V_6 * V_368 = V_315 -> V_7 ;
V_23 = F_315 ( V_368 ) ;
if ( V_23 )
return V_23 ;
F_4 ( V_368 ) ;
}
} else
return 0 ;
F_270 ( V_7 , V_315 , V_361 ) ;
return 0 ;
}
static bool F_319 ( struct V_71 * V_72 ,
unsigned long V_9 )
{
struct V_369 * V_370 = & V_72 -> V_333 ;
struct V_369 * V_371 ;
if ( V_72 -> V_260 -> V_18 . V_372 == NULL )
return true ;
if ( ! F_293 ( V_370 ) )
return true ;
if ( F_227 ( & V_370 -> V_373 ) )
return true ;
V_371 = F_320 ( V_370 -> V_373 . V_374 , struct V_369 , V_373 ) ;
if ( V_371 -> V_375 && ! V_371 -> V_376 && V_371 -> V_377 != V_9 )
return false ;
V_371 = F_320 ( V_370 -> V_373 . V_73 , struct V_369 , V_373 ) ;
if ( V_371 -> V_375 && ! V_370 -> V_376 && V_371 -> V_377 != V_9 )
return false ;
return true ;
}
static struct V_71 *
F_321 ( struct V_6 * V_7 ,
struct V_378 * V_260 ,
const struct V_379 * V_335 ,
unsigned V_380 ,
T_4 V_198 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_17 , V_381 , V_382 , V_383 ;
unsigned long V_109 =
V_198 & V_384 ? V_198 & V_385 : 0 ;
unsigned long V_110 =
V_198 & V_128 ? V_16 -> V_36 . V_234 : V_260 -> V_37 ;
struct V_71 * V_72 ;
int V_23 ;
if( F_16 ( F_296 ( V_260 ) != ! ! V_335 ) )
return F_318 ( - V_50 ) ;
V_381 = F_189 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ) ;
V_382 = F_190 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , true ) ;
V_383 =
F_190 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , false ) ;
if ( V_380 == 0 )
V_380 = V_198 & V_128 ? V_382 :
V_383 ;
if ( V_198 & V_128 && V_380 & ( V_382 - 1 ) ) {
F_200 ( L_11 , V_380 ) ;
return F_318 ( - V_50 ) ;
}
V_17 = V_198 & V_128 ? V_381 : V_7 -> V_8 . V_17 ;
if ( V_7 -> V_8 . V_17 > V_110 ) {
F_200 ( L_12 ,
V_7 -> V_8 . V_17 ,
V_198 & V_128 ? L_13 : L_14 ,
V_110 ) ;
return F_318 ( - V_235 ) ;
}
V_23 = F_56 ( V_7 ) ;
if ( V_23 )
return F_318 ( V_23 ) ;
F_84 ( V_7 ) ;
V_72 = V_335 ? F_322 ( V_7 , V_335 ) :
F_323 ( V_7 , V_260 ) ;
if ( F_28 ( V_72 ) )
goto V_386;
V_387:
V_23 = F_324 ( & V_260 -> V_18 , & V_72 -> V_333 ,
V_17 , V_380 ,
V_7 -> V_9 ,
V_109 , V_110 ,
V_388 ,
V_389 ) ;
if ( V_23 ) {
V_23 = F_325 ( V_2 , V_260 , V_17 , V_380 ,
V_7 -> V_9 ,
V_109 , V_110 ,
V_198 ) ;
if ( V_23 == 0 )
goto V_387;
goto V_390;
}
if ( F_16 ( ! F_319 ( V_72 , V_7 -> V_9 ) ) ) {
V_23 = - V_50 ;
goto V_391;
}
V_23 = F_326 ( V_7 ) ;
if ( V_23 )
goto V_391;
if ( V_72 -> V_260 -> V_392 ) {
F_327 ( V_72 -> V_260 , V_72 -> V_333 . V_109 , V_72 -> V_333 . V_17 ,
F_328 ( V_72 -> V_260 ) ) ;
V_23 = V_72 -> V_260 -> V_392 ( V_72 -> V_260 ,
V_72 -> V_333 . V_109 ,
V_72 -> V_333 . V_17 ) ;
if ( V_23 )
goto V_391;
}
F_329 ( V_72 , V_198 ) ;
V_23 = F_330 ( V_72 , V_7 -> V_9 ,
V_198 & V_393 ? V_394 : 0 ) ;
if ( V_23 )
goto V_395;
F_224 ( & V_7 -> V_239 , & V_16 -> V_18 . V_396 ) ;
F_221 ( & V_72 -> V_259 , & V_260 -> V_261 ) ;
return V_72 ;
V_395:
F_299 ( V_7 ) ;
V_391:
F_298 ( & V_72 -> V_333 ) ;
V_390:
F_294 ( V_72 ) ;
V_72 = F_318 ( V_23 ) ;
V_386:
F_101 ( V_7 ) ;
return V_72 ;
}
bool
F_120 ( struct V_6 * V_7 ,
bool V_397 )
{
if ( V_7 -> V_60 == NULL )
return false ;
if ( V_7 -> V_398 || V_7 -> V_44 )
return false ;
if ( ! V_397 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) ) {
V_7 -> V_399 = true ;
return false ;
}
F_331 ( V_7 ) ;
F_332 ( V_7 -> V_60 ) ;
V_7 -> V_399 = false ;
return true ;
}
static void
F_333 ( struct V_6 * V_7 )
{
T_5 V_330 ;
if ( V_7 -> V_8 . V_65 != V_194 )
return;
F_334 () ;
V_330 = V_7 -> V_8 . V_65 ;
V_7 -> V_8 . V_65 = 0 ;
F_63 ( V_7 , false ) ;
F_292 ( V_7 ,
V_7 -> V_8 . V_64 ,
V_330 ) ;
}
static void
F_173 ( struct V_6 * V_7 )
{
T_5 V_330 ;
if ( V_7 -> V_8 . V_65 != V_66 )
return;
if ( F_120 ( V_7 , V_7 -> V_10 ) )
F_34 ( V_7 -> V_8 . V_2 ) ;
V_330 = V_7 -> V_8 . V_65 ;
V_7 -> V_8 . V_65 = 0 ;
F_63 ( V_7 , false ) ;
F_292 ( V_7 ,
V_7 -> V_8 . V_64 ,
V_330 ) ;
}
int
F_112 ( struct V_6 * V_7 , bool V_214 )
{
T_5 V_330 , V_331 ;
struct V_71 * V_72 ;
int V_23 ;
if ( V_7 -> V_8 . V_65 == V_194 )
return 0 ;
V_23 = F_59 ( V_7 , ! V_214 ) ;
if ( V_23 )
return V_23 ;
F_83 ( V_7 ) ;
V_23 = F_56 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_173 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_64 & V_194 ) == 0 )
F_291 () ;
V_330 = V_7 -> V_8 . V_65 ;
V_331 = V_7 -> V_8 . V_64 ;
F_41 ( ( V_7 -> V_8 . V_65 & ~ V_194 ) != 0 ) ;
V_7 -> V_8 . V_64 |= V_194 ;
if ( V_214 ) {
V_7 -> V_8 . V_64 = V_194 ;
V_7 -> V_8 . V_65 = V_194 ;
V_7 -> V_68 = 1 ;
}
if ( V_214 )
F_60 ( V_7 , NULL , V_131 ) ;
F_292 ( V_7 ,
V_331 ,
V_330 ) ;
V_72 = F_335 ( V_7 ) ;
if ( V_72 && F_293 ( & V_72 -> V_333 ) && ! V_7 -> V_186 )
F_224 ( & V_72 -> V_259 ,
& F_336 ( V_7 -> V_8 . V_2 ) -> V_36 . V_8 . V_261 ) ;
return 0 ;
}
int F_337 ( struct V_6 * V_7 ,
enum V_3 V_9 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_71 * V_72 , * V_73 ;
int V_23 ;
if ( V_7 -> V_9 == V_9 )
return 0 ;
if ( F_21 ( V_7 ) ) {
F_200 ( L_15 ) ;
return - V_76 ;
}
F_50 (vma, next, &obj->vma_list, vma_link) {
if ( ! F_319 ( V_72 , V_9 ) ) {
V_23 = F_51 ( V_72 ) ;
if ( V_23 )
return V_23 ;
}
}
if ( F_209 ( V_7 ) ) {
V_23 = F_295 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_290 ( V_7 ) ;
if ( F_147 ( V_2 ) -> V_168 < 6 ) {
V_23 = F_113 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
F_20 (vma, &obj->vma_list, vma_link)
if ( F_293 ( & V_72 -> V_333 ) ) {
V_23 = F_330 ( V_72 , V_9 ,
V_72 -> V_400 & V_394 ) ;
if ( V_23 )
return V_23 ;
}
}
F_20 (vma, &obj->vma_list, vma_link)
V_72 -> V_333 . V_377 = V_9 ;
V_7 -> V_9 = V_9 ;
if ( V_7 -> V_399 &&
V_7 -> V_8 . V_65 != V_66 &&
F_3 ( V_7 ) ) {
if ( F_120 ( V_7 , true ) )
F_34 ( V_7 -> V_8 . V_2 ) ;
}
return 0 ;
}
int F_338 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_401 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_32 , args -> V_89 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
switch ( V_7 -> V_9 ) {
case V_402 :
case V_403 :
args -> V_404 = V_405 ;
break;
case V_406 :
args -> V_404 = V_407 ;
break;
default:
args -> V_404 = V_408 ;
break;
}
F_53 ( & V_7 -> V_8 ) ;
V_122:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_339 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_401 * args = V_30 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_23 ;
switch ( args -> V_404 ) {
case V_408 :
V_4 = V_5 ;
break;
case V_405 :
V_4 = V_402 ;
break;
case V_407 :
V_4 = F_340 ( V_2 ) ? V_406 : V_5 ;
break;
default:
return - V_50 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_32 , args -> V_89 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
V_23 = F_337 ( V_7 , V_4 ) ;
F_53 ( & V_7 -> V_8 ) ;
V_122:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static bool F_341 ( struct V_6 * V_7 )
{
struct V_71 * V_72 ;
V_72 = F_335 ( V_7 ) ;
if ( ! V_72 )
return false ;
return V_72 -> V_334 ;
}
int
F_342 ( struct V_6 * V_7 ,
T_6 V_380 ,
struct V_153 * V_409 ,
const struct V_379 * V_410 )
{
T_6 V_331 , V_330 ;
bool V_411 ;
int V_23 ;
if ( V_409 != F_139 ( V_7 -> V_189 ) ) {
V_23 = F_285 ( V_7 , V_409 ) ;
if ( V_23 )
return V_23 ;
}
V_411 = V_7 -> V_10 ;
V_7 -> V_10 = true ;
V_23 = F_337 ( V_7 ,
F_340 ( V_7 -> V_8 . V_2 ) ? V_406 : V_5 ) ;
if ( V_23 )
goto V_412;
V_23 = F_343 ( V_7 , V_410 , V_380 ,
V_410 -> type == V_336 ?
V_128 : 0 ) ;
if ( V_23 )
goto V_412;
F_173 ( V_7 ) ;
V_330 = V_7 -> V_8 . V_65 ;
V_331 = V_7 -> V_8 . V_64 ;
V_7 -> V_8 . V_65 = 0 ;
V_7 -> V_8 . V_64 |= V_194 ;
F_292 ( V_7 ,
V_331 ,
V_330 ) ;
return 0 ;
V_412:
F_16 ( V_411 != F_341 ( V_7 ) ) ;
V_7 -> V_10 = V_411 ;
return V_23 ;
}
void
F_344 ( struct V_6 * V_7 ,
const struct V_379 * V_410 )
{
F_345 ( V_7 , V_410 ) ;
V_7 -> V_10 = F_341 ( V_7 ) ;
}
int
F_295 ( struct V_6 * V_7 )
{
int V_23 ;
if ( ( V_7 -> V_8 . V_64 & V_191 ) == 0 )
return 0 ;
V_23 = F_59 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_8 . V_64 &= ~ V_191 ;
return 0 ;
}
int
F_42 ( struct V_6 * V_7 , bool V_214 )
{
T_5 V_330 , V_331 ;
int V_23 ;
if ( V_7 -> V_8 . V_65 == V_66 )
return 0 ;
V_23 = F_59 ( V_7 , ! V_214 ) ;
if ( V_23 )
return V_23 ;
F_83 ( V_7 ) ;
F_333 ( V_7 ) ;
V_330 = V_7 -> V_8 . V_65 ;
V_331 = V_7 -> V_8 . V_64 ;
if ( ( V_7 -> V_8 . V_64 & V_66 ) == 0 ) {
F_120 ( V_7 , false ) ;
V_7 -> V_8 . V_64 |= V_66 ;
}
F_41 ( ( V_7 -> V_8 . V_65 & ~ V_66 ) != 0 ) ;
if ( V_214 ) {
V_7 -> V_8 . V_64 = V_66 ;
V_7 -> V_8 . V_65 = V_66 ;
}
if ( V_214 )
F_60 ( V_7 , NULL , V_84 ) ;
F_292 ( V_7 ,
V_331 ,
V_330 ) ;
return 0 ;
}
static int
F_346 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_156 * V_81 = V_32 -> V_192 ;
unsigned long V_413 = V_166 - F_150 ( 20 ) ;
struct V_148 * V_269 , * V_414 = NULL ;
unsigned V_158 ;
int V_23 ;
V_23 = F_10 ( & V_16 -> V_28 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_126 ( & V_16 -> V_28 , false ) ;
if ( V_23 )
return V_23 ;
F_7 ( & V_81 -> V_18 . V_287 ) ;
F_20 (request, &file_priv->mm.request_list, client_list) {
if ( F_156 ( V_269 -> V_284 , V_413 ) )
break;
V_414 = V_269 ;
}
V_158 = F_154 ( & V_16 -> V_28 . V_158 ) ;
if ( V_414 )
F_166 ( V_414 ) ;
F_8 ( & V_81 -> V_18 . V_287 ) ;
if ( V_414 == NULL )
return 0 ;
V_23 = F_138 ( V_414 , V_158 , true , NULL , NULL ) ;
if ( V_23 == 0 )
F_247 ( V_16 -> V_170 , & V_16 -> V_18 . V_290 , 0 ) ;
F_19 ( & V_2 -> V_29 ) ;
F_167 ( V_414 ) ;
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static bool
F_347 ( struct V_71 * V_72 , T_5 V_380 , T_4 V_198 )
{
struct V_6 * V_7 = V_72 -> V_7 ;
if ( V_380 &&
V_72 -> V_333 . V_109 & ( V_380 - 1 ) )
return true ;
if ( V_198 & V_128 && ! V_7 -> V_338 )
return true ;
if ( V_198 & V_384 &&
V_72 -> V_333 . V_109 < ( V_198 & V_385 ) )
return true ;
return false ;
}
static int
F_348 ( struct V_6 * V_7 ,
struct V_378 * V_260 ,
const struct V_379 * V_335 ,
T_5 V_380 ,
T_4 V_198 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_71 * V_72 ;
unsigned V_400 ;
int V_23 ;
if ( F_16 ( V_260 == & V_16 -> V_18 . V_415 -> V_8 ) )
return - V_173 ;
if ( F_16 ( V_198 & ( V_393 | V_128 ) && ! F_296 ( V_260 ) ) )
return - V_50 ;
if ( F_16 ( ( V_198 & ( V_128 | V_393 ) ) == V_128 ) )
return - V_50 ;
if ( F_16 ( F_296 ( V_260 ) != ! ! V_335 ) )
return - V_50 ;
V_72 = V_335 ? F_349 ( V_7 , V_335 ) :
F_350 ( V_7 , V_260 ) ;
if ( F_28 ( V_72 ) )
return F_29 ( V_72 ) ;
if ( V_72 ) {
if ( F_16 ( V_72 -> V_334 == V_416 ) )
return - V_76 ;
if ( F_347 ( V_72 , V_380 , V_198 ) ) {
unsigned long V_57 ;
V_57 = V_335 ? F_351 ( V_7 , V_335 ) :
F_352 ( V_7 , V_260 ) ;
F_143 ( V_72 -> V_334 ,
L_16
L_17
L_18 ,
V_335 ? L_19 : L_20 ,
V_57 ,
V_380 ,
! ! ( V_198 & V_128 ) ,
V_7 -> V_338 ) ;
V_23 = F_51 ( V_72 ) ;
if ( V_23 )
return V_23 ;
V_72 = NULL ;
}
}
V_400 = V_72 ? V_72 -> V_400 : 0 ;
if ( V_72 == NULL || ! F_293 ( & V_72 -> V_333 ) ) {
V_72 = F_321 ( V_7 , V_260 , V_335 , V_380 ,
V_198 ) ;
if ( F_28 ( V_72 ) )
return F_29 ( V_72 ) ;
}
if ( V_198 & V_393 && ! ( V_72 -> V_400 & V_394 ) ) {
V_23 = F_330 ( V_72 , V_7 -> V_9 , V_394 ) ;
if ( V_23 )
return V_23 ;
}
if ( ( V_400 ^ V_72 -> V_400 ) & V_394 ) {
bool V_133 , V_417 ;
T_6 V_381 , V_382 ;
V_381 = F_189 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ) ;
V_382 = F_190 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ,
true ) ;
V_417 = ( V_72 -> V_333 . V_17 == V_381 &&
( V_72 -> V_333 . V_109 & ( V_382 - 1 ) ) == 0 ) ;
V_133 = ( V_72 -> V_333 . V_109 + V_381 <=
V_16 -> V_36 . V_234 ) ;
V_7 -> V_338 = V_133 && V_417 ;
}
F_16 ( V_198 & V_128 && ! V_7 -> V_338 ) ;
V_72 -> V_334 ++ ;
if ( V_198 & V_128 )
V_7 -> V_418 |= true ;
return 0 ;
}
int
F_353 ( struct V_6 * V_7 ,
struct V_378 * V_260 ,
T_5 V_380 ,
T_4 V_198 )
{
return F_348 ( V_7 , V_260 ,
F_296 ( V_260 ) ? & V_419 : NULL ,
V_380 , V_198 ) ;
}
int
F_343 ( struct V_6 * V_7 ,
const struct V_379 * V_410 ,
T_5 V_380 ,
T_4 V_198 )
{
if ( F_186 ( ! V_410 , L_21 ) )
return - V_50 ;
return F_348 ( V_7 , F_354 ( V_7 ) , V_410 ,
V_380 , V_198 | V_393 ) ;
}
void
F_345 ( struct V_6 * V_7 ,
const struct V_379 * V_410 )
{
struct V_71 * V_72 = F_349 ( V_7 , V_410 ) ;
F_41 ( ! V_72 ) ;
F_16 ( V_72 -> V_334 == 0 ) ;
F_16 ( ! F_355 ( V_7 , V_410 ) ) ;
if ( -- V_72 -> V_334 == 0 && V_410 -> type == V_336 )
V_7 -> V_418 = false ;
}
bool
F_356 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 != V_14 ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_71 * V_420 = F_335 ( V_7 ) ;
F_16 ( ! V_420 ||
V_16 -> V_316 [ V_7 -> V_13 ] . V_334 >
V_420 -> V_334 ) ;
V_16 -> V_316 [ V_7 -> V_13 ] . V_334 ++ ;
return true ;
} else
return false ;
}
void
F_357 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 != V_14 ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
F_16 ( V_16 -> V_316 [ V_7 -> V_13 ] . V_334 <= 0 ) ;
V_16 -> V_316 [ V_7 -> V_13 ] . V_334 -- ;
}
}
int
F_358 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_421 * args = V_30 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_32 , args -> V_89 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
V_23 = F_283 ( V_7 ) ;
args -> V_422 = V_7 -> V_186 ;
if ( V_7 -> V_189 ) {
struct V_153 * V_150 ;
F_359 ( V_423 > 16 ) ;
V_150 = F_139 ( V_7 -> V_189 ) ;
args -> V_422 |= F_141 ( V_150 ) << 16 ;
}
F_53 ( & V_7 -> V_8 ) ;
V_122:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_360 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_81 )
{
return F_346 ( V_2 , V_81 ) ;
}
int
F_361 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_81 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_424 * args = V_30 ;
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
V_7 = F_104 ( F_105 ( V_2 , V_81 , args -> V_89 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
if ( F_21 ( V_7 ) ) {
V_23 = - V_50 ;
goto V_86;
}
if ( V_7 -> V_60 &&
V_7 -> V_11 != V_143 &&
V_16 -> V_252 & V_253 ) {
if ( V_7 -> V_62 == V_70 )
F_101 ( V_7 ) ;
if ( args -> V_62 == V_70 )
F_84 ( V_7 ) ;
}
if ( V_7 -> V_62 != V_63 )
V_7 -> V_62 = args -> V_62 ;
if ( V_7 -> V_62 == V_67 && V_7 -> V_60 == NULL )
F_203 ( V_7 ) ;
args -> V_425 = V_7 -> V_62 != V_63 ;
V_86:
F_53 ( & V_7 -> V_8 ) ;
V_122:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void F_362 ( struct V_6 * V_7 ,
const struct V_237 * V_78 )
{
F_363 ( & V_7 -> V_239 ) ;
F_363 ( & V_7 -> V_257 ) ;
F_363 ( & V_7 -> V_426 ) ;
F_363 ( & V_7 -> V_339 ) ;
F_363 ( & V_7 -> V_427 ) ;
V_7 -> V_78 = V_78 ;
V_7 -> V_13 = V_14 ;
V_7 -> V_62 = V_70 ;
F_6 ( V_7 -> V_8 . V_2 -> V_27 , V_7 -> V_8 . V_17 ) ;
}
struct V_6 * F_70 ( struct V_1 * V_2 ,
T_1 V_17 )
{
struct V_6 * V_7 ;
struct V_39 * V_40 ;
T_13 V_428 ;
V_7 = F_64 ( V_2 ) ;
if ( V_7 == NULL )
return NULL ;
if ( F_364 ( V_2 , & V_7 -> V_8 , V_17 ) != 0 ) {
F_66 ( V_7 ) ;
return NULL ;
}
V_428 = V_429 | V_430 ;
if ( F_365 ( V_2 ) || F_366 ( V_2 ) ) {
V_428 &= ~ V_431 ;
V_428 |= V_251 ;
}
V_40 = F_25 ( V_7 -> V_8 . V_41 ) -> V_42 ;
F_367 ( V_40 , V_428 ) ;
F_362 ( V_7 , & V_432 ) ;
V_7 -> V_8 . V_65 = V_66 ;
V_7 -> V_8 . V_64 = V_66 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_9 = V_402 ;
} else
V_7 -> V_9 = V_5 ;
F_368 ( V_7 ) ;
return V_7 ;
}
static bool F_369 ( struct V_6 * V_7 )
{
if ( V_7 -> V_62 != V_70 )
return false ;
if ( V_7 -> V_8 . V_41 == NULL )
return true ;
return F_370 ( & V_7 -> V_8 . V_41 -> V_433 ) == 1 ;
}
void F_371 ( struct V_197 * V_434 )
{
struct V_6 * V_7 = F_104 ( V_434 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_71 * V_72 , * V_73 ;
F_123 ( V_16 ) ;
F_372 ( V_7 ) ;
F_50 (vma, next, &obj->vma_list, vma_link) {
int V_23 ;
V_72 -> V_334 = 0 ;
V_23 = F_51 ( V_72 ) ;
if ( F_16 ( V_23 == - V_180 ) ) {
bool V_435 ;
V_435 = V_16 -> V_18 . V_145 ;
V_16 -> V_18 . V_145 = false ;
F_16 ( F_51 ( V_72 ) ) ;
V_16 -> V_18 . V_145 = V_435 ;
}
}
if ( V_7 -> V_398 )
F_101 ( V_7 ) ;
F_16 ( V_7 -> V_436 ) ;
if ( V_7 -> V_60 && V_7 -> V_62 == V_70 &&
V_16 -> V_252 & V_253 &&
V_7 -> V_11 != V_143 )
F_101 ( V_7 ) ;
if ( F_16 ( V_7 -> V_238 ) )
V_7 -> V_238 = 0 ;
if ( F_369 ( V_7 ) )
V_7 -> V_62 = V_67 ;
F_52 ( V_7 ) ;
F_197 ( V_7 ) ;
F_41 ( V_7 -> V_60 ) ;
if ( V_7 -> V_8 . V_437 )
F_373 ( & V_7 -> V_8 , NULL ) ;
if ( V_7 -> V_78 -> V_438 )
V_7 -> V_78 -> V_438 ( V_7 ) ;
F_374 ( & V_7 -> V_8 ) ;
F_9 ( V_16 , V_7 -> V_8 . V_17 ) ;
F_37 ( V_7 -> V_439 ) ;
F_66 ( V_7 ) ;
F_125 ( V_16 ) ;
}
struct V_71 * F_350 ( struct V_6 * V_7 ,
struct V_378 * V_260 )
{
struct V_71 * V_72 ;
F_20 (vma, &obj->vma_list, vma_link) {
if ( F_296 ( V_72 -> V_260 ) &&
V_72 -> V_335 . type != V_336 )
continue;
if ( V_72 -> V_260 == V_260 )
return V_72 ;
}
return NULL ;
}
struct V_71 * F_349 ( struct V_6 * V_7 ,
const struct V_379 * V_410 )
{
struct V_378 * V_440 = F_354 ( V_7 ) ;
struct V_71 * V_72 ;
if ( F_186 ( ! V_410 , L_21 ) )
return F_318 ( - V_50 ) ;
F_20 (vma, &obj->vma_list, vma_link)
if ( V_72 -> V_260 == V_440 &&
F_375 ( & V_72 -> V_335 , V_410 ) )
return V_72 ;
return NULL ;
}
void F_294 ( struct V_71 * V_72 )
{
struct V_378 * V_260 = NULL ;
F_16 ( V_72 -> V_333 . V_375 ) ;
if ( ! F_227 ( & V_72 -> V_441 ) )
return;
V_260 = V_72 -> V_260 ;
if ( ! F_296 ( V_260 ) )
F_376 ( F_377 ( V_260 ) ) ;
F_210 ( & V_72 -> V_332 ) ;
F_37 ( V_72 ) ;
}
static void
F_378 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_153 * V_150 ;
int V_49 ;
F_230 (ring, dev_priv, i)
V_16 -> V_442 . V_443 ( V_150 ) ;
}
int
F_379 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 = 0 ;
F_19 ( & V_2 -> V_29 ) ;
V_23 = F_300 ( V_2 ) ;
if ( V_23 )
goto V_444;
F_232 ( V_2 ) ;
F_378 ( V_2 ) ;
F_23 ( & V_2 -> V_29 ) ;
F_246 ( & V_16 -> V_28 . V_445 ) ;
F_246 ( & V_16 -> V_18 . V_290 ) ;
F_380 ( & V_16 -> V_18 . V_171 ) ;
F_16 ( V_16 -> V_18 . V_422 ) ;
return 0 ;
V_444:
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_381 ( struct V_153 * V_150 , int V_446 )
{
struct V_1 * V_2 = V_150 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_447 = V_448 + ( V_446 * 0x200 ) ;
T_6 * V_449 = V_16 -> V_450 . V_449 [ V_446 ] ;
int V_49 , V_23 ;
if ( ! F_382 ( V_2 ) || ! V_449 )
return 0 ;
V_23 = F_383 ( V_150 , V_451 / 4 * 3 ) ;
if ( V_23 )
return V_23 ;
for ( V_49 = 0 ; V_49 < V_451 ; V_49 += 4 ) {
F_384 ( V_150 , F_385 ( 1 ) ) ;
F_384 ( V_150 , V_447 + V_49 ) ;
F_384 ( V_150 , V_449 [ V_49 / 4 ] ) ;
}
F_386 ( V_150 ) ;
return V_23 ;
}
void F_387 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_147 ( V_2 ) -> V_168 < 5 ||
V_16 -> V_18 . V_452 == V_453 )
return;
F_303 ( V_454 , F_388 ( V_454 ) |
V_455 ) ;
if ( F_389 ( V_2 ) )
return;
F_303 ( V_456 , F_388 ( V_456 ) | V_457 ) ;
if ( F_390 ( V_2 ) )
F_303 ( V_458 , F_391 ( V_459 ) ) ;
else if ( F_392 ( V_2 ) )
F_303 ( V_458 , F_391 ( V_460 ) ) ;
else if ( F_393 ( V_2 ) )
F_303 ( V_461 , F_391 ( V_462 ) ) ;
else
F_394 () ;
}
static bool
F_395 ( struct V_1 * V_2 )
{
if ( ! F_396 ( V_2 ) )
return false ;
if ( F_390 ( V_2 ) && V_2 -> V_463 -> V_464 < 8 ) {
F_397 ( L_22
L_23 ) ;
return false ;
}
return true ;
}
static void F_398 ( struct V_1 * V_2 , T_6 V_8 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
F_303 ( F_399 ( V_8 ) , 0 ) ;
F_303 ( F_400 ( V_8 ) , 0 ) ;
F_303 ( F_401 ( V_8 ) , 0 ) ;
F_303 ( F_402 ( V_8 ) , 0 ) ;
}
static void F_403 ( struct V_1 * V_2 )
{
if ( F_404 ( V_2 ) ) {
F_398 ( V_2 , V_465 ) ;
F_398 ( V_2 , V_466 ) ;
F_398 ( V_2 , V_467 ) ;
F_398 ( V_2 , V_468 ) ;
F_398 ( V_2 , V_469 ) ;
} else if ( F_312 ( V_2 ) ) {
F_398 ( V_2 , V_466 ) ;
F_398 ( V_2 , V_467 ) ;
} else if ( F_313 ( V_2 ) ) {
F_398 ( V_2 , V_465 ) ;
F_398 ( V_2 , V_470 ) ;
}
}
int F_405 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
V_23 = F_406 ( V_2 ) ;
if ( V_23 )
return V_23 ;
if ( F_407 ( V_2 ) ) {
V_23 = F_408 ( V_2 ) ;
if ( V_23 )
goto V_471;
}
if ( F_395 ( V_2 ) ) {
V_23 = F_409 ( V_2 ) ;
if ( V_23 )
goto V_472;
}
if ( F_410 ( V_2 ) ) {
V_23 = F_411 ( V_2 ) ;
if ( V_23 )
goto V_473;
}
if ( F_412 ( V_2 ) ) {
V_23 = F_413 ( V_2 ) ;
if ( V_23 )
goto V_474;
}
V_23 = F_235 ( V_2 , ( ( T_6 ) ~ 0 - 0x1000 ) ) ;
if ( V_23 )
goto V_475;
return 0 ;
V_475:
F_414 ( & V_16 -> V_150 [ V_476 ] ) ;
V_474:
F_414 ( & V_16 -> V_150 [ V_477 ] ) ;
V_473:
F_414 ( & V_16 -> V_150 [ V_478 ] ) ;
V_472:
F_414 ( & V_16 -> V_150 [ V_479 ] ) ;
V_471:
F_414 ( & V_16 -> V_150 [ V_169 ] ) ;
return V_23 ;
}
int
F_415 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_153 * V_150 ;
int V_23 , V_49 ;
if ( F_147 ( V_2 ) -> V_168 < 6 && ! F_416 () )
return - V_26 ;
F_417 ( V_16 , V_480 ) ;
if ( V_16 -> V_481 )
F_303 ( V_482 , F_388 ( V_482 ) | F_418 ( 0xf ) ) ;
if ( F_419 ( V_2 ) )
F_303 ( V_483 , F_420 ( V_2 ) ?
V_484 : V_485 ) ;
if ( F_421 ( V_2 ) ) {
if ( F_422 ( V_2 ) ) {
T_6 V_486 = F_388 ( V_487 ) ;
V_486 &= ~ ( V_488 | V_489 ) ;
F_303 ( V_487 , V_486 ) ;
} else if ( F_147 ( V_2 ) -> V_168 >= 7 ) {
T_6 V_486 = F_388 ( V_490 ) ;
V_486 &= ~ V_491 ;
F_303 ( V_490 , V_486 ) ;
}
}
F_387 ( V_2 ) ;
F_403 ( V_2 ) ;
F_230 (ring, dev_priv, i) {
V_23 = V_150 -> V_492 ( V_150 ) ;
if ( V_23 )
goto V_86;
}
for ( V_49 = 0 ; V_49 < F_423 ( V_2 ) ; V_49 ++ )
F_381 ( & V_16 -> V_150 [ V_169 ] , V_49 ) ;
V_23 = F_424 ( V_2 ) ;
if ( V_23 && V_23 != - V_26 ) {
F_13 ( L_24 , V_23 ) ;
F_425 ( V_2 ) ;
}
V_23 = F_426 ( V_16 ) ;
if ( V_23 && V_23 != - V_26 ) {
F_13 ( L_25 , V_23 ) ;
F_425 ( V_2 ) ;
goto V_86;
}
V_86:
F_427 ( V_16 , V_480 ) ;
return V_23 ;
}
int F_428 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
V_118 . V_273 = F_429 ( V_2 ,
V_118 . V_273 ) ;
F_19 ( & V_2 -> V_29 ) ;
if ( F_430 ( V_2 ) ) {
F_303 ( V_493 , V_494 ) ;
if ( F_431 ( ( F_388 ( V_495 ) &
V_496 ) , 10 ) )
F_432 ( L_26 ) ;
}
if ( ! V_118 . V_273 ) {
V_16 -> V_442 . V_497 = V_498 ;
V_16 -> V_442 . V_499 = F_405 ;
V_16 -> V_442 . V_500 = F_414 ;
V_16 -> V_442 . V_443 = V_501 ;
} else {
V_16 -> V_442 . V_497 = V_502 ;
V_16 -> V_442 . V_499 = V_503 ;
V_16 -> V_442 . V_500 = V_504 ;
V_16 -> V_442 . V_443 = V_505 ;
}
F_417 ( V_16 , V_480 ) ;
V_23 = F_433 ( V_2 ) ;
if ( V_23 )
goto V_506;
F_434 ( V_2 ) ;
V_23 = F_435 ( V_2 ) ;
if ( V_23 )
goto V_506;
V_23 = V_16 -> V_442 . V_499 ( V_2 ) ;
if ( V_23 )
goto V_506;
V_23 = F_415 ( V_2 ) ;
if ( V_23 == - V_26 ) {
F_13 ( L_27 ) ;
F_436 ( V_507 , & V_16 -> V_28 . V_158 ) ;
V_23 = 0 ;
}
V_506:
F_427 ( V_16 , V_480 ) ;
F_23 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void
F_425 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_153 * V_150 ;
int V_49 ;
F_230 (ring, dev_priv, i)
V_16 -> V_442 . V_500 ( V_150 ) ;
}
static void
F_437 ( struct V_153 * V_150 )
{
F_363 ( & V_150 -> V_258 ) ;
F_363 ( & V_150 -> V_286 ) ;
}
void F_438 ( struct V_15 * V_16 ,
struct V_378 * V_260 )
{
if ( ! F_296 ( V_260 ) )
F_439 ( & V_260 -> V_18 , V_260 -> V_109 , V_260 -> V_37 ) ;
V_260 -> V_2 = V_16 -> V_2 ;
F_363 ( & V_260 -> V_258 ) ;
F_363 ( & V_260 -> V_261 ) ;
F_363 ( & V_260 -> V_508 ) ;
F_221 ( & V_260 -> V_508 , & V_16 -> V_509 ) ;
}
void
F_440 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_49 ;
V_16 -> V_87 =
F_441 ( L_28 ,
sizeof( struct V_6 ) , 0 ,
V_510 ,
NULL ) ;
F_363 ( & V_16 -> V_509 ) ;
F_438 ( V_16 , & V_16 -> V_36 . V_8 ) ;
F_363 ( & V_16 -> V_511 ) ;
F_363 ( & V_16 -> V_18 . V_255 ) ;
F_363 ( & V_16 -> V_18 . V_396 ) ;
F_363 ( & V_16 -> V_18 . V_363 ) ;
for ( V_49 = 0 ; V_49 < V_423 ; V_49 ++ )
F_437 ( & V_16 -> V_150 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_512 ; V_49 ++ )
F_363 ( & V_16 -> V_316 [ V_49 ] . V_362 ) ;
F_442 ( & V_16 -> V_18 . V_290 ,
F_279 ) ;
F_442 ( & V_16 -> V_18 . V_171 ,
F_281 ) ;
F_443 ( & V_16 -> V_28 . V_24 ) ;
V_16 -> V_513 = V_514 ;
if ( F_147 ( V_2 ) -> V_168 >= 7 && ! F_430 ( V_2 ) )
V_16 -> V_313 = 32 ;
else if ( F_147 ( V_2 ) -> V_168 >= 4 || F_444 ( V_2 ) || F_445 ( V_2 ) || F_191 ( V_2 ) )
V_16 -> V_313 = 16 ;
else
V_16 -> V_313 = 8 ;
if ( F_446 ( V_2 ) )
V_16 -> V_313 =
F_388 ( F_447 ( V_515 . V_516 ) ) ;
F_363 ( & V_16 -> V_18 . V_363 ) ;
F_269 ( V_2 ) ;
F_448 ( V_2 ) ;
F_443 ( & V_16 -> V_517 ) ;
V_16 -> V_18 . V_145 = true ;
F_449 ( V_16 ) ;
F_450 ( V_2 , & V_16 -> V_18 . V_518 ) ;
F_451 ( & V_16 -> V_519 . V_287 ) ;
}
void F_452 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_156 * V_81 = V_32 -> V_192 ;
F_246 ( & V_81 -> V_18 . V_171 ) ;
F_7 ( & V_81 -> V_18 . V_287 ) ;
while ( ! F_227 ( & V_81 -> V_18 . V_286 ) ) {
struct V_148 * V_269 ;
V_269 = F_268 ( & V_81 -> V_18 . V_286 ,
struct V_148 ,
V_288 ) ;
F_210 ( & V_269 -> V_288 ) ;
V_269 -> V_81 = NULL ;
}
F_8 ( & V_81 -> V_18 . V_287 ) ;
}
static void
F_453 ( struct V_321 * V_322 )
{
struct V_156 * V_81 =
F_260 ( V_322 , F_261 ( * V_81 ) , V_18 . V_171 . V_322 ) ;
F_454 ( & V_81 -> V_157 , false ) ;
}
int F_455 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_156 * V_81 ;
int V_23 ;
F_432 ( L_29 ) ;
V_81 = F_456 ( sizeof( * V_81 ) , V_54 ) ;
if ( ! V_81 )
return - V_55 ;
V_32 -> V_192 = V_81 ;
V_81 -> V_16 = V_2 -> V_27 ;
V_81 -> V_32 = V_32 ;
F_457 ( & V_81 -> V_18 . V_287 ) ;
F_363 ( & V_81 -> V_18 . V_286 ) ;
F_442 ( & V_81 -> V_18 . V_171 ,
F_453 ) ;
V_23 = F_458 ( V_2 , V_32 ) ;
if ( V_23 )
F_37 ( V_81 ) ;
return V_23 ;
}
void F_459 ( struct V_6 * V_368 ,
struct V_6 * V_520 ,
unsigned V_436 )
{
if ( V_368 ) {
F_16 ( ! F_130 ( & V_368 -> V_8 . V_2 -> V_29 ) ) ;
F_16 ( ! ( V_368 -> V_436 & V_436 ) ) ;
V_368 -> V_436 &= ~ V_436 ;
}
if ( V_520 ) {
F_16 ( ! F_130 ( & V_520 -> V_8 . V_2 -> V_29 ) ) ;
F_16 ( V_520 -> V_436 & V_436 ) ;
V_520 -> V_436 |= V_436 ;
}
}
unsigned long
F_352 ( struct V_6 * V_521 ,
struct V_378 * V_260 )
{
struct V_15 * V_16 = V_521 -> V_8 . V_2 -> V_27 ;
struct V_71 * V_72 ;
F_16 ( V_260 == & V_16 -> V_18 . V_415 -> V_8 ) ;
F_20 (vma, &o->vma_list, vma_link) {
if ( F_296 ( V_72 -> V_260 ) &&
V_72 -> V_335 . type != V_336 )
continue;
if ( V_72 -> V_260 == V_260 )
return V_72 -> V_333 . V_109 ;
}
F_143 ( 1 , L_30 ,
F_296 ( V_260 ) ? L_31 : L_20 ) ;
return - 1 ;
}
unsigned long
F_351 ( struct V_6 * V_521 ,
const struct V_379 * V_410 )
{
struct V_378 * V_440 = F_354 ( V_521 ) ;
struct V_71 * V_72 ;
F_20 (vma, &o->vma_list, vma_link)
if ( V_72 -> V_260 == V_440 &&
F_375 ( & V_72 -> V_335 , V_410 ) )
return V_72 -> V_333 . V_109 ;
F_143 ( 1 , L_32 ) ;
return - 1 ;
}
bool F_460 ( struct V_6 * V_521 ,
struct V_378 * V_260 )
{
struct V_71 * V_72 ;
F_20 (vma, &o->vma_list, vma_link) {
if ( F_296 ( V_72 -> V_260 ) &&
V_72 -> V_335 . type != V_336 )
continue;
if ( V_72 -> V_260 == V_260 && F_293 ( & V_72 -> V_333 ) )
return true ;
}
return false ;
}
bool F_355 ( struct V_6 * V_521 ,
const struct V_379 * V_410 )
{
struct V_378 * V_440 = F_354 ( V_521 ) ;
struct V_71 * V_72 ;
F_20 (vma, &o->vma_list, vma_link)
if ( V_72 -> V_260 == V_440 &&
F_375 ( & V_72 -> V_335 , V_410 ) &&
F_293 ( & V_72 -> V_333 ) )
return true ;
return false ;
}
bool F_209 ( struct V_6 * V_521 )
{
struct V_71 * V_72 ;
F_20 (vma, &o->vma_list, vma_link)
if ( F_293 ( & V_72 -> V_333 ) )
return true ;
return false ;
}
unsigned long F_461 ( struct V_6 * V_521 ,
struct V_378 * V_260 )
{
struct V_15 * V_16 = V_521 -> V_8 . V_2 -> V_27 ;
struct V_71 * V_72 ;
F_16 ( V_260 == & V_16 -> V_18 . V_415 -> V_8 ) ;
F_41 ( F_227 ( & V_521 -> V_339 ) ) ;
F_20 (vma, &o->vma_list, vma_link) {
if ( F_296 ( V_72 -> V_260 ) &&
V_72 -> V_335 . type != V_336 )
continue;
if ( V_72 -> V_260 == V_260 )
return V_72 -> V_333 . V_17 ;
}
return 0 ;
}
bool F_21 ( struct V_6 * V_7 )
{
struct V_71 * V_72 ;
F_20 (vma, &obj->vma_list, vma_link) {
if ( F_296 ( V_72 -> V_260 ) &&
V_72 -> V_335 . type != V_336 )
continue;
if ( V_72 -> V_334 > 0 )
return true ;
}
return false ;
}

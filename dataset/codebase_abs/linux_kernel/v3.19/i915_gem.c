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
struct V_6 * V_7 ;
T_1 V_35 ;
V_35 = 0 ;
F_21 ( & V_2 -> V_29 ) ;
F_22 (obj, &dev_priv->mm.bound_list, global_list)
if ( F_23 ( V_7 ) )
V_35 += F_24 ( V_7 ) ;
F_25 ( & V_2 -> V_29 ) ;
args -> V_36 = V_16 -> V_37 . V_8 . V_38 ;
args -> V_39 = args -> V_36 - V_35 ;
return 0 ;
}
static int
F_26 ( struct V_6 * V_7 )
{
struct V_40 * V_41 = F_27 ( V_7 -> V_8 . V_42 ) -> V_43 ;
char * V_44 = V_7 -> V_45 -> V_44 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_50 ;
if ( F_16 ( F_28 ( V_7 ) ) )
return - V_51 ;
for ( V_50 = 0 ; V_50 < V_7 -> V_8 . V_17 / V_52 ; V_50 ++ ) {
struct V_53 * V_53 ;
char * V_54 ;
V_53 = F_29 ( V_41 , V_50 ) ;
if ( F_30 ( V_53 ) )
return F_31 ( V_53 ) ;
V_54 = F_32 ( V_53 ) ;
memcpy ( V_44 , V_54 , V_52 ) ;
F_33 ( V_44 , V_52 ) ;
F_34 ( V_54 ) ;
F_35 ( V_53 ) ;
V_44 += V_52 ;
}
F_36 ( V_7 -> V_8 . V_2 ) ;
V_47 = F_37 ( sizeof( * V_47 ) , V_55 ) ;
if ( V_47 == NULL )
return - V_56 ;
if ( F_38 ( V_47 , 1 , V_55 ) ) {
F_39 ( V_47 ) ;
return - V_56 ;
}
V_49 = V_47 -> V_57 ;
V_49 -> V_58 = 0 ;
V_49 -> V_59 = V_7 -> V_8 . V_17 ;
F_40 ( V_49 ) = V_7 -> V_45 -> V_60 ;
F_41 ( V_49 ) = V_7 -> V_8 . V_17 ;
V_7 -> V_61 = V_47 ;
V_7 -> V_62 = true ;
return 0 ;
}
static void
F_42 ( struct V_6 * V_7 )
{
int V_23 ;
F_43 ( V_7 -> V_63 == V_64 ) ;
V_23 = F_44 ( V_7 , true ) ;
if ( V_23 ) {
F_16 ( V_23 != - V_26 ) ;
V_7 -> V_8 . V_65 = V_7 -> V_8 . V_66 = V_67 ;
}
if ( V_7 -> V_63 == V_68 )
V_7 -> V_69 = 0 ;
if ( V_7 -> V_69 ) {
struct V_40 * V_41 = F_27 ( V_7 -> V_8 . V_42 ) -> V_43 ;
char * V_44 = V_7 -> V_45 -> V_44 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_7 -> V_8 . V_17 / V_52 ; V_50 ++ ) {
struct V_53 * V_53 ;
char * V_70 ;
V_53 = F_29 ( V_41 , V_50 ) ;
if ( F_30 ( V_53 ) )
continue;
V_70 = F_32 ( V_53 ) ;
F_33 ( V_44 , V_52 ) ;
memcpy ( V_70 , V_44 , V_52 ) ;
F_34 ( V_70 ) ;
F_45 ( V_53 ) ;
if ( V_7 -> V_63 == V_71 )
F_46 ( V_53 ) ;
F_35 ( V_53 ) ;
V_44 += V_52 ;
}
V_7 -> V_69 = 0 ;
}
F_47 ( V_7 -> V_61 ) ;
F_39 ( V_7 -> V_61 ) ;
V_7 -> V_62 = false ;
}
static void
F_48 ( struct V_6 * V_7 )
{
F_49 ( V_7 -> V_8 . V_2 , V_7 -> V_45 ) ;
}
static int
F_50 ( struct V_6 * V_7 )
{
struct V_72 * V_73 , * V_74 ;
int V_23 ;
F_51 ( & V_7 -> V_8 ) ;
F_52 (vma, next, &obj->vma_list, vma_link)
if ( F_53 ( V_73 ) )
break;
V_23 = F_54 ( V_7 ) ;
F_55 ( & V_7 -> V_8 ) ;
return V_23 ;
}
int
F_56 ( struct V_6 * V_7 ,
int V_75 )
{
T_2 * V_76 ;
int V_23 ;
if ( V_7 -> V_45 ) {
if ( ( unsigned long ) V_7 -> V_45 -> V_44 & ( V_75 - 1 ) )
return - V_77 ;
return 0 ;
}
if ( V_7 -> V_63 != V_71 )
return - V_78 ;
if ( V_7 -> V_8 . V_42 == NULL )
return - V_51 ;
V_23 = F_50 ( V_7 ) ;
if ( V_23 )
return V_23 ;
V_76 = F_57 ( V_7 -> V_8 . V_2 , V_7 -> V_8 . V_17 , V_75 ) ;
if ( ! V_76 )
return - V_56 ;
V_7 -> V_45 = V_76 ;
V_7 -> V_79 = & V_80 ;
return F_58 ( V_7 ) ;
}
static int
F_59 ( struct V_6 * V_7 ,
struct V_81 * args ,
struct V_32 * V_82 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
void * V_44 = V_7 -> V_45 -> V_44 + args -> V_58 ;
char T_3 * V_83 = F_60 ( args -> V_84 ) ;
int V_23 ;
V_23 = F_61 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
if ( F_62 ( V_44 , V_83 , args -> V_17 ) ) {
unsigned long V_85 ;
F_25 ( & V_2 -> V_29 ) ;
V_85 = F_63 ( V_44 , V_83 , args -> V_17 ) ;
F_21 ( & V_2 -> V_29 ) ;
if ( V_85 )
return - V_78 ;
}
F_33 ( V_44 , args -> V_17 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
void * F_64 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
return F_65 ( V_16 -> V_86 , V_55 ) ;
}
void F_66 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
F_67 ( V_16 -> V_86 , V_7 ) ;
}
static int
F_68 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_4 V_17 ,
T_5 * V_87 )
{
struct V_6 * V_7 ;
int V_23 ;
T_6 V_88 ;
V_17 = F_69 ( V_17 , V_52 ) ;
if ( V_17 == 0 )
return - V_51 ;
V_7 = F_70 ( V_2 , V_17 ) ;
if ( V_7 == NULL )
return - V_56 ;
V_23 = F_71 ( V_33 , & V_7 -> V_8 , & V_88 ) ;
F_72 ( & V_7 -> V_8 ) ;
if ( V_23 )
return V_23 ;
* V_87 = V_88 ;
return 0 ;
}
int
F_73 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
struct V_89 * args )
{
args -> V_90 = F_74 ( args -> V_91 * F_75 ( args -> V_92 , 8 ) , 64 ) ;
args -> V_17 = args -> V_90 * args -> V_93 ;
return F_68 ( V_33 , V_2 ,
args -> V_17 , & args -> V_88 ) ;
}
int
F_76 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_94 * args = V_31 ;
return F_68 ( V_33 , V_2 ,
args -> V_17 , & args -> V_88 ) ;
}
static inline int
F_77 ( char T_3 * V_95 ,
const char * V_96 , int V_97 ,
int V_59 )
{
int V_23 , V_98 = 0 ;
while ( V_59 > 0 ) {
int V_99 = F_74 ( V_97 + 1 , 64 ) ;
int V_100 = F_78 ( V_99 - V_97 , V_59 ) ;
int V_101 = V_97 ^ 64 ;
V_23 = F_79 ( V_95 + V_98 ,
V_96 + V_101 ,
V_100 ) ;
if ( V_23 )
return V_23 + V_59 ;
V_98 += V_100 ;
V_97 += V_100 ;
V_59 -= V_100 ;
}
return 0 ;
}
static inline int
F_80 ( char * V_96 , int V_97 ,
const char T_3 * V_95 ,
int V_59 )
{
int V_23 , V_98 = 0 ;
while ( V_59 > 0 ) {
int V_99 = F_74 ( V_97 + 1 , 64 ) ;
int V_100 = F_78 ( V_99 - V_97 , V_59 ) ;
int V_101 = V_97 ^ 64 ;
V_23 = F_81 ( V_96 + V_101 ,
V_95 + V_98 ,
V_100 ) ;
if ( V_23 )
return V_23 + V_59 ;
V_98 += V_100 ;
V_97 += V_100 ;
V_59 -= V_100 ;
}
return 0 ;
}
int F_82 ( struct V_6 * V_7 ,
int * V_102 )
{
int V_23 ;
* V_102 = 0 ;
if ( ! V_7 -> V_8 . V_42 )
return - V_51 ;
if ( ! ( V_7 -> V_8 . V_65 & V_67 ) ) {
* V_102 = ! F_1 ( V_7 -> V_8 . V_2 ,
V_7 -> V_9 ) ;
V_23 = F_61 ( V_7 , true ) ;
if ( V_23 )
return V_23 ;
F_83 ( V_7 ) ;
}
V_23 = F_58 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_84 ( V_7 ) ;
return V_23 ;
}
static int
F_85 ( struct V_53 * V_53 , int V_103 , int V_104 ,
char T_3 * V_83 ,
bool V_105 , bool V_102 )
{
char * V_44 ;
int V_23 ;
if ( F_86 ( V_105 ) )
return - V_51 ;
V_44 = F_32 ( V_53 ) ;
if ( V_102 )
F_33 ( V_44 + V_103 ,
V_104 ) ;
V_23 = F_87 ( V_83 ,
V_44 + V_103 ,
V_104 ) ;
F_34 ( V_44 ) ;
return V_23 ? - V_78 : 0 ;
}
static void
F_88 ( char * V_106 , unsigned long V_59 ,
bool V_107 )
{
if ( F_86 ( V_107 ) ) {
unsigned long V_108 = ( unsigned long ) V_106 ;
unsigned long V_109 = ( unsigned long ) V_106 + V_59 ;
V_108 = F_89 ( V_108 , 128 ) ;
V_109 = F_90 ( V_109 , 128 ) ;
F_33 ( ( void * ) V_108 , V_109 - V_108 ) ;
} else {
F_33 ( V_106 , V_59 ) ;
}
}
static int
F_91 ( struct V_53 * V_53 , int V_103 , int V_104 ,
char T_3 * V_83 ,
bool V_105 , bool V_102 )
{
char * V_44 ;
int V_23 ;
V_44 = F_92 ( V_53 ) ;
if ( V_102 )
F_88 ( V_44 + V_103 ,
V_104 ,
V_105 ) ;
if ( V_105 )
V_23 = F_77 ( V_83 ,
V_44 , V_103 ,
V_104 ) ;
else
V_23 = F_79 ( V_83 ,
V_44 + V_103 ,
V_104 ) ;
F_93 ( V_53 ) ;
return V_23 ? - V_78 : 0 ;
}
static int
F_94 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_110 * args ,
struct V_32 * V_33 )
{
char T_3 * V_83 ;
T_7 V_111 ;
T_8 V_58 ;
int V_103 , V_104 , V_23 = 0 ;
int V_112 , V_105 ;
int V_113 = 0 ;
int V_102 = 0 ;
struct V_114 V_115 ;
V_83 = F_60 ( args -> V_84 ) ;
V_111 = args -> V_17 ;
V_112 = F_28 ( V_7 ) ;
V_23 = F_82 ( V_7 , & V_102 ) ;
if ( V_23 )
return V_23 ;
V_58 = args -> V_58 ;
F_95 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_53 * V_53 = F_96 ( & V_115 ) ;
if ( V_111 <= 0 )
break;
V_103 = F_97 ( V_58 ) ;
V_104 = V_111 ;
if ( ( V_103 + V_104 ) > V_52 )
V_104 = V_52 - V_103 ;
V_105 = V_112 &&
( F_98 ( V_53 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_85 ( V_53 , V_103 , V_104 ,
V_83 , V_105 ,
V_102 ) ;
if ( V_23 == 0 )
goto V_116;
F_25 ( & V_2 -> V_29 ) ;
if ( F_99 ( ! V_117 . V_118 ) && ! V_113 ) {
V_23 = F_100 ( V_83 , V_111 ) ;
( void ) V_23 ;
V_113 = 1 ;
}
V_23 = F_91 ( V_53 , V_103 , V_104 ,
V_83 , V_105 ,
V_102 ) ;
F_21 ( & V_2 -> V_29 ) ;
if ( V_23 )
goto V_119;
V_116:
V_111 -= V_104 ;
V_83 += V_104 ;
V_58 += V_104 ;
}
V_119:
F_101 ( V_7 ) ;
return V_23 ;
}
int
F_102 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_110 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_103 ( V_120 ,
F_60 ( args -> V_84 ) ,
args -> V_17 ) )
return - V_78 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_33 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
if ( args -> V_58 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_58 ) {
V_23 = - V_51 ;
goto V_119;
}
if ( ! V_7 -> V_8 . V_42 ) {
V_23 = - V_51 ;
goto V_119;
}
F_106 ( V_7 , args -> V_58 , args -> V_17 ) ;
V_23 = F_94 ( V_2 , V_7 , args , V_33 ) ;
V_119:
F_55 ( & V_7 -> V_8 ) ;
V_122:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static inline int
F_107 ( struct V_123 * V_41 ,
T_8 V_124 , int V_125 ,
char T_3 * V_83 ,
int V_59 )
{
void T_9 * V_126 ;
void * V_44 ;
unsigned long V_85 ;
V_126 = F_108 ( V_41 , V_124 ) ;
V_44 = ( void V_127 * ) V_126 + V_125 ;
V_85 = F_62 ( V_44 ,
V_83 , V_59 ) ;
F_109 ( V_126 ) ;
return V_85 ;
}
static int
F_110 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_81 * args ,
struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_7 V_111 ;
T_8 V_58 , V_124 ;
char T_3 * V_83 ;
int V_125 , V_104 , V_23 ;
V_23 = F_111 ( V_7 , 0 , V_128 | V_129 ) ;
if ( V_23 )
goto V_119;
V_23 = F_112 ( V_7 , true ) ;
if ( V_23 )
goto V_130;
V_23 = F_113 ( V_7 ) ;
if ( V_23 )
goto V_130;
V_83 = F_60 ( args -> V_84 ) ;
V_111 = args -> V_17 ;
V_58 = F_114 ( V_7 ) + args -> V_58 ;
while ( V_111 > 0 ) {
V_124 = V_58 & V_131 ;
V_125 = F_97 ( V_58 ) ;
V_104 = V_111 ;
if ( ( V_125 + V_111 ) > V_52 )
V_104 = V_52 - V_125 ;
if ( F_107 ( V_16 -> V_37 . V_132 , V_124 ,
V_125 , V_83 , V_104 ) ) {
V_23 = - V_78 ;
goto V_130;
}
V_111 -= V_104 ;
V_83 += V_104 ;
V_58 += V_104 ;
}
V_130:
F_115 ( V_7 ) ;
V_119:
return V_23 ;
}
static int
F_116 ( struct V_53 * V_53 , int V_103 , int V_104 ,
char T_3 * V_83 ,
bool V_105 ,
bool V_133 ,
bool V_134 )
{
char * V_44 ;
int V_23 ;
if ( F_86 ( V_105 ) )
return - V_51 ;
V_44 = F_32 ( V_53 ) ;
if ( V_133 )
F_33 ( V_44 + V_103 ,
V_104 ) ;
V_23 = F_117 ( V_44 + V_103 ,
V_83 , V_104 ) ;
if ( V_134 )
F_33 ( V_44 + V_103 ,
V_104 ) ;
F_34 ( V_44 ) ;
return V_23 ? - V_78 : 0 ;
}
static int
F_118 ( struct V_53 * V_53 , int V_103 , int V_104 ,
char T_3 * V_83 ,
bool V_105 ,
bool V_133 ,
bool V_134 )
{
char * V_44 ;
int V_23 ;
V_44 = F_92 ( V_53 ) ;
if ( F_86 ( V_133 || V_105 ) )
F_88 ( V_44 + V_103 ,
V_104 ,
V_105 ) ;
if ( V_105 )
V_23 = F_80 ( V_44 , V_103 ,
V_83 ,
V_104 ) ;
else
V_23 = F_81 ( V_44 + V_103 ,
V_83 ,
V_104 ) ;
if ( V_134 )
F_88 ( V_44 + V_103 ,
V_104 ,
V_105 ) ;
F_93 ( V_53 ) ;
return V_23 ? - V_78 : 0 ;
}
static int
F_119 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_81 * args ,
struct V_32 * V_33 )
{
T_7 V_111 ;
T_8 V_58 ;
char T_3 * V_83 ;
int V_103 , V_104 , V_23 = 0 ;
int V_112 , V_105 ;
int V_135 = 0 ;
int V_134 = 0 ;
int V_133 = 0 ;
struct V_114 V_115 ;
V_83 = F_60 ( args -> V_84 ) ;
V_111 = args -> V_17 ;
V_112 = F_28 ( V_7 ) ;
if ( V_7 -> V_8 . V_66 != V_67 ) {
V_134 = F_3 ( V_7 ) ;
V_23 = F_61 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
F_83 ( V_7 ) ;
}
if ( ( V_7 -> V_8 . V_65 & V_67 ) == 0 )
V_133 =
! F_1 ( V_2 , V_7 -> V_9 ) ;
V_23 = F_58 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_84 ( V_7 ) ;
V_58 = args -> V_58 ;
V_7 -> V_69 = 1 ;
F_95 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_53 * V_53 = F_96 ( & V_115 ) ;
int V_136 ;
if ( V_111 <= 0 )
break;
V_103 = F_97 ( V_58 ) ;
V_104 = V_111 ;
if ( ( V_103 + V_104 ) > V_52 )
V_104 = V_52 - V_103 ;
V_136 = V_133 &&
( ( V_103 | V_104 )
& ( V_137 . V_138 - 1 ) ) ;
V_105 = V_112 &&
( F_98 ( V_53 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_116 ( V_53 , V_103 , V_104 ,
V_83 , V_105 ,
V_136 ,
V_134 ) ;
if ( V_23 == 0 )
goto V_116;
V_135 = 1 ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_118 ( V_53 , V_103 , V_104 ,
V_83 , V_105 ,
V_136 ,
V_134 ) ;
F_21 ( & V_2 -> V_29 ) ;
if ( V_23 )
goto V_119;
V_116:
V_111 -= V_104 ;
V_83 += V_104 ;
V_58 += V_104 ;
}
V_119:
F_101 ( V_7 ) ;
if ( V_135 ) {
if ( ! V_134 &&
V_7 -> V_8 . V_66 != V_67 ) {
if ( F_120 ( V_7 , V_7 -> V_10 ) )
F_36 ( V_2 ) ;
}
}
if ( V_134 )
F_36 ( V_2 ) ;
return V_23 ;
}
int
F_121 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_81 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_103 ( V_139 ,
F_60 ( args -> V_84 ) ,
args -> V_17 ) )
return - V_78 ;
if ( F_99 ( ! V_117 . V_118 ) ) {
V_23 = F_122 ( F_60 ( args -> V_84 ) ,
args -> V_17 ) ;
if ( V_23 )
return - V_78 ;
}
F_123 ( V_16 ) ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
goto V_140;
V_7 = F_104 ( F_105 ( V_2 , V_33 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
if ( args -> V_58 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_58 ) {
V_23 = - V_51 ;
goto V_119;
}
if ( ! V_7 -> V_8 . V_42 ) {
V_23 = - V_51 ;
goto V_119;
}
F_124 ( V_7 , args -> V_58 , args -> V_17 ) ;
V_23 = - V_78 ;
if ( V_7 -> V_11 == V_141 &&
V_7 -> V_8 . V_66 != V_67 &&
F_3 ( V_7 ) ) {
V_23 = F_110 ( V_2 , V_7 , args , V_33 ) ;
}
if ( V_23 == - V_78 || V_23 == - V_142 ) {
if ( V_7 -> V_45 )
V_23 = F_59 ( V_7 , args , V_33 ) ;
else
V_23 = F_119 ( V_2 , V_7 , args , V_33 ) ;
}
V_119:
F_55 ( & V_7 -> V_8 ) ;
V_122:
F_25 ( & V_2 -> V_29 ) ;
V_140:
F_125 ( V_16 ) ;
return V_23 ;
}
int
F_126 ( struct V_22 * error ,
bool V_143 )
{
if ( F_127 ( error ) ) {
if ( ! V_143 )
return - V_26 ;
if ( F_128 ( error ) )
return - V_26 ;
if ( ! error -> V_144 )
return - V_145 ;
}
return 0 ;
}
int
F_129 ( struct V_146 * V_147 , T_6 V_148 )
{
int V_23 ;
F_43 ( ! F_130 ( & V_147 -> V_2 -> V_29 ) ) ;
V_23 = 0 ;
if ( V_148 == V_147 -> V_149 )
V_23 = F_131 ( V_147 , NULL ) ;
return V_23 ;
}
static void F_132 ( unsigned long V_31 )
{
F_133 ( (struct V_150 * ) V_31 ) ;
}
static bool F_134 ( struct V_15 * V_16 ,
struct V_146 * V_147 )
{
return F_135 ( V_147 -> V_151 , & V_16 -> V_28 . V_152 ) ;
}
static bool F_136 ( struct V_153 * V_82 )
{
if ( V_82 == NULL )
return true ;
return ! F_137 ( & V_82 -> V_154 , true ) ;
}
int F_138 ( struct V_146 * V_147 , T_6 V_148 ,
unsigned V_155 ,
bool V_143 ,
T_10 * V_156 ,
struct V_153 * V_82 )
{
struct V_1 * V_2 = V_147 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
const bool V_157 =
F_139 ( V_16 -> V_28 . V_158 ) & F_140 ( V_147 ) ;
F_141 ( V_159 ) ;
unsigned long V_160 ;
T_10 V_161 , V_162 ;
int V_23 ;
F_142 ( ! F_143 ( V_16 ) , L_2 ) ;
if ( F_144 ( V_147 -> V_163 ( V_147 , true ) , V_148 ) )
return 0 ;
V_160 = V_156 ?
V_164 + F_145 ( ( V_165 ) * V_156 ) : 0 ;
if ( F_146 ( V_2 ) -> V_166 >= 6 && V_147 -> V_151 == V_167 && F_136 ( V_82 ) ) {
F_147 ( V_16 ) ;
if ( V_82 )
F_148 ( V_16 -> V_168 ,
& V_82 -> V_18 . V_169 ,
F_149 ( 100 ) ) ;
}
if ( ! V_157 && F_16 ( ! V_147 -> V_170 ( V_147 ) ) )
return - V_171 ;
F_150 ( V_147 , V_148 ) ;
V_161 = F_151 () ;
for (; ; ) {
struct V_172 V_173 ;
F_152 ( & V_147 -> V_174 , & V_159 ,
V_143 ? V_175 : V_176 ) ;
if ( V_155 != F_153 ( & V_16 -> V_28 . V_155 ) ) {
V_23 = F_126 ( & V_16 -> V_28 , V_143 ) ;
if ( V_23 == 0 )
V_23 = - V_145 ;
break;
}
if ( F_144 ( V_147 -> V_163 ( V_147 , false ) , V_148 ) ) {
V_23 = 0 ;
break;
}
if ( V_143 && F_154 ( V_177 ) ) {
V_23 = - V_178 ;
break;
}
if ( V_156 && F_155 ( V_164 , V_160 ) ) {
V_23 = - V_179 ;
break;
}
V_173 . V_180 = NULL ;
if ( V_156 || F_134 ( V_16 , V_147 ) ) {
unsigned long V_181 ;
F_156 ( & V_173 , F_132 , ( unsigned long ) V_177 ) ;
V_181 = F_134 ( V_16 , V_147 ) ? V_164 + 1 : V_160 ;
F_157 ( & V_173 , V_181 ) ;
}
F_158 () ;
if ( V_173 . V_180 ) {
F_159 ( & V_173 ) ;
F_160 ( & V_173 ) ;
}
}
V_162 = F_151 () ;
F_161 ( V_147 , V_148 ) ;
if ( ! V_157 )
V_147 -> V_182 ( V_147 ) ;
F_162 ( & V_147 -> V_174 , & V_159 ) ;
if ( V_156 ) {
T_10 V_183 = * V_156 - ( V_162 - V_161 ) ;
* V_156 = V_183 < 0 ? 0 : V_183 ;
if ( V_23 == - V_179 && * V_156 < F_163 ( 1 ) * 1000 )
* V_156 = 0 ;
}
return V_23 ;
}
int
F_164 ( struct V_146 * V_147 , T_5 V_148 )
{
struct V_1 * V_2 = V_147 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_143 = V_16 -> V_18 . V_143 ;
unsigned V_155 ;
int V_23 ;
F_43 ( ! F_130 ( & V_2 -> V_29 ) ) ;
F_43 ( V_148 == 0 ) ;
V_23 = F_126 ( & V_16 -> V_28 , V_143 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_129 ( V_147 , V_148 ) ;
if ( V_23 )
return V_23 ;
V_155 = F_153 ( & V_16 -> V_28 . V_155 ) ;
return F_138 ( V_147 , V_148 , V_155 , V_143 ,
NULL , NULL ) ;
}
static int
F_165 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_30 )
return 0 ;
V_7 -> V_184 = 0 ;
return 0 ;
}
static T_11 int
F_61 ( struct V_6 * V_7 ,
bool V_185 )
{
struct V_146 * V_147 = V_7 -> V_147 ;
T_6 V_148 ;
int V_23 ;
V_148 = V_185 ? V_7 -> V_184 : V_7 -> V_186 ;
if ( V_148 == 0 )
return 0 ;
V_23 = F_164 ( V_147 , V_148 ) ;
if ( V_23 )
return V_23 ;
return F_165 ( V_7 ) ;
}
static T_11 int
F_166 ( struct V_6 * V_7 ,
struct V_153 * V_82 ,
bool V_185 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_146 * V_147 = V_7 -> V_147 ;
unsigned V_155 ;
T_6 V_148 ;
int V_23 ;
F_43 ( ! F_130 ( & V_2 -> V_29 ) ) ;
F_43 ( ! V_16 -> V_18 . V_143 ) ;
V_148 = V_185 ? V_7 -> V_184 : V_7 -> V_186 ;
if ( V_148 == 0 )
return 0 ;
V_23 = F_126 ( & V_16 -> V_28 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = F_129 ( V_147 , V_148 ) ;
if ( V_23 )
return V_23 ;
V_155 = F_153 ( & V_16 -> V_28 . V_155 ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_138 ( V_147 , V_148 , V_155 , true , NULL ,
V_82 ) ;
F_21 ( & V_2 -> V_29 ) ;
if ( V_23 )
return V_23 ;
return F_165 ( V_7 ) ;
}
int
F_167 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_187 * args = V_31 ;
struct V_6 * V_7 ;
T_5 V_65 = args -> V_65 ;
T_5 V_66 = args -> V_66 ;
int V_23 ;
if ( V_66 & V_188 )
return - V_51 ;
if ( V_65 & V_188 )
return - V_51 ;
if ( V_66 != 0 && V_65 != V_66 )
return - V_51 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_33 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
V_23 = F_166 ( V_7 ,
V_33 -> V_189 ,
! V_66 ) ;
if ( V_23 )
goto V_190;
if ( V_65 & V_191 ) {
V_23 = F_112 ( V_7 , V_66 != 0 ) ;
if ( V_23 == - V_51 )
V_23 = 0 ;
} else {
V_23 = F_44 ( V_7 , V_66 != 0 ) ;
}
V_190:
F_55 ( & V_7 -> V_8 ) ;
V_122:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_168 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_192 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_33 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
if ( V_7 -> V_10 )
F_169 ( V_7 , true ) ;
F_55 ( & V_7 -> V_8 ) ;
V_122:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_170 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_193 * args = V_31 ;
struct V_194 * V_7 ;
unsigned long V_106 ;
V_7 = F_105 ( V_2 , V_33 , args -> V_88 ) ;
if ( V_7 == NULL )
return - V_121 ;
if ( ! V_7 -> V_42 ) {
F_72 ( V_7 ) ;
return - V_51 ;
}
V_106 = F_171 ( V_7 -> V_42 , 0 , args -> V_17 ,
V_195 | V_196 , V_197 ,
args -> V_58 ) ;
F_72 ( V_7 ) ;
if ( F_30 ( ( void * ) V_106 ) )
return V_106 ;
args -> V_198 = ( T_4 ) V_106 ;
return 0 ;
}
int F_172 ( struct V_199 * V_73 , struct V_200 * V_201 )
{
struct V_6 * V_7 = F_104 ( V_73 -> V_202 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_12 V_125 ;
unsigned long V_203 ;
int V_23 = 0 ;
bool V_204 = ! ! ( V_201 -> V_205 & V_206 ) ;
F_123 ( V_16 ) ;
V_125 = ( ( unsigned long ) V_201 -> V_207 - V_73 -> V_208 ) >>
V_209 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
goto V_119;
F_173 ( V_7 , V_125 , true , V_204 ) ;
V_23 = F_166 ( V_7 , NULL , ! V_204 ) ;
if ( V_23 )
goto V_122;
if ( V_7 -> V_9 != V_5 && ! F_2 ( V_2 ) ) {
V_23 = - V_78 ;
goto V_122;
}
V_23 = F_111 ( V_7 , 0 , V_128 ) ;
if ( V_23 )
goto V_122;
V_23 = F_112 ( V_7 , V_204 ) ;
if ( V_23 )
goto V_210;
V_23 = F_174 ( V_7 ) ;
if ( V_23 )
goto V_210;
V_203 = V_16 -> V_37 . V_211 + F_114 ( V_7 ) ;
V_203 >>= V_209 ;
if ( ! V_7 -> V_212 ) {
unsigned long V_17 = F_175 (unsigned long,
vma->vm_end - vma->vm_start,
obj->base.size) ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_17 > > V_209 ; V_50 ++ ) {
V_23 = F_176 ( V_73 ,
( unsigned long ) V_73 -> V_208 + V_50 * V_52 ,
V_203 + V_50 ) ;
if ( V_23 )
break;
}
V_7 -> V_212 = true ;
} else
V_23 = F_176 ( V_73 ,
( unsigned long ) V_201 -> V_207 ,
V_203 + V_125 ) ;
V_210:
F_115 ( V_7 ) ;
V_122:
F_25 ( & V_2 -> V_29 ) ;
V_119:
switch ( V_23 ) {
case - V_26 :
if ( ! F_128 ( & V_16 -> V_28 ) ) {
V_23 = V_213 ;
break;
}
case - V_145 :
case 0 :
case - V_178 :
case - V_214 :
case - V_77 :
V_23 = V_215 ;
break;
case - V_56 :
V_23 = V_216 ;
break;
case - V_142 :
case - V_78 :
V_23 = V_213 ;
break;
default:
F_177 ( V_23 , L_3 , V_23 ) ;
V_23 = V_213 ;
break;
}
F_125 ( V_16 ) ;
return V_23 ;
}
void
F_5 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_212 )
return;
F_178 ( & V_7 -> V_8 . V_217 ,
V_7 -> V_8 . V_2 -> V_218 -> V_43 ) ;
V_7 -> V_212 = false ;
}
void
F_179 ( struct V_15 * V_16 )
{
struct V_6 * V_7 ;
F_22 (obj, &dev_priv->mm.bound_list, global_list)
F_5 ( V_7 ) ;
}
T_5
F_180 ( struct V_1 * V_2 , T_5 V_17 , int V_11 )
{
T_5 V_219 ;
if ( F_146 ( V_2 ) -> V_166 >= 4 ||
V_11 == V_141 )
return V_17 ;
if ( F_146 ( V_2 ) -> V_166 == 3 )
V_219 = 1024 * 1024 ;
else
V_219 = 512 * 1024 ;
while ( V_219 < V_17 )
V_219 <<= 1 ;
return V_219 ;
}
T_5
F_181 ( struct V_1 * V_2 , T_5 V_17 ,
int V_11 , bool V_220 )
{
if ( F_146 ( V_2 ) -> V_166 >= 4 || ( ! V_220 && F_182 ( V_2 ) ) ||
V_11 == V_141 )
return 4096 ;
return F_180 ( V_2 , V_17 , V_11 ) ;
}
static int F_183 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_184 ( & V_7 -> V_8 . V_217 ) )
return 0 ;
V_16 -> V_18 . V_221 = true ;
V_23 = F_185 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_142 )
goto V_119;
F_186 ( V_16 ,
V_7 -> V_8 . V_17 >> V_209 ,
V_222 |
V_223 |
V_224 ) ;
V_23 = F_185 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_142 )
goto V_119;
F_187 ( V_16 ) ;
V_23 = F_185 ( & V_7 -> V_8 ) ;
V_119:
V_16 -> V_18 . V_221 = false ;
return V_23 ;
}
static void F_188 ( struct V_6 * V_7 )
{
F_189 ( & V_7 -> V_8 ) ;
}
int
F_190 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_5 V_88 ,
T_4 * V_58 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_33 , V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
if ( V_7 -> V_8 . V_17 > V_16 -> V_37 . V_225 ) {
V_23 = - V_226 ;
goto V_119;
}
if ( V_7 -> V_63 != V_71 ) {
F_191 ( L_4 ) ;
V_23 = - V_78 ;
goto V_119;
}
V_23 = F_183 ( V_7 ) ;
if ( V_23 )
goto V_119;
* V_58 = F_192 ( & V_7 -> V_8 . V_217 ) ;
V_119:
F_55 ( & V_7 -> V_8 ) ;
V_122:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_193 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_227 * args = V_31 ;
return F_190 ( V_33 , V_2 , args -> V_88 , & args -> V_58 ) ;
}
static inline int
F_194 ( struct V_6 * V_7 )
{
return V_7 -> V_63 == V_68 ;
}
static void
F_195 ( struct V_6 * V_7 )
{
F_188 ( V_7 ) ;
if ( V_7 -> V_8 . V_42 == NULL )
return;
F_196 ( F_27 ( V_7 -> V_8 . V_42 ) , 0 , ( T_8 ) - 1 ) ;
V_7 -> V_63 = V_64 ;
}
static void
F_197 ( struct V_6 * V_7 )
{
struct V_40 * V_41 ;
switch ( V_7 -> V_63 ) {
case V_68 :
F_195 ( V_7 ) ;
case V_64 :
return;
}
if ( V_7 -> V_8 . V_42 == NULL )
return;
V_41 = F_27 ( V_7 -> V_8 . V_42 ) -> V_43 ,
F_198 ( V_41 , 0 , ( T_8 ) - 1 ) ;
}
static void
F_199 ( struct V_6 * V_7 )
{
struct V_114 V_115 ;
int V_23 ;
F_43 ( V_7 -> V_63 == V_64 ) ;
V_23 = F_44 ( V_7 , true ) ;
if ( V_23 ) {
F_16 ( V_23 != - V_26 ) ;
F_120 ( V_7 , true ) ;
V_7 -> V_8 . V_65 = V_7 -> V_8 . V_66 = V_67 ;
}
if ( F_28 ( V_7 ) )
F_200 ( V_7 ) ;
if ( V_7 -> V_63 == V_68 )
V_7 -> V_69 = 0 ;
F_95 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_53 * V_53 = F_96 ( & V_115 ) ;
if ( V_7 -> V_69 )
F_45 ( V_53 ) ;
if ( V_7 -> V_63 == V_71 )
F_46 ( V_53 ) ;
F_35 ( V_53 ) ;
}
V_7 -> V_69 = 0 ;
F_47 ( V_7 -> V_61 ) ;
F_39 ( V_7 -> V_61 ) ;
}
int
F_54 ( struct V_6 * V_7 )
{
const struct V_228 * V_79 = V_7 -> V_79 ;
if ( V_7 -> V_61 == NULL )
return 0 ;
if ( V_7 -> V_229 )
return - V_77 ;
F_43 ( F_19 ( V_7 ) ) ;
F_201 ( & V_7 -> V_230 ) ;
V_79 -> V_231 ( V_7 ) ;
V_7 -> V_61 = NULL ;
F_197 ( V_7 ) ;
return 0 ;
}
unsigned long
F_186 ( struct V_15 * V_16 ,
long V_232 , unsigned V_205 )
{
const struct {
struct V_233 * V_234 ;
unsigned int V_235 ;
} V_236 [] = {
{ & V_16 -> V_18 . V_237 , V_223 } ,
{ & V_16 -> V_18 . V_238 , V_222 } ,
{ NULL , 0 } ,
} , * V_239 ;
unsigned long V_240 = 0 ;
for ( V_239 = V_236 ; V_239 -> V_234 ; V_239 ++ ) {
struct V_233 V_241 ;
if ( ( V_205 & V_239 -> V_235 ) == 0 )
continue;
F_202 ( & V_241 ) ;
while ( V_240 < V_232 && ! F_203 ( V_239 -> V_234 ) ) {
struct V_6 * V_7 ;
struct V_72 * V_73 , * V_242 ;
V_7 = F_204 ( V_239 -> V_234 ,
F_205 ( * V_7 ) , V_230 ) ;
F_206 ( & V_7 -> V_230 , & V_241 ) ;
if ( V_205 & V_224 &&
! F_194 ( V_7 ) )
continue;
F_51 ( & V_7 -> V_8 ) ;
F_52 (vma, v,
&obj->vma_list, vma_link)
if ( F_53 ( V_73 ) )
break;
if ( F_54 ( V_7 ) == 0 )
V_240 += V_7 -> V_8 . V_17 >> V_209 ;
F_55 ( & V_7 -> V_8 ) ;
}
F_207 ( & V_241 , V_239 -> V_234 ) ;
}
return V_240 ;
}
static unsigned long
F_187 ( struct V_15 * V_16 )
{
F_208 ( V_16 -> V_2 ) ;
return F_186 ( V_16 , V_243 ,
V_222 | V_223 ) ;
}
static int
F_209 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_244 , V_50 ;
struct V_40 * V_41 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_114 V_115 ;
struct V_53 * V_53 ;
unsigned long V_245 = 0 ;
T_13 V_246 ;
F_43 ( V_7 -> V_8 . V_65 & V_188 ) ;
F_43 ( V_7 -> V_8 . V_66 & V_188 ) ;
V_47 = F_37 ( sizeof( * V_47 ) , V_55 ) ;
if ( V_47 == NULL )
return - V_56 ;
V_244 = V_7 -> V_8 . V_17 / V_52 ;
if ( F_38 ( V_47 , V_244 , V_55 ) ) {
F_39 ( V_47 ) ;
return - V_56 ;
}
V_41 = F_27 ( V_7 -> V_8 . V_42 ) -> V_43 ;
V_246 = F_210 ( V_41 ) ;
V_246 |= V_247 | V_248 | V_249 ;
V_246 &= ~ ( V_250 | V_251 ) ;
V_49 = V_47 -> V_57 ;
V_47 -> V_252 = 0 ;
for ( V_50 = 0 ; V_50 < V_244 ; V_50 ++ ) {
V_53 = F_211 ( V_41 , V_50 , V_246 ) ;
if ( F_30 ( V_53 ) ) {
F_186 ( V_16 ,
V_244 ,
V_222 |
V_223 |
V_224 ) ;
V_53 = F_211 ( V_41 , V_50 , V_246 ) ;
}
if ( F_30 ( V_53 ) ) {
F_187 ( V_16 ) ;
V_53 = F_29 ( V_41 , V_50 ) ;
if ( F_30 ( V_53 ) )
goto V_253;
}
#ifdef F_212
if ( F_213 () ) {
V_47 -> V_252 ++ ;
F_214 ( V_49 , V_53 , V_52 , 0 ) ;
V_49 = F_215 ( V_49 ) ;
continue;
}
#endif
if ( ! V_50 || F_216 ( V_53 ) != V_245 + 1 ) {
if ( V_50 )
V_49 = F_215 ( V_49 ) ;
V_47 -> V_252 ++ ;
F_214 ( V_49 , V_53 , V_52 , 0 ) ;
} else {
V_49 -> V_59 += V_52 ;
}
V_245 = F_216 ( V_53 ) ;
F_16 ( ( V_246 & V_254 ) && ( V_245 >= 0x00100000UL ) ) ;
}
#ifdef F_212
if ( ! F_213 () )
#endif
F_217 ( V_49 ) ;
V_7 -> V_61 = V_47 ;
if ( F_28 ( V_7 ) )
F_218 ( V_7 ) ;
if ( V_7 -> V_11 != V_141 &&
V_16 -> V_255 & V_256 )
F_84 ( V_7 ) ;
return 0 ;
V_253:
F_217 ( V_49 ) ;
F_95 (st->sgl, &sg_iter, st->nents, 0 )
F_35 ( F_96 ( & V_115 ) ) ;
F_47 ( V_47 ) ;
F_39 ( V_47 ) ;
if ( F_31 ( V_53 ) == - V_142 )
return - V_56 ;
else
return F_31 ( V_53 ) ;
}
int
F_58 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
const struct V_228 * V_79 = V_7 -> V_79 ;
int V_23 ;
if ( V_7 -> V_61 )
return 0 ;
if ( V_7 -> V_63 != V_71 ) {
F_191 ( L_5 ) ;
return - V_78 ;
}
F_43 ( V_7 -> V_229 ) ;
V_23 = V_79 -> V_257 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_219 ( & V_7 -> V_230 , & V_16 -> V_18 . V_237 ) ;
return 0 ;
}
static void
F_220 ( struct V_6 * V_7 ,
struct V_146 * V_147 )
{
T_6 V_148 = F_221 ( V_147 ) ;
F_43 ( V_147 == NULL ) ;
if ( V_7 -> V_147 != V_147 && V_7 -> V_184 ) {
V_7 -> V_184 = V_148 ;
}
V_7 -> V_147 = V_147 ;
if ( ! V_7 -> V_30 ) {
F_51 ( & V_7 -> V_8 ) ;
V_7 -> V_30 = 1 ;
}
F_206 ( & V_7 -> V_258 , & V_147 -> V_259 ) ;
V_7 -> V_186 = V_148 ;
}
void F_222 ( struct V_72 * V_73 ,
struct V_146 * V_147 )
{
F_206 ( & V_73 -> V_260 , & V_73 -> V_261 -> V_259 ) ;
return F_220 ( V_73 -> V_7 , V_147 ) ;
}
static void
F_223 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_262 * V_261 ;
struct V_72 * V_73 ;
F_43 ( V_7 -> V_8 . V_66 & ~ V_188 ) ;
F_43 ( ! V_7 -> V_30 ) ;
F_22 (vm, &dev_priv->vm_list, global_link) {
V_73 = F_224 ( V_7 , V_261 ) ;
if ( V_73 && ! F_203 ( & V_73 -> V_260 ) )
F_206 ( & V_73 -> V_260 , & V_261 -> V_263 ) ;
}
F_225 ( V_7 , true ) ;
F_226 ( & V_7 -> V_258 ) ;
V_7 -> V_147 = NULL ;
V_7 -> V_186 = 0 ;
V_7 -> V_184 = 0 ;
V_7 -> V_8 . V_66 = 0 ;
V_7 -> V_264 = 0 ;
V_7 -> V_30 = 0 ;
F_55 ( & V_7 -> V_8 ) ;
F_16 ( F_17 ( V_2 ) ) ;
}
static void
F_83 ( struct V_6 * V_7 )
{
struct V_146 * V_147 = V_7 -> V_147 ;
if ( V_147 == NULL )
return;
if ( F_144 ( V_147 -> V_163 ( V_147 , true ) ,
V_7 -> V_186 ) )
F_223 ( V_7 ) ;
}
static int
F_227 ( struct V_1 * V_2 , T_6 V_148 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_146 * V_147 ;
int V_23 , V_50 , V_265 ;
F_228 (ring, dev_priv, i) {
V_23 = F_229 ( V_147 ) ;
if ( V_23 )
return V_23 ;
}
F_230 ( V_2 ) ;
F_228 (ring, dev_priv, i) {
F_231 ( V_147 , V_148 ) ;
for ( V_265 = 0 ; V_265 < F_232 ( V_147 -> V_266 . V_267 ) ; V_265 ++ )
V_147 -> V_266 . V_267 [ V_265 ] = 0 ;
}
return 0 ;
}
int F_233 ( struct V_1 * V_2 , T_6 V_148 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( V_148 == 0 )
return - V_51 ;
V_23 = F_227 ( V_2 , V_148 - 1 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_268 = V_148 ;
V_16 -> V_269 = V_148 - 1 ;
if ( V_16 -> V_269 == 0 )
V_16 -> V_269 -- ;
return 0 ;
}
int
F_234 ( struct V_1 * V_2 , T_6 * V_148 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( V_16 -> V_268 == 0 ) {
int V_23 = F_227 ( V_2 , 0 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_268 = 1 ;
}
* V_148 = V_16 -> V_269 = V_16 -> V_268 ++ ;
return 0 ;
}
int F_235 ( struct V_146 * V_147 ,
struct V_32 * V_33 ,
struct V_6 * V_7 ,
T_6 * V_270 )
{
struct V_15 * V_16 = V_147 -> V_2 -> V_27 ;
struct V_271 * V_272 ;
struct V_273 * V_274 ;
T_6 V_275 , V_276 ;
int V_23 ;
V_272 = V_147 -> V_277 ;
if ( F_16 ( V_272 == NULL ) )
return - V_56 ;
if ( V_117 . V_278 ) {
struct V_279 * V_280 = V_272 -> V_280 ;
V_274 = V_280 -> V_281 [ V_147 -> V_151 ] . V_274 ;
} else
V_274 = V_147 -> V_282 ;
V_276 = F_236 ( V_274 ) ;
if ( V_117 . V_278 ) {
V_23 = F_237 ( V_274 ) ;
if ( V_23 )
return V_23 ;
} else {
V_23 = F_238 ( V_147 ) ;
if ( V_23 )
return V_23 ;
}
V_275 = F_236 ( V_274 ) ;
if ( V_117 . V_278 ) {
V_23 = V_147 -> V_283 ( V_274 ) ;
if ( V_23 )
return V_23 ;
} else {
V_23 = V_147 -> V_284 ( V_147 ) ;
if ( V_23 )
return V_23 ;
}
V_272 -> V_148 = F_221 ( V_147 ) ;
V_272 -> V_147 = V_147 ;
V_272 -> V_285 = V_276 ;
V_272 -> V_286 = V_275 ;
V_272 -> V_287 = V_7 ;
if ( ! V_117 . V_278 ) {
V_272 -> V_280 = V_147 -> V_288 ;
if ( V_272 -> V_280 )
F_239 ( V_272 -> V_280 ) ;
}
V_272 -> V_289 = V_164 ;
F_219 ( & V_272 -> V_234 , & V_147 -> V_290 ) ;
V_272 -> V_82 = NULL ;
if ( V_33 ) {
struct V_153 * V_82 = V_33 -> V_189 ;
F_7 ( & V_82 -> V_18 . V_291 ) ;
V_272 -> V_82 = V_82 ;
F_219 ( & V_272 -> V_292 ,
& V_82 -> V_18 . V_290 ) ;
F_8 ( & V_82 -> V_18 . V_291 ) ;
}
F_240 ( V_147 , V_272 -> V_148 ) ;
V_147 -> V_149 = 0 ;
V_147 -> V_277 = NULL ;
F_241 ( V_147 -> V_2 ) ;
F_242 ( & V_16 -> V_18 . V_169 ) ;
F_243 ( V_16 -> V_168 ,
& V_16 -> V_18 . V_293 ,
F_244 ( V_25 ) ) ;
F_245 ( V_16 -> V_2 ) ;
if ( V_270 )
* V_270 = V_272 -> V_148 ;
return 0 ;
}
static inline void
F_246 ( struct V_271 * V_272 )
{
struct V_153 * V_82 = V_272 -> V_82 ;
if ( ! V_82 )
return;
F_7 ( & V_82 -> V_18 . V_291 ) ;
F_201 ( & V_272 -> V_292 ) ;
V_272 -> V_82 = NULL ;
F_8 ( & V_82 -> V_18 . V_291 ) ;
}
static bool F_247 ( struct V_15 * V_16 ,
const struct V_279 * V_280 )
{
unsigned long V_294 ;
V_294 = F_248 () - V_280 -> V_295 . V_296 ;
if ( V_280 -> V_295 . V_297 )
return true ;
if ( V_294 <= V_298 ) {
if ( ! F_249 ( V_280 ) ) {
F_191 ( L_6 ) ;
return true ;
} else if ( F_250 ( V_16 ) ) {
if ( F_251 ( V_16 ) )
F_13 ( L_7 ) ;
return true ;
}
}
return false ;
}
static void F_252 ( struct V_15 * V_16 ,
struct V_279 * V_280 ,
const bool V_299 )
{
struct V_300 * V_301 ;
if ( F_16 ( ! V_280 ) )
return;
V_301 = & V_280 -> V_295 ;
if ( V_299 ) {
V_301 -> V_297 = F_247 ( V_16 , V_280 ) ;
V_301 -> V_302 ++ ;
V_301 -> V_296 = F_248 () ;
} else {
V_301 -> V_303 ++ ;
}
}
static void F_253 ( struct V_271 * V_272 )
{
struct V_279 * V_280 = V_272 -> V_280 ;
F_201 ( & V_272 -> V_234 ) ;
F_246 ( V_272 ) ;
if ( V_280 ) {
if ( V_117 . V_278 ) {
struct V_146 * V_147 = V_272 -> V_147 ;
if ( V_280 != V_147 -> V_304 )
F_254 ( V_147 , V_280 ) ;
}
F_255 ( V_280 ) ;
}
F_39 ( V_272 ) ;
}
struct V_271 *
F_256 ( struct V_146 * V_147 )
{
struct V_271 * V_272 ;
T_6 V_305 ;
V_305 = V_147 -> V_163 ( V_147 , false ) ;
F_22 (request, &ring->request_list, list) {
if ( F_144 ( V_305 , V_272 -> V_148 ) )
continue;
return V_272 ;
}
return NULL ;
}
static void F_257 ( struct V_15 * V_16 ,
struct V_146 * V_147 )
{
struct V_271 * V_272 ;
bool V_306 ;
V_272 = F_256 ( V_147 ) ;
if ( V_272 == NULL )
return;
V_306 = V_147 -> V_307 . V_308 >= V_309 ;
F_252 ( V_16 , V_272 -> V_280 , V_306 ) ;
F_258 (request, &ring->request_list, list)
F_252 ( V_16 , V_272 -> V_280 , false ) ;
}
static void F_259 ( struct V_15 * V_16 ,
struct V_146 * V_147 )
{
while ( ! F_203 ( & V_147 -> V_259 ) ) {
struct V_6 * V_7 ;
V_7 = F_204 ( & V_147 -> V_259 ,
struct V_6 ,
V_258 ) ;
F_223 ( V_7 ) ;
}
while ( ! F_203 ( & V_147 -> V_310 ) ) {
struct V_311 * V_312 ;
V_312 = F_204 ( & V_147 -> V_310 ,
struct V_311 ,
V_313 ) ;
F_201 ( & V_312 -> V_313 ) ;
F_125 ( V_16 ) ;
F_255 ( V_312 -> V_280 ) ;
F_39 ( V_312 ) ;
}
while ( ! F_203 ( & V_147 -> V_290 ) ) {
struct V_271 * V_272 ;
V_272 = F_204 ( & V_147 -> V_290 ,
struct V_271 ,
V_234 ) ;
F_253 ( V_272 ) ;
}
F_39 ( V_147 -> V_277 ) ;
V_147 -> V_277 = NULL ;
V_147 -> V_149 = 0 ;
}
void F_260 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_16 -> V_314 ; V_50 ++ ) {
struct V_315 * V_316 = & V_16 -> V_317 [ V_50 ] ;
if ( V_316 -> V_7 ) {
F_261 ( V_316 -> V_7 , V_316 ,
V_316 -> V_7 -> V_11 ) ;
} else {
F_262 ( V_2 , V_50 , NULL ) ;
}
}
}
void F_263 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_146 * V_147 ;
int V_50 ;
F_228 (ring, dev_priv, i)
F_257 ( V_16 , V_147 ) ;
F_228 (ring, dev_priv, i)
F_259 ( V_16 , V_147 ) ;
F_264 ( V_2 ) ;
F_260 ( V_2 ) ;
}
void
F_265 ( struct V_146 * V_147 )
{
T_5 V_148 ;
if ( F_203 ( & V_147 -> V_290 ) )
return;
F_16 ( F_17 ( V_147 -> V_2 ) ) ;
V_148 = V_147 -> V_163 ( V_147 , true ) ;
while ( ! F_203 ( & V_147 -> V_259 ) ) {
struct V_6 * V_7 ;
V_7 = F_204 ( & V_147 -> V_259 ,
struct V_6 ,
V_258 ) ;
if ( ! F_144 ( V_148 , V_7 -> V_186 ) )
break;
F_223 ( V_7 ) ;
}
while ( ! F_203 ( & V_147 -> V_290 ) ) {
struct V_271 * V_272 ;
struct V_273 * V_274 ;
V_272 = F_204 ( & V_147 -> V_290 ,
struct V_271 ,
V_234 ) ;
if ( ! F_144 ( V_148 , V_272 -> V_148 ) )
break;
F_266 ( V_147 , V_272 -> V_148 ) ;
if ( V_117 . V_278 ) {
struct V_279 * V_280 = V_272 -> V_280 ;
V_274 = V_280 -> V_281 [ V_147 -> V_151 ] . V_274 ;
} else
V_274 = V_147 -> V_282 ;
V_274 -> V_318 = V_272 -> V_286 ;
F_253 ( V_272 ) ;
}
if ( F_86 ( V_147 -> V_319 &&
F_144 ( V_148 , V_147 -> V_319 ) ) ) {
V_147 -> V_182 ( V_147 ) ;
V_147 -> V_319 = 0 ;
}
F_16 ( F_17 ( V_147 -> V_2 ) ) ;
}
bool
F_230 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_146 * V_147 ;
bool V_320 = true ;
int V_50 ;
F_228 (ring, dev_priv, i) {
F_265 ( V_147 ) ;
V_320 &= F_203 ( & V_147 -> V_290 ) ;
if ( V_117 . V_278 ) {
unsigned long V_205 ;
F_267 ( & V_147 -> V_321 , V_205 ) ;
V_320 &= F_203 ( & V_147 -> V_310 ) ;
F_268 ( & V_147 -> V_321 , V_205 ) ;
F_269 ( V_147 ) ;
}
}
if ( V_320 )
F_148 ( V_16 -> V_168 ,
& V_16 -> V_18 . V_169 ,
F_149 ( 100 ) ) ;
return V_320 ;
}
static void
F_270 ( struct V_322 * V_323 )
{
struct V_15 * V_16 =
F_271 ( V_323 , F_205 ( * V_16 ) , V_18 . V_293 . V_323 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_320 ;
V_320 = false ;
if ( F_272 ( & V_2 -> V_29 ) ) {
V_320 = F_230 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
}
if ( ! V_320 )
F_243 ( V_16 -> V_168 , & V_16 -> V_18 . V_293 ,
F_244 ( V_25 ) ) ;
}
static void
F_273 ( struct V_322 * V_323 )
{
struct V_15 * V_16 =
F_271 ( V_323 , F_205 ( * V_16 ) , V_18 . V_169 . V_323 ) ;
F_274 ( V_16 -> V_2 ) ;
}
static int
F_275 ( struct V_6 * V_7 )
{
int V_23 ;
if ( V_7 -> V_30 ) {
V_23 = F_129 ( V_7 -> V_147 , V_7 -> V_186 ) ;
if ( V_23 )
return V_23 ;
F_265 ( V_7 -> V_147 ) ;
}
return 0 ;
}
int
F_276 ( struct V_1 * V_2 , void * V_31 , struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_324 * args = V_31 ;
struct V_6 * V_7 ;
struct V_146 * V_147 = NULL ;
unsigned V_155 ;
T_6 V_148 = 0 ;
int V_23 = 0 ;
if ( args -> V_205 != 0 )
return - V_51 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_33 , args -> V_325 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_25 ( & V_2 -> V_29 ) ;
return - V_121 ;
}
V_23 = F_275 ( V_7 ) ;
if ( V_23 )
goto V_119;
if ( V_7 -> V_30 ) {
V_148 = V_7 -> V_186 ;
V_147 = V_7 -> V_147 ;
}
if ( V_148 == 0 )
goto V_119;
if ( args -> V_326 <= 0 ) {
V_23 = - V_179 ;
goto V_119;
}
F_55 ( & V_7 -> V_8 ) ;
V_155 = F_153 ( & V_16 -> V_28 . V_155 ) ;
F_25 ( & V_2 -> V_29 ) ;
return F_138 ( V_147 , V_148 , V_155 , true ,
& args -> V_326 , V_33 -> V_189 ) ;
V_119:
F_55 ( & V_7 -> V_8 ) ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_277 ( struct V_6 * V_7 ,
struct V_146 * V_327 )
{
struct V_146 * V_328 = V_7 -> V_147 ;
T_6 V_148 ;
int V_23 , V_329 ;
if ( V_328 == NULL || V_327 == V_328 )
return 0 ;
if ( V_327 == NULL || ! F_278 ( V_7 -> V_8 . V_2 ) )
return F_61 ( V_7 , false ) ;
V_329 = F_279 ( V_328 , V_327 ) ;
V_148 = V_7 -> V_186 ;
if ( V_148 <= V_328 -> V_266 . V_267 [ V_329 ] )
return 0 ;
V_23 = F_129 ( V_7 -> V_147 , V_148 ) ;
if ( V_23 )
return V_23 ;
F_280 ( V_328 , V_327 , V_148 ) ;
V_23 = V_327 -> V_266 . V_330 ( V_327 , V_328 , V_148 ) ;
if ( ! V_23 )
V_328 -> V_266 . V_267 [ V_329 ] = V_7 -> V_186 ;
return V_23 ;
}
static void F_281 ( struct V_6 * V_7 )
{
T_6 V_331 , V_332 ;
F_5 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_65 & V_191 ) == 0 )
return;
F_282 () ;
V_332 = V_7 -> V_8 . V_65 ;
V_331 = V_7 -> V_8 . V_66 ;
V_7 -> V_8 . V_65 &= ~ V_191 ;
V_7 -> V_8 . V_66 &= ~ V_191 ;
F_283 ( V_7 ,
V_332 ,
V_331 ) ;
}
int F_53 ( struct V_72 * V_73 )
{
struct V_6 * V_7 = V_73 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_203 ( & V_73 -> V_333 ) )
return 0 ;
if ( ! F_284 ( & V_73 -> V_334 ) ) {
F_285 ( V_73 ) ;
return 0 ;
}
if ( V_73 -> V_335 )
return - V_77 ;
F_43 ( V_7 -> V_61 == NULL ) ;
V_23 = F_286 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_83 ( V_7 ) ;
if ( F_287 ( V_73 -> V_261 ) ) {
F_281 ( V_7 ) ;
V_23 = F_113 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
F_288 ( V_73 ) ;
V_73 -> V_336 ( V_73 ) ;
F_226 ( & V_73 -> V_260 ) ;
if ( F_287 ( V_73 -> V_261 ) )
V_7 -> V_337 = false ;
F_289 ( & V_73 -> V_334 ) ;
F_285 ( V_73 ) ;
if ( F_203 ( & V_7 -> V_338 ) ) {
F_290 ( V_7 ) ;
F_206 ( & V_7 -> V_230 , & V_16 -> V_18 . V_237 ) ;
}
F_101 ( V_7 ) ;
return 0 ;
}
int F_291 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_146 * V_147 ;
int V_23 , V_50 ;
F_228 (ring, dev_priv, i) {
if ( ! V_117 . V_278 ) {
V_23 = F_292 ( V_147 , V_147 -> V_304 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_229 ( V_147 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static void F_293 ( struct V_1 * V_2 , int V_316 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_13 ;
int V_339 ;
if ( F_146 ( V_2 ) -> V_166 >= 6 ) {
V_13 = V_340 ;
V_339 = V_341 ;
} else {
V_13 = V_342 ;
V_339 = V_343 ;
}
V_13 += V_316 * 8 ;
F_294 ( V_13 , 0 ) ;
F_295 ( V_13 ) ;
if ( V_7 ) {
T_6 V_17 = F_24 ( V_7 ) ;
T_4 V_344 ;
if ( V_7 -> V_11 != V_141 ) {
T_5 V_345 = V_7 -> V_346 *
( V_7 -> V_11 == V_347 ? 32 : 8 ) ;
V_17 = ( V_17 / V_345 ) * V_345 ;
}
V_344 = ( T_4 ) ( ( F_114 ( V_7 ) + V_17 - 4096 ) &
0xfffff000 ) << 32 ;
V_344 |= F_114 ( V_7 ) & 0xfffff000 ;
V_344 |= ( T_4 ) ( ( V_7 -> V_346 / 128 ) - 1 ) << V_339 ;
if ( V_7 -> V_11 == V_347 )
V_344 |= 1 << V_348 ;
V_344 |= V_349 ;
F_294 ( V_13 + 4 , V_344 >> 32 ) ;
F_295 ( V_13 + 4 ) ;
F_294 ( V_13 + 0 , V_344 ) ;
F_295 ( V_13 ) ;
} else {
F_294 ( V_13 + 4 , 0 ) ;
F_295 ( V_13 + 4 ) ;
}
}
static void F_296 ( struct V_1 * V_2 , int V_316 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_344 ;
if ( V_7 ) {
T_6 V_17 = F_24 ( V_7 ) ;
int V_350 ;
int V_351 ;
F_142 ( ( F_114 ( V_7 ) & ~ V_352 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_114 ( V_7 ) & ( V_17 - 1 ) ) ,
L_8 ,
F_114 ( V_7 ) , V_7 -> V_337 , V_17 ) ;
if ( V_7 -> V_11 == V_347 && F_297 ( V_2 ) )
V_351 = 128 ;
else
V_351 = 512 ;
V_350 = V_7 -> V_346 / V_351 ;
V_350 = F_298 ( V_350 ) - 1 ;
V_344 = F_114 ( V_7 ) ;
if ( V_7 -> V_11 == V_347 )
V_344 |= 1 << V_353 ;
V_344 |= F_299 ( V_17 ) ;
V_344 |= V_350 << V_354 ;
V_344 |= V_355 ;
} else
V_344 = 0 ;
if ( V_316 < 8 )
V_316 = V_356 + V_316 * 4 ;
else
V_316 = V_357 + ( V_316 - 8 ) * 4 ;
F_294 ( V_316 , V_344 ) ;
F_295 ( V_316 ) ;
}
static void F_300 ( struct V_1 * V_2 , int V_316 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_5 V_344 ;
if ( V_7 ) {
T_6 V_17 = F_24 ( V_7 ) ;
T_5 V_350 ;
F_142 ( ( F_114 ( V_7 ) & ~ V_358 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_114 ( V_7 ) & ( V_17 - 1 ) ) ,
L_9 ,
F_114 ( V_7 ) , V_17 ) ;
V_350 = V_7 -> V_346 / 128 ;
V_350 = F_298 ( V_350 ) - 1 ;
V_344 = F_114 ( V_7 ) ;
if ( V_7 -> V_11 == V_347 )
V_344 |= 1 << V_353 ;
V_344 |= F_301 ( V_17 ) ;
V_344 |= V_350 << V_354 ;
V_344 |= V_355 ;
} else
V_344 = 0 ;
F_294 ( V_356 + V_316 * 4 , V_344 ) ;
F_295 ( V_356 + V_316 * 4 ) ;
}
inline static bool F_302 ( struct V_6 * V_7 )
{
return V_7 && V_7 -> V_8 . V_65 & V_191 ;
}
static void F_262 ( struct V_1 * V_2 , int V_316 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_302 ( V_16 -> V_317 [ V_316 ] . V_7 ) )
F_282 () ;
F_142 ( V_7 && ( ! V_7 -> V_346 || ! V_7 -> V_11 ) ,
L_10 ,
V_7 -> V_346 , V_7 -> V_11 ) ;
switch ( F_146 ( V_2 ) -> V_166 ) {
case 9 :
case 8 :
case 7 :
case 6 :
case 5 :
case 4 : F_293 ( V_2 , V_316 , V_7 ) ; break;
case 3 : F_296 ( V_2 , V_316 , V_7 ) ; break;
case 2 : F_300 ( V_2 , V_316 , V_7 ) ; break;
default: F_303 () ;
}
if ( F_302 ( V_7 ) )
F_282 () ;
}
static inline int F_304 ( struct V_15 * V_16 ,
struct V_315 * V_359 )
{
return V_359 - V_16 -> V_317 ;
}
static void F_261 ( struct V_6 * V_7 ,
struct V_315 * V_359 ,
bool V_360 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_316 = F_304 ( V_16 , V_359 ) ;
F_262 ( V_7 -> V_8 . V_2 , V_316 , V_360 ? V_7 : NULL ) ;
if ( V_360 ) {
V_7 -> V_13 = V_316 ;
V_359 -> V_7 = V_7 ;
F_206 ( & V_359 -> V_361 , & V_16 -> V_18 . V_362 ) ;
} else {
V_7 -> V_13 = V_14 ;
V_359 -> V_7 = NULL ;
F_226 ( & V_359 -> V_361 ) ;
}
V_7 -> V_12 = false ;
}
static int
F_305 ( struct V_6 * V_7 )
{
if ( V_7 -> V_264 ) {
int V_23 = F_164 ( V_7 -> V_147 , V_7 -> V_264 ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_264 = 0 ;
}
return 0 ;
}
int
F_113 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_315 * V_359 ;
int V_23 ;
V_23 = F_305 ( V_7 ) ;
if ( V_23 )
return V_23 ;
if ( V_7 -> V_13 == V_14 )
return 0 ;
V_359 = & V_16 -> V_317 [ V_7 -> V_13 ] ;
if ( F_16 ( V_359 -> V_335 ) )
return - V_77 ;
F_4 ( V_7 ) ;
F_261 ( V_7 , V_359 , false ) ;
return 0 ;
}
static struct V_315 *
F_306 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_315 * V_316 , * V_363 ;
int V_50 ;
V_363 = NULL ;
for ( V_50 = V_16 -> V_364 ; V_50 < V_16 -> V_314 ; V_50 ++ ) {
V_316 = & V_16 -> V_317 [ V_50 ] ;
if ( ! V_316 -> V_7 )
return V_316 ;
if ( ! V_316 -> V_335 )
V_363 = V_316 ;
}
if ( V_363 == NULL )
goto V_365;
F_22 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_316 -> V_335 )
continue;
return V_316 ;
}
V_365:
if ( F_307 ( V_2 ) )
return F_308 ( - V_145 ) ;
return F_308 ( - V_366 ) ;
}
int
F_174 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_360 = V_7 -> V_11 != V_141 ;
struct V_315 * V_316 ;
int V_23 ;
if ( V_7 -> V_12 ) {
V_23 = F_305 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_7 -> V_13 != V_14 ) {
V_316 = & V_16 -> V_317 [ V_7 -> V_13 ] ;
if ( ! V_7 -> V_12 ) {
F_206 ( & V_316 -> V_361 ,
& V_16 -> V_18 . V_362 ) ;
return 0 ;
}
} else if ( V_360 ) {
if ( F_16 ( ! V_7 -> V_337 ) )
return - V_51 ;
V_316 = F_306 ( V_2 ) ;
if ( F_30 ( V_316 ) )
return F_31 ( V_316 ) ;
if ( V_316 -> V_7 ) {
struct V_6 * V_367 = V_316 -> V_7 ;
V_23 = F_305 ( V_367 ) ;
if ( V_23 )
return V_23 ;
F_4 ( V_367 ) ;
}
} else
return 0 ;
F_261 ( V_7 , V_316 , V_360 ) ;
return 0 ;
}
static bool F_309 ( struct V_72 * V_73 ,
unsigned long V_9 )
{
struct V_368 * V_369 = & V_73 -> V_334 ;
struct V_368 * V_370 ;
if ( V_73 -> V_261 -> V_18 . V_371 == NULL )
return true ;
if ( ! F_284 ( V_369 ) )
return true ;
if ( F_203 ( & V_369 -> V_372 ) )
return true ;
V_370 = F_310 ( V_369 -> V_372 . V_373 , struct V_368 , V_372 ) ;
if ( V_370 -> V_374 && ! V_370 -> V_375 && V_370 -> V_376 != V_9 )
return false ;
V_370 = F_310 ( V_369 -> V_372 . V_74 , struct V_368 , V_372 ) ;
if ( V_370 -> V_374 && ! V_369 -> V_375 && V_370 -> V_376 != V_9 )
return false ;
return true ;
}
static struct V_72 *
F_311 ( struct V_6 * V_7 ,
struct V_262 * V_261 ,
unsigned V_377 ,
T_4 V_205 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_17 , V_378 , V_379 , V_380 ;
unsigned long V_108 =
V_205 & V_381 ? V_205 & V_382 : 0 ;
unsigned long V_109 =
V_205 & V_128 ? V_16 -> V_37 . V_225 : V_261 -> V_38 ;
struct V_72 * V_73 ;
int V_23 ;
V_378 = F_180 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ) ;
V_379 = F_181 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , true ) ;
V_380 =
F_181 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , false ) ;
if ( V_377 == 0 )
V_377 = V_205 & V_128 ? V_379 :
V_380 ;
if ( V_205 & V_128 && V_377 & ( V_379 - 1 ) ) {
F_191 ( L_11 , V_377 ) ;
return F_308 ( - V_51 ) ;
}
V_17 = V_205 & V_128 ? V_378 : V_7 -> V_8 . V_17 ;
if ( V_7 -> V_8 . V_17 > V_109 ) {
F_191 ( L_12 ,
V_7 -> V_8 . V_17 ,
V_205 & V_128 ? L_13 : L_14 ,
V_109 ) ;
return F_308 ( - V_226 ) ;
}
V_23 = F_58 ( V_7 ) ;
if ( V_23 )
return F_308 ( V_23 ) ;
F_84 ( V_7 ) ;
V_73 = F_312 ( V_7 , V_261 ) ;
if ( F_30 ( V_73 ) )
goto V_383;
V_384:
V_23 = F_313 ( & V_261 -> V_18 , & V_73 -> V_334 ,
V_17 , V_377 ,
V_7 -> V_9 ,
V_108 , V_109 ,
V_385 ,
V_386 ) ;
if ( V_23 ) {
V_23 = F_314 ( V_2 , V_261 , V_17 , V_377 ,
V_7 -> V_9 ,
V_108 , V_109 ,
V_205 ) ;
if ( V_23 == 0 )
goto V_384;
goto V_387;
}
if ( F_16 ( ! F_309 ( V_73 , V_7 -> V_9 ) ) ) {
V_23 = - V_51 ;
goto V_388;
}
V_23 = F_315 ( V_7 ) ;
if ( V_23 )
goto V_388;
F_206 ( & V_7 -> V_230 , & V_16 -> V_18 . V_238 ) ;
F_219 ( & V_73 -> V_260 , & V_261 -> V_263 ) ;
F_316 ( V_73 , V_205 ) ;
V_73 -> V_389 ( V_73 , V_7 -> V_9 ,
V_205 & V_390 ? V_391 : 0 ) ;
return V_73 ;
V_388:
F_289 ( & V_73 -> V_334 ) ;
V_387:
F_285 ( V_73 ) ;
V_73 = F_308 ( V_23 ) ;
V_383:
F_101 ( V_7 ) ;
return V_73 ;
}
bool
F_120 ( struct V_6 * V_7 ,
bool V_392 )
{
if ( V_7 -> V_61 == NULL )
return false ;
if ( V_7 -> V_393 || V_7 -> V_45 )
return false ;
if ( ! V_392 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) )
return false ;
F_317 ( V_7 ) ;
F_318 ( V_7 -> V_61 ) ;
return true ;
}
static void
F_319 ( struct V_6 * V_7 )
{
T_5 V_331 ;
if ( V_7 -> V_8 . V_66 != V_191 )
return;
F_320 () ;
V_331 = V_7 -> V_8 . V_66 ;
V_7 -> V_8 . V_66 = 0 ;
F_225 ( V_7 , false ) ;
F_283 ( V_7 ,
V_7 -> V_8 . V_65 ,
V_331 ) ;
}
static void
F_169 ( struct V_6 * V_7 ,
bool V_392 )
{
T_5 V_331 ;
if ( V_7 -> V_8 . V_66 != V_67 )
return;
if ( F_120 ( V_7 , V_392 ) )
F_36 ( V_7 -> V_8 . V_2 ) ;
V_331 = V_7 -> V_8 . V_66 ;
V_7 -> V_8 . V_66 = 0 ;
F_225 ( V_7 , false ) ;
F_283 ( V_7 ,
V_7 -> V_8 . V_65 ,
V_331 ) ;
}
int
F_112 ( struct V_6 * V_7 , bool V_204 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_72 * V_73 = F_321 ( V_7 ) ;
T_5 V_331 , V_332 ;
int V_23 ;
if ( V_73 == NULL )
return - V_51 ;
if ( V_7 -> V_8 . V_66 == V_191 )
return 0 ;
V_23 = F_61 ( V_7 , ! V_204 ) ;
if ( V_23 )
return V_23 ;
F_83 ( V_7 ) ;
F_169 ( V_7 , false ) ;
if ( ( V_7 -> V_8 . V_65 & V_191 ) == 0 )
F_282 () ;
V_331 = V_7 -> V_8 . V_66 ;
V_332 = V_7 -> V_8 . V_65 ;
F_43 ( ( V_7 -> V_8 . V_66 & ~ V_191 ) != 0 ) ;
V_7 -> V_8 . V_65 |= V_191 ;
if ( V_204 ) {
V_7 -> V_8 . V_65 = V_191 ;
V_7 -> V_8 . V_66 = V_191 ;
V_7 -> V_69 = 1 ;
}
if ( V_204 )
F_322 ( V_7 , NULL ) ;
F_283 ( V_7 ,
V_332 ,
V_331 ) ;
if ( F_18 ( V_7 ) )
F_206 ( & V_73 -> V_260 ,
& V_16 -> V_37 . V_8 . V_263 ) ;
return 0 ;
}
int F_323 ( struct V_6 * V_7 ,
enum V_3 V_9 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_72 * V_73 , * V_74 ;
int V_23 ;
if ( V_7 -> V_9 == V_9 )
return 0 ;
if ( F_23 ( V_7 ) ) {
F_191 ( L_15 ) ;
return - V_77 ;
}
F_52 (vma, next, &obj->vma_list, vma_link) {
if ( ! F_309 ( V_73 , V_9 ) ) {
V_23 = F_53 ( V_73 ) ;
if ( V_23 )
return V_23 ;
}
}
if ( F_19 ( V_7 ) ) {
V_23 = F_286 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_281 ( V_7 ) ;
if ( F_146 ( V_2 ) -> V_166 < 6 ) {
V_23 = F_113 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
F_22 (vma, &obj->vma_list, vma_link)
if ( F_284 ( & V_73 -> V_334 ) )
V_73 -> V_389 ( V_73 , V_9 ,
V_73 -> V_394 & V_391 ) ;
}
F_22 (vma, &obj->vma_list, vma_link)
V_73 -> V_334 . V_376 = V_9 ;
V_7 -> V_9 = V_9 ;
if ( F_3 ( V_7 ) ) {
T_6 V_332 , V_331 ;
F_83 ( V_7 ) ;
F_16 ( V_7 -> V_8 . V_66 & ~ V_67 ) ;
V_332 = V_7 -> V_8 . V_65 ;
V_331 = V_7 -> V_8 . V_66 ;
V_7 -> V_8 . V_65 = V_67 ;
V_7 -> V_8 . V_66 = V_67 ;
F_283 ( V_7 ,
V_332 ,
V_331 ) ;
}
return 0 ;
}
int F_324 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_395 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_33 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
switch ( V_7 -> V_9 ) {
case V_396 :
case V_397 :
args -> V_398 = V_399 ;
break;
case V_400 :
args -> V_398 = V_401 ;
break;
default:
args -> V_398 = V_402 ;
break;
}
F_55 ( & V_7 -> V_8 ) ;
V_122:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_325 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_395 * args = V_31 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_23 ;
switch ( args -> V_398 ) {
case V_402 :
V_4 = V_5 ;
break;
case V_399 :
V_4 = V_396 ;
break;
case V_401 :
V_4 = F_326 ( V_2 ) ? V_400 : V_5 ;
break;
default:
return - V_51 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_33 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
V_23 = F_323 ( V_7 , V_4 ) ;
F_55 ( & V_7 -> V_8 ) ;
V_122:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static bool F_327 ( struct V_6 * V_7 )
{
struct V_72 * V_73 ;
V_73 = F_321 ( V_7 ) ;
if ( ! V_73 )
return false ;
return V_73 -> V_335 - ! ! V_7 -> V_403 ;
}
int
F_328 ( struct V_6 * V_7 ,
T_6 V_377 ,
struct V_146 * V_404 )
{
T_6 V_332 , V_331 ;
bool V_405 ;
int V_23 ;
if ( V_404 != V_7 -> V_147 ) {
V_23 = F_277 ( V_7 , V_404 ) ;
if ( V_23 )
return V_23 ;
}
V_405 = V_7 -> V_10 ;
V_7 -> V_10 = true ;
V_23 = F_323 ( V_7 ,
F_326 ( V_7 -> V_8 . V_2 ) ? V_400 : V_5 ) ;
if ( V_23 )
goto V_406;
V_23 = F_111 ( V_7 , V_377 , V_128 ) ;
if ( V_23 )
goto V_406;
F_169 ( V_7 , true ) ;
V_331 = V_7 -> V_8 . V_66 ;
V_332 = V_7 -> V_8 . V_65 ;
V_7 -> V_8 . V_66 = 0 ;
V_7 -> V_8 . V_65 |= V_191 ;
F_283 ( V_7 ,
V_332 ,
V_331 ) ;
return 0 ;
V_406:
F_16 ( V_405 != F_327 ( V_7 ) ) ;
V_7 -> V_10 = V_405 ;
return V_23 ;
}
void
F_329 ( struct V_6 * V_7 )
{
F_115 ( V_7 ) ;
V_7 -> V_10 = F_327 ( V_7 ) ;
}
int
F_286 ( struct V_6 * V_7 )
{
int V_23 ;
if ( ( V_7 -> V_8 . V_65 & V_188 ) == 0 )
return 0 ;
V_23 = F_61 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_8 . V_65 &= ~ V_188 ;
return 0 ;
}
int
F_44 ( struct V_6 * V_7 , bool V_204 )
{
T_5 V_331 , V_332 ;
int V_23 ;
if ( V_7 -> V_8 . V_66 == V_67 )
return 0 ;
V_23 = F_61 ( V_7 , ! V_204 ) ;
if ( V_23 )
return V_23 ;
F_83 ( V_7 ) ;
F_319 ( V_7 ) ;
V_331 = V_7 -> V_8 . V_66 ;
V_332 = V_7 -> V_8 . V_65 ;
if ( ( V_7 -> V_8 . V_65 & V_67 ) == 0 ) {
F_120 ( V_7 , false ) ;
V_7 -> V_8 . V_65 |= V_67 ;
}
F_43 ( ( V_7 -> V_8 . V_66 & ~ V_67 ) != 0 ) ;
if ( V_204 ) {
V_7 -> V_8 . V_65 = V_67 ;
V_7 -> V_8 . V_66 = V_67 ;
}
if ( V_204 )
F_322 ( V_7 , NULL ) ;
F_283 ( V_7 ,
V_332 ,
V_331 ) ;
return 0 ;
}
static int
F_330 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_153 * V_82 = V_33 -> V_189 ;
unsigned long V_407 = V_164 - F_149 ( 20 ) ;
struct V_271 * V_272 ;
struct V_146 * V_147 = NULL ;
unsigned V_155 ;
T_6 V_148 = 0 ;
int V_23 ;
V_23 = F_10 ( & V_16 -> V_28 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_126 ( & V_16 -> V_28 , false ) ;
if ( V_23 )
return V_23 ;
F_7 ( & V_82 -> V_18 . V_291 ) ;
F_22 (request, &file_priv->mm.request_list, client_list) {
if ( F_155 ( V_272 -> V_289 , V_407 ) )
break;
V_147 = V_272 -> V_147 ;
V_148 = V_272 -> V_148 ;
}
V_155 = F_153 ( & V_16 -> V_28 . V_155 ) ;
F_8 ( & V_82 -> V_18 . V_291 ) ;
if ( V_148 == 0 )
return 0 ;
V_23 = F_138 ( V_147 , V_148 , V_155 , true , NULL , NULL ) ;
if ( V_23 == 0 )
F_243 ( V_16 -> V_168 , & V_16 -> V_18 . V_293 , 0 ) ;
return V_23 ;
}
static bool
F_331 ( struct V_72 * V_73 , T_5 V_377 , T_4 V_205 )
{
struct V_6 * V_7 = V_73 -> V_7 ;
if ( V_377 &&
V_73 -> V_334 . V_108 & ( V_377 - 1 ) )
return true ;
if ( V_205 & V_128 && ! V_7 -> V_337 )
return true ;
if ( V_205 & V_381 &&
V_73 -> V_334 . V_108 < ( V_205 & V_382 ) )
return true ;
return false ;
}
int
F_332 ( struct V_6 * V_7 ,
struct V_262 * V_261 ,
T_5 V_377 ,
T_4 V_205 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_72 * V_73 ;
unsigned V_394 ;
int V_23 ;
if ( F_16 ( V_261 == & V_16 -> V_18 . V_408 -> V_8 ) )
return - V_171 ;
if ( F_16 ( V_205 & ( V_390 | V_128 ) && ! F_287 ( V_261 ) ) )
return - V_51 ;
if ( F_16 ( ( V_205 & ( V_128 | V_390 ) ) == V_128 ) )
return - V_51 ;
V_73 = F_224 ( V_7 , V_261 ) ;
if ( V_73 ) {
if ( F_16 ( V_73 -> V_335 == V_409 ) )
return - V_77 ;
if ( F_331 ( V_73 , V_377 , V_205 ) ) {
F_142 ( V_73 -> V_335 ,
L_16
L_17
L_18 ,
F_333 ( V_7 , V_261 ) , V_377 ,
! ! ( V_205 & V_128 ) ,
V_7 -> V_337 ) ;
V_23 = F_53 ( V_73 ) ;
if ( V_23 )
return V_23 ;
V_73 = NULL ;
}
}
V_394 = V_73 ? V_73 -> V_394 : 0 ;
if ( V_73 == NULL || ! F_284 ( & V_73 -> V_334 ) ) {
V_73 = F_311 ( V_7 , V_261 , V_377 , V_205 ) ;
if ( F_30 ( V_73 ) )
return F_31 ( V_73 ) ;
}
if ( V_205 & V_390 && ! ( V_73 -> V_394 & V_391 ) )
V_73 -> V_389 ( V_73 , V_7 -> V_9 , V_391 ) ;
if ( ( V_394 ^ V_73 -> V_394 ) & V_391 ) {
bool V_132 , V_410 ;
T_6 V_378 , V_379 ;
V_378 = F_180 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ) ;
V_379 = F_181 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ,
true ) ;
V_410 = ( V_73 -> V_334 . V_17 == V_378 &&
( V_73 -> V_334 . V_108 & ( V_379 - 1 ) ) == 0 ) ;
V_132 = ( V_73 -> V_334 . V_108 + V_7 -> V_8 . V_17 <=
V_16 -> V_37 . V_225 ) ;
V_7 -> V_337 = V_132 && V_410 ;
}
F_16 ( V_205 & V_128 && ! V_7 -> V_337 ) ;
V_73 -> V_335 ++ ;
if ( V_205 & V_128 )
V_7 -> V_411 |= true ;
return 0 ;
}
void
F_115 ( struct V_6 * V_7 )
{
struct V_72 * V_73 = F_321 ( V_7 ) ;
F_43 ( ! V_73 ) ;
F_43 ( V_73 -> V_335 == 0 ) ;
F_43 ( ! F_334 ( V_7 ) ) ;
if ( -- V_73 -> V_335 == 0 )
V_7 -> V_411 = false ;
}
bool
F_335 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 != V_14 ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_72 * V_412 = F_321 ( V_7 ) ;
F_16 ( ! V_412 ||
V_16 -> V_317 [ V_7 -> V_13 ] . V_335 >
V_412 -> V_335 ) ;
V_16 -> V_317 [ V_7 -> V_13 ] . V_335 ++ ;
return true ;
} else
return false ;
}
void
F_336 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 != V_14 ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
F_16 ( V_16 -> V_317 [ V_7 -> V_13 ] . V_335 <= 0 ) ;
V_16 -> V_317 [ V_7 -> V_13 ] . V_335 -- ;
}
}
int
F_337 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_413 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
if ( F_338 ( V_2 , V_414 ) )
return - V_171 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_33 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
if ( V_7 -> V_63 != V_71 ) {
F_191 ( L_19 ) ;
V_23 = - V_78 ;
goto V_119;
}
if ( V_7 -> V_415 != NULL && V_7 -> V_415 != V_33 ) {
F_191 ( L_20 ,
args -> V_88 ) ;
V_23 = - V_51 ;
goto V_119;
}
if ( V_7 -> V_403 == V_416 ) {
V_23 = - V_77 ;
goto V_119;
}
if ( V_7 -> V_403 == 0 ) {
V_23 = F_111 ( V_7 , args -> V_377 , V_128 ) ;
if ( V_23 )
goto V_119;
}
V_7 -> V_403 ++ ;
V_7 -> V_415 = V_33 ;
args -> V_58 = F_114 ( V_7 ) ;
V_119:
F_55 ( & V_7 -> V_8 ) ;
V_122:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_339 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_413 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
if ( F_338 ( V_2 , V_414 ) )
return - V_171 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_33 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
if ( V_7 -> V_415 != V_33 ) {
F_191 ( L_21 ,
args -> V_88 ) ;
V_23 = - V_51 ;
goto V_119;
}
V_7 -> V_403 -- ;
if ( V_7 -> V_403 == 0 ) {
V_7 -> V_415 = NULL ;
F_115 ( V_7 ) ;
}
V_119:
F_55 ( & V_7 -> V_8 ) ;
V_122:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_340 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_417 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_33 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
V_23 = F_275 ( V_7 ) ;
args -> V_418 = V_7 -> V_30 ;
if ( V_7 -> V_147 ) {
F_341 ( V_419 > 16 ) ;
args -> V_418 |= F_140 ( V_7 -> V_147 ) << 16 ;
}
F_55 ( & V_7 -> V_8 ) ;
V_122:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_342 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_82 )
{
return F_330 ( V_2 , V_82 ) ;
}
int
F_343 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_82 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_420 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
switch ( args -> V_63 ) {
case V_68 :
case V_71 :
break;
default:
return - V_51 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_104 ( F_105 ( V_2 , V_82 , args -> V_88 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_121 ;
goto V_122;
}
if ( F_23 ( V_7 ) ) {
V_23 = - V_51 ;
goto V_119;
}
if ( V_7 -> V_61 &&
V_7 -> V_11 != V_141 &&
V_16 -> V_255 & V_256 ) {
if ( V_7 -> V_63 == V_71 )
F_101 ( V_7 ) ;
if ( args -> V_63 == V_71 )
F_84 ( V_7 ) ;
}
if ( V_7 -> V_63 != V_64 )
V_7 -> V_63 = args -> V_63 ;
if ( F_194 ( V_7 ) && V_7 -> V_61 == NULL )
F_195 ( V_7 ) ;
args -> V_421 = V_7 -> V_63 != V_64 ;
V_119:
F_55 ( & V_7 -> V_8 ) ;
V_122:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void F_344 ( struct V_6 * V_7 ,
const struct V_228 * V_79 )
{
F_202 ( & V_7 -> V_230 ) ;
F_202 ( & V_7 -> V_258 ) ;
F_202 ( & V_7 -> V_422 ) ;
F_202 ( & V_7 -> V_338 ) ;
V_7 -> V_79 = V_79 ;
V_7 -> V_13 = V_14 ;
V_7 -> V_63 = V_71 ;
F_6 ( V_7 -> V_8 . V_2 -> V_27 , V_7 -> V_8 . V_17 ) ;
}
struct V_6 * F_70 ( struct V_1 * V_2 ,
T_1 V_17 )
{
struct V_6 * V_7 ;
struct V_40 * V_41 ;
T_13 V_423 ;
V_7 = F_64 ( V_2 ) ;
if ( V_7 == NULL )
return NULL ;
if ( F_345 ( V_2 , & V_7 -> V_8 , V_17 ) != 0 ) {
F_66 ( V_7 ) ;
return NULL ;
}
V_423 = V_424 | V_425 ;
if ( F_346 ( V_2 ) || F_347 ( V_2 ) ) {
V_423 &= ~ V_426 ;
V_423 |= V_254 ;
}
V_41 = F_27 ( V_7 -> V_8 . V_42 ) -> V_43 ;
F_348 ( V_41 , V_423 ) ;
F_344 ( V_7 , & V_427 ) ;
V_7 -> V_8 . V_66 = V_67 ;
V_7 -> V_8 . V_65 = V_67 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_9 = V_396 ;
} else
V_7 -> V_9 = V_5 ;
F_349 ( V_7 ) ;
return V_7 ;
}
static bool F_350 ( struct V_6 * V_7 )
{
if ( V_7 -> V_63 != V_71 )
return false ;
if ( V_7 -> V_8 . V_42 == NULL )
return true ;
return F_351 ( & V_7 -> V_8 . V_42 -> V_428 ) == 1 ;
}
void F_352 ( struct V_194 * V_429 )
{
struct V_6 * V_7 = F_104 ( V_429 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_72 * V_73 , * V_74 ;
F_123 ( V_16 ) ;
F_353 ( V_7 ) ;
F_52 (vma, next, &obj->vma_list, vma_link) {
int V_23 ;
V_73 -> V_335 = 0 ;
V_23 = F_53 ( V_73 ) ;
if ( F_16 ( V_23 == - V_178 ) ) {
bool V_430 ;
V_430 = V_16 -> V_18 . V_143 ;
V_16 -> V_18 . V_143 = false ;
F_16 ( F_53 ( V_73 ) ) ;
V_16 -> V_18 . V_143 = V_430 ;
}
}
if ( V_7 -> V_393 )
F_101 ( V_7 ) ;
F_16 ( V_7 -> V_431 ) ;
if ( V_7 -> V_61 && V_7 -> V_63 == V_71 &&
V_16 -> V_255 & V_256 &&
V_7 -> V_11 != V_141 )
F_101 ( V_7 ) ;
if ( F_16 ( V_7 -> V_229 ) )
V_7 -> V_229 = 0 ;
if ( F_350 ( V_7 ) )
V_7 -> V_63 = V_68 ;
F_54 ( V_7 ) ;
F_188 ( V_7 ) ;
F_43 ( V_7 -> V_61 ) ;
if ( V_7 -> V_8 . V_432 )
F_354 ( & V_7 -> V_8 , NULL ) ;
if ( V_7 -> V_79 -> V_433 )
V_7 -> V_79 -> V_433 ( V_7 ) ;
F_355 ( & V_7 -> V_8 ) ;
F_9 ( V_16 , V_7 -> V_8 . V_17 ) ;
F_39 ( V_7 -> V_434 ) ;
F_66 ( V_7 ) ;
F_125 ( V_16 ) ;
}
struct V_72 * F_224 ( struct V_6 * V_7 ,
struct V_262 * V_261 )
{
struct V_72 * V_73 ;
F_22 (vma, &obj->vma_list, vma_link)
if ( V_73 -> V_261 == V_261 )
return V_73 ;
return NULL ;
}
void F_285 ( struct V_72 * V_73 )
{
struct V_262 * V_261 = NULL ;
F_16 ( V_73 -> V_334 . V_374 ) ;
if ( ! F_203 ( & V_73 -> V_435 ) )
return;
V_261 = V_73 -> V_261 ;
if ( ! F_287 ( V_261 ) )
F_356 ( F_357 ( V_261 ) ) ;
F_201 ( & V_73 -> V_333 ) ;
F_39 ( V_73 ) ;
}
static void
F_358 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_146 * V_147 ;
int V_50 ;
F_228 (ring, dev_priv, i)
V_16 -> V_436 . V_437 ( V_147 ) ;
}
int
F_359 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 = 0 ;
F_21 ( & V_2 -> V_29 ) ;
V_23 = F_291 ( V_2 ) ;
if ( V_23 )
goto V_438;
F_230 ( V_2 ) ;
if ( ! F_338 ( V_2 , V_414 ) )
F_208 ( V_2 ) ;
F_358 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
F_360 ( & V_16 -> V_28 . V_439 ) ;
F_242 ( & V_16 -> V_18 . V_293 ) ;
F_361 ( & V_16 -> V_18 . V_169 ) ;
return 0 ;
V_438:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_362 ( struct V_146 * V_147 , int V_440 )
{
struct V_1 * V_2 = V_147 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_441 = V_442 + ( V_440 * 0x200 ) ;
T_6 * V_443 = V_16 -> V_444 . V_443 [ V_440 ] ;
int V_50 , V_23 ;
if ( ! F_363 ( V_2 ) || ! V_443 )
return 0 ;
V_23 = F_364 ( V_147 , V_445 / 4 * 3 ) ;
if ( V_23 )
return V_23 ;
for ( V_50 = 0 ; V_50 < V_445 ; V_50 += 4 ) {
F_365 ( V_147 , F_366 ( 1 ) ) ;
F_365 ( V_147 , V_441 + V_50 ) ;
F_365 ( V_147 , V_443 [ V_50 / 4 ] ) ;
}
F_367 ( V_147 ) ;
return V_23 ;
}
void F_368 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_146 ( V_2 ) -> V_166 < 5 ||
V_16 -> V_18 . V_446 == V_447 )
return;
F_294 ( V_448 , F_369 ( V_448 ) |
V_449 ) ;
if ( F_370 ( V_2 ) )
return;
F_294 ( V_450 , F_369 ( V_450 ) | V_451 ) ;
if ( F_371 ( V_2 ) )
F_294 ( V_452 , F_372 ( V_453 ) ) ;
else if ( F_373 ( V_2 ) )
F_294 ( V_452 , F_372 ( V_454 ) ) ;
else if ( F_374 ( V_2 ) )
F_294 ( V_455 , F_372 ( V_456 ) ) ;
else
F_303 () ;
}
static bool
F_375 ( struct V_1 * V_2 )
{
if ( ! F_376 ( V_2 ) )
return false ;
if ( F_371 ( V_2 ) && V_2 -> V_457 -> V_458 < 8 ) {
F_377 ( L_22
L_23 ) ;
return false ;
}
return true ;
}
static void F_378 ( struct V_1 * V_2 , T_6 V_8 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
F_294 ( F_379 ( V_8 ) , 0 ) ;
F_294 ( F_380 ( V_8 ) , 0 ) ;
F_294 ( F_381 ( V_8 ) , 0 ) ;
F_294 ( F_382 ( V_8 ) , 0 ) ;
}
static void F_383 ( struct V_1 * V_2 )
{
if ( F_384 ( V_2 ) ) {
F_378 ( V_2 , V_459 ) ;
F_378 ( V_2 , V_460 ) ;
F_378 ( V_2 , V_461 ) ;
F_378 ( V_2 , V_462 ) ;
F_378 ( V_2 , V_463 ) ;
} else if ( F_385 ( V_2 ) ) {
F_378 ( V_2 , V_460 ) ;
F_378 ( V_2 , V_461 ) ;
} else if ( F_386 ( V_2 ) ) {
F_378 ( V_2 , V_459 ) ;
F_378 ( V_2 , V_464 ) ;
}
}
int F_387 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
F_383 ( V_2 ) ;
V_23 = F_388 ( V_2 ) ;
if ( V_23 )
return V_23 ;
if ( F_389 ( V_2 ) ) {
V_23 = F_390 ( V_2 ) ;
if ( V_23 )
goto V_465;
}
if ( F_375 ( V_2 ) ) {
V_23 = F_391 ( V_2 ) ;
if ( V_23 )
goto V_466;
}
if ( F_392 ( V_2 ) ) {
V_23 = F_393 ( V_2 ) ;
if ( V_23 )
goto V_467;
}
if ( F_394 ( V_2 ) ) {
V_23 = F_395 ( V_2 ) ;
if ( V_23 )
goto V_468;
}
V_23 = F_233 ( V_2 , ( ( T_6 ) ~ 0 - 0x1000 ) ) ;
if ( V_23 )
goto V_469;
return 0 ;
V_469:
F_396 ( & V_16 -> V_147 [ V_470 ] ) ;
V_468:
F_396 ( & V_16 -> V_147 [ V_471 ] ) ;
V_467:
F_396 ( & V_16 -> V_147 [ V_472 ] ) ;
V_466:
F_396 ( & V_16 -> V_147 [ V_473 ] ) ;
V_465:
F_396 ( & V_16 -> V_147 [ V_167 ] ) ;
return V_23 ;
}
int
F_397 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 , V_50 ;
if ( F_146 ( V_2 ) -> V_166 < 6 && ! F_398 () )
return - V_26 ;
if ( V_16 -> V_474 )
F_294 ( V_475 , F_369 ( V_475 ) | F_399 ( 0xf ) ) ;
if ( F_400 ( V_2 ) )
F_294 ( V_476 , F_401 ( V_2 ) ?
V_477 : V_478 ) ;
if ( F_402 ( V_2 ) ) {
if ( F_403 ( V_2 ) ) {
T_6 V_479 = F_369 ( V_480 ) ;
V_479 &= ~ ( V_481 | V_482 ) ;
F_294 ( V_480 , V_479 ) ;
} else if ( F_146 ( V_2 ) -> V_166 >= 7 ) {
T_6 V_479 = F_369 ( V_483 ) ;
V_479 &= ~ V_484 ;
F_294 ( V_483 , V_479 ) ;
}
}
F_368 ( V_2 ) ;
V_23 = V_16 -> V_436 . V_485 ( V_2 ) ;
if ( V_23 )
return V_23 ;
for ( V_50 = 0 ; V_50 < F_404 ( V_2 ) ; V_50 ++ )
F_362 ( & V_16 -> V_147 [ V_167 ] , V_50 ) ;
V_23 = F_405 ( V_2 ) ;
if ( V_23 && V_23 != - V_26 ) {
F_13 ( L_24 , V_23 ) ;
F_406 ( V_2 ) ;
}
V_23 = F_407 ( V_16 ) ;
if ( V_23 && V_23 != - V_26 ) {
F_13 ( L_25 , V_23 ) ;
F_406 ( V_2 ) ;
return V_23 ;
}
return V_23 ;
}
int F_408 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
V_117 . V_278 = F_409 ( V_2 ,
V_117 . V_278 ) ;
F_21 ( & V_2 -> V_29 ) ;
if ( F_410 ( V_2 ) ) {
F_294 ( V_486 , V_487 ) ;
if ( F_411 ( ( F_369 ( V_488 ) &
V_489 ) , 10 ) )
F_412 ( L_26 ) ;
}
if ( ! V_117 . V_278 ) {
V_16 -> V_436 . V_490 = V_491 ;
V_16 -> V_436 . V_485 = F_387 ;
V_16 -> V_436 . V_492 = F_396 ;
V_16 -> V_436 . V_437 = V_493 ;
} else {
V_16 -> V_436 . V_490 = V_494 ;
V_16 -> V_436 . V_485 = V_495 ;
V_16 -> V_436 . V_492 = V_496 ;
V_16 -> V_436 . V_437 = V_497 ;
}
V_23 = F_413 ( V_2 ) ;
if ( V_23 ) {
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
F_414 ( V_2 ) ;
V_23 = F_415 ( V_2 ) ;
if ( V_23 ) {
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
V_23 = F_397 ( V_2 ) ;
if ( V_23 == - V_26 ) {
F_13 ( L_27 ) ;
F_416 ( V_498 , & V_16 -> V_28 . V_155 ) ;
V_23 = 0 ;
}
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void
F_406 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_146 * V_147 ;
int V_50 ;
F_228 (ring, dev_priv, i)
V_16 -> V_436 . V_492 ( V_147 ) ;
}
static void
F_417 ( struct V_146 * V_147 )
{
F_202 ( & V_147 -> V_259 ) ;
F_202 ( & V_147 -> V_290 ) ;
}
void F_418 ( struct V_15 * V_16 ,
struct V_262 * V_261 )
{
if ( ! F_287 ( V_261 ) )
F_419 ( & V_261 -> V_18 , V_261 -> V_108 , V_261 -> V_38 ) ;
V_261 -> V_2 = V_16 -> V_2 ;
F_202 ( & V_261 -> V_259 ) ;
F_202 ( & V_261 -> V_263 ) ;
F_202 ( & V_261 -> V_499 ) ;
F_219 ( & V_261 -> V_499 , & V_16 -> V_500 ) ;
}
void
F_420 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_50 ;
V_16 -> V_86 =
F_421 ( L_28 ,
sizeof( struct V_6 ) , 0 ,
V_501 ,
NULL ) ;
F_202 ( & V_16 -> V_500 ) ;
F_418 ( V_16 , & V_16 -> V_37 . V_8 ) ;
F_202 ( & V_16 -> V_502 ) ;
F_202 ( & V_16 -> V_18 . V_237 ) ;
F_202 ( & V_16 -> V_18 . V_238 ) ;
F_202 ( & V_16 -> V_18 . V_362 ) ;
for ( V_50 = 0 ; V_50 < V_419 ; V_50 ++ )
F_417 ( & V_16 -> V_147 [ V_50 ] ) ;
for ( V_50 = 0 ; V_50 < V_503 ; V_50 ++ )
F_202 ( & V_16 -> V_317 [ V_50 ] . V_361 ) ;
F_422 ( & V_16 -> V_18 . V_293 ,
F_270 ) ;
F_422 ( & V_16 -> V_18 . V_169 ,
F_273 ) ;
F_423 ( & V_16 -> V_28 . V_24 ) ;
if ( ! F_338 ( V_2 , V_414 ) && F_386 ( V_2 ) ) {
F_294 ( V_504 ,
F_372 ( V_505 ) ) ;
}
V_16 -> V_506 = V_507 ;
if ( ! F_338 ( V_2 , V_414 ) )
V_16 -> V_364 = 3 ;
if ( F_146 ( V_2 ) -> V_166 >= 7 && ! F_410 ( V_2 ) )
V_16 -> V_314 = 32 ;
else if ( F_146 ( V_2 ) -> V_166 >= 4 || F_424 ( V_2 ) || F_425 ( V_2 ) || F_182 ( V_2 ) )
V_16 -> V_314 = 16 ;
else
V_16 -> V_314 = 8 ;
F_202 ( & V_16 -> V_18 . V_362 ) ;
F_260 ( V_2 ) ;
F_426 ( V_2 ) ;
F_423 ( & V_16 -> V_508 ) ;
V_16 -> V_18 . V_143 = true ;
V_16 -> V_18 . V_509 . V_510 = V_511 ;
V_16 -> V_18 . V_509 . V_512 = V_513 ;
V_16 -> V_18 . V_509 . V_514 = V_515 ;
F_427 ( & V_16 -> V_18 . V_509 ) ;
V_16 -> V_18 . V_516 . V_517 = V_518 ;
F_428 ( & V_16 -> V_18 . V_516 ) ;
F_429 ( & V_16 -> V_519 . V_291 ) ;
}
void F_430 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_153 * V_82 = V_33 -> V_189 ;
F_242 ( & V_82 -> V_18 . V_169 ) ;
F_7 ( & V_82 -> V_18 . V_291 ) ;
while ( ! F_203 ( & V_82 -> V_18 . V_290 ) ) {
struct V_271 * V_272 ;
V_272 = F_204 ( & V_82 -> V_18 . V_290 ,
struct V_271 ,
V_292 ) ;
F_201 ( & V_272 -> V_292 ) ;
V_272 -> V_82 = NULL ;
}
F_8 ( & V_82 -> V_18 . V_291 ) ;
}
static void
F_431 ( struct V_322 * V_323 )
{
struct V_153 * V_82 =
F_271 ( V_323 , F_205 ( * V_82 ) , V_18 . V_169 . V_323 ) ;
F_432 ( & V_82 -> V_154 , false ) ;
}
int F_433 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_153 * V_82 ;
int V_23 ;
F_412 ( L_29 ) ;
V_82 = F_434 ( sizeof( * V_82 ) , V_55 ) ;
if ( ! V_82 )
return - V_56 ;
V_33 -> V_189 = V_82 ;
V_82 -> V_16 = V_2 -> V_27 ;
V_82 -> V_33 = V_33 ;
F_435 ( & V_82 -> V_18 . V_291 ) ;
F_202 ( & V_82 -> V_18 . V_290 ) ;
F_422 ( & V_82 -> V_18 . V_169 ,
F_431 ) ;
V_23 = F_436 ( V_2 , V_33 ) ;
if ( V_23 )
F_39 ( V_82 ) ;
return V_23 ;
}
void F_437 ( struct V_6 * V_367 ,
struct V_6 * V_520 ,
unsigned V_431 )
{
if ( V_367 ) {
F_16 ( ! F_130 ( & V_367 -> V_8 . V_2 -> V_29 ) ) ;
F_16 ( ! ( V_367 -> V_431 & V_431 ) ) ;
V_367 -> V_431 &= ~ V_431 ;
}
if ( V_520 ) {
F_16 ( ! F_130 ( & V_520 -> V_8 . V_2 -> V_29 ) ) ;
F_16 ( V_520 -> V_431 & V_431 ) ;
V_520 -> V_431 |= V_431 ;
}
}
static bool F_438 ( struct V_521 * V_521 , struct V_150 * V_522 )
{
if ( ! F_130 ( V_521 ) )
return false ;
#if F_439 ( V_523 ) && ! F_439 ( V_524 )
return V_521 -> V_525 == V_522 ;
#else
return false ;
#endif
}
static bool F_440 ( struct V_1 * V_2 , bool * V_122 )
{
if ( ! F_272 ( & V_2 -> V_29 ) ) {
if ( ! F_438 ( & V_2 -> V_29 , V_177 ) )
return false ;
if ( F_441 ( V_2 ) -> V_18 . V_221 )
return false ;
* V_122 = false ;
} else
* V_122 = true ;
return true ;
}
static int F_442 ( struct V_6 * V_7 )
{
struct V_72 * V_73 ;
int V_240 = 0 ;
F_22 (vma, &obj->vma_list, vma_link)
if ( F_284 ( & V_73 -> V_334 ) )
V_240 ++ ;
return V_240 ;
}
static unsigned long
V_513 ( struct V_509 * V_509 , struct V_526 * V_527 )
{
struct V_15 * V_16 =
F_271 ( V_509 , struct V_15 , V_18 . V_509 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_6 * V_7 ;
unsigned long V_240 ;
bool V_122 ;
if ( ! F_440 ( V_2 , & V_122 ) )
return 0 ;
V_240 = 0 ;
F_22 (obj, &dev_priv->mm.unbound_list, global_list)
if ( V_7 -> V_229 == 0 )
V_240 += V_7 -> V_8 . V_17 >> V_209 ;
F_22 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_23 ( V_7 ) &&
V_7 -> V_229 == F_442 ( V_7 ) )
V_240 += V_7 -> V_8 . V_17 >> V_209 ;
}
if ( V_122 )
F_25 ( & V_2 -> V_29 ) ;
return V_240 ;
}
unsigned long F_333 ( struct V_6 * V_528 ,
struct V_262 * V_261 )
{
struct V_15 * V_16 = V_528 -> V_8 . V_2 -> V_27 ;
struct V_72 * V_73 ;
F_16 ( V_261 == & V_16 -> V_18 . V_408 -> V_8 ) ;
F_22 (vma, &o->vma_list, vma_link) {
if ( V_73 -> V_261 == V_261 )
return V_73 -> V_334 . V_108 ;
}
F_142 ( 1 , L_30 ,
F_287 ( V_261 ) ? L_31 : L_32 ) ;
return - 1 ;
}
bool F_443 ( struct V_6 * V_528 ,
struct V_262 * V_261 )
{
struct V_72 * V_73 ;
F_22 (vma, &o->vma_list, vma_link)
if ( V_73 -> V_261 == V_261 && F_284 ( & V_73 -> V_334 ) )
return true ;
return false ;
}
bool F_19 ( struct V_6 * V_528 )
{
struct V_72 * V_73 ;
F_22 (vma, &o->vma_list, vma_link)
if ( F_284 ( & V_73 -> V_334 ) )
return true ;
return false ;
}
unsigned long F_444 ( struct V_6 * V_528 ,
struct V_262 * V_261 )
{
struct V_15 * V_16 = V_528 -> V_8 . V_2 -> V_27 ;
struct V_72 * V_73 ;
F_16 ( V_261 == & V_16 -> V_18 . V_408 -> V_8 ) ;
F_43 ( F_203 ( & V_528 -> V_338 ) ) ;
F_22 (vma, &o->vma_list, vma_link)
if ( V_73 -> V_261 == V_261 )
return V_73 -> V_334 . V_17 ;
return 0 ;
}
static unsigned long
V_511 ( struct V_509 * V_509 , struct V_526 * V_527 )
{
struct V_15 * V_16 =
F_271 ( V_509 , struct V_15 , V_18 . V_509 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_529 ;
bool V_122 ;
if ( ! F_440 ( V_2 , & V_122 ) )
return V_530 ;
V_529 = F_186 ( V_16 ,
V_527 -> V_531 ,
V_222 |
V_223 |
V_224 ) ;
if ( V_529 < V_527 -> V_531 )
V_529 += F_186 ( V_16 ,
V_527 -> V_531 - V_529 ,
V_222 |
V_223 ) ;
if ( V_122 )
F_25 ( & V_2 -> V_29 ) ;
return V_529 ;
}
static int
V_518 ( struct V_532 * V_533 , unsigned long V_534 , void * V_535 )
{
struct V_15 * V_16 =
F_271 ( V_533 , struct V_15 , V_18 . V_516 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_6 * V_7 ;
unsigned long V_156 = F_149 ( 5000 ) + 1 ;
unsigned long V_35 , V_394 , V_536 , V_537 ;
bool V_430 ;
bool V_122 ;
while ( ! F_440 ( V_2 , & V_122 ) && -- V_156 ) {
F_445 ( 1 ) ;
if ( F_446 ( V_177 ) )
return V_538 ;
}
if ( V_156 == 0 ) {
F_447 ( L_33 ) ;
return V_538 ;
}
V_430 = V_16 -> V_18 . V_143 ;
V_16 -> V_18 . V_143 = false ;
V_537 = F_187 ( V_16 ) ;
V_16 -> V_18 . V_143 = V_430 ;
V_536 = V_394 = V_35 = 0 ;
F_22 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( ! V_7 -> V_8 . V_42 )
continue;
if ( V_7 -> V_229 )
V_35 += V_7 -> V_8 . V_17 ;
else
V_536 += V_7 -> V_8 . V_17 ;
}
F_22 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! V_7 -> V_8 . V_42 )
continue;
if ( V_7 -> V_229 )
V_35 += V_7 -> V_8 . V_17 ;
else
V_394 += V_7 -> V_8 . V_17 ;
}
if ( V_122 )
F_25 ( & V_2 -> V_29 ) ;
if ( V_537 || V_536 || V_394 )
F_448 ( L_34 ,
V_537 << V_209 , V_35 ) ;
if ( V_536 || V_394 )
F_447 ( L_35
L_36 ,
V_394 , V_536 ) ;
* ( unsigned long * ) V_535 += V_537 ;
return V_538 ;
}
struct V_72 * F_321 ( struct V_6 * V_7 )
{
struct V_72 * V_73 ;
V_73 = F_204 ( & V_7 -> V_338 , F_205 ( * V_73 ) , V_333 ) ;
if ( V_73 -> V_261 != F_449 ( V_7 ) )
return NULL ;
return V_73 ;
}

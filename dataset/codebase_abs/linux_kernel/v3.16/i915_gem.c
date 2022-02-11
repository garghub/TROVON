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
if ( F_28 ( V_7 ) )
V_45 += F_29 ( V_7 ) ;
F_25 ( & V_2 -> V_29 ) ;
args -> V_46 = V_16 -> V_42 . V_8 . V_47 ;
args -> V_48 = args -> V_46 - V_45 ;
return 0 ;
}
static void F_30 ( struct V_6 * V_7 )
{
T_2 * V_49 = V_7 -> V_50 ;
if ( ! V_49 )
return;
if ( V_7 -> V_51 == V_52 ) {
struct V_53 * V_54 = F_31 ( V_7 -> V_8 . V_55 ) -> V_56 ;
char * V_57 = V_49 -> V_57 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_7 -> V_8 . V_17 / V_39 ; V_58 ++ ) {
struct V_59 * V_59 = F_32 ( V_54 , V_58 ) ;
if ( ! F_33 ( V_59 ) ) {
char * V_60 = F_34 ( V_59 ) ;
memcpy ( V_60 , V_57 , V_39 ) ;
F_35 ( V_60 , V_39 ) ;
F_36 ( V_60 ) ;
F_37 ( V_59 ) ;
F_38 ( V_59 ) ;
F_39 ( V_59 ) ;
}
V_57 += V_39 ;
}
F_40 ( V_7 -> V_8 . V_2 ) ;
}
#ifdef F_41
F_42 ( ( unsigned long ) V_49 -> V_57 , V_49 -> V_17 / V_39 ) ;
#endif
F_43 ( V_7 -> V_8 . V_2 , V_49 ) ;
V_7 -> V_50 = NULL ;
}
int
F_44 ( struct V_6 * V_7 ,
int V_61 )
{
T_2 * V_49 ;
struct V_53 * V_54 ;
char * V_57 ;
int V_58 ;
if ( V_7 -> V_50 ) {
if ( ( unsigned long ) V_7 -> V_50 -> V_57 & ( V_61 - 1 ) )
return - V_62 ;
return 0 ;
}
if ( V_7 -> V_51 != V_52 )
return - V_63 ;
if ( V_7 -> V_8 . V_55 == NULL )
return - V_40 ;
V_49 = F_45 ( V_7 -> V_8 . V_2 , V_7 -> V_8 . V_17 , V_61 ) ;
if ( ! V_49 )
return - V_64 ;
V_57 = V_49 -> V_57 ;
#ifdef F_41
F_46 ( ( unsigned long ) V_57 , V_49 -> V_17 / V_39 ) ;
#endif
V_54 = F_31 ( V_7 -> V_8 . V_55 ) -> V_56 ;
for ( V_58 = 0 ; V_58 < V_7 -> V_8 . V_17 / V_39 ; V_58 ++ ) {
struct V_59 * V_59 ;
char * V_65 ;
V_59 = F_32 ( V_54 , V_58 ) ;
if ( F_33 ( V_59 ) ) {
#ifdef F_41
F_42 ( ( unsigned long ) V_49 -> V_57 , V_49 -> V_17 / V_39 ) ;
#endif
F_43 ( V_7 -> V_8 . V_2 , V_49 ) ;
return F_47 ( V_59 ) ;
}
V_65 = F_34 ( V_59 ) ;
memcpy ( V_57 , V_65 , V_39 ) ;
F_36 ( V_65 ) ;
F_38 ( V_59 ) ;
F_39 ( V_59 ) ;
V_57 += V_39 ;
}
V_7 -> V_50 = V_49 ;
return 0 ;
}
static int
F_48 ( struct V_6 * V_7 ,
struct V_66 * args ,
struct V_32 * V_67 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
void * V_57 = V_7 -> V_50 -> V_57 + args -> V_68 ;
char T_3 * V_69 = F_49 ( args -> V_70 ) ;
if ( F_50 ( V_57 , V_69 , args -> V_17 ) ) {
unsigned long V_71 ;
F_25 ( & V_2 -> V_29 ) ;
V_71 = F_51 ( V_57 , V_69 , args -> V_17 ) ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_71 )
return - V_63 ;
}
F_40 ( V_2 ) ;
return 0 ;
}
void * F_52 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
return F_53 ( V_16 -> V_72 , V_73 ) ;
}
void F_54 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
F_55 ( V_16 -> V_72 , V_7 ) ;
}
static int
F_56 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_4 V_17 ,
T_5 * V_74 )
{
struct V_6 * V_7 ;
int V_23 ;
T_6 V_75 ;
V_17 = F_57 ( V_17 , V_39 ) ;
if ( V_17 == 0 )
return - V_40 ;
V_7 = F_58 ( V_2 , V_17 ) ;
if ( V_7 == NULL )
return - V_64 ;
V_23 = F_59 ( V_33 , & V_7 -> V_8 , & V_75 ) ;
F_60 ( & V_7 -> V_8 ) ;
if ( V_23 )
return V_23 ;
* V_74 = V_75 ;
return 0 ;
}
int
F_61 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
struct V_76 * args )
{
args -> V_77 = F_62 ( args -> V_78 * F_63 ( args -> V_79 , 8 ) , 64 ) ;
args -> V_17 = args -> V_77 * args -> V_80 ;
return F_56 ( V_33 , V_2 ,
args -> V_17 , & args -> V_75 ) ;
}
int
F_64 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_81 * args = V_31 ;
return F_56 ( V_33 , V_2 ,
args -> V_17 , & args -> V_75 ) ;
}
static inline int
F_65 ( char T_3 * V_82 ,
const char * V_83 , int V_84 ,
int V_85 )
{
int V_23 , V_86 = 0 ;
while ( V_85 > 0 ) {
int V_87 = F_62 ( V_84 + 1 , 64 ) ;
int V_88 = F_66 ( V_87 - V_84 , V_85 ) ;
int V_89 = V_84 ^ 64 ;
V_23 = F_67 ( V_82 + V_86 ,
V_83 + V_89 ,
V_88 ) ;
if ( V_23 )
return V_23 + V_85 ;
V_86 += V_88 ;
V_84 += V_88 ;
V_85 -= V_88 ;
}
return 0 ;
}
static inline int
F_68 ( char * V_83 , int V_84 ,
const char T_3 * V_82 ,
int V_85 )
{
int V_23 , V_86 = 0 ;
while ( V_85 > 0 ) {
int V_87 = F_62 ( V_84 + 1 , 64 ) ;
int V_88 = F_66 ( V_87 - V_84 , V_85 ) ;
int V_89 = V_84 ^ 64 ;
V_23 = F_69 ( V_83 + V_89 ,
V_82 + V_86 ,
V_88 ) ;
if ( V_23 )
return V_23 + V_85 ;
V_86 += V_88 ;
V_84 += V_88 ;
V_85 -= V_88 ;
}
return 0 ;
}
int F_70 ( struct V_6 * V_7 ,
int * V_90 )
{
int V_23 ;
* V_90 = 0 ;
if ( ! V_7 -> V_8 . V_55 )
return - V_40 ;
if ( ! ( V_7 -> V_8 . V_91 & V_92 ) ) {
* V_90 = ! F_1 ( V_7 -> V_8 . V_2 ,
V_7 -> V_9 ) ;
V_23 = F_71 ( V_7 , true ) ;
if ( V_23 )
return V_23 ;
F_72 ( V_7 ) ;
}
V_23 = F_73 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_74 ( V_7 ) ;
return V_23 ;
}
static int
F_75 ( struct V_59 * V_59 , int V_93 , int V_94 ,
char T_3 * V_69 ,
bool V_95 , bool V_90 )
{
char * V_57 ;
int V_23 ;
if ( F_76 ( V_95 ) )
return - V_40 ;
V_57 = F_34 ( V_59 ) ;
if ( V_90 )
F_35 ( V_57 + V_93 ,
V_94 ) ;
V_23 = F_77 ( V_69 ,
V_57 + V_93 ,
V_94 ) ;
F_36 ( V_57 ) ;
return V_23 ? - V_63 : 0 ;
}
static void
F_78 ( char * V_96 , unsigned long V_85 ,
bool V_97 )
{
if ( F_76 ( V_97 ) ) {
unsigned long V_98 = ( unsigned long ) V_96 ;
unsigned long V_99 = ( unsigned long ) V_96 + V_85 ;
V_98 = F_79 ( V_98 , 128 ) ;
V_99 = F_80 ( V_99 , 128 ) ;
F_35 ( ( void * ) V_98 , V_99 - V_98 ) ;
} else {
F_35 ( V_96 , V_85 ) ;
}
}
static int
F_81 ( struct V_59 * V_59 , int V_93 , int V_94 ,
char T_3 * V_69 ,
bool V_95 , bool V_90 )
{
char * V_57 ;
int V_23 ;
V_57 = F_82 ( V_59 ) ;
if ( V_90 )
F_78 ( V_57 + V_93 ,
V_94 ,
V_95 ) ;
if ( V_95 )
V_23 = F_65 ( V_69 ,
V_57 , V_93 ,
V_94 ) ;
else
V_23 = F_67 ( V_69 ,
V_57 + V_93 ,
V_94 ) ;
F_83 ( V_59 ) ;
return V_23 ? - V_63 : 0 ;
}
static int
F_84 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_100 * args ,
struct V_32 * V_33 )
{
char T_3 * V_69 ;
T_7 V_101 ;
T_8 V_68 ;
int V_93 , V_94 , V_23 = 0 ;
int V_102 , V_95 ;
int V_103 = 0 ;
int V_90 = 0 ;
struct V_104 V_105 ;
V_69 = F_49 ( args -> V_70 ) ;
V_101 = args -> V_17 ;
V_102 = F_85 ( V_7 ) ;
V_23 = F_70 ( V_7 , & V_90 ) ;
if ( V_23 )
return V_23 ;
V_68 = args -> V_68 ;
F_86 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_59 * V_59 = F_87 ( & V_105 ) ;
if ( V_101 <= 0 )
break;
V_93 = F_88 ( V_68 ) ;
V_94 = V_101 ;
if ( ( V_93 + V_94 ) > V_39 )
V_94 = V_39 - V_93 ;
V_95 = V_102 &&
( F_89 ( V_59 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_75 ( V_59 , V_93 , V_94 ,
V_69 , V_95 ,
V_90 ) ;
if ( V_23 == 0 )
goto V_106;
F_25 ( & V_2 -> V_29 ) ;
if ( F_90 ( ! V_107 . V_108 ) && ! V_103 ) {
V_23 = F_91 ( V_69 , V_101 ) ;
( void ) V_23 ;
V_103 = 1 ;
}
V_23 = F_81 ( V_59 , V_93 , V_94 ,
V_69 , V_95 ,
V_90 ) ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_23 )
goto V_109;
V_106:
V_101 -= V_94 ;
V_69 += V_94 ;
V_68 += V_94 ;
}
V_109:
F_92 ( V_7 ) ;
return V_23 ;
}
int
F_93 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_100 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_94 ( V_110 ,
F_49 ( args -> V_70 ) ,
args -> V_17 ) )
return - V_63 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_95 ( F_96 ( V_2 , V_33 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
if ( args -> V_68 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_68 ) {
V_23 = - V_40 ;
goto V_109;
}
if ( ! V_7 -> V_8 . V_55 ) {
V_23 = - V_40 ;
goto V_109;
}
F_97 ( V_7 , args -> V_68 , args -> V_17 ) ;
V_23 = F_84 ( V_2 , V_7 , args , V_33 ) ;
V_109:
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static inline int
F_99 ( struct V_113 * V_54 ,
T_8 V_114 , int V_115 ,
char T_3 * V_69 ,
int V_85 )
{
void T_9 * V_116 ;
void * V_57 ;
unsigned long V_71 ;
V_116 = F_100 ( V_54 , V_114 ) ;
V_57 = ( void V_117 * ) V_116 + V_115 ;
V_71 = F_50 ( V_57 ,
V_69 , V_85 ) ;
F_101 ( V_116 ) ;
return V_71 ;
}
static int
F_102 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_66 * args ,
struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_7 V_101 ;
T_8 V_68 , V_114 ;
char T_3 * V_69 ;
int V_115 , V_94 , V_23 ;
V_23 = F_103 ( V_7 , 0 , V_118 | V_119 ) ;
if ( V_23 )
goto V_109;
V_23 = F_104 ( V_7 , true ) ;
if ( V_23 )
goto V_120;
V_23 = F_105 ( V_7 ) ;
if ( V_23 )
goto V_120;
V_69 = F_49 ( args -> V_70 ) ;
V_101 = args -> V_17 ;
V_68 = F_106 ( V_7 ) + args -> V_68 ;
while ( V_101 > 0 ) {
V_114 = V_68 & V_121 ;
V_115 = F_88 ( V_68 ) ;
V_94 = V_101 ;
if ( ( V_115 + V_101 ) > V_39 )
V_94 = V_39 - V_115 ;
if ( F_99 ( V_16 -> V_42 . V_122 , V_114 ,
V_115 , V_69 , V_94 ) ) {
V_23 = - V_63 ;
goto V_120;
}
V_101 -= V_94 ;
V_69 += V_94 ;
V_68 += V_94 ;
}
V_120:
F_107 ( V_7 ) ;
V_109:
return V_23 ;
}
static int
F_108 ( struct V_59 * V_59 , int V_93 , int V_94 ,
char T_3 * V_69 ,
bool V_95 ,
bool V_123 ,
bool V_124 )
{
char * V_57 ;
int V_23 ;
if ( F_76 ( V_95 ) )
return - V_40 ;
V_57 = F_34 ( V_59 ) ;
if ( V_123 )
F_35 ( V_57 + V_93 ,
V_94 ) ;
V_23 = F_109 ( V_57 + V_93 ,
V_69 , V_94 ) ;
if ( V_124 )
F_35 ( V_57 + V_93 ,
V_94 ) ;
F_36 ( V_57 ) ;
return V_23 ? - V_63 : 0 ;
}
static int
F_110 ( struct V_59 * V_59 , int V_93 , int V_94 ,
char T_3 * V_69 ,
bool V_95 ,
bool V_123 ,
bool V_124 )
{
char * V_57 ;
int V_23 ;
V_57 = F_82 ( V_59 ) ;
if ( F_76 ( V_123 || V_95 ) )
F_78 ( V_57 + V_93 ,
V_94 ,
V_95 ) ;
if ( V_95 )
V_23 = F_68 ( V_57 , V_93 ,
V_69 ,
V_94 ) ;
else
V_23 = F_69 ( V_57 + V_93 ,
V_69 ,
V_94 ) ;
if ( V_124 )
F_78 ( V_57 + V_93 ,
V_94 ,
V_95 ) ;
F_83 ( V_59 ) ;
return V_23 ? - V_63 : 0 ;
}
static int
F_111 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_66 * args ,
struct V_32 * V_33 )
{
T_7 V_101 ;
T_8 V_68 ;
char T_3 * V_69 ;
int V_93 , V_94 , V_23 = 0 ;
int V_102 , V_95 ;
int V_125 = 0 ;
int V_124 = 0 ;
int V_123 = 0 ;
struct V_104 V_105 ;
V_69 = F_49 ( args -> V_70 ) ;
V_101 = args -> V_17 ;
V_102 = F_85 ( V_7 ) ;
if ( V_7 -> V_8 . V_126 != V_92 ) {
V_124 = F_3 ( V_7 ) ;
V_23 = F_71 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
F_72 ( V_7 ) ;
}
if ( ( V_7 -> V_8 . V_91 & V_92 ) == 0 )
V_123 =
! F_1 ( V_2 , V_7 -> V_9 ) ;
V_23 = F_73 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_74 ( V_7 ) ;
V_68 = args -> V_68 ;
V_7 -> V_127 = 1 ;
F_86 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_59 * V_59 = F_87 ( & V_105 ) ;
int V_128 ;
if ( V_101 <= 0 )
break;
V_93 = F_88 ( V_68 ) ;
V_94 = V_101 ;
if ( ( V_93 + V_94 ) > V_39 )
V_94 = V_39 - V_93 ;
V_128 = V_123 &&
( ( V_93 | V_94 )
& ( V_129 . V_130 - 1 ) ) ;
V_95 = V_102 &&
( F_89 ( V_59 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_108 ( V_59 , V_93 , V_94 ,
V_69 , V_95 ,
V_128 ,
V_124 ) ;
if ( V_23 == 0 )
goto V_106;
V_125 = 1 ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_110 ( V_59 , V_93 , V_94 ,
V_69 , V_95 ,
V_128 ,
V_124 ) ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_23 )
goto V_109;
V_106:
V_101 -= V_94 ;
V_69 += V_94 ;
V_68 += V_94 ;
}
V_109:
F_92 ( V_7 ) ;
if ( V_125 ) {
if ( ! V_124 &&
V_7 -> V_8 . V_126 != V_92 ) {
if ( F_112 ( V_7 , V_7 -> V_10 ) )
F_40 ( V_2 ) ;
}
}
if ( V_124 )
F_40 ( V_2 ) ;
return V_23 ;
}
int
F_113 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_66 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_94 ( V_131 ,
F_49 ( args -> V_70 ) ,
args -> V_17 ) )
return - V_63 ;
if ( F_90 ( ! V_107 . V_108 ) ) {
V_23 = F_114 ( F_49 ( args -> V_70 ) ,
args -> V_17 ) ;
if ( V_23 )
return - V_63 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_95 ( F_96 ( V_2 , V_33 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
if ( args -> V_68 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_68 ) {
V_23 = - V_40 ;
goto V_109;
}
if ( ! V_7 -> V_8 . V_55 ) {
V_23 = - V_40 ;
goto V_109;
}
F_115 ( V_7 , args -> V_68 , args -> V_17 ) ;
V_23 = - V_63 ;
if ( V_7 -> V_50 ) {
V_23 = F_48 ( V_7 , args , V_33 ) ;
goto V_109;
}
if ( V_7 -> V_11 == V_132 &&
V_7 -> V_8 . V_126 != V_92 &&
F_3 ( V_7 ) ) {
V_23 = F_102 ( V_2 , V_7 , args , V_33 ) ;
}
if ( V_23 == - V_63 || V_23 == - V_133 )
V_23 = F_111 ( V_2 , V_7 , args , V_33 ) ;
V_109:
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_116 ( struct V_22 * error ,
bool V_134 )
{
if ( F_117 ( error ) ) {
if ( ! V_134 )
return - V_26 ;
if ( F_118 ( error ) )
return - V_26 ;
return - V_135 ;
}
return 0 ;
}
static int
F_119 ( struct V_136 * V_137 , T_6 V_138 )
{
int V_23 ;
F_120 ( ! F_121 ( & V_137 -> V_2 -> V_29 ) ) ;
V_23 = 0 ;
if ( V_138 == V_137 -> V_139 )
V_23 = F_122 ( V_137 , NULL ) ;
return V_23 ;
}
static void F_123 ( unsigned long V_31 )
{
F_124 ( (struct V_140 * ) V_31 ) ;
}
static bool F_125 ( struct V_15 * V_16 ,
struct V_136 * V_137 )
{
return F_126 ( V_137 -> V_141 , & V_16 -> V_28 . V_142 ) ;
}
static bool F_127 ( struct V_143 * V_67 )
{
if ( V_67 == NULL )
return true ;
return ! F_128 ( & V_67 -> V_144 , true ) ;
}
static int F_129 ( struct V_136 * V_137 , T_6 V_138 ,
unsigned V_145 ,
bool V_134 ,
struct V_146 * V_147 ,
struct V_143 * V_67 )
{
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
const bool V_148 =
F_130 ( V_16 -> V_28 . V_149 ) & F_131 ( V_137 ) ;
struct V_146 V_150 , V_151 ;
F_132 ( V_152 ) ;
unsigned long V_153 ;
int V_23 ;
F_133 ( V_16 -> V_154 . V_155 , L_2 ) ;
if ( F_134 ( V_137 -> V_156 ( V_137 , true ) , V_138 ) )
return 0 ;
V_153 = V_147 ? V_157 + F_135 ( V_147 ) : 0 ;
if ( F_22 ( V_2 ) -> V_41 >= 6 && F_127 ( V_67 ) ) {
F_136 ( V_16 ) ;
if ( V_67 )
F_137 ( V_16 -> V_158 ,
& V_67 -> V_18 . V_159 ,
F_138 ( 100 ) ) ;
}
if ( ! V_148 && F_16 ( ! V_137 -> V_160 ( V_137 ) ) )
return - V_36 ;
F_139 ( V_137 , V_138 ) ;
F_140 ( & V_150 ) ;
for (; ; ) {
struct V_161 V_162 ;
F_141 ( & V_137 -> V_163 , & V_152 ,
V_134 ? V_164 : V_165 ) ;
if ( V_145 != F_142 ( & V_16 -> V_28 . V_145 ) ) {
V_23 = F_116 ( & V_16 -> V_28 , V_134 ) ;
if ( V_23 == 0 )
V_23 = - V_135 ;
break;
}
if ( F_134 ( V_137 -> V_156 ( V_137 , false ) , V_138 ) ) {
V_23 = 0 ;
break;
}
if ( V_134 && F_143 ( V_166 ) ) {
V_23 = - V_167 ;
break;
}
if ( V_147 && F_144 ( V_157 , V_153 ) ) {
V_23 = - V_168 ;
break;
}
V_162 . V_169 = NULL ;
if ( V_147 || F_125 ( V_16 , V_137 ) ) {
unsigned long V_170 ;
F_145 ( & V_162 , F_123 , ( unsigned long ) V_166 ) ;
V_170 = F_125 ( V_16 , V_137 ) ? V_157 + 1 : V_153 ;
F_146 ( & V_162 , V_170 ) ;
}
F_147 () ;
if ( V_162 . V_169 ) {
F_148 ( & V_162 ) ;
F_149 ( & V_162 ) ;
}
}
F_140 ( & V_151 ) ;
F_150 ( V_137 , V_138 ) ;
if ( ! V_148 )
V_137 -> V_171 ( V_137 ) ;
F_151 ( & V_137 -> V_163 , & V_152 ) ;
if ( V_147 ) {
struct V_146 V_172 = F_152 ( V_151 , V_150 ) ;
* V_147 = F_152 ( * V_147 , V_172 ) ;
if ( ! F_153 ( V_147 ) )
F_154 ( V_147 , 0 , 0 ) ;
}
return V_23 ;
}
int
F_155 ( struct V_136 * V_137 , T_5 V_138 )
{
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_134 = V_16 -> V_18 . V_134 ;
int V_23 ;
F_120 ( ! F_121 ( & V_2 -> V_29 ) ) ;
F_120 ( V_138 == 0 ) ;
V_23 = F_116 ( & V_16 -> V_28 , V_134 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_119 ( V_137 , V_138 ) ;
if ( V_23 )
return V_23 ;
return F_129 ( V_137 , V_138 ,
F_142 ( & V_16 -> V_28 . V_145 ) ,
V_134 , NULL , NULL ) ;
}
static int
F_156 ( struct V_6 * V_7 ,
struct V_136 * V_137 )
{
if ( ! V_7 -> V_30 )
return 0 ;
V_7 -> V_173 = 0 ;
return 0 ;
}
static T_10 int
F_71 ( struct V_6 * V_7 ,
bool V_174 )
{
struct V_136 * V_137 = V_7 -> V_137 ;
T_6 V_138 ;
int V_23 ;
V_138 = V_174 ? V_7 -> V_173 : V_7 -> V_175 ;
if ( V_138 == 0 )
return 0 ;
V_23 = F_155 ( V_137 , V_138 ) ;
if ( V_23 )
return V_23 ;
return F_156 ( V_7 , V_137 ) ;
}
static T_10 int
F_157 ( struct V_6 * V_7 ,
struct V_143 * V_67 ,
bool V_174 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 = V_7 -> V_137 ;
unsigned V_145 ;
T_6 V_138 ;
int V_23 ;
F_120 ( ! F_121 ( & V_2 -> V_29 ) ) ;
F_120 ( ! V_16 -> V_18 . V_134 ) ;
V_138 = V_174 ? V_7 -> V_173 : V_7 -> V_175 ;
if ( V_138 == 0 )
return 0 ;
V_23 = F_116 ( & V_16 -> V_28 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = F_119 ( V_137 , V_138 ) ;
if ( V_23 )
return V_23 ;
V_145 = F_142 ( & V_16 -> V_28 . V_145 ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_129 ( V_137 , V_138 , V_145 , true , NULL , V_67 ) ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_23 )
return V_23 ;
return F_156 ( V_7 , V_137 ) ;
}
int
F_158 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_176 * args = V_31 ;
struct V_6 * V_7 ;
T_5 V_91 = args -> V_91 ;
T_5 V_126 = args -> V_126 ;
int V_23 ;
if ( V_126 & V_177 )
return - V_40 ;
if ( V_91 & V_177 )
return - V_40 ;
if ( V_126 != 0 && V_91 != V_126 )
return - V_40 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_95 ( F_96 ( V_2 , V_33 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
V_23 = F_157 ( V_7 ,
V_33 -> V_178 ,
! V_126 ) ;
if ( V_23 )
goto V_179;
if ( V_91 & V_180 ) {
V_23 = F_104 ( V_7 , V_126 != 0 ) ;
if ( V_23 == - V_40 )
V_23 = 0 ;
} else {
V_23 = F_159 ( V_7 , V_126 != 0 ) ;
}
V_179:
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_160 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_181 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_95 ( F_96 ( V_2 , V_33 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
if ( V_7 -> V_10 )
F_161 ( V_7 , true ) ;
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_162 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_182 * args = V_31 ;
struct V_183 * V_7 ;
unsigned long V_96 ;
V_7 = F_96 ( V_2 , V_33 , args -> V_75 ) ;
if ( V_7 == NULL )
return - V_111 ;
if ( ! V_7 -> V_55 ) {
F_60 ( V_7 ) ;
return - V_40 ;
}
V_96 = F_163 ( V_7 -> V_55 , 0 , args -> V_17 ,
V_184 | V_185 , V_186 ,
args -> V_68 ) ;
F_60 ( V_7 ) ;
if ( F_33 ( ( void * ) V_96 ) )
return V_96 ;
args -> V_187 = ( T_4 ) V_96 ;
return 0 ;
}
int F_164 ( struct V_188 * V_189 , struct V_190 * V_191 )
{
struct V_6 * V_7 = F_95 ( V_189 -> V_192 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_11 V_115 ;
unsigned long V_193 ;
int V_23 = 0 ;
bool V_194 = ! ! ( V_191 -> V_195 & V_196 ) ;
F_165 ( V_16 ) ;
V_115 = ( ( unsigned long ) V_191 -> V_197 - V_189 -> V_198 ) >>
V_199 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
goto V_109;
F_166 ( V_7 , V_115 , true , V_194 ) ;
V_23 = F_157 ( V_7 , NULL , ! V_194 ) ;
if ( V_23 )
goto V_112;
if ( V_7 -> V_9 != V_5 && ! F_2 ( V_2 ) ) {
V_23 = - V_63 ;
goto V_112;
}
V_23 = F_103 ( V_7 , 0 , V_118 ) ;
if ( V_23 )
goto V_112;
V_23 = F_104 ( V_7 , V_194 ) ;
if ( V_23 )
goto V_200;
V_23 = F_167 ( V_7 ) ;
if ( V_23 )
goto V_200;
V_7 -> V_201 = true ;
V_193 = V_16 -> V_42 . V_202 + F_106 ( V_7 ) ;
V_193 >>= V_199 ;
V_193 += V_115 ;
V_23 = F_168 ( V_189 , ( unsigned long ) V_191 -> V_197 , V_193 ) ;
V_200:
F_107 ( V_7 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
V_109:
switch ( V_23 ) {
case - V_26 :
if ( F_118 ( & V_16 -> V_28 ) ) {
V_23 = V_203 ;
break;
}
case - V_135 :
case 0 :
case - V_167 :
case - V_204 :
case - V_62 :
V_23 = V_205 ;
break;
case - V_64 :
V_23 = V_206 ;
break;
case - V_133 :
case - V_63 :
V_23 = V_203 ;
break;
default:
F_169 ( V_23 , L_3 , V_23 ) ;
V_23 = V_203 ;
break;
}
F_170 ( V_16 ) ;
return V_23 ;
}
void
F_5 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_201 )
return;
F_171 ( & V_7 -> V_8 . V_207 ,
V_7 -> V_8 . V_2 -> V_208 -> V_56 ) ;
V_7 -> V_201 = false ;
}
void
F_172 ( struct V_15 * V_16 )
{
struct V_6 * V_7 ;
F_27 (obj, &dev_priv->mm.bound_list, global_list)
F_5 ( V_7 ) ;
}
T_5
F_173 ( struct V_1 * V_2 , T_5 V_17 , int V_11 )
{
T_5 V_209 ;
if ( F_22 ( V_2 ) -> V_41 >= 4 ||
V_11 == V_132 )
return V_17 ;
if ( F_22 ( V_2 ) -> V_41 == 3 )
V_209 = 1024 * 1024 ;
else
V_209 = 512 * 1024 ;
while ( V_209 < V_17 )
V_209 <<= 1 ;
return V_209 ;
}
T_5
F_174 ( struct V_1 * V_2 , T_5 V_17 ,
int V_11 , bool V_210 )
{
if ( F_22 ( V_2 ) -> V_41 >= 4 || ( ! V_210 && F_175 ( V_2 ) ) ||
V_11 == V_132 )
return 4096 ;
return F_173 ( V_2 , V_17 , V_11 ) ;
}
static int F_176 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_177 ( & V_7 -> V_8 . V_207 ) )
return 0 ;
V_16 -> V_18 . V_211 = true ;
V_23 = F_178 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_133 )
goto V_109;
F_179 ( V_16 , V_7 -> V_8 . V_17 >> V_199 ) ;
V_23 = F_178 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_133 )
goto V_109;
F_180 ( V_16 ) ;
V_23 = F_178 ( & V_7 -> V_8 ) ;
V_109:
V_16 -> V_18 . V_211 = false ;
return V_23 ;
}
static void F_181 ( struct V_6 * V_7 )
{
F_182 ( & V_7 -> V_8 ) ;
}
int
F_183 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_5 V_75 ,
T_4 * V_68 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_95 ( F_96 ( V_2 , V_33 , V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
if ( V_7 -> V_8 . V_17 > V_16 -> V_42 . V_43 ) {
V_23 = - V_212 ;
goto V_109;
}
if ( V_7 -> V_51 != V_52 ) {
F_184 ( L_4 ) ;
V_23 = - V_63 ;
goto V_109;
}
V_23 = F_176 ( V_7 ) ;
if ( V_23 )
goto V_109;
* V_68 = F_185 ( & V_7 -> V_8 . V_207 ) ;
V_109:
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_186 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_213 * args = V_31 ;
return F_183 ( V_33 , V_2 , args -> V_75 , & args -> V_68 ) ;
}
static inline int
F_187 ( struct V_6 * V_7 )
{
return V_7 -> V_51 == V_214 ;
}
static void
F_188 ( struct V_6 * V_7 )
{
F_181 ( V_7 ) ;
if ( V_7 -> V_8 . V_55 == NULL )
return;
F_189 ( F_31 ( V_7 -> V_8 . V_55 ) , 0 , ( T_8 ) - 1 ) ;
V_7 -> V_51 = V_215 ;
}
static void
F_190 ( struct V_6 * V_7 )
{
struct V_53 * V_54 ;
switch ( V_7 -> V_51 ) {
case V_214 :
F_188 ( V_7 ) ;
case V_215 :
return;
}
if ( V_7 -> V_8 . V_55 == NULL )
return;
V_54 = F_31 ( V_7 -> V_8 . V_55 ) -> V_56 ,
F_191 ( V_54 , 0 , ( T_8 ) - 1 ) ;
}
static void
F_192 ( struct V_6 * V_7 )
{
struct V_104 V_105 ;
int V_23 ;
F_120 ( V_7 -> V_51 == V_215 ) ;
V_23 = F_159 ( V_7 , true ) ;
if ( V_23 ) {
F_16 ( V_23 != - V_26 ) ;
F_112 ( V_7 , true ) ;
V_7 -> V_8 . V_91 = V_7 -> V_8 . V_126 = V_92 ;
}
if ( F_85 ( V_7 ) )
F_193 ( V_7 ) ;
if ( V_7 -> V_51 == V_214 )
V_7 -> V_127 = 0 ;
F_86 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_59 * V_59 = F_87 ( & V_105 ) ;
if ( V_7 -> V_127 )
F_37 ( V_59 ) ;
if ( V_7 -> V_51 == V_52 )
F_38 ( V_59 ) ;
F_39 ( V_59 ) ;
}
V_7 -> V_127 = 0 ;
F_194 ( V_7 -> V_216 ) ;
F_195 ( V_7 -> V_216 ) ;
}
int
F_196 ( struct V_6 * V_7 )
{
const struct V_217 * V_218 = V_7 -> V_218 ;
if ( V_7 -> V_216 == NULL )
return 0 ;
if ( V_7 -> V_219 )
return - V_62 ;
F_120 ( F_19 ( V_7 ) ) ;
F_197 ( & V_7 -> V_220 ) ;
V_218 -> V_221 ( V_7 ) ;
V_7 -> V_216 = NULL ;
F_190 ( V_7 ) ;
return 0 ;
}
static unsigned long
F_198 ( struct V_15 * V_16 , long V_222 ,
bool V_223 )
{
struct V_224 V_225 ;
struct V_6 * V_7 ;
unsigned long V_226 = 0 ;
F_199 ( & V_225 ) ;
while ( V_226 < V_222 && ! F_200 ( & V_16 -> V_18 . V_227 ) ) {
V_7 = F_201 ( & V_16 -> V_18 . V_227 ,
F_202 ( * V_7 ) , V_220 ) ;
F_203 ( & V_7 -> V_220 , & V_225 ) ;
if ( ! F_187 ( V_7 ) && V_223 )
continue;
F_204 ( & V_7 -> V_8 ) ;
if ( F_196 ( V_7 ) == 0 )
V_226 += V_7 -> V_8 . V_17 >> V_199 ;
F_98 ( & V_7 -> V_8 ) ;
}
F_205 ( & V_225 , & V_16 -> V_18 . V_227 ) ;
F_199 ( & V_225 ) ;
while ( V_226 < V_222 && ! F_200 ( & V_16 -> V_18 . V_228 ) ) {
struct V_229 * V_189 , * V_230 ;
V_7 = F_201 ( & V_16 -> V_18 . V_228 ,
F_202 ( * V_7 ) , V_220 ) ;
F_203 ( & V_7 -> V_220 , & V_225 ) ;
if ( ! F_187 ( V_7 ) && V_223 )
continue;
F_204 ( & V_7 -> V_8 ) ;
F_206 (vma, v, &obj->vma_list, vma_link)
if ( F_207 ( V_189 ) )
break;
if ( F_196 ( V_7 ) == 0 )
V_226 += V_7 -> V_8 . V_17 >> V_199 ;
F_98 ( & V_7 -> V_8 ) ;
}
F_205 ( & V_225 , & V_16 -> V_18 . V_228 ) ;
return V_226 ;
}
static unsigned long
F_179 ( struct V_15 * V_16 , long V_222 )
{
return F_198 ( V_16 , V_222 , true ) ;
}
static unsigned long
F_180 ( struct V_15 * V_16 )
{
F_208 ( V_16 -> V_2 ) ;
return F_198 ( V_16 , V_231 , false ) ;
}
static int
F_209 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_232 , V_58 ;
struct V_53 * V_54 ;
struct V_233 * V_234 ;
struct V_235 * V_236 ;
struct V_104 V_105 ;
struct V_59 * V_59 ;
unsigned long V_237 = 0 ;
T_12 V_238 ;
F_120 ( V_7 -> V_8 . V_91 & V_177 ) ;
F_120 ( V_7 -> V_8 . V_126 & V_177 ) ;
V_234 = F_210 ( sizeof( * V_234 ) , V_73 ) ;
if ( V_234 == NULL )
return - V_64 ;
V_232 = V_7 -> V_8 . V_17 / V_39 ;
if ( F_211 ( V_234 , V_232 , V_73 ) ) {
F_195 ( V_234 ) ;
return - V_64 ;
}
V_54 = F_31 ( V_7 -> V_8 . V_55 ) -> V_56 ;
V_238 = F_212 ( V_54 ) ;
V_238 |= V_239 | V_240 | V_241 ;
V_238 &= ~ ( V_242 | V_243 ) ;
V_236 = V_234 -> V_244 ;
V_234 -> V_245 = 0 ;
for ( V_58 = 0 ; V_58 < V_232 ; V_58 ++ ) {
V_59 = F_213 ( V_54 , V_58 , V_238 ) ;
if ( F_33 ( V_59 ) ) {
F_179 ( V_16 , V_232 ) ;
V_59 = F_213 ( V_54 , V_58 , V_238 ) ;
}
if ( F_33 ( V_59 ) ) {
V_238 &= ~ ( V_239 | V_240 | V_241 ) ;
V_238 |= V_242 | V_243 ;
F_180 ( V_16 ) ;
V_59 = F_213 ( V_54 , V_58 , V_238 ) ;
if ( F_33 ( V_59 ) )
goto V_246;
V_238 |= V_239 | V_240 | V_241 ;
V_238 &= ~ ( V_242 | V_243 ) ;
}
#ifdef F_214
if ( F_215 () ) {
V_234 -> V_245 ++ ;
F_216 ( V_236 , V_59 , V_39 , 0 ) ;
V_236 = F_217 ( V_236 ) ;
continue;
}
#endif
if ( ! V_58 || F_218 ( V_59 ) != V_237 + 1 ) {
if ( V_58 )
V_236 = F_217 ( V_236 ) ;
V_234 -> V_245 ++ ;
F_216 ( V_236 , V_59 , V_39 , 0 ) ;
} else {
V_236 -> V_85 += V_39 ;
}
V_237 = F_218 ( V_59 ) ;
F_16 ( ( V_238 & V_247 ) && ( V_237 >= 0x00100000UL ) ) ;
}
#ifdef F_214
if ( ! F_215 () )
#endif
F_219 ( V_236 ) ;
V_7 -> V_216 = V_234 ;
if ( F_85 ( V_7 ) )
F_220 ( V_7 ) ;
return 0 ;
V_246:
F_219 ( V_236 ) ;
F_86 (st->sgl, &sg_iter, st->nents, 0 )
F_39 ( F_87 ( & V_105 ) ) ;
F_194 ( V_234 ) ;
F_195 ( V_234 ) ;
if ( F_47 ( V_59 ) == - V_133 )
return - V_64 ;
else
return F_47 ( V_59 ) ;
}
int
F_73 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
const struct V_217 * V_218 = V_7 -> V_218 ;
int V_23 ;
if ( V_7 -> V_216 )
return 0 ;
if ( V_7 -> V_51 != V_52 ) {
F_184 ( L_5 ) ;
return - V_63 ;
}
F_120 ( V_7 -> V_219 ) ;
V_23 = V_218 -> V_248 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_221 ( & V_7 -> V_220 , & V_16 -> V_18 . V_227 ) ;
return 0 ;
}
static void
F_222 ( struct V_6 * V_7 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_138 = F_223 ( V_137 ) ;
F_120 ( V_137 == NULL ) ;
if ( V_7 -> V_137 != V_137 && V_7 -> V_173 ) {
V_7 -> V_173 = V_138 ;
}
V_7 -> V_137 = V_137 ;
if ( ! V_7 -> V_30 ) {
F_204 ( & V_7 -> V_8 ) ;
V_7 -> V_30 = 1 ;
}
F_203 ( & V_7 -> V_249 , & V_137 -> V_250 ) ;
V_7 -> V_175 = V_138 ;
if ( V_7 -> V_251 ) {
V_7 -> V_252 = V_138 ;
if ( V_7 -> V_13 != V_14 ) {
struct V_253 * V_254 ;
V_254 = & V_16 -> V_255 [ V_7 -> V_13 ] ;
F_203 ( & V_254 -> V_256 ,
& V_16 -> V_18 . V_257 ) ;
}
}
}
void F_224 ( struct V_229 * V_189 ,
struct V_136 * V_137 )
{
F_203 ( & V_189 -> V_258 , & V_189 -> V_259 -> V_250 ) ;
return F_222 ( V_189 -> V_7 , V_137 ) ;
}
static void
F_225 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_260 * V_259 ;
struct V_229 * V_189 ;
F_120 ( V_7 -> V_8 . V_126 & ~ V_177 ) ;
F_120 ( ! V_7 -> V_30 ) ;
F_27 (vm, &dev_priv->vm_list, global_link) {
V_189 = F_226 ( V_7 , V_259 ) ;
if ( V_189 && ! F_200 ( & V_189 -> V_258 ) )
F_203 ( & V_189 -> V_258 , & V_259 -> V_261 ) ;
}
F_227 ( & V_7 -> V_249 ) ;
V_7 -> V_137 = NULL ;
V_7 -> V_175 = 0 ;
V_7 -> V_173 = 0 ;
V_7 -> V_8 . V_126 = 0 ;
V_7 -> V_252 = 0 ;
V_7 -> V_251 = false ;
V_7 -> V_30 = 0 ;
F_98 ( & V_7 -> V_8 ) ;
F_16 ( F_17 ( V_2 ) ) ;
}
static void
F_72 ( struct V_6 * V_7 )
{
struct V_136 * V_137 = V_7 -> V_137 ;
if ( V_137 == NULL )
return;
if ( F_134 ( V_137 -> V_156 ( V_137 , true ) ,
V_7 -> V_175 ) )
F_225 ( V_7 ) ;
}
static int
F_228 ( struct V_1 * V_2 , T_6 V_138 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
int V_23 , V_58 , V_262 ;
F_229 (ring, dev_priv, i) {
V_23 = F_230 ( V_137 ) ;
if ( V_23 )
return V_23 ;
}
F_231 ( V_2 ) ;
F_229 (ring, dev_priv, i) {
F_232 ( V_137 , V_138 ) ;
for ( V_262 = 0 ; V_262 < F_233 ( V_137 -> V_263 . V_264 ) ; V_262 ++ )
V_137 -> V_263 . V_264 [ V_262 ] = 0 ;
}
return 0 ;
}
int F_234 ( struct V_1 * V_2 , T_6 V_138 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( V_138 == 0 )
return - V_40 ;
V_23 = F_228 ( V_2 , V_138 - 1 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_265 = V_138 ;
V_16 -> V_266 = V_138 - 1 ;
if ( V_16 -> V_266 == 0 )
V_16 -> V_266 -- ;
return 0 ;
}
int
F_235 ( struct V_1 * V_2 , T_6 * V_138 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( V_16 -> V_265 == 0 ) {
int V_23 = F_228 ( V_2 , 0 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_265 = 1 ;
}
* V_138 = V_16 -> V_266 = V_16 -> V_265 ++ ;
return 0 ;
}
int F_236 ( struct V_136 * V_137 ,
struct V_32 * V_33 ,
struct V_6 * V_7 ,
T_6 * V_267 )
{
struct V_15 * V_16 = V_137 -> V_2 -> V_27 ;
struct V_268 * V_269 ;
T_6 V_270 , V_271 ;
int V_23 ;
V_271 = F_237 ( V_137 ) ;
V_23 = F_238 ( V_137 ) ;
if ( V_23 )
return V_23 ;
V_269 = V_137 -> V_272 ;
if ( F_16 ( V_269 == NULL ) )
return - V_64 ;
V_270 = F_237 ( V_137 ) ;
V_23 = V_137 -> V_273 ( V_137 ) ;
if ( V_23 )
return V_23 ;
V_269 -> V_138 = F_223 ( V_137 ) ;
V_269 -> V_137 = V_137 ;
V_269 -> V_274 = V_271 ;
V_269 -> V_275 = V_270 ;
V_269 -> V_276 = V_7 ;
V_269 -> V_277 = V_137 -> V_278 ;
if ( V_269 -> V_277 )
F_239 ( V_269 -> V_277 ) ;
V_269 -> V_279 = V_157 ;
F_221 ( & V_269 -> V_280 , & V_137 -> V_281 ) ;
V_269 -> V_67 = NULL ;
if ( V_33 ) {
struct V_143 * V_67 = V_33 -> V_178 ;
F_7 ( & V_67 -> V_18 . V_282 ) ;
V_269 -> V_67 = V_67 ;
F_221 ( & V_269 -> V_283 ,
& V_67 -> V_18 . V_281 ) ;
F_8 ( & V_67 -> V_18 . V_282 ) ;
}
F_240 ( V_137 , V_269 -> V_138 ) ;
V_137 -> V_139 = 0 ;
V_137 -> V_272 = NULL ;
if ( ! V_16 -> V_284 . V_285 ) {
F_241 ( V_137 -> V_2 ) ;
F_242 ( & V_16 -> V_18 . V_159 ) ;
F_243 ( V_16 -> V_158 ,
& V_16 -> V_18 . V_286 ,
F_244 ( V_25 ) ) ;
F_245 ( V_16 -> V_2 ) ;
}
if ( V_267 )
* V_267 = V_269 -> V_138 ;
return 0 ;
}
static inline void
F_246 ( struct V_268 * V_269 )
{
struct V_143 * V_67 = V_269 -> V_67 ;
if ( ! V_67 )
return;
F_7 ( & V_67 -> V_18 . V_282 ) ;
F_197 ( & V_269 -> V_283 ) ;
V_269 -> V_67 = NULL ;
F_8 ( & V_67 -> V_18 . V_282 ) ;
}
static bool F_247 ( struct V_15 * V_16 ,
const struct V_287 * V_277 )
{
unsigned long V_288 ;
V_288 = F_248 () - V_277 -> V_289 . V_290 ;
if ( V_277 -> V_289 . V_291 )
return true ;
if ( V_288 <= V_292 ) {
if ( ! F_249 ( V_277 ) ) {
F_184 ( L_6 ) ;
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
struct V_287 * V_277 ,
const bool V_293 )
{
struct V_294 * V_295 ;
if ( F_16 ( ! V_277 ) )
return;
V_295 = & V_277 -> V_289 ;
if ( V_293 ) {
V_295 -> V_291 = F_247 ( V_16 , V_277 ) ;
V_295 -> V_296 ++ ;
V_295 -> V_290 = F_248 () ;
} else {
V_295 -> V_297 ++ ;
}
}
static void F_253 ( struct V_268 * V_269 )
{
F_197 ( & V_269 -> V_280 ) ;
F_246 ( V_269 ) ;
if ( V_269 -> V_277 )
F_254 ( V_269 -> V_277 ) ;
F_195 ( V_269 ) ;
}
struct V_268 *
F_255 ( struct V_136 * V_137 )
{
struct V_268 * V_269 ;
T_6 V_298 ;
V_298 = V_137 -> V_156 ( V_137 , false ) ;
F_27 (request, &ring->request_list, list) {
if ( F_134 ( V_298 , V_269 -> V_138 ) )
continue;
return V_269 ;
}
return NULL ;
}
static void F_256 ( struct V_15 * V_16 ,
struct V_136 * V_137 )
{
struct V_268 * V_269 ;
bool V_299 ;
V_269 = F_255 ( V_137 ) ;
if ( V_269 == NULL )
return;
V_299 = V_137 -> V_300 . V_301 >= V_302 ;
F_252 ( V_16 , V_269 -> V_277 , V_299 ) ;
F_257 (request, &ring->request_list, list)
F_252 ( V_16 , V_269 -> V_277 , false ) ;
}
static void F_258 ( struct V_15 * V_16 ,
struct V_136 * V_137 )
{
while ( ! F_200 ( & V_137 -> V_250 ) ) {
struct V_6 * V_7 ;
V_7 = F_201 ( & V_137 -> V_250 ,
struct V_6 ,
V_249 ) ;
F_225 ( V_7 ) ;
}
while ( ! F_200 ( & V_137 -> V_281 ) ) {
struct V_268 * V_269 ;
V_269 = F_201 ( & V_137 -> V_281 ,
struct V_268 ,
V_280 ) ;
F_253 ( V_269 ) ;
}
F_195 ( V_137 -> V_272 ) ;
V_137 -> V_272 = NULL ;
V_137 -> V_139 = 0 ;
}
void F_259 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_16 -> V_303 ; V_58 ++ ) {
struct V_253 * V_254 = & V_16 -> V_255 [ V_58 ] ;
if ( V_254 -> V_7 ) {
F_260 ( V_254 -> V_7 , V_254 ,
V_254 -> V_7 -> V_11 ) ;
} else {
F_261 ( V_2 , V_58 , NULL ) ;
}
}
}
void F_262 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
int V_58 ;
F_229 (ring, dev_priv, i)
F_256 ( V_16 , V_137 ) ;
F_229 (ring, dev_priv, i)
F_258 ( V_16 , V_137 ) ;
F_263 ( V_2 ) ;
F_259 ( V_2 ) ;
}
void
F_264 ( struct V_136 * V_137 )
{
T_5 V_138 ;
if ( F_200 ( & V_137 -> V_281 ) )
return;
F_16 ( F_17 ( V_137 -> V_2 ) ) ;
V_138 = V_137 -> V_156 ( V_137 , true ) ;
while ( ! F_200 ( & V_137 -> V_250 ) ) {
struct V_6 * V_7 ;
V_7 = F_201 ( & V_137 -> V_250 ,
struct V_6 ,
V_249 ) ;
if ( ! F_134 ( V_138 , V_7 -> V_175 ) )
break;
F_225 ( V_7 ) ;
}
while ( ! F_200 ( & V_137 -> V_281 ) ) {
struct V_268 * V_269 ;
V_269 = F_201 ( & V_137 -> V_281 ,
struct V_268 ,
V_280 ) ;
if ( ! F_134 ( V_138 , V_269 -> V_138 ) )
break;
F_265 ( V_137 , V_269 -> V_138 ) ;
V_137 -> V_304 -> V_305 = V_269 -> V_275 ;
F_253 ( V_269 ) ;
}
if ( F_76 ( V_137 -> V_306 &&
F_134 ( V_138 , V_137 -> V_306 ) ) ) {
V_137 -> V_171 ( V_137 ) ;
V_137 -> V_306 = 0 ;
}
F_16 ( F_17 ( V_137 -> V_2 ) ) ;
}
bool
F_231 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
bool V_307 = true ;
int V_58 ;
F_229 (ring, dev_priv, i) {
F_264 ( V_137 ) ;
V_307 &= F_200 ( & V_137 -> V_281 ) ;
}
if ( V_307 )
F_137 ( V_16 -> V_158 ,
& V_16 -> V_18 . V_159 ,
F_138 ( 100 ) ) ;
return V_307 ;
}
static void
F_266 ( struct V_308 * V_309 )
{
struct V_15 * V_16 =
F_267 ( V_309 , F_202 ( * V_16 ) , V_18 . V_286 . V_309 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_307 ;
V_307 = false ;
if ( F_268 ( & V_2 -> V_29 ) ) {
V_307 = F_231 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
}
if ( ! V_307 )
F_243 ( V_16 -> V_158 , & V_16 -> V_18 . V_286 ,
F_244 ( V_25 ) ) ;
}
static void
F_269 ( struct V_308 * V_309 )
{
struct V_15 * V_16 =
F_267 ( V_309 , F_202 ( * V_16 ) , V_18 . V_159 . V_309 ) ;
F_270 ( V_16 -> V_2 ) ;
}
static int
F_271 ( struct V_6 * V_7 )
{
int V_23 ;
if ( V_7 -> V_30 ) {
V_23 = F_119 ( V_7 -> V_137 , V_7 -> V_175 ) ;
if ( V_23 )
return V_23 ;
F_264 ( V_7 -> V_137 ) ;
}
return 0 ;
}
int
F_272 ( struct V_1 * V_2 , void * V_31 , struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_310 * args = V_31 ;
struct V_6 * V_7 ;
struct V_136 * V_137 = NULL ;
struct V_146 V_311 , * V_147 = NULL ;
unsigned V_145 ;
T_6 V_138 = 0 ;
int V_23 = 0 ;
if ( args -> V_312 >= 0 ) {
V_311 = F_273 ( args -> V_312 ) ;
V_147 = & V_311 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_95 ( F_96 ( V_2 , V_33 , args -> V_313 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_25 ( & V_2 -> V_29 ) ;
return - V_111 ;
}
V_23 = F_271 ( V_7 ) ;
if ( V_23 )
goto V_109;
if ( V_7 -> V_30 ) {
V_138 = V_7 -> V_175 ;
V_137 = V_7 -> V_137 ;
}
if ( V_138 == 0 )
goto V_109;
if ( ! args -> V_312 ) {
V_23 = - V_168 ;
goto V_109;
}
F_98 ( & V_7 -> V_8 ) ;
V_145 = F_142 ( & V_16 -> V_28 . V_145 ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_129 ( V_137 , V_138 , V_145 , true , V_147 , V_33 -> V_178 ) ;
if ( V_147 )
args -> V_312 = F_274 ( V_147 ) ;
return V_23 ;
V_109:
F_98 ( & V_7 -> V_8 ) ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_275 ( struct V_6 * V_7 ,
struct V_136 * V_314 )
{
struct V_136 * V_315 = V_7 -> V_137 ;
T_6 V_138 ;
int V_23 , V_316 ;
if ( V_315 == NULL || V_314 == V_315 )
return 0 ;
if ( V_314 == NULL || ! F_276 ( V_7 -> V_8 . V_2 ) )
return F_71 ( V_7 , false ) ;
V_316 = F_277 ( V_315 , V_314 ) ;
V_138 = V_7 -> V_175 ;
if ( V_138 <= V_315 -> V_263 . V_264 [ V_316 ] )
return 0 ;
V_23 = F_119 ( V_7 -> V_137 , V_138 ) ;
if ( V_23 )
return V_23 ;
F_278 ( V_315 , V_314 , V_138 ) ;
V_23 = V_314 -> V_263 . V_317 ( V_314 , V_315 , V_138 ) ;
if ( ! V_23 )
V_315 -> V_263 . V_264 [ V_316 ] = V_7 -> V_175 ;
return V_23 ;
}
static void F_279 ( struct V_6 * V_7 )
{
T_6 V_318 , V_319 ;
F_5 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_91 & V_180 ) == 0 )
return;
F_280 () ;
V_319 = V_7 -> V_8 . V_91 ;
V_318 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_91 &= ~ V_180 ;
V_7 -> V_8 . V_126 &= ~ V_180 ;
F_281 ( V_7 ,
V_319 ,
V_318 ) ;
}
int F_207 ( struct V_229 * V_189 )
{
struct V_6 * V_7 = V_189 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_200 ( & V_189 -> V_320 ) )
return 0 ;
if ( ! F_282 ( & V_189 -> V_321 ) ) {
F_283 ( V_189 ) ;
return 0 ;
}
if ( V_189 -> V_322 )
return - V_62 ;
F_120 ( V_7 -> V_216 == NULL ) ;
V_23 = F_284 ( V_7 ) ;
if ( V_23 )
return V_23 ;
if ( F_285 ( V_189 -> V_259 ) ) {
F_279 ( V_7 ) ;
V_23 = F_105 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
F_286 ( V_189 ) ;
V_189 -> V_323 ( V_189 ) ;
F_287 ( V_7 ) ;
F_227 ( & V_189 -> V_258 ) ;
if ( F_285 ( V_189 -> V_259 ) )
V_7 -> V_324 = true ;
F_288 ( & V_189 -> V_321 ) ;
F_283 ( V_189 ) ;
if ( F_200 ( & V_7 -> V_325 ) )
F_203 ( & V_7 -> V_220 , & V_16 -> V_18 . V_227 ) ;
F_92 ( V_7 ) ;
return 0 ;
}
int F_289 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
int V_23 , V_58 ;
F_229 (ring, dev_priv, i) {
V_23 = F_290 ( V_137 , V_137 -> V_326 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_230 ( V_137 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static void F_291 ( struct V_1 * V_2 , int V_254 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_13 ;
int V_327 ;
if ( F_22 ( V_2 ) -> V_41 >= 6 ) {
V_13 = V_328 ;
V_327 = V_329 ;
} else {
V_13 = V_330 ;
V_327 = V_331 ;
}
V_13 += V_254 * 8 ;
F_292 ( V_13 , 0 ) ;
F_293 ( V_13 ) ;
if ( V_7 ) {
T_6 V_17 = F_29 ( V_7 ) ;
T_4 V_332 ;
V_332 = ( T_4 ) ( ( F_106 ( V_7 ) + V_17 - 4096 ) &
0xfffff000 ) << 32 ;
V_332 |= F_106 ( V_7 ) & 0xfffff000 ;
V_332 |= ( T_4 ) ( ( V_7 -> V_333 / 128 ) - 1 ) << V_327 ;
if ( V_7 -> V_11 == V_334 )
V_332 |= 1 << V_335 ;
V_332 |= V_336 ;
F_292 ( V_13 + 4 , V_332 >> 32 ) ;
F_293 ( V_13 + 4 ) ;
F_292 ( V_13 + 0 , V_332 ) ;
F_293 ( V_13 ) ;
} else {
F_292 ( V_13 + 4 , 0 ) ;
F_293 ( V_13 + 4 ) ;
}
}
static void F_294 ( struct V_1 * V_2 , int V_254 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_332 ;
if ( V_7 ) {
T_6 V_17 = F_29 ( V_7 ) ;
int V_337 ;
int V_338 ;
F_133 ( ( F_106 ( V_7 ) & ~ V_339 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_106 ( V_7 ) & ( V_17 - 1 ) ) ,
L_8 ,
F_106 ( V_7 ) , V_7 -> V_324 , V_17 ) ;
if ( V_7 -> V_11 == V_334 && F_295 ( V_2 ) )
V_338 = 128 ;
else
V_338 = 512 ;
V_337 = V_7 -> V_333 / V_338 ;
V_337 = F_296 ( V_337 ) - 1 ;
V_332 = F_106 ( V_7 ) ;
if ( V_7 -> V_11 == V_334 )
V_332 |= 1 << V_340 ;
V_332 |= F_297 ( V_17 ) ;
V_332 |= V_337 << V_341 ;
V_332 |= V_342 ;
} else
V_332 = 0 ;
if ( V_254 < 8 )
V_254 = V_343 + V_254 * 4 ;
else
V_254 = V_344 + ( V_254 - 8 ) * 4 ;
F_292 ( V_254 , V_332 ) ;
F_293 ( V_254 ) ;
}
static void F_298 ( struct V_1 * V_2 , int V_254 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_5 V_332 ;
if ( V_7 ) {
T_6 V_17 = F_29 ( V_7 ) ;
T_5 V_337 ;
F_133 ( ( F_106 ( V_7 ) & ~ V_345 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_106 ( V_7 ) & ( V_17 - 1 ) ) ,
L_9 ,
F_106 ( V_7 ) , V_17 ) ;
V_337 = V_7 -> V_333 / 128 ;
V_337 = F_296 ( V_337 ) - 1 ;
V_332 = F_106 ( V_7 ) ;
if ( V_7 -> V_11 == V_334 )
V_332 |= 1 << V_340 ;
V_332 |= F_299 ( V_17 ) ;
V_332 |= V_337 << V_341 ;
V_332 |= V_342 ;
} else
V_332 = 0 ;
F_292 ( V_343 + V_254 * 4 , V_332 ) ;
F_293 ( V_343 + V_254 * 4 ) ;
}
inline static bool F_300 ( struct V_6 * V_7 )
{
return V_7 && V_7 -> V_8 . V_91 & V_180 ;
}
static void F_261 ( struct V_1 * V_2 , int V_254 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_300 ( V_16 -> V_255 [ V_254 ] . V_7 ) )
F_280 () ;
F_133 ( V_7 && ( ! V_7 -> V_333 || ! V_7 -> V_11 ) ,
L_10 ,
V_7 -> V_333 , V_7 -> V_11 ) ;
switch ( F_22 ( V_2 ) -> V_41 ) {
case 8 :
case 7 :
case 6 :
case 5 :
case 4 : F_291 ( V_2 , V_254 , V_7 ) ; break;
case 3 : F_294 ( V_2 , V_254 , V_7 ) ; break;
case 2 : F_298 ( V_2 , V_254 , V_7 ) ; break;
default: F_301 () ;
}
if ( F_300 ( V_7 ) )
F_280 () ;
}
static inline int F_302 ( struct V_15 * V_16 ,
struct V_253 * V_346 )
{
return V_346 - V_16 -> V_255 ;
}
static void F_260 ( struct V_6 * V_7 ,
struct V_253 * V_346 ,
bool V_347 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_254 = F_302 ( V_16 , V_346 ) ;
F_261 ( V_7 -> V_8 . V_2 , V_254 , V_347 ? V_7 : NULL ) ;
if ( V_347 ) {
V_7 -> V_13 = V_254 ;
V_346 -> V_7 = V_7 ;
F_203 ( & V_346 -> V_256 , & V_16 -> V_18 . V_257 ) ;
} else {
V_7 -> V_13 = V_14 ;
V_346 -> V_7 = NULL ;
F_227 ( & V_346 -> V_256 ) ;
}
V_7 -> V_12 = false ;
}
static int
F_303 ( struct V_6 * V_7 )
{
if ( V_7 -> V_252 ) {
int V_23 = F_155 ( V_7 -> V_137 , V_7 -> V_252 ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_252 = 0 ;
}
V_7 -> V_251 = false ;
return 0 ;
}
int
F_105 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_253 * V_346 ;
int V_23 ;
V_23 = F_303 ( V_7 ) ;
if ( V_23 )
return V_23 ;
if ( V_7 -> V_13 == V_14 )
return 0 ;
V_346 = & V_16 -> V_255 [ V_7 -> V_13 ] ;
if ( F_16 ( V_346 -> V_322 ) )
return - V_62 ;
F_4 ( V_7 ) ;
F_260 ( V_7 , V_346 , false ) ;
return 0 ;
}
static struct V_253 *
F_304 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_253 * V_254 , * V_348 ;
int V_58 ;
V_348 = NULL ;
for ( V_58 = V_16 -> V_349 ; V_58 < V_16 -> V_303 ; V_58 ++ ) {
V_254 = & V_16 -> V_255 [ V_58 ] ;
if ( ! V_254 -> V_7 )
return V_254 ;
if ( ! V_254 -> V_322 )
V_348 = V_254 ;
}
if ( V_348 == NULL )
goto V_350;
F_27 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_254 -> V_322 )
continue;
return V_254 ;
}
V_350:
if ( F_305 ( V_2 ) )
return F_306 ( - V_135 ) ;
return F_306 ( - V_351 ) ;
}
int
F_167 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_347 = V_7 -> V_11 != V_132 ;
struct V_253 * V_254 ;
int V_23 ;
if ( V_7 -> V_12 ) {
V_23 = F_303 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_7 -> V_13 != V_14 ) {
V_254 = & V_16 -> V_255 [ V_7 -> V_13 ] ;
if ( ! V_7 -> V_12 ) {
F_203 ( & V_254 -> V_256 ,
& V_16 -> V_18 . V_257 ) ;
return 0 ;
}
} else if ( V_347 ) {
V_254 = F_304 ( V_2 ) ;
if ( F_33 ( V_254 ) )
return F_47 ( V_254 ) ;
if ( V_254 -> V_7 ) {
struct V_6 * V_352 = V_254 -> V_7 ;
V_23 = F_303 ( V_352 ) ;
if ( V_23 )
return V_23 ;
F_4 ( V_352 ) ;
}
} else
return 0 ;
F_260 ( V_7 , V_254 , V_347 ) ;
return 0 ;
}
static bool F_307 ( struct V_1 * V_2 ,
struct V_353 * V_354 ,
unsigned long V_9 )
{
struct V_353 * V_355 ;
if ( F_2 ( V_2 ) )
return true ;
if ( ! F_282 ( V_354 ) )
return true ;
if ( F_200 ( & V_354 -> V_356 ) )
return true ;
V_355 = F_308 ( V_354 -> V_356 . V_357 , struct V_353 , V_356 ) ;
if ( V_355 -> V_358 && ! V_355 -> V_359 && V_355 -> V_360 != V_9 )
return false ;
V_355 = F_308 ( V_354 -> V_356 . V_361 , struct V_353 , V_356 ) ;
if ( V_355 -> V_358 && ! V_354 -> V_359 && V_355 -> V_360 != V_9 )
return false ;
return true ;
}
static void F_309 ( struct V_1 * V_2 )
{
#if V_362
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_6 * V_7 ;
int V_363 = 0 ;
F_27 (obj, &dev_priv->mm.gtt_list, global_list) {
if ( V_7 -> V_354 == NULL ) {
F_310 ( V_364 L_11 ) ;
V_363 ++ ;
continue;
}
if ( V_7 -> V_9 != V_7 -> V_354 -> V_360 ) {
F_310 ( V_364 L_12 ,
F_106 ( V_7 ) ,
F_106 ( V_7 ) + F_29 ( V_7 ) ,
V_7 -> V_9 ,
V_7 -> V_354 -> V_360 ) ;
V_363 ++ ;
continue;
}
if ( ! F_307 ( V_2 ,
V_7 -> V_354 ,
V_7 -> V_9 ) ) {
F_310 ( V_364 L_13 ,
F_106 ( V_7 ) ,
F_106 ( V_7 ) + F_29 ( V_7 ) ,
V_7 -> V_9 ) ;
V_363 ++ ;
continue;
}
}
F_16 ( V_363 ) ;
#endif
}
static struct V_229 *
F_311 ( struct V_6 * V_7 ,
struct V_260 * V_259 ,
unsigned V_365 ,
T_4 V_195 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_17 , V_366 , V_367 , V_368 ;
unsigned long V_98 =
V_195 & V_369 ? V_195 & V_370 : 0 ;
unsigned long V_99 =
V_195 & V_118 ? V_16 -> V_42 . V_43 : V_259 -> V_47 ;
struct V_229 * V_189 ;
int V_23 ;
V_366 = F_173 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ) ;
V_367 = F_174 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , true ) ;
V_368 =
F_174 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , false ) ;
if ( V_365 == 0 )
V_365 = V_195 & V_118 ? V_367 :
V_368 ;
if ( V_195 & V_118 && V_365 & ( V_367 - 1 ) ) {
F_184 ( L_14 , V_365 ) ;
return F_306 ( - V_40 ) ;
}
V_17 = V_195 & V_118 ? V_366 : V_7 -> V_8 . V_17 ;
if ( V_7 -> V_8 . V_17 > V_99 ) {
F_184 ( L_15 ,
V_7 -> V_8 . V_17 ,
V_195 & V_118 ? L_16 : L_17 ,
V_99 ) ;
return F_306 ( - V_212 ) ;
}
V_23 = F_73 ( V_7 ) ;
if ( V_23 )
return F_306 ( V_23 ) ;
F_74 ( V_7 ) ;
V_189 = F_312 ( V_7 , V_259 ) ;
if ( F_33 ( V_189 ) )
goto V_371;
V_372:
V_23 = F_313 ( & V_259 -> V_18 , & V_189 -> V_321 ,
V_17 , V_365 ,
V_7 -> V_9 ,
V_98 , V_99 ,
V_373 ,
V_374 ) ;
if ( V_23 ) {
V_23 = F_314 ( V_2 , V_259 , V_17 , V_365 ,
V_7 -> V_9 ,
V_98 , V_99 ,
V_195 ) ;
if ( V_23 == 0 )
goto V_372;
goto V_375;
}
if ( F_16 ( ! F_307 ( V_2 , & V_189 -> V_321 ,
V_7 -> V_9 ) ) ) {
V_23 = - V_40 ;
goto V_376;
}
V_23 = F_315 ( V_7 ) ;
if ( V_23 )
goto V_376;
F_203 ( & V_7 -> V_220 , & V_16 -> V_18 . V_228 ) ;
F_221 ( & V_189 -> V_258 , & V_259 -> V_261 ) ;
if ( F_285 ( V_259 ) ) {
bool V_122 , V_377 ;
V_377 = ( V_189 -> V_321 . V_17 == V_366 &&
( V_189 -> V_321 . V_98 & ( V_367 - 1 ) ) == 0 ) ;
V_122 = ( V_189 -> V_321 . V_98 + V_7 -> V_8 . V_17 <=
V_16 -> V_42 . V_43 ) ;
V_7 -> V_324 = V_122 && V_377 ;
}
F_16 ( V_195 & V_118 && ! V_7 -> V_324 ) ;
F_316 ( V_189 , V_195 ) ;
V_189 -> V_378 ( V_189 , V_7 -> V_9 ,
V_195 & ( V_118 | V_379 ) ? V_380 : 0 ) ;
F_309 ( V_2 ) ;
return V_189 ;
V_376:
F_288 ( & V_189 -> V_321 ) ;
V_375:
F_283 ( V_189 ) ;
V_189 = F_306 ( V_23 ) ;
V_371:
F_92 ( V_7 ) ;
return V_189 ;
}
bool
F_112 ( struct V_6 * V_7 ,
bool V_381 )
{
if ( V_7 -> V_216 == NULL )
return false ;
if ( V_7 -> V_382 )
return false ;
if ( ! V_381 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) )
return false ;
F_317 ( V_7 ) ;
F_318 ( V_7 -> V_216 ) ;
return true ;
}
static void
F_319 ( struct V_6 * V_7 )
{
T_5 V_318 ;
if ( V_7 -> V_8 . V_126 != V_180 )
return;
F_320 () ;
V_318 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_126 = 0 ;
F_281 ( V_7 ,
V_7 -> V_8 . V_91 ,
V_318 ) ;
}
static void
F_161 ( struct V_6 * V_7 ,
bool V_381 )
{
T_5 V_318 ;
if ( V_7 -> V_8 . V_126 != V_92 )
return;
if ( F_112 ( V_7 , V_381 ) )
F_40 ( V_7 -> V_8 . V_2 ) ;
V_318 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_126 = 0 ;
F_281 ( V_7 ,
V_7 -> V_8 . V_91 ,
V_318 ) ;
}
int
F_104 ( struct V_6 * V_7 , bool V_194 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
T_5 V_318 , V_319 ;
int V_23 ;
if ( ! F_19 ( V_7 ) )
return - V_40 ;
if ( V_7 -> V_8 . V_126 == V_180 )
return 0 ;
V_23 = F_71 ( V_7 , ! V_194 ) ;
if ( V_23 )
return V_23 ;
F_72 ( V_7 ) ;
F_161 ( V_7 , false ) ;
if ( ( V_7 -> V_8 . V_91 & V_180 ) == 0 )
F_280 () ;
V_318 = V_7 -> V_8 . V_126 ;
V_319 = V_7 -> V_8 . V_91 ;
F_120 ( ( V_7 -> V_8 . V_126 & ~ V_180 ) != 0 ) ;
V_7 -> V_8 . V_91 |= V_180 ;
if ( V_194 ) {
V_7 -> V_8 . V_91 = V_180 ;
V_7 -> V_8 . V_126 = V_180 ;
V_7 -> V_127 = 1 ;
}
F_281 ( V_7 ,
V_319 ,
V_318 ) ;
if ( F_18 ( V_7 ) ) {
struct V_229 * V_189 = F_321 ( V_7 ) ;
if ( V_189 )
F_203 ( & V_189 -> V_258 ,
& V_16 -> V_42 . V_8 . V_261 ) ;
}
return 0 ;
}
int F_322 ( struct V_6 * V_7 ,
enum V_3 V_9 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_229 * V_189 , * V_361 ;
int V_23 ;
if ( V_7 -> V_9 == V_9 )
return 0 ;
if ( F_28 ( V_7 ) ) {
F_184 ( L_18 ) ;
return - V_62 ;
}
F_206 (vma, next, &obj->vma_list, vma_link) {
if ( ! F_307 ( V_2 , & V_189 -> V_321 , V_9 ) ) {
V_23 = F_207 ( V_189 ) ;
if ( V_23 )
return V_23 ;
}
}
if ( F_19 ( V_7 ) ) {
V_23 = F_284 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_279 ( V_7 ) ;
if ( F_22 ( V_2 ) -> V_41 < 6 ) {
V_23 = F_105 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
F_27 (vma, &obj->vma_list, vma_link)
if ( F_282 ( & V_189 -> V_321 ) )
V_189 -> V_378 ( V_189 , V_9 ,
V_7 -> V_383 ? V_380 : 0 ) ;
}
F_27 (vma, &obj->vma_list, vma_link)
V_189 -> V_321 . V_360 = V_9 ;
V_7 -> V_9 = V_9 ;
if ( F_3 ( V_7 ) ) {
T_6 V_319 , V_318 ;
F_72 ( V_7 ) ;
F_16 ( V_7 -> V_8 . V_126 & ~ V_92 ) ;
V_319 = V_7 -> V_8 . V_91 ;
V_318 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_91 = V_92 ;
V_7 -> V_8 . V_126 = V_92 ;
F_281 ( V_7 ,
V_319 ,
V_318 ) ;
}
F_309 ( V_2 ) ;
return 0 ;
}
int F_323 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_384 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_95 ( F_96 ( V_2 , V_33 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
switch ( V_7 -> V_9 ) {
case V_385 :
case V_386 :
args -> V_387 = V_388 ;
break;
case V_389 :
args -> V_387 = V_390 ;
break;
default:
args -> V_387 = V_391 ;
break;
}
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_324 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_384 * args = V_31 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_23 ;
switch ( args -> V_387 ) {
case V_391 :
V_4 = V_5 ;
break;
case V_388 :
V_4 = V_385 ;
break;
case V_390 :
V_4 = F_325 ( V_2 ) ? V_389 : V_5 ;
break;
default:
return - V_40 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_95 ( F_96 ( V_2 , V_33 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
V_23 = F_322 ( V_7 , V_4 ) ;
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static bool F_326 ( struct V_6 * V_7 )
{
struct V_229 * V_189 ;
if ( F_200 ( & V_7 -> V_325 ) )
return false ;
V_189 = F_321 ( V_7 ) ;
if ( ! V_189 )
return false ;
return V_189 -> V_322 - ! ! V_7 -> V_392 ;
}
int
F_327 ( struct V_6 * V_7 ,
T_6 V_365 ,
struct V_136 * V_393 )
{
T_6 V_319 , V_318 ;
bool V_394 ;
int V_23 ;
if ( V_393 != V_7 -> V_137 ) {
V_23 = F_275 ( V_7 , V_393 ) ;
if ( V_23 )
return V_23 ;
}
V_394 = V_7 -> V_10 ;
V_7 -> V_10 = true ;
V_23 = F_322 ( V_7 ,
F_325 ( V_7 -> V_8 . V_2 ) ? V_389 : V_5 ) ;
if ( V_23 )
goto V_395;
V_23 = F_103 ( V_7 , V_365 , V_118 ) ;
if ( V_23 )
goto V_395;
F_161 ( V_7 , true ) ;
V_318 = V_7 -> V_8 . V_126 ;
V_319 = V_7 -> V_8 . V_91 ;
V_7 -> V_8 . V_126 = 0 ;
V_7 -> V_8 . V_91 |= V_180 ;
F_281 ( V_7 ,
V_319 ,
V_318 ) ;
return 0 ;
V_395:
F_16 ( V_394 != F_326 ( V_7 ) ) ;
V_7 -> V_10 = V_394 ;
return V_23 ;
}
void
F_328 ( struct V_6 * V_7 )
{
F_107 ( V_7 ) ;
V_7 -> V_10 = F_326 ( V_7 ) ;
}
int
F_284 ( struct V_6 * V_7 )
{
int V_23 ;
if ( ( V_7 -> V_8 . V_91 & V_177 ) == 0 )
return 0 ;
V_23 = F_71 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_8 . V_91 &= ~ V_177 ;
return 0 ;
}
int
F_159 ( struct V_6 * V_7 , bool V_194 )
{
T_5 V_318 , V_319 ;
int V_23 ;
if ( V_7 -> V_8 . V_126 == V_92 )
return 0 ;
V_23 = F_71 ( V_7 , ! V_194 ) ;
if ( V_23 )
return V_23 ;
F_72 ( V_7 ) ;
F_319 ( V_7 ) ;
V_318 = V_7 -> V_8 . V_126 ;
V_319 = V_7 -> V_8 . V_91 ;
if ( ( V_7 -> V_8 . V_91 & V_92 ) == 0 ) {
F_112 ( V_7 , false ) ;
V_7 -> V_8 . V_91 |= V_92 ;
}
F_120 ( ( V_7 -> V_8 . V_126 & ~ V_92 ) != 0 ) ;
if ( V_194 ) {
V_7 -> V_8 . V_91 = V_92 ;
V_7 -> V_8 . V_126 = V_92 ;
}
F_281 ( V_7 ,
V_319 ,
V_318 ) ;
return 0 ;
}
static int
F_329 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_143 * V_67 = V_33 -> V_178 ;
unsigned long V_396 = V_157 - F_138 ( 20 ) ;
struct V_268 * V_269 ;
struct V_136 * V_137 = NULL ;
unsigned V_145 ;
T_6 V_138 = 0 ;
int V_23 ;
V_23 = F_10 ( & V_16 -> V_28 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_116 ( & V_16 -> V_28 , false ) ;
if ( V_23 )
return V_23 ;
F_7 ( & V_67 -> V_18 . V_282 ) ;
F_27 (request, &file_priv->mm.request_list, client_list) {
if ( F_144 ( V_269 -> V_279 , V_396 ) )
break;
V_137 = V_269 -> V_137 ;
V_138 = V_269 -> V_138 ;
}
V_145 = F_142 ( & V_16 -> V_28 . V_145 ) ;
F_8 ( & V_67 -> V_18 . V_282 ) ;
if ( V_138 == 0 )
return 0 ;
V_23 = F_129 ( V_137 , V_138 , V_145 , true , NULL , NULL ) ;
if ( V_23 == 0 )
F_243 ( V_16 -> V_158 , & V_16 -> V_18 . V_286 , 0 ) ;
return V_23 ;
}
static bool
F_330 ( struct V_229 * V_189 , T_5 V_365 , T_4 V_195 )
{
struct V_6 * V_7 = V_189 -> V_7 ;
if ( V_365 &&
V_189 -> V_321 . V_98 & ( V_365 - 1 ) )
return true ;
if ( V_195 & V_118 && ! V_7 -> V_324 )
return true ;
if ( V_195 & V_369 &&
V_189 -> V_321 . V_98 < ( V_195 & V_370 ) )
return true ;
return false ;
}
int
F_331 ( struct V_6 * V_7 ,
struct V_260 * V_259 ,
T_5 V_365 ,
T_4 V_195 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_229 * V_189 ;
int V_23 ;
if ( F_16 ( V_259 == & V_16 -> V_18 . V_397 -> V_8 ) )
return - V_36 ;
if ( F_16 ( V_195 & ( V_379 | V_118 ) && ! F_285 ( V_259 ) ) )
return - V_40 ;
V_189 = F_226 ( V_7 , V_259 ) ;
if ( V_189 ) {
if ( F_16 ( V_189 -> V_322 == V_398 ) )
return - V_62 ;
if ( F_330 ( V_189 , V_365 , V_195 ) ) {
F_133 ( V_189 -> V_322 ,
L_19
L_20
L_21 ,
F_332 ( V_7 , V_259 ) , V_365 ,
! ! ( V_195 & V_118 ) ,
V_7 -> V_324 ) ;
V_23 = F_207 ( V_189 ) ;
if ( V_23 )
return V_23 ;
V_189 = NULL ;
}
}
if ( V_189 == NULL || ! F_282 ( & V_189 -> V_321 ) ) {
V_189 = F_311 ( V_7 , V_259 , V_365 , V_195 ) ;
if ( F_33 ( V_189 ) )
return F_47 ( V_189 ) ;
}
if ( V_195 & V_379 && ! V_7 -> V_383 )
V_189 -> V_378 ( V_189 , V_7 -> V_9 , V_380 ) ;
V_189 -> V_322 ++ ;
if ( V_195 & V_118 )
V_7 -> V_399 |= true ;
return 0 ;
}
void
F_107 ( struct V_6 * V_7 )
{
struct V_229 * V_189 = F_321 ( V_7 ) ;
F_120 ( ! V_189 ) ;
F_120 ( V_189 -> V_322 == 0 ) ;
F_120 ( ! F_333 ( V_7 ) ) ;
if ( -- V_189 -> V_322 == 0 )
V_7 -> V_399 = false ;
}
bool
F_334 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 != V_14 ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_229 * V_400 = F_321 ( V_7 ) ;
F_16 ( ! V_400 ||
V_16 -> V_255 [ V_7 -> V_13 ] . V_322 >
V_400 -> V_322 ) ;
V_16 -> V_255 [ V_7 -> V_13 ] . V_322 ++ ;
return true ;
} else
return false ;
}
void
F_335 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 != V_14 ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
F_16 ( V_16 -> V_255 [ V_7 -> V_13 ] . V_322 <= 0 ) ;
V_16 -> V_255 [ V_7 -> V_13 ] . V_322 -- ;
}
}
int
F_336 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_401 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
if ( F_22 ( V_2 ) -> V_41 >= 6 )
return - V_36 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_95 ( F_96 ( V_2 , V_33 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
if ( V_7 -> V_51 != V_52 ) {
F_184 ( L_22 ) ;
V_23 = - V_63 ;
goto V_109;
}
if ( V_7 -> V_402 != NULL && V_7 -> V_402 != V_33 ) {
F_184 ( L_23 ,
args -> V_75 ) ;
V_23 = - V_40 ;
goto V_109;
}
if ( V_7 -> V_392 == V_403 ) {
V_23 = - V_62 ;
goto V_109;
}
if ( V_7 -> V_392 == 0 ) {
V_23 = F_103 ( V_7 , args -> V_365 , V_118 ) ;
if ( V_23 )
goto V_109;
}
V_7 -> V_392 ++ ;
V_7 -> V_402 = V_33 ;
args -> V_68 = F_106 ( V_7 ) ;
V_109:
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_337 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_401 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_95 ( F_96 ( V_2 , V_33 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
if ( V_7 -> V_402 != V_33 ) {
F_184 ( L_24 ,
args -> V_75 ) ;
V_23 = - V_40 ;
goto V_109;
}
V_7 -> V_392 -- ;
if ( V_7 -> V_392 == 0 ) {
V_7 -> V_402 = NULL ;
F_107 ( V_7 ) ;
}
V_109:
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_338 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_404 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_95 ( F_96 ( V_2 , V_33 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
V_23 = F_271 ( V_7 ) ;
args -> V_405 = V_7 -> V_30 ;
if ( V_7 -> V_137 ) {
F_339 ( V_406 > 16 ) ;
args -> V_405 |= F_131 ( V_7 -> V_137 ) << 16 ;
}
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_340 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_67 )
{
return F_329 ( V_2 , V_67 ) ;
}
int
F_341 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_67 )
{
struct V_407 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
switch ( args -> V_51 ) {
case V_214 :
case V_52 :
break;
default:
return - V_40 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_95 ( F_96 ( V_2 , V_67 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
if ( F_28 ( V_7 ) ) {
V_23 = - V_40 ;
goto V_109;
}
if ( V_7 -> V_51 != V_215 )
V_7 -> V_51 = args -> V_51 ;
if ( F_187 ( V_7 ) && V_7 -> V_216 == NULL )
F_188 ( V_7 ) ;
args -> V_408 = V_7 -> V_51 != V_215 ;
V_109:
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void F_342 ( struct V_6 * V_7 ,
const struct V_217 * V_218 )
{
F_199 ( & V_7 -> V_220 ) ;
F_199 ( & V_7 -> V_249 ) ;
F_199 ( & V_7 -> V_409 ) ;
F_199 ( & V_7 -> V_325 ) ;
V_7 -> V_218 = V_218 ;
V_7 -> V_13 = V_14 ;
V_7 -> V_51 = V_52 ;
V_7 -> V_324 = true ;
F_6 ( V_7 -> V_8 . V_2 -> V_27 , V_7 -> V_8 . V_17 ) ;
}
struct V_6 * F_58 ( struct V_1 * V_2 ,
T_1 V_17 )
{
struct V_6 * V_7 ;
struct V_53 * V_54 ;
T_12 V_410 ;
V_7 = F_52 ( V_2 ) ;
if ( V_7 == NULL )
return NULL ;
if ( F_343 ( V_2 , & V_7 -> V_8 , V_17 ) != 0 ) {
F_54 ( V_7 ) ;
return NULL ;
}
V_410 = V_411 | V_412 ;
if ( F_344 ( V_2 ) || F_345 ( V_2 ) ) {
V_410 &= ~ V_413 ;
V_410 |= V_247 ;
}
V_54 = F_31 ( V_7 -> V_8 . V_55 ) -> V_56 ;
F_346 ( V_54 , V_410 ) ;
F_342 ( V_7 , & V_414 ) ;
V_7 -> V_8 . V_126 = V_92 ;
V_7 -> V_8 . V_91 = V_92 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_9 = V_385 ;
} else
V_7 -> V_9 = V_5 ;
F_347 ( V_7 ) ;
return V_7 ;
}
static bool F_348 ( struct V_6 * V_7 )
{
if ( V_7 -> V_51 != V_52 )
return false ;
if ( V_7 -> V_8 . V_55 == NULL )
return true ;
return F_349 ( & V_7 -> V_8 . V_55 -> V_415 ) == 1 ;
}
void F_350 ( struct V_183 * V_416 )
{
struct V_6 * V_7 = F_95 ( V_416 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_229 * V_189 , * V_361 ;
F_165 ( V_16 ) ;
F_351 ( V_7 ) ;
F_206 (vma, next, &obj->vma_list, vma_link) {
int V_23 ;
V_189 -> V_322 = 0 ;
V_23 = F_207 ( V_189 ) ;
if ( F_16 ( V_23 == - V_167 ) ) {
bool V_417 ;
V_417 = V_16 -> V_18 . V_134 ;
V_16 -> V_18 . V_134 = false ;
F_16 ( F_207 ( V_189 ) ) ;
V_16 -> V_18 . V_134 = V_417 ;
}
}
F_30 ( V_7 ) ;
if ( V_7 -> V_382 )
F_92 ( V_7 ) ;
if ( F_16 ( V_7 -> V_219 ) )
V_7 -> V_219 = 0 ;
if ( F_348 ( V_7 ) )
V_7 -> V_51 = V_214 ;
F_196 ( V_7 ) ;
F_181 ( V_7 ) ;
F_352 ( V_7 ) ;
F_120 ( V_7 -> V_216 ) ;
if ( V_7 -> V_8 . V_418 )
F_353 ( & V_7 -> V_8 , NULL ) ;
if ( V_7 -> V_218 -> V_419 )
V_7 -> V_218 -> V_419 ( V_7 ) ;
F_354 ( & V_7 -> V_8 ) ;
F_9 ( V_16 , V_7 -> V_8 . V_17 ) ;
F_195 ( V_7 -> V_420 ) ;
F_54 ( V_7 ) ;
F_170 ( V_16 ) ;
}
struct V_229 * F_226 ( struct V_6 * V_7 ,
struct V_260 * V_259 )
{
struct V_229 * V_189 ;
F_27 (vma, &obj->vma_list, vma_link)
if ( V_189 -> V_259 == V_259 )
return V_189 ;
return NULL ;
}
void F_283 ( struct V_229 * V_189 )
{
F_16 ( V_189 -> V_321 . V_358 ) ;
if ( ! F_200 ( & V_189 -> V_421 ) )
return;
F_197 ( & V_189 -> V_320 ) ;
F_195 ( V_189 ) ;
}
static void
F_355 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
int V_58 ;
F_229 (ring, dev_priv, i)
F_356 ( V_137 ) ;
}
int
F_357 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 = 0 ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_16 -> V_284 . V_285 )
goto V_363;
V_23 = F_289 ( V_2 ) ;
if ( V_23 )
goto V_363;
F_231 ( V_2 ) ;
if ( ! F_21 ( V_2 , V_35 ) )
F_208 ( V_2 ) ;
F_358 ( V_2 ) ;
F_355 ( V_2 ) ;
V_16 -> V_284 . V_285 = ! F_21 ( V_2 ,
V_35 ) ;
F_25 ( & V_2 -> V_29 ) ;
F_359 ( & V_16 -> V_28 . V_422 ) ;
F_242 ( & V_16 -> V_18 . V_286 ) ;
F_242 ( & V_16 -> V_18 . V_159 ) ;
return 0 ;
V_363:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_360 ( struct V_136 * V_137 , int V_423 )
{
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_424 = V_425 + ( V_423 * 0x200 ) ;
T_6 * V_426 = V_16 -> V_427 . V_426 [ V_423 ] ;
int V_58 , V_23 ;
if ( ! F_361 ( V_2 ) || ! V_426 )
return 0 ;
V_23 = F_362 ( V_137 , V_428 / 4 * 3 ) ;
if ( V_23 )
return V_23 ;
for ( V_58 = 0 ; V_58 < V_428 ; V_58 += 4 ) {
F_363 ( V_137 , F_364 ( 1 ) ) ;
F_363 ( V_137 , V_424 + V_58 ) ;
F_363 ( V_137 , V_426 [ V_58 / 4 ] ) ;
}
F_365 ( V_137 ) ;
return V_23 ;
}
void F_366 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_22 ( V_2 ) -> V_41 < 5 ||
V_16 -> V_18 . V_429 == V_430 )
return;
F_292 ( V_431 , F_367 ( V_431 ) |
V_432 ) ;
if ( F_368 ( V_2 ) )
return;
F_292 ( V_433 , F_367 ( V_433 ) | V_434 ) ;
if ( F_369 ( V_2 ) )
F_292 ( V_435 , F_370 ( V_436 ) ) ;
else if ( F_371 ( V_2 ) )
F_292 ( V_435 , F_370 ( V_437 ) ) ;
else if ( F_372 ( V_2 ) )
F_292 ( V_438 , F_370 ( V_439 ) ) ;
else
F_301 () ;
}
static bool
F_373 ( struct V_1 * V_2 )
{
if ( ! F_374 ( V_2 ) )
return false ;
if ( F_369 ( V_2 ) && V_2 -> V_440 -> V_441 < 8 ) {
F_375 ( L_25
L_26 ) ;
return false ;
}
return true ;
}
static int F_376 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
V_23 = F_377 ( V_2 ) ;
if ( V_23 )
return V_23 ;
if ( F_378 ( V_2 ) ) {
V_23 = F_379 ( V_2 ) ;
if ( V_23 )
goto V_442;
}
if ( F_373 ( V_2 ) ) {
V_23 = F_380 ( V_2 ) ;
if ( V_23 )
goto V_443;
}
if ( F_381 ( V_2 ) ) {
V_23 = F_382 ( V_2 ) ;
if ( V_23 )
goto V_444;
}
if ( F_383 ( V_2 ) ) {
V_23 = F_384 ( V_2 ) ;
if ( V_23 )
goto V_445;
}
V_23 = F_234 ( V_2 , ( ( T_6 ) ~ 0 - 0x1000 ) ) ;
if ( V_23 )
goto V_446;
return 0 ;
V_446:
F_385 ( & V_16 -> V_137 [ V_447 ] ) ;
V_445:
F_385 ( & V_16 -> V_137 [ V_448 ] ) ;
V_444:
F_385 ( & V_16 -> V_137 [ V_449 ] ) ;
V_443:
F_385 ( & V_16 -> V_137 [ V_450 ] ) ;
V_442:
F_385 ( & V_16 -> V_137 [ V_451 ] ) ;
return V_23 ;
}
int
F_386 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 , V_58 ;
if ( F_22 ( V_2 ) -> V_41 < 6 && ! F_387 () )
return - V_26 ;
if ( V_16 -> V_452 )
F_292 ( V_453 , F_367 ( V_453 ) | F_388 ( 0xf ) ) ;
if ( F_389 ( V_2 ) )
F_292 ( V_454 , F_390 ( V_2 ) ?
V_455 : V_456 ) ;
if ( F_391 ( V_2 ) ) {
if ( F_392 ( V_2 ) ) {
T_6 V_457 = F_367 ( V_458 ) ;
V_457 &= ~ ( V_459 | V_460 ) ;
F_292 ( V_458 , V_457 ) ;
} else if ( F_22 ( V_2 ) -> V_41 >= 7 ) {
T_6 V_457 = F_367 ( V_461 ) ;
V_457 &= ~ V_462 ;
F_292 ( V_461 , V_457 ) ;
}
}
F_366 ( V_2 ) ;
V_23 = F_376 ( V_2 ) ;
if ( V_23 )
return V_23 ;
for ( V_58 = 0 ; V_58 < F_393 ( V_2 ) ; V_58 ++ )
F_360 ( & V_16 -> V_137 [ V_451 ] , V_58 ) ;
V_23 = F_394 ( V_16 ) ;
if ( V_23 && V_23 != - V_26 ) {
F_13 ( L_27 , V_23 ) ;
F_395 ( V_2 ) ;
}
return V_23 ;
}
int F_396 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
F_23 ( & V_2 -> V_29 ) ;
if ( F_397 ( V_2 ) ) {
F_292 ( V_463 , V_464 ) ;
if ( F_398 ( ( F_367 ( V_465 ) &
V_466 ) , 10 ) )
F_399 ( L_28 ) ;
}
F_400 ( V_2 ) ;
F_401 ( V_2 ) ;
V_23 = F_402 ( V_2 ) ;
if ( V_23 ) {
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
V_23 = F_386 ( V_2 ) ;
if ( V_23 == - V_26 ) {
F_13 ( L_29 ) ;
F_403 ( V_467 , & V_16 -> V_28 . V_145 ) ;
V_23 = 0 ;
}
F_25 ( & V_2 -> V_29 ) ;
if ( ! F_21 ( V_2 , V_35 ) )
V_16 -> V_468 . V_469 = 1 ;
return V_23 ;
}
void
F_395 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
int V_58 ;
F_229 (ring, dev_priv, i)
F_385 ( V_137 ) ;
}
int
F_404 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_67 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( F_21 ( V_2 , V_35 ) )
return 0 ;
if ( F_117 ( & V_16 -> V_28 ) ) {
F_13 ( L_30 ) ;
F_405 ( & V_16 -> V_28 . V_145 , 0 ) ;
}
F_23 ( & V_2 -> V_29 ) ;
V_16 -> V_284 . V_285 = 0 ;
V_23 = F_386 ( V_2 ) ;
if ( V_23 != 0 ) {
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
F_120 ( ! F_200 ( & V_16 -> V_42 . V_8 . V_250 ) ) ;
V_23 = F_406 ( V_2 , V_2 -> V_440 -> V_470 ) ;
if ( V_23 )
goto V_471;
F_25 ( & V_2 -> V_29 ) ;
return 0 ;
V_471:
F_395 ( V_2 ) ;
V_16 -> V_284 . V_285 = 1 ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_407 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_67 )
{
if ( F_21 ( V_2 , V_35 ) )
return 0 ;
F_23 ( & V_2 -> V_29 ) ;
F_408 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
return F_357 ( V_2 ) ;
}
void
F_409 ( struct V_1 * V_2 )
{
int V_23 ;
if ( F_21 ( V_2 , V_35 ) )
return;
V_23 = F_357 ( V_2 ) ;
if ( V_23 )
F_13 ( L_31 , V_23 ) ;
}
static void
F_410 ( struct V_136 * V_137 )
{
F_199 ( & V_137 -> V_250 ) ;
F_199 ( & V_137 -> V_281 ) ;
}
void F_411 ( struct V_15 * V_16 ,
struct V_260 * V_259 )
{
if ( ! F_285 ( V_259 ) )
F_412 ( & V_259 -> V_18 , V_259 -> V_98 , V_259 -> V_47 ) ;
V_259 -> V_2 = V_16 -> V_2 ;
F_199 ( & V_259 -> V_250 ) ;
F_199 ( & V_259 -> V_261 ) ;
F_199 ( & V_259 -> V_472 ) ;
F_221 ( & V_259 -> V_472 , & V_16 -> V_473 ) ;
}
void
F_413 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_58 ;
V_16 -> V_72 =
F_414 ( L_32 ,
sizeof( struct V_6 ) , 0 ,
V_474 ,
NULL ) ;
F_199 ( & V_16 -> V_473 ) ;
F_411 ( V_16 , & V_16 -> V_42 . V_8 ) ;
F_199 ( & V_16 -> V_475 ) ;
F_199 ( & V_16 -> V_18 . V_227 ) ;
F_199 ( & V_16 -> V_18 . V_228 ) ;
F_199 ( & V_16 -> V_18 . V_257 ) ;
for ( V_58 = 0 ; V_58 < V_406 ; V_58 ++ )
F_410 ( & V_16 -> V_137 [ V_58 ] ) ;
for ( V_58 = 0 ; V_58 < V_476 ; V_58 ++ )
F_199 ( & V_16 -> V_255 [ V_58 ] . V_256 ) ;
F_415 ( & V_16 -> V_18 . V_286 ,
F_266 ) ;
F_415 ( & V_16 -> V_18 . V_159 ,
F_269 ) ;
F_416 ( & V_16 -> V_28 . V_24 ) ;
if ( ! F_21 ( V_2 , V_35 ) && F_417 ( V_2 ) ) {
F_292 ( V_477 ,
F_370 ( V_478 ) ) ;
}
V_16 -> V_479 = V_480 ;
if ( ! F_21 ( V_2 , V_35 ) )
V_16 -> V_349 = 3 ;
if ( F_22 ( V_2 ) -> V_41 >= 7 && ! F_397 ( V_2 ) )
V_16 -> V_303 = 32 ;
else if ( F_22 ( V_2 ) -> V_41 >= 4 || F_418 ( V_2 ) || F_419 ( V_2 ) || F_175 ( V_2 ) )
V_16 -> V_303 = 16 ;
else
V_16 -> V_303 = 8 ;
F_199 ( & V_16 -> V_18 . V_257 ) ;
F_259 ( V_2 ) ;
F_420 ( V_2 ) ;
F_416 ( & V_16 -> V_481 ) ;
V_16 -> V_18 . V_134 = true ;
V_16 -> V_18 . V_482 . V_483 = V_484 ;
V_16 -> V_18 . V_482 . V_485 = V_486 ;
V_16 -> V_18 . V_482 . V_487 = V_488 ;
F_421 ( & V_16 -> V_18 . V_482 ) ;
V_16 -> V_18 . V_489 . V_490 = V_491 ;
F_422 ( & V_16 -> V_18 . V_489 ) ;
}
void F_423 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_143 * V_67 = V_33 -> V_178 ;
F_242 ( & V_67 -> V_18 . V_159 ) ;
F_7 ( & V_67 -> V_18 . V_282 ) ;
while ( ! F_200 ( & V_67 -> V_18 . V_281 ) ) {
struct V_268 * V_269 ;
V_269 = F_201 ( & V_67 -> V_18 . V_281 ,
struct V_268 ,
V_283 ) ;
F_197 ( & V_269 -> V_283 ) ;
V_269 -> V_67 = NULL ;
}
F_8 ( & V_67 -> V_18 . V_282 ) ;
}
static void
F_424 ( struct V_308 * V_309 )
{
struct V_143 * V_67 =
F_267 ( V_309 , F_202 ( * V_67 ) , V_18 . V_159 . V_309 ) ;
F_405 ( & V_67 -> V_144 , false ) ;
}
int F_425 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_143 * V_67 ;
int V_23 ;
F_399 ( L_33 ) ;
V_67 = F_426 ( sizeof( * V_67 ) , V_73 ) ;
if ( ! V_67 )
return - V_64 ;
V_33 -> V_178 = V_67 ;
V_67 -> V_16 = V_2 -> V_27 ;
V_67 -> V_33 = V_33 ;
F_427 ( & V_67 -> V_18 . V_282 ) ;
F_199 ( & V_67 -> V_18 . V_281 ) ;
F_415 ( & V_67 -> V_18 . V_159 ,
F_424 ) ;
V_23 = F_428 ( V_2 , V_33 ) ;
if ( V_23 )
F_195 ( V_67 ) ;
return V_23 ;
}
static bool F_429 ( struct V_492 * V_492 , struct V_140 * V_493 )
{
if ( ! F_121 ( V_492 ) )
return false ;
#if F_430 ( V_494 ) || F_430 ( V_495 )
return V_492 -> V_496 == V_493 ;
#else
return false ;
#endif
}
static bool F_431 ( struct V_1 * V_2 , bool * V_112 )
{
if ( ! F_268 ( & V_2 -> V_29 ) ) {
if ( ! F_429 ( & V_2 -> V_29 , V_166 ) )
return false ;
if ( F_432 ( V_2 ) -> V_18 . V_211 )
return false ;
* V_112 = false ;
} else
* V_112 = true ;
return true ;
}
static int F_433 ( struct V_6 * V_7 )
{
struct V_229 * V_189 ;
int V_226 = 0 ;
F_27 (vma, &obj->vma_list, vma_link)
if ( F_282 ( & V_189 -> V_321 ) )
V_226 ++ ;
return V_226 ;
}
static unsigned long
V_486 ( struct V_482 * V_482 , struct V_497 * V_498 )
{
struct V_15 * V_16 =
F_267 ( V_482 , struct V_15 , V_18 . V_482 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_6 * V_7 ;
unsigned long V_226 ;
bool V_112 ;
if ( ! F_431 ( V_2 , & V_112 ) )
return 0 ;
V_226 = 0 ;
F_27 (obj, &dev_priv->mm.unbound_list, global_list)
if ( V_7 -> V_219 == 0 )
V_226 += V_7 -> V_8 . V_17 >> V_199 ;
F_27 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_28 ( V_7 ) &&
V_7 -> V_219 == F_433 ( V_7 ) )
V_226 += V_7 -> V_8 . V_17 >> V_199 ;
}
if ( V_112 )
F_25 ( & V_2 -> V_29 ) ;
return V_226 ;
}
unsigned long F_332 ( struct V_6 * V_499 ,
struct V_260 * V_259 )
{
struct V_15 * V_16 = V_499 -> V_8 . V_2 -> V_27 ;
struct V_229 * V_189 ;
if ( ! V_16 -> V_18 . V_397 ||
V_259 == & V_16 -> V_18 . V_397 -> V_8 )
V_259 = & V_16 -> V_42 . V_8 ;
F_120 ( F_200 ( & V_499 -> V_325 ) ) ;
F_27 (vma, &o->vma_list, vma_link) {
if ( V_189 -> V_259 == V_259 )
return V_189 -> V_321 . V_98 ;
}
return - 1 ;
}
bool F_434 ( struct V_6 * V_499 ,
struct V_260 * V_259 )
{
struct V_229 * V_189 ;
F_27 (vma, &o->vma_list, vma_link)
if ( V_189 -> V_259 == V_259 && F_282 ( & V_189 -> V_321 ) )
return true ;
return false ;
}
bool F_19 ( struct V_6 * V_499 )
{
struct V_229 * V_189 ;
F_27 (vma, &o->vma_list, vma_link)
if ( F_282 ( & V_189 -> V_321 ) )
return true ;
return false ;
}
unsigned long F_435 ( struct V_6 * V_499 ,
struct V_260 * V_259 )
{
struct V_15 * V_16 = V_499 -> V_8 . V_2 -> V_27 ;
struct V_229 * V_189 ;
if ( ! V_16 -> V_18 . V_397 ||
V_259 == & V_16 -> V_18 . V_397 -> V_8 )
V_259 = & V_16 -> V_42 . V_8 ;
F_120 ( F_200 ( & V_499 -> V_325 ) ) ;
F_27 (vma, &o->vma_list, vma_link)
if ( V_189 -> V_259 == V_259 )
return V_189 -> V_321 . V_17 ;
return 0 ;
}
static unsigned long
V_484 ( struct V_482 * V_482 , struct V_497 * V_498 )
{
struct V_15 * V_16 =
F_267 ( V_482 , struct V_15 , V_18 . V_482 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_500 ;
bool V_112 ;
if ( ! F_431 ( V_2 , & V_112 ) )
return V_501 ;
V_500 = F_179 ( V_16 , V_498 -> V_502 ) ;
if ( V_500 < V_498 -> V_502 )
V_500 += F_198 ( V_16 ,
V_498 -> V_502 - V_500 ,
false ) ;
if ( V_112 )
F_25 ( & V_2 -> V_29 ) ;
return V_500 ;
}
static int
V_491 ( struct V_503 * V_504 , unsigned long V_505 , void * V_506 )
{
struct V_15 * V_16 =
F_267 ( V_504 , struct V_15 , V_18 . V_489 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_6 * V_7 ;
unsigned long V_147 = F_138 ( 5000 ) + 1 ;
unsigned long V_45 , V_507 , V_508 , V_500 ;
bool V_417 ;
bool V_112 ;
while ( ! F_431 ( V_2 , & V_112 ) && -- V_147 )
F_436 ( 1 ) ;
if ( V_147 == 0 ) {
F_437 ( L_34 ) ;
return V_509 ;
}
V_417 = V_16 -> V_18 . V_134 ;
V_16 -> V_18 . V_134 = false ;
V_500 = F_180 ( V_16 ) ;
V_16 -> V_18 . V_134 = V_417 ;
V_508 = V_507 = V_45 = 0 ;
F_27 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( ! V_7 -> V_8 . V_55 )
continue;
if ( V_7 -> V_219 )
V_45 += V_7 -> V_8 . V_17 ;
else
V_508 += V_7 -> V_8 . V_17 ;
}
F_27 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! V_7 -> V_8 . V_55 )
continue;
if ( V_7 -> V_219 )
V_45 += V_7 -> V_8 . V_17 ;
else
V_507 += V_7 -> V_8 . V_17 ;
}
if ( V_112 )
F_25 ( & V_2 -> V_29 ) ;
F_438 ( L_35 ,
V_500 , V_45 ) ;
if ( V_508 || V_507 )
F_437 ( L_36
L_37 ,
V_507 , V_508 ) ;
* ( unsigned long * ) V_506 += V_500 ;
return V_509 ;
}
struct V_229 * F_321 ( struct V_6 * V_7 )
{
struct V_229 * V_189 ;
if ( F_16 ( F_200 ( & V_7 -> V_325 ) ) )
return NULL ;
V_189 = F_201 ( & V_7 -> V_325 , F_202 ( * V_189 ) , V_320 ) ;
if ( V_189 -> V_259 != F_439 ( V_7 ) )
return NULL ;
return V_189 ;
}

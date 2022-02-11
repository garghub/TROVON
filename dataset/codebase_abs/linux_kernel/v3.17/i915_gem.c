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
int
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
T_10 * V_146 ,
struct V_143 * V_67 )
{
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
const bool V_147 =
F_130 ( V_16 -> V_28 . V_148 ) & F_131 ( V_137 ) ;
F_132 ( V_149 ) ;
unsigned long V_150 ;
T_10 V_151 , V_152 ;
int V_23 ;
F_133 ( ! F_134 ( V_16 ) , L_2 ) ;
if ( F_135 ( V_137 -> V_153 ( V_137 , true ) , V_138 ) )
return 0 ;
V_150 = V_146 ? V_154 + F_136 ( ( V_155 ) * V_146 ) : 0 ;
if ( F_22 ( V_2 ) -> V_41 >= 6 && V_137 -> V_141 == V_156 && F_127 ( V_67 ) ) {
F_137 ( V_16 ) ;
if ( V_67 )
F_138 ( V_16 -> V_157 ,
& V_67 -> V_18 . V_158 ,
F_139 ( 100 ) ) ;
}
if ( ! V_147 && F_16 ( ! V_137 -> V_159 ( V_137 ) ) )
return - V_36 ;
F_140 ( V_137 , V_138 ) ;
V_151 = F_141 () ;
for (; ; ) {
struct V_160 V_161 ;
F_142 ( & V_137 -> V_162 , & V_149 ,
V_134 ? V_163 : V_164 ) ;
if ( V_145 != F_143 ( & V_16 -> V_28 . V_145 ) ) {
V_23 = F_116 ( & V_16 -> V_28 , V_134 ) ;
if ( V_23 == 0 )
V_23 = - V_135 ;
break;
}
if ( F_135 ( V_137 -> V_153 ( V_137 , false ) , V_138 ) ) {
V_23 = 0 ;
break;
}
if ( V_134 && F_144 ( V_165 ) ) {
V_23 = - V_166 ;
break;
}
if ( V_146 && F_145 ( V_154 , V_150 ) ) {
V_23 = - V_167 ;
break;
}
V_161 . V_168 = NULL ;
if ( V_146 || F_125 ( V_16 , V_137 ) ) {
unsigned long V_169 ;
F_146 ( & V_161 , F_123 , ( unsigned long ) V_165 ) ;
V_169 = F_125 ( V_16 , V_137 ) ? V_154 + 1 : V_150 ;
F_147 ( & V_161 , V_169 ) ;
}
F_148 () ;
if ( V_161 . V_168 ) {
F_149 ( & V_161 ) ;
F_150 ( & V_161 ) ;
}
}
V_152 = F_141 () ;
F_151 ( V_137 , V_138 ) ;
if ( ! V_147 )
V_137 -> V_170 ( V_137 ) ;
F_152 ( & V_137 -> V_162 , & V_149 ) ;
if ( V_146 ) {
T_10 V_171 = * V_146 - ( V_152 - V_151 ) ;
* V_146 = V_171 < 0 ? 0 : V_171 ;
}
return V_23 ;
}
int
F_153 ( struct V_136 * V_137 , T_5 V_138 )
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
F_143 ( & V_16 -> V_28 . V_145 ) ,
V_134 , NULL , NULL ) ;
}
static int
F_154 ( struct V_6 * V_7 ,
struct V_136 * V_137 )
{
if ( ! V_7 -> V_30 )
return 0 ;
V_7 -> V_172 = 0 ;
return 0 ;
}
static T_11 int
F_71 ( struct V_6 * V_7 ,
bool V_173 )
{
struct V_136 * V_137 = V_7 -> V_137 ;
T_6 V_138 ;
int V_23 ;
V_138 = V_173 ? V_7 -> V_172 : V_7 -> V_174 ;
if ( V_138 == 0 )
return 0 ;
V_23 = F_153 ( V_137 , V_138 ) ;
if ( V_23 )
return V_23 ;
return F_154 ( V_7 , V_137 ) ;
}
static T_11 int
F_155 ( struct V_6 * V_7 ,
struct V_143 * V_67 ,
bool V_173 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 = V_7 -> V_137 ;
unsigned V_145 ;
T_6 V_138 ;
int V_23 ;
F_120 ( ! F_121 ( & V_2 -> V_29 ) ) ;
F_120 ( ! V_16 -> V_18 . V_134 ) ;
V_138 = V_173 ? V_7 -> V_172 : V_7 -> V_174 ;
if ( V_138 == 0 )
return 0 ;
V_23 = F_116 ( & V_16 -> V_28 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = F_119 ( V_137 , V_138 ) ;
if ( V_23 )
return V_23 ;
V_145 = F_143 ( & V_16 -> V_28 . V_145 ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_129 ( V_137 , V_138 , V_145 , true , NULL , V_67 ) ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_23 )
return V_23 ;
return F_154 ( V_7 , V_137 ) ;
}
int
F_156 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_175 * args = V_31 ;
struct V_6 * V_7 ;
T_5 V_91 = args -> V_91 ;
T_5 V_126 = args -> V_126 ;
int V_23 ;
if ( V_126 & V_176 )
return - V_40 ;
if ( V_91 & V_176 )
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
V_23 = F_155 ( V_7 ,
V_33 -> V_177 ,
! V_126 ) ;
if ( V_23 )
goto V_178;
if ( V_91 & V_179 ) {
V_23 = F_104 ( V_7 , V_126 != 0 ) ;
if ( V_23 == - V_40 )
V_23 = 0 ;
} else {
V_23 = F_157 ( V_7 , V_126 != 0 ) ;
}
V_178:
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_158 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_180 * args = V_31 ;
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
F_159 ( V_7 , true ) ;
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
struct V_182 * V_7 ;
unsigned long V_96 ;
V_7 = F_96 ( V_2 , V_33 , args -> V_75 ) ;
if ( V_7 == NULL )
return - V_111 ;
if ( ! V_7 -> V_55 ) {
F_60 ( V_7 ) ;
return - V_40 ;
}
V_96 = F_161 ( V_7 -> V_55 , 0 , args -> V_17 ,
V_183 | V_184 , V_185 ,
args -> V_68 ) ;
F_60 ( V_7 ) ;
if ( F_33 ( ( void * ) V_96 ) )
return V_96 ;
args -> V_186 = ( T_4 ) V_96 ;
return 0 ;
}
int F_162 ( struct V_187 * V_188 , struct V_189 * V_190 )
{
struct V_6 * V_7 = F_95 ( V_188 -> V_191 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_12 V_115 ;
unsigned long V_192 ;
int V_23 = 0 ;
bool V_193 = ! ! ( V_190 -> V_194 & V_195 ) ;
F_163 ( V_16 ) ;
V_115 = ( ( unsigned long ) V_190 -> V_196 - V_188 -> V_197 ) >>
V_198 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
goto V_109;
F_164 ( V_7 , V_115 , true , V_193 ) ;
V_23 = F_155 ( V_7 , NULL , ! V_193 ) ;
if ( V_23 )
goto V_112;
if ( V_7 -> V_9 != V_5 && ! F_2 ( V_2 ) ) {
V_23 = - V_63 ;
goto V_112;
}
V_23 = F_103 ( V_7 , 0 , V_118 ) ;
if ( V_23 )
goto V_112;
V_23 = F_104 ( V_7 , V_193 ) ;
if ( V_23 )
goto V_199;
V_23 = F_165 ( V_7 ) ;
if ( V_23 )
goto V_199;
V_192 = V_16 -> V_42 . V_200 + F_106 ( V_7 ) ;
V_192 >>= V_198 ;
if ( ! V_7 -> V_201 ) {
unsigned long V_17 = F_166 (unsigned long,
vma->vm_end - vma->vm_start,
obj->base.size) ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_17 > > V_198 ; V_58 ++ ) {
V_23 = F_167 ( V_188 ,
( unsigned long ) V_188 -> V_197 + V_58 * V_39 ,
V_192 + V_58 ) ;
if ( V_23 )
break;
}
V_7 -> V_201 = true ;
} else
V_23 = F_167 ( V_188 ,
( unsigned long ) V_190 -> V_196 ,
V_192 + V_115 ) ;
V_199:
F_107 ( V_7 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
V_109:
switch ( V_23 ) {
case - V_26 :
if ( ! F_118 ( & V_16 -> V_28 ) ) {
V_23 = V_202 ;
break;
}
case - V_135 :
case 0 :
case - V_166 :
case - V_203 :
case - V_62 :
V_23 = V_204 ;
break;
case - V_64 :
V_23 = V_205 ;
break;
case - V_133 :
case - V_63 :
V_23 = V_202 ;
break;
default:
F_168 ( V_23 , L_3 , V_23 ) ;
V_23 = V_202 ;
break;
}
F_169 ( V_16 ) ;
return V_23 ;
}
void
F_5 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_201 )
return;
F_170 ( & V_7 -> V_8 . V_206 ,
V_7 -> V_8 . V_2 -> V_207 -> V_56 ) ;
V_7 -> V_201 = false ;
}
void
F_171 ( struct V_15 * V_16 )
{
struct V_6 * V_7 ;
F_27 (obj, &dev_priv->mm.bound_list, global_list)
F_5 ( V_7 ) ;
}
T_5
F_172 ( struct V_1 * V_2 , T_5 V_17 , int V_11 )
{
T_5 V_208 ;
if ( F_22 ( V_2 ) -> V_41 >= 4 ||
V_11 == V_132 )
return V_17 ;
if ( F_22 ( V_2 ) -> V_41 == 3 )
V_208 = 1024 * 1024 ;
else
V_208 = 512 * 1024 ;
while ( V_208 < V_17 )
V_208 <<= 1 ;
return V_208 ;
}
T_5
F_173 ( struct V_1 * V_2 , T_5 V_17 ,
int V_11 , bool V_209 )
{
if ( F_22 ( V_2 ) -> V_41 >= 4 || ( ! V_209 && F_174 ( V_2 ) ) ||
V_11 == V_132 )
return 4096 ;
return F_172 ( V_2 , V_17 , V_11 ) ;
}
static int F_175 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_176 ( & V_7 -> V_8 . V_206 ) )
return 0 ;
V_16 -> V_18 . V_210 = true ;
V_23 = F_177 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_133 )
goto V_109;
F_178 ( V_16 , V_7 -> V_8 . V_17 >> V_198 ) ;
V_23 = F_177 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_133 )
goto V_109;
F_179 ( V_16 ) ;
V_23 = F_177 ( & V_7 -> V_8 ) ;
V_109:
V_16 -> V_18 . V_210 = false ;
return V_23 ;
}
static void F_180 ( struct V_6 * V_7 )
{
F_181 ( & V_7 -> V_8 ) ;
}
int
F_182 ( struct V_32 * V_33 ,
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
V_23 = - V_211 ;
goto V_109;
}
if ( V_7 -> V_51 != V_52 ) {
F_183 ( L_4 ) ;
V_23 = - V_63 ;
goto V_109;
}
V_23 = F_175 ( V_7 ) ;
if ( V_23 )
goto V_109;
* V_68 = F_184 ( & V_7 -> V_8 . V_206 ) ;
V_109:
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_185 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_212 * args = V_31 ;
return F_182 ( V_33 , V_2 , args -> V_75 , & args -> V_68 ) ;
}
static inline int
F_186 ( struct V_6 * V_7 )
{
return V_7 -> V_51 == V_213 ;
}
static void
F_187 ( struct V_6 * V_7 )
{
F_180 ( V_7 ) ;
if ( V_7 -> V_8 . V_55 == NULL )
return;
F_188 ( F_31 ( V_7 -> V_8 . V_55 ) , 0 , ( T_8 ) - 1 ) ;
V_7 -> V_51 = V_214 ;
}
static void
F_189 ( struct V_6 * V_7 )
{
struct V_53 * V_54 ;
switch ( V_7 -> V_51 ) {
case V_213 :
F_187 ( V_7 ) ;
case V_214 :
return;
}
if ( V_7 -> V_8 . V_55 == NULL )
return;
V_54 = F_31 ( V_7 -> V_8 . V_55 ) -> V_56 ,
F_190 ( V_54 , 0 , ( T_8 ) - 1 ) ;
}
static void
F_191 ( struct V_6 * V_7 )
{
struct V_104 V_105 ;
int V_23 ;
F_120 ( V_7 -> V_51 == V_214 ) ;
V_23 = F_157 ( V_7 , true ) ;
if ( V_23 ) {
F_16 ( V_23 != - V_26 ) ;
F_112 ( V_7 , true ) ;
V_7 -> V_8 . V_91 = V_7 -> V_8 . V_126 = V_92 ;
}
if ( F_85 ( V_7 ) )
F_192 ( V_7 ) ;
if ( V_7 -> V_51 == V_213 )
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
F_193 ( V_7 -> V_215 ) ;
F_194 ( V_7 -> V_215 ) ;
}
int
F_195 ( struct V_6 * V_7 )
{
const struct V_216 * V_217 = V_7 -> V_217 ;
if ( V_7 -> V_215 == NULL )
return 0 ;
if ( V_7 -> V_218 )
return - V_62 ;
F_120 ( F_19 ( V_7 ) ) ;
F_196 ( & V_7 -> V_219 ) ;
V_217 -> V_220 ( V_7 ) ;
V_7 -> V_215 = NULL ;
F_189 ( V_7 ) ;
return 0 ;
}
static unsigned long
F_197 ( struct V_15 * V_16 , long V_221 ,
bool V_222 )
{
struct V_223 V_224 ;
struct V_6 * V_7 ;
unsigned long V_225 = 0 ;
F_198 ( & V_224 ) ;
while ( V_225 < V_221 && ! F_199 ( & V_16 -> V_18 . V_226 ) ) {
V_7 = F_200 ( & V_16 -> V_18 . V_226 ,
F_201 ( * V_7 ) , V_219 ) ;
F_202 ( & V_7 -> V_219 , & V_224 ) ;
if ( ! F_186 ( V_7 ) && V_222 )
continue;
F_203 ( & V_7 -> V_8 ) ;
if ( F_195 ( V_7 ) == 0 )
V_225 += V_7 -> V_8 . V_17 >> V_198 ;
F_98 ( & V_7 -> V_8 ) ;
}
F_204 ( & V_224 , & V_16 -> V_18 . V_226 ) ;
F_198 ( & V_224 ) ;
while ( V_225 < V_221 && ! F_199 ( & V_16 -> V_18 . V_227 ) ) {
struct V_228 * V_188 , * V_229 ;
V_7 = F_200 ( & V_16 -> V_18 . V_227 ,
F_201 ( * V_7 ) , V_219 ) ;
F_202 ( & V_7 -> V_219 , & V_224 ) ;
if ( ! F_186 ( V_7 ) && V_222 )
continue;
F_203 ( & V_7 -> V_8 ) ;
F_205 (vma, v, &obj->vma_list, vma_link)
if ( F_206 ( V_188 ) )
break;
if ( F_195 ( V_7 ) == 0 )
V_225 += V_7 -> V_8 . V_17 >> V_198 ;
F_98 ( & V_7 -> V_8 ) ;
}
F_204 ( & V_224 , & V_16 -> V_18 . V_227 ) ;
return V_225 ;
}
static unsigned long
F_178 ( struct V_15 * V_16 , long V_221 )
{
return F_197 ( V_16 , V_221 , true ) ;
}
static unsigned long
F_179 ( struct V_15 * V_16 )
{
F_207 ( V_16 -> V_2 ) ;
return F_197 ( V_16 , V_230 , false ) ;
}
static int
F_208 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_231 , V_58 ;
struct V_53 * V_54 ;
struct V_232 * V_233 ;
struct V_234 * V_235 ;
struct V_104 V_105 ;
struct V_59 * V_59 ;
unsigned long V_236 = 0 ;
T_13 V_237 ;
F_120 ( V_7 -> V_8 . V_91 & V_176 ) ;
F_120 ( V_7 -> V_8 . V_126 & V_176 ) ;
V_233 = F_209 ( sizeof( * V_233 ) , V_73 ) ;
if ( V_233 == NULL )
return - V_64 ;
V_231 = V_7 -> V_8 . V_17 / V_39 ;
if ( F_210 ( V_233 , V_231 , V_73 ) ) {
F_194 ( V_233 ) ;
return - V_64 ;
}
V_54 = F_31 ( V_7 -> V_8 . V_55 ) -> V_56 ;
V_237 = F_211 ( V_54 ) ;
V_237 |= V_238 | V_239 | V_240 ;
V_237 &= ~ ( V_241 | V_242 ) ;
V_235 = V_233 -> V_243 ;
V_233 -> V_244 = 0 ;
for ( V_58 = 0 ; V_58 < V_231 ; V_58 ++ ) {
V_59 = F_212 ( V_54 , V_58 , V_237 ) ;
if ( F_33 ( V_59 ) ) {
F_178 ( V_16 , V_231 ) ;
V_59 = F_212 ( V_54 , V_58 , V_237 ) ;
}
if ( F_33 ( V_59 ) ) {
F_179 ( V_16 ) ;
V_59 = F_32 ( V_54 , V_58 ) ;
if ( F_33 ( V_59 ) )
goto V_245;
}
#ifdef F_213
if ( F_214 () ) {
V_233 -> V_244 ++ ;
F_215 ( V_235 , V_59 , V_39 , 0 ) ;
V_235 = F_216 ( V_235 ) ;
continue;
}
#endif
if ( ! V_58 || F_217 ( V_59 ) != V_236 + 1 ) {
if ( V_58 )
V_235 = F_216 ( V_235 ) ;
V_233 -> V_244 ++ ;
F_215 ( V_235 , V_59 , V_39 , 0 ) ;
} else {
V_235 -> V_85 += V_39 ;
}
V_236 = F_217 ( V_59 ) ;
F_16 ( ( V_237 & V_246 ) && ( V_236 >= 0x00100000UL ) ) ;
}
#ifdef F_213
if ( ! F_214 () )
#endif
F_218 ( V_235 ) ;
V_7 -> V_215 = V_233 ;
if ( F_85 ( V_7 ) )
F_219 ( V_7 ) ;
return 0 ;
V_245:
F_218 ( V_235 ) ;
F_86 (st->sgl, &sg_iter, st->nents, 0 )
F_39 ( F_87 ( & V_105 ) ) ;
F_193 ( V_233 ) ;
F_194 ( V_233 ) ;
if ( F_47 ( V_59 ) == - V_133 )
return - V_64 ;
else
return F_47 ( V_59 ) ;
}
int
F_73 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
const struct V_216 * V_217 = V_7 -> V_217 ;
int V_23 ;
if ( V_7 -> V_215 )
return 0 ;
if ( V_7 -> V_51 != V_52 ) {
F_183 ( L_5 ) ;
return - V_63 ;
}
F_120 ( V_7 -> V_218 ) ;
V_23 = V_217 -> V_247 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_220 ( & V_7 -> V_219 , & V_16 -> V_18 . V_226 ) ;
return 0 ;
}
static void
F_221 ( struct V_6 * V_7 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_138 = F_222 ( V_137 ) ;
F_120 ( V_137 == NULL ) ;
if ( V_7 -> V_137 != V_137 && V_7 -> V_172 ) {
V_7 -> V_172 = V_138 ;
}
V_7 -> V_137 = V_137 ;
if ( ! V_7 -> V_30 ) {
F_203 ( & V_7 -> V_8 ) ;
V_7 -> V_30 = 1 ;
}
F_202 ( & V_7 -> V_248 , & V_137 -> V_249 ) ;
V_7 -> V_174 = V_138 ;
if ( V_7 -> V_250 ) {
V_7 -> V_251 = V_138 ;
if ( V_7 -> V_13 != V_14 ) {
struct V_252 * V_253 ;
V_253 = & V_16 -> V_254 [ V_7 -> V_13 ] ;
F_202 ( & V_253 -> V_255 ,
& V_16 -> V_18 . V_256 ) ;
}
}
}
void F_223 ( struct V_228 * V_188 ,
struct V_136 * V_137 )
{
F_202 ( & V_188 -> V_257 , & V_188 -> V_258 -> V_249 ) ;
return F_221 ( V_188 -> V_7 , V_137 ) ;
}
static void
F_224 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_259 * V_258 ;
struct V_228 * V_188 ;
F_120 ( V_7 -> V_8 . V_126 & ~ V_176 ) ;
F_120 ( ! V_7 -> V_30 ) ;
F_27 (vm, &dev_priv->vm_list, global_link) {
V_188 = F_225 ( V_7 , V_258 ) ;
if ( V_188 && ! F_199 ( & V_188 -> V_257 ) )
F_202 ( & V_188 -> V_257 , & V_258 -> V_260 ) ;
}
F_226 ( V_7 , true ) ;
F_227 ( & V_7 -> V_248 ) ;
V_7 -> V_137 = NULL ;
V_7 -> V_174 = 0 ;
V_7 -> V_172 = 0 ;
V_7 -> V_8 . V_126 = 0 ;
V_7 -> V_251 = 0 ;
V_7 -> V_250 = false ;
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
if ( F_135 ( V_137 -> V_153 ( V_137 , true ) ,
V_7 -> V_174 ) )
F_224 ( V_7 ) ;
}
static int
F_228 ( struct V_1 * V_2 , T_6 V_138 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
int V_23 , V_58 , V_261 ;
F_229 (ring, dev_priv, i) {
V_23 = F_230 ( V_137 ) ;
if ( V_23 )
return V_23 ;
}
F_231 ( V_2 ) ;
F_229 (ring, dev_priv, i) {
F_232 ( V_137 , V_138 ) ;
for ( V_261 = 0 ; V_261 < F_233 ( V_137 -> V_262 . V_263 ) ; V_261 ++ )
V_137 -> V_262 . V_263 [ V_261 ] = 0 ;
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
V_16 -> V_264 = V_138 ;
V_16 -> V_265 = V_138 - 1 ;
if ( V_16 -> V_265 == 0 )
V_16 -> V_265 -- ;
return 0 ;
}
int
F_235 ( struct V_1 * V_2 , T_6 * V_138 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( V_16 -> V_264 == 0 ) {
int V_23 = F_228 ( V_2 , 0 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_264 = 1 ;
}
* V_138 = V_16 -> V_265 = V_16 -> V_264 ++ ;
return 0 ;
}
int F_236 ( struct V_136 * V_137 ,
struct V_32 * V_33 ,
struct V_6 * V_7 ,
T_6 * V_266 )
{
struct V_15 * V_16 = V_137 -> V_2 -> V_27 ;
struct V_267 * V_268 ;
T_6 V_269 , V_270 ;
int V_23 ;
V_270 = F_237 ( V_137 -> V_271 ) ;
V_23 = F_238 ( V_137 ) ;
if ( V_23 )
return V_23 ;
V_268 = V_137 -> V_272 ;
if ( F_16 ( V_268 == NULL ) )
return - V_64 ;
V_269 = F_237 ( V_137 -> V_271 ) ;
V_23 = V_137 -> V_273 ( V_137 ) ;
if ( V_23 )
return V_23 ;
V_268 -> V_138 = F_222 ( V_137 ) ;
V_268 -> V_137 = V_137 ;
V_268 -> V_274 = V_270 ;
V_268 -> V_275 = V_269 ;
V_268 -> V_276 = V_7 ;
V_268 -> V_277 = V_137 -> V_278 ;
if ( V_268 -> V_277 )
F_239 ( V_268 -> V_277 ) ;
V_268 -> V_279 = V_154 ;
F_220 ( & V_268 -> V_280 , & V_137 -> V_281 ) ;
V_268 -> V_67 = NULL ;
if ( V_33 ) {
struct V_143 * V_67 = V_33 -> V_177 ;
F_7 ( & V_67 -> V_18 . V_282 ) ;
V_268 -> V_67 = V_67 ;
F_220 ( & V_268 -> V_283 ,
& V_67 -> V_18 . V_281 ) ;
F_8 ( & V_67 -> V_18 . V_282 ) ;
}
F_240 ( V_137 , V_268 -> V_138 ) ;
V_137 -> V_139 = 0 ;
V_137 -> V_272 = NULL ;
if ( ! V_16 -> V_284 . V_285 ) {
F_241 ( V_137 -> V_2 ) ;
F_242 ( & V_16 -> V_18 . V_158 ) ;
F_243 ( V_16 -> V_157 ,
& V_16 -> V_18 . V_286 ,
F_244 ( V_25 ) ) ;
F_245 ( V_16 -> V_2 ) ;
}
if ( V_266 )
* V_266 = V_268 -> V_138 ;
return 0 ;
}
static inline void
F_246 ( struct V_267 * V_268 )
{
struct V_143 * V_67 = V_268 -> V_67 ;
if ( ! V_67 )
return;
F_7 ( & V_67 -> V_18 . V_282 ) ;
F_196 ( & V_268 -> V_283 ) ;
V_268 -> V_67 = NULL ;
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
F_183 ( L_6 ) ;
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
static void F_253 ( struct V_267 * V_268 )
{
F_196 ( & V_268 -> V_280 ) ;
F_246 ( V_268 ) ;
if ( V_268 -> V_277 )
F_254 ( V_268 -> V_277 ) ;
F_194 ( V_268 ) ;
}
struct V_267 *
F_255 ( struct V_136 * V_137 )
{
struct V_267 * V_268 ;
T_6 V_298 ;
V_298 = V_137 -> V_153 ( V_137 , false ) ;
F_27 (request, &ring->request_list, list) {
if ( F_135 ( V_298 , V_268 -> V_138 ) )
continue;
return V_268 ;
}
return NULL ;
}
static void F_256 ( struct V_15 * V_16 ,
struct V_136 * V_137 )
{
struct V_267 * V_268 ;
bool V_299 ;
V_268 = F_255 ( V_137 ) ;
if ( V_268 == NULL )
return;
V_299 = V_137 -> V_300 . V_301 >= V_302 ;
F_252 ( V_16 , V_268 -> V_277 , V_299 ) ;
F_257 (request, &ring->request_list, list)
F_252 ( V_16 , V_268 -> V_277 , false ) ;
}
static void F_258 ( struct V_15 * V_16 ,
struct V_136 * V_137 )
{
while ( ! F_199 ( & V_137 -> V_249 ) ) {
struct V_6 * V_7 ;
V_7 = F_200 ( & V_137 -> V_249 ,
struct V_6 ,
V_248 ) ;
F_224 ( V_7 ) ;
}
while ( ! F_199 ( & V_137 -> V_281 ) ) {
struct V_267 * V_268 ;
V_268 = F_200 ( & V_137 -> V_281 ,
struct V_267 ,
V_280 ) ;
F_253 ( V_268 ) ;
}
F_194 ( V_137 -> V_272 ) ;
V_137 -> V_272 = NULL ;
V_137 -> V_139 = 0 ;
}
void F_259 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_16 -> V_303 ; V_58 ++ ) {
struct V_252 * V_253 = & V_16 -> V_254 [ V_58 ] ;
if ( V_253 -> V_7 ) {
F_260 ( V_253 -> V_7 , V_253 ,
V_253 -> V_7 -> V_11 ) ;
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
if ( F_199 ( & V_137 -> V_281 ) )
return;
F_16 ( F_17 ( V_137 -> V_2 ) ) ;
V_138 = V_137 -> V_153 ( V_137 , true ) ;
while ( ! F_199 ( & V_137 -> V_249 ) ) {
struct V_6 * V_7 ;
V_7 = F_200 ( & V_137 -> V_249 ,
struct V_6 ,
V_248 ) ;
if ( ! F_135 ( V_138 , V_7 -> V_174 ) )
break;
F_224 ( V_7 ) ;
}
while ( ! F_199 ( & V_137 -> V_281 ) ) {
struct V_267 * V_268 ;
V_268 = F_200 ( & V_137 -> V_281 ,
struct V_267 ,
V_280 ) ;
if ( ! F_135 ( V_138 , V_268 -> V_138 ) )
break;
F_265 ( V_137 , V_268 -> V_138 ) ;
V_137 -> V_271 -> V_304 = V_268 -> V_275 ;
F_253 ( V_268 ) ;
}
if ( F_76 ( V_137 -> V_305 &&
F_135 ( V_138 , V_137 -> V_305 ) ) ) {
V_137 -> V_170 ( V_137 ) ;
V_137 -> V_305 = 0 ;
}
F_16 ( F_17 ( V_137 -> V_2 ) ) ;
}
bool
F_231 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
bool V_306 = true ;
int V_58 ;
F_229 (ring, dev_priv, i) {
F_264 ( V_137 ) ;
V_306 &= F_199 ( & V_137 -> V_281 ) ;
}
if ( V_306 )
F_138 ( V_16 -> V_157 ,
& V_16 -> V_18 . V_158 ,
F_139 ( 100 ) ) ;
return V_306 ;
}
static void
F_266 ( struct V_307 * V_308 )
{
struct V_15 * V_16 =
F_267 ( V_308 , F_201 ( * V_16 ) , V_18 . V_286 . V_308 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_306 ;
V_306 = false ;
if ( F_268 ( & V_2 -> V_29 ) ) {
V_306 = F_231 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
}
if ( ! V_306 )
F_243 ( V_16 -> V_157 , & V_16 -> V_18 . V_286 ,
F_244 ( V_25 ) ) ;
}
static void
F_269 ( struct V_307 * V_308 )
{
struct V_15 * V_16 =
F_267 ( V_308 , F_201 ( * V_16 ) , V_18 . V_158 . V_308 ) ;
F_270 ( V_16 -> V_2 ) ;
}
static int
F_271 ( struct V_6 * V_7 )
{
int V_23 ;
if ( V_7 -> V_30 ) {
V_23 = F_119 ( V_7 -> V_137 , V_7 -> V_174 ) ;
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
struct V_309 * args = V_31 ;
struct V_6 * V_7 ;
struct V_136 * V_137 = NULL ;
unsigned V_145 ;
T_6 V_138 = 0 ;
int V_23 = 0 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_95 ( F_96 ( V_2 , V_33 , args -> V_310 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_25 ( & V_2 -> V_29 ) ;
return - V_111 ;
}
V_23 = F_271 ( V_7 ) ;
if ( V_23 )
goto V_109;
if ( V_7 -> V_30 ) {
V_138 = V_7 -> V_174 ;
V_137 = V_7 -> V_137 ;
}
if ( V_138 == 0 )
goto V_109;
if ( args -> V_311 <= 0 ) {
V_23 = - V_167 ;
goto V_109;
}
F_98 ( & V_7 -> V_8 ) ;
V_145 = F_143 ( & V_16 -> V_28 . V_145 ) ;
F_25 ( & V_2 -> V_29 ) ;
return F_129 ( V_137 , V_138 , V_145 , true , & args -> V_311 ,
V_33 -> V_177 ) ;
V_109:
F_98 ( & V_7 -> V_8 ) ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_273 ( struct V_6 * V_7 ,
struct V_136 * V_312 )
{
struct V_136 * V_313 = V_7 -> V_137 ;
T_6 V_138 ;
int V_23 , V_314 ;
if ( V_313 == NULL || V_312 == V_313 )
return 0 ;
if ( V_312 == NULL || ! F_274 ( V_7 -> V_8 . V_2 ) )
return F_71 ( V_7 , false ) ;
V_314 = F_275 ( V_313 , V_312 ) ;
V_138 = V_7 -> V_174 ;
if ( V_138 <= V_313 -> V_262 . V_263 [ V_314 ] )
return 0 ;
V_23 = F_119 ( V_7 -> V_137 , V_138 ) ;
if ( V_23 )
return V_23 ;
F_276 ( V_313 , V_312 , V_138 ) ;
V_23 = V_312 -> V_262 . V_315 ( V_312 , V_313 , V_138 ) ;
if ( ! V_23 )
V_313 -> V_262 . V_263 [ V_314 ] = V_7 -> V_174 ;
return V_23 ;
}
static void F_277 ( struct V_6 * V_7 )
{
T_6 V_316 , V_317 ;
F_5 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_91 & V_179 ) == 0 )
return;
F_278 () ;
V_317 = V_7 -> V_8 . V_91 ;
V_316 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_91 &= ~ V_179 ;
V_7 -> V_8 . V_126 &= ~ V_179 ;
F_279 ( V_7 ,
V_317 ,
V_316 ) ;
}
int F_206 ( struct V_228 * V_188 )
{
struct V_6 * V_7 = V_188 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_199 ( & V_188 -> V_318 ) )
return 0 ;
if ( ! F_280 ( & V_188 -> V_319 ) ) {
F_281 ( V_188 ) ;
return 0 ;
}
if ( V_188 -> V_320 )
return - V_62 ;
F_120 ( V_7 -> V_215 == NULL ) ;
V_23 = F_282 ( V_7 ) ;
if ( V_23 )
return V_23 ;
if ( F_283 ( V_188 -> V_258 ) ) {
F_277 ( V_7 ) ;
V_23 = F_105 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
F_284 ( V_188 ) ;
V_188 -> V_321 ( V_188 ) ;
F_227 ( & V_188 -> V_257 ) ;
if ( F_283 ( V_188 -> V_258 ) )
V_7 -> V_322 = true ;
F_285 ( & V_188 -> V_319 ) ;
F_281 ( V_188 ) ;
if ( F_199 ( & V_7 -> V_323 ) ) {
F_286 ( V_7 ) ;
F_202 ( & V_7 -> V_219 , & V_16 -> V_18 . V_226 ) ;
}
F_92 ( V_7 ) ;
return 0 ;
}
int F_287 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
int V_23 , V_58 ;
F_229 (ring, dev_priv, i) {
V_23 = F_288 ( V_137 , V_137 -> V_324 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_230 ( V_137 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static void F_289 ( struct V_1 * V_2 , int V_253 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_13 ;
int V_325 ;
if ( F_22 ( V_2 ) -> V_41 >= 6 ) {
V_13 = V_326 ;
V_325 = V_327 ;
} else {
V_13 = V_328 ;
V_325 = V_329 ;
}
V_13 += V_253 * 8 ;
F_290 ( V_13 , 0 ) ;
F_291 ( V_13 ) ;
if ( V_7 ) {
T_6 V_17 = F_29 ( V_7 ) ;
T_4 V_330 ;
V_330 = ( T_4 ) ( ( F_106 ( V_7 ) + V_17 - 4096 ) &
0xfffff000 ) << 32 ;
V_330 |= F_106 ( V_7 ) & 0xfffff000 ;
V_330 |= ( T_4 ) ( ( V_7 -> V_331 / 128 ) - 1 ) << V_325 ;
if ( V_7 -> V_11 == V_332 )
V_330 |= 1 << V_333 ;
V_330 |= V_334 ;
F_290 ( V_13 + 4 , V_330 >> 32 ) ;
F_291 ( V_13 + 4 ) ;
F_290 ( V_13 + 0 , V_330 ) ;
F_291 ( V_13 ) ;
} else {
F_290 ( V_13 + 4 , 0 ) ;
F_291 ( V_13 + 4 ) ;
}
}
static void F_292 ( struct V_1 * V_2 , int V_253 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_330 ;
if ( V_7 ) {
T_6 V_17 = F_29 ( V_7 ) ;
int V_335 ;
int V_336 ;
F_133 ( ( F_106 ( V_7 ) & ~ V_337 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_106 ( V_7 ) & ( V_17 - 1 ) ) ,
L_8 ,
F_106 ( V_7 ) , V_7 -> V_322 , V_17 ) ;
if ( V_7 -> V_11 == V_332 && F_293 ( V_2 ) )
V_336 = 128 ;
else
V_336 = 512 ;
V_335 = V_7 -> V_331 / V_336 ;
V_335 = F_294 ( V_335 ) - 1 ;
V_330 = F_106 ( V_7 ) ;
if ( V_7 -> V_11 == V_332 )
V_330 |= 1 << V_338 ;
V_330 |= F_295 ( V_17 ) ;
V_330 |= V_335 << V_339 ;
V_330 |= V_340 ;
} else
V_330 = 0 ;
if ( V_253 < 8 )
V_253 = V_341 + V_253 * 4 ;
else
V_253 = V_342 + ( V_253 - 8 ) * 4 ;
F_290 ( V_253 , V_330 ) ;
F_291 ( V_253 ) ;
}
static void F_296 ( struct V_1 * V_2 , int V_253 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_5 V_330 ;
if ( V_7 ) {
T_6 V_17 = F_29 ( V_7 ) ;
T_5 V_335 ;
F_133 ( ( F_106 ( V_7 ) & ~ V_343 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_106 ( V_7 ) & ( V_17 - 1 ) ) ,
L_9 ,
F_106 ( V_7 ) , V_17 ) ;
V_335 = V_7 -> V_331 / 128 ;
V_335 = F_294 ( V_335 ) - 1 ;
V_330 = F_106 ( V_7 ) ;
if ( V_7 -> V_11 == V_332 )
V_330 |= 1 << V_338 ;
V_330 |= F_297 ( V_17 ) ;
V_330 |= V_335 << V_339 ;
V_330 |= V_340 ;
} else
V_330 = 0 ;
F_290 ( V_341 + V_253 * 4 , V_330 ) ;
F_291 ( V_341 + V_253 * 4 ) ;
}
inline static bool F_298 ( struct V_6 * V_7 )
{
return V_7 && V_7 -> V_8 . V_91 & V_179 ;
}
static void F_261 ( struct V_1 * V_2 , int V_253 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_298 ( V_16 -> V_254 [ V_253 ] . V_7 ) )
F_278 () ;
F_133 ( V_7 && ( ! V_7 -> V_331 || ! V_7 -> V_11 ) ,
L_10 ,
V_7 -> V_331 , V_7 -> V_11 ) ;
switch ( F_22 ( V_2 ) -> V_41 ) {
case 8 :
case 7 :
case 6 :
case 5 :
case 4 : F_289 ( V_2 , V_253 , V_7 ) ; break;
case 3 : F_292 ( V_2 , V_253 , V_7 ) ; break;
case 2 : F_296 ( V_2 , V_253 , V_7 ) ; break;
default: F_299 () ;
}
if ( F_298 ( V_7 ) )
F_278 () ;
}
static inline int F_300 ( struct V_15 * V_16 ,
struct V_252 * V_344 )
{
return V_344 - V_16 -> V_254 ;
}
static void F_260 ( struct V_6 * V_7 ,
struct V_252 * V_344 ,
bool V_345 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_253 = F_300 ( V_16 , V_344 ) ;
F_261 ( V_7 -> V_8 . V_2 , V_253 , V_345 ? V_7 : NULL ) ;
if ( V_345 ) {
V_7 -> V_13 = V_253 ;
V_344 -> V_7 = V_7 ;
F_202 ( & V_344 -> V_255 , & V_16 -> V_18 . V_256 ) ;
} else {
V_7 -> V_13 = V_14 ;
V_344 -> V_7 = NULL ;
F_227 ( & V_344 -> V_255 ) ;
}
V_7 -> V_12 = false ;
}
static int
F_301 ( struct V_6 * V_7 )
{
if ( V_7 -> V_251 ) {
int V_23 = F_153 ( V_7 -> V_137 , V_7 -> V_251 ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_251 = 0 ;
}
V_7 -> V_250 = false ;
return 0 ;
}
int
F_105 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_252 * V_344 ;
int V_23 ;
V_23 = F_301 ( V_7 ) ;
if ( V_23 )
return V_23 ;
if ( V_7 -> V_13 == V_14 )
return 0 ;
V_344 = & V_16 -> V_254 [ V_7 -> V_13 ] ;
if ( F_16 ( V_344 -> V_320 ) )
return - V_62 ;
F_4 ( V_7 ) ;
F_260 ( V_7 , V_344 , false ) ;
return 0 ;
}
static struct V_252 *
F_302 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_252 * V_253 , * V_346 ;
int V_58 ;
V_346 = NULL ;
for ( V_58 = V_16 -> V_347 ; V_58 < V_16 -> V_303 ; V_58 ++ ) {
V_253 = & V_16 -> V_254 [ V_58 ] ;
if ( ! V_253 -> V_7 )
return V_253 ;
if ( ! V_253 -> V_320 )
V_346 = V_253 ;
}
if ( V_346 == NULL )
goto V_348;
F_27 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_253 -> V_320 )
continue;
return V_253 ;
}
V_348:
if ( F_303 ( V_2 ) )
return F_304 ( - V_135 ) ;
return F_304 ( - V_349 ) ;
}
int
F_165 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_345 = V_7 -> V_11 != V_132 ;
struct V_252 * V_253 ;
int V_23 ;
if ( V_7 -> V_12 ) {
V_23 = F_301 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_7 -> V_13 != V_14 ) {
V_253 = & V_16 -> V_254 [ V_7 -> V_13 ] ;
if ( ! V_7 -> V_12 ) {
F_202 ( & V_253 -> V_255 ,
& V_16 -> V_18 . V_256 ) ;
return 0 ;
}
} else if ( V_345 ) {
V_253 = F_302 ( V_2 ) ;
if ( F_33 ( V_253 ) )
return F_47 ( V_253 ) ;
if ( V_253 -> V_7 ) {
struct V_6 * V_350 = V_253 -> V_7 ;
V_23 = F_301 ( V_350 ) ;
if ( V_23 )
return V_23 ;
F_4 ( V_350 ) ;
}
} else
return 0 ;
F_260 ( V_7 , V_253 , V_345 ) ;
return 0 ;
}
static bool F_305 ( struct V_1 * V_2 ,
struct V_351 * V_352 ,
unsigned long V_9 )
{
struct V_351 * V_353 ;
if ( F_2 ( V_2 ) )
return true ;
if ( ! F_280 ( V_352 ) )
return true ;
if ( F_199 ( & V_352 -> V_354 ) )
return true ;
V_353 = F_306 ( V_352 -> V_354 . V_355 , struct V_351 , V_354 ) ;
if ( V_353 -> V_356 && ! V_353 -> V_357 && V_353 -> V_358 != V_9 )
return false ;
V_353 = F_306 ( V_352 -> V_354 . V_359 , struct V_351 , V_354 ) ;
if ( V_353 -> V_356 && ! V_352 -> V_357 && V_353 -> V_358 != V_9 )
return false ;
return true ;
}
static void F_307 ( struct V_1 * V_2 )
{
#if V_360
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_6 * V_7 ;
int V_361 = 0 ;
F_27 (obj, &dev_priv->mm.gtt_list, global_list) {
if ( V_7 -> V_352 == NULL ) {
F_308 ( V_362 L_11 ) ;
V_361 ++ ;
continue;
}
if ( V_7 -> V_9 != V_7 -> V_352 -> V_358 ) {
F_308 ( V_362 L_12 ,
F_106 ( V_7 ) ,
F_106 ( V_7 ) + F_29 ( V_7 ) ,
V_7 -> V_9 ,
V_7 -> V_352 -> V_358 ) ;
V_361 ++ ;
continue;
}
if ( ! F_305 ( V_2 ,
V_7 -> V_352 ,
V_7 -> V_9 ) ) {
F_308 ( V_362 L_13 ,
F_106 ( V_7 ) ,
F_106 ( V_7 ) + F_29 ( V_7 ) ,
V_7 -> V_9 ) ;
V_361 ++ ;
continue;
}
}
F_16 ( V_361 ) ;
#endif
}
static struct V_228 *
F_309 ( struct V_6 * V_7 ,
struct V_259 * V_258 ,
unsigned V_363 ,
T_4 V_194 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_17 , V_364 , V_365 , V_366 ;
unsigned long V_98 =
V_194 & V_367 ? V_194 & V_368 : 0 ;
unsigned long V_99 =
V_194 & V_118 ? V_16 -> V_42 . V_43 : V_258 -> V_47 ;
struct V_228 * V_188 ;
int V_23 ;
V_364 = F_172 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ) ;
V_365 = F_173 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , true ) ;
V_366 =
F_173 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , false ) ;
if ( V_363 == 0 )
V_363 = V_194 & V_118 ? V_365 :
V_366 ;
if ( V_194 & V_118 && V_363 & ( V_365 - 1 ) ) {
F_183 ( L_14 , V_363 ) ;
return F_304 ( - V_40 ) ;
}
V_17 = V_194 & V_118 ? V_364 : V_7 -> V_8 . V_17 ;
if ( V_7 -> V_8 . V_17 > V_99 ) {
F_183 ( L_15 ,
V_7 -> V_8 . V_17 ,
V_194 & V_118 ? L_16 : L_17 ,
V_99 ) ;
return F_304 ( - V_211 ) ;
}
V_23 = F_73 ( V_7 ) ;
if ( V_23 )
return F_304 ( V_23 ) ;
F_74 ( V_7 ) ;
V_188 = F_310 ( V_7 , V_258 ) ;
if ( F_33 ( V_188 ) )
goto V_369;
V_370:
V_23 = F_311 ( & V_258 -> V_18 , & V_188 -> V_319 ,
V_17 , V_363 ,
V_7 -> V_9 ,
V_98 , V_99 ,
V_371 ,
V_372 ) ;
if ( V_23 ) {
V_23 = F_312 ( V_2 , V_258 , V_17 , V_363 ,
V_7 -> V_9 ,
V_98 , V_99 ,
V_194 ) ;
if ( V_23 == 0 )
goto V_370;
goto V_373;
}
if ( F_16 ( ! F_305 ( V_2 , & V_188 -> V_319 ,
V_7 -> V_9 ) ) ) {
V_23 = - V_40 ;
goto V_374;
}
V_23 = F_313 ( V_7 ) ;
if ( V_23 )
goto V_374;
F_202 ( & V_7 -> V_219 , & V_16 -> V_18 . V_227 ) ;
F_220 ( & V_188 -> V_257 , & V_258 -> V_260 ) ;
if ( F_283 ( V_258 ) ) {
bool V_122 , V_375 ;
V_375 = ( V_188 -> V_319 . V_17 == V_364 &&
( V_188 -> V_319 . V_98 & ( V_365 - 1 ) ) == 0 ) ;
V_122 = ( V_188 -> V_319 . V_98 + V_7 -> V_8 . V_17 <=
V_16 -> V_42 . V_43 ) ;
V_7 -> V_322 = V_122 && V_375 ;
}
F_16 ( V_194 & V_118 && ! V_7 -> V_322 ) ;
F_314 ( V_188 , V_194 ) ;
V_188 -> V_376 ( V_188 , V_7 -> V_9 ,
V_194 & ( V_118 | V_377 ) ? V_378 : 0 ) ;
F_307 ( V_2 ) ;
return V_188 ;
V_374:
F_285 ( & V_188 -> V_319 ) ;
V_373:
F_281 ( V_188 ) ;
V_188 = F_304 ( V_23 ) ;
V_369:
F_92 ( V_7 ) ;
return V_188 ;
}
bool
F_112 ( struct V_6 * V_7 ,
bool V_379 )
{
if ( V_7 -> V_215 == NULL )
return false ;
if ( V_7 -> V_380 )
return false ;
if ( ! V_379 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) )
return false ;
F_315 ( V_7 ) ;
F_316 ( V_7 -> V_215 ) ;
return true ;
}
static void
F_317 ( struct V_6 * V_7 )
{
T_5 V_316 ;
if ( V_7 -> V_8 . V_126 != V_179 )
return;
F_318 () ;
V_316 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_126 = 0 ;
F_226 ( V_7 , false ) ;
F_279 ( V_7 ,
V_7 -> V_8 . V_91 ,
V_316 ) ;
}
static void
F_159 ( struct V_6 * V_7 ,
bool V_379 )
{
T_5 V_316 ;
if ( V_7 -> V_8 . V_126 != V_92 )
return;
if ( F_112 ( V_7 , V_379 ) )
F_40 ( V_7 -> V_8 . V_2 ) ;
V_316 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_126 = 0 ;
F_226 ( V_7 , false ) ;
F_279 ( V_7 ,
V_7 -> V_8 . V_91 ,
V_316 ) ;
}
int
F_104 ( struct V_6 * V_7 , bool V_193 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
T_5 V_316 , V_317 ;
int V_23 ;
if ( ! F_19 ( V_7 ) )
return - V_40 ;
if ( V_7 -> V_8 . V_126 == V_179 )
return 0 ;
V_23 = F_71 ( V_7 , ! V_193 ) ;
if ( V_23 )
return V_23 ;
F_72 ( V_7 ) ;
F_159 ( V_7 , false ) ;
if ( ( V_7 -> V_8 . V_91 & V_179 ) == 0 )
F_278 () ;
V_316 = V_7 -> V_8 . V_126 ;
V_317 = V_7 -> V_8 . V_91 ;
F_120 ( ( V_7 -> V_8 . V_126 & ~ V_179 ) != 0 ) ;
V_7 -> V_8 . V_91 |= V_179 ;
if ( V_193 ) {
V_7 -> V_8 . V_91 = V_179 ;
V_7 -> V_8 . V_126 = V_179 ;
V_7 -> V_127 = 1 ;
}
if ( V_193 )
F_319 ( V_7 , NULL ) ;
F_279 ( V_7 ,
V_317 ,
V_316 ) ;
if ( F_18 ( V_7 ) ) {
struct V_228 * V_188 = F_320 ( V_7 ) ;
if ( V_188 )
F_202 ( & V_188 -> V_257 ,
& V_16 -> V_42 . V_8 . V_260 ) ;
}
return 0 ;
}
int F_321 ( struct V_6 * V_7 ,
enum V_3 V_9 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_228 * V_188 , * V_359 ;
int V_23 ;
if ( V_7 -> V_9 == V_9 )
return 0 ;
if ( F_28 ( V_7 ) ) {
F_183 ( L_18 ) ;
return - V_62 ;
}
F_205 (vma, next, &obj->vma_list, vma_link) {
if ( ! F_305 ( V_2 , & V_188 -> V_319 , V_9 ) ) {
V_23 = F_206 ( V_188 ) ;
if ( V_23 )
return V_23 ;
}
}
if ( F_19 ( V_7 ) ) {
V_23 = F_282 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_277 ( V_7 ) ;
if ( F_22 ( V_2 ) -> V_41 < 6 ) {
V_23 = F_105 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
F_27 (vma, &obj->vma_list, vma_link)
if ( F_280 ( & V_188 -> V_319 ) )
V_188 -> V_376 ( V_188 , V_9 ,
V_7 -> V_381 ? V_378 : 0 ) ;
}
F_27 (vma, &obj->vma_list, vma_link)
V_188 -> V_319 . V_358 = V_9 ;
V_7 -> V_9 = V_9 ;
if ( F_3 ( V_7 ) ) {
T_6 V_317 , V_316 ;
F_72 ( V_7 ) ;
F_16 ( V_7 -> V_8 . V_126 & ~ V_92 ) ;
V_317 = V_7 -> V_8 . V_91 ;
V_316 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_91 = V_92 ;
V_7 -> V_8 . V_126 = V_92 ;
F_279 ( V_7 ,
V_317 ,
V_316 ) ;
}
F_307 ( V_2 ) ;
return 0 ;
}
int F_322 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_382 * args = V_31 ;
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
case V_383 :
case V_384 :
args -> V_385 = V_386 ;
break;
case V_387 :
args -> V_385 = V_388 ;
break;
default:
args -> V_385 = V_389 ;
break;
}
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_323 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_382 * args = V_31 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_23 ;
switch ( args -> V_385 ) {
case V_389 :
V_4 = V_5 ;
break;
case V_386 :
V_4 = V_383 ;
break;
case V_388 :
V_4 = F_324 ( V_2 ) ? V_387 : V_5 ;
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
V_23 = F_321 ( V_7 , V_4 ) ;
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static bool F_325 ( struct V_6 * V_7 )
{
struct V_228 * V_188 ;
if ( F_199 ( & V_7 -> V_323 ) )
return false ;
V_188 = F_320 ( V_7 ) ;
if ( ! V_188 )
return false ;
return V_188 -> V_320 - ! ! V_7 -> V_390 ;
}
int
F_326 ( struct V_6 * V_7 ,
T_6 V_363 ,
struct V_136 * V_391 )
{
T_6 V_317 , V_316 ;
bool V_392 ;
int V_23 ;
if ( V_391 != V_7 -> V_137 ) {
V_23 = F_273 ( V_7 , V_391 ) ;
if ( V_23 )
return V_23 ;
}
V_392 = V_7 -> V_10 ;
V_7 -> V_10 = true ;
V_23 = F_321 ( V_7 ,
F_324 ( V_7 -> V_8 . V_2 ) ? V_387 : V_5 ) ;
if ( V_23 )
goto V_393;
V_23 = F_103 ( V_7 , V_363 , V_118 ) ;
if ( V_23 )
goto V_393;
F_159 ( V_7 , true ) ;
V_316 = V_7 -> V_8 . V_126 ;
V_317 = V_7 -> V_8 . V_91 ;
V_7 -> V_8 . V_126 = 0 ;
V_7 -> V_8 . V_91 |= V_179 ;
F_279 ( V_7 ,
V_317 ,
V_316 ) ;
return 0 ;
V_393:
F_16 ( V_392 != F_325 ( V_7 ) ) ;
V_7 -> V_10 = V_392 ;
return V_23 ;
}
void
F_327 ( struct V_6 * V_7 )
{
F_107 ( V_7 ) ;
V_7 -> V_10 = F_325 ( V_7 ) ;
}
int
F_282 ( struct V_6 * V_7 )
{
int V_23 ;
if ( ( V_7 -> V_8 . V_91 & V_176 ) == 0 )
return 0 ;
V_23 = F_71 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_8 . V_91 &= ~ V_176 ;
return 0 ;
}
int
F_157 ( struct V_6 * V_7 , bool V_193 )
{
T_5 V_316 , V_317 ;
int V_23 ;
if ( V_7 -> V_8 . V_126 == V_92 )
return 0 ;
V_23 = F_71 ( V_7 , ! V_193 ) ;
if ( V_23 )
return V_23 ;
F_72 ( V_7 ) ;
F_317 ( V_7 ) ;
V_316 = V_7 -> V_8 . V_126 ;
V_317 = V_7 -> V_8 . V_91 ;
if ( ( V_7 -> V_8 . V_91 & V_92 ) == 0 ) {
F_112 ( V_7 , false ) ;
V_7 -> V_8 . V_91 |= V_92 ;
}
F_120 ( ( V_7 -> V_8 . V_126 & ~ V_92 ) != 0 ) ;
if ( V_193 ) {
V_7 -> V_8 . V_91 = V_92 ;
V_7 -> V_8 . V_126 = V_92 ;
}
if ( V_193 )
F_319 ( V_7 , NULL ) ;
F_279 ( V_7 ,
V_317 ,
V_316 ) ;
return 0 ;
}
static int
F_328 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_143 * V_67 = V_33 -> V_177 ;
unsigned long V_394 = V_154 - F_139 ( 20 ) ;
struct V_267 * V_268 ;
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
if ( F_145 ( V_268 -> V_279 , V_394 ) )
break;
V_137 = V_268 -> V_137 ;
V_138 = V_268 -> V_138 ;
}
V_145 = F_143 ( & V_16 -> V_28 . V_145 ) ;
F_8 ( & V_67 -> V_18 . V_282 ) ;
if ( V_138 == 0 )
return 0 ;
V_23 = F_129 ( V_137 , V_138 , V_145 , true , NULL , NULL ) ;
if ( V_23 == 0 )
F_243 ( V_16 -> V_157 , & V_16 -> V_18 . V_286 , 0 ) ;
return V_23 ;
}
static bool
F_329 ( struct V_228 * V_188 , T_5 V_363 , T_4 V_194 )
{
struct V_6 * V_7 = V_188 -> V_7 ;
if ( V_363 &&
V_188 -> V_319 . V_98 & ( V_363 - 1 ) )
return true ;
if ( V_194 & V_118 && ! V_7 -> V_322 )
return true ;
if ( V_194 & V_367 &&
V_188 -> V_319 . V_98 < ( V_194 & V_368 ) )
return true ;
return false ;
}
int
F_330 ( struct V_6 * V_7 ,
struct V_259 * V_258 ,
T_5 V_363 ,
T_4 V_194 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_228 * V_188 ;
int V_23 ;
if ( F_16 ( V_258 == & V_16 -> V_18 . V_395 -> V_8 ) )
return - V_36 ;
if ( F_16 ( V_194 & ( V_377 | V_118 ) && ! F_283 ( V_258 ) ) )
return - V_40 ;
V_188 = F_225 ( V_7 , V_258 ) ;
if ( V_188 ) {
if ( F_16 ( V_188 -> V_320 == V_396 ) )
return - V_62 ;
if ( F_329 ( V_188 , V_363 , V_194 ) ) {
F_133 ( V_188 -> V_320 ,
L_19
L_20
L_21 ,
F_331 ( V_7 , V_258 ) , V_363 ,
! ! ( V_194 & V_118 ) ,
V_7 -> V_322 ) ;
V_23 = F_206 ( V_188 ) ;
if ( V_23 )
return V_23 ;
V_188 = NULL ;
}
}
if ( V_188 == NULL || ! F_280 ( & V_188 -> V_319 ) ) {
V_188 = F_309 ( V_7 , V_258 , V_363 , V_194 ) ;
if ( F_33 ( V_188 ) )
return F_47 ( V_188 ) ;
}
if ( V_194 & V_377 && ! V_7 -> V_381 )
V_188 -> V_376 ( V_188 , V_7 -> V_9 , V_378 ) ;
V_188 -> V_320 ++ ;
if ( V_194 & V_118 )
V_7 -> V_397 |= true ;
return 0 ;
}
void
F_107 ( struct V_6 * V_7 )
{
struct V_228 * V_188 = F_320 ( V_7 ) ;
F_120 ( ! V_188 ) ;
F_120 ( V_188 -> V_320 == 0 ) ;
F_120 ( ! F_332 ( V_7 ) ) ;
if ( -- V_188 -> V_320 == 0 )
V_7 -> V_397 = false ;
}
bool
F_333 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 != V_14 ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_228 * V_398 = F_320 ( V_7 ) ;
F_16 ( ! V_398 ||
V_16 -> V_254 [ V_7 -> V_13 ] . V_320 >
V_398 -> V_320 ) ;
V_16 -> V_254 [ V_7 -> V_13 ] . V_320 ++ ;
return true ;
} else
return false ;
}
void
F_334 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 != V_14 ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
F_16 ( V_16 -> V_254 [ V_7 -> V_13 ] . V_320 <= 0 ) ;
V_16 -> V_254 [ V_7 -> V_13 ] . V_320 -- ;
}
}
int
F_335 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_399 * args = V_31 ;
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
F_183 ( L_22 ) ;
V_23 = - V_63 ;
goto V_109;
}
if ( V_7 -> V_400 != NULL && V_7 -> V_400 != V_33 ) {
F_183 ( L_23 ,
args -> V_75 ) ;
V_23 = - V_40 ;
goto V_109;
}
if ( V_7 -> V_390 == V_401 ) {
V_23 = - V_62 ;
goto V_109;
}
if ( V_7 -> V_390 == 0 ) {
V_23 = F_103 ( V_7 , args -> V_363 , V_118 ) ;
if ( V_23 )
goto V_109;
}
V_7 -> V_390 ++ ;
V_7 -> V_400 = V_33 ;
args -> V_68 = F_106 ( V_7 ) ;
V_109:
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_336 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_399 * args = V_31 ;
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
if ( V_7 -> V_400 != V_33 ) {
F_183 ( L_24 ,
args -> V_75 ) ;
V_23 = - V_40 ;
goto V_109;
}
V_7 -> V_390 -- ;
if ( V_7 -> V_390 == 0 ) {
V_7 -> V_400 = NULL ;
F_107 ( V_7 ) ;
}
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
struct V_402 * args = V_31 ;
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
args -> V_403 = V_7 -> V_30 ;
if ( V_7 -> V_137 ) {
F_338 ( V_404 > 16 ) ;
args -> V_403 |= F_131 ( V_7 -> V_137 ) << 16 ;
}
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_339 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_67 )
{
return F_328 ( V_2 , V_67 ) ;
}
int
F_340 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_67 )
{
struct V_405 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
switch ( args -> V_51 ) {
case V_213 :
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
if ( V_7 -> V_51 != V_214 )
V_7 -> V_51 = args -> V_51 ;
if ( F_186 ( V_7 ) && V_7 -> V_215 == NULL )
F_187 ( V_7 ) ;
args -> V_406 = V_7 -> V_51 != V_214 ;
V_109:
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void F_341 ( struct V_6 * V_7 ,
const struct V_216 * V_217 )
{
F_198 ( & V_7 -> V_219 ) ;
F_198 ( & V_7 -> V_248 ) ;
F_198 ( & V_7 -> V_407 ) ;
F_198 ( & V_7 -> V_323 ) ;
V_7 -> V_217 = V_217 ;
V_7 -> V_13 = V_14 ;
V_7 -> V_51 = V_52 ;
V_7 -> V_322 = true ;
F_6 ( V_7 -> V_8 . V_2 -> V_27 , V_7 -> V_8 . V_17 ) ;
}
struct V_6 * F_58 ( struct V_1 * V_2 ,
T_1 V_17 )
{
struct V_6 * V_7 ;
struct V_53 * V_54 ;
T_13 V_408 ;
V_7 = F_52 ( V_2 ) ;
if ( V_7 == NULL )
return NULL ;
if ( F_342 ( V_2 , & V_7 -> V_8 , V_17 ) != 0 ) {
F_54 ( V_7 ) ;
return NULL ;
}
V_408 = V_409 | V_410 ;
if ( F_343 ( V_2 ) || F_344 ( V_2 ) ) {
V_408 &= ~ V_411 ;
V_408 |= V_246 ;
}
V_54 = F_31 ( V_7 -> V_8 . V_55 ) -> V_56 ;
F_345 ( V_54 , V_408 ) ;
F_341 ( V_7 , & V_412 ) ;
V_7 -> V_8 . V_126 = V_92 ;
V_7 -> V_8 . V_91 = V_92 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_9 = V_383 ;
} else
V_7 -> V_9 = V_5 ;
F_346 ( V_7 ) ;
return V_7 ;
}
static bool F_347 ( struct V_6 * V_7 )
{
if ( V_7 -> V_51 != V_52 )
return false ;
if ( V_7 -> V_8 . V_55 == NULL )
return true ;
return F_348 ( & V_7 -> V_8 . V_55 -> V_413 ) == 1 ;
}
void F_349 ( struct V_182 * V_414 )
{
struct V_6 * V_7 = F_95 ( V_414 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_228 * V_188 , * V_359 ;
F_163 ( V_16 ) ;
F_350 ( V_7 ) ;
F_205 (vma, next, &obj->vma_list, vma_link) {
int V_23 ;
V_188 -> V_320 = 0 ;
V_23 = F_206 ( V_188 ) ;
if ( F_16 ( V_23 == - V_166 ) ) {
bool V_415 ;
V_415 = V_16 -> V_18 . V_134 ;
V_16 -> V_18 . V_134 = false ;
F_16 ( F_206 ( V_188 ) ) ;
V_16 -> V_18 . V_134 = V_415 ;
}
}
F_30 ( V_7 ) ;
if ( V_7 -> V_380 )
F_92 ( V_7 ) ;
F_16 ( V_7 -> V_416 ) ;
if ( F_16 ( V_7 -> V_218 ) )
V_7 -> V_218 = 0 ;
if ( F_347 ( V_7 ) )
V_7 -> V_51 = V_213 ;
F_195 ( V_7 ) ;
F_180 ( V_7 ) ;
F_120 ( V_7 -> V_215 ) ;
if ( V_7 -> V_8 . V_417 )
F_351 ( & V_7 -> V_8 , NULL ) ;
if ( V_7 -> V_217 -> V_418 )
V_7 -> V_217 -> V_418 ( V_7 ) ;
F_352 ( & V_7 -> V_8 ) ;
F_9 ( V_16 , V_7 -> V_8 . V_17 ) ;
F_194 ( V_7 -> V_419 ) ;
F_54 ( V_7 ) ;
F_169 ( V_16 ) ;
}
struct V_228 * F_225 ( struct V_6 * V_7 ,
struct V_259 * V_258 )
{
struct V_228 * V_188 ;
F_27 (vma, &obj->vma_list, vma_link)
if ( V_188 -> V_258 == V_258 )
return V_188 ;
return NULL ;
}
void F_281 ( struct V_228 * V_188 )
{
F_16 ( V_188 -> V_319 . V_356 ) ;
if ( ! F_199 ( & V_188 -> V_420 ) )
return;
F_196 ( & V_188 -> V_318 ) ;
F_194 ( V_188 ) ;
}
static void
F_353 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
int V_58 ;
F_229 (ring, dev_priv, i)
F_354 ( V_137 ) ;
}
int
F_355 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 = 0 ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_16 -> V_284 . V_285 )
goto V_361;
V_23 = F_287 ( V_2 ) ;
if ( V_23 )
goto V_361;
F_231 ( V_2 ) ;
if ( ! F_21 ( V_2 , V_35 ) )
F_207 ( V_2 ) ;
F_356 ( V_2 ) ;
F_353 ( V_2 ) ;
V_16 -> V_284 . V_285 = ! F_21 ( V_2 ,
V_35 ) ;
F_25 ( & V_2 -> V_29 ) ;
F_357 ( & V_16 -> V_28 . V_421 ) ;
F_242 ( & V_16 -> V_18 . V_286 ) ;
F_358 ( & V_16 -> V_18 . V_158 ) ;
return 0 ;
V_361:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_359 ( struct V_136 * V_137 , int V_422 )
{
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_423 = V_424 + ( V_422 * 0x200 ) ;
T_6 * V_425 = V_16 -> V_426 . V_425 [ V_422 ] ;
int V_58 , V_23 ;
if ( ! F_360 ( V_2 ) || ! V_425 )
return 0 ;
V_23 = F_361 ( V_137 , V_427 / 4 * 3 ) ;
if ( V_23 )
return V_23 ;
for ( V_58 = 0 ; V_58 < V_427 ; V_58 += 4 ) {
F_362 ( V_137 , F_363 ( 1 ) ) ;
F_362 ( V_137 , V_423 + V_58 ) ;
F_362 ( V_137 , V_425 [ V_58 / 4 ] ) ;
}
F_364 ( V_137 ) ;
return V_23 ;
}
void F_365 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_22 ( V_2 ) -> V_41 < 5 ||
V_16 -> V_18 . V_428 == V_429 )
return;
F_290 ( V_430 , F_366 ( V_430 ) |
V_431 ) ;
if ( F_367 ( V_2 ) )
return;
F_290 ( V_432 , F_366 ( V_432 ) | V_433 ) ;
if ( F_368 ( V_2 ) )
F_290 ( V_434 , F_369 ( V_435 ) ) ;
else if ( F_370 ( V_2 ) )
F_290 ( V_434 , F_369 ( V_436 ) ) ;
else if ( F_371 ( V_2 ) )
F_290 ( V_437 , F_369 ( V_438 ) ) ;
else
F_299 () ;
}
static bool
F_372 ( struct V_1 * V_2 )
{
if ( ! F_373 ( V_2 ) )
return false ;
if ( F_368 ( V_2 ) && V_2 -> V_439 -> V_440 < 8 ) {
F_374 ( L_25
L_26 ) ;
return false ;
}
return true ;
}
static int F_375 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
V_23 = F_376 ( V_2 ) ;
if ( V_23 )
return V_23 ;
if ( F_377 ( V_2 ) ) {
V_23 = F_378 ( V_2 ) ;
if ( V_23 )
goto V_441;
}
if ( F_372 ( V_2 ) ) {
V_23 = F_379 ( V_2 ) ;
if ( V_23 )
goto V_442;
}
if ( F_380 ( V_2 ) ) {
V_23 = F_381 ( V_2 ) ;
if ( V_23 )
goto V_443;
}
if ( F_382 ( V_2 ) ) {
V_23 = F_383 ( V_2 ) ;
if ( V_23 )
goto V_444;
}
V_23 = F_234 ( V_2 , ( ( T_6 ) ~ 0 - 0x1000 ) ) ;
if ( V_23 )
goto V_445;
return 0 ;
V_445:
F_384 ( & V_16 -> V_137 [ V_446 ] ) ;
V_444:
F_384 ( & V_16 -> V_137 [ V_447 ] ) ;
V_443:
F_384 ( & V_16 -> V_137 [ V_448 ] ) ;
V_442:
F_384 ( & V_16 -> V_137 [ V_449 ] ) ;
V_441:
F_384 ( & V_16 -> V_137 [ V_156 ] ) ;
return V_23 ;
}
int
F_385 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 , V_58 ;
if ( F_22 ( V_2 ) -> V_41 < 6 && ! F_386 () )
return - V_26 ;
if ( V_16 -> V_450 )
F_290 ( V_451 , F_366 ( V_451 ) | F_387 ( 0xf ) ) ;
if ( F_388 ( V_2 ) )
F_290 ( V_452 , F_389 ( V_2 ) ?
V_453 : V_454 ) ;
if ( F_390 ( V_2 ) ) {
if ( F_391 ( V_2 ) ) {
T_6 V_455 = F_366 ( V_456 ) ;
V_455 &= ~ ( V_457 | V_458 ) ;
F_290 ( V_456 , V_455 ) ;
} else if ( F_22 ( V_2 ) -> V_41 >= 7 ) {
T_6 V_455 = F_366 ( V_459 ) ;
V_455 &= ~ V_460 ;
F_290 ( V_459 , V_455 ) ;
}
}
F_365 ( V_2 ) ;
V_23 = F_375 ( V_2 ) ;
if ( V_23 )
return V_23 ;
for ( V_58 = 0 ; V_58 < F_392 ( V_2 ) ; V_58 ++ )
F_359 ( & V_16 -> V_137 [ V_156 ] , V_58 ) ;
V_23 = F_393 ( V_16 ) ;
if ( V_23 && V_23 != - V_26 ) {
F_13 ( L_27 , V_23 ) ;
F_394 ( V_2 ) ;
}
return V_23 ;
}
int F_395 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
F_23 ( & V_2 -> V_29 ) ;
if ( F_396 ( V_2 ) ) {
F_290 ( V_461 , V_462 ) ;
if ( F_397 ( ( F_366 ( V_463 ) &
V_464 ) , 10 ) )
F_398 ( L_28 ) ;
}
F_399 ( V_2 ) ;
F_400 ( V_2 ) ;
V_23 = F_401 ( V_2 ) ;
if ( V_23 ) {
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
V_23 = F_385 ( V_2 ) ;
if ( V_23 == - V_26 ) {
F_13 ( L_29 ) ;
F_402 ( V_465 , & V_16 -> V_28 . V_145 ) ;
V_23 = 0 ;
}
F_25 ( & V_2 -> V_29 ) ;
if ( ! F_21 ( V_2 , V_35 ) )
V_16 -> V_466 . V_467 = 1 ;
return V_23 ;
}
void
F_394 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
int V_58 ;
F_229 (ring, dev_priv, i)
F_384 ( V_137 ) ;
}
int
F_403 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_67 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( F_21 ( V_2 , V_35 ) )
return 0 ;
if ( F_117 ( & V_16 -> V_28 ) ) {
F_13 ( L_30 ) ;
F_404 ( & V_16 -> V_28 . V_145 , 0 ) ;
}
F_23 ( & V_2 -> V_29 ) ;
V_16 -> V_284 . V_285 = 0 ;
V_23 = F_385 ( V_2 ) ;
if ( V_23 != 0 ) {
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
F_120 ( ! F_199 ( & V_16 -> V_42 . V_8 . V_249 ) ) ;
V_23 = F_405 ( V_2 , V_2 -> V_439 -> V_468 ) ;
if ( V_23 )
goto V_469;
F_25 ( & V_2 -> V_29 ) ;
return 0 ;
V_469:
F_394 ( V_2 ) ;
V_16 -> V_284 . V_285 = 1 ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_406 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_67 )
{
if ( F_21 ( V_2 , V_35 ) )
return 0 ;
F_23 ( & V_2 -> V_29 ) ;
F_407 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
return F_355 ( V_2 ) ;
}
void
F_408 ( struct V_1 * V_2 )
{
int V_23 ;
if ( F_21 ( V_2 , V_35 ) )
return;
V_23 = F_355 ( V_2 ) ;
if ( V_23 )
F_13 ( L_31 , V_23 ) ;
}
static void
F_409 ( struct V_136 * V_137 )
{
F_198 ( & V_137 -> V_249 ) ;
F_198 ( & V_137 -> V_281 ) ;
}
void F_410 ( struct V_15 * V_16 ,
struct V_259 * V_258 )
{
if ( ! F_283 ( V_258 ) )
F_411 ( & V_258 -> V_18 , V_258 -> V_98 , V_258 -> V_47 ) ;
V_258 -> V_2 = V_16 -> V_2 ;
F_198 ( & V_258 -> V_249 ) ;
F_198 ( & V_258 -> V_260 ) ;
F_198 ( & V_258 -> V_470 ) ;
F_220 ( & V_258 -> V_470 , & V_16 -> V_471 ) ;
}
void
F_412 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_58 ;
V_16 -> V_72 =
F_413 ( L_32 ,
sizeof( struct V_6 ) , 0 ,
V_472 ,
NULL ) ;
F_198 ( & V_16 -> V_471 ) ;
F_410 ( V_16 , & V_16 -> V_42 . V_8 ) ;
F_198 ( & V_16 -> V_473 ) ;
F_198 ( & V_16 -> V_18 . V_226 ) ;
F_198 ( & V_16 -> V_18 . V_227 ) ;
F_198 ( & V_16 -> V_18 . V_256 ) ;
for ( V_58 = 0 ; V_58 < V_404 ; V_58 ++ )
F_409 ( & V_16 -> V_137 [ V_58 ] ) ;
for ( V_58 = 0 ; V_58 < V_474 ; V_58 ++ )
F_198 ( & V_16 -> V_254 [ V_58 ] . V_255 ) ;
F_414 ( & V_16 -> V_18 . V_286 ,
F_266 ) ;
F_414 ( & V_16 -> V_18 . V_158 ,
F_269 ) ;
F_415 ( & V_16 -> V_28 . V_24 ) ;
if ( ! F_21 ( V_2 , V_35 ) && F_416 ( V_2 ) ) {
F_290 ( V_475 ,
F_369 ( V_476 ) ) ;
}
V_16 -> V_477 = V_478 ;
if ( ! F_21 ( V_2 , V_35 ) )
V_16 -> V_347 = 3 ;
if ( F_22 ( V_2 ) -> V_41 >= 7 && ! F_396 ( V_2 ) )
V_16 -> V_303 = 32 ;
else if ( F_22 ( V_2 ) -> V_41 >= 4 || F_417 ( V_2 ) || F_418 ( V_2 ) || F_174 ( V_2 ) )
V_16 -> V_303 = 16 ;
else
V_16 -> V_303 = 8 ;
F_198 ( & V_16 -> V_18 . V_256 ) ;
F_259 ( V_2 ) ;
F_419 ( V_2 ) ;
F_415 ( & V_16 -> V_479 ) ;
V_16 -> V_18 . V_134 = true ;
V_16 -> V_18 . V_480 . V_481 = V_482 ;
V_16 -> V_18 . V_480 . V_483 = V_484 ;
V_16 -> V_18 . V_480 . V_485 = V_486 ;
F_420 ( & V_16 -> V_18 . V_480 ) ;
V_16 -> V_18 . V_487 . V_488 = V_489 ;
F_421 ( & V_16 -> V_18 . V_487 ) ;
F_422 ( & V_16 -> V_490 . V_282 ) ;
}
void F_423 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_143 * V_67 = V_33 -> V_177 ;
F_242 ( & V_67 -> V_18 . V_158 ) ;
F_7 ( & V_67 -> V_18 . V_282 ) ;
while ( ! F_199 ( & V_67 -> V_18 . V_281 ) ) {
struct V_267 * V_268 ;
V_268 = F_200 ( & V_67 -> V_18 . V_281 ,
struct V_267 ,
V_283 ) ;
F_196 ( & V_268 -> V_283 ) ;
V_268 -> V_67 = NULL ;
}
F_8 ( & V_67 -> V_18 . V_282 ) ;
}
static void
F_424 ( struct V_307 * V_308 )
{
struct V_143 * V_67 =
F_267 ( V_308 , F_201 ( * V_67 ) , V_18 . V_158 . V_308 ) ;
F_404 ( & V_67 -> V_144 , false ) ;
}
int F_425 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_143 * V_67 ;
int V_23 ;
F_398 ( L_33 ) ;
V_67 = F_426 ( sizeof( * V_67 ) , V_73 ) ;
if ( ! V_67 )
return - V_64 ;
V_33 -> V_177 = V_67 ;
V_67 -> V_16 = V_2 -> V_27 ;
V_67 -> V_33 = V_33 ;
F_427 ( & V_67 -> V_18 . V_282 ) ;
F_198 ( & V_67 -> V_18 . V_281 ) ;
F_414 ( & V_67 -> V_18 . V_158 ,
F_424 ) ;
V_23 = F_428 ( V_2 , V_33 ) ;
if ( V_23 )
F_194 ( V_67 ) ;
return V_23 ;
}
void F_429 ( struct V_6 * V_350 ,
struct V_6 * V_491 ,
unsigned V_416 )
{
if ( V_350 ) {
F_16 ( ! F_121 ( & V_350 -> V_8 . V_2 -> V_29 ) ) ;
F_16 ( ! ( V_350 -> V_416 & V_416 ) ) ;
V_350 -> V_416 &= ~ V_416 ;
}
if ( V_491 ) {
F_16 ( ! F_121 ( & V_491 -> V_8 . V_2 -> V_29 ) ) ;
F_16 ( V_491 -> V_416 & V_416 ) ;
V_491 -> V_416 |= V_416 ;
}
}
static bool F_430 ( struct V_492 * V_492 , struct V_140 * V_493 )
{
if ( ! F_121 ( V_492 ) )
return false ;
#if F_431 ( V_494 ) || F_431 ( V_495 )
return V_492 -> V_496 == V_493 ;
#else
return false ;
#endif
}
static bool F_432 ( struct V_1 * V_2 , bool * V_112 )
{
if ( ! F_268 ( & V_2 -> V_29 ) ) {
if ( ! F_430 ( & V_2 -> V_29 , V_165 ) )
return false ;
if ( F_433 ( V_2 ) -> V_18 . V_210 )
return false ;
* V_112 = false ;
} else
* V_112 = true ;
return true ;
}
static int F_434 ( struct V_6 * V_7 )
{
struct V_228 * V_188 ;
int V_225 = 0 ;
F_27 (vma, &obj->vma_list, vma_link)
if ( F_280 ( & V_188 -> V_319 ) )
V_225 ++ ;
return V_225 ;
}
static unsigned long
V_484 ( struct V_480 * V_480 , struct V_497 * V_498 )
{
struct V_15 * V_16 =
F_267 ( V_480 , struct V_15 , V_18 . V_480 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_6 * V_7 ;
unsigned long V_225 ;
bool V_112 ;
if ( ! F_432 ( V_2 , & V_112 ) )
return 0 ;
V_225 = 0 ;
F_27 (obj, &dev_priv->mm.unbound_list, global_list)
if ( V_7 -> V_218 == 0 )
V_225 += V_7 -> V_8 . V_17 >> V_198 ;
F_27 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_28 ( V_7 ) &&
V_7 -> V_218 == F_434 ( V_7 ) )
V_225 += V_7 -> V_8 . V_17 >> V_198 ;
}
if ( V_112 )
F_25 ( & V_2 -> V_29 ) ;
return V_225 ;
}
unsigned long F_331 ( struct V_6 * V_499 ,
struct V_259 * V_258 )
{
struct V_15 * V_16 = V_499 -> V_8 . V_2 -> V_27 ;
struct V_228 * V_188 ;
if ( ! V_16 -> V_18 . V_395 ||
V_258 == & V_16 -> V_18 . V_395 -> V_8 )
V_258 = & V_16 -> V_42 . V_8 ;
F_27 (vma, &o->vma_list, vma_link) {
if ( V_188 -> V_258 == V_258 )
return V_188 -> V_319 . V_98 ;
}
F_133 ( 1 , L_34 ,
F_283 ( V_258 ) ? L_35 : L_36 ) ;
return - 1 ;
}
bool F_435 ( struct V_6 * V_499 ,
struct V_259 * V_258 )
{
struct V_228 * V_188 ;
F_27 (vma, &o->vma_list, vma_link)
if ( V_188 -> V_258 == V_258 && F_280 ( & V_188 -> V_319 ) )
return true ;
return false ;
}
bool F_19 ( struct V_6 * V_499 )
{
struct V_228 * V_188 ;
F_27 (vma, &o->vma_list, vma_link)
if ( F_280 ( & V_188 -> V_319 ) )
return true ;
return false ;
}
unsigned long F_436 ( struct V_6 * V_499 ,
struct V_259 * V_258 )
{
struct V_15 * V_16 = V_499 -> V_8 . V_2 -> V_27 ;
struct V_228 * V_188 ;
if ( ! V_16 -> V_18 . V_395 ||
V_258 == & V_16 -> V_18 . V_395 -> V_8 )
V_258 = & V_16 -> V_42 . V_8 ;
F_120 ( F_199 ( & V_499 -> V_323 ) ) ;
F_27 (vma, &o->vma_list, vma_link)
if ( V_188 -> V_258 == V_258 )
return V_188 -> V_319 . V_17 ;
return 0 ;
}
static unsigned long
V_482 ( struct V_480 * V_480 , struct V_497 * V_498 )
{
struct V_15 * V_16 =
F_267 ( V_480 , struct V_15 , V_18 . V_480 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_500 ;
bool V_112 ;
if ( ! F_432 ( V_2 , & V_112 ) )
return V_501 ;
V_500 = F_178 ( V_16 , V_498 -> V_502 ) ;
if ( V_500 < V_498 -> V_502 )
V_500 += F_197 ( V_16 ,
V_498 -> V_502 - V_500 ,
false ) ;
if ( V_112 )
F_25 ( & V_2 -> V_29 ) ;
return V_500 ;
}
static int
V_489 ( struct V_503 * V_504 , unsigned long V_505 , void * V_506 )
{
struct V_15 * V_16 =
F_267 ( V_504 , struct V_15 , V_18 . V_487 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_6 * V_7 ;
unsigned long V_146 = F_139 ( 5000 ) + 1 ;
unsigned long V_45 , V_507 , V_508 , V_500 ;
bool V_415 ;
bool V_112 ;
while ( ! F_432 ( V_2 , & V_112 ) && -- V_146 ) {
F_437 ( 1 ) ;
if ( F_438 ( V_165 ) )
return V_509 ;
}
if ( V_146 == 0 ) {
F_439 ( L_37 ) ;
return V_509 ;
}
V_415 = V_16 -> V_18 . V_134 ;
V_16 -> V_18 . V_134 = false ;
V_500 = F_179 ( V_16 ) ;
V_16 -> V_18 . V_134 = V_415 ;
V_508 = V_507 = V_45 = 0 ;
F_27 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( ! V_7 -> V_8 . V_55 )
continue;
if ( V_7 -> V_218 )
V_45 += V_7 -> V_8 . V_17 ;
else
V_508 += V_7 -> V_8 . V_17 ;
}
F_27 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! V_7 -> V_8 . V_55 )
continue;
if ( V_7 -> V_218 )
V_45 += V_7 -> V_8 . V_17 ;
else
V_507 += V_7 -> V_8 . V_17 ;
}
if ( V_112 )
F_25 ( & V_2 -> V_29 ) ;
F_440 ( L_38 ,
V_500 , V_45 ) ;
if ( V_508 || V_507 )
F_439 ( L_39
L_40 ,
V_507 , V_508 ) ;
* ( unsigned long * ) V_506 += V_500 ;
return V_509 ;
}
struct V_228 * F_320 ( struct V_6 * V_7 )
{
struct V_228 * V_188 ;
if ( F_16 ( F_199 ( & V_7 -> V_323 ) ) )
return NULL ;
V_188 = F_200 ( & V_7 -> V_323 , F_201 ( * V_188 ) , V_318 ) ;
if ( V_188 -> V_258 != F_441 ( V_7 ) )
return NULL ;
return V_188 ;
}

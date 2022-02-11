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
if ( ! error -> V_135 )
return - V_136 ;
}
return 0 ;
}
int
F_119 ( struct V_137 * V_138 , T_6 V_139 )
{
int V_23 ;
F_120 ( ! F_121 ( & V_138 -> V_2 -> V_29 ) ) ;
V_23 = 0 ;
if ( V_139 == V_138 -> V_140 )
V_23 = F_122 ( V_138 , NULL ) ;
return V_23 ;
}
static void F_123 ( unsigned long V_31 )
{
F_124 ( (struct V_141 * ) V_31 ) ;
}
static bool F_125 ( struct V_15 * V_16 ,
struct V_137 * V_138 )
{
return F_126 ( V_138 -> V_142 , & V_16 -> V_28 . V_143 ) ;
}
static bool F_127 ( struct V_144 * V_67 )
{
if ( V_67 == NULL )
return true ;
return ! F_128 ( & V_67 -> V_145 , true ) ;
}
static int F_129 ( struct V_137 * V_138 , T_6 V_139 ,
unsigned V_146 ,
bool V_134 ,
T_10 * V_147 ,
struct V_144 * V_67 )
{
struct V_1 * V_2 = V_138 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
const bool V_148 =
F_130 ( V_16 -> V_28 . V_149 ) & F_131 ( V_138 ) ;
F_132 ( V_150 ) ;
unsigned long V_151 ;
T_10 V_152 , V_153 ;
int V_23 ;
F_133 ( ! F_134 ( V_16 ) , L_2 ) ;
if ( F_135 ( V_138 -> V_154 ( V_138 , true ) , V_139 ) )
return 0 ;
V_151 = V_147 ? V_155 + F_136 ( ( V_156 ) * V_147 ) : 0 ;
if ( F_22 ( V_2 ) -> V_41 >= 6 && V_138 -> V_142 == V_157 && F_127 ( V_67 ) ) {
F_137 ( V_16 ) ;
if ( V_67 )
F_138 ( V_16 -> V_158 ,
& V_67 -> V_18 . V_159 ,
F_139 ( 100 ) ) ;
}
if ( ! V_148 && F_16 ( ! V_138 -> V_160 ( V_138 ) ) )
return - V_36 ;
F_140 ( V_138 , V_139 ) ;
V_152 = F_141 () ;
for (; ; ) {
struct V_161 V_162 ;
F_142 ( & V_138 -> V_163 , & V_150 ,
V_134 ? V_164 : V_165 ) ;
if ( V_146 != F_143 ( & V_16 -> V_28 . V_146 ) ) {
V_23 = F_116 ( & V_16 -> V_28 , V_134 ) ;
if ( V_23 == 0 )
V_23 = - V_136 ;
break;
}
if ( F_135 ( V_138 -> V_154 ( V_138 , false ) , V_139 ) ) {
V_23 = 0 ;
break;
}
if ( V_134 && F_144 ( V_166 ) ) {
V_23 = - V_167 ;
break;
}
if ( V_147 && F_145 ( V_155 , V_151 ) ) {
V_23 = - V_168 ;
break;
}
V_162 . V_169 = NULL ;
if ( V_147 || F_125 ( V_16 , V_138 ) ) {
unsigned long V_170 ;
F_146 ( & V_162 , F_123 , ( unsigned long ) V_166 ) ;
V_170 = F_125 ( V_16 , V_138 ) ? V_155 + 1 : V_151 ;
F_147 ( & V_162 , V_170 ) ;
}
F_148 () ;
if ( V_162 . V_169 ) {
F_149 ( & V_162 ) ;
F_150 ( & V_162 ) ;
}
}
V_153 = F_141 () ;
F_151 ( V_138 , V_139 ) ;
if ( ! V_148 )
V_138 -> V_171 ( V_138 ) ;
F_152 ( & V_138 -> V_163 , & V_150 ) ;
if ( V_147 ) {
T_10 V_172 = * V_147 - ( V_153 - V_152 ) ;
* V_147 = V_172 < 0 ? 0 : V_172 ;
}
return V_23 ;
}
int
F_153 ( struct V_137 * V_138 , T_5 V_139 )
{
struct V_1 * V_2 = V_138 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_134 = V_16 -> V_18 . V_134 ;
int V_23 ;
F_120 ( ! F_121 ( & V_2 -> V_29 ) ) ;
F_120 ( V_139 == 0 ) ;
V_23 = F_116 ( & V_16 -> V_28 , V_134 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_119 ( V_138 , V_139 ) ;
if ( V_23 )
return V_23 ;
return F_129 ( V_138 , V_139 ,
F_143 ( & V_16 -> V_28 . V_146 ) ,
V_134 , NULL , NULL ) ;
}
static int
F_154 ( struct V_6 * V_7 ,
struct V_137 * V_138 )
{
if ( ! V_7 -> V_30 )
return 0 ;
V_7 -> V_173 = 0 ;
return 0 ;
}
static T_11 int
F_71 ( struct V_6 * V_7 ,
bool V_174 )
{
struct V_137 * V_138 = V_7 -> V_138 ;
T_6 V_139 ;
int V_23 ;
V_139 = V_174 ? V_7 -> V_173 : V_7 -> V_175 ;
if ( V_139 == 0 )
return 0 ;
V_23 = F_153 ( V_138 , V_139 ) ;
if ( V_23 )
return V_23 ;
return F_154 ( V_7 , V_138 ) ;
}
static T_11 int
F_155 ( struct V_6 * V_7 ,
struct V_144 * V_67 ,
bool V_174 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_137 * V_138 = V_7 -> V_138 ;
unsigned V_146 ;
T_6 V_139 ;
int V_23 ;
F_120 ( ! F_121 ( & V_2 -> V_29 ) ) ;
F_120 ( ! V_16 -> V_18 . V_134 ) ;
V_139 = V_174 ? V_7 -> V_173 : V_7 -> V_175 ;
if ( V_139 == 0 )
return 0 ;
V_23 = F_116 ( & V_16 -> V_28 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = F_119 ( V_138 , V_139 ) ;
if ( V_23 )
return V_23 ;
V_146 = F_143 ( & V_16 -> V_28 . V_146 ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_129 ( V_138 , V_139 , V_146 , true , NULL , V_67 ) ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_23 )
return V_23 ;
return F_154 ( V_7 , V_138 ) ;
}
int
F_156 ( struct V_1 * V_2 , void * V_31 ,
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
V_23 = F_155 ( V_7 ,
V_33 -> V_178 ,
! V_126 ) ;
if ( V_23 )
goto V_179;
if ( V_91 & V_180 ) {
V_23 = F_104 ( V_7 , V_126 != 0 ) ;
if ( V_23 == - V_40 )
V_23 = 0 ;
} else {
V_23 = F_157 ( V_7 , V_126 != 0 ) ;
}
V_179:
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_158 ( struct V_1 * V_2 , void * V_31 ,
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
V_96 = F_161 ( V_7 -> V_55 , 0 , args -> V_17 ,
V_184 | V_185 , V_186 ,
args -> V_68 ) ;
F_60 ( V_7 ) ;
if ( F_33 ( ( void * ) V_96 ) )
return V_96 ;
args -> V_187 = ( T_4 ) V_96 ;
return 0 ;
}
int F_162 ( struct V_188 * V_189 , struct V_190 * V_191 )
{
struct V_6 * V_7 = F_95 ( V_189 -> V_192 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_12 V_115 ;
unsigned long V_193 ;
int V_23 = 0 ;
bool V_194 = ! ! ( V_191 -> V_195 & V_196 ) ;
F_163 ( V_16 ) ;
V_115 = ( ( unsigned long ) V_191 -> V_197 - V_189 -> V_198 ) >>
V_199 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
goto V_109;
F_164 ( V_7 , V_115 , true , V_194 ) ;
V_23 = F_155 ( V_7 , NULL , ! V_194 ) ;
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
V_23 = F_165 ( V_7 ) ;
if ( V_23 )
goto V_200;
V_193 = V_16 -> V_42 . V_201 + F_106 ( V_7 ) ;
V_193 >>= V_199 ;
if ( ! V_7 -> V_202 ) {
unsigned long V_17 = F_166 (unsigned long,
vma->vm_end - vma->vm_start,
obj->base.size) ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_17 > > V_199 ; V_58 ++ ) {
V_23 = F_167 ( V_189 ,
( unsigned long ) V_189 -> V_198 + V_58 * V_39 ,
V_193 + V_58 ) ;
if ( V_23 )
break;
}
V_7 -> V_202 = true ;
} else
V_23 = F_167 ( V_189 ,
( unsigned long ) V_191 -> V_197 ,
V_193 + V_115 ) ;
V_200:
F_107 ( V_7 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
V_109:
switch ( V_23 ) {
case - V_26 :
if ( ! F_118 ( & V_16 -> V_28 ) ) {
V_23 = V_203 ;
break;
}
case - V_136 :
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
F_168 ( V_23 , L_3 , V_23 ) ;
V_23 = V_203 ;
break;
}
F_169 ( V_16 ) ;
return V_23 ;
}
void
F_5 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_202 )
return;
F_170 ( & V_7 -> V_8 . V_207 ,
V_7 -> V_8 . V_2 -> V_208 -> V_56 ) ;
V_7 -> V_202 = false ;
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
F_173 ( struct V_1 * V_2 , T_5 V_17 ,
int V_11 , bool V_210 )
{
if ( F_22 ( V_2 ) -> V_41 >= 4 || ( ! V_210 && F_174 ( V_2 ) ) ||
V_11 == V_132 )
return 4096 ;
return F_172 ( V_2 , V_17 , V_11 ) ;
}
static int F_175 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_176 ( & V_7 -> V_8 . V_207 ) )
return 0 ;
V_16 -> V_18 . V_211 = true ;
V_23 = F_177 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_133 )
goto V_109;
F_178 ( V_16 ,
V_7 -> V_8 . V_17 >> V_199 ,
V_212 |
V_213 |
V_214 ) ;
V_23 = F_177 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_133 )
goto V_109;
F_179 ( V_16 ) ;
V_23 = F_177 ( & V_7 -> V_8 ) ;
V_109:
V_16 -> V_18 . V_211 = false ;
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
V_23 = - V_215 ;
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
* V_68 = F_184 ( & V_7 -> V_8 . V_207 ) ;
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
struct V_216 * args = V_31 ;
return F_182 ( V_33 , V_2 , args -> V_75 , & args -> V_68 ) ;
}
static inline int
F_186 ( struct V_6 * V_7 )
{
return V_7 -> V_51 == V_217 ;
}
static void
F_187 ( struct V_6 * V_7 )
{
F_180 ( V_7 ) ;
if ( V_7 -> V_8 . V_55 == NULL )
return;
F_188 ( F_31 ( V_7 -> V_8 . V_55 ) , 0 , ( T_8 ) - 1 ) ;
V_7 -> V_51 = V_218 ;
}
static void
F_189 ( struct V_6 * V_7 )
{
struct V_53 * V_54 ;
switch ( V_7 -> V_51 ) {
case V_217 :
F_187 ( V_7 ) ;
case V_218 :
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
F_120 ( V_7 -> V_51 == V_218 ) ;
V_23 = F_157 ( V_7 , true ) ;
if ( V_23 ) {
F_16 ( V_23 != - V_26 ) ;
F_112 ( V_7 , true ) ;
V_7 -> V_8 . V_91 = V_7 -> V_8 . V_126 = V_92 ;
}
if ( F_85 ( V_7 ) )
F_192 ( V_7 ) ;
if ( V_7 -> V_51 == V_217 )
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
F_193 ( V_7 -> V_219 ) ;
F_194 ( V_7 -> V_219 ) ;
}
int
F_195 ( struct V_6 * V_7 )
{
const struct V_220 * V_221 = V_7 -> V_221 ;
if ( V_7 -> V_219 == NULL )
return 0 ;
if ( V_7 -> V_222 )
return - V_62 ;
F_120 ( F_19 ( V_7 ) ) ;
F_196 ( & V_7 -> V_223 ) ;
V_221 -> V_224 ( V_7 ) ;
V_7 -> V_219 = NULL ;
F_189 ( V_7 ) ;
return 0 ;
}
unsigned long
F_178 ( struct V_15 * V_16 ,
long V_225 , unsigned V_195 )
{
const bool V_226 = V_195 & V_214 ;
unsigned long V_227 = 0 ;
if ( V_195 & V_213 ) {
struct V_228 V_229 ;
F_197 ( & V_229 ) ;
while ( V_227 < V_225 && ! F_198 ( & V_16 -> V_18 . V_230 ) ) {
struct V_6 * V_7 ;
V_7 = F_199 ( & V_16 -> V_18 . V_230 ,
F_200 ( * V_7 ) , V_223 ) ;
F_201 ( & V_7 -> V_223 , & V_229 ) ;
if ( ! F_186 ( V_7 ) && V_226 )
continue;
F_202 ( & V_7 -> V_8 ) ;
if ( F_195 ( V_7 ) == 0 )
V_227 += V_7 -> V_8 . V_17 >> V_199 ;
F_98 ( & V_7 -> V_8 ) ;
}
F_203 ( & V_229 , & V_16 -> V_18 . V_230 ) ;
}
if ( V_195 & V_212 ) {
struct V_228 V_229 ;
F_197 ( & V_229 ) ;
while ( V_227 < V_225 && ! F_198 ( & V_16 -> V_18 . V_231 ) ) {
struct V_6 * V_7 ;
struct V_232 * V_189 , * V_233 ;
V_7 = F_199 ( & V_16 -> V_18 . V_231 ,
F_200 ( * V_7 ) , V_223 ) ;
F_201 ( & V_7 -> V_223 , & V_229 ) ;
if ( ! F_186 ( V_7 ) && V_226 )
continue;
F_202 ( & V_7 -> V_8 ) ;
F_204 (vma, v, &obj->vma_list, vma_link)
if ( F_205 ( V_189 ) )
break;
if ( F_195 ( V_7 ) == 0 )
V_227 += V_7 -> V_8 . V_17 >> V_199 ;
F_98 ( & V_7 -> V_8 ) ;
}
F_203 ( & V_229 , & V_16 -> V_18 . V_231 ) ;
}
return V_227 ;
}
static unsigned long
F_179 ( struct V_15 * V_16 )
{
F_206 ( V_16 -> V_2 ) ;
return F_178 ( V_16 , V_234 ,
V_212 | V_213 ) ;
}
static int
F_207 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_235 , V_58 ;
struct V_53 * V_54 ;
struct V_236 * V_237 ;
struct V_238 * V_239 ;
struct V_104 V_105 ;
struct V_59 * V_59 ;
unsigned long V_240 = 0 ;
T_13 V_241 ;
F_120 ( V_7 -> V_8 . V_91 & V_177 ) ;
F_120 ( V_7 -> V_8 . V_126 & V_177 ) ;
V_237 = F_208 ( sizeof( * V_237 ) , V_73 ) ;
if ( V_237 == NULL )
return - V_64 ;
V_235 = V_7 -> V_8 . V_17 / V_39 ;
if ( F_209 ( V_237 , V_235 , V_73 ) ) {
F_194 ( V_237 ) ;
return - V_64 ;
}
V_54 = F_31 ( V_7 -> V_8 . V_55 ) -> V_56 ;
V_241 = F_210 ( V_54 ) ;
V_241 |= V_242 | V_243 | V_244 ;
V_241 &= ~ ( V_245 | V_246 ) ;
V_239 = V_237 -> V_247 ;
V_237 -> V_248 = 0 ;
for ( V_58 = 0 ; V_58 < V_235 ; V_58 ++ ) {
V_59 = F_211 ( V_54 , V_58 , V_241 ) ;
if ( F_33 ( V_59 ) ) {
F_178 ( V_16 ,
V_235 ,
V_212 |
V_213 |
V_214 ) ;
V_59 = F_211 ( V_54 , V_58 , V_241 ) ;
}
if ( F_33 ( V_59 ) ) {
F_179 ( V_16 ) ;
V_59 = F_32 ( V_54 , V_58 ) ;
if ( F_33 ( V_59 ) )
goto V_249;
}
#ifdef F_212
if ( F_213 () ) {
V_237 -> V_248 ++ ;
F_214 ( V_239 , V_59 , V_39 , 0 ) ;
V_239 = F_215 ( V_239 ) ;
continue;
}
#endif
if ( ! V_58 || F_216 ( V_59 ) != V_240 + 1 ) {
if ( V_58 )
V_239 = F_215 ( V_239 ) ;
V_237 -> V_248 ++ ;
F_214 ( V_239 , V_59 , V_39 , 0 ) ;
} else {
V_239 -> V_85 += V_39 ;
}
V_240 = F_216 ( V_59 ) ;
F_16 ( ( V_241 & V_250 ) && ( V_240 >= 0x00100000UL ) ) ;
}
#ifdef F_212
if ( ! F_213 () )
#endif
F_217 ( V_239 ) ;
V_7 -> V_219 = V_237 ;
if ( F_85 ( V_7 ) )
F_218 ( V_7 ) ;
return 0 ;
V_249:
F_217 ( V_239 ) ;
F_86 (st->sgl, &sg_iter, st->nents, 0 )
F_39 ( F_87 ( & V_105 ) ) ;
F_193 ( V_237 ) ;
F_194 ( V_237 ) ;
if ( F_47 ( V_59 ) == - V_133 )
return - V_64 ;
else
return F_47 ( V_59 ) ;
}
int
F_73 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
const struct V_220 * V_221 = V_7 -> V_221 ;
int V_23 ;
if ( V_7 -> V_219 )
return 0 ;
if ( V_7 -> V_51 != V_52 ) {
F_183 ( L_5 ) ;
return - V_63 ;
}
F_120 ( V_7 -> V_222 ) ;
V_23 = V_221 -> V_251 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_219 ( & V_7 -> V_223 , & V_16 -> V_18 . V_230 ) ;
return 0 ;
}
static void
F_220 ( struct V_6 * V_7 ,
struct V_137 * V_138 )
{
T_6 V_139 = F_221 ( V_138 ) ;
F_120 ( V_138 == NULL ) ;
if ( V_7 -> V_138 != V_138 && V_7 -> V_173 ) {
V_7 -> V_173 = V_139 ;
}
V_7 -> V_138 = V_138 ;
if ( ! V_7 -> V_30 ) {
F_202 ( & V_7 -> V_8 ) ;
V_7 -> V_30 = 1 ;
}
F_201 ( & V_7 -> V_252 , & V_138 -> V_253 ) ;
V_7 -> V_175 = V_139 ;
}
void F_222 ( struct V_232 * V_189 ,
struct V_137 * V_138 )
{
F_201 ( & V_189 -> V_254 , & V_189 -> V_255 -> V_253 ) ;
return F_220 ( V_189 -> V_7 , V_138 ) ;
}
static void
F_223 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_256 * V_255 ;
struct V_232 * V_189 ;
F_120 ( V_7 -> V_8 . V_126 & ~ V_177 ) ;
F_120 ( ! V_7 -> V_30 ) ;
F_27 (vm, &dev_priv->vm_list, global_link) {
V_189 = F_224 ( V_7 , V_255 ) ;
if ( V_189 && ! F_198 ( & V_189 -> V_254 ) )
F_201 ( & V_189 -> V_254 , & V_255 -> V_257 ) ;
}
F_225 ( V_7 , true ) ;
F_226 ( & V_7 -> V_252 ) ;
V_7 -> V_138 = NULL ;
V_7 -> V_175 = 0 ;
V_7 -> V_173 = 0 ;
V_7 -> V_8 . V_126 = 0 ;
V_7 -> V_258 = 0 ;
V_7 -> V_30 = 0 ;
F_98 ( & V_7 -> V_8 ) ;
F_16 ( F_17 ( V_2 ) ) ;
}
static void
F_72 ( struct V_6 * V_7 )
{
struct V_137 * V_138 = V_7 -> V_138 ;
if ( V_138 == NULL )
return;
if ( F_135 ( V_138 -> V_154 ( V_138 , true ) ,
V_7 -> V_175 ) )
F_223 ( V_7 ) ;
}
static int
F_227 ( struct V_1 * V_2 , T_6 V_139 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_137 * V_138 ;
int V_23 , V_58 , V_259 ;
F_228 (ring, dev_priv, i) {
V_23 = F_229 ( V_138 ) ;
if ( V_23 )
return V_23 ;
}
F_230 ( V_2 ) ;
F_228 (ring, dev_priv, i) {
F_231 ( V_138 , V_139 ) ;
for ( V_259 = 0 ; V_259 < F_232 ( V_138 -> V_260 . V_261 ) ; V_259 ++ )
V_138 -> V_260 . V_261 [ V_259 ] = 0 ;
}
return 0 ;
}
int F_233 ( struct V_1 * V_2 , T_6 V_139 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( V_139 == 0 )
return - V_40 ;
V_23 = F_227 ( V_2 , V_139 - 1 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_262 = V_139 ;
V_16 -> V_263 = V_139 - 1 ;
if ( V_16 -> V_263 == 0 )
V_16 -> V_263 -- ;
return 0 ;
}
int
F_234 ( struct V_1 * V_2 , T_6 * V_139 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( V_16 -> V_262 == 0 ) {
int V_23 = F_227 ( V_2 , 0 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_262 = 1 ;
}
* V_139 = V_16 -> V_263 = V_16 -> V_262 ++ ;
return 0 ;
}
int F_235 ( struct V_137 * V_138 ,
struct V_32 * V_33 ,
struct V_6 * V_7 ,
T_6 * V_264 )
{
struct V_15 * V_16 = V_138 -> V_2 -> V_27 ;
struct V_265 * V_266 ;
struct V_267 * V_268 ;
T_6 V_269 , V_270 ;
int V_23 ;
V_266 = V_138 -> V_271 ;
if ( F_16 ( V_266 == NULL ) )
return - V_64 ;
if ( V_107 . V_272 ) {
struct V_273 * V_274 = V_266 -> V_274 ;
V_268 = V_274 -> V_275 [ V_138 -> V_142 ] . V_268 ;
} else
V_268 = V_138 -> V_276 ;
V_270 = F_236 ( V_268 ) ;
if ( V_107 . V_272 ) {
V_23 = F_237 ( V_268 ) ;
if ( V_23 )
return V_23 ;
} else {
V_23 = F_238 ( V_138 ) ;
if ( V_23 )
return V_23 ;
}
V_269 = F_236 ( V_268 ) ;
if ( V_107 . V_272 ) {
V_23 = V_138 -> V_277 ( V_268 ) ;
if ( V_23 )
return V_23 ;
} else {
V_23 = V_138 -> V_278 ( V_138 ) ;
if ( V_23 )
return V_23 ;
}
V_266 -> V_139 = F_221 ( V_138 ) ;
V_266 -> V_138 = V_138 ;
V_266 -> V_279 = V_270 ;
V_266 -> V_280 = V_269 ;
V_266 -> V_281 = V_7 ;
if ( ! V_107 . V_272 ) {
V_266 -> V_274 = V_138 -> V_282 ;
if ( V_266 -> V_274 )
F_239 ( V_266 -> V_274 ) ;
}
V_266 -> V_283 = V_155 ;
F_219 ( & V_266 -> V_284 , & V_138 -> V_285 ) ;
V_266 -> V_67 = NULL ;
if ( V_33 ) {
struct V_144 * V_67 = V_33 -> V_178 ;
F_7 ( & V_67 -> V_18 . V_286 ) ;
V_266 -> V_67 = V_67 ;
F_219 ( & V_266 -> V_287 ,
& V_67 -> V_18 . V_285 ) ;
F_8 ( & V_67 -> V_18 . V_286 ) ;
}
F_240 ( V_138 , V_266 -> V_139 ) ;
V_138 -> V_140 = 0 ;
V_138 -> V_271 = NULL ;
if ( ! V_16 -> V_288 . V_289 ) {
F_241 ( V_138 -> V_2 ) ;
F_242 ( & V_16 -> V_18 . V_159 ) ;
F_243 ( V_16 -> V_158 ,
& V_16 -> V_18 . V_290 ,
F_244 ( V_25 ) ) ;
F_245 ( V_16 -> V_2 ) ;
}
if ( V_264 )
* V_264 = V_266 -> V_139 ;
return 0 ;
}
static inline void
F_246 ( struct V_265 * V_266 )
{
struct V_144 * V_67 = V_266 -> V_67 ;
if ( ! V_67 )
return;
F_7 ( & V_67 -> V_18 . V_286 ) ;
F_196 ( & V_266 -> V_287 ) ;
V_266 -> V_67 = NULL ;
F_8 ( & V_67 -> V_18 . V_286 ) ;
}
static bool F_247 ( struct V_15 * V_16 ,
const struct V_273 * V_274 )
{
unsigned long V_291 ;
V_291 = F_248 () - V_274 -> V_292 . V_293 ;
if ( V_274 -> V_292 . V_294 )
return true ;
if ( V_291 <= V_295 ) {
if ( ! F_249 ( V_274 ) ) {
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
struct V_273 * V_274 ,
const bool V_296 )
{
struct V_297 * V_298 ;
if ( F_16 ( ! V_274 ) )
return;
V_298 = & V_274 -> V_292 ;
if ( V_296 ) {
V_298 -> V_294 = F_247 ( V_16 , V_274 ) ;
V_298 -> V_299 ++ ;
V_298 -> V_293 = F_248 () ;
} else {
V_298 -> V_300 ++ ;
}
}
static void F_253 ( struct V_265 * V_266 )
{
F_196 ( & V_266 -> V_284 ) ;
F_246 ( V_266 ) ;
if ( V_266 -> V_274 )
F_254 ( V_266 -> V_274 ) ;
F_194 ( V_266 ) ;
}
struct V_265 *
F_255 ( struct V_137 * V_138 )
{
struct V_265 * V_266 ;
T_6 V_301 ;
V_301 = V_138 -> V_154 ( V_138 , false ) ;
F_27 (request, &ring->request_list, list) {
if ( F_135 ( V_301 , V_266 -> V_139 ) )
continue;
return V_266 ;
}
return NULL ;
}
static void F_256 ( struct V_15 * V_16 ,
struct V_137 * V_138 )
{
struct V_265 * V_266 ;
bool V_302 ;
V_266 = F_255 ( V_138 ) ;
if ( V_266 == NULL )
return;
V_302 = V_138 -> V_303 . V_304 >= V_305 ;
F_252 ( V_16 , V_266 -> V_274 , V_302 ) ;
F_257 (request, &ring->request_list, list)
F_252 ( V_16 , V_266 -> V_274 , false ) ;
}
static void F_258 ( struct V_15 * V_16 ,
struct V_137 * V_138 )
{
while ( ! F_198 ( & V_138 -> V_253 ) ) {
struct V_6 * V_7 ;
V_7 = F_199 ( & V_138 -> V_253 ,
struct V_6 ,
V_252 ) ;
F_223 ( V_7 ) ;
}
while ( ! F_198 ( & V_138 -> V_285 ) ) {
struct V_265 * V_266 ;
V_266 = F_199 ( & V_138 -> V_285 ,
struct V_265 ,
V_284 ) ;
F_253 ( V_266 ) ;
}
while ( ! F_198 ( & V_138 -> V_306 ) ) {
struct V_307 * V_308 ;
V_308 = F_199 ( & V_138 -> V_306 ,
struct V_307 ,
V_309 ) ;
F_196 ( & V_308 -> V_309 ) ;
F_169 ( V_16 ) ;
F_254 ( V_308 -> V_274 ) ;
F_194 ( V_308 ) ;
}
F_194 ( V_138 -> V_271 ) ;
V_138 -> V_271 = NULL ;
V_138 -> V_140 = 0 ;
}
void F_259 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_16 -> V_310 ; V_58 ++ ) {
struct V_311 * V_312 = & V_16 -> V_313 [ V_58 ] ;
if ( V_312 -> V_7 ) {
F_260 ( V_312 -> V_7 , V_312 ,
V_312 -> V_7 -> V_11 ) ;
} else {
F_261 ( V_2 , V_58 , NULL ) ;
}
}
}
void F_262 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_137 * V_138 ;
int V_58 ;
F_228 (ring, dev_priv, i)
F_256 ( V_16 , V_138 ) ;
F_228 (ring, dev_priv, i)
F_258 ( V_16 , V_138 ) ;
F_263 ( V_2 ) ;
F_259 ( V_2 ) ;
}
void
F_264 ( struct V_137 * V_138 )
{
T_5 V_139 ;
if ( F_198 ( & V_138 -> V_285 ) )
return;
F_16 ( F_17 ( V_138 -> V_2 ) ) ;
V_139 = V_138 -> V_154 ( V_138 , true ) ;
while ( ! F_198 ( & V_138 -> V_253 ) ) {
struct V_6 * V_7 ;
V_7 = F_199 ( & V_138 -> V_253 ,
struct V_6 ,
V_252 ) ;
if ( ! F_135 ( V_139 , V_7 -> V_175 ) )
break;
F_223 ( V_7 ) ;
}
while ( ! F_198 ( & V_138 -> V_285 ) ) {
struct V_265 * V_266 ;
struct V_267 * V_268 ;
V_266 = F_199 ( & V_138 -> V_285 ,
struct V_265 ,
V_284 ) ;
if ( ! F_135 ( V_139 , V_266 -> V_139 ) )
break;
F_265 ( V_138 , V_266 -> V_139 ) ;
if ( V_107 . V_272 ) {
struct V_273 * V_274 = V_266 -> V_274 ;
V_268 = V_274 -> V_275 [ V_138 -> V_142 ] . V_268 ;
} else
V_268 = V_138 -> V_276 ;
V_268 -> V_314 = V_266 -> V_280 ;
F_253 ( V_266 ) ;
}
if ( F_76 ( V_138 -> V_315 &&
F_135 ( V_139 , V_138 -> V_315 ) ) ) {
V_138 -> V_171 ( V_138 ) ;
V_138 -> V_315 = 0 ;
}
F_16 ( F_17 ( V_138 -> V_2 ) ) ;
}
bool
F_230 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_137 * V_138 ;
bool V_316 = true ;
int V_58 ;
F_228 (ring, dev_priv, i) {
F_264 ( V_138 ) ;
V_316 &= F_198 ( & V_138 -> V_285 ) ;
}
if ( V_316 )
F_138 ( V_16 -> V_158 ,
& V_16 -> V_18 . V_159 ,
F_139 ( 100 ) ) ;
return V_316 ;
}
static void
F_266 ( struct V_317 * V_318 )
{
struct V_15 * V_16 =
F_267 ( V_318 , F_200 ( * V_16 ) , V_18 . V_290 . V_318 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_316 ;
V_316 = false ;
if ( F_268 ( & V_2 -> V_29 ) ) {
V_316 = F_230 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
}
if ( ! V_316 )
F_243 ( V_16 -> V_158 , & V_16 -> V_18 . V_290 ,
F_244 ( V_25 ) ) ;
}
static void
F_269 ( struct V_317 * V_318 )
{
struct V_15 * V_16 =
F_267 ( V_318 , F_200 ( * V_16 ) , V_18 . V_159 . V_318 ) ;
F_270 ( V_16 -> V_2 ) ;
}
static int
F_271 ( struct V_6 * V_7 )
{
int V_23 ;
if ( V_7 -> V_30 ) {
V_23 = F_119 ( V_7 -> V_138 , V_7 -> V_175 ) ;
if ( V_23 )
return V_23 ;
F_264 ( V_7 -> V_138 ) ;
}
return 0 ;
}
int
F_272 ( struct V_1 * V_2 , void * V_31 , struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_319 * args = V_31 ;
struct V_6 * V_7 ;
struct V_137 * V_138 = NULL ;
unsigned V_146 ;
T_6 V_139 = 0 ;
int V_23 = 0 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_95 ( F_96 ( V_2 , V_33 , args -> V_320 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_25 ( & V_2 -> V_29 ) ;
return - V_111 ;
}
V_23 = F_271 ( V_7 ) ;
if ( V_23 )
goto V_109;
if ( V_7 -> V_30 ) {
V_139 = V_7 -> V_175 ;
V_138 = V_7 -> V_138 ;
}
if ( V_139 == 0 )
goto V_109;
if ( args -> V_321 <= 0 ) {
V_23 = - V_168 ;
goto V_109;
}
F_98 ( & V_7 -> V_8 ) ;
V_146 = F_143 ( & V_16 -> V_28 . V_146 ) ;
F_25 ( & V_2 -> V_29 ) ;
return F_129 ( V_138 , V_139 , V_146 , true , & args -> V_321 ,
V_33 -> V_178 ) ;
V_109:
F_98 ( & V_7 -> V_8 ) ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_273 ( struct V_6 * V_7 ,
struct V_137 * V_322 )
{
struct V_137 * V_323 = V_7 -> V_138 ;
T_6 V_139 ;
int V_23 , V_324 ;
if ( V_323 == NULL || V_322 == V_323 )
return 0 ;
if ( V_322 == NULL || ! F_274 ( V_7 -> V_8 . V_2 ) )
return F_71 ( V_7 , false ) ;
V_324 = F_275 ( V_323 , V_322 ) ;
V_139 = V_7 -> V_175 ;
if ( V_139 <= V_323 -> V_260 . V_261 [ V_324 ] )
return 0 ;
V_23 = F_119 ( V_7 -> V_138 , V_139 ) ;
if ( V_23 )
return V_23 ;
F_276 ( V_323 , V_322 , V_139 ) ;
V_23 = V_322 -> V_260 . V_325 ( V_322 , V_323 , V_139 ) ;
if ( ! V_23 )
V_323 -> V_260 . V_261 [ V_324 ] = V_7 -> V_175 ;
return V_23 ;
}
static void F_277 ( struct V_6 * V_7 )
{
T_6 V_326 , V_327 ;
F_5 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_91 & V_180 ) == 0 )
return;
F_278 () ;
V_327 = V_7 -> V_8 . V_91 ;
V_326 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_91 &= ~ V_180 ;
V_7 -> V_8 . V_126 &= ~ V_180 ;
F_279 ( V_7 ,
V_327 ,
V_326 ) ;
}
int F_205 ( struct V_232 * V_189 )
{
struct V_6 * V_7 = V_189 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_198 ( & V_189 -> V_328 ) )
return 0 ;
if ( ! F_280 ( & V_189 -> V_329 ) ) {
F_281 ( V_189 ) ;
return 0 ;
}
if ( V_189 -> V_330 )
return - V_62 ;
F_120 ( V_7 -> V_219 == NULL ) ;
V_23 = F_282 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_72 ( V_7 ) ;
if ( F_283 ( V_189 -> V_255 ) ) {
F_277 ( V_7 ) ;
V_23 = F_105 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
F_284 ( V_189 ) ;
V_189 -> V_331 ( V_189 ) ;
F_226 ( & V_189 -> V_254 ) ;
if ( F_283 ( V_189 -> V_255 ) )
V_7 -> V_332 = false ;
F_285 ( & V_189 -> V_329 ) ;
F_281 ( V_189 ) ;
if ( F_198 ( & V_7 -> V_333 ) ) {
F_286 ( V_7 ) ;
F_201 ( & V_7 -> V_223 , & V_16 -> V_18 . V_230 ) ;
}
F_92 ( V_7 ) ;
return 0 ;
}
int F_287 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_137 * V_138 ;
int V_23 , V_58 ;
F_228 (ring, dev_priv, i) {
if ( ! V_107 . V_272 ) {
V_23 = F_288 ( V_138 , V_138 -> V_334 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_229 ( V_138 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static void F_289 ( struct V_1 * V_2 , int V_312 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_13 ;
int V_335 ;
if ( F_22 ( V_2 ) -> V_41 >= 6 ) {
V_13 = V_336 ;
V_335 = V_337 ;
} else {
V_13 = V_338 ;
V_335 = V_339 ;
}
V_13 += V_312 * 8 ;
F_290 ( V_13 , 0 ) ;
F_291 ( V_13 ) ;
if ( V_7 ) {
T_6 V_17 = F_29 ( V_7 ) ;
T_4 V_340 ;
V_340 = ( T_4 ) ( ( F_106 ( V_7 ) + V_17 - 4096 ) &
0xfffff000 ) << 32 ;
V_340 |= F_106 ( V_7 ) & 0xfffff000 ;
V_340 |= ( T_4 ) ( ( V_7 -> V_341 / 128 ) - 1 ) << V_335 ;
if ( V_7 -> V_11 == V_342 )
V_340 |= 1 << V_343 ;
V_340 |= V_344 ;
F_290 ( V_13 + 4 , V_340 >> 32 ) ;
F_291 ( V_13 + 4 ) ;
F_290 ( V_13 + 0 , V_340 ) ;
F_291 ( V_13 ) ;
} else {
F_290 ( V_13 + 4 , 0 ) ;
F_291 ( V_13 + 4 ) ;
}
}
static void F_292 ( struct V_1 * V_2 , int V_312 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_340 ;
if ( V_7 ) {
T_6 V_17 = F_29 ( V_7 ) ;
int V_345 ;
int V_346 ;
F_133 ( ( F_106 ( V_7 ) & ~ V_347 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_106 ( V_7 ) & ( V_17 - 1 ) ) ,
L_8 ,
F_106 ( V_7 ) , V_7 -> V_332 , V_17 ) ;
if ( V_7 -> V_11 == V_342 && F_293 ( V_2 ) )
V_346 = 128 ;
else
V_346 = 512 ;
V_345 = V_7 -> V_341 / V_346 ;
V_345 = F_294 ( V_345 ) - 1 ;
V_340 = F_106 ( V_7 ) ;
if ( V_7 -> V_11 == V_342 )
V_340 |= 1 << V_348 ;
V_340 |= F_295 ( V_17 ) ;
V_340 |= V_345 << V_349 ;
V_340 |= V_350 ;
} else
V_340 = 0 ;
if ( V_312 < 8 )
V_312 = V_351 + V_312 * 4 ;
else
V_312 = V_352 + ( V_312 - 8 ) * 4 ;
F_290 ( V_312 , V_340 ) ;
F_291 ( V_312 ) ;
}
static void F_296 ( struct V_1 * V_2 , int V_312 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_5 V_340 ;
if ( V_7 ) {
T_6 V_17 = F_29 ( V_7 ) ;
T_5 V_345 ;
F_133 ( ( F_106 ( V_7 ) & ~ V_353 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_106 ( V_7 ) & ( V_17 - 1 ) ) ,
L_9 ,
F_106 ( V_7 ) , V_17 ) ;
V_345 = V_7 -> V_341 / 128 ;
V_345 = F_294 ( V_345 ) - 1 ;
V_340 = F_106 ( V_7 ) ;
if ( V_7 -> V_11 == V_342 )
V_340 |= 1 << V_348 ;
V_340 |= F_297 ( V_17 ) ;
V_340 |= V_345 << V_349 ;
V_340 |= V_350 ;
} else
V_340 = 0 ;
F_290 ( V_351 + V_312 * 4 , V_340 ) ;
F_291 ( V_351 + V_312 * 4 ) ;
}
inline static bool F_298 ( struct V_6 * V_7 )
{
return V_7 && V_7 -> V_8 . V_91 & V_180 ;
}
static void F_261 ( struct V_1 * V_2 , int V_312 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_298 ( V_16 -> V_313 [ V_312 ] . V_7 ) )
F_278 () ;
F_133 ( V_7 && ( ! V_7 -> V_341 || ! V_7 -> V_11 ) ,
L_10 ,
V_7 -> V_341 , V_7 -> V_11 ) ;
switch ( F_22 ( V_2 ) -> V_41 ) {
case 8 :
case 7 :
case 6 :
case 5 :
case 4 : F_289 ( V_2 , V_312 , V_7 ) ; break;
case 3 : F_292 ( V_2 , V_312 , V_7 ) ; break;
case 2 : F_296 ( V_2 , V_312 , V_7 ) ; break;
default: F_299 () ;
}
if ( F_298 ( V_7 ) )
F_278 () ;
}
static inline int F_300 ( struct V_15 * V_16 ,
struct V_311 * V_354 )
{
return V_354 - V_16 -> V_313 ;
}
static void F_260 ( struct V_6 * V_7 ,
struct V_311 * V_354 ,
bool V_355 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_312 = F_300 ( V_16 , V_354 ) ;
F_261 ( V_7 -> V_8 . V_2 , V_312 , V_355 ? V_7 : NULL ) ;
if ( V_355 ) {
V_7 -> V_13 = V_312 ;
V_354 -> V_7 = V_7 ;
F_201 ( & V_354 -> V_356 , & V_16 -> V_18 . V_357 ) ;
} else {
V_7 -> V_13 = V_14 ;
V_354 -> V_7 = NULL ;
F_226 ( & V_354 -> V_356 ) ;
}
V_7 -> V_12 = false ;
}
static int
F_301 ( struct V_6 * V_7 )
{
if ( V_7 -> V_258 ) {
int V_23 = F_153 ( V_7 -> V_138 , V_7 -> V_258 ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_258 = 0 ;
}
return 0 ;
}
int
F_105 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_311 * V_354 ;
int V_23 ;
V_23 = F_301 ( V_7 ) ;
if ( V_23 )
return V_23 ;
if ( V_7 -> V_13 == V_14 )
return 0 ;
V_354 = & V_16 -> V_313 [ V_7 -> V_13 ] ;
if ( F_16 ( V_354 -> V_330 ) )
return - V_62 ;
F_4 ( V_7 ) ;
F_260 ( V_7 , V_354 , false ) ;
return 0 ;
}
static struct V_311 *
F_302 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_311 * V_312 , * V_358 ;
int V_58 ;
V_358 = NULL ;
for ( V_58 = V_16 -> V_359 ; V_58 < V_16 -> V_310 ; V_58 ++ ) {
V_312 = & V_16 -> V_313 [ V_58 ] ;
if ( ! V_312 -> V_7 )
return V_312 ;
if ( ! V_312 -> V_330 )
V_358 = V_312 ;
}
if ( V_358 == NULL )
goto V_360;
F_27 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_312 -> V_330 )
continue;
return V_312 ;
}
V_360:
if ( F_303 ( V_2 ) )
return F_304 ( - V_136 ) ;
return F_304 ( - V_361 ) ;
}
int
F_165 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_355 = V_7 -> V_11 != V_132 ;
struct V_311 * V_312 ;
int V_23 ;
if ( V_7 -> V_12 ) {
V_23 = F_301 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_7 -> V_13 != V_14 ) {
V_312 = & V_16 -> V_313 [ V_7 -> V_13 ] ;
if ( ! V_7 -> V_12 ) {
F_201 ( & V_312 -> V_356 ,
& V_16 -> V_18 . V_357 ) ;
return 0 ;
}
} else if ( V_355 ) {
if ( F_16 ( ! V_7 -> V_332 ) )
return - V_40 ;
V_312 = F_302 ( V_2 ) ;
if ( F_33 ( V_312 ) )
return F_47 ( V_312 ) ;
if ( V_312 -> V_7 ) {
struct V_6 * V_362 = V_312 -> V_7 ;
V_23 = F_301 ( V_362 ) ;
if ( V_23 )
return V_23 ;
F_4 ( V_362 ) ;
}
} else
return 0 ;
F_260 ( V_7 , V_312 , V_355 ) ;
return 0 ;
}
static bool F_305 ( struct V_232 * V_189 ,
unsigned long V_9 )
{
struct V_363 * V_364 = & V_189 -> V_329 ;
struct V_363 * V_365 ;
if ( V_189 -> V_255 -> V_18 . V_366 == NULL )
return true ;
if ( ! F_280 ( V_364 ) )
return true ;
if ( F_198 ( & V_364 -> V_367 ) )
return true ;
V_365 = F_306 ( V_364 -> V_367 . V_368 , struct V_363 , V_367 ) ;
if ( V_365 -> V_369 && ! V_365 -> V_370 && V_365 -> V_371 != V_9 )
return false ;
V_365 = F_306 ( V_364 -> V_367 . V_372 , struct V_363 , V_367 ) ;
if ( V_365 -> V_369 && ! V_364 -> V_370 && V_365 -> V_371 != V_9 )
return false ;
return true ;
}
static void F_307 ( struct V_1 * V_2 )
{
#if V_373
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_6 * V_7 ;
int V_374 = 0 ;
F_27 (obj, &dev_priv->mm.gtt_list, global_list) {
if ( V_7 -> V_364 == NULL ) {
F_308 ( V_375 L_11 ) ;
V_374 ++ ;
continue;
}
if ( V_7 -> V_9 != V_7 -> V_364 -> V_371 ) {
F_308 ( V_375 L_12 ,
F_106 ( V_7 ) ,
F_106 ( V_7 ) + F_29 ( V_7 ) ,
V_7 -> V_9 ,
V_7 -> V_364 -> V_371 ) ;
V_374 ++ ;
continue;
}
if ( ! F_305 ( V_2 ,
V_7 -> V_364 ,
V_7 -> V_9 ) ) {
F_308 ( V_375 L_13 ,
F_106 ( V_7 ) ,
F_106 ( V_7 ) + F_29 ( V_7 ) ,
V_7 -> V_9 ) ;
V_374 ++ ;
continue;
}
}
F_16 ( V_374 ) ;
#endif
}
static struct V_232 *
F_309 ( struct V_6 * V_7 ,
struct V_256 * V_255 ,
unsigned V_376 ,
T_4 V_195 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_17 , V_377 , V_378 , V_379 ;
unsigned long V_98 =
V_195 & V_380 ? V_195 & V_381 : 0 ;
unsigned long V_99 =
V_195 & V_118 ? V_16 -> V_42 . V_43 : V_255 -> V_47 ;
struct V_232 * V_189 ;
int V_23 ;
V_377 = F_172 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ) ;
V_378 = F_173 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , true ) ;
V_379 =
F_173 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , false ) ;
if ( V_376 == 0 )
V_376 = V_195 & V_118 ? V_378 :
V_379 ;
if ( V_195 & V_118 && V_376 & ( V_378 - 1 ) ) {
F_183 ( L_14 , V_376 ) ;
return F_304 ( - V_40 ) ;
}
V_17 = V_195 & V_118 ? V_377 : V_7 -> V_8 . V_17 ;
if ( V_7 -> V_8 . V_17 > V_99 ) {
F_183 ( L_15 ,
V_7 -> V_8 . V_17 ,
V_195 & V_118 ? L_16 : L_17 ,
V_99 ) ;
return F_304 ( - V_215 ) ;
}
V_23 = F_73 ( V_7 ) ;
if ( V_23 )
return F_304 ( V_23 ) ;
F_74 ( V_7 ) ;
V_189 = F_310 ( V_7 , V_255 ) ;
if ( F_33 ( V_189 ) )
goto V_382;
V_383:
V_23 = F_311 ( & V_255 -> V_18 , & V_189 -> V_329 ,
V_17 , V_376 ,
V_7 -> V_9 ,
V_98 , V_99 ,
V_384 ,
V_385 ) ;
if ( V_23 ) {
V_23 = F_312 ( V_2 , V_255 , V_17 , V_376 ,
V_7 -> V_9 ,
V_98 , V_99 ,
V_195 ) ;
if ( V_23 == 0 )
goto V_383;
goto V_386;
}
if ( F_16 ( ! F_305 ( V_189 , V_7 -> V_9 ) ) ) {
V_23 = - V_40 ;
goto V_387;
}
V_23 = F_313 ( V_7 ) ;
if ( V_23 )
goto V_387;
F_201 ( & V_7 -> V_223 , & V_16 -> V_18 . V_231 ) ;
F_219 ( & V_189 -> V_254 , & V_255 -> V_257 ) ;
if ( F_283 ( V_255 ) ) {
bool V_122 , V_388 ;
V_388 = ( V_189 -> V_329 . V_17 == V_377 &&
( V_189 -> V_329 . V_98 & ( V_378 - 1 ) ) == 0 ) ;
V_122 = ( V_189 -> V_329 . V_98 + V_7 -> V_8 . V_17 <=
V_16 -> V_42 . V_43 ) ;
V_7 -> V_332 = V_122 && V_388 ;
}
F_16 ( V_195 & V_118 && ! V_7 -> V_332 ) ;
F_314 ( V_189 , V_195 ) ;
V_189 -> V_389 ( V_189 , V_7 -> V_9 ,
V_195 & ( V_118 | V_390 ) ? V_391 : 0 ) ;
F_307 ( V_2 ) ;
return V_189 ;
V_387:
F_285 ( & V_189 -> V_329 ) ;
V_386:
F_281 ( V_189 ) ;
V_189 = F_304 ( V_23 ) ;
V_382:
F_92 ( V_7 ) ;
return V_189 ;
}
bool
F_112 ( struct V_6 * V_7 ,
bool V_392 )
{
if ( V_7 -> V_219 == NULL )
return false ;
if ( V_7 -> V_393 )
return false ;
if ( ! V_392 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) )
return false ;
F_315 ( V_7 ) ;
F_316 ( V_7 -> V_219 ) ;
return true ;
}
static void
F_317 ( struct V_6 * V_7 )
{
T_5 V_326 ;
if ( V_7 -> V_8 . V_126 != V_180 )
return;
F_318 () ;
V_326 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_126 = 0 ;
F_225 ( V_7 , false ) ;
F_279 ( V_7 ,
V_7 -> V_8 . V_91 ,
V_326 ) ;
}
static void
F_159 ( struct V_6 * V_7 ,
bool V_392 )
{
T_5 V_326 ;
if ( V_7 -> V_8 . V_126 != V_92 )
return;
if ( F_112 ( V_7 , V_392 ) )
F_40 ( V_7 -> V_8 . V_2 ) ;
V_326 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_126 = 0 ;
F_225 ( V_7 , false ) ;
F_279 ( V_7 ,
V_7 -> V_8 . V_91 ,
V_326 ) ;
}
int
F_104 ( struct V_6 * V_7 , bool V_194 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_232 * V_189 = F_319 ( V_7 ) ;
T_5 V_326 , V_327 ;
int V_23 ;
if ( V_189 == NULL )
return - V_40 ;
if ( V_7 -> V_8 . V_126 == V_180 )
return 0 ;
V_23 = F_71 ( V_7 , ! V_194 ) ;
if ( V_23 )
return V_23 ;
F_72 ( V_7 ) ;
F_159 ( V_7 , false ) ;
if ( ( V_7 -> V_8 . V_91 & V_180 ) == 0 )
F_278 () ;
V_326 = V_7 -> V_8 . V_126 ;
V_327 = V_7 -> V_8 . V_91 ;
F_120 ( ( V_7 -> V_8 . V_126 & ~ V_180 ) != 0 ) ;
V_7 -> V_8 . V_91 |= V_180 ;
if ( V_194 ) {
V_7 -> V_8 . V_91 = V_180 ;
V_7 -> V_8 . V_126 = V_180 ;
V_7 -> V_127 = 1 ;
}
if ( V_194 )
F_320 ( V_7 , NULL ) ;
F_279 ( V_7 ,
V_327 ,
V_326 ) ;
if ( F_18 ( V_7 ) )
F_201 ( & V_189 -> V_254 ,
& V_16 -> V_42 . V_8 . V_257 ) ;
return 0 ;
}
int F_321 ( struct V_6 * V_7 ,
enum V_3 V_9 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_232 * V_189 , * V_372 ;
int V_23 ;
if ( V_7 -> V_9 == V_9 )
return 0 ;
if ( F_28 ( V_7 ) ) {
F_183 ( L_18 ) ;
return - V_62 ;
}
F_204 (vma, next, &obj->vma_list, vma_link) {
if ( ! F_305 ( V_189 , V_9 ) ) {
V_23 = F_205 ( V_189 ) ;
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
if ( F_280 ( & V_189 -> V_329 ) )
V_189 -> V_389 ( V_189 , V_9 ,
V_7 -> V_394 ? V_391 : 0 ) ;
}
F_27 (vma, &obj->vma_list, vma_link)
V_189 -> V_329 . V_371 = V_9 ;
V_7 -> V_9 = V_9 ;
if ( F_3 ( V_7 ) ) {
T_6 V_327 , V_326 ;
F_72 ( V_7 ) ;
F_16 ( V_7 -> V_8 . V_126 & ~ V_92 ) ;
V_327 = V_7 -> V_8 . V_91 ;
V_326 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_91 = V_92 ;
V_7 -> V_8 . V_126 = V_92 ;
F_279 ( V_7 ,
V_327 ,
V_326 ) ;
}
F_307 ( V_2 ) ;
return 0 ;
}
int F_322 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_395 * args = V_31 ;
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
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_323 ( struct V_1 * V_2 , void * V_31 ,
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
V_4 = F_324 ( V_2 ) ? V_400 : V_5 ;
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
struct V_232 * V_189 ;
V_189 = F_319 ( V_7 ) ;
if ( ! V_189 )
return false ;
return V_189 -> V_330 - ! ! V_7 -> V_403 ;
}
int
F_326 ( struct V_6 * V_7 ,
T_6 V_376 ,
struct V_137 * V_404 )
{
T_6 V_327 , V_326 ;
bool V_405 ;
int V_23 ;
if ( V_404 != V_7 -> V_138 ) {
V_23 = F_273 ( V_7 , V_404 ) ;
if ( V_23 )
return V_23 ;
}
V_405 = V_7 -> V_10 ;
V_7 -> V_10 = true ;
V_23 = F_321 ( V_7 ,
F_324 ( V_7 -> V_8 . V_2 ) ? V_400 : V_5 ) ;
if ( V_23 )
goto V_406;
V_23 = F_103 ( V_7 , V_376 , V_118 ) ;
if ( V_23 )
goto V_406;
F_159 ( V_7 , true ) ;
V_326 = V_7 -> V_8 . V_126 ;
V_327 = V_7 -> V_8 . V_91 ;
V_7 -> V_8 . V_126 = 0 ;
V_7 -> V_8 . V_91 |= V_180 ;
F_279 ( V_7 ,
V_327 ,
V_326 ) ;
return 0 ;
V_406:
F_16 ( V_405 != F_325 ( V_7 ) ) ;
V_7 -> V_10 = V_405 ;
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
if ( ( V_7 -> V_8 . V_91 & V_177 ) == 0 )
return 0 ;
V_23 = F_71 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_8 . V_91 &= ~ V_177 ;
return 0 ;
}
int
F_157 ( struct V_6 * V_7 , bool V_194 )
{
T_5 V_326 , V_327 ;
int V_23 ;
if ( V_7 -> V_8 . V_126 == V_92 )
return 0 ;
V_23 = F_71 ( V_7 , ! V_194 ) ;
if ( V_23 )
return V_23 ;
F_72 ( V_7 ) ;
F_317 ( V_7 ) ;
V_326 = V_7 -> V_8 . V_126 ;
V_327 = V_7 -> V_8 . V_91 ;
if ( ( V_7 -> V_8 . V_91 & V_92 ) == 0 ) {
F_112 ( V_7 , false ) ;
V_7 -> V_8 . V_91 |= V_92 ;
}
F_120 ( ( V_7 -> V_8 . V_126 & ~ V_92 ) != 0 ) ;
if ( V_194 ) {
V_7 -> V_8 . V_91 = V_92 ;
V_7 -> V_8 . V_126 = V_92 ;
}
if ( V_194 )
F_320 ( V_7 , NULL ) ;
F_279 ( V_7 ,
V_327 ,
V_326 ) ;
return 0 ;
}
static int
F_328 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_144 * V_67 = V_33 -> V_178 ;
unsigned long V_407 = V_155 - F_139 ( 20 ) ;
struct V_265 * V_266 ;
struct V_137 * V_138 = NULL ;
unsigned V_146 ;
T_6 V_139 = 0 ;
int V_23 ;
V_23 = F_10 ( & V_16 -> V_28 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_116 ( & V_16 -> V_28 , false ) ;
if ( V_23 )
return V_23 ;
F_7 ( & V_67 -> V_18 . V_286 ) ;
F_27 (request, &file_priv->mm.request_list, client_list) {
if ( F_145 ( V_266 -> V_283 , V_407 ) )
break;
V_138 = V_266 -> V_138 ;
V_139 = V_266 -> V_139 ;
}
V_146 = F_143 ( & V_16 -> V_28 . V_146 ) ;
F_8 ( & V_67 -> V_18 . V_286 ) ;
if ( V_139 == 0 )
return 0 ;
V_23 = F_129 ( V_138 , V_139 , V_146 , true , NULL , NULL ) ;
if ( V_23 == 0 )
F_243 ( V_16 -> V_158 , & V_16 -> V_18 . V_290 , 0 ) ;
return V_23 ;
}
static bool
F_329 ( struct V_232 * V_189 , T_5 V_376 , T_4 V_195 )
{
struct V_6 * V_7 = V_189 -> V_7 ;
if ( V_376 &&
V_189 -> V_329 . V_98 & ( V_376 - 1 ) )
return true ;
if ( V_195 & V_118 && ! V_7 -> V_332 )
return true ;
if ( V_195 & V_380 &&
V_189 -> V_329 . V_98 < ( V_195 & V_381 ) )
return true ;
return false ;
}
int
F_330 ( struct V_6 * V_7 ,
struct V_256 * V_255 ,
T_5 V_376 ,
T_4 V_195 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_232 * V_189 ;
int V_23 ;
if ( F_16 ( V_255 == & V_16 -> V_18 . V_408 -> V_8 ) )
return - V_36 ;
if ( F_16 ( V_195 & ( V_390 | V_118 ) && ! F_283 ( V_255 ) ) )
return - V_40 ;
V_189 = F_224 ( V_7 , V_255 ) ;
if ( V_189 ) {
if ( F_16 ( V_189 -> V_330 == V_409 ) )
return - V_62 ;
if ( F_329 ( V_189 , V_376 , V_195 ) ) {
F_133 ( V_189 -> V_330 ,
L_19
L_20
L_21 ,
F_331 ( V_7 , V_255 ) , V_376 ,
! ! ( V_195 & V_118 ) ,
V_7 -> V_332 ) ;
V_23 = F_205 ( V_189 ) ;
if ( V_23 )
return V_23 ;
V_189 = NULL ;
}
}
if ( V_189 == NULL || ! F_280 ( & V_189 -> V_329 ) ) {
V_189 = F_309 ( V_7 , V_255 , V_376 , V_195 ) ;
if ( F_33 ( V_189 ) )
return F_47 ( V_189 ) ;
}
if ( V_195 & V_390 && ! V_7 -> V_394 )
V_189 -> V_389 ( V_189 , V_7 -> V_9 , V_391 ) ;
V_189 -> V_330 ++ ;
if ( V_195 & V_118 )
V_7 -> V_410 |= true ;
return 0 ;
}
void
F_107 ( struct V_6 * V_7 )
{
struct V_232 * V_189 = F_319 ( V_7 ) ;
F_120 ( ! V_189 ) ;
F_120 ( V_189 -> V_330 == 0 ) ;
F_120 ( ! F_332 ( V_7 ) ) ;
if ( -- V_189 -> V_330 == 0 )
V_7 -> V_410 = false ;
}
bool
F_333 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 != V_14 ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_232 * V_411 = F_319 ( V_7 ) ;
F_16 ( ! V_411 ||
V_16 -> V_313 [ V_7 -> V_13 ] . V_330 >
V_411 -> V_330 ) ;
V_16 -> V_313 [ V_7 -> V_13 ] . V_330 ++ ;
return true ;
} else
return false ;
}
void
F_334 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 != V_14 ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
F_16 ( V_16 -> V_313 [ V_7 -> V_13 ] . V_330 <= 0 ) ;
V_16 -> V_313 [ V_7 -> V_13 ] . V_330 -- ;
}
}
int
F_335 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_412 * args = V_31 ;
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
if ( V_7 -> V_413 != NULL && V_7 -> V_413 != V_33 ) {
F_183 ( L_23 ,
args -> V_75 ) ;
V_23 = - V_40 ;
goto V_109;
}
if ( V_7 -> V_403 == V_414 ) {
V_23 = - V_62 ;
goto V_109;
}
if ( V_7 -> V_403 == 0 ) {
V_23 = F_103 ( V_7 , args -> V_376 , V_118 ) ;
if ( V_23 )
goto V_109;
}
V_7 -> V_403 ++ ;
V_7 -> V_413 = V_33 ;
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
struct V_412 * args = V_31 ;
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
if ( V_7 -> V_413 != V_33 ) {
F_183 ( L_24 ,
args -> V_75 ) ;
V_23 = - V_40 ;
goto V_109;
}
V_7 -> V_403 -- ;
if ( V_7 -> V_403 == 0 ) {
V_7 -> V_413 = NULL ;
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
struct V_415 * args = V_31 ;
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
args -> V_416 = V_7 -> V_30 ;
if ( V_7 -> V_138 ) {
F_338 ( V_417 > 16 ) ;
args -> V_416 |= F_131 ( V_7 -> V_138 ) << 16 ;
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
struct V_418 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
switch ( args -> V_51 ) {
case V_217 :
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
if ( V_7 -> V_51 != V_218 )
V_7 -> V_51 = args -> V_51 ;
if ( F_186 ( V_7 ) && V_7 -> V_219 == NULL )
F_187 ( V_7 ) ;
args -> V_419 = V_7 -> V_51 != V_218 ;
V_109:
F_98 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void F_341 ( struct V_6 * V_7 ,
const struct V_220 * V_221 )
{
F_197 ( & V_7 -> V_223 ) ;
F_197 ( & V_7 -> V_252 ) ;
F_197 ( & V_7 -> V_420 ) ;
F_197 ( & V_7 -> V_333 ) ;
V_7 -> V_221 = V_221 ;
V_7 -> V_13 = V_14 ;
V_7 -> V_51 = V_52 ;
F_6 ( V_7 -> V_8 . V_2 -> V_27 , V_7 -> V_8 . V_17 ) ;
}
struct V_6 * F_58 ( struct V_1 * V_2 ,
T_1 V_17 )
{
struct V_6 * V_7 ;
struct V_53 * V_54 ;
T_13 V_421 ;
V_7 = F_52 ( V_2 ) ;
if ( V_7 == NULL )
return NULL ;
if ( F_342 ( V_2 , & V_7 -> V_8 , V_17 ) != 0 ) {
F_54 ( V_7 ) ;
return NULL ;
}
V_421 = V_422 | V_423 ;
if ( F_343 ( V_2 ) || F_344 ( V_2 ) ) {
V_421 &= ~ V_424 ;
V_421 |= V_250 ;
}
V_54 = F_31 ( V_7 -> V_8 . V_55 ) -> V_56 ;
F_345 ( V_54 , V_421 ) ;
F_341 ( V_7 , & V_425 ) ;
V_7 -> V_8 . V_126 = V_92 ;
V_7 -> V_8 . V_91 = V_92 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_9 = V_396 ;
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
return F_348 ( & V_7 -> V_8 . V_55 -> V_426 ) == 1 ;
}
void F_349 ( struct V_183 * V_427 )
{
struct V_6 * V_7 = F_95 ( V_427 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_232 * V_189 , * V_372 ;
F_163 ( V_16 ) ;
F_350 ( V_7 ) ;
F_204 (vma, next, &obj->vma_list, vma_link) {
int V_23 ;
V_189 -> V_330 = 0 ;
V_23 = F_205 ( V_189 ) ;
if ( F_16 ( V_23 == - V_167 ) ) {
bool V_428 ;
V_428 = V_16 -> V_18 . V_134 ;
V_16 -> V_18 . V_134 = false ;
F_16 ( F_205 ( V_189 ) ) ;
V_16 -> V_18 . V_134 = V_428 ;
}
}
F_30 ( V_7 ) ;
if ( V_7 -> V_393 )
F_92 ( V_7 ) ;
F_16 ( V_7 -> V_429 ) ;
if ( F_16 ( V_7 -> V_222 ) )
V_7 -> V_222 = 0 ;
if ( F_347 ( V_7 ) )
V_7 -> V_51 = V_217 ;
F_195 ( V_7 ) ;
F_180 ( V_7 ) ;
F_120 ( V_7 -> V_219 ) ;
if ( V_7 -> V_8 . V_430 )
F_351 ( & V_7 -> V_8 , NULL ) ;
if ( V_7 -> V_221 -> V_431 )
V_7 -> V_221 -> V_431 ( V_7 ) ;
F_352 ( & V_7 -> V_8 ) ;
F_9 ( V_16 , V_7 -> V_8 . V_17 ) ;
F_194 ( V_7 -> V_432 ) ;
F_54 ( V_7 ) ;
F_169 ( V_16 ) ;
}
struct V_232 * F_224 ( struct V_6 * V_7 ,
struct V_256 * V_255 )
{
struct V_232 * V_189 ;
F_27 (vma, &obj->vma_list, vma_link)
if ( V_189 -> V_255 == V_255 )
return V_189 ;
return NULL ;
}
void F_281 ( struct V_232 * V_189 )
{
struct V_256 * V_255 = NULL ;
F_16 ( V_189 -> V_329 . V_369 ) ;
if ( ! F_198 ( & V_189 -> V_433 ) )
return;
V_255 = V_189 -> V_255 ;
if ( ! F_283 ( V_255 ) )
F_353 ( F_354 ( V_255 ) ) ;
F_196 ( & V_189 -> V_328 ) ;
F_194 ( V_189 ) ;
}
static void
F_355 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_137 * V_138 ;
int V_58 ;
F_228 (ring, dev_priv, i)
V_16 -> V_434 . V_435 ( V_138 ) ;
}
int
F_356 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 = 0 ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_16 -> V_288 . V_289 )
goto V_374;
V_23 = F_287 ( V_2 ) ;
if ( V_23 )
goto V_374;
F_230 ( V_2 ) ;
if ( ! F_21 ( V_2 , V_35 ) )
F_206 ( V_2 ) ;
F_357 ( V_2 ) ;
F_355 ( V_2 ) ;
V_16 -> V_288 . V_289 = ! F_21 ( V_2 ,
V_35 ) ;
F_25 ( & V_2 -> V_29 ) ;
F_358 ( & V_16 -> V_28 . V_436 ) ;
F_242 ( & V_16 -> V_18 . V_290 ) ;
F_359 ( & V_16 -> V_18 . V_159 ) ;
return 0 ;
V_374:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_360 ( struct V_137 * V_138 , int V_437 )
{
struct V_1 * V_2 = V_138 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_438 = V_439 + ( V_437 * 0x200 ) ;
T_6 * V_440 = V_16 -> V_441 . V_440 [ V_437 ] ;
int V_58 , V_23 ;
if ( ! F_361 ( V_2 ) || ! V_440 )
return 0 ;
V_23 = F_362 ( V_138 , V_442 / 4 * 3 ) ;
if ( V_23 )
return V_23 ;
for ( V_58 = 0 ; V_58 < V_442 ; V_58 += 4 ) {
F_363 ( V_138 , F_364 ( 1 ) ) ;
F_363 ( V_138 , V_438 + V_58 ) ;
F_363 ( V_138 , V_440 [ V_58 / 4 ] ) ;
}
F_365 ( V_138 ) ;
return V_23 ;
}
void F_366 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_22 ( V_2 ) -> V_41 < 5 ||
V_16 -> V_18 . V_443 == V_444 )
return;
F_290 ( V_445 , F_367 ( V_445 ) |
V_446 ) ;
if ( F_368 ( V_2 ) )
return;
F_290 ( V_447 , F_367 ( V_447 ) | V_448 ) ;
if ( F_369 ( V_2 ) )
F_290 ( V_449 , F_370 ( V_450 ) ) ;
else if ( F_371 ( V_2 ) )
F_290 ( V_449 , F_370 ( V_451 ) ) ;
else if ( F_372 ( V_2 ) )
F_290 ( V_452 , F_370 ( V_453 ) ) ;
else
F_299 () ;
}
static bool
F_373 ( struct V_1 * V_2 )
{
if ( ! F_374 ( V_2 ) )
return false ;
if ( F_369 ( V_2 ) && V_2 -> V_454 -> V_455 < 8 ) {
F_375 ( L_25
L_26 ) ;
return false ;
}
return true ;
}
static void F_376 ( struct V_1 * V_2 , T_6 V_8 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
F_290 ( F_377 ( V_8 ) , 0 ) ;
F_290 ( F_378 ( V_8 ) , 0 ) ;
F_290 ( F_379 ( V_8 ) , 0 ) ;
F_290 ( F_380 ( V_8 ) , 0 ) ;
}
static void F_381 ( struct V_1 * V_2 )
{
if ( F_382 ( V_2 ) ) {
F_376 ( V_2 , V_456 ) ;
F_376 ( V_2 , V_457 ) ;
F_376 ( V_2 , V_458 ) ;
F_376 ( V_2 , V_459 ) ;
F_376 ( V_2 , V_460 ) ;
} else if ( F_383 ( V_2 ) ) {
F_376 ( V_2 , V_457 ) ;
F_376 ( V_2 , V_458 ) ;
} else if ( F_384 ( V_2 ) ) {
F_376 ( V_2 , V_456 ) ;
F_376 ( V_2 , V_461 ) ;
}
}
int F_385 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
F_381 ( V_2 ) ;
V_23 = F_386 ( V_2 ) ;
if ( V_23 )
return V_23 ;
if ( F_387 ( V_2 ) ) {
V_23 = F_388 ( V_2 ) ;
if ( V_23 )
goto V_462;
}
if ( F_373 ( V_2 ) ) {
V_23 = F_389 ( V_2 ) ;
if ( V_23 )
goto V_463;
}
if ( F_390 ( V_2 ) ) {
V_23 = F_391 ( V_2 ) ;
if ( V_23 )
goto V_464;
}
if ( F_392 ( V_2 ) ) {
V_23 = F_393 ( V_2 ) ;
if ( V_23 )
goto V_465;
}
V_23 = F_233 ( V_2 , ( ( T_6 ) ~ 0 - 0x1000 ) ) ;
if ( V_23 )
goto V_466;
return 0 ;
V_466:
F_394 ( & V_16 -> V_138 [ V_467 ] ) ;
V_465:
F_394 ( & V_16 -> V_138 [ V_468 ] ) ;
V_464:
F_394 ( & V_16 -> V_138 [ V_469 ] ) ;
V_463:
F_394 ( & V_16 -> V_138 [ V_470 ] ) ;
V_462:
F_394 ( & V_16 -> V_138 [ V_157 ] ) ;
return V_23 ;
}
int
F_395 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 , V_58 ;
if ( F_22 ( V_2 ) -> V_41 < 6 && ! F_396 () )
return - V_26 ;
if ( V_16 -> V_471 )
F_290 ( V_472 , F_367 ( V_472 ) | F_397 ( 0xf ) ) ;
if ( F_398 ( V_2 ) )
F_290 ( V_473 , F_399 ( V_2 ) ?
V_474 : V_475 ) ;
if ( F_400 ( V_2 ) ) {
if ( F_401 ( V_2 ) ) {
T_6 V_476 = F_367 ( V_477 ) ;
V_476 &= ~ ( V_478 | V_479 ) ;
F_290 ( V_477 , V_476 ) ;
} else if ( F_22 ( V_2 ) -> V_41 >= 7 ) {
T_6 V_476 = F_367 ( V_480 ) ;
V_476 &= ~ V_481 ;
F_290 ( V_480 , V_476 ) ;
}
}
F_366 ( V_2 ) ;
V_23 = V_16 -> V_434 . V_482 ( V_2 ) ;
if ( V_23 )
return V_23 ;
for ( V_58 = 0 ; V_58 < F_402 ( V_2 ) ; V_58 ++ )
F_360 ( & V_16 -> V_138 [ V_157 ] , V_58 ) ;
V_23 = F_403 ( V_16 ) ;
if ( V_23 && V_23 != - V_26 ) {
F_13 ( L_27 , V_23 ) ;
F_404 ( V_2 ) ;
return V_23 ;
}
V_23 = F_405 ( V_2 ) ;
if ( V_23 && V_23 != - V_26 ) {
F_13 ( L_28 , V_23 ) ;
F_404 ( V_2 ) ;
}
return V_23 ;
}
int F_406 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
V_107 . V_272 = F_407 ( V_2 ,
V_107 . V_272 ) ;
F_23 ( & V_2 -> V_29 ) ;
if ( F_408 ( V_2 ) ) {
F_290 ( V_483 , V_484 ) ;
if ( F_409 ( ( F_367 ( V_485 ) &
V_486 ) , 10 ) )
F_410 ( L_29 ) ;
}
if ( ! V_107 . V_272 ) {
V_16 -> V_434 . V_487 = V_488 ;
V_16 -> V_434 . V_482 = F_385 ;
V_16 -> V_434 . V_489 = F_394 ;
V_16 -> V_434 . V_435 = V_490 ;
} else {
V_16 -> V_434 . V_487 = V_491 ;
V_16 -> V_434 . V_482 = V_492 ;
V_16 -> V_434 . V_489 = V_493 ;
V_16 -> V_434 . V_435 = V_494 ;
}
V_23 = F_411 ( V_2 ) ;
if ( V_23 ) {
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
F_412 ( V_2 ) ;
V_23 = F_413 ( V_2 ) ;
if ( V_23 ) {
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
V_23 = F_395 ( V_2 ) ;
if ( V_23 == - V_26 ) {
F_13 ( L_30 ) ;
F_414 ( V_495 , & V_16 -> V_28 . V_146 ) ;
V_23 = 0 ;
}
F_25 ( & V_2 -> V_29 ) ;
if ( ! F_21 ( V_2 , V_35 ) )
V_16 -> V_496 . V_497 = 1 ;
return V_23 ;
}
void
F_404 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_137 * V_138 ;
int V_58 ;
F_228 (ring, dev_priv, i)
V_16 -> V_434 . V_489 ( V_138 ) ;
}
int
F_415 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_67 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( F_21 ( V_2 , V_35 ) )
return 0 ;
if ( F_117 ( & V_16 -> V_28 ) ) {
F_13 ( L_31 ) ;
F_416 ( & V_16 -> V_28 . V_146 , 0 ) ;
}
F_23 ( & V_2 -> V_29 ) ;
V_16 -> V_288 . V_289 = 0 ;
V_23 = F_395 ( V_2 ) ;
if ( V_23 != 0 ) {
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
F_120 ( ! F_198 ( & V_16 -> V_42 . V_8 . V_253 ) ) ;
V_23 = F_417 ( V_2 , V_2 -> V_454 -> V_498 ) ;
if ( V_23 )
goto V_499;
F_25 ( & V_2 -> V_29 ) ;
return 0 ;
V_499:
F_404 ( V_2 ) ;
V_16 -> V_288 . V_289 = 1 ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_418 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_67 )
{
if ( F_21 ( V_2 , V_35 ) )
return 0 ;
F_23 ( & V_2 -> V_29 ) ;
F_419 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
return F_356 ( V_2 ) ;
}
void
F_420 ( struct V_1 * V_2 )
{
int V_23 ;
if ( F_21 ( V_2 , V_35 ) )
return;
V_23 = F_356 ( V_2 ) ;
if ( V_23 )
F_13 ( L_32 , V_23 ) ;
}
static void
F_421 ( struct V_137 * V_138 )
{
F_197 ( & V_138 -> V_253 ) ;
F_197 ( & V_138 -> V_285 ) ;
}
void F_422 ( struct V_15 * V_16 ,
struct V_256 * V_255 )
{
if ( ! F_283 ( V_255 ) )
F_423 ( & V_255 -> V_18 , V_255 -> V_98 , V_255 -> V_47 ) ;
V_255 -> V_2 = V_16 -> V_2 ;
F_197 ( & V_255 -> V_253 ) ;
F_197 ( & V_255 -> V_257 ) ;
F_197 ( & V_255 -> V_500 ) ;
F_219 ( & V_255 -> V_500 , & V_16 -> V_501 ) ;
}
void
F_424 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_58 ;
V_16 -> V_72 =
F_425 ( L_33 ,
sizeof( struct V_6 ) , 0 ,
V_502 ,
NULL ) ;
F_197 ( & V_16 -> V_501 ) ;
F_422 ( V_16 , & V_16 -> V_42 . V_8 ) ;
F_197 ( & V_16 -> V_503 ) ;
F_197 ( & V_16 -> V_18 . V_230 ) ;
F_197 ( & V_16 -> V_18 . V_231 ) ;
F_197 ( & V_16 -> V_18 . V_357 ) ;
for ( V_58 = 0 ; V_58 < V_417 ; V_58 ++ )
F_421 ( & V_16 -> V_138 [ V_58 ] ) ;
for ( V_58 = 0 ; V_58 < V_504 ; V_58 ++ )
F_197 ( & V_16 -> V_313 [ V_58 ] . V_356 ) ;
F_426 ( & V_16 -> V_18 . V_290 ,
F_266 ) ;
F_426 ( & V_16 -> V_18 . V_159 ,
F_269 ) ;
F_427 ( & V_16 -> V_28 . V_24 ) ;
if ( ! F_21 ( V_2 , V_35 ) && F_384 ( V_2 ) ) {
F_290 ( V_505 ,
F_370 ( V_506 ) ) ;
}
V_16 -> V_507 = V_508 ;
if ( ! F_21 ( V_2 , V_35 ) )
V_16 -> V_359 = 3 ;
if ( F_22 ( V_2 ) -> V_41 >= 7 && ! F_408 ( V_2 ) )
V_16 -> V_310 = 32 ;
else if ( F_22 ( V_2 ) -> V_41 >= 4 || F_428 ( V_2 ) || F_429 ( V_2 ) || F_174 ( V_2 ) )
V_16 -> V_310 = 16 ;
else
V_16 -> V_310 = 8 ;
F_197 ( & V_16 -> V_18 . V_357 ) ;
F_259 ( V_2 ) ;
F_430 ( V_2 ) ;
F_427 ( & V_16 -> V_509 ) ;
V_16 -> V_18 . V_134 = true ;
V_16 -> V_18 . V_510 . V_511 = V_512 ;
V_16 -> V_18 . V_510 . V_513 = V_514 ;
V_16 -> V_18 . V_510 . V_515 = V_516 ;
F_431 ( & V_16 -> V_18 . V_510 ) ;
V_16 -> V_18 . V_517 . V_518 = V_519 ;
F_432 ( & V_16 -> V_18 . V_517 ) ;
F_433 ( & V_16 -> V_520 . V_286 ) ;
}
void F_434 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_144 * V_67 = V_33 -> V_178 ;
F_242 ( & V_67 -> V_18 . V_159 ) ;
F_7 ( & V_67 -> V_18 . V_286 ) ;
while ( ! F_198 ( & V_67 -> V_18 . V_285 ) ) {
struct V_265 * V_266 ;
V_266 = F_199 ( & V_67 -> V_18 . V_285 ,
struct V_265 ,
V_287 ) ;
F_196 ( & V_266 -> V_287 ) ;
V_266 -> V_67 = NULL ;
}
F_8 ( & V_67 -> V_18 . V_286 ) ;
}
static void
F_435 ( struct V_317 * V_318 )
{
struct V_144 * V_67 =
F_267 ( V_318 , F_200 ( * V_67 ) , V_18 . V_159 . V_318 ) ;
F_416 ( & V_67 -> V_145 , false ) ;
}
int F_436 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_144 * V_67 ;
int V_23 ;
F_410 ( L_34 ) ;
V_67 = F_437 ( sizeof( * V_67 ) , V_73 ) ;
if ( ! V_67 )
return - V_64 ;
V_33 -> V_178 = V_67 ;
V_67 -> V_16 = V_2 -> V_27 ;
V_67 -> V_33 = V_33 ;
F_438 ( & V_67 -> V_18 . V_286 ) ;
F_197 ( & V_67 -> V_18 . V_285 ) ;
F_426 ( & V_67 -> V_18 . V_159 ,
F_435 ) ;
V_23 = F_439 ( V_2 , V_33 ) ;
if ( V_23 )
F_194 ( V_67 ) ;
return V_23 ;
}
void F_440 ( struct V_6 * V_362 ,
struct V_6 * V_521 ,
unsigned V_429 )
{
if ( V_362 ) {
F_16 ( ! F_121 ( & V_362 -> V_8 . V_2 -> V_29 ) ) ;
F_16 ( ! ( V_362 -> V_429 & V_429 ) ) ;
V_362 -> V_429 &= ~ V_429 ;
}
if ( V_521 ) {
F_16 ( ! F_121 ( & V_521 -> V_8 . V_2 -> V_29 ) ) ;
F_16 ( V_521 -> V_429 & V_429 ) ;
V_521 -> V_429 |= V_429 ;
}
}
static bool F_441 ( struct V_522 * V_522 , struct V_141 * V_523 )
{
if ( ! F_121 ( V_522 ) )
return false ;
#if F_442 ( V_524 ) || F_442 ( V_525 )
return V_522 -> V_526 == V_523 ;
#else
return false ;
#endif
}
static bool F_443 ( struct V_1 * V_2 , bool * V_112 )
{
if ( ! F_268 ( & V_2 -> V_29 ) ) {
if ( ! F_441 ( & V_2 -> V_29 , V_166 ) )
return false ;
if ( F_444 ( V_2 ) -> V_18 . V_211 )
return false ;
* V_112 = false ;
} else
* V_112 = true ;
return true ;
}
static int F_445 ( struct V_6 * V_7 )
{
struct V_232 * V_189 ;
int V_227 = 0 ;
F_27 (vma, &obj->vma_list, vma_link)
if ( F_280 ( & V_189 -> V_329 ) )
V_227 ++ ;
return V_227 ;
}
static unsigned long
V_514 ( struct V_510 * V_510 , struct V_527 * V_528 )
{
struct V_15 * V_16 =
F_267 ( V_510 , struct V_15 , V_18 . V_510 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_6 * V_7 ;
unsigned long V_227 ;
bool V_112 ;
if ( ! F_443 ( V_2 , & V_112 ) )
return 0 ;
V_227 = 0 ;
F_27 (obj, &dev_priv->mm.unbound_list, global_list)
if ( V_7 -> V_222 == 0 )
V_227 += V_7 -> V_8 . V_17 >> V_199 ;
F_27 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_28 ( V_7 ) &&
V_7 -> V_222 == F_445 ( V_7 ) )
V_227 += V_7 -> V_8 . V_17 >> V_199 ;
}
if ( V_112 )
F_25 ( & V_2 -> V_29 ) ;
return V_227 ;
}
unsigned long F_331 ( struct V_6 * V_529 ,
struct V_256 * V_255 )
{
struct V_15 * V_16 = V_529 -> V_8 . V_2 -> V_27 ;
struct V_232 * V_189 ;
F_16 ( V_255 == & V_16 -> V_18 . V_408 -> V_8 ) ;
F_27 (vma, &o->vma_list, vma_link) {
if ( V_189 -> V_255 == V_255 )
return V_189 -> V_329 . V_98 ;
}
F_133 ( 1 , L_35 ,
F_283 ( V_255 ) ? L_36 : L_37 ) ;
return - 1 ;
}
bool F_446 ( struct V_6 * V_529 ,
struct V_256 * V_255 )
{
struct V_232 * V_189 ;
F_27 (vma, &o->vma_list, vma_link)
if ( V_189 -> V_255 == V_255 && F_280 ( & V_189 -> V_329 ) )
return true ;
return false ;
}
bool F_19 ( struct V_6 * V_529 )
{
struct V_232 * V_189 ;
F_27 (vma, &o->vma_list, vma_link)
if ( F_280 ( & V_189 -> V_329 ) )
return true ;
return false ;
}
unsigned long F_447 ( struct V_6 * V_529 ,
struct V_256 * V_255 )
{
struct V_15 * V_16 = V_529 -> V_8 . V_2 -> V_27 ;
struct V_232 * V_189 ;
F_16 ( V_255 == & V_16 -> V_18 . V_408 -> V_8 ) ;
F_120 ( F_198 ( & V_529 -> V_333 ) ) ;
F_27 (vma, &o->vma_list, vma_link)
if ( V_189 -> V_255 == V_255 )
return V_189 -> V_329 . V_17 ;
return 0 ;
}
static unsigned long
V_512 ( struct V_510 * V_510 , struct V_527 * V_528 )
{
struct V_15 * V_16 =
F_267 ( V_510 , struct V_15 , V_18 . V_510 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_530 ;
bool V_112 ;
if ( ! F_443 ( V_2 , & V_112 ) )
return V_531 ;
V_530 = F_178 ( V_16 ,
V_528 -> V_532 ,
V_212 |
V_213 |
V_214 ) ;
if ( V_530 < V_528 -> V_532 )
V_530 += F_178 ( V_16 ,
V_528 -> V_532 - V_530 ,
V_212 |
V_213 ) ;
if ( V_112 )
F_25 ( & V_2 -> V_29 ) ;
return V_530 ;
}
static int
V_519 ( struct V_533 * V_534 , unsigned long V_535 , void * V_536 )
{
struct V_15 * V_16 =
F_267 ( V_534 , struct V_15 , V_18 . V_517 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_6 * V_7 ;
unsigned long V_147 = F_139 ( 5000 ) + 1 ;
unsigned long V_45 , V_537 , V_538 , V_530 ;
bool V_428 ;
bool V_112 ;
while ( ! F_443 ( V_2 , & V_112 ) && -- V_147 ) {
F_448 ( 1 ) ;
if ( F_449 ( V_166 ) )
return V_539 ;
}
if ( V_147 == 0 ) {
F_450 ( L_38 ) ;
return V_539 ;
}
V_428 = V_16 -> V_18 . V_134 ;
V_16 -> V_18 . V_134 = false ;
V_530 = F_179 ( V_16 ) ;
V_16 -> V_18 . V_134 = V_428 ;
V_538 = V_537 = V_45 = 0 ;
F_27 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( ! V_7 -> V_8 . V_55 )
continue;
if ( V_7 -> V_222 )
V_45 += V_7 -> V_8 . V_17 ;
else
V_538 += V_7 -> V_8 . V_17 ;
}
F_27 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! V_7 -> V_8 . V_55 )
continue;
if ( V_7 -> V_222 )
V_45 += V_7 -> V_8 . V_17 ;
else
V_537 += V_7 -> V_8 . V_17 ;
}
if ( V_112 )
F_25 ( & V_2 -> V_29 ) ;
F_451 ( L_39 ,
V_530 , V_45 ) ;
if ( V_538 || V_537 )
F_450 ( L_40
L_41 ,
V_537 , V_538 ) ;
* ( unsigned long * ) V_536 += V_530 ;
return V_539 ;
}
struct V_232 * F_319 ( struct V_6 * V_7 )
{
struct V_232 * V_189 ;
V_189 = F_199 ( & V_7 -> V_333 , F_200 ( * V_189 ) , V_328 ) ;
if ( V_189 -> V_255 != F_452 ( V_7 ) )
return NULL ;
return V_189 ;
}

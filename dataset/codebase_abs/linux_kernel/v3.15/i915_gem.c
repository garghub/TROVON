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
}
V_23 = F_72 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_73 ( V_7 ) ;
return V_23 ;
}
static int
F_74 ( struct V_59 * V_59 , int V_93 , int V_94 ,
char T_3 * V_69 ,
bool V_95 , bool V_90 )
{
char * V_57 ;
int V_23 ;
if ( F_75 ( V_95 ) )
return - V_40 ;
V_57 = F_34 ( V_59 ) ;
if ( V_90 )
F_35 ( V_57 + V_93 ,
V_94 ) ;
V_23 = F_76 ( V_69 ,
V_57 + V_93 ,
V_94 ) ;
F_36 ( V_57 ) ;
return V_23 ? - V_63 : 0 ;
}
static void
F_77 ( char * V_96 , unsigned long V_85 ,
bool V_97 )
{
if ( F_75 ( V_97 ) ) {
unsigned long V_98 = ( unsigned long ) V_96 ;
unsigned long V_99 = ( unsigned long ) V_96 + V_85 ;
V_98 = F_78 ( V_98 , 128 ) ;
V_99 = F_79 ( V_99 , 128 ) ;
F_35 ( ( void * ) V_98 , V_99 - V_98 ) ;
} else {
F_35 ( V_96 , V_85 ) ;
}
}
static int
F_80 ( struct V_59 * V_59 , int V_93 , int V_94 ,
char T_3 * V_69 ,
bool V_95 , bool V_90 )
{
char * V_57 ;
int V_23 ;
V_57 = F_81 ( V_59 ) ;
if ( V_90 )
F_77 ( V_57 + V_93 ,
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
F_82 ( V_59 ) ;
return V_23 ? - V_63 : 0 ;
}
static int
F_83 ( struct V_1 * V_2 ,
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
V_102 = F_84 ( V_7 ) ;
V_23 = F_70 ( V_7 , & V_90 ) ;
if ( V_23 )
return V_23 ;
V_68 = args -> V_68 ;
F_85 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_59 * V_59 = F_86 ( & V_105 ) ;
if ( V_101 <= 0 )
break;
V_93 = F_87 ( V_68 ) ;
V_94 = V_101 ;
if ( ( V_93 + V_94 ) > V_39 )
V_94 = V_39 - V_93 ;
V_95 = V_102 &&
( F_88 ( V_59 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_74 ( V_59 , V_93 , V_94 ,
V_69 , V_95 ,
V_90 ) ;
if ( V_23 == 0 )
goto V_106;
F_25 ( & V_2 -> V_29 ) ;
if ( F_89 ( ! V_107 . V_108 ) && ! V_103 ) {
V_23 = F_90 ( V_69 , V_101 ) ;
( void ) V_23 ;
V_103 = 1 ;
}
V_23 = F_80 ( V_59 , V_93 , V_94 ,
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
F_91 ( V_7 ) ;
return V_23 ;
}
int
F_92 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_100 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_93 ( V_110 ,
F_49 ( args -> V_70 ) ,
args -> V_17 ) )
return - V_63 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_94 ( F_95 ( V_2 , V_33 , args -> V_75 ) ) ;
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
F_96 ( V_7 , args -> V_68 , args -> V_17 ) ;
V_23 = F_83 ( V_2 , V_7 , args , V_33 ) ;
V_109:
F_97 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static inline int
F_98 ( struct V_113 * V_54 ,
T_8 V_114 , int V_115 ,
char T_3 * V_69 ,
int V_85 )
{
void T_9 * V_116 ;
void * V_57 ;
unsigned long V_71 ;
V_116 = F_99 ( V_54 , V_114 ) ;
V_57 = ( void V_117 * ) V_116 + V_115 ;
V_71 = F_50 ( V_57 ,
V_69 , V_85 ) ;
F_100 ( V_116 ) ;
return V_71 ;
}
static int
F_101 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_66 * args ,
struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_7 V_101 ;
T_8 V_68 , V_114 ;
char T_3 * V_69 ;
int V_115 , V_94 , V_23 ;
V_23 = F_102 ( V_7 , 0 , V_118 | V_119 ) ;
if ( V_23 )
goto V_109;
V_23 = F_103 ( V_7 , true ) ;
if ( V_23 )
goto V_120;
V_23 = F_104 ( V_7 ) ;
if ( V_23 )
goto V_120;
V_69 = F_49 ( args -> V_70 ) ;
V_101 = args -> V_17 ;
V_68 = F_105 ( V_7 ) + args -> V_68 ;
while ( V_101 > 0 ) {
V_114 = V_68 & V_121 ;
V_115 = F_87 ( V_68 ) ;
V_94 = V_101 ;
if ( ( V_115 + V_101 ) > V_39 )
V_94 = V_39 - V_115 ;
if ( F_98 ( V_16 -> V_42 . V_122 , V_114 ,
V_115 , V_69 , V_94 ) ) {
V_23 = - V_63 ;
goto V_120;
}
V_101 -= V_94 ;
V_69 += V_94 ;
V_68 += V_94 ;
}
V_120:
F_106 ( V_7 ) ;
V_109:
return V_23 ;
}
static int
F_107 ( struct V_59 * V_59 , int V_93 , int V_94 ,
char T_3 * V_69 ,
bool V_95 ,
bool V_123 ,
bool V_124 )
{
char * V_57 ;
int V_23 ;
if ( F_75 ( V_95 ) )
return - V_40 ;
V_57 = F_34 ( V_59 ) ;
if ( V_123 )
F_35 ( V_57 + V_93 ,
V_94 ) ;
V_23 = F_108 ( V_57 + V_93 ,
V_69 , V_94 ) ;
if ( V_124 )
F_35 ( V_57 + V_93 ,
V_94 ) ;
F_36 ( V_57 ) ;
return V_23 ? - V_63 : 0 ;
}
static int
F_109 ( struct V_59 * V_59 , int V_93 , int V_94 ,
char T_3 * V_69 ,
bool V_95 ,
bool V_123 ,
bool V_124 )
{
char * V_57 ;
int V_23 ;
V_57 = F_81 ( V_59 ) ;
if ( F_75 ( V_123 || V_95 ) )
F_77 ( V_57 + V_93 ,
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
F_77 ( V_57 + V_93 ,
V_94 ,
V_95 ) ;
F_82 ( V_59 ) ;
return V_23 ? - V_63 : 0 ;
}
static int
F_110 ( struct V_1 * V_2 ,
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
V_102 = F_84 ( V_7 ) ;
if ( V_7 -> V_8 . V_126 != V_92 ) {
V_124 = F_3 ( V_7 ) ;
V_23 = F_71 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
}
if ( ( V_7 -> V_8 . V_91 & V_92 ) == 0 )
V_123 =
! F_1 ( V_2 , V_7 -> V_9 ) ;
V_23 = F_72 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_73 ( V_7 ) ;
V_68 = args -> V_68 ;
V_7 -> V_127 = 1 ;
F_85 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_59 * V_59 = F_86 ( & V_105 ) ;
int V_128 ;
if ( V_101 <= 0 )
break;
V_93 = F_87 ( V_68 ) ;
V_94 = V_101 ;
if ( ( V_93 + V_94 ) > V_39 )
V_94 = V_39 - V_93 ;
V_128 = V_123 &&
( ( V_93 | V_94 )
& ( V_129 . V_130 - 1 ) ) ;
V_95 = V_102 &&
( F_88 ( V_59 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_107 ( V_59 , V_93 , V_94 ,
V_69 , V_95 ,
V_128 ,
V_124 ) ;
if ( V_23 == 0 )
goto V_106;
V_125 = 1 ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_109 ( V_59 , V_93 , V_94 ,
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
F_91 ( V_7 ) ;
if ( V_125 ) {
if ( ! V_124 &&
V_7 -> V_8 . V_126 != V_92 ) {
if ( F_111 ( V_7 , V_7 -> V_10 ) )
F_40 ( V_2 ) ;
}
}
if ( V_124 )
F_40 ( V_2 ) ;
return V_23 ;
}
int
F_112 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_66 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_93 ( V_131 ,
F_49 ( args -> V_70 ) ,
args -> V_17 ) )
return - V_63 ;
if ( F_89 ( ! V_107 . V_108 ) ) {
V_23 = F_113 ( F_49 ( args -> V_70 ) ,
args -> V_17 ) ;
if ( V_23 )
return - V_63 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_94 ( F_95 ( V_2 , V_33 , args -> V_75 ) ) ;
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
F_114 ( V_7 , args -> V_68 , args -> V_17 ) ;
V_23 = - V_63 ;
if ( V_7 -> V_50 ) {
V_23 = F_48 ( V_7 , args , V_33 ) ;
goto V_109;
}
if ( V_7 -> V_11 == V_132 &&
V_7 -> V_8 . V_126 != V_92 &&
F_3 ( V_7 ) ) {
V_23 = F_101 ( V_2 , V_7 , args , V_33 ) ;
}
if ( V_23 == - V_63 || V_23 == - V_133 )
V_23 = F_110 ( V_2 , V_7 , args , V_33 ) ;
V_109:
F_97 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_115 ( struct V_22 * error ,
bool V_134 )
{
if ( F_116 ( error ) ) {
if ( ! V_134 )
return - V_26 ;
if ( F_117 ( error ) )
return - V_26 ;
return - V_135 ;
}
return 0 ;
}
static int
F_118 ( struct V_136 * V_137 , T_6 V_138 )
{
int V_23 ;
F_119 ( ! F_120 ( & V_137 -> V_2 -> V_29 ) ) ;
V_23 = 0 ;
if ( V_138 == V_137 -> V_139 )
V_23 = F_121 ( V_137 , NULL ) ;
return V_23 ;
}
static void F_122 ( unsigned long V_31 )
{
F_123 ( (struct V_140 * ) V_31 ) ;
}
static bool F_124 ( struct V_15 * V_16 ,
struct V_136 * V_137 )
{
return F_125 ( V_137 -> V_141 , & V_16 -> V_28 . V_142 ) ;
}
static bool F_126 ( struct V_143 * V_67 )
{
if ( V_67 == NULL )
return true ;
return ! F_127 ( & V_67 -> V_144 , true ) ;
}
static int F_128 ( struct V_136 * V_137 , T_6 V_138 ,
unsigned V_145 ,
bool V_134 ,
struct V_146 * V_147 ,
struct V_143 * V_67 )
{
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
const bool V_148 =
F_129 ( V_16 -> V_28 . V_149 ) & F_130 ( V_137 ) ;
struct V_146 V_150 , V_151 ;
F_131 ( V_152 ) ;
unsigned long V_153 ;
int V_23 ;
F_132 ( V_16 -> V_154 . V_155 , L_2 ) ;
if ( F_133 ( V_137 -> V_156 ( V_137 , true ) , V_138 ) )
return 0 ;
V_153 = V_147 ? V_157 + F_134 ( V_147 ) : 0 ;
if ( F_22 ( V_2 ) -> V_41 >= 6 && F_126 ( V_67 ) ) {
F_135 ( V_16 ) ;
if ( V_67 )
F_136 ( V_16 -> V_158 ,
& V_67 -> V_18 . V_159 ,
F_137 ( 100 ) ) ;
}
if ( ! V_148 && F_16 ( ! V_137 -> V_160 ( V_137 ) ) )
return - V_36 ;
F_138 ( V_137 , V_138 ) ;
F_139 ( & V_150 ) ;
for (; ; ) {
struct V_161 V_162 ;
F_140 ( & V_137 -> V_163 , & V_152 ,
V_134 ? V_164 : V_165 ) ;
if ( V_145 != F_141 ( & V_16 -> V_28 . V_145 ) ) {
V_23 = F_115 ( & V_16 -> V_28 , V_134 ) ;
if ( V_23 == 0 )
V_23 = - V_135 ;
break;
}
if ( F_133 ( V_137 -> V_156 ( V_137 , false ) , V_138 ) ) {
V_23 = 0 ;
break;
}
if ( V_134 && F_142 ( V_166 ) ) {
V_23 = - V_167 ;
break;
}
if ( V_147 && F_143 ( V_157 , V_153 ) ) {
V_23 = - V_168 ;
break;
}
V_162 . V_169 = NULL ;
if ( V_147 || F_124 ( V_16 , V_137 ) ) {
unsigned long V_170 ;
F_144 ( & V_162 , F_122 , ( unsigned long ) V_166 ) ;
V_170 = F_124 ( V_16 , V_137 ) ? V_157 + 1 : V_153 ;
F_145 ( & V_162 , V_170 ) ;
}
F_146 () ;
if ( V_162 . V_169 ) {
F_147 ( & V_162 ) ;
F_148 ( & V_162 ) ;
}
}
F_139 ( & V_151 ) ;
F_149 ( V_137 , V_138 ) ;
if ( ! V_148 )
V_137 -> V_171 ( V_137 ) ;
F_150 ( & V_137 -> V_163 , & V_152 ) ;
if ( V_147 ) {
struct V_146 V_172 = F_151 ( V_151 , V_150 ) ;
* V_147 = F_151 ( * V_147 , V_172 ) ;
if ( ! F_152 ( V_147 ) )
F_153 ( V_147 , 0 , 0 ) ;
}
return V_23 ;
}
int
F_154 ( struct V_136 * V_137 , T_5 V_138 )
{
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_134 = V_16 -> V_18 . V_134 ;
int V_23 ;
F_119 ( ! F_120 ( & V_2 -> V_29 ) ) ;
F_119 ( V_138 == 0 ) ;
V_23 = F_115 ( & V_16 -> V_28 , V_134 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_118 ( V_137 , V_138 ) ;
if ( V_23 )
return V_23 ;
return F_128 ( V_137 , V_138 ,
F_141 ( & V_16 -> V_28 . V_145 ) ,
V_134 , NULL , NULL ) ;
}
static int
F_155 ( struct V_6 * V_7 ,
struct V_136 * V_137 )
{
F_156 ( V_137 ) ;
V_7 -> V_173 = 0 ;
V_7 -> V_8 . V_126 &= ~ V_174 ;
return 0 ;
}
static T_10 int
F_71 ( struct V_6 * V_7 ,
bool V_175 )
{
struct V_136 * V_137 = V_7 -> V_137 ;
T_6 V_138 ;
int V_23 ;
V_138 = V_175 ? V_7 -> V_173 : V_7 -> V_176 ;
if ( V_138 == 0 )
return 0 ;
V_23 = F_154 ( V_137 , V_138 ) ;
if ( V_23 )
return V_23 ;
return F_155 ( V_7 , V_137 ) ;
}
static T_10 int
F_157 ( struct V_6 * V_7 ,
struct V_143 * V_67 ,
bool V_175 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 = V_7 -> V_137 ;
unsigned V_145 ;
T_6 V_138 ;
int V_23 ;
F_119 ( ! F_120 ( & V_2 -> V_29 ) ) ;
F_119 ( ! V_16 -> V_18 . V_134 ) ;
V_138 = V_175 ? V_7 -> V_173 : V_7 -> V_176 ;
if ( V_138 == 0 )
return 0 ;
V_23 = F_115 ( & V_16 -> V_28 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = F_118 ( V_137 , V_138 ) ;
if ( V_23 )
return V_23 ;
V_145 = F_141 ( & V_16 -> V_28 . V_145 ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_128 ( V_137 , V_138 , V_145 , true , NULL , V_67 ) ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_23 )
return V_23 ;
return F_155 ( V_7 , V_137 ) ;
}
int
F_158 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_177 * args = V_31 ;
struct V_6 * V_7 ;
T_5 V_91 = args -> V_91 ;
T_5 V_126 = args -> V_126 ;
int V_23 ;
if ( V_126 & V_174 )
return - V_40 ;
if ( V_91 & V_174 )
return - V_40 ;
if ( V_126 != 0 && V_91 != V_126 )
return - V_40 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_94 ( F_95 ( V_2 , V_33 , args -> V_75 ) ) ;
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
V_23 = F_103 ( V_7 , V_126 != 0 ) ;
if ( V_23 == - V_40 )
V_23 = 0 ;
} else {
V_23 = F_159 ( V_7 , V_126 != 0 ) ;
}
V_179:
F_97 ( & V_7 -> V_8 ) ;
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
V_7 = F_94 ( F_95 ( V_2 , V_33 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
if ( V_7 -> V_10 )
F_161 ( V_7 , true ) ;
F_97 ( & V_7 -> V_8 ) ;
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
V_7 = F_95 ( V_2 , V_33 , args -> V_75 ) ;
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
struct V_6 * V_7 = F_94 ( V_189 -> V_192 ) ;
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
V_23 = - V_40 ;
goto V_112;
}
V_23 = F_102 ( V_7 , 0 , V_118 ) ;
if ( V_23 )
goto V_112;
V_23 = F_103 ( V_7 , V_194 ) ;
if ( V_23 )
goto V_200;
V_23 = F_167 ( V_7 ) ;
if ( V_23 )
goto V_200;
V_7 -> V_201 = true ;
V_193 = V_16 -> V_42 . V_202 + F_105 ( V_7 ) ;
V_193 >>= V_199 ;
V_193 += V_115 ;
V_23 = F_168 ( V_189 , ( unsigned long ) V_191 -> V_197 , V_193 ) ;
V_200:
F_106 ( V_7 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
V_109:
switch ( V_23 ) {
case - V_26 :
if ( F_117 ( & V_16 -> V_28 ) ) {
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
void F_171 ( struct V_15 * V_16 )
{
struct V_207 * V_189 ;
F_16 ( ! F_172 ( & V_16 -> V_42 . V_8 . V_208 ) ) ;
F_27 (vma, &dev_priv->gtt.base.active_list, mm_list)
F_5 ( V_189 -> V_7 ) ;
F_27 (vma, &dev_priv->gtt.base.inactive_list, mm_list)
F_5 ( V_189 -> V_7 ) ;
}
void
F_5 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_201 )
return;
F_173 ( & V_7 -> V_8 . V_209 ,
V_7 -> V_8 . V_2 -> V_210 -> V_56 ) ;
V_7 -> V_201 = false ;
}
T_5
F_174 ( struct V_1 * V_2 , T_5 V_17 , int V_11 )
{
T_5 V_211 ;
if ( F_22 ( V_2 ) -> V_41 >= 4 ||
V_11 == V_132 )
return V_17 ;
if ( F_22 ( V_2 ) -> V_41 == 3 )
V_211 = 1024 * 1024 ;
else
V_211 = 512 * 1024 ;
while ( V_211 < V_17 )
V_211 <<= 1 ;
return V_211 ;
}
T_5
F_175 ( struct V_1 * V_2 , T_5 V_17 ,
int V_11 , bool V_212 )
{
if ( F_22 ( V_2 ) -> V_41 >= 4 || ( ! V_212 && F_176 ( V_2 ) ) ||
V_11 == V_132 )
return 4096 ;
return F_174 ( V_2 , V_17 , V_11 ) ;
}
static int F_177 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_178 ( & V_7 -> V_8 . V_209 ) )
return 0 ;
V_16 -> V_18 . V_213 = true ;
V_23 = F_179 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_133 )
goto V_109;
F_180 ( V_16 , V_7 -> V_8 . V_17 >> V_199 ) ;
V_23 = F_179 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_133 )
goto V_109;
F_181 ( V_16 ) ;
V_23 = F_179 ( & V_7 -> V_8 ) ;
V_109:
V_16 -> V_18 . V_213 = false ;
return V_23 ;
}
static void F_182 ( struct V_6 * V_7 )
{
F_183 ( & V_7 -> V_8 ) ;
}
int
F_184 ( struct V_32 * V_33 ,
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
V_7 = F_94 ( F_95 ( V_2 , V_33 , V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
if ( V_7 -> V_8 . V_17 > V_16 -> V_42 . V_43 ) {
V_23 = - V_214 ;
goto V_109;
}
if ( V_7 -> V_51 != V_52 ) {
F_185 ( L_4 ) ;
V_23 = - V_63 ;
goto V_109;
}
V_23 = F_177 ( V_7 ) ;
if ( V_23 )
goto V_109;
* V_68 = F_186 ( & V_7 -> V_8 . V_209 ) ;
V_109:
F_97 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_187 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_215 * args = V_31 ;
return F_184 ( V_33 , V_2 , args -> V_75 , & args -> V_68 ) ;
}
static void
F_188 ( struct V_6 * V_7 )
{
struct V_216 * V_216 ;
F_182 ( V_7 ) ;
if ( V_7 -> V_8 . V_55 == NULL )
return;
V_216 = F_31 ( V_7 -> V_8 . V_55 ) ;
F_189 ( V_216 , 0 , ( T_8 ) - 1 ) ;
V_7 -> V_51 = V_217 ;
}
static inline int
F_190 ( struct V_6 * V_7 )
{
return V_7 -> V_51 == V_218 ;
}
static void
F_191 ( struct V_6 * V_7 )
{
struct V_104 V_105 ;
int V_23 ;
F_119 ( V_7 -> V_51 == V_217 ) ;
V_23 = F_159 ( V_7 , true ) ;
if ( V_23 ) {
F_16 ( V_23 != - V_26 ) ;
F_111 ( V_7 , true ) ;
V_7 -> V_8 . V_91 = V_7 -> V_8 . V_126 = V_92 ;
}
if ( F_84 ( V_7 ) )
F_192 ( V_7 ) ;
if ( V_7 -> V_51 == V_218 )
V_7 -> V_127 = 0 ;
F_85 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_59 * V_59 = F_86 ( & V_105 ) ;
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
F_119 ( F_19 ( V_7 ) ) ;
F_196 ( & V_7 -> V_223 ) ;
V_221 -> V_224 ( V_7 ) ;
V_7 -> V_219 = NULL ;
if ( F_190 ( V_7 ) )
F_188 ( V_7 ) ;
return 0 ;
}
static unsigned long
F_197 ( struct V_15 * V_16 , long V_225 ,
bool V_226 )
{
struct V_227 V_228 ;
struct V_6 * V_7 , * V_229 ;
unsigned long V_230 = 0 ;
F_198 (obj, next,
&dev_priv->mm.unbound_list,
global_list) {
if ( ( F_190 ( V_7 ) || ! V_226 ) &&
F_195 ( V_7 ) == 0 ) {
V_230 += V_7 -> V_8 . V_17 >> V_199 ;
if ( V_230 >= V_225 )
return V_230 ;
}
}
F_199 ( & V_228 ) ;
while ( V_230 < V_225 && ! F_172 ( & V_16 -> V_18 . V_231 ) ) {
struct V_207 * V_189 , * V_232 ;
V_7 = F_200 ( & V_16 -> V_18 . V_231 ,
F_201 ( * V_7 ) , V_223 ) ;
F_202 ( & V_7 -> V_223 , & V_228 ) ;
if ( ! F_190 ( V_7 ) && V_226 )
continue;
F_203 ( & V_7 -> V_8 ) ;
F_198 (vma, v, &obj->vma_list, vma_link)
if ( F_204 ( V_189 ) )
break;
if ( F_195 ( V_7 ) == 0 )
V_230 += V_7 -> V_8 . V_17 >> V_199 ;
F_97 ( & V_7 -> V_8 ) ;
}
F_205 ( & V_228 , & V_16 -> V_18 . V_231 ) ;
return V_230 ;
}
static unsigned long
F_180 ( struct V_15 * V_16 , long V_225 )
{
return F_197 ( V_16 , V_225 , true ) ;
}
static unsigned long
F_181 ( struct V_15 * V_16 )
{
struct V_6 * V_7 , * V_229 ;
long V_233 = 0 ;
F_206 ( V_16 -> V_2 ) ;
F_198 (obj, next, &dev_priv->mm.unbound_list,
global_list) {
if ( F_195 ( V_7 ) == 0 )
V_233 += V_7 -> V_8 . V_17 >> V_199 ;
}
return V_233 ;
}
static int
F_207 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_234 , V_58 ;
struct V_53 * V_54 ;
struct V_235 * V_236 ;
struct V_237 * V_238 ;
struct V_104 V_105 ;
struct V_59 * V_59 ;
unsigned long V_239 = 0 ;
T_12 V_240 ;
F_119 ( V_7 -> V_8 . V_91 & V_174 ) ;
F_119 ( V_7 -> V_8 . V_126 & V_174 ) ;
V_236 = F_208 ( sizeof( * V_236 ) , V_73 ) ;
if ( V_236 == NULL )
return - V_64 ;
V_234 = V_7 -> V_8 . V_17 / V_39 ;
if ( F_209 ( V_236 , V_234 , V_73 ) ) {
F_194 ( V_236 ) ;
return - V_64 ;
}
V_54 = F_31 ( V_7 -> V_8 . V_55 ) -> V_56 ;
V_240 = F_210 ( V_54 ) ;
V_240 |= V_241 | V_242 | V_243 ;
V_240 &= ~ ( V_244 | V_245 ) ;
V_238 = V_236 -> V_246 ;
V_236 -> V_247 = 0 ;
for ( V_58 = 0 ; V_58 < V_234 ; V_58 ++ ) {
V_59 = F_211 ( V_54 , V_58 , V_240 ) ;
if ( F_33 ( V_59 ) ) {
F_180 ( V_16 , V_234 ) ;
V_59 = F_211 ( V_54 , V_58 , V_240 ) ;
}
if ( F_33 ( V_59 ) ) {
V_240 &= ~ ( V_241 | V_242 | V_243 ) ;
V_240 |= V_244 | V_245 ;
F_181 ( V_16 ) ;
V_59 = F_211 ( V_54 , V_58 , V_240 ) ;
if ( F_33 ( V_59 ) )
goto V_248;
V_240 |= V_241 | V_242 | V_243 ;
V_240 &= ~ ( V_244 | V_245 ) ;
}
#ifdef F_212
if ( F_213 () ) {
V_236 -> V_247 ++ ;
F_214 ( V_238 , V_59 , V_39 , 0 ) ;
V_238 = F_215 ( V_238 ) ;
continue;
}
#endif
if ( ! V_58 || F_216 ( V_59 ) != V_239 + 1 ) {
if ( V_58 )
V_238 = F_215 ( V_238 ) ;
V_236 -> V_247 ++ ;
F_214 ( V_238 , V_59 , V_39 , 0 ) ;
} else {
V_238 -> V_85 += V_39 ;
}
V_239 = F_216 ( V_59 ) ;
F_16 ( ( V_240 & V_249 ) && ( V_239 >= 0x00100000UL ) ) ;
}
#ifdef F_212
if ( ! F_213 () )
#endif
F_217 ( V_238 ) ;
V_7 -> V_219 = V_236 ;
if ( F_84 ( V_7 ) )
F_218 ( V_7 ) ;
return 0 ;
V_248:
F_217 ( V_238 ) ;
F_85 (st->sgl, &sg_iter, st->nents, 0 )
F_39 ( F_86 ( & V_105 ) ) ;
F_193 ( V_236 ) ;
F_194 ( V_236 ) ;
return F_47 ( V_59 ) ;
}
int
F_72 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
const struct V_220 * V_221 = V_7 -> V_221 ;
int V_23 ;
if ( V_7 -> V_219 )
return 0 ;
if ( V_7 -> V_51 != V_52 ) {
F_185 ( L_5 ) ;
return - V_63 ;
}
F_119 ( V_7 -> V_222 ) ;
V_23 = V_221 -> V_250 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_219 ( & V_7 -> V_223 , & V_16 -> V_18 . V_251 ) ;
return 0 ;
}
static void
F_220 ( struct V_6 * V_7 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_138 = F_221 ( V_137 ) ;
F_119 ( V_137 == NULL ) ;
if ( V_7 -> V_137 != V_137 && V_7 -> V_173 ) {
V_7 -> V_173 = V_138 ;
}
V_7 -> V_137 = V_137 ;
if ( ! V_7 -> V_30 ) {
F_203 ( & V_7 -> V_8 ) ;
V_7 -> V_30 = 1 ;
}
F_202 ( & V_7 -> V_252 , & V_137 -> V_208 ) ;
V_7 -> V_176 = V_138 ;
if ( V_7 -> V_253 ) {
V_7 -> V_254 = V_138 ;
if ( V_7 -> V_13 != V_14 ) {
struct V_255 * V_256 ;
V_256 = & V_16 -> V_257 [ V_7 -> V_13 ] ;
F_202 ( & V_256 -> V_258 ,
& V_16 -> V_18 . V_259 ) ;
}
}
}
void F_222 ( struct V_207 * V_189 ,
struct V_136 * V_137 )
{
F_202 ( & V_189 -> V_260 , & V_189 -> V_261 -> V_208 ) ;
return F_220 ( V_189 -> V_7 , V_137 ) ;
}
static void
F_223 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_262 * V_261 ;
struct V_207 * V_189 ;
F_119 ( V_7 -> V_8 . V_126 & ~ V_174 ) ;
F_119 ( ! V_7 -> V_30 ) ;
F_27 (vm, &dev_priv->vm_list, global_link) {
V_189 = F_224 ( V_7 , V_261 ) ;
if ( V_189 && ! F_172 ( & V_189 -> V_260 ) )
F_202 ( & V_189 -> V_260 , & V_261 -> V_263 ) ;
}
F_225 ( & V_7 -> V_252 ) ;
V_7 -> V_137 = NULL ;
V_7 -> V_176 = 0 ;
V_7 -> V_173 = 0 ;
V_7 -> V_8 . V_126 = 0 ;
V_7 -> V_254 = 0 ;
V_7 -> V_253 = false ;
V_7 -> V_30 = 0 ;
F_97 ( & V_7 -> V_8 ) ;
F_16 ( F_17 ( V_2 ) ) ;
}
static int
F_226 ( struct V_1 * V_2 , T_6 V_138 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
int V_23 , V_58 , V_264 ;
F_227 (ring, dev_priv, i) {
V_23 = F_228 ( V_137 ) ;
if ( V_23 )
return V_23 ;
}
F_229 ( V_2 ) ;
F_227 (ring, dev_priv, i) {
F_230 ( V_137 , V_138 ) ;
for ( V_264 = 0 ; V_264 < F_231 ( V_137 -> V_265 ) ; V_264 ++ )
V_137 -> V_265 [ V_264 ] = 0 ;
}
return 0 ;
}
int F_232 ( struct V_1 * V_2 , T_6 V_138 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( V_138 == 0 )
return - V_40 ;
V_23 = F_226 ( V_2 , V_138 - 1 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_266 = V_138 ;
V_16 -> V_267 = V_138 - 1 ;
if ( V_16 -> V_267 == 0 )
V_16 -> V_267 -- ;
return 0 ;
}
int
F_233 ( struct V_1 * V_2 , T_6 * V_138 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( V_16 -> V_266 == 0 ) {
int V_23 = F_226 ( V_2 , 0 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_266 = 1 ;
}
* V_138 = V_16 -> V_267 = V_16 -> V_266 ++ ;
return 0 ;
}
int F_234 ( struct V_136 * V_137 ,
struct V_32 * V_33 ,
struct V_6 * V_7 ,
T_6 * V_268 )
{
struct V_15 * V_16 = V_137 -> V_2 -> V_27 ;
struct V_269 * V_270 ;
T_6 V_271 , V_272 ;
int V_23 ;
V_272 = F_235 ( V_137 ) ;
V_23 = F_236 ( V_137 ) ;
if ( V_23 )
return V_23 ;
V_270 = V_137 -> V_273 ;
if ( F_16 ( V_270 == NULL ) )
return - V_64 ;
V_271 = F_235 ( V_137 ) ;
V_23 = V_137 -> V_274 ( V_137 ) ;
if ( V_23 )
return V_23 ;
V_270 -> V_138 = F_221 ( V_137 ) ;
V_270 -> V_137 = V_137 ;
V_270 -> V_275 = V_272 ;
V_270 -> V_276 = V_271 ;
V_270 -> V_277 = V_7 ;
V_270 -> V_278 = V_137 -> V_279 ;
if ( V_270 -> V_278 )
F_237 ( V_270 -> V_278 ) ;
V_270 -> V_280 = V_157 ;
F_219 ( & V_270 -> V_281 , & V_137 -> V_282 ) ;
V_270 -> V_67 = NULL ;
if ( V_33 ) {
struct V_143 * V_67 = V_33 -> V_178 ;
F_7 ( & V_67 -> V_18 . V_283 ) ;
V_270 -> V_67 = V_67 ;
F_219 ( & V_270 -> V_284 ,
& V_67 -> V_18 . V_282 ) ;
F_8 ( & V_67 -> V_18 . V_283 ) ;
}
F_238 ( V_137 , V_270 -> V_138 ) ;
V_137 -> V_139 = 0 ;
V_137 -> V_273 = NULL ;
if ( ! V_16 -> V_285 . V_286 ) {
F_239 ( V_137 -> V_2 ) ;
F_240 ( & V_16 -> V_18 . V_159 ) ;
F_241 ( V_16 -> V_158 ,
& V_16 -> V_18 . V_287 ,
F_242 ( V_25 ) ) ;
F_243 ( V_16 -> V_2 ) ;
}
if ( V_268 )
* V_268 = V_270 -> V_138 ;
return 0 ;
}
static inline void
F_244 ( struct V_269 * V_270 )
{
struct V_143 * V_67 = V_270 -> V_67 ;
if ( ! V_67 )
return;
F_7 ( & V_67 -> V_18 . V_283 ) ;
F_196 ( & V_270 -> V_284 ) ;
V_270 -> V_67 = NULL ;
F_8 ( & V_67 -> V_18 . V_283 ) ;
}
static bool F_245 ( struct V_15 * V_16 ,
const struct V_288 * V_278 )
{
unsigned long V_289 ;
V_289 = F_246 () - V_278 -> V_290 . V_291 ;
if ( V_278 -> V_290 . V_292 )
return true ;
if ( V_289 <= V_293 ) {
if ( ! F_247 ( V_278 ) ) {
F_185 ( L_6 ) ;
return true ;
} else if ( V_16 -> V_28 . V_294 == 0 ) {
F_13 ( L_7 ) ;
return true ;
}
}
return false ;
}
static void F_248 ( struct V_15 * V_16 ,
struct V_288 * V_278 ,
const bool V_295 )
{
struct V_296 * V_297 ;
if ( F_16 ( ! V_278 ) )
return;
V_297 = & V_278 -> V_290 ;
if ( V_295 ) {
V_297 -> V_292 = F_245 ( V_16 , V_278 ) ;
V_297 -> V_298 ++ ;
V_297 -> V_291 = F_246 () ;
} else {
V_297 -> V_299 ++ ;
}
}
static void F_249 ( struct V_269 * V_270 )
{
F_196 ( & V_270 -> V_281 ) ;
F_244 ( V_270 ) ;
if ( V_270 -> V_278 )
F_250 ( V_270 -> V_278 ) ;
F_194 ( V_270 ) ;
}
struct V_269 *
F_251 ( struct V_136 * V_137 )
{
struct V_269 * V_270 ;
T_6 V_300 ;
V_300 = V_137 -> V_156 ( V_137 , false ) ;
F_27 (request, &ring->request_list, list) {
if ( F_133 ( V_300 , V_270 -> V_138 ) )
continue;
return V_270 ;
}
return NULL ;
}
static void F_252 ( struct V_15 * V_16 ,
struct V_136 * V_137 )
{
struct V_269 * V_270 ;
bool V_301 ;
V_270 = F_251 ( V_137 ) ;
if ( V_270 == NULL )
return;
V_301 = V_137 -> V_302 . V_303 >= V_304 ;
F_248 ( V_16 , V_270 -> V_278 , V_301 ) ;
F_253 (request, &ring->request_list, list)
F_248 ( V_16 , V_270 -> V_278 , false ) ;
}
static void F_254 ( struct V_15 * V_16 ,
struct V_136 * V_137 )
{
while ( ! F_172 ( & V_137 -> V_208 ) ) {
struct V_6 * V_7 ;
V_7 = F_200 ( & V_137 -> V_208 ,
struct V_6 ,
V_252 ) ;
F_223 ( V_7 ) ;
}
while ( ! F_172 ( & V_137 -> V_282 ) ) {
struct V_269 * V_270 ;
V_270 = F_200 ( & V_137 -> V_282 ,
struct V_269 ,
V_281 ) ;
F_249 ( V_270 ) ;
}
}
void F_255 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_16 -> V_305 ; V_58 ++ ) {
struct V_255 * V_256 = & V_16 -> V_257 [ V_58 ] ;
if ( V_256 -> V_7 ) {
F_256 ( V_256 -> V_7 , V_256 ,
V_256 -> V_7 -> V_11 ) ;
} else {
F_257 ( V_2 , V_58 , NULL ) ;
}
}
}
void F_258 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
int V_58 ;
F_227 (ring, dev_priv, i)
F_252 ( V_16 , V_137 ) ;
F_227 (ring, dev_priv, i)
F_254 ( V_16 , V_137 ) ;
F_259 ( V_2 ) ;
F_260 ( V_2 ) ;
F_255 ( V_2 ) ;
}
static void
F_156 ( struct V_136 * V_137 )
{
T_5 V_138 ;
if ( F_172 ( & V_137 -> V_282 ) )
return;
F_16 ( F_17 ( V_137 -> V_2 ) ) ;
V_138 = V_137 -> V_156 ( V_137 , true ) ;
while ( ! F_172 ( & V_137 -> V_208 ) ) {
struct V_6 * V_7 ;
V_7 = F_200 ( & V_137 -> V_208 ,
struct V_6 ,
V_252 ) ;
if ( ! F_133 ( V_138 , V_7 -> V_176 ) )
break;
F_223 ( V_7 ) ;
}
while ( ! F_172 ( & V_137 -> V_282 ) ) {
struct V_269 * V_270 ;
V_270 = F_200 ( & V_137 -> V_282 ,
struct V_269 ,
V_281 ) ;
if ( ! F_133 ( V_138 , V_270 -> V_138 ) )
break;
F_261 ( V_137 , V_270 -> V_138 ) ;
V_137 -> V_306 = V_270 -> V_276 ;
F_249 ( V_270 ) ;
}
if ( F_75 ( V_137 -> V_307 &&
F_133 ( V_138 , V_137 -> V_307 ) ) ) {
V_137 -> V_171 ( V_137 ) ;
V_137 -> V_307 = 0 ;
}
F_16 ( F_17 ( V_137 -> V_2 ) ) ;
}
bool
F_229 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
bool V_308 = true ;
int V_58 ;
F_227 (ring, dev_priv, i) {
F_156 ( V_137 ) ;
V_308 &= F_172 ( & V_137 -> V_282 ) ;
}
if ( V_308 )
F_136 ( V_16 -> V_158 ,
& V_16 -> V_18 . V_159 ,
F_137 ( 100 ) ) ;
return V_308 ;
}
static void
F_262 ( struct V_309 * V_310 )
{
struct V_15 * V_16 =
F_263 ( V_310 , F_201 ( * V_16 ) , V_18 . V_287 . V_310 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_308 ;
V_308 = false ;
if ( F_264 ( & V_2 -> V_29 ) ) {
V_308 = F_229 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
}
if ( ! V_308 )
F_241 ( V_16 -> V_158 , & V_16 -> V_18 . V_287 ,
F_242 ( V_25 ) ) ;
}
static void
F_265 ( struct V_309 * V_310 )
{
struct V_15 * V_16 =
F_263 ( V_310 , F_201 ( * V_16 ) , V_18 . V_159 . V_310 ) ;
F_266 ( V_16 -> V_2 ) ;
}
static int
F_267 ( struct V_6 * V_7 )
{
int V_23 ;
if ( V_7 -> V_30 ) {
V_23 = F_118 ( V_7 -> V_137 , V_7 -> V_176 ) ;
if ( V_23 )
return V_23 ;
F_156 ( V_7 -> V_137 ) ;
}
return 0 ;
}
int
F_268 ( struct V_1 * V_2 , void * V_31 , struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_311 * args = V_31 ;
struct V_6 * V_7 ;
struct V_136 * V_137 = NULL ;
struct V_146 V_312 , * V_147 = NULL ;
unsigned V_145 ;
T_6 V_138 = 0 ;
int V_23 = 0 ;
if ( args -> V_313 >= 0 ) {
V_312 = F_269 ( args -> V_313 ) ;
V_147 = & V_312 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_94 ( F_95 ( V_2 , V_33 , args -> V_314 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_25 ( & V_2 -> V_29 ) ;
return - V_111 ;
}
V_23 = F_267 ( V_7 ) ;
if ( V_23 )
goto V_109;
if ( V_7 -> V_30 ) {
V_138 = V_7 -> V_176 ;
V_137 = V_7 -> V_137 ;
}
if ( V_138 == 0 )
goto V_109;
if ( ! args -> V_313 ) {
V_23 = - V_168 ;
goto V_109;
}
F_97 ( & V_7 -> V_8 ) ;
V_145 = F_141 ( & V_16 -> V_28 . V_145 ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_128 ( V_137 , V_138 , V_145 , true , V_147 , V_33 -> V_178 ) ;
if ( V_147 )
args -> V_313 = F_270 ( V_147 ) ;
return V_23 ;
V_109:
F_97 ( & V_7 -> V_8 ) ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_271 ( struct V_6 * V_7 ,
struct V_136 * V_315 )
{
struct V_136 * V_316 = V_7 -> V_137 ;
T_6 V_138 ;
int V_23 , V_317 ;
if ( V_316 == NULL || V_315 == V_316 )
return 0 ;
if ( V_315 == NULL || ! F_272 ( V_7 -> V_8 . V_2 ) )
return F_71 ( V_7 , false ) ;
V_317 = F_273 ( V_316 , V_315 ) ;
V_138 = V_7 -> V_176 ;
if ( V_138 <= V_316 -> V_265 [ V_317 ] )
return 0 ;
V_23 = F_118 ( V_7 -> V_137 , V_138 ) ;
if ( V_23 )
return V_23 ;
F_274 ( V_316 , V_315 , V_138 ) ;
V_23 = V_315 -> V_318 ( V_315 , V_316 , V_138 ) ;
if ( ! V_23 )
V_316 -> V_265 [ V_317 ] = V_7 -> V_176 ;
return V_23 ;
}
static void F_275 ( struct V_6 * V_7 )
{
T_6 V_319 , V_320 ;
F_5 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_91 & V_180 ) == 0 )
return;
F_276 () ;
V_320 = V_7 -> V_8 . V_91 ;
V_319 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_91 &= ~ V_180 ;
V_7 -> V_8 . V_126 &= ~ V_180 ;
F_277 ( V_7 ,
V_320 ,
V_319 ) ;
}
int F_204 ( struct V_207 * V_189 )
{
struct V_6 * V_7 = V_189 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_172 ( & V_189 -> V_321 ) )
return 0 ;
if ( ! F_278 ( & V_189 -> V_322 ) ) {
F_279 ( V_189 ) ;
return 0 ;
}
if ( V_189 -> V_323 )
return - V_62 ;
F_119 ( V_7 -> V_219 == NULL ) ;
V_23 = F_280 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_275 ( V_7 ) ;
V_23 = F_104 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_281 ( V_189 ) ;
V_189 -> V_324 ( V_189 ) ;
F_282 ( V_7 ) ;
F_225 ( & V_189 -> V_260 ) ;
if ( F_283 ( V_189 -> V_261 ) )
V_7 -> V_325 = true ;
F_284 ( & V_189 -> V_322 ) ;
F_279 ( V_189 ) ;
if ( F_172 ( & V_7 -> V_326 ) )
F_202 ( & V_7 -> V_223 , & V_16 -> V_18 . V_251 ) ;
F_91 ( V_7 ) ;
return 0 ;
}
int F_285 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
int V_23 , V_58 ;
F_227 (ring, dev_priv, i) {
V_23 = F_286 ( V_137 , V_137 -> V_327 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_228 ( V_137 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static void F_287 ( struct V_1 * V_2 , int V_256 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_13 ;
int V_328 ;
if ( F_22 ( V_2 ) -> V_41 >= 6 ) {
V_13 = V_329 ;
V_328 = V_330 ;
} else {
V_13 = V_331 ;
V_328 = V_332 ;
}
V_13 += V_256 * 8 ;
F_288 ( V_13 , 0 ) ;
F_289 ( V_13 ) ;
if ( V_7 ) {
T_6 V_17 = F_29 ( V_7 ) ;
T_4 V_333 ;
V_333 = ( T_4 ) ( ( F_105 ( V_7 ) + V_17 - 4096 ) &
0xfffff000 ) << 32 ;
V_333 |= F_105 ( V_7 ) & 0xfffff000 ;
V_333 |= ( T_4 ) ( ( V_7 -> V_334 / 128 ) - 1 ) << V_328 ;
if ( V_7 -> V_11 == V_335 )
V_333 |= 1 << V_336 ;
V_333 |= V_337 ;
F_288 ( V_13 + 4 , V_333 >> 32 ) ;
F_289 ( V_13 + 4 ) ;
F_288 ( V_13 + 0 , V_333 ) ;
F_289 ( V_13 ) ;
} else {
F_288 ( V_13 + 4 , 0 ) ;
F_289 ( V_13 + 4 ) ;
}
}
static void F_290 ( struct V_1 * V_2 , int V_256 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_333 ;
if ( V_7 ) {
T_6 V_17 = F_29 ( V_7 ) ;
int V_338 ;
int V_339 ;
F_132 ( ( F_105 ( V_7 ) & ~ V_340 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_105 ( V_7 ) & ( V_17 - 1 ) ) ,
L_8 ,
F_105 ( V_7 ) , V_7 -> V_325 , V_17 ) ;
if ( V_7 -> V_11 == V_335 && F_291 ( V_2 ) )
V_339 = 128 ;
else
V_339 = 512 ;
V_338 = V_7 -> V_334 / V_339 ;
V_338 = F_292 ( V_338 ) - 1 ;
V_333 = F_105 ( V_7 ) ;
if ( V_7 -> V_11 == V_335 )
V_333 |= 1 << V_341 ;
V_333 |= F_293 ( V_17 ) ;
V_333 |= V_338 << V_342 ;
V_333 |= V_343 ;
} else
V_333 = 0 ;
if ( V_256 < 8 )
V_256 = V_344 + V_256 * 4 ;
else
V_256 = V_345 + ( V_256 - 8 ) * 4 ;
F_288 ( V_256 , V_333 ) ;
F_289 ( V_256 ) ;
}
static void F_294 ( struct V_1 * V_2 , int V_256 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
T_5 V_333 ;
if ( V_7 ) {
T_6 V_17 = F_29 ( V_7 ) ;
T_5 V_338 ;
F_132 ( ( F_105 ( V_7 ) & ~ V_346 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_105 ( V_7 ) & ( V_17 - 1 ) ) ,
L_9 ,
F_105 ( V_7 ) , V_17 ) ;
V_338 = V_7 -> V_334 / 128 ;
V_338 = F_292 ( V_338 ) - 1 ;
V_333 = F_105 ( V_7 ) ;
if ( V_7 -> V_11 == V_335 )
V_333 |= 1 << V_341 ;
V_333 |= F_295 ( V_17 ) ;
V_333 |= V_338 << V_342 ;
V_333 |= V_343 ;
} else
V_333 = 0 ;
F_288 ( V_344 + V_256 * 4 , V_333 ) ;
F_289 ( V_344 + V_256 * 4 ) ;
}
inline static bool F_296 ( struct V_6 * V_7 )
{
return V_7 && V_7 -> V_8 . V_91 & V_180 ;
}
static void F_257 ( struct V_1 * V_2 , int V_256 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_296 ( V_16 -> V_257 [ V_256 ] . V_7 ) )
F_276 () ;
F_132 ( V_7 && ( ! V_7 -> V_334 || ! V_7 -> V_11 ) ,
L_10 ,
V_7 -> V_334 , V_7 -> V_11 ) ;
switch ( F_22 ( V_2 ) -> V_41 ) {
case 8 :
case 7 :
case 6 :
case 5 :
case 4 : F_287 ( V_2 , V_256 , V_7 ) ; break;
case 3 : F_290 ( V_2 , V_256 , V_7 ) ; break;
case 2 : F_294 ( V_2 , V_256 , V_7 ) ; break;
default: F_297 () ;
}
if ( F_296 ( V_7 ) )
F_276 () ;
}
static inline int F_298 ( struct V_15 * V_16 ,
struct V_255 * V_347 )
{
return V_347 - V_16 -> V_257 ;
}
static void F_256 ( struct V_6 * V_7 ,
struct V_255 * V_347 ,
bool V_348 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_256 = F_298 ( V_16 , V_347 ) ;
F_257 ( V_7 -> V_8 . V_2 , V_256 , V_348 ? V_7 : NULL ) ;
if ( V_348 ) {
V_7 -> V_13 = V_256 ;
V_347 -> V_7 = V_7 ;
F_202 ( & V_347 -> V_258 , & V_16 -> V_18 . V_259 ) ;
} else {
V_7 -> V_13 = V_14 ;
V_347 -> V_7 = NULL ;
F_225 ( & V_347 -> V_258 ) ;
}
V_7 -> V_12 = false ;
}
static int
F_299 ( struct V_6 * V_7 )
{
if ( V_7 -> V_254 ) {
int V_23 = F_154 ( V_7 -> V_137 , V_7 -> V_254 ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_254 = 0 ;
}
V_7 -> V_253 = false ;
return 0 ;
}
int
F_104 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_255 * V_347 ;
int V_23 ;
V_23 = F_299 ( V_7 ) ;
if ( V_23 )
return V_23 ;
if ( V_7 -> V_13 == V_14 )
return 0 ;
V_347 = & V_16 -> V_257 [ V_7 -> V_13 ] ;
F_4 ( V_7 ) ;
F_256 ( V_7 , V_347 , false ) ;
return 0 ;
}
static struct V_255 *
F_300 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_255 * V_256 , * V_349 ;
int V_58 ;
V_349 = NULL ;
for ( V_58 = V_16 -> V_350 ; V_58 < V_16 -> V_305 ; V_58 ++ ) {
V_256 = & V_16 -> V_257 [ V_58 ] ;
if ( ! V_256 -> V_7 )
return V_256 ;
if ( ! V_256 -> V_323 )
V_349 = V_256 ;
}
if ( V_349 == NULL )
goto V_351;
F_27 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_256 -> V_323 )
continue;
return V_256 ;
}
V_351:
if ( F_301 ( V_2 ) )
return F_302 ( - V_135 ) ;
return F_302 ( - V_352 ) ;
}
int
F_167 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_348 = V_7 -> V_11 != V_132 ;
struct V_255 * V_256 ;
int V_23 ;
if ( V_7 -> V_12 ) {
V_23 = F_299 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_7 -> V_13 != V_14 ) {
V_256 = & V_16 -> V_257 [ V_7 -> V_13 ] ;
if ( ! V_7 -> V_12 ) {
F_202 ( & V_256 -> V_258 ,
& V_16 -> V_18 . V_259 ) ;
return 0 ;
}
} else if ( V_348 ) {
V_256 = F_300 ( V_2 ) ;
if ( F_33 ( V_256 ) )
return F_47 ( V_256 ) ;
if ( V_256 -> V_7 ) {
struct V_6 * V_353 = V_256 -> V_7 ;
V_23 = F_299 ( V_353 ) ;
if ( V_23 )
return V_23 ;
F_4 ( V_353 ) ;
}
} else
return 0 ;
F_256 ( V_7 , V_256 , V_348 ) ;
return 0 ;
}
static bool F_303 ( struct V_1 * V_2 ,
struct V_354 * V_355 ,
unsigned long V_9 )
{
struct V_354 * V_356 ;
if ( F_2 ( V_2 ) )
return true ;
if ( ! F_278 ( V_355 ) )
return true ;
if ( F_172 ( & V_355 -> V_357 ) )
return true ;
V_356 = F_304 ( V_355 -> V_357 . V_358 , struct V_354 , V_357 ) ;
if ( V_356 -> V_359 && ! V_356 -> V_360 && V_356 -> V_361 != V_9 )
return false ;
V_356 = F_304 ( V_355 -> V_357 . V_229 , struct V_354 , V_357 ) ;
if ( V_356 -> V_359 && ! V_355 -> V_360 && V_356 -> V_361 != V_9 )
return false ;
return true ;
}
static void F_305 ( struct V_1 * V_2 )
{
#if V_362
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_6 * V_7 ;
int V_363 = 0 ;
F_27 (obj, &dev_priv->mm.gtt_list, global_list) {
if ( V_7 -> V_355 == NULL ) {
F_306 ( V_364 L_11 ) ;
V_363 ++ ;
continue;
}
if ( V_7 -> V_9 != V_7 -> V_355 -> V_361 ) {
F_306 ( V_364 L_12 ,
F_105 ( V_7 ) ,
F_105 ( V_7 ) + F_29 ( V_7 ) ,
V_7 -> V_9 ,
V_7 -> V_355 -> V_361 ) ;
V_363 ++ ;
continue;
}
if ( ! F_303 ( V_2 ,
V_7 -> V_355 ,
V_7 -> V_9 ) ) {
F_306 ( V_364 L_13 ,
F_105 ( V_7 ) ,
F_105 ( V_7 ) + F_29 ( V_7 ) ,
V_7 -> V_9 ) ;
V_363 ++ ;
continue;
}
}
F_16 ( V_363 ) ;
#endif
}
static struct V_207 *
F_307 ( struct V_6 * V_7 ,
struct V_262 * V_261 ,
unsigned V_365 ,
T_4 V_195 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_17 , V_366 , V_367 , V_368 ;
unsigned long V_98 =
V_195 & V_369 ? V_195 & V_370 : 0 ;
unsigned long V_99 =
V_195 & V_118 ? V_16 -> V_42 . V_43 : V_261 -> V_47 ;
struct V_207 * V_189 ;
int V_23 ;
V_366 = F_174 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ) ;
V_367 = F_175 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , true ) ;
V_368 =
F_175 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , false ) ;
if ( V_365 == 0 )
V_365 = V_195 & V_118 ? V_367 :
V_368 ;
if ( V_195 & V_118 && V_365 & ( V_367 - 1 ) ) {
F_185 ( L_14 , V_365 ) ;
return F_302 ( - V_40 ) ;
}
V_17 = V_195 & V_118 ? V_366 : V_7 -> V_8 . V_17 ;
if ( V_7 -> V_8 . V_17 > V_99 ) {
F_185 ( L_15 ,
V_7 -> V_8 . V_17 ,
V_195 & V_118 ? L_16 : L_17 ,
V_99 ) ;
return F_302 ( - V_214 ) ;
}
V_23 = F_72 ( V_7 ) ;
if ( V_23 )
return F_302 ( V_23 ) ;
F_73 ( V_7 ) ;
V_189 = F_308 ( V_7 , V_261 ) ;
if ( F_33 ( V_189 ) )
goto V_371;
V_372:
V_23 = F_309 ( & V_261 -> V_18 , & V_189 -> V_322 ,
V_17 , V_365 ,
V_7 -> V_9 ,
V_98 , V_99 ,
V_373 ,
V_374 ) ;
if ( V_23 ) {
V_23 = F_310 ( V_2 , V_261 , V_17 , V_365 ,
V_7 -> V_9 ,
V_98 , V_99 ,
V_195 ) ;
if ( V_23 == 0 )
goto V_372;
goto V_375;
}
if ( F_16 ( ! F_303 ( V_2 , & V_189 -> V_322 ,
V_7 -> V_9 ) ) ) {
V_23 = - V_40 ;
goto V_376;
}
V_23 = F_311 ( V_7 ) ;
if ( V_23 )
goto V_376;
F_202 ( & V_7 -> V_223 , & V_16 -> V_18 . V_231 ) ;
F_219 ( & V_189 -> V_260 , & V_261 -> V_263 ) ;
if ( F_283 ( V_261 ) ) {
bool V_122 , V_377 ;
V_377 = ( V_189 -> V_322 . V_17 == V_366 &&
( V_189 -> V_322 . V_98 & ( V_367 - 1 ) ) == 0 ) ;
V_122 = ( V_189 -> V_322 . V_98 + V_7 -> V_8 . V_17 <=
V_16 -> V_42 . V_43 ) ;
V_7 -> V_325 = V_122 && V_377 ;
}
F_16 ( V_195 & V_118 && ! V_7 -> V_325 ) ;
F_312 ( V_189 , V_195 ) ;
V_189 -> V_378 ( V_189 , V_7 -> V_9 ,
V_195 & ( V_118 | V_379 ) ? V_380 : 0 ) ;
F_305 ( V_2 ) ;
return V_189 ;
V_376:
F_284 ( & V_189 -> V_322 ) ;
V_375:
F_279 ( V_189 ) ;
V_189 = F_302 ( V_23 ) ;
V_371:
F_91 ( V_7 ) ;
return V_189 ;
}
bool
F_111 ( struct V_6 * V_7 ,
bool V_381 )
{
if ( V_7 -> V_219 == NULL )
return false ;
if ( V_7 -> V_382 )
return false ;
if ( ! V_381 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) )
return false ;
F_313 ( V_7 ) ;
F_314 ( V_7 -> V_219 ) ;
return true ;
}
static void
F_315 ( struct V_6 * V_7 )
{
T_5 V_319 ;
if ( V_7 -> V_8 . V_126 != V_180 )
return;
F_316 () ;
V_319 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_126 = 0 ;
F_277 ( V_7 ,
V_7 -> V_8 . V_91 ,
V_319 ) ;
}
static void
F_161 ( struct V_6 * V_7 ,
bool V_381 )
{
T_5 V_319 ;
if ( V_7 -> V_8 . V_126 != V_92 )
return;
if ( F_111 ( V_7 , V_381 ) )
F_40 ( V_7 -> V_8 . V_2 ) ;
V_319 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_126 = 0 ;
F_277 ( V_7 ,
V_7 -> V_8 . V_91 ,
V_319 ) ;
}
int
F_103 ( struct V_6 * V_7 , bool V_194 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
T_5 V_319 , V_320 ;
int V_23 ;
if ( ! F_19 ( V_7 ) )
return - V_40 ;
if ( V_7 -> V_8 . V_126 == V_180 )
return 0 ;
V_23 = F_71 ( V_7 , ! V_194 ) ;
if ( V_23 )
return V_23 ;
F_161 ( V_7 , false ) ;
if ( ( V_7 -> V_8 . V_91 & V_180 ) == 0 )
F_276 () ;
V_319 = V_7 -> V_8 . V_126 ;
V_320 = V_7 -> V_8 . V_91 ;
F_119 ( ( V_7 -> V_8 . V_126 & ~ V_180 ) != 0 ) ;
V_7 -> V_8 . V_91 |= V_180 ;
if ( V_194 ) {
V_7 -> V_8 . V_91 = V_180 ;
V_7 -> V_8 . V_126 = V_180 ;
V_7 -> V_127 = 1 ;
}
F_277 ( V_7 ,
V_320 ,
V_319 ) ;
if ( F_18 ( V_7 ) ) {
struct V_207 * V_189 = F_317 ( V_7 ) ;
if ( V_189 )
F_202 ( & V_189 -> V_260 ,
& V_16 -> V_42 . V_8 . V_263 ) ;
}
return 0 ;
}
int F_318 ( struct V_6 * V_7 ,
enum V_3 V_9 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_207 * V_189 , * V_229 ;
int V_23 ;
if ( V_7 -> V_9 == V_9 )
return 0 ;
if ( F_28 ( V_7 ) ) {
F_185 ( L_18 ) ;
return - V_62 ;
}
F_198 (vma, next, &obj->vma_list, vma_link) {
if ( ! F_303 ( V_2 , & V_189 -> V_322 , V_9 ) ) {
V_23 = F_204 ( V_189 ) ;
if ( V_23 )
return V_23 ;
}
}
if ( F_19 ( V_7 ) ) {
V_23 = F_280 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_275 ( V_7 ) ;
if ( F_22 ( V_2 ) -> V_41 < 6 ) {
V_23 = F_104 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
F_27 (vma, &obj->vma_list, vma_link)
if ( F_278 ( & V_189 -> V_322 ) )
V_189 -> V_378 ( V_189 , V_9 ,
V_7 -> V_383 ? V_380 : 0 ) ;
}
F_27 (vma, &obj->vma_list, vma_link)
V_189 -> V_322 . V_361 = V_9 ;
V_7 -> V_9 = V_9 ;
if ( F_3 ( V_7 ) ) {
T_6 V_320 , V_319 ;
F_16 ( V_7 -> V_8 . V_126 & ~ V_92 ) ;
V_320 = V_7 -> V_8 . V_91 ;
V_319 = V_7 -> V_8 . V_126 ;
V_7 -> V_8 . V_91 = V_92 ;
V_7 -> V_8 . V_126 = V_92 ;
F_277 ( V_7 ,
V_320 ,
V_319 ) ;
}
F_305 ( V_2 ) ;
return 0 ;
}
int F_319 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_384 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_94 ( F_95 ( V_2 , V_33 , args -> V_75 ) ) ;
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
F_97 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_320 ( struct V_1 * V_2 , void * V_31 ,
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
V_4 = F_321 ( V_2 ) ? V_389 : V_5 ;
break;
default:
return - V_40 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_94 ( F_95 ( V_2 , V_33 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
V_23 = F_318 ( V_7 , V_4 ) ;
F_97 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static bool F_322 ( struct V_6 * V_7 )
{
return F_317 ( V_7 ) -> V_323 - ! ! V_7 -> V_392 ;
}
int
F_323 ( struct V_6 * V_7 ,
T_6 V_365 ,
struct V_136 * V_393 )
{
T_6 V_320 , V_319 ;
int V_23 ;
if ( V_393 != V_7 -> V_137 ) {
V_23 = F_271 ( V_7 , V_393 ) ;
if ( V_23 )
return V_23 ;
}
V_7 -> V_10 = true ;
V_23 = F_318 ( V_7 ,
F_321 ( V_7 -> V_8 . V_2 ) ? V_389 : V_5 ) ;
if ( V_23 )
goto V_394;
V_23 = F_102 ( V_7 , V_365 , V_118 ) ;
if ( V_23 )
goto V_394;
F_161 ( V_7 , true ) ;
V_319 = V_7 -> V_8 . V_126 ;
V_320 = V_7 -> V_8 . V_91 ;
V_7 -> V_8 . V_126 = 0 ;
V_7 -> V_8 . V_91 |= V_180 ;
F_277 ( V_7 ,
V_320 ,
V_319 ) ;
return 0 ;
V_394:
V_7 -> V_10 = F_322 ( V_7 ) ;
return V_23 ;
}
void
F_324 ( struct V_6 * V_7 )
{
F_106 ( V_7 ) ;
V_7 -> V_10 = F_322 ( V_7 ) ;
}
int
F_280 ( struct V_6 * V_7 )
{
int V_23 ;
if ( ( V_7 -> V_8 . V_91 & V_174 ) == 0 )
return 0 ;
V_23 = F_71 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_8 . V_91 &= ~ V_174 ;
return 0 ;
}
int
F_159 ( struct V_6 * V_7 , bool V_194 )
{
T_5 V_319 , V_320 ;
int V_23 ;
if ( V_7 -> V_8 . V_126 == V_92 )
return 0 ;
V_23 = F_71 ( V_7 , ! V_194 ) ;
if ( V_23 )
return V_23 ;
F_315 ( V_7 ) ;
V_319 = V_7 -> V_8 . V_126 ;
V_320 = V_7 -> V_8 . V_91 ;
if ( ( V_7 -> V_8 . V_91 & V_92 ) == 0 ) {
F_111 ( V_7 , false ) ;
V_7 -> V_8 . V_91 |= V_92 ;
}
F_119 ( ( V_7 -> V_8 . V_126 & ~ V_92 ) != 0 ) ;
if ( V_194 ) {
V_7 -> V_8 . V_91 = V_92 ;
V_7 -> V_8 . V_126 = V_92 ;
}
F_277 ( V_7 ,
V_320 ,
V_319 ) ;
return 0 ;
}
static int
F_325 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_143 * V_67 = V_33 -> V_178 ;
unsigned long V_395 = V_157 - F_137 ( 20 ) ;
struct V_269 * V_270 ;
struct V_136 * V_137 = NULL ;
unsigned V_145 ;
T_6 V_138 = 0 ;
int V_23 ;
V_23 = F_10 ( & V_16 -> V_28 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_115 ( & V_16 -> V_28 , false ) ;
if ( V_23 )
return V_23 ;
F_7 ( & V_67 -> V_18 . V_283 ) ;
F_27 (request, &file_priv->mm.request_list, client_list) {
if ( F_143 ( V_270 -> V_280 , V_395 ) )
break;
V_137 = V_270 -> V_137 ;
V_138 = V_270 -> V_138 ;
}
V_145 = F_141 ( & V_16 -> V_28 . V_145 ) ;
F_8 ( & V_67 -> V_18 . V_283 ) ;
if ( V_138 == 0 )
return 0 ;
V_23 = F_128 ( V_137 , V_138 , V_145 , true , NULL , NULL ) ;
if ( V_23 == 0 )
F_241 ( V_16 -> V_158 , & V_16 -> V_18 . V_287 , 0 ) ;
return V_23 ;
}
static bool
F_326 ( struct V_207 * V_189 , T_5 V_365 , T_4 V_195 )
{
struct V_6 * V_7 = V_189 -> V_7 ;
if ( V_365 &&
V_189 -> V_322 . V_98 & ( V_365 - 1 ) )
return true ;
if ( V_195 & V_118 && ! V_7 -> V_325 )
return true ;
if ( V_195 & V_369 &&
V_189 -> V_322 . V_98 < ( V_195 & V_370 ) )
return true ;
return false ;
}
int
F_327 ( struct V_6 * V_7 ,
struct V_262 * V_261 ,
T_5 V_365 ,
T_4 V_195 )
{
struct V_207 * V_189 ;
int V_23 ;
if ( F_16 ( V_195 & ( V_379 | V_118 ) && ! F_283 ( V_261 ) ) )
return - V_40 ;
V_189 = F_224 ( V_7 , V_261 ) ;
if ( V_189 ) {
if ( F_16 ( V_189 -> V_323 == V_396 ) )
return - V_62 ;
if ( F_326 ( V_189 , V_365 , V_195 ) ) {
F_132 ( V_189 -> V_323 ,
L_19
L_20
L_21 ,
F_328 ( V_7 , V_261 ) , V_365 ,
! ! ( V_195 & V_118 ) ,
V_7 -> V_325 ) ;
V_23 = F_204 ( V_189 ) ;
if ( V_23 )
return V_23 ;
V_189 = NULL ;
}
}
if ( V_189 == NULL || ! F_278 ( & V_189 -> V_322 ) ) {
V_189 = F_307 ( V_7 , V_261 , V_365 , V_195 ) ;
if ( F_33 ( V_189 ) )
return F_47 ( V_189 ) ;
}
if ( V_195 & V_379 && ! V_7 -> V_383 )
V_189 -> V_378 ( V_189 , V_7 -> V_9 , V_380 ) ;
V_189 -> V_323 ++ ;
if ( V_195 & V_118 )
V_7 -> V_397 |= true ;
return 0 ;
}
void
F_106 ( struct V_6 * V_7 )
{
struct V_207 * V_189 = F_317 ( V_7 ) ;
F_119 ( ! V_189 ) ;
F_119 ( V_189 -> V_323 == 0 ) ;
F_119 ( ! F_329 ( V_7 ) ) ;
if ( -- V_189 -> V_323 == 0 )
V_7 -> V_397 = false ;
}
int
F_330 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_398 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
if ( F_22 ( V_2 ) -> V_41 >= 6 )
return - V_36 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_94 ( F_95 ( V_2 , V_33 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
if ( V_7 -> V_51 != V_52 ) {
F_185 ( L_22 ) ;
V_23 = - V_63 ;
goto V_109;
}
if ( V_7 -> V_399 != NULL && V_7 -> V_399 != V_33 ) {
F_185 ( L_23 ,
args -> V_75 ) ;
V_23 = - V_40 ;
goto V_109;
}
if ( V_7 -> V_392 == V_400 ) {
V_23 = - V_62 ;
goto V_109;
}
if ( V_7 -> V_392 == 0 ) {
V_23 = F_102 ( V_7 , args -> V_365 , V_118 ) ;
if ( V_23 )
goto V_109;
}
V_7 -> V_392 ++ ;
V_7 -> V_399 = V_33 ;
args -> V_68 = F_105 ( V_7 ) ;
V_109:
F_97 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_331 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_398 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_94 ( F_95 ( V_2 , V_33 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
if ( V_7 -> V_399 != V_33 ) {
F_185 ( L_24 ,
args -> V_75 ) ;
V_23 = - V_40 ;
goto V_109;
}
V_7 -> V_392 -- ;
if ( V_7 -> V_392 == 0 ) {
V_7 -> V_399 = NULL ;
F_106 ( V_7 ) ;
}
V_109:
F_97 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_332 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_401 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_94 ( F_95 ( V_2 , V_33 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
V_23 = F_267 ( V_7 ) ;
args -> V_402 = V_7 -> V_30 ;
if ( V_7 -> V_137 ) {
F_333 ( V_403 > 16 ) ;
args -> V_402 |= F_130 ( V_7 -> V_137 ) << 16 ;
}
F_97 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_334 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_67 )
{
return F_325 ( V_2 , V_67 ) ;
}
int
F_335 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_67 )
{
struct V_404 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
switch ( args -> V_51 ) {
case V_218 :
case V_52 :
break;
default:
return - V_40 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_94 ( F_95 ( V_2 , V_67 , args -> V_75 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_111 ;
goto V_112;
}
if ( F_28 ( V_7 ) ) {
V_23 = - V_40 ;
goto V_109;
}
if ( V_7 -> V_51 != V_217 )
V_7 -> V_51 = args -> V_51 ;
if ( F_190 ( V_7 ) && V_7 -> V_219 == NULL )
F_188 ( V_7 ) ;
args -> V_405 = V_7 -> V_51 != V_217 ;
V_109:
F_97 ( & V_7 -> V_8 ) ;
V_112:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void F_336 ( struct V_6 * V_7 ,
const struct V_220 * V_221 )
{
F_199 ( & V_7 -> V_223 ) ;
F_199 ( & V_7 -> V_252 ) ;
F_199 ( & V_7 -> V_406 ) ;
F_199 ( & V_7 -> V_326 ) ;
V_7 -> V_221 = V_221 ;
V_7 -> V_13 = V_14 ;
V_7 -> V_51 = V_52 ;
V_7 -> V_325 = true ;
F_6 ( V_7 -> V_8 . V_2 -> V_27 , V_7 -> V_8 . V_17 ) ;
}
struct V_6 * F_58 ( struct V_1 * V_2 ,
T_1 V_17 )
{
struct V_6 * V_7 ;
struct V_53 * V_54 ;
T_12 V_407 ;
V_7 = F_52 ( V_2 ) ;
if ( V_7 == NULL )
return NULL ;
if ( F_337 ( V_2 , & V_7 -> V_8 , V_17 ) != 0 ) {
F_54 ( V_7 ) ;
return NULL ;
}
V_407 = V_408 | V_409 ;
if ( F_338 ( V_2 ) || F_339 ( V_2 ) ) {
V_407 &= ~ V_410 ;
V_407 |= V_249 ;
}
V_54 = F_31 ( V_7 -> V_8 . V_55 ) -> V_56 ;
F_340 ( V_54 , V_407 ) ;
F_336 ( V_7 , & V_411 ) ;
V_7 -> V_8 . V_126 = V_92 ;
V_7 -> V_8 . V_91 = V_92 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_9 = V_385 ;
} else
V_7 -> V_9 = V_5 ;
F_341 ( V_7 ) ;
return V_7 ;
}
void F_342 ( struct V_183 * V_412 )
{
struct V_6 * V_7 = F_94 ( V_412 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_207 * V_189 , * V_229 ;
F_165 ( V_16 ) ;
F_343 ( V_7 ) ;
F_198 (vma, next, &obj->vma_list, vma_link) {
int V_23 ;
V_189 -> V_323 = 0 ;
V_23 = F_204 ( V_189 ) ;
if ( F_16 ( V_23 == - V_167 ) ) {
bool V_413 ;
V_413 = V_16 -> V_18 . V_134 ;
V_16 -> V_18 . V_134 = false ;
F_16 ( F_204 ( V_189 ) ) ;
V_16 -> V_18 . V_134 = V_413 ;
}
}
F_30 ( V_7 ) ;
if ( V_7 -> V_382 )
F_91 ( V_7 ) ;
if ( F_16 ( V_7 -> V_222 ) )
V_7 -> V_222 = 0 ;
F_195 ( V_7 ) ;
F_182 ( V_7 ) ;
F_344 ( V_7 ) ;
F_119 ( V_7 -> V_219 ) ;
if ( V_7 -> V_8 . V_414 )
F_345 ( & V_7 -> V_8 , NULL ) ;
F_346 ( & V_7 -> V_8 ) ;
F_9 ( V_16 , V_7 -> V_8 . V_17 ) ;
F_194 ( V_7 -> V_415 ) ;
F_54 ( V_7 ) ;
F_170 ( V_16 ) ;
}
struct V_207 * F_224 ( struct V_6 * V_7 ,
struct V_262 * V_261 )
{
struct V_207 * V_189 ;
F_27 (vma, &obj->vma_list, vma_link)
if ( V_189 -> V_261 == V_261 )
return V_189 ;
return NULL ;
}
void F_279 ( struct V_207 * V_189 )
{
F_16 ( V_189 -> V_322 . V_359 ) ;
if ( ! F_172 ( & V_189 -> V_416 ) )
return;
F_196 ( & V_189 -> V_321 ) ;
F_194 ( V_189 ) ;
}
int
F_347 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 = 0 ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_16 -> V_285 . V_286 )
goto V_363;
V_23 = F_285 ( V_2 ) ;
if ( V_23 )
goto V_363;
F_229 ( V_2 ) ;
if ( ! F_21 ( V_2 , V_35 ) )
F_206 ( V_2 ) ;
F_348 ( V_2 ) ;
F_259 ( V_2 ) ;
V_16 -> V_285 . V_286 = ! F_21 ( V_2 ,
V_35 ) ;
F_25 ( & V_2 -> V_29 ) ;
F_349 ( & V_16 -> V_28 . V_417 ) ;
F_240 ( & V_16 -> V_18 . V_287 ) ;
F_240 ( & V_16 -> V_18 . V_159 ) ;
return 0 ;
V_363:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_350 ( struct V_136 * V_137 , int V_418 )
{
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_6 V_419 = V_420 + ( V_418 * 0x200 ) ;
T_6 * V_421 = V_16 -> V_422 . V_421 [ V_418 ] ;
int V_58 , V_23 ;
if ( ! F_351 ( V_2 ) || ! V_421 )
return 0 ;
V_23 = F_352 ( V_137 , V_423 / 4 * 3 ) ;
if ( V_23 )
return V_23 ;
for ( V_58 = 0 ; V_58 < V_423 ; V_58 += 4 ) {
F_353 ( V_137 , F_354 ( 1 ) ) ;
F_353 ( V_137 , V_419 + V_58 ) ;
F_353 ( V_137 , V_421 [ V_58 / 4 ] ) ;
}
F_355 ( V_137 ) ;
return V_23 ;
}
void F_356 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_22 ( V_2 ) -> V_41 < 5 ||
V_16 -> V_18 . V_424 == V_425 )
return;
F_288 ( V_426 , F_357 ( V_426 ) |
V_427 ) ;
if ( F_358 ( V_2 ) )
return;
F_288 ( V_428 , F_357 ( V_428 ) | V_429 ) ;
if ( F_359 ( V_2 ) )
F_288 ( V_430 , F_360 ( V_431 ) ) ;
else if ( F_361 ( V_2 ) )
F_288 ( V_430 , F_360 ( V_432 ) ) ;
else if ( F_362 ( V_2 ) )
F_288 ( V_433 , F_360 ( V_434 ) ) ;
else
F_297 () ;
}
static bool
F_363 ( struct V_1 * V_2 )
{
if ( ! F_364 ( V_2 ) )
return false ;
if ( F_359 ( V_2 ) && V_2 -> V_435 -> V_436 < 8 ) {
F_365 ( L_25
L_26 ) ;
return false ;
}
return true ;
}
static int F_366 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
V_23 = F_367 ( V_2 ) ;
if ( V_23 )
return V_23 ;
if ( F_368 ( V_2 ) ) {
V_23 = F_369 ( V_2 ) ;
if ( V_23 )
goto V_437;
}
if ( F_363 ( V_2 ) ) {
V_23 = F_370 ( V_2 ) ;
if ( V_23 )
goto V_438;
}
if ( F_371 ( V_2 ) ) {
V_23 = F_372 ( V_2 ) ;
if ( V_23 )
goto V_439;
}
V_23 = F_232 ( V_2 , ( ( T_6 ) ~ 0 - 0x1000 ) ) ;
if ( V_23 )
goto V_440;
return 0 ;
V_440:
F_373 ( & V_16 -> V_137 [ V_441 ] ) ;
V_439:
F_373 ( & V_16 -> V_137 [ V_442 ] ) ;
V_438:
F_373 ( & V_16 -> V_137 [ V_443 ] ) ;
V_437:
F_373 ( & V_16 -> V_137 [ V_444 ] ) ;
return V_23 ;
}
int
F_374 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 , V_58 ;
if ( F_22 ( V_2 ) -> V_41 < 6 && ! F_375 () )
return - V_26 ;
if ( V_16 -> V_445 )
F_288 ( V_446 , F_357 ( V_446 ) | F_376 ( 0xf ) ) ;
if ( F_377 ( V_2 ) )
F_288 ( V_447 , F_378 ( V_2 ) ?
V_448 : V_449 ) ;
if ( F_379 ( V_2 ) ) {
if ( F_380 ( V_2 ) ) {
T_6 V_450 = F_357 ( V_451 ) ;
V_450 &= ~ ( V_452 | V_453 ) ;
F_288 ( V_451 , V_450 ) ;
} else if ( F_22 ( V_2 ) -> V_41 >= 7 ) {
T_6 V_450 = F_357 ( V_454 ) ;
V_450 &= ~ V_455 ;
F_288 ( V_454 , V_450 ) ;
}
}
F_356 ( V_2 ) ;
V_23 = F_366 ( V_2 ) ;
if ( V_23 )
return V_23 ;
for ( V_58 = 0 ; V_58 < F_381 ( V_2 ) ; V_58 ++ )
F_350 ( & V_16 -> V_137 [ V_444 ] , V_58 ) ;
V_23 = F_382 ( V_16 ) ;
if ( V_23 ) {
F_13 ( L_27 , V_23 ) ;
goto V_456;
}
return 0 ;
V_456:
F_259 ( V_2 ) ;
return V_23 ;
}
int F_383 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
F_23 ( & V_2 -> V_29 ) ;
if ( F_384 ( V_2 ) ) {
F_288 ( V_457 , 1 ) ;
if ( F_385 ( ( F_357 ( V_458 ) & 1 ) == 1 , 10 ) )
F_386 ( L_28 ) ;
}
F_387 ( V_2 ) ;
V_23 = F_388 ( V_2 ) ;
if ( V_23 ) {
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
V_23 = F_374 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
if ( V_23 ) {
F_16 ( V_16 -> V_18 . V_459 ) ;
F_389 ( V_2 ) ;
F_390 ( & V_16 -> V_42 . V_8 . V_18 ) ;
return V_23 ;
}
if ( ! F_21 ( V_2 , V_35 ) )
V_16 -> V_460 . V_461 = 1 ;
return 0 ;
}
void
F_259 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_136 * V_137 ;
int V_58 ;
F_227 (ring, dev_priv, i)
F_373 ( V_137 ) ;
}
int
F_391 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_67 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( F_21 ( V_2 , V_35 ) )
return 0 ;
if ( F_116 ( & V_16 -> V_28 ) ) {
F_13 ( L_29 ) ;
F_392 ( & V_16 -> V_28 . V_145 , 0 ) ;
}
F_23 ( & V_2 -> V_29 ) ;
V_16 -> V_285 . V_286 = 0 ;
V_23 = F_374 ( V_2 ) ;
if ( V_23 != 0 ) {
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
F_119 ( ! F_172 ( & V_16 -> V_42 . V_8 . V_208 ) ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_393 ( V_2 ) ;
if ( V_23 )
goto V_462;
return 0 ;
V_462:
F_23 ( & V_2 -> V_29 ) ;
F_259 ( V_2 ) ;
V_16 -> V_285 . V_286 = 1 ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_394 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_67 )
{
if ( F_21 ( V_2 , V_35 ) )
return 0 ;
F_395 ( V_2 ) ;
return F_347 ( V_2 ) ;
}
void
F_396 ( struct V_1 * V_2 )
{
int V_23 ;
if ( F_21 ( V_2 , V_35 ) )
return;
V_23 = F_347 ( V_2 ) ;
if ( V_23 )
F_13 ( L_30 , V_23 ) ;
}
static void
F_397 ( struct V_136 * V_137 )
{
F_199 ( & V_137 -> V_208 ) ;
F_199 ( & V_137 -> V_282 ) ;
}
void F_398 ( struct V_15 * V_16 ,
struct V_262 * V_261 )
{
if ( ! F_283 ( V_261 ) )
F_399 ( & V_261 -> V_18 , V_261 -> V_98 , V_261 -> V_47 ) ;
V_261 -> V_2 = V_16 -> V_2 ;
F_199 ( & V_261 -> V_208 ) ;
F_199 ( & V_261 -> V_263 ) ;
F_199 ( & V_261 -> V_463 ) ;
F_219 ( & V_261 -> V_463 , & V_16 -> V_464 ) ;
}
void
F_400 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_58 ;
V_16 -> V_72 =
F_401 ( L_31 ,
sizeof( struct V_6 ) , 0 ,
V_465 ,
NULL ) ;
F_199 ( & V_16 -> V_464 ) ;
F_398 ( V_16 , & V_16 -> V_42 . V_8 ) ;
F_199 ( & V_16 -> V_466 ) ;
F_199 ( & V_16 -> V_18 . V_251 ) ;
F_199 ( & V_16 -> V_18 . V_231 ) ;
F_199 ( & V_16 -> V_18 . V_259 ) ;
for ( V_58 = 0 ; V_58 < V_403 ; V_58 ++ )
F_397 ( & V_16 -> V_137 [ V_58 ] ) ;
for ( V_58 = 0 ; V_58 < V_467 ; V_58 ++ )
F_199 ( & V_16 -> V_257 [ V_58 ] . V_258 ) ;
F_402 ( & V_16 -> V_18 . V_287 ,
F_262 ) ;
F_402 ( & V_16 -> V_18 . V_159 ,
F_265 ) ;
F_403 ( & V_16 -> V_28 . V_24 ) ;
if ( F_404 ( V_2 ) ) {
F_288 ( V_468 ,
F_360 ( V_469 ) ) ;
}
V_16 -> V_470 = V_471 ;
if ( ! F_21 ( V_2 , V_35 ) )
V_16 -> V_350 = 3 ;
if ( F_22 ( V_2 ) -> V_41 >= 7 && ! F_384 ( V_2 ) )
V_16 -> V_305 = 32 ;
else if ( F_22 ( V_2 ) -> V_41 >= 4 || F_405 ( V_2 ) || F_406 ( V_2 ) || F_176 ( V_2 ) )
V_16 -> V_305 = 16 ;
else
V_16 -> V_305 = 8 ;
F_199 ( & V_16 -> V_18 . V_259 ) ;
F_255 ( V_2 ) ;
F_407 ( V_2 ) ;
F_403 ( & V_16 -> V_472 ) ;
V_16 -> V_18 . V_134 = true ;
V_16 -> V_18 . V_473 . V_474 = V_475 ;
V_16 -> V_18 . V_473 . V_476 = V_477 ;
V_16 -> V_18 . V_473 . V_478 = V_479 ;
F_408 ( & V_16 -> V_18 . V_473 ) ;
}
void F_409 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_143 * V_67 = V_33 -> V_178 ;
F_240 ( & V_67 -> V_18 . V_159 ) ;
F_7 ( & V_67 -> V_18 . V_283 ) ;
while ( ! F_172 ( & V_67 -> V_18 . V_282 ) ) {
struct V_269 * V_270 ;
V_270 = F_200 ( & V_67 -> V_18 . V_282 ,
struct V_269 ,
V_284 ) ;
F_196 ( & V_270 -> V_284 ) ;
V_270 -> V_67 = NULL ;
}
F_8 ( & V_67 -> V_18 . V_283 ) ;
}
static void
F_410 ( struct V_309 * V_310 )
{
struct V_143 * V_67 =
F_263 ( V_310 , F_201 ( * V_67 ) , V_18 . V_159 . V_310 ) ;
F_392 ( & V_67 -> V_144 , false ) ;
}
int F_411 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_143 * V_67 ;
int V_23 ;
F_386 ( L_32 ) ;
V_67 = F_412 ( sizeof( * V_67 ) , V_73 ) ;
if ( ! V_67 )
return - V_64 ;
V_33 -> V_178 = V_67 ;
V_67 -> V_16 = V_2 -> V_27 ;
V_67 -> V_33 = V_33 ;
F_413 ( & V_67 -> V_18 . V_283 ) ;
F_199 ( & V_67 -> V_18 . V_282 ) ;
F_402 ( & V_67 -> V_18 . V_159 ,
F_410 ) ;
V_23 = F_414 ( V_2 , V_33 ) ;
if ( V_23 )
F_194 ( V_67 ) ;
return V_23 ;
}
static bool F_415 ( struct V_480 * V_480 , struct V_140 * V_481 )
{
if ( ! F_120 ( V_480 ) )
return false ;
#if F_416 ( V_482 ) || F_416 ( V_483 )
return V_480 -> V_484 == V_481 ;
#else
return false ;
#endif
}
static unsigned long
V_477 ( struct V_485 * V_485 , struct V_486 * V_487 )
{
struct V_15 * V_16 =
F_263 ( V_485 ,
struct V_15 ,
V_18 . V_473 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_6 * V_7 ;
bool V_112 = true ;
unsigned long V_230 ;
if ( ! F_264 ( & V_2 -> V_29 ) ) {
if ( ! F_415 ( & V_2 -> V_29 , V_166 ) )
return 0 ;
if ( V_16 -> V_18 . V_213 )
return 0 ;
V_112 = false ;
}
V_230 = 0 ;
F_27 (obj, &dev_priv->mm.unbound_list, global_list)
if ( V_7 -> V_222 == 0 )
V_230 += V_7 -> V_8 . V_17 >> V_199 ;
F_27 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_7 -> V_30 )
continue;
if ( ! F_28 ( V_7 ) && V_7 -> V_222 == 0 )
V_230 += V_7 -> V_8 . V_17 >> V_199 ;
}
if ( V_112 )
F_25 ( & V_2 -> V_29 ) ;
return V_230 ;
}
unsigned long F_328 ( struct V_6 * V_488 ,
struct V_262 * V_261 )
{
struct V_15 * V_16 = V_488 -> V_8 . V_2 -> V_27 ;
struct V_207 * V_189 ;
if ( ! V_16 -> V_18 . V_459 ||
V_261 == & V_16 -> V_18 . V_459 -> V_8 )
V_261 = & V_16 -> V_42 . V_8 ;
F_119 ( F_172 ( & V_488 -> V_326 ) ) ;
F_27 (vma, &o->vma_list, vma_link) {
if ( V_189 -> V_261 == V_261 )
return V_189 -> V_322 . V_98 ;
}
return - 1 ;
}
bool F_417 ( struct V_6 * V_488 ,
struct V_262 * V_261 )
{
struct V_207 * V_189 ;
F_27 (vma, &o->vma_list, vma_link)
if ( V_189 -> V_261 == V_261 && F_278 ( & V_189 -> V_322 ) )
return true ;
return false ;
}
bool F_19 ( struct V_6 * V_488 )
{
struct V_207 * V_189 ;
F_27 (vma, &o->vma_list, vma_link)
if ( F_278 ( & V_189 -> V_322 ) )
return true ;
return false ;
}
unsigned long F_418 ( struct V_6 * V_488 ,
struct V_262 * V_261 )
{
struct V_15 * V_16 = V_488 -> V_8 . V_2 -> V_27 ;
struct V_207 * V_189 ;
if ( ! V_16 -> V_18 . V_459 ||
V_261 == & V_16 -> V_18 . V_459 -> V_8 )
V_261 = & V_16 -> V_42 . V_8 ;
F_119 ( F_172 ( & V_488 -> V_326 ) ) ;
F_27 (vma, &o->vma_list, vma_link)
if ( V_189 -> V_261 == V_261 )
return V_189 -> V_322 . V_17 ;
return 0 ;
}
static unsigned long
V_475 ( struct V_485 * V_485 , struct V_486 * V_487 )
{
struct V_15 * V_16 =
F_263 ( V_485 ,
struct V_15 ,
V_18 . V_473 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_233 ;
bool V_112 = true ;
if ( ! F_264 ( & V_2 -> V_29 ) ) {
if ( ! F_415 ( & V_2 -> V_29 , V_166 ) )
return V_489 ;
if ( V_16 -> V_18 . V_213 )
return V_489 ;
V_112 = false ;
}
V_233 = F_180 ( V_16 , V_487 -> V_490 ) ;
if ( V_233 < V_487 -> V_490 )
V_233 += F_197 ( V_16 ,
V_487 -> V_490 - V_233 ,
false ) ;
if ( V_233 < V_487 -> V_490 )
V_233 += F_181 ( V_16 ) ;
if ( V_112 )
F_25 ( & V_2 -> V_29 ) ;
return V_233 ;
}
struct V_207 * F_317 ( struct V_6 * V_7 )
{
struct V_207 * V_189 ;
if ( F_16 ( F_172 ( & V_7 -> V_326 ) ) )
return NULL ;
V_189 = F_200 ( & V_7 -> V_326 , F_201 ( * V_189 ) , V_321 ) ;
if ( V_189 -> V_261 != F_419 ( V_7 ) )
return NULL ;
return V_189 ;
}

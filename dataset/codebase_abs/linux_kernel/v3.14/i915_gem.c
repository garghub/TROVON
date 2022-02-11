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
if ( V_7 -> V_46 )
V_45 += F_28 ( V_7 ) ;
F_25 ( & V_2 -> V_29 ) ;
args -> V_47 = V_16 -> V_42 . V_8 . V_48 ;
args -> V_49 = args -> V_47 - V_45 ;
return 0 ;
}
void * F_29 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
return F_30 ( V_16 -> V_50 , V_51 ) ;
}
void F_31 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
F_32 ( V_16 -> V_50 , V_7 ) ;
}
static int
F_33 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_2 V_17 ,
T_3 * V_52 )
{
struct V_6 * V_7 ;
int V_23 ;
T_4 V_53 ;
V_17 = F_34 ( V_17 , V_39 ) ;
if ( V_17 == 0 )
return - V_40 ;
V_7 = F_35 ( V_2 , V_17 ) ;
if ( V_7 == NULL )
return - V_54 ;
V_23 = F_36 ( V_33 , & V_7 -> V_8 , & V_53 ) ;
F_37 ( & V_7 -> V_8 ) ;
if ( V_23 )
return V_23 ;
* V_52 = V_53 ;
return 0 ;
}
int
F_38 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
struct V_55 * args )
{
args -> V_56 = F_39 ( args -> V_57 * F_40 ( args -> V_58 , 8 ) , 64 ) ;
args -> V_17 = args -> V_56 * args -> V_59 ;
return F_33 ( V_33 , V_2 ,
args -> V_17 , & args -> V_53 ) ;
}
int
F_41 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_60 * args = V_31 ;
return F_33 ( V_33 , V_2 ,
args -> V_17 , & args -> V_53 ) ;
}
static inline int
F_42 ( char T_5 * V_61 ,
const char * V_62 , int V_63 ,
int V_64 )
{
int V_23 , V_65 = 0 ;
while ( V_64 > 0 ) {
int V_66 = F_39 ( V_63 + 1 , 64 ) ;
int V_67 = F_43 ( V_66 - V_63 , V_64 ) ;
int V_68 = V_63 ^ 64 ;
V_23 = F_44 ( V_61 + V_65 ,
V_62 + V_68 ,
V_67 ) ;
if ( V_23 )
return V_23 + V_64 ;
V_65 += V_67 ;
V_63 += V_67 ;
V_64 -= V_67 ;
}
return 0 ;
}
static inline int
F_45 ( char * V_62 , int V_63 ,
const char T_5 * V_61 ,
int V_64 )
{
int V_23 , V_65 = 0 ;
while ( V_64 > 0 ) {
int V_66 = F_39 ( V_63 + 1 , 64 ) ;
int V_67 = F_43 ( V_66 - V_63 , V_64 ) ;
int V_68 = V_63 ^ 64 ;
V_23 = F_46 ( V_62 + V_68 ,
V_61 + V_65 ,
V_67 ) ;
if ( V_23 )
return V_23 + V_64 ;
V_65 += V_67 ;
V_63 += V_67 ;
V_64 -= V_67 ;
}
return 0 ;
}
static int
F_47 ( struct V_69 * V_69 , int V_70 , int V_71 ,
char T_5 * V_72 ,
bool V_73 , bool V_74 )
{
char * V_75 ;
int V_23 ;
if ( F_48 ( V_73 ) )
return - V_40 ;
V_75 = F_49 ( V_69 ) ;
if ( V_74 )
F_50 ( V_75 + V_70 ,
V_71 ) ;
V_23 = F_51 ( V_72 ,
V_75 + V_70 ,
V_71 ) ;
F_52 ( V_75 ) ;
return V_23 ? - V_76 : 0 ;
}
static void
F_53 ( char * V_77 , unsigned long V_64 ,
bool V_78 )
{
if ( F_48 ( V_78 ) ) {
unsigned long V_79 = ( unsigned long ) V_77 ;
unsigned long V_80 = ( unsigned long ) V_77 + V_64 ;
V_79 = F_54 ( V_79 , 128 ) ;
V_80 = F_55 ( V_80 , 128 ) ;
F_50 ( ( void * ) V_79 , V_80 - V_79 ) ;
} else {
F_50 ( V_77 , V_64 ) ;
}
}
static int
F_56 ( struct V_69 * V_69 , int V_70 , int V_71 ,
char T_5 * V_72 ,
bool V_73 , bool V_74 )
{
char * V_75 ;
int V_23 ;
V_75 = F_57 ( V_69 ) ;
if ( V_74 )
F_53 ( V_75 + V_70 ,
V_71 ,
V_73 ) ;
if ( V_73 )
V_23 = F_42 ( V_72 ,
V_75 , V_70 ,
V_71 ) ;
else
V_23 = F_44 ( V_72 ,
V_75 + V_70 ,
V_71 ) ;
F_58 ( V_69 ) ;
return V_23 ? - V_76 : 0 ;
}
static int
F_59 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_81 * args ,
struct V_32 * V_33 )
{
char T_5 * V_72 ;
T_6 V_82 ;
T_7 V_83 ;
int V_70 , V_71 , V_23 = 0 ;
int V_84 , V_73 ;
int V_85 = 0 ;
int V_74 = 0 ;
struct V_86 V_87 ;
V_72 = F_60 ( args -> V_88 ) ;
V_82 = args -> V_17 ;
V_84 = F_61 ( V_7 ) ;
if ( ! ( V_7 -> V_8 . V_89 & V_90 ) ) {
V_74 = ! F_1 ( V_2 , V_7 -> V_9 ) ;
V_23 = F_62 ( V_7 , true ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_63 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_64 ( V_7 ) ;
V_83 = args -> V_83 ;
F_65 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_69 * V_69 = F_66 ( & V_87 ) ;
if ( V_82 <= 0 )
break;
V_70 = F_67 ( V_83 ) ;
V_71 = V_82 ;
if ( ( V_70 + V_71 ) > V_39 )
V_71 = V_39 - V_70 ;
V_73 = V_84 &&
( F_68 ( V_69 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_47 ( V_69 , V_70 , V_71 ,
V_72 , V_73 ,
V_74 ) ;
if ( V_23 == 0 )
goto V_91;
F_25 ( & V_2 -> V_29 ) ;
if ( F_69 ( ! V_92 ) && ! V_85 ) {
V_23 = F_70 ( V_72 , V_82 ) ;
( void ) V_23 ;
V_85 = 1 ;
}
V_23 = F_56 ( V_69 , V_70 , V_71 ,
V_72 , V_73 ,
V_74 ) ;
F_23 ( & V_2 -> V_29 ) ;
V_91:
F_71 ( V_69 ) ;
if ( V_23 )
goto V_93;
V_82 -= V_71 ;
V_72 += V_71 ;
V_83 += V_71 ;
}
V_93:
F_72 ( V_7 ) ;
return V_23 ;
}
int
F_73 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_81 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_74 ( V_94 ,
F_60 ( args -> V_88 ) ,
args -> V_17 ) )
return - V_76 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( args -> V_83 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_83 ) {
V_23 = - V_40 ;
goto V_93;
}
if ( ! V_7 -> V_8 . V_97 ) {
V_23 = - V_40 ;
goto V_93;
}
F_77 ( V_7 , args -> V_83 , args -> V_17 ) ;
V_23 = F_59 ( V_2 , V_7 , args , V_33 ) ;
V_93:
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static inline int
F_79 ( struct V_98 * V_99 ,
T_7 V_100 , int V_101 ,
char T_5 * V_72 ,
int V_64 )
{
void T_8 * V_102 ;
void * V_75 ;
unsigned long V_103 ;
V_102 = F_80 ( V_99 , V_100 ) ;
V_75 = ( void V_104 * ) V_102 + V_101 ;
V_103 = F_81 ( V_75 ,
V_72 , V_64 ) ;
F_82 ( V_102 ) ;
return V_103 ;
}
static int
F_83 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_105 * args ,
struct V_32 * V_33 )
{
T_9 * V_16 = V_2 -> V_27 ;
T_6 V_82 ;
T_7 V_83 , V_100 ;
char T_5 * V_72 ;
int V_101 , V_71 , V_23 ;
V_23 = F_84 ( V_7 , 0 , true , true ) ;
if ( V_23 )
goto V_93;
V_23 = F_85 ( V_7 , true ) ;
if ( V_23 )
goto V_106;
V_23 = F_86 ( V_7 ) ;
if ( V_23 )
goto V_106;
V_72 = F_60 ( args -> V_88 ) ;
V_82 = args -> V_17 ;
V_83 = F_87 ( V_7 ) + args -> V_83 ;
while ( V_82 > 0 ) {
V_100 = V_83 & V_107 ;
V_101 = F_67 ( V_83 ) ;
V_71 = V_82 ;
if ( ( V_101 + V_82 ) > V_39 )
V_71 = V_39 - V_101 ;
if ( F_79 ( V_16 -> V_42 . V_108 , V_100 ,
V_101 , V_72 , V_71 ) ) {
V_23 = - V_76 ;
goto V_106;
}
V_82 -= V_71 ;
V_72 += V_71 ;
V_83 += V_71 ;
}
V_106:
F_88 ( V_7 ) ;
V_93:
return V_23 ;
}
static int
F_89 ( struct V_69 * V_69 , int V_70 , int V_71 ,
char T_5 * V_72 ,
bool V_73 ,
bool V_109 ,
bool V_110 )
{
char * V_75 ;
int V_23 ;
if ( F_48 ( V_73 ) )
return - V_40 ;
V_75 = F_49 ( V_69 ) ;
if ( V_109 )
F_50 ( V_75 + V_70 ,
V_71 ) ;
V_23 = F_81 ( V_75 + V_70 ,
V_72 ,
V_71 ) ;
if ( V_110 )
F_50 ( V_75 + V_70 ,
V_71 ) ;
F_52 ( V_75 ) ;
return V_23 ? - V_76 : 0 ;
}
static int
F_90 ( struct V_69 * V_69 , int V_70 , int V_71 ,
char T_5 * V_72 ,
bool V_73 ,
bool V_109 ,
bool V_110 )
{
char * V_75 ;
int V_23 ;
V_75 = F_57 ( V_69 ) ;
if ( F_48 ( V_109 || V_73 ) )
F_53 ( V_75 + V_70 ,
V_71 ,
V_73 ) ;
if ( V_73 )
V_23 = F_45 ( V_75 , V_70 ,
V_72 ,
V_71 ) ;
else
V_23 = F_46 ( V_75 + V_70 ,
V_72 ,
V_71 ) ;
if ( V_110 )
F_53 ( V_75 + V_70 ,
V_71 ,
V_73 ) ;
F_58 ( V_69 ) ;
return V_23 ? - V_76 : 0 ;
}
static int
F_91 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_105 * args ,
struct V_32 * V_33 )
{
T_6 V_82 ;
T_7 V_83 ;
char T_5 * V_72 ;
int V_70 , V_71 , V_23 = 0 ;
int V_84 , V_73 ;
int V_111 = 0 ;
int V_110 = 0 ;
int V_109 = 0 ;
struct V_86 V_87 ;
V_72 = F_60 ( args -> V_88 ) ;
V_82 = args -> V_17 ;
V_84 = F_61 ( V_7 ) ;
if ( V_7 -> V_8 . V_112 != V_90 ) {
V_110 = F_3 ( V_7 ) ;
V_23 = F_62 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
}
if ( ( V_7 -> V_8 . V_89 & V_90 ) == 0 )
V_109 =
! F_1 ( V_2 , V_7 -> V_9 ) ;
V_23 = F_63 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_64 ( V_7 ) ;
V_83 = args -> V_83 ;
V_7 -> V_113 = 1 ;
F_65 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_69 * V_69 = F_66 ( & V_87 ) ;
int V_114 ;
if ( V_82 <= 0 )
break;
V_70 = F_67 ( V_83 ) ;
V_71 = V_82 ;
if ( ( V_70 + V_71 ) > V_39 )
V_71 = V_39 - V_70 ;
V_114 = V_109 &&
( ( V_70 | V_71 )
& ( V_115 . V_116 - 1 ) ) ;
V_73 = V_84 &&
( F_68 ( V_69 ) & ( 1 << 17 ) ) != 0 ;
V_23 = F_89 ( V_69 , V_70 , V_71 ,
V_72 , V_73 ,
V_114 ,
V_110 ) ;
if ( V_23 == 0 )
goto V_91;
V_111 = 1 ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_90 ( V_69 , V_70 , V_71 ,
V_72 , V_73 ,
V_114 ,
V_110 ) ;
F_23 ( & V_2 -> V_29 ) ;
V_91:
F_92 ( V_69 ) ;
F_71 ( V_69 ) ;
if ( V_23 )
goto V_93;
V_82 -= V_71 ;
V_72 += V_71 ;
V_83 += V_71 ;
}
V_93:
F_72 ( V_7 ) ;
if ( V_111 ) {
if ( ! V_110 &&
V_7 -> V_8 . V_112 != V_90 ) {
if ( F_93 ( V_7 , V_7 -> V_10 ) )
F_94 ( V_2 ) ;
}
}
if ( V_110 )
F_94 ( V_2 ) ;
return V_23 ;
}
int
F_95 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_105 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_74 ( V_117 ,
F_60 ( args -> V_88 ) ,
args -> V_17 ) )
return - V_76 ;
if ( F_69 ( ! V_92 ) ) {
V_23 = F_96 ( F_60 ( args -> V_88 ) ,
args -> V_17 ) ;
if ( V_23 )
return - V_76 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( args -> V_83 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_83 ) {
V_23 = - V_40 ;
goto V_93;
}
if ( ! V_7 -> V_8 . V_97 ) {
V_23 = - V_40 ;
goto V_93;
}
F_97 ( V_7 , args -> V_83 , args -> V_17 ) ;
V_23 = - V_76 ;
if ( V_7 -> V_118 ) {
V_23 = F_98 ( V_2 , V_7 , args , V_33 ) ;
goto V_93;
}
if ( V_7 -> V_11 == V_119 &&
V_7 -> V_8 . V_112 != V_90 &&
F_3 ( V_7 ) ) {
V_23 = F_83 ( V_2 , V_7 , args , V_33 ) ;
}
if ( V_23 == - V_76 || V_23 == - V_120 )
V_23 = F_91 ( V_2 , V_7 , args , V_33 ) ;
V_93:
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_99 ( struct V_22 * error ,
bool V_121 )
{
if ( F_100 ( error ) ) {
if ( ! V_121 )
return - V_26 ;
if ( F_101 ( error ) )
return - V_26 ;
return - V_122 ;
}
return 0 ;
}
static int
F_102 ( struct V_123 * V_124 , T_4 V_125 )
{
int V_23 ;
F_103 ( ! F_104 ( & V_124 -> V_2 -> V_29 ) ) ;
V_23 = 0 ;
if ( V_125 == V_124 -> V_126 )
V_23 = F_105 ( V_124 , NULL ) ;
return V_23 ;
}
static void F_106 ( unsigned long V_31 )
{
F_107 ( (struct V_127 * ) V_31 ) ;
}
static bool F_108 ( struct V_15 * V_16 ,
struct V_123 * V_124 )
{
return F_109 ( V_124 -> V_128 , & V_16 -> V_28 . V_129 ) ;
}
static bool F_110 ( struct V_130 * V_131 )
{
if ( V_131 == NULL )
return true ;
return ! F_111 ( & V_131 -> V_132 , true ) ;
}
static int F_112 ( struct V_123 * V_124 , T_4 V_125 ,
unsigned V_133 ,
bool V_121 ,
struct V_134 * V_135 ,
struct V_130 * V_131 )
{
T_9 * V_16 = V_124 -> V_2 -> V_27 ;
const bool V_136 =
F_113 ( V_16 -> V_28 . V_137 ) & F_114 ( V_124 ) ;
struct V_134 V_138 , V_139 ;
F_115 ( V_140 ) ;
unsigned long V_141 ;
int V_23 ;
F_116 ( V_16 -> V_142 . V_143 , L_2 ) ;
if ( F_117 ( V_124 -> V_144 ( V_124 , true ) , V_125 ) )
return 0 ;
V_141 = V_135 ? V_145 + F_118 ( V_135 ) : 0 ;
if ( V_16 -> V_146 -> V_41 >= 6 && F_110 ( V_131 ) ) {
F_119 ( V_16 ) ;
if ( V_131 )
F_120 ( V_16 -> V_147 ,
& V_131 -> V_18 . V_148 ,
F_121 ( 100 ) ) ;
}
if ( ! V_136 && F_16 ( ! V_124 -> V_149 ( V_124 ) ) )
return - V_36 ;
F_122 ( V_124 , V_125 ) ;
F_123 ( & V_138 ) ;
for (; ; ) {
struct V_150 V_151 ;
F_124 ( & V_124 -> V_152 , & V_140 ,
V_121 ? V_153 : V_154 ) ;
if ( V_133 != F_125 ( & V_16 -> V_28 . V_133 ) ) {
V_23 = F_99 ( & V_16 -> V_28 , V_121 ) ;
if ( V_23 == 0 )
V_23 = - V_122 ;
break;
}
if ( F_117 ( V_124 -> V_144 ( V_124 , false ) , V_125 ) ) {
V_23 = 0 ;
break;
}
if ( V_121 && F_126 ( V_155 ) ) {
V_23 = - V_156 ;
break;
}
if ( V_135 && F_127 ( V_145 , V_141 ) ) {
V_23 = - V_157 ;
break;
}
V_151 . V_158 = NULL ;
if ( V_135 || F_108 ( V_16 , V_124 ) ) {
unsigned long V_159 ;
F_128 ( & V_151 , F_106 , ( unsigned long ) V_155 ) ;
V_159 = F_108 ( V_16 , V_124 ) ? V_145 + 1 : V_141 ;
F_129 ( & V_151 , V_159 ) ;
}
F_130 () ;
if ( V_151 . V_158 ) {
F_131 ( & V_151 ) ;
F_132 ( & V_151 ) ;
}
}
F_123 ( & V_139 ) ;
F_133 ( V_124 , V_125 ) ;
if ( ! V_136 )
V_124 -> V_160 ( V_124 ) ;
F_134 ( & V_124 -> V_152 , & V_140 ) ;
if ( V_135 ) {
struct V_134 V_161 = F_135 ( V_139 , V_138 ) ;
* V_135 = F_135 ( * V_135 , V_161 ) ;
if ( ! F_136 ( V_135 ) )
F_137 ( V_135 , 0 , 0 ) ;
}
return V_23 ;
}
int
F_138 ( struct V_123 * V_124 , T_3 V_125 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_121 = V_16 -> V_18 . V_121 ;
int V_23 ;
F_103 ( ! F_104 ( & V_2 -> V_29 ) ) ;
F_103 ( V_125 == 0 ) ;
V_23 = F_99 ( & V_16 -> V_28 , V_121 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_102 ( V_124 , V_125 ) ;
if ( V_23 )
return V_23 ;
return F_112 ( V_124 , V_125 ,
F_125 ( & V_16 -> V_28 . V_133 ) ,
V_121 , NULL , NULL ) ;
}
static int
F_139 ( struct V_6 * V_7 ,
struct V_123 * V_124 )
{
F_140 ( V_124 ) ;
V_7 -> V_162 = 0 ;
V_7 -> V_8 . V_112 &= ~ V_163 ;
return 0 ;
}
static T_10 int
F_62 ( struct V_6 * V_7 ,
bool V_164 )
{
struct V_123 * V_124 = V_7 -> V_124 ;
T_4 V_125 ;
int V_23 ;
V_125 = V_164 ? V_7 -> V_162 : V_7 -> V_165 ;
if ( V_125 == 0 )
return 0 ;
V_23 = F_138 ( V_124 , V_125 ) ;
if ( V_23 )
return V_23 ;
return F_139 ( V_7 , V_124 ) ;
}
static T_10 int
F_141 ( struct V_6 * V_7 ,
struct V_32 * V_33 ,
bool V_164 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 = V_7 -> V_124 ;
unsigned V_133 ;
T_4 V_125 ;
int V_23 ;
F_103 ( ! F_104 ( & V_2 -> V_29 ) ) ;
F_103 ( ! V_16 -> V_18 . V_121 ) ;
V_125 = V_164 ? V_7 -> V_162 : V_7 -> V_165 ;
if ( V_125 == 0 )
return 0 ;
V_23 = F_99 ( & V_16 -> V_28 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = F_102 ( V_124 , V_125 ) ;
if ( V_23 )
return V_23 ;
V_133 = F_125 ( & V_16 -> V_28 . V_133 ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_112 ( V_124 , V_125 , V_133 , true , NULL , V_33 -> V_166 ) ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_23 )
return V_23 ;
return F_139 ( V_7 , V_124 ) ;
}
int
F_142 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_167 * args = V_31 ;
struct V_6 * V_7 ;
T_3 V_89 = args -> V_89 ;
T_3 V_112 = args -> V_112 ;
int V_23 ;
if ( V_112 & V_163 )
return - V_40 ;
if ( V_89 & V_163 )
return - V_40 ;
if ( V_112 != 0 && V_89 != V_112 )
return - V_40 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
V_23 = F_141 ( V_7 , V_33 , ! V_112 ) ;
if ( V_23 )
goto V_168;
if ( V_89 & V_169 ) {
V_23 = F_85 ( V_7 , V_112 != 0 ) ;
if ( V_23 == - V_40 )
V_23 = 0 ;
} else {
V_23 = F_143 ( V_7 , V_112 != 0 ) ;
}
V_168:
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_144 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_170 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 = 0 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( V_7 -> V_10 )
F_145 ( V_7 , true ) ;
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_146 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_171 * args = V_31 ;
struct V_172 * V_7 ;
unsigned long V_77 ;
V_7 = F_76 ( V_2 , V_33 , args -> V_53 ) ;
if ( V_7 == NULL )
return - V_95 ;
if ( ! V_7 -> V_97 ) {
F_37 ( V_7 ) ;
return - V_40 ;
}
V_77 = F_147 ( V_7 -> V_97 , 0 , args -> V_17 ,
V_173 | V_174 , V_175 ,
args -> V_83 ) ;
F_37 ( V_7 ) ;
if ( F_148 ( ( void * ) V_77 ) )
return V_77 ;
args -> V_176 = ( T_2 ) V_77 ;
return 0 ;
}
int F_149 ( struct V_177 * V_178 , struct V_179 * V_180 )
{
struct V_6 * V_7 = F_75 ( V_178 -> V_181 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
T_9 * V_16 = V_2 -> V_27 ;
T_11 V_101 ;
unsigned long V_182 ;
int V_23 = 0 ;
bool V_183 = ! ! ( V_180 -> V_184 & V_185 ) ;
F_150 ( V_16 ) ;
V_101 = ( ( unsigned long ) V_180 -> V_186 - V_178 -> V_187 ) >>
V_188 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
goto V_93;
F_151 ( V_7 , V_101 , true , V_183 ) ;
if ( V_7 -> V_9 != V_5 && ! F_2 ( V_2 ) ) {
V_23 = - V_40 ;
goto V_96;
}
V_23 = F_84 ( V_7 , 0 , true , false ) ;
if ( V_23 )
goto V_96;
V_23 = F_85 ( V_7 , V_183 ) ;
if ( V_23 )
goto V_189;
V_23 = F_152 ( V_7 ) ;
if ( V_23 )
goto V_189;
V_7 -> V_190 = true ;
V_182 = V_16 -> V_42 . V_191 + F_87 ( V_7 ) ;
V_182 >>= V_188 ;
V_182 += V_101 ;
V_23 = F_153 ( V_178 , ( unsigned long ) V_180 -> V_186 , V_182 ) ;
V_189:
F_88 ( V_7 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
V_93:
switch ( V_23 ) {
case - V_26 :
if ( F_101 ( & V_16 -> V_28 ) ) {
V_23 = V_192 ;
break;
}
case - V_122 :
case 0 :
case - V_156 :
case - V_193 :
case - V_194 :
V_23 = V_195 ;
break;
case - V_54 :
V_23 = V_196 ;
break;
case - V_120 :
V_23 = V_192 ;
break;
default:
F_154 ( V_23 , L_3 , V_23 ) ;
V_23 = V_192 ;
break;
}
F_155 ( V_16 ) ;
return V_23 ;
}
void F_156 ( struct V_15 * V_16 )
{
struct V_197 * V_178 ;
F_16 ( ! F_157 ( & V_16 -> V_42 . V_8 . V_198 ) ) ;
F_27 (vma, &dev_priv->gtt.base.active_list, mm_list)
F_5 ( V_178 -> V_7 ) ;
F_27 (vma, &dev_priv->gtt.base.inactive_list, mm_list)
F_5 ( V_178 -> V_7 ) ;
}
void
F_5 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_190 )
return;
F_158 ( & V_7 -> V_8 . V_199 , V_7 -> V_8 . V_2 -> V_200 ) ;
V_7 -> V_190 = false ;
}
T_3
F_159 ( struct V_1 * V_2 , T_3 V_17 , int V_11 )
{
T_3 V_201 ;
if ( F_22 ( V_2 ) -> V_41 >= 4 ||
V_11 == V_119 )
return V_17 ;
if ( F_22 ( V_2 ) -> V_41 == 3 )
V_201 = 1024 * 1024 ;
else
V_201 = 512 * 1024 ;
while ( V_201 < V_17 )
V_201 <<= 1 ;
return V_201 ;
}
T_3
F_160 ( struct V_1 * V_2 , T_3 V_17 ,
int V_11 , bool V_202 )
{
if ( F_22 ( V_2 ) -> V_41 >= 4 || ( ! V_202 && F_161 ( V_2 ) ) ||
V_11 == V_119 )
return 4096 ;
return F_159 ( V_2 , V_17 , V_11 ) ;
}
static int F_162 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
if ( F_163 ( & V_7 -> V_8 . V_199 ) )
return 0 ;
V_16 -> V_18 . V_203 = true ;
V_23 = F_164 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_120 )
goto V_93;
F_165 ( V_16 , V_7 -> V_8 . V_17 >> V_188 ) ;
V_23 = F_164 ( & V_7 -> V_8 ) ;
if ( V_23 != - V_120 )
goto V_93;
F_166 ( V_16 ) ;
V_23 = F_164 ( & V_7 -> V_8 ) ;
V_93:
V_16 -> V_18 . V_203 = false ;
return V_23 ;
}
static void F_167 ( struct V_6 * V_7 )
{
F_168 ( & V_7 -> V_8 ) ;
}
int
F_169 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_3 V_53 ,
T_2 * V_83 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( V_7 -> V_8 . V_17 > V_16 -> V_42 . V_43 ) {
V_23 = - V_204 ;
goto V_93;
}
if ( V_7 -> V_205 != V_206 ) {
F_13 ( L_4 ) ;
V_23 = - V_40 ;
goto V_93;
}
V_23 = F_162 ( V_7 ) ;
if ( V_23 )
goto V_93;
* V_83 = F_170 ( & V_7 -> V_8 . V_199 ) ;
V_93:
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_171 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_207 * args = V_31 ;
return F_169 ( V_33 , V_2 , args -> V_53 , & args -> V_83 ) ;
}
static void
F_172 ( struct V_6 * V_7 )
{
struct V_208 * V_208 ;
F_167 ( V_7 ) ;
if ( V_7 -> V_8 . V_97 == NULL )
return;
V_208 = F_173 ( V_7 -> V_8 . V_97 ) ;
F_174 ( V_208 , 0 , ( T_7 ) - 1 ) ;
V_7 -> V_205 = V_209 ;
}
static inline int
F_175 ( struct V_6 * V_7 )
{
return V_7 -> V_205 == V_210 ;
}
static void
F_176 ( struct V_6 * V_7 )
{
struct V_86 V_87 ;
int V_23 ;
F_103 ( V_7 -> V_205 == V_209 ) ;
V_23 = F_143 ( V_7 , true ) ;
if ( V_23 ) {
F_16 ( V_23 != - V_26 ) ;
F_93 ( V_7 , true ) ;
V_7 -> V_8 . V_89 = V_7 -> V_8 . V_112 = V_90 ;
}
if ( F_61 ( V_7 ) )
F_177 ( V_7 ) ;
if ( V_7 -> V_205 == V_210 )
V_7 -> V_113 = 0 ;
F_65 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_69 * V_69 = F_66 ( & V_87 ) ;
if ( V_7 -> V_113 )
F_92 ( V_69 ) ;
if ( V_7 -> V_205 == V_206 )
F_71 ( V_69 ) ;
F_178 ( V_69 ) ;
}
V_7 -> V_113 = 0 ;
F_179 ( V_7 -> V_211 ) ;
F_180 ( V_7 -> V_211 ) ;
}
int
F_181 ( struct V_6 * V_7 )
{
const struct V_212 * V_213 = V_7 -> V_213 ;
if ( V_7 -> V_211 == NULL )
return 0 ;
if ( V_7 -> V_214 )
return - V_194 ;
F_103 ( F_19 ( V_7 ) ) ;
F_182 ( & V_7 -> V_215 ) ;
V_213 -> V_216 ( V_7 ) ;
V_7 -> V_211 = NULL ;
if ( F_175 ( V_7 ) )
F_172 ( V_7 ) ;
return 0 ;
}
static unsigned long
F_183 ( struct V_15 * V_16 , long V_217 ,
bool V_218 )
{
struct V_219 V_220 ;
struct V_6 * V_7 , * V_221 ;
unsigned long V_222 = 0 ;
F_184 (obj, next,
&dev_priv->mm.unbound_list,
global_list) {
if ( ( F_175 ( V_7 ) || ! V_218 ) &&
F_181 ( V_7 ) == 0 ) {
V_222 += V_7 -> V_8 . V_17 >> V_188 ;
if ( V_222 >= V_217 )
return V_222 ;
}
}
F_185 ( & V_220 ) ;
while ( V_222 < V_217 && ! F_157 ( & V_16 -> V_18 . V_223 ) ) {
struct V_197 * V_178 , * V_224 ;
V_7 = F_186 ( & V_16 -> V_18 . V_223 ,
F_187 ( * V_7 ) , V_215 ) ;
F_188 ( & V_7 -> V_215 , & V_220 ) ;
if ( ! F_175 ( V_7 ) && V_218 )
continue;
F_189 ( & V_7 -> V_8 ) ;
F_184 (vma, v, &obj->vma_list, vma_link)
if ( F_190 ( V_178 ) )
break;
if ( F_181 ( V_7 ) == 0 )
V_222 += V_7 -> V_8 . V_17 >> V_188 ;
F_78 ( & V_7 -> V_8 ) ;
}
F_191 ( & V_220 , & V_16 -> V_18 . V_223 ) ;
return V_222 ;
}
static unsigned long
F_165 ( struct V_15 * V_16 , long V_217 )
{
return F_183 ( V_16 , V_217 , true ) ;
}
static unsigned long
F_166 ( struct V_15 * V_16 )
{
struct V_6 * V_7 , * V_221 ;
long V_225 = 0 ;
F_192 ( V_16 -> V_2 ) ;
F_184 (obj, next, &dev_priv->mm.unbound_list,
global_list) {
if ( F_181 ( V_7 ) == 0 )
V_225 += V_7 -> V_8 . V_17 >> V_188 ;
}
return V_225 ;
}
static int
F_193 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_226 , V_227 ;
struct V_228 * V_99 ;
struct V_229 * V_230 ;
struct V_231 * V_232 ;
struct V_86 V_87 ;
struct V_69 * V_69 ;
unsigned long V_233 = 0 ;
T_12 V_234 ;
F_103 ( V_7 -> V_8 . V_89 & V_163 ) ;
F_103 ( V_7 -> V_8 . V_112 & V_163 ) ;
V_230 = F_194 ( sizeof( * V_230 ) , V_51 ) ;
if ( V_230 == NULL )
return - V_54 ;
V_226 = V_7 -> V_8 . V_17 / V_39 ;
if ( F_195 ( V_230 , V_226 , V_51 ) ) {
F_180 ( V_230 ) ;
return - V_54 ;
}
V_99 = F_173 ( V_7 -> V_8 . V_97 ) -> V_235 ;
V_234 = F_196 ( V_99 ) ;
V_234 |= V_236 | V_237 | V_238 ;
V_234 &= ~ ( V_239 | V_240 ) ;
V_232 = V_230 -> V_241 ;
V_230 -> V_242 = 0 ;
for ( V_227 = 0 ; V_227 < V_226 ; V_227 ++ ) {
V_69 = F_197 ( V_99 , V_227 , V_234 ) ;
if ( F_148 ( V_69 ) ) {
F_165 ( V_16 , V_226 ) ;
V_69 = F_197 ( V_99 , V_227 , V_234 ) ;
}
if ( F_148 ( V_69 ) ) {
V_234 &= ~ ( V_236 | V_237 | V_238 ) ;
V_234 |= V_239 | V_240 ;
F_166 ( V_16 ) ;
V_69 = F_197 ( V_99 , V_227 , V_234 ) ;
if ( F_148 ( V_69 ) )
goto V_243;
V_234 |= V_236 | V_237 | V_238 ;
V_234 &= ~ ( V_239 | V_240 ) ;
}
#ifdef F_198
if ( F_199 () ) {
V_230 -> V_242 ++ ;
F_200 ( V_232 , V_69 , V_39 , 0 ) ;
V_232 = F_201 ( V_232 ) ;
continue;
}
#endif
if ( ! V_227 || F_202 ( V_69 ) != V_233 + 1 ) {
if ( V_227 )
V_232 = F_201 ( V_232 ) ;
V_230 -> V_242 ++ ;
F_200 ( V_232 , V_69 , V_39 , 0 ) ;
} else {
V_232 -> V_64 += V_39 ;
}
V_233 = F_202 ( V_69 ) ;
F_16 ( ( V_234 & V_244 ) && ( V_233 >= 0x00100000UL ) ) ;
}
#ifdef F_198
if ( ! F_199 () )
#endif
F_203 ( V_232 ) ;
V_7 -> V_211 = V_230 ;
if ( F_61 ( V_7 ) )
F_204 ( V_7 ) ;
return 0 ;
V_243:
F_203 ( V_232 ) ;
F_65 (st->sgl, &sg_iter, st->nents, 0 )
F_178 ( F_66 ( & V_87 ) ) ;
F_179 ( V_230 ) ;
F_180 ( V_230 ) ;
return F_205 ( V_69 ) ;
}
int
F_63 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
const struct V_212 * V_213 = V_7 -> V_213 ;
int V_23 ;
if ( V_7 -> V_211 )
return 0 ;
if ( V_7 -> V_205 != V_206 ) {
F_13 ( L_5 ) ;
return - V_40 ;
}
F_103 ( V_7 -> V_214 ) ;
V_23 = V_213 -> V_245 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_206 ( & V_7 -> V_215 , & V_16 -> V_18 . V_246 ) ;
return 0 ;
}
static void
F_207 ( struct V_6 * V_7 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
T_4 V_125 = F_208 ( V_124 ) ;
F_103 ( V_124 == NULL ) ;
if ( V_7 -> V_124 != V_124 && V_7 -> V_162 ) {
V_7 -> V_162 = V_125 ;
}
V_7 -> V_124 = V_124 ;
if ( ! V_7 -> V_30 ) {
F_189 ( & V_7 -> V_8 ) ;
V_7 -> V_30 = 1 ;
}
F_188 ( & V_7 -> V_247 , & V_124 -> V_198 ) ;
V_7 -> V_165 = V_125 ;
if ( V_7 -> V_248 ) {
V_7 -> V_249 = V_125 ;
if ( V_7 -> V_13 != V_14 ) {
struct V_250 * V_251 ;
V_251 = & V_16 -> V_252 [ V_7 -> V_13 ] ;
F_188 ( & V_251 -> V_253 ,
& V_16 -> V_18 . V_254 ) ;
}
}
}
void F_209 ( struct V_197 * V_178 ,
struct V_123 * V_124 )
{
F_188 ( & V_178 -> V_255 , & V_178 -> V_256 -> V_198 ) ;
return F_207 ( V_178 -> V_7 , V_124 ) ;
}
static void
F_210 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_257 * V_258 = & V_16 -> V_42 . V_8 ;
struct V_197 * V_178 = F_211 ( V_7 , V_258 ) ;
F_103 ( V_7 -> V_8 . V_112 & ~ V_163 ) ;
F_103 ( ! V_7 -> V_30 ) ;
F_188 ( & V_178 -> V_255 , & V_258 -> V_259 ) ;
F_212 ( & V_7 -> V_247 ) ;
V_7 -> V_124 = NULL ;
V_7 -> V_165 = 0 ;
V_7 -> V_162 = 0 ;
V_7 -> V_8 . V_112 = 0 ;
V_7 -> V_249 = 0 ;
V_7 -> V_248 = false ;
V_7 -> V_30 = 0 ;
F_78 ( & V_7 -> V_8 ) ;
F_16 ( F_17 ( V_2 ) ) ;
}
static int
F_213 ( struct V_1 * V_2 , T_4 V_125 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 ;
int V_23 , V_227 , V_260 ;
F_214 (ring, dev_priv, i) {
V_23 = F_215 ( V_124 ) ;
if ( V_23 )
return V_23 ;
}
F_216 ( V_2 ) ;
F_214 (ring, dev_priv, i) {
F_217 ( V_124 , V_125 ) ;
for ( V_260 = 0 ; V_260 < F_218 ( V_124 -> V_261 ) ; V_260 ++ )
V_124 -> V_261 [ V_260 ] = 0 ;
}
return 0 ;
}
int F_219 ( struct V_1 * V_2 , T_4 V_125 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( V_125 == 0 )
return - V_40 ;
V_23 = F_213 ( V_2 , V_125 - 1 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_262 = V_125 ;
V_16 -> V_263 = V_125 - 1 ;
if ( V_16 -> V_263 == 0 )
V_16 -> V_263 -- ;
return 0 ;
}
int
F_220 ( struct V_1 * V_2 , T_4 * V_125 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( V_16 -> V_262 == 0 ) {
int V_23 = F_213 ( V_2 , 0 ) ;
if ( V_23 )
return V_23 ;
V_16 -> V_262 = 1 ;
}
* V_125 = V_16 -> V_263 = V_16 -> V_262 ++ ;
return 0 ;
}
int F_221 ( struct V_123 * V_124 ,
struct V_32 * V_33 ,
struct V_6 * V_7 ,
T_4 * V_264 )
{
T_9 * V_16 = V_124 -> V_2 -> V_27 ;
struct V_265 * V_266 ;
T_4 V_267 , V_268 ;
int V_269 ;
int V_23 ;
V_268 = F_222 ( V_124 ) ;
V_23 = F_223 ( V_124 ) ;
if ( V_23 )
return V_23 ;
V_266 = V_124 -> V_270 ;
if ( F_16 ( V_266 == NULL ) )
return - V_54 ;
V_267 = F_222 ( V_124 ) ;
V_23 = V_124 -> V_271 ( V_124 ) ;
if ( V_23 )
return V_23 ;
V_266 -> V_125 = F_208 ( V_124 ) ;
V_266 -> V_124 = V_124 ;
V_266 -> V_272 = V_268 ;
V_266 -> V_273 = V_267 ;
V_266 -> V_274 = V_7 ;
V_266 -> V_275 = V_124 -> V_276 ;
if ( V_266 -> V_275 )
F_224 ( V_266 -> V_275 ) ;
V_266 -> V_277 = V_145 ;
V_269 = F_157 ( & V_124 -> V_278 ) ;
F_206 ( & V_266 -> V_279 , & V_124 -> V_278 ) ;
V_266 -> V_131 = NULL ;
if ( V_33 ) {
struct V_130 * V_131 = V_33 -> V_166 ;
F_7 ( & V_131 -> V_18 . V_280 ) ;
V_266 -> V_131 = V_131 ;
F_206 ( & V_266 -> V_281 ,
& V_131 -> V_18 . V_278 ) ;
F_8 ( & V_131 -> V_18 . V_280 ) ;
}
F_225 ( V_124 , V_266 -> V_125 ) ;
V_124 -> V_126 = 0 ;
V_124 -> V_270 = NULL ;
if ( ! V_16 -> V_282 . V_283 ) {
F_226 ( V_124 -> V_2 ) ;
if ( V_269 ) {
F_227 ( & V_16 -> V_18 . V_148 ) ;
F_228 ( V_16 -> V_147 ,
& V_16 -> V_18 . V_284 ,
F_229 ( V_25 ) ) ;
F_230 ( V_16 -> V_2 ) ;
}
}
if ( V_264 )
* V_264 = V_266 -> V_125 ;
return 0 ;
}
static inline void
F_231 ( struct V_265 * V_266 )
{
struct V_130 * V_131 = V_266 -> V_131 ;
if ( ! V_131 )
return;
F_7 ( & V_131 -> V_18 . V_280 ) ;
F_182 ( & V_266 -> V_281 ) ;
V_266 -> V_131 = NULL ;
F_8 ( & V_131 -> V_18 . V_280 ) ;
}
static bool F_232 ( T_4 V_285 , struct V_6 * V_7 ,
struct V_257 * V_256 )
{
if ( V_285 >= F_233 ( V_7 , V_256 ) &&
V_285 < F_233 ( V_7 , V_256 ) + V_7 -> V_8 . V_17 )
return true ;
return false ;
}
static bool F_234 ( const T_4 V_286 ,
const T_4 V_268 ,
const T_4 V_287 )
{
const T_4 V_285 = V_286 & V_288 ;
if ( V_268 < V_287 ) {
if ( V_285 >= V_268 && V_285 < V_287 )
return true ;
} else if ( V_268 > V_287 ) {
if ( V_285 >= V_268 || V_285 < V_287 )
return true ;
}
return false ;
}
static struct V_257 *
F_235 ( struct V_265 * V_266 )
{
struct V_15 * V_16 = V_266 -> V_124 -> V_2 -> V_27 ;
struct V_257 * V_256 ;
V_256 = & V_16 -> V_42 . V_8 ;
return V_256 ;
}
static bool F_236 ( struct V_265 * V_266 ,
const T_4 V_285 , bool * V_289 )
{
if ( V_266 -> V_274 ) {
if ( F_232 ( V_285 , V_266 -> V_274 ,
F_235 ( V_266 ) ) ) {
* V_289 = true ;
return true ;
}
}
if ( F_234 ( V_285 , V_266 -> V_272 , V_266 -> V_273 ) ) {
* V_289 = false ;
return true ;
}
return false ;
}
static bool F_237 ( const struct V_290 * V_291 )
{
const unsigned long V_292 = F_238 () - V_291 -> V_293 ;
if ( V_291 -> V_294 )
return true ;
if ( V_292 <= V_295 ) {
F_13 ( L_6 ) ;
return true ;
}
return false ;
}
static void F_239 ( struct V_123 * V_124 ,
struct V_265 * V_266 ,
T_4 V_285 )
{
struct V_290 * V_291 = NULL ;
bool V_289 , V_296 ;
unsigned long V_83 = 0 ;
V_296 = false ;
if ( V_266 -> V_274 )
V_83 = F_233 ( V_266 -> V_274 ,
F_235 ( V_266 ) ) ;
if ( V_124 -> V_297 . V_298 != V_299 &&
F_236 ( V_266 , V_285 , & V_289 ) ) {
F_240 ( L_7 ,
V_124 -> V_300 ,
V_289 ? L_8 : L_9 ,
V_83 ,
V_266 -> V_275 ? V_266 -> V_275 -> V_128 : 0 ,
V_285 ) ;
V_296 = true ;
}
if ( V_266 -> V_275 && V_266 -> V_275 -> V_128 != V_301 )
V_291 = & V_266 -> V_275 -> V_302 ;
else if ( V_266 -> V_131 )
V_291 = & V_266 -> V_131 -> V_302 ;
if ( V_291 ) {
if ( V_296 ) {
V_291 -> V_294 = F_237 ( V_291 ) ;
V_291 -> V_303 ++ ;
V_291 -> V_293 = F_238 () ;
} else {
V_291 -> V_304 ++ ;
}
}
}
static void F_241 ( struct V_265 * V_266 )
{
F_182 ( & V_266 -> V_279 ) ;
F_231 ( V_266 ) ;
if ( V_266 -> V_275 )
F_242 ( V_266 -> V_275 ) ;
F_180 ( V_266 ) ;
}
static void F_243 ( struct V_15 * V_16 ,
struct V_123 * V_124 )
{
T_4 V_305 = V_124 -> V_144 ( V_124 , false ) ;
T_4 V_285 = F_244 ( V_124 ) ;
struct V_265 * V_266 ;
F_27 (request, &ring->request_list, list) {
if ( F_117 ( V_305 , V_266 -> V_125 ) )
continue;
F_239 ( V_124 , V_266 , V_285 ) ;
}
}
static void F_245 ( struct V_15 * V_16 ,
struct V_123 * V_124 )
{
while ( ! F_157 ( & V_124 -> V_198 ) ) {
struct V_6 * V_7 ;
V_7 = F_186 ( & V_124 -> V_198 ,
struct V_6 ,
V_247 ) ;
F_210 ( V_7 ) ;
}
while ( ! F_157 ( & V_124 -> V_278 ) ) {
struct V_265 * V_266 ;
V_266 = F_186 ( & V_124 -> V_278 ,
struct V_265 ,
V_279 ) ;
F_241 ( V_266 ) ;
}
}
void F_246 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_227 ;
for ( V_227 = 0 ; V_227 < V_16 -> V_306 ; V_227 ++ ) {
struct V_250 * V_251 = & V_16 -> V_252 [ V_227 ] ;
if ( V_251 -> V_7 ) {
F_247 ( V_251 -> V_7 , V_251 ,
V_251 -> V_7 -> V_11 ) ;
} else {
F_248 ( V_2 , V_227 , NULL ) ;
}
}
}
void F_249 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 ;
int V_227 ;
F_214 (ring, dev_priv, i)
F_243 ( V_16 , V_124 ) ;
F_214 (ring, dev_priv, i)
F_245 ( V_16 , V_124 ) ;
F_250 ( V_2 ) ;
F_246 ( V_2 ) ;
}
void
F_140 ( struct V_123 * V_124 )
{
T_3 V_125 ;
if ( F_157 ( & V_124 -> V_278 ) )
return;
F_16 ( F_17 ( V_124 -> V_2 ) ) ;
V_125 = V_124 -> V_144 ( V_124 , true ) ;
while ( ! F_157 ( & V_124 -> V_278 ) ) {
struct V_265 * V_266 ;
V_266 = F_186 ( & V_124 -> V_278 ,
struct V_265 ,
V_279 ) ;
if ( ! F_117 ( V_125 , V_266 -> V_125 ) )
break;
F_251 ( V_124 , V_266 -> V_125 ) ;
V_124 -> V_307 = V_266 -> V_273 ;
F_241 ( V_266 ) ;
}
while ( ! F_157 ( & V_124 -> V_198 ) ) {
struct V_6 * V_7 ;
V_7 = F_186 ( & V_124 -> V_198 ,
struct V_6 ,
V_247 ) ;
if ( ! F_117 ( V_125 , V_7 -> V_165 ) )
break;
F_210 ( V_7 ) ;
}
if ( F_48 ( V_124 -> V_308 &&
F_117 ( V_125 , V_124 -> V_308 ) ) ) {
V_124 -> V_160 ( V_124 ) ;
V_124 -> V_308 = 0 ;
}
F_16 ( F_17 ( V_124 -> V_2 ) ) ;
}
bool
F_216 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 ;
bool V_309 = true ;
int V_227 ;
F_214 (ring, dev_priv, i) {
F_140 ( V_124 ) ;
V_309 &= F_157 ( & V_124 -> V_278 ) ;
}
if ( V_309 )
F_120 ( V_16 -> V_147 ,
& V_16 -> V_18 . V_148 ,
F_121 ( 100 ) ) ;
return V_309 ;
}
static void
F_252 ( struct V_310 * V_311 )
{
struct V_15 * V_16 =
F_253 ( V_311 , F_187 ( * V_16 ) , V_18 . V_284 . V_311 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_309 ;
V_309 = false ;
if ( F_254 ( & V_2 -> V_29 ) ) {
V_309 = F_216 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
}
if ( ! V_309 )
F_228 ( V_16 -> V_147 , & V_16 -> V_18 . V_284 ,
F_229 ( V_25 ) ) ;
}
static void
F_255 ( struct V_310 * V_311 )
{
struct V_15 * V_16 =
F_253 ( V_311 , F_187 ( * V_16 ) , V_18 . V_148 . V_311 ) ;
F_256 ( V_16 -> V_2 ) ;
}
static int
F_257 ( struct V_6 * V_7 )
{
int V_23 ;
if ( V_7 -> V_30 ) {
V_23 = F_102 ( V_7 -> V_124 , V_7 -> V_165 ) ;
if ( V_23 )
return V_23 ;
F_140 ( V_7 -> V_124 ) ;
}
return 0 ;
}
int
F_258 ( struct V_1 * V_2 , void * V_31 , struct V_32 * V_33 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_312 * args = V_31 ;
struct V_6 * V_7 ;
struct V_123 * V_124 = NULL ;
struct V_134 V_313 , * V_135 = NULL ;
unsigned V_133 ;
T_4 V_125 = 0 ;
int V_23 = 0 ;
if ( args -> V_314 >= 0 ) {
V_313 = F_259 ( args -> V_314 ) ;
V_135 = & V_313 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_315 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_25 ( & V_2 -> V_29 ) ;
return - V_95 ;
}
V_23 = F_257 ( V_7 ) ;
if ( V_23 )
goto V_93;
if ( V_7 -> V_30 ) {
V_125 = V_7 -> V_165 ;
V_124 = V_7 -> V_124 ;
}
if ( V_125 == 0 )
goto V_93;
if ( ! args -> V_314 ) {
V_23 = - V_157 ;
goto V_93;
}
F_78 ( & V_7 -> V_8 ) ;
V_133 = F_125 ( & V_16 -> V_28 . V_133 ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_112 ( V_124 , V_125 , V_133 , true , V_135 , V_33 -> V_166 ) ;
if ( V_135 )
args -> V_314 = F_260 ( V_135 ) ;
return V_23 ;
V_93:
F_78 ( & V_7 -> V_8 ) ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_261 ( struct V_6 * V_7 ,
struct V_123 * V_316 )
{
struct V_123 * V_317 = V_7 -> V_124 ;
T_4 V_125 ;
int V_23 , V_318 ;
if ( V_317 == NULL || V_316 == V_317 )
return 0 ;
if ( V_316 == NULL || ! F_262 ( V_7 -> V_8 . V_2 ) )
return F_62 ( V_7 , false ) ;
V_318 = F_263 ( V_317 , V_316 ) ;
V_125 = V_7 -> V_165 ;
if ( V_125 <= V_317 -> V_261 [ V_318 ] )
return 0 ;
V_23 = F_102 ( V_7 -> V_124 , V_125 ) ;
if ( V_23 )
return V_23 ;
F_264 ( V_317 , V_316 , V_125 ) ;
V_23 = V_316 -> V_319 ( V_316 , V_317 , V_125 ) ;
if ( ! V_23 )
V_317 -> V_261 [ V_318 ] = V_7 -> V_165 ;
return V_23 ;
}
static void F_265 ( struct V_6 * V_7 )
{
T_4 V_320 , V_321 ;
F_5 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_89 & V_169 ) == 0 )
return;
F_266 () ;
V_321 = V_7 -> V_8 . V_89 ;
V_320 = V_7 -> V_8 . V_112 ;
V_7 -> V_8 . V_89 &= ~ V_169 ;
V_7 -> V_8 . V_112 &= ~ V_169 ;
F_267 ( V_7 ,
V_321 ,
V_320 ) ;
}
int F_190 ( struct V_197 * V_178 )
{
struct V_6 * V_7 = V_178 -> V_7 ;
T_9 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_23 ;
F_16 ( ! F_268 ( & V_7 -> V_322 ) ) ;
if ( F_157 ( & V_178 -> V_323 ) )
return 0 ;
if ( ! F_269 ( & V_178 -> V_324 ) ) {
F_270 ( V_178 ) ;
return 0 ;
}
if ( V_7 -> V_46 )
return - V_194 ;
F_103 ( V_7 -> V_211 == NULL ) ;
V_23 = F_271 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_265 ( V_7 ) ;
V_23 = F_86 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_272 ( V_178 ) ;
if ( V_7 -> V_325 )
F_273 ( V_7 ) ;
if ( V_7 -> V_326 ) {
F_274 ( V_16 -> V_18 . V_327 , V_7 ) ;
V_7 -> V_326 = 0 ;
}
F_275 ( V_7 ) ;
F_182 ( & V_178 -> V_255 ) ;
if ( F_276 ( V_178 -> V_256 ) )
V_7 -> V_328 = true ;
F_277 ( & V_178 -> V_324 ) ;
F_270 ( V_178 ) ;
if ( F_157 ( & V_7 -> V_322 ) )
F_188 ( & V_7 -> V_215 , & V_16 -> V_18 . V_246 ) ;
F_72 ( V_7 ) ;
return 0 ;
}
int
F_278 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_257 * V_329 = & V_16 -> V_42 . V_8 ;
if ( ! F_279 ( V_7 ) )
return 0 ;
if ( V_7 -> V_46 )
return - V_194 ;
F_103 ( V_7 -> V_211 == NULL ) ;
return F_190 ( F_211 ( V_7 , V_329 ) ) ;
}
int F_280 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 ;
int V_23 , V_227 ;
F_214 (ring, dev_priv, i) {
V_23 = F_281 ( V_124 , NULL , V_301 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_215 ( V_124 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static void F_282 ( struct V_1 * V_2 , int V_251 ,
struct V_6 * V_7 )
{
T_9 * V_16 = V_2 -> V_27 ;
int V_13 ;
int V_330 ;
if ( F_22 ( V_2 ) -> V_41 >= 6 ) {
V_13 = V_331 ;
V_330 = V_332 ;
} else {
V_13 = V_333 ;
V_330 = V_334 ;
}
V_13 += V_251 * 8 ;
F_283 ( V_13 , 0 ) ;
F_284 ( V_13 ) ;
if ( V_7 ) {
T_4 V_17 = F_28 ( V_7 ) ;
T_2 V_335 ;
V_335 = ( T_2 ) ( ( F_87 ( V_7 ) + V_17 - 4096 ) &
0xfffff000 ) << 32 ;
V_335 |= F_87 ( V_7 ) & 0xfffff000 ;
V_335 |= ( T_2 ) ( ( V_7 -> V_336 / 128 ) - 1 ) << V_330 ;
if ( V_7 -> V_11 == V_337 )
V_335 |= 1 << V_338 ;
V_335 |= V_339 ;
F_283 ( V_13 + 4 , V_335 >> 32 ) ;
F_284 ( V_13 + 4 ) ;
F_283 ( V_13 + 0 , V_335 ) ;
F_284 ( V_13 ) ;
} else {
F_283 ( V_13 + 4 , 0 ) ;
F_284 ( V_13 + 4 ) ;
}
}
static void F_285 ( struct V_1 * V_2 , int V_251 ,
struct V_6 * V_7 )
{
T_9 * V_16 = V_2 -> V_27 ;
T_4 V_335 ;
if ( V_7 ) {
T_4 V_17 = F_28 ( V_7 ) ;
int V_340 ;
int V_341 ;
F_116 ( ( F_87 ( V_7 ) & ~ V_342 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_87 ( V_7 ) & ( V_17 - 1 ) ) ,
L_10 ,
F_87 ( V_7 ) , V_7 -> V_328 , V_17 ) ;
if ( V_7 -> V_11 == V_337 && F_286 ( V_2 ) )
V_341 = 128 ;
else
V_341 = 512 ;
V_340 = V_7 -> V_336 / V_341 ;
V_340 = F_287 ( V_340 ) - 1 ;
V_335 = F_87 ( V_7 ) ;
if ( V_7 -> V_11 == V_337 )
V_335 |= 1 << V_343 ;
V_335 |= F_288 ( V_17 ) ;
V_335 |= V_340 << V_344 ;
V_335 |= V_345 ;
} else
V_335 = 0 ;
if ( V_251 < 8 )
V_251 = V_346 + V_251 * 4 ;
else
V_251 = V_347 + ( V_251 - 8 ) * 4 ;
F_283 ( V_251 , V_335 ) ;
F_284 ( V_251 ) ;
}
static void F_289 ( struct V_1 * V_2 , int V_251 ,
struct V_6 * V_7 )
{
T_9 * V_16 = V_2 -> V_27 ;
T_3 V_335 ;
if ( V_7 ) {
T_4 V_17 = F_28 ( V_7 ) ;
T_3 V_340 ;
F_116 ( ( F_87 ( V_7 ) & ~ V_348 ) ||
( V_17 & - V_17 ) != V_17 ||
( F_87 ( V_7 ) & ( V_17 - 1 ) ) ,
L_11 ,
F_87 ( V_7 ) , V_17 ) ;
V_340 = V_7 -> V_336 / 128 ;
V_340 = F_287 ( V_340 ) - 1 ;
V_335 = F_87 ( V_7 ) ;
if ( V_7 -> V_11 == V_337 )
V_335 |= 1 << V_343 ;
V_335 |= F_290 ( V_17 ) ;
V_335 |= V_340 << V_344 ;
V_335 |= V_345 ;
} else
V_335 = 0 ;
F_283 ( V_346 + V_251 * 4 , V_335 ) ;
F_284 ( V_346 + V_251 * 4 ) ;
}
inline static bool F_291 ( struct V_6 * V_7 )
{
return V_7 && V_7 -> V_8 . V_89 & V_169 ;
}
static void F_248 ( struct V_1 * V_2 , int V_251 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
if ( F_291 ( V_16 -> V_252 [ V_251 ] . V_7 ) )
F_266 () ;
F_116 ( V_7 && ( ! V_7 -> V_336 || ! V_7 -> V_11 ) ,
L_12 ,
V_7 -> V_336 , V_7 -> V_11 ) ;
switch ( F_22 ( V_2 ) -> V_41 ) {
case 8 :
case 7 :
case 6 :
case 5 :
case 4 : F_282 ( V_2 , V_251 , V_7 ) ; break;
case 3 : F_285 ( V_2 , V_251 , V_7 ) ; break;
case 2 : F_289 ( V_2 , V_251 , V_7 ) ; break;
default: F_292 () ;
}
if ( F_291 ( V_7 ) )
F_266 () ;
}
static inline int F_293 ( struct V_15 * V_16 ,
struct V_250 * V_349 )
{
return V_349 - V_16 -> V_252 ;
}
static void F_247 ( struct V_6 * V_7 ,
struct V_250 * V_349 ,
bool V_350 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
int V_251 = F_293 ( V_16 , V_349 ) ;
F_248 ( V_7 -> V_8 . V_2 , V_251 , V_350 ? V_7 : NULL ) ;
if ( V_350 ) {
V_7 -> V_13 = V_251 ;
V_349 -> V_7 = V_7 ;
F_188 ( & V_349 -> V_253 , & V_16 -> V_18 . V_254 ) ;
} else {
V_7 -> V_13 = V_14 ;
V_349 -> V_7 = NULL ;
F_212 ( & V_349 -> V_253 ) ;
}
V_7 -> V_12 = false ;
}
static int
F_294 ( struct V_6 * V_7 )
{
if ( V_7 -> V_249 ) {
int V_23 = F_138 ( V_7 -> V_124 , V_7 -> V_249 ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_249 = 0 ;
}
V_7 -> V_248 = false ;
return 0 ;
}
int
F_86 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
struct V_250 * V_349 ;
int V_23 ;
V_23 = F_294 ( V_7 ) ;
if ( V_23 )
return V_23 ;
if ( V_7 -> V_13 == V_14 )
return 0 ;
V_349 = & V_16 -> V_252 [ V_7 -> V_13 ] ;
F_4 ( V_7 ) ;
F_247 ( V_7 , V_349 , false ) ;
return 0 ;
}
static struct V_250 *
F_295 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_250 * V_251 , * V_351 ;
int V_227 ;
V_351 = NULL ;
for ( V_227 = V_16 -> V_352 ; V_227 < V_16 -> V_306 ; V_227 ++ ) {
V_251 = & V_16 -> V_252 [ V_227 ] ;
if ( ! V_251 -> V_7 )
return V_251 ;
if ( ! V_251 -> V_46 )
V_351 = V_251 ;
}
if ( V_351 == NULL )
goto V_353;
F_27 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_251 -> V_46 )
continue;
return V_251 ;
}
V_353:
if ( F_296 ( V_2 ) )
return F_297 ( - V_122 ) ;
return F_297 ( - V_354 ) ;
}
int
F_152 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 * V_16 = V_2 -> V_27 ;
bool V_350 = V_7 -> V_11 != V_119 ;
struct V_250 * V_251 ;
int V_23 ;
if ( V_7 -> V_12 ) {
V_23 = F_294 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_7 -> V_13 != V_14 ) {
V_251 = & V_16 -> V_252 [ V_7 -> V_13 ] ;
if ( ! V_7 -> V_12 ) {
F_188 ( & V_251 -> V_253 ,
& V_16 -> V_18 . V_254 ) ;
return 0 ;
}
} else if ( V_350 ) {
V_251 = F_295 ( V_2 ) ;
if ( F_148 ( V_251 ) )
return F_205 ( V_251 ) ;
if ( V_251 -> V_7 ) {
struct V_6 * V_355 = V_251 -> V_7 ;
V_23 = F_294 ( V_355 ) ;
if ( V_23 )
return V_23 ;
F_4 ( V_355 ) ;
}
} else
return 0 ;
F_247 ( V_7 , V_251 , V_350 ) ;
return 0 ;
}
static bool F_298 ( struct V_1 * V_2 ,
struct V_356 * V_357 ,
unsigned long V_9 )
{
struct V_356 * V_358 ;
if ( F_2 ( V_2 ) )
return true ;
if ( ! F_269 ( V_357 ) )
return true ;
if ( F_157 ( & V_357 -> V_359 ) )
return true ;
V_358 = F_299 ( V_357 -> V_359 . V_360 , struct V_356 , V_359 ) ;
if ( V_358 -> V_361 && ! V_358 -> V_362 && V_358 -> V_363 != V_9 )
return false ;
V_358 = F_299 ( V_357 -> V_359 . V_221 , struct V_356 , V_359 ) ;
if ( V_358 -> V_361 && ! V_357 -> V_362 && V_358 -> V_363 != V_9 )
return false ;
return true ;
}
static void F_300 ( struct V_1 * V_2 )
{
#if V_364
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_6 * V_7 ;
int V_365 = 0 ;
F_27 (obj, &dev_priv->mm.gtt_list, global_list) {
if ( V_7 -> V_357 == NULL ) {
F_301 ( V_366 L_13 ) ;
V_365 ++ ;
continue;
}
if ( V_7 -> V_9 != V_7 -> V_357 -> V_363 ) {
F_301 ( V_366 L_14 ,
F_87 ( V_7 ) ,
F_87 ( V_7 ) + F_28 ( V_7 ) ,
V_7 -> V_9 ,
V_7 -> V_357 -> V_363 ) ;
V_365 ++ ;
continue;
}
if ( ! F_298 ( V_2 ,
V_7 -> V_357 ,
V_7 -> V_9 ) ) {
F_301 ( V_366 L_15 ,
F_87 ( V_7 ) ,
F_87 ( V_7 ) + F_28 ( V_7 ) ,
V_7 -> V_9 ) ;
V_365 ++ ;
continue;
}
}
F_16 ( V_365 ) ;
#endif
}
static int
F_302 ( struct V_6 * V_7 ,
struct V_257 * V_256 ,
unsigned V_367 ,
bool V_328 ,
bool V_368 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
T_9 * V_16 = V_2 -> V_27 ;
T_4 V_17 , V_369 , V_370 , V_371 ;
T_1 V_372 =
V_328 ? V_16 -> V_42 . V_43 : V_256 -> V_48 ;
struct V_197 * V_178 ;
int V_23 ;
V_369 = F_159 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 ) ;
V_370 = F_160 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , true ) ;
V_371 =
F_160 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_11 , false ) ;
if ( V_367 == 0 )
V_367 = V_328 ? V_370 :
V_371 ;
if ( V_328 && V_367 & ( V_370 - 1 ) ) {
F_13 ( L_16 , V_367 ) ;
return - V_40 ;
}
V_17 = V_328 ? V_369 : V_7 -> V_8 . V_17 ;
if ( V_7 -> V_8 . V_17 > V_372 ) {
F_13 ( L_17 ,
V_7 -> V_8 . V_17 ,
V_328 ? L_18 : L_19 ,
V_372 ) ;
return - V_204 ;
}
V_23 = F_63 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_64 ( V_7 ) ;
F_103 ( ! F_276 ( V_256 ) ) ;
V_178 = F_303 ( V_7 , V_256 ) ;
if ( F_148 ( V_178 ) ) {
V_23 = F_205 ( V_178 ) ;
goto V_373;
}
F_16 ( ! F_268 ( & V_7 -> V_322 ) ) ;
V_374:
V_23 = F_304 ( & V_256 -> V_18 , & V_178 -> V_324 ,
V_17 , V_367 ,
V_7 -> V_9 , 0 , V_372 ,
V_375 ) ;
if ( V_23 ) {
V_23 = F_305 ( V_2 , V_256 , V_17 , V_367 ,
V_7 -> V_9 ,
V_328 ,
V_368 ) ;
if ( V_23 == 0 )
goto V_374;
goto V_376;
}
if ( F_16 ( ! F_298 ( V_2 , & V_178 -> V_324 ,
V_7 -> V_9 ) ) ) {
V_23 = - V_40 ;
goto V_377;
}
V_23 = F_306 ( V_7 ) ;
if ( V_23 )
goto V_377;
F_188 ( & V_7 -> V_215 , & V_16 -> V_18 . V_223 ) ;
F_206 ( & V_178 -> V_255 , & V_256 -> V_259 ) ;
if ( F_276 ( V_256 ) ) {
bool V_108 , V_378 ;
V_378 = ( V_178 -> V_324 . V_17 == V_369 &&
( V_178 -> V_324 . V_79 & ( V_370 - 1 ) ) == 0 ) ;
V_108 = ( V_178 -> V_324 . V_79 + V_7 -> V_8 . V_17 <=
V_16 -> V_42 . V_43 ) ;
V_7 -> V_328 = V_108 && V_378 ;
}
F_16 ( V_328 && ! V_7 -> V_328 ) ;
F_307 ( V_178 , V_328 ) ;
F_300 ( V_2 ) ;
return 0 ;
V_377:
F_277 ( & V_178 -> V_324 ) ;
V_376:
F_270 ( V_178 ) ;
V_373:
F_72 ( V_7 ) ;
return V_23 ;
}
bool
F_93 ( struct V_6 * V_7 ,
bool V_379 )
{
if ( V_7 -> V_211 == NULL )
return false ;
if ( V_7 -> V_380 )
return false ;
if ( ! V_379 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) )
return false ;
F_308 ( V_7 ) ;
F_309 ( V_7 -> V_211 ) ;
return true ;
}
static void
F_310 ( struct V_6 * V_7 )
{
T_3 V_320 ;
if ( V_7 -> V_8 . V_112 != V_169 )
return;
F_311 () ;
V_320 = V_7 -> V_8 . V_112 ;
V_7 -> V_8 . V_112 = 0 ;
F_267 ( V_7 ,
V_7 -> V_8 . V_89 ,
V_320 ) ;
}
static void
F_145 ( struct V_6 * V_7 ,
bool V_379 )
{
T_3 V_320 ;
if ( V_7 -> V_8 . V_112 != V_90 )
return;
if ( F_93 ( V_7 , V_379 ) )
F_94 ( V_7 -> V_8 . V_2 ) ;
V_320 = V_7 -> V_8 . V_112 ;
V_7 -> V_8 . V_112 = 0 ;
F_267 ( V_7 ,
V_7 -> V_8 . V_89 ,
V_320 ) ;
}
int
F_85 ( struct V_6 * V_7 , bool V_183 )
{
T_9 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
T_3 V_320 , V_321 ;
int V_23 ;
if ( ! F_19 ( V_7 ) )
return - V_40 ;
if ( V_7 -> V_8 . V_112 == V_169 )
return 0 ;
V_23 = F_62 ( V_7 , ! V_183 ) ;
if ( V_23 )
return V_23 ;
F_145 ( V_7 , false ) ;
if ( ( V_7 -> V_8 . V_89 & V_169 ) == 0 )
F_266 () ;
V_320 = V_7 -> V_8 . V_112 ;
V_321 = V_7 -> V_8 . V_89 ;
F_103 ( ( V_7 -> V_8 . V_112 & ~ V_169 ) != 0 ) ;
V_7 -> V_8 . V_89 |= V_169 ;
if ( V_183 ) {
V_7 -> V_8 . V_89 = V_169 ;
V_7 -> V_8 . V_112 = V_169 ;
V_7 -> V_113 = 1 ;
}
F_267 ( V_7 ,
V_321 ,
V_320 ) ;
if ( F_18 ( V_7 ) ) {
struct V_197 * V_178 = F_312 ( V_7 ) ;
if ( V_178 )
F_188 ( & V_178 -> V_255 ,
& V_16 -> V_42 . V_8 . V_259 ) ;
}
return 0 ;
}
int F_313 ( struct V_6 * V_7 ,
enum V_3 V_9 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
T_9 * V_16 = V_2 -> V_27 ;
struct V_197 * V_178 ;
int V_23 ;
if ( V_7 -> V_9 == V_9 )
return 0 ;
if ( V_7 -> V_46 ) {
F_240 ( L_20 ) ;
return - V_194 ;
}
F_27 (vma, &obj->vma_list, vma_link) {
if ( ! F_298 ( V_2 , & V_178 -> V_324 , V_9 ) ) {
V_23 = F_190 ( V_178 ) ;
if ( V_23 )
return V_23 ;
break;
}
}
if ( F_19 ( V_7 ) ) {
V_23 = F_271 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_265 ( V_7 ) ;
if ( F_22 ( V_2 ) -> V_41 < 6 ) {
V_23 = F_86 ( V_7 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_7 -> V_325 )
F_314 ( V_7 , V_9 ) ;
if ( V_7 -> V_326 )
F_315 ( V_16 -> V_18 . V_327 ,
V_7 , V_9 ) ;
}
F_27 (vma, &obj->vma_list, vma_link)
V_178 -> V_324 . V_363 = V_9 ;
V_7 -> V_9 = V_9 ;
if ( F_3 ( V_7 ) ) {
T_4 V_321 , V_320 ;
F_16 ( V_7 -> V_8 . V_112 & ~ V_90 ) ;
V_321 = V_7 -> V_8 . V_89 ;
V_320 = V_7 -> V_8 . V_112 ;
V_7 -> V_8 . V_89 = V_90 ;
V_7 -> V_8 . V_112 = V_90 ;
F_267 ( V_7 ,
V_321 ,
V_320 ) ;
}
F_300 ( V_2 ) ;
return 0 ;
}
int F_316 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_381 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
switch ( V_7 -> V_9 ) {
case V_382 :
case V_383 :
args -> V_384 = V_385 ;
break;
case V_386 :
args -> V_384 = V_387 ;
break;
default:
args -> V_384 = V_388 ;
break;
}
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_317 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_381 * args = V_31 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_23 ;
switch ( args -> V_384 ) {
case V_388 :
V_4 = V_5 ;
break;
case V_385 :
V_4 = V_382 ;
break;
case V_387 :
V_4 = F_318 ( V_2 ) ? V_386 : V_5 ;
break;
default:
return - V_40 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
V_23 = F_313 ( V_7 , V_4 ) ;
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
static bool F_319 ( struct V_6 * V_7 )
{
return V_7 -> V_46 - ! ! V_7 -> V_389 ;
}
int
F_320 ( struct V_6 * V_7 ,
T_4 V_367 ,
struct V_123 * V_390 )
{
T_4 V_321 , V_320 ;
int V_23 ;
if ( V_390 != V_7 -> V_124 ) {
V_23 = F_261 ( V_7 , V_390 ) ;
if ( V_23 )
return V_23 ;
}
V_7 -> V_10 = true ;
V_23 = F_313 ( V_7 ,
F_318 ( V_7 -> V_8 . V_2 ) ? V_386 : V_5 ) ;
if ( V_23 )
goto V_391;
V_23 = F_84 ( V_7 , V_367 , true , false ) ;
if ( V_23 )
goto V_391;
F_145 ( V_7 , true ) ;
V_320 = V_7 -> V_8 . V_112 ;
V_321 = V_7 -> V_8 . V_89 ;
V_7 -> V_8 . V_112 = 0 ;
V_7 -> V_8 . V_89 |= V_169 ;
F_267 ( V_7 ,
V_321 ,
V_320 ) ;
return 0 ;
V_391:
V_7 -> V_10 = F_319 ( V_7 ) ;
return V_23 ;
}
void
F_321 ( struct V_6 * V_7 )
{
F_88 ( V_7 ) ;
V_7 -> V_10 = F_319 ( V_7 ) ;
}
int
F_271 ( struct V_6 * V_7 )
{
int V_23 ;
if ( ( V_7 -> V_8 . V_89 & V_163 ) == 0 )
return 0 ;
V_23 = F_62 ( V_7 , false ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_8 . V_89 &= ~ V_163 ;
return 0 ;
}
int
F_143 ( struct V_6 * V_7 , bool V_183 )
{
T_3 V_320 , V_321 ;
int V_23 ;
if ( V_7 -> V_8 . V_112 == V_90 )
return 0 ;
V_23 = F_62 ( V_7 , ! V_183 ) ;
if ( V_23 )
return V_23 ;
F_310 ( V_7 ) ;
V_320 = V_7 -> V_8 . V_112 ;
V_321 = V_7 -> V_8 . V_89 ;
if ( ( V_7 -> V_8 . V_89 & V_90 ) == 0 ) {
F_93 ( V_7 , false ) ;
V_7 -> V_8 . V_89 |= V_90 ;
}
F_103 ( ( V_7 -> V_8 . V_112 & ~ V_90 ) != 0 ) ;
if ( V_183 ) {
V_7 -> V_8 . V_89 = V_90 ;
V_7 -> V_8 . V_112 = V_90 ;
}
F_267 ( V_7 ,
V_321 ,
V_320 ) ;
return 0 ;
}
static int
F_322 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
struct V_130 * V_131 = V_33 -> V_166 ;
unsigned long V_392 = V_145 - F_121 ( 20 ) ;
struct V_265 * V_266 ;
struct V_123 * V_124 = NULL ;
unsigned V_133 ;
T_4 V_125 = 0 ;
int V_23 ;
V_23 = F_10 ( & V_16 -> V_28 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_99 ( & V_16 -> V_28 , false ) ;
if ( V_23 )
return V_23 ;
F_7 ( & V_131 -> V_18 . V_280 ) ;
F_27 (request, &file_priv->mm.request_list, client_list) {
if ( F_127 ( V_266 -> V_277 , V_392 ) )
break;
V_124 = V_266 -> V_124 ;
V_125 = V_266 -> V_125 ;
}
V_133 = F_125 ( & V_16 -> V_28 . V_133 ) ;
F_8 ( & V_131 -> V_18 . V_280 ) ;
if ( V_125 == 0 )
return 0 ;
V_23 = F_112 ( V_124 , V_125 , V_133 , true , NULL , NULL ) ;
if ( V_23 == 0 )
F_228 ( V_16 -> V_147 , & V_16 -> V_18 . V_284 , 0 ) ;
return V_23 ;
}
int
F_323 ( struct V_6 * V_7 ,
struct V_257 * V_256 ,
T_3 V_367 ,
bool V_328 ,
bool V_368 )
{
struct V_197 * V_178 ;
int V_23 ;
if ( F_16 ( V_7 -> V_46 == V_393 ) )
return - V_194 ;
F_16 ( V_328 && ! F_276 ( V_256 ) ) ;
V_178 = F_211 ( V_7 , V_256 ) ;
if ( V_178 ) {
if ( ( V_367 &&
V_178 -> V_324 . V_79 & ( V_367 - 1 ) ) ||
( V_328 && ! V_7 -> V_328 ) ) {
F_116 ( V_7 -> V_46 ,
L_21
L_22
L_23 ,
F_233 ( V_7 , V_256 ) , V_367 ,
V_328 ,
V_7 -> V_328 ) ;
V_23 = F_190 ( V_178 ) ;
if ( V_23 )
return V_23 ;
}
}
if ( ! F_324 ( V_7 , V_256 ) ) {
struct V_15 * V_16 = V_7 -> V_8 . V_2 -> V_27 ;
V_23 = F_302 ( V_7 , V_256 , V_367 ,
V_328 ,
V_368 ) ;
if ( V_23 )
return V_23 ;
if ( ! V_16 -> V_18 . V_327 )
F_314 ( V_7 , V_7 -> V_9 ) ;
}
if ( ! V_7 -> V_325 && V_328 )
F_314 ( V_7 , V_7 -> V_9 ) ;
V_7 -> V_46 ++ ;
V_7 -> V_394 |= V_328 ;
return 0 ;
}
void
F_88 ( struct V_6 * V_7 )
{
F_103 ( V_7 -> V_46 == 0 ) ;
F_103 ( ! F_19 ( V_7 ) ) ;
if ( -- V_7 -> V_46 == 0 )
V_7 -> V_394 = false ;
}
int
F_325 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_395 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( V_7 -> V_205 != V_206 ) {
F_13 ( L_24 ) ;
V_23 = - V_40 ;
goto V_93;
}
if ( V_7 -> V_396 != NULL && V_7 -> V_396 != V_33 ) {
F_13 ( L_25 ,
args -> V_53 ) ;
V_23 = - V_40 ;
goto V_93;
}
if ( V_7 -> V_389 == V_397 ) {
V_23 = - V_194 ;
goto V_93;
}
if ( V_7 -> V_389 == 0 ) {
V_23 = F_84 ( V_7 , args -> V_367 , true , false ) ;
if ( V_23 )
goto V_93;
}
V_7 -> V_389 ++ ;
V_7 -> V_396 = V_33 ;
args -> V_83 = F_87 ( V_7 ) ;
V_93:
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_326 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_395 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( V_7 -> V_396 != V_33 ) {
F_13 ( L_26 ,
args -> V_53 ) ;
V_23 = - V_40 ;
goto V_93;
}
V_7 -> V_389 -- ;
if ( V_7 -> V_389 == 0 ) {
V_7 -> V_396 = NULL ;
F_88 ( V_7 ) ;
}
V_93:
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_327 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_398 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_33 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
V_23 = F_257 ( V_7 ) ;
args -> V_399 = V_7 -> V_30 ;
if ( V_7 -> V_124 ) {
F_328 ( V_400 > 16 ) ;
args -> V_399 |= F_114 ( V_7 -> V_124 ) << 16 ;
}
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_329 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_131 )
{
return F_322 ( V_2 , V_131 ) ;
}
int
F_330 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_131 )
{
struct V_401 * args = V_31 ;
struct V_6 * V_7 ;
int V_23 ;
switch ( args -> V_205 ) {
case V_210 :
case V_206 :
break;
default:
return - V_40 ;
}
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = F_75 ( F_76 ( V_2 , V_131 , args -> V_53 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_23 = - V_95 ;
goto V_96;
}
if ( V_7 -> V_46 ) {
V_23 = - V_40 ;
goto V_93;
}
if ( V_7 -> V_205 != V_209 )
V_7 -> V_205 = args -> V_205 ;
if ( F_175 ( V_7 ) && V_7 -> V_211 == NULL )
F_172 ( V_7 ) ;
args -> V_402 = V_7 -> V_205 != V_209 ;
V_93:
F_78 ( & V_7 -> V_8 ) ;
V_96:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
void F_331 ( struct V_6 * V_7 ,
const struct V_212 * V_213 )
{
F_185 ( & V_7 -> V_215 ) ;
F_185 ( & V_7 -> V_247 ) ;
F_185 ( & V_7 -> V_403 ) ;
F_185 ( & V_7 -> V_322 ) ;
V_7 -> V_213 = V_213 ;
V_7 -> V_13 = V_14 ;
V_7 -> V_205 = V_206 ;
V_7 -> V_328 = true ;
F_6 ( V_7 -> V_8 . V_2 -> V_27 , V_7 -> V_8 . V_17 ) ;
}
struct V_6 * F_35 ( struct V_1 * V_2 ,
T_1 V_17 )
{
struct V_6 * V_7 ;
struct V_228 * V_99 ;
T_12 V_404 ;
V_7 = F_29 ( V_2 ) ;
if ( V_7 == NULL )
return NULL ;
if ( F_332 ( V_2 , & V_7 -> V_8 , V_17 ) != 0 ) {
F_31 ( V_7 ) ;
return NULL ;
}
V_404 = V_405 | V_406 ;
if ( F_333 ( V_2 ) || F_334 ( V_2 ) ) {
V_404 &= ~ V_407 ;
V_404 |= V_244 ;
}
V_99 = F_173 ( V_7 -> V_8 . V_97 ) -> V_235 ;
F_335 ( V_99 , V_404 ) ;
F_331 ( V_7 , & V_408 ) ;
V_7 -> V_8 . V_112 = V_90 ;
V_7 -> V_8 . V_89 = V_90 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_9 = V_382 ;
} else
V_7 -> V_9 = V_5 ;
F_336 ( V_7 ) ;
return V_7 ;
}
void F_337 ( struct V_172 * V_409 )
{
struct V_6 * V_7 = F_75 ( V_409 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
T_9 * V_16 = V_2 -> V_27 ;
struct V_197 * V_178 , * V_221 ;
F_150 ( V_16 ) ;
F_338 ( V_7 ) ;
if ( V_7 -> V_118 )
F_339 ( V_2 , V_7 ) ;
V_7 -> V_46 = 0 ;
F_16 ( ! F_157 ( & V_7 -> V_322 ) &&
! F_268 ( & V_7 -> V_322 ) ) ;
F_184 (vma, next, &obj->vma_list, vma_link) {
int V_23 = F_190 ( V_178 ) ;
if ( F_16 ( V_23 == - V_156 ) ) {
bool V_410 ;
V_410 = V_16 -> V_18 . V_121 ;
V_16 -> V_18 . V_121 = false ;
F_16 ( F_190 ( V_178 ) ) ;
V_16 -> V_18 . V_121 = V_410 ;
}
}
if ( V_7 -> V_380 )
F_72 ( V_7 ) ;
if ( F_16 ( V_7 -> V_214 ) )
V_7 -> V_214 = 0 ;
F_181 ( V_7 ) ;
F_167 ( V_7 ) ;
F_340 ( V_7 ) ;
F_103 ( V_7 -> V_211 ) ;
if ( V_7 -> V_8 . V_411 )
F_341 ( & V_7 -> V_8 , NULL ) ;
F_342 ( & V_7 -> V_8 ) ;
F_9 ( V_16 , V_7 -> V_8 . V_17 ) ;
F_180 ( V_7 -> V_412 ) ;
F_31 ( V_7 ) ;
F_155 ( V_16 ) ;
}
struct V_197 * F_211 ( struct V_6 * V_7 ,
struct V_257 * V_256 )
{
struct V_197 * V_178 ;
F_27 (vma, &obj->vma_list, vma_link)
if ( V_178 -> V_256 == V_256 )
return V_178 ;
return NULL ;
}
static struct V_197 * F_343 ( struct V_6 * V_7 ,
struct V_257 * V_256 )
{
struct V_197 * V_178 = F_344 ( sizeof( * V_178 ) , V_51 ) ;
if ( V_178 == NULL )
return F_297 ( - V_54 ) ;
F_185 ( & V_178 -> V_323 ) ;
F_185 ( & V_178 -> V_255 ) ;
F_185 ( & V_178 -> V_413 ) ;
V_178 -> V_256 = V_256 ;
V_178 -> V_7 = V_7 ;
if ( F_276 ( V_256 ) )
F_345 ( & V_178 -> V_323 , & V_7 -> V_322 ) ;
else
F_206 ( & V_178 -> V_323 , & V_7 -> V_322 ) ;
return V_178 ;
}
struct V_197 *
F_303 ( struct V_6 * V_7 ,
struct V_257 * V_256 )
{
struct V_197 * V_178 ;
V_178 = F_211 ( V_7 , V_256 ) ;
if ( ! V_178 )
V_178 = F_343 ( V_7 , V_256 ) ;
return V_178 ;
}
void F_270 ( struct V_197 * V_178 )
{
F_16 ( V_178 -> V_324 . V_361 ) ;
if ( ! F_157 ( & V_178 -> V_413 ) )
return;
F_182 ( & V_178 -> V_323 ) ;
F_180 ( V_178 ) ;
}
int
F_346 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
int V_23 = 0 ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_16 -> V_282 . V_283 )
goto V_365;
V_23 = F_280 ( V_2 ) ;
if ( V_23 )
goto V_365;
F_216 ( V_2 ) ;
if ( ! F_21 ( V_2 , V_35 ) )
F_192 ( V_2 ) ;
F_347 ( V_2 ) ;
F_250 ( V_2 ) ;
V_16 -> V_282 . V_283 = ! F_21 ( V_2 ,
V_35 ) ;
F_25 ( & V_2 -> V_29 ) ;
F_348 ( & V_16 -> V_28 . V_414 ) ;
F_227 ( & V_16 -> V_18 . V_284 ) ;
F_227 ( & V_16 -> V_18 . V_148 ) ;
return 0 ;
V_365:
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int F_349 ( struct V_123 * V_124 , int V_415 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
T_9 * V_16 = V_2 -> V_27 ;
T_4 V_416 = V_417 + ( V_415 * 0x200 ) ;
T_4 * V_418 = V_16 -> V_419 . V_418 [ V_415 ] ;
int V_227 , V_23 ;
if ( ! F_350 ( V_2 ) || ! V_418 )
return 0 ;
V_23 = F_351 ( V_124 , V_420 / 4 * 3 ) ;
if ( V_23 )
return V_23 ;
for ( V_227 = 0 ; V_227 < V_420 ; V_227 += 4 ) {
F_352 ( V_124 , F_353 ( 1 ) ) ;
F_352 ( V_124 , V_416 + V_227 ) ;
F_352 ( V_124 , V_418 [ V_227 / 4 ] ) ;
}
F_354 ( V_124 ) ;
return V_23 ;
}
void F_355 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
if ( F_22 ( V_2 ) -> V_41 < 5 ||
V_16 -> V_18 . V_421 == V_422 )
return;
F_283 ( V_423 , F_356 ( V_423 ) |
V_424 ) ;
if ( F_357 ( V_2 ) )
return;
F_283 ( V_425 , F_356 ( V_425 ) | V_426 ) ;
if ( F_358 ( V_2 ) )
F_283 ( V_427 , F_359 ( V_428 ) ) ;
else if ( F_360 ( V_2 ) )
F_283 ( V_427 , F_359 ( V_429 ) ) ;
else if ( F_361 ( V_2 ) )
F_283 ( V_430 , F_359 ( V_431 ) ) ;
else
F_292 () ;
}
static bool
F_362 ( struct V_1 * V_2 )
{
if ( ! F_363 ( V_2 ) )
return false ;
if ( F_358 ( V_2 ) && V_2 -> V_432 -> V_433 < 8 ) {
F_364 ( L_27
L_28 ) ;
return false ;
}
return true ;
}
static int F_365 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
V_23 = F_366 ( V_2 ) ;
if ( V_23 )
return V_23 ;
if ( F_367 ( V_2 ) ) {
V_23 = F_368 ( V_2 ) ;
if ( V_23 )
goto V_434;
}
if ( F_362 ( V_2 ) ) {
V_23 = F_369 ( V_2 ) ;
if ( V_23 )
goto V_435;
}
if ( F_370 ( V_2 ) ) {
V_23 = F_371 ( V_2 ) ;
if ( V_23 )
goto V_436;
}
V_23 = F_219 ( V_2 , ( ( T_4 ) ~ 0 - 0x1000 ) ) ;
if ( V_23 )
goto V_437;
return 0 ;
V_437:
F_372 ( & V_16 -> V_124 [ V_438 ] ) ;
V_436:
F_372 ( & V_16 -> V_124 [ V_439 ] ) ;
V_435:
F_372 ( & V_16 -> V_124 [ V_440 ] ) ;
V_434:
F_372 ( & V_16 -> V_124 [ V_441 ] ) ;
return V_23 ;
}
int
F_373 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
int V_23 , V_227 ;
if ( F_22 ( V_2 ) -> V_41 < 6 && ! F_374 () )
return - V_26 ;
if ( V_16 -> V_442 )
F_283 ( V_443 , F_356 ( V_443 ) | F_375 ( 0xf ) ) ;
if ( F_376 ( V_2 ) )
F_283 ( V_444 , F_377 ( V_2 ) ?
V_445 : V_446 ) ;
if ( F_378 ( V_2 ) ) {
T_4 V_447 = F_356 ( V_448 ) ;
V_447 &= ~ ( V_449 | V_450 ) ;
F_283 ( V_448 , V_447 ) ;
}
F_355 ( V_2 ) ;
V_23 = F_365 ( V_2 ) ;
if ( V_23 )
return V_23 ;
for ( V_227 = 0 ; V_227 < F_379 ( V_2 ) ; V_227 ++ )
F_349 ( & V_16 -> V_124 [ V_441 ] , V_227 ) ;
V_23 = F_380 ( V_2 ) ;
if ( V_23 ) {
F_250 ( V_2 ) ;
F_13 ( L_29 , V_23 ) ;
return V_23 ;
}
if ( V_16 -> V_18 . V_327 ) {
V_23 = V_16 -> V_18 . V_327 -> V_350 ( V_2 ) ;
if ( V_23 ) {
F_381 ( V_2 ) ;
F_364 ( L_30 ) ;
}
}
return 0 ;
}
int F_382 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
F_23 ( & V_2 -> V_29 ) ;
if ( F_383 ( V_2 ) ) {
F_283 ( V_451 , 1 ) ;
if ( F_384 ( ( F_356 ( V_452 ) & 1 ) == 1 , 10 ) )
F_385 ( L_31 ) ;
}
F_386 ( V_2 ) ;
V_23 = F_373 ( V_2 ) ;
F_25 ( & V_2 -> V_29 ) ;
if ( V_23 ) {
F_381 ( V_2 ) ;
return V_23 ;
}
if ( ! F_21 ( V_2 , V_35 ) )
V_16 -> V_453 . V_454 = 1 ;
return 0 ;
}
void
F_250 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_123 * V_124 ;
int V_227 ;
F_214 (ring, dev_priv, i)
F_372 ( V_124 ) ;
}
int
F_387 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_131 )
{
struct V_15 * V_16 = V_2 -> V_27 ;
int V_23 ;
if ( F_21 ( V_2 , V_35 ) )
return 0 ;
if ( F_100 ( & V_16 -> V_28 ) ) {
F_13 ( L_32 ) ;
F_388 ( & V_16 -> V_28 . V_133 , 0 ) ;
}
F_23 ( & V_2 -> V_29 ) ;
V_16 -> V_282 . V_283 = 0 ;
V_23 = F_373 ( V_2 ) ;
if ( V_23 != 0 ) {
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
F_103 ( ! F_157 ( & V_16 -> V_42 . V_8 . V_198 ) ) ;
F_25 ( & V_2 -> V_29 ) ;
V_23 = F_389 ( V_2 ) ;
if ( V_23 )
goto V_455;
return 0 ;
V_455:
F_23 ( & V_2 -> V_29 ) ;
F_250 ( V_2 ) ;
V_16 -> V_282 . V_283 = 1 ;
F_25 ( & V_2 -> V_29 ) ;
return V_23 ;
}
int
F_390 ( struct V_1 * V_2 , void * V_31 ,
struct V_32 * V_131 )
{
if ( F_21 ( V_2 , V_35 ) )
return 0 ;
F_391 ( V_2 ) ;
return F_346 ( V_2 ) ;
}
void
F_392 ( struct V_1 * V_2 )
{
int V_23 ;
if ( F_21 ( V_2 , V_35 ) )
return;
V_23 = F_346 ( V_2 ) ;
if ( V_23 )
F_13 ( L_33 , V_23 ) ;
}
static void
F_393 ( struct V_123 * V_124 )
{
F_185 ( & V_124 -> V_198 ) ;
F_185 ( & V_124 -> V_278 ) ;
}
static void F_394 ( struct V_15 * V_16 ,
struct V_257 * V_256 )
{
V_256 -> V_2 = V_16 -> V_2 ;
F_185 ( & V_256 -> V_198 ) ;
F_185 ( & V_256 -> V_259 ) ;
F_185 ( & V_256 -> V_456 ) ;
F_345 ( & V_256 -> V_456 , & V_16 -> V_457 ) ;
}
void
F_395 ( struct V_1 * V_2 )
{
T_9 * V_16 = V_2 -> V_27 ;
int V_227 ;
V_16 -> V_50 =
F_396 ( L_34 ,
sizeof( struct V_6 ) , 0 ,
V_458 ,
NULL ) ;
F_185 ( & V_16 -> V_457 ) ;
F_394 ( V_16 , & V_16 -> V_42 . V_8 ) ;
F_185 ( & V_16 -> V_459 ) ;
F_185 ( & V_16 -> V_18 . V_246 ) ;
F_185 ( & V_16 -> V_18 . V_223 ) ;
F_185 ( & V_16 -> V_18 . V_254 ) ;
for ( V_227 = 0 ; V_227 < V_400 ; V_227 ++ )
F_393 ( & V_16 -> V_124 [ V_227 ] ) ;
for ( V_227 = 0 ; V_227 < V_460 ; V_227 ++ )
F_185 ( & V_16 -> V_252 [ V_227 ] . V_253 ) ;
F_397 ( & V_16 -> V_18 . V_284 ,
F_252 ) ;
F_397 ( & V_16 -> V_18 . V_148 ,
F_255 ) ;
F_398 ( & V_16 -> V_28 . V_24 ) ;
if ( F_399 ( V_2 ) ) {
F_283 ( V_461 ,
F_359 ( V_462 ) ) ;
}
V_16 -> V_463 = V_464 ;
if ( ! F_21 ( V_2 , V_35 ) )
V_16 -> V_352 = 3 ;
if ( F_22 ( V_2 ) -> V_41 >= 7 && ! F_383 ( V_2 ) )
V_16 -> V_306 = 32 ;
else if ( F_22 ( V_2 ) -> V_41 >= 4 || F_400 ( V_2 ) || F_401 ( V_2 ) || F_161 ( V_2 ) )
V_16 -> V_306 = 16 ;
else
V_16 -> V_306 = 8 ;
F_185 ( & V_16 -> V_18 . V_254 ) ;
F_246 ( V_2 ) ;
F_402 ( V_2 ) ;
F_398 ( & V_16 -> V_465 ) ;
V_16 -> V_18 . V_121 = true ;
V_16 -> V_18 . V_466 . V_467 = V_468 ;
V_16 -> V_18 . V_466 . V_469 = V_470 ;
V_16 -> V_18 . V_466 . V_471 = V_472 ;
F_403 ( & V_16 -> V_18 . V_466 ) ;
}
static int F_404 ( struct V_1 * V_2 ,
int V_128 , int V_17 , int V_473 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_474 * V_118 ;
int V_23 ;
if ( V_16 -> V_18 . V_475 [ V_128 - 1 ] || ! V_17 )
return 0 ;
V_118 = F_344 ( sizeof( * V_118 ) , V_51 ) ;
if ( ! V_118 )
return - V_54 ;
V_118 -> V_128 = V_128 ;
V_118 -> V_53 = F_405 ( V_2 , V_17 , V_473 ) ;
if ( ! V_118 -> V_53 ) {
V_23 = - V_54 ;
goto V_476;
}
#ifdef F_406
F_407 ( ( unsigned long ) V_118 -> V_53 -> V_75 , V_118 -> V_53 -> V_17 / V_39 ) ;
#endif
V_16 -> V_18 . V_475 [ V_128 - 1 ] = V_118 ;
return 0 ;
V_476:
F_180 ( V_118 ) ;
return V_23 ;
}
static void F_408 ( struct V_1 * V_2 , int V_128 )
{
T_9 * V_16 = V_2 -> V_27 ;
struct V_474 * V_118 ;
if ( ! V_16 -> V_18 . V_475 [ V_128 - 1 ] )
return;
V_118 = V_16 -> V_18 . V_475 [ V_128 - 1 ] ;
if ( V_118 -> V_477 ) {
F_339 ( V_2 , V_118 -> V_477 ) ;
}
#ifdef F_406
F_409 ( ( unsigned long ) V_118 -> V_53 -> V_75 , V_118 -> V_53 -> V_17 / V_39 ) ;
#endif
F_410 ( V_2 , V_118 -> V_53 ) ;
F_180 ( V_118 ) ;
V_16 -> V_18 . V_475 [ V_128 - 1 ] = NULL ;
}
void F_411 ( struct V_1 * V_2 )
{
int V_227 ;
for ( V_227 = V_478 ; V_227 <= V_479 ; V_227 ++ )
F_408 ( V_2 , V_227 ) ;
}
void F_339 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_228 * V_99 = F_173 ( V_7 -> V_8 . V_97 ) -> V_235 ;
char * V_75 ;
int V_227 ;
int V_226 ;
if ( ! V_7 -> V_118 )
return;
V_75 = V_7 -> V_118 -> V_53 -> V_75 ;
V_226 = V_7 -> V_8 . V_17 / V_39 ;
for ( V_227 = 0 ; V_227 < V_226 ; V_227 ++ ) {
struct V_69 * V_69 = F_412 ( V_99 , V_227 ) ;
if ( ! F_148 ( V_69 ) ) {
char * V_480 = F_49 ( V_69 ) ;
memcpy ( V_480 , V_75 + V_227 * V_39 , V_39 ) ;
F_52 ( V_480 ) ;
F_413 ( & V_69 , 1 ) ;
F_92 ( V_69 ) ;
F_71 ( V_69 ) ;
F_178 ( V_69 ) ;
}
}
F_94 ( V_2 ) ;
V_7 -> V_118 -> V_477 = NULL ;
V_7 -> V_118 = NULL ;
}
int
F_414 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_128 ,
int V_473 )
{
struct V_228 * V_99 = F_173 ( V_7 -> V_8 . V_97 ) -> V_235 ;
T_9 * V_16 = V_2 -> V_27 ;
int V_23 = 0 ;
int V_226 ;
int V_227 ;
if ( V_128 > V_479 )
return - V_40 ;
if ( V_7 -> V_118 ) {
if ( V_7 -> V_118 -> V_128 == V_128 )
return 0 ;
F_339 ( V_2 , V_7 ) ;
}
if ( ! V_16 -> V_18 . V_475 [ V_128 - 1 ] ) {
V_23 = F_404 ( V_2 , V_128 ,
V_7 -> V_8 . V_17 , V_473 ) ;
if ( V_23 ) {
F_13 ( L_35 ,
V_128 , V_7 -> V_8 . V_17 ) ;
return V_23 ;
}
}
V_7 -> V_118 = V_16 -> V_18 . V_475 [ V_128 - 1 ] ;
V_7 -> V_118 -> V_477 = V_7 ;
V_226 = V_7 -> V_8 . V_17 / V_39 ;
for ( V_227 = 0 ; V_227 < V_226 ; V_227 ++ ) {
struct V_69 * V_69 ;
char * V_480 , * V_481 ;
V_69 = F_412 ( V_99 , V_227 ) ;
if ( F_148 ( V_69 ) )
return F_205 ( V_69 ) ;
V_481 = F_49 ( V_69 ) ;
V_480 = V_7 -> V_118 -> V_53 -> V_75 + ( V_227 * V_39 ) ;
memcpy ( V_480 , V_481 , V_39 ) ;
F_52 ( V_481 ) ;
F_71 ( V_69 ) ;
F_178 ( V_69 ) ;
}
return 0 ;
}
static int
F_98 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_105 * args ,
struct V_32 * V_131 )
{
void * V_75 = V_7 -> V_118 -> V_53 -> V_75 + args -> V_83 ;
char T_5 * V_72 = F_60 ( args -> V_88 ) ;
if ( F_81 ( V_75 , V_72 , args -> V_17 ) ) {
unsigned long V_103 ;
F_25 ( & V_2 -> V_29 ) ;
V_103 = F_415 ( V_75 , V_72 , args -> V_17 ) ;
F_23 ( & V_2 -> V_29 ) ;
if ( V_103 )
return - V_76 ;
}
F_94 ( V_2 ) ;
return 0 ;
}
void F_416 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_130 * V_131 = V_33 -> V_166 ;
F_227 ( & V_131 -> V_18 . V_148 ) ;
F_7 ( & V_131 -> V_18 . V_280 ) ;
while ( ! F_157 ( & V_131 -> V_18 . V_278 ) ) {
struct V_265 * V_266 ;
V_266 = F_186 ( & V_131 -> V_18 . V_278 ,
struct V_265 ,
V_281 ) ;
F_182 ( & V_266 -> V_281 ) ;
V_266 -> V_131 = NULL ;
}
F_8 ( & V_131 -> V_18 . V_280 ) ;
}
static void
F_417 ( struct V_310 * V_311 )
{
struct V_130 * V_131 =
F_253 ( V_311 , F_187 ( * V_131 ) , V_18 . V_148 . V_311 ) ;
F_388 ( & V_131 -> V_132 , false ) ;
}
int F_418 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_130 * V_131 ;
F_385 ( L_36 ) ;
V_131 = F_344 ( sizeof( * V_131 ) , V_51 ) ;
if ( ! V_131 )
return - V_54 ;
V_33 -> V_166 = V_131 ;
V_131 -> V_16 = V_2 -> V_27 ;
F_419 ( & V_131 -> V_18 . V_280 ) ;
F_185 ( & V_131 -> V_18 . V_278 ) ;
F_397 ( & V_131 -> V_18 . V_148 ,
F_417 ) ;
F_420 ( & V_131 -> V_482 ) ;
return 0 ;
}
static bool F_421 ( struct V_483 * V_483 , struct V_127 * V_484 )
{
if ( ! F_104 ( V_483 ) )
return false ;
#if F_422 ( V_485 ) || F_422 ( V_486 )
return V_483 -> V_487 == V_484 ;
#else
return false ;
#endif
}
static unsigned long
V_470 ( struct V_488 * V_488 , struct V_489 * V_490 )
{
struct V_15 * V_16 =
F_253 ( V_488 ,
struct V_15 ,
V_18 . V_466 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_6 * V_7 ;
bool V_96 = true ;
unsigned long V_222 ;
if ( ! F_254 ( & V_2 -> V_29 ) ) {
if ( ! F_421 ( & V_2 -> V_29 , V_155 ) )
return 0 ;
if ( V_16 -> V_18 . V_203 )
return 0 ;
V_96 = false ;
}
V_222 = 0 ;
F_27 (obj, &dev_priv->mm.unbound_list, global_list)
if ( V_7 -> V_214 == 0 )
V_222 += V_7 -> V_8 . V_17 >> V_188 ;
F_27 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_7 -> V_30 )
continue;
if ( V_7 -> V_46 == 0 && V_7 -> V_214 == 0 )
V_222 += V_7 -> V_8 . V_17 >> V_188 ;
}
if ( V_96 )
F_25 ( & V_2 -> V_29 ) ;
return V_222 ;
}
unsigned long F_233 ( struct V_6 * V_491 ,
struct V_257 * V_256 )
{
struct V_15 * V_16 = V_491 -> V_8 . V_2 -> V_27 ;
struct V_197 * V_178 ;
if ( V_256 == & V_16 -> V_18 . V_327 -> V_8 )
V_256 = & V_16 -> V_42 . V_8 ;
F_103 ( F_157 ( & V_491 -> V_322 ) ) ;
F_27 (vma, &o->vma_list, vma_link) {
if ( V_178 -> V_256 == V_256 )
return V_178 -> V_324 . V_79 ;
}
return - 1 ;
}
bool F_324 ( struct V_6 * V_491 ,
struct V_257 * V_256 )
{
struct V_197 * V_178 ;
F_27 (vma, &o->vma_list, vma_link)
if ( V_178 -> V_256 == V_256 && F_269 ( & V_178 -> V_324 ) )
return true ;
return false ;
}
bool F_19 ( struct V_6 * V_491 )
{
struct V_197 * V_178 ;
F_27 (vma, &o->vma_list, vma_link)
if ( F_269 ( & V_178 -> V_324 ) )
return true ;
return false ;
}
unsigned long F_423 ( struct V_6 * V_491 ,
struct V_257 * V_256 )
{
struct V_15 * V_16 = V_491 -> V_8 . V_2 -> V_27 ;
struct V_197 * V_178 ;
if ( V_256 == & V_16 -> V_18 . V_327 -> V_8 )
V_256 = & V_16 -> V_42 . V_8 ;
F_103 ( F_157 ( & V_491 -> V_322 ) ) ;
F_27 (vma, &o->vma_list, vma_link)
if ( V_178 -> V_256 == V_256 )
return V_178 -> V_324 . V_17 ;
return 0 ;
}
static unsigned long
V_468 ( struct V_488 * V_488 , struct V_489 * V_490 )
{
struct V_15 * V_16 =
F_253 ( V_488 ,
struct V_15 ,
V_18 . V_466 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_225 ;
bool V_96 = true ;
if ( ! F_254 ( & V_2 -> V_29 ) ) {
if ( ! F_421 ( & V_2 -> V_29 , V_155 ) )
return V_492 ;
if ( V_16 -> V_18 . V_203 )
return V_492 ;
V_96 = false ;
}
V_225 = F_165 ( V_16 , V_490 -> V_493 ) ;
if ( V_225 < V_490 -> V_493 )
V_225 += F_183 ( V_16 ,
V_490 -> V_493 - V_225 ,
false ) ;
if ( V_225 < V_490 -> V_493 )
V_225 += F_166 ( V_16 ) ;
if ( V_96 )
F_25 ( & V_2 -> V_29 ) ;
return V_225 ;
}
struct V_197 * F_312 ( struct V_6 * V_7 )
{
struct V_197 * V_178 ;
if ( F_16 ( F_157 ( & V_7 -> V_322 ) ) )
return NULL ;
V_178 = F_186 ( & V_7 -> V_322 , F_187 ( * V_178 ) , V_323 ) ;
if ( F_16 ( V_178 -> V_256 != F_424 ( V_7 ) ) )
return NULL ;
return V_178 ;
}

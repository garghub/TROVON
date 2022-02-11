static inline void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_2 ( V_2 ) ;
V_2 -> V_4 = false ;
V_2 -> V_5 = V_6 ;
}
static void F_3 ( struct V_7 * V_8 ,
T_1 V_9 )
{
V_8 -> V_10 . V_11 ++ ;
V_8 -> V_10 . V_12 += V_9 ;
}
static void F_4 ( struct V_7 * V_8 ,
T_1 V_9 )
{
V_8 -> V_10 . V_11 -- ;
V_8 -> V_10 . V_12 -= V_9 ;
}
static int
F_5 ( struct V_13 * error )
{
int V_14 ;
#define F_6 (!i915_reset_in_progress(error))
if ( F_6 )
return 0 ;
if ( F_7 ( error ) )
return - V_15 ;
V_14 = F_8 ( error -> V_16 ,
F_6 ,
10 * V_17 ) ;
if ( V_14 == 0 ) {
F_9 ( L_1 ) ;
return - V_15 ;
} else if ( V_14 < 0 ) {
return V_14 ;
}
#undef F_6
return 0 ;
}
int F_10 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
int V_14 ;
V_14 = F_5 ( & V_8 -> V_21 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_11 ( & V_19 -> V_22 ) ;
if ( V_14 )
return V_14 ;
F_12 ( F_13 ( V_19 ) ) ;
return 0 ;
}
static inline bool
F_14 ( struct V_1 * V_2 )
{
return V_2 -> V_23 && ! V_2 -> V_24 ;
}
int
F_15 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_28 * args = V_25 ;
if ( F_16 ( V_19 , V_29 ) )
return - V_30 ;
if ( args -> V_31 >= args -> V_32 ||
( args -> V_32 | args -> V_31 ) & ( V_33 - 1 ) )
return - V_34 ;
if ( F_17 ( V_19 ) -> V_35 >= 5 )
return - V_30 ;
F_18 ( & V_19 -> V_22 ) ;
F_19 ( V_19 , args -> V_31 , args -> V_32 ,
args -> V_32 ) ;
V_8 -> V_36 . V_37 = args -> V_32 ;
F_20 ( & V_19 -> V_22 ) ;
return 0 ;
}
int
F_21 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_38 * args = V_25 ;
struct V_1 * V_2 ;
T_1 V_39 ;
V_39 = 0 ;
F_18 ( & V_19 -> V_22 ) ;
F_22 (obj, &dev_priv->mm.bound_list, gtt_list)
if ( V_2 -> V_40 )
V_39 += V_2 -> V_23 -> V_9 ;
F_20 ( & V_19 -> V_22 ) ;
args -> V_41 = V_8 -> V_36 . V_42 ;
args -> V_43 = args -> V_41 - V_39 ;
return 0 ;
}
void * F_23 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
return F_24 ( V_8 -> V_44 , V_45 | V_46 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
F_26 ( V_8 -> V_44 , V_2 ) ;
}
static int
F_27 ( struct V_26 * V_27 ,
struct V_18 * V_19 ,
T_2 V_9 ,
T_3 * V_48 )
{
struct V_1 * V_2 ;
int V_14 ;
T_4 V_49 ;
V_9 = F_28 ( V_9 , V_33 ) ;
if ( V_9 == 0 )
return - V_34 ;
V_2 = F_29 ( V_19 , V_9 ) ;
if ( V_2 == NULL )
return - V_50 ;
V_14 = F_30 ( V_27 , & V_2 -> V_47 , & V_49 ) ;
if ( V_14 ) {
F_31 ( & V_2 -> V_47 ) ;
F_4 ( V_19 -> V_20 , V_2 -> V_47 . V_9 ) ;
F_25 ( V_2 ) ;
return V_14 ;
}
F_32 ( & V_2 -> V_47 ) ;
F_33 ( V_2 ) ;
* V_48 = V_49 ;
return 0 ;
}
int
F_34 ( struct V_26 * V_27 ,
struct V_18 * V_19 ,
struct V_51 * args )
{
args -> V_52 = F_35 ( args -> V_53 * ( ( args -> V_54 + 7 ) / 8 ) , 64 ) ;
args -> V_9 = args -> V_52 * args -> V_55 ;
return F_27 ( V_27 , V_19 ,
args -> V_9 , & args -> V_49 ) ;
}
int F_36 ( struct V_26 * V_27 ,
struct V_18 * V_19 ,
T_3 V_49 )
{
return F_37 ( V_27 , V_49 ) ;
}
int
F_38 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_56 * args = V_25 ;
return F_27 ( V_27 , V_19 ,
args -> V_9 , & args -> V_49 ) ;
}
static inline int
F_39 ( char T_5 * V_57 ,
const char * V_58 , int V_59 ,
int V_60 )
{
int V_14 , V_61 = 0 ;
while ( V_60 > 0 ) {
int V_62 = F_35 ( V_59 + 1 , 64 ) ;
int V_63 = F_40 ( V_62 - V_59 , V_60 ) ;
int V_64 = V_59 ^ 64 ;
V_14 = F_41 ( V_57 + V_61 ,
V_58 + V_64 ,
V_63 ) ;
if ( V_14 )
return V_14 + V_60 ;
V_61 += V_63 ;
V_59 += V_63 ;
V_60 -= V_63 ;
}
return 0 ;
}
static inline int
F_42 ( char * V_58 , int V_59 ,
const char T_5 * V_57 ,
int V_60 )
{
int V_14 , V_61 = 0 ;
while ( V_60 > 0 ) {
int V_62 = F_35 ( V_59 + 1 , 64 ) ;
int V_63 = F_40 ( V_62 - V_59 , V_60 ) ;
int V_64 = V_59 ^ 64 ;
V_14 = F_43 ( V_58 + V_64 ,
V_57 + V_61 ,
V_63 ) ;
if ( V_14 )
return V_14 + V_60 ;
V_61 += V_63 ;
V_59 += V_63 ;
V_60 -= V_63 ;
}
return 0 ;
}
static int
F_44 ( struct V_65 * V_65 , int V_66 , int V_67 ,
char T_5 * V_68 ,
bool V_69 , bool V_70 )
{
char * V_71 ;
int V_14 ;
if ( F_45 ( V_69 ) )
return - V_34 ;
V_71 = F_46 ( V_65 ) ;
if ( V_70 )
F_47 ( V_71 + V_66 ,
V_67 ) ;
V_14 = F_48 ( V_68 ,
V_71 + V_66 ,
V_67 ) ;
F_49 ( V_71 ) ;
return V_14 ? - V_72 : 0 ;
}
static void
F_50 ( char * V_73 , unsigned long V_60 ,
bool V_74 )
{
if ( F_45 ( V_74 ) ) {
unsigned long V_75 = ( unsigned long ) V_73 ;
unsigned long V_76 = ( unsigned long ) V_73 + V_60 ;
V_75 = F_51 ( V_75 , 128 ) ;
V_76 = F_52 ( V_76 , 128 ) ;
F_47 ( ( void * ) V_75 , V_76 - V_75 ) ;
} else {
F_47 ( V_73 , V_60 ) ;
}
}
static int
F_53 ( struct V_65 * V_65 , int V_66 , int V_67 ,
char T_5 * V_68 ,
bool V_69 , bool V_70 )
{
char * V_71 ;
int V_14 ;
V_71 = F_54 ( V_65 ) ;
if ( V_70 )
F_50 ( V_71 + V_66 ,
V_67 ,
V_69 ) ;
if ( V_69 )
V_14 = F_39 ( V_68 ,
V_71 , V_66 ,
V_67 ) ;
else
V_14 = F_41 ( V_68 ,
V_71 + V_66 ,
V_67 ) ;
F_55 ( V_65 ) ;
return V_14 ? - V_72 : 0 ;
}
static int
F_56 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_77 * args ,
struct V_26 * V_27 )
{
char T_5 * V_68 ;
T_6 V_78 ;
T_7 V_79 ;
int V_66 , V_67 , V_14 = 0 ;
int V_80 , V_69 ;
int V_81 = 0 ;
int V_70 = 0 ;
struct V_82 * V_83 ;
int V_84 ;
V_68 = ( char T_5 * ) ( V_85 ) args -> V_86 ;
V_78 = args -> V_9 ;
V_80 = F_57 ( V_2 ) ;
if ( ! ( V_2 -> V_47 . V_87 & V_88 ) ) {
if ( V_2 -> V_89 == V_90 )
V_70 = 1 ;
if ( V_2 -> V_23 ) {
V_14 = F_58 ( V_2 , false ) ;
if ( V_14 )
return V_14 ;
}
}
V_14 = F_59 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_60 ( V_2 ) ;
V_79 = args -> V_79 ;
F_61 (obj->pages->sgl, sg, obj->pages->nents, i) {
struct V_65 * V_65 ;
if ( V_84 < V_79 > > V_91 )
continue;
if ( V_78 <= 0 )
break;
V_66 = F_62 ( V_79 ) ;
V_67 = V_78 ;
if ( ( V_66 + V_67 ) > V_33 )
V_67 = V_33 - V_66 ;
V_65 = F_63 ( V_83 ) ;
V_69 = V_80 &&
( F_64 ( V_65 ) & ( 1 << 17 ) ) != 0 ;
V_14 = F_44 ( V_65 , V_66 , V_67 ,
V_68 , V_69 ,
V_70 ) ;
if ( V_14 == 0 )
goto V_92;
F_20 ( & V_19 -> V_22 ) ;
if ( ! V_81 ) {
V_14 = F_65 ( V_68 , V_78 ) ;
( void ) V_14 ;
V_81 = 1 ;
}
V_14 = F_53 ( V_65 , V_66 , V_67 ,
V_68 , V_69 ,
V_70 ) ;
F_18 ( & V_19 -> V_22 ) ;
V_92:
F_66 ( V_65 ) ;
if ( V_14 )
goto V_93;
V_78 -= V_67 ;
V_68 += V_67 ;
V_79 += V_67 ;
}
V_93:
F_67 ( V_2 ) ;
return V_14 ;
}
int
F_68 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_77 * args = V_25 ;
struct V_1 * V_2 ;
int V_14 = 0 ;
if ( args -> V_9 == 0 )
return 0 ;
if ( ! F_69 ( V_94 ,
( char T_5 * ) ( V_85 ) args -> V_86 ,
args -> V_9 ) )
return - V_72 ;
V_14 = F_10 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
if ( args -> V_79 > V_2 -> V_47 . V_9 ||
args -> V_9 > V_2 -> V_47 . V_9 - args -> V_79 ) {
V_14 = - V_34 ;
goto V_93;
}
if ( ! V_2 -> V_47 . V_97 ) {
V_14 = - V_34 ;
goto V_93;
}
F_72 ( V_2 , args -> V_79 , args -> V_9 ) ;
V_14 = F_56 ( V_19 , V_2 , args , V_27 ) ;
V_93:
F_32 ( & V_2 -> V_47 ) ;
V_96:
F_20 ( & V_19 -> V_22 ) ;
return V_14 ;
}
static inline int
F_73 ( struct V_98 * V_99 ,
T_7 V_100 , int V_101 ,
char T_5 * V_68 ,
int V_60 )
{
void T_8 * V_102 ;
void * V_71 ;
unsigned long V_103 ;
V_102 = F_74 ( V_99 , V_100 ) ;
V_71 = ( void V_104 * ) V_102 + V_101 ;
V_103 = F_75 ( V_71 ,
V_68 , V_60 ) ;
F_76 ( V_102 ) ;
return V_103 ;
}
static int
F_77 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_105 * args ,
struct V_26 * V_27 )
{
T_9 * V_8 = V_19 -> V_20 ;
T_6 V_78 ;
T_7 V_79 , V_100 ;
char T_5 * V_68 ;
int V_101 , V_67 , V_14 ;
V_14 = F_78 ( V_2 , 0 , true , true ) ;
if ( V_14 )
goto V_93;
V_14 = F_58 ( V_2 , true ) ;
if ( V_14 )
goto V_106;
V_14 = F_79 ( V_2 ) ;
if ( V_14 )
goto V_106;
V_68 = ( char T_5 * ) ( V_85 ) args -> V_86 ;
V_78 = args -> V_9 ;
V_79 = V_2 -> V_107 + args -> V_79 ;
while ( V_78 > 0 ) {
V_100 = V_79 & V_108 ;
V_101 = F_62 ( V_79 ) ;
V_67 = V_78 ;
if ( ( V_101 + V_78 ) > V_33 )
V_67 = V_33 - V_101 ;
if ( F_73 ( V_8 -> V_36 . V_109 , V_100 ,
V_101 , V_68 , V_67 ) ) {
V_14 = - V_72 ;
goto V_106;
}
V_78 -= V_67 ;
V_68 += V_67 ;
V_79 += V_67 ;
}
V_106:
F_80 ( V_2 ) ;
V_93:
return V_14 ;
}
static int
F_81 ( struct V_65 * V_65 , int V_66 , int V_67 ,
char T_5 * V_68 ,
bool V_69 ,
bool V_110 ,
bool V_111 )
{
char * V_71 ;
int V_14 ;
if ( F_45 ( V_69 ) )
return - V_34 ;
V_71 = F_46 ( V_65 ) ;
if ( V_110 )
F_47 ( V_71 + V_66 ,
V_67 ) ;
V_14 = F_75 ( V_71 + V_66 ,
V_68 ,
V_67 ) ;
if ( V_111 )
F_47 ( V_71 + V_66 ,
V_67 ) ;
F_49 ( V_71 ) ;
return V_14 ? - V_72 : 0 ;
}
static int
F_82 ( struct V_65 * V_65 , int V_66 , int V_67 ,
char T_5 * V_68 ,
bool V_69 ,
bool V_110 ,
bool V_111 )
{
char * V_71 ;
int V_14 ;
V_71 = F_54 ( V_65 ) ;
if ( F_45 ( V_110 || V_69 ) )
F_50 ( V_71 + V_66 ,
V_67 ,
V_69 ) ;
if ( V_69 )
V_14 = F_42 ( V_71 , V_66 ,
V_68 ,
V_67 ) ;
else
V_14 = F_43 ( V_71 + V_66 ,
V_68 ,
V_67 ) ;
if ( V_111 )
F_50 ( V_71 + V_66 ,
V_67 ,
V_69 ) ;
F_55 ( V_65 ) ;
return V_14 ? - V_72 : 0 ;
}
static int
F_83 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_105 * args ,
struct V_26 * V_27 )
{
T_6 V_78 ;
T_7 V_79 ;
char T_5 * V_68 ;
int V_66 , V_67 , V_14 = 0 ;
int V_80 , V_69 ;
int V_112 = 0 ;
int V_111 = 0 ;
int V_110 = 0 ;
int V_84 ;
struct V_82 * V_83 ;
V_68 = ( char T_5 * ) ( V_85 ) args -> V_86 ;
V_78 = args -> V_9 ;
V_80 = F_57 ( V_2 ) ;
if ( V_2 -> V_47 . V_113 != V_88 ) {
if ( V_2 -> V_89 == V_90 )
V_111 = 1 ;
if ( V_2 -> V_23 ) {
V_14 = F_58 ( V_2 , true ) ;
if ( V_14 )
return V_14 ;
}
}
if ( ! ( V_2 -> V_47 . V_87 & V_88 )
&& V_2 -> V_89 == V_90 )
V_110 = 1 ;
V_14 = F_59 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_60 ( V_2 ) ;
V_79 = args -> V_79 ;
V_2 -> V_114 = 1 ;
F_61 (obj->pages->sgl, sg, obj->pages->nents, i) {
struct V_65 * V_65 ;
int V_115 ;
if ( V_84 < V_79 > > V_91 )
continue;
if ( V_78 <= 0 )
break;
V_66 = F_62 ( V_79 ) ;
V_67 = V_78 ;
if ( ( V_66 + V_67 ) > V_33 )
V_67 = V_33 - V_66 ;
V_115 = V_110 &&
( ( V_66 | V_67 )
& ( V_116 . V_117 - 1 ) ) ;
V_65 = F_63 ( V_83 ) ;
V_69 = V_80 &&
( F_64 ( V_65 ) & ( 1 << 17 ) ) != 0 ;
V_14 = F_81 ( V_65 , V_66 , V_67 ,
V_68 , V_69 ,
V_115 ,
V_111 ) ;
if ( V_14 == 0 )
goto V_92;
V_112 = 1 ;
F_20 ( & V_19 -> V_22 ) ;
V_14 = F_82 ( V_65 , V_66 , V_67 ,
V_68 , V_69 ,
V_115 ,
V_111 ) ;
F_18 ( & V_19 -> V_22 ) ;
V_92:
F_84 ( V_65 ) ;
F_66 ( V_65 ) ;
if ( V_14 )
goto V_93;
V_78 -= V_67 ;
V_68 += V_67 ;
V_79 += V_67 ;
}
V_93:
F_67 ( V_2 ) ;
if ( V_112 ) {
if ( ! V_111 &&
V_2 -> V_47 . V_113 != V_88 ) {
F_85 ( V_2 ) ;
F_86 ( V_19 ) ;
}
}
if ( V_111 )
F_86 ( V_19 ) ;
return V_14 ;
}
int
F_87 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_105 * args = V_25 ;
struct V_1 * V_2 ;
int V_14 ;
if ( args -> V_9 == 0 )
return 0 ;
if ( ! F_69 ( V_118 ,
( char T_5 * ) ( V_85 ) args -> V_86 ,
args -> V_9 ) )
return - V_72 ;
V_14 = F_88 ( ( char T_5 * ) ( V_85 ) args -> V_86 ,
args -> V_9 ) ;
if ( V_14 )
return - V_72 ;
V_14 = F_10 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
if ( args -> V_79 > V_2 -> V_47 . V_9 ||
args -> V_9 > V_2 -> V_47 . V_9 - args -> V_79 ) {
V_14 = - V_34 ;
goto V_93;
}
if ( ! V_2 -> V_47 . V_97 ) {
V_14 = - V_34 ;
goto V_93;
}
F_89 ( V_2 , args -> V_79 , args -> V_9 ) ;
V_14 = - V_72 ;
if ( V_2 -> V_119 ) {
V_14 = F_90 ( V_19 , V_2 , args , V_27 ) ;
goto V_93;
}
if ( V_2 -> V_89 == V_90 &&
V_2 -> V_3 == V_120 &&
V_2 -> V_47 . V_113 != V_88 ) {
V_14 = F_77 ( V_19 , V_2 , args , V_27 ) ;
}
if ( V_14 == - V_72 || V_14 == - V_121 )
V_14 = F_83 ( V_19 , V_2 , args , V_27 ) ;
V_93:
F_32 ( & V_2 -> V_47 ) ;
V_96:
F_20 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_91 ( struct V_13 * error ,
bool V_122 )
{
if ( F_92 ( error ) ) {
if ( ! V_122 )
return - V_15 ;
if ( F_7 ( error ) )
return - V_15 ;
return - V_123 ;
}
return 0 ;
}
static int
F_93 ( struct V_124 * V_125 , T_4 V_126 )
{
int V_14 ;
F_94 ( ! F_95 ( & V_125 -> V_19 -> V_22 ) ) ;
V_14 = 0 ;
if ( V_126 == V_125 -> V_127 )
V_14 = F_96 ( V_125 , NULL , NULL ) ;
return V_14 ;
}
static int F_97 ( struct V_124 * V_125 , T_4 V_126 ,
unsigned V_128 ,
bool V_122 , struct V_129 * V_130 )
{
T_9 * V_8 = V_125 -> V_19 -> V_20 ;
struct V_129 V_131 , V_132 , V_133 = { 1 , 0 } ;
unsigned long V_134 ;
long V_76 ;
bool V_135 = true ;
int V_14 ;
if ( F_98 ( V_125 -> V_136 ( V_125 , true ) , V_126 ) )
return 0 ;
F_99 ( V_125 , V_126 ) ;
if ( V_130 != NULL ) {
V_133 = * V_130 ;
V_135 = false ;
}
V_134 = F_100 ( & V_133 ) ;
if ( F_12 ( ! V_125 -> V_137 ( V_125 ) ) )
return - V_30 ;
F_101 ( & V_131 ) ;
#define F_6 \
(i915_seqno_passed(ring->get_seqno(ring, false), seqno) || \
i915_reset_in_progress(&dev_priv->gpu_error) || \
reset_counter != atomic_read(&dev_priv->gpu_error.reset_counter))
do {
if ( V_122 )
V_76 = F_8 ( V_125 -> V_138 ,
F_6 ,
V_134 ) ;
else
V_76 = F_102 ( V_125 -> V_138 , F_6 ,
V_134 ) ;
if ( V_128 != F_103 ( & V_8 -> V_21 . V_128 ) )
V_76 = - V_123 ;
V_14 = F_91 ( & V_8 -> V_21 , V_122 ) ;
if ( V_14 )
V_76 = V_14 ;
} while ( V_76 == 0 && V_135 );
F_101 ( & V_132 ) ;
V_125 -> V_139 ( V_125 ) ;
F_104 ( V_125 , V_126 ) ;
#undef F_6
if ( V_130 ) {
struct V_129 V_140 = F_105 ( V_132 , V_131 ) ;
* V_130 = F_105 ( * V_130 , V_140 ) ;
}
switch ( V_76 ) {
case - V_15 :
case - V_123 :
case - V_141 :
return ( int ) V_76 ;
case 0 :
if ( V_130 )
F_106 ( V_130 , 0 , 0 ) ;
return - V_142 ;
default:
F_12 ( V_76 < 0 ) ;
return 0 ;
}
}
int
F_107 ( struct V_124 * V_125 , T_3 V_126 )
{
struct V_18 * V_19 = V_125 -> V_19 ;
struct V_7 * V_8 = V_19 -> V_20 ;
bool V_122 = V_8 -> V_10 . V_122 ;
int V_14 ;
F_94 ( ! F_95 ( & V_19 -> V_22 ) ) ;
F_94 ( V_126 == 0 ) ;
V_14 = F_91 ( & V_8 -> V_21 , V_122 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_93 ( V_125 , V_126 ) ;
if ( V_14 )
return V_14 ;
return F_97 ( V_125 , V_126 ,
F_103 ( & V_8 -> V_21 . V_128 ) ,
V_122 , NULL ) ;
}
static T_10 int
F_108 ( struct V_1 * V_2 ,
bool V_143 )
{
struct V_124 * V_125 = V_2 -> V_125 ;
T_4 V_126 ;
int V_14 ;
V_126 = V_143 ? V_2 -> V_144 : V_2 -> V_145 ;
if ( V_126 == 0 )
return 0 ;
V_14 = F_107 ( V_125 , V_126 ) ;
if ( V_14 )
return V_14 ;
F_109 ( V_125 ) ;
if ( V_2 -> V_144 &&
F_98 ( V_126 , V_2 -> V_144 ) ) {
V_2 -> V_144 = 0 ;
V_2 -> V_47 . V_113 &= ~ V_146 ;
}
return 0 ;
}
static T_10 int
F_110 ( struct V_1 * V_2 ,
bool V_143 )
{
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_124 * V_125 = V_2 -> V_125 ;
unsigned V_128 ;
T_4 V_126 ;
int V_14 ;
F_94 ( ! F_95 ( & V_19 -> V_22 ) ) ;
F_94 ( ! V_8 -> V_10 . V_122 ) ;
V_126 = V_143 ? V_2 -> V_144 : V_2 -> V_145 ;
if ( V_126 == 0 )
return 0 ;
V_14 = F_91 ( & V_8 -> V_21 , true ) ;
if ( V_14 )
return V_14 ;
V_14 = F_93 ( V_125 , V_126 ) ;
if ( V_14 )
return V_14 ;
V_128 = F_103 ( & V_8 -> V_21 . V_128 ) ;
F_20 ( & V_19 -> V_22 ) ;
V_14 = F_97 ( V_125 , V_126 , V_128 , true , NULL ) ;
F_18 ( & V_19 -> V_22 ) ;
F_109 ( V_125 ) ;
if ( V_2 -> V_144 &&
F_98 ( V_126 , V_2 -> V_144 ) ) {
V_2 -> V_144 = 0 ;
V_2 -> V_47 . V_113 &= ~ V_146 ;
}
return V_14 ;
}
int
F_111 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_147 * args = V_25 ;
struct V_1 * V_2 ;
T_3 V_87 = args -> V_87 ;
T_3 V_113 = args -> V_113 ;
int V_14 ;
if ( V_113 & V_146 )
return - V_34 ;
if ( V_87 & V_146 )
return - V_34 ;
if ( V_113 != 0 && V_87 != V_113 )
return - V_34 ;
V_14 = F_10 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
V_14 = F_110 ( V_2 , ! V_113 ) ;
if ( V_14 )
goto V_148;
if ( V_87 & V_149 ) {
V_14 = F_58 ( V_2 , V_113 != 0 ) ;
if ( V_14 == - V_34 )
V_14 = 0 ;
} else {
V_14 = F_112 ( V_2 , V_113 != 0 ) ;
}
V_148:
F_32 ( & V_2 -> V_47 ) ;
V_96:
F_20 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_113 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_150 * args = V_25 ;
struct V_1 * V_2 ;
int V_14 = 0 ;
V_14 = F_10 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
if ( V_2 -> V_40 )
F_114 ( V_2 ) ;
F_32 ( & V_2 -> V_47 ) ;
V_96:
F_20 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_115 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_151 * args = V_25 ;
struct V_152 * V_2 ;
unsigned long V_73 ;
V_2 = F_71 ( V_19 , V_27 , args -> V_49 ) ;
if ( V_2 == NULL )
return - V_95 ;
if ( ! V_2 -> V_97 ) {
F_116 ( V_2 ) ;
return - V_34 ;
}
V_73 = F_117 ( V_2 -> V_97 , 0 , args -> V_9 ,
V_153 | V_154 , V_155 ,
args -> V_79 ) ;
F_116 ( V_2 ) ;
if ( F_118 ( ( void * ) V_73 ) )
return V_73 ;
args -> V_156 = ( T_2 ) V_73 ;
return 0 ;
}
int F_119 ( struct V_157 * V_158 , struct V_159 * V_160 )
{
struct V_1 * V_2 = F_70 ( V_158 -> V_161 ) ;
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
T_9 * V_8 = V_19 -> V_20 ;
T_11 V_101 ;
unsigned long V_162 ;
int V_14 = 0 ;
bool V_163 = ! ! ( V_160 -> V_164 & V_165 ) ;
V_101 = ( ( unsigned long ) V_160 -> V_166 - V_158 -> V_167 ) >>
V_91 ;
V_14 = F_10 ( V_19 ) ;
if ( V_14 )
goto V_93;
F_120 ( V_2 , V_101 , true , V_163 ) ;
if ( V_2 -> V_89 != V_90 && ! F_121 ( V_19 ) ) {
V_14 = - V_34 ;
goto V_96;
}
V_14 = F_78 ( V_2 , 0 , true , false ) ;
if ( V_14 )
goto V_96;
V_14 = F_58 ( V_2 , V_163 ) ;
if ( V_14 )
goto V_168;
V_14 = F_122 ( V_2 ) ;
if ( V_14 )
goto V_168;
V_2 -> V_169 = true ;
V_162 = ( ( V_8 -> V_36 . V_170 + V_2 -> V_107 ) >> V_91 ) +
V_101 ;
V_14 = F_123 ( V_158 , ( unsigned long ) V_160 -> V_166 , V_162 ) ;
V_168:
F_80 ( V_2 ) ;
V_96:
F_20 ( & V_19 -> V_22 ) ;
V_93:
switch ( V_14 ) {
case - V_15 :
if ( F_7 ( & V_8 -> V_21 ) )
return V_171 ;
case - V_123 :
F_124 () ;
case 0 :
case - V_141 :
case - V_172 :
case - V_173 :
return V_174 ;
case - V_50 :
return V_175 ;
case - V_121 :
return V_171 ;
default:
F_125 ( V_14 , L_2 , V_14 ) ;
return V_171 ;
}
}
void
F_2 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_169 )
return;
if ( V_2 -> V_47 . V_19 -> V_176 )
F_126 ( V_2 -> V_47 . V_19 -> V_176 ,
( T_7 ) V_2 -> V_47 . V_177 . V_178 . V_179 << V_91 ,
V_2 -> V_47 . V_9 , 1 ) ;
V_2 -> V_169 = false ;
}
T_3
F_127 ( struct V_18 * V_19 , T_3 V_9 , int V_3 )
{
T_3 V_180 ;
if ( F_17 ( V_19 ) -> V_35 >= 4 ||
V_3 == V_120 )
return V_9 ;
if ( F_17 ( V_19 ) -> V_35 == 3 )
V_180 = 1024 * 1024 ;
else
V_180 = 512 * 1024 ;
while ( V_180 < V_9 )
V_180 <<= 1 ;
return V_180 ;
}
T_3
F_128 ( struct V_18 * V_19 , T_3 V_9 ,
int V_3 , bool V_181 )
{
if ( F_17 ( V_19 ) -> V_35 >= 4 || ( ! V_181 && F_129 ( V_19 ) ) ||
V_3 == V_120 )
return 4096 ;
return F_127 ( V_19 , V_9 , V_3 ) ;
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
int V_14 ;
if ( V_2 -> V_47 . V_177 . V_182 )
return 0 ;
V_8 -> V_10 . V_183 = true ;
V_14 = F_131 ( & V_2 -> V_47 ) ;
if ( V_14 != - V_121 )
goto V_93;
F_132 ( V_8 , V_2 -> V_47 . V_9 >> V_91 ) ;
V_14 = F_131 ( & V_2 -> V_47 ) ;
if ( V_14 != - V_121 )
goto V_93;
F_133 ( V_8 ) ;
V_14 = F_131 ( & V_2 -> V_47 ) ;
V_93:
V_8 -> V_10 . V_183 = false ;
return V_14 ;
}
static void F_134 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_47 . V_177 . V_182 )
return;
F_135 ( & V_2 -> V_47 ) ;
}
int
F_136 ( struct V_26 * V_27 ,
struct V_18 * V_19 ,
T_3 V_49 ,
T_2 * V_79 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_1 * V_2 ;
int V_14 ;
V_14 = F_10 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
if ( V_2 -> V_47 . V_9 > V_8 -> V_36 . V_37 ) {
V_14 = - V_184 ;
goto V_93;
}
if ( V_2 -> V_185 != V_186 ) {
F_9 ( L_3 ) ;
V_14 = - V_34 ;
goto V_93;
}
V_14 = F_130 ( V_2 ) ;
if ( V_14 )
goto V_93;
* V_79 = ( V_187 ) V_2 -> V_47 . V_177 . V_178 . V_179 << V_91 ;
V_93:
F_32 ( & V_2 -> V_47 ) ;
V_96:
F_20 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_137 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_188 * args = V_25 ;
return F_136 ( V_27 , V_19 , args -> V_49 , & args -> V_79 ) ;
}
static void
F_138 ( struct V_1 * V_2 )
{
struct V_189 * V_189 ;
F_134 ( V_2 ) ;
if ( V_2 -> V_47 . V_97 == NULL )
return;
V_189 = F_139 ( V_2 -> V_47 . V_97 ) ;
F_140 ( V_189 , 0 , ( T_7 ) - 1 ) ;
V_2 -> V_185 = V_190 ;
}
static inline int
F_141 ( struct V_1 * V_2 )
{
return V_2 -> V_185 == V_191 ;
}
static void
F_142 ( struct V_1 * V_2 )
{
int V_192 = V_2 -> V_47 . V_9 / V_33 ;
struct V_82 * V_83 ;
int V_14 , V_84 ;
F_94 ( V_2 -> V_185 == V_190 ) ;
V_14 = F_112 ( V_2 , true ) ;
if ( V_14 ) {
F_12 ( V_14 != - V_15 ) ;
F_85 ( V_2 ) ;
V_2 -> V_47 . V_87 = V_2 -> V_47 . V_113 = V_88 ;
}
if ( F_57 ( V_2 ) )
F_143 ( V_2 ) ;
if ( V_2 -> V_185 == V_191 )
V_2 -> V_114 = 0 ;
F_61 (obj->pages->sgl, sg, page_count, i) {
struct V_65 * V_65 = F_63 ( V_83 ) ;
if ( V_2 -> V_114 )
F_84 ( V_65 ) ;
if ( V_2 -> V_185 == V_186 )
F_66 ( V_65 ) ;
F_144 ( V_65 ) ;
}
V_2 -> V_114 = 0 ;
F_145 ( V_2 -> V_193 ) ;
F_146 ( V_2 -> V_193 ) ;
}
int
F_147 ( struct V_1 * V_2 )
{
const struct V_194 * V_195 = V_2 -> V_195 ;
if ( V_2 -> V_193 == NULL )
return 0 ;
F_94 ( V_2 -> V_23 ) ;
if ( V_2 -> V_196 )
return - V_173 ;
F_148 ( & V_2 -> V_197 ) ;
V_195 -> V_198 ( V_2 ) ;
V_2 -> V_193 = NULL ;
if ( F_141 ( V_2 ) )
F_138 ( V_2 ) ;
return 0 ;
}
static long
F_149 ( struct V_7 * V_8 , long V_199 ,
bool V_200 )
{
struct V_1 * V_2 , * V_201 ;
long V_202 = 0 ;
F_150 (obj, next,
&dev_priv->mm.unbound_list,
gtt_list) {
if ( ( F_141 ( V_2 ) || ! V_200 ) &&
F_147 ( V_2 ) == 0 ) {
V_202 += V_2 -> V_47 . V_9 >> V_91 ;
if ( V_202 >= V_199 )
return V_202 ;
}
}
F_150 (obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if ( ( F_141 ( V_2 ) || ! V_200 ) &&
F_151 ( V_2 ) == 0 &&
F_147 ( V_2 ) == 0 ) {
V_202 += V_2 -> V_47 . V_9 >> V_91 ;
if ( V_202 >= V_199 )
return V_202 ;
}
}
return V_202 ;
}
static long
F_132 ( struct V_7 * V_8 , long V_199 )
{
return F_149 ( V_8 , V_199 , true ) ;
}
static void
F_133 ( struct V_7 * V_8 )
{
struct V_1 * V_2 , * V_201 ;
F_152 ( V_8 -> V_19 ) ;
F_150 (obj, next, &dev_priv->mm.unbound_list, gtt_list)
F_147 ( V_2 ) ;
}
static int
F_153 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
int V_192 , V_84 ;
struct V_203 * V_99 ;
struct V_204 * V_205 ;
struct V_82 * V_83 ;
struct V_65 * V_65 ;
T_12 V_206 ;
F_94 ( V_2 -> V_47 . V_87 & V_146 ) ;
F_94 ( V_2 -> V_47 . V_113 & V_146 ) ;
V_205 = F_154 ( sizeof( * V_205 ) , V_45 ) ;
if ( V_205 == NULL )
return - V_50 ;
V_192 = V_2 -> V_47 . V_9 / V_33 ;
if ( F_155 ( V_205 , V_192 , V_45 ) ) {
F_145 ( V_205 ) ;
F_146 ( V_205 ) ;
return - V_50 ;
}
V_99 = F_139 ( V_2 -> V_47 . V_97 ) -> V_207 ;
V_206 = F_156 ( V_99 ) ;
V_206 |= V_208 | V_209 | V_210 ;
V_206 &= ~ ( V_211 | V_212 ) ;
F_61 (st->sgl, sg, page_count, i) {
V_65 = F_157 ( V_99 , V_84 , V_206 ) ;
if ( F_118 ( V_65 ) ) {
F_132 ( V_8 , V_192 ) ;
V_65 = F_157 ( V_99 , V_84 , V_206 ) ;
}
if ( F_118 ( V_65 ) ) {
V_206 &= ~ ( V_208 | V_209 | V_210 ) ;
V_206 |= V_211 | V_212 ;
F_133 ( V_8 ) ;
V_65 = F_157 ( V_99 , V_84 , V_206 ) ;
if ( F_118 ( V_65 ) )
goto V_213;
V_206 |= V_208 | V_209 | V_210 ;
V_206 &= ~ ( V_211 | V_212 ) ;
}
F_158 ( V_83 , V_65 , V_33 , 0 ) ;
}
V_2 -> V_193 = V_205 ;
if ( F_57 ( V_2 ) )
F_159 ( V_2 ) ;
return 0 ;
V_213:
F_61 (st->sgl, sg, i, page_count)
F_144 ( F_63 ( V_83 ) ) ;
F_145 ( V_205 ) ;
F_146 ( V_205 ) ;
return F_160 ( V_65 ) ;
}
int
F_59 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
const struct V_194 * V_195 = V_2 -> V_195 ;
int V_14 ;
if ( V_2 -> V_193 )
return 0 ;
if ( V_2 -> V_185 != V_186 ) {
F_9 ( L_4 ) ;
return - V_34 ;
}
F_94 ( V_2 -> V_196 ) ;
V_14 = V_195 -> V_214 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_161 ( & V_2 -> V_197 , & V_8 -> V_10 . V_215 ) ;
return 0 ;
}
void
F_162 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
struct V_7 * V_8 = V_19 -> V_20 ;
T_4 V_126 = F_163 ( V_125 ) ;
F_94 ( V_125 == NULL ) ;
V_2 -> V_125 = V_125 ;
if ( ! V_2 -> V_24 ) {
F_164 ( & V_2 -> V_47 ) ;
V_2 -> V_24 = 1 ;
}
F_165 ( & V_2 -> V_216 , & V_8 -> V_10 . V_217 ) ;
F_165 ( & V_2 -> V_218 , & V_125 -> V_217 ) ;
V_2 -> V_145 = V_126 ;
if ( V_2 -> V_219 ) {
V_2 -> V_220 = V_126 ;
if ( V_2 -> V_5 != V_6 ) {
struct V_221 * V_222 ;
V_222 = & V_8 -> V_223 [ V_2 -> V_5 ] ;
F_165 ( & V_222 -> V_224 ,
& V_8 -> V_10 . V_225 ) ;
}
}
}
static void
F_166 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
struct V_7 * V_8 = V_19 -> V_20 ;
F_94 ( V_2 -> V_47 . V_113 & ~ V_146 ) ;
F_94 ( ! V_2 -> V_24 ) ;
F_165 ( & V_2 -> V_216 , & V_8 -> V_10 . V_226 ) ;
F_167 ( & V_2 -> V_218 ) ;
V_2 -> V_125 = NULL ;
V_2 -> V_145 = 0 ;
V_2 -> V_144 = 0 ;
V_2 -> V_47 . V_113 = 0 ;
V_2 -> V_220 = 0 ;
V_2 -> V_219 = false ;
V_2 -> V_24 = 0 ;
F_32 ( & V_2 -> V_47 ) ;
F_12 ( F_13 ( V_19 ) ) ;
}
static int
F_168 ( struct V_18 * V_19 , T_4 V_126 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_124 * V_125 ;
int V_14 , V_84 , V_227 ;
F_169 (ring, dev_priv, i) {
V_14 = F_170 ( V_125 ) ;
if ( V_14 )
return V_14 ;
}
F_171 ( V_19 ) ;
F_169 (ring, dev_priv, i) {
F_172 ( V_125 , V_126 ) ;
for ( V_227 = 0 ; V_227 < F_173 ( V_125 -> V_228 ) ; V_227 ++ )
V_125 -> V_228 [ V_227 ] = 0 ;
}
return 0 ;
}
int F_174 ( struct V_18 * V_19 , T_4 V_126 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
int V_14 ;
if ( V_126 == 0 )
return - V_34 ;
V_14 = F_168 ( V_19 , V_126 - 1 ) ;
if ( V_14 )
return V_14 ;
V_8 -> V_229 = V_126 ;
V_8 -> V_230 = V_126 - 1 ;
if ( V_8 -> V_230 == 0 )
V_8 -> V_230 -- ;
return 0 ;
}
int
F_175 ( struct V_18 * V_19 , T_4 * V_126 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
if ( V_8 -> V_229 == 0 ) {
int V_14 = F_168 ( V_19 , 0 ) ;
if ( V_14 )
return V_14 ;
V_8 -> V_229 = 1 ;
}
* V_126 = V_8 -> V_230 = V_8 -> V_229 ++ ;
return 0 ;
}
int
F_96 ( struct V_124 * V_125 ,
struct V_26 * V_27 ,
T_4 * V_231 )
{
T_9 * V_8 = V_125 -> V_19 -> V_20 ;
struct V_232 * V_233 ;
T_4 V_234 ;
int V_235 ;
int V_14 ;
V_14 = F_176 ( V_125 ) ;
if ( V_14 )
return V_14 ;
V_233 = F_154 ( sizeof( * V_233 ) , V_45 ) ;
if ( V_233 == NULL )
return - V_50 ;
V_234 = F_177 ( V_125 ) ;
V_14 = V_125 -> V_236 ( V_125 ) ;
if ( V_14 ) {
F_146 ( V_233 ) ;
return V_14 ;
}
V_233 -> V_126 = F_163 ( V_125 ) ;
V_233 -> V_125 = V_125 ;
V_233 -> V_237 = V_234 ;
V_233 -> V_238 = V_239 ;
V_235 = F_178 ( & V_125 -> V_240 ) ;
F_161 ( & V_233 -> V_241 , & V_125 -> V_240 ) ;
V_233 -> V_242 = NULL ;
if ( V_27 ) {
struct V_243 * V_242 = V_27 -> V_244 ;
F_179 ( & V_242 -> V_10 . V_245 ) ;
V_233 -> V_242 = V_242 ;
F_161 ( & V_233 -> V_246 ,
& V_242 -> V_10 . V_240 ) ;
F_180 ( & V_242 -> V_10 . V_245 ) ;
}
F_181 ( V_125 , V_233 -> V_126 ) ;
V_125 -> V_127 = 0 ;
if ( ! V_8 -> V_10 . V_247 ) {
if ( V_248 ) {
F_182 ( & V_8 -> V_21 . V_249 ,
F_183 ( V_239 + V_250 ) ) ;
}
if ( V_235 ) {
F_184 ( V_8 -> V_251 ,
& V_8 -> V_10 . V_252 ,
F_185 ( V_17 ) ) ;
F_186 ( V_8 -> V_19 ) ;
}
}
if ( V_231 )
* V_231 = V_233 -> V_126 ;
return 0 ;
}
static inline void
F_187 ( struct V_232 * V_233 )
{
struct V_243 * V_242 = V_233 -> V_242 ;
if ( ! V_242 )
return;
F_179 ( & V_242 -> V_10 . V_245 ) ;
if ( V_233 -> V_242 ) {
F_148 ( & V_233 -> V_246 ) ;
V_233 -> V_242 = NULL ;
}
F_180 ( & V_242 -> V_10 . V_245 ) ;
}
static void F_188 ( struct V_7 * V_8 ,
struct V_124 * V_125 )
{
while ( ! F_178 ( & V_125 -> V_240 ) ) {
struct V_232 * V_233 ;
V_233 = F_189 ( & V_125 -> V_240 ,
struct V_232 ,
V_241 ) ;
F_148 ( & V_233 -> V_241 ) ;
F_187 ( V_233 ) ;
F_146 ( V_233 ) ;
}
while ( ! F_178 ( & V_125 -> V_217 ) ) {
struct V_1 * V_2 ;
V_2 = F_189 ( & V_125 -> V_217 ,
struct V_1 ,
V_218 ) ;
F_166 ( V_2 ) ;
}
}
static void F_190 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
int V_84 ;
for ( V_84 = 0 ; V_84 < V_8 -> V_253 ; V_84 ++ ) {
struct V_221 * V_222 = & V_8 -> V_223 [ V_84 ] ;
F_191 ( V_19 , V_84 , NULL ) ;
if ( V_222 -> V_2 )
F_1 ( V_222 -> V_2 ) ;
V_222 -> V_40 = 0 ;
V_222 -> V_2 = NULL ;
F_192 ( & V_222 -> V_224 ) ;
}
F_192 ( & V_8 -> V_10 . V_225 ) ;
}
void F_193 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_1 * V_2 ;
struct V_124 * V_125 ;
int V_84 ;
F_169 (ring, dev_priv, i)
F_188 ( V_8 , V_125 ) ;
F_22 (obj,
&dev_priv->mm.inactive_list,
mm_list)
{
V_2 -> V_47 . V_87 &= ~ V_146 ;
}
F_190 ( V_19 ) ;
}
void
F_109 ( struct V_124 * V_125 )
{
T_3 V_126 ;
if ( F_178 ( & V_125 -> V_240 ) )
return;
F_12 ( F_13 ( V_125 -> V_19 ) ) ;
V_126 = V_125 -> V_136 ( V_125 , true ) ;
while ( ! F_178 ( & V_125 -> V_240 ) ) {
struct V_232 * V_233 ;
V_233 = F_189 ( & V_125 -> V_240 ,
struct V_232 ,
V_241 ) ;
if ( ! F_98 ( V_126 , V_233 -> V_126 ) )
break;
F_194 ( V_125 , V_233 -> V_126 ) ;
V_125 -> V_254 = V_233 -> V_237 ;
F_148 ( & V_233 -> V_241 ) ;
F_187 ( V_233 ) ;
F_146 ( V_233 ) ;
}
while ( ! F_178 ( & V_125 -> V_217 ) ) {
struct V_1 * V_2 ;
V_2 = F_189 ( & V_125 -> V_217 ,
struct V_1 ,
V_218 ) ;
if ( ! F_98 ( V_126 , V_2 -> V_145 ) )
break;
F_166 ( V_2 ) ;
}
if ( F_45 ( V_125 -> V_255 &&
F_98 ( V_126 , V_125 -> V_255 ) ) ) {
V_125 -> V_139 ( V_125 ) ;
V_125 -> V_255 = 0 ;
}
F_12 ( F_13 ( V_125 -> V_19 ) ) ;
}
void
F_171 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
struct V_124 * V_125 ;
int V_84 ;
F_169 (ring, dev_priv, i)
F_109 ( V_125 ) ;
}
static void
F_195 ( struct V_256 * V_257 )
{
T_9 * V_8 ;
struct V_18 * V_19 ;
struct V_124 * V_125 ;
bool V_258 ;
int V_84 ;
V_8 = F_196 ( V_257 , T_9 ,
V_10 . V_252 . V_257 ) ;
V_19 = V_8 -> V_19 ;
if ( ! F_197 ( & V_19 -> V_22 ) ) {
F_184 ( V_8 -> V_251 , & V_8 -> V_10 . V_252 ,
F_185 ( V_17 ) ) ;
return;
}
F_171 ( V_19 ) ;
V_258 = true ;
F_169 (ring, dev_priv, i) {
if ( V_125 -> V_259 )
F_96 ( V_125 , NULL , NULL ) ;
V_258 &= F_178 ( & V_125 -> V_240 ) ;
}
if ( ! V_8 -> V_10 . V_247 && ! V_258 )
F_184 ( V_8 -> V_251 , & V_8 -> V_10 . V_252 ,
F_185 ( V_17 ) ) ;
if ( V_258 )
F_198 ( V_19 ) ;
F_20 ( & V_19 -> V_22 ) ;
}
static int
F_199 ( struct V_1 * V_2 )
{
int V_14 ;
if ( V_2 -> V_24 ) {
V_14 = F_93 ( V_2 -> V_125 , V_2 -> V_145 ) ;
if ( V_14 )
return V_14 ;
F_109 ( V_2 -> V_125 ) ;
}
return 0 ;
}
int
F_200 ( struct V_18 * V_19 , void * V_25 , struct V_26 * V_27 )
{
T_9 * V_8 = V_19 -> V_20 ;
struct V_260 * args = V_25 ;
struct V_1 * V_2 ;
struct V_124 * V_125 = NULL ;
struct V_129 V_261 , * V_130 = NULL ;
unsigned V_128 ;
T_4 V_126 = 0 ;
int V_14 = 0 ;
if ( args -> V_262 >= 0 ) {
V_261 = F_201 ( args -> V_262 ) ;
V_130 = & V_261 ;
}
V_14 = F_10 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_263 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
F_20 ( & V_19 -> V_22 ) ;
return - V_95 ;
}
V_14 = F_199 ( V_2 ) ;
if ( V_14 )
goto V_93;
if ( V_2 -> V_24 ) {
V_126 = V_2 -> V_145 ;
V_125 = V_2 -> V_125 ;
}
if ( V_126 == 0 )
goto V_93;
if ( ! args -> V_262 ) {
V_14 = - V_142 ;
goto V_93;
}
F_32 ( & V_2 -> V_47 ) ;
V_128 = F_103 ( & V_8 -> V_21 . V_128 ) ;
F_20 ( & V_19 -> V_22 ) ;
V_14 = F_97 ( V_125 , V_126 , V_128 , true , V_130 ) ;
if ( V_130 ) {
F_12 ( ! F_202 ( V_130 ) ) ;
args -> V_262 = F_203 ( V_130 ) ;
}
return V_14 ;
V_93:
F_32 ( & V_2 -> V_47 ) ;
F_20 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_204 ( struct V_1 * V_2 ,
struct V_124 * V_264 )
{
struct V_124 * V_265 = V_2 -> V_125 ;
T_4 V_126 ;
int V_14 , V_266 ;
if ( V_265 == NULL || V_264 == V_265 )
return 0 ;
if ( V_264 == NULL || ! F_205 ( V_2 -> V_47 . V_19 ) )
return F_108 ( V_2 , false ) ;
V_266 = F_206 ( V_265 , V_264 ) ;
V_126 = V_2 -> V_145 ;
if ( V_126 <= V_265 -> V_228 [ V_266 ] )
return 0 ;
V_14 = F_93 ( V_2 -> V_125 , V_126 ) ;
if ( V_14 )
return V_14 ;
V_14 = V_264 -> V_267 ( V_264 , V_265 , V_126 ) ;
if ( ! V_14 )
V_265 -> V_228 [ V_266 ] = V_2 -> V_145 ;
return V_14 ;
}
static void F_207 ( struct V_1 * V_2 )
{
T_4 V_268 , V_269 ;
F_2 ( V_2 ) ;
if ( ( V_2 -> V_47 . V_87 & V_149 ) == 0 )
return;
F_208 () ;
V_269 = V_2 -> V_47 . V_87 ;
V_268 = V_2 -> V_47 . V_113 ;
V_2 -> V_47 . V_87 &= ~ V_149 ;
V_2 -> V_47 . V_113 &= ~ V_149 ;
F_209 ( V_2 ,
V_269 ,
V_268 ) ;
}
int
F_151 ( struct V_1 * V_2 )
{
T_9 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
int V_14 ;
if ( V_2 -> V_23 == NULL )
return 0 ;
if ( V_2 -> V_40 )
return - V_173 ;
F_94 ( V_2 -> V_193 == NULL ) ;
V_14 = F_210 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_207 ( V_2 ) ;
V_14 = F_79 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_211 ( V_2 ) ;
if ( V_2 -> V_270 )
F_212 ( V_2 ) ;
if ( V_2 -> V_271 ) {
F_213 ( V_8 -> V_10 . V_272 , V_2 ) ;
V_2 -> V_271 = 0 ;
}
F_214 ( V_2 ) ;
F_148 ( & V_2 -> V_216 ) ;
F_165 ( & V_2 -> V_197 , & V_8 -> V_10 . V_215 ) ;
V_2 -> V_273 = true ;
F_215 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
V_2 -> V_107 = 0 ;
return 0 ;
}
int F_216 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
struct V_124 * V_125 ;
int V_14 , V_84 ;
F_169 (ring, dev_priv, i) {
V_14 = F_217 ( V_125 , NULL , V_274 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_170 ( V_125 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static void F_218 ( struct V_18 * V_19 , int V_222 ,
struct V_1 * V_2 )
{
T_9 * V_8 = V_19 -> V_20 ;
int V_5 ;
int V_275 ;
T_2 V_276 ;
if ( F_17 ( V_19 ) -> V_35 >= 6 ) {
V_5 = V_277 ;
V_275 = V_278 ;
} else {
V_5 = V_279 ;
V_275 = V_280 ;
}
if ( V_2 ) {
T_4 V_9 = V_2 -> V_23 -> V_9 ;
V_276 = ( T_2 ) ( ( V_2 -> V_107 + V_9 - 4096 ) &
0xfffff000 ) << 32 ;
V_276 |= V_2 -> V_107 & 0xfffff000 ;
V_276 |= ( T_2 ) ( ( V_2 -> V_281 / 128 ) - 1 ) << V_275 ;
if ( V_2 -> V_3 == V_282 )
V_276 |= 1 << V_283 ;
V_276 |= V_284 ;
} else
V_276 = 0 ;
V_5 += V_222 * 8 ;
F_219 ( V_5 , V_276 ) ;
F_220 ( V_5 ) ;
}
static void F_221 ( struct V_18 * V_19 , int V_222 ,
struct V_1 * V_2 )
{
T_9 * V_8 = V_19 -> V_20 ;
T_4 V_276 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_23 -> V_9 ;
int V_285 ;
int V_286 ;
F_222 ( ( V_2 -> V_107 & ~ V_287 ) ||
( V_9 & - V_9 ) != V_9 ||
( V_2 -> V_107 & ( V_9 - 1 ) ) ,
L_5 ,
V_2 -> V_107 , V_2 -> V_273 , V_9 ) ;
if ( V_2 -> V_3 == V_282 && F_223 ( V_19 ) )
V_286 = 128 ;
else
V_286 = 512 ;
V_285 = V_2 -> V_281 / V_286 ;
V_285 = F_224 ( V_285 ) - 1 ;
V_276 = V_2 -> V_107 ;
if ( V_2 -> V_3 == V_282 )
V_276 |= 1 << V_288 ;
V_276 |= F_225 ( V_9 ) ;
V_276 |= V_285 << V_289 ;
V_276 |= V_290 ;
} else
V_276 = 0 ;
if ( V_222 < 8 )
V_222 = V_291 + V_222 * 4 ;
else
V_222 = V_292 + ( V_222 - 8 ) * 4 ;
F_226 ( V_222 , V_276 ) ;
F_220 ( V_222 ) ;
}
static void F_227 ( struct V_18 * V_19 , int V_222 ,
struct V_1 * V_2 )
{
T_9 * V_8 = V_19 -> V_20 ;
T_3 V_276 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_23 -> V_9 ;
T_3 V_285 ;
F_222 ( ( V_2 -> V_107 & ~ V_293 ) ||
( V_9 & - V_9 ) != V_9 ||
( V_2 -> V_107 & ( V_9 - 1 ) ) ,
L_6 ,
V_2 -> V_107 , V_9 ) ;
V_285 = V_2 -> V_281 / 128 ;
V_285 = F_224 ( V_285 ) - 1 ;
V_276 = V_2 -> V_107 ;
if ( V_2 -> V_3 == V_282 )
V_276 |= 1 << V_288 ;
V_276 |= F_228 ( V_9 ) ;
V_276 |= V_285 << V_289 ;
V_276 |= V_290 ;
} else
V_276 = 0 ;
F_226 ( V_291 + V_222 * 4 , V_276 ) ;
F_220 ( V_291 + V_222 * 4 ) ;
}
inline static bool F_229 ( struct V_1 * V_2 )
{
return V_2 && V_2 -> V_47 . V_87 & V_149 ;
}
static void F_191 ( struct V_18 * V_19 , int V_222 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
if ( F_229 ( V_8 -> V_223 [ V_222 ] . V_2 ) )
F_208 () ;
switch ( F_17 ( V_19 ) -> V_35 ) {
case 7 :
case 6 :
case 5 :
case 4 : F_218 ( V_19 , V_222 , V_2 ) ; break;
case 3 : F_221 ( V_19 , V_222 , V_2 ) ; break;
case 2 : F_227 ( V_19 , V_222 , V_2 ) ; break;
default: F_230 () ;
}
if ( F_229 ( V_2 ) )
F_208 () ;
}
static inline int F_231 ( struct V_7 * V_8 ,
struct V_221 * V_294 )
{
return V_294 - V_8 -> V_223 ;
}
static void F_232 ( struct V_1 * V_2 ,
struct V_221 * V_294 ,
bool V_295 )
{
struct V_7 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
int V_222 = F_231 ( V_8 , V_294 ) ;
F_191 ( V_2 -> V_47 . V_19 , V_222 , V_295 ? V_2 : NULL ) ;
if ( V_295 ) {
V_2 -> V_5 = V_222 ;
V_294 -> V_2 = V_2 ;
F_165 ( & V_294 -> V_224 , & V_8 -> V_10 . V_225 ) ;
} else {
V_2 -> V_5 = V_6 ;
V_294 -> V_2 = NULL ;
F_167 ( & V_294 -> V_224 ) ;
}
}
static int
F_233 ( struct V_1 * V_2 )
{
if ( V_2 -> V_220 ) {
int V_14 = F_107 ( V_2 -> V_125 , V_2 -> V_220 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_220 = 0 ;
}
V_2 -> V_219 = false ;
return 0 ;
}
int
F_79 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
int V_14 ;
V_14 = F_233 ( V_2 ) ;
if ( V_14 )
return V_14 ;
if ( V_2 -> V_5 == V_6 )
return 0 ;
F_232 ( V_2 ,
& V_8 -> V_223 [ V_2 -> V_5 ] ,
false ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static struct V_221 *
F_234 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_221 * V_222 , * V_296 ;
int V_84 ;
V_296 = NULL ;
for ( V_84 = V_8 -> V_297 ; V_84 < V_8 -> V_253 ; V_84 ++ ) {
V_222 = & V_8 -> V_223 [ V_84 ] ;
if ( ! V_222 -> V_2 )
return V_222 ;
if ( ! V_222 -> V_40 )
V_296 = V_222 ;
}
if ( V_296 == NULL )
return NULL ;
F_22 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_222 -> V_40 )
continue;
return V_222 ;
}
return NULL ;
}
int
F_122 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
struct V_7 * V_8 = V_19 -> V_20 ;
bool V_295 = V_2 -> V_3 != V_120 ;
struct V_221 * V_222 ;
int V_14 ;
if ( V_2 -> V_4 ) {
V_14 = F_233 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_2 -> V_5 != V_6 ) {
V_222 = & V_8 -> V_223 [ V_2 -> V_5 ] ;
if ( ! V_2 -> V_4 ) {
F_165 ( & V_222 -> V_224 ,
& V_8 -> V_10 . V_225 ) ;
return 0 ;
}
} else if ( V_295 ) {
V_222 = F_234 ( V_19 ) ;
if ( V_222 == NULL )
return - V_298 ;
if ( V_222 -> V_2 ) {
struct V_1 * V_299 = V_222 -> V_2 ;
V_14 = F_233 ( V_299 ) ;
if ( V_14 )
return V_14 ;
F_1 ( V_299 ) ;
}
} else
return 0 ;
F_232 ( V_2 , V_222 , V_295 ) ;
V_2 -> V_4 = false ;
return 0 ;
}
static bool F_235 ( struct V_18 * V_19 ,
struct V_300 * V_23 ,
unsigned long V_89 )
{
struct V_300 * V_301 ;
if ( F_121 ( V_19 ) )
return true ;
if ( V_23 == NULL )
return true ;
if ( F_178 ( & V_23 -> V_302 ) )
return true ;
V_301 = F_236 ( V_23 -> V_302 . V_303 , struct V_300 , V_302 ) ;
if ( V_301 -> V_304 && ! V_301 -> V_305 && V_301 -> V_306 != V_89 )
return false ;
V_301 = F_236 ( V_23 -> V_302 . V_201 , struct V_300 , V_302 ) ;
if ( V_301 -> V_304 && ! V_23 -> V_305 && V_301 -> V_306 != V_89 )
return false ;
return true ;
}
static void F_237 ( struct V_18 * V_19 )
{
#if V_307
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_1 * V_2 ;
int V_308 = 0 ;
F_22 (obj, &dev_priv->mm.gtt_list, gtt_list) {
if ( V_2 -> V_23 == NULL ) {
F_238 ( V_309 L_7 ) ;
V_308 ++ ;
continue;
}
if ( V_2 -> V_89 != V_2 -> V_23 -> V_306 ) {
F_238 ( V_309 L_8 ,
V_2 -> V_23 -> V_75 ,
V_2 -> V_23 -> V_75 + V_2 -> V_23 -> V_9 ,
V_2 -> V_89 ,
V_2 -> V_23 -> V_306 ) ;
V_308 ++ ;
continue;
}
if ( ! F_235 ( V_19 ,
V_2 -> V_23 ,
V_2 -> V_89 ) ) {
F_238 ( V_309 L_9 ,
V_2 -> V_23 -> V_75 ,
V_2 -> V_23 -> V_75 + V_2 -> V_23 -> V_9 ,
V_2 -> V_89 ) ;
V_308 ++ ;
continue;
}
}
F_12 ( V_308 ) ;
#endif
}
static int
F_239 ( struct V_1 * V_2 ,
unsigned V_310 ,
bool V_273 ,
bool V_311 )
{
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
T_9 * V_8 = V_19 -> V_20 ;
struct V_300 * V_312 ;
T_4 V_9 , V_313 , V_314 , V_315 ;
bool V_109 , V_316 ;
int V_14 ;
V_313 = F_127 ( V_19 ,
V_2 -> V_47 . V_9 ,
V_2 -> V_3 ) ;
V_314 = F_128 ( V_19 ,
V_2 -> V_47 . V_9 ,
V_2 -> V_3 , true ) ;
V_315 =
F_128 ( V_19 ,
V_2 -> V_47 . V_9 ,
V_2 -> V_3 , false ) ;
if ( V_310 == 0 )
V_310 = V_273 ? V_314 :
V_315 ;
if ( V_273 && V_310 & ( V_314 - 1 ) ) {
F_9 ( L_10 , V_310 ) ;
return - V_34 ;
}
V_9 = V_273 ? V_313 : V_2 -> V_47 . V_9 ;
if ( V_2 -> V_47 . V_9 >
( V_273 ? V_8 -> V_36 . V_37 : V_8 -> V_36 . V_42 ) ) {
F_9 ( L_11 ) ;
return - V_184 ;
}
V_14 = F_59 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_60 ( V_2 ) ;
V_312 = F_240 ( sizeof( * V_312 ) , V_45 ) ;
if ( V_312 == NULL ) {
F_67 ( V_2 ) ;
return - V_50 ;
}
V_317:
if ( V_273 )
V_14 = F_241 ( & V_8 -> V_10 . V_23 , V_312 ,
V_9 , V_310 , V_2 -> V_89 ,
0 , V_8 -> V_36 . V_37 ) ;
else
V_14 = F_242 ( & V_8 -> V_10 . V_23 , V_312 ,
V_9 , V_310 , V_2 -> V_89 ) ;
if ( V_14 ) {
V_14 = F_243 ( V_19 , V_9 , V_310 ,
V_2 -> V_89 ,
V_273 ,
V_311 ) ;
if ( V_14 == 0 )
goto V_317;
F_67 ( V_2 ) ;
F_146 ( V_312 ) ;
return V_14 ;
}
if ( F_12 ( ! F_235 ( V_19 , V_312 , V_2 -> V_89 ) ) ) {
F_67 ( V_2 ) ;
F_215 ( V_312 ) ;
return - V_34 ;
}
V_14 = F_244 ( V_2 ) ;
if ( V_14 ) {
F_67 ( V_2 ) ;
F_215 ( V_312 ) ;
return V_14 ;
}
F_165 ( & V_2 -> V_197 , & V_8 -> V_10 . V_318 ) ;
F_161 ( & V_2 -> V_216 , & V_8 -> V_10 . V_226 ) ;
V_2 -> V_23 = V_312 ;
V_2 -> V_107 = V_312 -> V_75 ;
V_316 =
V_312 -> V_9 == V_313 &&
( V_312 -> V_75 & ( V_314 - 1 ) ) == 0 ;
V_109 =
V_2 -> V_107 + V_2 -> V_47 . V_9 <= V_8 -> V_36 . V_37 ;
V_2 -> V_273 = V_109 && V_316 ;
F_67 ( V_2 ) ;
F_245 ( V_2 , V_273 ) ;
F_237 ( V_19 ) ;
return 0 ;
}
void
F_85 ( struct V_1 * V_2 )
{
if ( V_2 -> V_193 == NULL )
return;
if ( V_2 -> V_319 )
return;
if ( V_2 -> V_89 != V_90 )
return;
F_246 ( V_2 ) ;
F_247 ( V_2 -> V_193 ) ;
}
static void
F_248 ( struct V_1 * V_2 )
{
T_3 V_268 ;
if ( V_2 -> V_47 . V_113 != V_149 )
return;
F_249 () ;
V_268 = V_2 -> V_47 . V_113 ;
V_2 -> V_47 . V_113 = 0 ;
F_209 ( V_2 ,
V_2 -> V_47 . V_87 ,
V_268 ) ;
}
static void
F_114 ( struct V_1 * V_2 )
{
T_3 V_268 ;
if ( V_2 -> V_47 . V_113 != V_88 )
return;
F_85 ( V_2 ) ;
F_86 ( V_2 -> V_47 . V_19 ) ;
V_268 = V_2 -> V_47 . V_113 ;
V_2 -> V_47 . V_113 = 0 ;
F_209 ( V_2 ,
V_2 -> V_47 . V_87 ,
V_268 ) ;
}
int
F_58 ( struct V_1 * V_2 , bool V_163 )
{
T_9 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
T_3 V_268 , V_269 ;
int V_14 ;
if ( V_2 -> V_23 == NULL )
return - V_34 ;
if ( V_2 -> V_47 . V_113 == V_149 )
return 0 ;
V_14 = F_108 ( V_2 , ! V_163 ) ;
if ( V_14 )
return V_14 ;
F_114 ( V_2 ) ;
if ( ( V_2 -> V_47 . V_87 & V_149 ) == 0 )
F_208 () ;
V_268 = V_2 -> V_47 . V_113 ;
V_269 = V_2 -> V_47 . V_87 ;
F_94 ( ( V_2 -> V_47 . V_113 & ~ V_149 ) != 0 ) ;
V_2 -> V_47 . V_87 |= V_149 ;
if ( V_163 ) {
V_2 -> V_47 . V_87 = V_149 ;
V_2 -> V_47 . V_113 = V_149 ;
V_2 -> V_114 = 1 ;
}
F_209 ( V_2 ,
V_269 ,
V_268 ) ;
if ( F_14 ( V_2 ) )
F_165 ( & V_2 -> V_216 , & V_8 -> V_10 . V_226 ) ;
return 0 ;
}
int F_250 ( struct V_1 * V_2 ,
enum V_320 V_89 )
{
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
T_9 * V_8 = V_19 -> V_20 ;
int V_14 ;
if ( V_2 -> V_89 == V_89 )
return 0 ;
if ( V_2 -> V_40 ) {
F_251 ( L_12 ) ;
return - V_173 ;
}
if ( ! F_235 ( V_19 , V_2 -> V_23 , V_89 ) ) {
V_14 = F_151 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_2 -> V_23 ) {
V_14 = F_210 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_207 ( V_2 ) ;
if ( F_17 ( V_19 ) -> V_35 < 6 ) {
V_14 = F_79 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_2 -> V_270 )
F_252 ( V_2 , V_89 ) ;
if ( V_2 -> V_271 )
F_253 ( V_8 -> V_10 . V_272 ,
V_2 , V_89 ) ;
V_2 -> V_23 -> V_306 = V_89 ;
}
if ( V_89 == V_90 ) {
T_4 V_269 , V_268 ;
F_12 ( V_2 -> V_47 . V_113 & ~ V_88 ) ;
F_12 ( V_2 -> V_47 . V_87 & ~ V_88 ) ;
V_269 = V_2 -> V_47 . V_87 ;
V_268 = V_2 -> V_47 . V_113 ;
V_2 -> V_47 . V_87 = V_88 ;
V_2 -> V_47 . V_113 = V_88 ;
F_209 ( V_2 ,
V_269 ,
V_268 ) ;
}
V_2 -> V_89 = V_89 ;
F_237 ( V_19 ) ;
return 0 ;
}
int F_254 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_321 * args = V_25 ;
struct V_1 * V_2 ;
int V_14 ;
V_14 = F_10 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
args -> V_322 = V_2 -> V_89 != V_90 ;
F_32 ( & V_2 -> V_47 ) ;
V_96:
F_20 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int F_255 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_321 * args = V_25 ;
struct V_1 * V_2 ;
enum V_320 V_323 ;
int V_14 ;
switch ( args -> V_322 ) {
case V_324 :
V_323 = V_90 ;
break;
case V_325 :
V_323 = V_326 ;
break;
default:
return - V_34 ;
}
V_14 = F_10 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
V_14 = F_250 ( V_2 , V_323 ) ;
F_32 ( & V_2 -> V_47 ) ;
V_96:
F_20 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_256 ( struct V_1 * V_2 ,
T_4 V_310 ,
struct V_124 * V_327 )
{
T_4 V_269 , V_268 ;
int V_14 ;
if ( V_327 != V_2 -> V_125 ) {
V_14 = F_204 ( V_2 , V_327 ) ;
if ( V_14 )
return V_14 ;
}
V_14 = F_250 ( V_2 , V_90 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_78 ( V_2 , V_310 , true , false ) ;
if ( V_14 )
return V_14 ;
F_114 ( V_2 ) ;
V_268 = V_2 -> V_47 . V_113 ;
V_269 = V_2 -> V_47 . V_87 ;
V_2 -> V_47 . V_113 = 0 ;
V_2 -> V_47 . V_87 |= V_149 ;
F_209 ( V_2 ,
V_269 ,
V_268 ) ;
return 0 ;
}
int
F_210 ( struct V_1 * V_2 )
{
int V_14 ;
if ( ( V_2 -> V_47 . V_87 & V_146 ) == 0 )
return 0 ;
V_14 = F_108 ( V_2 , false ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_47 . V_87 &= ~ V_146 ;
return 0 ;
}
int
F_112 ( struct V_1 * V_2 , bool V_163 )
{
T_3 V_268 , V_269 ;
int V_14 ;
if ( V_2 -> V_47 . V_113 == V_88 )
return 0 ;
V_14 = F_108 ( V_2 , ! V_163 ) ;
if ( V_14 )
return V_14 ;
F_248 ( V_2 ) ;
V_268 = V_2 -> V_47 . V_113 ;
V_269 = V_2 -> V_47 . V_87 ;
if ( ( V_2 -> V_47 . V_87 & V_88 ) == 0 ) {
F_85 ( V_2 ) ;
V_2 -> V_47 . V_87 |= V_88 ;
}
F_94 ( ( V_2 -> V_47 . V_113 & ~ V_88 ) != 0 ) ;
if ( V_163 ) {
V_2 -> V_47 . V_87 = V_88 ;
V_2 -> V_47 . V_113 = V_88 ;
}
F_209 ( V_2 ,
V_269 ,
V_268 ) ;
return 0 ;
}
static int
F_257 ( struct V_18 * V_19 , struct V_26 * V_27 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_243 * V_242 = V_27 -> V_244 ;
unsigned long V_328 = V_239 - F_258 ( 20 ) ;
struct V_232 * V_233 ;
struct V_124 * V_125 = NULL ;
unsigned V_128 ;
T_4 V_126 = 0 ;
int V_14 ;
V_14 = F_5 ( & V_8 -> V_21 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_91 ( & V_8 -> V_21 , false ) ;
if ( V_14 )
return V_14 ;
F_179 ( & V_242 -> V_10 . V_245 ) ;
F_22 (request, &file_priv->mm.request_list, client_list) {
if ( F_259 ( V_233 -> V_238 , V_328 ) )
break;
V_125 = V_233 -> V_125 ;
V_126 = V_233 -> V_126 ;
}
V_128 = F_103 ( & V_8 -> V_21 . V_128 ) ;
F_180 ( & V_242 -> V_10 . V_245 ) ;
if ( V_126 == 0 )
return 0 ;
V_14 = F_97 ( V_125 , V_126 , V_128 , true , NULL ) ;
if ( V_14 == 0 )
F_184 ( V_8 -> V_251 , & V_8 -> V_10 . V_252 , 0 ) ;
return V_14 ;
}
int
F_78 ( struct V_1 * V_2 ,
T_3 V_310 ,
bool V_273 ,
bool V_311 )
{
int V_14 ;
if ( F_12 ( V_2 -> V_40 == V_329 ) )
return - V_173 ;
if ( V_2 -> V_23 != NULL ) {
if ( ( V_310 && V_2 -> V_107 & ( V_310 - 1 ) ) ||
( V_273 && ! V_2 -> V_273 ) ) {
F_222 ( V_2 -> V_40 ,
L_13
L_14
L_15 ,
V_2 -> V_107 , V_310 ,
V_273 ,
V_2 -> V_273 ) ;
V_14 = F_151 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
}
if ( V_2 -> V_23 == NULL ) {
struct V_7 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
V_14 = F_239 ( V_2 , V_310 ,
V_273 ,
V_311 ) ;
if ( V_14 )
return V_14 ;
if ( ! V_8 -> V_10 . V_272 )
F_252 ( V_2 , V_2 -> V_89 ) ;
}
if ( ! V_2 -> V_270 && V_273 )
F_252 ( V_2 , V_2 -> V_89 ) ;
V_2 -> V_40 ++ ;
V_2 -> V_330 |= V_273 ;
return 0 ;
}
void
F_80 ( struct V_1 * V_2 )
{
F_94 ( V_2 -> V_40 == 0 ) ;
F_94 ( V_2 -> V_23 == NULL ) ;
if ( -- V_2 -> V_40 == 0 )
V_2 -> V_330 = false ;
}
int
F_260 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_331 * args = V_25 ;
struct V_1 * V_2 ;
int V_14 ;
V_14 = F_10 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
if ( V_2 -> V_185 != V_186 ) {
F_9 ( L_16 ) ;
V_14 = - V_34 ;
goto V_93;
}
if ( V_2 -> V_332 != NULL && V_2 -> V_332 != V_27 ) {
F_9 ( L_17 ,
args -> V_49 ) ;
V_14 = - V_34 ;
goto V_93;
}
if ( V_2 -> V_333 == 0 ) {
V_14 = F_78 ( V_2 , args -> V_310 , true , false ) ;
if ( V_14 )
goto V_93;
}
V_2 -> V_333 ++ ;
V_2 -> V_332 = V_27 ;
F_114 ( V_2 ) ;
args -> V_79 = V_2 -> V_107 ;
V_93:
F_32 ( & V_2 -> V_47 ) ;
V_96:
F_20 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_261 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_331 * args = V_25 ;
struct V_1 * V_2 ;
int V_14 ;
V_14 = F_10 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
if ( V_2 -> V_332 != V_27 ) {
F_9 ( L_18 ,
args -> V_49 ) ;
V_14 = - V_34 ;
goto V_93;
}
V_2 -> V_333 -- ;
if ( V_2 -> V_333 == 0 ) {
V_2 -> V_332 = NULL ;
F_80 ( V_2 ) ;
}
V_93:
F_32 ( & V_2 -> V_47 ) ;
V_96:
F_20 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_262 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_334 * args = V_25 ;
struct V_1 * V_2 ;
int V_14 ;
V_14 = F_10 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
V_14 = F_199 ( V_2 ) ;
args -> V_335 = V_2 -> V_24 ;
if ( V_2 -> V_125 ) {
F_263 ( V_336 > 16 ) ;
args -> V_335 |= F_264 ( V_2 -> V_125 ) << 16 ;
}
F_32 ( & V_2 -> V_47 ) ;
V_96:
F_20 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_265 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_242 )
{
return F_257 ( V_19 , V_242 ) ;
}
int
F_266 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_242 )
{
struct V_337 * args = V_25 ;
struct V_1 * V_2 ;
int V_14 ;
switch ( args -> V_185 ) {
case V_191 :
case V_186 :
break;
default:
return - V_34 ;
}
V_14 = F_10 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_242 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
if ( V_2 -> V_40 ) {
V_14 = - V_34 ;
goto V_93;
}
if ( V_2 -> V_185 != V_190 )
V_2 -> V_185 = args -> V_185 ;
if ( F_141 ( V_2 ) && V_2 -> V_193 == NULL )
F_138 ( V_2 ) ;
args -> V_338 = V_2 -> V_185 != V_190 ;
V_93:
F_32 ( & V_2 -> V_47 ) ;
V_96:
F_20 ( & V_19 -> V_22 ) ;
return V_14 ;
}
void F_267 ( struct V_1 * V_2 ,
const struct V_194 * V_195 )
{
F_192 ( & V_2 -> V_216 ) ;
F_192 ( & V_2 -> V_197 ) ;
F_192 ( & V_2 -> V_218 ) ;
F_192 ( & V_2 -> V_339 ) ;
V_2 -> V_195 = V_195 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_185 = V_186 ;
V_2 -> V_273 = true ;
F_3 ( V_2 -> V_47 . V_19 -> V_20 , V_2 -> V_47 . V_9 ) ;
}
struct V_1 * F_29 ( struct V_18 * V_19 ,
T_1 V_9 )
{
struct V_1 * V_2 ;
struct V_203 * V_99 ;
T_12 V_340 ;
V_2 = F_23 ( V_19 ) ;
if ( V_2 == NULL )
return NULL ;
if ( F_268 ( V_19 , & V_2 -> V_47 , V_9 ) != 0 ) {
F_25 ( V_2 ) ;
return NULL ;
}
V_340 = V_341 | V_342 ;
if ( F_269 ( V_19 ) || F_270 ( V_19 ) ) {
V_340 &= ~ V_343 ;
V_340 |= V_344 ;
}
V_99 = F_139 ( V_2 -> V_47 . V_97 ) -> V_207 ;
F_271 ( V_99 , V_340 ) ;
F_267 ( V_2 , & V_345 ) ;
V_2 -> V_47 . V_113 = V_88 ;
V_2 -> V_47 . V_87 = V_88 ;
if ( F_121 ( V_19 ) ) {
V_2 -> V_89 = V_326 ;
} else
V_2 -> V_89 = V_90 ;
return V_2 ;
}
int F_272 ( struct V_152 * V_2 )
{
F_230 () ;
return 0 ;
}
void F_273 ( struct V_152 * V_346 )
{
struct V_1 * V_2 = F_70 ( V_346 ) ;
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
T_9 * V_8 = V_19 -> V_20 ;
F_274 ( V_2 ) ;
if ( V_2 -> V_119 )
F_275 ( V_19 , V_2 ) ;
V_2 -> V_40 = 0 ;
if ( F_12 ( F_151 ( V_2 ) == - V_141 ) ) {
bool V_347 ;
V_347 = V_8 -> V_10 . V_122 ;
V_8 -> V_10 . V_122 = false ;
F_12 ( F_151 ( V_2 ) ) ;
V_8 -> V_10 . V_122 = V_347 ;
}
V_2 -> V_196 = 0 ;
F_147 ( V_2 ) ;
F_134 ( V_2 ) ;
F_276 ( V_2 ) ;
F_94 ( V_2 -> V_193 ) ;
if ( V_2 -> V_47 . V_348 )
F_277 ( & V_2 -> V_47 , NULL ) ;
F_31 ( & V_2 -> V_47 ) ;
F_4 ( V_8 , V_2 -> V_47 . V_9 ) ;
F_146 ( V_2 -> V_349 ) ;
F_25 ( V_2 ) ;
}
int
F_278 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
int V_14 ;
F_18 ( & V_19 -> V_22 ) ;
if ( V_8 -> V_10 . V_247 ) {
F_20 ( & V_19 -> V_22 ) ;
return 0 ;
}
V_14 = F_216 ( V_19 ) ;
if ( V_14 ) {
F_20 ( & V_19 -> V_22 ) ;
return V_14 ;
}
F_171 ( V_19 ) ;
if ( ! F_16 ( V_19 , V_29 ) )
F_152 ( V_19 ) ;
F_190 ( V_19 ) ;
V_8 -> V_10 . V_247 = 1 ;
F_279 ( & V_8 -> V_21 . V_249 ) ;
F_280 ( V_19 ) ;
F_281 ( V_19 ) ;
F_20 ( & V_19 -> V_22 ) ;
F_282 ( & V_8 -> V_10 . V_252 ) ;
return 0 ;
}
void F_283 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
T_4 V_350 ;
int V_84 ;
if ( ! F_284 ( V_19 ) )
return;
if ( ! V_8 -> V_351 . V_352 )
return;
V_350 = F_285 ( V_353 ) ;
F_226 ( V_353 , V_350 & ~ V_354 ) ;
F_220 ( V_353 ) ;
for ( V_84 = 0 ; V_84 < V_355 ; V_84 += 4 ) {
T_4 V_356 = F_285 ( V_357 + V_84 ) ;
if ( V_356 && V_356 != V_8 -> V_351 . V_352 [ V_84 / 4 ] )
F_251 ( L_19 ,
V_357 + V_84 , V_356 ) ;
if ( V_356 && ! V_8 -> V_351 . V_352 [ V_84 / 4 ] )
F_286 ( L_20 ) ;
F_226 ( V_357 + V_84 , V_8 -> V_351 . V_352 [ V_84 / 4 ] ) ;
}
F_220 ( V_357 ) ;
F_226 ( V_353 , V_350 ) ;
}
void F_287 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
if ( F_17 ( V_19 ) -> V_35 < 5 ||
V_8 -> V_10 . V_358 == V_359 )
return;
F_226 ( V_360 , F_285 ( V_360 ) |
V_361 ) ;
if ( F_288 ( V_19 ) )
return;
F_226 ( V_362 , F_285 ( V_362 ) | V_363 ) ;
if ( F_289 ( V_19 ) )
F_226 ( V_364 , F_290 ( V_365 ) ) ;
else if ( F_291 ( V_19 ) )
F_226 ( V_364 , F_290 ( V_366 ) ) ;
else
F_230 () ;
}
static bool
F_292 ( struct V_18 * V_19 )
{
if ( ! F_293 ( V_19 ) )
return false ;
if ( F_289 ( V_19 ) && V_19 -> V_367 -> V_368 < 8 ) {
F_294 ( L_21
L_22 ) ;
return false ;
}
return true ;
}
static int F_295 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
int V_14 ;
V_14 = F_296 ( V_19 ) ;
if ( V_14 )
return V_14 ;
if ( F_297 ( V_19 ) ) {
V_14 = F_298 ( V_19 ) ;
if ( V_14 )
goto V_369;
}
if ( F_292 ( V_19 ) ) {
V_14 = F_299 ( V_19 ) ;
if ( V_14 )
goto V_370;
}
V_14 = F_174 ( V_19 , ( ( T_4 ) ~ 0 - 0x1000 ) ) ;
if ( V_14 )
goto V_371;
return 0 ;
V_371:
F_300 ( & V_8 -> V_125 [ V_372 ] ) ;
V_370:
F_300 ( & V_8 -> V_125 [ V_373 ] ) ;
V_369:
F_300 ( & V_8 -> V_125 [ V_374 ] ) ;
return V_14 ;
}
int
F_301 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
int V_14 ;
if ( F_17 ( V_19 ) -> V_35 < 6 && ! F_302 () )
return - V_15 ;
if ( F_303 ( V_19 ) && ( F_285 ( 0x120010 ) == 1 ) )
F_226 ( 0x9008 , F_285 ( 0x9008 ) | 0xf0000 ) ;
F_283 ( V_19 ) ;
F_287 ( V_19 ) ;
V_14 = F_295 ( V_19 ) ;
if ( V_14 )
return V_14 ;
F_304 ( V_19 ) ;
F_305 ( V_19 ) ;
return 0 ;
}
int F_306 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
int V_14 ;
F_18 ( & V_19 -> V_22 ) ;
F_307 ( V_19 ) ;
V_14 = F_301 ( V_19 ) ;
F_20 ( & V_19 -> V_22 ) ;
if ( V_14 ) {
F_308 ( V_19 ) ;
return V_14 ;
}
if ( ! F_16 ( V_19 , V_29 ) )
V_8 -> V_375 . V_376 = 1 ;
return 0 ;
}
void
F_281 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
struct V_124 * V_125 ;
int V_84 ;
F_169 (ring, dev_priv, i)
F_300 ( V_125 ) ;
}
int
F_309 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_242 )
{
T_9 * V_8 = V_19 -> V_20 ;
int V_14 ;
if ( F_16 ( V_19 , V_29 ) )
return 0 ;
if ( F_92 ( & V_8 -> V_21 ) ) {
F_9 ( L_23 ) ;
F_310 ( & V_8 -> V_21 . V_128 , 0 ) ;
}
F_18 ( & V_19 -> V_22 ) ;
V_8 -> V_10 . V_247 = 0 ;
V_14 = F_301 ( V_19 ) ;
if ( V_14 != 0 ) {
F_20 ( & V_19 -> V_22 ) ;
return V_14 ;
}
F_94 ( ! F_178 ( & V_8 -> V_10 . V_217 ) ) ;
F_20 ( & V_19 -> V_22 ) ;
V_14 = F_311 ( V_19 ) ;
if ( V_14 )
goto V_377;
return 0 ;
V_377:
F_18 ( & V_19 -> V_22 ) ;
F_281 ( V_19 ) ;
V_8 -> V_10 . V_247 = 1 ;
F_20 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_312 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_242 )
{
if ( F_16 ( V_19 , V_29 ) )
return 0 ;
F_313 ( V_19 ) ;
return F_278 ( V_19 ) ;
}
void
F_314 ( struct V_18 * V_19 )
{
int V_14 ;
if ( F_16 ( V_19 , V_29 ) )
return;
V_14 = F_278 ( V_19 ) ;
if ( V_14 )
F_9 ( L_24 , V_14 ) ;
}
static void
F_315 ( struct V_124 * V_125 )
{
F_192 ( & V_125 -> V_217 ) ;
F_192 ( & V_125 -> V_240 ) ;
}
void
F_316 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
int V_84 ;
V_8 -> V_44 =
F_317 ( L_25 ,
sizeof( struct V_1 ) , 0 ,
V_378 ,
NULL ) ;
F_192 ( & V_8 -> V_10 . V_217 ) ;
F_192 ( & V_8 -> V_10 . V_226 ) ;
F_192 ( & V_8 -> V_10 . V_215 ) ;
F_192 ( & V_8 -> V_10 . V_318 ) ;
F_192 ( & V_8 -> V_10 . V_225 ) ;
for ( V_84 = 0 ; V_84 < V_336 ; V_84 ++ )
F_315 ( & V_8 -> V_125 [ V_84 ] ) ;
for ( V_84 = 0 ; V_84 < V_379 ; V_84 ++ )
F_192 ( & V_8 -> V_223 [ V_84 ] . V_224 ) ;
F_318 ( & V_8 -> V_10 . V_252 ,
F_195 ) ;
F_319 ( & V_8 -> V_21 . V_16 ) ;
if ( F_320 ( V_19 ) ) {
F_226 ( V_380 ,
F_290 ( V_381 ) ) ;
}
V_8 -> V_382 = V_383 ;
if ( ! F_16 ( V_19 , V_29 ) )
V_8 -> V_297 = 3 ;
if ( F_17 ( V_19 ) -> V_35 >= 4 || F_321 ( V_19 ) || F_322 ( V_19 ) || F_129 ( V_19 ) )
V_8 -> V_253 = 16 ;
else
V_8 -> V_253 = 8 ;
F_190 ( V_19 ) ;
F_323 ( V_19 ) ;
F_319 ( & V_8 -> V_384 ) ;
V_8 -> V_10 . V_122 = true ;
V_8 -> V_10 . V_385 . V_386 = V_387 ;
V_8 -> V_10 . V_385 . V_388 = V_389 ;
F_324 ( & V_8 -> V_10 . V_385 ) ;
}
static int F_325 ( struct V_18 * V_19 ,
int V_390 , int V_9 , int V_391 )
{
T_9 * V_8 = V_19 -> V_20 ;
struct V_392 * V_119 ;
int V_14 ;
if ( V_8 -> V_10 . V_393 [ V_390 - 1 ] || ! V_9 )
return 0 ;
V_119 = F_240 ( sizeof( struct V_392 ) , V_45 ) ;
if ( ! V_119 )
return - V_50 ;
V_119 -> V_390 = V_390 ;
V_119 -> V_49 = F_326 ( V_19 , V_9 , V_391 ) ;
if ( ! V_119 -> V_49 ) {
V_14 = - V_50 ;
goto V_394;
}
#ifdef F_327
F_328 ( ( unsigned long ) V_119 -> V_49 -> V_71 , V_119 -> V_49 -> V_9 / V_33 ) ;
#endif
V_8 -> V_10 . V_393 [ V_390 - 1 ] = V_119 ;
return 0 ;
V_394:
F_146 ( V_119 ) ;
return V_14 ;
}
static void F_329 ( struct V_18 * V_19 , int V_390 )
{
T_9 * V_8 = V_19 -> V_20 ;
struct V_392 * V_119 ;
if ( ! V_8 -> V_10 . V_393 [ V_390 - 1 ] )
return;
V_119 = V_8 -> V_10 . V_393 [ V_390 - 1 ] ;
if ( V_119 -> V_395 ) {
F_275 ( V_19 , V_119 -> V_395 ) ;
}
#ifdef F_327
F_330 ( ( unsigned long ) V_119 -> V_49 -> V_71 , V_119 -> V_49 -> V_9 / V_33 ) ;
#endif
F_331 ( V_19 , V_119 -> V_49 ) ;
F_146 ( V_119 ) ;
V_8 -> V_10 . V_393 [ V_390 - 1 ] = NULL ;
}
void F_332 ( struct V_18 * V_19 )
{
int V_84 ;
for ( V_84 = V_396 ; V_84 <= V_397 ; V_84 ++ )
F_329 ( V_19 , V_84 ) ;
}
void F_275 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_203 * V_99 = F_139 ( V_2 -> V_47 . V_97 ) -> V_207 ;
char * V_71 ;
int V_84 ;
int V_192 ;
if ( ! V_2 -> V_119 )
return;
V_71 = V_2 -> V_119 -> V_49 -> V_71 ;
V_192 = V_2 -> V_47 . V_9 / V_33 ;
for ( V_84 = 0 ; V_84 < V_192 ; V_84 ++ ) {
struct V_65 * V_65 = F_333 ( V_99 , V_84 ) ;
if ( ! F_118 ( V_65 ) ) {
char * V_398 = F_46 ( V_65 ) ;
memcpy ( V_398 , V_71 + V_84 * V_33 , V_33 ) ;
F_49 ( V_398 ) ;
F_334 ( & V_65 , 1 ) ;
F_84 ( V_65 ) ;
F_66 ( V_65 ) ;
F_144 ( V_65 ) ;
}
}
F_86 ( V_19 ) ;
V_2 -> V_119 -> V_395 = NULL ;
V_2 -> V_119 = NULL ;
}
int
F_335 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_390 ,
int V_391 )
{
struct V_203 * V_99 = F_139 ( V_2 -> V_47 . V_97 ) -> V_207 ;
T_9 * V_8 = V_19 -> V_20 ;
int V_14 = 0 ;
int V_192 ;
int V_84 ;
if ( V_390 > V_397 )
return - V_34 ;
if ( V_2 -> V_119 ) {
if ( V_2 -> V_119 -> V_390 == V_390 )
return 0 ;
F_275 ( V_19 , V_2 ) ;
}
if ( ! V_8 -> V_10 . V_393 [ V_390 - 1 ] ) {
V_14 = F_325 ( V_19 , V_390 ,
V_2 -> V_47 . V_9 , V_391 ) ;
if ( V_14 ) {
F_9 ( L_26 ,
V_390 , V_2 -> V_47 . V_9 ) ;
return V_14 ;
}
}
V_2 -> V_119 = V_8 -> V_10 . V_393 [ V_390 - 1 ] ;
V_2 -> V_119 -> V_395 = V_2 ;
V_192 = V_2 -> V_47 . V_9 / V_33 ;
for ( V_84 = 0 ; V_84 < V_192 ; V_84 ++ ) {
struct V_65 * V_65 ;
char * V_398 , * V_399 ;
V_65 = F_333 ( V_99 , V_84 ) ;
if ( F_118 ( V_65 ) )
return F_160 ( V_65 ) ;
V_399 = F_46 ( V_65 ) ;
V_398 = V_2 -> V_119 -> V_49 -> V_71 + ( V_84 * V_33 ) ;
memcpy ( V_398 , V_399 , V_33 ) ;
F_49 ( V_399 ) ;
F_66 ( V_65 ) ;
F_144 ( V_65 ) ;
}
return 0 ;
}
static int
F_90 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_105 * args ,
struct V_26 * V_242 )
{
void * V_71 = V_2 -> V_119 -> V_49 -> V_71 + args -> V_79 ;
char T_5 * V_68 = ( char T_5 * ) ( V_85 ) args -> V_86 ;
if ( F_75 ( V_71 , V_68 , args -> V_9 ) ) {
unsigned long V_103 ;
F_20 ( & V_19 -> V_22 ) ;
V_103 = F_336 ( V_71 , V_68 , args -> V_9 ) ;
F_18 ( & V_19 -> V_22 ) ;
if ( V_103 )
return - V_72 ;
}
F_86 ( V_19 ) ;
return 0 ;
}
void F_337 ( struct V_18 * V_19 , struct V_26 * V_27 )
{
struct V_243 * V_242 = V_27 -> V_244 ;
F_179 ( & V_242 -> V_10 . V_245 ) ;
while ( ! F_178 ( & V_242 -> V_10 . V_240 ) ) {
struct V_232 * V_233 ;
V_233 = F_189 ( & V_242 -> V_10 . V_240 ,
struct V_232 ,
V_246 ) ;
F_148 ( & V_233 -> V_246 ) ;
V_233 -> V_242 = NULL ;
}
F_180 ( & V_242 -> V_10 . V_245 ) ;
}
static bool F_338 ( struct V_400 * V_400 , struct V_401 * V_402 )
{
if ( ! F_95 ( V_400 ) )
return false ;
#if F_339 ( V_403 ) || F_339 ( V_404 )
return V_400 -> V_405 == V_402 ;
#else
return false ;
#endif
}
static int
V_387 ( struct V_406 * V_406 , struct V_407 * V_408 )
{
struct V_7 * V_8 =
F_196 ( V_406 ,
struct V_7 ,
V_10 . V_385 ) ;
struct V_18 * V_19 = V_8 -> V_19 ;
struct V_1 * V_2 ;
int V_409 = V_408 -> V_409 ;
bool V_96 = true ;
int V_410 ;
if ( ! F_197 ( & V_19 -> V_22 ) ) {
if ( ! F_338 ( & V_19 -> V_22 , V_411 ) )
return 0 ;
if ( V_8 -> V_10 . V_183 )
return 0 ;
V_96 = false ;
}
if ( V_409 ) {
V_409 -= F_132 ( V_8 , V_409 ) ;
if ( V_409 > 0 )
V_409 -= F_149 ( V_8 , V_409 ,
false ) ;
if ( V_409 > 0 )
F_133 ( V_8 ) ;
}
V_410 = 0 ;
F_22 (obj, &dev_priv->mm.unbound_list, gtt_list)
if ( V_2 -> V_196 == 0 )
V_410 += V_2 -> V_47 . V_9 >> V_91 ;
F_22 (obj, &dev_priv->mm.inactive_list, gtt_list)
if ( V_2 -> V_40 == 0 && V_2 -> V_196 == 0 )
V_410 += V_2 -> V_47 . V_9 >> V_91 ;
if ( V_96 )
F_20 ( & V_19 -> V_22 ) ;
return V_410 ;
}

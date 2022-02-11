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
#define F_6 (!i915_reset_in_progress(error) || \
i915_terminally_wedged(error))
if ( F_6 )
return 0 ;
V_14 = F_7 ( error -> V_15 ,
F_6 ,
10 * V_16 ) ;
if ( V_14 == 0 ) {
F_8 ( L_1 ) ;
return - V_17 ;
} else if ( V_14 < 0 ) {
return V_14 ;
}
#undef F_6
return 0 ;
}
int F_9 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
int V_14 ;
V_14 = F_5 ( & V_8 -> V_21 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_10 ( & V_19 -> V_22 ) ;
if ( V_14 )
return V_14 ;
F_11 ( F_12 ( V_19 ) ) ;
return 0 ;
}
static inline bool
F_13 ( struct V_1 * V_2 )
{
return V_2 -> V_23 && ! V_2 -> V_24 ;
}
int
F_14 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_28 * args = V_25 ;
if ( F_15 ( V_19 , V_29 ) )
return - V_30 ;
if ( args -> V_31 >= args -> V_32 ||
( args -> V_32 | args -> V_31 ) & ( V_33 - 1 ) )
return - V_34 ;
if ( F_16 ( V_19 ) -> V_35 >= 5 )
return - V_30 ;
F_17 ( & V_19 -> V_22 ) ;
F_18 ( V_19 , args -> V_31 , args -> V_32 ,
args -> V_32 ) ;
V_8 -> V_36 . V_37 = args -> V_32 ;
F_19 ( & V_19 -> V_22 ) ;
return 0 ;
}
int
F_20 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_38 * args = V_25 ;
struct V_1 * V_2 ;
T_1 V_39 ;
V_39 = 0 ;
F_17 ( & V_19 -> V_22 ) ;
F_21 (obj, &dev_priv->mm.bound_list, gtt_list)
if ( V_2 -> V_40 )
V_39 += V_2 -> V_23 -> V_9 ;
F_19 ( & V_19 -> V_22 ) ;
args -> V_41 = V_8 -> V_36 . V_42 ;
args -> V_43 = args -> V_41 - V_39 ;
return 0 ;
}
void * F_22 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
return F_23 ( V_8 -> V_44 , V_45 | V_46 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
F_25 ( V_8 -> V_44 , V_2 ) ;
}
static int
F_26 ( struct V_26 * V_27 ,
struct V_18 * V_19 ,
T_2 V_9 ,
T_3 * V_48 )
{
struct V_1 * V_2 ;
int V_14 ;
T_4 V_49 ;
V_9 = F_27 ( V_9 , V_33 ) ;
if ( V_9 == 0 )
return - V_34 ;
V_2 = F_28 ( V_19 , V_9 ) ;
if ( V_2 == NULL )
return - V_50 ;
V_14 = F_29 ( V_27 , & V_2 -> V_47 , & V_49 ) ;
if ( V_14 ) {
F_30 ( & V_2 -> V_47 ) ;
F_4 ( V_19 -> V_20 , V_2 -> V_47 . V_9 ) ;
F_24 ( V_2 ) ;
return V_14 ;
}
F_31 ( & V_2 -> V_47 ) ;
F_32 ( V_2 ) ;
* V_48 = V_49 ;
return 0 ;
}
int
F_33 ( struct V_26 * V_27 ,
struct V_18 * V_19 ,
struct V_51 * args )
{
args -> V_52 = F_34 ( args -> V_53 * ( ( args -> V_54 + 7 ) / 8 ) , 64 ) ;
args -> V_9 = args -> V_52 * args -> V_55 ;
return F_26 ( V_27 , V_19 ,
args -> V_9 , & args -> V_49 ) ;
}
int F_35 ( struct V_26 * V_27 ,
struct V_18 * V_19 ,
T_3 V_49 )
{
return F_36 ( V_27 , V_49 ) ;
}
int
F_37 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_56 * args = V_25 ;
return F_26 ( V_27 , V_19 ,
args -> V_9 , & args -> V_49 ) ;
}
static inline int
F_38 ( char T_5 * V_57 ,
const char * V_58 , int V_59 ,
int V_60 )
{
int V_14 , V_61 = 0 ;
while ( V_60 > 0 ) {
int V_62 = F_34 ( V_59 + 1 , 64 ) ;
int V_63 = F_39 ( V_62 - V_59 , V_60 ) ;
int V_64 = V_59 ^ 64 ;
V_14 = F_40 ( V_57 + V_61 ,
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
F_41 ( char * V_58 , int V_59 ,
const char T_5 * V_57 ,
int V_60 )
{
int V_14 , V_61 = 0 ;
while ( V_60 > 0 ) {
int V_62 = F_34 ( V_59 + 1 , 64 ) ;
int V_63 = F_39 ( V_62 - V_59 , V_60 ) ;
int V_64 = V_59 ^ 64 ;
V_14 = F_42 ( V_58 + V_64 ,
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
F_43 ( struct V_65 * V_65 , int V_66 , int V_67 ,
char T_5 * V_68 ,
bool V_69 , bool V_70 )
{
char * V_71 ;
int V_14 ;
if ( F_44 ( V_69 ) )
return - V_34 ;
V_71 = F_45 ( V_65 ) ;
if ( V_70 )
F_46 ( V_71 + V_66 ,
V_67 ) ;
V_14 = F_47 ( V_68 ,
V_71 + V_66 ,
V_67 ) ;
F_48 ( V_71 ) ;
return V_14 ? - V_72 : 0 ;
}
static void
F_49 ( char * V_73 , unsigned long V_60 ,
bool V_74 )
{
if ( F_44 ( V_74 ) ) {
unsigned long V_75 = ( unsigned long ) V_73 ;
unsigned long V_76 = ( unsigned long ) V_73 + V_60 ;
V_75 = F_50 ( V_75 , 128 ) ;
V_76 = F_51 ( V_76 , 128 ) ;
F_46 ( ( void * ) V_75 , V_76 - V_75 ) ;
} else {
F_46 ( V_73 , V_60 ) ;
}
}
static int
F_52 ( struct V_65 * V_65 , int V_66 , int V_67 ,
char T_5 * V_68 ,
bool V_69 , bool V_70 )
{
char * V_71 ;
int V_14 ;
V_71 = F_53 ( V_65 ) ;
if ( V_70 )
F_49 ( V_71 + V_66 ,
V_67 ,
V_69 ) ;
if ( V_69 )
V_14 = F_38 ( V_68 ,
V_71 , V_66 ,
V_67 ) ;
else
V_14 = F_40 ( V_68 ,
V_71 + V_66 ,
V_67 ) ;
F_54 ( V_65 ) ;
return V_14 ? - V_72 : 0 ;
}
static int
F_55 ( struct V_18 * V_19 ,
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
struct V_82 V_83 ;
V_68 = F_56 ( args -> V_84 ) ;
V_78 = args -> V_9 ;
V_80 = F_57 ( V_2 ) ;
if ( ! ( V_2 -> V_47 . V_85 & V_86 ) ) {
if ( V_2 -> V_87 == V_88 )
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
F_61 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_65 * V_65 = F_62 ( & V_83 ) ;
if ( V_78 <= 0 )
break;
V_66 = F_63 ( V_79 ) ;
V_67 = V_78 ;
if ( ( V_66 + V_67 ) > V_33 )
V_67 = V_33 - V_66 ;
V_69 = V_80 &&
( F_64 ( V_65 ) & ( 1 << 17 ) ) != 0 ;
V_14 = F_43 ( V_65 , V_66 , V_67 ,
V_68 , V_69 ,
V_70 ) ;
if ( V_14 == 0 )
goto V_89;
F_19 ( & V_19 -> V_22 ) ;
if ( ! V_81 ) {
V_14 = F_65 ( V_68 , V_78 ) ;
( void ) V_14 ;
V_81 = 1 ;
}
V_14 = F_52 ( V_65 , V_66 , V_67 ,
V_68 , V_69 ,
V_70 ) ;
F_17 ( & V_19 -> V_22 ) ;
V_89:
F_66 ( V_65 ) ;
if ( V_14 )
goto V_90;
V_78 -= V_67 ;
V_68 += V_67 ;
V_79 += V_67 ;
}
V_90:
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
if ( ! F_69 ( V_91 ,
F_56 ( args -> V_84 ) ,
args -> V_9 ) )
return - V_72 ;
V_14 = F_9 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_92 ;
goto V_93;
}
if ( args -> V_79 > V_2 -> V_47 . V_9 ||
args -> V_9 > V_2 -> V_47 . V_9 - args -> V_79 ) {
V_14 = - V_34 ;
goto V_90;
}
if ( ! V_2 -> V_47 . V_94 ) {
V_14 = - V_34 ;
goto V_90;
}
F_72 ( V_2 , args -> V_79 , args -> V_9 ) ;
V_14 = F_55 ( V_19 , V_2 , args , V_27 ) ;
V_90:
F_31 ( & V_2 -> V_47 ) ;
V_93:
F_19 ( & V_19 -> V_22 ) ;
return V_14 ;
}
static inline int
F_73 ( struct V_95 * V_96 ,
T_7 V_97 , int V_98 ,
char T_5 * V_68 ,
int V_60 )
{
void T_8 * V_99 ;
void * V_71 ;
unsigned long V_100 ;
V_99 = F_74 ( V_96 , V_97 ) ;
V_71 = ( void V_101 * ) V_99 + V_98 ;
V_100 = F_75 ( V_71 ,
V_68 , V_60 ) ;
F_76 ( V_99 ) ;
return V_100 ;
}
static int
F_77 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_102 * args ,
struct V_26 * V_27 )
{
T_9 * V_8 = V_19 -> V_20 ;
T_6 V_78 ;
T_7 V_79 , V_97 ;
char T_5 * V_68 ;
int V_98 , V_67 , V_14 ;
V_14 = F_78 ( V_2 , 0 , true , true ) ;
if ( V_14 )
goto V_90;
V_14 = F_58 ( V_2 , true ) ;
if ( V_14 )
goto V_103;
V_14 = F_79 ( V_2 ) ;
if ( V_14 )
goto V_103;
V_68 = F_56 ( args -> V_84 ) ;
V_78 = args -> V_9 ;
V_79 = V_2 -> V_104 + args -> V_79 ;
while ( V_78 > 0 ) {
V_97 = V_79 & V_105 ;
V_98 = F_63 ( V_79 ) ;
V_67 = V_78 ;
if ( ( V_98 + V_78 ) > V_33 )
V_67 = V_33 - V_98 ;
if ( F_73 ( V_8 -> V_36 . V_106 , V_97 ,
V_98 , V_68 , V_67 ) ) {
V_14 = - V_72 ;
goto V_103;
}
V_78 -= V_67 ;
V_68 += V_67 ;
V_79 += V_67 ;
}
V_103:
F_80 ( V_2 ) ;
V_90:
return V_14 ;
}
static int
F_81 ( struct V_65 * V_65 , int V_66 , int V_67 ,
char T_5 * V_68 ,
bool V_69 ,
bool V_107 ,
bool V_108 )
{
char * V_71 ;
int V_14 ;
if ( F_44 ( V_69 ) )
return - V_34 ;
V_71 = F_45 ( V_65 ) ;
if ( V_107 )
F_46 ( V_71 + V_66 ,
V_67 ) ;
V_14 = F_75 ( V_71 + V_66 ,
V_68 ,
V_67 ) ;
if ( V_108 )
F_46 ( V_71 + V_66 ,
V_67 ) ;
F_48 ( V_71 ) ;
return V_14 ? - V_72 : 0 ;
}
static int
F_82 ( struct V_65 * V_65 , int V_66 , int V_67 ,
char T_5 * V_68 ,
bool V_69 ,
bool V_107 ,
bool V_108 )
{
char * V_71 ;
int V_14 ;
V_71 = F_53 ( V_65 ) ;
if ( F_44 ( V_107 || V_69 ) )
F_49 ( V_71 + V_66 ,
V_67 ,
V_69 ) ;
if ( V_69 )
V_14 = F_41 ( V_71 , V_66 ,
V_68 ,
V_67 ) ;
else
V_14 = F_42 ( V_71 + V_66 ,
V_68 ,
V_67 ) ;
if ( V_108 )
F_49 ( V_71 + V_66 ,
V_67 ,
V_69 ) ;
F_54 ( V_65 ) ;
return V_14 ? - V_72 : 0 ;
}
static int
F_83 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_102 * args ,
struct V_26 * V_27 )
{
T_6 V_78 ;
T_7 V_79 ;
char T_5 * V_68 ;
int V_66 , V_67 , V_14 = 0 ;
int V_80 , V_69 ;
int V_109 = 0 ;
int V_108 = 0 ;
int V_107 = 0 ;
struct V_82 V_83 ;
V_68 = F_56 ( args -> V_84 ) ;
V_78 = args -> V_9 ;
V_80 = F_57 ( V_2 ) ;
if ( V_2 -> V_47 . V_110 != V_86 ) {
if ( V_2 -> V_87 == V_88 )
V_108 = 1 ;
if ( V_2 -> V_23 ) {
V_14 = F_58 ( V_2 , true ) ;
if ( V_14 )
return V_14 ;
}
}
if ( ! ( V_2 -> V_47 . V_85 & V_86 )
&& V_2 -> V_87 == V_88 )
V_107 = 1 ;
V_14 = F_59 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_60 ( V_2 ) ;
V_79 = args -> V_79 ;
V_2 -> V_111 = 1 ;
F_61 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_65 * V_65 = F_62 ( & V_83 ) ;
int V_112 ;
if ( V_78 <= 0 )
break;
V_66 = F_63 ( V_79 ) ;
V_67 = V_78 ;
if ( ( V_66 + V_67 ) > V_33 )
V_67 = V_33 - V_66 ;
V_112 = V_107 &&
( ( V_66 | V_67 )
& ( V_113 . V_114 - 1 ) ) ;
V_69 = V_80 &&
( F_64 ( V_65 ) & ( 1 << 17 ) ) != 0 ;
V_14 = F_81 ( V_65 , V_66 , V_67 ,
V_68 , V_69 ,
V_112 ,
V_108 ) ;
if ( V_14 == 0 )
goto V_89;
V_109 = 1 ;
F_19 ( & V_19 -> V_22 ) ;
V_14 = F_82 ( V_65 , V_66 , V_67 ,
V_68 , V_69 ,
V_112 ,
V_108 ) ;
F_17 ( & V_19 -> V_22 ) ;
V_89:
F_84 ( V_65 ) ;
F_66 ( V_65 ) ;
if ( V_14 )
goto V_90;
V_78 -= V_67 ;
V_68 += V_67 ;
V_79 += V_67 ;
}
V_90:
F_67 ( V_2 ) ;
if ( V_109 ) {
if ( ! V_108 &&
V_2 -> V_47 . V_110 != V_86 ) {
F_85 ( V_2 ) ;
F_86 ( V_19 ) ;
}
}
if ( V_108 )
F_86 ( V_19 ) ;
return V_14 ;
}
int
F_87 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_102 * args = V_25 ;
struct V_1 * V_2 ;
int V_14 ;
if ( args -> V_9 == 0 )
return 0 ;
if ( ! F_69 ( V_115 ,
F_56 ( args -> V_84 ) ,
args -> V_9 ) )
return - V_72 ;
V_14 = F_88 ( F_56 ( args -> V_84 ) ,
args -> V_9 ) ;
if ( V_14 )
return - V_72 ;
V_14 = F_9 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_92 ;
goto V_93;
}
if ( args -> V_79 > V_2 -> V_47 . V_9 ||
args -> V_9 > V_2 -> V_47 . V_9 - args -> V_79 ) {
V_14 = - V_34 ;
goto V_90;
}
if ( ! V_2 -> V_47 . V_94 ) {
V_14 = - V_34 ;
goto V_90;
}
F_89 ( V_2 , args -> V_79 , args -> V_9 ) ;
V_14 = - V_72 ;
if ( V_2 -> V_116 ) {
V_14 = F_90 ( V_19 , V_2 , args , V_27 ) ;
goto V_90;
}
if ( V_2 -> V_87 == V_88 &&
V_2 -> V_3 == V_117 &&
V_2 -> V_47 . V_110 != V_86 ) {
V_14 = F_77 ( V_19 , V_2 , args , V_27 ) ;
}
if ( V_14 == - V_72 || V_14 == - V_118 )
V_14 = F_83 ( V_19 , V_2 , args , V_27 ) ;
V_90:
F_31 ( & V_2 -> V_47 ) ;
V_93:
F_19 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_91 ( struct V_13 * error ,
bool V_119 )
{
if ( F_92 ( error ) ) {
if ( ! V_119 )
return - V_17 ;
if ( F_93 ( error ) )
return - V_17 ;
return - V_120 ;
}
return 0 ;
}
static int
F_94 ( struct V_121 * V_122 , T_4 V_123 )
{
int V_14 ;
F_95 ( ! F_96 ( & V_122 -> V_19 -> V_22 ) ) ;
V_14 = 0 ;
if ( V_123 == V_122 -> V_124 )
V_14 = F_97 ( V_122 , NULL , NULL ) ;
return V_14 ;
}
static int F_98 ( struct V_121 * V_122 , T_4 V_123 ,
unsigned V_125 ,
bool V_119 , struct V_126 * V_127 )
{
T_9 * V_8 = V_122 -> V_19 -> V_20 ;
struct V_126 V_128 , V_129 , V_130 = { 1 , 0 } ;
unsigned long V_131 ;
long V_76 ;
bool V_132 = true ;
int V_14 ;
if ( F_99 ( V_122 -> V_133 ( V_122 , true ) , V_123 ) )
return 0 ;
F_100 ( V_122 , V_123 ) ;
if ( V_127 != NULL ) {
V_130 = * V_127 ;
V_132 = false ;
}
V_131 = F_101 ( & V_130 ) ;
if ( F_11 ( ! V_122 -> V_134 ( V_122 ) ) )
return - V_30 ;
F_102 ( & V_128 ) ;
#define F_6 \
(i915_seqno_passed(ring->get_seqno(ring, false), seqno) || \
i915_reset_in_progress(&dev_priv->gpu_error) || \
reset_counter != atomic_read(&dev_priv->gpu_error.reset_counter))
do {
if ( V_119 )
V_76 = F_7 ( V_122 -> V_135 ,
F_6 ,
V_131 ) ;
else
V_76 = F_103 ( V_122 -> V_135 , F_6 ,
V_131 ) ;
if ( V_125 != F_104 ( & V_8 -> V_21 . V_125 ) )
V_76 = - V_120 ;
V_14 = F_91 ( & V_8 -> V_21 , V_119 ) ;
if ( V_14 )
V_76 = V_14 ;
} while ( V_76 == 0 && V_132 );
F_102 ( & V_129 ) ;
V_122 -> V_136 ( V_122 ) ;
F_105 ( V_122 , V_123 ) ;
#undef F_6
if ( V_127 ) {
struct V_126 V_137 = F_106 ( V_129 , V_128 ) ;
* V_127 = F_106 ( * V_127 , V_137 ) ;
if ( ! F_107 ( V_127 ) )
F_108 ( V_127 , 0 , 0 ) ;
}
switch ( V_76 ) {
case - V_17 :
case - V_120 :
case - V_138 :
return ( int ) V_76 ;
case 0 :
return - V_139 ;
default:
F_11 ( V_76 < 0 ) ;
return 0 ;
}
}
int
F_109 ( struct V_121 * V_122 , T_3 V_123 )
{
struct V_18 * V_19 = V_122 -> V_19 ;
struct V_7 * V_8 = V_19 -> V_20 ;
bool V_119 = V_8 -> V_10 . V_119 ;
int V_14 ;
F_95 ( ! F_96 ( & V_19 -> V_22 ) ) ;
F_95 ( V_123 == 0 ) ;
V_14 = F_91 ( & V_8 -> V_21 , V_119 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_94 ( V_122 , V_123 ) ;
if ( V_14 )
return V_14 ;
return F_98 ( V_122 , V_123 ,
F_104 ( & V_8 -> V_21 . V_125 ) ,
V_119 , NULL ) ;
}
static T_10 int
F_110 ( struct V_1 * V_2 ,
bool V_140 )
{
struct V_121 * V_122 = V_2 -> V_122 ;
T_4 V_123 ;
int V_14 ;
V_123 = V_140 ? V_2 -> V_141 : V_2 -> V_142 ;
if ( V_123 == 0 )
return 0 ;
V_14 = F_109 ( V_122 , V_123 ) ;
if ( V_14 )
return V_14 ;
F_111 ( V_122 ) ;
if ( V_2 -> V_141 &&
F_99 ( V_123 , V_2 -> V_141 ) ) {
V_2 -> V_141 = 0 ;
V_2 -> V_47 . V_110 &= ~ V_143 ;
}
return 0 ;
}
static T_10 int
F_112 ( struct V_1 * V_2 ,
bool V_140 )
{
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_121 * V_122 = V_2 -> V_122 ;
unsigned V_125 ;
T_4 V_123 ;
int V_14 ;
F_95 ( ! F_96 ( & V_19 -> V_22 ) ) ;
F_95 ( ! V_8 -> V_10 . V_119 ) ;
V_123 = V_140 ? V_2 -> V_141 : V_2 -> V_142 ;
if ( V_123 == 0 )
return 0 ;
V_14 = F_91 ( & V_8 -> V_21 , true ) ;
if ( V_14 )
return V_14 ;
V_14 = F_94 ( V_122 , V_123 ) ;
if ( V_14 )
return V_14 ;
V_125 = F_104 ( & V_8 -> V_21 . V_125 ) ;
F_19 ( & V_19 -> V_22 ) ;
V_14 = F_98 ( V_122 , V_123 , V_125 , true , NULL ) ;
F_17 ( & V_19 -> V_22 ) ;
F_111 ( V_122 ) ;
if ( V_2 -> V_141 &&
F_99 ( V_123 , V_2 -> V_141 ) ) {
V_2 -> V_141 = 0 ;
V_2 -> V_47 . V_110 &= ~ V_143 ;
}
return V_14 ;
}
int
F_113 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_144 * args = V_25 ;
struct V_1 * V_2 ;
T_3 V_85 = args -> V_85 ;
T_3 V_110 = args -> V_110 ;
int V_14 ;
if ( V_110 & V_143 )
return - V_34 ;
if ( V_85 & V_143 )
return - V_34 ;
if ( V_110 != 0 && V_85 != V_110 )
return - V_34 ;
V_14 = F_9 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_92 ;
goto V_93;
}
V_14 = F_112 ( V_2 , ! V_110 ) ;
if ( V_14 )
goto V_145;
if ( V_85 & V_146 ) {
V_14 = F_58 ( V_2 , V_110 != 0 ) ;
if ( V_14 == - V_34 )
V_14 = 0 ;
} else {
V_14 = F_114 ( V_2 , V_110 != 0 ) ;
}
V_145:
F_31 ( & V_2 -> V_47 ) ;
V_93:
F_19 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_115 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_147 * args = V_25 ;
struct V_1 * V_2 ;
int V_14 = 0 ;
V_14 = F_9 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_92 ;
goto V_93;
}
if ( V_2 -> V_40 )
F_116 ( V_2 ) ;
F_31 ( & V_2 -> V_47 ) ;
V_93:
F_19 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_117 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_148 * args = V_25 ;
struct V_149 * V_2 ;
unsigned long V_73 ;
V_2 = F_71 ( V_19 , V_27 , args -> V_49 ) ;
if ( V_2 == NULL )
return - V_92 ;
if ( ! V_2 -> V_94 ) {
F_118 ( V_2 ) ;
return - V_34 ;
}
V_73 = F_119 ( V_2 -> V_94 , 0 , args -> V_9 ,
V_150 | V_151 , V_152 ,
args -> V_79 ) ;
F_118 ( V_2 ) ;
if ( F_120 ( ( void * ) V_73 ) )
return V_73 ;
args -> V_153 = ( T_2 ) V_73 ;
return 0 ;
}
int F_121 ( struct V_154 * V_155 , struct V_156 * V_157 )
{
struct V_1 * V_2 = F_70 ( V_155 -> V_158 ) ;
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
T_9 * V_8 = V_19 -> V_20 ;
T_11 V_98 ;
unsigned long V_159 ;
int V_14 = 0 ;
bool V_160 = ! ! ( V_157 -> V_161 & V_162 ) ;
V_98 = ( ( unsigned long ) V_157 -> V_163 - V_155 -> V_164 ) >>
V_165 ;
V_14 = F_9 ( V_19 ) ;
if ( V_14 )
goto V_90;
F_122 ( V_2 , V_98 , true , V_160 ) ;
if ( V_2 -> V_87 != V_88 && ! F_123 ( V_19 ) ) {
V_14 = - V_34 ;
goto V_93;
}
V_14 = F_78 ( V_2 , 0 , true , false ) ;
if ( V_14 )
goto V_93;
V_14 = F_58 ( V_2 , V_160 ) ;
if ( V_14 )
goto V_166;
V_14 = F_124 ( V_2 ) ;
if ( V_14 )
goto V_166;
V_2 -> V_167 = true ;
V_159 = ( ( V_8 -> V_36 . V_168 + V_2 -> V_104 ) >> V_165 ) +
V_98 ;
V_14 = F_125 ( V_155 , ( unsigned long ) V_157 -> V_163 , V_159 ) ;
V_166:
F_80 ( V_2 ) ;
V_93:
F_19 ( & V_19 -> V_22 ) ;
V_90:
switch ( V_14 ) {
case - V_17 :
if ( F_93 ( & V_8 -> V_21 ) )
return V_169 ;
case - V_120 :
F_126 () ;
case 0 :
case - V_138 :
case - V_170 :
case - V_171 :
return V_172 ;
case - V_50 :
return V_173 ;
case - V_118 :
return V_169 ;
default:
F_127 ( V_14 , L_2 , V_14 ) ;
return V_169 ;
}
}
void
F_2 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_167 )
return;
if ( V_2 -> V_47 . V_19 -> V_174 )
F_128 ( V_2 -> V_47 . V_19 -> V_174 ,
( T_7 ) V_2 -> V_47 . V_175 . V_176 . V_177 << V_165 ,
V_2 -> V_47 . V_9 , 1 ) ;
V_2 -> V_167 = false ;
}
T_3
F_129 ( struct V_18 * V_19 , T_3 V_9 , int V_3 )
{
T_3 V_178 ;
if ( F_16 ( V_19 ) -> V_35 >= 4 ||
V_3 == V_117 )
return V_9 ;
if ( F_16 ( V_19 ) -> V_35 == 3 )
V_178 = 1024 * 1024 ;
else
V_178 = 512 * 1024 ;
while ( V_178 < V_9 )
V_178 <<= 1 ;
return V_178 ;
}
T_3
F_130 ( struct V_18 * V_19 , T_3 V_9 ,
int V_3 , bool V_179 )
{
if ( F_16 ( V_19 ) -> V_35 >= 4 || ( ! V_179 && F_131 ( V_19 ) ) ||
V_3 == V_117 )
return 4096 ;
return F_129 ( V_19 , V_9 , V_3 ) ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
int V_14 ;
if ( V_2 -> V_47 . V_175 . V_180 )
return 0 ;
V_8 -> V_10 . V_181 = true ;
V_14 = F_133 ( & V_2 -> V_47 ) ;
if ( V_14 != - V_118 )
goto V_90;
F_134 ( V_8 , V_2 -> V_47 . V_9 >> V_165 ) ;
V_14 = F_133 ( & V_2 -> V_47 ) ;
if ( V_14 != - V_118 )
goto V_90;
F_135 ( V_8 ) ;
V_14 = F_133 ( & V_2 -> V_47 ) ;
V_90:
V_8 -> V_10 . V_181 = false ;
return V_14 ;
}
static void F_136 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_47 . V_175 . V_180 )
return;
F_137 ( & V_2 -> V_47 ) ;
}
int
F_138 ( struct V_26 * V_27 ,
struct V_18 * V_19 ,
T_3 V_49 ,
T_2 * V_79 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_1 * V_2 ;
int V_14 ;
V_14 = F_9 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_92 ;
goto V_93;
}
if ( V_2 -> V_47 . V_9 > V_8 -> V_36 . V_37 ) {
V_14 = - V_182 ;
goto V_90;
}
if ( V_2 -> V_183 != V_184 ) {
F_8 ( L_3 ) ;
V_14 = - V_34 ;
goto V_90;
}
V_14 = F_132 ( V_2 ) ;
if ( V_14 )
goto V_90;
* V_79 = ( V_185 ) V_2 -> V_47 . V_175 . V_176 . V_177 << V_165 ;
V_90:
F_31 ( & V_2 -> V_47 ) ;
V_93:
F_19 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_139 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_186 * args = V_25 ;
return F_138 ( V_27 , V_19 , args -> V_49 , & args -> V_79 ) ;
}
static void
F_140 ( struct V_1 * V_2 )
{
struct V_187 * V_187 ;
F_136 ( V_2 ) ;
if ( V_2 -> V_47 . V_94 == NULL )
return;
V_187 = F_141 ( V_2 -> V_47 . V_94 ) ;
F_142 ( V_187 , 0 , ( T_7 ) - 1 ) ;
V_2 -> V_183 = V_188 ;
}
static inline int
F_143 ( struct V_1 * V_2 )
{
return V_2 -> V_183 == V_189 ;
}
static void
F_144 ( struct V_1 * V_2 )
{
struct V_82 V_83 ;
int V_14 ;
F_95 ( V_2 -> V_183 == V_188 ) ;
V_14 = F_114 ( V_2 , true ) ;
if ( V_14 ) {
F_11 ( V_14 != - V_17 ) ;
F_85 ( V_2 ) ;
V_2 -> V_47 . V_85 = V_2 -> V_47 . V_110 = V_86 ;
}
if ( F_57 ( V_2 ) )
F_145 ( V_2 ) ;
if ( V_2 -> V_183 == V_189 )
V_2 -> V_111 = 0 ;
F_61 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_65 * V_65 = F_62 ( & V_83 ) ;
if ( V_2 -> V_111 )
F_84 ( V_65 ) ;
if ( V_2 -> V_183 == V_184 )
F_66 ( V_65 ) ;
F_146 ( V_65 ) ;
}
V_2 -> V_111 = 0 ;
F_147 ( V_2 -> V_190 ) ;
F_148 ( V_2 -> V_190 ) ;
}
int
F_149 ( struct V_1 * V_2 )
{
const struct V_191 * V_192 = V_2 -> V_192 ;
if ( V_2 -> V_190 == NULL )
return 0 ;
F_95 ( V_2 -> V_23 ) ;
if ( V_2 -> V_193 )
return - V_171 ;
F_150 ( & V_2 -> V_194 ) ;
V_192 -> V_195 ( V_2 ) ;
V_2 -> V_190 = NULL ;
if ( F_143 ( V_2 ) )
F_140 ( V_2 ) ;
return 0 ;
}
static long
F_151 ( struct V_7 * V_8 , long V_196 ,
bool V_197 )
{
struct V_1 * V_2 , * V_198 ;
long V_199 = 0 ;
F_152 (obj, next,
&dev_priv->mm.unbound_list,
gtt_list) {
if ( ( F_143 ( V_2 ) || ! V_197 ) &&
F_149 ( V_2 ) == 0 ) {
V_199 += V_2 -> V_47 . V_9 >> V_165 ;
if ( V_199 >= V_196 )
return V_199 ;
}
}
F_152 (obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if ( ( F_143 ( V_2 ) || ! V_197 ) &&
F_153 ( V_2 ) == 0 &&
F_149 ( V_2 ) == 0 ) {
V_199 += V_2 -> V_47 . V_9 >> V_165 ;
if ( V_199 >= V_196 )
return V_199 ;
}
}
return V_199 ;
}
static long
F_134 ( struct V_7 * V_8 , long V_196 )
{
return F_151 ( V_8 , V_196 , true ) ;
}
static void
F_135 ( struct V_7 * V_8 )
{
struct V_1 * V_2 , * V_198 ;
F_154 ( V_8 -> V_19 ) ;
F_152 (obj, next, &dev_priv->mm.unbound_list, gtt_list)
F_149 ( V_2 ) ;
}
static int
F_155 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
int V_200 , V_201 ;
struct V_202 * V_96 ;
struct V_203 * V_204 ;
struct V_205 * V_206 ;
struct V_82 V_83 ;
struct V_65 * V_65 ;
unsigned long V_207 = 0 ;
T_12 V_208 ;
F_95 ( V_2 -> V_47 . V_85 & V_143 ) ;
F_95 ( V_2 -> V_47 . V_110 & V_143 ) ;
V_204 = F_156 ( sizeof( * V_204 ) , V_45 ) ;
if ( V_204 == NULL )
return - V_50 ;
V_200 = V_2 -> V_47 . V_9 / V_33 ;
if ( F_157 ( V_204 , V_200 , V_45 ) ) {
F_147 ( V_204 ) ;
F_148 ( V_204 ) ;
return - V_50 ;
}
V_96 = F_141 ( V_2 -> V_47 . V_94 ) -> V_209 ;
V_208 = F_158 ( V_96 ) ;
V_208 |= V_210 | V_211 | V_212 ;
V_208 &= ~ ( V_213 | V_214 ) ;
V_206 = V_204 -> V_215 ;
V_204 -> V_216 = 0 ;
for ( V_201 = 0 ; V_201 < V_200 ; V_201 ++ ) {
V_65 = F_159 ( V_96 , V_201 , V_208 ) ;
if ( F_120 ( V_65 ) ) {
F_134 ( V_8 , V_200 ) ;
V_65 = F_159 ( V_96 , V_201 , V_208 ) ;
}
if ( F_120 ( V_65 ) ) {
V_208 &= ~ ( V_210 | V_211 | V_212 ) ;
V_208 |= V_213 | V_214 ;
F_135 ( V_8 ) ;
V_65 = F_159 ( V_96 , V_201 , V_208 ) ;
if ( F_120 ( V_65 ) )
goto V_217;
V_208 |= V_210 | V_211 | V_212 ;
V_208 &= ~ ( V_213 | V_214 ) ;
}
#ifdef F_160
if ( F_161 () ) {
V_204 -> V_216 ++ ;
F_162 ( V_206 , V_65 , V_33 , 0 ) ;
V_206 = F_163 ( V_206 ) ;
continue;
}
#endif
if ( ! V_201 || F_164 ( V_65 ) != V_207 + 1 ) {
if ( V_201 )
V_206 = F_163 ( V_206 ) ;
V_204 -> V_216 ++ ;
F_162 ( V_206 , V_65 , V_33 , 0 ) ;
} else {
V_206 -> V_60 += V_33 ;
}
V_207 = F_164 ( V_65 ) ;
}
#ifdef F_160
if ( ! F_161 () )
#endif
F_165 ( V_206 ) ;
V_2 -> V_190 = V_204 ;
if ( F_57 ( V_2 ) )
F_166 ( V_2 ) ;
return 0 ;
V_217:
F_165 ( V_206 ) ;
F_61 (st->sgl, &sg_iter, st->nents, 0 )
F_146 ( F_62 ( & V_83 ) ) ;
F_147 ( V_204 ) ;
F_148 ( V_204 ) ;
return F_167 ( V_65 ) ;
}
int
F_59 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
const struct V_191 * V_192 = V_2 -> V_192 ;
int V_14 ;
if ( V_2 -> V_190 )
return 0 ;
if ( V_2 -> V_183 != V_184 ) {
F_8 ( L_4 ) ;
return - V_34 ;
}
F_95 ( V_2 -> V_193 ) ;
V_14 = V_192 -> V_218 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_168 ( & V_2 -> V_194 , & V_8 -> V_10 . V_219 ) ;
return 0 ;
}
void
F_169 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
struct V_7 * V_8 = V_19 -> V_20 ;
T_4 V_123 = F_170 ( V_122 ) ;
F_95 ( V_122 == NULL ) ;
V_2 -> V_122 = V_122 ;
if ( ! V_2 -> V_24 ) {
F_171 ( & V_2 -> V_47 ) ;
V_2 -> V_24 = 1 ;
}
F_172 ( & V_2 -> V_220 , & V_8 -> V_10 . V_221 ) ;
F_172 ( & V_2 -> V_222 , & V_122 -> V_221 ) ;
V_2 -> V_142 = V_123 ;
if ( V_2 -> V_223 ) {
V_2 -> V_224 = V_123 ;
if ( V_2 -> V_5 != V_6 ) {
struct V_225 * V_226 ;
V_226 = & V_8 -> V_227 [ V_2 -> V_5 ] ;
F_172 ( & V_226 -> V_228 ,
& V_8 -> V_10 . V_229 ) ;
}
}
}
static void
F_173 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
struct V_7 * V_8 = V_19 -> V_20 ;
F_95 ( V_2 -> V_47 . V_110 & ~ V_143 ) ;
F_95 ( ! V_2 -> V_24 ) ;
F_172 ( & V_2 -> V_220 , & V_8 -> V_10 . V_230 ) ;
F_174 ( & V_2 -> V_222 ) ;
V_2 -> V_122 = NULL ;
V_2 -> V_142 = 0 ;
V_2 -> V_141 = 0 ;
V_2 -> V_47 . V_110 = 0 ;
V_2 -> V_224 = 0 ;
V_2 -> V_223 = false ;
V_2 -> V_24 = 0 ;
F_31 ( & V_2 -> V_47 ) ;
F_11 ( F_12 ( V_19 ) ) ;
}
static int
F_175 ( struct V_18 * V_19 , T_4 V_123 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_121 * V_122 ;
int V_14 , V_201 , V_231 ;
F_176 (ring, dev_priv, i) {
V_14 = F_177 ( V_122 ) ;
if ( V_14 )
return V_14 ;
}
F_178 ( V_19 ) ;
F_176 (ring, dev_priv, i) {
F_179 ( V_122 , V_123 ) ;
for ( V_231 = 0 ; V_231 < F_180 ( V_122 -> V_232 ) ; V_231 ++ )
V_122 -> V_232 [ V_231 ] = 0 ;
}
return 0 ;
}
int F_181 ( struct V_18 * V_19 , T_4 V_123 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
int V_14 ;
if ( V_123 == 0 )
return - V_34 ;
V_14 = F_175 ( V_19 , V_123 - 1 ) ;
if ( V_14 )
return V_14 ;
V_8 -> V_233 = V_123 ;
V_8 -> V_234 = V_123 - 1 ;
if ( V_8 -> V_234 == 0 )
V_8 -> V_234 -- ;
return 0 ;
}
int
F_182 ( struct V_18 * V_19 , T_4 * V_123 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
if ( V_8 -> V_233 == 0 ) {
int V_14 = F_175 ( V_19 , 0 ) ;
if ( V_14 )
return V_14 ;
V_8 -> V_233 = 1 ;
}
* V_123 = V_8 -> V_234 = V_8 -> V_233 ++ ;
return 0 ;
}
int
F_97 ( struct V_121 * V_122 ,
struct V_26 * V_27 ,
T_4 * V_235 )
{
T_9 * V_8 = V_122 -> V_19 -> V_20 ;
struct V_236 * V_237 ;
T_4 V_238 ;
int V_239 ;
int V_14 ;
V_14 = F_183 ( V_122 ) ;
if ( V_14 )
return V_14 ;
V_237 = F_156 ( sizeof( * V_237 ) , V_45 ) ;
if ( V_237 == NULL )
return - V_50 ;
V_238 = F_184 ( V_122 ) ;
V_14 = V_122 -> V_240 ( V_122 ) ;
if ( V_14 ) {
F_148 ( V_237 ) ;
return V_14 ;
}
V_237 -> V_123 = F_170 ( V_122 ) ;
V_237 -> V_122 = V_122 ;
V_237 -> V_241 = V_238 ;
V_237 -> V_242 = V_243 ;
V_239 = F_185 ( & V_122 -> V_244 ) ;
F_168 ( & V_237 -> V_245 , & V_122 -> V_244 ) ;
V_237 -> V_246 = NULL ;
if ( V_27 ) {
struct V_247 * V_246 = V_27 -> V_248 ;
F_186 ( & V_246 -> V_10 . V_249 ) ;
V_237 -> V_246 = V_246 ;
F_168 ( & V_237 -> V_250 ,
& V_246 -> V_10 . V_244 ) ;
F_187 ( & V_246 -> V_10 . V_249 ) ;
}
F_188 ( V_122 , V_237 -> V_123 ) ;
V_122 -> V_124 = 0 ;
if ( ! V_8 -> V_10 . V_251 ) {
if ( V_252 ) {
F_189 ( & V_8 -> V_21 . V_253 ,
F_190 ( V_243 + V_254 ) ) ;
}
if ( V_239 ) {
F_191 ( V_8 -> V_255 ,
& V_8 -> V_10 . V_256 ,
F_192 ( V_16 ) ) ;
F_193 ( V_8 -> V_19 ) ;
}
}
if ( V_235 )
* V_235 = V_237 -> V_123 ;
return 0 ;
}
static inline void
F_194 ( struct V_236 * V_237 )
{
struct V_247 * V_246 = V_237 -> V_246 ;
if ( ! V_246 )
return;
F_186 ( & V_246 -> V_10 . V_249 ) ;
if ( V_237 -> V_246 ) {
F_150 ( & V_237 -> V_250 ) ;
V_237 -> V_246 = NULL ;
}
F_187 ( & V_246 -> V_10 . V_249 ) ;
}
static void F_195 ( struct V_7 * V_8 ,
struct V_121 * V_122 )
{
while ( ! F_185 ( & V_122 -> V_244 ) ) {
struct V_236 * V_237 ;
V_237 = F_196 ( & V_122 -> V_244 ,
struct V_236 ,
V_245 ) ;
F_150 ( & V_237 -> V_245 ) ;
F_194 ( V_237 ) ;
F_148 ( V_237 ) ;
}
while ( ! F_185 ( & V_122 -> V_221 ) ) {
struct V_1 * V_2 ;
V_2 = F_196 ( & V_122 -> V_221 ,
struct V_1 ,
V_222 ) ;
F_173 ( V_2 ) ;
}
}
void F_197 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
int V_201 ;
for ( V_201 = 0 ; V_201 < V_8 -> V_257 ; V_201 ++ ) {
struct V_225 * V_226 = & V_8 -> V_227 [ V_201 ] ;
F_198 ( V_19 , V_201 , V_226 -> V_2 ) ;
}
}
void F_199 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_1 * V_2 ;
struct V_121 * V_122 ;
int V_201 ;
F_176 (ring, dev_priv, i)
F_195 ( V_8 , V_122 ) ;
F_21 (obj,
&dev_priv->mm.inactive_list,
mm_list)
{
V_2 -> V_47 . V_85 &= ~ V_143 ;
}
F_197 ( V_19 ) ;
}
void
F_111 ( struct V_121 * V_122 )
{
T_3 V_123 ;
if ( F_185 ( & V_122 -> V_244 ) )
return;
F_11 ( F_12 ( V_122 -> V_19 ) ) ;
V_123 = V_122 -> V_133 ( V_122 , true ) ;
while ( ! F_185 ( & V_122 -> V_244 ) ) {
struct V_236 * V_237 ;
V_237 = F_196 ( & V_122 -> V_244 ,
struct V_236 ,
V_245 ) ;
if ( ! F_99 ( V_123 , V_237 -> V_123 ) )
break;
F_200 ( V_122 , V_237 -> V_123 ) ;
V_122 -> V_258 = V_237 -> V_241 ;
F_150 ( & V_237 -> V_245 ) ;
F_194 ( V_237 ) ;
F_148 ( V_237 ) ;
}
while ( ! F_185 ( & V_122 -> V_221 ) ) {
struct V_1 * V_2 ;
V_2 = F_196 ( & V_122 -> V_221 ,
struct V_1 ,
V_222 ) ;
if ( ! F_99 ( V_123 , V_2 -> V_142 ) )
break;
F_173 ( V_2 ) ;
}
if ( F_44 ( V_122 -> V_259 &&
F_99 ( V_123 , V_122 -> V_259 ) ) ) {
V_122 -> V_136 ( V_122 ) ;
V_122 -> V_259 = 0 ;
}
F_11 ( F_12 ( V_122 -> V_19 ) ) ;
}
void
F_178 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
struct V_121 * V_122 ;
int V_201 ;
F_176 (ring, dev_priv, i)
F_111 ( V_122 ) ;
}
static void
F_201 ( struct V_260 * V_261 )
{
T_9 * V_8 ;
struct V_18 * V_19 ;
struct V_121 * V_122 ;
bool V_262 ;
int V_201 ;
V_8 = F_202 ( V_261 , T_9 ,
V_10 . V_256 . V_261 ) ;
V_19 = V_8 -> V_19 ;
if ( ! F_203 ( & V_19 -> V_22 ) ) {
F_191 ( V_8 -> V_255 , & V_8 -> V_10 . V_256 ,
F_192 ( V_16 ) ) ;
return;
}
F_178 ( V_19 ) ;
V_262 = true ;
F_176 (ring, dev_priv, i) {
if ( V_122 -> V_263 )
F_97 ( V_122 , NULL , NULL ) ;
V_262 &= F_185 ( & V_122 -> V_244 ) ;
}
if ( ! V_8 -> V_10 . V_251 && ! V_262 )
F_191 ( V_8 -> V_255 , & V_8 -> V_10 . V_256 ,
F_192 ( V_16 ) ) ;
if ( V_262 )
F_204 ( V_19 ) ;
F_19 ( & V_19 -> V_22 ) ;
}
static int
F_205 ( struct V_1 * V_2 )
{
int V_14 ;
if ( V_2 -> V_24 ) {
V_14 = F_94 ( V_2 -> V_122 , V_2 -> V_142 ) ;
if ( V_14 )
return V_14 ;
F_111 ( V_2 -> V_122 ) ;
}
return 0 ;
}
int
F_206 ( struct V_18 * V_19 , void * V_25 , struct V_26 * V_27 )
{
T_9 * V_8 = V_19 -> V_20 ;
struct V_264 * args = V_25 ;
struct V_1 * V_2 ;
struct V_121 * V_122 = NULL ;
struct V_126 V_265 , * V_127 = NULL ;
unsigned V_125 ;
T_4 V_123 = 0 ;
int V_14 = 0 ;
if ( args -> V_266 >= 0 ) {
V_265 = F_207 ( args -> V_266 ) ;
V_127 = & V_265 ;
}
V_14 = F_9 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_267 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
F_19 ( & V_19 -> V_22 ) ;
return - V_92 ;
}
V_14 = F_205 ( V_2 ) ;
if ( V_14 )
goto V_90;
if ( V_2 -> V_24 ) {
V_123 = V_2 -> V_142 ;
V_122 = V_2 -> V_122 ;
}
if ( V_123 == 0 )
goto V_90;
if ( ! args -> V_266 ) {
V_14 = - V_139 ;
goto V_90;
}
F_31 ( & V_2 -> V_47 ) ;
V_125 = F_104 ( & V_8 -> V_21 . V_125 ) ;
F_19 ( & V_19 -> V_22 ) ;
V_14 = F_98 ( V_122 , V_123 , V_125 , true , V_127 ) ;
if ( V_127 )
args -> V_266 = F_208 ( V_127 ) ;
return V_14 ;
V_90:
F_31 ( & V_2 -> V_47 ) ;
F_19 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_209 ( struct V_1 * V_2 ,
struct V_121 * V_268 )
{
struct V_121 * V_269 = V_2 -> V_122 ;
T_4 V_123 ;
int V_14 , V_270 ;
if ( V_269 == NULL || V_268 == V_269 )
return 0 ;
if ( V_268 == NULL || ! F_210 ( V_2 -> V_47 . V_19 ) )
return F_110 ( V_2 , false ) ;
V_270 = F_211 ( V_269 , V_268 ) ;
V_123 = V_2 -> V_142 ;
if ( V_123 <= V_269 -> V_232 [ V_270 ] )
return 0 ;
V_14 = F_94 ( V_2 -> V_122 , V_123 ) ;
if ( V_14 )
return V_14 ;
V_14 = V_268 -> V_271 ( V_268 , V_269 , V_123 ) ;
if ( ! V_14 )
V_269 -> V_232 [ V_270 ] = V_2 -> V_142 ;
return V_14 ;
}
static void F_212 ( struct V_1 * V_2 )
{
T_4 V_272 , V_273 ;
F_2 ( V_2 ) ;
if ( ( V_2 -> V_47 . V_85 & V_146 ) == 0 )
return;
F_213 () ;
V_273 = V_2 -> V_47 . V_85 ;
V_272 = V_2 -> V_47 . V_110 ;
V_2 -> V_47 . V_85 &= ~ V_146 ;
V_2 -> V_47 . V_110 &= ~ V_146 ;
F_214 ( V_2 ,
V_273 ,
V_272 ) ;
}
int
F_153 ( struct V_1 * V_2 )
{
T_9 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
int V_14 ;
if ( V_2 -> V_23 == NULL )
return 0 ;
if ( V_2 -> V_40 )
return - V_171 ;
F_95 ( V_2 -> V_190 == NULL ) ;
V_14 = F_215 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_212 ( V_2 ) ;
V_14 = F_79 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_216 ( V_2 ) ;
if ( V_2 -> V_274 )
F_217 ( V_2 ) ;
if ( V_2 -> V_275 ) {
F_218 ( V_8 -> V_10 . V_276 , V_2 ) ;
V_2 -> V_275 = 0 ;
}
F_219 ( V_2 ) ;
F_150 ( & V_2 -> V_220 ) ;
F_172 ( & V_2 -> V_194 , & V_8 -> V_10 . V_219 ) ;
V_2 -> V_277 = true ;
F_220 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
V_2 -> V_104 = 0 ;
return 0 ;
}
int F_221 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
struct V_121 * V_122 ;
int V_14 , V_201 ;
F_176 (ring, dev_priv, i) {
V_14 = F_222 ( V_122 , NULL , V_278 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_177 ( V_122 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static void F_223 ( struct V_18 * V_19 , int V_226 ,
struct V_1 * V_2 )
{
T_9 * V_8 = V_19 -> V_20 ;
int V_5 ;
int V_279 ;
T_2 V_280 ;
if ( F_16 ( V_19 ) -> V_35 >= 6 ) {
V_5 = V_281 ;
V_279 = V_282 ;
} else {
V_5 = V_283 ;
V_279 = V_284 ;
}
if ( V_2 ) {
T_4 V_9 = V_2 -> V_23 -> V_9 ;
V_280 = ( T_2 ) ( ( V_2 -> V_104 + V_9 - 4096 ) &
0xfffff000 ) << 32 ;
V_280 |= V_2 -> V_104 & 0xfffff000 ;
V_280 |= ( T_2 ) ( ( V_2 -> V_285 / 128 ) - 1 ) << V_279 ;
if ( V_2 -> V_3 == V_286 )
V_280 |= 1 << V_287 ;
V_280 |= V_288 ;
} else
V_280 = 0 ;
V_5 += V_226 * 8 ;
F_224 ( V_5 , V_280 ) ;
F_225 ( V_5 ) ;
}
static void F_226 ( struct V_18 * V_19 , int V_226 ,
struct V_1 * V_2 )
{
T_9 * V_8 = V_19 -> V_20 ;
T_4 V_280 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_23 -> V_9 ;
int V_289 ;
int V_290 ;
F_227 ( ( V_2 -> V_104 & ~ V_291 ) ||
( V_9 & - V_9 ) != V_9 ||
( V_2 -> V_104 & ( V_9 - 1 ) ) ,
L_5 ,
V_2 -> V_104 , V_2 -> V_277 , V_9 ) ;
if ( V_2 -> V_3 == V_286 && F_228 ( V_19 ) )
V_290 = 128 ;
else
V_290 = 512 ;
V_289 = V_2 -> V_285 / V_290 ;
V_289 = F_229 ( V_289 ) - 1 ;
V_280 = V_2 -> V_104 ;
if ( V_2 -> V_3 == V_286 )
V_280 |= 1 << V_292 ;
V_280 |= F_230 ( V_9 ) ;
V_280 |= V_289 << V_293 ;
V_280 |= V_294 ;
} else
V_280 = 0 ;
if ( V_226 < 8 )
V_226 = V_295 + V_226 * 4 ;
else
V_226 = V_296 + ( V_226 - 8 ) * 4 ;
F_231 ( V_226 , V_280 ) ;
F_225 ( V_226 ) ;
}
static void F_232 ( struct V_18 * V_19 , int V_226 ,
struct V_1 * V_2 )
{
T_9 * V_8 = V_19 -> V_20 ;
T_3 V_280 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_23 -> V_9 ;
T_3 V_289 ;
F_227 ( ( V_2 -> V_104 & ~ V_297 ) ||
( V_9 & - V_9 ) != V_9 ||
( V_2 -> V_104 & ( V_9 - 1 ) ) ,
L_6 ,
V_2 -> V_104 , V_9 ) ;
V_289 = V_2 -> V_285 / 128 ;
V_289 = F_229 ( V_289 ) - 1 ;
V_280 = V_2 -> V_104 ;
if ( V_2 -> V_3 == V_286 )
V_280 |= 1 << V_292 ;
V_280 |= F_233 ( V_9 ) ;
V_280 |= V_289 << V_293 ;
V_280 |= V_294 ;
} else
V_280 = 0 ;
F_231 ( V_295 + V_226 * 4 , V_280 ) ;
F_225 ( V_295 + V_226 * 4 ) ;
}
inline static bool F_234 ( struct V_1 * V_2 )
{
return V_2 && V_2 -> V_47 . V_85 & V_146 ;
}
static void F_198 ( struct V_18 * V_19 , int V_226 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
if ( F_234 ( V_8 -> V_227 [ V_226 ] . V_2 ) )
F_213 () ;
switch ( F_16 ( V_19 ) -> V_35 ) {
case 7 :
case 6 :
case 5 :
case 4 : F_223 ( V_19 , V_226 , V_2 ) ; break;
case 3 : F_226 ( V_19 , V_226 , V_2 ) ; break;
case 2 : F_232 ( V_19 , V_226 , V_2 ) ; break;
default: F_235 () ;
}
if ( F_234 ( V_2 ) )
F_213 () ;
}
static inline int F_236 ( struct V_7 * V_8 ,
struct V_225 * V_298 )
{
return V_298 - V_8 -> V_227 ;
}
static void F_237 ( void * V_25 )
{
F_238 () ;
}
static void F_239 ( struct V_1 * V_2 ,
struct V_225 * V_298 ,
bool V_299 )
{
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
struct V_7 * V_8 = V_19 -> V_20 ;
int V_5 = F_236 ( V_8 , V_298 ) ;
if ( F_123 ( V_2 -> V_47 . V_19 ) )
F_240 ( F_237 , NULL , 1 ) ;
F_198 ( V_19 , V_5 , V_299 ? V_2 : NULL ) ;
if ( V_299 ) {
V_2 -> V_5 = V_5 ;
V_298 -> V_2 = V_2 ;
F_172 ( & V_298 -> V_228 , & V_8 -> V_10 . V_229 ) ;
} else {
V_2 -> V_5 = V_6 ;
V_298 -> V_2 = NULL ;
F_174 ( & V_298 -> V_228 ) ;
}
}
static int
F_241 ( struct V_1 * V_2 )
{
if ( V_2 -> V_224 ) {
int V_14 = F_109 ( V_2 -> V_122 , V_2 -> V_224 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_224 = 0 ;
}
V_2 -> V_223 = false ;
return 0 ;
}
int
F_79 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
struct V_225 * V_298 ;
int V_14 ;
V_14 = F_241 ( V_2 ) ;
if ( V_14 )
return V_14 ;
if ( V_2 -> V_5 == V_6 )
return 0 ;
V_298 = & V_8 -> V_227 [ V_2 -> V_5 ] ;
F_1 ( V_2 ) ;
F_239 ( V_2 , V_298 , false ) ;
return 0 ;
}
static struct V_225 *
F_242 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_225 * V_226 , * V_300 ;
int V_201 ;
V_300 = NULL ;
for ( V_201 = V_8 -> V_301 ; V_201 < V_8 -> V_257 ; V_201 ++ ) {
V_226 = & V_8 -> V_227 [ V_201 ] ;
if ( ! V_226 -> V_2 )
return V_226 ;
if ( ! V_226 -> V_40 )
V_300 = V_226 ;
}
if ( V_300 == NULL )
return NULL ;
F_21 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_226 -> V_40 )
continue;
return V_226 ;
}
return NULL ;
}
int
F_124 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
struct V_7 * V_8 = V_19 -> V_20 ;
bool V_299 = V_2 -> V_3 != V_117 ;
struct V_225 * V_226 ;
int V_14 ;
if ( V_2 -> V_4 ) {
V_14 = F_241 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_2 -> V_5 != V_6 ) {
V_226 = & V_8 -> V_227 [ V_2 -> V_5 ] ;
if ( ! V_2 -> V_4 ) {
F_172 ( & V_226 -> V_228 ,
& V_8 -> V_10 . V_229 ) ;
return 0 ;
}
} else if ( V_299 ) {
V_226 = F_242 ( V_19 ) ;
if ( V_226 == NULL )
return - V_302 ;
if ( V_226 -> V_2 ) {
struct V_1 * V_303 = V_226 -> V_2 ;
V_14 = F_241 ( V_303 ) ;
if ( V_14 )
return V_14 ;
F_1 ( V_303 ) ;
}
} else
return 0 ;
F_239 ( V_2 , V_226 , V_299 ) ;
V_2 -> V_4 = false ;
return 0 ;
}
static bool F_243 ( struct V_18 * V_19 ,
struct V_304 * V_23 ,
unsigned long V_87 )
{
struct V_304 * V_305 ;
if ( F_123 ( V_19 ) )
return true ;
if ( V_23 == NULL )
return true ;
if ( F_185 ( & V_23 -> V_306 ) )
return true ;
V_305 = F_244 ( V_23 -> V_306 . V_307 , struct V_304 , V_306 ) ;
if ( V_305 -> V_308 && ! V_305 -> V_309 && V_305 -> V_310 != V_87 )
return false ;
V_305 = F_244 ( V_23 -> V_306 . V_198 , struct V_304 , V_306 ) ;
if ( V_305 -> V_308 && ! V_23 -> V_309 && V_305 -> V_310 != V_87 )
return false ;
return true ;
}
static void F_245 ( struct V_18 * V_19 )
{
#if V_311
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_1 * V_2 ;
int V_312 = 0 ;
F_21 (obj, &dev_priv->mm.gtt_list, gtt_list) {
if ( V_2 -> V_23 == NULL ) {
F_246 ( V_313 L_7 ) ;
V_312 ++ ;
continue;
}
if ( V_2 -> V_87 != V_2 -> V_23 -> V_310 ) {
F_246 ( V_313 L_8 ,
V_2 -> V_23 -> V_75 ,
V_2 -> V_23 -> V_75 + V_2 -> V_23 -> V_9 ,
V_2 -> V_87 ,
V_2 -> V_23 -> V_310 ) ;
V_312 ++ ;
continue;
}
if ( ! F_243 ( V_19 ,
V_2 -> V_23 ,
V_2 -> V_87 ) ) {
F_246 ( V_313 L_9 ,
V_2 -> V_23 -> V_75 ,
V_2 -> V_23 -> V_75 + V_2 -> V_23 -> V_9 ,
V_2 -> V_87 ) ;
V_312 ++ ;
continue;
}
}
F_11 ( V_312 ) ;
#endif
}
static int
F_247 ( struct V_1 * V_2 ,
unsigned V_314 ,
bool V_277 ,
bool V_315 )
{
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
T_9 * V_8 = V_19 -> V_20 ;
struct V_304 * V_316 ;
T_4 V_9 , V_317 , V_318 , V_319 ;
bool V_106 , V_320 ;
int V_14 ;
V_317 = F_129 ( V_19 ,
V_2 -> V_47 . V_9 ,
V_2 -> V_3 ) ;
V_318 = F_130 ( V_19 ,
V_2 -> V_47 . V_9 ,
V_2 -> V_3 , true ) ;
V_319 =
F_130 ( V_19 ,
V_2 -> V_47 . V_9 ,
V_2 -> V_3 , false ) ;
if ( V_314 == 0 )
V_314 = V_277 ? V_318 :
V_319 ;
if ( V_277 && V_314 & ( V_318 - 1 ) ) {
F_8 ( L_10 , V_314 ) ;
return - V_34 ;
}
V_9 = V_277 ? V_317 : V_2 -> V_47 . V_9 ;
if ( V_2 -> V_47 . V_9 >
( V_277 ? V_8 -> V_36 . V_37 : V_8 -> V_36 . V_42 ) ) {
F_8 ( L_11 ) ;
return - V_182 ;
}
V_14 = F_59 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_60 ( V_2 ) ;
V_316 = F_248 ( sizeof( * V_316 ) , V_45 ) ;
if ( V_316 == NULL ) {
F_67 ( V_2 ) ;
return - V_50 ;
}
V_321:
if ( V_277 )
V_14 = F_249 ( & V_8 -> V_10 . V_23 , V_316 ,
V_9 , V_314 , V_2 -> V_87 ,
0 , V_8 -> V_36 . V_37 ) ;
else
V_14 = F_250 ( & V_8 -> V_10 . V_23 , V_316 ,
V_9 , V_314 , V_2 -> V_87 ) ;
if ( V_14 ) {
V_14 = F_251 ( V_19 , V_9 , V_314 ,
V_2 -> V_87 ,
V_277 ,
V_315 ) ;
if ( V_14 == 0 )
goto V_321;
F_67 ( V_2 ) ;
F_148 ( V_316 ) ;
return V_14 ;
}
if ( F_11 ( ! F_243 ( V_19 , V_316 , V_2 -> V_87 ) ) ) {
F_67 ( V_2 ) ;
F_220 ( V_316 ) ;
return - V_34 ;
}
V_14 = F_252 ( V_2 ) ;
if ( V_14 ) {
F_67 ( V_2 ) ;
F_220 ( V_316 ) ;
return V_14 ;
}
F_172 ( & V_2 -> V_194 , & V_8 -> V_10 . V_322 ) ;
F_168 ( & V_2 -> V_220 , & V_8 -> V_10 . V_230 ) ;
V_2 -> V_23 = V_316 ;
V_2 -> V_104 = V_316 -> V_75 ;
V_320 =
V_316 -> V_9 == V_317 &&
( V_316 -> V_75 & ( V_318 - 1 ) ) == 0 ;
V_106 =
V_2 -> V_104 + V_2 -> V_47 . V_9 <= V_8 -> V_36 . V_37 ;
V_2 -> V_277 = V_106 && V_320 ;
F_67 ( V_2 ) ;
F_253 ( V_2 , V_277 ) ;
F_245 ( V_19 ) ;
return 0 ;
}
void
F_85 ( struct V_1 * V_2 )
{
if ( V_2 -> V_190 == NULL )
return;
if ( V_2 -> V_323 )
return;
if ( V_2 -> V_87 != V_88 )
return;
F_254 ( V_2 ) ;
F_255 ( V_2 -> V_190 ) ;
}
static void
F_256 ( struct V_1 * V_2 )
{
T_3 V_272 ;
if ( V_2 -> V_47 . V_110 != V_146 )
return;
F_257 () ;
V_272 = V_2 -> V_47 . V_110 ;
V_2 -> V_47 . V_110 = 0 ;
F_214 ( V_2 ,
V_2 -> V_47 . V_85 ,
V_272 ) ;
}
static void
F_116 ( struct V_1 * V_2 )
{
T_3 V_272 ;
if ( V_2 -> V_47 . V_110 != V_86 )
return;
F_85 ( V_2 ) ;
F_86 ( V_2 -> V_47 . V_19 ) ;
V_272 = V_2 -> V_47 . V_110 ;
V_2 -> V_47 . V_110 = 0 ;
F_214 ( V_2 ,
V_2 -> V_47 . V_85 ,
V_272 ) ;
}
int
F_58 ( struct V_1 * V_2 , bool V_160 )
{
T_9 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
T_3 V_272 , V_273 ;
int V_14 ;
if ( V_2 -> V_23 == NULL )
return - V_34 ;
if ( V_2 -> V_47 . V_110 == V_146 )
return 0 ;
V_14 = F_110 ( V_2 , ! V_160 ) ;
if ( V_14 )
return V_14 ;
F_116 ( V_2 ) ;
if ( ( V_2 -> V_47 . V_85 & V_146 ) == 0 )
F_213 () ;
V_272 = V_2 -> V_47 . V_110 ;
V_273 = V_2 -> V_47 . V_85 ;
F_95 ( ( V_2 -> V_47 . V_110 & ~ V_146 ) != 0 ) ;
V_2 -> V_47 . V_85 |= V_146 ;
if ( V_160 ) {
V_2 -> V_47 . V_85 = V_146 ;
V_2 -> V_47 . V_110 = V_146 ;
V_2 -> V_111 = 1 ;
}
F_214 ( V_2 ,
V_273 ,
V_272 ) ;
if ( F_13 ( V_2 ) )
F_172 ( & V_2 -> V_220 , & V_8 -> V_10 . V_230 ) ;
return 0 ;
}
int F_258 ( struct V_1 * V_2 ,
enum V_324 V_87 )
{
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
T_9 * V_8 = V_19 -> V_20 ;
int V_14 ;
if ( V_2 -> V_87 == V_87 )
return 0 ;
if ( V_2 -> V_40 ) {
F_259 ( L_12 ) ;
return - V_171 ;
}
if ( ! F_243 ( V_19 , V_2 -> V_23 , V_87 ) ) {
V_14 = F_153 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_2 -> V_23 ) {
V_14 = F_215 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_212 ( V_2 ) ;
if ( F_16 ( V_19 ) -> V_35 < 6 ) {
V_14 = F_79 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_2 -> V_274 )
F_260 ( V_2 , V_87 ) ;
if ( V_2 -> V_275 )
F_261 ( V_8 -> V_10 . V_276 ,
V_2 , V_87 ) ;
V_2 -> V_23 -> V_310 = V_87 ;
}
if ( V_87 == V_88 ) {
T_4 V_273 , V_272 ;
F_11 ( V_2 -> V_47 . V_110 & ~ V_86 ) ;
F_11 ( V_2 -> V_47 . V_85 & ~ V_86 ) ;
V_273 = V_2 -> V_47 . V_85 ;
V_272 = V_2 -> V_47 . V_110 ;
V_2 -> V_47 . V_85 = V_86 ;
V_2 -> V_47 . V_110 = V_86 ;
F_214 ( V_2 ,
V_273 ,
V_272 ) ;
}
V_2 -> V_87 = V_87 ;
F_245 ( V_19 ) ;
return 0 ;
}
int F_262 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_325 * args = V_25 ;
struct V_1 * V_2 ;
int V_14 ;
V_14 = F_9 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_92 ;
goto V_93;
}
args -> V_326 = V_2 -> V_87 != V_88 ;
F_31 ( & V_2 -> V_47 ) ;
V_93:
F_19 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int F_263 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_325 * args = V_25 ;
struct V_1 * V_2 ;
enum V_324 V_327 ;
int V_14 ;
switch ( args -> V_326 ) {
case V_328 :
V_327 = V_88 ;
break;
case V_329 :
V_327 = V_330 ;
break;
default:
return - V_34 ;
}
V_14 = F_9 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_92 ;
goto V_93;
}
V_14 = F_258 ( V_2 , V_327 ) ;
F_31 ( & V_2 -> V_47 ) ;
V_93:
F_19 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_264 ( struct V_1 * V_2 ,
T_4 V_314 ,
struct V_121 * V_331 )
{
T_4 V_273 , V_272 ;
int V_14 ;
if ( V_331 != V_2 -> V_122 ) {
V_14 = F_209 ( V_2 , V_331 ) ;
if ( V_14 )
return V_14 ;
}
V_14 = F_258 ( V_2 , V_88 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_78 ( V_2 , V_314 , true , false ) ;
if ( V_14 )
return V_14 ;
F_116 ( V_2 ) ;
V_272 = V_2 -> V_47 . V_110 ;
V_273 = V_2 -> V_47 . V_85 ;
V_2 -> V_47 . V_110 = 0 ;
V_2 -> V_47 . V_85 |= V_146 ;
F_214 ( V_2 ,
V_273 ,
V_272 ) ;
return 0 ;
}
int
F_215 ( struct V_1 * V_2 )
{
int V_14 ;
if ( ( V_2 -> V_47 . V_85 & V_143 ) == 0 )
return 0 ;
V_14 = F_110 ( V_2 , false ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_47 . V_85 &= ~ V_143 ;
return 0 ;
}
int
F_114 ( struct V_1 * V_2 , bool V_160 )
{
T_3 V_272 , V_273 ;
int V_14 ;
if ( V_2 -> V_47 . V_110 == V_86 )
return 0 ;
V_14 = F_110 ( V_2 , ! V_160 ) ;
if ( V_14 )
return V_14 ;
F_256 ( V_2 ) ;
V_272 = V_2 -> V_47 . V_110 ;
V_273 = V_2 -> V_47 . V_85 ;
if ( ( V_2 -> V_47 . V_85 & V_86 ) == 0 ) {
F_85 ( V_2 ) ;
V_2 -> V_47 . V_85 |= V_86 ;
}
F_95 ( ( V_2 -> V_47 . V_110 & ~ V_86 ) != 0 ) ;
if ( V_160 ) {
V_2 -> V_47 . V_85 = V_86 ;
V_2 -> V_47 . V_110 = V_86 ;
}
F_214 ( V_2 ,
V_273 ,
V_272 ) ;
return 0 ;
}
static int
F_265 ( struct V_18 * V_19 , struct V_26 * V_27 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_247 * V_246 = V_27 -> V_248 ;
unsigned long V_332 = V_243 - F_266 ( 20 ) ;
struct V_236 * V_237 ;
struct V_121 * V_122 = NULL ;
unsigned V_125 ;
T_4 V_123 = 0 ;
int V_14 ;
V_14 = F_5 ( & V_8 -> V_21 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_91 ( & V_8 -> V_21 , false ) ;
if ( V_14 )
return V_14 ;
F_186 ( & V_246 -> V_10 . V_249 ) ;
F_21 (request, &file_priv->mm.request_list, client_list) {
if ( F_267 ( V_237 -> V_242 , V_332 ) )
break;
V_122 = V_237 -> V_122 ;
V_123 = V_237 -> V_123 ;
}
V_125 = F_104 ( & V_8 -> V_21 . V_125 ) ;
F_187 ( & V_246 -> V_10 . V_249 ) ;
if ( V_123 == 0 )
return 0 ;
V_14 = F_98 ( V_122 , V_123 , V_125 , true , NULL ) ;
if ( V_14 == 0 )
F_191 ( V_8 -> V_255 , & V_8 -> V_10 . V_256 , 0 ) ;
return V_14 ;
}
int
F_78 ( struct V_1 * V_2 ,
T_3 V_314 ,
bool V_277 ,
bool V_315 )
{
int V_14 ;
if ( F_11 ( V_2 -> V_40 == V_333 ) )
return - V_171 ;
if ( V_2 -> V_23 != NULL ) {
if ( ( V_314 && V_2 -> V_104 & ( V_314 - 1 ) ) ||
( V_277 && ! V_2 -> V_277 ) ) {
F_227 ( V_2 -> V_40 ,
L_13
L_14
L_15 ,
V_2 -> V_104 , V_314 ,
V_277 ,
V_2 -> V_277 ) ;
V_14 = F_153 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
}
if ( V_2 -> V_23 == NULL ) {
struct V_7 * V_8 = V_2 -> V_47 . V_19 -> V_20 ;
V_14 = F_247 ( V_2 , V_314 ,
V_277 ,
V_315 ) ;
if ( V_14 )
return V_14 ;
if ( ! V_8 -> V_10 . V_276 )
F_260 ( V_2 , V_2 -> V_87 ) ;
}
if ( ! V_2 -> V_274 && V_277 )
F_260 ( V_2 , V_2 -> V_87 ) ;
V_2 -> V_40 ++ ;
V_2 -> V_334 |= V_277 ;
return 0 ;
}
void
F_80 ( struct V_1 * V_2 )
{
F_95 ( V_2 -> V_40 == 0 ) ;
F_95 ( V_2 -> V_23 == NULL ) ;
if ( -- V_2 -> V_40 == 0 )
V_2 -> V_334 = false ;
}
int
F_268 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_335 * args = V_25 ;
struct V_1 * V_2 ;
int V_14 ;
V_14 = F_9 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_92 ;
goto V_93;
}
if ( V_2 -> V_183 != V_184 ) {
F_8 ( L_16 ) ;
V_14 = - V_34 ;
goto V_90;
}
if ( V_2 -> V_336 != NULL && V_2 -> V_336 != V_27 ) {
F_8 ( L_17 ,
args -> V_49 ) ;
V_14 = - V_34 ;
goto V_90;
}
if ( V_2 -> V_337 == 0 ) {
V_14 = F_78 ( V_2 , args -> V_314 , true , false ) ;
if ( V_14 )
goto V_90;
}
V_2 -> V_337 ++ ;
V_2 -> V_336 = V_27 ;
F_116 ( V_2 ) ;
args -> V_79 = V_2 -> V_104 ;
V_90:
F_31 ( & V_2 -> V_47 ) ;
V_93:
F_19 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_269 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_335 * args = V_25 ;
struct V_1 * V_2 ;
int V_14 ;
V_14 = F_9 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_92 ;
goto V_93;
}
if ( V_2 -> V_336 != V_27 ) {
F_8 ( L_18 ,
args -> V_49 ) ;
V_14 = - V_34 ;
goto V_90;
}
V_2 -> V_337 -- ;
if ( V_2 -> V_337 == 0 ) {
V_2 -> V_336 = NULL ;
F_80 ( V_2 ) ;
}
V_90:
F_31 ( & V_2 -> V_47 ) ;
V_93:
F_19 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_270 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_338 * args = V_25 ;
struct V_1 * V_2 ;
int V_14 ;
V_14 = F_9 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_27 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_92 ;
goto V_93;
}
V_14 = F_205 ( V_2 ) ;
args -> V_339 = V_2 -> V_24 ;
if ( V_2 -> V_122 ) {
F_271 ( V_340 > 16 ) ;
args -> V_339 |= F_272 ( V_2 -> V_122 ) << 16 ;
}
F_31 ( & V_2 -> V_47 ) ;
V_93:
F_19 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_273 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_246 )
{
return F_265 ( V_19 , V_246 ) ;
}
int
F_274 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_246 )
{
struct V_341 * args = V_25 ;
struct V_1 * V_2 ;
int V_14 ;
switch ( args -> V_183 ) {
case V_189 :
case V_184 :
break;
default:
return - V_34 ;
}
V_14 = F_9 ( V_19 ) ;
if ( V_14 )
return V_14 ;
V_2 = F_70 ( F_71 ( V_19 , V_246 , args -> V_49 ) ) ;
if ( & V_2 -> V_47 == NULL ) {
V_14 = - V_92 ;
goto V_93;
}
if ( V_2 -> V_40 ) {
V_14 = - V_34 ;
goto V_90;
}
if ( V_2 -> V_183 != V_188 )
V_2 -> V_183 = args -> V_183 ;
if ( F_143 ( V_2 ) && V_2 -> V_190 == NULL )
F_140 ( V_2 ) ;
args -> V_342 = V_2 -> V_183 != V_188 ;
V_90:
F_31 ( & V_2 -> V_47 ) ;
V_93:
F_19 ( & V_19 -> V_22 ) ;
return V_14 ;
}
void F_275 ( struct V_1 * V_2 ,
const struct V_191 * V_192 )
{
F_276 ( & V_2 -> V_220 ) ;
F_276 ( & V_2 -> V_194 ) ;
F_276 ( & V_2 -> V_222 ) ;
F_276 ( & V_2 -> V_343 ) ;
V_2 -> V_192 = V_192 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_183 = V_184 ;
V_2 -> V_277 = true ;
F_3 ( V_2 -> V_47 . V_19 -> V_20 , V_2 -> V_47 . V_9 ) ;
}
struct V_1 * F_28 ( struct V_18 * V_19 ,
T_1 V_9 )
{
struct V_1 * V_2 ;
struct V_202 * V_96 ;
T_12 V_344 ;
V_2 = F_22 ( V_19 ) ;
if ( V_2 == NULL )
return NULL ;
if ( F_277 ( V_19 , & V_2 -> V_47 , V_9 ) != 0 ) {
F_24 ( V_2 ) ;
return NULL ;
}
V_344 = V_345 | V_346 ;
if ( F_278 ( V_19 ) || F_279 ( V_19 ) ) {
V_344 &= ~ V_347 ;
V_344 |= V_348 ;
}
V_96 = F_141 ( V_2 -> V_47 . V_94 ) -> V_209 ;
F_280 ( V_96 , V_344 ) ;
F_275 ( V_2 , & V_349 ) ;
V_2 -> V_47 . V_110 = V_86 ;
V_2 -> V_47 . V_85 = V_86 ;
if ( F_123 ( V_19 ) ) {
V_2 -> V_87 = V_330 ;
} else
V_2 -> V_87 = V_88 ;
return V_2 ;
}
int F_281 ( struct V_149 * V_2 )
{
F_235 () ;
return 0 ;
}
void F_282 ( struct V_149 * V_350 )
{
struct V_1 * V_2 = F_70 ( V_350 ) ;
struct V_18 * V_19 = V_2 -> V_47 . V_19 ;
T_9 * V_8 = V_19 -> V_20 ;
F_283 ( V_2 ) ;
if ( V_2 -> V_116 )
F_284 ( V_19 , V_2 ) ;
V_2 -> V_40 = 0 ;
if ( F_11 ( F_153 ( V_2 ) == - V_138 ) ) {
bool V_351 ;
V_351 = V_8 -> V_10 . V_119 ;
V_8 -> V_10 . V_119 = false ;
F_11 ( F_153 ( V_2 ) ) ;
V_8 -> V_10 . V_119 = V_351 ;
}
V_2 -> V_193 = 0 ;
F_149 ( V_2 ) ;
F_136 ( V_2 ) ;
F_285 ( V_2 ) ;
F_95 ( V_2 -> V_190 ) ;
if ( V_2 -> V_47 . V_352 )
F_286 ( & V_2 -> V_47 , NULL ) ;
F_30 ( & V_2 -> V_47 ) ;
F_4 ( V_8 , V_2 -> V_47 . V_9 ) ;
F_148 ( V_2 -> V_353 ) ;
F_24 ( V_2 ) ;
}
int
F_287 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
int V_14 ;
F_17 ( & V_19 -> V_22 ) ;
if ( V_8 -> V_10 . V_251 ) {
F_19 ( & V_19 -> V_22 ) ;
return 0 ;
}
V_14 = F_221 ( V_19 ) ;
if ( V_14 ) {
F_19 ( & V_19 -> V_22 ) ;
return V_14 ;
}
F_178 ( V_19 ) ;
if ( ! F_15 ( V_19 , V_29 ) )
F_154 ( V_19 ) ;
V_8 -> V_10 . V_251 = 1 ;
F_288 ( & V_8 -> V_21 . V_253 ) ;
F_289 ( V_19 ) ;
F_290 ( V_19 ) ;
F_19 ( & V_19 -> V_22 ) ;
F_291 ( & V_8 -> V_10 . V_256 ) ;
return 0 ;
}
void F_292 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
T_4 V_354 ;
int V_201 ;
if ( ! F_293 ( V_19 ) )
return;
if ( ! V_8 -> V_355 . V_356 )
return;
V_354 = F_294 ( V_357 ) ;
F_231 ( V_357 , V_354 & ~ V_358 ) ;
F_225 ( V_357 ) ;
for ( V_201 = 0 ; V_201 < V_359 ; V_201 += 4 ) {
T_4 V_360 = F_294 ( V_361 + V_201 ) ;
if ( V_360 && V_360 != V_8 -> V_355 . V_356 [ V_201 / 4 ] )
F_259 ( L_19 ,
V_361 + V_201 , V_360 ) ;
if ( V_360 && ! V_8 -> V_355 . V_356 [ V_201 / 4 ] )
F_295 ( L_20 ) ;
F_231 ( V_361 + V_201 , V_8 -> V_355 . V_356 [ V_201 / 4 ] ) ;
}
F_225 ( V_361 ) ;
F_231 ( V_357 , V_354 ) ;
}
void F_296 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
if ( F_16 ( V_19 ) -> V_35 < 5 ||
V_8 -> V_10 . V_362 == V_363 )
return;
F_231 ( V_364 , F_294 ( V_364 ) |
V_365 ) ;
if ( F_297 ( V_19 ) )
return;
F_231 ( V_366 , F_294 ( V_366 ) | V_367 ) ;
if ( F_298 ( V_19 ) )
F_231 ( V_368 , F_299 ( V_369 ) ) ;
else if ( F_300 ( V_19 ) )
F_231 ( V_368 , F_299 ( V_370 ) ) ;
else
F_235 () ;
}
static bool
F_301 ( struct V_18 * V_19 )
{
if ( ! F_302 ( V_19 ) )
return false ;
if ( F_298 ( V_19 ) && V_19 -> V_371 -> V_372 < 8 ) {
F_303 ( L_21
L_22 ) ;
return false ;
}
return true ;
}
static int F_304 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
int V_14 ;
V_14 = F_305 ( V_19 ) ;
if ( V_14 )
return V_14 ;
if ( F_306 ( V_19 ) ) {
V_14 = F_307 ( V_19 ) ;
if ( V_14 )
goto V_373;
}
if ( F_301 ( V_19 ) ) {
V_14 = F_308 ( V_19 ) ;
if ( V_14 )
goto V_374;
}
V_14 = F_181 ( V_19 , ( ( T_4 ) ~ 0 - 0x1000 ) ) ;
if ( V_14 )
goto V_375;
return 0 ;
V_375:
F_309 ( & V_8 -> V_122 [ V_376 ] ) ;
V_374:
F_309 ( & V_8 -> V_122 [ V_377 ] ) ;
V_373:
F_309 ( & V_8 -> V_122 [ V_378 ] ) ;
return V_14 ;
}
int
F_310 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
int V_14 ;
if ( F_16 ( V_19 ) -> V_35 < 6 && ! F_311 () )
return - V_17 ;
if ( F_312 ( V_19 ) && ( F_294 ( 0x120010 ) == 1 ) )
F_231 ( 0x9008 , F_294 ( 0x9008 ) | 0xf0000 ) ;
if ( F_313 ( V_19 ) ) {
T_4 V_379 = F_294 ( V_380 ) ;
V_379 &= ~ ( V_381 | V_382 ) ;
F_231 ( V_380 , V_379 ) ;
}
F_292 ( V_19 ) ;
F_296 ( V_19 ) ;
V_14 = F_304 ( V_19 ) ;
if ( V_14 )
return V_14 ;
F_314 ( V_19 ) ;
if ( V_8 -> V_10 . V_276 ) {
V_14 = V_8 -> V_10 . V_276 -> V_299 ( V_19 ) ;
if ( V_14 ) {
F_315 ( V_19 ) ;
F_303 ( L_23 ) ;
}
}
return 0 ;
}
int F_316 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
int V_14 ;
F_17 ( & V_19 -> V_22 ) ;
if ( F_317 ( V_19 ) ) {
F_231 ( V_383 , 1 ) ;
if ( F_318 ( ( F_294 ( V_384 ) & 1 ) == 1 , 10 ) )
F_295 ( L_24 ) ;
}
F_319 ( V_19 ) ;
V_14 = F_310 ( V_19 ) ;
F_19 ( & V_19 -> V_22 ) ;
if ( V_14 ) {
F_315 ( V_19 ) ;
return V_14 ;
}
if ( ! F_15 ( V_19 , V_29 ) )
V_8 -> V_385 . V_386 = 1 ;
return 0 ;
}
void
F_290 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
struct V_121 * V_122 ;
int V_201 ;
F_176 (ring, dev_priv, i)
F_309 ( V_122 ) ;
}
int
F_320 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_246 )
{
T_9 * V_8 = V_19 -> V_20 ;
int V_14 ;
if ( F_15 ( V_19 , V_29 ) )
return 0 ;
if ( F_92 ( & V_8 -> V_21 ) ) {
F_8 ( L_25 ) ;
F_321 ( & V_8 -> V_21 . V_125 , 0 ) ;
}
F_17 ( & V_19 -> V_22 ) ;
V_8 -> V_10 . V_251 = 0 ;
V_14 = F_310 ( V_19 ) ;
if ( V_14 != 0 ) {
F_19 ( & V_19 -> V_22 ) ;
return V_14 ;
}
F_95 ( ! F_185 ( & V_8 -> V_10 . V_221 ) ) ;
F_19 ( & V_19 -> V_22 ) ;
V_14 = F_322 ( V_19 ) ;
if ( V_14 )
goto V_387;
return 0 ;
V_387:
F_17 ( & V_19 -> V_22 ) ;
F_290 ( V_19 ) ;
V_8 -> V_10 . V_251 = 1 ;
F_19 ( & V_19 -> V_22 ) ;
return V_14 ;
}
int
F_323 ( struct V_18 * V_19 , void * V_25 ,
struct V_26 * V_246 )
{
if ( F_15 ( V_19 , V_29 ) )
return 0 ;
F_324 ( V_19 ) ;
return F_287 ( V_19 ) ;
}
void
F_325 ( struct V_18 * V_19 )
{
int V_14 ;
if ( F_15 ( V_19 , V_29 ) )
return;
V_14 = F_287 ( V_19 ) ;
if ( V_14 )
F_8 ( L_26 , V_14 ) ;
}
static void
F_326 ( struct V_121 * V_122 )
{
F_276 ( & V_122 -> V_221 ) ;
F_276 ( & V_122 -> V_244 ) ;
}
void
F_327 ( struct V_18 * V_19 )
{
T_9 * V_8 = V_19 -> V_20 ;
int V_201 ;
V_8 -> V_44 =
F_328 ( L_27 ,
sizeof( struct V_1 ) , 0 ,
V_388 ,
NULL ) ;
F_276 ( & V_8 -> V_10 . V_221 ) ;
F_276 ( & V_8 -> V_10 . V_230 ) ;
F_276 ( & V_8 -> V_10 . V_219 ) ;
F_276 ( & V_8 -> V_10 . V_322 ) ;
F_276 ( & V_8 -> V_10 . V_229 ) ;
for ( V_201 = 0 ; V_201 < V_340 ; V_201 ++ )
F_326 ( & V_8 -> V_122 [ V_201 ] ) ;
for ( V_201 = 0 ; V_201 < V_389 ; V_201 ++ )
F_276 ( & V_8 -> V_227 [ V_201 ] . V_228 ) ;
F_329 ( & V_8 -> V_10 . V_256 ,
F_201 ) ;
F_330 ( & V_8 -> V_21 . V_15 ) ;
if ( F_331 ( V_19 ) ) {
F_231 ( V_390 ,
F_299 ( V_391 ) ) ;
}
V_8 -> V_392 = V_393 ;
if ( ! F_15 ( V_19 , V_29 ) )
V_8 -> V_301 = 3 ;
if ( F_16 ( V_19 ) -> V_35 >= 7 && ! F_317 ( V_19 ) )
V_8 -> V_257 = 32 ;
else if ( F_16 ( V_19 ) -> V_35 >= 4 || F_332 ( V_19 ) || F_333 ( V_19 ) || F_131 ( V_19 ) )
V_8 -> V_257 = 16 ;
else
V_8 -> V_257 = 8 ;
F_276 ( & V_8 -> V_10 . V_229 ) ;
F_197 ( V_19 ) ;
F_334 ( V_19 ) ;
F_330 ( & V_8 -> V_394 ) ;
V_8 -> V_10 . V_119 = true ;
V_8 -> V_10 . V_395 . V_396 = V_397 ;
V_8 -> V_10 . V_395 . V_398 = V_399 ;
F_335 ( & V_8 -> V_10 . V_395 ) ;
}
static int F_336 ( struct V_18 * V_19 ,
int V_400 , int V_9 , int V_401 )
{
T_9 * V_8 = V_19 -> V_20 ;
struct V_402 * V_116 ;
int V_14 ;
if ( V_8 -> V_10 . V_403 [ V_400 - 1 ] || ! V_9 )
return 0 ;
V_116 = F_248 ( sizeof( struct V_402 ) , V_45 ) ;
if ( ! V_116 )
return - V_50 ;
V_116 -> V_400 = V_400 ;
V_116 -> V_49 = F_337 ( V_19 , V_9 , V_401 ) ;
if ( ! V_116 -> V_49 ) {
V_14 = - V_50 ;
goto V_404;
}
#ifdef F_338
F_339 ( ( unsigned long ) V_116 -> V_49 -> V_71 , V_116 -> V_49 -> V_9 / V_33 ) ;
#endif
V_8 -> V_10 . V_403 [ V_400 - 1 ] = V_116 ;
return 0 ;
V_404:
F_148 ( V_116 ) ;
return V_14 ;
}
static void F_340 ( struct V_18 * V_19 , int V_400 )
{
T_9 * V_8 = V_19 -> V_20 ;
struct V_402 * V_116 ;
if ( ! V_8 -> V_10 . V_403 [ V_400 - 1 ] )
return;
V_116 = V_8 -> V_10 . V_403 [ V_400 - 1 ] ;
if ( V_116 -> V_405 ) {
F_284 ( V_19 , V_116 -> V_405 ) ;
}
#ifdef F_338
F_341 ( ( unsigned long ) V_116 -> V_49 -> V_71 , V_116 -> V_49 -> V_9 / V_33 ) ;
#endif
F_342 ( V_19 , V_116 -> V_49 ) ;
F_148 ( V_116 ) ;
V_8 -> V_10 . V_403 [ V_400 - 1 ] = NULL ;
}
void F_343 ( struct V_18 * V_19 )
{
int V_201 ;
for ( V_201 = V_406 ; V_201 <= V_407 ; V_201 ++ )
F_340 ( V_19 , V_201 ) ;
}
void F_284 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_202 * V_96 = F_141 ( V_2 -> V_47 . V_94 ) -> V_209 ;
char * V_71 ;
int V_201 ;
int V_200 ;
if ( ! V_2 -> V_116 )
return;
V_71 = V_2 -> V_116 -> V_49 -> V_71 ;
V_200 = V_2 -> V_47 . V_9 / V_33 ;
for ( V_201 = 0 ; V_201 < V_200 ; V_201 ++ ) {
struct V_65 * V_65 = F_344 ( V_96 , V_201 ) ;
if ( ! F_120 ( V_65 ) ) {
char * V_408 = F_45 ( V_65 ) ;
memcpy ( V_408 , V_71 + V_201 * V_33 , V_33 ) ;
F_48 ( V_408 ) ;
F_345 ( & V_65 , 1 ) ;
F_84 ( V_65 ) ;
F_66 ( V_65 ) ;
F_146 ( V_65 ) ;
}
}
F_86 ( V_19 ) ;
V_2 -> V_116 -> V_405 = NULL ;
V_2 -> V_116 = NULL ;
}
int
F_346 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_400 ,
int V_401 )
{
struct V_202 * V_96 = F_141 ( V_2 -> V_47 . V_94 ) -> V_209 ;
T_9 * V_8 = V_19 -> V_20 ;
int V_14 = 0 ;
int V_200 ;
int V_201 ;
if ( V_400 > V_407 )
return - V_34 ;
if ( V_2 -> V_116 ) {
if ( V_2 -> V_116 -> V_400 == V_400 )
return 0 ;
F_284 ( V_19 , V_2 ) ;
}
if ( ! V_8 -> V_10 . V_403 [ V_400 - 1 ] ) {
V_14 = F_336 ( V_19 , V_400 ,
V_2 -> V_47 . V_9 , V_401 ) ;
if ( V_14 ) {
F_8 ( L_28 ,
V_400 , V_2 -> V_47 . V_9 ) ;
return V_14 ;
}
}
V_2 -> V_116 = V_8 -> V_10 . V_403 [ V_400 - 1 ] ;
V_2 -> V_116 -> V_405 = V_2 ;
V_200 = V_2 -> V_47 . V_9 / V_33 ;
for ( V_201 = 0 ; V_201 < V_200 ; V_201 ++ ) {
struct V_65 * V_65 ;
char * V_408 , * V_409 ;
V_65 = F_344 ( V_96 , V_201 ) ;
if ( F_120 ( V_65 ) )
return F_167 ( V_65 ) ;
V_409 = F_45 ( V_65 ) ;
V_408 = V_2 -> V_116 -> V_49 -> V_71 + ( V_201 * V_33 ) ;
memcpy ( V_408 , V_409 , V_33 ) ;
F_48 ( V_409 ) ;
F_66 ( V_65 ) ;
F_146 ( V_65 ) ;
}
return 0 ;
}
static int
F_90 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_102 * args ,
struct V_26 * V_246 )
{
void * V_71 = V_2 -> V_116 -> V_49 -> V_71 + args -> V_79 ;
char T_5 * V_68 = F_56 ( args -> V_84 ) ;
if ( F_75 ( V_71 , V_68 , args -> V_9 ) ) {
unsigned long V_100 ;
F_19 ( & V_19 -> V_22 ) ;
V_100 = F_347 ( V_71 , V_68 , args -> V_9 ) ;
F_17 ( & V_19 -> V_22 ) ;
if ( V_100 )
return - V_72 ;
}
F_86 ( V_19 ) ;
return 0 ;
}
void F_348 ( struct V_18 * V_19 , struct V_26 * V_27 )
{
struct V_247 * V_246 = V_27 -> V_248 ;
F_186 ( & V_246 -> V_10 . V_249 ) ;
while ( ! F_185 ( & V_246 -> V_10 . V_244 ) ) {
struct V_236 * V_237 ;
V_237 = F_196 ( & V_246 -> V_10 . V_244 ,
struct V_236 ,
V_250 ) ;
F_150 ( & V_237 -> V_250 ) ;
V_237 -> V_246 = NULL ;
}
F_187 ( & V_246 -> V_10 . V_249 ) ;
}
static bool F_349 ( struct V_410 * V_410 , struct V_411 * V_412 )
{
if ( ! F_96 ( V_410 ) )
return false ;
#if F_350 ( V_413 ) || F_350 ( V_414 )
return V_410 -> V_415 == V_412 ;
#else
return false ;
#endif
}
static int
V_397 ( struct V_416 * V_416 , struct V_417 * V_418 )
{
struct V_7 * V_8 =
F_202 ( V_416 ,
struct V_7 ,
V_10 . V_395 ) ;
struct V_18 * V_19 = V_8 -> V_19 ;
struct V_1 * V_2 ;
int V_419 = V_418 -> V_419 ;
bool V_93 = true ;
int V_420 ;
if ( ! F_203 ( & V_19 -> V_22 ) ) {
if ( ! F_349 ( & V_19 -> V_22 , V_421 ) )
return 0 ;
if ( V_8 -> V_10 . V_181 )
return 0 ;
V_93 = false ;
}
if ( V_419 ) {
V_419 -= F_134 ( V_8 , V_419 ) ;
if ( V_419 > 0 )
V_419 -= F_151 ( V_8 , V_419 ,
false ) ;
if ( V_419 > 0 )
F_135 ( V_8 ) ;
}
V_420 = 0 ;
F_21 (obj, &dev_priv->mm.unbound_list, gtt_list)
if ( V_2 -> V_193 == 0 )
V_420 += V_2 -> V_47 . V_9 >> V_165 ;
F_21 (obj, &dev_priv->mm.inactive_list, gtt_list)
if ( V_2 -> V_40 == 0 && V_2 -> V_193 == 0 )
V_420 += V_2 -> V_47 . V_9 >> V_165 ;
if ( V_93 )
F_19 ( & V_19 -> V_22 ) ;
return V_420 ;
}

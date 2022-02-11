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
F_5 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_16 * V_17 = & V_8 -> V_18 ;
unsigned long V_19 ;
int V_20 ;
if ( ! F_6 ( & V_8 -> V_10 . V_21 ) )
return 0 ;
V_20 = F_7 ( V_17 , 10 * V_22 ) ;
if ( V_20 == 0 ) {
F_8 ( L_1 ) ;
return - V_23 ;
} else if ( V_20 < 0 ) {
return V_20 ;
}
if ( F_6 ( & V_8 -> V_10 . V_21 ) ) {
F_9 ( & V_17 -> V_24 . V_25 , V_19 ) ;
V_17 -> V_26 ++ ;
F_10 ( & V_17 -> V_24 . V_25 , V_19 ) ;
}
return 0 ;
}
int F_11 ( struct V_13 * V_14 )
{
int V_20 ;
V_20 = F_5 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_12 ( & V_14 -> V_27 ) ;
if ( V_20 )
return V_20 ;
F_13 ( F_14 ( V_14 ) ) ;
return 0 ;
}
static inline bool
F_15 ( struct V_1 * V_2 )
{
return V_2 -> V_28 && ! V_2 -> V_29 ;
}
int
F_16 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_33 * args = V_30 ;
if ( F_17 ( V_14 , V_34 ) )
return - V_35 ;
if ( args -> V_36 >= args -> V_37 ||
( args -> V_37 | args -> V_36 ) & ( V_38 - 1 ) )
return - V_39 ;
if ( F_18 ( V_14 ) -> V_40 >= 5 )
return - V_35 ;
F_19 ( & V_14 -> V_27 ) ;
F_20 ( V_14 , args -> V_36 ,
args -> V_37 , args -> V_37 ) ;
F_21 ( & V_14 -> V_27 ) ;
return 0 ;
}
int
F_22 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_41 * args = V_30 ;
struct V_1 * V_2 ;
T_1 V_42 ;
V_42 = 0 ;
F_19 ( & V_14 -> V_27 ) ;
F_23 (obj, &dev_priv->mm.bound_list, gtt_list)
if ( V_2 -> V_43 )
V_42 += V_2 -> V_28 -> V_9 ;
F_21 ( & V_14 -> V_27 ) ;
args -> V_44 = V_8 -> V_10 . V_45 ;
args -> V_46 = args -> V_44 - V_42 ;
return 0 ;
}
static int
F_24 ( struct V_31 * V_32 ,
struct V_13 * V_14 ,
T_2 V_9 ,
T_3 * V_47 )
{
struct V_1 * V_2 ;
int V_20 ;
T_4 V_48 ;
V_9 = F_25 ( V_9 , V_38 ) ;
if ( V_9 == 0 )
return - V_39 ;
V_2 = F_26 ( V_14 , V_9 ) ;
if ( V_2 == NULL )
return - V_49 ;
V_20 = F_27 ( V_32 , & V_2 -> V_50 , & V_48 ) ;
if ( V_20 ) {
F_28 ( & V_2 -> V_50 ) ;
F_4 ( V_14 -> V_15 , V_2 -> V_50 . V_9 ) ;
F_29 ( V_2 ) ;
return V_20 ;
}
F_30 ( & V_2 -> V_50 ) ;
F_31 ( V_2 ) ;
* V_47 = V_48 ;
return 0 ;
}
int
F_32 ( struct V_31 * V_32 ,
struct V_13 * V_14 ,
struct V_51 * args )
{
args -> V_52 = F_33 ( args -> V_53 * ( ( args -> V_54 + 7 ) / 8 ) , 64 ) ;
args -> V_9 = args -> V_52 * args -> V_55 ;
return F_24 ( V_32 , V_14 ,
args -> V_9 , & args -> V_48 ) ;
}
int F_34 ( struct V_31 * V_32 ,
struct V_13 * V_14 ,
T_3 V_48 )
{
return F_35 ( V_32 , V_48 ) ;
}
int
F_36 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_56 * args = V_30 ;
return F_24 ( V_32 , V_14 ,
args -> V_9 , & args -> V_48 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
T_5 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
return V_8 -> V_10 . V_57 == V_58 &&
V_2 -> V_3 != V_59 ;
}
static inline int
F_38 ( char T_6 * V_60 ,
const char * V_61 , int V_62 ,
int V_63 )
{
int V_20 , V_64 = 0 ;
while ( V_63 > 0 ) {
int V_65 = F_33 ( V_62 + 1 , 64 ) ;
int V_66 = F_39 ( V_65 - V_62 , V_63 ) ;
int V_67 = V_62 ^ 64 ;
V_20 = F_40 ( V_60 + V_64 ,
V_61 + V_67 ,
V_66 ) ;
if ( V_20 )
return V_20 + V_63 ;
V_64 += V_66 ;
V_62 += V_66 ;
V_63 -= V_66 ;
}
return 0 ;
}
static inline int
F_41 ( char * V_61 , int V_62 ,
const char T_6 * V_60 ,
int V_63 )
{
int V_20 , V_64 = 0 ;
while ( V_63 > 0 ) {
int V_65 = F_33 ( V_62 + 1 , 64 ) ;
int V_66 = F_39 ( V_65 - V_62 , V_63 ) ;
int V_67 = V_62 ^ 64 ;
V_20 = F_42 ( V_61 + V_67 ,
V_60 + V_64 ,
V_66 ) ;
if ( V_20 )
return V_20 + V_63 ;
V_64 += V_66 ;
V_62 += V_66 ;
V_63 -= V_66 ;
}
return 0 ;
}
static int
F_43 ( struct V_68 * V_68 , int V_69 , int V_70 ,
char T_6 * V_71 ,
bool V_72 , bool V_73 )
{
char * V_74 ;
int V_20 ;
if ( F_44 ( V_72 ) )
return - V_39 ;
V_74 = F_45 ( V_68 ) ;
if ( V_73 )
F_46 ( V_74 + V_69 ,
V_70 ) ;
V_20 = F_47 ( V_71 ,
V_74 + V_69 ,
V_70 ) ;
F_48 ( V_74 ) ;
return V_20 ? - V_75 : 0 ;
}
static void
F_49 ( char * V_76 , unsigned long V_63 ,
bool V_77 )
{
if ( F_44 ( V_77 ) ) {
unsigned long V_78 = ( unsigned long ) V_76 ;
unsigned long V_79 = ( unsigned long ) V_76 + V_63 ;
V_78 = F_50 ( V_78 , 128 ) ;
V_79 = F_51 ( V_79 , 128 ) ;
F_46 ( ( void * ) V_78 , V_79 - V_78 ) ;
} else {
F_46 ( V_76 , V_63 ) ;
}
}
static int
F_52 ( struct V_68 * V_68 , int V_69 , int V_70 ,
char T_6 * V_71 ,
bool V_72 , bool V_73 )
{
char * V_74 ;
int V_20 ;
V_74 = F_53 ( V_68 ) ;
if ( V_73 )
F_49 ( V_74 + V_69 ,
V_70 ,
V_72 ) ;
if ( V_72 )
V_20 = F_38 ( V_71 ,
V_74 , V_69 ,
V_70 ) ;
else
V_20 = F_40 ( V_71 ,
V_74 + V_69 ,
V_70 ) ;
F_54 ( V_68 ) ;
return V_20 ? - V_75 : 0 ;
}
static int
F_55 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_80 * args ,
struct V_31 * V_32 )
{
char T_6 * V_71 ;
T_7 V_81 ;
T_8 V_82 ;
int V_69 , V_70 , V_20 = 0 ;
int V_83 , V_72 ;
int V_84 = 0 ;
int V_85 = 0 ;
int V_73 = 0 ;
struct V_86 * V_87 ;
int V_88 ;
V_71 = ( char T_6 * ) ( V_89 ) args -> V_90 ;
V_81 = args -> V_9 ;
V_83 = F_37 ( V_2 ) ;
if ( ! ( V_2 -> V_50 . V_91 & V_92 ) ) {
if ( V_2 -> V_93 == V_94 )
V_73 = 1 ;
if ( V_2 -> V_28 ) {
V_20 = F_56 ( V_2 , false ) ;
if ( V_20 )
return V_20 ;
}
}
V_20 = F_57 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_58 ( V_2 ) ;
V_82 = args -> V_82 ;
F_59 (obj->pages->sgl, sg, obj->pages->nents, i) {
struct V_68 * V_68 ;
if ( V_88 < V_82 > > V_95 )
continue;
if ( V_81 <= 0 )
break;
V_69 = F_60 ( V_82 ) ;
V_70 = V_81 ;
if ( ( V_69 + V_70 ) > V_38 )
V_70 = V_38 - V_69 ;
V_68 = F_61 ( V_87 ) ;
V_72 = V_83 &&
( F_62 ( V_68 ) & ( 1 << 17 ) ) != 0 ;
V_20 = F_43 ( V_68 , V_69 , V_70 ,
V_71 , V_72 ,
V_73 ) ;
if ( V_20 == 0 )
goto V_96;
V_84 = 1 ;
F_21 ( & V_14 -> V_27 ) ;
if ( ! V_85 ) {
V_20 = F_63 ( V_71 , V_81 ) ;
( void ) V_20 ;
V_85 = 1 ;
}
V_20 = F_52 ( V_68 , V_69 , V_70 ,
V_71 , V_72 ,
V_73 ) ;
F_19 ( & V_14 -> V_27 ) ;
V_96:
F_64 ( V_68 ) ;
if ( V_20 )
goto V_97;
V_81 -= V_70 ;
V_71 += V_70 ;
V_82 += V_70 ;
}
V_97:
F_65 ( V_2 ) ;
if ( V_84 ) {
if ( V_2 -> V_98 == V_99 )
F_66 ( V_2 ) ;
}
return V_20 ;
}
int
F_67 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_80 * args = V_30 ;
struct V_1 * V_2 ;
int V_20 = 0 ;
if ( args -> V_9 == 0 )
return 0 ;
if ( ! F_68 ( V_100 ,
( char T_6 * ) ( V_89 ) args -> V_90 ,
args -> V_9 ) )
return - V_75 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_32 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_101 ;
goto V_102;
}
if ( args -> V_82 > V_2 -> V_50 . V_9 ||
args -> V_9 > V_2 -> V_50 . V_9 - args -> V_82 ) {
V_20 = - V_39 ;
goto V_97;
}
if ( ! V_2 -> V_50 . V_103 ) {
V_20 = - V_39 ;
goto V_97;
}
F_71 ( V_2 , args -> V_82 , args -> V_9 ) ;
V_20 = F_55 ( V_14 , V_2 , args , V_32 ) ;
V_97:
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
static inline int
F_72 ( struct V_104 * V_105 ,
T_8 V_106 , int V_107 ,
char T_6 * V_71 ,
int V_63 )
{
void T_9 * V_108 ;
void * V_74 ;
unsigned long V_109 ;
V_108 = F_73 ( V_105 , V_106 ) ;
V_74 = ( void V_110 * ) V_108 + V_107 ;
V_109 = F_74 ( V_74 ,
V_71 , V_63 ) ;
F_75 ( V_108 ) ;
return V_109 ;
}
static int
F_76 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_111 * args ,
struct V_31 * V_32 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_7 V_81 ;
T_8 V_82 , V_106 ;
char T_6 * V_71 ;
int V_107 , V_70 , V_20 ;
V_20 = F_77 ( V_2 , 0 , true , true ) ;
if ( V_20 )
goto V_97;
V_20 = F_56 ( V_2 , true ) ;
if ( V_20 )
goto V_112;
V_20 = F_78 ( V_2 ) ;
if ( V_20 )
goto V_112;
V_71 = ( char T_6 * ) ( V_89 ) args -> V_90 ;
V_81 = args -> V_9 ;
V_82 = V_2 -> V_113 + args -> V_82 ;
while ( V_81 > 0 ) {
V_106 = V_82 & V_114 ;
V_107 = F_60 ( V_82 ) ;
V_70 = V_81 ;
if ( ( V_107 + V_81 ) > V_38 )
V_70 = V_38 - V_107 ;
if ( F_72 ( V_8 -> V_10 . V_115 , V_106 ,
V_107 , V_71 , V_70 ) ) {
V_20 = - V_75 ;
goto V_112;
}
V_81 -= V_70 ;
V_71 += V_70 ;
V_82 += V_70 ;
}
V_112:
F_79 ( V_2 ) ;
V_97:
return V_20 ;
}
static int
F_80 ( struct V_68 * V_68 , int V_69 , int V_70 ,
char T_6 * V_71 ,
bool V_72 ,
bool V_116 ,
bool V_117 )
{
char * V_74 ;
int V_20 ;
if ( F_44 ( V_72 ) )
return - V_39 ;
V_74 = F_45 ( V_68 ) ;
if ( V_116 )
F_46 ( V_74 + V_69 ,
V_70 ) ;
V_20 = F_74 ( V_74 + V_69 ,
V_71 ,
V_70 ) ;
if ( V_117 )
F_46 ( V_74 + V_69 ,
V_70 ) ;
F_48 ( V_74 ) ;
return V_20 ? - V_75 : 0 ;
}
static int
F_81 ( struct V_68 * V_68 , int V_69 , int V_70 ,
char T_6 * V_71 ,
bool V_72 ,
bool V_116 ,
bool V_117 )
{
char * V_74 ;
int V_20 ;
V_74 = F_53 ( V_68 ) ;
if ( F_44 ( V_116 || V_72 ) )
F_49 ( V_74 + V_69 ,
V_70 ,
V_72 ) ;
if ( V_72 )
V_20 = F_41 ( V_74 , V_69 ,
V_71 ,
V_70 ) ;
else
V_20 = F_42 ( V_74 + V_69 ,
V_71 ,
V_70 ) ;
if ( V_117 )
F_49 ( V_74 + V_69 ,
V_70 ,
V_72 ) ;
F_54 ( V_68 ) ;
return V_20 ? - V_75 : 0 ;
}
static int
F_82 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_111 * args ,
struct V_31 * V_32 )
{
T_7 V_81 ;
T_8 V_82 ;
char T_6 * V_71 ;
int V_69 , V_70 , V_20 = 0 ;
int V_83 , V_72 ;
int V_84 = 0 ;
int V_117 = 0 ;
int V_116 = 0 ;
int V_88 ;
struct V_86 * V_87 ;
V_71 = ( char T_6 * ) ( V_89 ) args -> V_90 ;
V_81 = args -> V_9 ;
V_83 = F_37 ( V_2 ) ;
if ( V_2 -> V_50 . V_118 != V_92 ) {
if ( V_2 -> V_93 == V_94 )
V_117 = 1 ;
if ( V_2 -> V_28 ) {
V_20 = F_56 ( V_2 , true ) ;
if ( V_20 )
return V_20 ;
}
}
if ( ! ( V_2 -> V_50 . V_91 & V_92 )
&& V_2 -> V_93 == V_94 )
V_116 = 1 ;
V_20 = F_57 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_58 ( V_2 ) ;
V_82 = args -> V_82 ;
V_2 -> V_119 = 1 ;
F_59 (obj->pages->sgl, sg, obj->pages->nents, i) {
struct V_68 * V_68 ;
int V_120 ;
if ( V_88 < V_82 > > V_95 )
continue;
if ( V_81 <= 0 )
break;
V_69 = F_60 ( V_82 ) ;
V_70 = V_81 ;
if ( ( V_69 + V_70 ) > V_38 )
V_70 = V_38 - V_69 ;
V_120 = V_116 &&
( ( V_69 | V_70 )
& ( V_121 . V_122 - 1 ) ) ;
V_68 = F_61 ( V_87 ) ;
V_72 = V_83 &&
( F_62 ( V_68 ) & ( 1 << 17 ) ) != 0 ;
V_20 = F_80 ( V_68 , V_69 , V_70 ,
V_71 , V_72 ,
V_120 ,
V_117 ) ;
if ( V_20 == 0 )
goto V_96;
V_84 = 1 ;
F_21 ( & V_14 -> V_27 ) ;
V_20 = F_81 ( V_68 , V_69 , V_70 ,
V_71 , V_72 ,
V_120 ,
V_117 ) ;
F_19 ( & V_14 -> V_27 ) ;
V_96:
F_83 ( V_68 ) ;
F_64 ( V_68 ) ;
if ( V_20 )
goto V_97;
V_81 -= V_70 ;
V_71 += V_70 ;
V_82 += V_70 ;
}
V_97:
F_65 ( V_2 ) ;
if ( V_84 ) {
if ( V_2 -> V_98 == V_99 )
F_66 ( V_2 ) ;
if ( V_2 -> V_50 . V_118 != V_92 ) {
F_84 ( V_2 ) ;
F_85 () ;
}
}
if ( V_117 )
F_85 () ;
return V_20 ;
}
int
F_86 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_111 * args = V_30 ;
struct V_1 * V_2 ;
int V_20 ;
if ( args -> V_9 == 0 )
return 0 ;
if ( ! F_68 ( V_123 ,
( char T_6 * ) ( V_89 ) args -> V_90 ,
args -> V_9 ) )
return - V_75 ;
V_20 = F_87 ( ( char T_6 * ) ( V_89 ) args -> V_90 ,
args -> V_9 ) ;
if ( V_20 )
return - V_75 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_32 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_101 ;
goto V_102;
}
if ( args -> V_82 > V_2 -> V_50 . V_9 ||
args -> V_9 > V_2 -> V_50 . V_9 - args -> V_82 ) {
V_20 = - V_39 ;
goto V_97;
}
if ( ! V_2 -> V_50 . V_103 ) {
V_20 = - V_39 ;
goto V_97;
}
F_88 ( V_2 , args -> V_82 , args -> V_9 ) ;
V_20 = - V_75 ;
if ( V_2 -> V_124 ) {
V_20 = F_89 ( V_14 , V_2 , args , V_32 ) ;
goto V_97;
}
if ( V_2 -> V_93 == V_94 &&
V_2 -> V_3 == V_59 &&
V_2 -> V_50 . V_118 != V_92 ) {
V_20 = F_76 ( V_14 , V_2 , args , V_32 ) ;
}
if ( V_20 == - V_75 || V_20 == - V_125 )
V_20 = F_82 ( V_14 , V_2 , args , V_32 ) ;
V_97:
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_90 ( struct V_7 * V_8 ,
bool V_126 )
{
if ( F_6 ( & V_8 -> V_10 . V_21 ) ) {
struct V_16 * V_17 = & V_8 -> V_18 ;
bool V_127 ;
unsigned long V_19 ;
F_9 ( & V_17 -> V_24 . V_25 , V_19 ) ;
V_127 = V_17 -> V_26 > 0 ;
F_10 ( & V_17 -> V_24 . V_25 , V_19 ) ;
if ( ! V_126 )
return - V_23 ;
if ( V_127 )
return - V_23 ;
return - V_128 ;
}
return 0 ;
}
static int
F_91 ( struct V_129 * V_130 , T_4 V_131 )
{
int V_20 ;
F_92 ( ! F_93 ( & V_130 -> V_14 -> V_27 ) ) ;
V_20 = 0 ;
if ( V_131 == V_130 -> V_132 )
V_20 = F_94 ( V_130 , NULL , NULL ) ;
return V_20 ;
}
static int F_95 ( struct V_129 * V_130 , T_4 V_131 ,
bool V_126 , struct V_133 * V_134 )
{
T_5 * V_8 = V_130 -> V_14 -> V_15 ;
struct V_133 V_135 , V_136 , V_137 = { 1 , 0 } ;
unsigned long V_138 ;
long V_79 ;
bool V_139 = true ;
int V_20 ;
if ( F_96 ( V_130 -> V_140 ( V_130 , true ) , V_131 ) )
return 0 ;
F_97 ( V_130 , V_131 ) ;
if ( V_134 != NULL ) {
V_137 = * V_134 ;
V_139 = false ;
}
V_138 = F_98 ( & V_137 ) ;
if ( F_13 ( ! V_130 -> V_141 ( V_130 ) ) )
return - V_35 ;
F_99 ( & V_135 ) ;
#define F_100 \
(i915_seqno_passed(ring->get_seqno(ring, false), seqno) || \
atomic_read(&dev_priv->mm.wedged))
do {
if ( V_126 )
V_79 = F_101 ( V_130 -> V_142 ,
F_100 ,
V_138 ) ;
else
V_79 = F_102 ( V_130 -> V_142 , F_100 ,
V_138 ) ;
V_20 = F_90 ( V_8 , V_126 ) ;
if ( V_20 )
V_79 = V_20 ;
} while ( V_79 == 0 && V_139 );
F_99 ( & V_136 ) ;
V_130 -> V_143 ( V_130 ) ;
F_103 ( V_130 , V_131 ) ;
#undef F_100
if ( V_134 ) {
struct V_133 V_144 = F_104 ( V_136 , V_135 ) ;
* V_134 = F_104 ( * V_134 , V_144 ) ;
}
switch ( V_79 ) {
case - V_23 :
case - V_128 :
case - V_145 :
return ( int ) V_79 ;
case 0 :
if ( V_134 )
F_105 ( V_134 , 0 , 0 ) ;
return - V_146 ;
default:
F_13 ( V_79 < 0 ) ;
return 0 ;
}
}
int
F_106 ( struct V_129 * V_130 , T_3 V_131 )
{
struct V_13 * V_14 = V_130 -> V_14 ;
struct V_7 * V_8 = V_14 -> V_15 ;
bool V_126 = V_8 -> V_10 . V_126 ;
int V_20 ;
F_92 ( ! F_93 ( & V_14 -> V_27 ) ) ;
F_92 ( V_131 == 0 ) ;
V_20 = F_90 ( V_8 , V_126 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_91 ( V_130 , V_131 ) ;
if ( V_20 )
return V_20 ;
return F_95 ( V_130 , V_131 , V_126 , NULL ) ;
}
static T_10 int
F_107 ( struct V_1 * V_2 ,
bool V_147 )
{
struct V_129 * V_130 = V_2 -> V_130 ;
T_4 V_131 ;
int V_20 ;
V_131 = V_147 ? V_2 -> V_148 : V_2 -> V_149 ;
if ( V_131 == 0 )
return 0 ;
V_20 = F_106 ( V_130 , V_131 ) ;
if ( V_20 )
return V_20 ;
F_108 ( V_130 ) ;
if ( V_2 -> V_148 &&
F_96 ( V_131 , V_2 -> V_148 ) ) {
V_2 -> V_148 = 0 ;
V_2 -> V_50 . V_118 &= ~ V_150 ;
}
return 0 ;
}
static T_10 int
F_109 ( struct V_1 * V_2 ,
bool V_147 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_129 * V_130 = V_2 -> V_130 ;
T_4 V_131 ;
int V_20 ;
F_92 ( ! F_93 ( & V_14 -> V_27 ) ) ;
F_92 ( ! V_8 -> V_10 . V_126 ) ;
V_131 = V_147 ? V_2 -> V_148 : V_2 -> V_149 ;
if ( V_131 == 0 )
return 0 ;
V_20 = F_90 ( V_8 , true ) ;
if ( V_20 )
return V_20 ;
V_20 = F_91 ( V_130 , V_131 ) ;
if ( V_20 )
return V_20 ;
F_21 ( & V_14 -> V_27 ) ;
V_20 = F_95 ( V_130 , V_131 , true , NULL ) ;
F_19 ( & V_14 -> V_27 ) ;
F_108 ( V_130 ) ;
if ( V_2 -> V_148 &&
F_96 ( V_131 , V_2 -> V_148 ) ) {
V_2 -> V_148 = 0 ;
V_2 -> V_50 . V_118 &= ~ V_150 ;
}
return V_20 ;
}
int
F_110 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_151 * args = V_30 ;
struct V_1 * V_2 ;
T_3 V_91 = args -> V_91 ;
T_3 V_118 = args -> V_118 ;
int V_20 ;
if ( V_118 & V_150 )
return - V_39 ;
if ( V_91 & V_150 )
return - V_39 ;
if ( V_118 != 0 && V_91 != V_118 )
return - V_39 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_32 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_101 ;
goto V_102;
}
V_20 = F_109 ( V_2 , ! V_118 ) ;
if ( V_20 )
goto V_152;
if ( V_91 & V_153 ) {
V_20 = F_56 ( V_2 , V_118 != 0 ) ;
if ( V_20 == - V_39 )
V_20 = 0 ;
} else {
V_20 = F_111 ( V_2 , V_118 != 0 ) ;
}
V_152:
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_112 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_154 * args = V_30 ;
struct V_1 * V_2 ;
int V_20 = 0 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_32 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_101 ;
goto V_102;
}
if ( V_2 -> V_43 )
F_113 ( V_2 ) ;
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_114 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_155 * args = V_30 ;
struct V_156 * V_2 ;
unsigned long V_76 ;
V_2 = F_70 ( V_14 , V_32 , args -> V_48 ) ;
if ( V_2 == NULL )
return - V_101 ;
if ( ! V_2 -> V_103 ) {
F_115 ( V_2 ) ;
return - V_39 ;
}
V_76 = F_116 ( V_2 -> V_103 , 0 , args -> V_9 ,
V_157 | V_158 , V_159 ,
args -> V_82 ) ;
F_115 ( V_2 ) ;
if ( F_117 ( ( void * ) V_76 ) )
return V_76 ;
args -> V_160 = ( T_2 ) V_76 ;
return 0 ;
}
int F_118 ( struct V_161 * V_162 , struct V_163 * V_164 )
{
struct V_1 * V_2 = F_69 ( V_162 -> V_165 ) ;
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
T_11 V_107 ;
unsigned long V_166 ;
int V_20 = 0 ;
bool V_167 = ! ! ( V_164 -> V_19 & V_168 ) ;
V_107 = ( ( unsigned long ) V_164 -> V_169 - V_162 -> V_170 ) >>
V_95 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
goto V_97;
F_119 ( V_2 , V_107 , true , V_167 ) ;
if ( ! V_2 -> V_171 ) {
V_20 = F_120 ( V_2 ) ;
if ( V_20 )
goto V_102;
}
if ( ! V_2 -> V_28 ) {
V_20 = F_121 ( V_2 , 0 , true , false ) ;
if ( V_20 )
goto V_102;
V_20 = F_56 ( V_2 , V_167 ) ;
if ( V_20 )
goto V_102;
}
if ( ! V_2 -> V_172 )
F_122 ( V_2 , V_2 -> V_93 ) ;
V_20 = F_123 ( V_2 ) ;
if ( V_20 )
goto V_102;
if ( F_15 ( V_2 ) )
F_124 ( & V_2 -> V_173 , & V_8 -> V_10 . V_174 ) ;
V_2 -> V_175 = true ;
V_166 = ( ( V_8 -> V_10 . V_176 + V_2 -> V_113 ) >> V_95 ) +
V_107 ;
V_20 = F_125 ( V_162 , ( unsigned long ) V_164 -> V_169 , V_166 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
V_97:
switch ( V_20 ) {
case - V_23 :
if ( ! F_6 ( & V_8 -> V_10 . V_21 ) )
return V_177 ;
case - V_128 :
F_126 () ;
case 0 :
case - V_145 :
case - V_178 :
case - V_179 :
return V_180 ;
case - V_49 :
return V_181 ;
case - V_125 :
return V_177 ;
default:
F_127 ( V_20 , L_2 , V_20 ) ;
return V_177 ;
}
}
void
F_2 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_175 )
return;
if ( V_2 -> V_50 . V_14 -> V_182 )
F_128 ( V_2 -> V_50 . V_14 -> V_182 ,
( T_8 ) V_2 -> V_50 . V_183 . V_184 . V_185 << V_95 ,
V_2 -> V_50 . V_9 , 1 ) ;
V_2 -> V_175 = false ;
}
static T_3
F_129 ( struct V_13 * V_14 , T_3 V_9 , int V_3 )
{
T_3 V_186 ;
if ( F_18 ( V_14 ) -> V_40 >= 4 ||
V_3 == V_59 )
return V_9 ;
if ( F_18 ( V_14 ) -> V_40 == 3 )
V_186 = 1024 * 1024 ;
else
V_186 = 512 * 1024 ;
while ( V_186 < V_9 )
V_186 <<= 1 ;
return V_186 ;
}
static T_3
F_130 ( struct V_13 * V_14 ,
T_3 V_9 ,
int V_3 )
{
if ( F_18 ( V_14 ) -> V_40 >= 4 ||
V_3 == V_59 )
return 4096 ;
return F_129 ( V_14 , V_9 , V_3 ) ;
}
T_3
F_131 ( struct V_13 * V_14 ,
T_3 V_9 ,
int V_3 )
{
if ( F_18 ( V_14 ) -> V_40 >= 4 || F_132 ( V_14 ) ||
V_3 == V_59 )
return 4096 ;
return F_129 ( V_14 , V_9 , V_3 ) ;
}
static int F_133 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
int V_20 ;
if ( V_2 -> V_50 . V_183 . V_187 )
return 0 ;
V_20 = F_134 ( & V_2 -> V_50 ) ;
if ( V_20 != - V_125 )
return V_20 ;
F_135 ( V_8 , V_2 -> V_50 . V_9 >> V_95 ) ;
V_20 = F_134 ( & V_2 -> V_50 ) ;
if ( V_20 != - V_125 )
return V_20 ;
F_136 ( V_8 ) ;
return F_134 ( & V_2 -> V_50 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_50 . V_183 . V_187 )
return;
F_138 ( & V_2 -> V_50 ) ;
}
int
F_139 ( struct V_31 * V_32 ,
struct V_13 * V_14 ,
T_3 V_48 ,
T_2 * V_82 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_1 * V_2 ;
int V_20 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_32 , V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_101 ;
goto V_102;
}
if ( V_2 -> V_50 . V_9 > V_8 -> V_10 . V_188 ) {
V_20 = - V_189 ;
goto V_97;
}
if ( V_2 -> V_98 != V_190 ) {
F_8 ( L_3 ) ;
V_20 = - V_39 ;
goto V_97;
}
V_20 = F_133 ( V_2 ) ;
if ( V_20 )
goto V_97;
* V_82 = ( V_191 ) V_2 -> V_50 . V_183 . V_184 . V_185 << V_95 ;
V_97:
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_140 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_192 * args = V_30 ;
return F_139 ( V_32 , V_14 , args -> V_48 , & args -> V_82 ) ;
}
static void
F_66 ( struct V_1 * V_2 )
{
struct V_193 * V_193 ;
F_137 ( V_2 ) ;
if ( V_2 -> V_50 . V_103 == NULL )
return;
V_193 = V_2 -> V_50 . V_103 -> V_194 . V_195 -> V_196 ;
F_141 ( V_193 , 0 , ( T_8 ) - 1 ) ;
V_2 -> V_98 = V_99 ;
}
static inline int
F_142 ( struct V_1 * V_2 )
{
return V_2 -> V_98 == V_197 ;
}
static void
F_143 ( struct V_1 * V_2 )
{
int V_198 = V_2 -> V_50 . V_9 / V_38 ;
struct V_86 * V_87 ;
int V_20 , V_88 ;
F_92 ( V_2 -> V_98 == V_99 ) ;
V_20 = F_111 ( V_2 , true ) ;
if ( V_20 ) {
F_13 ( V_20 != - V_23 ) ;
F_84 ( V_2 ) ;
V_2 -> V_50 . V_91 = V_2 -> V_50 . V_118 = V_92 ;
}
if ( F_37 ( V_2 ) )
F_144 ( V_2 ) ;
if ( V_2 -> V_98 == V_197 )
V_2 -> V_119 = 0 ;
F_59 (obj->pages->sgl, sg, page_count, i) {
struct V_68 * V_68 = F_61 ( V_87 ) ;
if ( V_2 -> V_119 )
F_83 ( V_68 ) ;
if ( V_2 -> V_98 == V_190 )
F_64 ( V_68 ) ;
F_145 ( V_68 ) ;
}
V_2 -> V_119 = 0 ;
F_146 ( V_2 -> V_199 ) ;
F_29 ( V_2 -> V_199 ) ;
}
static int
F_147 ( struct V_1 * V_2 )
{
const struct V_200 * V_201 = V_2 -> V_201 ;
if ( V_2 -> V_199 == NULL )
return 0 ;
F_92 ( V_2 -> V_28 ) ;
if ( V_2 -> V_202 )
return - V_179 ;
V_201 -> V_203 ( V_2 ) ;
V_2 -> V_199 = NULL ;
F_148 ( & V_2 -> V_204 ) ;
if ( F_142 ( V_2 ) )
F_66 ( V_2 ) ;
return 0 ;
}
static long
F_135 ( struct V_7 * V_8 , long V_205 )
{
struct V_1 * V_2 , * V_206 ;
long V_207 = 0 ;
F_149 (obj, next,
&dev_priv->mm.unbound_list,
gtt_list) {
if ( F_142 ( V_2 ) &&
F_147 ( V_2 ) == 0 ) {
V_207 += V_2 -> V_50 . V_9 >> V_95 ;
if ( V_207 >= V_205 )
return V_207 ;
}
}
F_149 (obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if ( F_142 ( V_2 ) &&
F_120 ( V_2 ) == 0 &&
F_147 ( V_2 ) == 0 ) {
V_207 += V_2 -> V_50 . V_9 >> V_95 ;
if ( V_207 >= V_205 )
return V_207 ;
}
}
return V_207 ;
}
static void
F_136 ( struct V_7 * V_8 )
{
struct V_1 * V_2 , * V_206 ;
F_150 ( V_8 -> V_14 ) ;
F_149 (obj, next, &dev_priv->mm.unbound_list, gtt_list)
F_147 ( V_2 ) ;
}
static int
F_151 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
int V_198 , V_88 ;
struct V_208 * V_105 ;
struct V_209 * V_210 ;
struct V_86 * V_87 ;
struct V_68 * V_68 ;
T_12 V_211 ;
F_92 ( V_2 -> V_50 . V_91 & V_150 ) ;
F_92 ( V_2 -> V_50 . V_118 & V_150 ) ;
V_210 = F_152 ( sizeof( * V_210 ) , V_212 ) ;
if ( V_210 == NULL )
return - V_49 ;
V_198 = V_2 -> V_50 . V_9 / V_38 ;
if ( F_153 ( V_210 , V_198 , V_212 ) ) {
F_146 ( V_210 ) ;
F_29 ( V_210 ) ;
return - V_49 ;
}
V_105 = V_2 -> V_50 . V_103 -> V_194 . V_195 -> V_196 -> V_213 ;
V_211 = F_154 ( V_105 ) ;
V_211 |= V_214 | V_215 | V_216 ;
V_211 &= ~ ( V_217 | V_218 ) ;
F_59 (st->sgl, sg, page_count, i) {
V_68 = F_155 ( V_105 , V_88 , V_211 ) ;
if ( F_117 ( V_68 ) ) {
F_135 ( V_8 , V_198 ) ;
V_68 = F_155 ( V_105 , V_88 , V_211 ) ;
}
if ( F_117 ( V_68 ) ) {
V_211 &= ~ ( V_214 | V_215 | V_216 ) ;
V_211 |= V_217 | V_218 ;
F_136 ( V_8 ) ;
V_68 = F_155 ( V_105 , V_88 , V_211 ) ;
if ( F_117 ( V_68 ) )
goto V_219;
V_211 |= V_214 | V_215 | V_216 ;
V_211 &= ~ ( V_217 | V_218 ) ;
}
F_156 ( V_87 , V_68 , V_38 , 0 ) ;
}
V_2 -> V_199 = V_210 ;
if ( F_37 ( V_2 ) )
F_157 ( V_2 ) ;
return 0 ;
V_219:
F_59 (st->sgl, sg, i, page_count)
F_145 ( F_61 ( V_87 ) ) ;
F_146 ( V_210 ) ;
F_29 ( V_210 ) ;
return F_158 ( V_68 ) ;
}
int
F_57 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
const struct V_200 * V_201 = V_2 -> V_201 ;
int V_20 ;
if ( V_2 -> V_199 )
return 0 ;
F_92 ( V_2 -> V_202 ) ;
V_20 = V_201 -> V_220 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_159 ( & V_2 -> V_204 , & V_8 -> V_10 . V_221 ) ;
return 0 ;
}
void
F_160 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
T_4 V_131 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
struct V_7 * V_8 = V_14 -> V_15 ;
F_92 ( V_130 == NULL ) ;
V_2 -> V_130 = V_130 ;
if ( ! V_2 -> V_29 ) {
F_161 ( & V_2 -> V_50 ) ;
V_2 -> V_29 = 1 ;
}
F_124 ( & V_2 -> V_173 , & V_8 -> V_10 . V_222 ) ;
F_124 ( & V_2 -> V_223 , & V_130 -> V_222 ) ;
V_2 -> V_149 = V_131 ;
if ( V_2 -> V_224 ) {
V_2 -> V_225 = V_131 ;
if ( V_2 -> V_5 != V_6 ) {
struct V_226 * V_227 ;
V_227 = & V_8 -> V_228 [ V_2 -> V_5 ] ;
F_124 ( & V_227 -> V_229 ,
& V_8 -> V_10 . V_230 ) ;
}
}
}
static void
F_162 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
struct V_7 * V_8 = V_14 -> V_15 ;
F_92 ( V_2 -> V_50 . V_118 & ~ V_150 ) ;
F_92 ( ! V_2 -> V_29 ) ;
if ( V_2 -> V_43 )
F_163 ( V_2 ) ;
F_124 ( & V_2 -> V_173 , & V_8 -> V_10 . V_174 ) ;
F_164 ( & V_2 -> V_223 ) ;
V_2 -> V_130 = NULL ;
V_2 -> V_149 = 0 ;
V_2 -> V_148 = 0 ;
V_2 -> V_50 . V_118 = 0 ;
V_2 -> V_225 = 0 ;
V_2 -> V_224 = false ;
V_2 -> V_29 = 0 ;
F_30 ( & V_2 -> V_50 ) ;
F_13 ( F_14 ( V_14 ) ) ;
}
static T_4
F_165 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_4 V_131 = V_8 -> V_231 ;
if ( ++ V_8 -> V_231 == 0 )
V_8 -> V_231 = 1 ;
return V_131 ;
}
T_4
F_166 ( struct V_129 * V_130 )
{
if ( V_130 -> V_132 == 0 )
V_130 -> V_132 = F_165 ( V_130 -> V_14 ) ;
return V_130 -> V_132 ;
}
int
F_94 ( struct V_129 * V_130 ,
struct V_31 * V_32 ,
T_4 * V_232 )
{
T_5 * V_8 = V_130 -> V_14 -> V_15 ;
struct V_233 * V_234 ;
T_4 V_235 ;
T_4 V_131 ;
int V_236 ;
int V_20 ;
V_20 = F_167 ( V_130 ) ;
if ( V_20 )
return V_20 ;
V_234 = F_152 ( sizeof( * V_234 ) , V_212 ) ;
if ( V_234 == NULL )
return - V_49 ;
V_131 = F_166 ( V_130 ) ;
V_235 = F_168 ( V_130 ) ;
V_20 = V_130 -> V_237 ( V_130 , & V_131 ) ;
if ( V_20 ) {
F_29 ( V_234 ) ;
return V_20 ;
}
F_169 ( V_130 , V_131 ) ;
V_234 -> V_131 = V_131 ;
V_234 -> V_130 = V_130 ;
V_234 -> V_238 = V_235 ;
V_234 -> V_239 = V_240 ;
V_236 = F_170 ( & V_130 -> V_241 ) ;
F_159 ( & V_234 -> V_242 , & V_130 -> V_241 ) ;
V_234 -> V_243 = NULL ;
if ( V_32 ) {
struct V_244 * V_243 = V_32 -> V_245 ;
F_171 ( & V_243 -> V_10 . V_25 ) ;
V_234 -> V_243 = V_243 ;
F_159 ( & V_234 -> V_246 ,
& V_243 -> V_10 . V_241 ) ;
F_172 ( & V_243 -> V_10 . V_25 ) ;
}
V_130 -> V_132 = 0 ;
if ( ! V_8 -> V_10 . V_247 ) {
if ( V_248 ) {
F_173 ( & V_8 -> V_249 ,
V_240 +
F_174 ( V_250 ) ) ;
}
if ( V_236 ) {
F_175 ( V_8 -> V_251 ,
& V_8 -> V_10 . V_252 , V_22 ) ;
F_176 ( V_8 -> V_14 ) ;
}
}
if ( V_232 )
* V_232 = V_131 ;
return 0 ;
}
static inline void
F_177 ( struct V_233 * V_234 )
{
struct V_244 * V_243 = V_234 -> V_243 ;
if ( ! V_243 )
return;
F_171 ( & V_243 -> V_10 . V_25 ) ;
if ( V_234 -> V_243 ) {
F_148 ( & V_234 -> V_246 ) ;
V_234 -> V_243 = NULL ;
}
F_172 ( & V_243 -> V_10 . V_25 ) ;
}
static void F_178 ( struct V_7 * V_8 ,
struct V_129 * V_130 )
{
while ( ! F_170 ( & V_130 -> V_241 ) ) {
struct V_233 * V_234 ;
V_234 = F_179 ( & V_130 -> V_241 ,
struct V_233 ,
V_242 ) ;
F_148 ( & V_234 -> V_242 ) ;
F_177 ( V_234 ) ;
F_29 ( V_234 ) ;
}
while ( ! F_170 ( & V_130 -> V_222 ) ) {
struct V_1 * V_2 ;
V_2 = F_179 ( & V_130 -> V_222 ,
struct V_1 ,
V_223 ) ;
F_162 ( V_2 ) ;
}
}
static void F_180 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_8 -> V_253 ; V_88 ++ ) {
struct V_226 * V_227 = & V_8 -> V_228 [ V_88 ] ;
F_181 ( V_14 , V_88 , NULL ) ;
if ( V_227 -> V_2 )
F_1 ( V_227 -> V_2 ) ;
V_227 -> V_43 = 0 ;
V_227 -> V_2 = NULL ;
F_182 ( & V_227 -> V_229 ) ;
}
F_182 ( & V_8 -> V_10 . V_230 ) ;
}
void F_183 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_1 * V_2 ;
struct V_129 * V_130 ;
int V_88 ;
F_184 (ring, dev_priv, i)
F_178 ( V_8 , V_130 ) ;
F_23 (obj,
&dev_priv->mm.inactive_list,
mm_list)
{
V_2 -> V_50 . V_91 &= ~ V_150 ;
}
F_180 ( V_14 ) ;
}
void
F_108 ( struct V_129 * V_130 )
{
T_3 V_131 ;
int V_88 ;
if ( F_170 ( & V_130 -> V_241 ) )
return;
F_13 ( F_14 ( V_130 -> V_14 ) ) ;
V_131 = V_130 -> V_140 ( V_130 , true ) ;
for ( V_88 = 0 ; V_88 < F_185 ( V_130 -> V_254 ) ; V_88 ++ )
if ( V_131 >= V_130 -> V_254 [ V_88 ] )
V_130 -> V_254 [ V_88 ] = 0 ;
while ( ! F_170 ( & V_130 -> V_241 ) ) {
struct V_233 * V_234 ;
V_234 = F_179 ( & V_130 -> V_241 ,
struct V_233 ,
V_242 ) ;
if ( ! F_96 ( V_131 , V_234 -> V_131 ) )
break;
F_186 ( V_130 , V_234 -> V_131 ) ;
V_130 -> V_255 = V_234 -> V_238 ;
F_148 ( & V_234 -> V_242 ) ;
F_177 ( V_234 ) ;
F_29 ( V_234 ) ;
}
while ( ! F_170 ( & V_130 -> V_222 ) ) {
struct V_1 * V_2 ;
V_2 = F_179 ( & V_130 -> V_222 ,
struct V_1 ,
V_223 ) ;
if ( ! F_96 ( V_131 , V_2 -> V_149 ) )
break;
F_162 ( V_2 ) ;
}
if ( F_44 ( V_130 -> V_256 &&
F_96 ( V_131 , V_130 -> V_256 ) ) ) {
V_130 -> V_143 ( V_130 ) ;
V_130 -> V_256 = 0 ;
}
F_13 ( F_14 ( V_130 -> V_14 ) ) ;
}
void
F_187 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_129 * V_130 ;
int V_88 ;
F_184 (ring, dev_priv, i)
F_108 ( V_130 ) ;
}
static void
F_188 ( struct V_257 * V_258 )
{
T_5 * V_8 ;
struct V_13 * V_14 ;
struct V_129 * V_130 ;
bool V_259 ;
int V_88 ;
V_8 = F_189 ( V_258 , T_5 ,
V_10 . V_252 . V_258 ) ;
V_14 = V_8 -> V_14 ;
if ( ! F_190 ( & V_14 -> V_27 ) ) {
F_175 ( V_8 -> V_251 , & V_8 -> V_10 . V_252 , V_22 ) ;
return;
}
F_187 ( V_14 ) ;
V_259 = true ;
F_184 (ring, dev_priv, i) {
if ( V_130 -> V_260 )
F_94 ( V_130 , NULL , NULL ) ;
V_259 &= F_170 ( & V_130 -> V_241 ) ;
}
if ( ! V_8 -> V_10 . V_247 && ! V_259 )
F_175 ( V_8 -> V_251 , & V_8 -> V_10 . V_252 , V_22 ) ;
if ( V_259 )
F_191 ( V_14 ) ;
F_21 ( & V_14 -> V_27 ) ;
}
static int
F_192 ( struct V_1 * V_2 )
{
int V_20 ;
if ( V_2 -> V_29 ) {
V_20 = F_91 ( V_2 -> V_130 , V_2 -> V_149 ) ;
if ( V_20 )
return V_20 ;
F_108 ( V_2 -> V_130 ) ;
}
return 0 ;
}
int
F_193 ( struct V_13 * V_14 , void * V_30 , struct V_31 * V_32 )
{
struct V_261 * args = V_30 ;
struct V_1 * V_2 ;
struct V_129 * V_130 = NULL ;
struct V_133 V_262 , * V_134 = NULL ;
T_4 V_131 = 0 ;
int V_20 = 0 ;
if ( args -> V_263 >= 0 ) {
V_262 = F_194 ( args -> V_263 ) ;
V_134 = & V_262 ;
}
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_32 , args -> V_264 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
F_21 ( & V_14 -> V_27 ) ;
return - V_101 ;
}
V_20 = F_192 ( V_2 ) ;
if ( V_20 )
goto V_97;
if ( V_2 -> V_29 ) {
V_131 = V_2 -> V_149 ;
V_130 = V_2 -> V_130 ;
}
if ( V_131 == 0 )
goto V_97;
if ( ! args -> V_263 ) {
V_20 = - V_146 ;
goto V_97;
}
F_30 ( & V_2 -> V_50 ) ;
F_21 ( & V_14 -> V_27 ) ;
V_20 = F_95 ( V_130 , V_131 , true , V_134 ) ;
if ( V_134 ) {
F_13 ( ! F_195 ( V_134 ) ) ;
args -> V_263 = F_196 ( V_134 ) ;
}
return V_20 ;
V_97:
F_30 ( & V_2 -> V_50 ) ;
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_197 ( struct V_1 * V_2 ,
struct V_129 * V_265 )
{
struct V_129 * V_266 = V_2 -> V_130 ;
T_4 V_131 ;
int V_20 , V_267 ;
if ( V_266 == NULL || V_265 == V_266 )
return 0 ;
if ( V_265 == NULL || ! F_198 ( V_2 -> V_50 . V_14 ) )
return F_107 ( V_2 , false ) ;
V_267 = F_199 ( V_266 , V_265 ) ;
V_131 = V_2 -> V_149 ;
if ( V_131 <= V_266 -> V_254 [ V_267 ] )
return 0 ;
V_20 = F_91 ( V_2 -> V_130 , V_131 ) ;
if ( V_20 )
return V_20 ;
V_20 = V_265 -> V_268 ( V_265 , V_266 , V_131 ) ;
if ( ! V_20 )
V_266 -> V_254 [ V_267 ] = V_131 ;
return V_20 ;
}
static void F_200 ( struct V_1 * V_2 )
{
T_4 V_269 , V_270 ;
F_201 () ;
F_2 ( V_2 ) ;
if ( ( V_2 -> V_50 . V_91 & V_153 ) == 0 )
return;
V_270 = V_2 -> V_50 . V_91 ;
V_269 = V_2 -> V_50 . V_118 ;
V_2 -> V_50 . V_91 &= ~ V_153 ;
V_2 -> V_50 . V_118 &= ~ V_153 ;
F_202 ( V_2 ,
V_270 ,
V_269 ) ;
}
int
F_120 ( struct V_1 * V_2 )
{
T_5 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
int V_20 = 0 ;
if ( V_2 -> V_28 == NULL )
return 0 ;
if ( V_2 -> V_43 )
return - V_179 ;
F_92 ( V_2 -> V_199 == NULL ) ;
V_20 = F_203 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_200 ( V_2 ) ;
V_20 = F_78 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_204 ( V_2 ) ;
if ( V_2 -> V_172 )
F_205 ( V_2 ) ;
if ( V_2 -> V_271 ) {
F_206 ( V_8 -> V_10 . V_272 , V_2 ) ;
V_2 -> V_271 = 0 ;
}
F_207 ( V_2 ) ;
F_148 ( & V_2 -> V_173 ) ;
F_124 ( & V_2 -> V_204 , & V_8 -> V_10 . V_221 ) ;
V_2 -> V_171 = true ;
F_208 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
V_2 -> V_113 = 0 ;
return 0 ;
}
static int F_209 ( struct V_129 * V_130 )
{
if ( F_170 ( & V_130 -> V_222 ) )
return 0 ;
return F_106 ( V_130 , F_166 ( V_130 ) ) ;
}
int F_210 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_129 * V_130 ;
int V_20 , V_88 ;
F_184 (ring, dev_priv, i) {
V_20 = F_211 ( V_130 , NULL , V_273 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_209 ( V_130 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static void F_212 ( struct V_13 * V_14 , int V_227 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_2 V_274 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_28 -> V_9 ;
V_274 = ( T_2 ) ( ( V_2 -> V_113 + V_9 - 4096 ) &
0xfffff000 ) << 32 ;
V_274 |= V_2 -> V_113 & 0xfffff000 ;
V_274 |= ( T_2 ) ( ( V_2 -> V_275 / 128 ) - 1 ) <<
V_276 ;
if ( V_2 -> V_3 == V_277 )
V_274 |= 1 << V_278 ;
V_274 |= V_279 ;
} else
V_274 = 0 ;
F_213 ( V_280 + V_227 * 8 , V_274 ) ;
F_214 ( V_280 + V_227 * 8 ) ;
}
static void F_215 ( struct V_13 * V_14 , int V_227 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_2 V_274 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_28 -> V_9 ;
V_274 = ( T_2 ) ( ( V_2 -> V_113 + V_9 - 4096 ) &
0xfffff000 ) << 32 ;
V_274 |= V_2 -> V_113 & 0xfffff000 ;
V_274 |= ( ( V_2 -> V_275 / 128 ) - 1 ) << V_281 ;
if ( V_2 -> V_3 == V_277 )
V_274 |= 1 << V_278 ;
V_274 |= V_279 ;
} else
V_274 = 0 ;
F_213 ( V_282 + V_227 * 8 , V_274 ) ;
F_214 ( V_282 + V_227 * 8 ) ;
}
static void F_216 ( struct V_13 * V_14 , int V_227 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_4 V_274 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_28 -> V_9 ;
int V_283 ;
int V_284 ;
F_217 ( ( V_2 -> V_113 & ~ V_285 ) ||
( V_9 & - V_9 ) != V_9 ||
( V_2 -> V_113 & ( V_9 - 1 ) ) ,
L_4 ,
V_2 -> V_113 , V_2 -> V_171 , V_9 ) ;
if ( V_2 -> V_3 == V_277 && F_218 ( V_14 ) )
V_284 = 128 ;
else
V_284 = 512 ;
V_283 = V_2 -> V_275 / V_284 ;
V_283 = F_219 ( V_283 ) - 1 ;
V_274 = V_2 -> V_113 ;
if ( V_2 -> V_3 == V_277 )
V_274 |= 1 << V_286 ;
V_274 |= F_220 ( V_9 ) ;
V_274 |= V_283 << V_287 ;
V_274 |= V_288 ;
} else
V_274 = 0 ;
if ( V_227 < 8 )
V_227 = V_289 + V_227 * 4 ;
else
V_227 = V_290 + ( V_227 - 8 ) * 4 ;
F_221 ( V_227 , V_274 ) ;
F_214 ( V_227 ) ;
}
static void F_222 ( struct V_13 * V_14 , int V_227 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_3 V_274 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_28 -> V_9 ;
T_3 V_283 ;
F_217 ( ( V_2 -> V_113 & ~ V_291 ) ||
( V_9 & - V_9 ) != V_9 ||
( V_2 -> V_113 & ( V_9 - 1 ) ) ,
L_5 ,
V_2 -> V_113 , V_9 ) ;
V_283 = V_2 -> V_275 / 128 ;
V_283 = F_219 ( V_283 ) - 1 ;
V_274 = V_2 -> V_113 ;
if ( V_2 -> V_3 == V_277 )
V_274 |= 1 << V_286 ;
V_274 |= F_223 ( V_9 ) ;
V_274 |= V_283 << V_287 ;
V_274 |= V_288 ;
} else
V_274 = 0 ;
F_221 ( V_289 + V_227 * 4 , V_274 ) ;
F_214 ( V_289 + V_227 * 4 ) ;
}
static void F_181 ( struct V_13 * V_14 , int V_227 ,
struct V_1 * V_2 )
{
switch ( F_18 ( V_14 ) -> V_40 ) {
case 7 :
case 6 : F_212 ( V_14 , V_227 , V_2 ) ; break;
case 5 :
case 4 : F_215 ( V_14 , V_227 , V_2 ) ; break;
case 3 : F_216 ( V_14 , V_227 , V_2 ) ; break;
case 2 : F_222 ( V_14 , V_227 , V_2 ) ; break;
default: break;
}
}
static inline int F_224 ( struct V_7 * V_8 ,
struct V_226 * V_292 )
{
return V_292 - V_8 -> V_228 ;
}
static void F_225 ( struct V_1 * V_2 ,
struct V_226 * V_292 ,
bool V_293 )
{
struct V_7 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
int V_227 = F_224 ( V_8 , V_292 ) ;
F_181 ( V_2 -> V_50 . V_14 , V_227 , V_293 ? V_2 : NULL ) ;
if ( V_293 ) {
V_2 -> V_5 = V_227 ;
V_292 -> V_2 = V_2 ;
F_124 ( & V_292 -> V_229 , & V_8 -> V_10 . V_230 ) ;
} else {
V_2 -> V_5 = V_6 ;
V_292 -> V_2 = NULL ;
F_164 ( & V_292 -> V_229 ) ;
}
}
static int
F_226 ( struct V_1 * V_2 )
{
if ( V_2 -> V_225 ) {
int V_20 = F_106 ( V_2 -> V_130 , V_2 -> V_225 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_225 = 0 ;
}
if ( V_2 -> V_50 . V_91 & V_153 )
F_201 () ;
V_2 -> V_224 = false ;
return 0 ;
}
int
F_78 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
int V_20 ;
V_20 = F_226 ( V_2 ) ;
if ( V_20 )
return V_20 ;
if ( V_2 -> V_5 == V_6 )
return 0 ;
F_225 ( V_2 ,
& V_8 -> V_228 [ V_2 -> V_5 ] ,
false ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static struct V_226 *
F_227 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_226 * V_227 , * V_294 ;
int V_88 ;
V_294 = NULL ;
for ( V_88 = V_8 -> V_295 ; V_88 < V_8 -> V_253 ; V_88 ++ ) {
V_227 = & V_8 -> V_228 [ V_88 ] ;
if ( ! V_227 -> V_2 )
return V_227 ;
if ( ! V_227 -> V_43 )
V_294 = V_227 ;
}
if ( V_294 == NULL )
return NULL ;
F_23 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_227 -> V_43 )
continue;
return V_227 ;
}
return NULL ;
}
int
F_123 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
struct V_7 * V_8 = V_14 -> V_15 ;
bool V_293 = V_2 -> V_3 != V_59 ;
struct V_226 * V_227 ;
int V_20 ;
if ( V_2 -> V_4 ) {
V_20 = F_226 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_2 -> V_5 != V_6 ) {
V_227 = & V_8 -> V_228 [ V_2 -> V_5 ] ;
if ( ! V_2 -> V_4 ) {
F_124 ( & V_227 -> V_229 ,
& V_8 -> V_10 . V_230 ) ;
return 0 ;
}
} else if ( V_293 ) {
V_227 = F_227 ( V_14 ) ;
if ( V_227 == NULL )
return - V_296 ;
if ( V_227 -> V_2 ) {
struct V_1 * V_297 = V_227 -> V_2 ;
V_20 = F_226 ( V_297 ) ;
if ( V_20 )
return V_20 ;
F_1 ( V_297 ) ;
}
} else
return 0 ;
F_225 ( V_2 , V_227 , V_293 ) ;
V_2 -> V_4 = false ;
return 0 ;
}
static bool F_228 ( struct V_13 * V_14 ,
struct V_298 * V_28 ,
unsigned long V_93 )
{
struct V_298 * V_299 ;
if ( F_229 ( V_14 ) )
return true ;
if ( V_28 == NULL )
return true ;
if ( F_170 ( & V_28 -> V_300 ) )
return true ;
V_299 = F_230 ( V_28 -> V_300 . V_301 , struct V_298 , V_300 ) ;
if ( V_299 -> V_302 && ! V_299 -> V_303 && V_299 -> V_304 != V_93 )
return false ;
V_299 = F_230 ( V_28 -> V_300 . V_206 , struct V_298 , V_300 ) ;
if ( V_299 -> V_302 && ! V_28 -> V_303 && V_299 -> V_304 != V_93 )
return false ;
return true ;
}
static void F_231 ( struct V_13 * V_14 )
{
#if V_305
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_1 * V_2 ;
int V_306 = 0 ;
F_23 (obj, &dev_priv->mm.gtt_list, gtt_list) {
if ( V_2 -> V_28 == NULL ) {
F_232 ( V_307 L_6 ) ;
V_306 ++ ;
continue;
}
if ( V_2 -> V_93 != V_2 -> V_28 -> V_304 ) {
F_232 ( V_307 L_7 ,
V_2 -> V_28 -> V_78 ,
V_2 -> V_28 -> V_78 + V_2 -> V_28 -> V_9 ,
V_2 -> V_93 ,
V_2 -> V_28 -> V_304 ) ;
V_306 ++ ;
continue;
}
if ( ! F_228 ( V_14 ,
V_2 -> V_28 ,
V_2 -> V_93 ) ) {
F_232 ( V_307 L_8 ,
V_2 -> V_28 -> V_78 ,
V_2 -> V_28 -> V_78 + V_2 -> V_28 -> V_9 ,
V_2 -> V_93 ) ;
V_306 ++ ;
continue;
}
}
F_13 ( V_306 ) ;
#endif
}
static int
F_121 ( struct V_1 * V_2 ,
unsigned V_308 ,
bool V_171 ,
bool V_309 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
struct V_298 * V_310 ;
T_4 V_9 , V_311 , V_312 , V_313 ;
bool V_314 , V_315 ;
int V_20 ;
if ( V_2 -> V_98 != V_190 ) {
F_8 ( L_9 ) ;
return - V_39 ;
}
V_311 = F_129 ( V_14 ,
V_2 -> V_50 . V_9 ,
V_2 -> V_3 ) ;
V_312 = F_130 ( V_14 ,
V_2 -> V_50 . V_9 ,
V_2 -> V_3 ) ;
V_313 =
F_131 ( V_14 ,
V_2 -> V_50 . V_9 ,
V_2 -> V_3 ) ;
if ( V_308 == 0 )
V_308 = V_171 ? V_312 :
V_313 ;
if ( V_171 && V_308 & ( V_312 - 1 ) ) {
F_8 ( L_10 , V_308 ) ;
return - V_39 ;
}
V_9 = V_171 ? V_311 : V_2 -> V_50 . V_9 ;
if ( V_2 -> V_50 . V_9 >
( V_171 ? V_8 -> V_10 . V_188 : V_8 -> V_10 . V_45 ) ) {
F_8 ( L_11 ) ;
return - V_189 ;
}
V_20 = F_57 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_316:
if ( V_171 )
V_310 =
F_233 ( & V_8 -> V_10 . V_28 ,
V_9 , V_308 , V_2 -> V_93 ,
0 , V_8 -> V_10 . V_188 ,
false ) ;
else
V_310 = F_234 ( & V_8 -> V_10 . V_28 ,
V_9 , V_308 , V_2 -> V_93 ,
false ) ;
if ( V_310 != NULL ) {
if ( V_171 )
V_2 -> V_28 =
F_235 ( V_310 ,
V_9 , V_308 , V_2 -> V_93 ,
0 , V_8 -> V_10 . V_188 ,
false ) ;
else
V_2 -> V_28 =
F_236 ( V_310 ,
V_9 , V_308 , V_2 -> V_93 ,
false ) ;
}
if ( V_2 -> V_28 == NULL ) {
V_20 = F_237 ( V_14 , V_9 , V_308 ,
V_2 -> V_93 ,
V_171 ,
V_309 ) ;
if ( V_20 )
return V_20 ;
goto V_316;
}
if ( F_13 ( ! F_228 ( V_14 ,
V_2 -> V_28 ,
V_2 -> V_93 ) ) ) {
F_208 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
return - V_39 ;
}
V_20 = F_238 ( V_2 ) ;
if ( V_20 ) {
F_208 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
return V_20 ;
}
if ( ! V_8 -> V_10 . V_272 )
F_122 ( V_2 , V_2 -> V_93 ) ;
F_124 ( & V_2 -> V_204 , & V_8 -> V_10 . V_317 ) ;
F_159 ( & V_2 -> V_173 , & V_8 -> V_10 . V_174 ) ;
V_2 -> V_113 = V_2 -> V_28 -> V_78 ;
V_315 =
V_2 -> V_28 -> V_9 == V_311 &&
( V_2 -> V_28 -> V_78 & ( V_312 - 1 ) ) == 0 ;
V_314 =
V_2 -> V_113 + V_2 -> V_50 . V_9 <= V_8 -> V_10 . V_188 ;
V_2 -> V_171 = V_314 && V_315 ;
F_239 ( V_2 , V_171 ) ;
F_231 ( V_14 ) ;
return 0 ;
}
void
F_84 ( struct V_1 * V_2 )
{
if ( V_2 -> V_199 == NULL )
return;
if ( V_2 -> V_93 != V_94 )
return;
F_240 ( V_2 ) ;
F_241 ( V_2 -> V_199 ) ;
}
static void
F_242 ( struct V_1 * V_2 )
{
T_3 V_269 ;
if ( V_2 -> V_50 . V_118 != V_153 )
return;
F_243 () ;
V_269 = V_2 -> V_50 . V_118 ;
V_2 -> V_50 . V_118 = 0 ;
F_202 ( V_2 ,
V_2 -> V_50 . V_91 ,
V_269 ) ;
}
static void
F_113 ( struct V_1 * V_2 )
{
T_3 V_269 ;
if ( V_2 -> V_50 . V_118 != V_92 )
return;
F_84 ( V_2 ) ;
F_85 () ;
V_269 = V_2 -> V_50 . V_118 ;
V_2 -> V_50 . V_118 = 0 ;
F_202 ( V_2 ,
V_2 -> V_50 . V_91 ,
V_269 ) ;
}
int
F_56 ( struct V_1 * V_2 , bool V_167 )
{
T_5 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
T_3 V_269 , V_270 ;
int V_20 ;
if ( V_2 -> V_28 == NULL )
return - V_39 ;
if ( V_2 -> V_50 . V_118 == V_153 )
return 0 ;
V_20 = F_107 ( V_2 , ! V_167 ) ;
if ( V_20 )
return V_20 ;
F_113 ( V_2 ) ;
V_269 = V_2 -> V_50 . V_118 ;
V_270 = V_2 -> V_50 . V_91 ;
F_92 ( ( V_2 -> V_50 . V_118 & ~ V_153 ) != 0 ) ;
V_2 -> V_50 . V_91 |= V_153 ;
if ( V_167 ) {
V_2 -> V_50 . V_91 = V_153 ;
V_2 -> V_50 . V_118 = V_153 ;
V_2 -> V_119 = 1 ;
}
F_202 ( V_2 ,
V_270 ,
V_269 ) ;
if ( F_15 ( V_2 ) )
F_124 ( & V_2 -> V_173 , & V_8 -> V_10 . V_174 ) ;
return 0 ;
}
int F_244 ( struct V_1 * V_2 ,
enum V_318 V_93 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
if ( V_2 -> V_93 == V_93 )
return 0 ;
if ( V_2 -> V_43 ) {
F_245 ( L_12 ) ;
return - V_179 ;
}
if ( ! F_228 ( V_14 , V_2 -> V_28 , V_93 ) ) {
V_20 = F_120 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_2 -> V_28 ) {
V_20 = F_203 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_200 ( V_2 ) ;
if ( F_18 ( V_14 ) -> V_40 < 6 ) {
V_20 = F_78 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_2 -> V_172 )
F_122 ( V_2 , V_93 ) ;
if ( V_2 -> V_271 )
F_246 ( V_8 -> V_10 . V_272 ,
V_2 , V_93 ) ;
V_2 -> V_28 -> V_304 = V_93 ;
}
if ( V_93 == V_94 ) {
T_4 V_270 , V_269 ;
F_13 ( V_2 -> V_50 . V_118 & ~ V_92 ) ;
F_13 ( V_2 -> V_50 . V_91 & ~ V_92 ) ;
V_270 = V_2 -> V_50 . V_91 ;
V_269 = V_2 -> V_50 . V_118 ;
V_2 -> V_50 . V_91 = V_92 ;
V_2 -> V_50 . V_118 = V_92 ;
F_202 ( V_2 ,
V_270 ,
V_269 ) ;
}
V_2 -> V_93 = V_93 ;
F_231 ( V_14 ) ;
return 0 ;
}
int F_247 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_319 * args = V_30 ;
struct V_1 * V_2 ;
int V_20 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_32 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_101 ;
goto V_102;
}
args -> V_320 = V_2 -> V_93 != V_94 ;
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int F_248 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_319 * args = V_30 ;
struct V_1 * V_2 ;
enum V_318 V_321 ;
int V_20 ;
switch ( args -> V_320 ) {
case V_322 :
V_321 = V_94 ;
break;
case V_323 :
V_321 = V_324 ;
break;
default:
return - V_39 ;
}
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_32 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_101 ;
goto V_102;
}
V_20 = F_244 ( V_2 , V_321 ) ;
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_249 ( struct V_1 * V_2 ,
T_4 V_308 ,
struct V_129 * V_325 )
{
T_4 V_270 , V_269 ;
int V_20 ;
if ( V_325 != V_2 -> V_130 ) {
V_20 = F_197 ( V_2 , V_325 ) ;
if ( V_20 )
return V_20 ;
}
V_20 = F_244 ( V_2 , V_94 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_77 ( V_2 , V_308 , true , false ) ;
if ( V_20 )
return V_20 ;
F_113 ( V_2 ) ;
V_269 = V_2 -> V_50 . V_118 ;
V_270 = V_2 -> V_50 . V_91 ;
V_2 -> V_50 . V_118 = 0 ;
V_2 -> V_50 . V_91 |= V_153 ;
F_202 ( V_2 ,
V_270 ,
V_269 ) ;
return 0 ;
}
int
F_203 ( struct V_1 * V_2 )
{
int V_20 ;
if ( ( V_2 -> V_50 . V_91 & V_150 ) == 0 )
return 0 ;
V_20 = F_107 ( V_2 , false ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_50 . V_91 &= ~ V_150 ;
return 0 ;
}
int
F_111 ( struct V_1 * V_2 , bool V_167 )
{
T_3 V_269 , V_270 ;
int V_20 ;
if ( V_2 -> V_50 . V_118 == V_92 )
return 0 ;
V_20 = F_107 ( V_2 , ! V_167 ) ;
if ( V_20 )
return V_20 ;
F_242 ( V_2 ) ;
V_269 = V_2 -> V_50 . V_118 ;
V_270 = V_2 -> V_50 . V_91 ;
if ( ( V_2 -> V_50 . V_91 & V_92 ) == 0 ) {
F_84 ( V_2 ) ;
V_2 -> V_50 . V_91 |= V_92 ;
}
F_92 ( ( V_2 -> V_50 . V_118 & ~ V_92 ) != 0 ) ;
if ( V_167 ) {
V_2 -> V_50 . V_91 = V_92 ;
V_2 -> V_50 . V_118 = V_92 ;
}
F_202 ( V_2 ,
V_270 ,
V_269 ) ;
return 0 ;
}
static int
F_250 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_244 * V_243 = V_32 -> V_245 ;
unsigned long V_326 = V_240 - F_174 ( 20 ) ;
struct V_233 * V_234 ;
struct V_129 * V_130 = NULL ;
T_4 V_131 = 0 ;
int V_20 ;
if ( F_6 ( & V_8 -> V_10 . V_21 ) )
return - V_23 ;
F_171 ( & V_243 -> V_10 . V_25 ) ;
F_23 (request, &file_priv->mm.request_list, client_list) {
if ( F_251 ( V_234 -> V_239 , V_326 ) )
break;
V_130 = V_234 -> V_130 ;
V_131 = V_234 -> V_131 ;
}
F_172 ( & V_243 -> V_10 . V_25 ) ;
if ( V_131 == 0 )
return 0 ;
V_20 = F_95 ( V_130 , V_131 , true , NULL ) ;
if ( V_20 == 0 )
F_175 ( V_8 -> V_251 , & V_8 -> V_10 . V_252 , 0 ) ;
return V_20 ;
}
int
F_77 ( struct V_1 * V_2 ,
T_3 V_308 ,
bool V_171 ,
bool V_309 )
{
int V_20 ;
if ( F_13 ( V_2 -> V_43 == V_327 ) )
return - V_179 ;
if ( V_2 -> V_28 != NULL ) {
if ( ( V_308 && V_2 -> V_113 & ( V_308 - 1 ) ) ||
( V_171 && ! V_2 -> V_171 ) ) {
F_217 ( V_2 -> V_43 ,
L_13
L_14
L_15 ,
V_2 -> V_113 , V_308 ,
V_171 ,
V_2 -> V_171 ) ;
V_20 = F_120 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
}
if ( V_2 -> V_28 == NULL ) {
V_20 = F_121 ( V_2 , V_308 ,
V_171 ,
V_309 ) ;
if ( V_20 )
return V_20 ;
}
if ( ! V_2 -> V_172 && V_171 )
F_122 ( V_2 , V_2 -> V_93 ) ;
V_2 -> V_43 ++ ;
V_2 -> V_328 |= V_171 ;
return 0 ;
}
void
F_79 ( struct V_1 * V_2 )
{
F_92 ( V_2 -> V_43 == 0 ) ;
F_92 ( V_2 -> V_28 == NULL ) ;
if ( -- V_2 -> V_43 == 0 )
V_2 -> V_328 = false ;
}
int
F_252 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_329 * args = V_30 ;
struct V_1 * V_2 ;
int V_20 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_32 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_101 ;
goto V_102;
}
if ( V_2 -> V_98 != V_190 ) {
F_8 ( L_16 ) ;
V_20 = - V_39 ;
goto V_97;
}
if ( V_2 -> V_330 != NULL && V_2 -> V_330 != V_32 ) {
F_8 ( L_17 ,
args -> V_48 ) ;
V_20 = - V_39 ;
goto V_97;
}
V_2 -> V_331 ++ ;
V_2 -> V_330 = V_32 ;
if ( V_2 -> V_331 == 1 ) {
V_20 = F_77 ( V_2 , args -> V_308 , true , false ) ;
if ( V_20 )
goto V_97;
}
F_113 ( V_2 ) ;
args -> V_82 = V_2 -> V_113 ;
V_97:
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_253 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_329 * args = V_30 ;
struct V_1 * V_2 ;
int V_20 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_32 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_101 ;
goto V_102;
}
if ( V_2 -> V_330 != V_32 ) {
F_8 ( L_18 ,
args -> V_48 ) ;
V_20 = - V_39 ;
goto V_97;
}
V_2 -> V_331 -- ;
if ( V_2 -> V_331 == 0 ) {
V_2 -> V_330 = NULL ;
F_79 ( V_2 ) ;
}
V_97:
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_254 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_332 * args = V_30 ;
struct V_1 * V_2 ;
int V_20 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_32 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_101 ;
goto V_102;
}
V_20 = F_192 ( V_2 ) ;
args -> V_333 = V_2 -> V_29 ;
if ( V_2 -> V_130 ) {
F_255 ( V_334 > 16 ) ;
args -> V_333 |= F_256 ( V_2 -> V_130 ) << 16 ;
}
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_257 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_243 )
{
return F_250 ( V_14 , V_243 ) ;
}
int
F_258 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_243 )
{
struct V_335 * args = V_30 ;
struct V_1 * V_2 ;
int V_20 ;
switch ( args -> V_98 ) {
case V_197 :
case V_190 :
break;
default:
return - V_39 ;
}
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_243 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_101 ;
goto V_102;
}
if ( V_2 -> V_43 ) {
V_20 = - V_39 ;
goto V_97;
}
if ( V_2 -> V_98 != V_99 )
V_2 -> V_98 = args -> V_98 ;
if ( F_142 ( V_2 ) && V_2 -> V_199 == NULL )
F_66 ( V_2 ) ;
args -> V_336 = V_2 -> V_98 != V_99 ;
V_97:
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
void F_259 ( struct V_1 * V_2 ,
const struct V_200 * V_201 )
{
F_182 ( & V_2 -> V_173 ) ;
F_182 ( & V_2 -> V_204 ) ;
F_182 ( & V_2 -> V_223 ) ;
F_182 ( & V_2 -> V_337 ) ;
V_2 -> V_201 = V_201 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_98 = V_190 ;
V_2 -> V_171 = true ;
F_3 ( V_2 -> V_50 . V_14 -> V_15 , V_2 -> V_50 . V_9 ) ;
}
struct V_1 * F_26 ( struct V_13 * V_14 ,
T_1 V_9 )
{
struct V_1 * V_2 ;
struct V_208 * V_105 ;
T_4 V_338 ;
V_2 = F_260 ( sizeof( * V_2 ) , V_212 ) ;
if ( V_2 == NULL )
return NULL ;
if ( F_261 ( V_14 , & V_2 -> V_50 , V_9 ) != 0 ) {
F_29 ( V_2 ) ;
return NULL ;
}
V_338 = V_339 | V_340 ;
if ( F_262 ( V_14 ) || F_263 ( V_14 ) ) {
V_338 &= ~ V_341 ;
V_338 |= V_342 ;
}
V_105 = V_2 -> V_50 . V_103 -> V_194 . V_195 -> V_196 -> V_213 ;
F_264 ( V_105 , V_338 ) ;
F_259 ( V_2 , & V_343 ) ;
V_2 -> V_50 . V_118 = V_92 ;
V_2 -> V_50 . V_91 = V_92 ;
if ( F_229 ( V_14 ) ) {
V_2 -> V_93 = V_324 ;
} else
V_2 -> V_93 = V_94 ;
return V_2 ;
}
int F_265 ( struct V_156 * V_2 )
{
F_266 () ;
return 0 ;
}
void F_267 ( struct V_156 * V_344 )
{
struct V_1 * V_2 = F_69 ( V_344 ) ;
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
F_268 ( V_2 ) ;
if ( V_2 -> V_124 )
F_269 ( V_14 , V_2 ) ;
V_2 -> V_43 = 0 ;
if ( F_13 ( F_120 ( V_2 ) == - V_145 ) ) {
bool V_345 ;
V_345 = V_8 -> V_10 . V_126 ;
V_8 -> V_10 . V_126 = false ;
F_13 ( F_120 ( V_2 ) ) ;
V_8 -> V_10 . V_126 = V_345 ;
}
V_2 -> V_202 = 0 ;
F_147 ( V_2 ) ;
F_137 ( V_2 ) ;
F_92 ( V_2 -> V_199 ) ;
if ( V_2 -> V_50 . V_346 )
F_270 ( & V_2 -> V_50 , NULL ) ;
F_28 ( & V_2 -> V_50 ) ;
F_4 ( V_8 , V_2 -> V_50 . V_9 ) ;
F_29 ( V_2 -> V_347 ) ;
F_29 ( V_2 ) ;
}
int
F_271 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
F_19 ( & V_14 -> V_27 ) ;
if ( V_8 -> V_10 . V_247 ) {
F_21 ( & V_14 -> V_27 ) ;
return 0 ;
}
V_20 = F_210 ( V_14 ) ;
if ( V_20 ) {
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
F_187 ( V_14 ) ;
if ( ! F_17 ( V_14 , V_34 ) )
F_150 ( V_14 ) ;
F_180 ( V_14 ) ;
V_8 -> V_10 . V_247 = 1 ;
F_272 ( & V_8 -> V_249 ) ;
F_273 ( V_14 ) ;
F_274 ( V_14 ) ;
F_21 ( & V_14 -> V_27 ) ;
F_275 ( & V_8 -> V_10 . V_252 ) ;
return 0 ;
}
void F_276 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_4 V_348 ;
int V_88 ;
if ( ! F_277 ( V_14 ) )
return;
if ( ! V_8 -> V_10 . V_349 )
return;
V_348 = F_278 ( V_350 ) ;
F_221 ( V_350 , V_348 & ~ V_351 ) ;
F_214 ( V_350 ) ;
for ( V_88 = 0 ; V_88 < V_352 ; V_88 += 4 ) {
T_4 V_353 = F_278 ( V_354 + V_88 ) ;
if ( V_353 && V_353 != V_8 -> V_10 . V_349 [ V_88 / 4 ] )
F_245 ( L_19 ,
V_354 + V_88 , V_353 ) ;
if ( V_353 && ! V_8 -> V_10 . V_349 [ V_88 / 4 ] )
F_279 ( L_20 ) ;
F_221 ( V_354 + V_88 , V_8 -> V_10 . V_349 [ V_88 / 4 ] ) ;
}
F_214 ( V_354 ) ;
F_221 ( V_350 , V_348 ) ;
}
void F_280 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
if ( F_18 ( V_14 ) -> V_40 < 5 ||
V_8 -> V_10 . V_57 == V_355 )
return;
F_221 ( V_356 , F_278 ( V_356 ) |
V_357 ) ;
if ( F_281 ( V_14 ) )
return;
F_221 ( V_358 , F_278 ( V_358 ) | V_359 ) ;
if ( F_282 ( V_14 ) )
F_221 ( V_360 , F_283 ( V_361 ) ) ;
else
F_221 ( V_360 , F_283 ( V_362 ) ) ;
}
void F_284 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_3 V_363 ;
struct V_129 * V_130 ;
struct V_364 * V_365 = V_8 -> V_10 . V_272 ;
T_3 T_9 * V_366 ;
T_3 V_367 ;
int V_88 ;
if ( ! V_8 -> V_10 . V_272 )
return;
V_366 = V_8 -> V_10 . V_368 -> V_368 + V_365 -> V_363 / sizeof( T_3 ) ;
for ( V_88 = 0 ; V_88 < V_365 -> V_369 ; V_88 ++ ) {
T_13 V_370 ;
if ( V_8 -> V_10 . V_368 -> V_371 )
V_370 = V_365 -> V_372 [ V_88 ] ;
else
V_370 = F_62 ( V_365 -> V_373 [ V_88 ] ) ;
V_367 = F_285 ( V_370 ) ;
V_367 |= V_374 ;
F_286 ( V_367 , V_366 + V_88 ) ;
}
F_287 ( V_366 ) ;
V_363 = V_365 -> V_363 ;
V_363 /= 64 ;
V_363 <<= 16 ;
if ( F_18 ( V_14 ) -> V_40 == 6 ) {
T_3 V_375 , V_376 , V_377 ;
V_377 = F_278 ( V_378 ) ;
F_221 ( V_378 , V_377 | V_379 ) ;
V_376 = F_278 ( V_380 ) ;
F_221 ( V_380 , V_376 | V_381 ) ;
V_375 = F_278 ( V_382 ) ;
F_221 ( V_382 , V_375 | V_383 |
V_384 ) ;
F_221 ( V_385 , F_283 ( V_386 ) ) ;
} else if ( F_18 ( V_14 ) -> V_40 >= 7 ) {
F_221 ( V_382 , V_384 ) ;
}
F_184 (ring, dev_priv, i) {
if ( F_18 ( V_14 ) -> V_40 >= 7 )
F_221 ( F_288 ( V_130 ) ,
F_283 ( V_386 ) ) ;
F_221 ( F_289 ( V_130 ) , V_387 ) ;
F_221 ( F_290 ( V_130 ) , V_363 ) ;
}
}
static bool
F_291 ( struct V_13 * V_14 )
{
if ( ! F_292 ( V_14 ) )
return false ;
if ( F_282 ( V_14 ) && V_14 -> V_388 -> V_389 < 8 ) {
F_293 ( L_21
L_22 ) ;
return false ;
}
return true ;
}
int
F_294 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
if ( ! F_295 () )
return - V_23 ;
if ( F_296 ( V_14 ) && ( F_278 ( 0x120010 ) == 1 ) )
F_221 ( 0x9008 , F_278 ( 0x9008 ) | 0xf0000 ) ;
F_276 ( V_14 ) ;
F_280 ( V_14 ) ;
V_20 = F_297 ( V_14 ) ;
if ( V_20 )
return V_20 ;
if ( F_298 ( V_14 ) ) {
V_20 = F_299 ( V_14 ) ;
if ( V_20 )
goto V_390;
}
if ( F_291 ( V_14 ) ) {
V_20 = F_300 ( V_14 ) ;
if ( V_20 )
goto V_391;
}
V_8 -> V_231 = 1 ;
F_301 ( V_14 ) ;
F_284 ( V_14 ) ;
return 0 ;
V_391:
F_302 ( & V_8 -> V_130 [ V_392 ] ) ;
V_390:
F_302 ( & V_8 -> V_130 [ V_393 ] ) ;
return V_20 ;
}
static bool
F_303 ( struct V_13 * V_14 )
{
if ( V_394 >= 0 )
return V_394 ;
#ifdef F_304
if ( F_18 ( V_14 ) -> V_40 == 6 && V_395 )
return false ;
#endif
return true ;
}
int F_305 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
unsigned long V_186 , V_396 ;
int V_20 ;
V_186 = V_8 -> V_10 . V_368 -> V_397 << V_95 ;
V_396 = V_8 -> V_10 . V_368 -> V_398 << V_95 ;
F_19 ( & V_14 -> V_27 ) ;
if ( F_303 ( V_14 ) && F_306 ( V_14 ) ) {
V_186 -= V_399 * V_38 ;
F_20 ( V_14 , 0 , V_396 , V_186 ) ;
V_20 = F_307 ( V_14 ) ;
if ( V_20 ) {
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
} else {
F_20 ( V_14 , 0 , V_396 ,
V_186 ) ;
}
V_20 = F_294 ( V_14 ) ;
F_21 ( & V_14 -> V_27 ) ;
if ( V_20 ) {
F_308 ( V_14 ) ;
return V_20 ;
}
if ( ! F_17 ( V_14 , V_34 ) )
V_8 -> V_400 . V_401 = 1 ;
return 0 ;
}
void
F_274 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_129 * V_130 ;
int V_88 ;
F_184 (ring, dev_priv, i)
F_302 ( V_130 ) ;
}
int
F_309 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_243 )
{
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
if ( F_17 ( V_14 , V_34 ) )
return 0 ;
if ( F_6 ( & V_8 -> V_10 . V_21 ) ) {
F_8 ( L_23 ) ;
F_310 ( & V_8 -> V_10 . V_21 , 0 ) ;
}
F_19 ( & V_14 -> V_27 ) ;
V_8 -> V_10 . V_247 = 0 ;
V_20 = F_294 ( V_14 ) ;
if ( V_20 != 0 ) {
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
F_92 ( ! F_170 ( & V_8 -> V_10 . V_222 ) ) ;
F_21 ( & V_14 -> V_27 ) ;
V_20 = F_311 ( V_14 ) ;
if ( V_20 )
goto V_402;
return 0 ;
V_402:
F_19 ( & V_14 -> V_27 ) ;
F_274 ( V_14 ) ;
V_8 -> V_10 . V_247 = 1 ;
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_312 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_243 )
{
if ( F_17 ( V_14 , V_34 ) )
return 0 ;
F_313 ( V_14 ) ;
return F_271 ( V_14 ) ;
}
void
F_314 ( struct V_13 * V_14 )
{
int V_20 ;
if ( F_17 ( V_14 , V_34 ) )
return;
V_20 = F_271 ( V_14 ) ;
if ( V_20 )
F_8 ( L_24 , V_20 ) ;
}
static void
F_315 ( struct V_129 * V_130 )
{
F_182 ( & V_130 -> V_222 ) ;
F_182 ( & V_130 -> V_241 ) ;
}
void
F_316 ( struct V_13 * V_14 )
{
int V_88 ;
T_5 * V_8 = V_14 -> V_15 ;
F_182 ( & V_8 -> V_10 . V_222 ) ;
F_182 ( & V_8 -> V_10 . V_174 ) ;
F_182 ( & V_8 -> V_10 . V_221 ) ;
F_182 ( & V_8 -> V_10 . V_317 ) ;
F_182 ( & V_8 -> V_10 . V_230 ) ;
for ( V_88 = 0 ; V_88 < V_334 ; V_88 ++ )
F_315 ( & V_8 -> V_130 [ V_88 ] ) ;
for ( V_88 = 0 ; V_88 < V_403 ; V_88 ++ )
F_182 ( & V_8 -> V_228 [ V_88 ] . V_229 ) ;
F_317 ( & V_8 -> V_10 . V_252 ,
F_188 ) ;
F_318 ( & V_8 -> V_18 ) ;
if ( F_319 ( V_14 ) ) {
F_221 ( V_404 ,
F_283 ( V_405 ) ) ;
}
V_8 -> V_406 = V_407 ;
if ( ! F_17 ( V_14 , V_34 ) )
V_8 -> V_295 = 3 ;
if ( F_18 ( V_14 ) -> V_40 >= 4 || F_320 ( V_14 ) || F_321 ( V_14 ) || F_132 ( V_14 ) )
V_8 -> V_253 = 16 ;
else
V_8 -> V_253 = 8 ;
F_180 ( V_14 ) ;
F_322 ( V_14 ) ;
F_323 ( & V_8 -> V_408 ) ;
V_8 -> V_10 . V_126 = true ;
V_8 -> V_10 . V_409 . V_410 = V_411 ;
V_8 -> V_10 . V_409 . V_412 = V_413 ;
F_324 ( & V_8 -> V_10 . V_409 ) ;
}
static int F_325 ( struct V_13 * V_14 ,
int V_414 , int V_9 , int V_415 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_416 * V_124 ;
int V_20 ;
if ( V_8 -> V_10 . V_417 [ V_414 - 1 ] || ! V_9 )
return 0 ;
V_124 = F_260 ( sizeof( struct V_416 ) , V_212 ) ;
if ( ! V_124 )
return - V_49 ;
V_124 -> V_414 = V_414 ;
V_124 -> V_48 = F_326 ( V_14 , V_9 , V_415 ) ;
if ( ! V_124 -> V_48 ) {
V_20 = - V_49 ;
goto V_418;
}
#ifdef F_327
F_328 ( ( unsigned long ) V_124 -> V_48 -> V_74 , V_124 -> V_48 -> V_9 / V_38 ) ;
#endif
V_8 -> V_10 . V_417 [ V_414 - 1 ] = V_124 ;
return 0 ;
V_418:
F_29 ( V_124 ) ;
return V_20 ;
}
static void F_329 ( struct V_13 * V_14 , int V_414 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_416 * V_124 ;
if ( ! V_8 -> V_10 . V_417 [ V_414 - 1 ] )
return;
V_124 = V_8 -> V_10 . V_417 [ V_414 - 1 ] ;
if ( V_124 -> V_419 ) {
F_269 ( V_14 , V_124 -> V_419 ) ;
}
#ifdef F_327
F_330 ( ( unsigned long ) V_124 -> V_48 -> V_74 , V_124 -> V_48 -> V_9 / V_38 ) ;
#endif
F_331 ( V_14 , V_124 -> V_48 ) ;
F_29 ( V_124 ) ;
V_8 -> V_10 . V_417 [ V_414 - 1 ] = NULL ;
}
void F_332 ( struct V_13 * V_14 )
{
int V_88 ;
for ( V_88 = V_420 ; V_88 <= V_421 ; V_88 ++ )
F_329 ( V_14 , V_88 ) ;
}
void F_269 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_208 * V_105 = V_2 -> V_50 . V_103 -> V_194 . V_195 -> V_196 -> V_213 ;
char * V_74 ;
int V_88 ;
int V_198 ;
if ( ! V_2 -> V_124 )
return;
V_74 = V_2 -> V_124 -> V_48 -> V_74 ;
V_198 = V_2 -> V_50 . V_9 / V_38 ;
for ( V_88 = 0 ; V_88 < V_198 ; V_88 ++ ) {
struct V_68 * V_68 = F_333 ( V_105 , V_88 ) ;
if ( ! F_117 ( V_68 ) ) {
char * V_422 = F_45 ( V_68 ) ;
memcpy ( V_422 , V_74 + V_88 * V_38 , V_38 ) ;
F_48 ( V_422 ) ;
F_334 ( & V_68 , 1 ) ;
F_83 ( V_68 ) ;
F_64 ( V_68 ) ;
F_145 ( V_68 ) ;
}
}
F_85 () ;
V_2 -> V_124 -> V_419 = NULL ;
V_2 -> V_124 = NULL ;
}
int
F_335 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_414 ,
int V_415 )
{
struct V_208 * V_105 = V_2 -> V_50 . V_103 -> V_194 . V_195 -> V_196 -> V_213 ;
T_5 * V_8 = V_14 -> V_15 ;
int V_20 = 0 ;
int V_198 ;
int V_88 ;
if ( V_414 > V_421 )
return - V_39 ;
if ( V_2 -> V_124 ) {
if ( V_2 -> V_124 -> V_414 == V_414 )
return 0 ;
F_269 ( V_14 , V_2 ) ;
}
if ( ! V_8 -> V_10 . V_417 [ V_414 - 1 ] ) {
V_20 = F_325 ( V_14 , V_414 ,
V_2 -> V_50 . V_9 , V_415 ) ;
if ( V_20 ) {
F_8 ( L_25 ,
V_414 , V_2 -> V_50 . V_9 ) ;
return V_20 ;
}
}
V_2 -> V_124 = V_8 -> V_10 . V_417 [ V_414 - 1 ] ;
V_2 -> V_124 -> V_419 = V_2 ;
V_198 = V_2 -> V_50 . V_9 / V_38 ;
for ( V_88 = 0 ; V_88 < V_198 ; V_88 ++ ) {
struct V_68 * V_68 ;
char * V_422 , * V_423 ;
V_68 = F_333 ( V_105 , V_88 ) ;
if ( F_117 ( V_68 ) )
return F_158 ( V_68 ) ;
V_423 = F_45 ( V_68 ) ;
V_422 = V_2 -> V_124 -> V_48 -> V_74 + ( V_88 * V_38 ) ;
memcpy ( V_422 , V_423 , V_38 ) ;
F_48 ( V_423 ) ;
F_64 ( V_68 ) ;
F_145 ( V_68 ) ;
}
return 0 ;
}
static int
F_89 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_111 * args ,
struct V_31 * V_243 )
{
void * V_74 = V_2 -> V_124 -> V_48 -> V_74 + args -> V_82 ;
char T_6 * V_71 = ( char T_6 * ) ( V_89 ) args -> V_90 ;
if ( F_74 ( V_74 , V_71 , args -> V_9 ) ) {
unsigned long V_109 ;
F_21 ( & V_14 -> V_27 ) ;
V_109 = F_336 ( V_74 , V_71 , args -> V_9 ) ;
F_19 ( & V_14 -> V_27 ) ;
if ( V_109 )
return - V_75 ;
}
F_85 () ;
return 0 ;
}
void F_337 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
struct V_244 * V_243 = V_32 -> V_245 ;
F_171 ( & V_243 -> V_10 . V_25 ) ;
while ( ! F_170 ( & V_243 -> V_10 . V_241 ) ) {
struct V_233 * V_234 ;
V_234 = F_179 ( & V_243 -> V_10 . V_241 ,
struct V_233 ,
V_246 ) ;
F_148 ( & V_234 -> V_246 ) ;
V_234 -> V_243 = NULL ;
}
F_172 ( & V_243 -> V_10 . V_25 ) ;
}
static int
V_411 ( struct V_424 * V_424 , struct V_425 * V_426 )
{
struct V_7 * V_8 =
F_189 ( V_424 ,
struct V_7 ,
V_10 . V_409 ) ;
struct V_13 * V_14 = V_8 -> V_14 ;
struct V_1 * V_2 ;
int V_427 = V_426 -> V_427 ;
int V_428 ;
if ( ! F_190 ( & V_14 -> V_27 ) )
return 0 ;
if ( V_427 ) {
V_427 -= F_135 ( V_8 , V_427 ) ;
if ( V_427 > 0 )
F_136 ( V_8 ) ;
}
V_428 = 0 ;
F_23 (obj, &dev_priv->mm.unbound_list, gtt_list)
if ( V_2 -> V_202 == 0 )
V_428 += V_2 -> V_50 . V_9 >> V_95 ;
F_23 (obj, &dev_priv->mm.bound_list, gtt_list)
if ( V_2 -> V_43 == 0 && V_2 -> V_202 == 0 )
V_428 += V_2 -> V_50 . V_9 >> V_95 ;
F_21 ( & V_14 -> V_27 ) ;
return V_428 ;
}

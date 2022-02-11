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
F_85 ( V_14 ) ;
}
}
if ( V_117 )
F_85 ( V_14 ) ;
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
V_20 = F_77 ( V_2 , 0 , true , false ) ;
if ( V_20 )
goto V_102;
V_20 = F_56 ( V_2 , V_167 ) ;
if ( V_20 )
goto V_171;
V_20 = F_120 ( V_2 ) ;
if ( V_20 )
goto V_171;
V_2 -> V_172 = true ;
V_166 = ( ( V_8 -> V_10 . V_173 + V_2 -> V_113 ) >> V_95 ) +
V_107 ;
V_20 = F_121 ( V_162 , ( unsigned long ) V_164 -> V_169 , V_166 ) ;
V_171:
F_79 ( V_2 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
V_97:
switch ( V_20 ) {
case - V_23 :
if ( ! F_6 ( & V_8 -> V_10 . V_21 ) )
return V_174 ;
case - V_128 :
F_122 () ;
case 0 :
case - V_145 :
case - V_175 :
case - V_176 :
return V_177 ;
case - V_49 :
return V_178 ;
case - V_125 :
return V_174 ;
default:
F_123 ( V_20 , L_2 , V_20 ) ;
return V_174 ;
}
}
void
F_2 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_172 )
return;
if ( V_2 -> V_50 . V_14 -> V_179 )
F_124 ( V_2 -> V_50 . V_14 -> V_179 ,
( T_8 ) V_2 -> V_50 . V_180 . V_181 . V_182 << V_95 ,
V_2 -> V_50 . V_9 , 1 ) ;
V_2 -> V_172 = false ;
}
static T_3
F_125 ( struct V_13 * V_14 , T_3 V_9 , int V_3 )
{
T_3 V_183 ;
if ( F_18 ( V_14 ) -> V_40 >= 4 ||
V_3 == V_59 )
return V_9 ;
if ( F_18 ( V_14 ) -> V_40 == 3 )
V_183 = 1024 * 1024 ;
else
V_183 = 512 * 1024 ;
while ( V_183 < V_9 )
V_183 <<= 1 ;
return V_183 ;
}
static T_3
F_126 ( struct V_13 * V_14 ,
T_3 V_9 ,
int V_3 )
{
if ( F_18 ( V_14 ) -> V_40 >= 4 ||
V_3 == V_59 )
return 4096 ;
return F_125 ( V_14 , V_9 , V_3 ) ;
}
T_3
F_127 ( struct V_13 * V_14 ,
T_3 V_9 ,
int V_3 )
{
if ( F_18 ( V_14 ) -> V_40 >= 4 || F_128 ( V_14 ) ||
V_3 == V_59 )
return 4096 ;
return F_125 ( V_14 , V_9 , V_3 ) ;
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
int V_20 ;
if ( V_2 -> V_50 . V_180 . V_184 )
return 0 ;
V_8 -> V_10 . V_185 = true ;
V_20 = F_130 ( & V_2 -> V_50 ) ;
if ( V_20 != - V_125 )
goto V_97;
F_131 ( V_8 , V_2 -> V_50 . V_9 >> V_95 ) ;
V_20 = F_130 ( & V_2 -> V_50 ) ;
if ( V_20 != - V_125 )
goto V_97;
F_132 ( V_8 ) ;
V_20 = F_130 ( & V_2 -> V_50 ) ;
V_97:
V_8 -> V_10 . V_185 = false ;
return V_20 ;
}
static void F_133 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_50 . V_180 . V_184 )
return;
F_134 ( & V_2 -> V_50 ) ;
}
int
F_135 ( struct V_31 * V_32 ,
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
if ( V_2 -> V_50 . V_9 > V_8 -> V_10 . V_186 ) {
V_20 = - V_187 ;
goto V_97;
}
if ( V_2 -> V_98 != V_188 ) {
F_8 ( L_3 ) ;
V_20 = - V_39 ;
goto V_97;
}
V_20 = F_129 ( V_2 ) ;
if ( V_20 )
goto V_97;
* V_82 = ( V_189 ) V_2 -> V_50 . V_180 . V_181 . V_182 << V_95 ;
V_97:
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_136 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_190 * args = V_30 ;
return F_135 ( V_32 , V_14 , args -> V_48 , & args -> V_82 ) ;
}
static void
F_66 ( struct V_1 * V_2 )
{
struct V_191 * V_191 ;
F_133 ( V_2 ) ;
if ( V_2 -> V_50 . V_103 == NULL )
return;
V_191 = V_2 -> V_50 . V_103 -> V_192 . V_193 -> V_194 ;
F_137 ( V_191 , 0 , ( T_8 ) - 1 ) ;
V_2 -> V_98 = V_99 ;
}
static inline int
F_138 ( struct V_1 * V_2 )
{
return V_2 -> V_98 == V_195 ;
}
static void
F_139 ( struct V_1 * V_2 )
{
int V_196 = V_2 -> V_50 . V_9 / V_38 ;
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
F_140 ( V_2 ) ;
if ( V_2 -> V_98 == V_195 )
V_2 -> V_119 = 0 ;
F_59 (obj->pages->sgl, sg, page_count, i) {
struct V_68 * V_68 = F_61 ( V_87 ) ;
if ( V_2 -> V_119 )
F_83 ( V_68 ) ;
if ( V_2 -> V_98 == V_188 )
F_64 ( V_68 ) ;
F_141 ( V_68 ) ;
}
V_2 -> V_119 = 0 ;
F_142 ( V_2 -> V_197 ) ;
F_29 ( V_2 -> V_197 ) ;
}
static int
F_143 ( struct V_1 * V_2 )
{
const struct V_198 * V_199 = V_2 -> V_199 ;
if ( V_2 -> V_197 == NULL )
return 0 ;
F_92 ( V_2 -> V_28 ) ;
if ( V_2 -> V_200 )
return - V_176 ;
F_144 ( & V_2 -> V_201 ) ;
V_199 -> V_202 ( V_2 ) ;
V_2 -> V_197 = NULL ;
if ( F_138 ( V_2 ) )
F_66 ( V_2 ) ;
return 0 ;
}
static long
F_145 ( struct V_7 * V_8 , long V_203 ,
bool V_204 )
{
struct V_1 * V_2 , * V_205 ;
long V_206 = 0 ;
F_146 (obj, next,
&dev_priv->mm.unbound_list,
gtt_list) {
if ( ( F_138 ( V_2 ) || ! V_204 ) &&
F_143 ( V_2 ) == 0 ) {
V_206 += V_2 -> V_50 . V_9 >> V_95 ;
if ( V_206 >= V_203 )
return V_206 ;
}
}
F_146 (obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if ( ( F_138 ( V_2 ) || ! V_204 ) &&
F_147 ( V_2 ) == 0 &&
F_143 ( V_2 ) == 0 ) {
V_206 += V_2 -> V_50 . V_9 >> V_95 ;
if ( V_206 >= V_203 )
return V_206 ;
}
}
return V_206 ;
}
static long
F_131 ( struct V_7 * V_8 , long V_203 )
{
return F_145 ( V_8 , V_203 , true ) ;
}
static void
F_132 ( struct V_7 * V_8 )
{
struct V_1 * V_2 , * V_205 ;
F_148 ( V_8 -> V_14 ) ;
F_146 (obj, next, &dev_priv->mm.unbound_list, gtt_list)
F_143 ( V_2 ) ;
}
static int
F_149 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
int V_196 , V_88 ;
struct V_207 * V_105 ;
struct V_208 * V_209 ;
struct V_86 * V_87 ;
struct V_68 * V_68 ;
T_12 V_210 ;
F_92 ( V_2 -> V_50 . V_91 & V_150 ) ;
F_92 ( V_2 -> V_50 . V_118 & V_150 ) ;
V_209 = F_150 ( sizeof( * V_209 ) , V_211 ) ;
if ( V_209 == NULL )
return - V_49 ;
V_196 = V_2 -> V_50 . V_9 / V_38 ;
if ( F_151 ( V_209 , V_196 , V_211 ) ) {
F_142 ( V_209 ) ;
F_29 ( V_209 ) ;
return - V_49 ;
}
V_105 = V_2 -> V_50 . V_103 -> V_192 . V_193 -> V_194 -> V_212 ;
V_210 = F_152 ( V_105 ) ;
V_210 |= V_213 | V_214 | V_215 ;
V_210 &= ~ ( V_216 | V_217 ) ;
F_59 (st->sgl, sg, page_count, i) {
V_68 = F_153 ( V_105 , V_88 , V_210 ) ;
if ( F_117 ( V_68 ) ) {
F_131 ( V_8 , V_196 ) ;
V_68 = F_153 ( V_105 , V_88 , V_210 ) ;
}
if ( F_117 ( V_68 ) ) {
V_210 &= ~ ( V_213 | V_214 | V_215 ) ;
V_210 |= V_216 | V_217 ;
F_132 ( V_8 ) ;
V_68 = F_153 ( V_105 , V_88 , V_210 ) ;
if ( F_117 ( V_68 ) )
goto V_218;
V_210 |= V_213 | V_214 | V_215 ;
V_210 &= ~ ( V_216 | V_217 ) ;
}
F_154 ( V_87 , V_68 , V_38 , 0 ) ;
}
V_2 -> V_197 = V_209 ;
if ( F_37 ( V_2 ) )
F_155 ( V_2 ) ;
return 0 ;
V_218:
F_59 (st->sgl, sg, i, page_count)
F_141 ( F_61 ( V_87 ) ) ;
F_142 ( V_209 ) ;
F_29 ( V_209 ) ;
return F_156 ( V_68 ) ;
}
int
F_57 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
const struct V_198 * V_199 = V_2 -> V_199 ;
int V_20 ;
if ( V_2 -> V_197 )
return 0 ;
F_92 ( V_2 -> V_200 ) ;
V_20 = V_199 -> V_219 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_157 ( & V_2 -> V_201 , & V_8 -> V_10 . V_220 ) ;
return 0 ;
}
void
F_158 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
struct V_7 * V_8 = V_14 -> V_15 ;
T_4 V_131 = F_159 ( V_130 ) ;
F_92 ( V_130 == NULL ) ;
V_2 -> V_130 = V_130 ;
if ( ! V_2 -> V_29 ) {
F_160 ( & V_2 -> V_50 ) ;
V_2 -> V_29 = 1 ;
}
F_161 ( & V_2 -> V_221 , & V_8 -> V_10 . V_222 ) ;
F_161 ( & V_2 -> V_223 , & V_130 -> V_222 ) ;
V_2 -> V_149 = V_131 ;
if ( V_2 -> V_224 ) {
V_2 -> V_225 = V_131 ;
if ( V_2 -> V_5 != V_6 ) {
struct V_226 * V_227 ;
V_227 = & V_8 -> V_228 [ V_2 -> V_5 ] ;
F_161 ( & V_227 -> V_229 ,
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
F_161 ( & V_2 -> V_221 , & V_8 -> V_10 . V_231 ) ;
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
static int
F_165 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_129 * V_130 ;
int V_20 , V_88 , V_232 ;
V_20 = 0 ;
F_166 (ring, dev_priv, i) {
for ( V_232 = 0 ; V_232 < F_167 ( V_130 -> V_233 ) ; V_232 ++ )
V_20 |= V_130 -> V_233 [ V_232 ] != 0 ;
}
if ( V_20 == 0 )
return V_20 ;
V_20 = F_168 ( V_14 ) ;
if ( V_20 )
return V_20 ;
F_169 ( V_14 ) ;
F_166 (ring, dev_priv, i) {
for ( V_232 = 0 ; V_232 < F_167 ( V_130 -> V_233 ) ; V_232 ++ )
V_130 -> V_233 [ V_232 ] = 0 ;
}
return 0 ;
}
int
F_170 ( struct V_13 * V_14 , T_4 * V_131 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
if ( V_8 -> V_234 == 0 ) {
int V_20 = F_165 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_8 -> V_234 = 1 ;
}
* V_131 = V_8 -> V_234 ++ ;
return 0 ;
}
int
F_94 ( struct V_129 * V_130 ,
struct V_31 * V_32 ,
T_4 * V_235 )
{
T_5 * V_8 = V_130 -> V_14 -> V_15 ;
struct V_236 * V_237 ;
T_4 V_238 ;
int V_239 ;
int V_20 ;
V_20 = F_171 ( V_130 ) ;
if ( V_20 )
return V_20 ;
V_237 = F_150 ( sizeof( * V_237 ) , V_211 ) ;
if ( V_237 == NULL )
return - V_49 ;
V_238 = F_172 ( V_130 ) ;
V_20 = V_130 -> V_240 ( V_130 ) ;
if ( V_20 ) {
F_29 ( V_237 ) ;
return V_20 ;
}
V_237 -> V_131 = F_159 ( V_130 ) ;
V_237 -> V_130 = V_130 ;
V_237 -> V_241 = V_238 ;
V_237 -> V_242 = V_243 ;
V_239 = F_173 ( & V_130 -> V_244 ) ;
F_157 ( & V_237 -> V_245 , & V_130 -> V_244 ) ;
V_237 -> V_246 = NULL ;
if ( V_32 ) {
struct V_247 * V_246 = V_32 -> V_248 ;
F_174 ( & V_246 -> V_10 . V_25 ) ;
V_237 -> V_246 = V_246 ;
F_157 ( & V_237 -> V_249 ,
& V_246 -> V_10 . V_244 ) ;
F_175 ( & V_246 -> V_10 . V_25 ) ;
}
F_176 ( V_130 , V_237 -> V_131 ) ;
V_130 -> V_132 = 0 ;
if ( ! V_8 -> V_10 . V_250 ) {
if ( V_251 ) {
F_177 ( & V_8 -> V_252 ,
F_178 ( V_243 + V_253 ) ) ;
}
if ( V_239 ) {
F_179 ( V_8 -> V_254 ,
& V_8 -> V_10 . V_255 ,
F_180 ( V_22 ) ) ;
F_181 ( V_8 -> V_14 ) ;
}
}
if ( V_235 )
* V_235 = V_237 -> V_131 ;
return 0 ;
}
static inline void
F_182 ( struct V_236 * V_237 )
{
struct V_247 * V_246 = V_237 -> V_246 ;
if ( ! V_246 )
return;
F_174 ( & V_246 -> V_10 . V_25 ) ;
if ( V_237 -> V_246 ) {
F_144 ( & V_237 -> V_249 ) ;
V_237 -> V_246 = NULL ;
}
F_175 ( & V_246 -> V_10 . V_25 ) ;
}
static void F_183 ( struct V_7 * V_8 ,
struct V_129 * V_130 )
{
while ( ! F_173 ( & V_130 -> V_244 ) ) {
struct V_236 * V_237 ;
V_237 = F_184 ( & V_130 -> V_244 ,
struct V_236 ,
V_245 ) ;
F_144 ( & V_237 -> V_245 ) ;
F_182 ( V_237 ) ;
F_29 ( V_237 ) ;
}
while ( ! F_173 ( & V_130 -> V_222 ) ) {
struct V_1 * V_2 ;
V_2 = F_184 ( & V_130 -> V_222 ,
struct V_1 ,
V_223 ) ;
F_162 ( V_2 ) ;
}
}
static void F_185 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_8 -> V_256 ; V_88 ++ ) {
struct V_226 * V_227 = & V_8 -> V_228 [ V_88 ] ;
F_186 ( V_14 , V_88 , NULL ) ;
if ( V_227 -> V_2 )
F_1 ( V_227 -> V_2 ) ;
V_227 -> V_43 = 0 ;
V_227 -> V_2 = NULL ;
F_187 ( & V_227 -> V_229 ) ;
}
F_187 ( & V_8 -> V_10 . V_230 ) ;
}
void F_188 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_1 * V_2 ;
struct V_129 * V_130 ;
int V_88 ;
F_166 (ring, dev_priv, i)
F_183 ( V_8 , V_130 ) ;
F_23 (obj,
&dev_priv->mm.inactive_list,
mm_list)
{
V_2 -> V_50 . V_91 &= ~ V_150 ;
}
F_185 ( V_14 ) ;
}
void
F_108 ( struct V_129 * V_130 )
{
T_3 V_131 ;
if ( F_173 ( & V_130 -> V_244 ) )
return;
F_13 ( F_14 ( V_130 -> V_14 ) ) ;
V_131 = V_130 -> V_140 ( V_130 , true ) ;
while ( ! F_173 ( & V_130 -> V_244 ) ) {
struct V_236 * V_237 ;
V_237 = F_184 ( & V_130 -> V_244 ,
struct V_236 ,
V_245 ) ;
if ( ! F_96 ( V_131 , V_237 -> V_131 ) )
break;
F_189 ( V_130 , V_237 -> V_131 ) ;
V_130 -> V_257 = V_237 -> V_241 ;
F_144 ( & V_237 -> V_245 ) ;
F_182 ( V_237 ) ;
F_29 ( V_237 ) ;
}
while ( ! F_173 ( & V_130 -> V_222 ) ) {
struct V_1 * V_2 ;
V_2 = F_184 ( & V_130 -> V_222 ,
struct V_1 ,
V_223 ) ;
if ( ! F_96 ( V_131 , V_2 -> V_149 ) )
break;
F_162 ( V_2 ) ;
}
if ( F_44 ( V_130 -> V_258 &&
F_96 ( V_131 , V_130 -> V_258 ) ) ) {
V_130 -> V_143 ( V_130 ) ;
V_130 -> V_258 = 0 ;
}
F_13 ( F_14 ( V_130 -> V_14 ) ) ;
}
void
F_169 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_129 * V_130 ;
int V_88 ;
F_166 (ring, dev_priv, i)
F_108 ( V_130 ) ;
}
static void
F_190 ( struct V_259 * V_260 )
{
T_5 * V_8 ;
struct V_13 * V_14 ;
struct V_129 * V_130 ;
bool V_261 ;
int V_88 ;
V_8 = F_191 ( V_260 , T_5 ,
V_10 . V_255 . V_260 ) ;
V_14 = V_8 -> V_14 ;
if ( ! F_192 ( & V_14 -> V_27 ) ) {
F_179 ( V_8 -> V_254 , & V_8 -> V_10 . V_255 ,
F_180 ( V_22 ) ) ;
return;
}
F_169 ( V_14 ) ;
V_261 = true ;
F_166 (ring, dev_priv, i) {
if ( V_130 -> V_262 )
F_94 ( V_130 , NULL , NULL ) ;
V_261 &= F_173 ( & V_130 -> V_244 ) ;
}
if ( ! V_8 -> V_10 . V_250 && ! V_261 )
F_179 ( V_8 -> V_254 , & V_8 -> V_10 . V_255 ,
F_180 ( V_22 ) ) ;
if ( V_261 )
F_193 ( V_14 ) ;
F_21 ( & V_14 -> V_27 ) ;
}
static int
F_194 ( struct V_1 * V_2 )
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
F_195 ( struct V_13 * V_14 , void * V_30 , struct V_31 * V_32 )
{
struct V_263 * args = V_30 ;
struct V_1 * V_2 ;
struct V_129 * V_130 = NULL ;
struct V_133 V_264 , * V_134 = NULL ;
T_4 V_131 = 0 ;
int V_20 = 0 ;
if ( args -> V_265 >= 0 ) {
V_264 = F_196 ( args -> V_265 ) ;
V_134 = & V_264 ;
}
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_32 , args -> V_266 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
F_21 ( & V_14 -> V_27 ) ;
return - V_101 ;
}
V_20 = F_194 ( V_2 ) ;
if ( V_20 )
goto V_97;
if ( V_2 -> V_29 ) {
V_131 = V_2 -> V_149 ;
V_130 = V_2 -> V_130 ;
}
if ( V_131 == 0 )
goto V_97;
if ( ! args -> V_265 ) {
V_20 = - V_146 ;
goto V_97;
}
F_30 ( & V_2 -> V_50 ) ;
F_21 ( & V_14 -> V_27 ) ;
V_20 = F_95 ( V_130 , V_131 , true , V_134 ) ;
if ( V_134 ) {
F_13 ( ! F_197 ( V_134 ) ) ;
args -> V_265 = F_198 ( V_134 ) ;
}
return V_20 ;
V_97:
F_30 ( & V_2 -> V_50 ) ;
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_199 ( struct V_1 * V_2 ,
struct V_129 * V_267 )
{
struct V_129 * V_268 = V_2 -> V_130 ;
T_4 V_131 ;
int V_20 , V_269 ;
if ( V_268 == NULL || V_267 == V_268 )
return 0 ;
if ( V_267 == NULL || ! F_200 ( V_2 -> V_50 . V_14 ) )
return F_107 ( V_2 , false ) ;
V_269 = F_201 ( V_268 , V_267 ) ;
V_131 = V_2 -> V_149 ;
if ( V_131 <= V_268 -> V_233 [ V_269 ] )
return 0 ;
V_20 = F_91 ( V_2 -> V_130 , V_131 ) ;
if ( V_20 )
return V_20 ;
V_20 = V_267 -> V_270 ( V_267 , V_268 , V_131 ) ;
if ( ! V_20 )
V_268 -> V_233 [ V_269 ] = V_2 -> V_149 ;
return V_20 ;
}
static void F_202 ( struct V_1 * V_2 )
{
T_4 V_271 , V_272 ;
F_203 () ;
F_2 ( V_2 ) ;
if ( ( V_2 -> V_50 . V_91 & V_153 ) == 0 )
return;
V_272 = V_2 -> V_50 . V_91 ;
V_271 = V_2 -> V_50 . V_118 ;
V_2 -> V_50 . V_91 &= ~ V_153 ;
V_2 -> V_50 . V_118 &= ~ V_153 ;
F_204 ( V_2 ,
V_272 ,
V_271 ) ;
}
int
F_147 ( struct V_1 * V_2 )
{
T_5 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
int V_20 = 0 ;
if ( V_2 -> V_28 == NULL )
return 0 ;
if ( V_2 -> V_43 )
return - V_176 ;
F_92 ( V_2 -> V_197 == NULL ) ;
V_20 = F_205 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_202 ( V_2 ) ;
V_20 = F_78 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_206 ( V_2 ) ;
if ( V_2 -> V_273 )
F_207 ( V_2 ) ;
if ( V_2 -> V_274 ) {
F_208 ( V_8 -> V_10 . V_275 , V_2 ) ;
V_2 -> V_274 = 0 ;
}
F_209 ( V_2 ) ;
F_144 ( & V_2 -> V_221 ) ;
F_161 ( & V_2 -> V_201 , & V_8 -> V_10 . V_220 ) ;
V_2 -> V_276 = true ;
F_210 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
V_2 -> V_113 = 0 ;
return 0 ;
}
int F_168 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_129 * V_130 ;
int V_20 , V_88 ;
F_166 (ring, dev_priv, i) {
V_20 = F_211 ( V_130 , NULL , V_277 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_212 ( V_130 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static void F_213 ( struct V_13 * V_14 , int V_227 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_2 V_278 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_28 -> V_9 ;
V_278 = ( T_2 ) ( ( V_2 -> V_113 + V_9 - 4096 ) &
0xfffff000 ) << 32 ;
V_278 |= V_2 -> V_113 & 0xfffff000 ;
V_278 |= ( T_2 ) ( ( V_2 -> V_279 / 128 ) - 1 ) <<
V_280 ;
if ( V_2 -> V_3 == V_281 )
V_278 |= 1 << V_282 ;
V_278 |= V_283 ;
} else
V_278 = 0 ;
F_214 ( V_284 + V_227 * 8 , V_278 ) ;
F_215 ( V_284 + V_227 * 8 ) ;
}
static void F_216 ( struct V_13 * V_14 , int V_227 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_2 V_278 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_28 -> V_9 ;
V_278 = ( T_2 ) ( ( V_2 -> V_113 + V_9 - 4096 ) &
0xfffff000 ) << 32 ;
V_278 |= V_2 -> V_113 & 0xfffff000 ;
V_278 |= ( ( V_2 -> V_279 / 128 ) - 1 ) << V_285 ;
if ( V_2 -> V_3 == V_281 )
V_278 |= 1 << V_282 ;
V_278 |= V_283 ;
} else
V_278 = 0 ;
F_214 ( V_286 + V_227 * 8 , V_278 ) ;
F_215 ( V_286 + V_227 * 8 ) ;
}
static void F_217 ( struct V_13 * V_14 , int V_227 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_4 V_278 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_28 -> V_9 ;
int V_287 ;
int V_288 ;
F_218 ( ( V_2 -> V_113 & ~ V_289 ) ||
( V_9 & - V_9 ) != V_9 ||
( V_2 -> V_113 & ( V_9 - 1 ) ) ,
L_4 ,
V_2 -> V_113 , V_2 -> V_276 , V_9 ) ;
if ( V_2 -> V_3 == V_281 && F_219 ( V_14 ) )
V_288 = 128 ;
else
V_288 = 512 ;
V_287 = V_2 -> V_279 / V_288 ;
V_287 = F_220 ( V_287 ) - 1 ;
V_278 = V_2 -> V_113 ;
if ( V_2 -> V_3 == V_281 )
V_278 |= 1 << V_290 ;
V_278 |= F_221 ( V_9 ) ;
V_278 |= V_287 << V_291 ;
V_278 |= V_292 ;
} else
V_278 = 0 ;
if ( V_227 < 8 )
V_227 = V_293 + V_227 * 4 ;
else
V_227 = V_294 + ( V_227 - 8 ) * 4 ;
F_222 ( V_227 , V_278 ) ;
F_215 ( V_227 ) ;
}
static void F_223 ( struct V_13 * V_14 , int V_227 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_3 V_278 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_28 -> V_9 ;
T_3 V_287 ;
F_218 ( ( V_2 -> V_113 & ~ V_295 ) ||
( V_9 & - V_9 ) != V_9 ||
( V_2 -> V_113 & ( V_9 - 1 ) ) ,
L_5 ,
V_2 -> V_113 , V_9 ) ;
V_287 = V_2 -> V_279 / 128 ;
V_287 = F_220 ( V_287 ) - 1 ;
V_278 = V_2 -> V_113 ;
if ( V_2 -> V_3 == V_281 )
V_278 |= 1 << V_290 ;
V_278 |= F_224 ( V_9 ) ;
V_278 |= V_287 << V_291 ;
V_278 |= V_292 ;
} else
V_278 = 0 ;
F_222 ( V_293 + V_227 * 4 , V_278 ) ;
F_215 ( V_293 + V_227 * 4 ) ;
}
static void F_186 ( struct V_13 * V_14 , int V_227 ,
struct V_1 * V_2 )
{
switch ( F_18 ( V_14 ) -> V_40 ) {
case 7 :
case 6 : F_213 ( V_14 , V_227 , V_2 ) ; break;
case 5 :
case 4 : F_216 ( V_14 , V_227 , V_2 ) ; break;
case 3 : F_217 ( V_14 , V_227 , V_2 ) ; break;
case 2 : F_223 ( V_14 , V_227 , V_2 ) ; break;
default: break;
}
}
static inline int F_225 ( struct V_7 * V_8 ,
struct V_226 * V_296 )
{
return V_296 - V_8 -> V_228 ;
}
static void F_226 ( struct V_1 * V_2 ,
struct V_226 * V_296 ,
bool V_297 )
{
struct V_7 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
int V_227 = F_225 ( V_8 , V_296 ) ;
F_186 ( V_2 -> V_50 . V_14 , V_227 , V_297 ? V_2 : NULL ) ;
if ( V_297 ) {
V_2 -> V_5 = V_227 ;
V_296 -> V_2 = V_2 ;
F_161 ( & V_296 -> V_229 , & V_8 -> V_10 . V_230 ) ;
} else {
V_2 -> V_5 = V_6 ;
V_296 -> V_2 = NULL ;
F_164 ( & V_296 -> V_229 ) ;
}
}
static int
F_227 ( struct V_1 * V_2 )
{
if ( V_2 -> V_225 ) {
int V_20 = F_106 ( V_2 -> V_130 , V_2 -> V_225 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_225 = 0 ;
}
if ( V_2 -> V_50 . V_91 & V_153 )
F_203 () ;
V_2 -> V_224 = false ;
return 0 ;
}
int
F_78 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
int V_20 ;
V_20 = F_227 ( V_2 ) ;
if ( V_20 )
return V_20 ;
if ( V_2 -> V_5 == V_6 )
return 0 ;
F_226 ( V_2 ,
& V_8 -> V_228 [ V_2 -> V_5 ] ,
false ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static struct V_226 *
F_228 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_226 * V_227 , * V_298 ;
int V_88 ;
V_298 = NULL ;
for ( V_88 = V_8 -> V_299 ; V_88 < V_8 -> V_256 ; V_88 ++ ) {
V_227 = & V_8 -> V_228 [ V_88 ] ;
if ( ! V_227 -> V_2 )
return V_227 ;
if ( ! V_227 -> V_43 )
V_298 = V_227 ;
}
if ( V_298 == NULL )
return NULL ;
F_23 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_227 -> V_43 )
continue;
return V_227 ;
}
return NULL ;
}
int
F_120 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
struct V_7 * V_8 = V_14 -> V_15 ;
bool V_297 = V_2 -> V_3 != V_59 ;
struct V_226 * V_227 ;
int V_20 ;
if ( V_2 -> V_4 ) {
V_20 = F_227 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_2 -> V_5 != V_6 ) {
V_227 = & V_8 -> V_228 [ V_2 -> V_5 ] ;
if ( ! V_2 -> V_4 ) {
F_161 ( & V_227 -> V_229 ,
& V_8 -> V_10 . V_230 ) ;
return 0 ;
}
} else if ( V_297 ) {
V_227 = F_228 ( V_14 ) ;
if ( V_227 == NULL )
return - V_300 ;
if ( V_227 -> V_2 ) {
struct V_1 * V_301 = V_227 -> V_2 ;
V_20 = F_227 ( V_301 ) ;
if ( V_20 )
return V_20 ;
F_1 ( V_301 ) ;
}
} else
return 0 ;
F_226 ( V_2 , V_227 , V_297 ) ;
V_2 -> V_4 = false ;
return 0 ;
}
static bool F_229 ( struct V_13 * V_14 ,
struct V_302 * V_28 ,
unsigned long V_93 )
{
struct V_302 * V_303 ;
if ( F_230 ( V_14 ) )
return true ;
if ( V_28 == NULL )
return true ;
if ( F_173 ( & V_28 -> V_304 ) )
return true ;
V_303 = F_231 ( V_28 -> V_304 . V_305 , struct V_302 , V_304 ) ;
if ( V_303 -> V_306 && ! V_303 -> V_307 && V_303 -> V_308 != V_93 )
return false ;
V_303 = F_231 ( V_28 -> V_304 . V_205 , struct V_302 , V_304 ) ;
if ( V_303 -> V_306 && ! V_28 -> V_307 && V_303 -> V_308 != V_93 )
return false ;
return true ;
}
static void F_232 ( struct V_13 * V_14 )
{
#if V_309
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_1 * V_2 ;
int V_310 = 0 ;
F_23 (obj, &dev_priv->mm.gtt_list, gtt_list) {
if ( V_2 -> V_28 == NULL ) {
F_233 ( V_311 L_6 ) ;
V_310 ++ ;
continue;
}
if ( V_2 -> V_93 != V_2 -> V_28 -> V_308 ) {
F_233 ( V_311 L_7 ,
V_2 -> V_28 -> V_78 ,
V_2 -> V_28 -> V_78 + V_2 -> V_28 -> V_9 ,
V_2 -> V_93 ,
V_2 -> V_28 -> V_308 ) ;
V_310 ++ ;
continue;
}
if ( ! F_229 ( V_14 ,
V_2 -> V_28 ,
V_2 -> V_93 ) ) {
F_233 ( V_311 L_8 ,
V_2 -> V_28 -> V_78 ,
V_2 -> V_28 -> V_78 + V_2 -> V_28 -> V_9 ,
V_2 -> V_93 ) ;
V_310 ++ ;
continue;
}
}
F_13 ( V_310 ) ;
#endif
}
static int
F_234 ( struct V_1 * V_2 ,
unsigned V_312 ,
bool V_276 ,
bool V_313 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
struct V_302 * V_314 ;
T_4 V_9 , V_315 , V_316 , V_317 ;
bool V_318 , V_319 ;
int V_20 ;
if ( V_2 -> V_98 != V_188 ) {
F_8 ( L_9 ) ;
return - V_39 ;
}
V_315 = F_125 ( V_14 ,
V_2 -> V_50 . V_9 ,
V_2 -> V_3 ) ;
V_316 = F_126 ( V_14 ,
V_2 -> V_50 . V_9 ,
V_2 -> V_3 ) ;
V_317 =
F_127 ( V_14 ,
V_2 -> V_50 . V_9 ,
V_2 -> V_3 ) ;
if ( V_312 == 0 )
V_312 = V_276 ? V_316 :
V_317 ;
if ( V_276 && V_312 & ( V_316 - 1 ) ) {
F_8 ( L_10 , V_312 ) ;
return - V_39 ;
}
V_9 = V_276 ? V_315 : V_2 -> V_50 . V_9 ;
if ( V_2 -> V_50 . V_9 >
( V_276 ? V_8 -> V_10 . V_186 : V_8 -> V_10 . V_45 ) ) {
F_8 ( L_11 ) ;
return - V_187 ;
}
V_20 = F_57 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_58 ( V_2 ) ;
V_314 = F_235 ( sizeof( * V_314 ) , V_211 ) ;
if ( V_314 == NULL ) {
F_65 ( V_2 ) ;
return - V_49 ;
}
V_320:
if ( V_276 )
V_20 = F_236 ( & V_8 -> V_10 . V_28 , V_314 ,
V_9 , V_312 , V_2 -> V_93 ,
0 , V_8 -> V_10 . V_186 ) ;
else
V_20 = F_237 ( & V_8 -> V_10 . V_28 , V_314 ,
V_9 , V_312 , V_2 -> V_93 ) ;
if ( V_20 ) {
V_20 = F_238 ( V_14 , V_9 , V_312 ,
V_2 -> V_93 ,
V_276 ,
V_313 ) ;
if ( V_20 == 0 )
goto V_320;
F_65 ( V_2 ) ;
F_29 ( V_314 ) ;
return V_20 ;
}
if ( F_13 ( ! F_229 ( V_14 , V_314 , V_2 -> V_93 ) ) ) {
F_65 ( V_2 ) ;
F_210 ( V_314 ) ;
return - V_39 ;
}
V_20 = F_239 ( V_2 ) ;
if ( V_20 ) {
F_65 ( V_2 ) ;
F_210 ( V_314 ) ;
return V_20 ;
}
F_161 ( & V_2 -> V_201 , & V_8 -> V_10 . V_321 ) ;
F_157 ( & V_2 -> V_221 , & V_8 -> V_10 . V_231 ) ;
V_2 -> V_28 = V_314 ;
V_2 -> V_113 = V_314 -> V_78 ;
V_319 =
V_314 -> V_9 == V_315 &&
( V_314 -> V_78 & ( V_316 - 1 ) ) == 0 ;
V_318 =
V_2 -> V_113 + V_2 -> V_50 . V_9 <= V_8 -> V_10 . V_186 ;
V_2 -> V_276 = V_318 && V_319 ;
F_65 ( V_2 ) ;
F_240 ( V_2 , V_276 ) ;
F_232 ( V_14 ) ;
return 0 ;
}
void
F_84 ( struct V_1 * V_2 )
{
if ( V_2 -> V_197 == NULL )
return;
if ( V_2 -> V_93 != V_94 )
return;
F_241 ( V_2 ) ;
F_242 ( V_2 -> V_197 ) ;
}
static void
F_243 ( struct V_1 * V_2 )
{
T_3 V_271 ;
if ( V_2 -> V_50 . V_118 != V_153 )
return;
F_244 () ;
V_271 = V_2 -> V_50 . V_118 ;
V_2 -> V_50 . V_118 = 0 ;
F_204 ( V_2 ,
V_2 -> V_50 . V_91 ,
V_271 ) ;
}
static void
F_113 ( struct V_1 * V_2 )
{
T_3 V_271 ;
if ( V_2 -> V_50 . V_118 != V_92 )
return;
F_84 ( V_2 ) ;
F_85 ( V_2 -> V_50 . V_14 ) ;
V_271 = V_2 -> V_50 . V_118 ;
V_2 -> V_50 . V_118 = 0 ;
F_204 ( V_2 ,
V_2 -> V_50 . V_91 ,
V_271 ) ;
}
int
F_56 ( struct V_1 * V_2 , bool V_167 )
{
T_5 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
T_3 V_271 , V_272 ;
int V_20 ;
if ( V_2 -> V_28 == NULL )
return - V_39 ;
if ( V_2 -> V_50 . V_118 == V_153 )
return 0 ;
V_20 = F_107 ( V_2 , ! V_167 ) ;
if ( V_20 )
return V_20 ;
F_113 ( V_2 ) ;
V_271 = V_2 -> V_50 . V_118 ;
V_272 = V_2 -> V_50 . V_91 ;
F_92 ( ( V_2 -> V_50 . V_118 & ~ V_153 ) != 0 ) ;
V_2 -> V_50 . V_91 |= V_153 ;
if ( V_167 ) {
V_2 -> V_50 . V_91 = V_153 ;
V_2 -> V_50 . V_118 = V_153 ;
V_2 -> V_119 = 1 ;
}
F_204 ( V_2 ,
V_272 ,
V_271 ) ;
if ( F_15 ( V_2 ) )
F_161 ( & V_2 -> V_221 , & V_8 -> V_10 . V_231 ) ;
return 0 ;
}
int F_245 ( struct V_1 * V_2 ,
enum V_322 V_93 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
if ( V_2 -> V_93 == V_93 )
return 0 ;
if ( V_2 -> V_43 ) {
F_246 ( L_12 ) ;
return - V_176 ;
}
if ( ! F_229 ( V_14 , V_2 -> V_28 , V_93 ) ) {
V_20 = F_147 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_2 -> V_28 ) {
V_20 = F_205 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_202 ( V_2 ) ;
if ( F_18 ( V_14 ) -> V_40 < 6 ) {
V_20 = F_78 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_2 -> V_273 )
F_247 ( V_2 , V_93 ) ;
if ( V_2 -> V_274 )
F_248 ( V_8 -> V_10 . V_275 ,
V_2 , V_93 ) ;
V_2 -> V_28 -> V_308 = V_93 ;
}
if ( V_93 == V_94 ) {
T_4 V_272 , V_271 ;
F_13 ( V_2 -> V_50 . V_118 & ~ V_92 ) ;
F_13 ( V_2 -> V_50 . V_91 & ~ V_92 ) ;
V_272 = V_2 -> V_50 . V_91 ;
V_271 = V_2 -> V_50 . V_118 ;
V_2 -> V_50 . V_91 = V_92 ;
V_2 -> V_50 . V_118 = V_92 ;
F_204 ( V_2 ,
V_272 ,
V_271 ) ;
}
V_2 -> V_93 = V_93 ;
F_232 ( V_14 ) ;
return 0 ;
}
int F_249 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_323 * args = V_30 ;
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
args -> V_324 = V_2 -> V_93 != V_94 ;
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int F_250 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_323 * args = V_30 ;
struct V_1 * V_2 ;
enum V_322 V_325 ;
int V_20 ;
switch ( args -> V_324 ) {
case V_326 :
V_325 = V_94 ;
break;
case V_327 :
V_325 = V_328 ;
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
V_20 = F_245 ( V_2 , V_325 ) ;
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_251 ( struct V_1 * V_2 ,
T_4 V_312 ,
struct V_129 * V_329 )
{
T_4 V_272 , V_271 ;
int V_20 ;
if ( V_329 != V_2 -> V_130 ) {
V_20 = F_199 ( V_2 , V_329 ) ;
if ( V_20 )
return V_20 ;
}
V_20 = F_245 ( V_2 , V_94 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_77 ( V_2 , V_312 , true , false ) ;
if ( V_20 )
return V_20 ;
F_113 ( V_2 ) ;
V_271 = V_2 -> V_50 . V_118 ;
V_272 = V_2 -> V_50 . V_91 ;
V_2 -> V_50 . V_118 = 0 ;
V_2 -> V_50 . V_91 |= V_153 ;
F_204 ( V_2 ,
V_272 ,
V_271 ) ;
return 0 ;
}
int
F_205 ( struct V_1 * V_2 )
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
T_3 V_271 , V_272 ;
int V_20 ;
if ( V_2 -> V_50 . V_118 == V_92 )
return 0 ;
V_20 = F_107 ( V_2 , ! V_167 ) ;
if ( V_20 )
return V_20 ;
F_243 ( V_2 ) ;
V_271 = V_2 -> V_50 . V_118 ;
V_272 = V_2 -> V_50 . V_91 ;
if ( ( V_2 -> V_50 . V_91 & V_92 ) == 0 ) {
F_84 ( V_2 ) ;
V_2 -> V_50 . V_91 |= V_92 ;
}
F_92 ( ( V_2 -> V_50 . V_118 & ~ V_92 ) != 0 ) ;
if ( V_167 ) {
V_2 -> V_50 . V_91 = V_92 ;
V_2 -> V_50 . V_118 = V_92 ;
}
F_204 ( V_2 ,
V_272 ,
V_271 ) ;
return 0 ;
}
static int
F_252 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_247 * V_246 = V_32 -> V_248 ;
unsigned long V_330 = V_243 - F_253 ( 20 ) ;
struct V_236 * V_237 ;
struct V_129 * V_130 = NULL ;
T_4 V_131 = 0 ;
int V_20 ;
if ( F_6 ( & V_8 -> V_10 . V_21 ) )
return - V_23 ;
F_174 ( & V_246 -> V_10 . V_25 ) ;
F_23 (request, &file_priv->mm.request_list, client_list) {
if ( F_254 ( V_237 -> V_242 , V_330 ) )
break;
V_130 = V_237 -> V_130 ;
V_131 = V_237 -> V_131 ;
}
F_175 ( & V_246 -> V_10 . V_25 ) ;
if ( V_131 == 0 )
return 0 ;
V_20 = F_95 ( V_130 , V_131 , true , NULL ) ;
if ( V_20 == 0 )
F_179 ( V_8 -> V_254 , & V_8 -> V_10 . V_255 , 0 ) ;
return V_20 ;
}
int
F_77 ( struct V_1 * V_2 ,
T_3 V_312 ,
bool V_276 ,
bool V_313 )
{
int V_20 ;
if ( F_13 ( V_2 -> V_43 == V_331 ) )
return - V_176 ;
if ( V_2 -> V_28 != NULL ) {
if ( ( V_312 && V_2 -> V_113 & ( V_312 - 1 ) ) ||
( V_276 && ! V_2 -> V_276 ) ) {
F_218 ( V_2 -> V_43 ,
L_13
L_14
L_15 ,
V_2 -> V_113 , V_312 ,
V_276 ,
V_2 -> V_276 ) ;
V_20 = F_147 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
}
if ( V_2 -> V_28 == NULL ) {
struct V_7 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
V_20 = F_234 ( V_2 , V_312 ,
V_276 ,
V_313 ) ;
if ( V_20 )
return V_20 ;
if ( ! V_8 -> V_10 . V_275 )
F_247 ( V_2 , V_2 -> V_93 ) ;
}
if ( ! V_2 -> V_273 && V_276 )
F_247 ( V_2 , V_2 -> V_93 ) ;
V_2 -> V_43 ++ ;
V_2 -> V_332 |= V_276 ;
return 0 ;
}
void
F_79 ( struct V_1 * V_2 )
{
F_92 ( V_2 -> V_43 == 0 ) ;
F_92 ( V_2 -> V_28 == NULL ) ;
if ( -- V_2 -> V_43 == 0 )
V_2 -> V_332 = false ;
}
int
F_255 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_333 * args = V_30 ;
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
if ( V_2 -> V_98 != V_188 ) {
F_8 ( L_16 ) ;
V_20 = - V_39 ;
goto V_97;
}
if ( V_2 -> V_334 != NULL && V_2 -> V_334 != V_32 ) {
F_8 ( L_17 ,
args -> V_48 ) ;
V_20 = - V_39 ;
goto V_97;
}
if ( V_2 -> V_335 == 0 ) {
V_20 = F_77 ( V_2 , args -> V_312 , true , false ) ;
if ( V_20 )
goto V_97;
}
V_2 -> V_335 ++ ;
V_2 -> V_334 = V_32 ;
F_113 ( V_2 ) ;
args -> V_82 = V_2 -> V_113 ;
V_97:
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_256 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_333 * args = V_30 ;
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
if ( V_2 -> V_334 != V_32 ) {
F_8 ( L_18 ,
args -> V_48 ) ;
V_20 = - V_39 ;
goto V_97;
}
V_2 -> V_335 -- ;
if ( V_2 -> V_335 == 0 ) {
V_2 -> V_334 = NULL ;
F_79 ( V_2 ) ;
}
V_97:
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_257 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_336 * args = V_30 ;
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
V_20 = F_194 ( V_2 ) ;
args -> V_337 = V_2 -> V_29 ;
if ( V_2 -> V_130 ) {
F_258 ( V_338 > 16 ) ;
args -> V_337 |= F_259 ( V_2 -> V_130 ) << 16 ;
}
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_260 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_246 )
{
return F_252 ( V_14 , V_246 ) ;
}
int
F_261 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_246 )
{
struct V_339 * args = V_30 ;
struct V_1 * V_2 ;
int V_20 ;
switch ( args -> V_98 ) {
case V_195 :
case V_188 :
break;
default:
return - V_39 ;
}
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_246 , args -> V_48 ) ) ;
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
if ( F_138 ( V_2 ) && V_2 -> V_197 == NULL )
F_66 ( V_2 ) ;
args -> V_340 = V_2 -> V_98 != V_99 ;
V_97:
F_30 ( & V_2 -> V_50 ) ;
V_102:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
void F_262 ( struct V_1 * V_2 ,
const struct V_198 * V_199 )
{
F_187 ( & V_2 -> V_221 ) ;
F_187 ( & V_2 -> V_201 ) ;
F_187 ( & V_2 -> V_223 ) ;
F_187 ( & V_2 -> V_341 ) ;
V_2 -> V_199 = V_199 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_98 = V_188 ;
V_2 -> V_276 = true ;
F_3 ( V_2 -> V_50 . V_14 -> V_15 , V_2 -> V_50 . V_9 ) ;
}
struct V_1 * F_26 ( struct V_13 * V_14 ,
T_1 V_9 )
{
struct V_1 * V_2 ;
struct V_207 * V_105 ;
T_4 V_342 ;
V_2 = F_235 ( sizeof( * V_2 ) , V_211 ) ;
if ( V_2 == NULL )
return NULL ;
if ( F_263 ( V_14 , & V_2 -> V_50 , V_9 ) != 0 ) {
F_29 ( V_2 ) ;
return NULL ;
}
V_342 = V_343 | V_344 ;
if ( F_264 ( V_14 ) || F_265 ( V_14 ) ) {
V_342 &= ~ V_345 ;
V_342 |= V_346 ;
}
V_105 = V_2 -> V_50 . V_103 -> V_192 . V_193 -> V_194 -> V_212 ;
F_266 ( V_105 , V_342 ) ;
F_262 ( V_2 , & V_347 ) ;
V_2 -> V_50 . V_118 = V_92 ;
V_2 -> V_50 . V_91 = V_92 ;
if ( F_230 ( V_14 ) ) {
V_2 -> V_93 = V_328 ;
} else
V_2 -> V_93 = V_94 ;
return V_2 ;
}
int F_267 ( struct V_156 * V_2 )
{
F_268 () ;
return 0 ;
}
void F_269 ( struct V_156 * V_348 )
{
struct V_1 * V_2 = F_69 ( V_348 ) ;
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
F_270 ( V_2 ) ;
if ( V_2 -> V_124 )
F_271 ( V_14 , V_2 ) ;
V_2 -> V_43 = 0 ;
if ( F_13 ( F_147 ( V_2 ) == - V_145 ) ) {
bool V_349 ;
V_349 = V_8 -> V_10 . V_126 ;
V_8 -> V_10 . V_126 = false ;
F_13 ( F_147 ( V_2 ) ) ;
V_8 -> V_10 . V_126 = V_349 ;
}
V_2 -> V_200 = 0 ;
F_143 ( V_2 ) ;
F_133 ( V_2 ) ;
F_92 ( V_2 -> V_197 ) ;
if ( V_2 -> V_50 . V_350 )
F_272 ( & V_2 -> V_50 , NULL ) ;
F_28 ( & V_2 -> V_50 ) ;
F_4 ( V_8 , V_2 -> V_50 . V_9 ) ;
F_29 ( V_2 -> V_351 ) ;
F_29 ( V_2 ) ;
}
int
F_273 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
F_19 ( & V_14 -> V_27 ) ;
if ( V_8 -> V_10 . V_250 ) {
F_21 ( & V_14 -> V_27 ) ;
return 0 ;
}
V_20 = F_168 ( V_14 ) ;
if ( V_20 ) {
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
F_169 ( V_14 ) ;
if ( ! F_17 ( V_14 , V_34 ) )
F_148 ( V_14 ) ;
F_185 ( V_14 ) ;
V_8 -> V_10 . V_250 = 1 ;
F_274 ( & V_8 -> V_252 ) ;
F_275 ( V_14 ) ;
F_276 ( V_14 ) ;
F_21 ( & V_14 -> V_27 ) ;
F_277 ( & V_8 -> V_10 . V_255 ) ;
return 0 ;
}
void F_278 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_4 V_352 ;
int V_88 ;
if ( ! F_279 ( V_14 ) )
return;
if ( ! V_8 -> V_353 . V_354 )
return;
V_352 = F_280 ( V_355 ) ;
F_222 ( V_355 , V_352 & ~ V_356 ) ;
F_215 ( V_355 ) ;
for ( V_88 = 0 ; V_88 < V_357 ; V_88 += 4 ) {
T_4 V_358 = F_280 ( V_359 + V_88 ) ;
if ( V_358 && V_358 != V_8 -> V_353 . V_354 [ V_88 / 4 ] )
F_246 ( L_19 ,
V_359 + V_88 , V_358 ) ;
if ( V_358 && ! V_8 -> V_353 . V_354 [ V_88 / 4 ] )
F_281 ( L_20 ) ;
F_222 ( V_359 + V_88 , V_8 -> V_353 . V_354 [ V_88 / 4 ] ) ;
}
F_215 ( V_359 ) ;
F_222 ( V_355 , V_352 ) ;
}
void F_282 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
if ( F_18 ( V_14 ) -> V_40 < 5 ||
V_8 -> V_10 . V_57 == V_360 )
return;
F_222 ( V_361 , F_280 ( V_361 ) |
V_362 ) ;
if ( F_283 ( V_14 ) )
return;
F_222 ( V_363 , F_280 ( V_363 ) | V_364 ) ;
if ( F_284 ( V_14 ) )
F_222 ( V_365 , F_285 ( V_366 ) ) ;
else
F_222 ( V_365 , F_285 ( V_367 ) ) ;
}
static bool
F_286 ( struct V_13 * V_14 )
{
if ( ! F_287 ( V_14 ) )
return false ;
if ( F_284 ( V_14 ) && V_14 -> V_368 -> V_369 < 8 ) {
F_288 ( L_21
L_22 ) ;
return false ;
}
return true ;
}
int
F_289 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
if ( F_18 ( V_14 ) -> V_40 < 6 && ! F_290 () )
return - V_23 ;
if ( F_291 ( V_14 ) && ( F_280 ( 0x120010 ) == 1 ) )
F_222 ( 0x9008 , F_280 ( 0x9008 ) | 0xf0000 ) ;
F_278 ( V_14 ) ;
F_282 ( V_14 ) ;
V_20 = F_292 ( V_14 ) ;
if ( V_20 )
return V_20 ;
if ( F_293 ( V_14 ) ) {
V_20 = F_294 ( V_14 ) ;
if ( V_20 )
goto V_370;
}
if ( F_286 ( V_14 ) ) {
V_20 = F_295 ( V_14 ) ;
if ( V_20 )
goto V_371;
}
V_8 -> V_234 = 1 ;
F_296 ( V_14 ) ;
F_297 ( V_14 ) ;
return 0 ;
V_371:
F_298 ( & V_8 -> V_130 [ V_372 ] ) ;
V_370:
F_298 ( & V_8 -> V_130 [ V_373 ] ) ;
return V_20 ;
}
static bool
F_299 ( struct V_13 * V_14 )
{
if ( V_374 >= 0 )
return V_374 ;
#ifdef F_300
if ( F_18 ( V_14 ) -> V_40 == 6 && V_375 )
return false ;
#endif
return true ;
}
int F_301 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
unsigned long V_183 , V_376 ;
int V_20 ;
V_183 = V_8 -> V_10 . V_377 -> V_378 << V_95 ;
V_376 = V_8 -> V_10 . V_377 -> V_379 << V_95 ;
F_19 ( & V_14 -> V_27 ) ;
if ( F_299 ( V_14 ) && F_302 ( V_14 ) ) {
V_183 -= V_380 * V_38 ;
F_20 ( V_14 , 0 , V_376 , V_183 ) ;
V_20 = F_303 ( V_14 ) ;
if ( V_20 ) {
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
} else {
F_20 ( V_14 , 0 , V_376 ,
V_183 ) ;
}
V_20 = F_289 ( V_14 ) ;
F_21 ( & V_14 -> V_27 ) ;
if ( V_20 ) {
F_304 ( V_14 ) ;
return V_20 ;
}
if ( ! F_17 ( V_14 , V_34 ) )
V_8 -> V_381 . V_382 = 1 ;
return 0 ;
}
void
F_276 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_129 * V_130 ;
int V_88 ;
F_166 (ring, dev_priv, i)
F_298 ( V_130 ) ;
}
int
F_305 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_246 )
{
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
if ( F_17 ( V_14 , V_34 ) )
return 0 ;
if ( F_6 ( & V_8 -> V_10 . V_21 ) ) {
F_8 ( L_23 ) ;
F_306 ( & V_8 -> V_10 . V_21 , 0 ) ;
}
F_19 ( & V_14 -> V_27 ) ;
V_8 -> V_10 . V_250 = 0 ;
V_20 = F_289 ( V_14 ) ;
if ( V_20 != 0 ) {
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
F_92 ( ! F_173 ( & V_8 -> V_10 . V_222 ) ) ;
F_21 ( & V_14 -> V_27 ) ;
V_20 = F_307 ( V_14 ) ;
if ( V_20 )
goto V_383;
return 0 ;
V_383:
F_19 ( & V_14 -> V_27 ) ;
F_276 ( V_14 ) ;
V_8 -> V_10 . V_250 = 1 ;
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_308 ( struct V_13 * V_14 , void * V_30 ,
struct V_31 * V_246 )
{
if ( F_17 ( V_14 , V_34 ) )
return 0 ;
F_309 ( V_14 ) ;
return F_273 ( V_14 ) ;
}
void
F_310 ( struct V_13 * V_14 )
{
int V_20 ;
if ( F_17 ( V_14 , V_34 ) )
return;
V_20 = F_273 ( V_14 ) ;
if ( V_20 )
F_8 ( L_24 , V_20 ) ;
}
static void
F_311 ( struct V_129 * V_130 )
{
F_187 ( & V_130 -> V_222 ) ;
F_187 ( & V_130 -> V_244 ) ;
}
void
F_312 ( struct V_13 * V_14 )
{
int V_88 ;
T_5 * V_8 = V_14 -> V_15 ;
F_187 ( & V_8 -> V_10 . V_222 ) ;
F_187 ( & V_8 -> V_10 . V_231 ) ;
F_187 ( & V_8 -> V_10 . V_220 ) ;
F_187 ( & V_8 -> V_10 . V_321 ) ;
F_187 ( & V_8 -> V_10 . V_230 ) ;
for ( V_88 = 0 ; V_88 < V_338 ; V_88 ++ )
F_311 ( & V_8 -> V_130 [ V_88 ] ) ;
for ( V_88 = 0 ; V_88 < V_384 ; V_88 ++ )
F_187 ( & V_8 -> V_228 [ V_88 ] . V_229 ) ;
F_313 ( & V_8 -> V_10 . V_255 ,
F_190 ) ;
F_314 ( & V_8 -> V_18 ) ;
if ( F_315 ( V_14 ) ) {
F_222 ( V_385 ,
F_285 ( V_386 ) ) ;
}
V_8 -> V_387 = V_388 ;
if ( ! F_17 ( V_14 , V_34 ) )
V_8 -> V_299 = 3 ;
if ( F_18 ( V_14 ) -> V_40 >= 4 || F_316 ( V_14 ) || F_317 ( V_14 ) || F_128 ( V_14 ) )
V_8 -> V_256 = 16 ;
else
V_8 -> V_256 = 8 ;
F_185 ( V_14 ) ;
F_318 ( V_14 ) ;
F_319 ( & V_8 -> V_389 ) ;
V_8 -> V_10 . V_126 = true ;
V_8 -> V_10 . V_390 . V_391 = V_392 ;
V_8 -> V_10 . V_390 . V_393 = V_394 ;
F_320 ( & V_8 -> V_10 . V_390 ) ;
}
static int F_321 ( struct V_13 * V_14 ,
int V_395 , int V_9 , int V_396 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_397 * V_124 ;
int V_20 ;
if ( V_8 -> V_10 . V_398 [ V_395 - 1 ] || ! V_9 )
return 0 ;
V_124 = F_235 ( sizeof( struct V_397 ) , V_211 ) ;
if ( ! V_124 )
return - V_49 ;
V_124 -> V_395 = V_395 ;
V_124 -> V_48 = F_322 ( V_14 , V_9 , V_396 ) ;
if ( ! V_124 -> V_48 ) {
V_20 = - V_49 ;
goto V_399;
}
#ifdef F_323
F_324 ( ( unsigned long ) V_124 -> V_48 -> V_74 , V_124 -> V_48 -> V_9 / V_38 ) ;
#endif
V_8 -> V_10 . V_398 [ V_395 - 1 ] = V_124 ;
return 0 ;
V_399:
F_29 ( V_124 ) ;
return V_20 ;
}
static void F_325 ( struct V_13 * V_14 , int V_395 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_397 * V_124 ;
if ( ! V_8 -> V_10 . V_398 [ V_395 - 1 ] )
return;
V_124 = V_8 -> V_10 . V_398 [ V_395 - 1 ] ;
if ( V_124 -> V_400 ) {
F_271 ( V_14 , V_124 -> V_400 ) ;
}
#ifdef F_323
F_326 ( ( unsigned long ) V_124 -> V_48 -> V_74 , V_124 -> V_48 -> V_9 / V_38 ) ;
#endif
F_327 ( V_14 , V_124 -> V_48 ) ;
F_29 ( V_124 ) ;
V_8 -> V_10 . V_398 [ V_395 - 1 ] = NULL ;
}
void F_328 ( struct V_13 * V_14 )
{
int V_88 ;
for ( V_88 = V_401 ; V_88 <= V_402 ; V_88 ++ )
F_325 ( V_14 , V_88 ) ;
}
void F_271 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_207 * V_105 = V_2 -> V_50 . V_103 -> V_192 . V_193 -> V_194 -> V_212 ;
char * V_74 ;
int V_88 ;
int V_196 ;
if ( ! V_2 -> V_124 )
return;
V_74 = V_2 -> V_124 -> V_48 -> V_74 ;
V_196 = V_2 -> V_50 . V_9 / V_38 ;
for ( V_88 = 0 ; V_88 < V_196 ; V_88 ++ ) {
struct V_68 * V_68 = F_329 ( V_105 , V_88 ) ;
if ( ! F_117 ( V_68 ) ) {
char * V_403 = F_45 ( V_68 ) ;
memcpy ( V_403 , V_74 + V_88 * V_38 , V_38 ) ;
F_48 ( V_403 ) ;
F_330 ( & V_68 , 1 ) ;
F_83 ( V_68 ) ;
F_64 ( V_68 ) ;
F_141 ( V_68 ) ;
}
}
F_85 ( V_14 ) ;
V_2 -> V_124 -> V_400 = NULL ;
V_2 -> V_124 = NULL ;
}
int
F_331 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_395 ,
int V_396 )
{
struct V_207 * V_105 = V_2 -> V_50 . V_103 -> V_192 . V_193 -> V_194 -> V_212 ;
T_5 * V_8 = V_14 -> V_15 ;
int V_20 = 0 ;
int V_196 ;
int V_88 ;
if ( V_395 > V_402 )
return - V_39 ;
if ( V_2 -> V_124 ) {
if ( V_2 -> V_124 -> V_395 == V_395 )
return 0 ;
F_271 ( V_14 , V_2 ) ;
}
if ( ! V_8 -> V_10 . V_398 [ V_395 - 1 ] ) {
V_20 = F_321 ( V_14 , V_395 ,
V_2 -> V_50 . V_9 , V_396 ) ;
if ( V_20 ) {
F_8 ( L_25 ,
V_395 , V_2 -> V_50 . V_9 ) ;
return V_20 ;
}
}
V_2 -> V_124 = V_8 -> V_10 . V_398 [ V_395 - 1 ] ;
V_2 -> V_124 -> V_400 = V_2 ;
V_196 = V_2 -> V_50 . V_9 / V_38 ;
for ( V_88 = 0 ; V_88 < V_196 ; V_88 ++ ) {
struct V_68 * V_68 ;
char * V_403 , * V_404 ;
V_68 = F_329 ( V_105 , V_88 ) ;
if ( F_117 ( V_68 ) )
return F_156 ( V_68 ) ;
V_404 = F_45 ( V_68 ) ;
V_403 = V_2 -> V_124 -> V_48 -> V_74 + ( V_88 * V_38 ) ;
memcpy ( V_403 , V_404 , V_38 ) ;
F_48 ( V_404 ) ;
F_64 ( V_68 ) ;
F_141 ( V_68 ) ;
}
return 0 ;
}
static int
F_89 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_111 * args ,
struct V_31 * V_246 )
{
void * V_74 = V_2 -> V_124 -> V_48 -> V_74 + args -> V_82 ;
char T_6 * V_71 = ( char T_6 * ) ( V_89 ) args -> V_90 ;
if ( F_74 ( V_74 , V_71 , args -> V_9 ) ) {
unsigned long V_109 ;
F_21 ( & V_14 -> V_27 ) ;
V_109 = F_332 ( V_74 , V_71 , args -> V_9 ) ;
F_19 ( & V_14 -> V_27 ) ;
if ( V_109 )
return - V_75 ;
}
F_85 ( V_14 ) ;
return 0 ;
}
void F_333 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
struct V_247 * V_246 = V_32 -> V_248 ;
F_174 ( & V_246 -> V_10 . V_25 ) ;
while ( ! F_173 ( & V_246 -> V_10 . V_244 ) ) {
struct V_236 * V_237 ;
V_237 = F_184 ( & V_246 -> V_10 . V_244 ,
struct V_236 ,
V_249 ) ;
F_144 ( & V_237 -> V_249 ) ;
V_237 -> V_246 = NULL ;
}
F_175 ( & V_246 -> V_10 . V_25 ) ;
}
static bool F_334 ( struct V_405 * V_405 , struct V_406 * V_407 )
{
if ( ! F_93 ( V_405 ) )
return false ;
#if F_335 ( V_408 ) || F_335 ( V_409 )
return V_405 -> V_410 == V_407 ;
#else
return false ;
#endif
}
static int
V_392 ( struct V_411 * V_411 , struct V_412 * V_413 )
{
struct V_7 * V_8 =
F_191 ( V_411 ,
struct V_7 ,
V_10 . V_390 ) ;
struct V_13 * V_14 = V_8 -> V_14 ;
struct V_1 * V_2 ;
int V_414 = V_413 -> V_414 ;
bool V_102 = true ;
int V_415 ;
if ( ! F_192 ( & V_14 -> V_27 ) ) {
if ( ! F_334 ( & V_14 -> V_27 , V_416 ) )
return 0 ;
if ( V_8 -> V_10 . V_185 )
return 0 ;
V_102 = false ;
}
if ( V_414 ) {
V_414 -= F_131 ( V_8 , V_414 ) ;
if ( V_414 > 0 )
V_414 -= F_145 ( V_8 , V_414 ,
false ) ;
if ( V_414 > 0 )
F_132 ( V_8 ) ;
}
V_415 = 0 ;
F_23 (obj, &dev_priv->mm.unbound_list, gtt_list)
if ( V_2 -> V_200 == 0 )
V_415 += V_2 -> V_50 . V_9 >> V_95 ;
F_23 (obj, &dev_priv->mm.inactive_list, gtt_list)
if ( V_2 -> V_43 == 0 && V_2 -> V_200 == 0 )
V_415 += V_2 -> V_50 . V_9 >> V_95 ;
if ( V_102 )
F_21 ( & V_14 -> V_27 ) ;
return V_415 ;
}

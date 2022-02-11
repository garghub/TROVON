static bool F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
return F_2 ( V_2 ) || V_4 != V_5 ;
}
static bool F_3 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 . V_9 == V_10 )
return false ;
if ( ! F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_11 ) )
return true ;
return V_7 -> V_12 ;
}
static int
F_4 ( struct V_13 * V_14 ,
struct V_15 * V_16 , T_1 V_17 )
{
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
return F_5 ( & V_14 -> V_18 . V_8 . V_19 , V_16 ,
V_17 , 0 , 0 , 0 ,
V_14 -> V_18 . V_20 ,
V_21 ,
V_22 ) ;
}
static void
F_6 ( struct V_15 * V_16 )
{
F_7 ( V_16 ) ;
}
static void F_8 ( struct V_13 * V_23 ,
T_2 V_17 )
{
F_9 ( & V_23 -> V_19 . V_24 ) ;
V_23 -> V_19 . V_25 ++ ;
V_23 -> V_19 . V_26 += V_17 ;
F_10 ( & V_23 -> V_19 . V_24 ) ;
}
static void F_11 ( struct V_13 * V_23 ,
T_2 V_17 )
{
F_9 ( & V_23 -> V_19 . V_24 ) ;
V_23 -> V_19 . V_25 -- ;
V_23 -> V_19 . V_26 -= V_17 ;
F_10 ( & V_23 -> V_19 . V_24 ) ;
}
static int
F_12 ( struct V_27 * error )
{
int V_28 ;
if ( ! F_13 ( error ) )
return 0 ;
V_28 = F_14 ( error -> V_29 ,
! F_13 ( error ) ,
10 * V_30 ) ;
if ( V_28 == 0 ) {
F_15 ( L_1 ) ;
return - V_31 ;
} else if ( V_28 < 0 ) {
return V_28 ;
} else {
return 0 ;
}
}
int F_16 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
int V_28 ;
V_28 = F_12 ( & V_23 -> V_32 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_18 ( & V_2 -> V_33 ) ;
if ( V_28 )
return V_28 ;
F_19 ( F_20 ( V_2 ) ) ;
return 0 ;
}
int
F_21 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_37 * V_18 = & V_23 -> V_18 ;
struct V_38 * args = V_34 ;
struct V_39 * V_40 ;
T_2 V_41 ;
V_41 = 0 ;
F_22 ( & V_2 -> V_33 ) ;
F_23 (vma, &ggtt->base.active_list, vm_link)
if ( V_40 -> V_42 )
V_41 += V_40 -> V_16 . V_17 ;
F_23 (vma, &ggtt->base.inactive_list, vm_link)
if ( V_40 -> V_42 )
V_41 += V_40 -> V_16 . V_17 ;
F_24 ( & V_2 -> V_33 ) ;
args -> V_43 = V_18 -> V_8 . V_44 ;
args -> V_45 = args -> V_43 - V_41 ;
return 0 ;
}
static int
F_25 ( struct V_6 * V_7 )
{
struct V_46 * V_47 = V_7 -> V_8 . V_48 -> V_49 ;
char * V_50 = V_7 -> V_51 -> V_50 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
int V_56 ;
if ( F_19 ( F_26 ( V_7 ) ) )
return - V_57 ;
for ( V_56 = 0 ; V_56 < V_7 -> V_8 . V_17 / V_58 ; V_56 ++ ) {
struct V_59 * V_59 ;
char * V_60 ;
V_59 = F_27 ( V_47 , V_56 ) ;
if ( F_28 ( V_59 ) )
return F_29 ( V_59 ) ;
V_60 = F_30 ( V_59 ) ;
memcpy ( V_50 , V_60 , V_58 ) ;
F_31 ( V_50 , V_58 ) ;
F_32 ( V_60 ) ;
F_33 ( V_59 ) ;
V_50 += V_58 ;
}
F_34 ( F_17 ( V_7 -> V_8 . V_2 ) ) ;
V_53 = F_35 ( sizeof( * V_53 ) , V_61 ) ;
if ( V_53 == NULL )
return - V_62 ;
if ( F_36 ( V_53 , 1 , V_61 ) ) {
F_37 ( V_53 ) ;
return - V_62 ;
}
V_55 = V_53 -> V_63 ;
V_55 -> V_64 = 0 ;
V_55 -> V_65 = V_7 -> V_8 . V_17 ;
F_38 ( V_55 ) = V_7 -> V_51 -> V_66 ;
F_39 ( V_55 ) = V_7 -> V_8 . V_17 ;
V_7 -> V_67 = V_53 ;
return 0 ;
}
static void
F_40 ( struct V_6 * V_7 )
{
int V_28 ;
F_41 ( V_7 -> V_68 == V_69 ) ;
V_28 = F_42 ( V_7 , true ) ;
if ( F_19 ( V_28 ) ) {
V_7 -> V_8 . V_70 = V_7 -> V_8 . V_9 = V_10 ;
}
if ( V_7 -> V_68 == V_71 )
V_7 -> V_72 = 0 ;
if ( V_7 -> V_72 ) {
struct V_46 * V_47 = V_7 -> V_8 . V_48 -> V_49 ;
char * V_50 = V_7 -> V_51 -> V_50 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_7 -> V_8 . V_17 / V_58 ; V_56 ++ ) {
struct V_59 * V_59 ;
char * V_73 ;
V_59 = F_27 ( V_47 , V_56 ) ;
if ( F_28 ( V_59 ) )
continue;
V_73 = F_30 ( V_59 ) ;
F_31 ( V_50 , V_58 ) ;
memcpy ( V_73 , V_50 , V_58 ) ;
F_32 ( V_73 ) ;
F_43 ( V_59 ) ;
if ( V_7 -> V_68 == V_74 )
F_44 ( V_59 ) ;
F_33 ( V_59 ) ;
V_50 += V_58 ;
}
V_7 -> V_72 = 0 ;
}
F_45 ( V_7 -> V_67 ) ;
F_37 ( V_7 -> V_67 ) ;
}
static void
F_46 ( struct V_6 * V_7 )
{
F_47 ( V_7 -> V_8 . V_2 , V_7 -> V_51 ) ;
}
static int
F_48 ( struct V_6 * V_7 )
{
struct V_39 * V_40 , * V_75 ;
int V_28 ;
F_49 ( & V_7 -> V_8 ) ;
F_50 (vma, next, &obj->vma_list, obj_link)
if ( F_51 ( V_40 ) )
break;
V_28 = F_52 ( V_7 ) ;
F_53 ( & V_7 -> V_8 ) ;
return V_28 ;
}
int
F_54 ( struct V_6 * V_7 ,
int V_76 )
{
T_3 * V_77 ;
int V_28 ;
if ( V_7 -> V_51 ) {
if ( ( unsigned long ) V_7 -> V_51 -> V_50 & ( V_76 - 1 ) )
return - V_78 ;
return 0 ;
}
if ( V_7 -> V_68 != V_74 )
return - V_79 ;
if ( V_7 -> V_8 . V_48 == NULL )
return - V_57 ;
V_28 = F_48 ( V_7 ) ;
if ( V_28 )
return V_28 ;
V_77 = F_55 ( V_7 -> V_8 . V_2 , V_7 -> V_8 . V_17 , V_76 ) ;
if ( ! V_77 )
return - V_62 ;
V_7 -> V_51 = V_77 ;
V_7 -> V_80 = & V_81 ;
return F_56 ( V_7 ) ;
}
static int
F_57 ( struct V_6 * V_7 ,
struct V_82 * args ,
struct V_35 * V_83 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
void * V_50 = V_7 -> V_51 -> V_50 + args -> V_64 ;
char T_4 * V_84 = F_58 ( args -> V_85 ) ;
int V_28 = 0 ;
V_28 = F_59 ( V_7 , false ) ;
if ( V_28 )
return V_28 ;
F_60 ( V_7 , V_86 ) ;
if ( F_61 ( V_50 , V_84 , args -> V_17 ) ) {
unsigned long V_87 ;
F_24 ( & V_2 -> V_33 ) ;
V_87 = F_62 ( V_50 , V_84 , args -> V_17 ) ;
F_22 ( & V_2 -> V_33 ) ;
if ( V_87 ) {
V_28 = - V_79 ;
goto V_88;
}
}
F_31 ( V_50 , args -> V_17 ) ;
F_34 ( F_17 ( V_2 ) ) ;
V_88:
F_63 ( V_7 , false , V_86 ) ;
return V_28 ;
}
void * F_64 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
return F_65 ( V_23 -> V_89 , V_61 ) ;
}
void F_66 ( struct V_6 * V_7 )
{
struct V_13 * V_23 = F_17 ( V_7 -> V_8 . V_2 ) ;
F_67 ( V_23 -> V_89 , V_7 ) ;
}
static int
F_68 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
T_5 V_17 ,
T_6 * V_90 )
{
struct V_6 * V_7 ;
int V_28 ;
T_1 V_91 ;
V_17 = F_69 ( V_17 , V_58 ) ;
if ( V_17 == 0 )
return - V_57 ;
V_7 = F_70 ( V_2 , V_17 ) ;
if ( F_28 ( V_7 ) )
return F_29 ( V_7 ) ;
V_28 = F_71 ( V_36 , & V_7 -> V_8 , & V_91 ) ;
F_72 ( & V_7 -> V_8 ) ;
if ( V_28 )
return V_28 ;
* V_90 = V_91 ;
return 0 ;
}
int
F_73 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
struct V_92 * args )
{
args -> V_93 = F_74 ( args -> V_94 * F_75 ( args -> V_95 , 8 ) , 64 ) ;
args -> V_17 = args -> V_93 * args -> V_96 ;
return F_68 ( V_36 , V_2 ,
args -> V_17 , & args -> V_91 ) ;
}
int
F_76 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_97 * args = V_34 ;
return F_68 ( V_36 , V_2 ,
args -> V_17 , & args -> V_91 ) ;
}
static inline int
F_77 ( char T_4 * V_98 ,
const char * V_99 , int V_100 ,
int V_65 )
{
int V_28 , V_101 = 0 ;
while ( V_65 > 0 ) {
int V_102 = F_74 ( V_100 + 1 , 64 ) ;
int V_103 = F_78 ( V_102 - V_100 , V_65 ) ;
int V_104 = V_100 ^ 64 ;
V_28 = F_79 ( V_98 + V_101 ,
V_99 + V_104 ,
V_103 ) ;
if ( V_28 )
return V_28 + V_65 ;
V_101 += V_103 ;
V_100 += V_103 ;
V_65 -= V_103 ;
}
return 0 ;
}
static inline int
F_80 ( char * V_99 , int V_100 ,
const char T_4 * V_98 ,
int V_65 )
{
int V_28 , V_101 = 0 ;
while ( V_65 > 0 ) {
int V_102 = F_74 ( V_100 + 1 , 64 ) ;
int V_103 = F_78 ( V_102 - V_100 , V_65 ) ;
int V_104 = V_100 ^ 64 ;
V_28 = F_81 ( V_99 + V_104 ,
V_98 + V_101 ,
V_103 ) ;
if ( V_28 )
return V_28 + V_65 ;
V_101 += V_103 ;
V_100 += V_103 ;
V_65 -= V_103 ;
}
return 0 ;
}
int F_82 ( struct V_6 * V_7 ,
int * V_105 )
{
int V_28 ;
* V_105 = 0 ;
if ( F_19 ( ! F_83 ( V_7 ) ) )
return - V_57 ;
if ( ! ( V_7 -> V_8 . V_70 & V_10 ) ) {
* V_105 = ! F_1 ( V_7 -> V_8 . V_2 ,
V_7 -> V_11 ) ;
V_28 = F_59 ( V_7 , true ) ;
if ( V_28 )
return V_28 ;
}
V_28 = F_56 ( V_7 ) ;
if ( V_28 )
return V_28 ;
F_84 ( V_7 ) ;
return V_28 ;
}
static int
F_85 ( struct V_59 * V_59 , int V_106 , int V_107 ,
char T_4 * V_84 ,
bool V_108 , bool V_105 )
{
char * V_50 ;
int V_28 ;
if ( F_86 ( V_108 ) )
return - V_57 ;
V_50 = F_30 ( V_59 ) ;
if ( V_105 )
F_31 ( V_50 + V_106 ,
V_107 ) ;
V_28 = F_87 ( V_84 ,
V_50 + V_106 ,
V_107 ) ;
F_32 ( V_50 ) ;
return V_28 ? - V_79 : 0 ;
}
static void
F_88 ( char * V_109 , unsigned long V_65 ,
bool V_110 )
{
if ( F_86 ( V_110 ) ) {
unsigned long V_111 = ( unsigned long ) V_109 ;
unsigned long V_112 = ( unsigned long ) V_109 + V_65 ;
V_111 = F_89 ( V_111 , 128 ) ;
V_112 = F_90 ( V_112 , 128 ) ;
F_31 ( ( void * ) V_111 , V_112 - V_111 ) ;
} else {
F_31 ( V_109 , V_65 ) ;
}
}
static int
F_91 ( struct V_59 * V_59 , int V_106 , int V_107 ,
char T_4 * V_84 ,
bool V_108 , bool V_105 )
{
char * V_50 ;
int V_28 ;
V_50 = F_92 ( V_59 ) ;
if ( V_105 )
F_88 ( V_50 + V_106 ,
V_107 ,
V_108 ) ;
if ( V_108 )
V_28 = F_77 ( V_84 ,
V_50 , V_106 ,
V_107 ) ;
else
V_28 = F_79 ( V_84 ,
V_50 + V_106 ,
V_107 ) ;
F_93 ( V_59 ) ;
return V_28 ? - V_79 : 0 ;
}
static inline unsigned long
F_94 ( struct V_113 * V_47 ,
T_5 V_114 , int V_115 ,
char T_4 * V_84 ,
unsigned long V_65 , bool V_116 )
{
void T_7 * V_117 ;
void * V_50 ;
T_5 V_87 ;
V_117 = F_95 ( V_47 , V_114 , V_58 ) ;
V_50 = ( void V_118 * ) V_117 + V_115 ;
if ( V_116 )
V_87 = F_81 ( V_50 , V_84 , V_65 ) ;
else
V_87 = F_79 ( V_84 , V_50 , V_65 ) ;
F_96 ( V_117 ) ;
return V_87 ;
}
static int
F_97 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_5 V_17 ,
T_5 V_119 , T_5 V_85 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_37 * V_18 = & V_23 -> V_18 ;
struct V_15 V_16 ;
char T_4 * V_84 ;
T_5 V_120 ;
T_5 V_64 ;
int V_28 ;
V_28 = F_98 ( V_7 , 0 , V_121 ) ;
if ( V_28 ) {
V_28 = F_4 ( V_23 , & V_16 , V_58 ) ;
if ( V_28 )
goto V_88;
V_28 = F_56 ( V_7 ) ;
if ( V_28 ) {
F_6 ( & V_16 ) ;
goto V_88;
}
F_84 ( V_7 ) ;
} else {
V_16 . V_111 = F_99 ( V_7 ) ;
V_16 . V_122 = false ;
V_28 = F_100 ( V_7 ) ;
if ( V_28 )
goto V_123;
}
V_28 = F_101 ( V_7 , false ) ;
if ( V_28 )
goto V_123;
V_84 = F_58 ( V_85 ) ;
V_120 = V_17 ;
V_64 = V_119 ;
F_24 ( & V_2 -> V_33 ) ;
if ( F_102 ( ! V_14 . V_124 ) ) {
V_28 = F_103 ( V_84 , V_120 ) ;
if ( V_28 ) {
F_22 ( & V_2 -> V_33 ) ;
goto V_123;
}
}
while ( V_120 > 0 ) {
T_1 V_114 = V_16 . V_111 ;
unsigned V_115 = F_104 ( V_64 ) ;
unsigned V_107 = V_58 - V_115 ;
V_107 = V_120 < V_107 ? V_120 : V_107 ;
if ( V_16 . V_122 ) {
F_105 () ;
V_18 -> V_8 . V_125 ( & V_18 -> V_8 ,
F_106 ( V_7 , V_64 >> V_126 ) ,
V_16 . V_111 ,
V_5 , 0 ) ;
F_105 () ;
} else {
V_114 += V_64 & V_127 ;
}
if ( F_94 ( V_18 -> V_128 , V_114 ,
V_115 , V_84 ,
V_107 , false ) ) {
V_28 = - V_79 ;
break;
}
V_120 -= V_107 ;
V_84 += V_107 ;
V_64 += V_107 ;
}
F_22 ( & V_2 -> V_33 ) ;
if ( V_28 == 0 && ( V_7 -> V_8 . V_70 & V_129 ) == 0 ) {
V_28 = F_101 ( V_7 , false ) ;
}
V_123:
if ( V_16 . V_122 ) {
F_105 () ;
V_18 -> V_8 . V_130 ( & V_18 -> V_8 ,
V_16 . V_111 , V_16 . V_17 ,
true ) ;
F_107 ( V_7 ) ;
F_6 ( & V_16 ) ;
} else {
F_108 ( V_7 ) ;
}
V_88:
return V_28 ;
}
static int
F_109 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_131 * args ,
struct V_35 * V_36 )
{
char T_4 * V_84 ;
T_8 V_120 ;
T_9 V_64 ;
int V_106 , V_107 , V_28 = 0 ;
int V_132 , V_108 ;
int V_133 = 0 ;
int V_105 = 0 ;
struct V_134 V_135 ;
if ( ! F_83 ( V_7 ) )
return - V_136 ;
V_84 = F_58 ( args -> V_85 ) ;
V_120 = args -> V_17 ;
V_132 = F_26 ( V_7 ) ;
V_28 = F_82 ( V_7 , & V_105 ) ;
if ( V_28 )
return V_28 ;
V_64 = args -> V_64 ;
F_110 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_59 * V_59 = F_111 ( & V_135 ) ;
if ( V_120 <= 0 )
break;
V_106 = F_104 ( V_64 ) ;
V_107 = V_120 ;
if ( ( V_106 + V_107 ) > V_58 )
V_107 = V_58 - V_106 ;
V_108 = V_132 &&
( F_112 ( V_59 ) & ( 1 << 17 ) ) != 0 ;
V_28 = F_85 ( V_59 , V_106 , V_107 ,
V_84 , V_108 ,
V_105 ) ;
if ( V_28 == 0 )
goto V_137;
F_24 ( & V_2 -> V_33 ) ;
if ( F_102 ( ! V_14 . V_124 ) && ! V_133 ) {
V_28 = F_103 ( V_84 , V_120 ) ;
( void ) V_28 ;
V_133 = 1 ;
}
V_28 = F_91 ( V_59 , V_106 , V_107 ,
V_84 , V_108 ,
V_105 ) ;
F_22 ( & V_2 -> V_33 ) ;
if ( V_28 )
goto V_88;
V_137:
V_120 -= V_107 ;
V_84 += V_107 ;
V_64 += V_107 ;
}
V_88:
F_107 ( V_7 ) ;
return V_28 ;
}
int
F_113 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_131 * args = V_34 ;
struct V_6 * V_7 ;
int V_28 = 0 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_114 ( V_138 ,
F_58 ( args -> V_85 ) ,
args -> V_17 ) )
return - V_79 ;
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
return V_28 ;
V_7 = F_115 ( F_116 ( V_36 , args -> V_91 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_28 = - V_139 ;
goto V_140;
}
if ( args -> V_64 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_64 ) {
V_28 = - V_57 ;
goto V_88;
}
F_117 ( V_7 , args -> V_64 , args -> V_17 ) ;
V_28 = F_109 ( V_2 , V_7 , args , V_36 ) ;
if ( V_28 == - V_79 || V_28 == - V_136 ) {
F_118 ( F_17 ( V_2 ) ) ;
V_28 = F_97 ( V_2 , V_7 , args -> V_17 ,
args -> V_64 , args -> V_85 ) ;
F_119 ( F_17 ( V_2 ) ) ;
}
V_88:
F_53 ( & V_7 -> V_8 ) ;
V_140:
F_24 ( & V_2 -> V_33 ) ;
return V_28 ;
}
static inline int
F_120 ( struct V_113 * V_47 ,
T_9 V_114 , int V_115 ,
char T_4 * V_84 ,
int V_65 )
{
void T_7 * V_141 ;
void * V_50 ;
unsigned long V_87 ;
V_141 = F_121 ( V_47 , V_114 ) ;
V_50 = ( void V_118 * ) V_141 + V_115 ;
V_87 = F_61 ( V_50 ,
V_84 , V_65 ) ;
F_122 ( V_141 ) ;
return V_87 ;
}
static int
F_123 ( struct V_13 * V_14 ,
struct V_6 * V_7 ,
struct V_82 * args ,
struct V_35 * V_36 )
{
struct V_37 * V_18 = & V_14 -> V_18 ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_15 V_16 ;
T_5 V_120 , V_64 ;
char T_4 * V_84 ;
int V_28 ;
bool V_142 = false ;
if ( V_7 -> V_143 != V_144 )
return - V_79 ;
V_28 = F_98 ( V_7 , 0 , V_121 | V_145 ) ;
if ( V_28 ) {
V_28 = F_4 ( V_14 , & V_16 , V_58 ) ;
if ( V_28 )
goto V_88;
V_28 = F_56 ( V_7 ) ;
if ( V_28 ) {
F_6 ( & V_16 ) ;
goto V_88;
}
F_84 ( V_7 ) ;
} else {
V_16 . V_111 = F_99 ( V_7 ) ;
V_16 . V_122 = false ;
V_28 = F_100 ( V_7 ) ;
if ( V_28 )
goto V_123;
}
V_28 = F_101 ( V_7 , true ) ;
if ( V_28 )
goto V_123;
F_60 ( V_7 , V_146 ) ;
V_7 -> V_72 = true ;
V_84 = F_58 ( args -> V_85 ) ;
V_64 = args -> V_64 ;
V_120 = args -> V_17 ;
while ( V_120 ) {
T_1 V_114 = V_16 . V_111 ;
unsigned V_115 = F_104 ( V_64 ) ;
unsigned V_107 = V_58 - V_115 ;
V_107 = V_120 < V_107 ? V_120 : V_107 ;
if ( V_16 . V_122 ) {
F_105 () ;
V_18 -> V_8 . V_125 ( & V_18 -> V_8 ,
F_106 ( V_7 , V_64 >> V_126 ) ,
V_16 . V_111 , V_5 , 0 ) ;
F_105 () ;
} else {
V_114 += V_64 & V_127 ;
}
if ( F_120 ( V_18 -> V_128 , V_114 ,
V_115 , V_84 , V_107 ) ) {
V_142 = true ;
F_24 ( & V_2 -> V_33 ) ;
if ( F_94 ( V_18 -> V_128 ,
V_114 ,
V_115 , V_84 ,
V_107 , true ) ) {
V_28 = - V_79 ;
F_22 ( & V_2 -> V_33 ) ;
goto V_147;
}
F_22 ( & V_2 -> V_33 ) ;
}
V_120 -= V_107 ;
V_84 += V_107 ;
V_64 += V_107 ;
}
V_147:
if ( V_142 ) {
if ( V_28 == 0 &&
( V_7 -> V_8 . V_70 & V_129 ) == 0 ) {
V_28 = F_101 ( V_7 , false ) ;
}
}
F_63 ( V_7 , false , V_146 ) ;
V_123:
if ( V_16 . V_122 ) {
F_105 () ;
V_18 -> V_8 . V_130 ( & V_18 -> V_8 ,
V_16 . V_111 , V_16 . V_17 ,
true ) ;
F_107 ( V_7 ) ;
F_6 ( & V_16 ) ;
} else {
F_108 ( V_7 ) ;
}
V_88:
return V_28 ;
}
static int
F_124 ( struct V_59 * V_59 , int V_106 , int V_107 ,
char T_4 * V_84 ,
bool V_108 ,
bool V_148 ,
bool V_149 )
{
char * V_50 ;
int V_28 ;
if ( F_86 ( V_108 ) )
return - V_57 ;
V_50 = F_30 ( V_59 ) ;
if ( V_148 )
F_31 ( V_50 + V_106 ,
V_107 ) ;
V_28 = F_125 ( V_50 + V_106 ,
V_84 , V_107 ) ;
if ( V_149 )
F_31 ( V_50 + V_106 ,
V_107 ) ;
F_32 ( V_50 ) ;
return V_28 ? - V_79 : 0 ;
}
static int
F_126 ( struct V_59 * V_59 , int V_106 , int V_107 ,
char T_4 * V_84 ,
bool V_108 ,
bool V_148 ,
bool V_149 )
{
char * V_50 ;
int V_28 ;
V_50 = F_92 ( V_59 ) ;
if ( F_86 ( V_148 || V_108 ) )
F_88 ( V_50 + V_106 ,
V_107 ,
V_108 ) ;
if ( V_108 )
V_28 = F_80 ( V_50 , V_106 ,
V_84 ,
V_107 ) ;
else
V_28 = F_81 ( V_50 + V_106 ,
V_84 ,
V_107 ) ;
if ( V_149 )
F_88 ( V_50 + V_106 ,
V_107 ,
V_108 ) ;
F_93 ( V_59 ) ;
return V_28 ? - V_79 : 0 ;
}
static int
F_127 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_82 * args ,
struct V_35 * V_36 )
{
T_8 V_120 ;
T_9 V_64 ;
char T_4 * V_84 ;
int V_106 , V_107 , V_28 = 0 ;
int V_132 , V_108 ;
int V_150 = 0 ;
int V_149 = 0 ;
int V_148 = 0 ;
struct V_134 V_135 ;
V_84 = F_58 ( args -> V_85 ) ;
V_120 = args -> V_17 ;
V_132 = F_26 ( V_7 ) ;
if ( V_7 -> V_8 . V_9 != V_10 ) {
V_149 = F_3 ( V_7 ) ;
V_28 = F_59 ( V_7 , false ) ;
if ( V_28 )
return V_28 ;
}
if ( ( V_7 -> V_8 . V_70 & V_10 ) == 0 )
V_148 =
! F_1 ( V_2 , V_7 -> V_11 ) ;
V_28 = F_56 ( V_7 ) ;
if ( V_28 )
return V_28 ;
F_60 ( V_7 , V_86 ) ;
F_84 ( V_7 ) ;
V_64 = args -> V_64 ;
V_7 -> V_72 = 1 ;
F_110 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_59 * V_59 = F_111 ( & V_135 ) ;
int V_151 ;
if ( V_120 <= 0 )
break;
V_106 = F_104 ( V_64 ) ;
V_107 = V_120 ;
if ( ( V_106 + V_107 ) > V_58 )
V_107 = V_58 - V_106 ;
V_151 = V_148 &&
( ( V_106 | V_107 )
& ( V_152 . V_153 - 1 ) ) ;
V_108 = V_132 &&
( F_112 ( V_59 ) & ( 1 << 17 ) ) != 0 ;
V_28 = F_124 ( V_59 , V_106 , V_107 ,
V_84 , V_108 ,
V_151 ,
V_149 ) ;
if ( V_28 == 0 )
goto V_137;
V_150 = 1 ;
F_24 ( & V_2 -> V_33 ) ;
V_28 = F_126 ( V_59 , V_106 , V_107 ,
V_84 , V_108 ,
V_151 ,
V_149 ) ;
F_22 ( & V_2 -> V_33 ) ;
if ( V_28 )
goto V_88;
V_137:
V_120 -= V_107 ;
V_84 += V_107 ;
V_64 += V_107 ;
}
V_88:
F_107 ( V_7 ) ;
if ( V_150 ) {
if ( ! V_149 &&
V_7 -> V_8 . V_9 != V_10 ) {
if ( F_128 ( V_7 , V_7 -> V_12 ) )
V_149 = true ;
}
}
if ( V_149 )
F_34 ( F_17 ( V_2 ) ) ;
else
V_7 -> V_154 = true ;
F_63 ( V_7 , false , V_86 ) ;
return V_28 ;
}
int
F_129 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_82 * args = V_34 ;
struct V_6 * V_7 ;
int V_28 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_114 ( V_155 ,
F_58 ( args -> V_85 ) ,
args -> V_17 ) )
return - V_79 ;
if ( F_102 ( ! V_14 . V_124 ) ) {
V_28 = F_130 ( F_58 ( args -> V_85 ) ,
args -> V_17 ) ;
if ( V_28 )
return - V_79 ;
}
F_118 ( V_23 ) ;
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
goto V_156;
V_7 = F_115 ( F_116 ( V_36 , args -> V_91 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_28 = - V_139 ;
goto V_140;
}
if ( args -> V_64 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_64 ) {
V_28 = - V_57 ;
goto V_88;
}
F_131 ( V_7 , args -> V_64 , args -> V_17 ) ;
V_28 = - V_79 ;
if ( ! F_83 ( V_7 ) ||
F_3 ( V_7 ) ) {
V_28 = F_123 ( V_23 , V_7 , args , V_36 ) ;
}
if ( V_28 == - V_79 || V_28 == - V_157 ) {
if ( V_7 -> V_51 )
V_28 = F_57 ( V_7 , args , V_36 ) ;
else if ( F_83 ( V_7 ) )
V_28 = F_127 ( V_2 , V_7 , args , V_36 ) ;
else
V_28 = - V_136 ;
}
V_88:
F_53 ( & V_7 -> V_8 ) ;
V_140:
F_24 ( & V_2 -> V_33 ) ;
V_156:
F_119 ( V_23 ) ;
return V_28 ;
}
static int
F_132 ( unsigned V_158 , bool V_159 )
{
if ( F_133 ( V_158 ) )
return - V_31 ;
if ( F_134 ( V_158 ) ) {
if ( ! V_159 )
return - V_31 ;
return - V_160 ;
}
return 0 ;
}
static unsigned long F_135 ( unsigned * V_161 )
{
unsigned long V_162 ;
* V_161 = F_136 () ;
V_162 = F_137 () >> 10 ;
F_138 () ;
return V_162 ;
}
static bool F_139 ( unsigned long V_163 , unsigned V_161 )
{
unsigned V_164 ;
if ( F_140 ( F_135 ( & V_164 ) , V_163 ) )
return true ;
return V_164 != V_161 ;
}
bool F_141 ( const struct V_165 * V_166 ,
int V_167 , unsigned long V_168 )
{
unsigned V_161 ;
V_168 += F_135 ( & V_161 ) ;
do {
if ( F_142 ( V_166 ) )
return true ;
if ( F_143 ( V_167 , V_169 ) )
break;
if ( F_139 ( V_168 , V_161 ) )
break;
F_144 () ;
} while ( ! F_145 () );
return false ;
}
int F_146 ( struct V_165 * V_166 ,
bool V_159 ,
T_10 * V_163 ,
struct V_170 * V_171 )
{
int V_167 = V_159 ? V_172 : V_173 ;
F_147 ( V_174 ) ;
struct V_175 V_176 ;
unsigned long V_177 ;
T_10 V_178 = 0 ;
int V_28 = 0 ;
F_148 () ;
if ( F_149 ( & V_166 -> V_179 ) )
return 0 ;
if ( F_142 ( V_166 ) )
return 0 ;
V_177 = V_180 ;
if ( V_163 ) {
if ( F_19 ( * V_163 < 0 ) )
return - V_57 ;
if ( * V_163 == 0 )
return - V_181 ;
V_177 = F_150 ( * V_163 ) ;
V_178 = F_151 () ;
}
F_152 ( V_166 ) ;
if ( F_153 ( V_166 -> V_14 ) -> V_182 >= 6 )
F_154 ( V_166 -> V_14 , V_171 , V_166 -> V_183 ) ;
if ( F_155 ( V_166 , V_167 , 5 ) )
goto V_184;
F_156 ( V_167 ) ;
F_157 ( & V_166 -> V_14 -> V_32 . V_185 , & V_174 ) ;
F_158 ( & V_176 , V_166 -> V_186 ) ;
if ( F_159 ( V_166 -> V_187 , & V_176 ) )
goto V_188;
for (; ; ) {
if ( F_143 ( V_167 , V_169 ) ) {
V_28 = - V_189 ;
break;
}
V_177 = F_160 ( V_177 ) ;
if ( V_177 == 0 ) {
V_28 = - V_181 ;
break;
}
if ( F_161 ( & V_176 ) )
break;
F_156 ( V_167 ) ;
V_188:
if ( F_162 ( V_166 ) )
break;
if ( F_155 ( V_166 , V_167 , 2 ) )
break;
}
F_163 ( & V_166 -> V_14 -> V_32 . V_185 , & V_174 ) ;
F_164 ( V_166 -> V_187 , & V_176 ) ;
F_165 ( V_190 ) ;
V_184:
F_166 ( V_166 ) ;
if ( V_163 ) {
T_10 V_191 = * V_163 - ( F_151 () - V_178 ) ;
* V_163 = V_191 < 0 ? 0 : V_191 ;
if ( V_28 == - V_181 && * V_163 < F_167 ( 1 ) * 1000 )
* V_163 = 0 ;
}
if ( V_171 && V_166 -> V_186 == V_166 -> V_187 -> V_192 ) {
F_9 ( & V_166 -> V_14 -> V_171 . V_193 ) ;
F_168 ( & V_171 -> V_194 ) ;
F_10 ( & V_166 -> V_14 -> V_171 . V_193 ) ;
}
return V_28 ;
}
int F_169 ( struct V_165 * V_166 ,
struct V_35 * V_36 )
{
struct V_195 * V_83 ;
F_19 ( ! V_166 || ! V_36 || V_166 -> V_83 ) ;
if ( ! V_166 || ! V_36 )
return - V_57 ;
if ( V_166 -> V_83 )
return - V_57 ;
V_83 = V_36 -> V_196 ;
F_9 ( & V_83 -> V_19 . V_197 ) ;
V_166 -> V_83 = V_83 ;
F_170 ( & V_166 -> V_198 , & V_83 -> V_19 . V_199 ) ;
F_10 ( & V_83 -> V_19 . V_197 ) ;
V_166 -> V_200 = F_171 ( F_172 ( V_169 ) ) ;
return 0 ;
}
static inline void
F_173 ( struct V_165 * V_201 )
{
struct V_195 * V_83 = V_201 -> V_83 ;
if ( ! V_83 )
return;
F_9 ( & V_83 -> V_19 . V_197 ) ;
F_174 ( & V_201 -> V_198 ) ;
V_201 -> V_83 = NULL ;
F_10 ( & V_83 -> V_19 . V_197 ) ;
F_175 ( V_201 -> V_200 ) ;
V_201 -> V_200 = NULL ;
}
static void F_176 ( struct V_165 * V_201 )
{
F_177 ( V_201 ) ;
V_201 -> V_202 -> V_203 = V_201 -> V_204 ;
F_168 ( & V_201 -> V_179 ) ;
F_173 ( V_201 ) ;
if ( V_201 -> V_205 ) {
if ( V_14 . V_206 )
F_178 ( V_201 -> V_205 ,
V_201 -> V_187 ) ;
}
F_179 ( V_201 -> V_207 ) ;
F_180 ( V_201 ) ;
}
static void
F_181 ( struct V_165 * V_166 )
{
struct V_208 * V_187 = V_166 -> V_187 ;
struct V_165 * V_209 ;
F_182 ( & V_187 -> V_14 -> V_210 . V_33 ) ;
if ( F_149 ( & V_166 -> V_179 ) )
return;
do {
V_209 = F_183 ( & V_187 -> V_199 ,
F_184 ( * V_209 ) , V_179 ) ;
F_176 ( V_209 ) ;
} while ( V_209 != V_166 );
F_19 ( F_20 ( V_187 -> V_2 ) ) ;
}
int
F_185 ( struct V_165 * V_166 )
{
struct V_13 * V_23 = V_166 -> V_14 ;
bool V_159 ;
int V_28 ;
V_159 = V_23 -> V_19 . V_159 ;
F_41 ( ! F_186 ( & V_23 -> V_210 . V_33 ) ) ;
V_28 = F_146 ( V_166 , V_159 , NULL , NULL ) ;
if ( V_28 )
return V_28 ;
if ( ! F_13 ( & V_23 -> V_32 ) )
F_181 ( V_166 ) ;
return 0 ;
}
int
F_59 ( struct V_6 * V_7 ,
bool V_211 )
{
int V_28 , V_56 ;
if ( ! V_7 -> V_212 )
return 0 ;
if ( V_211 ) {
if ( V_7 -> V_213 != NULL ) {
V_28 = F_185 ( V_7 -> V_213 ) ;
if ( V_28 )
return V_28 ;
V_56 = V_7 -> V_213 -> V_187 -> V_214 ;
if ( V_7 -> V_215 [ V_56 ] == V_7 -> V_213 )
F_187 ( V_7 , V_56 ) ;
else
F_188 ( V_7 ) ;
}
} else {
for ( V_56 = 0 ; V_56 < V_216 ; V_56 ++ ) {
if ( V_7 -> V_215 [ V_56 ] == NULL )
continue;
V_28 = F_185 ( V_7 -> V_215 [ V_56 ] ) ;
if ( V_28 )
return V_28 ;
F_187 ( V_7 , V_56 ) ;
}
F_189 ( V_7 -> V_212 ) ;
}
return 0 ;
}
static void
F_190 ( struct V_6 * V_7 ,
struct V_165 * V_166 )
{
int V_217 = V_166 -> V_187 -> V_214 ;
if ( V_7 -> V_215 [ V_217 ] == V_166 )
F_187 ( V_7 , V_217 ) ;
else if ( V_7 -> V_213 == V_166 )
F_188 ( V_7 ) ;
if ( ! F_13 ( & V_166 -> V_14 -> V_32 ) )
F_181 ( V_166 ) ;
}
static T_11 int
F_191 ( struct V_6 * V_7 ,
struct V_170 * V_171 ,
bool V_211 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_165 * V_218 [ V_216 ] ;
int V_28 , V_56 , V_219 = 0 ;
F_41 ( ! F_186 ( & V_2 -> V_33 ) ) ;
F_41 ( ! V_23 -> V_19 . V_159 ) ;
if ( ! V_7 -> V_212 )
return 0 ;
if ( V_211 ) {
struct V_165 * V_166 ;
V_166 = V_7 -> V_213 ;
if ( V_166 == NULL )
return 0 ;
V_218 [ V_219 ++ ] = F_192 ( V_166 ) ;
} else {
for ( V_56 = 0 ; V_56 < V_216 ; V_56 ++ ) {
struct V_165 * V_166 ;
V_166 = V_7 -> V_215 [ V_56 ] ;
if ( V_166 == NULL )
continue;
V_218 [ V_219 ++ ] = F_192 ( V_166 ) ;
}
}
F_24 ( & V_2 -> V_33 ) ;
V_28 = 0 ;
for ( V_56 = 0 ; V_28 == 0 && V_56 < V_219 ; V_56 ++ )
V_28 = F_146 ( V_218 [ V_56 ] , true , NULL , V_171 ) ;
F_22 ( & V_2 -> V_33 ) ;
for ( V_56 = 0 ; V_56 < V_219 ; V_56 ++ ) {
if ( V_28 == 0 )
F_190 ( V_7 , V_218 [ V_56 ] ) ;
F_180 ( V_218 [ V_56 ] ) ;
}
return V_28 ;
}
static struct V_170 * F_193 ( struct V_35 * V_36 )
{
struct V_195 * V_220 = V_36 -> V_196 ;
return & V_220 -> V_171 ;
}
static enum V_221
F_194 ( struct V_6 * V_7 , unsigned V_222 )
{
return V_222 == V_129 && ! V_7 -> V_223 ?
V_146 : V_86 ;
}
int
F_195 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_224 * args = V_34 ;
struct V_6 * V_7 ;
T_6 V_70 = args -> V_70 ;
T_6 V_9 = args -> V_9 ;
int V_28 ;
if ( V_9 & V_225 )
return - V_57 ;
if ( V_70 & V_225 )
return - V_57 ;
if ( V_9 != 0 && V_70 != V_9 )
return - V_57 ;
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
return V_28 ;
V_7 = F_115 ( F_116 ( V_36 , args -> V_91 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_28 = - V_139 ;
goto V_140;
}
V_28 = F_191 ( V_7 ,
F_193 ( V_36 ) ,
! V_9 ) ;
if ( V_28 )
goto V_226;
if ( V_70 & V_129 )
V_28 = F_101 ( V_7 , V_9 != 0 ) ;
else
V_28 = F_42 ( V_7 , V_9 != 0 ) ;
if ( V_9 != 0 )
F_60 ( V_7 , F_194 ( V_7 , V_9 ) ) ;
V_226:
F_53 ( & V_7 -> V_8 ) ;
V_140:
F_24 ( & V_2 -> V_33 ) ;
return V_28 ;
}
int
F_196 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_227 * args = V_34 ;
struct V_6 * V_7 ;
int V_28 = 0 ;
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
return V_28 ;
V_7 = F_115 ( F_116 ( V_36 , args -> V_91 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_28 = - V_139 ;
goto V_140;
}
if ( V_7 -> V_12 )
F_197 ( V_7 ) ;
F_53 ( & V_7 -> V_8 ) ;
V_140:
F_24 ( & V_2 -> V_33 ) ;
return V_28 ;
}
int
F_198 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_228 * args = V_34 ;
struct V_229 * V_7 ;
unsigned long V_109 ;
if ( args -> V_230 & ~ ( V_231 ) )
return - V_57 ;
if ( args -> V_230 & V_231 && ! F_199 ( V_232 ) )
return - V_136 ;
V_7 = F_116 ( V_36 , args -> V_91 ) ;
if ( V_7 == NULL )
return - V_139 ;
if ( ! V_7 -> V_48 ) {
F_72 ( V_7 ) ;
return - V_57 ;
}
V_109 = F_200 ( V_7 -> V_48 , 0 , args -> V_17 ,
V_233 | V_234 , V_235 ,
args -> V_64 ) ;
if ( args -> V_230 & V_231 ) {
struct V_236 * V_19 = V_169 -> V_19 ;
struct V_237 * V_40 ;
if ( F_201 ( & V_19 -> V_238 ) ) {
F_72 ( V_7 ) ;
return - V_239 ;
}
V_40 = F_202 ( V_19 , V_109 ) ;
if ( V_40 )
V_40 -> V_240 =
F_203 ( F_204 ( V_40 -> V_241 ) ) ;
else
V_109 = - V_62 ;
F_205 ( & V_19 -> V_238 ) ;
F_206 ( F_115 ( V_7 ) -> V_223 , true ) ;
}
F_72 ( V_7 ) ;
if ( F_28 ( ( void * ) V_109 ) )
return V_109 ;
args -> V_242 = ( T_5 ) V_109 ;
return 0 ;
}
int F_207 ( struct V_237 * V_40 , struct V_243 * V_244 )
{
struct V_6 * V_7 = F_115 ( V_40 -> V_245 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_37 * V_18 = & V_23 -> V_18 ;
struct V_246 V_247 = V_248 ;
T_12 V_115 ;
unsigned long V_249 ;
int V_28 = 0 ;
bool V_250 = ! ! ( V_244 -> V_230 & V_251 ) ;
F_118 ( V_23 ) ;
V_115 = ( ( unsigned long ) V_244 -> V_252 - V_40 -> V_253 ) >>
V_126 ;
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
goto V_88;
F_208 ( V_7 , V_115 , true , V_250 ) ;
V_28 = F_191 ( V_7 , NULL , ! V_250 ) ;
if ( V_28 )
goto V_140;
if ( V_7 -> V_11 != V_5 && ! F_2 ( V_2 ) ) {
V_28 = - V_79 ;
goto V_140;
}
if ( V_7 -> V_8 . V_17 >= V_18 -> V_20 &&
V_7 -> V_143 == V_144 ) {
static const unsigned int V_254 = 256 ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
V_247 . type = V_255 ;
V_247 . V_256 . V_257 . V_64 = F_209 ( V_115 , V_254 ) ;
V_247 . V_256 . V_257 . V_17 =
F_210 (unsigned int,
chunk_size,
(vma->vm_end - vma->vm_start)/PAGE_SIZE -
view.params.partial.offset) ;
}
V_28 = F_211 ( V_7 , & V_247 , 0 , V_121 ) ;
if ( V_28 )
goto V_140;
V_28 = F_101 ( V_7 , V_250 ) ;
if ( V_28 )
goto V_258;
V_28 = F_212 ( V_7 ) ;
if ( V_28 )
goto V_258;
V_249 = V_18 -> V_259 +
F_213 ( V_7 , & V_247 ) ;
V_249 >>= V_126 ;
if ( F_86 ( V_247 . type == V_255 ) ) {
unsigned long V_8 = V_40 -> V_253 +
( V_247 . V_256 . V_257 . V_64 << V_126 ) ;
unsigned int V_56 ;
for ( V_56 = 0 ; V_56 < V_247 . V_256 . V_257 . V_17 ; V_56 ++ ) {
V_28 = F_214 ( V_40 , V_8 + V_56 * V_58 , V_249 + V_56 ) ;
if ( V_28 )
break;
}
V_7 -> V_260 = true ;
} else {
if ( ! V_7 -> V_260 ) {
unsigned long V_17 = F_210 (unsigned long,
vma->vm_end - vma->vm_start,
obj->base.size) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_17 > > V_126 ; V_56 ++ ) {
V_28 = F_214 ( V_40 ,
( unsigned long ) V_40 -> V_253 + V_56 * V_58 ,
V_249 + V_56 ) ;
if ( V_28 )
break;
}
V_7 -> V_260 = true ;
} else
V_28 = F_214 ( V_40 ,
( unsigned long ) V_244 -> V_252 ,
V_249 + V_115 ) ;
}
V_258:
F_215 ( V_7 , & V_247 ) ;
V_140:
F_24 ( & V_2 -> V_33 ) ;
V_88:
switch ( V_28 ) {
case - V_31 :
if ( ! F_216 ( & V_23 -> V_32 ) ) {
V_28 = V_261 ;
break;
}
case - V_160 :
case 0 :
case - V_189 :
case - V_239 :
case - V_78 :
V_28 = V_262 ;
break;
case - V_62 :
V_28 = V_263 ;
break;
case - V_157 :
case - V_79 :
V_28 = V_261 ;
break;
default:
F_217 ( V_28 , L_2 , V_28 ) ;
V_28 = V_261 ;
break;
}
F_119 ( V_23 ) ;
return V_28 ;
}
void
F_218 ( struct V_6 * V_7 )
{
F_182 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
if ( ! V_7 -> V_260 )
return;
F_219 ( & V_7 -> V_8 . V_264 ,
V_7 -> V_8 . V_2 -> V_265 -> V_266 ) ;
F_105 () ;
V_7 -> V_260 = false ;
}
void
F_220 ( struct V_13 * V_23 )
{
struct V_6 * V_7 ;
F_23 (obj, &dev_priv->mm.bound_list, global_list)
F_218 ( V_7 ) ;
}
T_6
F_221 ( struct V_1 * V_2 , T_6 V_17 , int V_143 )
{
T_6 V_267 ;
if ( F_153 ( V_2 ) -> V_182 >= 4 ||
V_143 == V_144 )
return V_17 ;
if ( F_222 ( V_2 ) )
V_267 = 1024 * 1024 ;
else
V_267 = 512 * 1024 ;
while ( V_267 < V_17 )
V_267 <<= 1 ;
return V_267 ;
}
T_6
F_223 ( struct V_1 * V_2 , T_6 V_17 ,
int V_143 , bool V_268 )
{
if ( F_153 ( V_2 ) -> V_182 >= 4 || ( ! V_268 && F_224 ( V_2 ) ) ||
V_143 == V_144 )
return 4096 ;
return F_221 ( V_2 , V_17 , V_143 ) ;
}
static int F_225 ( struct V_6 * V_7 )
{
struct V_13 * V_23 = F_17 ( V_7 -> V_8 . V_2 ) ;
int V_28 ;
V_23 -> V_19 . V_269 = true ;
V_28 = F_226 ( & V_7 -> V_8 ) ;
if ( V_28 != - V_157 )
goto V_88;
F_227 ( V_23 ,
V_7 -> V_8 . V_17 >> V_126 ,
V_270 |
V_271 |
V_272 ) ;
V_28 = F_226 ( & V_7 -> V_8 ) ;
if ( V_28 != - V_157 )
goto V_88;
F_228 ( V_23 ) ;
V_28 = F_226 ( & V_7 -> V_8 ) ;
V_88:
V_23 -> V_19 . V_269 = false ;
return V_28 ;
}
static void F_229 ( struct V_6 * V_7 )
{
F_230 ( & V_7 -> V_8 ) ;
}
int
F_231 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
T_6 V_91 ,
T_5 * V_64 )
{
struct V_6 * V_7 ;
int V_28 ;
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
return V_28 ;
V_7 = F_115 ( F_116 ( V_36 , V_91 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_28 = - V_139 ;
goto V_140;
}
if ( V_7 -> V_68 != V_74 ) {
F_232 ( L_3 ) ;
V_28 = - V_79 ;
goto V_88;
}
V_28 = F_225 ( V_7 ) ;
if ( V_28 )
goto V_88;
* V_64 = F_233 ( & V_7 -> V_8 . V_264 ) ;
V_88:
F_53 ( & V_7 -> V_8 ) ;
V_140:
F_24 ( & V_2 -> V_33 ) ;
return V_28 ;
}
int
F_234 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_273 * args = V_34 ;
return F_231 ( V_36 , V_2 , args -> V_91 , & args -> V_64 ) ;
}
static void
F_235 ( struct V_6 * V_7 )
{
F_229 ( V_7 ) ;
if ( V_7 -> V_8 . V_48 == NULL )
return;
F_236 ( F_237 ( V_7 -> V_8 . V_48 ) , 0 , ( T_9 ) - 1 ) ;
V_7 -> V_68 = V_69 ;
}
static void
F_238 ( struct V_6 * V_7 )
{
struct V_46 * V_47 ;
switch ( V_7 -> V_68 ) {
case V_71 :
F_235 ( V_7 ) ;
case V_69 :
return;
}
if ( V_7 -> V_8 . V_48 == NULL )
return;
V_47 = V_7 -> V_8 . V_48 -> V_49 ,
F_239 ( V_47 , 0 , ( T_9 ) - 1 ) ;
}
static void
F_240 ( struct V_6 * V_7 )
{
struct V_274 V_274 ;
struct V_59 * V_59 ;
int V_28 ;
F_41 ( V_7 -> V_68 == V_69 ) ;
V_28 = F_42 ( V_7 , true ) ;
if ( F_19 ( V_28 ) ) {
F_128 ( V_7 , true ) ;
V_7 -> V_8 . V_70 = V_7 -> V_8 . V_9 = V_10 ;
}
F_241 ( V_7 ) ;
if ( F_26 ( V_7 ) )
F_242 ( V_7 ) ;
if ( V_7 -> V_68 == V_71 )
V_7 -> V_72 = 0 ;
F_243 (page, sgt_iter, obj->pages) {
if ( V_7 -> V_72 )
F_43 ( V_59 ) ;
if ( V_7 -> V_68 == V_74 )
F_44 ( V_59 ) ;
F_33 ( V_59 ) ;
}
V_7 -> V_72 = 0 ;
F_45 ( V_7 -> V_67 ) ;
F_37 ( V_7 -> V_67 ) ;
}
int
F_52 ( struct V_6 * V_7 )
{
const struct V_275 * V_80 = V_7 -> V_80 ;
if ( V_7 -> V_67 == NULL )
return 0 ;
if ( V_7 -> V_276 )
return - V_78 ;
F_41 ( F_244 ( V_7 ) ) ;
F_174 ( & V_7 -> V_277 ) ;
if ( V_7 -> V_47 ) {
if ( F_245 ( V_7 -> V_47 ) )
F_246 ( V_7 -> V_47 ) ;
else
F_93 ( F_247 ( V_7 -> V_47 ) ) ;
V_7 -> V_47 = NULL ;
}
V_80 -> V_278 ( V_7 ) ;
V_7 -> V_67 = NULL ;
F_238 ( V_7 ) ;
return 0 ;
}
static int
F_248 ( struct V_6 * V_7 )
{
struct V_13 * V_23 = F_17 ( V_7 -> V_8 . V_2 ) ;
int V_279 , V_56 ;
struct V_46 * V_47 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_274 V_274 ;
struct V_59 * V_59 ;
unsigned long V_280 = 0 ;
int V_28 ;
T_13 V_281 ;
F_41 ( V_7 -> V_8 . V_70 & V_225 ) ;
F_41 ( V_7 -> V_8 . V_9 & V_225 ) ;
V_53 = F_35 ( sizeof( * V_53 ) , V_61 ) ;
if ( V_53 == NULL )
return - V_62 ;
V_279 = V_7 -> V_8 . V_17 / V_58 ;
if ( F_36 ( V_53 , V_279 , V_61 ) ) {
F_37 ( V_53 ) ;
return - V_62 ;
}
V_47 = V_7 -> V_8 . V_48 -> V_49 ;
V_281 = F_249 ( V_47 , ~ ( V_282 | V_283 ) ) ;
V_281 |= V_284 | V_285 ;
V_55 = V_53 -> V_63 ;
V_53 -> V_286 = 0 ;
for ( V_56 = 0 ; V_56 < V_279 ; V_56 ++ ) {
V_59 = F_250 ( V_47 , V_56 , V_281 ) ;
if ( F_28 ( V_59 ) ) {
F_227 ( V_23 ,
V_279 ,
V_270 |
V_271 |
V_272 ) ;
V_59 = F_250 ( V_47 , V_56 , V_281 ) ;
}
if ( F_28 ( V_59 ) ) {
F_228 ( V_23 ) ;
V_59 = F_27 ( V_47 , V_56 ) ;
if ( F_28 ( V_59 ) ) {
V_28 = F_29 ( V_59 ) ;
goto V_287;
}
}
#ifdef F_251
if ( F_252 () ) {
V_53 -> V_286 ++ ;
F_253 ( V_55 , V_59 , V_58 , 0 ) ;
V_55 = F_254 ( V_55 ) ;
continue;
}
#endif
if ( ! V_56 || F_255 ( V_59 ) != V_280 + 1 ) {
if ( V_56 )
V_55 = F_254 ( V_55 ) ;
V_53 -> V_286 ++ ;
F_253 ( V_55 , V_59 , V_58 , 0 ) ;
} else {
V_55 -> V_65 += V_58 ;
}
V_280 = F_255 ( V_59 ) ;
F_19 ( ( V_281 & V_288 ) && ( V_280 >= 0x00100000UL ) ) ;
}
#ifdef F_251
if ( ! F_252 () )
#endif
F_256 ( V_55 ) ;
V_7 -> V_67 = V_53 ;
V_28 = F_257 ( V_7 ) ;
if ( V_28 )
goto V_287;
if ( F_26 ( V_7 ) )
F_258 ( V_7 ) ;
if ( V_7 -> V_143 != V_144 &&
V_23 -> V_289 & V_290 )
F_84 ( V_7 ) ;
return 0 ;
V_287:
F_256 ( V_55 ) ;
F_243 (page, sgt_iter, st)
F_33 ( V_59 ) ;
F_45 ( V_53 ) ;
F_37 ( V_53 ) ;
if ( V_28 == - V_157 )
V_28 = - V_62 ;
return V_28 ;
}
int
F_56 ( struct V_6 * V_7 )
{
struct V_13 * V_23 = F_17 ( V_7 -> V_8 . V_2 ) ;
const struct V_275 * V_80 = V_7 -> V_80 ;
int V_28 ;
if ( V_7 -> V_67 )
return 0 ;
if ( V_7 -> V_68 != V_74 ) {
F_232 ( L_4 ) ;
return - V_79 ;
}
F_41 ( V_7 -> V_276 ) ;
V_28 = V_80 -> V_291 ( V_7 ) ;
if ( V_28 )
return V_28 ;
F_170 ( & V_7 -> V_277 , & V_23 -> V_19 . V_292 ) ;
V_7 -> V_293 . V_55 = V_7 -> V_67 -> V_63 ;
V_7 -> V_293 . V_294 = 0 ;
return 0 ;
}
static void * F_259 ( const struct V_6 * V_7 )
{
unsigned long V_295 = V_7 -> V_8 . V_17 >> V_126 ;
struct V_52 * V_296 = V_7 -> V_67 ;
struct V_274 V_274 ;
struct V_59 * V_59 ;
struct V_59 * V_297 [ 32 ] ;
struct V_59 * * V_67 = V_297 ;
unsigned long V_56 = 0 ;
void * V_109 ;
if ( V_295 == 1 )
return F_92 ( F_260 ( V_296 -> V_63 ) ) ;
if ( V_295 > F_261 ( V_297 ) ) {
V_67 = F_262 ( V_295 , sizeof( * V_67 ) , V_298 ) ;
if ( ! V_67 )
return NULL ;
}
F_243 (page, sgt_iter, sgt)
V_67 [ V_56 ++ ] = V_59 ;
F_189 ( V_56 != V_295 ) ;
V_109 = F_263 ( V_67 , V_295 , 0 , V_299 ) ;
if ( V_67 != V_297 )
F_264 ( V_67 ) ;
return V_109 ;
}
void * F_265 ( struct V_6 * V_7 )
{
int V_28 ;
F_182 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
V_28 = F_56 ( V_7 ) ;
if ( V_28 )
return F_266 ( V_28 ) ;
F_84 ( V_7 ) ;
if ( ! V_7 -> V_47 ) {
V_7 -> V_47 = F_259 ( V_7 ) ;
if ( ! V_7 -> V_47 ) {
F_107 ( V_7 ) ;
return F_266 ( - V_62 ) ;
}
}
return V_7 -> V_47 ;
}
void F_267 ( struct V_39 * V_40 ,
struct V_165 * V_166 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_208 * V_187 ;
V_187 = F_268 ( V_166 ) ;
if ( V_7 -> V_212 == 0 )
F_49 ( & V_7 -> V_8 ) ;
V_7 -> V_212 |= F_269 ( V_187 ) ;
F_270 ( & V_7 -> V_300 [ V_187 -> V_214 ] , & V_187 -> V_301 ) ;
F_271 ( & V_7 -> V_215 [ V_187 -> V_214 ] , V_166 ) ;
F_270 ( & V_40 -> V_302 , & V_40 -> V_303 -> V_301 ) ;
}
static void
F_188 ( struct V_6 * V_7 )
{
F_189 ( V_7 -> V_213 == NULL ) ;
F_189 ( ! ( V_7 -> V_212 & F_269 ( V_7 -> V_213 -> V_187 ) ) ) ;
F_271 ( & V_7 -> V_213 , NULL ) ;
F_63 ( V_7 , true , V_304 ) ;
}
static void
F_187 ( struct V_6 * V_7 , int V_217 )
{
struct V_39 * V_40 ;
F_189 ( V_7 -> V_215 [ V_217 ] == NULL ) ;
F_189 ( ! ( V_7 -> V_212 & ( 1 << V_217 ) ) ) ;
F_168 ( & V_7 -> V_300 [ V_217 ] ) ;
F_271 ( & V_7 -> V_215 [ V_217 ] , NULL ) ;
if ( V_7 -> V_213 && V_7 -> V_213 -> V_187 -> V_214 == V_217 )
F_188 ( V_7 ) ;
V_7 -> V_212 &= ~ ( 1 << V_217 ) ;
if ( V_7 -> V_212 )
return;
F_270 ( & V_7 -> V_277 ,
& F_17 ( V_7 -> V_8 . V_2 ) -> V_19 . V_305 ) ;
F_23 (vma, &obj->vma_list, obj_link) {
if ( ! F_149 ( & V_40 -> V_302 ) )
F_270 ( & V_40 -> V_302 , & V_40 -> V_303 -> V_306 ) ;
}
F_271 ( & V_7 -> V_307 , NULL ) ;
F_53 ( & V_7 -> V_8 ) ;
}
static int
F_272 ( struct V_13 * V_23 , T_1 V_186 )
{
struct V_208 * V_187 ;
int V_28 ;
F_273 (engine, dev_priv) {
V_28 = F_274 ( V_187 ) ;
if ( V_28 )
return V_28 ;
}
F_275 ( V_23 ) ;
if ( ! F_276 ( V_186 , V_23 -> V_308 ) ) {
while ( F_277 ( V_23 ) ||
F_278 ( V_23 ) )
F_279 () ;
}
F_273 (engine, dev_priv)
F_280 ( V_187 , V_186 ) ;
return 0 ;
}
int F_281 ( struct V_1 * V_2 , T_1 V_186 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
int V_28 ;
if ( V_186 == 0 )
return - V_57 ;
V_28 = F_272 ( V_23 , V_186 - 1 ) ;
if ( V_28 )
return V_28 ;
V_23 -> V_308 = V_186 ;
V_23 -> V_309 = V_186 - 1 ;
if ( V_23 -> V_309 == 0 )
V_23 -> V_309 -- ;
return 0 ;
}
int
F_282 ( struct V_13 * V_23 , T_1 * V_186 )
{
if ( V_23 -> V_308 == 0 ) {
int V_28 = F_272 ( V_23 , 0 ) ;
if ( V_28 )
return V_28 ;
V_23 -> V_308 = 1 ;
}
* V_186 = V_23 -> V_309 = V_23 -> V_308 ++ ;
return 0 ;
}
static void F_283 ( const struct V_208 * V_187 )
{
struct V_13 * V_23 = V_187 -> V_14 ;
V_23 -> V_310 . V_311 |= F_269 ( V_187 ) ;
if ( V_23 -> V_310 . V_312 )
return;
F_284 ( V_23 ) ;
V_23 -> V_310 . V_312 = true ;
F_285 ( V_23 ) ;
if ( F_286 ( V_23 ) >= 6 )
F_287 ( V_23 ) ;
F_288 ( V_23 -> V_313 ,
& V_23 -> V_310 . V_314 ,
F_289 ( V_30 ) ) ;
}
void F_290 ( struct V_165 * V_201 ,
struct V_6 * V_7 ,
bool V_315 )
{
struct V_208 * V_187 ;
struct V_316 * V_202 ;
T_1 V_317 ;
T_1 V_318 ;
int V_28 ;
if ( F_19 ( V_201 == NULL ) )
return;
V_187 = V_201 -> V_187 ;
V_202 = V_201 -> V_202 ;
V_317 = F_291 ( V_202 ) ;
V_318 = V_201 -> V_319 ;
V_201 -> V_319 = 0 ;
if ( V_315 ) {
if ( V_14 . V_206 )
V_28 = F_292 ( V_201 ) ;
else
V_28 = F_293 ( V_201 ) ;
F_294 ( V_28 , L_5 , V_28 ) ;
}
F_295 ( V_201 ) ;
V_201 -> V_320 = V_317 ;
V_201 -> V_321 = V_7 ;
V_201 -> V_183 = V_322 ;
V_201 -> V_323 = V_187 -> V_192 ;
F_296 ( V_187 -> V_192 , V_201 -> V_186 ) ;
F_170 ( & V_201 -> V_179 , & V_187 -> V_199 ) ;
V_201 -> V_204 = F_291 ( V_202 ) ;
if ( V_14 . V_206 )
V_28 = V_187 -> V_324 ( V_201 ) ;
else {
V_28 = V_187 -> V_325 ( V_201 ) ;
V_201 -> V_326 = F_291 ( V_202 ) ;
}
F_294 ( V_28 , L_6 , V_28 ) ;
V_28 = F_291 ( V_202 ) - V_317 ;
if ( V_28 < 0 )
V_28 += V_202 -> V_17 ;
F_217 ( V_28 > V_318 ,
L_7
L_8 ,
V_318 , V_28 ) ;
F_283 ( V_187 ) ;
}
static bool F_297 ( const struct V_327 * V_207 )
{
unsigned long V_328 ;
if ( V_207 -> V_329 . V_330 )
return true ;
V_328 = F_298 () - V_207 -> V_329 . V_331 ;
if ( V_207 -> V_329 . V_332 &&
V_328 <= V_207 -> V_329 . V_332 ) {
F_232 ( L_9 ) ;
return true ;
}
return false ;
}
static void F_299 ( struct V_327 * V_207 ,
const bool V_333 )
{
struct V_334 * V_335 = & V_207 -> V_329 ;
if ( V_333 ) {
V_335 -> V_330 = F_297 ( V_207 ) ;
V_335 -> V_336 ++ ;
V_335 -> V_331 = F_298 () ;
} else {
V_335 -> V_337 ++ ;
}
}
void F_300 ( struct V_338 * V_339 )
{
struct V_165 * V_166 = F_301 ( V_339 ,
F_184 ( * V_166 ) , V_340 ) ;
F_67 ( V_166 -> V_14 -> V_218 , V_166 ) ;
}
static inline int
F_302 ( struct V_208 * V_187 ,
struct V_327 * V_207 ,
struct V_165 * * V_341 )
{
struct V_13 * V_23 = V_187 -> V_14 ;
unsigned V_158 = F_303 ( & V_23 -> V_32 ) ;
struct V_165 * V_166 ;
int V_28 ;
if ( ! V_341 )
return - V_57 ;
* V_341 = NULL ;
V_28 = F_132 ( V_158 , V_23 -> V_19 . V_159 ) ;
if ( V_28 )
return V_28 ;
V_166 = F_65 ( V_23 -> V_218 , V_61 ) ;
if ( V_166 == NULL )
return - V_62 ;
V_28 = F_282 ( V_187 -> V_14 , & V_166 -> V_186 ) ;
if ( V_28 )
goto V_342;
F_304 ( & V_166 -> V_340 ) ;
V_166 -> V_14 = V_23 ;
V_166 -> V_187 = V_187 ;
V_166 -> V_207 = V_207 ;
F_305 ( V_166 -> V_207 ) ;
V_166 -> V_319 = V_343 ;
if ( V_14 . V_206 )
V_28 = F_306 ( V_166 ) ;
else
V_28 = F_307 ( V_166 ) ;
if ( V_28 )
goto V_344;
* V_341 = V_166 ;
return 0 ;
V_344:
F_179 ( V_207 ) ;
V_342:
F_67 ( V_23 -> V_218 , V_166 ) ;
return V_28 ;
}
struct V_165 *
F_308 ( struct V_208 * V_187 ,
struct V_327 * V_207 )
{
struct V_165 * V_166 ;
int V_342 ;
if ( V_207 == NULL )
V_207 = V_187 -> V_14 -> V_345 ;
V_342 = F_302 ( V_187 , V_207 , & V_166 ) ;
return V_342 ? F_266 ( V_342 ) : V_166 ;
}
struct V_165 *
F_309 ( struct V_208 * V_187 )
{
struct V_165 * V_201 ;
F_23 (request, &engine->request_list, list) {
if ( F_142 ( V_201 ) )
continue;
return V_201 ;
}
return NULL ;
}
static void F_310 ( struct V_208 * V_187 )
{
struct V_165 * V_201 ;
bool V_346 ;
V_201 = F_309 ( V_187 ) ;
if ( V_201 == NULL )
return;
V_346 = V_187 -> V_347 . V_348 >= V_349 ;
F_299 ( V_201 -> V_207 , V_346 ) ;
F_311 (request, &engine->request_list, list)
F_299 ( V_201 -> V_207 , false ) ;
}
static void F_312 ( struct V_208 * V_187 )
{
struct V_316 * V_350 ;
while ( ! F_149 ( & V_187 -> V_301 ) ) {
struct V_6 * V_7 ;
V_7 = F_183 ( & V_187 -> V_301 ,
struct V_6 ,
V_300 [ V_187 -> V_214 ] ) ;
F_187 ( V_7 , V_187 -> V_214 ) ;
}
if ( V_14 . V_206 ) {
F_313 ( & V_187 -> V_351 ) ;
F_314 ( V_187 ) ;
}
while ( ! F_149 ( & V_187 -> V_199 ) ) {
struct V_165 * V_201 ;
V_201 = F_183 ( & V_187 -> V_199 ,
struct V_165 ,
V_179 ) ;
F_176 ( V_201 ) ;
}
F_23 (buffer, &engine->buffers, link) {
V_350 -> V_203 = V_350 -> V_326 ;
F_315 ( V_350 ) ;
}
F_280 ( V_187 , V_187 -> V_192 ) ;
V_187 -> V_14 -> V_310 . V_311 &= ~ F_269 ( V_187 ) ;
}
void F_316 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_208 * V_187 ;
F_273 (engine, dev_priv)
F_310 ( V_187 ) ;
F_273 (engine, dev_priv)
F_312 ( V_187 ) ;
F_317 ( V_23 -> V_313 , & V_23 -> V_310 . V_352 , 0 ) ;
F_318 ( V_2 ) ;
F_319 ( V_2 ) ;
F_19 ( F_20 ( V_2 ) ) ;
}
void
F_320 ( struct V_208 * V_187 )
{
F_19 ( F_20 ( V_187 -> V_2 ) ) ;
while ( ! F_149 ( & V_187 -> V_199 ) ) {
struct V_165 * V_201 ;
V_201 = F_183 ( & V_187 -> V_199 ,
struct V_165 ,
V_179 ) ;
if ( ! F_142 ( V_201 ) )
break;
F_176 ( V_201 ) ;
}
while ( ! F_149 ( & V_187 -> V_301 ) ) {
struct V_6 * V_7 ;
V_7 = F_183 ( & V_187 -> V_301 ,
struct V_6 ,
V_300 [ V_187 -> V_214 ] ) ;
if ( ! F_149 ( & V_7 -> V_215 [ V_187 -> V_214 ] -> V_179 ) )
break;
F_187 ( V_7 , V_187 -> V_214 ) ;
}
F_19 ( F_20 ( V_187 -> V_2 ) ) ;
}
void F_275 ( struct V_13 * V_23 )
{
struct V_208 * V_187 ;
F_182 ( & V_23 -> V_210 . V_33 ) ;
if ( V_23 -> V_310 . V_311 == 0 )
return;
F_189 ( ! V_23 -> V_310 . V_312 ) ;
F_273 (engine, dev_priv) {
F_320 ( V_187 ) ;
if ( F_149 ( & V_187 -> V_199 ) )
V_23 -> V_310 . V_311 &= ~ F_269 ( V_187 ) ;
}
if ( V_23 -> V_310 . V_311 == 0 )
F_288 ( V_23 -> V_313 ,
& V_23 -> V_310 . V_352 ,
F_321 ( 100 ) ) ;
}
static void
F_322 ( struct V_353 * V_354 )
{
struct V_13 * V_23 =
F_301 ( V_354 , F_184 ( * V_23 ) , V_310 . V_314 . V_354 ) ;
struct V_1 * V_2 = & V_23 -> V_210 ;
if ( F_323 ( & V_2 -> V_33 ) ) {
F_275 ( V_23 ) ;
F_24 ( & V_2 -> V_33 ) ;
}
if ( F_324 ( V_23 -> V_310 . V_312 ) )
F_288 ( V_23 -> V_313 ,
& V_23 -> V_310 . V_314 ,
F_289 ( V_30 ) ) ;
}
static void
F_325 ( struct V_353 * V_354 )
{
struct V_13 * V_23 =
F_301 ( V_354 , F_184 ( * V_23 ) , V_310 . V_352 . V_354 ) ;
struct V_1 * V_2 = & V_23 -> V_210 ;
struct V_208 * V_187 ;
unsigned int V_355 ;
bool V_356 ;
if ( ! F_324 ( V_23 -> V_310 . V_312 ) )
return;
if ( F_324 ( V_23 -> V_310 . V_311 ) )
return;
V_356 =
F_326 ( & V_23 -> V_32 . V_357 ) ;
if ( ! F_323 ( & V_2 -> V_33 ) ) {
F_317 ( V_23 -> V_313 ,
& V_23 -> V_310 . V_352 ,
F_321 ( 50 ) ) ;
goto V_358;
}
if ( V_23 -> V_310 . V_311 )
goto V_359;
F_273 (engine, dev_priv)
F_327 ( & V_187 -> V_360 ) ;
F_189 ( ! V_23 -> V_310 . V_312 ) ;
V_23 -> V_310 . V_312 = false ;
V_356 = false ;
V_355 = F_277 ( V_23 ) ;
if ( F_86 ( V_355 ) ) {
F_328 ( L_10 ) ;
V_23 -> V_32 . V_361 |= V_355 ;
}
if ( F_286 ( V_23 ) >= 6 )
F_329 ( V_23 ) ;
F_119 ( V_23 ) ;
V_359:
F_24 ( & V_2 -> V_33 ) ;
V_358:
if ( V_356 ) {
F_189 ( ! V_23 -> V_310 . V_312 ) ;
F_330 ( V_23 ) ;
}
}
static int
F_331 ( struct V_6 * V_7 )
{
int V_56 ;
if ( ! V_7 -> V_212 )
return 0 ;
for ( V_56 = 0 ; V_56 < V_216 ; V_56 ++ ) {
struct V_165 * V_166 ;
V_166 = V_7 -> V_215 [ V_56 ] ;
if ( V_166 == NULL )
continue;
if ( F_142 ( V_166 ) )
F_187 ( V_7 , V_56 ) ;
}
return 0 ;
}
int
F_332 ( struct V_1 * V_2 , void * V_34 , struct V_35 * V_36 )
{
struct V_362 * args = V_34 ;
struct V_6 * V_7 ;
struct V_165 * V_166 [ V_216 ] ;
int V_56 , V_219 = 0 ;
int V_28 ;
if ( args -> V_230 != 0 )
return - V_57 ;
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
return V_28 ;
V_7 = F_115 ( F_116 ( V_36 , args -> V_363 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_24 ( & V_2 -> V_33 ) ;
return - V_139 ;
}
V_28 = F_331 ( V_7 ) ;
if ( V_28 )
goto V_88;
if ( ! V_7 -> V_212 )
goto V_88;
if ( args -> V_364 == 0 ) {
V_28 = - V_181 ;
goto V_88;
}
F_53 ( & V_7 -> V_8 ) ;
for ( V_56 = 0 ; V_56 < V_216 ; V_56 ++ ) {
if ( V_7 -> V_215 [ V_56 ] == NULL )
continue;
V_166 [ V_219 ++ ] = F_192 ( V_7 -> V_215 [ V_56 ] ) ;
}
F_24 ( & V_2 -> V_33 ) ;
for ( V_56 = 0 ; V_56 < V_219 ; V_56 ++ ) {
if ( V_28 == 0 )
V_28 = F_146 ( V_166 [ V_56 ] , true ,
args -> V_364 > 0 ? & args -> V_364 : NULL ,
F_193 ( V_36 ) ) ;
F_180 ( V_166 [ V_56 ] ) ;
}
return V_28 ;
V_88:
F_53 ( & V_7 -> V_8 ) ;
F_24 ( & V_2 -> V_33 ) ;
return V_28 ;
}
static int
F_333 ( struct V_6 * V_7 ,
struct V_208 * V_365 ,
struct V_165 * V_366 ,
struct V_165 * * V_367 )
{
struct V_208 * V_368 ;
int V_28 ;
V_368 = F_268 ( V_366 ) ;
if ( V_365 == V_368 )
return 0 ;
if ( F_142 ( V_366 ) )
return 0 ;
if ( ! F_334 ( F_17 ( V_7 -> V_8 . V_2 ) ) ) {
struct V_13 * V_14 = F_17 ( V_7 -> V_8 . V_2 ) ;
V_28 = F_146 ( V_366 ,
V_14 -> V_19 . V_159 ,
NULL ,
& V_14 -> V_171 . V_369 ) ;
if ( V_28 )
return V_28 ;
F_190 ( V_7 , V_366 ) ;
} else {
int V_370 = F_335 ( V_368 , V_365 ) ;
T_1 V_186 = F_336 ( V_366 ) ;
F_19 ( ! V_367 ) ;
if ( V_186 <= V_368 -> V_371 . V_372 [ V_370 ] )
return 0 ;
if ( * V_367 == NULL ) {
struct V_165 * V_166 ;
V_166 = F_308 ( V_365 , NULL ) ;
if ( F_28 ( V_166 ) )
return F_29 ( V_166 ) ;
* V_367 = V_166 ;
}
F_337 ( * V_367 , V_368 , V_366 ) ;
V_28 = V_365 -> V_371 . V_373 ( * V_367 , V_368 , V_186 ) ;
if ( V_28 )
return V_28 ;
V_368 -> V_371 . V_372 [ V_370 ] =
F_336 ( V_7 -> V_215 [ V_368 -> V_214 ] ) ;
}
return 0 ;
}
int
F_338 ( struct V_6 * V_7 ,
struct V_208 * V_365 ,
struct V_165 * * V_367 )
{
const bool V_211 = V_7 -> V_8 . V_374 == 0 ;
struct V_165 * V_166 [ V_216 ] ;
int V_28 , V_56 , V_219 ;
if ( ! V_7 -> V_212 )
return 0 ;
if ( V_365 == NULL )
return F_59 ( V_7 , V_211 ) ;
V_219 = 0 ;
if ( V_211 ) {
if ( V_7 -> V_213 )
V_166 [ V_219 ++ ] = V_7 -> V_213 ;
} else {
for ( V_56 = 0 ; V_56 < V_216 ; V_56 ++ )
if ( V_7 -> V_215 [ V_56 ] )
V_166 [ V_219 ++ ] = V_7 -> V_215 [ V_56 ] ;
}
for ( V_56 = 0 ; V_56 < V_219 ; V_56 ++ ) {
V_28 = F_333 ( V_7 , V_365 , V_166 [ V_56 ] , V_367 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
static void F_339 ( struct V_6 * V_7 )
{
T_1 V_375 , V_376 ;
F_218 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_70 & V_129 ) == 0 )
return;
V_376 = V_7 -> V_8 . V_70 ;
V_375 = V_7 -> V_8 . V_9 ;
V_7 -> V_8 . V_70 &= ~ V_129 ;
V_7 -> V_8 . V_9 &= ~ V_129 ;
F_340 ( V_7 ,
V_376 ,
V_375 ) ;
}
static void F_341 ( struct V_39 * V_40 )
{
F_189 ( V_40 -> V_42 ) ;
if ( V_40 -> V_377 == NULL )
return;
F_96 ( V_40 -> V_377 ) ;
V_40 -> V_377 = NULL ;
}
static int F_342 ( struct V_39 * V_40 , bool V_176 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_13 * V_23 = F_17 ( V_7 -> V_8 . V_2 ) ;
int V_28 ;
if ( F_149 ( & V_40 -> V_378 ) )
return 0 ;
if ( ! F_343 ( & V_40 -> V_16 ) ) {
F_344 ( V_40 ) ;
return 0 ;
}
if ( V_40 -> V_42 )
return - V_78 ;
F_41 ( V_7 -> V_67 == NULL ) ;
if ( V_176 ) {
V_28 = F_59 ( V_7 , false ) ;
if ( V_28 )
return V_28 ;
}
if ( V_40 -> V_379 && V_40 -> V_380 . type == V_381 ) {
F_339 ( V_7 ) ;
V_28 = F_100 ( V_7 ) ;
if ( V_28 )
return V_28 ;
F_341 ( V_40 ) ;
}
F_345 ( V_40 ) ;
V_40 -> V_303 -> V_382 ( V_40 ) ;
V_40 -> V_383 = 0 ;
F_168 ( & V_40 -> V_302 ) ;
if ( V_40 -> V_379 ) {
if ( V_40 -> V_380 . type == V_381 ) {
V_7 -> V_384 = false ;
} else if ( V_40 -> V_380 . V_67 ) {
F_45 ( V_40 -> V_380 . V_67 ) ;
F_37 ( V_40 -> V_380 . V_67 ) ;
}
V_40 -> V_380 . V_67 = NULL ;
}
F_7 ( & V_40 -> V_16 ) ;
F_344 ( V_40 ) ;
if ( F_149 ( & V_7 -> V_385 ) )
F_270 ( & V_7 -> V_277 , & V_23 -> V_19 . V_292 ) ;
F_107 ( V_7 ) ;
return 0 ;
}
int F_51 ( struct V_39 * V_40 )
{
return F_342 ( V_40 , true ) ;
}
int F_346 ( struct V_39 * V_40 )
{
return F_342 ( V_40 , false ) ;
}
int F_347 ( struct V_13 * V_23 )
{
struct V_208 * V_187 ;
int V_28 ;
F_182 ( & V_23 -> V_210 . V_33 ) ;
F_273 (engine, dev_priv) {
if ( V_187 -> V_386 == NULL )
continue;
V_28 = F_274 ( V_187 ) ;
if ( V_28 )
return V_28 ;
}
F_19 ( F_20 ( V_2 ) ) ;
return 0 ;
}
static bool F_348 ( struct V_39 * V_40 ,
unsigned long V_11 )
{
struct V_15 * V_387 = & V_40 -> V_16 ;
struct V_15 * V_388 ;
if ( V_40 -> V_303 -> V_19 . V_389 == NULL )
return true ;
if ( ! F_343 ( V_387 ) )
return true ;
if ( F_149 ( & V_387 -> V_390 ) )
return true ;
V_388 = F_349 ( V_387 -> V_390 . V_391 , struct V_15 , V_390 ) ;
if ( V_388 -> V_122 && ! V_388 -> V_392 && V_388 -> V_393 != V_11 )
return false ;
V_388 = F_349 ( V_387 -> V_390 . V_75 , struct V_15 , V_390 ) ;
if ( V_388 -> V_122 && ! V_387 -> V_392 && V_388 -> V_393 != V_11 )
return false ;
return true ;
}
static struct V_39 *
F_350 ( struct V_6 * V_7 ,
struct V_394 * V_303 ,
const struct V_246 * V_380 ,
unsigned V_395 ,
T_5 V_230 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_37 * V_18 = & V_23 -> V_18 ;
T_1 V_396 , V_397 ;
T_1 V_398 , V_399 ;
T_14 V_111 , V_112 ;
T_14 V_17 , V_400 ;
struct V_39 * V_40 ;
int V_28 ;
if ( F_351 ( V_303 ) ) {
T_1 V_401 ;
if ( F_19 ( ! V_380 ) )
return F_266 ( - V_57 ) ;
V_401 = F_352 ( V_7 , V_380 ) ;
V_400 = F_221 ( V_2 ,
V_401 ,
V_7 -> V_143 ) ;
V_396 = F_223 ( V_2 ,
V_401 ,
V_7 -> V_143 ,
true ) ;
V_397 = F_223 ( V_2 ,
V_401 ,
V_7 -> V_143 ,
false ) ;
V_17 = V_230 & V_121 ? V_400 : V_401 ;
} else {
V_400 = F_221 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_143 ) ;
V_396 = F_223 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_143 ,
true ) ;
V_397 =
F_223 ( V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_143 ,
false ) ;
V_17 = V_230 & V_121 ? V_400 : V_7 -> V_8 . V_17 ;
}
V_111 = V_230 & V_402 ? V_230 & V_403 : 0 ;
V_112 = V_303 -> V_44 ;
if ( V_230 & V_121 )
V_112 = F_210 ( T_14 , V_112 , V_18 -> V_20 ) ;
if ( V_230 & V_404 )
V_112 = F_210 ( T_14 , V_112 , ( 1ULL << 32 ) - V_58 ) ;
if ( V_395 == 0 )
V_395 = V_230 & V_121 ? V_396 :
V_397 ;
if ( V_230 & V_121 && V_395 & ( V_396 - 1 ) ) {
F_232 ( L_11 ,
V_380 ? V_380 -> type : 0 ,
V_395 ) ;
return F_266 ( - V_57 ) ;
}
if ( V_17 > V_112 ) {
F_232 ( L_12 ,
V_380 ? V_380 -> type : 0 ,
V_17 ,
V_230 & V_121 ? L_13 : L_14 ,
V_112 ) ;
return F_266 ( - V_405 ) ;
}
V_28 = F_56 ( V_7 ) ;
if ( V_28 )
return F_266 ( V_28 ) ;
F_84 ( V_7 ) ;
V_40 = V_380 ? F_353 ( V_7 , V_380 ) :
F_354 ( V_7 , V_303 ) ;
if ( F_28 ( V_40 ) )
goto V_406;
if ( V_230 & V_407 ) {
T_5 V_64 = V_230 & V_403 ;
if ( V_64 & ( V_395 - 1 ) || V_64 + V_17 > V_112 ) {
V_28 = - V_57 ;
goto V_408;
}
V_40 -> V_16 . V_111 = V_64 ;
V_40 -> V_16 . V_17 = V_17 ;
V_40 -> V_16 . V_393 = V_7 -> V_11 ;
V_28 = F_355 ( & V_303 -> V_19 , & V_40 -> V_16 ) ;
if ( V_28 ) {
V_28 = F_356 ( V_40 ) ;
if ( V_28 == 0 )
V_28 = F_355 ( & V_303 -> V_19 , & V_40 -> V_16 ) ;
}
if ( V_28 )
goto V_408;
} else {
if ( V_230 & V_409 ) {
V_398 = V_410 ;
V_399 = V_411 ;
} else {
V_398 = V_21 ;
V_399 = V_22 ;
}
V_412:
V_28 = F_5 ( & V_303 -> V_19 , & V_40 -> V_16 ,
V_17 , V_395 ,
V_7 -> V_11 ,
V_111 , V_112 ,
V_398 ,
V_399 ) ;
if ( V_28 ) {
V_28 = F_357 ( V_2 , V_303 , V_17 , V_395 ,
V_7 -> V_11 ,
V_111 , V_112 ,
V_230 ) ;
if ( V_28 == 0 )
goto V_412;
goto V_408;
}
}
if ( F_19 ( ! F_348 ( V_40 , V_7 -> V_11 ) ) ) {
V_28 = - V_57 ;
goto V_413;
}
F_358 ( V_40 , V_230 ) ;
V_28 = F_359 ( V_40 , V_7 -> V_11 , V_230 ) ;
if ( V_28 )
goto V_413;
F_270 ( & V_7 -> V_277 , & V_23 -> V_19 . V_305 ) ;
F_170 ( & V_40 -> V_302 , & V_303 -> V_306 ) ;
return V_40 ;
V_413:
F_7 ( & V_40 -> V_16 ) ;
V_408:
F_344 ( V_40 ) ;
V_40 = F_266 ( V_28 ) ;
V_406:
F_107 ( V_7 ) ;
return V_40 ;
}
bool
F_128 ( struct V_6 * V_7 ,
bool V_414 )
{
if ( V_7 -> V_67 == NULL )
return false ;
if ( V_7 -> V_415 || V_7 -> V_51 )
return false ;
if ( ! V_414 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_11 ) ) {
V_7 -> V_154 = true ;
return false ;
}
F_360 ( V_7 ) ;
F_361 ( V_7 -> V_67 ) ;
V_7 -> V_154 = false ;
return true ;
}
static void
F_362 ( struct V_6 * V_7 )
{
T_6 V_375 ;
if ( V_7 -> V_8 . V_9 != V_129 )
return;
F_105 () ;
V_375 = V_7 -> V_8 . V_9 ;
V_7 -> V_8 . V_9 = 0 ;
F_63 ( V_7 , false , V_146 ) ;
F_340 ( V_7 ,
V_7 -> V_8 . V_70 ,
V_375 ) ;
}
static void
F_197 ( struct V_6 * V_7 )
{
T_6 V_375 ;
if ( V_7 -> V_8 . V_9 != V_10 )
return;
if ( F_128 ( V_7 , V_7 -> V_12 ) )
F_34 ( F_17 ( V_7 -> V_8 . V_2 ) ) ;
V_375 = V_7 -> V_8 . V_9 ;
V_7 -> V_8 . V_9 = 0 ;
F_63 ( V_7 , false , V_86 ) ;
F_340 ( V_7 ,
V_7 -> V_8 . V_70 ,
V_375 ) ;
}
int
F_101 ( struct V_6 * V_7 , bool V_250 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_37 * V_18 = & V_23 -> V_18 ;
T_6 V_375 , V_376 ;
struct V_39 * V_40 ;
int V_28 ;
if ( V_7 -> V_8 . V_9 == V_129 )
return 0 ;
V_28 = F_59 ( V_7 , ! V_250 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_56 ( V_7 ) ;
if ( V_28 )
return V_28 ;
F_197 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_70 & V_129 ) == 0 )
F_363 () ;
V_375 = V_7 -> V_8 . V_9 ;
V_376 = V_7 -> V_8 . V_70 ;
F_41 ( ( V_7 -> V_8 . V_9 & ~ V_129 ) != 0 ) ;
V_7 -> V_8 . V_70 |= V_129 ;
if ( V_250 ) {
V_7 -> V_8 . V_70 = V_129 ;
V_7 -> V_8 . V_9 = V_129 ;
V_7 -> V_72 = 1 ;
}
F_340 ( V_7 ,
V_376 ,
V_375 ) ;
V_40 = F_364 ( V_7 ) ;
if ( V_40 && F_343 ( & V_40 -> V_16 ) && ! V_7 -> V_212 )
F_270 ( & V_40 -> V_302 ,
& V_18 -> V_8 . V_306 ) ;
return 0 ;
}
int F_365 ( struct V_6 * V_7 ,
enum V_3 V_11 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_39 * V_40 , * V_75 ;
bool V_383 = false ;
int V_28 = 0 ;
if ( V_7 -> V_11 == V_11 )
goto V_88;
F_50 (vma, next, &obj->vma_list, obj_link) {
if ( ! F_343 ( & V_40 -> V_16 ) )
continue;
if ( V_40 -> V_42 ) {
F_232 ( L_15 ) ;
return - V_78 ;
}
if ( ! F_348 ( V_40 , V_11 ) ) {
V_28 = F_51 ( V_40 ) ;
if ( V_28 )
return V_28 ;
} else
V_383 = true ;
}
if ( V_383 ) {
V_28 = F_59 ( V_7 , false ) ;
if ( V_28 )
return V_28 ;
if ( ! F_2 ( V_2 ) && V_11 != V_5 ) {
F_218 ( V_7 ) ;
V_28 = F_100 ( V_7 ) ;
if ( V_28 )
return V_28 ;
} else {
}
F_23 (vma, &obj->vma_list, obj_link) {
if ( ! F_343 ( & V_40 -> V_16 ) )
continue;
V_28 = F_359 ( V_40 , V_11 , V_416 ) ;
if ( V_28 )
return V_28 ;
}
}
F_23 (vma, &obj->vma_list, obj_link)
V_40 -> V_16 . V_393 = V_11 ;
V_7 -> V_11 = V_11 ;
V_88:
if ( V_7 -> V_154 && F_3 ( V_7 ) ) {
if ( F_128 ( V_7 , true ) )
F_34 ( F_17 ( V_7 -> V_8 . V_2 ) ) ;
}
return 0 ;
}
int F_366 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_417 * args = V_34 ;
struct V_6 * V_7 ;
V_7 = F_115 ( F_116 ( V_36 , args -> V_91 ) ) ;
if ( & V_7 -> V_8 == NULL )
return - V_139 ;
switch ( V_7 -> V_11 ) {
case V_418 :
case V_419 :
args -> V_420 = V_421 ;
break;
case V_422 :
args -> V_420 = V_423 ;
break;
default:
args -> V_420 = V_424 ;
break;
}
F_72 ( & V_7 -> V_8 ) ;
return 0 ;
}
int F_367 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_417 * args = V_34 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_28 ;
switch ( args -> V_420 ) {
case V_424 :
V_4 = V_5 ;
break;
case V_421 :
if ( ! F_2 ( V_2 ) && ! F_368 ( V_2 ) )
return - V_136 ;
V_4 = V_418 ;
break;
case V_423 :
V_4 = F_369 ( V_2 ) ? V_422 : V_5 ;
break;
default:
return - V_57 ;
}
F_118 ( V_23 ) ;
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
goto V_425;
V_7 = F_115 ( F_116 ( V_36 , args -> V_91 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_28 = - V_139 ;
goto V_140;
}
V_28 = F_365 ( V_7 , V_4 ) ;
F_53 ( & V_7 -> V_8 ) ;
V_140:
F_24 ( & V_2 -> V_33 ) ;
V_425:
F_119 ( V_23 ) ;
return V_28 ;
}
int
F_370 ( struct V_6 * V_7 ,
T_1 V_395 ,
const struct V_246 * V_247 )
{
T_1 V_376 , V_375 ;
int V_28 ;
V_7 -> V_12 ++ ;
V_28 = F_365 ( V_7 ,
F_369 ( V_7 -> V_8 . V_2 ) ? V_422 : V_5 ) ;
if ( V_28 )
goto V_426;
V_28 = F_211 ( V_7 , V_247 , V_395 ,
V_247 -> type == V_381 ?
V_121 : 0 ) ;
if ( V_28 )
goto V_426;
F_197 ( V_7 ) ;
V_375 = V_7 -> V_8 . V_9 ;
V_376 = V_7 -> V_8 . V_70 ;
V_7 -> V_8 . V_9 = 0 ;
V_7 -> V_8 . V_70 |= V_129 ;
F_340 ( V_7 ,
V_376 ,
V_375 ) ;
return 0 ;
V_426:
V_7 -> V_12 -- ;
return V_28 ;
}
void
F_371 ( struct V_6 * V_7 ,
const struct V_246 * V_247 )
{
if ( F_19 ( V_7 -> V_12 == 0 ) )
return;
F_215 ( V_7 , V_247 ) ;
V_7 -> V_12 -- ;
}
int
F_42 ( struct V_6 * V_7 , bool V_250 )
{
T_6 V_375 , V_376 ;
int V_28 ;
if ( V_7 -> V_8 . V_9 == V_10 )
return 0 ;
V_28 = F_59 ( V_7 , ! V_250 ) ;
if ( V_28 )
return V_28 ;
F_362 ( V_7 ) ;
V_375 = V_7 -> V_8 . V_9 ;
V_376 = V_7 -> V_8 . V_70 ;
if ( ( V_7 -> V_8 . V_70 & V_10 ) == 0 ) {
F_128 ( V_7 , false ) ;
V_7 -> V_8 . V_70 |= V_10 ;
}
F_41 ( ( V_7 -> V_8 . V_9 & ~ V_10 ) != 0 ) ;
if ( V_250 ) {
V_7 -> V_8 . V_70 = V_10 ;
V_7 -> V_8 . V_9 = V_10 ;
}
F_340 ( V_7 ,
V_376 ,
V_375 ) ;
return 0 ;
}
static int
F_372 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_195 * V_83 = V_36 -> V_196 ;
unsigned long V_427 = V_322 - V_428 ;
struct V_165 * V_201 , * V_429 = NULL ;
int V_28 ;
V_28 = F_12 ( & V_23 -> V_32 ) ;
if ( V_28 )
return V_28 ;
if ( F_216 ( & V_23 -> V_32 ) )
return - V_31 ;
F_9 ( & V_83 -> V_19 . V_197 ) ;
F_23 (request, &file_priv->mm.request_list, client_list) {
if ( F_373 ( V_201 -> V_183 , V_427 ) )
break;
if ( ! V_201 -> V_183 )
continue;
V_429 = V_201 ;
}
if ( V_429 )
F_192 ( V_429 ) ;
F_10 ( & V_83 -> V_19 . V_197 ) ;
if ( V_429 == NULL )
return 0 ;
V_28 = F_146 ( V_429 , true , NULL , NULL ) ;
F_180 ( V_429 ) ;
return V_28 ;
}
static bool
F_374 ( struct V_39 * V_40 , T_6 V_395 , T_5 V_230 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
if ( V_395 &&
V_40 -> V_16 . V_111 & ( V_395 - 1 ) )
return true ;
if ( V_230 & V_121 && ! V_7 -> V_384 )
return true ;
if ( V_230 & V_402 &&
V_40 -> V_16 . V_111 < ( V_230 & V_403 ) )
return true ;
if ( V_230 & V_407 &&
V_40 -> V_16 . V_111 != ( V_230 & V_403 ) )
return true ;
return false ;
}
void F_375 ( struct V_39 * V_40 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
bool V_128 , V_430 ;
T_1 V_400 , V_396 ;
V_400 = F_221 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_143 ) ;
V_396 = F_223 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_17 ,
V_7 -> V_143 ,
true ) ;
V_430 = ( V_40 -> V_16 . V_17 == V_400 &&
( V_40 -> V_16 . V_111 & ( V_396 - 1 ) ) == 0 ) ;
V_128 = ( V_40 -> V_16 . V_111 + V_400 <=
F_17 ( V_7 -> V_8 . V_2 ) -> V_18 . V_20 ) ;
V_7 -> V_384 = V_128 && V_430 ;
}
static int
F_376 ( struct V_6 * V_7 ,
struct V_394 * V_303 ,
const struct V_246 * V_380 ,
T_6 V_395 ,
T_5 V_230 )
{
struct V_13 * V_23 = F_17 ( V_7 -> V_8 . V_2 ) ;
struct V_39 * V_40 ;
unsigned V_383 ;
int V_28 ;
if ( F_19 ( V_303 == & V_23 -> V_19 . V_431 -> V_8 ) )
return - V_136 ;
if ( F_19 ( V_230 & ( V_432 | V_121 ) && ! F_351 ( V_303 ) ) )
return - V_57 ;
if ( F_19 ( ( V_230 & ( V_121 | V_432 ) ) == V_121 ) )
return - V_57 ;
if ( F_19 ( F_351 ( V_303 ) != ! ! V_380 ) )
return - V_57 ;
V_40 = V_380 ? F_377 ( V_7 , V_380 ) :
F_378 ( V_7 , V_303 ) ;
if ( V_40 ) {
if ( F_19 ( V_40 -> V_42 == V_433 ) )
return - V_78 ;
if ( F_374 ( V_40 , V_395 , V_230 ) ) {
F_294 ( V_40 -> V_42 ,
L_16
L_17
L_18 ,
V_380 ? L_19 : L_20 ,
F_379 ( V_40 -> V_16 . V_111 ) ,
F_380 ( V_40 -> V_16 . V_111 ) ,
V_395 ,
! ! ( V_230 & V_121 ) ,
V_7 -> V_384 ) ;
V_28 = F_51 ( V_40 ) ;
if ( V_28 )
return V_28 ;
V_40 = NULL ;
}
}
V_383 = V_40 ? V_40 -> V_383 : 0 ;
if ( V_40 == NULL || ! F_343 ( & V_40 -> V_16 ) ) {
V_40 = F_350 ( V_7 , V_303 , V_380 , V_395 ,
V_230 ) ;
if ( F_28 ( V_40 ) )
return F_29 ( V_40 ) ;
} else {
V_28 = F_359 ( V_40 , V_7 -> V_11 , V_230 ) ;
if ( V_28 )
return V_28 ;
}
if ( V_380 && V_380 -> type == V_381 &&
( V_383 ^ V_40 -> V_383 ) & V_434 ) {
F_375 ( V_40 ) ;
F_19 ( V_230 & V_121 && ! V_7 -> V_384 ) ;
}
V_40 -> V_42 ++ ;
return 0 ;
}
int
F_381 ( struct V_6 * V_7 ,
struct V_394 * V_303 ,
T_6 V_395 ,
T_5 V_230 )
{
return F_376 ( V_7 , V_303 ,
F_351 ( V_303 ) ? & V_248 : NULL ,
V_395 , V_230 ) ;
}
int
F_211 ( struct V_6 * V_7 ,
const struct V_246 * V_247 ,
T_6 V_395 ,
T_5 V_230 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_37 * V_18 = & V_23 -> V_18 ;
F_41 ( ! V_247 ) ;
return F_376 ( V_7 , & V_18 -> V_8 , V_247 ,
V_395 , V_230 | V_432 ) ;
}
void
F_215 ( struct V_6 * V_7 ,
const struct V_246 * V_247 )
{
struct V_39 * V_40 = F_377 ( V_7 , V_247 ) ;
F_19 ( V_40 -> V_42 == 0 ) ;
F_19 ( ! F_382 ( V_7 , V_247 ) ) ;
-- V_40 -> V_42 ;
}
int
F_383 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_435 * args = V_34 ;
struct V_6 * V_7 ;
int V_28 ;
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
return V_28 ;
V_7 = F_115 ( F_116 ( V_36 , args -> V_91 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_28 = - V_139 ;
goto V_140;
}
V_28 = F_331 ( V_7 ) ;
if ( V_28 )
goto V_226;
args -> V_436 = 0 ;
if ( V_7 -> V_212 ) {
int V_56 ;
for ( V_56 = 0 ; V_56 < V_216 ; V_56 ++ ) {
struct V_165 * V_166 ;
V_166 = V_7 -> V_215 [ V_56 ] ;
if ( V_166 )
args -> V_436 |= 1 << ( 16 + V_166 -> V_187 -> V_437 ) ;
}
if ( V_7 -> V_213 )
args -> V_436 |= V_7 -> V_213 -> V_187 -> V_437 ;
}
V_226:
F_53 ( & V_7 -> V_8 ) ;
V_140:
F_24 ( & V_2 -> V_33 ) ;
return V_28 ;
}
int
F_384 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_83 )
{
return F_372 ( V_2 , V_83 ) ;
}
int
F_385 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_83 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_438 * args = V_34 ;
struct V_6 * V_7 ;
int V_28 ;
switch ( args -> V_68 ) {
case V_71 :
case V_74 :
break;
default:
return - V_57 ;
}
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
return V_28 ;
V_7 = F_115 ( F_116 ( V_83 , args -> V_91 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_28 = - V_139 ;
goto V_140;
}
if ( F_386 ( V_7 ) ) {
V_28 = - V_57 ;
goto V_88;
}
if ( V_7 -> V_67 &&
V_7 -> V_143 != V_144 &&
V_23 -> V_289 & V_290 ) {
if ( V_7 -> V_68 == V_74 )
F_107 ( V_7 ) ;
if ( args -> V_68 == V_74 )
F_84 ( V_7 ) ;
}
if ( V_7 -> V_68 != V_69 )
V_7 -> V_68 = args -> V_68 ;
if ( V_7 -> V_68 == V_71 && V_7 -> V_67 == NULL )
F_235 ( V_7 ) ;
args -> V_439 = V_7 -> V_68 != V_69 ;
V_88:
F_53 ( & V_7 -> V_8 ) ;
V_140:
F_24 ( & V_2 -> V_33 ) ;
return V_28 ;
}
void F_387 ( struct V_6 * V_7 ,
const struct V_275 * V_80 )
{
int V_56 ;
F_388 ( & V_7 -> V_277 ) ;
for ( V_56 = 0 ; V_56 < V_216 ; V_56 ++ )
F_388 ( & V_7 -> V_300 [ V_56 ] ) ;
F_388 ( & V_7 -> V_440 ) ;
F_388 ( & V_7 -> V_385 ) ;
F_388 ( & V_7 -> V_441 ) ;
V_7 -> V_80 = V_80 ;
V_7 -> V_442 = V_443 ;
V_7 -> V_68 = V_74 ;
F_8 ( F_17 ( V_7 -> V_8 . V_2 ) , V_7 -> V_8 . V_17 ) ;
}
struct V_6 * F_70 ( struct V_1 * V_2 ,
T_2 V_17 )
{
struct V_6 * V_7 ;
struct V_46 * V_47 ;
T_13 V_444 ;
int V_28 ;
V_7 = F_64 ( V_2 ) ;
if ( V_7 == NULL )
return F_266 ( - V_62 ) ;
V_28 = F_389 ( V_2 , & V_7 -> V_8 , V_17 ) ;
if ( V_28 )
goto V_445;
V_444 = V_446 | V_447 ;
if ( F_390 ( V_2 ) || F_391 ( V_2 ) ) {
V_444 &= ~ V_448 ;
V_444 |= V_288 ;
}
V_47 = V_7 -> V_8 . V_48 -> V_49 ;
F_392 ( V_47 , V_444 ) ;
F_387 ( V_7 , & V_449 ) ;
V_7 -> V_8 . V_9 = V_10 ;
V_7 -> V_8 . V_70 = V_10 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_11 = V_418 ;
} else
V_7 -> V_11 = V_5 ;
F_393 ( V_7 ) ;
return V_7 ;
V_445:
F_66 ( V_7 ) ;
return F_266 ( V_28 ) ;
}
static bool F_394 ( struct V_6 * V_7 )
{
if ( V_7 -> V_68 != V_74 )
return false ;
if ( V_7 -> V_8 . V_48 == NULL )
return true ;
return F_395 ( & V_7 -> V_8 . V_48 -> V_450 ) == 1 ;
}
void F_396 ( struct V_229 * V_451 )
{
struct V_6 * V_7 = F_115 ( V_451 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_39 * V_40 , * V_75 ;
F_118 ( V_23 ) ;
F_397 ( V_7 ) ;
F_50 (vma, next, &obj->vma_list, obj_link) {
int V_28 ;
V_40 -> V_42 = 0 ;
V_28 = F_51 ( V_40 ) ;
if ( F_19 ( V_28 == - V_189 ) ) {
bool V_452 ;
V_452 = V_23 -> V_19 . V_159 ;
V_23 -> V_19 . V_159 = false ;
F_19 ( F_51 ( V_40 ) ) ;
V_23 -> V_19 . V_159 = V_452 ;
}
}
if ( V_7 -> V_415 )
F_107 ( V_7 ) ;
F_19 ( V_7 -> V_453 ) ;
if ( V_7 -> V_67 && V_7 -> V_68 == V_74 &&
V_23 -> V_289 & V_290 &&
V_7 -> V_143 != V_144 )
F_107 ( V_7 ) ;
if ( F_19 ( V_7 -> V_276 ) )
V_7 -> V_276 = 0 ;
if ( F_394 ( V_7 ) )
V_7 -> V_68 = V_71 ;
F_52 ( V_7 ) ;
F_229 ( V_7 ) ;
F_41 ( V_7 -> V_67 ) ;
if ( V_7 -> V_8 . V_454 )
F_398 ( & V_7 -> V_8 , NULL ) ;
if ( V_7 -> V_80 -> V_455 )
V_7 -> V_80 -> V_455 ( V_7 ) ;
F_399 ( & V_7 -> V_8 ) ;
F_11 ( V_23 , V_7 -> V_8 . V_17 ) ;
F_37 ( V_7 -> V_456 ) ;
F_66 ( V_7 ) ;
F_119 ( V_23 ) ;
}
struct V_39 * F_378 ( struct V_6 * V_7 ,
struct V_394 * V_303 )
{
struct V_39 * V_40 ;
F_23 (vma, &obj->vma_list, obj_link) {
if ( V_40 -> V_380 . type == V_381 &&
V_40 -> V_303 == V_303 )
return V_40 ;
}
return NULL ;
}
struct V_39 * F_377 ( struct V_6 * V_7 ,
const struct V_246 * V_247 )
{
struct V_39 * V_40 ;
F_189 ( ! V_247 ) ;
F_23 (vma, &obj->vma_list, obj_link)
if ( V_40 -> V_379 && F_400 ( & V_40 -> V_380 , V_247 ) )
return V_40 ;
return NULL ;
}
void F_344 ( struct V_39 * V_40 )
{
F_19 ( V_40 -> V_16 . V_122 ) ;
if ( ! F_149 ( & V_40 -> V_457 ) )
return;
if ( ! V_40 -> V_379 )
F_401 ( F_402 ( V_40 -> V_303 ) ) ;
F_174 ( & V_40 -> V_378 ) ;
F_67 ( F_17 ( V_40 -> V_7 -> V_8 . V_2 ) -> V_458 , V_40 ) ;
}
static void
F_403 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_208 * V_187 ;
F_273 (engine, dev_priv)
V_23 -> V_310 . V_459 ( V_187 ) ;
}
int
F_404 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
int V_28 = 0 ;
F_22 ( & V_2 -> V_33 ) ;
V_28 = F_347 ( V_23 ) ;
if ( V_28 )
goto V_342;
F_275 ( V_23 ) ;
F_403 ( V_2 ) ;
F_405 ( V_23 ) ;
F_24 ( & V_2 -> V_33 ) ;
F_326 ( & V_23 -> V_32 . V_357 ) ;
F_326 ( & V_23 -> V_310 . V_314 ) ;
F_406 ( & V_23 -> V_310 . V_352 ) ;
F_19 ( V_23 -> V_310 . V_312 ) ;
return 0 ;
V_342:
F_24 ( & V_2 -> V_33 ) ;
return V_28 ;
}
void F_407 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
if ( F_153 ( V_2 ) -> V_182 < 5 ||
V_23 -> V_19 . V_460 == V_461 )
return;
F_408 ( V_462 , F_409 ( V_462 ) |
V_463 ) ;
if ( F_410 ( V_2 ) )
return;
F_408 ( V_464 , F_409 ( V_464 ) | V_465 ) ;
if ( F_411 ( V_2 ) )
F_408 ( V_466 , F_412 ( V_467 ) ) ;
else if ( F_413 ( V_2 ) )
F_408 ( V_466 , F_412 ( V_468 ) ) ;
else if ( F_414 ( V_2 ) )
F_408 ( V_469 , F_412 ( V_470 ) ) ;
else
F_415 () ;
}
static void F_416 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
F_408 ( F_417 ( V_8 ) , 0 ) ;
F_408 ( F_418 ( V_8 ) , 0 ) ;
F_408 ( F_419 ( V_8 ) , 0 ) ;
F_408 ( F_420 ( V_8 ) , 0 ) ;
}
static void F_421 ( struct V_1 * V_2 )
{
if ( F_422 ( V_2 ) ) {
F_416 ( V_2 , V_471 ) ;
F_416 ( V_2 , V_472 ) ;
F_416 ( V_2 , V_473 ) ;
F_416 ( V_2 , V_474 ) ;
F_416 ( V_2 , V_475 ) ;
} else if ( F_423 ( V_2 ) ) {
F_416 ( V_2 , V_472 ) ;
F_416 ( V_2 , V_473 ) ;
} else if ( F_222 ( V_2 ) ) {
F_416 ( V_2 , V_471 ) ;
F_416 ( V_2 , V_476 ) ;
}
}
int F_424 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
int V_28 ;
V_28 = F_425 ( V_2 ) ;
if ( V_28 )
return V_28 ;
if ( F_426 ( V_2 ) ) {
V_28 = F_427 ( V_2 ) ;
if ( V_28 )
goto V_477;
}
if ( F_428 ( V_2 ) ) {
V_28 = F_429 ( V_2 ) ;
if ( V_28 )
goto V_478;
}
if ( F_430 ( V_2 ) ) {
V_28 = F_431 ( V_2 ) ;
if ( V_28 )
goto V_479;
}
if ( F_432 ( V_2 ) ) {
V_28 = F_433 ( V_2 ) ;
if ( V_28 )
goto V_480;
}
return 0 ;
V_480:
F_434 ( & V_23 -> V_187 [ V_481 ] ) ;
V_479:
F_434 ( & V_23 -> V_187 [ V_482 ] ) ;
V_478:
F_434 ( & V_23 -> V_187 [ V_483 ] ) ;
V_477:
F_434 ( & V_23 -> V_187 [ V_484 ] ) ;
return V_28 ;
}
int
F_435 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_208 * V_187 ;
int V_28 ;
F_436 ( V_23 , V_485 ) ;
if ( F_437 ( V_2 ) && F_286 ( V_23 ) < 9 )
F_408 ( V_486 , F_409 ( V_486 ) | F_438 ( 0xf ) ) ;
if ( F_439 ( V_2 ) )
F_408 ( V_487 , F_440 ( V_2 ) ?
V_488 : V_489 ) ;
if ( F_441 ( V_2 ) ) {
if ( F_442 ( V_2 ) ) {
T_1 V_490 = F_409 ( V_491 ) ;
V_490 &= ~ ( V_492 | V_493 ) ;
F_408 ( V_491 , V_490 ) ;
} else if ( F_153 ( V_2 ) -> V_182 >= 7 ) {
T_1 V_490 = F_409 ( V_494 ) ;
V_490 &= ~ V_495 ;
F_408 ( V_494 , V_490 ) ;
}
}
F_407 ( V_2 ) ;
F_421 ( V_2 ) ;
F_41 ( ! V_23 -> V_345 ) ;
V_28 = F_443 ( V_2 ) ;
if ( V_28 ) {
F_15 ( L_21 , V_28 ) ;
goto V_88;
}
F_273 (engine, dev_priv) {
V_28 = V_187 -> V_496 ( V_187 ) ;
if ( V_28 )
goto V_88;
}
F_444 ( V_2 ) ;
V_28 = F_445 ( V_2 ) ;
if ( V_28 )
goto V_88;
V_88:
F_446 ( V_23 , V_485 ) ;
return V_28 ;
}
int F_447 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
int V_28 ;
F_22 ( & V_2 -> V_33 ) ;
if ( ! V_14 . V_206 ) {
V_23 -> V_310 . V_497 = V_498 ;
V_23 -> V_310 . V_499 = F_424 ;
V_23 -> V_310 . V_500 = F_434 ;
V_23 -> V_310 . V_459 = V_501 ;
} else {
V_23 -> V_310 . V_497 = V_502 ;
V_23 -> V_310 . V_499 = V_503 ;
V_23 -> V_310 . V_500 = V_504 ;
V_23 -> V_310 . V_459 = V_505 ;
}
F_436 ( V_23 , V_485 ) ;
F_448 ( V_23 ) ;
F_449 ( V_2 ) ;
V_28 = F_450 ( V_2 ) ;
if ( V_28 )
goto V_359;
V_28 = V_23 -> V_310 . V_499 ( V_2 ) ;
if ( V_28 )
goto V_359;
V_28 = F_435 ( V_2 ) ;
if ( V_28 == - V_31 ) {
F_15 ( L_22 ) ;
F_451 ( V_506 , & V_23 -> V_32 . V_158 ) ;
V_28 = 0 ;
}
V_359:
F_446 ( V_23 , V_485 ) ;
F_24 ( & V_2 -> V_33 ) ;
return V_28 ;
}
void
F_452 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_208 * V_187 ;
F_273 (engine, dev_priv)
V_23 -> V_310 . V_500 ( V_187 ) ;
}
static void
F_453 ( struct V_208 * V_187 )
{
F_388 ( & V_187 -> V_301 ) ;
F_388 ( & V_187 -> V_199 ) ;
}
void
F_454 ( struct V_13 * V_23 )
{
struct V_1 * V_2 = & V_23 -> V_210 ;
if ( F_153 ( V_23 ) -> V_182 >= 7 && ! F_455 ( V_23 ) &&
! F_456 ( V_23 ) )
V_23 -> V_507 = 32 ;
else if ( F_153 ( V_23 ) -> V_182 >= 4 || F_457 ( V_23 ) ||
F_458 ( V_23 ) || F_224 ( V_23 ) )
V_23 -> V_507 = 16 ;
else
V_23 -> V_507 = 8 ;
if ( F_459 ( V_23 ) )
V_23 -> V_507 =
F_409 ( F_460 ( V_508 . V_509 ) ) ;
F_319 ( V_2 ) ;
F_461 ( V_2 ) ;
}
void
F_462 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
int V_56 ;
V_23 -> V_89 =
F_463 ( L_23 ,
sizeof( struct V_6 ) , 0 ,
V_510 ,
NULL ) ;
V_23 -> V_458 =
F_463 ( L_24 ,
sizeof( struct V_39 ) , 0 ,
V_510 ,
NULL ) ;
V_23 -> V_218 =
F_463 ( L_25 ,
sizeof( struct V_165 ) , 0 ,
V_510 ,
NULL ) ;
F_388 ( & V_23 -> V_511 ) ;
F_388 ( & V_23 -> V_512 ) ;
F_388 ( & V_23 -> V_19 . V_292 ) ;
F_388 ( & V_23 -> V_19 . V_305 ) ;
F_388 ( & V_23 -> V_19 . V_513 ) ;
for ( V_56 = 0 ; V_56 < V_216 ; V_56 ++ )
F_453 ( & V_23 -> V_187 [ V_56 ] ) ;
for ( V_56 = 0 ; V_56 < V_514 ; V_56 ++ )
F_388 ( & V_23 -> V_515 [ V_56 ] . V_516 ) ;
F_464 ( & V_23 -> V_310 . V_314 ,
F_322 ) ;
F_464 ( & V_23 -> V_310 . V_352 ,
F_325 ) ;
F_465 ( & V_23 -> V_32 . V_185 ) ;
F_465 ( & V_23 -> V_32 . V_29 ) ;
V_23 -> V_517 = V_518 ;
F_388 ( & V_23 -> V_19 . V_513 ) ;
F_465 ( & V_23 -> V_519 ) ;
V_23 -> V_19 . V_159 = true ;
F_466 ( & V_23 -> V_520 . V_197 ) ;
}
void F_467 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
F_468 ( V_23 -> V_218 ) ;
F_468 ( V_23 -> V_458 ) ;
F_468 ( V_23 -> V_89 ) ;
}
int F_469 ( struct V_13 * V_23 )
{
struct V_6 * V_7 ;
F_23 (obj, &dev_priv->mm.unbound_list, global_list) {
V_7 -> V_8 . V_70 = V_10 ;
V_7 -> V_8 . V_9 = V_10 ;
}
F_23 (obj, &dev_priv->mm.bound_list, global_list) {
V_7 -> V_8 . V_70 = V_10 ;
V_7 -> V_8 . V_9 = V_10 ;
}
return 0 ;
}
void F_470 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_195 * V_83 = V_36 -> V_196 ;
F_9 ( & V_83 -> V_19 . V_197 ) ;
while ( ! F_149 ( & V_83 -> V_19 . V_199 ) ) {
struct V_165 * V_201 ;
V_201 = F_183 ( & V_83 -> V_19 . V_199 ,
struct V_165 ,
V_198 ) ;
F_174 ( & V_201 -> V_198 ) ;
V_201 -> V_83 = NULL ;
}
F_10 ( & V_83 -> V_19 . V_197 ) ;
if ( ! F_149 ( & V_83 -> V_171 . V_194 ) ) {
F_9 ( & F_17 ( V_2 ) -> V_171 . V_193 ) ;
F_174 ( & V_83 -> V_171 . V_194 ) ;
F_10 ( & F_17 ( V_2 ) -> V_171 . V_193 ) ;
}
}
int F_471 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_195 * V_83 ;
int V_28 ;
F_328 ( L_26 ) ;
V_83 = F_472 ( sizeof( * V_83 ) , V_61 ) ;
if ( ! V_83 )
return - V_62 ;
V_36 -> V_196 = V_83 ;
V_83 -> V_23 = F_17 ( V_2 ) ;
V_83 -> V_36 = V_36 ;
F_388 ( & V_83 -> V_171 . V_194 ) ;
F_473 ( & V_83 -> V_19 . V_197 ) ;
F_388 ( & V_83 -> V_19 . V_199 ) ;
V_83 -> V_521 = - 1 ;
V_28 = F_474 ( V_2 , V_36 ) ;
if ( V_28 )
F_37 ( V_83 ) ;
return V_28 ;
}
void F_475 ( struct V_6 * V_522 ,
struct V_6 * V_523 ,
unsigned V_453 )
{
if ( V_522 ) {
F_19 ( ! F_186 ( & V_522 -> V_8 . V_2 -> V_33 ) ) ;
F_19 ( ! ( V_522 -> V_453 & V_453 ) ) ;
V_522 -> V_453 &= ~ V_453 ;
}
if ( V_523 ) {
F_19 ( ! F_186 ( & V_523 -> V_8 . V_2 -> V_33 ) ) ;
F_19 ( V_523 -> V_453 & V_453 ) ;
V_523 -> V_453 |= V_453 ;
}
}
T_14 F_476 ( struct V_6 * V_524 ,
struct V_394 * V_303 )
{
struct V_13 * V_23 = F_17 ( V_524 -> V_8 . V_2 ) ;
struct V_39 * V_40 ;
F_19 ( V_303 == & V_23 -> V_19 . V_431 -> V_8 ) ;
F_23 (vma, &o->vma_list, obj_link) {
if ( V_40 -> V_379 &&
V_40 -> V_380 . type != V_381 )
continue;
if ( V_40 -> V_303 == V_303 )
return V_40 -> V_16 . V_111 ;
}
F_294 ( 1 , L_27 ,
F_351 ( V_303 ) ? L_28 : L_20 ) ;
return - 1 ;
}
T_14 F_213 ( struct V_6 * V_524 ,
const struct V_246 * V_247 )
{
struct V_39 * V_40 ;
F_23 (vma, &o->vma_list, obj_link)
if ( V_40 -> V_379 && F_400 ( & V_40 -> V_380 , V_247 ) )
return V_40 -> V_16 . V_111 ;
F_294 ( 1 , L_29 , V_247 -> type ) ;
return - 1 ;
}
bool F_477 ( struct V_6 * V_524 ,
struct V_394 * V_303 )
{
struct V_39 * V_40 ;
F_23 (vma, &o->vma_list, obj_link) {
if ( V_40 -> V_379 &&
V_40 -> V_380 . type != V_381 )
continue;
if ( V_40 -> V_303 == V_303 && F_343 ( & V_40 -> V_16 ) )
return true ;
}
return false ;
}
bool F_382 ( struct V_6 * V_524 ,
const struct V_246 * V_247 )
{
struct V_39 * V_40 ;
F_23 (vma, &o->vma_list, obj_link)
if ( V_40 -> V_379 &&
F_400 ( & V_40 -> V_380 , V_247 ) &&
F_343 ( & V_40 -> V_16 ) )
return true ;
return false ;
}
bool F_244 ( struct V_6 * V_524 )
{
struct V_39 * V_40 ;
F_23 (vma, &o->vma_list, obj_link)
if ( F_343 ( & V_40 -> V_16 ) )
return true ;
return false ;
}
unsigned long F_478 ( struct V_6 * V_524 )
{
struct V_39 * V_40 ;
F_189 ( F_149 ( & V_524 -> V_385 ) ) ;
F_23 (vma, &o->vma_list, obj_link) {
if ( V_40 -> V_379 &&
V_40 -> V_380 . type == V_381 )
return V_40 -> V_16 . V_17 ;
}
return 0 ;
}
bool F_386 ( struct V_6 * V_7 )
{
struct V_39 * V_40 ;
F_23 (vma, &obj->vma_list, obj_link)
if ( V_40 -> V_42 > 0 )
return true ;
return false ;
}
struct V_59 *
F_479 ( struct V_6 * V_7 , int V_219 )
{
struct V_59 * V_59 ;
if ( F_19 ( ! F_83 ( V_7 ) ) )
return NULL ;
V_59 = F_480 ( V_7 , V_219 ) ;
F_43 ( V_59 ) ;
return V_59 ;
}
struct V_6 *
F_481 ( struct V_1 * V_2 ,
const void * V_34 , T_2 V_17 )
{
struct V_6 * V_7 ;
struct V_52 * V_55 ;
T_2 V_525 ;
int V_28 ;
V_7 = F_70 ( V_2 , F_90 ( V_17 , V_58 ) ) ;
if ( F_28 ( V_7 ) )
return V_7 ;
V_28 = F_42 ( V_7 , true ) ;
if ( V_28 )
goto V_445;
V_28 = F_56 ( V_7 ) ;
if ( V_28 )
goto V_445;
F_84 ( V_7 ) ;
V_55 = V_7 -> V_67 ;
V_525 = F_482 ( V_55 -> V_63 , V_55 -> V_286 , ( void * ) V_34 , V_17 ) ;
V_7 -> V_72 = 1 ;
F_107 ( V_7 ) ;
if ( F_19 ( V_525 != V_17 ) ) {
F_15 ( L_30 , V_525 , V_17 ) ;
V_28 = - V_79 ;
goto V_445;
}
return V_7 ;
V_445:
F_53 ( & V_7 -> V_8 ) ;
return F_266 ( V_28 ) ;
}

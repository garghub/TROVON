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
static void F_4 ( struct V_11 * V_12 ,
T_1 V_13 )
{
F_5 ( & V_12 -> V_14 . V_15 ) ;
V_12 -> V_14 . V_16 ++ ;
V_12 -> V_14 . V_17 += V_13 ;
F_6 ( & V_12 -> V_14 . V_15 ) ;
}
static void F_7 ( struct V_11 * V_12 ,
T_1 V_13 )
{
F_5 ( & V_12 -> V_14 . V_15 ) ;
V_12 -> V_14 . V_16 -- ;
V_12 -> V_14 . V_17 -= V_13 ;
F_6 ( & V_12 -> V_14 . V_15 ) ;
}
static int
F_8 ( struct V_18 * error )
{
int V_19 ;
if ( ! F_9 ( error ) )
return 0 ;
V_19 = F_10 ( error -> V_20 ,
! F_9 ( error ) ,
10 * V_21 ) ;
if ( V_19 == 0 ) {
F_11 ( L_1 ) ;
return - V_22 ;
} else if ( V_19 < 0 ) {
return V_19 ;
} else {
return 0 ;
}
}
int F_12 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 ;
V_19 = F_8 ( & V_12 -> V_24 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_13 ( & V_2 -> V_25 ) ;
if ( V_19 )
return V_19 ;
F_14 ( F_15 ( V_2 ) ) ;
return 0 ;
}
int
F_16 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_11 * V_12 = F_17 ( V_2 ) ;
struct V_29 * V_30 = & V_12 -> V_30 ;
struct V_31 * args = V_26 ;
struct V_32 * V_33 ;
T_1 V_34 ;
V_34 = 0 ;
F_18 ( & V_2 -> V_25 ) ;
F_19 (vma, &ggtt->base.active_list, vm_link)
if ( V_33 -> V_35 )
V_34 += V_33 -> V_36 . V_13 ;
F_19 (vma, &ggtt->base.inactive_list, vm_link)
if ( V_33 -> V_35 )
V_34 += V_33 -> V_36 . V_13 ;
F_20 ( & V_2 -> V_25 ) ;
args -> V_37 = V_30 -> V_8 . V_38 ;
args -> V_39 = args -> V_37 - V_34 ;
return 0 ;
}
static int
F_21 ( struct V_6 * V_7 )
{
struct V_40 * V_41 = F_22 ( V_7 -> V_8 . V_42 ) -> V_43 ;
char * V_44 = V_7 -> V_45 -> V_44 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_50 ;
if ( F_14 ( F_23 ( V_7 ) ) )
return - V_51 ;
for ( V_50 = 0 ; V_50 < V_7 -> V_8 . V_13 / V_52 ; V_50 ++ ) {
struct V_53 * V_53 ;
char * V_54 ;
V_53 = F_24 ( V_41 , V_50 ) ;
if ( F_25 ( V_53 ) )
return F_26 ( V_53 ) ;
V_54 = F_27 ( V_53 ) ;
memcpy ( V_44 , V_54 , V_52 ) ;
F_28 ( V_44 , V_52 ) ;
F_29 ( V_54 ) ;
F_30 ( V_53 ) ;
V_44 += V_52 ;
}
F_31 ( V_7 -> V_8 . V_2 ) ;
V_47 = F_32 ( sizeof( * V_47 ) , V_55 ) ;
if ( V_47 == NULL )
return - V_56 ;
if ( F_33 ( V_47 , 1 , V_55 ) ) {
F_34 ( V_47 ) ;
return - V_56 ;
}
V_49 = V_47 -> V_57 ;
V_49 -> V_58 = 0 ;
V_49 -> V_59 = V_7 -> V_8 . V_13 ;
F_35 ( V_49 ) = V_7 -> V_45 -> V_60 ;
F_36 ( V_49 ) = V_7 -> V_8 . V_13 ;
V_7 -> V_61 = V_47 ;
return 0 ;
}
static void
F_37 ( struct V_6 * V_7 )
{
int V_19 ;
F_38 ( V_7 -> V_62 == V_63 ) ;
V_19 = F_39 ( V_7 , true ) ;
if ( F_14 ( V_19 ) ) {
V_7 -> V_8 . V_64 = V_7 -> V_8 . V_65 = V_66 ;
}
if ( V_7 -> V_62 == V_67 )
V_7 -> V_68 = 0 ;
if ( V_7 -> V_68 ) {
struct V_40 * V_41 = F_22 ( V_7 -> V_8 . V_42 ) -> V_43 ;
char * V_44 = V_7 -> V_45 -> V_44 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_7 -> V_8 . V_13 / V_52 ; V_50 ++ ) {
struct V_53 * V_53 ;
char * V_69 ;
V_53 = F_24 ( V_41 , V_50 ) ;
if ( F_25 ( V_53 ) )
continue;
V_69 = F_27 ( V_53 ) ;
F_28 ( V_44 , V_52 ) ;
memcpy ( V_69 , V_44 , V_52 ) ;
F_29 ( V_69 ) ;
F_40 ( V_53 ) ;
if ( V_7 -> V_62 == V_70 )
F_41 ( V_53 ) ;
F_30 ( V_53 ) ;
V_44 += V_52 ;
}
V_7 -> V_68 = 0 ;
}
F_42 ( V_7 -> V_61 ) ;
F_34 ( V_7 -> V_61 ) ;
}
static void
F_43 ( struct V_6 * V_7 )
{
F_44 ( V_7 -> V_8 . V_2 , V_7 -> V_45 ) ;
}
static int
F_45 ( struct V_6 * V_7 )
{
struct V_32 * V_33 , * V_71 ;
int V_19 ;
F_46 ( & V_7 -> V_8 ) ;
F_47 (vma, next, &obj->vma_list, obj_link)
if ( F_48 ( V_33 ) )
break;
V_19 = F_49 ( V_7 ) ;
F_50 ( & V_7 -> V_8 ) ;
return V_19 ;
}
int
F_51 ( struct V_6 * V_7 ,
int V_72 )
{
T_2 * V_73 ;
int V_19 ;
if ( V_7 -> V_45 ) {
if ( ( unsigned long ) V_7 -> V_45 -> V_44 & ( V_72 - 1 ) )
return - V_74 ;
return 0 ;
}
if ( V_7 -> V_62 != V_70 )
return - V_75 ;
if ( V_7 -> V_8 . V_42 == NULL )
return - V_51 ;
V_19 = F_45 ( V_7 ) ;
if ( V_19 )
return V_19 ;
V_73 = F_52 ( V_7 -> V_8 . V_2 , V_7 -> V_8 . V_13 , V_72 ) ;
if ( ! V_73 )
return - V_56 ;
V_7 -> V_45 = V_73 ;
V_7 -> V_76 = & V_77 ;
return F_53 ( V_7 ) ;
}
static int
F_54 ( struct V_6 * V_7 ,
struct V_78 * args ,
struct V_27 * V_79 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
void * V_44 = V_7 -> V_45 -> V_44 + args -> V_58 ;
char T_3 * V_80 = F_55 ( args -> V_81 ) ;
int V_19 = 0 ;
V_19 = F_56 ( V_7 , false ) ;
if ( V_19 )
return V_19 ;
F_57 ( V_7 , V_82 ) ;
if ( F_58 ( V_44 , V_80 , args -> V_13 ) ) {
unsigned long V_83 ;
F_20 ( & V_2 -> V_25 ) ;
V_83 = F_59 ( V_44 , V_80 , args -> V_13 ) ;
F_18 ( & V_2 -> V_25 ) ;
if ( V_83 ) {
V_19 = - V_75 ;
goto V_84;
}
}
F_28 ( V_44 , args -> V_13 ) ;
F_31 ( V_2 ) ;
V_84:
F_60 ( V_7 , false , V_82 ) ;
return V_19 ;
}
void * F_61 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
return F_62 ( V_12 -> V_85 , V_55 ) ;
}
void F_63 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
F_64 ( V_12 -> V_85 , V_7 ) ;
}
static int
F_65 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
T_4 V_13 ,
T_5 * V_86 )
{
struct V_6 * V_7 ;
int V_19 ;
T_6 V_87 ;
V_13 = F_66 ( V_13 , V_52 ) ;
if ( V_13 == 0 )
return - V_51 ;
V_7 = F_67 ( V_2 , V_13 ) ;
if ( V_7 == NULL )
return - V_56 ;
V_19 = F_68 ( V_28 , & V_7 -> V_8 , & V_87 ) ;
F_69 ( & V_7 -> V_8 ) ;
if ( V_19 )
return V_19 ;
* V_86 = V_87 ;
return 0 ;
}
int
F_70 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_88 * args )
{
args -> V_89 = F_71 ( args -> V_90 * F_72 ( args -> V_91 , 8 ) , 64 ) ;
args -> V_13 = args -> V_89 * args -> V_92 ;
return F_65 ( V_28 , V_2 ,
args -> V_13 , & args -> V_87 ) ;
}
int
F_73 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_93 * args = V_26 ;
return F_65 ( V_28 , V_2 ,
args -> V_13 , & args -> V_87 ) ;
}
static inline int
F_74 ( char T_3 * V_94 ,
const char * V_95 , int V_96 ,
int V_59 )
{
int V_19 , V_97 = 0 ;
while ( V_59 > 0 ) {
int V_98 = F_71 ( V_96 + 1 , 64 ) ;
int V_99 = F_75 ( V_98 - V_96 , V_59 ) ;
int V_100 = V_96 ^ 64 ;
V_19 = F_76 ( V_94 + V_97 ,
V_95 + V_100 ,
V_99 ) ;
if ( V_19 )
return V_19 + V_59 ;
V_97 += V_99 ;
V_96 += V_99 ;
V_59 -= V_99 ;
}
return 0 ;
}
static inline int
F_77 ( char * V_95 , int V_96 ,
const char T_3 * V_94 ,
int V_59 )
{
int V_19 , V_97 = 0 ;
while ( V_59 > 0 ) {
int V_98 = F_71 ( V_96 + 1 , 64 ) ;
int V_99 = F_75 ( V_98 - V_96 , V_59 ) ;
int V_100 = V_96 ^ 64 ;
V_19 = F_78 ( V_95 + V_100 ,
V_94 + V_97 ,
V_99 ) ;
if ( V_19 )
return V_19 + V_59 ;
V_97 += V_99 ;
V_96 += V_99 ;
V_59 -= V_99 ;
}
return 0 ;
}
int F_79 ( struct V_6 * V_7 ,
int * V_101 )
{
int V_19 ;
* V_101 = 0 ;
if ( F_14 ( ( V_7 -> V_76 -> V_102 & V_103 ) == 0 ) )
return - V_51 ;
if ( ! ( V_7 -> V_8 . V_64 & V_66 ) ) {
* V_101 = ! F_1 ( V_7 -> V_8 . V_2 ,
V_7 -> V_9 ) ;
V_19 = F_56 ( V_7 , true ) ;
if ( V_19 )
return V_19 ;
}
V_19 = F_53 ( V_7 ) ;
if ( V_19 )
return V_19 ;
F_80 ( V_7 ) ;
return V_19 ;
}
static int
F_81 ( struct V_53 * V_53 , int V_104 , int V_105 ,
char T_3 * V_80 ,
bool V_106 , bool V_101 )
{
char * V_44 ;
int V_19 ;
if ( F_82 ( V_106 ) )
return - V_51 ;
V_44 = F_27 ( V_53 ) ;
if ( V_101 )
F_28 ( V_44 + V_104 ,
V_105 ) ;
V_19 = F_83 ( V_80 ,
V_44 + V_104 ,
V_105 ) ;
F_29 ( V_44 ) ;
return V_19 ? - V_75 : 0 ;
}
static void
F_84 ( char * V_107 , unsigned long V_59 ,
bool V_108 )
{
if ( F_82 ( V_108 ) ) {
unsigned long V_109 = ( unsigned long ) V_107 ;
unsigned long V_110 = ( unsigned long ) V_107 + V_59 ;
V_109 = F_85 ( V_109 , 128 ) ;
V_110 = F_86 ( V_110 , 128 ) ;
F_28 ( ( void * ) V_109 , V_110 - V_109 ) ;
} else {
F_28 ( V_107 , V_59 ) ;
}
}
static int
F_87 ( struct V_53 * V_53 , int V_104 , int V_105 ,
char T_3 * V_80 ,
bool V_106 , bool V_101 )
{
char * V_44 ;
int V_19 ;
V_44 = F_88 ( V_53 ) ;
if ( V_101 )
F_84 ( V_44 + V_104 ,
V_105 ,
V_106 ) ;
if ( V_106 )
V_19 = F_74 ( V_80 ,
V_44 , V_104 ,
V_105 ) ;
else
V_19 = F_76 ( V_80 ,
V_44 + V_104 ,
V_105 ) ;
F_89 ( V_53 ) ;
return V_19 ? - V_75 : 0 ;
}
static int
F_90 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_111 * args ,
struct V_27 * V_28 )
{
char T_3 * V_80 ;
T_7 V_112 ;
T_8 V_58 ;
int V_104 , V_105 , V_19 = 0 ;
int V_113 , V_106 ;
int V_114 = 0 ;
int V_101 = 0 ;
struct V_115 V_116 ;
V_80 = F_55 ( args -> V_81 ) ;
V_112 = args -> V_13 ;
V_113 = F_23 ( V_7 ) ;
V_19 = F_79 ( V_7 , & V_101 ) ;
if ( V_19 )
return V_19 ;
V_58 = args -> V_58 ;
F_91 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_53 * V_53 = F_92 ( & V_116 ) ;
if ( V_112 <= 0 )
break;
V_104 = F_93 ( V_58 ) ;
V_105 = V_112 ;
if ( ( V_104 + V_105 ) > V_52 )
V_105 = V_52 - V_104 ;
V_106 = V_113 &&
( F_94 ( V_53 ) & ( 1 << 17 ) ) != 0 ;
V_19 = F_81 ( V_53 , V_104 , V_105 ,
V_80 , V_106 ,
V_101 ) ;
if ( V_19 == 0 )
goto V_117;
F_20 ( & V_2 -> V_25 ) ;
if ( F_95 ( ! V_118 . V_119 ) && ! V_114 ) {
V_19 = F_96 ( V_80 , V_112 ) ;
( void ) V_19 ;
V_114 = 1 ;
}
V_19 = F_87 ( V_53 , V_104 , V_105 ,
V_80 , V_106 ,
V_101 ) ;
F_18 ( & V_2 -> V_25 ) ;
if ( V_19 )
goto V_84;
V_117:
V_112 -= V_105 ;
V_80 += V_105 ;
V_58 += V_105 ;
}
V_84:
F_97 ( V_7 ) ;
return V_19 ;
}
int
F_98 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_111 * args = V_26 ;
struct V_6 * V_7 ;
int V_19 = 0 ;
if ( args -> V_13 == 0 )
return 0 ;
if ( ! F_99 ( V_120 ,
F_55 ( args -> V_81 ) ,
args -> V_13 ) )
return - V_75 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_100 ( F_101 ( V_28 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_121 ;
goto V_122;
}
if ( args -> V_58 > V_7 -> V_8 . V_13 ||
args -> V_13 > V_7 -> V_8 . V_13 - args -> V_58 ) {
V_19 = - V_51 ;
goto V_84;
}
if ( ! V_7 -> V_8 . V_42 ) {
V_19 = - V_51 ;
goto V_84;
}
F_102 ( V_7 , args -> V_58 , args -> V_13 ) ;
V_19 = F_90 ( V_2 , V_7 , args , V_28 ) ;
V_84:
F_50 ( & V_7 -> V_8 ) ;
V_122:
F_20 ( & V_2 -> V_25 ) ;
return V_19 ;
}
static inline int
F_103 ( struct V_123 * V_41 ,
T_8 V_124 , int V_125 ,
char T_3 * V_80 ,
int V_59 )
{
void T_9 * V_126 ;
void * V_44 ;
unsigned long V_83 ;
V_126 = F_104 ( V_41 , V_124 ) ;
V_44 = ( void V_127 * ) V_126 + V_125 ;
V_83 = F_58 ( V_44 ,
V_80 , V_59 ) ;
F_105 ( V_126 ) ;
return V_83 ;
}
static int
F_106 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_78 * args ,
struct V_27 * V_28 )
{
struct V_11 * V_12 = F_17 ( V_2 ) ;
struct V_29 * V_30 = & V_12 -> V_30 ;
T_7 V_112 ;
T_8 V_58 , V_124 ;
char T_3 * V_80 ;
int V_125 , V_105 , V_19 ;
V_19 = F_107 ( V_7 , 0 , V_128 | V_129 ) ;
if ( V_19 )
goto V_84;
V_19 = F_108 ( V_7 , true ) ;
if ( V_19 )
goto V_130;
V_19 = F_109 ( V_7 ) ;
if ( V_19 )
goto V_130;
V_80 = F_55 ( args -> V_81 ) ;
V_112 = args -> V_13 ;
V_58 = F_110 ( V_7 ) + args -> V_58 ;
F_57 ( V_7 , V_131 ) ;
while ( V_112 > 0 ) {
V_124 = V_58 & V_132 ;
V_125 = F_93 ( V_58 ) ;
V_105 = V_112 ;
if ( ( V_125 + V_112 ) > V_52 )
V_105 = V_52 - V_125 ;
if ( F_103 ( V_30 -> V_133 , V_124 ,
V_125 , V_80 , V_105 ) ) {
V_19 = - V_75 ;
goto V_134;
}
V_112 -= V_105 ;
V_80 += V_105 ;
V_58 += V_105 ;
}
V_134:
F_60 ( V_7 , false , V_131 ) ;
V_130:
F_111 ( V_7 ) ;
V_84:
return V_19 ;
}
static int
F_112 ( struct V_53 * V_53 , int V_104 , int V_105 ,
char T_3 * V_80 ,
bool V_106 ,
bool V_135 ,
bool V_136 )
{
char * V_44 ;
int V_19 ;
if ( F_82 ( V_106 ) )
return - V_51 ;
V_44 = F_27 ( V_53 ) ;
if ( V_135 )
F_28 ( V_44 + V_104 ,
V_105 ) ;
V_19 = F_113 ( V_44 + V_104 ,
V_80 , V_105 ) ;
if ( V_136 )
F_28 ( V_44 + V_104 ,
V_105 ) ;
F_29 ( V_44 ) ;
return V_19 ? - V_75 : 0 ;
}
static int
F_114 ( struct V_53 * V_53 , int V_104 , int V_105 ,
char T_3 * V_80 ,
bool V_106 ,
bool V_135 ,
bool V_136 )
{
char * V_44 ;
int V_19 ;
V_44 = F_88 ( V_53 ) ;
if ( F_82 ( V_135 || V_106 ) )
F_84 ( V_44 + V_104 ,
V_105 ,
V_106 ) ;
if ( V_106 )
V_19 = F_77 ( V_44 , V_104 ,
V_80 ,
V_105 ) ;
else
V_19 = F_78 ( V_44 + V_104 ,
V_80 ,
V_105 ) ;
if ( V_136 )
F_84 ( V_44 + V_104 ,
V_105 ,
V_106 ) ;
F_89 ( V_53 ) ;
return V_19 ? - V_75 : 0 ;
}
static int
F_115 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_78 * args ,
struct V_27 * V_28 )
{
T_7 V_112 ;
T_8 V_58 ;
char T_3 * V_80 ;
int V_104 , V_105 , V_19 = 0 ;
int V_113 , V_106 ;
int V_137 = 0 ;
int V_136 = 0 ;
int V_135 = 0 ;
struct V_115 V_116 ;
V_80 = F_55 ( args -> V_81 ) ;
V_112 = args -> V_13 ;
V_113 = F_23 ( V_7 ) ;
if ( V_7 -> V_8 . V_65 != V_66 ) {
V_136 = F_3 ( V_7 ) ;
V_19 = F_56 ( V_7 , false ) ;
if ( V_19 )
return V_19 ;
}
if ( ( V_7 -> V_8 . V_64 & V_66 ) == 0 )
V_135 =
! F_1 ( V_2 , V_7 -> V_9 ) ;
V_19 = F_53 ( V_7 ) ;
if ( V_19 )
return V_19 ;
F_57 ( V_7 , V_82 ) ;
F_80 ( V_7 ) ;
V_58 = args -> V_58 ;
V_7 -> V_68 = 1 ;
F_91 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_53 * V_53 = F_92 ( & V_116 ) ;
int V_138 ;
if ( V_112 <= 0 )
break;
V_104 = F_93 ( V_58 ) ;
V_105 = V_112 ;
if ( ( V_104 + V_105 ) > V_52 )
V_105 = V_52 - V_104 ;
V_138 = V_135 &&
( ( V_104 | V_105 )
& ( V_139 . V_140 - 1 ) ) ;
V_106 = V_113 &&
( F_94 ( V_53 ) & ( 1 << 17 ) ) != 0 ;
V_19 = F_112 ( V_53 , V_104 , V_105 ,
V_80 , V_106 ,
V_138 ,
V_136 ) ;
if ( V_19 == 0 )
goto V_117;
V_137 = 1 ;
F_20 ( & V_2 -> V_25 ) ;
V_19 = F_114 ( V_53 , V_104 , V_105 ,
V_80 , V_106 ,
V_138 ,
V_136 ) ;
F_18 ( & V_2 -> V_25 ) ;
if ( V_19 )
goto V_84;
V_117:
V_112 -= V_105 ;
V_80 += V_105 ;
V_58 += V_105 ;
}
V_84:
F_97 ( V_7 ) ;
if ( V_137 ) {
if ( ! V_136 &&
V_7 -> V_8 . V_65 != V_66 ) {
if ( F_116 ( V_7 , V_7 -> V_10 ) )
V_136 = true ;
}
}
if ( V_136 )
F_31 ( V_2 ) ;
else
V_7 -> V_141 = true ;
F_60 ( V_7 , false , V_82 ) ;
return V_19 ;
}
int
F_117 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_78 * args = V_26 ;
struct V_6 * V_7 ;
int V_19 ;
if ( args -> V_13 == 0 )
return 0 ;
if ( ! F_99 ( V_142 ,
F_55 ( args -> V_81 ) ,
args -> V_13 ) )
return - V_75 ;
if ( F_95 ( ! V_118 . V_119 ) ) {
V_19 = F_118 ( F_55 ( args -> V_81 ) ,
args -> V_13 ) ;
if ( V_19 )
return - V_75 ;
}
F_119 ( V_12 ) ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
goto V_143;
V_7 = F_100 ( F_101 ( V_28 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_121 ;
goto V_122;
}
if ( args -> V_58 > V_7 -> V_8 . V_13 ||
args -> V_13 > V_7 -> V_8 . V_13 - args -> V_58 ) {
V_19 = - V_51 ;
goto V_84;
}
if ( ! V_7 -> V_8 . V_42 ) {
V_19 = - V_51 ;
goto V_84;
}
F_120 ( V_7 , args -> V_58 , args -> V_13 ) ;
V_19 = - V_75 ;
if ( V_7 -> V_144 == V_145 &&
V_7 -> V_8 . V_65 != V_66 &&
F_3 ( V_7 ) ) {
V_19 = F_106 ( V_2 , V_7 , args , V_28 ) ;
}
if ( V_19 == - V_75 || V_19 == - V_146 ) {
if ( V_7 -> V_45 )
V_19 = F_54 ( V_7 , args , V_28 ) ;
else
V_19 = F_115 ( V_2 , V_7 , args , V_28 ) ;
}
V_84:
F_50 ( & V_7 -> V_8 ) ;
V_122:
F_20 ( & V_2 -> V_25 ) ;
V_143:
F_121 ( V_12 ) ;
return V_19 ;
}
static int
F_122 ( unsigned V_147 , bool V_148 )
{
if ( F_123 ( V_147 ) )
return - V_22 ;
if ( F_124 ( V_147 ) ) {
if ( ! V_148 )
return - V_22 ;
return - V_149 ;
}
return 0 ;
}
static void F_125 ( unsigned long V_26 )
{
F_126 ( (struct V_150 * ) V_26 ) ;
}
static bool F_127 ( struct V_11 * V_12 ,
struct V_151 * V_152 )
{
return F_128 ( V_152 -> V_153 , & V_12 -> V_24 . V_154 ) ;
}
static unsigned long F_129 ( unsigned * V_155 )
{
unsigned long V_156 ;
* V_155 = F_130 () ;
V_156 = F_131 () >> 10 ;
F_132 () ;
return V_156 ;
}
static bool F_133 ( unsigned long V_157 , unsigned V_155 )
{
unsigned V_158 ;
if ( F_134 ( F_129 ( & V_158 ) , V_157 ) )
return true ;
return V_158 != V_155 ;
}
static int F_135 ( struct V_159 * V_160 , int V_161 )
{
unsigned long V_157 ;
unsigned V_155 ;
if ( V_160 -> V_152 -> V_162 )
return - V_74 ;
if ( ! F_136 ( V_160 , true ) )
return - V_149 ;
V_157 = F_129 ( & V_155 ) + 5 ;
while ( ! F_137 () ) {
if ( F_138 ( V_160 , true ) )
return 0 ;
if ( F_139 ( V_161 , V_163 ) )
break;
if ( F_133 ( V_157 , V_155 ) )
break;
F_140 () ;
}
if ( F_138 ( V_160 , false ) )
return 0 ;
return - V_149 ;
}
int F_141 ( struct V_159 * V_160 ,
bool V_148 ,
T_10 * V_157 ,
struct V_164 * V_165 )
{
struct V_151 * V_152 = F_142 ( V_160 ) ;
struct V_1 * V_2 = V_152 -> V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
const bool V_166 =
F_143 ( V_12 -> V_24 . V_167 ) & F_144 ( V_152 ) ;
int V_161 = V_148 ? V_168 : V_169 ;
F_145 ( V_170 ) ;
unsigned long V_171 ;
T_10 V_172 = 0 ;
int V_19 ;
F_146 ( ! F_147 ( V_12 ) , L_2 ) ;
if ( F_148 ( & V_160 -> V_173 ) )
return 0 ;
if ( F_138 ( V_160 , true ) )
return 0 ;
V_171 = 0 ;
if ( V_157 ) {
if ( F_14 ( * V_157 < 0 ) )
return - V_51 ;
if ( * V_157 == 0 )
return - V_174 ;
V_171 = V_175 + F_149 ( * V_157 ) ;
V_172 = F_150 () ;
}
if ( F_151 ( V_12 ) -> V_176 >= 6 )
F_152 ( V_12 , V_165 , V_160 -> V_177 ) ;
F_153 ( V_160 ) ;
V_19 = F_135 ( V_160 , V_161 ) ;
if ( V_19 == 0 )
goto V_84;
if ( ! V_166 && F_14 ( ! V_152 -> V_178 ( V_152 ) ) ) {
V_19 = - V_179 ;
goto V_84;
}
for (; ; ) {
struct V_180 V_181 ;
F_154 ( & V_152 -> V_182 , & V_170 , V_161 ) ;
if ( V_160 -> V_147 != F_155 ( & V_12 -> V_24 ) ) {
V_19 = 0 ;
break;
}
if ( F_138 ( V_160 , false ) ) {
V_19 = 0 ;
break;
}
if ( F_139 ( V_161 , V_163 ) ) {
V_19 = - V_183 ;
break;
}
if ( V_157 && F_156 ( V_175 , V_171 ) ) {
V_19 = - V_174 ;
break;
}
V_181 . V_184 = NULL ;
if ( V_157 || F_127 ( V_12 , V_152 ) ) {
unsigned long V_185 ;
F_157 ( & V_181 , F_125 , ( unsigned long ) V_163 ) ;
V_185 = F_127 ( V_12 , V_152 ) ? V_175 + 1 : V_171 ;
F_158 ( & V_181 , V_185 ) ;
}
F_159 () ;
if ( V_181 . V_184 ) {
F_160 ( & V_181 ) ;
F_161 ( & V_181 ) ;
}
}
if ( ! V_166 )
V_152 -> V_186 ( V_152 ) ;
F_162 ( & V_152 -> V_182 , & V_170 ) ;
V_84:
F_163 ( V_160 ) ;
if ( V_157 ) {
T_10 V_187 = * V_157 - ( F_150 () - V_172 ) ;
* V_157 = V_187 < 0 ? 0 : V_187 ;
if ( V_19 == - V_174 && * V_157 < F_164 ( 1 ) * 1000 )
* V_157 = 0 ;
}
return V_19 ;
}
int F_165 ( struct V_159 * V_160 ,
struct V_27 * V_28 )
{
struct V_188 * V_79 ;
F_14 ( ! V_160 || ! V_28 || V_160 -> V_79 ) ;
if ( ! V_160 || ! V_28 )
return - V_51 ;
if ( V_160 -> V_79 )
return - V_51 ;
V_79 = V_28 -> V_189 ;
F_5 ( & V_79 -> V_14 . V_190 ) ;
V_160 -> V_79 = V_79 ;
F_166 ( & V_160 -> V_191 , & V_79 -> V_14 . V_192 ) ;
F_6 ( & V_79 -> V_14 . V_190 ) ;
V_160 -> V_193 = F_167 ( F_168 ( V_163 ) ) ;
return 0 ;
}
static inline void
F_169 ( struct V_159 * V_194 )
{
struct V_188 * V_79 = V_194 -> V_79 ;
if ( ! V_79 )
return;
F_5 ( & V_79 -> V_14 . V_190 ) ;
F_170 ( & V_194 -> V_191 ) ;
V_194 -> V_79 = NULL ;
F_6 ( & V_79 -> V_14 . V_190 ) ;
F_171 ( V_194 -> V_193 ) ;
V_194 -> V_193 = NULL ;
}
static void F_172 ( struct V_159 * V_194 )
{
F_173 ( V_194 ) ;
V_194 -> V_195 -> V_196 = V_194 -> V_197 ;
F_174 ( & V_194 -> V_173 ) ;
F_169 ( V_194 ) ;
F_175 ( V_194 ) ;
}
static void
F_176 ( struct V_159 * V_160 )
{
struct V_151 * V_152 = V_160 -> V_152 ;
struct V_159 * V_198 ;
F_177 ( & V_152 -> V_2 -> V_25 ) ;
if ( F_148 ( & V_160 -> V_173 ) )
return;
do {
V_198 = F_178 ( & V_152 -> V_192 ,
F_179 ( * V_198 ) , V_173 ) ;
F_172 ( V_198 ) ;
} while ( V_198 != V_160 );
F_14 ( F_15 ( V_152 -> V_2 ) ) ;
}
int
F_180 ( struct V_159 * V_160 )
{
struct V_11 * V_12 = V_160 -> V_118 ;
bool V_148 ;
int V_19 ;
V_148 = V_12 -> V_14 . V_148 ;
F_38 ( ! F_181 ( & V_12 -> V_2 -> V_25 ) ) ;
V_19 = F_141 ( V_160 , V_148 , NULL , NULL ) ;
if ( V_19 )
return V_19 ;
if ( V_160 -> V_147 == F_155 ( & V_12 -> V_24 ) )
F_176 ( V_160 ) ;
return 0 ;
}
int
F_56 ( struct V_6 * V_7 ,
bool V_199 )
{
int V_19 , V_50 ;
if ( ! V_7 -> V_200 )
return 0 ;
if ( V_199 ) {
if ( V_7 -> V_201 != NULL ) {
V_19 = F_180 ( V_7 -> V_201 ) ;
if ( V_19 )
return V_19 ;
V_50 = V_7 -> V_201 -> V_152 -> V_153 ;
if ( V_7 -> V_202 [ V_50 ] == V_7 -> V_201 )
F_182 ( V_7 , V_50 ) ;
else
F_183 ( V_7 ) ;
}
} else {
for ( V_50 = 0 ; V_50 < V_203 ; V_50 ++ ) {
if ( V_7 -> V_202 [ V_50 ] == NULL )
continue;
V_19 = F_180 ( V_7 -> V_202 [ V_50 ] ) ;
if ( V_19 )
return V_19 ;
F_182 ( V_7 , V_50 ) ;
}
F_184 ( V_7 -> V_200 ) ;
}
return 0 ;
}
static void
F_185 ( struct V_6 * V_7 ,
struct V_159 * V_160 )
{
int V_204 = V_160 -> V_152 -> V_153 ;
if ( V_7 -> V_202 [ V_204 ] == V_160 )
F_182 ( V_7 , V_204 ) ;
else if ( V_7 -> V_201 == V_160 )
F_183 ( V_7 ) ;
if ( V_160 -> V_147 == F_155 ( & V_160 -> V_118 -> V_24 ) )
F_176 ( V_160 ) ;
}
static T_11 int
F_186 ( struct V_6 * V_7 ,
struct V_164 * V_165 ,
bool V_199 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_159 * V_205 [ V_203 ] ;
int V_19 , V_50 , V_206 = 0 ;
F_38 ( ! F_181 ( & V_2 -> V_25 ) ) ;
F_38 ( ! V_12 -> V_14 . V_148 ) ;
if ( ! V_7 -> V_200 )
return 0 ;
if ( V_199 ) {
struct V_159 * V_160 ;
V_160 = V_7 -> V_201 ;
if ( V_160 == NULL )
return 0 ;
V_205 [ V_206 ++ ] = F_187 ( V_160 ) ;
} else {
for ( V_50 = 0 ; V_50 < V_203 ; V_50 ++ ) {
struct V_159 * V_160 ;
V_160 = V_7 -> V_202 [ V_50 ] ;
if ( V_160 == NULL )
continue;
V_205 [ V_206 ++ ] = F_187 ( V_160 ) ;
}
}
F_20 ( & V_2 -> V_25 ) ;
V_19 = 0 ;
for ( V_50 = 0 ; V_19 == 0 && V_50 < V_206 ; V_50 ++ )
V_19 = F_141 ( V_205 [ V_50 ] , true , NULL , V_165 ) ;
F_18 ( & V_2 -> V_25 ) ;
for ( V_50 = 0 ; V_50 < V_206 ; V_50 ++ ) {
if ( V_19 == 0 )
F_185 ( V_7 , V_205 [ V_50 ] ) ;
F_175 ( V_205 [ V_50 ] ) ;
}
return V_19 ;
}
static struct V_164 * F_188 ( struct V_27 * V_28 )
{
struct V_188 * V_207 = V_28 -> V_189 ;
return & V_207 -> V_165 ;
}
int
F_189 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_208 * args = V_26 ;
struct V_6 * V_7 ;
T_5 V_64 = args -> V_64 ;
T_5 V_65 = args -> V_65 ;
int V_19 ;
if ( V_65 & V_209 )
return - V_51 ;
if ( V_64 & V_209 )
return - V_51 ;
if ( V_65 != 0 && V_64 != V_65 )
return - V_51 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_100 ( F_101 ( V_28 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_121 ;
goto V_122;
}
V_19 = F_186 ( V_7 ,
F_188 ( V_28 ) ,
! V_65 ) ;
if ( V_19 )
goto V_210;
if ( V_64 & V_211 )
V_19 = F_108 ( V_7 , V_65 != 0 ) ;
else
V_19 = F_39 ( V_7 , V_65 != 0 ) ;
if ( V_65 != 0 )
F_57 ( V_7 ,
V_65 == V_211 ?
V_131 : V_82 ) ;
V_210:
F_50 ( & V_7 -> V_8 ) ;
V_122:
F_20 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_190 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_212 * args = V_26 ;
struct V_6 * V_7 ;
int V_19 = 0 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_100 ( F_101 ( V_28 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_121 ;
goto V_122;
}
if ( V_7 -> V_10 )
F_191 ( V_7 ) ;
F_50 ( & V_7 -> V_8 ) ;
V_122:
F_20 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_192 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_213 * args = V_26 ;
struct V_214 * V_7 ;
unsigned long V_107 ;
if ( args -> V_102 & ~ ( V_215 ) )
return - V_51 ;
if ( args -> V_102 & V_215 && ! F_193 ( V_216 ) )
return - V_179 ;
V_7 = F_101 ( V_28 , args -> V_87 ) ;
if ( V_7 == NULL )
return - V_121 ;
if ( ! V_7 -> V_42 ) {
F_69 ( V_7 ) ;
return - V_51 ;
}
V_107 = F_194 ( V_7 -> V_42 , 0 , args -> V_13 ,
V_217 | V_218 , V_219 ,
args -> V_58 ) ;
if ( args -> V_102 & V_215 ) {
struct V_220 * V_14 = V_163 -> V_14 ;
struct V_221 * V_33 ;
if ( F_195 ( & V_14 -> V_222 ) ) {
F_69 ( V_7 ) ;
return - V_223 ;
}
V_33 = F_196 ( V_14 , V_107 ) ;
if ( V_33 )
V_33 -> V_224 =
F_197 ( F_198 ( V_33 -> V_225 ) ) ;
else
V_107 = - V_56 ;
F_199 ( & V_14 -> V_222 ) ;
}
F_69 ( V_7 ) ;
if ( F_25 ( ( void * ) V_107 ) )
return V_107 ;
args -> V_226 = ( T_4 ) V_107 ;
return 0 ;
}
int F_200 ( struct V_221 * V_33 , struct V_227 * V_228 )
{
struct V_6 * V_7 = F_100 ( V_33 -> V_229 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = F_17 ( V_2 ) ;
struct V_29 * V_30 = & V_12 -> V_30 ;
struct V_230 V_231 = V_232 ;
T_12 V_125 ;
unsigned long V_233 ;
int V_19 = 0 ;
bool V_234 = ! ! ( V_228 -> V_102 & V_235 ) ;
F_119 ( V_12 ) ;
V_125 = ( ( unsigned long ) V_228 -> V_236 - V_33 -> V_237 ) >>
V_238 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
goto V_84;
F_201 ( V_7 , V_125 , true , V_234 ) ;
V_19 = F_186 ( V_7 , NULL , ! V_234 ) ;
if ( V_19 )
goto V_122;
if ( V_7 -> V_9 != V_5 && ! F_2 ( V_2 ) ) {
V_19 = - V_75 ;
goto V_122;
}
if ( V_7 -> V_8 . V_13 >= V_30 -> V_239 &&
V_7 -> V_144 == V_145 ) {
static const unsigned int V_240 = 256 ;
memset ( & V_231 , 0 , sizeof( V_231 ) ) ;
V_231 . type = V_241 ;
V_231 . V_242 . V_243 . V_58 = F_202 ( V_125 , V_240 ) ;
V_231 . V_242 . V_243 . V_13 =
F_203 (unsigned int,
chunk_size,
(vma->vm_end - vma->vm_start)/PAGE_SIZE -
view.params.partial.offset) ;
}
V_19 = F_204 ( V_7 , & V_231 , 0 , V_128 ) ;
if ( V_19 )
goto V_122;
V_19 = F_108 ( V_7 , V_234 ) ;
if ( V_19 )
goto V_244;
V_19 = F_205 ( V_7 ) ;
if ( V_19 )
goto V_244;
V_233 = V_30 -> V_245 +
F_206 ( V_7 , & V_231 ) ;
V_233 >>= V_238 ;
if ( F_82 ( V_231 . type == V_241 ) ) {
unsigned long V_8 = V_33 -> V_237 +
( V_231 . V_242 . V_243 . V_58 << V_238 ) ;
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < V_231 . V_242 . V_243 . V_13 ; V_50 ++ ) {
V_19 = F_207 ( V_33 , V_8 + V_50 * V_52 , V_233 + V_50 ) ;
if ( V_19 )
break;
}
V_7 -> V_246 = true ;
} else {
if ( ! V_7 -> V_246 ) {
unsigned long V_13 = F_203 (unsigned long,
vma->vm_end - vma->vm_start,
obj->base.size) ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_13 > > V_238 ; V_50 ++ ) {
V_19 = F_207 ( V_33 ,
( unsigned long ) V_33 -> V_237 + V_50 * V_52 ,
V_233 + V_50 ) ;
if ( V_19 )
break;
}
V_7 -> V_246 = true ;
} else
V_19 = F_207 ( V_33 ,
( unsigned long ) V_228 -> V_236 ,
V_233 + V_125 ) ;
}
V_244:
F_208 ( V_7 , & V_231 ) ;
V_122:
F_20 ( & V_2 -> V_25 ) ;
V_84:
switch ( V_19 ) {
case - V_22 :
if ( ! F_209 ( & V_12 -> V_24 ) ) {
V_19 = V_247 ;
break;
}
case - V_149 :
case 0 :
case - V_183 :
case - V_223 :
case - V_74 :
V_19 = V_248 ;
break;
case - V_56 :
V_19 = V_249 ;
break;
case - V_146 :
case - V_75 :
V_19 = V_247 ;
break;
default:
F_210 ( V_19 , L_3 , V_19 ) ;
V_19 = V_247 ;
break;
}
F_121 ( V_12 ) ;
return V_19 ;
}
void
F_211 ( struct V_6 * V_7 )
{
F_177 ( & V_7 -> V_8 . V_2 -> V_25 ) ;
if ( ! V_7 -> V_246 )
return;
F_212 ( & V_7 -> V_8 . V_250 ,
V_7 -> V_8 . V_2 -> V_251 -> V_43 ) ;
F_213 () ;
V_7 -> V_246 = false ;
}
void
F_214 ( struct V_11 * V_12 )
{
struct V_6 * V_7 ;
F_19 (obj, &dev_priv->mm.bound_list, global_list)
F_211 ( V_7 ) ;
}
T_5
F_215 ( struct V_1 * V_2 , T_5 V_13 , int V_144 )
{
T_5 V_252 ;
if ( F_151 ( V_2 ) -> V_176 >= 4 ||
V_144 == V_145 )
return V_13 ;
if ( F_151 ( V_2 ) -> V_176 == 3 )
V_252 = 1024 * 1024 ;
else
V_252 = 512 * 1024 ;
while ( V_252 < V_13 )
V_252 <<= 1 ;
return V_252 ;
}
T_5
F_216 ( struct V_1 * V_2 , T_5 V_13 ,
int V_144 , bool V_253 )
{
if ( F_151 ( V_2 ) -> V_176 >= 4 || ( ! V_253 && F_217 ( V_2 ) ) ||
V_144 == V_145 )
return 4096 ;
return F_215 ( V_2 , V_13 , V_144 ) ;
}
static int F_218 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
int V_19 ;
V_12 -> V_14 . V_254 = true ;
V_19 = F_219 ( & V_7 -> V_8 ) ;
if ( V_19 != - V_146 )
goto V_84;
F_220 ( V_12 ,
V_7 -> V_8 . V_13 >> V_238 ,
V_255 |
V_256 |
V_257 ) ;
V_19 = F_219 ( & V_7 -> V_8 ) ;
if ( V_19 != - V_146 )
goto V_84;
F_221 ( V_12 ) ;
V_19 = F_219 ( & V_7 -> V_8 ) ;
V_84:
V_12 -> V_14 . V_254 = false ;
return V_19 ;
}
static void F_222 ( struct V_6 * V_7 )
{
F_223 ( & V_7 -> V_8 ) ;
}
int
F_224 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
T_5 V_87 ,
T_4 * V_58 )
{
struct V_6 * V_7 ;
int V_19 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_100 ( F_101 ( V_28 , V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_121 ;
goto V_122;
}
if ( V_7 -> V_62 != V_70 ) {
F_225 ( L_4 ) ;
V_19 = - V_75 ;
goto V_84;
}
V_19 = F_218 ( V_7 ) ;
if ( V_19 )
goto V_84;
* V_58 = F_226 ( & V_7 -> V_8 . V_250 ) ;
V_84:
F_50 ( & V_7 -> V_8 ) ;
V_122:
F_20 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_227 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_258 * args = V_26 ;
return F_224 ( V_28 , V_2 , args -> V_87 , & args -> V_58 ) ;
}
static void
F_228 ( struct V_6 * V_7 )
{
F_222 ( V_7 ) ;
if ( V_7 -> V_8 . V_42 == NULL )
return;
F_229 ( F_22 ( V_7 -> V_8 . V_42 ) , 0 , ( T_8 ) - 1 ) ;
V_7 -> V_62 = V_63 ;
}
static void
F_230 ( struct V_6 * V_7 )
{
struct V_40 * V_41 ;
switch ( V_7 -> V_62 ) {
case V_67 :
F_228 ( V_7 ) ;
case V_63 :
return;
}
if ( V_7 -> V_8 . V_42 == NULL )
return;
V_41 = F_22 ( V_7 -> V_8 . V_42 ) -> V_43 ,
F_231 ( V_41 , 0 , ( T_8 ) - 1 ) ;
}
static void
F_232 ( struct V_6 * V_7 )
{
struct V_115 V_116 ;
int V_19 ;
F_38 ( V_7 -> V_62 == V_63 ) ;
V_19 = F_39 ( V_7 , true ) ;
if ( F_14 ( V_19 ) ) {
F_116 ( V_7 , true ) ;
V_7 -> V_8 . V_64 = V_7 -> V_8 . V_65 = V_66 ;
}
F_233 ( V_7 ) ;
if ( F_23 ( V_7 ) )
F_234 ( V_7 ) ;
if ( V_7 -> V_62 == V_67 )
V_7 -> V_68 = 0 ;
F_91 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_53 * V_53 = F_92 ( & V_116 ) ;
if ( V_7 -> V_68 )
F_40 ( V_53 ) ;
if ( V_7 -> V_62 == V_70 )
F_41 ( V_53 ) ;
F_30 ( V_53 ) ;
}
V_7 -> V_68 = 0 ;
F_42 ( V_7 -> V_61 ) ;
F_34 ( V_7 -> V_61 ) ;
}
int
F_49 ( struct V_6 * V_7 )
{
const struct V_259 * V_76 = V_7 -> V_76 ;
if ( V_7 -> V_61 == NULL )
return 0 ;
if ( V_7 -> V_260 )
return - V_74 ;
F_38 ( F_235 ( V_7 ) ) ;
F_170 ( & V_7 -> V_261 ) ;
if ( V_7 -> V_41 ) {
if ( F_236 ( V_7 -> V_41 ) )
F_237 ( V_7 -> V_41 ) ;
else
F_89 ( F_238 ( V_7 -> V_41 ) ) ;
V_7 -> V_41 = NULL ;
}
V_76 -> V_262 ( V_7 ) ;
V_7 -> V_61 = NULL ;
F_230 ( V_7 ) ;
return 0 ;
}
static int
F_239 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
int V_263 , V_50 ;
struct V_40 * V_41 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_115 V_116 ;
struct V_53 * V_53 ;
unsigned long V_264 = 0 ;
int V_19 ;
T_13 V_265 ;
F_38 ( V_7 -> V_8 . V_64 & V_209 ) ;
F_38 ( V_7 -> V_8 . V_65 & V_209 ) ;
V_47 = F_32 ( sizeof( * V_47 ) , V_55 ) ;
if ( V_47 == NULL )
return - V_56 ;
V_263 = V_7 -> V_8 . V_13 / V_52 ;
if ( F_33 ( V_47 , V_263 , V_55 ) ) {
F_34 ( V_47 ) ;
return - V_56 ;
}
V_41 = F_22 ( V_7 -> V_8 . V_42 ) -> V_43 ;
V_265 = F_240 ( V_41 , ~ ( V_266 | V_267 ) ) ;
V_265 |= V_268 | V_269 ;
V_49 = V_47 -> V_57 ;
V_47 -> V_270 = 0 ;
for ( V_50 = 0 ; V_50 < V_263 ; V_50 ++ ) {
V_53 = F_241 ( V_41 , V_50 , V_265 ) ;
if ( F_25 ( V_53 ) ) {
F_220 ( V_12 ,
V_263 ,
V_255 |
V_256 |
V_257 ) ;
V_53 = F_241 ( V_41 , V_50 , V_265 ) ;
}
if ( F_25 ( V_53 ) ) {
F_221 ( V_12 ) ;
V_53 = F_24 ( V_41 , V_50 ) ;
if ( F_25 ( V_53 ) ) {
V_19 = F_26 ( V_53 ) ;
goto V_271;
}
}
#ifdef F_242
if ( F_243 () ) {
V_47 -> V_270 ++ ;
F_244 ( V_49 , V_53 , V_52 , 0 ) ;
V_49 = F_245 ( V_49 ) ;
continue;
}
#endif
if ( ! V_50 || F_246 ( V_53 ) != V_264 + 1 ) {
if ( V_50 )
V_49 = F_245 ( V_49 ) ;
V_47 -> V_270 ++ ;
F_244 ( V_49 , V_53 , V_52 , 0 ) ;
} else {
V_49 -> V_59 += V_52 ;
}
V_264 = F_246 ( V_53 ) ;
F_14 ( ( V_265 & V_272 ) && ( V_264 >= 0x00100000UL ) ) ;
}
#ifdef F_242
if ( ! F_243 () )
#endif
F_247 ( V_49 ) ;
V_7 -> V_61 = V_47 ;
V_19 = F_248 ( V_7 ) ;
if ( V_19 )
goto V_271;
if ( F_23 ( V_7 ) )
F_249 ( V_7 ) ;
if ( V_7 -> V_144 != V_145 &&
V_12 -> V_273 & V_274 )
F_80 ( V_7 ) ;
return 0 ;
V_271:
F_247 ( V_49 ) ;
F_91 (st->sgl, &sg_iter, st->nents, 0 )
F_30 ( F_92 ( & V_116 ) ) ;
F_42 ( V_47 ) ;
F_34 ( V_47 ) ;
if ( V_19 == - V_146 )
V_19 = - V_56 ;
return V_19 ;
}
int
F_53 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
const struct V_259 * V_76 = V_7 -> V_76 ;
int V_19 ;
if ( V_7 -> V_61 )
return 0 ;
if ( V_7 -> V_62 != V_70 ) {
F_225 ( L_5 ) ;
return - V_75 ;
}
F_38 ( V_7 -> V_260 ) ;
V_19 = V_76 -> V_275 ( V_7 ) ;
if ( V_19 )
return V_19 ;
F_166 ( & V_7 -> V_261 , & V_12 -> V_14 . V_276 ) ;
V_7 -> V_277 . V_49 = V_7 -> V_61 -> V_57 ;
V_7 -> V_277 . V_278 = 0 ;
return 0 ;
}
void * F_250 ( struct V_6 * V_7 )
{
int V_19 ;
F_177 ( & V_7 -> V_8 . V_2 -> V_25 ) ;
V_19 = F_53 ( V_7 ) ;
if ( V_19 )
return F_251 ( V_19 ) ;
F_80 ( V_7 ) ;
if ( V_7 -> V_41 == NULL ) {
struct V_53 * * V_61 ;
V_61 = NULL ;
if ( V_7 -> V_8 . V_13 == V_52 )
V_7 -> V_41 = F_88 ( F_252 ( V_7 -> V_61 -> V_57 ) ) ;
else
V_61 = F_253 ( V_7 -> V_8 . V_13 >> V_238 ,
sizeof( * V_61 ) ,
V_279 ) ;
if ( V_61 != NULL ) {
struct V_115 V_116 ;
int V_206 ;
V_206 = 0 ;
F_91 (obj->pages->sgl, &sg_iter,
obj->pages->nents, 0 )
V_61 [ V_206 ++ ] = F_92 ( & V_116 ) ;
V_7 -> V_41 = F_254 ( V_61 , V_206 , 0 , V_280 ) ;
F_255 ( V_61 ) ;
}
if ( V_7 -> V_41 == NULL ) {
F_97 ( V_7 ) ;
return F_251 ( - V_56 ) ;
}
}
return V_7 -> V_41 ;
}
void F_256 ( struct V_32 * V_33 ,
struct V_159 * V_160 )
{
struct V_6 * V_7 = V_33 -> V_7 ;
struct V_151 * V_152 ;
V_152 = F_142 ( V_160 ) ;
if ( V_7 -> V_200 == 0 )
F_46 ( & V_7 -> V_8 ) ;
V_7 -> V_200 |= F_144 ( V_152 ) ;
F_257 ( & V_7 -> V_281 [ V_152 -> V_153 ] , & V_152 -> V_282 ) ;
F_258 ( & V_7 -> V_202 [ V_152 -> V_153 ] , V_160 ) ;
F_257 ( & V_33 -> V_283 , & V_33 -> V_284 -> V_282 ) ;
}
static void
F_183 ( struct V_6 * V_7 )
{
F_184 ( V_7 -> V_201 == NULL ) ;
F_184 ( ! ( V_7 -> V_200 & F_144 ( V_7 -> V_201 -> V_152 ) ) ) ;
F_258 ( & V_7 -> V_201 , NULL ) ;
F_60 ( V_7 , true , V_285 ) ;
}
static void
F_182 ( struct V_6 * V_7 , int V_204 )
{
struct V_32 * V_33 ;
F_184 ( V_7 -> V_202 [ V_204 ] == NULL ) ;
F_184 ( ! ( V_7 -> V_200 & ( 1 << V_204 ) ) ) ;
F_174 ( & V_7 -> V_281 [ V_204 ] ) ;
F_258 ( & V_7 -> V_202 [ V_204 ] , NULL ) ;
if ( V_7 -> V_201 && V_7 -> V_201 -> V_152 -> V_153 == V_204 )
F_183 ( V_7 ) ;
V_7 -> V_200 &= ~ ( 1 << V_204 ) ;
if ( V_7 -> V_200 )
return;
F_257 ( & V_7 -> V_261 ,
& F_17 ( V_7 -> V_8 . V_2 ) -> V_14 . V_286 ) ;
F_19 (vma, &obj->vma_list, obj_link) {
if ( ! F_148 ( & V_33 -> V_283 ) )
F_257 ( & V_33 -> V_283 , & V_33 -> V_284 -> V_287 ) ;
}
F_258 ( & V_7 -> V_288 , NULL ) ;
F_50 ( & V_7 -> V_8 ) ;
}
static int
F_259 ( struct V_1 * V_2 , T_6 V_289 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_151 * V_152 ;
int V_19 ;
F_260 (engine, dev_priv) {
V_19 = F_261 ( V_152 ) ;
if ( V_19 )
return V_19 ;
}
F_262 ( V_2 ) ;
F_260 (engine, dev_priv)
F_263 ( V_152 , V_289 ) ;
return 0 ;
}
int F_264 ( struct V_1 * V_2 , T_6 V_289 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 ;
if ( V_289 == 0 )
return - V_51 ;
V_19 = F_259 ( V_2 , V_289 - 1 ) ;
if ( V_19 )
return V_19 ;
V_12 -> V_290 = V_289 ;
V_12 -> V_291 = V_289 - 1 ;
if ( V_12 -> V_291 == 0 )
V_12 -> V_291 -- ;
return 0 ;
}
int
F_265 ( struct V_1 * V_2 , T_6 * V_289 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
if ( V_12 -> V_290 == 0 ) {
int V_19 = F_259 ( V_2 , 0 ) ;
if ( V_19 )
return V_19 ;
V_12 -> V_290 = 1 ;
}
* V_289 = V_12 -> V_291 = V_12 -> V_290 ++ ;
return 0 ;
}
void F_266 ( struct V_159 * V_194 ,
struct V_6 * V_7 ,
bool V_292 )
{
struct V_151 * V_152 ;
struct V_11 * V_12 ;
struct V_293 * V_195 ;
T_6 V_294 ;
int V_19 ;
if ( F_14 ( V_194 == NULL ) )
return;
V_152 = V_194 -> V_152 ;
V_12 = V_194 -> V_118 ;
V_195 = V_194 -> V_195 ;
F_267 ( V_195 ) ;
V_294 = F_268 ( V_195 ) ;
if ( V_292 ) {
if ( V_118 . V_295 )
V_19 = F_269 ( V_194 ) ;
else
V_19 = F_270 ( V_194 ) ;
F_146 ( V_19 , L_6 , V_19 ) ;
}
F_271 ( V_194 ) ;
V_194 -> V_296 = V_294 ;
V_194 -> V_297 = V_7 ;
V_194 -> V_177 = V_175 ;
V_194 -> V_298 = V_152 -> V_299 ;
F_272 ( V_152 -> V_299 , V_194 -> V_289 ) ;
F_166 ( & V_194 -> V_173 , & V_152 -> V_192 ) ;
V_194 -> V_197 = F_268 ( V_195 ) ;
if ( V_118 . V_295 )
V_19 = V_152 -> V_300 ( V_194 ) ;
else {
V_19 = V_152 -> V_301 ( V_194 ) ;
V_194 -> V_302 = F_268 ( V_195 ) ;
}
F_146 ( V_19 , L_7 , V_19 ) ;
F_273 ( V_152 -> V_2 ) ;
F_274 ( V_12 -> V_303 ,
& V_12 -> V_14 . V_304 ,
F_275 ( V_21 ) ) ;
F_276 ( V_12 -> V_2 ) ;
F_277 ( V_195 ) ;
}
static bool F_278 ( struct V_11 * V_12 ,
const struct V_305 * V_306 )
{
unsigned long V_307 ;
V_307 = F_279 () - V_306 -> V_308 . V_309 ;
if ( V_306 -> V_308 . V_310 )
return true ;
if ( V_306 -> V_308 . V_311 &&
V_307 <= V_306 -> V_308 . V_311 ) {
if ( ! F_280 ( V_306 ) ) {
F_225 ( L_8 ) ;
return true ;
} else if ( F_281 ( V_12 ) ) {
if ( F_282 ( V_12 ) )
F_11 ( L_9 ) ;
return true ;
}
}
return false ;
}
static void F_283 ( struct V_11 * V_12 ,
struct V_305 * V_306 ,
const bool V_312 )
{
struct V_313 * V_314 ;
if ( F_14 ( ! V_306 ) )
return;
V_314 = & V_306 -> V_308 ;
if ( V_312 ) {
V_314 -> V_310 = F_278 ( V_12 , V_306 ) ;
V_314 -> V_315 ++ ;
V_314 -> V_309 = F_279 () ;
} else {
V_314 -> V_316 ++ ;
}
}
void F_284 ( struct V_317 * V_318 )
{
struct V_159 * V_160 = F_285 ( V_318 ,
F_179 ( * V_160 ) , V_319 ) ;
struct V_305 * V_306 = V_160 -> V_306 ;
if ( V_160 -> V_79 )
F_169 ( V_160 ) ;
if ( V_306 ) {
if ( V_118 . V_295 && V_306 != V_160 -> V_118 -> V_320 )
F_286 ( V_306 , V_160 -> V_152 ) ;
F_287 ( V_306 ) ;
}
F_64 ( V_160 -> V_118 -> V_205 , V_160 ) ;
}
static inline int
F_288 ( struct V_151 * V_152 ,
struct V_305 * V_306 ,
struct V_159 * * V_321 )
{
struct V_11 * V_12 = F_17 ( V_152 -> V_2 ) ;
unsigned V_147 = F_155 ( & V_12 -> V_24 ) ;
struct V_159 * V_160 ;
int V_19 ;
if ( ! V_321 )
return - V_51 ;
* V_321 = NULL ;
V_19 = F_122 ( V_147 , V_12 -> V_14 . V_148 ) ;
if ( V_19 )
return V_19 ;
V_160 = F_62 ( V_12 -> V_205 , V_55 ) ;
if ( V_160 == NULL )
return - V_56 ;
V_19 = F_265 ( V_152 -> V_2 , & V_160 -> V_289 ) ;
if ( V_19 )
goto V_322;
F_289 ( & V_160 -> V_319 ) ;
V_160 -> V_118 = V_12 ;
V_160 -> V_152 = V_152 ;
V_160 -> V_147 = V_147 ;
V_160 -> V_306 = V_306 ;
F_290 ( V_160 -> V_306 ) ;
if ( V_118 . V_295 )
V_19 = F_291 ( V_160 ) ;
else
V_19 = F_292 ( V_160 ) ;
if ( V_19 ) {
F_287 ( V_160 -> V_306 ) ;
goto V_322;
}
if ( V_118 . V_295 )
V_19 = F_293 ( V_160 ) ;
else
V_19 = F_294 ( V_160 ) ;
if ( V_19 ) {
F_295 ( V_160 -> V_195 ) ;
F_175 ( V_160 ) ;
return V_19 ;
}
* V_321 = V_160 ;
return 0 ;
V_322:
F_64 ( V_12 -> V_205 , V_160 ) ;
return V_19 ;
}
struct V_159 *
F_296 ( struct V_151 * V_152 ,
struct V_305 * V_306 )
{
struct V_159 * V_160 ;
int V_322 ;
if ( V_306 == NULL )
V_306 = F_17 ( V_152 -> V_2 ) -> V_320 ;
V_322 = F_288 ( V_152 , V_306 , & V_160 ) ;
return V_322 ? F_251 ( V_322 ) : V_160 ;
}
struct V_159 *
F_297 ( struct V_151 * V_152 )
{
struct V_159 * V_194 ;
F_19 (request, &engine->request_list, list) {
if ( F_138 ( V_194 , false ) )
continue;
return V_194 ;
}
return NULL ;
}
static void F_298 ( struct V_11 * V_12 ,
struct V_151 * V_152 )
{
struct V_159 * V_194 ;
bool V_323 ;
V_194 = F_297 ( V_152 ) ;
if ( V_194 == NULL )
return;
V_323 = V_152 -> V_324 . V_325 >= V_326 ;
F_283 ( V_12 , V_194 -> V_306 , V_323 ) ;
F_299 (request, &engine->request_list, list)
F_283 ( V_12 , V_194 -> V_306 , false ) ;
}
static void F_300 ( struct V_11 * V_12 ,
struct V_151 * V_152 )
{
struct V_293 * V_327 ;
while ( ! F_148 ( & V_152 -> V_282 ) ) {
struct V_6 * V_7 ;
V_7 = F_178 ( & V_152 -> V_282 ,
struct V_6 ,
V_281 [ V_152 -> V_153 ] ) ;
F_182 ( V_7 , V_152 -> V_153 ) ;
}
if ( V_118 . V_295 ) {
F_301 ( & V_152 -> V_328 ) ;
F_302 ( & V_152 -> V_329 ) ;
F_303 ( & V_152 -> V_330 ,
& V_152 -> V_331 ) ;
F_304 ( & V_152 -> V_329 ) ;
F_305 ( V_152 ) ;
}
while ( ! F_148 ( & V_152 -> V_192 ) ) {
struct V_159 * V_194 ;
V_194 = F_178 ( & V_152 -> V_192 ,
struct V_159 ,
V_173 ) ;
F_172 ( V_194 ) ;
}
F_19 (buffer, &engine->buffers, link) {
V_327 -> V_196 = V_327 -> V_302 ;
F_306 ( V_327 ) ;
}
F_263 ( V_152 , V_152 -> V_299 ) ;
}
void F_307 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_151 * V_152 ;
F_260 (engine, dev_priv)
F_298 ( V_12 , V_152 ) ;
F_260 (engine, dev_priv)
F_300 ( V_12 , V_152 ) ;
F_308 ( V_2 ) ;
F_309 ( V_2 ) ;
F_14 ( F_15 ( V_2 ) ) ;
}
void
F_310 ( struct V_151 * V_152 )
{
F_14 ( F_15 ( V_152 -> V_2 ) ) ;
while ( ! F_148 ( & V_152 -> V_192 ) ) {
struct V_159 * V_194 ;
V_194 = F_178 ( & V_152 -> V_192 ,
struct V_159 ,
V_173 ) ;
if ( ! F_138 ( V_194 , true ) )
break;
F_172 ( V_194 ) ;
}
while ( ! F_148 ( & V_152 -> V_282 ) ) {
struct V_6 * V_7 ;
V_7 = F_178 ( & V_152 -> V_282 ,
struct V_6 ,
V_281 [ V_152 -> V_153 ] ) ;
if ( ! F_148 ( & V_7 -> V_202 [ V_152 -> V_153 ] -> V_173 ) )
break;
F_182 ( V_7 , V_152 -> V_153 ) ;
}
if ( F_82 ( V_152 -> V_332 &&
F_138 ( V_152 -> V_332 , true ) ) ) {
V_152 -> V_186 ( V_152 ) ;
F_258 ( & V_152 -> V_332 , NULL ) ;
}
F_14 ( F_15 ( V_152 -> V_2 ) ) ;
}
bool
F_262 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_151 * V_152 ;
bool V_333 = true ;
F_260 (engine, dev_priv) {
F_310 ( V_152 ) ;
V_333 &= F_148 ( & V_152 -> V_192 ) ;
if ( V_118 . V_295 ) {
F_302 ( & V_152 -> V_329 ) ;
V_333 &= F_148 ( & V_152 -> V_330 ) ;
F_304 ( & V_152 -> V_329 ) ;
F_305 ( V_152 ) ;
}
}
if ( V_333 )
F_311 ( V_12 -> V_303 ,
& V_12 -> V_14 . V_334 ,
F_312 ( 100 ) ) ;
return V_333 ;
}
static void
F_313 ( struct V_335 * V_336 )
{
struct V_11 * V_12 =
F_285 ( V_336 , F_179 ( * V_12 ) , V_14 . V_304 . V_336 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
bool V_333 ;
V_333 = false ;
if ( F_314 ( & V_2 -> V_25 ) ) {
V_333 = F_262 ( V_2 ) ;
F_20 ( & V_2 -> V_25 ) ;
}
if ( ! V_333 )
F_274 ( V_12 -> V_303 , & V_12 -> V_14 . V_304 ,
F_275 ( V_21 ) ) ;
}
static void
F_315 ( struct V_335 * V_336 )
{
struct V_11 * V_12 =
F_285 ( V_336 , F_179 ( * V_12 ) , V_14 . V_334 . V_336 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_151 * V_152 ;
F_260 (engine, dev_priv)
if ( ! F_148 ( & V_152 -> V_192 ) )
return;
F_316 ( V_2 ) ;
if ( F_314 ( & V_2 -> V_25 ) ) {
F_260 (engine, dev_priv)
F_317 ( & V_152 -> V_337 ) ;
F_20 ( & V_2 -> V_25 ) ;
}
}
static int
F_318 ( struct V_6 * V_7 )
{
int V_50 ;
if ( ! V_7 -> V_200 )
return 0 ;
for ( V_50 = 0 ; V_50 < V_203 ; V_50 ++ ) {
struct V_159 * V_160 ;
V_160 = V_7 -> V_202 [ V_50 ] ;
if ( V_160 == NULL )
continue;
if ( F_148 ( & V_160 -> V_173 ) )
goto V_338;
if ( F_138 ( V_160 , true ) ) {
F_176 ( V_160 ) ;
V_338:
F_182 ( V_7 , V_50 ) ;
}
}
return 0 ;
}
int
F_319 ( struct V_1 * V_2 , void * V_26 , struct V_27 * V_28 )
{
struct V_339 * args = V_26 ;
struct V_6 * V_7 ;
struct V_159 * V_160 [ V_203 ] ;
int V_50 , V_206 = 0 ;
int V_19 ;
if ( args -> V_102 != 0 )
return - V_51 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_100 ( F_101 ( V_28 , args -> V_340 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
F_20 ( & V_2 -> V_25 ) ;
return - V_121 ;
}
V_19 = F_318 ( V_7 ) ;
if ( V_19 )
goto V_84;
if ( ! V_7 -> V_200 )
goto V_84;
if ( args -> V_341 == 0 ) {
V_19 = - V_174 ;
goto V_84;
}
F_50 ( & V_7 -> V_8 ) ;
for ( V_50 = 0 ; V_50 < V_203 ; V_50 ++ ) {
if ( V_7 -> V_202 [ V_50 ] == NULL )
continue;
V_160 [ V_206 ++ ] = F_187 ( V_7 -> V_202 [ V_50 ] ) ;
}
F_20 ( & V_2 -> V_25 ) ;
for ( V_50 = 0 ; V_50 < V_206 ; V_50 ++ ) {
if ( V_19 == 0 )
V_19 = F_141 ( V_160 [ V_50 ] , true ,
args -> V_341 > 0 ? & args -> V_341 : NULL ,
F_188 ( V_28 ) ) ;
F_320 ( V_160 [ V_50 ] ) ;
}
return V_19 ;
V_84:
F_50 ( & V_7 -> V_8 ) ;
F_20 ( & V_2 -> V_25 ) ;
return V_19 ;
}
static int
F_321 ( struct V_6 * V_7 ,
struct V_151 * V_342 ,
struct V_159 * V_343 ,
struct V_159 * * V_344 )
{
struct V_151 * V_345 ;
int V_19 ;
V_345 = F_142 ( V_343 ) ;
if ( V_342 == V_345 )
return 0 ;
if ( F_138 ( V_343 , true ) )
return 0 ;
if ( ! F_322 ( V_7 -> V_8 . V_2 ) ) {
struct V_11 * V_118 = F_17 ( V_7 -> V_8 . V_2 ) ;
V_19 = F_141 ( V_343 ,
V_118 -> V_14 . V_148 ,
NULL ,
& V_118 -> V_165 . V_346 ) ;
if ( V_19 )
return V_19 ;
F_185 ( V_7 , V_343 ) ;
} else {
int V_347 = F_323 ( V_345 , V_342 ) ;
T_6 V_289 = F_324 ( V_343 ) ;
F_14 ( ! V_344 ) ;
if ( V_289 <= V_345 -> V_348 . V_349 [ V_347 ] )
return 0 ;
if ( * V_344 == NULL ) {
struct V_159 * V_160 ;
V_160 = F_296 ( V_342 , NULL ) ;
if ( F_25 ( V_160 ) )
return F_26 ( V_160 ) ;
* V_344 = V_160 ;
}
F_325 ( * V_344 , V_345 , V_343 ) ;
V_19 = V_342 -> V_348 . V_350 ( * V_344 , V_345 , V_289 ) ;
if ( V_19 )
return V_19 ;
V_345 -> V_348 . V_349 [ V_347 ] =
F_324 ( V_7 -> V_202 [ V_345 -> V_153 ] ) ;
}
return 0 ;
}
int
F_326 ( struct V_6 * V_7 ,
struct V_151 * V_342 ,
struct V_159 * * V_344 )
{
const bool V_199 = V_7 -> V_8 . V_351 == 0 ;
struct V_159 * V_160 [ V_203 ] ;
int V_19 , V_50 , V_206 ;
if ( ! V_7 -> V_200 )
return 0 ;
if ( V_342 == NULL )
return F_56 ( V_7 , V_199 ) ;
V_206 = 0 ;
if ( V_199 ) {
if ( V_7 -> V_201 )
V_160 [ V_206 ++ ] = V_7 -> V_201 ;
} else {
for ( V_50 = 0 ; V_50 < V_203 ; V_50 ++ )
if ( V_7 -> V_202 [ V_50 ] )
V_160 [ V_206 ++ ] = V_7 -> V_202 [ V_50 ] ;
}
for ( V_50 = 0 ; V_50 < V_206 ; V_50 ++ ) {
V_19 = F_321 ( V_7 , V_342 , V_160 [ V_50 ] , V_344 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static void F_327 ( struct V_6 * V_7 )
{
T_6 V_352 , V_353 ;
F_211 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_64 & V_211 ) == 0 )
return;
V_353 = V_7 -> V_8 . V_64 ;
V_352 = V_7 -> V_8 . V_65 ;
V_7 -> V_8 . V_64 &= ~ V_211 ;
V_7 -> V_8 . V_65 &= ~ V_211 ;
F_328 ( V_7 ,
V_353 ,
V_352 ) ;
}
static int F_329 ( struct V_32 * V_33 , bool V_170 )
{
struct V_6 * V_7 = V_33 -> V_7 ;
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
int V_19 ;
if ( F_148 ( & V_33 -> V_354 ) )
return 0 ;
if ( ! F_330 ( & V_33 -> V_36 ) ) {
F_331 ( V_33 ) ;
return 0 ;
}
if ( V_33 -> V_35 )
return - V_74 ;
F_38 ( V_7 -> V_61 == NULL ) ;
if ( V_170 ) {
V_19 = F_56 ( V_7 , false ) ;
if ( V_19 )
return V_19 ;
}
if ( V_33 -> V_355 && V_33 -> V_356 . type == V_357 ) {
F_327 ( V_7 ) ;
V_19 = F_109 ( V_7 ) ;
if ( V_19 )
return V_19 ;
}
F_332 ( V_33 ) ;
V_33 -> V_284 -> V_358 ( V_33 ) ;
V_33 -> V_359 = 0 ;
F_174 ( & V_33 -> V_283 ) ;
if ( V_33 -> V_355 ) {
if ( V_33 -> V_356 . type == V_357 ) {
V_7 -> V_360 = false ;
} else if ( V_33 -> V_356 . V_61 ) {
F_42 ( V_33 -> V_356 . V_61 ) ;
F_34 ( V_33 -> V_356 . V_61 ) ;
}
V_33 -> V_356 . V_61 = NULL ;
}
F_333 ( & V_33 -> V_36 ) ;
F_331 ( V_33 ) ;
if ( F_148 ( & V_7 -> V_361 ) )
F_257 ( & V_7 -> V_261 , & V_12 -> V_14 . V_276 ) ;
F_97 ( V_7 ) ;
return 0 ;
}
int F_48 ( struct V_32 * V_33 )
{
return F_329 ( V_33 , true ) ;
}
int F_334 ( struct V_32 * V_33 )
{
return F_329 ( V_33 , false ) ;
}
int F_335 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_151 * V_152 ;
int V_19 ;
F_260 (engine, dev_priv) {
if ( ! V_118 . V_295 ) {
struct V_159 * V_160 ;
V_160 = F_296 ( V_152 , NULL ) ;
if ( F_25 ( V_160 ) )
return F_26 ( V_160 ) ;
V_19 = F_336 ( V_160 ) ;
F_337 ( V_160 ) ;
if ( V_19 )
return V_19 ;
}
V_19 = F_261 ( V_152 ) ;
if ( V_19 )
return V_19 ;
}
F_14 ( F_15 ( V_2 ) ) ;
return 0 ;
}
static bool F_338 ( struct V_32 * V_33 ,
unsigned long V_9 )
{
struct V_362 * V_363 = & V_33 -> V_36 ;
struct V_362 * V_364 ;
if ( V_33 -> V_284 -> V_14 . V_365 == NULL )
return true ;
if ( ! F_330 ( V_363 ) )
return true ;
if ( F_148 ( & V_363 -> V_366 ) )
return true ;
V_364 = F_339 ( V_363 -> V_366 . V_367 , struct V_362 , V_366 ) ;
if ( V_364 -> V_368 && ! V_364 -> V_369 && V_364 -> V_370 != V_9 )
return false ;
V_364 = F_339 ( V_363 -> V_366 . V_71 , struct V_362 , V_366 ) ;
if ( V_364 -> V_368 && ! V_363 -> V_369 && V_364 -> V_370 != V_9 )
return false ;
return true ;
}
static struct V_32 *
F_340 ( struct V_6 * V_7 ,
struct V_371 * V_284 ,
const struct V_230 * V_356 ,
unsigned V_372 ,
T_4 V_102 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = F_17 ( V_2 ) ;
struct V_29 * V_30 = & V_12 -> V_30 ;
T_6 V_373 , V_374 ;
T_6 V_375 , V_376 ;
T_14 V_109 , V_110 ;
T_14 V_13 , V_377 ;
struct V_32 * V_33 ;
int V_19 ;
if ( F_341 ( V_284 ) ) {
T_6 V_378 ;
if ( F_14 ( ! V_356 ) )
return F_251 ( - V_51 ) ;
V_378 = F_342 ( V_7 , V_356 ) ;
V_377 = F_215 ( V_2 ,
V_378 ,
V_7 -> V_144 ) ;
V_373 = F_216 ( V_2 ,
V_378 ,
V_7 -> V_144 ,
true ) ;
V_374 = F_216 ( V_2 ,
V_378 ,
V_7 -> V_144 ,
false ) ;
V_13 = V_102 & V_128 ? V_377 : V_378 ;
} else {
V_377 = F_215 ( V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_144 ) ;
V_373 = F_216 ( V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_144 ,
true ) ;
V_374 =
F_216 ( V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_144 ,
false ) ;
V_13 = V_102 & V_128 ? V_377 : V_7 -> V_8 . V_13 ;
}
V_109 = V_102 & V_379 ? V_102 & V_380 : 0 ;
V_110 = V_284 -> V_38 ;
if ( V_102 & V_128 )
V_110 = F_203 ( T_14 , V_110 , V_30 -> V_239 ) ;
if ( V_102 & V_381 )
V_110 = F_203 ( T_14 , V_110 , ( 1ULL << 32 ) - V_52 ) ;
if ( V_372 == 0 )
V_372 = V_102 & V_128 ? V_373 :
V_374 ;
if ( V_102 & V_128 && V_372 & ( V_373 - 1 ) ) {
F_225 ( L_10 ,
V_356 ? V_356 -> type : 0 ,
V_372 ) ;
return F_251 ( - V_51 ) ;
}
if ( V_13 > V_110 ) {
F_225 ( L_11 ,
V_356 ? V_356 -> type : 0 ,
V_13 ,
V_102 & V_128 ? L_12 : L_13 ,
V_110 ) ;
return F_251 ( - V_382 ) ;
}
V_19 = F_53 ( V_7 ) ;
if ( V_19 )
return F_251 ( V_19 ) ;
F_80 ( V_7 ) ;
V_33 = V_356 ? F_343 ( V_7 , V_356 ) :
F_344 ( V_7 , V_284 ) ;
if ( F_25 ( V_33 ) )
goto V_383;
if ( V_102 & V_384 ) {
T_4 V_58 = V_102 & V_380 ;
if ( V_58 & ( V_372 - 1 ) || V_58 + V_13 > V_110 ) {
V_19 = - V_51 ;
goto V_385;
}
V_33 -> V_36 . V_109 = V_58 ;
V_33 -> V_36 . V_13 = V_13 ;
V_33 -> V_36 . V_370 = V_7 -> V_9 ;
V_19 = F_345 ( & V_284 -> V_14 , & V_33 -> V_36 ) ;
if ( V_19 ) {
V_19 = F_346 ( V_33 ) ;
if ( V_19 == 0 )
V_19 = F_345 ( & V_284 -> V_14 , & V_33 -> V_36 ) ;
}
if ( V_19 )
goto V_385;
} else {
if ( V_102 & V_386 ) {
V_375 = V_387 ;
V_376 = V_388 ;
} else {
V_375 = V_389 ;
V_376 = V_390 ;
}
V_391:
V_19 = F_347 ( & V_284 -> V_14 , & V_33 -> V_36 ,
V_13 , V_372 ,
V_7 -> V_9 ,
V_109 , V_110 ,
V_375 ,
V_376 ) ;
if ( V_19 ) {
V_19 = F_348 ( V_2 , V_284 , V_13 , V_372 ,
V_7 -> V_9 ,
V_109 , V_110 ,
V_102 ) ;
if ( V_19 == 0 )
goto V_391;
goto V_385;
}
}
if ( F_14 ( ! F_338 ( V_33 , V_7 -> V_9 ) ) ) {
V_19 = - V_51 ;
goto V_392;
}
F_349 ( V_33 , V_102 ) ;
V_19 = F_350 ( V_33 , V_7 -> V_9 , V_102 ) ;
if ( V_19 )
goto V_392;
F_257 ( & V_7 -> V_261 , & V_12 -> V_14 . V_286 ) ;
F_166 ( & V_33 -> V_283 , & V_284 -> V_287 ) ;
return V_33 ;
V_392:
F_333 ( & V_33 -> V_36 ) ;
V_385:
F_331 ( V_33 ) ;
V_33 = F_251 ( V_19 ) ;
V_383:
F_97 ( V_7 ) ;
return V_33 ;
}
bool
F_116 ( struct V_6 * V_7 ,
bool V_393 )
{
if ( V_7 -> V_61 == NULL )
return false ;
if ( V_7 -> V_394 || V_7 -> V_45 )
return false ;
if ( ! V_393 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_9 ) ) {
V_7 -> V_141 = true ;
return false ;
}
F_351 ( V_7 ) ;
F_352 ( V_7 -> V_61 ) ;
V_7 -> V_141 = false ;
return true ;
}
static void
F_353 ( struct V_6 * V_7 )
{
T_5 V_352 ;
if ( V_7 -> V_8 . V_65 != V_211 )
return;
F_213 () ;
V_352 = V_7 -> V_8 . V_65 ;
V_7 -> V_8 . V_65 = 0 ;
F_60 ( V_7 , false , V_131 ) ;
F_328 ( V_7 ,
V_7 -> V_8 . V_64 ,
V_352 ) ;
}
static void
F_191 ( struct V_6 * V_7 )
{
T_5 V_352 ;
if ( V_7 -> V_8 . V_65 != V_66 )
return;
if ( F_116 ( V_7 , V_7 -> V_10 ) )
F_31 ( V_7 -> V_8 . V_2 ) ;
V_352 = V_7 -> V_8 . V_65 ;
V_7 -> V_8 . V_65 = 0 ;
F_60 ( V_7 , false , V_82 ) ;
F_328 ( V_7 ,
V_7 -> V_8 . V_64 ,
V_352 ) ;
}
int
F_108 ( struct V_6 * V_7 , bool V_234 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = F_17 ( V_2 ) ;
struct V_29 * V_30 = & V_12 -> V_30 ;
T_5 V_352 , V_353 ;
struct V_32 * V_33 ;
int V_19 ;
if ( V_7 -> V_8 . V_65 == V_211 )
return 0 ;
V_19 = F_56 ( V_7 , ! V_234 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_53 ( V_7 ) ;
if ( V_19 )
return V_19 ;
F_191 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_64 & V_211 ) == 0 )
F_354 () ;
V_352 = V_7 -> V_8 . V_65 ;
V_353 = V_7 -> V_8 . V_64 ;
F_38 ( ( V_7 -> V_8 . V_65 & ~ V_211 ) != 0 ) ;
V_7 -> V_8 . V_64 |= V_211 ;
if ( V_234 ) {
V_7 -> V_8 . V_64 = V_211 ;
V_7 -> V_8 . V_65 = V_211 ;
V_7 -> V_68 = 1 ;
}
F_328 ( V_7 ,
V_353 ,
V_352 ) ;
V_33 = F_355 ( V_7 ) ;
if ( V_33 && F_330 ( & V_33 -> V_36 ) && ! V_7 -> V_200 )
F_257 ( & V_33 -> V_283 ,
& V_30 -> V_8 . V_287 ) ;
return 0 ;
}
int F_356 ( struct V_6 * V_7 ,
enum V_3 V_9 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_32 * V_33 , * V_71 ;
bool V_359 = false ;
int V_19 = 0 ;
if ( V_7 -> V_9 == V_9 )
goto V_84;
F_47 (vma, next, &obj->vma_list, obj_link) {
if ( ! F_330 ( & V_33 -> V_36 ) )
continue;
if ( V_33 -> V_35 ) {
F_225 ( L_14 ) ;
return - V_74 ;
}
if ( ! F_338 ( V_33 , V_9 ) ) {
V_19 = F_48 ( V_33 ) ;
if ( V_19 )
return V_19 ;
} else
V_359 = true ;
}
if ( V_359 ) {
V_19 = F_56 ( V_7 , false ) ;
if ( V_19 )
return V_19 ;
if ( ! F_2 ( V_2 ) && V_9 != V_5 ) {
F_211 ( V_7 ) ;
V_19 = F_109 ( V_7 ) ;
if ( V_19 )
return V_19 ;
} else {
}
F_19 (vma, &obj->vma_list, obj_link) {
if ( ! F_330 ( & V_33 -> V_36 ) )
continue;
V_19 = F_350 ( V_33 , V_9 , V_395 ) ;
if ( V_19 )
return V_19 ;
}
}
F_19 (vma, &obj->vma_list, obj_link)
V_33 -> V_36 . V_370 = V_9 ;
V_7 -> V_9 = V_9 ;
V_84:
if ( V_7 -> V_141 &&
V_7 -> V_8 . V_65 != V_66 &&
F_3 ( V_7 ) ) {
if ( F_116 ( V_7 , true ) )
F_31 ( V_7 -> V_8 . V_2 ) ;
}
return 0 ;
}
int F_357 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_396 * args = V_26 ;
struct V_6 * V_7 ;
V_7 = F_100 ( F_101 ( V_28 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL )
return - V_121 ;
switch ( V_7 -> V_9 ) {
case V_397 :
case V_398 :
args -> V_399 = V_400 ;
break;
case V_401 :
args -> V_399 = V_402 ;
break;
default:
args -> V_399 = V_403 ;
break;
}
F_69 ( & V_7 -> V_8 ) ;
return 0 ;
}
int F_358 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_396 * args = V_26 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_19 ;
switch ( args -> V_399 ) {
case V_403 :
V_4 = V_5 ;
break;
case V_400 :
if ( ! F_2 ( V_2 ) && ! F_359 ( V_2 ) )
return - V_179 ;
V_4 = V_397 ;
break;
case V_402 :
V_4 = F_360 ( V_2 ) ? V_401 : V_5 ;
break;
default:
return - V_51 ;
}
F_119 ( V_12 ) ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
goto V_404;
V_7 = F_100 ( F_101 ( V_28 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_121 ;
goto V_122;
}
V_19 = F_356 ( V_7 , V_4 ) ;
F_50 ( & V_7 -> V_8 ) ;
V_122:
F_20 ( & V_2 -> V_25 ) ;
V_404:
F_121 ( V_12 ) ;
return V_19 ;
}
int
F_361 ( struct V_6 * V_7 ,
T_6 V_372 ,
const struct V_230 * V_231 )
{
T_6 V_353 , V_352 ;
int V_19 ;
V_7 -> V_10 ++ ;
V_19 = F_356 ( V_7 ,
F_360 ( V_7 -> V_8 . V_2 ) ? V_401 : V_5 ) ;
if ( V_19 )
goto V_405;
V_19 = F_204 ( V_7 , V_231 , V_372 ,
V_231 -> type == V_357 ?
V_128 : 0 ) ;
if ( V_19 )
goto V_405;
F_191 ( V_7 ) ;
V_352 = V_7 -> V_8 . V_65 ;
V_353 = V_7 -> V_8 . V_64 ;
V_7 -> V_8 . V_65 = 0 ;
V_7 -> V_8 . V_64 |= V_211 ;
F_328 ( V_7 ,
V_353 ,
V_352 ) ;
return 0 ;
V_405:
V_7 -> V_10 -- ;
return V_19 ;
}
void
F_362 ( struct V_6 * V_7 ,
const struct V_230 * V_231 )
{
if ( F_14 ( V_7 -> V_10 == 0 ) )
return;
F_208 ( V_7 , V_231 ) ;
V_7 -> V_10 -- ;
}
int
F_39 ( struct V_6 * V_7 , bool V_234 )
{
T_5 V_352 , V_353 ;
int V_19 ;
if ( V_7 -> V_8 . V_65 == V_66 )
return 0 ;
V_19 = F_56 ( V_7 , ! V_234 ) ;
if ( V_19 )
return V_19 ;
F_353 ( V_7 ) ;
V_352 = V_7 -> V_8 . V_65 ;
V_353 = V_7 -> V_8 . V_64 ;
if ( ( V_7 -> V_8 . V_64 & V_66 ) == 0 ) {
F_116 ( V_7 , false ) ;
V_7 -> V_8 . V_64 |= V_66 ;
}
F_38 ( ( V_7 -> V_8 . V_65 & ~ V_66 ) != 0 ) ;
if ( V_234 ) {
V_7 -> V_8 . V_64 = V_66 ;
V_7 -> V_8 . V_65 = V_66 ;
}
F_328 ( V_7 ,
V_353 ,
V_352 ) ;
return 0 ;
}
static int
F_363 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_188 * V_79 = V_28 -> V_189 ;
unsigned long V_406 = V_175 - V_407 ;
struct V_159 * V_194 , * V_408 = NULL ;
int V_19 ;
V_19 = F_8 ( & V_12 -> V_24 ) ;
if ( V_19 )
return V_19 ;
if ( F_209 ( & V_12 -> V_24 ) )
return - V_22 ;
F_5 ( & V_79 -> V_14 . V_190 ) ;
F_19 (request, &file_priv->mm.request_list, client_list) {
if ( F_156 ( V_194 -> V_177 , V_406 ) )
break;
if ( ! V_194 -> V_177 )
continue;
V_408 = V_194 ;
}
if ( V_408 )
F_187 ( V_408 ) ;
F_6 ( & V_79 -> V_14 . V_190 ) ;
if ( V_408 == NULL )
return 0 ;
V_19 = F_141 ( V_408 , true , NULL , NULL ) ;
if ( V_19 == 0 )
F_274 ( V_12 -> V_303 , & V_12 -> V_14 . V_304 , 0 ) ;
F_320 ( V_408 ) ;
return V_19 ;
}
static bool
F_364 ( struct V_32 * V_33 , T_5 V_372 , T_4 V_102 )
{
struct V_6 * V_7 = V_33 -> V_7 ;
if ( V_372 &&
V_33 -> V_36 . V_109 & ( V_372 - 1 ) )
return true ;
if ( V_102 & V_128 && ! V_7 -> V_360 )
return true ;
if ( V_102 & V_379 &&
V_33 -> V_36 . V_109 < ( V_102 & V_380 ) )
return true ;
if ( V_102 & V_384 &&
V_33 -> V_36 . V_109 != ( V_102 & V_380 ) )
return true ;
return false ;
}
void F_365 ( struct V_32 * V_33 )
{
struct V_6 * V_7 = V_33 -> V_7 ;
bool V_133 , V_409 ;
T_6 V_377 , V_373 ;
V_377 = F_215 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_144 ) ;
V_373 = F_216 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_13 ,
V_7 -> V_144 ,
true ) ;
V_409 = ( V_33 -> V_36 . V_13 == V_377 &&
( V_33 -> V_36 . V_109 & ( V_373 - 1 ) ) == 0 ) ;
V_133 = ( V_33 -> V_36 . V_109 + V_377 <=
F_17 ( V_7 -> V_8 . V_2 ) -> V_30 . V_239 ) ;
V_7 -> V_360 = V_133 && V_409 ;
}
static int
F_366 ( struct V_6 * V_7 ,
struct V_371 * V_284 ,
const struct V_230 * V_356 ,
T_5 V_372 ,
T_4 V_102 )
{
struct V_11 * V_12 = V_7 -> V_8 . V_2 -> V_23 ;
struct V_32 * V_33 ;
unsigned V_359 ;
int V_19 ;
if ( F_14 ( V_284 == & V_12 -> V_14 . V_410 -> V_8 ) )
return - V_179 ;
if ( F_14 ( V_102 & ( V_411 | V_128 ) && ! F_341 ( V_284 ) ) )
return - V_51 ;
if ( F_14 ( ( V_102 & ( V_128 | V_411 ) ) == V_128 ) )
return - V_51 ;
if ( F_14 ( F_341 ( V_284 ) != ! ! V_356 ) )
return - V_51 ;
V_33 = V_356 ? F_367 ( V_7 , V_356 ) :
F_368 ( V_7 , V_284 ) ;
if ( V_33 ) {
if ( F_14 ( V_33 -> V_35 == V_412 ) )
return - V_74 ;
if ( F_364 ( V_33 , V_372 , V_102 ) ) {
F_146 ( V_33 -> V_35 ,
L_15
L_16
L_17 ,
V_356 ? L_18 : L_19 ,
F_369 ( V_33 -> V_36 . V_109 ) ,
F_370 ( V_33 -> V_36 . V_109 ) ,
V_372 ,
! ! ( V_102 & V_128 ) ,
V_7 -> V_360 ) ;
V_19 = F_48 ( V_33 ) ;
if ( V_19 )
return V_19 ;
V_33 = NULL ;
}
}
V_359 = V_33 ? V_33 -> V_359 : 0 ;
if ( V_33 == NULL || ! F_330 ( & V_33 -> V_36 ) ) {
V_33 = F_340 ( V_7 , V_284 , V_356 , V_372 ,
V_102 ) ;
if ( F_25 ( V_33 ) )
return F_26 ( V_33 ) ;
} else {
V_19 = F_350 ( V_33 , V_7 -> V_9 , V_102 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_356 && V_356 -> type == V_357 &&
( V_359 ^ V_33 -> V_359 ) & V_413 ) {
F_365 ( V_33 ) ;
F_14 ( V_102 & V_128 && ! V_7 -> V_360 ) ;
}
V_33 -> V_35 ++ ;
return 0 ;
}
int
F_371 ( struct V_6 * V_7 ,
struct V_371 * V_284 ,
T_5 V_372 ,
T_4 V_102 )
{
return F_366 ( V_7 , V_284 ,
F_341 ( V_284 ) ? & V_232 : NULL ,
V_372 , V_102 ) ;
}
int
F_204 ( struct V_6 * V_7 ,
const struct V_230 * V_231 ,
T_5 V_372 ,
T_4 V_102 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = F_17 ( V_2 ) ;
struct V_29 * V_30 = & V_12 -> V_30 ;
F_38 ( ! V_231 ) ;
return F_366 ( V_7 , & V_30 -> V_8 , V_231 ,
V_372 , V_102 | V_411 ) ;
}
void
F_208 ( struct V_6 * V_7 ,
const struct V_230 * V_231 )
{
struct V_32 * V_33 = F_367 ( V_7 , V_231 ) ;
F_14 ( V_33 -> V_35 == 0 ) ;
F_14 ( ! F_372 ( V_7 , V_231 ) ) ;
-- V_33 -> V_35 ;
}
int
F_373 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_414 * args = V_26 ;
struct V_6 * V_7 ;
int V_19 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_100 ( F_101 ( V_28 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_121 ;
goto V_122;
}
V_19 = F_318 ( V_7 ) ;
if ( V_19 )
goto V_210;
args -> V_415 = 0 ;
if ( V_7 -> V_200 ) {
int V_50 ;
for ( V_50 = 0 ; V_50 < V_203 ; V_50 ++ ) {
struct V_159 * V_160 ;
V_160 = V_7 -> V_202 [ V_50 ] ;
if ( V_160 )
args -> V_415 |= 1 << ( 16 + V_160 -> V_152 -> V_416 ) ;
}
if ( V_7 -> V_201 )
args -> V_415 |= V_7 -> V_201 -> V_152 -> V_416 ;
}
V_210:
F_50 ( & V_7 -> V_8 ) ;
V_122:
F_20 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int
F_374 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_79 )
{
return F_363 ( V_2 , V_79 ) ;
}
int
F_375 ( struct V_1 * V_2 , void * V_26 ,
struct V_27 * V_79 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_417 * args = V_26 ;
struct V_6 * V_7 ;
int V_19 ;
switch ( args -> V_62 ) {
case V_67 :
case V_70 :
break;
default:
return - V_51 ;
}
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_7 = F_100 ( F_101 ( V_79 , args -> V_87 ) ) ;
if ( & V_7 -> V_8 == NULL ) {
V_19 = - V_121 ;
goto V_122;
}
if ( F_376 ( V_7 ) ) {
V_19 = - V_51 ;
goto V_84;
}
if ( V_7 -> V_61 &&
V_7 -> V_144 != V_145 &&
V_12 -> V_273 & V_274 ) {
if ( V_7 -> V_62 == V_70 )
F_97 ( V_7 ) ;
if ( args -> V_62 == V_70 )
F_80 ( V_7 ) ;
}
if ( V_7 -> V_62 != V_63 )
V_7 -> V_62 = args -> V_62 ;
if ( V_7 -> V_62 == V_67 && V_7 -> V_61 == NULL )
F_228 ( V_7 ) ;
args -> V_418 = V_7 -> V_62 != V_63 ;
V_84:
F_50 ( & V_7 -> V_8 ) ;
V_122:
F_20 ( & V_2 -> V_25 ) ;
return V_19 ;
}
void F_377 ( struct V_6 * V_7 ,
const struct V_259 * V_76 )
{
int V_50 ;
F_378 ( & V_7 -> V_261 ) ;
for ( V_50 = 0 ; V_50 < V_203 ; V_50 ++ )
F_378 ( & V_7 -> V_281 [ V_50 ] ) ;
F_378 ( & V_7 -> V_419 ) ;
F_378 ( & V_7 -> V_361 ) ;
F_378 ( & V_7 -> V_420 ) ;
V_7 -> V_76 = V_76 ;
V_7 -> V_421 = V_422 ;
V_7 -> V_62 = V_70 ;
F_4 ( V_7 -> V_8 . V_2 -> V_23 , V_7 -> V_8 . V_13 ) ;
}
struct V_6 * F_67 ( struct V_1 * V_2 ,
T_1 V_13 )
{
struct V_6 * V_7 ;
struct V_40 * V_41 ;
T_13 V_423 ;
V_7 = F_61 ( V_2 ) ;
if ( V_7 == NULL )
return NULL ;
if ( F_379 ( V_2 , & V_7 -> V_8 , V_13 ) != 0 ) {
F_63 ( V_7 ) ;
return NULL ;
}
V_423 = V_424 | V_425 ;
if ( F_380 ( V_2 ) || F_381 ( V_2 ) ) {
V_423 &= ~ V_426 ;
V_423 |= V_272 ;
}
V_41 = F_22 ( V_7 -> V_8 . V_42 ) -> V_43 ;
F_382 ( V_41 , V_423 ) ;
F_377 ( V_7 , & V_427 ) ;
V_7 -> V_8 . V_65 = V_66 ;
V_7 -> V_8 . V_64 = V_66 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_9 = V_397 ;
} else
V_7 -> V_9 = V_5 ;
F_383 ( V_7 ) ;
return V_7 ;
}
static bool F_384 ( struct V_6 * V_7 )
{
if ( V_7 -> V_62 != V_70 )
return false ;
if ( V_7 -> V_8 . V_42 == NULL )
return true ;
return F_385 ( & V_7 -> V_8 . V_42 -> V_428 ) == 1 ;
}
void F_386 ( struct V_214 * V_429 )
{
struct V_6 * V_7 = F_100 ( V_429 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_32 * V_33 , * V_71 ;
F_119 ( V_12 ) ;
F_387 ( V_7 ) ;
F_47 (vma, next, &obj->vma_list, obj_link) {
int V_19 ;
V_33 -> V_35 = 0 ;
V_19 = F_48 ( V_33 ) ;
if ( F_14 ( V_19 == - V_183 ) ) {
bool V_430 ;
V_430 = V_12 -> V_14 . V_148 ;
V_12 -> V_14 . V_148 = false ;
F_14 ( F_48 ( V_33 ) ) ;
V_12 -> V_14 . V_148 = V_430 ;
}
}
if ( V_7 -> V_394 )
F_97 ( V_7 ) ;
F_14 ( V_7 -> V_431 ) ;
if ( V_7 -> V_61 && V_7 -> V_62 == V_70 &&
V_12 -> V_273 & V_274 &&
V_7 -> V_144 != V_145 )
F_97 ( V_7 ) ;
if ( F_14 ( V_7 -> V_260 ) )
V_7 -> V_260 = 0 ;
if ( F_384 ( V_7 ) )
V_7 -> V_62 = V_67 ;
F_49 ( V_7 ) ;
F_222 ( V_7 ) ;
F_38 ( V_7 -> V_61 ) ;
if ( V_7 -> V_8 . V_432 )
F_388 ( & V_7 -> V_8 , NULL ) ;
if ( V_7 -> V_76 -> V_433 )
V_7 -> V_76 -> V_433 ( V_7 ) ;
F_389 ( & V_7 -> V_8 ) ;
F_7 ( V_12 , V_7 -> V_8 . V_13 ) ;
F_34 ( V_7 -> V_434 ) ;
F_63 ( V_7 ) ;
F_121 ( V_12 ) ;
}
struct V_32 * F_368 ( struct V_6 * V_7 ,
struct V_371 * V_284 )
{
struct V_32 * V_33 ;
F_19 (vma, &obj->vma_list, obj_link) {
if ( V_33 -> V_356 . type == V_357 &&
V_33 -> V_284 == V_284 )
return V_33 ;
}
return NULL ;
}
struct V_32 * F_367 ( struct V_6 * V_7 ,
const struct V_230 * V_231 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_11 * V_12 = F_17 ( V_2 ) ;
struct V_29 * V_30 = & V_12 -> V_30 ;
struct V_32 * V_33 ;
F_38 ( ! V_231 ) ;
F_19 (vma, &obj->vma_list, obj_link)
if ( V_33 -> V_284 == & V_30 -> V_8 &&
F_390 ( & V_33 -> V_356 , V_231 ) )
return V_33 ;
return NULL ;
}
void F_331 ( struct V_32 * V_33 )
{
F_14 ( V_33 -> V_36 . V_368 ) ;
if ( ! F_148 ( & V_33 -> V_435 ) )
return;
if ( ! V_33 -> V_355 )
F_391 ( F_392 ( V_33 -> V_284 ) ) ;
F_170 ( & V_33 -> V_354 ) ;
F_64 ( F_17 ( V_33 -> V_7 -> V_8 . V_2 ) -> V_436 , V_33 ) ;
}
static void
F_393 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_151 * V_152 ;
F_260 (engine, dev_priv)
V_12 -> V_437 . V_438 ( V_152 ) ;
}
int
F_394 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 = 0 ;
F_18 ( & V_2 -> V_25 ) ;
V_19 = F_335 ( V_2 ) ;
if ( V_19 )
goto V_322;
F_262 ( V_2 ) ;
F_393 ( V_2 ) ;
F_20 ( & V_2 -> V_25 ) ;
F_395 ( & V_12 -> V_24 . V_439 ) ;
F_395 ( & V_12 -> V_14 . V_304 ) ;
F_396 ( & V_12 -> V_14 . V_334 ) ;
F_14 ( V_12 -> V_14 . V_415 ) ;
return 0 ;
V_322:
F_20 ( & V_2 -> V_25 ) ;
return V_19 ;
}
int F_397 ( struct V_159 * V_160 , int V_440 )
{
struct V_151 * V_152 = V_160 -> V_152 ;
struct V_1 * V_2 = V_152 -> V_2 ;
struct V_11 * V_12 = V_2 -> V_23 ;
T_6 * V_441 = V_12 -> V_442 . V_441 [ V_440 ] ;
int V_50 , V_19 ;
if ( ! F_398 ( V_2 ) || ! V_441 )
return 0 ;
V_19 = F_399 ( V_160 , V_443 / 4 * 3 ) ;
if ( V_19 )
return V_19 ;
for ( V_50 = 0 ; V_50 < V_443 / 4 ; V_50 ++ ) {
F_400 ( V_152 , F_401 ( 1 ) ) ;
F_402 ( V_152 , F_403 ( V_440 , V_50 ) ) ;
F_400 ( V_152 , V_441 [ V_50 ] ) ;
}
F_404 ( V_152 ) ;
return V_19 ;
}
void F_405 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
if ( F_151 ( V_2 ) -> V_176 < 5 ||
V_12 -> V_14 . V_444 == V_445 )
return;
F_406 ( V_446 , F_407 ( V_446 ) |
V_447 ) ;
if ( F_408 ( V_2 ) )
return;
F_406 ( V_448 , F_407 ( V_448 ) | V_449 ) ;
if ( F_409 ( V_2 ) )
F_406 ( V_450 , F_410 ( V_451 ) ) ;
else if ( F_411 ( V_2 ) )
F_406 ( V_450 , F_410 ( V_452 ) ) ;
else if ( F_412 ( V_2 ) )
F_406 ( V_453 , F_410 ( V_454 ) ) ;
else
F_413 () ;
}
static void F_414 ( struct V_1 * V_2 , T_6 V_8 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
F_406 ( F_415 ( V_8 ) , 0 ) ;
F_406 ( F_416 ( V_8 ) , 0 ) ;
F_406 ( F_417 ( V_8 ) , 0 ) ;
F_406 ( F_418 ( V_8 ) , 0 ) ;
}
static void F_419 ( struct V_1 * V_2 )
{
if ( F_420 ( V_2 ) ) {
F_414 ( V_2 , V_455 ) ;
F_414 ( V_2 , V_456 ) ;
F_414 ( V_2 , V_457 ) ;
F_414 ( V_2 , V_458 ) ;
F_414 ( V_2 , V_459 ) ;
} else if ( F_421 ( V_2 ) ) {
F_414 ( V_2 , V_456 ) ;
F_414 ( V_2 , V_457 ) ;
} else if ( F_422 ( V_2 ) ) {
F_414 ( V_2 , V_455 ) ;
F_414 ( V_2 , V_460 ) ;
}
}
int F_423 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 ;
V_19 = F_424 ( V_2 ) ;
if ( V_19 )
return V_19 ;
if ( F_425 ( V_2 ) ) {
V_19 = F_426 ( V_2 ) ;
if ( V_19 )
goto V_461;
}
if ( F_427 ( V_2 ) ) {
V_19 = F_428 ( V_2 ) ;
if ( V_19 )
goto V_462;
}
if ( F_429 ( V_2 ) ) {
V_19 = F_430 ( V_2 ) ;
if ( V_19 )
goto V_463;
}
if ( F_431 ( V_2 ) ) {
V_19 = F_432 ( V_2 ) ;
if ( V_19 )
goto V_464;
}
return 0 ;
V_464:
F_433 ( & V_12 -> V_152 [ V_465 ] ) ;
V_463:
F_433 ( & V_12 -> V_152 [ V_466 ] ) ;
V_462:
F_433 ( & V_12 -> V_152 [ V_467 ] ) ;
V_461:
F_433 ( & V_12 -> V_152 [ V_468 ] ) ;
return V_19 ;
}
int
F_434 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_151 * V_152 ;
int V_19 , V_469 ;
F_435 ( V_12 , V_470 ) ;
if ( F_436 ( V_2 ) && F_437 ( V_12 ) < 9 )
F_406 ( V_471 , F_407 ( V_471 ) | F_438 ( 0xf ) ) ;
if ( F_439 ( V_2 ) )
F_406 ( V_472 , F_440 ( V_2 ) ?
V_473 : V_474 ) ;
if ( F_441 ( V_2 ) ) {
if ( F_442 ( V_2 ) ) {
T_6 V_475 = F_407 ( V_476 ) ;
V_475 &= ~ ( V_477 | V_478 ) ;
F_406 ( V_476 , V_475 ) ;
} else if ( F_151 ( V_2 ) -> V_176 >= 7 ) {
T_6 V_475 = F_407 ( V_479 ) ;
V_475 &= ~ V_480 ;
F_406 ( V_479 , V_475 ) ;
}
}
F_405 ( V_2 ) ;
F_419 ( V_2 ) ;
F_38 ( ! V_12 -> V_320 ) ;
V_19 = F_443 ( V_2 ) ;
if ( V_19 ) {
F_11 ( L_20 , V_19 ) ;
goto V_84;
}
F_260 (engine, dev_priv) {
V_19 = V_152 -> V_481 ( V_152 ) ;
if ( V_19 )
goto V_84;
}
F_444 ( V_2 ) ;
if ( F_445 ( V_2 ) ) {
V_19 = F_446 ( V_2 ) ;
if ( V_19 ) {
F_11 ( L_21 , V_19 ) ;
V_19 = - V_22 ;
goto V_84;
}
}
V_19 = F_264 ( V_2 , V_12 -> V_290 + 0x100 ) ;
if ( V_19 )
goto V_84;
F_260 (engine, dev_priv) {
struct V_159 * V_160 ;
V_160 = F_296 ( V_152 , NULL ) ;
if ( F_25 ( V_160 ) ) {
V_19 = F_26 ( V_160 ) ;
break;
}
if ( V_152 -> V_153 == V_468 ) {
for ( V_469 = 0 ; V_469 < F_447 ( V_2 ) ; V_469 ++ ) {
V_19 = F_397 ( V_160 , V_469 ) ;
if ( V_19 )
goto V_482;
}
}
V_19 = F_448 ( V_160 ) ;
if ( V_19 )
goto V_482;
V_19 = F_449 ( V_160 ) ;
if ( V_19 )
goto V_482;
V_482:
F_337 ( V_160 ) ;
if ( V_19 ) {
F_11 ( L_22 ,
V_152 -> V_483 , V_19 ) ;
F_450 ( V_2 ) ;
break;
}
}
V_84:
F_451 ( V_12 , V_470 ) ;
return V_19 ;
}
int F_452 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_19 ;
V_118 . V_295 = F_453 ( V_2 ,
V_118 . V_295 ) ;
F_18 ( & V_2 -> V_25 ) ;
if ( ! V_118 . V_295 ) {
V_12 -> V_437 . V_484 = V_485 ;
V_12 -> V_437 . V_486 = F_423 ;
V_12 -> V_437 . V_487 = F_433 ;
V_12 -> V_437 . V_438 = V_488 ;
} else {
V_12 -> V_437 . V_484 = V_489 ;
V_12 -> V_437 . V_486 = V_490 ;
V_12 -> V_437 . V_487 = V_491 ;
V_12 -> V_437 . V_438 = V_492 ;
}
F_435 ( V_12 , V_470 ) ;
V_19 = F_454 ( V_2 ) ;
if ( V_19 )
goto V_493;
F_455 ( V_2 ) ;
V_19 = F_456 ( V_2 ) ;
if ( V_19 )
goto V_493;
V_19 = V_12 -> V_437 . V_486 ( V_2 ) ;
if ( V_19 )
goto V_493;
V_19 = F_434 ( V_2 ) ;
if ( V_19 == - V_22 ) {
F_11 ( L_23 ) ;
F_457 ( V_494 , & V_12 -> V_24 . V_147 ) ;
V_19 = 0 ;
}
V_493:
F_451 ( V_12 , V_470 ) ;
F_20 ( & V_2 -> V_25 ) ;
return V_19 ;
}
void
F_450 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
struct V_151 * V_152 ;
F_260 (engine, dev_priv)
V_12 -> V_437 . V_487 ( V_152 ) ;
if ( V_118 . V_295 )
F_458 ( V_2 , V_495 ) ;
}
static void
F_459 ( struct V_151 * V_152 )
{
F_378 ( & V_152 -> V_282 ) ;
F_378 ( & V_152 -> V_192 ) ;
}
void
F_460 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
if ( F_151 ( V_12 ) -> V_176 >= 7 && ! F_461 ( V_12 ) &&
! F_462 ( V_12 ) )
V_12 -> V_496 = 32 ;
else if ( F_151 ( V_12 ) -> V_176 >= 4 || F_463 ( V_12 ) ||
F_464 ( V_12 ) || F_217 ( V_12 ) )
V_12 -> V_496 = 16 ;
else
V_12 -> V_496 = 8 ;
if ( F_465 ( V_2 ) )
V_12 -> V_496 =
F_407 ( F_466 ( V_497 . V_498 ) ) ;
F_309 ( V_2 ) ;
F_467 ( V_2 ) ;
}
void
F_468 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
int V_50 ;
V_12 -> V_85 =
F_469 ( L_24 ,
sizeof( struct V_6 ) , 0 ,
V_499 ,
NULL ) ;
V_12 -> V_436 =
F_469 ( L_25 ,
sizeof( struct V_32 ) , 0 ,
V_499 ,
NULL ) ;
V_12 -> V_205 =
F_469 ( L_26 ,
sizeof( struct V_159 ) , 0 ,
V_499 ,
NULL ) ;
F_378 ( & V_12 -> V_500 ) ;
F_378 ( & V_12 -> V_501 ) ;
F_378 ( & V_12 -> V_14 . V_276 ) ;
F_378 ( & V_12 -> V_14 . V_286 ) ;
F_378 ( & V_12 -> V_14 . V_502 ) ;
for ( V_50 = 0 ; V_50 < V_203 ; V_50 ++ )
F_459 ( & V_12 -> V_152 [ V_50 ] ) ;
for ( V_50 = 0 ; V_50 < V_503 ; V_50 ++ )
F_378 ( & V_12 -> V_504 [ V_50 ] . V_505 ) ;
F_470 ( & V_12 -> V_14 . V_304 ,
F_313 ) ;
F_470 ( & V_12 -> V_14 . V_334 ,
F_315 ) ;
F_471 ( & V_12 -> V_24 . V_20 ) ;
V_12 -> V_506 = V_507 ;
V_12 -> V_290 = ( ( T_6 ) ~ 0 - 0x1100 ) ;
V_12 -> V_291 = ( ( T_6 ) ~ 0 - 0x1101 ) ;
F_378 ( & V_12 -> V_14 . V_502 ) ;
F_471 ( & V_12 -> V_508 ) ;
V_12 -> V_14 . V_148 = true ;
F_472 ( & V_12 -> V_509 . V_190 ) ;
}
void F_473 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_17 ( V_2 ) ;
F_474 ( V_12 -> V_205 ) ;
F_474 ( V_12 -> V_436 ) ;
F_474 ( V_12 -> V_85 ) ;
}
void F_475 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_188 * V_79 = V_28 -> V_189 ;
F_5 ( & V_79 -> V_14 . V_190 ) ;
while ( ! F_148 ( & V_79 -> V_14 . V_192 ) ) {
struct V_159 * V_194 ;
V_194 = F_178 ( & V_79 -> V_14 . V_192 ,
struct V_159 ,
V_191 ) ;
F_170 ( & V_194 -> V_191 ) ;
V_194 -> V_79 = NULL ;
}
F_6 ( & V_79 -> V_14 . V_190 ) ;
if ( ! F_148 ( & V_79 -> V_165 . V_510 ) ) {
F_5 ( & F_17 ( V_2 ) -> V_165 . V_511 ) ;
F_170 ( & V_79 -> V_165 . V_510 ) ;
F_6 ( & F_17 ( V_2 ) -> V_165 . V_511 ) ;
}
}
int F_476 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_188 * V_79 ;
int V_19 ;
F_477 ( L_27 ) ;
V_79 = F_478 ( sizeof( * V_79 ) , V_55 ) ;
if ( ! V_79 )
return - V_56 ;
V_28 -> V_189 = V_79 ;
V_79 -> V_12 = V_2 -> V_23 ;
V_79 -> V_28 = V_28 ;
F_378 ( & V_79 -> V_165 . V_510 ) ;
F_479 ( & V_79 -> V_14 . V_190 ) ;
F_378 ( & V_79 -> V_14 . V_192 ) ;
V_79 -> V_512 = - 1 ;
V_19 = F_480 ( V_2 , V_28 ) ;
if ( V_19 )
F_34 ( V_79 ) ;
return V_19 ;
}
void F_481 ( struct V_6 * V_513 ,
struct V_6 * V_514 ,
unsigned V_431 )
{
if ( V_513 ) {
F_14 ( ! F_181 ( & V_513 -> V_8 . V_2 -> V_25 ) ) ;
F_14 ( ! ( V_513 -> V_431 & V_431 ) ) ;
V_513 -> V_431 &= ~ V_431 ;
}
if ( V_514 ) {
F_14 ( ! F_181 ( & V_514 -> V_8 . V_2 -> V_25 ) ) ;
F_14 ( V_514 -> V_431 & V_431 ) ;
V_514 -> V_431 |= V_431 ;
}
}
T_14 F_482 ( struct V_6 * V_515 ,
struct V_371 * V_284 )
{
struct V_11 * V_12 = V_515 -> V_8 . V_2 -> V_23 ;
struct V_32 * V_33 ;
F_14 ( V_284 == & V_12 -> V_14 . V_410 -> V_8 ) ;
F_19 (vma, &o->vma_list, obj_link) {
if ( V_33 -> V_355 &&
V_33 -> V_356 . type != V_357 )
continue;
if ( V_33 -> V_284 == V_284 )
return V_33 -> V_36 . V_109 ;
}
F_146 ( 1 , L_28 ,
F_341 ( V_284 ) ? L_29 : L_19 ) ;
return - 1 ;
}
T_14 F_206 ( struct V_6 * V_515 ,
const struct V_230 * V_231 )
{
struct V_11 * V_12 = F_17 ( V_515 -> V_8 . V_2 ) ;
struct V_29 * V_30 = & V_12 -> V_30 ;
struct V_32 * V_33 ;
F_19 (vma, &o->vma_list, obj_link)
if ( V_33 -> V_284 == & V_30 -> V_8 &&
F_390 ( & V_33 -> V_356 , V_231 ) )
return V_33 -> V_36 . V_109 ;
F_146 ( 1 , L_30 , V_231 -> type ) ;
return - 1 ;
}
bool F_483 ( struct V_6 * V_515 ,
struct V_371 * V_284 )
{
struct V_32 * V_33 ;
F_19 (vma, &o->vma_list, obj_link) {
if ( V_33 -> V_355 &&
V_33 -> V_356 . type != V_357 )
continue;
if ( V_33 -> V_284 == V_284 && F_330 ( & V_33 -> V_36 ) )
return true ;
}
return false ;
}
bool F_372 ( struct V_6 * V_515 ,
const struct V_230 * V_231 )
{
struct V_11 * V_12 = F_17 ( V_515 -> V_8 . V_2 ) ;
struct V_29 * V_30 = & V_12 -> V_30 ;
struct V_32 * V_33 ;
F_19 (vma, &o->vma_list, obj_link)
if ( V_33 -> V_284 == & V_30 -> V_8 &&
F_390 ( & V_33 -> V_356 , V_231 ) &&
F_330 ( & V_33 -> V_36 ) )
return true ;
return false ;
}
bool F_235 ( struct V_6 * V_515 )
{
struct V_32 * V_33 ;
F_19 (vma, &o->vma_list, obj_link)
if ( F_330 ( & V_33 -> V_36 ) )
return true ;
return false ;
}
unsigned long F_484 ( struct V_6 * V_515 ,
struct V_371 * V_284 )
{
struct V_11 * V_12 = V_515 -> V_8 . V_2 -> V_23 ;
struct V_32 * V_33 ;
F_14 ( V_284 == & V_12 -> V_14 . V_410 -> V_8 ) ;
F_38 ( F_148 ( & V_515 -> V_361 ) ) ;
F_19 (vma, &o->vma_list, obj_link) {
if ( V_33 -> V_355 &&
V_33 -> V_356 . type != V_357 )
continue;
if ( V_33 -> V_284 == V_284 )
return V_33 -> V_36 . V_13 ;
}
return 0 ;
}
bool F_376 ( struct V_6 * V_7 )
{
struct V_32 * V_33 ;
F_19 (vma, &obj->vma_list, obj_link)
if ( V_33 -> V_35 > 0 )
return true ;
return false ;
}
struct V_53 *
F_485 ( struct V_6 * V_7 , int V_206 )
{
struct V_53 * V_53 ;
if ( F_14 ( ( V_7 -> V_76 -> V_102 & V_103 ) == 0 ) )
return NULL ;
V_53 = F_486 ( V_7 , V_206 ) ;
F_40 ( V_53 ) ;
return V_53 ;
}
struct V_6 *
F_487 ( struct V_1 * V_2 ,
const void * V_26 , T_1 V_13 )
{
struct V_6 * V_7 ;
struct V_46 * V_49 ;
T_1 V_516 ;
int V_19 ;
V_7 = F_67 ( V_2 , F_86 ( V_13 , V_52 ) ) ;
if ( F_488 ( V_7 ) )
return V_7 ;
V_19 = F_39 ( V_7 , true ) ;
if ( V_19 )
goto V_517;
V_19 = F_53 ( V_7 ) ;
if ( V_19 )
goto V_517;
F_80 ( V_7 ) ;
V_49 = V_7 -> V_61 ;
V_516 = F_489 ( V_49 -> V_57 , V_49 -> V_270 , ( void * ) V_26 , V_13 ) ;
V_7 -> V_68 = 1 ;
F_97 ( V_7 ) ;
if ( F_14 ( V_516 != V_13 ) ) {
F_11 ( L_31 , V_516 , V_13 ) ;
V_19 = - V_75 ;
goto V_517;
}
return V_7 ;
V_517:
F_50 ( & V_7 -> V_8 ) ;
return F_251 ( V_19 ) ;
}

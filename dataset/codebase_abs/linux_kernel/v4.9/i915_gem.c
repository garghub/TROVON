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
return 0 ;
}
int
F_19 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_37 * V_18 = & V_23 -> V_18 ;
struct V_38 * args = V_34 ;
struct V_39 * V_40 ;
T_2 V_41 ;
V_41 = 0 ;
F_20 ( & V_2 -> V_33 ) ;
F_21 (vma, &ggtt->base.active_list, vm_link)
if ( F_22 ( V_40 ) )
V_41 += V_40 -> V_16 . V_17 ;
F_21 (vma, &ggtt->base.inactive_list, vm_link)
if ( F_22 ( V_40 ) )
V_41 += V_40 -> V_16 . V_17 ;
F_23 ( & V_2 -> V_33 ) ;
args -> V_42 = V_18 -> V_8 . V_43 ;
args -> V_44 = args -> V_42 - V_41 ;
return 0 ;
}
static int
F_24 ( struct V_6 * V_7 )
{
struct V_45 * V_46 = V_7 -> V_8 . V_47 -> V_48 ;
char * V_49 = V_7 -> V_50 -> V_49 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
int V_55 ;
if ( F_25 ( F_26 ( V_7 ) ) )
return - V_56 ;
for ( V_55 = 0 ; V_55 < V_7 -> V_8 . V_17 / V_57 ; V_55 ++ ) {
struct V_58 * V_58 ;
char * V_59 ;
V_58 = F_27 ( V_46 , V_55 ) ;
if ( F_28 ( V_58 ) )
return F_29 ( V_58 ) ;
V_59 = F_30 ( V_58 ) ;
memcpy ( V_49 , V_59 , V_57 ) ;
F_31 ( V_49 , V_57 ) ;
F_32 ( V_59 ) ;
F_33 ( V_58 ) ;
V_49 += V_57 ;
}
F_34 ( F_17 ( V_7 -> V_8 . V_2 ) ) ;
V_52 = F_35 ( sizeof( * V_52 ) , V_60 ) ;
if ( V_52 == NULL )
return - V_61 ;
if ( F_36 ( V_52 , 1 , V_60 ) ) {
F_37 ( V_52 ) ;
return - V_61 ;
}
V_54 = V_52 -> V_62 ;
V_54 -> V_63 = 0 ;
V_54 -> V_64 = V_7 -> V_8 . V_17 ;
F_38 ( V_54 ) = V_7 -> V_50 -> V_65 ;
F_39 ( V_54 ) = V_7 -> V_8 . V_17 ;
V_7 -> V_66 = V_52 ;
return 0 ;
}
static void
F_40 ( struct V_6 * V_7 )
{
int V_28 ;
F_41 ( V_7 -> V_67 == V_68 ) ;
V_28 = F_42 ( V_7 , true ) ;
if ( F_25 ( V_28 ) ) {
V_7 -> V_8 . V_69 = V_7 -> V_8 . V_9 = V_10 ;
}
if ( V_7 -> V_67 == V_70 )
V_7 -> V_71 = 0 ;
if ( V_7 -> V_71 ) {
struct V_45 * V_46 = V_7 -> V_8 . V_47 -> V_48 ;
char * V_49 = V_7 -> V_50 -> V_49 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_7 -> V_8 . V_17 / V_57 ; V_55 ++ ) {
struct V_58 * V_58 ;
char * V_72 ;
V_58 = F_27 ( V_46 , V_55 ) ;
if ( F_28 ( V_58 ) )
continue;
V_72 = F_30 ( V_58 ) ;
F_31 ( V_49 , V_57 ) ;
memcpy ( V_72 , V_49 , V_57 ) ;
F_32 ( V_72 ) ;
F_43 ( V_58 ) ;
if ( V_7 -> V_67 == V_73 )
F_44 ( V_58 ) ;
F_33 ( V_58 ) ;
V_49 += V_57 ;
}
V_7 -> V_71 = 0 ;
}
F_45 ( V_7 -> V_66 ) ;
F_37 ( V_7 -> V_66 ) ;
}
static void
F_46 ( struct V_6 * V_7 )
{
F_47 ( V_7 -> V_8 . V_2 , V_7 -> V_50 ) ;
}
int F_48 ( struct V_6 * V_7 )
{
struct V_39 * V_40 ;
F_49 ( V_74 ) ;
int V_28 ;
F_50 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
V_28 = F_51 ( V_7 , false ) ;
if ( V_28 )
return V_28 ;
F_52 ( F_17 ( V_7 -> V_8 . V_2 ) ) ;
while ( ( V_40 = F_53 ( & V_7 -> V_75 ,
struct V_39 ,
V_76 ) ) ) {
F_54 ( & V_40 -> V_76 , & V_74 ) ;
V_28 = F_55 ( V_40 ) ;
if ( V_28 )
break;
}
F_56 ( & V_74 , & V_7 -> V_75 ) ;
return V_28 ;
}
int
F_51 ( struct V_6 * V_7 ,
bool V_77 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
unsigned long V_82 ;
int V_83 ;
F_50 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
if ( ! V_77 ) {
V_81 = V_7 -> V_84 ;
V_82 = F_57 ( V_7 ) ;
} else {
V_82 = 1 ;
V_81 = & V_7 -> V_85 ;
}
F_58 (active_mask, idx) {
int V_28 ;
V_28 = F_59 ( & V_81 [ V_83 ] ,
& V_7 -> V_8 . V_2 -> V_33 ) ;
if ( V_28 )
return V_28 ;
}
V_79 = F_60 ( V_7 ) ;
if ( V_79 ) {
long V_86 ;
V_86 = F_61 ( V_79 , ! V_77 , true ,
V_87 ) ;
if ( V_86 < 0 )
return V_86 ;
}
return 0 ;
}
static T_3 int
F_62 ( struct V_6 * V_7 ,
struct V_88 * V_89 ,
bool V_77 )
{
struct V_80 * V_81 ;
unsigned long V_82 ;
int V_83 ;
V_82 = F_63 ( V_7 ) ;
if ( ! V_82 )
return 0 ;
if ( ! V_77 ) {
V_81 = V_7 -> V_84 ;
} else {
V_82 = 1 ;
V_81 = & V_7 -> V_85 ;
}
F_58 (active_mask, idx) {
int V_28 ;
V_28 = F_64 ( & V_81 [ V_83 ] ,
V_90 ,
NULL , V_89 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
static struct V_88 * F_65 ( struct V_35 * V_36 )
{
struct V_91 * V_92 = V_36 -> V_93 ;
return & V_92 -> V_89 ;
}
int
F_66 ( struct V_6 * V_7 ,
int V_94 )
{
T_4 * V_95 ;
int V_28 ;
if ( V_7 -> V_50 ) {
if ( ( unsigned long ) V_7 -> V_50 -> V_49 & ( V_94 - 1 ) )
return - V_96 ;
return 0 ;
}
if ( V_7 -> V_67 != V_73 )
return - V_97 ;
if ( V_7 -> V_8 . V_47 == NULL )
return - V_56 ;
V_28 = F_48 ( V_7 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_67 ( V_7 ) ;
if ( V_28 )
return V_28 ;
V_95 = F_68 ( V_7 -> V_8 . V_2 , V_7 -> V_8 . V_17 , V_94 ) ;
if ( ! V_95 )
return - V_61 ;
V_7 -> V_50 = V_95 ;
V_7 -> V_98 = & V_99 ;
return F_69 ( V_7 ) ;
}
static int
F_70 ( struct V_6 * V_7 ,
struct V_100 * args ,
struct V_35 * V_101 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
void * V_49 = V_7 -> V_50 -> V_49 + args -> V_63 ;
char T_5 * V_102 = F_71 ( args -> V_103 ) ;
int V_28 = 0 ;
V_28 = F_51 ( V_7 , false ) ;
if ( V_28 )
return V_28 ;
F_72 ( V_7 , V_104 ) ;
if ( F_73 ( V_49 , V_102 , args -> V_17 ) ) {
unsigned long V_105 ;
F_23 ( & V_2 -> V_33 ) ;
V_105 = F_74 ( V_49 , V_102 , args -> V_17 ) ;
F_20 ( & V_2 -> V_33 ) ;
if ( V_105 ) {
V_28 = - V_97 ;
goto V_106;
}
}
F_31 ( V_49 , args -> V_17 ) ;
F_34 ( F_17 ( V_2 ) ) ;
V_106:
F_75 ( V_7 , false , V_104 ) ;
return V_28 ;
}
void * F_76 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
return F_77 ( V_23 -> V_107 , V_60 ) ;
}
void F_78 ( struct V_6 * V_7 )
{
struct V_13 * V_23 = F_17 ( V_7 -> V_8 . V_2 ) ;
F_79 ( V_23 -> V_107 , V_7 ) ;
}
static int
F_80 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
T_6 V_17 ,
T_7 * V_108 )
{
struct V_6 * V_7 ;
int V_28 ;
T_1 V_109 ;
V_17 = F_81 ( V_17 , V_57 ) ;
if ( V_17 == 0 )
return - V_56 ;
V_7 = F_82 ( V_2 , V_17 ) ;
if ( F_28 ( V_7 ) )
return F_29 ( V_7 ) ;
V_28 = F_83 ( V_36 , & V_7 -> V_8 , & V_109 ) ;
F_84 ( V_7 ) ;
if ( V_28 )
return V_28 ;
* V_108 = V_109 ;
return 0 ;
}
int
F_85 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
struct V_110 * args )
{
args -> V_111 = F_86 ( args -> V_112 * F_87 ( args -> V_113 , 8 ) , 64 ) ;
args -> V_17 = args -> V_111 * args -> V_114 ;
return F_80 ( V_36 , V_2 ,
args -> V_17 , & args -> V_109 ) ;
}
int
F_88 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_115 * args = V_34 ;
return F_80 ( V_36 , V_2 ,
args -> V_17 , & args -> V_109 ) ;
}
static inline int
F_89 ( char T_5 * V_116 ,
const char * V_117 , int V_118 ,
int V_64 )
{
int V_28 , V_119 = 0 ;
while ( V_64 > 0 ) {
int V_120 = F_86 ( V_118 + 1 , 64 ) ;
int V_121 = F_90 ( V_120 - V_118 , V_64 ) ;
int V_122 = V_118 ^ 64 ;
V_28 = F_91 ( V_116 + V_119 ,
V_117 + V_122 ,
V_121 ) ;
if ( V_28 )
return V_28 + V_64 ;
V_119 += V_121 ;
V_118 += V_121 ;
V_64 -= V_121 ;
}
return 0 ;
}
static inline int
F_92 ( char * V_117 , int V_118 ,
const char T_5 * V_116 ,
int V_64 )
{
int V_28 , V_119 = 0 ;
while ( V_64 > 0 ) {
int V_120 = F_86 ( V_118 + 1 , 64 ) ;
int V_121 = F_90 ( V_120 - V_118 , V_64 ) ;
int V_122 = V_118 ^ 64 ;
V_28 = F_93 ( V_117 + V_122 ,
V_116 + V_119 ,
V_121 ) ;
if ( V_28 )
return V_28 + V_64 ;
V_119 += V_121 ;
V_118 += V_121 ;
V_64 -= V_121 ;
}
return 0 ;
}
int F_94 ( struct V_6 * V_7 ,
unsigned int * V_123 )
{
int V_28 ;
* V_123 = 0 ;
if ( ! F_95 ( V_7 ) )
return - V_124 ;
V_28 = F_51 ( V_7 , true ) ;
if ( V_28 )
return V_28 ;
V_28 = F_69 ( V_7 ) ;
if ( V_28 )
return V_28 ;
F_96 ( V_7 ) ;
F_97 ( V_7 ) ;
if ( ! ( V_7 -> V_8 . V_69 & V_10 ) )
* V_123 = ! F_1 ( V_7 -> V_8 . V_2 ,
V_7 -> V_11 ) ;
if ( * V_123 && ! F_98 ( V_125 ) ) {
V_28 = F_42 ( V_7 , false ) ;
if ( V_28 )
goto V_126;
* V_123 = 0 ;
}
return 0 ;
V_126:
F_99 ( V_7 ) ;
return V_28 ;
}
int F_100 ( struct V_6 * V_7 ,
unsigned int * V_123 )
{
int V_28 ;
* V_123 = 0 ;
if ( ! F_95 ( V_7 ) )
return - V_124 ;
V_28 = F_51 ( V_7 , false ) ;
if ( V_28 )
return V_28 ;
V_28 = F_69 ( V_7 ) ;
if ( V_28 )
return V_28 ;
F_96 ( V_7 ) ;
F_97 ( V_7 ) ;
if ( V_7 -> V_8 . V_9 != V_10 )
* V_123 |= F_3 ( V_7 ) << 1 ;
if ( ! ( V_7 -> V_8 . V_69 & V_10 ) )
* V_123 |= ! F_1 ( V_7 -> V_8 . V_2 ,
V_7 -> V_11 ) ;
if ( * V_123 && ! F_98 ( V_125 ) ) {
V_28 = F_42 ( V_7 , true ) ;
if ( V_28 )
goto V_126;
* V_123 = 0 ;
}
if ( ( * V_123 & V_127 ) == 0 )
V_7 -> V_128 = true ;
F_72 ( V_7 , V_104 ) ;
V_7 -> V_71 = 1 ;
return 0 ;
V_126:
F_99 ( V_7 ) ;
return V_28 ;
}
static int
F_101 ( struct V_58 * V_58 , int V_129 , int V_130 ,
char T_5 * V_102 ,
bool V_131 , bool V_123 )
{
char * V_49 ;
int V_28 ;
if ( F_102 ( V_131 ) )
return - V_56 ;
V_49 = F_30 ( V_58 ) ;
if ( V_123 )
F_31 ( V_49 + V_129 ,
V_130 ) ;
V_28 = F_103 ( V_102 ,
V_49 + V_129 ,
V_130 ) ;
F_32 ( V_49 ) ;
return V_28 ? - V_97 : 0 ;
}
static void
F_104 ( char * V_132 , unsigned long V_64 ,
bool V_133 )
{
if ( F_102 ( V_133 ) ) {
unsigned long V_134 = ( unsigned long ) V_132 ;
unsigned long V_135 = ( unsigned long ) V_132 + V_64 ;
V_134 = F_105 ( V_134 , 128 ) ;
V_135 = F_106 ( V_135 , 128 ) ;
F_31 ( ( void * ) V_134 , V_135 - V_134 ) ;
} else {
F_31 ( V_132 , V_64 ) ;
}
}
static int
F_107 ( struct V_58 * V_58 , int V_129 , int V_130 ,
char T_5 * V_102 ,
bool V_131 , bool V_123 )
{
char * V_49 ;
int V_28 ;
V_49 = F_108 ( V_58 ) ;
if ( V_123 )
F_104 ( V_49 + V_129 ,
V_130 ,
V_131 ) ;
if ( V_131 )
V_28 = F_89 ( V_102 ,
V_49 , V_129 ,
V_130 ) ;
else
V_28 = F_91 ( V_102 ,
V_49 + V_129 ,
V_130 ) ;
F_109 ( V_58 ) ;
return V_28 ? - V_97 : 0 ;
}
static inline unsigned long
F_110 ( struct V_136 * V_46 ,
T_6 V_137 , int V_138 ,
char T_5 * V_102 ,
unsigned long V_64 , bool V_139 )
{
void T_8 * V_140 ;
void * V_49 ;
T_6 V_105 ;
V_140 = F_111 ( V_46 , V_137 , V_57 ) ;
V_49 = ( void V_141 * ) V_140 + V_138 ;
if ( V_139 )
V_105 = F_93 ( V_49 , V_102 , V_64 ) ;
else
V_105 = F_91 ( V_102 , V_49 , V_64 ) ;
F_112 ( V_140 ) ;
return V_105 ;
}
static int
F_113 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_6 V_17 ,
T_6 V_142 , T_6 V_103 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_37 * V_18 = & V_23 -> V_18 ;
struct V_39 * V_40 ;
struct V_15 V_16 ;
char T_5 * V_102 ;
T_6 V_143 ;
T_6 V_63 ;
int V_28 ;
V_40 = F_114 ( V_7 , NULL , 0 , 0 , V_144 ) ;
if ( ! F_28 ( V_40 ) ) {
V_16 . V_134 = F_115 ( V_40 ) ;
V_16 . V_145 = false ;
V_28 = F_116 ( V_40 ) ;
if ( V_28 ) {
F_117 ( V_40 ) ;
V_40 = F_118 ( V_28 ) ;
}
}
if ( F_28 ( V_40 ) ) {
V_28 = F_4 ( V_23 , & V_16 , V_57 ) ;
if ( V_28 )
goto V_106;
V_28 = F_69 ( V_7 ) ;
if ( V_28 ) {
F_6 ( & V_16 ) ;
goto V_106;
}
F_96 ( V_7 ) ;
}
V_28 = F_119 ( V_7 , false ) ;
if ( V_28 )
goto V_146;
V_102 = F_71 ( V_103 ) ;
V_143 = V_17 ;
V_63 = V_142 ;
F_23 ( & V_2 -> V_33 ) ;
if ( F_120 ( ! V_14 . V_147 ) ) {
V_28 = F_121 ( V_102 , V_143 ) ;
if ( V_28 ) {
F_20 ( & V_2 -> V_33 ) ;
goto V_146;
}
}
while ( V_143 > 0 ) {
T_1 V_137 = V_16 . V_134 ;
unsigned V_138 = F_122 ( V_63 ) ;
unsigned V_130 = V_57 - V_138 ;
V_130 = V_143 < V_130 ? V_143 : V_130 ;
if ( V_16 . V_145 ) {
F_123 () ;
V_18 -> V_8 . V_148 ( & V_18 -> V_8 ,
F_124 ( V_7 , V_63 >> V_149 ) ,
V_16 . V_134 ,
V_5 , 0 ) ;
F_123 () ;
} else {
V_137 += V_63 & V_150 ;
}
if ( F_110 ( & V_18 -> V_151 , V_137 ,
V_138 , V_102 ,
V_130 , false ) ) {
V_28 = - V_97 ;
break;
}
V_143 -= V_130 ;
V_102 += V_130 ;
V_63 += V_130 ;
}
F_20 ( & V_2 -> V_33 ) ;
if ( V_28 == 0 && ( V_7 -> V_8 . V_69 & V_152 ) == 0 ) {
V_28 = F_119 ( V_7 , false ) ;
}
V_146:
if ( V_16 . V_145 ) {
F_123 () ;
V_18 -> V_8 . V_153 ( & V_18 -> V_8 ,
V_16 . V_134 , V_16 . V_17 ,
true ) ;
F_99 ( V_7 ) ;
F_6 ( & V_16 ) ;
} else {
F_117 ( V_40 ) ;
}
V_106:
return V_28 ;
}
static int
F_125 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_154 * args ,
struct V_35 * V_36 )
{
char T_5 * V_102 ;
T_9 V_143 ;
T_10 V_63 ;
int V_129 , V_130 , V_28 = 0 ;
int V_155 , V_131 ;
int V_156 = 0 ;
int V_123 = 0 ;
struct V_157 V_158 ;
V_28 = F_94 ( V_7 , & V_123 ) ;
if ( V_28 )
return V_28 ;
V_155 = F_26 ( V_7 ) ;
V_102 = F_71 ( args -> V_103 ) ;
V_63 = args -> V_63 ;
V_143 = args -> V_17 ;
F_126 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_58 * V_58 = F_127 ( & V_158 ) ;
if ( V_143 <= 0 )
break;
V_129 = F_122 ( V_63 ) ;
V_130 = V_143 ;
if ( ( V_129 + V_130 ) > V_57 )
V_130 = V_57 - V_129 ;
V_131 = V_155 &&
( F_128 ( V_58 ) & ( 1 << 17 ) ) != 0 ;
V_28 = F_101 ( V_58 , V_129 , V_130 ,
V_102 , V_131 ,
V_123 ) ;
if ( V_28 == 0 )
goto V_159;
F_23 ( & V_2 -> V_33 ) ;
if ( F_120 ( ! V_14 . V_147 ) && ! V_156 ) {
V_28 = F_121 ( V_102 , V_143 ) ;
( void ) V_28 ;
V_156 = 1 ;
}
V_28 = F_107 ( V_58 , V_129 , V_130 ,
V_102 , V_131 ,
V_123 ) ;
F_20 ( & V_2 -> V_33 ) ;
if ( V_28 )
goto V_106;
V_159:
V_143 -= V_130 ;
V_102 += V_130 ;
V_63 += V_130 ;
}
V_106:
F_129 ( V_7 ) ;
return V_28 ;
}
int
F_130 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_154 * args = V_34 ;
struct V_6 * V_7 ;
int V_28 = 0 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_131 ( V_160 ,
F_71 ( args -> V_103 ) ,
args -> V_17 ) )
return - V_97 ;
V_7 = F_132 ( V_36 , args -> V_109 ) ;
if ( ! V_7 )
return - V_161 ;
if ( args -> V_63 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_63 ) {
V_28 = - V_56 ;
goto V_86;
}
F_133 ( V_7 , args -> V_63 , args -> V_17 ) ;
V_28 = F_62 ( V_7 , F_65 ( V_36 ) , true ) ;
if ( V_28 )
goto V_86;
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
goto V_86;
V_28 = F_125 ( V_2 , V_7 , args , V_36 ) ;
if ( V_28 == - V_97 || V_28 == - V_124 ) {
F_134 ( F_17 ( V_2 ) ) ;
V_28 = F_113 ( V_2 , V_7 , args -> V_17 ,
args -> V_63 , args -> V_103 ) ;
F_135 ( F_17 ( V_2 ) ) ;
}
F_136 ( V_7 ) ;
F_23 ( & V_2 -> V_33 ) ;
return V_28 ;
V_86:
F_84 ( V_7 ) ;
return V_28 ;
}
static inline int
F_137 ( struct V_136 * V_46 ,
T_10 V_137 , int V_138 ,
char T_5 * V_102 ,
int V_64 )
{
void T_8 * V_162 ;
void * V_49 ;
unsigned long V_105 ;
V_162 = F_138 ( V_46 , V_137 ) ;
V_49 = ( void V_141 * ) V_162 + V_138 ;
V_105 = F_73 ( V_49 ,
V_102 , V_64 ) ;
F_139 ( V_162 ) ;
return V_105 ;
}
static int
F_140 ( struct V_13 * V_14 ,
struct V_6 * V_7 ,
struct V_100 * args ,
struct V_35 * V_36 )
{
struct V_37 * V_18 = & V_14 -> V_18 ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_39 * V_40 ;
struct V_15 V_16 ;
T_6 V_143 , V_63 ;
char T_5 * V_102 ;
int V_28 ;
bool V_163 = false ;
if ( F_141 ( V_7 ) )
return - V_97 ;
V_40 = F_114 ( V_7 , NULL , 0 , 0 ,
V_144 | V_164 ) ;
if ( ! F_28 ( V_40 ) ) {
V_16 . V_134 = F_115 ( V_40 ) ;
V_16 . V_145 = false ;
V_28 = F_116 ( V_40 ) ;
if ( V_28 ) {
F_117 ( V_40 ) ;
V_40 = F_118 ( V_28 ) ;
}
}
if ( F_28 ( V_40 ) ) {
V_28 = F_4 ( V_14 , & V_16 , V_57 ) ;
if ( V_28 )
goto V_106;
V_28 = F_69 ( V_7 ) ;
if ( V_28 ) {
F_6 ( & V_16 ) ;
goto V_106;
}
F_96 ( V_7 ) ;
}
V_28 = F_119 ( V_7 , true ) ;
if ( V_28 )
goto V_146;
F_72 ( V_7 , V_104 ) ;
V_7 -> V_71 = true ;
V_102 = F_71 ( args -> V_103 ) ;
V_63 = args -> V_63 ;
V_143 = args -> V_17 ;
while ( V_143 ) {
T_1 V_137 = V_16 . V_134 ;
unsigned V_138 = F_122 ( V_63 ) ;
unsigned V_130 = V_57 - V_138 ;
V_130 = V_143 < V_130 ? V_143 : V_130 ;
if ( V_16 . V_145 ) {
F_123 () ;
V_18 -> V_8 . V_148 ( & V_18 -> V_8 ,
F_124 ( V_7 , V_63 >> V_149 ) ,
V_16 . V_134 , V_5 , 0 ) ;
F_123 () ;
} else {
V_137 += V_63 & V_150 ;
}
if ( F_137 ( & V_18 -> V_151 , V_137 ,
V_138 , V_102 , V_130 ) ) {
V_163 = true ;
F_23 ( & V_2 -> V_33 ) ;
if ( F_110 ( & V_18 -> V_151 ,
V_137 ,
V_138 , V_102 ,
V_130 , true ) ) {
V_28 = - V_97 ;
F_20 ( & V_2 -> V_33 ) ;
goto V_165;
}
F_20 ( & V_2 -> V_33 ) ;
}
V_143 -= V_130 ;
V_102 += V_130 ;
V_63 += V_130 ;
}
V_165:
if ( V_163 ) {
if ( V_28 == 0 &&
( V_7 -> V_8 . V_69 & V_152 ) == 0 ) {
V_28 = F_119 ( V_7 , false ) ;
}
}
F_75 ( V_7 , false , V_104 ) ;
V_146:
if ( V_16 . V_145 ) {
F_123 () ;
V_18 -> V_8 . V_153 ( & V_18 -> V_8 ,
V_16 . V_134 , V_16 . V_17 ,
true ) ;
F_99 ( V_7 ) ;
F_6 ( & V_16 ) ;
} else {
F_117 ( V_40 ) ;
}
V_106:
return V_28 ;
}
static int
F_142 ( struct V_58 * V_58 , int V_129 , int V_130 ,
char T_5 * V_102 ,
bool V_131 ,
bool V_166 ,
bool V_167 )
{
char * V_49 ;
int V_28 ;
if ( F_102 ( V_131 ) )
return - V_56 ;
V_49 = F_30 ( V_58 ) ;
if ( V_166 )
F_31 ( V_49 + V_129 ,
V_130 ) ;
V_28 = F_143 ( V_49 + V_129 ,
V_102 , V_130 ) ;
if ( V_167 )
F_31 ( V_49 + V_129 ,
V_130 ) ;
F_32 ( V_49 ) ;
return V_28 ? - V_97 : 0 ;
}
static int
F_144 ( struct V_58 * V_58 , int V_129 , int V_130 ,
char T_5 * V_102 ,
bool V_131 ,
bool V_166 ,
bool V_167 )
{
char * V_49 ;
int V_28 ;
V_49 = F_108 ( V_58 ) ;
if ( F_102 ( V_166 || V_131 ) )
F_104 ( V_49 + V_129 ,
V_130 ,
V_131 ) ;
if ( V_131 )
V_28 = F_92 ( V_49 , V_129 ,
V_102 ,
V_130 ) ;
else
V_28 = F_93 ( V_49 + V_129 ,
V_102 ,
V_130 ) ;
if ( V_167 )
F_104 ( V_49 + V_129 ,
V_130 ,
V_131 ) ;
F_109 ( V_58 ) ;
return V_28 ? - V_97 : 0 ;
}
static int
F_145 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_100 * args ,
struct V_35 * V_36 )
{
T_9 V_143 ;
T_10 V_63 ;
char T_5 * V_102 ;
int V_129 , V_130 , V_28 = 0 ;
int V_155 , V_131 ;
int V_168 = 0 ;
unsigned int V_123 ;
struct V_157 V_158 ;
V_28 = F_100 ( V_7 , & V_123 ) ;
if ( V_28 )
return V_28 ;
V_155 = F_26 ( V_7 ) ;
V_102 = F_71 ( args -> V_103 ) ;
V_63 = args -> V_63 ;
V_143 = args -> V_17 ;
F_126 (obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct V_58 * V_58 = F_127 ( & V_158 ) ;
int V_169 ;
if ( V_143 <= 0 )
break;
V_129 = F_122 ( V_63 ) ;
V_130 = V_143 ;
if ( ( V_129 + V_130 ) > V_57 )
V_130 = V_57 - V_129 ;
V_169 = V_123 & V_170 &&
( ( V_129 | V_130 )
& ( V_171 . V_172 - 1 ) ) ;
V_131 = V_155 &&
( F_128 ( V_58 ) & ( 1 << 17 ) ) != 0 ;
V_28 = F_142 ( V_58 , V_129 , V_130 ,
V_102 , V_131 ,
V_169 ,
V_123 & V_127 ) ;
if ( V_28 == 0 )
goto V_159;
V_168 = 1 ;
F_23 ( & V_2 -> V_33 ) ;
V_28 = F_144 ( V_58 , V_129 , V_130 ,
V_102 , V_131 ,
V_169 ,
V_123 & V_127 ) ;
F_20 ( & V_2 -> V_33 ) ;
if ( V_28 )
goto V_106;
V_159:
V_143 -= V_130 ;
V_102 += V_130 ;
V_63 += V_130 ;
}
V_106:
F_129 ( V_7 ) ;
if ( V_168 ) {
if ( ! ( V_123 & V_127 ) &&
V_7 -> V_8 . V_9 != V_10 ) {
if ( F_146 ( V_7 , V_7 -> V_12 ) )
V_123 |= V_127 ;
}
}
if ( V_123 & V_127 )
F_34 ( F_17 ( V_2 ) ) ;
F_75 ( V_7 , false , V_104 ) ;
return V_28 ;
}
int
F_147 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_100 * args = V_34 ;
struct V_6 * V_7 ;
int V_28 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_131 ( V_173 ,
F_71 ( args -> V_103 ) ,
args -> V_17 ) )
return - V_97 ;
if ( F_120 ( ! V_14 . V_147 ) ) {
V_28 = F_148 ( F_71 ( args -> V_103 ) ,
args -> V_17 ) ;
if ( V_28 )
return - V_97 ;
}
V_7 = F_132 ( V_36 , args -> V_109 ) ;
if ( ! V_7 )
return - V_161 ;
if ( args -> V_63 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_63 ) {
V_28 = - V_56 ;
goto V_86;
}
F_149 ( V_7 , args -> V_63 , args -> V_17 ) ;
V_28 = F_62 ( V_7 , F_65 ( V_36 ) , false ) ;
if ( V_28 )
goto V_86;
F_134 ( V_23 ) ;
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
goto V_174;
V_28 = - V_97 ;
if ( ! F_95 ( V_7 ) ||
F_3 ( V_7 ) ) {
V_28 = F_140 ( V_23 , V_7 , args , V_36 ) ;
}
if ( V_28 == - V_97 || V_28 == - V_175 ) {
if ( V_7 -> V_50 )
V_28 = F_70 ( V_7 , args , V_36 ) ;
else
V_28 = F_145 ( V_2 , V_7 , args , V_36 ) ;
}
F_136 ( V_7 ) ;
F_23 ( & V_2 -> V_33 ) ;
F_135 ( V_23 ) ;
return V_28 ;
V_174:
F_135 ( V_23 ) ;
V_86:
F_84 ( V_7 ) ;
return V_28 ;
}
static inline enum V_176
F_150 ( struct V_6 * V_7 , unsigned V_177 )
{
return ( V_177 == V_152 ?
V_7 -> V_178 : V_104 ) ;
}
int
F_151 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_179 * args = V_34 ;
struct V_6 * V_7 ;
T_7 V_69 = args -> V_69 ;
T_7 V_9 = args -> V_9 ;
int V_28 ;
if ( ( V_9 | V_69 ) & V_180 )
return - V_56 ;
if ( V_9 != 0 && V_69 != V_9 )
return - V_56 ;
V_7 = F_132 ( V_36 , args -> V_109 ) ;
if ( ! V_7 )
return - V_161 ;
V_28 = F_62 ( V_7 , F_65 ( V_36 ) , ! V_9 ) ;
if ( V_28 )
goto V_86;
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
goto V_86;
if ( V_69 & V_152 )
V_28 = F_119 ( V_7 , V_9 != 0 ) ;
else
V_28 = F_42 ( V_7 , V_9 != 0 ) ;
if ( V_9 != 0 )
F_72 ( V_7 , F_150 ( V_7 , V_9 ) ) ;
F_136 ( V_7 ) ;
F_23 ( & V_2 -> V_33 ) ;
return V_28 ;
V_86:
F_84 ( V_7 ) ;
return V_28 ;
}
int
F_152 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_181 * args = V_34 ;
struct V_6 * V_7 ;
int V_86 = 0 ;
V_7 = F_132 ( V_36 , args -> V_109 ) ;
if ( ! V_7 )
return - V_161 ;
if ( F_153 ( V_7 -> V_12 ) ) {
V_86 = F_16 ( V_2 ) ;
if ( ! V_86 ) {
F_154 ( V_7 ) ;
F_23 ( & V_2 -> V_33 ) ;
}
}
F_84 ( V_7 ) ;
return V_86 ;
}
int
F_155 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_182 * args = V_34 ;
struct V_6 * V_7 ;
unsigned long V_132 ;
if ( args -> V_183 & ~ ( V_184 ) )
return - V_56 ;
if ( args -> V_183 & V_184 && ! F_156 ( V_185 ) )
return - V_124 ;
V_7 = F_132 ( V_36 , args -> V_109 ) ;
if ( ! V_7 )
return - V_161 ;
if ( ! V_7 -> V_8 . V_47 ) {
F_84 ( V_7 ) ;
return - V_56 ;
}
V_132 = F_157 ( V_7 -> V_8 . V_47 , 0 , args -> V_17 ,
V_186 | V_187 , V_188 ,
args -> V_63 ) ;
if ( args -> V_183 & V_184 ) {
struct V_189 * V_19 = V_190 -> V_19 ;
struct V_191 * V_40 ;
if ( F_158 ( & V_19 -> V_192 ) ) {
F_84 ( V_7 ) ;
return - V_193 ;
}
V_40 = F_159 ( V_19 , V_132 ) ;
if ( V_40 )
V_40 -> V_194 =
F_160 ( F_161 ( V_40 -> V_195 ) ) ;
else
V_132 = - V_61 ;
F_162 ( & V_19 -> V_192 ) ;
F_163 ( V_7 -> V_178 , V_104 ) ;
}
F_84 ( V_7 ) ;
if ( F_28 ( ( void * ) V_132 ) )
return V_132 ;
args -> V_196 = ( T_6 ) V_132 ;
return 0 ;
}
static unsigned int F_164 ( struct V_6 * V_7 )
{
T_11 V_17 ;
V_17 = F_165 ( V_7 ) ;
V_17 *= F_166 ( V_7 ) == V_197 ? 32 : 8 ;
return V_17 >> V_149 ;
}
int F_167 ( void )
{
return 1 ;
}
int F_168 ( struct V_191 * V_198 , struct V_199 * V_200 )
{
#define F_169 ((1 << 20) >> PAGE_SHIFT)
struct V_6 * V_7 = F_170 ( V_198 -> V_201 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_37 * V_18 = & V_23 -> V_18 ;
bool V_202 = ! ! ( V_200 -> V_183 & V_203 ) ;
struct V_39 * V_40 ;
T_12 V_138 ;
unsigned int V_183 ;
int V_28 ;
V_138 = ( ( unsigned long ) V_200 -> V_204 - V_198 -> V_205 ) >>
V_149 ;
F_171 ( V_7 , V_138 , true , V_202 ) ;
V_28 = F_62 ( V_7 , NULL , ! V_202 ) ;
if ( V_28 )
goto V_86;
F_134 ( V_23 ) ;
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
goto V_174;
if ( V_7 -> V_11 != V_5 && ! F_2 ( V_2 ) ) {
V_28 = - V_97 ;
goto V_206;
}
V_183 = V_144 ;
if ( V_7 -> V_8 . V_17 > 2 * F_169 << V_149 )
V_183 |= V_164 | V_207 ;
V_40 = F_114 ( V_7 , NULL , 0 , 0 , V_183 ) ;
if ( F_28 ( V_40 ) ) {
struct V_208 V_209 ;
unsigned int V_210 ;
V_210 = F_169 ;
if ( F_141 ( V_7 ) )
V_210 = F_81 ( V_210 , F_164 ( V_7 ) ) ;
memset ( & V_209 , 0 , sizeof( V_209 ) ) ;
V_209 . type = V_211 ;
V_209 . V_212 . V_213 . V_63 = F_172 ( V_138 , V_210 ) ;
V_209 . V_212 . V_213 . V_17 =
F_173 (unsigned int, chunk_size,
(area->vm_end - area->vm_start) / PAGE_SIZE -
view.params.partial.offset) ;
if ( V_210 >= V_7 -> V_8 . V_17 >> V_149 )
V_209 . type = V_214 ;
V_7 -> V_178 = V_104 ;
V_40 = F_114 ( V_7 , & V_209 , 0 , 0 , V_144 ) ;
}
if ( F_28 ( V_40 ) ) {
V_28 = F_29 ( V_40 ) ;
goto V_206;
}
V_28 = F_119 ( V_7 , V_202 ) ;
if ( V_28 )
goto V_126;
V_28 = F_174 ( V_40 ) ;
if ( V_28 )
goto V_126;
V_28 = F_175 ( V_198 ,
V_198 -> V_205 + ( V_40 -> V_215 . V_212 . V_213 . V_63 << V_149 ) ,
( V_18 -> V_216 + V_40 -> V_16 . V_134 ) >> V_149 ,
F_173 ( T_11 , V_40 -> V_17 , V_198 -> V_217 - V_198 -> V_205 ) ,
& V_18 -> V_151 ) ;
if ( V_28 )
goto V_126;
V_7 -> V_218 = true ;
V_126:
F_176 ( V_40 ) ;
V_206:
F_23 ( & V_2 -> V_33 ) ;
V_174:
F_135 ( V_23 ) ;
V_86:
switch ( V_28 ) {
case - V_31 :
if ( ! F_177 ( & V_23 -> V_32 ) ) {
V_28 = V_219 ;
break;
}
case - V_220 :
case 0 :
case - V_221 :
case - V_193 :
case - V_96 :
V_28 = V_222 ;
break;
case - V_61 :
V_28 = V_223 ;
break;
case - V_175 :
case - V_97 :
V_28 = V_219 ;
break;
default:
F_178 ( V_28 , L_2 , V_28 ) ;
V_28 = V_219 ;
break;
}
return V_28 ;
}
void
F_179 ( struct V_6 * V_7 )
{
F_50 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
if ( ! V_7 -> V_218 )
return;
F_180 ( & V_7 -> V_8 . V_224 ,
V_7 -> V_8 . V_2 -> V_225 -> V_226 ) ;
F_123 () ;
V_7 -> V_218 = false ;
}
void
F_181 ( struct V_13 * V_23 )
{
struct V_6 * V_7 ;
F_21 (obj, &dev_priv->mm.bound_list, global_list)
F_179 ( V_7 ) ;
}
T_11 F_182 ( struct V_13 * V_23 ,
T_11 V_17 , int V_227 )
{
T_11 V_228 ;
F_183 ( V_17 == 0 ) ;
if ( F_184 ( V_23 ) >= 4 ||
V_227 == V_229 )
return V_17 ;
if ( F_185 ( V_23 ) )
V_228 = 1024 * 1024 ;
else
V_228 = 512 * 1024 ;
while ( V_228 < V_17 )
V_228 <<= 1 ;
return V_228 ;
}
T_11 F_186 ( struct V_13 * V_23 , T_11 V_17 ,
int V_227 , bool V_230 )
{
F_183 ( V_17 == 0 ) ;
if ( F_184 ( V_23 ) >= 4 || ( ! V_230 && F_187 ( V_23 ) ) ||
V_227 == V_229 )
return 4096 ;
return F_182 ( V_23 , V_17 , V_227 ) ;
}
static int F_188 ( struct V_6 * V_7 )
{
struct V_13 * V_23 = F_17 ( V_7 -> V_8 . V_2 ) ;
int V_86 ;
V_86 = F_189 ( & V_7 -> V_8 ) ;
if ( ! V_86 )
return 0 ;
V_86 = F_190 ( V_23 , V_90 ) ;
if ( V_86 )
return V_86 ;
V_86 = F_16 ( & V_23 -> V_231 ) ;
if ( ! V_86 ) {
F_52 ( V_23 ) ;
V_86 = F_189 ( & V_7 -> V_8 ) ;
F_23 ( & V_23 -> V_231 . V_33 ) ;
}
return V_86 ;
}
static void F_191 ( struct V_6 * V_7 )
{
F_192 ( & V_7 -> V_8 ) ;
}
int
F_193 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
T_7 V_109 ,
T_6 * V_63 )
{
struct V_6 * V_7 ;
int V_28 ;
V_7 = F_132 ( V_36 , V_109 ) ;
if ( ! V_7 )
return - V_161 ;
V_28 = F_188 ( V_7 ) ;
if ( V_28 == 0 )
* V_63 = F_194 ( & V_7 -> V_8 . V_224 ) ;
F_84 ( V_7 ) ;
return V_28 ;
}
int
F_195 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_232 * args = V_34 ;
return F_193 ( V_36 , V_2 , args -> V_109 , & args -> V_63 ) ;
}
static void
F_196 ( struct V_6 * V_7 )
{
F_191 ( V_7 ) ;
if ( V_7 -> V_8 . V_47 == NULL )
return;
F_197 ( F_198 ( V_7 -> V_8 . V_47 ) , 0 , ( T_10 ) - 1 ) ;
V_7 -> V_67 = V_68 ;
}
static void
F_199 ( struct V_6 * V_7 )
{
struct V_45 * V_46 ;
switch ( V_7 -> V_67 ) {
case V_70 :
F_196 ( V_7 ) ;
case V_68 :
return;
}
if ( V_7 -> V_8 . V_47 == NULL )
return;
V_46 = V_7 -> V_8 . V_47 -> V_48 ,
F_200 ( V_46 , 0 , ( T_10 ) - 1 ) ;
}
static void
F_201 ( struct V_6 * V_7 )
{
struct V_233 V_233 ;
struct V_58 * V_58 ;
int V_28 ;
F_41 ( V_7 -> V_67 == V_68 ) ;
V_28 = F_42 ( V_7 , true ) ;
if ( F_25 ( V_28 ) ) {
F_146 ( V_7 , true ) ;
V_7 -> V_8 . V_69 = V_7 -> V_8 . V_9 = V_10 ;
}
F_202 ( V_7 ) ;
if ( F_26 ( V_7 ) )
F_203 ( V_7 ) ;
if ( V_7 -> V_67 == V_70 )
V_7 -> V_71 = 0 ;
F_204 (page, sgt_iter, obj->pages) {
if ( V_7 -> V_71 )
F_43 ( V_58 ) ;
if ( V_7 -> V_67 == V_73 )
F_44 ( V_58 ) ;
F_33 ( V_58 ) ;
}
V_7 -> V_71 = 0 ;
F_45 ( V_7 -> V_66 ) ;
F_37 ( V_7 -> V_66 ) ;
}
int
F_67 ( struct V_6 * V_7 )
{
const struct V_234 * V_98 = V_7 -> V_98 ;
if ( V_7 -> V_66 == NULL )
return 0 ;
if ( V_7 -> V_235 )
return - V_96 ;
F_183 ( V_7 -> V_236 ) ;
F_205 ( & V_7 -> V_237 ) ;
if ( V_7 -> V_46 ) {
void * V_238 ;
V_238 = F_206 ( V_7 -> V_46 ) ;
if ( F_207 ( V_238 ) )
F_208 ( V_238 ) ;
else
F_109 ( F_209 ( V_238 ) ) ;
V_7 -> V_46 = NULL ;
}
V_98 -> V_239 ( V_7 ) ;
V_7 -> V_66 = NULL ;
F_199 ( V_7 ) ;
return 0 ;
}
static int
F_210 ( struct V_6 * V_7 )
{
struct V_13 * V_23 = F_17 ( V_7 -> V_8 . V_2 ) ;
int V_240 , V_55 ;
struct V_45 * V_46 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_233 V_233 ;
struct V_58 * V_58 ;
unsigned long V_241 = 0 ;
int V_28 ;
T_13 V_242 ;
F_41 ( V_7 -> V_8 . V_69 & V_180 ) ;
F_41 ( V_7 -> V_8 . V_9 & V_180 ) ;
V_52 = F_35 ( sizeof( * V_52 ) , V_60 ) ;
if ( V_52 == NULL )
return - V_61 ;
V_240 = V_7 -> V_8 . V_17 / V_57 ;
if ( F_36 ( V_52 , V_240 , V_60 ) ) {
F_37 ( V_52 ) ;
return - V_61 ;
}
V_46 = V_7 -> V_8 . V_47 -> V_48 ;
V_242 = F_211 ( V_46 , ~ ( V_243 | V_244 ) ) ;
V_242 |= V_245 | V_246 ;
V_54 = V_52 -> V_62 ;
V_52 -> V_247 = 0 ;
for ( V_55 = 0 ; V_55 < V_240 ; V_55 ++ ) {
V_58 = F_212 ( V_46 , V_55 , V_242 ) ;
if ( F_28 ( V_58 ) ) {
F_213 ( V_23 ,
V_240 ,
V_248 |
V_249 |
V_250 ) ;
V_58 = F_212 ( V_46 , V_55 , V_242 ) ;
}
if ( F_28 ( V_58 ) ) {
F_214 ( V_23 ) ;
V_58 = F_27 ( V_46 , V_55 ) ;
if ( F_28 ( V_58 ) ) {
V_28 = F_29 ( V_58 ) ;
goto V_251;
}
}
#ifdef F_215
if ( F_216 () ) {
V_52 -> V_247 ++ ;
F_217 ( V_54 , V_58 , V_57 , 0 ) ;
V_54 = F_218 ( V_54 ) ;
continue;
}
#endif
if ( ! V_55 || F_219 ( V_58 ) != V_241 + 1 ) {
if ( V_55 )
V_54 = F_218 ( V_54 ) ;
V_52 -> V_247 ++ ;
F_217 ( V_54 , V_58 , V_57 , 0 ) ;
} else {
V_54 -> V_64 += V_57 ;
}
V_241 = F_219 ( V_58 ) ;
F_25 ( ( V_242 & V_252 ) && ( V_241 >= 0x00100000UL ) ) ;
}
#ifdef F_215
if ( ! F_216 () )
#endif
F_220 ( V_54 ) ;
V_7 -> V_66 = V_52 ;
V_28 = F_221 ( V_7 ) ;
if ( V_28 )
goto V_253;
if ( F_26 ( V_7 ) )
F_222 ( V_7 ) ;
if ( F_141 ( V_7 ) &&
V_23 -> V_254 & V_255 )
F_96 ( V_7 ) ;
return 0 ;
V_251:
F_220 ( V_54 ) ;
V_253:
F_204 (page, sgt_iter, st)
F_33 ( V_58 ) ;
F_45 ( V_52 ) ;
F_37 ( V_52 ) ;
if ( V_28 == - V_175 )
V_28 = - V_61 ;
return V_28 ;
}
int
F_69 ( struct V_6 * V_7 )
{
struct V_13 * V_23 = F_17 ( V_7 -> V_8 . V_2 ) ;
const struct V_234 * V_98 = V_7 -> V_98 ;
int V_28 ;
if ( V_7 -> V_66 )
return 0 ;
if ( V_7 -> V_67 != V_73 ) {
F_223 ( L_3 ) ;
return - V_97 ;
}
F_41 ( V_7 -> V_235 ) ;
V_28 = V_98 -> V_256 ( V_7 ) ;
if ( V_28 )
return V_28 ;
F_224 ( & V_7 -> V_237 , & V_23 -> V_19 . V_257 ) ;
V_7 -> V_258 . V_54 = V_7 -> V_66 -> V_62 ;
V_7 -> V_258 . V_259 = 0 ;
return 0 ;
}
static void * F_225 ( const struct V_6 * V_7 ,
enum V_260 type )
{
unsigned long V_261 = V_7 -> V_8 . V_17 >> V_149 ;
struct V_51 * V_262 = V_7 -> V_66 ;
struct V_233 V_233 ;
struct V_58 * V_58 ;
struct V_58 * V_263 [ 32 ] ;
struct V_58 * * V_66 = V_263 ;
unsigned long V_55 = 0 ;
T_14 V_264 ;
void * V_132 ;
if ( V_261 == 1 && type == V_265 )
return F_108 ( F_226 ( V_262 -> V_62 ) ) ;
if ( V_261 > F_227 ( V_263 ) ) {
V_66 = F_228 ( V_261 , sizeof( * V_66 ) , V_266 ) ;
if ( ! V_66 )
return NULL ;
}
F_204 (page, sgt_iter, sgt)
V_66 [ V_55 ++ ] = V_58 ;
F_183 ( V_55 != V_261 ) ;
switch ( type ) {
case V_265 :
V_264 = V_267 ;
break;
case V_268 :
V_264 = F_160 ( V_269 ) ;
break;
}
V_132 = F_229 ( V_66 , V_261 , 0 , V_264 ) ;
if ( V_66 != V_263 )
F_230 ( V_66 ) ;
return V_132 ;
}
void * F_231 ( struct V_6 * V_7 ,
enum V_260 type )
{
enum V_260 V_270 ;
bool V_41 ;
void * V_238 ;
int V_28 ;
F_50 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
F_183 ( ! F_95 ( V_7 ) ) ;
V_28 = F_69 ( V_7 ) ;
if ( V_28 )
return F_118 ( V_28 ) ;
F_96 ( V_7 ) ;
V_41 = V_7 -> V_235 > 1 ;
V_238 = F_232 ( V_7 -> V_46 , V_270 ) ;
if ( V_238 && V_270 != type ) {
if ( V_41 ) {
V_28 = - V_96 ;
goto V_86;
}
if ( F_207 ( V_238 ) )
F_208 ( V_238 ) ;
else
F_109 ( F_209 ( V_238 ) ) ;
V_238 = V_7 -> V_46 = NULL ;
}
if ( ! V_238 ) {
V_238 = F_225 ( V_7 , type ) ;
if ( ! V_238 ) {
V_28 = - V_61 ;
goto V_86;
}
V_7 -> V_46 = F_233 ( V_238 , type ) ;
}
return V_238 ;
V_86:
F_99 ( V_7 ) ;
return F_118 ( V_28 ) ;
}
static void
F_234 ( struct V_80 * V_81 ,
struct V_271 * V_272 )
{
struct V_6 * V_7 =
F_235 ( V_81 , struct V_6 , V_85 ) ;
F_75 ( V_7 , true , V_273 ) ;
}
static void
F_236 ( struct V_80 * V_81 ,
struct V_271 * V_272 )
{
int V_83 = V_272 -> V_274 -> V_275 ;
struct V_6 * V_7 =
F_235 ( V_81 , struct V_6 , V_84 [ V_83 ] ) ;
F_183 ( ! F_237 ( V_7 , V_83 ) ) ;
F_238 ( V_7 , V_83 ) ;
if ( F_239 ( V_7 ) )
return;
if ( V_7 -> V_236 )
F_54 ( & V_7 -> V_237 ,
& V_272 -> V_14 -> V_19 . V_276 ) ;
F_136 ( V_7 ) ;
}
static bool F_240 ( const struct V_277 * V_278 )
{
unsigned long V_279 ;
if ( V_278 -> V_280 . V_281 )
return true ;
V_279 = F_241 () - V_278 -> V_280 . V_282 ;
if ( V_278 -> V_280 . V_283 &&
V_279 <= V_278 -> V_280 . V_283 ) {
F_223 ( L_4 ) ;
return true ;
}
return false ;
}
static void F_242 ( struct V_277 * V_278 ,
const bool V_284 )
{
struct V_285 * V_286 = & V_278 -> V_280 ;
if ( V_284 ) {
V_286 -> V_281 = F_240 ( V_278 ) ;
V_286 -> V_287 ++ ;
V_286 -> V_282 = F_241 () ;
} else {
V_286 -> V_288 ++ ;
}
}
struct V_271 *
F_243 ( struct V_289 * V_274 )
{
struct V_271 * V_272 ;
F_21 (request, &engine->request_list, link) {
if ( F_244 ( V_272 ) )
continue;
if ( ! F_245 ( & V_272 -> V_290 ) )
break;
return V_272 ;
}
return NULL ;
}
static void F_246 ( struct V_271 * V_272 )
{
void * V_49 = V_272 -> V_291 -> V_49 ;
T_1 V_292 ;
V_292 = V_272 -> V_292 ;
if ( V_272 -> V_293 < V_292 ) {
memset ( V_49 + V_292 , 0 , V_272 -> V_291 -> V_17 - V_292 ) ;
V_292 = 0 ;
}
memset ( V_49 + V_292 , 0 , V_272 -> V_293 - V_292 ) ;
}
static void F_247 ( struct V_289 * V_274 )
{
struct V_271 * V_272 ;
struct V_277 * V_294 ;
bool V_295 ;
F_248 ( & V_274 -> V_296 ) ;
if ( V_274 -> V_297 )
V_274 -> V_297 ( V_274 ) ;
V_272 = F_243 ( V_274 ) ;
if ( ! V_272 )
return;
V_295 = V_274 -> V_298 . V_299 >= V_300 ;
F_242 ( V_272 -> V_278 , V_295 ) ;
if ( ! V_295 )
return;
F_249 ( L_5 ,
V_274 -> V_301 , V_272 -> V_302 . V_303 ) ;
V_274 -> V_304 ( V_274 , V_272 ) ;
V_294 = V_272 -> V_278 ;
if ( F_250 ( V_294 ) )
return;
F_251 (request, &engine->request_list, link)
if ( V_272 -> V_278 == V_294 )
F_246 ( V_272 ) ;
}
void F_252 ( struct V_13 * V_23 )
{
struct V_289 * V_274 ;
F_52 ( V_23 ) ;
F_253 (engine, dev_priv)
F_247 ( V_274 ) ;
F_254 ( & V_23 -> V_231 ) ;
if ( V_23 -> V_305 . V_306 ) {
F_255 ( V_23 ) ;
F_256 ( V_23 ) ;
if ( F_184 ( V_23 ) >= 6 )
F_257 ( V_23 ) ;
}
}
static void F_258 ( struct V_271 * V_272 )
{
}
static void F_259 ( struct V_289 * V_274 )
{
V_274 -> V_307 = F_258 ;
F_260 ( V_274 , V_274 -> V_308 ) ;
if ( V_14 . V_309 ) {
F_9 ( & V_274 -> V_310 ) ;
F_261 ( & V_274 -> V_311 ) ;
F_262 ( V_274 -> V_312 [ 0 ] . V_272 ) ;
F_262 ( V_274 -> V_312 [ 1 ] . V_272 ) ;
memset ( V_274 -> V_312 , 0 , sizeof( V_274 -> V_312 ) ) ;
F_10 ( & V_274 -> V_310 ) ;
}
V_274 -> V_14 -> V_305 . V_313 &= ~ F_263 ( V_274 ) ;
}
void F_264 ( struct V_13 * V_23 )
{
struct V_289 * V_274 ;
F_50 ( & V_23 -> V_231 . V_33 ) ;
F_265 ( V_314 , & V_23 -> V_32 . V_183 ) ;
F_266 ( V_23 ) ;
F_253 (engine, dev_priv)
F_259 ( V_274 ) ;
F_267 ( V_23 -> V_315 , & V_23 -> V_305 . V_316 , 0 ) ;
F_52 ( V_23 ) ;
}
static void
F_268 ( struct V_317 * V_318 )
{
struct V_13 * V_23 =
F_235 ( V_318 , F_269 ( * V_23 ) , V_305 . V_319 . V_318 ) ;
struct V_1 * V_2 = & V_23 -> V_231 ;
if ( F_270 ( & V_2 -> V_33 ) ) {
F_52 ( V_23 ) ;
F_23 ( & V_2 -> V_33 ) ;
}
if ( F_153 ( V_23 -> V_305 . V_306 ) ) {
F_271 ( V_23 ) ;
F_272 ( V_23 -> V_315 ,
& V_23 -> V_305 . V_319 ,
F_273 ( V_30 ) ) ;
}
}
static void
F_274 ( struct V_317 * V_318 )
{
struct V_13 * V_23 =
F_235 ( V_318 , F_269 ( * V_23 ) , V_305 . V_316 . V_318 ) ;
struct V_1 * V_2 = & V_23 -> V_231 ;
struct V_289 * V_274 ;
bool V_320 ;
if ( ! F_153 ( V_23 -> V_305 . V_306 ) )
return;
if ( F_153 ( V_23 -> V_305 . V_313 ) )
return;
V_320 =
F_275 ( & V_23 -> V_32 . V_321 ) ;
if ( ! F_270 ( & V_2 -> V_33 ) ) {
F_267 ( V_23 -> V_315 ,
& V_23 -> V_305 . V_316 ,
F_276 ( 50 ) ) ;
goto V_322;
}
if ( V_23 -> V_305 . V_313 )
goto V_323;
F_253 (engine, dev_priv)
F_277 ( & V_274 -> V_324 ) ;
F_183 ( ! V_23 -> V_305 . V_306 ) ;
V_23 -> V_305 . V_306 = false ;
V_320 = false ;
if ( F_184 ( V_23 ) >= 6 )
F_278 ( V_23 ) ;
F_135 ( V_23 ) ;
V_323:
F_23 ( & V_2 -> V_33 ) ;
V_322:
if ( V_320 ) {
F_183 ( ! V_23 -> V_305 . V_306 ) ;
F_271 ( V_23 ) ;
}
}
void F_279 ( struct V_325 * V_326 , struct V_35 * V_36 )
{
struct V_6 * V_7 = F_170 ( V_326 ) ;
struct V_91 * V_92 = V_36 -> V_93 ;
struct V_39 * V_40 , * V_327 ;
F_20 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
F_280 (vma, vn, &obj->vma_list, obj_link)
if ( V_40 -> V_328 -> V_36 == V_92 )
F_281 ( V_40 ) ;
F_23 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
}
int
F_282 ( struct V_1 * V_2 , void * V_34 , struct V_35 * V_36 )
{
struct V_329 * args = V_34 ;
struct V_88 * V_89 = F_65 ( V_36 ) ;
struct V_6 * V_7 ;
unsigned long V_81 ;
int V_83 , V_28 = 0 ;
if ( args -> V_183 != 0 )
return - V_56 ;
V_7 = F_132 ( V_36 , args -> V_330 ) ;
if ( ! V_7 )
return - V_161 ;
V_81 = F_63 ( V_7 ) ;
F_58 (active, idx) {
T_15 * V_331 = args -> V_332 >= 0 ? & args -> V_332 : NULL ;
V_28 = F_64 ( & V_7 -> V_84 [ V_83 ] ,
V_90 ,
V_331 , V_89 ) ;
if ( V_28 )
break;
}
F_84 ( V_7 ) ;
return V_28 ;
}
static void F_283 ( struct V_39 * V_40 )
{
F_183 ( F_22 ( V_40 ) ) ;
if ( V_40 -> V_333 == NULL )
return;
F_112 ( V_40 -> V_333 ) ;
V_40 -> V_333 = NULL ;
}
int F_55 ( struct V_39 * V_40 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
unsigned long V_81 ;
int V_28 ;
V_81 = F_284 ( V_40 ) ;
if ( V_81 ) {
int V_83 ;
F_285 ( V_40 ) ;
F_58 (active, idx) {
V_28 = F_286 ( & V_40 -> V_84 [ V_83 ] ,
& V_40 -> V_328 -> V_2 -> V_33 ) ;
if ( V_28 )
break;
}
F_176 ( V_40 ) ;
if ( V_28 )
return V_28 ;
F_183 ( F_287 ( V_40 ) ) ;
}
if ( F_22 ( V_40 ) )
return - V_96 ;
if ( ! F_288 ( & V_40 -> V_16 ) )
goto V_334;
F_183 ( V_7 -> V_236 == 0 ) ;
F_183 ( ! V_7 -> V_66 ) ;
if ( F_289 ( V_40 ) ) {
V_28 = F_116 ( V_40 ) ;
if ( V_28 )
return V_28 ;
F_179 ( V_7 ) ;
F_283 ( V_40 ) ;
V_40 -> V_183 &= ~ V_335 ;
}
if ( F_120 ( ! V_40 -> V_328 -> V_336 ) ) {
F_290 ( V_40 ) ;
V_40 -> V_328 -> V_337 ( V_40 ) ;
}
V_40 -> V_183 &= ~ ( V_338 | V_339 ) ;
F_7 ( & V_40 -> V_16 ) ;
F_54 ( & V_40 -> V_340 , & V_40 -> V_328 -> V_257 ) ;
if ( V_40 -> V_66 != V_7 -> V_66 ) {
F_183 ( ! V_40 -> V_66 ) ;
F_45 ( V_40 -> V_66 ) ;
F_37 ( V_40 -> V_66 ) ;
}
V_40 -> V_66 = NULL ;
if ( -- V_7 -> V_236 == 0 )
F_54 ( & V_7 -> V_237 ,
& F_17 ( V_7 -> V_8 . V_2 ) -> V_19 . V_257 ) ;
F_99 ( V_7 ) ;
V_334:
if ( F_102 ( F_291 ( V_40 ) ) )
F_292 ( V_40 ) ;
return 0 ;
}
int F_190 ( struct V_13 * V_23 ,
unsigned int V_183 )
{
struct V_289 * V_274 ;
int V_28 ;
F_253 (engine, dev_priv) {
if ( V_274 -> V_341 == NULL )
continue;
V_28 = F_293 ( V_274 , V_183 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
static bool F_294 ( struct V_39 * V_40 ,
unsigned long V_11 )
{
struct V_15 * V_342 = & V_40 -> V_16 ;
struct V_15 * V_343 ;
if ( V_40 -> V_328 -> V_19 . V_344 == NULL )
return true ;
if ( ! F_288 ( V_342 ) )
return true ;
if ( F_295 ( & V_342 -> V_345 ) )
return true ;
V_343 = F_296 ( V_342 -> V_345 . V_346 , struct V_15 , V_345 ) ;
if ( V_343 -> V_145 && ! V_343 -> V_347 && V_343 -> V_348 != V_11 )
return false ;
V_343 = F_296 ( V_342 -> V_345 . V_349 , struct V_15 , V_345 ) ;
if ( V_343 -> V_145 && ! V_342 -> V_347 && V_343 -> V_348 != V_11 )
return false ;
return true ;
}
static int
F_297 ( struct V_39 * V_40 , T_11 V_17 , T_11 V_350 , T_11 V_183 )
{
struct V_13 * V_23 = F_17 ( V_40 -> V_328 -> V_2 ) ;
struct V_6 * V_7 = V_40 -> V_7 ;
T_11 V_134 , V_135 ;
int V_28 ;
F_183 ( V_40 -> V_183 & ( V_338 | V_339 ) ) ;
F_183 ( F_288 ( & V_40 -> V_16 ) ) ;
V_17 = F_298 ( V_17 , V_40 -> V_17 ) ;
if ( V_183 & V_144 )
V_17 = F_182 ( V_23 , V_17 ,
F_166 ( V_7 ) ) ;
V_350 = F_298 ( F_298 ( V_350 , V_40 -> V_351 ) ,
F_186 ( V_23 , V_17 ,
F_166 ( V_7 ) ,
V_183 & V_144 ) ) ;
V_134 = V_183 & V_352 ? V_183 & V_353 : 0 ;
V_135 = V_40 -> V_328 -> V_43 ;
if ( V_183 & V_144 )
V_135 = F_173 ( T_11 , V_135 , V_23 -> V_18 . V_20 ) ;
if ( V_183 & V_354 )
V_135 = F_173 ( T_11 , V_135 , ( 1ULL << 32 ) - V_57 ) ;
if ( V_17 > V_135 ) {
F_223 ( L_6 ,
V_17 , V_7 -> V_8 . V_17 ,
V_183 & V_144 ? L_7 : L_8 ,
V_135 ) ;
return - V_355 ;
}
V_28 = F_69 ( V_7 ) ;
if ( V_28 )
return V_28 ;
F_96 ( V_7 ) ;
if ( V_183 & V_356 ) {
T_11 V_63 = V_183 & V_353 ;
if ( V_63 & ( V_350 - 1 ) || V_63 > V_135 - V_17 ) {
V_28 = - V_56 ;
goto V_126;
}
V_40 -> V_16 . V_134 = V_63 ;
V_40 -> V_16 . V_17 = V_17 ;
V_40 -> V_16 . V_348 = V_7 -> V_11 ;
V_28 = F_299 ( & V_40 -> V_328 -> V_19 , & V_40 -> V_16 ) ;
if ( V_28 ) {
V_28 = F_300 ( V_40 ) ;
if ( V_28 == 0 )
V_28 = F_299 ( & V_40 -> V_328 -> V_19 , & V_40 -> V_16 ) ;
if ( V_28 )
goto V_126;
}
} else {
T_1 V_357 , V_358 ;
if ( V_183 & V_359 ) {
V_357 = V_360 ;
V_358 = V_361 ;
} else {
V_357 = V_21 ;
V_358 = V_22 ;
}
if ( V_350 <= 4096 )
V_350 = 0 ;
V_362:
V_28 = F_5 ( & V_40 -> V_328 -> V_19 ,
& V_40 -> V_16 ,
V_17 , V_350 ,
V_7 -> V_11 ,
V_134 , V_135 ,
V_357 ,
V_358 ) ;
if ( V_28 ) {
V_28 = F_301 ( V_40 -> V_328 , V_17 , V_350 ,
V_7 -> V_11 ,
V_134 , V_135 ,
V_183 ) ;
if ( V_28 == 0 )
goto V_362;
goto V_126;
}
}
F_183 ( ! F_294 ( V_40 , V_7 -> V_11 ) ) ;
F_54 ( & V_7 -> V_237 , & V_23 -> V_19 . V_276 ) ;
F_54 ( & V_40 -> V_340 , & V_40 -> V_328 -> V_363 ) ;
V_7 -> V_236 ++ ;
return 0 ;
V_126:
F_99 ( V_7 ) ;
return V_28 ;
}
bool
F_146 ( struct V_6 * V_7 ,
bool V_364 )
{
if ( V_7 -> V_66 == NULL )
return false ;
if ( V_7 -> V_365 || V_7 -> V_50 )
return false ;
if ( ! V_364 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_11 ) ) {
V_7 -> V_128 = true ;
return false ;
}
F_302 ( V_7 ) ;
F_303 ( V_7 -> V_66 ) ;
V_7 -> V_128 = false ;
return true ;
}
static void
F_97 ( struct V_6 * V_7 )
{
struct V_13 * V_23 = F_17 ( V_7 -> V_8 . V_2 ) ;
if ( V_7 -> V_8 . V_9 != V_152 )
return;
F_123 () ;
if ( F_184 ( V_23 ) >= 6 && ! F_2 ( V_23 ) )
F_304 ( F_305 ( V_23 -> V_274 [ V_366 ] . V_367 ) ) ;
F_75 ( V_7 , false , F_150 ( V_7 , V_152 ) ) ;
V_7 -> V_8 . V_9 = 0 ;
F_306 ( V_7 ,
V_7 -> V_8 . V_69 ,
V_152 ) ;
}
static void
F_154 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 . V_9 != V_10 )
return;
if ( F_146 ( V_7 , V_7 -> V_12 ) )
F_34 ( F_17 ( V_7 -> V_8 . V_2 ) ) ;
F_75 ( V_7 , false , V_104 ) ;
V_7 -> V_8 . V_9 = 0 ;
F_306 ( V_7 ,
V_7 -> V_8 . V_69 ,
V_10 ) ;
}
static void F_307 ( struct V_6 * V_7 )
{
struct V_39 * V_40 ;
F_21 (vma, &obj->vma_list, obj_link) {
if ( ! F_308 ( V_40 ) )
continue;
if ( F_287 ( V_40 ) )
continue;
if ( ! F_288 ( & V_40 -> V_16 ) )
continue;
F_54 ( & V_40 -> V_340 , & V_40 -> V_328 -> V_363 ) ;
}
}
int
F_119 ( struct V_6 * V_7 , bool V_202 )
{
T_7 V_368 , V_369 ;
int V_28 ;
V_28 = F_51 ( V_7 , ! V_202 ) ;
if ( V_28 )
return V_28 ;
if ( V_7 -> V_8 . V_9 == V_152 )
return 0 ;
V_28 = F_69 ( V_7 ) ;
if ( V_28 )
return V_28 ;
F_154 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_69 & V_152 ) == 0 )
F_309 () ;
V_368 = V_7 -> V_8 . V_9 ;
V_369 = V_7 -> V_8 . V_69 ;
F_41 ( ( V_7 -> V_8 . V_9 & ~ V_152 ) != 0 ) ;
V_7 -> V_8 . V_69 |= V_152 ;
if ( V_202 ) {
V_7 -> V_8 . V_69 = V_152 ;
V_7 -> V_8 . V_9 = V_152 ;
V_7 -> V_71 = 1 ;
}
F_306 ( V_7 ,
V_369 ,
V_368 ) ;
F_307 ( V_7 ) ;
return 0 ;
}
int F_310 ( struct V_6 * V_7 ,
enum V_3 V_11 )
{
struct V_39 * V_40 ;
int V_28 = 0 ;
if ( V_7 -> V_11 == V_11 )
goto V_106;
V_370:
F_21 (vma, &obj->vma_list, obj_link) {
if ( ! F_288 ( & V_40 -> V_16 ) )
continue;
if ( F_22 ( V_40 ) ) {
F_223 ( L_9 ) ;
return - V_96 ;
}
if ( F_294 ( V_40 , V_11 ) )
continue;
V_28 = F_55 ( V_40 ) ;
if ( V_28 )
return V_28 ;
goto V_370;
}
if ( V_7 -> V_236 ) {
V_28 = F_51 ( V_7 , false ) ;
if ( V_28 )
return V_28 ;
if ( ! F_2 ( V_7 -> V_8 . V_2 ) && V_11 != V_5 ) {
F_179 ( V_7 ) ;
F_21 (vma, &obj->vma_list, obj_link) {
V_28 = F_116 ( V_40 ) ;
if ( V_28 )
return V_28 ;
}
} else {
}
F_21 (vma, &obj->vma_list, obj_link) {
if ( ! F_288 ( & V_40 -> V_16 ) )
continue;
V_28 = F_311 ( V_40 , V_11 , V_371 ) ;
if ( V_28 )
return V_28 ;
}
}
F_21 (vma, &obj->vma_list, obj_link)
V_40 -> V_16 . V_348 = V_11 ;
V_7 -> V_11 = V_11 ;
V_106:
if ( V_7 -> V_128 && F_3 ( V_7 ) ) {
if ( F_146 ( V_7 , true ) )
F_34 ( F_17 ( V_7 -> V_8 . V_2 ) ) ;
}
return 0 ;
}
int F_312 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_372 * args = V_34 ;
struct V_6 * V_7 ;
V_7 = F_132 ( V_36 , args -> V_109 ) ;
if ( ! V_7 )
return - V_161 ;
switch ( V_7 -> V_11 ) {
case V_373 :
case V_374 :
args -> V_375 = V_376 ;
break;
case V_377 :
args -> V_375 = V_378 ;
break;
default:
args -> V_375 = V_379 ;
break;
}
F_84 ( V_7 ) ;
return 0 ;
}
int F_313 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_372 * args = V_34 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_28 ;
switch ( args -> V_375 ) {
case V_379 :
V_4 = V_5 ;
break;
case V_376 :
if ( ! F_2 ( V_2 ) && ! F_314 ( V_2 ) )
return - V_124 ;
V_4 = V_373 ;
break;
case V_378 :
V_4 = F_315 ( V_2 ) ? V_377 : V_5 ;
break;
default:
return - V_56 ;
}
F_134 ( V_23 ) ;
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
goto V_380;
V_7 = F_132 ( V_36 , args -> V_109 ) ;
if ( ! V_7 ) {
V_28 = - V_161 ;
goto V_381;
}
V_28 = F_310 ( V_7 , V_4 ) ;
F_136 ( V_7 ) ;
V_381:
F_23 ( & V_2 -> V_33 ) ;
V_380:
F_135 ( V_23 ) ;
return V_28 ;
}
struct V_39 *
F_316 ( struct V_6 * V_7 ,
T_1 V_350 ,
const struct V_208 * V_209 )
{
struct V_39 * V_40 ;
T_1 V_369 , V_368 ;
int V_28 ;
V_7 -> V_12 ++ ;
V_28 = F_310 ( V_7 ,
F_315 ( V_7 -> V_8 . V_2 ) ? V_377 : V_5 ) ;
if ( V_28 ) {
V_40 = F_118 ( V_28 ) ;
goto V_382;
}
V_40 = F_118 ( - V_175 ) ;
if ( V_209 -> type == V_214 )
V_40 = F_114 ( V_7 , V_209 , 0 , V_350 ,
V_144 | V_164 ) ;
if ( F_28 ( V_40 ) ) {
struct V_13 * V_14 = F_17 ( V_7 -> V_8 . V_2 ) ;
unsigned int V_183 ;
V_183 = 0 ;
if ( F_317 ( V_14 ) )
V_183 = V_144 ;
V_40 = F_114 ( V_7 , V_209 , 0 , V_350 , V_183 ) ;
}
if ( F_28 ( V_40 ) )
goto V_382;
V_40 -> V_351 = F_318 ( T_11 , V_40 -> V_351 , V_350 ) ;
F_154 ( V_7 ) ;
V_368 = V_7 -> V_8 . V_9 ;
V_369 = V_7 -> V_8 . V_69 ;
V_7 -> V_8 . V_9 = 0 ;
V_7 -> V_8 . V_69 |= V_152 ;
F_306 ( V_7 ,
V_369 ,
V_368 ) ;
return V_40 ;
V_382:
V_7 -> V_12 -- ;
return V_40 ;
}
void
F_319 ( struct V_39 * V_40 )
{
if ( F_25 ( V_40 -> V_7 -> V_12 == 0 ) )
return;
if ( -- V_40 -> V_7 -> V_12 == 0 )
V_40 -> V_351 = 0 ;
if ( ! F_287 ( V_40 ) )
F_54 ( & V_40 -> V_340 , & V_40 -> V_328 -> V_363 ) ;
F_117 ( V_40 ) ;
}
int
F_42 ( struct V_6 * V_7 , bool V_202 )
{
T_7 V_368 , V_369 ;
int V_28 ;
V_28 = F_51 ( V_7 , ! V_202 ) ;
if ( V_28 )
return V_28 ;
if ( V_7 -> V_8 . V_9 == V_10 )
return 0 ;
F_97 ( V_7 ) ;
V_368 = V_7 -> V_8 . V_9 ;
V_369 = V_7 -> V_8 . V_69 ;
if ( ( V_7 -> V_8 . V_69 & V_10 ) == 0 ) {
F_146 ( V_7 , false ) ;
V_7 -> V_8 . V_69 |= V_10 ;
}
F_41 ( ( V_7 -> V_8 . V_9 & ~ V_10 ) != 0 ) ;
if ( V_202 ) {
V_7 -> V_8 . V_69 = V_10 ;
V_7 -> V_8 . V_9 = V_10 ;
}
F_306 ( V_7 ,
V_369 ,
V_368 ) ;
return 0 ;
}
static int
F_320 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_91 * V_101 = V_36 -> V_93 ;
unsigned long V_383 = V_384 - V_385 ;
struct V_271 * V_272 , * V_386 = NULL ;
int V_28 ;
V_28 = F_12 ( & V_23 -> V_32 ) ;
if ( V_28 )
return V_28 ;
if ( F_177 ( & V_23 -> V_32 ) )
return - V_31 ;
F_9 ( & V_101 -> V_19 . V_387 ) ;
F_21 (request, &file_priv->mm.request_list, client_list) {
if ( F_321 ( V_272 -> V_388 , V_383 ) )
break;
if ( ! V_272 -> V_388 )
continue;
V_386 = V_272 ;
}
if ( V_386 )
F_322 ( V_386 ) ;
F_10 ( & V_101 -> V_19 . V_387 ) ;
if ( V_386 == NULL )
return 0 ;
V_28 = F_323 ( V_386 , V_90 , NULL , NULL ) ;
F_262 ( V_386 ) ;
return V_28 ;
}
static bool
F_324 ( struct V_39 * V_40 , T_11 V_17 , T_11 V_350 , T_11 V_183 )
{
if ( ! F_288 ( & V_40 -> V_16 ) )
return false ;
if ( V_40 -> V_16 . V_17 < V_17 )
return true ;
if ( V_350 && V_40 -> V_16 . V_134 & ( V_350 - 1 ) )
return true ;
if ( V_183 & V_144 && ! F_289 ( V_40 ) )
return true ;
if ( V_183 & V_352 &&
V_40 -> V_16 . V_134 < ( V_183 & V_353 ) )
return true ;
if ( V_183 & V_356 &&
V_40 -> V_16 . V_134 != ( V_183 & V_353 ) )
return true ;
return false ;
}
void F_325 ( struct V_39 * V_40 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_13 * V_23 = F_17 ( V_7 -> V_8 . V_2 ) ;
bool V_151 , V_389 ;
T_1 V_390 , V_391 ;
V_390 = F_182 ( V_23 ,
V_40 -> V_17 ,
F_166 ( V_7 ) ) ;
V_391 = F_186 ( V_23 ,
V_40 -> V_17 ,
F_166 ( V_7 ) ,
true ) ;
V_389 = ( V_40 -> V_16 . V_17 == V_390 &&
( V_40 -> V_16 . V_134 & ( V_391 - 1 ) ) == 0 ) ;
V_151 = ( V_40 -> V_16 . V_134 + V_390 <=
V_23 -> V_18 . V_20 ) ;
if ( V_151 && V_389 &&
V_40 -> V_215 . type != V_392 )
V_40 -> V_183 |= V_335 ;
else
V_40 -> V_183 &= ~ V_335 ;
}
int F_326 ( struct V_39 * V_40 ,
T_11 V_17 , T_11 V_350 , T_11 V_183 )
{
unsigned int V_393 = V_40 -> V_183 ;
int V_28 ;
F_183 ( ( V_183 & ( V_394 | V_395 ) ) == 0 ) ;
F_183 ( ( V_183 & V_394 ) && ! F_308 ( V_40 ) ) ;
if ( F_25 ( V_393 & V_396 ) ) {
V_28 = - V_96 ;
goto V_86;
}
if ( ( V_393 & V_397 ) == 0 ) {
V_28 = F_297 ( V_40 , V_17 , V_350 , V_183 ) ;
if ( V_28 )
goto V_86;
}
V_28 = F_311 ( V_40 , V_40 -> V_7 -> V_11 , V_183 ) ;
if ( V_28 )
goto V_86;
if ( ( V_393 ^ V_40 -> V_183 ) & V_338 )
F_325 ( V_40 ) ;
F_183 ( F_324 ( V_40 , V_17 , V_350 , V_183 ) ) ;
return 0 ;
V_86:
F_176 ( V_40 ) ;
return V_28 ;
}
struct V_39 *
F_114 ( struct V_6 * V_7 ,
const struct V_208 * V_209 ,
T_11 V_17 ,
T_11 V_350 ,
T_11 V_183 )
{
struct V_398 * V_328 = & F_17 ( V_7 -> V_8 . V_2 ) -> V_18 . V_8 ;
struct V_39 * V_40 ;
int V_28 ;
V_40 = F_327 ( V_7 , V_328 , V_209 ) ;
if ( F_28 ( V_40 ) )
return V_40 ;
if ( F_324 ( V_40 , V_17 , V_350 , V_183 ) ) {
if ( V_183 & V_164 &&
( F_22 ( V_40 ) || F_287 ( V_40 ) ) )
return F_118 ( - V_175 ) ;
F_328 ( F_22 ( V_40 ) ,
L_10
L_11
L_12 ,
F_115 ( V_40 ) , V_350 ,
! ! ( V_183 & V_144 ) ,
F_289 ( V_40 ) ) ;
V_28 = F_55 ( V_40 ) ;
if ( V_28 )
return F_118 ( V_28 ) ;
}
V_28 = F_329 ( V_40 , V_17 , V_350 , V_183 | V_394 ) ;
if ( V_28 )
return F_118 ( V_28 ) ;
return V_40 ;
}
static T_16 unsigned int F_330 ( unsigned int V_275 )
{
F_331 ( V_399 > 16 ) ;
return 0x10000 << V_275 ;
}
static T_16 unsigned int F_332 ( unsigned int V_275 )
{
return V_275 | F_330 ( V_275 ) ;
}
static T_16 unsigned int
F_333 ( const struct V_80 * V_81 )
{
return F_334 ( V_81 , F_330 ) ;
}
static T_16 unsigned int
F_335 ( const struct V_80 * V_81 )
{
return F_334 ( V_81 , F_332 ) ;
}
int
F_336 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_400 * args = V_34 ;
struct V_6 * V_7 ;
unsigned long V_81 ;
V_7 = F_132 ( V_36 , args -> V_109 ) ;
if ( ! V_7 )
return - V_161 ;
args -> V_401 = 0 ;
V_81 = F_63 ( V_7 ) ;
if ( V_81 ) {
int V_83 ;
F_337 () ;
F_58 (active, idx)
args -> V_401 |= F_333 ( & V_7 -> V_84 [ V_83 ] ) ;
args -> V_401 |= F_335 ( & V_7 -> V_85 ) ;
F_338 () ;
}
F_84 ( V_7 ) ;
return 0 ;
}
int
F_339 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_101 )
{
return F_320 ( V_2 , V_101 ) ;
}
int
F_340 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_101 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_402 * args = V_34 ;
struct V_6 * V_7 ;
int V_28 ;
switch ( args -> V_67 ) {
case V_70 :
case V_73 :
break;
default:
return - V_56 ;
}
V_28 = F_16 ( V_2 ) ;
if ( V_28 )
return V_28 ;
V_7 = F_132 ( V_101 , args -> V_109 ) ;
if ( ! V_7 ) {
V_28 = - V_161 ;
goto V_381;
}
if ( V_7 -> V_66 &&
F_141 ( V_7 ) &&
V_23 -> V_254 & V_255 ) {
if ( V_7 -> V_67 == V_73 )
F_99 ( V_7 ) ;
if ( args -> V_67 == V_73 )
F_96 ( V_7 ) ;
}
if ( V_7 -> V_67 != V_68 )
V_7 -> V_67 = args -> V_67 ;
if ( V_7 -> V_67 == V_70 && V_7 -> V_66 == NULL )
F_196 ( V_7 ) ;
args -> V_403 = V_7 -> V_67 != V_68 ;
F_136 ( V_7 ) ;
V_381:
F_23 ( & V_2 -> V_33 ) ;
return V_28 ;
}
void F_341 ( struct V_6 * V_7 ,
const struct V_234 * V_98 )
{
int V_55 ;
F_261 ( & V_7 -> V_237 ) ;
for ( V_55 = 0 ; V_55 < V_399 ; V_55 ++ )
F_342 ( & V_7 -> V_84 [ V_55 ] ,
F_236 ) ;
F_342 ( & V_7 -> V_85 ,
F_234 ) ;
F_261 ( & V_7 -> V_404 ) ;
F_261 ( & V_7 -> V_75 ) ;
F_261 ( & V_7 -> V_405 ) ;
V_7 -> V_98 = V_98 ;
V_7 -> V_178 = V_406 ;
V_7 -> V_67 = V_73 ;
F_8 ( F_17 ( V_7 -> V_8 . V_2 ) , V_7 -> V_8 . V_17 ) ;
}
struct V_6 * F_82 ( struct V_1 * V_2 ,
T_2 V_17 )
{
struct V_6 * V_7 ;
struct V_45 * V_46 ;
T_13 V_407 ;
int V_28 ;
V_7 = F_76 ( V_2 ) ;
if ( V_7 == NULL )
return F_118 ( - V_61 ) ;
V_28 = F_343 ( V_2 , & V_7 -> V_8 , V_17 ) ;
if ( V_28 )
goto V_408;
V_407 = V_409 | V_410 ;
if ( F_344 ( V_2 ) || F_345 ( V_2 ) ) {
V_407 &= ~ V_411 ;
V_407 |= V_252 ;
}
V_46 = V_7 -> V_8 . V_47 -> V_48 ;
F_346 ( V_46 , V_407 ) ;
F_341 ( V_7 , & V_412 ) ;
V_7 -> V_8 . V_9 = V_10 ;
V_7 -> V_8 . V_69 = V_10 ;
if ( F_2 ( V_2 ) ) {
V_7 -> V_11 = V_373 ;
} else
V_7 -> V_11 = V_5 ;
F_347 ( V_7 ) ;
return V_7 ;
V_408:
F_78 ( V_7 ) ;
return F_118 ( V_28 ) ;
}
static bool F_348 ( struct V_6 * V_7 )
{
if ( V_7 -> V_67 != V_73 )
return false ;
if ( V_7 -> V_8 . V_47 == NULL )
return true ;
return F_349 ( & V_7 -> V_8 . V_47 -> V_413 ) == 1 ;
}
void F_350 ( struct V_325 * V_414 )
{
struct V_6 * V_7 = F_170 ( V_414 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_39 * V_40 , * V_349 ;
F_134 ( V_23 ) ;
F_351 ( V_7 ) ;
F_280 (vma, next, &obj->vma_list, obj_link) {
F_183 ( ! F_308 ( V_40 ) ) ;
F_183 ( F_287 ( V_40 ) ) ;
V_40 -> V_183 &= ~ V_415 ;
F_281 ( V_40 ) ;
}
F_183 ( V_7 -> V_236 ) ;
if ( V_7 -> V_365 )
F_99 ( V_7 ) ;
F_25 ( F_352 ( & V_7 -> V_416 ) ) ;
if ( V_7 -> V_66 && V_7 -> V_67 == V_73 &&
V_23 -> V_254 & V_255 &&
F_141 ( V_7 ) )
F_99 ( V_7 ) ;
if ( F_25 ( V_7 -> V_235 ) )
V_7 -> V_235 = 0 ;
if ( F_348 ( V_7 ) )
V_7 -> V_67 = V_70 ;
F_67 ( V_7 ) ;
F_41 ( V_7 -> V_66 ) ;
if ( V_7 -> V_8 . V_417 )
F_353 ( & V_7 -> V_8 , NULL ) ;
if ( V_7 -> V_98 -> V_418 )
V_7 -> V_98 -> V_418 ( V_7 ) ;
F_354 ( & V_7 -> V_8 ) ;
F_11 ( V_23 , V_7 -> V_8 . V_17 ) ;
F_37 ( V_7 -> V_419 ) ;
F_78 ( V_7 ) ;
F_135 ( V_23 ) ;
}
int F_355 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
int V_28 ;
F_356 ( V_23 ) ;
F_20 ( & V_2 -> V_33 ) ;
V_28 = F_357 ( V_23 ) ;
if ( V_28 )
goto V_86;
V_28 = F_190 ( V_23 ,
V_90 |
V_420 ) ;
if ( V_28 )
goto V_86;
F_52 ( V_23 ) ;
F_266 ( V_23 ) ;
F_23 ( & V_2 -> V_33 ) ;
F_275 ( & V_23 -> V_32 . V_321 ) ;
F_275 ( & V_23 -> V_305 . V_319 ) ;
F_358 ( & V_23 -> V_305 . V_316 ) ;
F_25 ( V_23 -> V_305 . V_306 ) ;
return 0 ;
V_86:
F_23 ( & V_2 -> V_33 ) ;
return V_28 ;
}
void F_359 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
F_20 ( & V_2 -> V_33 ) ;
F_360 ( V_2 ) ;
V_23 -> V_305 . V_421 ( V_23 ) ;
F_23 ( & V_2 -> V_33 ) ;
}
void F_361 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
if ( F_362 ( V_2 ) -> V_422 < 5 ||
V_23 -> V_19 . V_423 == V_424 )
return;
F_363 ( V_425 , F_364 ( V_425 ) |
V_426 ) ;
if ( F_365 ( V_2 ) )
return;
F_363 ( V_427 , F_364 ( V_427 ) | V_428 ) ;
if ( F_366 ( V_2 ) )
F_363 ( V_429 , F_367 ( V_430 ) ) ;
else if ( F_368 ( V_2 ) )
F_363 ( V_429 , F_367 ( V_431 ) ) ;
else if ( F_369 ( V_2 ) )
F_363 ( V_432 , F_367 ( V_433 ) ) ;
else
F_370 () ;
}
static void F_371 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
F_363 ( F_372 ( V_8 ) , 0 ) ;
F_363 ( F_373 ( V_8 ) , 0 ) ;
F_363 ( F_374 ( V_8 ) , 0 ) ;
F_363 ( F_375 ( V_8 ) , 0 ) ;
}
static void F_376 ( struct V_1 * V_2 )
{
if ( F_377 ( V_2 ) ) {
F_371 ( V_2 , V_434 ) ;
F_371 ( V_2 , V_435 ) ;
F_371 ( V_2 , V_436 ) ;
F_371 ( V_2 , V_437 ) ;
F_371 ( V_2 , V_438 ) ;
} else if ( F_378 ( V_2 ) ) {
F_371 ( V_2 , V_435 ) ;
F_371 ( V_2 , V_436 ) ;
} else if ( F_185 ( V_2 ) ) {
F_371 ( V_2 , V_434 ) ;
F_371 ( V_2 , V_439 ) ;
}
}
int
F_379 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_289 * V_274 ;
int V_28 ;
F_380 ( V_23 , V_440 ) ;
if ( F_381 ( V_2 ) && F_184 ( V_23 ) < 9 )
F_363 ( V_441 , F_364 ( V_441 ) | F_382 ( 0xf ) ) ;
if ( F_383 ( V_2 ) )
F_363 ( V_442 , F_384 ( V_2 ) ?
V_443 : V_444 ) ;
if ( F_385 ( V_2 ) ) {
if ( F_386 ( V_2 ) ) {
T_1 V_445 = F_364 ( V_446 ) ;
V_445 &= ~ ( V_447 | V_448 ) ;
F_363 ( V_446 , V_445 ) ;
} else if ( F_362 ( V_2 ) -> V_422 >= 7 ) {
T_1 V_445 = F_364 ( V_449 ) ;
V_445 &= ~ V_450 ;
F_363 ( V_449 , V_445 ) ;
}
}
F_361 ( V_2 ) ;
F_376 ( V_2 ) ;
F_41 ( ! V_23 -> V_451 ) ;
V_28 = F_387 ( V_2 ) ;
if ( V_28 ) {
F_15 ( L_13 , V_28 ) ;
goto V_106;
}
F_253 (engine, dev_priv) {
V_28 = V_274 -> V_452 ( V_274 ) ;
if ( V_28 )
goto V_106;
}
F_388 ( V_2 ) ;
V_28 = F_389 ( V_2 ) ;
if ( V_28 )
goto V_106;
V_106:
F_390 ( V_23 , V_440 ) ;
return V_28 ;
}
bool F_391 ( struct V_13 * V_23 , int V_453 )
{
if ( F_362 ( V_23 ) -> V_422 < 6 )
return false ;
if ( V_14 . V_309 )
return false ;
if ( V_453 >= 0 )
return V_453 ;
#ifdef F_392
if ( F_362 ( V_23 ) -> V_422 == 6 && V_454 )
return false ;
#endif
return true ;
}
int F_393 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
int V_28 ;
F_20 ( & V_2 -> V_33 ) ;
if ( ! V_14 . V_309 ) {
V_23 -> V_305 . V_421 = V_455 ;
V_23 -> V_305 . V_456 = V_457 ;
} else {
V_23 -> V_305 . V_421 = V_458 ;
V_23 -> V_305 . V_456 = V_459 ;
}
F_380 ( V_23 , V_440 ) ;
F_394 ( V_23 ) ;
V_28 = F_395 ( V_23 ) ;
if ( V_28 )
goto V_323;
V_28 = F_396 ( V_2 ) ;
if ( V_28 )
goto V_323;
V_28 = F_397 ( V_2 ) ;
if ( V_28 )
goto V_323;
V_28 = F_379 ( V_2 ) ;
if ( V_28 == - V_31 ) {
F_15 ( L_14 ) ;
F_264 ( V_23 ) ;
V_28 = 0 ;
}
V_323:
F_390 ( V_23 , V_440 ) ;
F_23 ( & V_2 -> V_33 ) ;
return V_28 ;
}
void
F_398 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
struct V_289 * V_274 ;
F_253 (engine, dev_priv)
V_23 -> V_305 . V_456 ( V_274 ) ;
}
static void
F_399 ( struct V_289 * V_274 )
{
F_261 ( & V_274 -> V_460 ) ;
}
void
F_400 ( struct V_13 * V_23 )
{
struct V_1 * V_2 = & V_23 -> V_231 ;
int V_55 ;
if ( F_362 ( V_23 ) -> V_422 >= 7 && ! F_401 ( V_23 ) &&
! F_402 ( V_23 ) )
V_23 -> V_461 = 32 ;
else if ( F_362 ( V_23 ) -> V_422 >= 4 || F_403 ( V_23 ) ||
F_404 ( V_23 ) || F_187 ( V_23 ) )
V_23 -> V_461 = 16 ;
else
V_23 -> V_461 = 8 ;
if ( F_405 ( V_23 ) )
V_23 -> V_461 =
F_364 ( F_406 ( V_462 . V_463 ) ) ;
for ( V_55 = 0 ; V_55 < V_23 -> V_461 ; V_55 ++ ) {
struct V_464 * V_302 = & V_23 -> V_465 [ V_55 ] ;
V_302 -> V_14 = V_23 ;
V_302 -> V_275 = V_55 ;
F_224 ( & V_302 -> V_466 , & V_23 -> V_19 . V_467 ) ;
}
F_254 ( V_2 ) ;
F_407 ( V_2 ) ;
}
void
F_408 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
int V_55 ;
V_23 -> V_107 =
F_409 ( L_15 ,
sizeof( struct V_6 ) , 0 ,
V_468 ,
NULL ) ;
V_23 -> V_469 =
F_409 ( L_16 ,
sizeof( struct V_39 ) , 0 ,
V_468 ,
NULL ) ;
V_23 -> V_470 =
F_409 ( L_17 ,
sizeof( struct V_271 ) , 0 ,
V_468 |
V_471 |
V_472 ,
NULL ) ;
F_261 ( & V_23 -> V_473 ) ;
F_261 ( & V_23 -> V_19 . V_257 ) ;
F_261 ( & V_23 -> V_19 . V_276 ) ;
F_261 ( & V_23 -> V_19 . V_467 ) ;
for ( V_55 = 0 ; V_55 < V_399 ; V_55 ++ )
F_399 ( & V_23 -> V_274 [ V_55 ] ) ;
F_410 ( & V_23 -> V_305 . V_319 ,
F_268 ) ;
F_410 ( & V_23 -> V_305 . V_316 ,
F_274 ) ;
F_411 ( & V_23 -> V_32 . V_474 ) ;
F_411 ( & V_23 -> V_32 . V_29 ) ;
V_23 -> V_475 = V_476 ;
F_411 ( & V_23 -> V_477 ) ;
V_23 -> V_19 . V_478 = true ;
F_412 ( & V_23 -> V_19 . V_479 , 0 ) ;
F_413 ( & V_23 -> V_480 . V_387 ) ;
}
void F_414 ( struct V_1 * V_2 )
{
struct V_13 * V_23 = F_17 ( V_2 ) ;
F_415 ( V_23 -> V_470 ) ;
F_415 ( V_23 -> V_469 ) ;
F_415 ( V_23 -> V_107 ) ;
F_416 () ;
}
int F_417 ( struct V_13 * V_23 )
{
F_134 ( V_23 ) ;
F_20 ( & V_23 -> V_231 . V_33 ) ;
F_214 ( V_23 ) ;
F_23 ( & V_23 -> V_231 . V_33 ) ;
F_135 ( V_23 ) ;
return 0 ;
}
int F_418 ( struct V_13 * V_23 )
{
struct V_6 * V_7 ;
struct V_481 * V_482 [] = {
& V_23 -> V_19 . V_257 ,
& V_23 -> V_19 . V_276 ,
NULL
} , * * V_483 ;
F_20 ( & V_23 -> V_231 . V_33 ) ;
F_213 ( V_23 , - 1UL , V_249 ) ;
for ( V_483 = V_482 ; * V_483 ; V_483 ++ ) {
F_21 (obj, *p, global_list) {
V_7 -> V_8 . V_69 = V_10 ;
V_7 -> V_8 . V_9 = V_10 ;
}
}
F_23 ( & V_23 -> V_231 . V_33 ) ;
return 0 ;
}
void F_419 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_91 * V_101 = V_36 -> V_93 ;
struct V_271 * V_272 ;
F_9 ( & V_101 -> V_19 . V_387 ) ;
F_21 (request, &file_priv->mm.request_list, client_list)
V_272 -> V_101 = NULL ;
F_10 ( & V_101 -> V_19 . V_387 ) ;
if ( ! F_295 ( & V_101 -> V_89 . V_466 ) ) {
F_9 ( & F_17 ( V_2 ) -> V_89 . V_484 ) ;
F_205 ( & V_101 -> V_89 . V_466 ) ;
F_10 ( & F_17 ( V_2 ) -> V_89 . V_484 ) ;
}
}
int F_420 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_91 * V_101 ;
int V_28 ;
F_249 ( L_18 ) ;
V_101 = F_421 ( sizeof( * V_101 ) , V_60 ) ;
if ( ! V_101 )
return - V_61 ;
V_36 -> V_93 = V_101 ;
V_101 -> V_23 = F_17 ( V_2 ) ;
V_101 -> V_36 = V_36 ;
F_261 ( & V_101 -> V_89 . V_466 ) ;
F_413 ( & V_101 -> V_19 . V_387 ) ;
F_261 ( & V_101 -> V_19 . V_460 ) ;
V_101 -> V_485 = - 1 ;
V_28 = F_422 ( V_2 , V_36 ) ;
if ( V_28 )
F_37 ( V_101 ) ;
return V_28 ;
}
void F_423 ( struct V_6 * V_486 ,
struct V_6 * V_487 ,
unsigned V_416 )
{
F_331 ( V_488 * V_489 >
sizeof( V_490 ) * V_491 ) ;
if ( V_486 ) {
F_25 ( ! ( F_352 ( & V_486 -> V_416 ) & V_416 ) ) ;
F_424 ( V_416 , & V_486 -> V_416 ) ;
}
if ( V_487 ) {
F_25 ( F_352 ( & V_487 -> V_416 ) & V_416 ) ;
F_425 ( V_416 , & V_487 -> V_416 ) ;
}
}
struct V_58 *
F_426 ( struct V_6 * V_7 , int V_492 )
{
struct V_58 * V_58 ;
if ( F_25 ( ! F_95 ( V_7 ) ) )
return NULL ;
V_58 = F_427 ( V_7 , V_492 ) ;
F_43 ( V_58 ) ;
return V_58 ;
}
struct V_6 *
F_428 ( struct V_1 * V_2 ,
const void * V_34 , T_2 V_17 )
{
struct V_6 * V_7 ;
struct V_51 * V_54 ;
T_2 V_493 ;
int V_28 ;
V_7 = F_82 ( V_2 , F_106 ( V_17 , V_57 ) ) ;
if ( F_28 ( V_7 ) )
return V_7 ;
V_28 = F_42 ( V_7 , true ) ;
if ( V_28 )
goto V_408;
V_28 = F_69 ( V_7 ) ;
if ( V_28 )
goto V_408;
F_96 ( V_7 ) ;
V_54 = V_7 -> V_66 ;
V_493 = F_429 ( V_54 -> V_62 , V_54 -> V_247 , ( void * ) V_34 , V_17 ) ;
V_7 -> V_71 = 1 ;
F_99 ( V_7 ) ;
if ( F_25 ( V_493 != V_17 ) ) {
F_15 ( L_19 , V_493 , V_17 ) ;
V_28 = - V_97 ;
goto V_408;
}
return V_7 ;
V_408:
F_136 ( V_7 ) ;
return F_118 ( V_28 ) ;
}

static bool F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 == V_5 )
return false ;
if ( ! F_2 ( V_2 ) )
return true ;
return V_2 -> V_6 ;
}
static int
F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 , T_1 V_11 )
{
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
return F_4 ( & V_8 -> V_3 . V_12 , V_10 ,
V_11 , 0 , V_13 ,
0 , V_8 -> V_14 ,
V_15 ) ;
}
static void
F_5 ( struct V_9 * V_10 )
{
F_6 ( V_10 ) ;
}
static void F_7 ( struct V_16 * V_17 ,
T_2 V_11 )
{
F_8 ( & V_17 -> V_12 . V_18 ) ;
V_17 -> V_12 . V_19 ++ ;
V_17 -> V_12 . V_20 += V_11 ;
F_9 ( & V_17 -> V_12 . V_18 ) ;
}
static void F_10 ( struct V_16 * V_17 ,
T_2 V_11 )
{
F_8 ( & V_17 -> V_12 . V_18 ) ;
V_17 -> V_12 . V_19 -- ;
V_17 -> V_12 . V_20 -= V_11 ;
F_9 ( & V_17 -> V_12 . V_18 ) ;
}
static int
F_11 ( struct V_21 * error )
{
int V_22 ;
F_12 () ;
V_22 = F_13 ( error -> V_23 ,
! F_14 ( error ) ,
V_24 ) ;
if ( V_22 == 0 ) {
F_15 ( L_1 ) ;
return - V_25 ;
} else if ( V_22 < 0 ) {
return V_22 ;
} else {
return 0 ;
}
}
int F_16 ( struct V_26 * V_27 )
{
struct V_16 * V_17 = F_17 ( V_27 ) ;
int V_22 ;
V_22 = F_11 ( & V_17 -> V_28 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_18 ( & V_27 -> V_29 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
int
F_19 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_16 * V_17 = F_17 ( V_27 ) ;
struct V_7 * V_8 = & V_17 -> V_8 ;
struct V_33 * args = V_30 ;
struct V_34 * V_35 ;
T_3 V_36 ;
V_36 = 0 ;
F_20 ( & V_27 -> V_29 ) ;
F_21 (vma, &ggtt->base.active_list, vm_link)
if ( F_22 ( V_35 ) )
V_36 += V_35 -> V_10 . V_11 ;
F_21 (vma, &ggtt->base.inactive_list, vm_link)
if ( F_22 ( V_35 ) )
V_36 += V_35 -> V_10 . V_11 ;
F_23 ( & V_27 -> V_29 ) ;
args -> V_37 = V_8 -> V_3 . V_38 ;
args -> V_39 = args -> V_37 - V_36 ;
return 0 ;
}
static struct V_40 *
F_24 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_3 . V_43 -> V_44 ;
T_4 * V_45 ;
struct V_40 * V_46 ;
struct V_47 * V_48 ;
char * V_49 ;
int V_50 ;
if ( F_25 ( F_26 ( V_2 ) ) )
return F_27 ( - V_51 ) ;
V_45 = F_28 ( V_2 -> V_3 . V_27 ,
V_2 -> V_3 . V_11 ,
F_29 ( V_2 -> V_3 . V_11 ) ) ;
if ( ! V_45 )
return F_27 ( - V_52 ) ;
V_49 = V_45 -> V_49 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_3 . V_11 / V_53 ; V_50 ++ ) {
struct V_54 * V_54 ;
char * V_55 ;
V_54 = F_30 ( V_42 , V_50 ) ;
if ( F_31 ( V_54 ) ) {
V_46 = F_32 ( V_54 ) ;
goto V_56;
}
V_55 = F_33 ( V_54 ) ;
memcpy ( V_49 , V_55 , V_53 ) ;
F_34 ( V_49 , V_53 ) ;
F_35 ( V_55 ) ;
F_36 ( V_54 ) ;
V_49 += V_53 ;
}
F_37 ( F_17 ( V_2 -> V_3 . V_27 ) ) ;
V_46 = F_38 ( sizeof( * V_46 ) , V_57 ) ;
if ( ! V_46 ) {
V_46 = F_27 ( - V_52 ) ;
goto V_56;
}
if ( F_39 ( V_46 , 1 , V_57 ) ) {
F_40 ( V_46 ) ;
V_46 = F_27 ( - V_52 ) ;
goto V_56;
}
V_48 = V_46 -> V_58 ;
V_48 -> V_59 = 0 ;
V_48 -> V_60 = V_2 -> V_3 . V_11 ;
F_41 ( V_48 ) = V_45 -> V_61 ;
F_42 ( V_48 ) = V_2 -> V_3 . V_11 ;
V_2 -> V_62 = V_45 ;
return V_46 ;
V_56:
F_43 ( V_2 -> V_3 . V_27 , V_45 ) ;
return V_46 ;
}
static void
F_44 ( struct V_1 * V_2 ,
struct V_40 * V_63 ,
bool V_64 )
{
F_45 ( V_2 -> V_12 . V_65 == V_66 ) ;
if ( V_2 -> V_12 . V_65 == V_67 )
V_2 -> V_12 . V_68 = false ;
if ( V_64 &&
( V_2 -> V_3 . V_69 & V_5 ) == 0 &&
! F_2 ( V_2 ) )
F_46 ( V_63 ) ;
V_2 -> V_3 . V_69 = V_5 ;
V_2 -> V_3 . V_4 = V_5 ;
}
static void
F_47 ( struct V_1 * V_2 ,
struct V_40 * V_63 )
{
F_44 ( V_2 , V_63 , false ) ;
if ( V_2 -> V_12 . V_68 ) {
struct V_41 * V_42 = V_2 -> V_3 . V_43 -> V_44 ;
char * V_49 = V_2 -> V_62 -> V_49 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_3 . V_11 / V_53 ; V_50 ++ ) {
struct V_54 * V_54 ;
char * V_70 ;
V_54 = F_30 ( V_42 , V_50 ) ;
if ( F_31 ( V_54 ) )
continue;
V_70 = F_33 ( V_54 ) ;
F_34 ( V_49 , V_53 ) ;
memcpy ( V_70 , V_49 , V_53 ) ;
F_35 ( V_70 ) ;
F_48 ( V_54 ) ;
if ( V_2 -> V_12 . V_65 == V_71 )
F_49 ( V_54 ) ;
F_36 ( V_54 ) ;
V_49 += V_53 ;
}
V_2 -> V_12 . V_68 = false ;
}
F_50 ( V_63 ) ;
F_40 ( V_63 ) ;
F_43 ( V_2 -> V_3 . V_27 , V_2 -> V_62 ) ;
}
static void
F_51 ( struct V_1 * V_2 )
{
F_52 ( V_2 ) ;
}
int F_53 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
F_54 ( V_72 ) ;
int V_22 ;
F_55 ( & V_2 -> V_3 . V_27 -> V_29 ) ;
V_22 = F_56 ( V_2 ,
V_73 |
V_74 |
V_75 ,
V_76 ,
NULL ) ;
if ( V_22 )
return V_22 ;
F_57 ( F_17 ( V_2 -> V_3 . V_27 ) ) ;
while ( ( V_35 = F_58 ( & V_2 -> V_77 ,
struct V_34 ,
V_78 ) ) ) {
F_59 ( & V_35 -> V_78 , & V_72 ) ;
V_22 = F_60 ( V_35 ) ;
if ( V_22 )
break;
}
F_61 ( & V_72 , & V_2 -> V_77 ) ;
return V_22 ;
}
static long
F_62 ( struct V_79 * V_80 ,
unsigned int V_81 ,
long V_82 ,
struct V_83 * V_84 )
{
struct V_85 * V_86 ;
F_63 ( V_73 != 0x1 ) ;
if ( F_64 ( V_87 , & V_80 -> V_81 ) )
return V_82 ;
if ( ! F_65 ( V_80 ) )
return F_66 ( V_80 ,
V_81 & V_73 ,
V_82 ) ;
V_86 = F_67 ( V_80 ) ;
if ( F_68 ( V_86 ) )
goto V_88;
if ( V_84 ) {
if ( F_69 ( V_86 -> V_89 ) >= 6 )
F_70 ( V_86 -> V_89 , V_84 , V_86 -> V_90 ) ;
else
V_84 = NULL ;
}
V_82 = F_71 ( V_86 , V_81 , V_82 ) ;
V_88:
if ( V_81 & V_74 && F_68 ( V_86 ) )
F_72 ( V_86 ) ;
if ( V_84 && F_73 ( V_86 ) == F_74 ( V_86 -> V_91 ) ) {
F_8 ( & V_86 -> V_89 -> V_84 . V_92 ) ;
F_75 ( & V_84 -> V_93 ) ;
F_9 ( & V_86 -> V_89 -> V_84 . V_92 ) ;
}
return V_82 ;
}
static long
F_76 ( struct V_94 * V_95 ,
unsigned int V_81 ,
long V_82 ,
struct V_83 * V_84 )
{
unsigned int V_96 = F_77 ( & V_95 -> V_96 ) ;
struct V_79 * V_97 ;
bool V_98 = false ;
if ( V_81 & V_75 ) {
struct V_79 * * V_99 ;
unsigned int V_100 , V_50 ;
int V_22 ;
V_22 = F_78 ( V_95 ,
& V_97 , & V_100 , & V_99 ) ;
if ( V_22 )
return V_22 ;
for ( V_50 = 0 ; V_50 < V_100 ; V_50 ++ ) {
V_82 = F_62 ( V_99 [ V_50 ] ,
V_81 , V_82 ,
V_84 ) ;
if ( V_82 < 0 )
break;
F_79 ( V_99 [ V_50 ] ) ;
}
for (; V_50 < V_100 ; V_50 ++ )
F_79 ( V_99 [ V_50 ] ) ;
F_40 ( V_99 ) ;
V_98 = V_100 && V_82 >= 0 ;
} else {
V_97 = F_80 ( V_95 ) ;
}
if ( V_97 && V_82 >= 0 ) {
V_82 = F_62 ( V_97 , V_81 , V_82 , V_84 ) ;
V_98 = V_82 >= 0 ;
}
F_79 ( V_97 ) ;
if ( V_98 && ! F_81 ( & V_95 -> V_96 , V_96 ) ) {
if ( F_82 ( V_95 ) ) {
if ( ! F_81 ( & V_95 -> V_96 , V_96 ) )
F_83 ( V_95 , NULL ) ;
F_84 ( V_95 ) ;
}
}
return V_82 ;
}
static void F_85 ( struct V_79 * V_80 , int V_101 )
{
struct V_85 * V_86 ;
struct V_102 * V_91 ;
if ( ! F_65 ( V_80 ) )
return;
V_86 = F_67 ( V_80 ) ;
V_91 = V_86 -> V_91 ;
if ( ! V_91 -> V_103 )
return;
V_91 -> V_103 ( V_86 , V_101 ) ;
}
static void F_86 ( struct V_79 * V_80 , int V_101 )
{
if ( F_87 ( V_80 ) ) {
struct V_104 * V_105 = F_88 ( V_80 ) ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_105 -> V_106 ; V_50 ++ )
F_85 ( V_105 -> V_107 [ V_50 ] , V_101 ) ;
} else {
F_85 ( V_80 , V_101 ) ;
}
}
int
F_89 ( struct V_1 * V_2 ,
unsigned int V_81 ,
int V_101 )
{
struct V_79 * V_97 ;
if ( V_81 & V_75 ) {
struct V_79 * * V_99 ;
unsigned int V_100 , V_50 ;
int V_22 ;
V_22 = F_78 ( V_2 -> V_95 ,
& V_97 , & V_100 , & V_99 ) ;
if ( V_22 )
return V_22 ;
for ( V_50 = 0 ; V_50 < V_100 ; V_50 ++ ) {
F_86 ( V_99 [ V_50 ] , V_101 ) ;
F_79 ( V_99 [ V_50 ] ) ;
}
F_40 ( V_99 ) ;
} else {
V_97 = F_80 ( V_2 -> V_95 ) ;
}
if ( V_97 ) {
F_86 ( V_97 , V_101 ) ;
F_79 ( V_97 ) ;
}
return 0 ;
}
int
F_56 ( struct V_1 * V_2 ,
unsigned int V_81 ,
long V_82 ,
struct V_83 * V_84 )
{
F_12 () ;
#if F_90 ( V_108 )
F_45 ( V_109 &&
! ! F_91 ( & V_2 -> V_3 . V_27 -> V_29 ) !=
! ! ( V_81 & V_74 ) ) ;
#endif
F_45 ( V_82 < 0 ) ;
V_82 = F_76 ( V_2 -> V_95 ,
V_81 , V_82 ,
V_84 ) ;
return V_82 < 0 ? V_82 : 0 ;
}
static struct V_83 * F_92 ( struct V_31 * V_32 )
{
struct V_110 * V_111 = V_32 -> V_112 ;
return & V_111 -> V_84 ;
}
int
F_93 ( struct V_1 * V_2 ,
int V_113 )
{
int V_22 ;
if ( V_113 > V_2 -> V_3 . V_11 )
return - V_51 ;
if ( V_2 -> V_114 == & V_115 )
return 0 ;
if ( V_2 -> V_12 . V_65 != V_71 )
return - V_116 ;
if ( V_2 -> V_3 . V_43 == NULL )
return - V_51 ;
V_22 = F_53 ( V_2 ) ;
if ( V_22 )
return V_22 ;
F_94 ( V_2 , V_117 ) ;
if ( V_2 -> V_12 . V_63 )
return - V_118 ;
F_45 ( V_2 -> V_114 != & V_119 ) ;
V_2 -> V_114 = & V_115 ;
V_22 = F_95 ( V_2 ) ;
if ( V_22 )
goto V_120;
return 0 ;
V_120:
V_2 -> V_114 = & V_119 ;
return V_22 ;
}
static int
F_96 ( struct V_1 * V_2 ,
struct V_121 * args ,
struct V_31 * V_32 )
{
void * V_49 = V_2 -> V_62 -> V_49 + args -> V_59 ;
char T_5 * V_122 = F_97 ( args -> V_123 ) ;
F_98 ( V_2 , V_124 ) ;
if ( F_99 ( V_49 , V_122 , args -> V_11 ) )
return - V_116 ;
F_34 ( V_49 , args -> V_11 ) ;
F_37 ( F_17 ( V_2 -> V_3 . V_27 ) ) ;
F_100 ( V_2 , V_124 ) ;
return 0 ;
}
void * F_101 ( struct V_16 * V_17 )
{
return F_102 ( V_17 -> V_125 , V_57 ) ;
}
void F_103 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_17 ( V_2 -> V_3 . V_27 ) ;
F_104 ( V_17 -> V_125 , V_2 ) ;
}
static int
F_105 ( struct V_31 * V_32 ,
struct V_16 * V_17 ,
T_6 V_11 ,
T_7 * V_126 )
{
struct V_1 * V_2 ;
int V_22 ;
T_1 V_127 ;
V_11 = F_106 ( V_11 , V_53 ) ;
if ( V_11 == 0 )
return - V_51 ;
V_2 = F_107 ( V_17 , V_11 ) ;
if ( F_31 ( V_2 ) )
return F_108 ( V_2 ) ;
V_22 = F_109 ( V_32 , & V_2 -> V_3 , & V_127 ) ;
F_110 ( V_2 ) ;
if ( V_22 )
return V_22 ;
* V_126 = V_127 ;
return 0 ;
}
int
F_111 ( struct V_31 * V_32 ,
struct V_26 * V_27 ,
struct V_128 * args )
{
args -> V_129 = F_112 ( args -> V_130 * F_113 ( args -> V_131 , 8 ) , 64 ) ;
args -> V_11 = args -> V_129 * args -> V_132 ;
return F_105 ( V_32 , F_17 ( V_27 ) ,
args -> V_11 , & args -> V_127 ) ;
}
int
F_114 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_16 * V_17 = F_17 ( V_27 ) ;
struct V_133 * args = V_30 ;
F_115 ( V_17 ) ;
return F_105 ( V_32 , V_17 ,
args -> V_11 , & args -> V_127 ) ;
}
static inline int
F_116 ( char T_5 * V_134 ,
const char * V_135 , int V_136 ,
int V_60 )
{
int V_22 , V_137 = 0 ;
while ( V_60 > 0 ) {
int V_138 = F_112 ( V_136 + 1 , 64 ) ;
int V_139 = F_117 ( V_138 - V_136 , V_60 ) ;
int V_140 = V_136 ^ 64 ;
V_22 = F_118 ( V_134 + V_137 ,
V_135 + V_140 ,
V_139 ) ;
if ( V_22 )
return V_22 + V_60 ;
V_137 += V_139 ;
V_136 += V_139 ;
V_60 -= V_139 ;
}
return 0 ;
}
static inline int
F_119 ( char * V_135 , int V_136 ,
const char T_5 * V_134 ,
int V_60 )
{
int V_22 , V_137 = 0 ;
while ( V_60 > 0 ) {
int V_138 = F_112 ( V_136 + 1 , 64 ) ;
int V_139 = F_117 ( V_138 - V_136 , V_60 ) ;
int V_140 = V_136 ^ 64 ;
V_22 = F_120 ( V_135 + V_140 ,
V_134 + V_137 ,
V_139 ) ;
if ( V_22 )
return V_22 + V_60 ;
V_137 += V_139 ;
V_136 += V_139 ;
V_60 -= V_139 ;
}
return 0 ;
}
int F_121 ( struct V_1 * V_2 ,
unsigned int * V_64 )
{
int V_22 ;
F_55 ( & V_2 -> V_3 . V_27 -> V_29 ) ;
* V_64 = 0 ;
if ( ! F_122 ( V_2 ) )
return - V_141 ;
V_22 = F_56 ( V_2 ,
V_73 |
V_74 ,
V_76 ,
NULL ) ;
if ( V_22 )
return V_22 ;
V_22 = F_95 ( V_2 ) ;
if ( V_22 )
return V_22 ;
if ( F_2 ( V_2 ) ||
! F_123 ( V_142 ) ) {
V_22 = F_124 ( V_2 , false ) ;
if ( V_22 )
goto V_143;
else
goto V_88;
}
F_125 ( V_2 ) ;
if ( ! ( V_2 -> V_3 . V_69 & V_5 ) )
* V_64 = V_144 ;
V_88:
return 0 ;
V_143:
F_52 ( V_2 ) ;
return V_22 ;
}
int F_126 ( struct V_1 * V_2 ,
unsigned int * V_64 )
{
int V_22 ;
F_55 ( & V_2 -> V_3 . V_27 -> V_29 ) ;
* V_64 = 0 ;
if ( ! F_122 ( V_2 ) )
return - V_141 ;
V_22 = F_56 ( V_2 ,
V_73 |
V_74 |
V_75 ,
V_76 ,
NULL ) ;
if ( V_22 )
return V_22 ;
V_22 = F_95 ( V_2 ) ;
if ( V_22 )
return V_22 ;
if ( F_2 ( V_2 ) ||
! F_123 ( V_142 ) ) {
V_22 = F_124 ( V_2 , true ) ;
if ( V_22 )
goto V_143;
else
goto V_88;
}
F_125 ( V_2 ) ;
if ( V_2 -> V_3 . V_4 != V_5 )
* V_64 |= V_145 ;
if ( ! ( V_2 -> V_3 . V_69 & V_5 ) )
* V_64 |= V_144 ;
V_88:
F_98 ( V_2 , V_124 ) ;
V_2 -> V_12 . V_68 = true ;
return 0 ;
V_143:
F_52 ( V_2 ) ;
return V_22 ;
}
static void
F_127 ( char * V_146 , unsigned long V_60 ,
bool V_147 )
{
if ( F_128 ( V_147 ) ) {
unsigned long V_148 = ( unsigned long ) V_146 ;
unsigned long V_149 = ( unsigned long ) V_146 + V_60 ;
V_148 = F_129 ( V_148 , 128 ) ;
V_149 = F_130 ( V_149 , 128 ) ;
F_34 ( ( void * ) V_148 , V_149 - V_148 ) ;
} else {
F_34 ( V_146 , V_60 ) ;
}
}
static int
F_131 ( struct V_54 * V_54 , int V_59 , int V_60 ,
char T_5 * V_122 ,
bool V_150 , bool V_64 )
{
char * V_49 ;
int V_22 ;
V_49 = F_132 ( V_54 ) ;
if ( V_64 )
F_127 ( V_49 + V_59 , V_60 ,
V_150 ) ;
if ( V_150 )
V_22 = F_116 ( V_122 , V_49 , V_59 , V_60 ) ;
else
V_22 = F_118 ( V_122 , V_49 + V_59 , V_60 ) ;
F_133 ( V_54 ) ;
return V_22 ? - V_116 : 0 ;
}
static int
F_134 ( struct V_54 * V_54 , int V_59 , int V_60 , char T_5 * V_122 ,
bool V_150 , bool V_64 )
{
int V_22 ;
V_22 = - V_141 ;
if ( ! V_150 ) {
char * V_49 = F_33 ( V_54 ) ;
if ( V_64 )
F_34 ( V_49 + V_59 , V_60 ) ;
V_22 = F_135 ( V_122 , V_49 + V_59 , V_60 ) ;
F_35 ( V_49 ) ;
}
if ( V_22 == 0 )
return 0 ;
return F_131 ( V_54 , V_59 , V_60 , V_122 ,
V_150 , V_64 ) ;
}
static int
F_136 ( struct V_1 * V_2 ,
struct V_151 * args )
{
char T_5 * V_122 ;
T_2 V_152 ;
unsigned int V_153 ;
unsigned int V_64 ;
unsigned int V_154 , V_59 ;
int V_22 ;
V_153 = 0 ;
if ( F_26 ( V_2 ) )
V_153 = F_137 ( 17 ) ;
V_22 = F_18 ( & V_2 -> V_3 . V_27 -> V_29 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_121 ( V_2 , & V_64 ) ;
F_23 ( & V_2 -> V_3 . V_27 -> V_29 ) ;
if ( V_22 )
return V_22 ;
V_152 = args -> V_11 ;
V_122 = F_97 ( args -> V_123 ) ;
V_59 = F_138 ( args -> V_59 ) ;
for ( V_154 = args -> V_59 >> V_155 ; V_152 ; V_154 ++ ) {
struct V_54 * V_54 = F_139 ( V_2 , V_154 ) ;
int V_60 ;
V_60 = V_152 ;
if ( V_59 + V_60 > V_53 )
V_60 = V_53 - V_59 ;
V_22 = F_134 ( V_54 , V_59 , V_60 , V_122 ,
F_140 ( V_54 ) & V_153 ,
V_64 ) ;
if ( V_22 )
break;
V_152 -= V_60 ;
V_122 += V_60 ;
V_59 = 0 ;
}
F_141 ( V_2 ) ;
return V_22 ;
}
static inline bool
F_142 ( struct V_156 * V_42 ,
T_8 V_3 , int V_59 ,
char T_5 * V_122 , int V_60 )
{
void * V_49 ;
unsigned long V_157 ;
V_49 = ( void V_158 * ) F_143 ( V_42 , V_3 ) ;
V_157 = F_135 ( V_122 , V_49 + V_59 , V_60 ) ;
F_144 ( V_49 ) ;
if ( V_157 ) {
V_49 = ( void V_158 * )
F_145 ( V_42 , V_3 , V_53 ) ;
V_157 = F_146 ( V_122 , V_49 + V_59 , V_60 ) ;
F_147 ( V_49 ) ;
}
return V_157 ;
}
static int
F_148 ( struct V_1 * V_2 ,
const struct V_151 * args )
{
struct V_16 * V_89 = F_17 ( V_2 -> V_3 . V_27 ) ;
struct V_7 * V_8 = & V_89 -> V_8 ;
struct V_9 V_10 ;
struct V_34 * V_35 ;
void T_5 * V_122 ;
T_2 V_152 , V_59 ;
int V_22 ;
V_22 = F_18 ( & V_89 -> V_159 . V_29 ) ;
if ( V_22 )
return V_22 ;
F_149 ( V_89 ) ;
V_35 = F_150 ( V_2 , NULL , 0 , 0 ,
V_160 | V_161 ) ;
if ( ! F_31 ( V_35 ) ) {
V_10 . V_148 = F_151 ( V_35 ) ;
V_10 . V_162 = false ;
V_22 = F_152 ( V_35 ) ;
if ( V_22 ) {
F_153 ( V_35 ) ;
V_35 = F_27 ( V_22 ) ;
}
}
if ( F_31 ( V_35 ) ) {
V_22 = F_3 ( V_8 , & V_10 , V_53 ) ;
if ( V_22 )
goto V_163;
F_45 ( ! V_10 . V_162 ) ;
}
V_22 = F_154 ( V_2 , false ) ;
if ( V_22 )
goto V_164;
F_23 ( & V_89 -> V_159 . V_29 ) ;
V_122 = F_97 ( args -> V_123 ) ;
V_152 = args -> V_11 ;
V_59 = args -> V_59 ;
while ( V_152 > 0 ) {
T_1 V_165 = V_10 . V_148 ;
unsigned V_166 = F_138 ( V_59 ) ;
unsigned V_167 = V_53 - V_166 ;
V_167 = V_152 < V_167 ? V_152 : V_167 ;
if ( V_10 . V_162 ) {
F_155 () ;
V_8 -> V_3 . V_168 ( & V_8 -> V_3 ,
F_156 ( V_2 , V_59 >> V_155 ) ,
V_10 . V_148 , V_169 , 0 ) ;
F_155 () ;
} else {
V_165 += V_59 & V_170 ;
}
if ( F_142 ( & V_8 -> V_171 , V_165 , V_166 ,
V_122 , V_167 ) ) {
V_22 = - V_116 ;
break;
}
V_152 -= V_167 ;
V_122 += V_167 ;
V_59 += V_167 ;
}
F_20 ( & V_89 -> V_159 . V_29 ) ;
V_164:
if ( V_10 . V_162 ) {
F_155 () ;
V_8 -> V_3 . V_172 ( & V_8 -> V_3 ,
V_10 . V_148 , V_10 . V_11 ) ;
F_5 ( & V_10 ) ;
} else {
F_153 ( V_35 ) ;
}
V_163:
F_157 ( V_89 ) ;
F_23 ( & V_89 -> V_159 . V_29 ) ;
return V_22 ;
}
int
F_158 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_151 * args = V_30 ;
struct V_1 * V_2 ;
int V_22 ;
if ( args -> V_11 == 0 )
return 0 ;
if ( ! F_159 ( V_173 ,
F_97 ( args -> V_123 ) ,
args -> V_11 ) )
return - V_116 ;
V_2 = F_160 ( V_32 , args -> V_127 ) ;
if ( ! V_2 )
return - V_174 ;
if ( F_161 ( T_2 , args -> V_59 , args -> V_11 , V_2 -> V_3 . V_11 ) ) {
V_22 = - V_51 ;
goto V_88;
}
F_162 ( V_2 , args -> V_59 , args -> V_11 ) ;
V_22 = F_56 ( V_2 ,
V_73 ,
V_76 ,
F_92 ( V_32 ) ) ;
if ( V_22 )
goto V_88;
V_22 = F_95 ( V_2 ) ;
if ( V_22 )
goto V_88;
V_22 = F_136 ( V_2 , args ) ;
if ( V_22 == - V_116 || V_22 == - V_141 )
V_22 = F_148 ( V_2 , args ) ;
F_52 ( V_2 ) ;
V_88:
F_110 ( V_2 ) ;
return V_22 ;
}
static inline bool
F_163 ( struct V_156 * V_42 ,
T_8 V_3 , int V_59 ,
char T_5 * V_122 , int V_60 )
{
void * V_49 ;
unsigned long V_157 ;
V_49 = ( void V_158 * ) F_143 ( V_42 , V_3 ) ;
V_157 = F_164 ( V_49 + V_59 ,
V_122 , V_60 ) ;
F_144 ( V_49 ) ;
if ( V_157 ) {
V_49 = ( void V_158 * )
F_145 ( V_42 , V_3 , V_53 ) ;
V_157 = F_99 ( V_49 + V_59 , V_122 , V_60 ) ;
F_147 ( V_49 ) ;
}
return V_157 ;
}
static int
F_165 ( struct V_1 * V_2 ,
const struct V_121 * args )
{
struct V_16 * V_89 = F_17 ( V_2 -> V_3 . V_27 ) ;
struct V_7 * V_8 = & V_89 -> V_8 ;
struct V_9 V_10 ;
struct V_34 * V_35 ;
T_2 V_152 , V_59 ;
void T_5 * V_122 ;
int V_22 ;
V_22 = F_18 ( & V_89 -> V_159 . V_29 ) ;
if ( V_22 )
return V_22 ;
F_149 ( V_89 ) ;
V_35 = F_150 ( V_2 , NULL , 0 , 0 ,
V_160 | V_161 ) ;
if ( ! F_31 ( V_35 ) ) {
V_10 . V_148 = F_151 ( V_35 ) ;
V_10 . V_162 = false ;
V_22 = F_152 ( V_35 ) ;
if ( V_22 ) {
F_153 ( V_35 ) ;
V_35 = F_27 ( V_22 ) ;
}
}
if ( F_31 ( V_35 ) ) {
V_22 = F_3 ( V_8 , & V_10 , V_53 ) ;
if ( V_22 )
goto V_163;
F_45 ( ! V_10 . V_162 ) ;
}
V_22 = F_154 ( V_2 , true ) ;
if ( V_22 )
goto V_164;
F_23 ( & V_89 -> V_159 . V_29 ) ;
F_98 ( V_2 , V_124 ) ;
V_122 = F_97 ( args -> V_123 ) ;
V_59 = args -> V_59 ;
V_152 = args -> V_11 ;
while ( V_152 ) {
T_1 V_165 = V_10 . V_148 ;
unsigned int V_166 = F_138 ( V_59 ) ;
unsigned int V_167 = V_53 - V_166 ;
V_167 = V_152 < V_167 ? V_152 : V_167 ;
if ( V_10 . V_162 ) {
F_155 () ;
V_8 -> V_3 . V_168 ( & V_8 -> V_3 ,
F_156 ( V_2 , V_59 >> V_155 ) ,
V_10 . V_148 , V_169 , 0 ) ;
F_155 () ;
} else {
V_165 += V_59 & V_170 ;
}
if ( F_163 ( & V_8 -> V_171 , V_165 , V_166 ,
V_122 , V_167 ) ) {
V_22 = - V_116 ;
break;
}
V_152 -= V_167 ;
V_122 += V_167 ;
V_59 += V_167 ;
}
F_100 ( V_2 , V_124 ) ;
F_20 ( & V_89 -> V_159 . V_29 ) ;
V_164:
if ( V_10 . V_162 ) {
F_155 () ;
V_8 -> V_3 . V_172 ( & V_8 -> V_3 ,
V_10 . V_148 , V_10 . V_11 ) ;
F_5 ( & V_10 ) ;
} else {
F_153 ( V_35 ) ;
}
V_163:
F_157 ( V_89 ) ;
F_23 ( & V_89 -> V_159 . V_29 ) ;
return V_22 ;
}
static int
F_166 ( struct V_54 * V_54 , int V_59 , int V_60 ,
char T_5 * V_122 ,
bool V_150 ,
bool V_175 ,
bool V_176 )
{
char * V_49 ;
int V_22 ;
V_49 = F_132 ( V_54 ) ;
if ( F_128 ( V_175 || V_150 ) )
F_127 ( V_49 + V_59 , V_60 ,
V_150 ) ;
if ( V_150 )
V_22 = F_119 ( V_49 , V_59 , V_122 ,
V_60 ) ;
else
V_22 = F_120 ( V_49 + V_59 , V_122 , V_60 ) ;
if ( V_176 )
F_127 ( V_49 + V_59 , V_60 ,
V_150 ) ;
F_133 ( V_54 ) ;
return V_22 ? - V_116 : 0 ;
}
static int
F_167 ( struct V_54 * V_54 , int V_59 , int V_177 , char T_5 * V_122 ,
bool V_150 ,
bool V_175 ,
bool V_176 )
{
int V_22 ;
V_22 = - V_141 ;
if ( ! V_150 ) {
char * V_49 = F_33 ( V_54 ) ;
if ( V_175 )
F_34 ( V_49 + V_59 , V_177 ) ;
V_22 = F_168 ( V_49 + V_59 , V_122 , V_177 ) ;
if ( V_176 )
F_34 ( V_49 + V_59 , V_177 ) ;
F_35 ( V_49 ) ;
}
if ( V_22 == 0 )
return V_22 ;
return F_166 ( V_54 , V_59 , V_177 , V_122 ,
V_150 ,
V_175 ,
V_176 ) ;
}
static int
F_169 ( struct V_1 * V_2 ,
const struct V_121 * args )
{
struct V_16 * V_89 = F_17 ( V_2 -> V_3 . V_27 ) ;
void T_5 * V_122 ;
T_2 V_152 ;
unsigned int V_153 ;
unsigned int V_178 ;
unsigned int V_64 ;
unsigned int V_59 , V_154 ;
int V_22 ;
V_22 = F_18 ( & V_89 -> V_159 . V_29 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_126 ( V_2 , & V_64 ) ;
F_23 ( & V_89 -> V_159 . V_29 ) ;
if ( V_22 )
return V_22 ;
V_153 = 0 ;
if ( F_26 ( V_2 ) )
V_153 = F_137 ( 17 ) ;
V_178 = 0 ;
if ( V_64 & V_144 )
V_178 = V_179 . V_180 - 1 ;
V_122 = F_97 ( args -> V_123 ) ;
V_152 = args -> V_11 ;
V_59 = F_138 ( args -> V_59 ) ;
for ( V_154 = args -> V_59 >> V_155 ; V_152 ; V_154 ++ ) {
struct V_54 * V_54 = F_139 ( V_2 , V_154 ) ;
int V_60 ;
V_60 = V_152 ;
if ( V_59 + V_60 > V_53 )
V_60 = V_53 - V_59 ;
V_22 = F_167 ( V_54 , V_59 , V_60 , V_122 ,
F_140 ( V_54 ) & V_153 ,
( V_59 | V_60 ) & V_178 ,
V_64 & V_145 ) ;
if ( V_22 )
break;
V_152 -= V_60 ;
V_122 += V_60 ;
V_59 = 0 ;
}
F_100 ( V_2 , V_124 ) ;
F_141 ( V_2 ) ;
return V_22 ;
}
int
F_170 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_121 * args = V_30 ;
struct V_1 * V_2 ;
int V_22 ;
if ( args -> V_11 == 0 )
return 0 ;
if ( ! F_159 ( V_181 ,
F_97 ( args -> V_123 ) ,
args -> V_11 ) )
return - V_116 ;
V_2 = F_160 ( V_32 , args -> V_127 ) ;
if ( ! V_2 )
return - V_174 ;
if ( F_161 ( T_2 , args -> V_59 , args -> V_11 , V_2 -> V_3 . V_11 ) ) {
V_22 = - V_51 ;
goto V_182;
}
F_171 ( V_2 , args -> V_59 , args -> V_11 ) ;
V_22 = - V_141 ;
if ( V_2 -> V_114 -> V_183 )
V_22 = V_2 -> V_114 -> V_183 ( V_2 , args ) ;
if ( V_22 != - V_141 )
goto V_182;
V_22 = F_56 ( V_2 ,
V_73 |
V_75 ,
V_76 ,
F_92 ( V_32 ) ) ;
if ( V_22 )
goto V_182;
V_22 = F_95 ( V_2 ) ;
if ( V_22 )
goto V_182;
V_22 = - V_116 ;
if ( ! F_122 ( V_2 ) ||
F_1 ( V_2 ) )
V_22 = F_165 ( V_2 , args ) ;
if ( V_22 == - V_116 || V_22 == - V_184 ) {
if ( V_2 -> V_62 )
V_22 = F_96 ( V_2 , args , V_32 ) ;
else
V_22 = F_169 ( V_2 , args ) ;
}
F_52 ( V_2 ) ;
V_182:
F_110 ( V_2 ) ;
return V_22 ;
}
static inline enum V_185
F_172 ( struct V_1 * V_2 , unsigned V_186 )
{
return ( V_186 == V_187 ?
V_2 -> V_188 : V_124 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_16 * V_89 ;
struct V_189 * V_190 ;
struct V_34 * V_35 ;
F_21 (vma, &obj->vma_list, obj_link) {
if ( ! F_174 ( V_35 ) )
break;
if ( F_175 ( V_35 ) )
continue;
if ( ! F_176 ( & V_35 -> V_10 ) )
continue;
F_59 ( & V_35 -> V_191 , & V_35 -> V_192 -> V_193 ) ;
}
V_89 = F_17 ( V_2 -> V_3 . V_27 ) ;
V_190 = V_2 -> V_194 ? & V_89 -> V_12 . V_195 : & V_89 -> V_12 . V_196 ;
F_59 ( & V_2 -> V_197 , V_190 ) ;
}
int
F_177 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_198 * args = V_30 ;
struct V_1 * V_2 ;
T_7 V_69 = args -> V_69 ;
T_7 V_4 = args -> V_4 ;
int V_182 ;
if ( ( V_4 | V_69 ) & V_199 )
return - V_51 ;
if ( V_4 != 0 && V_69 != V_4 )
return - V_51 ;
V_2 = F_160 ( V_32 , args -> V_127 ) ;
if ( ! V_2 )
return - V_174 ;
V_182 = F_56 ( V_2 ,
V_73 |
( V_4 ? V_75 : 0 ) ,
V_76 ,
F_92 ( V_32 ) ) ;
if ( V_182 )
goto V_88;
V_182 = F_95 ( V_2 ) ;
if ( V_182 )
goto V_88;
V_182 = F_16 ( V_27 ) ;
if ( V_182 )
goto V_164;
if ( V_69 & V_187 )
V_182 = F_154 ( V_2 , V_4 != 0 ) ;
else
V_182 = F_124 ( V_2 , V_4 != 0 ) ;
F_173 ( V_2 ) ;
F_23 ( & V_27 -> V_29 ) ;
if ( V_4 != 0 )
F_98 ( V_2 , F_172 ( V_2 , V_4 ) ) ;
V_164:
F_52 ( V_2 ) ;
V_88:
F_110 ( V_2 ) ;
return V_182 ;
}
int
F_178 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_200 * args = V_30 ;
struct V_1 * V_2 ;
V_2 = F_160 ( V_32 , args -> V_127 ) ;
if ( ! V_2 )
return - V_174 ;
F_179 ( V_2 ) ;
F_110 ( V_2 ) ;
return 0 ;
}
int
F_180 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_201 * args = V_30 ;
struct V_1 * V_2 ;
unsigned long V_146 ;
if ( args -> V_81 & ~ ( V_202 ) )
return - V_51 ;
if ( args -> V_81 & V_202 && ! F_181 ( V_203 ) )
return - V_141 ;
V_2 = F_160 ( V_32 , args -> V_127 ) ;
if ( ! V_2 )
return - V_174 ;
if ( ! V_2 -> V_3 . V_43 ) {
F_110 ( V_2 ) ;
return - V_51 ;
}
V_146 = F_182 ( V_2 -> V_3 . V_43 , 0 , args -> V_11 ,
V_204 | V_205 , V_206 ,
args -> V_59 ) ;
if ( args -> V_81 & V_202 ) {
struct V_207 * V_12 = V_208 -> V_12 ;
struct V_209 * V_35 ;
if ( F_183 ( & V_12 -> V_210 ) ) {
F_110 ( V_2 ) ;
return - V_211 ;
}
V_35 = F_184 ( V_12 , V_146 ) ;
if ( V_35 )
V_35 -> V_212 =
F_185 ( F_186 ( V_35 -> V_213 ) ) ;
else
V_146 = - V_52 ;
F_187 ( & V_12 -> V_210 ) ;
F_188 ( V_2 -> V_188 , V_124 ) ;
}
F_110 ( V_2 ) ;
if ( F_31 ( ( void * ) V_146 ) )
return V_146 ;
args -> V_214 = ( T_6 ) V_146 ;
return 0 ;
}
static unsigned int F_189 ( struct V_1 * V_2 )
{
return F_190 ( V_2 ) >> V_155 ;
}
int F_191 ( void )
{
return 1 ;
}
static inline struct V_215
F_192 ( struct V_1 * V_2 ,
T_9 V_166 ,
unsigned int V_216 )
{
struct V_215 V_217 ;
if ( F_193 ( V_2 ) )
V_216 = F_106 ( V_216 , F_189 ( V_2 ) ) ;
V_217 . type = V_218 ;
V_217 . V_219 . V_59 = F_194 ( V_166 , V_216 ) ;
V_217 . V_219 . V_11 =
F_195 (unsigned int, chunk,
(obj->base.size >> PAGE_SHIFT) - view.partial.offset) ;
if ( V_216 >= V_2 -> V_3 . V_11 >> V_155 )
V_217 . type = V_220 ;
return V_217 ;
}
int F_196 ( struct V_221 * V_222 )
{
#define F_197 ((1 << 20) >> PAGE_SHIFT)
struct V_209 * V_223 = V_222 -> V_35 ;
struct V_1 * V_2 = F_198 ( V_223 -> V_224 ) ;
struct V_26 * V_27 = V_2 -> V_3 . V_27 ;
struct V_16 * V_17 = F_17 ( V_27 ) ;
struct V_7 * V_8 = & V_17 -> V_8 ;
bool V_225 = ! ! ( V_222 -> V_81 & V_226 ) ;
struct V_34 * V_35 ;
T_9 V_166 ;
unsigned int V_81 ;
int V_22 ;
V_166 = ( V_222 -> V_227 - V_223 -> V_228 ) >> V_155 ;
F_199 ( V_2 , V_166 , true , V_225 ) ;
V_22 = F_56 ( V_2 ,
V_73 ,
V_76 ,
NULL ) ;
if ( V_22 )
goto V_182;
V_22 = F_95 ( V_2 ) ;
if ( V_22 )
goto V_182;
F_149 ( V_17 ) ;
V_22 = F_16 ( V_27 ) ;
if ( V_22 )
goto V_229;
if ( V_2 -> V_230 != V_169 && ! F_200 ( V_17 ) ) {
V_22 = - V_116 ;
goto V_231;
}
V_81 = V_160 ;
if ( V_2 -> V_3 . V_11 > 2 * F_197 << V_155 )
V_81 |= V_161 | V_232 ;
V_35 = F_150 ( V_2 , NULL , 0 , 0 , V_81 ) ;
if ( F_31 ( V_35 ) ) {
struct V_215 V_217 =
F_192 ( V_2 , V_166 , F_197 ) ;
V_2 -> V_188 = V_124 ;
V_35 = F_150 ( V_2 , & V_217 , 0 , 0 , V_160 ) ;
}
if ( F_31 ( V_35 ) ) {
V_22 = F_108 ( V_35 ) ;
goto V_231;
}
V_22 = F_154 ( V_2 , V_225 ) ;
if ( V_22 )
goto V_143;
V_22 = F_201 ( V_35 ) ;
if ( V_22 )
goto V_143;
F_202 ( V_17 ) ;
if ( F_203 ( & V_2 -> V_233 ) )
F_204 ( & V_2 -> V_233 , & V_17 -> V_12 . V_234 ) ;
V_22 = F_205 ( V_223 ,
V_223 -> V_228 + ( V_35 -> V_235 . V_219 . V_59 << V_155 ) ,
( V_8 -> V_236 + V_35 -> V_10 . V_148 ) >> V_155 ,
F_195 ( T_2 , V_35 -> V_11 , V_223 -> V_237 - V_223 -> V_228 ) ,
& V_8 -> V_171 ) ;
V_143:
F_206 ( V_35 ) ;
V_231:
F_23 ( & V_27 -> V_29 ) ;
V_229:
F_157 ( V_17 ) ;
F_52 ( V_2 ) ;
V_182:
switch ( V_22 ) {
case - V_25 :
if ( ! F_207 ( & V_17 -> V_28 ) ) {
V_22 = V_238 ;
break;
}
case - V_239 :
case 0 :
case - V_240 :
case - V_211 :
case - V_118 :
V_22 = V_241 ;
break;
case - V_52 :
V_22 = V_242 ;
break;
case - V_184 :
case - V_116 :
V_22 = V_238 ;
break;
default:
F_208 ( V_22 , L_2 , V_22 ) ;
V_22 = V_238 ;
break;
}
return V_22 ;
}
void
F_209 ( struct V_1 * V_2 )
{
struct V_16 * V_89 = F_17 ( V_2 -> V_3 . V_27 ) ;
F_55 ( & V_89 -> V_159 . V_29 ) ;
F_149 ( V_89 ) ;
if ( F_203 ( & V_2 -> V_233 ) )
goto V_88;
F_75 ( & V_2 -> V_233 ) ;
F_210 ( & V_2 -> V_3 . V_243 ,
V_2 -> V_3 . V_27 -> V_244 -> V_245 ) ;
F_155 () ;
V_88:
F_157 ( V_89 ) ;
}
void F_211 ( struct V_16 * V_17 )
{
struct V_1 * V_2 , * V_246 ;
int V_50 ;
F_212 (obj, on,
&dev_priv->mm.userfault_list, userfault_link) {
F_75 ( & V_2 -> V_233 ) ;
F_210 ( & V_2 -> V_3 . V_243 ,
V_2 -> V_3 . V_27 -> V_244 -> V_245 ) ;
}
for ( V_50 = 0 ; V_50 < V_17 -> V_247 ; V_50 ++ ) {
struct V_248 * V_249 = & V_17 -> V_250 [ V_50 ] ;
if ( ! V_249 -> V_35 )
continue;
F_45 ( ! F_203 ( & V_249 -> V_35 -> V_2 -> V_233 ) ) ;
V_249 -> V_68 = true ;
}
}
static int F_213 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_17 ( V_2 -> V_3 . V_27 ) ;
int V_182 ;
V_182 = F_214 ( & V_2 -> V_3 ) ;
if ( F_215 ( ! V_182 ) )
return 0 ;
do {
V_182 = F_216 ( V_17 , V_73 ) ;
if ( V_182 )
break;
F_217 ( V_17 ) ;
V_182 = F_214 ( & V_2 -> V_3 ) ;
if ( ! V_182 )
break;
} while ( F_218 ( & V_17 -> V_251 . V_252 ) );
return V_182 ;
}
static void F_219 ( struct V_1 * V_2 )
{
F_220 ( & V_2 -> V_3 ) ;
}
int
F_221 ( struct V_31 * V_32 ,
struct V_26 * V_27 ,
T_7 V_127 ,
T_6 * V_59 )
{
struct V_1 * V_2 ;
int V_22 ;
V_2 = F_160 ( V_32 , V_127 ) ;
if ( ! V_2 )
return - V_174 ;
V_22 = F_213 ( V_2 ) ;
if ( V_22 == 0 )
* V_59 = F_222 ( & V_2 -> V_3 . V_243 ) ;
F_110 ( V_2 ) ;
return V_22 ;
}
int
F_223 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_253 * args = V_30 ;
return F_221 ( V_32 , V_27 , args -> V_127 , & args -> V_59 ) ;
}
static void
F_224 ( struct V_1 * V_2 )
{
F_219 ( V_2 ) ;
if ( V_2 -> V_3 . V_43 == NULL )
return;
F_225 ( F_226 ( V_2 -> V_3 . V_43 ) , 0 , ( T_8 ) - 1 ) ;
V_2 -> V_12 . V_65 = V_66 ;
V_2 -> V_12 . V_63 = F_27 ( - V_116 ) ;
}
void F_227 ( struct V_1 * V_2 )
{
struct V_41 * V_42 ;
F_55 ( & V_2 -> V_12 . V_254 ) ;
F_45 ( V_2 -> V_12 . V_63 ) ;
switch ( V_2 -> V_12 . V_65 ) {
case V_67 :
F_224 ( V_2 ) ;
case V_66 :
return;
}
if ( V_2 -> V_3 . V_43 == NULL )
return;
V_42 = V_2 -> V_3 . V_43 -> V_44 ,
F_228 ( V_42 , 0 , ( T_8 ) - 1 ) ;
}
static void
F_229 ( struct V_1 * V_2 ,
struct V_40 * V_63 )
{
struct V_255 V_255 ;
struct V_54 * V_54 ;
F_44 ( V_2 , V_63 , true ) ;
F_230 ( V_2 , V_63 ) ;
if ( F_26 ( V_2 ) )
F_231 ( V_2 , V_63 ) ;
F_232 (page, sgt_iter, pages) {
if ( V_2 -> V_12 . V_68 )
F_48 ( V_54 ) ;
if ( V_2 -> V_12 . V_65 == V_71 )
F_49 ( V_54 ) ;
F_36 ( V_54 ) ;
}
V_2 -> V_12 . V_68 = false ;
F_50 ( V_63 ) ;
F_40 ( V_63 ) ;
}
static void F_233 ( struct V_1 * V_2 )
{
struct V_256 V_257 ;
void * * V_258 ;
F_234 (slot, &obj->mm.get_page.radix, &iter, 0 )
F_235 ( & V_2 -> V_12 . V_259 . V_260 , V_257 . V_261 ) ;
}
void F_94 ( struct V_1 * V_2 ,
enum V_262 V_263 )
{
struct V_40 * V_63 ;
if ( F_236 ( V_2 ) )
return;
F_45 ( V_2 -> V_194 ) ;
if ( ! F_237 ( V_2 -> V_12 . V_63 ) )
return;
F_238 ( & V_2 -> V_12 . V_254 , V_263 ) ;
if ( F_128 ( F_239 ( & V_2 -> V_12 . V_264 ) ) )
goto V_265;
V_63 = F_240 ( & V_2 -> V_12 . V_63 ) ;
F_45 ( ! V_63 ) ;
if ( V_2 -> V_12 . V_42 ) {
void * V_266 ;
V_266 = F_241 ( V_2 -> V_12 . V_42 ) ;
if ( F_242 ( V_266 ) )
F_243 ( V_266 ) ;
else
F_133 ( F_244 ( V_266 ) ) ;
V_2 -> V_12 . V_42 = NULL ;
}
F_233 ( V_2 ) ;
if ( ! F_31 ( V_63 ) )
V_2 -> V_114 -> V_267 ( V_2 , V_63 ) ;
V_265:
F_23 ( & V_2 -> V_12 . V_254 ) ;
}
static bool F_245 ( struct V_40 * V_268 )
{
struct V_40 V_269 ;
struct V_47 * V_48 , * V_270 ;
unsigned int V_50 ;
if ( V_268 -> V_271 == V_268 -> V_272 )
return false ;
if ( F_39 ( & V_269 , V_268 -> V_271 , V_57 | V_273 ) )
return false ;
V_270 = V_269 . V_58 ;
F_246 (orig_st->sgl, sg, orig_st->nents, i) {
F_247 ( V_270 , F_248 ( V_48 ) , V_48 -> V_60 , 0 ) ;
V_270 = F_249 ( V_270 ) ;
}
F_45 ( V_270 ) ;
F_50 ( V_268 ) ;
* V_268 = V_269 ;
return true ;
}
static struct V_40 *
F_250 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_17 ( V_2 -> V_3 . V_27 ) ;
const unsigned long V_274 = V_2 -> V_3 . V_11 / V_53 ;
unsigned long V_50 ;
struct V_41 * V_42 ;
struct V_40 * V_46 ;
struct V_47 * V_48 ;
struct V_255 V_255 ;
struct V_54 * V_54 ;
unsigned long V_275 = 0 ;
unsigned int V_276 ;
T_10 V_277 ;
int V_22 ;
F_45 ( V_2 -> V_3 . V_69 & V_199 ) ;
F_45 ( V_2 -> V_3 . V_4 & V_199 ) ;
V_276 = F_251 () ;
if ( ! V_276 )
V_276 = F_194 ( V_278 , V_53 ) ;
V_46 = F_38 ( sizeof( * V_46 ) , V_57 ) ;
if ( V_46 == NULL )
return F_27 ( - V_52 ) ;
V_279:
if ( F_39 ( V_46 , V_274 , V_57 ) ) {
F_40 ( V_46 ) ;
return F_27 ( - V_52 ) ;
}
V_42 = V_2 -> V_3 . V_43 -> V_44 ;
V_277 = F_252 ( V_42 ,
~ ( V_280 | V_281 ) ) ;
V_277 |= V_282 | V_273 ;
V_48 = V_46 -> V_58 ;
V_46 -> V_271 = 0 ;
for ( V_50 = 0 ; V_50 < V_274 ; V_50 ++ ) {
const unsigned int V_283 [] = {
V_284 | V_285 | V_286 ,
0 ,
} , * V_287 = V_283 ;
T_10 V_288 = V_277 ;
do {
V_54 = F_253 ( V_42 , V_50 , V_288 ) ;
if ( F_215 ( ! F_31 ( V_54 ) ) )
break;
if ( ! * V_287 ) {
V_22 = F_108 ( V_54 ) ;
goto V_289;
}
F_254 ( V_17 , 2 * V_274 , * V_287 ++ ) ;
F_255 () ;
if ( ! * V_287 ) {
V_288 = F_256 ( V_42 ) ;
}
} while ( 1 );
if ( ! V_50 ||
V_48 -> V_60 >= V_276 ||
F_257 ( V_54 ) != V_275 + 1 ) {
if ( V_50 )
V_48 = F_249 ( V_48 ) ;
V_46 -> V_271 ++ ;
F_247 ( V_48 , V_54 , V_53 , 0 ) ;
} else {
V_48 -> V_60 += V_53 ;
}
V_275 = F_257 ( V_54 ) ;
F_25 ( ( V_288 & V_290 ) && ( V_275 >= 0x00100000UL ) ) ;
}
if ( V_48 )
F_258 ( V_48 ) ;
F_245 ( V_46 ) ;
V_22 = F_259 ( V_2 , V_46 ) ;
if ( V_22 ) {
if ( V_276 > V_53 ) {
F_232 (page, sgt_iter, st)
F_36 ( V_54 ) ;
F_50 ( V_46 ) ;
V_276 = V_53 ;
goto V_279;
} else {
F_260 ( & V_17 -> V_159 . V_291 -> V_27 ,
L_3 ,
V_274 ) ;
goto V_292;
}
}
if ( F_26 ( V_2 ) )
F_261 ( V_2 , V_46 ) ;
return V_46 ;
V_289:
F_258 ( V_48 ) ;
V_292:
F_232 (page, sgt_iter, st)
F_36 ( V_54 ) ;
F_50 ( V_46 ) ;
F_40 ( V_46 ) ;
if ( V_22 == - V_184 )
V_22 = - V_52 ;
return F_27 ( V_22 ) ;
}
void F_262 ( struct V_1 * V_2 ,
struct V_40 * V_63 )
{
F_55 ( & V_2 -> V_12 . V_254 ) ;
V_2 -> V_12 . V_259 . V_293 = V_63 -> V_58 ;
V_2 -> V_12 . V_259 . V_294 = 0 ;
V_2 -> V_12 . V_63 = V_63 ;
if ( F_193 ( V_2 ) &&
F_17 ( V_2 -> V_3 . V_27 ) -> V_295 & V_296 ) {
F_45 ( V_2 -> V_12 . V_297 ) ;
F_263 ( V_2 ) ;
V_2 -> V_12 . V_297 = true ;
}
}
static int F_264 ( struct V_1 * V_2 )
{
struct V_40 * V_63 ;
F_45 ( F_236 ( V_2 ) ) ;
if ( F_128 ( V_2 -> V_12 . V_65 != V_71 ) ) {
F_265 ( L_4 ) ;
return - V_116 ;
}
V_63 = V_2 -> V_114 -> V_298 ( V_2 ) ;
if ( F_128 ( F_31 ( V_63 ) ) )
return F_108 ( V_63 ) ;
F_262 ( V_2 , V_63 ) ;
return 0 ;
}
int F_266 ( struct V_1 * V_2 )
{
int V_182 ;
V_182 = F_18 ( & V_2 -> V_12 . V_254 ) ;
if ( V_182 )
return V_182 ;
if ( F_128 ( F_267 ( V_2 -> V_12 . V_63 ) ) ) {
V_182 = F_264 ( V_2 ) ;
if ( V_182 )
goto V_265;
F_268 () ;
}
F_269 ( & V_2 -> V_12 . V_264 ) ;
V_265:
F_23 ( & V_2 -> V_12 . V_254 ) ;
return V_182 ;
}
static void * F_270 ( const struct V_1 * V_2 ,
enum V_299 type )
{
unsigned long V_300 = V_2 -> V_3 . V_11 >> V_155 ;
struct V_40 * V_301 = V_2 -> V_12 . V_63 ;
struct V_255 V_255 ;
struct V_54 * V_54 ;
struct V_54 * V_302 [ 32 ] ;
struct V_54 * * V_63 = V_302 ;
unsigned long V_50 = 0 ;
T_11 V_303 ;
void * V_146 ;
if ( V_300 == 1 && type == V_304 )
return F_132 ( F_248 ( V_301 -> V_58 ) ) ;
if ( V_300 > F_271 ( V_302 ) ) {
V_63 = F_272 ( V_300 , sizeof( * V_63 ) , V_305 ) ;
if ( ! V_63 )
return NULL ;
}
F_232 (page, sgt_iter, sgt)
V_63 [ V_50 ++ ] = V_54 ;
F_45 ( V_50 != V_300 ) ;
switch ( type ) {
case V_304 :
V_303 = V_306 ;
break;
case V_307 :
V_303 = F_185 ( V_308 ) ;
break;
}
V_146 = F_273 ( V_63 , V_300 , 0 , V_303 ) ;
if ( V_63 != V_302 )
F_274 ( V_63 ) ;
return V_146 ;
}
void * F_275 ( struct V_1 * V_2 ,
enum V_299 type )
{
enum V_299 V_309 ;
bool V_36 ;
void * V_266 ;
int V_22 ;
F_45 ( ! F_122 ( V_2 ) ) ;
V_22 = F_18 ( & V_2 -> V_12 . V_254 ) ;
if ( V_22 )
return F_27 ( V_22 ) ;
V_36 = true ;
if ( ! F_276 ( & V_2 -> V_12 . V_264 ) ) {
if ( F_128 ( F_267 ( V_2 -> V_12 . V_63 ) ) ) {
V_22 = F_264 ( V_2 ) ;
if ( V_22 )
goto V_231;
F_268 () ;
}
F_269 ( & V_2 -> V_12 . V_264 ) ;
V_36 = false ;
}
F_45 ( ! V_2 -> V_12 . V_63 ) ;
V_266 = F_277 ( V_2 -> V_12 . V_42 , V_309 ) ;
if ( V_266 && V_309 != type ) {
if ( V_36 ) {
V_22 = - V_118 ;
goto V_143;
}
if ( F_242 ( V_266 ) )
F_243 ( V_266 ) ;
else
F_133 ( F_244 ( V_266 ) ) ;
V_266 = V_2 -> V_12 . V_42 = NULL ;
}
if ( ! V_266 ) {
V_266 = F_270 ( V_2 , type ) ;
if ( ! V_266 ) {
V_22 = - V_52 ;
goto V_143;
}
V_2 -> V_12 . V_42 = F_278 ( V_266 , type ) ;
}
V_163:
F_23 ( & V_2 -> V_12 . V_254 ) ;
return V_266 ;
V_143:
F_279 ( & V_2 -> V_12 . V_264 ) ;
V_231:
V_266 = F_27 ( V_22 ) ;
goto V_163;
}
static int
F_280 ( struct V_1 * V_2 ,
const struct V_121 * V_310 )
{
struct V_41 * V_42 = V_2 -> V_3 . V_43 -> V_44 ;
char T_5 * V_122 = F_97 ( V_310 -> V_123 ) ;
T_2 V_152 , V_59 ;
unsigned int V_311 ;
if ( F_237 ( V_2 -> V_12 . V_63 ) )
return - V_141 ;
V_152 = V_310 -> V_11 ;
V_59 = V_310 -> V_59 ;
V_311 = F_138 ( V_59 ) ;
do {
unsigned int V_177 , V_157 ;
struct V_54 * V_54 ;
void * V_30 , * V_49 ;
int V_182 ;
V_177 = V_53 - V_311 ;
if ( V_177 > V_152 )
V_177 = V_152 ;
V_182 = F_281 ( V_2 -> V_3 . V_43 , V_42 ,
V_59 , V_177 , 0 ,
& V_54 , & V_30 ) ;
if ( V_182 < 0 )
return V_182 ;
V_49 = F_132 ( V_54 ) ;
V_157 = F_99 ( V_49 + V_311 , V_122 , V_177 ) ;
F_133 ( V_54 ) ;
V_182 = F_282 ( V_2 -> V_3 . V_43 , V_42 ,
V_59 , V_177 , V_177 - V_157 ,
V_54 , V_30 ) ;
if ( V_182 < 0 )
return V_182 ;
if ( V_157 )
return - V_116 ;
V_152 -= V_177 ;
V_122 += V_177 ;
V_59 += V_177 ;
V_311 = 0 ;
} while ( V_152 );
return 0 ;
}
static bool F_283 ( const struct V_312 * V_313 )
{
return ( F_284 ( V_313 ) &&
V_313 -> V_314 >= V_315 ) ;
}
static void F_285 ( struct V_312 * V_313 )
{
V_313 -> V_316 ++ ;
V_313 -> V_314 += V_317 ;
if ( F_283 ( V_313 ) )
F_286 ( V_313 ) ;
F_287 ( L_5 ,
V_313 -> V_318 , V_313 -> V_314 ,
F_288 ( F_289 ( V_313 ) ) ) ;
if ( ! F_289 ( V_313 ) || F_267 ( V_313 -> V_319 ) )
return;
V_313 -> V_319 -> V_320 ++ ;
F_287 ( L_6 ,
V_313 -> V_318 , V_313 -> V_319 -> V_320 ) ;
}
static void F_290 ( struct V_312 * V_313 )
{
V_313 -> V_321 ++ ;
}
struct V_85 *
F_291 ( struct V_102 * V_91 )
{
struct V_85 * V_322 , * V_323 = NULL ;
unsigned long V_81 ;
F_292 ( & V_91 -> V_324 -> V_254 , V_81 ) ;
F_21 (request, &engine->timeline->requests, link) {
if ( F_293 ( V_322 ,
V_322 -> V_325 ) )
continue;
F_45 ( V_322 -> V_91 != V_91 ) ;
F_45 ( F_64 ( V_87 ,
& V_322 -> V_80 . V_81 ) ) ;
V_323 = V_322 ;
break;
}
F_294 ( & V_91 -> V_324 -> V_254 , V_81 ) ;
return V_323 ;
}
static bool F_295 ( struct V_102 * V_91 )
{
if ( ! V_91 -> V_326 . V_327 )
return false ;
if ( V_91 -> V_326 . V_328 != F_296 ( V_91 ) ) {
F_287 ( L_7 , V_91 -> V_318 ) ;
return false ;
}
return true ;
}
int F_297 ( struct V_16 * V_17 )
{
struct V_102 * V_91 ;
enum V_329 V_330 ;
int V_182 = 0 ;
F_298 (engine, dev_priv, id) {
struct V_85 * V_322 ;
F_299 ( V_91 -> V_331 . V_332 ) ;
F_300 ( & V_91 -> V_333 ) ;
F_301 ( & V_91 -> V_333 ) ;
if ( V_91 -> V_334 )
V_91 -> V_334 ( V_91 ) ;
if ( F_295 ( V_91 ) ) {
V_322 = F_291 ( V_91 ) ;
if ( V_322 && V_322 -> V_80 . error == - V_25 )
V_182 = - V_25 ;
}
}
F_302 ( V_17 ) ;
return V_182 ;
}
static void F_303 ( struct V_85 * V_322 )
{
void * V_49 = V_322 -> V_335 -> V_49 ;
T_1 V_336 ;
V_336 = V_322 -> V_336 ;
if ( V_322 -> V_337 < V_336 ) {
memset ( V_49 + V_336 , 0 , V_322 -> V_335 -> V_11 - V_336 ) ;
V_336 = 0 ;
}
memset ( V_49 + V_336 , 0 , V_322 -> V_337 - V_336 ) ;
F_304 ( & V_322 -> V_80 , - V_25 ) ;
}
static void F_305 ( struct V_85 * V_322 )
{
struct V_102 * V_91 = V_322 -> V_91 ;
struct V_312 * V_338 = V_322 -> V_313 ;
struct V_339 * V_324 ;
unsigned long V_81 ;
V_324 = F_306 ( V_338 , V_91 ) ;
F_292 ( & V_91 -> V_324 -> V_254 , V_81 ) ;
F_8 ( & V_324 -> V_254 ) ;
F_307 (request, &engine->timeline->requests, link)
if ( V_322 -> V_313 == V_338 )
F_303 ( V_322 ) ;
F_21 (request, &timeline->requests, link)
F_303 ( V_322 ) ;
F_9 ( & V_324 -> V_254 ) ;
F_294 ( & V_91 -> V_324 -> V_254 , V_81 ) ;
}
static bool F_308 ( struct V_85 * V_322 )
{
const bool V_340 = F_295 ( V_322 -> V_91 ) ;
if ( V_340 ) {
F_285 ( V_322 -> V_313 ) ;
F_303 ( V_322 ) ;
} else {
F_290 ( V_322 -> V_313 ) ;
F_304 ( & V_322 -> V_80 , - V_239 ) ;
}
return V_340 ;
}
static void F_309 ( struct V_102 * V_91 )
{
struct V_85 * V_322 ;
V_322 = F_291 ( V_91 ) ;
if ( V_322 && F_308 ( V_322 ) ) {
F_287 ( L_8 ,
V_91 -> V_318 , V_322 -> V_325 ) ;
if ( F_289 ( V_322 -> V_313 ) )
F_305 ( V_322 ) ;
}
V_91 -> V_341 ( V_91 , V_322 ) ;
}
void F_310 ( struct V_16 * V_17 )
{
struct V_102 * V_91 ;
enum V_329 V_330 ;
F_55 ( & V_17 -> V_159 . V_29 ) ;
F_57 ( V_17 ) ;
F_298 (engine, dev_priv, id) {
struct V_312 * V_313 ;
F_309 ( V_91 ) ;
V_313 = F_240 ( & V_91 -> V_342 ) ;
if ( V_313 )
V_91 -> V_343 ( V_91 , V_313 ) ;
}
F_311 ( V_17 ) ;
if ( V_17 -> V_251 . V_344 ) {
F_312 ( V_17 ) ;
F_313 ( V_17 ) ;
if ( F_69 ( V_17 ) >= 6 )
F_314 ( V_17 ) ;
}
}
void F_315 ( struct V_16 * V_17 )
{
struct V_102 * V_91 ;
enum V_329 V_330 ;
F_55 ( & V_17 -> V_159 . V_29 ) ;
F_298 (engine, dev_priv, id) {
F_316 ( & V_91 -> V_333 ) ;
F_317 ( V_91 -> V_331 . V_332 ) ;
}
}
static void F_318 ( struct V_85 * V_322 )
{
F_304 ( & V_322 -> V_80 , - V_25 ) ;
F_319 ( V_322 ) ;
F_320 ( V_322 -> V_91 , V_322 -> V_325 ) ;
}
static void F_321 ( struct V_102 * V_91 )
{
struct V_85 * V_322 ;
unsigned long V_81 ;
V_91 -> V_345 = F_318 ;
F_292 ( & V_91 -> V_324 -> V_254 , V_81 ) ;
F_21 (request, &engine->timeline->requests, link)
F_304 ( & V_322 -> V_80 , - V_25 ) ;
F_294 ( & V_91 -> V_324 -> V_254 , V_81 ) ;
F_320 ( V_91 ,
F_74 ( V_91 ) ) ;
if ( V_89 . V_346 ) {
unsigned long V_81 ;
F_292 ( & V_91 -> V_324 -> V_254 , V_81 ) ;
F_322 ( V_91 -> V_347 [ 0 ] . V_322 ) ;
F_322 ( V_91 -> V_347 [ 1 ] . V_322 ) ;
memset ( V_91 -> V_347 , 0 , sizeof( V_91 -> V_347 ) ) ;
V_91 -> V_348 = V_349 ;
V_91 -> V_350 = NULL ;
F_294 ( & V_91 -> V_324 -> V_254 , V_81 ) ;
}
}
static int F_323 ( void * V_30 )
{
struct V_16 * V_89 = V_30 ;
struct V_102 * V_91 ;
enum V_329 V_330 ;
F_298 (engine, i915, id)
F_321 ( V_91 ) ;
return 0 ;
}
void F_324 ( struct V_16 * V_17 )
{
F_55 ( & V_17 -> V_159 . V_29 ) ;
F_325 ( V_351 , & V_17 -> V_28 . V_81 ) ;
F_57 ( V_17 ) ;
F_326 ( F_323 , V_17 , NULL ) ;
F_327 ( V_17 ) ;
F_328 ( V_17 -> V_352 , & V_17 -> V_251 . V_353 , 0 ) ;
}
bool F_329 ( struct V_16 * V_89 )
{
struct V_354 * V_355 ;
int V_50 ;
F_55 ( & V_89 -> V_159 . V_29 ) ;
if ( ! F_64 ( V_351 , & V_89 -> V_28 . V_81 ) )
return true ;
F_21 (tl, &i915->gt.timelines, link) {
for ( V_50 = 0 ; V_50 < F_271 ( V_355 -> V_91 ) ; V_50 ++ ) {
struct V_85 * V_86 ;
V_86 = F_330 ( & V_355 -> V_91 [ V_50 ] . V_356 ,
& V_89 -> V_159 . V_29 ) ;
if ( ! V_86 )
continue;
if ( F_331 ( & V_86 -> V_80 , true ,
V_76 ) < 0 )
return false ;
}
}
F_332 ( V_89 ) ;
F_268 () ;
F_333 ( V_351 , & V_89 -> V_28 . V_81 ) ;
return true ;
}
static void
F_334 ( struct V_357 * V_358 )
{
struct V_16 * V_17 =
F_335 ( V_358 , F_336 ( * V_17 ) , V_251 . V_252 . V_358 ) ;
struct V_26 * V_27 = & V_17 -> V_159 ;
if ( F_337 ( & V_27 -> V_29 ) ) {
F_57 ( V_17 ) ;
F_23 ( & V_27 -> V_29 ) ;
}
if ( F_237 ( V_17 -> V_251 . V_344 ) ) {
F_338 ( V_17 ) ;
F_339 ( V_17 -> V_352 ,
& V_17 -> V_251 . V_252 ,
F_340 ( V_359 ) ) ;
}
}
static void
F_341 ( struct V_357 * V_358 )
{
struct V_16 * V_17 =
F_335 ( V_358 , F_336 ( * V_17 ) , V_251 . V_353 . V_358 ) ;
struct V_26 * V_27 = & V_17 -> V_159 ;
struct V_102 * V_91 ;
enum V_329 V_330 ;
bool V_360 ;
if ( ! F_237 ( V_17 -> V_251 . V_344 ) )
return;
F_342 ( F_343 ( V_17 ) , 10 ) ;
if ( F_237 ( V_17 -> V_251 . V_361 ) )
return;
V_360 =
F_344 ( & V_17 -> V_28 . V_362 ) ;
if ( ! F_337 ( & V_27 -> V_29 ) ) {
F_328 ( V_17 -> V_352 ,
& V_17 -> V_251 . V_353 ,
F_345 ( 50 ) ) ;
goto V_363;
}
if ( F_346 ( V_358 ) )
goto V_163;
if ( V_17 -> V_251 . V_361 )
goto V_163;
if ( F_342 ( F_343 ( V_17 ) , 10 ) )
F_15 ( L_9 ) ;
F_298 (engine, dev_priv, id) {
F_347 ( V_91 ) ;
F_348 ( & V_91 -> V_364 ) ;
}
F_45 ( ! V_17 -> V_251 . V_344 ) ;
V_17 -> V_251 . V_344 = false ;
V_360 = false ;
if ( F_69 ( V_17 ) >= 6 )
F_349 ( V_17 ) ;
F_157 ( V_17 ) ;
V_163:
F_23 ( & V_27 -> V_29 ) ;
V_363:
if ( V_360 ) {
F_45 ( ! V_17 -> V_251 . V_344 ) ;
F_338 ( V_17 ) ;
}
}
void F_350 ( struct V_365 * V_366 , struct V_31 * V_32 )
{
struct V_1 * V_2 = F_198 ( V_366 ) ;
struct V_110 * V_111 = V_32 -> V_112 ;
struct V_34 * V_35 , * V_367 ;
F_20 ( & V_2 -> V_3 . V_27 -> V_29 ) ;
F_212 (vma, vn, &obj->vma_list, obj_link)
if ( V_35 -> V_192 -> V_32 == V_111 )
F_351 ( V_35 ) ;
if ( F_352 ( V_2 ) &&
! F_353 ( V_2 ) ) {
F_354 ( V_2 ) ;
F_355 ( V_2 ) ;
}
F_23 ( & V_2 -> V_3 . V_27 -> V_29 ) ;
}
static unsigned long F_356 ( T_12 V_368 )
{
if ( V_368 < 0 )
return V_76 ;
if ( V_368 == 0 )
return 0 ;
return F_357 ( V_368 ) ;
}
int
F_358 ( struct V_26 * V_27 , void * V_30 , struct V_31 * V_32 )
{
struct V_369 * args = V_30 ;
struct V_1 * V_2 ;
T_13 V_148 ;
long V_22 ;
if ( args -> V_81 != 0 )
return - V_51 ;
V_2 = F_160 ( V_32 , args -> V_370 ) ;
if ( ! V_2 )
return - V_174 ;
V_148 = F_359 () ;
V_22 = F_56 ( V_2 ,
V_73 | V_75 ,
F_356 ( args -> V_368 ) ,
F_92 ( V_32 ) ) ;
if ( args -> V_368 > 0 ) {
args -> V_368 -= F_360 ( F_361 ( F_359 () , V_148 ) ) ;
if ( args -> V_368 < 0 )
args -> V_368 = 0 ;
if ( V_22 == - V_371 && ! F_362 ( args -> V_368 ) )
args -> V_368 = 0 ;
}
F_110 ( V_2 ) ;
return V_22 ;
}
static int F_363 ( struct V_354 * V_355 , unsigned int V_81 )
{
int V_22 , V_50 ;
for ( V_50 = 0 ; V_50 < F_271 ( V_355 -> V_91 ) ; V_50 ++ ) {
V_22 = F_364 ( & V_355 -> V_91 [ V_50 ] . V_356 , V_81 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static int F_365 ( struct V_102 * V_91 , int V_372 )
{
return F_342 ( F_366 ( V_91 ) , V_372 ) ;
}
static int F_367 ( struct V_16 * V_89 )
{
struct V_102 * V_91 ;
enum V_329 V_330 ;
F_298 (engine, i915, id) {
if ( F_368 ( F_365 ( V_91 , 50 ) ) ) {
F_324 ( V_89 ) ;
return - V_25 ;
}
F_45 ( F_296 ( V_91 ) !=
F_74 ( V_91 ) ) ;
}
return 0 ;
}
int F_216 ( struct V_16 * V_89 , unsigned int V_81 )
{
int V_22 ;
if ( ! F_237 ( V_89 -> V_251 . V_344 ) )
return 0 ;
if ( V_81 & V_74 ) {
struct V_354 * V_355 ;
F_55 ( & V_89 -> V_159 . V_29 ) ;
F_21 (tl, &i915->gt.timelines, link) {
V_22 = F_363 ( V_355 , V_81 ) ;
if ( V_22 )
return V_22 ;
}
F_57 ( V_89 ) ;
F_45 ( V_89 -> V_251 . V_361 ) ;
V_22 = F_367 ( V_89 ) ;
} else {
V_22 = F_363 ( & V_89 -> V_251 . V_373 , V_81 ) ;
}
return V_22 ;
}
static void
F_125 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_17 ( V_2 -> V_3 . V_27 ) ;
if ( V_2 -> V_3 . V_4 != V_187 )
return;
F_155 () ;
if ( F_69 ( V_17 ) >= 6 && ! F_200 ( V_17 ) ) {
if ( F_369 ( V_17 ) ) {
F_370 ( & V_17 -> V_374 . V_254 ) ;
F_371 ( F_372 ( V_17 -> V_91 [ V_375 ] -> V_376 ) ) ;
F_373 ( & V_17 -> V_374 . V_254 ) ;
F_157 ( V_17 ) ;
}
}
F_100 ( V_2 , F_172 ( V_2 , V_187 ) ) ;
V_2 -> V_3 . V_4 = 0 ;
}
static void
F_374 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 != V_5 )
return;
F_375 ( V_2 , V_377 ) ;
V_2 -> V_3 . V_4 = 0 ;
}
static void F_376 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 != V_5 && ! V_2 -> V_378 )
return;
F_375 ( V_2 , V_379 ) ;
V_2 -> V_3 . V_4 = 0 ;
}
void F_179 ( struct V_1 * V_2 )
{
if ( ! F_237 ( V_2 -> V_6 ) )
return;
F_20 ( & V_2 -> V_3 . V_27 -> V_29 ) ;
F_376 ( V_2 ) ;
F_23 ( & V_2 -> V_3 . V_27 -> V_29 ) ;
}
int
F_154 ( struct V_1 * V_2 , bool V_225 )
{
int V_22 ;
F_55 ( & V_2 -> V_3 . V_27 -> V_29 ) ;
V_22 = F_56 ( V_2 ,
V_73 |
V_74 |
( V_225 ? V_75 : 0 ) ,
V_76 ,
NULL ) ;
if ( V_22 )
return V_22 ;
if ( V_2 -> V_3 . V_4 == V_187 )
return 0 ;
V_22 = F_95 ( V_2 ) ;
if ( V_22 )
return V_22 ;
F_374 ( V_2 ) ;
if ( ( V_2 -> V_3 . V_69 & V_187 ) == 0 )
F_377 () ;
F_45 ( ( V_2 -> V_3 . V_4 & ~ V_187 ) != 0 ) ;
V_2 -> V_3 . V_69 |= V_187 ;
if ( V_225 ) {
V_2 -> V_3 . V_69 = V_187 ;
V_2 -> V_3 . V_4 = V_187 ;
V_2 -> V_12 . V_68 = true ;
}
F_52 ( V_2 ) ;
return 0 ;
}
int F_378 ( struct V_1 * V_2 ,
enum V_380 V_230 )
{
struct V_34 * V_35 ;
int V_22 ;
F_55 ( & V_2 -> V_3 . V_27 -> V_29 ) ;
if ( V_2 -> V_230 == V_230 )
return 0 ;
V_381:
F_21 (vma, &obj->vma_list, obj_link) {
if ( ! F_176 ( & V_35 -> V_10 ) )
continue;
if ( F_22 ( V_35 ) ) {
F_265 ( L_10 ) ;
return - V_118 ;
}
if ( F_379 ( V_35 , V_230 ) )
continue;
V_22 = F_60 ( V_35 ) ;
if ( V_22 )
return V_22 ;
goto V_381;
}
if ( V_2 -> V_194 ) {
V_22 = F_56 ( V_2 ,
V_73 |
V_74 |
V_75 ,
V_76 ,
NULL ) ;
if ( V_22 )
return V_22 ;
if ( ! F_200 ( F_17 ( V_2 -> V_3 . V_27 ) ) &&
V_230 != V_169 ) {
F_209 ( V_2 ) ;
F_21 (vma, &obj->vma_list, obj_link) {
V_22 = F_152 ( V_35 ) ;
if ( V_22 )
return V_22 ;
}
} else {
}
F_21 (vma, &obj->vma_list, obj_link) {
if ( ! F_176 ( & V_35 -> V_10 ) )
continue;
V_22 = F_380 ( V_35 , V_230 , V_382 ) ;
if ( V_22 )
return V_22 ;
}
}
if ( V_2 -> V_3 . V_4 == V_5 &&
F_2 ( V_2 ) )
V_2 -> V_378 = true ;
F_21 (vma, &obj->vma_list, obj_link)
V_35 -> V_10 . V_383 = V_230 ;
V_2 -> V_230 = V_230 ;
return 0 ;
}
int F_381 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_384 * args = V_30 ;
struct V_1 * V_2 ;
int V_182 = 0 ;
F_382 () ;
V_2 = F_383 ( V_32 , args -> V_127 ) ;
if ( ! V_2 ) {
V_182 = - V_174 ;
goto V_88;
}
switch ( V_2 -> V_230 ) {
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
V_88:
F_384 () ;
return V_182 ;
}
int F_385 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_16 * V_89 = F_17 ( V_27 ) ;
struct V_384 * args = V_30 ;
struct V_1 * V_2 ;
enum V_380 V_392 ;
int V_22 = 0 ;
switch ( args -> V_387 ) {
case V_391 :
V_392 = V_169 ;
break;
case V_388 :
if ( ! F_200 ( V_89 ) && ! F_386 ( V_89 ) )
return - V_141 ;
V_392 = V_385 ;
break;
case V_390 :
V_392 = F_387 ( V_89 ) ? V_389 : V_169 ;
break;
default:
return - V_51 ;
}
V_2 = F_160 ( V_32 , args -> V_127 ) ;
if ( ! V_2 )
return - V_174 ;
if ( V_2 -> V_230 == V_392 )
goto V_88;
V_22 = F_56 ( V_2 ,
V_73 ,
V_76 ,
F_92 ( V_32 ) ) ;
if ( V_22 )
goto V_88;
V_22 = F_16 ( V_27 ) ;
if ( V_22 )
goto V_88;
V_22 = F_378 ( V_2 , V_392 ) ;
F_23 ( & V_27 -> V_29 ) ;
V_88:
F_110 ( V_2 ) ;
return V_22 ;
}
struct V_34 *
F_388 ( struct V_1 * V_2 ,
T_1 V_393 ,
const struct V_215 * V_217 )
{
struct V_34 * V_35 ;
int V_22 ;
F_55 ( & V_2 -> V_3 . V_27 -> V_29 ) ;
V_2 -> V_6 ++ ;
V_22 = F_378 ( V_2 ,
F_387 ( F_17 ( V_2 -> V_3 . V_27 ) ) ?
V_389 : V_169 ) ;
if ( V_22 ) {
V_35 = F_27 ( V_22 ) ;
goto V_394;
}
V_35 = F_27 ( - V_184 ) ;
if ( ! V_217 || V_217 -> type == V_220 )
V_35 = F_150 ( V_2 , V_217 , 0 , V_393 ,
V_160 | V_161 ) ;
if ( F_31 ( V_35 ) ) {
struct V_16 * V_89 = F_17 ( V_2 -> V_3 . V_27 ) ;
unsigned int V_81 ;
V_81 = 0 ;
if ( F_389 ( V_89 ) )
V_81 = V_160 ;
V_35 = F_150 ( V_2 , V_217 , 0 , V_393 , V_81 ) ;
}
if ( F_31 ( V_35 ) )
goto V_394;
V_35 -> V_395 = F_390 ( T_2 , V_35 -> V_395 , V_393 ) ;
F_376 ( V_2 ) ;
F_100 ( V_2 , V_396 ) ;
V_2 -> V_3 . V_69 |= V_187 ;
return V_35 ;
V_394:
V_2 -> V_6 -- ;
return V_35 ;
}
void
F_391 ( struct V_34 * V_35 )
{
F_55 ( & V_35 -> V_192 -> V_89 -> V_159 . V_29 ) ;
if ( F_25 ( V_35 -> V_2 -> V_6 == 0 ) )
return;
if ( -- V_35 -> V_2 -> V_6 == 0 )
V_35 -> V_395 = V_397 ;
F_173 ( V_35 -> V_2 ) ;
F_153 ( V_35 ) ;
}
int
F_124 ( struct V_1 * V_2 , bool V_225 )
{
int V_22 ;
F_55 ( & V_2 -> V_3 . V_27 -> V_29 ) ;
V_22 = F_56 ( V_2 ,
V_73 |
V_74 |
( V_225 ? V_75 : 0 ) ,
V_76 ,
NULL ) ;
if ( V_22 )
return V_22 ;
if ( V_2 -> V_3 . V_4 == V_5 )
return 0 ;
F_125 ( V_2 ) ;
if ( ( V_2 -> V_3 . V_69 & V_5 ) == 0 ) {
F_375 ( V_2 , V_377 ) ;
V_2 -> V_3 . V_69 |= V_5 ;
}
F_45 ( ( V_2 -> V_3 . V_4 & ~ V_5 ) != 0 ) ;
if ( V_225 ) {
V_2 -> V_3 . V_69 = V_5 ;
V_2 -> V_3 . V_4 = V_5 ;
}
return 0 ;
}
static int
F_392 ( struct V_26 * V_27 , struct V_31 * V_32 )
{
struct V_16 * V_17 = F_17 ( V_27 ) ;
struct V_110 * V_319 = V_32 -> V_112 ;
unsigned long V_398 = V_399 - V_400 ;
struct V_85 * V_322 , * V_401 = NULL ;
long V_22 ;
if ( F_207 ( & V_17 -> V_28 ) )
return - V_25 ;
F_8 ( & V_319 -> V_12 . V_254 ) ;
F_21 (request, &file_priv->mm.request_list, client_link) {
if ( F_393 ( V_322 -> V_90 , V_398 ) )
break;
if ( V_401 ) {
F_394 ( & V_401 -> V_402 ) ;
V_401 -> V_319 = NULL ;
}
V_401 = V_322 ;
}
if ( V_401 )
F_395 ( V_401 ) ;
F_9 ( & V_319 -> V_12 . V_254 ) ;
if ( V_401 == NULL )
return 0 ;
V_22 = F_71 ( V_401 ,
V_73 ,
V_76 ) ;
F_322 ( V_401 ) ;
return V_22 < 0 ? V_22 : 0 ;
}
struct V_34 *
F_150 ( struct V_1 * V_2 ,
const struct V_215 * V_217 ,
T_2 V_11 ,
T_2 V_393 ,
T_2 V_81 )
{
struct V_16 * V_17 = F_17 ( V_2 -> V_3 . V_27 ) ;
struct V_403 * V_192 = & V_17 -> V_8 . V_3 ;
struct V_34 * V_35 ;
int V_22 ;
F_55 ( & V_2 -> V_3 . V_27 -> V_29 ) ;
V_35 = F_396 ( V_2 , V_192 , V_217 ) ;
if ( F_128 ( F_31 ( V_35 ) ) )
return V_35 ;
if ( F_397 ( V_35 , V_11 , V_393 , V_81 ) ) {
if ( V_81 & V_161 &&
( F_22 ( V_35 ) || F_175 ( V_35 ) ) )
return F_27 ( - V_184 ) ;
if ( V_81 & V_160 ) {
if ( V_35 -> V_404 > V_17 -> V_8 . V_14 )
return F_27 ( - V_405 ) ;
if ( V_81 & V_161 &&
V_35 -> V_404 > V_17 -> V_8 . V_14 / 2 )
return F_27 ( - V_184 ) ;
}
F_398 ( F_22 ( V_35 ) ,
L_11
L_12
L_13 ,
F_151 ( V_35 ) , V_393 ,
! ! ( V_81 & V_160 ) ,
F_399 ( V_35 ) ) ;
V_22 = F_60 ( V_35 ) ;
if ( V_22 )
return F_27 ( V_22 ) ;
}
V_22 = F_400 ( V_35 , V_11 , V_393 , V_81 | V_406 ) ;
if ( V_22 )
return F_27 ( V_22 ) ;
return V_35 ;
}
static T_14 unsigned int F_401 ( unsigned int V_330 )
{
F_63 ( V_407 > 16 ) ;
return 0x10000 << V_330 ;
}
static T_14 unsigned int F_402 ( unsigned int V_330 )
{
return V_330 | F_401 ( V_330 ) ;
}
static T_14 unsigned int
F_403 ( const struct V_79 * V_80 )
{
return F_404 ( V_80 , F_401 ) ;
}
static T_14 unsigned int
F_405 ( const struct V_79 * V_80 )
{
if ( ! V_80 )
return 0 ;
return F_404 ( V_80 , F_402 ) ;
}
int
F_406 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_408 * args = V_30 ;
struct V_1 * V_2 ;
struct V_409 * V_190 ;
unsigned int V_96 ;
int V_182 ;
V_182 = - V_174 ;
F_382 () ;
V_2 = F_383 ( V_32 , args -> V_127 ) ;
if ( ! V_2 )
goto V_88;
V_410:
V_96 = F_407 ( & V_2 -> V_95 -> V_96 ) ;
args -> V_411 = F_405 ( F_408 ( V_2 -> V_95 -> V_412 ) ) ;
V_190 = F_408 ( V_2 -> V_95 -> V_80 ) ;
if ( V_190 ) {
unsigned int V_413 = V_190 -> V_413 , V_50 ;
for ( V_50 = 0 ; V_50 < V_413 ; ++ V_50 ) {
struct V_79 * V_80 =
F_408 ( V_190 -> V_99 [ V_50 ] ) ;
args -> V_411 |= F_403 ( V_80 ) ;
}
}
if ( args -> V_411 && F_409 ( & V_2 -> V_95 -> V_96 , V_96 ) )
goto V_410;
V_182 = 0 ;
V_88:
F_384 () ;
return V_182 ;
}
int
F_410 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_319 )
{
return F_392 ( V_27 , V_319 ) ;
}
int
F_411 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_319 )
{
struct V_16 * V_17 = F_17 ( V_27 ) ;
struct V_414 * args = V_30 ;
struct V_1 * V_2 ;
int V_182 ;
switch ( args -> V_65 ) {
case V_67 :
case V_71 :
break;
default:
return - V_51 ;
}
V_2 = F_160 ( V_319 , args -> V_127 ) ;
if ( ! V_2 )
return - V_174 ;
V_182 = F_18 ( & V_2 -> V_12 . V_254 ) ;
if ( V_182 )
goto V_88;
if ( V_2 -> V_12 . V_63 &&
F_193 ( V_2 ) &&
V_17 -> V_295 & V_296 ) {
if ( V_2 -> V_12 . V_65 == V_71 ) {
F_45 ( ! V_2 -> V_12 . V_297 ) ;
F_412 ( V_2 ) ;
V_2 -> V_12 . V_297 = false ;
}
if ( args -> V_65 == V_71 ) {
F_45 ( V_2 -> V_12 . V_297 ) ;
F_263 ( V_2 ) ;
V_2 -> V_12 . V_297 = true ;
}
}
if ( V_2 -> V_12 . V_65 != V_66 )
V_2 -> V_12 . V_65 = args -> V_65 ;
if ( V_2 -> V_12 . V_65 == V_67 && ! V_2 -> V_12 . V_63 )
F_224 ( V_2 ) ;
args -> V_415 = V_2 -> V_12 . V_65 != V_66 ;
F_23 ( & V_2 -> V_12 . V_254 ) ;
V_88:
F_110 ( V_2 ) ;
return V_182 ;
}
static void
F_413 ( struct V_416 * V_323 ,
struct V_85 * V_322 )
{
struct V_1 * V_2 =
F_335 ( V_323 , F_336 ( * V_2 ) , V_417 ) ;
F_100 ( V_2 , V_418 ) ;
}
void F_414 ( struct V_1 * V_2 ,
const struct V_419 * V_114 )
{
F_415 ( & V_2 -> V_12 . V_254 ) ;
F_416 ( & V_2 -> V_197 ) ;
F_416 ( & V_2 -> V_233 ) ;
F_416 ( & V_2 -> V_420 ) ;
F_416 ( & V_2 -> V_77 ) ;
F_416 ( & V_2 -> V_421 ) ;
V_2 -> V_114 = V_114 ;
F_417 ( & V_2 -> V_422 ) ;
V_2 -> V_95 = & V_2 -> V_422 ;
V_2 -> V_188 = V_423 ;
F_418 ( & V_2 -> V_417 , F_413 ) ;
V_2 -> V_12 . V_65 = V_71 ;
F_419 ( & V_2 -> V_12 . V_259 . V_260 , V_57 | V_273 ) ;
F_415 ( & V_2 -> V_12 . V_259 . V_254 ) ;
F_7 ( F_17 ( V_2 -> V_3 . V_27 ) , V_2 -> V_3 . V_11 ) ;
}
struct V_1 *
F_107 ( struct V_16 * V_17 , T_2 V_11 )
{
struct V_1 * V_2 ;
struct V_41 * V_42 ;
T_10 V_424 ;
int V_22 ;
if ( F_25 ( V_11 >> V_155 > V_425 ) )
return F_27 ( - V_405 ) ;
if ( F_420 ( V_11 , V_2 -> V_3 . V_11 ) )
return F_27 ( - V_405 ) ;
V_2 = F_101 ( V_17 ) ;
if ( V_2 == NULL )
return F_27 ( - V_52 ) ;
V_22 = F_421 ( & V_17 -> V_159 , & V_2 -> V_3 , V_11 ) ;
if ( V_22 )
goto V_426;
V_424 = V_427 | V_428 ;
if ( F_422 ( V_17 ) || F_423 ( V_17 ) ) {
V_424 &= ~ V_429 ;
V_424 |= V_290 ;
}
V_42 = V_2 -> V_3 . V_43 -> V_44 ;
F_424 ( V_42 , V_424 ) ;
F_45 ( ! ( F_256 ( V_42 ) & V_281 ) ) ;
F_414 ( V_2 , & V_119 ) ;
V_2 -> V_3 . V_4 = V_5 ;
V_2 -> V_3 . V_69 = V_5 ;
if ( F_200 ( V_17 ) ) {
V_2 -> V_230 = V_385 ;
} else
V_2 -> V_230 = V_169 ;
F_425 ( V_2 ) ;
return V_2 ;
V_426:
F_103 ( V_2 ) ;
return F_27 ( V_22 ) ;
}
static bool F_426 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_65 != V_71 )
return false ;
if ( V_2 -> V_3 . V_43 == NULL )
return true ;
return F_427 ( & V_2 -> V_3 . V_43 -> V_430 ) == 1 ;
}
static void F_428 ( struct V_16 * V_89 ,
struct V_431 * V_432 )
{
struct V_1 * V_2 , * V_246 ;
F_20 ( & V_89 -> V_159 . V_29 ) ;
F_149 ( V_89 ) ;
F_429 (obj, freed, freed) {
struct V_34 * V_35 , * V_367 ;
F_430 ( V_2 ) ;
F_45 ( F_352 ( V_2 ) ) ;
F_212 (vma, vn,
&obj->vma_list, obj_link) {
F_45 ( ! F_174 ( V_35 ) ) ;
F_45 ( F_175 ( V_35 ) ) ;
V_35 -> V_81 &= ~ V_433 ;
F_351 ( V_35 ) ;
}
F_45 ( ! F_203 ( & V_2 -> V_77 ) ) ;
F_45 ( ! F_431 ( & V_2 -> V_434 ) ) ;
F_394 ( & V_2 -> V_197 ) ;
}
F_157 ( V_89 ) ;
F_23 ( & V_89 -> V_159 . V_29 ) ;
F_432 (obj, on, freed, freed) {
F_45 ( V_2 -> V_194 ) ;
F_45 ( F_239 ( & V_2 -> V_435 ) ) ;
if ( V_2 -> V_114 -> V_436 )
V_2 -> V_114 -> V_436 ( V_2 ) ;
if ( F_25 ( F_236 ( V_2 ) ) )
F_433 ( & V_2 -> V_12 . V_264 , 0 ) ;
F_94 ( V_2 , V_117 ) ;
F_45 ( V_2 -> V_12 . V_63 ) ;
if ( V_2 -> V_3 . V_437 )
F_434 ( & V_2 -> V_3 , NULL ) ;
F_435 ( & V_2 -> V_422 ) ;
F_436 ( & V_2 -> V_3 ) ;
F_10 ( V_89 , V_2 -> V_3 . V_11 ) ;
F_40 ( V_2 -> V_438 ) ;
F_103 ( V_2 ) ;
}
}
static void F_115 ( struct V_16 * V_89 )
{
struct V_431 * V_432 ;
V_432 = F_437 ( & V_89 -> V_12 . V_439 ) ;
if ( F_128 ( V_432 ) )
F_428 ( V_89 , V_432 ) ;
}
static void F_438 ( struct V_357 * V_358 )
{
struct V_16 * V_89 =
F_335 ( V_358 , struct V_16 , V_12 . V_440 ) ;
struct V_431 * V_432 ;
while ( ( V_432 = F_437 ( & V_89 -> V_12 . V_439 ) ) )
F_428 ( V_89 , V_432 ) ;
}
static void F_439 ( struct V_441 * V_336 )
{
struct V_1 * V_2 =
F_335 ( V_336 , F_336 ( * V_2 ) , V_442 ) ;
struct V_16 * V_89 = F_17 ( V_2 -> V_3 . V_27 ) ;
if ( F_440 ( & V_2 -> V_432 , & V_89 -> V_12 . V_439 ) )
F_441 ( & V_89 -> V_12 . V_440 ) ;
}
void F_442 ( struct V_365 * V_443 )
{
struct V_1 * V_2 = F_198 ( V_443 ) ;
if ( V_2 -> V_12 . V_297 )
F_412 ( V_2 ) ;
if ( F_426 ( V_2 ) )
V_2 -> V_12 . V_65 = V_67 ;
F_443 ( & V_2 -> V_442 , F_439 ) ;
}
void F_444 ( struct V_1 * V_2 )
{
F_55 ( & V_2 -> V_3 . V_27 -> V_29 ) ;
F_45 ( F_353 ( V_2 ) ) ;
if ( F_352 ( V_2 ) )
F_354 ( V_2 ) ;
else
F_110 ( V_2 ) ;
}
static void F_445 ( struct V_16 * V_17 )
{
struct V_102 * V_91 ;
enum V_329 V_330 ;
F_298 (engine, dev_priv, id)
F_45 ( V_91 -> V_342 &&
! F_446 ( V_91 -> V_342 ) ) ;
}
void F_447 ( struct V_16 * V_89 )
{
if ( F_448 ( V_89 ) ) {
int V_444 = F_449 ( V_89 , V_445 ) ;
F_25 ( V_444 && V_444 != - V_141 ) ;
}
}
int F_450 ( struct V_16 * V_17 )
{
struct V_26 * V_27 = & V_17 -> V_159 ;
int V_22 ;
F_149 ( V_17 ) ;
F_451 ( V_17 ) ;
F_20 ( & V_27 -> V_29 ) ;
V_22 = F_452 ( V_17 ) ;
if ( V_22 )
goto V_231;
V_22 = F_216 ( V_17 ,
V_73 |
V_74 ) ;
if ( V_22 )
goto V_231;
F_445 ( V_17 ) ;
F_327 ( V_17 ) ;
F_23 ( & V_27 -> V_29 ) ;
F_453 ( V_17 ) ;
F_344 ( & V_17 -> V_28 . V_362 ) ;
F_344 ( & V_17 -> V_251 . V_252 ) ;
while ( F_218 ( & V_17 -> V_251 . V_353 ) )
;
F_217 ( V_17 ) ;
F_25 ( V_17 -> V_251 . V_344 ) ;
F_25 ( ! F_343 ( V_17 ) ) ;
F_447 ( V_17 ) ;
goto V_446;
V_231:
F_23 ( & V_27 -> V_29 ) ;
V_446:
F_157 ( V_17 ) ;
return V_22 ;
}
void F_454 ( struct V_16 * V_17 )
{
struct V_26 * V_27 = & V_17 -> V_159 ;
F_25 ( V_17 -> V_251 . V_344 ) ;
F_20 ( & V_27 -> V_29 ) ;
F_455 ( V_17 ) ;
V_17 -> V_251 . V_447 ( V_17 ) ;
F_23 ( & V_27 -> V_29 ) ;
}
void F_456 ( struct V_16 * V_17 )
{
if ( F_69 ( V_17 ) < 5 ||
V_17 -> V_12 . V_448 == V_449 )
return;
F_457 ( V_450 , F_458 ( V_450 ) |
V_451 ) ;
if ( F_459 ( V_17 ) )
return;
F_457 ( V_452 , F_458 ( V_452 ) | V_453 ) ;
if ( F_460 ( V_17 ) )
F_457 ( V_454 , F_461 ( V_455 ) ) ;
else if ( F_462 ( V_17 ) )
F_457 ( V_454 , F_461 ( V_456 ) ) ;
else if ( F_463 ( V_17 ) )
F_457 ( V_457 , F_461 ( V_458 ) ) ;
else
F_464 () ;
}
static void F_465 ( struct V_16 * V_17 , T_1 V_3 )
{
F_457 ( F_466 ( V_3 ) , 0 ) ;
F_457 ( F_467 ( V_3 ) , 0 ) ;
F_457 ( F_468 ( V_3 ) , 0 ) ;
F_457 ( F_469 ( V_3 ) , 0 ) ;
}
static void F_470 ( struct V_16 * V_17 )
{
if ( F_471 ( V_17 ) ) {
F_465 ( V_17 , V_459 ) ;
F_465 ( V_17 , V_460 ) ;
F_465 ( V_17 , V_461 ) ;
F_465 ( V_17 , V_462 ) ;
F_465 ( V_17 , V_463 ) ;
} else if ( F_472 ( V_17 ) ) {
F_465 ( V_17 , V_460 ) ;
F_465 ( V_17 , V_461 ) ;
} else if ( F_473 ( V_17 ) ) {
F_465 ( V_17 , V_459 ) ;
F_465 ( V_17 , V_464 ) ;
}
}
static int F_474 ( void * V_30 )
{
struct V_16 * V_89 = V_30 ;
struct V_102 * V_91 ;
enum V_329 V_330 ;
int V_182 ;
F_298 (engine, i915, id) {
V_182 = V_91 -> V_465 ( V_91 ) ;
if ( V_182 )
return V_182 ;
}
return 0 ;
}
int F_475 ( struct V_16 * V_17 )
{
int V_22 ;
V_17 -> V_251 . V_466 = F_359 () ;
F_476 ( V_17 , V_467 ) ;
if ( F_477 ( V_17 ) && F_69 ( V_17 ) < 9 )
F_457 ( V_468 , F_458 ( V_468 ) | F_478 ( 0xf ) ) ;
if ( F_479 ( V_17 ) )
F_457 ( V_469 , F_480 ( V_17 ) ?
V_470 : V_471 ) ;
if ( F_481 ( V_17 ) ) {
if ( F_482 ( V_17 ) ) {
T_1 V_472 = F_458 ( V_473 ) ;
V_472 &= ~ ( V_474 | V_475 ) ;
F_457 ( V_473 , V_472 ) ;
} else if ( F_69 ( V_17 ) >= 7 ) {
T_1 V_472 = F_458 ( V_476 ) ;
V_472 &= ~ V_477 ;
F_457 ( V_476 , V_472 ) ;
}
}
F_456 ( V_17 ) ;
F_470 ( V_17 ) ;
F_483 ( ! V_17 -> V_478 ) ;
V_22 = F_484 ( V_17 ) ;
if ( V_22 ) {
F_15 ( L_14 , V_22 ) ;
goto V_88;
}
V_22 = F_474 ( V_17 ) ;
if ( V_22 )
goto V_88;
F_485 ( V_17 ) ;
V_22 = F_486 ( V_17 ) ;
if ( V_22 )
goto V_88;
V_88:
F_487 ( V_17 , V_467 ) ;
return V_22 ;
}
bool F_488 ( struct V_16 * V_17 , int V_479 )
{
if ( F_489 ( V_17 ) -> V_480 < 6 )
return false ;
if ( V_89 . V_346 )
return false ;
if ( V_479 >= 0 )
return V_479 ;
#ifdef F_490
if ( F_489 ( V_17 ) -> V_480 == 6 && V_481 )
return false ;
#endif
return true ;
}
int F_491 ( struct V_16 * V_17 )
{
int V_22 ;
F_20 ( & V_17 -> V_159 . V_29 ) ;
F_492 ( V_17 ) ;
if ( ! V_89 . V_346 ) {
V_17 -> V_251 . V_447 = V_482 ;
V_17 -> V_251 . V_483 = V_484 ;
} else {
V_17 -> V_251 . V_447 = V_485 ;
V_17 -> V_251 . V_483 = V_486 ;
}
F_476 ( V_17 , V_467 ) ;
F_493 ( V_17 ) ;
V_22 = F_494 ( V_17 ) ;
if ( V_22 )
goto V_163;
V_22 = F_495 ( V_17 ) ;
if ( V_22 )
goto V_163;
V_22 = F_496 ( V_17 ) ;
if ( V_22 )
goto V_163;
V_22 = F_475 ( V_17 ) ;
if ( V_22 == - V_25 ) {
F_15 ( L_15 ) ;
F_324 ( V_17 ) ;
V_22 = 0 ;
}
V_163:
F_487 ( V_17 , V_467 ) ;
F_23 ( & V_17 -> V_159 . V_29 ) ;
return V_22 ;
}
void F_497 ( struct V_16 * V_89 )
{
F_447 ( V_89 ) ;
}
void
F_498 ( struct V_16 * V_17 )
{
struct V_102 * V_91 ;
enum V_329 V_330 ;
F_298 (engine, dev_priv, id)
V_17 -> V_251 . V_483 ( V_91 ) ;
}
void
F_499 ( struct V_16 * V_17 )
{
int V_50 ;
if ( F_489 ( V_17 ) -> V_480 >= 7 && ! F_500 ( V_17 ) &&
! F_501 ( V_17 ) )
V_17 -> V_247 = 32 ;
else if ( F_489 ( V_17 ) -> V_480 >= 4 ||
F_502 ( V_17 ) || F_503 ( V_17 ) ||
F_504 ( V_17 ) || F_505 ( V_17 ) )
V_17 -> V_247 = 16 ;
else
V_17 -> V_247 = 8 ;
if ( F_506 ( V_17 ) )
V_17 -> V_247 =
F_458 ( F_507 ( V_487 . V_488 ) ) ;
for ( V_50 = 0 ; V_50 < V_17 -> V_247 ; V_50 ++ ) {
struct V_248 * V_80 = & V_17 -> V_250 [ V_50 ] ;
V_80 -> V_89 = V_17 ;
V_80 -> V_330 = V_50 ;
F_508 ( & V_80 -> V_93 , & V_17 -> V_12 . V_489 ) ;
}
F_311 ( V_17 ) ;
F_509 ( V_17 ) ;
}
int
F_510 ( struct V_16 * V_17 )
{
int V_182 = - V_52 ;
V_17 -> V_125 = F_511 ( V_1 , V_490 ) ;
if ( ! V_17 -> V_125 )
goto V_491;
V_17 -> V_492 = F_511 ( V_34 , V_490 ) ;
if ( ! V_17 -> V_492 )
goto V_493;
V_17 -> V_494 = F_511 ( V_85 ,
V_490 |
V_495 |
V_496 ) ;
if ( ! V_17 -> V_494 )
goto V_497;
V_17 -> V_498 = F_511 ( V_499 ,
V_490 |
V_495 ) ;
if ( ! V_17 -> V_498 )
goto V_500;
F_20 ( & V_17 -> V_159 . V_29 ) ;
F_416 ( & V_17 -> V_251 . V_501 ) ;
V_182 = F_512 ( V_17 ) ;
F_23 ( & V_17 -> V_159 . V_29 ) ;
if ( V_182 )
goto V_502;
F_416 ( & V_17 -> V_503 ) ;
F_513 ( & V_17 -> V_12 . V_440 , F_438 ) ;
F_514 ( & V_17 -> V_12 . V_439 ) ;
F_416 ( & V_17 -> V_12 . V_196 ) ;
F_416 ( & V_17 -> V_12 . V_195 ) ;
F_416 ( & V_17 -> V_12 . V_489 ) ;
F_416 ( & V_17 -> V_12 . V_234 ) ;
F_515 ( & V_17 -> V_251 . V_252 ,
F_334 ) ;
F_515 ( & V_17 -> V_251 . V_353 ,
F_341 ) ;
F_516 ( & V_17 -> V_28 . V_504 ) ;
F_516 ( & V_17 -> V_28 . V_23 ) ;
F_516 ( & V_17 -> V_505 ) ;
V_17 -> V_12 . V_506 = true ;
F_433 ( & V_17 -> V_12 . V_507 , 0 ) ;
F_517 ( & V_17 -> V_508 . V_254 ) ;
return 0 ;
V_502:
F_518 ( V_17 -> V_498 ) ;
V_500:
F_518 ( V_17 -> V_494 ) ;
V_497:
F_518 ( V_17 -> V_492 ) ;
V_493:
F_518 ( V_17 -> V_125 ) ;
V_491:
return V_182 ;
}
void F_519 ( struct V_16 * V_17 )
{
F_217 ( V_17 ) ;
F_25 ( ! F_520 ( & V_17 -> V_12 . V_439 ) ) ;
F_25 ( V_17 -> V_12 . V_19 ) ;
F_20 ( & V_17 -> V_159 . V_29 ) ;
F_521 ( & V_17 -> V_251 . V_373 ) ;
F_25 ( ! F_203 ( & V_17 -> V_251 . V_501 ) ) ;
F_23 ( & V_17 -> V_159 . V_29 ) ;
F_518 ( V_17 -> V_498 ) ;
F_518 ( V_17 -> V_494 ) ;
F_518 ( V_17 -> V_492 ) ;
F_518 ( V_17 -> V_125 ) ;
F_522 () ;
}
int F_523 ( struct V_16 * V_17 )
{
F_20 ( & V_17 -> V_159 . V_29 ) ;
F_524 ( V_17 ) ;
F_23 ( & V_17 -> V_159 . V_29 ) ;
return 0 ;
}
int F_525 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_189 * V_509 [] = {
& V_17 -> V_12 . V_196 ,
& V_17 -> V_12 . V_195 ,
NULL
} , * * V_510 ;
F_20 ( & V_17 -> V_159 . V_29 ) ;
F_254 ( V_17 , - 1UL , V_285 ) ;
for ( V_510 = V_509 ; * V_510 ; V_510 ++ ) {
F_21 (obj, *p, global_link) {
V_2 -> V_3 . V_69 = V_5 ;
V_2 -> V_3 . V_4 = V_5 ;
}
}
F_23 ( & V_17 -> V_159 . V_29 ) ;
return 0 ;
}
void F_526 ( struct V_26 * V_27 , struct V_31 * V_32 )
{
struct V_110 * V_319 = V_32 -> V_112 ;
struct V_85 * V_322 ;
F_8 ( & V_319 -> V_12 . V_254 ) ;
F_21 (request, &file_priv->mm.request_list, client_link)
V_322 -> V_319 = NULL ;
F_9 ( & V_319 -> V_12 . V_254 ) ;
if ( ! F_203 ( & V_319 -> V_84 . V_93 ) ) {
F_8 ( & F_17 ( V_27 ) -> V_84 . V_92 ) ;
F_394 ( & V_319 -> V_84 . V_93 ) ;
F_9 ( & F_17 ( V_27 ) -> V_84 . V_92 ) ;
}
}
int F_527 ( struct V_26 * V_27 , struct V_31 * V_32 )
{
struct V_110 * V_319 ;
int V_22 ;
F_265 ( L_16 ) ;
V_319 = F_528 ( sizeof( * V_319 ) , V_57 ) ;
if ( ! V_319 )
return - V_52 ;
V_32 -> V_112 = V_319 ;
V_319 -> V_17 = F_17 ( V_27 ) ;
V_319 -> V_32 = V_32 ;
F_416 ( & V_319 -> V_84 . V_93 ) ;
F_517 ( & V_319 -> V_12 . V_254 ) ;
F_416 ( & V_319 -> V_12 . V_511 ) ;
V_319 -> V_512 = - 1 ;
V_22 = F_529 ( V_27 , V_32 ) ;
if ( V_22 )
F_40 ( V_319 ) ;
return V_22 ;
}
void F_530 ( struct V_1 * V_513 ,
struct V_1 * V_514 ,
unsigned V_435 )
{
F_63 ( V_515 * V_516 >
sizeof( V_517 ) * V_518 ) ;
if ( V_513 ) {
F_25 ( ! ( F_239 ( & V_513 -> V_435 ) & V_435 ) ) ;
F_531 ( V_435 , & V_513 -> V_435 ) ;
}
if ( V_514 ) {
F_25 ( F_239 ( & V_514 -> V_435 ) & V_435 ) ;
F_532 ( V_435 , & V_514 -> V_435 ) ;
}
}
struct V_1 *
F_533 ( struct V_16 * V_17 ,
const void * V_30 , T_3 V_11 )
{
struct V_1 * V_2 ;
struct V_32 * V_32 ;
T_3 V_59 ;
int V_182 ;
V_2 = F_107 ( V_17 , F_130 ( V_11 , V_53 ) ) ;
if ( F_31 ( V_2 ) )
return V_2 ;
F_45 ( V_2 -> V_3 . V_4 != V_5 ) ;
V_32 = V_2 -> V_3 . V_43 ;
V_59 = 0 ;
do {
unsigned int V_177 = F_195 ( F_336 ( V_11 ) , V_11 , V_53 ) ;
struct V_54 * V_54 ;
void * V_519 , * V_49 ;
V_182 = F_281 ( V_32 , V_32 -> V_44 ,
V_59 , V_177 , 0 ,
& V_54 , & V_519 ) ;
if ( V_182 < 0 )
goto V_426;
V_49 = F_132 ( V_54 ) ;
memcpy ( V_49 , V_30 , V_177 ) ;
F_133 ( V_54 ) ;
V_182 = F_282 ( V_32 , V_32 -> V_44 ,
V_59 , V_177 , V_177 ,
V_54 , V_519 ) ;
if ( V_182 < 0 )
goto V_426;
V_11 -= V_177 ;
V_30 += V_177 ;
V_59 += V_177 ;
} while ( V_11 );
return V_2 ;
V_426:
F_110 ( V_2 ) ;
return F_27 ( V_182 ) ;
}
struct V_47 *
F_534 ( struct V_1 * V_2 ,
unsigned int V_520 ,
unsigned int * V_59 )
{
struct V_521 * V_257 = & V_2 -> V_12 . V_259 ;
struct V_47 * V_48 ;
unsigned int V_154 , V_100 ;
F_12 () ;
F_45 ( V_520 >= V_2 -> V_3 . V_11 >> V_155 ) ;
F_45 ( ! F_236 ( V_2 ) ) ;
if ( V_520 < F_237 ( V_257 -> V_294 ) )
goto V_522;
F_20 ( & V_257 -> V_254 ) ;
V_48 = V_257 -> V_293 ;
V_154 = V_257 -> V_294 ;
V_100 = F_535 ( V_48 ) ;
while ( V_154 + V_100 <= V_520 ) {
unsigned long V_523 , V_50 ;
int V_22 ;
V_22 = F_536 ( & V_257 -> V_260 , V_154 , V_48 ) ;
if ( V_22 && V_22 != - V_524 )
goto V_525;
V_523 =
V_526 |
V_154 << V_527 ;
for ( V_50 = 1 ; V_50 < V_100 ; V_50 ++ ) {
V_22 = F_536 ( & V_257 -> V_260 , V_154 + V_50 ,
( void * ) V_523 ) ;
if ( V_22 && V_22 != - V_524 )
goto V_525;
}
V_154 += V_100 ;
V_48 = F_537 ( V_48 ) ;
V_100 = F_535 ( V_48 ) ;
}
V_525:
V_257 -> V_293 = V_48 ;
V_257 -> V_294 = V_154 ;
F_23 ( & V_257 -> V_254 ) ;
if ( F_128 ( V_520 < V_154 ) )
goto V_522;
while ( V_154 + V_100 <= V_520 ) {
V_154 += V_100 ;
V_48 = F_537 ( V_48 ) ;
V_100 = F_535 ( V_48 ) ;
}
* V_59 = V_520 - V_154 ;
return V_48 ;
V_522:
F_382 () ;
V_48 = F_538 ( & V_257 -> V_260 , V_520 ) ;
F_45 ( ! V_48 ) ;
* V_59 = 0 ;
if ( F_128 ( F_539 ( V_48 ) ) ) {
unsigned long V_3 =
( unsigned long ) V_48 >> V_527 ;
V_48 = F_538 ( & V_257 -> V_260 , V_3 ) ;
F_45 ( ! V_48 ) ;
* V_59 = V_520 - V_3 ;
}
F_384 () ;
return V_48 ;
}
struct V_54 *
F_139 ( struct V_1 * V_2 , unsigned int V_520 )
{
struct V_47 * V_48 ;
unsigned int V_59 ;
F_45 ( ! F_122 ( V_2 ) ) ;
V_48 = F_534 ( V_2 , V_520 , & V_59 ) ;
return F_540 ( F_248 ( V_48 ) , V_59 ) ;
}
struct V_54 *
F_541 ( struct V_1 * V_2 ,
unsigned int V_520 )
{
struct V_54 * V_54 ;
V_54 = F_139 ( V_2 , V_520 ) ;
if ( ! V_2 -> V_12 . V_68 )
F_48 ( V_54 ) ;
return V_54 ;
}
T_15
F_156 ( struct V_1 * V_2 ,
unsigned long V_520 )
{
struct V_47 * V_48 ;
unsigned int V_59 ;
V_48 = F_534 ( V_2 , V_520 , & V_59 ) ;
return F_41 ( V_48 ) + ( V_59 << V_155 ) ;
}

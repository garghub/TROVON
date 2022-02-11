static bool F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
return F_2 ( F_3 ( V_2 ) ) || V_4 != V_5 ;
}
static bool F_4 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 . V_9 == V_10 )
return false ;
if ( ! F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_11 ) )
return true ;
return V_7 -> V_12 ;
}
static int
F_5 ( struct V_13 * V_14 ,
struct V_15 * V_16 , T_1 V_17 )
{
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
return F_6 ( & V_14 -> V_8 . V_18 , V_16 ,
V_17 , 0 , V_19 ,
0 , V_14 -> V_20 ,
V_21 ) ;
}
static void
F_7 ( struct V_15 * V_16 )
{
F_8 ( V_16 ) ;
}
static void F_9 ( struct V_22 * V_23 ,
T_2 V_17 )
{
F_10 ( & V_23 -> V_18 . V_24 ) ;
V_23 -> V_18 . V_25 ++ ;
V_23 -> V_18 . V_26 += V_17 ;
F_11 ( & V_23 -> V_18 . V_24 ) ;
}
static void F_12 ( struct V_22 * V_23 ,
T_2 V_17 )
{
F_10 ( & V_23 -> V_18 . V_24 ) ;
V_23 -> V_18 . V_25 -- ;
V_23 -> V_18 . V_26 -= V_17 ;
F_11 ( & V_23 -> V_18 . V_24 ) ;
}
static int
F_13 ( struct V_27 * error )
{
int V_28 ;
F_14 () ;
if ( ! F_15 ( error ) )
return 0 ;
V_28 = F_16 ( error -> V_29 ,
! F_15 ( error ) ,
V_30 ) ;
if ( V_28 == 0 ) {
F_17 ( L_1 ) ;
return - V_31 ;
} else if ( V_28 < 0 ) {
return V_28 ;
} else {
return 0 ;
}
}
int F_18 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
int V_28 ;
V_28 = F_13 ( & V_23 -> V_32 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_19 ( & V_2 -> V_33 ) ;
if ( V_28 )
return V_28 ;
return 0 ;
}
int
F_20 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
struct V_13 * V_14 = & V_23 -> V_14 ;
struct V_37 * args = V_34 ;
struct V_38 * V_39 ;
T_3 V_40 ;
V_40 = 0 ;
F_21 ( & V_2 -> V_33 ) ;
F_22 (vma, &ggtt->base.active_list, vm_link)
if ( F_23 ( V_39 ) )
V_40 += V_39 -> V_16 . V_17 ;
F_22 (vma, &ggtt->base.inactive_list, vm_link)
if ( F_23 ( V_39 ) )
V_40 += V_39 -> V_16 . V_17 ;
F_24 ( & V_2 -> V_33 ) ;
args -> V_41 = V_14 -> V_8 . V_42 ;
args -> V_43 = args -> V_41 - V_40 ;
return 0 ;
}
static struct V_44 *
F_25 ( struct V_6 * V_7 )
{
struct V_45 * V_46 = V_7 -> V_8 . V_47 -> V_48 ;
T_4 * V_49 ;
struct V_44 * V_50 ;
struct V_51 * V_52 ;
char * V_53 ;
int V_54 ;
if ( F_26 ( F_27 ( V_7 ) ) )
return F_28 ( - V_55 ) ;
V_49 = F_29 ( V_7 -> V_8 . V_2 ,
V_7 -> V_8 . V_17 ,
F_30 ( V_7 -> V_8 . V_17 ) ) ;
if ( ! V_49 )
return F_28 ( - V_56 ) ;
V_53 = V_49 -> V_53 ;
for ( V_54 = 0 ; V_54 < V_7 -> V_8 . V_17 / V_57 ; V_54 ++ ) {
struct V_58 * V_58 ;
char * V_59 ;
V_58 = F_31 ( V_46 , V_54 ) ;
if ( F_32 ( V_58 ) ) {
V_50 = F_33 ( V_58 ) ;
goto V_60;
}
V_59 = F_34 ( V_58 ) ;
memcpy ( V_53 , V_59 , V_57 ) ;
F_35 ( V_53 , V_57 ) ;
F_36 ( V_59 ) ;
F_37 ( V_58 ) ;
V_53 += V_57 ;
}
F_38 ( F_3 ( V_7 -> V_8 . V_2 ) ) ;
V_50 = F_39 ( sizeof( * V_50 ) , V_61 ) ;
if ( ! V_50 ) {
V_50 = F_28 ( - V_56 ) ;
goto V_60;
}
if ( F_40 ( V_50 , 1 , V_61 ) ) {
F_41 ( V_50 ) ;
V_50 = F_28 ( - V_56 ) ;
goto V_60;
}
V_52 = V_50 -> V_62 ;
V_52 -> V_63 = 0 ;
V_52 -> V_64 = V_7 -> V_8 . V_17 ;
F_42 ( V_52 ) = V_49 -> V_65 ;
F_43 ( V_52 ) = V_7 -> V_8 . V_17 ;
V_7 -> V_66 = V_49 ;
return V_50 ;
V_60:
F_44 ( V_7 -> V_8 . V_2 , V_49 ) ;
return V_50 ;
}
static void
F_45 ( struct V_6 * V_7 ,
struct V_44 * V_67 ,
bool V_68 )
{
F_46 ( V_7 -> V_18 . V_69 == V_70 ) ;
if ( V_7 -> V_18 . V_69 == V_71 )
V_7 -> V_18 . V_72 = false ;
if ( V_68 &&
( V_7 -> V_8 . V_73 & V_10 ) == 0 &&
! F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_11 ) )
F_47 ( V_67 ) ;
V_7 -> V_8 . V_73 = V_10 ;
V_7 -> V_8 . V_9 = V_10 ;
}
static void
F_48 ( struct V_6 * V_7 ,
struct V_44 * V_67 )
{
F_45 ( V_7 , V_67 , false ) ;
if ( V_7 -> V_18 . V_72 ) {
struct V_45 * V_46 = V_7 -> V_8 . V_47 -> V_48 ;
char * V_53 = V_7 -> V_66 -> V_53 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_7 -> V_8 . V_17 / V_57 ; V_54 ++ ) {
struct V_58 * V_58 ;
char * V_74 ;
V_58 = F_31 ( V_46 , V_54 ) ;
if ( F_32 ( V_58 ) )
continue;
V_74 = F_34 ( V_58 ) ;
F_35 ( V_53 , V_57 ) ;
memcpy ( V_74 , V_53 , V_57 ) ;
F_36 ( V_74 ) ;
F_49 ( V_58 ) ;
if ( V_7 -> V_18 . V_69 == V_75 )
F_50 ( V_58 ) ;
F_37 ( V_58 ) ;
V_53 += V_57 ;
}
V_7 -> V_18 . V_72 = false ;
}
F_51 ( V_67 ) ;
F_41 ( V_67 ) ;
F_44 ( V_7 -> V_8 . V_2 , V_7 -> V_66 ) ;
}
static void
F_52 ( struct V_6 * V_7 )
{
F_53 ( V_7 ) ;
}
int F_54 ( struct V_6 * V_7 )
{
struct V_38 * V_39 ;
F_55 ( V_76 ) ;
int V_28 ;
F_56 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
V_28 = F_57 ( V_7 ,
V_77 |
V_78 |
V_79 ,
V_80 ,
NULL ) ;
if ( V_28 )
return V_28 ;
F_58 ( F_3 ( V_7 -> V_8 . V_2 ) ) ;
while ( ( V_39 = F_59 ( & V_7 -> V_81 ,
struct V_38 ,
V_82 ) ) ) {
F_60 ( & V_39 -> V_82 , & V_76 ) ;
V_28 = F_61 ( V_39 ) ;
if ( V_28 )
break;
}
F_62 ( & V_76 , & V_7 -> V_81 ) ;
return V_28 ;
}
static long
F_63 ( struct V_83 * V_84 ,
unsigned int V_85 ,
long V_86 ,
struct V_87 * V_88 )
{
struct V_89 * V_90 ;
F_64 ( V_77 != 0x1 ) ;
if ( F_65 ( V_91 , & V_84 -> V_85 ) )
return V_86 ;
if ( ! F_66 ( V_84 ) )
return F_67 ( V_84 ,
V_85 & V_77 ,
V_86 ) ;
V_90 = F_68 ( V_84 ) ;
if ( F_69 ( V_90 ) )
goto V_92;
if ( V_88 ) {
if ( F_70 ( V_90 -> V_93 ) >= 6 )
F_71 ( V_90 -> V_93 , V_88 , V_90 -> V_94 ) ;
else
V_88 = NULL ;
}
V_86 = F_72 ( V_90 , V_85 , V_86 ) ;
V_92:
if ( V_85 & V_78 && F_69 ( V_90 ) )
F_73 ( V_90 ) ;
if ( V_88 && V_90 -> V_95 == F_74 ( V_90 -> V_96 ) ) {
F_10 ( & V_90 -> V_93 -> V_88 . V_97 ) ;
F_75 ( & V_88 -> V_98 ) ;
F_11 ( & V_90 -> V_93 -> V_88 . V_97 ) ;
}
return V_86 ;
}
static long
F_76 ( struct V_99 * V_100 ,
unsigned int V_85 ,
long V_86 ,
struct V_87 * V_88 )
{
struct V_83 * V_101 ;
if ( V_85 & V_79 ) {
struct V_83 * * V_102 ;
unsigned int V_103 , V_54 ;
int V_28 ;
V_28 = F_77 ( V_100 ,
& V_101 , & V_103 , & V_102 ) ;
if ( V_28 )
return V_28 ;
for ( V_54 = 0 ; V_54 < V_103 ; V_54 ++ ) {
V_86 = F_63 ( V_102 [ V_54 ] ,
V_85 , V_86 ,
V_88 ) ;
if ( V_86 < 0 )
break;
F_78 ( V_102 [ V_54 ] ) ;
}
for (; V_54 < V_103 ; V_54 ++ )
F_78 ( V_102 [ V_54 ] ) ;
F_41 ( V_102 ) ;
} else {
V_101 = F_79 ( V_100 ) ;
}
if ( V_101 && V_86 >= 0 )
V_86 = F_63 ( V_101 , V_85 , V_86 , V_88 ) ;
F_78 ( V_101 ) ;
return V_86 ;
}
static void F_80 ( struct V_83 * V_84 , int V_104 )
{
struct V_89 * V_90 ;
struct V_105 * V_96 ;
if ( ! F_66 ( V_84 ) )
return;
V_90 = F_68 ( V_84 ) ;
V_96 = V_90 -> V_96 ;
if ( ! V_96 -> V_106 )
return;
V_96 -> V_106 ( V_90 , V_104 ) ;
}
static void F_81 ( struct V_83 * V_84 , int V_104 )
{
if ( F_82 ( V_84 ) ) {
struct V_107 * V_108 = F_83 ( V_84 ) ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_108 -> V_109 ; V_54 ++ )
F_80 ( V_108 -> V_110 [ V_54 ] , V_104 ) ;
} else {
F_80 ( V_84 , V_104 ) ;
}
}
int
F_84 ( struct V_6 * V_7 ,
unsigned int V_85 ,
int V_104 )
{
struct V_83 * V_101 ;
if ( V_85 & V_79 ) {
struct V_83 * * V_102 ;
unsigned int V_103 , V_54 ;
int V_28 ;
V_28 = F_77 ( V_7 -> V_100 ,
& V_101 , & V_103 , & V_102 ) ;
if ( V_28 )
return V_28 ;
for ( V_54 = 0 ; V_54 < V_103 ; V_54 ++ ) {
F_81 ( V_102 [ V_54 ] , V_104 ) ;
F_78 ( V_102 [ V_54 ] ) ;
}
F_41 ( V_102 ) ;
} else {
V_101 = F_79 ( V_7 -> V_100 ) ;
}
if ( V_101 ) {
F_81 ( V_101 , V_104 ) ;
F_78 ( V_101 ) ;
}
return 0 ;
}
int
F_57 ( struct V_6 * V_7 ,
unsigned int V_85 ,
long V_86 ,
struct V_87 * V_88 )
{
F_14 () ;
#if F_85 ( V_111 )
F_46 ( V_112 &&
! ! F_86 ( & V_7 -> V_8 . V_2 -> V_33 ) !=
! ! ( V_85 & V_78 ) ) ;
#endif
F_46 ( V_86 < 0 ) ;
V_86 = F_76 ( V_7 -> V_100 ,
V_85 , V_86 ,
V_88 ) ;
return V_86 < 0 ? V_86 : 0 ;
}
static struct V_87 * F_87 ( struct V_35 * V_36 )
{
struct V_113 * V_114 = V_36 -> V_115 ;
return & V_114 -> V_88 ;
}
int
F_88 ( struct V_6 * V_7 ,
int V_116 )
{
int V_28 ;
if ( V_116 > V_7 -> V_8 . V_17 )
return - V_55 ;
if ( V_7 -> V_117 == & V_118 )
return 0 ;
if ( V_7 -> V_18 . V_69 != V_75 )
return - V_119 ;
if ( V_7 -> V_8 . V_47 == NULL )
return - V_55 ;
V_28 = F_54 ( V_7 ) ;
if ( V_28 )
return V_28 ;
F_89 ( V_7 , V_120 ) ;
if ( V_7 -> V_18 . V_67 )
return - V_121 ;
V_7 -> V_117 = & V_118 ;
return F_90 ( V_7 ) ;
}
static int
F_91 ( struct V_6 * V_7 ,
struct V_122 * args ,
struct V_35 * V_36 )
{
void * V_53 = V_7 -> V_66 -> V_53 + args -> V_63 ;
char T_5 * V_123 = F_92 ( args -> V_124 ) ;
F_93 ( V_7 , V_125 ) ;
if ( F_94 ( V_53 , V_123 , args -> V_17 ) )
return - V_119 ;
F_35 ( V_53 , args -> V_17 ) ;
F_38 ( F_3 ( V_7 -> V_8 . V_2 ) ) ;
F_95 ( V_7 , false , V_125 ) ;
return 0 ;
}
void * F_96 ( struct V_22 * V_23 )
{
return F_97 ( V_23 -> V_126 , V_61 ) ;
}
void F_98 ( struct V_6 * V_7 )
{
struct V_22 * V_23 = F_3 ( V_7 -> V_8 . V_2 ) ;
F_99 ( V_23 -> V_126 , V_7 ) ;
}
static int
F_100 ( struct V_35 * V_36 ,
struct V_22 * V_23 ,
T_6 V_17 ,
T_7 * V_127 )
{
struct V_6 * V_7 ;
int V_28 ;
T_1 V_128 ;
V_17 = F_101 ( V_17 , V_57 ) ;
if ( V_17 == 0 )
return - V_55 ;
V_7 = F_102 ( V_23 , V_17 ) ;
if ( F_32 ( V_7 ) )
return F_103 ( V_7 ) ;
V_28 = F_104 ( V_36 , & V_7 -> V_8 , & V_128 ) ;
F_105 ( V_7 ) ;
if ( V_28 )
return V_28 ;
* V_127 = V_128 ;
return 0 ;
}
int
F_106 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
struct V_129 * args )
{
args -> V_130 = F_107 ( args -> V_131 * F_108 ( args -> V_132 , 8 ) , 64 ) ;
args -> V_17 = args -> V_130 * args -> V_133 ;
return F_100 ( V_36 , F_3 ( V_2 ) ,
args -> V_17 , & args -> V_128 ) ;
}
int
F_109 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
struct V_134 * args = V_34 ;
F_110 ( V_23 ) ;
return F_100 ( V_36 , V_23 ,
args -> V_17 , & args -> V_128 ) ;
}
static inline int
F_111 ( char T_5 * V_135 ,
const char * V_136 , int V_137 ,
int V_64 )
{
int V_28 , V_138 = 0 ;
while ( V_64 > 0 ) {
int V_139 = F_107 ( V_137 + 1 , 64 ) ;
int V_140 = F_112 ( V_139 - V_137 , V_64 ) ;
int V_141 = V_137 ^ 64 ;
V_28 = F_113 ( V_135 + V_138 ,
V_136 + V_141 ,
V_140 ) ;
if ( V_28 )
return V_28 + V_64 ;
V_138 += V_140 ;
V_137 += V_140 ;
V_64 -= V_140 ;
}
return 0 ;
}
static inline int
F_114 ( char * V_136 , int V_137 ,
const char T_5 * V_135 ,
int V_64 )
{
int V_28 , V_138 = 0 ;
while ( V_64 > 0 ) {
int V_139 = F_107 ( V_137 + 1 , 64 ) ;
int V_140 = F_112 ( V_139 - V_137 , V_64 ) ;
int V_141 = V_137 ^ 64 ;
V_28 = F_115 ( V_136 + V_141 ,
V_135 + V_138 ,
V_140 ) ;
if ( V_28 )
return V_28 + V_64 ;
V_138 += V_140 ;
V_137 += V_140 ;
V_64 -= V_140 ;
}
return 0 ;
}
int F_116 ( struct V_6 * V_7 ,
unsigned int * V_68 )
{
int V_28 ;
F_56 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
* V_68 = 0 ;
if ( ! F_117 ( V_7 ) )
return - V_142 ;
V_28 = F_57 ( V_7 ,
V_77 |
V_78 ,
V_80 ,
NULL ) ;
if ( V_28 )
return V_28 ;
V_28 = F_90 ( V_7 ) ;
if ( V_28 )
return V_28 ;
F_118 ( V_7 ) ;
if ( ! ( V_7 -> V_8 . V_73 & V_10 ) )
* V_68 = ! F_1 ( V_7 -> V_8 . V_2 ,
V_7 -> V_11 ) ;
if ( * V_68 && ! F_119 ( V_143 ) ) {
V_28 = F_120 ( V_7 , false ) ;
if ( V_28 )
goto V_144;
* V_68 = 0 ;
}
return 0 ;
V_144:
F_53 ( V_7 ) ;
return V_28 ;
}
int F_121 ( struct V_6 * V_7 ,
unsigned int * V_68 )
{
int V_28 ;
F_56 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
* V_68 = 0 ;
if ( ! F_117 ( V_7 ) )
return - V_142 ;
V_28 = F_57 ( V_7 ,
V_77 |
V_78 |
V_79 ,
V_80 ,
NULL ) ;
if ( V_28 )
return V_28 ;
V_28 = F_90 ( V_7 ) ;
if ( V_28 )
return V_28 ;
F_118 ( V_7 ) ;
if ( V_7 -> V_8 . V_9 != V_10 )
* V_68 |= F_4 ( V_7 ) << 1 ;
if ( ! ( V_7 -> V_8 . V_73 & V_10 ) )
* V_68 |= ! F_1 ( V_7 -> V_8 . V_2 ,
V_7 -> V_11 ) ;
if ( * V_68 && ! F_119 ( V_143 ) ) {
V_28 = F_120 ( V_7 , true ) ;
if ( V_28 )
goto V_144;
* V_68 = 0 ;
}
if ( ( * V_68 & V_145 ) == 0 )
V_7 -> V_146 = true ;
F_93 ( V_7 , V_125 ) ;
V_7 -> V_18 . V_72 = true ;
return 0 ;
V_144:
F_53 ( V_7 ) ;
return V_28 ;
}
static void
F_122 ( char * V_147 , unsigned long V_64 ,
bool V_148 )
{
if ( F_123 ( V_148 ) ) {
unsigned long V_149 = ( unsigned long ) V_147 ;
unsigned long V_150 = ( unsigned long ) V_147 + V_64 ;
V_149 = F_124 ( V_149 , 128 ) ;
V_150 = F_125 ( V_150 , 128 ) ;
F_35 ( ( void * ) V_149 , V_150 - V_149 ) ;
} else {
F_35 ( V_147 , V_64 ) ;
}
}
static int
F_126 ( struct V_58 * V_58 , int V_63 , int V_64 ,
char T_5 * V_123 ,
bool V_151 , bool V_68 )
{
char * V_53 ;
int V_28 ;
V_53 = F_127 ( V_58 ) ;
if ( V_68 )
F_122 ( V_53 + V_63 , V_64 ,
V_151 ) ;
if ( V_151 )
V_28 = F_111 ( V_123 , V_53 , V_63 , V_64 ) ;
else
V_28 = F_113 ( V_123 , V_53 + V_63 , V_64 ) ;
F_128 ( V_58 ) ;
return V_28 ? - V_119 : 0 ;
}
static int
F_129 ( struct V_58 * V_58 , int V_63 , int V_64 , char T_5 * V_123 ,
bool V_151 , bool V_68 )
{
int V_28 ;
V_28 = - V_142 ;
if ( ! V_151 ) {
char * V_53 = F_34 ( V_58 ) ;
if ( V_68 )
F_35 ( V_53 + V_63 , V_64 ) ;
V_28 = F_130 ( V_123 , V_53 + V_63 , V_64 ) ;
F_36 ( V_53 ) ;
}
if ( V_28 == 0 )
return 0 ;
return F_126 ( V_58 , V_63 , V_64 , V_123 ,
V_151 , V_68 ) ;
}
static int
F_131 ( struct V_6 * V_7 ,
struct V_152 * args )
{
char T_5 * V_123 ;
T_2 V_153 ;
unsigned int V_154 ;
unsigned int V_68 ;
unsigned int V_155 , V_63 ;
int V_28 ;
V_154 = 0 ;
if ( F_27 ( V_7 ) )
V_154 = F_132 ( 17 ) ;
V_28 = F_19 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_116 ( V_7 , & V_68 ) ;
F_24 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
if ( V_28 )
return V_28 ;
V_153 = args -> V_17 ;
V_123 = F_92 ( args -> V_124 ) ;
V_63 = F_133 ( args -> V_63 ) ;
for ( V_155 = args -> V_63 >> V_156 ; V_153 ; V_155 ++ ) {
struct V_58 * V_58 = F_134 ( V_7 , V_155 ) ;
int V_64 ;
V_64 = V_153 ;
if ( V_63 + V_64 > V_57 )
V_64 = V_57 - V_63 ;
V_28 = F_129 ( V_58 , V_63 , V_64 , V_123 ,
F_135 ( V_58 ) & V_154 ,
V_68 ) ;
if ( V_28 )
break;
V_153 -= V_64 ;
V_123 += V_64 ;
V_63 = 0 ;
}
F_136 ( V_7 ) ;
return V_28 ;
}
static inline bool
F_137 ( struct V_157 * V_46 ,
T_8 V_8 , int V_63 ,
char T_5 * V_123 , int V_64 )
{
void * V_53 ;
unsigned long V_158 ;
V_53 = ( void V_159 * ) F_138 ( V_46 , V_8 ) ;
V_158 = F_130 ( V_123 , V_53 + V_63 , V_64 ) ;
F_139 ( V_53 ) ;
if ( V_158 ) {
V_53 = ( void V_159 * )
F_140 ( V_46 , V_8 , V_57 ) ;
V_158 = F_141 ( V_123 , V_53 + V_63 , V_64 ) ;
F_142 ( V_53 ) ;
}
return V_158 ;
}
static int
F_143 ( struct V_6 * V_7 ,
const struct V_152 * args )
{
struct V_22 * V_93 = F_3 ( V_7 -> V_8 . V_2 ) ;
struct V_13 * V_14 = & V_93 -> V_14 ;
struct V_15 V_16 ;
struct V_38 * V_39 ;
void T_5 * V_123 ;
T_2 V_153 , V_63 ;
int V_28 ;
V_28 = F_19 ( & V_93 -> V_160 . V_33 ) ;
if ( V_28 )
return V_28 ;
F_144 ( V_93 ) ;
V_39 = F_145 ( V_7 , NULL , 0 , 0 ,
V_161 | V_162 ) ;
if ( ! F_32 ( V_39 ) ) {
V_16 . V_149 = F_146 ( V_39 ) ;
V_16 . V_163 = false ;
V_28 = F_147 ( V_39 ) ;
if ( V_28 ) {
F_148 ( V_39 ) ;
V_39 = F_28 ( V_28 ) ;
}
}
if ( F_32 ( V_39 ) ) {
V_28 = F_5 ( V_14 , & V_16 , V_57 ) ;
if ( V_28 )
goto V_164;
F_46 ( ! V_16 . V_163 ) ;
}
V_28 = F_149 ( V_7 , false ) ;
if ( V_28 )
goto V_165;
F_24 ( & V_93 -> V_160 . V_33 ) ;
V_123 = F_92 ( args -> V_124 ) ;
V_153 = args -> V_17 ;
V_63 = args -> V_63 ;
while ( V_153 > 0 ) {
T_1 V_166 = V_16 . V_149 ;
unsigned V_167 = F_133 ( V_63 ) ;
unsigned V_168 = V_57 - V_167 ;
V_168 = V_153 < V_168 ? V_153 : V_168 ;
if ( V_16 . V_163 ) {
F_150 () ;
V_14 -> V_8 . V_169 ( & V_14 -> V_8 ,
F_151 ( V_7 , V_63 >> V_156 ) ,
V_16 . V_149 , V_5 , 0 ) ;
F_150 () ;
} else {
V_166 += V_63 & V_170 ;
}
if ( F_137 ( & V_14 -> V_171 , V_166 , V_167 ,
V_123 , V_168 ) ) {
V_28 = - V_119 ;
break;
}
V_153 -= V_168 ;
V_123 += V_168 ;
V_63 += V_168 ;
}
F_21 ( & V_93 -> V_160 . V_33 ) ;
V_165:
if ( V_16 . V_163 ) {
F_150 () ;
V_14 -> V_8 . V_172 ( & V_14 -> V_8 ,
V_16 . V_149 , V_16 . V_17 ) ;
F_7 ( & V_16 ) ;
} else {
F_148 ( V_39 ) ;
}
V_164:
F_152 ( V_93 ) ;
F_24 ( & V_93 -> V_160 . V_33 ) ;
return V_28 ;
}
int
F_153 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_152 * args = V_34 ;
struct V_6 * V_7 ;
int V_28 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_154 ( V_173 ,
F_92 ( args -> V_124 ) ,
args -> V_17 ) )
return - V_119 ;
V_7 = F_155 ( V_36 , args -> V_128 ) ;
if ( ! V_7 )
return - V_174 ;
if ( F_156 ( T_2 , args -> V_63 , args -> V_17 , V_7 -> V_8 . V_17 ) ) {
V_28 = - V_55 ;
goto V_92;
}
F_157 ( V_7 , args -> V_63 , args -> V_17 ) ;
V_28 = F_57 ( V_7 ,
V_77 ,
V_80 ,
F_87 ( V_36 ) ) ;
if ( V_28 )
goto V_92;
V_28 = F_90 ( V_7 ) ;
if ( V_28 )
goto V_92;
V_28 = F_131 ( V_7 , args ) ;
if ( V_28 == - V_119 || V_28 == - V_142 )
V_28 = F_143 ( V_7 , args ) ;
F_53 ( V_7 ) ;
V_92:
F_105 ( V_7 ) ;
return V_28 ;
}
static inline bool
F_158 ( struct V_157 * V_46 ,
T_8 V_8 , int V_63 ,
char T_5 * V_123 , int V_64 )
{
void * V_53 ;
unsigned long V_158 ;
V_53 = ( void V_159 * ) F_138 ( V_46 , V_8 ) ;
V_158 = F_159 ( V_53 + V_63 ,
V_123 , V_64 ) ;
F_139 ( V_53 ) ;
if ( V_158 ) {
V_53 = ( void V_159 * )
F_140 ( V_46 , V_8 , V_57 ) ;
V_158 = F_94 ( V_53 + V_63 , V_123 , V_64 ) ;
F_142 ( V_53 ) ;
}
return V_158 ;
}
static int
F_160 ( struct V_6 * V_7 ,
const struct V_122 * args )
{
struct V_22 * V_93 = F_3 ( V_7 -> V_8 . V_2 ) ;
struct V_13 * V_14 = & V_93 -> V_14 ;
struct V_15 V_16 ;
struct V_38 * V_39 ;
T_2 V_153 , V_63 ;
void T_5 * V_123 ;
int V_28 ;
V_28 = F_19 ( & V_93 -> V_160 . V_33 ) ;
if ( V_28 )
return V_28 ;
F_144 ( V_93 ) ;
V_39 = F_145 ( V_7 , NULL , 0 , 0 ,
V_161 | V_162 ) ;
if ( ! F_32 ( V_39 ) ) {
V_16 . V_149 = F_146 ( V_39 ) ;
V_16 . V_163 = false ;
V_28 = F_147 ( V_39 ) ;
if ( V_28 ) {
F_148 ( V_39 ) ;
V_39 = F_28 ( V_28 ) ;
}
}
if ( F_32 ( V_39 ) ) {
V_28 = F_5 ( V_14 , & V_16 , V_57 ) ;
if ( V_28 )
goto V_164;
F_46 ( ! V_16 . V_163 ) ;
}
V_28 = F_149 ( V_7 , true ) ;
if ( V_28 )
goto V_165;
F_24 ( & V_93 -> V_160 . V_33 ) ;
F_93 ( V_7 , V_125 ) ;
V_123 = F_92 ( args -> V_124 ) ;
V_63 = args -> V_63 ;
V_153 = args -> V_17 ;
while ( V_153 ) {
T_1 V_166 = V_16 . V_149 ;
unsigned int V_167 = F_133 ( V_63 ) ;
unsigned int V_168 = V_57 - V_167 ;
V_168 = V_153 < V_168 ? V_153 : V_168 ;
if ( V_16 . V_163 ) {
F_150 () ;
V_14 -> V_8 . V_169 ( & V_14 -> V_8 ,
F_151 ( V_7 , V_63 >> V_156 ) ,
V_16 . V_149 , V_5 , 0 ) ;
F_150 () ;
} else {
V_166 += V_63 & V_170 ;
}
if ( F_158 ( & V_14 -> V_171 , V_166 , V_167 ,
V_123 , V_168 ) ) {
V_28 = - V_119 ;
break;
}
V_153 -= V_168 ;
V_123 += V_168 ;
V_63 += V_168 ;
}
F_95 ( V_7 , false , V_125 ) ;
F_21 ( & V_93 -> V_160 . V_33 ) ;
V_165:
if ( V_16 . V_163 ) {
F_150 () ;
V_14 -> V_8 . V_172 ( & V_14 -> V_8 ,
V_16 . V_149 , V_16 . V_17 ) ;
F_7 ( & V_16 ) ;
} else {
F_148 ( V_39 ) ;
}
V_164:
F_152 ( V_93 ) ;
F_24 ( & V_93 -> V_160 . V_33 ) ;
return V_28 ;
}
static int
F_161 ( struct V_58 * V_58 , int V_63 , int V_64 ,
char T_5 * V_123 ,
bool V_151 ,
bool V_175 ,
bool V_176 )
{
char * V_53 ;
int V_28 ;
V_53 = F_127 ( V_58 ) ;
if ( F_123 ( V_175 || V_151 ) )
F_122 ( V_53 + V_63 , V_64 ,
V_151 ) ;
if ( V_151 )
V_28 = F_114 ( V_53 , V_63 , V_123 ,
V_64 ) ;
else
V_28 = F_115 ( V_53 + V_63 , V_123 , V_64 ) ;
if ( V_176 )
F_122 ( V_53 + V_63 , V_64 ,
V_151 ) ;
F_128 ( V_58 ) ;
return V_28 ? - V_119 : 0 ;
}
static int
F_162 ( struct V_58 * V_58 , int V_63 , int V_177 , char T_5 * V_123 ,
bool V_151 ,
bool V_175 ,
bool V_176 )
{
int V_28 ;
V_28 = - V_142 ;
if ( ! V_151 ) {
char * V_53 = F_34 ( V_58 ) ;
if ( V_175 )
F_35 ( V_53 + V_63 , V_177 ) ;
V_28 = F_163 ( V_53 + V_63 , V_123 , V_177 ) ;
if ( V_176 )
F_35 ( V_53 + V_63 , V_177 ) ;
F_36 ( V_53 ) ;
}
if ( V_28 == 0 )
return V_28 ;
return F_161 ( V_58 , V_63 , V_177 , V_123 ,
V_151 ,
V_175 ,
V_176 ) ;
}
static int
F_164 ( struct V_6 * V_7 ,
const struct V_122 * args )
{
struct V_22 * V_93 = F_3 ( V_7 -> V_8 . V_2 ) ;
void T_5 * V_123 ;
T_2 V_153 ;
unsigned int V_154 ;
unsigned int V_178 ;
unsigned int V_68 ;
unsigned int V_63 , V_155 ;
int V_28 ;
V_28 = F_19 ( & V_93 -> V_160 . V_33 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_121 ( V_7 , & V_68 ) ;
F_24 ( & V_93 -> V_160 . V_33 ) ;
if ( V_28 )
return V_28 ;
V_154 = 0 ;
if ( F_27 ( V_7 ) )
V_154 = F_132 ( 17 ) ;
V_178 = 0 ;
if ( V_68 & V_179 )
V_178 = V_180 . V_181 - 1 ;
V_123 = F_92 ( args -> V_124 ) ;
V_153 = args -> V_17 ;
V_63 = F_133 ( args -> V_63 ) ;
for ( V_155 = args -> V_63 >> V_156 ; V_153 ; V_155 ++ ) {
struct V_58 * V_58 = F_134 ( V_7 , V_155 ) ;
int V_64 ;
V_64 = V_153 ;
if ( V_63 + V_64 > V_57 )
V_64 = V_57 - V_63 ;
V_28 = F_162 ( V_58 , V_63 , V_64 , V_123 ,
F_135 ( V_58 ) & V_154 ,
( V_63 | V_64 ) & V_178 ,
V_68 & V_145 ) ;
if ( V_28 )
break;
V_153 -= V_64 ;
V_123 += V_64 ;
V_63 = 0 ;
}
F_95 ( V_7 , false , V_125 ) ;
F_136 ( V_7 ) ;
return V_28 ;
}
int
F_165 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_122 * args = V_34 ;
struct V_6 * V_7 ;
int V_28 ;
if ( args -> V_17 == 0 )
return 0 ;
if ( ! F_154 ( V_182 ,
F_92 ( args -> V_124 ) ,
args -> V_17 ) )
return - V_119 ;
V_7 = F_155 ( V_36 , args -> V_128 ) ;
if ( ! V_7 )
return - V_174 ;
if ( F_156 ( T_2 , args -> V_63 , args -> V_17 , V_7 -> V_8 . V_17 ) ) {
V_28 = - V_55 ;
goto V_183;
}
F_166 ( V_7 , args -> V_63 , args -> V_17 ) ;
V_28 = - V_142 ;
if ( V_7 -> V_117 -> V_184 )
V_28 = V_7 -> V_117 -> V_184 ( V_7 , args ) ;
if ( V_28 != - V_142 )
goto V_183;
V_28 = F_57 ( V_7 ,
V_77 |
V_79 ,
V_80 ,
F_87 ( V_36 ) ) ;
if ( V_28 )
goto V_183;
V_28 = F_90 ( V_7 ) ;
if ( V_28 )
goto V_183;
V_28 = - V_119 ;
if ( ! F_117 ( V_7 ) ||
F_4 ( V_7 ) )
V_28 = F_160 ( V_7 , args ) ;
if ( V_28 == - V_119 || V_28 == - V_185 ) {
if ( V_7 -> V_66 )
V_28 = F_91 ( V_7 , args , V_36 ) ;
else
V_28 = F_164 ( V_7 , args ) ;
}
F_53 ( V_7 ) ;
V_183:
F_105 ( V_7 ) ;
return V_28 ;
}
static inline enum V_186
F_167 ( struct V_6 * V_7 , unsigned V_187 )
{
return ( V_187 == V_188 ?
V_7 -> V_189 : V_125 ) ;
}
static void F_168 ( struct V_6 * V_7 )
{
struct V_22 * V_93 ;
struct V_190 * V_191 ;
struct V_38 * V_39 ;
F_22 (vma, &obj->vma_list, obj_link) {
if ( ! F_169 ( V_39 ) )
break;
if ( F_170 ( V_39 ) )
continue;
if ( ! F_171 ( & V_39 -> V_16 ) )
continue;
F_60 ( & V_39 -> V_192 , & V_39 -> V_193 -> V_194 ) ;
}
V_93 = F_3 ( V_7 -> V_8 . V_2 ) ;
V_191 = V_7 -> V_195 ? & V_93 -> V_18 . V_196 : & V_93 -> V_18 . V_197 ;
F_60 ( & V_7 -> V_198 , V_191 ) ;
}
int
F_172 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_199 * args = V_34 ;
struct V_6 * V_7 ;
T_7 V_73 = args -> V_73 ;
T_7 V_9 = args -> V_9 ;
int V_183 ;
if ( ( V_9 | V_73 ) & V_200 )
return - V_55 ;
if ( V_9 != 0 && V_73 != V_9 )
return - V_55 ;
V_7 = F_155 ( V_36 , args -> V_128 ) ;
if ( ! V_7 )
return - V_174 ;
V_183 = F_57 ( V_7 ,
V_77 |
( V_9 ? V_79 : 0 ) ,
V_80 ,
F_87 ( V_36 ) ) ;
if ( V_183 )
goto V_92;
V_183 = F_90 ( V_7 ) ;
if ( V_183 )
goto V_92;
V_183 = F_18 ( V_2 ) ;
if ( V_183 )
goto V_165;
if ( V_73 & V_188 )
V_183 = F_149 ( V_7 , V_9 != 0 ) ;
else
V_183 = F_120 ( V_7 , V_9 != 0 ) ;
F_168 ( V_7 ) ;
F_24 ( & V_2 -> V_33 ) ;
if ( V_9 != 0 )
F_93 ( V_7 , F_167 ( V_7 , V_9 ) ) ;
V_165:
F_53 ( V_7 ) ;
V_92:
F_105 ( V_7 ) ;
return V_183 ;
}
int
F_173 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_201 * args = V_34 ;
struct V_6 * V_7 ;
int V_183 = 0 ;
V_7 = F_155 ( V_36 , args -> V_128 ) ;
if ( ! V_7 )
return - V_174 ;
if ( F_174 ( V_7 -> V_12 ) ) {
V_183 = F_18 ( V_2 ) ;
if ( ! V_183 ) {
F_175 ( V_7 ) ;
F_24 ( & V_2 -> V_33 ) ;
}
}
F_105 ( V_7 ) ;
return V_183 ;
}
int
F_176 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_202 * args = V_34 ;
struct V_6 * V_7 ;
unsigned long V_147 ;
if ( args -> V_85 & ~ ( V_203 ) )
return - V_55 ;
if ( args -> V_85 & V_203 && ! F_177 ( V_204 ) )
return - V_142 ;
V_7 = F_155 ( V_36 , args -> V_128 ) ;
if ( ! V_7 )
return - V_174 ;
if ( ! V_7 -> V_8 . V_47 ) {
F_105 ( V_7 ) ;
return - V_55 ;
}
V_147 = F_178 ( V_7 -> V_8 . V_47 , 0 , args -> V_17 ,
V_205 | V_206 , V_207 ,
args -> V_63 ) ;
if ( args -> V_85 & V_203 ) {
struct V_208 * V_18 = V_209 -> V_18 ;
struct V_210 * V_39 ;
if ( F_179 ( & V_18 -> V_211 ) ) {
F_105 ( V_7 ) ;
return - V_212 ;
}
V_39 = F_180 ( V_18 , V_147 ) ;
if ( V_39 )
V_39 -> V_213 =
F_181 ( F_182 ( V_39 -> V_214 ) ) ;
else
V_147 = - V_56 ;
F_183 ( & V_18 -> V_211 ) ;
F_184 ( V_7 -> V_189 , V_125 ) ;
}
F_105 ( V_7 ) ;
if ( F_32 ( ( void * ) V_147 ) )
return V_147 ;
args -> V_215 = ( T_6 ) V_147 ;
return 0 ;
}
static unsigned int F_185 ( struct V_6 * V_7 )
{
return F_186 ( V_7 ) >> V_156 ;
}
int F_187 ( void )
{
return 1 ;
}
static inline struct V_216
F_188 ( struct V_6 * V_7 ,
T_9 V_167 ,
unsigned int V_217 )
{
struct V_216 V_218 ;
if ( F_189 ( V_7 ) )
V_217 = F_101 ( V_217 , F_185 ( V_7 ) ) ;
V_218 . type = V_219 ;
V_218 . V_220 . V_63 = F_190 ( V_167 , V_217 ) ;
V_218 . V_220 . V_17 =
F_191 (unsigned int, chunk,
(obj->base.size >> PAGE_SHIFT) - view.partial.offset) ;
if ( V_217 >= V_7 -> V_8 . V_17 >> V_156 )
V_218 . type = V_221 ;
return V_218 ;
}
int F_192 ( struct V_222 * V_223 )
{
#define F_193 ((1 << 20) >> PAGE_SHIFT)
struct V_210 * V_224 = V_223 -> V_39 ;
struct V_6 * V_7 = F_194 ( V_224 -> V_225 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_22 * V_23 = F_3 ( V_2 ) ;
struct V_13 * V_14 = & V_23 -> V_14 ;
bool V_226 = ! ! ( V_223 -> V_85 & V_227 ) ;
struct V_38 * V_39 ;
T_9 V_167 ;
unsigned int V_85 ;
int V_28 ;
V_167 = ( V_223 -> V_228 - V_224 -> V_229 ) >> V_156 ;
F_195 ( V_7 , V_167 , true , V_226 ) ;
V_28 = F_57 ( V_7 ,
V_77 ,
V_80 ,
NULL ) ;
if ( V_28 )
goto V_183;
V_28 = F_90 ( V_7 ) ;
if ( V_28 )
goto V_183;
F_144 ( V_23 ) ;
V_28 = F_18 ( V_2 ) ;
if ( V_28 )
goto V_230;
if ( V_7 -> V_11 != V_5 && ! F_2 ( V_23 ) ) {
V_28 = - V_119 ;
goto V_231;
}
V_85 = V_161 ;
if ( V_7 -> V_8 . V_17 > 2 * F_193 << V_156 )
V_85 |= V_162 | V_232 ;
V_39 = F_145 ( V_7 , NULL , 0 , 0 , V_85 ) ;
if ( F_32 ( V_39 ) ) {
struct V_216 V_218 =
F_188 ( V_7 , V_167 , F_193 ) ;
V_7 -> V_189 = V_125 ;
V_39 = F_145 ( V_7 , & V_218 , 0 , 0 , V_161 ) ;
}
if ( F_32 ( V_39 ) ) {
V_28 = F_103 ( V_39 ) ;
goto V_231;
}
V_28 = F_149 ( V_7 , V_226 ) ;
if ( V_28 )
goto V_144;
V_28 = F_196 ( V_39 ) ;
if ( V_28 )
goto V_144;
F_197 ( V_23 ) ;
if ( F_198 ( & V_7 -> V_233 ) )
F_199 ( & V_7 -> V_233 , & V_23 -> V_18 . V_234 ) ;
V_28 = F_200 ( V_224 ,
V_224 -> V_229 + ( V_39 -> V_235 . V_220 . V_63 << V_156 ) ,
( V_14 -> V_236 + V_39 -> V_16 . V_149 ) >> V_156 ,
F_191 ( T_2 , V_39 -> V_17 , V_224 -> V_237 - V_224 -> V_229 ) ,
& V_14 -> V_171 ) ;
V_144:
F_201 ( V_39 ) ;
V_231:
F_24 ( & V_2 -> V_33 ) ;
V_230:
F_152 ( V_23 ) ;
F_53 ( V_7 ) ;
V_183:
switch ( V_28 ) {
case - V_31 :
if ( ! F_202 ( & V_23 -> V_32 ) ) {
V_28 = V_238 ;
break;
}
case - V_239 :
case 0 :
case - V_240 :
case - V_212 :
case - V_121 :
V_28 = V_241 ;
break;
case - V_56 :
V_28 = V_242 ;
break;
case - V_185 :
case - V_119 :
V_28 = V_238 ;
break;
default:
F_203 ( V_28 , L_2 , V_28 ) ;
V_28 = V_238 ;
break;
}
return V_28 ;
}
void
F_204 ( struct V_6 * V_7 )
{
struct V_22 * V_93 = F_3 ( V_7 -> V_8 . V_2 ) ;
F_56 ( & V_93 -> V_160 . V_33 ) ;
F_144 ( V_93 ) ;
if ( F_198 ( & V_7 -> V_233 ) )
goto V_92;
F_75 ( & V_7 -> V_233 ) ;
F_205 ( & V_7 -> V_8 . V_243 ,
V_7 -> V_8 . V_2 -> V_244 -> V_245 ) ;
F_150 () ;
V_92:
F_152 ( V_93 ) ;
}
void F_206 ( struct V_22 * V_23 )
{
struct V_6 * V_7 , * V_246 ;
int V_54 ;
F_207 (obj, on,
&dev_priv->mm.userfault_list, userfault_link) {
F_75 ( & V_7 -> V_233 ) ;
F_205 ( & V_7 -> V_8 . V_243 ,
V_7 -> V_8 . V_2 -> V_244 -> V_245 ) ;
}
for ( V_54 = 0 ; V_54 < V_23 -> V_247 ; V_54 ++ ) {
struct V_248 * V_249 = & V_23 -> V_250 [ V_54 ] ;
if ( ! V_249 -> V_39 )
continue;
F_46 ( ! F_198 ( & V_249 -> V_39 -> V_7 -> V_233 ) ) ;
V_249 -> V_72 = true ;
}
}
static int F_208 ( struct V_6 * V_7 )
{
struct V_22 * V_23 = F_3 ( V_7 -> V_8 . V_2 ) ;
int V_183 ;
V_183 = F_209 ( & V_7 -> V_8 ) ;
if ( F_210 ( ! V_183 ) )
return 0 ;
do {
V_183 = F_211 ( V_23 , V_77 ) ;
if ( V_183 )
break;
F_212 ( V_23 ) ;
V_183 = F_209 ( & V_7 -> V_8 ) ;
if ( ! V_183 )
break;
} while ( F_213 ( & V_23 -> V_251 . V_252 ) );
return V_183 ;
}
static void F_214 ( struct V_6 * V_7 )
{
F_215 ( & V_7 -> V_8 ) ;
}
int
F_216 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
T_7 V_128 ,
T_6 * V_63 )
{
struct V_6 * V_7 ;
int V_28 ;
V_7 = F_155 ( V_36 , V_128 ) ;
if ( ! V_7 )
return - V_174 ;
V_28 = F_208 ( V_7 ) ;
if ( V_28 == 0 )
* V_63 = F_217 ( & V_7 -> V_8 . V_243 ) ;
F_105 ( V_7 ) ;
return V_28 ;
}
int
F_218 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_253 * args = V_34 ;
return F_216 ( V_36 , V_2 , args -> V_128 , & args -> V_63 ) ;
}
static void
F_219 ( struct V_6 * V_7 )
{
F_214 ( V_7 ) ;
if ( V_7 -> V_8 . V_47 == NULL )
return;
F_220 ( F_221 ( V_7 -> V_8 . V_47 ) , 0 , ( T_8 ) - 1 ) ;
V_7 -> V_18 . V_69 = V_70 ;
V_7 -> V_18 . V_67 = F_28 ( - V_119 ) ;
}
void F_222 ( struct V_6 * V_7 )
{
struct V_45 * V_46 ;
F_56 ( & V_7 -> V_18 . V_254 ) ;
F_46 ( V_7 -> V_18 . V_67 ) ;
switch ( V_7 -> V_18 . V_69 ) {
case V_71 :
F_219 ( V_7 ) ;
case V_70 :
return;
}
if ( V_7 -> V_8 . V_47 == NULL )
return;
V_46 = V_7 -> V_8 . V_47 -> V_48 ,
F_223 ( V_46 , 0 , ( T_8 ) - 1 ) ;
}
static void
F_224 ( struct V_6 * V_7 ,
struct V_44 * V_67 )
{
struct V_255 V_255 ;
struct V_58 * V_58 ;
F_45 ( V_7 , V_67 , true ) ;
F_225 ( V_7 , V_67 ) ;
if ( F_27 ( V_7 ) )
F_226 ( V_7 , V_67 ) ;
F_227 (page, sgt_iter, pages) {
if ( V_7 -> V_18 . V_72 )
F_49 ( V_58 ) ;
if ( V_7 -> V_18 . V_69 == V_75 )
F_50 ( V_58 ) ;
F_37 ( V_58 ) ;
}
V_7 -> V_18 . V_72 = false ;
F_51 ( V_67 ) ;
F_41 ( V_67 ) ;
}
static void F_228 ( struct V_6 * V_7 )
{
struct V_256 V_257 ;
void * * V_258 ;
F_229 (slot, &obj->mm.get_page.radix, &iter, 0 )
F_230 ( & V_7 -> V_18 . V_259 . V_260 , V_257 . V_261 ) ;
}
void F_89 ( struct V_6 * V_7 ,
enum V_262 V_263 )
{
struct V_44 * V_67 ;
if ( F_231 ( V_7 ) )
return;
F_46 ( V_7 -> V_195 ) ;
if ( ! F_174 ( V_7 -> V_18 . V_67 ) )
return;
F_232 ( & V_7 -> V_18 . V_254 , V_263 ) ;
if ( F_123 ( F_233 ( & V_7 -> V_18 . V_264 ) ) )
goto V_265;
V_67 = F_234 ( & V_7 -> V_18 . V_67 ) ;
F_46 ( ! V_67 ) ;
if ( V_7 -> V_18 . V_46 ) {
void * V_266 ;
V_266 = F_235 ( V_7 -> V_18 . V_46 ) ;
if ( F_236 ( V_266 ) )
F_237 ( V_266 ) ;
else
F_128 ( F_238 ( V_266 ) ) ;
V_7 -> V_18 . V_46 = NULL ;
}
F_228 ( V_7 ) ;
if ( ! F_32 ( V_67 ) )
V_7 -> V_117 -> V_267 ( V_7 , V_67 ) ;
V_265:
F_24 ( & V_7 -> V_18 . V_254 ) ;
}
static void F_239 ( struct V_44 * V_268 )
{
struct V_44 V_269 ;
struct V_51 * V_52 , * V_270 ;
unsigned int V_54 ;
if ( V_268 -> V_271 == V_268 -> V_272 )
return;
if ( F_40 ( & V_269 , V_268 -> V_271 , V_61 | V_273 ) )
return;
V_270 = V_269 . V_62 ;
F_240 (orig_st->sgl, sg, orig_st->nents, i) {
F_241 ( V_270 , F_242 ( V_52 ) , V_52 -> V_64 , 0 ) ;
V_270 = F_243 ( V_270 ) ;
}
F_46 ( V_270 ) ;
F_51 ( V_268 ) ;
* V_268 = V_269 ;
}
static struct V_44 *
F_244 ( struct V_6 * V_7 )
{
struct V_22 * V_23 = F_3 ( V_7 -> V_8 . V_2 ) ;
const unsigned long V_274 = V_7 -> V_8 . V_17 / V_57 ;
unsigned long V_54 ;
struct V_45 * V_46 ;
struct V_44 * V_50 ;
struct V_51 * V_52 ;
struct V_255 V_255 ;
struct V_58 * V_58 ;
unsigned long V_275 = 0 ;
unsigned int V_276 ;
int V_28 ;
T_10 V_277 ;
F_46 ( V_7 -> V_8 . V_73 & V_200 ) ;
F_46 ( V_7 -> V_8 . V_9 & V_200 ) ;
V_276 = F_245 () ;
if ( ! V_276 )
V_276 = F_190 ( V_278 , V_57 ) ;
V_50 = F_39 ( sizeof( * V_50 ) , V_61 ) ;
if ( V_50 == NULL )
return F_28 ( - V_56 ) ;
V_279:
if ( F_40 ( V_50 , V_274 , V_61 ) ) {
F_41 ( V_50 ) ;
return F_28 ( - V_56 ) ;
}
V_46 = V_7 -> V_8 . V_47 -> V_48 ;
V_277 = F_246 ( V_46 , ~ ( V_280 | V_281 ) ) ;
V_277 |= V_282 | V_273 ;
V_52 = V_50 -> V_62 ;
V_50 -> V_271 = 0 ;
for ( V_54 = 0 ; V_54 < V_274 ; V_54 ++ ) {
V_58 = F_247 ( V_46 , V_54 , V_277 ) ;
if ( F_32 ( V_58 ) ) {
F_248 ( V_23 ,
V_274 ,
V_283 |
V_284 |
V_285 ) ;
V_58 = F_247 ( V_46 , V_54 , V_277 ) ;
}
if ( F_32 ( V_58 ) ) {
V_58 = F_31 ( V_46 , V_54 ) ;
if ( F_32 ( V_58 ) ) {
V_28 = F_103 ( V_58 ) ;
goto V_286;
}
}
if ( ! V_54 ||
V_52 -> V_64 >= V_276 ||
F_249 ( V_58 ) != V_275 + 1 ) {
if ( V_54 )
V_52 = F_243 ( V_52 ) ;
V_50 -> V_271 ++ ;
F_241 ( V_52 , V_58 , V_57 , 0 ) ;
} else {
V_52 -> V_64 += V_57 ;
}
V_275 = F_249 ( V_58 ) ;
F_26 ( ( V_277 & V_287 ) && ( V_275 >= 0x00100000UL ) ) ;
}
if ( V_52 )
F_250 ( V_52 ) ;
F_239 ( V_50 ) ;
V_28 = F_251 ( V_7 , V_50 ) ;
if ( V_28 ) {
if ( V_276 > V_57 ) {
F_227 (page, sgt_iter, st)
F_37 ( V_58 ) ;
F_51 ( V_50 ) ;
V_276 = V_57 ;
goto V_279;
} else {
F_252 ( & V_23 -> V_160 . V_288 -> V_2 ,
L_3 ,
V_274 ) ;
goto V_289;
}
}
if ( F_27 ( V_7 ) )
F_253 ( V_7 , V_50 ) ;
return V_50 ;
V_286:
F_250 ( V_52 ) ;
V_289:
F_227 (page, sgt_iter, st)
F_37 ( V_58 ) ;
F_51 ( V_50 ) ;
F_41 ( V_50 ) ;
if ( V_28 == - V_185 )
V_28 = - V_56 ;
return F_28 ( V_28 ) ;
}
void F_254 ( struct V_6 * V_7 ,
struct V_44 * V_67 )
{
F_56 ( & V_7 -> V_18 . V_254 ) ;
V_7 -> V_18 . V_259 . V_290 = V_67 -> V_62 ;
V_7 -> V_18 . V_259 . V_291 = 0 ;
V_7 -> V_18 . V_67 = V_67 ;
if ( F_189 ( V_7 ) &&
F_3 ( V_7 -> V_8 . V_2 ) -> V_292 & V_293 ) {
F_46 ( V_7 -> V_18 . V_294 ) ;
F_255 ( V_7 ) ;
V_7 -> V_18 . V_294 = true ;
}
}
static int F_256 ( struct V_6 * V_7 )
{
struct V_44 * V_67 ;
F_46 ( F_231 ( V_7 ) ) ;
if ( F_123 ( V_7 -> V_18 . V_69 != V_75 ) ) {
F_257 ( L_4 ) ;
return - V_119 ;
}
V_67 = V_7 -> V_117 -> V_295 ( V_7 ) ;
if ( F_123 ( F_32 ( V_67 ) ) )
return F_103 ( V_67 ) ;
F_254 ( V_7 , V_67 ) ;
return 0 ;
}
int F_258 ( struct V_6 * V_7 )
{
int V_183 ;
V_183 = F_19 ( & V_7 -> V_18 . V_254 ) ;
if ( V_183 )
return V_183 ;
if ( F_123 ( F_259 ( V_7 -> V_18 . V_67 ) ) ) {
V_183 = F_256 ( V_7 ) ;
if ( V_183 )
goto V_265;
F_260 () ;
}
F_261 ( & V_7 -> V_18 . V_264 ) ;
V_265:
F_24 ( & V_7 -> V_18 . V_254 ) ;
return V_183 ;
}
static void * F_262 ( const struct V_6 * V_7 ,
enum V_296 type )
{
unsigned long V_297 = V_7 -> V_8 . V_17 >> V_156 ;
struct V_44 * V_298 = V_7 -> V_18 . V_67 ;
struct V_255 V_255 ;
struct V_58 * V_58 ;
struct V_58 * V_299 [ 32 ] ;
struct V_58 * * V_67 = V_299 ;
unsigned long V_54 = 0 ;
T_11 V_300 ;
void * V_147 ;
if ( V_297 == 1 && type == V_301 )
return F_127 ( F_242 ( V_298 -> V_62 ) ) ;
if ( V_297 > F_263 ( V_299 ) ) {
V_67 = F_264 ( V_297 , sizeof( * V_67 ) , V_302 ) ;
if ( ! V_67 )
return NULL ;
}
F_227 (page, sgt_iter, sgt)
V_67 [ V_54 ++ ] = V_58 ;
F_46 ( V_54 != V_297 ) ;
switch ( type ) {
case V_301 :
V_300 = V_303 ;
break;
case V_304 :
V_300 = F_181 ( V_305 ) ;
break;
}
V_147 = F_265 ( V_67 , V_297 , 0 , V_300 ) ;
if ( V_67 != V_299 )
F_266 ( V_67 ) ;
return V_147 ;
}
void * F_267 ( struct V_6 * V_7 ,
enum V_296 type )
{
enum V_296 V_306 ;
bool V_40 ;
void * V_266 ;
int V_28 ;
F_46 ( ! F_117 ( V_7 ) ) ;
V_28 = F_19 ( & V_7 -> V_18 . V_254 ) ;
if ( V_28 )
return F_28 ( V_28 ) ;
V_40 = true ;
if ( ! F_268 ( & V_7 -> V_18 . V_264 ) ) {
if ( F_123 ( F_259 ( V_7 -> V_18 . V_67 ) ) ) {
V_28 = F_256 ( V_7 ) ;
if ( V_28 )
goto V_231;
F_260 () ;
}
F_261 ( & V_7 -> V_18 . V_264 ) ;
V_40 = false ;
}
F_46 ( ! V_7 -> V_18 . V_67 ) ;
V_266 = F_269 ( V_7 -> V_18 . V_46 , V_306 ) ;
if ( V_266 && V_306 != type ) {
if ( V_40 ) {
V_28 = - V_121 ;
goto V_144;
}
if ( F_236 ( V_266 ) )
F_237 ( V_266 ) ;
else
F_128 ( F_238 ( V_266 ) ) ;
V_266 = V_7 -> V_18 . V_46 = NULL ;
}
if ( ! V_266 ) {
V_266 = F_262 ( V_7 , type ) ;
if ( ! V_266 ) {
V_28 = - V_56 ;
goto V_144;
}
V_7 -> V_18 . V_46 = F_270 ( V_266 , type ) ;
}
V_164:
F_24 ( & V_7 -> V_18 . V_254 ) ;
return V_266 ;
V_144:
F_271 ( & V_7 -> V_18 . V_264 ) ;
V_231:
V_266 = F_28 ( V_28 ) ;
goto V_164;
}
static int
F_272 ( struct V_6 * V_7 ,
const struct V_122 * V_307 )
{
struct V_45 * V_46 = V_7 -> V_8 . V_47 -> V_48 ;
char T_5 * V_123 = F_92 ( V_307 -> V_124 ) ;
T_2 V_153 , V_63 ;
unsigned int V_308 ;
if ( F_174 ( V_7 -> V_18 . V_67 ) )
return - V_142 ;
V_153 = V_307 -> V_17 ;
V_63 = V_307 -> V_63 ;
V_308 = F_133 ( V_63 ) ;
do {
unsigned int V_177 , V_158 ;
struct V_58 * V_58 ;
void * V_34 , * V_53 ;
int V_183 ;
V_177 = V_57 - V_308 ;
if ( V_177 > V_153 )
V_177 = V_153 ;
V_183 = F_273 ( V_7 -> V_8 . V_47 , V_46 ,
V_63 , V_177 , 0 ,
& V_58 , & V_34 ) ;
if ( V_183 < 0 )
return V_183 ;
V_53 = F_127 ( V_58 ) ;
V_158 = F_94 ( V_53 + V_308 , V_123 , V_177 ) ;
F_128 ( V_58 ) ;
V_183 = F_274 ( V_7 -> V_8 . V_47 , V_46 ,
V_63 , V_177 , V_177 - V_158 ,
V_58 , V_34 ) ;
if ( V_183 < 0 )
return V_183 ;
if ( V_158 )
return - V_119 ;
V_153 -= V_177 ;
V_123 += V_177 ;
V_63 += V_177 ;
V_308 = 0 ;
} while ( V_153 );
return 0 ;
}
static bool F_275 ( const struct V_309 * V_310 )
{
return ( F_276 ( V_310 ) &&
V_310 -> V_311 >= V_312 ) ;
}
static void F_277 ( struct V_309 * V_310 )
{
V_310 -> V_313 ++ ;
V_310 -> V_311 += V_314 ;
if ( F_275 ( V_310 ) )
F_278 ( V_310 ) ;
F_279 ( L_5 ,
V_310 -> V_315 , V_310 -> V_311 ,
F_280 ( F_281 ( V_310 ) ) ) ;
if ( ! F_281 ( V_310 ) || F_259 ( V_310 -> V_316 ) )
return;
V_310 -> V_316 -> V_317 ++ ;
F_279 ( L_6 ,
V_310 -> V_315 , V_310 -> V_316 -> V_317 ) ;
}
static void F_282 ( struct V_309 * V_310 )
{
V_310 -> V_318 ++ ;
}
struct V_89 *
F_283 ( struct V_105 * V_96 )
{
struct V_89 * V_319 ;
F_22 (request, &engine->timeline->requests, link) {
if ( F_284 ( V_319 ) )
continue;
F_46 ( V_319 -> V_96 != V_96 ) ;
return V_319 ;
}
return NULL ;
}
static bool F_285 ( struct V_105 * V_96 )
{
if ( ! V_96 -> V_320 . V_321 )
return false ;
if ( V_96 -> V_320 . V_322 != F_286 ( V_96 ) ) {
F_279 ( L_7 , V_96 -> V_315 ) ;
return false ;
}
return true ;
}
int F_287 ( struct V_22 * V_23 )
{
struct V_105 * V_96 ;
enum V_323 V_324 ;
int V_183 = 0 ;
F_288 (engine, dev_priv, id) {
struct V_89 * V_319 ;
F_289 ( & V_96 -> V_325 ) ;
F_290 ( & V_96 -> V_325 ) ;
if ( F_285 ( V_96 ) ) {
V_319 = F_283 ( V_96 ) ;
if ( V_319 && V_319 -> V_84 . error == - V_31 )
V_183 = - V_31 ;
}
}
F_291 ( V_23 ) ;
return V_183 ;
}
static void F_292 ( struct V_89 * V_319 )
{
void * V_53 = V_319 -> V_326 -> V_53 ;
T_1 V_327 ;
V_327 = V_319 -> V_327 ;
if ( V_319 -> V_328 < V_327 ) {
memset ( V_53 + V_327 , 0 , V_319 -> V_326 -> V_17 - V_327 ) ;
V_327 = 0 ;
}
memset ( V_53 + V_327 , 0 , V_319 -> V_328 - V_327 ) ;
F_293 ( & V_319 -> V_84 , - V_31 ) ;
}
static void F_294 ( struct V_89 * V_319 )
{
struct V_105 * V_96 = V_319 -> V_96 ;
struct V_309 * V_329 = V_319 -> V_310 ;
struct V_330 * V_331 ;
unsigned long V_85 ;
V_331 = F_295 ( V_329 , V_96 ) ;
F_296 ( & V_96 -> V_331 -> V_254 , V_85 ) ;
F_10 ( & V_331 -> V_254 ) ;
F_297 (request, &engine->timeline->requests, link)
if ( V_319 -> V_310 == V_329 )
F_292 ( V_319 ) ;
F_22 (request, &timeline->requests, link)
F_292 ( V_319 ) ;
F_11 ( & V_331 -> V_254 ) ;
F_298 ( & V_96 -> V_331 -> V_254 , V_85 ) ;
}
static bool F_299 ( struct V_89 * V_319 )
{
const bool V_332 = F_285 ( V_319 -> V_96 ) ;
if ( V_332 ) {
F_277 ( V_319 -> V_310 ) ;
F_292 ( V_319 ) ;
} else {
F_282 ( V_319 -> V_310 ) ;
F_293 ( & V_319 -> V_84 , - V_239 ) ;
}
return V_332 ;
}
static void F_300 ( struct V_105 * V_96 )
{
struct V_89 * V_319 ;
if ( V_96 -> V_333 )
V_96 -> V_333 ( V_96 ) ;
V_319 = F_283 ( V_96 ) ;
if ( V_319 && F_299 ( V_319 ) ) {
F_279 ( L_8 ,
V_96 -> V_315 , V_319 -> V_95 ) ;
if ( F_281 ( V_319 -> V_310 ) )
F_294 ( V_319 ) ;
}
V_96 -> V_334 ( V_96 , V_319 ) ;
}
void F_301 ( struct V_22 * V_23 )
{
struct V_105 * V_96 ;
enum V_323 V_324 ;
F_56 ( & V_23 -> V_160 . V_33 ) ;
F_58 ( V_23 ) ;
F_288 (engine, dev_priv, id)
F_300 ( V_96 ) ;
F_302 ( V_23 ) ;
if ( V_23 -> V_251 . V_335 ) {
F_303 ( V_23 ) ;
F_304 ( V_23 ) ;
if ( F_70 ( V_23 ) >= 6 )
F_305 ( V_23 ) ;
}
}
void F_306 ( struct V_22 * V_23 )
{
struct V_105 * V_96 ;
enum V_323 V_324 ;
F_56 ( & V_23 -> V_160 . V_33 ) ;
F_288 (engine, dev_priv, id)
F_307 ( & V_96 -> V_325 ) ;
}
static void F_308 ( struct V_89 * V_319 )
{
F_293 ( & V_319 -> V_84 , - V_31 ) ;
F_309 ( V_319 ) ;
F_310 ( V_319 -> V_96 , V_319 -> V_95 ) ;
}
static void F_311 ( struct V_105 * V_96 )
{
struct V_89 * V_319 ;
unsigned long V_85 ;
V_96 -> V_336 = F_308 ;
F_296 ( & V_96 -> V_331 -> V_254 , V_85 ) ;
F_22 (request, &engine->timeline->requests, link)
F_293 ( & V_319 -> V_84 , - V_31 ) ;
F_298 ( & V_96 -> V_331 -> V_254 , V_85 ) ;
F_310 ( V_96 ,
F_74 ( V_96 ) ) ;
if ( V_93 . V_337 ) {
unsigned long V_85 ;
F_296 ( & V_96 -> V_331 -> V_254 , V_85 ) ;
F_312 ( V_96 -> V_338 [ 0 ] . V_319 ) ;
F_312 ( V_96 -> V_338 [ 1 ] . V_319 ) ;
memset ( V_96 -> V_338 , 0 , sizeof( V_96 -> V_338 ) ) ;
V_96 -> V_339 = V_340 ;
V_96 -> V_341 = NULL ;
F_298 ( & V_96 -> V_331 -> V_254 , V_85 ) ;
}
}
static int F_313 ( void * V_34 )
{
struct V_22 * V_93 = V_34 ;
struct V_105 * V_96 ;
enum V_323 V_324 ;
F_288 (engine, i915, id)
F_311 ( V_96 ) ;
return 0 ;
}
void F_314 ( struct V_22 * V_23 )
{
F_56 ( & V_23 -> V_160 . V_33 ) ;
F_315 ( V_342 , & V_23 -> V_32 . V_85 ) ;
F_316 ( F_313 , V_23 , NULL ) ;
F_317 ( V_23 ) ;
F_58 ( V_23 ) ;
F_318 ( V_23 -> V_343 , & V_23 -> V_251 . V_344 , 0 ) ;
}
static void
F_319 ( struct V_345 * V_346 )
{
struct V_22 * V_23 =
F_320 ( V_346 , F_321 ( * V_23 ) , V_251 . V_252 . V_346 ) ;
struct V_1 * V_2 = & V_23 -> V_160 ;
if ( F_322 ( & V_2 -> V_33 ) ) {
F_58 ( V_23 ) ;
F_24 ( & V_2 -> V_33 ) ;
}
if ( F_174 ( V_23 -> V_251 . V_335 ) ) {
F_323 ( V_23 ) ;
F_324 ( V_23 -> V_343 ,
& V_23 -> V_251 . V_252 ,
F_325 ( V_347 ) ) ;
}
}
static void
F_326 ( struct V_345 * V_346 )
{
struct V_22 * V_23 =
F_320 ( V_346 , F_321 ( * V_23 ) , V_251 . V_344 . V_346 ) ;
struct V_1 * V_2 = & V_23 -> V_160 ;
struct V_105 * V_96 ;
enum V_323 V_324 ;
bool V_348 ;
if ( ! F_174 ( V_23 -> V_251 . V_335 ) )
return;
F_327 ( F_174 ( V_23 -> V_251 . V_349 ) ||
F_328 ( V_23 ) , 10 ) ;
if ( F_174 ( V_23 -> V_251 . V_349 ) )
return;
V_348 =
F_329 ( & V_23 -> V_32 . V_350 ) ;
if ( ! F_322 ( & V_2 -> V_33 ) ) {
F_318 ( V_23 -> V_343 ,
& V_23 -> V_251 . V_344 ,
F_330 ( 50 ) ) ;
goto V_351;
}
if ( F_331 ( V_346 ) )
goto V_164;
if ( V_23 -> V_251 . V_349 )
goto V_164;
if ( F_327 ( F_328 ( V_23 ) , 10 ) )
F_17 ( L_9 ) ;
F_288 (engine, dev_priv, id)
F_332 ( & V_96 -> V_352 ) ;
F_46 ( ! V_23 -> V_251 . V_335 ) ;
V_23 -> V_251 . V_335 = false ;
V_348 = false ;
if ( F_70 ( V_23 ) >= 6 )
F_333 ( V_23 ) ;
F_152 ( V_23 ) ;
V_164:
F_24 ( & V_2 -> V_33 ) ;
V_351:
if ( V_348 ) {
F_46 ( ! V_23 -> V_251 . V_335 ) ;
F_323 ( V_23 ) ;
}
}
void F_334 ( struct V_353 * V_354 , struct V_35 * V_36 )
{
struct V_6 * V_7 = F_194 ( V_354 ) ;
struct V_113 * V_114 = V_36 -> V_115 ;
struct V_38 * V_39 , * V_355 ;
F_21 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
F_207 (vma, vn, &obj->vma_list, obj_link)
if ( V_39 -> V_193 -> V_36 == V_114 )
F_335 ( V_39 ) ;
if ( F_336 ( V_7 ) &&
! F_337 ( V_7 ) ) {
F_338 ( V_7 ) ;
F_339 ( V_7 ) ;
}
F_24 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
}
static unsigned long F_340 ( T_12 V_356 )
{
if ( V_356 < 0 )
return V_80 ;
if ( V_356 == 0 )
return 0 ;
return F_341 ( V_356 ) ;
}
int
F_342 ( struct V_1 * V_2 , void * V_34 , struct V_35 * V_36 )
{
struct V_357 * args = V_34 ;
struct V_6 * V_7 ;
T_13 V_149 ;
long V_28 ;
if ( args -> V_85 != 0 )
return - V_55 ;
V_7 = F_155 ( V_36 , args -> V_358 ) ;
if ( ! V_7 )
return - V_174 ;
V_149 = F_343 () ;
V_28 = F_57 ( V_7 ,
V_77 | V_79 ,
F_340 ( args -> V_356 ) ,
F_87 ( V_36 ) ) ;
if ( args -> V_356 > 0 ) {
args -> V_356 -= F_344 ( F_345 ( F_343 () , V_149 ) ) ;
if ( args -> V_356 < 0 )
args -> V_356 = 0 ;
if ( V_28 == - V_359 && ! F_346 ( args -> V_356 ) )
args -> V_356 = 0 ;
}
F_105 ( V_7 ) ;
return V_28 ;
}
static int F_347 ( struct V_360 * V_361 , unsigned int V_85 )
{
int V_28 , V_54 ;
for ( V_54 = 0 ; V_54 < F_263 ( V_361 -> V_96 ) ; V_54 ++ ) {
V_28 = F_348 ( & V_361 -> V_96 [ V_54 ] . V_362 , V_85 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
int F_211 ( struct V_22 * V_93 , unsigned int V_85 )
{
int V_28 ;
if ( V_85 & V_78 ) {
struct V_360 * V_361 ;
F_56 ( & V_93 -> V_160 . V_33 ) ;
F_22 (tl, &i915->gt.timelines, link) {
V_28 = F_347 ( V_361 , V_85 ) ;
if ( V_28 )
return V_28 ;
}
} else {
V_28 = F_347 ( & V_93 -> V_251 . V_363 , V_85 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
void F_349 ( struct V_6 * V_7 ,
bool V_364 )
{
if ( ! V_7 -> V_18 . V_67 )
return;
if ( V_7 -> V_365 || V_7 -> V_66 )
return;
if ( ! V_364 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_11 ) ) {
V_7 -> V_146 = true ;
return;
}
F_350 ( V_7 ) ;
F_47 ( V_7 -> V_18 . V_67 ) ;
V_7 -> V_146 = false ;
}
static void
F_118 ( struct V_6 * V_7 )
{
struct V_22 * V_23 = F_3 ( V_7 -> V_8 . V_2 ) ;
if ( V_7 -> V_8 . V_9 != V_188 )
return;
F_150 () ;
if ( F_70 ( V_23 ) >= 6 && ! F_2 ( V_23 ) )
F_351 ( F_352 ( V_23 -> V_96 [ V_366 ] -> V_367 ) ) ;
F_95 ( V_7 , false , F_167 ( V_7 , V_188 ) ) ;
V_7 -> V_8 . V_9 = 0 ;
F_353 ( V_7 ,
V_7 -> V_8 . V_73 ,
V_188 ) ;
}
static void
F_175 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 . V_9 != V_10 )
return;
F_349 ( V_7 , V_7 -> V_12 ) ;
F_95 ( V_7 , false , V_125 ) ;
V_7 -> V_8 . V_9 = 0 ;
F_353 ( V_7 ,
V_7 -> V_8 . V_73 ,
V_10 ) ;
}
int
F_149 ( struct V_6 * V_7 , bool V_226 )
{
T_7 V_368 , V_369 ;
int V_28 ;
F_56 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
V_28 = F_57 ( V_7 ,
V_77 |
V_78 |
( V_226 ? V_79 : 0 ) ,
V_80 ,
NULL ) ;
if ( V_28 )
return V_28 ;
if ( V_7 -> V_8 . V_9 == V_188 )
return 0 ;
V_28 = F_90 ( V_7 ) ;
if ( V_28 )
return V_28 ;
F_175 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_73 & V_188 ) == 0 )
F_354 () ;
V_368 = V_7 -> V_8 . V_9 ;
V_369 = V_7 -> V_8 . V_73 ;
F_46 ( ( V_7 -> V_8 . V_9 & ~ V_188 ) != 0 ) ;
V_7 -> V_8 . V_73 |= V_188 ;
if ( V_226 ) {
V_7 -> V_8 . V_73 = V_188 ;
V_7 -> V_8 . V_9 = V_188 ;
V_7 -> V_18 . V_72 = true ;
}
F_353 ( V_7 ,
V_369 ,
V_368 ) ;
F_53 ( V_7 ) ;
return 0 ;
}
int F_355 ( struct V_6 * V_7 ,
enum V_3 V_11 )
{
struct V_38 * V_39 ;
int V_28 ;
F_56 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
if ( V_7 -> V_11 == V_11 )
return 0 ;
V_370:
F_22 (vma, &obj->vma_list, obj_link) {
if ( ! F_171 ( & V_39 -> V_16 ) )
continue;
if ( F_23 ( V_39 ) ) {
F_257 ( L_10 ) ;
return - V_121 ;
}
if ( F_356 ( V_39 , V_11 ) )
continue;
V_28 = F_61 ( V_39 ) ;
if ( V_28 )
return V_28 ;
goto V_370;
}
if ( V_7 -> V_195 ) {
V_28 = F_57 ( V_7 ,
V_77 |
V_78 |
V_79 ,
V_80 ,
NULL ) ;
if ( V_28 )
return V_28 ;
if ( ! F_2 ( F_3 ( V_7 -> V_8 . V_2 ) ) &&
V_11 != V_5 ) {
F_204 ( V_7 ) ;
F_22 (vma, &obj->vma_list, obj_link) {
V_28 = F_147 ( V_39 ) ;
if ( V_28 )
return V_28 ;
}
} else {
}
F_22 (vma, &obj->vma_list, obj_link) {
if ( ! F_171 ( & V_39 -> V_16 ) )
continue;
V_28 = F_357 ( V_39 , V_11 , V_371 ) ;
if ( V_28 )
return V_28 ;
}
}
if ( V_7 -> V_8 . V_9 == V_10 &&
F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_11 ) )
V_7 -> V_146 = true ;
F_22 (vma, &obj->vma_list, obj_link)
V_39 -> V_16 . V_372 = V_11 ;
V_7 -> V_11 = V_11 ;
return 0 ;
}
int F_358 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_373 * args = V_34 ;
struct V_6 * V_7 ;
int V_183 = 0 ;
F_359 () ;
V_7 = F_360 ( V_36 , args -> V_128 ) ;
if ( ! V_7 ) {
V_183 = - V_174 ;
goto V_92;
}
switch ( V_7 -> V_11 ) {
case V_374 :
case V_375 :
args -> V_376 = V_377 ;
break;
case V_378 :
args -> V_376 = V_379 ;
break;
default:
args -> V_376 = V_380 ;
break;
}
V_92:
F_361 () ;
return V_183 ;
}
int F_362 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_22 * V_93 = F_3 ( V_2 ) ;
struct V_373 * args = V_34 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_28 = 0 ;
switch ( args -> V_376 ) {
case V_380 :
V_4 = V_5 ;
break;
case V_377 :
if ( ! F_2 ( V_93 ) && ! F_363 ( V_93 ) )
return - V_142 ;
V_4 = V_374 ;
break;
case V_379 :
V_4 = F_364 ( V_93 ) ? V_378 : V_5 ;
break;
default:
return - V_55 ;
}
V_7 = F_155 ( V_36 , args -> V_128 ) ;
if ( ! V_7 )
return - V_174 ;
if ( V_7 -> V_11 == V_4 )
goto V_92;
V_28 = F_57 ( V_7 ,
V_77 ,
V_80 ,
F_87 ( V_36 ) ) ;
if ( V_28 )
goto V_92;
V_28 = F_18 ( V_2 ) ;
if ( V_28 )
goto V_92;
V_28 = F_355 ( V_7 , V_4 ) ;
F_24 ( & V_2 -> V_33 ) ;
V_92:
F_105 ( V_7 ) ;
return V_28 ;
}
struct V_38 *
F_365 ( struct V_6 * V_7 ,
T_1 V_381 ,
const struct V_216 * V_218 )
{
struct V_38 * V_39 ;
T_1 V_369 , V_368 ;
int V_28 ;
F_56 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
V_7 -> V_12 ++ ;
V_28 = F_355 ( V_7 ,
F_364 ( F_3 ( V_7 -> V_8 . V_2 ) ) ?
V_378 : V_5 ) ;
if ( V_28 ) {
V_39 = F_28 ( V_28 ) ;
goto V_382;
}
V_39 = F_28 ( - V_185 ) ;
if ( ! V_218 || V_218 -> type == V_221 )
V_39 = F_145 ( V_7 , V_218 , 0 , V_381 ,
V_161 | V_162 ) ;
if ( F_32 ( V_39 ) ) {
struct V_22 * V_93 = F_3 ( V_7 -> V_8 . V_2 ) ;
unsigned int V_85 ;
V_85 = 0 ;
if ( F_366 ( V_93 ) )
V_85 = V_161 ;
V_39 = F_145 ( V_7 , V_218 , 0 , V_381 , V_85 ) ;
}
if ( F_32 ( V_39 ) )
goto V_382;
V_39 -> V_383 = F_367 ( T_2 , V_39 -> V_383 , V_381 ) ;
if ( V_7 -> V_146 || V_7 -> V_8 . V_9 == V_10 ) {
F_349 ( V_7 , true ) ;
F_95 ( V_7 , false , V_384 ) ;
}
V_368 = V_7 -> V_8 . V_9 ;
V_369 = V_7 -> V_8 . V_73 ;
V_7 -> V_8 . V_9 = 0 ;
V_7 -> V_8 . V_73 |= V_188 ;
F_353 ( V_7 ,
V_369 ,
V_368 ) ;
return V_39 ;
V_382:
V_7 -> V_12 -- ;
return V_39 ;
}
void
F_368 ( struct V_38 * V_39 )
{
F_56 ( & V_39 -> V_193 -> V_93 -> V_160 . V_33 ) ;
if ( F_26 ( V_39 -> V_7 -> V_12 == 0 ) )
return;
if ( -- V_39 -> V_7 -> V_12 == 0 )
V_39 -> V_383 = V_385 ;
F_168 ( V_39 -> V_7 ) ;
F_148 ( V_39 ) ;
}
int
F_120 ( struct V_6 * V_7 , bool V_226 )
{
T_7 V_368 , V_369 ;
int V_28 ;
F_56 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
V_28 = F_57 ( V_7 ,
V_77 |
V_78 |
( V_226 ? V_79 : 0 ) ,
V_80 ,
NULL ) ;
if ( V_28 )
return V_28 ;
if ( V_7 -> V_8 . V_9 == V_10 )
return 0 ;
F_118 ( V_7 ) ;
V_368 = V_7 -> V_8 . V_9 ;
V_369 = V_7 -> V_8 . V_73 ;
if ( ( V_7 -> V_8 . V_73 & V_10 ) == 0 ) {
F_349 ( V_7 , false ) ;
V_7 -> V_8 . V_73 |= V_10 ;
}
F_46 ( ( V_7 -> V_8 . V_9 & ~ V_10 ) != 0 ) ;
if ( V_226 ) {
V_7 -> V_8 . V_73 = V_10 ;
V_7 -> V_8 . V_9 = V_10 ;
}
F_353 ( V_7 ,
V_369 ,
V_368 ) ;
return 0 ;
}
static int
F_369 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
struct V_113 * V_316 = V_36 -> V_115 ;
unsigned long V_386 = V_387 - V_388 ;
struct V_89 * V_319 , * V_389 = NULL ;
long V_28 ;
if ( F_202 ( & V_23 -> V_32 ) )
return - V_31 ;
F_10 ( & V_316 -> V_18 . V_254 ) ;
F_22 (request, &file_priv->mm.request_list, client_list) {
if ( F_370 ( V_319 -> V_94 , V_386 ) )
break;
if ( ! V_319 -> V_94 )
continue;
V_389 = V_319 ;
}
if ( V_389 )
F_371 ( V_389 ) ;
F_11 ( & V_316 -> V_18 . V_254 ) ;
if ( V_389 == NULL )
return 0 ;
V_28 = F_72 ( V_389 ,
V_77 ,
V_80 ) ;
F_312 ( V_389 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
struct V_38 *
F_145 ( struct V_6 * V_7 ,
const struct V_216 * V_218 ,
T_2 V_17 ,
T_2 V_381 ,
T_2 V_85 )
{
struct V_22 * V_23 = F_3 ( V_7 -> V_8 . V_2 ) ;
struct V_390 * V_193 = & V_23 -> V_14 . V_8 ;
struct V_38 * V_39 ;
int V_28 ;
F_56 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
V_39 = F_372 ( V_7 , V_193 , V_218 ) ;
if ( F_123 ( F_32 ( V_39 ) ) )
return V_39 ;
if ( F_373 ( V_39 , V_17 , V_381 , V_85 ) ) {
if ( V_85 & V_162 &&
( F_23 ( V_39 ) || F_170 ( V_39 ) ) )
return F_28 ( - V_185 ) ;
if ( V_85 & V_161 ) {
if ( V_39 -> V_391 > V_23 -> V_14 . V_20 )
return F_28 ( - V_392 ) ;
if ( V_85 & V_162 &&
V_39 -> V_391 > V_23 -> V_14 . V_20 / 2 )
return F_28 ( - V_185 ) ;
}
F_374 ( F_23 ( V_39 ) ,
L_11
L_12
L_13 ,
F_146 ( V_39 ) , V_381 ,
! ! ( V_85 & V_161 ) ,
F_375 ( V_39 ) ) ;
V_28 = F_61 ( V_39 ) ;
if ( V_28 )
return F_28 ( V_28 ) ;
}
V_28 = F_376 ( V_39 , V_17 , V_381 , V_85 | V_393 ) ;
if ( V_28 )
return F_28 ( V_28 ) ;
return V_39 ;
}
static T_14 unsigned int F_377 ( unsigned int V_324 )
{
F_64 ( V_394 > 16 ) ;
return 0x10000 << V_324 ;
}
static T_14 unsigned int F_378 ( unsigned int V_324 )
{
return V_324 | F_377 ( V_324 ) ;
}
static T_14 unsigned int
F_379 ( const struct V_83 * V_84 )
{
return F_380 ( V_84 , F_377 ) ;
}
static T_14 unsigned int
F_381 ( const struct V_83 * V_84 )
{
if ( ! V_84 )
return 0 ;
return F_380 ( V_84 , F_378 ) ;
}
int
F_382 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_395 * args = V_34 ;
struct V_6 * V_7 ;
struct V_396 * V_191 ;
unsigned int V_397 ;
int V_183 ;
V_183 = - V_174 ;
F_359 () ;
V_7 = F_360 ( V_36 , args -> V_128 ) ;
if ( ! V_7 )
goto V_92;
V_398:
V_397 = F_383 ( & V_7 -> V_100 -> V_397 ) ;
args -> V_399 = F_381 ( F_384 ( V_7 -> V_100 -> V_400 ) ) ;
V_191 = F_384 ( V_7 -> V_100 -> V_84 ) ;
if ( V_191 ) {
unsigned int V_401 = V_191 -> V_401 , V_54 ;
for ( V_54 = 0 ; V_54 < V_401 ; ++ V_54 ) {
struct V_83 * V_84 =
F_384 ( V_191 -> V_102 [ V_54 ] ) ;
args -> V_399 |= F_379 ( V_84 ) ;
}
}
if ( args -> V_399 && F_385 ( & V_7 -> V_100 -> V_397 , V_397 ) )
goto V_398;
V_183 = 0 ;
V_92:
F_361 () ;
return V_183 ;
}
int
F_386 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_316 )
{
return F_369 ( V_2 , V_316 ) ;
}
int
F_387 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_316 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
struct V_402 * args = V_34 ;
struct V_6 * V_7 ;
int V_183 ;
switch ( args -> V_69 ) {
case V_71 :
case V_75 :
break;
default:
return - V_55 ;
}
V_7 = F_155 ( V_316 , args -> V_128 ) ;
if ( ! V_7 )
return - V_174 ;
V_183 = F_19 ( & V_7 -> V_18 . V_254 ) ;
if ( V_183 )
goto V_92;
if ( V_7 -> V_18 . V_67 &&
F_189 ( V_7 ) &&
V_23 -> V_292 & V_293 ) {
if ( V_7 -> V_18 . V_69 == V_75 ) {
F_46 ( ! V_7 -> V_18 . V_294 ) ;
F_388 ( V_7 ) ;
V_7 -> V_18 . V_294 = false ;
}
if ( args -> V_69 == V_75 ) {
F_46 ( V_7 -> V_18 . V_294 ) ;
F_255 ( V_7 ) ;
V_7 -> V_18 . V_294 = true ;
}
}
if ( V_7 -> V_18 . V_69 != V_70 )
V_7 -> V_18 . V_69 = args -> V_69 ;
if ( V_7 -> V_18 . V_69 == V_71 && ! V_7 -> V_18 . V_67 )
F_219 ( V_7 ) ;
args -> V_403 = V_7 -> V_18 . V_69 != V_70 ;
F_24 ( & V_7 -> V_18 . V_254 ) ;
V_92:
F_105 ( V_7 ) ;
return V_183 ;
}
static void
F_389 ( struct V_404 * V_405 ,
struct V_89 * V_319 )
{
struct V_6 * V_7 =
F_320 ( V_405 , F_321 ( * V_7 ) , V_406 ) ;
F_95 ( V_7 , true , V_407 ) ;
}
void F_390 ( struct V_6 * V_7 ,
const struct V_408 * V_117 )
{
F_391 ( & V_7 -> V_18 . V_254 ) ;
F_392 ( & V_7 -> V_198 ) ;
F_392 ( & V_7 -> V_233 ) ;
F_392 ( & V_7 -> V_409 ) ;
F_392 ( & V_7 -> V_81 ) ;
F_392 ( & V_7 -> V_410 ) ;
V_7 -> V_117 = V_117 ;
F_393 ( & V_7 -> V_411 ) ;
V_7 -> V_100 = & V_7 -> V_411 ;
V_7 -> V_189 = V_412 ;
F_394 ( & V_7 -> V_406 , F_389 ) ;
V_7 -> V_18 . V_69 = V_75 ;
F_395 ( & V_7 -> V_18 . V_259 . V_260 , V_61 | V_273 ) ;
F_391 ( & V_7 -> V_18 . V_259 . V_254 ) ;
F_9 ( F_3 ( V_7 -> V_8 . V_2 ) , V_7 -> V_8 . V_17 ) ;
}
struct V_6 *
F_102 ( struct V_22 * V_23 , T_2 V_17 )
{
struct V_6 * V_7 ;
struct V_45 * V_46 ;
T_10 V_413 ;
int V_28 ;
if ( F_26 ( V_17 >> V_156 > V_414 ) )
return F_28 ( - V_392 ) ;
if ( F_396 ( V_17 , V_7 -> V_8 . V_17 ) )
return F_28 ( - V_392 ) ;
V_7 = F_96 ( V_23 ) ;
if ( V_7 == NULL )
return F_28 ( - V_56 ) ;
V_28 = F_397 ( & V_23 -> V_160 , & V_7 -> V_8 , V_17 ) ;
if ( V_28 )
goto V_415;
V_413 = V_416 | V_417 ;
if ( F_398 ( V_23 ) || F_399 ( V_23 ) ) {
V_413 &= ~ V_418 ;
V_413 |= V_287 ;
}
V_46 = V_7 -> V_8 . V_47 -> V_48 ;
F_400 ( V_46 , V_413 ) ;
F_390 ( V_7 , & V_419 ) ;
V_7 -> V_8 . V_9 = V_10 ;
V_7 -> V_8 . V_73 = V_10 ;
if ( F_2 ( V_23 ) ) {
V_7 -> V_11 = V_374 ;
} else
V_7 -> V_11 = V_5 ;
F_401 ( V_7 ) ;
return V_7 ;
V_415:
F_98 ( V_7 ) ;
return F_28 ( V_28 ) ;
}
static bool F_402 ( struct V_6 * V_7 )
{
if ( V_7 -> V_18 . V_69 != V_75 )
return false ;
if ( V_7 -> V_8 . V_47 == NULL )
return true ;
return F_403 ( & V_7 -> V_8 . V_47 -> V_420 ) == 1 ;
}
static void F_404 ( struct V_22 * V_93 ,
struct V_421 * V_422 )
{
struct V_6 * V_7 , * V_246 ;
F_21 ( & V_93 -> V_160 . V_33 ) ;
F_144 ( V_93 ) ;
F_405 (obj, freed, freed) {
struct V_38 * V_39 , * V_355 ;
F_406 ( V_7 ) ;
F_46 ( F_336 ( V_7 ) ) ;
F_207 (vma, vn,
&obj->vma_list, obj_link) {
F_46 ( ! F_169 ( V_39 ) ) ;
F_46 ( F_170 ( V_39 ) ) ;
V_39 -> V_85 &= ~ V_423 ;
F_335 ( V_39 ) ;
}
F_46 ( ! F_198 ( & V_7 -> V_81 ) ) ;
F_46 ( ! F_407 ( & V_7 -> V_424 ) ) ;
F_408 ( & V_7 -> V_198 ) ;
}
F_152 ( V_93 ) ;
F_24 ( & V_93 -> V_160 . V_33 ) ;
F_409 (obj, on, freed, freed) {
F_46 ( V_7 -> V_195 ) ;
F_46 ( F_233 ( & V_7 -> V_425 ) ) ;
if ( V_7 -> V_117 -> V_426 )
V_7 -> V_117 -> V_426 ( V_7 ) ;
if ( F_26 ( F_231 ( V_7 ) ) )
F_410 ( & V_7 -> V_18 . V_264 , 0 ) ;
F_89 ( V_7 , V_120 ) ;
F_46 ( V_7 -> V_18 . V_67 ) ;
if ( V_7 -> V_8 . V_427 )
F_411 ( & V_7 -> V_8 , NULL ) ;
F_412 ( & V_7 -> V_411 ) ;
F_413 ( & V_7 -> V_8 ) ;
F_12 ( V_93 , V_7 -> V_8 . V_17 ) ;
F_41 ( V_7 -> V_428 ) ;
F_98 ( V_7 ) ;
}
}
static void F_110 ( struct V_22 * V_93 )
{
struct V_421 * V_422 ;
V_422 = F_414 ( & V_93 -> V_18 . V_429 ) ;
if ( F_123 ( V_422 ) )
F_404 ( V_93 , V_422 ) ;
}
static void F_415 ( struct V_345 * V_346 )
{
struct V_22 * V_93 =
F_320 ( V_346 , struct V_22 , V_18 . V_430 ) ;
struct V_421 * V_422 ;
while ( ( V_422 = F_414 ( & V_93 -> V_18 . V_429 ) ) )
F_404 ( V_93 , V_422 ) ;
}
static void F_416 ( struct V_431 * V_327 )
{
struct V_6 * V_7 =
F_320 ( V_327 , F_321 ( * V_7 ) , V_432 ) ;
struct V_22 * V_93 = F_3 ( V_7 -> V_8 . V_2 ) ;
if ( F_417 ( & V_7 -> V_422 , & V_93 -> V_18 . V_429 ) )
F_418 ( & V_93 -> V_18 . V_430 ) ;
}
void F_419 ( struct V_353 * V_433 )
{
struct V_6 * V_7 = F_194 ( V_433 ) ;
if ( V_7 -> V_18 . V_294 )
F_388 ( V_7 ) ;
if ( F_402 ( V_7 ) )
V_7 -> V_18 . V_69 = V_71 ;
F_420 ( & V_7 -> V_432 , F_416 ) ;
}
void F_421 ( struct V_6 * V_7 )
{
F_56 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
F_46 ( F_337 ( V_7 ) ) ;
if ( F_336 ( V_7 ) )
F_338 ( V_7 ) ;
else
F_105 ( V_7 ) ;
}
static void F_422 ( struct V_22 * V_23 )
{
struct V_105 * V_96 ;
enum V_323 V_324 ;
F_288 (engine, dev_priv, id)
F_46 ( V_96 -> V_434 &&
! F_423 ( V_96 -> V_434 ) ) ;
}
int F_424 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = & V_23 -> V_160 ;
int V_28 ;
F_425 ( V_23 ) ;
F_21 ( & V_2 -> V_33 ) ;
V_28 = F_426 ( V_23 ) ;
if ( V_28 )
goto V_183;
V_28 = F_211 ( V_23 ,
V_77 |
V_78 ) ;
if ( V_28 )
goto V_183;
F_58 ( V_23 ) ;
F_46 ( V_23 -> V_251 . V_349 ) ;
F_422 ( V_23 ) ;
F_317 ( V_23 ) ;
F_24 ( & V_2 -> V_33 ) ;
F_427 ( V_23 ) ;
F_329 ( & V_23 -> V_32 . V_350 ) ;
F_329 ( & V_23 -> V_251 . V_252 ) ;
while ( F_213 ( & V_23 -> V_251 . V_344 ) )
;
F_212 ( V_23 ) ;
F_26 ( V_23 -> V_251 . V_335 ) ;
F_26 ( ! F_328 ( V_23 ) ) ;
if ( F_428 ( V_23 ) ) {
int V_435 = F_429 ( V_23 , V_436 ) ;
F_26 ( V_435 && V_435 != - V_142 ) ;
}
return 0 ;
V_183:
F_24 ( & V_2 -> V_33 ) ;
return V_28 ;
}
void F_430 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = & V_23 -> V_160 ;
F_26 ( V_23 -> V_251 . V_335 ) ;
F_21 ( & V_2 -> V_33 ) ;
F_431 ( V_23 ) ;
V_23 -> V_251 . V_437 ( V_23 ) ;
F_24 ( & V_2 -> V_33 ) ;
}
void F_432 ( struct V_22 * V_23 )
{
if ( F_70 ( V_23 ) < 5 ||
V_23 -> V_18 . V_438 == V_439 )
return;
F_433 ( V_440 , F_434 ( V_440 ) |
V_441 ) ;
if ( F_435 ( V_23 ) )
return;
F_433 ( V_442 , F_434 ( V_442 ) | V_443 ) ;
if ( F_436 ( V_23 ) )
F_433 ( V_444 , F_437 ( V_445 ) ) ;
else if ( F_438 ( V_23 ) )
F_433 ( V_444 , F_437 ( V_446 ) ) ;
else if ( F_439 ( V_23 ) )
F_433 ( V_447 , F_437 ( V_448 ) ) ;
else
F_440 () ;
}
static void F_441 ( struct V_22 * V_23 , T_1 V_8 )
{
F_433 ( F_442 ( V_8 ) , 0 ) ;
F_433 ( F_443 ( V_8 ) , 0 ) ;
F_433 ( F_444 ( V_8 ) , 0 ) ;
F_433 ( F_445 ( V_8 ) , 0 ) ;
}
static void F_446 ( struct V_22 * V_23 )
{
if ( F_447 ( V_23 ) ) {
F_441 ( V_23 , V_449 ) ;
F_441 ( V_23 , V_450 ) ;
F_441 ( V_23 , V_451 ) ;
F_441 ( V_23 , V_452 ) ;
F_441 ( V_23 , V_453 ) ;
} else if ( F_448 ( V_23 ) ) {
F_441 ( V_23 , V_450 ) ;
F_441 ( V_23 , V_451 ) ;
} else if ( F_449 ( V_23 ) ) {
F_441 ( V_23 , V_449 ) ;
F_441 ( V_23 , V_454 ) ;
}
}
int
F_450 ( struct V_22 * V_23 )
{
struct V_105 * V_96 ;
enum V_323 V_324 ;
int V_28 ;
V_23 -> V_251 . V_455 = F_343 () ;
F_451 ( V_23 , V_456 ) ;
if ( F_452 ( V_23 ) && F_70 ( V_23 ) < 9 )
F_433 ( V_457 , F_434 ( V_457 ) | F_453 ( 0xf ) ) ;
if ( F_454 ( V_23 ) )
F_433 ( V_458 , F_455 ( V_23 ) ?
V_459 : V_460 ) ;
if ( F_456 ( V_23 ) ) {
if ( F_457 ( V_23 ) ) {
T_1 V_461 = F_434 ( V_462 ) ;
V_461 &= ~ ( V_463 | V_464 ) ;
F_433 ( V_462 , V_461 ) ;
} else if ( F_70 ( V_23 ) >= 7 ) {
T_1 V_461 = F_434 ( V_465 ) ;
V_461 &= ~ V_466 ;
F_433 ( V_465 , V_461 ) ;
}
}
F_432 ( V_23 ) ;
F_446 ( V_23 ) ;
F_458 ( ! V_23 -> V_467 ) ;
V_28 = F_459 ( V_23 ) ;
if ( V_28 ) {
F_17 ( L_14 , V_28 ) ;
goto V_92;
}
F_288 (engine, dev_priv, id) {
V_28 = V_96 -> V_468 ( V_96 ) ;
if ( V_28 )
goto V_92;
}
F_460 ( V_23 ) ;
V_28 = F_461 ( V_23 ) ;
if ( V_28 )
goto V_92;
V_92:
F_462 ( V_23 , V_456 ) ;
return V_28 ;
}
bool F_463 ( struct V_22 * V_23 , int V_469 )
{
if ( F_464 ( V_23 ) -> V_470 < 6 )
return false ;
if ( V_93 . V_337 )
return false ;
if ( V_469 >= 0 )
return V_469 ;
#ifdef F_465
if ( F_464 ( V_23 ) -> V_470 == 6 && V_471 )
return false ;
#endif
return true ;
}
int F_466 ( struct V_22 * V_23 )
{
int V_28 ;
F_21 ( & V_23 -> V_160 . V_33 ) ;
if ( ! V_93 . V_337 ) {
V_23 -> V_251 . V_437 = V_472 ;
V_23 -> V_251 . V_473 = V_474 ;
} else {
V_23 -> V_251 . V_437 = V_475 ;
V_23 -> V_251 . V_473 = V_476 ;
}
F_451 ( V_23 , V_456 ) ;
F_467 ( V_23 ) ;
V_28 = F_468 ( V_23 ) ;
if ( V_28 )
goto V_164;
V_28 = F_469 ( V_23 ) ;
if ( V_28 )
goto V_164;
V_28 = F_470 ( V_23 ) ;
if ( V_28 )
goto V_164;
V_28 = F_450 ( V_23 ) ;
if ( V_28 == - V_31 ) {
F_17 ( L_15 ) ;
F_314 ( V_23 ) ;
V_28 = 0 ;
}
V_164:
F_462 ( V_23 , V_456 ) ;
F_24 ( & V_23 -> V_160 . V_33 ) ;
return V_28 ;
}
void
F_471 ( struct V_22 * V_23 )
{
struct V_105 * V_96 ;
enum V_323 V_324 ;
F_288 (engine, dev_priv, id)
V_23 -> V_251 . V_473 ( V_96 ) ;
}
void
F_472 ( struct V_22 * V_23 )
{
int V_54 ;
if ( F_464 ( V_23 ) -> V_470 >= 7 && ! F_473 ( V_23 ) &&
! F_474 ( V_23 ) )
V_23 -> V_247 = 32 ;
else if ( F_464 ( V_23 ) -> V_470 >= 4 ||
F_475 ( V_23 ) || F_476 ( V_23 ) ||
F_477 ( V_23 ) || F_478 ( V_23 ) )
V_23 -> V_247 = 16 ;
else
V_23 -> V_247 = 8 ;
if ( F_479 ( V_23 ) )
V_23 -> V_247 =
F_434 ( F_480 ( V_477 . V_478 ) ) ;
for ( V_54 = 0 ; V_54 < V_23 -> V_247 ; V_54 ++ ) {
struct V_248 * V_84 = & V_23 -> V_250 [ V_54 ] ;
V_84 -> V_93 = V_23 ;
V_84 -> V_324 = V_54 ;
F_481 ( & V_84 -> V_98 , & V_23 -> V_18 . V_479 ) ;
}
F_302 ( V_23 ) ;
F_482 ( V_23 ) ;
}
int
F_483 ( struct V_22 * V_23 )
{
int V_183 = - V_56 ;
V_23 -> V_126 = F_484 ( V_6 , V_480 ) ;
if ( ! V_23 -> V_126 )
goto V_481;
V_23 -> V_482 = F_484 ( V_38 , V_480 ) ;
if ( ! V_23 -> V_482 )
goto V_483;
V_23 -> V_484 = F_484 ( V_89 ,
V_480 |
V_485 |
V_486 ) ;
if ( ! V_23 -> V_484 )
goto V_487;
V_23 -> V_488 = F_484 ( V_489 ,
V_480 |
V_485 ) ;
if ( ! V_23 -> V_488 )
goto V_490;
F_21 ( & V_23 -> V_160 . V_33 ) ;
F_392 ( & V_23 -> V_251 . V_491 ) ;
V_183 = F_485 ( V_23 ) ;
F_24 ( & V_23 -> V_160 . V_33 ) ;
if ( V_183 )
goto V_492;
F_392 ( & V_23 -> V_493 ) ;
F_486 ( & V_23 -> V_18 . V_430 , F_415 ) ;
F_487 ( & V_23 -> V_18 . V_429 ) ;
F_392 ( & V_23 -> V_18 . V_197 ) ;
F_392 ( & V_23 -> V_18 . V_196 ) ;
F_392 ( & V_23 -> V_18 . V_479 ) ;
F_392 ( & V_23 -> V_18 . V_234 ) ;
F_488 ( & V_23 -> V_251 . V_252 ,
F_319 ) ;
F_488 ( & V_23 -> V_251 . V_344 ,
F_326 ) ;
F_489 ( & V_23 -> V_32 . V_494 ) ;
F_489 ( & V_23 -> V_32 . V_29 ) ;
F_489 ( & V_23 -> V_495 ) ;
V_23 -> V_18 . V_496 = true ;
F_410 ( & V_23 -> V_18 . V_497 , 0 ) ;
F_490 ( & V_23 -> V_498 . V_254 ) ;
return 0 ;
V_492:
F_491 ( V_23 -> V_488 ) ;
V_490:
F_491 ( V_23 -> V_484 ) ;
V_487:
F_491 ( V_23 -> V_482 ) ;
V_483:
F_491 ( V_23 -> V_126 ) ;
V_481:
return V_183 ;
}
void F_492 ( struct V_22 * V_23 )
{
F_26 ( ! F_493 ( & V_23 -> V_18 . V_429 ) ) ;
F_21 ( & V_23 -> V_160 . V_33 ) ;
F_494 ( & V_23 -> V_251 . V_363 ) ;
F_26 ( ! F_198 ( & V_23 -> V_251 . V_491 ) ) ;
F_24 ( & V_23 -> V_160 . V_33 ) ;
F_491 ( V_23 -> V_488 ) ;
F_491 ( V_23 -> V_484 ) ;
F_491 ( V_23 -> V_482 ) ;
F_491 ( V_23 -> V_126 ) ;
F_495 () ;
}
int F_496 ( struct V_22 * V_23 )
{
F_144 ( V_23 ) ;
F_21 ( & V_23 -> V_160 . V_33 ) ;
F_497 ( V_23 ) ;
F_24 ( & V_23 -> V_160 . V_33 ) ;
F_152 ( V_23 ) ;
return 0 ;
}
int F_498 ( struct V_22 * V_23 )
{
struct V_6 * V_7 ;
struct V_190 * V_499 [] = {
& V_23 -> V_18 . V_197 ,
& V_23 -> V_18 . V_196 ,
NULL
} , * * V_500 ;
F_21 ( & V_23 -> V_160 . V_33 ) ;
F_248 ( V_23 , - 1UL , V_284 ) ;
for ( V_500 = V_499 ; * V_500 ; V_500 ++ ) {
F_22 (obj, *p, global_link) {
V_7 -> V_8 . V_73 = V_10 ;
V_7 -> V_8 . V_9 = V_10 ;
}
}
F_24 ( & V_23 -> V_160 . V_33 ) ;
return 0 ;
}
void F_499 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_113 * V_316 = V_36 -> V_115 ;
struct V_89 * V_319 ;
F_10 ( & V_316 -> V_18 . V_254 ) ;
F_22 (request, &file_priv->mm.request_list, client_list)
V_319 -> V_316 = NULL ;
F_11 ( & V_316 -> V_18 . V_254 ) ;
if ( ! F_198 ( & V_316 -> V_88 . V_98 ) ) {
F_10 ( & F_3 ( V_2 ) -> V_88 . V_97 ) ;
F_408 ( & V_316 -> V_88 . V_98 ) ;
F_11 ( & F_3 ( V_2 ) -> V_88 . V_97 ) ;
}
}
int F_500 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_113 * V_316 ;
int V_28 ;
F_257 ( L_16 ) ;
V_316 = F_501 ( sizeof( * V_316 ) , V_61 ) ;
if ( ! V_316 )
return - V_56 ;
V_36 -> V_115 = V_316 ;
V_316 -> V_23 = F_3 ( V_2 ) ;
V_316 -> V_36 = V_36 ;
F_392 ( & V_316 -> V_88 . V_98 ) ;
F_490 ( & V_316 -> V_18 . V_254 ) ;
F_392 ( & V_316 -> V_18 . V_501 ) ;
V_316 -> V_502 = - 1 ;
V_28 = F_502 ( V_2 , V_36 ) ;
if ( V_28 )
F_41 ( V_316 ) ;
return V_28 ;
}
void F_503 ( struct V_6 * V_503 ,
struct V_6 * V_504 ,
unsigned V_425 )
{
F_64 ( V_505 * V_506 >
sizeof( V_507 ) * V_508 ) ;
if ( V_503 ) {
F_26 ( ! ( F_233 ( & V_503 -> V_425 ) & V_425 ) ) ;
F_504 ( V_425 , & V_503 -> V_425 ) ;
}
if ( V_504 ) {
F_26 ( F_233 ( & V_504 -> V_425 ) & V_425 ) ;
F_505 ( V_425 , & V_504 -> V_425 ) ;
}
}
struct V_6 *
F_506 ( struct V_22 * V_23 ,
const void * V_34 , T_3 V_17 )
{
struct V_6 * V_7 ;
struct V_44 * V_52 ;
T_3 V_509 ;
int V_28 ;
V_7 = F_102 ( V_23 , F_125 ( V_17 , V_57 ) ) ;
if ( F_32 ( V_7 ) )
return V_7 ;
V_28 = F_120 ( V_7 , true ) ;
if ( V_28 )
goto V_415;
V_28 = F_90 ( V_7 ) ;
if ( V_28 )
goto V_415;
V_52 = V_7 -> V_18 . V_67 ;
V_509 = F_507 ( V_52 -> V_62 , V_52 -> V_271 , ( void * ) V_34 , V_17 ) ;
V_7 -> V_18 . V_72 = true ;
F_53 ( V_7 ) ;
if ( F_26 ( V_509 != V_17 ) ) {
F_17 ( L_17 , V_509 , V_17 ) ;
V_28 = - V_119 ;
goto V_415;
}
return V_7 ;
V_415:
F_105 ( V_7 ) ;
return F_28 ( V_28 ) ;
}
struct V_51 *
F_508 ( struct V_6 * V_7 ,
unsigned int V_510 ,
unsigned int * V_63 )
{
struct V_511 * V_257 = & V_7 -> V_18 . V_259 ;
struct V_51 * V_52 ;
unsigned int V_155 , V_103 ;
F_14 () ;
F_46 ( V_510 >= V_7 -> V_8 . V_17 >> V_156 ) ;
F_46 ( ! F_231 ( V_7 ) ) ;
if ( V_510 < F_174 ( V_257 -> V_291 ) )
goto V_512;
F_21 ( & V_257 -> V_254 ) ;
V_52 = V_257 -> V_290 ;
V_155 = V_257 -> V_291 ;
V_103 = F_509 ( V_52 ) ;
while ( V_155 + V_103 <= V_510 ) {
unsigned long V_513 , V_54 ;
int V_28 ;
V_28 = F_510 ( & V_257 -> V_260 , V_155 , V_52 ) ;
if ( V_28 && V_28 != - V_514 )
goto V_515;
V_513 =
V_516 |
V_155 << V_517 ;
for ( V_54 = 1 ; V_54 < V_103 ; V_54 ++ ) {
V_28 = F_510 ( & V_257 -> V_260 , V_155 + V_54 ,
( void * ) V_513 ) ;
if ( V_28 && V_28 != - V_514 )
goto V_515;
}
V_155 += V_103 ;
V_52 = F_511 ( V_52 ) ;
V_103 = F_509 ( V_52 ) ;
}
V_515:
V_257 -> V_290 = V_52 ;
V_257 -> V_291 = V_155 ;
F_24 ( & V_257 -> V_254 ) ;
if ( F_123 ( V_510 < V_155 ) )
goto V_512;
while ( V_155 + V_103 <= V_510 ) {
V_155 += V_103 ;
V_52 = F_511 ( V_52 ) ;
V_103 = F_509 ( V_52 ) ;
}
* V_63 = V_510 - V_155 ;
return V_52 ;
V_512:
F_359 () ;
V_52 = F_512 ( & V_257 -> V_260 , V_510 ) ;
F_46 ( ! V_52 ) ;
* V_63 = 0 ;
if ( F_123 ( F_513 ( V_52 ) ) ) {
unsigned long V_8 =
( unsigned long ) V_52 >> V_517 ;
V_52 = F_512 ( & V_257 -> V_260 , V_8 ) ;
F_46 ( ! V_52 ) ;
* V_63 = V_510 - V_8 ;
}
F_361 () ;
return V_52 ;
}
struct V_58 *
F_134 ( struct V_6 * V_7 , unsigned int V_510 )
{
struct V_51 * V_52 ;
unsigned int V_63 ;
F_46 ( ! F_117 ( V_7 ) ) ;
V_52 = F_508 ( V_7 , V_510 , & V_63 ) ;
return F_514 ( F_242 ( V_52 ) , V_63 ) ;
}
struct V_58 *
F_515 ( struct V_6 * V_7 ,
unsigned int V_510 )
{
struct V_58 * V_58 ;
V_58 = F_134 ( V_7 , V_510 ) ;
if ( ! V_7 -> V_18 . V_72 )
F_49 ( V_58 ) ;
return V_58 ;
}
T_15
F_151 ( struct V_6 * V_7 ,
unsigned long V_510 )
{
struct V_51 * V_52 ;
unsigned int V_63 ;
V_52 = F_508 ( V_7 , V_510 , & V_63 ) ;
return F_42 ( V_52 ) + ( V_63 << V_156 ) ;
}

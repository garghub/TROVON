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
V_17 , 0 , - 1 ,
0 , V_14 -> V_19 ,
V_20 ,
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
if ( V_86 <= 0 )
break;
F_78 ( V_102 [ V_54 ] ) ;
}
for (; V_54 < V_103 ; V_54 ++ )
F_78 ( V_102 [ V_54 ] ) ;
F_41 ( V_102 ) ;
} else {
V_101 = F_79 ( V_100 ) ;
}
if ( V_101 && V_86 > 0 )
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
void * F_96 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
return F_97 ( V_23 -> V_126 , V_61 ) ;
}
void F_98 ( struct V_6 * V_7 )
{
struct V_22 * V_23 = F_3 ( V_7 -> V_8 . V_2 ) ;
F_99 ( V_23 -> V_126 , V_7 ) ;
}
static int
F_100 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
T_6 V_17 ,
T_7 * V_127 )
{
struct V_6 * V_7 ;
int V_28 ;
T_1 V_128 ;
V_17 = F_101 ( V_17 , V_57 ) ;
if ( V_17 == 0 )
return - V_55 ;
V_7 = F_102 ( V_2 , V_17 ) ;
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
return F_100 ( V_36 , V_2 ,
args -> V_17 , & args -> V_128 ) ;
}
int
F_109 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_134 * args = V_34 ;
F_110 ( F_3 ( V_2 ) ) ;
return F_100 ( V_36 , V_2 ,
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
if ( args -> V_63 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_63 ) {
V_28 = - V_55 ;
goto V_92;
}
F_156 ( V_7 , args -> V_63 , args -> V_17 ) ;
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
F_157 ( struct V_157 * V_46 ,
T_8 V_8 , int V_63 ,
char T_5 * V_123 , int V_64 )
{
void * V_53 ;
unsigned long V_158 ;
V_53 = ( void V_159 * ) F_138 ( V_46 , V_8 ) ;
V_158 = F_158 ( V_53 + V_63 ,
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
F_159 ( struct V_6 * V_7 ,
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
if ( F_157 ( & V_14 -> V_171 , V_166 , V_167 ,
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
F_160 ( struct V_58 * V_58 , int V_63 , int V_64 ,
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
F_161 ( struct V_58 * V_58 , int V_63 , int V_177 , char T_5 * V_123 ,
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
V_28 = F_162 ( V_53 + V_63 , V_123 , V_177 ) ;
if ( V_176 )
F_35 ( V_53 + V_63 , V_177 ) ;
F_36 ( V_53 ) ;
}
if ( V_28 == 0 )
return V_28 ;
return F_160 ( V_58 , V_63 , V_177 , V_123 ,
V_151 ,
V_175 ,
V_176 ) ;
}
static int
F_163 ( struct V_6 * V_7 ,
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
V_28 = F_161 ( V_58 , V_63 , V_64 , V_123 ,
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
F_164 ( struct V_1 * V_2 , void * V_34 ,
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
if ( args -> V_63 > V_7 -> V_8 . V_17 ||
args -> V_17 > V_7 -> V_8 . V_17 - args -> V_63 ) {
V_28 = - V_55 ;
goto V_183;
}
F_165 ( V_7 , args -> V_63 , args -> V_17 ) ;
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
V_28 = F_159 ( V_7 , args ) ;
if ( V_28 == - V_119 || V_28 == - V_184 ) {
if ( V_7 -> V_66 )
V_28 = F_91 ( V_7 , args , V_36 ) ;
else
V_28 = F_163 ( V_7 , args ) ;
}
F_53 ( V_7 ) ;
V_183:
F_105 ( V_7 ) ;
return V_28 ;
}
static inline enum V_185
F_166 ( struct V_6 * V_7 , unsigned V_186 )
{
return ( V_186 == V_187 ?
V_7 -> V_188 : V_125 ) ;
}
static void F_167 ( struct V_6 * V_7 )
{
struct V_22 * V_93 ;
struct V_189 * V_190 ;
struct V_38 * V_39 ;
F_22 (vma, &obj->vma_list, obj_link) {
if ( ! F_168 ( V_39 ) )
continue;
if ( F_169 ( V_39 ) )
continue;
if ( ! F_170 ( & V_39 -> V_16 ) )
continue;
F_60 ( & V_39 -> V_191 , & V_39 -> V_192 -> V_193 ) ;
}
V_93 = F_3 ( V_7 -> V_8 . V_2 ) ;
V_190 = V_7 -> V_194 ? & V_93 -> V_18 . V_195 : & V_93 -> V_18 . V_196 ;
F_60 ( & V_7 -> V_197 , V_190 ) ;
}
int
F_171 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_198 * args = V_34 ;
struct V_6 * V_7 ;
T_7 V_73 = args -> V_73 ;
T_7 V_9 = args -> V_9 ;
int V_183 ;
if ( ( V_9 | V_73 ) & V_199 )
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
if ( V_73 & V_187 )
V_183 = F_149 ( V_7 , V_9 != 0 ) ;
else
V_183 = F_120 ( V_7 , V_9 != 0 ) ;
F_167 ( V_7 ) ;
F_24 ( & V_2 -> V_33 ) ;
if ( V_9 != 0 )
F_93 ( V_7 , F_166 ( V_7 , V_9 ) ) ;
V_165:
F_53 ( V_7 ) ;
V_92:
F_105 ( V_7 ) ;
return V_183 ;
}
int
F_172 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_200 * args = V_34 ;
struct V_6 * V_7 ;
int V_183 = 0 ;
V_7 = F_155 ( V_36 , args -> V_128 ) ;
if ( ! V_7 )
return - V_174 ;
if ( F_173 ( V_7 -> V_12 ) ) {
V_183 = F_18 ( V_2 ) ;
if ( ! V_183 ) {
F_174 ( V_7 ) ;
F_24 ( & V_2 -> V_33 ) ;
}
}
F_105 ( V_7 ) ;
return V_183 ;
}
int
F_175 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_201 * args = V_34 ;
struct V_6 * V_7 ;
unsigned long V_147 ;
if ( args -> V_85 & ~ ( V_202 ) )
return - V_55 ;
if ( args -> V_85 & V_202 && ! F_176 ( V_203 ) )
return - V_142 ;
V_7 = F_155 ( V_36 , args -> V_128 ) ;
if ( ! V_7 )
return - V_174 ;
if ( ! V_7 -> V_8 . V_47 ) {
F_105 ( V_7 ) ;
return - V_55 ;
}
V_147 = F_177 ( V_7 -> V_8 . V_47 , 0 , args -> V_17 ,
V_204 | V_205 , V_206 ,
args -> V_63 ) ;
if ( args -> V_85 & V_202 ) {
struct V_207 * V_18 = V_208 -> V_18 ;
struct V_209 * V_39 ;
if ( F_178 ( & V_18 -> V_210 ) ) {
F_105 ( V_7 ) ;
return - V_211 ;
}
V_39 = F_179 ( V_18 , V_147 ) ;
if ( V_39 )
V_39 -> V_212 =
F_180 ( F_181 ( V_39 -> V_213 ) ) ;
else
V_147 = - V_56 ;
F_182 ( & V_18 -> V_210 ) ;
F_183 ( V_7 -> V_188 , V_125 ) ;
}
F_105 ( V_7 ) ;
if ( F_32 ( ( void * ) V_147 ) )
return V_147 ;
args -> V_214 = ( T_6 ) V_147 ;
return 0 ;
}
static unsigned int F_184 ( struct V_6 * V_7 )
{
T_2 V_17 ;
V_17 = F_185 ( V_7 ) ;
V_17 *= F_186 ( V_7 ) == V_215 ? 32 : 8 ;
return V_17 >> V_156 ;
}
int F_187 ( void )
{
return 1 ;
}
int F_188 ( struct V_209 * V_216 , struct V_217 * V_218 )
{
#define F_189 ((1 << 20) >> PAGE_SHIFT)
struct V_6 * V_7 = F_190 ( V_216 -> V_219 ) ;
struct V_1 * V_2 = V_7 -> V_8 . V_2 ;
struct V_22 * V_23 = F_3 ( V_2 ) ;
struct V_13 * V_14 = & V_23 -> V_14 ;
bool V_220 = ! ! ( V_218 -> V_85 & V_221 ) ;
struct V_38 * V_39 ;
T_9 V_167 ;
unsigned int V_85 ;
int V_28 ;
V_167 = ( V_218 -> V_222 - V_216 -> V_223 ) >> V_156 ;
F_191 ( V_7 , V_167 , true , V_220 ) ;
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
goto V_224;
if ( V_7 -> V_11 != V_5 && ! F_2 ( V_23 ) ) {
V_28 = - V_119 ;
goto V_225;
}
V_85 = V_161 ;
if ( V_7 -> V_8 . V_17 > 2 * F_189 << V_156 )
V_85 |= V_162 | V_226 ;
V_39 = F_145 ( V_7 , NULL , 0 , 0 , V_85 ) ;
if ( F_32 ( V_39 ) ) {
struct V_227 V_228 ;
unsigned int V_229 ;
V_229 = F_189 ;
if ( F_192 ( V_7 ) )
V_229 = F_101 ( V_229 , F_184 ( V_7 ) ) ;
memset ( & V_228 , 0 , sizeof( V_228 ) ) ;
V_228 . type = V_230 ;
V_228 . V_231 . V_232 . V_63 = F_193 ( V_167 , V_229 ) ;
V_228 . V_231 . V_232 . V_17 =
F_194 (unsigned int, chunk_size,
vma_pages(area) - view.params.partial.offset) ;
if ( V_229 >= V_7 -> V_8 . V_17 >> V_156 )
V_228 . type = V_233 ;
V_7 -> V_188 = V_125 ;
V_39 = F_145 ( V_7 , & V_228 , 0 , 0 , V_161 ) ;
}
if ( F_32 ( V_39 ) ) {
V_28 = F_103 ( V_39 ) ;
goto V_225;
}
V_28 = F_149 ( V_7 , V_220 ) ;
if ( V_28 )
goto V_144;
V_28 = F_195 ( V_39 ) ;
if ( V_28 )
goto V_144;
F_196 ( V_23 ) ;
if ( F_197 ( & V_7 -> V_234 ) )
F_198 ( & V_7 -> V_234 , & V_23 -> V_18 . V_235 ) ;
V_28 = F_199 ( V_216 ,
V_216 -> V_223 + ( V_39 -> V_236 . V_231 . V_232 . V_63 << V_156 ) ,
( V_14 -> V_237 + V_39 -> V_16 . V_149 ) >> V_156 ,
F_194 ( T_2 , V_39 -> V_17 , V_216 -> V_238 - V_216 -> V_223 ) ,
& V_14 -> V_171 ) ;
V_144:
F_200 ( V_39 ) ;
V_225:
F_24 ( & V_2 -> V_33 ) ;
V_224:
F_152 ( V_23 ) ;
F_53 ( V_7 ) ;
V_183:
switch ( V_28 ) {
case - V_31 :
if ( ! F_201 ( & V_23 -> V_32 ) ) {
V_28 = V_239 ;
break;
}
case - V_240 :
case 0 :
case - V_241 :
case - V_211 :
case - V_121 :
V_28 = V_242 ;
break;
case - V_56 :
V_28 = V_243 ;
break;
case - V_184 :
case - V_119 :
V_28 = V_239 ;
break;
default:
F_202 ( V_28 , L_2 , V_28 ) ;
V_28 = V_239 ;
break;
}
return V_28 ;
}
void
F_203 ( struct V_6 * V_7 )
{
struct V_22 * V_93 = F_3 ( V_7 -> V_8 . V_2 ) ;
F_56 ( & V_93 -> V_160 . V_33 ) ;
F_144 ( V_93 ) ;
if ( F_197 ( & V_7 -> V_234 ) )
goto V_92;
F_75 ( & V_7 -> V_234 ) ;
F_204 ( & V_7 -> V_8 . V_244 ,
V_7 -> V_8 . V_2 -> V_245 -> V_246 ) ;
F_150 () ;
V_92:
F_152 ( V_93 ) ;
}
void F_205 ( struct V_22 * V_23 )
{
struct V_6 * V_7 , * V_247 ;
int V_54 ;
F_206 (obj, on,
&dev_priv->mm.userfault_list, userfault_link) {
F_75 ( & V_7 -> V_234 ) ;
F_204 ( & V_7 -> V_8 . V_244 ,
V_7 -> V_8 . V_2 -> V_245 -> V_246 ) ;
}
for ( V_54 = 0 ; V_54 < V_23 -> V_248 ; V_54 ++ ) {
struct V_249 * V_250 = & V_23 -> V_251 [ V_54 ] ;
if ( ! V_250 -> V_39 )
continue;
F_46 ( ! F_197 ( & V_250 -> V_39 -> V_7 -> V_234 ) ) ;
V_250 -> V_72 = true ;
}
}
T_2 F_207 ( struct V_22 * V_23 ,
T_2 V_17 , int V_252 )
{
T_2 V_253 ;
F_46 ( V_17 == 0 ) ;
if ( F_70 ( V_23 ) >= 4 ||
V_252 == V_254 )
return V_17 ;
if ( F_208 ( V_23 ) )
V_253 = 1024 * 1024 ;
else
V_253 = 512 * 1024 ;
while ( V_253 < V_17 )
V_253 <<= 1 ;
return V_253 ;
}
T_2 F_209 ( struct V_22 * V_23 , T_2 V_17 ,
int V_252 , bool V_255 )
{
F_46 ( V_17 == 0 ) ;
if ( F_70 ( V_23 ) >= 4 || ( ! V_255 && F_210 ( V_23 ) ) ||
V_252 == V_254 )
return 4096 ;
return F_207 ( V_23 , V_17 , V_252 ) ;
}
static int F_211 ( struct V_6 * V_7 )
{
struct V_22 * V_23 = F_3 ( V_7 -> V_8 . V_2 ) ;
int V_183 ;
V_183 = F_212 ( & V_7 -> V_8 ) ;
if ( ! V_183 )
return 0 ;
V_183 = F_213 ( V_23 , V_77 ) ;
if ( V_183 )
return V_183 ;
V_183 = F_18 ( & V_23 -> V_160 ) ;
if ( ! V_183 ) {
F_58 ( V_23 ) ;
V_183 = F_212 ( & V_7 -> V_8 ) ;
F_24 ( & V_23 -> V_160 . V_33 ) ;
}
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
V_28 = F_211 ( V_7 ) ;
if ( V_28 == 0 )
* V_63 = F_217 ( & V_7 -> V_8 . V_244 ) ;
F_105 ( V_7 ) ;
return V_28 ;
}
int
F_218 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_256 * args = V_34 ;
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
}
void F_222 ( struct V_6 * V_7 )
{
struct V_45 * V_46 ;
F_56 ( & V_7 -> V_18 . V_257 ) ;
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
struct V_258 V_258 ;
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
struct V_259 V_260 ;
void * * V_261 ;
F_229 (slot, &obj->mm.get_page.radix, &iter, 0 )
F_230 ( & V_7 -> V_18 . V_262 . V_263 , V_260 . V_264 ) ;
}
void F_89 ( struct V_6 * V_7 ,
enum V_265 V_266 )
{
struct V_44 * V_67 ;
if ( F_231 ( V_7 ) )
return;
F_46 ( V_7 -> V_194 ) ;
if ( ! F_173 ( V_7 -> V_18 . V_67 ) )
return;
F_232 ( & V_7 -> V_18 . V_257 , V_266 ) ;
if ( F_123 ( F_233 ( & V_7 -> V_18 . V_267 ) ) )
goto V_268;
V_67 = F_234 ( & V_7 -> V_18 . V_67 ) ;
F_46 ( ! V_67 ) ;
if ( V_7 -> V_18 . V_46 ) {
void * V_269 ;
V_269 = F_235 ( V_7 -> V_18 . V_46 ) ;
if ( F_236 ( V_269 ) )
F_237 ( V_269 ) ;
else
F_128 ( F_238 ( V_269 ) ) ;
V_7 -> V_18 . V_46 = NULL ;
}
F_228 ( V_7 ) ;
V_7 -> V_117 -> V_270 ( V_7 , V_67 ) ;
V_268:
F_24 ( & V_7 -> V_18 . V_257 ) ;
}
static void F_239 ( struct V_44 * V_271 )
{
struct V_44 V_272 ;
struct V_51 * V_52 , * V_273 ;
unsigned int V_54 ;
if ( V_271 -> V_274 == V_271 -> V_275 )
return;
if ( F_40 ( & V_272 , V_271 -> V_274 , V_61 | V_276 ) )
return;
V_273 = V_272 . V_62 ;
F_240 (orig_st->sgl, sg, orig_st->nents, i) {
F_241 ( V_273 , F_242 ( V_52 ) , V_52 -> V_64 , 0 ) ;
V_273 = F_243 ( V_273 ) ;
}
F_51 ( V_271 ) ;
* V_271 = V_272 ;
}
static struct V_44 *
F_244 ( struct V_6 * V_7 )
{
struct V_22 * V_23 = F_3 ( V_7 -> V_8 . V_2 ) ;
const unsigned long V_277 = V_7 -> V_8 . V_17 / V_57 ;
unsigned long V_54 ;
struct V_45 * V_46 ;
struct V_44 * V_50 ;
struct V_51 * V_52 ;
struct V_258 V_258 ;
struct V_58 * V_58 ;
unsigned long V_278 = 0 ;
unsigned int V_279 ;
int V_28 ;
T_10 V_280 ;
F_46 ( V_7 -> V_8 . V_73 & V_199 ) ;
F_46 ( V_7 -> V_8 . V_9 & V_199 ) ;
V_279 = F_245 () ;
if ( ! V_279 )
V_279 = F_193 ( V_281 , V_57 ) ;
V_50 = F_39 ( sizeof( * V_50 ) , V_61 ) ;
if ( V_50 == NULL )
return F_28 ( - V_56 ) ;
V_282:
if ( F_40 ( V_50 , V_277 , V_61 ) ) {
F_41 ( V_50 ) ;
return F_28 ( - V_56 ) ;
}
V_46 = V_7 -> V_8 . V_47 -> V_48 ;
V_280 = F_246 ( V_46 , ~ ( V_283 | V_284 ) ) ;
V_280 |= V_285 | V_276 ;
V_52 = V_50 -> V_62 ;
V_50 -> V_274 = 0 ;
for ( V_54 = 0 ; V_54 < V_277 ; V_54 ++ ) {
V_58 = F_247 ( V_46 , V_54 , V_280 ) ;
if ( F_32 ( V_58 ) ) {
F_248 ( V_23 ,
V_277 ,
V_286 |
V_287 |
V_288 ) ;
V_58 = F_247 ( V_46 , V_54 , V_280 ) ;
}
if ( F_32 ( V_58 ) ) {
V_58 = F_31 ( V_46 , V_54 ) ;
if ( F_32 ( V_58 ) ) {
V_28 = F_103 ( V_58 ) ;
goto V_289;
}
}
if ( ! V_54 ||
V_52 -> V_64 >= V_279 ||
F_249 ( V_58 ) != V_278 + 1 ) {
if ( V_54 )
V_52 = F_243 ( V_52 ) ;
V_50 -> V_274 ++ ;
F_241 ( V_52 , V_58 , V_57 , 0 ) ;
} else {
V_52 -> V_64 += V_57 ;
}
V_278 = F_249 ( V_58 ) ;
F_26 ( ( V_280 & V_290 ) && ( V_278 >= 0x00100000UL ) ) ;
}
if ( V_52 )
F_250 ( V_52 ) ;
F_239 ( V_50 ) ;
V_28 = F_251 ( V_7 , V_50 ) ;
if ( V_28 ) {
if ( V_279 > V_57 ) {
F_227 (page, sgt_iter, st)
F_37 ( V_58 ) ;
F_51 ( V_50 ) ;
V_279 = V_57 ;
goto V_282;
} else {
F_252 ( & V_23 -> V_160 . V_291 -> V_2 ,
L_3 ,
V_277 ) ;
goto V_292;
}
}
if ( F_27 ( V_7 ) )
F_253 ( V_7 , V_50 ) ;
return V_50 ;
V_289:
F_250 ( V_52 ) ;
V_292:
F_227 (page, sgt_iter, st)
F_37 ( V_58 ) ;
F_51 ( V_50 ) ;
F_41 ( V_50 ) ;
if ( V_28 == - V_184 )
V_28 = - V_56 ;
return F_28 ( V_28 ) ;
}
void F_254 ( struct V_6 * V_7 ,
struct V_44 * V_67 )
{
F_56 ( & V_7 -> V_18 . V_257 ) ;
V_7 -> V_18 . V_262 . V_293 = V_67 -> V_62 ;
V_7 -> V_18 . V_262 . V_294 = 0 ;
V_7 -> V_18 . V_67 = V_67 ;
if ( F_192 ( V_7 ) &&
F_3 ( V_7 -> V_8 . V_2 ) -> V_295 & V_296 ) {
F_46 ( V_7 -> V_18 . V_297 ) ;
F_255 ( V_7 ) ;
V_7 -> V_18 . V_297 = true ;
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
V_67 = V_7 -> V_117 -> V_298 ( V_7 ) ;
if ( F_123 ( F_32 ( V_67 ) ) )
return F_103 ( V_67 ) ;
F_254 ( V_7 , V_67 ) ;
return 0 ;
}
int F_258 ( struct V_6 * V_7 )
{
int V_183 ;
V_183 = F_19 ( & V_7 -> V_18 . V_257 ) ;
if ( V_183 )
return V_183 ;
if ( F_123 ( ! V_7 -> V_18 . V_67 ) ) {
V_183 = F_256 ( V_7 ) ;
if ( V_183 )
goto V_268;
F_259 () ;
}
F_260 ( & V_7 -> V_18 . V_267 ) ;
V_268:
F_24 ( & V_7 -> V_18 . V_257 ) ;
return V_183 ;
}
static void * F_261 ( const struct V_6 * V_7 ,
enum V_299 type )
{
unsigned long V_300 = V_7 -> V_8 . V_17 >> V_156 ;
struct V_44 * V_301 = V_7 -> V_18 . V_67 ;
struct V_258 V_258 ;
struct V_58 * V_58 ;
struct V_58 * V_302 [ 32 ] ;
struct V_58 * * V_67 = V_302 ;
unsigned long V_54 = 0 ;
T_11 V_303 ;
void * V_147 ;
if ( V_300 == 1 && type == V_304 )
return F_127 ( F_242 ( V_301 -> V_62 ) ) ;
if ( V_300 > F_262 ( V_302 ) ) {
V_67 = F_263 ( V_300 , sizeof( * V_67 ) , V_305 ) ;
if ( ! V_67 )
return NULL ;
}
F_227 (page, sgt_iter, sgt)
V_67 [ V_54 ++ ] = V_58 ;
F_46 ( V_54 != V_300 ) ;
switch ( type ) {
case V_304 :
V_303 = V_306 ;
break;
case V_307 :
V_303 = F_180 ( V_308 ) ;
break;
}
V_147 = F_264 ( V_67 , V_300 , 0 , V_303 ) ;
if ( V_67 != V_302 )
F_265 ( V_67 ) ;
return V_147 ;
}
void * F_266 ( struct V_6 * V_7 ,
enum V_299 type )
{
enum V_299 V_309 ;
bool V_40 ;
void * V_269 ;
int V_28 ;
F_46 ( ! F_117 ( V_7 ) ) ;
V_28 = F_19 ( & V_7 -> V_18 . V_257 ) ;
if ( V_28 )
return F_28 ( V_28 ) ;
V_40 = true ;
if ( ! F_267 ( & V_7 -> V_18 . V_267 ) ) {
if ( F_123 ( ! V_7 -> V_18 . V_67 ) ) {
V_28 = F_256 ( V_7 ) ;
if ( V_28 )
goto V_225;
F_259 () ;
}
F_260 ( & V_7 -> V_18 . V_267 ) ;
V_40 = false ;
}
F_46 ( ! V_7 -> V_18 . V_67 ) ;
V_269 = F_268 ( V_7 -> V_18 . V_46 , V_309 ) ;
if ( V_269 && V_309 != type ) {
if ( V_40 ) {
V_28 = - V_121 ;
goto V_144;
}
if ( F_236 ( V_269 ) )
F_237 ( V_269 ) ;
else
F_128 ( F_238 ( V_269 ) ) ;
V_269 = V_7 -> V_18 . V_46 = NULL ;
}
if ( ! V_269 ) {
V_269 = F_261 ( V_7 , type ) ;
if ( ! V_269 ) {
V_28 = - V_56 ;
goto V_144;
}
V_7 -> V_18 . V_46 = F_269 ( V_269 , type ) ;
}
V_164:
F_24 ( & V_7 -> V_18 . V_257 ) ;
return V_269 ;
V_144:
F_270 ( & V_7 -> V_18 . V_267 ) ;
V_225:
V_269 = F_28 ( V_28 ) ;
goto V_164;
}
static bool F_271 ( const struct V_310 * V_311 )
{
unsigned long V_312 ;
if ( V_311 -> V_313 . V_314 )
return true ;
V_312 = F_272 () - V_311 -> V_313 . V_315 ;
if ( V_311 -> V_313 . V_316 &&
V_312 <= V_311 -> V_313 . V_316 ) {
F_257 ( L_5 ) ;
return true ;
}
return false ;
}
static void F_273 ( struct V_310 * V_311 ,
const bool V_317 )
{
struct V_318 * V_319 = & V_311 -> V_313 ;
if ( V_317 ) {
V_319 -> V_314 = F_271 ( V_311 ) ;
V_319 -> V_320 ++ ;
V_319 -> V_315 = F_272 () ;
} else {
V_319 -> V_321 ++ ;
}
}
struct V_89 *
F_274 ( struct V_105 * V_96 )
{
struct V_89 * V_322 ;
F_22 (request, &engine->timeline->requests, link) {
if ( F_275 ( V_322 ) )
continue;
return V_322 ;
}
return NULL ;
}
static void F_276 ( struct V_89 * V_322 )
{
void * V_53 = V_322 -> V_323 -> V_53 ;
T_1 V_324 ;
V_324 = V_322 -> V_324 ;
if ( V_322 -> V_325 < V_324 ) {
memset ( V_53 + V_324 , 0 , V_322 -> V_323 -> V_17 - V_324 ) ;
V_324 = 0 ;
}
memset ( V_53 + V_324 , 0 , V_322 -> V_325 - V_324 ) ;
}
static void F_277 ( struct V_105 * V_96 )
{
struct V_89 * V_322 ;
struct V_310 * V_326 ;
struct V_327 * V_328 ;
unsigned long V_85 ;
bool V_329 ;
if ( V_96 -> V_330 )
V_96 -> V_330 ( V_96 ) ;
V_322 = F_274 ( V_96 ) ;
if ( ! V_322 )
return;
V_329 = V_96 -> V_331 . V_332 >= V_333 ;
if ( V_96 -> V_331 . V_334 != F_278 ( V_96 ) )
V_329 = false ;
F_273 ( V_322 -> V_311 , V_329 ) ;
if ( ! V_329 )
return;
F_279 ( L_6 ,
V_96 -> V_335 , V_322 -> V_95 ) ;
V_96 -> V_336 ( V_96 , V_322 ) ;
V_326 = V_322 -> V_311 ;
if ( F_280 ( V_326 ) )
return;
V_328 = F_281 ( V_326 , V_96 ) ;
F_282 ( & V_96 -> V_328 -> V_257 , V_85 ) ;
F_10 ( & V_328 -> V_257 ) ;
F_283 (request, &engine->timeline->requests, link)
if ( V_322 -> V_311 == V_326 )
F_276 ( V_322 ) ;
F_22 (request, &timeline->requests, link)
F_276 ( V_322 ) ;
F_11 ( & V_328 -> V_257 ) ;
F_284 ( & V_96 -> V_328 -> V_257 , V_85 ) ;
}
void F_285 ( struct V_22 * V_23 )
{
struct V_105 * V_96 ;
enum V_337 V_338 ;
F_56 ( & V_23 -> V_160 . V_33 ) ;
F_58 ( V_23 ) ;
F_286 (engine, dev_priv, id)
F_277 ( V_96 ) ;
F_287 ( V_23 ) ;
if ( V_23 -> V_339 . V_340 ) {
F_288 ( V_23 ) ;
F_289 ( V_23 ) ;
if ( F_70 ( V_23 ) >= 6 )
F_290 ( V_23 ) ;
}
}
static void F_291 ( struct V_89 * V_322 )
{
F_292 ( V_322 ) ;
F_293 ( V_322 -> V_96 , V_322 -> V_95 ) ;
}
static void F_294 ( struct V_105 * V_96 )
{
V_96 -> V_341 = F_291 ;
F_293 ( V_96 ,
F_74 ( V_96 ) ) ;
if ( V_93 . V_342 ) {
unsigned long V_85 ;
F_282 ( & V_96 -> V_328 -> V_257 , V_85 ) ;
F_295 ( V_96 -> V_343 [ 0 ] . V_322 ) ;
F_295 ( V_96 -> V_343 [ 1 ] . V_322 ) ;
memset ( V_96 -> V_343 , 0 , sizeof( V_96 -> V_343 ) ) ;
V_96 -> V_344 = V_345 ;
V_96 -> V_346 = NULL ;
F_284 ( & V_96 -> V_328 -> V_257 , V_85 ) ;
}
}
void F_296 ( struct V_22 * V_23 )
{
struct V_105 * V_96 ;
enum V_337 V_338 ;
F_56 ( & V_23 -> V_160 . V_33 ) ;
F_297 ( V_347 , & V_23 -> V_32 . V_85 ) ;
F_298 ( V_23 ) ;
F_286 (engine, dev_priv, id)
F_294 ( V_96 ) ;
F_299 ( V_23 -> V_348 , & V_23 -> V_339 . V_349 , 0 ) ;
F_58 ( V_23 ) ;
}
static void
F_300 ( struct V_350 * V_351 )
{
struct V_22 * V_23 =
F_301 ( V_351 , F_302 ( * V_23 ) , V_339 . V_352 . V_351 ) ;
struct V_1 * V_2 = & V_23 -> V_160 ;
if ( F_303 ( & V_2 -> V_33 ) ) {
F_58 ( V_23 ) ;
F_24 ( & V_2 -> V_33 ) ;
}
if ( F_173 ( V_23 -> V_339 . V_340 ) ) {
F_304 ( V_23 ) ;
F_305 ( V_23 -> V_348 ,
& V_23 -> V_339 . V_352 ,
F_306 ( V_353 ) ) ;
}
}
static void
F_307 ( struct V_350 * V_351 )
{
struct V_22 * V_23 =
F_301 ( V_351 , F_302 ( * V_23 ) , V_339 . V_349 . V_351 ) ;
struct V_1 * V_2 = & V_23 -> V_160 ;
struct V_105 * V_96 ;
enum V_337 V_338 ;
bool V_354 ;
if ( ! F_173 ( V_23 -> V_339 . V_340 ) )
return;
F_308 ( F_173 ( V_23 -> V_339 . V_355 ) ||
F_309 ( V_23 ) , 10 ) ;
if ( F_173 ( V_23 -> V_339 . V_355 ) )
return;
V_354 =
F_310 ( & V_23 -> V_32 . V_356 ) ;
if ( ! F_303 ( & V_2 -> V_33 ) ) {
F_299 ( V_23 -> V_348 ,
& V_23 -> V_339 . V_349 ,
F_311 ( 50 ) ) ;
goto V_357;
}
if ( F_312 ( V_351 ) )
goto V_164;
if ( V_23 -> V_339 . V_355 )
goto V_164;
if ( F_308 ( F_309 ( V_23 ) , 10 ) )
F_17 ( L_7 ) ;
F_286 (engine, dev_priv, id)
F_313 ( & V_96 -> V_358 ) ;
F_46 ( ! V_23 -> V_339 . V_340 ) ;
V_23 -> V_339 . V_340 = false ;
V_354 = false ;
if ( F_70 ( V_23 ) >= 6 )
F_314 ( V_23 ) ;
F_152 ( V_23 ) ;
V_164:
F_24 ( & V_2 -> V_33 ) ;
V_357:
if ( V_354 ) {
F_46 ( ! V_23 -> V_339 . V_340 ) ;
F_304 ( V_23 ) ;
}
}
void F_315 ( struct V_359 * V_360 , struct V_35 * V_36 )
{
struct V_6 * V_7 = F_190 ( V_360 ) ;
struct V_113 * V_114 = V_36 -> V_115 ;
struct V_38 * V_39 , * V_361 ;
F_21 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
F_206 (vma, vn, &obj->vma_list, obj_link)
if ( V_39 -> V_192 -> V_36 == V_114 )
F_316 ( V_39 ) ;
if ( F_317 ( V_7 ) &&
! F_318 ( V_7 ) ) {
F_319 ( V_7 ) ;
F_320 ( V_7 ) ;
}
F_24 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
}
static unsigned long F_321 ( T_12 V_362 )
{
if ( V_362 < 0 )
return V_80 ;
if ( V_362 == 0 )
return 0 ;
return F_322 ( V_362 ) ;
}
int
F_323 ( struct V_1 * V_2 , void * V_34 , struct V_35 * V_36 )
{
struct V_363 * args = V_34 ;
struct V_6 * V_7 ;
T_13 V_149 ;
long V_28 ;
if ( args -> V_85 != 0 )
return - V_55 ;
V_7 = F_155 ( V_36 , args -> V_364 ) ;
if ( ! V_7 )
return - V_174 ;
V_149 = F_324 () ;
V_28 = F_57 ( V_7 ,
V_77 | V_79 ,
F_321 ( args -> V_362 ) ,
F_87 ( V_36 ) ) ;
if ( args -> V_362 > 0 ) {
args -> V_362 -= F_325 ( F_326 ( F_324 () , V_149 ) ) ;
if ( args -> V_362 < 0 )
args -> V_362 = 0 ;
}
F_105 ( V_7 ) ;
return V_28 ;
}
static int F_327 ( struct V_365 * V_366 , unsigned int V_85 )
{
int V_28 , V_54 ;
for ( V_54 = 0 ; V_54 < F_262 ( V_366 -> V_96 ) ; V_54 ++ ) {
V_28 = F_328 ( & V_366 -> V_96 [ V_54 ] . V_367 , V_85 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
int F_213 ( struct V_22 * V_93 , unsigned int V_85 )
{
int V_28 ;
if ( V_85 & V_78 ) {
struct V_365 * V_366 ;
F_56 ( & V_93 -> V_160 . V_33 ) ;
F_22 (tl, &i915->gt.timelines, link) {
V_28 = F_327 ( V_366 , V_85 ) ;
if ( V_28 )
return V_28 ;
}
} else {
V_28 = F_327 ( & V_93 -> V_339 . V_368 , V_85 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
void F_329 ( struct V_6 * V_7 ,
bool V_369 )
{
if ( ! V_7 -> V_18 . V_67 )
return;
if ( V_7 -> V_370 || V_7 -> V_66 )
return;
if ( ! V_369 && F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_11 ) ) {
V_7 -> V_146 = true ;
return;
}
F_330 ( V_7 ) ;
F_47 ( V_7 -> V_18 . V_67 ) ;
V_7 -> V_146 = false ;
}
static void
F_118 ( struct V_6 * V_7 )
{
struct V_22 * V_23 = F_3 ( V_7 -> V_8 . V_2 ) ;
if ( V_7 -> V_8 . V_9 != V_187 )
return;
F_150 () ;
if ( F_70 ( V_23 ) >= 6 && ! F_2 ( V_23 ) )
F_331 ( F_332 ( V_23 -> V_96 [ V_371 ] -> V_372 ) ) ;
F_95 ( V_7 , false , F_166 ( V_7 , V_187 ) ) ;
V_7 -> V_8 . V_9 = 0 ;
F_333 ( V_7 ,
V_7 -> V_8 . V_73 ,
V_187 ) ;
}
static void
F_174 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 . V_9 != V_10 )
return;
F_329 ( V_7 , V_7 -> V_12 ) ;
F_95 ( V_7 , false , V_125 ) ;
V_7 -> V_8 . V_9 = 0 ;
F_333 ( V_7 ,
V_7 -> V_8 . V_73 ,
V_10 ) ;
}
int
F_149 ( struct V_6 * V_7 , bool V_220 )
{
T_7 V_373 , V_374 ;
int V_28 ;
F_56 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
V_28 = F_57 ( V_7 ,
V_77 |
V_78 |
( V_220 ? V_79 : 0 ) ,
V_80 ,
NULL ) ;
if ( V_28 )
return V_28 ;
if ( V_7 -> V_8 . V_9 == V_187 )
return 0 ;
V_28 = F_90 ( V_7 ) ;
if ( V_28 )
return V_28 ;
F_174 ( V_7 ) ;
if ( ( V_7 -> V_8 . V_73 & V_187 ) == 0 )
F_334 () ;
V_373 = V_7 -> V_8 . V_9 ;
V_374 = V_7 -> V_8 . V_73 ;
F_46 ( ( V_7 -> V_8 . V_9 & ~ V_187 ) != 0 ) ;
V_7 -> V_8 . V_73 |= V_187 ;
if ( V_220 ) {
V_7 -> V_8 . V_73 = V_187 ;
V_7 -> V_8 . V_9 = V_187 ;
V_7 -> V_18 . V_72 = true ;
}
F_333 ( V_7 ,
V_374 ,
V_373 ) ;
F_53 ( V_7 ) ;
return 0 ;
}
int F_335 ( struct V_6 * V_7 ,
enum V_3 V_11 )
{
struct V_38 * V_39 ;
int V_28 ;
F_56 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
if ( V_7 -> V_11 == V_11 )
return 0 ;
V_375:
F_22 (vma, &obj->vma_list, obj_link) {
if ( ! F_170 ( & V_39 -> V_16 ) )
continue;
if ( F_23 ( V_39 ) ) {
F_257 ( L_8 ) ;
return - V_121 ;
}
if ( F_336 ( V_39 , V_11 ) )
continue;
V_28 = F_61 ( V_39 ) ;
if ( V_28 )
return V_28 ;
goto V_375;
}
if ( V_7 -> V_194 ) {
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
F_203 ( V_7 ) ;
F_22 (vma, &obj->vma_list, obj_link) {
V_28 = F_147 ( V_39 ) ;
if ( V_28 )
return V_28 ;
}
} else {
}
F_22 (vma, &obj->vma_list, obj_link) {
if ( ! F_170 ( & V_39 -> V_16 ) )
continue;
V_28 = F_337 ( V_39 , V_11 , V_376 ) ;
if ( V_28 )
return V_28 ;
}
}
if ( V_7 -> V_8 . V_9 == V_10 &&
F_1 ( V_7 -> V_8 . V_2 , V_7 -> V_11 ) )
V_7 -> V_146 = true ;
F_22 (vma, &obj->vma_list, obj_link)
V_39 -> V_16 . V_377 = V_11 ;
V_7 -> V_11 = V_11 ;
return 0 ;
}
int F_338 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_378 * args = V_34 ;
struct V_6 * V_7 ;
int V_183 = 0 ;
F_339 () ;
V_7 = F_340 ( V_36 , args -> V_128 ) ;
if ( ! V_7 ) {
V_183 = - V_174 ;
goto V_92;
}
switch ( V_7 -> V_11 ) {
case V_379 :
case V_380 :
args -> V_381 = V_382 ;
break;
case V_383 :
args -> V_381 = V_384 ;
break;
default:
args -> V_381 = V_385 ;
break;
}
V_92:
F_341 () ;
return V_183 ;
}
int F_342 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_22 * V_93 = F_3 ( V_2 ) ;
struct V_378 * args = V_34 ;
struct V_6 * V_7 ;
enum V_3 V_4 ;
int V_28 ;
switch ( args -> V_381 ) {
case V_385 :
V_4 = V_5 ;
break;
case V_382 :
if ( ! F_2 ( V_93 ) && ! F_343 ( V_93 ) )
return - V_142 ;
V_4 = V_379 ;
break;
case V_384 :
V_4 = F_344 ( V_93 ) ? V_383 : V_5 ;
break;
default:
return - V_55 ;
}
V_28 = F_18 ( V_2 ) ;
if ( V_28 )
return V_28 ;
V_7 = F_155 ( V_36 , args -> V_128 ) ;
if ( ! V_7 ) {
V_28 = - V_174 ;
goto V_268;
}
V_28 = F_335 ( V_7 , V_4 ) ;
F_105 ( V_7 ) ;
V_268:
F_24 ( & V_2 -> V_33 ) ;
return V_28 ;
}
struct V_38 *
F_345 ( struct V_6 * V_7 ,
T_1 V_386 ,
const struct V_227 * V_228 )
{
struct V_38 * V_39 ;
T_1 V_374 , V_373 ;
int V_28 ;
F_56 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
V_7 -> V_12 ++ ;
V_28 = F_335 ( V_7 ,
F_344 ( F_3 ( V_7 -> V_8 . V_2 ) ) ?
V_383 : V_5 ) ;
if ( V_28 ) {
V_39 = F_28 ( V_28 ) ;
goto V_387;
}
V_39 = F_28 ( - V_184 ) ;
if ( V_228 -> type == V_233 )
V_39 = F_145 ( V_7 , V_228 , 0 , V_386 ,
V_161 | V_162 ) ;
if ( F_32 ( V_39 ) ) {
struct V_22 * V_93 = F_3 ( V_7 -> V_8 . V_2 ) ;
unsigned int V_85 ;
V_85 = 0 ;
if ( F_346 ( V_93 ) )
V_85 = V_161 ;
V_39 = F_145 ( V_7 , V_228 , 0 , V_386 , V_85 ) ;
}
if ( F_32 ( V_39 ) )
goto V_387;
V_39 -> V_388 = F_347 ( T_2 , V_39 -> V_388 , V_386 ) ;
if ( V_7 -> V_146 || V_7 -> V_8 . V_9 == V_10 ) {
F_329 ( V_7 , true ) ;
F_95 ( V_7 , false , V_389 ) ;
}
V_373 = V_7 -> V_8 . V_9 ;
V_374 = V_7 -> V_8 . V_73 ;
V_7 -> V_8 . V_9 = 0 ;
V_7 -> V_8 . V_73 |= V_187 ;
F_333 ( V_7 ,
V_374 ,
V_373 ) ;
return V_39 ;
V_387:
V_7 -> V_12 -- ;
return V_39 ;
}
void
F_348 ( struct V_38 * V_39 )
{
F_56 ( & V_39 -> V_192 -> V_2 -> V_33 ) ;
if ( F_26 ( V_39 -> V_7 -> V_12 == 0 ) )
return;
if ( -- V_39 -> V_7 -> V_12 == 0 )
V_39 -> V_388 = 0 ;
if ( ! F_169 ( V_39 ) )
F_60 ( & V_39 -> V_191 , & V_39 -> V_192 -> V_193 ) ;
F_148 ( V_39 ) ;
}
int
F_120 ( struct V_6 * V_7 , bool V_220 )
{
T_7 V_373 , V_374 ;
int V_28 ;
F_56 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
V_28 = F_57 ( V_7 ,
V_77 |
V_78 |
( V_220 ? V_79 : 0 ) ,
V_80 ,
NULL ) ;
if ( V_28 )
return V_28 ;
if ( V_7 -> V_8 . V_9 == V_10 )
return 0 ;
F_118 ( V_7 ) ;
V_373 = V_7 -> V_8 . V_9 ;
V_374 = V_7 -> V_8 . V_73 ;
if ( ( V_7 -> V_8 . V_73 & V_10 ) == 0 ) {
F_329 ( V_7 , false ) ;
V_7 -> V_8 . V_73 |= V_10 ;
}
F_46 ( ( V_7 -> V_8 . V_9 & ~ V_10 ) != 0 ) ;
if ( V_220 ) {
V_7 -> V_8 . V_73 = V_10 ;
V_7 -> V_8 . V_9 = V_10 ;
}
F_333 ( V_7 ,
V_374 ,
V_373 ) ;
return 0 ;
}
static int
F_349 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
struct V_113 * V_390 = V_36 -> V_115 ;
unsigned long V_391 = V_392 - V_393 ;
struct V_89 * V_322 , * V_394 = NULL ;
long V_28 ;
if ( F_201 ( & V_23 -> V_32 ) )
return - V_31 ;
F_10 ( & V_390 -> V_18 . V_257 ) ;
F_22 (request, &file_priv->mm.request_list, client_list) {
if ( F_350 ( V_322 -> V_94 , V_391 ) )
break;
if ( ! V_322 -> V_94 )
continue;
V_394 = V_322 ;
}
if ( V_394 )
F_351 ( V_394 ) ;
F_11 ( & V_390 -> V_18 . V_257 ) ;
if ( V_394 == NULL )
return 0 ;
V_28 = F_72 ( V_394 ,
V_77 ,
V_80 ) ;
F_295 ( V_394 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
struct V_38 *
F_145 ( struct V_6 * V_7 ,
const struct V_227 * V_228 ,
T_2 V_17 ,
T_2 V_386 ,
T_2 V_85 )
{
struct V_22 * V_23 = F_3 ( V_7 -> V_8 . V_2 ) ;
struct V_395 * V_192 = & V_23 -> V_14 . V_8 ;
struct V_38 * V_39 ;
int V_28 ;
F_56 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
V_39 = F_352 ( V_7 , V_192 , V_228 ) ;
if ( F_32 ( V_39 ) )
return V_39 ;
if ( F_353 ( V_39 , V_17 , V_386 , V_85 ) ) {
if ( V_85 & V_162 &&
( F_23 ( V_39 ) || F_169 ( V_39 ) ) )
return F_28 ( - V_184 ) ;
if ( V_85 & V_161 ) {
T_1 V_396 ;
V_396 = F_207 ( V_23 , V_39 -> V_17 ,
F_186 ( V_7 ) ) ;
if ( V_396 > V_23 -> V_14 . V_19 )
return F_28 ( - V_397 ) ;
if ( V_85 & V_162 &&
V_396 > V_23 -> V_14 . V_19 / 2 )
return F_28 ( - V_184 ) ;
}
F_354 ( F_23 ( V_39 ) ,
L_9
L_10
L_11 ,
F_146 ( V_39 ) , V_386 ,
! ! ( V_85 & V_161 ) ,
F_355 ( V_39 ) ) ;
V_28 = F_61 ( V_39 ) ;
if ( V_28 )
return F_28 ( V_28 ) ;
}
V_28 = F_356 ( V_39 , V_17 , V_386 , V_85 | V_398 ) ;
if ( V_28 )
return F_28 ( V_28 ) ;
return V_39 ;
}
static T_14 unsigned int F_357 ( unsigned int V_338 )
{
F_64 ( V_399 > 16 ) ;
return 0x10000 << V_338 ;
}
static T_14 unsigned int F_358 ( unsigned int V_338 )
{
return V_338 | F_357 ( V_338 ) ;
}
static T_14 unsigned int
F_359 ( const struct V_83 * V_84 )
{
return F_360 ( V_84 , F_357 ) ;
}
static T_14 unsigned int
F_361 ( const struct V_83 * V_84 )
{
if ( ! V_84 )
return 0 ;
return F_360 ( V_84 , F_358 ) ;
}
int
F_362 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_400 * args = V_34 ;
struct V_6 * V_7 ;
struct V_401 * V_190 ;
unsigned int V_402 ;
int V_183 ;
V_183 = - V_174 ;
F_339 () ;
V_7 = F_340 ( V_36 , args -> V_128 ) ;
if ( ! V_7 )
goto V_92;
V_403:
V_402 = F_363 ( & V_7 -> V_100 -> V_402 ) ;
args -> V_404 = F_361 ( F_364 ( V_7 -> V_100 -> V_405 ) ) ;
V_190 = F_364 ( V_7 -> V_100 -> V_84 ) ;
if ( V_190 ) {
unsigned int V_406 = V_190 -> V_406 , V_54 ;
for ( V_54 = 0 ; V_54 < V_406 ; ++ V_54 ) {
struct V_83 * V_84 =
F_364 ( V_190 -> V_102 [ V_54 ] ) ;
args -> V_404 |= F_359 ( V_84 ) ;
}
}
if ( args -> V_404 && F_365 ( & V_7 -> V_100 -> V_402 , V_402 ) )
goto V_403;
V_183 = 0 ;
V_92:
F_341 () ;
return V_183 ;
}
int
F_366 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_390 )
{
return F_349 ( V_2 , V_390 ) ;
}
int
F_367 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_390 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
struct V_407 * args = V_34 ;
struct V_6 * V_7 ;
int V_183 ;
switch ( args -> V_69 ) {
case V_71 :
case V_75 :
break;
default:
return - V_55 ;
}
V_7 = F_155 ( V_390 , args -> V_128 ) ;
if ( ! V_7 )
return - V_174 ;
V_183 = F_19 ( & V_7 -> V_18 . V_257 ) ;
if ( V_183 )
goto V_92;
if ( V_7 -> V_18 . V_67 &&
F_192 ( V_7 ) &&
V_23 -> V_295 & V_296 ) {
if ( V_7 -> V_18 . V_69 == V_75 ) {
F_46 ( ! V_7 -> V_18 . V_297 ) ;
F_368 ( V_7 ) ;
V_7 -> V_18 . V_297 = false ;
}
if ( args -> V_69 == V_75 ) {
F_46 ( V_7 -> V_18 . V_297 ) ;
F_255 ( V_7 ) ;
V_7 -> V_18 . V_297 = true ;
}
}
if ( V_7 -> V_18 . V_69 != V_70 )
V_7 -> V_18 . V_69 = args -> V_69 ;
if ( V_7 -> V_18 . V_69 == V_71 && ! V_7 -> V_18 . V_67 )
F_219 ( V_7 ) ;
args -> V_408 = V_7 -> V_18 . V_69 != V_70 ;
F_24 ( & V_7 -> V_18 . V_257 ) ;
V_92:
F_105 ( V_7 ) ;
return V_183 ;
}
static void
F_369 ( struct V_409 * V_410 ,
struct V_89 * V_322 )
{
struct V_6 * V_7 =
F_301 ( V_410 , F_302 ( * V_7 ) , V_411 ) ;
F_95 ( V_7 , true , V_412 ) ;
}
void F_370 ( struct V_6 * V_7 ,
const struct V_413 * V_117 )
{
F_371 ( & V_7 -> V_18 . V_257 ) ;
F_372 ( & V_7 -> V_197 ) ;
F_372 ( & V_7 -> V_234 ) ;
F_372 ( & V_7 -> V_414 ) ;
F_372 ( & V_7 -> V_81 ) ;
F_372 ( & V_7 -> V_415 ) ;
V_7 -> V_117 = V_117 ;
F_373 ( & V_7 -> V_416 ) ;
V_7 -> V_100 = & V_7 -> V_416 ;
V_7 -> V_188 = V_417 ;
F_374 ( & V_7 -> V_411 , F_369 ) ;
V_7 -> V_18 . V_69 = V_75 ;
F_375 ( & V_7 -> V_18 . V_262 . V_263 , V_61 | V_276 ) ;
F_371 ( & V_7 -> V_18 . V_262 . V_257 ) ;
F_9 ( F_3 ( V_7 -> V_8 . V_2 ) , V_7 -> V_8 . V_17 ) ;
}
struct V_6 *
F_102 ( struct V_1 * V_2 , T_2 V_17 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
struct V_6 * V_7 ;
struct V_45 * V_46 ;
T_10 V_418 ;
int V_28 ;
if ( F_26 ( V_17 >> V_156 > V_419 ) )
return F_28 ( - V_397 ) ;
if ( F_376 ( V_17 , V_7 -> V_8 . V_17 ) )
return F_28 ( - V_397 ) ;
V_7 = F_96 ( V_2 ) ;
if ( V_7 == NULL )
return F_28 ( - V_56 ) ;
V_28 = F_377 ( V_2 , & V_7 -> V_8 , V_17 ) ;
if ( V_28 )
goto V_420;
V_418 = V_421 | V_422 ;
if ( F_378 ( V_23 ) || F_379 ( V_23 ) ) {
V_418 &= ~ V_423 ;
V_418 |= V_290 ;
}
V_46 = V_7 -> V_8 . V_47 -> V_48 ;
F_380 ( V_46 , V_418 ) ;
F_370 ( V_7 , & V_424 ) ;
V_7 -> V_8 . V_9 = V_10 ;
V_7 -> V_8 . V_73 = V_10 ;
if ( F_2 ( V_23 ) ) {
V_7 -> V_11 = V_379 ;
} else
V_7 -> V_11 = V_5 ;
F_381 ( V_7 ) ;
return V_7 ;
V_420:
F_98 ( V_7 ) ;
return F_28 ( V_28 ) ;
}
static bool F_382 ( struct V_6 * V_7 )
{
if ( V_7 -> V_18 . V_69 != V_75 )
return false ;
if ( V_7 -> V_8 . V_47 == NULL )
return true ;
return F_383 ( & V_7 -> V_8 . V_47 -> V_425 ) == 1 ;
}
static void F_384 ( struct V_22 * V_93 ,
struct V_426 * V_427 )
{
struct V_6 * V_7 , * V_247 ;
F_21 ( & V_93 -> V_160 . V_33 ) ;
F_144 ( V_93 ) ;
F_385 (obj, freed, freed) {
struct V_38 * V_39 , * V_361 ;
F_386 ( V_7 ) ;
F_46 ( F_317 ( V_7 ) ) ;
F_206 (vma, vn,
&obj->vma_list, obj_link) {
F_46 ( ! F_168 ( V_39 ) ) ;
F_46 ( F_169 ( V_39 ) ) ;
V_39 -> V_85 &= ~ V_428 ;
F_316 ( V_39 ) ;
}
F_46 ( ! F_197 ( & V_7 -> V_81 ) ) ;
F_46 ( ! F_387 ( & V_7 -> V_429 ) ) ;
F_388 ( & V_7 -> V_197 ) ;
}
F_152 ( V_93 ) ;
F_24 ( & V_93 -> V_160 . V_33 ) ;
F_389 (obj, on, freed, freed) {
F_46 ( V_7 -> V_194 ) ;
F_46 ( F_233 ( & V_7 -> V_430 ) ) ;
if ( V_7 -> V_117 -> V_431 )
V_7 -> V_117 -> V_431 ( V_7 ) ;
if ( F_26 ( F_231 ( V_7 ) ) )
F_390 ( & V_7 -> V_18 . V_267 , 0 ) ;
F_89 ( V_7 , V_120 ) ;
F_46 ( V_7 -> V_18 . V_67 ) ;
if ( V_7 -> V_8 . V_432 )
F_391 ( & V_7 -> V_8 , NULL ) ;
F_392 ( & V_7 -> V_416 ) ;
F_393 ( & V_7 -> V_8 ) ;
F_12 ( V_93 , V_7 -> V_8 . V_17 ) ;
F_41 ( V_7 -> V_433 ) ;
F_98 ( V_7 ) ;
}
}
static void F_110 ( struct V_22 * V_93 )
{
struct V_426 * V_427 ;
V_427 = F_394 ( & V_93 -> V_18 . V_434 ) ;
if ( F_123 ( V_427 ) )
F_384 ( V_93 , V_427 ) ;
}
static void F_395 ( struct V_350 * V_351 )
{
struct V_22 * V_93 =
F_301 ( V_351 , struct V_22 , V_18 . V_435 ) ;
struct V_426 * V_427 ;
while ( ( V_427 = F_394 ( & V_93 -> V_18 . V_434 ) ) )
F_384 ( V_93 , V_427 ) ;
}
static void F_396 ( struct V_436 * V_324 )
{
struct V_6 * V_7 =
F_301 ( V_324 , F_302 ( * V_7 ) , V_437 ) ;
struct V_22 * V_93 = F_3 ( V_7 -> V_8 . V_2 ) ;
if ( F_397 ( & V_7 -> V_427 , & V_93 -> V_18 . V_434 ) )
F_398 ( & V_93 -> V_18 . V_435 ) ;
}
void F_399 ( struct V_359 * V_438 )
{
struct V_6 * V_7 = F_190 ( V_438 ) ;
if ( V_7 -> V_18 . V_297 )
F_368 ( V_7 ) ;
if ( F_382 ( V_7 ) )
V_7 -> V_18 . V_69 = V_71 ;
F_400 ( & V_7 -> V_437 , F_396 ) ;
}
void F_401 ( struct V_6 * V_7 )
{
F_56 ( & V_7 -> V_8 . V_2 -> V_33 ) ;
F_46 ( F_318 ( V_7 ) ) ;
if ( F_317 ( V_7 ) )
F_319 ( V_7 ) ;
else
F_105 ( V_7 ) ;
}
static void F_402 ( struct V_22 * V_23 )
{
struct V_105 * V_96 ;
enum V_337 V_338 ;
F_286 (engine, dev_priv, id)
F_46 ( V_96 -> V_439 != V_23 -> V_440 ) ;
}
int F_403 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
int V_28 ;
F_404 ( V_23 ) ;
F_21 ( & V_2 -> V_33 ) ;
V_28 = F_405 ( V_23 ) ;
if ( V_28 )
goto V_183;
V_28 = F_213 ( V_23 ,
V_77 |
V_78 ) ;
if ( V_28 )
goto V_183;
F_58 ( V_23 ) ;
F_46 ( V_23 -> V_339 . V_355 ) ;
F_402 ( V_23 ) ;
F_298 ( V_23 ) ;
F_24 ( & V_2 -> V_33 ) ;
F_310 ( & V_23 -> V_32 . V_356 ) ;
F_310 ( & V_23 -> V_339 . V_352 ) ;
F_406 ( & V_23 -> V_339 . V_349 ) ;
F_407 ( & V_23 -> V_18 . V_435 ) ;
F_26 ( V_23 -> V_339 . V_340 ) ;
F_26 ( ! F_309 ( V_23 ) ) ;
if ( F_408 ( V_23 ) ) {
int V_441 = F_409 ( V_23 , V_442 ) ;
F_26 ( V_441 && V_441 != - V_142 ) ;
}
return 0 ;
V_183:
F_24 ( & V_2 -> V_33 ) ;
return V_28 ;
}
void F_410 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
F_26 ( V_23 -> V_339 . V_340 ) ;
F_21 ( & V_2 -> V_33 ) ;
F_411 ( V_23 ) ;
V_23 -> V_339 . V_443 ( V_23 ) ;
F_24 ( & V_2 -> V_33 ) ;
}
void F_412 ( struct V_22 * V_23 )
{
if ( F_70 ( V_23 ) < 5 ||
V_23 -> V_18 . V_444 == V_445 )
return;
F_413 ( V_446 , F_414 ( V_446 ) |
V_447 ) ;
if ( F_415 ( V_23 ) )
return;
F_413 ( V_448 , F_414 ( V_448 ) | V_449 ) ;
if ( F_416 ( V_23 ) )
F_413 ( V_450 , F_417 ( V_451 ) ) ;
else if ( F_418 ( V_23 ) )
F_413 ( V_450 , F_417 ( V_452 ) ) ;
else if ( F_419 ( V_23 ) )
F_413 ( V_453 , F_417 ( V_454 ) ) ;
else
F_420 () ;
}
static void F_421 ( struct V_22 * V_23 , T_1 V_8 )
{
F_413 ( F_422 ( V_8 ) , 0 ) ;
F_413 ( F_423 ( V_8 ) , 0 ) ;
F_413 ( F_424 ( V_8 ) , 0 ) ;
F_413 ( F_425 ( V_8 ) , 0 ) ;
}
static void F_426 ( struct V_22 * V_23 )
{
if ( F_427 ( V_23 ) ) {
F_421 ( V_23 , V_455 ) ;
F_421 ( V_23 , V_456 ) ;
F_421 ( V_23 , V_457 ) ;
F_421 ( V_23 , V_458 ) ;
F_421 ( V_23 , V_459 ) ;
} else if ( F_428 ( V_23 ) ) {
F_421 ( V_23 , V_456 ) ;
F_421 ( V_23 , V_457 ) ;
} else if ( F_208 ( V_23 ) ) {
F_421 ( V_23 , V_455 ) ;
F_421 ( V_23 , V_460 ) ;
}
}
int
F_429 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
struct V_105 * V_96 ;
enum V_337 V_338 ;
int V_28 ;
V_23 -> V_339 . V_461 = F_324 () ;
F_430 ( V_23 , V_462 ) ;
if ( F_431 ( V_23 ) && F_70 ( V_23 ) < 9 )
F_413 ( V_463 , F_414 ( V_463 ) | F_432 ( 0xf ) ) ;
if ( F_433 ( V_23 ) )
F_413 ( V_464 , F_434 ( V_23 ) ?
V_465 : V_466 ) ;
if ( F_435 ( V_23 ) ) {
if ( F_436 ( V_23 ) ) {
T_1 V_467 = F_414 ( V_468 ) ;
V_467 &= ~ ( V_469 | V_470 ) ;
F_413 ( V_468 , V_467 ) ;
} else if ( F_70 ( V_23 ) >= 7 ) {
T_1 V_467 = F_414 ( V_471 ) ;
V_467 &= ~ V_472 ;
F_413 ( V_471 , V_467 ) ;
}
}
F_412 ( V_23 ) ;
F_426 ( V_23 ) ;
F_437 ( ! V_23 -> V_440 ) ;
V_28 = F_438 ( V_23 ) ;
if ( V_28 ) {
F_17 ( L_12 , V_28 ) ;
goto V_92;
}
F_286 (engine, dev_priv, id) {
V_28 = V_96 -> V_473 ( V_96 ) ;
if ( V_28 )
goto V_92;
}
F_439 ( V_2 ) ;
V_28 = F_440 ( V_2 ) ;
if ( V_28 )
goto V_92;
V_92:
F_441 ( V_23 , V_462 ) ;
return V_28 ;
}
bool F_442 ( struct V_22 * V_23 , int V_474 )
{
if ( F_443 ( V_23 ) -> V_475 < 6 )
return false ;
if ( V_93 . V_342 )
return false ;
if ( V_474 >= 0 )
return V_474 ;
#ifdef F_444
if ( F_443 ( V_23 ) -> V_475 == 6 && V_476 )
return false ;
#endif
return true ;
}
int F_445 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
int V_28 ;
F_21 ( & V_2 -> V_33 ) ;
if ( ! V_93 . V_342 ) {
V_23 -> V_339 . V_443 = V_477 ;
V_23 -> V_339 . V_478 = V_479 ;
} else {
V_23 -> V_339 . V_443 = V_480 ;
V_23 -> V_339 . V_478 = V_481 ;
}
F_430 ( V_23 , V_462 ) ;
F_446 ( V_23 ) ;
V_28 = F_447 ( V_23 ) ;
if ( V_28 )
goto V_164;
V_28 = F_448 ( V_2 ) ;
if ( V_28 )
goto V_164;
V_28 = F_449 ( V_2 ) ;
if ( V_28 )
goto V_164;
V_28 = F_429 ( V_2 ) ;
if ( V_28 == - V_31 ) {
F_17 ( L_13 ) ;
F_296 ( V_23 ) ;
V_28 = 0 ;
}
V_164:
F_441 ( V_23 , V_462 ) ;
F_24 ( & V_2 -> V_33 ) ;
return V_28 ;
}
void
F_450 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
struct V_105 * V_96 ;
enum V_337 V_338 ;
F_286 (engine, dev_priv, id)
V_23 -> V_339 . V_478 ( V_96 ) ;
}
void
F_451 ( struct V_22 * V_23 )
{
int V_54 ;
if ( F_443 ( V_23 ) -> V_475 >= 7 && ! F_452 ( V_23 ) &&
! F_453 ( V_23 ) )
V_23 -> V_248 = 32 ;
else if ( F_443 ( V_23 ) -> V_475 >= 4 || F_454 ( V_23 ) ||
F_455 ( V_23 ) || F_210 ( V_23 ) )
V_23 -> V_248 = 16 ;
else
V_23 -> V_248 = 8 ;
if ( F_456 ( V_23 ) )
V_23 -> V_248 =
F_414 ( F_457 ( V_482 . V_483 ) ) ;
for ( V_54 = 0 ; V_54 < V_23 -> V_248 ; V_54 ++ ) {
struct V_249 * V_84 = & V_23 -> V_251 [ V_54 ] ;
V_84 -> V_93 = V_23 ;
V_84 -> V_338 = V_54 ;
F_458 ( & V_84 -> V_98 , & V_23 -> V_18 . V_484 ) ;
}
F_287 ( V_23 ) ;
F_459 ( V_23 ) ;
}
int
F_460 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
int V_183 = - V_56 ;
V_23 -> V_126 = F_461 ( V_6 , V_485 ) ;
if ( ! V_23 -> V_126 )
goto V_486;
V_23 -> V_487 = F_461 ( V_38 , V_485 ) ;
if ( ! V_23 -> V_487 )
goto V_488;
V_23 -> V_489 = F_461 ( V_89 ,
V_485 |
V_490 |
V_491 ) ;
if ( ! V_23 -> V_489 )
goto V_492;
V_23 -> V_493 = F_461 ( V_494 ,
V_485 |
V_490 ) ;
if ( ! V_23 -> V_493 )
goto V_495;
F_21 ( & V_23 -> V_160 . V_33 ) ;
F_372 ( & V_23 -> V_339 . V_496 ) ;
V_183 = F_462 ( V_23 ) ;
F_24 ( & V_23 -> V_160 . V_33 ) ;
if ( V_183 )
goto V_497;
F_372 ( & V_23 -> V_498 ) ;
F_463 ( & V_23 -> V_18 . V_435 , F_395 ) ;
F_464 ( & V_23 -> V_18 . V_434 ) ;
F_372 ( & V_23 -> V_18 . V_196 ) ;
F_372 ( & V_23 -> V_18 . V_195 ) ;
F_372 ( & V_23 -> V_18 . V_484 ) ;
F_372 ( & V_23 -> V_18 . V_235 ) ;
F_465 ( & V_23 -> V_339 . V_352 ,
F_300 ) ;
F_465 ( & V_23 -> V_339 . V_349 ,
F_307 ) ;
F_466 ( & V_23 -> V_32 . V_499 ) ;
F_466 ( & V_23 -> V_32 . V_29 ) ;
V_23 -> V_500 = V_501 ;
F_466 ( & V_23 -> V_502 ) ;
V_23 -> V_18 . V_503 = true ;
F_390 ( & V_23 -> V_18 . V_504 , 0 ) ;
F_467 ( & V_23 -> V_505 . V_257 ) ;
return 0 ;
V_497:
F_468 ( V_23 -> V_493 ) ;
V_495:
F_468 ( V_23 -> V_489 ) ;
V_492:
F_468 ( V_23 -> V_487 ) ;
V_488:
F_468 ( V_23 -> V_126 ) ;
V_486:
return V_183 ;
}
void F_469 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_3 ( V_2 ) ;
F_26 ( ! F_470 ( & V_23 -> V_18 . V_434 ) ) ;
F_21 ( & V_23 -> V_160 . V_33 ) ;
F_471 ( & V_23 -> V_339 . V_368 ) ;
F_26 ( ! F_197 ( & V_23 -> V_339 . V_496 ) ) ;
F_24 ( & V_23 -> V_160 . V_33 ) ;
F_468 ( V_23 -> V_493 ) ;
F_468 ( V_23 -> V_489 ) ;
F_468 ( V_23 -> V_487 ) ;
F_468 ( V_23 -> V_126 ) ;
F_472 () ;
}
int F_473 ( struct V_22 * V_23 )
{
F_144 ( V_23 ) ;
F_21 ( & V_23 -> V_160 . V_33 ) ;
F_474 ( V_23 ) ;
F_24 ( & V_23 -> V_160 . V_33 ) ;
F_152 ( V_23 ) ;
return 0 ;
}
int F_475 ( struct V_22 * V_23 )
{
struct V_6 * V_7 ;
struct V_189 * V_506 [] = {
& V_23 -> V_18 . V_196 ,
& V_23 -> V_18 . V_195 ,
NULL
} , * * V_507 ;
F_21 ( & V_23 -> V_160 . V_33 ) ;
F_248 ( V_23 , - 1UL , V_287 ) ;
for ( V_507 = V_506 ; * V_507 ; V_507 ++ ) {
F_22 (obj, *p, global_link) {
V_7 -> V_8 . V_73 = V_10 ;
V_7 -> V_8 . V_9 = V_10 ;
}
}
F_24 ( & V_23 -> V_160 . V_33 ) ;
return 0 ;
}
void F_476 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_113 * V_390 = V_36 -> V_115 ;
struct V_89 * V_322 ;
F_10 ( & V_390 -> V_18 . V_257 ) ;
F_22 (request, &file_priv->mm.request_list, client_list)
V_322 -> V_390 = NULL ;
F_11 ( & V_390 -> V_18 . V_257 ) ;
if ( ! F_197 ( & V_390 -> V_88 . V_98 ) ) {
F_10 ( & F_3 ( V_2 ) -> V_88 . V_97 ) ;
F_388 ( & V_390 -> V_88 . V_98 ) ;
F_11 ( & F_3 ( V_2 ) -> V_88 . V_97 ) ;
}
}
int F_477 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_113 * V_390 ;
int V_28 ;
F_257 ( L_14 ) ;
V_390 = F_478 ( sizeof( * V_390 ) , V_61 ) ;
if ( ! V_390 )
return - V_56 ;
V_36 -> V_115 = V_390 ;
V_390 -> V_23 = F_3 ( V_2 ) ;
V_390 -> V_36 = V_36 ;
F_372 ( & V_390 -> V_88 . V_98 ) ;
F_467 ( & V_390 -> V_18 . V_257 ) ;
F_372 ( & V_390 -> V_18 . V_508 ) ;
V_390 -> V_509 = - 1 ;
V_28 = F_479 ( V_2 , V_36 ) ;
if ( V_28 )
F_41 ( V_390 ) ;
return V_28 ;
}
void F_480 ( struct V_6 * V_510 ,
struct V_6 * V_511 ,
unsigned V_430 )
{
F_64 ( V_512 * V_513 >
sizeof( V_514 ) * V_515 ) ;
if ( V_510 ) {
F_26 ( ! ( F_233 ( & V_510 -> V_430 ) & V_430 ) ) ;
F_481 ( V_430 , & V_510 -> V_430 ) ;
}
if ( V_511 ) {
F_26 ( F_233 ( & V_511 -> V_430 ) & V_430 ) ;
F_482 ( V_430 , & V_511 -> V_430 ) ;
}
}
struct V_6 *
F_483 ( struct V_1 * V_2 ,
const void * V_34 , T_3 V_17 )
{
struct V_6 * V_7 ;
struct V_44 * V_52 ;
T_3 V_516 ;
int V_28 ;
V_7 = F_102 ( V_2 , F_125 ( V_17 , V_57 ) ) ;
if ( F_32 ( V_7 ) )
return V_7 ;
V_28 = F_120 ( V_7 , true ) ;
if ( V_28 )
goto V_420;
V_28 = F_90 ( V_7 ) ;
if ( V_28 )
goto V_420;
V_52 = V_7 -> V_18 . V_67 ;
V_516 = F_484 ( V_52 -> V_62 , V_52 -> V_274 , ( void * ) V_34 , V_17 ) ;
V_7 -> V_18 . V_72 = true ;
F_53 ( V_7 ) ;
if ( F_26 ( V_516 != V_17 ) ) {
F_17 ( L_15 , V_516 , V_17 ) ;
V_28 = - V_119 ;
goto V_420;
}
return V_7 ;
V_420:
F_105 ( V_7 ) ;
return F_28 ( V_28 ) ;
}
struct V_51 *
F_485 ( struct V_6 * V_7 ,
unsigned int V_517 ,
unsigned int * V_63 )
{
struct V_518 * V_260 = & V_7 -> V_18 . V_262 ;
struct V_51 * V_52 ;
unsigned int V_155 , V_103 ;
F_14 () ;
F_46 ( V_517 >= V_7 -> V_8 . V_17 >> V_156 ) ;
F_46 ( ! F_231 ( V_7 ) ) ;
if ( V_517 < F_173 ( V_260 -> V_294 ) )
goto V_519;
F_21 ( & V_260 -> V_257 ) ;
V_52 = V_260 -> V_293 ;
V_155 = V_260 -> V_294 ;
V_103 = F_486 ( V_52 ) ;
while ( V_155 + V_103 <= V_517 ) {
unsigned long V_520 , V_54 ;
int V_28 ;
V_28 = F_487 ( & V_260 -> V_263 , V_155 , V_52 ) ;
if ( V_28 && V_28 != - V_521 )
goto V_522;
V_520 =
V_523 |
V_155 << V_524 ;
for ( V_54 = 1 ; V_54 < V_103 ; V_54 ++ ) {
V_28 = F_487 ( & V_260 -> V_263 , V_155 + V_54 ,
( void * ) V_520 ) ;
if ( V_28 && V_28 != - V_521 )
goto V_522;
}
V_155 += V_103 ;
V_52 = F_488 ( V_52 ) ;
V_103 = F_486 ( V_52 ) ;
}
V_522:
V_260 -> V_293 = V_52 ;
V_260 -> V_294 = V_155 ;
F_24 ( & V_260 -> V_257 ) ;
if ( F_123 ( V_517 < V_155 ) )
goto V_519;
while ( V_155 + V_103 <= V_517 ) {
V_155 += V_103 ;
V_52 = F_488 ( V_52 ) ;
V_103 = F_486 ( V_52 ) ;
}
* V_63 = V_517 - V_155 ;
return V_52 ;
V_519:
F_339 () ;
V_52 = F_489 ( & V_260 -> V_263 , V_517 ) ;
F_46 ( ! V_52 ) ;
* V_63 = 0 ;
if ( F_123 ( F_490 ( V_52 ) ) ) {
unsigned long V_8 =
( unsigned long ) V_52 >> V_524 ;
V_52 = F_489 ( & V_260 -> V_263 , V_8 ) ;
F_46 ( ! V_52 ) ;
* V_63 = V_517 - V_8 ;
}
F_341 () ;
return V_52 ;
}
struct V_58 *
F_134 ( struct V_6 * V_7 , unsigned int V_517 )
{
struct V_51 * V_52 ;
unsigned int V_63 ;
F_46 ( ! F_117 ( V_7 ) ) ;
V_52 = F_485 ( V_7 , V_517 , & V_63 ) ;
return F_491 ( F_242 ( V_52 ) , V_63 ) ;
}
struct V_58 *
F_492 ( struct V_6 * V_7 ,
unsigned int V_517 )
{
struct V_58 * V_58 ;
V_58 = F_134 ( V_7 , V_517 ) ;
if ( ! V_7 -> V_18 . V_72 )
F_49 ( V_58 ) ;
return V_58 ;
}
T_15
F_151 ( struct V_6 * V_7 ,
unsigned long V_517 )
{
struct V_51 * V_52 ;
unsigned int V_63 ;
V_52 = F_485 ( V_7 , V_517 , & V_63 ) ;
return F_42 ( V_52 ) + ( V_63 << V_156 ) ;
}

static bool F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return false ;
if ( ! ( V_2 -> V_4 & V_5 ) )
return true ;
return V_2 -> V_6 ;
}
static int
F_2 ( struct V_7 * V_8 ,
struct V_9 * V_10 , T_1 V_11 )
{
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
return F_3 ( & V_8 -> V_12 . V_13 , V_10 ,
V_11 , 0 , V_14 ,
0 , V_8 -> V_15 ,
V_16 ) ;
}
static void
F_4 ( struct V_9 * V_10 )
{
F_5 ( V_10 ) ;
}
static void F_6 ( struct V_17 * V_18 ,
T_2 V_11 )
{
F_7 ( & V_18 -> V_13 . V_19 ) ;
V_18 -> V_13 . V_20 ++ ;
V_18 -> V_13 . V_21 += V_11 ;
F_8 ( & V_18 -> V_13 . V_19 ) ;
}
static void F_9 ( struct V_17 * V_18 ,
T_2 V_11 )
{
F_7 ( & V_18 -> V_13 . V_19 ) ;
V_18 -> V_13 . V_20 -- ;
V_18 -> V_13 . V_21 -= V_11 ;
F_8 ( & V_18 -> V_13 . V_19 ) ;
}
static int
F_10 ( struct V_22 * error )
{
int V_23 ;
F_11 () ;
V_23 = F_12 ( error -> V_24 ,
! F_13 ( error ) ,
V_25 ) ;
if ( V_23 == 0 ) {
F_14 ( L_1 ) ;
return - V_26 ;
} else if ( V_23 < 0 ) {
return V_23 ;
} else {
return 0 ;
}
}
int F_15 ( struct V_27 * V_28 )
{
struct V_17 * V_18 = F_16 ( V_28 ) ;
int V_23 ;
V_23 = F_10 ( & V_18 -> V_29 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_17 ( & V_28 -> V_30 ) ;
if ( V_23 )
return V_23 ;
return 0 ;
}
int
F_18 ( struct V_27 * V_28 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_17 * V_18 = F_16 ( V_28 ) ;
struct V_7 * V_8 = & V_18 -> V_8 ;
struct V_34 * args = V_31 ;
struct V_35 * V_36 ;
T_2 V_37 ;
V_37 = V_8 -> V_12 . V_38 ;
F_19 ( & V_28 -> V_30 ) ;
F_20 (vma, &ggtt->base.active_list, vm_link)
if ( F_21 ( V_36 ) )
V_37 += V_36 -> V_10 . V_11 ;
F_20 (vma, &ggtt->base.inactive_list, vm_link)
if ( F_21 ( V_36 ) )
V_37 += V_36 -> V_10 . V_11 ;
F_22 ( & V_28 -> V_30 ) ;
args -> V_39 = V_8 -> V_12 . V_40 ;
args -> V_41 = args -> V_39 - V_37 ;
return 0 ;
}
static struct V_42 *
F_23 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_12 . V_45 -> V_46 ;
T_3 * V_47 ;
struct V_42 * V_48 ;
struct V_49 * V_50 ;
char * V_51 ;
int V_52 ;
if ( F_24 ( F_25 ( V_2 ) ) )
return F_26 ( - V_53 ) ;
V_47 = F_27 ( V_2 -> V_12 . V_28 ,
V_2 -> V_12 . V_11 ,
F_28 ( V_2 -> V_12 . V_11 ) ) ;
if ( ! V_47 )
return F_26 ( - V_54 ) ;
V_51 = V_47 -> V_51 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_12 . V_11 / V_55 ; V_52 ++ ) {
struct V_56 * V_56 ;
char * V_57 ;
V_56 = F_29 ( V_44 , V_52 ) ;
if ( F_30 ( V_56 ) ) {
V_48 = F_31 ( V_56 ) ;
goto V_58;
}
V_57 = F_32 ( V_56 ) ;
memcpy ( V_51 , V_57 , V_55 ) ;
F_33 ( V_51 , V_55 ) ;
F_34 ( V_57 ) ;
F_35 ( V_56 ) ;
V_51 += V_55 ;
}
F_36 ( F_16 ( V_2 -> V_12 . V_28 ) ) ;
V_48 = F_37 ( sizeof( * V_48 ) , V_59 ) ;
if ( ! V_48 ) {
V_48 = F_26 ( - V_54 ) ;
goto V_58;
}
if ( F_38 ( V_48 , 1 , V_59 ) ) {
F_39 ( V_48 ) ;
V_48 = F_26 ( - V_54 ) ;
goto V_58;
}
V_50 = V_48 -> V_60 ;
V_50 -> V_61 = 0 ;
V_50 -> V_62 = V_2 -> V_12 . V_11 ;
F_40 ( V_50 ) = V_47 -> V_63 ;
F_41 ( V_50 ) = V_2 -> V_12 . V_11 ;
V_2 -> V_64 = V_47 ;
return V_48 ;
V_58:
F_42 ( V_2 -> V_12 . V_28 , V_47 ) ;
return V_48 ;
}
static void F_43 ( struct V_1 * V_2 )
{
V_2 -> V_12 . V_65 = V_66 ;
V_2 -> V_12 . V_67 = V_66 ;
if ( F_1 ( V_2 ) )
V_2 -> V_3 = true ;
}
static void
F_44 ( struct V_1 * V_2 ,
struct V_42 * V_68 ,
bool V_69 )
{
F_45 ( V_2 -> V_13 . V_70 == V_71 ) ;
if ( V_2 -> V_13 . V_70 == V_72 )
V_2 -> V_13 . V_73 = false ;
if ( V_69 &&
( V_2 -> V_12 . V_65 & V_66 ) == 0 &&
! ( V_2 -> V_4 & V_74 ) )
F_46 ( V_68 ) ;
F_43 ( V_2 ) ;
}
static void
F_47 ( struct V_1 * V_2 ,
struct V_42 * V_68 )
{
F_44 ( V_2 , V_68 , false ) ;
if ( V_2 -> V_13 . V_73 ) {
struct V_43 * V_44 = V_2 -> V_12 . V_45 -> V_46 ;
char * V_51 = V_2 -> V_64 -> V_51 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_12 . V_11 / V_55 ; V_52 ++ ) {
struct V_56 * V_56 ;
char * V_75 ;
V_56 = F_29 ( V_44 , V_52 ) ;
if ( F_30 ( V_56 ) )
continue;
V_75 = F_32 ( V_56 ) ;
F_33 ( V_51 , V_55 ) ;
memcpy ( V_75 , V_51 , V_55 ) ;
F_34 ( V_75 ) ;
F_48 ( V_56 ) ;
if ( V_2 -> V_13 . V_70 == V_76 )
F_49 ( V_56 ) ;
F_35 ( V_56 ) ;
V_51 += V_55 ;
}
V_2 -> V_13 . V_73 = false ;
}
F_50 ( V_68 ) ;
F_39 ( V_68 ) ;
F_42 ( V_2 -> V_12 . V_28 , V_2 -> V_64 ) ;
}
static void
F_51 ( struct V_1 * V_2 )
{
F_52 ( V_2 ) ;
}
int F_53 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
F_54 ( V_77 ) ;
int V_23 ;
F_55 ( & V_2 -> V_12 . V_28 -> V_30 ) ;
V_23 = F_56 ( V_2 ,
V_78 |
V_79 |
V_80 ,
V_81 ,
NULL ) ;
if ( V_23 )
return V_23 ;
F_57 ( F_16 ( V_2 -> V_12 . V_28 ) ) ;
while ( ( V_36 = F_58 ( & V_2 -> V_82 ,
struct V_35 ,
V_83 ) ) ) {
F_59 ( & V_36 -> V_83 , & V_77 ) ;
V_23 = F_60 ( V_36 ) ;
if ( V_23 )
break;
}
F_61 ( & V_77 , & V_2 -> V_82 ) ;
return V_23 ;
}
static long
F_62 ( struct V_84 * V_85 ,
unsigned int V_86 ,
long V_87 ,
struct V_88 * V_89 )
{
struct V_90 * V_91 ;
F_63 ( V_78 != 0x1 ) ;
if ( F_64 ( V_92 , & V_85 -> V_86 ) )
return V_87 ;
if ( ! F_65 ( V_85 ) )
return F_66 ( V_85 ,
V_86 & V_78 ,
V_87 ) ;
V_91 = F_67 ( V_85 ) ;
if ( F_68 ( V_91 ) )
goto V_93;
if ( V_89 ) {
if ( F_69 ( V_91 -> V_94 ) >= 6 )
F_70 ( V_91 , V_89 ) ;
else
V_89 = NULL ;
}
V_87 = F_71 ( V_91 , V_86 , V_87 ) ;
V_93:
if ( V_86 & V_79 && F_68 ( V_91 ) )
F_72 ( V_91 ) ;
return V_87 ;
}
static long
F_73 ( struct V_95 * V_96 ,
unsigned int V_86 ,
long V_87 ,
struct V_88 * V_89 )
{
unsigned int V_97 = F_74 ( & V_96 -> V_97 ) ;
struct V_84 * V_98 ;
bool V_99 = false ;
if ( V_86 & V_80 ) {
struct V_84 * * V_100 ;
unsigned int V_101 , V_52 ;
int V_23 ;
V_23 = F_75 ( V_96 ,
& V_98 , & V_101 , & V_100 ) ;
if ( V_23 )
return V_23 ;
for ( V_52 = 0 ; V_52 < V_101 ; V_52 ++ ) {
V_87 = F_62 ( V_100 [ V_52 ] ,
V_86 , V_87 ,
V_89 ) ;
if ( V_87 < 0 )
break;
F_76 ( V_100 [ V_52 ] ) ;
}
for (; V_52 < V_101 ; V_52 ++ )
F_76 ( V_100 [ V_52 ] ) ;
F_39 ( V_100 ) ;
V_99 = V_101 && V_87 >= 0 ;
} else {
V_98 = F_77 ( V_96 ) ;
}
if ( V_98 && V_87 >= 0 ) {
V_87 = F_62 ( V_98 , V_86 , V_87 , V_89 ) ;
V_99 = V_87 >= 0 ;
}
F_76 ( V_98 ) ;
if ( V_99 && ! F_78 ( & V_96 -> V_97 , V_97 ) ) {
if ( F_79 ( V_96 ) ) {
if ( ! F_78 ( & V_96 -> V_97 , V_97 ) )
F_80 ( V_96 , NULL ) ;
F_81 ( V_96 ) ;
}
}
return V_87 ;
}
static void F_82 ( struct V_84 * V_85 , int V_102 )
{
struct V_90 * V_91 ;
struct V_103 * V_104 ;
if ( ! F_65 ( V_85 ) )
return;
V_91 = F_67 ( V_85 ) ;
V_104 = V_91 -> V_104 ;
if ( ! V_104 -> V_105 )
return;
V_104 -> V_105 ( V_91 , V_102 ) ;
}
static void F_83 ( struct V_84 * V_85 , int V_102 )
{
if ( F_84 ( V_85 ) ) {
struct V_106 * V_107 = F_85 ( V_85 ) ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_107 -> V_108 ; V_52 ++ )
F_82 ( V_107 -> V_109 [ V_52 ] , V_102 ) ;
} else {
F_82 ( V_85 , V_102 ) ;
}
}
int
F_86 ( struct V_1 * V_2 ,
unsigned int V_86 ,
int V_102 )
{
struct V_84 * V_98 ;
if ( V_86 & V_80 ) {
struct V_84 * * V_100 ;
unsigned int V_101 , V_52 ;
int V_23 ;
V_23 = F_75 ( V_2 -> V_96 ,
& V_98 , & V_101 , & V_100 ) ;
if ( V_23 )
return V_23 ;
for ( V_52 = 0 ; V_52 < V_101 ; V_52 ++ ) {
F_83 ( V_100 [ V_52 ] , V_102 ) ;
F_76 ( V_100 [ V_52 ] ) ;
}
F_39 ( V_100 ) ;
} else {
V_98 = F_77 ( V_2 -> V_96 ) ;
}
if ( V_98 ) {
F_83 ( V_98 , V_102 ) ;
F_76 ( V_98 ) ;
}
return 0 ;
}
int
F_56 ( struct V_1 * V_2 ,
unsigned int V_86 ,
long V_87 ,
struct V_88 * V_89 )
{
F_11 () ;
#if F_87 ( V_110 )
F_45 ( V_111 &&
! ! F_88 ( & V_2 -> V_12 . V_28 -> V_30 ) !=
! ! ( V_86 & V_79 ) ) ;
#endif
F_45 ( V_87 < 0 ) ;
V_87 = F_73 ( V_2 -> V_96 ,
V_86 , V_87 ,
V_89 ) ;
return V_87 < 0 ? V_87 : 0 ;
}
static struct V_88 * F_89 ( struct V_32 * V_33 )
{
struct V_112 * V_113 = V_33 -> V_114 ;
return & V_113 -> V_89 ;
}
static int
F_90 ( struct V_1 * V_2 ,
struct V_115 * args ,
struct V_32 * V_33 )
{
void * V_51 = V_2 -> V_64 -> V_51 + args -> V_61 ;
char T_4 * V_116 = F_91 ( args -> V_117 ) ;
F_92 ( V_2 , V_118 ) ;
if ( F_93 ( V_51 , V_116 , args -> V_11 ) )
return - V_119 ;
F_33 ( V_51 , args -> V_11 ) ;
F_36 ( F_16 ( V_2 -> V_12 . V_28 ) ) ;
F_94 ( V_2 , V_118 ) ;
return 0 ;
}
void * F_95 ( struct V_17 * V_18 )
{
return F_96 ( V_18 -> V_120 , V_59 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_16 ( V_2 -> V_12 . V_28 ) ;
F_98 ( V_18 -> V_120 , V_2 ) ;
}
static int
F_99 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
T_5 V_11 ,
T_6 * V_121 )
{
struct V_1 * V_2 ;
int V_23 ;
T_1 V_122 ;
V_11 = F_100 ( V_11 , V_55 ) ;
if ( V_11 == 0 )
return - V_53 ;
V_2 = F_101 ( V_18 , V_11 ) ;
if ( F_30 ( V_2 ) )
return F_102 ( V_2 ) ;
V_23 = F_103 ( V_33 , & V_2 -> V_12 , & V_122 ) ;
F_104 ( V_2 ) ;
if ( V_23 )
return V_23 ;
* V_121 = V_122 ;
return 0 ;
}
int
F_105 ( struct V_32 * V_33 ,
struct V_27 * V_28 ,
struct V_123 * args )
{
args -> V_124 = F_106 ( args -> V_125 * F_107 ( args -> V_126 , 8 ) , 64 ) ;
args -> V_11 = args -> V_124 * args -> V_127 ;
return F_99 ( V_33 , F_16 ( V_28 ) ,
args -> V_11 , & args -> V_122 ) ;
}
static bool F_108 ( struct V_1 * V_2 )
{
return ! ( V_2 -> V_128 == V_129 ||
V_2 -> V_128 == V_130 ) ;
}
int
F_109 ( struct V_27 * V_28 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_17 * V_18 = F_16 ( V_28 ) ;
struct V_131 * args = V_31 ;
F_110 ( V_18 ) ;
return F_99 ( V_33 , V_18 ,
args -> V_11 , & args -> V_122 ) ;
}
static inline enum V_132
F_111 ( struct V_1 * V_2 , unsigned int V_133 )
{
return ( V_133 == V_134 ?
V_2 -> V_135 : V_118 ) ;
}
static void
F_112 ( struct V_1 * V_2 , unsigned int V_136 )
{
struct V_17 * V_18 = F_16 ( V_2 -> V_12 . V_28 ) ;
if ( ! ( V_2 -> V_12 . V_67 & V_136 ) )
return;
F_113 () ;
switch ( V_2 -> V_12 . V_67 ) {
case V_134 :
if ( F_69 ( V_18 ) >= 6 && ! F_114 ( V_18 ) ) {
F_115 ( V_18 ) ;
F_116 ( & V_18 -> V_137 . V_138 ) ;
F_117 ( F_118 ( V_18 -> V_104 [ V_139 ] -> V_140 ) ) ;
F_119 ( & V_18 -> V_137 . V_138 ) ;
F_120 ( V_18 ) ;
}
F_94 ( V_2 ,
F_111 ( V_2 , V_134 ) ) ;
break;
case V_66 :
F_121 ( V_2 , V_141 ) ;
break;
case V_142 :
if ( F_108 ( V_2 ) )
V_2 -> V_3 = true ;
break;
}
V_2 -> V_12 . V_67 = 0 ;
}
static inline int
F_122 ( char T_4 * V_143 ,
const char * V_144 , int V_145 ,
int V_62 )
{
int V_23 , V_146 = 0 ;
while ( V_62 > 0 ) {
int V_147 = F_106 ( V_145 + 1 , 64 ) ;
int V_148 = F_123 ( V_147 - V_145 , V_62 ) ;
int V_149 = V_145 ^ 64 ;
V_23 = F_124 ( V_143 + V_146 ,
V_144 + V_149 ,
V_148 ) ;
if ( V_23 )
return V_23 + V_62 ;
V_146 += V_148 ;
V_145 += V_148 ;
V_62 -= V_148 ;
}
return 0 ;
}
static inline int
F_125 ( char * V_144 , int V_145 ,
const char T_4 * V_143 ,
int V_62 )
{
int V_23 , V_146 = 0 ;
while ( V_62 > 0 ) {
int V_147 = F_106 ( V_145 + 1 , 64 ) ;
int V_148 = F_123 ( V_147 - V_145 , V_62 ) ;
int V_149 = V_145 ^ 64 ;
V_23 = F_126 ( V_144 + V_149 ,
V_143 + V_146 ,
V_148 ) ;
if ( V_23 )
return V_23 + V_62 ;
V_146 += V_148 ;
V_145 += V_148 ;
V_62 -= V_148 ;
}
return 0 ;
}
int F_127 ( struct V_1 * V_2 ,
unsigned int * V_69 )
{
int V_23 ;
F_55 ( & V_2 -> V_12 . V_28 -> V_30 ) ;
* V_69 = 0 ;
if ( ! F_128 ( V_2 ) )
return - V_150 ;
V_23 = F_56 ( V_2 ,
V_78 |
V_79 ,
V_81 ,
NULL ) ;
if ( V_23 )
return V_23 ;
V_23 = F_129 ( V_2 ) ;
if ( V_23 )
return V_23 ;
if ( V_2 -> V_4 & V_74 ||
! F_130 ( V_151 ) ) {
V_23 = F_131 ( V_2 , false ) ;
if ( V_23 )
goto V_152;
else
goto V_93;
}
F_112 ( V_2 , ~ V_66 ) ;
if ( ! V_2 -> V_3 &&
! ( V_2 -> V_12 . V_65 & V_66 ) )
* V_69 = V_153 ;
V_93:
return 0 ;
V_152:
F_52 ( V_2 ) ;
return V_23 ;
}
int F_132 ( struct V_1 * V_2 ,
unsigned int * V_69 )
{
int V_23 ;
F_55 ( & V_2 -> V_12 . V_28 -> V_30 ) ;
* V_69 = 0 ;
if ( ! F_128 ( V_2 ) )
return - V_150 ;
V_23 = F_56 ( V_2 ,
V_78 |
V_79 |
V_80 ,
V_81 ,
NULL ) ;
if ( V_23 )
return V_23 ;
V_23 = F_129 ( V_2 ) ;
if ( V_23 )
return V_23 ;
if ( V_2 -> V_4 & V_5 ||
! F_130 ( V_151 ) ) {
V_23 = F_131 ( V_2 , true ) ;
if ( V_23 )
goto V_152;
else
goto V_93;
}
F_112 ( V_2 , ~ V_66 ) ;
if ( ! V_2 -> V_3 ) {
* V_69 |= V_154 ;
if ( ! ( V_2 -> V_12 . V_65 & V_66 ) )
* V_69 |= V_153 ;
}
V_93:
F_92 ( V_2 , V_118 ) ;
V_2 -> V_13 . V_73 = true ;
return 0 ;
V_152:
F_52 ( V_2 ) ;
return V_23 ;
}
static void
F_133 ( char * V_155 , unsigned long V_62 ,
bool V_156 )
{
if ( F_134 ( V_156 ) ) {
unsigned long V_157 = ( unsigned long ) V_155 ;
unsigned long V_158 = ( unsigned long ) V_155 + V_62 ;
V_157 = F_135 ( V_157 , 128 ) ;
V_158 = F_136 ( V_158 , 128 ) ;
F_33 ( ( void * ) V_157 , V_158 - V_157 ) ;
} else {
F_33 ( V_155 , V_62 ) ;
}
}
static int
F_137 ( struct V_56 * V_56 , int V_61 , int V_62 ,
char T_4 * V_116 ,
bool V_159 , bool V_69 )
{
char * V_51 ;
int V_23 ;
V_51 = F_138 ( V_56 ) ;
if ( V_69 )
F_133 ( V_51 + V_61 , V_62 ,
V_159 ) ;
if ( V_159 )
V_23 = F_122 ( V_116 , V_51 , V_61 , V_62 ) ;
else
V_23 = F_124 ( V_116 , V_51 + V_61 , V_62 ) ;
F_139 ( V_56 ) ;
return V_23 ? - V_119 : 0 ;
}
static int
F_140 ( struct V_56 * V_56 , int V_61 , int V_62 , char T_4 * V_116 ,
bool V_159 , bool V_69 )
{
int V_23 ;
V_23 = - V_150 ;
if ( ! V_159 ) {
char * V_51 = F_32 ( V_56 ) ;
if ( V_69 )
F_33 ( V_51 + V_61 , V_62 ) ;
V_23 = F_141 ( V_116 , V_51 + V_61 , V_62 ) ;
F_34 ( V_51 ) ;
}
if ( V_23 == 0 )
return 0 ;
return F_137 ( V_56 , V_61 , V_62 , V_116 ,
V_159 , V_69 ) ;
}
static int
F_142 ( struct V_1 * V_2 ,
struct V_160 * args )
{
char T_4 * V_116 ;
T_2 V_161 ;
unsigned int V_162 ;
unsigned int V_69 ;
unsigned int V_163 , V_61 ;
int V_23 ;
V_162 = 0 ;
if ( F_25 ( V_2 ) )
V_162 = F_143 ( 17 ) ;
V_23 = F_17 ( & V_2 -> V_12 . V_28 -> V_30 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_127 ( V_2 , & V_69 ) ;
F_22 ( & V_2 -> V_12 . V_28 -> V_30 ) ;
if ( V_23 )
return V_23 ;
V_161 = args -> V_11 ;
V_116 = F_91 ( args -> V_117 ) ;
V_61 = F_144 ( args -> V_61 ) ;
for ( V_163 = args -> V_61 >> V_164 ; V_161 ; V_163 ++ ) {
struct V_56 * V_56 = F_145 ( V_2 , V_163 ) ;
int V_62 ;
V_62 = V_161 ;
if ( V_61 + V_62 > V_55 )
V_62 = V_55 - V_61 ;
V_23 = F_140 ( V_56 , V_61 , V_62 , V_116 ,
F_146 ( V_56 ) & V_162 ,
V_69 ) ;
if ( V_23 )
break;
V_161 -= V_62 ;
V_116 += V_62 ;
V_61 = 0 ;
}
F_147 ( V_2 ) ;
return V_23 ;
}
static inline bool
F_148 ( struct V_165 * V_44 ,
T_7 V_12 , int V_61 ,
char T_4 * V_116 , int V_62 )
{
void * V_51 ;
unsigned long V_166 ;
V_51 = ( void V_167 * ) F_149 ( V_44 , V_12 ) ;
V_166 = F_141 ( V_116 , V_51 + V_61 , V_62 ) ;
F_150 ( V_51 ) ;
if ( V_166 ) {
V_51 = ( void V_167 * )
F_151 ( V_44 , V_12 , V_55 ) ;
V_166 = F_152 ( V_116 , V_51 + V_61 , V_62 ) ;
F_153 ( V_51 ) ;
}
return V_166 ;
}
static int
F_154 ( struct V_1 * V_2 ,
const struct V_160 * args )
{
struct V_17 * V_94 = F_16 ( V_2 -> V_12 . V_28 ) ;
struct V_7 * V_8 = & V_94 -> V_8 ;
struct V_9 V_10 ;
struct V_35 * V_36 ;
void T_4 * V_116 ;
T_2 V_161 , V_61 ;
int V_23 ;
V_23 = F_17 ( & V_94 -> V_168 . V_30 ) ;
if ( V_23 )
return V_23 ;
F_115 ( V_94 ) ;
V_36 = F_155 ( V_2 , NULL , 0 , 0 ,
V_169 | V_170 ) ;
if ( ! F_30 ( V_36 ) ) {
V_10 . V_157 = F_156 ( V_36 ) ;
V_10 . V_171 = false ;
V_23 = F_157 ( V_36 ) ;
if ( V_23 ) {
F_158 ( V_36 ) ;
V_36 = F_26 ( V_23 ) ;
}
}
if ( F_30 ( V_36 ) ) {
V_23 = F_2 ( V_8 , & V_10 , V_55 ) ;
if ( V_23 )
goto V_172;
F_45 ( ! V_10 . V_171 ) ;
}
V_23 = F_159 ( V_2 , false ) ;
if ( V_23 )
goto V_173;
F_22 ( & V_94 -> V_168 . V_30 ) ;
V_116 = F_91 ( args -> V_117 ) ;
V_161 = args -> V_11 ;
V_61 = args -> V_61 ;
while ( V_161 > 0 ) {
T_1 V_174 = V_10 . V_157 ;
unsigned V_175 = F_144 ( V_61 ) ;
unsigned V_176 = V_55 - V_175 ;
V_176 = V_161 < V_176 ? V_161 : V_176 ;
if ( V_10 . V_171 ) {
F_113 () ;
V_8 -> V_12 . V_177 ( & V_8 -> V_12 ,
F_160 ( V_2 , V_61 >> V_164 ) ,
V_10 . V_157 , V_129 , 0 ) ;
F_113 () ;
} else {
V_174 += V_61 & V_178 ;
}
if ( F_148 ( & V_8 -> V_179 , V_174 , V_175 ,
V_116 , V_176 ) ) {
V_23 = - V_119 ;
break;
}
V_161 -= V_176 ;
V_116 += V_176 ;
V_61 += V_176 ;
}
F_19 ( & V_94 -> V_168 . V_30 ) ;
V_173:
if ( V_10 . V_171 ) {
F_113 () ;
V_8 -> V_12 . V_180 ( & V_8 -> V_12 ,
V_10 . V_157 , V_10 . V_11 ) ;
F_4 ( & V_10 ) ;
} else {
F_158 ( V_36 ) ;
}
V_172:
F_120 ( V_94 ) ;
F_22 ( & V_94 -> V_168 . V_30 ) ;
return V_23 ;
}
int
F_161 ( struct V_27 * V_28 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_160 * args = V_31 ;
struct V_1 * V_2 ;
int V_23 ;
if ( args -> V_11 == 0 )
return 0 ;
if ( ! F_162 ( V_181 ,
F_91 ( args -> V_117 ) ,
args -> V_11 ) )
return - V_119 ;
V_2 = F_163 ( V_33 , args -> V_122 ) ;
if ( ! V_2 )
return - V_182 ;
if ( F_164 ( T_2 , args -> V_61 , args -> V_11 , V_2 -> V_12 . V_11 ) ) {
V_23 = - V_53 ;
goto V_93;
}
F_165 ( V_2 , args -> V_61 , args -> V_11 ) ;
V_23 = F_56 ( V_2 ,
V_78 ,
V_81 ,
F_89 ( V_33 ) ) ;
if ( V_23 )
goto V_93;
V_23 = F_129 ( V_2 ) ;
if ( V_23 )
goto V_93;
V_23 = F_142 ( V_2 , args ) ;
if ( V_23 == - V_119 || V_23 == - V_150 )
V_23 = F_154 ( V_2 , args ) ;
F_52 ( V_2 ) ;
V_93:
F_104 ( V_2 ) ;
return V_23 ;
}
static inline bool
F_166 ( struct V_165 * V_44 ,
T_7 V_12 , int V_61 ,
char T_4 * V_116 , int V_62 )
{
void * V_51 ;
unsigned long V_166 ;
V_51 = ( void V_167 * ) F_149 ( V_44 , V_12 ) ;
V_166 = F_167 ( V_51 + V_61 ,
V_116 , V_62 ) ;
F_150 ( V_51 ) ;
if ( V_166 ) {
V_51 = ( void V_167 * )
F_151 ( V_44 , V_12 , V_55 ) ;
V_166 = F_93 ( V_51 + V_61 , V_116 , V_62 ) ;
F_153 ( V_51 ) ;
}
return V_166 ;
}
static int
F_168 ( struct V_1 * V_2 ,
const struct V_115 * args )
{
struct V_17 * V_94 = F_16 ( V_2 -> V_12 . V_28 ) ;
struct V_7 * V_8 = & V_94 -> V_8 ;
struct V_9 V_10 ;
struct V_35 * V_36 ;
T_2 V_161 , V_61 ;
void T_4 * V_116 ;
int V_23 ;
V_23 = F_17 ( & V_94 -> V_168 . V_30 ) ;
if ( V_23 )
return V_23 ;
F_115 ( V_94 ) ;
V_36 = F_155 ( V_2 , NULL , 0 , 0 ,
V_169 | V_170 ) ;
if ( ! F_30 ( V_36 ) ) {
V_10 . V_157 = F_156 ( V_36 ) ;
V_10 . V_171 = false ;
V_23 = F_157 ( V_36 ) ;
if ( V_23 ) {
F_158 ( V_36 ) ;
V_36 = F_26 ( V_23 ) ;
}
}
if ( F_30 ( V_36 ) ) {
V_23 = F_2 ( V_8 , & V_10 , V_55 ) ;
if ( V_23 )
goto V_172;
F_45 ( ! V_10 . V_171 ) ;
}
V_23 = F_159 ( V_2 , true ) ;
if ( V_23 )
goto V_173;
F_22 ( & V_94 -> V_168 . V_30 ) ;
F_92 ( V_2 , V_118 ) ;
V_116 = F_91 ( args -> V_117 ) ;
V_61 = args -> V_61 ;
V_161 = args -> V_11 ;
while ( V_161 ) {
T_1 V_174 = V_10 . V_157 ;
unsigned int V_175 = F_144 ( V_61 ) ;
unsigned int V_176 = V_55 - V_175 ;
V_176 = V_161 < V_176 ? V_161 : V_176 ;
if ( V_10 . V_171 ) {
F_113 () ;
V_8 -> V_12 . V_177 ( & V_8 -> V_12 ,
F_160 ( V_2 , V_61 >> V_164 ) ,
V_10 . V_157 , V_129 , 0 ) ;
F_113 () ;
} else {
V_174 += V_61 & V_178 ;
}
if ( F_166 ( & V_8 -> V_179 , V_174 , V_175 ,
V_116 , V_176 ) ) {
V_23 = - V_119 ;
break;
}
V_161 -= V_176 ;
V_116 += V_176 ;
V_61 += V_176 ;
}
F_94 ( V_2 , V_118 ) ;
F_19 ( & V_94 -> V_168 . V_30 ) ;
V_173:
if ( V_10 . V_171 ) {
F_113 () ;
V_8 -> V_12 . V_180 ( & V_8 -> V_12 ,
V_10 . V_157 , V_10 . V_11 ) ;
F_4 ( & V_10 ) ;
} else {
F_158 ( V_36 ) ;
}
V_172:
F_120 ( V_94 ) ;
F_22 ( & V_94 -> V_168 . V_30 ) ;
return V_23 ;
}
static int
F_169 ( struct V_56 * V_56 , int V_61 , int V_62 ,
char T_4 * V_116 ,
bool V_159 ,
bool V_183 ,
bool V_184 )
{
char * V_51 ;
int V_23 ;
V_51 = F_138 ( V_56 ) ;
if ( F_134 ( V_183 || V_159 ) )
F_133 ( V_51 + V_61 , V_62 ,
V_159 ) ;
if ( V_159 )
V_23 = F_125 ( V_51 , V_61 , V_116 ,
V_62 ) ;
else
V_23 = F_126 ( V_51 + V_61 , V_116 , V_62 ) ;
if ( V_184 )
F_133 ( V_51 + V_61 , V_62 ,
V_159 ) ;
F_139 ( V_56 ) ;
return V_23 ? - V_119 : 0 ;
}
static int
F_170 ( struct V_56 * V_56 , int V_61 , int V_185 , char T_4 * V_116 ,
bool V_159 ,
bool V_183 ,
bool V_184 )
{
int V_23 ;
V_23 = - V_150 ;
if ( ! V_159 ) {
char * V_51 = F_32 ( V_56 ) ;
if ( V_183 )
F_33 ( V_51 + V_61 , V_185 ) ;
V_23 = F_171 ( V_51 + V_61 , V_116 , V_185 ) ;
if ( V_184 )
F_33 ( V_51 + V_61 , V_185 ) ;
F_34 ( V_51 ) ;
}
if ( V_23 == 0 )
return V_23 ;
return F_169 ( V_56 , V_61 , V_185 , V_116 ,
V_159 ,
V_183 ,
V_184 ) ;
}
static int
F_172 ( struct V_1 * V_2 ,
const struct V_115 * args )
{
struct V_17 * V_94 = F_16 ( V_2 -> V_12 . V_28 ) ;
void T_4 * V_116 ;
T_2 V_161 ;
unsigned int V_162 ;
unsigned int V_186 ;
unsigned int V_69 ;
unsigned int V_61 , V_163 ;
int V_23 ;
V_23 = F_17 ( & V_94 -> V_168 . V_30 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_132 ( V_2 , & V_69 ) ;
F_22 ( & V_94 -> V_168 . V_30 ) ;
if ( V_23 )
return V_23 ;
V_162 = 0 ;
if ( F_25 ( V_2 ) )
V_162 = F_143 ( 17 ) ;
V_186 = 0 ;
if ( V_69 & V_153 )
V_186 = V_187 . V_188 - 1 ;
V_116 = F_91 ( args -> V_117 ) ;
V_161 = args -> V_11 ;
V_61 = F_144 ( args -> V_61 ) ;
for ( V_163 = args -> V_61 >> V_164 ; V_161 ; V_163 ++ ) {
struct V_56 * V_56 = F_145 ( V_2 , V_163 ) ;
int V_62 ;
V_62 = V_161 ;
if ( V_61 + V_62 > V_55 )
V_62 = V_55 - V_61 ;
V_23 = F_170 ( V_56 , V_61 , V_62 , V_116 ,
F_146 ( V_56 ) & V_162 ,
( V_61 | V_62 ) & V_186 ,
V_69 & V_154 ) ;
if ( V_23 )
break;
V_161 -= V_62 ;
V_116 += V_62 ;
V_61 = 0 ;
}
F_94 ( V_2 , V_118 ) ;
F_147 ( V_2 ) ;
return V_23 ;
}
int
F_173 ( struct V_27 * V_28 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_115 * args = V_31 ;
struct V_1 * V_2 ;
int V_23 ;
if ( args -> V_11 == 0 )
return 0 ;
if ( ! F_162 ( V_189 ,
F_91 ( args -> V_117 ) ,
args -> V_11 ) )
return - V_119 ;
V_2 = F_163 ( V_33 , args -> V_122 ) ;
if ( ! V_2 )
return - V_182 ;
if ( F_164 ( T_2 , args -> V_61 , args -> V_11 , V_2 -> V_12 . V_11 ) ) {
V_23 = - V_53 ;
goto V_190;
}
F_174 ( V_2 , args -> V_61 , args -> V_11 ) ;
V_23 = - V_150 ;
if ( V_2 -> V_191 -> V_192 )
V_23 = V_2 -> V_191 -> V_192 ( V_2 , args ) ;
if ( V_23 != - V_150 )
goto V_190;
V_23 = F_56 ( V_2 ,
V_78 |
V_80 ,
V_81 ,
F_89 ( V_33 ) ) ;
if ( V_23 )
goto V_190;
V_23 = F_129 ( V_2 ) ;
if ( V_23 )
goto V_190;
V_23 = - V_119 ;
if ( ! F_128 ( V_2 ) ||
F_1 ( V_2 ) )
V_23 = F_168 ( V_2 , args ) ;
if ( V_23 == - V_119 || V_23 == - V_193 ) {
if ( V_2 -> V_64 )
V_23 = F_90 ( V_2 , args , V_33 ) ;
else
V_23 = F_172 ( V_2 , args ) ;
}
F_52 ( V_2 ) ;
V_190:
F_104 ( V_2 ) ;
return V_23 ;
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_17 * V_94 ;
struct V_194 * V_195 ;
struct V_35 * V_36 ;
F_20 (vma, &obj->vma_list, obj_link) {
if ( ! F_176 ( V_36 ) )
break;
if ( F_177 ( V_36 ) )
continue;
if ( ! F_178 ( & V_36 -> V_10 ) )
continue;
F_59 ( & V_36 -> V_196 , & V_36 -> V_197 -> V_198 ) ;
}
V_94 = F_16 ( V_2 -> V_12 . V_28 ) ;
V_195 = V_2 -> V_199 ? & V_94 -> V_13 . V_200 : & V_94 -> V_13 . V_201 ;
F_59 ( & V_2 -> V_202 , V_195 ) ;
}
int
F_179 ( struct V_27 * V_28 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_203 * args = V_31 ;
struct V_1 * V_2 ;
T_6 V_65 = args -> V_65 ;
T_6 V_67 = args -> V_67 ;
int V_190 ;
if ( ( V_67 | V_65 ) & V_204 )
return - V_53 ;
if ( V_67 != 0 && V_65 != V_67 )
return - V_53 ;
V_2 = F_163 ( V_33 , args -> V_122 ) ;
if ( ! V_2 )
return - V_182 ;
V_190 = F_56 ( V_2 ,
V_78 |
( V_67 ? V_80 : 0 ) ,
V_81 ,
F_89 ( V_33 ) ) ;
if ( V_190 )
goto V_93;
V_190 = F_129 ( V_2 ) ;
if ( V_190 )
goto V_93;
V_190 = F_15 ( V_28 ) ;
if ( V_190 )
goto V_173;
if ( V_65 & V_205 )
V_190 = F_180 ( V_2 , V_67 ) ;
else if ( V_65 & V_134 )
V_190 = F_159 ( V_2 , V_67 ) ;
else
V_190 = F_131 ( V_2 , V_67 ) ;
F_175 ( V_2 ) ;
F_22 ( & V_28 -> V_30 ) ;
if ( V_67 != 0 )
F_92 ( V_2 ,
F_111 ( V_2 , V_67 ) ) ;
V_173:
F_52 ( V_2 ) ;
V_93:
F_104 ( V_2 ) ;
return V_190 ;
}
int
F_181 ( struct V_27 * V_28 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_206 * args = V_31 ;
struct V_1 * V_2 ;
V_2 = F_163 ( V_33 , args -> V_122 ) ;
if ( ! V_2 )
return - V_182 ;
F_182 ( V_2 ) ;
F_104 ( V_2 ) ;
return 0 ;
}
int
F_183 ( struct V_27 * V_28 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_207 * args = V_31 ;
struct V_1 * V_2 ;
unsigned long V_155 ;
if ( args -> V_86 & ~ ( V_208 ) )
return - V_53 ;
if ( args -> V_86 & V_208 && ! F_184 ( V_209 ) )
return - V_150 ;
V_2 = F_163 ( V_33 , args -> V_122 ) ;
if ( ! V_2 )
return - V_182 ;
if ( ! V_2 -> V_12 . V_45 ) {
F_104 ( V_2 ) ;
return - V_53 ;
}
V_155 = F_185 ( V_2 -> V_12 . V_45 , 0 , args -> V_11 ,
V_210 | V_211 , V_212 ,
args -> V_61 ) ;
if ( args -> V_86 & V_208 ) {
struct V_213 * V_13 = V_214 -> V_13 ;
struct V_215 * V_36 ;
if ( F_186 ( & V_13 -> V_216 ) ) {
F_104 ( V_2 ) ;
return - V_217 ;
}
V_36 = F_187 ( V_13 , V_155 ) ;
if ( V_36 )
V_36 -> V_218 =
F_188 ( F_189 ( V_36 -> V_219 ) ) ;
else
V_155 = - V_54 ;
F_190 ( & V_13 -> V_216 ) ;
F_191 ( V_2 -> V_135 , V_118 ) ;
}
F_104 ( V_2 ) ;
if ( F_30 ( ( void * ) V_155 ) )
return V_155 ;
args -> V_220 = ( T_5 ) V_155 ;
return 0 ;
}
static unsigned int F_192 ( struct V_1 * V_2 )
{
return F_193 ( V_2 ) >> V_164 ;
}
int F_194 ( void )
{
return 2 ;
}
static inline struct V_221
F_195 ( struct V_1 * V_2 ,
T_8 V_175 ,
unsigned int V_222 )
{
struct V_221 V_223 ;
if ( F_196 ( V_2 ) )
V_222 = F_100 ( V_222 , F_192 ( V_2 ) ) ;
V_223 . type = V_224 ;
V_223 . V_225 . V_61 = F_197 ( V_175 , V_222 ) ;
V_223 . V_225 . V_11 =
F_198 (unsigned int, chunk,
(obj->base.size >> PAGE_SHIFT) - view.partial.offset) ;
if ( V_222 >= V_2 -> V_12 . V_11 >> V_164 )
V_223 . type = V_226 ;
return V_223 ;
}
int F_199 ( struct V_227 * V_228 )
{
#define F_200 ((1 << 20) >> PAGE_SHIFT)
struct V_215 * V_229 = V_228 -> V_36 ;
struct V_1 * V_2 = F_201 ( V_229 -> V_230 ) ;
struct V_27 * V_28 = V_2 -> V_12 . V_28 ;
struct V_17 * V_18 = F_16 ( V_28 ) ;
struct V_7 * V_8 = & V_18 -> V_8 ;
bool V_231 = ! ! ( V_228 -> V_86 & V_232 ) ;
struct V_35 * V_36 ;
T_8 V_175 ;
unsigned int V_86 ;
int V_23 ;
V_175 = ( V_228 -> V_233 - V_229 -> V_234 ) >> V_164 ;
F_202 ( V_2 , V_175 , true , V_231 ) ;
V_23 = F_56 ( V_2 ,
V_78 ,
V_81 ,
NULL ) ;
if ( V_23 )
goto V_190;
V_23 = F_129 ( V_2 ) ;
if ( V_23 )
goto V_190;
F_115 ( V_18 ) ;
V_23 = F_15 ( V_28 ) ;
if ( V_23 )
goto V_235;
if ( V_2 -> V_128 != V_129 && ! F_114 ( V_18 ) ) {
V_23 = - V_119 ;
goto V_236;
}
V_86 = V_169 ;
if ( V_2 -> V_12 . V_11 > 2 * F_200 << V_164 )
V_86 |= V_170 | V_237 ;
V_36 = F_155 ( V_2 , NULL , 0 , 0 , V_86 ) ;
if ( F_30 ( V_36 ) ) {
struct V_221 V_223 =
F_195 ( V_2 , V_175 , F_200 ) ;
V_2 -> V_135 = V_118 ;
V_36 = F_155 ( V_2 , & V_223 , 0 , 0 , V_169 ) ;
}
if ( F_30 ( V_36 ) ) {
V_23 = F_102 ( V_36 ) ;
goto V_236;
}
V_23 = F_159 ( V_2 , V_231 ) ;
if ( V_23 )
goto V_152;
V_23 = F_203 ( V_36 ) ;
if ( V_23 )
goto V_152;
F_204 ( V_18 ) ;
if ( F_205 ( & V_2 -> V_238 ) )
F_206 ( & V_2 -> V_238 , & V_18 -> V_13 . V_239 ) ;
V_23 = F_207 ( V_229 ,
V_229 -> V_234 + ( V_36 -> V_240 . V_225 . V_61 << V_164 ) ,
( V_8 -> V_241 + V_36 -> V_10 . V_157 ) >> V_164 ,
F_198 ( T_2 , V_36 -> V_11 , V_229 -> V_242 - V_229 -> V_234 ) ,
& V_8 -> V_179 ) ;
V_152:
F_208 ( V_36 ) ;
V_236:
F_22 ( & V_28 -> V_30 ) ;
V_235:
F_120 ( V_18 ) ;
F_52 ( V_2 ) ;
V_190:
switch ( V_23 ) {
case - V_26 :
if ( ! F_209 ( & V_18 -> V_29 ) ) {
V_23 = V_243 ;
break;
}
case - V_244 :
case 0 :
case - V_245 :
case - V_217 :
case - V_246 :
V_23 = V_247 ;
break;
case - V_54 :
V_23 = V_248 ;
break;
case - V_193 :
case - V_119 :
V_23 = V_243 ;
break;
default:
F_210 ( V_23 , L_2 , V_23 ) ;
V_23 = V_243 ;
break;
}
return V_23 ;
}
void
F_211 ( struct V_1 * V_2 )
{
struct V_17 * V_94 = F_16 ( V_2 -> V_12 . V_28 ) ;
F_55 ( & V_94 -> V_168 . V_30 ) ;
F_115 ( V_94 ) ;
if ( F_205 ( & V_2 -> V_238 ) )
goto V_93;
F_212 ( & V_2 -> V_238 ) ;
F_213 ( & V_2 -> V_12 . V_249 ,
V_2 -> V_12 . V_28 -> V_250 -> V_251 ) ;
F_113 () ;
V_93:
F_120 ( V_94 ) ;
}
void F_214 ( struct V_17 * V_18 )
{
struct V_1 * V_2 , * V_252 ;
int V_52 ;
F_215 (obj, on,
&dev_priv->mm.userfault_list, userfault_link) {
F_212 ( & V_2 -> V_238 ) ;
F_213 ( & V_2 -> V_12 . V_249 ,
V_2 -> V_12 . V_28 -> V_250 -> V_251 ) ;
}
for ( V_52 = 0 ; V_52 < V_18 -> V_253 ; V_52 ++ ) {
struct V_254 * V_255 = & V_18 -> V_256 [ V_52 ] ;
if ( ! V_255 -> V_36 )
continue;
F_45 ( ! F_205 ( & V_255 -> V_36 -> V_2 -> V_238 ) ) ;
V_255 -> V_73 = true ;
}
}
static int F_216 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_16 ( V_2 -> V_12 . V_28 ) ;
int V_190 ;
V_190 = F_217 ( & V_2 -> V_12 ) ;
if ( F_218 ( ! V_190 ) )
return 0 ;
do {
V_190 = F_219 ( V_18 , V_78 ) ;
if ( V_190 )
break;
F_220 ( V_18 ) ;
V_190 = F_217 ( & V_2 -> V_12 ) ;
if ( ! V_190 )
break;
} while ( F_221 ( & V_18 -> V_257 . V_258 ) );
return V_190 ;
}
static void F_222 ( struct V_1 * V_2 )
{
F_223 ( & V_2 -> V_12 ) ;
}
int
F_224 ( struct V_32 * V_33 ,
struct V_27 * V_28 ,
T_6 V_122 ,
T_5 * V_61 )
{
struct V_1 * V_2 ;
int V_23 ;
V_2 = F_163 ( V_33 , V_122 ) ;
if ( ! V_2 )
return - V_182 ;
V_23 = F_216 ( V_2 ) ;
if ( V_23 == 0 )
* V_61 = F_225 ( & V_2 -> V_12 . V_249 ) ;
F_104 ( V_2 ) ;
return V_23 ;
}
int
F_226 ( struct V_27 * V_28 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_259 * args = V_31 ;
return F_224 ( V_33 , V_28 , args -> V_122 , & args -> V_61 ) ;
}
static void
F_227 ( struct V_1 * V_2 )
{
F_222 ( V_2 ) ;
if ( V_2 -> V_12 . V_45 == NULL )
return;
F_228 ( F_229 ( V_2 -> V_12 . V_45 ) , 0 , ( T_7 ) - 1 ) ;
V_2 -> V_13 . V_70 = V_71 ;
V_2 -> V_13 . V_68 = F_26 ( - V_119 ) ;
}
void F_230 ( struct V_1 * V_2 )
{
struct V_43 * V_44 ;
F_55 ( & V_2 -> V_13 . V_138 ) ;
F_45 ( V_2 -> V_13 . V_68 ) ;
switch ( V_2 -> V_13 . V_70 ) {
case V_72 :
F_227 ( V_2 ) ;
case V_71 :
return;
}
if ( V_2 -> V_12 . V_45 == NULL )
return;
V_44 = V_2 -> V_12 . V_45 -> V_46 ,
F_231 ( V_44 , 0 , ( T_7 ) - 1 ) ;
}
static void
F_232 ( struct V_1 * V_2 ,
struct V_42 * V_68 )
{
struct V_260 V_260 ;
struct V_56 * V_56 ;
F_44 ( V_2 , V_68 , true ) ;
F_233 ( V_2 , V_68 ) ;
if ( F_25 ( V_2 ) )
F_234 ( V_2 , V_68 ) ;
F_235 (page, sgt_iter, pages) {
if ( V_2 -> V_13 . V_73 )
F_48 ( V_56 ) ;
if ( V_2 -> V_13 . V_70 == V_76 )
F_49 ( V_56 ) ;
F_35 ( V_56 ) ;
}
V_2 -> V_13 . V_73 = false ;
F_50 ( V_68 ) ;
F_39 ( V_68 ) ;
}
static void F_236 ( struct V_1 * V_2 )
{
struct V_261 V_262 ;
void T_9 * * V_263 ;
F_237 () ;
F_238 (slot, &obj->mm.get_page.radix, &iter, 0 )
F_239 ( & V_2 -> V_13 . V_264 . V_265 , V_262 . V_266 ) ;
F_240 () ;
}
void F_241 ( struct V_1 * V_2 ,
enum V_267 V_268 )
{
struct V_42 * V_68 ;
if ( F_242 ( V_2 ) )
return;
F_45 ( V_2 -> V_199 ) ;
if ( ! F_243 ( V_2 -> V_13 . V_68 ) )
return;
F_244 ( & V_2 -> V_13 . V_138 , V_268 ) ;
if ( F_134 ( F_245 ( & V_2 -> V_13 . V_269 ) ) )
goto V_270;
V_68 = F_246 ( & V_2 -> V_13 . V_68 ) ;
F_45 ( ! V_68 ) ;
if ( V_2 -> V_13 . V_44 ) {
void * V_271 ;
V_271 = F_247 ( V_2 -> V_13 . V_44 ) ;
if ( F_248 ( V_271 ) )
F_249 ( V_271 ) ;
else
F_139 ( F_250 ( V_271 ) ) ;
V_2 -> V_13 . V_44 = NULL ;
}
F_236 ( V_2 ) ;
if ( ! F_30 ( V_68 ) )
V_2 -> V_191 -> V_272 ( V_2 , V_68 ) ;
V_270:
F_22 ( & V_2 -> V_13 . V_138 ) ;
}
static bool F_251 ( struct V_42 * V_273 )
{
struct V_42 V_274 ;
struct V_49 * V_50 , * V_275 ;
unsigned int V_52 ;
if ( V_273 -> V_276 == V_273 -> V_277 )
return false ;
if ( F_38 ( & V_274 , V_273 -> V_276 , V_59 | V_278 ) )
return false ;
V_275 = V_274 . V_60 ;
F_252 (orig_st->sgl, sg, orig_st->nents, i) {
F_253 ( V_275 , F_254 ( V_50 ) , V_50 -> V_62 , 0 ) ;
V_275 = F_255 ( V_275 ) ;
}
F_45 ( V_275 ) ;
F_50 ( V_273 ) ;
* V_273 = V_274 ;
return true ;
}
static struct V_42 *
F_256 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_16 ( V_2 -> V_12 . V_28 ) ;
const unsigned long V_279 = V_2 -> V_12 . V_11 / V_55 ;
unsigned long V_52 ;
struct V_43 * V_44 ;
struct V_42 * V_48 ;
struct V_49 * V_50 ;
struct V_260 V_260 ;
struct V_56 * V_56 ;
unsigned long V_280 = 0 ;
unsigned int V_281 ;
T_10 V_282 ;
int V_23 ;
F_45 ( V_2 -> V_12 . V_65 & V_204 ) ;
F_45 ( V_2 -> V_12 . V_67 & V_204 ) ;
V_281 = F_257 () ;
if ( ! V_281 )
V_281 = F_197 ( V_283 , V_55 ) ;
V_48 = F_37 ( sizeof( * V_48 ) , V_59 ) ;
if ( V_48 == NULL )
return F_26 ( - V_54 ) ;
V_284:
if ( F_38 ( V_48 , V_279 , V_59 ) ) {
F_39 ( V_48 ) ;
return F_26 ( - V_54 ) ;
}
V_44 = V_2 -> V_12 . V_45 -> V_46 ;
V_282 = F_258 ( V_44 , ~ V_285 ) ;
V_282 |= V_286 | V_278 ;
V_50 = V_48 -> V_60 ;
V_48 -> V_276 = 0 ;
for ( V_52 = 0 ; V_52 < V_279 ; V_52 ++ ) {
const unsigned int V_287 [] = {
V_288 | V_289 | V_290 ,
0 ,
} , * V_291 = V_287 ;
T_10 V_292 = V_282 ;
do {
V_56 = F_259 ( V_44 , V_52 , V_292 ) ;
if ( F_218 ( ! F_30 ( V_56 ) ) )
break;
if ( ! * V_291 ) {
V_23 = F_102 ( V_56 ) ;
goto V_293;
}
F_260 ( V_18 , 2 * V_279 , NULL , * V_291 ++ ) ;
F_261 () ;
if ( ! * V_291 ) {
V_292 = F_262 ( V_44 ) ;
V_292 |= V_294 ;
}
} while ( 1 );
if ( ! V_52 ||
V_50 -> V_62 >= V_281 ||
F_263 ( V_56 ) != V_280 + 1 ) {
if ( V_52 )
V_50 = F_255 ( V_50 ) ;
V_48 -> V_276 ++ ;
F_253 ( V_50 , V_56 , V_55 , 0 ) ;
} else {
V_50 -> V_62 += V_55 ;
}
V_280 = F_263 ( V_56 ) ;
F_24 ( ( V_292 & V_295 ) && ( V_280 >= 0x00100000UL ) ) ;
}
if ( V_50 )
F_264 ( V_50 ) ;
F_251 ( V_48 ) ;
V_23 = F_265 ( V_2 , V_48 ) ;
if ( V_23 ) {
if ( V_281 > V_55 ) {
F_235 (page, sgt_iter, st)
F_35 ( V_56 ) ;
F_50 ( V_48 ) ;
V_281 = V_55 ;
goto V_284;
} else {
F_266 ( & V_18 -> V_168 . V_296 -> V_28 ,
L_3 ,
V_279 ) ;
goto V_297;
}
}
if ( F_25 ( V_2 ) )
F_267 ( V_2 , V_48 ) ;
return V_48 ;
V_293:
F_264 ( V_50 ) ;
V_297:
F_235 (page, sgt_iter, st)
F_35 ( V_56 ) ;
F_50 ( V_48 ) ;
F_39 ( V_48 ) ;
if ( V_23 == - V_193 )
V_23 = - V_54 ;
return F_26 ( V_23 ) ;
}
void F_268 ( struct V_1 * V_2 ,
struct V_42 * V_68 )
{
F_55 ( & V_2 -> V_13 . V_138 ) ;
V_2 -> V_13 . V_264 . V_298 = V_68 -> V_60 ;
V_2 -> V_13 . V_264 . V_299 = 0 ;
V_2 -> V_13 . V_68 = V_68 ;
if ( F_196 ( V_2 ) &&
F_16 ( V_2 -> V_12 . V_28 ) -> V_300 & V_301 ) {
F_45 ( V_2 -> V_13 . V_302 ) ;
F_269 ( V_2 ) ;
V_2 -> V_13 . V_302 = true ;
}
}
static int F_270 ( struct V_1 * V_2 )
{
struct V_42 * V_68 ;
F_45 ( F_242 ( V_2 ) ) ;
if ( F_134 ( V_2 -> V_13 . V_70 != V_76 ) ) {
F_271 ( L_4 ) ;
return - V_119 ;
}
V_68 = V_2 -> V_191 -> V_303 ( V_2 ) ;
if ( F_134 ( F_30 ( V_68 ) ) )
return F_102 ( V_68 ) ;
F_268 ( V_2 , V_68 ) ;
return 0 ;
}
int F_272 ( struct V_1 * V_2 )
{
int V_190 ;
V_190 = F_17 ( & V_2 -> V_13 . V_138 ) ;
if ( V_190 )
return V_190 ;
if ( F_134 ( F_273 ( V_2 -> V_13 . V_68 ) ) ) {
V_190 = F_270 ( V_2 ) ;
if ( V_190 )
goto V_270;
F_274 () ;
}
F_275 ( & V_2 -> V_13 . V_269 ) ;
V_270:
F_22 ( & V_2 -> V_13 . V_138 ) ;
return V_190 ;
}
static void * F_276 ( const struct V_1 * V_2 ,
enum V_304 type )
{
unsigned long V_305 = V_2 -> V_12 . V_11 >> V_164 ;
struct V_42 * V_306 = V_2 -> V_13 . V_68 ;
struct V_260 V_260 ;
struct V_56 * V_56 ;
struct V_56 * V_307 [ 32 ] ;
struct V_56 * * V_68 = V_307 ;
unsigned long V_52 = 0 ;
T_11 V_308 ;
void * V_155 ;
if ( V_305 == 1 && type == V_309 )
return F_138 ( F_254 ( V_306 -> V_60 ) ) ;
if ( V_305 > F_277 ( V_307 ) ) {
V_68 = F_278 ( V_305 , sizeof( * V_68 ) , V_59 ) ;
if ( ! V_68 )
return NULL ;
}
F_235 (page, sgt_iter, sgt)
V_68 [ V_52 ++ ] = V_56 ;
F_45 ( V_52 != V_305 ) ;
switch ( type ) {
default:
F_279 ( type ) ;
case V_309 :
V_308 = V_310 ;
break;
case V_311 :
V_308 = F_188 ( V_312 ) ;
break;
}
V_155 = F_280 ( V_68 , V_305 , 0 , V_308 ) ;
if ( V_68 != V_307 )
F_281 ( V_68 ) ;
return V_155 ;
}
void * F_282 ( struct V_1 * V_2 ,
enum V_304 type )
{
enum V_304 V_313 ;
bool V_37 ;
void * V_271 ;
int V_23 ;
F_45 ( ! F_128 ( V_2 ) ) ;
V_23 = F_17 ( & V_2 -> V_13 . V_138 ) ;
if ( V_23 )
return F_26 ( V_23 ) ;
V_37 = ! ( type & V_314 ) ;
type &= ~ V_314 ;
if ( ! F_283 ( & V_2 -> V_13 . V_269 ) ) {
if ( F_134 ( F_273 ( V_2 -> V_13 . V_68 ) ) ) {
V_23 = F_270 ( V_2 ) ;
if ( V_23 )
goto V_236;
F_274 () ;
}
F_275 ( & V_2 -> V_13 . V_269 ) ;
V_37 = false ;
}
F_45 ( ! V_2 -> V_13 . V_68 ) ;
V_271 = F_284 ( V_2 -> V_13 . V_44 , & V_313 ) ;
if ( V_271 && V_313 != type ) {
if ( V_37 ) {
V_23 = - V_246 ;
goto V_152;
}
if ( F_248 ( V_271 ) )
F_249 ( V_271 ) ;
else
F_139 ( F_250 ( V_271 ) ) ;
V_271 = V_2 -> V_13 . V_44 = NULL ;
}
if ( ! V_271 ) {
V_271 = F_276 ( V_2 , type ) ;
if ( ! V_271 ) {
V_23 = - V_54 ;
goto V_152;
}
V_2 -> V_13 . V_44 = F_285 ( V_271 , type ) ;
}
V_172:
F_22 ( & V_2 -> V_13 . V_138 ) ;
return V_271 ;
V_152:
F_286 ( & V_2 -> V_13 . V_269 ) ;
V_236:
V_271 = F_26 ( V_23 ) ;
goto V_172;
}
static int
F_287 ( struct V_1 * V_2 ,
const struct V_115 * V_315 )
{
struct V_43 * V_44 = V_2 -> V_12 . V_45 -> V_46 ;
char T_4 * V_116 = F_91 ( V_315 -> V_117 ) ;
T_2 V_161 , V_61 ;
unsigned int V_316 ;
if ( F_243 ( V_2 -> V_13 . V_68 ) )
return - V_150 ;
if ( V_2 -> V_13 . V_70 != V_76 )
return - V_119 ;
V_161 = V_315 -> V_11 ;
V_61 = V_315 -> V_61 ;
V_316 = F_144 ( V_61 ) ;
do {
unsigned int V_185 , V_166 ;
struct V_56 * V_56 ;
void * V_31 , * V_51 ;
int V_190 ;
V_185 = V_55 - V_316 ;
if ( V_185 > V_161 )
V_185 = V_161 ;
V_190 = F_288 ( V_2 -> V_12 . V_45 , V_44 ,
V_61 , V_185 , 0 ,
& V_56 , & V_31 ) ;
if ( V_190 < 0 )
return V_190 ;
V_51 = F_138 ( V_56 ) ;
V_166 = F_93 ( V_51 + V_316 , V_116 , V_185 ) ;
F_139 ( V_56 ) ;
V_190 = F_289 ( V_2 -> V_12 . V_45 , V_44 ,
V_61 , V_185 , V_185 - V_166 ,
V_56 , V_31 ) ;
if ( V_190 < 0 )
return V_190 ;
if ( V_166 )
return - V_119 ;
V_161 -= V_185 ;
V_116 += V_185 ;
V_61 += V_185 ;
V_316 = 0 ;
} while ( V_161 );
return 0 ;
}
static bool F_290 ( const struct V_317 * V_318 ,
unsigned int V_319 )
{
return ( F_291 ( V_318 ) &&
V_319 >= V_320 ) ;
}
static void F_292 ( struct V_317 * V_318 )
{
unsigned int V_319 ;
bool V_321 ;
F_275 ( & V_318 -> V_322 ) ;
V_319 = F_293 ( V_323 , & V_318 -> V_324 ) ;
V_321 = F_290 ( V_318 , V_319 ) ;
F_294 ( L_5 ,
V_318 -> V_325 , V_319 , F_295 ( V_321 ) ) ;
if ( ! V_321 )
return;
F_296 ( V_318 ) ;
if ( ! F_273 ( V_318 -> V_326 ) ) {
F_275 ( & V_318 -> V_326 -> V_327 ) ;
F_294 ( L_6 ,
V_318 -> V_325 , F_245 ( & V_318 -> V_326 -> V_327 ) ) ;
}
}
static void F_297 ( struct V_317 * V_318 )
{
F_275 ( & V_318 -> V_328 ) ;
}
struct V_90 *
F_298 ( struct V_103 * V_104 )
{
struct V_90 * V_329 , * V_330 = NULL ;
unsigned long V_86 ;
F_299 ( & V_104 -> V_331 -> V_138 , V_86 ) ;
F_20 (request, &engine->timeline->requests, link) {
if ( F_300 ( V_329 ,
V_329 -> V_332 ) )
continue;
F_45 ( V_329 -> V_104 != V_104 ) ;
F_45 ( F_64 ( V_92 ,
& V_329 -> V_85 . V_86 ) ) ;
V_330 = V_329 ;
break;
}
F_301 ( & V_104 -> V_331 -> V_138 , V_86 ) ;
return V_330 ;
}
static bool F_302 ( struct V_103 * V_104 )
{
if ( ! V_104 -> V_333 . V_334 )
return false ;
if ( V_104 -> V_333 . V_335 != F_303 ( V_104 ) ) {
F_294 ( L_7 , V_104 -> V_325 ) ;
return false ;
}
return true ;
}
struct V_90 *
F_304 ( struct V_103 * V_104 )
{
struct V_90 * V_329 = NULL ;
F_305 ( V_104 -> V_336 . V_337 ) ;
F_306 ( & V_104 -> V_338 ) ;
F_307 ( & V_104 -> V_338 ) ;
if ( V_104 -> V_339 )
V_104 -> V_339 ( V_104 ) ;
V_329 = F_298 ( V_104 ) ;
if ( V_329 && V_329 -> V_85 . error == - V_26 )
V_329 = F_26 ( - V_26 ) ;
return V_329 ;
}
int F_308 ( struct V_17 * V_18 )
{
struct V_103 * V_104 ;
struct V_90 * V_329 ;
enum V_340 V_341 ;
int V_190 = 0 ;
F_309 (engine, dev_priv, id) {
V_329 = F_304 ( V_104 ) ;
if ( F_30 ( V_329 ) ) {
V_190 = F_102 ( V_329 ) ;
continue;
}
V_104 -> V_333 . V_342 = V_329 ;
}
F_310 ( V_18 ) ;
return V_190 ;
}
static void F_311 ( struct V_90 * V_329 )
{
void * V_51 = V_329 -> V_343 -> V_51 ;
T_1 V_344 ;
V_344 = V_329 -> V_344 ;
if ( V_329 -> V_345 < V_344 ) {
memset ( V_51 + V_344 , 0 , V_329 -> V_343 -> V_11 - V_344 ) ;
V_344 = 0 ;
}
memset ( V_51 + V_344 , 0 , V_329 -> V_345 - V_344 ) ;
F_312 ( & V_329 -> V_85 , - V_26 ) ;
}
static void F_313 ( struct V_90 * V_329 )
{
struct V_103 * V_104 = V_329 -> V_104 ;
struct V_317 * V_346 = V_329 -> V_318 ;
struct V_347 * V_331 ;
unsigned long V_86 ;
V_331 = F_314 ( V_346 , V_104 ) ;
F_299 ( & V_104 -> V_331 -> V_138 , V_86 ) ;
F_7 ( & V_331 -> V_138 ) ;
F_315 (request, &engine->timeline->requests, link)
if ( V_329 -> V_318 == V_346 )
F_311 ( V_329 ) ;
F_20 (request, &timeline->requests, link)
F_311 ( V_329 ) ;
F_8 ( & V_331 -> V_138 ) ;
F_301 ( & V_104 -> V_331 -> V_138 , V_86 ) ;
}
static struct V_90 *
F_316 ( struct V_103 * V_104 ,
struct V_90 * V_329 )
{
if ( F_302 ( V_104 ) ) {
F_292 ( V_329 -> V_318 ) ;
F_311 ( V_329 ) ;
if ( F_317 ( V_329 -> V_318 ) )
F_313 ( V_329 ) ;
} else {
V_329 = F_298 ( V_104 ) ;
if ( V_329 ) {
F_297 ( V_329 -> V_318 ) ;
F_312 ( & V_329 -> V_85 , - V_244 ) ;
F_116 ( & V_104 -> V_331 -> V_138 ) ;
V_329 = F_318 ( V_329 , V_348 ) ;
if ( & V_329 -> V_348 == & V_104 -> V_331 -> V_349 )
V_329 = NULL ;
F_119 ( & V_104 -> V_331 -> V_138 ) ;
}
}
return V_329 ;
}
void F_319 ( struct V_103 * V_104 ,
struct V_90 * V_329 )
{
V_104 -> V_350 = 0 ;
if ( V_329 )
V_329 = F_316 ( V_104 , V_329 ) ;
if ( V_329 ) {
F_294 ( L_8 ,
V_104 -> V_325 , V_329 -> V_332 ) ;
}
V_104 -> V_351 ( V_104 , V_329 ) ;
}
void F_320 ( struct V_17 * V_18 )
{
struct V_103 * V_104 ;
enum V_340 V_341 ;
F_55 ( & V_18 -> V_168 . V_30 ) ;
F_57 ( V_18 ) ;
F_309 (engine, dev_priv, id) {
struct V_317 * V_318 ;
F_319 ( V_104 , V_104 -> V_333 . V_342 ) ;
V_318 = F_246 ( & V_104 -> V_352 ) ;
if ( V_318 )
V_104 -> V_353 ( V_104 , V_318 ) ;
}
F_321 ( V_18 ) ;
if ( V_18 -> V_257 . V_354 ) {
F_322 ( V_18 ) ;
F_323 ( V_18 ) ;
if ( F_69 ( V_18 ) >= 6 )
F_324 ( V_18 ) ;
}
}
void F_325 ( struct V_103 * V_104 )
{
F_326 ( & V_104 -> V_338 ) ;
F_327 ( V_104 -> V_336 . V_337 ) ;
}
void F_328 ( struct V_17 * V_18 )
{
struct V_103 * V_104 ;
enum V_340 V_341 ;
F_55 ( & V_18 -> V_168 . V_30 ) ;
F_309 (engine, dev_priv, id) {
V_104 -> V_333 . V_342 = NULL ;
F_325 ( V_104 ) ;
}
}
static void F_329 ( struct V_90 * V_329 )
{
unsigned long V_86 ;
F_45 ( ! F_209 ( & V_329 -> V_94 -> V_29 ) ) ;
F_312 ( & V_329 -> V_85 , - V_26 ) ;
F_299 ( & V_329 -> V_104 -> V_331 -> V_138 , V_86 ) ;
F_330 ( V_329 ) ;
F_331 ( V_329 -> V_104 , V_329 -> V_332 ) ;
F_301 ( & V_329 -> V_104 -> V_331 -> V_138 , V_86 ) ;
}
static void F_332 ( struct V_103 * V_104 )
{
struct V_90 * V_329 ;
unsigned long V_86 ;
V_104 -> V_355 = F_329 ;
F_299 ( & V_104 -> V_331 -> V_138 , V_86 ) ;
F_20 (request, &engine->timeline->requests, link)
if ( ! F_68 ( V_329 ) )
F_312 ( & V_329 -> V_85 , - V_26 ) ;
F_301 ( & V_104 -> V_331 -> V_138 , V_86 ) ;
if ( V_94 . V_356 ) {
struct V_357 * V_358 = V_104 -> V_357 ;
unsigned long V_86 ;
unsigned int V_359 ;
F_299 ( & V_104 -> V_331 -> V_138 , V_86 ) ;
for ( V_359 = 0 ; V_359 < F_277 ( V_104 -> V_357 ) ; V_359 ++ )
F_333 ( F_334 ( & V_358 [ V_359 ] ) ) ;
memset ( V_104 -> V_357 , 0 , sizeof( V_104 -> V_357 ) ) ;
V_104 -> V_360 = V_361 ;
V_104 -> V_362 = NULL ;
F_301 ( & V_104 -> V_331 -> V_138 , V_86 ) ;
F_335 ( V_363 , & V_104 -> V_350 ) ;
}
F_331 ( V_104 ,
F_336 ( V_104 ) ) ;
}
static int F_337 ( void * V_31 )
{
struct V_17 * V_94 = V_31 ;
struct V_103 * V_104 ;
enum V_340 V_341 ;
F_309 (engine, i915, id)
F_332 ( V_104 ) ;
F_338 ( V_364 , & V_94 -> V_29 . V_86 ) ;
F_339 ( & V_94 -> V_29 . V_24 ) ;
return 0 ;
}
void F_340 ( struct V_17 * V_18 )
{
F_341 ( F_337 , V_18 , NULL ) ;
}
bool F_342 ( struct V_17 * V_94 )
{
struct V_365 * V_366 ;
int V_52 ;
F_55 ( & V_94 -> V_168 . V_30 ) ;
if ( ! F_64 ( V_364 , & V_94 -> V_29 . V_86 ) )
return true ;
F_20 (tl, &i915->gt.timelines, link) {
for ( V_52 = 0 ; V_52 < F_277 ( V_366 -> V_104 ) ; V_52 ++ ) {
struct V_90 * V_91 ;
V_91 = F_343 ( & V_366 -> V_104 [ V_52 ] . V_367 ,
& V_94 -> V_168 . V_30 ) ;
if ( ! V_91 )
continue;
if ( F_344 ( & V_91 -> V_85 , true ,
V_81 ) < 0 )
return false ;
}
}
F_345 ( V_94 ) ;
F_346 ( V_94 ) ;
F_274 () ;
F_335 ( V_364 , & V_94 -> V_29 . V_86 ) ;
return true ;
}
static void
F_347 ( struct V_368 * V_369 )
{
struct V_17 * V_18 =
F_348 ( V_369 , F_349 ( * V_18 ) , V_257 . V_258 . V_369 ) ;
struct V_27 * V_28 = & V_18 -> V_168 ;
if ( F_350 ( & V_28 -> V_30 ) ) {
F_57 ( V_18 ) ;
F_22 ( & V_28 -> V_30 ) ;
}
if ( F_243 ( V_18 -> V_257 . V_354 ) ) {
F_351 ( V_18 ) ;
F_352 ( V_18 -> V_370 ,
& V_18 -> V_257 . V_258 ,
F_353 ( V_371 ) ) ;
}
}
static void
F_354 ( struct V_368 * V_369 )
{
struct V_17 * V_18 =
F_348 ( V_369 , F_349 ( * V_18 ) , V_257 . V_372 . V_369 ) ;
struct V_27 * V_28 = & V_18 -> V_168 ;
bool V_373 ;
if ( ! F_243 ( V_18 -> V_257 . V_354 ) )
return;
F_355 ( F_356 ( V_18 ) , 10 ) ;
if ( F_243 ( V_18 -> V_257 . V_374 ) )
return;
V_373 =
F_357 ( & V_18 -> V_29 . V_375 ) ;
if ( ! F_350 ( & V_28 -> V_30 ) ) {
F_358 ( V_18 -> V_370 ,
& V_18 -> V_257 . V_372 ,
F_359 ( 50 ) ) ;
goto V_376;
}
if ( F_360 ( V_369 ) )
goto V_172;
if ( V_18 -> V_257 . V_374 )
goto V_172;
if ( F_355 ( F_356 ( V_18 ) , 10 ) )
F_14 ( L_9 ) ;
F_361 ( V_18 ) ;
F_362 ( V_18 ) ;
F_45 ( ! V_18 -> V_257 . V_354 ) ;
V_18 -> V_257 . V_354 = false ;
V_373 = false ;
if ( F_69 ( V_18 ) >= 6 )
F_363 ( V_18 ) ;
F_120 ( V_18 ) ;
V_172:
F_22 ( & V_28 -> V_30 ) ;
V_376:
if ( V_373 ) {
F_45 ( ! V_18 -> V_257 . V_354 ) ;
F_351 ( V_18 ) ;
}
}
void F_364 ( struct V_377 * V_378 , struct V_32 * V_33 )
{
struct V_17 * V_94 = F_16 ( V_378 -> V_28 ) ;
struct V_1 * V_2 = F_201 ( V_378 ) ;
struct V_112 * V_113 = V_33 -> V_114 ;
struct V_379 * V_380 , * V_381 ;
F_19 ( & V_94 -> V_168 . V_30 ) ;
F_215 (lut, ln, &obj->lut_list, obj_link) {
struct V_317 * V_318 = V_380 -> V_318 ;
struct V_35 * V_36 ;
if ( V_318 -> V_326 != V_113 )
continue;
V_36 = F_239 ( & V_318 -> V_382 , V_380 -> V_122 ) ;
F_45 ( V_36 -> V_2 != V_2 ) ;
F_45 ( ! V_36 -> V_383 ) ;
if ( ! -- V_36 -> V_383 && ! F_176 ( V_36 ) )
F_365 ( V_36 ) ;
F_366 ( & V_380 -> V_83 ) ;
F_366 ( & V_380 -> V_384 ) ;
F_98 ( V_94 -> V_385 , V_380 ) ;
F_367 ( V_2 ) ;
}
F_22 ( & V_94 -> V_168 . V_30 ) ;
}
static unsigned long F_368 ( T_12 V_386 )
{
if ( V_386 < 0 )
return V_81 ;
if ( V_386 == 0 )
return 0 ;
return F_369 ( V_386 ) ;
}
int
F_370 ( struct V_27 * V_28 , void * V_31 , struct V_32 * V_33 )
{
struct V_387 * args = V_31 ;
struct V_1 * V_2 ;
T_13 V_157 ;
long V_23 ;
if ( args -> V_86 != 0 )
return - V_53 ;
V_2 = F_163 ( V_33 , args -> V_388 ) ;
if ( ! V_2 )
return - V_182 ;
V_157 = F_371 () ;
V_23 = F_56 ( V_2 ,
V_78 | V_80 ,
F_368 ( args -> V_386 ) ,
F_89 ( V_33 ) ) ;
if ( args -> V_386 > 0 ) {
args -> V_386 -= F_372 ( F_373 ( F_371 () , V_157 ) ) ;
if ( args -> V_386 < 0 )
args -> V_386 = 0 ;
if ( V_23 == - V_389 && ! F_374 ( args -> V_386 ) )
args -> V_386 = 0 ;
if ( V_23 == - V_389 && args -> V_386 )
V_23 = - V_244 ;
}
F_104 ( V_2 ) ;
return V_23 ;
}
static int F_375 ( struct V_365 * V_366 , unsigned int V_86 )
{
int V_23 , V_52 ;
for ( V_52 = 0 ; V_52 < F_277 ( V_366 -> V_104 ) ; V_52 ++ ) {
V_23 = F_376 ( & V_366 -> V_104 [ V_52 ] . V_367 , V_86 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static int F_377 ( struct V_103 * V_104 , int V_390 )
{
return F_355 ( F_378 ( V_104 ) , V_390 ) ;
}
static int F_379 ( struct V_17 * V_94 )
{
struct V_103 * V_104 ;
enum V_340 V_341 ;
F_309 (engine, i915, id) {
if ( F_380 ( F_377 ( V_104 , 50 ) ) ) {
F_340 ( V_94 ) ;
return - V_26 ;
}
F_45 ( F_303 ( V_104 ) !=
F_336 ( V_104 ) ) ;
}
return 0 ;
}
int F_219 ( struct V_17 * V_94 , unsigned int V_86 )
{
int V_23 ;
if ( ! F_243 ( V_94 -> V_257 . V_354 ) )
return 0 ;
if ( V_86 & V_79 ) {
struct V_365 * V_366 ;
F_55 ( & V_94 -> V_168 . V_30 ) ;
F_20 (tl, &i915->gt.timelines, link) {
V_23 = F_375 ( V_366 , V_86 ) ;
if ( V_23 )
return V_23 ;
}
F_57 ( V_94 ) ;
F_45 ( V_94 -> V_257 . V_374 ) ;
V_23 = F_379 ( V_94 ) ;
} else {
V_23 = F_375 ( & V_94 -> V_257 . V_391 , V_86 ) ;
}
return V_23 ;
}
static void F_381 ( struct V_1 * V_2 )
{
F_112 ( V_2 , ~ V_66 ) ;
if ( V_2 -> V_3 )
F_121 ( V_2 , V_392 ) ;
V_2 -> V_12 . V_67 = 0 ;
}
void F_182 ( struct V_1 * V_2 )
{
if ( ! F_243 ( V_2 -> V_6 ) )
return;
F_19 ( & V_2 -> V_12 . V_28 -> V_30 ) ;
F_381 ( V_2 ) ;
F_22 ( & V_2 -> V_12 . V_28 -> V_30 ) ;
}
int
F_180 ( struct V_1 * V_2 , bool V_231 )
{
int V_23 ;
F_55 ( & V_2 -> V_12 . V_28 -> V_30 ) ;
V_23 = F_56 ( V_2 ,
V_78 |
V_79 |
( V_231 ? V_80 : 0 ) ,
V_81 ,
NULL ) ;
if ( V_23 )
return V_23 ;
if ( V_2 -> V_12 . V_67 == V_205 )
return 0 ;
V_23 = F_129 ( V_2 ) ;
if ( V_23 )
return V_23 ;
F_112 ( V_2 , ~ V_205 ) ;
if ( ( V_2 -> V_12 . V_65 & V_205 ) == 0 )
F_382 () ;
F_45 ( ( V_2 -> V_12 . V_67 & ~ V_205 ) != 0 ) ;
V_2 -> V_12 . V_65 |= V_205 ;
if ( V_231 ) {
V_2 -> V_12 . V_65 = V_205 ;
V_2 -> V_12 . V_67 = V_205 ;
V_2 -> V_13 . V_73 = true ;
}
F_52 ( V_2 ) ;
return 0 ;
}
int
F_159 ( struct V_1 * V_2 , bool V_231 )
{
int V_23 ;
F_55 ( & V_2 -> V_12 . V_28 -> V_30 ) ;
V_23 = F_56 ( V_2 ,
V_78 |
V_79 |
( V_231 ? V_80 : 0 ) ,
V_81 ,
NULL ) ;
if ( V_23 )
return V_23 ;
if ( V_2 -> V_12 . V_67 == V_134 )
return 0 ;
V_23 = F_129 ( V_2 ) ;
if ( V_23 )
return V_23 ;
F_112 ( V_2 , ~ V_134 ) ;
if ( ( V_2 -> V_12 . V_65 & V_134 ) == 0 )
F_382 () ;
F_45 ( ( V_2 -> V_12 . V_67 & ~ V_134 ) != 0 ) ;
V_2 -> V_12 . V_65 |= V_134 ;
if ( V_231 ) {
V_2 -> V_12 . V_65 = V_134 ;
V_2 -> V_12 . V_67 = V_134 ;
V_2 -> V_13 . V_73 = true ;
}
F_52 ( V_2 ) ;
return 0 ;
}
int F_383 ( struct V_1 * V_2 ,
enum V_393 V_128 )
{
struct V_35 * V_36 ;
int V_23 ;
F_55 ( & V_2 -> V_12 . V_28 -> V_30 ) ;
if ( V_2 -> V_128 == V_128 )
return 0 ;
V_394:
F_20 (vma, &obj->vma_list, obj_link) {
if ( ! F_178 ( & V_36 -> V_10 ) )
continue;
if ( F_21 ( V_36 ) ) {
F_271 ( L_10 ) ;
return - V_246 ;
}
if ( F_384 ( V_36 , V_128 ) )
continue;
V_23 = F_60 ( V_36 ) ;
if ( V_23 )
return V_23 ;
goto V_394;
}
if ( V_2 -> V_199 ) {
V_23 = F_56 ( V_2 ,
V_78 |
V_79 |
V_80 ,
V_81 ,
NULL ) ;
if ( V_23 )
return V_23 ;
if ( ! F_114 ( F_16 ( V_2 -> V_12 . V_28 ) ) &&
V_128 != V_129 ) {
F_211 ( V_2 ) ;
F_20 (vma, &obj->vma_list, obj_link) {
V_23 = F_157 ( V_36 ) ;
if ( V_23 )
return V_23 ;
}
} else {
}
F_20 (vma, &obj->vma_list, obj_link) {
if ( ! F_178 ( & V_36 -> V_10 ) )
continue;
V_23 = F_385 ( V_36 , V_128 , V_395 ) ;
if ( V_23 )
return V_23 ;
}
}
F_20 (vma, &obj->vma_list, obj_link)
V_36 -> V_10 . V_396 = V_128 ;
F_386 ( V_2 , V_128 ) ;
V_2 -> V_3 = true ;
return 0 ;
}
int F_387 ( struct V_27 * V_28 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_397 * args = V_31 ;
struct V_1 * V_2 ;
int V_190 = 0 ;
F_237 () ;
V_2 = F_388 ( V_33 , args -> V_122 ) ;
if ( ! V_2 ) {
V_190 = - V_182 ;
goto V_93;
}
switch ( V_2 -> V_128 ) {
case V_398 :
case V_399 :
args -> V_400 = V_401 ;
break;
case V_130 :
args -> V_400 = V_402 ;
break;
default:
args -> V_400 = V_403 ;
break;
}
V_93:
F_240 () ;
return V_190 ;
}
int F_389 ( struct V_27 * V_28 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_17 * V_94 = F_16 ( V_28 ) ;
struct V_397 * args = V_31 ;
struct V_1 * V_2 ;
enum V_393 V_404 ;
int V_23 = 0 ;
switch ( args -> V_400 ) {
case V_403 :
V_404 = V_129 ;
break;
case V_401 :
if ( ! F_114 ( V_94 ) && ! F_390 ( V_94 ) )
return - V_150 ;
V_404 = V_398 ;
break;
case V_402 :
V_404 = F_391 ( V_94 ) ? V_130 : V_129 ;
break;
default:
return - V_53 ;
}
V_2 = F_163 ( V_33 , args -> V_122 ) ;
if ( ! V_2 )
return - V_182 ;
if ( V_2 -> V_128 == V_404 )
goto V_93;
V_23 = F_56 ( V_2 ,
V_78 ,
V_81 ,
F_89 ( V_33 ) ) ;
if ( V_23 )
goto V_93;
V_23 = F_15 ( V_28 ) ;
if ( V_23 )
goto V_93;
V_23 = F_383 ( V_2 , V_404 ) ;
F_22 ( & V_28 -> V_30 ) ;
V_93:
F_104 ( V_2 ) ;
return V_23 ;
}
struct V_35 *
F_392 ( struct V_1 * V_2 ,
T_1 V_405 ,
const struct V_221 * V_223 )
{
struct V_35 * V_36 ;
int V_23 ;
F_55 ( & V_2 -> V_12 . V_28 -> V_30 ) ;
V_2 -> V_6 ++ ;
V_23 = F_383 ( V_2 ,
F_391 ( F_16 ( V_2 -> V_12 . V_28 ) ) ?
V_130 : V_129 ) ;
if ( V_23 ) {
V_36 = F_26 ( V_23 ) ;
goto V_406;
}
V_36 = F_26 ( - V_193 ) ;
if ( ! V_223 || V_223 -> type == V_226 )
V_36 = F_155 ( V_2 , V_223 , 0 , V_405 ,
V_169 | V_170 ) ;
if ( F_30 ( V_36 ) ) {
struct V_17 * V_94 = F_16 ( V_2 -> V_12 . V_28 ) ;
unsigned int V_86 ;
V_86 = 0 ;
if ( F_393 ( V_94 ) )
V_86 = V_169 ;
V_36 = F_155 ( V_2 , V_223 , 0 , V_405 , V_86 ) ;
}
if ( F_30 ( V_36 ) )
goto V_406;
V_36 -> V_407 = F_394 ( T_2 , V_36 -> V_407 , V_405 ) ;
F_381 ( V_2 ) ;
F_94 ( V_2 , V_408 ) ;
V_2 -> V_12 . V_65 |= V_134 ;
return V_36 ;
V_406:
V_2 -> V_6 -- ;
return V_36 ;
}
void
F_395 ( struct V_35 * V_36 )
{
F_55 ( & V_36 -> V_197 -> V_94 -> V_168 . V_30 ) ;
if ( F_24 ( V_36 -> V_2 -> V_6 == 0 ) )
return;
if ( -- V_36 -> V_2 -> V_6 == 0 )
V_36 -> V_407 = V_409 ;
F_175 ( V_36 -> V_2 ) ;
F_158 ( V_36 ) ;
}
int
F_131 ( struct V_1 * V_2 , bool V_231 )
{
int V_23 ;
F_55 ( & V_2 -> V_12 . V_28 -> V_30 ) ;
V_23 = F_56 ( V_2 ,
V_78 |
V_79 |
( V_231 ? V_80 : 0 ) ,
V_81 ,
NULL ) ;
if ( V_23 )
return V_23 ;
F_112 ( V_2 , ~ V_66 ) ;
if ( ( V_2 -> V_12 . V_65 & V_66 ) == 0 ) {
F_121 ( V_2 , V_141 ) ;
V_2 -> V_12 . V_65 |= V_66 ;
}
F_45 ( V_2 -> V_12 . V_67 & ~ V_66 ) ;
if ( V_231 )
F_43 ( V_2 ) ;
return 0 ;
}
static int
F_396 ( struct V_27 * V_28 , struct V_32 * V_33 )
{
struct V_17 * V_18 = F_16 ( V_28 ) ;
struct V_112 * V_326 = V_33 -> V_114 ;
unsigned long V_410 = V_411 - V_412 ;
struct V_90 * V_329 , * V_413 = NULL ;
long V_23 ;
if ( F_209 ( & V_18 -> V_29 ) )
return - V_26 ;
F_7 ( & V_326 -> V_13 . V_138 ) ;
F_20 (request, &file_priv->mm.request_list, client_link) {
if ( F_397 ( V_329 -> V_414 , V_410 ) )
break;
if ( V_413 ) {
F_366 ( & V_413 -> V_415 ) ;
V_413 -> V_326 = NULL ;
}
V_413 = V_329 ;
}
if ( V_413 )
F_398 ( V_413 ) ;
F_8 ( & V_326 -> V_13 . V_138 ) ;
if ( V_413 == NULL )
return 0 ;
V_23 = F_71 ( V_413 ,
V_78 ,
V_81 ) ;
F_333 ( V_413 ) ;
return V_23 < 0 ? V_23 : 0 ;
}
struct V_35 *
F_155 ( struct V_1 * V_2 ,
const struct V_221 * V_223 ,
T_2 V_11 ,
T_2 V_405 ,
T_2 V_86 )
{
struct V_17 * V_18 = F_16 ( V_2 -> V_12 . V_28 ) ;
struct V_416 * V_197 = & V_18 -> V_8 . V_12 ;
struct V_35 * V_36 ;
int V_23 ;
F_55 ( & V_2 -> V_12 . V_28 -> V_30 ) ;
V_36 = F_399 ( V_2 , V_197 , V_223 ) ;
if ( F_134 ( F_30 ( V_36 ) ) )
return V_36 ;
if ( F_400 ( V_36 , V_11 , V_405 , V_86 ) ) {
if ( V_86 & V_170 &&
( F_21 ( V_36 ) || F_177 ( V_36 ) ) )
return F_26 ( - V_193 ) ;
if ( V_86 & V_169 ) {
if ( V_36 -> V_417 > V_18 -> V_8 . V_15 )
return F_26 ( - V_418 ) ;
if ( V_86 & V_170 &&
V_36 -> V_417 > V_18 -> V_8 . V_15 / 2 )
return F_26 ( - V_193 ) ;
}
F_401 ( F_21 ( V_36 ) ,
L_11
L_12
L_13 ,
F_156 ( V_36 ) , V_405 ,
! ! ( V_86 & V_169 ) ,
F_402 ( V_36 ) ) ;
V_23 = F_60 ( V_36 ) ;
if ( V_23 )
return F_26 ( V_23 ) ;
}
V_23 = F_403 ( V_36 , V_11 , V_405 , V_86 | V_419 ) ;
if ( V_23 )
return F_26 ( V_23 ) ;
return V_36 ;
}
static T_14 unsigned int F_404 ( unsigned int V_341 )
{
F_63 ( V_420 > 16 ) ;
return 0x10000 << V_341 ;
}
static T_14 unsigned int F_405 ( unsigned int V_341 )
{
return V_341 | F_404 ( V_341 ) ;
}
static T_14 unsigned int
F_406 ( const struct V_84 * V_85 )
{
return F_407 ( V_85 , F_404 ) ;
}
static T_14 unsigned int
F_408 ( const struct V_84 * V_85 )
{
if ( ! V_85 )
return 0 ;
return F_407 ( V_85 , F_405 ) ;
}
int
F_409 ( struct V_27 * V_28 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_421 * args = V_31 ;
struct V_1 * V_2 ;
struct V_422 * V_195 ;
unsigned int V_97 ;
int V_190 ;
V_190 = - V_182 ;
F_237 () ;
V_2 = F_388 ( V_33 , args -> V_122 ) ;
if ( ! V_2 )
goto V_93;
V_423:
V_97 = F_410 ( & V_2 -> V_96 -> V_97 ) ;
args -> V_424 = F_408 ( F_411 ( V_2 -> V_96 -> V_425 ) ) ;
V_195 = F_411 ( V_2 -> V_96 -> V_85 ) ;
if ( V_195 ) {
unsigned int V_426 = V_195 -> V_426 , V_52 ;
for ( V_52 = 0 ; V_52 < V_426 ; ++ V_52 ) {
struct V_84 * V_85 =
F_411 ( V_195 -> V_100 [ V_52 ] ) ;
args -> V_424 |= F_406 ( V_85 ) ;
}
}
if ( args -> V_424 && F_412 ( & V_2 -> V_96 -> V_97 , V_97 ) )
goto V_423;
V_190 = 0 ;
V_93:
F_240 () ;
return V_190 ;
}
int
F_413 ( struct V_27 * V_28 , void * V_31 ,
struct V_32 * V_326 )
{
return F_396 ( V_28 , V_326 ) ;
}
int
F_414 ( struct V_27 * V_28 , void * V_31 ,
struct V_32 * V_326 )
{
struct V_17 * V_18 = F_16 ( V_28 ) ;
struct V_427 * args = V_31 ;
struct V_1 * V_2 ;
int V_190 ;
switch ( args -> V_70 ) {
case V_72 :
case V_76 :
break;
default:
return - V_53 ;
}
V_2 = F_163 ( V_326 , args -> V_122 ) ;
if ( ! V_2 )
return - V_182 ;
V_190 = F_17 ( & V_2 -> V_13 . V_138 ) ;
if ( V_190 )
goto V_93;
if ( V_2 -> V_13 . V_68 &&
F_196 ( V_2 ) &&
V_18 -> V_300 & V_301 ) {
if ( V_2 -> V_13 . V_70 == V_76 ) {
F_45 ( ! V_2 -> V_13 . V_302 ) ;
F_415 ( V_2 ) ;
V_2 -> V_13 . V_302 = false ;
}
if ( args -> V_70 == V_76 ) {
F_45 ( V_2 -> V_13 . V_302 ) ;
F_269 ( V_2 ) ;
V_2 -> V_13 . V_302 = true ;
}
}
if ( V_2 -> V_13 . V_70 != V_71 )
V_2 -> V_13 . V_70 = args -> V_70 ;
if ( V_2 -> V_13 . V_70 == V_72 && ! V_2 -> V_13 . V_68 )
F_227 ( V_2 ) ;
args -> V_428 = V_2 -> V_13 . V_70 != V_71 ;
F_22 ( & V_2 -> V_13 . V_138 ) ;
V_93:
F_104 ( V_2 ) ;
return V_190 ;
}
static void
F_416 ( struct V_429 * V_330 ,
struct V_90 * V_329 )
{
struct V_1 * V_2 =
F_348 ( V_330 , F_349 ( * V_2 ) , V_430 ) ;
F_94 ( V_2 , V_431 ) ;
}
void F_417 ( struct V_1 * V_2 ,
const struct V_432 * V_191 )
{
F_418 ( & V_2 -> V_13 . V_138 ) ;
F_419 ( & V_2 -> V_202 ) ;
F_419 ( & V_2 -> V_238 ) ;
F_419 ( & V_2 -> V_82 ) ;
F_419 ( & V_2 -> V_433 ) ;
F_419 ( & V_2 -> V_434 ) ;
V_2 -> V_191 = V_191 ;
F_420 ( & V_2 -> V_435 ) ;
V_2 -> V_96 = & V_2 -> V_435 ;
V_2 -> V_135 = V_436 ;
F_421 ( & V_2 -> V_430 , F_416 ) ;
V_2 -> V_13 . V_70 = V_76 ;
F_422 ( & V_2 -> V_13 . V_264 . V_265 , V_59 | V_278 ) ;
F_418 ( & V_2 -> V_13 . V_264 . V_138 ) ;
F_6 ( F_16 ( V_2 -> V_12 . V_28 ) , V_2 -> V_12 . V_11 ) ;
}
struct V_1 *
F_101 ( struct V_17 * V_18 , T_2 V_11 )
{
struct V_1 * V_2 ;
struct V_43 * V_44 ;
unsigned int V_128 ;
T_10 V_437 ;
int V_23 ;
if ( V_11 >> V_164 > V_438 )
return F_26 ( - V_418 ) ;
if ( F_423 ( V_11 , V_2 -> V_12 . V_11 ) )
return F_26 ( - V_418 ) ;
V_2 = F_95 ( V_18 ) ;
if ( V_2 == NULL )
return F_26 ( - V_54 ) ;
V_23 = F_424 ( & V_18 -> V_168 , & V_2 -> V_12 , V_11 ) ;
if ( V_23 )
goto V_439;
V_437 = V_440 | V_441 ;
if ( F_425 ( V_18 ) || F_426 ( V_18 ) ) {
V_437 &= ~ V_442 ;
V_437 |= V_295 ;
}
V_44 = V_2 -> V_12 . V_45 -> V_46 ;
F_427 ( V_44 , V_437 ) ;
F_45 ( ! ( F_262 ( V_44 ) & V_285 ) ) ;
F_417 ( V_2 , & V_443 ) ;
V_2 -> V_12 . V_67 = V_66 ;
V_2 -> V_12 . V_65 = V_66 ;
if ( F_114 ( V_18 ) )
V_128 = V_398 ;
else
V_128 = V_129 ;
F_386 ( V_2 , V_128 ) ;
F_428 ( V_2 ) ;
return V_2 ;
V_439:
F_97 ( V_2 ) ;
return F_26 ( V_23 ) ;
}
static bool F_429 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 . V_70 != V_76 )
return false ;
if ( V_2 -> V_12 . V_45 == NULL )
return true ;
return F_430 ( & V_2 -> V_12 . V_45 -> V_444 ) == 1 ;
}
static void F_431 ( struct V_17 * V_94 ,
struct V_445 * V_446 )
{
struct V_1 * V_2 , * V_252 ;
F_19 ( & V_94 -> V_168 . V_30 ) ;
F_115 ( V_94 ) ;
F_432 (obj, freed, freed) {
struct V_35 * V_36 , * V_447 ;
F_433 ( V_2 ) ;
F_45 ( F_434 ( V_2 ) ) ;
F_215 (vma, vn,
&obj->vma_list, obj_link) {
F_45 ( F_177 ( V_36 ) ) ;
V_36 -> V_86 &= ~ V_448 ;
F_365 ( V_36 ) ;
}
F_45 ( ! F_205 ( & V_2 -> V_82 ) ) ;
F_45 ( ! F_435 ( & V_2 -> V_449 ) ) ;
F_366 ( & V_2 -> V_202 ) ;
}
F_120 ( V_94 ) ;
F_22 ( & V_94 -> V_168 . V_30 ) ;
F_261 () ;
F_436 (obj, on, freed, freed) {
F_45 ( V_2 -> V_199 ) ;
F_45 ( F_245 ( & V_2 -> V_450 ) ) ;
if ( V_2 -> V_191 -> V_451 )
V_2 -> V_191 -> V_451 ( V_2 ) ;
if ( F_24 ( F_242 ( V_2 ) ) )
F_437 ( & V_2 -> V_13 . V_269 , 0 ) ;
F_241 ( V_2 , V_452 ) ;
F_45 ( V_2 -> V_13 . V_68 ) ;
if ( V_2 -> V_12 . V_453 )
F_438 ( & V_2 -> V_12 , NULL ) ;
F_439 ( & V_2 -> V_435 ) ;
F_440 ( & V_2 -> V_12 ) ;
F_9 ( V_94 , V_2 -> V_12 . V_11 ) ;
F_39 ( V_2 -> V_454 ) ;
F_97 ( V_2 ) ;
}
}
static void F_110 ( struct V_17 * V_94 )
{
struct V_445 * V_446 ;
V_446 = F_441 ( & V_94 -> V_13 . V_455 ) ;
if ( F_134 ( V_446 ) )
F_431 ( V_94 , V_446 ) ;
}
static void F_442 ( struct V_368 * V_369 )
{
struct V_17 * V_94 =
F_348 ( V_369 , struct V_17 , V_13 . V_456 ) ;
struct V_445 * V_446 ;
while ( ( V_446 = F_441 ( & V_94 -> V_13 . V_455 ) ) ) {
F_431 ( V_94 , V_446 ) ;
if ( F_443 () )
break;
}
}
static void F_444 ( struct V_457 * V_344 )
{
struct V_1 * V_2 =
F_348 ( V_344 , F_349 ( * V_2 ) , V_458 ) ;
struct V_17 * V_94 = F_16 ( V_2 -> V_12 . V_28 ) ;
if ( F_445 ( & V_2 -> V_446 , & V_94 -> V_13 . V_455 ) )
F_446 ( & V_94 -> V_13 . V_456 ) ;
}
void F_447 ( struct V_377 * V_459 )
{
struct V_1 * V_2 = F_201 ( V_459 ) ;
if ( V_2 -> V_13 . V_302 )
F_415 ( V_2 ) ;
if ( F_429 ( V_2 ) )
V_2 -> V_13 . V_70 = V_72 ;
F_448 ( & V_2 -> V_458 , F_444 ) ;
}
void F_367 ( struct V_1 * V_2 )
{
F_55 ( & V_2 -> V_12 . V_28 -> V_30 ) ;
if ( ! F_449 ( V_2 ) &&
F_434 ( V_2 ) )
F_450 ( V_2 ) ;
else
F_104 ( V_2 ) ;
}
static void F_451 ( struct V_17 * V_18 )
{
struct V_103 * V_104 ;
enum V_340 V_341 ;
F_309 (engine, dev_priv, id)
F_45 ( V_104 -> V_352 &&
! F_452 ( V_104 -> V_352 ) ) ;
}
void F_453 ( struct V_17 * V_94 )
{
if ( F_69 ( V_94 ) >= 5 ) {
int V_460 = F_454 ( V_94 , V_461 ) ;
F_24 ( V_460 && V_460 != - V_150 ) ;
}
}
int F_455 ( struct V_17 * V_18 )
{
struct V_27 * V_28 = & V_18 -> V_168 ;
int V_23 ;
F_115 ( V_18 ) ;
F_456 ( V_18 ) ;
F_19 ( & V_28 -> V_30 ) ;
V_23 = F_457 ( V_18 ) ;
if ( V_23 )
goto V_236;
V_23 = F_219 ( V_18 ,
V_78 |
V_79 ) ;
if ( V_23 )
goto V_236;
F_451 ( V_18 ) ;
F_346 ( V_18 ) ;
F_22 ( & V_28 -> V_30 ) ;
F_458 ( V_18 ) ;
F_357 ( & V_18 -> V_29 . V_375 ) ;
F_357 ( & V_18 -> V_257 . V_258 ) ;
while ( F_221 ( & V_18 -> V_257 . V_372 ) )
;
F_24 ( V_18 -> V_257 . V_354 ) ;
F_24 ( ! F_356 ( V_18 ) ) ;
F_453 ( V_18 ) ;
goto V_462;
V_236:
F_22 ( & V_28 -> V_30 ) ;
V_462:
F_120 ( V_18 ) ;
return V_23 ;
}
void F_459 ( struct V_17 * V_18 )
{
struct V_27 * V_28 = & V_18 -> V_168 ;
F_24 ( V_18 -> V_257 . V_354 ) ;
F_19 ( & V_28 -> V_30 ) ;
F_460 ( V_18 ) ;
V_18 -> V_257 . V_463 ( V_18 ) ;
F_22 ( & V_28 -> V_30 ) ;
}
void F_461 ( struct V_17 * V_18 )
{
if ( F_69 ( V_18 ) < 5 ||
V_18 -> V_13 . V_464 == V_465 )
return;
F_462 ( V_466 , F_463 ( V_466 ) |
V_467 ) ;
if ( F_464 ( V_18 ) )
return;
F_462 ( V_468 , F_463 ( V_468 ) | V_469 ) ;
if ( F_465 ( V_18 ) )
F_462 ( V_470 , F_466 ( V_471 ) ) ;
else if ( F_467 ( V_18 ) )
F_462 ( V_470 , F_466 ( V_472 ) ) ;
else if ( F_468 ( V_18 ) )
F_462 ( V_473 , F_466 ( V_474 ) ) ;
else
F_469 () ;
}
static void F_470 ( struct V_17 * V_18 , T_1 V_12 )
{
F_462 ( F_471 ( V_12 ) , 0 ) ;
F_462 ( F_472 ( V_12 ) , 0 ) ;
F_462 ( F_473 ( V_12 ) , 0 ) ;
F_462 ( F_474 ( V_12 ) , 0 ) ;
}
static void F_475 ( struct V_17 * V_18 )
{
if ( F_476 ( V_18 ) ) {
F_470 ( V_18 , V_475 ) ;
F_470 ( V_18 , V_476 ) ;
F_470 ( V_18 , V_477 ) ;
F_470 ( V_18 , V_478 ) ;
F_470 ( V_18 , V_479 ) ;
} else if ( F_477 ( V_18 ) ) {
F_470 ( V_18 , V_476 ) ;
F_470 ( V_18 , V_477 ) ;
} else if ( F_478 ( V_18 ) ) {
F_470 ( V_18 , V_475 ) ;
F_470 ( V_18 , V_480 ) ;
}
}
static int F_479 ( void * V_31 )
{
struct V_17 * V_94 = V_31 ;
struct V_103 * V_104 ;
enum V_340 V_341 ;
int V_190 ;
F_309 (engine, i915, id) {
V_190 = V_104 -> V_481 ( V_104 ) ;
if ( V_190 )
return V_190 ;
}
return 0 ;
}
int F_480 ( struct V_17 * V_18 )
{
int V_23 ;
V_18 -> V_257 . V_482 = F_371 () ;
F_481 ( V_18 , V_483 ) ;
if ( F_482 ( V_18 ) && F_69 ( V_18 ) < 9 )
F_462 ( V_484 , F_463 ( V_484 ) | F_483 ( 0xf ) ) ;
if ( F_484 ( V_18 ) )
F_462 ( V_485 , F_485 ( V_18 ) ?
V_486 : V_487 ) ;
if ( F_486 ( V_18 ) ) {
if ( F_487 ( V_18 ) ) {
T_1 V_488 = F_463 ( V_489 ) ;
V_488 &= ~ ( V_490 | V_491 ) ;
F_462 ( V_489 , V_488 ) ;
} else if ( F_69 ( V_18 ) >= 7 ) {
T_1 V_488 = F_463 ( V_492 ) ;
V_488 &= ~ V_493 ;
F_462 ( V_492 , V_488 ) ;
}
}
F_461 ( V_18 ) ;
F_475 ( V_18 ) ;
F_488 ( ! V_18 -> V_494 ) ;
V_23 = F_489 ( V_18 ) ;
if ( V_23 ) {
F_14 ( L_14 , V_23 ) ;
goto V_93;
}
V_23 = F_479 ( V_18 ) ;
if ( V_23 )
goto V_93;
F_490 ( V_18 ) ;
V_23 = F_491 ( V_18 ) ;
if ( V_23 )
goto V_93;
V_93:
F_492 ( V_18 , V_483 ) ;
return V_23 ;
}
bool F_493 ( struct V_17 * V_18 , int V_495 )
{
if ( F_494 ( V_18 ) -> V_496 < 6 )
return false ;
if ( V_94 . V_356 )
return false ;
if ( V_495 >= 0 )
return V_495 ;
if ( F_465 ( V_18 ) && F_495 () )
return false ;
return true ;
}
int F_496 ( struct V_17 * V_18 )
{
int V_23 ;
F_19 ( & V_18 -> V_168 . V_30 ) ;
V_18 -> V_13 . V_497 = F_497 ( 1 ) ;
if ( ! V_94 . V_356 ) {
V_18 -> V_257 . V_463 = V_498 ;
V_18 -> V_257 . V_499 = V_500 ;
} else {
V_18 -> V_257 . V_463 = V_501 ;
V_18 -> V_257 . V_499 = V_502 ;
}
F_481 ( V_18 , V_483 ) ;
V_23 = F_498 ( V_18 ) ;
if ( V_23 )
goto V_172;
V_23 = F_499 ( V_18 ) ;
if ( V_23 )
goto V_172;
V_23 = F_500 ( V_18 ) ;
if ( V_23 )
goto V_172;
V_23 = F_501 ( V_18 ) ;
if ( V_23 )
goto V_172;
V_23 = F_480 ( V_18 ) ;
if ( V_23 == - V_26 ) {
F_14 ( L_15 ) ;
F_340 ( V_18 ) ;
V_23 = 0 ;
}
V_172:
F_492 ( V_18 , V_483 ) ;
F_22 ( & V_18 -> V_168 . V_30 ) ;
return V_23 ;
}
void F_502 ( struct V_17 * V_94 )
{
F_453 ( V_94 ) ;
}
void
F_503 ( struct V_17 * V_18 )
{
struct V_103 * V_104 ;
enum V_340 V_341 ;
F_309 (engine, dev_priv, id)
V_18 -> V_257 . V_499 ( V_104 ) ;
}
void
F_504 ( struct V_17 * V_18 )
{
int V_52 ;
if ( F_494 ( V_18 ) -> V_496 >= 7 && ! F_505 ( V_18 ) &&
! F_506 ( V_18 ) )
V_18 -> V_253 = 32 ;
else if ( F_494 ( V_18 ) -> V_496 >= 4 ||
F_507 ( V_18 ) || F_508 ( V_18 ) ||
F_509 ( V_18 ) || F_510 ( V_18 ) )
V_18 -> V_253 = 16 ;
else
V_18 -> V_253 = 8 ;
if ( F_511 ( V_18 ) )
V_18 -> V_253 =
F_463 ( F_512 ( V_503 . V_504 ) ) ;
for ( V_52 = 0 ; V_52 < V_18 -> V_253 ; V_52 ++ ) {
struct V_254 * V_85 = & V_18 -> V_256 [ V_52 ] ;
V_85 -> V_94 = V_18 ;
V_85 -> V_341 = V_52 ;
F_513 ( & V_85 -> V_348 , & V_18 -> V_13 . V_505 ) ;
}
F_321 ( V_18 ) ;
F_514 ( V_18 ) ;
}
int
F_515 ( struct V_17 * V_18 )
{
int V_190 = - V_54 ;
V_18 -> V_120 = F_516 ( V_1 , V_506 ) ;
if ( ! V_18 -> V_120 )
goto V_507;
V_18 -> V_508 = F_516 ( V_35 , V_506 ) ;
if ( ! V_18 -> V_508 )
goto V_509;
V_18 -> V_385 = F_516 ( V_379 , 0 ) ;
if ( ! V_18 -> V_385 )
goto V_510;
V_18 -> V_349 = F_516 ( V_90 ,
V_506 |
V_511 |
V_512 ) ;
if ( ! V_18 -> V_349 )
goto V_513;
V_18 -> V_514 = F_516 ( V_515 ,
V_506 |
V_511 ) ;
if ( ! V_18 -> V_514 )
goto V_516;
V_18 -> V_517 = F_516 ( V_518 , V_506 ) ;
if ( ! V_18 -> V_517 )
goto V_519;
F_19 ( & V_18 -> V_168 . V_30 ) ;
F_419 ( & V_18 -> V_257 . V_520 ) ;
V_190 = F_517 ( V_18 ) ;
F_22 ( & V_18 -> V_168 . V_30 ) ;
if ( V_190 )
goto V_521;
F_518 ( & V_18 -> V_13 . V_456 , F_442 ) ;
F_519 ( & V_18 -> V_13 . V_455 ) ;
F_419 ( & V_18 -> V_13 . V_201 ) ;
F_419 ( & V_18 -> V_13 . V_200 ) ;
F_419 ( & V_18 -> V_13 . V_505 ) ;
F_419 ( & V_18 -> V_13 . V_239 ) ;
F_520 ( & V_18 -> V_257 . V_258 ,
F_347 ) ;
F_520 ( & V_18 -> V_257 . V_372 ,
F_354 ) ;
F_521 ( & V_18 -> V_29 . V_522 ) ;
F_521 ( & V_18 -> V_29 . V_24 ) ;
F_437 ( & V_18 -> V_13 . V_523 , 0 ) ;
F_522 ( & V_18 -> V_524 . V_138 ) ;
return 0 ;
V_521:
F_523 ( V_18 -> V_517 ) ;
V_519:
F_523 ( V_18 -> V_514 ) ;
V_516:
F_523 ( V_18 -> V_349 ) ;
V_513:
F_523 ( V_18 -> V_385 ) ;
V_510:
F_523 ( V_18 -> V_508 ) ;
V_509:
F_523 ( V_18 -> V_120 ) ;
V_507:
return V_190 ;
}
void F_524 ( struct V_17 * V_18 )
{
F_220 ( V_18 ) ;
F_24 ( ! F_525 ( & V_18 -> V_13 . V_455 ) ) ;
F_24 ( V_18 -> V_13 . V_20 ) ;
F_19 ( & V_18 -> V_168 . V_30 ) ;
F_526 ( & V_18 -> V_257 . V_391 ) ;
F_24 ( ! F_205 ( & V_18 -> V_257 . V_520 ) ) ;
F_22 ( & V_18 -> V_168 . V_30 ) ;
F_523 ( V_18 -> V_517 ) ;
F_523 ( V_18 -> V_514 ) ;
F_523 ( V_18 -> V_349 ) ;
F_523 ( V_18 -> V_385 ) ;
F_523 ( V_18 -> V_508 ) ;
F_523 ( V_18 -> V_120 ) ;
F_527 () ;
}
int F_528 ( struct V_17 * V_18 )
{
F_529 ( V_18 ) ;
return 0 ;
}
int F_530 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_194 * V_525 [] = {
& V_18 -> V_13 . V_201 ,
& V_18 -> V_13 . V_200 ,
NULL
} , * * V_526 ;
F_260 ( V_18 , - 1UL , NULL , V_289 ) ;
F_220 ( V_18 ) ;
F_19 ( & V_18 -> V_168 . V_30 ) ;
for ( V_526 = V_525 ; * V_526 ; V_526 ++ ) {
F_20 (obj, *p, global_link)
F_43 ( V_2 ) ;
}
F_22 ( & V_18 -> V_168 . V_30 ) ;
return 0 ;
}
void F_531 ( struct V_27 * V_28 , struct V_32 * V_33 )
{
struct V_112 * V_326 = V_33 -> V_114 ;
struct V_90 * V_329 ;
F_7 ( & V_326 -> V_13 . V_138 ) ;
F_20 (request, &file_priv->mm.request_list, client_link)
V_329 -> V_326 = NULL ;
F_8 ( & V_326 -> V_13 . V_138 ) ;
}
int F_532 ( struct V_17 * V_94 , struct V_32 * V_33 )
{
struct V_112 * V_326 ;
int V_23 ;
F_271 ( L_16 ) ;
V_326 = F_533 ( sizeof( * V_326 ) , V_59 ) ;
if ( ! V_326 )
return - V_54 ;
V_33 -> V_114 = V_326 ;
V_326 -> V_18 = V_94 ;
V_326 -> V_33 = V_33 ;
F_522 ( & V_326 -> V_13 . V_138 ) ;
F_419 ( & V_326 -> V_13 . V_527 ) ;
V_326 -> V_528 = - 1 ;
V_23 = F_534 ( V_94 , V_33 ) ;
if ( V_23 )
F_39 ( V_326 ) ;
return V_23 ;
}
void F_535 ( struct V_1 * V_529 ,
struct V_1 * V_530 ,
unsigned V_450 )
{
F_63 ( V_531 * V_532 >
sizeof( V_533 ) * V_534 ) ;
if ( V_529 ) {
F_24 ( ! ( F_245 ( & V_529 -> V_450 ) & V_450 ) ) ;
F_536 ( V_450 , & V_529 -> V_450 ) ;
}
if ( V_530 ) {
F_24 ( F_245 ( & V_530 -> V_450 ) & V_450 ) ;
F_537 ( V_450 , & V_530 -> V_450 ) ;
}
}
struct V_1 *
F_538 ( struct V_17 * V_18 ,
const void * V_31 , T_15 V_11 )
{
struct V_1 * V_2 ;
struct V_33 * V_33 ;
T_15 V_61 ;
int V_190 ;
V_2 = F_101 ( V_18 , F_136 ( V_11 , V_55 ) ) ;
if ( F_30 ( V_2 ) )
return V_2 ;
F_45 ( V_2 -> V_12 . V_67 != V_66 ) ;
V_33 = V_2 -> V_12 . V_45 ;
V_61 = 0 ;
do {
unsigned int V_185 = F_198 ( F_349 ( V_11 ) , V_11 , V_55 ) ;
struct V_56 * V_56 ;
void * V_535 , * V_51 ;
V_190 = F_288 ( V_33 , V_33 -> V_46 ,
V_61 , V_185 , 0 ,
& V_56 , & V_535 ) ;
if ( V_190 < 0 )
goto V_439;
V_51 = F_138 ( V_56 ) ;
memcpy ( V_51 , V_31 , V_185 ) ;
F_139 ( V_56 ) ;
V_190 = F_289 ( V_33 , V_33 -> V_46 ,
V_61 , V_185 , V_185 ,
V_56 , V_535 ) ;
if ( V_190 < 0 )
goto V_439;
V_11 -= V_185 ;
V_31 += V_185 ;
V_61 += V_185 ;
} while ( V_11 );
return V_2 ;
V_439:
F_104 ( V_2 ) ;
return F_26 ( V_190 ) ;
}
struct V_49 *
F_539 ( struct V_1 * V_2 ,
unsigned int V_359 ,
unsigned int * V_61 )
{
struct V_536 * V_262 = & V_2 -> V_13 . V_264 ;
struct V_49 * V_50 ;
unsigned int V_163 , V_101 ;
F_11 () ;
F_45 ( V_359 >= V_2 -> V_12 . V_11 >> V_164 ) ;
F_45 ( ! F_242 ( V_2 ) ) ;
if ( V_359 < F_243 ( V_262 -> V_299 ) )
goto V_537;
F_19 ( & V_262 -> V_138 ) ;
V_50 = V_262 -> V_298 ;
V_163 = V_262 -> V_299 ;
V_101 = F_540 ( V_50 ) ;
while ( V_163 + V_101 <= V_359 ) {
unsigned long V_538 , V_52 ;
int V_23 ;
V_23 = F_541 ( & V_262 -> V_265 , V_163 , V_50 ) ;
if ( V_23 && V_23 != - V_539 )
goto V_540;
V_538 =
V_541 |
V_163 << V_542 ;
for ( V_52 = 1 ; V_52 < V_101 ; V_52 ++ ) {
V_23 = F_541 ( & V_262 -> V_265 , V_163 + V_52 ,
( void * ) V_538 ) ;
if ( V_23 && V_23 != - V_539 )
goto V_540;
}
V_163 += V_101 ;
V_50 = F_542 ( V_50 ) ;
V_101 = F_540 ( V_50 ) ;
}
V_540:
V_262 -> V_298 = V_50 ;
V_262 -> V_299 = V_163 ;
F_22 ( & V_262 -> V_138 ) ;
if ( F_134 ( V_359 < V_163 ) )
goto V_537;
while ( V_163 + V_101 <= V_359 ) {
V_163 += V_101 ;
V_50 = F_542 ( V_50 ) ;
V_101 = F_540 ( V_50 ) ;
}
* V_61 = V_359 - V_163 ;
return V_50 ;
V_537:
F_237 () ;
V_50 = F_543 ( & V_262 -> V_265 , V_359 ) ;
F_45 ( ! V_50 ) ;
* V_61 = 0 ;
if ( F_134 ( F_544 ( V_50 ) ) ) {
unsigned long V_12 =
( unsigned long ) V_50 >> V_542 ;
V_50 = F_543 ( & V_262 -> V_265 , V_12 ) ;
F_45 ( ! V_50 ) ;
* V_61 = V_359 - V_12 ;
}
F_240 () ;
return V_50 ;
}
struct V_56 *
F_145 ( struct V_1 * V_2 , unsigned int V_359 )
{
struct V_49 * V_50 ;
unsigned int V_61 ;
F_45 ( ! F_128 ( V_2 ) ) ;
V_50 = F_539 ( V_2 , V_359 , & V_61 ) ;
return F_545 ( F_254 ( V_50 ) , V_61 ) ;
}
struct V_56 *
F_546 ( struct V_1 * V_2 ,
unsigned int V_359 )
{
struct V_56 * V_56 ;
V_56 = F_145 ( V_2 , V_359 ) ;
if ( ! V_2 -> V_13 . V_73 )
F_48 ( V_56 ) ;
return V_56 ;
}
T_16
F_160 ( struct V_1 * V_2 ,
unsigned long V_359 )
{
struct V_49 * V_50 ;
unsigned int V_61 ;
V_50 = F_539 ( V_2 , V_359 , & V_61 ) ;
return F_40 ( V_50 ) + ( V_61 << V_164 ) ;
}
int F_547 ( struct V_1 * V_2 , int V_543 )
{
struct V_42 * V_68 ;
int V_190 ;
if ( V_543 > V_2 -> V_12 . V_11 )
return - V_53 ;
if ( V_2 -> V_191 == & V_544 )
return 0 ;
if ( V_2 -> V_191 != & V_443 )
return - V_53 ;
V_190 = F_53 ( V_2 ) ;
if ( V_190 )
return V_190 ;
F_19 ( & V_2 -> V_13 . V_138 ) ;
if ( V_2 -> V_13 . V_70 != V_76 ) {
V_190 = - V_119 ;
goto V_236;
}
if ( V_2 -> V_13 . V_302 ) {
V_190 = - V_119 ;
goto V_236;
}
if ( V_2 -> V_13 . V_44 ) {
V_190 = - V_246 ;
goto V_236;
}
V_68 = V_2 -> V_13 . V_68 ;
V_2 -> V_191 = & V_544 ;
V_190 = F_270 ( V_2 ) ;
if ( V_190 )
goto V_545;
F_269 ( V_2 ) ;
if ( ! F_273 ( V_68 ) )
V_443 . V_272 ( V_2 , V_68 ) ;
F_22 ( & V_2 -> V_13 . V_138 ) ;
return 0 ;
V_545:
V_2 -> V_191 = & V_443 ;
V_2 -> V_13 . V_68 = V_68 ;
V_236:
F_22 ( & V_2 -> V_13 . V_138 ) ;
return V_190 ;
}

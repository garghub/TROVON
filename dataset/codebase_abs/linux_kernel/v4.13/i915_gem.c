static bool F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return false ;
if ( ! V_2 -> V_4 )
return true ;
return V_2 -> V_5 ;
}
static int
F_2 ( struct V_6 * V_7 ,
struct V_8 * V_9 , T_1 V_10 )
{
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
return F_3 ( & V_7 -> V_11 . V_12 , V_9 ,
V_10 , 0 , V_13 ,
0 , V_7 -> V_14 ,
V_15 ) ;
}
static void
F_4 ( struct V_8 * V_9 )
{
F_5 ( V_9 ) ;
}
static void F_6 ( struct V_16 * V_17 ,
T_2 V_10 )
{
F_7 ( & V_17 -> V_12 . V_18 ) ;
V_17 -> V_12 . V_19 ++ ;
V_17 -> V_12 . V_20 += V_10 ;
F_8 ( & V_17 -> V_12 . V_18 ) ;
}
static void F_9 ( struct V_16 * V_17 ,
T_2 V_10 )
{
F_7 ( & V_17 -> V_12 . V_18 ) ;
V_17 -> V_12 . V_19 -- ;
V_17 -> V_12 . V_20 -= V_10 ;
F_8 ( & V_17 -> V_12 . V_18 ) ;
}
static int
F_10 ( struct V_21 * error )
{
int V_22 ;
F_11 () ;
V_22 = F_12 ( error -> V_23 ,
! F_13 ( error ) ,
V_24 ) ;
if ( V_22 == 0 ) {
F_14 ( L_1 ) ;
return - V_25 ;
} else if ( V_22 < 0 ) {
return V_22 ;
} else {
return 0 ;
}
}
int F_15 ( struct V_26 * V_27 )
{
struct V_16 * V_17 = F_16 ( V_27 ) ;
int V_22 ;
V_22 = F_10 ( & V_17 -> V_28 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_17 ( & V_27 -> V_29 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
int
F_18 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_16 * V_17 = F_16 ( V_27 ) ;
struct V_6 * V_7 = & V_17 -> V_7 ;
struct V_33 * args = V_30 ;
struct V_34 * V_35 ;
T_2 V_36 ;
V_36 = V_7 -> V_11 . V_37 ;
F_19 ( & V_27 -> V_29 ) ;
F_20 (vma, &ggtt->base.active_list, vm_link)
if ( F_21 ( V_35 ) )
V_36 += V_35 -> V_9 . V_10 ;
F_20 (vma, &ggtt->base.inactive_list, vm_link)
if ( F_21 ( V_35 ) )
V_36 += V_35 -> V_9 . V_10 ;
F_22 ( & V_27 -> V_29 ) ;
args -> V_38 = V_7 -> V_11 . V_39 ;
args -> V_40 = args -> V_38 - V_36 ;
return 0 ;
}
static struct V_41 *
F_23 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_11 . V_44 -> V_45 ;
T_3 * V_46 ;
struct V_41 * V_47 ;
struct V_48 * V_49 ;
char * V_50 ;
int V_51 ;
if ( F_24 ( F_25 ( V_2 ) ) )
return F_26 ( - V_52 ) ;
V_46 = F_27 ( V_2 -> V_11 . V_27 ,
V_2 -> V_11 . V_10 ,
F_28 ( V_2 -> V_11 . V_10 ) ) ;
if ( ! V_46 )
return F_26 ( - V_53 ) ;
V_50 = V_46 -> V_50 ;
for ( V_51 = 0 ; V_51 < V_2 -> V_11 . V_10 / V_54 ; V_51 ++ ) {
struct V_55 * V_55 ;
char * V_56 ;
V_55 = F_29 ( V_43 , V_51 ) ;
if ( F_30 ( V_55 ) ) {
V_47 = F_31 ( V_55 ) ;
goto V_57;
}
V_56 = F_32 ( V_55 ) ;
memcpy ( V_50 , V_56 , V_54 ) ;
F_33 ( V_50 , V_54 ) ;
F_34 ( V_56 ) ;
F_35 ( V_55 ) ;
V_50 += V_54 ;
}
F_36 ( F_16 ( V_2 -> V_11 . V_27 ) ) ;
V_47 = F_37 ( sizeof( * V_47 ) , V_58 ) ;
if ( ! V_47 ) {
V_47 = F_26 ( - V_53 ) ;
goto V_57;
}
if ( F_38 ( V_47 , 1 , V_58 ) ) {
F_39 ( V_47 ) ;
V_47 = F_26 ( - V_53 ) ;
goto V_57;
}
V_49 = V_47 -> V_59 ;
V_49 -> V_60 = 0 ;
V_49 -> V_61 = V_2 -> V_11 . V_10 ;
F_40 ( V_49 ) = V_46 -> V_62 ;
F_41 ( V_49 ) = V_2 -> V_11 . V_10 ;
V_2 -> V_63 = V_46 ;
return V_47 ;
V_57:
F_42 ( V_2 -> V_11 . V_27 , V_46 ) ;
return V_47 ;
}
static void F_43 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_64 = V_65 ;
V_2 -> V_11 . V_66 = V_65 ;
if ( F_1 ( V_2 ) )
V_2 -> V_3 = true ;
}
static void
F_44 ( struct V_1 * V_2 ,
struct V_41 * V_67 ,
bool V_68 )
{
F_45 ( V_2 -> V_12 . V_69 == V_70 ) ;
if ( V_2 -> V_12 . V_69 == V_71 )
V_2 -> V_12 . V_72 = false ;
if ( V_68 &&
( V_2 -> V_11 . V_64 & V_65 ) == 0 &&
! V_2 -> V_4 )
F_46 ( V_67 ) ;
F_43 ( V_2 ) ;
}
static void
F_47 ( struct V_1 * V_2 ,
struct V_41 * V_67 )
{
F_44 ( V_2 , V_67 , false ) ;
if ( V_2 -> V_12 . V_72 ) {
struct V_42 * V_43 = V_2 -> V_11 . V_44 -> V_45 ;
char * V_50 = V_2 -> V_63 -> V_50 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_2 -> V_11 . V_10 / V_54 ; V_51 ++ ) {
struct V_55 * V_55 ;
char * V_73 ;
V_55 = F_29 ( V_43 , V_51 ) ;
if ( F_30 ( V_55 ) )
continue;
V_73 = F_32 ( V_55 ) ;
F_33 ( V_50 , V_54 ) ;
memcpy ( V_73 , V_50 , V_54 ) ;
F_34 ( V_73 ) ;
F_48 ( V_55 ) ;
if ( V_2 -> V_12 . V_69 == V_74 )
F_49 ( V_55 ) ;
F_35 ( V_55 ) ;
V_50 += V_54 ;
}
V_2 -> V_12 . V_72 = false ;
}
F_50 ( V_67 ) ;
F_39 ( V_67 ) ;
F_42 ( V_2 -> V_11 . V_27 , V_2 -> V_63 ) ;
}
static void
F_51 ( struct V_1 * V_2 )
{
F_52 ( V_2 ) ;
}
int F_53 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
F_54 ( V_75 ) ;
int V_22 ;
F_55 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
V_22 = F_56 ( V_2 ,
V_76 |
V_77 |
V_78 ,
V_79 ,
NULL ) ;
if ( V_22 )
return V_22 ;
F_57 ( F_16 ( V_2 -> V_11 . V_27 ) ) ;
while ( ( V_35 = F_58 ( & V_2 -> V_80 ,
struct V_34 ,
V_81 ) ) ) {
F_59 ( & V_35 -> V_81 , & V_75 ) ;
V_22 = F_60 ( V_35 ) ;
if ( V_22 )
break;
}
F_61 ( & V_75 , & V_2 -> V_80 ) ;
return V_22 ;
}
static long
F_62 ( struct V_82 * V_83 ,
unsigned int V_84 ,
long V_85 ,
struct V_86 * V_87 )
{
struct V_88 * V_89 ;
F_63 ( V_76 != 0x1 ) ;
if ( F_64 ( V_90 , & V_83 -> V_84 ) )
return V_85 ;
if ( ! F_65 ( V_83 ) )
return F_66 ( V_83 ,
V_84 & V_76 ,
V_85 ) ;
V_89 = F_67 ( V_83 ) ;
if ( F_68 ( V_89 ) )
goto V_91;
if ( V_87 ) {
if ( F_69 ( V_89 -> V_92 ) >= 6 )
F_70 ( V_89 -> V_92 , V_87 , V_89 -> V_93 ) ;
else
V_87 = NULL ;
}
V_85 = F_71 ( V_89 , V_84 , V_85 ) ;
V_91:
if ( V_84 & V_77 && F_68 ( V_89 ) )
F_72 ( V_89 ) ;
if ( V_87 && F_73 ( V_89 ) == F_74 ( V_89 -> V_94 ) ) {
F_7 ( & V_89 -> V_92 -> V_87 . V_95 ) ;
F_75 ( & V_87 -> V_96 ) ;
F_8 ( & V_89 -> V_92 -> V_87 . V_95 ) ;
}
return V_85 ;
}
static long
F_76 ( struct V_97 * V_98 ,
unsigned int V_84 ,
long V_85 ,
struct V_86 * V_87 )
{
unsigned int V_99 = F_77 ( & V_98 -> V_99 ) ;
struct V_82 * V_100 ;
bool V_101 = false ;
if ( V_84 & V_78 ) {
struct V_82 * * V_102 ;
unsigned int V_103 , V_51 ;
int V_22 ;
V_22 = F_78 ( V_98 ,
& V_100 , & V_103 , & V_102 ) ;
if ( V_22 )
return V_22 ;
for ( V_51 = 0 ; V_51 < V_103 ; V_51 ++ ) {
V_85 = F_62 ( V_102 [ V_51 ] ,
V_84 , V_85 ,
V_87 ) ;
if ( V_85 < 0 )
break;
F_79 ( V_102 [ V_51 ] ) ;
}
for (; V_51 < V_103 ; V_51 ++ )
F_79 ( V_102 [ V_51 ] ) ;
F_39 ( V_102 ) ;
V_101 = V_103 && V_85 >= 0 ;
} else {
V_100 = F_80 ( V_98 ) ;
}
if ( V_100 && V_85 >= 0 ) {
V_85 = F_62 ( V_100 , V_84 , V_85 , V_87 ) ;
V_101 = V_85 >= 0 ;
}
F_79 ( V_100 ) ;
if ( V_101 && ! F_81 ( & V_98 -> V_99 , V_99 ) ) {
if ( F_82 ( V_98 ) ) {
if ( ! F_81 ( & V_98 -> V_99 , V_99 ) )
F_83 ( V_98 , NULL ) ;
F_84 ( V_98 ) ;
}
}
return V_85 ;
}
static void F_85 ( struct V_82 * V_83 , int V_104 )
{
struct V_88 * V_89 ;
struct V_105 * V_94 ;
if ( ! F_65 ( V_83 ) )
return;
V_89 = F_67 ( V_83 ) ;
V_94 = V_89 -> V_94 ;
if ( ! V_94 -> V_106 )
return;
V_94 -> V_106 ( V_89 , V_104 ) ;
}
static void F_86 ( struct V_82 * V_83 , int V_104 )
{
if ( F_87 ( V_83 ) ) {
struct V_107 * V_108 = F_88 ( V_83 ) ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_108 -> V_109 ; V_51 ++ )
F_85 ( V_108 -> V_110 [ V_51 ] , V_104 ) ;
} else {
F_85 ( V_83 , V_104 ) ;
}
}
int
F_89 ( struct V_1 * V_2 ,
unsigned int V_84 ,
int V_104 )
{
struct V_82 * V_100 ;
if ( V_84 & V_78 ) {
struct V_82 * * V_102 ;
unsigned int V_103 , V_51 ;
int V_22 ;
V_22 = F_78 ( V_2 -> V_98 ,
& V_100 , & V_103 , & V_102 ) ;
if ( V_22 )
return V_22 ;
for ( V_51 = 0 ; V_51 < V_103 ; V_51 ++ ) {
F_86 ( V_102 [ V_51 ] , V_104 ) ;
F_79 ( V_102 [ V_51 ] ) ;
}
F_39 ( V_102 ) ;
} else {
V_100 = F_80 ( V_2 -> V_98 ) ;
}
if ( V_100 ) {
F_86 ( V_100 , V_104 ) ;
F_79 ( V_100 ) ;
}
return 0 ;
}
int
F_56 ( struct V_1 * V_2 ,
unsigned int V_84 ,
long V_85 ,
struct V_86 * V_87 )
{
F_11 () ;
#if F_90 ( V_111 )
F_45 ( V_112 &&
! ! F_91 ( & V_2 -> V_11 . V_27 -> V_29 ) !=
! ! ( V_84 & V_77 ) ) ;
#endif
F_45 ( V_85 < 0 ) ;
V_85 = F_76 ( V_2 -> V_98 ,
V_84 , V_85 ,
V_87 ) ;
return V_85 < 0 ? V_85 : 0 ;
}
static struct V_86 * F_92 ( struct V_31 * V_32 )
{
struct V_113 * V_114 = V_32 -> V_115 ;
return & V_114 -> V_87 ;
}
int
F_93 ( struct V_1 * V_2 ,
int V_116 )
{
int V_22 ;
if ( V_116 > V_2 -> V_11 . V_10 )
return - V_52 ;
if ( V_2 -> V_117 == & V_118 )
return 0 ;
if ( V_2 -> V_12 . V_69 != V_74 )
return - V_119 ;
if ( V_2 -> V_11 . V_44 == NULL )
return - V_52 ;
V_22 = F_53 ( V_2 ) ;
if ( V_22 )
return V_22 ;
F_94 ( V_2 , V_120 ) ;
if ( V_2 -> V_12 . V_67 )
return - V_121 ;
F_45 ( V_2 -> V_117 != & V_122 ) ;
V_2 -> V_117 = & V_118 ;
V_22 = F_95 ( V_2 ) ;
if ( V_22 )
goto V_123;
return 0 ;
V_123:
V_2 -> V_117 = & V_122 ;
return V_22 ;
}
static int
F_96 ( struct V_1 * V_2 ,
struct V_124 * args ,
struct V_31 * V_32 )
{
void * V_50 = V_2 -> V_63 -> V_50 + args -> V_60 ;
char T_4 * V_125 = F_97 ( args -> V_126 ) ;
F_98 ( V_2 , V_127 ) ;
if ( F_99 ( V_50 , V_125 , args -> V_10 ) )
return - V_119 ;
F_33 ( V_50 , args -> V_10 ) ;
F_36 ( F_16 ( V_2 -> V_11 . V_27 ) ) ;
F_100 ( V_2 , V_127 ) ;
return 0 ;
}
void * F_101 ( struct V_16 * V_17 )
{
return F_102 ( V_17 -> V_128 , V_58 ) ;
}
void F_103 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_16 ( V_2 -> V_11 . V_27 ) ;
F_104 ( V_17 -> V_128 , V_2 ) ;
}
static int
F_105 ( struct V_31 * V_32 ,
struct V_16 * V_17 ,
T_5 V_10 ,
T_6 * V_129 )
{
struct V_1 * V_2 ;
int V_22 ;
T_1 V_130 ;
V_10 = F_106 ( V_10 , V_54 ) ;
if ( V_10 == 0 )
return - V_52 ;
V_2 = F_107 ( V_17 , V_10 ) ;
if ( F_30 ( V_2 ) )
return F_108 ( V_2 ) ;
V_22 = F_109 ( V_32 , & V_2 -> V_11 , & V_130 ) ;
F_110 ( V_2 ) ;
if ( V_22 )
return V_22 ;
* V_129 = V_130 ;
return 0 ;
}
int
F_111 ( struct V_31 * V_32 ,
struct V_26 * V_27 ,
struct V_131 * args )
{
args -> V_132 = F_112 ( args -> V_133 * F_113 ( args -> V_134 , 8 ) , 64 ) ;
args -> V_10 = args -> V_132 * args -> V_135 ;
return F_105 ( V_32 , F_16 ( V_27 ) ,
args -> V_10 , & args -> V_130 ) ;
}
static bool F_114 ( struct V_1 * V_2 )
{
return ! ( V_2 -> V_136 == V_137 ||
V_2 -> V_136 == V_138 ) ;
}
int
F_115 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_16 * V_17 = F_16 ( V_27 ) ;
struct V_139 * args = V_30 ;
F_116 ( V_17 ) ;
return F_105 ( V_32 , V_17 ,
args -> V_10 , & args -> V_130 ) ;
}
static inline enum V_140
F_117 ( struct V_1 * V_2 , unsigned int V_141 )
{
return ( V_141 == V_142 ?
V_2 -> V_143 : V_127 ) ;
}
static void
F_118 ( struct V_1 * V_2 , unsigned int V_144 )
{
struct V_16 * V_17 = F_16 ( V_2 -> V_11 . V_27 ) ;
if ( ! ( V_2 -> V_11 . V_66 & V_144 ) )
return;
F_119 () ;
switch ( V_2 -> V_11 . V_66 ) {
case V_142 :
if ( F_69 ( V_17 ) >= 6 && ! F_120 ( V_17 ) ) {
if ( F_121 ( V_17 ) ) {
F_122 ( & V_17 -> V_145 . V_146 ) ;
F_123 ( F_124 ( V_17 -> V_94 [ V_147 ] -> V_148 ) ) ;
F_125 ( & V_17 -> V_145 . V_146 ) ;
F_126 ( V_17 ) ;
}
}
F_100 ( V_2 ,
F_117 ( V_2 , V_142 ) ) ;
break;
case V_65 :
F_127 ( V_2 , V_149 ) ;
break;
case V_150 :
if ( F_114 ( V_2 ) )
V_2 -> V_3 = true ;
break;
}
V_2 -> V_11 . V_66 = 0 ;
}
static inline int
F_128 ( char T_4 * V_151 ,
const char * V_152 , int V_153 ,
int V_61 )
{
int V_22 , V_154 = 0 ;
while ( V_61 > 0 ) {
int V_155 = F_112 ( V_153 + 1 , 64 ) ;
int V_156 = F_129 ( V_155 - V_153 , V_61 ) ;
int V_157 = V_153 ^ 64 ;
V_22 = F_130 ( V_151 + V_154 ,
V_152 + V_157 ,
V_156 ) ;
if ( V_22 )
return V_22 + V_61 ;
V_154 += V_156 ;
V_153 += V_156 ;
V_61 -= V_156 ;
}
return 0 ;
}
static inline int
F_131 ( char * V_152 , int V_153 ,
const char T_4 * V_151 ,
int V_61 )
{
int V_22 , V_154 = 0 ;
while ( V_61 > 0 ) {
int V_155 = F_112 ( V_153 + 1 , 64 ) ;
int V_156 = F_129 ( V_155 - V_153 , V_61 ) ;
int V_157 = V_153 ^ 64 ;
V_22 = F_132 ( V_152 + V_157 ,
V_151 + V_154 ,
V_156 ) ;
if ( V_22 )
return V_22 + V_61 ;
V_154 += V_156 ;
V_153 += V_156 ;
V_61 -= V_156 ;
}
return 0 ;
}
int F_133 ( struct V_1 * V_2 ,
unsigned int * V_68 )
{
int V_22 ;
F_55 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
* V_68 = 0 ;
if ( ! F_134 ( V_2 ) )
return - V_158 ;
V_22 = F_56 ( V_2 ,
V_76 |
V_77 ,
V_79 ,
NULL ) ;
if ( V_22 )
return V_22 ;
V_22 = F_95 ( V_2 ) ;
if ( V_22 )
return V_22 ;
if ( V_2 -> V_4 || ! F_135 ( V_159 ) ) {
V_22 = F_136 ( V_2 , false ) ;
if ( V_22 )
goto V_160;
else
goto V_91;
}
F_118 ( V_2 , ~ V_65 ) ;
if ( ! V_2 -> V_3 &&
! ( V_2 -> V_11 . V_64 & V_65 ) )
* V_68 = V_161 ;
V_91:
return 0 ;
V_160:
F_52 ( V_2 ) ;
return V_22 ;
}
int F_137 ( struct V_1 * V_2 ,
unsigned int * V_68 )
{
int V_22 ;
F_55 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
* V_68 = 0 ;
if ( ! F_134 ( V_2 ) )
return - V_158 ;
V_22 = F_56 ( V_2 ,
V_76 |
V_77 |
V_78 ,
V_79 ,
NULL ) ;
if ( V_22 )
return V_22 ;
V_22 = F_95 ( V_2 ) ;
if ( V_22 )
return V_22 ;
if ( V_2 -> V_4 || ! F_135 ( V_159 ) ) {
V_22 = F_136 ( V_2 , true ) ;
if ( V_22 )
goto V_160;
else
goto V_91;
}
F_118 ( V_2 , ~ V_65 ) ;
if ( ! V_2 -> V_3 ) {
* V_68 |= V_162 ;
if ( ! ( V_2 -> V_11 . V_64 & V_65 ) )
* V_68 |= V_161 ;
}
V_91:
F_98 ( V_2 , V_127 ) ;
V_2 -> V_12 . V_72 = true ;
return 0 ;
V_160:
F_52 ( V_2 ) ;
return V_22 ;
}
static void
F_138 ( char * V_163 , unsigned long V_61 ,
bool V_164 )
{
if ( F_139 ( V_164 ) ) {
unsigned long V_165 = ( unsigned long ) V_163 ;
unsigned long V_166 = ( unsigned long ) V_163 + V_61 ;
V_165 = F_140 ( V_165 , 128 ) ;
V_166 = F_141 ( V_166 , 128 ) ;
F_33 ( ( void * ) V_165 , V_166 - V_165 ) ;
} else {
F_33 ( V_163 , V_61 ) ;
}
}
static int
F_142 ( struct V_55 * V_55 , int V_60 , int V_61 ,
char T_4 * V_125 ,
bool V_167 , bool V_68 )
{
char * V_50 ;
int V_22 ;
V_50 = F_143 ( V_55 ) ;
if ( V_68 )
F_138 ( V_50 + V_60 , V_61 ,
V_167 ) ;
if ( V_167 )
V_22 = F_128 ( V_125 , V_50 , V_60 , V_61 ) ;
else
V_22 = F_130 ( V_125 , V_50 + V_60 , V_61 ) ;
F_144 ( V_55 ) ;
return V_22 ? - V_119 : 0 ;
}
static int
F_145 ( struct V_55 * V_55 , int V_60 , int V_61 , char T_4 * V_125 ,
bool V_167 , bool V_68 )
{
int V_22 ;
V_22 = - V_158 ;
if ( ! V_167 ) {
char * V_50 = F_32 ( V_55 ) ;
if ( V_68 )
F_33 ( V_50 + V_60 , V_61 ) ;
V_22 = F_146 ( V_125 , V_50 + V_60 , V_61 ) ;
F_34 ( V_50 ) ;
}
if ( V_22 == 0 )
return 0 ;
return F_142 ( V_55 , V_60 , V_61 , V_125 ,
V_167 , V_68 ) ;
}
static int
F_147 ( struct V_1 * V_2 ,
struct V_168 * args )
{
char T_4 * V_125 ;
T_2 V_169 ;
unsigned int V_170 ;
unsigned int V_68 ;
unsigned int V_171 , V_60 ;
int V_22 ;
V_170 = 0 ;
if ( F_25 ( V_2 ) )
V_170 = F_148 ( 17 ) ;
V_22 = F_17 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_133 ( V_2 , & V_68 ) ;
F_22 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
if ( V_22 )
return V_22 ;
V_169 = args -> V_10 ;
V_125 = F_97 ( args -> V_126 ) ;
V_60 = F_149 ( args -> V_60 ) ;
for ( V_171 = args -> V_60 >> V_172 ; V_169 ; V_171 ++ ) {
struct V_55 * V_55 = F_150 ( V_2 , V_171 ) ;
int V_61 ;
V_61 = V_169 ;
if ( V_60 + V_61 > V_54 )
V_61 = V_54 - V_60 ;
V_22 = F_145 ( V_55 , V_60 , V_61 , V_125 ,
F_151 ( V_55 ) & V_170 ,
V_68 ) ;
if ( V_22 )
break;
V_169 -= V_61 ;
V_125 += V_61 ;
V_60 = 0 ;
}
F_152 ( V_2 ) ;
return V_22 ;
}
static inline bool
F_153 ( struct V_173 * V_43 ,
T_7 V_11 , int V_60 ,
char T_4 * V_125 , int V_61 )
{
void * V_50 ;
unsigned long V_174 ;
V_50 = ( void V_175 * ) F_154 ( V_43 , V_11 ) ;
V_174 = F_146 ( V_125 , V_50 + V_60 , V_61 ) ;
F_155 ( V_50 ) ;
if ( V_174 ) {
V_50 = ( void V_175 * )
F_156 ( V_43 , V_11 , V_54 ) ;
V_174 = F_157 ( V_125 , V_50 + V_60 , V_61 ) ;
F_158 ( V_50 ) ;
}
return V_174 ;
}
static int
F_159 ( struct V_1 * V_2 ,
const struct V_168 * args )
{
struct V_16 * V_92 = F_16 ( V_2 -> V_11 . V_27 ) ;
struct V_6 * V_7 = & V_92 -> V_7 ;
struct V_8 V_9 ;
struct V_34 * V_35 ;
void T_4 * V_125 ;
T_2 V_169 , V_60 ;
int V_22 ;
V_22 = F_17 ( & V_92 -> V_176 . V_29 ) ;
if ( V_22 )
return V_22 ;
F_160 ( V_92 ) ;
V_35 = F_161 ( V_2 , NULL , 0 , 0 ,
V_177 | V_178 ) ;
if ( ! F_30 ( V_35 ) ) {
V_9 . V_165 = F_162 ( V_35 ) ;
V_9 . V_179 = false ;
V_22 = F_163 ( V_35 ) ;
if ( V_22 ) {
F_164 ( V_35 ) ;
V_35 = F_26 ( V_22 ) ;
}
}
if ( F_30 ( V_35 ) ) {
V_22 = F_2 ( V_7 , & V_9 , V_54 ) ;
if ( V_22 )
goto V_180;
F_45 ( ! V_9 . V_179 ) ;
}
V_22 = F_165 ( V_2 , false ) ;
if ( V_22 )
goto V_181;
F_22 ( & V_92 -> V_176 . V_29 ) ;
V_125 = F_97 ( args -> V_126 ) ;
V_169 = args -> V_10 ;
V_60 = args -> V_60 ;
while ( V_169 > 0 ) {
T_1 V_182 = V_9 . V_165 ;
unsigned V_183 = F_149 ( V_60 ) ;
unsigned V_184 = V_54 - V_183 ;
V_184 = V_169 < V_184 ? V_169 : V_184 ;
if ( V_9 . V_179 ) {
F_119 () ;
V_7 -> V_11 . V_185 ( & V_7 -> V_11 ,
F_166 ( V_2 , V_60 >> V_172 ) ,
V_9 . V_165 , V_137 , 0 ) ;
F_119 () ;
} else {
V_182 += V_60 & V_186 ;
}
if ( F_153 ( & V_7 -> V_187 , V_182 , V_183 ,
V_125 , V_184 ) ) {
V_22 = - V_119 ;
break;
}
V_169 -= V_184 ;
V_125 += V_184 ;
V_60 += V_184 ;
}
F_19 ( & V_92 -> V_176 . V_29 ) ;
V_181:
if ( V_9 . V_179 ) {
F_119 () ;
V_7 -> V_11 . V_188 ( & V_7 -> V_11 ,
V_9 . V_165 , V_9 . V_10 ) ;
F_4 ( & V_9 ) ;
} else {
F_164 ( V_35 ) ;
}
V_180:
F_126 ( V_92 ) ;
F_22 ( & V_92 -> V_176 . V_29 ) ;
return V_22 ;
}
int
F_167 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_168 * args = V_30 ;
struct V_1 * V_2 ;
int V_22 ;
if ( args -> V_10 == 0 )
return 0 ;
if ( ! F_168 ( V_189 ,
F_97 ( args -> V_126 ) ,
args -> V_10 ) )
return - V_119 ;
V_2 = F_169 ( V_32 , args -> V_130 ) ;
if ( ! V_2 )
return - V_190 ;
if ( F_170 ( T_2 , args -> V_60 , args -> V_10 , V_2 -> V_11 . V_10 ) ) {
V_22 = - V_52 ;
goto V_91;
}
F_171 ( V_2 , args -> V_60 , args -> V_10 ) ;
V_22 = F_56 ( V_2 ,
V_76 ,
V_79 ,
F_92 ( V_32 ) ) ;
if ( V_22 )
goto V_91;
V_22 = F_95 ( V_2 ) ;
if ( V_22 )
goto V_91;
V_22 = F_147 ( V_2 , args ) ;
if ( V_22 == - V_119 || V_22 == - V_158 )
V_22 = F_159 ( V_2 , args ) ;
F_52 ( V_2 ) ;
V_91:
F_110 ( V_2 ) ;
return V_22 ;
}
static inline bool
F_172 ( struct V_173 * V_43 ,
T_7 V_11 , int V_60 ,
char T_4 * V_125 , int V_61 )
{
void * V_50 ;
unsigned long V_174 ;
V_50 = ( void V_175 * ) F_154 ( V_43 , V_11 ) ;
V_174 = F_173 ( V_50 + V_60 ,
V_125 , V_61 ) ;
F_155 ( V_50 ) ;
if ( V_174 ) {
V_50 = ( void V_175 * )
F_156 ( V_43 , V_11 , V_54 ) ;
V_174 = F_99 ( V_50 + V_60 , V_125 , V_61 ) ;
F_158 ( V_50 ) ;
}
return V_174 ;
}
static int
F_174 ( struct V_1 * V_2 ,
const struct V_124 * args )
{
struct V_16 * V_92 = F_16 ( V_2 -> V_11 . V_27 ) ;
struct V_6 * V_7 = & V_92 -> V_7 ;
struct V_8 V_9 ;
struct V_34 * V_35 ;
T_2 V_169 , V_60 ;
void T_4 * V_125 ;
int V_22 ;
V_22 = F_17 ( & V_92 -> V_176 . V_29 ) ;
if ( V_22 )
return V_22 ;
F_160 ( V_92 ) ;
V_35 = F_161 ( V_2 , NULL , 0 , 0 ,
V_177 | V_178 ) ;
if ( ! F_30 ( V_35 ) ) {
V_9 . V_165 = F_162 ( V_35 ) ;
V_9 . V_179 = false ;
V_22 = F_163 ( V_35 ) ;
if ( V_22 ) {
F_164 ( V_35 ) ;
V_35 = F_26 ( V_22 ) ;
}
}
if ( F_30 ( V_35 ) ) {
V_22 = F_2 ( V_7 , & V_9 , V_54 ) ;
if ( V_22 )
goto V_180;
F_45 ( ! V_9 . V_179 ) ;
}
V_22 = F_165 ( V_2 , true ) ;
if ( V_22 )
goto V_181;
F_22 ( & V_92 -> V_176 . V_29 ) ;
F_98 ( V_2 , V_127 ) ;
V_125 = F_97 ( args -> V_126 ) ;
V_60 = args -> V_60 ;
V_169 = args -> V_10 ;
while ( V_169 ) {
T_1 V_182 = V_9 . V_165 ;
unsigned int V_183 = F_149 ( V_60 ) ;
unsigned int V_184 = V_54 - V_183 ;
V_184 = V_169 < V_184 ? V_169 : V_184 ;
if ( V_9 . V_179 ) {
F_119 () ;
V_7 -> V_11 . V_185 ( & V_7 -> V_11 ,
F_166 ( V_2 , V_60 >> V_172 ) ,
V_9 . V_165 , V_137 , 0 ) ;
F_119 () ;
} else {
V_182 += V_60 & V_186 ;
}
if ( F_172 ( & V_7 -> V_187 , V_182 , V_183 ,
V_125 , V_184 ) ) {
V_22 = - V_119 ;
break;
}
V_169 -= V_184 ;
V_125 += V_184 ;
V_60 += V_184 ;
}
F_100 ( V_2 , V_127 ) ;
F_19 ( & V_92 -> V_176 . V_29 ) ;
V_181:
if ( V_9 . V_179 ) {
F_119 () ;
V_7 -> V_11 . V_188 ( & V_7 -> V_11 ,
V_9 . V_165 , V_9 . V_10 ) ;
F_4 ( & V_9 ) ;
} else {
F_164 ( V_35 ) ;
}
V_180:
F_126 ( V_92 ) ;
F_22 ( & V_92 -> V_176 . V_29 ) ;
return V_22 ;
}
static int
F_175 ( struct V_55 * V_55 , int V_60 , int V_61 ,
char T_4 * V_125 ,
bool V_167 ,
bool V_191 ,
bool V_192 )
{
char * V_50 ;
int V_22 ;
V_50 = F_143 ( V_55 ) ;
if ( F_139 ( V_191 || V_167 ) )
F_138 ( V_50 + V_60 , V_61 ,
V_167 ) ;
if ( V_167 )
V_22 = F_131 ( V_50 , V_60 , V_125 ,
V_61 ) ;
else
V_22 = F_132 ( V_50 + V_60 , V_125 , V_61 ) ;
if ( V_192 )
F_138 ( V_50 + V_60 , V_61 ,
V_167 ) ;
F_144 ( V_55 ) ;
return V_22 ? - V_119 : 0 ;
}
static int
F_176 ( struct V_55 * V_55 , int V_60 , int V_193 , char T_4 * V_125 ,
bool V_167 ,
bool V_191 ,
bool V_192 )
{
int V_22 ;
V_22 = - V_158 ;
if ( ! V_167 ) {
char * V_50 = F_32 ( V_55 ) ;
if ( V_191 )
F_33 ( V_50 + V_60 , V_193 ) ;
V_22 = F_177 ( V_50 + V_60 , V_125 , V_193 ) ;
if ( V_192 )
F_33 ( V_50 + V_60 , V_193 ) ;
F_34 ( V_50 ) ;
}
if ( V_22 == 0 )
return V_22 ;
return F_175 ( V_55 , V_60 , V_193 , V_125 ,
V_167 ,
V_191 ,
V_192 ) ;
}
static int
F_178 ( struct V_1 * V_2 ,
const struct V_124 * args )
{
struct V_16 * V_92 = F_16 ( V_2 -> V_11 . V_27 ) ;
void T_4 * V_125 ;
T_2 V_169 ;
unsigned int V_170 ;
unsigned int V_194 ;
unsigned int V_68 ;
unsigned int V_60 , V_171 ;
int V_22 ;
V_22 = F_17 ( & V_92 -> V_176 . V_29 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_137 ( V_2 , & V_68 ) ;
F_22 ( & V_92 -> V_176 . V_29 ) ;
if ( V_22 )
return V_22 ;
V_170 = 0 ;
if ( F_25 ( V_2 ) )
V_170 = F_148 ( 17 ) ;
V_194 = 0 ;
if ( V_68 & V_161 )
V_194 = V_195 . V_196 - 1 ;
V_125 = F_97 ( args -> V_126 ) ;
V_169 = args -> V_10 ;
V_60 = F_149 ( args -> V_60 ) ;
for ( V_171 = args -> V_60 >> V_172 ; V_169 ; V_171 ++ ) {
struct V_55 * V_55 = F_150 ( V_2 , V_171 ) ;
int V_61 ;
V_61 = V_169 ;
if ( V_60 + V_61 > V_54 )
V_61 = V_54 - V_60 ;
V_22 = F_176 ( V_55 , V_60 , V_61 , V_125 ,
F_151 ( V_55 ) & V_170 ,
( V_60 | V_61 ) & V_194 ,
V_68 & V_162 ) ;
if ( V_22 )
break;
V_169 -= V_61 ;
V_125 += V_61 ;
V_60 = 0 ;
}
F_100 ( V_2 , V_127 ) ;
F_152 ( V_2 ) ;
return V_22 ;
}
int
F_179 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_124 * args = V_30 ;
struct V_1 * V_2 ;
int V_22 ;
if ( args -> V_10 == 0 )
return 0 ;
if ( ! F_168 ( V_197 ,
F_97 ( args -> V_126 ) ,
args -> V_10 ) )
return - V_119 ;
V_2 = F_169 ( V_32 , args -> V_130 ) ;
if ( ! V_2 )
return - V_190 ;
if ( F_170 ( T_2 , args -> V_60 , args -> V_10 , V_2 -> V_11 . V_10 ) ) {
V_22 = - V_52 ;
goto V_198;
}
F_180 ( V_2 , args -> V_60 , args -> V_10 ) ;
V_22 = - V_158 ;
if ( V_2 -> V_117 -> V_199 )
V_22 = V_2 -> V_117 -> V_199 ( V_2 , args ) ;
if ( V_22 != - V_158 )
goto V_198;
V_22 = F_56 ( V_2 ,
V_76 |
V_78 ,
V_79 ,
F_92 ( V_32 ) ) ;
if ( V_22 )
goto V_198;
V_22 = F_95 ( V_2 ) ;
if ( V_22 )
goto V_198;
V_22 = - V_119 ;
if ( ! F_134 ( V_2 ) ||
F_1 ( V_2 ) )
V_22 = F_174 ( V_2 , args ) ;
if ( V_22 == - V_119 || V_22 == - V_200 ) {
if ( V_2 -> V_63 )
V_22 = F_96 ( V_2 , args , V_32 ) ;
else
V_22 = F_178 ( V_2 , args ) ;
}
F_52 ( V_2 ) ;
V_198:
F_110 ( V_2 ) ;
return V_22 ;
}
static void F_181 ( struct V_1 * V_2 )
{
struct V_16 * V_92 ;
struct V_201 * V_202 ;
struct V_34 * V_35 ;
F_20 (vma, &obj->vma_list, obj_link) {
if ( ! F_182 ( V_35 ) )
break;
if ( F_183 ( V_35 ) )
continue;
if ( ! F_184 ( & V_35 -> V_9 ) )
continue;
F_59 ( & V_35 -> V_203 , & V_35 -> V_204 -> V_205 ) ;
}
V_92 = F_16 ( V_2 -> V_11 . V_27 ) ;
V_202 = V_2 -> V_206 ? & V_92 -> V_12 . V_207 : & V_92 -> V_12 . V_208 ;
F_59 ( & V_2 -> V_209 , V_202 ) ;
}
int
F_185 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_210 * args = V_30 ;
struct V_1 * V_2 ;
T_6 V_64 = args -> V_64 ;
T_6 V_66 = args -> V_66 ;
int V_198 ;
if ( ( V_66 | V_64 ) & V_211 )
return - V_52 ;
if ( V_66 != 0 && V_64 != V_66 )
return - V_52 ;
V_2 = F_169 ( V_32 , args -> V_130 ) ;
if ( ! V_2 )
return - V_190 ;
V_198 = F_56 ( V_2 ,
V_76 |
( V_66 ? V_78 : 0 ) ,
V_79 ,
F_92 ( V_32 ) ) ;
if ( V_198 )
goto V_91;
V_198 = F_95 ( V_2 ) ;
if ( V_198 )
goto V_91;
V_198 = F_15 ( V_27 ) ;
if ( V_198 )
goto V_181;
if ( V_64 & V_212 )
V_198 = F_186 ( V_2 , V_66 ) ;
else if ( V_64 & V_142 )
V_198 = F_165 ( V_2 , V_66 ) ;
else
V_198 = F_136 ( V_2 , V_66 ) ;
F_181 ( V_2 ) ;
F_22 ( & V_27 -> V_29 ) ;
if ( V_66 != 0 )
F_98 ( V_2 ,
F_117 ( V_2 , V_66 ) ) ;
V_181:
F_52 ( V_2 ) ;
V_91:
F_110 ( V_2 ) ;
return V_198 ;
}
int
F_187 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_213 * args = V_30 ;
struct V_1 * V_2 ;
V_2 = F_169 ( V_32 , args -> V_130 ) ;
if ( ! V_2 )
return - V_190 ;
F_188 ( V_2 ) ;
F_110 ( V_2 ) ;
return 0 ;
}
int
F_189 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_214 * args = V_30 ;
struct V_1 * V_2 ;
unsigned long V_163 ;
if ( args -> V_84 & ~ ( V_215 ) )
return - V_52 ;
if ( args -> V_84 & V_215 && ! F_190 ( V_216 ) )
return - V_158 ;
V_2 = F_169 ( V_32 , args -> V_130 ) ;
if ( ! V_2 )
return - V_190 ;
if ( ! V_2 -> V_11 . V_44 ) {
F_110 ( V_2 ) ;
return - V_52 ;
}
V_163 = F_191 ( V_2 -> V_11 . V_44 , 0 , args -> V_10 ,
V_217 | V_218 , V_219 ,
args -> V_60 ) ;
if ( args -> V_84 & V_215 ) {
struct V_220 * V_12 = V_221 -> V_12 ;
struct V_222 * V_35 ;
if ( F_192 ( & V_12 -> V_223 ) ) {
F_110 ( V_2 ) ;
return - V_224 ;
}
V_35 = F_193 ( V_12 , V_163 ) ;
if ( V_35 )
V_35 -> V_225 =
F_194 ( F_195 ( V_35 -> V_226 ) ) ;
else
V_163 = - V_53 ;
F_196 ( & V_12 -> V_223 ) ;
F_197 ( V_2 -> V_143 , V_127 ) ;
}
F_110 ( V_2 ) ;
if ( F_30 ( ( void * ) V_163 ) )
return V_163 ;
args -> V_227 = ( T_5 ) V_163 ;
return 0 ;
}
static unsigned int F_198 ( struct V_1 * V_2 )
{
return F_199 ( V_2 ) >> V_172 ;
}
int F_200 ( void )
{
return 2 ;
}
static inline struct V_228
F_201 ( struct V_1 * V_2 ,
T_8 V_183 ,
unsigned int V_229 )
{
struct V_228 V_230 ;
if ( F_202 ( V_2 ) )
V_229 = F_106 ( V_229 , F_198 ( V_2 ) ) ;
V_230 . type = V_231 ;
V_230 . V_232 . V_60 = F_203 ( V_183 , V_229 ) ;
V_230 . V_232 . V_10 =
F_204 (unsigned int, chunk,
(obj->base.size >> PAGE_SHIFT) - view.partial.offset) ;
if ( V_229 >= V_2 -> V_11 . V_10 >> V_172 )
V_230 . type = V_233 ;
return V_230 ;
}
int F_205 ( struct V_234 * V_235 )
{
#define F_206 ((1 << 20) >> PAGE_SHIFT)
struct V_222 * V_236 = V_235 -> V_35 ;
struct V_1 * V_2 = F_207 ( V_236 -> V_237 ) ;
struct V_26 * V_27 = V_2 -> V_11 . V_27 ;
struct V_16 * V_17 = F_16 ( V_27 ) ;
struct V_6 * V_7 = & V_17 -> V_7 ;
bool V_238 = ! ! ( V_235 -> V_84 & V_239 ) ;
struct V_34 * V_35 ;
T_8 V_183 ;
unsigned int V_84 ;
int V_22 ;
V_183 = ( V_235 -> V_240 - V_236 -> V_241 ) >> V_172 ;
F_208 ( V_2 , V_183 , true , V_238 ) ;
V_22 = F_56 ( V_2 ,
V_76 ,
V_79 ,
NULL ) ;
if ( V_22 )
goto V_198;
V_22 = F_95 ( V_2 ) ;
if ( V_22 )
goto V_198;
F_160 ( V_17 ) ;
V_22 = F_15 ( V_27 ) ;
if ( V_22 )
goto V_242;
if ( V_2 -> V_136 != V_137 && ! F_120 ( V_17 ) ) {
V_22 = - V_119 ;
goto V_243;
}
V_84 = V_177 ;
if ( V_2 -> V_11 . V_10 > 2 * F_206 << V_172 )
V_84 |= V_178 | V_244 ;
V_35 = F_161 ( V_2 , NULL , 0 , 0 , V_84 ) ;
if ( F_30 ( V_35 ) ) {
struct V_228 V_230 =
F_201 ( V_2 , V_183 , F_206 ) ;
V_2 -> V_143 = V_127 ;
V_35 = F_161 ( V_2 , & V_230 , 0 , 0 , V_177 ) ;
}
if ( F_30 ( V_35 ) ) {
V_22 = F_108 ( V_35 ) ;
goto V_243;
}
V_22 = F_165 ( V_2 , V_238 ) ;
if ( V_22 )
goto V_160;
V_22 = F_209 ( V_35 ) ;
if ( V_22 )
goto V_160;
F_210 ( V_17 ) ;
if ( F_211 ( & V_2 -> V_245 ) )
F_212 ( & V_2 -> V_245 , & V_17 -> V_12 . V_246 ) ;
V_22 = F_213 ( V_236 ,
V_236 -> V_241 + ( V_35 -> V_247 . V_232 . V_60 << V_172 ) ,
( V_7 -> V_248 + V_35 -> V_9 . V_165 ) >> V_172 ,
F_204 ( T_2 , V_35 -> V_10 , V_236 -> V_249 - V_236 -> V_241 ) ,
& V_7 -> V_187 ) ;
V_160:
F_214 ( V_35 ) ;
V_243:
F_22 ( & V_27 -> V_29 ) ;
V_242:
F_126 ( V_17 ) ;
F_52 ( V_2 ) ;
V_198:
switch ( V_22 ) {
case - V_25 :
if ( ! F_215 ( & V_17 -> V_28 ) ) {
V_22 = V_250 ;
break;
}
case - V_251 :
case 0 :
case - V_252 :
case - V_224 :
case - V_121 :
V_22 = V_253 ;
break;
case - V_53 :
V_22 = V_254 ;
break;
case - V_200 :
case - V_119 :
V_22 = V_250 ;
break;
default:
F_216 ( V_22 , L_2 , V_22 ) ;
V_22 = V_250 ;
break;
}
return V_22 ;
}
void
F_217 ( struct V_1 * V_2 )
{
struct V_16 * V_92 = F_16 ( V_2 -> V_11 . V_27 ) ;
F_55 ( & V_92 -> V_176 . V_29 ) ;
F_160 ( V_92 ) ;
if ( F_211 ( & V_2 -> V_245 ) )
goto V_91;
F_75 ( & V_2 -> V_245 ) ;
F_218 ( & V_2 -> V_11 . V_255 ,
V_2 -> V_11 . V_27 -> V_256 -> V_257 ) ;
F_119 () ;
V_91:
F_126 ( V_92 ) ;
}
void F_219 ( struct V_16 * V_17 )
{
struct V_1 * V_2 , * V_258 ;
int V_51 ;
F_220 (obj, on,
&dev_priv->mm.userfault_list, userfault_link) {
F_75 ( & V_2 -> V_245 ) ;
F_218 ( & V_2 -> V_11 . V_255 ,
V_2 -> V_11 . V_27 -> V_256 -> V_257 ) ;
}
for ( V_51 = 0 ; V_51 < V_17 -> V_259 ; V_51 ++ ) {
struct V_260 * V_261 = & V_17 -> V_262 [ V_51 ] ;
if ( ! V_261 -> V_35 )
continue;
F_45 ( ! F_211 ( & V_261 -> V_35 -> V_2 -> V_245 ) ) ;
V_261 -> V_72 = true ;
}
}
static int F_221 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_16 ( V_2 -> V_11 . V_27 ) ;
int V_198 ;
V_198 = F_222 ( & V_2 -> V_11 ) ;
if ( F_223 ( ! V_198 ) )
return 0 ;
do {
V_198 = F_224 ( V_17 , V_76 ) ;
if ( V_198 )
break;
F_225 ( V_17 ) ;
V_198 = F_222 ( & V_2 -> V_11 ) ;
if ( ! V_198 )
break;
} while ( F_226 ( & V_17 -> V_263 . V_264 ) );
return V_198 ;
}
static void F_227 ( struct V_1 * V_2 )
{
F_228 ( & V_2 -> V_11 ) ;
}
int
F_229 ( struct V_31 * V_32 ,
struct V_26 * V_27 ,
T_6 V_130 ,
T_5 * V_60 )
{
struct V_1 * V_2 ;
int V_22 ;
V_2 = F_169 ( V_32 , V_130 ) ;
if ( ! V_2 )
return - V_190 ;
V_22 = F_221 ( V_2 ) ;
if ( V_22 == 0 )
* V_60 = F_230 ( & V_2 -> V_11 . V_255 ) ;
F_110 ( V_2 ) ;
return V_22 ;
}
int
F_231 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_265 * args = V_30 ;
return F_229 ( V_32 , V_27 , args -> V_130 , & args -> V_60 ) ;
}
static void
F_232 ( struct V_1 * V_2 )
{
F_227 ( V_2 ) ;
if ( V_2 -> V_11 . V_44 == NULL )
return;
F_233 ( F_234 ( V_2 -> V_11 . V_44 ) , 0 , ( T_7 ) - 1 ) ;
V_2 -> V_12 . V_69 = V_70 ;
V_2 -> V_12 . V_67 = F_26 ( - V_119 ) ;
}
void F_235 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
F_55 ( & V_2 -> V_12 . V_146 ) ;
F_45 ( V_2 -> V_12 . V_67 ) ;
switch ( V_2 -> V_12 . V_69 ) {
case V_71 :
F_232 ( V_2 ) ;
case V_70 :
return;
}
if ( V_2 -> V_11 . V_44 == NULL )
return;
V_43 = V_2 -> V_11 . V_44 -> V_45 ,
F_236 ( V_43 , 0 , ( T_7 ) - 1 ) ;
}
static void
F_237 ( struct V_1 * V_2 ,
struct V_41 * V_67 )
{
struct V_266 V_266 ;
struct V_55 * V_55 ;
F_44 ( V_2 , V_67 , true ) ;
F_238 ( V_2 , V_67 ) ;
if ( F_25 ( V_2 ) )
F_239 ( V_2 , V_67 ) ;
F_240 (page, sgt_iter, pages) {
if ( V_2 -> V_12 . V_72 )
F_48 ( V_55 ) ;
if ( V_2 -> V_12 . V_69 == V_74 )
F_49 ( V_55 ) ;
F_35 ( V_55 ) ;
}
V_2 -> V_12 . V_72 = false ;
F_50 ( V_67 ) ;
F_39 ( V_67 ) ;
}
static void F_241 ( struct V_1 * V_2 )
{
struct V_267 V_268 ;
void * * V_269 ;
F_242 (slot, &obj->mm.get_page.radix, &iter, 0 )
F_243 ( & V_2 -> V_12 . V_270 . V_271 , V_268 . V_272 ) ;
}
void F_94 ( struct V_1 * V_2 ,
enum V_273 V_274 )
{
struct V_41 * V_67 ;
if ( F_244 ( V_2 ) )
return;
F_45 ( V_2 -> V_206 ) ;
if ( ! F_245 ( V_2 -> V_12 . V_67 ) )
return;
F_246 ( & V_2 -> V_12 . V_146 , V_274 ) ;
if ( F_139 ( F_247 ( & V_2 -> V_12 . V_275 ) ) )
goto V_276;
V_67 = F_248 ( & V_2 -> V_12 . V_67 ) ;
F_45 ( ! V_67 ) ;
if ( V_2 -> V_12 . V_43 ) {
void * V_277 ;
V_277 = F_249 ( V_2 -> V_12 . V_43 ) ;
if ( F_250 ( V_277 ) )
F_251 ( V_277 ) ;
else
F_144 ( F_252 ( V_277 ) ) ;
V_2 -> V_12 . V_43 = NULL ;
}
F_241 ( V_2 ) ;
if ( ! F_30 ( V_67 ) )
V_2 -> V_117 -> V_278 ( V_2 , V_67 ) ;
V_276:
F_22 ( & V_2 -> V_12 . V_146 ) ;
}
static bool F_253 ( struct V_41 * V_279 )
{
struct V_41 V_280 ;
struct V_48 * V_49 , * V_281 ;
unsigned int V_51 ;
if ( V_279 -> V_282 == V_279 -> V_283 )
return false ;
if ( F_38 ( & V_280 , V_279 -> V_282 , V_58 | V_284 ) )
return false ;
V_281 = V_280 . V_59 ;
F_254 (orig_st->sgl, sg, orig_st->nents, i) {
F_255 ( V_281 , F_256 ( V_49 ) , V_49 -> V_61 , 0 ) ;
V_281 = F_257 ( V_281 ) ;
}
F_45 ( V_281 ) ;
F_50 ( V_279 ) ;
* V_279 = V_280 ;
return true ;
}
static struct V_41 *
F_258 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_16 ( V_2 -> V_11 . V_27 ) ;
const unsigned long V_285 = V_2 -> V_11 . V_10 / V_54 ;
unsigned long V_51 ;
struct V_42 * V_43 ;
struct V_41 * V_47 ;
struct V_48 * V_49 ;
struct V_266 V_266 ;
struct V_55 * V_55 ;
unsigned long V_286 = 0 ;
unsigned int V_287 ;
T_9 V_288 ;
int V_22 ;
F_45 ( V_2 -> V_11 . V_64 & V_211 ) ;
F_45 ( V_2 -> V_11 . V_66 & V_211 ) ;
V_287 = F_259 () ;
if ( ! V_287 )
V_287 = F_203 ( V_289 , V_54 ) ;
V_47 = F_37 ( sizeof( * V_47 ) , V_58 ) ;
if ( V_47 == NULL )
return F_26 ( - V_53 ) ;
V_290:
if ( F_38 ( V_47 , V_285 , V_58 ) ) {
F_39 ( V_47 ) ;
return F_26 ( - V_53 ) ;
}
V_43 = V_2 -> V_11 . V_44 -> V_45 ;
V_288 = F_260 ( V_43 , ~ V_291 ) ;
V_288 |= V_292 | V_284 ;
V_49 = V_47 -> V_59 ;
V_47 -> V_282 = 0 ;
for ( V_51 = 0 ; V_51 < V_285 ; V_51 ++ ) {
const unsigned int V_293 [] = {
V_294 | V_295 | V_296 ,
0 ,
} , * V_297 = V_293 ;
T_9 V_298 = V_288 ;
do {
V_55 = F_261 ( V_43 , V_51 , V_298 ) ;
if ( F_223 ( ! F_30 ( V_55 ) ) )
break;
if ( ! * V_297 ) {
V_22 = F_108 ( V_55 ) ;
goto V_299;
}
F_262 ( V_17 , 2 * V_285 , * V_297 ++ ) ;
F_263 () ;
if ( ! * V_297 ) {
V_298 = F_264 ( V_43 ) ;
V_298 |= V_300 ;
}
} while ( 1 );
if ( ! V_51 ||
V_49 -> V_61 >= V_287 ||
F_265 ( V_55 ) != V_286 + 1 ) {
if ( V_51 )
V_49 = F_257 ( V_49 ) ;
V_47 -> V_282 ++ ;
F_255 ( V_49 , V_55 , V_54 , 0 ) ;
} else {
V_49 -> V_61 += V_54 ;
}
V_286 = F_265 ( V_55 ) ;
F_24 ( ( V_298 & V_301 ) && ( V_286 >= 0x00100000UL ) ) ;
}
if ( V_49 )
F_266 ( V_49 ) ;
F_253 ( V_47 ) ;
V_22 = F_267 ( V_2 , V_47 ) ;
if ( V_22 ) {
if ( V_287 > V_54 ) {
F_240 (page, sgt_iter, st)
F_35 ( V_55 ) ;
F_50 ( V_47 ) ;
V_287 = V_54 ;
goto V_290;
} else {
F_268 ( & V_17 -> V_176 . V_302 -> V_27 ,
L_3 ,
V_285 ) ;
goto V_303;
}
}
if ( F_25 ( V_2 ) )
F_269 ( V_2 , V_47 ) ;
return V_47 ;
V_299:
F_266 ( V_49 ) ;
V_303:
F_240 (page, sgt_iter, st)
F_35 ( V_55 ) ;
F_50 ( V_47 ) ;
F_39 ( V_47 ) ;
if ( V_22 == - V_200 )
V_22 = - V_53 ;
return F_26 ( V_22 ) ;
}
void F_270 ( struct V_1 * V_2 ,
struct V_41 * V_67 )
{
F_55 ( & V_2 -> V_12 . V_146 ) ;
V_2 -> V_12 . V_270 . V_304 = V_67 -> V_59 ;
V_2 -> V_12 . V_270 . V_305 = 0 ;
V_2 -> V_12 . V_67 = V_67 ;
if ( F_202 ( V_2 ) &&
F_16 ( V_2 -> V_11 . V_27 ) -> V_306 & V_307 ) {
F_45 ( V_2 -> V_12 . V_308 ) ;
F_271 ( V_2 ) ;
V_2 -> V_12 . V_308 = true ;
}
}
static int F_272 ( struct V_1 * V_2 )
{
struct V_41 * V_67 ;
F_45 ( F_244 ( V_2 ) ) ;
if ( F_139 ( V_2 -> V_12 . V_69 != V_74 ) ) {
F_273 ( L_4 ) ;
return - V_119 ;
}
V_67 = V_2 -> V_117 -> V_309 ( V_2 ) ;
if ( F_139 ( F_30 ( V_67 ) ) )
return F_108 ( V_67 ) ;
F_270 ( V_2 , V_67 ) ;
return 0 ;
}
int F_274 ( struct V_1 * V_2 )
{
int V_198 ;
V_198 = F_17 ( & V_2 -> V_12 . V_146 ) ;
if ( V_198 )
return V_198 ;
if ( F_139 ( F_275 ( V_2 -> V_12 . V_67 ) ) ) {
V_198 = F_272 ( V_2 ) ;
if ( V_198 )
goto V_276;
F_276 () ;
}
F_277 ( & V_2 -> V_12 . V_275 ) ;
V_276:
F_22 ( & V_2 -> V_12 . V_146 ) ;
return V_198 ;
}
static void * F_278 ( const struct V_1 * V_2 ,
enum V_310 type )
{
unsigned long V_311 = V_2 -> V_11 . V_10 >> V_172 ;
struct V_41 * V_312 = V_2 -> V_12 . V_67 ;
struct V_266 V_266 ;
struct V_55 * V_55 ;
struct V_55 * V_313 [ 32 ] ;
struct V_55 * * V_67 = V_313 ;
unsigned long V_51 = 0 ;
T_10 V_314 ;
void * V_163 ;
if ( V_311 == 1 && type == V_315 )
return F_143 ( F_256 ( V_312 -> V_59 ) ) ;
if ( V_311 > F_279 ( V_313 ) ) {
V_67 = F_280 ( V_311 , sizeof( * V_67 ) , V_316 ) ;
if ( ! V_67 )
return NULL ;
}
F_240 (page, sgt_iter, sgt)
V_67 [ V_51 ++ ] = V_55 ;
F_45 ( V_51 != V_311 ) ;
switch ( type ) {
case V_315 :
V_314 = V_317 ;
break;
case V_318 :
V_314 = F_194 ( V_319 ) ;
break;
}
V_163 = F_281 ( V_67 , V_311 , 0 , V_314 ) ;
if ( V_67 != V_313 )
F_282 ( V_67 ) ;
return V_163 ;
}
void * F_283 ( struct V_1 * V_2 ,
enum V_310 type )
{
enum V_310 V_320 ;
bool V_36 ;
void * V_277 ;
int V_22 ;
F_45 ( ! F_134 ( V_2 ) ) ;
V_22 = F_17 ( & V_2 -> V_12 . V_146 ) ;
if ( V_22 )
return F_26 ( V_22 ) ;
V_36 = true ;
if ( ! F_284 ( & V_2 -> V_12 . V_275 ) ) {
if ( F_139 ( F_275 ( V_2 -> V_12 . V_67 ) ) ) {
V_22 = F_272 ( V_2 ) ;
if ( V_22 )
goto V_243;
F_276 () ;
}
F_277 ( & V_2 -> V_12 . V_275 ) ;
V_36 = false ;
}
F_45 ( ! V_2 -> V_12 . V_67 ) ;
V_277 = F_285 ( V_2 -> V_12 . V_43 , & V_320 ) ;
if ( V_277 && V_320 != type ) {
if ( V_36 ) {
V_22 = - V_121 ;
goto V_160;
}
if ( F_250 ( V_277 ) )
F_251 ( V_277 ) ;
else
F_144 ( F_252 ( V_277 ) ) ;
V_277 = V_2 -> V_12 . V_43 = NULL ;
}
if ( ! V_277 ) {
V_277 = F_278 ( V_2 , type ) ;
if ( ! V_277 ) {
V_22 = - V_53 ;
goto V_160;
}
V_2 -> V_12 . V_43 = F_286 ( V_277 , type ) ;
}
V_180:
F_22 ( & V_2 -> V_12 . V_146 ) ;
return V_277 ;
V_160:
F_287 ( & V_2 -> V_12 . V_275 ) ;
V_243:
V_277 = F_26 ( V_22 ) ;
goto V_180;
}
static int
F_288 ( struct V_1 * V_2 ,
const struct V_124 * V_321 )
{
struct V_42 * V_43 = V_2 -> V_11 . V_44 -> V_45 ;
char T_4 * V_125 = F_97 ( V_321 -> V_126 ) ;
T_2 V_169 , V_60 ;
unsigned int V_322 ;
if ( F_245 ( V_2 -> V_12 . V_67 ) )
return - V_158 ;
V_169 = V_321 -> V_10 ;
V_60 = V_321 -> V_60 ;
V_322 = F_149 ( V_60 ) ;
do {
unsigned int V_193 , V_174 ;
struct V_55 * V_55 ;
void * V_30 , * V_50 ;
int V_198 ;
V_193 = V_54 - V_322 ;
if ( V_193 > V_169 )
V_193 = V_169 ;
V_198 = F_289 ( V_2 -> V_11 . V_44 , V_43 ,
V_60 , V_193 , 0 ,
& V_55 , & V_30 ) ;
if ( V_198 < 0 )
return V_198 ;
V_50 = F_143 ( V_55 ) ;
V_174 = F_99 ( V_50 + V_322 , V_125 , V_193 ) ;
F_144 ( V_55 ) ;
V_198 = F_290 ( V_2 -> V_11 . V_44 , V_43 ,
V_60 , V_193 , V_193 - V_174 ,
V_55 , V_30 ) ;
if ( V_198 < 0 )
return V_198 ;
if ( V_174 )
return - V_119 ;
V_169 -= V_193 ;
V_125 += V_193 ;
V_60 += V_193 ;
V_322 = 0 ;
} while ( V_169 );
return 0 ;
}
static bool F_291 ( const struct V_323 * V_324 )
{
return ( F_292 ( V_324 ) &&
V_324 -> V_325 >= V_326 ) ;
}
static void F_293 ( struct V_323 * V_324 )
{
V_324 -> V_327 ++ ;
V_324 -> V_325 += V_328 ;
if ( F_291 ( V_324 ) )
F_294 ( V_324 ) ;
F_295 ( L_5 ,
V_324 -> V_329 , V_324 -> V_325 ,
F_296 ( F_297 ( V_324 ) ) ) ;
if ( ! F_297 ( V_324 ) || F_275 ( V_324 -> V_330 ) )
return;
V_324 -> V_330 -> V_331 ++ ;
F_295 ( L_6 ,
V_324 -> V_329 , V_324 -> V_330 -> V_331 ) ;
}
static void F_298 ( struct V_323 * V_324 )
{
V_324 -> V_332 ++ ;
}
struct V_88 *
F_299 ( struct V_105 * V_94 )
{
struct V_88 * V_333 , * V_334 = NULL ;
unsigned long V_84 ;
F_300 ( & V_94 -> V_335 -> V_146 , V_84 ) ;
F_20 (request, &engine->timeline->requests, link) {
if ( F_301 ( V_333 ,
V_333 -> V_336 ) )
continue;
F_45 ( V_333 -> V_94 != V_94 ) ;
F_45 ( F_64 ( V_90 ,
& V_333 -> V_83 . V_84 ) ) ;
V_334 = V_333 ;
break;
}
F_302 ( & V_94 -> V_335 -> V_146 , V_84 ) ;
return V_334 ;
}
static bool F_303 ( struct V_105 * V_94 )
{
if ( ! V_94 -> V_337 . V_338 )
return false ;
if ( V_94 -> V_337 . V_339 != F_304 ( V_94 ) ) {
F_295 ( L_7 , V_94 -> V_329 ) ;
return false ;
}
return true ;
}
int F_305 ( struct V_16 * V_17 )
{
struct V_105 * V_94 ;
enum V_340 V_341 ;
int V_198 = 0 ;
F_306 (engine, dev_priv, id) {
struct V_88 * V_333 ;
F_307 ( V_94 -> V_342 . V_343 ) ;
F_308 ( & V_94 -> V_344 ) ;
F_309 ( & V_94 -> V_344 ) ;
if ( V_94 -> V_345 )
V_94 -> V_345 ( V_94 ) ;
if ( F_303 ( V_94 ) ) {
V_333 = F_299 ( V_94 ) ;
if ( V_333 && V_333 -> V_83 . error == - V_25 )
V_198 = - V_25 ;
}
}
F_310 ( V_17 ) ;
return V_198 ;
}
static void F_311 ( struct V_88 * V_333 )
{
void * V_50 = V_333 -> V_346 -> V_50 ;
T_1 V_347 ;
V_347 = V_333 -> V_347 ;
if ( V_333 -> V_348 < V_347 ) {
memset ( V_50 + V_347 , 0 , V_333 -> V_346 -> V_10 - V_347 ) ;
V_347 = 0 ;
}
memset ( V_50 + V_347 , 0 , V_333 -> V_348 - V_347 ) ;
F_312 ( & V_333 -> V_83 , - V_25 ) ;
}
static void F_313 ( struct V_88 * V_333 )
{
struct V_105 * V_94 = V_333 -> V_94 ;
struct V_323 * V_349 = V_333 -> V_324 ;
struct V_350 * V_335 ;
unsigned long V_84 ;
V_335 = F_314 ( V_349 , V_94 ) ;
F_300 ( & V_94 -> V_335 -> V_146 , V_84 ) ;
F_7 ( & V_335 -> V_146 ) ;
F_315 (request, &engine->timeline->requests, link)
if ( V_333 -> V_324 == V_349 )
F_311 ( V_333 ) ;
F_20 (request, &timeline->requests, link)
F_311 ( V_333 ) ;
F_8 ( & V_335 -> V_146 ) ;
F_302 ( & V_94 -> V_335 -> V_146 , V_84 ) ;
}
static bool F_316 ( struct V_88 * V_333 )
{
const bool V_351 = F_303 ( V_333 -> V_94 ) ;
if ( V_351 ) {
F_293 ( V_333 -> V_324 ) ;
F_311 ( V_333 ) ;
} else {
F_298 ( V_333 -> V_324 ) ;
F_312 ( & V_333 -> V_83 , - V_251 ) ;
}
return V_351 ;
}
static void F_317 ( struct V_105 * V_94 )
{
struct V_88 * V_333 ;
V_333 = F_299 ( V_94 ) ;
if ( V_333 && F_316 ( V_333 ) ) {
F_295 ( L_8 ,
V_94 -> V_329 , V_333 -> V_336 ) ;
if ( F_297 ( V_333 -> V_324 ) )
F_313 ( V_333 ) ;
}
V_94 -> V_352 ( V_94 , V_333 ) ;
}
void F_318 ( struct V_16 * V_17 )
{
struct V_105 * V_94 ;
enum V_340 V_341 ;
F_55 ( & V_17 -> V_176 . V_29 ) ;
F_57 ( V_17 ) ;
F_306 (engine, dev_priv, id) {
struct V_323 * V_324 ;
F_317 ( V_94 ) ;
V_324 = F_248 ( & V_94 -> V_353 ) ;
if ( V_324 )
V_94 -> V_354 ( V_94 , V_324 ) ;
}
F_319 ( V_17 ) ;
if ( V_17 -> V_263 . V_355 ) {
F_320 ( V_17 ) ;
F_321 ( V_17 ) ;
if ( F_69 ( V_17 ) >= 6 )
F_322 ( V_17 ) ;
}
}
void F_323 ( struct V_16 * V_17 )
{
struct V_105 * V_94 ;
enum V_340 V_341 ;
F_55 ( & V_17 -> V_176 . V_29 ) ;
F_306 (engine, dev_priv, id) {
F_324 ( & V_94 -> V_344 ) ;
F_325 ( V_94 -> V_342 . V_343 ) ;
}
}
static void F_326 ( struct V_88 * V_333 )
{
F_312 ( & V_333 -> V_83 , - V_25 ) ;
F_327 ( V_333 ) ;
F_328 ( V_333 -> V_94 , V_333 -> V_336 ) ;
}
static void F_329 ( struct V_105 * V_94 )
{
struct V_88 * V_333 ;
unsigned long V_84 ;
V_94 -> V_356 = F_326 ;
F_300 ( & V_94 -> V_335 -> V_146 , V_84 ) ;
F_20 (request, &engine->timeline->requests, link)
F_312 ( & V_333 -> V_83 , - V_25 ) ;
F_302 ( & V_94 -> V_335 -> V_146 , V_84 ) ;
F_328 ( V_94 ,
F_74 ( V_94 ) ) ;
if ( V_92 . V_357 ) {
struct V_358 * V_359 = V_94 -> V_358 ;
unsigned long V_84 ;
unsigned int V_360 ;
F_300 ( & V_94 -> V_335 -> V_146 , V_84 ) ;
for ( V_360 = 0 ; V_360 < F_279 ( V_94 -> V_358 ) ; V_360 ++ )
F_330 ( F_331 ( & V_359 [ V_360 ] ) ) ;
memset ( V_94 -> V_358 , 0 , sizeof( V_94 -> V_358 ) ) ;
V_94 -> V_361 = V_362 ;
V_94 -> V_363 = NULL ;
F_302 ( & V_94 -> V_335 -> V_146 , V_84 ) ;
}
}
static int F_332 ( void * V_30 )
{
struct V_16 * V_92 = V_30 ;
struct V_105 * V_94 ;
enum V_340 V_341 ;
F_306 (engine, i915, id)
F_329 ( V_94 ) ;
return 0 ;
}
void F_333 ( struct V_16 * V_17 )
{
F_55 ( & V_17 -> V_176 . V_29 ) ;
F_334 ( V_364 , & V_17 -> V_28 . V_84 ) ;
F_57 ( V_17 ) ;
F_335 ( F_332 , V_17 , NULL ) ;
F_336 ( V_17 ) ;
F_337 ( V_17 -> V_365 , & V_17 -> V_263 . V_366 , 0 ) ;
}
bool F_338 ( struct V_16 * V_92 )
{
struct V_367 * V_368 ;
int V_51 ;
F_55 ( & V_92 -> V_176 . V_29 ) ;
if ( ! F_64 ( V_364 , & V_92 -> V_28 . V_84 ) )
return true ;
F_20 (tl, &i915->gt.timelines, link) {
for ( V_51 = 0 ; V_51 < F_279 ( V_368 -> V_94 ) ; V_51 ++ ) {
struct V_88 * V_89 ;
V_89 = F_339 ( & V_368 -> V_94 [ V_51 ] . V_369 ,
& V_92 -> V_176 . V_29 ) ;
if ( ! V_89 )
continue;
if ( F_340 ( & V_89 -> V_83 , true ,
V_79 ) < 0 )
return false ;
}
}
F_341 ( V_92 ) ;
F_276 () ;
F_342 ( V_364 , & V_92 -> V_28 . V_84 ) ;
return true ;
}
static void
F_343 ( struct V_370 * V_371 )
{
struct V_16 * V_17 =
F_344 ( V_371 , F_345 ( * V_17 ) , V_263 . V_264 . V_371 ) ;
struct V_26 * V_27 = & V_17 -> V_176 ;
if ( F_346 ( & V_27 -> V_29 ) ) {
F_57 ( V_17 ) ;
F_22 ( & V_27 -> V_29 ) ;
}
if ( F_245 ( V_17 -> V_263 . V_355 ) ) {
F_347 ( V_17 ) ;
F_348 ( V_17 -> V_365 ,
& V_17 -> V_263 . V_264 ,
F_349 ( V_372 ) ) ;
}
}
static void
F_350 ( struct V_370 * V_371 )
{
struct V_16 * V_17 =
F_344 ( V_371 , F_345 ( * V_17 ) , V_263 . V_366 . V_371 ) ;
struct V_26 * V_27 = & V_17 -> V_176 ;
bool V_373 ;
if ( ! F_245 ( V_17 -> V_263 . V_355 ) )
return;
F_351 ( F_352 ( V_17 ) , 10 ) ;
if ( F_245 ( V_17 -> V_263 . V_374 ) )
return;
V_373 =
F_353 ( & V_17 -> V_28 . V_375 ) ;
if ( ! F_346 ( & V_27 -> V_29 ) ) {
F_337 ( V_17 -> V_365 ,
& V_17 -> V_263 . V_366 ,
F_354 ( 50 ) ) ;
goto V_376;
}
if ( F_355 ( V_371 ) )
goto V_180;
if ( V_17 -> V_263 . V_374 )
goto V_180;
if ( F_351 ( F_352 ( V_17 ) , 10 ) )
F_14 ( L_9 ) ;
F_356 ( V_17 ) ;
F_357 ( V_17 ) ;
F_45 ( ! V_17 -> V_263 . V_355 ) ;
V_17 -> V_263 . V_355 = false ;
V_373 = false ;
if ( F_69 ( V_17 ) >= 6 )
F_358 ( V_17 ) ;
F_126 ( V_17 ) ;
V_180:
F_22 ( & V_27 -> V_29 ) ;
V_376:
if ( V_373 ) {
F_45 ( ! V_17 -> V_263 . V_355 ) ;
F_347 ( V_17 ) ;
}
}
void F_359 ( struct V_377 * V_378 , struct V_31 * V_32 )
{
struct V_1 * V_2 = F_207 ( V_378 ) ;
struct V_113 * V_114 = V_32 -> V_115 ;
struct V_34 * V_35 , * V_379 ;
F_19 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
F_220 (vma, vn, &obj->vma_list, obj_link)
if ( V_35 -> V_204 -> V_32 == V_114 )
F_360 ( V_35 ) ;
V_35 = V_2 -> V_380 ;
if ( V_35 && V_35 -> V_324 -> V_330 == V_114 )
F_361 ( V_35 ) ;
if ( F_362 ( V_2 ) &&
! F_363 ( V_2 ) ) {
F_364 ( V_2 ) ;
F_365 ( V_2 ) ;
}
F_22 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
}
static unsigned long F_366 ( T_11 V_381 )
{
if ( V_381 < 0 )
return V_79 ;
if ( V_381 == 0 )
return 0 ;
return F_367 ( V_381 ) ;
}
int
F_368 ( struct V_26 * V_27 , void * V_30 , struct V_31 * V_32 )
{
struct V_382 * args = V_30 ;
struct V_1 * V_2 ;
T_12 V_165 ;
long V_22 ;
if ( args -> V_84 != 0 )
return - V_52 ;
V_2 = F_169 ( V_32 , args -> V_383 ) ;
if ( ! V_2 )
return - V_190 ;
V_165 = F_369 () ;
V_22 = F_56 ( V_2 ,
V_76 | V_78 ,
F_366 ( args -> V_381 ) ,
F_92 ( V_32 ) ) ;
if ( args -> V_381 > 0 ) {
args -> V_381 -= F_370 ( F_371 ( F_369 () , V_165 ) ) ;
if ( args -> V_381 < 0 )
args -> V_381 = 0 ;
if ( V_22 == - V_384 && ! F_372 ( args -> V_381 ) )
args -> V_381 = 0 ;
}
F_110 ( V_2 ) ;
return V_22 ;
}
static int F_373 ( struct V_367 * V_368 , unsigned int V_84 )
{
int V_22 , V_51 ;
for ( V_51 = 0 ; V_51 < F_279 ( V_368 -> V_94 ) ; V_51 ++ ) {
V_22 = F_374 ( & V_368 -> V_94 [ V_51 ] . V_369 , V_84 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static int F_375 ( struct V_105 * V_94 , int V_385 )
{
return F_351 ( F_376 ( V_94 ) , V_385 ) ;
}
static int F_377 ( struct V_16 * V_92 )
{
struct V_105 * V_94 ;
enum V_340 V_341 ;
F_306 (engine, i915, id) {
if ( F_378 ( F_375 ( V_94 , 50 ) ) ) {
F_333 ( V_92 ) ;
return - V_25 ;
}
F_45 ( F_304 ( V_94 ) !=
F_74 ( V_94 ) ) ;
}
return 0 ;
}
int F_224 ( struct V_16 * V_92 , unsigned int V_84 )
{
int V_22 ;
if ( ! F_245 ( V_92 -> V_263 . V_355 ) )
return 0 ;
if ( V_84 & V_77 ) {
struct V_367 * V_368 ;
F_55 ( & V_92 -> V_176 . V_29 ) ;
F_20 (tl, &i915->gt.timelines, link) {
V_22 = F_373 ( V_368 , V_84 ) ;
if ( V_22 )
return V_22 ;
}
F_57 ( V_92 ) ;
F_45 ( V_92 -> V_263 . V_374 ) ;
V_22 = F_377 ( V_92 ) ;
} else {
V_22 = F_373 ( & V_92 -> V_263 . V_386 , V_84 ) ;
}
return V_22 ;
}
static void F_379 ( struct V_1 * V_2 )
{
F_118 ( V_2 , ~ V_65 ) ;
if ( V_2 -> V_3 )
F_127 ( V_2 , V_387 ) ;
V_2 -> V_11 . V_66 = 0 ;
}
void F_188 ( struct V_1 * V_2 )
{
if ( ! F_245 ( V_2 -> V_5 ) )
return;
F_19 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
F_379 ( V_2 ) ;
F_22 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
}
int
F_186 ( struct V_1 * V_2 , bool V_238 )
{
int V_22 ;
F_55 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
V_22 = F_56 ( V_2 ,
V_76 |
V_77 |
( V_238 ? V_78 : 0 ) ,
V_79 ,
NULL ) ;
if ( V_22 )
return V_22 ;
if ( V_2 -> V_11 . V_66 == V_212 )
return 0 ;
V_22 = F_95 ( V_2 ) ;
if ( V_22 )
return V_22 ;
F_118 ( V_2 , ~ V_212 ) ;
if ( ( V_2 -> V_11 . V_64 & V_212 ) == 0 )
F_380 () ;
F_45 ( ( V_2 -> V_11 . V_66 & ~ V_212 ) != 0 ) ;
V_2 -> V_11 . V_64 |= V_212 ;
if ( V_238 ) {
V_2 -> V_11 . V_64 = V_212 ;
V_2 -> V_11 . V_66 = V_212 ;
V_2 -> V_12 . V_72 = true ;
}
F_52 ( V_2 ) ;
return 0 ;
}
int
F_165 ( struct V_1 * V_2 , bool V_238 )
{
int V_22 ;
F_55 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
V_22 = F_56 ( V_2 ,
V_76 |
V_77 |
( V_238 ? V_78 : 0 ) ,
V_79 ,
NULL ) ;
if ( V_22 )
return V_22 ;
if ( V_2 -> V_11 . V_66 == V_142 )
return 0 ;
V_22 = F_95 ( V_2 ) ;
if ( V_22 )
return V_22 ;
F_118 ( V_2 , ~ V_142 ) ;
if ( ( V_2 -> V_11 . V_64 & V_142 ) == 0 )
F_380 () ;
F_45 ( ( V_2 -> V_11 . V_66 & ~ V_142 ) != 0 ) ;
V_2 -> V_11 . V_64 |= V_142 ;
if ( V_238 ) {
V_2 -> V_11 . V_64 = V_142 ;
V_2 -> V_11 . V_66 = V_142 ;
V_2 -> V_12 . V_72 = true ;
}
F_52 ( V_2 ) ;
return 0 ;
}
int F_381 ( struct V_1 * V_2 ,
enum V_388 V_136 )
{
struct V_34 * V_35 ;
int V_22 ;
F_55 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
if ( V_2 -> V_136 == V_136 )
return 0 ;
V_389:
F_20 (vma, &obj->vma_list, obj_link) {
if ( ! F_184 ( & V_35 -> V_9 ) )
continue;
if ( F_21 ( V_35 ) ) {
F_273 ( L_10 ) ;
return - V_121 ;
}
if ( F_382 ( V_35 , V_136 ) )
continue;
V_22 = F_60 ( V_35 ) ;
if ( V_22 )
return V_22 ;
goto V_389;
}
if ( V_2 -> V_206 ) {
V_22 = F_56 ( V_2 ,
V_76 |
V_77 |
V_78 ,
V_79 ,
NULL ) ;
if ( V_22 )
return V_22 ;
if ( ! F_120 ( F_16 ( V_2 -> V_11 . V_27 ) ) &&
V_136 != V_137 ) {
F_217 ( V_2 ) ;
F_20 (vma, &obj->vma_list, obj_link) {
V_22 = F_163 ( V_35 ) ;
if ( V_22 )
return V_22 ;
}
} else {
}
F_20 (vma, &obj->vma_list, obj_link) {
if ( ! F_184 ( & V_35 -> V_9 ) )
continue;
V_22 = F_383 ( V_35 , V_136 , V_390 ) ;
if ( V_22 )
return V_22 ;
}
}
F_20 (vma, &obj->vma_list, obj_link)
V_35 -> V_9 . V_391 = V_136 ;
V_2 -> V_136 = V_136 ;
V_2 -> V_4 = F_384 ( V_2 ) ;
V_2 -> V_3 = true ;
return 0 ;
}
int F_385 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_392 * args = V_30 ;
struct V_1 * V_2 ;
int V_198 = 0 ;
F_386 () ;
V_2 = F_387 ( V_32 , args -> V_130 ) ;
if ( ! V_2 ) {
V_198 = - V_190 ;
goto V_91;
}
switch ( V_2 -> V_136 ) {
case V_393 :
case V_394 :
args -> V_395 = V_396 ;
break;
case V_138 :
args -> V_395 = V_397 ;
break;
default:
args -> V_395 = V_398 ;
break;
}
V_91:
F_388 () ;
return V_198 ;
}
int F_389 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_16 * V_92 = F_16 ( V_27 ) ;
struct V_392 * args = V_30 ;
struct V_1 * V_2 ;
enum V_388 V_399 ;
int V_22 = 0 ;
switch ( args -> V_395 ) {
case V_398 :
V_399 = V_137 ;
break;
case V_396 :
if ( ! F_120 ( V_92 ) && ! F_390 ( V_92 ) )
return - V_158 ;
V_399 = V_393 ;
break;
case V_397 :
V_399 = F_391 ( V_92 ) ? V_138 : V_137 ;
break;
default:
return - V_52 ;
}
V_2 = F_169 ( V_32 , args -> V_130 ) ;
if ( ! V_2 )
return - V_190 ;
if ( V_2 -> V_136 == V_399 )
goto V_91;
V_22 = F_56 ( V_2 ,
V_76 ,
V_79 ,
F_92 ( V_32 ) ) ;
if ( V_22 )
goto V_91;
V_22 = F_15 ( V_27 ) ;
if ( V_22 )
goto V_91;
V_22 = F_381 ( V_2 , V_399 ) ;
F_22 ( & V_27 -> V_29 ) ;
V_91:
F_110 ( V_2 ) ;
return V_22 ;
}
struct V_34 *
F_392 ( struct V_1 * V_2 ,
T_1 V_400 ,
const struct V_228 * V_230 )
{
struct V_34 * V_35 ;
int V_22 ;
F_55 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
V_2 -> V_5 ++ ;
V_22 = F_381 ( V_2 ,
F_391 ( F_16 ( V_2 -> V_11 . V_27 ) ) ?
V_138 : V_137 ) ;
if ( V_22 ) {
V_35 = F_26 ( V_22 ) ;
goto V_401;
}
V_35 = F_26 ( - V_200 ) ;
if ( ! V_230 || V_230 -> type == V_233 )
V_35 = F_161 ( V_2 , V_230 , 0 , V_400 ,
V_177 | V_178 ) ;
if ( F_30 ( V_35 ) ) {
struct V_16 * V_92 = F_16 ( V_2 -> V_11 . V_27 ) ;
unsigned int V_84 ;
V_84 = 0 ;
if ( F_393 ( V_92 ) )
V_84 = V_177 ;
V_35 = F_161 ( V_2 , V_230 , 0 , V_400 , V_84 ) ;
}
if ( F_30 ( V_35 ) )
goto V_401;
V_35 -> V_402 = F_394 ( T_2 , V_35 -> V_402 , V_400 ) ;
F_379 ( V_2 ) ;
F_100 ( V_2 , V_403 ) ;
V_2 -> V_11 . V_64 |= V_142 ;
return V_35 ;
V_401:
V_2 -> V_5 -- ;
return V_35 ;
}
void
F_395 ( struct V_34 * V_35 )
{
F_55 ( & V_35 -> V_204 -> V_92 -> V_176 . V_29 ) ;
if ( F_24 ( V_35 -> V_2 -> V_5 == 0 ) )
return;
if ( -- V_35 -> V_2 -> V_5 == 0 )
V_35 -> V_402 = V_404 ;
F_181 ( V_35 -> V_2 ) ;
F_164 ( V_35 ) ;
}
int
F_136 ( struct V_1 * V_2 , bool V_238 )
{
int V_22 ;
F_55 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
V_22 = F_56 ( V_2 ,
V_76 |
V_77 |
( V_238 ? V_78 : 0 ) ,
V_79 ,
NULL ) ;
if ( V_22 )
return V_22 ;
F_118 ( V_2 , ~ V_65 ) ;
if ( ( V_2 -> V_11 . V_64 & V_65 ) == 0 ) {
F_127 ( V_2 , V_149 ) ;
V_2 -> V_11 . V_64 |= V_65 ;
}
F_45 ( V_2 -> V_11 . V_66 & ~ V_65 ) ;
if ( V_238 )
F_43 ( V_2 ) ;
return 0 ;
}
static int
F_396 ( struct V_26 * V_27 , struct V_31 * V_32 )
{
struct V_16 * V_17 = F_16 ( V_27 ) ;
struct V_113 * V_330 = V_32 -> V_115 ;
unsigned long V_405 = V_406 - V_407 ;
struct V_88 * V_333 , * V_408 = NULL ;
long V_22 ;
if ( F_215 ( & V_17 -> V_28 ) )
return - V_25 ;
F_7 ( & V_330 -> V_12 . V_146 ) ;
F_20 (request, &file_priv->mm.request_list, client_link) {
if ( F_397 ( V_333 -> V_93 , V_405 ) )
break;
if ( V_408 ) {
F_398 ( & V_408 -> V_409 ) ;
V_408 -> V_330 = NULL ;
}
V_408 = V_333 ;
}
if ( V_408 )
F_399 ( V_408 ) ;
F_8 ( & V_330 -> V_12 . V_146 ) ;
if ( V_408 == NULL )
return 0 ;
V_22 = F_71 ( V_408 ,
V_76 ,
V_79 ) ;
F_330 ( V_408 ) ;
return V_22 < 0 ? V_22 : 0 ;
}
struct V_34 *
F_161 ( struct V_1 * V_2 ,
const struct V_228 * V_230 ,
T_2 V_10 ,
T_2 V_400 ,
T_2 V_84 )
{
struct V_16 * V_17 = F_16 ( V_2 -> V_11 . V_27 ) ;
struct V_410 * V_204 = & V_17 -> V_7 . V_11 ;
struct V_34 * V_35 ;
int V_22 ;
F_55 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
V_35 = F_400 ( V_2 , V_204 , V_230 ) ;
if ( F_139 ( F_30 ( V_35 ) ) )
return V_35 ;
if ( F_401 ( V_35 , V_10 , V_400 , V_84 ) ) {
if ( V_84 & V_178 &&
( F_21 ( V_35 ) || F_183 ( V_35 ) ) )
return F_26 ( - V_200 ) ;
if ( V_84 & V_177 ) {
if ( V_35 -> V_411 > V_17 -> V_7 . V_14 )
return F_26 ( - V_412 ) ;
if ( V_84 & V_178 &&
V_35 -> V_411 > V_17 -> V_7 . V_14 / 2 )
return F_26 ( - V_200 ) ;
}
F_402 ( F_21 ( V_35 ) ,
L_11
L_12
L_13 ,
F_162 ( V_35 ) , V_400 ,
! ! ( V_84 & V_177 ) ,
F_403 ( V_35 ) ) ;
V_22 = F_60 ( V_35 ) ;
if ( V_22 )
return F_26 ( V_22 ) ;
}
V_22 = F_404 ( V_35 , V_10 , V_400 , V_84 | V_413 ) ;
if ( V_22 )
return F_26 ( V_22 ) ;
return V_35 ;
}
static T_13 unsigned int F_405 ( unsigned int V_341 )
{
F_63 ( V_414 > 16 ) ;
return 0x10000 << V_341 ;
}
static T_13 unsigned int F_406 ( unsigned int V_341 )
{
return V_341 | F_405 ( V_341 ) ;
}
static T_13 unsigned int
F_407 ( const struct V_82 * V_83 )
{
return F_408 ( V_83 , F_405 ) ;
}
static T_13 unsigned int
F_409 ( const struct V_82 * V_83 )
{
if ( ! V_83 )
return 0 ;
return F_408 ( V_83 , F_406 ) ;
}
int
F_410 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_415 * args = V_30 ;
struct V_1 * V_2 ;
struct V_416 * V_202 ;
unsigned int V_99 ;
int V_198 ;
V_198 = - V_190 ;
F_386 () ;
V_2 = F_387 ( V_32 , args -> V_130 ) ;
if ( ! V_2 )
goto V_91;
V_417:
V_99 = F_411 ( & V_2 -> V_98 -> V_99 ) ;
args -> V_418 = F_409 ( F_412 ( V_2 -> V_98 -> V_419 ) ) ;
V_202 = F_412 ( V_2 -> V_98 -> V_83 ) ;
if ( V_202 ) {
unsigned int V_420 = V_202 -> V_420 , V_51 ;
for ( V_51 = 0 ; V_51 < V_420 ; ++ V_51 ) {
struct V_82 * V_83 =
F_412 ( V_202 -> V_102 [ V_51 ] ) ;
args -> V_418 |= F_407 ( V_83 ) ;
}
}
if ( args -> V_418 && F_413 ( & V_2 -> V_98 -> V_99 , V_99 ) )
goto V_417;
V_198 = 0 ;
V_91:
F_388 () ;
return V_198 ;
}
int
F_414 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_330 )
{
return F_396 ( V_27 , V_330 ) ;
}
int
F_415 ( struct V_26 * V_27 , void * V_30 ,
struct V_31 * V_330 )
{
struct V_16 * V_17 = F_16 ( V_27 ) ;
struct V_421 * args = V_30 ;
struct V_1 * V_2 ;
int V_198 ;
switch ( args -> V_69 ) {
case V_71 :
case V_74 :
break;
default:
return - V_52 ;
}
V_2 = F_169 ( V_330 , args -> V_130 ) ;
if ( ! V_2 )
return - V_190 ;
V_198 = F_17 ( & V_2 -> V_12 . V_146 ) ;
if ( V_198 )
goto V_91;
if ( V_2 -> V_12 . V_67 &&
F_202 ( V_2 ) &&
V_17 -> V_306 & V_307 ) {
if ( V_2 -> V_12 . V_69 == V_74 ) {
F_45 ( ! V_2 -> V_12 . V_308 ) ;
F_416 ( V_2 ) ;
V_2 -> V_12 . V_308 = false ;
}
if ( args -> V_69 == V_74 ) {
F_45 ( V_2 -> V_12 . V_308 ) ;
F_271 ( V_2 ) ;
V_2 -> V_12 . V_308 = true ;
}
}
if ( V_2 -> V_12 . V_69 != V_70 )
V_2 -> V_12 . V_69 = args -> V_69 ;
if ( V_2 -> V_12 . V_69 == V_71 && ! V_2 -> V_12 . V_67 )
F_232 ( V_2 ) ;
args -> V_422 = V_2 -> V_12 . V_69 != V_70 ;
F_22 ( & V_2 -> V_12 . V_146 ) ;
V_91:
F_110 ( V_2 ) ;
return V_198 ;
}
static void
F_417 ( struct V_423 * V_334 ,
struct V_88 * V_333 )
{
struct V_1 * V_2 =
F_344 ( V_334 , F_345 ( * V_2 ) , V_424 ) ;
F_100 ( V_2 , V_425 ) ;
}
void F_418 ( struct V_1 * V_2 ,
const struct V_426 * V_117 )
{
F_419 ( & V_2 -> V_12 . V_146 ) ;
F_420 ( & V_2 -> V_209 ) ;
F_420 ( & V_2 -> V_245 ) ;
F_420 ( & V_2 -> V_80 ) ;
F_420 ( & V_2 -> V_427 ) ;
V_2 -> V_117 = V_117 ;
F_421 ( & V_2 -> V_428 ) ;
V_2 -> V_98 = & V_2 -> V_428 ;
V_2 -> V_143 = V_429 ;
F_422 ( & V_2 -> V_424 , F_417 ) ;
V_2 -> V_12 . V_69 = V_74 ;
F_423 ( & V_2 -> V_12 . V_270 . V_271 , V_58 | V_284 ) ;
F_419 ( & V_2 -> V_12 . V_270 . V_146 ) ;
F_6 ( F_16 ( V_2 -> V_11 . V_27 ) , V_2 -> V_11 . V_10 ) ;
}
struct V_1 *
F_107 ( struct V_16 * V_17 , T_2 V_10 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
T_9 V_430 ;
int V_22 ;
if ( V_10 >> V_172 > V_431 )
return F_26 ( - V_412 ) ;
if ( F_424 ( V_10 , V_2 -> V_11 . V_10 ) )
return F_26 ( - V_412 ) ;
V_2 = F_101 ( V_17 ) ;
if ( V_2 == NULL )
return F_26 ( - V_53 ) ;
V_22 = F_425 ( & V_17 -> V_176 , & V_2 -> V_11 , V_10 ) ;
if ( V_22 )
goto V_432;
V_430 = V_433 | V_434 ;
if ( F_426 ( V_17 ) || F_427 ( V_17 ) ) {
V_430 &= ~ V_435 ;
V_430 |= V_301 ;
}
V_43 = V_2 -> V_11 . V_44 -> V_45 ;
F_428 ( V_43 , V_430 ) ;
F_45 ( ! ( F_264 ( V_43 ) & V_291 ) ) ;
F_418 ( V_2 , & V_122 ) ;
V_2 -> V_11 . V_66 = V_65 ;
V_2 -> V_11 . V_64 = V_65 ;
if ( F_120 ( V_17 ) ) {
V_2 -> V_136 = V_393 ;
} else
V_2 -> V_136 = V_137 ;
V_2 -> V_4 = F_384 ( V_2 ) ;
V_2 -> V_3 = ! V_2 -> V_4 ;
F_429 ( V_2 ) ;
return V_2 ;
V_432:
F_103 ( V_2 ) ;
return F_26 ( V_22 ) ;
}
static bool F_430 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_69 != V_74 )
return false ;
if ( V_2 -> V_11 . V_44 == NULL )
return true ;
return F_431 ( & V_2 -> V_11 . V_44 -> V_436 ) == 1 ;
}
static void F_432 ( struct V_16 * V_92 ,
struct V_437 * V_438 )
{
struct V_1 * V_2 , * V_258 ;
F_19 ( & V_92 -> V_176 . V_29 ) ;
F_160 ( V_92 ) ;
F_433 (obj, freed, freed) {
struct V_34 * V_35 , * V_379 ;
F_434 ( V_2 ) ;
F_45 ( F_362 ( V_2 ) ) ;
F_220 (vma, vn,
&obj->vma_list, obj_link) {
F_45 ( F_183 ( V_35 ) ) ;
V_35 -> V_84 &= ~ V_439 ;
F_360 ( V_35 ) ;
}
F_45 ( ! F_211 ( & V_2 -> V_80 ) ) ;
F_45 ( ! F_435 ( & V_2 -> V_440 ) ) ;
F_398 ( & V_2 -> V_209 ) ;
}
F_126 ( V_92 ) ;
F_22 ( & V_92 -> V_176 . V_29 ) ;
F_263 () ;
F_436 (obj, on, freed, freed) {
F_45 ( V_2 -> V_206 ) ;
F_45 ( F_247 ( & V_2 -> V_441 ) ) ;
if ( V_2 -> V_117 -> V_442 )
V_2 -> V_117 -> V_442 ( V_2 ) ;
if ( F_24 ( F_244 ( V_2 ) ) )
F_437 ( & V_2 -> V_12 . V_275 , 0 ) ;
F_94 ( V_2 , V_120 ) ;
F_45 ( V_2 -> V_12 . V_67 ) ;
if ( V_2 -> V_11 . V_443 )
F_438 ( & V_2 -> V_11 , NULL ) ;
F_439 ( & V_2 -> V_428 ) ;
F_440 ( & V_2 -> V_11 ) ;
F_9 ( V_92 , V_2 -> V_11 . V_10 ) ;
F_39 ( V_2 -> V_444 ) ;
F_103 ( V_2 ) ;
}
}
static void F_116 ( struct V_16 * V_92 )
{
struct V_437 * V_438 ;
V_438 = F_441 ( & V_92 -> V_12 . V_445 ) ;
if ( F_139 ( V_438 ) )
F_432 ( V_92 , V_438 ) ;
}
static void F_442 ( struct V_370 * V_371 )
{
struct V_16 * V_92 =
F_344 ( V_371 , struct V_16 , V_12 . V_446 ) ;
struct V_437 * V_438 ;
while ( ( V_438 = F_441 ( & V_92 -> V_12 . V_445 ) ) ) {
F_432 ( V_92 , V_438 ) ;
if ( F_443 () )
break;
}
}
static void F_444 ( struct V_447 * V_347 )
{
struct V_1 * V_2 =
F_344 ( V_347 , F_345 ( * V_2 ) , V_448 ) ;
struct V_16 * V_92 = F_16 ( V_2 -> V_11 . V_27 ) ;
if ( F_445 ( & V_2 -> V_438 , & V_92 -> V_12 . V_445 ) )
F_446 ( & V_92 -> V_12 . V_446 ) ;
}
void F_447 ( struct V_377 * V_449 )
{
struct V_1 * V_2 = F_207 ( V_449 ) ;
if ( V_2 -> V_12 . V_308 )
F_416 ( V_2 ) ;
if ( F_430 ( V_2 ) )
V_2 -> V_12 . V_69 = V_71 ;
F_448 ( & V_2 -> V_448 , F_444 ) ;
}
void F_449 ( struct V_1 * V_2 )
{
F_55 ( & V_2 -> V_11 . V_27 -> V_29 ) ;
F_45 ( F_363 ( V_2 ) ) ;
if ( F_362 ( V_2 ) )
F_364 ( V_2 ) ;
else
F_110 ( V_2 ) ;
}
static void F_450 ( struct V_16 * V_17 )
{
struct V_105 * V_94 ;
enum V_340 V_341 ;
F_306 (engine, dev_priv, id)
F_45 ( V_94 -> V_353 &&
! F_451 ( V_94 -> V_353 ) ) ;
}
void F_452 ( struct V_16 * V_92 )
{
if ( F_69 ( V_92 ) >= 5 ) {
int V_450 = F_453 ( V_92 , V_451 ) ;
F_24 ( V_450 && V_450 != - V_158 ) ;
}
}
int F_454 ( struct V_16 * V_17 )
{
struct V_26 * V_27 = & V_17 -> V_176 ;
int V_22 ;
F_160 ( V_17 ) ;
F_455 ( V_17 ) ;
F_19 ( & V_27 -> V_29 ) ;
V_22 = F_456 ( V_17 ) ;
if ( V_22 )
goto V_243;
V_22 = F_224 ( V_17 ,
V_76 |
V_77 ) ;
if ( V_22 )
goto V_243;
F_450 ( V_17 ) ;
F_336 ( V_17 ) ;
F_22 ( & V_27 -> V_29 ) ;
F_457 ( V_17 ) ;
F_353 ( & V_17 -> V_28 . V_375 ) ;
F_353 ( & V_17 -> V_263 . V_264 ) ;
while ( F_226 ( & V_17 -> V_263 . V_366 ) )
;
F_225 ( V_17 ) ;
F_24 ( V_17 -> V_263 . V_355 ) ;
F_24 ( ! F_352 ( V_17 ) ) ;
F_452 ( V_17 ) ;
goto V_452;
V_243:
F_22 ( & V_27 -> V_29 ) ;
V_452:
F_126 ( V_17 ) ;
return V_22 ;
}
void F_458 ( struct V_16 * V_17 )
{
struct V_26 * V_27 = & V_17 -> V_176 ;
F_24 ( V_17 -> V_263 . V_355 ) ;
F_19 ( & V_27 -> V_29 ) ;
F_459 ( V_17 ) ;
V_17 -> V_263 . V_453 ( V_17 ) ;
F_22 ( & V_27 -> V_29 ) ;
}
void F_460 ( struct V_16 * V_17 )
{
if ( F_69 ( V_17 ) < 5 ||
V_17 -> V_12 . V_454 == V_455 )
return;
F_461 ( V_456 , F_462 ( V_456 ) |
V_457 ) ;
if ( F_463 ( V_17 ) )
return;
F_461 ( V_458 , F_462 ( V_458 ) | V_459 ) ;
if ( F_464 ( V_17 ) )
F_461 ( V_460 , F_465 ( V_461 ) ) ;
else if ( F_466 ( V_17 ) )
F_461 ( V_460 , F_465 ( V_462 ) ) ;
else if ( F_467 ( V_17 ) )
F_461 ( V_463 , F_465 ( V_464 ) ) ;
else
F_468 () ;
}
static void F_469 ( struct V_16 * V_17 , T_1 V_11 )
{
F_461 ( F_470 ( V_11 ) , 0 ) ;
F_461 ( F_471 ( V_11 ) , 0 ) ;
F_461 ( F_472 ( V_11 ) , 0 ) ;
F_461 ( F_473 ( V_11 ) , 0 ) ;
}
static void F_474 ( struct V_16 * V_17 )
{
if ( F_475 ( V_17 ) ) {
F_469 ( V_17 , V_465 ) ;
F_469 ( V_17 , V_466 ) ;
F_469 ( V_17 , V_467 ) ;
F_469 ( V_17 , V_468 ) ;
F_469 ( V_17 , V_469 ) ;
} else if ( F_476 ( V_17 ) ) {
F_469 ( V_17 , V_466 ) ;
F_469 ( V_17 , V_467 ) ;
} else if ( F_477 ( V_17 ) ) {
F_469 ( V_17 , V_465 ) ;
F_469 ( V_17 , V_470 ) ;
}
}
static int F_478 ( void * V_30 )
{
struct V_16 * V_92 = V_30 ;
struct V_105 * V_94 ;
enum V_340 V_341 ;
int V_198 ;
F_306 (engine, i915, id) {
V_198 = V_94 -> V_471 ( V_94 ) ;
if ( V_198 )
return V_198 ;
}
return 0 ;
}
int F_479 ( struct V_16 * V_17 )
{
int V_22 ;
V_17 -> V_263 . V_472 = F_369 () ;
F_480 ( V_17 , V_473 ) ;
if ( F_481 ( V_17 ) && F_69 ( V_17 ) < 9 )
F_461 ( V_474 , F_462 ( V_474 ) | F_482 ( 0xf ) ) ;
if ( F_483 ( V_17 ) )
F_461 ( V_475 , F_484 ( V_17 ) ?
V_476 : V_477 ) ;
if ( F_485 ( V_17 ) ) {
if ( F_486 ( V_17 ) ) {
T_1 V_478 = F_462 ( V_479 ) ;
V_478 &= ~ ( V_480 | V_481 ) ;
F_461 ( V_479 , V_478 ) ;
} else if ( F_69 ( V_17 ) >= 7 ) {
T_1 V_478 = F_462 ( V_482 ) ;
V_478 &= ~ V_483 ;
F_461 ( V_482 , V_478 ) ;
}
}
F_460 ( V_17 ) ;
F_474 ( V_17 ) ;
F_487 ( ! V_17 -> V_484 ) ;
V_22 = F_488 ( V_17 ) ;
if ( V_22 ) {
F_14 ( L_14 , V_22 ) ;
goto V_91;
}
V_22 = F_478 ( V_17 ) ;
if ( V_22 )
goto V_91;
F_489 ( V_17 ) ;
V_22 = F_490 ( V_17 ) ;
if ( V_22 )
goto V_91;
V_91:
F_491 ( V_17 , V_473 ) ;
return V_22 ;
}
bool F_492 ( struct V_16 * V_17 , int V_485 )
{
if ( F_493 ( V_17 ) -> V_486 < 6 )
return false ;
if ( V_92 . V_357 )
return false ;
if ( V_485 >= 0 )
return V_485 ;
if ( F_464 ( V_17 ) && F_494 () )
return false ;
return true ;
}
int F_495 ( struct V_16 * V_17 )
{
int V_22 ;
F_19 ( & V_17 -> V_176 . V_29 ) ;
V_17 -> V_12 . V_487 = F_496 ( 1 ) ;
if ( ! V_92 . V_357 ) {
V_17 -> V_263 . V_453 = V_488 ;
V_17 -> V_263 . V_489 = V_490 ;
} else {
V_17 -> V_263 . V_453 = V_491 ;
V_17 -> V_263 . V_489 = V_492 ;
}
F_480 ( V_17 , V_473 ) ;
V_22 = F_497 ( V_17 ) ;
if ( V_22 )
goto V_180;
V_22 = F_498 ( V_17 ) ;
if ( V_22 )
goto V_180;
V_22 = F_499 ( V_17 ) ;
if ( V_22 )
goto V_180;
V_22 = F_500 ( V_17 ) ;
if ( V_22 )
goto V_180;
V_22 = F_479 ( V_17 ) ;
if ( V_22 == - V_25 ) {
F_14 ( L_15 ) ;
F_333 ( V_17 ) ;
V_22 = 0 ;
}
V_180:
F_491 ( V_17 , V_473 ) ;
F_22 ( & V_17 -> V_176 . V_29 ) ;
return V_22 ;
}
void F_501 ( struct V_16 * V_92 )
{
F_452 ( V_92 ) ;
}
void
F_502 ( struct V_16 * V_17 )
{
struct V_105 * V_94 ;
enum V_340 V_341 ;
F_306 (engine, dev_priv, id)
V_17 -> V_263 . V_489 ( V_94 ) ;
}
void
F_503 ( struct V_16 * V_17 )
{
int V_51 ;
if ( F_493 ( V_17 ) -> V_486 >= 7 && ! F_504 ( V_17 ) &&
! F_505 ( V_17 ) )
V_17 -> V_259 = 32 ;
else if ( F_493 ( V_17 ) -> V_486 >= 4 ||
F_506 ( V_17 ) || F_507 ( V_17 ) ||
F_508 ( V_17 ) || F_509 ( V_17 ) )
V_17 -> V_259 = 16 ;
else
V_17 -> V_259 = 8 ;
if ( F_510 ( V_17 ) )
V_17 -> V_259 =
F_462 ( F_511 ( V_493 . V_494 ) ) ;
for ( V_51 = 0 ; V_51 < V_17 -> V_259 ; V_51 ++ ) {
struct V_260 * V_83 = & V_17 -> V_262 [ V_51 ] ;
V_83 -> V_92 = V_17 ;
V_83 -> V_341 = V_51 ;
F_512 ( & V_83 -> V_96 , & V_17 -> V_12 . V_495 ) ;
}
F_319 ( V_17 ) ;
F_513 ( V_17 ) ;
}
int
F_514 ( struct V_16 * V_17 )
{
int V_198 = - V_53 ;
V_17 -> V_128 = F_515 ( V_1 , V_496 ) ;
if ( ! V_17 -> V_128 )
goto V_497;
V_17 -> V_498 = F_515 ( V_34 , V_496 ) ;
if ( ! V_17 -> V_498 )
goto V_499;
V_17 -> V_500 = F_515 ( V_88 ,
V_496 |
V_501 |
V_502 ) ;
if ( ! V_17 -> V_500 )
goto V_503;
V_17 -> V_504 = F_515 ( V_505 ,
V_496 |
V_501 ) ;
if ( ! V_17 -> V_504 )
goto V_506;
V_17 -> V_507 = F_515 ( V_508 , V_496 ) ;
if ( ! V_17 -> V_507 )
goto V_509;
F_19 ( & V_17 -> V_176 . V_29 ) ;
F_420 ( & V_17 -> V_263 . V_510 ) ;
V_198 = F_516 ( V_17 ) ;
F_22 ( & V_17 -> V_176 . V_29 ) ;
if ( V_198 )
goto V_511;
F_420 ( & V_17 -> V_512 ) ;
F_517 ( & V_17 -> V_12 . V_446 , F_442 ) ;
F_518 ( & V_17 -> V_12 . V_445 ) ;
F_420 ( & V_17 -> V_12 . V_208 ) ;
F_420 ( & V_17 -> V_12 . V_207 ) ;
F_420 ( & V_17 -> V_12 . V_495 ) ;
F_420 ( & V_17 -> V_12 . V_246 ) ;
F_519 ( & V_17 -> V_263 . V_264 ,
F_343 ) ;
F_519 ( & V_17 -> V_263 . V_366 ,
F_350 ) ;
F_520 ( & V_17 -> V_28 . V_513 ) ;
F_520 ( & V_17 -> V_28 . V_23 ) ;
F_520 ( & V_17 -> V_514 ) ;
F_437 ( & V_17 -> V_12 . V_515 , 0 ) ;
F_521 ( & V_17 -> V_516 . V_146 ) ;
return 0 ;
V_511:
F_522 ( V_17 -> V_507 ) ;
V_509:
F_522 ( V_17 -> V_504 ) ;
V_506:
F_522 ( V_17 -> V_500 ) ;
V_503:
F_522 ( V_17 -> V_498 ) ;
V_499:
F_522 ( V_17 -> V_128 ) ;
V_497:
return V_198 ;
}
void F_523 ( struct V_16 * V_17 )
{
F_225 ( V_17 ) ;
F_24 ( ! F_524 ( & V_17 -> V_12 . V_445 ) ) ;
F_24 ( V_17 -> V_12 . V_19 ) ;
F_19 ( & V_17 -> V_176 . V_29 ) ;
F_525 ( & V_17 -> V_263 . V_386 ) ;
F_24 ( ! F_211 ( & V_17 -> V_263 . V_510 ) ) ;
F_22 ( & V_17 -> V_176 . V_29 ) ;
F_522 ( V_17 -> V_507 ) ;
F_522 ( V_17 -> V_504 ) ;
F_522 ( V_17 -> V_500 ) ;
F_522 ( V_17 -> V_498 ) ;
F_522 ( V_17 -> V_128 ) ;
F_526 () ;
}
int F_527 ( struct V_16 * V_17 )
{
F_528 ( V_17 ) ;
return 0 ;
}
int F_529 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_201 * V_517 [] = {
& V_17 -> V_12 . V_208 ,
& V_17 -> V_12 . V_207 ,
NULL
} , * * V_518 ;
F_262 ( V_17 , - 1UL , V_295 ) ;
F_225 ( V_17 ) ;
F_19 ( & V_17 -> V_176 . V_29 ) ;
for ( V_518 = V_517 ; * V_518 ; V_518 ++ ) {
F_20 (obj, *p, global_link)
F_43 ( V_2 ) ;
}
F_22 ( & V_17 -> V_176 . V_29 ) ;
return 0 ;
}
void F_530 ( struct V_26 * V_27 , struct V_31 * V_32 )
{
struct V_113 * V_330 = V_32 -> V_115 ;
struct V_88 * V_333 ;
F_7 ( & V_330 -> V_12 . V_146 ) ;
F_20 (request, &file_priv->mm.request_list, client_link)
V_333 -> V_330 = NULL ;
F_8 ( & V_330 -> V_12 . V_146 ) ;
if ( ! F_211 ( & V_330 -> V_87 . V_96 ) ) {
F_7 ( & F_16 ( V_27 ) -> V_87 . V_95 ) ;
F_398 ( & V_330 -> V_87 . V_96 ) ;
F_8 ( & F_16 ( V_27 ) -> V_87 . V_95 ) ;
}
}
int F_531 ( struct V_26 * V_27 , struct V_31 * V_32 )
{
struct V_113 * V_330 ;
int V_22 ;
F_273 ( L_16 ) ;
V_330 = F_532 ( sizeof( * V_330 ) , V_58 ) ;
if ( ! V_330 )
return - V_53 ;
V_32 -> V_115 = V_330 ;
V_330 -> V_17 = F_16 ( V_27 ) ;
V_330 -> V_32 = V_32 ;
F_420 ( & V_330 -> V_87 . V_96 ) ;
F_521 ( & V_330 -> V_12 . V_146 ) ;
F_420 ( & V_330 -> V_12 . V_519 ) ;
V_330 -> V_520 = - 1 ;
V_22 = F_533 ( V_27 , V_32 ) ;
if ( V_22 )
F_39 ( V_330 ) ;
return V_22 ;
}
void F_534 ( struct V_1 * V_521 ,
struct V_1 * V_522 ,
unsigned V_441 )
{
F_63 ( V_523 * V_524 >
sizeof( V_525 ) * V_526 ) ;
if ( V_521 ) {
F_24 ( ! ( F_247 ( & V_521 -> V_441 ) & V_441 ) ) ;
F_535 ( V_441 , & V_521 -> V_441 ) ;
}
if ( V_522 ) {
F_24 ( F_247 ( & V_522 -> V_441 ) & V_441 ) ;
F_536 ( V_441 , & V_522 -> V_441 ) ;
}
}
struct V_1 *
F_537 ( struct V_16 * V_17 ,
const void * V_30 , T_14 V_10 )
{
struct V_1 * V_2 ;
struct V_32 * V_32 ;
T_14 V_60 ;
int V_198 ;
V_2 = F_107 ( V_17 , F_141 ( V_10 , V_54 ) ) ;
if ( F_30 ( V_2 ) )
return V_2 ;
F_45 ( V_2 -> V_11 . V_66 != V_65 ) ;
V_32 = V_2 -> V_11 . V_44 ;
V_60 = 0 ;
do {
unsigned int V_193 = F_204 ( F_345 ( V_10 ) , V_10 , V_54 ) ;
struct V_55 * V_55 ;
void * V_527 , * V_50 ;
V_198 = F_289 ( V_32 , V_32 -> V_45 ,
V_60 , V_193 , 0 ,
& V_55 , & V_527 ) ;
if ( V_198 < 0 )
goto V_432;
V_50 = F_143 ( V_55 ) ;
memcpy ( V_50 , V_30 , V_193 ) ;
F_144 ( V_55 ) ;
V_198 = F_290 ( V_32 , V_32 -> V_45 ,
V_60 , V_193 , V_193 ,
V_55 , V_527 ) ;
if ( V_198 < 0 )
goto V_432;
V_10 -= V_193 ;
V_30 += V_193 ;
V_60 += V_193 ;
} while ( V_10 );
return V_2 ;
V_432:
F_110 ( V_2 ) ;
return F_26 ( V_198 ) ;
}
struct V_48 *
F_538 ( struct V_1 * V_2 ,
unsigned int V_360 ,
unsigned int * V_60 )
{
struct V_528 * V_268 = & V_2 -> V_12 . V_270 ;
struct V_48 * V_49 ;
unsigned int V_171 , V_103 ;
F_11 () ;
F_45 ( V_360 >= V_2 -> V_11 . V_10 >> V_172 ) ;
F_45 ( ! F_244 ( V_2 ) ) ;
if ( V_360 < F_245 ( V_268 -> V_305 ) )
goto V_529;
F_19 ( & V_268 -> V_146 ) ;
V_49 = V_268 -> V_304 ;
V_171 = V_268 -> V_305 ;
V_103 = F_539 ( V_49 ) ;
while ( V_171 + V_103 <= V_360 ) {
unsigned long V_530 , V_51 ;
int V_22 ;
V_22 = F_540 ( & V_268 -> V_271 , V_171 , V_49 ) ;
if ( V_22 && V_22 != - V_531 )
goto V_532;
V_530 =
V_533 |
V_171 << V_534 ;
for ( V_51 = 1 ; V_51 < V_103 ; V_51 ++ ) {
V_22 = F_540 ( & V_268 -> V_271 , V_171 + V_51 ,
( void * ) V_530 ) ;
if ( V_22 && V_22 != - V_531 )
goto V_532;
}
V_171 += V_103 ;
V_49 = F_541 ( V_49 ) ;
V_103 = F_539 ( V_49 ) ;
}
V_532:
V_268 -> V_304 = V_49 ;
V_268 -> V_305 = V_171 ;
F_22 ( & V_268 -> V_146 ) ;
if ( F_139 ( V_360 < V_171 ) )
goto V_529;
while ( V_171 + V_103 <= V_360 ) {
V_171 += V_103 ;
V_49 = F_541 ( V_49 ) ;
V_103 = F_539 ( V_49 ) ;
}
* V_60 = V_360 - V_171 ;
return V_49 ;
V_529:
F_386 () ;
V_49 = F_542 ( & V_268 -> V_271 , V_360 ) ;
F_45 ( ! V_49 ) ;
* V_60 = 0 ;
if ( F_139 ( F_543 ( V_49 ) ) ) {
unsigned long V_11 =
( unsigned long ) V_49 >> V_534 ;
V_49 = F_542 ( & V_268 -> V_271 , V_11 ) ;
F_45 ( ! V_49 ) ;
* V_60 = V_360 - V_11 ;
}
F_388 () ;
return V_49 ;
}
struct V_55 *
F_150 ( struct V_1 * V_2 , unsigned int V_360 )
{
struct V_48 * V_49 ;
unsigned int V_60 ;
F_45 ( ! F_134 ( V_2 ) ) ;
V_49 = F_538 ( V_2 , V_360 , & V_60 ) ;
return F_544 ( F_256 ( V_49 ) , V_60 ) ;
}
struct V_55 *
F_545 ( struct V_1 * V_2 ,
unsigned int V_360 )
{
struct V_55 * V_55 ;
V_55 = F_150 ( V_2 , V_360 ) ;
if ( ! V_2 -> V_12 . V_72 )
F_48 ( V_55 ) ;
return V_55 ;
}
T_15
F_166 ( struct V_1 * V_2 ,
unsigned long V_360 )
{
struct V_48 * V_49 ;
unsigned int V_60 ;
V_49 = F_538 ( V_2 , V_360 , & V_60 ) ;
return F_40 ( V_49 ) + ( V_60 << V_172 ) ;
}

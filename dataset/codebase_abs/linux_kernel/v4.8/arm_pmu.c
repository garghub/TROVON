static int
F_1 ( T_1 V_1 , T_2 V_2 )
{
return ( int ) ( V_2 & V_1 ) ;
}
int F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
struct V_8 * V_9 = & V_4 -> V_10 ;
T_3 V_11 = F_4 ( & V_9 -> V_12 ) ;
T_3 V_13 = V_9 -> V_14 ;
int V_15 = 0 ;
if ( F_5 ( V_11 <= - V_13 ) ) {
V_11 = V_13 ;
F_6 ( & V_9 -> V_12 , V_11 ) ;
V_9 -> V_16 = V_13 ;
V_15 = 1 ;
}
if ( F_5 ( V_11 <= 0 ) ) {
V_11 += V_13 ;
F_6 ( & V_9 -> V_12 , V_11 ) ;
V_9 -> V_16 = V_13 ;
V_15 = 1 ;
}
if ( V_11 > ( V_6 -> V_17 >> 1 ) )
V_11 = V_6 -> V_17 >> 1 ;
F_6 ( & V_9 -> V_18 , ( T_2 ) - V_11 ) ;
V_6 -> V_19 ( V_4 , ( T_2 ) ( - V_11 ) & 0xffffffff ) ;
F_7 ( V_4 ) ;
return V_15 ;
}
T_2 F_8 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
struct V_8 * V_9 = & V_4 -> V_10 ;
T_2 V_20 , V_21 , V_22 ;
V_23:
V_21 = F_4 ( & V_9 -> V_18 ) ;
V_22 = V_6 -> V_24 ( V_4 ) ;
if ( F_9 ( & V_9 -> V_18 , V_21 ,
V_22 ) != V_21 )
goto V_23;
V_20 = ( V_22 - V_21 ) & V_6 -> V_17 ;
F_10 ( V_20 , & V_4 -> V_25 ) ;
F_11 ( V_20 , & V_9 -> V_12 ) ;
return V_22 ;
}
static void
F_12 ( struct V_3 * V_4 )
{
F_8 ( V_4 ) ;
}
static void
F_13 ( struct V_3 * V_4 , int V_26 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
struct V_8 * V_9 = & V_4 -> V_10 ;
if ( ! ( V_9 -> V_27 & V_28 ) ) {
V_6 -> V_29 ( V_4 ) ;
F_8 ( V_4 ) ;
V_9 -> V_27 |= V_28 | V_30 ;
}
}
static void F_14 ( struct V_3 * V_4 , int V_26 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
struct V_8 * V_9 = & V_4 -> V_10 ;
if ( V_26 & V_31 )
F_15 ( ! ( V_9 -> V_27 & V_30 ) ) ;
V_9 -> V_27 = 0 ;
F_2 ( V_4 ) ;
V_6 -> V_32 ( V_4 ) ;
}
static void
F_16 ( struct V_3 * V_4 , int V_26 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
struct V_33 * V_34 = F_17 ( V_6 -> V_34 ) ;
struct V_8 * V_9 = & V_4 -> V_10 ;
int V_35 = V_9 -> V_35 ;
F_13 ( V_4 , V_36 ) ;
V_34 -> V_37 [ V_35 ] = NULL ;
F_18 ( V_35 , V_34 -> V_38 ) ;
if ( V_6 -> V_39 )
V_6 -> V_39 ( V_34 , V_4 ) ;
F_7 ( V_4 ) ;
}
static int
F_19 ( struct V_3 * V_4 , int V_26 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
struct V_33 * V_34 = F_17 ( V_6 -> V_34 ) ;
struct V_8 * V_9 = & V_4 -> V_10 ;
int V_35 ;
int V_40 = 0 ;
if ( ! F_20 ( F_21 () , & V_6 -> V_41 ) )
return - V_42 ;
F_22 ( V_4 -> V_7 ) ;
V_35 = V_6 -> V_43 ( V_34 , V_4 ) ;
if ( V_35 < 0 ) {
V_40 = V_35 ;
goto V_44;
}
V_4 -> V_10 . V_35 = V_35 ;
V_6 -> V_29 ( V_4 ) ;
V_34 -> V_37 [ V_35 ] = V_4 ;
V_9 -> V_27 = V_28 | V_30 ;
if ( V_26 & V_45 )
F_14 ( V_4 , V_31 ) ;
F_7 ( V_4 ) ;
V_44:
F_23 ( V_4 -> V_7 ) ;
return V_40 ;
}
static int
F_24 ( struct V_7 * V_7 , struct V_33 * V_34 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( F_25 ( V_4 ) )
return 1 ;
if ( V_4 -> V_7 != V_7 )
return 0 ;
if ( V_4 -> V_27 < V_46 )
return 1 ;
if ( V_4 -> V_27 == V_46 && ! V_4 -> V_47 . V_48 )
return 1 ;
V_6 = F_3 ( V_4 -> V_7 ) ;
return V_6 -> V_43 ( V_34 , V_4 ) >= 0 ;
}
static int
F_26 ( struct V_3 * V_4 )
{
struct V_3 * V_49 , * V_50 = V_4 -> V_51 ;
struct V_33 V_52 ;
memset ( & V_52 . V_38 , 0 , sizeof( V_52 . V_38 ) ) ;
if ( ! F_24 ( V_4 -> V_7 , & V_52 , V_50 ) )
return - V_53 ;
F_27 (sibling, &leader->sibling_list, group_entry) {
if ( ! F_24 ( V_4 -> V_7 , & V_52 , V_49 ) )
return - V_53 ;
}
if ( ! F_24 ( V_4 -> V_7 , & V_52 , V_4 ) )
return - V_53 ;
return 0 ;
}
static T_4 F_28 ( int V_54 , void * V_55 )
{
struct V_5 * V_6 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
int V_15 ;
T_2 V_60 , V_61 ;
V_6 = * ( void * * ) V_55 ;
V_57 = V_6 -> V_57 ;
V_59 = F_29 ( & V_57 -> V_55 ) ;
V_60 = F_30 () ;
if ( V_59 && V_59 -> V_62 )
V_15 = V_59 -> V_62 ( V_54 , V_6 , V_6 -> V_62 ) ;
else
V_15 = V_6 -> V_62 ( V_54 , V_6 ) ;
V_61 = F_30 () ;
F_31 ( V_61 - V_60 ) ;
return V_15 ;
}
static void
F_32 ( struct V_5 * V_6 )
{
V_6 -> V_63 ( V_6 ) ;
}
static int
F_33 ( struct V_5 * V_6 )
{
int V_40 = V_6 -> V_64 ( V_6 , F_28 ) ;
if ( V_40 ) {
F_32 ( V_6 ) ;
return V_40 ;
}
return 0 ;
}
static void
F_34 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
T_5 * V_65 = & V_6 -> V_65 ;
struct V_66 * V_67 = & V_6 -> V_68 ;
if ( F_35 ( V_65 , V_67 ) ) {
F_32 ( V_6 ) ;
F_36 ( V_67 ) ;
}
}
static int
F_37 ( struct V_69 * V_47 )
{
return V_47 -> V_70 || V_47 -> V_71 ||
V_47 -> V_72 || V_47 -> V_73 ;
}
static int
F_38 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
struct V_8 * V_9 = & V_4 -> V_10 ;
int V_74 ;
V_74 = V_6 -> V_75 ( V_4 ) ;
if ( V_74 < 0 ) {
F_39 ( L_1 , V_4 -> V_47 . type ,
V_4 -> V_47 . V_2 ) ;
return V_74 ;
}
V_9 -> V_35 = - 1 ;
V_9 -> V_76 = 0 ;
V_9 -> V_2 = 0 ;
V_9 -> V_77 = 0 ;
if ( ( ! V_6 -> V_78 ||
V_6 -> V_78 ( V_9 , & V_4 -> V_47 ) ) &&
F_37 ( & V_4 -> V_47 ) ) {
F_39 ( L_2
L_3 ) ;
return - V_79 ;
}
V_9 -> V_76 |= ( unsigned long ) V_74 ;
if ( ! F_40 ( V_4 ) ) {
V_9 -> V_14 = V_6 -> V_17 >> 1 ;
V_9 -> V_16 = V_9 -> V_14 ;
F_6 ( & V_9 -> V_12 , V_9 -> V_14 ) ;
}
if ( V_4 -> V_51 != V_4 ) {
if ( F_26 ( V_4 ) != 0 )
return - V_53 ;
}
return 0 ;
}
static int F_41 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
int V_40 = 0 ;
T_5 * V_65 = & V_6 -> V_65 ;
if ( V_4 -> V_80 != - 1 &&
! F_20 ( V_4 -> V_80 , & V_6 -> V_41 ) )
return - V_42 ;
if ( F_42 ( V_4 ) )
return - V_79 ;
if ( V_6 -> V_75 ( V_4 ) == - V_42 )
return - V_42 ;
V_4 -> V_81 = F_34 ;
if ( ! F_43 ( V_65 ) ) {
F_44 ( & V_6 -> V_68 ) ;
if ( F_45 ( V_65 ) == 0 )
V_40 = F_33 ( V_6 ) ;
if ( ! V_40 )
F_46 ( V_65 ) ;
F_36 ( & V_6 -> V_68 ) ;
}
if ( V_40 )
return V_40 ;
V_40 = F_38 ( V_4 ) ;
if ( V_40 )
F_34 ( V_4 ) ;
return V_40 ;
}
static void F_47 ( struct V_7 * V_7 )
{
struct V_5 * V_6 = F_3 ( V_7 ) ;
struct V_33 * V_34 = F_17 ( V_6 -> V_34 ) ;
int V_82 = F_48 ( V_34 -> V_38 , V_6 -> V_83 ) ;
if ( ! F_20 ( F_21 () , & V_6 -> V_41 ) )
return;
if ( V_82 )
V_6 -> V_84 ( V_6 ) ;
}
static void F_49 ( struct V_7 * V_7 )
{
struct V_5 * V_6 = F_3 ( V_7 ) ;
if ( ! F_20 ( F_21 () , & V_6 -> V_41 ) )
return;
V_6 -> V_85 ( V_6 ) ;
}
static int F_50 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
unsigned int V_80 = F_21 () ;
return F_20 ( V_80 , & V_6 -> V_41 ) ;
}
static void F_51 ( struct V_5 * V_6 )
{
F_52 ( & V_6 -> V_65 , 0 ) ;
F_53 ( & V_6 -> V_68 ) ;
V_6 -> V_7 = (struct V_7 ) {
. V_86 = F_47 ,
. V_87 = F_49 ,
. V_88 = F_41 ,
. V_89 = F_19 ,
. V_90 = F_16 ,
. V_84 = F_14 ,
. V_85 = F_13 ,
. V_91 = F_12 ,
. V_92 = F_50 ,
} ;
}
const char * F_54 ( void )
{
if ( ! V_93 )
return NULL ;
return V_93 -> V_94 ;
}
int F_55 ( void )
{
int V_95 = 0 ;
if ( V_93 != NULL )
V_95 = V_93 -> V_83 ;
return V_95 ;
}
static void F_56 ( void * V_96 )
{
int V_54 = * ( int * ) V_96 ;
F_57 ( V_54 , V_97 ) ;
}
static void F_58 ( void * V_96 )
{
int V_54 = * ( int * ) V_96 ;
F_59 ( V_54 ) ;
}
static void F_60 ( struct V_5 * V_98 )
{
int V_99 , V_54 , V_100 ;
struct V_56 * V_101 = V_98 -> V_57 ;
struct V_33 T_6 * V_34 = V_98 -> V_34 ;
V_100 = F_61 ( V_101 -> V_102 , F_62 () ) ;
V_54 = F_63 ( V_101 , 0 ) ;
if ( V_54 >= 0 && F_64 ( V_54 ) ) {
F_65 ( & V_98 -> V_41 ,
F_58 , & V_54 , 1 ) ;
F_66 ( V_54 , & V_34 -> V_103 ) ;
} else {
for ( V_99 = 0 ; V_99 < V_100 ; ++ V_99 ) {
int V_80 = V_99 ;
if ( V_98 -> V_104 )
V_80 = V_98 -> V_104 [ V_99 ] ;
if ( ! F_67 ( V_80 , & V_98 -> V_105 ) )
continue;
V_54 = F_63 ( V_101 , V_99 ) ;
if ( V_54 >= 0 )
V_63 ( V_54 , F_68 ( & V_34 -> V_103 , V_80 ) ) ;
}
}
}
static int F_69 ( struct V_5 * V_98 , T_7 V_106 )
{
int V_99 , V_40 , V_54 , V_100 ;
struct V_56 * V_101 = V_98 -> V_57 ;
struct V_33 T_6 * V_34 = V_98 -> V_34 ;
if ( ! V_101 )
return - V_107 ;
V_100 = F_61 ( V_101 -> V_102 , F_62 () ) ;
if ( V_100 < 1 ) {
F_70 ( L_4 ) ;
return 0 ;
}
V_54 = F_63 ( V_101 , 0 ) ;
if ( V_54 >= 0 && F_64 ( V_54 ) ) {
V_40 = F_71 ( V_54 , V_106 , L_5 ,
& V_34 -> V_103 ) ;
if ( V_40 ) {
F_72 ( L_6 ,
V_54 ) ;
return V_40 ;
}
F_65 ( & V_98 -> V_41 ,
F_56 , & V_54 , 1 ) ;
} else {
for ( V_99 = 0 ; V_99 < V_100 ; ++ V_99 ) {
int V_80 = V_99 ;
V_40 = 0 ;
V_54 = F_63 ( V_101 , V_99 ) ;
if ( V_54 < 0 )
continue;
if ( V_98 -> V_104 )
V_80 = V_98 -> V_104 [ V_99 ] ;
if ( F_73 ( V_54 , F_74 ( V_80 ) ) && V_100 > 1 ) {
F_75 ( L_7 ,
V_54 , V_80 ) ;
continue;
}
V_40 = V_64 ( V_54 , V_106 ,
V_108 | V_109 , L_5 ,
F_68 ( & V_34 -> V_103 , V_80 ) ) ;
if ( V_40 ) {
F_72 ( L_6 ,
V_54 ) ;
return V_40 ;
}
F_76 ( V_80 , & V_98 -> V_105 ) ;
}
}
return 0 ;
}
static int F_77 ( unsigned int V_80 )
{
struct V_5 * V_7 ;
F_78 ( & V_110 ) ;
F_27 (pmu, &arm_pmu_list, entry) {
if ( ! F_20 ( V_80 , & V_7 -> V_41 ) )
continue;
if ( V_7 -> V_111 )
V_7 -> V_111 ( V_7 ) ;
}
F_79 ( & V_110 ) ;
return 0 ;
}
static void F_80 ( struct V_5 * V_6 , unsigned long V_112 )
{
struct V_33 * V_34 = F_17 ( V_6 -> V_34 ) ;
struct V_3 * V_4 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_6 -> V_83 ; V_35 ++ ) {
if ( ! F_81 ( V_35 , V_34 -> V_38 ) )
continue;
V_4 = V_34 -> V_37 [ V_35 ] ;
switch ( V_112 ) {
case V_113 :
F_13 ( V_4 , V_36 ) ;
break;
case V_114 :
case V_115 :
F_82 ( F_14 ( V_4 , V_31 ) ) ;
break;
default:
break;
}
}
}
static int F_83 ( struct V_116 * V_117 , unsigned long V_112 ,
void * V_118 )
{
struct V_5 * V_6 = F_84 ( V_117 , struct V_5 , V_119 ) ;
struct V_33 * V_34 = F_17 ( V_6 -> V_34 ) ;
int V_82 = F_48 ( V_34 -> V_38 , V_6 -> V_83 ) ;
if ( ! F_20 ( F_21 () , & V_6 -> V_41 ) )
return V_120 ;
if ( V_112 == V_114 && V_6 -> V_111 )
V_6 -> V_111 ( V_6 ) ;
if ( ! V_82 )
return V_121 ;
switch ( V_112 ) {
case V_113 :
V_6 -> V_85 ( V_6 ) ;
F_80 ( V_6 , V_112 ) ;
break;
case V_114 :
F_80 ( V_6 , V_112 ) ;
case V_115 :
V_6 -> V_84 ( V_6 ) ;
break;
default:
return V_120 ;
}
return V_121 ;
}
static int F_85 ( struct V_5 * V_98 )
{
V_98 -> V_119 . V_122 = F_83 ;
return F_86 ( & V_98 -> V_119 ) ;
}
static void F_87 ( struct V_5 * V_98 )
{
F_88 ( & V_98 -> V_119 ) ;
}
static inline int F_85 ( struct V_5 * V_98 ) { return 0 ; }
static inline void F_87 ( struct V_5 * V_98 ) { }
static int F_89 ( struct V_5 * V_98 )
{
int V_40 ;
int V_80 ;
struct V_33 T_6 * V_123 ;
V_123 = F_90 ( struct V_33 ) ;
if ( ! V_123 )
return - V_124 ;
F_78 ( & V_110 ) ;
F_91 ( & V_98 -> V_125 , & V_126 ) ;
F_79 ( & V_110 ) ;
V_40 = F_85 ( V_98 ) ;
if ( V_40 )
goto V_127;
F_92 (cpu) {
struct V_33 * V_37 = F_68 ( V_123 , V_80 ) ;
F_93 ( & V_37 -> V_128 ) ;
V_37 -> V_103 = V_98 ;
}
V_98 -> V_34 = V_123 ;
V_98 -> V_64 = F_69 ;
V_98 -> V_63 = F_60 ;
if ( V_98 -> V_111 )
F_65 ( & V_98 -> V_41 , V_98 -> V_111 ,
V_98 , 1 ) ;
if ( ! F_63 ( V_98 -> V_57 , 0 ) )
V_98 -> V_7 . V_129 |= V_130 ;
V_98 -> V_7 . V_129 |= V_131 ;
return 0 ;
V_127:
F_78 ( & V_110 ) ;
F_94 ( & V_98 -> V_125 ) ;
F_79 ( & V_110 ) ;
F_95 ( V_123 ) ;
return V_40 ;
}
static void F_96 ( struct V_5 * V_98 )
{
F_87 ( V_98 ) ;
F_78 ( & V_110 ) ;
F_94 ( & V_98 -> V_125 ) ;
F_79 ( & V_110 ) ;
F_95 ( V_98 -> V_34 ) ;
}
static int F_97 ( struct V_5 * V_7 ,
const struct V_132 * V_133 )
{
int V_80 = F_98 () ;
unsigned int V_134 = F_99 () ;
int V_15 = - V_107 ;
F_100 ( L_8 , V_80 ) ;
for (; V_133 -> V_135 != NULL ; V_133 ++ ) {
if ( ( V_134 & V_133 -> V_136 ) != V_133 -> V_134 )
continue;
V_15 = V_133 -> V_135 ( V_7 ) ;
break;
}
F_101 () ;
return V_15 ;
}
static int F_102 ( struct V_5 * V_7 )
{
int * V_100 , V_99 = 0 ;
bool V_137 = false ;
struct V_56 * V_138 = V_7 -> V_57 ;
V_100 = F_103 ( V_138 -> V_102 , sizeof( * V_100 ) , V_139 ) ;
if ( ! V_100 )
return - V_124 ;
do {
struct V_140 * V_141 ;
int V_80 , V_54 ;
V_141 = F_104 ( V_138 -> V_55 . V_142 , L_9 , V_99 ) ;
if ( ! V_141 )
break;
V_54 = F_63 ( V_138 , V_99 ) ;
if ( V_54 >= 0 ) {
bool V_143 = ! F_64 ( V_54 ) ;
if ( V_99 > 0 && V_143 != V_137 ) {
F_72 ( L_10 ,
V_141 -> V_94 ) ;
F_105 ( V_141 ) ;
F_106 ( V_100 ) ;
return - V_53 ;
}
V_137 = V_143 ;
}
F_92 (cpu) {
struct V_140 * V_144 ;
V_144 = F_107 ( V_80 ) ;
F_105 ( V_144 ) ;
if ( V_141 == V_144 )
break;
}
if ( V_80 >= V_145 ) {
F_75 ( L_11 ,
V_141 -> V_94 ) ;
F_105 ( V_141 ) ;
F_108 ( & V_7 -> V_41 ) ;
break;
}
F_105 ( V_141 ) ;
if ( V_137 ) {
if ( V_99 >= V_138 -> V_102 )
break;
V_100 [ V_99 ] = V_80 ;
}
F_76 ( V_80 , & V_7 -> V_41 ) ;
V_99 ++ ;
} while ( 1 );
if ( F_109 ( & V_7 -> V_41 ) == 0 ) {
int V_54 = F_63 ( V_138 , 0 ) ;
if ( V_54 >= 0 && F_64 ( V_54 ) ) {
int V_15 ;
V_15 = F_110 ( V_54 , & V_7 -> V_41 ) ;
if ( V_15 ) {
F_106 ( V_100 ) ;
return V_15 ;
}
} else {
F_108 ( & V_7 -> V_41 ) ;
}
}
if ( V_137 && V_99 == V_138 -> V_102 )
V_7 -> V_104 = V_100 ;
else
F_106 ( V_100 ) ;
return 0 ;
}
int F_111 ( struct V_56 * V_138 ,
const struct V_146 * V_147 ,
const struct V_132 * V_148 )
{
const struct V_146 * V_149 ;
const int (* F_112)( struct V_5 * );
struct V_140 * V_150 = V_138 -> V_55 . V_142 ;
struct V_5 * V_7 ;
int V_15 = - V_107 ;
V_7 = F_113 ( sizeof( struct V_5 ) , V_139 ) ;
if ( ! V_7 ) {
F_100 ( L_12 ) ;
return - V_124 ;
}
F_51 ( V_7 ) ;
V_7 -> V_57 = V_138 ;
if ( V_150 && ( V_149 = F_114 ( V_147 , V_138 -> V_55 . V_142 ) ) ) {
F_112 = V_149 -> V_96 ;
V_7 -> V_151 = F_115 ( V_138 -> V_55 . V_142 ,
L_13 ) ;
if ( F_116 ( V_152 ) && V_7 -> V_151 ) {
F_75 ( L_14 ) ;
V_7 -> V_151 = false ;
}
V_15 = F_102 ( V_7 ) ;
if ( ! V_15 )
V_15 = F_112 ( V_7 ) ;
} else {
F_108 ( & V_7 -> V_41 ) ;
V_15 = F_97 ( V_7 , V_148 ) ;
}
if ( V_15 ) {
F_100 ( L_15 , F_117 ( V_150 ) ) ;
goto V_153;
}
V_15 = F_89 ( V_7 ) ;
if ( V_15 )
goto V_153;
V_15 = F_118 ( & V_7 -> V_7 , V_7 -> V_94 , - 1 ) ;
if ( V_15 )
goto V_154;
if ( ! V_93 )
V_93 = V_7 ;
F_100 ( L_16 ,
V_7 -> V_94 , V_7 -> V_83 ) ;
return 0 ;
V_154:
F_96 ( V_7 ) ;
V_153:
F_100 ( L_17 ,
F_117 ( V_150 ) ) ;
F_106 ( V_7 -> V_104 ) ;
F_106 ( V_7 ) ;
return V_15 ;
}
static int F_119 ( void )
{
int V_15 ;
V_15 = F_120 ( V_155 ,
L_18 ,
F_77 , NULL ) ;
if ( V_15 )
F_72 ( L_19 ,
V_15 ) ;
return V_15 ;
}

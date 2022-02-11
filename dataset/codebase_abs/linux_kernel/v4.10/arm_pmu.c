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
static T_6 F_51 ( struct V_86 * V_55 ,
struct V_87 * V_47 , char * V_88 )
{
struct V_5 * V_6 = F_3 ( F_52 ( V_55 ) ) ;
return F_53 ( true , V_88 , & V_6 -> V_41 ) ;
}
static void F_54 ( struct V_5 * V_6 )
{
F_55 ( & V_6 -> V_65 , 0 ) ;
F_56 ( & V_6 -> V_68 ) ;
V_6 -> V_7 = (struct V_7 ) {
. V_89 = F_47 ,
. V_90 = F_49 ,
. V_91 = F_41 ,
. V_92 = F_19 ,
. V_93 = F_16 ,
. V_84 = F_14 ,
. V_85 = F_13 ,
. V_94 = F_12 ,
. V_95 = F_50 ,
. V_96 = V_6 -> V_96 ,
} ;
V_6 -> V_96 [ V_97 ] =
& V_98 ;
}
const char * F_57 ( void )
{
if ( ! V_99 )
return NULL ;
return V_99 -> V_100 ;
}
int F_58 ( void )
{
int V_101 = 0 ;
if ( V_99 != NULL )
V_101 = V_99 -> V_83 ;
return V_101 ;
}
static void F_59 ( void * V_102 )
{
int V_54 = * ( int * ) V_102 ;
F_60 ( V_54 , V_103 ) ;
}
static void F_61 ( void * V_102 )
{
int V_54 = * ( int * ) V_102 ;
F_62 ( V_54 ) ;
}
static void F_63 ( struct V_5 * V_104 )
{
int V_105 , V_54 , V_106 ;
struct V_56 * V_107 = V_104 -> V_57 ;
struct V_33 T_7 * V_34 = V_104 -> V_34 ;
V_106 = F_64 ( V_107 -> V_108 , F_65 () ) ;
V_54 = F_66 ( V_107 , 0 ) ;
if ( V_54 > 0 && F_67 ( V_54 ) ) {
F_68 ( & V_104 -> V_41 ,
F_61 , & V_54 , 1 ) ;
F_69 ( V_54 , & V_34 -> V_109 ) ;
} else {
for ( V_105 = 0 ; V_105 < V_106 ; ++ V_105 ) {
int V_80 = V_105 ;
if ( V_104 -> V_110 )
V_80 = V_104 -> V_110 [ V_105 ] ;
if ( ! F_70 ( V_80 , & V_104 -> V_111 ) )
continue;
V_54 = F_66 ( V_107 , V_105 ) ;
if ( V_54 > 0 )
V_63 ( V_54 , F_71 ( & V_34 -> V_109 , V_80 ) ) ;
}
}
}
static int F_72 ( struct V_5 * V_104 , T_8 V_112 )
{
int V_105 , V_40 , V_54 , V_106 ;
struct V_56 * V_107 = V_104 -> V_57 ;
struct V_33 T_7 * V_34 = V_104 -> V_34 ;
if ( ! V_107 )
return - V_113 ;
V_106 = F_64 ( V_107 -> V_108 , F_65 () ) ;
if ( V_106 < 1 ) {
F_73 ( L_4 ) ;
return 0 ;
}
V_54 = F_66 ( V_107 , 0 ) ;
if ( V_54 > 0 && F_67 ( V_54 ) ) {
V_40 = F_74 ( V_54 , V_112 , L_5 ,
& V_34 -> V_109 ) ;
if ( V_40 ) {
F_75 ( L_6 ,
V_54 ) ;
return V_40 ;
}
F_68 ( & V_104 -> V_41 ,
F_59 , & V_54 , 1 ) ;
} else {
for ( V_105 = 0 ; V_105 < V_106 ; ++ V_105 ) {
int V_80 = V_105 ;
V_40 = 0 ;
V_54 = F_66 ( V_107 , V_105 ) ;
if ( V_54 < 0 )
continue;
if ( V_104 -> V_110 )
V_80 = V_104 -> V_110 [ V_105 ] ;
if ( F_76 ( V_54 , F_77 ( V_80 ) ) && V_106 > 1 ) {
F_78 ( L_7 ,
V_54 , V_80 ) ;
continue;
}
V_40 = V_64 ( V_54 , V_112 ,
V_114 | V_115 , L_5 ,
F_71 ( & V_34 -> V_109 , V_80 ) ) ;
if ( V_40 ) {
F_75 ( L_6 ,
V_54 ) ;
return V_40 ;
}
F_79 ( V_80 , & V_104 -> V_111 ) ;
}
}
return 0 ;
}
static int F_80 ( unsigned int V_80 , struct V_116 * V_117 )
{
struct V_5 * V_7 = F_81 ( V_117 , struct V_5 , V_117 ) ;
if ( ! F_20 ( V_80 , & V_7 -> V_41 ) )
return 0 ;
if ( V_7 -> V_118 )
V_7 -> V_118 ( V_7 ) ;
return 0 ;
}
static void F_82 ( struct V_5 * V_6 , unsigned long V_119 )
{
struct V_33 * V_34 = F_17 ( V_6 -> V_34 ) ;
struct V_3 * V_4 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_6 -> V_83 ; V_35 ++ ) {
if ( ! F_83 ( V_35 , V_34 -> V_38 ) )
continue;
V_4 = V_34 -> V_37 [ V_35 ] ;
switch ( V_119 ) {
case V_120 :
F_13 ( V_4 , V_36 ) ;
break;
case V_121 :
case V_122 :
F_84 ( F_14 ( V_4 , V_31 ) ) ;
break;
default:
break;
}
}
}
static int F_85 ( struct V_123 * V_124 , unsigned long V_119 ,
void * V_125 )
{
struct V_5 * V_6 = F_86 ( V_124 , struct V_5 , V_126 ) ;
struct V_33 * V_34 = F_17 ( V_6 -> V_34 ) ;
int V_82 = F_48 ( V_34 -> V_38 , V_6 -> V_83 ) ;
if ( ! F_20 ( F_21 () , & V_6 -> V_41 ) )
return V_127 ;
if ( V_119 == V_121 && V_6 -> V_118 )
V_6 -> V_118 ( V_6 ) ;
if ( ! V_82 )
return V_128 ;
switch ( V_119 ) {
case V_120 :
V_6 -> V_85 ( V_6 ) ;
F_82 ( V_6 , V_119 ) ;
break;
case V_121 :
F_82 ( V_6 , V_119 ) ;
case V_122 :
V_6 -> V_84 ( V_6 ) ;
break;
default:
return V_127 ;
}
return V_128 ;
}
static int F_87 ( struct V_5 * V_104 )
{
V_104 -> V_126 . V_129 = F_85 ;
return F_88 ( & V_104 -> V_126 ) ;
}
static void F_89 ( struct V_5 * V_104 )
{
F_90 ( & V_104 -> V_126 ) ;
}
static inline int F_87 ( struct V_5 * V_104 ) { return 0 ; }
static inline void F_89 ( struct V_5 * V_104 ) { }
static int F_91 ( struct V_5 * V_104 )
{
int V_40 ;
int V_80 ;
struct V_33 T_7 * V_130 ;
V_130 = F_92 ( struct V_33 ) ;
if ( ! V_130 )
return - V_131 ;
V_40 = F_93 ( V_132 ,
& V_104 -> V_117 ) ;
if ( V_40 )
goto V_133;
V_40 = F_87 ( V_104 ) ;
if ( V_40 )
goto V_134;
F_94 (cpu) {
struct V_33 * V_37 = F_71 ( V_130 , V_80 ) ;
F_95 ( & V_37 -> V_135 ) ;
V_37 -> V_109 = V_104 ;
}
V_104 -> V_34 = V_130 ;
V_104 -> V_64 = F_72 ;
V_104 -> V_63 = F_63 ;
if ( V_104 -> V_118 )
F_68 ( & V_104 -> V_41 , V_104 -> V_118 ,
V_104 , 1 ) ;
if ( ! F_66 ( V_104 -> V_57 , 0 ) )
V_104 -> V_7 . V_136 |= V_137 ;
V_104 -> V_7 . V_136 |= V_138 ;
return 0 ;
V_134:
F_96 ( V_132 ,
& V_104 -> V_117 ) ;
V_133:
F_97 ( V_130 ) ;
return V_40 ;
}
static void F_98 ( struct V_5 * V_104 )
{
F_89 ( V_104 ) ;
F_96 ( V_132 ,
& V_104 -> V_117 ) ;
F_97 ( V_104 -> V_34 ) ;
}
static int F_99 ( struct V_5 * V_7 ,
const struct V_139 * V_140 )
{
int V_80 = F_100 () ;
unsigned int V_141 = F_101 () ;
int V_15 = - V_113 ;
F_102 ( L_8 , V_80 ) ;
for (; V_140 -> V_142 != NULL ; V_140 ++ ) {
if ( ( V_141 & V_140 -> V_143 ) != V_140 -> V_141 )
continue;
V_15 = V_140 -> V_142 ( V_7 ) ;
break;
}
F_103 () ;
return V_15 ;
}
static int F_104 ( struct V_5 * V_7 )
{
int * V_106 , V_105 = 0 ;
bool V_144 = false ;
struct V_56 * V_145 = V_7 -> V_57 ;
V_106 = F_105 ( V_145 -> V_108 , sizeof( * V_106 ) , V_146 ) ;
if ( ! V_106 )
return - V_131 ;
do {
struct V_147 * V_148 ;
int V_80 , V_54 ;
V_148 = F_106 ( V_145 -> V_55 . V_149 , L_9 , V_105 ) ;
if ( ! V_148 )
break;
V_54 = F_66 ( V_145 , V_105 ) ;
if ( V_54 > 0 ) {
bool V_150 = ! F_67 ( V_54 ) ;
if ( V_105 > 0 && V_150 != V_144 ) {
F_75 ( L_10 ,
V_148 -> V_100 ) ;
F_107 ( V_148 ) ;
F_108 ( V_106 ) ;
return - V_53 ;
}
V_144 = V_150 ;
}
F_94 (cpu) {
struct V_147 * V_151 ;
V_151 = F_109 ( V_80 ) ;
F_107 ( V_151 ) ;
if ( V_148 == V_151 )
break;
}
if ( V_80 >= V_152 ) {
F_78 ( L_11 ,
V_148 -> V_100 ) ;
F_107 ( V_148 ) ;
F_110 ( & V_7 -> V_41 ) ;
break;
}
F_107 ( V_148 ) ;
if ( V_144 ) {
if ( V_105 >= V_145 -> V_108 )
break;
V_106 [ V_105 ] = V_80 ;
}
F_79 ( V_80 , & V_7 -> V_41 ) ;
V_105 ++ ;
} while ( 1 );
if ( F_111 ( & V_7 -> V_41 ) == 0 ) {
int V_54 = F_66 ( V_145 , 0 ) ;
if ( V_54 > 0 && F_67 ( V_54 ) ) {
int V_15 ;
V_15 = F_112 ( V_54 , & V_7 -> V_41 ) ;
if ( V_15 ) {
F_108 ( V_106 ) ;
return V_15 ;
}
} else {
F_110 ( & V_7 -> V_41 ) ;
}
}
if ( V_144 && V_105 == V_145 -> V_108 )
V_7 -> V_110 = V_106 ;
else
F_108 ( V_106 ) ;
return 0 ;
}
int F_113 ( struct V_56 * V_145 ,
const struct V_153 * V_154 ,
const struct V_139 * V_155 )
{
const struct V_153 * V_156 ;
const int (* F_114)( struct V_5 * );
struct V_147 * V_117 = V_145 -> V_55 . V_149 ;
struct V_5 * V_7 ;
int V_15 = - V_113 ;
V_7 = F_115 ( sizeof( struct V_5 ) , V_146 ) ;
if ( ! V_7 ) {
F_102 ( L_12 ) ;
return - V_131 ;
}
F_54 ( V_7 ) ;
V_7 -> V_57 = V_145 ;
if ( V_117 && ( V_156 = F_116 ( V_154 , V_145 -> V_55 . V_149 ) ) ) {
F_114 = V_156 -> V_102 ;
V_7 -> V_157 = F_117 ( V_145 -> V_55 . V_149 ,
L_13 ) ;
if ( F_118 ( V_158 ) && V_7 -> V_157 ) {
F_78 ( L_14 ) ;
V_7 -> V_157 = false ;
}
V_15 = F_104 ( V_7 ) ;
if ( ! V_15 )
V_15 = F_114 ( V_7 ) ;
} else if ( V_155 ) {
F_110 ( & V_7 -> V_41 ) ;
V_15 = F_99 ( V_7 , V_155 ) ;
}
if ( V_15 ) {
F_102 ( L_15 , F_119 ( V_117 ) ) ;
goto V_133;
}
V_15 = F_91 ( V_7 ) ;
if ( V_15 )
goto V_133;
V_15 = F_120 ( & V_7 -> V_7 , V_7 -> V_100 , - 1 ) ;
if ( V_15 )
goto V_159;
if ( ! V_99 )
V_99 = V_7 ;
F_102 ( L_16 ,
V_7 -> V_100 , V_7 -> V_83 ) ;
return 0 ;
V_159:
F_98 ( V_7 ) ;
V_133:
F_102 ( L_17 ,
F_119 ( V_117 ) ) ;
F_108 ( V_7 -> V_110 ) ;
F_108 ( V_7 ) ;
return V_15 ;
}
static int F_121 ( void )
{
int V_15 ;
V_15 = F_122 ( V_132 ,
L_18 ,
F_80 , NULL ) ;
if ( V_15 )
F_75 ( L_19 ,
V_15 ) ;
return V_15 ;
}

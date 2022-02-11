static inline T_1 F_1 ( T_1 V_1 , T_2 V_2 , int V_3 )
{
return ( V_1 + ( V_3 ? ( 1 << V_2 ) - 1 : 0 ) ) >> V_2 ;
}
static inline T_1 F_2 ( T_2 V_4 )
{
T_1 V_5 = ( T_1 ) V_4 * V_6 / 1 ;
return V_5 ;
}
static inline T_1 F_3 ( T_2 V_4 )
{
return 1 ;
}
static inline int F_4 ( unsigned int V_7 )
{
return V_8 -
( ( V_8 - V_9 ) >>
( V_7 >> V_10 ) ) ;
}
static void F_5 ( struct V_11 * V_12 )
{
int V_13 = V_12 -> V_14 ;
T_1 V_15 = V_12 -> V_16 ;
int V_17 = F_6 ( & V_12 -> V_18 ) ;
int V_19 = F_6 ( & V_12 -> V_20 ) ;
int V_21 = F_6 ( & V_12 -> V_22 ) ;
F_7 ( V_12 -> V_23 , V_24 ,
V_15 ) ;
F_7 ( V_12 -> V_23 , V_25 ,
V_17 ) ;
F_7 ( V_12 -> V_23 , V_26 ,
V_19 ) ;
F_7 ( V_12 -> V_23 , V_27 ,
V_13 ) ;
F_7 ( V_12 -> V_23 , V_28 ,
V_21 ) ;
}
static void F_8 ( struct V_11 * V_12 )
{
struct V_29 * V_30 ;
V_30 = F_9 ( V_12 , struct V_31 ,
V_32 ) -> V_33 ;
F_10 ( & V_30 -> V_34 ) ;
V_12 -> V_16 = V_30 -> V_35 ;
F_11 ( & V_12 -> V_36 , V_30 -> V_37 ) ;
F_12 ( & V_30 -> V_34 ) ;
}
static int F_13 ( struct V_11 * V_12 )
{
T_3 V_38 ;
int V_39 ;
V_38 = F_14 () - V_12 -> V_40 ;
if ( V_38 < V_12 -> V_41 )
return 0 ;
F_15 ( & V_12 -> V_42 ) ;
V_38 = F_14 () - V_12 -> V_40 ;
if ( V_38 < V_12 -> V_41 ) {
F_16 ( & V_12 -> V_42 ) ;
return 0 ;
}
F_8 ( V_12 ) ;
F_16 ( & V_12 -> V_42 ) ;
if ( ! F_17 ( F_9 ( V_12 , struct V_31 ,
V_32 ) ) ) {
V_39 = 0 ;
goto V_43;
}
V_39 = F_18 ( F_9 ( V_12 , struct V_31 , V_32 ) ,
0 , V_44 , V_45 ) ;
V_43:
F_15 ( & V_12 -> V_42 ) ;
V_12 -> V_40 = F_14 () ;
F_7 ( V_12 -> V_23 , V_46 ,
V_38 ) ;
F_16 ( & V_12 -> V_42 ) ;
return V_39 ;
}
static int F_19 ( struct V_11 * V_12 ,
int V_47 , T_4 V_48 )
{
struct V_31 * V_49 ;
int V_50 ;
V_49 = F_9 ( V_12 , struct V_31 , V_32 ) ;
if ( ! F_17 ( V_49 ) )
return 0 ;
F_8 ( V_12 ) ;
F_15 ( & V_49 -> V_51 ) ;
V_50 = V_49 -> V_52 ;
F_16 ( & V_49 -> V_51 ) ;
if ( V_47 == 0 )
return ( V_50 / 100 ) * V_53 ;
else
return F_18 ( V_49 , V_47 , V_44 , V_54 ) ;
}
static int F_20 ( struct V_11 * V_12 )
{
T_5 V_38 ;
int V_55 ;
V_38 = F_14 () - V_12 -> V_40 ;
if ( V_38 > 0 ) {
F_15 ( & V_12 -> V_42 ) ;
V_38 = F_14 () - V_12 -> V_40 ;
if ( V_38 > 0 ) {
F_5 ( V_12 ) ;
F_11 ( & V_12 -> V_20 , 0 ) ;
F_11 ( & V_12 -> V_22 , 0 ) ;
}
F_16 ( & V_12 -> V_42 ) ;
}
if ( V_12 -> V_56 -> V_57 ) {
V_55 = V_12 -> V_56 -> V_57 ( V_12 ) ;
F_7 ( V_12 -> V_23 , V_58 ,
V_55 ) ;
}
V_38 = V_12 -> V_40 - F_14 () +
V_12 -> V_41 ;
if ( V_38 <= 0 ) {
F_21 ( V_59 , L_1 ,
V_12 -> V_60 , ( long ) V_38 ,
( long ) V_12 -> V_41 ) ;
V_38 = 1 ;
}
return V_38 ;
}
static int F_22 ( struct V_11 * V_12 , int V_47 , T_4 V_48 )
{
int V_61 = 0 ;
if ( V_12 -> V_56 -> V_62 ) {
V_61 = V_12 -> V_56 -> V_62 ( V_12 , V_47 , V_48 ) ;
if ( V_47 > 0 ) {
F_7 ( V_12 -> V_23 ,
V_63 ,
V_47 ) ;
F_7 ( V_12 -> V_23 ,
V_64 ,
V_61 ) ;
F_21 ( V_59 , L_2 ,
V_12 -> V_60 , V_47 , V_61 ) ;
}
}
return V_61 ;
}
static int F_23 ( struct V_65 * V_66 , void * V_50 )
{
int V_17 , V_19 , V_21 ;
int V_67 , V_68 ;
struct V_11 * V_12 = V_66 -> V_69 ;
T_1 V_15 , V_70 ;
T_2 V_71 ;
F_15 ( & V_12 -> V_42 ) ;
V_15 = V_12 -> V_16 ;
V_70 = V_12 -> V_72 ;
V_71 = F_6 ( & V_12 -> V_36 ) ;
V_17 = F_6 ( & V_12 -> V_18 ) ;
V_19 = F_6 ( & V_12 -> V_20 ) ;
V_21 = F_6 ( & V_12 -> V_22 ) ;
V_67 = V_19 - V_21 ;
V_68 = F_6 ( & V_12 -> V_73 ) ;
F_16 ( & V_12 -> V_42 ) ;
F_24 ( V_66 , L_3
L_4
L_5
L_6 ,
V_12 -> V_60 , V_15 , V_70 , V_68 ) ;
F_24 ( V_66 , L_7
L_8 ,
V_19 , V_21 , V_67 ,
V_17 , V_71 ) ;
return 0 ;
}
static T_6 F_25 ( struct V_74 * V_75 , struct V_76 * V_77 ,
char * V_78 )
{
struct V_11 * V_12 = F_9 ( V_75 , struct V_11 ,
V_79 ) ;
int V_67 ;
F_15 ( & V_12 -> V_42 ) ;
V_67 = F_6 ( & V_12 -> V_20 ) -
F_6 ( & V_12 -> V_22 ) ;
F_16 ( & V_12 -> V_42 ) ;
return sprintf ( V_78 , L_9 , V_67 ) ;
}
static void F_26 ( struct V_74 * V_75 )
{
struct V_11 * V_12 = F_9 ( V_75 , struct V_11 ,
V_79 ) ;
F_27 ( & V_12 -> V_80 ) ;
}
static int F_28 ( struct V_11 * V_12 )
{
struct V_31 * V_49 = F_9 ( V_12 , struct V_31 ,
V_32 ) ;
int V_81 ;
F_29 ( & V_12 -> V_80 ) ;
V_81 = F_30 ( & V_12 -> V_79 , & V_82 , & V_49 -> V_83 ,
L_10 ) ;
return V_81 ;
}
static int F_31 ( struct V_11 * V_12 )
{
struct V_31 * V_49 = F_9 ( V_12 , struct V_31 ,
V_32 ) ;
struct V_84 * V_85 ;
struct V_86 V_87 [ 2 ] ;
char * V_88 = NULL ;
int V_89 = 0 ;
V_88 = F_32 ( V_90 + 1 , V_91 ) ;
if ( ! V_88 )
return - V_92 ;
V_85 = V_49 -> V_93 ;
if ( F_33 ( V_85 ) ) {
F_34 ( L_11 ,
F_35 ( V_49 ) ) ;
V_89 = - V_94 ;
goto V_95;
}
V_12 -> V_96 = F_36 ( L_10 , V_85 ,
NULL , NULL ) ;
if ( F_37 ( V_12 -> V_96 ) ) {
F_34 ( L_12 ) ;
V_89 = F_38 ( V_12 -> V_96 ) ;
V_12 -> V_96 = NULL ;
goto V_95;
}
V_88 [ V_90 ] = '\0' ;
memset ( V_87 , 0 , sizeof( V_87 ) ) ;
V_87 [ 0 ] . V_97 = V_88 ;
F_39 ( V_98 , V_12 , & V_99 ) ;
V_12 -> V_23 = F_40 ( V_100 -
V_101 , 0 ) ;
if ( ! V_12 -> V_23 ) {
V_89 = - V_92 ;
goto V_95;
}
F_41 ( V_12 -> V_23 , V_25 ,
V_102 | V_103 ,
L_13 , L_14 ) ;
F_41 ( V_12 -> V_23 , V_104 ,
V_102 | V_103 ,
L_15 , L_14 ) ;
F_41 ( V_12 -> V_23 , V_105 ,
V_102 | V_103 ,
L_16 , L_14 ) ;
F_41 ( V_12 -> V_23 , V_26 ,
V_102 | V_103 ,
L_17 , L_18 ) ;
F_41 ( V_12 -> V_23 , V_28 ,
V_102 | V_103 ,
L_19 , L_18 ) ;
F_41 ( V_12 -> V_23 , V_27 ,
V_102 | V_103 ,
L_20 , L_18 ) ;
F_41 ( V_12 -> V_23 , V_24 ,
V_102 | V_103 ,
L_21 , L_21 ) ;
F_41 ( V_12 -> V_23 , V_63 ,
V_102 | V_103 ,
L_22 , L_14 ) ;
F_41 ( V_12 -> V_23 , V_64 ,
V_102 | V_103 ,
L_23 , L_14 ) ;
F_41 ( V_12 -> V_23 , V_58 ,
V_102 | V_103 ,
L_24 , L_14 ) ;
F_41 ( V_12 -> V_23 , V_46 ,
V_102 | V_103 ,
L_25 , L_26 ) ;
V_89 = F_42 ( V_12 -> V_96 , L_27 ,
V_12 -> V_23 ) ;
V_95:
F_43 ( V_88 ) ;
return V_89 ;
}
static void F_44 ( struct V_11 * V_12 )
{
F_45 ( & V_12 -> V_79 ) ;
F_46 ( & V_12 -> V_80 ) ;
}
static void F_47 ( struct V_11 * V_12 )
{
if ( V_12 -> V_23 ) {
F_48 ( & V_12 -> V_23 ) ;
V_12 -> V_23 = NULL ;
}
if ( V_12 -> V_96 ) {
F_49 ( & V_12 -> V_96 ) ;
V_12 -> V_96 = NULL ;
}
}
int F_50 ( struct V_11 * V_12 , struct V_31 * V_49 ,
int V_106 , enum V_107 V_108 )
{
int V_89 ;
F_51 ( & V_12 -> V_42 ) ;
F_11 ( & V_12 -> V_18 , 0 ) ;
V_12 -> V_40 = F_14 () ;
F_11 ( & V_12 -> V_73 , 1 ) ;
F_11 ( & V_12 -> V_20 , 0 ) ;
F_11 ( & V_12 -> V_22 , 0 ) ;
V_12 -> V_14 = F_52 ( V_109 ) ;
snprintf ( V_12 -> V_60 , sizeof( V_12 -> V_60 ) , L_28 ,
F_35 ( V_49 ) , V_106 ) ;
F_11 ( & V_12 -> V_36 , 1 ) ;
V_12 -> V_16 = 0 ;
V_12 -> V_56 = & V_110 ;
V_12 -> V_41 = V_111 ;
V_12 -> V_72 = 0 ;
V_89 = F_31 ( V_12 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_28 ( V_12 ) ;
if ( V_89 )
return V_89 ;
F_21 ( V_59 , L_29 , V_12 -> V_60 ) ;
return V_89 ;
}
void F_53 ( struct V_11 * V_12 )
{
F_44 ( V_12 ) ;
F_47 ( V_12 ) ;
F_54 ( V_12 , 0x5a , sizeof( * V_12 ) ) ;
}
void F_55 ( struct V_11 * V_12 , struct V_112 * V_113 )
{
if ( V_113 -> V_114 -> V_115 == V_116 )
return;
F_56 ( & V_12 -> V_18 ) ;
F_56 ( & V_12 -> V_20 ) ;
F_57 ( V_12 -> V_23 , V_104 ) ;
}
void F_58 ( struct V_11 * V_12 , struct V_112 * V_113 )
{
if ( V_113 -> V_114 -> V_115 == V_116 )
return;
F_59 ( F_6 ( & V_12 -> V_18 ) > 0 ) ;
F_60 ( & V_12 -> V_18 ) ;
F_56 ( & V_12 -> V_22 ) ;
F_57 ( V_12 -> V_23 , V_105 ) ;
}
T_1 F_61 ( struct V_11 * V_12 )
{
T_1 V_15 ;
F_15 ( & V_12 -> V_42 ) ;
V_15 = V_12 -> V_16 ;
F_16 ( & V_12 -> V_42 ) ;
return V_15 ;
}
void F_62 ( struct V_11 * V_12 , T_1 V_70 )
{
F_15 ( & V_12 -> V_42 ) ;
V_12 -> V_72 = V_70 ;
F_16 ( & V_12 -> V_42 ) ;
}
T_2 F_63 ( struct V_11 * V_12 )
{
return F_6 ( & V_12 -> V_73 ) ;
}
static int F_64 ( struct V_11 * V_12 )
{
return F_6 ( & V_12 -> V_18 ) ;
}
static unsigned long F_65 ( enum V_107 V_108 , T_4 V_48 )
{
unsigned long V_117 = 0 ;
int V_118 ;
struct V_31 * V_49 ;
struct V_31 * V_119 = NULL ;
if ( V_108 == V_120 && ! ( V_48 & V_121 ) )
return 0 ;
F_21 ( V_59 , L_30 ,
V_108 == V_120 ? L_31 : L_32 ) ;
for ( V_118 = F_66 ( V_108 ) ;
V_118 > 0 ; V_118 -- ) {
F_67 ( F_68 ( V_108 ) ) ;
if ( F_69 ( F_70 ( V_108 ) ) ) {
F_71 ( F_68 ( V_108 ) ) ;
return 0 ;
}
V_49 = F_72 ( V_108 ) ;
if ( V_49 == V_119 ) {
F_71 ( F_68 ( V_108 ) ) ;
break;
}
if ( F_73 ( V_49 ) ) {
F_74 ( V_49 , V_108 ) ;
F_71 ( F_68 ( V_108 ) ) ;
continue;
}
if ( ! V_119 )
V_119 = V_49 ;
F_75 ( V_49 ) ;
F_76 ( V_49 , V_108 ) ;
F_71 ( F_68 ( V_108 ) ) ;
V_117 += F_22 ( & V_49 -> V_32 , 0 , V_48 ) ;
F_77 ( V_49 ) ;
}
return V_117 ;
}
static unsigned long F_78 ( enum V_107 V_108 , int V_47 ,
T_4 V_48 )
{
unsigned long V_122 = 0 ;
int V_123 , V_118 ;
struct V_31 * V_49 ;
if ( V_108 == V_120 && ! ( V_48 & V_121 ) )
return - 1 ;
for ( V_123 = V_118 = F_66 ( V_108 ) ;
V_123 > 0 ; V_123 -- ) {
int V_61 , V_124 ;
F_67 ( F_68 ( V_108 ) ) ;
if ( F_69 ( F_70 ( V_108 ) ) ) {
F_71 ( F_68 ( V_108 ) ) ;
break;
}
V_49 = F_72 ( V_108 ) ;
F_75 ( V_49 ) ;
F_76 ( V_49 , V_108 ) ;
F_71 ( F_68 ( V_108 ) ) ;
V_124 = F_64 ( & V_49 -> V_32 ) ;
V_61 = 1 + F_79 ( int , V_124 , V_47 / V_118 ) ;
V_122 += F_22 ( & V_49 -> V_32 , V_61 , V_48 ) ;
F_77 ( V_49 ) ;
}
return V_122 ;
}
static unsigned long F_80 ( struct V_125 * V_126 ,
struct V_127 * V_128 )
{
return F_65 ( V_120 , V_128 -> V_48 ) ;
}
static unsigned long F_81 ( struct V_125 * V_126 ,
struct V_127 * V_128 )
{
return F_78 ( V_120 , V_128 -> V_129 ,
V_128 -> V_48 ) ;
}
static int F_82 ( enum V_107 V_108 )
{
struct V_31 * V_49 ;
struct V_31 * V_119 = NULL ;
int time = V_111 ;
int V_47 ;
for ( V_47 = F_66 ( V_108 ) ; V_47 > 0 ; V_47 -- ) {
int V_130 ;
F_67 ( F_68 ( V_108 ) ) ;
if ( F_69 ( F_70 ( V_108 ) ) ) {
F_71 ( F_68 ( V_108 ) ) ;
break;
}
V_49 = F_72 ( V_108 ) ;
if ( V_119 == V_49 ) {
F_71 ( F_68 ( V_108 ) ) ;
break;
}
if ( F_73 ( V_49 ) ) {
F_74 ( V_49 , V_108 ) ;
F_71 ( F_68 ( V_108 ) ) ;
continue;
}
if ( ! V_119 )
V_119 = V_49 ;
F_15 ( & V_49 -> V_51 ) ;
if ( V_49 -> V_131 ) {
V_130 = 1 ;
} else {
V_130 = 0 ;
F_75 ( V_49 ) ;
}
F_16 ( & V_49 -> V_51 ) ;
F_76 ( V_49 , V_108 ) ;
F_71 ( F_68 ( V_108 ) ) ;
if ( ! V_130 ) {
int V_132 = F_20 ( & V_49 -> V_32 ) ;
if ( V_132 < time )
time = V_132 ;
F_77 ( V_49 ) ;
}
}
F_83 () ;
return time ;
}
static int F_84 ( void * V_133 )
{
struct V_134 * V_135 = (struct V_134 * ) V_133 ;
int V_136 ;
F_85 ( V_135 , V_137 ) ;
F_86 ( & V_135 -> V_138 ) ;
F_21 ( V_59 , L_33 ,
L_34 , F_87 () ) ;
while ( 1 ) {
struct V_139 V_140 ;
V_136 = F_82 ( V_120 ) ;
V_140 = F_88 ( F_89 ( V_136 ) ,
NULL , NULL ) ;
F_90 ( V_135 -> V_138 ,
F_91 ( V_135 ) ||
F_92 ( V_135 ) ,
& V_140 ) ;
if ( F_93 ( V_135 , V_141 ) )
break;
F_93 ( V_135 , V_142 ) ;
}
F_85 ( V_135 , V_143 ) ;
F_86 ( & V_135 -> V_138 ) ;
F_21 ( V_59 , L_35 ,
L_34 , F_87 () ) ;
F_94 ( & V_144 , 0 ) ;
}
static int F_95 ( void )
{
struct V_139 V_140 = { 0 } ;
struct V_145 * V_146 ;
if ( V_147 )
return - V_148 ;
V_147 = F_32 ( sizeof( * V_147 ) , V_91 ) ;
if ( ! V_147 )
return - V_92 ;
F_29 ( & V_144 ) ;
F_96 ( & V_147 -> V_138 ) ;
V_146 = F_97 ( F_84 , V_147 ,
L_34 ) ;
if ( F_37 ( V_146 ) ) {
F_34 ( L_36 , F_38 ( V_146 ) ) ;
F_43 ( V_147 ) ;
V_147 = NULL ;
return F_38 ( V_146 ) ;
}
F_90 ( V_147 -> V_138 ,
F_98 ( V_147 ) , & V_140 ) ;
return 0 ;
}
static void F_99 ( void )
{
if ( ! V_147 )
return;
F_85 ( V_147 , V_141 ) ;
F_86 ( & V_147 -> V_138 ) ;
F_46 ( & V_144 ) ;
F_43 ( V_147 ) ;
V_147 = NULL ;
}
int F_100 ( void )
{
int V_89 ;
V_89 = F_95 () ;
if ( V_89 == 0 )
F_101 ( & V_149 ) ;
return V_89 ;
}
void F_102 ( void )
{
if ( V_147 )
F_103 ( & V_149 ) ;
F_99 () ;
}

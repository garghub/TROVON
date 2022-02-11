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
V_38 = F_21 () - V_12 -> V_40 ;
if ( V_38 <= 0 )
goto V_56;
F_15 ( & V_12 -> V_42 ) ;
if ( V_38 > 0 ) {
F_5 ( V_12 ) ;
F_11 ( & V_12 -> V_20 , 0 ) ;
F_11 ( & V_12 -> V_22 , 0 ) ;
}
F_16 ( & V_12 -> V_42 ) ;
V_56:
if ( V_12 -> V_57 -> V_58 ) {
V_55 = V_12 -> V_57 -> V_58 ( V_12 ) ;
F_7 ( V_12 -> V_23 , V_59 ,
V_55 ) ;
}
V_38 = V_12 -> V_40 - F_21 () +
V_12 -> V_41 ;
if ( V_38 <= 0 ) {
F_22 ( V_60 ,
L_1 ,
V_38 ,
( V_61 ) V_12 -> V_41 ) ;
V_38 = 1 ;
}
return V_38 ;
}
static int F_23 ( struct V_11 * V_12 , int V_47 , T_4 V_48 )
{
int V_62 = 0 ;
if ( V_12 -> V_57 -> V_63 ) {
V_62 = V_12 -> V_57 -> V_63 ( V_12 , V_47 , V_48 ) ;
if ( V_47 > 0 ) {
F_7 ( V_12 -> V_23 ,
V_64 ,
V_47 ) ;
F_7 ( V_12 -> V_23 ,
V_65 ,
V_62 ) ;
F_22 ( V_60 , L_2 ,
V_12 -> V_66 , V_47 , V_62 ) ;
}
}
return V_62 ;
}
static int F_24 ( struct V_67 * V_68 , void * V_50 )
{
int V_17 , V_19 , V_21 ;
int V_69 , V_70 ;
struct V_11 * V_12 = V_68 -> V_71 ;
T_1 V_15 , V_72 ;
T_2 V_73 ;
F_15 ( & V_12 -> V_42 ) ;
V_15 = V_12 -> V_16 ;
V_72 = V_12 -> V_74 ;
V_73 = F_6 ( & V_12 -> V_36 ) ;
V_17 = F_6 ( & V_12 -> V_18 ) ;
V_19 = F_6 ( & V_12 -> V_20 ) ;
V_21 = F_6 ( & V_12 -> V_22 ) ;
V_69 = V_19 - V_21 ;
V_70 = F_6 ( & V_12 -> V_75 ) ;
F_16 ( & V_12 -> V_42 ) ;
F_25 ( V_68 , L_3
L_4
L_5
L_6 ,
V_12 -> V_66 , V_15 , V_72 , V_70 ) ;
F_25 ( V_68 , L_7
L_8 ,
V_19 , V_21 , V_69 ,
V_17 , V_73 ) ;
return 0 ;
}
static T_6 F_26 ( struct V_76 * V_77 , struct V_78 * V_79 ,
char * V_80 )
{
struct V_11 * V_12 = F_9 ( V_77 , struct V_11 ,
V_81 ) ;
int V_69 ;
F_15 ( & V_12 -> V_42 ) ;
V_69 = F_6 ( & V_12 -> V_20 ) -
F_6 ( & V_12 -> V_22 ) ;
F_16 ( & V_12 -> V_42 ) ;
return sprintf ( V_80 , L_9 , V_69 ) ;
}
static void F_27 ( struct V_76 * V_77 )
{
struct V_11 * V_12 = F_9 ( V_77 , struct V_11 ,
V_81 ) ;
F_28 ( & V_12 -> V_82 ) ;
}
static int F_29 ( struct V_11 * V_12 )
{
struct V_31 * V_49 = F_9 ( V_12 , struct V_31 ,
V_32 ) ;
int V_83 ;
F_30 ( & V_12 -> V_82 ) ;
V_83 = F_31 ( & V_12 -> V_81 , & V_84 , & V_49 -> V_85 ,
L_10 ) ;
return V_83 ;
}
static int F_32 ( struct V_11 * V_12 )
{
struct V_31 * V_49 = F_9 ( V_12 , struct V_31 ,
V_32 ) ;
struct V_86 * V_87 ;
struct V_88 V_89 [ 2 ] ;
char * V_90 = NULL ;
int V_91 = 0 ;
V_90 = F_33 ( V_92 + 1 , V_93 ) ;
if ( ! V_90 )
return - V_94 ;
V_87 = V_49 -> V_95 ;
if ( F_34 ( V_87 ) ) {
F_35 ( L_11 ,
F_36 ( V_49 ) ) ;
V_91 = - V_96 ;
goto V_97;
}
V_12 -> V_98 = F_37 ( L_10 , V_87 ,
NULL , NULL ) ;
if ( F_38 ( V_12 -> V_98 ) ) {
F_35 ( L_12 ) ;
V_91 = F_39 ( V_12 -> V_98 ) ;
V_12 -> V_98 = NULL ;
goto V_97;
}
V_90 [ V_92 ] = '\0' ;
memset ( V_89 , 0 , sizeof( V_89 ) ) ;
V_89 [ 0 ] . V_99 = V_90 ;
F_40 ( V_100 , V_12 , & V_101 ) ;
V_12 -> V_23 = F_41 ( V_102 -
V_103 , 0 ) ;
if ( ! V_12 -> V_23 ) {
V_91 = - V_94 ;
goto V_97;
}
F_42 ( V_12 -> V_23 , V_25 ,
V_104 | V_105 ,
L_13 , L_14 ) ;
F_42 ( V_12 -> V_23 , V_106 ,
V_104 | V_105 ,
L_15 , L_14 ) ;
F_42 ( V_12 -> V_23 , V_107 ,
V_104 | V_105 ,
L_16 , L_14 ) ;
F_42 ( V_12 -> V_23 , V_26 ,
V_104 | V_105 ,
L_17 , L_18 ) ;
F_42 ( V_12 -> V_23 , V_28 ,
V_104 | V_105 ,
L_19 , L_18 ) ;
F_42 ( V_12 -> V_23 , V_27 ,
V_104 | V_105 ,
L_20 , L_18 ) ;
F_42 ( V_12 -> V_23 , V_24 ,
V_104 | V_105 ,
L_21 , L_21 ) ;
F_42 ( V_12 -> V_23 , V_64 ,
V_104 | V_105 ,
L_22 , L_14 ) ;
F_42 ( V_12 -> V_23 , V_65 ,
V_104 | V_105 ,
L_23 , L_14 ) ;
F_42 ( V_12 -> V_23 , V_59 ,
V_104 | V_105 ,
L_24 , L_14 ) ;
F_42 ( V_12 -> V_23 , V_46 ,
V_104 | V_105 ,
L_25 , L_26 ) ;
V_91 = F_43 ( V_12 -> V_98 , L_27 ,
V_12 -> V_23 ) ;
V_97:
F_44 ( V_90 ) ;
return V_91 ;
}
static void F_45 ( struct V_11 * V_12 )
{
F_46 ( & V_12 -> V_81 ) ;
F_47 ( & V_12 -> V_82 ) ;
}
static void F_48 ( struct V_11 * V_12 )
{
if ( V_12 -> V_23 ) {
F_49 ( & V_12 -> V_23 ) ;
V_12 -> V_23 = NULL ;
}
if ( V_12 -> V_98 ) {
F_50 ( & V_12 -> V_98 ) ;
V_12 -> V_98 = NULL ;
}
}
int F_51 ( struct V_11 * V_12 , struct V_31 * V_49 ,
int V_108 , T_7 V_109 )
{
int V_91 ;
F_52 ( & V_12 -> V_42 ) ;
F_11 ( & V_12 -> V_18 , 0 ) ;
V_12 -> V_40 = F_21 () ;
F_11 ( & V_12 -> V_75 , 1 ) ;
F_11 ( & V_12 -> V_20 , 0 ) ;
F_11 ( & V_12 -> V_22 , 0 ) ;
V_12 -> V_14 = F_53 ( V_110 ) ;
snprintf ( V_12 -> V_66 , sizeof( V_12 -> V_66 ) , L_28 ,
F_36 ( V_49 ) , V_108 ) ;
F_11 ( & V_12 -> V_36 , 1 ) ;
V_12 -> V_16 = 0 ;
V_12 -> V_57 = & V_111 ;
V_12 -> V_41 = V_112 ;
V_12 -> V_74 = 0 ;
V_91 = F_32 ( V_12 ) ;
if ( V_91 )
return V_91 ;
V_91 = F_29 ( V_12 ) ;
if ( V_91 )
return V_91 ;
F_22 ( V_60 , L_29 , V_12 -> V_66 ) ;
return V_91 ;
}
void F_54 ( struct V_11 * V_12 )
{
F_45 ( V_12 ) ;
F_48 ( V_12 ) ;
F_55 ( V_12 , 0x5a , sizeof( * V_12 ) ) ;
}
void F_56 ( struct V_11 * V_12 , struct V_113 * V_114 )
{
if ( V_114 -> V_115 -> V_116 == V_117 )
return;
F_57 ( & V_12 -> V_18 ) ;
F_57 ( & V_12 -> V_20 ) ;
F_58 ( V_12 -> V_23 , V_106 ) ;
}
void F_59 ( struct V_11 * V_12 , struct V_113 * V_114 )
{
if ( V_114 -> V_115 -> V_116 == V_117 )
return;
F_60 ( F_6 ( & V_12 -> V_18 ) > 0 ) ;
F_61 ( & V_12 -> V_18 ) ;
F_57 ( & V_12 -> V_22 ) ;
F_58 ( V_12 -> V_23 , V_107 ) ;
}
T_1 F_62 ( struct V_11 * V_12 )
{
T_1 V_15 ;
F_15 ( & V_12 -> V_42 ) ;
V_15 = V_12 -> V_16 ;
F_16 ( & V_12 -> V_42 ) ;
return V_15 ;
}
void F_63 ( struct V_11 * V_12 , T_1 V_72 )
{
F_15 ( & V_12 -> V_42 ) ;
V_12 -> V_74 = V_72 ;
F_16 ( & V_12 -> V_42 ) ;
}
T_2 F_64 ( struct V_11 * V_12 )
{
return F_6 ( & V_12 -> V_75 ) ;
}
static int F_65 ( struct V_11 * V_12 )
{
return F_6 ( & V_12 -> V_18 ) ;
}
static unsigned long F_66 ( T_7 V_109 , T_4 V_48 )
{
int V_118 = 0 , V_119 ;
struct V_31 * V_49 ;
struct V_31 * V_120 = NULL ;
void * V_121 ;
if ( V_109 == V_122 && ! ( V_48 & V_123 ) )
return 0 ;
F_22 ( V_60 , L_30 ,
V_109 == V_122 ? L_31 : L_32 ) ;
V_121 = F_67 () ;
for ( V_119 = F_68 ( V_109 ) ;
V_119 > 0 ; V_119 -- ) {
F_69 ( F_70 ( V_109 ) ) ;
if ( F_71 ( F_72 ( V_109 ) ) ) {
F_73 ( F_70 ( V_109 ) ) ;
F_74 ( V_121 ) ;
return 0 ;
}
V_49 = F_75 ( V_109 ) ;
if ( V_49 == V_120 ) {
F_73 ( F_70 ( V_109 ) ) ;
break;
}
if ( F_76 ( V_49 ) ) {
F_77 ( V_49 , V_109 ) ;
F_73 ( F_70 ( V_109 ) ) ;
continue;
}
if ( ! V_120 )
V_120 = V_49 ;
F_78 ( V_49 ) ;
F_79 ( V_49 , V_109 ) ;
F_73 ( F_70 ( V_109 ) ) ;
V_118 += F_23 ( & V_49 -> V_32 , 0 , V_48 ) ;
F_80 ( V_49 ) ;
}
F_74 ( V_121 ) ;
return V_118 ;
}
static unsigned long F_81 ( T_7 V_109 , int V_47 , T_4 V_48 )
{
unsigned long V_124 = 0 ;
int V_125 , V_119 ;
struct V_31 * V_49 ;
void * V_121 ;
if ( V_109 == V_122 && ! ( V_48 & V_123 ) )
return - 1 ;
V_121 = F_67 () ;
for ( V_125 = V_119 = F_68 ( V_109 ) ;
V_125 > 0 ; V_125 -- ) {
int V_62 , V_126 ;
F_69 ( F_70 ( V_109 ) ) ;
if ( F_71 ( F_72 ( V_109 ) ) ) {
F_73 ( F_70 ( V_109 ) ) ;
break;
}
V_49 = F_75 ( V_109 ) ;
F_78 ( V_49 ) ;
F_79 ( V_49 , V_109 ) ;
F_73 ( F_70 ( V_109 ) ) ;
V_126 = F_65 ( & V_49 -> V_32 ) ;
V_62 = 1 + F_82 ( int , V_126 , V_47 / V_119 ) ;
V_124 += F_23 ( & V_49 -> V_32 , V_62 , V_48 ) ;
F_80 ( V_49 ) ;
}
F_74 ( V_121 ) ;
return V_124 ;
}
static unsigned long F_83 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
return F_66 ( V_122 , V_130 -> V_48 ) ;
}
static unsigned long F_84 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
return F_81 ( V_122 , V_130 -> V_131 ,
V_130 -> V_48 ) ;
}
static int F_85 ( T_7 V_109 )
{
struct V_31 * V_49 ;
struct V_31 * V_120 = NULL ;
int V_47 ;
int time = 50 ;
for ( V_47 = F_68 ( V_109 ) ; V_47 > 0 ; V_47 -- ) {
int V_132 ;
F_69 ( F_70 ( V_109 ) ) ;
if ( F_71 ( F_72 ( V_109 ) ) ) {
F_73 ( F_70 ( V_109 ) ) ;
break;
}
V_49 = F_75 ( V_109 ) ;
if ( V_120 == V_49 ) {
F_73 ( F_70 ( V_109 ) ) ;
break;
}
if ( F_76 ( V_49 ) ) {
F_77 ( V_49 , V_109 ) ;
F_73 ( F_70 ( V_109 ) ) ;
continue;
}
if ( ! V_120 )
V_120 = V_49 ;
F_15 ( & V_49 -> V_51 ) ;
if ( V_49 -> V_133 ) {
V_132 = 1 ;
} else {
V_132 = 0 ;
F_78 ( V_49 ) ;
}
F_16 ( & V_49 -> V_51 ) ;
F_79 ( V_49 , V_109 ) ;
F_73 ( F_70 ( V_109 ) ) ;
if ( ! V_132 ) {
int V_134 = F_20 ( & V_49 -> V_32 ) ;
if ( V_134 < time )
time = V_134 ;
F_80 ( V_49 ) ;
}
}
return time ;
}
static int F_86 ( void * V_135 )
{
struct V_136 * V_137 = (struct V_136 * ) V_135 ;
int V_138 ;
F_87 ( V_137 , V_139 ) ;
F_88 ( & V_137 -> V_140 ) ;
F_22 ( V_60 , L_33 ,
L_34 , F_89 () ) ;
while ( 1 ) {
struct V_141 V_142 ;
V_138 = F_85 ( V_122 ) ;
V_142 = F_90 ( F_91 ( V_138 ) ,
NULL , NULL ) ;
F_92 ( V_137 -> V_140 ,
F_93 ( V_137 ) ||
F_94 ( V_137 ) ,
& V_142 ) ;
if ( F_95 ( V_137 , V_143 ) )
break;
F_95 ( V_137 , V_144 ) ;
}
F_87 ( V_137 , V_145 ) ;
F_88 ( & V_137 -> V_140 ) ;
F_22 ( V_60 , L_35 ,
L_34 , F_89 () ) ;
F_96 ( & V_146 , 0 ) ;
}
static int F_97 ( void )
{
struct V_141 V_142 = { 0 } ;
struct V_147 * V_148 ;
if ( V_149 )
return - V_150 ;
V_149 = F_33 ( sizeof( * V_149 ) , V_93 ) ;
if ( ! V_149 )
return - V_94 ;
F_30 ( & V_146 ) ;
F_98 ( & V_149 -> V_140 ) ;
V_148 = F_99 ( F_86 , V_149 ,
L_34 ) ;
if ( F_38 ( V_148 ) ) {
F_35 ( L_36 , F_39 ( V_148 ) ) ;
F_44 ( V_149 ) ;
V_149 = NULL ;
return F_39 ( V_148 ) ;
}
F_92 ( V_149 -> V_140 ,
F_100 ( V_149 ) , & V_142 ) ;
return 0 ;
}
static void F_101 ( void )
{
if ( ! V_149 )
return;
F_87 ( V_149 , V_143 ) ;
F_88 ( & V_149 -> V_140 ) ;
F_47 ( & V_146 ) ;
F_44 ( V_149 ) ;
V_149 = NULL ;
}
int F_102 ( void )
{
int V_91 ;
V_91 = F_97 () ;
if ( V_91 == 0 )
F_103 ( & V_151 ) ;
return V_91 ;
}
void F_104 ( void )
{
if ( V_149 )
F_105 ( & V_151 ) ;
F_101 () ;
}

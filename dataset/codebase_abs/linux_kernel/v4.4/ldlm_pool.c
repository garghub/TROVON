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
static inline struct V_7 * F_4 ( struct V_8 * V_9 )
{
return F_5 ( V_9 , struct V_7 , V_10 ) ;
}
static inline int F_6 ( unsigned int V_11 )
{
return V_12 -
( ( V_12 - V_13 ) >>
( V_11 >> V_14 ) ) ;
}
static T_2 F_7 ( struct V_8 * V_9 )
{
return F_8 ( & V_9 -> V_15 ) ;
}
static void F_9 ( struct V_8 * V_9 , T_2 V_16 )
{
F_10 ( & V_9 -> V_15 , V_16 ) ;
}
static void F_11 ( struct V_8 * V_9 )
{
int V_17 = V_9 -> V_18 ;
T_1 V_19 = V_9 -> V_20 ;
int V_21 = F_8 ( & V_9 -> V_22 ) ;
int V_23 = F_8 ( & V_9 -> V_24 ) ;
int V_25 = F_8 ( & V_9 -> V_26 ) ;
F_12 ( V_9 -> V_27 , V_28 ,
V_19 ) ;
F_12 ( V_9 -> V_27 , V_29 ,
V_21 ) ;
F_12 ( V_9 -> V_27 , V_30 ,
V_23 ) ;
F_12 ( V_9 -> V_27 , V_31 ,
V_17 ) ;
F_12 ( V_9 -> V_27 , V_32 ,
V_25 ) ;
}
static void F_13 ( struct V_8 * V_9 )
{
struct V_33 * V_34 ;
V_34 = F_4 ( V_9 ) -> V_35 ;
F_14 ( V_34 != NULL ) ;
F_15 ( & V_34 -> V_36 ) ;
V_9 -> V_20 = V_34 -> V_37 ;
F_9 ( V_9 , V_34 -> V_38 ) ;
F_16 ( & V_34 -> V_36 ) ;
}
static int F_17 ( struct V_8 * V_9 )
{
T_3 V_39 ;
int V_40 ;
V_39 = F_18 () - V_9 -> V_41 ;
if ( V_39 < V_9 -> V_42 )
return 0 ;
F_19 ( & V_9 -> V_43 ) ;
V_39 = F_18 () - V_9 -> V_41 ;
if ( V_39 < V_9 -> V_42 ) {
F_20 ( & V_9 -> V_43 ) ;
return 0 ;
}
F_13 ( V_9 ) ;
F_20 ( & V_9 -> V_43 ) ;
if ( ! F_21 ( F_4 ( V_9 ) ) ) {
V_40 = 0 ;
goto V_44;
}
V_40 = F_22 ( F_4 ( V_9 ) , 0 , V_45 , V_46 ) ;
V_44:
F_19 ( & V_9 -> V_43 ) ;
V_9 -> V_41 = F_18 () ;
F_12 ( V_9 -> V_27 , V_47 ,
V_39 ) ;
F_20 ( & V_9 -> V_43 ) ;
return V_40 ;
}
static int F_23 ( struct V_8 * V_9 ,
int V_48 , T_4 V_49 )
{
struct V_7 * V_50 ;
int V_51 ;
V_50 = F_4 ( V_9 ) ;
if ( ! F_21 ( V_50 ) )
return 0 ;
F_13 ( V_9 ) ;
F_19 ( & V_50 -> V_52 ) ;
V_51 = V_50 -> V_53 ;
F_20 ( & V_50 -> V_52 ) ;
if ( V_48 == 0 )
return ( V_51 / 100 ) * V_54 ;
else
return F_22 ( V_50 , V_48 , V_45 , V_55 ) ;
}
static int F_24 ( struct V_8 * V_9 )
{
T_5 V_39 ;
int V_56 ;
V_39 = F_25 () - V_9 -> V_41 ;
if ( V_39 <= 0 )
goto V_57;
F_19 ( & V_9 -> V_43 ) ;
if ( V_39 > 0 ) {
F_11 ( V_9 ) ;
F_10 ( & V_9 -> V_24 , 0 ) ;
F_10 ( & V_9 -> V_26 , 0 ) ;
}
F_20 ( & V_9 -> V_43 ) ;
V_57:
if ( V_9 -> V_58 -> V_59 != NULL ) {
V_56 = V_9 -> V_58 -> V_59 ( V_9 ) ;
F_12 ( V_9 -> V_27 , V_60 ,
V_56 ) ;
}
V_39 = V_9 -> V_41 - F_25 () +
V_9 -> V_42 ;
if ( V_39 <= 0 ) {
F_26 ( V_61 ,
L_1 ,
V_39 ,
( V_62 ) V_9 -> V_42 ) ;
V_39 = 1 ;
}
return V_39 ;
}
static int F_27 ( struct V_8 * V_9 , int V_48 , T_4 V_49 )
{
int V_63 = 0 ;
if ( V_9 -> V_58 -> V_64 != NULL ) {
V_63 = V_9 -> V_58 -> V_64 ( V_9 , V_48 , V_49 ) ;
if ( V_48 > 0 ) {
F_12 ( V_9 -> V_27 ,
V_65 ,
V_48 ) ;
F_12 ( V_9 -> V_27 ,
V_66 ,
V_63 ) ;
F_26 ( V_61 , L_2 ,
V_9 -> V_67 , V_48 , V_63 ) ;
}
}
return V_63 ;
}
static int F_28 ( struct V_68 * V_69 , void * V_51 )
{
int V_21 , V_23 , V_25 ;
int V_70 , V_71 ;
struct V_8 * V_9 = V_69 -> V_72 ;
T_1 V_19 , V_73 ;
T_2 V_16 ;
F_19 ( & V_9 -> V_43 ) ;
V_19 = V_9 -> V_20 ;
V_73 = V_9 -> V_74 ;
V_16 = F_7 ( V_9 ) ;
V_21 = F_8 ( & V_9 -> V_22 ) ;
V_23 = F_8 ( & V_9 -> V_24 ) ;
V_25 = F_8 ( & V_9 -> V_26 ) ;
V_70 = V_23 - V_25 ;
V_71 = F_8 ( & V_9 -> V_75 ) ;
F_20 ( & V_9 -> V_43 ) ;
F_29 ( V_69 , L_3
L_4
L_5
L_6 ,
V_9 -> V_67 , V_19 , V_73 , V_71 ) ;
F_29 ( V_69 , L_7
L_8 ,
V_23 , V_25 , V_70 ,
V_21 , V_16 ) ;
return 0 ;
}
static T_6 F_30 ( struct V_76 * V_77 , struct V_78 * V_79 ,
char * V_80 )
{
struct V_8 * V_9 = F_5 ( V_77 , struct V_8 ,
V_81 ) ;
int V_70 ;
F_19 ( & V_9 -> V_43 ) ;
V_70 = F_8 ( & V_9 -> V_24 ) -
F_8 ( & V_9 -> V_26 ) ;
F_20 ( & V_9 -> V_43 ) ;
return sprintf ( V_80 , L_9 , V_70 ) ;
}
static void F_31 ( struct V_76 * V_77 )
{
struct V_8 * V_9 = F_5 ( V_77 , struct V_8 ,
V_81 ) ;
F_32 ( & V_9 -> V_82 ) ;
}
static int F_33 ( struct V_8 * V_9 )
{
struct V_7 * V_50 = F_4 ( V_9 ) ;
int V_83 ;
F_34 ( & V_9 -> V_82 ) ;
V_83 = F_35 ( & V_9 -> V_81 , & V_84 , & V_50 -> V_85 ,
L_10 ) ;
return V_83 ;
}
static int F_36 ( struct V_8 * V_9 )
{
struct V_7 * V_50 = F_4 ( V_9 ) ;
struct V_86 * V_87 ;
struct V_88 V_89 [ 2 ] ;
char * V_90 = NULL ;
int V_91 = 0 ;
V_90 = F_37 ( V_92 + 1 , V_93 ) ;
if ( ! V_90 )
return - V_94 ;
V_87 = V_50 -> V_95 ;
if ( F_38 ( V_87 ) ) {
F_39 ( L_11 ,
F_40 ( V_50 ) ) ;
V_91 = - V_96 ;
goto V_97;
}
V_9 -> V_98 = F_41 ( L_10 , V_87 ,
NULL , NULL ) ;
if ( F_42 ( V_9 -> V_98 ) ) {
F_39 ( L_12 ) ;
V_91 = F_43 ( V_9 -> V_98 ) ;
V_9 -> V_98 = NULL ;
goto V_97;
}
V_90 [ V_92 ] = '\0' ;
memset ( V_89 , 0 , sizeof( V_89 ) ) ;
V_89 [ 0 ] . V_99 = V_90 ;
F_44 ( V_100 , V_9 , & V_101 ) ;
V_9 -> V_27 = F_45 ( V_102 -
V_103 , 0 ) ;
if ( ! V_9 -> V_27 ) {
V_91 = - V_94 ;
goto V_97;
}
F_46 ( V_9 -> V_27 , V_29 ,
V_104 | V_105 ,
L_13 , L_14 ) ;
F_46 ( V_9 -> V_27 , V_106 ,
V_104 | V_105 ,
L_15 , L_14 ) ;
F_46 ( V_9 -> V_27 , V_107 ,
V_104 | V_105 ,
L_16 , L_14 ) ;
F_46 ( V_9 -> V_27 , V_30 ,
V_104 | V_105 ,
L_17 , L_18 ) ;
F_46 ( V_9 -> V_27 , V_32 ,
V_104 | V_105 ,
L_19 , L_18 ) ;
F_46 ( V_9 -> V_27 , V_31 ,
V_104 | V_105 ,
L_20 , L_18 ) ;
F_46 ( V_9 -> V_27 , V_28 ,
V_104 | V_105 ,
L_21 , L_21 ) ;
F_46 ( V_9 -> V_27 , V_65 ,
V_104 | V_105 ,
L_22 , L_14 ) ;
F_46 ( V_9 -> V_27 , V_66 ,
V_104 | V_105 ,
L_23 , L_14 ) ;
F_46 ( V_9 -> V_27 , V_60 ,
V_104 | V_105 ,
L_24 , L_14 ) ;
F_46 ( V_9 -> V_27 , V_47 ,
V_104 | V_105 ,
L_25 , L_26 ) ;
V_91 = F_47 ( V_9 -> V_98 , L_27 ,
V_9 -> V_27 ) ;
V_97:
F_48 ( V_90 ) ;
return V_91 ;
}
static void F_49 ( struct V_8 * V_9 )
{
F_50 ( & V_9 -> V_81 ) ;
F_51 ( & V_9 -> V_82 ) ;
}
static void F_52 ( struct V_8 * V_9 )
{
if ( V_9 -> V_27 != NULL ) {
F_53 ( & V_9 -> V_27 ) ;
V_9 -> V_27 = NULL ;
}
if ( V_9 -> V_98 != NULL ) {
F_54 ( & V_9 -> V_98 ) ;
V_9 -> V_98 = NULL ;
}
}
int F_55 ( struct V_8 * V_9 , struct V_7 * V_50 ,
int V_108 , T_7 V_109 )
{
int V_91 ;
F_56 ( & V_9 -> V_43 ) ;
F_10 ( & V_9 -> V_22 , 0 ) ;
V_9 -> V_41 = F_25 () ;
F_10 ( & V_9 -> V_75 , 1 ) ;
F_10 ( & V_9 -> V_24 , 0 ) ;
F_10 ( & V_9 -> V_26 , 0 ) ;
V_9 -> V_18 = F_57 ( V_110 ) ;
snprintf ( V_9 -> V_67 , sizeof( V_9 -> V_67 ) , L_28 ,
F_40 ( V_50 ) , V_108 ) ;
F_9 ( V_9 , 1 ) ;
V_9 -> V_20 = 0 ;
V_9 -> V_58 = & V_111 ;
V_9 -> V_42 = V_112 ;
V_9 -> V_74 = 0 ;
V_91 = F_36 ( V_9 ) ;
if ( V_91 )
return V_91 ;
V_91 = F_33 ( V_9 ) ;
if ( V_91 )
return V_91 ;
F_26 ( V_61 , L_29 , V_9 -> V_67 ) ;
return V_91 ;
}
void F_58 ( struct V_8 * V_9 )
{
F_49 ( V_9 ) ;
F_52 ( V_9 ) ;
F_59 ( V_9 , 0x5a , sizeof( * V_9 ) ) ;
}
void F_60 ( struct V_8 * V_9 , struct V_113 * V_114 )
{
if ( V_114 -> V_115 -> V_116 == V_117 )
return;
F_61 ( & V_9 -> V_22 ) ;
F_61 ( & V_9 -> V_24 ) ;
F_62 ( V_9 -> V_27 , V_106 ) ;
}
void F_63 ( struct V_8 * V_9 , struct V_113 * V_114 )
{
if ( V_114 -> V_115 -> V_116 == V_117 )
return;
F_14 ( F_8 ( & V_9 -> V_22 ) > 0 ) ;
F_64 ( & V_9 -> V_22 ) ;
F_61 ( & V_9 -> V_26 ) ;
F_62 ( V_9 -> V_27 , V_107 ) ;
}
T_1 F_65 ( struct V_8 * V_9 )
{
T_1 V_19 ;
F_19 ( & V_9 -> V_43 ) ;
V_19 = V_9 -> V_20 ;
F_20 ( & V_9 -> V_43 ) ;
return V_19 ;
}
void F_66 ( struct V_8 * V_9 , T_1 V_73 )
{
F_19 ( & V_9 -> V_43 ) ;
V_9 -> V_74 = V_73 ;
F_20 ( & V_9 -> V_43 ) ;
}
T_2 F_67 ( struct V_8 * V_9 )
{
return F_8 ( & V_9 -> V_75 ) ;
}
static int F_68 ( struct V_8 * V_9 )
{
return F_8 ( & V_9 -> V_22 ) ;
}
static unsigned long F_69 ( T_7 V_109 , T_4 V_49 )
{
int V_118 = 0 , V_119 ;
struct V_7 * V_50 ;
struct V_7 * V_120 = NULL ;
void * V_121 ;
if ( V_109 == V_122 && ! ( V_49 & V_123 ) )
return 0 ;
F_26 ( V_61 , L_30 ,
V_109 == V_122 ? L_31 : L_32 ) ;
V_121 = F_70 () ;
for ( V_119 = F_71 ( V_109 ) ;
V_119 > 0 ; V_119 -- ) {
F_72 ( F_73 ( V_109 ) ) ;
if ( F_74 ( F_75 ( V_109 ) ) ) {
F_76 ( F_73 ( V_109 ) ) ;
F_77 ( V_121 ) ;
return 0 ;
}
V_50 = F_78 ( V_109 ) ;
if ( V_50 == V_120 ) {
F_76 ( F_73 ( V_109 ) ) ;
break;
}
if ( F_79 ( V_50 ) ) {
F_80 ( V_50 , V_109 ) ;
F_76 ( F_73 ( V_109 ) ) ;
continue;
}
if ( V_120 == NULL )
V_120 = V_50 ;
F_81 ( V_50 ) ;
F_82 ( V_50 , V_109 ) ;
F_76 ( F_73 ( V_109 ) ) ;
V_118 += F_27 ( & V_50 -> V_10 , 0 , V_49 ) ;
F_83 ( V_50 ) ;
}
F_77 ( V_121 ) ;
return V_118 ;
}
static unsigned long F_84 ( T_7 V_109 , int V_48 , T_4 V_49 )
{
unsigned long V_124 = 0 ;
int V_125 , V_119 ;
struct V_7 * V_50 ;
void * V_121 ;
if ( V_109 == V_122 && ! ( V_49 & V_123 ) )
return - 1 ;
V_121 = F_70 () ;
for ( V_125 = V_119 = F_71 ( V_109 ) ;
V_125 > 0 ; V_125 -- ) {
int V_63 , V_126 ;
F_72 ( F_73 ( V_109 ) ) ;
if ( F_74 ( F_75 ( V_109 ) ) ) {
F_76 ( F_73 ( V_109 ) ) ;
break;
}
V_50 = F_78 ( V_109 ) ;
F_81 ( V_50 ) ;
F_82 ( V_50 , V_109 ) ;
F_76 ( F_73 ( V_109 ) ) ;
V_126 = F_68 ( & V_50 -> V_10 ) ;
V_63 = 1 + F_85 ( int , V_126 , V_48 / V_119 ) ;
V_124 += F_27 ( & V_50 -> V_10 , V_63 , V_49 ) ;
F_83 ( V_50 ) ;
}
F_77 ( V_121 ) ;
return V_124 ;
}
static unsigned long F_86 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
return F_69 ( V_122 , V_130 -> V_49 ) ;
}
static unsigned long F_87 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
return F_84 ( V_122 , V_130 -> V_131 ,
V_130 -> V_49 ) ;
}
static int F_88 ( T_7 V_109 )
{
struct V_7 * V_50 ;
struct V_7 * V_120 = NULL ;
int V_48 ;
int time = 50 ;
for ( V_48 = F_71 ( V_109 ) ; V_48 > 0 ; V_48 -- ) {
int V_132 ;
F_72 ( F_73 ( V_109 ) ) ;
if ( F_74 ( F_75 ( V_109 ) ) ) {
F_76 ( F_73 ( V_109 ) ) ;
break;
}
V_50 = F_78 ( V_109 ) ;
if ( V_120 == V_50 ) {
F_76 ( F_73 ( V_109 ) ) ;
break;
}
if ( F_79 ( V_50 ) ) {
F_80 ( V_50 , V_109 ) ;
F_76 ( F_73 ( V_109 ) ) ;
continue;
}
if ( V_120 == NULL )
V_120 = V_50 ;
F_19 ( & V_50 -> V_52 ) ;
if ( V_50 -> V_133 ) {
V_132 = 1 ;
} else {
V_132 = 0 ;
F_81 ( V_50 ) ;
}
F_20 ( & V_50 -> V_52 ) ;
F_82 ( V_50 , V_109 ) ;
F_76 ( F_73 ( V_109 ) ) ;
if ( ! V_132 ) {
int V_134 = F_24 ( & V_50 -> V_10 ) ;
if ( V_134 < time )
time = V_134 ;
F_83 ( V_50 ) ;
}
}
return time ;
}
static int F_89 ( void * V_135 )
{
struct V_136 * V_137 = (struct V_136 * ) V_135 ;
int V_138 ;
F_90 ( V_137 , V_139 ) ;
F_91 ( & V_137 -> V_140 ) ;
F_26 ( V_61 , L_33 ,
L_34 , F_92 () ) ;
while ( 1 ) {
struct V_141 V_142 ;
V_138 = F_88 ( V_122 ) ;
V_142 = F_93 ( F_94 ( V_138 ) ,
NULL , NULL ) ;
F_95 ( V_137 -> V_140 ,
F_96 ( V_137 ) ||
F_97 ( V_137 ) ,
& V_142 ) ;
if ( F_98 ( V_137 , V_143 ) )
break;
F_98 ( V_137 , V_144 ) ;
}
F_90 ( V_137 , V_145 ) ;
F_91 ( & V_137 -> V_140 ) ;
F_26 ( V_61 , L_35 ,
L_34 , F_92 () ) ;
F_99 ( & V_146 , 0 ) ;
}
static int F_100 ( void )
{
struct V_141 V_142 = { 0 } ;
struct V_147 * V_148 ;
if ( V_149 != NULL )
return - V_150 ;
V_149 = F_37 ( sizeof( * V_149 ) , V_93 ) ;
if ( ! V_149 )
return - V_94 ;
F_34 ( & V_146 ) ;
F_101 ( & V_149 -> V_140 ) ;
V_148 = F_102 ( F_89 , V_149 ,
L_34 ) ;
if ( F_42 ( V_148 ) ) {
F_39 ( L_36 , F_43 ( V_148 ) ) ;
F_48 ( V_149 ) ;
V_149 = NULL ;
return F_43 ( V_148 ) ;
}
F_95 ( V_149 -> V_140 ,
F_103 ( V_149 ) , & V_142 ) ;
return 0 ;
}
static void F_104 ( void )
{
if ( V_149 == NULL )
return;
F_90 ( V_149 , V_143 ) ;
F_91 ( & V_149 -> V_140 ) ;
F_51 ( & V_146 ) ;
F_48 ( V_149 ) ;
V_149 = NULL ;
}
int F_105 ( void )
{
int V_91 ;
V_91 = F_100 () ;
if ( V_91 == 0 )
F_106 ( & V_151 ) ;
return V_91 ;
}
void F_107 ( void )
{
if ( V_149 )
F_108 ( & V_151 ) ;
F_104 () ;
}

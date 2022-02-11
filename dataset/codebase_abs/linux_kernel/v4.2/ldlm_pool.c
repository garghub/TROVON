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
static void F_7 ( struct V_8 * V_9 )
{
int V_15 , V_16 , V_17 ;
V_17 = F_8 ( V_9 ) ;
V_15 = F_9 ( & V_9 -> V_18 ) ;
V_16 = F_6 ( V_9 -> V_19 ) ;
V_16 = ( ( V_17 - V_15 ) * V_16 ) / 100 ;
V_9 -> V_20 = V_15 + V_16 ;
V_17 = ( V_17 * 5 ) >> 2 ;
if ( V_9 -> V_20 > V_17 )
V_9 -> V_20 = V_17 ;
}
static void F_10 ( struct V_8 * V_9 )
{
int V_15 ;
int V_21 ;
int V_3 ;
T_1 V_22 ;
T_1 V_23 ;
T_1 V_24 ;
T_2 V_17 ;
V_22 = V_9 -> V_25 ;
V_21 = V_9 -> V_20 ;
V_17 = F_8 ( V_9 ) ;
V_15 = F_9 ( & V_9 -> V_18 ) ;
V_3 = V_15 < V_17 ;
V_24 = F_11 ( int , V_17 - ( V_15 - V_21 ) , 1 ) ;
V_23 = V_24 << V_26 ;
F_12 ( V_23 , V_17 ) ;
V_22 = V_22 * V_23 ;
V_22 = F_1 ( V_22 , V_26 , V_3 ) ;
if ( V_22 > F_2 ( V_17 ) )
V_22 = F_2 ( V_17 ) ;
else if ( V_22 < F_3 ( V_17 ) )
V_22 = F_3 ( V_17 ) ;
V_9 -> V_25 = V_22 ;
}
static void F_13 ( struct V_8 * V_9 )
{
int V_21 = V_9 -> V_20 ;
T_1 V_22 = V_9 -> V_25 ;
int V_15 = F_9 ( & V_9 -> V_18 ) ;
int V_27 = F_9 ( & V_9 -> V_28 ) ;
int V_29 = F_9 ( & V_9 -> V_30 ) ;
F_14 ( V_9 -> V_31 , V_32 ,
V_22 ) ;
F_14 ( V_9 -> V_31 , V_33 ,
V_15 ) ;
F_14 ( V_9 -> V_31 , V_34 ,
V_27 ) ;
F_14 ( V_9 -> V_31 , V_35 ,
V_21 ) ;
F_14 ( V_9 -> V_31 , V_36 ,
V_29 ) ;
}
static void F_15 ( struct V_8 * V_9 )
{
struct V_37 * V_38 ;
V_38 = F_4 ( V_9 ) -> V_39 ;
F_16 ( V_38 != NULL ) ;
F_17 ( & V_38 -> V_40 ) ;
V_38 -> V_41 = V_9 -> V_25 ;
F_18 ( & V_38 -> V_40 ) ;
}
static int F_19 ( struct V_8 * V_9 )
{
T_3 V_42 ;
V_42 = F_20 () - V_9 -> V_43 ;
if ( V_42 < V_9 -> V_19 )
return 0 ;
F_21 ( & V_9 -> V_44 ) ;
V_42 = F_20 () - V_9 -> V_43 ;
if ( V_42 < V_9 -> V_19 ) {
F_22 ( & V_9 -> V_44 ) ;
return 0 ;
}
F_10 ( V_9 ) ;
F_15 ( V_9 ) ;
F_7 ( V_9 ) ;
V_9 -> V_43 = F_20 () ;
F_14 ( V_9 -> V_31 , V_45 ,
V_42 ) ;
F_22 ( & V_9 -> V_44 ) ;
return 0 ;
}
static int F_23 ( struct V_8 * V_9 ,
int V_46 , T_4 V_47 )
{
T_2 V_17 ;
if ( V_46 == 0 )
return F_9 ( & V_9 -> V_18 ) ;
if ( F_9 ( & V_9 -> V_18 ) == 0 )
return 0 ;
F_21 ( & V_9 -> V_44 ) ;
if ( V_46 < V_9 -> V_25 ) {
V_9 -> V_25 = V_9 -> V_25 - V_46 ;
} else {
V_17 = F_8 ( V_9 ) ;
V_9 -> V_25 = F_3 ( V_17 ) ;
}
F_15 ( V_9 ) ;
F_22 ( & V_9 -> V_44 ) ;
return 0 ;
}
static int F_24 ( struct V_8 * V_9 , int V_17 )
{
struct V_37 * V_38 ;
V_38 = F_4 ( V_9 ) -> V_39 ;
F_16 ( V_38 != NULL && V_38 != V_48 ) ;
F_16 ( V_38 -> V_49 != V_48 ) ;
F_17 ( & V_38 -> V_40 ) ;
V_38 -> V_50 = V_17 ;
F_18 ( & V_38 -> V_40 ) ;
F_25 ( V_9 , V_17 ) ;
return 0 ;
}
static void F_26 ( struct V_8 * V_9 )
{
struct V_37 * V_38 ;
V_38 = F_4 ( V_9 ) -> V_39 ;
F_16 ( V_38 != NULL ) ;
F_27 ( & V_38 -> V_40 ) ;
V_9 -> V_25 = V_38 -> V_41 ;
F_25 ( V_9 , V_38 -> V_50 ) ;
F_28 ( & V_38 -> V_40 ) ;
}
static int F_29 ( struct V_8 * V_9 )
{
T_3 V_42 ;
int V_51 ;
V_42 = F_20 () - V_9 -> V_43 ;
if ( V_42 < V_9 -> V_19 )
return 0 ;
F_21 ( & V_9 -> V_44 ) ;
V_42 = F_20 () - V_9 -> V_43 ;
if ( V_42 < V_9 -> V_19 ) {
F_22 ( & V_9 -> V_44 ) ;
return 0 ;
}
F_26 ( V_9 ) ;
F_22 ( & V_9 -> V_44 ) ;
if ( ! F_30 ( F_4 ( V_9 ) ) ) {
V_51 = 0 ;
goto V_52;
}
V_51 = F_31 ( F_4 ( V_9 ) , 0 , V_53 , V_54 ) ;
V_52:
F_21 ( & V_9 -> V_44 ) ;
V_9 -> V_43 = F_20 () ;
F_14 ( V_9 -> V_31 , V_45 ,
V_42 ) ;
F_22 ( & V_9 -> V_44 ) ;
return V_51 ;
}
static int F_32 ( struct V_8 * V_9 ,
int V_46 , T_4 V_47 )
{
struct V_7 * V_55 ;
int V_56 ;
V_55 = F_4 ( V_9 ) ;
if ( ! F_30 ( V_55 ) )
return 0 ;
F_26 ( V_9 ) ;
F_21 ( & V_55 -> V_57 ) ;
V_56 = V_55 -> V_58 ;
F_22 ( & V_55 -> V_57 ) ;
if ( V_46 == 0 )
return ( V_56 / 100 ) * V_59 ;
else
return F_31 ( V_55 , V_46 , V_53 , V_60 ) ;
}
int F_33 ( struct V_8 * V_9 )
{
T_3 V_42 ;
int V_61 ;
V_42 = F_20 () - V_9 -> V_43 ;
if ( V_42 <= 0 )
goto V_62;
F_21 ( & V_9 -> V_44 ) ;
if ( V_42 > 0 ) {
F_13 ( V_9 ) ;
F_34 ( & V_9 -> V_28 , 0 ) ;
F_34 ( & V_9 -> V_30 , 0 ) ;
}
F_22 ( & V_9 -> V_44 ) ;
V_62:
if ( V_9 -> V_63 -> V_64 != NULL ) {
V_61 = V_9 -> V_63 -> V_64 ( V_9 ) ;
F_14 ( V_9 -> V_31 , V_65 ,
V_61 ) ;
}
V_42 = V_9 -> V_43 - F_20 () +
V_9 -> V_19 ;
if ( V_42 <= 0 ) {
F_35 ( V_66 , L_1
L_2 ,
V_42 ,
V_9 -> V_19 ) ;
V_42 = 1 ;
}
return V_42 ;
}
int F_36 ( struct V_8 * V_9 , int V_46 ,
T_4 V_47 )
{
int V_67 = 0 ;
if ( V_9 -> V_63 -> V_68 != NULL ) {
V_67 = V_9 -> V_63 -> V_68 ( V_9 , V_46 , V_47 ) ;
if ( V_46 > 0 ) {
F_14 ( V_9 -> V_31 ,
V_69 ,
V_46 ) ;
F_14 ( V_9 -> V_31 ,
V_70 ,
V_67 ) ;
F_35 ( V_66 , L_3 ,
V_9 -> V_71 , V_46 , V_67 ) ;
}
}
return V_67 ;
}
int F_37 ( struct V_8 * V_9 , int V_17 )
{
if ( V_9 -> V_63 -> V_72 != NULL )
return V_9 -> V_63 -> V_72 ( V_9 , V_17 ) ;
return 0 ;
}
static int F_38 ( struct V_73 * V_74 , void * V_56 )
{
int V_15 , V_27 , V_29 , V_16 ;
int V_75 , V_21 , V_76 ;
struct V_8 * V_9 = V_74 -> V_77 ;
T_1 V_22 , V_78 ;
T_2 V_17 ;
F_21 ( & V_9 -> V_44 ) ;
V_22 = V_9 -> V_25 ;
V_78 = V_9 -> V_79 ;
V_17 = F_8 ( V_9 ) ;
V_21 = V_9 -> V_20 ;
V_15 = F_9 ( & V_9 -> V_18 ) ;
V_27 = F_9 ( & V_9 -> V_28 ) ;
V_29 = F_9 ( & V_9 -> V_30 ) ;
V_75 = V_27 - V_29 ;
V_76 = F_9 ( & V_9 -> V_80 ) ;
V_16 = F_6 ( V_9 -> V_19 ) ;
F_22 ( & V_9 -> V_44 ) ;
F_39 ( V_74 , L_4
L_5
L_6
L_7 ,
V_9 -> V_71 , V_22 , V_78 , V_76 ) ;
if ( F_40 ( F_4 ( V_9 ) ) ) {
F_39 ( V_74 , L_8
L_9 ,
V_16 , V_21 ) ;
}
F_39 ( V_74 , L_10
L_11 ,
V_27 , V_29 , V_75 ,
V_15 , V_17 ) ;
return 0 ;
}
static T_5 F_41 ( struct V_81 * V_82 , struct V_83 * V_84 ,
char * V_85 )
{
struct V_8 * V_9 = F_5 ( V_82 , struct V_8 ,
V_86 ) ;
int V_75 ;
F_21 ( & V_9 -> V_44 ) ;
V_75 = F_9 ( & V_9 -> V_28 ) -
F_9 ( & V_9 -> V_30 ) ;
F_22 ( & V_9 -> V_44 ) ;
return sprintf ( V_85 , L_12 , V_75 ) ;
}
static void F_42 ( struct V_81 * V_82 )
{
struct V_8 * V_9 = F_5 ( V_82 , struct V_8 ,
V_86 ) ;
F_43 ( & V_9 -> V_87 ) ;
}
static int F_44 ( struct V_8 * V_9 )
{
struct V_7 * V_55 = F_4 ( V_9 ) ;
int V_88 ;
F_45 ( & V_9 -> V_87 ) ;
V_88 = F_46 ( & V_9 -> V_86 , & V_89 , & V_55 -> V_90 ,
L_13 ) ;
return V_88 ;
}
static int F_47 ( struct V_8 * V_9 )
{
struct V_7 * V_55 = F_4 ( V_9 ) ;
struct V_91 * V_92 ;
struct V_93 V_94 [ 2 ] ;
char * V_95 = NULL ;
int V_96 = 0 ;
V_95 = F_48 ( V_97 + 1 , V_98 ) ;
if ( ! V_95 )
return - V_99 ;
V_92 = V_55 -> V_100 ;
if ( F_49 ( V_92 ) ) {
F_50 ( L_14 ,
F_51 ( V_55 ) ) ;
V_96 = - V_101 ;
goto V_102;
}
V_9 -> V_103 = F_52 ( L_13 , V_92 ,
NULL , NULL ) ;
if ( F_53 ( V_9 -> V_103 ) ) {
F_50 ( L_15 ) ;
V_96 = F_54 ( V_9 -> V_103 ) ;
V_9 -> V_103 = NULL ;
goto V_102;
}
V_95 [ V_97 ] = '\0' ;
memset ( V_94 , 0 , sizeof( V_94 ) ) ;
V_94 [ 0 ] . V_104 = V_95 ;
F_55 ( V_105 , V_9 , & V_106 ) ;
V_9 -> V_31 = F_56 ( V_107 -
V_108 , 0 ) ;
if ( ! V_9 -> V_31 ) {
V_96 = - V_99 ;
goto V_102;
}
F_57 ( V_9 -> V_31 , V_33 ,
V_109 | V_110 ,
L_16 , L_17 ) ;
F_57 ( V_9 -> V_31 , V_111 ,
V_109 | V_110 ,
L_18 , L_17 ) ;
F_57 ( V_9 -> V_31 , V_112 ,
V_109 | V_110 ,
L_19 , L_17 ) ;
F_57 ( V_9 -> V_31 , V_34 ,
V_109 | V_110 ,
L_20 , L_21 ) ;
F_57 ( V_9 -> V_31 , V_36 ,
V_109 | V_110 ,
L_22 , L_21 ) ;
F_57 ( V_9 -> V_31 , V_35 ,
V_109 | V_110 ,
L_23 , L_21 ) ;
F_57 ( V_9 -> V_31 , V_32 ,
V_109 | V_110 ,
L_24 , L_24 ) ;
F_57 ( V_9 -> V_31 , V_69 ,
V_109 | V_110 ,
L_25 , L_17 ) ;
F_57 ( V_9 -> V_31 , V_70 ,
V_109 | V_110 ,
L_26 , L_17 ) ;
F_57 ( V_9 -> V_31 , V_65 ,
V_109 | V_110 ,
L_27 , L_17 ) ;
F_57 ( V_9 -> V_31 , V_45 ,
V_109 | V_110 ,
L_28 , L_29 ) ;
V_96 = F_58 ( V_9 -> V_103 , L_30 ,
V_9 -> V_31 ) ;
V_102:
F_59 ( V_95 ) ;
return V_96 ;
}
static void F_60 ( struct V_8 * V_9 )
{
F_61 ( & V_9 -> V_86 ) ;
F_62 ( & V_9 -> V_87 ) ;
}
static void F_63 ( struct V_8 * V_9 )
{
if ( V_9 -> V_31 != NULL ) {
F_64 ( & V_9 -> V_31 ) ;
V_9 -> V_31 = NULL ;
}
if ( V_9 -> V_103 != NULL ) {
F_65 ( & V_9 -> V_103 ) ;
V_9 -> V_103 = NULL ;
}
}
int F_66 ( struct V_8 * V_9 , struct V_7 * V_55 ,
int V_113 , T_6 V_114 )
{
int V_96 ;
F_67 ( & V_9 -> V_44 ) ;
F_34 ( & V_9 -> V_18 , 0 ) ;
V_9 -> V_43 = F_20 () ;
F_34 ( & V_9 -> V_80 , 1 ) ;
F_34 ( & V_9 -> V_28 , 0 ) ;
F_34 ( & V_9 -> V_30 , 0 ) ;
V_9 -> V_20 = F_68 ( V_115 ) ;
snprintf ( V_9 -> V_71 , sizeof( V_9 -> V_71 ) , L_31 ,
F_51 ( V_55 ) , V_113 ) ;
if ( V_114 == V_116 ) {
V_9 -> V_63 = & V_117 ;
F_25 ( V_9 , V_115 ) ;
V_9 -> V_19 = V_118 ;
V_9 -> V_25 = F_2 ( V_115 ) ;
} else {
F_25 ( V_9 , 1 ) ;
V_9 -> V_25 = 0 ;
V_9 -> V_63 = & V_119 ;
V_9 -> V_19 = V_120 ;
}
V_9 -> V_79 = 0 ;
V_96 = F_47 ( V_9 ) ;
if ( V_96 )
return V_96 ;
V_96 = F_44 ( V_9 ) ;
if ( V_96 )
return V_96 ;
F_35 ( V_66 , L_32 , V_9 -> V_71 ) ;
return V_96 ;
}
void F_69 ( struct V_8 * V_9 )
{
F_60 ( V_9 ) ;
F_63 ( V_9 ) ;
F_70 ( V_9 , 0x5a , sizeof( * V_9 ) ) ;
}
void F_71 ( struct V_8 * V_9 , struct V_121 * V_122 )
{
if ( V_122 -> V_123 -> V_124 == V_125 )
return;
F_72 ( & V_9 -> V_18 ) ;
F_72 ( & V_9 -> V_28 ) ;
F_73 ( V_9 -> V_31 , V_111 ) ;
if ( F_40 ( F_4 ( V_9 ) ) )
F_33 ( V_9 ) ;
}
void F_74 ( struct V_8 * V_9 , struct V_121 * V_122 )
{
if ( V_122 -> V_123 -> V_124 == V_125 )
return;
F_16 ( F_9 ( & V_9 -> V_18 ) > 0 ) ;
F_75 ( & V_9 -> V_18 ) ;
F_72 ( & V_9 -> V_30 ) ;
F_73 ( V_9 -> V_31 , V_112 ) ;
if ( F_40 ( F_4 ( V_9 ) ) )
F_33 ( V_9 ) ;
}
T_1 F_76 ( struct V_8 * V_9 )
{
T_1 V_22 ;
F_21 ( & V_9 -> V_44 ) ;
V_22 = V_9 -> V_25 ;
F_22 ( & V_9 -> V_44 ) ;
return V_22 ;
}
void F_77 ( struct V_8 * V_9 , T_1 V_22 )
{
F_21 ( & V_9 -> V_44 ) ;
V_9 -> V_25 = V_22 ;
F_22 ( & V_9 -> V_44 ) ;
}
T_1 F_78 ( struct V_8 * V_9 )
{
T_1 V_22 ;
F_21 ( & V_9 -> V_44 ) ;
V_22 = V_9 -> V_79 ;
F_22 ( & V_9 -> V_44 ) ;
return V_22 ;
}
void F_79 ( struct V_8 * V_9 , T_1 V_78 )
{
F_21 ( & V_9 -> V_44 ) ;
V_9 -> V_79 = V_78 ;
F_22 ( & V_9 -> V_44 ) ;
}
T_2 F_8 ( struct V_8 * V_9 )
{
return F_9 ( & V_9 -> V_126 ) ;
}
void F_25 ( struct V_8 * V_9 , T_2 V_17 )
{
F_34 ( & V_9 -> V_126 , V_17 ) ;
}
T_2 F_80 ( struct V_8 * V_9 )
{
return F_9 ( & V_9 -> V_80 ) ;
}
static int F_81 ( struct V_8 * V_9 )
{
return F_9 ( & V_9 -> V_18 ) ;
}
static unsigned long F_82 ( T_6 V_114 , T_4 V_47 )
{
int V_127 = 0 , V_128 ;
struct V_7 * V_55 ;
struct V_7 * V_129 = NULL ;
void * V_130 ;
if ( V_114 == V_131 && ! ( V_47 & V_132 ) )
return 0 ;
F_35 ( V_66 , L_33 ,
V_114 == V_131 ? L_34 : L_35 ) ;
V_130 = F_83 () ;
for ( V_128 = F_84 ( V_114 ) ;
V_128 > 0 ; V_128 -- ) {
F_85 ( F_86 ( V_114 ) ) ;
if ( F_87 ( F_88 ( V_114 ) ) ) {
F_89 ( F_86 ( V_114 ) ) ;
F_90 ( V_130 ) ;
return 0 ;
}
V_55 = F_91 ( V_114 ) ;
if ( V_55 == V_129 ) {
F_89 ( F_86 ( V_114 ) ) ;
break;
}
if ( F_92 ( V_55 ) ) {
F_93 ( V_55 , V_114 ) ;
F_89 ( F_86 ( V_114 ) ) ;
continue;
}
if ( V_129 == NULL )
V_129 = V_55 ;
F_94 ( V_55 ) ;
F_95 ( V_55 , V_114 ) ;
F_89 ( F_86 ( V_114 ) ) ;
V_127 += F_36 ( & V_55 -> V_10 , 0 , V_47 ) ;
F_96 ( V_55 ) ;
}
F_90 ( V_130 ) ;
return V_127 ;
}
static unsigned long F_97 ( T_6 V_114 , int V_46 , T_4 V_47 )
{
unsigned long V_133 = 0 ;
int V_134 , V_128 ;
struct V_7 * V_55 ;
void * V_130 ;
if ( V_114 == V_131 && ! ( V_47 & V_132 ) )
return - 1 ;
V_130 = F_83 () ;
for ( V_134 = V_128 = F_84 ( V_114 ) ;
V_134 > 0 ; V_134 -- ) {
int V_67 , V_135 ;
F_85 ( F_86 ( V_114 ) ) ;
if ( F_87 ( F_88 ( V_114 ) ) ) {
F_89 ( F_86 ( V_114 ) ) ;
break;
}
V_55 = F_91 ( V_114 ) ;
F_94 ( V_55 ) ;
F_95 ( V_55 , V_114 ) ;
F_89 ( F_86 ( V_114 ) ) ;
V_135 = F_81 ( & V_55 -> V_10 ) ;
V_67 = 1 + F_98 ( int , V_135 , V_46 / V_128 ) ;
V_133 += F_36 ( & V_55 -> V_10 , V_67 , V_47 ) ;
F_96 ( V_55 ) ;
}
F_90 ( V_130 ) ;
return ( V_114 == V_116 ) ? V_136 : V_133 ;
}
static unsigned long F_99 ( struct V_137 * V_138 ,
struct V_139 * V_140 )
{
return F_82 ( V_116 , V_140 -> V_47 ) ;
}
static unsigned long F_100 ( struct V_137 * V_138 ,
struct V_139 * V_140 )
{
return F_97 ( V_116 , V_140 -> V_141 ,
V_140 -> V_47 ) ;
}
static unsigned long F_101 ( struct V_137 * V_138 ,
struct V_139 * V_140 )
{
return F_82 ( V_131 , V_140 -> V_47 ) ;
}
static unsigned long F_102 ( struct V_137 * V_138 ,
struct V_139 * V_140 )
{
return F_97 ( V_131 , V_140 -> V_141 ,
V_140 -> V_47 ) ;
}
int F_103 ( T_6 V_114 )
{
T_2 V_142 = 0 , V_143 = 0 , V_144 ;
struct V_7 * V_55 ;
struct V_7 * V_129 = NULL ;
int V_46 , V_145 = 0 ;
int time = 50 ;
if ( V_114 == V_116 ) {
F_85 ( F_86 ( V_114 ) ) ;
F_104 (ns, ldlm_namespace_list(client),
ns_list_chain) {
if ( V_55 -> V_146 != V_147 )
continue;
V_144 = F_81 ( & V_55 -> V_10 ) ;
if ( V_144 == 0 )
V_144 = 1 ;
V_144 += F_1 ( V_144 , V_148 , 0 ) ;
F_37 ( & V_55 -> V_10 , V_144 ) ;
V_142 += V_144 ;
V_143 ++ ;
}
if ( V_142 >= 2 * ( V_115 / 3 ) ) {
F_105 ( L_36 ,
V_142 , V_115 ) ;
V_145 = 1 ;
}
F_104 (ns, ldlm_namespace_list(client),
ns_list_chain) {
if ( ! V_145 && V_55 -> V_146 != V_149 )
continue;
if ( V_145 ) {
V_144 = V_115 /
F_84 ( V_114 ) ;
} else {
V_144 = ( V_115 - V_142 ) /
( F_84 ( V_114 ) -
V_143 ) ;
}
F_37 ( & V_55 -> V_10 , V_144 ) ;
}
F_89 ( F_86 ( V_114 ) ) ;
}
for ( V_46 = F_84 ( V_114 ) ; V_46 > 0 ; V_46 -- ) {
int V_150 ;
F_85 ( F_86 ( V_114 ) ) ;
if ( F_87 ( F_88 ( V_114 ) ) ) {
F_89 ( F_86 ( V_114 ) ) ;
break;
}
V_55 = F_91 ( V_114 ) ;
if ( V_129 == V_55 ) {
F_89 ( F_86 ( V_114 ) ) ;
break;
}
if ( F_92 ( V_55 ) ) {
F_93 ( V_55 , V_114 ) ;
F_89 ( F_86 ( V_114 ) ) ;
continue;
}
if ( V_129 == NULL )
V_129 = V_55 ;
F_21 ( & V_55 -> V_57 ) ;
if ( V_55 -> V_151 ) {
V_150 = 1 ;
} else {
V_150 = 0 ;
F_94 ( V_55 ) ;
}
F_22 ( & V_55 -> V_57 ) ;
F_95 ( V_55 , V_114 ) ;
F_89 ( F_86 ( V_114 ) ) ;
if ( ! V_150 ) {
int V_152 = F_33 ( & V_55 -> V_10 ) ;
if ( V_152 < time )
time = V_152 ;
F_96 ( V_55 ) ;
}
}
return time ;
}
static int F_106 ( void * V_153 )
{
struct V_154 * V_155 = (struct V_154 * ) V_153 ;
int V_156 , V_157 ;
F_107 ( V_155 , V_158 ) ;
F_108 ( & V_155 -> V_159 ) ;
F_35 ( V_66 , L_37 ,
L_38 , F_109 () ) ;
while ( 1 ) {
struct V_160 V_161 ;
V_156 = F_103 ( V_116 ) ;
V_157 = F_103 ( V_131 ) ;
V_161 = F_110 ( F_111 ( F_112 ( V_156 , V_157 ) ) ,
NULL , NULL ) ;
F_113 ( V_155 -> V_159 ,
F_114 ( V_155 ) ||
F_115 ( V_155 ) ,
& V_161 ) ;
if ( F_116 ( V_155 , V_162 ) )
break;
F_116 ( V_155 , V_163 ) ;
}
F_107 ( V_155 , V_164 ) ;
F_108 ( & V_155 -> V_159 ) ;
F_35 ( V_66 , L_39 ,
L_38 , F_109 () ) ;
F_117 ( & V_165 , 0 ) ;
}
static int F_118 ( void )
{
struct V_160 V_161 = { 0 } ;
struct V_166 * V_167 ;
if ( V_168 != NULL )
return - V_169 ;
V_168 = F_48 ( sizeof( * V_168 ) , V_98 ) ;
if ( V_168 == NULL )
return - V_99 ;
F_45 ( & V_165 ) ;
F_119 ( & V_168 -> V_159 ) ;
V_167 = F_120 ( F_106 , V_168 ,
L_38 ) ;
if ( F_53 ( V_167 ) ) {
F_50 ( L_40 , F_54 ( V_167 ) ) ;
F_59 ( V_168 ) ;
V_168 = NULL ;
return F_54 ( V_167 ) ;
}
F_113 ( V_168 -> V_159 ,
F_121 ( V_168 ) , & V_161 ) ;
return 0 ;
}
static void F_122 ( void )
{
if ( V_168 == NULL )
return;
F_107 ( V_168 , V_162 ) ;
F_108 ( & V_168 -> V_159 ) ;
F_62 ( & V_165 ) ;
F_59 ( V_168 ) ;
V_168 = NULL ;
}
int F_123 ( void )
{
int V_96 ;
V_96 = F_118 () ;
if ( V_96 == 0 ) {
F_124 ( & V_170 ) ;
F_124 ( & V_171 ) ;
}
return V_96 ;
}
void F_125 ( void )
{
F_126 ( & V_170 ) ;
F_126 ( & V_171 ) ;
F_122 () ;
}

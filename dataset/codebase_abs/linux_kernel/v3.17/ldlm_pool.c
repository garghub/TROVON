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
V_23 = ( V_24 << V_26 ) ;
F_12 ( V_23 , V_17 ) ;
V_22 = V_22 * V_23 ;
V_22 = F_1 ( V_22 , V_26 , V_3 ) ;
if ( V_22 > F_2 ( V_17 ) ) {
V_22 = F_2 ( V_17 ) ;
} else if ( V_22 < F_3 ( V_17 ) ) {
V_22 = F_3 ( V_17 ) ;
}
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
V_9 -> V_43 = F_20 () ;
F_14 ( V_9 -> V_31 , V_45 ,
V_42 ) ;
F_22 ( & V_9 -> V_44 ) ;
if ( ! F_30 ( F_4 ( V_9 ) ) )
return 0 ;
return F_31 ( F_4 ( V_9 ) , 0 , V_51 , V_52 ) ;
}
static int F_32 ( struct V_8 * V_9 ,
int V_46 , T_4 V_47 )
{
struct V_7 * V_53 ;
int V_54 ;
V_53 = F_4 ( V_9 ) ;
if ( ! F_30 ( V_53 ) )
return 0 ;
F_26 ( V_9 ) ;
F_21 ( & V_53 -> V_55 ) ;
V_54 = V_53 -> V_56 ;
F_22 ( & V_53 -> V_55 ) ;
if ( V_46 == 0 )
return ( V_54 / 100 ) * V_57 ;
else
return F_31 ( V_53 , V_46 , V_51 , V_58 ) ;
}
int F_33 ( struct V_8 * V_9 )
{
T_3 V_42 ;
int V_59 ;
V_42 = F_20 () - V_9 -> V_43 ;
if ( V_42 <= 0 )
goto V_60;
F_21 ( & V_9 -> V_44 ) ;
if ( V_42 > 0 ) {
F_13 ( V_9 ) ;
F_34 ( & V_9 -> V_28 , 0 ) ;
F_34 ( & V_9 -> V_30 , 0 ) ;
}
F_22 ( & V_9 -> V_44 ) ;
V_60:
if ( V_9 -> V_61 -> V_62 != NULL ) {
V_59 = V_9 -> V_61 -> V_62 ( V_9 ) ;
F_14 ( V_9 -> V_31 , V_63 ,
V_59 ) ;
}
V_42 = V_9 -> V_43 - F_20 () +
V_9 -> V_19 ;
return V_42 ;
}
int F_35 ( struct V_8 * V_9 , int V_46 ,
T_4 V_47 )
{
int V_64 = 0 ;
if ( V_9 -> V_61 -> V_65 != NULL ) {
V_64 = V_9 -> V_61 -> V_65 ( V_9 , V_46 , V_47 ) ;
if ( V_46 > 0 ) {
F_14 ( V_9 -> V_31 ,
V_66 ,
V_46 ) ;
F_14 ( V_9 -> V_31 ,
V_67 ,
V_64 ) ;
F_36 ( V_68 , L_1
L_2 , V_9 -> V_69 , V_46 , V_64 ) ;
}
}
return V_64 ;
}
int F_37 ( struct V_8 * V_9 , int V_17 )
{
if ( V_9 -> V_61 -> V_70 != NULL )
return ( V_9 -> V_61 -> V_70 ( V_9 , V_17 ) ) ;
return 0 ;
}
static int F_38 ( struct V_71 * V_72 , void * V_54 )
{
int V_15 , V_27 , V_29 , V_16 ;
int V_73 , V_21 , V_74 ;
struct V_8 * V_9 = V_72 -> V_75 ;
T_1 V_22 , V_76 ;
T_2 V_17 ;
F_21 ( & V_9 -> V_44 ) ;
V_22 = V_9 -> V_25 ;
V_76 = V_9 -> V_77 ;
V_17 = F_8 ( V_9 ) ;
V_21 = V_9 -> V_20 ;
V_15 = F_9 ( & V_9 -> V_18 ) ;
V_27 = F_9 ( & V_9 -> V_28 ) ;
V_29 = F_9 ( & V_9 -> V_30 ) ;
V_73 = V_27 - V_29 ;
V_74 = F_9 ( & V_9 -> V_78 ) ;
V_16 = F_6 ( V_9 -> V_19 ) ;
F_22 ( & V_9 -> V_44 ) ;
F_39 ( V_72 , L_3
L_4
L_5
L_6 ,
V_9 -> V_69 , V_22 , V_76 , V_74 ) ;
if ( F_40 ( F_4 ( V_9 ) ) ) {
F_39 ( V_72 , L_7
L_8 ,
V_16 , V_21 ) ;
}
F_39 ( V_72 , L_9 L_10 L_11
L_12 L_13 ,
V_27 , V_29 , V_73 ,
V_15 , V_17 ) ;
return 0 ;
}
static int F_41 ( struct V_71 * V_72 , void * V_54 )
{
struct V_8 * V_9 = V_72 -> V_75 ;
int V_73 ;
F_21 ( & V_9 -> V_44 ) ;
V_73 = F_9 ( & V_9 -> V_28 ) -
F_9 ( & V_9 -> V_30 ) ;
F_22 ( & V_9 -> V_44 ) ;
return F_42 ( V_72 , & V_73 ) ;
}
static T_5 F_43 ( struct V_79 * V_79 , const char * V_80 ,
T_6 V_81 , T_7 * V_82 )
{
struct V_71 * V_83 = V_79 -> V_84 ;
return F_44 ( V_79 , V_80 , V_81 , V_83 -> V_75 ) ;
}
static int F_45 ( struct V_8 * V_9 )
{
struct V_7 * V_53 = F_4 ( V_9 ) ;
struct V_85 * V_86 ;
struct V_87 V_88 [ 2 ] ;
char * V_89 = NULL ;
int V_90 = 0 ;
F_46 ( V_89 , V_91 + 1 ) ;
if ( ! V_89 )
return - V_92 ;
V_86 = V_53 -> V_93 ;
if ( V_86 == NULL ) {
F_47 ( L_14 ,
F_48 ( V_53 ) ) ;
GOTO ( V_94 , V_90 = - V_95 ) ;
}
V_9 -> V_96 = F_49 ( L_15 , V_86 ,
NULL , NULL ) ;
if ( F_50 ( V_9 -> V_96 ) ) {
F_47 ( L_16 ) ;
V_90 = F_51 ( V_9 -> V_96 ) ;
V_9 -> V_96 = NULL ;
GOTO ( V_94 , V_90 ) ;
}
V_89 [ V_91 ] = '\0' ;
memset ( V_88 , 0 , sizeof( V_88 ) ) ;
V_88 [ 0 ] . V_97 = V_89 ;
F_52 ( L_17 , & V_9 -> V_25 ,
& V_98 ) ;
F_52 ( L_18 , & V_9 -> V_99 , & V_100 ) ;
F_52 ( L_19 , & V_9 -> V_18 , & V_101 ) ;
F_52 ( L_20 , V_9 , & V_102 ) ;
F_52 ( L_21 , & V_9 -> V_30 ,
& V_101 ) ;
F_52 ( L_22 , & V_9 -> V_28 ,
& V_101 ) ;
F_52 ( L_23 , V_9 , & V_103 ) ;
F_52 ( L_24 , V_9 , & V_104 ) ;
F_52 ( L_25 , & V_9 -> V_78 ,
& V_100 ) ;
F_52 ( L_26 , V_9 , & V_105 ) ;
V_9 -> V_31 = F_53 ( V_106 -
V_107 , 0 ) ;
if ( ! V_9 -> V_31 )
GOTO ( V_94 , V_90 = - V_92 ) ;
F_54 ( V_9 -> V_31 , V_33 ,
V_108 | V_109 ,
L_19 , L_27 ) ;
F_54 ( V_9 -> V_31 , V_110 ,
V_108 | V_109 ,
L_28 , L_27 ) ;
F_54 ( V_9 -> V_31 , V_111 ,
V_108 | V_109 ,
L_29 , L_27 ) ;
F_54 ( V_9 -> V_31 , V_34 ,
V_108 | V_109 ,
L_22 , L_30 ) ;
F_54 ( V_9 -> V_31 , V_36 ,
V_108 | V_109 ,
L_21 , L_30 ) ;
F_54 ( V_9 -> V_31 , V_35 ,
V_108 | V_109 ,
L_23 , L_30 ) ;
F_54 ( V_9 -> V_31 , V_32 ,
V_108 | V_109 ,
L_31 , L_31 ) ;
F_54 ( V_9 -> V_31 , V_66 ,
V_108 | V_109 ,
L_32 , L_27 ) ;
F_54 ( V_9 -> V_31 , V_67 ,
V_108 | V_109 ,
L_33 , L_27 ) ;
F_54 ( V_9 -> V_31 , V_63 ,
V_108 | V_109 ,
L_34 , L_27 ) ;
F_54 ( V_9 -> V_31 , V_45 ,
V_108 | V_109 ,
L_35 , L_36 ) ;
V_90 = F_55 ( V_9 -> V_96 , L_37 , V_9 -> V_31 ) ;
V_94:
F_56 ( V_89 , V_91 + 1 ) ;
return V_90 ;
}
static void F_57 ( struct V_8 * V_9 )
{
if ( V_9 -> V_31 != NULL ) {
F_58 ( & V_9 -> V_31 ) ;
V_9 -> V_31 = NULL ;
}
if ( V_9 -> V_96 != NULL ) {
F_59 ( & V_9 -> V_96 ) ;
V_9 -> V_96 = NULL ;
}
}
static int F_45 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_57 ( struct V_8 * V_9 ) {}
int F_60 ( struct V_8 * V_9 , struct V_7 * V_53 ,
int V_112 , T_8 V_113 )
{
int V_90 ;
F_61 ( & V_9 -> V_44 ) ;
F_34 ( & V_9 -> V_18 , 0 ) ;
V_9 -> V_43 = F_20 () ;
F_34 ( & V_9 -> V_78 , 1 ) ;
F_34 ( & V_9 -> V_28 , 0 ) ;
F_34 ( & V_9 -> V_30 , 0 ) ;
V_9 -> V_20 = F_62 ( V_114 ) ;
snprintf ( V_9 -> V_69 , sizeof( V_9 -> V_69 ) , L_38 ,
F_48 ( V_53 ) , V_112 ) ;
if ( V_113 == V_115 ) {
V_9 -> V_61 = & V_116 ;
F_25 ( V_9 , V_114 ) ;
V_9 -> V_19 = V_117 ;
V_9 -> V_25 = F_2 ( V_114 ) ;
} else {
F_25 ( V_9 , 1 ) ;
V_9 -> V_25 = 0 ;
V_9 -> V_61 = & V_118 ;
V_9 -> V_19 = V_119 ;
}
V_9 -> V_77 = 0 ;
V_90 = F_45 ( V_9 ) ;
if ( V_90 )
return V_90 ;
F_36 ( V_68 , L_39 , V_9 -> V_69 ) ;
return V_90 ;
}
void F_63 ( struct V_8 * V_9 )
{
F_57 ( V_9 ) ;
F_64 ( V_9 , 0x5a , sizeof( * V_9 ) ) ;
}
void F_65 ( struct V_8 * V_9 , struct V_120 * V_121 )
{
if ( V_121 -> V_122 -> V_123 == V_124 )
return;
F_66 ( & V_9 -> V_18 ) ;
F_66 ( & V_9 -> V_28 ) ;
F_67 ( V_9 -> V_31 , V_110 ) ;
if ( F_40 ( F_4 ( V_9 ) ) )
F_33 ( V_9 ) ;
}
void F_68 ( struct V_8 * V_9 , struct V_120 * V_121 )
{
if ( V_121 -> V_122 -> V_123 == V_124 )
return;
F_16 ( F_9 ( & V_9 -> V_18 ) > 0 ) ;
F_69 ( & V_9 -> V_18 ) ;
F_66 ( & V_9 -> V_30 ) ;
F_67 ( V_9 -> V_31 , V_111 ) ;
if ( F_40 ( F_4 ( V_9 ) ) )
F_33 ( V_9 ) ;
}
T_1 F_70 ( struct V_8 * V_9 )
{
T_1 V_22 ;
F_21 ( & V_9 -> V_44 ) ;
V_22 = V_9 -> V_25 ;
F_22 ( & V_9 -> V_44 ) ;
return V_22 ;
}
void F_71 ( struct V_8 * V_9 , T_1 V_22 )
{
F_21 ( & V_9 -> V_44 ) ;
V_9 -> V_25 = V_22 ;
F_22 ( & V_9 -> V_44 ) ;
}
T_1 F_72 ( struct V_8 * V_9 )
{
T_1 V_22 ;
F_21 ( & V_9 -> V_44 ) ;
V_22 = V_9 -> V_77 ;
F_22 ( & V_9 -> V_44 ) ;
return V_22 ;
}
void F_73 ( struct V_8 * V_9 , T_1 V_76 )
{
F_21 ( & V_9 -> V_44 ) ;
V_9 -> V_77 = V_76 ;
F_22 ( & V_9 -> V_44 ) ;
}
T_2 F_8 ( struct V_8 * V_9 )
{
return F_9 ( & V_9 -> V_99 ) ;
}
void F_25 ( struct V_8 * V_9 , T_2 V_17 )
{
F_34 ( & V_9 -> V_99 , V_17 ) ;
}
T_2 F_74 ( struct V_8 * V_9 )
{
return F_9 ( & V_9 -> V_78 ) ;
}
static int F_75 ( struct V_8 * V_9 )
{
return F_9 ( & V_9 -> V_18 ) ;
}
static unsigned long F_76 ( T_8 V_113 , T_4 V_47 )
{
int V_125 = 0 , V_126 ;
struct V_7 * V_53 ;
struct V_7 * V_127 = NULL ;
void * V_128 ;
if ( V_113 == V_129 && ! ( V_47 & V_130 ) )
return 0 ;
F_36 ( V_68 , L_40 ,
V_113 == V_129 ? L_41 : L_42 ) ;
V_128 = F_77 () ;
for ( V_126 = F_78 ( V_113 ) ;
V_126 > 0 ; V_126 -- ) {
F_79 ( F_80 ( V_113 ) ) ;
if ( F_81 ( F_82 ( V_113 ) ) ) {
F_83 ( F_80 ( V_113 ) ) ;
F_84 ( V_128 ) ;
return 0 ;
}
V_53 = F_85 ( V_113 ) ;
if ( V_53 == V_127 ) {
F_83 ( F_80 ( V_113 ) ) ;
break;
}
if ( F_86 ( V_53 ) ) {
F_87 ( V_53 , V_113 ) ;
F_83 ( F_80 ( V_113 ) ) ;
continue;
}
if ( V_127 == NULL )
V_127 = V_53 ;
F_88 ( V_53 ) ;
F_89 ( V_53 , V_113 ) ;
F_83 ( F_80 ( V_113 ) ) ;
V_125 += F_35 ( & V_53 -> V_10 , 0 , V_47 ) ;
F_90 ( V_53 ) ;
}
F_84 ( V_128 ) ;
return V_125 ;
}
static unsigned long F_91 ( T_8 V_113 , int V_46 , T_4 V_47 )
{
unsigned long V_131 = 0 ;
int V_132 , V_126 ;
struct V_7 * V_53 ;
void * V_128 ;
if ( V_113 == V_129 && ! ( V_47 & V_130 ) )
return - 1 ;
V_128 = F_77 () ;
for ( V_132 = V_126 = F_78 ( V_113 ) ;
V_132 > 0 ; V_132 -- ) {
int V_64 , V_133 ;
F_79 ( F_80 ( V_113 ) ) ;
if ( F_81 ( F_82 ( V_113 ) ) ) {
F_83 ( F_80 ( V_113 ) ) ;
break;
}
V_53 = F_85 ( V_113 ) ;
F_88 ( V_53 ) ;
F_89 ( V_53 , V_113 ) ;
F_83 ( F_80 ( V_113 ) ) ;
V_133 = F_75 ( & V_53 -> V_10 ) ;
V_64 = 1 + F_92 ( int , V_133 , V_46 / V_126 ) ;
V_131 += F_35 ( & V_53 -> V_10 , V_64 , V_47 ) ;
F_90 ( V_53 ) ;
}
F_84 ( V_128 ) ;
return ( V_113 == V_115 ) ? V_134 : V_131 ;
}
static unsigned long F_93 ( struct V_135 * V_136 , struct V_137 * V_138 )
{
return F_76 ( V_115 , V_138 -> V_47 ) ;
}
static unsigned long F_94 ( struct V_135 * V_136 , struct V_137 * V_138 )
{
return F_91 ( V_115 , V_138 -> V_139 ,
V_138 -> V_47 ) ;
}
static unsigned long F_95 ( struct V_135 * V_136 , struct V_137 * V_138 )
{
return F_76 ( V_129 , V_138 -> V_47 ) ;
}
static unsigned long F_96 ( struct V_135 * V_136 , struct V_137 * V_138 )
{
return F_91 ( V_129 , V_138 -> V_139 ,
V_138 -> V_47 ) ;
}
int F_97 ( T_8 V_113 )
{
T_2 V_140 = 0 , V_141 = 0 , V_142 ;
struct V_7 * V_53 ;
struct V_7 * V_127 = NULL ;
int V_46 , V_143 = 0 ;
int time = 50 ;
if ( V_113 == V_115 ) {
F_79 ( F_80 ( V_113 ) ) ;
F_98 (ns, ldlm_namespace_list(client),
ns_list_chain)
{
if ( V_53 -> V_144 != V_145 )
continue;
V_142 = F_75 ( & V_53 -> V_10 ) ;
if ( V_142 == 0 )
V_142 = 1 ;
V_142 += F_1 ( V_142 , V_146 , 0 ) ;
F_37 ( & V_53 -> V_10 , V_142 ) ;
V_140 += V_142 ;
V_141 ++ ;
}
if ( V_140 >= 2 * ( V_114 / 3 ) ) {
F_99 ( L_43
L_44
L_45
L_46 , V_140 , V_114 ) ;
V_143 = 1 ;
}
F_98 (ns, ldlm_namespace_list(client),
ns_list_chain)
{
if ( ! V_143 && V_53 -> V_144 != V_147 )
continue;
if ( V_143 ) {
V_142 = V_114 /
F_78 ( V_113 ) ;
} else {
V_142 = ( V_114 - V_140 ) /
( F_78 ( V_113 ) -
V_141 ) ;
}
F_37 ( & V_53 -> V_10 , V_142 ) ;
}
F_83 ( F_80 ( V_113 ) ) ;
}
for ( V_46 = F_78 ( V_113 ) ; V_46 > 0 ; V_46 -- ) {
int V_148 ;
F_79 ( F_80 ( V_113 ) ) ;
if ( F_81 ( F_82 ( V_113 ) ) ) {
F_83 ( F_80 ( V_113 ) ) ;
break;
}
V_53 = F_85 ( V_113 ) ;
if ( V_127 == V_53 ) {
F_83 ( F_80 ( V_113 ) ) ;
break;
}
if ( F_86 ( V_53 ) ) {
F_87 ( V_53 , V_113 ) ;
F_83 ( F_80 ( V_113 ) ) ;
continue;
}
if ( V_127 == NULL )
V_127 = V_53 ;
F_21 ( & V_53 -> V_55 ) ;
if ( V_53 -> V_149 ) {
V_148 = 1 ;
} else {
V_148 = 0 ;
F_88 ( V_53 ) ;
}
F_22 ( & V_53 -> V_55 ) ;
F_89 ( V_53 , V_113 ) ;
F_83 ( F_80 ( V_113 ) ) ;
if ( ! V_148 ) {
int V_150 = F_33 ( & V_53 -> V_10 ) ;
if ( V_150 < time )
time = V_150 ;
F_90 ( V_53 ) ;
}
}
return time ;
}
static int F_100 ( void * V_151 )
{
struct V_152 * V_153 = (struct V_152 * ) V_151 ;
int V_154 , V_155 ;
F_101 ( V_153 , V_156 ) ;
F_102 ( & V_153 -> V_157 ) ;
F_36 ( V_68 , L_47 ,
L_48 , F_103 () ) ;
while ( 1 ) {
struct V_158 V_159 ;
V_154 = F_97 ( V_115 ) ;
V_155 = F_97 ( V_129 ) ;
V_159 = F_104 ( F_105 ( F_106 ( V_154 , V_155 ) ) ,
NULL , NULL ) ;
F_107 ( V_153 -> V_157 ,
F_108 ( V_153 ) ||
F_109 ( V_153 ) ,
& V_159 ) ;
if ( F_110 ( V_153 , V_160 ) )
break;
else
F_110 ( V_153 , V_161 ) ;
}
F_101 ( V_153 , V_162 ) ;
F_102 ( & V_153 -> V_157 ) ;
F_36 ( V_68 , L_49 ,
L_48 , F_103 () ) ;
F_111 ( & V_163 , 0 ) ;
}
static int F_112 ( void )
{
struct V_158 V_159 = { 0 } ;
struct V_164 * V_165 ;
if ( V_166 != NULL )
return - V_167 ;
F_113 ( V_166 ) ;
if ( V_166 == NULL )
return - V_92 ;
F_114 ( & V_163 ) ;
F_115 ( & V_166 -> V_157 ) ;
V_165 = F_116 ( F_100 , V_166 ,
L_48 ) ;
if ( F_50 ( V_165 ) ) {
F_47 ( L_50 , F_51 ( V_165 ) ) ;
F_56 ( V_166 , sizeof( * V_166 ) ) ;
V_166 = NULL ;
return F_51 ( V_165 ) ;
}
F_107 ( V_166 -> V_157 ,
F_117 ( V_166 ) , & V_159 ) ;
return 0 ;
}
static void F_118 ( void )
{
if ( V_166 == NULL ) {
return;
}
F_101 ( V_166 , V_160 ) ;
F_102 ( & V_166 -> V_157 ) ;
F_119 ( & V_163 ) ;
F_120 ( V_166 ) ;
V_166 = NULL ;
}
int F_121 ( void )
{
int V_90 ;
V_90 = F_112 () ;
if ( V_90 == 0 ) {
F_122 ( & V_168 ) ;
F_122 ( & V_169 ) ;
}
return V_90 ;
}
void F_123 ( void )
{
F_124 ( & V_168 ) ;
F_124 ( & V_169 ) ;
F_118 () ;
}

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
int V_46 , unsigned int V_47 )
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
int V_46 , unsigned int V_47 )
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
unsigned int V_47 )
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
L_4 V_79 L_5
L_6 V_79 L_5
L_7 ,
V_9 -> V_69 , V_22 , V_76 , V_74 ) ;
if ( F_40 ( F_4 ( V_9 ) ) ) {
F_39 ( V_72 , L_8
L_9 ,
V_16 , V_21 ) ;
}
F_39 ( V_72 , L_10 L_11 L_12
L_13 L_14 ,
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
static T_4 F_43 ( struct V_80 * V_80 , const char * V_81 ,
T_5 V_82 , T_6 * V_83 )
{
struct V_71 * V_84 = V_80 -> V_85 ;
return F_44 ( V_80 , V_81 , V_82 , V_84 -> V_75 ) ;
}
static int F_45 ( struct V_8 * V_9 )
{
struct V_7 * V_53 = F_4 ( V_9 ) ;
struct V_86 * V_87 ;
struct V_88 V_89 [ 2 ] ;
char * V_90 = NULL ;
int V_91 = 0 ;
F_46 ( V_90 , V_92 + 1 ) ;
if ( ! V_90 )
return - V_93 ;
V_87 = V_53 -> V_94 ;
if ( V_87 == NULL ) {
F_47 ( L_15 ,
F_48 ( V_53 ) ) ;
GOTO ( V_95 , V_91 = - V_96 ) ;
}
V_9 -> V_97 = F_49 ( L_16 , V_87 ,
NULL , NULL ) ;
if ( F_50 ( V_9 -> V_97 ) ) {
F_47 ( L_17 ) ;
V_91 = F_51 ( V_9 -> V_97 ) ;
V_9 -> V_97 = NULL ;
GOTO ( V_95 , V_91 ) ;
}
V_90 [ V_92 ] = '\0' ;
memset ( V_89 , 0 , sizeof( V_89 ) ) ;
V_89 [ 0 ] . V_98 = V_90 ;
F_52 ( L_18 , & V_9 -> V_25 ,
& V_99 ) ;
F_52 ( L_19 , & V_9 -> V_100 , & V_101 ) ;
F_52 ( L_20 , & V_9 -> V_18 , & V_102 ) ;
F_52 ( L_21 , V_9 , & V_103 ) ;
F_52 ( L_22 , & V_9 -> V_30 ,
& V_102 ) ;
F_52 ( L_23 , & V_9 -> V_28 ,
& V_102 ) ;
F_52 ( L_24 , V_9 , & V_104 ) ;
F_52 ( L_25 , V_9 , & V_105 ) ;
F_52 ( L_26 , & V_9 -> V_78 ,
& V_101 ) ;
F_52 ( L_27 , V_9 , & V_106 ) ;
V_9 -> V_31 = F_53 ( V_107 -
V_108 , 0 ) ;
if ( ! V_9 -> V_31 )
GOTO ( V_95 , V_91 = - V_93 ) ;
F_54 ( V_9 -> V_31 , V_33 ,
V_109 | V_110 ,
L_20 , L_28 ) ;
F_54 ( V_9 -> V_31 , V_111 ,
V_109 | V_110 ,
L_29 , L_28 ) ;
F_54 ( V_9 -> V_31 , V_112 ,
V_109 | V_110 ,
L_30 , L_28 ) ;
F_54 ( V_9 -> V_31 , V_34 ,
V_109 | V_110 ,
L_23 , L_31 ) ;
F_54 ( V_9 -> V_31 , V_36 ,
V_109 | V_110 ,
L_22 , L_31 ) ;
F_54 ( V_9 -> V_31 , V_35 ,
V_109 | V_110 ,
L_24 , L_31 ) ;
F_54 ( V_9 -> V_31 , V_32 ,
V_109 | V_110 ,
L_32 , L_32 ) ;
F_54 ( V_9 -> V_31 , V_66 ,
V_109 | V_110 ,
L_33 , L_28 ) ;
F_54 ( V_9 -> V_31 , V_67 ,
V_109 | V_110 ,
L_34 , L_28 ) ;
F_54 ( V_9 -> V_31 , V_63 ,
V_109 | V_110 ,
L_35 , L_28 ) ;
F_54 ( V_9 -> V_31 , V_45 ,
V_109 | V_110 ,
L_36 , L_37 ) ;
V_91 = F_55 ( V_9 -> V_97 , L_38 , V_9 -> V_31 ) ;
V_95:
F_56 ( V_90 , V_92 + 1 ) ;
return V_91 ;
}
static void F_57 ( struct V_8 * V_9 )
{
if ( V_9 -> V_31 != NULL ) {
F_58 ( & V_9 -> V_31 ) ;
V_9 -> V_31 = NULL ;
}
if ( V_9 -> V_97 != NULL ) {
F_59 ( & V_9 -> V_97 ) ;
V_9 -> V_97 = NULL ;
}
}
int F_60 ( struct V_8 * V_9 , struct V_7 * V_53 ,
int V_113 , T_7 V_114 )
{
int V_91 ;
F_61 ( & V_9 -> V_44 ) ;
F_34 ( & V_9 -> V_18 , 0 ) ;
V_9 -> V_43 = F_20 () ;
F_34 ( & V_9 -> V_78 , 1 ) ;
F_34 ( & V_9 -> V_28 , 0 ) ;
F_34 ( & V_9 -> V_30 , 0 ) ;
V_9 -> V_20 = F_62 ( V_115 ) ;
snprintf ( V_9 -> V_69 , sizeof( V_9 -> V_69 ) , L_39 ,
F_48 ( V_53 ) , V_113 ) ;
if ( V_114 == V_116 ) {
V_9 -> V_61 = & V_117 ;
F_25 ( V_9 , V_115 ) ;
V_9 -> V_19 = V_118 ;
V_9 -> V_25 = F_2 ( V_115 ) ;
} else {
F_25 ( V_9 , 1 ) ;
V_9 -> V_25 = 0 ;
V_9 -> V_61 = & V_119 ;
V_9 -> V_19 = V_120 ;
}
V_9 -> V_77 = 0 ;
V_91 = F_45 ( V_9 ) ;
if ( V_91 )
return V_91 ;
F_36 ( V_68 , L_40 , V_9 -> V_69 ) ;
return V_91 ;
}
void F_63 ( struct V_8 * V_9 )
{
F_57 ( V_9 ) ;
F_64 ( V_9 , 0x5a , sizeof( * V_9 ) ) ;
}
void F_65 ( struct V_8 * V_9 , struct V_121 * V_122 )
{
if ( V_122 -> V_123 -> V_124 == V_125 )
return;
F_66 ( & V_9 -> V_18 ) ;
F_66 ( & V_9 -> V_28 ) ;
F_67 ( V_9 -> V_31 , V_111 ) ;
if ( F_40 ( F_4 ( V_9 ) ) )
F_33 ( V_9 ) ;
}
void F_68 ( struct V_8 * V_9 , struct V_121 * V_122 )
{
if ( V_122 -> V_123 -> V_124 == V_125 )
return;
F_16 ( F_9 ( & V_9 -> V_18 ) > 0 ) ;
F_69 ( & V_9 -> V_18 ) ;
F_66 ( & V_9 -> V_30 ) ;
F_67 ( V_9 -> V_31 , V_112 ) ;
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
return F_9 ( & V_9 -> V_100 ) ;
}
void F_25 ( struct V_8 * V_9 , T_2 V_17 )
{
F_34 ( & V_9 -> V_100 , V_17 ) ;
}
T_2 F_74 ( struct V_8 * V_9 )
{
return F_9 ( & V_9 -> V_78 ) ;
}
static int F_75 ( struct V_8 * V_9 )
{
return F_9 ( & V_9 -> V_18 ) ;
}
static unsigned long F_76 ( T_7 V_114 , unsigned int V_47 )
{
int V_126 = 0 , V_127 ;
struct V_7 * V_53 ;
struct V_7 * V_128 = NULL ;
void * V_129 ;
if ( V_114 == V_130 && ! ( V_47 & V_131 ) )
return 0 ;
F_36 ( V_68 , L_41 ,
V_114 == V_130 ? L_42 : L_43 ) ;
V_129 = F_77 () ;
for ( V_127 = F_78 ( V_114 ) ;
V_127 > 0 ; V_127 -- ) {
F_79 ( F_80 ( V_114 ) ) ;
if ( F_81 ( F_82 ( V_114 ) ) ) {
F_83 ( F_80 ( V_114 ) ) ;
F_84 ( V_129 ) ;
return 0 ;
}
V_53 = F_85 ( V_114 ) ;
if ( V_53 == V_128 ) {
F_83 ( F_80 ( V_114 ) ) ;
break;
}
if ( F_86 ( V_53 ) ) {
F_87 ( V_53 , V_114 ) ;
F_83 ( F_80 ( V_114 ) ) ;
continue;
}
if ( V_128 == NULL )
V_128 = V_53 ;
F_88 ( V_53 ) ;
F_89 ( V_53 , V_114 ) ;
F_83 ( F_80 ( V_114 ) ) ;
V_126 += F_35 ( & V_53 -> V_10 , 0 , V_47 ) ;
F_90 ( V_53 ) ;
}
F_84 ( V_129 ) ;
return V_126 ;
}
static unsigned long F_91 ( T_7 V_114 , int V_46 , unsigned int V_47 )
{
unsigned long V_132 = 0 ;
int V_133 , V_127 ;
struct V_7 * V_53 ;
void * V_129 ;
if ( V_114 == V_130 && ! ( V_47 & V_131 ) )
return - 1 ;
V_129 = F_77 () ;
for ( V_133 = V_127 = F_78 ( V_114 ) ;
V_133 > 0 ; V_133 -- ) {
int V_64 , V_134 ;
F_79 ( F_80 ( V_114 ) ) ;
if ( F_81 ( F_82 ( V_114 ) ) ) {
F_83 ( F_80 ( V_114 ) ) ;
break;
}
V_53 = F_85 ( V_114 ) ;
F_88 ( V_53 ) ;
F_89 ( V_53 , V_114 ) ;
F_83 ( F_80 ( V_114 ) ) ;
V_134 = F_75 ( & V_53 -> V_10 ) ;
V_64 = 1 + F_92 ( int , V_134 , V_46 / V_127 ) ;
V_132 += F_35 ( & V_53 -> V_10 , V_64 , V_47 ) ;
F_90 ( V_53 ) ;
}
F_84 ( V_129 ) ;
return ( V_114 == V_116 ) ? V_135 : V_132 ;
}
static unsigned long F_93 ( struct V_136 * V_137 , struct V_138 * V_139 )
{
return F_76 ( V_116 , V_139 -> V_47 ) ;
}
static unsigned long F_94 ( struct V_136 * V_137 , struct V_138 * V_139 )
{
return F_91 ( V_116 , V_139 -> V_140 ,
V_139 -> V_47 ) ;
}
static unsigned long F_95 ( struct V_136 * V_137 , struct V_138 * V_139 )
{
return F_76 ( V_130 , V_139 -> V_47 ) ;
}
static unsigned long F_96 ( struct V_136 * V_137 , struct V_138 * V_139 )
{
return F_91 ( V_130 , V_139 -> V_140 ,
V_139 -> V_47 ) ;
}
int F_97 ( T_7 V_114 )
{
T_2 V_141 = 0 , V_142 = 0 , V_143 ;
struct V_7 * V_53 ;
struct V_7 * V_128 = NULL ;
int V_46 , V_144 = 0 ;
int time = 50 ;
if ( V_114 == V_116 ) {
F_79 ( F_80 ( V_114 ) ) ;
F_98 (ns, ldlm_namespace_list(client),
ns_list_chain)
{
if ( V_53 -> V_145 != V_146 )
continue;
V_143 = F_75 ( & V_53 -> V_10 ) ;
if ( V_143 == 0 )
V_143 = 1 ;
V_143 += F_1 ( V_143 , V_147 , 0 ) ;
F_37 ( & V_53 -> V_10 , V_143 ) ;
V_141 += V_143 ;
V_142 ++ ;
}
if ( V_141 >= 2 * ( V_115 / 3 ) ) {
F_99 ( L_44
L_45
L_46
L_47 , V_141 , V_115 ) ;
V_144 = 1 ;
}
F_98 (ns, ldlm_namespace_list(client),
ns_list_chain)
{
if ( ! V_144 && V_53 -> V_145 != V_148 )
continue;
if ( V_144 ) {
V_143 = V_115 /
F_78 ( V_114 ) ;
} else {
V_143 = ( V_115 - V_141 ) /
( F_78 ( V_114 ) -
V_142 ) ;
}
F_37 ( & V_53 -> V_10 , V_143 ) ;
}
F_83 ( F_80 ( V_114 ) ) ;
}
for ( V_46 = F_78 ( V_114 ) ; V_46 > 0 ; V_46 -- ) {
int V_149 ;
F_79 ( F_80 ( V_114 ) ) ;
if ( F_81 ( F_82 ( V_114 ) ) ) {
F_83 ( F_80 ( V_114 ) ) ;
break;
}
V_53 = F_85 ( V_114 ) ;
if ( V_128 == V_53 ) {
F_83 ( F_80 ( V_114 ) ) ;
break;
}
if ( F_86 ( V_53 ) ) {
F_87 ( V_53 , V_114 ) ;
F_83 ( F_80 ( V_114 ) ) ;
continue;
}
if ( V_128 == NULL )
V_128 = V_53 ;
F_21 ( & V_53 -> V_55 ) ;
if ( V_53 -> V_150 ) {
V_149 = 1 ;
} else {
V_149 = 0 ;
F_88 ( V_53 ) ;
}
F_22 ( & V_53 -> V_55 ) ;
F_89 ( V_53 , V_114 ) ;
F_83 ( F_80 ( V_114 ) ) ;
if ( ! V_149 ) {
int V_151 = F_33 ( & V_53 -> V_10 ) ;
if ( V_151 < time )
time = V_151 ;
F_90 ( V_53 ) ;
}
}
return time ;
}
static int F_100 ( void * V_152 )
{
struct V_153 * V_154 = (struct V_153 * ) V_152 ;
int V_155 , V_156 ;
F_101 ( V_154 , V_157 ) ;
F_102 ( & V_154 -> V_158 ) ;
F_36 ( V_68 , L_48 ,
L_49 , F_103 () ) ;
while ( 1 ) {
struct V_159 V_160 ;
V_155 = F_97 ( V_116 ) ;
V_156 = F_97 ( V_130 ) ;
V_160 = F_104 ( F_105 ( F_106 ( V_155 , V_156 ) ) ,
NULL , NULL ) ;
F_107 ( V_154 -> V_158 ,
F_108 ( V_154 ) ||
F_109 ( V_154 ) ,
& V_160 ) ;
if ( F_110 ( V_154 , V_161 ) )
break;
else
F_110 ( V_154 , V_162 ) ;
}
F_101 ( V_154 , V_163 ) ;
F_102 ( & V_154 -> V_158 ) ;
F_36 ( V_68 , L_50 ,
L_49 , F_103 () ) ;
F_111 ( & V_164 , 0 ) ;
}
static int F_112 ( void )
{
struct V_159 V_160 = { 0 } ;
struct V_165 * V_166 ;
if ( V_167 != NULL )
return - V_168 ;
F_113 ( V_167 ) ;
if ( V_167 == NULL )
return - V_93 ;
F_114 ( & V_164 ) ;
F_115 ( & V_167 -> V_158 ) ;
V_166 = F_116 ( F_100 , V_167 ,
L_49 ) ;
if ( F_50 ( V_166 ) ) {
F_47 ( L_51 , F_51 ( V_166 ) ) ;
F_56 ( V_167 , sizeof( * V_167 ) ) ;
V_167 = NULL ;
return F_51 ( V_166 ) ;
}
F_107 ( V_167 -> V_158 ,
F_117 ( V_167 ) , & V_160 ) ;
return 0 ;
}
static void F_118 ( void )
{
if ( V_167 == NULL ) {
return;
}
F_101 ( V_167 , V_161 ) ;
F_102 ( & V_167 -> V_158 ) ;
F_119 ( & V_164 ) ;
F_120 ( V_167 ) ;
V_167 = NULL ;
}
int F_121 ( void )
{
int V_91 ;
V_91 = F_112 () ;
if ( V_91 == 0 ) {
F_122 ( & V_169 ) ;
F_122 ( & V_170 ) ;
}
return V_91 ;
}
void F_123 ( void )
{
F_124 ( & V_169 ) ;
F_124 ( & V_170 ) ;
F_118 () ;
}

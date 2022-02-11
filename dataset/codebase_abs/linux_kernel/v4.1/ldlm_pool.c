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
static int F_41 ( struct V_73 * V_74 , void * V_56 )
{
struct V_8 * V_9 = V_74 -> V_77 ;
int V_75 ;
F_21 ( & V_9 -> V_44 ) ;
V_75 = F_9 ( & V_9 -> V_28 ) -
F_9 ( & V_9 -> V_30 ) ;
F_22 ( & V_9 -> V_44 ) ;
return F_42 ( V_74 , & V_75 ) ;
}
static T_5 F_43 ( struct V_81 * V_81 ,
const char T_6 * V_82 ,
T_7 V_83 , T_8 * V_84 )
{
struct V_73 * V_85 = V_81 -> V_86 ;
return F_44 ( V_81 , V_82 , V_83 , V_85 -> V_77 ) ;
}
static int F_45 ( struct V_8 * V_9 )
{
struct V_7 * V_55 = F_4 ( V_9 ) ;
struct V_87 * V_88 ;
struct V_89 V_90 [ 2 ] ;
char * V_91 = NULL ;
int V_92 = 0 ;
F_46 ( V_91 , V_93 + 1 ) ;
if ( ! V_91 )
return - V_94 ;
V_88 = V_55 -> V_95 ;
if ( V_88 == NULL ) {
F_47 ( L_12 ,
F_48 ( V_55 ) ) ;
V_92 = - V_96 ;
goto V_97;
}
V_9 -> V_98 = F_49 ( L_13 , V_88 ,
NULL , NULL ) ;
if ( F_50 ( V_9 -> V_98 ) ) {
F_47 ( L_14 ) ;
V_92 = F_51 ( V_9 -> V_98 ) ;
V_9 -> V_98 = NULL ;
goto V_97;
}
V_91 [ V_93 ] = '\0' ;
memset ( V_90 , 0 , sizeof( V_90 ) ) ;
V_90 [ 0 ] . V_99 = V_91 ;
F_52 ( L_15 , & V_9 -> V_25 ,
& V_100 ) ;
F_52 ( L_16 , & V_9 -> V_101 , & V_102 ) ;
F_52 ( L_17 , & V_9 -> V_18 , & V_103 ) ;
F_52 ( L_18 , V_9 , & V_104 ) ;
F_52 ( L_19 , & V_9 -> V_30 ,
& V_103 ) ;
F_52 ( L_20 , & V_9 -> V_28 ,
& V_103 ) ;
F_52 ( L_21 , V_9 , & V_105 ) ;
F_52 ( L_22 , V_9 , & V_106 ) ;
F_52 ( L_23 , & V_9 -> V_80 ,
& V_102 ) ;
F_52 ( L_24 , V_9 , & V_107 ) ;
V_9 -> V_31 = F_53 ( V_108 -
V_109 , 0 ) ;
if ( ! V_9 -> V_31 ) {
V_92 = - V_94 ;
goto V_97;
}
F_54 ( V_9 -> V_31 , V_33 ,
V_110 | V_111 ,
L_17 , L_25 ) ;
F_54 ( V_9 -> V_31 , V_112 ,
V_110 | V_111 ,
L_26 , L_25 ) ;
F_54 ( V_9 -> V_31 , V_113 ,
V_110 | V_111 ,
L_27 , L_25 ) ;
F_54 ( V_9 -> V_31 , V_34 ,
V_110 | V_111 ,
L_20 , L_28 ) ;
F_54 ( V_9 -> V_31 , V_36 ,
V_110 | V_111 ,
L_19 , L_28 ) ;
F_54 ( V_9 -> V_31 , V_35 ,
V_110 | V_111 ,
L_21 , L_28 ) ;
F_54 ( V_9 -> V_31 , V_32 ,
V_110 | V_111 ,
L_29 , L_29 ) ;
F_54 ( V_9 -> V_31 , V_69 ,
V_110 | V_111 ,
L_30 , L_25 ) ;
F_54 ( V_9 -> V_31 , V_70 ,
V_110 | V_111 ,
L_31 , L_25 ) ;
F_54 ( V_9 -> V_31 , V_65 ,
V_110 | V_111 ,
L_32 , L_25 ) ;
F_54 ( V_9 -> V_31 , V_45 ,
V_110 | V_111 ,
L_33 , L_34 ) ;
V_92 = F_55 ( V_9 -> V_98 , L_35 , V_9 -> V_31 ) ;
V_97:
F_56 ( V_91 , V_93 + 1 ) ;
return V_92 ;
}
static void F_57 ( struct V_8 * V_9 )
{
if ( V_9 -> V_31 != NULL ) {
F_58 ( & V_9 -> V_31 ) ;
V_9 -> V_31 = NULL ;
}
if ( V_9 -> V_98 != NULL ) {
F_59 ( & V_9 -> V_98 ) ;
V_9 -> V_98 = NULL ;
}
}
static int F_45 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_57 ( struct V_8 * V_9 ) {}
int F_60 ( struct V_8 * V_9 , struct V_7 * V_55 ,
int V_114 , T_9 V_115 )
{
int V_92 ;
F_61 ( & V_9 -> V_44 ) ;
F_34 ( & V_9 -> V_18 , 0 ) ;
V_9 -> V_43 = F_20 () ;
F_34 ( & V_9 -> V_80 , 1 ) ;
F_34 ( & V_9 -> V_28 , 0 ) ;
F_34 ( & V_9 -> V_30 , 0 ) ;
V_9 -> V_20 = F_62 ( V_116 ) ;
snprintf ( V_9 -> V_71 , sizeof( V_9 -> V_71 ) , L_36 ,
F_48 ( V_55 ) , V_114 ) ;
if ( V_115 == V_117 ) {
V_9 -> V_63 = & V_118 ;
F_25 ( V_9 , V_116 ) ;
V_9 -> V_19 = V_119 ;
V_9 -> V_25 = F_2 ( V_116 ) ;
} else {
F_25 ( V_9 , 1 ) ;
V_9 -> V_25 = 0 ;
V_9 -> V_63 = & V_120 ;
V_9 -> V_19 = V_121 ;
}
V_9 -> V_79 = 0 ;
V_92 = F_45 ( V_9 ) ;
if ( V_92 )
return V_92 ;
F_35 ( V_66 , L_37 , V_9 -> V_71 ) ;
return V_92 ;
}
void F_63 ( struct V_8 * V_9 )
{
F_57 ( V_9 ) ;
F_64 ( V_9 , 0x5a , sizeof( * V_9 ) ) ;
}
void F_65 ( struct V_8 * V_9 , struct V_122 * V_123 )
{
if ( V_123 -> V_124 -> V_125 == V_126 )
return;
F_66 ( & V_9 -> V_18 ) ;
F_66 ( & V_9 -> V_28 ) ;
F_67 ( V_9 -> V_31 , V_112 ) ;
if ( F_40 ( F_4 ( V_9 ) ) )
F_33 ( V_9 ) ;
}
void F_68 ( struct V_8 * V_9 , struct V_122 * V_123 )
{
if ( V_123 -> V_124 -> V_125 == V_126 )
return;
F_16 ( F_9 ( & V_9 -> V_18 ) > 0 ) ;
F_69 ( & V_9 -> V_18 ) ;
F_66 ( & V_9 -> V_30 ) ;
F_67 ( V_9 -> V_31 , V_113 ) ;
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
V_22 = V_9 -> V_79 ;
F_22 ( & V_9 -> V_44 ) ;
return V_22 ;
}
void F_73 ( struct V_8 * V_9 , T_1 V_78 )
{
F_21 ( & V_9 -> V_44 ) ;
V_9 -> V_79 = V_78 ;
F_22 ( & V_9 -> V_44 ) ;
}
T_2 F_8 ( struct V_8 * V_9 )
{
return F_9 ( & V_9 -> V_101 ) ;
}
void F_25 ( struct V_8 * V_9 , T_2 V_17 )
{
F_34 ( & V_9 -> V_101 , V_17 ) ;
}
T_2 F_74 ( struct V_8 * V_9 )
{
return F_9 ( & V_9 -> V_80 ) ;
}
static int F_75 ( struct V_8 * V_9 )
{
return F_9 ( & V_9 -> V_18 ) ;
}
static unsigned long F_76 ( T_9 V_115 , T_4 V_47 )
{
int V_127 = 0 , V_128 ;
struct V_7 * V_55 ;
struct V_7 * V_129 = NULL ;
void * V_130 ;
if ( V_115 == V_131 && ! ( V_47 & V_132 ) )
return 0 ;
F_35 ( V_66 , L_38 ,
V_115 == V_131 ? L_39 : L_40 ) ;
V_130 = F_77 () ;
for ( V_128 = F_78 ( V_115 ) ;
V_128 > 0 ; V_128 -- ) {
F_79 ( F_80 ( V_115 ) ) ;
if ( F_81 ( F_82 ( V_115 ) ) ) {
F_83 ( F_80 ( V_115 ) ) ;
F_84 ( V_130 ) ;
return 0 ;
}
V_55 = F_85 ( V_115 ) ;
if ( V_55 == V_129 ) {
F_83 ( F_80 ( V_115 ) ) ;
break;
}
if ( F_86 ( V_55 ) ) {
F_87 ( V_55 , V_115 ) ;
F_83 ( F_80 ( V_115 ) ) ;
continue;
}
if ( V_129 == NULL )
V_129 = V_55 ;
F_88 ( V_55 ) ;
F_89 ( V_55 , V_115 ) ;
F_83 ( F_80 ( V_115 ) ) ;
V_127 += F_36 ( & V_55 -> V_10 , 0 , V_47 ) ;
F_90 ( V_55 ) ;
}
F_84 ( V_130 ) ;
return V_127 ;
}
static unsigned long F_91 ( T_9 V_115 , int V_46 , T_4 V_47 )
{
unsigned long V_133 = 0 ;
int V_134 , V_128 ;
struct V_7 * V_55 ;
void * V_130 ;
if ( V_115 == V_131 && ! ( V_47 & V_132 ) )
return - 1 ;
V_130 = F_77 () ;
for ( V_134 = V_128 = F_78 ( V_115 ) ;
V_134 > 0 ; V_134 -- ) {
int V_67 , V_135 ;
F_79 ( F_80 ( V_115 ) ) ;
if ( F_81 ( F_82 ( V_115 ) ) ) {
F_83 ( F_80 ( V_115 ) ) ;
break;
}
V_55 = F_85 ( V_115 ) ;
F_88 ( V_55 ) ;
F_89 ( V_55 , V_115 ) ;
F_83 ( F_80 ( V_115 ) ) ;
V_135 = F_75 ( & V_55 -> V_10 ) ;
V_67 = 1 + F_92 ( int , V_135 , V_46 / V_128 ) ;
V_133 += F_36 ( & V_55 -> V_10 , V_67 , V_47 ) ;
F_90 ( V_55 ) ;
}
F_84 ( V_130 ) ;
return ( V_115 == V_117 ) ? V_136 : V_133 ;
}
static unsigned long F_93 ( struct V_137 * V_138 ,
struct V_139 * V_140 )
{
return F_76 ( V_117 , V_140 -> V_47 ) ;
}
static unsigned long F_94 ( struct V_137 * V_138 ,
struct V_139 * V_140 )
{
return F_91 ( V_117 , V_140 -> V_141 ,
V_140 -> V_47 ) ;
}
static unsigned long F_95 ( struct V_137 * V_138 ,
struct V_139 * V_140 )
{
return F_76 ( V_131 , V_140 -> V_47 ) ;
}
static unsigned long F_96 ( struct V_137 * V_138 ,
struct V_139 * V_140 )
{
return F_91 ( V_131 , V_140 -> V_141 ,
V_140 -> V_47 ) ;
}
int F_97 ( T_9 V_115 )
{
T_2 V_142 = 0 , V_143 = 0 , V_144 ;
struct V_7 * V_55 ;
struct V_7 * V_129 = NULL ;
int V_46 , V_145 = 0 ;
int time = 50 ;
if ( V_115 == V_117 ) {
F_79 ( F_80 ( V_115 ) ) ;
F_98 (ns, ldlm_namespace_list(client),
ns_list_chain) {
if ( V_55 -> V_146 != V_147 )
continue;
V_144 = F_75 ( & V_55 -> V_10 ) ;
if ( V_144 == 0 )
V_144 = 1 ;
V_144 += F_1 ( V_144 , V_148 , 0 ) ;
F_37 ( & V_55 -> V_10 , V_144 ) ;
V_142 += V_144 ;
V_143 ++ ;
}
if ( V_142 >= 2 * ( V_116 / 3 ) ) {
F_99 ( L_41 ,
V_142 , V_116 ) ;
V_145 = 1 ;
}
F_98 (ns, ldlm_namespace_list(client),
ns_list_chain) {
if ( ! V_145 && V_55 -> V_146 != V_149 )
continue;
if ( V_145 ) {
V_144 = V_116 /
F_78 ( V_115 ) ;
} else {
V_144 = ( V_116 - V_142 ) /
( F_78 ( V_115 ) -
V_143 ) ;
}
F_37 ( & V_55 -> V_10 , V_144 ) ;
}
F_83 ( F_80 ( V_115 ) ) ;
}
for ( V_46 = F_78 ( V_115 ) ; V_46 > 0 ; V_46 -- ) {
int V_150 ;
F_79 ( F_80 ( V_115 ) ) ;
if ( F_81 ( F_82 ( V_115 ) ) ) {
F_83 ( F_80 ( V_115 ) ) ;
break;
}
V_55 = F_85 ( V_115 ) ;
if ( V_129 == V_55 ) {
F_83 ( F_80 ( V_115 ) ) ;
break;
}
if ( F_86 ( V_55 ) ) {
F_87 ( V_55 , V_115 ) ;
F_83 ( F_80 ( V_115 ) ) ;
continue;
}
if ( V_129 == NULL )
V_129 = V_55 ;
F_21 ( & V_55 -> V_57 ) ;
if ( V_55 -> V_151 ) {
V_150 = 1 ;
} else {
V_150 = 0 ;
F_88 ( V_55 ) ;
}
F_22 ( & V_55 -> V_57 ) ;
F_89 ( V_55 , V_115 ) ;
F_83 ( F_80 ( V_115 ) ) ;
if ( ! V_150 ) {
int V_152 = F_33 ( & V_55 -> V_10 ) ;
if ( V_152 < time )
time = V_152 ;
F_90 ( V_55 ) ;
}
}
return time ;
}
static int F_100 ( void * V_153 )
{
struct V_154 * V_155 = (struct V_154 * ) V_153 ;
int V_156 , V_157 ;
F_101 ( V_155 , V_158 ) ;
F_102 ( & V_155 -> V_159 ) ;
F_35 ( V_66 , L_42 ,
L_43 , F_103 () ) ;
while ( 1 ) {
struct V_160 V_161 ;
V_156 = F_97 ( V_117 ) ;
V_157 = F_97 ( V_131 ) ;
V_161 = F_104 ( F_105 ( F_106 ( V_156 , V_157 ) ) ,
NULL , NULL ) ;
F_107 ( V_155 -> V_159 ,
F_108 ( V_155 ) ||
F_109 ( V_155 ) ,
& V_161 ) ;
if ( F_110 ( V_155 , V_162 ) )
break;
else
F_110 ( V_155 , V_163 ) ;
}
F_101 ( V_155 , V_164 ) ;
F_102 ( & V_155 -> V_159 ) ;
F_35 ( V_66 , L_44 ,
L_43 , F_103 () ) ;
F_111 ( & V_165 , 0 ) ;
}
static int F_112 ( void )
{
struct V_160 V_161 = { 0 } ;
struct V_166 * V_167 ;
if ( V_168 != NULL )
return - V_169 ;
F_113 ( V_168 ) ;
if ( V_168 == NULL )
return - V_94 ;
F_114 ( & V_165 ) ;
F_115 ( & V_168 -> V_159 ) ;
V_167 = F_116 ( F_100 , V_168 ,
L_43 ) ;
if ( F_50 ( V_167 ) ) {
F_47 ( L_45 , F_51 ( V_167 ) ) ;
F_56 ( V_168 , sizeof( * V_168 ) ) ;
V_168 = NULL ;
return F_51 ( V_167 ) ;
}
F_107 ( V_168 -> V_159 ,
F_117 ( V_168 ) , & V_161 ) ;
return 0 ;
}
static void F_118 ( void )
{
if ( V_168 == NULL )
return;
F_101 ( V_168 , V_162 ) ;
F_102 ( & V_168 -> V_159 ) ;
F_119 ( & V_165 ) ;
F_120 ( V_168 ) ;
V_168 = NULL ;
}
int F_121 ( void )
{
int V_92 ;
V_92 = F_112 () ;
if ( V_92 == 0 ) {
F_122 ( & V_170 ) ;
F_122 ( & V_171 ) ;
}
return V_92 ;
}
void F_123 ( void )
{
F_124 ( & V_170 ) ;
F_124 ( & V_171 ) ;
F_118 () ;
}

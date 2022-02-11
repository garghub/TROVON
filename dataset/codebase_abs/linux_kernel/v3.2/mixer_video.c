static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * * V_5 = V_3 ;
* V_5 = F_2 ( V_2 ) ;
return 1 ;
}
static struct V_4 * F_3 (
struct V_6 * V_7 , char * V_8 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 = NULL ;
int V_11 ;
V_10 = F_4 ( V_8 , & V_12 ) ;
if ( ! V_10 ) {
F_5 ( V_7 , L_1 , V_8 ) ;
return NULL ;
}
V_11 = F_6 ( V_10 , NULL , & V_5 , F_1 ) ;
if ( V_5 == NULL ) {
F_5 ( V_7 , L_2 , V_8 ) ;
goto V_13;
}
V_11 = F_7 ( & V_7 -> V_14 , V_5 ) ;
if ( V_11 ) {
F_5 ( V_7 , L_3 , V_5 -> V_15 ) ;
V_5 = NULL ;
}
V_13:
F_8 ( V_10 ) ;
return V_5 ;
}
int T_1 F_9 ( struct V_6 * V_7 ,
struct V_16 * V_17 , int V_18 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_19 * V_14 = & V_7 -> V_14 ;
int V_20 ;
int V_11 = 0 ;
struct V_4 * V_5 ;
F_10 ( V_14 -> V_15 , F_11 ( V_7 -> V_2 ) , sizeof( V_14 -> V_15 ) ) ;
V_11 = F_12 ( V_2 , V_14 ) ;
if ( V_11 ) {
F_13 ( V_7 , L_4 ) ;
goto V_21;
}
V_7 -> V_22 = F_14 ( V_7 -> V_2 ) ;
if ( F_15 ( V_7 -> V_22 ) ) {
F_13 ( V_7 , L_5 ) ;
goto V_23;
}
V_7 -> V_24 = 0 ;
for ( V_20 = 0 ; V_20 < V_18 ; ++ V_20 ) {
struct V_16 * V_25 = & V_17 [ V_20 ] ;
struct V_26 * V_27 ;
V_5 = F_3 ( V_7 , V_25 -> V_8 ) ;
if ( V_5 == NULL )
continue;
V_27 = F_16 ( sizeof *V_27 , V_28 ) ;
if ( V_27 == NULL ) {
F_13 ( V_7 , L_6 ,
V_25 -> V_29 ) ;
V_11 = - V_30 ;
goto V_31;
}
F_10 ( V_27 -> V_15 , V_25 -> V_29 , sizeof( V_27 -> V_15 ) ) ;
V_27 -> V_5 = V_5 ;
V_27 -> V_32 = V_25 -> V_32 ;
V_7 -> V_33 [ V_7 -> V_24 ++ ] = V_27 ;
F_17 ( V_7 , L_7 ,
V_25 -> V_29 , V_25 -> V_8 ) ;
if ( V_7 -> V_24 >= V_34 )
break;
}
if ( V_7 -> V_24 == 0 ) {
F_13 ( V_7 , L_8 ) ;
V_11 = - V_35 ;
goto V_36;
}
return 0 ;
V_31:
for ( V_20 = 0 ; V_20 < V_7 -> V_24 ; ++ V_20 )
F_18 ( V_7 -> V_33 [ V_20 ] ) ;
memset ( V_7 -> V_33 , 0 , sizeof V_7 -> V_33 ) ;
V_36:
F_19 ( V_7 -> V_22 ) ;
V_23:
F_20 ( V_14 ) ;
V_21:
return V_11 ;
}
void T_2 F_21 ( struct V_6 * V_7 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_7 -> V_24 ; ++ V_20 )
F_18 ( V_7 -> V_33 [ V_20 ] ) ;
F_19 ( V_7 -> V_22 ) ;
F_20 ( & V_7 -> V_14 ) ;
}
static int F_22 ( struct V_37 * V_37 , void * V_38 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
F_10 ( V_40 -> V_44 , V_45 , sizeof V_40 -> V_44 ) ;
F_10 ( V_40 -> V_46 , V_42 -> V_47 . V_15 , sizeof V_40 -> V_46 ) ;
sprintf ( V_40 -> V_48 , L_10 , V_42 -> V_49 ) ;
V_40 -> V_50 = F_25 ( 0 , 1 , 0 ) ;
V_40 -> V_51 = V_52 |
V_53 | V_54 ;
return 0 ;
}
static void F_26 ( struct V_41 * V_42 )
{
struct V_6 * V_7 = V_42 -> V_7 ;
struct V_55 V_56 ;
F_27 ( V_7 , & V_56 ) ;
V_42 -> V_57 . V_58 . V_59 = V_56 . V_60 ;
V_42 -> V_57 . V_58 . V_61 = V_56 . V_62 ;
V_42 -> V_57 . V_58 . V_63 = V_56 . V_63 ;
V_42 -> V_64 . V_65 ( V_42 ) ;
}
static void F_28 ( struct V_41 * V_42 )
{
struct V_6 * V_7 = V_42 -> V_7 ;
struct V_55 V_56 ;
memset ( & V_42 -> V_57 , 0 , sizeof V_42 -> V_57 ) ;
F_27 ( V_7 , & V_56 ) ;
V_42 -> V_57 . V_58 . V_59 = V_56 . V_60 ;
V_42 -> V_57 . V_58 . V_61 = V_56 . V_62 ;
V_42 -> V_57 . V_58 . V_60 = V_42 -> V_57 . V_58 . V_59 ;
V_42 -> V_57 . V_58 . V_62 = V_42 -> V_57 . V_58 . V_61 ;
V_42 -> V_57 . V_58 . V_63 = V_56 . V_63 ;
V_42 -> V_57 . V_66 . V_59 = V_56 . V_60 ;
V_42 -> V_57 . V_66 . V_61 = V_56 . V_62 ;
V_42 -> V_57 . V_66 . V_60 = V_42 -> V_57 . V_66 . V_59 ;
V_42 -> V_57 . V_66 . V_62 = V_42 -> V_57 . V_66 . V_61 ;
V_42 -> V_64 . V_65 ( V_42 ) ;
}
static void F_29 ( struct V_6 * V_7 , struct V_67 * V_57 )
{
F_24 ( V_7 , L_11 ,
V_57 -> V_66 . V_59 , V_57 -> V_66 . V_61 ) ;
F_24 ( V_7 , L_12 ,
V_57 -> V_66 . V_60 , V_57 -> V_66 . V_62 ) ;
F_24 ( V_7 , L_13 ,
V_57 -> V_66 . V_68 , V_57 -> V_66 . V_69 ) ;
F_24 ( V_7 , L_14 ,
V_57 -> V_58 . V_59 , V_57 -> V_58 . V_61 ) ;
F_24 ( V_7 , L_15 ,
V_57 -> V_58 . V_60 , V_57 -> V_58 . V_62 ) ;
F_24 ( V_7 , L_16 ,
V_57 -> V_58 . V_68 , V_57 -> V_58 . V_69 ) ;
F_24 ( V_7 , L_17 ,
V_57 -> V_70 , V_57 -> V_71 ) ;
}
static int F_30 ( struct V_37 * V_37 , void * V_38 ,
struct V_72 * V_73 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
const struct V_74 * V_75 ;
F_24 ( V_7 , L_18 , V_43 ) ;
V_75 = F_31 ( V_42 , V_73 -> V_76 ) ;
if ( V_75 == NULL )
return - V_77 ;
F_10 ( V_73 -> V_78 , V_75 -> V_15 , sizeof( V_73 -> V_78 ) ) ;
V_73 -> V_79 = V_75 -> V_80 ;
return 0 ;
}
static int F_32 ( struct V_37 * V_37 , void * V_38 ,
struct V_81 * V_73 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
const struct V_74 * V_75 ;
struct V_82 * V_83 ;
struct V_6 * V_7 = V_42 -> V_7 ;
struct V_67 * V_57 = & V_42 -> V_57 ;
F_24 ( V_7 , L_9 , V_43 , __LINE__ ) ;
V_83 = & V_73 -> V_75 . V_84 ;
V_75 = F_33 ( V_42 , V_83 -> V_79 ) ;
if ( V_75 == NULL ) {
F_5 ( V_7 , L_19 ,
V_83 -> V_79 ) ;
return - V_77 ;
}
V_42 -> V_75 = V_75 ;
V_57 -> V_66 . V_59 = V_83 -> V_60 ;
V_57 -> V_66 . V_60 = V_83 -> V_60 ;
V_57 -> V_66 . V_61 = V_83 -> V_62 ;
V_57 -> V_66 . V_62 = V_83 -> V_62 ;
F_26 ( V_42 ) ;
F_24 ( V_7 , L_20 ,
V_57 -> V_66 . V_60 , V_57 -> V_66 . V_62 , V_57 -> V_66 . V_59 ) ;
return 0 ;
}
static unsigned int F_34 ( unsigned int V_85 , unsigned int V_86 )
{
return ( V_85 + V_86 - 1 ) / V_86 ;
}
unsigned long F_35 ( const struct V_87 * V_88 ,
unsigned int V_60 , unsigned int V_62 )
{
unsigned int V_89 = F_34 ( V_60 , V_88 -> V_60 ) ;
unsigned int V_90 = F_34 ( V_62 , V_88 -> V_62 ) ;
return V_89 * V_90 * V_88 -> V_91 ;
}
static void F_36 ( struct V_92 * V_93 ,
const struct V_74 * V_75 , T_3 V_60 , T_3 V_62 )
{
int V_20 ;
memset ( V_93 , 0 , sizeof( * V_93 ) * V_75 -> V_94 ) ;
for ( V_20 = 0 ; V_20 < V_75 -> V_95 ; ++ V_20 ) {
struct V_92 * V_96 = V_93
+ V_75 -> V_97 [ V_20 ] ;
const struct V_87 * V_88 = & V_75 -> V_96 [ V_20 ] ;
T_3 V_89 = F_34 ( V_60 , V_88 -> V_60 ) ;
T_3 V_90 = F_34 ( V_62 , V_88 -> V_62 ) ;
T_3 V_98 = V_89 * V_90 * V_88 -> V_91 ;
T_4 V_99 = V_89 * V_88 -> V_91 / V_88 -> V_62 ;
V_96 -> V_98 += V_98 ;
V_96 -> V_99 = F_37 ( V_96 -> V_99 , V_99 ) ;
}
}
static int F_38 ( struct V_37 * V_37 , void * V_38 ,
struct V_81 * V_73 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_82 * V_83 = & V_73 -> V_75 . V_84 ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
V_83 -> V_60 = V_42 -> V_57 . V_66 . V_59 ;
V_83 -> V_62 = V_42 -> V_57 . V_66 . V_61 ;
V_83 -> V_63 = V_100 ;
V_83 -> V_79 = V_42 -> V_75 -> V_80 ;
V_83 -> V_101 = V_42 -> V_75 -> V_101 ;
F_36 ( V_83 -> V_102 , V_42 -> V_75 , V_83 -> V_60 , V_83 -> V_62 ) ;
return 0 ;
}
static inline struct V_103 * F_39 ( struct V_67 * V_57 ,
enum V_104 type )
{
switch ( type ) {
case V_105 :
case V_106 :
return & V_57 -> V_58 ;
case V_107 :
return & V_57 -> V_66 ;
default:
return NULL ;
}
}
static int F_40 ( struct V_37 * V_37 , void * V_108 , struct V_109 * V_110 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_103 * V_111 ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
V_111 = F_39 ( & V_42 -> V_57 , V_110 -> type ) ;
if ( V_111 == NULL )
return - V_77 ;
F_26 ( V_42 ) ;
V_110 -> V_112 . V_113 = V_111 -> V_68 ;
V_110 -> V_112 . V_114 = V_111 -> V_69 ;
V_110 -> V_112 . V_60 = V_111 -> V_60 ;
V_110 -> V_112 . V_62 = V_111 -> V_62 ;
return 0 ;
}
static int F_41 ( struct V_37 * V_37 , void * V_108 , struct V_109 * V_110 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_103 * V_111 ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
V_111 = F_39 ( & V_42 -> V_57 , V_110 -> type ) ;
if ( V_111 == NULL )
return - V_77 ;
V_111 -> V_68 = V_110 -> V_112 . V_113 ;
V_111 -> V_69 = V_110 -> V_112 . V_114 ;
V_111 -> V_60 = V_110 -> V_112 . V_60 ;
V_111 -> V_62 = V_110 -> V_112 . V_62 ;
F_26 ( V_42 ) ;
return 0 ;
}
static int F_42 ( struct V_37 * V_37 , void * V_108 , struct V_115 * V_110 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_103 * V_111 ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
V_111 = F_39 ( & V_42 -> V_57 , V_110 -> type ) ;
if ( V_111 == NULL )
return - V_77 ;
F_26 ( V_42 ) ;
V_110 -> V_116 . V_113 = 0 ;
V_110 -> V_116 . V_114 = 0 ;
V_110 -> V_116 . V_60 = V_111 -> V_59 ;
V_110 -> V_116 . V_114 = V_111 -> V_61 ;
V_110 -> V_117 = V_110 -> V_116 ;
V_110 -> V_118 . V_119 = 1 ;
V_110 -> V_118 . V_120 = 1 ;
return 0 ;
}
static int F_43 ( struct V_37 * V_37 , void * V_108 ,
struct V_121 * V_122 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 ;
F_44 ( & V_7 -> V_123 ) ;
V_11 = F_45 ( F_46 ( V_7 ) , V_124 , V_125 , V_122 ) ;
F_47 ( & V_7 -> V_123 ) ;
return V_11 ? - V_77 : 0 ;
}
static int F_48 ( struct V_37 * V_37 , void * V_108 ,
struct V_126 * V_122 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 ;
F_44 ( & V_7 -> V_123 ) ;
if ( V_7 -> V_127 > 0 ) {
F_47 ( & V_7 -> V_123 ) ;
return - V_128 ;
}
V_11 = F_45 ( F_46 ( V_7 ) , V_124 , V_129 , V_122 ) ;
F_47 ( & V_7 -> V_123 ) ;
return V_11 ? - V_77 : 0 ;
}
static int F_49 ( struct V_37 * V_37 , void * V_108 ,
struct V_126 * V_122 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 ;
F_44 ( & V_7 -> V_123 ) ;
V_11 = F_45 ( F_46 ( V_7 ) , V_124 , V_130 , V_122 ) ;
F_47 ( & V_7 -> V_123 ) ;
return V_11 ? - V_77 : 0 ;
}
static int F_50 ( struct V_37 * V_37 , void * V_108 , T_5 * V_131 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 ;
F_44 ( & V_7 -> V_123 ) ;
if ( V_7 -> V_127 > 0 ) {
F_47 ( & V_7 -> V_123 ) ;
return - V_128 ;
}
V_11 = F_45 ( F_46 ( V_7 ) , V_124 , V_132 , * V_131 ) ;
F_47 ( & V_7 -> V_123 ) ;
return V_11 ? - V_77 : 0 ;
}
static int F_51 ( struct V_37 * V_37 , void * V_108 , T_5 * V_131 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 ;
F_44 ( & V_7 -> V_123 ) ;
V_11 = F_45 ( F_46 ( V_7 ) , V_124 , V_133 , V_131 ) ;
F_47 ( & V_7 -> V_123 ) ;
return V_11 ? - V_77 : 0 ;
}
static int F_52 ( struct V_37 * V_37 , void * V_108 , struct V_134 * V_110 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
struct V_26 * V_27 ;
struct V_4 * V_5 ;
if ( V_110 -> V_76 >= V_7 -> V_24 )
return - V_77 ;
V_27 = V_7 -> V_33 [ V_110 -> V_76 ] ;
F_53 ( V_27 == NULL ) ;
V_5 = V_27 -> V_5 ;
F_10 ( V_110 -> V_15 , V_27 -> V_15 , sizeof( V_110 -> V_15 ) ) ;
F_45 ( V_5 , V_124 , V_135 , & V_110 -> V_136 ) ;
V_110 -> V_51 = 0 ;
if ( V_5 -> V_64 -> V_124 && V_5 -> V_64 -> V_124 -> V_129 )
V_110 -> V_51 |= V_137 ;
if ( V_5 -> V_64 -> V_124 && V_5 -> V_64 -> V_124 -> V_132 )
V_110 -> V_51 |= V_138 ;
V_110 -> type = V_139 ;
return 0 ;
}
static int F_54 ( struct V_37 * V_37 , void * V_108 , unsigned int V_20 )
{
struct V_140 * V_47 = F_55 ( V_37 ) ;
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 = 0 ;
if ( V_20 >= V_7 -> V_24 || V_7 -> V_33 [ V_20 ] == NULL )
return - V_77 ;
F_44 ( & V_7 -> V_123 ) ;
if ( V_7 -> V_127 > 0 ) {
V_11 = - V_128 ;
goto V_13;
}
V_7 -> V_141 = V_20 ;
V_47 -> V_142 = 0 ;
F_45 ( F_46 ( V_7 ) , V_124 , V_135 ,
& V_47 -> V_142 ) ;
F_24 ( V_7 , L_21 , V_47 -> V_142 ) ;
V_13:
F_47 ( & V_7 -> V_123 ) ;
return V_11 ;
}
static int F_56 ( struct V_37 * V_37 , void * V_108 , unsigned int * V_3 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
F_44 ( & V_7 -> V_123 ) ;
* V_3 = V_7 -> V_141 ;
F_47 ( & V_7 -> V_123 ) ;
return 0 ;
}
static int F_57 ( struct V_37 * V_37 , void * V_38 ,
struct V_143 * V_3 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
return F_58 ( & V_42 -> V_144 , V_3 ) ;
}
static int F_59 ( struct V_37 * V_37 , void * V_38 , struct V_145 * V_3 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
return F_60 ( & V_42 -> V_144 , V_3 ) ;
}
static int F_61 ( struct V_37 * V_37 , void * V_38 , struct V_145 * V_3 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_22 , V_43 , __LINE__ , V_3 -> V_76 ) ;
return F_62 ( & V_42 -> V_144 , V_3 ) ;
}
static int F_63 ( struct V_37 * V_37 , void * V_38 , struct V_145 * V_3 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
return F_64 ( & V_42 -> V_144 , V_3 , V_37 -> V_146 & V_147 ) ;
}
static int F_65 ( struct V_37 * V_37 , void * V_38 , enum V_104 V_20 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
return F_66 ( & V_42 -> V_144 , V_20 ) ;
}
static int F_67 ( struct V_37 * V_37 , void * V_38 , enum V_104 V_20 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
return F_68 ( & V_42 -> V_144 , V_20 ) ;
}
static int F_69 ( struct V_37 * V_37 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 = 0 ;
F_24 ( V_7 , L_9 , V_43 , __LINE__ ) ;
F_70 () ;
V_11 = F_71 ( V_37 ) ;
if ( V_11 ) {
F_13 ( V_7 , L_23 ) ;
return V_11 ;
}
if ( ! F_72 ( V_37 ) )
return 0 ;
V_11 = F_73 ( V_7 ) ;
if ( V_11 ) {
F_13 ( V_7 , L_24 ) ;
goto V_148;
}
V_11 = F_74 ( & V_42 -> V_144 ) ;
if ( V_11 != 0 ) {
F_13 ( V_7 , L_25 ) ;
goto V_149;
}
V_42 -> V_75 = V_42 -> V_150 [ 0 ] ;
F_28 ( V_42 ) ;
return 0 ;
V_149:
F_75 ( V_7 ) ;
V_148:
F_76 ( V_37 ) ;
return V_11 ;
}
static unsigned int
F_77 ( struct V_37 * V_37 , struct V_151 * V_152 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
return F_78 ( & V_42 -> V_144 , V_37 , V_152 ) ;
}
static int F_79 ( struct V_37 * V_37 , struct V_153 * V_154 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
return F_80 ( & V_42 -> V_144 , V_154 ) ;
}
static int F_81 ( struct V_37 * V_37 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
if ( F_72 ( V_37 ) ) {
F_82 ( & V_42 -> V_144 ) ;
F_75 ( V_42 -> V_7 ) ;
}
F_76 ( V_37 ) ;
return 0 ;
}
static int F_83 ( struct V_155 * V_156 , const struct V_81 * V_157 ,
unsigned int * V_158 , unsigned int * V_159 , unsigned int V_160 [] ,
void * V_161 [] )
{
struct V_41 * V_42 = F_84 ( V_156 ) ;
const struct V_74 * V_75 = V_42 -> V_75 ;
int V_20 ;
struct V_6 * V_7 = V_42 -> V_7 ;
struct V_92 V_93 [ 3 ] ;
F_24 ( V_7 , L_18 , V_43 ) ;
if ( V_75 == NULL )
return - V_77 ;
F_24 ( V_7 , L_26 , V_75 -> V_15 ) ;
F_36 ( V_93 , V_75 , V_42 -> V_57 . V_66 . V_59 ,
V_42 -> V_57 . V_66 . V_61 ) ;
* V_159 = V_75 -> V_94 ;
for ( V_20 = 0 ; V_20 < V_75 -> V_94 ; ++ V_20 ) {
V_161 [ V_20 ] = V_42 -> V_7 -> V_22 ;
V_160 [ V_20 ] = F_85 ( V_93 [ V_20 ] . V_98 ) ;
F_24 ( V_7 , L_27 , V_20 , V_160 [ V_20 ] ) ;
}
if ( * V_158 == 0 )
* V_158 = 1 ;
return 0 ;
}
static void F_86 ( struct V_162 * V_163 )
{
struct V_164 * V_165 = F_87 ( V_163 , struct V_164 , V_163 ) ;
struct V_41 * V_42 = F_84 ( V_163 -> V_155 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
unsigned long V_166 ;
F_88 ( & V_42 -> V_167 , V_166 ) ;
F_89 ( & V_165 -> V_168 , & V_42 -> V_169 ) ;
F_90 ( & V_42 -> V_167 , V_166 ) ;
F_24 ( V_7 , L_28 ) ;
}
static void F_91 ( struct V_155 * V_156 )
{
struct V_41 * V_42 = F_84 ( V_156 ) ;
F_24 ( V_42 -> V_7 , L_18 , V_43 ) ;
F_44 ( & V_42 -> V_123 ) ;
}
static void F_92 ( struct V_155 * V_156 )
{
struct V_41 * V_42 = F_84 ( V_156 ) ;
F_24 ( V_42 -> V_7 , L_18 , V_43 ) ;
F_47 ( & V_42 -> V_123 ) ;
}
static int F_93 ( struct V_155 * V_156 , unsigned int V_170 )
{
struct V_41 * V_42 = F_84 ( V_156 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
unsigned long V_166 ;
F_24 ( V_7 , L_18 , V_43 ) ;
if ( V_170 == 0 ) {
F_24 ( V_7 , L_29 ) ;
return - V_77 ;
}
F_94 ( V_7 ) ;
F_26 ( V_42 ) ;
F_29 ( V_7 , & V_42 -> V_57 ) ;
V_42 -> V_64 . V_171 ( V_42 ) ;
F_88 ( & V_42 -> V_167 , V_166 ) ;
V_42 -> V_172 = V_173 ;
F_90 ( & V_42 -> V_167 , V_166 ) ;
V_42 -> V_64 . V_174 ( V_42 , V_175 ) ;
F_95 ( V_7 ) ;
return 0 ;
}
static void F_96 ( unsigned long V_176 )
{
struct V_41 * V_42 = (struct V_41 * ) V_176 ;
struct V_6 * V_7 = V_42 -> V_7 ;
unsigned long V_166 ;
F_13 ( V_7 , L_30 , V_42 -> V_47 . V_15 ) ;
F_88 ( & V_42 -> V_167 , V_166 ) ;
if ( V_42 -> V_177 == V_42 -> V_178 )
V_42 -> V_177 = NULL ;
if ( V_42 -> V_177 ) {
F_97 ( & V_42 -> V_177 -> V_163 , V_179 ) ;
V_42 -> V_177 = NULL ;
}
if ( V_42 -> V_178 ) {
F_97 ( & V_42 -> V_178 -> V_163 , V_179 ) ;
V_42 -> V_178 = NULL ;
}
F_90 ( & V_42 -> V_167 , V_166 ) ;
}
static int F_98 ( struct V_155 * V_156 )
{
struct V_41 * V_42 = F_84 ( V_156 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
unsigned long V_166 ;
struct V_180 V_181 ;
struct V_164 * V_182 , * V_183 ;
F_24 ( V_7 , L_18 , V_43 ) ;
F_88 ( & V_42 -> V_167 , V_166 ) ;
V_42 -> V_172 = V_184 ;
F_99 (buf, buf_tmp, &layer->enq_list, list) {
F_100 ( & V_182 -> V_168 ) ;
F_97 ( & V_182 -> V_163 , V_179 ) ;
}
F_90 ( & V_42 -> V_167 , V_166 ) ;
F_101 ( & V_181 , F_96 ,
( unsigned long ) V_42 ) ;
F_102 ( & V_181 , V_185 + F_103 ( 1000 ) ) ;
F_104 ( V_156 ) ;
F_105 ( & V_181 ) ;
F_106 ( & V_181 ) ;
F_88 ( & V_42 -> V_167 , V_166 ) ;
V_42 -> V_172 = V_186 ;
F_90 ( & V_42 -> V_167 , V_166 ) ;
V_42 -> V_64 . V_174 ( V_42 , V_187 ) ;
F_107 ( V_7 ) ;
F_108 ( V_7 ) ;
return 0 ;
}
int F_109 ( struct V_41 * V_42 )
{
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 ;
V_11 = F_110 ( & V_42 -> V_47 , V_188 , - 1 ) ;
if ( V_11 )
F_13 ( V_7 , L_31 ) ;
else
F_17 ( V_7 , L_32 ,
V_42 -> V_47 . V_15 , V_42 -> V_47 . V_189 ) ;
return V_11 ;
}
void F_111 ( struct V_41 * V_42 )
{
F_112 ( & V_42 -> V_47 ) ;
}
void F_113 ( struct V_41 * V_42 )
{
if ( V_42 -> V_64 . V_190 )
V_42 -> V_64 . V_190 ( V_42 ) ;
}
void F_114 ( struct V_41 * V_42 )
{
F_18 ( V_42 ) ;
}
static void F_115 ( struct V_140 * V_191 )
{
F_116 ( V_192 L_33 ) ;
}
struct V_41 * F_117 ( struct V_6 * V_7 ,
int V_49 , char * V_15 , struct V_193 * V_64 )
{
struct V_41 * V_42 ;
V_42 = F_16 ( sizeof *V_42 , V_28 ) ;
if ( V_42 == NULL ) {
F_13 ( V_7 , L_34 ) ;
goto V_21;
}
V_42 -> V_7 = V_7 ;
V_42 -> V_49 = V_49 ;
V_42 -> V_64 = * V_64 ;
F_118 ( & V_42 -> V_167 ) ;
F_119 ( & V_42 -> V_169 ) ;
F_120 ( & V_42 -> V_123 ) ;
V_42 -> V_47 = (struct V_140 ) {
. V_194 = - 1 ,
. V_190 = F_115 ,
. V_195 = & V_196 ,
. V_197 = & V_198 ,
} ;
F_10 ( V_42 -> V_47 . V_15 , V_15 , sizeof( V_42 -> V_47 . V_15 ) ) ;
F_121 ( V_199 , & V_42 -> V_47 . V_166 ) ;
F_122 ( & V_42 -> V_47 , V_42 ) ;
V_42 -> V_47 . V_200 = & V_42 -> V_123 ;
V_42 -> V_47 . V_14 = & V_7 -> V_14 ;
V_42 -> V_144 = (struct V_155 ) {
. type = V_106 ,
. V_201 = V_202 | V_203 ,
. V_204 = V_42 ,
. V_205 = sizeof( struct V_164 ) ,
. V_64 = & V_206 ,
. V_207 = & V_208 ,
} ;
return V_42 ;
V_21:
return NULL ;
}
static const struct V_74 * F_33 (
struct V_41 * V_42 , unsigned long V_80 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_42 -> V_209 ; ++ V_20 )
if ( V_42 -> V_150 [ V_20 ] -> V_80 == V_80 )
return V_42 -> V_150 [ V_20 ] ;
return NULL ;
}
static const struct V_74 * F_31 (
struct V_41 * V_42 , unsigned long V_76 )
{
if ( V_76 >= V_42 -> V_209 )
return NULL ;
return V_42 -> V_150 [ V_76 ] ;
}

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
return V_5 ;
}
int F_8 ( struct V_6 * V_7 ,
struct V_16 * V_17 , int V_18 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_19 * V_14 = & V_7 -> V_14 ;
int V_20 ;
int V_11 = 0 ;
struct V_4 * V_5 ;
F_9 ( V_14 -> V_15 , F_10 ( V_7 -> V_2 ) , sizeof( V_14 -> V_15 ) ) ;
V_11 = F_11 ( V_2 , V_14 ) ;
if ( V_11 ) {
F_12 ( V_7 , L_4 ) ;
goto V_21;
}
F_13 ( V_7 -> V_2 , F_14 ( 32 ) ) ;
V_7 -> V_22 = 0 ;
for ( V_20 = 0 ; V_20 < V_18 ; ++ V_20 ) {
struct V_16 * V_23 = & V_17 [ V_20 ] ;
struct V_24 * V_25 ;
V_5 = F_3 ( V_7 , V_23 -> V_8 ) ;
if ( V_5 == NULL )
continue;
V_25 = F_15 ( sizeof( * V_25 ) , V_26 ) ;
if ( V_25 == NULL ) {
F_12 ( V_7 , L_5 ,
V_23 -> V_27 ) ;
V_11 = - V_28 ;
goto V_29;
}
F_9 ( V_25 -> V_15 , V_23 -> V_27 , sizeof( V_25 -> V_15 ) ) ;
V_25 -> V_5 = V_5 ;
V_25 -> V_30 = V_23 -> V_30 ;
V_7 -> V_31 [ V_7 -> V_22 ++ ] = V_25 ;
F_16 ( V_7 , L_6 ,
V_23 -> V_27 , V_23 -> V_8 ) ;
if ( V_7 -> V_22 >= V_32 )
break;
}
if ( V_7 -> V_22 == 0 ) {
F_12 ( V_7 , L_7 ) ;
V_11 = - V_33 ;
goto V_34;
}
return 0 ;
V_29:
for ( V_20 = 0 ; V_20 < V_7 -> V_22 ; ++ V_20 )
F_17 ( V_7 -> V_31 [ V_20 ] ) ;
memset ( V_7 -> V_31 , 0 , sizeof( V_7 -> V_31 ) ) ;
V_34:
F_18 ( V_14 ) ;
V_21:
return V_11 ;
}
void F_19 ( struct V_6 * V_7 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_7 -> V_22 ; ++ V_20 )
F_17 ( V_7 -> V_31 [ V_20 ] ) ;
F_20 ( V_7 -> V_2 ) ;
F_18 ( & V_7 -> V_14 ) ;
}
static int F_21 ( struct V_35 * V_35 , void * V_36 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
F_23 ( V_40 -> V_7 , L_8 , V_41 , __LINE__ ) ;
F_9 ( V_38 -> V_42 , V_43 , sizeof( V_38 -> V_42 ) ) ;
F_9 ( V_38 -> V_44 , V_40 -> V_45 . V_15 , sizeof( V_38 -> V_44 ) ) ;
sprintf ( V_38 -> V_46 , L_9 , V_40 -> V_47 ) ;
V_38 -> V_48 = V_49 | V_50 ;
V_38 -> V_51 = V_38 -> V_48 | V_52 ;
return 0 ;
}
static void F_24 ( struct V_6 * V_7 , struct V_53 * V_54 )
{
F_23 ( V_7 , L_10 ,
V_54 -> V_55 . V_56 , V_54 -> V_55 . V_57 ) ;
F_23 ( V_7 , L_11 ,
V_54 -> V_55 . V_58 , V_54 -> V_55 . V_59 ) ;
F_23 ( V_7 , L_12 ,
V_54 -> V_55 . V_60 , V_54 -> V_55 . V_61 ) ;
F_23 ( V_7 , L_13 ,
V_54 -> V_62 . V_56 , V_54 -> V_62 . V_57 ) ;
F_23 ( V_7 , L_14 ,
V_54 -> V_62 . V_58 , V_54 -> V_62 . V_59 ) ;
F_23 ( V_7 , L_15 ,
V_54 -> V_62 . V_60 , V_54 -> V_62 . V_61 ) ;
F_23 ( V_7 , L_16 ,
V_54 -> V_63 , V_54 -> V_64 ) ;
}
static void F_25 ( struct V_39 * V_40 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_65 V_66 ;
memset ( & V_40 -> V_54 , 0 , sizeof( V_40 -> V_54 ) ) ;
F_26 ( V_7 , & V_66 ) ;
V_40 -> V_54 . V_62 . V_56 = V_66 . V_58 ;
V_40 -> V_54 . V_62 . V_57 = V_66 . V_59 ;
V_40 -> V_54 . V_62 . V_58 = V_40 -> V_54 . V_62 . V_56 ;
V_40 -> V_54 . V_62 . V_59 = V_40 -> V_54 . V_62 . V_57 ;
V_40 -> V_54 . V_62 . V_67 = V_66 . V_67 ;
V_40 -> V_54 . V_55 . V_56 = V_66 . V_58 ;
V_40 -> V_54 . V_55 . V_57 = V_66 . V_59 ;
V_40 -> V_54 . V_55 . V_58 = V_40 -> V_54 . V_55 . V_56 ;
V_40 -> V_54 . V_55 . V_59 = V_40 -> V_54 . V_55 . V_57 ;
F_24 ( V_7 , & V_40 -> V_54 ) ;
V_40 -> V_68 . V_69 ( V_40 , V_70 , 0 ) ;
F_24 ( V_7 , & V_40 -> V_54 ) ;
}
static void F_27 ( struct V_39 * V_40 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_65 V_66 ;
F_26 ( V_7 , & V_66 ) ;
if ( V_40 -> V_54 . V_62 . V_56 == V_66 . V_58 &&
V_40 -> V_54 . V_62 . V_57 == V_66 . V_58 )
return;
V_40 -> V_54 . V_62 . V_56 = V_66 . V_58 ;
V_40 -> V_54 . V_62 . V_57 = V_66 . V_59 ;
V_40 -> V_54 . V_62 . V_67 = V_66 . V_67 ;
V_40 -> V_68 . V_69 ( V_40 , V_70 , 0 ) ;
F_24 ( V_7 , & V_40 -> V_54 ) ;
}
static int F_28 ( struct V_35 * V_35 , void * V_36 ,
struct V_71 * V_72 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
struct V_6 * V_7 = V_40 -> V_7 ;
const struct V_73 * V_74 ;
F_23 ( V_7 , L_17 , V_41 ) ;
V_74 = F_29 ( V_40 , V_72 -> V_75 ) ;
if ( V_74 == NULL )
return - V_76 ;
F_9 ( V_72 -> V_77 , V_74 -> V_15 , sizeof( V_72 -> V_77 ) ) ;
V_72 -> V_78 = V_74 -> V_79 ;
return 0 ;
}
static unsigned int F_30 ( unsigned int V_80 , unsigned int V_81 )
{
return ( V_80 + V_81 - 1 ) / V_81 ;
}
unsigned long F_31 ( const struct V_82 * V_83 ,
unsigned int V_58 , unsigned int V_59 )
{
unsigned int V_84 = F_30 ( V_58 , V_83 -> V_58 ) ;
unsigned int V_85 = F_30 ( V_59 , V_83 -> V_59 ) ;
return V_84 * V_85 * V_83 -> V_86 ;
}
static void F_32 ( struct V_87 * V_88 ,
const struct V_73 * V_74 , T_1 V_58 , T_1 V_59 )
{
int V_20 ;
if ( ! V_88 )
return;
memset ( V_88 , 0 , sizeof( * V_88 ) * V_74 -> V_89 ) ;
for ( V_20 = 0 ; V_20 < V_74 -> V_90 ; ++ V_20 ) {
struct V_87 * V_91 = V_88
+ V_74 -> V_92 [ V_20 ] ;
const struct V_82 * V_83 = & V_74 -> V_91 [ V_20 ] ;
T_1 V_84 = F_30 ( V_58 , V_83 -> V_58 ) ;
T_1 V_85 = F_30 ( V_59 , V_83 -> V_59 ) ;
T_1 V_93 = V_84 * V_85 * V_83 -> V_86 ;
T_1 V_94 = V_84 * V_83 -> V_86 / V_83 -> V_59 ;
V_91 -> V_93 += V_93 ;
V_91 -> V_94 = F_33 ( V_91 -> V_94 , V_94 ) ;
}
}
static int F_34 ( struct V_35 * V_35 , void * V_36 ,
struct V_95 * V_72 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
struct V_96 * V_97 = & V_72 -> V_74 . V_98 ;
F_23 ( V_40 -> V_7 , L_8 , V_41 , __LINE__ ) ;
V_97 -> V_58 = V_40 -> V_54 . V_55 . V_56 ;
V_97 -> V_59 = V_40 -> V_54 . V_55 . V_57 ;
V_97 -> V_67 = V_99 ;
V_97 -> V_78 = V_40 -> V_74 -> V_79 ;
V_97 -> V_100 = V_40 -> V_74 -> V_100 ;
F_32 ( V_97 -> V_101 , V_40 -> V_74 , V_97 -> V_58 , V_97 -> V_59 ) ;
return 0 ;
}
static int F_35 ( struct V_35 * V_35 , void * V_36 ,
struct V_95 * V_72 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
const struct V_73 * V_74 ;
struct V_96 * V_97 ;
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_53 * V_54 = & V_40 -> V_54 ;
F_23 ( V_7 , L_8 , V_41 , __LINE__ ) ;
V_97 = & V_72 -> V_74 . V_98 ;
V_74 = F_36 ( V_40 , V_97 -> V_78 ) ;
if ( V_74 == NULL ) {
F_5 ( V_7 , L_18 ,
V_97 -> V_78 ) ;
return - V_76 ;
}
V_40 -> V_74 = V_74 ;
V_54 -> V_55 . V_56 = F_33 ( V_54 -> V_62 . V_56 , V_97 -> V_58 ) ;
V_54 -> V_55 . V_57 = F_33 ( V_54 -> V_62 . V_57 , V_97 -> V_59 ) ;
V_40 -> V_68 . V_69 ( V_40 , V_102 , 0 ) ;
F_24 ( V_7 , & V_40 -> V_54 ) ;
V_54 -> V_55 . V_58 = V_97 -> V_58 ;
V_54 -> V_55 . V_59 = V_97 -> V_59 ;
V_54 -> V_55 . V_60 = 0 ;
V_54 -> V_55 . V_61 = 0 ;
V_40 -> V_68 . V_69 ( V_40 , V_103 , V_104 ) ;
F_24 ( V_7 , & V_40 -> V_54 ) ;
V_54 -> V_55 . V_56 = 0 ;
V_54 -> V_55 . V_57 = 0 ;
V_40 -> V_68 . V_69 ( V_40 , V_102 , 0 ) ;
F_24 ( V_7 , & V_40 -> V_54 ) ;
F_34 ( V_35 , V_36 , V_72 ) ;
return 0 ;
}
static int F_37 ( struct V_35 * V_35 , void * V_105 ,
struct V_106 * V_107 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
struct V_53 * V_54 = & V_40 -> V_54 ;
F_23 ( V_40 -> V_7 , L_8 , V_41 , __LINE__ ) ;
if ( V_107 -> type != V_108 &&
V_107 -> type != V_109 )
return - V_76 ;
switch ( V_107 -> V_110 ) {
case V_111 :
V_107 -> V_112 . V_113 = V_54 -> V_55 . V_60 ;
V_107 -> V_112 . V_114 = V_54 -> V_55 . V_61 ;
V_107 -> V_112 . V_58 = V_54 -> V_55 . V_58 ;
V_107 -> V_112 . V_59 = V_54 -> V_55 . V_59 ;
break;
case V_115 :
case V_116 :
V_107 -> V_112 . V_113 = 0 ;
V_107 -> V_112 . V_114 = 0 ;
V_107 -> V_112 . V_58 = V_54 -> V_55 . V_56 ;
V_107 -> V_112 . V_59 = V_54 -> V_55 . V_57 ;
break;
case V_117 :
case V_118 :
V_107 -> V_112 . V_113 = V_54 -> V_62 . V_60 ;
V_107 -> V_112 . V_114 = V_54 -> V_62 . V_61 ;
V_107 -> V_112 . V_58 = V_54 -> V_62 . V_58 ;
V_107 -> V_112 . V_59 = V_54 -> V_62 . V_59 ;
break;
case V_119 :
case V_120 :
V_107 -> V_112 . V_113 = 0 ;
V_107 -> V_112 . V_114 = 0 ;
V_107 -> V_112 . V_58 = V_54 -> V_62 . V_56 ;
V_107 -> V_112 . V_59 = V_54 -> V_62 . V_57 ;
break;
default:
return - V_76 ;
}
return 0 ;
}
static int F_38 ( struct V_121 * V_122 , struct V_121 * V_123 )
{
if ( V_122 -> V_113 < V_123 -> V_113 )
return 0 ;
if ( V_122 -> V_114 < V_123 -> V_114 )
return 0 ;
if ( V_122 -> V_113 + V_122 -> V_58 > V_123 -> V_113 + V_123 -> V_58 )
return 0 ;
if ( V_122 -> V_114 + V_122 -> V_59 > V_123 -> V_114 + V_123 -> V_59 )
return 0 ;
return 1 ;
}
static int F_39 ( struct V_35 * V_35 , void * V_105 ,
struct V_106 * V_107 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
struct V_53 * V_54 = & V_40 -> V_54 ;
struct V_124 * V_110 = NULL ;
enum V_125 V_126 ;
struct V_53 V_127 ;
struct V_121 V_128 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
F_23 ( V_40 -> V_7 , L_19 , V_41 ,
V_107 -> V_112 . V_58 , V_107 -> V_112 . V_59 , V_107 -> V_112 . V_113 , V_107 -> V_112 . V_114 ) ;
if ( V_107 -> type != V_108 &&
V_107 -> type != V_109 )
return - V_76 ;
switch ( V_107 -> V_110 ) {
case V_115 :
case V_116 :
V_128 . V_58 = V_54 -> V_55 . V_56 ;
V_128 . V_59 = V_54 -> V_55 . V_57 ;
break;
case V_119 :
case V_120 :
V_128 . V_58 = V_54 -> V_62 . V_56 ;
V_128 . V_59 = V_54 -> V_62 . V_57 ;
break;
case V_111 :
V_110 = & V_54 -> V_55 ;
V_126 = V_103 ;
break;
case V_117 :
case V_118 :
V_110 = & V_54 -> V_62 ;
V_126 = V_129 ;
break;
default:
return - V_76 ;
}
if ( V_110 ) {
memcpy ( & V_127 , V_54 , sizeof( V_127 ) ) ;
V_110 -> V_60 = V_107 -> V_112 . V_113 ;
V_110 -> V_61 = V_107 -> V_112 . V_114 ;
V_110 -> V_58 = V_107 -> V_112 . V_58 ;
V_110 -> V_59 = V_107 -> V_112 . V_59 ;
V_40 -> V_68 . V_69 ( V_40 , V_126 , V_107 -> V_130 ) ;
V_128 . V_113 = V_110 -> V_60 ;
V_128 . V_114 = V_110 -> V_61 ;
V_128 . V_58 = V_110 -> V_58 ;
V_128 . V_59 = V_110 -> V_59 ;
F_24 ( V_40 -> V_7 , & V_40 -> V_54 ) ;
}
if ( ( V_107 -> V_130 & V_131 ) && ! F_38 ( & V_128 , & V_107 -> V_112 ) )
goto V_21;
if ( ( V_107 -> V_130 & V_132 ) && ! F_38 ( & V_107 -> V_112 , & V_128 ) )
goto V_21;
V_107 -> V_112 = V_128 ;
return 0 ;
V_21:
if ( V_110 )
memcpy ( V_54 , & V_127 , sizeof( V_127 ) ) ;
return - V_133 ;
}
static int F_40 ( struct V_35 * V_35 , void * V_105 ,
struct V_134 * V_135 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
struct V_6 * V_7 = V_40 -> V_7 ;
int V_11 ;
V_135 -> V_136 = 0 ;
F_41 ( & V_7 -> V_137 ) ;
V_11 = F_42 ( F_43 ( V_7 ) , V_136 , V_138 , V_135 ) ;
F_44 ( & V_7 -> V_137 ) ;
return V_11 ? - V_76 : 0 ;
}
static int F_45 ( struct V_35 * V_35 , void * V_105 ,
struct V_139 * V_135 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
struct V_6 * V_7 = V_40 -> V_7 ;
int V_11 ;
F_41 ( & V_7 -> V_137 ) ;
if ( V_7 -> V_140 > 0 ) {
F_44 ( & V_7 -> V_137 ) ;
return - V_141 ;
}
V_11 = F_42 ( F_43 ( V_7 ) , V_142 , V_143 , V_135 ) ;
F_44 ( & V_7 -> V_137 ) ;
F_27 ( V_40 ) ;
return V_11 ? - V_76 : 0 ;
}
static int F_46 ( struct V_35 * V_35 , void * V_105 ,
struct V_139 * V_135 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
struct V_6 * V_7 = V_40 -> V_7 ;
int V_11 ;
F_41 ( & V_7 -> V_137 ) ;
V_11 = F_42 ( F_43 ( V_7 ) , V_142 , V_144 , V_135 ) ;
F_44 ( & V_7 -> V_137 ) ;
return V_11 ? - V_76 : 0 ;
}
static int F_47 ( struct V_35 * V_35 , void * V_105 ,
struct V_145 * V_38 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
struct V_6 * V_7 = V_40 -> V_7 ;
int V_11 ;
V_38 -> V_136 = 0 ;
F_41 ( & V_7 -> V_137 ) ;
V_11 = F_42 ( F_43 ( V_7 ) , V_136 , V_146 , V_38 ) ;
F_44 ( & V_7 -> V_137 ) ;
return V_11 ? - V_76 : 0 ;
}
static int F_48 ( struct V_35 * V_35 , void * V_105 , T_2 V_147 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
struct V_6 * V_7 = V_40 -> V_7 ;
int V_11 ;
F_41 ( & V_7 -> V_137 ) ;
if ( V_7 -> V_140 > 0 ) {
F_44 ( & V_7 -> V_137 ) ;
return - V_141 ;
}
V_11 = F_42 ( F_43 ( V_7 ) , V_142 , V_148 , V_147 ) ;
F_44 ( & V_7 -> V_137 ) ;
F_27 ( V_40 ) ;
return V_11 ? - V_76 : 0 ;
}
static int F_49 ( struct V_35 * V_35 , void * V_105 , T_2 * V_147 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
struct V_6 * V_7 = V_40 -> V_7 ;
int V_11 ;
F_41 ( & V_7 -> V_137 ) ;
V_11 = F_42 ( F_43 ( V_7 ) , V_142 , V_149 , V_147 ) ;
F_44 ( & V_7 -> V_137 ) ;
return V_11 ? - V_76 : 0 ;
}
static int F_50 ( struct V_35 * V_35 , void * V_105 , struct V_150 * V_122 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_24 * V_25 ;
struct V_4 * V_5 ;
if ( V_122 -> V_75 >= V_7 -> V_22 )
return - V_76 ;
V_25 = V_7 -> V_31 [ V_122 -> V_75 ] ;
F_51 ( V_25 == NULL ) ;
V_5 = V_25 -> V_5 ;
F_9 ( V_122 -> V_15 , V_25 -> V_15 , sizeof( V_122 -> V_15 ) ) ;
F_42 ( V_5 , V_142 , V_151 , & V_122 -> V_152 ) ;
V_122 -> V_51 = 0 ;
if ( V_5 -> V_68 -> V_142 && V_5 -> V_68 -> V_142 -> V_143 )
V_122 -> V_51 |= V_153 ;
if ( V_5 -> V_68 -> V_142 && V_5 -> V_68 -> V_142 -> V_148 )
V_122 -> V_51 |= V_154 ;
V_122 -> type = V_155 ;
return 0 ;
}
static int F_52 ( struct V_35 * V_35 , void * V_105 , unsigned int V_20 )
{
struct V_156 * V_45 = F_53 ( V_35 ) ;
struct V_39 * V_40 = F_22 ( V_35 ) ;
struct V_6 * V_7 = V_40 -> V_7 ;
if ( V_20 >= V_7 -> V_22 || V_7 -> V_31 [ V_20 ] == NULL )
return - V_76 ;
F_41 ( & V_7 -> V_137 ) ;
if ( V_7 -> V_140 > 0 ) {
F_44 ( & V_7 -> V_137 ) ;
return - V_141 ;
}
V_7 -> V_157 = V_20 ;
V_45 -> V_158 = 0 ;
F_42 ( F_43 ( V_7 ) , V_142 , V_151 ,
& V_45 -> V_158 ) ;
F_44 ( & V_7 -> V_137 ) ;
F_27 ( V_40 ) ;
F_23 ( V_7 , L_20 , V_45 -> V_158 ) ;
return 0 ;
}
static int F_54 ( struct V_35 * V_35 , void * V_105 , unsigned int * V_3 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
struct V_6 * V_7 = V_40 -> V_7 ;
F_41 ( & V_7 -> V_137 ) ;
* V_3 = V_7 -> V_157 ;
F_44 ( & V_7 -> V_137 ) ;
return 0 ;
}
static int F_55 ( struct V_35 * V_35 , void * V_36 ,
struct V_159 * V_3 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
F_23 ( V_40 -> V_7 , L_8 , V_41 , __LINE__ ) ;
return F_56 ( & V_40 -> V_160 , V_3 ) ;
}
static int F_57 ( struct V_35 * V_35 , void * V_36 , struct V_161 * V_3 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
F_23 ( V_40 -> V_7 , L_8 , V_41 , __LINE__ ) ;
return F_58 ( & V_40 -> V_160 , V_3 ) ;
}
static int F_59 ( struct V_35 * V_35 , void * V_36 , struct V_161 * V_3 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
F_23 ( V_40 -> V_7 , L_21 , V_41 , __LINE__ , V_3 -> V_75 ) ;
return F_60 ( & V_40 -> V_160 , V_3 ) ;
}
static int F_61 ( struct V_35 * V_35 , void * V_36 , struct V_161 * V_3 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
F_23 ( V_40 -> V_7 , L_8 , V_41 , __LINE__ ) ;
return F_62 ( & V_40 -> V_160 , V_3 , V_35 -> V_162 & V_163 ) ;
}
static int F_63 ( struct V_35 * V_35 , void * V_36 ,
struct V_164 * V_165 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
F_23 ( V_40 -> V_7 , L_8 , V_41 , __LINE__ ) ;
return F_64 ( & V_40 -> V_160 , V_165 ) ;
}
static int F_65 ( struct V_35 * V_35 , void * V_36 , enum V_166 V_20 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
F_23 ( V_40 -> V_7 , L_8 , V_41 , __LINE__ ) ;
return F_66 ( & V_40 -> V_160 , V_20 ) ;
}
static int F_67 ( struct V_35 * V_35 , void * V_36 , enum V_166 V_20 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
F_23 ( V_40 -> V_7 , L_8 , V_41 , __LINE__ ) ;
return F_68 ( & V_40 -> V_160 , V_20 ) ;
}
static int F_69 ( struct V_35 * V_35 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
struct V_6 * V_7 = V_40 -> V_7 ;
int V_11 = 0 ;
F_23 ( V_7 , L_8 , V_41 , __LINE__ ) ;
if ( F_70 ( & V_40 -> V_137 ) )
return - V_167 ;
F_71 () ;
V_11 = F_72 ( V_35 ) ;
if ( V_11 ) {
F_12 ( V_7 , L_22 ) ;
goto V_168;
}
if ( ! F_73 ( V_35 ) )
goto V_168;
V_11 = F_74 ( V_7 ) ;
if ( V_11 ) {
F_12 ( V_7 , L_23 ) ;
goto V_169;
}
V_11 = F_75 ( & V_40 -> V_160 ) ;
if ( V_11 != 0 ) {
F_12 ( V_7 , L_24 ) ;
goto V_170;
}
V_40 -> V_74 = V_40 -> V_171 [ 0 ] ;
F_25 ( V_40 ) ;
F_44 ( & V_40 -> V_137 ) ;
return 0 ;
V_170:
F_76 ( V_7 ) ;
V_169:
F_77 ( V_35 ) ;
V_168:
F_44 ( & V_40 -> V_137 ) ;
return V_11 ;
}
static unsigned int
F_78 ( struct V_35 * V_35 , struct V_172 * V_173 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
unsigned int V_128 ;
F_23 ( V_40 -> V_7 , L_8 , V_41 , __LINE__ ) ;
F_41 ( & V_40 -> V_137 ) ;
V_128 = F_79 ( & V_40 -> V_160 , V_35 , V_173 ) ;
F_44 ( & V_40 -> V_137 ) ;
return V_128 ;
}
static int F_80 ( struct V_35 * V_35 , struct V_174 * V_175 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
int V_11 ;
F_23 ( V_40 -> V_7 , L_8 , V_41 , __LINE__ ) ;
if ( F_70 ( & V_40 -> V_137 ) )
return - V_167 ;
V_11 = F_81 ( & V_40 -> V_160 , V_175 ) ;
F_44 ( & V_40 -> V_137 ) ;
return V_11 ;
}
static int F_82 ( struct V_35 * V_35 )
{
struct V_39 * V_40 = F_22 ( V_35 ) ;
F_23 ( V_40 -> V_7 , L_8 , V_41 , __LINE__ ) ;
F_41 ( & V_40 -> V_137 ) ;
if ( F_73 ( V_35 ) ) {
F_83 ( & V_40 -> V_160 ) ;
F_76 ( V_40 -> V_7 ) ;
}
F_77 ( V_35 ) ;
F_44 ( & V_40 -> V_137 ) ;
return 0 ;
}
static int F_84 ( struct V_176 * V_177 ,
unsigned int * V_178 , unsigned int * V_179 , unsigned int V_180 [] ,
struct V_1 * V_181 [] )
{
struct V_39 * V_40 = F_85 ( V_177 ) ;
const struct V_73 * V_74 = V_40 -> V_74 ;
int V_20 ;
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_87 V_88 [ 3 ] ;
F_23 ( V_7 , L_17 , V_41 ) ;
if ( V_74 == NULL )
return - V_76 ;
F_23 ( V_7 , L_25 , V_74 -> V_15 ) ;
F_32 ( V_88 , V_74 , V_40 -> V_54 . V_55 . V_56 ,
V_40 -> V_54 . V_55 . V_57 ) ;
* V_179 = V_74 -> V_89 ;
for ( V_20 = 0 ; V_20 < V_74 -> V_89 ; ++ V_20 ) {
V_180 [ V_20 ] = V_88 [ V_20 ] . V_93 ;
F_23 ( V_7 , L_26 , V_20 , V_180 [ V_20 ] ) ;
}
if ( * V_178 == 0 )
* V_178 = 1 ;
return 0 ;
}
static void F_86 ( struct V_182 * V_183 )
{
struct V_184 * V_185 = F_87 ( V_183 ) ;
struct V_186 * V_187 = F_88 ( V_185 , struct V_186 , V_183 ) ;
struct V_39 * V_40 = F_85 ( V_183 -> V_176 ) ;
struct V_6 * V_7 = V_40 -> V_7 ;
unsigned long V_130 ;
F_89 ( & V_40 -> V_188 , V_130 ) ;
F_90 ( & V_187 -> V_189 , & V_40 -> V_190 ) ;
F_91 ( & V_40 -> V_188 , V_130 ) ;
F_23 ( V_7 , L_27 ) ;
}
static int F_92 ( struct V_176 * V_177 , unsigned int V_191 )
{
struct V_39 * V_40 = F_85 ( V_177 ) ;
struct V_6 * V_7 = V_40 -> V_7 ;
unsigned long V_130 ;
F_23 ( V_7 , L_17 , V_41 ) ;
F_93 ( V_7 ) ;
F_27 ( V_40 ) ;
V_40 -> V_68 . V_192 ( V_40 ) ;
F_89 ( & V_40 -> V_188 , V_130 ) ;
V_40 -> V_193 = V_194 ;
F_91 ( & V_40 -> V_188 , V_130 ) ;
V_40 -> V_68 . V_195 ( V_40 , V_196 ) ;
F_94 ( V_7 ) ;
return 0 ;
}
static void F_95 ( unsigned long V_197 )
{
struct V_39 * V_40 = (struct V_39 * ) V_197 ;
struct V_6 * V_7 = V_40 -> V_7 ;
unsigned long V_130 ;
F_12 ( V_7 , L_28 , V_40 -> V_45 . V_15 ) ;
F_89 ( & V_40 -> V_188 , V_130 ) ;
if ( V_40 -> V_198 == V_40 -> V_199 )
V_40 -> V_198 = NULL ;
if ( V_40 -> V_198 ) {
F_96 ( & V_40 -> V_198 -> V_183 . V_200 ,
V_201 ) ;
V_40 -> V_198 = NULL ;
}
if ( V_40 -> V_199 ) {
F_96 ( & V_40 -> V_199 -> V_183 . V_200 ,
V_201 ) ;
V_40 -> V_199 = NULL ;
}
F_91 ( & V_40 -> V_188 , V_130 ) ;
}
static void F_97 ( struct V_176 * V_177 )
{
struct V_39 * V_40 = F_85 ( V_177 ) ;
struct V_6 * V_7 = V_40 -> V_7 ;
unsigned long V_130 ;
struct V_202 V_203 ;
struct V_186 * V_204 , * V_205 ;
F_23 ( V_7 , L_17 , V_41 ) ;
F_89 ( & V_40 -> V_188 , V_130 ) ;
V_40 -> V_193 = V_206 ;
F_98 (buf, buf_tmp, &layer->enq_list, list) {
F_99 ( & V_204 -> V_189 ) ;
F_96 ( & V_204 -> V_183 . V_200 , V_201 ) ;
}
F_91 ( & V_40 -> V_188 , V_130 ) ;
F_100 ( & V_203 , F_95 ,
( unsigned long ) V_40 ) ;
F_101 ( & V_203 , V_207 + F_102 ( 1000 ) ) ;
F_103 ( V_177 ) ;
F_104 ( & V_203 ) ;
F_105 ( & V_203 ) ;
F_89 ( & V_40 -> V_188 , V_130 ) ;
V_40 -> V_193 = V_208 ;
F_91 ( & V_40 -> V_188 , V_130 ) ;
V_40 -> V_68 . V_195 ( V_40 , V_209 ) ;
F_106 ( V_7 ) ;
F_107 ( V_7 ) ;
}
int F_108 ( struct V_39 * V_40 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
int V_11 ;
V_11 = F_109 ( & V_40 -> V_45 , V_210 , - 1 ) ;
if ( V_11 )
F_12 ( V_7 , L_29 ) ;
else
F_16 ( V_7 , L_30 ,
V_40 -> V_45 . V_15 , V_40 -> V_45 . V_211 ) ;
return V_11 ;
}
void F_110 ( struct V_39 * V_40 )
{
F_111 ( & V_40 -> V_45 ) ;
}
void F_112 ( struct V_39 * V_40 )
{
if ( V_40 -> V_68 . V_212 )
V_40 -> V_68 . V_212 ( V_40 ) ;
}
void F_113 ( struct V_39 * V_40 )
{
F_17 ( V_40 ) ;
}
static void F_114 ( struct V_156 * V_213 )
{
F_115 ( L_31 ) ;
}
struct V_39 * F_116 ( struct V_6 * V_7 ,
int V_47 , char * V_15 , const struct V_214 * V_68 )
{
struct V_39 * V_40 ;
V_40 = F_15 ( sizeof( * V_40 ) , V_26 ) ;
if ( V_40 == NULL ) {
F_12 ( V_7 , L_32 ) ;
goto V_21;
}
V_40 -> V_7 = V_7 ;
V_40 -> V_47 = V_47 ;
V_40 -> V_68 = * V_68 ;
F_117 ( & V_40 -> V_188 ) ;
F_118 ( & V_40 -> V_190 ) ;
F_119 ( & V_40 -> V_137 ) ;
V_40 -> V_45 = (struct V_156 ) {
. V_215 = - 1 ,
. V_212 = F_114 ,
. V_216 = & V_217 ,
. V_218 = V_219 ,
. V_220 = & V_221 ,
} ;
F_9 ( V_40 -> V_45 . V_15 , V_15 , sizeof( V_40 -> V_45 . V_15 ) ) ;
F_120 ( & V_40 -> V_45 , V_40 ) ;
V_40 -> V_45 . V_222 = & V_40 -> V_137 ;
V_40 -> V_45 . V_14 = & V_7 -> V_14 ;
V_40 -> V_160 = (struct V_176 ) {
. type = V_109 ,
. V_223 = V_224 | V_225 | V_226 ,
. V_227 = V_40 ,
. V_228 = sizeof( struct V_186 ) ,
. V_68 = & V_229 ,
. V_230 = 1 ,
. V_231 = & V_232 ,
. V_222 = & V_40 -> V_137 ,
. V_2 = V_7 -> V_2 ,
} ;
return V_40 ;
V_21:
return NULL ;
}
static const struct V_73 * F_36 (
struct V_39 * V_40 , unsigned long V_79 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_40 -> V_233 ; ++ V_20 )
if ( V_40 -> V_171 [ V_20 ] -> V_79 == V_79 )
return V_40 -> V_171 [ V_20 ] ;
return NULL ;
}
static const struct V_73 * F_29 (
struct V_39 * V_40 , unsigned long V_75 )
{
if ( V_75 >= V_40 -> V_233 )
return NULL ;
return V_40 -> V_171 [ V_75 ] ;
}

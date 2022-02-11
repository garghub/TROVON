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
V_7 -> V_22 = F_13 ( V_7 -> V_2 ) ;
if ( F_14 ( V_7 -> V_22 ) ) {
F_12 ( V_7 , L_5 ) ;
V_11 = F_15 ( V_7 -> V_22 ) ;
goto V_23;
}
V_7 -> V_24 = 0 ;
for ( V_20 = 0 ; V_20 < V_18 ; ++ V_20 ) {
struct V_16 * V_25 = & V_17 [ V_20 ] ;
struct V_26 * V_27 ;
V_5 = F_3 ( V_7 , V_25 -> V_8 ) ;
if ( V_5 == NULL )
continue;
V_27 = F_16 ( sizeof( * V_27 ) , V_28 ) ;
if ( V_27 == NULL ) {
F_12 ( V_7 , L_6 ,
V_25 -> V_29 ) ;
V_11 = - V_30 ;
goto V_31;
}
F_9 ( V_27 -> V_15 , V_25 -> V_29 , sizeof( V_27 -> V_15 ) ) ;
V_27 -> V_5 = V_5 ;
V_27 -> V_32 = V_25 -> V_32 ;
V_7 -> V_33 [ V_7 -> V_24 ++ ] = V_27 ;
F_17 ( V_7 , L_7 ,
V_25 -> V_29 , V_25 -> V_8 ) ;
if ( V_7 -> V_24 >= V_34 )
break;
}
if ( V_7 -> V_24 == 0 ) {
F_12 ( V_7 , L_8 ) ;
V_11 = - V_35 ;
goto V_36;
}
return 0 ;
V_31:
for ( V_20 = 0 ; V_20 < V_7 -> V_24 ; ++ V_20 )
F_18 ( V_7 -> V_33 [ V_20 ] ) ;
memset ( V_7 -> V_33 , 0 , sizeof( V_7 -> V_33 ) ) ;
V_36:
F_19 ( V_7 -> V_22 ) ;
V_23:
F_20 ( V_14 ) ;
V_21:
return V_11 ;
}
void F_21 ( struct V_6 * V_7 )
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
F_9 ( V_40 -> V_44 , V_45 , sizeof( V_40 -> V_44 ) ) ;
F_9 ( V_40 -> V_46 , V_42 -> V_47 . V_15 , sizeof( V_40 -> V_46 ) ) ;
sprintf ( V_40 -> V_48 , L_10 , V_42 -> V_49 ) ;
V_40 -> V_50 = V_51 | V_52 ;
V_40 -> V_53 = V_40 -> V_50 | V_54 ;
return 0 ;
}
static void F_25 ( struct V_6 * V_7 , struct V_55 * V_56 )
{
F_24 ( V_7 , L_11 ,
V_56 -> V_57 . V_58 , V_56 -> V_57 . V_59 ) ;
F_24 ( V_7 , L_12 ,
V_56 -> V_57 . V_60 , V_56 -> V_57 . V_61 ) ;
F_24 ( V_7 , L_13 ,
V_56 -> V_57 . V_62 , V_56 -> V_57 . V_63 ) ;
F_24 ( V_7 , L_14 ,
V_56 -> V_64 . V_58 , V_56 -> V_64 . V_59 ) ;
F_24 ( V_7 , L_15 ,
V_56 -> V_64 . V_60 , V_56 -> V_64 . V_61 ) ;
F_24 ( V_7 , L_16 ,
V_56 -> V_64 . V_62 , V_56 -> V_64 . V_63 ) ;
F_24 ( V_7 , L_17 ,
V_56 -> V_65 , V_56 -> V_66 ) ;
}
static void F_26 ( struct V_41 * V_42 )
{
struct V_6 * V_7 = V_42 -> V_7 ;
struct V_67 V_68 ;
memset ( & V_42 -> V_56 , 0 , sizeof( V_42 -> V_56 ) ) ;
F_27 ( V_7 , & V_68 ) ;
V_42 -> V_56 . V_64 . V_58 = V_68 . V_60 ;
V_42 -> V_56 . V_64 . V_59 = V_68 . V_61 ;
V_42 -> V_56 . V_64 . V_60 = V_42 -> V_56 . V_64 . V_58 ;
V_42 -> V_56 . V_64 . V_61 = V_42 -> V_56 . V_64 . V_59 ;
V_42 -> V_56 . V_64 . V_69 = V_68 . V_69 ;
V_42 -> V_56 . V_57 . V_58 = V_68 . V_60 ;
V_42 -> V_56 . V_57 . V_59 = V_68 . V_61 ;
V_42 -> V_56 . V_57 . V_60 = V_42 -> V_56 . V_57 . V_58 ;
V_42 -> V_56 . V_57 . V_61 = V_42 -> V_56 . V_57 . V_59 ;
F_25 ( V_7 , & V_42 -> V_56 ) ;
V_42 -> V_70 . V_71 ( V_42 , V_72 , 0 ) ;
F_25 ( V_7 , & V_42 -> V_56 ) ;
}
static void F_28 ( struct V_41 * V_42 )
{
struct V_6 * V_7 = V_42 -> V_7 ;
struct V_67 V_68 ;
F_27 ( V_7 , & V_68 ) ;
if ( V_42 -> V_56 . V_64 . V_58 == V_68 . V_60 &&
V_42 -> V_56 . V_64 . V_59 == V_68 . V_60 )
return;
V_42 -> V_56 . V_64 . V_58 = V_68 . V_60 ;
V_42 -> V_56 . V_64 . V_59 = V_68 . V_61 ;
V_42 -> V_56 . V_64 . V_69 = V_68 . V_69 ;
V_42 -> V_70 . V_71 ( V_42 , V_72 , 0 ) ;
F_25 ( V_7 , & V_42 -> V_56 ) ;
}
static int F_29 ( struct V_37 * V_37 , void * V_38 ,
struct V_73 * V_74 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
const struct V_75 * V_76 ;
F_24 ( V_7 , L_18 , V_43 ) ;
V_76 = F_30 ( V_42 , V_74 -> V_77 ) ;
if ( V_76 == NULL )
return - V_78 ;
F_9 ( V_74 -> V_79 , V_76 -> V_15 , sizeof( V_74 -> V_79 ) ) ;
V_74 -> V_80 = V_76 -> V_81 ;
return 0 ;
}
static unsigned int F_31 ( unsigned int V_82 , unsigned int V_83 )
{
return ( V_82 + V_83 - 1 ) / V_83 ;
}
unsigned long F_32 ( const struct V_84 * V_85 ,
unsigned int V_60 , unsigned int V_61 )
{
unsigned int V_86 = F_31 ( V_60 , V_85 -> V_60 ) ;
unsigned int V_87 = F_31 ( V_61 , V_85 -> V_61 ) ;
return V_86 * V_87 * V_85 -> V_88 ;
}
static void F_33 ( struct V_89 * V_90 ,
const struct V_75 * V_76 , T_1 V_60 , T_1 V_61 )
{
int V_20 ;
if ( ! V_90 )
return;
memset ( V_90 , 0 , sizeof( * V_90 ) * V_76 -> V_91 ) ;
for ( V_20 = 0 ; V_20 < V_76 -> V_92 ; ++ V_20 ) {
struct V_89 * V_93 = V_90
+ V_76 -> V_94 [ V_20 ] ;
const struct V_84 * V_85 = & V_76 -> V_93 [ V_20 ] ;
T_1 V_86 = F_31 ( V_60 , V_85 -> V_60 ) ;
T_1 V_87 = F_31 ( V_61 , V_85 -> V_61 ) ;
T_1 V_95 = V_86 * V_87 * V_85 -> V_88 ;
T_1 V_96 = V_86 * V_85 -> V_88 / V_85 -> V_61 ;
V_93 -> V_95 += V_95 ;
V_93 -> V_96 = F_34 ( V_93 -> V_96 , V_96 ) ;
}
}
static int F_35 ( struct V_37 * V_37 , void * V_38 ,
struct V_97 * V_74 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_98 * V_99 = & V_74 -> V_76 . V_100 ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
V_99 -> V_60 = V_42 -> V_56 . V_57 . V_58 ;
V_99 -> V_61 = V_42 -> V_56 . V_57 . V_59 ;
V_99 -> V_69 = V_101 ;
V_99 -> V_80 = V_42 -> V_76 -> V_81 ;
V_99 -> V_102 = V_42 -> V_76 -> V_102 ;
F_33 ( V_99 -> V_103 , V_42 -> V_76 , V_99 -> V_60 , V_99 -> V_61 ) ;
return 0 ;
}
static int F_36 ( struct V_37 * V_37 , void * V_38 ,
struct V_97 * V_74 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
const struct V_75 * V_76 ;
struct V_98 * V_99 ;
struct V_6 * V_7 = V_42 -> V_7 ;
struct V_55 * V_56 = & V_42 -> V_56 ;
F_24 ( V_7 , L_9 , V_43 , __LINE__ ) ;
V_99 = & V_74 -> V_76 . V_100 ;
V_76 = F_37 ( V_42 , V_99 -> V_80 ) ;
if ( V_76 == NULL ) {
F_5 ( V_7 , L_19 ,
V_99 -> V_80 ) ;
return - V_78 ;
}
V_42 -> V_76 = V_76 ;
V_56 -> V_57 . V_58 = F_34 ( V_56 -> V_64 . V_58 , V_99 -> V_60 ) ;
V_56 -> V_57 . V_59 = F_34 ( V_56 -> V_64 . V_59 , V_99 -> V_61 ) ;
V_42 -> V_70 . V_71 ( V_42 , V_104 , 0 ) ;
F_25 ( V_7 , & V_42 -> V_56 ) ;
V_56 -> V_57 . V_60 = V_99 -> V_60 ;
V_56 -> V_57 . V_61 = V_99 -> V_61 ;
V_56 -> V_57 . V_62 = 0 ;
V_56 -> V_57 . V_63 = 0 ;
V_42 -> V_70 . V_71 ( V_42 , V_105 , V_106 ) ;
F_25 ( V_7 , & V_42 -> V_56 ) ;
V_56 -> V_57 . V_58 = 0 ;
V_56 -> V_57 . V_59 = 0 ;
V_42 -> V_70 . V_71 ( V_42 , V_104 , 0 ) ;
F_25 ( V_7 , & V_42 -> V_56 ) ;
F_35 ( V_37 , V_38 , V_74 ) ;
return 0 ;
}
static int F_38 ( struct V_37 * V_37 , void * V_107 ,
struct V_108 * V_109 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_55 * V_56 = & V_42 -> V_56 ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
if ( V_109 -> type != V_110 &&
V_109 -> type != V_111 )
return - V_78 ;
switch ( V_109 -> V_112 ) {
case V_113 :
V_109 -> V_114 . V_115 = V_56 -> V_57 . V_62 ;
V_109 -> V_114 . V_116 = V_56 -> V_57 . V_63 ;
V_109 -> V_114 . V_60 = V_56 -> V_57 . V_60 ;
V_109 -> V_114 . V_61 = V_56 -> V_57 . V_61 ;
break;
case V_117 :
case V_118 :
V_109 -> V_114 . V_115 = 0 ;
V_109 -> V_114 . V_116 = 0 ;
V_109 -> V_114 . V_60 = V_56 -> V_57 . V_58 ;
V_109 -> V_114 . V_61 = V_56 -> V_57 . V_59 ;
break;
case V_119 :
case V_120 :
V_109 -> V_114 . V_115 = V_56 -> V_64 . V_62 ;
V_109 -> V_114 . V_116 = V_56 -> V_64 . V_63 ;
V_109 -> V_114 . V_60 = V_56 -> V_64 . V_60 ;
V_109 -> V_114 . V_61 = V_56 -> V_64 . V_61 ;
break;
case V_121 :
case V_122 :
V_109 -> V_114 . V_115 = 0 ;
V_109 -> V_114 . V_116 = 0 ;
V_109 -> V_114 . V_60 = V_56 -> V_64 . V_58 ;
V_109 -> V_114 . V_61 = V_56 -> V_64 . V_59 ;
break;
default:
return - V_78 ;
}
return 0 ;
}
static int F_39 ( struct V_123 * V_124 , struct V_123 * V_125 )
{
if ( V_124 -> V_115 < V_125 -> V_115 )
return 0 ;
if ( V_124 -> V_116 < V_125 -> V_116 )
return 0 ;
if ( V_124 -> V_115 + V_124 -> V_60 > V_125 -> V_115 + V_125 -> V_60 )
return 0 ;
if ( V_124 -> V_116 + V_124 -> V_61 > V_125 -> V_116 + V_125 -> V_61 )
return 0 ;
return 1 ;
}
static int F_40 ( struct V_37 * V_37 , void * V_107 ,
struct V_108 * V_109 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_55 * V_56 = & V_42 -> V_56 ;
struct V_126 * V_112 = NULL ;
enum V_127 V_128 ;
struct V_55 V_129 ;
struct V_123 V_130 ;
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
F_24 ( V_42 -> V_7 , L_20 , V_43 ,
V_109 -> V_114 . V_60 , V_109 -> V_114 . V_61 , V_109 -> V_114 . V_115 , V_109 -> V_114 . V_116 ) ;
if ( V_109 -> type != V_110 &&
V_109 -> type != V_111 )
return - V_78 ;
switch ( V_109 -> V_112 ) {
case V_117 :
case V_118 :
V_130 . V_60 = V_56 -> V_57 . V_58 ;
V_130 . V_61 = V_56 -> V_57 . V_59 ;
break;
case V_121 :
case V_122 :
V_130 . V_60 = V_56 -> V_64 . V_58 ;
V_130 . V_61 = V_56 -> V_64 . V_59 ;
break;
case V_113 :
V_112 = & V_56 -> V_57 ;
V_128 = V_105 ;
break;
case V_119 :
case V_120 :
V_112 = & V_56 -> V_64 ;
V_128 = V_131 ;
break;
default:
return - V_78 ;
}
if ( V_112 ) {
memcpy ( & V_129 , V_56 , sizeof( V_129 ) ) ;
V_112 -> V_62 = V_109 -> V_114 . V_115 ;
V_112 -> V_63 = V_109 -> V_114 . V_116 ;
V_112 -> V_60 = V_109 -> V_114 . V_60 ;
V_112 -> V_61 = V_109 -> V_114 . V_61 ;
V_42 -> V_70 . V_71 ( V_42 , V_128 , V_109 -> V_132 ) ;
V_130 . V_115 = V_112 -> V_62 ;
V_130 . V_116 = V_112 -> V_63 ;
V_130 . V_60 = V_112 -> V_60 ;
V_130 . V_61 = V_112 -> V_61 ;
F_25 ( V_42 -> V_7 , & V_42 -> V_56 ) ;
}
if ( ( V_109 -> V_132 & V_133 ) && ! F_39 ( & V_130 , & V_109 -> V_114 ) )
goto V_21;
if ( ( V_109 -> V_132 & V_134 ) && ! F_39 ( & V_109 -> V_114 , & V_130 ) )
goto V_21;
V_109 -> V_114 = V_130 ;
return 0 ;
V_21:
if ( V_112 )
memcpy ( V_56 , & V_129 , sizeof( V_129 ) ) ;
return - V_135 ;
}
static int F_41 ( struct V_37 * V_37 , void * V_107 ,
struct V_136 * V_137 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 ;
V_137 -> V_138 = 0 ;
F_42 ( & V_7 -> V_139 ) ;
V_11 = F_43 ( F_44 ( V_7 ) , V_138 , V_140 , V_137 ) ;
F_45 ( & V_7 -> V_139 ) ;
return V_11 ? - V_78 : 0 ;
}
static int F_46 ( struct V_37 * V_37 , void * V_107 ,
struct V_141 * V_137 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 ;
F_42 ( & V_7 -> V_139 ) ;
if ( V_7 -> V_142 > 0 ) {
F_45 ( & V_7 -> V_139 ) ;
return - V_143 ;
}
V_11 = F_43 ( F_44 ( V_7 ) , V_144 , V_145 , V_137 ) ;
F_45 ( & V_7 -> V_139 ) ;
F_28 ( V_42 ) ;
return V_11 ? - V_78 : 0 ;
}
static int F_47 ( struct V_37 * V_37 , void * V_107 ,
struct V_141 * V_137 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 ;
F_42 ( & V_7 -> V_139 ) ;
V_11 = F_43 ( F_44 ( V_7 ) , V_144 , V_146 , V_137 ) ;
F_45 ( & V_7 -> V_139 ) ;
return V_11 ? - V_78 : 0 ;
}
static int F_48 ( struct V_37 * V_37 , void * V_107 ,
struct V_147 * V_40 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 ;
V_40 -> V_138 = 0 ;
F_42 ( & V_7 -> V_139 ) ;
V_11 = F_43 ( F_44 ( V_7 ) , V_138 , V_148 , V_40 ) ;
F_45 ( & V_7 -> V_139 ) ;
return V_11 ? - V_78 : 0 ;
}
static int F_49 ( struct V_37 * V_37 , void * V_107 , T_2 V_149 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 ;
F_42 ( & V_7 -> V_139 ) ;
if ( V_7 -> V_142 > 0 ) {
F_45 ( & V_7 -> V_139 ) ;
return - V_143 ;
}
V_11 = F_43 ( F_44 ( V_7 ) , V_144 , V_150 , V_149 ) ;
F_45 ( & V_7 -> V_139 ) ;
F_28 ( V_42 ) ;
return V_11 ? - V_78 : 0 ;
}
static int F_50 ( struct V_37 * V_37 , void * V_107 , T_2 * V_149 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 ;
F_42 ( & V_7 -> V_139 ) ;
V_11 = F_43 ( F_44 ( V_7 ) , V_144 , V_151 , V_149 ) ;
F_45 ( & V_7 -> V_139 ) ;
return V_11 ? - V_78 : 0 ;
}
static int F_51 ( struct V_37 * V_37 , void * V_107 , struct V_152 * V_124 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
struct V_26 * V_27 ;
struct V_4 * V_5 ;
if ( V_124 -> V_77 >= V_7 -> V_24 )
return - V_78 ;
V_27 = V_7 -> V_33 [ V_124 -> V_77 ] ;
F_52 ( V_27 == NULL ) ;
V_5 = V_27 -> V_5 ;
F_9 ( V_124 -> V_15 , V_27 -> V_15 , sizeof( V_124 -> V_15 ) ) ;
F_43 ( V_5 , V_144 , V_153 , & V_124 -> V_154 ) ;
V_124 -> V_53 = 0 ;
if ( V_5 -> V_70 -> V_144 && V_5 -> V_70 -> V_144 -> V_145 )
V_124 -> V_53 |= V_155 ;
if ( V_5 -> V_70 -> V_144 && V_5 -> V_70 -> V_144 -> V_150 )
V_124 -> V_53 |= V_156 ;
V_124 -> type = V_157 ;
return 0 ;
}
static int F_53 ( struct V_37 * V_37 , void * V_107 , unsigned int V_20 )
{
struct V_158 * V_47 = F_54 ( V_37 ) ;
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
if ( V_20 >= V_7 -> V_24 || V_7 -> V_33 [ V_20 ] == NULL )
return - V_78 ;
F_42 ( & V_7 -> V_139 ) ;
if ( V_7 -> V_142 > 0 ) {
F_45 ( & V_7 -> V_139 ) ;
return - V_143 ;
}
V_7 -> V_159 = V_20 ;
V_47 -> V_160 = 0 ;
F_43 ( F_44 ( V_7 ) , V_144 , V_153 ,
& V_47 -> V_160 ) ;
F_45 ( & V_7 -> V_139 ) ;
F_28 ( V_42 ) ;
F_24 ( V_7 , L_21 , V_47 -> V_160 ) ;
return 0 ;
}
static int F_55 ( struct V_37 * V_37 , void * V_107 , unsigned int * V_3 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
F_42 ( & V_7 -> V_139 ) ;
* V_3 = V_7 -> V_159 ;
F_45 ( & V_7 -> V_139 ) ;
return 0 ;
}
static int F_56 ( struct V_37 * V_37 , void * V_38 ,
struct V_161 * V_3 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
return F_57 ( & V_42 -> V_162 , V_3 ) ;
}
static int F_58 ( struct V_37 * V_37 , void * V_38 , struct V_163 * V_3 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
return F_59 ( & V_42 -> V_162 , V_3 ) ;
}
static int F_60 ( struct V_37 * V_37 , void * V_38 , struct V_163 * V_3 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_22 , V_43 , __LINE__ , V_3 -> V_77 ) ;
return F_61 ( & V_42 -> V_162 , V_3 ) ;
}
static int F_62 ( struct V_37 * V_37 , void * V_38 , struct V_163 * V_3 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
return F_63 ( & V_42 -> V_162 , V_3 , V_37 -> V_164 & V_165 ) ;
}
static int F_64 ( struct V_37 * V_37 , void * V_38 ,
struct V_166 * V_167 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
return F_65 ( & V_42 -> V_162 , V_167 ) ;
}
static int F_66 ( struct V_37 * V_37 , void * V_38 , enum V_168 V_20 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
return F_67 ( & V_42 -> V_162 , V_20 ) ;
}
static int F_68 ( struct V_37 * V_37 , void * V_38 , enum V_168 V_20 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
return F_69 ( & V_42 -> V_162 , V_20 ) ;
}
static int F_70 ( struct V_37 * V_37 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 = 0 ;
F_24 ( V_7 , L_9 , V_43 , __LINE__ ) ;
if ( F_71 ( & V_42 -> V_139 ) )
return - V_169 ;
F_72 () ;
V_11 = F_73 ( V_37 ) ;
if ( V_11 ) {
F_12 ( V_7 , L_23 ) ;
goto V_170;
}
if ( ! F_74 ( V_37 ) )
goto V_170;
V_11 = F_75 ( V_7 ) ;
if ( V_11 ) {
F_12 ( V_7 , L_24 ) ;
goto V_171;
}
V_11 = F_76 ( & V_42 -> V_162 ) ;
if ( V_11 != 0 ) {
F_12 ( V_7 , L_25 ) ;
goto V_172;
}
V_42 -> V_76 = V_42 -> V_173 [ 0 ] ;
F_26 ( V_42 ) ;
F_45 ( & V_42 -> V_139 ) ;
return 0 ;
V_172:
F_77 ( V_7 ) ;
V_171:
F_78 ( V_37 ) ;
V_170:
F_45 ( & V_42 -> V_139 ) ;
return V_11 ;
}
static unsigned int
F_79 ( struct V_37 * V_37 , struct V_174 * V_175 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
unsigned int V_130 ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
F_42 ( & V_42 -> V_139 ) ;
V_130 = F_80 ( & V_42 -> V_162 , V_37 , V_175 ) ;
F_45 ( & V_42 -> V_139 ) ;
return V_130 ;
}
static int F_81 ( struct V_37 * V_37 , struct V_176 * V_177 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
int V_11 ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
if ( F_71 ( & V_42 -> V_139 ) )
return - V_169 ;
V_11 = F_82 ( & V_42 -> V_162 , V_177 ) ;
F_45 ( & V_42 -> V_139 ) ;
return V_11 ;
}
static int F_83 ( struct V_37 * V_37 )
{
struct V_41 * V_42 = F_23 ( V_37 ) ;
F_24 ( V_42 -> V_7 , L_9 , V_43 , __LINE__ ) ;
F_42 ( & V_42 -> V_139 ) ;
if ( F_74 ( V_37 ) ) {
F_84 ( & V_42 -> V_162 ) ;
F_77 ( V_42 -> V_7 ) ;
}
F_78 ( V_37 ) ;
F_45 ( & V_42 -> V_139 ) ;
return 0 ;
}
static int F_85 ( struct V_178 * V_179 ,
unsigned int * V_180 , unsigned int * V_181 , unsigned int V_182 [] ,
void * V_183 [] )
{
struct V_41 * V_42 = F_86 ( V_179 ) ;
const struct V_75 * V_76 = V_42 -> V_76 ;
int V_20 ;
struct V_6 * V_7 = V_42 -> V_7 ;
struct V_89 V_90 [ 3 ] ;
F_24 ( V_7 , L_18 , V_43 ) ;
if ( V_76 == NULL )
return - V_78 ;
F_24 ( V_7 , L_26 , V_76 -> V_15 ) ;
F_33 ( V_90 , V_76 , V_42 -> V_56 . V_57 . V_58 ,
V_42 -> V_56 . V_57 . V_59 ) ;
* V_181 = V_76 -> V_91 ;
for ( V_20 = 0 ; V_20 < V_76 -> V_91 ; ++ V_20 ) {
V_183 [ V_20 ] = V_42 -> V_7 -> V_22 ;
V_182 [ V_20 ] = V_90 [ V_20 ] . V_95 ;
F_24 ( V_7 , L_27 , V_20 , V_182 [ V_20 ] ) ;
}
if ( * V_180 == 0 )
* V_180 = 1 ;
return 0 ;
}
static void F_87 ( struct V_184 * V_185 )
{
struct V_186 * V_187 = F_88 ( V_185 ) ;
struct V_188 * V_189 = F_89 ( V_187 , struct V_188 , V_185 ) ;
struct V_41 * V_42 = F_86 ( V_185 -> V_178 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
unsigned long V_132 ;
F_90 ( & V_42 -> V_190 , V_132 ) ;
F_91 ( & V_189 -> V_191 , & V_42 -> V_192 ) ;
F_92 ( & V_42 -> V_190 , V_132 ) ;
F_24 ( V_7 , L_28 ) ;
}
static int F_93 ( struct V_178 * V_179 , unsigned int V_193 )
{
struct V_41 * V_42 = F_86 ( V_179 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
unsigned long V_132 ;
F_24 ( V_7 , L_18 , V_43 ) ;
F_94 ( V_7 ) ;
F_28 ( V_42 ) ;
V_42 -> V_70 . V_194 ( V_42 ) ;
F_90 ( & V_42 -> V_190 , V_132 ) ;
V_42 -> V_195 = V_196 ;
F_92 ( & V_42 -> V_190 , V_132 ) ;
V_42 -> V_70 . V_197 ( V_42 , V_198 ) ;
F_95 ( V_7 ) ;
return 0 ;
}
static void F_96 ( unsigned long V_199 )
{
struct V_41 * V_42 = (struct V_41 * ) V_199 ;
struct V_6 * V_7 = V_42 -> V_7 ;
unsigned long V_132 ;
F_12 ( V_7 , L_29 , V_42 -> V_47 . V_15 ) ;
F_90 ( & V_42 -> V_190 , V_132 ) ;
if ( V_42 -> V_200 == V_42 -> V_201 )
V_42 -> V_200 = NULL ;
if ( V_42 -> V_200 ) {
F_97 ( & V_42 -> V_200 -> V_185 . V_202 ,
V_203 ) ;
V_42 -> V_200 = NULL ;
}
if ( V_42 -> V_201 ) {
F_97 ( & V_42 -> V_201 -> V_185 . V_202 ,
V_203 ) ;
V_42 -> V_201 = NULL ;
}
F_92 ( & V_42 -> V_190 , V_132 ) ;
}
static void F_98 ( struct V_178 * V_179 )
{
struct V_41 * V_42 = F_86 ( V_179 ) ;
struct V_6 * V_7 = V_42 -> V_7 ;
unsigned long V_132 ;
struct V_204 V_205 ;
struct V_188 * V_206 , * V_207 ;
F_24 ( V_7 , L_18 , V_43 ) ;
F_90 ( & V_42 -> V_190 , V_132 ) ;
V_42 -> V_195 = V_208 ;
F_99 (buf, buf_tmp, &layer->enq_list, list) {
F_100 ( & V_206 -> V_191 ) ;
F_97 ( & V_206 -> V_185 . V_202 , V_203 ) ;
}
F_92 ( & V_42 -> V_190 , V_132 ) ;
F_101 ( & V_205 , F_96 ,
( unsigned long ) V_42 ) ;
F_102 ( & V_205 , V_209 + F_103 ( 1000 ) ) ;
F_104 ( V_179 ) ;
F_105 ( & V_205 ) ;
F_106 ( & V_205 ) ;
F_90 ( & V_42 -> V_190 , V_132 ) ;
V_42 -> V_195 = V_210 ;
F_92 ( & V_42 -> V_190 , V_132 ) ;
V_42 -> V_70 . V_197 ( V_42 , V_211 ) ;
F_107 ( V_7 ) ;
F_108 ( V_7 ) ;
}
int F_109 ( struct V_41 * V_42 )
{
struct V_6 * V_7 = V_42 -> V_7 ;
int V_11 ;
V_11 = F_110 ( & V_42 -> V_47 , V_212 , - 1 ) ;
if ( V_11 )
F_12 ( V_7 , L_30 ) ;
else
F_17 ( V_7 , L_31 ,
V_42 -> V_47 . V_15 , V_42 -> V_47 . V_213 ) ;
return V_11 ;
}
void F_111 ( struct V_41 * V_42 )
{
F_112 ( & V_42 -> V_47 ) ;
}
void F_113 ( struct V_41 * V_42 )
{
if ( V_42 -> V_70 . V_214 )
V_42 -> V_70 . V_214 ( V_42 ) ;
}
void F_114 ( struct V_41 * V_42 )
{
F_18 ( V_42 ) ;
}
static void F_115 ( struct V_158 * V_215 )
{
F_116 ( L_32 ) ;
}
struct V_41 * F_117 ( struct V_6 * V_7 ,
int V_49 , char * V_15 , struct V_216 * V_70 )
{
struct V_41 * V_42 ;
V_42 = F_16 ( sizeof( * V_42 ) , V_28 ) ;
if ( V_42 == NULL ) {
F_12 ( V_7 , L_33 ) ;
goto V_21;
}
V_42 -> V_7 = V_7 ;
V_42 -> V_49 = V_49 ;
V_42 -> V_70 = * V_70 ;
F_118 ( & V_42 -> V_190 ) ;
F_119 ( & V_42 -> V_192 ) ;
F_120 ( & V_42 -> V_139 ) ;
V_42 -> V_47 = (struct V_158 ) {
. V_217 = - 1 ,
. V_214 = F_115 ,
. V_218 = & V_219 ,
. V_220 = V_221 ,
. V_222 = & V_223 ,
} ;
F_9 ( V_42 -> V_47 . V_15 , V_15 , sizeof( V_42 -> V_47 . V_15 ) ) ;
F_121 ( & V_42 -> V_47 , V_42 ) ;
V_42 -> V_47 . V_224 = & V_42 -> V_139 ;
V_42 -> V_47 . V_14 = & V_7 -> V_14 ;
V_42 -> V_162 = (struct V_178 ) {
. type = V_111 ,
. V_225 = V_226 | V_227 | V_228 ,
. V_229 = V_42 ,
. V_230 = sizeof( struct V_188 ) ,
. V_70 = & V_231 ,
. V_232 = 1 ,
. V_233 = & V_234 ,
. V_224 = & V_42 -> V_139 ,
} ;
return V_42 ;
V_21:
return NULL ;
}
static const struct V_75 * F_37 (
struct V_41 * V_42 , unsigned long V_81 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_42 -> V_235 ; ++ V_20 )
if ( V_42 -> V_173 [ V_20 ] -> V_81 == V_81 )
return V_42 -> V_173 [ V_20 ] ;
return NULL ;
}
static const struct V_75 * F_30 (
struct V_41 * V_42 , unsigned long V_77 )
{
if ( V_77 >= V_42 -> V_235 )
return NULL ;
return V_42 -> V_173 [ V_77 ] ;
}

struct V_1 * F_1 ( struct V_2 * V_3 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
if ( V_6 [ V_4 ] . V_7 == V_3 -> V_8 . V_9 . V_10 )
return & V_6 [ V_4 ] ;
}
return NULL ;
}
static struct V_11 * F_2 ( struct V_12 * V_13 ,
enum V_14 type )
{
switch ( type ) {
case V_15 :
return & V_13 -> V_16 ;
case V_17 :
return & V_13 -> V_18 ;
default:
return F_3 ( - V_19 ) ;
}
}
static int F_4 ( struct V_20 * V_21 , const struct V_2 * V_8 ,
unsigned int * V_22 , unsigned int * V_23 ,
unsigned int V_24 [] , void * V_25 [] )
{
struct V_12 * V_13 = F_5 ( V_21 ) ;
struct V_11 * V_3 = F_2 ( V_13 , V_21 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_24 [ 0 ] = V_3 -> V_26 ;
* V_23 = 1 ;
V_25 [ 0 ] = V_13 -> V_27 -> V_28 ;
if ( * V_22 == 0 )
* V_22 = 1 ;
return 0 ;
}
static int F_8 ( struct V_29 * V_30 )
{
struct V_12 * V_13 = F_5 ( V_30 -> V_20 ) ;
struct V_11 * V_3 = F_2 ( V_13 , V_30 -> V_20 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
F_9 ( V_30 , 0 , V_3 -> V_26 ) ;
return 0 ;
}
static void F_10 ( struct V_29 * V_30 )
{
struct V_12 * V_13 = F_5 ( V_30 -> V_20 ) ;
F_11 ( V_13 -> V_31 , V_30 ) ;
}
static int F_12 ( void * V_32 , struct V_20 * V_33 ,
struct V_20 * V_34 )
{
struct V_12 * V_13 = V_32 ;
int V_35 ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> type = V_15 ;
V_33 -> V_36 = V_37 | V_38 ;
V_33 -> V_39 = V_13 ;
V_33 -> V_40 = & V_41 ;
V_33 -> V_42 = & V_43 ;
V_33 -> V_44 = sizeof( struct V_45 ) ;
V_35 = F_13 ( V_33 ) ;
if ( V_35 )
return V_35 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> type = V_17 ;
V_34 -> V_36 = V_37 | V_38 ;
V_34 -> V_39 = V_13 ;
V_34 -> V_40 = & V_41 ;
V_34 -> V_42 = & V_43 ;
V_34 -> V_44 = sizeof( struct V_45 ) ;
return F_13 ( V_34 ) ;
}
static int F_14 ( struct V_46 * V_47 )
{
struct V_12 * V_13 = F_15 ( V_47 -> V_48 , struct V_12 ,
V_49 ) ;
switch ( V_47 -> V_50 ) {
case V_51 :
if ( V_47 -> V_52 == V_53 )
V_13 -> V_54 = V_55 ;
else
V_13 -> V_54 = V_56 ;
break;
default:
F_16 ( & V_13 -> V_27 -> V_57 , L_1 ) ;
return - V_19 ;
}
return 0 ;
}
int F_17 ( struct V_12 * V_13 )
{
struct V_58 * V_27 = V_13 -> V_27 ;
F_18 ( & V_13 -> V_49 , 1 ) ;
if ( V_13 -> V_49 . error ) {
F_16 ( & V_27 -> V_57 , L_2 ) ;
return V_13 -> V_49 . error ;
}
F_19 (
& V_13 -> V_49 ,
& V_59 ,
V_51 ,
V_53 ,
~ ( ( 1 << V_60 ) | ( 1 << V_53 ) ) ,
V_60 ) ;
if ( V_13 -> V_49 . error ) {
F_16 ( & V_27 -> V_57 , L_2 ) ;
return V_13 -> V_49 . error ;
}
return 0 ;
}
static int F_20 ( struct V_61 * V_61 )
{
struct V_58 * V_27 = F_21 ( V_61 ) ;
struct V_12 * V_13 = NULL ;
int V_35 = 0 ;
V_13 = F_22 ( sizeof( * V_13 ) , V_62 ) ;
if ( ! V_13 )
return - V_63 ;
V_13 -> V_27 = V_27 ;
V_13 -> V_16 = V_64 ;
V_13 -> V_18 = V_64 ;
V_13 -> V_31 = F_23 ( V_27 -> V_65 , V_13 , & F_12 ) ;
if ( F_6 ( V_13 -> V_31 ) ) {
V_35 = F_7 ( V_13 -> V_31 ) ;
F_24 ( V_13 ) ;
return V_35 ;
}
F_25 ( & V_13 -> V_66 , F_26 ( V_61 ) ) ;
V_61 -> V_67 = & V_13 -> V_66 ;
F_27 ( & V_13 -> V_66 ) ;
F_17 ( V_13 ) ;
F_28 ( & V_13 -> V_49 ) ;
V_13 -> V_66 . V_49 = & V_13 -> V_49 ;
F_29 ( & V_27 -> V_57 , L_3 ) ;
return 0 ;
}
static int F_30 ( struct V_61 * V_61 )
{
struct V_58 * V_27 = F_21 ( V_61 ) ;
struct V_12 * V_13 = F_31 ( V_61 -> V_67 ) ;
F_32 ( & V_13 -> V_49 ) ;
F_33 ( & V_13 -> V_66 ) ;
F_34 ( & V_13 -> V_66 ) ;
F_24 ( V_13 ) ;
F_29 ( & V_27 -> V_57 , L_4 ) ;
return 0 ;
}
static int F_35 ( struct V_61 * V_61 , void * V_32 ,
struct V_68 * V_69 )
{
strncpy ( V_69 -> V_70 , V_71 , sizeof( V_69 -> V_70 ) - 1 ) ;
strncpy ( V_69 -> V_72 , V_71 , sizeof( V_69 -> V_72 ) - 1 ) ;
V_69 -> V_73 [ 0 ] = 0 ;
V_69 -> V_74 = F_36 ( 1 , 0 , 0 ) ;
V_69 -> V_75 = V_76 | V_77
| V_78 ;
return 0 ;
}
static int F_37 ( struct V_61 * V_61 , void * V_79 , struct V_80 * V_3 )
{
struct V_1 * V_8 ;
if ( V_3 -> V_81 >= V_5 )
return - V_19 ;
V_8 = & V_6 [ V_3 -> V_81 ] ;
V_3 -> V_10 = V_8 -> V_7 ;
strncpy ( V_3 -> V_82 , V_8 -> V_83 , sizeof( V_3 -> V_82 ) - 1 ) ;
return 0 ;
}
static int F_38 ( struct V_61 * V_61 , void * V_79 , struct V_2 * V_3 )
{
struct V_12 * V_13 = V_79 ;
struct V_20 * V_21 ;
struct V_11 * V_84 ;
V_21 = F_39 ( V_13 -> V_31 , V_3 -> type ) ;
if ( ! V_21 )
return - V_19 ;
V_84 = F_2 ( V_13 , V_3 -> type ) ;
if ( F_6 ( V_84 ) )
return F_7 ( V_84 ) ;
V_3 -> V_8 . V_9 . V_85 = V_84 -> V_85 ;
V_3 -> V_8 . V_9 . V_86 = V_84 -> V_86 ;
V_3 -> V_8 . V_9 . V_87 = V_88 ;
V_3 -> V_8 . V_9 . V_10 = V_84 -> V_8 -> V_7 ;
V_3 -> V_8 . V_9 . V_89 = ( V_84 -> V_85 * V_84 -> V_8 -> V_90 ) >> 3 ;
V_3 -> V_8 . V_9 . V_91 = V_84 -> V_26 ;
return 0 ;
}
static int F_40 ( struct V_61 * V_61 , void * V_79 , struct V_2 * V_3 )
{
struct V_1 * V_8 ;
enum V_92 * V_87 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
return - V_19 ;
V_87 = & V_3 -> V_8 . V_9 . V_87 ;
if ( * V_87 == V_93 )
* V_87 = V_88 ;
else if ( * V_87 != V_88 )
return - V_19 ;
if ( V_3 -> V_8 . V_9 . V_85 > V_94 )
V_3 -> V_8 . V_9 . V_85 = V_94 ;
if ( V_3 -> V_8 . V_9 . V_86 > V_95 )
V_3 -> V_8 . V_9 . V_86 = V_95 ;
if ( V_3 -> V_8 . V_9 . V_85 < 1 )
V_3 -> V_8 . V_9 . V_85 = 1 ;
if ( V_3 -> V_8 . V_9 . V_86 < 1 )
V_3 -> V_8 . V_9 . V_86 = 1 ;
V_3 -> V_8 . V_9 . V_89 = ( V_3 -> V_8 . V_9 . V_85 * V_8 -> V_90 ) >> 3 ;
V_3 -> V_8 . V_9 . V_91 = V_3 -> V_8 . V_9 . V_86 * V_3 -> V_8 . V_9 . V_89 ;
return 0 ;
}
static int F_41 ( struct V_61 * V_61 , void * V_79 , struct V_2 * V_3 )
{
struct V_12 * V_13 = V_79 ;
struct V_58 * V_27 = V_13 -> V_27 ;
struct V_20 * V_21 ;
struct V_11 * V_84 ;
struct V_1 * V_8 ;
int V_35 = 0 ;
V_35 = F_40 ( V_61 , V_79 , V_3 ) ;
if ( V_35 )
return V_35 ;
V_21 = F_39 ( V_13 -> V_31 , V_3 -> type ) ;
if ( F_42 ( V_21 ) ) {
F_16 ( & V_27 -> V_57 , L_5 , V_3 -> type ) ;
return - V_96 ;
}
V_84 = F_2 ( V_13 , V_3 -> type ) ;
if ( F_6 ( V_84 ) )
return F_7 ( V_84 ) ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
return - V_19 ;
V_84 -> V_85 = V_3 -> V_8 . V_9 . V_85 ;
V_84 -> V_86 = V_3 -> V_8 . V_9 . V_86 ;
V_84 -> V_26 = V_3 -> V_8 . V_9 . V_91 ;
V_84 -> V_97 = 0 ;
V_84 -> V_98 = 0 ;
V_84 -> V_99 = V_84 -> V_85 ;
V_84 -> V_100 = V_84 -> V_86 ;
V_84 -> V_101 = V_84 -> V_85 ;
V_84 -> V_102 = V_84 -> V_86 ;
V_84 -> V_8 = V_8 ;
V_84 -> V_103 = V_3 -> V_8 . V_9 . V_89 ;
return 0 ;
}
static unsigned int F_43 ( struct V_61 * V_61 , struct V_104 * V_105 )
{
struct V_12 * V_13 = F_31 ( V_61 -> V_67 ) ;
return F_44 ( V_61 , V_13 -> V_31 , V_105 ) ;
}
static int F_45 ( struct V_61 * V_61 , struct V_106 * V_107 )
{
struct V_12 * V_13 = F_31 ( V_61 -> V_67 ) ;
return F_46 ( V_61 , V_13 -> V_31 , V_107 ) ;
}
static int F_47 ( struct V_61 * V_61 , void * V_32 ,
struct V_108 * V_109 )
{
struct V_12 * V_13 = V_32 ;
return F_48 ( V_61 , V_13 -> V_31 , V_109 ) ;
}
static int F_49 ( struct V_61 * V_61 , void * V_32 ,
struct V_110 * V_111 )
{
struct V_12 * V_13 = V_32 ;
return F_50 ( V_61 , V_13 -> V_31 , V_111 ) ;
}
static int F_51 ( struct V_61 * V_61 , void * V_32 , struct V_110 * V_111 )
{
struct V_12 * V_13 = V_32 ;
return F_52 ( V_61 , V_13 -> V_31 , V_111 ) ;
}
static int F_53 ( struct V_61 * V_61 , void * V_32 , struct V_110 * V_111 )
{
struct V_12 * V_13 = V_32 ;
return F_54 ( V_61 , V_13 -> V_31 , V_111 ) ;
}
static int F_55 ( struct V_61 * V_61 , void * V_32 ,
enum V_14 type )
{
struct V_12 * V_13 = V_32 ;
return F_56 ( V_61 , V_13 -> V_31 , type ) ;
}
static int F_57 ( struct V_61 * V_61 , void * V_32 ,
enum V_14 type )
{
struct V_12 * V_13 = V_32 ;
return F_58 ( V_61 , V_13 -> V_31 , type ) ;
}
static int F_59 ( struct V_61 * V_61 , void * V_32 ,
struct V_112 * V_113 )
{
struct V_12 * V_13 = V_32 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_113 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_113 -> V_114 . V_115 = 0 ;
V_113 -> V_114 . V_116 = 0 ;
V_113 -> V_114 . V_85 = V_3 -> V_85 ;
V_113 -> V_114 . V_86 = V_3 -> V_86 ;
V_113 -> V_117 = V_113 -> V_114 ;
return 0 ;
}
static int F_60 ( struct V_61 * V_61 , void * V_79 , struct V_118 * V_113 )
{
struct V_12 * V_13 = V_79 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_113 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_113 -> V_119 . V_115 = V_3 -> V_98 ;
V_113 -> V_119 . V_116 = V_3 -> V_97 ;
V_113 -> V_119 . V_85 = V_3 -> V_99 ;
V_113 -> V_119 . V_86 = V_3 -> V_100 ;
return 0 ;
}
static int F_61 ( struct V_61 * V_61 , void * V_79 , struct V_118 * V_113 )
{
struct V_12 * V_13 = V_79 ;
struct V_58 * V_27 = V_13 -> V_27 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_113 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
if ( V_113 -> V_119 . V_116 < 0 || V_113 -> V_119 . V_115 < 0 ) {
F_16 ( & V_27 -> V_57 ,
L_6 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_62 ( struct V_61 * V_61 , void * V_79 , struct V_118 * V_113 )
{
struct V_12 * V_13 = V_79 ;
struct V_11 * V_3 ;
int V_35 ;
V_35 = F_61 ( V_61 , V_79 , V_113 ) ;
if ( V_35 )
return V_35 ;
V_3 = F_2 ( V_13 , V_113 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_3 -> V_99 = V_113 -> V_119 . V_85 ;
V_3 -> V_100 = V_113 -> V_119 . V_86 ;
V_3 -> V_97 = V_113 -> V_119 . V_115 ;
V_3 -> V_98 = V_113 -> V_119 . V_116 ;
V_3 -> V_102 = V_3 -> V_98 + V_3 -> V_100 ;
V_3 -> V_101 = V_3 -> V_97 + V_3 -> V_99 ;
return 0 ;
}
static void F_63 ( void * V_79 )
{
struct V_12 * V_13 = V_79 ;
struct V_58 * V_27 = V_13 -> V_27 ;
F_64 ( & V_27 -> V_120 ) ;
}
static void F_65 ( void * V_79 )
{
struct V_12 * V_13 = V_79 ;
struct V_58 * V_27 = V_13 -> V_27 ;
F_66 ( & V_27 -> V_120 ) ;
}
static void F_67 ( void * V_79 )
{
struct V_12 * V_13 = V_79 ;
struct V_58 * V_27 = V_13 -> V_27 ;
int V_35 ;
if ( V_27 -> V_121 == 0 )
return;
V_35 = F_68 ( V_27 -> V_122 ,
V_27 -> V_121 == 0 ,
F_69 ( V_123 ) ) ;
}
static void F_70 ( void * V_79 )
{
struct V_12 * V_13 = V_79 ;
struct V_58 * V_27 = V_13 -> V_27 ;
struct V_29 * V_124 , * V_125 ;
T_1 V_126 = 0 ;
V_27 -> V_121 = V_13 ;
V_124 = F_71 ( V_13 -> V_31 ) ;
V_125 = F_72 ( V_13 -> V_31 ) ;
F_73 ( V_27 -> V_127 ) ;
F_74 ( V_27 ) ;
F_75 ( V_27 , & V_13 -> V_16 ) ;
F_76 ( V_27 , F_77 ( V_124 , 0 ) ) ;
F_78 ( V_27 , & V_13 -> V_18 ) ;
F_79 ( V_27 , F_77 ( V_125 , 0 ) ) ;
F_80 ( V_27 , V_13 -> V_54 ) ;
if ( V_13 -> V_16 . V_99 != V_13 -> V_18 . V_99 ||
V_13 -> V_16 . V_100 != V_13 -> V_18 . V_100 )
V_126 |= F_81 ( 1 ) ;
F_82 ( V_27 , V_126 ) ;
F_83 ( V_27 ) ;
}
static T_2 F_84 ( int V_128 , void * V_79 )
{
struct V_58 * V_27 = V_79 ;
struct V_12 * V_13 = V_27 -> V_121 ;
struct V_29 * V_124 , * V_125 ;
F_85 ( V_27 ) ;
F_86 ( V_27 -> V_127 ) ;
F_87 ( V_13 == 0 ) ;
V_124 = F_88 ( V_13 -> V_31 ) ;
V_125 = F_89 ( V_13 -> V_31 ) ;
F_87 ( V_124 == 0 ) ;
F_87 ( V_125 == 0 ) ;
F_90 ( V_124 , V_129 ) ;
F_90 ( V_125 , V_129 ) ;
F_91 ( V_27 -> V_65 , V_13 -> V_31 ) ;
V_27 -> V_121 = 0 ;
F_92 ( & V_27 -> V_122 ) ;
return V_130 ;
}
static int F_93 ( struct V_131 * V_132 )
{
struct V_58 * V_27 ;
struct V_133 * V_134 ;
struct V_135 * V_136 ;
int V_35 = 0 ;
V_27 = F_22 ( sizeof( * V_27 ) , V_62 ) ;
if ( ! V_27 )
return - V_63 ;
F_94 ( & V_27 -> V_137 ) ;
F_95 ( & V_27 -> V_120 ) ;
F_96 ( & V_27 -> V_138 , 0 ) ;
F_97 ( & V_27 -> V_122 ) ;
V_136 = F_98 ( V_132 , V_139 , 0 ) ;
if ( ! V_136 ) {
F_99 ( & V_132 -> V_27 , L_7 ) ;
V_35 = - V_140 ;
goto V_141;
}
V_27 -> V_142 = F_100 ( V_136 -> V_143 , F_101 ( V_136 ) ,
F_102 ( & V_132 -> V_27 ) ) ;
if ( ! V_27 -> V_142 ) {
F_99 ( & V_132 -> V_27 , L_8 ) ;
V_35 = - V_140 ;
goto V_141;
}
V_27 -> V_144 = F_103 ( V_136 -> V_143 , F_101 ( V_136 ) ) ;
if ( ! V_27 -> V_144 ) {
F_99 ( & V_132 -> V_27 , L_9 ) ;
V_35 = - V_140 ;
goto V_145;
}
V_27 -> V_146 = F_104 ( & V_132 -> V_27 , L_10 ) ;
if ( F_105 ( V_27 -> V_146 ) ) {
F_99 ( & V_132 -> V_27 , L_11 ) ;
V_35 = - V_147 ;
goto V_148;
}
V_27 -> V_127 = F_104 ( & V_132 -> V_27 , L_12 ) ;
if ( F_105 ( V_27 -> V_127 ) ) {
F_99 ( & V_132 -> V_27 , L_13 ) ;
V_35 = - V_147 ;
goto V_149;
}
V_136 = F_98 ( V_132 , V_150 , 0 ) ;
if ( ! V_136 ) {
F_99 ( & V_132 -> V_27 , L_14 ) ;
V_35 = - V_147 ;
goto V_151;
}
V_27 -> V_128 = V_136 -> V_143 ;
V_35 = F_106 ( V_27 -> V_128 , F_84 , 0 , V_132 -> V_83 , V_27 ) ;
if ( V_35 ) {
F_99 ( & V_132 -> V_27 , L_15 ) ;
goto V_151;
}
V_27 -> V_28 = F_107 ( & V_132 -> V_27 ) ;
if ( F_6 ( V_27 -> V_28 ) ) {
V_35 = F_7 ( V_27 -> V_28 ) ;
goto V_152;
}
V_35 = F_108 ( & V_132 -> V_27 , & V_27 -> V_57 ) ;
if ( V_35 )
goto V_153;
V_134 = F_109 () ;
if ( ! V_134 ) {
F_16 ( & V_27 -> V_57 , L_16 ) ;
V_35 = - V_63 ;
goto V_154;
}
* V_134 = V_155 ;
V_134 -> V_156 = & V_27 -> V_120 ;
V_35 = F_110 ( V_134 , V_157 , 0 ) ;
if ( V_35 ) {
F_16 ( & V_27 -> V_57 , L_17 ) ;
goto V_158;
}
F_111 ( V_134 , V_27 ) ;
snprintf ( V_134 -> V_83 , sizeof( V_134 -> V_83 ) , L_18 , V_155 . V_83 ) ;
V_27 -> V_134 = V_134 ;
F_29 ( & V_27 -> V_57 , L_19 ,
V_134 -> V_159 ) ;
F_112 ( V_132 , V_27 ) ;
V_27 -> V_65 = F_113 ( & V_160 ) ;
if ( F_6 ( V_27 -> V_65 ) ) {
F_16 ( & V_27 -> V_57 , L_20 ) ;
V_35 = F_7 ( V_27 -> V_65 ) ;
goto V_161;
}
V_64 . V_103 = ( V_64 . V_85 * V_64 . V_8 -> V_90 ) >> 3 ;
return 0 ;
V_161:
F_114 ( V_27 -> V_134 ) ;
V_158:
F_115 ( V_134 ) ;
V_154:
F_116 ( & V_27 -> V_57 ) ;
V_153:
F_117 ( V_27 -> V_28 ) ;
V_152:
F_118 ( V_27 -> V_128 , V_27 ) ;
V_151:
F_119 ( V_27 -> V_127 ) ;
V_149:
F_119 ( V_27 -> V_146 ) ;
V_148:
F_120 ( V_27 -> V_144 ) ;
V_145:
F_121 ( V_27 -> V_142 ) ;
V_141:
F_24 ( V_27 ) ;
return V_35 ;
}
static int F_122 ( struct V_131 * V_132 )
{
struct V_58 * V_27 = (struct V_58 * ) F_123 ( V_132 ) ;
F_29 ( & V_27 -> V_57 , L_21 V_71 ) ;
F_124 ( V_27 -> V_65 ) ;
F_114 ( V_27 -> V_134 ) ;
F_116 ( & V_27 -> V_57 ) ;
F_117 ( V_27 -> V_28 ) ;
F_118 ( V_27 -> V_128 , V_27 ) ;
F_119 ( V_27 -> V_127 ) ;
F_119 ( V_27 -> V_146 ) ;
F_120 ( V_27 -> V_144 ) ;
F_121 ( V_27 -> V_142 ) ;
F_24 ( V_27 ) ;
return 0 ;
}

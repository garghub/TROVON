static struct V_1 * F_1 ( struct V_2 * V_3 )
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
V_33 -> type = V_15 ;
V_33 -> V_36 = V_37 | V_38 ;
V_33 -> V_39 = V_13 ;
V_33 -> V_40 = & V_41 ;
V_33 -> V_42 = & V_43 ;
V_33 -> V_44 = sizeof( struct V_45 ) ;
V_35 = F_13 ( V_33 ) ;
if ( V_35 )
return V_35 ;
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
unsigned long V_50 ;
F_16 ( & V_13 -> V_27 -> V_51 , V_50 ) ;
switch ( V_47 -> V_52 ) {
case V_53 :
if ( V_47 -> V_54 == V_55 )
V_13 -> V_56 = V_57 ;
else
V_13 -> V_56 = V_58 ;
break;
case V_59 :
V_13 -> V_60 = V_13 -> V_61 -> V_54 | ( V_13 -> V_62 -> V_54 << 1 ) ;
break;
}
F_17 ( & V_13 -> V_27 -> V_51 , V_50 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 )
{
struct V_63 * V_27 = V_13 -> V_27 ;
F_19 ( & V_13 -> V_49 , 3 ) ;
V_13 -> V_61 = F_20 ( & V_13 -> V_49 , & V_64 ,
V_59 , 0 , 1 , 1 , 0 ) ;
V_13 -> V_62 = F_20 ( & V_13 -> V_49 , & V_64 ,
V_65 , 0 , 1 , 1 , 0 ) ;
F_21 (
& V_13 -> V_49 ,
& V_64 ,
V_53 ,
V_55 ,
~ ( ( 1 << V_66 ) | ( 1 << V_55 ) ) ,
V_66 ) ;
if ( V_13 -> V_49 . error ) {
int V_67 = V_13 -> V_49 . error ;
F_22 ( & V_27 -> V_68 , L_1 ) ;
F_23 ( & V_13 -> V_49 ) ;
return V_67 ;
}
F_24 ( 2 , & V_13 -> V_61 ) ;
return 0 ;
}
static int F_25 ( struct V_69 * V_69 )
{
struct V_63 * V_27 = F_26 ( V_69 ) ;
struct V_12 * V_13 = NULL ;
int V_35 = 0 ;
V_13 = F_27 ( sizeof( * V_13 ) , V_70 ) ;
if ( ! V_13 )
return - V_71 ;
V_13 -> V_27 = V_27 ;
V_13 -> V_16 = V_72 ;
V_13 -> V_18 = V_72 ;
if ( F_28 ( & V_27 -> V_73 ) ) {
F_29 ( V_13 ) ;
return - V_74 ;
}
V_13 -> V_31 = F_30 ( V_27 -> V_75 , V_13 , & F_12 ) ;
if ( F_6 ( V_13 -> V_31 ) ) {
V_35 = F_7 ( V_13 -> V_31 ) ;
F_31 ( & V_27 -> V_73 ) ;
F_29 ( V_13 ) ;
return V_35 ;
}
F_32 ( & V_13 -> V_76 , F_33 ( V_69 ) ) ;
V_69 -> V_77 = & V_13 -> V_76 ;
F_34 ( & V_13 -> V_76 ) ;
F_18 ( V_13 ) ;
F_35 ( & V_13 -> V_49 ) ;
V_13 -> V_76 . V_49 = & V_13 -> V_49 ;
F_31 ( & V_27 -> V_73 ) ;
F_36 ( & V_27 -> V_68 , L_2 ) ;
return 0 ;
}
static int F_37 ( struct V_69 * V_69 )
{
struct V_63 * V_27 = F_26 ( V_69 ) ;
struct V_12 * V_13 = F_38 ( V_69 -> V_77 ) ;
F_23 ( & V_13 -> V_49 ) ;
F_39 ( & V_13 -> V_76 ) ;
F_40 ( & V_13 -> V_76 ) ;
F_29 ( V_13 ) ;
F_36 ( & V_27 -> V_68 , L_3 ) ;
return 0 ;
}
static int F_41 ( struct V_69 * V_69 , void * V_32 ,
struct V_78 * V_79 )
{
strncpy ( V_79 -> V_80 , V_81 , sizeof( V_79 -> V_80 ) - 1 ) ;
strncpy ( V_79 -> V_82 , V_81 , sizeof( V_79 -> V_82 ) - 1 ) ;
V_79 -> V_83 [ 0 ] = 0 ;
V_79 -> V_84 = F_42 ( 1 , 0 , 0 ) ;
V_79 -> V_85 = V_86 | V_87 |
V_88 | V_89 ;
return 0 ;
}
static int F_43 ( struct V_69 * V_69 , void * V_90 , struct V_91 * V_3 )
{
struct V_1 * V_8 ;
if ( V_3 -> V_92 >= V_5 )
return - V_19 ;
V_8 = & V_6 [ V_3 -> V_92 ] ;
V_3 -> V_10 = V_8 -> V_7 ;
strncpy ( V_3 -> V_93 , V_8 -> V_94 , sizeof( V_3 -> V_93 ) - 1 ) ;
return 0 ;
}
static int F_44 ( struct V_69 * V_69 , void * V_90 , struct V_2 * V_3 )
{
struct V_12 * V_13 = V_90 ;
struct V_20 * V_21 ;
struct V_11 * V_95 ;
V_21 = F_45 ( V_13 -> V_31 , V_3 -> type ) ;
if ( ! V_21 )
return - V_19 ;
V_95 = F_2 ( V_13 , V_3 -> type ) ;
if ( F_6 ( V_95 ) )
return F_7 ( V_95 ) ;
V_3 -> V_8 . V_9 . V_96 = V_95 -> V_96 ;
V_3 -> V_8 . V_9 . V_97 = V_95 -> V_97 ;
V_3 -> V_8 . V_9 . V_98 = V_99 ;
V_3 -> V_8 . V_9 . V_10 = V_95 -> V_8 -> V_7 ;
V_3 -> V_8 . V_9 . V_100 = ( V_95 -> V_96 * V_95 -> V_8 -> V_101 ) >> 3 ;
V_3 -> V_8 . V_9 . V_102 = V_95 -> V_26 ;
return 0 ;
}
static int F_46 ( struct V_69 * V_69 , void * V_90 , struct V_2 * V_3 )
{
struct V_1 * V_8 ;
enum V_103 * V_98 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
return - V_19 ;
V_98 = & V_3 -> V_8 . V_9 . V_98 ;
if ( * V_98 == V_104 )
* V_98 = V_99 ;
else if ( * V_98 != V_99 )
return - V_19 ;
if ( V_3 -> V_8 . V_9 . V_96 > V_105 )
V_3 -> V_8 . V_9 . V_96 = V_105 ;
if ( V_3 -> V_8 . V_9 . V_97 > V_106 )
V_3 -> V_8 . V_9 . V_97 = V_106 ;
if ( V_3 -> V_8 . V_9 . V_96 < 1 )
V_3 -> V_8 . V_9 . V_96 = 1 ;
if ( V_3 -> V_8 . V_9 . V_97 < 1 )
V_3 -> V_8 . V_9 . V_97 = 1 ;
V_3 -> V_8 . V_9 . V_100 = ( V_3 -> V_8 . V_9 . V_96 * V_8 -> V_101 ) >> 3 ;
V_3 -> V_8 . V_9 . V_102 = V_3 -> V_8 . V_9 . V_97 * V_3 -> V_8 . V_9 . V_100 ;
return 0 ;
}
static int F_47 ( struct V_69 * V_69 , void * V_90 , struct V_2 * V_3 )
{
struct V_12 * V_13 = V_90 ;
struct V_63 * V_27 = V_13 -> V_27 ;
struct V_20 * V_21 ;
struct V_11 * V_95 ;
struct V_1 * V_8 ;
int V_35 = 0 ;
V_35 = F_46 ( V_69 , V_90 , V_3 ) ;
if ( V_35 )
return V_35 ;
V_21 = F_45 ( V_13 -> V_31 , V_3 -> type ) ;
if ( F_48 ( V_21 ) ) {
F_22 ( & V_27 -> V_68 , L_4 , V_3 -> type ) ;
return - V_107 ;
}
V_95 = F_2 ( V_13 , V_3 -> type ) ;
if ( F_6 ( V_95 ) )
return F_7 ( V_95 ) ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
return - V_19 ;
V_95 -> V_96 = V_3 -> V_8 . V_9 . V_96 ;
V_95 -> V_97 = V_3 -> V_8 . V_9 . V_97 ;
V_95 -> V_26 = V_3 -> V_8 . V_9 . V_102 ;
V_95 -> V_108 = 0 ;
V_95 -> V_109 = 0 ;
V_95 -> V_110 = V_95 -> V_96 ;
V_95 -> V_111 = V_95 -> V_97 ;
V_95 -> V_112 = V_95 -> V_96 ;
V_95 -> V_113 = V_95 -> V_97 ;
V_95 -> V_8 = V_8 ;
V_95 -> V_114 = V_3 -> V_8 . V_9 . V_100 ;
return 0 ;
}
static unsigned int F_49 ( struct V_69 * V_69 , struct V_115 * V_116 )
{
struct V_12 * V_13 = F_38 ( V_69 -> V_77 ) ;
struct V_63 * V_27 = V_13 -> V_27 ;
unsigned int V_117 ;
F_50 ( & V_27 -> V_73 ) ;
V_117 = F_51 ( V_69 , V_13 -> V_31 , V_116 ) ;
F_31 ( & V_27 -> V_73 ) ;
return V_117 ;
}
static int F_52 ( struct V_69 * V_69 , struct V_118 * V_119 )
{
struct V_12 * V_13 = F_38 ( V_69 -> V_77 ) ;
struct V_63 * V_27 = V_13 -> V_27 ;
int V_35 ;
if ( F_28 ( & V_27 -> V_73 ) )
return - V_74 ;
V_35 = F_53 ( V_69 , V_13 -> V_31 , V_119 ) ;
F_31 ( & V_27 -> V_73 ) ;
return V_35 ;
}
static int F_54 ( struct V_69 * V_69 , void * V_32 ,
struct V_120 * V_121 )
{
struct V_12 * V_13 = V_32 ;
return F_55 ( V_69 , V_13 -> V_31 , V_121 ) ;
}
static int F_56 ( struct V_69 * V_69 , void * V_32 ,
struct V_122 * V_123 )
{
struct V_12 * V_13 = V_32 ;
return F_57 ( V_69 , V_13 -> V_31 , V_123 ) ;
}
static int F_58 ( struct V_69 * V_69 , void * V_32 , struct V_122 * V_123 )
{
struct V_12 * V_13 = V_32 ;
return F_59 ( V_69 , V_13 -> V_31 , V_123 ) ;
}
static int F_60 ( struct V_69 * V_69 , void * V_32 , struct V_122 * V_123 )
{
struct V_12 * V_13 = V_32 ;
return F_61 ( V_69 , V_13 -> V_31 , V_123 ) ;
}
static int F_62 ( struct V_69 * V_69 , void * V_32 ,
enum V_14 type )
{
struct V_12 * V_13 = V_32 ;
return F_63 ( V_69 , V_13 -> V_31 , type ) ;
}
static int F_64 ( struct V_69 * V_69 , void * V_32 ,
enum V_14 type )
{
struct V_12 * V_13 = V_32 ;
return F_65 ( V_69 , V_13 -> V_31 , type ) ;
}
static int F_66 ( struct V_69 * V_69 , void * V_32 ,
struct V_124 * V_125 )
{
struct V_12 * V_13 = V_32 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_125 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_125 -> V_126 . V_127 = 0 ;
V_125 -> V_126 . V_128 = 0 ;
V_125 -> V_126 . V_96 = V_3 -> V_96 ;
V_125 -> V_126 . V_97 = V_3 -> V_97 ;
V_125 -> V_129 = V_125 -> V_126 ;
return 0 ;
}
static int F_67 ( struct V_69 * V_69 , void * V_90 , struct V_130 * V_125 )
{
struct V_12 * V_13 = V_90 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_125 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_125 -> V_131 . V_127 = V_3 -> V_109 ;
V_125 -> V_131 . V_128 = V_3 -> V_108 ;
V_125 -> V_131 . V_96 = V_3 -> V_110 ;
V_125 -> V_131 . V_97 = V_3 -> V_111 ;
return 0 ;
}
static int F_68 ( struct V_69 * V_69 , void * V_90 , const struct V_130 * V_125 )
{
struct V_12 * V_13 = V_90 ;
struct V_63 * V_27 = V_13 -> V_27 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_125 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
if ( V_125 -> V_131 . V_128 < 0 || V_125 -> V_131 . V_127 < 0 ) {
F_22 ( & V_27 -> V_68 ,
L_5 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_69 ( struct V_69 * V_69 , void * V_90 , const struct V_130 * V_125 )
{
struct V_12 * V_13 = V_90 ;
struct V_11 * V_3 ;
int V_35 ;
V_35 = F_68 ( V_69 , V_90 , V_125 ) ;
if ( V_35 )
return V_35 ;
V_3 = F_2 ( V_13 , V_125 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_3 -> V_110 = V_125 -> V_131 . V_96 ;
V_3 -> V_111 = V_125 -> V_131 . V_97 ;
V_3 -> V_108 = V_125 -> V_131 . V_127 ;
V_3 -> V_109 = V_125 -> V_131 . V_128 ;
V_3 -> V_113 = V_3 -> V_109 + V_3 -> V_111 ;
V_3 -> V_112 = V_3 -> V_108 + V_3 -> V_110 ;
return 0 ;
}
static void F_70 ( void * V_90 )
{
struct V_12 * V_13 = V_90 ;
struct V_63 * V_27 = V_13 -> V_27 ;
F_50 ( & V_27 -> V_73 ) ;
}
static void F_71 ( void * V_90 )
{
struct V_12 * V_13 = V_90 ;
struct V_63 * V_27 = V_13 -> V_27 ;
F_31 ( & V_27 -> V_73 ) ;
}
static void F_72 ( void * V_90 )
{
struct V_12 * V_13 = V_90 ;
struct V_63 * V_27 = V_13 -> V_27 ;
int V_35 ;
if ( V_27 -> V_132 == NULL )
return;
V_35 = F_73 ( V_27 -> V_133 ,
V_27 -> V_132 == NULL ,
F_74 ( V_134 ) ) ;
}
static void F_75 ( void * V_90 )
{
struct V_12 * V_13 = V_90 ;
struct V_63 * V_27 = V_13 -> V_27 ;
struct V_29 * V_135 , * V_136 ;
unsigned long V_50 ;
T_1 V_137 = 0 ;
V_27 -> V_132 = V_13 ;
V_135 = F_76 ( V_13 -> V_31 ) ;
V_136 = F_77 ( V_13 -> V_31 ) ;
F_78 ( V_27 -> V_138 ) ;
F_79 ( V_27 ) ;
F_16 ( & V_27 -> V_51 , V_50 ) ;
F_80 ( V_27 , & V_13 -> V_16 ) ;
F_81 ( V_27 , F_82 ( V_135 , 0 ) ) ;
F_83 ( V_27 , & V_13 -> V_18 ) ;
F_84 ( V_27 , F_82 ( V_136 , 0 ) ) ;
F_85 ( V_27 , V_13 -> V_56 ) ;
F_86 ( V_27 , V_13 -> V_60 ) ;
if ( V_13 -> V_16 . V_110 != V_13 -> V_18 . V_110 ||
V_13 -> V_16 . V_111 != V_13 -> V_18 . V_111 ) {
if ( V_27 -> V_139 -> V_140 == V_141 )
V_137 |= V_142 ;
else
F_87 ( V_27 , & V_13 -> V_16 , & V_13 -> V_18 ) ;
}
F_88 ( V_27 , V_137 ) ;
F_89 ( V_27 ) ;
F_17 ( & V_27 -> V_51 , V_50 ) ;
}
static T_2 F_90 ( int V_143 , void * V_90 )
{
struct V_63 * V_27 = V_90 ;
struct V_12 * V_13 = V_27 -> V_132 ;
struct V_29 * V_135 , * V_136 ;
F_91 ( V_27 ) ;
F_92 ( V_27 -> V_138 ) ;
F_93 ( V_13 == NULL ) ;
V_135 = F_94 ( V_13 -> V_31 ) ;
V_136 = F_95 ( V_13 -> V_31 ) ;
F_93 ( V_135 == NULL ) ;
F_93 ( V_136 == NULL ) ;
F_96 ( V_135 , V_144 ) ;
F_96 ( V_136 , V_144 ) ;
F_97 ( V_27 -> V_75 , V_13 -> V_31 ) ;
V_27 -> V_132 = NULL ;
F_98 ( & V_27 -> V_133 ) ;
return V_145 ;
}
static int F_99 ( struct V_146 * V_147 )
{
struct V_63 * V_27 ;
struct V_148 * V_149 ;
struct V_150 * V_117 ;
int V_35 = 0 ;
V_27 = F_100 ( & V_147 -> V_27 , sizeof( * V_27 ) , V_70 ) ;
if ( ! V_27 )
return - V_71 ;
F_101 ( & V_27 -> V_51 ) ;
F_102 ( & V_27 -> V_73 ) ;
F_103 ( & V_27 -> V_151 , 0 ) ;
F_104 ( & V_27 -> V_133 ) ;
V_117 = F_105 ( V_147 , V_152 , 0 ) ;
V_27 -> V_153 = F_106 ( & V_147 -> V_27 , V_117 ) ;
if ( F_6 ( V_27 -> V_153 ) )
return F_7 ( V_27 -> V_153 ) ;
V_27 -> V_154 = F_107 ( & V_147 -> V_27 , L_6 ) ;
if ( F_6 ( V_27 -> V_154 ) ) {
F_108 ( & V_147 -> V_27 , L_7 ) ;
return - V_155 ;
}
V_35 = F_109 ( V_27 -> V_154 ) ;
if ( V_35 ) {
F_108 ( & V_147 -> V_27 , L_8 ) ;
goto V_156;
}
V_27 -> V_138 = F_107 ( & V_147 -> V_27 , L_9 ) ;
if ( F_6 ( V_27 -> V_138 ) ) {
F_108 ( & V_147 -> V_27 , L_10 ) ;
V_35 = - V_155 ;
goto V_157;
}
V_35 = F_109 ( V_27 -> V_138 ) ;
if ( V_35 ) {
F_108 ( & V_147 -> V_27 , L_11 ) ;
goto V_158;
}
V_117 = F_105 ( V_147 , V_159 , 0 ) ;
if ( ! V_117 ) {
F_108 ( & V_147 -> V_27 , L_12 ) ;
V_35 = - V_155 ;
goto V_160;
}
V_27 -> V_143 = V_117 -> V_161 ;
V_35 = F_110 ( & V_147 -> V_27 , V_27 -> V_143 , F_90 ,
0 , V_147 -> V_94 , V_27 ) ;
if ( V_35 ) {
F_108 ( & V_147 -> V_27 , L_13 ) ;
goto V_158;
}
V_27 -> V_28 = F_111 ( & V_147 -> V_27 ) ;
if ( F_6 ( V_27 -> V_28 ) ) {
V_35 = F_7 ( V_27 -> V_28 ) ;
goto V_160;
}
V_35 = F_112 ( & V_147 -> V_27 , & V_27 -> V_68 ) ;
if ( V_35 )
goto V_162;
V_149 = F_113 () ;
if ( ! V_149 ) {
F_22 ( & V_27 -> V_68 , L_14 ) ;
V_35 = - V_71 ;
goto V_163;
}
* V_149 = V_164 ;
V_149 -> V_165 = & V_27 -> V_73 ;
V_35 = F_114 ( V_149 , V_166 , 0 ) ;
if ( V_35 ) {
F_22 ( & V_27 -> V_68 , L_15 ) ;
goto V_167;
}
F_115 ( V_149 , V_27 ) ;
snprintf ( V_149 -> V_94 , sizeof( V_149 -> V_94 ) , L_16 , V_164 . V_94 ) ;
V_27 -> V_149 = V_149 ;
F_36 ( & V_27 -> V_68 , L_17 ,
V_149 -> V_168 ) ;
F_116 ( V_147 , V_27 ) ;
V_27 -> V_75 = F_117 ( & V_169 ) ;
if ( F_6 ( V_27 -> V_75 ) ) {
F_22 ( & V_27 -> V_68 , L_18 ) ;
V_35 = F_7 ( V_27 -> V_75 ) ;
goto V_170;
}
V_72 . V_114 = ( V_72 . V_96 * V_72 . V_8 -> V_101 ) >> 3 ;
V_27 -> V_139 = F_118 ( V_147 ) ;
return 0 ;
V_170:
F_119 ( V_27 -> V_149 ) ;
V_167:
F_120 ( V_149 ) ;
V_163:
F_121 ( & V_27 -> V_68 ) ;
V_162:
F_122 ( V_27 -> V_28 ) ;
V_160:
F_123 ( V_27 -> V_138 ) ;
V_158:
F_124 ( V_27 -> V_138 ) ;
V_157:
F_123 ( V_27 -> V_154 ) ;
V_156:
F_124 ( V_27 -> V_154 ) ;
return V_35 ;
}
static int F_125 ( struct V_146 * V_147 )
{
struct V_63 * V_27 = (struct V_63 * ) F_126 ( V_147 ) ;
F_36 ( & V_27 -> V_68 , L_19 V_81 ) ;
F_127 ( V_27 -> V_75 ) ;
F_119 ( V_27 -> V_149 ) ;
F_121 ( & V_27 -> V_68 ) ;
F_122 ( V_27 -> V_28 ) ;
F_123 ( V_27 -> V_138 ) ;
F_124 ( V_27 -> V_138 ) ;
F_123 ( V_27 -> V_154 ) ;
F_124 ( V_27 -> V_154 ) ;
return 0 ;
}

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
V_13 -> V_31 = F_28 ( V_27 -> V_73 , V_13 , & F_12 ) ;
if ( F_6 ( V_13 -> V_31 ) ) {
V_35 = F_7 ( V_13 -> V_31 ) ;
F_29 ( V_13 ) ;
return V_35 ;
}
F_30 ( & V_13 -> V_74 , F_31 ( V_69 ) ) ;
V_69 -> V_75 = & V_13 -> V_74 ;
F_32 ( & V_13 -> V_74 ) ;
F_18 ( V_13 ) ;
F_33 ( & V_13 -> V_49 ) ;
V_13 -> V_74 . V_49 = & V_13 -> V_49 ;
F_34 ( & V_27 -> V_68 , L_2 ) ;
return 0 ;
}
static int F_35 ( struct V_69 * V_69 )
{
struct V_63 * V_27 = F_26 ( V_69 ) ;
struct V_12 * V_13 = F_36 ( V_69 -> V_75 ) ;
F_23 ( & V_13 -> V_49 ) ;
F_37 ( & V_13 -> V_74 ) ;
F_38 ( & V_13 -> V_74 ) ;
F_29 ( V_13 ) ;
F_34 ( & V_27 -> V_68 , L_3 ) ;
return 0 ;
}
static int F_39 ( struct V_69 * V_69 , void * V_32 ,
struct V_76 * V_77 )
{
strncpy ( V_77 -> V_78 , V_79 , sizeof( V_77 -> V_78 ) - 1 ) ;
strncpy ( V_77 -> V_80 , V_79 , sizeof( V_77 -> V_80 ) - 1 ) ;
V_77 -> V_81 [ 0 ] = 0 ;
V_77 -> V_82 = F_40 ( 1 , 0 , 0 ) ;
V_77 -> V_83 = V_84 | V_85
| V_86 ;
return 0 ;
}
static int F_41 ( struct V_69 * V_69 , void * V_87 , struct V_88 * V_3 )
{
struct V_1 * V_8 ;
if ( V_3 -> V_89 >= V_5 )
return - V_19 ;
V_8 = & V_6 [ V_3 -> V_89 ] ;
V_3 -> V_10 = V_8 -> V_7 ;
strncpy ( V_3 -> V_90 , V_8 -> V_91 , sizeof( V_3 -> V_90 ) - 1 ) ;
return 0 ;
}
static int F_42 ( struct V_69 * V_69 , void * V_87 , struct V_2 * V_3 )
{
struct V_12 * V_13 = V_87 ;
struct V_20 * V_21 ;
struct V_11 * V_92 ;
V_21 = F_43 ( V_13 -> V_31 , V_3 -> type ) ;
if ( ! V_21 )
return - V_19 ;
V_92 = F_2 ( V_13 , V_3 -> type ) ;
if ( F_6 ( V_92 ) )
return F_7 ( V_92 ) ;
V_3 -> V_8 . V_9 . V_93 = V_92 -> V_93 ;
V_3 -> V_8 . V_9 . V_94 = V_92 -> V_94 ;
V_3 -> V_8 . V_9 . V_95 = V_96 ;
V_3 -> V_8 . V_9 . V_10 = V_92 -> V_8 -> V_7 ;
V_3 -> V_8 . V_9 . V_97 = ( V_92 -> V_93 * V_92 -> V_8 -> V_98 ) >> 3 ;
V_3 -> V_8 . V_9 . V_99 = V_92 -> V_26 ;
return 0 ;
}
static int F_44 ( struct V_69 * V_69 , void * V_87 , struct V_2 * V_3 )
{
struct V_1 * V_8 ;
enum V_100 * V_95 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
return - V_19 ;
V_95 = & V_3 -> V_8 . V_9 . V_95 ;
if ( * V_95 == V_101 )
* V_95 = V_96 ;
else if ( * V_95 != V_96 )
return - V_19 ;
if ( V_3 -> V_8 . V_9 . V_93 > V_102 )
V_3 -> V_8 . V_9 . V_93 = V_102 ;
if ( V_3 -> V_8 . V_9 . V_94 > V_103 )
V_3 -> V_8 . V_9 . V_94 = V_103 ;
if ( V_3 -> V_8 . V_9 . V_93 < 1 )
V_3 -> V_8 . V_9 . V_93 = 1 ;
if ( V_3 -> V_8 . V_9 . V_94 < 1 )
V_3 -> V_8 . V_9 . V_94 = 1 ;
V_3 -> V_8 . V_9 . V_97 = ( V_3 -> V_8 . V_9 . V_93 * V_8 -> V_98 ) >> 3 ;
V_3 -> V_8 . V_9 . V_99 = V_3 -> V_8 . V_9 . V_94 * V_3 -> V_8 . V_9 . V_97 ;
return 0 ;
}
static int F_45 ( struct V_69 * V_69 , void * V_87 , struct V_2 * V_3 )
{
struct V_12 * V_13 = V_87 ;
struct V_63 * V_27 = V_13 -> V_27 ;
struct V_20 * V_21 ;
struct V_11 * V_92 ;
struct V_1 * V_8 ;
int V_35 = 0 ;
V_35 = F_44 ( V_69 , V_87 , V_3 ) ;
if ( V_35 )
return V_35 ;
V_21 = F_43 ( V_13 -> V_31 , V_3 -> type ) ;
if ( F_46 ( V_21 ) ) {
F_22 ( & V_27 -> V_68 , L_4 , V_3 -> type ) ;
return - V_104 ;
}
V_92 = F_2 ( V_13 , V_3 -> type ) ;
if ( F_6 ( V_92 ) )
return F_7 ( V_92 ) ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
return - V_19 ;
V_92 -> V_93 = V_3 -> V_8 . V_9 . V_93 ;
V_92 -> V_94 = V_3 -> V_8 . V_9 . V_94 ;
V_92 -> V_26 = V_3 -> V_8 . V_9 . V_99 ;
V_92 -> V_105 = 0 ;
V_92 -> V_106 = 0 ;
V_92 -> V_107 = V_92 -> V_93 ;
V_92 -> V_108 = V_92 -> V_94 ;
V_92 -> V_109 = V_92 -> V_93 ;
V_92 -> V_110 = V_92 -> V_94 ;
V_92 -> V_8 = V_8 ;
V_92 -> V_111 = V_3 -> V_8 . V_9 . V_97 ;
return 0 ;
}
static unsigned int F_47 ( struct V_69 * V_69 , struct V_112 * V_113 )
{
struct V_12 * V_13 = F_36 ( V_69 -> V_75 ) ;
return F_48 ( V_69 , V_13 -> V_31 , V_113 ) ;
}
static int F_49 ( struct V_69 * V_69 , struct V_114 * V_115 )
{
struct V_12 * V_13 = F_36 ( V_69 -> V_75 ) ;
return F_50 ( V_69 , V_13 -> V_31 , V_115 ) ;
}
static int F_51 ( struct V_69 * V_69 , void * V_32 ,
struct V_116 * V_117 )
{
struct V_12 * V_13 = V_32 ;
return F_52 ( V_69 , V_13 -> V_31 , V_117 ) ;
}
static int F_53 ( struct V_69 * V_69 , void * V_32 ,
struct V_118 * V_119 )
{
struct V_12 * V_13 = V_32 ;
return F_54 ( V_69 , V_13 -> V_31 , V_119 ) ;
}
static int F_55 ( struct V_69 * V_69 , void * V_32 , struct V_118 * V_119 )
{
struct V_12 * V_13 = V_32 ;
return F_56 ( V_69 , V_13 -> V_31 , V_119 ) ;
}
static int F_57 ( struct V_69 * V_69 , void * V_32 , struct V_118 * V_119 )
{
struct V_12 * V_13 = V_32 ;
return F_58 ( V_69 , V_13 -> V_31 , V_119 ) ;
}
static int F_59 ( struct V_69 * V_69 , void * V_32 ,
enum V_14 type )
{
struct V_12 * V_13 = V_32 ;
return F_60 ( V_69 , V_13 -> V_31 , type ) ;
}
static int F_61 ( struct V_69 * V_69 , void * V_32 ,
enum V_14 type )
{
struct V_12 * V_13 = V_32 ;
return F_62 ( V_69 , V_13 -> V_31 , type ) ;
}
static int F_63 ( struct V_69 * V_69 , void * V_32 ,
struct V_120 * V_121 )
{
struct V_12 * V_13 = V_32 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_121 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_121 -> V_122 . V_123 = 0 ;
V_121 -> V_122 . V_124 = 0 ;
V_121 -> V_122 . V_93 = V_3 -> V_93 ;
V_121 -> V_122 . V_94 = V_3 -> V_94 ;
V_121 -> V_125 = V_121 -> V_122 ;
return 0 ;
}
static int F_64 ( struct V_69 * V_69 , void * V_87 , struct V_126 * V_121 )
{
struct V_12 * V_13 = V_87 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_121 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_121 -> V_127 . V_123 = V_3 -> V_106 ;
V_121 -> V_127 . V_124 = V_3 -> V_105 ;
V_121 -> V_127 . V_93 = V_3 -> V_107 ;
V_121 -> V_127 . V_94 = V_3 -> V_108 ;
return 0 ;
}
static int F_65 ( struct V_69 * V_69 , void * V_87 , struct V_126 * V_121 )
{
struct V_12 * V_13 = V_87 ;
struct V_63 * V_27 = V_13 -> V_27 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_121 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
if ( V_121 -> V_127 . V_124 < 0 || V_121 -> V_127 . V_123 < 0 ) {
F_22 ( & V_27 -> V_68 ,
L_5 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_66 ( struct V_69 * V_69 , void * V_87 , struct V_126 * V_121 )
{
struct V_12 * V_13 = V_87 ;
struct V_11 * V_3 ;
int V_35 ;
V_35 = F_65 ( V_69 , V_87 , V_121 ) ;
if ( V_35 )
return V_35 ;
V_3 = F_2 ( V_13 , V_121 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_3 -> V_107 = V_121 -> V_127 . V_93 ;
V_3 -> V_108 = V_121 -> V_127 . V_94 ;
V_3 -> V_105 = V_121 -> V_127 . V_123 ;
V_3 -> V_106 = V_121 -> V_127 . V_124 ;
V_3 -> V_110 = V_3 -> V_106 + V_3 -> V_108 ;
V_3 -> V_109 = V_3 -> V_105 + V_3 -> V_107 ;
return 0 ;
}
static void F_67 ( void * V_87 )
{
struct V_12 * V_13 = V_87 ;
struct V_63 * V_27 = V_13 -> V_27 ;
F_68 ( & V_27 -> V_128 ) ;
}
static void F_69 ( void * V_87 )
{
struct V_12 * V_13 = V_87 ;
struct V_63 * V_27 = V_13 -> V_27 ;
F_70 ( & V_27 -> V_128 ) ;
}
static void F_71 ( void * V_87 )
{
struct V_12 * V_13 = V_87 ;
struct V_63 * V_27 = V_13 -> V_27 ;
int V_35 ;
if ( V_27 -> V_129 == NULL )
return;
V_35 = F_72 ( V_27 -> V_130 ,
V_27 -> V_129 == NULL ,
F_73 ( V_131 ) ) ;
}
static void F_74 ( void * V_87 )
{
struct V_12 * V_13 = V_87 ;
struct V_63 * V_27 = V_13 -> V_27 ;
struct V_29 * V_132 , * V_133 ;
unsigned long V_50 ;
T_1 V_134 = 0 ;
V_27 -> V_129 = V_13 ;
V_132 = F_75 ( V_13 -> V_31 ) ;
V_133 = F_76 ( V_13 -> V_31 ) ;
F_77 ( V_27 -> V_135 ) ;
F_78 ( V_27 ) ;
F_16 ( & V_27 -> V_51 , V_50 ) ;
F_79 ( V_27 , & V_13 -> V_16 ) ;
F_80 ( V_27 , F_81 ( V_132 , 0 ) ) ;
F_82 ( V_27 , & V_13 -> V_18 ) ;
F_83 ( V_27 , F_81 ( V_133 , 0 ) ) ;
F_84 ( V_27 , V_13 -> V_56 ) ;
F_85 ( V_27 , V_13 -> V_60 ) ;
if ( V_13 -> V_16 . V_107 != V_13 -> V_18 . V_107 ||
V_13 -> V_16 . V_108 != V_13 -> V_18 . V_108 )
V_134 |= F_86 ( 1 ) ;
F_87 ( V_27 , V_134 ) ;
F_88 ( V_27 ) ;
F_17 ( & V_27 -> V_51 , V_50 ) ;
}
static T_2 F_89 ( int V_136 , void * V_87 )
{
struct V_63 * V_27 = V_87 ;
struct V_12 * V_13 = V_27 -> V_129 ;
struct V_29 * V_132 , * V_133 ;
F_90 ( V_27 ) ;
F_91 ( V_27 -> V_135 ) ;
F_92 ( V_13 == NULL ) ;
V_132 = F_93 ( V_13 -> V_31 ) ;
V_133 = F_94 ( V_13 -> V_31 ) ;
F_92 ( V_132 == NULL ) ;
F_92 ( V_133 == NULL ) ;
F_95 ( V_132 , V_137 ) ;
F_95 ( V_133 , V_137 ) ;
F_96 ( V_27 -> V_73 , V_13 -> V_31 ) ;
V_27 -> V_129 = NULL ;
F_97 ( & V_27 -> V_130 ) ;
return V_138 ;
}
static int F_98 ( struct V_139 * V_140 )
{
struct V_63 * V_27 ;
struct V_141 * V_142 ;
struct V_143 * V_144 ;
int V_35 = 0 ;
V_27 = F_99 ( & V_140 -> V_27 , sizeof( * V_27 ) , V_70 ) ;
if ( ! V_27 )
return - V_71 ;
F_100 ( & V_27 -> V_51 ) ;
F_101 ( & V_27 -> V_128 ) ;
F_102 ( & V_27 -> V_145 , 0 ) ;
F_103 ( & V_27 -> V_130 ) ;
V_144 = F_104 ( V_140 , V_146 , 0 ) ;
V_27 -> V_147 = F_105 ( & V_140 -> V_27 , V_144 ) ;
if ( V_27 -> V_147 == NULL ) {
F_106 ( & V_140 -> V_27 , L_6 ) ;
return - V_148 ;
}
V_27 -> V_149 = F_107 ( & V_140 -> V_27 , L_7 ) ;
if ( F_108 ( V_27 -> V_149 ) ) {
F_106 ( & V_140 -> V_27 , L_8 ) ;
return - V_150 ;
}
V_35 = F_109 ( V_27 -> V_149 ) ;
if ( V_35 ) {
F_106 ( & V_140 -> V_27 , L_9 ) ;
goto V_151;
}
V_27 -> V_135 = F_107 ( & V_140 -> V_27 , L_10 ) ;
if ( F_108 ( V_27 -> V_135 ) ) {
F_106 ( & V_140 -> V_27 , L_11 ) ;
V_35 = - V_150 ;
goto V_152;
}
V_35 = F_109 ( V_27 -> V_135 ) ;
if ( V_35 ) {
F_106 ( & V_140 -> V_27 , L_12 ) ;
goto V_153;
}
V_144 = F_104 ( V_140 , V_154 , 0 ) ;
if ( ! V_144 ) {
F_106 ( & V_140 -> V_27 , L_13 ) ;
V_35 = - V_150 ;
goto V_155;
}
V_27 -> V_136 = V_144 -> V_156 ;
V_35 = F_110 ( & V_140 -> V_27 , V_27 -> V_136 , F_89 ,
0 , V_140 -> V_91 , V_27 ) ;
if ( V_35 ) {
F_106 ( & V_140 -> V_27 , L_14 ) ;
goto V_153;
}
V_27 -> V_28 = F_111 ( & V_140 -> V_27 ) ;
if ( F_6 ( V_27 -> V_28 ) ) {
V_35 = F_7 ( V_27 -> V_28 ) ;
goto V_155;
}
V_35 = F_112 ( & V_140 -> V_27 , & V_27 -> V_68 ) ;
if ( V_35 )
goto V_157;
V_142 = F_113 () ;
if ( ! V_142 ) {
F_22 ( & V_27 -> V_68 , L_15 ) ;
V_35 = - V_71 ;
goto V_158;
}
* V_142 = V_159 ;
F_114 ( V_160 , & V_142 -> V_50 ) ;
V_142 -> V_161 = & V_27 -> V_128 ;
V_35 = F_115 ( V_142 , V_162 , 0 ) ;
if ( V_35 ) {
F_22 ( & V_27 -> V_68 , L_16 ) ;
goto V_163;
}
F_116 ( V_142 , V_27 ) ;
snprintf ( V_142 -> V_91 , sizeof( V_142 -> V_91 ) , L_17 , V_159 . V_91 ) ;
V_27 -> V_142 = V_142 ;
F_34 ( & V_27 -> V_68 , L_18 ,
V_142 -> V_164 ) ;
F_117 ( V_140 , V_27 ) ;
V_27 -> V_73 = F_118 ( & V_165 ) ;
if ( F_6 ( V_27 -> V_73 ) ) {
F_22 ( & V_27 -> V_68 , L_19 ) ;
V_35 = F_7 ( V_27 -> V_73 ) ;
goto V_166;
}
V_72 . V_111 = ( V_72 . V_93 * V_72 . V_8 -> V_98 ) >> 3 ;
return 0 ;
V_166:
F_119 ( V_27 -> V_142 ) ;
V_163:
F_120 ( V_142 ) ;
V_158:
F_121 ( & V_27 -> V_68 ) ;
V_157:
F_122 ( V_27 -> V_28 ) ;
V_155:
F_123 ( V_27 -> V_135 ) ;
V_153:
F_124 ( V_27 -> V_135 ) ;
V_152:
F_123 ( V_27 -> V_149 ) ;
V_151:
F_124 ( V_27 -> V_149 ) ;
return V_35 ;
}
static int F_125 ( struct V_139 * V_140 )
{
struct V_63 * V_27 = (struct V_63 * ) F_126 ( V_140 ) ;
F_34 ( & V_27 -> V_68 , L_20 V_79 ) ;
F_127 ( V_27 -> V_73 ) ;
F_119 ( V_27 -> V_142 ) ;
F_121 ( & V_27 -> V_68 ) ;
F_122 ( V_27 -> V_28 ) ;
F_123 ( V_27 -> V_135 ) ;
F_124 ( V_27 -> V_135 ) ;
F_123 ( V_27 -> V_149 ) ;
F_124 ( V_27 -> V_149 ) ;
return 0 ;
}

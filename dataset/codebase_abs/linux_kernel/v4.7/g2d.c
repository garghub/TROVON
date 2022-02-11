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
static int F_4 ( struct V_20 * V_21 ,
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
struct V_31 * V_32 = F_11 ( V_30 ) ;
struct V_12 * V_13 = F_5 ( V_30 -> V_20 ) ;
F_12 ( V_13 -> V_33 . V_34 , V_32 ) ;
}
static int F_13 ( void * V_35 , struct V_20 * V_36 ,
struct V_20 * V_37 )
{
struct V_12 * V_13 = V_35 ;
int V_38 ;
V_36 -> type = V_15 ;
V_36 -> V_39 = V_40 | V_41 ;
V_36 -> V_42 = V_13 ;
V_36 -> V_43 = & V_44 ;
V_36 -> V_45 = & V_46 ;
V_36 -> V_47 = sizeof( struct V_48 ) ;
V_36 -> V_49 = V_50 ;
V_36 -> V_51 = & V_13 -> V_27 -> V_52 ;
V_38 = F_14 ( V_36 ) ;
if ( V_38 )
return V_38 ;
V_37 -> type = V_17 ;
V_37 -> V_39 = V_40 | V_41 ;
V_37 -> V_42 = V_13 ;
V_37 -> V_43 = & V_44 ;
V_37 -> V_45 = & V_46 ;
V_37 -> V_47 = sizeof( struct V_48 ) ;
V_37 -> V_49 = V_50 ;
V_37 -> V_51 = & V_13 -> V_27 -> V_52 ;
return F_14 ( V_37 ) ;
}
static int F_15 ( struct V_53 * V_54 )
{
struct V_12 * V_13 = F_16 ( V_54 -> V_55 , struct V_12 ,
V_56 ) ;
unsigned long V_57 ;
F_17 ( & V_13 -> V_27 -> V_58 , V_57 ) ;
switch ( V_54 -> V_59 ) {
case V_60 :
if ( V_54 -> V_61 == V_62 )
V_13 -> V_63 = V_64 ;
else
V_13 -> V_63 = V_65 ;
break;
case V_66 :
V_13 -> V_67 = V_13 -> V_68 -> V_61 | ( V_13 -> V_69 -> V_61 << 1 ) ;
break;
}
F_18 ( & V_13 -> V_27 -> V_58 , V_57 ) ;
return 0 ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_70 * V_27 = V_13 -> V_27 ;
F_20 ( & V_13 -> V_56 , 3 ) ;
V_13 -> V_68 = F_21 ( & V_13 -> V_56 , & V_71 ,
V_66 , 0 , 1 , 1 , 0 ) ;
V_13 -> V_69 = F_21 ( & V_13 -> V_56 , & V_71 ,
V_72 , 0 , 1 , 1 , 0 ) ;
F_22 (
& V_13 -> V_56 ,
& V_71 ,
V_60 ,
V_62 ,
~ ( ( 1 << V_73 ) | ( 1 << V_62 ) ) ,
V_73 ) ;
if ( V_13 -> V_56 . error ) {
int V_74 = V_13 -> V_56 . error ;
F_23 ( & V_27 -> V_75 , L_1 ) ;
F_24 ( & V_13 -> V_56 ) ;
return V_74 ;
}
F_25 ( 2 , & V_13 -> V_68 ) ;
return 0 ;
}
static int F_26 ( struct V_76 * V_76 )
{
struct V_70 * V_27 = F_27 ( V_76 ) ;
struct V_12 * V_13 = NULL ;
int V_38 = 0 ;
V_13 = F_28 ( sizeof( * V_13 ) , V_77 ) ;
if ( ! V_13 )
return - V_78 ;
V_13 -> V_27 = V_27 ;
V_13 -> V_16 = V_79 ;
V_13 -> V_18 = V_79 ;
if ( F_29 ( & V_27 -> V_52 ) ) {
F_30 ( V_13 ) ;
return - V_80 ;
}
V_13 -> V_33 . V_34 = F_31 ( V_27 -> V_81 , V_13 , & F_13 ) ;
if ( F_6 ( V_13 -> V_33 . V_34 ) ) {
V_38 = F_7 ( V_13 -> V_33 . V_34 ) ;
F_32 ( & V_27 -> V_52 ) ;
F_30 ( V_13 ) ;
return V_38 ;
}
F_33 ( & V_13 -> V_33 , F_34 ( V_76 ) ) ;
V_76 -> V_82 = & V_13 -> V_33 ;
F_35 ( & V_13 -> V_33 ) ;
F_19 ( V_13 ) ;
F_36 ( & V_13 -> V_56 ) ;
V_13 -> V_33 . V_56 = & V_13 -> V_56 ;
F_32 ( & V_27 -> V_52 ) ;
F_37 ( & V_27 -> V_75 , L_2 ) ;
return 0 ;
}
static int F_38 ( struct V_76 * V_76 )
{
struct V_70 * V_27 = F_27 ( V_76 ) ;
struct V_12 * V_13 = F_39 ( V_76 -> V_82 ) ;
F_24 ( & V_13 -> V_56 ) ;
F_40 ( & V_13 -> V_33 ) ;
F_41 ( & V_13 -> V_33 ) ;
F_30 ( V_13 ) ;
F_37 ( & V_27 -> V_75 , L_3 ) ;
return 0 ;
}
static int F_42 ( struct V_76 * V_76 , void * V_35 ,
struct V_83 * V_84 )
{
strncpy ( V_84 -> V_85 , V_86 , sizeof( V_84 -> V_85 ) - 1 ) ;
strncpy ( V_84 -> V_87 , V_86 , sizeof( V_84 -> V_87 ) - 1 ) ;
V_84 -> V_88 [ 0 ] = 0 ;
V_84 -> V_89 = V_90 | V_91 ;
V_84 -> V_92 = V_84 -> V_89 | V_93 ;
return 0 ;
}
static int F_43 ( struct V_76 * V_76 , void * V_94 , struct V_95 * V_3 )
{
struct V_1 * V_8 ;
if ( V_3 -> V_96 >= V_5 )
return - V_19 ;
V_8 = & V_6 [ V_3 -> V_96 ] ;
V_3 -> V_10 = V_8 -> V_7 ;
strncpy ( V_3 -> V_97 , V_8 -> V_98 , sizeof( V_3 -> V_97 ) - 1 ) ;
return 0 ;
}
static int F_44 ( struct V_76 * V_76 , void * V_94 , struct V_2 * V_3 )
{
struct V_12 * V_13 = V_94 ;
struct V_20 * V_21 ;
struct V_11 * V_99 ;
V_21 = F_45 ( V_13 -> V_33 . V_34 , V_3 -> type ) ;
if ( ! V_21 )
return - V_19 ;
V_99 = F_2 ( V_13 , V_3 -> type ) ;
if ( F_6 ( V_99 ) )
return F_7 ( V_99 ) ;
V_3 -> V_8 . V_9 . V_100 = V_99 -> V_100 ;
V_3 -> V_8 . V_9 . V_101 = V_99 -> V_101 ;
V_3 -> V_8 . V_9 . V_102 = V_103 ;
V_3 -> V_8 . V_9 . V_10 = V_99 -> V_8 -> V_7 ;
V_3 -> V_8 . V_9 . V_104 = ( V_99 -> V_100 * V_99 -> V_8 -> V_105 ) >> 3 ;
V_3 -> V_8 . V_9 . V_106 = V_99 -> V_26 ;
return 0 ;
}
static int F_46 ( struct V_76 * V_76 , void * V_94 , struct V_2 * V_3 )
{
struct V_1 * V_8 ;
enum V_107 * V_102 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
return - V_19 ;
V_102 = & V_3 -> V_8 . V_9 . V_102 ;
if ( * V_102 == V_108 )
* V_102 = V_103 ;
else if ( * V_102 != V_103 )
return - V_19 ;
if ( V_3 -> V_8 . V_9 . V_100 > V_109 )
V_3 -> V_8 . V_9 . V_100 = V_109 ;
if ( V_3 -> V_8 . V_9 . V_101 > V_110 )
V_3 -> V_8 . V_9 . V_101 = V_110 ;
if ( V_3 -> V_8 . V_9 . V_100 < 1 )
V_3 -> V_8 . V_9 . V_100 = 1 ;
if ( V_3 -> V_8 . V_9 . V_101 < 1 )
V_3 -> V_8 . V_9 . V_101 = 1 ;
V_3 -> V_8 . V_9 . V_104 = ( V_3 -> V_8 . V_9 . V_100 * V_8 -> V_105 ) >> 3 ;
V_3 -> V_8 . V_9 . V_106 = V_3 -> V_8 . V_9 . V_101 * V_3 -> V_8 . V_9 . V_104 ;
return 0 ;
}
static int F_47 ( struct V_76 * V_76 , void * V_94 , struct V_2 * V_3 )
{
struct V_12 * V_13 = V_94 ;
struct V_70 * V_27 = V_13 -> V_27 ;
struct V_20 * V_21 ;
struct V_11 * V_99 ;
struct V_1 * V_8 ;
int V_38 = 0 ;
V_38 = F_46 ( V_76 , V_94 , V_3 ) ;
if ( V_38 )
return V_38 ;
V_21 = F_45 ( V_13 -> V_33 . V_34 , V_3 -> type ) ;
if ( F_48 ( V_21 ) ) {
F_23 ( & V_27 -> V_75 , L_4 , V_3 -> type ) ;
return - V_111 ;
}
V_99 = F_2 ( V_13 , V_3 -> type ) ;
if ( F_6 ( V_99 ) )
return F_7 ( V_99 ) ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
return - V_19 ;
V_99 -> V_100 = V_3 -> V_8 . V_9 . V_100 ;
V_99 -> V_101 = V_3 -> V_8 . V_9 . V_101 ;
V_99 -> V_26 = V_3 -> V_8 . V_9 . V_106 ;
V_99 -> V_112 = 0 ;
V_99 -> V_113 = 0 ;
V_99 -> V_114 = V_99 -> V_100 ;
V_99 -> V_115 = V_99 -> V_101 ;
V_99 -> V_116 = V_99 -> V_100 ;
V_99 -> V_117 = V_99 -> V_101 ;
V_99 -> V_8 = V_8 ;
V_99 -> V_118 = V_3 -> V_8 . V_9 . V_104 ;
return 0 ;
}
static int F_49 ( struct V_76 * V_76 , void * V_35 ,
struct V_119 * V_120 )
{
struct V_12 * V_13 = V_35 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_120 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_120 -> V_121 . V_122 = 0 ;
V_120 -> V_121 . V_123 = 0 ;
V_120 -> V_121 . V_100 = V_3 -> V_100 ;
V_120 -> V_121 . V_101 = V_3 -> V_101 ;
V_120 -> V_124 = V_120 -> V_121 ;
return 0 ;
}
static int F_50 ( struct V_76 * V_76 , void * V_94 , struct V_125 * V_120 )
{
struct V_12 * V_13 = V_94 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_120 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_120 -> V_126 . V_122 = V_3 -> V_113 ;
V_120 -> V_126 . V_123 = V_3 -> V_112 ;
V_120 -> V_126 . V_100 = V_3 -> V_114 ;
V_120 -> V_126 . V_101 = V_3 -> V_115 ;
return 0 ;
}
static int F_51 ( struct V_76 * V_76 , void * V_94 , const struct V_125 * V_120 )
{
struct V_12 * V_13 = V_94 ;
struct V_70 * V_27 = V_13 -> V_27 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_120 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
if ( V_120 -> V_126 . V_123 < 0 || V_120 -> V_126 . V_122 < 0 ) {
F_23 ( & V_27 -> V_75 ,
L_5 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_52 ( struct V_76 * V_76 , void * V_94 , const struct V_125 * V_120 )
{
struct V_12 * V_13 = V_94 ;
struct V_11 * V_3 ;
int V_38 ;
V_38 = F_51 ( V_76 , V_94 , V_120 ) ;
if ( V_38 )
return V_38 ;
V_3 = F_2 ( V_13 , V_120 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_3 -> V_114 = V_120 -> V_126 . V_100 ;
V_3 -> V_115 = V_120 -> V_126 . V_101 ;
V_3 -> V_112 = V_120 -> V_126 . V_122 ;
V_3 -> V_113 = V_120 -> V_126 . V_123 ;
V_3 -> V_117 = V_3 -> V_113 + V_3 -> V_115 ;
V_3 -> V_116 = V_3 -> V_112 + V_3 -> V_114 ;
return 0 ;
}
static void F_53 ( void * V_94 )
{
struct V_12 * V_13 = V_94 ;
struct V_70 * V_27 = V_13 -> V_27 ;
if ( V_27 -> V_127 == NULL )
return;
F_54 ( V_27 -> V_128 ,
V_27 -> V_127 == NULL ,
F_55 ( V_129 ) ) ;
}
static void F_56 ( void * V_94 )
{
struct V_12 * V_13 = V_94 ;
struct V_70 * V_27 = V_13 -> V_27 ;
struct V_29 * V_130 , * V_131 ;
unsigned long V_57 ;
T_1 V_132 = 0 ;
V_27 -> V_127 = V_13 ;
V_130 = F_57 ( V_13 -> V_33 . V_34 ) ;
V_131 = F_58 ( V_13 -> V_33 . V_34 ) ;
F_59 ( V_27 -> V_133 ) ;
F_60 ( V_27 ) ;
F_17 ( & V_27 -> V_58 , V_57 ) ;
F_61 ( V_27 , & V_13 -> V_16 ) ;
F_62 ( V_27 , F_63 ( V_130 , 0 ) ) ;
F_64 ( V_27 , & V_13 -> V_18 ) ;
F_65 ( V_27 , F_63 ( V_131 , 0 ) ) ;
F_66 ( V_27 , V_13 -> V_63 ) ;
F_67 ( V_27 , V_13 -> V_67 ) ;
if ( V_13 -> V_16 . V_114 != V_13 -> V_18 . V_114 ||
V_13 -> V_16 . V_115 != V_13 -> V_18 . V_115 ) {
if ( V_27 -> V_134 -> V_135 == V_136 )
V_132 |= V_137 ;
else
F_68 ( V_27 , & V_13 -> V_16 , & V_13 -> V_18 ) ;
}
F_69 ( V_27 , V_132 ) ;
F_70 ( V_27 ) ;
F_18 ( & V_27 -> V_58 , V_57 ) ;
}
static T_2 F_71 ( int V_138 , void * V_94 )
{
struct V_70 * V_27 = V_94 ;
struct V_12 * V_13 = V_27 -> V_127 ;
struct V_31 * V_130 , * V_131 ;
F_72 ( V_27 ) ;
F_73 ( V_27 -> V_133 ) ;
F_74 ( V_13 == NULL ) ;
V_130 = F_75 ( V_13 -> V_33 . V_34 ) ;
V_131 = F_76 ( V_13 -> V_33 . V_34 ) ;
F_74 ( V_130 == NULL ) ;
F_74 ( V_131 == NULL ) ;
V_131 -> V_139 = V_130 -> V_139 ;
V_131 -> V_140 . V_141 = V_130 -> V_140 . V_141 ;
V_131 -> V_57 &= ~ V_142 ;
V_131 -> V_57 |=
V_130 -> V_57 & V_142 ;
F_77 ( V_130 , V_143 ) ;
F_77 ( V_131 , V_143 ) ;
F_78 ( V_27 -> V_81 , V_13 -> V_33 . V_34 ) ;
V_27 -> V_127 = NULL ;
F_79 ( & V_27 -> V_128 ) ;
return V_144 ;
}
static int F_80 ( struct V_145 * V_146 )
{
struct V_70 * V_27 ;
struct V_147 * V_148 ;
struct V_149 * V_150 ;
const struct V_151 * V_152 ;
int V_38 = 0 ;
V_27 = F_81 ( & V_146 -> V_27 , sizeof( * V_27 ) , V_77 ) ;
if ( ! V_27 )
return - V_78 ;
F_82 ( & V_27 -> V_58 ) ;
F_83 ( & V_27 -> V_52 ) ;
F_84 ( & V_27 -> V_153 , 0 ) ;
F_85 ( & V_27 -> V_128 ) ;
V_150 = F_86 ( V_146 , V_154 , 0 ) ;
V_27 -> V_155 = F_87 ( & V_146 -> V_27 , V_150 ) ;
if ( F_6 ( V_27 -> V_155 ) )
return F_7 ( V_27 -> V_155 ) ;
V_27 -> V_156 = F_88 ( & V_146 -> V_27 , L_6 ) ;
if ( F_6 ( V_27 -> V_156 ) ) {
F_89 ( & V_146 -> V_27 , L_7 ) ;
return - V_157 ;
}
V_38 = F_90 ( V_27 -> V_156 ) ;
if ( V_38 ) {
F_89 ( & V_146 -> V_27 , L_8 ) ;
goto V_158;
}
V_27 -> V_133 = F_88 ( & V_146 -> V_27 , L_9 ) ;
if ( F_6 ( V_27 -> V_133 ) ) {
F_89 ( & V_146 -> V_27 , L_10 ) ;
V_38 = - V_157 ;
goto V_159;
}
V_38 = F_90 ( V_27 -> V_133 ) ;
if ( V_38 ) {
F_89 ( & V_146 -> V_27 , L_11 ) ;
goto V_160;
}
V_150 = F_86 ( V_146 , V_161 , 0 ) ;
if ( ! V_150 ) {
F_89 ( & V_146 -> V_27 , L_12 ) ;
V_38 = - V_157 ;
goto V_162;
}
V_27 -> V_138 = V_150 -> V_163 ;
V_38 = F_91 ( & V_146 -> V_27 , V_27 -> V_138 , F_71 ,
0 , V_146 -> V_98 , V_27 ) ;
if ( V_38 ) {
F_89 ( & V_146 -> V_27 , L_13 ) ;
goto V_160;
}
V_27 -> V_28 = F_92 ( & V_146 -> V_27 ) ;
if ( F_6 ( V_27 -> V_28 ) ) {
V_38 = F_7 ( V_27 -> V_28 ) ;
goto V_162;
}
V_38 = F_93 ( & V_146 -> V_27 , & V_27 -> V_75 ) ;
if ( V_38 )
goto V_164;
V_148 = F_94 () ;
if ( ! V_148 ) {
F_23 ( & V_27 -> V_75 , L_14 ) ;
V_38 = - V_78 ;
goto V_165;
}
* V_148 = V_166 ;
V_148 -> V_51 = & V_27 -> V_52 ;
V_148 -> V_75 = & V_27 -> V_75 ;
V_38 = F_95 ( V_148 , V_167 , 0 ) ;
if ( V_38 ) {
F_23 ( & V_27 -> V_75 , L_15 ) ;
goto V_168;
}
F_96 ( V_148 , V_27 ) ;
snprintf ( V_148 -> V_98 , sizeof( V_148 -> V_98 ) , L_16 , V_166 . V_98 ) ;
V_27 -> V_148 = V_148 ;
F_37 ( & V_27 -> V_75 , L_17 ,
V_148 -> V_169 ) ;
F_97 ( V_146 , V_27 ) ;
V_27 -> V_81 = F_98 ( & V_170 ) ;
if ( F_6 ( V_27 -> V_81 ) ) {
F_23 ( & V_27 -> V_75 , L_18 ) ;
V_38 = F_7 ( V_27 -> V_81 ) ;
goto V_171;
}
V_79 . V_118 = ( V_79 . V_100 * V_79 . V_8 -> V_105 ) >> 3 ;
V_152 = F_99 ( V_172 , V_146 -> V_27 . V_173 ) ;
if ( ! V_152 ) {
V_38 = - V_174 ;
goto V_171;
}
V_27 -> V_134 = (struct V_175 * ) V_152 -> V_176 ;
return 0 ;
V_171:
F_100 ( V_27 -> V_148 ) ;
V_168:
F_101 ( V_148 ) ;
V_165:
F_102 ( & V_27 -> V_75 ) ;
V_164:
F_103 ( V_27 -> V_28 ) ;
V_162:
F_104 ( V_27 -> V_133 ) ;
V_160:
F_105 ( V_27 -> V_133 ) ;
V_159:
F_104 ( V_27 -> V_156 ) ;
V_158:
F_105 ( V_27 -> V_156 ) ;
return V_38 ;
}
static int F_106 ( struct V_145 * V_146 )
{
struct V_70 * V_27 = F_107 ( V_146 ) ;
F_37 ( & V_27 -> V_75 , L_19 V_86 ) ;
F_108 ( V_27 -> V_81 ) ;
F_100 ( V_27 -> V_148 ) ;
F_102 ( & V_27 -> V_75 ) ;
F_103 ( V_27 -> V_28 ) ;
F_104 ( V_27 -> V_133 ) ;
F_105 ( V_27 -> V_133 ) ;
F_104 ( V_27 -> V_156 ) ;
F_105 ( V_27 -> V_156 ) ;
return 0 ;
}

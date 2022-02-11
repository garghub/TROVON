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
static int F_4 ( struct V_20 * V_21 , const void * V_22 ,
unsigned int * V_23 , unsigned int * V_24 ,
unsigned int V_25 [] , void * V_26 [] )
{
struct V_12 * V_13 = F_5 ( V_21 ) ;
struct V_11 * V_3 = F_2 ( V_13 , V_21 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_25 [ 0 ] = V_3 -> V_27 ;
* V_24 = 1 ;
V_26 [ 0 ] = V_13 -> V_28 -> V_29 ;
if ( * V_23 == 0 )
* V_23 = 1 ;
return 0 ;
}
static int F_8 ( struct V_30 * V_31 )
{
struct V_12 * V_13 = F_5 ( V_31 -> V_20 ) ;
struct V_11 * V_3 = F_2 ( V_13 , V_31 -> V_20 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
F_9 ( V_31 , 0 , V_3 -> V_27 ) ;
return 0 ;
}
static void F_10 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = F_11 ( V_31 ) ;
struct V_12 * V_13 = F_5 ( V_31 -> V_20 ) ;
F_12 ( V_13 -> V_34 . V_35 , V_33 ) ;
}
static int F_13 ( void * V_36 , struct V_20 * V_37 ,
struct V_20 * V_38 )
{
struct V_12 * V_13 = V_36 ;
int V_39 ;
V_37 -> type = V_15 ;
V_37 -> V_40 = V_41 | V_42 ;
V_37 -> V_43 = V_13 ;
V_37 -> V_44 = & V_45 ;
V_37 -> V_46 = & V_47 ;
V_37 -> V_48 = sizeof( struct V_49 ) ;
V_37 -> V_50 = V_51 ;
V_37 -> V_52 = & V_13 -> V_28 -> V_53 ;
V_39 = F_14 ( V_37 ) ;
if ( V_39 )
return V_39 ;
V_38 -> type = V_17 ;
V_38 -> V_40 = V_41 | V_42 ;
V_38 -> V_43 = V_13 ;
V_38 -> V_44 = & V_45 ;
V_38 -> V_46 = & V_47 ;
V_38 -> V_48 = sizeof( struct V_49 ) ;
V_38 -> V_50 = V_51 ;
V_38 -> V_52 = & V_13 -> V_28 -> V_53 ;
return F_14 ( V_38 ) ;
}
static int F_15 ( struct V_54 * V_55 )
{
struct V_12 * V_13 = F_16 ( V_55 -> V_56 , struct V_12 ,
V_57 ) ;
unsigned long V_58 ;
F_17 ( & V_13 -> V_28 -> V_59 , V_58 ) ;
switch ( V_55 -> V_60 ) {
case V_61 :
if ( V_55 -> V_62 == V_63 )
V_13 -> V_64 = V_65 ;
else
V_13 -> V_64 = V_66 ;
break;
case V_67 :
V_13 -> V_68 = V_13 -> V_69 -> V_62 | ( V_13 -> V_70 -> V_62 << 1 ) ;
break;
}
F_18 ( & V_13 -> V_28 -> V_59 , V_58 ) ;
return 0 ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_71 * V_28 = V_13 -> V_28 ;
F_20 ( & V_13 -> V_57 , 3 ) ;
V_13 -> V_69 = F_21 ( & V_13 -> V_57 , & V_72 ,
V_67 , 0 , 1 , 1 , 0 ) ;
V_13 -> V_70 = F_21 ( & V_13 -> V_57 , & V_72 ,
V_73 , 0 , 1 , 1 , 0 ) ;
F_22 (
& V_13 -> V_57 ,
& V_72 ,
V_61 ,
V_63 ,
~ ( ( 1 << V_74 ) | ( 1 << V_63 ) ) ,
V_74 ) ;
if ( V_13 -> V_57 . error ) {
int V_75 = V_13 -> V_57 . error ;
F_23 ( & V_28 -> V_76 , L_1 ) ;
F_24 ( & V_13 -> V_57 ) ;
return V_75 ;
}
F_25 ( 2 , & V_13 -> V_69 ) ;
return 0 ;
}
static int F_26 ( struct V_77 * V_77 )
{
struct V_71 * V_28 = F_27 ( V_77 ) ;
struct V_12 * V_13 = NULL ;
int V_39 = 0 ;
V_13 = F_28 ( sizeof( * V_13 ) , V_78 ) ;
if ( ! V_13 )
return - V_79 ;
V_13 -> V_28 = V_28 ;
V_13 -> V_16 = V_80 ;
V_13 -> V_18 = V_80 ;
if ( F_29 ( & V_28 -> V_53 ) ) {
F_30 ( V_13 ) ;
return - V_81 ;
}
V_13 -> V_34 . V_35 = F_31 ( V_28 -> V_82 , V_13 , & F_13 ) ;
if ( F_6 ( V_13 -> V_34 . V_35 ) ) {
V_39 = F_7 ( V_13 -> V_34 . V_35 ) ;
F_32 ( & V_28 -> V_53 ) ;
F_30 ( V_13 ) ;
return V_39 ;
}
F_33 ( & V_13 -> V_34 , F_34 ( V_77 ) ) ;
V_77 -> V_83 = & V_13 -> V_34 ;
F_35 ( & V_13 -> V_34 ) ;
F_19 ( V_13 ) ;
F_36 ( & V_13 -> V_57 ) ;
V_13 -> V_34 . V_57 = & V_13 -> V_57 ;
F_32 ( & V_28 -> V_53 ) ;
F_37 ( & V_28 -> V_76 , L_2 ) ;
return 0 ;
}
static int F_38 ( struct V_77 * V_77 )
{
struct V_71 * V_28 = F_27 ( V_77 ) ;
struct V_12 * V_13 = F_39 ( V_77 -> V_83 ) ;
F_24 ( & V_13 -> V_57 ) ;
F_40 ( & V_13 -> V_34 ) ;
F_41 ( & V_13 -> V_34 ) ;
F_30 ( V_13 ) ;
F_37 ( & V_28 -> V_76 , L_3 ) ;
return 0 ;
}
static int F_42 ( struct V_77 * V_77 , void * V_36 ,
struct V_84 * V_85 )
{
strncpy ( V_85 -> V_86 , V_87 , sizeof( V_85 -> V_86 ) - 1 ) ;
strncpy ( V_85 -> V_88 , V_87 , sizeof( V_85 -> V_88 ) - 1 ) ;
V_85 -> V_89 [ 0 ] = 0 ;
V_85 -> V_90 = V_91 | V_92 ;
V_85 -> V_93 = V_85 -> V_90 | V_94 ;
return 0 ;
}
static int F_43 ( struct V_77 * V_77 , void * V_95 , struct V_96 * V_3 )
{
struct V_1 * V_8 ;
if ( V_3 -> V_97 >= V_5 )
return - V_19 ;
V_8 = & V_6 [ V_3 -> V_97 ] ;
V_3 -> V_10 = V_8 -> V_7 ;
strncpy ( V_3 -> V_98 , V_8 -> V_99 , sizeof( V_3 -> V_98 ) - 1 ) ;
return 0 ;
}
static int F_44 ( struct V_77 * V_77 , void * V_95 , struct V_2 * V_3 )
{
struct V_12 * V_13 = V_95 ;
struct V_20 * V_21 ;
struct V_11 * V_100 ;
V_21 = F_45 ( V_13 -> V_34 . V_35 , V_3 -> type ) ;
if ( ! V_21 )
return - V_19 ;
V_100 = F_2 ( V_13 , V_3 -> type ) ;
if ( F_6 ( V_100 ) )
return F_7 ( V_100 ) ;
V_3 -> V_8 . V_9 . V_101 = V_100 -> V_101 ;
V_3 -> V_8 . V_9 . V_102 = V_100 -> V_102 ;
V_3 -> V_8 . V_9 . V_103 = V_104 ;
V_3 -> V_8 . V_9 . V_10 = V_100 -> V_8 -> V_7 ;
V_3 -> V_8 . V_9 . V_105 = ( V_100 -> V_101 * V_100 -> V_8 -> V_106 ) >> 3 ;
V_3 -> V_8 . V_9 . V_107 = V_100 -> V_27 ;
return 0 ;
}
static int F_46 ( struct V_77 * V_77 , void * V_95 , struct V_2 * V_3 )
{
struct V_1 * V_8 ;
enum V_108 * V_103 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
return - V_19 ;
V_103 = & V_3 -> V_8 . V_9 . V_103 ;
if ( * V_103 == V_109 )
* V_103 = V_104 ;
else if ( * V_103 != V_104 )
return - V_19 ;
if ( V_3 -> V_8 . V_9 . V_101 > V_110 )
V_3 -> V_8 . V_9 . V_101 = V_110 ;
if ( V_3 -> V_8 . V_9 . V_102 > V_111 )
V_3 -> V_8 . V_9 . V_102 = V_111 ;
if ( V_3 -> V_8 . V_9 . V_101 < 1 )
V_3 -> V_8 . V_9 . V_101 = 1 ;
if ( V_3 -> V_8 . V_9 . V_102 < 1 )
V_3 -> V_8 . V_9 . V_102 = 1 ;
V_3 -> V_8 . V_9 . V_105 = ( V_3 -> V_8 . V_9 . V_101 * V_8 -> V_106 ) >> 3 ;
V_3 -> V_8 . V_9 . V_107 = V_3 -> V_8 . V_9 . V_102 * V_3 -> V_8 . V_9 . V_105 ;
return 0 ;
}
static int F_47 ( struct V_77 * V_77 , void * V_95 , struct V_2 * V_3 )
{
struct V_12 * V_13 = V_95 ;
struct V_71 * V_28 = V_13 -> V_28 ;
struct V_20 * V_21 ;
struct V_11 * V_100 ;
struct V_1 * V_8 ;
int V_39 = 0 ;
V_39 = F_46 ( V_77 , V_95 , V_3 ) ;
if ( V_39 )
return V_39 ;
V_21 = F_45 ( V_13 -> V_34 . V_35 , V_3 -> type ) ;
if ( F_48 ( V_21 ) ) {
F_23 ( & V_28 -> V_76 , L_4 , V_3 -> type ) ;
return - V_112 ;
}
V_100 = F_2 ( V_13 , V_3 -> type ) ;
if ( F_6 ( V_100 ) )
return F_7 ( V_100 ) ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
return - V_19 ;
V_100 -> V_101 = V_3 -> V_8 . V_9 . V_101 ;
V_100 -> V_102 = V_3 -> V_8 . V_9 . V_102 ;
V_100 -> V_27 = V_3 -> V_8 . V_9 . V_107 ;
V_100 -> V_113 = 0 ;
V_100 -> V_114 = 0 ;
V_100 -> V_115 = V_100 -> V_101 ;
V_100 -> V_116 = V_100 -> V_102 ;
V_100 -> V_117 = V_100 -> V_101 ;
V_100 -> V_118 = V_100 -> V_102 ;
V_100 -> V_8 = V_8 ;
V_100 -> V_119 = V_3 -> V_8 . V_9 . V_105 ;
return 0 ;
}
static int F_49 ( struct V_77 * V_77 , void * V_36 ,
struct V_120 * V_121 )
{
struct V_12 * V_13 = V_36 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_121 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_121 -> V_122 . V_123 = 0 ;
V_121 -> V_122 . V_124 = 0 ;
V_121 -> V_122 . V_101 = V_3 -> V_101 ;
V_121 -> V_122 . V_102 = V_3 -> V_102 ;
V_121 -> V_125 = V_121 -> V_122 ;
return 0 ;
}
static int F_50 ( struct V_77 * V_77 , void * V_95 , struct V_126 * V_121 )
{
struct V_12 * V_13 = V_95 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_121 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_121 -> V_127 . V_123 = V_3 -> V_114 ;
V_121 -> V_127 . V_124 = V_3 -> V_113 ;
V_121 -> V_127 . V_101 = V_3 -> V_115 ;
V_121 -> V_127 . V_102 = V_3 -> V_116 ;
return 0 ;
}
static int F_51 ( struct V_77 * V_77 , void * V_95 , const struct V_126 * V_121 )
{
struct V_12 * V_13 = V_95 ;
struct V_71 * V_28 = V_13 -> V_28 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_121 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
if ( V_121 -> V_127 . V_124 < 0 || V_121 -> V_127 . V_123 < 0 ) {
F_23 ( & V_28 -> V_76 ,
L_5 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_52 ( struct V_77 * V_77 , void * V_95 , const struct V_126 * V_121 )
{
struct V_12 * V_13 = V_95 ;
struct V_11 * V_3 ;
int V_39 ;
V_39 = F_51 ( V_77 , V_95 , V_121 ) ;
if ( V_39 )
return V_39 ;
V_3 = F_2 ( V_13 , V_121 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_3 -> V_115 = V_121 -> V_127 . V_101 ;
V_3 -> V_116 = V_121 -> V_127 . V_102 ;
V_3 -> V_113 = V_121 -> V_127 . V_123 ;
V_3 -> V_114 = V_121 -> V_127 . V_124 ;
V_3 -> V_118 = V_3 -> V_114 + V_3 -> V_116 ;
V_3 -> V_117 = V_3 -> V_113 + V_3 -> V_115 ;
return 0 ;
}
static void F_53 ( void * V_95 )
{
struct V_12 * V_13 = V_95 ;
struct V_71 * V_28 = V_13 -> V_28 ;
if ( V_28 -> V_128 == NULL )
return;
F_54 ( V_28 -> V_129 ,
V_28 -> V_128 == NULL ,
F_55 ( V_130 ) ) ;
}
static void F_56 ( void * V_95 )
{
struct V_12 * V_13 = V_95 ;
struct V_71 * V_28 = V_13 -> V_28 ;
struct V_30 * V_131 , * V_132 ;
unsigned long V_58 ;
T_1 V_133 = 0 ;
V_28 -> V_128 = V_13 ;
V_131 = F_57 ( V_13 -> V_34 . V_35 ) ;
V_132 = F_58 ( V_13 -> V_34 . V_35 ) ;
F_59 ( V_28 -> V_134 ) ;
F_60 ( V_28 ) ;
F_17 ( & V_28 -> V_59 , V_58 ) ;
F_61 ( V_28 , & V_13 -> V_16 ) ;
F_62 ( V_28 , F_63 ( V_131 , 0 ) ) ;
F_64 ( V_28 , & V_13 -> V_18 ) ;
F_65 ( V_28 , F_63 ( V_132 , 0 ) ) ;
F_66 ( V_28 , V_13 -> V_64 ) ;
F_67 ( V_28 , V_13 -> V_68 ) ;
if ( V_13 -> V_16 . V_115 != V_13 -> V_18 . V_115 ||
V_13 -> V_16 . V_116 != V_13 -> V_18 . V_116 ) {
if ( V_28 -> V_135 -> V_136 == V_137 )
V_133 |= V_138 ;
else
F_68 ( V_28 , & V_13 -> V_16 , & V_13 -> V_18 ) ;
}
F_69 ( V_28 , V_133 ) ;
F_70 ( V_28 ) ;
F_18 ( & V_28 -> V_59 , V_58 ) ;
}
static T_2 F_71 ( int V_139 , void * V_95 )
{
struct V_71 * V_28 = V_95 ;
struct V_12 * V_13 = V_28 -> V_128 ;
struct V_32 * V_131 , * V_132 ;
F_72 ( V_28 ) ;
F_73 ( V_28 -> V_134 ) ;
F_74 ( V_13 == NULL ) ;
V_131 = F_75 ( V_13 -> V_34 . V_35 ) ;
V_132 = F_76 ( V_13 -> V_34 . V_35 ) ;
F_74 ( V_131 == NULL ) ;
F_74 ( V_132 == NULL ) ;
V_132 -> V_140 = V_131 -> V_140 ;
V_132 -> V_141 = V_131 -> V_141 ;
V_132 -> V_58 &= ~ V_142 ;
V_132 -> V_58 |=
V_131 -> V_58 & V_142 ;
F_77 ( V_131 , V_143 ) ;
F_77 ( V_132 , V_143 ) ;
F_78 ( V_28 -> V_82 , V_13 -> V_34 . V_35 ) ;
V_28 -> V_128 = NULL ;
F_79 ( & V_28 -> V_129 ) ;
return V_144 ;
}
static int F_80 ( struct V_145 * V_146 )
{
struct V_71 * V_28 ;
struct V_147 * V_148 ;
struct V_149 * V_150 ;
const struct V_151 * V_152 ;
int V_39 = 0 ;
V_28 = F_81 ( & V_146 -> V_28 , sizeof( * V_28 ) , V_78 ) ;
if ( ! V_28 )
return - V_79 ;
F_82 ( & V_28 -> V_59 ) ;
F_83 ( & V_28 -> V_53 ) ;
F_84 ( & V_28 -> V_153 , 0 ) ;
F_85 ( & V_28 -> V_129 ) ;
V_150 = F_86 ( V_146 , V_154 , 0 ) ;
V_28 -> V_155 = F_87 ( & V_146 -> V_28 , V_150 ) ;
if ( F_6 ( V_28 -> V_155 ) )
return F_7 ( V_28 -> V_155 ) ;
V_28 -> V_156 = F_88 ( & V_146 -> V_28 , L_6 ) ;
if ( F_6 ( V_28 -> V_156 ) ) {
F_89 ( & V_146 -> V_28 , L_7 ) ;
return - V_157 ;
}
V_39 = F_90 ( V_28 -> V_156 ) ;
if ( V_39 ) {
F_89 ( & V_146 -> V_28 , L_8 ) ;
goto V_158;
}
V_28 -> V_134 = F_88 ( & V_146 -> V_28 , L_9 ) ;
if ( F_6 ( V_28 -> V_134 ) ) {
F_89 ( & V_146 -> V_28 , L_10 ) ;
V_39 = - V_157 ;
goto V_159;
}
V_39 = F_90 ( V_28 -> V_134 ) ;
if ( V_39 ) {
F_89 ( & V_146 -> V_28 , L_11 ) ;
goto V_160;
}
V_150 = F_86 ( V_146 , V_161 , 0 ) ;
if ( ! V_150 ) {
F_89 ( & V_146 -> V_28 , L_12 ) ;
V_39 = - V_157 ;
goto V_162;
}
V_28 -> V_139 = V_150 -> V_163 ;
V_39 = F_91 ( & V_146 -> V_28 , V_28 -> V_139 , F_71 ,
0 , V_146 -> V_99 , V_28 ) ;
if ( V_39 ) {
F_89 ( & V_146 -> V_28 , L_13 ) ;
goto V_160;
}
V_28 -> V_29 = F_92 ( & V_146 -> V_28 ) ;
if ( F_6 ( V_28 -> V_29 ) ) {
V_39 = F_7 ( V_28 -> V_29 ) ;
goto V_162;
}
V_39 = F_93 ( & V_146 -> V_28 , & V_28 -> V_76 ) ;
if ( V_39 )
goto V_164;
V_148 = F_94 () ;
if ( ! V_148 ) {
F_23 ( & V_28 -> V_76 , L_14 ) ;
V_39 = - V_79 ;
goto V_165;
}
* V_148 = V_166 ;
V_148 -> V_52 = & V_28 -> V_53 ;
V_148 -> V_76 = & V_28 -> V_76 ;
V_39 = F_95 ( V_148 , V_167 , 0 ) ;
if ( V_39 ) {
F_23 ( & V_28 -> V_76 , L_15 ) ;
goto V_168;
}
F_96 ( V_148 , V_28 ) ;
snprintf ( V_148 -> V_99 , sizeof( V_148 -> V_99 ) , L_16 , V_166 . V_99 ) ;
V_28 -> V_148 = V_148 ;
F_37 ( & V_28 -> V_76 , L_17 ,
V_148 -> V_169 ) ;
F_97 ( V_146 , V_28 ) ;
V_28 -> V_82 = F_98 ( & V_170 ) ;
if ( F_6 ( V_28 -> V_82 ) ) {
F_23 ( & V_28 -> V_76 , L_18 ) ;
V_39 = F_7 ( V_28 -> V_82 ) ;
goto V_171;
}
V_80 . V_119 = ( V_80 . V_101 * V_80 . V_8 -> V_106 ) >> 3 ;
if ( ! V_146 -> V_28 . V_172 ) {
V_28 -> V_135 = F_99 ( V_146 ) ;
} else {
V_152 = F_100 ( V_173 , V_146 -> V_28 . V_172 ) ;
if ( ! V_152 ) {
V_39 = - V_174 ;
goto V_171;
}
V_28 -> V_135 = (struct V_175 * ) V_152 -> V_176 ;
}
return 0 ;
V_171:
F_101 ( V_28 -> V_148 ) ;
V_168:
F_102 ( V_148 ) ;
V_165:
F_103 ( & V_28 -> V_76 ) ;
V_164:
F_104 ( V_28 -> V_29 ) ;
V_162:
F_105 ( V_28 -> V_134 ) ;
V_160:
F_106 ( V_28 -> V_134 ) ;
V_159:
F_105 ( V_28 -> V_156 ) ;
V_158:
F_106 ( V_28 -> V_156 ) ;
return V_39 ;
}
static int F_107 ( struct V_145 * V_146 )
{
struct V_71 * V_28 = F_108 ( V_146 ) ;
F_37 ( & V_28 -> V_76 , L_19 V_87 ) ;
F_109 ( V_28 -> V_82 ) ;
F_101 ( V_28 -> V_148 ) ;
F_103 ( & V_28 -> V_76 ) ;
F_104 ( V_28 -> V_29 ) ;
F_105 ( V_28 -> V_134 ) ;
F_106 ( V_28 -> V_134 ) ;
F_105 ( V_28 -> V_156 ) ;
F_106 ( V_28 -> V_156 ) ;
return 0 ;
}

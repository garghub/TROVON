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
F_11 ( V_13 -> V_31 . V_32 , V_30 ) ;
}
static int F_12 ( void * V_33 , struct V_20 * V_34 ,
struct V_20 * V_35 )
{
struct V_12 * V_13 = V_33 ;
int V_36 ;
V_34 -> type = V_15 ;
V_34 -> V_37 = V_38 | V_39 ;
V_34 -> V_40 = V_13 ;
V_34 -> V_41 = & V_42 ;
V_34 -> V_43 = & V_44 ;
V_34 -> V_45 = sizeof( struct V_46 ) ;
V_34 -> V_47 = V_48 ;
V_34 -> V_49 = & V_13 -> V_27 -> V_50 ;
V_36 = F_13 ( V_34 ) ;
if ( V_36 )
return V_36 ;
V_35 -> type = V_17 ;
V_35 -> V_37 = V_38 | V_39 ;
V_35 -> V_40 = V_13 ;
V_35 -> V_41 = & V_42 ;
V_35 -> V_43 = & V_44 ;
V_35 -> V_45 = sizeof( struct V_46 ) ;
V_35 -> V_47 = V_48 ;
V_35 -> V_49 = & V_13 -> V_27 -> V_50 ;
return F_13 ( V_35 ) ;
}
static int F_14 ( struct V_51 * V_52 )
{
struct V_12 * V_13 = F_15 ( V_52 -> V_53 , struct V_12 ,
V_54 ) ;
unsigned long V_55 ;
F_16 ( & V_13 -> V_27 -> V_56 , V_55 ) ;
switch ( V_52 -> V_57 ) {
case V_58 :
if ( V_52 -> V_59 == V_60 )
V_13 -> V_61 = V_62 ;
else
V_13 -> V_61 = V_63 ;
break;
case V_64 :
V_13 -> V_65 = V_13 -> V_66 -> V_59 | ( V_13 -> V_67 -> V_59 << 1 ) ;
break;
}
F_17 ( & V_13 -> V_27 -> V_56 , V_55 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 )
{
struct V_68 * V_27 = V_13 -> V_27 ;
F_19 ( & V_13 -> V_54 , 3 ) ;
V_13 -> V_66 = F_20 ( & V_13 -> V_54 , & V_69 ,
V_64 , 0 , 1 , 1 , 0 ) ;
V_13 -> V_67 = F_20 ( & V_13 -> V_54 , & V_69 ,
V_70 , 0 , 1 , 1 , 0 ) ;
F_21 (
& V_13 -> V_54 ,
& V_69 ,
V_58 ,
V_60 ,
~ ( ( 1 << V_71 ) | ( 1 << V_60 ) ) ,
V_71 ) ;
if ( V_13 -> V_54 . error ) {
int V_72 = V_13 -> V_54 . error ;
F_22 ( & V_27 -> V_73 , L_1 ) ;
F_23 ( & V_13 -> V_54 ) ;
return V_72 ;
}
F_24 ( 2 , & V_13 -> V_66 ) ;
return 0 ;
}
static int F_25 ( struct V_74 * V_74 )
{
struct V_68 * V_27 = F_26 ( V_74 ) ;
struct V_12 * V_13 = NULL ;
int V_36 = 0 ;
V_13 = F_27 ( sizeof( * V_13 ) , V_75 ) ;
if ( ! V_13 )
return - V_76 ;
V_13 -> V_27 = V_27 ;
V_13 -> V_16 = V_77 ;
V_13 -> V_18 = V_77 ;
if ( F_28 ( & V_27 -> V_50 ) ) {
F_29 ( V_13 ) ;
return - V_78 ;
}
V_13 -> V_31 . V_32 = F_30 ( V_27 -> V_79 , V_13 , & F_12 ) ;
if ( F_6 ( V_13 -> V_31 . V_32 ) ) {
V_36 = F_7 ( V_13 -> V_31 . V_32 ) ;
F_31 ( & V_27 -> V_50 ) ;
F_29 ( V_13 ) ;
return V_36 ;
}
F_32 ( & V_13 -> V_31 , F_33 ( V_74 ) ) ;
V_74 -> V_80 = & V_13 -> V_31 ;
F_34 ( & V_13 -> V_31 ) ;
F_18 ( V_13 ) ;
F_35 ( & V_13 -> V_54 ) ;
V_13 -> V_31 . V_54 = & V_13 -> V_54 ;
F_31 ( & V_27 -> V_50 ) ;
F_36 ( & V_27 -> V_73 , L_2 ) ;
return 0 ;
}
static int F_37 ( struct V_74 * V_74 )
{
struct V_68 * V_27 = F_26 ( V_74 ) ;
struct V_12 * V_13 = F_38 ( V_74 -> V_80 ) ;
F_23 ( & V_13 -> V_54 ) ;
F_39 ( & V_13 -> V_31 ) ;
F_40 ( & V_13 -> V_31 ) ;
F_29 ( V_13 ) ;
F_36 ( & V_27 -> V_73 , L_3 ) ;
return 0 ;
}
static int F_41 ( struct V_74 * V_74 , void * V_33 ,
struct V_81 * V_82 )
{
strncpy ( V_82 -> V_83 , V_84 , sizeof( V_82 -> V_83 ) - 1 ) ;
strncpy ( V_82 -> V_85 , V_84 , sizeof( V_82 -> V_85 ) - 1 ) ;
V_82 -> V_86 [ 0 ] = 0 ;
V_82 -> V_87 = V_88 | V_89 ;
V_82 -> V_90 = V_82 -> V_87 | V_91 ;
return 0 ;
}
static int F_42 ( struct V_74 * V_74 , void * V_92 , struct V_93 * V_3 )
{
struct V_1 * V_8 ;
if ( V_3 -> V_94 >= V_5 )
return - V_19 ;
V_8 = & V_6 [ V_3 -> V_94 ] ;
V_3 -> V_10 = V_8 -> V_7 ;
strncpy ( V_3 -> V_95 , V_8 -> V_96 , sizeof( V_3 -> V_95 ) - 1 ) ;
return 0 ;
}
static int F_43 ( struct V_74 * V_74 , void * V_92 , struct V_2 * V_3 )
{
struct V_12 * V_13 = V_92 ;
struct V_20 * V_21 ;
struct V_11 * V_97 ;
V_21 = F_44 ( V_13 -> V_31 . V_32 , V_3 -> type ) ;
if ( ! V_21 )
return - V_19 ;
V_97 = F_2 ( V_13 , V_3 -> type ) ;
if ( F_6 ( V_97 ) )
return F_7 ( V_97 ) ;
V_3 -> V_8 . V_9 . V_98 = V_97 -> V_98 ;
V_3 -> V_8 . V_9 . V_99 = V_97 -> V_99 ;
V_3 -> V_8 . V_9 . V_100 = V_101 ;
V_3 -> V_8 . V_9 . V_10 = V_97 -> V_8 -> V_7 ;
V_3 -> V_8 . V_9 . V_102 = ( V_97 -> V_98 * V_97 -> V_8 -> V_103 ) >> 3 ;
V_3 -> V_8 . V_9 . V_104 = V_97 -> V_26 ;
return 0 ;
}
static int F_45 ( struct V_74 * V_74 , void * V_92 , struct V_2 * V_3 )
{
struct V_1 * V_8 ;
enum V_105 * V_100 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
return - V_19 ;
V_100 = & V_3 -> V_8 . V_9 . V_100 ;
if ( * V_100 == V_106 )
* V_100 = V_101 ;
else if ( * V_100 != V_101 )
return - V_19 ;
if ( V_3 -> V_8 . V_9 . V_98 > V_107 )
V_3 -> V_8 . V_9 . V_98 = V_107 ;
if ( V_3 -> V_8 . V_9 . V_99 > V_108 )
V_3 -> V_8 . V_9 . V_99 = V_108 ;
if ( V_3 -> V_8 . V_9 . V_98 < 1 )
V_3 -> V_8 . V_9 . V_98 = 1 ;
if ( V_3 -> V_8 . V_9 . V_99 < 1 )
V_3 -> V_8 . V_9 . V_99 = 1 ;
V_3 -> V_8 . V_9 . V_102 = ( V_3 -> V_8 . V_9 . V_98 * V_8 -> V_103 ) >> 3 ;
V_3 -> V_8 . V_9 . V_104 = V_3 -> V_8 . V_9 . V_99 * V_3 -> V_8 . V_9 . V_102 ;
return 0 ;
}
static int F_46 ( struct V_74 * V_74 , void * V_92 , struct V_2 * V_3 )
{
struct V_12 * V_13 = V_92 ;
struct V_68 * V_27 = V_13 -> V_27 ;
struct V_20 * V_21 ;
struct V_11 * V_97 ;
struct V_1 * V_8 ;
int V_36 = 0 ;
V_36 = F_45 ( V_74 , V_92 , V_3 ) ;
if ( V_36 )
return V_36 ;
V_21 = F_44 ( V_13 -> V_31 . V_32 , V_3 -> type ) ;
if ( F_47 ( V_21 ) ) {
F_22 ( & V_27 -> V_73 , L_4 , V_3 -> type ) ;
return - V_109 ;
}
V_97 = F_2 ( V_13 , V_3 -> type ) ;
if ( F_6 ( V_97 ) )
return F_7 ( V_97 ) ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
return - V_19 ;
V_97 -> V_98 = V_3 -> V_8 . V_9 . V_98 ;
V_97 -> V_99 = V_3 -> V_8 . V_9 . V_99 ;
V_97 -> V_26 = V_3 -> V_8 . V_9 . V_104 ;
V_97 -> V_110 = 0 ;
V_97 -> V_111 = 0 ;
V_97 -> V_112 = V_97 -> V_98 ;
V_97 -> V_113 = V_97 -> V_99 ;
V_97 -> V_114 = V_97 -> V_98 ;
V_97 -> V_115 = V_97 -> V_99 ;
V_97 -> V_8 = V_8 ;
V_97 -> V_116 = V_3 -> V_8 . V_9 . V_102 ;
return 0 ;
}
static int F_48 ( struct V_74 * V_74 , void * V_33 ,
struct V_117 * V_118 )
{
struct V_12 * V_13 = V_33 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_118 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_118 -> V_119 . V_120 = 0 ;
V_118 -> V_119 . V_121 = 0 ;
V_118 -> V_119 . V_98 = V_3 -> V_98 ;
V_118 -> V_119 . V_99 = V_3 -> V_99 ;
V_118 -> V_122 = V_118 -> V_119 ;
return 0 ;
}
static int F_49 ( struct V_74 * V_74 , void * V_92 , struct V_123 * V_118 )
{
struct V_12 * V_13 = V_92 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_118 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_118 -> V_124 . V_120 = V_3 -> V_111 ;
V_118 -> V_124 . V_121 = V_3 -> V_110 ;
V_118 -> V_124 . V_98 = V_3 -> V_112 ;
V_118 -> V_124 . V_99 = V_3 -> V_113 ;
return 0 ;
}
static int F_50 ( struct V_74 * V_74 , void * V_92 , const struct V_123 * V_118 )
{
struct V_12 * V_13 = V_92 ;
struct V_68 * V_27 = V_13 -> V_27 ;
struct V_11 * V_3 ;
V_3 = F_2 ( V_13 , V_118 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
if ( V_118 -> V_124 . V_121 < 0 || V_118 -> V_124 . V_120 < 0 ) {
F_22 ( & V_27 -> V_73 ,
L_5 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_51 ( struct V_74 * V_74 , void * V_92 , const struct V_123 * V_118 )
{
struct V_12 * V_13 = V_92 ;
struct V_11 * V_3 ;
int V_36 ;
V_36 = F_50 ( V_74 , V_92 , V_118 ) ;
if ( V_36 )
return V_36 ;
V_3 = F_2 ( V_13 , V_118 -> type ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_3 -> V_112 = V_118 -> V_124 . V_98 ;
V_3 -> V_113 = V_118 -> V_124 . V_99 ;
V_3 -> V_110 = V_118 -> V_124 . V_120 ;
V_3 -> V_111 = V_118 -> V_124 . V_121 ;
V_3 -> V_115 = V_3 -> V_111 + V_3 -> V_113 ;
V_3 -> V_114 = V_3 -> V_110 + V_3 -> V_112 ;
return 0 ;
}
static void F_52 ( void * V_92 )
{
struct V_12 * V_13 = V_92 ;
struct V_68 * V_27 = V_13 -> V_27 ;
if ( V_27 -> V_125 == NULL )
return;
F_53 ( V_27 -> V_126 ,
V_27 -> V_125 == NULL ,
F_54 ( V_127 ) ) ;
}
static void F_55 ( void * V_92 )
{
struct V_12 * V_13 = V_92 ;
struct V_68 * V_27 = V_13 -> V_27 ;
struct V_29 * V_128 , * V_129 ;
unsigned long V_55 ;
T_1 V_130 = 0 ;
V_27 -> V_125 = V_13 ;
V_128 = F_56 ( V_13 -> V_31 . V_32 ) ;
V_129 = F_57 ( V_13 -> V_31 . V_32 ) ;
F_58 ( V_27 -> V_131 ) ;
F_59 ( V_27 ) ;
F_16 ( & V_27 -> V_56 , V_55 ) ;
F_60 ( V_27 , & V_13 -> V_16 ) ;
F_61 ( V_27 , F_62 ( V_128 , 0 ) ) ;
F_63 ( V_27 , & V_13 -> V_18 ) ;
F_64 ( V_27 , F_62 ( V_129 , 0 ) ) ;
F_65 ( V_27 , V_13 -> V_61 ) ;
F_66 ( V_27 , V_13 -> V_65 ) ;
if ( V_13 -> V_16 . V_112 != V_13 -> V_18 . V_112 ||
V_13 -> V_16 . V_113 != V_13 -> V_18 . V_113 ) {
if ( V_27 -> V_132 -> V_133 == V_134 )
V_130 |= V_135 ;
else
F_67 ( V_27 , & V_13 -> V_16 , & V_13 -> V_18 ) ;
}
F_68 ( V_27 , V_130 ) ;
F_69 ( V_27 ) ;
F_17 ( & V_27 -> V_56 , V_55 ) ;
}
static T_2 F_70 ( int V_136 , void * V_92 )
{
struct V_68 * V_27 = V_92 ;
struct V_12 * V_13 = V_27 -> V_125 ;
struct V_29 * V_128 , * V_129 ;
F_71 ( V_27 ) ;
F_72 ( V_27 -> V_131 ) ;
F_73 ( V_13 == NULL ) ;
V_128 = F_74 ( V_13 -> V_31 . V_32 ) ;
V_129 = F_75 ( V_13 -> V_31 . V_32 ) ;
F_73 ( V_128 == NULL ) ;
F_73 ( V_129 == NULL ) ;
V_129 -> V_137 . V_138 = V_128 -> V_137 . V_138 ;
V_129 -> V_137 . V_139 = V_128 -> V_137 . V_139 ;
V_129 -> V_137 . V_55 &= ~ V_140 ;
V_129 -> V_137 . V_55 |=
V_128 -> V_137 . V_55 & V_140 ;
F_76 ( V_128 , V_141 ) ;
F_76 ( V_129 , V_141 ) ;
F_77 ( V_27 -> V_79 , V_13 -> V_31 . V_32 ) ;
V_27 -> V_125 = NULL ;
F_78 ( & V_27 -> V_126 ) ;
return V_142 ;
}
static int F_79 ( struct V_143 * V_144 )
{
struct V_68 * V_27 ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
const struct V_149 * V_150 ;
int V_36 = 0 ;
V_27 = F_80 ( & V_144 -> V_27 , sizeof( * V_27 ) , V_75 ) ;
if ( ! V_27 )
return - V_76 ;
F_81 ( & V_27 -> V_56 ) ;
F_82 ( & V_27 -> V_50 ) ;
F_83 ( & V_27 -> V_151 , 0 ) ;
F_84 ( & V_27 -> V_126 ) ;
V_148 = F_85 ( V_144 , V_152 , 0 ) ;
V_27 -> V_153 = F_86 ( & V_144 -> V_27 , V_148 ) ;
if ( F_6 ( V_27 -> V_153 ) )
return F_7 ( V_27 -> V_153 ) ;
V_27 -> V_154 = F_87 ( & V_144 -> V_27 , L_6 ) ;
if ( F_6 ( V_27 -> V_154 ) ) {
F_88 ( & V_144 -> V_27 , L_7 ) ;
return - V_155 ;
}
V_36 = F_89 ( V_27 -> V_154 ) ;
if ( V_36 ) {
F_88 ( & V_144 -> V_27 , L_8 ) ;
goto V_156;
}
V_27 -> V_131 = F_87 ( & V_144 -> V_27 , L_9 ) ;
if ( F_6 ( V_27 -> V_131 ) ) {
F_88 ( & V_144 -> V_27 , L_10 ) ;
V_36 = - V_155 ;
goto V_157;
}
V_36 = F_89 ( V_27 -> V_131 ) ;
if ( V_36 ) {
F_88 ( & V_144 -> V_27 , L_11 ) ;
goto V_158;
}
V_148 = F_85 ( V_144 , V_159 , 0 ) ;
if ( ! V_148 ) {
F_88 ( & V_144 -> V_27 , L_12 ) ;
V_36 = - V_155 ;
goto V_160;
}
V_27 -> V_136 = V_148 -> V_161 ;
V_36 = F_90 ( & V_144 -> V_27 , V_27 -> V_136 , F_70 ,
0 , V_144 -> V_96 , V_27 ) ;
if ( V_36 ) {
F_88 ( & V_144 -> V_27 , L_13 ) ;
goto V_158;
}
V_27 -> V_28 = F_91 ( & V_144 -> V_27 ) ;
if ( F_6 ( V_27 -> V_28 ) ) {
V_36 = F_7 ( V_27 -> V_28 ) ;
goto V_160;
}
V_36 = F_92 ( & V_144 -> V_27 , & V_27 -> V_73 ) ;
if ( V_36 )
goto V_162;
V_146 = F_93 () ;
if ( ! V_146 ) {
F_22 ( & V_27 -> V_73 , L_14 ) ;
V_36 = - V_76 ;
goto V_163;
}
* V_146 = V_164 ;
V_146 -> V_49 = & V_27 -> V_50 ;
V_146 -> V_73 = & V_27 -> V_73 ;
V_36 = F_94 ( V_146 , V_165 , 0 ) ;
if ( V_36 ) {
F_22 ( & V_27 -> V_73 , L_15 ) ;
goto V_166;
}
F_95 ( V_146 , V_27 ) ;
snprintf ( V_146 -> V_96 , sizeof( V_146 -> V_96 ) , L_16 , V_164 . V_96 ) ;
V_27 -> V_146 = V_146 ;
F_36 ( & V_27 -> V_73 , L_17 ,
V_146 -> V_167 ) ;
F_96 ( V_144 , V_27 ) ;
V_27 -> V_79 = F_97 ( & V_168 ) ;
if ( F_6 ( V_27 -> V_79 ) ) {
F_22 ( & V_27 -> V_73 , L_18 ) ;
V_36 = F_7 ( V_27 -> V_79 ) ;
goto V_169;
}
V_77 . V_116 = ( V_77 . V_98 * V_77 . V_8 -> V_103 ) >> 3 ;
if ( ! V_144 -> V_27 . V_170 ) {
V_27 -> V_132 = F_98 ( V_144 ) ;
} else {
V_150 = F_99 ( V_171 , V_144 -> V_27 . V_170 ) ;
if ( ! V_150 ) {
V_36 = - V_172 ;
goto V_169;
}
V_27 -> V_132 = (struct V_173 * ) V_150 -> V_174 ;
}
return 0 ;
V_169:
F_100 ( V_27 -> V_146 ) ;
V_166:
F_101 ( V_146 ) ;
V_163:
F_102 ( & V_27 -> V_73 ) ;
V_162:
F_103 ( V_27 -> V_28 ) ;
V_160:
F_104 ( V_27 -> V_131 ) ;
V_158:
F_105 ( V_27 -> V_131 ) ;
V_157:
F_104 ( V_27 -> V_154 ) ;
V_156:
F_105 ( V_27 -> V_154 ) ;
return V_36 ;
}
static int F_106 ( struct V_143 * V_144 )
{
struct V_68 * V_27 = F_107 ( V_144 ) ;
F_36 ( & V_27 -> V_73 , L_19 V_84 ) ;
F_108 ( V_27 -> V_79 ) ;
F_100 ( V_27 -> V_146 ) ;
F_102 ( & V_27 -> V_73 ) ;
F_103 ( V_27 -> V_28 ) ;
F_104 ( V_27 -> V_131 ) ;
F_105 ( V_27 -> V_131 ) ;
F_104 ( V_27 -> V_154 ) ;
F_105 ( V_27 -> V_154 ) ;
return 0 ;
}

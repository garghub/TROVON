static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_4 = & V_7 [ V_5 ] ;
if ( V_4 -> V_8 == V_3 -> V_4 . V_9 . V_10 )
break;
}
if ( V_5 == V_6 )
return NULL ;
return & V_7 [ V_5 ] ;
}
static struct V_11 * F_2 ( struct V_12 * V_13 ,
enum V_14 type )
{
switch ( type ) {
case V_15 :
return & ( V_13 -> V_16 [ V_17 ] ) ;
case V_18 :
return & ( V_13 -> V_16 [ V_19 ] ) ;
default:
F_3 () ;
}
return NULL ;
}
static void F_4 ( void * V_20 )
{
struct V_12 * V_13 = V_20 ;
struct V_21 * V_22 = V_13 -> V_23 ;
V_13 -> V_24 = 1 ;
F_5 ( V_22 , L_1 ) ;
F_6 ( V_22 -> V_25 , V_13 -> V_26 ) ;
}
static void F_7 ( void * V_20 )
{
struct V_12 * V_13 = V_20 ;
struct V_21 * V_22 = V_13 -> V_23 ;
F_8 ( & V_22 -> V_27 ) ;
}
static void F_9 ( void * V_20 )
{
struct V_12 * V_13 = V_20 ;
struct V_21 * V_22 = V_13 -> V_23 ;
F_10 ( & V_22 -> V_27 ) ;
}
static inline void F_11 ( struct V_21 * V_22 )
{
F_5 ( V_22 ,
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9 ,
F_12 ( V_22 -> V_28 + V_29 ) ,
F_12 ( V_22 -> V_28 + V_30 ) ,
F_12 ( V_22 -> V_28 + V_31 ) ,
F_12 ( V_22 -> V_28 + V_32 ) ,
F_12 ( V_22 -> V_28 + V_33 ) ,
F_12 ( V_22 -> V_28 + V_34 ) ,
F_12 ( V_22 -> V_28 + V_35 ) ) ;
}
static void F_13 ( void * V_20 )
{
struct V_12 * V_13 = V_20 ;
struct V_11 * V_36 , * V_37 ;
struct V_38 * V_39 , * V_40 ;
struct V_21 * V_22 = V_13 -> V_23 ;
unsigned int V_41 , V_42 ;
unsigned int V_43 , V_44 ;
unsigned int V_45 ;
T_1 V_46 , V_47 ;
T_2 V_48 ;
V_39 = F_14 ( V_13 -> V_26 ) ;
V_40 = F_15 ( V_13 -> V_26 ) ;
V_36 = F_2 ( V_13 , V_15 ) ;
V_41 = V_36 -> V_49 ;
V_42 = V_36 -> V_50 ;
V_37 = F_2 ( V_13 , V_18 ) ;
V_43 = V_37 -> V_49 ;
V_44 = V_37 -> V_50 ;
V_45 = V_43 * V_44 ;
V_46 = F_16 ( V_39 , 0 ) ;
V_47 = F_16 ( V_40 , 0 ) ;
if ( ! V_46 || ! V_47 ) {
F_17 ( & V_22 -> V_51 ,
L_10 ) ;
return;
}
F_18 ( V_46 , V_22 -> V_28 + V_29 ) ;
F_18 ( F_19 ( V_41 ) | F_20 ( V_42 ) ,
V_22 -> V_28 + V_30 ) ;
F_18 ( V_47 , V_22 -> V_28 + V_31 ) ;
F_18 ( V_47 + V_45 , V_22 -> V_28 + V_33 ) ;
F_18 ( V_47 + V_45 + ( V_45 >> 2 ) ,
V_22 -> V_28 + V_32 ) ;
F_18 ( F_19 ( V_43 ) | F_20 ( V_44 ) ,
V_22 -> V_28 + V_34 ) ;
V_48 = F_12 ( V_22 -> V_28 + V_52 ) ;
F_18 ( V_48 | V_53 |
V_54 |
V_55 ,
V_22 -> V_28 + V_52 ) ;
F_11 ( V_22 ) ;
V_48 = F_12 ( V_22 -> V_28 + V_35 ) ;
F_18 ( V_48 | V_56 |
V_57 |
V_58 ,
V_22 -> V_28 + V_35 ) ;
}
static T_3 F_21 ( int V_59 , void * V_60 )
{
struct V_21 * V_22 = V_60 ;
struct V_12 * V_61 ;
struct V_38 * V_62 , * V_63 ;
unsigned long V_64 ;
T_2 V_65 ;
V_65 = F_12 ( V_22 -> V_28 + V_66 ) ;
F_18 ( V_65 , V_22 -> V_28 + V_66 ) ;
F_5 ( V_22 , L_11 , V_65 ) ;
V_61 = F_22 ( V_22 -> V_25 ) ;
if ( V_61 == NULL ) {
F_23 ( L_12 ) ;
return V_67 ;
}
if ( ! V_61 -> V_24 ) {
if ( ( V_65 & V_68 ) ||
( V_65 & V_69 ) ) {
F_23 ( L_13 ) ;
F_18 ( V_70 , V_22 -> V_28 + V_35 ) ;
} else if ( V_65 & V_71 ) {
V_62 = F_24 ( V_61 -> V_26 ) ;
V_63 = F_25 ( V_61 -> V_26 ) ;
V_62 -> V_72 . V_73 = V_63 -> V_72 . V_73 ;
V_62 -> V_72 . V_74 = V_63 -> V_72 . V_74 ;
F_26 ( & V_22 -> V_75 , V_64 ) ;
F_27 ( V_62 , V_76 ) ;
F_27 ( V_63 , V_76 ) ;
F_28 ( & V_22 -> V_75 , V_64 ) ;
}
}
F_6 ( V_22 -> V_25 , V_61 -> V_26 ) ;
return V_67 ;
}
static int F_29 ( struct V_77 * V_77 , void * V_20 ,
struct V_78 * V_79 )
{
strncpy ( V_79 -> V_80 , V_81 , sizeof( V_79 -> V_80 ) - 1 ) ;
strncpy ( V_79 -> V_82 , V_81 , sizeof( V_79 -> V_82 ) - 1 ) ;
V_79 -> V_83 = V_84 | V_85 |
V_86 | V_87 ;
return 0 ;
}
static int F_30 ( struct V_88 * V_3 , T_2 type )
{
int V_89 , V_90 ;
struct V_1 * V_4 ;
V_90 = 0 ;
for ( V_89 = 0 ; V_89 < V_6 ; ++ V_89 ) {
if ( V_7 [ V_89 ] . V_91 & type ) {
if ( V_90 == V_3 -> V_92 )
break;
++ V_90 ;
}
}
if ( V_89 < V_6 ) {
V_4 = & V_7 [ V_89 ] ;
F_31 ( V_3 -> V_93 , V_4 -> V_94 , sizeof( V_3 -> V_93 ) - 1 ) ;
V_3 -> V_10 = V_4 -> V_8 ;
return 0 ;
}
return - V_95 ;
}
static int F_32 ( struct V_77 * V_77 , void * V_20 ,
struct V_88 * V_3 )
{
return F_30 ( V_3 , V_96 ) ;
}
static int F_33 ( struct V_77 * V_77 , void * V_20 ,
struct V_88 * V_3 )
{
return F_30 ( V_3 , V_97 ) ;
}
static int F_34 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
struct V_98 * V_99 ;
struct V_11 * V_16 ;
V_99 = F_35 ( V_13 -> V_26 , V_3 -> type ) ;
if ( ! V_99 )
return - V_95 ;
V_16 = F_2 ( V_13 , V_3 -> type ) ;
V_3 -> V_4 . V_9 . V_49 = V_16 -> V_49 ;
V_3 -> V_4 . V_9 . V_50 = V_16 -> V_50 ;
V_3 -> V_4 . V_9 . V_100 = V_101 ;
V_3 -> V_4 . V_9 . V_10 = V_16 -> V_4 -> V_8 ;
if ( V_3 -> V_4 . V_9 . V_10 == V_102 )
V_3 -> V_4 . V_9 . V_103 = V_16 -> V_49 * 3 / 2 ;
else
V_3 -> V_4 . V_9 . V_103 = V_16 -> V_49 * 2 ;
V_3 -> V_4 . V_9 . V_104 = V_16 -> V_104 ;
return 0 ;
}
static int F_36 ( struct V_77 * V_77 , void * V_20 ,
struct V_2 * V_3 )
{
return F_34 ( V_20 , V_3 ) ;
}
static int F_37 ( struct V_77 * V_77 , void * V_20 ,
struct V_2 * V_3 )
{
return F_34 ( V_20 , V_3 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
enum V_105 V_100 ;
if ( ! F_1 ( V_3 ) )
return - V_95 ;
V_100 = V_3 -> V_4 . V_9 . V_100 ;
if ( V_100 == V_106 )
V_100 = V_101 ;
else if ( V_101 != V_100 )
return - V_95 ;
V_3 -> V_4 . V_9 . V_100 = V_100 ;
if ( V_3 -> V_4 . V_9 . V_10 == V_102 ) {
F_39 ( & V_3 -> V_4 . V_9 . V_49 , V_107 , V_108 ,
V_109 , & V_3 -> V_4 . V_9 . V_50 ,
V_110 , V_111 , V_112 , V_113 ) ;
V_3 -> V_4 . V_9 . V_103 = V_3 -> V_4 . V_9 . V_49 * 3 / 2 ;
} else {
F_39 ( & V_3 -> V_4 . V_9 . V_49 , V_107 , V_108 ,
V_114 , & V_3 -> V_4 . V_9 . V_50 ,
V_110 , V_111 , V_112 , V_113 ) ;
V_3 -> V_4 . V_9 . V_103 = V_3 -> V_4 . V_9 . V_49 * 2 ;
}
V_3 -> V_4 . V_9 . V_104 = V_3 -> V_4 . V_9 . V_50 * V_3 -> V_4 . V_9 . V_103 ;
return 0 ;
}
static int F_40 ( struct V_77 * V_77 , void * V_20 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_12 * V_13 = V_20 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || ! ( V_4 -> V_91 & V_96 ) ) {
F_17 ( & V_13 -> V_23 -> V_51 ,
L_14 ,
V_3 -> V_4 . V_9 . V_10 ) ;
return - V_95 ;
}
return F_38 ( V_3 ) ;
}
static int F_41 ( struct V_77 * V_77 , void * V_20 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_12 * V_13 = V_20 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || ! ( V_4 -> V_91 & V_97 ) ) {
F_17 ( & V_13 -> V_23 -> V_51 ,
L_14 ,
V_3 -> V_4 . V_9 . V_10 ) ;
return - V_95 ;
}
return F_38 ( V_3 ) ;
}
static int F_42 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
struct V_11 * V_16 ;
struct V_98 * V_99 ;
int V_115 ;
V_99 = F_35 ( V_13 -> V_26 , V_3 -> type ) ;
if ( ! V_99 )
return - V_95 ;
V_16 = F_2 ( V_13 , V_3 -> type ) ;
if ( ! V_16 )
return - V_95 ;
if ( F_43 ( V_99 ) ) {
F_17 ( & V_13 -> V_23 -> V_51 , L_15 , V_116 ) ;
return - V_117 ;
}
V_115 = F_38 ( V_3 ) ;
if ( V_115 )
return V_115 ;
V_16 -> V_4 = F_1 ( V_3 ) ;
V_16 -> V_49 = V_3 -> V_4 . V_9 . V_49 ;
V_16 -> V_50 = V_3 -> V_4 . V_9 . V_50 ;
if ( V_16 -> V_4 -> V_8 == V_102 )
V_16 -> V_104 = V_16 -> V_49 * V_16 -> V_50 * 3 / 2 ;
else
V_16 -> V_104 = V_16 -> V_49 * V_16 -> V_50 * 2 ;
F_5 ( V_13 -> V_23 ,
L_16 ,
V_3 -> type , V_16 -> V_49 , V_16 -> V_50 , V_16 -> V_4 -> V_8 ) ;
return 0 ;
}
static int F_44 ( struct V_77 * V_77 , void * V_20 ,
struct V_2 * V_3 )
{
int V_115 ;
V_115 = F_40 ( V_77 , V_20 , V_3 ) ;
if ( V_115 )
return V_115 ;
return F_42 ( V_20 , V_3 ) ;
}
static int F_45 ( struct V_77 * V_77 , void * V_20 ,
struct V_2 * V_3 )
{
int V_115 ;
V_115 = F_41 ( V_77 , V_20 , V_3 ) ;
if ( V_115 )
return V_115 ;
return F_42 ( V_20 , V_3 ) ;
}
static int F_46 ( struct V_77 * V_77 , void * V_20 ,
struct V_118 * V_119 )
{
struct V_12 * V_13 = V_20 ;
return F_47 ( V_77 , V_13 -> V_26 , V_119 ) ;
}
static int F_48 ( struct V_77 * V_77 , void * V_20 ,
struct V_120 * V_121 )
{
struct V_12 * V_13 = V_20 ;
return F_49 ( V_77 , V_13 -> V_26 , V_121 ) ;
}
static int F_50 ( struct V_77 * V_77 , void * V_20 , struct V_120 * V_121 )
{
struct V_12 * V_13 = V_20 ;
return F_51 ( V_77 , V_13 -> V_26 , V_121 ) ;
}
static int F_52 ( struct V_77 * V_77 , void * V_20 , struct V_120 * V_121 )
{
struct V_12 * V_13 = V_20 ;
return F_53 ( V_77 , V_13 -> V_26 , V_121 ) ;
}
static int F_54 ( struct V_77 * V_77 , void * V_20 ,
enum V_14 type )
{
struct V_12 * V_13 = V_20 ;
return F_55 ( V_77 , V_13 -> V_26 , type ) ;
}
static int F_56 ( struct V_77 * V_77 , void * V_20 ,
enum V_14 type )
{
struct V_12 * V_13 = V_20 ;
return F_57 ( V_77 , V_13 -> V_26 , type ) ;
}
static int F_58 ( struct V_98 * V_99 ,
const struct V_2 * V_4 ,
unsigned int * V_122 , unsigned int * V_123 ,
unsigned int V_124 [] , void * V_125 [] )
{
struct V_12 * V_13 = F_59 ( V_99 ) ;
struct V_11 * V_16 ;
unsigned int V_126 , V_127 = * V_122 ;
V_16 = F_2 ( V_13 , V_99 -> type ) ;
if ( V_16 -> V_4 -> V_8 == V_102 )
V_126 = V_16 -> V_49 * V_16 -> V_50 * 3 / 2 ;
else
V_126 = V_16 -> V_49 * V_16 -> V_50 * 2 ;
while ( V_126 * V_127 > V_128 )
( V_127 ) -- ;
* V_123 = 1 ;
* V_122 = V_127 ;
V_124 [ 0 ] = V_126 ;
V_125 [ 0 ] = V_13 -> V_23 -> V_129 ;
F_5 ( V_13 -> V_23 , L_17 , V_127 , V_126 ) ;
return 0 ;
}
static int F_60 ( struct V_38 * V_130 )
{
struct V_12 * V_13 = F_59 ( V_130 -> V_98 ) ;
struct V_11 * V_16 ;
F_5 ( V_13 -> V_23 , L_18 , V_130 -> V_98 -> type ) ;
V_16 = F_2 ( V_13 , V_130 -> V_98 -> type ) ;
if ( F_61 ( V_130 , 0 ) < V_16 -> V_104 ) {
F_5 ( V_13 -> V_23 , L_19
L_20 , V_116 ,
F_61 ( V_130 , 0 ) ,
( long ) V_16 -> V_104 ) ;
return - V_95 ;
}
F_62 ( V_130 , 0 , V_16 -> V_104 ) ;
return 0 ;
}
static void F_63 ( struct V_38 * V_130 )
{
struct V_12 * V_13 = F_59 ( V_130 -> V_98 ) ;
F_64 ( V_13 -> V_26 , V_130 ) ;
}
static int F_65 ( void * V_20 , struct V_98 * V_131 ,
struct V_98 * V_132 )
{
struct V_12 * V_13 = V_20 ;
int V_115 ;
V_131 -> type = V_15 ;
V_131 -> V_133 = V_134 | V_135 ;
V_131 -> V_136 = V_13 ;
V_131 -> V_137 = sizeof( struct V_138 ) ;
V_131 -> V_139 = & V_140 ;
V_131 -> V_141 = & V_142 ;
V_131 -> V_143 = V_144 ;
V_115 = F_66 ( V_131 ) ;
if ( V_115 )
return V_115 ;
V_132 -> type = V_18 ;
V_132 -> V_133 = V_134 | V_135 ;
V_132 -> V_136 = V_13 ;
V_132 -> V_137 = sizeof( struct V_138 ) ;
V_132 -> V_139 = & V_140 ;
V_132 -> V_141 = & V_142 ;
V_132 -> V_143 = V_144 ;
return F_66 ( V_132 ) ;
}
static int F_67 ( struct V_77 * V_77 )
{
struct V_21 * V_22 = F_68 ( V_77 ) ;
struct V_12 * V_13 ;
V_13 = F_69 ( sizeof *V_13 , V_145 ) ;
if ( ! V_13 )
return - V_146 ;
V_77 -> V_147 = V_13 ;
V_13 -> V_23 = V_22 ;
if ( F_70 ( & V_22 -> V_27 ) ) {
F_71 ( V_13 ) ;
return - V_148 ;
}
V_13 -> V_26 = F_72 ( V_22 -> V_25 , V_13 , & F_65 ) ;
if ( F_73 ( V_13 -> V_26 ) ) {
int V_115 = F_74 ( V_13 -> V_26 ) ;
F_10 ( & V_22 -> V_27 ) ;
F_71 ( V_13 ) ;
return V_115 ;
}
F_75 ( V_22 -> V_149 ) ;
F_75 ( V_22 -> V_150 ) ;
V_13 -> V_16 [ V_17 ] . V_4 = & V_7 [ 1 ] ;
V_13 -> V_16 [ V_19 ] . V_4 = & V_7 [ 0 ] ;
F_10 ( & V_22 -> V_27 ) ;
F_5 ( V_22 , L_21 , V_13 , V_13 -> V_26 ) ;
return 0 ;
}
static int F_76 ( struct V_77 * V_77 )
{
struct V_21 * V_22 = F_68 ( V_77 ) ;
struct V_12 * V_13 = V_77 -> V_147 ;
F_5 ( V_22 , L_22 , V_13 ) ;
F_8 ( & V_22 -> V_27 ) ;
F_77 ( V_22 -> V_150 ) ;
F_77 ( V_22 -> V_149 ) ;
F_78 ( V_13 -> V_26 ) ;
F_10 ( & V_22 -> V_27 ) ;
F_71 ( V_13 ) ;
return 0 ;
}
static unsigned int F_79 ( struct V_77 * V_77 ,
struct V_151 * V_152 )
{
struct V_21 * V_22 = F_68 ( V_77 ) ;
struct V_12 * V_13 = V_77 -> V_147 ;
unsigned int V_153 ;
F_8 ( & V_22 -> V_27 ) ;
V_153 = F_80 ( V_77 , V_13 -> V_26 , V_152 ) ;
F_10 ( & V_22 -> V_27 ) ;
return V_153 ;
}
static int F_81 ( struct V_77 * V_77 , struct V_154 * V_155 )
{
struct V_21 * V_22 = F_68 ( V_77 ) ;
struct V_12 * V_13 = V_77 -> V_147 ;
int V_115 ;
if ( F_70 ( & V_22 -> V_27 ) )
return - V_148 ;
V_115 = F_82 ( V_77 , V_13 -> V_26 , V_155 ) ;
F_10 ( & V_22 -> V_27 ) ;
return V_115 ;
}
static int F_83 ( struct V_156 * V_157 )
{
struct V_21 * V_22 ;
struct V_158 * V_159 ;
struct V_160 * V_161 ;
int V_59 ;
int V_115 ;
V_22 = F_84 ( & V_157 -> V_23 , sizeof( * V_22 ) , V_145 ) ;
if ( ! V_22 )
return - V_146 ;
F_85 ( & V_22 -> V_75 ) ;
V_22 -> V_149 = F_86 ( & V_157 -> V_23 , L_23 ) ;
if ( F_73 ( V_22 -> V_149 ) ) {
return F_74 ( V_22 -> V_149 ) ;
}
V_22 -> V_150 = F_86 ( & V_157 -> V_23 , L_24 ) ;
if ( F_73 ( V_22 -> V_150 ) )
return F_74 ( V_22 -> V_150 ) ;
V_59 = F_87 ( V_157 , 0 ) ;
V_161 = F_88 ( V_157 , V_162 , 0 ) ;
if ( V_59 < 0 || V_161 == NULL ) {
F_89 ( & V_157 -> V_23 , L_25 ) ;
return - V_163 ;
}
V_115 = F_90 ( & V_157 -> V_23 , & V_22 -> V_51 ) ;
if ( V_115 )
return V_115 ;
F_91 ( & V_22 -> V_27 ) ;
V_159 = F_92 () ;
if ( ! V_159 ) {
F_17 ( & V_22 -> V_51 , L_26 ) ;
V_115 = - V_146 ;
goto V_164;
}
* V_159 = V_165 ;
V_159 -> V_166 = & V_22 -> V_27 ;
F_93 ( V_159 , V_22 ) ;
snprintf ( V_159 -> V_94 , sizeof( V_159 -> V_94 ) , L_27 , V_165 . V_94 ) ;
V_22 -> V_159 = V_159 ;
F_94 ( & V_22 -> V_51 , V_167
L_28 , V_159 -> V_90 ) ;
F_95 ( V_157 , V_22 ) ;
V_22 -> V_28 = F_96 ( & V_157 -> V_23 , V_161 ) ;
if ( F_73 ( V_22 -> V_28 ) ) {
V_115 = F_74 ( V_22 -> V_28 ) ;
goto V_168;
}
V_22 -> V_59 = V_59 ;
V_22 -> V_161 = V_161 ;
if ( F_97 ( & V_157 -> V_23 , V_22 -> V_59 , F_21 ,
0 , V_81 , V_22 ) < 0 ) {
V_115 = - V_163 ;
goto V_168;
}
V_22 -> V_129 = F_98 ( & V_157 -> V_23 ) ;
if ( F_73 ( V_22 -> V_129 ) ) {
F_17 ( & V_22 -> V_51 , L_29 ) ;
V_115 = F_74 ( V_22 -> V_129 ) ;
goto V_168;
}
V_22 -> V_25 = F_99 ( & V_169 ) ;
if ( F_73 ( V_22 -> V_25 ) ) {
F_17 ( & V_22 -> V_51 , L_30 ) ;
V_115 = F_74 ( V_22 -> V_25 ) ;
goto V_170;
}
V_115 = F_100 ( V_159 , V_171 , 0 ) ;
if ( V_115 ) {
F_17 ( & V_22 -> V_51 , L_31 ) ;
goto V_172;
}
return 0 ;
V_172:
F_101 ( V_22 -> V_25 ) ;
V_170:
F_102 ( V_22 -> V_129 ) ;
V_168:
F_103 ( V_159 ) ;
V_164:
F_104 ( & V_22 -> V_51 ) ;
return V_115 ;
}
static int F_105 ( struct V_156 * V_157 )
{
struct V_21 * V_22 = F_106 ( V_157 ) ;
F_94 ( & V_22 -> V_51 , L_32 V_167 ) ;
F_107 ( V_22 -> V_159 ) ;
F_101 ( V_22 -> V_25 ) ;
F_102 ( V_22 -> V_129 ) ;
F_104 ( & V_22 -> V_51 ) ;
return 0 ;
}

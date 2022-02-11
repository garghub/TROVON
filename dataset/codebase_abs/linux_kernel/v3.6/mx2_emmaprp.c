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
F_26 ( & V_22 -> V_72 , V_64 ) ;
F_27 ( V_62 , V_73 ) ;
F_27 ( V_63 , V_73 ) ;
F_28 ( & V_22 -> V_72 , V_64 ) ;
}
}
F_6 ( V_22 -> V_25 , V_61 -> V_26 ) ;
return V_67 ;
}
static int F_29 ( struct V_74 * V_74 , void * V_20 ,
struct V_75 * V_76 )
{
strncpy ( V_76 -> V_77 , V_78 , sizeof( V_76 -> V_77 ) - 1 ) ;
strncpy ( V_76 -> V_79 , V_78 , sizeof( V_76 -> V_79 ) - 1 ) ;
V_76 -> V_80 = V_81 | V_82 |
V_83 | V_84 ;
return 0 ;
}
static int F_30 ( struct V_85 * V_3 , T_2 type )
{
int V_86 , V_87 ;
struct V_1 * V_4 ;
V_87 = 0 ;
for ( V_86 = 0 ; V_86 < V_6 ; ++ V_86 ) {
if ( V_7 [ V_86 ] . V_88 & type ) {
if ( V_87 == V_3 -> V_89 )
break;
++ V_87 ;
}
}
if ( V_86 < V_6 ) {
V_4 = & V_7 [ V_86 ] ;
F_31 ( V_3 -> V_90 , V_4 -> V_91 , sizeof( V_3 -> V_90 ) - 1 ) ;
V_3 -> V_10 = V_4 -> V_8 ;
return 0 ;
}
return - V_92 ;
}
static int F_32 ( struct V_74 * V_74 , void * V_20 ,
struct V_85 * V_3 )
{
return F_30 ( V_3 , V_93 ) ;
}
static int F_33 ( struct V_74 * V_74 , void * V_20 ,
struct V_85 * V_3 )
{
return F_30 ( V_3 , V_94 ) ;
}
static int F_34 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
struct V_95 * V_96 ;
struct V_11 * V_16 ;
V_96 = F_35 ( V_13 -> V_26 , V_3 -> type ) ;
if ( ! V_96 )
return - V_92 ;
V_16 = F_2 ( V_13 , V_3 -> type ) ;
V_3 -> V_4 . V_9 . V_49 = V_16 -> V_49 ;
V_3 -> V_4 . V_9 . V_50 = V_16 -> V_50 ;
V_3 -> V_4 . V_9 . V_97 = V_98 ;
V_3 -> V_4 . V_9 . V_10 = V_16 -> V_4 -> V_8 ;
if ( V_3 -> V_4 . V_9 . V_10 == V_99 )
V_3 -> V_4 . V_9 . V_100 = V_16 -> V_49 * 3 / 2 ;
else
V_3 -> V_4 . V_9 . V_100 = V_16 -> V_49 * 2 ;
V_3 -> V_4 . V_9 . V_101 = V_16 -> V_101 ;
return 0 ;
}
static int F_36 ( struct V_74 * V_74 , void * V_20 ,
struct V_2 * V_3 )
{
return F_34 ( V_20 , V_3 ) ;
}
static int F_37 ( struct V_74 * V_74 , void * V_20 ,
struct V_2 * V_3 )
{
return F_34 ( V_20 , V_3 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
enum V_102 V_97 ;
if ( ! F_1 ( V_3 ) )
return - V_92 ;
V_97 = V_3 -> V_4 . V_9 . V_97 ;
if ( V_97 == V_103 )
V_97 = V_98 ;
else if ( V_98 != V_97 )
return - V_92 ;
V_3 -> V_4 . V_9 . V_97 = V_97 ;
if ( V_3 -> V_4 . V_9 . V_10 == V_99 ) {
F_39 ( & V_3 -> V_4 . V_9 . V_49 , V_104 , V_105 ,
V_106 , & V_3 -> V_4 . V_9 . V_50 ,
V_107 , V_108 , V_109 , V_110 ) ;
V_3 -> V_4 . V_9 . V_100 = V_3 -> V_4 . V_9 . V_49 * 3 / 2 ;
} else {
F_39 ( & V_3 -> V_4 . V_9 . V_49 , V_104 , V_105 ,
V_111 , & V_3 -> V_4 . V_9 . V_50 ,
V_107 , V_108 , V_109 , V_110 ) ;
V_3 -> V_4 . V_9 . V_100 = V_3 -> V_4 . V_9 . V_49 * 2 ;
}
V_3 -> V_4 . V_9 . V_101 = V_3 -> V_4 . V_9 . V_50 * V_3 -> V_4 . V_9 . V_100 ;
return 0 ;
}
static int F_40 ( struct V_74 * V_74 , void * V_20 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_12 * V_13 = V_20 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || ! ( V_4 -> V_88 & V_93 ) ) {
F_17 ( & V_13 -> V_23 -> V_51 ,
L_14 ,
V_3 -> V_4 . V_9 . V_10 ) ;
return - V_92 ;
}
return F_38 ( V_3 ) ;
}
static int F_41 ( struct V_74 * V_74 , void * V_20 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_12 * V_13 = V_20 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || ! ( V_4 -> V_88 & V_94 ) ) {
F_17 ( & V_13 -> V_23 -> V_51 ,
L_14 ,
V_3 -> V_4 . V_9 . V_10 ) ;
return - V_92 ;
}
return F_38 ( V_3 ) ;
}
static int F_42 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
struct V_11 * V_16 ;
struct V_95 * V_96 ;
int V_112 ;
V_96 = F_35 ( V_13 -> V_26 , V_3 -> type ) ;
if ( ! V_96 )
return - V_92 ;
V_16 = F_2 ( V_13 , V_3 -> type ) ;
if ( ! V_16 )
return - V_92 ;
if ( F_43 ( V_96 ) ) {
F_17 ( & V_13 -> V_23 -> V_51 , L_15 , V_113 ) ;
return - V_114 ;
}
V_112 = F_38 ( V_3 ) ;
if ( V_112 )
return V_112 ;
V_16 -> V_4 = F_1 ( V_3 ) ;
V_16 -> V_49 = V_3 -> V_4 . V_9 . V_49 ;
V_16 -> V_50 = V_3 -> V_4 . V_9 . V_50 ;
if ( V_16 -> V_4 -> V_8 == V_99 )
V_16 -> V_101 = V_16 -> V_49 * V_16 -> V_50 * 3 / 2 ;
else
V_16 -> V_101 = V_16 -> V_49 * V_16 -> V_50 * 2 ;
F_5 ( V_13 -> V_23 ,
L_16 ,
V_3 -> type , V_16 -> V_49 , V_16 -> V_50 , V_16 -> V_4 -> V_8 ) ;
return 0 ;
}
static int F_44 ( struct V_74 * V_74 , void * V_20 ,
struct V_2 * V_3 )
{
int V_112 ;
V_112 = F_40 ( V_74 , V_20 , V_3 ) ;
if ( V_112 )
return V_112 ;
return F_42 ( V_20 , V_3 ) ;
}
static int F_45 ( struct V_74 * V_74 , void * V_20 ,
struct V_2 * V_3 )
{
int V_112 ;
V_112 = F_41 ( V_74 , V_20 , V_3 ) ;
if ( V_112 )
return V_112 ;
return F_42 ( V_20 , V_3 ) ;
}
static int F_46 ( struct V_74 * V_74 , void * V_20 ,
struct V_115 * V_116 )
{
struct V_12 * V_13 = V_20 ;
return F_47 ( V_74 , V_13 -> V_26 , V_116 ) ;
}
static int F_48 ( struct V_74 * V_74 , void * V_20 ,
struct V_117 * V_118 )
{
struct V_12 * V_13 = V_20 ;
return F_49 ( V_74 , V_13 -> V_26 , V_118 ) ;
}
static int F_50 ( struct V_74 * V_74 , void * V_20 , struct V_117 * V_118 )
{
struct V_12 * V_13 = V_20 ;
return F_51 ( V_74 , V_13 -> V_26 , V_118 ) ;
}
static int F_52 ( struct V_74 * V_74 , void * V_20 , struct V_117 * V_118 )
{
struct V_12 * V_13 = V_20 ;
return F_53 ( V_74 , V_13 -> V_26 , V_118 ) ;
}
static int F_54 ( struct V_74 * V_74 , void * V_20 ,
enum V_14 type )
{
struct V_12 * V_13 = V_20 ;
return F_55 ( V_74 , V_13 -> V_26 , type ) ;
}
static int F_56 ( struct V_74 * V_74 , void * V_20 ,
enum V_14 type )
{
struct V_12 * V_13 = V_20 ;
return F_57 ( V_74 , V_13 -> V_26 , type ) ;
}
static int F_58 ( struct V_95 * V_96 ,
const struct V_2 * V_4 ,
unsigned int * V_119 , unsigned int * V_120 ,
unsigned int V_121 [] , void * V_122 [] )
{
struct V_12 * V_13 = F_59 ( V_96 ) ;
struct V_11 * V_16 ;
unsigned int V_123 , V_124 = * V_119 ;
V_16 = F_2 ( V_13 , V_96 -> type ) ;
if ( V_16 -> V_4 -> V_8 == V_99 )
V_123 = V_16 -> V_49 * V_16 -> V_50 * 3 / 2 ;
else
V_123 = V_16 -> V_49 * V_16 -> V_50 * 2 ;
while ( V_123 * V_124 > V_125 )
( V_124 ) -- ;
* V_120 = 1 ;
* V_119 = V_124 ;
V_121 [ 0 ] = V_123 ;
V_122 [ 0 ] = V_13 -> V_23 -> V_126 ;
F_5 ( V_13 -> V_23 , L_17 , V_124 , V_123 ) ;
return 0 ;
}
static int F_60 ( struct V_38 * V_127 )
{
struct V_12 * V_13 = F_59 ( V_127 -> V_95 ) ;
struct V_11 * V_16 ;
F_5 ( V_13 -> V_23 , L_18 , V_127 -> V_95 -> type ) ;
V_16 = F_2 ( V_13 , V_127 -> V_95 -> type ) ;
if ( F_61 ( V_127 , 0 ) < V_16 -> V_101 ) {
F_5 ( V_13 -> V_23 , L_19
L_20 , V_113 ,
F_61 ( V_127 , 0 ) ,
( long ) V_16 -> V_101 ) ;
return - V_92 ;
}
F_62 ( V_127 , 0 , V_16 -> V_101 ) ;
return 0 ;
}
static void F_63 ( struct V_38 * V_127 )
{
struct V_12 * V_13 = F_59 ( V_127 -> V_95 ) ;
F_64 ( V_13 -> V_26 , V_127 ) ;
}
static int F_65 ( void * V_20 , struct V_95 * V_128 ,
struct V_95 * V_129 )
{
struct V_12 * V_13 = V_20 ;
int V_112 ;
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
V_128 -> type = V_15 ;
V_128 -> V_130 = V_131 | V_132 ;
V_128 -> V_133 = V_13 ;
V_128 -> V_134 = sizeof( struct V_135 ) ;
V_128 -> V_136 = & V_137 ;
V_128 -> V_138 = & V_139 ;
V_112 = F_66 ( V_128 ) ;
if ( V_112 )
return V_112 ;
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
V_129 -> type = V_18 ;
V_129 -> V_130 = V_131 | V_132 ;
V_129 -> V_133 = V_13 ;
V_129 -> V_134 = sizeof( struct V_135 ) ;
V_129 -> V_136 = & V_137 ;
V_129 -> V_138 = & V_139 ;
return F_66 ( V_129 ) ;
}
static int F_67 ( struct V_74 * V_74 )
{
struct V_21 * V_22 = F_68 ( V_74 ) ;
struct V_12 * V_13 ;
V_13 = F_69 ( sizeof *V_13 , V_140 ) ;
if ( ! V_13 )
return - V_141 ;
V_74 -> V_142 = V_13 ;
V_13 -> V_23 = V_22 ;
V_13 -> V_26 = F_70 ( V_22 -> V_25 , V_13 , & F_65 ) ;
if ( F_71 ( V_13 -> V_26 ) ) {
int V_112 = F_72 ( V_13 -> V_26 ) ;
F_73 ( V_13 ) ;
return V_112 ;
}
F_74 ( V_22 -> V_143 ) ;
V_13 -> V_16 [ V_17 ] . V_4 = & V_7 [ 1 ] ;
V_13 -> V_16 [ V_19 ] . V_4 = & V_7 [ 0 ] ;
F_5 ( V_22 , L_21 , V_13 , V_13 -> V_26 ) ;
return 0 ;
}
static int F_75 ( struct V_74 * V_74 )
{
struct V_21 * V_22 = F_68 ( V_74 ) ;
struct V_12 * V_13 = V_74 -> V_142 ;
F_5 ( V_22 , L_22 , V_13 ) ;
F_76 ( V_22 -> V_143 ) ;
F_77 ( V_13 -> V_26 ) ;
F_73 ( V_13 ) ;
return 0 ;
}
static unsigned int F_78 ( struct V_74 * V_74 ,
struct V_144 * V_145 )
{
struct V_12 * V_13 = V_74 -> V_142 ;
return F_79 ( V_74 , V_13 -> V_26 , V_145 ) ;
}
static int F_80 ( struct V_74 * V_74 , struct V_146 * V_147 )
{
struct V_12 * V_13 = V_74 -> V_142 ;
return F_81 ( V_74 , V_13 -> V_26 , V_147 ) ;
}
static int F_82 ( struct V_148 * V_149 )
{
struct V_21 * V_22 ;
struct V_150 * V_151 ;
struct V_152 * V_153 ;
int V_59 ;
int V_112 ;
V_22 = F_69 ( sizeof *V_22 , V_140 ) ;
if ( ! V_22 )
return - V_141 ;
F_83 ( & V_22 -> V_72 ) ;
V_22 -> V_143 = F_84 ( & V_149 -> V_23 , NULL ) ;
if ( F_71 ( V_22 -> V_143 ) ) {
V_112 = F_72 ( V_22 -> V_143 ) ;
goto V_154;
}
V_59 = F_85 ( V_149 , 0 ) ;
V_153 = F_86 ( V_149 , V_155 , 0 ) ;
if ( V_59 < 0 || V_153 == NULL ) {
F_87 ( & V_149 -> V_23 , L_23 ) ;
V_112 = - V_156 ;
goto V_157;
}
V_112 = F_88 ( & V_149 -> V_23 , & V_22 -> V_51 ) ;
if ( V_112 )
goto V_157;
F_89 ( & V_22 -> V_27 ) ;
V_151 = F_90 () ;
if ( ! V_151 ) {
F_17 ( & V_22 -> V_51 , L_24 ) ;
V_112 = - V_141 ;
goto V_158;
}
* V_151 = V_159 ;
F_91 ( V_160 , & V_151 -> V_64 ) ;
V_151 -> V_161 = & V_22 -> V_27 ;
F_92 ( V_151 , V_22 ) ;
snprintf ( V_151 -> V_91 , sizeof( V_151 -> V_91 ) , L_25 , V_159 . V_91 ) ;
V_22 -> V_151 = V_151 ;
F_93 ( & V_22 -> V_51 , V_162
L_26 , V_151 -> V_87 ) ;
F_94 ( V_149 , V_22 ) ;
if ( F_95 ( & V_149 -> V_23 , V_153 -> V_163 ,
F_96 ( V_153 ) , V_78 ) == NULL )
goto V_164;
V_22 -> V_28 = F_97 ( & V_149 -> V_23 , V_153 -> V_163 ,
F_96 ( V_153 ) ) ;
if ( ! V_22 -> V_28 )
goto V_164;
V_22 -> V_59 = V_59 ;
V_22 -> V_153 = V_153 ;
if ( F_98 ( & V_149 -> V_23 , V_22 -> V_59 , F_21 ,
0 , V_78 , V_22 ) < 0 )
goto V_164;
V_22 -> V_126 = F_99 ( & V_149 -> V_23 ) ;
if ( F_71 ( V_22 -> V_126 ) ) {
F_17 ( & V_22 -> V_51 , L_27 ) ;
V_112 = F_72 ( V_22 -> V_126 ) ;
goto V_164;
}
V_22 -> V_25 = F_100 ( & V_165 ) ;
if ( F_71 ( V_22 -> V_25 ) ) {
F_17 ( & V_22 -> V_51 , L_28 ) ;
V_112 = F_72 ( V_22 -> V_25 ) ;
goto V_166;
}
V_112 = F_101 ( V_151 , V_167 , 0 ) ;
if ( V_112 ) {
F_17 ( & V_22 -> V_51 , L_29 ) ;
goto V_168;
}
return 0 ;
V_168:
F_102 ( V_22 -> V_25 ) ;
V_166:
F_103 ( V_22 -> V_126 ) ;
V_164:
F_104 ( V_151 ) ;
V_158:
F_105 ( & V_22 -> V_51 ) ;
V_157:
F_106 ( V_22 -> V_143 ) ;
V_154:
F_73 ( V_22 ) ;
return V_112 ;
}
static int F_107 ( struct V_148 * V_149 )
{
struct V_21 * V_22 = F_108 ( V_149 ) ;
F_93 ( & V_22 -> V_51 , L_30 V_162 ) ;
F_109 ( V_22 -> V_151 ) ;
F_102 ( V_22 -> V_25 ) ;
F_103 ( V_22 -> V_126 ) ;
F_105 ( & V_22 -> V_51 ) ;
F_106 ( V_22 -> V_143 ) ;
F_73 ( V_22 ) ;
return 0 ;
}
static void T_4 F_110 ( void )
{
F_111 ( & V_169 ) ;
}
static int T_5 F_112 ( void )
{
return F_113 ( & V_169 ) ;
}

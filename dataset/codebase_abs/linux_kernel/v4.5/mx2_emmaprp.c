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
struct V_62 * V_63 , * V_64 ;
unsigned long V_65 ;
T_2 V_66 ;
V_66 = F_12 ( V_22 -> V_28 + V_67 ) ;
F_18 ( V_66 , V_22 -> V_28 + V_67 ) ;
F_5 ( V_22 , L_11 , V_66 ) ;
V_61 = F_22 ( V_22 -> V_25 ) ;
if ( V_61 == NULL ) {
F_23 ( L_12 ) ;
return V_68 ;
}
if ( ! V_61 -> V_24 ) {
if ( ( V_66 & V_69 ) ||
( V_66 & V_70 ) ) {
F_23 ( L_13 ) ;
F_18 ( V_71 , V_22 -> V_28 + V_35 ) ;
} else if ( V_66 & V_72 ) {
V_63 = F_24 ( V_61 -> V_26 ) ;
V_64 = F_25 ( V_61 -> V_26 ) ;
V_64 -> V_73 . V_74 = V_63 -> V_73 . V_74 ;
V_64 -> V_65 &=
~ V_75 ;
V_64 -> V_65 |=
V_63 -> V_65
& V_75 ;
V_64 -> V_76 = V_63 -> V_76 ;
F_26 ( & V_22 -> V_77 , V_65 ) ;
F_27 ( V_63 , V_78 ) ;
F_27 ( V_64 , V_78 ) ;
F_28 ( & V_22 -> V_77 , V_65 ) ;
}
}
F_6 ( V_22 -> V_25 , V_61 -> V_26 ) ;
return V_68 ;
}
static int F_29 ( struct V_79 * V_79 , void * V_20 ,
struct V_80 * V_81 )
{
strncpy ( V_81 -> V_82 , V_83 , sizeof( V_81 -> V_82 ) - 1 ) ;
strncpy ( V_81 -> V_84 , V_83 , sizeof( V_81 -> V_84 ) - 1 ) ;
V_81 -> V_85 = V_86 | V_87 ;
V_81 -> V_88 = V_81 -> V_85 | V_89 ;
return 0 ;
}
static int F_30 ( struct V_90 * V_3 , T_2 type )
{
int V_91 , V_92 ;
struct V_1 * V_4 ;
V_92 = 0 ;
for ( V_91 = 0 ; V_91 < V_6 ; ++ V_91 ) {
if ( V_7 [ V_91 ] . V_93 & type ) {
if ( V_92 == V_3 -> V_94 )
break;
++ V_92 ;
}
}
if ( V_91 < V_6 ) {
V_4 = & V_7 [ V_91 ] ;
F_31 ( V_3 -> V_95 , V_4 -> V_96 , sizeof( V_3 -> V_95 ) - 1 ) ;
V_3 -> V_10 = V_4 -> V_8 ;
return 0 ;
}
return - V_97 ;
}
static int F_32 ( struct V_79 * V_79 , void * V_20 ,
struct V_90 * V_3 )
{
return F_30 ( V_3 , V_98 ) ;
}
static int F_33 ( struct V_79 * V_79 , void * V_20 ,
struct V_90 * V_3 )
{
return F_30 ( V_3 , V_99 ) ;
}
static int F_34 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
struct V_100 * V_101 ;
struct V_11 * V_16 ;
V_101 = F_35 ( V_13 -> V_26 , V_3 -> type ) ;
if ( ! V_101 )
return - V_97 ;
V_16 = F_2 ( V_13 , V_3 -> type ) ;
V_3 -> V_4 . V_9 . V_49 = V_16 -> V_49 ;
V_3 -> V_4 . V_9 . V_50 = V_16 -> V_50 ;
V_3 -> V_4 . V_9 . V_102 = V_103 ;
V_3 -> V_4 . V_9 . V_10 = V_16 -> V_4 -> V_8 ;
if ( V_3 -> V_4 . V_9 . V_10 == V_104 )
V_3 -> V_4 . V_9 . V_105 = V_16 -> V_49 * 3 / 2 ;
else
V_3 -> V_4 . V_9 . V_105 = V_16 -> V_49 * 2 ;
V_3 -> V_4 . V_9 . V_106 = V_16 -> V_106 ;
return 0 ;
}
static int F_36 ( struct V_79 * V_79 , void * V_20 ,
struct V_2 * V_3 )
{
return F_34 ( V_20 , V_3 ) ;
}
static int F_37 ( struct V_79 * V_79 , void * V_20 ,
struct V_2 * V_3 )
{
return F_34 ( V_20 , V_3 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
enum V_107 V_102 ;
if ( ! F_1 ( V_3 ) )
return - V_97 ;
V_102 = V_3 -> V_4 . V_9 . V_102 ;
if ( V_102 == V_108 )
V_102 = V_103 ;
else if ( V_103 != V_102 )
return - V_97 ;
V_3 -> V_4 . V_9 . V_102 = V_102 ;
if ( V_3 -> V_4 . V_9 . V_10 == V_104 ) {
F_39 ( & V_3 -> V_4 . V_9 . V_49 , V_109 , V_110 ,
V_111 , & V_3 -> V_4 . V_9 . V_50 ,
V_112 , V_113 , V_114 , V_115 ) ;
V_3 -> V_4 . V_9 . V_105 = V_3 -> V_4 . V_9 . V_49 * 3 / 2 ;
} else {
F_39 ( & V_3 -> V_4 . V_9 . V_49 , V_109 , V_110 ,
V_116 , & V_3 -> V_4 . V_9 . V_50 ,
V_112 , V_113 , V_114 , V_115 ) ;
V_3 -> V_4 . V_9 . V_105 = V_3 -> V_4 . V_9 . V_49 * 2 ;
}
V_3 -> V_4 . V_9 . V_106 = V_3 -> V_4 . V_9 . V_50 * V_3 -> V_4 . V_9 . V_105 ;
return 0 ;
}
static int F_40 ( struct V_79 * V_79 , void * V_20 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_12 * V_13 = V_20 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || ! ( V_4 -> V_93 & V_98 ) ) {
F_17 ( & V_13 -> V_23 -> V_51 ,
L_14 ,
V_3 -> V_4 . V_9 . V_10 ) ;
return - V_97 ;
}
return F_38 ( V_3 ) ;
}
static int F_41 ( struct V_79 * V_79 , void * V_20 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_12 * V_13 = V_20 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || ! ( V_4 -> V_93 & V_99 ) ) {
F_17 ( & V_13 -> V_23 -> V_51 ,
L_14 ,
V_3 -> V_4 . V_9 . V_10 ) ;
return - V_97 ;
}
return F_38 ( V_3 ) ;
}
static int F_42 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
struct V_11 * V_16 ;
struct V_100 * V_101 ;
int V_117 ;
V_101 = F_35 ( V_13 -> V_26 , V_3 -> type ) ;
if ( ! V_101 )
return - V_97 ;
V_16 = F_2 ( V_13 , V_3 -> type ) ;
if ( ! V_16 )
return - V_97 ;
if ( F_43 ( V_101 ) ) {
F_17 ( & V_13 -> V_23 -> V_51 , L_15 , V_118 ) ;
return - V_119 ;
}
V_117 = F_38 ( V_3 ) ;
if ( V_117 )
return V_117 ;
V_16 -> V_4 = F_1 ( V_3 ) ;
V_16 -> V_49 = V_3 -> V_4 . V_9 . V_49 ;
V_16 -> V_50 = V_3 -> V_4 . V_9 . V_50 ;
if ( V_16 -> V_4 -> V_8 == V_104 )
V_16 -> V_106 = V_16 -> V_49 * V_16 -> V_50 * 3 / 2 ;
else
V_16 -> V_106 = V_16 -> V_49 * V_16 -> V_50 * 2 ;
F_5 ( V_13 -> V_23 ,
L_16 ,
V_3 -> type , V_16 -> V_49 , V_16 -> V_50 , V_16 -> V_4 -> V_8 ) ;
return 0 ;
}
static int F_44 ( struct V_79 * V_79 , void * V_20 ,
struct V_2 * V_3 )
{
int V_117 ;
V_117 = F_40 ( V_79 , V_20 , V_3 ) ;
if ( V_117 )
return V_117 ;
return F_42 ( V_20 , V_3 ) ;
}
static int F_45 ( struct V_79 * V_79 , void * V_20 ,
struct V_2 * V_3 )
{
int V_117 ;
V_117 = F_41 ( V_79 , V_20 , V_3 ) ;
if ( V_117 )
return V_117 ;
return F_42 ( V_20 , V_3 ) ;
}
static int F_46 ( struct V_79 * V_79 , void * V_20 ,
struct V_120 * V_121 )
{
struct V_12 * V_13 = V_20 ;
return F_47 ( V_79 , V_13 -> V_26 , V_121 ) ;
}
static int F_48 ( struct V_79 * V_79 , void * V_20 ,
struct V_122 * V_123 )
{
struct V_12 * V_13 = V_20 ;
return F_49 ( V_79 , V_13 -> V_26 , V_123 ) ;
}
static int F_50 ( struct V_79 * V_79 , void * V_20 , struct V_122 * V_123 )
{
struct V_12 * V_13 = V_20 ;
return F_51 ( V_79 , V_13 -> V_26 , V_123 ) ;
}
static int F_52 ( struct V_79 * V_79 , void * V_20 , struct V_122 * V_123 )
{
struct V_12 * V_13 = V_20 ;
return F_53 ( V_79 , V_13 -> V_26 , V_123 ) ;
}
static int F_54 ( struct V_79 * V_79 , void * V_20 ,
enum V_14 type )
{
struct V_12 * V_13 = V_20 ;
return F_55 ( V_79 , V_13 -> V_26 , type ) ;
}
static int F_56 ( struct V_79 * V_79 , void * V_20 ,
enum V_14 type )
{
struct V_12 * V_13 = V_20 ;
return F_57 ( V_79 , V_13 -> V_26 , type ) ;
}
static int F_58 ( struct V_100 * V_101 ,
unsigned int * V_124 , unsigned int * V_125 ,
unsigned int V_126 [] , void * V_127 [] )
{
struct V_12 * V_13 = F_59 ( V_101 ) ;
struct V_11 * V_16 ;
unsigned int V_128 , V_129 = * V_124 ;
V_16 = F_2 ( V_13 , V_101 -> type ) ;
if ( V_16 -> V_4 -> V_8 == V_104 )
V_128 = V_16 -> V_49 * V_16 -> V_50 * 3 / 2 ;
else
V_128 = V_16 -> V_49 * V_16 -> V_50 * 2 ;
while ( V_128 * V_129 > V_130 )
( V_129 ) -- ;
* V_125 = 1 ;
* V_124 = V_129 ;
V_126 [ 0 ] = V_128 ;
V_127 [ 0 ] = V_13 -> V_23 -> V_131 ;
F_5 ( V_13 -> V_23 , L_17 , V_129 , V_128 ) ;
return 0 ;
}
static int F_60 ( struct V_38 * V_132 )
{
struct V_12 * V_13 = F_59 ( V_132 -> V_100 ) ;
struct V_11 * V_16 ;
F_5 ( V_13 -> V_23 , L_18 , V_132 -> V_100 -> type ) ;
V_16 = F_2 ( V_13 , V_132 -> V_100 -> type ) ;
if ( F_61 ( V_132 , 0 ) < V_16 -> V_106 ) {
F_5 ( V_13 -> V_23 , L_19
L_20 , V_118 ,
F_61 ( V_132 , 0 ) ,
( long ) V_16 -> V_106 ) ;
return - V_97 ;
}
F_62 ( V_132 , 0 , V_16 -> V_106 ) ;
return 0 ;
}
static void F_63 ( struct V_38 * V_132 )
{
struct V_62 * V_133 = F_64 ( V_132 ) ;
struct V_12 * V_13 = F_59 ( V_132 -> V_100 ) ;
F_65 ( V_13 -> V_26 , V_133 ) ;
}
static int F_66 ( void * V_20 , struct V_100 * V_134 ,
struct V_100 * V_135 )
{
struct V_12 * V_13 = V_20 ;
int V_117 ;
V_134 -> type = V_15 ;
V_134 -> V_136 = V_137 | V_138 ;
V_134 -> V_139 = V_13 ;
V_134 -> V_140 = sizeof( struct V_141 ) ;
V_134 -> V_142 = & V_143 ;
V_134 -> V_144 = & V_145 ;
V_134 -> V_146 = V_147 ;
V_117 = F_67 ( V_134 ) ;
if ( V_117 )
return V_117 ;
V_135 -> type = V_18 ;
V_135 -> V_136 = V_137 | V_138 ;
V_135 -> V_139 = V_13 ;
V_135 -> V_140 = sizeof( struct V_141 ) ;
V_135 -> V_142 = & V_143 ;
V_135 -> V_144 = & V_145 ;
V_135 -> V_146 = V_147 ;
return F_67 ( V_135 ) ;
}
static int F_68 ( struct V_79 * V_79 )
{
struct V_21 * V_22 = F_69 ( V_79 ) ;
struct V_12 * V_13 ;
V_13 = F_70 ( sizeof *V_13 , V_148 ) ;
if ( ! V_13 )
return - V_149 ;
V_79 -> V_150 = V_13 ;
V_13 -> V_23 = V_22 ;
if ( F_71 ( & V_22 -> V_27 ) ) {
F_72 ( V_13 ) ;
return - V_151 ;
}
V_13 -> V_26 = F_73 ( V_22 -> V_25 , V_13 , & F_66 ) ;
if ( F_74 ( V_13 -> V_26 ) ) {
int V_117 = F_75 ( V_13 -> V_26 ) ;
F_10 ( & V_22 -> V_27 ) ;
F_72 ( V_13 ) ;
return V_117 ;
}
F_76 ( V_22 -> V_152 ) ;
F_76 ( V_22 -> V_153 ) ;
V_13 -> V_16 [ V_17 ] . V_4 = & V_7 [ 1 ] ;
V_13 -> V_16 [ V_19 ] . V_4 = & V_7 [ 0 ] ;
F_10 ( & V_22 -> V_27 ) ;
F_5 ( V_22 , L_21 , V_13 , V_13 -> V_26 ) ;
return 0 ;
}
static int F_77 ( struct V_79 * V_79 )
{
struct V_21 * V_22 = F_69 ( V_79 ) ;
struct V_12 * V_13 = V_79 -> V_150 ;
F_5 ( V_22 , L_22 , V_13 ) ;
F_8 ( & V_22 -> V_27 ) ;
F_78 ( V_22 -> V_153 ) ;
F_78 ( V_22 -> V_152 ) ;
F_79 ( V_13 -> V_26 ) ;
F_10 ( & V_22 -> V_27 ) ;
F_72 ( V_13 ) ;
return 0 ;
}
static unsigned int F_80 ( struct V_79 * V_79 ,
struct V_154 * V_155 )
{
struct V_21 * V_22 = F_69 ( V_79 ) ;
struct V_12 * V_13 = V_79 -> V_150 ;
unsigned int V_156 ;
F_8 ( & V_22 -> V_27 ) ;
V_156 = F_81 ( V_79 , V_13 -> V_26 , V_155 ) ;
F_10 ( & V_22 -> V_27 ) ;
return V_156 ;
}
static int F_82 ( struct V_79 * V_79 , struct V_157 * V_158 )
{
struct V_21 * V_22 = F_69 ( V_79 ) ;
struct V_12 * V_13 = V_79 -> V_150 ;
int V_117 ;
if ( F_71 ( & V_22 -> V_27 ) )
return - V_151 ;
V_117 = F_83 ( V_79 , V_13 -> V_26 , V_158 ) ;
F_10 ( & V_22 -> V_27 ) ;
return V_117 ;
}
static int F_84 ( struct V_159 * V_160 )
{
struct V_21 * V_22 ;
struct V_161 * V_162 ;
struct V_163 * V_156 ;
int V_164 , V_117 ;
V_22 = F_85 ( & V_160 -> V_23 , sizeof( * V_22 ) , V_148 ) ;
if ( ! V_22 )
return - V_149 ;
F_86 ( & V_22 -> V_77 ) ;
V_22 -> V_152 = F_87 ( & V_160 -> V_23 , L_23 ) ;
if ( F_74 ( V_22 -> V_152 ) ) {
return F_75 ( V_22 -> V_152 ) ;
}
V_22 -> V_153 = F_87 ( & V_160 -> V_23 , L_24 ) ;
if ( F_74 ( V_22 -> V_153 ) )
return F_75 ( V_22 -> V_153 ) ;
V_156 = F_88 ( V_160 , V_165 , 0 ) ;
V_22 -> V_28 = F_89 ( & V_160 -> V_23 , V_156 ) ;
if ( F_74 ( V_22 -> V_28 ) )
return F_75 ( V_22 -> V_28 ) ;
V_117 = F_90 ( & V_160 -> V_23 , & V_22 -> V_51 ) ;
if ( V_117 )
return V_117 ;
F_91 ( & V_22 -> V_27 ) ;
V_162 = F_92 () ;
if ( ! V_162 ) {
F_17 ( & V_22 -> V_51 , L_25 ) ;
V_117 = - V_149 ;
goto V_166;
}
* V_162 = V_167 ;
V_162 -> V_168 = & V_22 -> V_27 ;
V_162 -> V_51 = & V_22 -> V_51 ;
F_93 ( V_162 , V_22 ) ;
snprintf ( V_162 -> V_96 , sizeof( V_162 -> V_96 ) , L_26 , V_167 . V_96 ) ;
V_22 -> V_162 = V_162 ;
F_94 ( & V_22 -> V_51 , V_169
L_27 , V_162 -> V_92 ) ;
F_95 ( V_160 , V_22 ) ;
V_164 = F_96 ( V_160 , 0 ) ;
V_117 = F_97 ( & V_160 -> V_23 , V_164 , F_21 , 0 ,
F_98 ( & V_160 -> V_23 ) , V_22 ) ;
if ( V_117 )
goto V_170;
V_22 -> V_131 = F_99 ( & V_160 -> V_23 ) ;
if ( F_74 ( V_22 -> V_131 ) ) {
F_17 ( & V_22 -> V_51 , L_28 ) ;
V_117 = F_75 ( V_22 -> V_131 ) ;
goto V_170;
}
V_22 -> V_25 = F_100 ( & V_171 ) ;
if ( F_74 ( V_22 -> V_25 ) ) {
F_17 ( & V_22 -> V_51 , L_29 ) ;
V_117 = F_75 ( V_22 -> V_25 ) ;
goto V_172;
}
V_117 = F_101 ( V_162 , V_173 , 0 ) ;
if ( V_117 ) {
F_17 ( & V_22 -> V_51 , L_30 ) ;
goto V_174;
}
return 0 ;
V_174:
F_102 ( V_22 -> V_25 ) ;
V_172:
F_103 ( V_22 -> V_131 ) ;
V_170:
F_104 ( V_162 ) ;
V_166:
F_105 ( & V_22 -> V_51 ) ;
F_106 ( & V_22 -> V_27 ) ;
return V_117 ;
}
static int F_107 ( struct V_159 * V_160 )
{
struct V_21 * V_22 = F_108 ( V_160 ) ;
F_94 ( & V_22 -> V_51 , L_31 V_169 ) ;
F_109 ( V_22 -> V_162 ) ;
F_102 ( V_22 -> V_25 ) ;
F_103 ( V_22 -> V_131 ) ;
F_105 ( & V_22 -> V_51 ) ;
F_106 ( & V_22 -> V_27 ) ;
return 0 ;
}

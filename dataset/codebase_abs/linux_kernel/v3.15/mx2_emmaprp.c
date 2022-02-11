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
V_63 -> V_72 . V_73 = V_62 -> V_72 . V_73 ;
V_63 -> V_72 . V_64 &=
~ V_74 ;
V_63 -> V_72 . V_64 |=
V_62 -> V_72 . V_64
& V_74 ;
V_63 -> V_72 . V_75 = V_62 -> V_72 . V_75 ;
F_26 ( & V_22 -> V_76 , V_64 ) ;
F_27 ( V_62 , V_77 ) ;
F_27 ( V_63 , V_77 ) ;
F_28 ( & V_22 -> V_76 , V_64 ) ;
}
}
F_6 ( V_22 -> V_25 , V_61 -> V_26 ) ;
return V_67 ;
}
static int F_29 ( struct V_78 * V_78 , void * V_20 ,
struct V_79 * V_80 )
{
strncpy ( V_80 -> V_81 , V_82 , sizeof( V_80 -> V_81 ) - 1 ) ;
strncpy ( V_80 -> V_83 , V_82 , sizeof( V_80 -> V_83 ) - 1 ) ;
V_80 -> V_84 = V_85 | V_86 |
V_87 | V_88 ;
return 0 ;
}
static int F_30 ( struct V_89 * V_3 , T_2 type )
{
int V_90 , V_91 ;
struct V_1 * V_4 ;
V_91 = 0 ;
for ( V_90 = 0 ; V_90 < V_6 ; ++ V_90 ) {
if ( V_7 [ V_90 ] . V_92 & type ) {
if ( V_91 == V_3 -> V_93 )
break;
++ V_91 ;
}
}
if ( V_90 < V_6 ) {
V_4 = & V_7 [ V_90 ] ;
F_31 ( V_3 -> V_94 , V_4 -> V_95 , sizeof( V_3 -> V_94 ) - 1 ) ;
V_3 -> V_10 = V_4 -> V_8 ;
return 0 ;
}
return - V_96 ;
}
static int F_32 ( struct V_78 * V_78 , void * V_20 ,
struct V_89 * V_3 )
{
return F_30 ( V_3 , V_97 ) ;
}
static int F_33 ( struct V_78 * V_78 , void * V_20 ,
struct V_89 * V_3 )
{
return F_30 ( V_3 , V_98 ) ;
}
static int F_34 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
struct V_99 * V_100 ;
struct V_11 * V_16 ;
V_100 = F_35 ( V_13 -> V_26 , V_3 -> type ) ;
if ( ! V_100 )
return - V_96 ;
V_16 = F_2 ( V_13 , V_3 -> type ) ;
V_3 -> V_4 . V_9 . V_49 = V_16 -> V_49 ;
V_3 -> V_4 . V_9 . V_50 = V_16 -> V_50 ;
V_3 -> V_4 . V_9 . V_101 = V_102 ;
V_3 -> V_4 . V_9 . V_10 = V_16 -> V_4 -> V_8 ;
if ( V_3 -> V_4 . V_9 . V_10 == V_103 )
V_3 -> V_4 . V_9 . V_104 = V_16 -> V_49 * 3 / 2 ;
else
V_3 -> V_4 . V_9 . V_104 = V_16 -> V_49 * 2 ;
V_3 -> V_4 . V_9 . V_105 = V_16 -> V_105 ;
return 0 ;
}
static int F_36 ( struct V_78 * V_78 , void * V_20 ,
struct V_2 * V_3 )
{
return F_34 ( V_20 , V_3 ) ;
}
static int F_37 ( struct V_78 * V_78 , void * V_20 ,
struct V_2 * V_3 )
{
return F_34 ( V_20 , V_3 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
enum V_106 V_101 ;
if ( ! F_1 ( V_3 ) )
return - V_96 ;
V_101 = V_3 -> V_4 . V_9 . V_101 ;
if ( V_101 == V_107 )
V_101 = V_102 ;
else if ( V_102 != V_101 )
return - V_96 ;
V_3 -> V_4 . V_9 . V_101 = V_101 ;
if ( V_3 -> V_4 . V_9 . V_10 == V_103 ) {
F_39 ( & V_3 -> V_4 . V_9 . V_49 , V_108 , V_109 ,
V_110 , & V_3 -> V_4 . V_9 . V_50 ,
V_111 , V_112 , V_113 , V_114 ) ;
V_3 -> V_4 . V_9 . V_104 = V_3 -> V_4 . V_9 . V_49 * 3 / 2 ;
} else {
F_39 ( & V_3 -> V_4 . V_9 . V_49 , V_108 , V_109 ,
V_115 , & V_3 -> V_4 . V_9 . V_50 ,
V_111 , V_112 , V_113 , V_114 ) ;
V_3 -> V_4 . V_9 . V_104 = V_3 -> V_4 . V_9 . V_49 * 2 ;
}
V_3 -> V_4 . V_9 . V_105 = V_3 -> V_4 . V_9 . V_50 * V_3 -> V_4 . V_9 . V_104 ;
return 0 ;
}
static int F_40 ( struct V_78 * V_78 , void * V_20 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_12 * V_13 = V_20 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || ! ( V_4 -> V_92 & V_97 ) ) {
F_17 ( & V_13 -> V_23 -> V_51 ,
L_14 ,
V_3 -> V_4 . V_9 . V_10 ) ;
return - V_96 ;
}
return F_38 ( V_3 ) ;
}
static int F_41 ( struct V_78 * V_78 , void * V_20 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_12 * V_13 = V_20 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || ! ( V_4 -> V_92 & V_98 ) ) {
F_17 ( & V_13 -> V_23 -> V_51 ,
L_14 ,
V_3 -> V_4 . V_9 . V_10 ) ;
return - V_96 ;
}
return F_38 ( V_3 ) ;
}
static int F_42 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
struct V_11 * V_16 ;
struct V_99 * V_100 ;
int V_116 ;
V_100 = F_35 ( V_13 -> V_26 , V_3 -> type ) ;
if ( ! V_100 )
return - V_96 ;
V_16 = F_2 ( V_13 , V_3 -> type ) ;
if ( ! V_16 )
return - V_96 ;
if ( F_43 ( V_100 ) ) {
F_17 ( & V_13 -> V_23 -> V_51 , L_15 , V_117 ) ;
return - V_118 ;
}
V_116 = F_38 ( V_3 ) ;
if ( V_116 )
return V_116 ;
V_16 -> V_4 = F_1 ( V_3 ) ;
V_16 -> V_49 = V_3 -> V_4 . V_9 . V_49 ;
V_16 -> V_50 = V_3 -> V_4 . V_9 . V_50 ;
if ( V_16 -> V_4 -> V_8 == V_103 )
V_16 -> V_105 = V_16 -> V_49 * V_16 -> V_50 * 3 / 2 ;
else
V_16 -> V_105 = V_16 -> V_49 * V_16 -> V_50 * 2 ;
F_5 ( V_13 -> V_23 ,
L_16 ,
V_3 -> type , V_16 -> V_49 , V_16 -> V_50 , V_16 -> V_4 -> V_8 ) ;
return 0 ;
}
static int F_44 ( struct V_78 * V_78 , void * V_20 ,
struct V_2 * V_3 )
{
int V_116 ;
V_116 = F_40 ( V_78 , V_20 , V_3 ) ;
if ( V_116 )
return V_116 ;
return F_42 ( V_20 , V_3 ) ;
}
static int F_45 ( struct V_78 * V_78 , void * V_20 ,
struct V_2 * V_3 )
{
int V_116 ;
V_116 = F_41 ( V_78 , V_20 , V_3 ) ;
if ( V_116 )
return V_116 ;
return F_42 ( V_20 , V_3 ) ;
}
static int F_46 ( struct V_78 * V_78 , void * V_20 ,
struct V_119 * V_120 )
{
struct V_12 * V_13 = V_20 ;
return F_47 ( V_78 , V_13 -> V_26 , V_120 ) ;
}
static int F_48 ( struct V_78 * V_78 , void * V_20 ,
struct V_121 * V_122 )
{
struct V_12 * V_13 = V_20 ;
return F_49 ( V_78 , V_13 -> V_26 , V_122 ) ;
}
static int F_50 ( struct V_78 * V_78 , void * V_20 , struct V_121 * V_122 )
{
struct V_12 * V_13 = V_20 ;
return F_51 ( V_78 , V_13 -> V_26 , V_122 ) ;
}
static int F_52 ( struct V_78 * V_78 , void * V_20 , struct V_121 * V_122 )
{
struct V_12 * V_13 = V_20 ;
return F_53 ( V_78 , V_13 -> V_26 , V_122 ) ;
}
static int F_54 ( struct V_78 * V_78 , void * V_20 ,
enum V_14 type )
{
struct V_12 * V_13 = V_20 ;
return F_55 ( V_78 , V_13 -> V_26 , type ) ;
}
static int F_56 ( struct V_78 * V_78 , void * V_20 ,
enum V_14 type )
{
struct V_12 * V_13 = V_20 ;
return F_57 ( V_78 , V_13 -> V_26 , type ) ;
}
static int F_58 ( struct V_99 * V_100 ,
const struct V_2 * V_4 ,
unsigned int * V_123 , unsigned int * V_124 ,
unsigned int V_125 [] , void * V_126 [] )
{
struct V_12 * V_13 = F_59 ( V_100 ) ;
struct V_11 * V_16 ;
unsigned int V_127 , V_128 = * V_123 ;
V_16 = F_2 ( V_13 , V_100 -> type ) ;
if ( V_16 -> V_4 -> V_8 == V_103 )
V_127 = V_16 -> V_49 * V_16 -> V_50 * 3 / 2 ;
else
V_127 = V_16 -> V_49 * V_16 -> V_50 * 2 ;
while ( V_127 * V_128 > V_129 )
( V_128 ) -- ;
* V_124 = 1 ;
* V_123 = V_128 ;
V_125 [ 0 ] = V_127 ;
V_126 [ 0 ] = V_13 -> V_23 -> V_130 ;
F_5 ( V_13 -> V_23 , L_17 , V_128 , V_127 ) ;
return 0 ;
}
static int F_60 ( struct V_38 * V_131 )
{
struct V_12 * V_13 = F_59 ( V_131 -> V_99 ) ;
struct V_11 * V_16 ;
F_5 ( V_13 -> V_23 , L_18 , V_131 -> V_99 -> type ) ;
V_16 = F_2 ( V_13 , V_131 -> V_99 -> type ) ;
if ( F_61 ( V_131 , 0 ) < V_16 -> V_105 ) {
F_5 ( V_13 -> V_23 , L_19
L_20 , V_117 ,
F_61 ( V_131 , 0 ) ,
( long ) V_16 -> V_105 ) ;
return - V_96 ;
}
F_62 ( V_131 , 0 , V_16 -> V_105 ) ;
return 0 ;
}
static void F_63 ( struct V_38 * V_131 )
{
struct V_12 * V_13 = F_59 ( V_131 -> V_99 ) ;
F_64 ( V_13 -> V_26 , V_131 ) ;
}
static int F_65 ( void * V_20 , struct V_99 * V_132 ,
struct V_99 * V_133 )
{
struct V_12 * V_13 = V_20 ;
int V_116 ;
V_132 -> type = V_15 ;
V_132 -> V_134 = V_135 | V_136 ;
V_132 -> V_137 = V_13 ;
V_132 -> V_138 = sizeof( struct V_139 ) ;
V_132 -> V_140 = & V_141 ;
V_132 -> V_142 = & V_143 ;
V_132 -> V_144 = V_145 ;
V_116 = F_66 ( V_132 ) ;
if ( V_116 )
return V_116 ;
V_133 -> type = V_18 ;
V_133 -> V_134 = V_135 | V_136 ;
V_133 -> V_137 = V_13 ;
V_133 -> V_138 = sizeof( struct V_139 ) ;
V_133 -> V_140 = & V_141 ;
V_133 -> V_142 = & V_143 ;
V_133 -> V_144 = V_145 ;
return F_66 ( V_133 ) ;
}
static int F_67 ( struct V_78 * V_78 )
{
struct V_21 * V_22 = F_68 ( V_78 ) ;
struct V_12 * V_13 ;
V_13 = F_69 ( sizeof *V_13 , V_146 ) ;
if ( ! V_13 )
return - V_147 ;
V_78 -> V_148 = V_13 ;
V_13 -> V_23 = V_22 ;
if ( F_70 ( & V_22 -> V_27 ) ) {
F_71 ( V_13 ) ;
return - V_149 ;
}
V_13 -> V_26 = F_72 ( V_22 -> V_25 , V_13 , & F_65 ) ;
if ( F_73 ( V_13 -> V_26 ) ) {
int V_116 = F_74 ( V_13 -> V_26 ) ;
F_10 ( & V_22 -> V_27 ) ;
F_71 ( V_13 ) ;
return V_116 ;
}
F_75 ( V_22 -> V_150 ) ;
F_75 ( V_22 -> V_151 ) ;
V_13 -> V_16 [ V_17 ] . V_4 = & V_7 [ 1 ] ;
V_13 -> V_16 [ V_19 ] . V_4 = & V_7 [ 0 ] ;
F_10 ( & V_22 -> V_27 ) ;
F_5 ( V_22 , L_21 , V_13 , V_13 -> V_26 ) ;
return 0 ;
}
static int F_76 ( struct V_78 * V_78 )
{
struct V_21 * V_22 = F_68 ( V_78 ) ;
struct V_12 * V_13 = V_78 -> V_148 ;
F_5 ( V_22 , L_22 , V_13 ) ;
F_8 ( & V_22 -> V_27 ) ;
F_77 ( V_22 -> V_151 ) ;
F_77 ( V_22 -> V_150 ) ;
F_78 ( V_13 -> V_26 ) ;
F_10 ( & V_22 -> V_27 ) ;
F_71 ( V_13 ) ;
return 0 ;
}
static unsigned int F_79 ( struct V_78 * V_78 ,
struct V_152 * V_153 )
{
struct V_21 * V_22 = F_68 ( V_78 ) ;
struct V_12 * V_13 = V_78 -> V_148 ;
unsigned int V_154 ;
F_8 ( & V_22 -> V_27 ) ;
V_154 = F_80 ( V_78 , V_13 -> V_26 , V_153 ) ;
F_10 ( & V_22 -> V_27 ) ;
return V_154 ;
}
static int F_81 ( struct V_78 * V_78 , struct V_155 * V_156 )
{
struct V_21 * V_22 = F_68 ( V_78 ) ;
struct V_12 * V_13 = V_78 -> V_148 ;
int V_116 ;
if ( F_70 ( & V_22 -> V_27 ) )
return - V_149 ;
V_116 = F_82 ( V_78 , V_13 -> V_26 , V_156 ) ;
F_10 ( & V_22 -> V_27 ) ;
return V_116 ;
}
static int F_83 ( struct V_157 * V_158 )
{
struct V_21 * V_22 ;
struct V_159 * V_160 ;
struct V_161 * V_162 ;
int V_59 ;
int V_116 ;
V_22 = F_84 ( & V_158 -> V_23 , sizeof( * V_22 ) , V_146 ) ;
if ( ! V_22 )
return - V_147 ;
F_85 ( & V_22 -> V_76 ) ;
V_22 -> V_150 = F_86 ( & V_158 -> V_23 , L_23 ) ;
if ( F_73 ( V_22 -> V_150 ) ) {
return F_74 ( V_22 -> V_150 ) ;
}
V_22 -> V_151 = F_86 ( & V_158 -> V_23 , L_24 ) ;
if ( F_73 ( V_22 -> V_151 ) )
return F_74 ( V_22 -> V_151 ) ;
V_59 = F_87 ( V_158 , 0 ) ;
V_162 = F_88 ( V_158 , V_163 , 0 ) ;
if ( V_59 < 0 || V_162 == NULL ) {
F_89 ( & V_158 -> V_23 , L_25 ) ;
return - V_164 ;
}
V_116 = F_90 ( & V_158 -> V_23 , & V_22 -> V_51 ) ;
if ( V_116 )
return V_116 ;
F_91 ( & V_22 -> V_27 ) ;
V_160 = F_92 () ;
if ( ! V_160 ) {
F_17 ( & V_22 -> V_51 , L_26 ) ;
V_116 = - V_147 ;
goto V_165;
}
* V_160 = V_166 ;
V_160 -> V_167 = & V_22 -> V_27 ;
V_160 -> V_51 = & V_22 -> V_51 ;
F_93 ( V_160 , V_22 ) ;
snprintf ( V_160 -> V_95 , sizeof( V_160 -> V_95 ) , L_27 , V_166 . V_95 ) ;
V_22 -> V_160 = V_160 ;
F_94 ( & V_22 -> V_51 , V_168
L_28 , V_160 -> V_91 ) ;
F_95 ( V_158 , V_22 ) ;
V_22 -> V_28 = F_96 ( & V_158 -> V_23 , V_162 ) ;
if ( F_73 ( V_22 -> V_28 ) ) {
V_116 = F_74 ( V_22 -> V_28 ) ;
goto V_169;
}
V_22 -> V_59 = V_59 ;
V_22 -> V_162 = V_162 ;
if ( F_97 ( & V_158 -> V_23 , V_22 -> V_59 , F_21 ,
0 , V_82 , V_22 ) < 0 ) {
V_116 = - V_164 ;
goto V_169;
}
V_22 -> V_130 = F_98 ( & V_158 -> V_23 ) ;
if ( F_73 ( V_22 -> V_130 ) ) {
F_17 ( & V_22 -> V_51 , L_29 ) ;
V_116 = F_74 ( V_22 -> V_130 ) ;
goto V_169;
}
V_22 -> V_25 = F_99 ( & V_170 ) ;
if ( F_73 ( V_22 -> V_25 ) ) {
F_17 ( & V_22 -> V_51 , L_30 ) ;
V_116 = F_74 ( V_22 -> V_25 ) ;
goto V_171;
}
V_116 = F_100 ( V_160 , V_172 , 0 ) ;
if ( V_116 ) {
F_17 ( & V_22 -> V_51 , L_31 ) ;
goto V_173;
}
return 0 ;
V_173:
F_101 ( V_22 -> V_25 ) ;
V_171:
F_102 ( V_22 -> V_130 ) ;
V_169:
F_103 ( V_160 ) ;
V_165:
F_104 ( & V_22 -> V_51 ) ;
return V_116 ;
}
static int F_105 ( struct V_157 * V_158 )
{
struct V_21 * V_22 = F_106 ( V_158 ) ;
F_94 ( & V_22 -> V_51 , L_32 V_168 ) ;
F_107 ( V_22 -> V_160 ) ;
F_101 ( V_22 -> V_25 ) ;
F_102 ( V_22 -> V_130 ) ;
F_104 ( & V_22 -> V_51 ) ;
return 0 ;
}

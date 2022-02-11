static T_1 F_1 ( T_2 * V_1 , T_2 V_2 )
{
if ( V_2 == 1 )
return * V_1 ;
else if ( V_2 == 2 )
return F_2 ( * ( ( V_3 * ) V_1 ) ) ;
else
return F_3 ( * ( ( V_4 * ) V_1 ) ) ;
}
static int F_4 ( struct V_5 * V_6 , T_1 V_7 , T_1 V_8 , T_1 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_6 ) ;
struct V_12 * V_13 = F_6 ( V_6 ) ;
T_2 V_14 [ V_15 + 1 ] ;
T_2 V_16 = F_7 ( V_8 ) ;
T_2 V_17 = F_8 ( V_8 ) ;
struct V_18 V_19 [ 2 ] ;
T_2 V_20 [ 5 ] ;
int V_21 ;
if ( ! V_11 -> V_22 )
return - V_23 ;
V_19 [ 0 ] . V_24 = V_11 -> V_24 ;
V_19 [ 0 ] . V_25 = 0 ;
V_19 [ 0 ] . V_26 = 5 ;
V_19 [ 0 ] . V_27 = V_20 ;
V_20 [ 0 ] = 5 ;
V_20 [ 1 ] = V_28 ;
V_20 [ 2 ] = V_16 ;
V_20 [ 3 ] = V_17 ;
V_20 [ 4 ] = V_7 ;
V_19 [ 1 ] . V_24 = V_11 -> V_24 ;
V_19 [ 1 ] . V_25 = V_29 ;
V_19 [ 1 ] . V_26 = V_7 + 1 ;
V_19 [ 1 ] . V_27 = V_14 ;
F_9 ( 200 , 300 ) ;
V_21 = F_10 ( V_11 -> V_22 , V_19 , 2 ) ;
if ( V_21 == 2 ) {
* V_9 = F_1 ( & V_14 [ 1 ] , V_7 ) ;
return 0 ;
}
if ( V_13 -> V_30 )
F_11 ( V_6 , L_1 ,
V_7 , V_16 , V_17 , V_21 ) ;
return V_21 < 0 ? V_21 : - V_31 ;
}
int F_12 ( struct V_5 * V_6 , T_1 V_8 , T_2 * V_9 )
{
T_1 V_32 ;
int V_21 ;
if ( F_13 ( V_8 ) != 1 ) {
F_11 ( V_6 , L_2 ) ;
return - V_33 ;
}
V_21 = F_4 ( V_6 , F_13 ( V_8 ) , V_8 , & V_32 ) ;
if ( V_21 )
return V_21 ;
* V_9 = ( T_2 ) V_32 ;
return V_21 ;
}
int F_14 ( struct V_5 * V_6 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_32 ;
int V_21 ;
if ( F_13 ( V_8 ) != 2 ) {
F_11 ( V_6 , L_2 ) ;
return - V_33 ;
}
V_21 = F_4 ( V_6 , F_13 ( V_8 ) , V_8 , & V_32 ) ;
if ( V_21 )
return V_21 ;
* V_9 = ( T_3 ) V_32 ;
return V_21 ;
}
int F_15 ( struct V_5 * V_6 , T_1 V_8 , T_1 * V_9 )
{
if ( F_13 ( V_8 ) != 4 ) {
F_11 ( V_6 , L_2 ) ;
return - V_33 ;
}
return F_4 ( V_6 , F_13 ( V_8 ) , V_8 , V_9 ) ;
}
int F_16 ( struct V_5 * V_6 , T_1 V_8 , T_1 V_9 )
{
struct V_10 * V_11 = F_5 ( V_6 ) ;
struct V_12 * V_13 = F_6 ( V_6 ) ;
T_2 V_20 [ V_15 + 4 ] ;
T_2 V_16 = F_7 ( V_8 ) ;
T_2 V_17 = F_8 ( V_8 ) ;
T_2 V_7 = F_13 ( V_8 ) ;
T_1 * V_27 = ( T_1 * ) & V_20 [ 4 ] ;
struct V_18 V_19 [ 1 ] ;
int V_21 ;
if ( ! V_11 -> V_22 )
return - V_23 ;
if ( V_7 != 1 && V_7 != 2 && V_7 != 4 ) {
F_11 ( V_6 , L_2 ) ;
return - V_33 ;
}
V_19 -> V_24 = V_11 -> V_24 ;
V_19 -> V_25 = 0 ;
V_19 -> V_26 = ( T_3 ) V_7 + 4 ;
V_19 -> V_27 = V_20 ;
V_20 [ 0 ] = V_7 + 4 ;
V_20 [ 1 ] = V_34 ;
V_20 [ 2 ] = V_16 ;
V_20 [ 3 ] = V_17 ;
* V_27 = F_1 ( ( T_2 * ) & V_9 , V_7 ) ;
F_9 ( 200 , 300 ) ;
V_21 = F_10 ( V_11 -> V_22 , V_19 , 1 ) ;
if ( V_21 == 1 )
return 0 ;
if ( V_13 -> V_30 )
F_11 ( V_6 , L_3 ,
V_16 , V_17 , V_21 ) ;
return V_21 < 0 ? V_21 : - V_31 ;
}
int F_17 ( struct V_5 * V_6 , T_1 V_8 , T_1 V_35 , T_1 V_36 ,
int V_37 )
{
int V_38 = V_37 < 0 ? V_39 : V_37 ;
unsigned long V_40 = V_41 + F_18 ( V_38 ) ;
T_2 V_42 ;
do {
int V_21 = F_12 ( V_6 , V_8 , & V_42 ) ;
if ( V_21 < 0 && ! ( V_36 & V_43 ) )
return V_21 ;
if ( ! V_21 && ( V_42 & V_36 & 0xff ) == ( V_35 & 0xff ) )
return 0 ;
F_9 ( 100 , 250 ) ;
} while ( V_38 > 0 && F_19 ( V_40 ) );
return - V_44 ;
}
int F_20 ( struct V_5 * V_6 , T_2 V_8 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
T_2 V_36 = F_21 ( V_13 ) ? V_45 : 0 ;
T_2 V_46 ;
int V_21 ;
V_21 = F_12 ( V_6 , V_47 , & V_46 ) ;
if ( ! V_21 )
V_21 = F_16 ( V_6 , V_48 , V_8 & ~ V_36 ) ;
return V_21 ;
}
int F_22 ( struct V_5 * V_6 , T_2 V_49 , T_1 V_37 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
int V_21 = F_23 ( V_13 -> V_50 ,
F_24 ( & V_13 -> V_51 , - 1 , 0 ) ,
F_18 ( V_37 ) ) ;
if ( V_21 <= 0 )
return V_21 ? V_21 : - V_52 ;
return F_17 ( V_6 , V_47 , V_49 ,
V_43 | V_49 , - 1 ) ;
}
static int F_25 ( struct V_5 * V_6 , T_2 V_53 )
{
int V_21 = F_16 ( V_6 , V_54 , V_53 ) ;
if ( V_21 < 0 )
return V_21 ;
return F_17 ( V_6 , V_54 , V_53 , 0xff ,
V_55 ) ;
}
int F_26 ( struct V_12 * V_13 , T_2 V_53 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
int V_21 = - V_33 ;
T_2 V_8 ;
if ( V_53 < V_56 || V_53 > V_57 )
return V_21 ;
V_21 = F_12 ( V_6 , V_54 , & V_8 ) ;
if ( V_21 || V_8 == V_53 )
return V_21 ;
switch ( V_8 ) {
case V_56 :
V_21 = F_25 ( V_6 , V_58 ) ;
if ( V_53 == V_58 )
break;
if ( ! V_21 )
V_21 = F_25 ( V_6 , V_57 ) ;
break;
case V_58 :
if ( V_53 == V_56 ) {
V_21 = F_25 ( V_6 , V_56 ) ;
break;
}
V_21 = F_25 ( V_6 , V_57 ) ;
break;
case V_57 :
V_21 = F_25 ( V_6 , V_58 ) ;
if ( V_53 == V_58 )
break;
if ( ! V_21 )
V_21 = F_25 ( V_6 , V_56 ) ;
break;
default:
F_27 ( V_6 , L_4 , V_53 ) ;
}
if ( ! V_21 )
V_13 -> V_53 = V_53 ;
return V_21 ;
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
struct V_59 * V_60 = & V_13 -> V_60 ;
T_2 * V_61 = V_60 -> V_61 ;
int V_62 ;
int V_21 ;
V_21 = F_12 ( V_6 , V_63 , & V_60 -> V_64 ) ;
if ( ! V_21 )
V_21 = F_12 ( V_6 , V_65 , & V_60 -> V_66 ) ;
if ( ! V_21 )
V_21 = F_14 ( V_6 , V_67 , & V_60 -> V_68 ) ;
if ( ! V_21 )
V_21 = F_14 ( V_6 , V_69 , & V_60 -> V_70 ) ;
if ( ! V_21 )
V_21 = F_14 ( V_6 , V_71 , & V_60 -> V_72 ) ;
if ( ! V_21 )
V_21 = F_14 ( V_6 , V_73 , & V_60 -> V_74 ) ;
if ( ! V_21 )
V_21 = F_12 ( V_6 , V_75 , & V_60 -> V_76 ) ;
if ( V_21 )
return V_21 ;
for ( V_62 = 0 ; V_62 < V_77 ; V_62 ++ ) {
V_21 = F_12 ( V_6 , V_78 , & V_61 [ V_62 ] ) ;
if ( V_21 )
return V_21 ;
}
F_29 ( V_6 , L_5 ,
F_30 ( V_13 , V_79 ) ?
L_6 :
F_30 ( V_13 , V_80 ) ?
L_7 :
F_30 ( V_13 , V_81 ) ?
L_8 : L_9 ) ;
F_29 ( V_6 , L_10 ,
V_13 -> V_60 . V_64 , V_13 -> V_60 . V_66 ) ;
if ( ! F_21 ( V_13 ) )
F_29 ( V_6 , L_11 ) ;
return V_21 ;
}
static enum V_82 F_31 ( T_1 V_83 )
{
enum V_82 type = V_84 ;
do {
if ( V_83 == V_85 [ type ] . V_83 )
return type ;
} while ( type ++ != V_86 );
return 0 ;
}
static int F_32 ( struct V_5 * V_6 ,
struct V_87 * V_88 ,
enum V_82 * type ,
T_1 * V_89 )
{
const struct V_90 * V_91 = & V_92 [ 0 ] ;
const struct V_90 * V_93 = NULL ;
enum V_82 V_94 = F_31 ( V_88 -> V_83 ) ;
int V_62 = F_33 ( V_92 ) ;
unsigned int V_95 = ~ 0 ;
while ( V_62 -- ) {
int V_96 ;
if ( V_94 == V_91 -> type ) {
V_96 = abs ( V_91 -> V_97 - V_88 -> V_97 )
+ abs ( V_91 -> V_98 - V_88 -> V_98 ) ;
if ( V_96 < V_95 ) {
V_95 = V_96 ;
V_93 = V_91 ;
}
}
V_91 ++ ;
}
if ( V_93 ) {
V_88 -> V_97 = V_93 -> V_97 ;
V_88 -> V_98 = V_93 -> V_98 ;
* V_89 = V_93 -> V_8 ;
* type = V_94 ;
return 0 ;
}
return - V_33 ;
}
static struct V_87 * F_34 ( struct V_12 * V_13 ,
struct V_99 * V_100 ,
enum V_101 V_102 ,
enum V_82 type )
{
if ( V_102 == V_103 )
return V_100 ? F_35 ( & V_13 -> V_6 , V_100 , 0 ) : NULL ;
return & V_13 -> V_104 [ type ] ;
}
static int F_36 ( struct V_5 * V_6 , struct V_99 * V_100 ,
struct V_105 * V_106 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
struct V_87 * V_107 ;
int V_21 = 0 ;
F_37 ( & V_13 -> V_108 ) ;
V_107 = F_34 ( V_13 , V_100 , V_106 -> V_102 , V_13 -> V_109 ) ;
if ( V_107 )
V_106 -> V_107 = * V_107 ;
else
V_21 = - V_33 ;
F_38 ( & V_13 -> V_108 ) ;
return V_21 ;
}
static int F_39 ( struct V_5 * V_6 , struct V_99 * V_100 ,
struct V_105 * V_106 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
struct V_87 * V_107 = & V_106 -> V_107 ;
struct V_87 * V_110 ;
enum V_82 type ;
T_1 V_89 = 0 ;
int V_21 ;
V_21 = F_32 ( V_6 , V_107 , & type , & V_89 ) ;
if ( V_21 < 0 )
return V_21 ;
V_110 = F_34 ( V_13 , V_100 , V_106 -> V_102 , type ) ;
if ( ! V_110 )
return 0 ;
F_37 ( & V_13 -> V_108 ) ;
V_107 -> V_83 = V_85 [ type ] . V_83 ;
V_107 -> V_111 = V_112 ;
V_107 -> V_113 = V_114 ;
if ( V_106 -> V_102 == V_115 ) {
* V_110 = * V_107 ;
V_13 -> V_89 = V_89 ;
V_13 -> V_109 = type ;
}
F_38 ( & V_13 -> V_108 ) ;
return V_21 ;
}
static int F_40 ( struct V_5 * V_6 , unsigned int V_116 ,
struct V_117 * V_118 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
if ( V_116 != 0 || V_118 == NULL )
return - V_33 ;
F_37 ( & V_13 -> V_108 ) ;
V_118 -> V_119 [ 0 ] . V_2 = V_13 -> V_120 . V_121 ;
V_118 -> V_119 [ 0 ] . V_122 = V_13 -> V_104 [ V_123 ] . V_83 ;
F_38 ( & V_13 -> V_108 ) ;
V_118 -> V_119 [ 0 ] . V_25 = V_124 ;
V_118 -> V_125 = 1 ;
return 0 ;
}
static int F_41 ( struct V_5 * V_6 , unsigned int V_116 ,
struct V_117 * V_118 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
struct V_87 * V_88 = & V_13 -> V_104 [ V_123 ] ;
if ( V_116 != 0 || V_118 == NULL )
return - V_33 ;
V_118 -> V_119 [ 0 ] . V_25 = V_124 ;
V_118 -> V_125 = 1 ;
V_118 -> V_119 [ 0 ] . V_2 = F_42 ( T_1 , V_118 -> V_119 [ 0 ] . V_2 ,
V_88 -> V_97 * V_88 -> V_98 ,
V_126 ) ;
F_37 ( & V_13 -> V_108 ) ;
V_13 -> V_120 . V_121 = V_118 -> V_119 [ 0 ] . V_2 ;
F_38 ( & V_13 -> V_108 ) ;
return 0 ;
}
static int F_43 ( struct V_5 * V_6 ,
struct V_99 * V_100 ,
struct V_127 * V_83 )
{
if ( ! V_83 || V_83 -> V_128 >= V_86 )
return - V_33 ;
V_83 -> V_83 = V_85 [ V_83 -> V_128 ] . V_83 ;
return 0 ;
}
int F_44 ( struct V_12 * V_13 )
{
int V_21 ;
if ( V_13 -> V_129 )
return 0 ;
V_21 = F_45 ( V_13 , V_130 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_46 ( & V_13 -> V_131 ) ;
V_13 -> V_129 = ! V_21 ;
return V_21 ;
}
static int F_47 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
int V_21 ;
V_21 = F_26 ( V_13 , V_56 ) ;
if ( ! V_21 )
V_21 = F_16 ( V_6 , V_132 , V_13 -> V_89 ) ;
if ( ! V_21 )
V_21 = F_16 ( V_6 , V_133 , V_134 ) ;
if ( ! V_21 )
V_21 = F_26 ( V_13 , V_58 ) ;
if ( ! V_21 )
V_21 = F_44 ( V_13 ) ;
return V_21 ;
}
static int F_48 ( struct V_5 * V_6 , int V_135 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
T_1 V_83 ;
int V_21 ;
F_37 ( & V_13 -> V_108 ) ;
V_83 = V_13 -> V_104 [ V_13 -> V_109 ] . V_83 ;
if ( V_135 ) {
if ( F_49 ( V_83 , V_84 ) )
V_21 = F_47 ( V_13 ) ;
else if ( F_49 ( V_83 , V_123 ) )
V_21 = F_50 ( V_13 ) ;
else
V_21 = - V_33 ;
} else {
V_21 = F_26 ( V_13 , V_56 ) ;
}
F_38 ( & V_13 -> V_108 ) ;
return V_21 ;
}
static int F_51 ( struct V_12 * V_13 , bool V_135 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
struct V_10 * V_11 = F_5 ( V_6 ) ;
const struct V_136 * V_137 = V_13 -> V_137 ;
int V_21 ;
if ( V_13 -> V_138 == V_135 )
return 0 ;
if ( V_135 ) {
if ( V_13 -> V_139 ) {
V_21 = V_13 -> V_139 ( & V_11 -> V_140 , 1 ) ;
if ( V_21 )
return V_21 ;
}
V_21 = F_52 ( F_33 ( V_141 ) , V_141 ) ;
if ( V_21 ) {
V_13 -> V_139 ( & V_11 -> V_140 , 0 ) ;
return V_21 ;
}
F_53 ( V_137 -> V_142 , ! V_137 -> V_143 ) ;
V_13 -> V_138 = 1 ;
return V_21 ;
}
V_21 = F_54 ( F_33 ( V_141 ) , V_141 ) ;
if ( V_21 )
return V_21 ;
if ( V_13 -> V_139 )
V_13 -> V_139 ( & V_11 -> V_140 , 0 ) ;
F_53 ( V_137 -> V_142 , V_137 -> V_143 ) ;
V_13 -> V_30 = 0 ;
V_13 -> V_138 = 0 ;
return V_21 ;
}
static int F_55 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
int V_21 ;
F_56 ( & V_13 -> V_51 , 0 ) ;
V_21 = F_17 ( V_6 , V_144 , V_145 ,
V_43 | 0xff , - 1 ) ;
if ( ! V_21 )
V_21 = F_16 ( V_6 , V_144 , V_146 ) ;
if ( ! V_21 )
V_21 = F_22 ( V_6 , V_147 , 2000 ) ;
if ( V_21 < 0 )
return V_21 ;
V_13 -> V_30 = 1 ;
V_21 = F_28 ( V_6 ) ;
if ( ! V_21 )
V_21 = F_57 ( V_6 , F_51 ) ;
if ( V_21 )
return V_21 ;
F_58 ( 1 , V_148 , V_6 , L_12 ) ;
V_21 = F_16 ( V_6 , V_149 , V_150 ) ;
if ( ! V_21 )
V_21 = F_20 ( V_6 ,
V_45 | V_151 ) ;
return V_21 ;
}
static int F_59 ( struct V_12 * V_13 )
{
int V_21 ;
V_21 = F_16 ( & V_13 -> V_6 , V_152 , V_153 ) ;
if ( ! V_21 )
V_21 = F_16 ( & V_13 -> V_6 , V_154 , V_155 ) ;
if ( ! V_21 )
V_21 = F_17 ( & V_13 -> V_6 , V_156 , V_157 ,
0xff , - 1 ) ;
return V_21 ;
}
static int F_60 ( struct V_5 * V_6 , int V_158 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
int V_21 ;
F_37 ( & V_13 -> V_108 ) ;
if ( V_158 ) {
V_21 = F_51 ( V_13 , true ) ;
if ( ! V_21 )
V_21 = F_55 ( V_6 ) ;
} else {
if ( F_30 ( V_13 , V_81 ) ) {
V_21 = F_26 ( V_13 , V_58 ) ;
if ( ! V_21 )
V_21 = F_59 ( V_13 ) ;
if ( V_21 < 0 )
F_27 ( V_6 , L_13 ) ;
}
V_21 = F_51 ( V_13 , false ) ;
V_13 -> V_129 = 0 ;
}
F_38 ( & V_13 -> V_108 ) ;
return V_21 ;
}
static int F_61 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
F_62 ( & V_13 -> V_131 , V_6 -> V_159 ) ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 , struct V_160 * V_161 )
{
struct V_87 * V_107 = F_35 ( V_6 , V_161 -> V_116 , 0 ) ;
* V_107 = V_85 [ 0 ] ;
return 0 ;
}
static T_4 F_64 ( int V_162 , void * V_1 )
{
struct V_12 * V_13 = F_6 ( V_1 ) ;
F_56 ( & V_13 -> V_51 , 1 ) ;
F_65 ( & V_13 -> V_50 ) ;
return V_163 ;
}
static int F_66 ( struct V_10 * V_11 ,
const struct V_164 * V_165 )
{
const struct V_136 * V_137 = V_11 -> V_140 . V_166 ;
unsigned long V_167 ;
struct V_12 * V_13 ;
struct V_5 * V_6 ;
int V_21 ;
if ( V_137 == NULL ) {
F_67 ( & V_11 -> V_140 , L_14 ) ;
return - V_33 ;
}
if ( ! F_68 ( V_137 -> V_142 ) ) {
F_67 ( & V_11 -> V_140 , L_15 ) ;
return - V_33 ;
}
if ( ! V_11 -> V_162 ) {
F_67 ( & V_11 -> V_140 , L_16 ) ;
return - V_33 ;
}
V_13 = F_69 ( & V_11 -> V_140 , sizeof( * V_13 ) , V_168 ) ;
if ( ! V_13 )
return - V_169 ;
V_13 -> V_137 = V_137 ;
V_13 -> V_139 = V_137 -> V_139 ;
V_167 = V_137 -> V_143
? V_170 : V_171 ;
V_21 = F_70 ( & V_11 -> V_140 , V_137 -> V_142 , V_167 ,
L_17 ) ;
if ( V_21 ) {
F_67 ( & V_11 -> V_140 , L_18 , V_21 ) ;
return V_21 ;
}
V_21 = F_71 ( & V_11 -> V_140 , F_33 ( V_141 ) ,
V_141 ) ;
if ( V_21 ) {
F_67 ( & V_11 -> V_140 , L_19 , V_21 ) ;
return V_21 ;
}
V_6 = & V_13 -> V_6 ;
F_72 ( V_6 , V_11 , & V_172 ) ;
F_73 ( V_6 -> V_159 , V_173 , sizeof( V_6 -> V_159 ) ) ;
V_6 -> V_25 |= V_174 ;
V_6 -> V_175 = & V_176 ;
V_13 -> V_116 . V_25 = V_177 ;
V_21 = F_74 ( & V_6 -> V_178 , 1 , & V_13 -> V_116 ) ;
if ( V_21 < 0 )
return V_21 ;
V_6 -> V_178 . V_179 = V_180 ;
F_75 ( & V_13 -> V_50 ) ;
F_76 ( & V_13 -> V_108 ) ;
V_21 = F_77 ( & V_11 -> V_140 , V_11 -> V_162 , F_64 ,
V_181 , V_173 , V_6 ) ;
if ( V_21 ) {
F_67 ( & V_11 -> V_140 , L_20 , V_21 ) ;
goto error;
}
V_13 -> V_109 = V_84 ;
V_13 -> V_104 [ 0 ] = V_85 [ 0 ] ;
V_13 -> V_104 [ 1 ] = V_85 [ 1 ] ;
V_21 = F_51 ( V_13 , true ) ;
if ( V_21 )
goto error;
V_21 = F_55 ( V_6 ) ;
if ( ! V_21 )
V_21 = F_78 ( V_6 ) ;
V_21 = F_51 ( V_13 , false ) ;
if ( ! V_21 )
return 0 ;
error:
F_79 ( & V_6 -> V_178 ) ;
return V_21 ;
}
static int F_80 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = F_81 ( V_11 ) ;
F_82 ( V_6 ) ;
F_83 ( V_6 -> V_182 ) ;
F_79 ( & V_6 -> V_178 ) ;
return 0 ;
}

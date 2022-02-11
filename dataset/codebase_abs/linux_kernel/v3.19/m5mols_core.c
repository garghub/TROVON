static T_1 F_1 ( T_2 * V_1 , T_2 V_2 )
{
if ( V_2 == 1 )
return * V_1 ;
else if ( V_2 == 2 )
return F_2 ( * ( ( V_3 * ) V_1 ) ) ;
else
return F_3 ( * ( ( T_1 * ) V_1 ) ) ;
}
static int F_4 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 , T_1 * V_8 )
{
struct V_9 * V_10 = F_5 ( V_5 ) ;
struct V_11 * V_12 = F_6 ( V_5 ) ;
T_2 V_13 [ V_14 + 1 ] ;
T_2 V_15 = F_7 ( V_7 ) ;
T_2 V_16 = F_8 ( V_7 ) ;
struct V_17 V_18 [ 2 ] ;
T_2 V_19 [ 5 ] ;
int V_20 ;
if ( ! V_10 -> V_21 )
return - V_22 ;
V_18 [ 0 ] . V_23 = V_10 -> V_23 ;
V_18 [ 0 ] . V_24 = 0 ;
V_18 [ 0 ] . V_25 = 5 ;
V_18 [ 0 ] . V_26 = V_19 ;
V_19 [ 0 ] = 5 ;
V_19 [ 1 ] = V_27 ;
V_19 [ 2 ] = V_15 ;
V_19 [ 3 ] = V_16 ;
V_19 [ 4 ] = V_6 ;
V_18 [ 1 ] . V_23 = V_10 -> V_23 ;
V_18 [ 1 ] . V_24 = V_28 ;
V_18 [ 1 ] . V_25 = V_6 + 1 ;
V_18 [ 1 ] . V_26 = V_13 ;
F_9 ( 200 , 200 ) ;
V_20 = F_10 ( V_10 -> V_21 , V_18 , 2 ) ;
if ( V_20 == 2 ) {
* V_8 = F_1 ( & V_13 [ 1 ] , V_6 ) ;
return 0 ;
}
if ( V_12 -> V_29 )
F_11 ( V_5 , L_1 ,
V_6 , V_15 , V_16 , V_20 ) ;
return V_20 < 0 ? V_20 : - V_30 ;
}
int F_12 ( struct V_4 * V_5 , T_1 V_7 , T_2 * V_8 )
{
T_1 V_31 ;
int V_20 ;
if ( F_13 ( V_7 ) != 1 ) {
F_11 ( V_5 , L_2 ) ;
return - V_32 ;
}
V_20 = F_4 ( V_5 , F_13 ( V_7 ) , V_7 , & V_31 ) ;
if ( V_20 )
return V_20 ;
* V_8 = ( T_2 ) V_31 ;
return V_20 ;
}
int F_14 ( struct V_4 * V_5 , T_1 V_7 , V_3 * V_8 )
{
T_1 V_31 ;
int V_20 ;
if ( F_13 ( V_7 ) != 2 ) {
F_11 ( V_5 , L_2 ) ;
return - V_32 ;
}
V_20 = F_4 ( V_5 , F_13 ( V_7 ) , V_7 , & V_31 ) ;
if ( V_20 )
return V_20 ;
* V_8 = ( V_3 ) V_31 ;
return V_20 ;
}
int F_15 ( struct V_4 * V_5 , T_1 V_7 , T_1 * V_8 )
{
if ( F_13 ( V_7 ) != 4 ) {
F_11 ( V_5 , L_2 ) ;
return - V_32 ;
}
return F_4 ( V_5 , F_13 ( V_7 ) , V_7 , V_8 ) ;
}
int F_16 ( struct V_4 * V_5 , T_1 V_7 , T_1 V_8 )
{
struct V_9 * V_10 = F_5 ( V_5 ) ;
struct V_11 * V_12 = F_6 ( V_5 ) ;
T_2 V_19 [ V_14 + 4 ] ;
T_2 V_15 = F_7 ( V_7 ) ;
T_2 V_16 = F_8 ( V_7 ) ;
T_2 V_6 = F_13 ( V_7 ) ;
T_1 * V_26 = ( T_1 * ) & V_19 [ 4 ] ;
struct V_17 V_18 [ 1 ] ;
int V_20 ;
if ( ! V_10 -> V_21 )
return - V_22 ;
if ( V_6 != 1 && V_6 != 2 && V_6 != 4 ) {
F_11 ( V_5 , L_2 ) ;
return - V_32 ;
}
V_18 -> V_23 = V_10 -> V_23 ;
V_18 -> V_24 = 0 ;
V_18 -> V_25 = ( V_3 ) V_6 + 4 ;
V_18 -> V_26 = V_19 ;
V_19 [ 0 ] = V_6 + 4 ;
V_19 [ 1 ] = V_33 ;
V_19 [ 2 ] = V_15 ;
V_19 [ 3 ] = V_16 ;
* V_26 = F_1 ( ( T_2 * ) & V_8 , V_6 ) ;
F_9 ( 200 , 200 ) ;
V_20 = F_10 ( V_10 -> V_21 , V_18 , 1 ) ;
if ( V_20 == 1 )
return 0 ;
if ( V_12 -> V_29 )
F_11 ( V_5 , L_3 ,
V_15 , V_16 , V_20 ) ;
return V_20 < 0 ? V_20 : - V_30 ;
}
int F_17 ( struct V_4 * V_5 , T_1 V_7 , T_1 V_34 , T_1 V_35 ,
int V_36 )
{
int V_37 = V_36 < 0 ? V_38 : V_36 ;
unsigned long V_39 = V_40 + F_18 ( V_37 ) ;
T_2 V_41 ;
do {
int V_20 = F_12 ( V_5 , V_7 , & V_41 ) ;
if ( V_20 < 0 && ! ( V_35 & V_42 ) )
return V_20 ;
if ( ! V_20 && ( V_41 & V_35 & 0xff ) == ( V_34 & 0xff ) )
return 0 ;
F_9 ( 100 , 250 ) ;
} while ( V_37 > 0 && F_19 ( V_39 ) );
return - V_43 ;
}
int F_20 ( struct V_4 * V_5 , T_2 V_7 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
T_2 V_35 = F_21 ( V_12 ) ? V_44 : 0 ;
T_2 V_45 ;
int V_20 ;
V_20 = F_12 ( V_5 , V_46 , & V_45 ) ;
if ( ! V_20 )
V_20 = F_16 ( V_5 , V_47 , V_7 & ~ V_35 ) ;
return V_20 ;
}
int F_22 ( struct V_4 * V_5 , T_2 V_48 , T_1 V_36 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
int V_20 = F_23 ( V_12 -> V_49 ,
F_24 ( & V_12 -> V_50 , - 1 , 0 ) ,
F_18 ( V_36 ) ) ;
if ( V_20 <= 0 )
return V_20 ? V_20 : - V_51 ;
return F_17 ( V_5 , V_46 , V_48 ,
V_42 | V_48 , - 1 ) ;
}
static int F_25 ( struct V_4 * V_5 , T_2 V_52 )
{
int V_20 = F_16 ( V_5 , V_53 , V_52 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_17 ( V_5 , V_53 , V_52 , 0xff ,
V_54 ) ;
}
int F_26 ( struct V_11 * V_12 , T_2 V_52 )
{
struct V_4 * V_5 = & V_12 -> V_5 ;
int V_20 = - V_32 ;
T_2 V_7 ;
if ( V_52 < V_55 || V_52 > V_56 )
return V_20 ;
V_20 = F_12 ( V_5 , V_53 , & V_7 ) ;
if ( V_20 || V_7 == V_52 )
return V_20 ;
switch ( V_7 ) {
case V_55 :
V_20 = F_25 ( V_5 , V_57 ) ;
if ( V_52 == V_57 )
break;
if ( ! V_20 )
V_20 = F_25 ( V_5 , V_56 ) ;
break;
case V_57 :
if ( V_52 == V_55 ) {
V_20 = F_25 ( V_5 , V_55 ) ;
break;
}
V_20 = F_25 ( V_5 , V_56 ) ;
break;
case V_56 :
V_20 = F_25 ( V_5 , V_57 ) ;
if ( V_52 == V_57 )
break;
if ( ! V_20 )
V_20 = F_25 ( V_5 , V_55 ) ;
break;
default:
F_27 ( V_5 , L_4 , V_52 ) ;
}
if ( ! V_20 )
V_12 -> V_52 = V_52 ;
return V_20 ;
}
static int F_28 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
struct V_58 * V_59 = & V_12 -> V_59 ;
T_2 * V_60 = V_59 -> V_60 ;
int V_61 ;
int V_20 ;
V_20 = F_12 ( V_5 , V_62 , & V_59 -> V_63 ) ;
if ( ! V_20 )
V_20 = F_12 ( V_5 , V_64 , & V_59 -> V_65 ) ;
if ( ! V_20 )
V_20 = F_14 ( V_5 , V_66 , & V_59 -> V_67 ) ;
if ( ! V_20 )
V_20 = F_14 ( V_5 , V_68 , & V_59 -> V_69 ) ;
if ( ! V_20 )
V_20 = F_14 ( V_5 , V_70 , & V_59 -> V_71 ) ;
if ( ! V_20 )
V_20 = F_14 ( V_5 , V_72 , & V_59 -> V_73 ) ;
if ( ! V_20 )
V_20 = F_12 ( V_5 , V_74 , & V_59 -> V_75 ) ;
if ( V_20 )
return V_20 ;
for ( V_61 = 0 ; V_61 < V_76 ; V_61 ++ ) {
V_20 = F_12 ( V_5 , V_77 , & V_60 [ V_61 ] ) ;
if ( V_20 )
return V_20 ;
}
V_59 -> V_67 = F_2 ( V_59 -> V_67 ) ;
V_59 -> V_69 = F_2 ( V_59 -> V_69 ) ;
V_59 -> V_71 = F_2 ( V_59 -> V_71 ) ;
V_59 -> V_73 = F_2 ( V_59 -> V_73 ) ;
F_29 ( V_5 , L_5 ,
F_30 ( V_12 , V_78 ) ?
L_6 :
F_30 ( V_12 , V_79 ) ?
L_7 :
F_30 ( V_12 , V_80 ) ?
L_8 : L_9 ) ;
F_29 ( V_5 , L_10 ,
V_12 -> V_59 . V_63 , V_12 -> V_59 . V_65 ) ;
if ( ! F_21 ( V_12 ) )
F_29 ( V_5 , L_11 ) ;
return V_20 ;
}
static enum V_81 F_31 ( T_1 V_82 )
{
enum V_81 type = V_83 ;
do {
if ( V_82 == V_84 [ type ] . V_82 )
return type ;
} while ( type ++ != V_85 );
return 0 ;
}
static int F_32 ( struct V_4 * V_5 ,
struct V_86 * V_87 ,
enum V_81 * type ,
T_1 * V_88 )
{
const struct V_89 * V_90 = & V_91 [ 0 ] ;
const struct V_89 * V_92 = NULL ;
enum V_81 V_93 = F_31 ( V_87 -> V_82 ) ;
int V_61 = F_33 ( V_91 ) ;
unsigned int V_94 = ~ 0 ;
while ( V_61 -- ) {
int V_95 ;
if ( V_93 == V_90 -> type ) {
V_95 = abs ( V_90 -> V_96 - V_87 -> V_96 )
+ abs ( V_90 -> V_97 - V_87 -> V_97 ) ;
if ( V_95 < V_94 ) {
V_94 = V_95 ;
V_92 = V_90 ;
}
}
V_90 ++ ;
}
if ( V_92 ) {
V_87 -> V_96 = V_92 -> V_96 ;
V_87 -> V_97 = V_92 -> V_97 ;
* V_88 = V_92 -> V_7 ;
* type = V_93 ;
return 0 ;
}
return - V_32 ;
}
static struct V_86 * F_34 ( struct V_11 * V_12 ,
struct V_98 * V_99 ,
enum V_100 V_101 ,
enum V_81 type )
{
if ( V_101 == V_102 )
return V_99 ? F_35 ( V_99 , 0 ) : NULL ;
return & V_12 -> V_103 [ type ] ;
}
static int F_36 ( struct V_4 * V_5 , struct V_98 * V_99 ,
struct V_104 * V_105 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
struct V_86 * V_106 ;
int V_20 = 0 ;
F_37 ( & V_12 -> V_107 ) ;
V_106 = F_34 ( V_12 , V_99 , V_105 -> V_101 , V_12 -> V_108 ) ;
if ( V_106 )
V_105 -> V_106 = * V_106 ;
else
V_20 = - V_32 ;
F_38 ( & V_12 -> V_107 ) ;
return V_20 ;
}
static int F_39 ( struct V_4 * V_5 , struct V_98 * V_99 ,
struct V_104 * V_105 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
struct V_86 * V_106 = & V_105 -> V_106 ;
struct V_86 * V_109 ;
enum V_81 type ;
T_1 V_88 = 0 ;
int V_20 ;
V_20 = F_32 ( V_5 , V_106 , & type , & V_88 ) ;
if ( V_20 < 0 )
return V_20 ;
V_109 = F_34 ( V_12 , V_99 , V_105 -> V_101 , type ) ;
if ( ! V_109 )
return 0 ;
F_37 ( & V_12 -> V_107 ) ;
V_106 -> V_82 = V_84 [ type ] . V_82 ;
V_106 -> V_110 = V_111 ;
V_106 -> V_112 = V_113 ;
if ( V_105 -> V_101 == V_114 ) {
* V_109 = * V_106 ;
V_12 -> V_88 = V_88 ;
V_12 -> V_108 = type ;
}
F_38 ( & V_12 -> V_107 ) ;
return V_20 ;
}
static int F_40 ( struct V_4 * V_5 , unsigned int V_115 ,
struct V_116 * V_117 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
if ( V_115 != 0 || V_117 == NULL )
return - V_32 ;
F_37 ( & V_12 -> V_107 ) ;
V_117 -> V_118 [ 0 ] . V_2 = V_12 -> V_119 . V_120 ;
V_117 -> V_118 [ 0 ] . V_121 = V_12 -> V_103 [ V_122 ] . V_82 ;
F_38 ( & V_12 -> V_107 ) ;
V_117 -> V_118 [ 0 ] . V_24 = V_123 ;
V_117 -> V_124 = 1 ;
return 0 ;
}
static int F_41 ( struct V_4 * V_5 , unsigned int V_115 ,
struct V_116 * V_117 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
struct V_86 * V_87 = & V_12 -> V_103 [ V_122 ] ;
if ( V_115 != 0 || V_117 == NULL )
return - V_32 ;
V_117 -> V_118 [ 0 ] . V_24 = V_123 ;
V_117 -> V_124 = 1 ;
V_117 -> V_118 [ 0 ] . V_2 = F_42 ( T_1 , V_117 -> V_118 [ 0 ] . V_2 ,
V_87 -> V_96 * V_87 -> V_97 ,
V_125 ) ;
F_37 ( & V_12 -> V_107 ) ;
V_12 -> V_119 . V_120 = V_117 -> V_118 [ 0 ] . V_2 ;
F_38 ( & V_12 -> V_107 ) ;
return 0 ;
}
static int F_43 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_126 * V_82 )
{
if ( ! V_82 || V_82 -> V_127 >= V_85 )
return - V_32 ;
V_82 -> V_82 = V_84 [ V_82 -> V_127 ] . V_82 ;
return 0 ;
}
int F_44 ( struct V_11 * V_12 )
{
int V_20 ;
if ( V_12 -> V_128 )
return 0 ;
V_20 = F_45 ( V_12 , V_129 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_46 ( & V_12 -> V_130 ) ;
V_12 -> V_128 = ! V_20 ;
return V_20 ;
}
static int F_47 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = & V_12 -> V_5 ;
int V_20 ;
V_20 = F_26 ( V_12 , V_55 ) ;
if ( ! V_20 )
V_20 = F_16 ( V_5 , V_131 , V_12 -> V_88 ) ;
if ( ! V_20 )
V_20 = F_16 ( V_5 , V_132 , V_133 ) ;
if ( ! V_20 )
V_20 = F_26 ( V_12 , V_57 ) ;
if ( ! V_20 )
V_20 = F_44 ( V_12 ) ;
return V_20 ;
}
static int F_48 ( struct V_4 * V_5 , int V_134 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
T_1 V_82 ;
int V_20 ;
F_37 ( & V_12 -> V_107 ) ;
V_82 = V_12 -> V_103 [ V_12 -> V_108 ] . V_82 ;
if ( V_134 ) {
if ( F_49 ( V_82 , V_83 ) )
V_20 = F_47 ( V_12 ) ;
else if ( F_49 ( V_82 , V_122 ) )
V_20 = F_50 ( V_12 ) ;
else
V_20 = - V_32 ;
} else {
V_20 = F_26 ( V_12 , V_55 ) ;
}
F_38 ( & V_12 -> V_107 ) ;
return V_20 ;
}
static int F_51 ( struct V_11 * V_12 , bool V_134 )
{
struct V_4 * V_5 = & V_12 -> V_5 ;
struct V_9 * V_10 = F_5 ( V_5 ) ;
const struct V_135 * V_136 = V_12 -> V_136 ;
int V_20 ;
if ( V_12 -> V_137 == V_134 )
return 0 ;
if ( V_134 ) {
if ( V_12 -> V_138 ) {
V_20 = V_12 -> V_138 ( & V_10 -> V_139 , 1 ) ;
if ( V_20 )
return V_20 ;
}
V_20 = F_52 ( F_33 ( V_140 ) , V_140 ) ;
if ( V_20 ) {
V_12 -> V_138 ( & V_10 -> V_139 , 0 ) ;
return V_20 ;
}
F_53 ( V_136 -> V_141 , ! V_136 -> V_142 ) ;
V_12 -> V_137 = 1 ;
return V_20 ;
}
V_20 = F_54 ( F_33 ( V_140 ) , V_140 ) ;
if ( V_20 )
return V_20 ;
if ( V_12 -> V_138 )
V_12 -> V_138 ( & V_10 -> V_139 , 0 ) ;
F_53 ( V_136 -> V_141 , V_136 -> V_142 ) ;
V_12 -> V_29 = 0 ;
V_12 -> V_137 = 0 ;
return V_20 ;
}
static int F_55 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
int V_20 ;
F_56 ( & V_12 -> V_50 , 0 ) ;
V_20 = F_17 ( V_5 , V_143 , V_144 ,
V_42 | 0xff , - 1 ) ;
if ( ! V_20 )
V_20 = F_16 ( V_5 , V_143 , V_145 ) ;
if ( ! V_20 )
V_20 = F_22 ( V_5 , V_146 , 2000 ) ;
if ( V_20 < 0 )
return V_20 ;
V_12 -> V_29 = 1 ;
V_20 = F_28 ( V_5 ) ;
if ( ! V_20 )
V_20 = F_57 ( V_5 , F_51 ) ;
if ( V_20 )
return V_20 ;
F_58 ( 1 , V_147 , V_5 , L_12 ) ;
V_20 = F_16 ( V_5 , V_148 , V_149 ) ;
if ( ! V_20 )
V_20 = F_20 ( V_5 ,
V_44 | V_150 ) ;
return V_20 ;
}
static int F_59 ( struct V_11 * V_12 )
{
int V_20 ;
V_20 = F_16 ( & V_12 -> V_5 , V_151 , V_152 ) ;
if ( ! V_20 )
V_20 = F_16 ( & V_12 -> V_5 , V_153 , V_154 ) ;
if ( ! V_20 )
V_20 = F_17 ( & V_12 -> V_5 , V_155 , V_156 ,
0xff , - 1 ) ;
return V_20 ;
}
static int F_60 ( struct V_4 * V_5 , int V_157 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
int V_20 ;
F_37 ( & V_12 -> V_107 ) ;
if ( V_157 ) {
V_20 = F_51 ( V_12 , true ) ;
if ( ! V_20 )
V_20 = F_55 ( V_5 ) ;
} else {
if ( F_30 ( V_12 , V_80 ) ) {
V_20 = F_26 ( V_12 , V_57 ) ;
if ( ! V_20 )
V_20 = F_59 ( V_12 ) ;
if ( V_20 < 0 )
F_27 ( V_5 , L_13 ) ;
}
V_20 = F_51 ( V_12 , false ) ;
V_12 -> V_128 = 0 ;
}
F_38 ( & V_12 -> V_107 ) ;
return V_20 ;
}
static int F_61 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
F_62 ( & V_12 -> V_130 , V_5 -> V_158 ) ;
return 0 ;
}
static int F_63 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
struct V_86 * V_106 = F_35 ( V_99 , 0 ) ;
* V_106 = V_84 [ 0 ] ;
return 0 ;
}
static T_3 F_64 ( int V_159 , void * V_1 )
{
struct V_11 * V_12 = F_6 ( V_1 ) ;
F_56 ( & V_12 -> V_50 , 1 ) ;
F_65 ( & V_12 -> V_49 ) ;
return V_160 ;
}
static int F_66 ( struct V_9 * V_10 ,
const struct V_161 * V_162 )
{
const struct V_135 * V_136 = V_10 -> V_139 . V_163 ;
unsigned long V_164 ;
struct V_11 * V_12 ;
struct V_4 * V_5 ;
int V_20 ;
if ( V_136 == NULL ) {
F_67 ( & V_10 -> V_139 , L_14 ) ;
return - V_32 ;
}
if ( ! F_68 ( V_136 -> V_141 ) ) {
F_67 ( & V_10 -> V_139 , L_15 ) ;
return - V_32 ;
}
if ( ! V_10 -> V_159 ) {
F_67 ( & V_10 -> V_139 , L_16 ) ;
return - V_32 ;
}
V_12 = F_69 ( & V_10 -> V_139 , sizeof( * V_12 ) , V_165 ) ;
if ( ! V_12 )
return - V_166 ;
V_12 -> V_136 = V_136 ;
V_12 -> V_138 = V_136 -> V_138 ;
V_164 = V_136 -> V_142
? V_167 : V_168 ;
V_20 = F_70 ( & V_10 -> V_139 , V_136 -> V_141 , V_164 ,
L_17 ) ;
if ( V_20 ) {
F_67 ( & V_10 -> V_139 , L_18 , V_20 ) ;
return V_20 ;
}
V_20 = F_71 ( & V_10 -> V_139 , F_33 ( V_140 ) ,
V_140 ) ;
if ( V_20 ) {
F_67 ( & V_10 -> V_139 , L_19 , V_20 ) ;
return V_20 ;
}
V_5 = & V_12 -> V_5 ;
F_72 ( V_5 , V_10 , & V_169 ) ;
F_73 ( V_5 -> V_158 , V_170 , sizeof( V_5 -> V_158 ) ) ;
V_5 -> V_24 |= V_171 ;
V_5 -> V_172 = & V_173 ;
V_12 -> V_115 . V_24 = V_174 ;
V_20 = F_74 ( & V_5 -> V_175 , 1 , & V_12 -> V_115 , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
V_5 -> V_175 . type = V_176 ;
F_75 ( & V_12 -> V_49 ) ;
F_76 ( & V_12 -> V_107 ) ;
V_20 = F_77 ( & V_10 -> V_139 , V_10 -> V_159 , F_64 ,
V_177 , V_170 , V_5 ) ;
if ( V_20 ) {
F_67 ( & V_10 -> V_139 , L_20 , V_20 ) ;
goto error;
}
V_12 -> V_108 = V_83 ;
V_12 -> V_103 [ 0 ] = V_84 [ 0 ] ;
V_12 -> V_103 [ 1 ] = V_84 [ 1 ] ;
V_20 = F_51 ( V_12 , true ) ;
if ( V_20 )
goto error;
V_20 = F_55 ( V_5 ) ;
if ( ! V_20 )
V_20 = F_78 ( V_5 ) ;
V_20 = F_51 ( V_12 , false ) ;
if ( ! V_20 )
return 0 ;
error:
F_79 ( & V_5 -> V_175 ) ;
return V_20 ;
}
static int F_80 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = F_81 ( V_10 ) ;
F_82 ( V_5 ) ;
F_83 ( V_5 -> V_178 ) ;
F_79 ( & V_5 -> V_175 ) ;
return 0 ;
}

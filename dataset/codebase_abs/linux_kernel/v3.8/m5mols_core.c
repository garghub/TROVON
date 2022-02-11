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
static enum V_81 F_31 ( enum V_82 V_83 )
{
enum V_81 type = V_84 ;
do {
if ( V_83 == V_85 [ type ] . V_83 )
return type ;
} while ( type ++ != V_86 );
return 0 ;
}
static int F_32 ( struct V_4 * V_5 ,
struct V_87 * V_88 ,
enum V_81 * type ,
T_1 * V_89 )
{
const struct V_90 * V_91 = & V_92 [ 0 ] ;
const struct V_90 * V_93 = NULL ;
enum V_81 V_94 = F_31 ( V_88 -> V_83 ) ;
int V_61 = F_33 ( V_92 ) ;
unsigned int V_95 = ~ 0 ;
while ( V_61 -- ) {
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
* V_89 = V_93 -> V_7 ;
* type = V_94 ;
return 0 ;
}
return - V_32 ;
}
static struct V_87 * F_34 ( struct V_11 * V_12 ,
struct V_99 * V_100 ,
enum V_101 V_102 ,
enum V_81 type )
{
if ( V_102 == V_103 )
return V_100 ? F_35 ( V_100 , 0 ) : NULL ;
return & V_12 -> V_104 [ type ] ;
}
static int F_36 ( struct V_4 * V_5 , struct V_99 * V_100 ,
struct V_105 * V_106 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
struct V_87 * V_107 ;
int V_20 = 0 ;
F_37 ( & V_12 -> V_108 ) ;
V_107 = F_34 ( V_12 , V_100 , V_106 -> V_102 , V_12 -> V_109 ) ;
if ( V_107 )
V_106 -> V_107 = * V_107 ;
else
V_20 = - V_32 ;
F_38 ( & V_12 -> V_108 ) ;
return V_20 ;
}
static int F_39 ( struct V_4 * V_5 , struct V_99 * V_100 ,
struct V_105 * V_106 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
struct V_87 * V_107 = & V_106 -> V_107 ;
struct V_87 * V_110 ;
enum V_81 type ;
T_1 V_89 = 0 ;
int V_20 ;
V_20 = F_32 ( V_5 , V_107 , & type , & V_89 ) ;
if ( V_20 < 0 )
return V_20 ;
V_110 = F_34 ( V_12 , V_100 , V_106 -> V_102 , type ) ;
if ( ! V_110 )
return 0 ;
F_37 ( & V_12 -> V_108 ) ;
V_107 -> V_83 = V_85 [ type ] . V_83 ;
V_107 -> V_111 = V_112 ;
V_107 -> V_113 = V_114 ;
if ( V_106 -> V_102 == V_115 ) {
* V_110 = * V_107 ;
V_12 -> V_89 = V_89 ;
V_12 -> V_109 = type ;
}
F_38 ( & V_12 -> V_108 ) ;
return V_20 ;
}
static int F_40 ( struct V_4 * V_5 , unsigned int V_116 ,
struct V_117 * V_118 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
if ( V_116 != 0 || V_118 == NULL )
return - V_32 ;
F_37 ( & V_12 -> V_108 ) ;
V_118 -> V_119 [ 0 ] . V_2 = V_12 -> V_120 . V_121 ;
V_118 -> V_119 [ 0 ] . V_122 = V_12 -> V_104 [ V_123 ] . V_83 ;
F_38 ( & V_12 -> V_108 ) ;
V_118 -> V_119 [ 0 ] . V_24 = V_124 ;
V_118 -> V_125 = 1 ;
return 0 ;
}
static int F_41 ( struct V_4 * V_5 , unsigned int V_116 ,
struct V_117 * V_118 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
struct V_87 * V_88 = & V_12 -> V_104 [ V_123 ] ;
if ( V_116 != 0 || V_118 == NULL )
return - V_32 ;
V_118 -> V_119 [ 0 ] . V_24 = V_124 ;
V_118 -> V_125 = 1 ;
V_118 -> V_119 [ 0 ] . V_2 = F_42 ( T_1 , V_118 -> V_119 [ 0 ] . V_2 ,
V_88 -> V_97 * V_88 -> V_98 ,
V_126 ) ;
F_37 ( & V_12 -> V_108 ) ;
V_12 -> V_120 . V_121 = V_118 -> V_119 [ 0 ] . V_2 ;
F_38 ( & V_12 -> V_108 ) ;
return 0 ;
}
static int F_43 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_127 * V_83 )
{
if ( ! V_83 || V_83 -> V_128 >= V_86 )
return - V_32 ;
V_83 -> V_83 = V_85 [ V_83 -> V_128 ] . V_83 ;
return 0 ;
}
int F_44 ( struct V_11 * V_12 )
{
int V_20 ;
if ( V_12 -> V_129 )
return 0 ;
V_20 = F_45 ( V_12 , V_130 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_46 ( & V_12 -> V_131 ) ;
V_12 -> V_129 = ! V_20 ;
return V_20 ;
}
static int F_47 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = & V_12 -> V_5 ;
int V_20 ;
V_20 = F_26 ( V_12 , V_55 ) ;
if ( ! V_20 )
V_20 = F_16 ( V_5 , V_132 , V_12 -> V_89 ) ;
if ( ! V_20 )
V_20 = F_16 ( V_5 , V_133 , V_134 ) ;
if ( ! V_20 )
V_20 = F_26 ( V_12 , V_57 ) ;
if ( ! V_20 )
V_20 = F_44 ( V_12 ) ;
return V_20 ;
}
static int F_48 ( struct V_4 * V_5 , int V_135 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
T_1 V_83 ;
int V_20 ;
F_37 ( & V_12 -> V_108 ) ;
V_83 = V_12 -> V_104 [ V_12 -> V_109 ] . V_83 ;
if ( V_135 ) {
if ( F_49 ( V_83 , V_84 ) )
V_20 = F_47 ( V_12 ) ;
if ( F_49 ( V_83 , V_123 ) )
V_20 = F_50 ( V_12 ) ;
else
V_20 = - V_32 ;
} else {
V_20 = F_26 ( V_12 , V_55 ) ;
}
F_38 ( & V_12 -> V_108 ) ;
return V_20 ;
}
static int F_51 ( struct V_11 * V_12 , bool V_135 )
{
struct V_4 * V_5 = & V_12 -> V_5 ;
struct V_9 * V_10 = F_5 ( V_5 ) ;
const struct V_136 * V_137 = V_12 -> V_137 ;
int V_20 ;
if ( V_12 -> V_138 == V_135 )
return 0 ;
if ( V_135 ) {
if ( V_12 -> V_139 ) {
V_20 = V_12 -> V_139 ( & V_10 -> V_140 , 1 ) ;
if ( V_20 )
return V_20 ;
}
V_20 = F_52 ( F_33 ( V_141 ) , V_141 ) ;
if ( V_20 ) {
V_12 -> V_139 ( & V_10 -> V_140 , 0 ) ;
return V_20 ;
}
F_53 ( V_137 -> V_142 , ! V_137 -> V_143 ) ;
V_12 -> V_138 = 1 ;
return V_20 ;
}
V_20 = F_54 ( F_33 ( V_141 ) , V_141 ) ;
if ( V_20 )
return V_20 ;
if ( V_12 -> V_139 )
V_12 -> V_139 ( & V_10 -> V_140 , 0 ) ;
F_53 ( V_137 -> V_142 , V_137 -> V_143 ) ;
V_12 -> V_29 = 0 ;
V_12 -> V_138 = 0 ;
return V_20 ;
}
static int F_55 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
int V_20 ;
F_56 ( & V_12 -> V_50 , 0 ) ;
V_20 = F_17 ( V_5 , V_144 , V_145 ,
V_42 | 0xff , - 1 ) ;
if ( ! V_20 )
V_20 = F_16 ( V_5 , V_144 , V_146 ) ;
if ( ! V_20 )
V_20 = F_22 ( V_5 , V_147 , 2000 ) ;
if ( V_20 < 0 )
return V_20 ;
V_12 -> V_29 = 1 ;
V_20 = F_28 ( V_5 ) ;
if ( ! V_20 )
V_20 = F_57 ( V_5 , F_51 ) ;
if ( V_20 )
return V_20 ;
F_58 ( 1 , V_148 , V_5 , L_12 ) ;
V_20 = F_16 ( V_5 , V_149 , V_150 ) ;
if ( ! V_20 )
V_20 = F_20 ( V_5 ,
V_44 | V_151 ) ;
return V_20 ;
}
static int F_59 ( struct V_11 * V_12 )
{
int V_20 ;
V_20 = F_16 ( & V_12 -> V_5 , V_152 , V_153 ) ;
if ( ! V_20 )
V_20 = F_16 ( & V_12 -> V_5 , V_154 , V_155 ) ;
if ( ! V_20 )
V_20 = F_17 ( & V_12 -> V_5 , V_156 , V_157 ,
0xff , - 1 ) ;
return V_20 ;
}
static int F_60 ( struct V_4 * V_5 , int V_158 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
int V_20 ;
F_37 ( & V_12 -> V_108 ) ;
if ( V_158 ) {
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
V_12 -> V_129 = 0 ;
}
F_38 ( & V_12 -> V_108 ) ;
return V_20 ;
}
static int F_61 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
F_62 ( & V_12 -> V_131 , V_5 -> V_159 ) ;
return 0 ;
}
static int F_63 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
struct V_87 * V_107 = F_35 ( V_100 , 0 ) ;
* V_107 = V_85 [ 0 ] ;
return 0 ;
}
static T_3 F_64 ( int V_160 , void * V_1 )
{
struct V_11 * V_12 = F_6 ( V_1 ) ;
F_56 ( & V_12 -> V_50 , 1 ) ;
F_65 ( & V_12 -> V_49 ) ;
return V_161 ;
}
static int F_66 ( struct V_9 * V_10 ,
const struct V_162 * V_163 )
{
const struct V_136 * V_137 = V_10 -> V_140 . V_164 ;
struct V_11 * V_12 ;
struct V_4 * V_5 ;
int V_20 ;
if ( V_137 == NULL ) {
F_67 ( & V_10 -> V_140 , L_14 ) ;
return - V_32 ;
}
if ( ! F_68 ( V_137 -> V_142 ) ) {
F_67 ( & V_10 -> V_140 , L_15 ) ;
return - V_32 ;
}
if ( ! V_10 -> V_160 ) {
F_67 ( & V_10 -> V_140 , L_16 ) ;
return - V_32 ;
}
V_12 = F_69 ( sizeof( struct V_11 ) , V_165 ) ;
if ( ! V_12 )
return - V_166 ;
V_12 -> V_137 = V_137 ;
V_12 -> V_139 = V_137 -> V_139 ;
V_20 = F_70 ( V_137 -> V_142 , L_17 ) ;
if ( V_20 ) {
F_67 ( & V_10 -> V_140 , L_18 , V_20 ) ;
goto V_167;
}
F_71 ( V_137 -> V_142 , V_137 -> V_143 ) ;
V_20 = F_72 ( & V_10 -> V_140 , F_33 ( V_141 ) , V_141 ) ;
if ( V_20 ) {
F_67 ( & V_10 -> V_140 , L_19 , V_20 ) ;
goto V_168;
}
V_5 = & V_12 -> V_5 ;
F_73 ( V_5 , V_10 , & V_169 ) ;
F_74 ( V_5 -> V_159 , V_170 , sizeof( V_5 -> V_159 ) ) ;
V_5 -> V_24 |= V_171 ;
V_5 -> V_172 = & V_173 ;
V_12 -> V_116 . V_24 = V_174 ;
V_20 = F_75 ( & V_5 -> V_175 , 1 , & V_12 -> V_116 , 0 ) ;
if ( V_20 < 0 )
goto V_176;
V_5 -> V_175 . type = V_177 ;
F_76 ( & V_12 -> V_49 ) ;
F_77 ( & V_12 -> V_108 ) ;
V_20 = F_78 ( V_10 -> V_160 , F_64 ,
V_178 , V_170 , V_5 ) ;
if ( V_20 ) {
F_67 ( & V_10 -> V_140 , L_20 , V_20 ) ;
goto V_179;
}
V_12 -> V_109 = V_84 ;
V_12 -> V_104 [ 0 ] = V_85 [ 0 ] ;
V_12 -> V_104 [ 1 ] = V_85 [ 1 ] ;
V_20 = F_51 ( V_12 , true ) ;
if ( V_20 )
goto V_180;
V_20 = F_55 ( V_5 ) ;
if ( ! V_20 )
V_20 = F_79 ( V_5 ) ;
V_20 = F_51 ( V_12 , false ) ;
if ( ! V_20 )
return 0 ;
V_180:
F_80 ( V_10 -> V_160 , V_5 ) ;
V_179:
F_81 ( & V_5 -> V_175 ) ;
V_176:
F_82 ( F_33 ( V_141 ) , V_141 ) ;
V_168:
F_83 ( V_137 -> V_142 ) ;
V_167:
F_84 ( V_12 ) ;
return V_20 ;
}
static int F_85 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = F_86 ( V_10 ) ;
struct V_11 * V_12 = F_6 ( V_5 ) ;
F_87 ( V_5 ) ;
F_88 ( V_5 -> V_181 ) ;
F_80 ( V_10 -> V_160 , V_5 ) ;
F_82 ( F_33 ( V_141 ) , V_141 ) ;
F_83 ( V_12 -> V_137 -> V_142 ) ;
F_81 ( & V_5 -> V_175 ) ;
F_84 ( V_12 ) ;
return 0 ;
}

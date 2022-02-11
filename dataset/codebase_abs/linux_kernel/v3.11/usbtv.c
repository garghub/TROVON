static int F_1 ( struct V_1 * V_1 )
{
int V_2 ;
int V_3 = F_2 ( V_1 -> V_4 , 0 ) ;
int V_5 ;
static const T_1 V_6 [] [ 2 ] = {
{ V_7 + 0x0008 , 0x0001 } ,
{ V_7 + 0x01d0 , 0x00ff } ,
{ V_7 + 0x01d9 , 0x0002 } ,
{ V_7 + 0x0239 , 0x0040 } ,
{ V_7 + 0x0240 , 0x0000 } ,
{ V_7 + 0x0241 , 0x0000 } ,
{ V_7 + 0x0242 , 0x0002 } ,
{ V_7 + 0x0243 , 0x0080 } ,
{ V_7 + 0x0244 , 0x0012 } ,
{ V_7 + 0x0245 , 0x0090 } ,
{ V_7 + 0x0246 , 0x0000 } ,
{ V_7 + 0x0278 , 0x002d } ,
{ V_7 + 0x0279 , 0x000a } ,
{ V_7 + 0x027a , 0x0032 } ,
{ 0xf890 , 0x000c } ,
{ 0xf894 , 0x0086 } ,
{ V_7 + 0x00ac , 0x00c0 } ,
{ V_7 + 0x00ad , 0x0000 } ,
{ V_7 + 0x00a2 , 0x0012 } ,
{ V_7 + 0x00a3 , 0x00e0 } ,
{ V_7 + 0x00a4 , 0x0028 } ,
{ V_7 + 0x00a5 , 0x0082 } ,
{ V_7 + 0x00a7 , 0x0080 } ,
{ V_7 + 0x0000 , 0x0014 } ,
{ V_7 + 0x0006 , 0x0003 } ,
{ V_7 + 0x0090 , 0x0099 } ,
{ V_7 + 0x0091 , 0x0090 } ,
{ V_7 + 0x0094 , 0x0068 } ,
{ V_7 + 0x0095 , 0x0070 } ,
{ V_7 + 0x009c , 0x0030 } ,
{ V_7 + 0x009d , 0x00c0 } ,
{ V_7 + 0x009e , 0x00e0 } ,
{ V_7 + 0x0019 , 0x0006 } ,
{ V_7 + 0x008c , 0x00ba } ,
{ V_7 + 0x0101 , 0x00ff } ,
{ V_7 + 0x010c , 0x00b3 } ,
{ V_7 + 0x01b2 , 0x0080 } ,
{ V_7 + 0x01b4 , 0x00a0 } ,
{ V_7 + 0x014c , 0x00ff } ,
{ V_7 + 0x014d , 0x00ca } ,
{ V_7 + 0x0113 , 0x0053 } ,
{ V_7 + 0x0119 , 0x008a } ,
{ V_7 + 0x013c , 0x0003 } ,
{ V_7 + 0x0150 , 0x009c } ,
{ V_7 + 0x0151 , 0x0071 } ,
{ V_7 + 0x0152 , 0x00c6 } ,
{ V_7 + 0x0153 , 0x0084 } ,
{ V_7 + 0x0154 , 0x00bc } ,
{ V_7 + 0x0155 , 0x00a0 } ,
{ V_7 + 0x0156 , 0x00a0 } ,
{ V_7 + 0x0157 , 0x009c } ,
{ V_7 + 0x0158 , 0x001f } ,
{ V_7 + 0x0159 , 0x0006 } ,
{ V_7 + 0x015d , 0x0000 } ,
{ V_7 + 0x0284 , 0x0088 } ,
{ V_7 + 0x0003 , 0x0004 } ,
{ V_7 + 0x001a , 0x0079 } ,
{ V_7 + 0x0100 , 0x00d3 } ,
{ V_7 + 0x010e , 0x0068 } ,
{ V_7 + 0x010f , 0x009c } ,
{ V_7 + 0x0112 , 0x00f0 } ,
{ V_7 + 0x0115 , 0x0015 } ,
{ V_7 + 0x0117 , 0x0000 } ,
{ V_7 + 0x0118 , 0x00fc } ,
{ V_7 + 0x012d , 0x0004 } ,
{ V_7 + 0x012f , 0x0008 } ,
{ V_7 + 0x0220 , 0x002e } ,
{ V_7 + 0x0225 , 0x0008 } ,
{ V_7 + 0x024e , 0x0002 } ,
{ V_7 + 0x024f , 0x0001 } ,
{ V_7 + 0x0254 , 0x005f } ,
{ V_7 + 0x025a , 0x0012 } ,
{ V_7 + 0x025b , 0x0001 } ,
{ V_7 + 0x0263 , 0x001c } ,
{ V_7 + 0x0266 , 0x0011 } ,
{ V_7 + 0x0267 , 0x0005 } ,
{ V_7 + 0x024e , 0x0002 } ,
{ V_7 + 0x024f , 0x0002 } ,
} ;
for ( V_5 = 0 ; V_5 < F_3 ( V_6 ) ; V_5 ++ ) {
T_1 V_8 = V_6 [ V_5 ] [ 0 ] ;
T_1 V_9 = V_6 [ V_5 ] [ 1 ] ;
V_2 = F_4 ( V_1 -> V_4 , V_3 , V_10 ,
V_11 | V_12 | V_13 ,
V_9 , V_8 , NULL , 0 , 0 ) ;
if ( V_2 < 0 )
return V_2 ;
}
return 0 ;
}
static void F_5 ( T_2 * V_14 , T_2 * V_15 , int V_16 , int V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < 2 ; V_18 ++ ) {
int V_19 = V_16 * 2 + V_18 ;
int line = V_19 / 3 ;
int V_20 = ( line * 2 + ! V_17 ) * 3 + ( V_19 % 3 ) ;
T_2 * V_21 = & V_14 [ V_20 * V_22 / 2 ] ;
memcpy ( V_21 , V_15 , V_22 / 2 * sizeof( * V_15 ) ) ;
V_15 += V_22 / 2 ;
}
}
static void F_6 ( struct V_1 * V_1 , T_2 * V_23 )
{
int V_24 , V_17 , V_16 ;
T_2 * V_14 ;
struct V_25 * V_26 ;
unsigned long V_27 ;
if ( ! F_7 ( V_23 ) )
return;
V_24 = F_8 ( V_23 ) ;
V_17 = F_9 ( V_23 ) ;
V_16 = F_10 ( V_23 ) ;
if ( V_16 >= V_28 )
return;
if ( V_16 == 0 ) {
V_1 -> V_24 = V_24 ;
V_1 -> V_29 = 0 ;
}
if ( V_1 -> V_24 != V_24 )
return;
F_11 ( & V_1 -> V_30 , V_27 ) ;
if ( F_12 ( & V_1 -> V_31 ) ) {
F_13 ( & V_1 -> V_30 , V_27 ) ;
return;
}
V_26 = F_14 ( & V_1 -> V_31 , struct V_25 , V_32 ) ;
V_14 = F_15 ( & V_26 -> V_33 , 0 ) ;
F_5 ( V_14 , & V_23 [ 1 ] , V_16 , V_17 ) ;
V_1 -> V_29 ++ ;
if ( V_17 && V_16 == V_28 - 1 ) {
int V_34 = F_16 ( & V_26 -> V_33 , 0 ) ;
enum V_35 V_36 = V_1 -> V_29 ==
V_28 ?
V_37 :
V_38 ;
V_26 -> V_33 . V_39 . V_40 = V_41 ;
V_26 -> V_33 . V_39 . V_42 = V_1 -> V_42 ++ ;
F_17 ( & V_26 -> V_33 . V_39 . V_43 ) ;
F_18 ( & V_26 -> V_33 , 0 , V_34 ) ;
F_19 ( & V_26 -> V_33 , V_36 ) ;
F_20 ( & V_26 -> V_32 ) ;
}
F_13 ( & V_1 -> V_30 , V_27 ) ;
}
static void F_21 ( struct V_44 * V_45 )
{
int V_2 ;
int V_5 ;
struct V_1 * V_1 = (struct V_1 * ) V_45 -> V_46 ;
switch ( V_45 -> V_47 ) {
case 0 :
break;
case - V_48 :
case - V_49 :
case - V_50 :
case - V_51 :
return;
default:
F_22 ( V_1 -> V_52 , L_1 ) ;
goto V_53;
}
for ( V_5 = 0 ; V_5 < V_45 -> V_54 ; V_5 ++ ) {
int V_34 = V_45 -> V_55 [ V_5 ] . V_56 ;
unsigned char * V_57 = V_45 -> V_58 +
V_45 -> V_55 [ V_5 ] . V_59 ;
int V_59 ;
for ( V_59 = 0 ; V_60 * V_59 < V_34 ; V_59 ++ )
F_6 ( V_1 ,
( T_2 * ) & V_57 [ V_60 * V_59 ] ) ;
}
V_53:
V_2 = F_23 ( V_45 , V_61 ) ;
if ( V_2 < 0 )
F_22 ( V_1 -> V_52 , L_2 ) ;
}
static struct V_44 * F_24 ( struct V_1 * V_1 )
{
struct V_44 * V_45 ;
int V_34 = V_1 -> V_62 ;
int V_5 ;
V_45 = F_25 ( V_63 , V_64 ) ;
if ( V_45 == NULL )
return NULL ;
V_45 -> V_52 = V_1 -> V_4 ;
V_45 -> V_46 = V_1 ;
V_45 -> V_3 = F_26 ( V_1 -> V_4 , V_65 ) ;
V_45 -> V_66 = 1 ;
V_45 -> V_67 = V_68 ;
V_45 -> V_58 = F_27 ( V_34 * V_63 ,
V_64 ) ;
V_45 -> V_69 = F_21 ;
V_45 -> V_54 = V_63 ;
V_45 -> V_70 = V_34 * V_63 ;
for ( V_5 = 0 ; V_5 < V_63 ; V_5 ++ ) {
V_45 -> V_55 [ V_5 ] . V_59 = V_34 * V_5 ;
V_45 -> V_55 [ V_5 ] . V_71 = V_34 ;
}
return V_45 ;
}
static void F_28 ( struct V_1 * V_1 )
{
int V_5 ;
unsigned long V_27 ;
for ( V_5 = 0 ; V_5 < V_72 ; V_5 ++ ) {
struct V_44 * V_45 = V_1 -> V_73 [ V_5 ] ;
if ( V_45 == NULL )
continue;
F_29 ( V_45 ) ;
F_30 ( V_45 -> V_58 ) ;
F_31 ( V_45 ) ;
V_1 -> V_73 [ V_5 ] = NULL ;
}
F_11 ( & V_1 -> V_30 , V_27 ) ;
while ( ! F_12 ( & V_1 -> V_31 ) ) {
struct V_25 * V_26 = F_14 ( & V_1 -> V_31 ,
struct V_25 , V_32 ) ;
F_19 ( & V_26 -> V_33 , V_38 ) ;
F_20 ( & V_26 -> V_32 ) ;
}
F_13 ( & V_1 -> V_30 , V_27 ) ;
}
static int F_32 ( struct V_1 * V_1 )
{
int V_5 ;
int V_2 ;
V_2 = F_33 ( V_1 -> V_4 , 0 , 0 ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_1 ( V_1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_33 ( V_1 -> V_4 , 0 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
for ( V_5 = 0 ; V_5 < V_72 ; V_5 ++ ) {
struct V_44 * V_45 ;
V_45 = F_24 ( V_1 ) ;
if ( V_45 == NULL ) {
V_2 = - V_74 ;
goto V_75;
}
V_1 -> V_73 [ V_5 ] = V_45 ;
V_2 = F_23 ( V_45 , V_64 ) ;
if ( V_2 < 0 )
goto V_75;
}
return 0 ;
V_75:
F_28 ( V_1 ) ;
return V_2 ;
}
static int F_34 ( struct V_76 * V_76 , void * V_77 ,
struct V_78 * V_79 )
{
struct V_1 * V_52 = F_35 ( V_76 ) ;
F_36 ( V_79 -> V_80 , L_3 , sizeof( V_79 -> V_80 ) ) ;
F_36 ( V_79 -> V_81 , L_3 , sizeof( V_79 -> V_81 ) ) ;
F_37 ( V_52 -> V_4 , V_79 -> V_82 , sizeof( V_79 -> V_82 ) ) ;
V_79 -> V_83 = V_84 ;
V_79 -> V_83 |= V_85 | V_86 ;
V_79 -> V_87 = V_79 -> V_83 | V_88 ;
return 0 ;
}
static int F_38 ( struct V_76 * V_76 , void * V_77 ,
struct V_89 * V_5 )
{
if ( V_5 -> V_8 > 0 )
return - V_90 ;
F_36 ( V_5 -> V_91 , L_4 , sizeof( V_5 -> V_91 ) ) ;
V_5 -> type = V_92 ;
V_5 -> V_93 = V_94 ;
return 0 ;
}
static int F_39 ( struct V_76 * V_76 , void * V_77 ,
struct V_95 * V_96 )
{
if ( V_96 -> V_8 > 0 )
return - V_90 ;
F_36 ( V_96 -> V_97 , L_5 ,
sizeof( V_96 -> V_97 ) ) ;
V_96 -> V_98 = V_99 ;
return 0 ;
}
static int F_40 ( struct V_76 * V_76 , void * V_77 ,
struct V_100 * V_96 )
{
V_96 -> V_101 . V_102 . V_103 = V_104 ;
V_96 -> V_101 . V_102 . V_105 = V_106 ;
V_96 -> V_101 . V_102 . V_98 = V_99 ;
V_96 -> V_101 . V_102 . V_40 = V_41 ;
V_96 -> V_101 . V_102 . V_107 = V_104 * 2 ;
V_96 -> V_101 . V_102 . V_108 = ( V_96 -> V_101 . V_102 . V_107 * V_96 -> V_101 . V_102 . V_105 ) ;
V_96 -> V_101 . V_102 . V_109 = V_110 ;
V_96 -> V_101 . V_102 . V_77 = 0 ;
return 0 ;
}
static int F_41 ( struct V_76 * V_76 , void * V_77 , T_3 * V_111 )
{
* V_111 = V_94 ;
return 0 ;
}
static int F_42 ( struct V_76 * V_76 , void * V_77 , unsigned int * V_5 )
{
* V_5 = 0 ;
return 0 ;
}
static int F_43 ( struct V_76 * V_76 , void * V_77 , unsigned int V_5 )
{
if ( V_5 > 0 )
return - V_90 ;
return 0 ;
}
static int F_44 ( struct V_76 * V_76 , void * V_77 , T_3 V_111 )
{
if ( V_111 & V_94 )
return 0 ;
return - V_90 ;
}
static int F_45 ( struct V_112 * V_113 ,
const struct V_100 * V_114 , unsigned int * V_115 ,
unsigned int * V_116 , unsigned int V_117 [] , void * V_118 [] )
{
if ( * V_115 < 2 )
* V_115 = 2 ;
* V_116 = 1 ;
V_117 [ 0 ] = V_104 * V_106 / 2 * sizeof( T_2 ) ;
return 0 ;
}
static void F_46 ( struct V_119 * V_33 )
{
struct V_1 * V_1 = F_47 ( V_33 -> V_112 ) ;
struct V_25 * V_26 = F_48 ( V_33 , struct V_25 , V_33 ) ;
unsigned long V_27 ;
if ( V_1 -> V_4 == NULL ) {
F_19 ( V_33 , V_38 ) ;
return;
}
F_11 ( & V_1 -> V_30 , V_27 ) ;
F_49 ( & V_26 -> V_32 , & V_1 -> V_31 ) ;
F_13 ( & V_1 -> V_30 , V_27 ) ;
}
static int F_50 ( struct V_112 * V_113 , unsigned int V_120 )
{
struct V_1 * V_1 = F_47 ( V_113 ) ;
if ( V_1 -> V_4 == NULL )
return - V_48 ;
return F_32 ( V_1 ) ;
}
static int F_51 ( struct V_112 * V_113 )
{
struct V_1 * V_1 = F_47 ( V_113 ) ;
if ( V_1 -> V_4 == NULL )
return - V_48 ;
F_28 ( V_1 ) ;
return 0 ;
}
static void F_52 ( struct V_121 * V_122 )
{
struct V_1 * V_1 = F_48 ( V_122 , struct V_1 , V_122 ) ;
F_53 ( & V_1 -> V_122 ) ;
F_54 ( & V_1 -> V_123 ) ;
F_30 ( V_1 ) ;
}
static int F_55 ( struct V_124 * V_125 ,
const struct V_126 * V_127 )
{
int V_2 ;
int V_34 ;
struct V_128 * V_52 = & V_125 -> V_52 ;
struct V_1 * V_1 ;
if ( V_125 -> V_129 != 2 )
return - V_48 ;
if ( V_125 -> V_130 [ 1 ] . V_131 . V_132 != 4 )
return - V_48 ;
V_34 = F_56 ( & V_125 -> V_130 [ 1 ] . V_133 [ 0 ] . V_131 ) ;
V_34 = ( V_34 & 0x07ff ) * ( ( ( V_34 & 0x1800 ) >> 11 ) + 1 ) ;
V_1 = F_27 ( sizeof( struct V_1 ) , V_64 ) ;
if ( V_1 == NULL )
return - V_74 ;
V_1 -> V_52 = V_52 ;
V_1 -> V_4 = F_57 ( F_58 ( V_125 ) ) ;
V_1 -> V_62 = V_34 ;
F_59 ( & V_1 -> V_30 ) ;
F_60 ( & V_1 -> V_134 ) ;
F_60 ( & V_1 -> V_135 ) ;
F_61 ( & V_1 -> V_31 ) ;
V_1 -> V_123 . type = V_136 ;
V_1 -> V_123 . V_137 = V_138 | V_139 | V_140 ;
V_1 -> V_123 . V_141 = V_1 ;
V_1 -> V_123 . V_142 = sizeof( struct V_25 ) ;
V_1 -> V_123 . V_143 = & V_144 ;
V_1 -> V_123 . V_145 = & V_146 ;
V_1 -> V_123 . V_147 = V_148 ;
V_1 -> V_123 . V_149 = & V_1 -> V_135 ;
V_2 = F_62 ( & V_1 -> V_123 ) ;
if ( V_2 < 0 ) {
F_22 ( V_52 , L_6 ) ;
goto V_150;
}
V_1 -> V_122 . V_151 = F_52 ;
V_2 = F_63 ( V_52 , & V_1 -> V_122 ) ;
if ( V_2 < 0 ) {
F_22 ( V_52 , L_7 ) ;
goto V_152;
}
F_64 ( V_125 , V_1 ) ;
F_36 ( V_1 -> V_153 . V_91 , L_3 , sizeof( V_1 -> V_153 . V_91 ) ) ;
V_1 -> V_153 . V_122 = & V_1 -> V_122 ;
V_1 -> V_153 . V_151 = V_154 ;
V_1 -> V_153 . V_155 = & V_156 ;
V_1 -> V_153 . V_157 = & V_158 ;
V_1 -> V_153 . V_159 = V_94 ;
V_1 -> V_153 . V_160 = & V_1 -> V_123 ;
V_1 -> V_153 . V_149 = & V_1 -> V_134 ;
F_65 ( V_161 , & V_1 -> V_153 . V_27 ) ;
F_66 ( & V_1 -> V_153 , V_1 ) ;
V_2 = F_67 ( & V_1 -> V_153 , V_162 , - 1 ) ;
if ( V_2 < 0 ) {
F_22 ( V_52 , L_8 ) ;
goto V_163;
}
F_68 ( V_52 , L_9 ) ;
return 0 ;
V_163:
F_53 ( & V_1 -> V_122 ) ;
V_152:
F_54 ( & V_1 -> V_123 ) ;
V_150:
F_30 ( V_1 ) ;
return V_2 ;
}
static void F_69 ( struct V_124 * V_125 )
{
struct V_1 * V_1 = F_70 ( V_125 ) ;
F_71 ( & V_1 -> V_135 ) ;
F_71 ( & V_1 -> V_134 ) ;
F_28 ( V_1 ) ;
F_64 ( V_125 , NULL ) ;
F_72 ( & V_1 -> V_153 ) ;
F_73 ( & V_1 -> V_122 ) ;
F_74 ( V_1 -> V_4 ) ;
V_1 -> V_4 = NULL ;
F_75 ( & V_1 -> V_134 ) ;
F_75 ( & V_1 -> V_135 ) ;
F_76 ( & V_1 -> V_122 ) ;
}

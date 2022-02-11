static int F_1 ( struct V_1 * V_1 , const T_1 V_2 [] [ 2 ] , int V_3 )
{
int V_4 ;
int V_5 = F_2 ( V_1 -> V_6 , 0 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
T_1 V_8 = V_2 [ V_7 ] [ 0 ] ;
T_1 V_9 = V_2 [ V_7 ] [ 1 ] ;
V_4 = F_3 ( V_1 -> V_6 , V_5 , V_10 ,
V_11 | V_12 | V_13 ,
V_9 , V_8 , NULL , 0 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , int V_14 )
{
int V_4 ;
static const T_1 V_15 [] [ 2 ] = {
{ V_16 + 0x0105 , 0x0060 } ,
{ V_16 + 0x011f , 0x00f2 } ,
{ V_16 + 0x0127 , 0x0060 } ,
{ V_16 + 0x00ae , 0x0010 } ,
{ V_16 + 0x0284 , 0x00aa } ,
{ V_16 + 0x0239 , 0x0060 } ,
} ;
static const T_1 V_17 [] [ 2 ] = {
{ V_16 + 0x0105 , 0x0010 } ,
{ V_16 + 0x011f , 0x00ff } ,
{ V_16 + 0x0127 , 0x0060 } ,
{ V_16 + 0x00ae , 0x0030 } ,
{ V_16 + 0x0284 , 0x0088 } ,
{ V_16 + 0x0239 , 0x0060 } ,
} ;
switch ( V_14 ) {
case V_18 :
V_4 = F_1 ( V_1 , V_15 , F_5 ( V_15 ) ) ;
break;
case V_19 :
V_4 = F_1 ( V_1 , V_17 , F_5 ( V_17 ) ) ;
break;
default:
V_4 = - V_20 ;
}
if ( ! V_4 )
V_1 -> V_14 = V_14 ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_1 )
{
int V_4 ;
static const T_1 V_21 [] [ 2 ] = {
{ V_16 + 0x0008 , 0x0001 } ,
{ V_16 + 0x01d0 , 0x00ff } ,
{ V_16 + 0x01d9 , 0x0002 } ,
{ V_16 + 0x0239 , 0x0040 } ,
{ V_16 + 0x0240 , 0x0000 } ,
{ V_16 + 0x0241 , 0x0000 } ,
{ V_16 + 0x0242 , 0x0002 } ,
{ V_16 + 0x0243 , 0x0080 } ,
{ V_16 + 0x0244 , 0x0012 } ,
{ V_16 + 0x0245 , 0x0090 } ,
{ V_16 + 0x0246 , 0x0000 } ,
{ V_16 + 0x0278 , 0x002d } ,
{ V_16 + 0x0279 , 0x000a } ,
{ V_16 + 0x027a , 0x0032 } ,
{ 0xf890 , 0x000c } ,
{ 0xf894 , 0x0086 } ,
{ V_16 + 0x00ac , 0x00c0 } ,
{ V_16 + 0x00ad , 0x0000 } ,
{ V_16 + 0x00a2 , 0x0012 } ,
{ V_16 + 0x00a3 , 0x00e0 } ,
{ V_16 + 0x00a4 , 0x0028 } ,
{ V_16 + 0x00a5 , 0x0082 } ,
{ V_16 + 0x00a7 , 0x0080 } ,
{ V_16 + 0x0000 , 0x0014 } ,
{ V_16 + 0x0006 , 0x0003 } ,
{ V_16 + 0x0090 , 0x0099 } ,
{ V_16 + 0x0091 , 0x0090 } ,
{ V_16 + 0x0094 , 0x0068 } ,
{ V_16 + 0x0095 , 0x0070 } ,
{ V_16 + 0x009c , 0x0030 } ,
{ V_16 + 0x009d , 0x00c0 } ,
{ V_16 + 0x009e , 0x00e0 } ,
{ V_16 + 0x0019 , 0x0006 } ,
{ V_16 + 0x008c , 0x00ba } ,
{ V_16 + 0x0101 , 0x00ff } ,
{ V_16 + 0x010c , 0x00b3 } ,
{ V_16 + 0x01b2 , 0x0080 } ,
{ V_16 + 0x01b4 , 0x00a0 } ,
{ V_16 + 0x014c , 0x00ff } ,
{ V_16 + 0x014d , 0x00ca } ,
{ V_16 + 0x0113 , 0x0053 } ,
{ V_16 + 0x0119 , 0x008a } ,
{ V_16 + 0x013c , 0x0003 } ,
{ V_16 + 0x0150 , 0x009c } ,
{ V_16 + 0x0151 , 0x0071 } ,
{ V_16 + 0x0152 , 0x00c6 } ,
{ V_16 + 0x0153 , 0x0084 } ,
{ V_16 + 0x0154 , 0x00bc } ,
{ V_16 + 0x0155 , 0x00a0 } ,
{ V_16 + 0x0156 , 0x00a0 } ,
{ V_16 + 0x0157 , 0x009c } ,
{ V_16 + 0x0158 , 0x001f } ,
{ V_16 + 0x0159 , 0x0006 } ,
{ V_16 + 0x015d , 0x0000 } ,
{ V_16 + 0x0284 , 0x0088 } ,
{ V_16 + 0x0003 , 0x0004 } ,
{ V_16 + 0x001a , 0x0079 } ,
{ V_16 + 0x0100 , 0x00d3 } ,
{ V_16 + 0x010e , 0x0068 } ,
{ V_16 + 0x010f , 0x009c } ,
{ V_16 + 0x0112 , 0x00f0 } ,
{ V_16 + 0x0115 , 0x0015 } ,
{ V_16 + 0x0117 , 0x0000 } ,
{ V_16 + 0x0118 , 0x00fc } ,
{ V_16 + 0x012d , 0x0004 } ,
{ V_16 + 0x012f , 0x0008 } ,
{ V_16 + 0x0220 , 0x002e } ,
{ V_16 + 0x0225 , 0x0008 } ,
{ V_16 + 0x024e , 0x0002 } ,
{ V_16 + 0x024f , 0x0001 } ,
{ V_16 + 0x0254 , 0x005f } ,
{ V_16 + 0x025a , 0x0012 } ,
{ V_16 + 0x025b , 0x0001 } ,
{ V_16 + 0x0263 , 0x001c } ,
{ V_16 + 0x0266 , 0x0011 } ,
{ V_16 + 0x0267 , 0x0005 } ,
{ V_16 + 0x024e , 0x0002 } ,
{ V_16 + 0x024f , 0x0002 } ,
} ;
V_4 = F_1 ( V_1 , V_21 , F_5 ( V_21 ) ) ;
if ( V_4 )
return V_4 ;
V_4 = F_4 ( V_1 , V_1 -> V_14 ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
static void F_7 ( T_2 * V_22 , T_2 * V_23 , int V_24 , int V_25 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
int V_27 = V_24 * 2 + V_26 ;
int line = V_27 / 3 ;
int V_28 = ( line * 2 + ! V_25 ) * 3 + ( V_27 % 3 ) ;
T_2 * V_29 = & V_22 [ V_28 * V_30 / 2 ] ;
memcpy ( V_29 , V_23 , V_30 / 2 * sizeof( * V_23 ) ) ;
V_23 += V_30 / 2 ;
}
}
static void F_8 ( struct V_1 * V_1 , T_2 * V_31 )
{
int V_32 , V_25 , V_24 ;
T_2 * V_22 ;
struct V_33 * V_34 ;
unsigned long V_35 ;
if ( ! F_9 ( V_31 ) )
return;
V_32 = F_10 ( V_31 ) ;
V_25 = F_11 ( V_31 ) ;
V_24 = F_12 ( V_31 ) ;
if ( V_24 >= V_36 )
return;
if ( V_24 == 0 ) {
V_1 -> V_32 = V_32 ;
V_1 -> V_37 = 0 ;
}
if ( V_1 -> V_32 != V_32 )
return;
F_13 ( & V_1 -> V_38 , V_35 ) ;
if ( F_14 ( & V_1 -> V_39 ) ) {
F_15 ( & V_1 -> V_38 , V_35 ) ;
return;
}
V_34 = F_16 ( & V_1 -> V_39 , struct V_33 , V_40 ) ;
V_22 = F_17 ( & V_34 -> V_41 , 0 ) ;
F_7 ( V_22 , & V_31 [ 1 ] , V_24 , V_25 ) ;
V_1 -> V_37 ++ ;
if ( V_25 && V_24 == V_36 - 1 ) {
int V_3 = F_18 ( & V_34 -> V_41 , 0 ) ;
enum V_42 V_43 = V_1 -> V_37 ==
V_36 ?
V_44 :
V_45 ;
V_34 -> V_41 . V_46 . V_47 = V_48 ;
V_34 -> V_41 . V_46 . V_49 = V_1 -> V_49 ++ ;
F_19 ( & V_34 -> V_41 . V_46 . V_50 ) ;
F_20 ( & V_34 -> V_41 , 0 , V_3 ) ;
F_21 ( & V_34 -> V_41 , V_43 ) ;
F_22 ( & V_34 -> V_40 ) ;
}
F_15 ( & V_1 -> V_38 , V_35 ) ;
}
static void F_23 ( struct V_51 * V_52 )
{
int V_4 ;
int V_7 ;
struct V_1 * V_1 = (struct V_1 * ) V_52 -> V_53 ;
switch ( V_52 -> V_54 ) {
case 0 :
break;
case - V_55 :
case - V_56 :
case - V_57 :
case - V_58 :
return;
default:
F_24 ( V_1 -> V_59 , L_1 ) ;
goto V_60;
}
for ( V_7 = 0 ; V_7 < V_52 -> V_61 ; V_7 ++ ) {
int V_3 = V_52 -> V_62 [ V_7 ] . V_63 ;
unsigned char * V_64 = V_52 -> V_65 +
V_52 -> V_62 [ V_7 ] . V_66 ;
int V_66 ;
for ( V_66 = 0 ; V_67 * V_66 < V_3 ; V_66 ++ )
F_8 ( V_1 ,
( T_2 * ) & V_64 [ V_67 * V_66 ] ) ;
}
V_60:
V_4 = F_25 ( V_52 , V_68 ) ;
if ( V_4 < 0 )
F_24 ( V_1 -> V_59 , L_2 ) ;
}
static struct V_51 * F_26 ( struct V_1 * V_1 )
{
struct V_51 * V_52 ;
int V_3 = V_1 -> V_69 ;
int V_7 ;
V_52 = F_27 ( V_70 , V_71 ) ;
if ( V_52 == NULL )
return NULL ;
V_52 -> V_59 = V_1 -> V_6 ;
V_52 -> V_53 = V_1 ;
V_52 -> V_5 = F_28 ( V_1 -> V_6 , V_72 ) ;
V_52 -> V_73 = 1 ;
V_52 -> V_74 = V_75 ;
V_52 -> V_65 = F_29 ( V_3 * V_70 ,
V_71 ) ;
V_52 -> V_76 = F_23 ;
V_52 -> V_61 = V_70 ;
V_52 -> V_77 = V_3 * V_70 ;
for ( V_7 = 0 ; V_7 < V_70 ; V_7 ++ ) {
V_52 -> V_62 [ V_7 ] . V_66 = V_3 * V_7 ;
V_52 -> V_62 [ V_7 ] . V_78 = V_3 ;
}
return V_52 ;
}
static void F_30 ( struct V_1 * V_1 )
{
int V_7 ;
unsigned long V_35 ;
for ( V_7 = 0 ; V_7 < V_79 ; V_7 ++ ) {
struct V_51 * V_52 = V_1 -> V_80 [ V_7 ] ;
if ( V_52 == NULL )
continue;
F_31 ( V_52 ) ;
F_32 ( V_52 -> V_65 ) ;
F_33 ( V_52 ) ;
V_1 -> V_80 [ V_7 ] = NULL ;
}
F_13 ( & V_1 -> V_38 , V_35 ) ;
while ( ! F_14 ( & V_1 -> V_39 ) ) {
struct V_33 * V_34 = F_16 ( & V_1 -> V_39 ,
struct V_33 , V_40 ) ;
F_21 ( & V_34 -> V_41 , V_45 ) ;
F_22 ( & V_34 -> V_40 ) ;
}
F_15 ( & V_1 -> V_38 , V_35 ) ;
}
static int F_34 ( struct V_1 * V_1 )
{
int V_7 ;
int V_4 ;
V_4 = F_35 ( V_1 -> V_6 , 0 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_6 ( V_1 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_35 ( V_1 -> V_6 , 0 , 1 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_7 = 0 ; V_7 < V_79 ; V_7 ++ ) {
struct V_51 * V_52 ;
V_52 = F_26 ( V_1 ) ;
if ( V_52 == NULL ) {
V_4 = - V_81 ;
goto V_82;
}
V_1 -> V_80 [ V_7 ] = V_52 ;
V_4 = F_25 ( V_52 , V_71 ) ;
if ( V_4 < 0 )
goto V_82;
}
return 0 ;
V_82:
F_30 ( V_1 ) ;
return V_4 ;
}
static int F_36 ( struct V_83 * V_83 , void * V_84 ,
struct V_85 * V_86 )
{
struct V_1 * V_59 = F_37 ( V_83 ) ;
F_38 ( V_86 -> V_87 , L_3 , sizeof( V_86 -> V_87 ) ) ;
F_38 ( V_86 -> V_88 , L_3 , sizeof( V_86 -> V_88 ) ) ;
F_39 ( V_59 -> V_6 , V_86 -> V_89 , sizeof( V_86 -> V_89 ) ) ;
V_86 -> V_90 = V_91 ;
V_86 -> V_90 |= V_92 | V_93 ;
V_86 -> V_94 = V_86 -> V_90 | V_95 ;
return 0 ;
}
static int F_40 ( struct V_83 * V_83 , void * V_84 ,
struct V_96 * V_7 )
{
switch ( V_7 -> V_8 ) {
case V_18 :
F_38 ( V_7 -> V_97 , L_4 , sizeof( V_7 -> V_97 ) ) ;
break;
case V_19 :
F_38 ( V_7 -> V_97 , L_5 , sizeof( V_7 -> V_97 ) ) ;
break;
default:
return - V_20 ;
}
V_7 -> type = V_98 ;
V_7 -> V_99 = V_100 ;
return 0 ;
}
static int F_41 ( struct V_83 * V_83 , void * V_84 ,
struct V_101 * V_102 )
{
if ( V_102 -> V_8 > 0 )
return - V_20 ;
F_38 ( V_102 -> V_103 , L_6 ,
sizeof( V_102 -> V_103 ) ) ;
V_102 -> V_104 = V_105 ;
return 0 ;
}
static int F_42 ( struct V_83 * V_83 , void * V_84 ,
struct V_106 * V_102 )
{
V_102 -> V_107 . V_108 . V_109 = V_110 ;
V_102 -> V_107 . V_108 . V_111 = V_112 ;
V_102 -> V_107 . V_108 . V_104 = V_105 ;
V_102 -> V_107 . V_108 . V_47 = V_48 ;
V_102 -> V_107 . V_108 . V_113 = V_110 * 2 ;
V_102 -> V_107 . V_108 . V_114 = ( V_102 -> V_107 . V_108 . V_113 * V_102 -> V_107 . V_108 . V_111 ) ;
V_102 -> V_107 . V_108 . V_115 = V_116 ;
V_102 -> V_107 . V_108 . V_84 = 0 ;
return 0 ;
}
static int F_43 ( struct V_83 * V_83 , void * V_84 , T_3 * V_117 )
{
* V_117 = V_100 ;
return 0 ;
}
static int F_44 ( struct V_83 * V_83 , void * V_84 , unsigned int * V_7 )
{
struct V_1 * V_1 = F_37 ( V_83 ) ;
* V_7 = V_1 -> V_14 ;
return 0 ;
}
static int F_45 ( struct V_83 * V_83 , void * V_84 , unsigned int V_7 )
{
struct V_1 * V_1 = F_37 ( V_83 ) ;
return F_4 ( V_1 , V_7 ) ;
}
static int F_46 ( struct V_83 * V_83 , void * V_84 , T_3 V_117 )
{
if ( V_117 & V_100 )
return 0 ;
return - V_20 ;
}
static int F_47 ( struct V_118 * V_119 ,
const struct V_106 * V_120 , unsigned int * V_121 ,
unsigned int * V_122 , unsigned int V_123 [] , void * V_124 [] )
{
if ( * V_121 < 2 )
* V_121 = 2 ;
* V_122 = 1 ;
V_123 [ 0 ] = V_110 * V_112 / 2 * sizeof( T_2 ) ;
return 0 ;
}
static void F_48 ( struct V_125 * V_41 )
{
struct V_1 * V_1 = F_49 ( V_41 -> V_118 ) ;
struct V_33 * V_34 = F_50 ( V_41 , struct V_33 , V_41 ) ;
unsigned long V_35 ;
if ( V_1 -> V_6 == NULL ) {
F_21 ( V_41 , V_45 ) ;
return;
}
F_13 ( & V_1 -> V_38 , V_35 ) ;
F_51 ( & V_34 -> V_40 , & V_1 -> V_39 ) ;
F_15 ( & V_1 -> V_38 , V_35 ) ;
}
static int F_52 ( struct V_118 * V_119 , unsigned int V_126 )
{
struct V_1 * V_1 = F_49 ( V_119 ) ;
if ( V_1 -> V_6 == NULL )
return - V_55 ;
return F_34 ( V_1 ) ;
}
static int F_53 ( struct V_118 * V_119 )
{
struct V_1 * V_1 = F_49 ( V_119 ) ;
if ( V_1 -> V_6 == NULL )
return - V_55 ;
F_30 ( V_1 ) ;
return 0 ;
}
static void F_54 ( struct V_127 * V_128 )
{
struct V_1 * V_1 = F_50 ( V_128 , struct V_1 , V_128 ) ;
F_55 ( & V_1 -> V_128 ) ;
F_56 ( & V_1 -> V_129 ) ;
F_32 ( V_1 ) ;
}
static int F_57 ( struct V_130 * V_131 ,
const struct V_132 * V_133 )
{
int V_4 ;
int V_3 ;
struct V_134 * V_59 = & V_131 -> V_59 ;
struct V_1 * V_1 ;
if ( V_131 -> V_135 != 2 )
return - V_55 ;
if ( V_131 -> V_136 [ 1 ] . V_137 . V_138 != 4 )
return - V_55 ;
V_3 = F_58 ( & V_131 -> V_136 [ 1 ] . V_139 [ 0 ] . V_137 ) ;
V_3 = ( V_3 & 0x07ff ) * ( ( ( V_3 & 0x1800 ) >> 11 ) + 1 ) ;
V_1 = F_29 ( sizeof( struct V_1 ) , V_71 ) ;
if ( V_1 == NULL )
return - V_81 ;
V_1 -> V_59 = V_59 ;
V_1 -> V_6 = F_59 ( F_60 ( V_131 ) ) ;
V_1 -> V_69 = V_3 ;
F_61 ( & V_1 -> V_38 ) ;
F_62 ( & V_1 -> V_140 ) ;
F_62 ( & V_1 -> V_141 ) ;
F_63 ( & V_1 -> V_39 ) ;
V_1 -> V_129 . type = V_142 ;
V_1 -> V_129 . V_143 = V_144 | V_145 | V_146 ;
V_1 -> V_129 . V_147 = V_1 ;
V_1 -> V_129 . V_148 = sizeof( struct V_33 ) ;
V_1 -> V_129 . V_149 = & V_150 ;
V_1 -> V_129 . V_151 = & V_152 ;
V_1 -> V_129 . V_153 = V_154 ;
V_1 -> V_129 . V_155 = & V_1 -> V_141 ;
V_4 = F_64 ( & V_1 -> V_129 ) ;
if ( V_4 < 0 ) {
F_24 ( V_59 , L_7 ) ;
goto V_156;
}
V_1 -> V_128 . V_157 = F_54 ;
V_4 = F_65 ( V_59 , & V_1 -> V_128 ) ;
if ( V_4 < 0 ) {
F_24 ( V_59 , L_8 ) ;
goto V_158;
}
F_66 ( V_131 , V_1 ) ;
F_38 ( V_1 -> V_159 . V_97 , L_3 , sizeof( V_1 -> V_159 . V_97 ) ) ;
V_1 -> V_159 . V_128 = & V_1 -> V_128 ;
V_1 -> V_159 . V_157 = V_160 ;
V_1 -> V_159 . V_161 = & V_162 ;
V_1 -> V_159 . V_163 = & V_164 ;
V_1 -> V_159 . V_165 = V_100 ;
V_1 -> V_159 . V_166 = & V_1 -> V_129 ;
V_1 -> V_159 . V_155 = & V_1 -> V_140 ;
F_67 ( V_167 , & V_1 -> V_159 . V_35 ) ;
F_68 ( & V_1 -> V_159 , V_1 ) ;
V_4 = F_69 ( & V_1 -> V_159 , V_168 , - 1 ) ;
if ( V_4 < 0 ) {
F_24 ( V_59 , L_9 ) ;
goto V_169;
}
F_70 ( V_59 , L_10 ) ;
return 0 ;
V_169:
F_55 ( & V_1 -> V_128 ) ;
V_158:
F_56 ( & V_1 -> V_129 ) ;
V_156:
F_32 ( V_1 ) ;
return V_4 ;
}
static void F_71 ( struct V_130 * V_131 )
{
struct V_1 * V_1 = F_72 ( V_131 ) ;
F_73 ( & V_1 -> V_141 ) ;
F_73 ( & V_1 -> V_140 ) ;
F_30 ( V_1 ) ;
F_66 ( V_131 , NULL ) ;
F_74 ( & V_1 -> V_159 ) ;
F_75 ( & V_1 -> V_128 ) ;
F_76 ( V_1 -> V_6 ) ;
V_1 -> V_6 = NULL ;
F_77 ( & V_1 -> V_140 ) ;
F_77 ( & V_1 -> V_141 ) ;
F_78 ( & V_1 -> V_128 ) ;
}

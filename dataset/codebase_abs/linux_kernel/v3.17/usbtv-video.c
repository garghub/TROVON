static int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_3 , V_4 = 0 ;
struct V_5 * V_6 = NULL ;
for ( V_3 = 0 ; V_3 < F_2 ( V_7 ) ; V_3 ++ ) {
if ( V_7 [ V_3 ] . V_2 & V_2 ) {
V_6 = & V_7 [ V_3 ] ;
break;
}
}
if ( V_6 ) {
V_1 -> V_8 = V_6 -> V_9 ;
V_1 -> V_10 = V_6 -> V_11 ;
V_1 -> V_12 = V_1 -> V_8 * V_1 -> V_10
/ 4 / V_13 ;
V_1 -> V_2 = V_6 -> V_2 ;
} else
V_4 = - V_14 ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_1 , int V_15 )
{
int V_4 ;
static const T_2 V_16 [] [ 2 ] = {
{ V_17 + 0x0105 , 0x0060 } ,
{ V_17 + 0x011f , 0x00f2 } ,
{ V_17 + 0x0127 , 0x0060 } ,
{ V_17 + 0x00ae , 0x0010 } ,
{ V_17 + 0x0284 , 0x00aa } ,
{ V_17 + 0x0239 , 0x0060 } ,
} ;
static const T_2 V_18 [] [ 2 ] = {
{ V_17 + 0x0105 , 0x0010 } ,
{ V_17 + 0x011f , 0x00ff } ,
{ V_17 + 0x0127 , 0x0060 } ,
{ V_17 + 0x00ae , 0x0030 } ,
{ V_17 + 0x0284 , 0x0088 } ,
{ V_17 + 0x0239 , 0x0060 } ,
} ;
switch ( V_15 ) {
case V_19 :
V_4 = F_4 ( V_1 , V_16 , F_2 ( V_16 ) ) ;
break;
case V_20 :
V_4 = F_4 ( V_1 , V_18 , F_2 ( V_18 ) ) ;
break;
default:
V_4 = - V_14 ;
}
if ( ! V_4 )
V_1 -> V_15 = V_15 ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_4 ;
static const T_2 V_21 [] [ 2 ] = {
{ V_17 + 0x001a , 0x0068 } ,
{ V_17 + 0x010e , 0x0072 } ,
{ V_17 + 0x010f , 0x00a2 } ,
{ V_17 + 0x0112 , 0x00b0 } ,
{ V_17 + 0x0117 , 0x0001 } ,
{ V_17 + 0x0118 , 0x002c } ,
{ V_17 + 0x012d , 0x0010 } ,
{ V_17 + 0x012f , 0x0020 } ,
{ V_17 + 0x024f , 0x0002 } ,
{ V_17 + 0x0254 , 0x0059 } ,
{ V_17 + 0x025a , 0x0016 } ,
{ V_17 + 0x025b , 0x0035 } ,
{ V_17 + 0x0263 , 0x0017 } ,
{ V_17 + 0x0266 , 0x0016 } ,
{ V_17 + 0x0267 , 0x0036 }
} ;
static const T_2 V_22 [] [ 2 ] = {
{ V_17 + 0x001a , 0x0079 } ,
{ V_17 + 0x010e , 0x0068 } ,
{ V_17 + 0x010f , 0x009c } ,
{ V_17 + 0x0112 , 0x00f0 } ,
{ V_17 + 0x0117 , 0x0000 } ,
{ V_17 + 0x0118 , 0x00fc } ,
{ V_17 + 0x012d , 0x0004 } ,
{ V_17 + 0x012f , 0x0008 } ,
{ V_17 + 0x024f , 0x0001 } ,
{ V_17 + 0x0254 , 0x005f } ,
{ V_17 + 0x025a , 0x0012 } ,
{ V_17 + 0x025b , 0x0001 } ,
{ V_17 + 0x0263 , 0x001c } ,
{ V_17 + 0x0266 , 0x0011 } ,
{ V_17 + 0x0267 , 0x0005 }
} ;
V_4 = F_1 ( V_1 , V_2 ) ;
if ( ! V_4 ) {
if ( V_2 & V_23 )
V_4 = F_4 ( V_1 , V_22 , F_2 ( V_22 ) ) ;
else if ( V_2 & V_24 )
V_4 = F_4 ( V_1 , V_21 , F_2 ( V_21 ) ) ;
}
return V_4 ;
}
static int F_6 ( struct V_1 * V_1 )
{
int V_4 ;
static const T_2 V_25 [] [ 2 ] = {
{ V_17 + 0x0008 , 0x0001 } ,
{ V_17 + 0x01d0 , 0x00ff } ,
{ V_17 + 0x01d9 , 0x0002 } ,
{ V_17 + 0x0239 , 0x0040 } ,
{ V_17 + 0x0240 , 0x0000 } ,
{ V_17 + 0x0241 , 0x0000 } ,
{ V_17 + 0x0242 , 0x0002 } ,
{ V_17 + 0x0243 , 0x0080 } ,
{ V_17 + 0x0244 , 0x0012 } ,
{ V_17 + 0x0245 , 0x0090 } ,
{ V_17 + 0x0246 , 0x0000 } ,
{ V_17 + 0x0278 , 0x002d } ,
{ V_17 + 0x0279 , 0x000a } ,
{ V_17 + 0x027a , 0x0032 } ,
{ 0xf890 , 0x000c } ,
{ 0xf894 , 0x0086 } ,
{ V_17 + 0x00ac , 0x00c0 } ,
{ V_17 + 0x00ad , 0x0000 } ,
{ V_17 + 0x00a2 , 0x0012 } ,
{ V_17 + 0x00a3 , 0x00e0 } ,
{ V_17 + 0x00a4 , 0x0028 } ,
{ V_17 + 0x00a5 , 0x0082 } ,
{ V_17 + 0x00a7 , 0x0080 } ,
{ V_17 + 0x0000 , 0x0014 } ,
{ V_17 + 0x0006 , 0x0003 } ,
{ V_17 + 0x0090 , 0x0099 } ,
{ V_17 + 0x0091 , 0x0090 } ,
{ V_17 + 0x0094 , 0x0068 } ,
{ V_17 + 0x0095 , 0x0070 } ,
{ V_17 + 0x009c , 0x0030 } ,
{ V_17 + 0x009d , 0x00c0 } ,
{ V_17 + 0x009e , 0x00e0 } ,
{ V_17 + 0x0019 , 0x0006 } ,
{ V_17 + 0x008c , 0x00ba } ,
{ V_17 + 0x0101 , 0x00ff } ,
{ V_17 + 0x010c , 0x00b3 } ,
{ V_17 + 0x01b2 , 0x0080 } ,
{ V_17 + 0x01b4 , 0x00a0 } ,
{ V_17 + 0x014c , 0x00ff } ,
{ V_17 + 0x014d , 0x00ca } ,
{ V_17 + 0x0113 , 0x0053 } ,
{ V_17 + 0x0119 , 0x008a } ,
{ V_17 + 0x013c , 0x0003 } ,
{ V_17 + 0x0150 , 0x009c } ,
{ V_17 + 0x0151 , 0x0071 } ,
{ V_17 + 0x0152 , 0x00c6 } ,
{ V_17 + 0x0153 , 0x0084 } ,
{ V_17 + 0x0154 , 0x00bc } ,
{ V_17 + 0x0155 , 0x00a0 } ,
{ V_17 + 0x0156 , 0x00a0 } ,
{ V_17 + 0x0157 , 0x009c } ,
{ V_17 + 0x0158 , 0x001f } ,
{ V_17 + 0x0159 , 0x0006 } ,
{ V_17 + 0x015d , 0x0000 } ,
{ V_17 + 0x0284 , 0x0088 } ,
{ V_17 + 0x0003 , 0x0004 } ,
{ V_17 + 0x0100 , 0x00d3 } ,
{ V_17 + 0x0115 , 0x0015 } ,
{ V_17 + 0x0220 , 0x002e } ,
{ V_17 + 0x0225 , 0x0008 } ,
{ V_17 + 0x024e , 0x0002 } ,
{ V_17 + 0x024e , 0x0002 } ,
{ V_17 + 0x024f , 0x0002 } ,
} ;
V_4 = F_4 ( V_1 , V_25 , F_2 ( V_25 ) ) ;
if ( V_4 )
return V_4 ;
V_4 = F_5 ( V_1 , V_1 -> V_2 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_3 ( V_1 , V_1 -> V_15 ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
static void F_7 ( T_3 * V_26 , T_3 * V_27 , int V_28 , int V_29 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < 2 ; V_30 ++ ) {
int V_31 = V_28 * 2 + V_30 ;
int line = V_31 / 3 ;
int V_32 = ( line * 2 + ! V_29 ) * 3 + ( V_31 % 3 ) ;
T_3 * V_33 = & V_26 [ V_32 * V_13 / 2 ] ;
memcpy ( V_33 , V_27 , V_13 / 2 * sizeof( * V_27 ) ) ;
V_27 += V_13 / 2 ;
}
}
static void F_8 ( struct V_1 * V_1 , T_3 * V_34 )
{
int V_35 , V_29 , V_28 ;
T_3 * V_26 ;
struct V_36 * V_37 ;
unsigned long V_38 ;
if ( ! F_9 ( V_34 ) )
return;
V_35 = F_10 ( V_34 ) ;
V_29 = F_11 ( V_34 ) ;
V_28 = F_12 ( V_34 ) ;
if ( V_28 >= V_1 -> V_12 )
return;
if ( V_28 == 0 ) {
V_1 -> V_35 = V_35 ;
V_1 -> V_39 = 0 ;
}
if ( V_1 -> V_35 != V_35 )
return;
F_13 ( & V_1 -> V_40 , V_38 ) ;
if ( F_14 ( & V_1 -> V_41 ) ) {
F_15 ( & V_1 -> V_40 , V_38 ) ;
return;
}
V_37 = F_16 ( & V_1 -> V_41 , struct V_36 , V_42 ) ;
V_26 = F_17 ( & V_37 -> V_43 , 0 ) ;
F_7 ( V_26 , & V_34 [ 1 ] , V_28 , V_29 ) ;
V_1 -> V_39 ++ ;
if ( V_29 && V_28 == V_1 -> V_12 - 1 ) {
int V_44 = F_18 ( & V_37 -> V_43 , 0 ) ;
enum V_45 V_46 = V_1 -> V_39 ==
V_1 -> V_12 ?
V_47 :
V_48 ;
V_37 -> V_43 . V_49 . V_50 = V_51 ;
V_37 -> V_43 . V_49 . V_52 = V_1 -> V_52 ++ ;
F_19 ( & V_37 -> V_43 . V_49 . V_53 ) ;
F_20 ( & V_37 -> V_43 , 0 , V_44 ) ;
F_21 ( & V_37 -> V_43 , V_46 ) ;
F_22 ( & V_37 -> V_42 ) ;
}
F_15 ( & V_1 -> V_40 , V_38 ) ;
}
static void F_23 ( struct V_54 * V_55 )
{
int V_4 ;
int V_3 ;
struct V_1 * V_1 = (struct V_1 * ) V_55 -> V_56 ;
switch ( V_55 -> V_57 ) {
case 0 :
break;
case - V_58 :
case - V_59 :
case - V_60 :
case - V_61 :
return;
default:
F_24 ( V_1 -> V_62 , L_1 ) ;
goto V_63;
}
for ( V_3 = 0 ; V_3 < V_55 -> V_64 ; V_3 ++ ) {
int V_44 = V_55 -> V_65 [ V_3 ] . V_66 ;
unsigned char * V_67 = V_55 -> V_68 +
V_55 -> V_65 [ V_3 ] . V_69 ;
int V_69 ;
for ( V_69 = 0 ; V_70 * V_69 < V_44 ; V_69 ++ )
F_8 ( V_1 ,
( T_3 * ) & V_67 [ V_70 * V_69 ] ) ;
}
V_63:
V_4 = F_25 ( V_55 , V_71 ) ;
if ( V_4 < 0 )
F_24 ( V_1 -> V_62 , L_2 ) ;
}
static struct V_54 * F_26 ( struct V_1 * V_1 )
{
struct V_54 * V_55 ;
int V_44 = V_1 -> V_72 ;
int V_3 ;
V_55 = F_27 ( V_73 , V_74 ) ;
if ( V_55 == NULL )
return NULL ;
V_55 -> V_62 = V_1 -> V_75 ;
V_55 -> V_56 = V_1 ;
V_55 -> V_76 = F_28 ( V_1 -> V_75 , V_77 ) ;
V_55 -> V_78 = 1 ;
V_55 -> V_79 = V_80 ;
V_55 -> V_68 = F_29 ( V_44 * V_73 ,
V_74 ) ;
V_55 -> V_81 = F_23 ;
V_55 -> V_64 = V_73 ;
V_55 -> V_82 = V_44 * V_73 ;
for ( V_3 = 0 ; V_3 < V_73 ; V_3 ++ ) {
V_55 -> V_65 [ V_3 ] . V_69 = V_44 * V_3 ;
V_55 -> V_65 [ V_3 ] . V_83 = V_44 ;
}
return V_55 ;
}
static void F_30 ( struct V_1 * V_1 )
{
int V_3 ;
unsigned long V_38 ;
for ( V_3 = 0 ; V_3 < V_84 ; V_3 ++ ) {
struct V_54 * V_55 = V_1 -> V_85 [ V_3 ] ;
if ( V_55 == NULL )
continue;
F_31 ( V_55 ) ;
F_32 ( V_55 -> V_68 ) ;
F_33 ( V_55 ) ;
V_1 -> V_85 [ V_3 ] = NULL ;
}
F_13 ( & V_1 -> V_40 , V_38 ) ;
while ( ! F_14 ( & V_1 -> V_41 ) ) {
struct V_36 * V_37 = F_16 ( & V_1 -> V_41 ,
struct V_36 , V_42 ) ;
F_21 ( & V_37 -> V_43 , V_48 ) ;
F_22 ( & V_37 -> V_42 ) ;
}
F_15 ( & V_1 -> V_40 , V_38 ) ;
}
static int F_34 ( struct V_1 * V_1 )
{
int V_3 ;
int V_4 ;
V_4 = F_35 ( V_1 -> V_75 , 0 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_6 ( V_1 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_35 ( V_1 -> V_75 , 0 , 1 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_3 = 0 ; V_3 < V_84 ; V_3 ++ ) {
struct V_54 * V_55 ;
V_55 = F_26 ( V_1 ) ;
if ( V_55 == NULL ) {
V_4 = - V_86 ;
goto V_87;
}
V_1 -> V_85 [ V_3 ] = V_55 ;
V_4 = F_25 ( V_55 , V_74 ) ;
if ( V_4 < 0 )
goto V_87;
}
return 0 ;
V_87:
F_30 ( V_1 ) ;
return V_4 ;
}
static int F_36 ( struct V_88 * V_88 , void * V_89 ,
struct V_90 * V_91 )
{
struct V_1 * V_62 = F_37 ( V_88 ) ;
F_38 ( V_91 -> V_92 , L_3 , sizeof( V_91 -> V_92 ) ) ;
F_38 ( V_91 -> V_93 , L_3 , sizeof( V_91 -> V_93 ) ) ;
F_39 ( V_62 -> V_75 , V_91 -> V_94 , sizeof( V_91 -> V_94 ) ) ;
V_91 -> V_95 = V_96 ;
V_91 -> V_95 |= V_97 | V_98 ;
V_91 -> V_99 = V_91 -> V_95 | V_100 ;
return 0 ;
}
static int F_40 ( struct V_88 * V_88 , void * V_89 ,
struct V_101 * V_3 )
{
struct V_1 * V_62 = F_37 ( V_88 ) ;
switch ( V_3 -> V_102 ) {
case V_19 :
F_38 ( V_3 -> V_103 , L_4 , sizeof( V_3 -> V_103 ) ) ;
break;
case V_20 :
F_38 ( V_3 -> V_103 , L_5 , sizeof( V_3 -> V_103 ) ) ;
break;
default:
return - V_14 ;
}
V_3 -> type = V_104 ;
V_3 -> V_105 = V_62 -> V_106 . V_107 ;
return 0 ;
}
static int F_41 ( struct V_88 * V_88 , void * V_89 ,
struct V_108 * V_109 )
{
if ( V_109 -> V_102 > 0 )
return - V_14 ;
F_38 ( V_109 -> V_110 , L_6 ,
sizeof( V_109 -> V_110 ) ) ;
V_109 -> V_111 = V_112 ;
return 0 ;
}
static int F_42 ( struct V_88 * V_88 , void * V_89 ,
struct V_113 * V_109 )
{
struct V_1 * V_1 = F_37 ( V_88 ) ;
V_109 -> V_114 . V_115 . V_8 = V_1 -> V_8 ;
V_109 -> V_114 . V_115 . V_10 = V_1 -> V_10 ;
V_109 -> V_114 . V_115 . V_111 = V_112 ;
V_109 -> V_114 . V_115 . V_50 = V_51 ;
V_109 -> V_114 . V_115 . V_116 = V_1 -> V_8 * 2 ;
V_109 -> V_114 . V_115 . V_117 = ( V_109 -> V_114 . V_115 . V_116 * V_109 -> V_114 . V_115 . V_10 ) ;
V_109 -> V_114 . V_115 . V_118 = V_119 ;
return 0 ;
}
static int F_43 ( struct V_88 * V_88 , void * V_89 , T_1 * V_2 )
{
struct V_1 * V_1 = F_37 ( V_88 ) ;
* V_2 = V_1 -> V_2 ;
return 0 ;
}
static int F_44 ( struct V_88 * V_88 , void * V_89 , T_1 V_2 )
{
int V_4 = - V_14 ;
struct V_1 * V_1 = F_37 ( V_88 ) ;
if ( ( V_2 & V_23 ) || ( V_2 & V_24 ) )
V_4 = F_5 ( V_1 , V_2 ) ;
return V_4 ;
}
static int F_45 ( struct V_88 * V_88 , void * V_89 , unsigned int * V_3 )
{
struct V_1 * V_1 = F_37 ( V_88 ) ;
* V_3 = V_1 -> V_15 ;
return 0 ;
}
static int F_46 ( struct V_88 * V_88 , void * V_89 , unsigned int V_3 )
{
struct V_1 * V_1 = F_37 ( V_88 ) ;
return F_3 ( V_1 , V_3 ) ;
}
static int F_47 ( struct V_120 * V_121 ,
const struct V_113 * V_122 , unsigned int * V_123 ,
unsigned int * V_124 , unsigned int V_125 [] , void * V_126 [] )
{
struct V_1 * V_1 = F_48 ( V_121 ) ;
if ( * V_123 < 2 )
* V_123 = 2 ;
* V_124 = 1 ;
V_125 [ 0 ] = V_13 * V_1 -> V_12 * 2 * sizeof( T_3 ) ;
return 0 ;
}
static void F_49 ( struct V_127 * V_43 )
{
struct V_1 * V_1 = F_48 ( V_43 -> V_120 ) ;
struct V_36 * V_37 = F_50 ( V_43 , struct V_36 , V_43 ) ;
unsigned long V_38 ;
if ( V_1 -> V_75 == NULL ) {
F_21 ( V_43 , V_48 ) ;
return;
}
F_13 ( & V_1 -> V_40 , V_38 ) ;
F_51 ( & V_37 -> V_42 , & V_1 -> V_41 ) ;
F_15 ( & V_1 -> V_40 , V_38 ) ;
}
static int F_52 ( struct V_120 * V_121 , unsigned int V_128 )
{
struct V_1 * V_1 = F_48 ( V_121 ) ;
if ( V_1 -> V_75 == NULL )
return - V_58 ;
return F_34 ( V_1 ) ;
}
static void F_53 ( struct V_120 * V_121 )
{
struct V_1 * V_1 = F_48 ( V_121 ) ;
if ( V_1 -> V_75 )
F_30 ( V_1 ) ;
}
static void F_54 ( struct V_129 * V_130 )
{
struct V_1 * V_1 = F_50 ( V_130 , struct V_1 , V_130 ) ;
F_55 ( & V_1 -> V_130 ) ;
F_56 ( & V_1 -> V_131 ) ;
F_32 ( V_1 ) ;
}
int F_57 ( struct V_1 * V_1 )
{
int V_4 ;
( void ) F_1 ( V_1 , V_23 ) ;
F_58 ( & V_1 -> V_40 ) ;
F_59 ( & V_1 -> V_132 ) ;
F_59 ( & V_1 -> V_133 ) ;
F_60 ( & V_1 -> V_41 ) ;
V_1 -> V_131 . type = V_134 ;
V_1 -> V_131 . V_135 = V_136 | V_137 | V_138 ;
V_1 -> V_131 . V_139 = V_1 ;
V_1 -> V_131 . V_140 = sizeof( struct V_36 ) ;
V_1 -> V_131 . V_141 = & V_142 ;
V_1 -> V_131 . V_143 = & V_144 ;
V_1 -> V_131 . V_145 = V_146 ;
V_1 -> V_131 . V_147 = & V_1 -> V_133 ;
V_4 = F_61 ( & V_1 -> V_131 ) ;
if ( V_4 < 0 ) {
F_24 ( V_1 -> V_62 , L_7 ) ;
return V_4 ;
}
V_1 -> V_130 . V_148 = F_54 ;
V_4 = F_62 ( V_1 -> V_62 , & V_1 -> V_130 ) ;
if ( V_4 < 0 ) {
F_24 ( V_1 -> V_62 , L_8 ) ;
goto V_149;
}
F_38 ( V_1 -> V_106 . V_103 , L_3 , sizeof( V_1 -> V_106 . V_103 ) ) ;
V_1 -> V_106 . V_130 = & V_1 -> V_130 ;
V_1 -> V_106 . V_148 = V_150 ;
V_1 -> V_106 . V_151 = & V_152 ;
V_1 -> V_106 . V_153 = & V_154 ;
V_1 -> V_106 . V_107 = V_155 ;
V_1 -> V_106 . V_156 = & V_1 -> V_131 ;
V_1 -> V_106 . V_147 = & V_1 -> V_132 ;
F_63 ( & V_1 -> V_106 , V_1 ) ;
V_4 = F_64 ( & V_1 -> V_106 , V_157 , - 1 ) ;
if ( V_4 < 0 ) {
F_24 ( V_1 -> V_62 , L_9 ) ;
goto V_158;
}
return 0 ;
V_158:
F_55 ( & V_1 -> V_130 ) ;
V_149:
F_56 ( & V_1 -> V_131 ) ;
return V_4 ;
}
void F_65 ( struct V_1 * V_1 )
{
F_66 ( & V_1 -> V_133 ) ;
F_66 ( & V_1 -> V_132 ) ;
F_30 ( V_1 ) ;
F_67 ( & V_1 -> V_106 ) ;
F_68 ( & V_1 -> V_130 ) ;
F_69 ( & V_1 -> V_132 ) ;
F_69 ( & V_1 -> V_133 ) ;
F_70 ( & V_1 -> V_130 ) ;
}

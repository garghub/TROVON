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
{ V_17 + 0x0239 , 0x0060 } ,
} ;
static const T_2 V_18 [] [ 2 ] = {
{ V_17 + 0x0105 , 0x0010 } ,
{ V_17 + 0x011f , 0x00ff } ,
{ V_17 + 0x0127 , 0x0060 } ,
{ V_17 + 0x00ae , 0x0030 } ,
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
static void F_7 ( T_3 * V_26 , T_4 * V_27 , int V_28 , int V_29 )
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
static void F_8 ( struct V_1 * V_1 , T_4 * V_34 )
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
V_26 = F_17 ( & V_37 -> V_43 . V_44 , 0 ) ;
F_7 ( V_26 , & V_34 [ 1 ] , V_28 , V_29 ) ;
V_1 -> V_39 ++ ;
if ( V_28 == V_1 -> V_12 - 1 ) {
if ( V_29 && ! V_1 -> V_45 ) {
int V_46 = F_18 ( & V_37 -> V_43 . V_44 , 0 ) ;
enum V_47 V_48 = V_1 -> V_39 ==
V_1 -> V_12 ?
V_49 :
V_50 ;
V_37 -> V_43 . V_51 = V_52 ;
V_37 -> V_43 . V_53 = V_1 -> V_53 ++ ;
V_37 -> V_43 . V_44 . V_54 = F_19 () ;
F_20 ( & V_37 -> V_43 . V_44 , 0 , V_46 ) ;
F_21 ( & V_37 -> V_43 . V_44 , V_48 ) ;
F_22 ( & V_37 -> V_42 ) ;
}
V_1 -> V_45 = V_29 ;
}
F_15 ( & V_1 -> V_40 , V_38 ) ;
}
static void F_23 ( struct V_55 * V_56 )
{
int V_4 ;
int V_3 ;
struct V_1 * V_1 = (struct V_1 * ) V_56 -> V_57 ;
switch ( V_56 -> V_58 ) {
case 0 :
break;
case - V_59 :
case - V_60 :
case - V_61 :
case - V_62 :
return;
default:
F_24 ( V_1 -> V_63 , L_1 ) ;
goto V_64;
}
for ( V_3 = 0 ; V_3 < V_56 -> V_65 ; V_3 ++ ) {
int V_46 = V_56 -> V_66 [ V_3 ] . V_67 ;
unsigned char * V_68 = V_56 -> V_69 +
V_56 -> V_66 [ V_3 ] . V_70 ;
int V_70 ;
for ( V_70 = 0 ; V_71 * V_70 < V_46 ; V_70 ++ )
F_8 ( V_1 ,
( T_4 * ) & V_68 [ V_71 * V_70 ] ) ;
}
V_64:
V_4 = F_25 ( V_56 , V_72 ) ;
if ( V_4 < 0 )
F_24 ( V_1 -> V_63 , L_2 ) ;
}
static struct V_55 * F_26 ( struct V_1 * V_1 )
{
struct V_55 * V_56 ;
int V_46 = V_1 -> V_73 ;
int V_3 ;
V_56 = F_27 ( V_74 , V_75 ) ;
if ( V_56 == NULL )
return NULL ;
V_56 -> V_63 = V_1 -> V_76 ;
V_56 -> V_57 = V_1 ;
V_56 -> V_77 = F_28 ( V_1 -> V_76 , V_78 ) ;
V_56 -> V_79 = 1 ;
V_56 -> V_80 = V_81 ;
V_56 -> V_69 = F_29 ( V_46 * V_74 ,
V_75 ) ;
if ( ! V_56 -> V_69 ) {
F_30 ( V_56 ) ;
return NULL ;
}
V_56 -> V_82 = F_23 ;
V_56 -> V_65 = V_74 ;
V_56 -> V_83 = V_46 * V_74 ;
for ( V_3 = 0 ; V_3 < V_74 ; V_3 ++ ) {
V_56 -> V_66 [ V_3 ] . V_70 = V_46 * V_3 ;
V_56 -> V_66 [ V_3 ] . V_84 = V_46 ;
}
return V_56 ;
}
static void F_31 ( struct V_1 * V_1 )
{
int V_3 ;
unsigned long V_38 ;
for ( V_3 = 0 ; V_3 < V_85 ; V_3 ++ ) {
struct V_55 * V_56 = V_1 -> V_86 [ V_3 ] ;
if ( V_56 == NULL )
continue;
F_32 ( V_56 ) ;
F_33 ( V_56 -> V_69 ) ;
F_30 ( V_56 ) ;
V_1 -> V_86 [ V_3 ] = NULL ;
}
F_13 ( & V_1 -> V_40 , V_38 ) ;
while ( ! F_14 ( & V_1 -> V_41 ) ) {
struct V_36 * V_37 = F_16 ( & V_1 -> V_41 ,
struct V_36 , V_42 ) ;
F_21 ( & V_37 -> V_43 . V_44 , V_50 ) ;
F_22 ( & V_37 -> V_42 ) ;
}
F_15 ( & V_1 -> V_40 , V_38 ) ;
}
static int F_34 ( struct V_1 * V_1 )
{
int V_3 ;
int V_4 ;
F_35 ( V_1 ) ;
V_4 = F_36 ( V_1 -> V_76 , 0 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_6 ( V_1 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_36 ( V_1 -> V_76 , 0 , 1 ) ;
if ( V_4 < 0 )
return V_4 ;
F_37 ( V_1 ) ;
for ( V_3 = 0 ; V_3 < V_85 ; V_3 ++ ) {
struct V_55 * V_56 ;
V_56 = F_26 ( V_1 ) ;
if ( V_56 == NULL ) {
V_4 = - V_87 ;
goto V_88;
}
V_1 -> V_86 [ V_3 ] = V_56 ;
V_4 = F_25 ( V_56 , V_75 ) ;
if ( V_4 < 0 )
goto V_88;
}
return 0 ;
V_88:
F_31 ( V_1 ) ;
return V_4 ;
}
static int F_38 ( struct V_89 * V_89 , void * V_90 ,
struct V_91 * V_92 )
{
struct V_1 * V_63 = F_39 ( V_89 ) ;
F_40 ( V_92 -> V_93 , L_3 , sizeof( V_92 -> V_93 ) ) ;
F_40 ( V_92 -> V_94 , L_3 , sizeof( V_92 -> V_94 ) ) ;
F_41 ( V_63 -> V_76 , V_92 -> V_95 , sizeof( V_92 -> V_95 ) ) ;
V_92 -> V_96 = V_97 ;
V_92 -> V_96 |= V_98 | V_99 ;
V_92 -> V_100 = V_92 -> V_96 | V_101 ;
return 0 ;
}
static int F_42 ( struct V_89 * V_89 , void * V_90 ,
struct V_102 * V_3 )
{
struct V_1 * V_63 = F_39 ( V_89 ) ;
switch ( V_3 -> V_103 ) {
case V_19 :
F_40 ( V_3 -> V_104 , L_4 , sizeof( V_3 -> V_104 ) ) ;
break;
case V_20 :
F_40 ( V_3 -> V_104 , L_5 , sizeof( V_3 -> V_104 ) ) ;
break;
default:
return - V_14 ;
}
V_3 -> type = V_105 ;
V_3 -> V_106 = V_63 -> V_107 . V_108 ;
return 0 ;
}
static int F_43 ( struct V_89 * V_89 , void * V_90 ,
struct V_109 * V_110 )
{
if ( V_110 -> V_103 > 0 )
return - V_14 ;
F_40 ( V_110 -> V_111 , L_6 ,
sizeof( V_110 -> V_111 ) ) ;
V_110 -> V_112 = V_113 ;
return 0 ;
}
static int F_44 ( struct V_89 * V_89 , void * V_90 ,
struct V_114 * V_110 )
{
struct V_1 * V_1 = F_39 ( V_89 ) ;
V_110 -> V_115 . V_116 . V_8 = V_1 -> V_8 ;
V_110 -> V_115 . V_116 . V_10 = V_1 -> V_10 ;
V_110 -> V_115 . V_116 . V_112 = V_113 ;
V_110 -> V_115 . V_116 . V_51 = V_52 ;
V_110 -> V_115 . V_116 . V_117 = V_1 -> V_8 * 2 ;
V_110 -> V_115 . V_116 . V_118 = ( V_110 -> V_115 . V_116 . V_117 * V_110 -> V_115 . V_116 . V_10 ) ;
V_110 -> V_115 . V_116 . V_119 = V_120 ;
return 0 ;
}
static int F_45 ( struct V_89 * V_89 , void * V_90 , T_1 * V_2 )
{
struct V_1 * V_1 = F_39 ( V_89 ) ;
* V_2 = V_1 -> V_2 ;
return 0 ;
}
static int F_46 ( struct V_89 * V_89 , void * V_90 , T_1 V_2 )
{
int V_4 = - V_14 ;
struct V_1 * V_1 = F_39 ( V_89 ) ;
if ( ( V_2 & V_23 ) || ( V_2 & V_24 ) )
V_4 = F_5 ( V_1 , V_2 ) ;
return V_4 ;
}
static int F_47 ( struct V_89 * V_89 , void * V_90 , unsigned int * V_3 )
{
struct V_1 * V_1 = F_39 ( V_89 ) ;
* V_3 = V_1 -> V_15 ;
return 0 ;
}
static int F_48 ( struct V_89 * V_89 , void * V_90 , unsigned int V_3 )
{
struct V_1 * V_1 = F_39 ( V_89 ) ;
return F_3 ( V_1 , V_3 ) ;
}
static int F_49 ( struct V_121 * V_122 ,
unsigned int * V_123 ,
unsigned int * V_124 , unsigned int V_125 [] , void * V_126 [] )
{
struct V_1 * V_1 = F_50 ( V_122 ) ;
unsigned V_46 = V_13 * V_1 -> V_12 * 2 * sizeof( T_3 ) ;
if ( V_122 -> V_127 + * V_123 < 2 )
* V_123 = 2 - V_122 -> V_127 ;
if ( * V_124 )
return V_125 [ 0 ] < V_46 ? - V_14 : 0 ;
* V_124 = 1 ;
V_125 [ 0 ] = V_46 ;
return 0 ;
}
static void F_51 ( struct V_128 * V_43 )
{
struct V_129 * V_130 = F_52 ( V_43 ) ;
struct V_1 * V_1 = F_50 ( V_43 -> V_121 ) ;
struct V_36 * V_37 = F_53 ( V_130 , struct V_36 , V_43 ) ;
unsigned long V_38 ;
if ( V_1 -> V_76 == NULL ) {
F_21 ( V_43 , V_50 ) ;
return;
}
F_13 ( & V_1 -> V_40 , V_38 ) ;
F_54 ( & V_37 -> V_42 , & V_1 -> V_41 ) ;
F_15 ( & V_1 -> V_40 , V_38 ) ;
}
static int F_55 ( struct V_121 * V_122 , unsigned int V_131 )
{
struct V_1 * V_1 = F_50 ( V_122 ) ;
if ( V_1 -> V_76 == NULL )
return - V_59 ;
V_1 -> V_45 = 1 ;
V_1 -> V_53 = 0 ;
return F_34 ( V_1 ) ;
}
static void F_56 ( struct V_121 * V_122 )
{
struct V_1 * V_1 = F_50 ( V_122 ) ;
if ( V_1 -> V_76 )
F_31 ( V_1 ) ;
}
static void F_57 ( struct V_132 * V_133 )
{
struct V_1 * V_1 = F_53 ( V_133 , struct V_1 , V_133 ) ;
F_58 ( & V_1 -> V_133 ) ;
F_59 ( & V_1 -> V_134 ) ;
F_33 ( V_1 ) ;
}
int F_60 ( struct V_1 * V_1 )
{
int V_4 ;
( void ) F_1 ( V_1 , V_23 ) ;
F_61 ( & V_1 -> V_40 ) ;
F_62 ( & V_1 -> V_135 ) ;
F_62 ( & V_1 -> V_136 ) ;
F_63 ( & V_1 -> V_41 ) ;
V_1 -> V_134 . type = V_137 ;
V_1 -> V_134 . V_138 = V_139 | V_140 | V_141 ;
V_1 -> V_134 . V_142 = V_1 ;
V_1 -> V_134 . V_143 = sizeof( struct V_36 ) ;
V_1 -> V_134 . V_144 = & V_145 ;
V_1 -> V_134 . V_146 = & V_147 ;
V_1 -> V_134 . V_148 = V_149 ;
V_1 -> V_134 . V_150 = & V_1 -> V_136 ;
V_4 = F_64 ( & V_1 -> V_134 ) ;
if ( V_4 < 0 ) {
F_24 ( V_1 -> V_63 , L_7 ) ;
return V_4 ;
}
V_1 -> V_133 . V_151 = F_57 ;
V_4 = F_65 ( V_1 -> V_63 , & V_1 -> V_133 ) ;
if ( V_4 < 0 ) {
F_24 ( V_1 -> V_63 , L_8 ) ;
goto V_152;
}
F_40 ( V_1 -> V_107 . V_104 , L_3 , sizeof( V_1 -> V_107 . V_104 ) ) ;
V_1 -> V_107 . V_133 = & V_1 -> V_133 ;
V_1 -> V_107 . V_151 = V_153 ;
V_1 -> V_107 . V_154 = & V_155 ;
V_1 -> V_107 . V_156 = & V_157 ;
V_1 -> V_107 . V_108 = V_158 ;
V_1 -> V_107 . V_159 = & V_1 -> V_134 ;
V_1 -> V_107 . V_150 = & V_1 -> V_135 ;
F_66 ( & V_1 -> V_107 , V_1 ) ;
V_4 = F_67 ( & V_1 -> V_107 , V_160 , - 1 ) ;
if ( V_4 < 0 ) {
F_24 ( V_1 -> V_63 , L_9 ) ;
goto V_161;
}
return 0 ;
V_161:
F_58 ( & V_1 -> V_133 ) ;
V_152:
F_59 ( & V_1 -> V_134 ) ;
return V_4 ;
}
void F_68 ( struct V_1 * V_1 )
{
F_69 ( & V_1 -> V_136 ) ;
F_69 ( & V_1 -> V_135 ) ;
F_31 ( V_1 ) ;
F_70 ( & V_1 -> V_107 ) ;
F_71 ( & V_1 -> V_133 ) ;
F_72 ( & V_1 -> V_135 ) ;
F_72 ( & V_1 -> V_136 ) ;
F_73 ( & V_1 -> V_133 ) ;
}

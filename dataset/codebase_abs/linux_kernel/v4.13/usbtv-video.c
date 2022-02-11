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
V_4 = F_7 ( & V_1 -> V_26 ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
static void F_8 ( T_3 * V_27 , T_4 * V_28 , int V_29 , int V_30 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < 2 ; V_31 ++ ) {
int V_32 = V_29 * 2 + V_31 ;
int line = V_32 / 3 ;
int V_33 = ( line * 2 + ! V_30 ) * 3 + ( V_32 % 3 ) ;
T_3 * V_34 = & V_27 [ V_33 * V_13 / 2 ] ;
memcpy ( V_34 , V_28 , V_13 / 2 * sizeof( * V_28 ) ) ;
V_28 += V_13 / 2 ;
}
}
static void F_9 ( struct V_1 * V_1 , T_4 * V_35 )
{
int V_36 , V_30 , V_29 ;
T_3 * V_27 ;
struct V_37 * V_38 ;
unsigned long V_39 ;
if ( ! F_10 ( V_35 ) )
return;
V_36 = F_11 ( V_35 ) ;
V_30 = F_12 ( V_35 ) ;
V_29 = F_13 ( V_35 ) ;
if ( V_29 >= V_1 -> V_12 )
return;
if ( V_29 == 0 ) {
V_1 -> V_36 = V_36 ;
V_1 -> V_40 = 0 ;
}
if ( V_1 -> V_36 != V_36 )
return;
F_14 ( & V_1 -> V_41 , V_39 ) ;
if ( F_15 ( & V_1 -> V_42 ) ) {
F_16 ( & V_1 -> V_41 , V_39 ) ;
return;
}
V_38 = F_17 ( & V_1 -> V_42 , struct V_37 , V_43 ) ;
V_27 = F_18 ( & V_38 -> V_44 . V_45 , 0 ) ;
F_8 ( V_27 , & V_35 [ 1 ] , V_29 , V_30 ) ;
V_1 -> V_40 ++ ;
if ( V_29 == V_1 -> V_12 - 1 ) {
if ( V_30 && ! V_1 -> V_46 ) {
int V_47 = F_19 ( & V_38 -> V_44 . V_45 , 0 ) ;
enum V_48 V_49 = V_1 -> V_40 ==
V_1 -> V_12 ?
V_50 :
V_51 ;
V_38 -> V_44 . V_52 = V_53 ;
V_38 -> V_44 . V_54 = V_1 -> V_54 ++ ;
V_38 -> V_44 . V_45 . V_55 = F_20 () ;
F_21 ( & V_38 -> V_44 . V_45 , 0 , V_47 ) ;
F_22 ( & V_38 -> V_44 . V_45 , V_49 ) ;
F_23 ( & V_38 -> V_43 ) ;
}
V_1 -> V_46 = V_30 ;
}
F_16 ( & V_1 -> V_41 , V_39 ) ;
}
static void F_24 ( struct V_56 * V_57 )
{
int V_4 ;
int V_3 ;
struct V_1 * V_1 = (struct V_1 * ) V_57 -> V_58 ;
switch ( V_57 -> V_59 ) {
case 0 :
break;
case - V_60 :
case - V_61 :
case - V_62 :
case - V_63 :
return;
default:
F_25 ( V_1 -> V_64 , L_1 ) ;
goto V_65;
}
for ( V_3 = 0 ; V_3 < V_57 -> V_66 ; V_3 ++ ) {
int V_47 = V_57 -> V_67 [ V_3 ] . V_68 ;
unsigned char * V_69 = V_57 -> V_70 +
V_57 -> V_67 [ V_3 ] . V_71 ;
int V_71 ;
for ( V_71 = 0 ; V_72 * V_71 < V_47 ; V_71 ++ )
F_9 ( V_1 ,
( T_4 * ) & V_69 [ V_72 * V_71 ] ) ;
}
V_65:
V_4 = F_26 ( V_57 , V_73 ) ;
if ( V_4 < 0 )
F_25 ( V_1 -> V_64 , L_2 ) ;
}
static struct V_56 * F_27 ( struct V_1 * V_1 )
{
struct V_56 * V_57 ;
int V_47 = V_1 -> V_74 ;
int V_3 ;
V_57 = F_28 ( V_75 , V_76 ) ;
if ( V_57 == NULL )
return NULL ;
V_57 -> V_64 = V_1 -> V_77 ;
V_57 -> V_58 = V_1 ;
V_57 -> V_78 = F_29 ( V_1 -> V_77 , V_79 ) ;
V_57 -> V_80 = 1 ;
V_57 -> V_81 = V_82 ;
V_57 -> V_70 = F_30 ( V_47 * V_75 ,
V_76 ) ;
if ( ! V_57 -> V_70 ) {
F_31 ( V_57 ) ;
return NULL ;
}
V_57 -> V_83 = F_24 ;
V_57 -> V_66 = V_75 ;
V_57 -> V_84 = V_47 * V_75 ;
for ( V_3 = 0 ; V_3 < V_75 ; V_3 ++ ) {
V_57 -> V_67 [ V_3 ] . V_71 = V_47 * V_3 ;
V_57 -> V_67 [ V_3 ] . V_85 = V_47 ;
}
return V_57 ;
}
static void F_32 ( struct V_1 * V_1 )
{
int V_3 ;
unsigned long V_39 ;
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
struct V_56 * V_57 = V_1 -> V_87 [ V_3 ] ;
if ( V_57 == NULL )
continue;
F_33 ( V_57 ) ;
F_34 ( V_57 -> V_70 ) ;
F_31 ( V_57 ) ;
V_1 -> V_87 [ V_3 ] = NULL ;
}
F_14 ( & V_1 -> V_41 , V_39 ) ;
while ( ! F_15 ( & V_1 -> V_42 ) ) {
struct V_37 * V_38 = F_17 ( & V_1 -> V_42 ,
struct V_37 , V_43 ) ;
F_22 ( & V_38 -> V_44 . V_45 , V_51 ) ;
F_23 ( & V_38 -> V_43 ) ;
}
F_16 ( & V_1 -> V_41 , V_39 ) ;
}
static int F_35 ( struct V_1 * V_1 )
{
int V_3 ;
int V_4 ;
F_36 ( V_1 ) ;
V_4 = F_37 ( V_1 -> V_77 , 0 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_6 ( V_1 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_37 ( V_1 -> V_77 , 0 , 1 ) ;
if ( V_4 < 0 )
return V_4 ;
F_38 ( V_1 ) ;
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
struct V_56 * V_57 ;
V_57 = F_27 ( V_1 ) ;
if ( V_57 == NULL ) {
V_4 = - V_88 ;
goto V_89;
}
V_1 -> V_87 [ V_3 ] = V_57 ;
V_4 = F_26 ( V_57 , V_76 ) ;
if ( V_4 < 0 )
goto V_89;
}
return 0 ;
V_89:
F_32 ( V_1 ) ;
return V_4 ;
}
static int F_39 ( struct V_90 * V_90 , void * V_91 ,
struct V_92 * V_93 )
{
struct V_1 * V_64 = F_40 ( V_90 ) ;
F_41 ( V_93 -> V_94 , L_3 , sizeof( V_93 -> V_94 ) ) ;
F_41 ( V_93 -> V_95 , L_3 , sizeof( V_93 -> V_95 ) ) ;
F_42 ( V_64 -> V_77 , V_93 -> V_96 , sizeof( V_93 -> V_96 ) ) ;
V_93 -> V_97 = V_98 ;
V_93 -> V_97 |= V_99 | V_100 ;
V_93 -> V_101 = V_93 -> V_97 | V_102 ;
return 0 ;
}
static int F_43 ( struct V_90 * V_90 , void * V_91 ,
struct V_103 * V_3 )
{
struct V_1 * V_64 = F_40 ( V_90 ) ;
switch ( V_3 -> V_104 ) {
case V_19 :
F_41 ( V_3 -> V_105 , L_4 , sizeof( V_3 -> V_105 ) ) ;
break;
case V_20 :
F_41 ( V_3 -> V_105 , L_5 , sizeof( V_3 -> V_105 ) ) ;
break;
default:
return - V_14 ;
}
V_3 -> type = V_106 ;
V_3 -> V_107 = V_64 -> V_108 . V_109 ;
return 0 ;
}
static int F_44 ( struct V_90 * V_90 , void * V_91 ,
struct V_110 * V_111 )
{
if ( V_111 -> V_104 > 0 )
return - V_14 ;
F_41 ( V_111 -> V_112 , L_6 ,
sizeof( V_111 -> V_112 ) ) ;
V_111 -> V_113 = V_114 ;
return 0 ;
}
static int F_45 ( struct V_90 * V_90 , void * V_91 ,
struct V_115 * V_111 )
{
struct V_1 * V_1 = F_40 ( V_90 ) ;
V_111 -> V_116 . V_117 . V_8 = V_1 -> V_8 ;
V_111 -> V_116 . V_117 . V_10 = V_1 -> V_10 ;
V_111 -> V_116 . V_117 . V_113 = V_114 ;
V_111 -> V_116 . V_117 . V_52 = V_53 ;
V_111 -> V_116 . V_117 . V_118 = V_1 -> V_8 * 2 ;
V_111 -> V_116 . V_117 . V_119 = ( V_111 -> V_116 . V_117 . V_118 * V_111 -> V_116 . V_117 . V_10 ) ;
V_111 -> V_116 . V_117 . V_120 = V_121 ;
return 0 ;
}
static int F_46 ( struct V_90 * V_90 , void * V_91 , T_1 * V_2 )
{
struct V_1 * V_1 = F_40 ( V_90 ) ;
* V_2 = V_1 -> V_2 ;
return 0 ;
}
static int F_47 ( struct V_90 * V_90 , void * V_91 , T_1 V_2 )
{
int V_4 = - V_14 ;
struct V_1 * V_1 = F_40 ( V_90 ) ;
if ( ( V_2 & V_23 ) || ( V_2 & V_24 ) )
V_4 = F_5 ( V_1 , V_2 ) ;
return V_4 ;
}
static int F_48 ( struct V_90 * V_90 , void * V_91 , unsigned int * V_3 )
{
struct V_1 * V_1 = F_40 ( V_90 ) ;
* V_3 = V_1 -> V_15 ;
return 0 ;
}
static int F_49 ( struct V_90 * V_90 , void * V_91 , unsigned int V_3 )
{
struct V_1 * V_1 = F_40 ( V_90 ) ;
return F_3 ( V_1 , V_3 ) ;
}
static int F_50 ( struct V_122 * V_123 ,
unsigned int * V_124 ,
unsigned int * V_125 , unsigned int V_126 [] , struct V_127 * V_128 [] )
{
struct V_1 * V_1 = F_51 ( V_123 ) ;
unsigned V_47 = V_13 * V_1 -> V_12 * 2 * sizeof( T_3 ) ;
if ( V_123 -> V_129 + * V_124 < 2 )
* V_124 = 2 - V_123 -> V_129 ;
if ( * V_125 )
return V_126 [ 0 ] < V_47 ? - V_14 : 0 ;
* V_125 = 1 ;
V_126 [ 0 ] = V_47 ;
return 0 ;
}
static void F_52 ( struct V_130 * V_44 )
{
struct V_131 * V_132 = F_53 ( V_44 ) ;
struct V_1 * V_1 = F_51 ( V_44 -> V_122 ) ;
struct V_37 * V_38 = F_54 ( V_132 , struct V_37 , V_44 ) ;
unsigned long V_39 ;
if ( V_1 -> V_77 == NULL ) {
F_22 ( V_44 , V_51 ) ;
return;
}
F_14 ( & V_1 -> V_41 , V_39 ) ;
F_55 ( & V_38 -> V_43 , & V_1 -> V_42 ) ;
F_16 ( & V_1 -> V_41 , V_39 ) ;
}
static int F_56 ( struct V_122 * V_123 , unsigned int V_133 )
{
struct V_1 * V_1 = F_51 ( V_123 ) ;
if ( V_1 -> V_77 == NULL )
return - V_60 ;
V_1 -> V_46 = 1 ;
V_1 -> V_54 = 0 ;
return F_35 ( V_1 ) ;
}
static void F_57 ( struct V_122 * V_123 )
{
struct V_1 * V_1 = F_51 ( V_123 ) ;
if ( V_1 -> V_77 )
F_32 ( V_1 ) ;
}
static int F_58 ( struct V_134 * V_26 )
{
struct V_1 * V_1 = F_54 ( V_26 -> V_135 , struct V_1 ,
V_26 ) ;
T_5 * V_69 ;
T_2 V_104 , V_47 ;
int V_4 ;
V_69 = F_59 ( 3 , V_76 ) ;
if ( ! V_69 )
return - V_88 ;
if ( V_26 -> V_136 == V_137 || V_26 -> V_136 == V_138 ) {
V_4 = F_60 ( V_1 -> V_77 ,
F_61 ( V_1 -> V_77 , 0 ) , V_139 ,
V_140 | V_141 | V_142 ,
0 , V_17 + 0x0244 , ( void * ) V_69 , 3 , 0 ) ;
if ( V_4 < 0 )
goto error;
}
switch ( V_26 -> V_136 ) {
case V_137 :
V_104 = V_17 + 0x0244 ;
V_47 = 3 ;
V_69 [ 0 ] &= 0xf0 ;
V_69 [ 0 ] |= ( V_26 -> V_143 >> 8 ) & 0xf ;
V_69 [ 2 ] = V_26 -> V_143 & 0xff ;
break;
case V_138 :
V_104 = V_17 + 0x0244 ;
V_47 = 3 ;
V_69 [ 0 ] &= 0x0f ;
V_69 [ 0 ] |= ( V_26 -> V_143 >> 4 ) & 0xf0 ;
V_69 [ 1 ] = V_26 -> V_143 & 0xff ;
break;
case V_144 :
V_104 = V_17 + 0x0242 ;
V_69 [ 0 ] = V_26 -> V_143 >> 8 ;
V_69 [ 1 ] = V_26 -> V_143 & 0xff ;
V_47 = 2 ;
break;
case V_145 :
V_104 = V_17 + 0x0240 ;
V_47 = 2 ;
if ( V_26 -> V_143 > 0 ) {
V_69 [ 0 ] = 0x92 + ( V_26 -> V_143 >> 8 ) ;
V_69 [ 1 ] = V_26 -> V_143 & 0xff ;
} else {
V_69 [ 0 ] = 0x82 + ( - V_26 -> V_143 >> 8 ) ;
V_69 [ 1 ] = - V_26 -> V_143 & 0xff ;
}
break;
case V_146 :
V_104 = V_17 + 0x0239 ;
V_69 [ 0 ] = 0 ;
V_69 [ 1 ] = V_26 -> V_143 ;
V_47 = 2 ;
break;
default:
F_34 ( V_69 ) ;
return - V_14 ;
}
V_4 = F_60 ( V_1 -> V_77 , F_61 ( V_1 -> V_77 , 0 ) ,
V_139 ,
V_140 | V_141 | V_142 ,
0 , V_104 , ( void * ) V_69 , V_47 , 0 ) ;
error:
if ( V_4 < 0 )
F_25 ( V_1 -> V_64 , L_7 ) ;
F_34 ( V_69 ) ;
return V_4 ;
}
static void F_62 ( struct V_147 * V_148 )
{
struct V_1 * V_1 = F_54 ( V_148 , struct V_1 , V_148 ) ;
F_63 ( & V_1 -> V_148 ) ;
F_64 ( & V_1 -> V_26 ) ;
F_65 ( & V_1 -> V_149 ) ;
F_34 ( V_1 ) ;
}
int F_66 ( struct V_1 * V_1 )
{
int V_4 ;
( void ) F_1 ( V_1 , V_23 ) ;
F_67 ( & V_1 -> V_41 ) ;
F_68 ( & V_1 -> V_150 ) ;
F_68 ( & V_1 -> V_151 ) ;
F_69 ( & V_1 -> V_42 ) ;
V_1 -> V_149 . type = V_152 ;
V_1 -> V_149 . V_153 = V_154 | V_155 | V_156 ;
V_1 -> V_149 . V_157 = V_1 ;
V_1 -> V_149 . V_158 = sizeof( struct V_37 ) ;
V_1 -> V_149 . V_159 = & V_160 ;
V_1 -> V_149 . V_161 = & V_162 ;
V_1 -> V_149 . V_163 = V_164 ;
V_1 -> V_149 . V_165 = & V_1 -> V_151 ;
V_4 = F_70 ( & V_1 -> V_149 ) ;
if ( V_4 < 0 ) {
F_25 ( V_1 -> V_64 , L_8 ) ;
return V_4 ;
}
F_71 ( & V_1 -> V_26 , 4 ) ;
F_72 ( & V_1 -> V_26 , & V_166 ,
V_138 , 0 , 0x3ff , 1 , 0x1d0 ) ;
F_72 ( & V_1 -> V_26 , & V_166 ,
V_137 , 0 , 0x3ff , 1 , 0x1c0 ) ;
F_72 ( & V_1 -> V_26 , & V_166 ,
V_144 , 0 , 0x3ff , 1 , 0x200 ) ;
F_72 ( & V_1 -> V_26 , & V_166 ,
V_145 , - 0xdff , 0xdff , 1 , 0x000 ) ;
F_72 ( & V_1 -> V_26 , & V_166 ,
V_146 , 0x0 , 0xff , 1 , 0x60 ) ;
V_4 = V_1 -> V_26 . error ;
if ( V_4 < 0 ) {
F_25 ( V_1 -> V_64 , L_9 ) ;
goto V_167;
}
V_1 -> V_148 . V_168 = & V_1 -> V_26 ;
V_1 -> V_148 . V_169 = F_62 ;
V_4 = F_73 ( V_1 -> V_64 , & V_1 -> V_148 ) ;
if ( V_4 < 0 ) {
F_25 ( V_1 -> V_64 , L_10 ) ;
goto V_170;
}
F_41 ( V_1 -> V_108 . V_105 , L_3 , sizeof( V_1 -> V_108 . V_105 ) ) ;
V_1 -> V_108 . V_148 = & V_1 -> V_148 ;
V_1 -> V_108 . V_169 = V_171 ;
V_1 -> V_108 . V_172 = & V_173 ;
V_1 -> V_108 . V_174 = & V_175 ;
V_1 -> V_108 . V_109 = V_176 ;
V_1 -> V_108 . V_177 = & V_1 -> V_149 ;
V_1 -> V_108 . V_165 = & V_1 -> V_150 ;
F_74 ( & V_1 -> V_108 , V_1 ) ;
V_4 = F_75 ( & V_1 -> V_108 , V_178 , - 1 ) ;
if ( V_4 < 0 ) {
F_25 ( V_1 -> V_64 , L_11 ) ;
goto V_179;
}
return 0 ;
V_179:
F_63 ( & V_1 -> V_148 ) ;
V_170:
V_167:
F_64 ( & V_1 -> V_26 ) ;
F_65 ( & V_1 -> V_149 ) ;
return V_4 ;
}
void F_76 ( struct V_1 * V_1 )
{
F_77 ( & V_1 -> V_151 ) ;
F_77 ( & V_1 -> V_150 ) ;
F_32 ( V_1 ) ;
F_78 ( & V_1 -> V_108 ) ;
F_79 ( & V_1 -> V_148 ) ;
F_80 ( & V_1 -> V_150 ) ;
F_80 ( & V_1 -> V_151 ) ;
F_81 ( & V_1 -> V_148 ) ;
}

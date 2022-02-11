static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
F_3 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_7 != V_8 ) {
V_5 = - V_9 ;
goto V_10;
}
V_5 = V_4 -> V_11 -> V_12 ( V_4 -> V_13 ) ;
if ( V_5 == 0 )
V_4 -> V_7 = V_14 ;
V_10:
F_4 ( & V_4 -> V_6 ) ;
return V_5 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_7 == V_8 )
goto V_10;
V_4 -> V_11 -> V_15 ( V_4 -> V_13 ) ;
V_4 -> V_7 = V_8 ;
V_10:
F_4 ( & V_4 -> V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
static struct V_18 {
T_1 V_19 [ 2 ] ;
T_1 V_20 ;
} V_18 [] = {
{ { 0x9f , 0x9a } , 0x00 } ,
{ { 0x98 , 0x10 } , 0xbc } ,
{ { 0x9e , 0x71 } , 0x00 } ,
{ { 0x98 , 0x09 } , 0x00 } ,
{ { 0x9e , 0xb4 } , 0x00 } ,
{ { 0x9c , 0x01 } , 0x08 } ,
{ { 0x9e , 0xaa } , 0x01 } ,
{ { 0x9b , 0xd1 } , 0x17 } ,
{ { 0x9b , 0xd2 } , 0x58 } ,
{ { 0x9b , 0xd3 } , 0x10 } ,
{ { 0x9b , 0xd4 } , 0x47 } ,
{ { 0x9b , 0xd5 } , 0x0c } ,
{ { 0x9b , 0xd6 } , 0x37 } ,
{ { 0x9b , 0xdd } , 0x33 } ,
{ { 0x9b , 0x84 } , 0x00 } ,
{ { 0x99 , 0x81 } , 0x79 } ,
{ { 0x99 , 0x31 } , 0x79 } ,
{ { 0x98 , 0x00 } , 0x3f } ,
{ { 0x9f , 0x09 } , 0x02 } ,
{ { 0x9f , 0x0a } , 0x05 } ,
{ { 0x9e , 0xd1 } , 0xa1 } ,
{ { 0x99 , 0x23 } , 0x01 } ,
{ { 0x9e , 0x74 } , 0x00 } ,
{ { 0x9e , 0x90 } , 0x00 } ,
{ { 0x9f , 0x28 } , 0x10 } ,
{ { 0x9f , 0x35 } , 0x04 } ,
{ { 0x9f , 0x36 } , 0x11 } ,
{ { 0x9c , 0x31 } , 0x00 } ,
{ { 0x9c , 0x32 } , 0x00 } ,
{ { 0x9c , 0x19 } , 0x0a } ,
{ { 0x9c , 0x1a } , 0x0a } ,
{ { 0x9c , 0x0c } , 0x00 } ,
{ { 0x9c , 0x0d } , 0x00 } ,
{ { 0x9c , 0x12 } , 0x00 } ,
{ { 0x9c , 0x13 } , 0x00 } ,
{ { 0x98 , 0xa2 } , 0x09 } ,
{ { 0x98 , 0x93 } , 0x00 } ,
{ { 0x98 , 0x7d } , 0x08 } ,
{ { 0x98 , 0x7e } , 0x00 } ,
{ { 0x9f , 0xc8 } , 0x00 } ,
} ;
struct V_18 * V_21 = V_18 ;
int V_22 = F_7 ( V_18 ) ;
struct V_16 * V_23 ;
T_1 V_24 [ 4 ] ;
int V_5 ;
V_24 [ 0 ] = 0 ;
while ( V_22 -- ) {
V_24 [ 1 ] = V_21 -> V_19 [ 0 ] ;
V_24 [ 2 ] = V_21 -> V_19 [ 1 ] ;
V_24 [ 3 ] = V_21 -> V_20 ;
V_5 = F_8 ( V_2 , V_25 , V_26 ,
V_24 , 4 , & V_23 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_23 -> V_27 != 1 ) {
F_9 ( V_23 ) ;
return - V_28 ;
}
if ( V_23 -> V_29 [ 0 ] != V_21 -> V_20 ) {
F_9 ( V_23 ) ;
return - V_30 ;
}
F_9 ( V_23 ) ;
V_21 ++ ;
}
V_24 [ 0 ] = V_31 ;
V_5 = F_10 ( V_2 , V_32 ,
V_33 , V_24 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_24 [ 0 ] = 0x3d ;
V_5 = F_10 ( V_2 , V_25 ,
V_34 , V_24 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_24 [ 0 ] = 0x0 ;
V_5 = F_10 ( V_2 , V_35 ,
V_36 , V_24 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_11 ( V_2 , V_35 ,
V_37 , NULL , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_24 [ 0 ] = 0x1 ;
V_5 = F_10 ( V_2 , V_38 ,
V_39 , V_24 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_24 [ 0 ] = 0x0 ;
V_5 = F_10 ( V_2 , V_38 ,
V_40 , V_24 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_12 ( V_2 , V_41 ,
V_42 , & V_17 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_17 -> V_27 != V_43 ) {
F_9 ( V_17 ) ;
return - V_44 ;
}
F_13 ( V_45 , L_1 ,
V_46 , 16 , 1 ,
V_17 -> V_29 , V_43 , false ) ;
F_9 ( V_17 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_11 -> V_47 ( V_4 -> V_13 , V_17 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
T_2 V_48 , T_2 V_49 )
{
T_1 V_50 = 0 ;
int V_5 ;
T_1 V_51 [ 2 ] ;
T_1 V_52 ;
T_1 V_53 = 0x3f ;
T_1 V_54 = 0x0f ;
T_1 V_55 = 0x01 ;
F_16 ( V_56 L_2 ,
V_57 , V_48 , V_49 ) ;
V_5 = F_11 ( V_2 , V_35 ,
V_37 , NULL , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_51 [ 0 ] = 0x18 ;
V_51 [ 1 ] = 0x6a ;
V_5 = F_10 ( V_2 , V_38 ,
V_58 , V_51 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_52 = 0 ;
V_5 = F_10 ( V_2 , V_38 ,
V_39 , & V_52 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_48 & ( V_59 | V_60 |
V_61 ) )
V_50 |= 1 ;
if ( V_48 & V_62 ) {
V_50 |= ( 1 << 2 ) ;
V_50 |= ( 1 << 3 ) ;
}
V_50 |= ( 1 << 5 ) ;
V_5 = F_10 ( V_2 , V_38 ,
V_40 , & V_50 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ( V_48 | V_49 ) & V_63 ) {
V_2 -> V_64 = F_17 ( V_2 -> V_65 ,
& V_2 -> V_66 ) ;
F_18 ( L_3 , V_2 -> V_64 ) ;
if ( V_2 -> V_64 == NULL || V_2 -> V_66 == 0 ) {
V_48 &= ~ V_63 ;
V_49 &= ~ V_63 ;
}
}
if ( V_48 & V_63 ) {
V_5 = F_11 ( V_2 ,
V_67 ,
V_37 , NULL , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_10 ( V_2 ,
V_67 ,
V_68 , & V_53 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_10 ( V_2 ,
V_67 ,
V_69 , V_2 -> V_64 , V_2 -> V_66 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_11 ( V_2 ,
V_67 ,
V_70 , NULL , 0 ) ;
if ( V_5 < 0 )
F_11 ( V_2 ,
V_67 ,
V_37 , NULL , 0 ) ;
}
if ( V_49 & V_63 ) {
V_5 = F_10 ( V_2 , V_71 ,
V_68 , & V_54 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_10 ( V_2 , V_71 ,
V_72 , V_2 -> V_64 , V_2 -> V_66 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_10 ( V_2 , V_71 ,
V_73 , & V_55 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_5 = F_11 ( V_2 , V_35 ,
V_70 , NULL , 0 ) ;
if ( V_5 < 0 )
F_11 ( V_2 , V_35 ,
V_37 , NULL , 0 ) ;
return V_5 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_74 * V_75 , T_1 V_76 ,
T_1 * V_64 , T_3 V_66 )
{
struct V_16 * V_77 = NULL ;
int V_5 ;
V_5 = F_12 ( V_2 , V_75 -> V_78 ,
V_72 , & V_77 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_77 -> V_27 == 0 || V_77 -> V_27 > V_79 ) {
V_5 = - V_28 ;
goto exit;
}
F_13 ( V_45 , L_4 , V_80 ,
16 , 1 , V_77 -> V_29 , V_77 -> V_27 , true ) ;
V_5 = F_20 ( V_2 -> V_65 , V_77 -> V_29 ,
V_77 -> V_27 ) ;
if ( V_5 == 0 )
V_5 = F_21 ( V_2 -> V_65 , V_75 -> V_81 , V_76 ,
V_82 ) ;
exit:
F_9 ( V_77 ) ;
return V_5 ;
}
static int F_22 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_67 ,
V_37 , NULL , 0 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_83 ,
struct V_74 * V_75 )
{
switch ( V_83 ) {
case V_84 :
V_75 -> V_85 = V_62 ;
break;
case V_86 :
V_75 -> V_85 = V_61 ;
V_75 -> V_87 = 0x0c00 ;
break;
case V_67 :
V_75 -> V_85 = V_63 ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
T_1 V_83 ,
struct V_74 * V_75 )
{
struct V_16 * V_88 ;
int V_5 = 0 ;
if ( V_83 == V_67 )
return V_5 ;
if ( V_75 -> V_85 & V_63 ) {
V_5 = F_8 ( V_2 ,
V_67 ,
V_89 , NULL , 0 , NULL ) ;
if ( V_5 < 0 )
return V_5 ;
V_75 -> V_78 = V_67 ;
} else if ( V_75 -> V_85 & V_60 ) {
if ( V_75 -> V_90 != 4 && V_75 -> V_90 != 7 &&
V_75 -> V_90 != 10 )
return - V_28 ;
V_5 = F_8 ( V_2 , V_35 ,
V_91 ,
V_75 -> V_92 , V_75 -> V_90 , NULL ) ;
} else if ( V_75 -> V_85 & V_62 ) {
V_5 = F_12 ( V_2 , V_84 ,
V_93 , & V_88 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_88 -> V_27 != 8 ) {
F_9 ( V_88 ) ;
return - V_28 ;
}
if ( ( V_88 -> V_29 [ 0 ] == 0x01 ) && ( V_88 -> V_29 [ 1 ] == 0xfe ) ) {
F_9 ( V_88 ) ;
V_5 = F_8 ( V_2 ,
V_67 ,
V_89 ,
NULL , 0 , NULL ) ;
if ( V_5 < 0 )
return V_5 ;
V_75 -> V_85 = V_63 ;
V_75 -> V_78 =
V_67 ;
} else {
V_5 = F_8 ( V_2 , V_84 ,
V_91 ,
V_88 -> V_29 , V_88 -> V_27 , NULL ) ;
F_9 ( V_88 ) ;
}
} else if ( V_75 -> V_85 & V_59 ) {
if ( V_75 -> V_87 == 0x4403 )
V_5 = F_8 ( V_2 , V_35 ,
V_94 ,
NULL , 0 , NULL ) ;
}
return V_5 ;
}
static void F_25 ( void * V_95 , struct V_16 * V_17 ,
int V_96 )
{
struct V_3 * V_4 = V_95 ;
switch ( V_4 -> V_97 ) {
case V_98 :
if ( V_96 == 0 )
F_26 ( V_17 , 1 ) ;
V_4 -> V_99 ( V_4 -> V_100 , V_17 , V_96 ) ;
break;
default:
if ( V_96 == 0 )
F_9 ( V_17 ) ;
break;
}
}
static int F_27 ( struct V_1 * V_2 ,
struct V_74 * V_75 ,
struct V_16 * V_17 , T_4 V_101 ,
void * V_102 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_16 ( V_56 L_5 , V_57 ,
V_75 -> V_78 ) ;
switch ( V_75 -> V_78 ) {
case V_35 :
if ( V_75 -> V_85 & V_60 ) {
if ( V_17 -> V_27 == V_103 &&
( V_17 -> V_29 [ 0 ] == V_104 ||
V_17 -> V_29 [ 0 ] == V_105 ) ) {
T_1 V_106 [ V_107 ] ;
T_1 * V_29 = V_17 -> V_29 + V_108 ;
memcpy ( V_106 , V_29 + V_109 ,
V_107 ) ;
memmove ( V_29 + V_107 , V_29 ,
V_109 ) ;
memcpy ( V_29 , V_106 , V_107 ) ;
}
return F_28 ( V_2 ,
V_75 -> V_78 ,
V_110 ,
V_17 -> V_29 , V_17 -> V_27 ,
V_101 , V_102 ) ;
} else
return 1 ;
case V_84 :
* F_29 ( V_17 , 1 ) = 0 ;
* F_29 ( V_17 , 1 ) = 0 ;
V_4 -> V_97 = V_98 ;
V_4 -> V_99 = V_101 ;
V_4 -> V_100 = V_102 ;
return F_28 ( V_2 , V_75 -> V_78 ,
V_111 , V_17 -> V_29 ,
V_17 -> V_27 ,
F_25 , V_4 ) ;
case V_86 :
return F_28 ( V_2 , V_75 -> V_78 ,
V_112 , V_17 -> V_29 ,
V_17 -> V_27 , V_101 , V_102 ) ;
case V_67 :
* F_29 ( V_17 , 1 ) = 0 ;
return F_11 ( V_2 , V_75 -> V_78 ,
V_113 , V_17 -> V_29 ,
V_17 -> V_27 ) ;
default:
return 1 ;
}
}
static int F_30 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
int V_5 ;
* F_29 ( V_17 , 1 ) = 0 ;
V_5 = F_11 ( V_2 , V_71 ,
V_113 , V_17 -> V_29 , V_17 -> V_27 ) ;
F_9 ( V_17 ) ;
return V_5 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
F_18 ( L_6 , V_75 -> V_85 ) ;
if ( V_75 -> V_85 & ( V_59 |
V_114 ) ) {
return F_8 ( V_2 , V_75 -> V_78 ,
V_115 ,
NULL , 0 , NULL ) ;
} else if ( V_75 -> V_85 & V_60 ) {
if ( V_75 -> V_90 != 4 && V_75 -> V_90 != 7 &&
V_75 -> V_90 != 10 )
return - V_116 ;
return F_8 ( V_2 , V_35 ,
V_91 ,
V_75 -> V_92 , V_75 -> V_90 , NULL ) ;
} else if ( V_75 -> V_85 & ( V_61 |
V_62 ) ) {
return - V_116 ;
} else if ( V_75 -> V_85 & V_63 ) {
return F_8 ( V_2 , V_75 -> V_78 ,
V_117 ,
NULL , 0 , NULL ) ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , T_1 V_83 , T_1 V_118 ,
struct V_16 * V_17 )
{
struct V_16 * V_77 = NULL ;
int V_5 ;
F_18 ( L_7 , V_118 ) ;
switch ( V_118 ) {
case V_119 :
if ( V_83 == V_67 ) {
V_5 = F_33 ( V_2 , V_83 ) ;
} else if ( V_83 == V_71 ) {
V_5 = F_12 ( V_2 , V_83 , V_69 ,
& V_77 ) ;
if ( V_5 < 0 )
goto exit;
V_5 = F_34 ( V_2 -> V_65 , V_63 ,
V_120 , V_77 -> V_29 ,
V_77 -> V_27 ) ;
F_9 ( V_77 ) ;
} else {
V_5 = - V_44 ;
}
break;
case V_121 :
V_5 = F_11 ( V_2 , V_83 , V_37 ,
NULL , 0 ) ;
break;
case V_122 :
if ( V_17 -> V_27 < 2 ) {
V_5 = - V_28 ;
goto exit;
}
if ( V_17 -> V_29 [ 0 ] != 0 ) {
F_18 ( L_8 , V_17 -> V_29 [ 0 ] ) ;
V_5 = - V_28 ;
goto exit;
}
F_26 ( V_17 , 2 ) ;
return F_35 ( V_2 -> V_65 , V_17 ) ;
default:
return 1 ;
}
exit:
F_9 ( V_17 ) ;
return V_5 ;
}
static int F_36 ( struct V_1 * V_2 ,
const char * V_123 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_124 == NULL )
return - V_125 ;
return V_4 -> V_124 ( V_4 -> V_13 , V_123 , V_2 -> V_126 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
T_2 V_127 = 0 ;
T_1 V_128 = 0x01 ;
struct V_16 * V_23 ;
int V_5 ;
V_5 = F_8 ( V_2 , V_25 , V_129 ,
NULL , 0 , & V_23 ) ;
if ( V_5 == 0 ) {
if ( V_23 -> V_27 == 2 && V_23 -> V_29 [ 0 ] == 0x00 )
F_38 ( V_2 -> V_65 , V_127 ++ , V_130 ) ;
F_9 ( V_23 ) ;
}
V_5 = F_11 ( V_2 , V_131 ,
V_132 ,
& V_128 , 1 ) ;
if ( V_5 == 0 )
F_38 ( V_2 -> V_65 , V_127 ++ , V_133 ) ;
return ! V_127 ;
}
static int F_39 ( struct V_1 * V_2 , T_2 V_127 )
{
struct V_134 * V_135 ;
T_1 V_12 = V_136 ;
static struct V_137 {
T_1 V_138 ;
T_1 V_19 [ 2 ] ;
T_1 V_20 ;
} V_137 [] = {
{ 0x00 , { 0x9e , 0xd9 } , 0x23 } ,
{ 0x00 , { 0x9e , 0xda } , 0x21 } ,
{ 0x00 , { 0x9e , 0xdb } , 0x22 } ,
{ 0x00 , { 0x9e , 0xdc } , 0x24 } ,
} ;
struct V_137 * V_21 = V_137 ;
int V_22 = F_7 ( V_137 ) ;
struct V_16 * V_23 ;
int V_5 ;
V_135 = F_40 ( V_2 -> V_65 , V_127 ) ;
switch ( V_135 -> type ) {
case V_130 :
while ( V_22 -- ) {
V_5 = F_8 ( V_2 , V_25 ,
V_26 , ( T_1 * ) V_21 , 4 , & V_23 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_23 -> V_27 != 1 ) {
F_9 ( V_23 ) ;
return - V_28 ;
}
if ( V_23 -> V_29 [ 0 ] != V_21 -> V_20 ) {
F_9 ( V_23 ) ;
return - V_30 ;
}
F_9 ( V_23 ) ;
V_21 ++ ;
}
return F_10 ( V_2 , V_139 ,
V_140 , & V_12 , 1 ) ;
case V_133 :
return F_10 ( V_2 , V_131 ,
V_141 , & V_12 , 1 ) ;
default:
return - V_44 ;
}
}
static int F_41 ( struct V_1 * V_2 , T_2 V_127 )
{
struct V_134 * V_135 ;
T_1 V_15 = V_142 ;
V_135 = F_40 ( V_2 -> V_65 , V_127 ) ;
switch ( V_135 -> type ) {
case V_130 :
return F_10 ( V_2 , V_139 ,
V_140 , & V_15 , 1 ) ;
case V_133 :
return F_10 ( V_2 , V_131 ,
V_141 , & V_15 , 1 ) ;
default:
return - V_44 ;
}
}
int F_42 ( void * V_13 , struct V_143 * V_11 , char * V_144 ,
int V_145 , int V_146 , int V_147 ,
T_5 V_124 , struct V_1 * * V_2 )
{
struct V_3 * V_4 ;
T_2 V_148 ;
struct V_149 V_150 ;
int V_5 ;
V_4 = F_43 ( sizeof( struct V_3 ) , V_151 ) ;
if ( ! V_4 ) {
V_5 = - V_152 ;
goto V_153;
}
V_4 -> V_11 = V_11 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_124 = V_124 ;
V_4 -> V_7 = V_8 ;
F_44 ( & V_4 -> V_6 ) ;
V_150 . V_154 = F_7 ( V_155 ) ;
memcpy ( V_150 . V_156 , V_155 , sizeof( V_155 ) ) ;
strcpy ( V_150 . V_157 , L_9 ) ;
V_148 = V_61 |
V_60 |
V_62 |
V_59 |
V_114 |
V_63 ;
V_4 -> V_2 = F_45 ( & V_158 , & V_150 , 0 ,
V_148 , V_144 ,
V_145 + V_159 ,
V_146 , V_147 ) ;
if ( ! V_4 -> V_2 ) {
F_46 ( L_10 ) ;
V_5 = - V_152 ;
goto V_160;
}
F_47 ( V_4 -> V_2 , V_4 ) ;
V_5 = F_48 ( V_4 -> V_2 ) ;
if ( V_5 )
goto V_161;
* V_2 = V_4 -> V_2 ;
return 0 ;
V_161:
F_49 ( V_4 -> V_2 ) ;
V_160:
F_50 ( V_4 ) ;
V_153:
return V_5 ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_52 ( V_2 ) ;
F_49 ( V_2 ) ;
F_50 ( V_4 ) ;
}

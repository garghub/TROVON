static void F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 , V_5 ;
char V_6 [] = { 0x05 , 0xF9 , 0x04 , 0x00 , 0xC3 , 0xE5 } ;
int V_7 = sizeof( V_6 ) ;
F_2 ( V_8 L_1 , V_9 ) ;
F_3 ( & V_2 -> V_10 -> V_11 , L_2 ) ;
F_4 ( V_2 -> V_12 , 0 ) ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_2 -> V_13 = V_3 ;
V_4 = 3 ;
while ( V_4 -- ) {
F_4 ( V_2 -> V_14 , ! V_2 -> V_13 ) ;
F_5 ( 10000 , 15000 ) ;
F_4 ( V_2 -> V_14 , V_2 -> V_13 ) ;
F_5 ( 10000 , 15000 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_3 ) ;
V_5 = F_7 ( V_2 -> V_10 , V_6 , V_7 ) ;
if ( V_5 == V_7 ) {
F_3 ( & V_2 -> V_10 -> V_11 ,
L_4 ,
( V_3 == 0 ? L_5 : L_6 ) ) ;
goto V_15;
}
}
}
F_8 ( & V_2 -> V_10 -> V_11 ,
L_7 ) ;
V_15:
F_4 ( V_2 -> V_14 , ! V_2 -> V_13 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_16 )
{
F_2 ( V_8 L_1 , V_9 ) ;
F_4 ( V_2 -> V_12 , 0 ) ;
F_4 ( V_2 -> V_14 , V_2 -> V_13 ) ;
F_5 ( 10000 , 15000 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_2 ( V_8 L_1 , V_9 ) ;
F_4 ( V_2 -> V_12 , 0 ) ;
F_4 ( V_2 -> V_14 , ! V_2 -> V_13 ) ;
F_5 ( 10000 , 15000 ) ;
F_4 ( V_2 -> V_14 , V_2 -> V_13 ) ;
F_5 ( 10000 , 15000 ) ;
F_4 ( V_2 -> V_14 , ! V_2 -> V_13 ) ;
F_5 ( 10000 , 15000 ) ;
}
static int F_11 ( struct V_17 * V_18 , T_1 * V_19 , int V_20 )
{
int V_21 ;
F_5 ( 3000 , 6000 ) ;
V_21 = F_7 ( V_18 , V_19 , V_20 ) ;
if ( V_21 == - V_22 ) {
F_5 ( 6000 , 10000 ) ;
V_21 = F_7 ( V_18 , V_19 , V_20 ) ;
}
if ( V_21 >= 0 && V_21 != V_20 )
V_21 = - V_22 ;
return V_21 ;
}
static int F_12 ( T_1 * V_19 , int V_23 )
{
int V_20 ;
T_2 V_24 ;
V_20 = V_19 [ 0 ] + 1 ;
V_24 = F_13 ( 0xffff , V_19 , V_20 - 2 ) ;
V_24 = ~ V_24 ;
if ( V_19 [ V_20 - 2 ] != ( V_24 & 0xff ) || V_19 [ V_20 - 1 ] != ( V_24 >> 8 ) ) {
F_14 ( V_25 L_8 ,
V_24 , V_19 [ V_20 - 1 ] , V_19 [ V_20 - 2 ] ) ;
F_2 ( V_8 L_9 , V_9 ) ;
F_15 ( V_26 , L_10 , V_27 ,
16 , 2 , V_19 , V_23 , false ) ;
return - V_28 ;
}
return 0 ;
}
static int F_16 ( struct V_17 * V_18 , struct V_29 * * V_30 )
{
int V_21 ;
T_1 V_20 ;
T_1 V_31 [ V_32 - 1 ] ;
V_21 = F_17 ( V_18 , & V_20 , 1 ) ;
if ( V_21 != 1 ) {
F_8 ( & V_18 -> V_11 , L_11 ) ;
return - V_22 ;
}
if ( ( V_20 < ( V_33 - 1 ) ) ||
( V_20 > ( V_32 - 1 ) ) ) {
F_8 ( & V_18 -> V_11 , L_12 ) ;
V_21 = - V_34 ;
goto V_35;
}
* V_30 = F_18 ( 1 + V_20 , V_36 ) ;
if ( * V_30 == NULL ) {
V_21 = - V_37 ;
goto V_35;
}
* F_19 ( * V_30 , 1 ) = V_20 ;
V_21 = F_17 ( V_18 , F_19 ( * V_30 , V_20 ) , V_20 ) ;
if ( V_21 != V_20 ) {
F_20 ( * V_30 ) ;
return - V_22 ;
}
V_21 = F_12 ( ( * V_30 ) -> V_38 , ( * V_30 ) -> V_20 ) ;
if ( V_21 != 0 ) {
F_20 ( * V_30 ) ;
V_21 = - V_34 ;
goto V_35;
}
F_21 ( * V_30 , 1 ) ;
F_22 ( * V_30 , ( * V_30 ) -> V_20 - 2 ) ;
F_5 ( 3000 , 6000 ) ;
return 0 ;
V_35:
if ( F_17 ( V_18 , V_31 , sizeof( V_31 ) ) < 0 )
V_21 = - V_22 ;
F_5 ( 3000 , 6000 ) ;
return V_21 ;
}
static T_3 F_23 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
struct V_17 * V_18 = V_2 -> V_10 ;
struct V_29 * V_30 = NULL ;
int V_21 ;
F_24 ( ! V_2 ) ;
F_24 ( V_39 != V_2 -> V_10 -> V_39 ) ;
F_6 ( & V_18 -> V_11 , L_13 ) ;
if ( V_2 -> V_41 != 0 )
return V_42 ;
V_21 = F_16 ( V_18 , & V_30 ) ;
if ( V_21 == - V_22 ) {
V_2 -> V_41 = V_21 ;
F_25 ( V_2 -> V_43 , NULL ) ;
return V_42 ;
} else if ( ( V_21 == - V_37 ) || ( V_21 == - V_34 ) ) {
return V_42 ;
}
F_25 ( V_2 -> V_43 , V_30 ) ;
return V_42 ;
}
static int F_26 ( struct V_44 * V_43 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
int V_21 = 0 ;
F_28 ( & V_2 -> V_45 ) ;
if ( V_2 -> V_46 != V_47 ) {
V_21 = - V_48 ;
goto V_15;
}
V_21 = F_9 ( V_2 , V_49 ) ;
if ( V_21 == 0 )
V_2 -> V_46 = V_50 ;
V_15:
F_29 ( & V_2 -> V_45 ) ;
return V_21 ;
}
static void F_30 ( struct V_44 * V_43 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
F_28 ( & V_2 -> V_45 ) ;
if ( V_2 -> V_46 == V_47 )
goto V_15;
F_10 ( V_2 ) ;
V_2 -> V_46 = V_47 ;
V_15:
F_29 ( & V_2 -> V_45 ) ;
}
static int F_31 ( struct V_44 * V_43 )
{
struct V_51 * V_52 = F_32 ( V_43 ) ;
struct V_29 * V_30 ;
static struct V_53 {
T_1 V_54 [ 2 ] ;
T_1 V_55 ;
} V_53 [] = {
{ { 0x9f , 0x9a } , 0x00 } ,
{ { 0x98 , 0x10 } , 0xbc } ,
{ { 0x9e , 0x71 } , 0x00 } ,
{ { 0x98 , 0x09 } , 0x00 } ,
{ { 0x9e , 0xb4 } , 0x00 } ,
{ { 0x9e , 0xd9 } , 0xff } ,
{ { 0x9e , 0xda } , 0xff } ,
{ { 0x9e , 0xdb } , 0x23 } ,
{ { 0x9e , 0xdc } , 0x21 } ,
{ { 0x9e , 0xdd } , 0x22 } ,
{ { 0x9e , 0xde } , 0x24 } ,
{ { 0x9c , 0x01 } , 0x08 } ,
{ { 0x9e , 0xaa } , 0x01 } ,
{ { 0x9b , 0xd1 } , 0x0d } ,
{ { 0x9b , 0xd2 } , 0x24 } ,
{ { 0x9b , 0xd3 } , 0x0a } ,
{ { 0x9b , 0xd4 } , 0x22 } ,
{ { 0x9b , 0xd5 } , 0x08 } ,
{ { 0x9b , 0xd6 } , 0x1e } ,
{ { 0x9b , 0xdd } , 0x1c } ,
{ { 0x9b , 0x84 } , 0x13 } ,
{ { 0x99 , 0x81 } , 0x7f } ,
{ { 0x99 , 0x31 } , 0x70 } ,
{ { 0x98 , 0x00 } , 0x3f } ,
{ { 0x9f , 0x09 } , 0x00 } ,
{ { 0x9f , 0x0a } , 0x05 } ,
{ { 0x9e , 0xd1 } , 0xa1 } ,
{ { 0x99 , 0x23 } , 0x00 } ,
{ { 0x9e , 0x74 } , 0x80 } ,
{ { 0x9f , 0x28 } , 0x10 } ,
{ { 0x9f , 0x35 } , 0x14 } ,
{ { 0x9f , 0x36 } , 0x60 } ,
{ { 0x9c , 0x31 } , 0x00 } ,
{ { 0x9c , 0x32 } , 0xc8 } ,
{ { 0x9c , 0x19 } , 0x40 } ,
{ { 0x9c , 0x1a } , 0x40 } ,
{ { 0x9c , 0x0c } , 0x00 } ,
{ { 0x9c , 0x0d } , 0x00 } ,
{ { 0x9c , 0x12 } , 0x00 } ,
{ { 0x9c , 0x13 } , 0x00 } ,
{ { 0x98 , 0xa2 } , 0x0e } ,
{ { 0x98 , 0x93 } , 0x40 } ,
{ { 0x98 , 0x7d } , 0x02 } ,
{ { 0x98 , 0x7e } , 0x00 } ,
{ { 0x9f , 0xc8 } , 0x01 } ,
} ;
struct V_53 * V_56 = V_53 ;
int V_7 = F_33 ( V_53 ) ;
struct V_29 * V_57 ;
T_1 V_58 [ 4 ] ;
int V_21 ;
V_58 [ 0 ] = 0 ;
while ( V_7 -- ) {
V_58 [ 1 ] = V_56 -> V_54 [ 0 ] ;
V_58 [ 2 ] = V_56 -> V_54 [ 1 ] ;
V_58 [ 3 ] = V_56 -> V_55 ;
V_21 = F_34 ( V_52 , V_59 , V_60 ,
V_58 , 4 , & V_57 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_57 -> V_20 != 1 ) {
F_20 ( V_57 ) ;
return - V_61 ;
}
if ( V_57 -> V_38 [ 0 ] != V_56 -> V_55 ) {
F_20 ( V_57 ) ;
return - V_62 ;
}
F_20 ( V_57 ) ;
V_56 ++ ;
}
V_58 [ 0 ] = V_63 ;
V_21 = F_35 ( V_52 , V_64 ,
V_65 , V_58 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_58 [ 0 ] = 0x3d ;
V_21 = F_35 ( V_52 , V_59 ,
V_66 , V_58 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_58 [ 0 ] = 0x0 ;
V_21 = F_35 ( V_52 , V_67 ,
V_68 , V_58 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_36 ( V_52 , V_67 ,
V_69 , NULL , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_58 [ 0 ] = 0x1 ;
V_21 = F_35 ( V_52 , V_70 ,
V_71 , V_58 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_58 [ 0 ] = 0x0 ;
V_21 = F_35 ( V_52 , V_70 ,
V_72 , V_58 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_37 ( V_52 , V_73 ,
V_74 , & V_30 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_30 -> V_20 != V_75 ) {
F_20 ( V_30 ) ;
return - V_76 ;
}
F_15 ( V_26 , L_14 ,
V_27 , 16 , 1 ,
V_30 -> V_38 , V_75 , false ) ;
F_20 ( V_30 ) ;
return 0 ;
}
static int F_38 ( struct V_44 * V_43 , struct V_29 * V_30 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
struct V_17 * V_18 = V_2 -> V_10 ;
if ( V_2 -> V_41 != 0 )
return V_2 -> V_41 ;
return F_11 ( V_18 , V_30 -> V_38 , V_30 -> V_20 ) ;
}
static int F_39 ( struct V_44 * V_43 ,
T_4 V_77 , T_4 V_78 )
{
struct V_51 * V_52 = F_32 ( V_43 ) ;
T_1 V_79 = 0 ;
int V_21 ;
T_1 V_80 [ 2 ] ;
T_1 V_81 ;
F_2 ( V_8 L_15 ,
V_9 , V_77 , V_78 ) ;
V_21 = F_36 ( V_52 , V_67 ,
V_69 , NULL , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_80 [ 0 ] = 0x18 ;
V_80 [ 1 ] = 0x6a ;
V_21 = F_35 ( V_52 , V_70 ,
V_82 , V_80 , 2 ) ;
if ( V_21 < 0 )
return V_21 ;
V_81 = 0 ;
V_21 = F_35 ( V_52 , V_70 ,
V_71 , & V_81 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_77 & ( V_83 | V_84 |
V_85 ) )
V_79 |= 1 ;
if ( V_77 & V_86 ) {
V_79 |= ( 1 << 2 ) ;
V_79 |= ( 1 << 3 ) ;
}
V_79 |= ( 1 << 5 ) ;
V_21 = F_35 ( V_52 , V_70 ,
V_72 , & V_79 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_36 ( V_52 , V_67 ,
V_87 , NULL , 0 ) ;
if ( V_21 < 0 )
F_36 ( V_52 , V_67 ,
V_69 , NULL , 0 ) ;
return V_21 ;
}
static int F_40 ( struct V_44 * V_43 , T_1 V_88 ,
struct V_89 * V_90 )
{
switch ( V_88 ) {
case V_91 :
V_90 -> V_92 = V_86 ;
break;
case V_93 :
V_90 -> V_92 = V_85 ;
V_90 -> V_94 = 0x0c00 ;
break;
default:
return - V_61 ;
}
return 0 ;
}
static int F_41 ( struct V_44 * V_43 ,
T_1 V_88 ,
struct V_89 * V_90 )
{
struct V_51 * V_52 = F_32 ( V_43 ) ;
struct V_29 * V_95 ;
int V_21 = 0 ;
if ( V_90 -> V_92 & V_84 ) {
if ( V_90 -> V_96 != 4 && V_90 -> V_96 != 7 &&
V_90 -> V_96 != 10 )
return - V_61 ;
V_21 = F_34 ( V_52 , V_67 ,
V_97 ,
V_90 -> V_98 , V_90 -> V_96 , NULL ) ;
} else if ( V_90 -> V_92 & V_86 ) {
V_21 = F_37 ( V_52 , V_91 ,
V_99 , & V_95 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_95 -> V_20 != 8 ) {
F_20 ( V_95 ) ;
return - V_61 ;
}
V_21 = F_34 ( V_52 , V_91 ,
V_97 ,
V_95 -> V_38 , V_95 -> V_20 , NULL ) ;
F_20 ( V_95 ) ;
} else if ( V_90 -> V_92 & V_83 ) {
if ( V_90 -> V_94 == 0x4403 )
V_21 = F_34 ( V_52 , V_67 ,
V_100 ,
NULL , 0 , NULL ) ;
}
return V_21 ;
}
static int F_42 ( struct V_44 * V_43 ,
struct V_89 * V_90 ,
struct V_29 * V_30 ,
struct V_29 * * V_57 )
{
struct V_51 * V_52 = F_32 ( V_43 ) ;
int V_21 ;
F_2 ( V_8 L_16 , V_9 ,
V_90 -> V_101 ) ;
switch ( V_90 -> V_101 ) {
case V_67 :
if ( V_90 -> V_92 & V_84 ) {
if ( V_30 -> V_20 == V_102 &&
( V_30 -> V_38 [ 0 ] == V_103 ||
V_30 -> V_38 [ 0 ] == V_104 ) ) {
T_1 V_105 [ V_106 ] ;
T_1 * V_38 = V_30 -> V_38 + V_107 ;
memcpy ( V_105 , V_38 + V_108 ,
V_106 ) ;
memmove ( V_38 + V_106 , V_38 ,
V_108 ) ;
memcpy ( V_38 , V_105 , V_106 ) ;
}
return F_34 ( V_52 , V_90 -> V_101 ,
V_109 ,
V_30 -> V_38 , V_30 -> V_20 , V_57 ) ;
} else
return 1 ;
case V_91 :
* F_43 ( V_30 , 1 ) = 0 ;
* F_43 ( V_30 , 1 ) = 0 ;
V_21 = F_34 ( V_52 , V_90 -> V_101 ,
V_110 ,
V_30 -> V_38 , V_30 -> V_20 , V_57 ) ;
if ( V_21 == 0 )
F_21 ( * V_57 , 1 ) ;
return V_21 ;
case V_93 :
return F_34 ( V_52 , V_90 -> V_101 ,
V_111 ,
V_30 -> V_38 , V_30 -> V_20 , V_57 ) ;
default:
return 1 ;
}
}
static int F_44 ( struct V_44 * V_43 ,
struct V_89 * V_90 )
{
struct V_51 * V_52 = F_32 ( V_43 ) ;
return F_34 ( V_52 , V_90 -> V_101 ,
V_112 ,
NULL , 0 , NULL ) ;
}
static int T_5 F_45 ( struct V_17 * V_18 ,
const struct V_113 * V_114 )
{
struct V_1 * V_2 ;
struct V_115 * V_116 ;
int V_21 = 0 ;
T_4 V_117 ;
struct V_118 V_119 ;
F_6 ( & V_18 -> V_11 , L_17 , V_9 ) ;
F_6 ( & V_18 -> V_11 , L_18 , V_18 -> V_39 ) ;
if ( ! F_46 ( V_18 -> V_120 , V_121 ) ) {
F_8 ( & V_18 -> V_11 , L_19 ) ;
return - V_122 ;
}
V_2 = F_47 ( sizeof( struct V_1 ) , V_36 ) ;
if ( ! V_2 ) {
F_8 ( & V_18 -> V_11 ,
L_20 ) ;
V_21 = - V_37 ;
goto V_123;
}
V_2 -> V_10 = V_18 ;
V_2 -> V_46 = V_47 ;
F_48 ( & V_2 -> V_45 ) ;
F_49 ( V_18 , V_2 ) ;
V_116 = V_18 -> V_11 . V_124 ;
if ( V_116 == NULL ) {
F_8 ( & V_18 -> V_11 , L_21 ) ;
V_21 = - V_76 ;
goto V_125;
}
if ( V_116 -> V_126 == NULL ) {
F_8 ( & V_18 -> V_11 , L_22 ) ;
V_21 = - V_76 ;
goto V_125;
}
V_21 = V_116 -> V_126 ( V_18 ) ;
if ( V_21 ) {
F_8 ( & V_18 -> V_11 , L_23 ) ;
goto V_125;
}
V_2 -> V_14 = V_116 -> V_127 ( V_128 ) ;
V_2 -> V_12 = V_116 -> V_127 ( V_129 ) ;
V_2 -> V_130 = V_116 -> V_127 ( V_131 ) ;
F_1 ( V_2 ) ;
V_21 = F_50 ( V_18 -> V_39 , NULL , F_23 ,
V_132 , V_25 ,
V_2 ) ;
if ( V_21 < 0 ) {
F_8 ( & V_18 -> V_11 , L_24 ) ;
goto V_133;
}
V_119 . V_134 = F_33 ( V_135 ) ;
memcpy ( V_119 . V_136 , V_135 , sizeof( V_135 ) ) ;
strcpy ( V_119 . V_137 , L_25 ) ;
V_117 = V_85 |
V_84 |
V_86 |
V_83 |
V_138 |
V_139 ;
V_2 -> V_43 = F_51 ( & V_140 ,
& V_119 , V_117 ,
V_141 , 0 ,
V_142 ,
F_52 ( & V_18 -> V_11 ) ) ;
if ( ! V_2 -> V_43 ) {
F_8 ( & V_18 -> V_11 , L_26 ) ;
V_21 = - V_37 ;
goto V_143;
}
F_53 ( V_2 -> V_43 , V_2 ) ;
return 0 ;
V_143:
F_54 ( V_18 -> V_39 , V_2 ) ;
V_133:
if ( V_116 -> V_144 != NULL )
V_116 -> V_144 () ;
V_125:
F_55 ( V_2 ) ;
V_123:
return V_21 ;
}
static T_6 int F_56 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_57 ( V_18 ) ;
struct V_115 * V_116 = V_18 -> V_11 . V_124 ;
F_6 ( & V_18 -> V_11 , L_17 , V_9 ) ;
F_58 ( V_2 -> V_43 ) ;
if ( V_2 -> V_46 != V_47 ) {
if ( V_116 -> V_145 )
V_116 -> V_145 () ;
}
F_54 ( V_18 -> V_39 , V_2 ) ;
if ( V_116 -> V_144 )
V_116 -> V_144 () ;
F_55 ( V_2 ) ;
return 0 ;
}
static int T_7 F_59 ( void )
{
int V_21 ;
F_60 ( V_8 L_1 , V_9 ) ;
V_21 = F_61 ( & V_146 ) ;
if ( V_21 ) {
F_14 ( V_25 L_27 ) ;
return V_21 ;
}
return 0 ;
}
static void T_8 F_62 ( void )
{
F_63 ( & V_146 ) ;
}

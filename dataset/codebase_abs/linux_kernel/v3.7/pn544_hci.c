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
if ( V_21 >= 0 ) {
if ( V_21 != V_20 )
return - V_22 ;
else
return 0 ;
}
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
struct V_17 * V_18 ;
struct V_29 * V_30 = NULL ;
int V_21 ;
if ( ! V_2 || V_39 != V_2 -> V_10 -> V_39 ) {
F_24 ( 1 ) ;
return V_41 ;
}
V_18 = V_2 -> V_10 ;
F_6 ( & V_18 -> V_11 , L_13 ) ;
if ( V_2 -> V_42 != 0 )
return V_43 ;
V_21 = F_16 ( V_18 , & V_30 ) ;
if ( V_21 == - V_22 ) {
V_2 -> V_42 = V_21 ;
F_25 ( V_2 -> V_44 , NULL ) ;
return V_43 ;
} else if ( ( V_21 == - V_37 ) || ( V_21 == - V_34 ) ) {
return V_43 ;
}
F_25 ( V_2 -> V_44 , V_30 ) ;
return V_43 ;
}
static int F_26 ( struct V_45 * V_44 )
{
struct V_1 * V_2 = F_27 ( V_44 ) ;
int V_21 = 0 ;
F_28 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_47 != V_48 ) {
V_21 = - V_49 ;
goto V_15;
}
V_21 = F_9 ( V_2 , V_50 ) ;
if ( V_21 == 0 )
V_2 -> V_47 = V_51 ;
V_15:
F_29 ( & V_2 -> V_46 ) ;
return V_21 ;
}
static void F_30 ( struct V_45 * V_44 )
{
struct V_1 * V_2 = F_27 ( V_44 ) ;
F_28 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_47 == V_48 )
goto V_15;
F_10 ( V_2 ) ;
V_2 -> V_47 = V_48 ;
V_15:
F_29 ( & V_2 -> V_46 ) ;
}
static int F_31 ( struct V_45 * V_44 )
{
struct V_29 * V_30 ;
static struct V_52 {
T_1 V_53 [ 2 ] ;
T_1 V_54 ;
} V_52 [] = {
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
struct V_52 * V_55 = V_52 ;
int V_7 = F_32 ( V_52 ) ;
struct V_29 * V_56 ;
T_1 V_57 [ 4 ] ;
int V_21 ;
V_57 [ 0 ] = 0 ;
while ( V_7 -- ) {
V_57 [ 1 ] = V_55 -> V_53 [ 0 ] ;
V_57 [ 2 ] = V_55 -> V_53 [ 1 ] ;
V_57 [ 3 ] = V_55 -> V_54 ;
V_21 = F_33 ( V_44 , V_58 , V_59 ,
V_57 , 4 , & V_56 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_56 -> V_20 != 1 ) {
F_20 ( V_56 ) ;
return - V_60 ;
}
if ( V_56 -> V_38 [ 0 ] != V_55 -> V_54 ) {
F_20 ( V_56 ) ;
return - V_61 ;
}
F_20 ( V_56 ) ;
V_55 ++ ;
}
V_57 [ 0 ] = V_62 ;
V_21 = F_34 ( V_44 , V_63 ,
V_64 , V_57 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_57 [ 0 ] = 0x3d ;
V_21 = F_34 ( V_44 , V_58 ,
V_65 , V_57 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_57 [ 0 ] = 0x0 ;
V_21 = F_34 ( V_44 , V_66 ,
V_67 , V_57 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_35 ( V_44 , V_66 ,
V_68 , NULL , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_57 [ 0 ] = 0x1 ;
V_21 = F_34 ( V_44 , V_69 ,
V_70 , V_57 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_57 [ 0 ] = 0x0 ;
V_21 = F_34 ( V_44 , V_69 ,
V_71 , V_57 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_36 ( V_44 , V_72 ,
V_73 , & V_30 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_30 -> V_20 != V_74 ) {
F_20 ( V_30 ) ;
return - V_75 ;
}
F_15 ( V_26 , L_14 ,
V_27 , 16 , 1 ,
V_30 -> V_38 , V_74 , false ) ;
F_20 ( V_30 ) ;
return 0 ;
}
static void F_37 ( struct V_29 * V_30 )
{
T_2 V_24 ;
int V_20 ;
V_20 = V_30 -> V_20 + 2 ;
* F_38 ( V_30 , 1 ) = V_20 ;
V_24 = F_13 ( 0xffff , V_30 -> V_38 , V_30 -> V_20 ) ;
V_24 = ~ V_24 ;
* F_19 ( V_30 , 1 ) = V_24 & 0xff ;
* F_19 ( V_30 , 1 ) = V_24 >> 8 ;
}
static void F_39 ( struct V_29 * V_30 )
{
F_21 ( V_30 , V_76 ) ;
F_22 ( V_30 , V_77 ) ;
}
static int F_40 ( struct V_45 * V_44 , struct V_29 * V_30 )
{
struct V_1 * V_2 = F_27 ( V_44 ) ;
struct V_17 * V_18 = V_2 -> V_10 ;
int V_21 ;
if ( V_2 -> V_42 != 0 )
return V_2 -> V_42 ;
F_37 ( V_30 ) ;
V_21 = F_11 ( V_18 , V_30 -> V_38 , V_30 -> V_20 ) ;
F_39 ( V_30 ) ;
return V_21 ;
}
static int F_41 ( struct V_45 * V_44 ,
T_4 V_78 , T_4 V_79 )
{
T_1 V_80 = 0 ;
int V_21 ;
T_1 V_81 [ 2 ] ;
T_1 V_82 ;
F_2 ( V_8 L_15 ,
V_9 , V_78 , V_79 ) ;
V_21 = F_35 ( V_44 , V_66 ,
V_68 , NULL , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_81 [ 0 ] = 0x18 ;
V_81 [ 1 ] = 0x6a ;
V_21 = F_34 ( V_44 , V_69 ,
V_83 , V_81 , 2 ) ;
if ( V_21 < 0 )
return V_21 ;
V_82 = 0 ;
V_21 = F_34 ( V_44 , V_69 ,
V_70 , & V_82 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_78 & ( V_84 | V_85 |
V_86 ) )
V_80 |= 1 ;
if ( V_78 & V_87 ) {
V_80 |= ( 1 << 2 ) ;
V_80 |= ( 1 << 3 ) ;
}
V_80 |= ( 1 << 5 ) ;
V_21 = F_34 ( V_44 , V_69 ,
V_71 , & V_80 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_35 ( V_44 , V_66 ,
V_88 , NULL , 0 ) ;
if ( V_21 < 0 )
F_35 ( V_44 , V_66 ,
V_68 , NULL , 0 ) ;
return V_21 ;
}
static int F_42 ( struct V_45 * V_44 , T_1 V_89 ,
struct V_90 * V_91 )
{
switch ( V_89 ) {
case V_92 :
V_91 -> V_93 = V_87 ;
break;
case V_94 :
V_91 -> V_93 = V_86 ;
V_91 -> V_95 = 0x0c00 ;
break;
default:
return - V_60 ;
}
return 0 ;
}
static int F_43 ( struct V_45 * V_44 ,
T_1 V_89 ,
struct V_90 * V_91 )
{
struct V_29 * V_96 ;
int V_21 = 0 ;
if ( V_91 -> V_93 & V_85 ) {
if ( V_91 -> V_97 != 4 && V_91 -> V_97 != 7 &&
V_91 -> V_97 != 10 )
return - V_60 ;
V_21 = F_33 ( V_44 , V_66 ,
V_98 ,
V_91 -> V_99 , V_91 -> V_97 , NULL ) ;
} else if ( V_91 -> V_93 & V_87 ) {
V_21 = F_36 ( V_44 , V_92 ,
V_100 , & V_96 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_96 -> V_20 != 8 ) {
F_20 ( V_96 ) ;
return - V_60 ;
}
V_21 = F_33 ( V_44 , V_92 ,
V_98 ,
V_96 -> V_38 , V_96 -> V_20 , NULL ) ;
F_20 ( V_96 ) ;
} else if ( V_91 -> V_93 & V_84 ) {
if ( V_91 -> V_95 == 0x4403 )
V_21 = F_33 ( V_44 , V_66 ,
V_101 ,
NULL , 0 , NULL ) ;
}
return V_21 ;
}
static void F_44 ( void * V_102 , struct V_29 * V_30 ,
int V_103 )
{
struct V_1 * V_2 = V_102 ;
switch ( V_2 -> V_104 ) {
case V_105 :
if ( V_103 == 0 )
F_21 ( V_30 , 1 ) ;
V_2 -> V_106 ( V_2 -> V_107 , V_30 , V_103 ) ;
break;
default:
if ( V_103 == 0 )
F_20 ( V_30 ) ;
break;
}
}
static int F_45 ( struct V_45 * V_44 ,
struct V_90 * V_91 ,
struct V_29 * V_30 , T_5 V_108 ,
void * V_109 )
{
struct V_1 * V_2 = F_27 ( V_44 ) ;
F_2 ( V_8 L_16 , V_9 ,
V_91 -> V_110 ) ;
switch ( V_91 -> V_110 ) {
case V_66 :
if ( V_91 -> V_93 & V_85 ) {
if ( V_30 -> V_20 == V_111 &&
( V_30 -> V_38 [ 0 ] == V_112 ||
V_30 -> V_38 [ 0 ] == V_113 ) ) {
T_1 V_114 [ V_115 ] ;
T_1 * V_38 = V_30 -> V_38 + V_116 ;
memcpy ( V_114 , V_38 + V_117 ,
V_115 ) ;
memmove ( V_38 + V_115 , V_38 ,
V_117 ) ;
memcpy ( V_38 , V_114 , V_115 ) ;
}
return F_46 ( V_44 ,
V_91 -> V_110 ,
V_118 ,
V_30 -> V_38 , V_30 -> V_20 ,
V_108 , V_109 ) ;
} else
return 1 ;
case V_92 :
* F_38 ( V_30 , 1 ) = 0 ;
* F_38 ( V_30 , 1 ) = 0 ;
V_2 -> V_104 = V_105 ;
V_2 -> V_106 = V_108 ;
V_2 -> V_107 = V_109 ;
return F_46 ( V_44 , V_91 -> V_110 ,
V_119 , V_30 -> V_38 ,
V_30 -> V_20 ,
F_44 , V_2 ) ;
case V_94 :
return F_46 ( V_44 , V_91 -> V_110 ,
V_120 , V_30 -> V_38 ,
V_30 -> V_20 , V_108 , V_109 ) ;
default:
return 1 ;
}
}
static int F_47 ( struct V_45 * V_44 ,
struct V_90 * V_91 )
{
return F_33 ( V_44 , V_91 -> V_110 ,
V_121 ,
NULL , 0 , NULL ) ;
}
static int T_6 F_48 ( struct V_17 * V_18 ,
const struct V_122 * V_123 )
{
struct V_1 * V_2 ;
struct V_124 * V_125 ;
int V_21 = 0 ;
T_4 V_126 ;
struct V_127 V_128 ;
F_6 ( & V_18 -> V_11 , L_17 , V_9 ) ;
F_6 ( & V_18 -> V_11 , L_18 , V_18 -> V_39 ) ;
if ( ! F_49 ( V_18 -> V_129 , V_130 ) ) {
F_8 ( & V_18 -> V_11 , L_19 ) ;
return - V_131 ;
}
V_2 = F_50 ( sizeof( struct V_1 ) , V_36 ) ;
if ( ! V_2 ) {
F_8 ( & V_18 -> V_11 ,
L_20 ) ;
V_21 = - V_37 ;
goto V_132;
}
V_2 -> V_10 = V_18 ;
V_2 -> V_47 = V_48 ;
F_51 ( & V_2 -> V_46 ) ;
F_52 ( V_18 , V_2 ) ;
V_125 = V_18 -> V_11 . V_133 ;
if ( V_125 == NULL ) {
F_8 ( & V_18 -> V_11 , L_21 ) ;
V_21 = - V_75 ;
goto V_134;
}
if ( V_125 -> V_135 == NULL ) {
F_8 ( & V_18 -> V_11 , L_22 ) ;
V_21 = - V_75 ;
goto V_134;
}
V_21 = V_125 -> V_135 ( V_18 ) ;
if ( V_21 ) {
F_8 ( & V_18 -> V_11 , L_23 ) ;
goto V_134;
}
V_2 -> V_14 = V_125 -> V_136 ( V_137 ) ;
V_2 -> V_12 = V_125 -> V_136 ( V_138 ) ;
V_2 -> V_139 = V_125 -> V_136 ( V_140 ) ;
F_1 ( V_2 ) ;
V_21 = F_53 ( V_18 -> V_39 , NULL , F_23 ,
V_141 | V_142 ,
V_25 , V_2 ) ;
if ( V_21 < 0 ) {
F_8 ( & V_18 -> V_11 , L_24 ) ;
goto V_143;
}
V_128 . V_144 = F_32 ( V_145 ) ;
memcpy ( V_128 . V_146 , V_145 , sizeof( V_145 ) ) ;
strcpy ( V_128 . V_147 , L_25 ) ;
V_126 = V_86 |
V_85 |
V_87 |
V_84 |
V_148 |
V_149 ;
V_2 -> V_44 = F_54 ( & V_150 , & V_128 ,
V_126 , V_151 ,
V_76 +
V_152 ,
V_77 ,
V_153 ) ;
if ( ! V_2 -> V_44 ) {
F_8 ( & V_18 -> V_11 , L_26 ) ;
V_21 = - V_37 ;
goto V_154;
}
F_55 ( V_2 -> V_44 , V_2 ) ;
V_21 = F_56 ( V_2 -> V_44 ) ;
if ( V_21 )
goto V_155;
return 0 ;
V_155:
F_57 ( V_2 -> V_44 ) ;
V_154:
F_58 ( V_18 -> V_39 , V_2 ) ;
V_143:
if ( V_125 -> V_156 != NULL )
V_125 -> V_156 () ;
V_134:
F_59 ( V_2 ) ;
V_132:
return V_21 ;
}
static T_7 int F_60 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
struct V_124 * V_125 = V_18 -> V_11 . V_133 ;
F_6 ( & V_18 -> V_11 , L_17 , V_9 ) ;
F_57 ( V_2 -> V_44 ) ;
if ( V_2 -> V_47 != V_48 ) {
if ( V_125 -> V_157 )
V_125 -> V_157 () ;
}
F_58 ( V_18 -> V_39 , V_2 ) ;
if ( V_125 -> V_156 )
V_125 -> V_156 () ;
F_59 ( V_2 ) ;
return 0 ;
}
static int T_8 F_62 ( void )
{
int V_21 ;
F_63 ( V_8 L_1 , V_9 ) ;
V_21 = F_64 ( & V_158 ) ;
if ( V_21 ) {
F_14 ( V_25 L_27 ) ;
return V_21 ;
}
return 0 ;
}
static void T_9 F_65 ( void )
{
F_66 ( & V_158 ) ;
}

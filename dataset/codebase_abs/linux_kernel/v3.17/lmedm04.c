static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , int V_4 , T_1 V_5 )
{
int V_6 , V_7 ;
V_6 = F_2 ( V_2 , F_3 ( V_2 , V_5 ) ,
V_3 , V_4 , & V_7 , 100 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 * V_8 , int V_4 , T_1 V_5 )
{
int V_6 , V_7 ;
V_6 = F_2 ( V_2 , F_5 ( V_2 , V_5 ) ,
V_8 , V_4 , & V_7 , 200 ) ;
return V_6 ;
}
static int F_6 ( struct V_9 * V_10 ,
T_1 * V_11 , int V_12 , T_1 * V_13 , int V_14 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
T_1 * V_18 ;
int V_6 = 0 ;
if ( V_16 -> V_19 == NULL ) {
V_16 -> V_19 = F_7 ( 64 , V_20 ) ;
if ( V_16 -> V_19 == NULL ) {
F_8 ( L_1 ) ;
return - V_21 ;
}
}
V_18 = V_16 -> V_19 ;
V_6 = F_9 ( & V_10 -> V_22 ) ;
if ( V_6 < 0 )
return - V_23 ;
memcpy ( V_18 , V_11 , ( V_12 < 64 ) ? V_12 : 64 ) ;
V_6 |= F_1 ( V_10 -> V_24 , V_18 , V_12 , 0x01 ) ;
V_6 |= F_4 ( V_10 -> V_24 , V_18 , ( V_14 < 64 ) ?
V_14 : 64 , 0x01 ) ;
if ( V_14 > 0 )
memcpy ( V_13 , V_18 , V_14 ) ;
F_10 ( & V_10 -> V_22 ) ;
return ( V_6 < 0 ) ? - V_25 : 0 ;
}
static int F_11 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
T_1 V_26 [] = V_27 ;
T_1 V_28 [] = V_29 ;
int V_6 ;
T_1 V_30 [ 1 ] ;
if ( V_16 -> V_31 )
V_6 = F_6 ( V_10 , V_26 , sizeof( V_26 ) ,
V_30 , sizeof( V_30 ) ) ;
V_6 = F_6 ( V_10 , V_28 , sizeof( V_28 ) ,
V_30 , sizeof( V_30 ) ) ;
return V_6 ;
}
static int F_12 ( struct V_9 * V_10 , T_1 V_32 , T_2 V_33 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
static T_1 V_34 [] = V_35 ;
static T_1 V_13 [ 1 ] ;
T_1 V_36 = V_32 * 2 ;
T_1 V_37 = V_36 + 2 ;
int V_6 = 0 ;
F_13 ( 1 , L_2 , V_33 ) ;
if ( V_16 -> V_38 == 0 )
V_6 |= F_11 ( V_10 ) ;
V_34 [ 2 ] = V_36 ;
V_34 [ 3 ] = ( T_1 ) V_33 & 0xff ;
V_34 [ 4 ] = V_36 + 1 ;
V_34 [ 5 ] = ( T_1 ) ( V_33 >> 8 ) ;
if ( V_37 > V_16 -> V_38 )
V_16 -> V_38 = V_37 ;
V_34 [ 7 ] = 0x80 + V_16 -> V_38 ;
V_6 |= F_6 ( V_10 , V_34 ,
sizeof( V_34 ) , V_13 , sizeof( V_13 ) ) ;
if ( V_16 -> V_28 )
V_6 |= F_11 ( V_10 ) ;
return V_6 ;
}
static void F_14 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
struct V_15 * V_16 = F_15 ( V_42 ) ;
static T_1 * V_44 , * V_13 ;
int V_45 = 0 , V_46 ;
T_3 V_47 ;
switch ( V_40 -> V_48 ) {
case 0 :
case - V_49 :
break;
case - V_50 :
case - V_51 :
case - V_52 :
return;
default:
F_8 ( L_3 , V_40 -> V_48 ) ;
break;
}
V_13 = ( T_1 * ) V_40 -> V_53 ;
V_46 = ( ( V_40 -> V_54 / 8 ) > 4 )
? 4 : ( V_40 -> V_54 / 8 ) ;
for ( V_45 = 0 ; V_45 < V_46 ; ++ V_45 ) {
V_44 = ( T_1 * ) & V_13 [ V_45 * 8 ] ;
F_13 ( 5 , L_4 ,
V_46 , V_45 , V_44 [ 0 ] , V_44 [ 1 ] ) ;
switch ( V_44 [ 0 ] ) {
case 0xaa :
F_16 ( 1 , L_5 , V_44 ) ;
if ( ( V_44 [ 4 ] + V_44 [ 5 ] ) == 0xff ) {
V_47 = F_17 ( ( V_44 [ 2 ] ^ 0xff ) << 8 |
( V_44 [ 3 ] > 0 ) ? ( V_44 [ 3 ] ^ 0xff ) : 0 ,
V_44 [ 5 ] ) ;
F_13 ( 1 , L_6 , V_47 ) ;
if ( F_18 ( V_42 ) -> V_55 != NULL )
F_19 ( F_18 ( V_42 ) -> V_55 ,
V_56 , V_47 , 0 ) ;
}
break;
case 0xbb :
switch ( V_16 -> V_57 ) {
case V_58 :
if ( V_44 [ 2 ] > 0 )
V_16 -> V_59 = V_44 [ 2 ] ;
V_16 -> V_60 = V_44 [ 4 ] ;
V_16 -> V_61 = V_44 [ 3 ] ;
V_16 -> V_62 = V_44 [ 7 ] ;
break;
case V_63 :
case V_64 :
if ( V_44 [ 1 ] == 0x03 ) {
if ( V_44 [ 2 ] > 1 )
V_16 -> V_59 = V_44 [ 2 ] ;
V_16 -> V_60 = V_44 [ 3 ] ;
V_16 -> V_61 = V_44 [ 4 ] ;
} else {
V_16 -> V_60 = V_44 [ 4 ] ;
V_16 -> V_61 = V_44 [ 5 ] ;
V_16 -> V_59 =
( V_16 -> V_59 & 0xf7 ) +
( ( V_44 [ 2 ] & 0x01 ) << 0x03 ) ;
}
break;
case V_65 :
if ( V_44 [ 2 ] & 0x1 )
V_16 -> V_59 = 0xff ;
else
V_16 -> V_59 = 0x00 ;
V_16 -> V_60 = V_44 [ 5 ] ;
V_16 -> V_61 = V_44 [ 4 ] ;
V_16 -> V_62 = V_44 [ 7 ] ;
default:
break;
}
F_16 ( 5 , L_7 , V_44 ) ;
break;
case 0xcc :
F_16 ( 1 , L_8 , V_44 ) ;
break;
default:
F_16 ( 1 , L_9 , V_44 ) ;
break;
}
}
F_20 ( V_40 , V_66 ) ;
V_16 -> V_67 = V_68 + F_21 ( 60 ) ;
}
static int F_22 ( struct V_41 * V_42 )
{
struct V_9 * V_10 = F_18 ( V_42 ) ;
struct V_15 * V_69 = F_15 ( V_42 ) ;
V_69 -> V_40 = F_23 ( 0 , V_66 ) ;
if ( V_69 -> V_40 == NULL )
return - V_21 ;
V_69 -> V_70 = F_24 ( V_10 -> V_24 , 128 , V_66 ,
& V_69 -> V_40 -> V_71 ) ;
if ( V_69 -> V_70 == NULL )
return - V_21 ;
F_25 ( V_69 -> V_40 ,
V_10 -> V_24 ,
F_26 ( V_10 -> V_24 , 0xa ) ,
V_69 -> V_70 ,
128 ,
F_14 ,
V_42 ,
8 ) ;
V_69 -> V_40 -> V_72 |= V_73 ;
F_20 ( V_69 -> V_40 , V_66 ) ;
F_8 ( L_10 ) ;
return 0 ;
}
static int F_27 ( struct V_41 * V_42 , int V_74 )
{
struct V_9 * V_10 = F_18 ( V_42 ) ;
struct V_15 * V_16 = F_15 ( V_42 ) ;
static T_1 V_75 [] = V_27 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 ;
F_13 ( 1 , L_11 ) ;
F_28 ( & V_10 -> V_76 ) ;
if ( ! V_74 ) {
V_6 |= F_6 ( V_10 , V_75 ,
sizeof( V_75 ) , V_13 , sizeof( V_13 ) ) ;
V_16 -> V_31 = true ;
} else
V_16 -> V_31 = false ;
V_16 -> V_38 = 0 ;
F_10 ( & V_10 -> V_76 ) ;
return 0 ;
}
static int F_29 ( struct V_41 * V_42 , int V_32 , T_2 V_77 ,
int V_74 )
{
struct V_9 * V_10 = F_18 ( V_42 ) ;
int V_6 = 0 ;
F_13 ( 3 , L_12 , V_78 ,
V_77 , V_32 , V_74 ) ;
if ( V_74 ) {
F_28 ( & V_10 -> V_76 ) ;
V_6 |= F_12 ( V_10 , V_32 , V_77 ) ;
F_10 ( & V_10 -> V_76 ) ;
}
return V_6 ;
}
static int F_30 ( struct V_9 * V_10 )
{
int V_6 = 0 ;
T_1 * V_79 ;
V_79 = F_31 ( 10 , V_20 ) ;
if ( ! V_79 )
return - V_21 ;
V_6 |= F_32 ( V_10 -> V_24 , F_33 ( V_10 -> V_24 , 0 ) ,
0x06 , 0x80 , 0x0302 , 0x00 , V_79 , 0x0006 , 200 ) ;
F_8 ( L_13 , V_6 , V_79 [ 2 ] ) ;
V_6 = ( V_6 < 0 ) ? - V_25 : V_79 [ 2 ] ;
F_34 ( V_79 ) ;
return V_6 ;
}
static int F_35 ( struct V_9 * V_10 ,
T_1 * V_11 , int V_12 , T_1 * V_13 , int V_14 )
{
int V_6 = 0 ;
struct V_15 * V_16 = V_10 -> V_17 ;
if ( V_16 -> V_80 == 1 ) {
V_6 = F_6 ( V_10 , V_11 , V_12 , V_13 , V_14 ) ;
switch ( V_16 -> V_57 ) {
case V_58 :
if ( V_11 [ 2 ] == 0x1c ) {
if ( V_11 [ 3 ] == 0x0e ) {
V_16 -> V_59 = V_13 [ 1 ] ;
if ( ( V_16 -> V_28 & 1 ) &&
( V_16 -> V_59 & 0x10 ) ) {
F_11 ( V_10 ) ;
V_16 -> V_80 = 0 ;
}
F_36 ( 80 ) ;
}
}
break;
case V_63 :
if ( V_11 [ 2 ] == 0xd0 ) {
if ( V_11 [ 3 ] == 0x24 ) {
V_16 -> V_59 = V_13 [ 1 ] ;
if ( ( V_16 -> V_28 & 1 ) &&
( V_16 -> V_59 & 0x8 ) ) {
F_11 ( V_10 ) ;
V_16 -> V_80 = 0 ;
}
}
}
break;
case V_64 :
if ( V_11 [ 2 ] == 0xd0 ) {
if ( V_11 [ 3 ] == 0x1b ) {
V_16 -> V_59 = V_13 [ 1 ] ;
if ( ( V_16 -> V_28 & 1 ) &&
( V_16 -> V_59 & 0x8 ) ) {
F_11 ( V_10 ) ;
V_16 -> V_80 = 0 ;
}
}
}
break;
case V_65 :
default:
break;
}
} else {
switch ( V_16 -> V_57 ) {
case V_58 :
switch ( V_11 [ 3 ] ) {
case 0x0e :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_59 ;
break;
case 0x43 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_60 ;
break;
case 0x1c :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_61 ;
break;
case 0x15 :
case 0x16 :
case 0x17 :
case 0x18 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = 0x00 ;
break;
default:
F_6 ( V_10 , V_11 , V_12 , V_13 , V_14 ) ;
V_16 -> V_80 = 1 ;
break;
}
break;
case V_63 :
switch ( V_11 [ 3 ] ) {
case 0x10 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = ( V_16 -> V_60 & 0x80 )
? 0 : ( V_16 -> V_60 * 2 ) ;
break;
case 0x2d :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_61 ;
break;
case 0x24 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_59 ;
break;
case 0x2e :
case 0x26 :
case 0x27 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = 0x00 ;
break;
default:
F_6 ( V_10 , V_11 , V_12 , V_13 , V_14 ) ;
V_16 -> V_80 = 1 ;
break;
}
break;
case V_64 :
switch ( V_11 [ 3 ] ) {
case 0x18 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = ( V_16 -> V_60 & 0x80 )
? 0 : ( V_16 -> V_60 * 2 ) ;
break;
case 0x24 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_61 ;
break;
case 0x1b :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_59 ;
break;
case 0x19 :
case 0x25 :
case 0x1e :
case 0x1d :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = 0x00 ;
break;
default:
F_6 ( V_10 , V_11 , V_12 , V_13 , V_14 ) ;
V_16 -> V_80 = 1 ;
break;
}
break;
case V_65 :
switch ( V_11 [ 3 ] ) {
case 0x8c :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_59 ;
if ( F_37 ( V_68 , V_16 -> V_67 ) )
V_13 [ 1 ] = 0 ;
break;
default:
F_6 ( V_10 , V_11 , V_12 , V_13 , V_14 ) ;
V_16 -> V_80 = 1 ;
break;
}
default:
break;
}
F_13 ( 4 , L_14 ,
V_11 [ 3 ] , V_13 [ 1 ] ) ;
}
return V_6 ;
}
static int F_38 ( struct V_81 * V_42 , struct V_82 V_83 [] ,
int V_84 )
{
struct V_9 * V_10 = F_39 ( V_42 ) ;
struct V_15 * V_16 = V_10 -> V_17 ;
static T_1 V_85 [ 64 ] , V_44 [ 64 ] ;
int V_45 , V_86 , V_87 ;
T_2 V_4 ;
T_1 V_88 = V_16 -> V_89 ;
F_28 ( & V_10 -> V_76 ) ;
if ( V_88 == 0 )
V_88 = 5 ;
for ( V_45 = 0 ; V_45 < V_84 ; V_45 ++ ) {
V_87 = V_83 [ V_45 ] . V_90 & V_91 ;
V_86 = V_45 + 1 < V_84 && V_83 [ V_45 + 1 ] . V_90 & V_91 ;
V_86 |= V_87 ;
V_88 = ( V_83 [ V_45 ] . V_92 == V_16 -> V_93 )
? ( V_86 ) ? V_16 -> V_94
: V_16 -> V_95
: V_16 -> V_89 ;
V_85 [ 0 ] = V_88 | ( V_86 << 7 ) ;
if ( V_88 == 5 )
V_85 [ 1 ] = ( V_86 ) ? 2 : V_83 [ V_45 ] . V_4 + 1 ;
else
V_85 [ 1 ] = V_83 [ V_45 ] . V_4 + V_86 + 1 ;
V_85 [ 2 ] = V_83 [ V_45 ] . V_92 << 1 ;
if ( V_86 ) {
if ( V_87 )
V_4 = 3 ;
else {
memcpy ( & V_85 [ 3 ] , V_83 [ V_45 ] . V_96 , V_83 [ V_45 ] . V_4 ) ;
V_85 [ V_83 [ V_45 ] . V_4 + 3 ] = V_83 [ V_45 + 1 ] . V_4 ;
V_4 = V_83 [ V_45 ] . V_4 + 4 ;
}
} else {
memcpy ( & V_85 [ 3 ] , V_83 [ V_45 ] . V_96 , V_83 [ V_45 ] . V_4 ) ;
V_4 = V_83 [ V_45 ] . V_4 + 3 ;
}
if ( F_35 ( V_10 , V_85 , V_4 , V_44 , 64 ) < 0 ) {
F_13 ( 1 , L_15 ) ;
F_10 ( & V_10 -> V_76 ) ;
return - V_23 ;
}
if ( V_86 ) {
if ( V_87 )
memcpy ( V_83 [ V_45 ] . V_96 , & V_44 [ 1 ] , V_83 [ V_45 ] . V_4 ) ;
else {
memcpy ( V_83 [ V_45 + 1 ] . V_96 , & V_44 [ 1 ] , V_83 [ V_45 + 1 ] . V_4 ) ;
V_45 ++ ;
}
}
}
F_10 ( & V_10 -> V_76 ) ;
return V_45 ;
}
static T_3 F_40 ( struct V_81 * V_97 )
{
return V_98 ;
}
static int F_41 ( struct V_99 * V_100 , int V_74 )
{
struct V_41 * V_42 = F_42 ( V_100 ) ;
struct V_9 * V_10 = F_18 ( V_42 ) ;
struct V_15 * V_16 = F_15 ( V_42 ) ;
static T_1 V_101 [] = V_27 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 , V_14 = sizeof( V_13 ) ;
F_13 ( 1 , L_16 , V_74 ) ;
if ( V_74 == 1 )
V_16 -> V_28 = 1 ;
else {
F_13 ( 1 , L_17 ) ;
F_28 ( & V_10 -> V_76 ) ;
V_6 = F_6 ( V_10 , V_101 ,
sizeof( V_101 ) , V_13 , V_14 ) ;
V_16 -> V_28 = 0 ;
V_16 -> V_80 = 1 ;
F_10 ( & V_10 -> V_76 ) ;
}
return ( V_6 < 0 ) ? - V_25 : 0 ;
}
static T_1 F_43 ( T_1 * V_102 , T_1 V_4 )
{
T_1 V_103 = 0 ;
while ( V_4 -- )
V_103 += * V_102 ++ ;
return V_103 ;
}
static int F_44 ( struct V_9 * V_10 ,
const struct V_104 * V_105 )
{
int V_6 = 0 ;
T_1 * V_79 ;
T_2 V_106 , V_12 , V_107 , V_108 , V_109 ;
T_1 V_110 , V_111 , V_45 ;
T_1 * V_112 ;
V_110 = 0x31 ;
V_107 = 1 ;
V_79 = F_31 ( 128 , V_20 ) ;
if ( ! V_79 ) {
F_8 ( L_18\
L_19 ) ;
return - V_21 ;
}
F_8 ( L_20 ) ;
for ( V_45 = 1 ; V_45 < 3 ; V_45 ++ ) {
V_108 = ( V_45 == 1 ) ? 0 : 512 ;
V_109 = ( V_45 == 1 ) ? 512 : V_105 -> V_113 ;
for ( V_106 = V_108 ; V_106 < V_109 ; V_106 += ( V_110 + 1 ) ) {
V_112 = ( T_1 * ) ( V_105 -> V_79 + V_106 ) ;
if ( ( V_109 - V_106 ) > V_110 ) {
V_79 [ 0 ] = V_45 ;
V_111 = V_110 ;
} else {
V_79 [ 0 ] = V_45 | 0x80 ;
V_111 = ( T_1 ) ( V_109 - V_106 ) - 1 ;
}
V_79 [ 1 ] = V_111 ;
memcpy ( & V_79 [ 2 ] , V_112 , V_111 + 1 ) ;
V_12 = ( T_1 ) V_111 + 4 ;
V_79 [ V_12 - 1 ] = F_43 ( V_112 , V_111 + 1 ) ;
F_13 ( 1 , L_21 , V_79 [ 3 ] ,
V_79 [ V_111 + 2 ] , V_79 [ V_111 + 3 ] ) ;
F_6 ( V_10 , V_79 , V_12 , V_79 , V_107 ) ;
V_6 |= ( V_79 [ 0 ] == 0x88 ) ? 0 : - 1 ;
}
}
V_79 [ 0 ] = 0x8a ;
V_107 = 1 ;
F_36 ( 2000 ) ;
F_6 ( V_10 , V_79 , V_107 , V_79 , V_107 ) ;
F_36 ( 400 ) ;
if ( V_6 < 0 )
F_8 ( L_22 , V_6 ) ;
else
F_8 ( L_23 ) ;
F_34 ( V_79 ) ;
return V_114 ;
}
static void F_45 ( struct V_9 * V_10 )
{
T_1 V_79 [ 1 ] = { 0 } ;
V_79 [ 0 ] = 0x0a ;
F_8 ( L_24 ) ;
F_6 ( V_10 , V_79 , sizeof( V_79 ) , V_79 , sizeof( V_79 ) ) ;
return;
}
static const char * F_46 ( struct V_9 * V_10 , int V_115 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
struct V_1 * V_24 = V_10 -> V_24 ;
const struct V_104 * V_105 = NULL ;
const char * V_116 ;
int V_6 = 0 ;
V_115 = ( V_115 > 0 ) ? ( V_115 & 1 ) : 0 ;
switch ( F_47 ( V_24 -> V_117 . V_118 ) ) {
case 0x1122 :
switch ( V_16 -> V_119 ) {
default:
V_16 -> V_119 = V_64 ;
case V_64 :
V_116 = V_120 ;
V_6 = F_48 ( & V_105 , V_116 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_115 = 0 ;
break;
}
V_16 -> V_119 = V_58 ;
case V_58 :
V_116 = V_121 ;
V_6 = F_48 ( & V_105 , V_116 , & V_24 -> V_2 ) ;
if ( V_6 == 0 )
break;
V_16 -> V_119 = V_122 ;
break;
}
break;
case 0x1120 :
switch ( V_16 -> V_119 ) {
default:
V_16 -> V_119 = V_63 ;
case V_63 :
V_116 = V_123 ;
V_6 = F_48 ( & V_105 , V_116 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_115 = 0 ;
break;
}
V_16 -> V_119 = V_58 ;
case V_58 :
V_116 = V_124 ;
V_6 = F_48 ( & V_105 , V_116 , & V_24 -> V_2 ) ;
if ( V_6 == 0 )
break;
V_16 -> V_119 = V_64 ;
case V_64 :
V_116 = V_125 ;
V_6 = F_48 ( & V_105 , V_116 , & V_24 -> V_2 ) ;
if ( V_6 == 0 )
break;
V_16 -> V_119 = V_122 ;
V_115 = 0 ;
break;
}
break;
case 0x22f0 :
V_116 = V_126 ;
V_16 -> V_119 = V_65 ;
break;
default:
V_116 = V_123 ;
}
F_49 ( V_105 ) ;
if ( V_115 ) {
V_119 = V_16 -> V_119 ;
F_8 ( L_25 , V_116 ) ;
F_45 ( V_10 ) ;
return NULL ;
}
return V_116 ;
}
static int F_50 ( struct V_127 * V_128 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_128 -> V_129 ; V_45 ++ ) {
F_13 ( 3 , L_26 , V_45 ) ;
F_51 ( V_128 -> V_130 [ V_45 ] ) ;
}
V_128 -> V_129 = 0 ;
return 0 ;
}
static int F_52 ( struct V_99 * V_100 ,
int V_131 )
{
struct V_41 * V_42 = F_42 ( V_100 ) ;
struct V_9 * V_10 = F_18 ( V_42 ) ;
struct V_15 * V_16 = V_10 -> V_17 ;
F_28 ( & V_10 -> V_76 ) ;
if ( ( V_16 -> V_80 == 1 ) && ( V_16 -> V_28 & 1 ) ) {
V_16 -> V_80 = 0 ;
F_11 ( V_10 ) ;
}
F_10 ( & V_10 -> V_76 ) ;
return 0 ;
}
static int F_53 ( struct V_99 * V_100 ,
T_4 V_132 )
{
struct V_9 * V_10 = F_54 ( V_100 ) ;
struct V_15 * V_16 = F_55 ( V_100 ) ;
static T_1 V_133 [] = V_134 ;
static T_1 V_135 [] = V_136 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 , V_4 = 3 , V_14 = 1 ;
F_28 ( & V_10 -> V_76 ) ;
switch ( V_132 ) {
case V_137 :
V_6 |= F_6 ( V_10 ,
V_135 , V_4 , V_13 , V_14 ) ;
break;
case V_138 :
case V_139 :
default:
V_6 |= F_6 ( V_10 ,
V_133 , V_4 , V_13 , V_14 ) ;
break;
}
F_10 ( & V_10 -> V_76 ) ;
if ( V_16 -> V_57 == V_65 )
if ( V_16 -> V_140 )
V_16 -> V_140 ( V_100 , V_132 ) ;
return ( V_6 < 0 ) ? - V_25 : 0 ;
}
static int F_56 ( struct V_99 * V_100 ,
T_2 * V_141 )
{
struct V_15 * V_16 = F_55 ( V_100 ) ;
* V_141 = ( T_2 ) ( ( T_3 ) V_16 -> V_60 * 0xffff / 0xff ) ;
return 0 ;
}
static int F_57 ( struct V_99 * V_100 , T_2 * V_142 )
{
struct V_15 * V_16 = F_55 ( V_100 ) ;
* V_142 = ( T_2 ) ( ( T_3 ) V_16 -> V_61 * 0xffff / 0x7f ) ;
return 0 ;
}
static int F_58 ( struct V_99 * V_100 , T_3 * V_143 )
{
* V_143 = 0 ;
return 0 ;
}
static int F_59 ( struct V_99 * V_100 , T_3 * V_144 )
{
* V_144 = 0 ;
return 0 ;
}
static int F_60 ( struct V_41 * V_42 )
{
struct V_9 * V_10 = F_18 ( V_42 ) ;
struct V_15 * V_16 = F_15 ( V_42 ) ;
const char * V_145 = V_10 -> V_146 ;
char * V_147 [] = { L_27 , L_28 , L_29 ,
L_30 , L_31 } ;
char * V_146 = V_42 -> V_100 [ 0 ] -> V_148 . F_8 . V_146 ;
F_61 ( V_146 , V_145 , 128 ) ;
F_62 ( V_146 , V_147 [ V_16 -> V_57 ] , 128 ) ;
return 0 ;
}
static int F_63 ( struct V_41 * V_42 )
{
struct V_9 * V_10 = F_18 ( V_42 ) ;
struct V_15 * V_16 = V_10 -> V_17 ;
int V_6 = 0 ;
V_16 -> V_80 = 1 ;
switch ( F_47 ( V_10 -> V_24 -> V_117 . V_118 ) ) {
case 0x1122 :
case 0x1120 :
V_16 -> V_89 = 4 ;
V_42 -> V_100 [ 0 ] = F_64 ( V_149 ,
& V_150 , & V_10 -> V_151 ) ;
if ( V_42 -> V_100 [ 0 ] ) {
F_8 ( L_32 ) ;
V_16 -> V_95 = 4 ;
V_16 -> V_94 = 4 ;
V_16 -> V_93 = 0x60 ;
V_16 -> V_57 = V_58 ;
if ( V_16 -> V_119 != V_58 ) {
V_16 -> V_119 = V_58 ;
V_6 = F_46 ( V_10 , 1 ) ? 0 : - V_25 ;
}
break;
}
V_16 -> V_89 = 4 ;
V_42 -> V_100 [ 0 ] = F_64 ( V_152 ,
& V_153 , & V_10 -> V_151 ) ;
if ( V_42 -> V_100 [ 0 ] ) {
F_8 ( L_33 ) ;
V_16 -> V_95 = 4 ;
V_16 -> V_94 = 5 ;
V_16 -> V_93 = 0x60 ;
V_16 -> V_57 = V_64 ;
if ( V_16 -> V_119 != V_64 ) {
V_16 -> V_119 = V_64 ;
V_6 = F_46 ( V_10 , 1 ) ? 0 : - V_25 ;
}
break;
}
V_16 -> V_89 = 5 ;
V_42 -> V_100 [ 0 ] = F_64 ( V_154 , & V_155 ,
& V_10 -> V_151 ) ;
if ( V_42 -> V_100 [ 0 ] ) {
F_8 ( L_34 ) ;
V_16 -> V_95 = 4 ;
V_16 -> V_94 = 5 ;
V_16 -> V_93 = 0x60 ;
V_16 -> V_57 = V_63 ;
if ( V_16 -> V_119 != V_63 ) {
V_16 -> V_119 = V_63 ;
V_6 = F_46 ( V_10 , 1 ) ? 0 : - V_25 ;
}
break;
}
case 0x22f0 :
V_16 -> V_89 = 5 ;
V_42 -> V_100 [ 0 ] = F_64 ( V_156 ,
& V_157 , & V_10 -> V_151 ) ;
if ( V_42 -> V_100 [ 0 ] ) {
F_8 ( L_35 ) ;
F_64 ( V_158 , V_42 -> V_100 [ 0 ] , & V_159 ,
& V_10 -> V_151 ) ;
V_16 -> V_95 = 5 ;
V_16 -> V_94 = 5 ;
V_16 -> V_93 = 0x60 ;
V_16 -> V_57 = V_65 ;
V_16 -> V_140 =
V_42 -> V_100 [ 0 ] -> V_148 . V_160 ;
V_42 -> V_100 [ 0 ] -> V_148 . V_161 =
F_56 ;
V_42 -> V_100 [ 0 ] -> V_148 . V_162 =
F_57 ;
V_42 -> V_100 [ 0 ] -> V_148 . V_163 =
F_58 ;
V_42 -> V_100 [ 0 ] -> V_148 . V_164 =
F_59 ;
}
break;
}
if ( V_42 -> V_100 [ 0 ] == NULL ) {
F_8 ( L_36 ) ;
return - V_25 ;
}
if ( V_6 ) {
if ( V_42 -> V_100 [ 0 ] ) {
F_65 ( V_42 -> V_100 [ 0 ] ) ;
V_42 -> V_100 [ 0 ] = NULL ;
}
V_10 -> V_165 = NULL ;
return - V_25 ;
}
V_42 -> V_100 [ 0 ] -> V_148 . V_160 = F_53 ;
V_6 = F_60 ( V_42 ) ;
return V_6 ;
}
static int F_66 ( struct V_41 * V_42 )
{
struct V_9 * V_10 = F_18 ( V_42 ) ;
struct V_15 * V_16 = F_15 ( V_42 ) ;
char * V_166 [] = { L_27 , L_37 , L_38 , L_39 , L_40 } ;
int V_6 = 0 ;
switch ( V_16 -> V_57 ) {
case V_58 :
if ( F_64 ( V_167 , V_42 -> V_100 [ 0 ] , 0x60 ,
& V_10 -> V_151 , 1 ) )
V_6 = V_16 -> V_57 ;
break;
case V_63 :
if ( F_64 ( V_168 , V_42 -> V_100 [ 0 ] , & V_169 ,
& V_10 -> V_151 ) )
V_6 = V_16 -> V_57 ;
break;
case V_64 :
if ( F_64 ( V_170 , V_42 -> V_100 [ 0 ] , 0x60 ,
& V_10 -> V_151 , V_171 ) )
V_6 = V_16 -> V_57 ;
break;
case V_65 :
V_6 = V_16 -> V_57 ;
break;
default:
break;
}
if ( V_6 )
F_8 ( L_41 , V_166 [ V_6 ] ) ;
else {
F_8 ( L_42 ) ;
F_45 ( V_10 ) ;
return - V_25 ;
}
V_6 = F_22 ( V_42 ) ;
if ( V_6 < 0 ) {
F_8 ( L_43 ) ;
return - V_25 ;
}
return V_6 ;
}
static int F_67 ( struct V_9 * V_10 , int V_74 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
static T_1 V_172 [] = V_173 ;
static T_1 V_174 [] = V_175 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 , V_4 = 3 , V_14 = 1 ;
F_28 ( & V_10 -> V_76 ) ;
if ( V_74 )
V_6 = F_6 ( V_10 , V_172 , V_4 , V_13 , V_14 ) ;
else
V_6 = F_6 ( V_10 , V_174 , V_4 , V_13 , V_14 ) ;
V_16 -> V_80 = 1 ;
F_10 ( & V_10 -> V_76 ) ;
return V_6 ;
}
static int F_68 ( struct V_9 * V_10 )
{
return 1 ;
}
static int F_69 ( struct V_9 * V_10 , const char * * V_146 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
F_70 ( V_10 -> V_24 ) ;
F_71 ( V_10 -> V_24 ,
V_10 -> V_176 -> V_177 , 1 ) ;
V_16 -> V_119 = V_119 ;
if ( F_30 ( V_10 ) == 0x44 ) {
* V_146 = F_46 ( V_10 , 0 ) ;
return V_178 ;
}
return 0 ;
}
static int F_72 ( struct V_99 * V_100 , T_1 * V_179 ,
struct V_180 * V_128 )
{
struct V_41 * V_42 = F_42 ( V_100 ) ;
struct V_9 * V_10 ;
if ( V_42 == NULL )
return 0 ;
V_10 = F_18 ( V_42 ) ;
if ( V_181 == 2 ) {
V_42 -> V_182 = 1 ;
V_42 -> V_183 = 15 ;
}
if ( ! ( F_47 ( V_10 -> V_24 -> V_117 . V_118 )
== 0x1122 ) )
V_128 -> V_184 = 0x8 ;
return 0 ;
}
static int F_73 ( struct V_9 * V_10 ,
struct V_185 * V_186 )
{
V_186 -> V_187 = V_188 ;
return 0 ;
}
static void * F_74 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
struct V_41 * V_42 = & V_10 -> V_97 [ 0 ] ;
void * V_70 = NULL ;
if ( V_42 != NULL ) {
F_50 ( & V_42 -> V_128 ) ;
}
if ( V_16 -> V_19 != NULL ) {
V_16 -> V_80 = 1 ;
V_16 -> V_59 = 0 ;
V_16 -> V_60 = 0 ;
V_16 -> V_61 = 0 ;
V_70 = V_16 -> V_19 ;
}
if ( V_16 -> V_40 != NULL ) {
F_51 ( V_16 -> V_40 ) ;
F_75 ( V_10 -> V_24 , 128 , V_16 -> V_70 ,
V_16 -> V_40 -> V_71 ) ;
F_8 ( L_44 ) ;
}
return V_70 ;
}
static void F_76 ( struct V_9 * V_10 )
{
void * V_19 ;
if ( V_10 != NULL ) {
V_19 = F_74 ( V_10 ) ;
F_34 ( V_19 ) ;
}
}

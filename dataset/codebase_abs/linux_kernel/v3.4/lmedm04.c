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
struct V_15 * V_16 = V_42 -> V_2 -> V_17 ;
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
F_15 ( 1 , L_5 , V_44 ) ;
if ( ( V_44 [ 4 ] + V_44 [ 5 ] ) == 0xff ) {
V_47 = V_44 [ 5 ] ;
V_47 += ( V_44 [ 3 ] > 0 )
? ( V_44 [ 3 ] ^ 0xff ) << 8 : 0 ;
V_47 += ( V_44 [ 2 ] ^ 0xff ) << 16 ;
F_13 ( 1 , L_6 , V_47 ) ;
if ( V_42 -> V_2 -> V_55 != NULL )
F_16 ( V_42 -> V_2 -> V_55 , V_47 , 0 ) ;
}
break;
case 0xbb :
switch ( V_16 -> V_56 ) {
case V_57 :
if ( V_44 [ 2 ] > 0 )
V_16 -> V_58 = V_44 [ 2 ] ;
V_16 -> V_59 = V_44 [ 4 ] ;
V_16 -> V_60 = V_44 [ 3 ] ;
V_16 -> V_61 = V_44 [ 7 ] ;
break;
case V_62 :
case V_63 :
if ( V_44 [ 1 ] == 0x03 ) {
if ( V_44 [ 2 ] > 1 )
V_16 -> V_58 = V_44 [ 2 ] ;
V_16 -> V_59 = V_44 [ 3 ] ;
V_16 -> V_60 = V_44 [ 4 ] ;
} else {
V_16 -> V_59 = V_44 [ 4 ] ;
V_16 -> V_60 = V_44 [ 5 ] ;
V_16 -> V_58 =
( V_16 -> V_58 & 0xf7 ) +
( ( V_44 [ 2 ] & 0x01 ) << 0x03 ) ;
}
break;
case V_64 :
if ( V_44 [ 2 ] > 0 )
V_16 -> V_58 = 0xff ;
else
V_16 -> V_58 = 0xf0 ;
V_16 -> V_59 = V_44 [ 4 ] ;
V_16 -> V_60 = V_44 [ 5 ] ;
V_16 -> V_61 = V_44 [ 7 ] ;
default:
break;
}
F_15 ( 5 , L_7 , V_44 ) ;
break;
case 0xcc :
F_15 ( 1 , L_8 , V_44 ) ;
break;
default:
F_15 ( 1 , L_9 , V_44 ) ;
break;
}
}
F_17 ( V_40 , V_65 ) ;
}
static int F_18 ( struct V_41 * V_42 )
{
struct V_15 * V_66 = V_42 -> V_2 -> V_17 ;
V_66 -> V_40 = F_19 ( 0 , V_65 ) ;
if ( V_66 -> V_40 == NULL )
return - V_21 ;
V_66 -> V_67 = F_20 ( V_42 -> V_2 -> V_24 , 128 , V_65 ,
& V_66 -> V_40 -> V_68 ) ;
if ( V_66 -> V_67 == NULL )
return - V_21 ;
F_21 ( V_66 -> V_40 ,
V_42 -> V_2 -> V_24 ,
F_22 ( V_42 -> V_2 -> V_24 , 0xa ) ,
V_66 -> V_67 ,
128 ,
F_14 ,
V_42 ,
8 ) ;
V_66 -> V_40 -> V_69 |= V_70 ;
F_17 ( V_66 -> V_40 , V_65 ) ;
F_8 ( L_10 ) ;
return 0 ;
}
static int F_23 ( struct V_41 * V_42 , int V_71 )
{
struct V_15 * V_16 = V_42 -> V_2 -> V_17 ;
static T_1 V_72 [] = V_27 ;
static T_1 V_13 [ 1 ] ;
int V_6 ;
F_13 ( 1 , L_11 ) ;
F_24 ( & V_42 -> V_2 -> V_73 ) ;
if ( ! V_71 ) {
V_6 |= F_6 ( V_42 -> V_2 , V_72 ,
sizeof( V_72 ) , V_13 , sizeof( V_13 ) ) ;
V_16 -> V_31 = true ;
} else
V_16 -> V_31 = false ;
V_16 -> V_38 = 0 ;
F_10 ( & V_42 -> V_2 -> V_73 ) ;
return 0 ;
}
static int F_25 ( struct V_41 * V_42 , int V_32 , T_2 V_74 ,
int V_71 )
{
int V_6 = 0 ;
F_13 ( 3 , L_12 , V_75 ,
V_74 , V_32 , V_71 ) ;
if ( V_71 ) {
F_24 ( & V_42 -> V_2 -> V_73 ) ;
V_6 |= F_12 ( V_42 -> V_2 , V_32 , V_74 ) ;
F_10 ( & V_42 -> V_2 -> V_73 ) ;
}
return V_6 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
T_1 * V_76 ;
V_76 = F_27 ( 10 , V_20 ) ;
if ( ! V_76 )
return - V_21 ;
V_6 |= F_28 ( V_2 , F_29 ( V_2 , 0 ) ,
0x06 , 0x80 , 0x0302 , 0x00 , V_76 , 0x0006 , 200 ) ;
F_8 ( L_13 , V_6 , V_76 [ 2 ] ) ;
V_6 = ( V_6 < 0 ) ? - V_25 : V_76 [ 2 ] ;
F_30 ( V_76 ) ;
return V_6 ;
}
static int F_31 ( struct V_9 * V_10 ,
T_1 * V_11 , int V_12 , T_1 * V_13 , int V_14 )
{
int V_6 = 0 ;
struct V_15 * V_16 = V_10 -> V_17 ;
if ( V_16 -> V_77 == 1 ) {
V_6 = F_6 ( V_10 , V_11 , V_12 , V_13 , V_14 ) ;
switch ( V_16 -> V_56 ) {
case V_57 :
if ( V_11 [ 2 ] == 0x1c ) {
if ( V_11 [ 3 ] == 0x0e ) {
V_16 -> V_58 = V_13 [ 1 ] ;
if ( ( V_16 -> V_28 & 1 ) &&
( V_16 -> V_58 & 0x10 ) ) {
F_11 ( V_10 ) ;
V_16 -> V_77 = 0 ;
}
F_32 ( 80 ) ;
}
}
break;
case V_62 :
if ( V_11 [ 2 ] == 0xd0 ) {
if ( V_11 [ 3 ] == 0x24 ) {
V_16 -> V_58 = V_13 [ 1 ] ;
if ( ( V_16 -> V_28 & 1 ) &&
( V_16 -> V_58 & 0x8 ) ) {
F_11 ( V_10 ) ;
V_16 -> V_77 = 0 ;
}
}
}
break;
case V_63 :
if ( V_11 [ 2 ] == 0xd0 ) {
if ( V_11 [ 3 ] == 0x1b ) {
V_16 -> V_58 = V_13 [ 1 ] ;
if ( ( V_16 -> V_28 & 1 ) &&
( V_16 -> V_58 & 0x8 ) ) {
F_11 ( V_10 ) ;
V_16 -> V_77 = 0 ;
}
}
}
break;
case V_64 :
default:
break;
}
} else {
switch ( V_16 -> V_56 ) {
case V_57 :
switch ( V_11 [ 3 ] ) {
case 0x0e :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_58 ;
break;
case 0x43 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_59 ;
break;
case 0x1c :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_60 ;
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
V_16 -> V_77 = 1 ;
break;
}
break;
case V_62 :
switch ( V_11 [ 3 ] ) {
case 0x10 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = ( V_16 -> V_59 & 0x80 )
? 0 : ( V_16 -> V_59 * 2 ) ;
break;
case 0x2d :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_60 ;
break;
case 0x24 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_58 ;
break;
case 0x2e :
case 0x26 :
case 0x27 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = 0x00 ;
break;
default:
F_6 ( V_10 , V_11 , V_12 , V_13 , V_14 ) ;
V_16 -> V_77 = 1 ;
break;
}
break;
case V_63 :
switch ( V_11 [ 3 ] ) {
case 0x18 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = ( V_16 -> V_59 & 0x80 )
? 0 : ( V_16 -> V_59 * 2 ) ;
break;
case 0x24 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_60 ;
break;
case 0x1b :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_58 ;
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
V_16 -> V_77 = 1 ;
break;
}
break;
case V_64 :
switch ( V_11 [ 3 ] ) {
case 0x8c :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = 0xff ;
if ( V_16 -> V_78 == V_16 -> V_61 ) {
V_16 -> V_79 ++ ;
if ( V_16 -> V_79 > 5 )
V_13 [ 1 ] = 0 ;
} else
V_16 -> V_79 = 0 ;
V_16 -> V_78 = V_16 -> V_61 ;
break;
default:
F_6 ( V_10 , V_11 , V_12 , V_13 , V_14 ) ;
V_16 -> V_77 = 1 ;
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
static int F_33 ( struct V_80 * V_42 , struct V_81 V_82 [] ,
int V_83 )
{
struct V_9 * V_10 = F_34 ( V_42 ) ;
struct V_15 * V_16 = V_10 -> V_17 ;
static T_1 V_84 [ 64 ] , V_44 [ 64 ] ;
int V_45 , V_85 , V_86 ;
T_2 V_4 ;
T_1 V_87 = V_16 -> V_88 ;
F_24 ( & V_10 -> V_73 ) ;
if ( V_87 == 0 )
V_87 = 5 ;
if ( V_83 > 2 )
F_35 ( L_15
L_16 ) ;
for ( V_45 = 0 ; V_45 < V_83 ; V_45 ++ ) {
V_86 = 1 & ( V_82 [ V_45 ] . V_89 & V_90 ) ;
V_85 = V_45 + 1 < V_83 && ( V_82 [ V_45 + 1 ] . V_89 & V_90 ) ;
V_85 |= V_86 ;
V_87 = ( V_82 [ V_45 ] . V_91 == V_16 -> V_92 )
? ( V_85 ) ? V_16 -> V_93
: V_16 -> V_94
: V_16 -> V_88 ;
V_84 [ 0 ] = V_87 | ( V_85 << 7 ) ;
if ( V_87 == 5 )
V_84 [ 1 ] = ( V_85 ) ? 2 : V_82 [ V_45 ] . V_4 + 1 ;
else
V_84 [ 1 ] = V_82 [ V_45 ] . V_4 + V_85 + 1 ;
V_84 [ 2 ] = V_82 [ V_45 ] . V_91 ;
if ( V_85 ) {
if ( V_86 )
V_4 = 3 ;
else {
memcpy ( & V_84 [ 3 ] , V_82 [ V_45 ] . V_95 , V_82 [ V_45 ] . V_4 ) ;
V_84 [ V_82 [ V_45 ] . V_4 + 3 ] = V_82 [ V_45 + 1 ] . V_4 ;
V_4 = V_82 [ V_45 ] . V_4 + 4 ;
}
} else {
memcpy ( & V_84 [ 3 ] , V_82 [ V_45 ] . V_95 , V_82 [ V_45 ] . V_4 ) ;
V_4 = V_82 [ V_45 ] . V_4 + 3 ;
}
if ( F_31 ( V_10 , V_84 , V_4 , V_44 , 64 ) < 0 ) {
F_13 ( 1 , L_17 ) ;
F_10 ( & V_10 -> V_73 ) ;
return - V_23 ;
}
if ( V_85 ) {
if ( V_86 )
memcpy ( V_82 [ V_45 ] . V_95 , & V_44 [ 1 ] , V_82 [ V_45 ] . V_4 ) ;
else {
memcpy ( V_82 [ V_45 + 1 ] . V_95 , & V_44 [ 1 ] , V_82 [ V_45 + 1 ] . V_4 ) ;
V_45 ++ ;
}
}
}
F_10 ( & V_10 -> V_73 ) ;
return V_45 ;
}
static T_3 F_36 ( struct V_80 * V_96 )
{
return V_97 ;
}
static int F_37 ( struct V_1 * V_24 ,
struct V_98 * V_99 ,
struct V_100 * * V_101 ,
int * V_102 )
{
if ( V_103 != 2 )
V_99 -> V_96 [ 0 ] . V_104 [ 0 ] . V_105 &=
~ V_106 ;
* V_102 = 0 ;
return 0 ;
}
static int F_38 ( struct V_41 * V_42 , int V_71 )
{
struct V_15 * V_16 = V_42 -> V_2 -> V_17 ;
static T_1 V_107 [] = V_27 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 , V_14 = sizeof( V_13 ) ;
F_13 ( 1 , L_18 , V_71 ) ;
if ( V_71 == 1 )
V_16 -> V_28 = 1 ;
else {
F_13 ( 1 , L_19 ) ;
F_24 ( & V_42 -> V_2 -> V_73 ) ;
V_6 = F_6 ( V_42 -> V_2 , V_107 ,
sizeof( V_107 ) , V_13 , V_14 ) ;
V_16 -> V_28 = 0 ;
V_16 -> V_77 = 1 ;
F_10 ( & V_42 -> V_2 -> V_73 ) ;
}
return ( V_6 < 0 ) ? - V_25 : 0 ;
}
static T_1 F_39 ( T_1 * V_108 , T_1 V_4 )
{
T_1 V_109 = 0 ;
while ( V_4 -- )
V_109 += * V_108 ++ ;
return V_109 ;
}
static int F_40 ( struct V_1 * V_2 ,
const struct V_110 * V_111 )
{
int V_6 = 0 ;
T_1 * V_76 ;
T_2 V_112 , V_12 , V_113 , V_114 , V_115 ;
T_1 V_116 , V_117 , V_45 ;
T_1 * V_118 ;
V_116 = 0x31 ;
V_113 = 1 ;
V_76 = F_27 ( 512 , V_20 ) ;
if ( ! V_76 ) {
F_8 ( L_20 ) ;
return - V_21 ;
}
F_8 ( L_21 ) ;
for ( V_45 = 1 ; V_45 < 3 ; V_45 ++ ) {
V_114 = ( V_45 == 1 ) ? 0 : 512 ;
V_115 = ( V_45 == 1 ) ? 512 : V_111 -> V_119 ;
for ( V_112 = V_114 ; V_112 < V_115 ; V_112 += ( V_116 + 1 ) ) {
V_118 = ( T_1 * ) ( V_111 -> V_76 + V_112 ) ;
if ( ( V_115 - V_112 ) > V_116 ) {
V_76 [ 0 ] = V_45 ;
V_117 = V_116 ;
} else {
V_76 [ 0 ] = V_45 | 0x80 ;
V_117 = ( T_1 ) ( V_115 - V_112 ) - 1 ;
}
V_76 [ 1 ] = V_117 ;
memcpy ( & V_76 [ 2 ] , V_118 , V_117 + 1 ) ;
V_12 = ( T_1 ) V_117 + 4 ;
V_76 [ V_12 - 1 ] = F_39 ( V_118 , V_117 + 1 ) ;
F_13 ( 1 , L_22 , V_76 [ 3 ] ,
V_76 [ V_117 + 2 ] , V_76 [ V_117 + 3 ] ) ;
V_6 |= F_1 ( V_2 , V_76 , V_12 , 1 ) ;
V_6 |= F_4 ( V_2 , V_76 , V_113 , 1 ) ;
V_6 |= ( V_76 [ 0 ] == 0x88 ) ? 0 : - 1 ;
}
}
F_28 ( V_2 , F_29 ( V_2 , 0 ) ,
0x06 , 0x80 , 0x0200 , 0x00 , V_76 , 0x0109 , 1000 ) ;
V_76 [ 0 ] = 0x8a ;
V_113 = 1 ;
F_32 ( 2000 ) ;
V_6 |= F_1 ( V_2 , V_76 , V_113 , 1 ) ;
V_6 |= F_4 ( V_2 , V_76 , V_113 , 1 ) ;
F_32 ( 400 ) ;
if ( V_6 < 0 )
F_8 ( L_23 , V_6 ) ;
else
F_8 ( L_24 ) ;
F_30 ( V_76 ) ;
return ( V_6 < 0 ) ? - V_25 : 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
int V_6 = 0 , V_113 ;
T_1 V_76 [ 512 ] = { 0 } ;
V_76 [ 0 ] = 0x0a ;
V_113 = 1 ;
F_8 ( L_25 ) ;
V_6 |= F_1 ( V_2 , V_76 , V_113 , 1 ) ;
V_6 |= F_4 ( V_2 , V_76 , V_113 , 1 ) ;
return;
}
static int F_42 ( struct V_1 * V_24 , int V_102 )
{
const struct V_110 * V_111 = NULL ;
const char V_120 [] = L_26 ;
const char V_121 [] = L_27 ;
const char V_122 [] = L_28 ;
const char V_123 [] = L_29 ;
const char V_124 [] = L_30 ;
const char V_125 [] = L_31 ;
const char * V_126 ;
int V_6 = 0 , V_127 ;
V_102 = ( V_102 > 0 ) ? ( V_102 & 1 ) : 0 ;
V_127 = ! V_102 ;
switch ( F_43 ( V_24 -> V_128 . V_129 ) ) {
case 0x1122 :
switch ( V_130 ) {
default:
V_130 = V_63 ;
case V_63 :
V_126 = V_125 ;
V_6 = F_44 ( & V_111 , V_126 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_102 = 0 ;
break;
}
V_130 = V_57 ;
case V_57 :
V_126 = V_124 ;
V_6 = F_44 ( & V_111 , V_126 , & V_24 -> V_2 ) ;
if ( V_6 == 0 )
break;
F_8 ( L_32 ) ;
V_130 = V_131 ;
V_102 = 0 ;
V_127 = 0 ;
break;
}
break;
case 0x1120 :
switch ( V_130 ) {
default:
V_130 = V_62 ;
case V_62 :
V_126 = V_120 ;
V_6 = F_44 ( & V_111 , V_126 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_102 = 0 ;
break;
}
V_130 = V_57 ;
case V_57 :
V_126 = V_121 ;
V_6 = F_44 ( & V_111 , V_126 , & V_24 -> V_2 ) ;
if ( V_6 == 0 )
break;
V_130 = V_63 ;
case V_63 :
V_126 = V_122 ;
V_6 = F_44 ( & V_111 , V_126 , & V_24 -> V_2 ) ;
if ( V_6 == 0 )
break;
F_8 ( L_32 ) ;
V_130 = V_131 ;
V_102 = 0 ;
V_127 = 0 ;
break;
}
break;
case 0x22f0 :
V_126 = V_123 ;
V_6 = F_44 ( & V_111 , V_126 , & V_24 -> V_2 ) ;
V_130 = V_64 ;
break;
default:
V_126 = V_120 ;
}
if ( V_127 ) {
F_8 ( L_33 , V_126 ) ;
V_6 = F_40 ( V_24 , V_111 ) ;
}
F_45 ( V_111 ) ;
if ( V_102 ) {
F_8 ( L_34 , V_126 ) ;
F_41 ( V_24 ) ;
return - V_25 ;
}
return V_6 ;
}
static int F_46 ( struct V_132 * V_133 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_133 -> V_134 ; V_45 ++ ) {
F_13 ( 3 , L_35 , V_45 ) ;
F_47 ( V_133 -> V_135 [ V_45 ] ) ;
}
V_133 -> V_134 = 0 ;
return 0 ;
}
static int F_48 ( struct V_136 * V_104 ,
int V_137 )
{
struct V_41 * V_42 = V_104 -> V_138 -> V_17 ;
struct V_9 * V_10 = V_42 -> V_2 ;
struct V_15 * V_16 = V_10 -> V_17 ;
F_24 ( & V_10 -> V_73 ) ;
if ( ( V_16 -> V_77 == 1 ) && ( V_16 -> V_28 & 1 ) ) {
V_16 -> V_77 = 0 ;
F_11 ( V_10 ) ;
}
F_10 ( & V_10 -> V_73 ) ;
return 0 ;
}
static int F_49 ( struct V_136 * V_104 ,
T_4 V_139 )
{
struct V_41 * V_42 = V_104 -> V_138 -> V_17 ;
static T_1 V_140 [] = V_141 ;
static T_1 V_142 [] = V_143 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 , V_4 = 3 , V_14 = 1 ;
F_24 ( & V_42 -> V_2 -> V_73 ) ;
switch ( V_139 ) {
case V_144 :
V_6 |= F_6 ( V_42 -> V_2 ,
V_142 , V_4 , V_13 , V_14 ) ;
break;
case V_145 :
case V_146 :
default:
V_6 |= F_6 ( V_42 -> V_2 ,
V_140 , V_4 , V_13 , V_14 ) ;
break;
}
F_10 ( & V_42 -> V_2 -> V_73 ) ;
return ( V_6 < 0 ) ? - V_25 : 0 ;
}
static int F_50 ( struct V_136 * V_104 ,
T_2 * V_147 )
{
struct V_41 * V_42 = V_104 -> V_138 -> V_17 ;
struct V_15 * V_16 = V_42 -> V_2 -> V_17 ;
* V_147 = ( T_2 ) ( ( T_3 ) V_16 -> V_59 * 0xffff / 0x7f ) ;
return 0 ;
}
static int F_51 ( struct V_136 * V_104 , T_2 * V_148 )
{
struct V_41 * V_42 = V_104 -> V_138 -> V_17 ;
struct V_15 * V_16 = V_42 -> V_2 -> V_17 ;
* V_148 = ( T_2 ) ( ( T_3 ) V_16 -> V_60 * 0xffff / 0xff ) ;
return 0 ;
}
static int F_52 ( struct V_41 * V_42 )
{
struct V_15 * V_16 = V_42 -> V_2 -> V_17 ;
const char * V_101 = V_42 -> V_2 -> V_101 -> V_149 ;
char * V_150 [] = { L_36 , L_37 , L_38 ,
L_39 , L_40 } ;
char * V_149 = V_42 -> V_151 [ 0 ] . V_104 -> V_152 . F_8 . V_149 ;
F_53 ( V_149 , V_101 , 128 ) ;
F_54 ( V_149 , V_150 [ V_16 -> V_56 ] , 128 ) ;
return 0 ;
}
static int F_55 ( struct V_41 * V_42 )
{
struct V_15 * V_16 = V_42 -> V_2 -> V_17 ;
int V_6 = 0 ;
V_16 -> V_77 = 1 ;
switch ( F_43 ( V_42 -> V_2 -> V_24 -> V_128 . V_129 ) ) {
case 0x1122 :
case 0x1120 :
V_16 -> V_88 = 4 ;
V_42 -> V_151 [ 0 ] . V_104 = F_56 ( V_153 ,
& V_154 , & V_42 -> V_2 -> V_155 ) ;
if ( V_42 -> V_151 [ 0 ] . V_104 ) {
F_8 ( L_41 ) ;
V_16 -> V_94 = 4 ;
V_16 -> V_93 = 4 ;
V_16 -> V_92 = 0xc0 ;
V_16 -> V_56 = V_57 ;
if ( V_130 != V_57 ) {
V_130 = V_57 ;
V_6 = F_42 ( V_42 -> V_2 -> V_24 , 1 ) ;
}
break;
}
V_16 -> V_88 = 4 ;
V_42 -> V_151 [ 0 ] . V_104 = F_56 ( V_156 ,
& V_157 , & V_42 -> V_2 -> V_155 ) ;
if ( V_42 -> V_151 [ 0 ] . V_104 ) {
F_8 ( L_42 ) ;
V_16 -> V_94 = 4 ;
V_16 -> V_93 = 5 ;
V_16 -> V_92 = 0xc0 ;
V_16 -> V_56 = V_63 ;
if ( V_130 != V_63 ) {
V_130 = V_63 ;
V_6 = F_42 ( V_42 -> V_2 -> V_24 , 1 ) ;
}
break;
}
V_16 -> V_88 = 5 ;
V_42 -> V_151 [ 0 ] . V_104 = F_56 ( V_158 , & V_159 ,
& V_42 -> V_2 -> V_155 ) ;
if ( V_42 -> V_151 [ 0 ] . V_104 ) {
F_8 ( L_43 ) ;
V_16 -> V_94 = 4 ;
V_16 -> V_93 = 5 ;
V_16 -> V_92 = 0xc0 ;
V_16 -> V_56 = V_62 ;
if ( V_130 != V_62 ) {
V_130 = V_62 ;
V_6 = F_42 ( V_42 -> V_2 -> V_24 , 1 ) ;
}
break;
}
case 0x22f0 :
V_16 -> V_88 = 5 ;
V_42 -> V_151 [ 0 ] . V_104 = F_56 ( V_160 ,
& V_161 , & V_42 -> V_2 -> V_155 ) ;
if ( V_42 -> V_151 [ 0 ] . V_104 ) {
F_8 ( L_44 ) ;
V_16 -> V_94 = 5 ;
V_16 -> V_93 = 5 ;
V_16 -> V_92 = 0xc0 ;
V_16 -> V_56 = V_64 ;
V_42 -> V_151 [ 0 ] . V_104 -> V_152 . V_162 =
F_50 ;
V_42 -> V_151 [ 0 ] . V_104 -> V_152 . V_163 =
F_51 ;
}
break;
}
if ( V_42 -> V_151 [ 0 ] . V_104 == NULL ) {
F_8 ( L_45 ) ;
return - V_25 ;
}
if ( V_6 ) {
if ( V_42 -> V_151 [ 0 ] . V_104 ) {
F_57 ( V_42 -> V_151 [ 0 ] . V_104 ) ;
V_42 -> V_151 [ 0 ] . V_104 = NULL ;
}
V_42 -> V_2 -> V_99 . V_164 . V_165 . V_166 = NULL ;
return - V_25 ;
}
V_42 -> V_151 [ 0 ] . V_104 -> V_152 . V_167 = F_49 ;
V_6 = F_52 ( V_42 ) ;
return V_6 ;
}
static int F_58 ( struct V_41 * V_42 )
{
struct V_15 * V_16 = V_42 -> V_2 -> V_17 ;
char * V_168 [] = { L_36 , L_46 , L_47 , L_48 , L_49 } ;
int V_6 = 0 ;
switch ( V_16 -> V_56 ) {
case V_57 :
if ( F_56 ( V_169 , V_42 -> V_151 [ 0 ] . V_104 , 0xc0 ,
& V_42 -> V_2 -> V_155 , 1 ) )
V_6 = V_16 -> V_56 ;
break;
case V_62 :
if ( F_56 ( V_170 , V_42 -> V_151 [ 0 ] . V_104 , & V_171 ,
& V_42 -> V_2 -> V_155 ) )
V_6 = V_16 -> V_56 ;
break;
case V_63 :
if ( F_56 ( V_172 , V_42 -> V_151 [ 0 ] . V_104 , 0xc0 ,
& V_42 -> V_2 -> V_155 , V_173 ) )
V_6 = V_16 -> V_56 ;
break;
case V_64 :
V_6 = V_16 -> V_56 ;
break;
default:
break;
}
if ( V_6 )
F_8 ( L_50 , V_168 [ V_6 ] ) ;
else {
F_8 ( L_51 ) ;
F_41 ( V_42 -> V_2 -> V_24 ) ;
return - V_25 ;
}
V_6 = F_18 ( V_42 ) ;
if ( V_6 < 0 ) {
F_8 ( L_52 ) ;
return - V_25 ;
}
return V_6 ;
}
static int F_59 ( struct V_9 * V_10 , int V_71 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
static T_1 V_174 [] = V_175 ;
static T_1 V_176 [] = V_177 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 , V_4 = 3 , V_14 = 1 ;
F_24 ( & V_10 -> V_73 ) ;
if ( V_71 )
V_6 = F_6 ( V_10 , V_174 , V_4 , V_13 , V_14 ) ;
else
V_6 = F_6 ( V_10 , V_176 , V_4 , V_13 , V_14 ) ;
V_16 -> V_77 = 1 ;
F_10 ( & V_10 -> V_73 ) ;
return V_6 ;
}
static int F_60 ( struct V_178 * V_179 ,
const struct V_180 * V_181 )
{
struct V_1 * V_24 = F_61 ( V_179 ) ;
int V_6 = 0 ;
F_62 ( V_24 ) ;
F_63 ( V_24 , V_179 -> V_182 -> V_101 . V_183 , 1 ) ;
if ( V_24 -> V_184 != V_185 ) {
V_6 = F_64 ( V_24 ) ;
F_8 ( L_53 ) ;
return - V_25 ;
}
if ( F_26 ( V_24 ) == 0x44 ) {
F_42 ( V_24 , 0 ) ;
return - V_25 ;
}
if ( 0 == F_65 ( V_179 , & V_186 ,
V_187 , NULL , V_188 ) ) {
F_8 ( L_54 ) ;
return 0 ;
}
if ( 0 == F_65 ( V_179 , & V_189 ,
V_187 , NULL , V_188 ) ) {
F_8 ( L_54 ) ;
return 0 ;
}
F_8 ( L_55 ) ;
return - V_25 ;
}
static void * F_66 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
struct V_41 * V_42 = & V_10 -> V_96 [ 0 ] ;
void * V_67 = NULL ;
if ( V_42 != NULL ) {
F_46 ( & V_42 -> V_151 [ 0 ] . V_133 ) ;
V_42 -> V_190 = 0 ;
}
if ( V_16 -> V_19 != NULL ) {
V_16 -> V_77 = 1 ;
V_16 -> V_58 = 0 ;
V_16 -> V_59 = 0 ;
V_16 -> V_60 = 0 ;
V_67 = V_16 -> V_19 ;
}
if ( V_16 -> V_40 != NULL ) {
F_47 ( V_16 -> V_40 ) ;
F_67 ( V_10 -> V_24 , 128 , V_16 -> V_67 ,
V_16 -> V_40 -> V_68 ) ;
F_8 ( L_56 ) ;
}
return V_67 ;
}
static void F_68 ( struct V_178 * V_179 )
{
struct V_9 * V_10 = F_69 ( V_179 ) ;
void * V_19 ;
if ( V_10 != NULL ) {
V_19 = F_66 ( V_10 ) ;
F_70 ( V_179 ) ;
if ( V_19 != NULL )
F_30 ( V_19 ) ;
}
}

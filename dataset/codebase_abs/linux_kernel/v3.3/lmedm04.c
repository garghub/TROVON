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
V_6 |= F_10 ( V_10 -> V_24 , F_3 ( V_10 -> V_24 , 0x01 ) ) ;
V_6 |= F_1 ( V_10 -> V_24 , V_18 , V_12 , 0x01 ) ;
F_11 ( 10 ) ;
V_6 |= F_10 ( V_10 -> V_24 , F_5 ( V_10 -> V_24 , 0x01 ) ) ;
V_6 |= F_4 ( V_10 -> V_24 , V_18 , ( V_14 < 64 ) ?
V_14 : 64 , 0x01 ) ;
if ( V_14 > 0 )
memcpy ( V_13 , V_18 , V_14 ) ;
F_12 ( & V_10 -> V_22 ) ;
return ( V_6 < 0 ) ? - V_25 : 0 ;
}
static int F_13 ( struct V_9 * V_10 )
{
static T_1 V_26 [] = V_27 ;
int V_6 ;
T_1 V_28 [ 10 ] ;
V_6 = F_6 ( V_10 , V_26 , sizeof( V_26 ) ,
V_28 , sizeof( V_28 ) ) ;
return V_6 ;
}
static int F_14 ( struct V_9 * V_10 , T_1 V_29 , T_2 V_30 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
static T_1 V_31 [] = V_32 ;
static T_1 V_13 [ 1 ] ;
T_1 V_33 = V_29 * 2 ;
T_1 V_34 = V_33 + 2 ;
int V_6 = 0 ;
F_15 ( 1 , L_2 , V_30 ) ;
if ( V_16 -> V_35 == 0 )
V_6 |= F_13 ( V_10 ) ;
V_31 [ 2 ] = V_33 ;
V_31 [ 3 ] = ( T_1 ) V_30 & 0xff ;
V_31 [ 4 ] = V_33 + 1 ;
V_31 [ 5 ] = ( T_1 ) ( V_30 >> 8 ) ;
if ( V_34 > V_16 -> V_35 )
V_16 -> V_35 = V_34 ;
V_31 [ 7 ] = 0x80 + V_16 -> V_35 ;
V_6 |= F_6 ( V_10 , V_31 ,
sizeof( V_31 ) , V_13 , sizeof( V_13 ) ) ;
if ( V_16 -> V_26 )
V_6 |= F_13 ( V_10 ) ;
return V_6 ;
}
static void F_16 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_40 ;
struct V_15 * V_16 = V_39 -> V_2 -> V_17 ;
static T_1 * V_41 , * V_13 ;
int V_42 = 0 , V_43 ;
T_3 V_44 ;
switch ( V_37 -> V_45 ) {
case 0 :
case - V_46 :
break;
case - V_47 :
case - V_48 :
case - V_49 :
return;
default:
F_8 ( L_3 , V_37 -> V_45 ) ;
break;
}
V_13 = ( T_1 * ) V_37 -> V_50 ;
V_43 = ( ( V_37 -> V_51 / 8 ) > 4 )
? 4 : ( V_37 -> V_51 / 8 ) ;
for ( V_42 = 0 ; V_42 < V_43 ; ++ V_42 ) {
V_41 = ( T_1 * ) & V_13 [ V_42 * 8 ] ;
F_15 ( 5 , L_4 ,
V_43 , V_42 , V_41 [ 0 ] , V_41 [ 1 ] ) ;
switch ( V_41 [ 0 ] ) {
case 0xaa :
F_17 ( 1 , L_5 , V_41 ) ;
if ( ( V_41 [ 4 ] + V_41 [ 5 ] ) == 0xff ) {
V_44 = V_41 [ 5 ] ;
V_44 += ( V_41 [ 3 ] > 0 )
? ( V_41 [ 3 ] ^ 0xff ) << 8 : 0 ;
V_44 += ( V_41 [ 2 ] ^ 0xff ) << 16 ;
F_15 ( 1 , L_6 , V_44 ) ;
if ( V_39 -> V_2 -> V_52 != NULL )
F_18 ( V_39 -> V_2 -> V_52 , V_44 , 0 ) ;
}
break;
case 0xbb :
switch ( V_16 -> V_53 ) {
case V_54 :
if ( V_41 [ 2 ] > 0 )
V_16 -> V_55 = V_41 [ 2 ] ;
V_16 -> V_56 = V_41 [ 4 ] ;
V_16 -> V_57 = V_41 [ 3 ] ;
V_16 -> V_58 = V_41 [ 7 ] ;
break;
case V_59 :
case V_60 :
if ( V_41 [ 1 ] == 0x03 ) {
if ( V_41 [ 2 ] > 1 )
V_16 -> V_55 = V_41 [ 2 ] ;
V_16 -> V_56 = V_41 [ 3 ] ;
V_16 -> V_57 = V_41 [ 4 ] ;
} else {
V_16 -> V_56 = V_41 [ 4 ] ;
V_16 -> V_57 = V_41 [ 5 ] ;
V_16 -> V_55 =
( V_16 -> V_55 & 0xf7 ) +
( ( V_41 [ 2 ] & 0x01 ) << 0x03 ) ;
}
break;
default:
break;
}
F_17 ( 5 , L_7 , V_41 ) ;
break;
case 0xcc :
F_17 ( 1 , L_8 , V_41 ) ;
break;
default:
F_17 ( 1 , L_9 , V_41 ) ;
break;
}
}
F_19 ( V_37 , V_61 ) ;
}
static int F_20 ( struct V_38 * V_39 )
{
struct V_15 * V_62 = V_39 -> V_2 -> V_17 ;
V_62 -> V_37 = F_21 ( 0 , V_61 ) ;
if ( V_62 -> V_37 == NULL )
return - V_21 ;
V_62 -> V_63 = F_22 ( V_39 -> V_2 -> V_24 , 128 , V_61 ,
& V_62 -> V_37 -> V_64 ) ;
if ( V_62 -> V_63 == NULL )
return - V_21 ;
F_23 ( V_62 -> V_37 ,
V_39 -> V_2 -> V_24 ,
F_24 ( V_39 -> V_2 -> V_24 , 0xa ) ,
V_62 -> V_63 ,
128 ,
F_16 ,
V_39 ,
8 ) ;
V_62 -> V_37 -> V_65 |= V_66 ;
F_19 ( V_62 -> V_37 , V_61 ) ;
F_8 ( L_10 ) ;
return 0 ;
}
static int F_25 ( struct V_38 * V_39 , int V_67 )
{
struct V_15 * V_16 = V_39 -> V_2 -> V_17 ;
static T_1 V_68 [] = V_69 ;
static T_1 V_13 [ 1 ] ;
int V_6 ;
F_15 ( 1 , L_11 ) ;
V_6 = F_9 ( & V_39 -> V_2 -> V_70 ) ;
if ( V_6 < 0 )
return - V_23 ;
if ( ! V_67 )
V_6 |= F_6 ( V_39 -> V_2 , V_68 ,
sizeof( V_68 ) , V_13 , sizeof( V_13 ) ) ;
V_16 -> V_35 = 0 ;
F_12 ( & V_39 -> V_2 -> V_70 ) ;
return 0 ;
}
static int F_26 ( struct V_38 * V_39 , int V_29 , T_2 V_71 ,
int V_67 )
{
int V_6 = 0 ;
F_15 ( 3 , L_12 , V_72 ,
V_71 , V_29 , V_67 ) ;
if ( V_67 ) {
V_6 = F_9 ( & V_39 -> V_2 -> V_70 ) ;
if ( V_6 < 0 )
return - V_23 ;
V_6 |= F_14 ( V_39 -> V_2 , V_29 , V_71 ) ;
F_12 ( & V_39 -> V_2 -> V_70 ) ;
}
return V_6 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
T_1 * V_73 ;
V_73 = F_28 ( 10 , V_20 ) ;
if ( ! V_73 )
return - V_21 ;
V_6 |= F_29 ( V_2 , F_30 ( V_2 , 0 ) ,
0x06 , 0x80 , 0x0302 , 0x00 , V_73 , 0x0006 , 200 ) ;
F_8 ( L_13 , V_6 , V_73 [ 2 ] ) ;
V_6 = ( V_6 < 0 ) ? - V_25 : V_73 [ 2 ] ;
F_31 ( V_73 ) ;
return V_6 ;
}
static int F_32 ( struct V_9 * V_10 ,
T_1 * V_11 , int V_12 , T_1 * V_13 , int V_14 )
{
int V_6 = 0 ;
struct V_15 * V_16 = V_10 -> V_17 ;
if ( F_9 ( & V_10 -> V_70 ) < 0 )
return - V_23 ;
if ( V_16 -> V_74 == 1 ) {
V_6 = F_6 ( V_10 , V_11 , V_12 , V_13 , V_14 ) ;
switch ( V_16 -> V_53 ) {
case V_54 :
if ( V_11 [ 2 ] == 0x1c ) {
if ( V_11 [ 3 ] == 0x0e ) {
V_16 -> V_55 = V_13 [ 1 ] ;
if ( ( V_16 -> V_26 & 1 ) &&
( V_16 -> V_55 & 0x10 ) ) {
F_13 ( V_10 ) ;
V_16 -> V_74 = 0 ;
}
F_11 ( 80 ) ;
}
}
break;
case V_59 :
if ( V_11 [ 2 ] == 0xd0 ) {
if ( V_11 [ 3 ] == 0x24 ) {
V_16 -> V_55 = V_13 [ 1 ] ;
if ( ( V_16 -> V_26 & 1 ) &&
( V_16 -> V_55 & 0x8 ) ) {
F_13 ( V_10 ) ;
V_16 -> V_74 = 0 ;
}
}
if ( ( V_11 [ 3 ] != 0x6 ) & ( V_11 [ 3 ] != 0x5 ) )
F_11 ( 5 ) ;
}
break;
case V_60 :
if ( V_11 [ 2 ] == 0xd0 ) {
if ( V_11 [ 3 ] == 0x1b ) {
V_16 -> V_55 = V_13 [ 1 ] ;
if ( ( V_16 -> V_26 & 1 ) &&
( V_16 -> V_55 & 0x8 ) ) {
F_13 ( V_10 ) ;
V_16 -> V_74 = 0 ;
}
}
}
break;
default:
break;
}
} else {
switch ( V_16 -> V_53 ) {
case V_54 :
switch ( V_11 [ 3 ] ) {
case 0x0e :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_55 ;
break;
case 0x43 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_56 ;
break;
case 0x1c :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_57 ;
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
V_16 -> V_74 = 1 ;
break;
}
break;
case V_59 :
switch ( V_11 [ 3 ] ) {
case 0x10 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = ( V_16 -> V_56 & 0x80 )
? 0 : ( V_16 -> V_56 * 2 ) ;
break;
case 0x2d :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_57 ;
break;
case 0x24 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_55 ;
break;
case 0x2e :
case 0x26 :
case 0x27 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = 0x00 ;
break;
default:
F_6 ( V_10 , V_11 , V_12 , V_13 , V_14 ) ;
V_16 -> V_74 = 1 ;
break;
}
break;
case V_60 :
switch ( V_11 [ 3 ] ) {
case 0x18 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = ( V_16 -> V_56 & 0x80 )
? 0 : ( V_16 -> V_56 * 2 ) ;
break;
case 0x24 :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_57 ;
break;
case 0x1b :
V_13 [ 0 ] = 0x55 ;
V_13 [ 1 ] = V_16 -> V_55 ;
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
V_16 -> V_74 = 1 ;
break;
}
break;
default:
break;
}
F_15 ( 4 , L_14 ,
V_11 [ 3 ] , V_13 [ 1 ] ) ;
}
F_12 ( & V_10 -> V_70 ) ;
return V_6 ;
}
static int F_33 ( struct V_75 * V_39 , struct V_76 V_77 [] ,
int V_78 )
{
struct V_9 * V_10 = F_34 ( V_39 ) ;
struct V_15 * V_16 = V_10 -> V_17 ;
static T_1 V_79 [ 64 ] , V_41 [ 64 ] ;
int V_42 , V_80 , V_81 ;
T_2 V_4 ;
T_1 V_82 = V_16 -> V_83 ;
if ( V_82 == 0 )
V_82 = 5 ;
if ( V_78 > 2 )
F_35 ( L_15
L_16 ) ;
for ( V_42 = 0 ; V_42 < V_78 ; V_42 ++ ) {
V_81 = 1 & ( V_77 [ V_42 ] . V_84 & V_85 ) ;
V_80 = V_42 + 1 < V_78 && ( V_77 [ V_42 + 1 ] . V_84 & V_85 ) ;
V_80 |= V_81 ;
V_82 = ( V_77 [ V_42 ] . V_86 == V_16 -> V_87 )
? ( V_80 ) ? V_16 -> V_88
: V_16 -> V_89
: V_16 -> V_83 ;
V_79 [ 0 ] = V_82 | ( V_80 << 7 ) ;
if ( V_82 == 5 )
V_79 [ 1 ] = ( V_80 ) ? 2 : V_77 [ V_42 ] . V_4 + 1 ;
else
V_79 [ 1 ] = V_77 [ V_42 ] . V_4 + V_80 + 1 ;
V_79 [ 2 ] = V_77 [ V_42 ] . V_86 ;
if ( V_80 ) {
if ( V_81 )
V_4 = 3 ;
else {
memcpy ( & V_79 [ 3 ] , V_77 [ V_42 ] . V_90 , V_77 [ V_42 ] . V_4 ) ;
V_79 [ V_77 [ V_42 ] . V_4 + 3 ] = V_77 [ V_42 + 1 ] . V_4 ;
V_4 = V_77 [ V_42 ] . V_4 + 4 ;
}
} else {
memcpy ( & V_79 [ 3 ] , V_77 [ V_42 ] . V_90 , V_77 [ V_42 ] . V_4 ) ;
V_4 = V_77 [ V_42 ] . V_4 + 3 ;
}
if ( F_32 ( V_10 , V_79 , V_4 , V_41 , 64 ) < 0 ) {
F_15 ( 1 , L_17 ) ;
return - V_23 ;
}
if ( V_80 ) {
if ( V_81 )
memcpy ( V_77 [ V_42 ] . V_90 , & V_41 [ 1 ] , V_77 [ V_42 ] . V_4 ) ;
else {
memcpy ( V_77 [ V_42 + 1 ] . V_90 , & V_41 [ 1 ] , V_77 [ V_42 + 1 ] . V_4 ) ;
V_42 ++ ;
}
}
}
return V_42 ;
}
static T_3 F_36 ( struct V_75 * V_91 )
{
return V_92 ;
}
static int F_37 ( struct V_1 * V_24 ,
struct V_93 * V_94 ,
struct V_95 * * V_96 ,
int * V_97 )
{
if ( V_98 > 0 )
V_94 -> V_91 [ 0 ] . V_99 [ 0 ] . V_100 &=
~ V_101 ;
* V_97 = 0 ;
return 0 ;
}
static int F_38 ( struct V_38 * V_39 , int V_67 )
{
struct V_15 * V_16 = V_39 -> V_2 -> V_17 ;
static T_1 V_102 [] = V_69 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 , V_14 = sizeof( V_13 ) ;
F_15 ( 1 , L_18 , V_67 ) ;
if ( V_67 == 1 )
V_16 -> V_26 = 1 ;
else {
F_15 ( 1 , L_19 ) ;
if ( F_9 ( & V_39 -> V_2 -> V_70 ) < 0 )
return - V_23 ;
V_6 = F_6 ( V_39 -> V_2 , V_102 ,
sizeof( V_102 ) , V_13 , V_14 ) ;
V_16 -> V_26 = 0 ;
V_16 -> V_74 = 1 ;
F_12 ( & V_39 -> V_2 -> V_70 ) ;
}
return ( V_6 < 0 ) ? - V_25 : 0 ;
}
static T_1 F_39 ( T_1 * V_103 , T_1 V_4 )
{
T_1 V_104 = 0 ;
while ( V_4 -- )
V_104 += * V_103 ++ ;
return V_104 ;
}
static int F_40 ( struct V_1 * V_2 ,
const struct V_105 * V_106 )
{
int V_6 = 0 ;
T_1 * V_73 ;
T_2 V_107 , V_12 , V_108 , V_109 , V_110 ;
T_1 V_111 , V_112 , V_42 ;
T_1 * V_113 ;
V_111 = 0x31 ;
V_108 = 1 ;
V_73 = F_28 ( 512 , V_20 ) ;
if ( ! V_73 ) {
F_8 ( L_20 ) ;
return - V_21 ;
}
F_8 ( L_21 ) ;
for ( V_42 = 1 ; V_42 < 3 ; V_42 ++ ) {
V_109 = ( V_42 == 1 ) ? 0 : 512 ;
V_110 = ( V_42 == 1 ) ? 512 : V_106 -> V_114 ;
for ( V_107 = V_109 ; V_107 < V_110 ; V_107 += ( V_111 + 1 ) ) {
V_113 = ( T_1 * ) ( V_106 -> V_73 + V_107 ) ;
if ( ( V_110 - V_107 ) > V_111 ) {
V_73 [ 0 ] = V_42 ;
V_112 = V_111 ;
} else {
V_73 [ 0 ] = V_42 | 0x80 ;
V_112 = ( T_1 ) ( V_110 - V_107 ) - 1 ;
}
V_73 [ 1 ] = V_112 ;
memcpy ( & V_73 [ 2 ] , V_113 , V_112 + 1 ) ;
V_12 = ( T_1 ) V_112 + 4 ;
V_73 [ V_12 - 1 ] = F_39 ( V_113 , V_112 + 1 ) ;
F_15 ( 1 , L_22 , V_73 [ 3 ] ,
V_73 [ V_112 + 2 ] , V_73 [ V_112 + 3 ] ) ;
V_6 |= F_1 ( V_2 , V_73 , V_12 , 1 ) ;
V_6 |= F_4 ( V_2 , V_73 , V_108 , 1 ) ;
V_6 |= ( V_73 [ 0 ] == 0x88 ) ? 0 : - 1 ;
}
}
F_29 ( V_2 , F_30 ( V_2 , 0 ) ,
0x06 , 0x80 , 0x0200 , 0x00 , V_73 , 0x0109 , 1000 ) ;
V_73 [ 0 ] = 0x8a ;
V_108 = 1 ;
F_11 ( 2000 ) ;
V_6 |= F_1 ( V_2 , V_73 , V_108 , 1 ) ;
V_6 |= F_4 ( V_2 , V_73 , V_108 , 1 ) ;
F_11 ( 400 ) ;
if ( V_6 < 0 )
F_8 ( L_23 , V_6 ) ;
else
F_8 ( L_24 ) ;
F_31 ( V_73 ) ;
return ( V_6 < 0 ) ? - V_25 : 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
int V_6 = 0 , V_108 ;
T_1 V_73 [ 512 ] = { 0 } ;
V_73 [ 0 ] = 0x0a ;
V_108 = 1 ;
F_8 ( L_25 ) ;
V_6 |= F_1 ( V_2 , V_73 , V_108 , 1 ) ;
V_6 |= F_4 ( V_2 , V_73 , V_108 , 1 ) ;
return;
}
static int F_42 ( struct V_1 * V_24 , int V_97 )
{
const struct V_105 * V_106 = NULL ;
const char V_115 [] = L_26 ;
const char V_116 [] = L_27 ;
const char V_117 [] = L_28 ;
const char V_118 [] = L_29 ;
const char V_119 [] = L_30 ;
const char * V_120 ;
int V_6 , V_121 ;
V_97 = ( V_97 > 0 ) ? ( V_97 & 1 ) : 0 ;
V_121 = ! V_97 ;
if ( F_43 ( V_24 -> V_122 . V_123 ) == 0x1122 ) {
switch ( V_124 ) {
default:
V_124 = V_60 ;
case V_60 :
V_120 = V_119 ;
V_6 = F_44 ( & V_106 , V_120 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_97 = 0 ;
break;
}
V_124 = V_54 ;
case V_54 :
V_120 = V_118 ;
V_6 = F_44 ( & V_106 , V_120 , & V_24 -> V_2 ) ;
if ( V_6 == 0 )
break;
F_8 ( L_31 ) ;
V_124 = V_125 ;
V_97 = 0 ;
V_121 = 0 ;
break;
}
} else {
switch ( V_124 ) {
default:
V_124 = V_59 ;
case V_59 :
V_120 = V_115 ;
V_6 = F_44 ( & V_106 , V_120 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_97 = 0 ;
break;
}
V_124 = V_54 ;
case V_54 :
V_120 = V_116 ;
V_6 = F_44 ( & V_106 , V_120 , & V_24 -> V_2 ) ;
if ( V_6 == 0 )
break;
V_124 = V_60 ;
case V_60 :
V_120 = V_117 ;
V_6 = F_44 ( & V_106 , V_120 , & V_24 -> V_2 ) ;
if ( V_6 == 0 )
break;
F_8 ( L_31 ) ;
V_124 = V_125 ;
V_97 = 0 ;
V_121 = 0 ;
break;
}
}
if ( V_121 ) {
F_8 ( L_32 , V_120 ) ;
V_6 = F_40 ( V_24 , V_106 ) ;
}
F_45 ( V_106 ) ;
if ( V_97 ) {
F_8 ( L_33 , V_120 ) ;
F_41 ( V_24 ) ;
return - V_25 ;
}
return V_6 ;
}
static int F_46 ( struct V_126 * V_127 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_127 -> V_128 ; V_42 ++ ) {
F_15 ( 3 , L_34 , V_42 ) ;
F_47 ( V_127 -> V_129 [ V_42 ] ) ;
}
V_127 -> V_128 = 0 ;
return 0 ;
}
static int F_48 ( struct V_130 * V_99 ,
T_4 V_131 )
{
struct V_38 * V_39 = V_99 -> V_132 -> V_17 ;
static T_1 V_133 [] = V_134 ;
static T_1 V_135 [] = V_136 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 , V_4 = 3 , V_14 = 1 ;
if ( F_9 ( & V_39 -> V_2 -> V_70 ) < 0 )
return - V_23 ;
switch ( V_131 ) {
case V_137 :
V_6 |= F_6 ( V_39 -> V_2 ,
V_135 , V_4 , V_13 , V_14 ) ;
break;
case V_138 :
case V_139 :
default:
V_6 |= F_6 ( V_39 -> V_2 ,
V_133 , V_4 , V_13 , V_14 ) ;
break;
}
F_12 ( & V_39 -> V_2 -> V_70 ) ;
return ( V_6 < 0 ) ? - V_25 : 0 ;
}
static int F_49 ( struct V_38 * V_39 )
{
struct V_15 * V_16 = V_39 -> V_2 -> V_17 ;
const char * V_96 = V_39 -> V_2 -> V_96 -> V_140 ;
char * V_141 [] = { L_35 , L_36 , L_37 ,
L_38 } ;
char * V_140 = V_39 -> V_142 [ 0 ] . V_99 -> V_143 . F_8 . V_140 ;
F_50 ( V_140 , V_96 , 128 ) ;
F_51 ( V_140 , V_141 [ V_16 -> V_53 ] , 128 ) ;
return 0 ;
}
static int F_52 ( struct V_38 * V_39 )
{
struct V_15 * V_16 = V_39 -> V_2 -> V_17 ;
int V_6 = 0 ;
V_16 -> V_74 = 1 ;
V_16 -> V_83 = 4 ;
V_39 -> V_142 [ 0 ] . V_99 = F_53 ( V_144 , & V_145 ,
& V_39 -> V_2 -> V_146 ) ;
if ( V_39 -> V_142 [ 0 ] . V_99 ) {
F_8 ( L_39 ) ;
V_16 -> V_89 = 4 ;
V_16 -> V_88 = 4 ;
V_16 -> V_87 = 0xc0 ;
V_16 -> V_53 = V_54 ;
if ( V_124 != V_54 ) {
V_124 = V_54 ;
V_6 = F_42 ( V_39 -> V_2 -> V_24 , 1 ) ;
}
goto V_110;
}
V_16 -> V_83 = 4 ;
V_39 -> V_142 [ 0 ] . V_99 = F_53 ( V_147 , & V_148 ,
& V_39 -> V_2 -> V_146 ) ;
if ( V_39 -> V_142 [ 0 ] . V_99 ) {
F_8 ( L_40 ) ;
V_16 -> V_89 = 4 ;
V_16 -> V_88 = 5 ;
V_16 -> V_87 = 0xc0 ;
V_16 -> V_53 = V_60 ;
if ( V_124 != V_60 ) {
V_124 = V_60 ;
V_6 = F_42 ( V_39 -> V_2 -> V_24 , 1 ) ;
}
goto V_110;
}
V_16 -> V_83 = 5 ;
V_39 -> V_142 [ 0 ] . V_99 = F_53 ( V_149 , & V_150 ,
& V_39 -> V_2 -> V_146 ) ;
if ( V_39 -> V_142 [ 0 ] . V_99 ) {
F_8 ( L_41 ) ;
V_16 -> V_89 = 4 ;
V_16 -> V_88 = 5 ;
V_16 -> V_87 = 0xc0 ;
V_16 -> V_53 = V_59 ;
if ( V_124 != V_59 ) {
V_124 = V_59 ;
V_6 = F_42 ( V_39 -> V_2 -> V_24 , 1 ) ;
}
} else {
F_8 ( L_42 ) ;
return - V_25 ;
}
V_110: if ( V_6 ) {
if ( V_39 -> V_142 [ 0 ] . V_99 ) {
F_54 ( V_39 -> V_142 [ 0 ] . V_99 ) ;
V_39 -> V_142 [ 0 ] . V_99 = NULL ;
}
V_39 -> V_2 -> V_94 . V_151 . V_152 . V_153 = NULL ;
return - V_25 ;
}
V_39 -> V_142 [ 0 ] . V_99 -> V_143 . V_154 = F_48 ;
V_6 = F_49 ( V_39 ) ;
return V_6 ;
}
static int F_55 ( struct V_38 * V_39 )
{
struct V_15 * V_16 = V_39 -> V_2 -> V_17 ;
char * V_155 [] = { L_35 , L_43 , L_44 , L_45 } ;
int V_6 = 0 ;
switch ( V_16 -> V_53 ) {
case V_54 :
if ( F_53 ( V_156 , V_39 -> V_142 [ 0 ] . V_99 , 0xc0 ,
& V_39 -> V_2 -> V_146 , 1 ) )
V_6 = V_16 -> V_53 ;
break;
case V_59 :
if ( F_53 ( V_157 , V_39 -> V_142 [ 0 ] . V_99 , & V_158 ,
& V_39 -> V_2 -> V_146 ) )
V_6 = V_16 -> V_53 ;
break;
case V_60 :
if ( F_53 ( V_159 , V_39 -> V_142 [ 0 ] . V_99 , 0xc0 ,
& V_39 -> V_2 -> V_146 , V_160 ) )
V_6 = V_16 -> V_53 ;
break;
default:
break;
}
if ( V_6 )
F_8 ( L_46 , V_155 [ V_6 ] ) ;
else {
F_8 ( L_47 ) ;
F_41 ( V_39 -> V_2 -> V_24 ) ;
return - V_25 ;
}
V_6 = F_20 ( V_39 ) ;
if ( V_6 < 0 ) {
F_8 ( L_48 ) ;
return - V_25 ;
}
return V_6 ;
}
static int F_56 ( struct V_9 * V_10 , int V_67 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
static T_1 V_161 [] = V_162 ;
static T_1 V_163 [] = V_164 ;
static T_1 V_13 [ 1 ] ;
int V_6 , V_4 = 3 , V_14 = 1 ;
if ( F_9 ( & V_10 -> V_70 ) < 0 )
return - V_23 ;
if ( V_67 )
V_6 = F_6 ( V_10 , V_161 , V_4 , V_13 , V_14 ) ;
else
V_6 = F_6 ( V_10 , V_163 , V_4 , V_13 , V_14 ) ;
V_16 -> V_74 = 1 ;
F_12 ( & V_10 -> V_70 ) ;
return V_6 ;
}
static int F_57 ( struct V_165 * V_166 ,
const struct V_167 * V_168 )
{
struct V_1 * V_24 = F_58 ( V_166 ) ;
int V_6 = 0 ;
F_59 ( V_24 ) ;
F_60 ( V_24 , V_166 -> V_169 -> V_96 . V_170 , 1 ) ;
if ( V_24 -> V_171 != V_172 ) {
V_6 = F_61 ( V_24 ) ;
F_8 ( L_49 ) ;
return - V_25 ;
}
if ( F_27 ( V_24 ) == 0x44 ) {
F_42 ( V_24 , 0 ) ;
return - V_25 ;
}
if ( 0 == F_62 ( V_166 , & V_173 ,
V_174 , NULL , V_175 ) ) {
F_8 ( L_50 ) ;
return 0 ;
}
if ( 0 == F_62 ( V_166 , & V_176 ,
V_174 , NULL , V_175 ) ) {
F_8 ( L_50 ) ;
return 0 ;
}
F_8 ( L_51 ) ;
return - V_25 ;
}
static void * F_63 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
struct V_38 * V_39 = & V_10 -> V_91 [ 0 ] ;
void * V_63 = NULL ;
if ( V_39 != NULL ) {
F_46 ( & V_39 -> V_142 [ 0 ] . V_127 ) ;
V_39 -> V_177 = 0 ;
}
if ( V_16 -> V_19 != NULL ) {
V_16 -> V_74 = 1 ;
V_16 -> V_55 = 0 ;
V_16 -> V_56 = 0 ;
V_16 -> V_57 = 0 ;
V_63 = V_16 -> V_19 ;
}
if ( V_16 -> V_37 != NULL ) {
F_47 ( V_16 -> V_37 ) ;
F_64 ( V_10 -> V_24 , 128 , V_16 -> V_63 ,
V_16 -> V_37 -> V_64 ) ;
F_8 ( L_52 ) ;
}
return V_63 ;
}
static void F_65 ( struct V_165 * V_166 )
{
struct V_9 * V_10 = F_66 ( V_166 ) ;
void * V_19 ;
if ( V_10 != NULL ) {
V_19 = F_63 ( V_10 ) ;
F_67 ( V_166 ) ;
if ( V_19 != NULL )
F_31 ( V_19 ) ;
}
}

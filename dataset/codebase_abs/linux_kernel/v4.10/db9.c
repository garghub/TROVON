static void F_1 ( struct V_1 * V_2 , int type , unsigned char V_3 , int V_4 , int V_5 )
{
unsigned char V_6 ;
switch ( type ) {
case 1 :
V_6 = 0x80 | 0x30 | ( V_4 ? 0x08 : 0 ) | ( V_5 ? 0x04 : 0 ) | V_3 ;
F_2 ( V_2 , V_6 ) ;
break;
case 2 :
V_6 = 0x40 | V_3 << 4 | ( V_4 ? 0x08 : 0 ) | ( V_5 ? 0x04 : 0 ) | 0x03 ;
F_2 ( V_2 , V_6 ) ;
break;
case 0 :
V_6 = ( ( ( ( V_3 & 2 ) ? 2 : 0 ) | ( ( V_3 & 1 ) ? 4 : 0 ) ) ^ 0x02 ) | ! V_4 ;
F_3 ( V_2 , V_6 ) ;
break;
}
}
static unsigned char F_4 ( struct V_1 * V_2 , int type )
{
unsigned char V_3 ;
if ( type ) {
V_3 = F_5 ( V_2 ) ^ 0x80 ;
return ( V_3 & 0x80 ? 1 : 0 ) | ( V_3 & 0x40 ? 2 : 0 )
| ( V_3 & 0x20 ? 4 : 0 ) | ( V_3 & 0x10 ? 8 : 0 ) ;
} else {
V_3 = F_6 ( V_2 ) & 0x0f ;
return ( V_3 & 0x8 ? 1 : 0 ) | ( V_3 & 0x4 ? 2 : 0 )
| ( V_3 & 0x2 ? 4 : 0 ) | ( V_3 & 0x1 ? 8 : 0 ) ;
}
}
static unsigned char F_7 ( struct V_1 * V_2 , int type , int V_4 )
{
unsigned char V_3 ;
F_1 ( V_2 , type , 0 , V_4 , 0 ) ;
F_8 ( V_7 ) ;
V_3 = F_4 ( V_2 , type ) << 4 ;
F_1 ( V_2 , type , 2 , V_4 , 0 ) ;
F_8 ( V_7 ) ;
V_3 |= F_4 ( V_2 , type ) ;
return V_3 ;
}
static unsigned char F_9 ( struct V_1 * V_2 , unsigned char * V_3 , int type , int V_4 )
{
int V_8 , V_9 ;
unsigned char V_10 ;
F_1 ( V_2 , type , 3 , V_4 , 0 ) ;
V_3 [ 0 ] = F_4 ( V_2 , type ) ;
switch ( V_3 [ 0 ] & 0x0f ) {
case 0xf :
return V_3 [ 0 ] = 0xff ;
case 0x4 : case 0x4 | 0x8 :
F_1 ( V_2 , type , 0 , V_4 , 1 ) ;
V_3 [ 2 ] = F_4 ( V_2 , type ) << 4 ;
F_1 ( V_2 , type , 2 , V_4 , 1 ) ;
V_3 [ 1 ] = F_4 ( V_2 , type ) << 4 ;
F_1 ( V_2 , type , 1 , V_4 , 1 ) ;
V_3 [ 1 ] |= F_4 ( V_2 , type ) ;
F_1 ( V_2 , type , 3 , V_4 , 1 ) ;
V_3 [ 2 ] |= V_3 [ 0 ] ;
return V_3 [ 0 ] = 0x02 ;
case 0x1 :
F_1 ( V_2 , type , 2 , V_4 , 0 ) ;
F_8 ( V_7 ) ;
V_3 [ 0 ] = F_7 ( V_2 , type , V_4 ) ;
if ( V_3 [ 0 ] != 0x41 ) {
for ( V_8 = 0 ; V_8 < ( V_3 [ 0 ] & 0x0f ) ; V_8 ++ )
V_3 [ V_8 + 1 ] = F_7 ( V_2 , type , V_4 ) ;
F_1 ( V_2 , type , 3 , V_4 , 0 ) ;
return V_3 [ 0 ] ;
} else {
if ( F_7 ( V_2 , type , V_4 ) != 0x60 )
return V_3 [ 0 ] = 0xff ;
for ( V_8 = 0 ; V_8 < 60 ; V_8 += 10 ) {
V_3 [ V_8 ] = F_7 ( V_2 , type , V_4 ) ;
if ( V_3 [ V_8 ] != 0xff )
for ( V_9 = 0 ; V_9 < ( V_3 [ V_8 ] & 0x0f ) ; V_9 ++ )
V_3 [ V_8 + V_9 + 1 ] = F_7 ( V_2 , type , V_4 ) ;
}
F_1 ( V_2 , type , 3 , V_4 , 0 ) ;
return 0x41 ;
}
case 0x0 :
F_1 ( V_2 , type , 2 , V_4 , 0 ) ;
F_8 ( V_7 ) ;
V_10 = F_7 ( V_2 , type , V_4 ) ;
if ( V_10 == 0xff ) {
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ )
V_3 [ V_8 + 1 ] = F_7 ( V_2 , type , V_4 ) ;
F_1 ( V_2 , type , 3 , V_4 , 0 ) ;
return V_3 [ 0 ] = 0xe3 ;
}
default:
return V_3 [ 0 ] ;
}
}
static int F_10 ( unsigned char V_11 , unsigned char V_3 [ 60 ] , struct V_12 * V_13 [] , int V_14 , int V_15 )
{
struct V_12 * V_16 ;
int V_10 , V_8 , V_9 ;
V_10 = ( V_11 == 0x41 ) ? 60 : 10 ;
for ( V_9 = 0 ; V_9 < V_10 && V_14 < V_15 ; V_9 += 10 , V_14 ++ ) {
V_16 = V_13 [ V_14 ] ;
switch ( V_3 [ V_9 ] ) {
case 0x16 :
F_11 ( V_16 , V_17 [ 5 ] , V_3 [ V_9 + 6 ] ) ;
case 0x15 :
F_11 ( V_16 , V_17 [ 3 ] , V_3 [ V_9 + 4 ] ) ;
F_11 ( V_16 , V_17 [ 4 ] , V_3 [ V_9 + 5 ] ) ;
case 0x13 :
F_11 ( V_16 , V_17 [ 2 ] , V_3 [ V_9 + 3 ] ) ;
case 0x34 :
case 0x02 :
F_11 ( V_16 , V_17 [ 0 ] , ! ( V_3 [ V_9 + 1 ] & 128 ) - ! ( V_3 [ V_9 + 1 ] & 64 ) ) ;
F_11 ( V_16 , V_17 [ 1 ] , ! ( V_3 [ V_9 + 1 ] & 32 ) - ! ( V_3 [ V_9 + 1 ] & 16 ) ) ;
for ( V_8 = 0 ; V_8 < 9 ; V_8 ++ )
F_12 ( V_16 , V_18 [ V_8 ] , ~ V_3 [ V_9 + V_19 [ V_8 ] ] & V_20 [ V_8 ] ) ;
break;
case 0x19 :
F_11 ( V_16 , V_17 [ 0 ] , ! ( V_3 [ V_9 + 1 ] & 128 ) - ! ( V_3 [ V_9 + 1 ] & 64 ) ) ;
F_11 ( V_16 , V_17 [ 1 ] , ! ( V_3 [ V_9 + 1 ] & 32 ) - ! ( V_3 [ V_9 + 1 ] & 16 ) ) ;
for ( V_8 = 0 ; V_8 < 9 ; V_8 ++ )
F_12 ( V_16 , V_18 [ V_8 ] , ~ V_3 [ V_9 + V_19 [ V_8 ] ] & V_20 [ V_8 ] ) ;
F_11 ( V_16 , V_17 [ 2 ] , V_3 [ V_9 + 3 ] ) ;
F_11 ( V_16 , V_17 [ 3 ] , V_3 [ V_9 + 4 ] ) ;
F_11 ( V_16 , V_17 [ 4 ] , V_3 [ V_9 + 5 ] ) ;
F_11 ( V_16 , V_17 [ 6 ] , V_3 [ V_9 + 7 ] ) ;
F_11 ( V_16 , V_17 [ 7 ] , V_3 [ V_9 + 8 ] ) ;
F_11 ( V_16 , V_17 [ 5 ] , V_3 [ V_9 + 9 ] ) ;
break;
case 0xd3 :
F_12 ( V_16 , V_21 , V_3 [ V_9 + 3 ] & 0x80 ) ;
F_11 ( V_16 , V_17 [ 2 ] , V_3 [ V_9 + 3 ] & 0x7f ) ;
break;
case 0xe3 :
F_12 ( V_16 , V_22 , V_3 [ V_9 + 1 ] & 0x08 ) ;
F_12 ( V_16 , V_21 , V_3 [ V_9 + 1 ] & 0x04 ) ;
F_12 ( V_16 , V_23 , V_3 [ V_9 + 1 ] & 0x02 ) ;
F_12 ( V_16 , V_24 , V_3 [ V_9 + 1 ] & 0x01 ) ;
F_11 ( V_16 , V_17 [ 2 ] , V_3 [ V_9 + 2 ] ^ 0x80 ) ;
F_11 ( V_16 , V_17 [ 3 ] , ( 0xff - ( V_3 [ V_9 + 3 ] ^ 0x80 ) ) + 1 ) ;
break;
case 0xff :
default:
F_11 ( V_16 , V_17 [ 0 ] , 0 ) ;
F_11 ( V_16 , V_17 [ 1 ] , 0 ) ;
for ( V_8 = 0 ; V_8 < 9 ; V_8 ++ )
F_12 ( V_16 , V_18 [ V_8 ] , 0 ) ;
break;
}
}
return V_14 ;
}
static int F_13 ( int V_25 , struct V_1 * V_2 , struct V_12 * V_13 [] )
{
unsigned char V_11 , V_3 [ 60 ] ;
int type , V_14 , V_15 ;
int V_10 , V_8 ;
switch ( V_25 ) {
case V_26 :
type = 0 ;
V_14 = 1 ;
break;
case V_27 :
type = 1 ;
V_14 = 1 ;
break;
case V_28 :
type = 1 ;
V_14 = 2 ;
break;
default:
return - 1 ;
}
V_15 = F_14 ( V_29 [ V_25 ] . V_30 , V_31 ) ;
for ( V_10 = 0 , V_8 = 0 ; V_8 < V_14 ; V_8 ++ ) {
V_11 = F_9 ( V_2 , V_3 , type + V_8 , 1 ) ;
V_10 = F_10 ( V_11 , V_3 , V_13 , V_10 , V_15 ) ;
}
return 0 ;
}
static void F_15 ( unsigned long V_32 )
{
struct V_33 * V_33 = ( void * ) V_32 ;
struct V_1 * V_2 = V_33 -> V_34 -> V_2 ;
struct V_12 * V_16 = V_33 -> V_16 [ 0 ] ;
struct V_12 * V_35 = V_33 -> V_16 [ 1 ] ;
int V_3 , V_8 ;
switch ( V_33 -> V_25 ) {
case V_36 :
V_3 = F_6 ( V_2 ) >> 3 ;
F_11 ( V_35 , V_37 , ( V_3 & V_38 ? 0 : 1 ) - ( V_3 & V_39 ? 0 : 1 ) ) ;
F_11 ( V_35 , V_40 , ( V_3 & V_41 ? 0 : 1 ) - ( V_3 & V_42 ? 0 : 1 ) ) ;
F_12 ( V_35 , V_43 , ~ V_3 & V_44 ) ;
case V_45 :
V_3 = F_5 ( V_2 ) >> 3 ;
F_11 ( V_16 , V_37 , ( V_3 & V_38 ? 0 : 1 ) - ( V_3 & V_39 ? 0 : 1 ) ) ;
F_11 ( V_16 , V_40 , ( V_3 & V_41 ? 0 : 1 ) - ( V_3 & V_42 ? 0 : 1 ) ) ;
F_12 ( V_16 , V_43 , V_3 & V_44 ) ;
break;
case V_46 :
V_3 = F_6 ( V_2 ) ;
F_11 ( V_16 , V_37 , ( V_3 & V_38 ? 0 : 1 ) - ( V_3 & V_39 ? 0 : 1 ) ) ;
F_11 ( V_16 , V_40 , ( V_3 & V_41 ? 0 : 1 ) - ( V_3 & V_42 ? 0 : 1 ) ) ;
F_12 ( V_16 , V_43 , ~ V_3 & V_44 ) ;
break;
case V_47 :
V_3 = F_6 ( V_2 ) ;
F_11 ( V_16 , V_37 , ( V_3 & V_38 ? 0 : 1 ) - ( V_3 & V_39 ? 0 : 1 ) ) ;
F_11 ( V_16 , V_40 , ( V_3 & V_41 ? 0 : 1 ) - ( V_3 & V_42 ? 0 : 1 ) ) ;
F_12 ( V_16 , V_43 , ~ V_3 & V_44 ) ;
F_12 ( V_16 , V_48 , ~ V_3 & V_49 ) ;
break;
case V_50 :
F_3 ( V_2 , V_51 ) ;
V_3 = F_6 ( V_2 ) ;
F_11 ( V_16 , V_37 , ( V_3 & V_38 ? 0 : 1 ) - ( V_3 & V_39 ? 0 : 1 ) ) ;
F_11 ( V_16 , V_40 , ( V_3 & V_41 ? 0 : 1 ) - ( V_3 & V_42 ? 0 : 1 ) ) ;
F_12 ( V_16 , V_24 , ~ V_3 & V_44 ) ;
F_12 ( V_16 , V_23 , ~ V_3 & V_49 ) ;
F_3 ( V_2 , V_52 ) ;
V_3 = F_6 ( V_2 ) ;
F_12 ( V_16 , V_21 , ~ V_3 & V_44 ) ;
F_12 ( V_16 , V_22 , ~ V_3 & V_49 ) ;
break;
case V_53 :
F_3 ( V_2 , V_51 ) ;
V_3 = F_6 ( V_2 ) ;
F_11 ( V_16 , V_37 , ( V_3 & V_38 ? 0 : 1 ) - ( V_3 & V_39 ? 0 : 1 ) ) ;
F_11 ( V_16 , V_40 , ( V_3 & V_41 ? 0 : 1 ) - ( V_3 & V_42 ? 0 : 1 ) ) ;
F_12 ( V_16 , V_24 , ~ V_3 & V_44 ) ;
F_12 ( V_16 , V_23 , ~ V_3 & V_49 ) ;
F_3 ( V_2 , V_52 ) ;
V_3 = F_6 ( V_2 ) ;
F_12 ( V_16 , V_21 , ~ V_3 & V_44 ) ;
F_12 ( V_16 , V_54 , ~ V_3 & V_49 ) ;
F_12 ( V_16 , V_55 , ~ V_3 & V_39 ) ;
F_12 ( V_16 , V_22 , ~ V_3 & V_38 ) ;
break;
case V_56 :
F_3 ( V_2 , V_51 ) ;
F_8 ( V_57 ) ;
V_3 = F_6 ( V_2 ) ;
F_11 ( V_16 , V_37 , ( V_3 & V_38 ? 0 : 1 ) - ( V_3 & V_39 ? 0 : 1 ) ) ;
F_11 ( V_16 , V_40 , ( V_3 & V_41 ? 0 : 1 ) - ( V_3 & V_42 ? 0 : 1 ) ) ;
F_12 ( V_16 , V_24 , ~ V_3 & V_44 ) ;
F_12 ( V_16 , V_23 , ~ V_3 & V_49 ) ;
F_3 ( V_2 , V_52 ) ;
F_8 ( V_57 ) ;
V_3 = F_6 ( V_2 ) ;
F_12 ( V_16 , V_21 , ~ V_3 & V_44 ) ;
F_12 ( V_16 , V_22 , ~ V_3 & V_49 ) ;
F_3 ( V_2 , V_51 ) ;
F_8 ( V_57 ) ;
F_3 ( V_2 , V_52 ) ;
F_8 ( V_57 ) ;
F_3 ( V_2 , V_51 ) ;
F_8 ( V_57 ) ;
V_3 = F_6 ( V_2 ) ;
F_12 ( V_16 , V_54 , ~ V_3 & V_39 ) ;
F_12 ( V_16 , V_55 , ~ V_3 & V_41 ) ;
F_12 ( V_16 , V_58 , ~ V_3 & V_42 ) ;
F_12 ( V_16 , V_59 , ~ V_3 & V_38 ) ;
F_3 ( V_2 , V_52 ) ;
F_8 ( V_57 ) ;
F_3 ( V_2 , V_51 ) ;
F_8 ( V_57 ) ;
F_3 ( V_2 , V_52 ) ;
break;
case V_26 :
case V_27 :
case V_28 :
F_13 ( V_33 -> V_25 , V_2 , V_33 -> V_16 ) ;
break;
case V_60 :
V_3 = F_6 ( V_2 ) ;
F_11 ( V_16 , V_37 , ( V_3 & V_38 ? 0 : 1 ) - ( V_3 & V_39 ? 0 : 1 ) ) ;
F_11 ( V_16 , V_40 , ( V_3 & V_41 ? 0 : 1 ) - ( V_3 & V_42 ? 0 : 1 ) ) ;
F_3 ( V_2 , 0x0a ) ;
for ( V_8 = 0 ; V_8 < 7 ; V_8 ++ ) {
V_3 = F_6 ( V_2 ) ;
F_3 ( V_2 , 0x02 ) ;
F_3 ( V_2 , 0x0a ) ;
F_12 ( V_16 , V_18 [ V_8 ] , ~ V_3 & V_49 ) ;
}
F_3 ( V_2 , 0x00 ) ;
break;
}
F_16 ( V_16 ) ;
F_17 ( & V_33 -> V_61 , V_62 + V_63 ) ;
}
static int F_18 ( struct V_12 * V_16 )
{
struct V_33 * V_33 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_33 -> V_34 -> V_2 ;
int V_64 ;
V_64 = F_20 ( & V_33 -> V_65 ) ;
if ( V_64 )
return V_64 ;
if ( ! V_33 -> V_66 ++ ) {
F_21 ( V_33 -> V_34 ) ;
F_2 ( V_2 , 0xff ) ;
if ( V_29 [ V_33 -> V_25 ] . V_67 ) {
F_22 ( V_2 ) ;
F_3 ( V_2 , V_52 ) ;
}
F_17 ( & V_33 -> V_61 , V_62 + V_63 ) ;
}
F_23 ( & V_33 -> V_65 ) ;
return 0 ;
}
static void F_24 ( struct V_12 * V_16 )
{
struct V_33 * V_33 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_33 -> V_34 -> V_2 ;
F_25 ( & V_33 -> V_65 ) ;
if ( ! -- V_33 -> V_66 ) {
F_26 ( & V_33 -> V_61 ) ;
F_3 ( V_2 , 0x00 ) ;
F_27 ( V_2 ) ;
F_28 ( V_33 -> V_34 ) ;
}
F_23 ( & V_33 -> V_65 ) ;
}
static void F_29 ( struct V_1 * V_68 )
{
struct V_33 * V_33 ;
const struct V_69 * V_70 ;
struct V_71 * V_34 ;
struct V_12 * V_12 ;
int V_8 , V_9 , V_72 ;
int V_25 ;
struct V_73 V_74 ;
for ( V_72 = 0 ; V_72 < V_75 ; V_72 ++ ) {
if ( V_76 [ V_72 ] . V_77 == 0 ||
V_76 [ V_72 ] . args [ V_78 ] < 0 )
continue;
if ( V_76 [ V_72 ] . args [ V_78 ] == V_68 -> V_79 )
break;
}
if ( V_72 == V_75 ) {
F_30 ( L_1 , V_68 -> V_79 ) ;
return;
}
V_25 = V_76 [ V_72 ] . args [ V_80 ] ;
if ( V_25 < 1 || V_25 >= V_81 || ! V_29 [ V_25 ] . V_82 ) {
F_31 ( V_83 L_2 , V_25 ) ;
return;
}
V_70 = & V_29 [ V_25 ] ;
if ( V_70 -> V_84 && ! ( V_68 -> V_85 & V_86 ) ) {
F_31 ( V_83 L_3 ) ;
return;
}
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_87 = V_88 ;
V_34 = F_32 ( V_68 , L_4 , & V_74 , V_72 ) ;
if ( ! V_34 ) {
F_31 ( V_83 L_5 ) ;
return;
}
V_33 = F_33 ( sizeof( struct V_33 ) , V_89 ) ;
if ( ! V_33 )
goto V_90;
F_34 ( & V_33 -> V_65 ) ;
V_33 -> V_34 = V_34 ;
V_33 -> V_25 = V_25 ;
V_33 -> V_91 = V_68 -> V_79 ;
F_35 ( & V_33 -> V_61 ) ;
V_33 -> V_61 . V_3 = ( long ) V_33 ;
V_33 -> V_61 . V_92 = F_15 ;
for ( V_8 = 0 ; V_8 < ( F_14 ( V_70 -> V_30 , V_31 ) ) ; V_8 ++ ) {
V_33 -> V_16 [ V_8 ] = V_12 = F_36 () ;
if ( ! V_12 ) {
F_31 ( V_83 L_6 ) ;
goto V_93;
}
snprintf ( V_33 -> V_94 [ V_8 ] , sizeof( V_33 -> V_94 [ V_8 ] ) ,
L_7 , V_33 -> V_34 -> V_2 -> V_95 , V_8 ) ;
V_12 -> V_95 = V_70 -> V_95 ;
V_12 -> V_94 = V_33 -> V_94 [ V_8 ] ;
V_12 -> V_11 . V_96 = V_97 ;
V_12 -> V_11 . V_98 = 0x0002 ;
V_12 -> V_11 . V_99 = V_25 ;
V_12 -> V_11 . V_100 = 0x0100 ;
F_37 ( V_12 , V_33 ) ;
V_12 -> V_101 = F_18 ;
V_12 -> V_102 = F_24 ;
V_12 -> V_103 [ 0 ] = F_38 ( V_104 ) | F_38 ( V_105 ) ;
for ( V_9 = 0 ; V_9 < V_70 -> V_82 ; V_9 ++ )
F_39 ( V_70 -> V_106 [ V_9 ] , V_12 -> V_107 ) ;
for ( V_9 = 0 ; V_9 < V_70 -> V_108 ; V_9 ++ ) {
if ( V_9 < 2 )
F_40 ( V_12 , V_17 [ V_9 ] , - 1 , 1 , 0 , 0 ) ;
else
F_40 ( V_12 , V_17 [ V_9 ] , 1 , 255 , 0 , 0 ) ;
}
if ( F_41 ( V_12 ) )
goto V_109;
}
V_110 [ V_72 ] = V_33 ;
return;
V_109:
F_42 ( V_33 -> V_16 [ V_8 ] ) ;
V_93:
while ( -- V_8 >= 0 )
F_43 ( V_33 -> V_16 [ V_8 ] ) ;
F_44 ( V_33 ) ;
V_90:
F_45 ( V_34 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_8 ;
struct V_33 * V_33 ;
for ( V_8 = 0 ; V_8 < V_75 ; V_8 ++ ) {
if ( V_110 [ V_8 ] && V_110 [ V_8 ] -> V_91 == V_2 -> V_79 )
break;
}
if ( V_8 == V_75 )
return;
V_33 = V_110 [ V_8 ] ;
V_110 [ V_8 ] = NULL ;
for ( V_8 = 0 ; V_8 < F_14 ( V_29 [ V_33 -> V_25 ] . V_30 , V_31 ) ; V_8 ++ )
F_43 ( V_33 -> V_16 [ V_8 ] ) ;
F_45 ( V_33 -> V_34 ) ;
F_44 ( V_33 ) ;
}
static int T_1 F_47 ( void )
{
int V_8 ;
int V_111 = 0 ;
for ( V_8 = 0 ; V_8 < V_75 ; V_8 ++ ) {
if ( V_76 [ V_8 ] . V_77 == 0 || V_76 [ V_8 ] . args [ V_78 ] < 0 )
continue;
if ( V_76 [ V_8 ] . V_77 < 2 ) {
F_31 ( V_83 L_8 ) ;
return - V_112 ;
}
V_111 = 1 ;
}
if ( ! V_111 )
return - V_113 ;
return F_48 ( & V_114 ) ;
}
static void T_2 F_49 ( void )
{
F_50 ( & V_114 ) ;
}

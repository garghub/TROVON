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
static struct V_33 T_1 * F_29 ( int V_1 , int V_25 )
{
struct V_33 * V_33 ;
const struct V_68 * V_69 ;
struct V_1 * V_70 ;
struct V_71 * V_34 ;
struct V_12 * V_12 ;
int V_8 , V_9 ;
int V_64 ;
if ( V_25 < 1 || V_25 >= V_72 || ! V_29 [ V_25 ] . V_73 ) {
F_30 ( V_74 L_1 , V_25 ) ;
V_64 = - V_75 ;
goto V_76;
}
V_69 = & V_29 [ V_25 ] ;
V_70 = F_31 ( V_1 ) ;
if ( ! V_70 ) {
F_30 ( V_74 L_2 ) ;
V_64 = - V_77 ;
goto V_76;
}
if ( V_69 -> V_78 && ! ( V_70 -> V_79 & V_80 ) ) {
F_30 ( V_74 L_3 ) ;
V_64 = - V_75 ;
goto V_81;
}
V_34 = F_32 ( V_70 , L_4 , NULL , NULL , NULL , V_82 , NULL ) ;
if ( ! V_34 ) {
F_30 ( V_74 L_5 ) ;
V_64 = - V_83 ;
goto V_81;
}
V_33 = F_33 ( sizeof( struct V_33 ) , V_84 ) ;
if ( ! V_33 ) {
F_30 ( V_74 L_6 ) ;
V_64 = - V_85 ;
goto V_86;
}
F_34 ( & V_33 -> V_65 ) ;
V_33 -> V_34 = V_34 ;
V_33 -> V_25 = V_25 ;
F_35 ( & V_33 -> V_61 ) ;
V_33 -> V_61 . V_3 = ( long ) V_33 ;
V_33 -> V_61 . V_87 = F_15 ;
for ( V_8 = 0 ; V_8 < ( F_14 ( V_69 -> V_30 , V_31 ) ) ; V_8 ++ ) {
V_33 -> V_16 [ V_8 ] = V_12 = F_36 () ;
if ( ! V_12 ) {
F_30 ( V_74 L_7 ) ;
V_64 = - V_85 ;
goto V_88;
}
snprintf ( V_33 -> V_89 [ V_8 ] , sizeof( V_33 -> V_89 [ V_8 ] ) ,
L_8 , V_33 -> V_34 -> V_2 -> V_90 , V_8 ) ;
V_12 -> V_90 = V_69 -> V_90 ;
V_12 -> V_89 = V_33 -> V_89 [ V_8 ] ;
V_12 -> V_11 . V_91 = V_92 ;
V_12 -> V_11 . V_93 = 0x0002 ;
V_12 -> V_11 . V_94 = V_25 ;
V_12 -> V_11 . V_95 = 0x0100 ;
F_37 ( V_12 , V_33 ) ;
V_12 -> V_96 = F_18 ;
V_12 -> V_97 = F_24 ;
V_12 -> V_98 [ 0 ] = F_38 ( V_99 ) | F_38 ( V_100 ) ;
for ( V_9 = 0 ; V_9 < V_69 -> V_73 ; V_9 ++ )
F_39 ( V_69 -> V_101 [ V_9 ] , V_12 -> V_102 ) ;
for ( V_9 = 0 ; V_9 < V_69 -> V_103 ; V_9 ++ ) {
if ( V_9 < 2 )
F_40 ( V_12 , V_17 [ V_9 ] , - 1 , 1 , 0 , 0 ) ;
else
F_40 ( V_12 , V_17 [ V_9 ] , 1 , 255 , 0 , 0 ) ;
}
V_64 = F_41 ( V_12 ) ;
if ( V_64 )
goto V_104;
}
F_42 ( V_70 ) ;
return V_33 ;
V_104:
F_43 ( V_33 -> V_16 [ V_8 ] ) ;
V_88:
while ( -- V_8 >= 0 )
F_44 ( V_33 -> V_16 [ V_8 ] ) ;
F_45 ( V_33 ) ;
V_86:
F_46 ( V_34 ) ;
V_81:
F_42 ( V_70 ) ;
V_76:
return F_47 ( V_64 ) ;
}
static void F_48 ( struct V_33 * V_33 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_14 ( V_29 [ V_33 -> V_25 ] . V_30 , V_31 ) ; V_8 ++ )
F_44 ( V_33 -> V_16 [ V_8 ] ) ;
F_46 ( V_33 -> V_34 ) ;
F_45 ( V_33 ) ;
}
static int T_1 F_49 ( void )
{
int V_8 ;
int V_105 = 0 ;
int V_64 = 0 ;
for ( V_8 = 0 ; V_8 < V_106 ; V_8 ++ ) {
if ( V_107 [ V_8 ] . V_108 == 0 || V_107 [ V_8 ] . args [ V_109 ] < 0 )
continue;
if ( V_107 [ V_8 ] . V_108 < 2 ) {
F_30 ( V_74 L_9 ) ;
V_64 = - V_75 ;
break;
}
V_110 [ V_8 ] = F_29 ( V_107 [ V_8 ] . args [ V_109 ] ,
V_107 [ V_8 ] . args [ V_111 ] ) ;
if ( F_50 ( V_110 [ V_8 ] ) ) {
V_64 = F_51 ( V_110 [ V_8 ] ) ;
break;
}
V_105 = 1 ;
}
if ( V_64 ) {
while ( -- V_8 >= 0 )
if ( V_110 [ V_8 ] )
F_48 ( V_110 [ V_8 ] ) ;
return V_64 ;
}
return V_105 ? 0 : - V_77 ;
}
static void T_2 F_52 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_106 ; V_8 ++ )
if ( V_110 [ V_8 ] )
F_48 ( V_110 [ V_8 ] ) ;
}

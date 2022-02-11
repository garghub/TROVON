static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_3 , V_4 } ;
struct V_7 V_8 = { . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 , . V_6 = V_6 , . V_13 = 2 } ;
V_5 = F_2 ( V_2 -> V_14 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_3 ( L_1 ,
V_15 , V_3 , V_5 ) ;
return ( V_5 != 1 ) ? - 1 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_16 , T_1 * V_17 , T_1 V_13 )
{
int V_5 ;
struct V_7 V_8 [] = { { . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 , . V_6 = & V_16 , . V_13 = 1 } ,
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = V_18 , . V_6 = V_17 , . V_13 = V_13 } } ;
V_5 = F_2 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( V_5 != 2 )
F_3 ( L_2 ,
V_15 , V_16 , V_5 ) ;
return V_5 == 2 ? 0 : - 1 ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_19 ;
F_4 ( V_2 , V_3 , & V_19 , 1 ) ;
return V_19 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_20 )
{
if ( V_20 == V_21 )
return 0 ;
return - V_22 ;
}
static int F_7 ( struct V_1 * V_2 , T_3 V_23 )
{
if ( V_23 == V_24 )
return F_1 ( V_2 , 0x07 , 0xff ) ;
if ( V_23 >= V_25 && V_23 <= V_26 )
return F_1 ( V_2 , 0x07 , 1 << ( V_26 - V_23 ) ) ;
return - V_22 ;
}
static T_3 F_8 ( struct V_1 * V_2 )
{
T_1 V_27 ;
static T_3 V_28 [] = { V_26 , V_25 , V_29 , V_30 ,
V_31 , V_32 , V_33 , V_34 } ;
V_27 = F_5 ( V_2 , 0x0e ) & 0x07 ;
return V_28 [ V_27 ] ;
}
static int F_9 ( struct V_1 * V_2 , T_4 V_35 )
{
T_4 V_36 ;
T_4 V_37 ;
T_1 V_38 ;
if ( V_35 > 32000000 )
V_35 = 32000000 ;
if ( V_35 < 500000 )
V_35 = 500000 ;
V_38 = 0 ;
if ( V_35 < 24000000 )
V_38 = 2 ;
if ( V_35 < 16000000 )
V_38 = 3 ;
V_37 = 31250 << 16 ;
V_36 = V_37 / V_35 ;
V_37 = ( V_37 % V_35 ) << 8 ;
V_36 = ( V_36 << 8 ) + V_37 / V_35 ;
V_37 = ( V_37 % V_35 ) << 8 ;
V_36 = ( V_36 << 8 ) + V_37 / V_35 ;
F_3 ( L_3 , ( unsigned int ) V_36 ) ;
F_1 ( V_2 , 0x05 , V_38 ) ;
F_1 ( V_2 , 0x02 , ( V_36 >> 16 ) & 0xff ) ;
F_1 ( V_2 , 0x03 , ( V_36 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x04 , ( V_36 ) & 0xff ) ;
F_1 ( V_2 , 0x00 , 0x3c ) ;
F_1 ( V_2 , 0x00 , 0x04 ) ;
return 1 ;
}
static void F_10 ( struct V_1 * V_2 , int V_39 )
{
unsigned long V_40 = V_41 ;
while ( V_41 - V_40 < V_39 &&
! ( F_5 ( V_2 , 0x02 ) & 0x80 ) )
{
F_11 ( 50 ) ;
} ;
}
static int F_12 ( struct V_1 * V_2 , T_5 V_42 )
{
F_1 ( V_2 , 0x26 , 0xf1 ) ;
switch ( V_42 ) {
case V_43 :
return F_1 ( V_2 , 0x29 , 0x00 ) ;
case V_44 :
return F_1 ( V_2 , 0x29 , 0x80 ) ;
default:
return - V_22 ;
} ;
}
static int F_13 ( struct V_1 * V_2 , T_6 V_45 )
{
switch ( V_45 ) {
case V_46 :
return F_1 ( V_2 , 0x20 , 0x00 ) ;
case V_47 :
return F_1 ( V_2 , 0x20 , 0x11 ) ;
default:
return - V_22 ;
} ;
}
static int F_14 ( struct V_1 * V_2 , T_7 V_48 )
{
switch ( V_48 ) {
case V_49 :
F_1 ( V_2 , 0x29 , ( 5 << 2 ) ) ;
break;
case V_50 :
F_1 ( V_2 , 0x29 , ( 7 << 2 ) ) ;
break;
default:
return - V_22 ;
} ;
F_10 ( V_2 , 100 ) ;
return 0 ;
}
static int F_15 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = V_52 -> V_55 ;
int V_56 ;
F_1 ( V_2 , 0x29 , ( V_54 -> V_57 - 3 ) | ( 1 << 2 ) ) ;
for ( V_56 = 0 ; V_56 < V_54 -> V_57 ; V_56 ++ )
F_1 ( V_2 , 0x23 + V_56 , V_54 -> V_8 [ V_56 ] ) ;
F_1 ( V_2 , 0x29 , ( V_54 -> V_57 - 3 ) | ( 3 << 2 ) ) ;
F_10 ( V_2 , 100 ) ;
return 0 ;
}
static int F_16 ( struct V_51 * V_52 , T_8 * V_58 )
{
struct V_1 * V_2 = V_52 -> V_55 ;
T_1 signal = ~ F_5 ( V_2 , 0x01 ) ;
T_1 V_59 = F_5 ( V_2 , 0x02 ) ;
* V_58 = 0 ;
if ( signal > 10 )
* V_58 |= V_60 ;
if ( V_59 & 0x01 )
* V_58 |= V_61 ;
if ( V_59 & 0x02 )
* V_58 |= V_62 ;
if ( V_59 & 0x10 )
* V_58 |= V_63 ;
if ( V_59 & 0x20 )
* V_58 |= V_64 ;
if ( ( V_59 & 0x1f ) == 0x1f )
* V_58 |= V_65 ;
return 0 ;
}
static int F_17 ( struct V_51 * V_52 , T_4 * V_66 )
{
struct V_1 * V_2 = V_52 -> V_55 ;
int V_5 ;
T_1 V_6 [ 3 ] ;
if ( ( V_5 = F_4 ( V_2 , 0x0b , V_6 , sizeof( V_6 ) ) ) )
return V_5 ;
* V_66 = ( ( V_6 [ 0 ] & 0x1f ) << 16 ) | ( V_6 [ 1 ] << 8 ) | V_6 [ 2 ] ;
return 0 ;
}
static int F_18 ( struct V_51 * V_52 , T_9 * V_67 )
{
struct V_1 * V_2 = V_52 -> V_55 ;
T_1 signal = ~ F_5 ( V_2 , 0x01 ) ;
* V_67 = ( signal << 8 ) | signal ;
return 0 ;
}
static int F_19 ( struct V_51 * V_52 , T_9 * V_68 )
{
struct V_1 * V_2 = V_52 -> V_55 ;
T_1 V_69 = F_5 ( V_2 , 0x08 ) ;
* V_68 = ( V_69 << 8 ) | V_69 ;
return 0 ;
}
static int F_20 ( struct V_51 * V_52 , T_4 * V_70 )
{
struct V_1 * V_2 = V_52 -> V_55 ;
* V_70 = F_5 ( V_2 , 0x0f ) ;
if ( * V_70 == 0xff )
* V_70 = 0xffffffff ;
return 0 ;
}
static int F_21 ( struct V_51 * V_52 )
{
struct V_71 * V_72 = & V_52 -> V_73 ;
struct V_1 * V_2 = V_52 -> V_55 ;
if ( V_52 -> V_74 . V_75 . V_76 ) {
V_52 -> V_74 . V_75 . V_76 ( V_52 ) ;
if ( V_52 -> V_74 . V_77 ) V_52 -> V_74 . V_77 ( V_52 , 0 ) ;
}
F_6 ( V_2 , V_72 -> V_20 ) ;
F_7 ( V_2 , V_72 -> V_78 ) ;
F_9 ( V_2 , V_72 -> V_79 ) ;
F_1 ( V_2 , 0x00 , 0x3c ) ;
F_1 ( V_2 , 0x00 , 0x04 ) ;
return 0 ;
}
static int F_22 ( struct V_51 * V_52 )
{
struct V_71 * V_72 = & V_52 -> V_73 ;
struct V_1 * V_2 = V_52 -> V_55 ;
V_72 -> V_20 = ( F_5 ( V_2 , 0x0e ) & 0x80 ) ?
V_80 : V_81 ;
V_72 -> V_78 = F_8 ( V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_55 ;
F_1 ( V_2 , 0x00 , 0x02 ) ;
return 0 ;
}
static int F_24 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_55 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < 44 ; V_56 ++ )
F_1 ( V_2 , V_56 , V_82 [ V_56 ] ) ;
F_1 ( V_2 , 0x00 , 0x3c ) ;
F_1 ( V_2 , 0x00 , 0x04 ) ;
return 0 ;
}
static int F_25 ( struct V_51 * V_52 , T_7 V_48 )
{
struct V_1 * V_2 = V_52 -> V_55 ;
F_14 ( V_2 , V_48 ) ;
F_1 ( V_2 , 0x00 , 0x3c ) ;
F_1 ( V_2 , 0x00 , 0x04 ) ;
return 0 ;
}
static int F_26 ( struct V_51 * V_52 , T_5 V_42 )
{
struct V_1 * V_2 = V_52 -> V_55 ;
F_12 ( V_2 , V_42 ) ;
F_1 ( V_2 , 0x00 , 0x3c ) ;
F_1 ( V_2 , 0x00 , 0x04 ) ;
return 0 ;
}
static int F_27 ( struct V_51 * V_52 , T_6 V_45 )
{
struct V_1 * V_2 = V_52 -> V_55 ;
F_13 ( V_2 , V_45 ) ;
F_1 ( V_2 , 0x00 , 0x3c ) ;
F_1 ( V_2 , 0x00 , 0x04 ) ;
return 0 ;
}
static void F_28 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_55 ;
F_29 ( V_2 ) ;
}
struct V_51 * F_30 ( const struct V_83 * V_10 ,
struct V_84 * V_14 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_31 ( sizeof( struct V_1 ) , V_85 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
if ( ( F_5 ( V_2 , 0x00 ) ) != 0x05 ) goto error;
memcpy ( & V_2 -> V_86 . V_74 , & V_87 , sizeof( struct V_88 ) ) ;
V_2 -> V_86 . V_55 = V_2 ;
return & V_2 -> V_86 ;
error:
F_29 ( V_2 ) ;
return NULL ;
}

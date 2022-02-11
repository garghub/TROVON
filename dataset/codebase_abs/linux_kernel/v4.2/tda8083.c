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
static int F_6 ( struct V_1 * V_2 ,
enum V_20 V_21 )
{
if ( V_21 == V_22 )
return 0 ;
return - V_23 ;
}
static int F_7 ( struct V_1 * V_2 , enum V_24 V_25 )
{
if ( V_25 == V_26 )
return F_1 ( V_2 , 0x07 , 0xff ) ;
if ( V_25 >= V_27 && V_25 <= V_28 )
return F_1 ( V_2 , 0x07 , 1 << ( V_28 - V_25 ) ) ;
return - V_23 ;
}
static enum V_24 F_8 ( struct V_1 * V_2 )
{
T_1 V_29 ;
static enum V_24 V_30 [] = {
V_28 , V_27 , V_31 , V_32 ,
V_33 , V_34 , V_35 , V_36
} ;
V_29 = F_5 ( V_2 , 0x0e ) & 0x07 ;
return V_30 [ V_29 ] ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_37 )
{
T_2 V_38 ;
T_2 V_39 ;
T_1 V_40 ;
if ( V_37 > 32000000 )
V_37 = 32000000 ;
if ( V_37 < 500000 )
V_37 = 500000 ;
V_40 = 0 ;
if ( V_37 < 24000000 )
V_40 = 2 ;
if ( V_37 < 16000000 )
V_40 = 3 ;
V_39 = 31250 << 16 ;
V_38 = V_39 / V_37 ;
V_39 = ( V_39 % V_37 ) << 8 ;
V_38 = ( V_38 << 8 ) + V_39 / V_37 ;
V_39 = ( V_39 % V_37 ) << 8 ;
V_38 = ( V_38 << 8 ) + V_39 / V_37 ;
F_3 ( L_3 , ( unsigned int ) V_38 ) ;
F_1 ( V_2 , 0x05 , V_40 ) ;
F_1 ( V_2 , 0x02 , ( V_38 >> 16 ) & 0xff ) ;
F_1 ( V_2 , 0x03 , ( V_38 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x04 , ( V_38 ) & 0xff ) ;
F_1 ( V_2 , 0x00 , 0x3c ) ;
F_1 ( V_2 , 0x00 , 0x04 ) ;
return 1 ;
}
static void F_10 ( struct V_1 * V_2 , int V_41 )
{
unsigned long V_42 = V_43 ;
while ( V_43 - V_42 < V_41 &&
! ( F_5 ( V_2 , 0x02 ) & 0x80 ) )
{
F_11 ( 50 ) ;
}
}
static int F_12 ( struct V_1 * V_2 ,
enum V_44 V_45 )
{
F_1 ( V_2 , 0x26 , 0xf1 ) ;
switch ( V_45 ) {
case V_46 :
return F_1 ( V_2 , 0x29 , 0x00 ) ;
case V_47 :
return F_1 ( V_2 , 0x29 , 0x80 ) ;
default:
return - V_23 ;
}
}
static int F_13 ( struct V_1 * V_2 ,
enum V_48 V_49 )
{
switch ( V_49 ) {
case V_50 :
return F_1 ( V_2 , 0x20 , 0x00 ) ;
case V_51 :
return F_1 ( V_2 , 0x20 , 0x11 ) ;
default:
return - V_23 ;
}
}
static int F_14 ( struct V_1 * V_2 ,
enum V_52 V_53 )
{
switch ( V_53 ) {
case V_54 :
F_1 ( V_2 , 0x29 , ( 5 << 2 ) ) ;
break;
case V_55 :
F_1 ( V_2 , 0x29 , ( 7 << 2 ) ) ;
break;
default:
return - V_23 ;
}
F_10 ( V_2 , 100 ) ;
return 0 ;
}
static int F_15 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = V_57 -> V_60 ;
int V_61 ;
F_1 ( V_2 , 0x29 , ( V_59 -> V_62 - 3 ) | ( 1 << 2 ) ) ;
for ( V_61 = 0 ; V_61 < V_59 -> V_62 ; V_61 ++ )
F_1 ( V_2 , 0x23 + V_61 , V_59 -> V_8 [ V_61 ] ) ;
F_1 ( V_2 , 0x29 , ( V_59 -> V_62 - 3 ) | ( 3 << 2 ) ) ;
F_10 ( V_2 , 100 ) ;
return 0 ;
}
static int F_16 ( struct V_56 * V_57 ,
enum V_63 * V_64 )
{
struct V_1 * V_2 = V_57 -> V_60 ;
T_1 signal = ~ F_5 ( V_2 , 0x01 ) ;
T_1 V_65 = F_5 ( V_2 , 0x02 ) ;
* V_64 = 0 ;
if ( signal > 10 )
* V_64 |= V_66 ;
if ( V_65 & 0x01 )
* V_64 |= V_67 ;
if ( V_65 & 0x02 )
* V_64 |= V_68 ;
if ( V_65 & 0x10 )
* V_64 |= V_69 ;
if ( V_65 & 0x20 )
* V_64 |= V_70 ;
if ( ( V_65 & 0x1f ) == 0x1f )
* V_64 |= V_71 ;
return 0 ;
}
static int F_17 ( struct V_56 * V_57 , T_2 * V_72 )
{
struct V_1 * V_2 = V_57 -> V_60 ;
int V_5 ;
T_1 V_6 [ 3 ] ;
if ( ( V_5 = F_4 ( V_2 , 0x0b , V_6 , sizeof( V_6 ) ) ) )
return V_5 ;
* V_72 = ( ( V_6 [ 0 ] & 0x1f ) << 16 ) | ( V_6 [ 1 ] << 8 ) | V_6 [ 2 ] ;
return 0 ;
}
static int F_18 ( struct V_56 * V_57 , T_3 * V_73 )
{
struct V_1 * V_2 = V_57 -> V_60 ;
T_1 signal = ~ F_5 ( V_2 , 0x01 ) ;
* V_73 = ( signal << 8 ) | signal ;
return 0 ;
}
static int F_19 ( struct V_56 * V_57 , T_3 * V_74 )
{
struct V_1 * V_2 = V_57 -> V_60 ;
T_1 V_75 = F_5 ( V_2 , 0x08 ) ;
* V_74 = ( V_75 << 8 ) | V_75 ;
return 0 ;
}
static int F_20 ( struct V_56 * V_57 , T_2 * V_76 )
{
struct V_1 * V_2 = V_57 -> V_60 ;
* V_76 = F_5 ( V_2 , 0x0f ) ;
if ( * V_76 == 0xff )
* V_76 = 0xffffffff ;
return 0 ;
}
static int F_21 ( struct V_56 * V_57 )
{
struct V_77 * V_78 = & V_57 -> V_79 ;
struct V_1 * V_2 = V_57 -> V_60 ;
if ( V_57 -> V_80 . V_81 . V_82 ) {
V_57 -> V_80 . V_81 . V_82 ( V_57 ) ;
if ( V_57 -> V_80 . V_83 ) V_57 -> V_80 . V_83 ( V_57 , 0 ) ;
}
F_6 ( V_2 , V_78 -> V_21 ) ;
F_7 ( V_2 , V_78 -> V_84 ) ;
F_9 ( V_2 , V_78 -> V_85 ) ;
F_1 ( V_2 , 0x00 , 0x3c ) ;
F_1 ( V_2 , 0x00 , 0x04 ) ;
return 0 ;
}
static int F_22 ( struct V_56 * V_57 )
{
struct V_77 * V_78 = & V_57 -> V_79 ;
struct V_1 * V_2 = V_57 -> V_60 ;
V_78 -> V_21 = ( F_5 ( V_2 , 0x0e ) & 0x80 ) ?
V_86 : V_87 ;
V_78 -> V_84 = F_8 ( V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_60 ;
F_1 ( V_2 , 0x00 , 0x02 ) ;
return 0 ;
}
static int F_24 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_60 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < 44 ; V_61 ++ )
F_1 ( V_2 , V_61 , V_88 [ V_61 ] ) ;
F_1 ( V_2 , 0x00 , 0x3c ) ;
F_1 ( V_2 , 0x00 , 0x04 ) ;
return 0 ;
}
static int F_25 ( struct V_56 * V_57 ,
enum V_52 V_53 )
{
struct V_1 * V_2 = V_57 -> V_60 ;
F_14 ( V_2 , V_53 ) ;
F_1 ( V_2 , 0x00 , 0x3c ) ;
F_1 ( V_2 , 0x00 , 0x04 ) ;
return 0 ;
}
static int F_26 ( struct V_56 * V_57 ,
enum V_44 V_45 )
{
struct V_1 * V_2 = V_57 -> V_60 ;
F_12 ( V_2 , V_45 ) ;
F_1 ( V_2 , 0x00 , 0x3c ) ;
F_1 ( V_2 , 0x00 , 0x04 ) ;
return 0 ;
}
static int F_27 ( struct V_56 * V_57 ,
enum V_48 V_49 )
{
struct V_1 * V_2 = V_57 -> V_60 ;
F_13 ( V_2 , V_49 ) ;
F_1 ( V_2 , 0x00 , 0x3c ) ;
F_1 ( V_2 , 0x00 , 0x04 ) ;
return 0 ;
}
static void F_28 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_60 ;
F_29 ( V_2 ) ;
}
struct V_56 * F_30 ( const struct V_89 * V_10 ,
struct V_90 * V_14 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_31 ( sizeof( struct V_1 ) , V_91 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
if ( ( F_5 ( V_2 , 0x00 ) ) != 0x05 ) goto error;
memcpy ( & V_2 -> V_92 . V_80 , & V_93 , sizeof( struct V_94 ) ) ;
V_2 -> V_92 . V_60 = V_2 ;
return & V_2 -> V_92 ;
error:
F_29 ( V_2 ) ;
return NULL ;
}

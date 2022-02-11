static void F_1 ( struct V_1 * V_2 )
{
}
static void F_2 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
}
static void F_3 ( struct V_1 * V_2 ,
unsigned int V_4 , unsigned int V_5 )
{
unsigned int V_6 ;
unsigned int V_7 ;
int V_8 ;
const unsigned int V_9 = 0x010000 ;
const unsigned int CLOCK = 0x020000 ;
const unsigned int V_10 = 0x040000 ;
const unsigned int V_11 = ( V_9 | CLOCK | V_10 ) ;
F_4 ( V_2 ) ;
V_6 = ( ( V_4 & 0x7f ) << 9 ) | ( V_5 & 0x1ff ) ;
F_5 ( V_2 , V_2 -> V_12 . V_13 | V_11 ) ;
F_6 ( V_2 , V_2 -> V_12 . V_14 & ~ V_11 ) ;
V_7 = F_7 ( V_2 ) & ~ V_11 ;
F_8 ( V_2 , V_7 ) ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
F_9 ( 1 ) ;
V_7 &= ~ CLOCK ;
V_6 = ( V_6 << 1 ) ;
if ( V_6 & 0x10000 )
V_7 |= V_9 ;
else
V_7 &= ~ V_9 ;
F_8 ( V_2 , V_7 ) ;
F_9 ( 1 ) ;
V_7 |= CLOCK ;
F_8 ( V_2 , V_7 ) ;
}
F_9 ( 1 ) ;
V_7 |= V_10 ;
F_8 ( V_2 , V_7 ) ;
F_9 ( 1 ) ;
V_7 |= ( V_9 | CLOCK ) ;
F_8 ( V_2 , V_7 ) ;
F_10 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_15 ,
unsigned int V_16 , unsigned int V_17 )
{
switch ( V_15 ) {
case 0 :
F_3 ( V_2 , 0x000 , V_16 ) ;
F_3 ( V_2 , 0x001 , V_17 | 0x100 ) ;
break;
case 1 :
F_3 ( V_2 , 0x004 , V_16 ) ;
F_3 ( V_2 , 0x005 , V_17 | 0x100 ) ;
break;
case 2 :
F_3 ( V_2 , 0x006 , V_16 ) ;
F_3 ( V_2 , 0x007 , V_17 | 0x100 ) ;
break;
}
}
static void F_12 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 0x1f , 0x000 ) ;
F_9 ( 10 ) ;
F_11 ( V_2 , 0 , 0 , 0 ) ;
F_11 ( V_2 , 1 , 0 , 0 ) ;
F_11 ( V_2 , 2 , 0 , 0 ) ;
F_3 ( V_2 , 0x03 , 0x022 ) ;
F_3 ( V_2 , 0x0a , 0x080 ) ;
F_3 ( V_2 , 0x12 , 0x000 ) ;
F_3 ( V_2 , 0x15 , 0x000 ) ;
F_3 ( V_2 , 0x09 , 0x000 ) ;
F_3 ( V_2 , 0x02 , 0x124 ) ;
F_3 ( V_2 , 0x02 , 0x120 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_3 > 96000 )
F_3 ( V_2 , 0x0a , 0x000 ) ;
else
F_3 ( V_2 , 0x0a , 0x080 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
unsigned int V_4 , unsigned int V_5 )
{
unsigned int V_18 ;
V_18 = ( V_4 << 9 ) | V_5 ;
F_15 ( V_2 , 0x34 , V_18 >> 8 , V_18 & 0xff ) ;
}
static void F_16 ( struct V_1 * V_2 ,
unsigned int V_16 , unsigned int V_17 )
{
F_14 ( V_2 , 0x03 , V_16 ) ;
F_14 ( V_2 , 0x04 , V_17 | 0x100 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned int V_16 , unsigned int V_17 )
{
F_14 ( V_2 , 0x0e , V_16 ) ;
F_14 ( V_2 , 0x0f , V_17 | 0x100 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
unsigned int V_19 )
{
static unsigned char V_20 [] = {
0x10 , 0x04 , 0x08 , 0x1c , 0x03
} ;
if ( V_19 > 4 )
V_19 = 4 ;
F_14 ( V_2 , 0x15 , V_20 [ V_19 ] ) ;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_21 )
{
if ( V_21 )
F_14 ( V_2 , 0x16 , 0x005 ) ;
else
F_14 ( V_2 , 0x16 , 0x001 ) ;
}
static void F_20 ( struct V_1 * V_2 , unsigned int V_22 )
{
switch ( V_22 ) {
case 0 :
F_14 ( V_2 , 0x11 , 0x000 ) ;
break;
case 1 :
F_14 ( V_2 , 0x10 , 0x07b ) ;
F_14 ( V_2 , 0x11 , 0x100 ) ;
break;
case 2 :
F_14 ( V_2 , 0x10 , 0x1fb ) ;
F_14 ( V_2 , 0x11 , 0x100 ) ;
break;
}
}
static void F_21 ( struct V_1 * V_2 )
{
int V_8 ;
static unsigned short V_23 [] = {
0x100 , 0x100 , 0x100 ,
0x100 , 0x100 , 0x100 ,
0x000 , 0x090 , 0x000 , 0x000 ,
0x022 , 0x022 , 0x022 ,
0x008 , 0x0cf , 0x0cf , 0x07b , 0x000 ,
0x032 , 0x000 , 0x0a6 , 0x001 , 0x001
} ;
F_14 ( V_2 , 0x17 , 0x000 ) ;
F_9 ( 10 ) ;
for ( V_8 = 0 ; V_8 < F_22 ( V_23 ) ; V_8 ++ )
F_14 ( V_2 , V_8 , V_23 [ V_8 ] ) ;
F_18 ( V_2 , 0 ) ;
F_19 ( V_2 , 0 ) ;
F_20 ( V_2 , 0 ) ;
F_17 ( V_2 , 0 , 0 ) ;
F_16 ( V_2 , 0 , 0 ) ;
F_14 ( V_2 , 0x00 , 0 ) ;
F_14 ( V_2 , 0x01 , 0 ) ;
F_14 ( V_2 , 0x02 , 0x100 ) ;
F_14 ( V_2 , 0x0d , 0x080 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_2 ( V_2 , V_3 ) ;
F_13 ( V_2 , V_3 ) ;
F_23 ( V_2 , V_3 ) ;
}
static int F_25 ( int V_24 )
{
const char * const * V_25 ;
int V_26 ;
V_25 = V_27 [ V_24 ] . V_25 ;
if ( ! V_25 )
return 0 ;
for ( V_26 = 0 ; V_25 [ V_26 ] ; V_26 ++ )
;
return V_26 ;
}
static int F_26 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_31 -> type = V_32 ;
V_31 -> V_33 = 2 ;
V_31 -> V_34 . integer . V_35 = 0 ;
V_31 -> V_34 . integer . V_36 = 0xff ;
return 0 ;
}
static int F_27 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
int V_24 , V_26 ;
V_24 = V_29 -> V_37 ;
V_26 = F_25 ( V_24 ) ;
if ( ! V_26 )
return - V_38 ;
return F_28 ( V_31 , 1 , V_26 , V_27 [ V_24 ] . V_25 ) ;
}
static int F_29 ( struct V_28 * V_29 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_29 ) ;
struct V_41 * V_42 = V_2 -> V_42 ;
int V_24 = V_29 -> V_37 ;
V_40 -> V_34 . integer . V_34 [ 0 ] = V_42 -> V_43 [ V_24 ] . V_44 ;
V_40 -> V_34 . integer . V_34 [ 1 ] = V_42 -> V_43 [ V_24 ] . V_45 ;
return 0 ;
}
static int F_31 ( struct V_28 * V_29 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_29 ) ;
struct V_41 * V_42 = V_2 -> V_42 ;
int V_24 = V_29 -> V_37 ;
V_40 -> V_34 . integer . V_34 [ 0 ] = V_42 -> V_43 [ V_24 ] . V_44 ;
return 0 ;
}
static int F_32 ( struct V_28 * V_29 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_29 ) ;
struct V_41 * V_42 = V_2 -> V_42 ;
int V_24 = V_29 -> V_37 ;
V_40 -> V_34 . V_46 . V_47 [ 0 ] = V_42 -> V_43 [ V_24 ] . V_44 ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 , int V_24 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
switch ( V_27 [ V_24 ] . V_48 ) {
case V_49 :
F_11 ( V_2 ,
V_27 [ V_24 ] . V_15 ,
V_42 -> V_43 [ V_24 ] . V_44 ,
V_42 -> V_43 [ V_24 ] . V_45 ) ;
break;
case V_50 :
F_17 ( V_2 ,
V_42 -> V_43 [ V_24 ] . V_44 ,
V_42 -> V_43 [ V_24 ] . V_45 ) ;
break;
case V_51 :
F_16 ( V_2 ,
V_42 -> V_43 [ V_24 ] . V_44 ,
V_42 -> V_43 [ V_24 ] . V_45 ) ;
break;
case V_52 :
F_18 ( V_2 ,
V_42 -> V_43 [ V_24 ] . V_44 ) ;
break;
case V_53 :
F_20 ( V_2 , V_42 -> V_43 [ V_24 ] . V_44 ) ;
break;
case V_54 :
F_19 ( V_2 , V_42 -> V_43 [ V_24 ] . V_44 ) ;
break;
default:
break;
}
}
static int F_34 ( struct V_28 * V_29 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_29 ) ;
struct V_41 * V_42 = V_2 -> V_42 ;
int V_24 = V_29 -> V_37 ;
unsigned int V_16 , V_17 ;
int V_55 ;
V_55 = 0 ;
V_16 = V_40 -> V_34 . integer . V_34 [ 0 ] & 0xff ;
V_17 = V_40 -> V_34 . integer . V_34 [ 1 ] & 0xff ;
if ( V_42 -> V_43 [ V_24 ] . V_44 != V_16 ) {
V_42 -> V_43 [ V_24 ] . V_44 = V_16 ;
V_55 = 1 ;
}
if ( V_42 -> V_43 [ V_24 ] . V_45 != V_17 ) {
V_42 -> V_43 [ V_24 ] . V_45 = V_17 ;
V_55 = 1 ;
}
if ( V_55 )
F_33 ( V_2 , V_24 ) ;
return V_55 ;
}
static int F_35 ( struct V_28 * V_29 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_29 ) ;
struct V_41 * V_42 = V_2 -> V_42 ;
int V_24 = V_29 -> V_37 ;
unsigned int V_16 ;
V_16 = ! ! V_40 -> V_34 . integer . V_34 [ 0 ] ;
if ( V_42 -> V_43 [ V_24 ] . V_44 != V_16 ) {
V_42 -> V_43 [ V_24 ] . V_44 = V_16 ;
F_33 ( V_2 , V_24 ) ;
return 1 ;
}
return 0 ;
}
static int F_36 ( struct V_28 * V_29 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_29 ) ;
struct V_41 * V_42 = V_2 -> V_42 ;
int V_24 = V_29 -> V_37 ;
unsigned int V_16 ;
V_16 = V_40 -> V_34 . V_46 . V_47 [ 0 ] ;
if ( V_16 >= F_25 ( V_24 ) )
return - V_38 ;
if ( V_42 -> V_43 [ V_24 ] . V_44 != V_16 ) {
V_42 -> V_43 [ V_24 ] . V_44 = V_16 ;
F_33 ( V_2 , V_24 ) ;
return 1 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_8 ;
struct V_56 V_57 ;
int V_58 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_59 = V_60 ;
for ( V_8 = 0 ; V_8 < F_22 ( V_27 ) ; V_8 ++ ) {
V_57 . V_37 = V_8 ;
V_57 . V_61 = V_27 [ V_8 ] . V_61 ;
V_57 . V_62 = V_63 ;
V_57 . V_64 . V_65 = NULL ;
switch ( V_27 [ V_8 ] . type ) {
case V_66 :
case V_67 :
V_57 . V_68 = F_26 ;
V_57 . V_69 = F_29 ;
V_57 . V_70 = F_34 ;
V_57 . V_62 |= V_71 ;
if ( V_27 [ V_8 ] . type == V_66 )
V_57 . V_64 . V_65 = V_72 ;
else
V_57 . V_64 . V_65 = V_73 ;
break;
case BOOLEAN :
V_57 . V_68 = V_74 ;
V_57 . V_69 = F_31 ;
V_57 . V_70 = F_35 ;
break;
case ENUM :
V_57 . V_68 = F_27 ;
V_57 . V_69 = F_32 ;
V_57 . V_70 = F_36 ;
break;
default:
F_38 () ;
return - V_38 ;
}
V_58 = F_39 ( V_2 -> V_75 , F_40 ( & V_57 , V_2 ) ) ;
if ( V_58 < 0 )
return V_58 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_41 * V_42 ;
V_42 = F_42 ( sizeof( * V_42 ) , V_76 ) ;
if ( ! V_42 )
return - V_77 ;
V_2 -> V_42 = V_42 ;
if ( V_2 -> V_78 . V_79 == V_80 ) {
V_2 -> V_81 = 2 ;
V_2 -> V_82 = 0 ;
V_2 -> V_83 = 1 ;
return 0 ;
} else if ( V_2 -> V_78 . V_79 == V_84 ) {
V_2 -> V_81 = 8 ;
V_2 -> V_82 = 2 ;
F_1 ( V_2 ) ;
F_12 ( V_2 ) ;
F_21 ( V_2 ) ;
V_2 -> V_12 . V_85 = F_24 ;
return 0 ;
}
return - V_86 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_58 ;
V_58 = 0 ;
if ( V_2 -> V_78 . V_79 == V_84 )
V_58 = F_37 ( V_2 ) ;
return V_58 ;
}

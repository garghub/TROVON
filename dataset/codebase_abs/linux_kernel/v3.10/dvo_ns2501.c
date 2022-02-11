static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_7 ,
struct V_9 ,
V_7 ) ;
struct V_11 * V_5 = V_10 -> V_5 ;
F_3 ( L_1 , V_12 ) ;
V_4 -> V_13 = F_4 ( V_14 ) ;
V_4 -> V_15 = F_4 ( V_16 ) ;
V_4 -> V_17 = F_4 ( V_18 ) ;
V_4 -> V_19 = F_4 ( V_20 ) ;
F_5 ( V_21 , 0x10004084 ) ;
F_5 ( V_16 , 0xd0820000 ) ;
F_5 ( V_18 , 0x400300 ) ;
F_5 ( V_20 , 0x1080304 ) ;
F_5 ( V_21 , 0x90004084 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_7 ,
struct V_9 ,
V_7 ) ;
struct V_11 * V_5 = V_10 -> V_5 ;
struct V_3 * V_4 = (struct V_3 * ) ( V_2 -> V_5 ) ;
F_5 ( V_21 , V_4 -> V_13 ) ;
F_5 ( V_16 , V_4 -> V_15 ) ;
F_5 ( V_18 , V_4 -> V_17 ) ;
F_5 ( V_20 , V_4 -> V_19 ) ;
}
static bool F_7 ( struct V_1 * V_2 , int V_22 , T_1 * V_23 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
T_2 V_24 [ 2 ] ;
T_2 V_25 [ 2 ] ;
struct V_26 V_27 [] = {
{
. V_22 = V_2 -> V_28 ,
. V_29 = 0 ,
. V_30 = 1 ,
. V_31 = V_24 ,
} ,
{
. V_22 = V_2 -> V_28 ,
. V_29 = V_32 ,
. V_30 = 1 ,
. V_31 = V_25 ,
}
} ;
V_24 [ 0 ] = V_22 ;
V_24 [ 1 ] = 0 ;
if ( F_8 ( V_7 , V_27 , 2 ) == 2 ) {
* V_23 = V_25 [ 0 ] ;
return true ;
} ;
if ( ! V_4 -> V_33 ) {
F_3
( L_2 , V_22 ,
V_7 -> V_34 , V_2 -> V_28 ) ;
}
return false ;
}
static bool F_9 ( struct V_1 * V_2 , int V_22 , T_1 V_23 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_24 [ 2 ] ;
struct V_26 V_35 = {
. V_22 = V_2 -> V_28 ,
. V_29 = 0 ,
. V_30 = 2 ,
. V_31 = V_24 ,
} ;
V_24 [ 0 ] = V_22 ;
V_24 [ 1 ] = V_23 ;
if ( F_8 ( V_7 , & V_35 , 1 ) == 1 ) {
return true ;
}
if ( ! V_4 -> V_33 ) {
F_3 ( L_3 ,
V_22 , V_7 -> V_34 , V_2 -> V_28 ) ;
}
return false ;
}
static bool F_10 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 ;
unsigned char V_23 ;
V_4 = F_11 ( sizeof( struct V_3 ) , V_36 ) ;
if ( V_4 == NULL )
return false ;
V_2 -> V_8 = V_7 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_33 = true ;
if ( ! F_7 ( V_2 , V_37 , & V_23 ) )
goto V_38;
if ( V_23 != ( V_39 & 0xff ) ) {
F_3 ( L_4 ,
V_23 , V_7 -> V_34 , V_2 -> V_28 ) ;
goto V_38;
}
if ( ! F_7 ( V_2 , V_40 , & V_23 ) )
goto V_38;
if ( V_23 != ( V_41 & 0xff ) ) {
F_3 ( L_4 ,
V_23 , V_7 -> V_34 , V_2 -> V_28 ) ;
goto V_38;
}
V_4 -> V_33 = false ;
V_4 -> V_42 = 0 ;
V_4 -> V_43 =
V_44 | V_45 | V_46 | V_47 ;
F_3 ( L_5 ) ;
return true ;
V_38:
F_12 ( V_4 ) ;
return false ;
}
static enum V_48 F_13 ( struct V_1 * V_2 )
{
return V_49 ;
}
static enum V_50 F_14 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
F_3
( L_6 ,
V_12 , V_52 -> V_53 , V_52 -> V_54 , V_52 -> V_55 ,
V_52 -> V_56 ) ;
if ( ( V_52 -> V_53 == 800 && V_52 -> V_55 == 600 ) ||
( V_52 -> V_53 == 640 && V_52 -> V_55 == 480 ) ||
( V_52 -> V_53 == 1024 && V_52 -> V_55 == 768 ) ) {
return V_57 ;
} else {
return V_58 ;
}
}
static void F_15 ( struct V_1 * V_2 ,
struct V_51 * V_52 ,
struct V_51 * V_59 )
{
bool V_60 ;
bool V_61 = false ;
struct V_3 * V_4 = (struct V_3 * ) ( V_2 -> V_5 ) ;
F_3
( L_7 ,
V_12 , V_52 -> V_53 , V_52 -> V_54 , V_52 -> V_55 ,
V_52 -> V_56 ) ;
do {
V_60 = true ;
if ( V_52 -> V_53 == 800 && V_52 -> V_55 == 600 ) {
V_4 -> V_43 &= ~ V_45 ;
F_3 ( L_8 ,
V_12 ) ;
V_60 &= F_9 ( V_2 , 0x11 , 0xc8 ) ;
V_60 &= F_9 ( V_2 , 0x1b , 0x19 ) ;
V_60 &= F_9 ( V_2 , 0x1c , 0x62 ) ;
V_60 &= F_9 ( V_2 , 0x1d , 0x02 ) ;
V_60 &= F_9 ( V_2 , 0x34 , 0x03 ) ;
V_60 &= F_9 ( V_2 , 0x35 , 0xff ) ;
V_60 &= F_9 ( V_2 , 0x80 , 0x27 ) ;
V_60 &= F_9 ( V_2 , 0x81 , 0x03 ) ;
V_60 &= F_9 ( V_2 , 0x82 , 0x41 ) ;
V_60 &= F_9 ( V_2 , 0x83 , 0x05 ) ;
V_60 &= F_9 ( V_2 , 0x8d , 0x02 ) ;
V_60 &= F_9 ( V_2 , 0x8e , 0x04 ) ;
V_60 &= F_9 ( V_2 , 0x8f , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0x90 , 0xfe ) ;
V_60 &= F_9 ( V_2 , 0x91 , 0x07 ) ;
V_60 &= F_9 ( V_2 , 0x94 , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0x95 , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0x96 , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0x99 , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0x9a , 0x88 ) ;
V_60 &= F_9 ( V_2 , 0x9c , 0x23 ) ;
V_60 &= F_9 ( V_2 , 0x9d , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0x9e , 0x25 ) ;
V_60 &= F_9 ( V_2 , 0x9f , 0x03 ) ;
V_60 &= F_9 ( V_2 , 0xa4 , 0x80 ) ;
V_60 &= F_9 ( V_2 , 0xb6 , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0xb9 , 0xc8 ) ;
V_60 &= F_9 ( V_2 , 0xba , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0xc0 , 0x05 ) ;
V_60 &= F_9 ( V_2 , 0xc1 , 0xd7 ) ;
V_60 &= F_9 ( V_2 , 0xc2 , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0xc3 , 0xf8 ) ;
V_60 &= F_9 ( V_2 , 0xc4 , 0x03 ) ;
V_60 &= F_9 ( V_2 , 0xc5 , 0x1a ) ;
V_60 &= F_9 ( V_2 , 0xc6 , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0xc7 , 0x73 ) ;
V_60 &= F_9 ( V_2 , 0xc8 , 0x02 ) ;
} else if ( V_52 -> V_53 == 640 && V_52 -> V_55 == 480 ) {
F_3 ( L_9 ,
V_12 ) ;
V_4 -> V_43 &= ~ V_45 ;
V_60 &= F_9 ( V_2 , 0x11 , 0xa0 ) ;
V_60 &= F_9 ( V_2 , 0x1b , 0x11 ) ;
V_60 &= F_9 ( V_2 , 0x1c , 0x54 ) ;
V_60 &= F_9 ( V_2 , 0x1d , 0x03 ) ;
V_60 &= F_9 ( V_2 , 0x34 , 0x03 ) ;
V_60 &= F_9 ( V_2 , 0x35 , 0xff ) ;
V_60 &= F_9 ( V_2 , 0x80 , 0xff ) ;
V_60 &= F_9 ( V_2 , 0x81 , 0x07 ) ;
V_60 &= F_9 ( V_2 , 0x82 , 0x3d ) ;
V_60 &= F_9 ( V_2 , 0x83 , 0x05 ) ;
V_60 &= F_9 ( V_2 , 0x8d , 0x02 ) ;
V_60 &= F_9 ( V_2 , 0x8e , 0x10 ) ;
V_60 &= F_9 ( V_2 , 0x8f , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0x90 , 0xff ) ;
V_60 &= F_9 ( V_2 , 0x91 , 0x07 ) ;
V_60 &= F_9 ( V_2 , 0x94 , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0x95 , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0x96 , 0x05 ) ;
V_60 &= F_9 ( V_2 , 0x99 , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0x9a , 0x88 ) ;
V_60 &= F_9 ( V_2 , 0x9c , 0x24 ) ;
V_60 &= F_9 ( V_2 , 0x9d , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0x9e , 0x25 ) ;
V_60 &= F_9 ( V_2 , 0x9f , 0x03 ) ;
V_60 &= F_9 ( V_2 , 0xa4 , 0x84 ) ;
V_60 &= F_9 ( V_2 , 0xb6 , 0x09 ) ;
V_60 &= F_9 ( V_2 , 0xb9 , 0xa0 ) ;
V_60 &= F_9 ( V_2 , 0xba , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0xc0 , 0x05 ) ;
V_60 &= F_9 ( V_2 , 0xc1 , 0x90 ) ;
V_60 &= F_9 ( V_2 , 0xc2 , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0xc3 , 0x0f ) ;
V_60 &= F_9 ( V_2 , 0xc4 , 0x03 ) ;
V_60 &= F_9 ( V_2 , 0xc5 , 0x16 ) ;
V_60 &= F_9 ( V_2 , 0xc6 , 0x00 ) ;
V_60 &= F_9 ( V_2 , 0xc7 , 0x02 ) ;
V_60 &= F_9 ( V_2 , 0xc8 , 0x02 ) ;
} else if ( V_52 -> V_53 == 1024 && V_52 -> V_55 == 768 ) {
F_3 ( L_10 ,
V_12 ) ;
V_4 -> V_43 |= V_45 ;
V_60 &= F_9 ( V_2 , 0x37 , 0x44 ) ;
} else {
V_4 -> V_43 |= V_45 ;
}
V_60 &= F_9 ( V_2 , V_62 , V_4 -> V_43 ) ;
if ( ! V_60 ) {
if ( V_61 )
F_6 ( V_2 ) ;
F_1 ( V_2 ) ;
V_61 = true ;
}
} while ( ! V_60 );
if ( V_61 )
F_6 ( V_2 ) ;
}
static bool F_16 ( struct V_1 * V_2 )
{
unsigned char V_23 ;
if ( ! F_7 ( V_2 , V_62 , & V_23 ) )
return false ;
if ( V_23 & V_44 )
return true ;
else
return false ;
}
static void F_17 ( struct V_1 * V_2 , bool V_63 )
{
bool V_60 ;
bool V_61 = false ;
struct V_3 * V_4 = (struct V_3 * ) ( V_2 -> V_5 ) ;
unsigned char V_23 ;
F_3 ( L_11 ,
V_12 , V_63 ) ;
V_23 = V_4 -> V_43 ;
if ( V_63 )
V_23 |= V_44 ;
else
V_23 &= ~ V_44 ;
if ( V_4 -> V_42 == 0 || V_4 -> V_43 != V_23 ) {
V_4 -> V_42 = 1 ;
V_4 -> V_43 = V_23 ;
do {
V_60 = true ;
V_60 &= F_9 ( V_2 , V_62 , V_23 ) ;
V_60 &=
F_9 ( V_2 , 0x34 ,
V_63 ? 0x03 : 0x00 ) ;
V_60 &=
F_9 ( V_2 , 0x35 ,
V_63 ? 0xff : 0x00 ) ;
if ( ! V_60 ) {
if ( V_61 )
F_6 ( V_2 ) ;
F_1 ( V_2 ) ;
V_61 = true ;
}
} while ( ! V_60 );
if ( V_61 )
F_6 ( V_2 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_64 ;
F_7 ( V_2 , V_65 , & V_64 ) ;
F_19 ( L_12 , V_64 ) ;
F_7 ( V_2 , V_66 , & V_64 ) ;
F_19 ( L_13 , V_64 ) ;
F_7 ( V_2 , V_62 , & V_64 ) ;
F_19 ( L_14 , V_64 ) ;
F_7 ( V_2 , V_67 , & V_64 ) ;
F_19 ( L_15 , V_64 ) ;
F_7 ( V_2 , V_68 , & V_64 ) ;
F_19 ( L_16 , V_64 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 ) {
F_12 ( V_4 ) ;
V_2 -> V_5 = NULL ;
}
}

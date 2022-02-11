static bool F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
T_2 V_11 [ 2 ] ;
T_2 V_12 [ 2 ] ;
struct V_13 V_14 [] = {
{
. V_3 = V_2 -> V_15 ,
. V_16 = 0 ,
. V_17 = 1 ,
. V_18 = V_11 ,
} ,
{
. V_3 = V_2 -> V_15 ,
. V_16 = V_19 ,
. V_17 = 1 ,
. V_18 = V_12 ,
}
} ;
V_11 [ 0 ] = V_3 ;
V_11 [ 1 ] = 0 ;
if ( F_2 ( V_9 , V_14 , 2 ) == 2 ) {
* V_4 = V_12 [ 0 ] ;
return true ;
} ;
if ( ! V_6 -> V_20 ) {
F_3
( L_1 , V_3 ,
V_9 -> V_21 , V_2 -> V_15 ) ;
}
return false ;
}
static bool F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
T_1 V_11 [ 2 ] ;
struct V_13 V_22 = {
. V_3 = V_2 -> V_15 ,
. V_16 = 0 ,
. V_17 = 2 ,
. V_18 = V_11 ,
} ;
V_11 [ 0 ] = V_3 ;
V_11 [ 1 ] = V_4 ;
if ( F_2 ( V_9 , & V_22 , 1 ) == 1 ) {
return true ;
}
if ( ! V_6 -> V_20 ) {
F_3 ( L_2 ,
V_3 , V_9 -> V_21 , V_2 -> V_15 ) ;
}
return false ;
}
static bool F_5 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_5 * V_6 ;
unsigned char V_4 ;
V_6 = F_6 ( sizeof( struct V_5 ) , V_23 ) ;
if ( V_6 == NULL )
return false ;
V_2 -> V_10 = V_9 ;
V_2 -> V_7 = V_6 ;
V_6 -> V_20 = true ;
if ( ! F_1 ( V_2 , V_24 , & V_4 ) )
goto V_25;
if ( V_4 != ( V_26 & 0xff ) ) {
F_3 ( L_3 ,
V_4 , V_9 -> V_21 , V_2 -> V_15 ) ;
goto V_25;
}
if ( ! F_1 ( V_2 , V_27 , & V_4 ) )
goto V_25;
if ( V_4 != ( V_28 & 0xff ) ) {
F_3 ( L_3 ,
V_4 , V_9 -> V_21 , V_2 -> V_15 ) ;
goto V_25;
}
V_6 -> V_20 = false ;
V_6 -> V_29 = 0 ;
V_6 -> V_30 =
V_31 | V_32 | V_33 | V_34 ;
F_3 ( L_4 ) ;
return true ;
V_25:
F_7 ( V_6 ) ;
return false ;
}
static enum V_35 F_8 ( struct V_1 * V_2 )
{
return V_36 ;
}
static enum V_37 F_9 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
F_3
( L_5 ,
V_40 , V_39 -> V_41 , V_39 -> V_42 , V_39 -> V_43 ,
V_39 -> V_44 ) ;
if ( ( V_39 -> V_41 == 800 && V_39 -> V_43 == 600 ) ||
( V_39 -> V_41 == 640 && V_39 -> V_43 == 480 ) ||
( V_39 -> V_41 == 1024 && V_39 -> V_43 == 768 ) ) {
return V_45 ;
} else {
return V_46 ;
}
}
static void F_10 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
struct V_38 * V_47 )
{
bool V_48 ;
int V_49 = 10 ;
struct V_5 * V_6 = (struct V_5 * ) ( V_2 -> V_7 ) ;
F_3
( L_6 ,
V_40 , V_39 -> V_41 , V_39 -> V_42 , V_39 -> V_43 ,
V_39 -> V_44 ) ;
do {
V_48 = true ;
if ( V_39 -> V_41 == 800 && V_39 -> V_43 == 600 ) {
V_6 -> V_30 &= ~ V_32 ;
F_3 ( L_7 ,
V_40 ) ;
V_48 &= F_4 ( V_2 , 0x11 , 0xc8 ) ;
V_48 &= F_4 ( V_2 , 0x1b , 0x19 ) ;
V_48 &= F_4 ( V_2 , 0x1c , 0x62 ) ;
V_48 &= F_4 ( V_2 , 0x1d , 0x02 ) ;
V_48 &= F_4 ( V_2 , 0x34 , 0x03 ) ;
V_48 &= F_4 ( V_2 , 0x35 , 0xff ) ;
V_48 &= F_4 ( V_2 , 0x80 , 0x27 ) ;
V_48 &= F_4 ( V_2 , 0x81 , 0x03 ) ;
V_48 &= F_4 ( V_2 , 0x82 , 0x41 ) ;
V_48 &= F_4 ( V_2 , 0x83 , 0x05 ) ;
V_48 &= F_4 ( V_2 , 0x8d , 0x02 ) ;
V_48 &= F_4 ( V_2 , 0x8e , 0x04 ) ;
V_48 &= F_4 ( V_2 , 0x8f , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0x90 , 0xfe ) ;
V_48 &= F_4 ( V_2 , 0x91 , 0x07 ) ;
V_48 &= F_4 ( V_2 , 0x94 , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0x95 , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0x96 , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0x99 , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0x9a , 0x88 ) ;
V_48 &= F_4 ( V_2 , 0x9c , 0x23 ) ;
V_48 &= F_4 ( V_2 , 0x9d , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0x9e , 0x25 ) ;
V_48 &= F_4 ( V_2 , 0x9f , 0x03 ) ;
V_48 &= F_4 ( V_2 , 0xa4 , 0x80 ) ;
V_48 &= F_4 ( V_2 , 0xb6 , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0xb9 , 0xc8 ) ;
V_48 &= F_4 ( V_2 , 0xba , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0xc0 , 0x05 ) ;
V_48 &= F_4 ( V_2 , 0xc1 , 0xd7 ) ;
V_48 &= F_4 ( V_2 , 0xc2 , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0xc3 , 0xf8 ) ;
V_48 &= F_4 ( V_2 , 0xc4 , 0x03 ) ;
V_48 &= F_4 ( V_2 , 0xc5 , 0x1a ) ;
V_48 &= F_4 ( V_2 , 0xc6 , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0xc7 , 0x73 ) ;
V_48 &= F_4 ( V_2 , 0xc8 , 0x02 ) ;
} else if ( V_39 -> V_41 == 640 && V_39 -> V_43 == 480 ) {
F_3 ( L_8 ,
V_40 ) ;
V_6 -> V_30 &= ~ V_32 ;
V_48 &= F_4 ( V_2 , 0x11 , 0xa0 ) ;
V_48 &= F_4 ( V_2 , 0x1b , 0x11 ) ;
V_48 &= F_4 ( V_2 , 0x1c , 0x54 ) ;
V_48 &= F_4 ( V_2 , 0x1d , 0x03 ) ;
V_48 &= F_4 ( V_2 , 0x34 , 0x03 ) ;
V_48 &= F_4 ( V_2 , 0x35 , 0xff ) ;
V_48 &= F_4 ( V_2 , 0x80 , 0xff ) ;
V_48 &= F_4 ( V_2 , 0x81 , 0x07 ) ;
V_48 &= F_4 ( V_2 , 0x82 , 0x3d ) ;
V_48 &= F_4 ( V_2 , 0x83 , 0x05 ) ;
V_48 &= F_4 ( V_2 , 0x8d , 0x02 ) ;
V_48 &= F_4 ( V_2 , 0x8e , 0x10 ) ;
V_48 &= F_4 ( V_2 , 0x8f , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0x90 , 0xff ) ;
V_48 &= F_4 ( V_2 , 0x91 , 0x07 ) ;
V_48 &= F_4 ( V_2 , 0x94 , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0x95 , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0x96 , 0x05 ) ;
V_48 &= F_4 ( V_2 , 0x99 , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0x9a , 0x88 ) ;
V_48 &= F_4 ( V_2 , 0x9c , 0x24 ) ;
V_48 &= F_4 ( V_2 , 0x9d , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0x9e , 0x25 ) ;
V_48 &= F_4 ( V_2 , 0x9f , 0x03 ) ;
V_48 &= F_4 ( V_2 , 0xa4 , 0x84 ) ;
V_48 &= F_4 ( V_2 , 0xb6 , 0x09 ) ;
V_48 &= F_4 ( V_2 , 0xb9 , 0xa0 ) ;
V_48 &= F_4 ( V_2 , 0xba , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0xc0 , 0x05 ) ;
V_48 &= F_4 ( V_2 , 0xc1 , 0x90 ) ;
V_48 &= F_4 ( V_2 , 0xc2 , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0xc3 , 0x0f ) ;
V_48 &= F_4 ( V_2 , 0xc4 , 0x03 ) ;
V_48 &= F_4 ( V_2 , 0xc5 , 0x16 ) ;
V_48 &= F_4 ( V_2 , 0xc6 , 0x00 ) ;
V_48 &= F_4 ( V_2 , 0xc7 , 0x02 ) ;
V_48 &= F_4 ( V_2 , 0xc8 , 0x02 ) ;
} else if ( V_39 -> V_41 == 1024 && V_39 -> V_43 == 768 ) {
F_3 ( L_9 ,
V_40 ) ;
V_6 -> V_30 |= V_32 ;
V_48 &= F_4 ( V_2 , 0x37 , 0x44 ) ;
} else {
V_6 -> V_30 |= V_32 ;
}
V_48 &= F_4 ( V_2 , V_50 , V_6 -> V_30 ) ;
} while ( ! V_48 && V_49 -- );
}
static bool F_11 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
if ( ! F_1 ( V_2 , V_50 , & V_4 ) )
return false ;
if ( V_4 & V_31 )
return true ;
else
return false ;
}
static void F_12 ( struct V_1 * V_2 , bool V_51 )
{
bool V_48 ;
int V_49 = 10 ;
struct V_5 * V_6 = (struct V_5 * ) ( V_2 -> V_7 ) ;
unsigned char V_4 ;
F_3 ( L_10 ,
V_40 , V_51 ) ;
V_4 = V_6 -> V_30 ;
if ( V_51 )
V_4 |= V_31 ;
else
V_4 &= ~ V_31 ;
if ( V_6 -> V_29 == 0 || V_6 -> V_30 != V_4 ) {
V_6 -> V_29 = 1 ;
V_6 -> V_30 = V_4 ;
do {
V_48 = true ;
V_48 &= F_4 ( V_2 , V_50 , V_4 ) ;
V_48 &=
F_4 ( V_2 , 0x34 ,
V_51 ? 0x03 : 0x00 ) ;
V_48 &=
F_4 ( V_2 , 0x35 ,
V_51 ? 0xff : 0x00 ) ;
} while ( ! V_48 && V_49 -- );
}
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_52 ;
F_1 ( V_2 , V_53 , & V_52 ) ;
F_14 ( L_11 , V_52 ) ;
F_1 ( V_2 , V_54 , & V_52 ) ;
F_14 ( L_12 , V_52 ) ;
F_1 ( V_2 , V_50 , & V_52 ) ;
F_14 ( L_13 , V_52 ) ;
F_1 ( V_2 , V_55 , & V_52 ) ;
F_14 ( L_14 , V_52 ) ;
F_1 ( V_2 , V_56 , & V_52 ) ;
F_14 ( L_15 , V_52 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 ) {
F_7 ( V_6 ) ;
V_2 -> V_7 = NULL ;
}
}

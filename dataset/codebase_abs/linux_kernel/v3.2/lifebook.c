static int F_1 ( const struct V_1 * V_2 )
{
V_3 = L_1 ;
return 1 ;
}
static int F_2 ( const struct V_1 * V_2 )
{
V_4 = true ;
return 1 ;
}
void T_1 F_3 ( void )
{
V_5 = F_4 ( V_6 ) ;
}
static T_2 F_5 ( struct V_7 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_12 = V_7 -> V_13 ;
struct V_11 * V_14 = V_9 ? V_9 -> V_14 : NULL ;
unsigned char * V_15 = V_7 -> V_15 ;
bool V_16 = V_15 [ 0 ] & 0x08 ;
if ( V_16 || ! V_4 ) {
if ( V_7 -> V_17 != 3 )
return V_18 ;
} else {
switch ( V_7 -> V_17 ) {
case 1 :
return ( V_15 [ 0 ] & 0xf8 ) == 0x00 ?
V_18 : V_19 ;
case 2 :
return V_18 ;
case 3 :
return ( ( V_15 [ 2 ] & 0x30 ) << 2 ) == ( V_15 [ 2 ] & 0xc0 ) ?
V_18 : V_19 ;
case 4 :
return ( V_15 [ 3 ] & 0xf8 ) == 0xc0 ?
V_18 : V_19 ;
case 5 :
return ( V_15 [ 4 ] & 0xc0 ) == ( V_15 [ 2 ] & 0xc0 ) ?
V_18 : V_19 ;
case 6 :
if ( ( ( V_15 [ 5 ] & 0x30 ) << 2 ) != ( V_15 [ 5 ] & 0xc0 ) )
return V_19 ;
if ( ( V_15 [ 5 ] & 0xc0 ) != ( V_15 [ 1 ] & 0xc0 ) )
return V_19 ;
break;
}
}
if ( V_16 ) {
if ( ! V_14 )
F_6 ( V_7 ,
L_2 ) ;
} else {
if ( V_4 ) {
F_7 ( V_12 , V_20 ,
( ( V_15 [ 1 ] & 0x3f ) << 6 ) | ( V_15 [ 2 ] & 0x3f ) ) ;
F_7 ( V_12 , V_21 ,
4096 - ( ( ( V_15 [ 4 ] & 0x3f ) << 6 ) | ( V_15 [ 5 ] & 0x3f ) ) ) ;
} else {
F_7 ( V_12 , V_20 ,
( V_15 [ 1 ] | ( ( V_15 [ 0 ] & 0x30 ) << 4 ) ) ) ;
F_7 ( V_12 , V_21 ,
1024 - ( V_15 [ 2 ] | ( ( V_15 [ 0 ] & 0xC0 ) << 2 ) ) ) ;
}
F_8 ( V_12 , V_22 , V_15 [ 0 ] & 0x04 ) ;
F_9 ( V_12 ) ;
}
if ( V_14 ) {
if ( V_16 ) {
F_10 ( V_14 , V_23 ,
( ( V_15 [ 0 ] & 0x10 ) ? V_15 [ 1 ] - 256 : V_15 [ 1 ] ) ) ;
F_10 ( V_14 , V_24 ,
- ( int ) ( ( V_15 [ 0 ] & 0x20 ) ? V_15 [ 2 ] - 256 : V_15 [ 2 ] ) ) ;
}
F_8 ( V_14 , V_25 , V_15 [ 0 ] & 0x01 ) ;
F_8 ( V_14 , V_26 , V_15 [ 0 ] & 0x02 ) ;
F_9 ( V_14 ) ;
}
return V_27 ;
}
static int F_11 ( struct V_7 * V_7 )
{
struct V_28 * V_28 = & V_7 -> V_28 ;
unsigned char V_29 ;
if ( F_12 ( V_7 ) )
return - 1 ;
V_29 = V_4 ? 0x08 : 0x07 ;
F_13 ( V_28 , & V_29 , V_30 ) ;
return 0 ;
}
static void F_14 ( struct V_7 * V_7 )
{
struct V_28 * V_28 = & V_7 -> V_28 ;
unsigned char V_29 = 0x06 ;
F_13 ( V_28 , & V_29 , V_30 ) ;
}
static void F_15 ( struct V_7 * V_7 , unsigned int V_31 )
{
static const unsigned char V_32 [] = { 0 , 1 , 2 , 2 , 3 } ;
unsigned char V_33 ;
if ( V_31 == 0 || V_31 > 400 )
V_31 = 400 ;
V_33 = V_32 [ V_31 / 100 ] ;
F_13 ( & V_7 -> V_28 , & V_33 , V_30 ) ;
V_7 -> V_31 = 50 << V_33 ;
}
static void F_16 ( struct V_7 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
F_12 ( V_7 ) ;
if ( V_9 ) {
F_17 ( V_9 -> V_14 ) ;
F_18 ( V_9 ) ;
}
V_7 -> V_10 = NULL ;
}
int F_19 ( struct V_7 * V_7 , bool V_34 )
{
if ( ! V_5 )
return - 1 ;
if ( V_3 &&
strcmp ( V_7 -> V_28 . V_35 -> V_36 , V_3 ) )
return - 1 ;
if ( V_34 ) {
V_7 -> V_37 = L_3 ;
V_7 -> V_38 = L_4 ;
}
return 0 ;
}
static int F_20 ( struct V_7 * V_7 )
{
struct V_11 * V_14 ;
struct V_8 * V_9 ;
int error = - V_39 ;
V_9 = F_21 ( sizeof( struct V_8 ) , V_40 ) ;
V_14 = F_22 () ;
if ( ! V_9 || ! V_14 )
goto V_41;
V_9 -> V_14 = V_14 ;
snprintf ( V_9 -> V_36 , sizeof( V_9 -> V_36 ) ,
L_5 , V_7 -> V_28 . V_35 -> V_36 ) ;
V_14 -> V_36 = V_9 -> V_36 ;
V_14 -> V_38 = L_6 ;
V_14 -> V_42 . V_43 = V_44 ;
V_14 -> V_42 . V_37 = 0x0002 ;
V_14 -> V_42 . V_45 = V_46 ;
V_14 -> V_42 . V_47 = 0x0000 ;
V_14 -> V_13 . V_48 = & V_7 -> V_28 . V_35 -> V_13 ;
V_14 -> V_49 [ 0 ] = F_23 ( V_50 ) | F_23 ( V_51 ) ;
V_14 -> V_52 [ F_24 ( V_23 ) ] = F_23 ( V_23 ) | F_23 ( V_24 ) ;
V_14 -> V_53 [ F_24 ( V_25 ) ] =
F_23 ( V_25 ) | F_23 ( V_26 ) ;
error = F_25 ( V_9 -> V_14 ) ;
if ( error )
goto V_41;
V_7 -> V_10 = V_9 ;
return 0 ;
V_41:
F_26 ( V_14 ) ;
F_18 ( V_9 ) ;
return error ;
}
int F_27 ( struct V_7 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_13 ;
int V_54 = V_4 ? 4096 : 1024 ;
if ( F_11 ( V_7 ) )
return - 1 ;
V_12 -> V_49 [ 0 ] = F_23 ( V_55 ) | F_23 ( V_50 ) ;
V_12 -> V_52 [ 0 ] = 0 ;
V_12 -> V_53 [ F_24 ( V_56 ) ] = 0 ;
V_12 -> V_53 [ F_24 ( V_22 ) ] = F_23 ( V_22 ) ;
F_28 ( V_12 , V_20 , 0 , V_54 , 0 , 0 ) ;
F_28 ( V_12 , V_21 , 0 , V_54 , 0 , 0 ) ;
if ( ! V_3 ) {
if ( F_20 ( V_7 ) ) {
F_14 ( V_7 ) ;
return - 1 ;
}
}
V_7 -> V_57 = F_5 ;
V_7 -> V_58 = F_15 ;
V_7 -> V_59 = F_16 ;
V_7 -> V_60 = F_11 ;
V_7 -> V_61 = V_4 ? 6 : 3 ;
V_7 -> V_62 = 3 ;
return 0 ;
}

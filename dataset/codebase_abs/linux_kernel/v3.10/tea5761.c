static void F_1 ( unsigned char * V_1 )
{
unsigned int div , V_2 ;
div = ( ( V_1 [ 2 ] & 0x3f ) << 8 ) | V_1 [ 3 ] ;
V_2 = 1000 * ( div * 32768 / 1000 + V_3 + 225 ) / 4 ;
F_2 ( V_4 L_1 ,
V_2 / 1000 , V_2 % 1000 , div ) ;
}
static int F_3 ( struct V_5 * V_6 ,
unsigned int V_7 ,
bool V_8 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
unsigned int V_2 = V_7 ;
unsigned char V_1 [ 7 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
unsigned div ;
int V_12 ;
F_4 ( L_2 , V_2 ) ;
if ( V_10 -> V_13 ) {
F_4 ( L_3 ) ;
V_1 [ 5 ] |= V_14 ;
} else {
V_1 [ 4 ] |= V_15 ;
}
if ( V_8 ) {
F_4 ( L_4 ) ;
V_1 [ 5 ] |= V_16 ;
} else {
F_4 ( L_5 ) ;
}
div = ( 1000 * ( V_2 * 4 / 16 + 700 + 225 ) ) >> 15 ;
V_1 [ 1 ] = ( div >> 8 ) & 0x3f ;
V_1 [ 2 ] = div & 0xff ;
if ( V_17 )
F_1 ( V_1 ) ;
if ( 7 != ( V_12 = F_5 ( & V_10 -> V_18 , V_1 , 7 ) ) )
F_6 ( L_6 , V_12 ) ;
V_10 -> V_19 = V_2 * 125 / 2 ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_20 * V_21 )
{
struct V_9 * V_10 = V_6 -> V_22 ;
V_10 -> V_13 = false ;
return F_3 ( V_6 , V_21 -> V_19 ,
V_21 -> V_23 == V_24 ) ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_22 ;
V_10 -> V_13 = true ;
return F_3 ( V_6 , V_10 -> V_19 , false ) ;
}
static int F_9 ( struct V_5 * V_6 , char * V_1 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
int V_12 ;
memset ( V_1 , 0 , 16 ) ;
if ( 16 != ( V_12 = F_10 ( & V_10 -> V_18 , V_1 , 16 ) ) ) {
F_6 ( L_7 , V_12 ) ;
return - V_25 ;
}
return 0 ;
}
static inline int F_11 ( struct V_5 * V_6 , const char * V_1 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
int signal = ( ( V_1 [ 9 ] & V_26 ) << ( 13 - 4 ) ) ;
F_4 ( L_8 , signal ) ;
return signal ;
}
static inline int F_12 ( struct V_5 * V_6 , const char * V_1 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
int V_27 = V_1 [ 9 ] & V_28 ;
F_4 ( L_9 , V_27 ) ;
return ( V_27 ? V_29 : 0 ) ;
}
static int F_13 ( struct V_5 * V_6 , T_1 * V_30 )
{
unsigned char V_1 [ 16 ] ;
* V_30 = 0 ;
if ( 0 == F_9 ( V_6 , V_1 ) ) {
if ( F_11 ( V_6 , V_1 ) )
* V_30 = V_31 ;
if ( F_12 ( V_6 , V_1 ) )
* V_30 |= V_32 ;
}
return 0 ;
}
static int F_14 ( struct V_5 * V_6 , T_2 * V_33 )
{
unsigned char V_1 [ 16 ] ;
* V_33 = 0 ;
if ( 0 == F_9 ( V_6 , V_1 ) )
* V_33 = F_11 ( V_6 , V_1 ) ;
return 0 ;
}
int F_15 ( struct V_34 * V_35 , T_3 V_36 )
{
unsigned char V_1 [ 16 ] ;
int V_12 ;
struct V_37 V_38 = { . V_39 = V_35 , . V_40 = V_36 } ;
if ( 16 != ( V_12 = F_10 ( & V_38 , V_1 , 16 ) ) ) {
F_2 ( V_41 L_10 , V_12 ) ;
return - V_42 ;
}
if ( ( V_1 [ 13 ] != 0x2b ) || ( V_1 [ 14 ] != 0x57 ) || ( V_1 [ 15 ] != 0x061 ) ) {
F_2 ( V_41 L_11
L_12 ,
V_1 [ 13 ] , V_1 [ 14 ] , V_1 [ 15 ] ) ;
return - V_42 ;
}
F_2 ( V_41 L_13
L_14 ,
V_1 [ 14 ] , V_1 [ 15 ] , V_1 [ 13 ] ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 )
{
F_17 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
return 0 ;
}
static int F_18 ( struct V_5 * V_6 , T_1 * V_19 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
* V_19 = V_10 -> V_19 ;
return 0 ;
}
struct V_5 * F_19 ( struct V_5 * V_6 ,
struct V_34 * V_35 ,
T_3 V_36 )
{
struct V_9 * V_10 = NULL ;
if ( F_15 ( V_35 , V_36 ) != 0 )
return NULL ;
V_10 = F_20 ( sizeof( struct V_9 ) , V_43 ) ;
if ( V_10 == NULL )
return NULL ;
V_6 -> V_11 = V_10 ;
V_10 -> V_18 . V_40 = V_36 ;
V_10 -> V_18 . V_39 = V_35 ;
V_10 -> V_18 . V_44 = L_15 ;
memcpy ( & V_6 -> V_45 . V_46 , & V_47 ,
sizeof( struct V_48 ) ) ;
F_21 ( L_16 , L_17 ) ;
return V_6 ;
}

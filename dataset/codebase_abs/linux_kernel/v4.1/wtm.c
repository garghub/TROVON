static inline void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_4 )
{
F_2 ( V_2 , V_5 , V_3 , V_4 ) ;
}
static inline unsigned char F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 , V_5 , V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_4 )
{
F_2 ( V_2 , V_6 , V_3 , V_4 ) ;
}
static inline unsigned char F_6 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 , V_6 , V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned char V_7 ,
unsigned short int * V_8 )
{
unsigned char V_9 , V_10 ;
int V_11 , V_12 , V_13 ;
for ( V_11 = 0 ; V_11 < 7 ; V_11 ++ ) {
if ( * V_8 & ( 0x01 << V_11 ) ) {
if ( V_11 == 0 )
V_12 = V_14 ;
else
V_12 = V_15 - 1 + V_11 ;
V_10 = F_3 ( V_2 , V_12 ) ;
V_9 = ( ~ V_7 << 7 & 0x80 ) | ( V_10 & ~ 0x80 ) ;
V_13 = ( V_9 != V_10 ) ;
if ( V_13 ) {
F_1 ( V_2 , V_12 , V_9 ) ;
* V_8 = * V_8 | ( 0x01 << V_11 ) ;
} else {
* V_8 = * V_8 & ~ ( 0x01 << V_11 ) ;
}
}
}
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
if ( * V_8 & ( 0x01 << ( V_11 + 7 ) ) ) {
if ( V_11 == 0 )
V_12 = V_14 ;
else
V_12 = V_15 - 1 + V_11 ;
V_10 = F_6 ( V_2 , V_12 ) ;
V_9 = ( ~ V_7 << 7 & 0x80 ) | ( V_10 & ~ 0x80 ) ;
V_13 = ( V_9 != V_10 ) ;
if ( V_13 ) {
F_5 ( V_2 , V_12 , V_9 ) ;
* V_8 = * V_8 | ( 0x01 << V_11 ) ;
} else {
* V_8 = * V_8 & ~ ( 0x01 << V_11 ) ;
}
}
}
}
static int F_8 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_20 * V_21 = V_2 -> V_21 ;
unsigned char V_4 ;
int V_12 , V_11 ;
F_10 ( & V_21 -> V_22 ) ;
if ( V_17 -> V_23 ) {
V_12 = V_14 ;
V_11 = 0 ;
} else {
V_11 = F_11 ( V_17 , & V_19 -> V_11 ) ;
V_12 = V_11 + V_15 ;
}
if ( V_11 < 6 )
V_4 = F_3 ( V_2 , V_12 ) ;
else
V_4 = F_6 ( V_2 , V_12 - 6 ) ;
V_19 -> V_24 . integer . V_24 [ 0 ] = ( ~ V_4 >> 7 ) & 0x1 ;
F_12 ( & V_21 -> V_22 ) ;
return 0 ;
}
static int F_13 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned char V_9 , V_10 ;
int V_11 , V_12 ;
int V_13 ;
if ( V_17 -> V_23 ) {
V_12 = V_14 ;
V_10 = F_3 ( V_2 , V_12 ) ;
V_9 = ( ~ V_19 -> V_24 . integer . V_24 [ 0 ] << 7 & 0x80 ) |
( V_10 & ~ 0x80 ) ;
V_13 = ( V_9 != V_10 ) ;
if ( V_13 ) {
F_1 ( V_2 , V_12 , V_9 ) ;
F_5 ( V_2 , V_12 , V_9 ) ;
}
} else {
V_11 = F_11 ( V_17 , & V_19 -> V_11 ) ;
V_12 = V_11 + V_15 ;
if ( V_11 < 6 )
V_10 = F_3 ( V_2 , V_12 ) ;
else
V_10 = F_6 ( V_2 , V_12 - 6 ) ;
V_9 = ( ~ V_19 -> V_24 . integer . V_24 [ 0 ] << 7 & 0x80 ) |
( V_10 & ~ 0x80 ) ;
V_13 = ( V_9 != V_10 ) ;
if ( V_13 ) {
if ( V_11 < 6 )
F_1 ( V_2 , V_12 , V_9 ) ;
else
F_5 ( V_2 , V_12 - 6 , V_9 ) ;
}
}
return V_13 ;
}
static int F_14 ( struct V_16 * V_17 ,
struct V_25 * V_26 )
{
V_26 -> type = V_27 ;
V_26 -> V_28 = 1 ;
V_26 -> V_24 . integer . V_29 = 0 ;
V_26 -> V_24 . integer . V_30 = 0x7f ;
return 0 ;
}
static int F_15 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_12 , V_11 ;
unsigned char V_31 ;
if ( V_17 -> V_23 ) {
V_12 = V_14 ;
V_11 = 0 ;
} else {
V_11 = F_11 ( V_17 , & V_19 -> V_11 ) ;
V_12 = V_11 + V_15 ;
}
if ( V_11 < 6 )
V_31 = F_3 ( V_2 , V_12 ) & 0x7f ;
else
V_31 = F_6 ( V_2 , V_12 - 6 ) & 0x7f ;
V_19 -> V_24 . integer . V_24 [ 0 ] = 0x7f - V_31 ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_12 , V_11 ;
unsigned char V_32 , V_33 , V_34 ;
int V_13 ;
if ( V_17 -> V_23 ) {
V_12 = V_14 ;
V_34 = V_19 -> V_24 . integer . V_24 [ 0 ] & 0x7f ;
V_32 = F_3 ( V_2 , V_12 ) ;
V_33 = 0x7f - ( V_32 & 0x7f ) ;
V_13 = ( V_33 != V_34 ) ;
if ( V_13 ) {
F_1 ( V_2 , V_12 , ( 0x7f - V_34 ) | ( V_32 & 0x80 ) ) ;
F_5 ( V_2 , V_12 , ( 0x7f - V_34 ) | ( V_32 & 0x80 ) ) ;
}
} else {
V_11 = F_11 ( V_17 , & V_19 -> V_11 ) ;
V_12 = V_11 + V_15 ;
V_34 = V_19 -> V_24 . integer . V_24 [ 0 ] & 0x7f ;
if ( V_11 < 6 )
V_32 = F_3 ( V_2 , V_12 ) ;
else
V_32 = F_6 ( V_2 , V_12 - 6 ) ;
V_33 = 0x7f - ( V_32 & 0x7f ) ;
V_13 = ( V_33 != V_34 ) ;
if ( V_13 ) {
if ( V_11 < 6 )
F_1 ( V_2 , V_12 , ( 0x7f - V_34 ) |
( V_32 & 0x80 ) ) ;
else
F_5 ( V_2 , V_12 - 6 , ( 0x7f - V_34 ) |
( V_32 & 0x80 ) ) ;
}
}
return V_13 ;
}
static int F_17 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned char V_4 ;
int V_35 , V_11 ;
V_11 = F_11 ( V_17 , & V_19 -> V_11 ) ;
if ( V_11 == 0 ) {
for ( V_35 = 0 ; V_35 < 2 ; ++ V_35 ) {
V_4 = F_3 ( V_2 , V_36 + V_35 ) ;
V_19 -> V_24 . integer . V_24 [ V_35 ] = ~ V_4 >> 7 & 0x1 ;
}
} else {
for ( V_35 = 0 ; V_35 < 2 ; ++ V_35 ) {
V_4 = F_6 ( V_2 , V_36 + V_35 ) ;
V_19 -> V_24 . integer . V_24 [ V_35 ] = ~ V_4 >> 7 & 0x1 ;
}
}
return 0 ;
}
static int F_18 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned char V_9 , V_10 ;
int V_35 , V_3 , V_11 ;
int V_13 ;
V_11 = F_11 ( V_17 , & V_19 -> V_11 ) ;
if ( V_11 == 0 ) {
for ( V_35 = 0 ; V_35 < 2 ; ++ V_35 ) {
V_3 = V_36 + V_35 ;
V_10 = F_3 ( V_2 , V_3 ) ;
V_9 = ( ~ V_19 -> V_24 . integer . V_24 [ V_35 ] << 7 & 0x80 ) |
( V_10 & ~ 0x80 ) ;
V_13 = ( V_9 != V_10 ) ;
if ( V_13 )
F_1 ( V_2 , V_3 , V_9 ) ;
}
} else {
for ( V_35 = 0 ; V_35 < 2 ; ++ V_35 ) {
V_3 = V_36 + V_35 ;
V_10 = F_6 ( V_2 , V_3 ) ;
V_9 = ( ~ V_19 -> V_24 . integer . V_24 [ V_35 ] << 7 & 0x80 ) |
( V_10 & ~ 0x80 ) ;
V_13 = ( V_9 != V_10 ) ;
if ( V_13 )
F_5 ( V_2 , V_3 , V_9 ) ;
}
}
return V_13 ;
}
static int F_19 ( struct V_16 * V_17 ,
struct V_25 * V_26 )
{
V_26 -> type = V_27 ;
V_26 -> V_28 = 2 ;
V_26 -> V_24 . integer . V_29 = 0 ;
V_26 -> V_24 . integer . V_30 = 0x0f ;
return 0 ;
}
static int F_20 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_35 , V_3 , V_11 ;
unsigned char V_31 ;
V_11 = F_11 ( V_17 , & V_19 -> V_11 ) ;
if ( V_11 == 0 ) {
for ( V_35 = 0 ; V_35 < 2 ; ++ V_35 ) {
V_3 = V_36 + V_35 ;
V_31 = F_3 ( V_2 , V_3 ) & 0x0f ;
V_19 -> V_24 . integer . V_24 [ V_35 ] = 0x0f - V_31 ;
}
} else {
for ( V_35 = 0 ; V_35 < 2 ; ++ V_35 ) {
V_3 = V_36 + V_35 ;
V_31 = F_6 ( V_2 , V_3 ) & 0x0f ;
V_19 -> V_24 . integer . V_24 [ V_35 ] = 0x0f - V_31 ;
}
}
return 0 ;
}
static int F_21 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_35 , V_3 , V_11 ;
unsigned char V_33 , V_34 ;
int V_13 ;
V_11 = F_11 ( V_17 , & V_19 -> V_11 ) ;
if ( V_11 == 0 ) {
for ( V_35 = 0 ; V_35 < 2 ; ++ V_35 ) {
V_3 = V_36 + V_35 ;
V_34 = V_19 -> V_24 . integer . V_24 [ V_35 ] & 0x0f ;
V_33 = 0x0f - F_3 ( V_2 , V_3 ) ;
V_13 = ( ( V_33 & 0x0f ) != V_34 ) ;
if ( V_13 )
F_1 ( V_2 , V_3 , ( 0x0f - V_34 ) |
( V_33 & ~ 0x0f ) ) ;
}
} else {
for ( V_35 = 0 ; V_35 < 2 ; ++ V_35 ) {
V_3 = V_36 + V_35 ;
V_34 = V_19 -> V_24 . integer . V_24 [ V_35 ] & 0x0f ;
V_33 = 0x0f - F_6 ( V_2 , V_3 ) ;
V_13 = ( ( V_33 & 0x0f ) != V_34 ) ;
if ( V_13 )
F_5 ( V_2 , V_3 , ( 0x0f - V_34 ) |
( V_33 & ~ 0x0f ) ) ;
}
}
return V_13 ;
}
static int F_22 ( struct V_16 * V_17 ,
struct V_25 * V_26 )
{
static const char * const V_37 [ 2 ] = { L_1 , L_2 } ;
return F_23 ( V_26 , 1 , 2 , V_37 ) ;
}
static int F_24 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned char V_4 ;
int V_11 ;
V_11 = F_11 ( V_17 , & V_19 -> V_11 ) ;
if ( V_11 == 0 )
V_4 = F_3 ( V_2 , V_38 ) ;
else
V_4 = F_6 ( V_2 , V_38 ) ;
V_19 -> V_24 . V_39 . V_40 [ 0 ] = ( V_4 >> 7 ) & 0x1 ;
return 0 ;
}
static int F_25 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned char V_9 , V_10 ;
int V_13 , V_11 ;
V_11 = F_11 ( V_17 , & V_19 -> V_11 ) ;
if ( V_11 == 0 )
V_10 = F_3 ( V_2 , V_38 ) ;
else
V_10 = F_6 ( V_2 , V_38 ) ;
V_9 = ( V_19 -> V_24 . V_39 . V_40 [ 0 ] << 7 & 0x80 ) | ( V_10 & ~ 0x80 ) ;
V_13 = ( V_9 != V_10 ) ;
if ( V_13 ) {
if ( V_11 == 0 )
F_1 ( V_2 , V_38 , V_9 ) ;
else
F_5 ( V_2 , V_38 , V_9 ) ;
}
return V_13 ;
}
static void F_26 ( struct V_1 * V_2 , unsigned int V_41 )
{
unsigned char V_10 , V_9 ;
unsigned short int V_42 ;
struct V_20 * V_21 = V_2 -> V_21 ;
if ( V_41 == 0 )
return;
else if ( V_41 <= 48000 )
V_9 = 0x08 ;
else if ( V_41 <= 96000 )
V_9 = 0x11 ;
else
V_9 = 0x12 ;
V_10 = F_3 ( V_2 , V_43 ) ;
if ( V_10 == V_9 )
return;
F_10 ( & V_21 -> V_22 ) ;
V_42 = 0xFFFF ;
F_7 ( V_2 , 0 , & V_42 ) ;
F_1 ( V_2 , V_43 , V_9 ) ;
F_5 ( V_2 , V_43 , V_9 ) ;
F_27 ( 10 ) ;
F_7 ( V_2 , 1 , & V_42 ) ;
F_12 ( & V_21 -> V_22 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
unsigned int V_35 ;
int V_44 ;
for ( V_35 = 0 ; V_35 < F_29 ( V_45 ) ; V_35 ++ ) {
V_44 = F_30 ( V_2 -> V_46 ,
F_31 ( & V_45 [ V_35 ] , V_2 ) ) ;
if ( V_44 < 0 )
return V_44 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
static unsigned short V_47 [] = {
V_48 , 0 ,
V_43 , 0x11 ,
( unsigned short ) - 1
} ;
unsigned short * V_49 ;
struct V_20 * V_21 ;
V_2 -> V_50 = 8 ;
V_2 -> V_51 = 4 ;
V_2 -> V_52 = 1 ;
V_21 = F_33 ( sizeof( * V_21 ) , V_53 ) ;
if ( ! V_21 )
return - V_54 ;
V_2 -> V_21 = V_21 ;
F_34 ( & V_21 -> V_22 ) ;
V_49 = V_47 ;
for (; * V_49 != ( unsigned short ) - 1 ; V_49 += 2 ) {
F_1 ( V_2 , V_49 [ 0 ] , V_49 [ 1 ] ) ;
F_5 ( V_2 , V_49 [ 0 ] , V_49 [ 1 ] ) ;
}
V_2 -> V_55 . V_56 = F_26 ;
return 0 ;
}

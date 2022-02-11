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
static int F_7 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
unsigned char V_4 ;
int V_11 , V_12 ;
if ( V_8 -> V_13 ) {
V_11 = V_14 ;
V_12 = 0 ;
} else {
V_12 = F_9 ( V_8 , & V_10 -> V_12 ) ;
V_11 = V_12 + V_15 ;
}
if ( V_12 < 6 )
V_4 = F_3 ( V_2 , V_11 ) ;
else
V_4 = F_6 ( V_2 , V_11 - 6 ) ;
V_10 -> V_16 . integer . V_16 [ 0 ] = ( ~ V_4 >> 7 ) & 0x1 ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
unsigned char V_17 , V_18 ;
int V_12 , V_11 ;
int V_19 ;
if ( V_8 -> V_13 ) {
V_11 = V_14 ;
V_18 = F_3 ( V_2 , V_11 ) ;
V_17 = ( ~ V_10 -> V_16 . integer . V_16 [ 0 ] << 7 & 0x80 ) |
( V_18 & ~ 0x80 ) ;
V_19 = ( V_17 != V_18 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_11 , V_17 ) ;
F_5 ( V_2 , V_11 , V_17 ) ;
}
} else {
V_12 = F_9 ( V_8 , & V_10 -> V_12 ) ;
V_11 = V_12 + V_15 ;
if ( V_12 < 6 )
V_18 = F_3 ( V_2 , V_11 ) ;
else
V_18 = F_6 ( V_2 , V_11 - 6 ) ;
V_17 = ( ~ V_10 -> V_16 . integer . V_16 [ 0 ] << 7 & 0x80 ) |
( V_18 & ~ 0x80 ) ;
V_19 = ( V_17 != V_18 ) ;
if ( V_19 ) {
if ( V_12 < 6 )
F_1 ( V_2 , V_11 , V_17 ) ;
else
F_5 ( V_2 , V_11 - 6 , V_17 ) ;
}
}
return V_19 ;
}
static int F_11 ( struct V_7 * V_8 ,
struct V_20 * V_21 )
{
V_21 -> type = V_22 ;
V_21 -> V_23 = 1 ;
V_21 -> V_16 . integer . V_24 = 0 ;
V_21 -> V_16 . integer . V_25 = 0x7f ;
return 0 ;
}
static int F_12 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
int V_11 , V_12 ;
unsigned char V_26 ;
if ( V_8 -> V_13 ) {
V_11 = V_14 ;
V_12 = 0 ;
} else {
V_12 = F_9 ( V_8 , & V_10 -> V_12 ) ;
V_11 = V_12 + V_15 ;
}
if ( V_12 < 6 )
V_26 = F_3 ( V_2 , V_11 ) & 0x7f ;
else
V_26 = F_6 ( V_2 , V_11 - 6 ) & 0x7f ;
V_10 -> V_16 . integer . V_16 [ 0 ] = 0x7f - V_26 ;
return 0 ;
}
static int F_13 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
int V_11 , V_12 ;
unsigned char V_27 , V_28 , V_29 ;
int V_19 ;
if ( V_8 -> V_13 ) {
V_11 = V_14 ;
V_29 = V_10 -> V_16 . integer . V_16 [ 0 ] & 0x7f ;
V_27 = F_3 ( V_2 , V_11 ) ;
V_28 = 0x7f - ( V_27 & 0x7f ) ;
V_19 = ( V_28 != V_29 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_11 , ( 0x7f - V_29 ) | ( V_27 & 0x80 ) ) ;
F_5 ( V_2 , V_11 , ( 0x7f - V_29 ) | ( V_27 & 0x80 ) ) ;
}
} else {
V_12 = F_9 ( V_8 , & V_10 -> V_12 ) ;
V_11 = V_12 + V_15 ;
V_29 = V_10 -> V_16 . integer . V_16 [ 0 ] & 0x7f ;
if ( V_12 < 6 )
V_27 = F_3 ( V_2 , V_11 ) ;
else
V_27 = F_6 ( V_2 , V_11 - 6 ) ;
V_28 = 0x7f - ( V_27 & 0x7f ) ;
V_19 = ( V_28 != V_29 ) ;
if ( V_19 ) {
if ( V_12 < 6 )
F_1 ( V_2 , V_11 , ( 0x7f - V_29 ) |
( V_27 & 0x80 ) ) ;
else
F_5 ( V_2 , V_11 - 6 , ( 0x7f - V_29 ) |
( V_27 & 0x80 ) ) ;
}
}
return V_19 ;
}
static int F_14 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
unsigned char V_4 ;
int V_30 , V_12 ;
V_12 = F_9 ( V_8 , & V_10 -> V_12 ) ;
if ( V_12 == 0 ) {
for ( V_30 = 0 ; V_30 < 2 ; ++ V_30 ) {
V_4 = F_3 ( V_2 , V_31 + V_30 ) ;
V_10 -> V_16 . integer . V_16 [ V_30 ] = ~ V_4 >> 7 & 0x1 ;
}
} else {
for ( V_30 = 0 ; V_30 < 2 ; ++ V_30 ) {
V_4 = F_6 ( V_2 , V_31 + V_30 ) ;
V_10 -> V_16 . integer . V_16 [ V_30 ] = ~ V_4 >> 7 & 0x1 ;
}
}
return 0 ;
}
static int F_15 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
unsigned char V_17 , V_18 ;
int V_30 , V_3 , V_12 ;
int V_19 ;
V_12 = F_9 ( V_8 , & V_10 -> V_12 ) ;
if ( V_12 == 0 ) {
for ( V_30 = 0 ; V_30 < 2 ; ++ V_30 ) {
V_3 = V_31 + V_30 ;
V_18 = F_3 ( V_2 , V_3 ) ;
V_17 = ( ~ V_10 -> V_16 . integer . V_16 [ V_30 ] << 7 & 0x80 ) |
( V_18 & ~ 0x80 ) ;
V_19 = ( V_17 != V_18 ) ;
if ( V_19 )
F_1 ( V_2 , V_3 , V_17 ) ;
}
} else {
for ( V_30 = 0 ; V_30 < 2 ; ++ V_30 ) {
V_3 = V_31 + V_30 ;
V_18 = F_6 ( V_2 , V_3 ) ;
V_17 = ( ~ V_10 -> V_16 . integer . V_16 [ V_30 ] << 7 & 0x80 ) |
( V_18 & ~ 0x80 ) ;
V_19 = ( V_17 != V_18 ) ;
if ( V_19 )
F_5 ( V_2 , V_3 , V_17 ) ;
}
}
return V_19 ;
}
static int F_16 ( struct V_7 * V_8 ,
struct V_20 * V_21 )
{
V_21 -> type = V_22 ;
V_21 -> V_23 = 2 ;
V_21 -> V_16 . integer . V_24 = 0 ;
V_21 -> V_16 . integer . V_25 = 0x0f ;
return 0 ;
}
static int F_17 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
int V_30 , V_3 , V_12 ;
unsigned char V_26 ;
V_12 = F_9 ( V_8 , & V_10 -> V_12 ) ;
if ( V_12 == 0 ) {
for ( V_30 = 0 ; V_30 < 2 ; ++ V_30 ) {
V_3 = V_31 + V_30 ;
V_26 = F_3 ( V_2 , V_3 ) & 0x0f ;
V_10 -> V_16 . integer . V_16 [ V_30 ] = 0x0f - V_26 ;
}
} else {
for ( V_30 = 0 ; V_30 < 2 ; ++ V_30 ) {
V_3 = V_31 + V_30 ;
V_26 = F_6 ( V_2 , V_3 ) & 0x0f ;
V_10 -> V_16 . integer . V_16 [ V_30 ] = 0x0f - V_26 ;
}
}
return 0 ;
}
static int F_18 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
int V_30 , V_3 , V_12 ;
unsigned char V_28 , V_29 ;
int V_19 ;
V_12 = F_9 ( V_8 , & V_10 -> V_12 ) ;
if ( V_12 == 0 ) {
for ( V_30 = 0 ; V_30 < 2 ; ++ V_30 ) {
V_3 = V_31 + V_30 ;
V_29 = V_10 -> V_16 . integer . V_16 [ V_30 ] & 0x0f ;
V_28 = 0x0f - F_3 ( V_2 , V_3 ) ;
V_19 = ( ( V_28 & 0x0f ) != V_29 ) ;
if ( V_19 )
F_1 ( V_2 , V_3 , ( 0x0f - V_29 ) |
( V_28 & ~ 0x0f ) ) ;
}
} else {
for ( V_30 = 0 ; V_30 < 2 ; ++ V_30 ) {
V_3 = V_31 + V_30 ;
V_29 = V_10 -> V_16 . integer . V_16 [ V_30 ] & 0x0f ;
V_28 = 0x0f - F_6 ( V_2 , V_3 ) ;
V_19 = ( ( V_28 & 0x0f ) != V_29 ) ;
if ( V_19 )
F_5 ( V_2 , V_3 , ( 0x0f - V_29 ) |
( V_28 & ~ 0x0f ) ) ;
}
}
return V_19 ;
}
static int F_19 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
unsigned char V_4 ;
int V_12 ;
V_12 = F_9 ( V_8 , & V_10 -> V_12 ) ;
if ( V_12 == 0 )
V_4 = F_3 ( V_2 , V_32 ) ;
else
V_4 = F_6 ( V_2 , V_32 ) ;
V_10 -> V_16 . integer . V_16 [ 0 ] = ~ V_4 >> 7 & 0x1 ;
return 0 ;
}
static int F_20 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
unsigned char V_17 , V_18 ;
int V_19 , V_12 ;
V_12 = F_9 ( V_8 , & V_10 -> V_12 ) ;
if ( V_12 == 0 )
V_18 = F_3 ( V_2 , V_32 ) ;
else
V_18 = F_6 ( V_2 , V_32 ) ;
V_17 = ( ~ V_10 -> V_16 . integer . V_16 [ 0 ] << 7 & 0x80 ) | ( V_18 & ~ 0x80 ) ;
V_19 = ( V_17 != V_18 ) ;
if ( V_19 ) {
if ( V_12 == 0 )
F_1 ( V_2 , V_32 , V_17 ) ;
else
F_5 ( V_2 , V_32 , V_17 ) ;
}
return V_19 ;
}
static int T_1 F_21 ( struct V_1 * V_2 )
{
unsigned int V_30 ;
int V_33 ;
for ( V_30 = 0 ; V_30 < F_22 ( V_34 ) ; V_30 ++ ) {
V_33 = F_23 ( V_2 -> V_35 ,
F_24 ( & V_34 [ V_30 ] , V_2 ) ) ;
if ( V_33 < 0 )
return V_33 ;
}
return 0 ;
}
static int T_1 F_25 ( struct V_1 * V_2 )
{
static unsigned short V_36 [] = {
V_37 , 0 ,
( unsigned short ) - 1
} ;
unsigned short * V_38 ;
V_2 -> V_39 = 8 ;
V_2 -> V_40 = 4 ;
V_2 -> V_41 = 1 ;
V_38 = V_36 ;
for (; * V_38 != ( unsigned short ) - 1 ; V_38 += 2 ) {
F_1 ( V_2 , V_38 [ 0 ] , V_38 [ 1 ] ) ;
F_5 ( V_2 , V_38 [ 0 ] , V_38 [ 1 ] ) ;
}
return 0 ;
}

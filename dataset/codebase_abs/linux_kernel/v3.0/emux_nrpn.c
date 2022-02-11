static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
int type , int V_8 , int V_9 )
{
int V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ ) {
if ( V_2 [ V_10 ] . V_12 == type ) {
V_11 = V_2 [ V_10 ] . F_2 ( V_8 ) ;
F_3 ( V_5 , V_7 , V_2 [ V_10 ] . V_13 ,
V_11 , V_9 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_4 ( int V_8 )
{
return ( unsigned short ) F_5 ( V_8 ) ;
}
static int F_6 ( int V_8 )
{
return ( unsigned short ) F_7 ( V_8 ) ;
}
static int F_8 ( int V_8 )
{
return ( unsigned short ) F_9 ( V_8 ) ;
}
static int F_10 ( int V_8 )
{
return ( unsigned short ) F_11 ( V_8 ) ;
}
static int F_12 ( int V_8 )
{
return ( unsigned short ) ( V_8 & 0xff ) ;
}
static int F_13 ( int V_8 )
{
return ( unsigned short ) ( ( V_8 * 2 ) & 0xff ) ;
}
static int F_14 ( int V_8 )
{
return ( short ) ( V_8 * 4096 / 1200 ) ;
}
static int F_15 ( int V_8 )
{
return ( unsigned short ) ( ( V_8 / 8 ) & 0xff ) ;
}
static int F_16 ( int V_8 )
{
return ( V_8 - 64 ) * V_14 [ V_15 ] / 50 ;
}
static int F_17 ( int V_8 )
{
return ( V_8 - 64 ) * V_14 [ V_16 ] / 50 ;
}
static int F_18 ( int V_8 )
{
return - ( V_8 - 64 ) * V_14 [ V_17 ] / 50 ;
}
static int F_19 ( int V_8 )
{
return - ( V_8 - 64 ) * V_14 [ V_18 ] / 50 ;
}
static int F_20 ( int V_8 )
{
return - ( V_8 - 64 ) * V_14 [ V_18 ] / 50 ;
}
static int F_21 ( int V_8 )
{
return ( V_8 - 64 ) * V_14 [ V_19 ] / 50 ;
}
static int F_22 ( int V_8 )
{
return ( V_8 - 64 ) * V_14 [ V_20 ] / 50 ;
}
static int F_23 ( int V_8 )
{
return - ( V_8 - 64 ) * V_14 [ V_21 ] / 50 ;
}
void
F_24 ( void * V_22 , struct V_6 * V_7 ,
struct V_23 * V_24 )
{
struct V_4 * V_5 ;
V_5 = V_22 ;
if ( F_25 ( ! V_5 || ! V_7 ) )
return;
if ( V_7 -> V_12 [ V_25 ] == 127 &&
V_7 -> V_12 [ V_26 ] <= 26 ) {
int V_8 ;
V_8 = ( V_7 -> V_12 [ V_27 ] << 7 ) |
V_7 -> V_12 [ V_28 ] ;
V_8 -= 8192 ;
F_1
( V_29 , F_26 ( V_29 ) ,
V_5 , V_7 , V_7 -> V_12 [ V_26 ] ,
V_8 , V_30 ) ;
return;
}
if ( V_5 -> V_24 . V_31 == V_32 &&
V_7 -> V_12 [ V_25 ] == 1 ) {
int V_8 ;
V_8 = V_7 -> V_12 [ V_27 ] ;
F_1
( V_33 , F_26 ( V_33 ) ,
V_5 , V_7 , V_7 -> V_12 [ V_26 ] ,
V_8 , V_34 ) ;
return;
}
}
static int F_27 ( int V_8 )
{
return ( V_8 - 64 ) * V_35 [ V_15 ] / 64 ;
}
static int F_28 ( int V_8 )
{
return ( V_8 - 64 ) * V_35 [ V_16 ] / 64 ;
}
static int F_29 ( int V_8 )
{
return - ( V_8 - 64 ) * V_35 [ V_17 ] / 64 ;
}
static int F_30 ( int V_8 )
{
return - ( V_8 - 64 ) * V_35 [ V_18 ] / 64 ;
}
int
F_31 ( struct V_4 * V_5 , struct V_6 * V_7 ,
int V_36 )
{
return F_1 ( V_37 , F_26 ( V_37 ) ,
V_5 , V_7 , V_36 ,
V_7 -> V_12 [ V_36 ] ,
V_34 ) ;
}
void
F_32 ( void * V_22 , unsigned char * V_38 , int V_39 , int V_40 ,
struct V_23 * V_24 )
{
struct V_4 * V_5 ;
struct V_41 * V_42 ;
V_5 = V_22 ;
if ( F_25 ( ! V_5 || ! V_24 ) )
return;
V_42 = V_5 -> V_42 ;
switch ( V_40 ) {
case V_43 :
F_33 ( V_5 , V_44 ) ;
break;
default:
if ( V_42 -> V_45 . V_46 )
V_42 -> V_45 . V_46 ( V_42 , V_38 , V_39 , V_40 , V_24 ) ;
break;
}
}

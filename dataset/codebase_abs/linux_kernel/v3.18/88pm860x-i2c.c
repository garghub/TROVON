int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = ( V_2 == V_5 -> V_8 ) ? V_5 -> V_6
: V_5 -> V_9 ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_3 ( V_7 , V_3 , & V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
else
return ( int ) V_10 ;
}
int F_4 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = ( V_2 == V_5 -> V_8 ) ? V_5 -> V_6
: V_5 -> V_9 ;
int V_11 ;
V_11 = F_5 ( V_7 , V_3 , V_10 ) ;
return V_11 ;
}
int F_6 ( struct V_1 * V_2 , int V_3 ,
int V_12 , unsigned char * V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = ( V_2 == V_5 -> V_8 ) ? V_5 -> V_6
: V_5 -> V_9 ;
int V_11 ;
V_11 = F_7 ( V_7 , V_3 , V_13 , V_12 ) ;
return V_11 ;
}
int F_8 ( struct V_1 * V_2 , int V_3 ,
int V_12 , unsigned char * V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = ( V_2 == V_5 -> V_8 ) ? V_5 -> V_6
: V_5 -> V_9 ;
int V_11 ;
V_11 = F_9 ( V_7 , V_3 , V_13 , V_12 ) ;
return V_11 ;
}
int F_10 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_14 , unsigned char V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = ( V_2 == V_5 -> V_8 ) ? V_5 -> V_6
: V_5 -> V_9 ;
int V_11 ;
V_11 = F_11 ( V_7 , V_3 , V_14 , V_10 ) ;
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 , int V_3 ,
int V_15 , void * V_16 )
{
unsigned char V_17 [ V_18 + 3 ] ;
unsigned char V_19 [ V_18 + 2 ] ;
struct V_20 * V_21 = V_2 -> V_22 ;
struct V_23 V_24 [ 2 ] = {
{
. V_25 = V_2 -> V_25 ,
. V_26 = 0 ,
. V_27 = 1 ,
. V_13 = V_17
} ,
{ . V_25 = V_2 -> V_25 ,
. V_26 = V_28 ,
. V_27 = 0 ,
. V_13 = V_19
} ,
} ;
int V_29 = 1 , V_11 = 0 ;
if ( V_16 == NULL )
return - V_30 ;
V_17 [ 0 ] = ( unsigned char ) V_3 ;
V_24 [ 1 ] . V_27 = V_15 ;
if ( V_15 > 0 )
V_29 = 2 ;
V_11 = V_21 -> V_31 -> V_32 ( V_21 , V_24 , V_29 ) ;
memcpy ( V_16 , V_19 , V_15 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_3 ,
int V_15 , void * V_33 )
{
unsigned char V_13 [ 2 ] ;
struct V_20 * V_21 = V_2 -> V_22 ;
struct V_23 V_24 ;
int V_11 ;
V_13 [ 0 ] = ( unsigned char ) V_3 ;
memcpy ( & V_13 [ 1 ] , V_33 , V_15 ) ;
V_24 . V_25 = V_2 -> V_25 ;
V_24 . V_26 = 0 ;
V_24 . V_27 = V_15 + 1 ;
V_24 . V_13 = V_13 ;
V_11 = V_21 -> V_31 -> V_32 ( V_21 , & V_24 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_10 )
{
unsigned char V_34 ;
int V_11 ;
F_15 ( V_2 -> V_22 ) ;
F_12 ( V_2 , 0xFA , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFB , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFF , 0 , & V_34 ) ;
V_11 = F_13 ( V_2 , V_3 , 1 , & V_10 ) ;
F_12 ( V_2 , 0xFE , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFC , 0 , & V_34 ) ;
F_16 ( V_2 -> V_22 ) ;
return V_11 ;
}
int F_17 ( struct V_1 * V_2 , int V_3 ,
int V_12 , unsigned char * V_13 )
{
unsigned char V_34 = 0 ;
int V_11 ;
F_15 ( V_2 -> V_22 ) ;
F_12 ( V_2 , 0xfa , 0 , & V_34 ) ;
F_12 ( V_2 , 0xfb , 0 , & V_34 ) ;
F_12 ( V_2 , 0xff , 0 , & V_34 ) ;
V_11 = F_12 ( V_2 , V_3 , V_12 , V_13 ) ;
F_12 ( V_2 , 0xFE , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFC , 0 , & V_34 ) ;
F_16 ( V_2 -> V_22 ) ;
return V_11 ;
}

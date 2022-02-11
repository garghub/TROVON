static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_3 ;
int V_6 ;
T_1 V_7 [] = { 0x00 , 0x00 } ;
struct V_8 V_9 = { . V_10 = V_5 -> V_11 , . V_12 = 0 , . V_13 = V_7 , . V_14 = 2 } ;
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 1 ) ;
if ( ( V_6 = F_4 ( V_5 -> V_17 , & V_9 , 1 ) ) != 1 ) {
F_5 ( L_1 , V_18 ) ;
}
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 0 ) ;
return ( V_6 == 1 ) ? 0 : V_6 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_21 ;
struct V_4 * V_5 = V_2 -> V_3 ;
T_2 div ;
T_2 V_22 ;
T_1 V_7 [] = { 0x00 , 0x00 } ;
T_1 V_23 [] = { 0x01 , 0x00 , 0x00 , 0x00 } ;
T_1 V_24 [] = { 0x02 , 0x00 , 0x00 } ;
struct V_8 V_25 = { . V_10 = V_5 -> V_11 , . V_12 = 0 , . V_13 = V_7 , . V_14 = 2 } ;
struct V_8 V_26 = { . V_10 = V_5 -> V_11 , . V_12 = 0 , . V_13 = V_23 , . V_14 = 4 } ;
struct V_8 V_27 = { . V_10 = V_5 -> V_11 , . V_12 = 0 , . V_13 = V_24 , . V_14 = 3 } ;
#define F_7 4
#define F_8 32
#define F_9 4000000
if ( V_20 -> V_28 < 2000000 )
V_7 [ 1 ] = 0x03 ;
else
V_7 [ 1 ] = 0x07 ;
if ( V_20 -> V_28 < 1630000 )
V_23 [ 1 ] = 0x2c ;
else
V_23 [ 1 ] = 0x0c ;
if ( F_8 == 64 )
V_23 [ 1 ] |= 0x40 ;
if ( V_20 -> V_28 >= 1525000 )
V_23 [ 1 ] |= 0x80 ;
V_24 [ 1 ] = ( F_7 >> 8 ) & 0x03 ;
V_24 [ 2 ] = F_7 ;
if ( V_20 -> V_28 < 1455000 )
V_24 [ 1 ] |= 0x1c ;
else if ( V_20 -> V_28 < 1630000 )
V_24 [ 1 ] |= 0x0c ;
else
V_24 [ 1 ] |= 0x1c ;
V_22 = ( V_20 -> V_28 * F_7 ) / ( F_9 / 1000 ) ;
div = V_22 / F_8 ;
V_23 [ 1 ] |= ( div >> 9 ) & 0x03 ;
V_23 [ 2 ] = div >> 1 ;
V_23 [ 3 ] = ( div << 7 ) ;
V_5 -> V_28 = ( ( div * F_8 ) * ( F_9 / 1000 ) ) / F_7 ;
V_23 [ 3 ] |= ( V_22 - ( div * F_8 ) ) & 0x7f ;
#undef F_7
#undef F_8
#undef F_9
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 1 ) ;
if ( F_4 ( V_5 -> V_17 , & V_25 , 1 ) != 1 )
return - V_29 ;
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 1 ) ;
if ( F_4 ( V_5 -> V_17 , & V_27 , 1 ) != 1 )
return - V_29 ;
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 1 ) ;
if ( F_4 ( V_5 -> V_17 , & V_26 , 1 ) != 1 )
return - V_29 ;
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 0 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 * V_28 )
{
struct V_4 * V_5 = V_2 -> V_3 ;
* V_28 = V_5 -> V_28 ;
return 0 ;
}
struct V_1 * F_11 ( struct V_1 * V_2 , int V_10 , struct V_30 * V_17 )
{
struct V_4 * V_5 = NULL ;
T_1 V_31 [] = { 0x80 } ;
T_1 V_32 [] = { 0x00 } ;
struct V_8 V_9 [] = { { . V_10 = V_10 , . V_12 = 0 , . V_13 = V_31 , . V_14 = 1 } ,
{ . V_10 = V_10 , . V_12 = V_33 , . V_13 = V_32 , . V_14 = 1 } } ;
int V_6 ;
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 1 ) ;
V_6 = F_4 ( V_17 , V_9 , 2 ) ;
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 0 ) ;
if ( V_6 != 2 )
return NULL ;
V_5 = F_12 ( sizeof( struct V_4 ) , V_34 ) ;
if ( V_5 == NULL )
return NULL ;
V_5 -> V_11 = V_10 ;
V_5 -> V_17 = V_17 ;
memcpy ( & V_2 -> V_15 . V_35 , & V_36 , sizeof( struct V_37 ) ) ;
V_2 -> V_3 = V_5 ;
return V_2 ;
}

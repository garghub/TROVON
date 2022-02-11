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
T_1 V_7 [] = { 0x00 , 0x8d } ;
struct V_8 V_9 = { . V_10 = V_5 -> V_11 , . V_12 = 0 , . V_7 = V_7 , . V_13 = 2 } ;
F_4 ( L_1 , V_14 ) ;
if ( ! V_5 -> V_15 )
V_7 [ 1 ] = 0xad ;
if ( V_2 -> V_16 . V_17 )
V_2 -> V_16 . V_17 ( V_2 , 1 ) ;
if ( ( V_6 = F_5 ( V_5 -> V_18 , & V_9 , 1 ) ) != 1 ) {
F_4 ( L_2 , V_14 ) ;
}
if ( V_2 -> V_16 . V_17 )
V_2 -> V_16 . V_17 ( V_2 , 0 ) ;
return ( V_6 == 1 ) ? 0 : V_6 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_4 * V_5 = V_2 -> V_3 ;
int V_6 ;
T_2 div ;
T_2 V_21 ;
T_2 V_22 ;
T_1 V_7 [ 11 ] ;
struct V_8 V_9 = { . V_10 = V_5 -> V_11 , . V_12 = 0 , . V_7 = V_7 , . V_13 = 11 } ;
F_4 ( L_1 , V_14 ) ;
div = ( V_20 -> V_23 + ( 1000 - 1 ) ) / 1000 ;
V_21 = V_20 -> V_24 . V_25 . V_26 / 1000 ;
V_22 = ( 878 * V_21 + 6500000 ) / 1000000 + 1 ;
if ( V_22 < 5 )
V_22 = 5 ;
else if ( V_22 > 36 )
V_22 = 36 ;
V_7 [ 0 ] = 0x00 ;
V_7 [ 1 ] = 0x09 ;
if ( ! V_5 -> V_15 )
V_7 [ 1 ] |= 0x20 ;
V_7 [ 2 ] = ( 1 << 5 ) | 0x0b ;
V_7 [ 3 ] = div >> 7 ;
V_7 [ 4 ] = div << 1 ;
V_7 [ 5 ] = ( ( V_22 - 5 ) << 3 ) | 7 ;
V_7 [ 6 ] = 0xfe ;
V_7 [ 7 ] = 0x83 ;
V_7 [ 8 ] = 0x80 ;
V_7 [ 9 ] = 0x1a ;
V_7 [ 10 ] = 0xd4 ;
if ( V_2 -> V_16 . V_17 )
V_2 -> V_16 . V_17 ( V_2 , 1 ) ;
if ( ( V_6 = F_5 ( V_5 -> V_18 , & V_9 , 1 ) ) != 1 ) {
F_4 ( L_2 , V_14 ) ;
}
if ( V_2 -> V_16 . V_17 )
V_2 -> V_16 . V_17 ( V_2 , 0 ) ;
V_5 -> V_23 = div * 1000 ;
return ( V_6 == 1 ) ? 0 : V_6 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 * V_23 )
{
struct V_4 * V_5 = V_2 -> V_3 ;
* V_23 = V_5 -> V_23 ;
return 0 ;
}
struct V_1 * F_8 ( struct V_1 * V_2 , int V_10 , struct V_27 * V_18 , int V_15 )
{
struct V_4 * V_5 = NULL ;
T_1 V_28 [] = { 0 , 0 } ;
struct V_8 V_9 [ 2 ] = {
{ . V_10 = V_10 , . V_12 = 0 , . V_7 = NULL , . V_13 = 0 } ,
{ . V_10 = V_10 , . V_12 = V_29 , . V_7 = V_28 , . V_13 = 2 }
} ;
int V_6 ;
F_4 ( L_1 , V_14 ) ;
if ( V_2 -> V_16 . V_17 )
V_2 -> V_16 . V_17 ( V_2 , 1 ) ;
V_6 = F_5 ( V_18 , V_9 , 2 ) ;
if ( V_2 -> V_16 . V_17 )
V_2 -> V_16 . V_17 ( V_2 , 0 ) ;
if ( V_6 != 2 )
return NULL ;
if ( ! ( V_28 [ 1 ] & 0x80 ) )
return NULL ;
V_5 = F_9 ( sizeof( struct V_4 ) , V_30 ) ;
if ( V_5 == NULL )
return NULL ;
V_5 -> V_11 = V_10 ;
V_5 -> V_18 = V_18 ;
V_5 -> V_15 = V_15 ;
memcpy ( & V_2 -> V_16 . V_31 , & V_32 , sizeof( struct V_33 ) ) ;
V_2 -> V_3 = V_5 ;
return V_2 ;
}

static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_5 = (struct V_5 * ) V_2 -> V_6 ;
struct V_7 V_8 = {
. V_9 = 0x08 ,
. V_10 = 0 ,
. V_11 = ( char * ) & V_5 -> V_12 ,
. V_13 = sizeof( V_5 -> V_12 ) ,
} ;
F_2 ( 1 , L_1 , V_14 , V_4 ,
V_15 , V_16 ) ;
V_5 -> V_12 [ 3 ] = 0x60 ;
switch ( V_4 ) {
case V_17 :
break;
case V_16 :
V_5 -> V_12 [ 3 ] |= V_18 ;
break;
case V_15 :
V_5 -> V_12 [ 3 ] |= ( V_18 | V_19 ) ;
break;
default:
return - V_20 ;
}
F_2 ( 1 , L_2 , V_14 , V_5 -> V_12 [ 3 ] ) ;
return ( F_3 ( V_5 -> V_21 , & V_8 , 1 ) == 1 ) ? 0 : - V_22 ;
}
static int F_4 ( struct V_1 * V_2 , long V_23 )
{
struct V_5 * V_5 = (struct V_5 * ) V_2 -> V_6 ;
struct V_7 V_8 = {
. V_9 = 0x08 ,
. V_10 = 0 ,
. V_11 = ( char * ) & V_5 -> V_12 ,
. V_13 = sizeof( V_5 -> V_12 ) ,
} ;
F_2 ( 1 , L_3 , V_14 , ( int ) V_23 ) ;
if ( V_23 )
V_5 -> V_12 [ 3 ] |= V_24 ;
else
V_5 -> V_12 [ 3 ] &= ~ V_24 ;
return ( F_3 ( V_5 -> V_21 , & V_8 , 1 ) == 1 ) ? 0 : - V_22 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( 1 , L_4 , V_14 ) ;
F_1 ( V_2 , V_17 ) ;
F_6 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
struct V_1 * F_7 ( struct V_1 * V_2 ,
struct V_25 * V_21 )
{
struct V_5 * V_5 = F_8 ( sizeof( struct V_5 ) , V_26 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_12 [ 0 ] = 0x00 ;
V_5 -> V_12 [ 1 ] = 0x28 ;
V_5 -> V_12 [ 2 ] = 0x48 ;
V_5 -> V_12 [ 3 ] = 0x60 ;
V_5 -> V_21 = V_21 ;
V_2 -> V_6 = V_5 ;
if ( F_1 ( V_2 , V_17 ) ) {
F_2 ( 0 , L_5 , V_14 ) ;
F_6 ( V_5 ) ;
V_2 -> V_6 = NULL ;
return NULL ;
}
V_2 -> V_27 . V_28 = F_5 ;
V_2 -> V_27 . V_29 = F_1 ;
V_2 -> V_27 . V_30 = F_4 ;
return V_2 ;
}

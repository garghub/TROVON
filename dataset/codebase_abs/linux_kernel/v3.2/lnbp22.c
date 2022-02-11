static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = (struct V_4 * ) V_2 -> V_5 ;
struct V_6 V_7 = {
. V_8 = 0x08 ,
. V_9 = 0 ,
. V_10 = ( char * ) & V_4 -> V_11 ,
. V_12 = sizeof( V_4 -> V_11 ) ,
} ;
F_2 ( 1 , L_1 , V_13 , V_3 ,
V_14 , V_15 ) ;
V_4 -> V_11 [ 3 ] = 0x60 ;
switch ( V_3 ) {
case V_16 :
break;
case V_15 :
V_4 -> V_11 [ 3 ] |= V_17 ;
break;
case V_14 :
V_4 -> V_11 [ 3 ] |= ( V_17 | V_18 ) ;
break;
default:
return - V_19 ;
} ;
F_2 ( 1 , L_2 , V_13 , V_4 -> V_11 [ 3 ] ) ;
return ( F_3 ( V_4 -> V_20 , & V_7 , 1 ) == 1 ) ? 0 : - V_21 ;
}
static int F_4 ( struct V_1 * V_2 , long V_22 )
{
struct V_4 * V_4 = (struct V_4 * ) V_2 -> V_5 ;
struct V_6 V_7 = {
. V_8 = 0x08 ,
. V_9 = 0 ,
. V_10 = ( char * ) & V_4 -> V_11 ,
. V_12 = sizeof( V_4 -> V_11 ) ,
} ;
F_2 ( 1 , L_3 , V_13 , ( int ) V_22 ) ;
if ( V_22 )
V_4 -> V_11 [ 3 ] |= V_23 ;
else
V_4 -> V_11 [ 3 ] &= ~ V_23 ;
return ( F_3 ( V_4 -> V_20 , & V_7 , 1 ) == 1 ) ? 0 : - V_21 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( 1 , L_4 , V_13 ) ;
F_1 ( V_2 , V_16 ) ;
F_6 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
struct V_1 * F_7 ( struct V_1 * V_2 ,
struct V_24 * V_20 )
{
struct V_4 * V_4 = F_8 ( sizeof( struct V_4 ) , V_25 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_11 [ 0 ] = 0x00 ;
V_4 -> V_11 [ 1 ] = 0x28 ;
V_4 -> V_11 [ 2 ] = 0x48 ;
V_4 -> V_11 [ 3 ] = 0x60 ;
V_4 -> V_20 = V_20 ;
V_2 -> V_5 = V_4 ;
if ( F_1 ( V_2 , V_16 ) ) {
F_2 ( 0 , L_5 , V_13 ) ;
F_6 ( V_4 ) ;
V_2 -> V_5 = NULL ;
return NULL ;
}
V_2 -> V_26 . V_27 = F_5 ;
V_2 -> V_26 . V_28 = F_1 ;
V_2 -> V_26 . V_29 = F_4 ;
return V_2 ;
}

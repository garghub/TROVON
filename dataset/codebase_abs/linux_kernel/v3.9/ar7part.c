static int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
struct V_5 * V_6 )
{
struct V_7 V_8 ;
unsigned int V_9 ;
T_1 V_10 ;
unsigned int V_11 = V_2 -> V_12 , V_13 = 0 ;
unsigned int V_14 = V_15 ;
int V_16 = 10 ;
struct V_3 * V_17 ;
V_17 = F_2 ( sizeof( * V_17 ) * V_18 , V_19 ) ;
if ( ! V_17 )
return - V_20 ;
V_17 [ 0 ] . V_21 = L_1 ;
V_17 [ 0 ] . V_9 = 0 ;
V_17 [ 0 ] . V_22 = V_2 -> V_12 ;
V_17 [ 0 ] . V_23 = V_24 ;
V_17 [ 1 ] . V_21 = L_2 ;
V_17 [ 1 ] . V_9 = 0 ;
V_17 [ 1 ] . V_22 = V_2 -> V_12 ;
V_17 [ 1 ] . V_23 = 0 ;
do {
V_9 = V_11 ;
F_3 ( V_2 , V_9 , sizeof( V_8 ) , & V_10 ,
( V_25 * ) & V_8 ) ;
if ( ! strncmp ( ( char * ) & V_8 , L_3 , 8 ) )
V_17 [ 1 ] . V_9 = V_11 ;
if ( V_8 . V_26 == V_27 )
break;
if ( V_8 . V_26 == V_28 )
break;
V_11 += V_2 -> V_12 ;
} while ( V_16 -- );
V_11 = V_9 ;
if ( ! V_17 [ 1 ] . V_9 ) {
V_17 [ 1 ] . V_9 = V_2 -> V_22 - V_2 -> V_12 ;
V_13 = V_2 -> V_12 ;
}
switch ( V_8 . V_26 ) {
case V_27 :
while ( V_8 . V_29 ) {
V_9 += sizeof( V_8 ) + V_8 . V_29 ;
F_3 ( V_2 , V_9 , sizeof( V_8 ) , & V_10 ,
( V_25 * ) & V_8 ) ;
}
V_14 = V_9 + sizeof( V_8 ) + 4 ;
break;
case V_28 :
while ( V_8 . V_29 ) {
V_9 += sizeof( V_8 ) + V_8 . V_29 ;
F_3 ( V_2 , V_9 , sizeof( V_8 ) , & V_10 ,
( V_25 * ) & V_8 ) ;
}
V_14 = V_9 + sizeof( V_8 ) + 4 + 0xff ;
V_14 &= ~ ( V_30 ) 0xff ;
break;
default:
F_4 ( V_31 L_4 , V_8 . V_26 ) ;
break;
}
F_3 ( V_2 , V_14 , sizeof( V_8 ) , & V_10 , ( V_32 * ) & V_8 ) ;
if ( V_8 . V_26 != V_33 ) {
V_14 += V_2 -> V_12 - 1 ;
V_14 &= ~ ( V_2 -> V_12 - 1 ) ;
}
V_17 [ 2 ] . V_21 = L_5 ;
V_17 [ 2 ] . V_9 = V_11 ;
V_17 [ 2 ] . V_22 = V_2 -> V_22 - V_11 - V_13 ;
V_17 [ 2 ] . V_23 = 0 ;
V_17 [ 3 ] . V_21 = L_6 ;
V_17 [ 3 ] . V_9 = V_14 ;
V_17 [ 3 ] . V_22 = V_2 -> V_22 - V_14 - V_13 ;
V_17 [ 3 ] . V_23 = 0 ;
* V_4 = V_17 ;
return V_18 ;
}
static int T_2 F_5 ( void )
{
return F_6 ( & V_34 ) ;
}
static void T_3 F_7 ( void )
{
F_8 ( & V_34 ) ;
}

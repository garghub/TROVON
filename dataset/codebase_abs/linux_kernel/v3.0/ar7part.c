static int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
unsigned long V_5 )
{
struct V_6 V_7 ;
unsigned int V_8 ;
T_1 V_9 ;
unsigned int V_10 = V_2 -> V_11 , V_12 = 0 ;
unsigned int V_13 = V_14 ;
int V_15 = 10 ;
struct V_3 * V_16 ;
V_16 = F_2 ( sizeof( * V_16 ) * V_17 , V_18 ) ;
if ( ! V_16 )
return - V_19 ;
V_16 [ 0 ] . V_20 = L_1 ;
V_16 [ 0 ] . V_8 = 0 ;
V_16 [ 0 ] . V_21 = V_2 -> V_11 ;
V_16 [ 0 ] . V_22 = V_23 ;
V_16 [ 1 ] . V_20 = L_2 ;
V_16 [ 1 ] . V_8 = 0 ;
V_16 [ 1 ] . V_21 = V_2 -> V_11 ;
V_16 [ 1 ] . V_22 = 0 ;
do {
V_8 = V_10 ;
V_2 -> V_24 ( V_2 , V_8 ,
sizeof( V_7 ) , & V_9 , ( V_25 * ) & V_7 ) ;
if ( ! strncmp ( ( char * ) & V_7 , L_3 , 8 ) )
V_16 [ 1 ] . V_8 = V_10 ;
if ( V_7 . V_26 == V_27 )
break;
if ( V_7 . V_26 == V_28 )
break;
V_10 += V_2 -> V_11 ;
} while ( V_15 -- );
V_10 = V_8 ;
if ( ! V_16 [ 1 ] . V_8 ) {
V_16 [ 1 ] . V_8 = V_2 -> V_21 - V_2 -> V_11 ;
V_12 = V_2 -> V_11 ;
}
switch ( V_7 . V_26 ) {
case V_27 :
while ( V_7 . V_29 ) {
V_8 += sizeof( V_7 ) + V_7 . V_29 ;
V_2 -> V_24 ( V_2 , V_8 , sizeof( V_7 ) ,
& V_9 , ( V_25 * ) & V_7 ) ;
}
V_13 = V_8 + sizeof( V_7 ) + 4 ;
break;
case V_28 :
while ( V_7 . V_29 ) {
V_8 += sizeof( V_7 ) + V_7 . V_29 ;
V_2 -> V_24 ( V_2 , V_8 , sizeof( V_7 ) ,
& V_9 , ( V_25 * ) & V_7 ) ;
}
V_13 = V_8 + sizeof( V_7 ) + 4 + 0xff ;
V_13 &= ~ ( V_30 ) 0xff ;
break;
default:
F_3 ( V_31 L_4 , V_7 . V_26 ) ;
break;
}
V_2 -> V_24 ( V_2 , V_13 ,
sizeof( V_7 ) , & V_9 , ( V_32 * ) & V_7 ) ;
if ( V_7 . V_26 != V_33 ) {
V_13 += V_2 -> V_11 - 1 ;
V_13 &= ~ ( V_2 -> V_11 - 1 ) ;
}
V_16 [ 2 ] . V_20 = L_5 ;
V_16 [ 2 ] . V_8 = V_10 ;
V_16 [ 2 ] . V_21 = V_2 -> V_21 - V_10 - V_12 ;
V_16 [ 2 ] . V_22 = 0 ;
V_16 [ 3 ] . V_20 = L_6 ;
V_16 [ 3 ] . V_8 = V_13 ;
V_16 [ 3 ] . V_21 = V_2 -> V_21 - V_13 - V_12 ;
V_16 [ 3 ] . V_22 = 0 ;
* V_4 = V_16 ;
return V_17 ;
}
static int T_2 F_4 ( void )
{
return F_5 ( & V_34 ) ;
}

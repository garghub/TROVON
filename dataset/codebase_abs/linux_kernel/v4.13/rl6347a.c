int F_1 ( void * V_1 , unsigned int V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
T_1 V_8 [ 4 ] ;
int V_9 , V_10 ;
if ( V_2 <= 0xff ) {
F_1 ( V_5 , V_11 , V_2 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 ; V_10 ++ ) {
if ( V_2 == V_7 -> V_13 [ V_10 ] . V_2 ) {
V_7 -> V_13 [ V_10 ] . V_14 = V_3 ;
break;
}
}
V_2 = V_15 ;
}
V_8 [ 0 ] = ( V_2 >> 24 ) & 0xff ;
V_8 [ 1 ] = ( V_2 >> 16 ) & 0xff ;
V_8 [ 2 ] = ( ( V_2 >> 8 ) & 0xff ) | ( ( V_3 >> 8 ) & 0xff ) ;
V_8 [ 3 ] = V_3 & 0xff ;
V_9 = F_3 ( V_5 , V_8 , 4 ) ;
if ( V_9 == 4 )
return 0 ;
else
F_4 ( & V_5 -> V_16 , L_1 , V_9 ) ;
if ( V_9 < 0 )
return V_9 ;
else
return - V_17 ;
}
int F_5 ( void * V_1 , unsigned int V_2 , unsigned int * V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_18 V_19 [ 2 ] ;
int V_9 ;
T_2 V_20 ;
unsigned int V_21 , V_22 , V_23 = 0x0 ;
if ( V_2 <= 0xff ) {
F_1 ( V_5 , V_11 , V_2 ) ;
V_2 = V_15 ;
}
V_2 = V_2 | 0x80000 ;
V_22 = ( V_2 >> 8 ) & 0xfff ;
if ( V_24 == ( V_22 & 0xf00 ) ) {
V_21 = ( V_2 >> 8 ) & 0xf ;
V_2 = ( V_2 & ~ 0xf0f ) | V_21 ;
}
V_20 = F_6 ( V_2 ) ;
V_19 [ 0 ] . V_25 = V_5 -> V_25 ;
V_19 [ 0 ] . V_26 = 0 ;
V_19 [ 0 ] . V_27 = 4 ;
V_19 [ 0 ] . V_23 = ( T_1 * ) & V_20 ;
V_19 [ 1 ] . V_25 = V_5 -> V_25 ;
V_19 [ 1 ] . V_26 = V_28 ;
V_19 [ 1 ] . V_27 = 4 ;
V_19 [ 1 ] . V_23 = ( T_1 * ) & V_23 ;
V_9 = F_7 ( V_5 -> V_29 , V_19 , 2 ) ;
if ( V_9 < 0 )
return V_9 ;
else if ( V_9 != 2 )
return - V_17 ;
* V_3 = F_8 ( V_23 ) ;
return 0 ;
}

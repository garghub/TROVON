static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , int * V_4 )
{
T_2 * V_5 , V_6 , V_7 , V_8 ;
T_3 V_9 ;
int V_10 , V_11 ;
struct V_12 * V_13 = V_2 -> V_14 ;
V_5 = F_2 ( 5 , V_15 ) ;
if ( ! V_5 )
return - V_16 ;
V_5 [ 0 ] = V_17 ;
V_5 [ 1 ] = 0x35 ;
V_11 = F_3 ( V_2 , V_5 , 2 , V_5 , 5 , 0 ) ;
if ( V_11 < 0 )
goto V_11;
* V_4 = V_18 ;
switch ( V_5 [ 0 ] ) {
case V_19 :
V_9 = ( ( V_5 [ 1 ] << 8 ) | V_5 [ 2 ] ) >> 3 ;
V_7 = ! ! ( V_9 & 0x800 ) ;
V_6 = V_9 & 0x3f ;
V_8 = ( V_9 >> 6 ) & 0x1f ;
F_4 ( L_1 ,
V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] , V_8 , V_6 , V_7 ) ;
for ( V_10 = 0 ; V_10 < F_5 ( V_20 ) ; V_10 ++ ) {
if ( F_6 ( & V_20 [ V_10 ] ) == V_6 &&
F_7 ( & V_20 [ V_10 ] ) == V_8 ) {
F_4 ( L_2 , F_6 ( & V_20 [ V_10 ] ) ,
F_7 ( & V_20 [ V_10 ] ) ) ;
* V_3 = V_20 [ V_10 ] . V_21 ;
* V_4 = V_22 ;
if ( V_13 -> V_23 == V_7 ) {
if ( V_13 -> V_24 ++ < 2 )
* V_4 = V_18 ;
} else {
V_13 -> V_24 = 0 ;
V_13 -> V_23 = V_7 ;
}
break;
}
}
break;
case V_25 :
default:
break;
}
V_11:
F_8 ( V_5 ) ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_26 [ 6 ] )
{
int V_10 ;
T_2 V_27 ;
V_26 [ 0 ] = 0x00 ;
V_26 [ 1 ] = 0x0d ;
V_26 [ 2 ] = 0xfe ;
for ( V_10 = 136 ; V_10 < 139 ; V_10 ++ ) {
F_10 ( V_2 , V_10 , & V_27 ) ;
V_26 [ 5 - ( V_10 - 136 ) ] = V_27 ;
}
return 0 ;
}
static int F_11 ( struct V_28 * V_29 ,
const struct V_30 * V_31 )
{
return F_12 ( V_29 , & V_32 ,
V_33 , NULL , V_34 ) ;
}

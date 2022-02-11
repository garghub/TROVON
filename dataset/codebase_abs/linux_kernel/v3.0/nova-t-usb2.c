static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , int * V_4 )
{
T_2 V_5 [ 5 ] , V_6 [ 2 ] = { V_7 , 0x35 } , V_8 , V_9 , V_10 ;
T_3 V_11 ;
int V_12 ;
struct V_13 * V_14 = V_2 -> V_15 ;
F_2 ( V_2 , V_6 , 2 , V_5 , 5 , 0 ) ;
* V_4 = V_16 ;
switch ( V_5 [ 0 ] ) {
case V_17 :
V_11 = ( ( V_5 [ 1 ] << 8 ) | V_5 [ 2 ] ) >> 3 ;
V_9 = ! ! ( V_11 & 0x800 ) ;
V_8 = V_11 & 0x3f ;
V_10 = ( V_11 >> 6 ) & 0x1f ;
F_3 ( L_1 , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] , V_10 , V_8 , V_9 ) ;
for ( V_12 = 0 ; V_12 < F_4 ( V_18 ) ; V_12 ++ ) {
if ( F_5 ( & V_18 [ V_12 ] ) == V_8 &&
F_6 ( & V_18 [ V_12 ] ) == V_10 ) {
F_3 ( L_2 , F_5 ( & V_18 [ V_12 ] ) ,
F_6 ( & V_18 [ V_12 ] ) ) ;
* V_3 = V_18 [ V_12 ] . V_19 ;
* V_4 = V_20 ;
if ( V_14 -> V_21 == V_9 ) {
if ( V_14 -> V_22 ++ < 2 )
* V_4 = V_16 ;
} else {
V_14 -> V_22 = 0 ;
V_14 -> V_21 = V_9 ;
}
break;
}
}
break;
case V_23 :
default:
break;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_24 [ 6 ] )
{
int V_12 ;
T_2 V_25 ;
V_24 [ 0 ] = 0x00 ;
V_24 [ 1 ] = 0x0d ;
V_24 [ 2 ] = 0xfe ;
for ( V_12 = 136 ; V_12 < 139 ; V_12 ++ ) {
F_8 ( V_2 , V_12 , & V_25 ) ;
V_24 [ 5 - ( V_12 - 136 ) ] = V_25 ;
}
return 0 ;
}
static int F_9 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
return F_10 ( V_27 , & V_30 ,
V_31 , NULL , V_32 ) ;
}
static int T_4 F_11 ( void )
{
int V_33 ;
if ( ( V_33 = F_12 ( & V_34 ) ) ) {
F_13 ( L_3 , V_33 ) ;
return V_33 ;
}
return 0 ;
}
static void T_5 F_14 ( void )
{
F_15 ( & V_34 ) ;
}

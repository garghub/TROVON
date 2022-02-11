static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
T_1 V_5 = 0x00 ;
T_1 V_6 [ 6 ] ;
struct V_7 V_8 [ 2 ] = {
{
. V_5 = V_2 -> V_9 ,
. V_10 = 0 ,
. V_11 = 1 ,
. V_12 = & V_5
} , {
. V_5 = V_2 -> V_9 ,
. V_10 = V_13 ,
. V_11 = sizeof( V_6 ) ,
. V_12 = V_6
}
} ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_4 = F_2 ( V_2 -> V_14 , & V_8 [ V_3 ] , 1 ) ;
if ( V_4 >= 0 && V_4 != 1 )
V_4 = - V_15 ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_14 -> V_16 ,
L_1 ,
V_17 , V_3 , V_4 ) ;
return V_4 ;
}
}
F_3 ( & V_2 -> V_14 -> V_16 , L_2 ,
V_17 , ( int ) sizeof( V_6 ) , V_6 ) ;
if ( ( V_6 [ 0 ] & ( V_18 | V_19 ) ) != 0 ) {
F_4 ( & V_2 -> V_14 -> V_16 ,
L_3 ,
V_17 , V_6 [ 0 ] ) ;
return - V_15 ;
}
return 0 ;
}
static int F_5 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
int V_4 ;
T_1 V_24 ;
const char * V_25 ;
struct V_1 * V_2 = V_21 -> V_26 ;
struct V_7 V_8 = {
. V_5 = V_2 -> V_9 ,
. V_10 = 0 ,
. V_11 = sizeof( V_2 -> V_27 ) ,
. V_12 = V_2 -> V_27
} ;
switch ( V_23 ) {
case V_28 :
V_24 = 0x00 ;
V_25 = L_4 ;
break;
case V_29 :
V_24 = V_30 ;
V_25 = L_5 ;
break;
case V_31 :
V_24 = V_32 ;
V_25 = L_6 ;
break;
default:
return - V_33 ;
}
V_2 -> V_27 [ 1 ] = V_24 ;
F_3 ( & V_2 -> V_14 -> V_16 ,
L_7 ,
V_17 , V_25 , V_2 -> V_9 ,
V_2 -> V_27 [ 0 ] , V_2 -> V_27 [ 1 ] , V_2 -> V_27 [ 2 ] ) ;
V_4 = F_2 ( V_2 -> V_14 , & V_8 , 1 ) ;
if ( V_4 >= 0 && V_4 != 1 )
V_4 = - V_15 ;
if ( V_4 < 0 ) {
F_4 ( & V_2 -> V_14 -> V_16 , L_8 ,
V_17 , V_4 ) ;
return V_4 ;
}
if ( V_23 != V_28 ) {
F_6 ( 120 ) ;
V_4 = F_1 ( V_2 ) ;
} else {
F_6 ( 20 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static void F_7 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_26 ;
F_3 ( & V_2 -> V_14 -> V_16 , L_9 , V_17 ) ;
F_5 ( V_21 , V_28 ) ;
F_8 ( V_21 -> V_26 ) ;
V_21 -> V_26 = NULL ;
}
struct V_20 * F_9 ( struct V_20 * V_21 ,
struct V_34 * V_35 ,
struct V_36 * V_14 )
{
struct V_1 * V_2 ;
F_3 ( & V_14 -> V_16 , L_9 , V_17 ) ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_9 = ( V_35 -> V_9 >> 1 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_27 [ 0 ] = 0x02 ;
V_2 -> V_27 [ 1 ] = 0x00 ;
V_2 -> V_27 [ 2 ] = V_35 -> V_38 ;
V_21 -> V_26 = V_2 ;
if ( F_5 ( V_21 , V_28 ) ) {
F_4 ( & V_14 -> V_16 ,
L_10 ,
V_17 , V_2 -> V_9 ) ;
F_8 ( V_2 ) ;
V_21 -> V_26 = NULL ;
return NULL ;
}
V_21 -> V_39 . V_40 = F_7 ;
V_21 -> V_39 . V_41 = F_5 ;
F_11 ( & V_14 -> V_16 , L_11 ,
V_17 , V_2 -> V_9 ) ;
return V_21 ;
}

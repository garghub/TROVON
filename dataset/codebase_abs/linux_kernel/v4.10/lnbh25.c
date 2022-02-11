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
F_4 ( L_2 ,
V_18 , V_6 , sizeof( V_6 ) ) ;
if ( ( V_6 [ 0 ] & ( V_19 | V_20 ) ) != 0 ) {
F_5 ( & V_2 -> V_14 -> V_16 ,
L_3 ,
V_17 , V_6 [ 0 ] ) ;
return - V_15 ;
}
return 0 ;
}
static int F_6 ( struct V_21 * V_22 ,
enum V_23 V_24 )
{
int V_4 ;
T_1 V_25 ;
const char * V_26 ;
struct V_1 * V_2 = V_22 -> V_27 ;
struct V_7 V_8 = {
. V_5 = V_2 -> V_9 ,
. V_10 = 0 ,
. V_11 = sizeof( V_2 -> V_28 ) ,
. V_12 = V_2 -> V_28
} ;
switch ( V_24 ) {
case V_29 :
V_25 = 0x00 ;
V_26 = L_4 ;
break;
case V_30 :
V_25 = V_31 ;
V_26 = L_5 ;
break;
case V_32 :
V_25 = V_33 ;
V_26 = L_6 ;
break;
default:
return - V_34 ;
}
V_2 -> V_28 [ 1 ] = V_25 ;
F_3 ( & V_2 -> V_14 -> V_16 ,
L_7 ,
V_17 , V_26 , V_2 -> V_9 ,
V_2 -> V_28 [ 0 ] , V_2 -> V_28 [ 1 ] , V_2 -> V_28 [ 2 ] ) ;
V_4 = F_2 ( V_2 -> V_14 , & V_8 , 1 ) ;
if ( V_4 >= 0 && V_4 != 1 )
V_4 = - V_15 ;
if ( V_4 < 0 ) {
F_5 ( & V_2 -> V_14 -> V_16 , L_8 ,
V_17 , V_4 ) ;
return V_4 ;
}
if ( V_24 != V_29 ) {
F_7 ( 120 ) ;
V_4 = F_1 ( V_2 ) ;
} else {
F_7 ( 20 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static void F_8 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_27 ;
F_3 ( & V_2 -> V_14 -> V_16 , L_9 , V_17 ) ;
F_6 ( V_22 , V_29 ) ;
F_9 ( V_22 -> V_27 ) ;
V_22 -> V_27 = NULL ;
}
struct V_21 * F_10 ( struct V_21 * V_22 ,
struct V_35 * V_36 ,
struct V_37 * V_14 )
{
struct V_1 * V_2 ;
F_3 ( & V_14 -> V_16 , L_9 , V_17 ) ;
V_2 = F_11 ( sizeof( struct V_1 ) , V_38 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_9 = ( V_36 -> V_9 >> 1 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_28 [ 0 ] = 0x02 ;
V_2 -> V_28 [ 1 ] = 0x00 ;
V_2 -> V_28 [ 2 ] = V_36 -> V_39 ;
V_22 -> V_27 = V_2 ;
if ( F_6 ( V_22 , V_29 ) ) {
F_5 ( & V_14 -> V_16 ,
L_10 ,
V_17 , V_2 -> V_9 ) ;
F_9 ( V_2 ) ;
V_22 -> V_27 = NULL ;
return NULL ;
}
V_22 -> V_40 . V_41 = F_8 ;
V_22 -> V_40 . V_42 = F_6 ;
F_5 ( & V_14 -> V_16 , L_11 ,
V_17 , V_2 -> V_9 ) ;
return V_22 ;
}

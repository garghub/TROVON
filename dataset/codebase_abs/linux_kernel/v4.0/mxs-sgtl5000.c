static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_11 = F_2 ( V_4 ) ;
T_1 V_12 ;
int V_13 ;
switch ( V_11 ) {
case 96000 :
V_12 = 256 * V_11 ;
break;
default:
V_12 = 512 * V_11 ;
break;
}
V_13 = F_3 ( V_9 , V_14 , V_12 , 0 ) ;
if ( V_13 ) {
F_4 ( V_9 -> V_15 , L_1 ,
V_12 / 1000000 , V_12 / 1000 % 1000 ) ;
return V_13 ;
}
V_13 = F_3 ( V_10 , V_16 , V_12 , 0 ) ;
if ( V_13 ) {
F_4 ( V_10 -> V_15 , L_1 ,
V_12 / 1000000 , V_12 / 1000 % 1000 ) ;
return V_13 ;
}
return 0 ;
}
static int F_5 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_21 ;
int V_13 , V_22 ;
struct V_23 * V_24 = V_18 -> V_15 . V_25 ;
struct V_23 * V_26 [ 2 ] , * V_27 ;
V_26 [ 0 ] = F_6 ( V_24 , L_2 , 0 ) ;
V_26 [ 1 ] = F_6 ( V_24 , L_2 , 1 ) ;
V_27 = F_6 ( V_24 , L_3 , 0 ) ;
if ( ! V_26 [ 0 ] || ! V_26 [ 1 ] || ! V_27 ) {
F_4 ( & V_18 -> V_15 , L_4 ) ;
return - V_28 ;
}
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
V_29 [ V_22 ] . V_30 = NULL ;
V_29 [ V_22 ] . V_31 = V_27 ;
V_29 [ V_22 ] . V_32 = NULL ;
V_29 [ V_22 ] . V_33 = V_26 [ V_22 ] ;
V_29 [ V_22 ] . V_34 = NULL ;
V_29 [ V_22 ] . V_35 = V_26 [ V_22 ] ;
}
F_7 ( V_27 ) ;
F_7 ( V_26 [ 0 ] ) ;
F_7 ( V_26 [ 1 ] ) ;
V_13 = F_8 ( 0 , 44100 * 256 , 44100 ) ;
if ( V_13 ) {
F_4 ( & V_18 -> V_15 , L_5 ) ;
return V_13 ;
}
V_20 -> V_15 = & V_18 -> V_15 ;
F_9 ( V_18 , V_20 ) ;
V_13 = F_10 ( V_20 ) ;
if ( V_13 ) {
F_4 ( & V_18 -> V_15 , L_6 ,
V_13 ) ;
return V_13 ;
}
return 0 ;
}
static int F_11 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_12 ( V_18 ) ;
F_13 ( 0 ) ;
F_14 ( V_20 ) ;
return 0 ;
}

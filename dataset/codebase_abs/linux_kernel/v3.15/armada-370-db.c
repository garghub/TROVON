static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_10 ;
switch ( F_2 ( V_4 ) ) {
default:
case 44100 :
V_10 = 11289600 ;
break;
case 48000 :
V_10 = 12288000 ;
break;
case 96000 :
V_10 = 24576000 ;
break;
}
return F_3 ( V_9 , 0 , V_10 , V_11 ) ;
}
static int F_4 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_16 ;
V_15 -> V_17 = & V_13 -> V_17 ;
V_18 [ 0 ] . V_19 =
F_5 ( V_13 -> V_17 . V_20 ,
L_1 , 0 ) ;
V_18 [ 0 ] . V_21 = V_18 [ 0 ] . V_19 ;
V_18 [ 0 ] . V_22 =
F_5 ( V_13 -> V_17 . V_20 ,
L_2 , 0 ) ;
V_18 [ 1 ] . V_19 = V_18 [ 0 ] . V_19 ;
V_18 [ 1 ] . V_21 = V_18 [ 0 ] . V_19 ;
V_18 [ 1 ] . V_22 =
F_5 ( V_13 -> V_17 . V_20 ,
L_2 , 1 ) ;
V_18 [ 2 ] . V_19 = V_18 [ 0 ] . V_19 ;
V_18 [ 2 ] . V_21 = V_18 [ 0 ] . V_19 ;
V_18 [ 2 ] . V_22 =
F_5 ( V_13 -> V_17 . V_20 ,
L_2 , 2 ) ;
return F_6 ( V_15 -> V_17 , V_15 ) ;
}

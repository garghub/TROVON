static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_11 = F_2 ( V_4 ) ;
T_1 V_12 , V_13 ;
int V_14 ;
switch ( V_11 ) {
case 96000 :
V_13 = 256 * V_11 ;
break;
default:
V_13 = 512 * V_11 ;
break;
}
if ( V_13 < 8000000 || V_13 > 27000000 ) {
F_3 ( V_9 -> V_15 , L_1 ,
V_13 / 1000000 , V_13 / 1000 % 1000 ) ;
return - V_16 ;
}
V_14 = F_4 ( V_9 , V_17 , V_13 , 0 ) ;
if ( V_14 ) {
F_3 ( V_9 -> V_15 , L_2 ,
V_13 / 1000000 , V_13 / 1000 % 1000 ) ;
return V_14 ;
}
V_14 = F_4 ( V_10 , V_18 , V_13 , 0 ) ;
if ( V_14 ) {
F_3 ( V_10 -> V_15 , L_2 ,
V_13 / 1000000 , V_13 / 1000 % 1000 ) ;
return V_14 ;
}
V_12 = V_19 | V_20 |
V_21 ;
V_14 = F_5 ( V_9 , V_12 ) ;
if ( V_14 ) {
F_3 ( V_9 -> V_15 , L_3 ,
V_12 ) ;
return V_14 ;
}
V_14 = F_5 ( V_10 , V_12 ) ;
if ( V_14 ) {
F_3 ( V_10 -> V_15 , L_3 ,
V_12 ) ;
return V_14 ;
}
return 0 ;
}
static int F_6 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = & V_26 ;
int V_14 , V_27 ;
struct V_28 * V_29 = V_23 -> V_15 . V_30 ;
struct V_28 * V_31 [ 2 ] , * V_32 ;
V_31 [ 0 ] = F_7 ( V_29 , L_4 , 0 ) ;
V_31 [ 1 ] = F_7 ( V_29 , L_4 , 1 ) ;
V_32 = F_7 ( V_29 , L_5 , 0 ) ;
if ( ! V_31 [ 0 ] || ! V_31 [ 1 ] || ! V_32 ) {
F_3 ( & V_23 -> V_15 , L_6 ) ;
return - V_16 ;
}
for ( V_27 = 0 ; V_27 < 2 ; V_27 ++ ) {
V_33 [ V_27 ] . V_34 = NULL ;
V_33 [ V_27 ] . V_35 = V_32 ;
V_33 [ V_27 ] . V_36 = NULL ;
V_33 [ V_27 ] . V_37 = V_31 [ V_27 ] ;
V_33 [ V_27 ] . V_38 = NULL ;
V_33 [ V_27 ] . V_39 = V_31 [ V_27 ] ;
}
F_8 ( V_32 ) ;
F_8 ( V_31 [ 0 ] ) ;
F_8 ( V_31 [ 1 ] ) ;
V_14 = F_9 ( 0 , 44100 * 256 , 44100 ) ;
if ( V_14 ) {
F_3 ( & V_23 -> V_15 , L_7 ) ;
return V_14 ;
}
V_25 -> V_15 = & V_23 -> V_15 ;
F_10 ( V_23 , V_25 ) ;
V_14 = F_11 ( V_25 ) ;
if ( V_14 ) {
F_3 ( & V_23 -> V_15 , L_8 ,
V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_12 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_13 ( V_23 ) ;
F_14 ( 0 ) ;
F_15 ( V_25 ) ;
return 0 ;
}

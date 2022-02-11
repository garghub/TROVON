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
if ( V_13 < 8000000 || V_13 > 27000000 )
return - V_15 ;
V_14 = F_3 ( V_9 , V_16 , V_13 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_3 ( V_10 , V_17 , V_13 , 0 ) ;
if ( V_14 )
return V_14 ;
V_12 = V_18 | V_19 |
V_20 ;
V_14 = F_4 ( V_9 , V_12 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_4 ( V_10 , V_12 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int F_5 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_25 . V_26 ;
struct V_23 * V_27 [ 2 ] , * V_28 ;
int V_29 , V_14 = 0 ;
if ( ! V_24 )
return 1 ;
V_27 [ 0 ] = F_6 ( V_24 , L_1 , 0 ) ;
V_27 [ 1 ] = F_6 ( V_24 , L_1 , 1 ) ;
V_28 = F_6 ( V_24 , L_2 , 0 ) ;
if ( ! V_27 [ 0 ] || ! V_27 [ 1 ] || ! V_28 ) {
F_7 ( & V_22 -> V_25 , L_3 ) ;
return - V_15 ;
}
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
V_30 [ V_29 ] . V_31 = NULL ;
V_30 [ V_29 ] . V_32 = V_28 ;
V_30 [ V_29 ] . V_33 = NULL ;
V_30 [ V_29 ] . V_34 = V_27 [ V_29 ] ;
V_30 [ V_29 ] . V_35 = NULL ;
V_30 [ V_29 ] . V_36 = V_27 [ V_29 ] ;
}
F_8 ( V_28 ) ;
F_8 ( V_27 [ 0 ] ) ;
F_8 ( V_27 [ 1 ] ) ;
return V_14 ;
}
static int F_9 ( struct V_21 * V_22 )
{
struct V_37 * V_38 = & V_39 ;
int V_14 ;
V_14 = F_5 ( V_22 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_10 ( 0 , 44100 * 256 , 44100 ) ;
if ( V_14 )
return V_14 ;
V_38 -> V_25 = & V_22 -> V_25 ;
F_11 ( V_22 , V_38 ) ;
V_14 = F_12 ( V_38 ) ;
if ( V_14 ) {
F_7 ( & V_22 -> V_25 , L_4 ,
V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_13 ( struct V_21 * V_22 )
{
struct V_37 * V_38 = F_14 ( V_22 ) ;
F_15 ( 0 ) ;
F_16 ( V_38 ) ;
return 0 ;
}

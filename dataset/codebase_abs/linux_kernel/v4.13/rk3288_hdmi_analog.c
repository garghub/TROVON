static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 -> V_9 ) ;
if ( ! F_3 ( V_7 -> V_10 ) )
return 0 ;
F_4 ( V_7 -> V_10 ,
F_5 ( V_5 ) ) ;
return 0 ;
}
static int F_6 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
int V_15 = 0 ;
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_19 * V_21 = V_17 -> V_21 ;
int V_22 ;
switch ( F_7 ( V_14 ) ) {
case 8000 :
case 16000 :
case 24000 :
case 32000 :
case 48000 :
case 64000 :
case 96000 :
V_22 = 12288000 ;
break;
case 192000 :
V_22 = 24576000 ;
break;
case 11025 :
case 22050 :
case 44100 :
case 88200 :
V_22 = 11289600 ;
break;
default:
return - V_23 ;
}
V_15 = F_8 ( V_20 , 0 , V_22 ,
V_24 ) ;
if ( V_15 && V_15 != - V_25 ) {
F_9 ( V_21 -> V_26 , L_1 , V_15 ) ;
return V_15 ;
}
V_15 = F_8 ( V_21 , 0 , V_22 ,
V_27 ) ;
if ( V_15 && V_15 != - V_25 ) {
F_9 ( V_21 -> V_26 , L_2 , V_15 ) ;
return V_15 ;
}
return 0 ;
}
static int F_10 ( struct V_16 * V_28 )
{
struct V_6 * V_7 = F_2 ( V_28 -> V_9 ) ;
if ( F_3 ( V_7 -> V_29 ) ) {
F_11 ( V_28 -> V_9 , L_3 ,
V_30 , & V_31 ,
V_32 ,
F_12 ( V_32 ) ) ;
V_33 . V_34 = V_7 -> V_29 ;
F_13 ( & V_31 , 1 , & V_33 ) ;
}
return 0 ;
}
static int F_14 ( struct V_35 * V_36 )
{
int V_15 = 0 ;
struct V_37 * V_9 = & V_38 ;
struct V_39 * V_40 = V_36 -> V_26 . V_41 ;
struct V_6 * V_7 ;
struct V_42 args ;
V_7 = F_15 ( & V_36 -> V_26 , sizeof( struct V_6 ) ,
V_43 ) ;
if ( ! V_7 )
return - V_44 ;
V_9 -> V_26 = & V_36 -> V_26 ;
V_7 -> V_29 = F_16 ( V_40 ,
L_4 , 0 ) ;
if ( ! F_3 ( V_7 -> V_29 ) && V_7 -> V_29 != - V_45 )
return V_7 -> V_29 ;
V_7 -> V_10 = F_16 ( V_40 ,
L_5 , 0 ) ;
if ( ! F_3 ( V_7 -> V_10 ) && V_7 -> V_10 != - V_45 )
return V_7 -> V_10 ;
if ( F_3 ( V_7 -> V_10 ) ) {
V_15 = F_17 ( & V_36 -> V_26 , V_7 -> V_10 ,
V_46 , L_6 ) ;
if ( V_15 ) {
F_9 ( V_9 -> V_26 , L_7 ) ;
return V_15 ;
}
}
V_15 = F_18 ( V_9 , L_8 ) ;
if ( V_15 ) {
F_9 ( V_9 -> V_26 , L_9 , V_15 ) ;
return V_15 ;
}
V_47 . V_48 [ 0 ] . V_41 = F_19 ( V_40 ,
L_10 ,
0 ) ;
if ( ! V_47 . V_48 [ 0 ] . V_41 ) {
F_9 ( & V_36 -> V_26 ,
L_11 ) ;
return - V_23 ;
}
V_15 = F_20 ( V_40 , L_10 ,
0 , 0 , & args ) ;
if ( V_15 ) {
F_9 ( & V_36 -> V_26 ,
L_12 ) ;
return V_15 ;
}
V_15 = F_21 ( & args , & V_47 . V_48 [ 0 ] . V_49 ) ;
if ( V_15 ) {
F_9 ( & V_36 -> V_26 , L_13 ) ;
return V_15 ;
}
V_47 . V_50 = F_19 ( V_40 , L_14 ,
0 ) ;
if ( ! V_47 . V_50 ) {
F_9 ( & V_36 -> V_26 ,
L_15 ) ;
return - V_23 ;
}
V_47 . V_51 = V_47 . V_50 ;
V_15 = F_22 ( V_9 , L_16 ) ;
if ( V_15 ) {
F_9 ( & V_36 -> V_26 ,
L_17 ) ;
return V_15 ;
}
F_23 ( V_9 , V_7 ) ;
V_15 = F_24 ( & V_36 -> V_26 , V_9 ) ;
if ( V_15 == - V_52 )
return - V_52 ;
if ( V_15 ) {
F_9 ( & V_36 -> V_26 ,
L_18 , V_15 ) ;
return V_15 ;
}
F_25 ( V_36 , V_9 ) ;
return V_15 ;
}

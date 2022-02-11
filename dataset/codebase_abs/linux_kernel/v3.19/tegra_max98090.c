static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_14 , V_15 ;
int V_16 ;
V_14 = F_3 ( V_4 ) ;
switch ( V_14 ) {
case 8000 :
case 16000 :
case 24000 :
case 32000 :
case 48000 :
case 64000 :
case 96000 :
V_15 = 12288000 ;
break;
case 11025 :
case 22050 :
case 44100 :
case 88200 :
V_15 = 11289600 ;
break;
default:
V_15 = 12000000 ;
break;
}
V_16 = F_4 ( & V_13 -> V_17 , V_14 , V_15 ) ;
if ( V_16 < 0 ) {
F_5 ( V_11 -> V_18 , L_1 ) ;
return V_16 ;
}
V_16 = F_6 ( V_9 , 0 , V_15 ,
V_19 ) ;
if ( V_16 < 0 ) {
F_5 ( V_11 -> V_18 , L_2 ) ;
return V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_20 * V_21 = V_9 -> V_21 ;
struct V_12 * V_13 = F_2 ( V_6 -> V_11 ) ;
if ( F_8 ( V_13 -> V_22 ) ) {
F_9 ( V_21 , L_3 , V_23 ,
& V_24 ) ;
F_10 ( & V_24 ,
F_11 ( V_25 ) ,
V_25 ) ;
V_26 . V_27 = V_13 -> V_22 ;
F_12 ( & V_24 ,
1 ,
& V_26 ) ;
}
if ( F_8 ( V_13 -> V_28 ) ) {
F_9 ( V_21 , L_4 , V_29 ,
& V_30 ) ;
F_10 ( & V_30 ,
F_11 ( V_31 ) ,
V_31 ) ;
V_32 . V_27 = V_13 -> V_28 ;
F_12 ( & V_30 ,
1 ,
& V_32 ) ;
}
return 0 ;
}
static int F_13 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_2 ( V_11 ) ;
if ( F_8 ( V_13 -> V_22 ) ) {
F_14 ( & V_24 , 1 ,
& V_26 ) ;
}
if ( F_8 ( V_13 -> V_28 ) ) {
F_14 ( & V_30 , 1 ,
& V_32 ) ;
}
return 0 ;
}
static int F_15 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_18 . V_37 ;
struct V_10 * V_11 = & V_38 ;
struct V_12 * V_13 ;
int V_39 ;
V_13 = F_16 ( & V_34 -> V_18 ,
sizeof( struct V_12 ) , V_40 ) ;
if ( ! V_13 ) {
F_5 ( & V_34 -> V_18 , L_5 ) ;
return - V_41 ;
}
V_11 -> V_18 = & V_34 -> V_18 ;
F_17 ( V_34 , V_11 ) ;
F_18 ( V_11 , V_13 ) ;
V_13 -> V_22 = F_19 ( V_36 , L_6 , 0 ) ;
if ( V_13 -> V_22 == - V_42 )
return - V_42 ;
V_13 -> V_28 =
F_19 ( V_36 , L_7 , 0 ) ;
if ( V_13 -> V_28 == - V_42 )
return - V_42 ;
V_39 = F_20 ( V_11 , L_8 ) ;
if ( V_39 )
goto V_16;
V_39 = F_21 ( V_11 , L_9 ) ;
if ( V_39 )
goto V_16;
V_43 . V_44 = F_22 ( V_36 ,
L_10 , 0 ) ;
if ( ! V_43 . V_44 ) {
F_5 ( & V_34 -> V_18 ,
L_11 ) ;
V_39 = - V_45 ;
goto V_16;
}
V_43 . V_46 = F_22 ( V_36 ,
L_12 , 0 ) ;
if ( ! V_43 . V_46 ) {
F_5 ( & V_34 -> V_18 ,
L_13 ) ;
V_39 = - V_45 ;
goto V_16;
}
V_43 . V_47 = V_43 . V_46 ;
V_39 = F_23 ( & V_13 -> V_17 , & V_34 -> V_18 ) ;
if ( V_39 )
goto V_16;
V_39 = F_24 ( V_11 ) ;
if ( V_39 ) {
F_5 ( & V_34 -> V_18 , L_14 ,
V_39 ) ;
goto V_48;
}
return 0 ;
V_48:
F_25 ( & V_13 -> V_17 ) ;
V_16:
return V_39 ;
}
static int F_26 ( struct V_33 * V_34 )
{
struct V_10 * V_11 = F_27 ( V_34 ) ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
F_28 ( V_11 ) ;
F_25 ( & V_13 -> V_17 ) ;
return 0 ;
}

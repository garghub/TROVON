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
return 0 ;
}
static int F_13 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_2 ( V_11 ) ;
if ( F_8 ( V_13 -> V_22 ) ) {
F_14 ( & V_24 , 1 ,
& V_26 ) ;
}
return 0 ;
}
static int F_15 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = V_29 -> V_18 . V_32 ;
struct V_10 * V_11 = & V_33 ;
struct V_12 * V_13 ;
int V_34 ;
V_13 = F_16 ( & V_29 -> V_18 ,
sizeof( struct V_12 ) , V_35 ) ;
if ( ! V_13 ) {
F_5 ( & V_29 -> V_18 , L_4 ) ;
return - V_36 ;
}
V_11 -> V_18 = & V_29 -> V_18 ;
F_17 ( V_29 , V_11 ) ;
F_18 ( V_11 , V_13 ) ;
V_13 -> V_22 = F_19 ( V_31 , L_5 , 0 ) ;
if ( V_13 -> V_22 == - V_37 )
return - V_37 ;
V_34 = F_20 ( V_11 , L_6 ) ;
if ( V_34 )
goto V_16;
V_34 = F_21 ( V_11 , L_7 ) ;
if ( V_34 )
goto V_16;
V_38 . V_39 = F_22 ( V_31 ,
L_8 , 0 ) ;
if ( ! V_38 . V_39 ) {
F_5 ( & V_29 -> V_18 ,
L_9 ) ;
V_34 = - V_40 ;
goto V_16;
}
V_38 . V_41 = F_22 ( V_31 ,
L_10 , 0 ) ;
if ( ! V_38 . V_41 ) {
F_5 ( & V_29 -> V_18 ,
L_11 ) ;
V_34 = - V_40 ;
goto V_16;
}
V_38 . V_42 = V_38 . V_41 ;
V_34 = F_23 ( & V_13 -> V_17 , & V_29 -> V_18 ) ;
if ( V_34 )
goto V_16;
V_34 = F_24 ( V_11 ) ;
if ( V_34 ) {
F_5 ( & V_29 -> V_18 , L_12 ,
V_34 ) ;
goto V_43;
}
return 0 ;
V_43:
F_25 ( & V_13 -> V_17 ) ;
V_16:
return V_34 ;
}
static int F_26 ( struct V_28 * V_29 )
{
struct V_10 * V_11 = F_27 ( V_29 ) ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
F_28 ( V_11 ) ;
F_25 ( & V_13 -> V_17 ) ;
return 0 ;
}

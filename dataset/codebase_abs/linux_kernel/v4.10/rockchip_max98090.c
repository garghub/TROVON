static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_9 * V_11 = V_7 -> V_11 ;
int V_12 ;
switch ( F_2 ( V_4 ) ) {
case 8000 :
case 16000 :
case 24000 :
case 32000 :
case 48000 :
case 64000 :
case 96000 :
V_12 = 12288000 ;
break;
case 11025 :
case 22050 :
case 44100 :
case 88200 :
V_12 = 11289600 ;
break;
default:
return - V_13 ;
}
V_5 = F_3 ( V_10 , 0 , V_12 ,
V_14 ) ;
if ( V_5 < 0 ) {
F_4 ( V_11 -> V_15 , L_1 , V_5 ) ;
return V_5 ;
}
V_5 = F_3 ( V_11 , 0 , V_12 ,
V_16 ) ;
if ( V_5 < 0 ) {
F_4 ( V_11 -> V_15 , L_1 , V_5 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_5 ( struct V_17 * V_18 )
{
int V_5 ;
V_5 = F_6 ( & V_19 , L_2 ,
V_20 |
V_21 | V_22 |
V_23 | V_24 ,
& V_25 ,
V_26 ,
F_7 ( V_26 ) ) ;
if ( V_5 )
return V_5 ;
V_5 = F_8 ( V_18 , & V_25 ) ;
return V_5 ;
}
static int F_9 ( struct V_27 * V_28 )
{
int V_5 = 0 ;
struct V_29 * V_30 = & V_19 ;
struct V_31 * V_32 = V_28 -> V_15 . V_33 ;
V_30 -> V_15 = & V_28 -> V_15 ;
V_34 . V_35 = F_10 ( V_32 ,
L_3 , 0 ) ;
if ( ! V_34 . V_35 ) {
F_4 ( & V_28 -> V_15 ,
L_4 ) ;
return - V_13 ;
}
V_34 . V_36 = F_10 ( V_32 ,
L_5 , 0 ) ;
if ( ! V_34 . V_36 ) {
F_4 ( & V_28 -> V_15 ,
L_6 ) ;
return - V_13 ;
}
V_34 . V_37 = V_34 . V_36 ;
V_38 . V_35 = F_10 ( V_32 ,
L_7 , 0 ) ;
if ( ! V_38 . V_35 ) {
F_4 ( & V_28 -> V_15 ,
L_8 ) ;
return - V_13 ;
}
V_5 = F_11 ( V_30 , L_9 ) ;
if ( V_5 ) {
F_4 ( & V_28 -> V_15 ,
L_10 , V_5 ) ;
return V_5 ;
}
V_5 = F_12 ( & V_28 -> V_15 , V_30 ) ;
if ( V_5 ) {
F_4 ( & V_28 -> V_15 ,
L_11 , V_5 ) ;
return V_5 ;
}
return V_5 ;
}

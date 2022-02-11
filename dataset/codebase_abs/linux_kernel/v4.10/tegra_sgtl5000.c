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
case 11025 :
case 22050 :
case 44100 :
case 88200 :
V_15 = 11289600 ;
break;
default:
V_15 = 12288000 ;
break;
}
V_16 = F_4 ( & V_13 -> V_17 , V_14 , V_15 ) ;
if ( V_16 < 0 ) {
F_5 ( V_11 -> V_18 , L_1 ) ;
return V_16 ;
}
V_16 = F_6 ( V_9 , V_19 , V_15 ,
V_20 ) ;
if ( V_16 < 0 ) {
F_5 ( V_11 -> V_18 , L_2 ) ;
return V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_18 . V_25 ;
struct V_10 * V_11 = & V_26 ;
struct V_12 * V_13 ;
int V_27 ;
V_13 = F_8 ( & V_22 -> V_18 , sizeof( struct V_12 ) ,
V_28 ) ;
if ( ! V_13 ) {
F_5 ( & V_22 -> V_18 , L_3 ) ;
return - V_29 ;
}
V_11 -> V_18 = & V_22 -> V_18 ;
F_9 ( V_22 , V_11 ) ;
F_10 ( V_11 , V_13 ) ;
V_27 = F_11 ( V_11 , L_4 ) ;
if ( V_27 )
goto V_16;
V_27 = F_12 ( V_11 , L_5 ) ;
if ( V_27 )
goto V_16;
V_30 . V_31 = F_13 ( V_24 ,
L_6 , 0 ) ;
if ( ! V_30 . V_31 ) {
F_5 ( & V_22 -> V_18 ,
L_7 ) ;
V_27 = - V_32 ;
goto V_16;
}
V_30 . V_33 = F_13 ( V_24 ,
L_8 , 0 ) ;
if ( ! V_30 . V_33 ) {
F_5 ( & V_22 -> V_18 ,
L_9 ) ;
V_27 = - V_32 ;
goto V_16;
}
V_30 . V_34 = V_30 . V_33 ;
V_27 = F_14 ( & V_13 -> V_17 , & V_22 -> V_18 ) ;
if ( V_27 )
goto V_16;
V_27 = F_15 ( V_11 ) ;
if ( V_27 ) {
F_5 ( & V_22 -> V_18 , L_10 ,
V_27 ) ;
goto V_35;
}
return 0 ;
V_35:
F_16 ( & V_13 -> V_17 ) ;
V_16:
return V_27 ;
}
static int F_17 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = F_18 ( V_22 ) ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_27 ;
V_27 = F_19 ( V_11 ) ;
F_16 ( & V_13 -> V_17 ) ;
return V_27 ;
}

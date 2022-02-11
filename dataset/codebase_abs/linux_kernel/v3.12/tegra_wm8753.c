static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
int V_16 , V_17 ;
int V_18 ;
V_16 = F_3 ( V_4 ) ;
switch ( V_16 ) {
case 11025 :
case 22050 :
case 44100 :
case 88200 :
V_17 = 11289600 ;
break;
default:
V_17 = 12288000 ;
break;
}
V_18 = F_4 ( & V_15 -> V_19 , V_16 , V_17 ) ;
if ( V_18 < 0 ) {
F_5 ( V_13 -> V_20 , L_1 ) ;
return V_18 ;
}
V_18 = F_6 ( V_9 , V_21 , V_17 ,
V_22 ) ;
if ( V_18 < 0 ) {
F_5 ( V_13 -> V_20 , L_2 ) ;
return V_18 ;
}
return 0 ;
}
static int F_7 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_20 . V_27 ;
struct V_12 * V_13 = & V_28 ;
struct V_14 * V_15 ;
int V_29 ;
V_15 = F_8 ( & V_24 -> V_20 , sizeof( struct V_14 ) ,
V_30 ) ;
if ( ! V_15 ) {
F_5 ( & V_24 -> V_20 , L_3 ) ;
return - V_31 ;
}
V_13 -> V_20 = & V_24 -> V_20 ;
F_9 ( V_24 , V_13 ) ;
F_10 ( V_13 , V_15 ) ;
V_29 = F_11 ( V_13 , L_4 ) ;
if ( V_29 )
goto V_18;
V_29 = F_12 ( V_13 , L_5 ) ;
if ( V_29 )
goto V_18;
V_32 . V_33 = F_13 ( V_26 ,
L_6 , 0 ) ;
if ( ! V_32 . V_33 ) {
F_5 ( & V_24 -> V_20 ,
L_7 ) ;
V_29 = - V_34 ;
goto V_18;
}
V_32 . V_35 = F_13 ( V_26 ,
L_8 , 0 ) ;
if ( ! V_32 . V_35 ) {
F_5 ( & V_24 -> V_20 ,
L_9 ) ;
V_29 = - V_34 ;
goto V_18;
}
V_32 . V_36 = V_32 . V_35 ;
V_29 = F_14 ( & V_15 -> V_19 , & V_24 -> V_20 ) ;
if ( V_29 )
goto V_18;
V_29 = F_15 ( V_13 ) ;
if ( V_29 ) {
F_5 ( & V_24 -> V_20 , L_10 ,
V_29 ) ;
goto V_37;
}
return 0 ;
V_37:
F_16 ( & V_15 -> V_19 ) ;
V_18:
return V_29 ;
}
static int F_17 ( struct V_23 * V_24 )
{
struct V_12 * V_13 = F_18 ( V_24 ) ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
F_19 ( V_13 ) ;
F_16 ( & V_15 -> V_19 ) ;
return 0 ;
}

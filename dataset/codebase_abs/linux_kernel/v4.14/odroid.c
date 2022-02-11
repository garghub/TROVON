static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_4 , V_5 , 2 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_4 ( V_9 -> V_13 ) ;
unsigned int V_14 , V_15 ;
int V_16 ;
switch ( F_5 ( V_7 ) ) {
case 32000 :
case 64000 :
V_14 = 131072006U ;
break;
case 44100 :
case 88200 :
case 176400 :
V_14 = 180633609U ;
break;
case 48000 :
case 96000 :
case 192000 :
V_14 = 196608001U ;
break;
default:
return - V_17 ;
}
V_16 = F_6 ( V_12 -> V_18 , V_14 / 2 + 1 ) ;
if ( V_16 < 0 )
return V_16 ;
V_15 = F_5 ( V_7 ) * 256 + 1 ;
V_16 = F_6 ( V_12 -> V_19 , V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_9 -> V_20 > 1 ) {
struct V_21 * V_22 = V_9 -> V_23 [ 1 ] ;
V_16 = F_7 ( V_22 , 0 , V_15 ,
V_24 ) ;
if ( V_16 < 0 )
return V_16 ;
}
return 0 ;
}
static void F_8 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = V_26 -> V_29 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_26 -> V_20 ; V_30 ++ , V_28 ++ ) {
if ( ! V_28 -> V_31 )
break;
F_9 ( V_28 -> V_31 ) ;
}
}
static int F_10 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = & V_33 -> V_35 ;
struct V_36 * V_37 , * V_38 ;
struct V_11 * V_12 ;
struct V_25 * V_26 ;
struct V_39 * V_13 ;
int V_16 ;
V_12 = F_11 ( V_35 , sizeof( * V_12 ) , V_40 ) ;
if ( ! V_12 )
return - V_41 ;
V_13 = & V_12 -> V_13 ;
V_13 -> V_35 = V_35 ;
V_13 -> V_42 = V_43 ;
V_13 -> V_44 = true ;
F_12 ( V_13 , V_12 ) ;
V_16 = F_13 ( V_13 , L_1 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( F_14 ( V_35 -> V_31 , L_2 ) ) {
V_16 = F_15 ( V_13 ,
L_2 ) ;
if ( V_16 < 0 )
return V_16 ;
}
if ( F_14 ( V_35 -> V_31 , L_3 ) ) {
V_16 = F_16 ( V_13 ,
L_3 ) ;
if ( V_16 < 0 )
return V_16 ;
}
V_26 = & V_12 -> V_45 ;
V_26 -> V_46 = & V_47 ;
V_26 -> V_48 = V_49 | V_50 |
V_51 ;
V_13 -> V_45 = & V_12 -> V_45 ;
V_13 -> V_52 = 1 ;
V_37 = F_17 ( V_35 -> V_31 , L_4 ) ;
V_38 = F_17 ( V_35 -> V_31 , L_5 ) ;
V_26 -> V_53 = F_18 ( V_37 , L_6 , 0 ) ;
if ( ! V_26 -> V_53 ) {
F_19 ( V_35 , L_7 ) ;
return - V_17 ;
}
V_16 = F_20 ( V_35 , V_38 , V_26 ) ;
if ( V_16 < 0 )
goto V_54;
V_26 -> V_55 = V_26 -> V_53 ;
V_26 -> V_56 = L_8 ;
V_26 -> V_57 = V_26 -> V_56 ;
V_12 -> V_19 = F_21 ( V_26 -> V_53 , L_9 ) ;
if ( F_22 ( V_12 -> V_19 ) ) {
V_16 = F_23 ( V_12 -> V_19 ) ;
goto V_58;
}
V_12 -> V_18 = F_21 ( V_26 -> V_53 , L_10 ) ;
if ( F_22 ( V_12 -> V_18 ) ) {
V_16 = F_23 ( V_12 -> V_18 ) ;
goto V_59;
}
V_16 = F_24 ( V_35 , V_13 ) ;
if ( V_16 < 0 ) {
F_19 ( V_35 , L_11 , V_16 ) ;
goto V_60;
}
return 0 ;
V_60:
F_25 ( V_12 -> V_18 ) ;
V_59:
F_25 ( V_12 -> V_19 ) ;
V_58:
F_9 ( V_26 -> V_53 ) ;
V_54:
F_8 ( V_26 ) ;
return V_16 ;
}
static int F_26 ( struct V_32 * V_33 )
{
struct V_11 * V_12 = F_27 ( V_33 ) ;
F_9 ( V_12 -> V_45 . V_53 ) ;
F_8 ( & V_12 -> V_45 ) ;
F_25 ( V_12 -> V_19 ) ;
F_25 ( V_12 -> V_18 ) ;
return 0 ;
}

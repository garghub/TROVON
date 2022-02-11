static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_3 ( V_4 -> V_6 ) ;
if ( V_5 ) {
F_4 ( V_2 , L_1 ) ;
return V_5 ;
}
V_5 = F_3 ( V_4 -> V_7 ) ;
if ( V_5 ) {
F_4 ( V_2 , L_2 ) ;
goto V_8;
}
F_5 ( V_4 -> V_9 , false ) ;
V_5 = F_6 ( V_4 -> V_9 ) ;
if ( V_5 ) {
F_4 ( V_2 , L_3 ) ;
goto V_10;
}
return 0 ;
V_10:
F_7 ( V_4 -> V_7 ) ;
V_8:
F_7 ( V_4 -> V_6 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_4 -> V_9 , true ) ;
F_9 ( V_4 -> V_9 ) ;
F_7 ( V_4 -> V_6 ) ;
F_7 ( V_4 -> V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 )
{
unsigned int V_13 = F_11 ( V_12 ) ;
switch ( V_13 ) {
case 8000 :
case 7350 :
return 0x0 ;
case 11025 :
return 0x1 ;
case 12000 :
return 0x2 ;
case 16000 :
return 0x3 ;
case 22050 :
return 0x4 ;
case 24000 :
return 0x5 ;
case 32000 :
return 0x6 ;
case 44100 :
return 0x7 ;
case 48000 :
return 0x8 ;
case 96000 :
return 0x9 ;
case 192000 :
return 0xa ;
default:
return - V_14 ;
}
}
static int F_12 ( struct V_15 * V_16 , unsigned int V_17 )
{
struct V_3 * V_4 = F_13 ( V_16 -> V_18 ) ;
T_1 V_19 ;
switch ( V_17 & V_20 ) {
case V_21 :
V_19 = 0x0 ;
break;
case V_22 :
V_19 = 0x1 ;
break;
default:
return - V_14 ;
}
F_14 ( V_4 -> V_9 , V_23 ,
F_15 ( V_24 ) ,
V_19 << V_24 ) ;
switch ( V_17 & V_25 ) {
case V_26 :
V_19 = 0x0 ;
break;
case V_27 :
V_19 = 0x1 ;
break;
default:
return - V_14 ;
}
F_14 ( V_4 -> V_9 , V_23 ,
F_15 ( V_28 ) ,
V_19 << V_28 ) ;
F_14 ( V_4 -> V_9 , V_23 ,
F_15 ( V_29 ) ,
V_19 << V_29 ) ;
switch ( V_17 & V_30 ) {
case V_31 :
V_19 = 0x0 ;
break;
case V_32 :
V_19 = 0x1 ;
break;
case V_33 :
V_19 = 0x2 ;
break;
case V_34 :
case V_35 :
V_19 = 0x3 ;
break;
default:
return - V_14 ;
}
F_14 ( V_4 -> V_9 , V_23 ,
F_15 ( V_36 ) ,
V_19 << V_36 ) ;
return 0 ;
}
static int F_16 ( struct V_37 * V_38 ,
struct V_11 * V_12 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_13 ( V_16 -> V_18 ) ;
int V_39 ;
F_14 ( V_4 -> V_9 , V_23 ,
V_40 ,
V_41 ) ;
F_14 ( V_4 -> V_9 , V_23 ,
V_42 ,
V_43 ) ;
V_39 = F_10 ( V_12 ) ;
if ( V_39 < 0 )
return V_39 ;
F_14 ( V_4 -> V_9 , V_44 ,
V_45 ,
V_39 << V_46 ) ;
F_14 ( V_4 -> V_9 , V_44 ,
V_47 ,
V_39 << V_48 ) ;
return 0 ;
}
static int F_17 ( struct V_49 * V_50 )
{
struct V_51 * V_52 ;
struct V_3 * V_4 ;
void T_2 * V_53 ;
int V_5 ;
V_4 = F_18 ( & V_50 -> V_2 , sizeof( * V_4 ) , V_54 ) ;
if ( ! V_4 )
return - V_55 ;
V_4 -> V_2 = & V_50 -> V_2 ;
V_4 -> V_6 = F_19 ( & V_50 -> V_2 , L_4 ) ;
if ( F_20 ( V_4 -> V_6 ) ) {
F_4 ( & V_50 -> V_2 , L_5 ) ;
return F_21 ( V_4 -> V_6 ) ;
}
V_4 -> V_7 = F_19 ( & V_50 -> V_2 , L_6 ) ;
if ( F_20 ( V_4 -> V_7 ) ) {
F_4 ( & V_50 -> V_2 , L_7 ) ;
return F_21 ( V_4 -> V_7 ) ;
}
V_52 = F_22 ( V_50 , V_56 , 0 ) ;
V_53 = F_23 ( & V_50 -> V_2 , V_52 ) ;
if ( F_20 ( V_53 ) ) {
F_4 ( & V_50 -> V_2 , L_8 ) ;
return F_21 ( V_53 ) ;
}
V_4 -> V_9 = F_24 ( & V_50 -> V_2 , V_53 ,
& V_57 ) ;
if ( F_20 ( V_4 -> V_9 ) ) {
F_4 ( & V_50 -> V_2 , L_9 ) ;
return F_21 ( V_4 -> V_9 ) ;
}
F_25 ( V_50 , V_4 ) ;
F_26 ( & V_50 -> V_2 ) ;
if ( ! F_27 ( & V_50 -> V_2 ) ) {
V_5 = F_1 ( & V_50 -> V_2 ) ;
if ( V_5 )
goto V_58;
}
V_5 = F_28 ( & V_50 -> V_2 , & V_59 ,
& V_60 , 1 ) ;
if ( V_5 ) {
F_4 ( & V_50 -> V_2 , L_10 ) ;
goto V_61;
}
return V_5 ;
V_61:
if ( ! F_29 ( & V_50 -> V_2 ) )
F_8 ( & V_50 -> V_2 ) ;
V_58:
F_30 ( & V_50 -> V_2 ) ;
return V_5 ;
}
static int F_31 ( struct V_49 * V_50 )
{
struct V_62 * V_63 = F_32 ( V_50 ) ;
struct V_3 * V_4 = F_33 ( V_63 ) ;
F_30 ( & V_50 -> V_2 ) ;
if ( ! F_29 ( & V_50 -> V_2 ) )
F_8 ( & V_50 -> V_2 ) ;
F_34 ( & V_50 -> V_2 ) ;
F_7 ( V_4 -> V_6 ) ;
F_7 ( V_4 -> V_7 ) ;
return 0 ;
}

static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
int V_8 = 0 ;
int V_9 ;
switch ( V_3 & V_10 ) {
case V_11 :
break;
case V_12 :
V_8 |= V_13 ;
break;
case V_14 :
V_8 |= V_13 | V_15 ;
break;
default:
F_3 ( V_5 -> V_16 , L_1 ) ;
return - V_17 ;
}
if ( ( V_3 & V_18 ) != V_19 )
return - V_17 ;
V_9 = F_4 ( V_7 -> V_20 , V_21 ,
V_13 | V_15 ,
V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static int F_5 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_1 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
int V_9 , V_8 = 0 ;
V_8 |= V_27 ;
F_6 ( V_7 -> V_20 , F_7 ( 0 ) , V_8 ) ;
V_8 = 0 ;
switch ( F_8 ( V_25 ) ) {
case 22050 :
V_8 |= V_28 ;
break;
case 24000 :
V_8 |= V_29 ;
break;
case 32000 :
V_8 |= V_30 ;
break;
case 44100 :
V_8 |= V_31 ;
break;
case 48000 :
V_8 |= V_32 ;
break;
case 88200 :
V_8 |= V_33 ;
break;
case 96000 :
V_8 |= V_34 ;
break;
case 176400 :
V_8 |= V_35 ;
break;
case 192000 :
V_8 |= V_36 ;
break;
default:
F_3 ( V_5 -> V_16 , L_2 ) ;
return - V_17 ;
}
V_9 = F_6 ( V_7 -> V_20 , F_7 ( 3 ) , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
int V_9 ;
V_9 = F_10 ( V_7 -> V_37 ) ;
if ( V_9 < 0 ) {
F_3 ( V_5 -> V_16 , L_3 , V_9 ) ;
return V_9 ;
}
V_9 = F_4 ( V_7 -> V_20 , V_21 ,
V_38 | V_39 ,
V_38 | V_39 ) ;
if ( V_9 < 0 )
goto V_40;
V_9 = F_4 ( V_7 -> V_20 , V_41 ,
V_42 , V_42 ) ;
if ( V_9 < 0 )
goto V_40;
return 0 ;
V_40:
F_11 ( V_7 -> V_37 ) ;
return V_9 ;
}
static int F_12 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
F_4 ( V_7 -> V_20 , V_21 ,
V_38 | V_39 , 0 ) ;
F_11 ( V_7 -> V_37 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 )
{
struct V_6 * V_43 = F_2 ( V_5 ) ;
F_11 ( V_43 -> V_37 ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 )
{
struct V_6 * V_43 = F_2 ( V_5 ) ;
int V_9 ;
V_9 = F_10 ( V_43 -> V_37 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static int F_15 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = V_45 -> V_16 . V_48 ;
struct V_6 * V_7 ;
unsigned int V_8 ;
int V_9 ;
V_45 -> V_49 = 8 ;
V_45 -> V_50 = V_51 ;
V_9 = F_16 ( V_45 ) ;
if ( V_9 < 0 )
return V_9 ;
V_7 = F_17 ( & V_45 -> V_16 , sizeof( struct V_6 ) ,
V_52 ) ;
if ( V_7 == NULL )
return - V_53 ;
V_7 -> V_37 = F_18 ( & V_45 -> V_16 , L_4 ) ;
if ( F_19 ( V_7 -> V_37 ) ) {
V_9 = F_20 ( V_7 -> V_37 ) ;
F_3 ( & V_45 -> V_16 , L_5 , V_9 ) ;
return V_9 ;
}
V_7 -> V_20 = F_21 ( V_45 , & V_54 ) ;
if ( F_19 ( V_7 -> V_20 ) ) {
V_9 = F_20 ( V_7 -> V_20 ) ;
return V_9 ;
}
if ( V_47 ) {
enum V_55 V_56 ;
int V_57 = F_22 ( V_47 , L_6 , 0 , & V_56 ) ;
if ( F_23 ( V_57 ) ) {
V_9 = F_24 ( & V_45 -> V_16 , V_57 ,
V_56 & V_58 ?
V_59 : V_60 ,
L_7 ) ;
if ( V_9 < 0 )
return V_9 ;
}
}
V_9 = F_25 ( V_7 -> V_20 , V_61 , & V_8 ) ;
if ( V_9 != 0 )
return V_9 ;
if ( V_8 != V_62 )
return - V_63 ;
F_26 ( V_45 , V_7 ) ;
V_9 = F_27 ( & V_45 -> V_16 ,
& V_64 , & V_65 , 1 ) ;
return V_9 ;
}
static int F_28 ( struct V_44 * V_45 )
{
F_29 ( & V_45 -> V_16 ) ;
return 0 ;
}

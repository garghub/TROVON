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
V_9 = F_4 ( V_7 -> V_20 , V_37 ,
V_38 , V_38 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static int F_9 ( struct V_22 * V_23 ,
struct V_1 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
return F_4 ( V_7 -> V_20 , V_37 ,
V_38 , 0 ) ;
}
static int F_10 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
int V_9 ;
V_5 -> V_39 = V_7 -> V_20 ;
V_9 = F_4 ( V_7 -> V_20 , V_21 ,
V_40 | V_41 ,
V_40 | V_41 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_4 ( V_7 -> V_20 , V_37 ,
V_38 , V_38 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
F_4 ( V_7 -> V_20 , V_21 ,
V_40 | V_41 , 0 ) ;
return 0 ;
}
static int F_12 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_16 . V_46 ;
struct V_6 * V_7 ;
unsigned int V_8 ;
int V_9 ;
V_43 -> V_47 = 8 ;
V_43 -> V_48 = V_49 ;
V_9 = F_13 ( V_43 ) ;
if ( V_9 < 0 )
return V_9 ;
V_7 = F_14 ( & V_43 -> V_16 , sizeof( struct V_6 ) ,
V_50 ) ;
if ( V_7 == NULL )
return - V_51 ;
V_7 -> V_20 = F_15 ( V_43 , & V_52 ) ;
if ( F_16 ( V_7 -> V_20 ) ) {
V_9 = F_17 ( V_7 -> V_20 ) ;
return V_9 ;
}
if ( V_45 ) {
enum V_53 V_54 ;
int V_55 = F_18 ( V_45 , L_3 , 0 , & V_54 ) ;
if ( F_19 ( V_55 ) ) {
V_9 = F_20 ( & V_43 -> V_16 , V_55 ,
V_54 & V_56 ?
V_57 : V_58 ,
L_4 ) ;
if ( V_9 < 0 )
return V_9 ;
}
}
V_9 = F_21 ( V_7 -> V_20 , V_59 , & V_8 ) ;
if ( V_9 != 0 )
return V_9 ;
if ( V_8 != V_60 )
return - V_61 ;
F_22 ( V_43 , V_7 ) ;
V_9 = F_23 ( & V_43 -> V_16 ,
& V_62 , & V_63 , 1 ) ;
return V_9 ;
}
static int F_24 ( struct V_42 * V_43 )
{
F_25 ( & V_43 -> V_16 ) ;
return 0 ;
}

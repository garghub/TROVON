static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = 0 ;
int V_7 ;
switch ( V_3 & V_8 ) {
case V_9 :
break;
case V_10 :
V_6 |= V_11 ;
break;
case V_12 :
V_6 |= V_11 | V_13 ;
break;
default:
F_2 ( V_5 -> V_14 , L_1 ) ;
return - V_15 ;
}
if ( ( V_3 & V_16 ) != V_17 )
return - V_15 ;
V_7 = F_3 ( V_5 , V_18 ,
V_11 | V_13 ,
V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_4 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_1 * V_23 )
{
struct V_4 * V_5 = V_23 -> V_5 ;
int V_6 = 0 ;
V_6 |= V_24 ;
F_5 ( V_5 , F_6 ( 0 ) , V_6 ) ;
V_6 = 0 ;
switch ( F_7 ( V_22 ) ) {
case 22050 :
V_6 |= V_25 ;
break;
case 24000 :
V_6 |= V_26 ;
break;
case 32000 :
V_6 |= V_27 ;
break;
case 44100 :
V_6 |= V_28 ;
break;
case 48000 :
V_6 |= V_29 ;
break;
case 88200 :
V_6 |= V_30 ;
break;
case 96000 :
V_6 |= V_31 ;
break;
case 176400 :
V_6 |= V_32 ;
break;
case 192000 :
V_6 |= V_33 ;
break;
default:
F_2 ( V_5 -> V_14 , L_2 ) ;
return - V_15 ;
}
return F_5 ( V_5 , F_6 ( 3 ) , V_6 ) ;
}
static int F_8 ( struct V_4 * V_5 )
{
struct V_34 * V_35 = F_9 ( V_5 ) ;
int V_7 ;
V_5 -> V_36 = V_35 -> V_37 ;
V_7 = F_10 ( V_5 , 8 , 8 , V_38 ) ;
if ( V_7 != 0 )
return V_7 ;
V_7 = F_3 ( V_5 , V_18 ,
V_39 | V_40 ,
V_39 | V_40 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_3 ( V_5 , V_41 ,
V_42 , V_42 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
F_3 ( V_5 , V_18 ,
V_39 | V_40 , 0 ) ;
return 0 ;
}
static int F_12 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = V_44 -> V_14 . V_47 ;
struct V_34 * V_35 ;
unsigned int V_6 ;
int V_7 ;
V_44 -> V_48 = 8 ;
V_44 -> V_49 = V_50 ;
V_7 = F_13 ( V_44 ) ;
if ( V_7 < 0 )
return V_7 ;
V_35 = F_14 ( & V_44 -> V_14 , sizeof( struct V_34 ) ,
V_51 ) ;
if ( V_35 == NULL )
return - V_52 ;
V_35 -> V_37 = F_15 ( V_44 , & V_53 ) ;
if ( F_16 ( V_35 -> V_37 ) ) {
V_7 = F_17 ( V_35 -> V_37 ) ;
return V_7 ;
}
if ( V_46 ) {
enum V_54 V_55 ;
int V_56 = F_18 ( V_46 , L_3 , 0 , & V_55 ) ;
if ( F_19 ( V_56 ) ) {
V_7 = F_20 ( & V_44 -> V_14 , V_56 ,
V_55 & V_57 ?
V_58 : V_59 ,
L_4 ) ;
if ( V_7 < 0 )
return V_7 ;
}
}
V_7 = F_21 ( V_35 -> V_37 , V_60 , & V_6 ) ;
if ( V_7 != 0 )
return V_7 ;
if ( V_6 != V_61 )
return - V_62 ;
F_22 ( V_44 , V_35 ) ;
V_7 = F_23 ( & V_44 -> V_14 ,
& V_63 , & V_64 , 1 ) ;
return V_7 ;
}
static int F_24 ( struct V_43 * V_44 )
{
F_25 ( & V_44 -> V_14 ) ;
return 0 ;
}

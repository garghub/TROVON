static int F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 -> V_4 , V_5 ,
F_3 ( 4 ) , ( V_3 ? F_3 ( 4 ) : 0 ) ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 -> V_4 , V_6 ,
F_3 ( 4 ) , ( V_3 ? F_3 ( 4 ) : 0 ) ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 -> V_4 , V_7 ,
F_3 ( 4 ) , ( V_3 ? F_3 ( 4 ) : 0 ) ) ;
return 0 ;
}
static int F_6 ( struct V_8 * V_4 ,
enum V_9 V_10 )
{
switch ( V_10 ) {
case V_11 :
break;
case V_12 :
break;
case V_13 :
F_2 ( V_4 , V_14 ,
V_15 , F_3 ( 0 ) ) ;
break;
case V_16 :
F_2 ( V_4 , V_14 ,
V_15 , 0 ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
struct V_1 * V_2 )
{
struct V_8 * V_4 = V_2 -> V_4 ;
T_1 V_21 = 0 ;
unsigned int V_22 = 0 ;
switch ( F_8 ( V_20 ) ) {
case 8000 :
V_22 = V_23 ;
break;
case 11025 :
V_22 = V_24 ;
break;
case 12000 :
V_22 = V_25 ;
break;
case 16000 :
V_22 = V_26 ;
break;
case 22050 :
V_22 = V_27 ;
break;
case 24000 :
V_22 = V_28 ;
break;
case 32000 :
V_22 = V_29 ;
break;
case 44100 :
V_22 = V_30 ;
break;
case 48000 :
V_22 = V_31 ;
break;
default:
return - V_32 ;
}
F_2 ( V_4 , V_33 ,
V_34 , V_22 ) ;
switch ( F_9 ( V_20 ) ) {
case 20 :
V_21 |= V_35 ;
break;
case 32 :
V_21 |= V_36 ;
break;
default:
return - V_32 ;
}
F_2 ( V_4 , V_37 ,
V_38 , V_21 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_39 , unsigned int V_40 )
{
struct V_8 * V_4 = V_39 -> V_4 ;
unsigned int V_41 = 0 ;
switch ( V_40 & V_42 ) {
case V_43 :
V_41 &= ~ V_44 ;
break;
case V_45 :
V_41 |= V_44 ;
break;
default:
return - V_32 ;
}
switch ( V_40 & V_46 ) {
case V_47 :
V_41 |= V_48 ;
break;
case V_49 :
V_41 |= V_50 ;
break;
case V_51 :
V_41 |= V_52 ;
break;
default:
return - V_32 ;
}
F_2 ( V_4 , V_37 ,
( V_44 | V_53 ) , V_41 ) ;
return 0 ;
}
static int F_11 ( struct V_54 * V_55 ,
const struct V_56 * V_57 )
{
struct V_58 * V_59 ;
int V_60 = 0 ;
V_59 = F_12 ( V_55 , & V_61 ) ;
if ( F_13 ( V_59 ) ) {
V_60 = F_14 ( V_59 ) ;
F_15 ( & V_55 -> V_62 , L_1 ,
V_60 ) ;
return V_60 ;
}
F_16 ( V_55 , V_59 ) ;
V_60 = F_17 ( & V_55 -> V_62 ,
& V_63 , V_64 ,
F_18 ( V_64 ) ) ;
if ( V_60 < 0 ) {
F_15 ( & V_55 -> V_62 , L_2 , V_60 ) ;
return V_60 ;
}
return V_60 ;
}
static int F_19 ( struct V_54 * V_65 )
{
F_20 ( & V_65 -> V_62 ) ;
return 0 ;
}

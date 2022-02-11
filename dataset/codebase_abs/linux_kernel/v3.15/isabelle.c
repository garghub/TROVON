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
V_4 -> V_17 . V_18 = V_10 ;
return 0 ;
}
static int F_7 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_8 * V_4 = V_2 -> V_4 ;
T_1 V_23 = 0 ;
unsigned int V_24 = 0 ;
switch ( F_8 ( V_22 ) ) {
case 8000 :
V_24 = V_25 ;
break;
case 11025 :
V_24 = V_26 ;
break;
case 12000 :
V_24 = V_27 ;
break;
case 16000 :
V_24 = V_28 ;
break;
case 22050 :
V_24 = V_29 ;
break;
case 24000 :
V_24 = V_30 ;
break;
case 32000 :
V_24 = V_31 ;
break;
case 44100 :
V_24 = V_32 ;
break;
case 48000 :
V_24 = V_33 ;
break;
default:
return - V_34 ;
}
F_2 ( V_4 , V_35 ,
V_36 , V_24 ) ;
switch ( F_9 ( V_22 ) ) {
case 20 :
V_23 |= V_37 ;
break;
case 32 :
V_23 |= V_38 ;
break;
default:
return - V_34 ;
}
F_2 ( V_4 , V_39 ,
V_40 , V_23 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_41 , unsigned int V_42 )
{
struct V_8 * V_4 = V_41 -> V_4 ;
unsigned int V_43 = 0 ;
switch ( V_42 & V_44 ) {
case V_45 :
V_43 &= ~ V_46 ;
break;
case V_47 :
V_43 |= V_46 ;
break;
default:
return - V_34 ;
}
switch ( V_42 & V_48 ) {
case V_49 :
V_43 |= V_50 ;
break;
case V_51 :
V_43 |= V_52 ;
break;
case V_53 :
V_43 |= V_54 ;
break;
default:
return - V_34 ;
}
F_2 ( V_4 , V_39 ,
( V_46 | V_55 ) , V_43 ) ;
return 0 ;
}
static int F_11 ( struct V_56 * V_57 ,
const struct V_58 * V_59 )
{
struct V_60 * V_61 ;
int V_62 = 0 ;
V_61 = F_12 ( V_57 , & V_63 ) ;
if ( F_13 ( V_61 ) ) {
V_62 = F_14 ( V_61 ) ;
F_15 ( & V_57 -> V_64 , L_1 ,
V_62 ) ;
return V_62 ;
}
F_16 ( V_57 , V_61 ) ;
V_62 = F_17 ( & V_57 -> V_64 ,
& V_65 , V_66 ,
F_18 ( V_66 ) ) ;
if ( V_62 < 0 ) {
F_15 ( & V_57 -> V_64 , L_2 , V_62 ) ;
return V_62 ;
}
return V_62 ;
}
static int F_19 ( struct V_56 * V_67 )
{
F_20 ( & V_67 -> V_64 ) ;
return 0 ;
}

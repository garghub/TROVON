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
struct V_23 * V_24 = V_20 -> V_25 ;
struct V_8 * V_4 = V_24 -> V_4 ;
T_1 V_26 = 0 ;
unsigned int V_27 = 0 ;
switch ( F_8 ( V_22 ) ) {
case 8000 :
V_27 = V_28 ;
break;
case 11025 :
V_27 = V_29 ;
break;
case 12000 :
V_27 = V_30 ;
break;
case 16000 :
V_27 = V_31 ;
break;
case 22050 :
V_27 = V_32 ;
break;
case 24000 :
V_27 = V_33 ;
break;
case 32000 :
V_27 = V_34 ;
break;
case 44100 :
V_27 = V_35 ;
break;
case 48000 :
V_27 = V_36 ;
break;
default:
return - V_37 ;
}
F_2 ( V_4 , V_38 ,
V_39 , V_27 ) ;
switch ( F_9 ( V_22 ) ) {
case 20 :
V_26 |= V_40 ;
break;
case 32 :
V_26 |= V_41 ;
break;
default:
return - V_37 ;
}
F_2 ( V_4 , V_42 ,
V_43 , V_26 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_44 , unsigned int V_45 )
{
struct V_8 * V_4 = V_44 -> V_4 ;
unsigned int V_46 = 0 ;
switch ( V_45 & V_47 ) {
case V_48 :
V_46 &= ~ V_49 ;
break;
case V_50 :
V_46 |= V_49 ;
break;
default:
return - V_37 ;
}
switch ( V_45 & V_51 ) {
case V_52 :
V_46 |= V_53 ;
break;
case V_54 :
V_46 |= V_55 ;
break;
case V_56 :
V_46 |= V_57 ;
break;
default:
return - V_37 ;
}
F_2 ( V_4 , V_42 ,
( V_49 | V_58 ) , V_46 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_4 )
{
int V_59 = 0 ;
V_4 -> V_60 = F_12 ( V_4 -> V_61 , NULL ) ;
V_59 = F_13 ( V_4 , 8 , 8 , V_62 ) ;
if ( V_59 < 0 ) {
F_14 ( V_4 -> V_61 , L_1 , V_59 ) ;
return V_59 ;
}
return 0 ;
}
static int F_15 ( struct V_63 * V_64 ,
const struct V_65 * V_66 )
{
struct V_67 * V_68 ;
int V_59 = 0 ;
V_68 = F_16 ( V_64 , & V_69 ) ;
if ( F_17 ( V_68 ) ) {
V_59 = F_18 ( V_68 ) ;
F_14 ( & V_64 -> V_61 , L_2 ,
V_59 ) ;
return V_59 ;
}
F_19 ( V_64 , V_68 ) ;
V_59 = F_20 ( & V_64 -> V_61 ,
& V_70 , V_71 ,
F_21 ( V_71 ) ) ;
if ( V_59 < 0 ) {
F_14 ( & V_64 -> V_61 , L_3 , V_59 ) ;
return V_59 ;
}
return V_59 ;
}
static int F_22 ( struct V_63 * V_72 )
{
F_23 ( & V_72 -> V_61 ) ;
return 0 ;
}

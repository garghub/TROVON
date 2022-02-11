static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_16 * V_17 , enum
V_18 V_19 )
{
struct V_20 * V_20 = F_3 ( V_17 ) ;
switch ( V_19 ) {
case V_21 :
case V_22 :
F_4 ( V_17 , V_4 , V_23 ,
V_24 ) ;
F_4 ( V_17 , V_15 , V_25 ,
V_26 ) ;
break;
case V_27 :
if ( F_5 ( V_17 ) == V_28 )
F_6 ( V_20 -> V_29 ) ;
F_4 ( V_17 , V_4 ,
V_23 , V_30 ) ;
F_4 ( V_17 , V_4 , V_31 ,
V_32 ) ;
F_4 ( V_17 , V_15 , V_25 ,
V_33 ) ;
break;
case V_28 :
break;
}
return 0 ;
}
static int F_7 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_16 * V_17 = V_39 -> V_17 ;
int V_40 , V_41 , V_42 ;
int V_43 ;
switch ( F_8 ( V_37 ) ) {
case 16 :
V_40 = 1 ;
V_43 = 0 ;
break;
case 24 :
V_40 = 2 ;
V_43 = 1 ;
break;
case 32 :
V_40 = 3 ;
V_43 = 2 ;
break;
default:
F_9 ( V_17 -> V_2 , L_1 ) ;
return - V_44 ;
}
switch ( F_10 ( V_37 ) ) {
case 8000 :
case 11025 :
V_41 = 0 ;
V_42 = 2 ;
break;
case 16000 :
case 22050 :
V_41 = 1 ;
V_42 = 0 ;
break;
case 32000 :
case 44100 :
case 48000 :
V_41 = 2 ;
V_42 = 0 ;
break;
default:
F_9 ( V_17 -> V_2 , L_2 ) ;
return - V_44 ;
}
if ( V_35 -> V_45 == V_46 ) {
F_4 ( V_17 , V_10 , V_47 ,
V_40 << 6 ) ;
F_4 ( V_17 , V_10 , V_48 ,
V_43 << 4 ) ;
F_4 ( V_17 , V_15 , V_49 ,
V_41 << 4 ) ;
} else {
F_4 ( V_17 , V_12 , V_47 ,
V_40 << 6 ) ;
F_4 ( V_17 , V_12 , V_48 ,
V_43 << 4 ) ;
F_4 ( V_17 , V_15 , V_50 ,
V_42 << 2 ) ;
}
return 0 ;
}
static int F_11 ( struct V_38 * V_39 , int V_51 )
{
T_1 V_52 = 0 ;
if ( V_51 )
V_52 |= V_53 ;
F_4 ( V_39 -> V_17 , V_4 , V_54 , V_52 ) ;
return 0 ;
}
static int F_12 ( struct V_38 * V_55 , T_2 V_56 )
{
struct V_16 * V_17 = V_55 -> V_17 ;
T_1 V_57 = 0 ;
switch ( V_56 & V_58 ) {
case V_59 :
V_57 = V_60 ;
break;
case V_61 :
V_57 = V_62 ;
break;
case V_63 :
V_57 = V_64 ;
break;
default:
return - V_44 ;
}
F_4 ( V_17 , V_9 , V_65 , V_57 ) ;
return 0 ;
}
static int F_13 ( struct V_66 * V_67 ,
const struct V_68 * V_69 )
{
struct V_20 * V_20 ;
int V_70 ;
V_20 = F_14 ( & V_67 -> V_2 , sizeof( struct V_20 ) , V_71 ) ;
if ( ! V_20 )
return - V_72 ;
V_20 -> V_29 = F_15 ( V_67 , & V_73 ) ;
if ( F_16 ( V_20 -> V_29 ) ) {
V_70 = F_17 ( V_20 -> V_29 ) ;
F_9 ( & V_67 -> V_2 , L_3 , V_70 ) ;
return V_70 ;
}
F_18 ( V_67 , V_20 ) ;
V_70 = F_19 ( & V_67 -> V_2 ,
& V_74 , & V_75 , 1 ) ;
if ( V_70 != 0 )
F_9 ( & V_67 -> V_2 , L_4 , V_70 ) ;
return V_70 ;
}
static int F_20 ( struct V_66 * V_76 )
{
F_21 ( & V_76 -> V_2 ) ;
return 0 ;
}

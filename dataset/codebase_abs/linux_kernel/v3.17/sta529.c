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
if ( V_17 -> V_28 . V_29 == V_30 )
F_5 ( V_20 -> V_31 ) ;
F_4 ( V_17 , V_4 ,
V_23 , V_32 ) ;
F_4 ( V_17 , V_4 , V_33 ,
V_34 ) ;
F_4 ( V_17 , V_15 , V_25 ,
V_35 ) ;
break;
case V_30 :
break;
}
V_17 -> V_28 . V_29 = V_19 ;
return 0 ;
}
static int F_6 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_16 * V_17 = V_41 -> V_17 ;
int V_42 , V_43 , V_44 ;
int V_45 ;
switch ( F_7 ( V_39 ) ) {
case 16 :
V_42 = 1 ;
V_45 = 0 ;
break;
case 24 :
V_42 = 2 ;
V_45 = 1 ;
break;
case 32 :
V_42 = 3 ;
V_45 = 2 ;
break;
default:
F_8 ( V_17 -> V_2 , L_1 ) ;
return - V_46 ;
}
switch ( F_9 ( V_39 ) ) {
case 8000 :
case 11025 :
V_43 = 0 ;
V_44 = 2 ;
break;
case 16000 :
case 22050 :
V_43 = 1 ;
V_44 = 0 ;
break;
case 32000 :
case 44100 :
case 48000 :
V_43 = 2 ;
V_44 = 0 ;
break;
default:
F_8 ( V_17 -> V_2 , L_2 ) ;
return - V_46 ;
}
if ( V_37 -> V_47 == V_48 ) {
F_4 ( V_17 , V_10 , V_49 ,
V_42 << 6 ) ;
F_4 ( V_17 , V_10 , V_50 ,
V_45 << 4 ) ;
F_4 ( V_17 , V_15 , V_51 ,
V_43 << 4 ) ;
} else {
F_4 ( V_17 , V_12 , V_49 ,
V_42 << 6 ) ;
F_4 ( V_17 , V_12 , V_50 ,
V_45 << 4 ) ;
F_4 ( V_17 , V_15 , V_52 ,
V_44 << 2 ) ;
}
return 0 ;
}
static int F_10 ( struct V_40 * V_41 , int V_53 )
{
T_1 V_54 = 0 ;
if ( V_53 )
V_54 |= V_55 ;
F_4 ( V_41 -> V_17 , V_4 , V_56 , V_54 ) ;
return 0 ;
}
static int F_11 ( struct V_40 * V_57 , T_2 V_58 )
{
struct V_16 * V_17 = V_57 -> V_17 ;
T_1 V_59 = 0 ;
switch ( V_58 & V_60 ) {
case V_61 :
V_59 = V_62 ;
break;
case V_63 :
V_59 = V_64 ;
break;
case V_65 :
V_59 = V_66 ;
break;
default:
return - V_46 ;
}
F_4 ( V_17 , V_9 , V_67 , V_59 ) ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 )
{
F_2 ( V_17 , V_27 ) ;
return 0 ;
}
static int F_13 ( struct V_16 * V_17 )
{
F_2 ( V_17 , V_30 ) ;
return 0 ;
}
static int F_14 ( struct V_16 * V_17 )
{
F_2 ( V_17 , V_30 ) ;
return 0 ;
}
static int F_15 ( struct V_16 * V_17 )
{
F_2 ( V_17 , V_27 ) ;
return 0 ;
}
static int F_16 ( struct V_68 * V_69 ,
const struct V_70 * V_71 )
{
struct V_20 * V_20 ;
int V_72 ;
if ( ! F_17 ( V_69 -> V_73 , V_74 ) )
return - V_46 ;
V_20 = F_18 ( & V_69 -> V_2 , sizeof( struct V_20 ) , V_75 ) ;
if ( ! V_20 )
return - V_76 ;
V_20 -> V_31 = F_19 ( V_69 , & V_77 ) ;
if ( F_20 ( V_20 -> V_31 ) ) {
V_72 = F_21 ( V_20 -> V_31 ) ;
F_8 ( & V_69 -> V_2 , L_3 , V_72 ) ;
return V_72 ;
}
F_22 ( V_69 , V_20 ) ;
V_72 = F_23 ( & V_69 -> V_2 ,
& V_78 , & V_79 , 1 ) ;
if ( V_72 != 0 )
F_8 ( & V_69 -> V_2 , L_4 , V_72 ) ;
return V_72 ;
}
static int F_24 ( struct V_68 * V_80 )
{
F_25 ( & V_80 -> V_2 ) ;
return 0 ;
}

static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
int V_11 ;
int V_12 = 0 ;
switch ( F_3 ( V_4 ) ) {
case 8000 :
V_11 = V_13 ;
break;
case 11025 :
V_11 = V_14 ;
break;
case 12000 :
V_11 = V_15 ;
break;
case 16000 :
V_11 = V_16 ;
break;
case 22050 :
V_11 = V_17 ;
break;
case 24000 :
V_11 = V_18 ;
break;
case 32000 :
V_11 = V_19 ;
break;
case 44100 :
V_11 = V_20 ;
break;
case 48000 :
V_11 = V_21 ;
break;
case 64000 :
V_11 = V_22 ;
break;
case 88200 :
V_11 = V_23 ;
break;
case 96000 :
V_11 = V_24 ;
break;
default:
return - V_25 ;
}
switch ( F_4 ( V_4 ) ) {
case 16 :
V_12 = V_26 ;
break;
case 24 :
V_12 = V_27 ;
break;
default:
return - V_25 ;
}
if ( V_10 -> V_28 )
F_5 ( V_8 , V_29 ,
V_30 ,
V_12 << V_31 ) ;
F_5 ( V_8 , V_29 ,
V_32 ,
V_11 << V_33 ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 , int V_34 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_5 ( V_8 , V_35 ,
V_36 ,
! ! V_34 << V_37 ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 , unsigned int V_38 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
int V_12 ;
int V_39 ;
switch ( V_38 & V_40 ) {
case V_41 :
break;
default:
return - V_25 ;
}
switch ( V_38 & V_42 ) {
case V_43 :
V_39 = V_44 ;
break;
case V_45 :
V_39 = V_46 ;
break;
default:
return - V_25 ;
}
switch ( V_38 & V_47 ) {
case V_48 :
V_10 -> V_28 = 0 ;
V_12 = V_49 ;
break;
case V_50 :
V_10 -> V_28 = 0 ;
V_12 = V_51 ;
break;
case V_52 :
V_10 -> V_28 = 1 ;
V_12 = V_27 ;
break;
default:
return - V_25 ;
}
F_5 ( V_8 , V_29 ,
V_53 ,
V_39 << V_54 ) ;
F_5 ( V_8 , V_29 ,
V_30 ,
V_12 << V_31 ) ;
return 0 ;
}
static bool F_8 ( struct V_55 * V_56 , unsigned int V_57 )
{
return V_57 == V_58 ;
}
static int F_9 ( struct V_59 * V_60 ,
const struct V_61 * V_62 )
{
struct V_9 * V_10 ;
int V_63 ;
V_10 = F_10 ( & V_60 -> V_56 , sizeof( * V_10 ) , V_64 ) ;
if ( F_11 ( V_10 ) )
return F_12 ( V_10 ) ;
F_13 ( V_60 , V_10 ) ;
V_10 -> V_65 = F_14 ( V_60 , & V_66 ) ;
if ( F_11 ( V_10 -> V_65 ) )
return F_12 ( V_10 -> V_65 ) ;
for ( V_63 = 0 ; V_63 < F_15 ( V_67 ) ; V_63 ++ )
F_16 ( V_10 -> V_65 ,
V_67 [ V_63 ] . V_57 , V_67 [ V_63 ] . V_68 ) ;
return F_17 ( & V_60 -> V_56 , & V_69 ,
& V_70 , 1 ) ;
}
static int F_18 ( struct V_59 * V_71 )
{
F_19 ( & V_71 -> V_56 ) ;
return 0 ;
}

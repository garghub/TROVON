static int F_1 ( struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
unsigned int V_4 , V_5 ;
V_3 = F_2 ( V_1 , V_6 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_1 , V_7 , & V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_5 &= V_8 ;
V_5 >>= V_9 ;
if ( V_5 == V_10 ) {
if ( V_4 & V_11 )
* V_2 = V_12 ;
else
* V_2 = V_13 ;
} else if ( ( V_5 == V_14 ) ||
( V_5 == V_15 ) ) {
* V_2 = V_16 ;
} else {
* V_2 = V_13 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
unsigned int V_5 ;
V_3 = F_2 ( V_1 , V_7 , & V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_5 &= V_8 ;
V_5 >>= V_9 ;
switch ( V_5 ) {
case V_15 :
* V_2 = V_17 ;
break;
case V_14 :
* V_2 = V_18 ;
break;
case V_10 :
case V_19 :
default:
* V_2 = V_20 ;
}
return 0 ;
}
static int F_4 ( struct V_21 * V_22 ,
struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
unsigned int V_4 ;
V_3 = F_2 ( V_1 , V_6 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_22 -> V_23 && ! ( V_4 & V_24 ) )
* V_2 = V_25 ;
else if ( ! ( V_4 & V_26 ) )
* V_2 = V_27 ;
else if ( V_4 & V_28 )
* V_2 = V_29 ;
else
* V_2 = V_30 ;
return 0 ;
}
static int F_5 ( struct V_31 * V_32 ,
enum V_33 V_34 ,
union V_35 * V_2 )
{
struct V_21 * V_22 = F_6 ( V_32 ) ;
struct V_1 * V_1 = V_22 -> V_1 ;
int V_3 = 0 ;
switch ( V_34 ) {
case V_36 :
V_3 = F_1 ( V_1 , & V_2 -> V_37 ) ;
break;
case V_38 :
V_3 = F_3 ( V_1 , & V_2 -> V_37 ) ;
break;
case V_39 :
V_2 -> V_37 = V_40 ;
break;
case V_41 :
V_3 = F_4 ( V_22 ,
V_1 , & V_2 -> V_37 ) ;
break;
case V_42 :
V_2 -> V_43 = V_44 ;
break;
case V_45 :
V_2 -> V_43 = V_46 ;
break;
default:
return - V_47 ;
}
return V_3 ;
}
static int F_7 ( struct V_48 * V_49 ,
struct V_21 * V_22 )
{
struct V_50 * V_51 = V_49 -> V_52 ;
enum V_53 V_54 ;
struct V_1 * V_1 = V_22 -> V_1 ;
T_1 V_55 ;
T_1 V_56 ;
T_1 V_57 ;
int V_58 ;
unsigned int V_59 = 0 ;
if ( ! V_51 ) {
F_8 ( V_49 , L_1 ) ;
return - V_47 ;
}
V_22 -> V_23 = F_9 ( V_51 ,
L_2 ) ;
V_58 = F_10 ( V_51 ,
L_3 , 0 , & V_54 ) ;
if ( F_11 ( V_58 ) ) {
F_12 ( V_58 ,
( ( V_54 == V_60 ) ? 0 : 1 ) ) ;
}
if ( F_13 ( V_51 ,
L_4 ,
& V_57 ) )
V_57 = V_61 ;
if ( F_13 ( V_51 ,
L_5 ,
& V_56 ) )
V_56 = V_62 ;
if ( F_13 ( V_51 , L_6 ,
& V_55 ) )
V_55 = V_63 ;
switch ( V_57 ) {
case 8000 :
V_59 |= V_64 ;
break;
case 7500 :
V_59 |= V_65 ;
break;
case 7000 :
V_59 |= V_66 ;
break;
case 6600 :
default:
V_59 |= V_67 ;
break;
}
switch ( V_56 ) {
case 60 :
V_59 |= V_68 ;
break;
case 80 :
V_59 |= V_69 ;
break;
case 0 :
V_59 |= V_70 ;
break;
case 40 :
default:
V_59 |= V_71 ;
break;
}
switch ( V_55 ) {
case 4 :
V_59 |= V_72 ;
break;
case 5 :
V_59 |= V_73 ;
break;
case 0 :
V_59 |= V_74 ;
break;
case 3 :
default:
V_59 |= V_75 ;
break;
}
return F_14 ( V_1 , V_76 , V_59 ) ;
}
static int F_15 ( struct V_77 * V_78 )
{
struct V_21 * V_22 ;
struct V_31 * V_32 ;
struct V_79 V_80 = {} ;
int V_3 ;
V_22 = F_16 ( & V_78 -> V_49 , sizeof( * V_22 ) , V_81 ) ;
if ( ! V_22 )
return - V_82 ;
V_22 -> V_1 = F_17 ( V_78 -> V_49 . V_83 , NULL ) ;
if ( ! V_22 -> V_1 ) {
F_8 ( & V_78 -> V_49 , L_7 ) ;
return - V_47 ;
}
V_3 = F_7 ( V_78 -> V_49 . V_83 , V_22 ) ;
if ( V_3 )
return V_3 ;
V_80 . V_52 = V_78 -> V_49 . V_83 -> V_52 ;
V_80 . V_84 = V_22 ;
V_32 = F_18 ( & V_78 -> V_49 ,
& V_85 ,
& V_80 ) ;
if ( F_19 ( V_32 ) ) {
F_8 ( & V_78 -> V_49 , L_8 ) ;
return F_20 ( V_32 ) ;
}
return 0 ;
}

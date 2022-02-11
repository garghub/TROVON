static int F_1 ( struct V_1 * V_2 ,
int * V_3 )
{
int V_4 , V_5 ;
V_4 = F_2 ( V_2 -> V_6 , V_7 , & V_5 ) ;
if ( V_4 )
return V_4 ;
switch ( V_5 & V_8 ) {
case V_9 :
* V_3 = 4100000 ;
break;
case V_10 :
* V_3 = 4150000 ;
break;
case V_11 :
* V_3 = 4200000 ;
break;
case V_12 :
* V_3 = 4360000 ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
int * V_3 )
{
int V_4 , V_5 ;
V_4 = F_2 ( V_2 -> V_6 , V_7 , & V_5 ) ;
if ( V_4 )
return V_4 ;
switch ( V_5 & V_8 ) {
case V_9 :
* V_3 = 4100000 ;
break;
case V_11 :
* V_3 = 4200000 ;
break;
case V_14 :
* V_3 = 4220000 ;
break;
case V_15 :
* V_3 = 4240000 ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static void F_4 ( struct V_1 * V_16 , int * V_3 )
{
if ( V_16 -> V_17 == V_18 )
* V_3 = * V_3 * 100000 + 300000 ;
else
* V_3 = * V_3 * 150000 + 300000 ;
}
static int F_5 ( struct V_1 * V_16 ,
int * V_3 )
{
int V_4 ;
V_4 = F_2 ( V_16 -> V_6 , V_7 , V_3 ) ;
if ( V_4 )
return V_4 ;
* V_3 &= V_19 ;
F_4 ( V_16 , V_3 ) ;
return 0 ;
}
static int F_6 ( struct V_20 * V_21 ,
enum V_22 V_23 ,
union V_24 * V_3 )
{
struct V_1 * V_2 = F_7 ( V_21 ) ;
struct V_25 * V_26 ;
int V_4 = 0 , V_5 , V_27 ;
switch ( V_23 ) {
case V_28 :
case V_29 :
V_4 = F_2 ( V_2 -> V_6 , V_30 ,
& V_5 ) ;
if ( V_4 )
return V_4 ;
V_3 -> V_31 = ! ! ( V_5 & V_32 ) ;
break;
case V_33 :
V_4 = F_2 ( V_2 -> V_6 , V_34 ,
& V_5 ) ;
if ( V_4 )
return V_4 ;
if ( V_5 & V_35 ) {
V_3 -> V_31 = V_36 ;
return 0 ;
}
V_4 = F_8 ( V_2 -> V_37 ,
& V_27 ) ;
if ( V_4 )
return V_4 ;
if ( V_27 ) {
V_3 -> V_31 = V_38 ;
return 0 ;
}
V_4 = F_2 ( V_2 -> V_6 , V_39 , & V_27 ) ;
if ( V_4 )
return V_4 ;
if ( ( V_27 & V_40 ) == 100 )
V_3 -> V_31 = V_41 ;
else
V_3 -> V_31 = V_42 ;
break;
case V_43 :
V_4 = F_2 ( V_2 -> V_6 , V_30 ,
& V_27 ) ;
if ( V_4 )
return V_4 ;
if ( V_27 & V_44 ) {
V_3 -> V_31 = V_45 ;
return 0 ;
}
V_3 -> V_31 = V_46 ;
break;
case V_47 :
V_4 = F_5 ( V_2 ,
& V_3 -> V_31 ) ;
if ( V_4 )
return V_4 ;
break;
case V_48 :
V_3 -> V_31 = V_19 ;
F_4 ( V_2 , & V_3 -> V_31 ) ;
break;
case V_49 :
V_4 = F_2 ( V_2 -> V_6 , V_34 ,
& V_5 ) ;
if ( V_4 )
return V_4 ;
if ( V_5 & V_35 )
V_26 = V_2 -> V_50 ;
else
V_26 = V_2 -> V_37 ;
V_4 = F_8 ( V_26 , & V_3 -> V_31 ) ;
if ( V_4 )
return V_4 ;
V_3 -> V_31 *= 1000 ;
break;
case V_51 :
V_4 = F_2 ( V_2 -> V_6 , V_30 ,
& V_5 ) ;
if ( V_4 )
return V_4 ;
if ( ! ( V_5 & V_32 ) ) {
V_3 -> V_31 = 100 ;
return 0 ;
}
V_4 = F_2 ( V_2 -> V_6 , V_39 , & V_5 ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_17 == V_52 &&
! ( V_5 & V_53 ) )
return - V_13 ;
V_3 -> V_31 = V_5 & V_40 ;
break;
case V_54 :
if ( V_2 -> V_17 == V_18 )
return F_1 ( V_2 ,
& V_3 -> V_31 ) ;
return F_3 ( V_2 ,
& V_3 -> V_31 ) ;
case V_55 :
V_4 = F_2 ( V_2 -> V_6 , V_56 , & V_5 ) ;
if ( V_4 )
return V_4 ;
V_3 -> V_31 = 2600000 + 100000 * ( V_5 & V_57 ) ;
break;
case V_58 :
V_4 = F_8 ( V_2 -> V_59 ,
& V_3 -> V_31 ) ;
if ( V_4 )
return V_4 ;
V_3 -> V_31 *= 1000 ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
int V_3 )
{
switch ( V_3 ) {
case 4100000 :
V_3 = V_9 ;
break;
case 4150000 :
if ( V_2 -> V_17 == V_52 )
return - V_13 ;
V_3 = V_10 ;
break;
case 4200000 :
V_3 = V_11 ;
break;
default:
return - V_13 ;
}
return F_10 ( V_2 -> V_6 , V_7 ,
V_8 , V_3 ) ;
}
static int F_11 ( struct V_1 * V_60 ,
int V_61 )
{
if ( V_60 -> V_17 == V_18 )
V_61 = ( V_61 - 300000 ) / 100000 ;
else
V_61 = ( V_61 - 300000 ) / 150000 ;
if ( V_61 > V_19 || V_61 < 0 )
return - V_13 ;
return F_10 ( V_60 -> V_6 , V_7 ,
V_19 , V_61 ) ;
}
static int F_12 ( struct V_1 * V_60 ,
int V_62 )
{
int V_27 = ( V_62 - 2600000 ) / 100000 ;
if ( V_27 < 0 || V_27 > V_57 )
return - V_13 ;
return F_10 ( V_60 -> V_6 , V_56 ,
V_57 , V_27 ) ;
}
static int F_13 ( struct V_20 * V_21 ,
enum V_22 V_23 ,
const union V_24 * V_3 )
{
struct V_1 * V_2 = F_7 ( V_21 ) ;
switch ( V_23 ) {
case V_55 :
return F_12 ( V_2 , V_3 -> V_31 ) ;
case V_54 :
return F_9 ( V_2 , V_3 -> V_31 ) ;
case V_47 :
return F_11 ( V_2 ,
V_3 -> V_31 ) ;
default:
return - V_13 ;
}
}
static int F_14 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
return V_23 == V_55 ||
V_23 == V_54 ||
V_23 == V_47 ;
}
static int F_15 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
struct V_65 V_66 = {} ;
if ( ! F_16 ( V_64 -> V_67 . V_68 ) )
return - V_69 ;
V_2 = F_17 ( & V_64 -> V_67 , sizeof( * V_2 ) ,
V_70 ) ;
if ( ! V_2 )
return - V_71 ;
V_2 -> V_67 = & V_64 -> V_67 ;
V_2 -> V_59 = F_18 ( & V_64 -> V_67 , L_1 ) ;
if ( F_19 ( V_2 -> V_59 ) ) {
if ( F_20 ( V_2 -> V_59 ) == - V_69 )
return - V_72 ;
return F_20 ( V_2 -> V_59 ) ;
}
V_2 -> V_50 = F_18 ( & V_64 -> V_67 ,
L_2 ) ;
if ( F_19 ( V_2 -> V_50 ) ) {
if ( F_20 ( V_2 -> V_50 ) == - V_69 )
return - V_72 ;
return F_20 ( V_2 -> V_50 ) ;
}
V_2 -> V_37 = F_18 ( & V_64 -> V_67 ,
L_3 ) ;
if ( F_19 ( V_2 -> V_37 ) ) {
if ( F_20 ( V_2 -> V_37 ) == - V_69 )
return - V_72 ;
return F_20 ( V_2 -> V_37 ) ;
}
V_2 -> V_6 = F_21 ( V_64 -> V_67 . V_73 , NULL ) ;
F_22 ( V_64 , V_2 ) ;
V_66 . V_74 = V_2 ;
V_66 . V_68 = V_64 -> V_67 . V_68 ;
V_2 -> V_17 = ( V_75 ) F_23 ( & V_64 -> V_67 ) ;
V_2 -> V_76 = F_24 ( & V_64 -> V_67 ,
& V_77 ,
& V_66 ) ;
if ( F_19 ( V_2 -> V_76 ) ) {
F_25 ( & V_64 -> V_67 , L_4 ,
F_20 ( V_2 -> V_76 ) ) ;
return F_20 ( V_2 -> V_76 ) ;
}
return 0 ;
}

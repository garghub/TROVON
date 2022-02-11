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
static void F_5 ( struct V_1 * V_16 , int * V_3 )
{
if ( V_16 -> V_17 == V_18 )
* V_3 = ( * V_3 - 300000 ) / 100000 ;
else
* V_3 = ( * V_3 - 300000 ) / 150000 ;
}
static int F_6 ( struct V_1 * V_16 ,
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
static int F_7 ( struct V_20 * V_21 ,
enum V_22 V_23 ,
union V_24 * V_3 )
{
struct V_1 * V_2 = F_8 ( V_21 ) ;
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
V_4 = F_9 ( V_2 -> V_37 ,
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
V_4 = F_6 ( V_2 ,
& V_3 -> V_31 ) ;
if ( V_4 )
return V_4 ;
break;
case V_48 :
V_3 -> V_31 = V_2 -> V_49 ;
break;
case V_50 :
V_4 = F_2 ( V_2 -> V_6 , V_34 ,
& V_5 ) ;
if ( V_4 )
return V_4 ;
if ( V_5 & V_35 )
V_26 = V_2 -> V_51 ;
else
V_26 = V_2 -> V_37 ;
V_4 = F_9 ( V_26 , & V_3 -> V_31 ) ;
if ( V_4 )
return V_4 ;
V_3 -> V_31 *= 1000 ;
break;
case V_52 :
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
if ( V_2 -> V_17 == V_53 &&
! ( V_5 & V_54 ) )
return - V_13 ;
V_3 -> V_31 = V_5 & V_40 ;
break;
case V_55 :
if ( V_2 -> V_17 == V_18 )
return F_1 ( V_2 ,
& V_3 -> V_31 ) ;
return F_3 ( V_2 ,
& V_3 -> V_31 ) ;
case V_56 :
V_4 = F_2 ( V_2 -> V_6 , V_57 , & V_5 ) ;
if ( V_4 )
return V_4 ;
V_3 -> V_31 = 2600000 + 100000 * ( V_5 & V_58 ) ;
break;
case V_59 :
V_4 = F_9 ( V_2 -> V_60 ,
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
static int F_10 ( struct V_1 * V_2 ,
int V_3 )
{
switch ( V_3 ) {
case 4100000 :
V_3 = V_9 ;
break;
case 4150000 :
if ( V_2 -> V_17 == V_53 )
return - V_13 ;
V_3 = V_10 ;
break;
case 4200000 :
V_3 = V_11 ;
break;
default:
return - V_13 ;
}
return F_11 ( V_2 -> V_6 , V_7 ,
V_8 , V_3 ) ;
}
static int F_12 ( struct V_1 * V_61 ,
int V_62 )
{
if ( V_62 > V_61 -> V_49 )
return - V_13 ;
F_5 ( V_61 , & V_62 ) ;
if ( V_62 > V_19 || V_62 < 0 )
return - V_13 ;
return F_11 ( V_61 -> V_6 , V_7 ,
V_19 , V_62 ) ;
}
static int F_13 ( struct V_1 * V_16 ,
int V_62 )
{
bool V_63 = false ;
F_5 ( V_16 , & V_62 ) ;
if ( V_62 > V_19 || V_62 < 0 )
return - V_13 ;
F_4 ( V_16 , & V_62 ) ;
if ( V_62 > V_16 -> V_49 )
F_14 ( V_16 -> V_64 ,
L_1 ) ;
else
V_63 = true ;
V_16 -> V_49 = V_62 ;
if ( V_63 ) {
int V_65 ;
F_6 ( V_16 , & V_65 ) ;
if ( V_65 > V_62 )
F_12 ( V_16 , V_62 ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_61 ,
int V_66 )
{
int V_27 = ( V_66 - 2600000 ) / 100000 ;
if ( V_27 < 0 || V_27 > V_58 )
return - V_13 ;
return F_11 ( V_61 -> V_6 , V_57 ,
V_58 , V_27 ) ;
}
static int F_16 ( struct V_20 * V_21 ,
enum V_22 V_23 ,
const union V_24 * V_3 )
{
struct V_1 * V_2 = F_8 ( V_21 ) ;
switch ( V_23 ) {
case V_56 :
return F_15 ( V_2 , V_3 -> V_31 ) ;
case V_55 :
return F_10 ( V_2 , V_3 -> V_31 ) ;
case V_47 :
return F_12 ( V_2 ,
V_3 -> V_31 ) ;
case V_48 :
return F_13 ( V_2 ,
V_3 -> V_31 ) ;
default:
return - V_13 ;
}
}
static int F_17 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
return V_23 == V_56 ||
V_23 == V_55 ||
V_23 == V_47 ||
V_23 == V_48 ;
}
static int F_18 ( struct V_67 * V_68 )
{
struct V_1 * V_2 ;
struct V_69 V_70 = {} ;
struct V_71 V_72 ;
if ( ! F_19 ( V_68 -> V_64 . V_73 ) )
return - V_74 ;
V_2 = F_20 ( & V_68 -> V_64 , sizeof( * V_2 ) ,
V_75 ) ;
if ( ! V_2 )
return - V_76 ;
V_2 -> V_64 = & V_68 -> V_64 ;
V_2 -> V_60 = F_21 ( & V_68 -> V_64 , L_2 ) ;
if ( F_22 ( V_2 -> V_60 ) ) {
if ( F_23 ( V_2 -> V_60 ) == - V_74 )
return - V_77 ;
return F_23 ( V_2 -> V_60 ) ;
}
V_2 -> V_51 = F_21 ( & V_68 -> V_64 ,
L_3 ) ;
if ( F_22 ( V_2 -> V_51 ) ) {
if ( F_23 ( V_2 -> V_51 ) == - V_74 )
return - V_77 ;
return F_23 ( V_2 -> V_51 ) ;
}
V_2 -> V_37 = F_21 ( & V_68 -> V_64 ,
L_4 ) ;
if ( F_22 ( V_2 -> V_37 ) ) {
if ( F_23 ( V_2 -> V_37 ) == - V_74 )
return - V_77 ;
return F_23 ( V_2 -> V_37 ) ;
}
V_2 -> V_6 = F_24 ( V_68 -> V_64 . V_78 , NULL ) ;
F_25 ( V_68 , V_2 ) ;
V_70 . V_79 = V_2 ;
V_70 . V_73 = V_68 -> V_64 . V_73 ;
V_2 -> V_17 = ( V_80 ) F_26 ( & V_68 -> V_64 ) ;
V_2 -> V_81 = F_27 ( & V_68 -> V_64 ,
& V_82 ,
& V_70 ) ;
if ( F_22 ( V_2 -> V_81 ) ) {
F_28 ( & V_68 -> V_64 , L_5 ,
F_23 ( V_2 -> V_81 ) ) ;
return F_23 ( V_2 -> V_81 ) ;
}
if ( ! F_29 ( V_2 -> V_81 , & V_72 ) ) {
int V_83 = V_72 . V_84 ;
int V_85 = V_72 . V_86 ;
if ( V_83 > 0 && F_15 ( V_2 ,
V_83 ) )
F_28 ( & V_68 -> V_64 ,
L_6 ) ;
V_2 -> V_49 = V_85 ;
if ( V_85 <= 0 || F_12 ( V_2 ,
V_85 ) ) {
F_28 ( & V_68 -> V_64 ,
L_7 ) ;
V_85 = 300000 ;
V_2 -> V_49 = V_85 ;
F_12 ( V_2 , V_85 ) ;
}
}
F_6 ( V_2 ,
& V_2 -> V_49 ) ;
return 0 ;
}

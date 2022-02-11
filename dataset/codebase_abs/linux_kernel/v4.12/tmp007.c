static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 ;
int V_5 = 50 ;
while ( V_5 -- > 0 ) {
V_4 = F_2 ( V_2 -> V_6 ,
V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ( V_4 & V_8 ) &&
! ( V_4 & V_9 ) )
break;
F_3 ( 100 ) ;
}
if ( V_5 < 0 )
return - V_10 ;
return F_2 ( V_2 -> V_6 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
return F_5 ( V_2 -> V_6 , V_11 ,
V_2 -> V_12 & ~ V_13 ) ;
}
static int F_6 ( struct V_14 * V_15 ,
struct V_16 const * V_17 , int * V_18 ,
int * V_19 , long V_20 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
T_2 V_4 ;
int V_21 ;
switch ( V_20 ) {
case V_22 :
switch ( V_17 -> V_23 ) {
case V_24 :
V_4 = F_2 ( V_2 -> V_6 , V_25 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_26 :
V_4 = F_1 ( V_2 , V_27 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
default:
return - V_28 ;
}
* V_18 = F_8 ( V_4 , 15 ) >> V_29 ;
return V_30 ;
case V_31 :
* V_18 = 31 ;
* V_19 = 250000 ;
return V_32 ;
case V_33 :
V_21 = ( V_2 -> V_12 & V_34 )
>> V_35 ;
* V_18 = V_36 [ V_21 ] [ 0 ] ;
* V_19 = V_36 [ V_21 ] [ 1 ] ;
return V_32 ;
default:
return - V_28 ;
}
}
static int F_9 ( struct V_14 * V_15 ,
struct V_16 const * V_17 , int V_18 ,
int V_19 , long V_20 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
int V_37 ;
T_3 V_38 ;
if ( V_20 == V_33 ) {
for ( V_37 = 0 ; V_37 < F_10 ( V_36 ) ; V_37 ++ ) {
if ( ( V_18 == V_36 [ V_37 ] [ 0 ] ) &&
( V_19 == V_36 [ V_37 ] [ 1 ] ) ) {
V_38 = V_2 -> V_12 & ~ V_34 ;
V_38 |= ( V_37 << V_35 ) ;
return F_5 ( V_2 -> V_6 ,
V_11 ,
V_2 -> V_12 = V_38 ) ;
}
}
}
return - V_28 ;
}
static T_4 F_11 ( int V_39 , void * V_40 )
{
struct V_14 * V_15 = V_40 ;
struct V_1 * V_2 = F_7 ( V_15 ) ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( ( V_4 < 0 ) || ! ( V_4 & ( V_41 | V_42 |
V_43 | V_44 ) ) )
return V_45 ;
if ( V_4 & V_41 )
F_12 ( V_15 ,
F_13 ( V_46 , 0 ,
V_26 ,
V_47 ,
V_48 ) ,
F_14 ( V_15 ) ) ;
if ( V_4 & V_42 )
F_12 ( V_15 ,
F_13 ( V_46 , 0 ,
V_26 ,
V_47 ,
V_49 ) ,
F_14 ( V_15 ) ) ;
if ( V_4 & V_43 )
F_12 ( V_15 ,
F_13 ( V_46 , 0 ,
V_24 ,
V_47 ,
V_48 ) ,
F_14 ( V_15 ) ) ;
if ( V_4 & V_44 )
F_12 ( V_15 ,
F_13 ( V_46 , 0 ,
V_24 ,
V_47 ,
V_49 ) ,
F_14 ( V_15 ) ) ;
return V_50 ;
}
static int F_15 ( struct V_14 * V_15 ,
const struct V_16 * V_51 , enum V_52 type ,
enum V_53 V_54 , int V_55 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
unsigned int V_56 ;
int V_4 ;
switch ( V_51 -> V_23 ) {
case V_24 :
if ( V_54 == V_48 )
V_56 = V_43 ;
else
V_56 = V_44 ;
break;
case V_26 :
if ( V_54 == V_48 )
V_56 = V_41 ;
else
V_56 = V_42 ;
break;
default:
return - V_28 ;
}
F_16 ( & V_2 -> V_57 ) ;
V_4 = F_2 ( V_2 -> V_6 , V_58 ) ;
F_17 ( & V_2 -> V_57 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_55 )
V_4 |= V_56 ;
else
V_4 &= ~ V_56 ;
return F_5 ( V_2 -> V_6 , V_58 ,
V_2 -> V_56 = V_4 ) ;
}
static int F_18 ( struct V_14 * V_15 ,
const struct V_16 * V_51 , enum V_52 type ,
enum V_53 V_54 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
unsigned int V_20 ;
switch ( V_51 -> V_23 ) {
case V_24 :
if ( V_54 == V_48 )
V_20 = V_43 ;
else
V_20 = V_44 ;
break;
case V_26 :
if ( V_54 == V_48 )
V_20 = V_41 ;
else
V_20 = V_42 ;
break;
default:
return - V_28 ;
}
return ! ! ( V_2 -> V_56 & V_20 ) ;
}
static int F_19 ( struct V_14 * V_15 ,
const struct V_16 * V_51 , enum V_52 type ,
enum V_53 V_54 , enum V_59 V_60 ,
int * V_18 , int * V_19 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
int V_4 ;
T_1 V_3 ;
switch ( V_51 -> V_23 ) {
case V_24 :
if ( V_54 == V_48 )
V_3 = V_61 ;
else
V_3 = V_62 ;
break;
case V_26 :
if ( V_54 == V_48 )
V_3 = V_63 ;
else
V_3 = V_64 ;
break;
default:
return - V_28 ;
}
V_4 = F_2 ( V_2 -> V_6 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_18 = F_8 ( V_4 , 15 ) >> 7 ;
return V_30 ;
}
static int F_20 ( struct V_14 * V_15 ,
const struct V_16 * V_51 , enum V_52 type ,
enum V_53 V_54 , enum V_59 V_60 ,
int V_18 , int V_19 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
T_1 V_3 ;
switch ( V_51 -> V_23 ) {
case V_24 :
if ( V_54 == V_48 )
V_3 = V_61 ;
else
V_3 = V_62 ;
break;
case V_26 :
if ( V_54 == V_48 )
V_3 = V_63 ;
else
V_3 = V_64 ;
break;
default:
return - V_28 ;
}
if ( V_18 < - 256 || V_18 > 255 )
return - V_28 ;
return F_5 ( V_2 -> V_6 , V_3 , ( V_18 << 7 ) ) ;
}
static bool F_21 ( struct V_65 * V_6 )
{
int V_66 , V_67 ;
V_66 = F_2 ( V_6 , V_68 ) ;
if ( V_66 < 0 )
return false ;
V_67 = F_2 ( V_6 , V_69 ) ;
if ( V_67 < 0 )
return false ;
return ( V_66 == V_70 && V_67 == V_71 ) ;
}
static int F_22 ( struct V_65 * V_6 ,
const struct V_72 * V_73 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_4 ;
if ( ! F_23 ( V_6 -> V_74 , V_75 ) )
return - V_76 ;
if ( ! F_21 ( V_6 ) ) {
F_24 ( & V_6 -> V_77 , L_1 ) ;
return - V_78 ;
}
V_15 = F_25 ( & V_6 -> V_77 , sizeof( * V_2 ) ) ;
if ( ! V_15 )
return - V_79 ;
V_2 = F_7 ( V_15 ) ;
F_26 ( V_6 , V_15 ) ;
V_2 -> V_6 = V_6 ;
F_27 ( & V_2 -> V_57 ) ;
V_15 -> V_77 . V_80 = & V_6 -> V_77 ;
V_15 -> V_81 = L_2 ;
V_15 -> V_82 = V_83 ;
V_15 -> V_60 = & V_84 ;
V_15 -> V_85 = V_86 ;
V_15 -> V_87 = F_10 ( V_86 ) ;
V_4 = F_2 ( V_2 -> V_6 , V_11 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_12 = V_4 ;
V_2 -> V_12 |= ( V_13 | V_88 | V_89 ) ;
V_4 = F_5 ( V_2 -> V_6 , V_11 ,
V_2 -> V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_2 ( V_2 -> V_6 , V_58 ) ;
if ( V_4 < 0 )
goto V_90;
V_2 -> V_56 = V_4 ;
V_2 -> V_56 |= ( V_41 | V_42
| V_43 | V_44 ) ;
V_4 = F_5 ( V_2 -> V_6 , V_58 , V_2 -> V_56 ) ;
if ( V_4 < 0 )
goto V_90;
if ( V_6 -> V_39 ) {
V_4 = F_28 ( & V_6 -> V_77 , V_6 -> V_39 ,
NULL , F_11 ,
V_91 | V_92 ,
V_73 -> V_81 , V_15 ) ;
if ( V_4 ) {
F_24 ( & V_6 -> V_77 , L_3 , - V_4 ) ;
goto V_90;
}
}
return F_29 ( V_15 ) ;
V_90:
F_4 ( V_2 ) ;
return V_4 ;
}
static int F_30 ( struct V_65 * V_6 )
{
struct V_14 * V_15 = F_31 ( V_6 ) ;
struct V_1 * V_2 = F_7 ( V_15 ) ;
F_32 ( V_15 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_33 ( struct V_93 * V_77 )
{
struct V_1 * V_2 = F_7 ( F_31 (
F_34 ( V_77 ) ) ) ;
return F_4 ( V_2 ) ;
}
static int F_35 ( struct V_93 * V_77 )
{
struct V_1 * V_2 = F_7 ( F_31 (
F_34 ( V_77 ) ) ) ;
return F_5 ( V_2 -> V_6 , V_11 ,
V_2 -> V_12 | V_13 ) ;
}

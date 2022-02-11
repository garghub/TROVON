static inline int
F_1 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_4 )
{
T_1 V_5 ;
int V_6 ;
V_6 = F_2 ( V_3 ,
& V_5 , V_2 -> V_7 + V_4 ) ;
return ( V_6 < 0 ) ? V_6 : V_5 ;
}
static inline int
F_3 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_4 ,
T_1 V_5 )
{
return F_4 ( V_3 ,
V_5 , V_2 -> V_7 + V_4 ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
return F_1 ( F_6 ( V_9 ) , V_10 ,
V_11 ) ;
}
static int F_7 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_12 = 0 , V_13 ;
if ( ! ( F_8 () && ( V_2 -> V_14 & V_15 ) ) ) {
V_12 = F_5 ( V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 &= V_16 ;
} else {
V_12 = 1 ;
}
V_13 = F_1 ( V_2 , V_10 , V_17 ) ;
V_13 = F_9 ( V_13 ) ;
return V_12 && ( V_13 == V_18 ) ;
}
static int F_10 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_12 = 0 ;
int V_19 ;
if ( ! ( F_8 () && ( V_2 -> V_14 & V_15 ) ) )
V_12 = F_5 ( V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
V_19 = F_3 ( V_2 , V_10 , V_17 ,
V_12 << V_20 |
V_18 ) ;
return V_19 ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_12 = 0 ;
int V_19 ;
if ( ! ( F_8 () && ( V_2 -> V_14 & V_15 ) ) )
V_12 = V_16 | V_21 | V_22 ;
V_19 = F_3 ( V_2 , V_10 , V_17 ,
( V_12 ) << V_20 |
V_23 ) ;
return V_19 ;
}
static int F_12 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_13 ;
V_13 = F_5 ( V_9 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_1 ( V_2 , V_10 , V_17 ) ;
switch ( F_9 ( V_13 ) ) {
case V_18 :
return V_24 ;
case V_25 :
return V_26 ;
case V_23 :
case V_27 :
default:
break;
}
return V_28 ;
}
static int F_13 ( struct V_8 * V_9 , unsigned V_29 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_12 = 0 ;
int V_13 ;
if ( ! ( F_8 () && ( V_2 -> V_14 & V_15 ) ) )
V_12 = F_5 ( V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
V_13 = V_12 << V_20 ;
switch ( V_29 ) {
case V_30 :
V_13 |= V_18 ;
break;
case V_31 :
V_13 |= V_25 ;
break;
default:
return - V_32 ;
}
return F_3 ( V_2 , V_10 , V_17 , V_13 ) ;
}
static int F_14 ( struct V_8 * V_9 , int V_33 ,
int V_34 , unsigned * V_35 )
{
return - V_36 ;
}
static int F_15 ( struct V_8 * V_9 )
{
return - V_36 ;
}
static int F_16 ( struct V_8 * V_9 , unsigned V_37 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
switch ( V_37 ) {
case 0 :
return 0 ;
case 1 ... 24 :
return ( V_2 -> V_38 + 100 * ( V_37 - 1 ) ) * 1000 ;
case 25 ... 30 :
return - V_32 ;
case 31 :
return 2750000 ;
default:
return - V_32 ;
}
}
static int
F_17 ( struct V_8 * V_9 , unsigned V_35 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return F_3 ( V_2 , V_10 , V_39 ,
V_35 ) ;
}
static int F_18 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_40 = F_1 ( V_2 , V_10 , V_39 ) ;
return V_40 ;
}
static int F_19 ( struct V_8 * V_9 , unsigned V_41 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_42 = 0 ;
switch ( V_2 -> V_43 ) {
case V_44 :
V_42 = 100000 ;
case 0 :
switch ( V_41 ) {
case 0 :
V_42 = 0 ;
break;
case 58 :
V_42 = 1350 * 1000 ;
break;
case 59 :
V_42 = 1500 * 1000 ;
break;
case 60 :
V_42 = 1800 * 1000 ;
break;
case 61 :
V_42 = 1900 * 1000 ;
break;
case 62 :
V_42 = 2100 * 1000 ;
break;
default:
V_42 += ( 600000 + ( 12500 * ( V_41 - 1 ) ) ) ;
}
break;
case V_45 :
switch ( V_41 ) {
case 0 :
V_42 = 0 ;
break;
case 58 :
V_42 = 2084 * 1000 ;
break;
case 59 :
V_42 = 2315 * 1000 ;
break;
case 60 :
V_42 = 2778 * 1000 ;
break;
case 61 :
V_42 = 2932 * 1000 ;
break;
case 62 :
V_42 = 3241 * 1000 ;
break;
default:
V_42 = ( 1852000 + ( 38600 * ( V_41 - 1 ) ) ) ;
}
break;
case V_44 | V_45 :
switch ( V_41 ) {
case 0 :
V_42 = 0 ;
break;
case 58 :
V_42 = 4167 * 1000 ;
break;
case 59 :
V_42 = 2315 * 1000 ;
break;
case 60 :
V_42 = 2778 * 1000 ;
break;
case 61 :
V_42 = 2932 * 1000 ;
break;
case 62 :
V_42 = 3241 * 1000 ;
break;
default:
V_42 = ( 2161000 + ( 38600 * ( V_41 - 1 ) ) ) ;
}
break;
}
return V_42 ;
}
static int F_20 ( struct V_8 * V_9 , int V_33 ,
int V_34 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_40 = 0 ;
switch ( V_2 -> V_43 ) {
case 0 :
if ( V_33 == 0 )
V_40 = 0 ;
else if ( ( V_33 >= 600000 ) && ( V_33 <= 1300000 ) ) {
V_40 = F_21 ( V_33 - 600000 , 12500 ) ;
V_40 ++ ;
}
else if ( ( V_33 > 1900000 ) && ( V_33 <= 2100000 ) )
V_40 = 62 ;
else if ( ( V_33 > 1800000 ) && ( V_33 <= 1900000 ) )
V_40 = 61 ;
else if ( ( V_33 > 1500000 ) && ( V_33 <= 1800000 ) )
V_40 = 60 ;
else if ( ( V_33 > 1350000 ) && ( V_33 <= 1500000 ) )
V_40 = 59 ;
else if ( ( V_33 > 1300000 ) && ( V_33 <= 1350000 ) )
V_40 = 58 ;
else
return - V_32 ;
break;
case V_44 :
if ( V_33 == 0 )
V_40 = 0 ;
else if ( ( V_33 >= 700000 ) && ( V_33 <= 1420000 ) ) {
V_40 = F_21 ( V_33 - 700000 , 12500 ) ;
V_40 ++ ;
}
else if ( ( V_33 > 1900000 ) && ( V_33 <= 2100000 ) )
V_40 = 62 ;
else if ( ( V_33 > 1800000 ) && ( V_33 <= 1900000 ) )
V_40 = 61 ;
else if ( ( V_33 > 1500000 ) && ( V_33 <= 1800000 ) )
V_40 = 60 ;
else if ( ( V_33 > 1350000 ) && ( V_33 <= 1500000 ) )
V_40 = 59 ;
else
return - V_32 ;
break;
case V_45 :
if ( V_33 == 0 ) {
V_40 = 0 ;
} else if ( ( V_33 >= 1852000 ) && ( V_34 <= 4013600 ) ) {
V_40 = F_21 ( V_33 - 1852000 , 38600 ) ;
V_40 ++ ;
}
break;
case V_44 | V_45 :
if ( V_33 == 0 ) {
V_40 = 0 ;
} else if ( ( V_33 >= 2161000 ) && ( V_33 <= 4321000 ) ) {
V_40 = F_21 ( V_33 - 2161000 , 38600 ) ;
V_40 ++ ;
}
break;
}
return V_40 ;
}
static int F_22 ( struct V_8 * V_9 ,
unsigned int V_35 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return F_3 ( V_2 , V_10 , V_46 ,
V_35 ) ;
}
static int F_23 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return F_1 ( V_2 , V_10 , V_46 ) ;
}
static T_1 F_24 ( void )
{
T_1 V_5 ;
F_2 ( V_10 , & V_5 ,
V_47 ) ;
return V_5 ;
}
static T_1 F_25 ( void )
{
T_1 V_5 ;
F_2 ( V_10 , & V_5 ,
V_48 ) ;
return V_5 ;
}
static int F_26 ( struct V_49 * V_50 )
{
int V_51 ;
struct V_1 * V_2 ;
const struct V_1 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_8 * V_9 ;
const struct V_57 * V_58 ;
struct V_59 V_60 = { } ;
V_58 = F_27 ( V_61 , & V_50 -> V_62 ) ;
if ( ! V_58 )
return - V_36 ;
V_52 = V_58 -> V_63 ;
if ( ! V_52 )
return - V_36 ;
V_51 = V_52 -> V_64 . V_51 ;
V_54 = F_28 ( & V_50 -> V_62 , V_50 -> V_62 . V_65 ,
& V_52 -> V_64 ) ;
if ( ! V_54 )
return - V_32 ;
V_2 = F_29 ( & V_50 -> V_62 , V_52 , sizeof( * V_2 ) , V_66 ) ;
if ( ! V_2 )
return - V_67 ;
V_56 = & V_54 -> V_68 ;
V_56 -> V_69 &= V_30 | V_31 ;
V_56 -> V_70 &= V_71
| V_72
| V_73 ;
switch ( V_51 ) {
case V_74 :
if ( F_25 () & V_75 )
V_2 -> V_43 |= V_45 ;
if ( F_24 () & V_75 )
V_2 -> V_43 |= V_44 ;
break;
case V_76 :
if ( F_25 () & V_77 )
V_2 -> V_43 |= V_45 ;
if ( F_24 () & V_77 )
V_2 -> V_43 |= V_44 ;
break;
case V_78 :
if ( F_25 () & V_79 )
V_2 -> V_43 |= V_45 ;
if ( F_24 () & V_79 )
V_2 -> V_43 |= V_44 ;
break;
}
V_60 . V_62 = & V_50 -> V_62 ;
V_60 . V_80 = V_54 ;
V_60 . V_81 = V_2 ;
V_60 . V_65 = V_50 -> V_62 . V_65 ;
V_9 = F_30 ( & V_50 -> V_62 , & V_2 -> V_64 , & V_60 ) ;
if ( F_31 ( V_9 ) ) {
F_32 ( & V_50 -> V_62 , L_1 ,
V_2 -> V_64 . V_82 , F_33 ( V_9 ) ) ;
return F_33 ( V_9 ) ;
}
F_34 ( V_50 , V_9 ) ;
return 0 ;
}
static int T_2 F_35 ( void )
{
return F_36 ( & V_83 ) ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_83 ) ;
}

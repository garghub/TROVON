static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return F_2 ( V_2 , F_3 ( V_4 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_8 ;
void T_1 * V_9 , * V_10 ;
if ( V_2 -> V_11 == V_12 ) {
V_9 = V_7 -> V_13 + V_14 ;
V_10 = V_7 -> V_13 + V_15 ;
} else {
V_9 = V_7 -> V_13 + V_16 ;
V_10 = V_7 -> V_13 + V_17 ;
}
F_5 ( V_9 , V_6 -> V_18 ) ;
F_5 ( V_10 , V_6 -> V_19 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_8 ;
unsigned long V_20 ;
V_20 = F_7 ( V_7 -> V_13 + V_21 ) ;
V_20 |= ( V_22 | V_23 ) ;
F_5 ( V_7 -> V_13 + V_21 , V_20 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_8 ;
unsigned long V_20 ;
V_20 = F_7 ( V_7 -> V_13 + V_21 ) ;
V_20 &= ~ ( V_22 | V_23 ) ;
F_5 ( V_7 -> V_13 + V_21 , V_20 ) ;
}
static T_2 F_9 ( int V_24 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
struct V_7 * V_7 = V_2 -> V_6 -> V_8 ;
unsigned long V_20 ;
F_10 ( & V_7 -> V_26 ) ;
V_20 = F_7 ( V_7 -> V_13 + V_21 ) ;
if ( V_20 & V_23 ) {
F_5 ( V_7 -> V_13 + V_21 , V_20 | V_23 ) ;
V_20 = F_7 ( V_7 -> V_13 + V_27 ) ;
if ( V_20 & V_28 ) {
V_20 |= V_28 ;
F_5 ( V_7 -> V_13 + V_27 , V_20 ) ;
}
if ( V_20 & V_29 ) {
V_20 |= V_29 ;
F_5 ( V_7 -> V_13 + V_27 , V_20 ) ;
}
} else if ( V_20 & V_22 ) {
F_5 ( V_7 -> V_13 + V_21 , V_20 | V_22 ) ;
V_20 = F_7 ( V_7 -> V_13 + V_30 ) ;
if ( V_20 & V_31 ) {
V_20 |= V_31 ;
F_5 ( V_7 -> V_13 + V_30 , V_20 ) ;
}
if ( V_20 & V_32 ) {
V_20 |= V_32 ;
F_5 ( V_7 -> V_13 + V_30 , V_20 ) ;
}
} else {
F_11 ( V_7 -> V_33 , L_1 ) ;
F_12 ( & V_7 -> V_26 ) ;
return V_34 ;
}
F_12 ( & V_7 -> V_26 ) ;
F_13 ( V_2 ) ;
return V_34 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_8 ;
unsigned long V_35 , V_20 ;
int V_36 = 0 ;
F_17 ( & V_7 -> V_26 , V_35 ) ;
F_4 ( V_2 ) ;
V_20 = F_7 ( V_7 -> V_13 + V_37 ) ;
switch ( V_6 -> V_38 ) {
case 1 :
if ( V_2 -> V_11 == V_12 ) {
V_20 &= ~ ( V_39 | V_40 ) ;
V_20 |= V_40 ;
} else {
V_20 &= ~ ( V_41 | V_42 ) ;
V_20 |= V_42 ;
}
F_5 ( V_7 -> V_13 + V_37 , V_20 ) ;
break;
case 2 :
if ( V_2 -> V_11 == V_12 )
V_20 |= ( V_39 | V_40 ) ;
else
V_20 |= ( V_41 | V_42 ) ;
F_5 ( V_7 -> V_13 + V_37 , V_20 ) ;
break;
default:
V_36 = - V_43 ;
}
F_18 ( & V_7 -> V_26 , V_35 ) ;
return V_36 ;
}
static int F_19 ( struct V_1 * V_2 , int V_44 )
{
int V_36 = 0 ;
switch ( V_44 ) {
case V_45 :
case V_46 :
F_6 ( V_2 ) ;
break;
case V_47 :
case V_48 :
F_8 ( V_2 ) ;
break;
default:
V_36 = - V_43 ;
break;
}
return V_36 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_3 * V_49 , T_3 * V_50 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_8 ;
if ( V_49 != NULL )
* V_49 = F_7 ( V_7 -> V_13 + V_51 ) ;
if ( V_50 != NULL )
* V_50 = F_7 ( V_7 -> V_13 + V_52 ) ;
return 0 ;
}
static T_4 F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_3 V_49 , V_50 ;
unsigned long V_53 ;
F_20 ( V_2 , & V_49 , & V_50 ) ;
if ( V_2 -> V_11 == V_54 )
V_53 = V_50 - V_6 -> V_18 ;
else
V_53 = V_49 - V_6 -> V_18 ;
return F_22 ( V_2 -> V_6 , V_53 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 ;
F_24 ( V_2 , & V_55 ) ;
V_7 = V_56 ;
if ( F_25 ( V_7 -> V_57 , F_9 ,
0 , L_2 , V_2 ) )
return - V_58 ;
V_6 -> V_8 = V_7 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_8 ;
F_27 ( V_7 -> V_57 , V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
return F_29 ( V_2 -> V_61 -> V_62 -> V_33 , V_60 , V_6 -> V_63 ,
V_6 -> V_18 , V_6 -> V_19 ) ;
}
static int F_30 ( struct V_64 * V_65 )
{
struct V_66 * V_62 = V_65 -> V_62 -> V_66 ;
struct V_67 * V_61 = V_65 -> V_61 ;
int V_36 ;
V_36 = F_31 ( V_62 -> V_33 , F_32 ( 32 ) ) ;
if ( V_36 )
return V_36 ;
F_33 ( V_61 , V_68 ,
V_62 -> V_33 , 4 * 1024 , ( 4 * 1024 ) - 1 ) ;
return 0 ;
}
static int F_34 ( struct V_69 * V_70 )
{
return F_35 ( & V_70 -> V_33 , & V_71 ) ;
}

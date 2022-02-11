static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_8 ;
unsigned long V_9 ;
int V_10 = 0 ;
V_10 = F_2 ( V_2 , F_3 ( V_4 ) ) ;
if ( V_10 < 0 )
return V_10 ;
F_4 ( & V_7 -> V_11 , V_9 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_12 [ V_2 -> V_13 ] = V_6 -> V_12 ;
V_7 -> V_14 [ V_2 -> V_13 ] =
F_3 ( V_4 ) ;
F_5 ( & V_7 -> V_11 , V_9 ) ;
return V_10 ;
}
static void F_6 ( struct V_1 * V_2 ,
T_1 V_12 , T_2 V_15 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_8 ;
void T_3 * V_16 , * V_17 ;
if ( V_2 -> V_13 == V_18 ) {
V_16 = V_7 -> V_19 + V_20 ;
V_17 = V_7 -> V_19 + V_21 ;
} else {
V_16 = V_7 -> V_19 + V_22 ;
V_17 = V_7 -> V_19 + V_23 ;
}
F_7 ( V_16 , V_12 ) ;
F_7 ( V_17 , V_15 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_8 ;
unsigned long V_24 ;
V_24 = F_9 ( V_7 -> V_19 + V_25 ) ;
V_24 |= ( V_26 | V_27 ) ;
F_7 ( V_7 -> V_19 + V_25 , V_24 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_8 ;
unsigned long V_24 ;
V_24 = F_9 ( V_7 -> V_19 + V_25 ) ;
V_24 &= ~ ( V_26 | V_27 ) ;
F_7 ( V_7 -> V_19 + V_25 , V_24 ) ;
}
static T_4 F_11 ( int V_28 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
struct V_7 * V_7 = V_2 -> V_6 -> V_8 ;
unsigned long V_24 ;
F_12 ( & V_7 -> V_11 ) ;
V_24 = F_9 ( V_7 -> V_19 + V_25 ) ;
if ( V_24 & V_27 ) {
F_7 ( V_7 -> V_19 + V_25 , V_24 | V_27 ) ;
V_24 = F_9 ( V_7 -> V_19 + V_30 ) ;
if ( V_24 & V_31 ) {
V_24 |= V_31 ;
F_7 ( V_7 -> V_19 + V_30 , V_24 ) ;
}
if ( V_24 & V_32 ) {
V_24 |= V_32 ;
F_7 ( V_7 -> V_19 + V_30 , V_24 ) ;
}
} else if ( V_24 & V_26 ) {
F_7 ( V_7 -> V_19 + V_25 , V_24 | V_26 ) ;
V_24 = F_9 ( V_7 -> V_19 + V_33 ) ;
if ( V_24 & V_34 ) {
V_24 |= V_34 ;
F_7 ( V_7 -> V_19 + V_33 , V_24 ) ;
}
if ( V_24 & V_35 ) {
V_24 |= V_35 ;
F_7 ( V_7 -> V_19 + V_33 , V_24 ) ;
}
} else {
F_13 ( V_7 -> V_36 , L_1 ) ;
F_14 ( & V_7 -> V_11 ) ;
return V_37 ;
}
F_14 ( & V_7 -> V_11 ) ;
F_15 ( V_2 ) ;
return V_37 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_8 ;
unsigned long V_9 , V_24 ;
int V_10 = 0 ;
F_4 ( & V_7 -> V_11 , V_9 ) ;
F_6 ( V_2 ,
V_7 -> V_12 [ V_2 -> V_13 ] ,
V_7 -> V_14 [ V_2 -> V_13 ] ) ;
V_24 = F_9 ( V_7 -> V_19 + V_38 ) ;
switch ( V_6 -> V_39 ) {
case 1 :
if ( V_2 -> V_13 == V_18 ) {
V_24 &= ~ ( V_40 | V_41 ) ;
V_24 |= V_41 ;
} else {
V_24 &= ~ ( V_42 | V_43 ) ;
V_24 |= V_43 ;
}
F_7 ( V_7 -> V_19 + V_38 , V_24 ) ;
break;
case 2 :
if ( V_2 -> V_13 == V_18 )
V_24 |= ( V_40 | V_41 ) ;
else
V_24 |= ( V_42 | V_43 ) ;
F_7 ( V_7 -> V_19 + V_38 , V_24 ) ;
break;
default:
V_10 = - V_44 ;
}
F_5 ( & V_7 -> V_11 , V_9 ) ;
return V_10 ;
}
static int F_19 ( struct V_1 * V_2 , int V_45 )
{
int V_10 = 0 ;
switch ( V_45 ) {
case V_46 :
case V_47 :
F_8 ( V_2 ) ;
break;
case V_48 :
case V_49 :
F_10 ( V_2 ) ;
break;
default:
V_10 = - V_44 ;
break;
}
return V_10 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_1 * V_50 , T_1 * V_51 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_8 ;
if ( V_50 != NULL )
* V_50 = F_9 ( V_7 -> V_19 + V_52 ) ;
if ( V_51 != NULL )
* V_51 = F_9 ( V_7 -> V_19 + V_53 ) ;
return 0 ;
}
static T_5 F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_50 , V_51 ;
unsigned long V_54 ;
F_20 ( V_2 , & V_50 , & V_51 ) ;
if ( V_2 -> V_13 == V_55 )
V_54 = V_51 - V_6 -> V_12 ;
else
V_54 = V_50 - V_6 -> V_12 ;
return F_22 ( V_2 -> V_6 , V_54 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 ;
F_24 ( V_2 , & V_56 ) ;
V_7 = V_57 ;
if ( F_25 ( V_7 -> V_58 , F_11 ,
0 , L_2 , V_2 ) )
return - V_59 ;
V_6 -> V_8 = V_7 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_8 ;
F_27 ( V_7 -> V_58 , V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
return F_29 ( V_2 -> V_62 -> V_63 -> V_36 , V_61 ,
V_6 -> V_64 ,
V_6 -> V_12 ,
V_6 -> V_65 ) ;
}
static int F_30 ( struct V_66 * V_67 )
{
struct V_68 * V_63 = V_67 -> V_63 -> V_68 ;
struct V_69 * V_62 = V_67 -> V_62 ;
int V_10 ;
V_10 = F_31 ( V_63 -> V_36 , F_32 ( 32 ) ) ;
if ( V_10 )
return V_10 ;
F_33 ( V_62 , V_70 ,
V_63 -> V_36 , 4 * 1024 , ( 4 * 1024 ) - 1 ) ;
return 0 ;
}
static int F_34 ( struct V_71 * V_72 )
{
return F_35 ( & V_72 -> V_36 , & V_73 ) ;
}
static int F_36 ( struct V_71 * V_72 )
{
F_37 ( & V_72 -> V_36 ) ;
return 0 ;
}

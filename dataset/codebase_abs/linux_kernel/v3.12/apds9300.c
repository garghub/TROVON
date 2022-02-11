static unsigned long F_1 ( T_1 V_1 , T_1 V_2 )
{
unsigned long V_3 , V_4 ;
if ( V_1 == 0 )
return 0 ;
V_4 = F_2 ( V_2 * 100 , V_1 ) ;
if ( V_4 <= 52 ) {
V_3 = 3150 * V_1 - ( unsigned long ) F_3 ( V_1
* V_5 [ V_4 ] * 5930ull , 1000 ) ;
} else if ( V_4 <= 65 ) {
V_3 = 2290 * V_1 - 2910 * V_2 ;
} else if ( V_4 <= 80 ) {
V_3 = 1570 * V_1 - 1800 * V_2 ;
} else if ( V_4 <= 130 ) {
V_3 = 338 * V_1 - 260 * V_2 ;
} else {
V_3 = 0 ;
}
return V_3 / 100000 ;
}
static int F_4 ( struct V_6 * V_7 , int V_8 )
{
int V_9 ;
T_2 V_10 = V_11 | V_12 ;
if ( ! V_7 -> V_13 )
return - V_14 ;
V_10 |= V_8 ? V_15 : V_16 ;
V_9 = F_5 ( V_7 -> V_17 , V_10 ) ;
if ( V_9 < 0 )
F_6 ( & V_7 -> V_17 -> V_18 ,
L_1 , V_8 ) ;
return V_9 ;
}
static int F_7 ( struct V_6 * V_7 , int V_19 )
{
int V_9 ;
if ( ! V_7 -> V_13 )
return - V_14 ;
if ( V_19 > V_20 )
return - V_21 ;
V_9 = F_8 ( V_7 -> V_17 , V_22
| V_11 | V_12 , V_19 ) ;
if ( V_9 ) {
F_6 ( & V_7 -> V_17 -> V_18 , L_2 ) ;
return V_9 ;
}
V_7 -> V_23 = V_19 ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 , int V_19 )
{
int V_9 ;
if ( ! V_7 -> V_13 )
return - V_14 ;
if ( V_19 > V_20 )
return - V_21 ;
V_9 = F_8 ( V_7 -> V_17 , V_24
| V_11 | V_12 , V_19 ) ;
if ( V_9 ) {
F_6 ( & V_7 -> V_17 -> V_18 , L_3 ) ;
return V_9 ;
}
V_7 -> V_25 = V_19 ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 , int V_26 )
{
int V_9 ;
T_2 V_27 ;
if ( ! V_7 -> V_13 )
return - V_14 ;
V_27 = V_26 ? V_28 | V_29 : 0x00 ;
V_9 = F_11 ( V_7 -> V_17 ,
V_30 | V_11 , V_27 ) ;
if ( V_9 ) {
F_6 ( & V_7 -> V_17 -> V_18 ,
L_4 , V_26 ) ;
return V_9 ;
}
V_7 -> V_31 = V_26 ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 , int V_26 )
{
int V_9 ;
T_2 V_27 ;
V_27 = V_26 ? V_32 : V_33 ;
V_9 = F_11 ( V_7 -> V_17 ,
V_34 | V_11 , V_27 ) ;
if ( V_9 ) {
F_6 ( & V_7 -> V_17 -> V_18 ,
L_5 , V_26 ) ;
return V_9 ;
}
V_7 -> V_13 = V_26 ;
return 0 ;
}
static void F_13 ( struct V_6 * V_7 )
{
int V_9 ;
V_9 = F_14 ( V_7 -> V_17 , V_35 | V_11 ) ;
if ( V_9 < 0 )
F_6 ( & V_7 -> V_17 -> V_18 , L_6 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
int V_9 ;
V_9 = F_12 ( V_7 , 0 ) ;
if ( V_9 < 0 )
goto V_36;
V_9 = F_12 ( V_7 , 1 ) ;
if ( V_9 < 0 )
goto V_36;
V_9 = F_16 ( V_7 -> V_17 ,
V_34 | V_11 ) ;
if ( V_9 != V_32 ) {
V_9 = - V_37 ;
goto V_36;
}
V_9 = F_10 ( V_7 , 0 ) ;
if ( V_9 < 0 )
goto V_36;
return 0 ;
V_36:
F_6 ( & V_7 -> V_17 -> V_18 , L_7 ) ;
return V_9 ;
}
static int F_17 ( struct V_38 * V_39 ,
struct V_40 const * V_41 , int * V_42 , int * V_43 ,
long V_44 )
{
int V_1 , V_2 , V_9 = - V_21 ;
struct V_6 * V_7 = F_18 ( V_39 ) ;
F_19 ( & V_7 -> V_45 ) ;
switch ( V_41 -> type ) {
case V_46 :
V_1 = F_4 ( V_7 , 0 ) ;
if ( V_1 < 0 ) {
V_9 = V_1 ;
break;
}
V_2 = F_4 ( V_7 , 1 ) ;
if ( V_2 < 0 ) {
V_9 = V_2 ;
break;
}
* V_42 = F_1 ( V_1 , V_2 ) ;
V_9 = V_47 ;
break;
case V_48 :
V_9 = F_4 ( V_7 , V_41 -> V_49 ) ;
if ( V_9 < 0 )
break;
* V_42 = V_9 ;
V_9 = V_47 ;
break;
default:
break;
}
F_20 ( & V_7 -> V_45 ) ;
return V_9 ;
}
static int F_21 ( struct V_38 * V_39 , T_3 V_50 ,
int * V_42 )
{
struct V_6 * V_7 = F_18 ( V_39 ) ;
switch ( F_22 ( V_50 ) ) {
case V_51 :
* V_42 = V_7 -> V_25 ;
break;
case V_52 :
* V_42 = V_7 -> V_23 ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_23 ( struct V_38 * V_39 , T_3 V_50 ,
int V_42 )
{
struct V_6 * V_7 = F_18 ( V_39 ) ;
int V_9 ;
F_19 ( & V_7 -> V_45 ) ;
if ( F_22 ( V_50 ) == V_51 )
V_9 = F_9 ( V_7 , V_42 ) ;
else
V_9 = F_7 ( V_7 , V_42 ) ;
F_20 ( & V_7 -> V_45 ) ;
return V_9 ;
}
static int F_24 ( struct V_38 * V_39 ,
T_3 V_50 )
{
struct V_6 * V_7 = F_18 ( V_39 ) ;
return V_7 -> V_31 ;
}
static int F_25 ( struct V_38 * V_39 ,
T_3 V_50 , int V_26 )
{
struct V_6 * V_7 = F_18 ( V_39 ) ;
int V_9 ;
F_19 ( & V_7 -> V_45 ) ;
V_9 = F_10 ( V_7 , V_26 ) ;
F_20 ( & V_7 -> V_45 ) ;
return V_9 ;
}
static T_4 F_26 ( int V_53 , void * V_54 )
{
struct V_38 * V_55 = V_54 ;
struct V_6 * V_7 = F_18 ( V_55 ) ;
F_27 ( V_55 ,
F_28 ( V_48 , 0 ,
V_56 ,
V_57 ) ,
F_29 () ) ;
F_13 ( V_7 ) ;
return V_58 ;
}
static int F_30 ( struct V_59 * V_17 ,
const struct V_60 * V_61 )
{
struct V_6 * V_7 ;
struct V_38 * V_39 ;
int V_9 ;
V_39 = F_31 ( & V_17 -> V_18 , sizeof( * V_7 ) ) ;
if ( ! V_39 )
return - V_62 ;
V_7 = F_18 ( V_39 ) ;
F_32 ( V_17 , V_39 ) ;
V_7 -> V_17 = V_17 ;
V_9 = F_15 ( V_7 ) ;
if ( V_9 < 0 )
goto V_36;
F_33 ( & V_7 -> V_45 ) ;
V_39 -> V_18 . V_63 = & V_17 -> V_18 ;
V_39 -> V_64 = V_65 ;
V_39 -> V_66 = F_34 ( V_65 ) ;
V_39 -> V_67 = V_68 ;
V_39 -> V_69 = V_70 ;
if ( V_17 -> V_53 )
V_39 -> V_71 = & V_72 ;
else
V_39 -> V_71 = & V_73 ;
if ( V_17 -> V_53 ) {
V_9 = F_35 ( & V_17 -> V_18 , V_17 -> V_53 ,
NULL , F_26 ,
V_74 | V_75 ,
V_76 , V_39 ) ;
if ( V_9 ) {
F_6 ( & V_17 -> V_18 , L_8 , - V_9 ) ;
goto V_36;
}
}
V_9 = F_36 ( V_39 ) ;
if ( V_9 < 0 )
goto V_36;
return 0 ;
V_36:
F_12 ( V_7 , 0 ) ;
return V_9 ;
}
static int F_37 ( struct V_59 * V_17 )
{
struct V_38 * V_39 = F_38 ( V_17 ) ;
struct V_6 * V_7 = F_18 ( V_39 ) ;
F_39 ( V_39 ) ;
F_10 ( V_7 , 0 ) ;
F_12 ( V_7 , 0 ) ;
return 0 ;
}
static int F_40 ( struct V_77 * V_18 )
{
struct V_38 * V_39 = F_38 ( F_41 ( V_18 ) ) ;
struct V_6 * V_7 = F_18 ( V_39 ) ;
int V_9 ;
F_19 ( & V_7 -> V_45 ) ;
V_9 = F_12 ( V_7 , 0 ) ;
F_20 ( & V_7 -> V_45 ) ;
return V_9 ;
}
static int F_42 ( struct V_77 * V_18 )
{
struct V_38 * V_39 = F_38 ( F_41 ( V_18 ) ) ;
struct V_6 * V_7 = F_18 ( V_39 ) ;
int V_9 ;
F_19 ( & V_7 -> V_45 ) ;
V_9 = F_12 ( V_7 , 1 ) ;
F_20 ( & V_7 -> V_45 ) ;
return V_9 ;
}

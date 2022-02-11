void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
bool V_5 , V_6 ;
F_2 () ;
V_4 = F_3 ( V_2 -> V_4 ) ;
V_5 = V_4 && F_4 ( V_4 ) ;
if ( V_5 ) {
unsigned int V_7 = F_5 ( V_2 -> V_7 ) ;
unsigned int V_8 = V_2 -> V_9 ( V_2 , V_4 -> V_10 ,
V_7 , & V_6 ) ;
F_6 ( & V_2 -> V_7 , V_7 , V_8 ) ;
if ( V_6 )
F_7 ( V_4 ) ;
}
F_8 () ;
}
static int F_9 ( struct V_3 * V_11 )
{
struct V_12 * V_10 = V_11 -> V_10 ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_1 * V_2 = F_10 ( V_14 -> V_16 ) ;
F_11 ( V_11 , & V_17 ) ;
F_12 ( V_10 , V_18 ) ;
V_10 -> V_15 = V_2 ;
return 0 ;
}
static int F_13 ( struct V_3 * V_11 )
{
F_14 () ;
return 0 ;
}
static int F_15 ( struct V_3 * V_11 ,
struct V_19 * V_20 )
{
struct V_12 * V_10 = V_11 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_15 ;
int V_21 ;
switch ( F_16 ( V_20 ) ) {
case 2 :
break;
default:
F_17 ( V_2 -> V_2 , L_1 ) ;
return - V_22 ;
}
switch ( F_18 ( V_20 ) ) {
case V_23 :
V_2 -> V_9 = V_24 ;
break;
case V_25 :
V_2 -> V_9 = V_26 ;
break;
default:
F_17 ( V_2 -> V_2 , L_2 ) ;
return - V_22 ;
}
if ( V_11 -> V_27 != V_28 ) {
F_17 ( V_2 -> V_2 , L_3 ) ;
return - V_22 ;
}
V_21 = F_19 ( V_11 ,
F_20 ( V_20 ) ) ;
if ( V_21 < 0 )
return V_21 ;
else
return 0 ;
}
static int F_21 ( struct V_3 * V_11 )
{
return F_22 ( V_11 ) ;
}
static int F_23 ( struct V_3 * V_11 , int V_29 )
{
struct V_12 * V_10 = V_11 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_15 ;
int V_21 = 0 ;
switch ( V_29 ) {
case V_30 :
case V_31 :
case V_32 :
F_24 ( V_2 -> V_7 , 0 ) ;
F_25 ( V_2 -> V_4 , V_11 ) ;
break;
case V_33 :
case V_34 :
case V_35 :
F_25 ( V_2 -> V_4 , NULL ) ;
break;
default:
V_21 = - V_22 ;
break;
}
return V_21 ;
}
static T_1 F_26 ( struct V_3 * V_11 )
{
struct V_12 * V_10 = V_11 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_15 ;
T_1 V_36 = F_5 ( V_2 -> V_7 ) ;
return V_36 < V_10 -> V_37 ? V_36 : 0 ;
}
static int F_27 ( struct V_13 * V_14 )
{
T_2 V_38 = V_17 . V_39 ;
return F_28 ( V_14 -> V_40 ,
V_41 ,
F_29 ( V_42 ) , V_38 , V_38 ) ;
}
static void F_30 ( struct V_43 * V_40 )
{
F_31 ( V_40 ) ;
}
int F_32 ( struct V_44 * V_45 )
{
return F_33 ( & V_45 -> V_2 , & V_46 ) ;
}

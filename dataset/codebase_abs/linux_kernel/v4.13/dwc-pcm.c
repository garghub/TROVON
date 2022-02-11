static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 ;
bool V_6 , V_7 ;
F_2 () ;
if ( V_3 )
V_5 = F_3 ( V_2 -> V_8 ) ;
else
V_5 = F_3 ( V_2 -> V_9 ) ;
V_6 = V_5 && F_4 ( V_5 ) ;
if ( V_6 ) {
unsigned int V_10 ;
unsigned int V_11 ;
if ( V_3 ) {
V_10 = F_5 ( V_2 -> V_12 ) ;
V_11 = V_2 -> V_13 ( V_2 , V_5 -> V_14 , V_10 ,
& V_7 ) ;
F_6 ( & V_2 -> V_12 , V_10 , V_11 ) ;
} else {
V_10 = F_5 ( V_2 -> V_15 ) ;
V_11 = V_2 -> V_16 ( V_2 , V_5 -> V_14 , V_10 ,
& V_7 ) ;
F_6 ( & V_2 -> V_15 , V_10 , V_11 ) ;
}
if ( V_7 )
F_7 ( V_5 ) ;
}
F_8 () ;
}
void F_9 ( struct V_1 * V_2 )
{
F_1 ( V_2 , true ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_1 ( V_2 , false ) ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_17 * V_14 = V_5 -> V_14 ;
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_1 * V_2 = F_12 ( V_19 -> V_21 ) ;
F_13 ( V_5 , & V_22 ) ;
F_14 ( V_14 , V_23 ) ;
V_14 -> V_20 = V_2 ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 )
{
F_16 () ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 ,
struct V_24 * V_25 )
{
struct V_17 * V_14 = V_5 -> V_14 ;
struct V_1 * V_2 = V_14 -> V_20 ;
int V_26 ;
switch ( F_18 ( V_25 ) ) {
case 2 :
break;
default:
F_19 ( V_2 -> V_2 , L_1 ) ;
return - V_27 ;
}
switch ( F_20 ( V_25 ) ) {
case V_28 :
V_2 -> V_13 = V_29 ;
V_2 -> V_16 = V_30 ;
break;
case V_31 :
case V_32 :
V_2 -> V_13 = V_33 ;
V_2 -> V_16 = V_34 ;
break;
default:
F_19 ( V_2 -> V_2 , L_2 ) ;
return - V_27 ;
}
V_26 = F_21 ( V_5 ,
F_22 ( V_25 ) ) ;
if ( V_26 < 0 )
return V_26 ;
else
return 0 ;
}
static int F_23 ( struct V_4 * V_5 )
{
return F_24 ( V_5 ) ;
}
static int F_25 ( struct V_4 * V_5 , int V_35 )
{
struct V_17 * V_14 = V_5 -> V_14 ;
struct V_1 * V_2 = V_14 -> V_20 ;
int V_26 = 0 ;
switch ( V_35 ) {
case V_36 :
case V_37 :
case V_38 :
if ( V_5 -> V_39 == V_40 ) {
F_26 ( V_2 -> V_12 , 0 ) ;
F_27 ( V_2 -> V_8 , V_5 ) ;
} else {
F_26 ( V_2 -> V_15 , 0 ) ;
F_27 ( V_2 -> V_9 , V_5 ) ;
}
break;
case V_41 :
case V_42 :
case V_43 :
if ( V_5 -> V_39 == V_40 )
F_27 ( V_2 -> V_8 , NULL ) ;
else
F_27 ( V_2 -> V_9 , NULL ) ;
break;
default:
V_26 = - V_27 ;
break;
}
return V_26 ;
}
static T_1 F_28 ( struct V_4 * V_5 )
{
struct V_17 * V_14 = V_5 -> V_14 ;
struct V_1 * V_2 = V_14 -> V_20 ;
T_1 V_44 ;
if ( V_5 -> V_39 == V_40 )
V_44 = F_5 ( V_2 -> V_12 ) ;
else
V_44 = F_5 ( V_2 -> V_15 ) ;
return V_44 < V_14 -> V_45 ? V_44 : 0 ;
}
static int F_29 ( struct V_18 * V_19 )
{
T_2 V_46 = V_22 . V_47 ;
return F_30 ( V_19 -> V_48 ,
V_49 ,
F_31 ( V_50 ) , V_46 , V_46 ) ;
}
static void F_32 ( struct V_51 * V_48 )
{
F_33 ( V_48 ) ;
}
int F_34 ( struct V_52 * V_53 )
{
return F_35 ( & V_53 -> V_2 , & V_54 ) ;
}

static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_6 ... V_5 :
return true ;
default:
return false ;
}
}
static int F_3 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
struct V_12 * V_13 = F_4 ( V_11 ) ;
unsigned int V_14 ;
V_14 = V_9 & V_15 ;
switch ( V_14 ) {
case V_16 :
case V_17 :
case V_18 :
V_13 -> V_19 = V_9 & V_15 ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_5 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
struct V_7 * V_25 )
{
struct V_10 * V_11 = V_25 -> V_11 ;
struct V_12 * V_13 = F_4 ( V_11 ) ;
int V_14 , V_26 ;
V_13 -> V_27 = F_6 ( V_24 ) ;
switch ( V_13 -> V_19 ) {
case V_16 :
V_14 = V_28 ;
break;
case V_17 :
V_14 = V_29 ;
break;
case V_18 :
switch ( F_7 ( V_24 ) ) {
case 16 :
V_14 = V_30 ;
break;
case 24 :
V_14 = V_31 ;
break;
default:
return - V_20 ;
}
break;
default:
return - V_20 ;
}
V_26 = F_8 ( V_11 , V_6 , V_32 ,
F_9 ( V_14 ) ) ;
if ( V_26 < 0 )
return V_26 ;
return 0 ;
}
static int F_10 ( struct V_7 * V_25 , int V_33 )
{
struct V_10 * V_11 = V_25 -> V_11 ;
int V_3 ;
V_3 = 0 ;
if ( V_33 )
V_3 = V_34 ;
return F_8 ( V_11 , V_35 , V_34 , V_3 ) ;
}
static int F_11 ( struct V_36 * V_37 ,
const struct V_38 * V_39 )
{
struct V_12 * V_13 ;
int V_26 ;
V_13 = F_12 ( & V_37 -> V_2 , sizeof( * V_13 ) , V_40 ) ;
if ( ! V_13 )
return - V_41 ;
V_13 -> V_42 = F_13 ( V_37 , & V_43 ) ;
if ( F_14 ( V_13 -> V_42 ) ) {
V_26 = F_15 ( V_13 -> V_42 ) ;
F_16 ( & V_37 -> V_2 , L_1 , V_26 ) ;
return V_26 ;
}
V_13 -> V_44 = F_17 ( & V_37 -> V_2 ,
L_2 , V_45 ) ;
if ( F_14 ( V_13 -> V_44 ) )
return F_15 ( V_13 -> V_44 ) ;
F_18 ( V_13 -> V_44 , 1 ) ;
F_19 ( V_37 , V_13 ) ;
return F_20 ( & V_37 -> V_2 , & V_46 ,
& V_47 , 1 ) ;
}
static int F_21 ( struct V_36 * V_37 )
{
struct V_12 * V_13 = F_22 ( V_37 ) ;
F_23 ( & V_37 -> V_2 ) ;
F_18 ( V_13 -> V_44 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_25 ( V_2 ) ;
int V_26 ;
V_26 = F_26 ( V_13 -> V_42 , V_5 , V_48 , V_48 ) ;
if ( V_26 < 0 )
return V_26 ;
F_27 ( V_13 -> V_42 , true ) ;
F_18 ( V_13 -> V_44 , 0 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_25 ( V_2 ) ;
int V_26 ;
V_26 = F_26 ( V_13 -> V_42 , V_5 , V_48 , 0 ) ;
if ( V_26 < 0 )
return V_26 ;
F_18 ( V_13 -> V_44 , 1 ) ;
F_27 ( V_13 -> V_42 , false ) ;
F_29 ( V_13 -> V_42 ) ;
return 0 ;
}

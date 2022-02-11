static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 ;
switch ( V_7 ) {
case V_11 :
V_10 = F_3 ( V_9 -> V_12 ,
V_13 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_5 = V_10 ;
return V_14 ;
case V_15 :
* V_5 = 1 << V_9 -> V_16 ;
return V_14 ;
case V_17 :
if ( V_9 -> V_16 == 0 )
* V_6 = 400000 ;
else if ( V_9 -> V_16 == 1 )
* V_6 = 200000 ;
else if ( V_9 -> V_16 == 2 )
* V_6 = 100000 ;
else
return - V_18 ;
* V_5 = 0 ;
return V_19 ;
default:
return - V_18 ;
}
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_5 , int V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_16 , V_10 ;
switch ( V_7 ) {
case V_17 :
if ( V_5 != 0 )
return - V_18 ;
if ( V_6 == 400000 )
V_16 = 0 ;
else if ( V_6 == 200000 )
V_16 = 1 ;
else if ( V_6 == 100000 )
V_16 = 2 ;
else
return - V_18 ;
F_5 ( & V_9 -> V_20 ) ;
V_10 = F_6 ( V_9 -> V_12 ,
V_21 , V_16 ) ;
if ( V_10 >= 0 )
V_9 -> V_16 = V_16 ;
F_7 ( & V_9 -> V_20 ) ;
return V_10 ;
default:
return - V_18 ;
}
}
static int F_8 ( struct V_22 * V_12 )
{
int V_10 = F_9 ( V_12 , V_23 ) ;
if ( V_10 < 0 )
return V_10 ;
switch ( V_10 >> V_24 ) {
case V_25 :
case V_26 :
case V_27 :
case V_28 :
return 0 ;
default:
return - V_29 ;
}
}
static int F_10 ( struct V_22 * V_12 ,
const struct V_30 * V_31 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
int V_10 ;
V_2 = F_11 ( & V_12 -> V_32 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_33 ;
V_9 = F_2 ( V_2 ) ;
F_12 ( V_12 , V_2 ) ;
V_9 -> V_12 = V_12 ;
F_13 ( & V_9 -> V_20 ) ;
V_10 = F_8 ( V_12 ) ;
if ( V_10 ) {
F_14 ( & V_12 -> V_32 , L_1 ) ;
return V_10 ;
}
V_10 = F_6 ( V_9 -> V_12 , V_34 ,
V_35 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_6 ( V_9 -> V_12 , V_21 ,
V_36 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_32 . V_37 = & V_12 -> V_32 ;
V_2 -> V_38 = & V_39 ;
V_2 -> V_40 = V_41 ;
V_2 -> V_42 = F_15 ( V_41 ) ;
V_2 -> V_43 = V_44 ;
V_2 -> V_45 = V_46 ;
return F_16 ( V_2 ) ;
}
static int F_17 ( struct V_22 * V_12 )
{
return F_6 ( V_12 , V_34 ,
V_47 ) ;
}
static int F_18 ( struct V_22 * V_12 )
{
F_19 ( F_20 ( V_12 ) ) ;
F_17 ( V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_48 * V_32 )
{
return F_17 ( F_22 ( V_32 ) ) ;
}
static int F_23 ( struct V_48 * V_32 )
{
return F_6 ( F_22 ( V_32 ) , V_34 ,
V_35 ) ;
}

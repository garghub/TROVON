static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 , & V_3 ) ;
if ( V_4 )
return V_4 ;
return F_3 ( V_7 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_8 )
{
int V_4 ;
T_1 V_3 ;
V_3 = F_5 ( V_7 , V_8 ) ;
V_4 = F_6 ( V_2 -> V_5 , V_6 , V_3 ) ;
if ( V_4 )
return V_4 ;
if ( ! V_8 ) {
F_7 ( V_2 -> V_9 ) ;
return 0 ;
}
V_4 = F_6 ( V_2 -> V_5 , V_10 , V_2 -> V_11 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_6 ( V_2 -> V_5 , V_12 , 0 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_8 ( V_2 -> V_5 , V_13 , V_3 ,
( V_3 & V_14 ) ,
100 , 1000 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_6 ( V_2 -> V_5 , V_15 ,
V_16 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_9 ( V_2 -> V_9 ) ;
if ( V_4 ) {
F_6 ( V_2 -> V_5 , V_6 , 0 ) ;
return V_4 ;
}
return F_10 ( V_2 -> V_5 , V_6 ,
V_17 , V_17 ) ;
}
static int F_11 ( struct V_1 * V_2 , int V_8 )
{
T_1 V_18 = V_19 | V_20 |
V_21 | V_22 ;
T_1 V_3 ;
if ( V_2 -> V_23 )
V_3 = V_8 ? V_19 : 0 ;
else
V_3 = V_8 ? V_20 : 0 ;
V_3 |= F_5 ( V_21 , V_8 ? V_2 -> V_24 : 0 ) ;
return F_10 ( V_2 -> V_5 , V_25 , V_18 , V_3 ) ;
}
static int F_12 ( struct V_26 * V_27 ,
struct V_28 const * V_29 ,
int V_3 , int V_30 , long V_18 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
int V_4 ;
switch ( V_18 ) {
case V_31 :
if ( V_3 < 0 || V_3 > 1 )
return - V_32 ;
V_4 = F_1 ( V_2 ) ;
if ( ( V_4 < 0 ) || ( ! V_4 && ! V_3 ) )
return V_4 ;
if ( V_3 && V_4 )
return - V_33 ;
V_4 = F_11 ( V_2 , V_3 ) ;
if ( V_4 )
return V_4 ;
return F_4 ( V_2 , V_3 ) ;
default:
return - V_32 ;
}
}
static int F_14 ( struct V_26 * V_27 ,
struct V_28 const * V_29 ,
int * V_3 , int * V_30 , long V_18 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
T_1 V_34 ;
int V_4 ;
switch ( V_18 ) {
case V_35 :
V_4 = F_2 ( V_2 -> V_5 , V_36 , & V_34 ) ;
if ( V_4 )
return V_4 ;
* V_3 = V_34 ;
return V_37 ;
case V_31 :
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_3 = V_4 ;
return V_37 ;
case V_38 :
* V_3 = 1 ;
* V_30 = 0 ;
if ( V_2 -> V_23 ) {
if ( V_2 -> V_24 > 1 )
* V_30 = 2 ;
else
* V_30 = 1 ;
}
return V_39 ;
default:
return - V_32 ;
}
}
static int F_15 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
return V_2 -> V_23 ;
}
static int F_16 ( struct V_26 * V_27 ,
const struct V_28 * V_29 ,
unsigned int type )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
if ( F_1 ( V_2 ) )
return - V_33 ;
V_2 -> V_23 = type ;
return 0 ;
}
static int F_17 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
return V_2 -> V_24 ;
}
static int F_18 ( struct V_26 * V_27 ,
const struct V_28 * V_29 ,
unsigned int type )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
if ( F_1 ( V_2 ) )
return - V_33 ;
V_2 -> V_24 = type ;
return 0 ;
}
static T_2 F_19 ( struct V_26 * V_27 ,
T_3 V_40 ,
const struct V_28 * V_29 ,
char * V_41 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
return snprintf ( V_41 , V_42 , L_1 , V_2 -> V_11 ) ;
}
static T_2 F_20 ( struct V_26 * V_27 ,
T_3 V_40 ,
const struct V_28 * V_29 ,
const char * V_41 , T_4 V_43 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
int V_4 ;
if ( F_1 ( V_2 ) )
return - V_33 ;
V_4 = F_21 ( V_41 , 0 , & V_2 -> V_11 ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_11 > V_44 )
return - V_32 ;
return V_43 ;
}
static int F_22 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_23 ( V_46 -> V_49 . V_50 ) ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
if ( F_24 ( V_48 ) )
return - V_32 ;
V_27 = F_25 ( & V_46 -> V_49 , sizeof( * V_2 ) ) ;
if ( ! V_27 )
return - V_51 ;
V_2 = F_13 ( V_27 ) ;
V_2 -> V_49 = & V_46 -> V_49 ;
V_2 -> V_5 = V_48 -> V_5 ;
V_2 -> V_9 = V_48 -> V_9 ;
V_2 -> V_11 = V_44 ;
V_27 -> V_52 = F_26 ( & V_46 -> V_49 ) ;
V_27 -> V_49 . V_50 = & V_46 -> V_49 ;
V_27 -> V_49 . V_53 = V_46 -> V_49 . V_53 ;
V_27 -> V_54 = & V_55 ;
if ( V_48 -> V_56 )
V_27 -> V_57 = & V_58 ;
else
V_27 -> V_57 = & V_59 ;
V_27 -> V_60 = 1 ;
F_27 ( V_46 , V_2 ) ;
return F_28 ( & V_46 -> V_49 , V_27 ) ;
}

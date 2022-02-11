static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 >= 0x10 && V_3 <= 0x17 ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned register V_3 )
{
bool V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
return V_4 && V_3 != 0x16 && V_3 != 0x17 ;
}
static int F_3 ( struct V_5 * V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
V_11 -> V_7 = V_7 ;
return 0 ;
}
static int F_5 ( struct V_5 * V_12 , int V_13 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_14 ;
V_14 = F_6 ( V_11 -> V_15 , V_16 ,
V_17 , ! ! V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_7 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_5 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_22 = 0 , V_14 ;
int V_23 = F_8 ( V_21 ) ;
V_11 -> V_24 = F_9 ( V_21 ) ;
switch ( V_11 -> V_7 & V_25 ) {
case V_26 :
if ( V_23 == V_27 ||
V_23 == V_28 )
V_22 = 0x02 ;
else if ( V_23 == V_29 )
V_22 = 0x00 ;
break;
case V_30 :
if ( V_23 == V_27 ||
V_23 == V_28 )
V_22 = 0x05 ;
else if ( V_23 == V_29 )
V_22 = 0x04 ;
break;
default:
F_10 ( V_9 -> V_2 , L_1 ) ;
return - V_31 ;
}
V_22 = V_22 << V_32 | V_33 ;
V_14 = F_6 ( V_11 -> V_15 , V_34 ,
V_35 | V_33 , V_22 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_11 ( struct V_36 * V_37 )
{
struct V_10 * V_38 ;
int V_14 ;
V_38 = F_12 ( & V_37 -> V_2 , sizeof( struct V_10 ) ,
V_39 ) ;
if ( ! V_38 )
return - V_40 ;
F_13 ( V_37 , V_38 ) ;
V_38 -> V_15 = F_14 ( V_37 , & V_41 ) ;
if ( F_15 ( V_38 -> V_15 ) ) {
V_14 = F_16 ( V_38 -> V_15 ) ;
F_10 ( & V_37 -> V_2 , L_2 , V_14 ) ;
return V_14 ;
}
return F_17 ( & V_37 -> V_2 ,
& V_42 , & V_43 , 1 ) ;
}
static int F_18 ( struct V_36 * V_37 )
{
F_19 ( & V_37 -> V_2 ) ;
return 0 ;
}

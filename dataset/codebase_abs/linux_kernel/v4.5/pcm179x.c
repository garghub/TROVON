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
V_11 -> V_23 = F_8 ( V_21 ) ;
switch ( V_11 -> V_7 & V_24 ) {
case V_25 :
switch ( F_9 ( V_21 ) ) {
case 24 :
case 32 :
V_22 = 2 ;
break;
case 16 :
V_22 = 0 ;
break;
default:
return - V_26 ;
}
break;
case V_27 :
switch ( F_9 ( V_21 ) ) {
case 24 :
case 32 :
V_22 = 5 ;
break;
case 16 :
V_22 = 4 ;
break;
default:
return - V_26 ;
}
break;
default:
F_10 ( V_9 -> V_2 , L_1 ) ;
return - V_26 ;
}
V_22 = V_22 << V_28 | V_29 ;
V_14 = F_6 ( V_11 -> V_15 , V_30 ,
V_31 | V_29 , V_22 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_11 ( struct V_32 * V_33 )
{
struct V_10 * V_34 ;
int V_14 ;
V_34 = F_12 ( & V_33 -> V_2 , sizeof( struct V_10 ) ,
V_35 ) ;
if ( ! V_34 )
return - V_36 ;
F_13 ( V_33 , V_34 ) ;
V_34 -> V_15 = F_14 ( V_33 , & V_37 ) ;
if ( F_15 ( V_34 -> V_15 ) ) {
V_14 = F_16 ( V_34 -> V_15 ) ;
F_10 ( & V_33 -> V_2 , L_2 , V_14 ) ;
return V_14 ;
}
return F_17 ( & V_33 -> V_2 ,
& V_38 , & V_39 , 1 ) ;
}
static int F_18 ( struct V_32 * V_33 )
{
F_19 ( & V_33 -> V_2 ) ;
return 0 ;
}

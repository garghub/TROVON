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
int F_11 ( struct V_1 * V_2 , struct V_15 * V_15 )
{
struct V_10 * V_32 ;
V_32 = F_12 ( V_2 , sizeof( struct V_10 ) ,
V_33 ) ;
if ( ! V_32 )
return - V_34 ;
V_32 -> V_15 = V_15 ;
F_13 ( V_2 , V_32 ) ;
return F_14 ( V_2 ,
& V_35 , & V_36 , 1 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
return 0 ;
}

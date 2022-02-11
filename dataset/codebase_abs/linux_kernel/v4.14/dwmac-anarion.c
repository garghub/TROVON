static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( ( void * ) ( V_2 -> V_4 + V_3 ) ) ;
}
static void F_3 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_5 )
{
F_4 ( V_5 , ( void * ) ( V_2 -> V_4 + V_3 ) ) ;
}
static int F_5 ( struct V_6 * V_7 , void * V_8 )
{
T_1 V_9 ;
struct V_1 * V_2 = V_8 ;
F_3 ( V_2 , V_10 , 1 ) ;
V_9 = F_1 ( V_2 , V_11 ) ;
V_9 &= ~ V_12 ;
V_9 |= ( V_2 -> V_13 & V_12 ) ;
F_3 ( V_2 , V_11 , V_9 ) ;
F_3 ( V_2 , V_10 , 0 ) ;
return 0 ;
}
static void F_6 ( struct V_6 * V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
F_3 ( V_2 , V_10 , 1 ) ;
}
static struct V_1 * F_7 ( struct V_6 * V_7 )
{
int V_14 ;
struct V_15 * V_16 ;
void T_3 * V_4 ;
struct V_1 * V_2 ;
V_16 = F_8 ( V_7 , V_17 , 1 ) ;
V_4 = F_9 ( & V_7 -> V_18 , V_16 ) ;
if ( F_10 ( V_4 ) ) {
F_11 ( & V_7 -> V_18 , L_1 ,
F_12 ( V_4 ) ) ;
return V_4 ;
}
V_2 = F_13 ( & V_7 -> V_18 , sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 )
return F_14 ( - V_20 ) ;
V_2 -> V_4 = ( V_21 ) V_4 ;
V_14 = F_15 ( V_7 -> V_18 . V_22 ) ;
switch ( V_14 ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
V_2 -> V_13 = V_27 ;
break;
default:
F_11 ( & V_7 -> V_18 , L_2 ,
V_14 ) ;
return F_14 ( - V_28 ) ;
}
return V_2 ;
}
static int F_16 ( struct V_6 * V_7 )
{
int V_29 ;
struct V_1 * V_2 ;
struct V_30 * V_31 ;
struct V_32 V_33 ;
V_29 = F_17 ( V_7 , & V_33 ) ;
if ( V_29 )
return V_29 ;
V_2 = F_7 ( V_7 ) ;
if ( F_10 ( V_2 ) )
return F_12 ( V_2 ) ;
V_31 = F_18 ( V_7 , & V_33 . V_34 ) ;
if ( F_10 ( V_31 ) )
return F_12 ( V_31 ) ;
V_31 -> V_35 = F_5 ;
V_31 -> exit = F_6 ;
F_5 ( V_7 , V_2 ) ;
V_31 -> V_36 = V_2 ;
V_29 = F_19 ( & V_7 -> V_18 , V_31 , & V_33 ) ;
if ( V_29 ) {
F_20 ( V_7 , V_31 ) ;
return V_29 ;
}
return 0 ;
}

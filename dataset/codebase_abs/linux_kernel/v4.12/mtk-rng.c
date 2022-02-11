static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
int V_6 ;
V_6 = F_3 ( V_4 -> V_7 ) ;
if ( V_6 )
return V_6 ;
V_5 = F_4 ( V_4 -> V_8 + V_9 ) ;
V_5 |= V_10 ;
F_5 ( V_5 , V_4 -> V_8 + V_9 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_4 ( V_4 -> V_8 + V_9 ) ;
V_5 &= ~ V_10 ;
F_5 ( V_5 , V_4 -> V_8 + V_9 ) ;
F_7 ( V_4 -> V_7 ) ;
}
static bool F_8 ( struct V_1 * V_2 , bool V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_12 ;
V_12 = F_4 ( V_4 -> V_8 + V_9 ) & V_13 ;
if ( ! V_12 && V_11 )
F_9 ( V_4 -> V_8 + V_9 , V_12 ,
V_12 & V_13 , V_14 ,
V_15 ) ;
return ! ! V_12 ;
}
static int F_10 ( struct V_1 * V_2 , void * V_16 , T_2 V_17 , bool V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 = 0 ;
while ( V_17 >= sizeof( T_1 ) ) {
if ( ! F_8 ( V_2 , V_11 ) )
break;
* ( T_1 * ) V_16 = F_4 ( V_4 -> V_8 + V_19 ) ;
V_18 += sizeof( T_1 ) ;
V_16 += sizeof( T_1 ) ;
V_17 -= sizeof( T_1 ) ;
}
return V_18 || ! V_11 ? V_18 : - V_20 ;
}
static int F_11 ( struct V_21 * V_22 )
{
struct V_23 * V_24 ;
int V_25 ;
struct V_3 * V_4 ;
V_24 = F_12 ( V_22 , V_26 , 0 ) ;
if ( ! V_24 ) {
F_13 ( & V_22 -> V_27 , L_1 ) ;
return - V_28 ;
}
V_4 = F_14 ( & V_22 -> V_27 , sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
return - V_30 ;
V_4 -> V_2 . V_31 = V_22 -> V_31 ;
V_4 -> V_2 . V_32 = F_1 ;
V_4 -> V_2 . V_33 = F_6 ;
V_4 -> V_2 . V_34 = F_10 ;
V_4 -> V_7 = F_15 ( & V_22 -> V_27 , L_2 ) ;
if ( F_16 ( V_4 -> V_7 ) ) {
V_25 = F_17 ( V_4 -> V_7 ) ;
F_13 ( & V_22 -> V_27 , L_3 , V_25 ) ;
return V_25 ;
}
V_4 -> V_8 = F_18 ( & V_22 -> V_27 , V_24 ) ;
if ( F_16 ( V_4 -> V_8 ) )
return F_17 ( V_4 -> V_8 ) ;
V_25 = F_19 ( & V_22 -> V_27 , & V_4 -> V_2 ) ;
if ( V_25 ) {
F_13 ( & V_22 -> V_27 , L_4 ,
V_25 ) ;
return V_25 ;
}
F_20 ( & V_22 -> V_27 , L_5 ) ;
return 0 ;
}

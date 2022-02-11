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
F_11 ( (struct V_19 * ) V_4 -> V_2 . V_4 ) ;
while ( V_17 >= sizeof( T_1 ) ) {
if ( ! F_8 ( V_2 , V_11 ) )
break;
* ( T_1 * ) V_16 = F_4 ( V_4 -> V_8 + V_20 ) ;
V_18 += sizeof( T_1 ) ;
V_16 += sizeof( T_1 ) ;
V_17 -= sizeof( T_1 ) ;
}
F_12 ( (struct V_19 * ) V_4 -> V_2 . V_4 ) ;
F_13 ( (struct V_19 * ) V_4 -> V_2 . V_4 ) ;
return V_18 || ! V_11 ? V_18 : - V_21 ;
}
static int F_14 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
int V_26 ;
struct V_3 * V_4 ;
V_25 = F_15 ( V_23 , V_27 , 0 ) ;
if ( ! V_25 ) {
F_16 ( & V_23 -> V_28 , L_1 ) ;
return - V_29 ;
}
V_4 = F_17 ( & V_23 -> V_28 , sizeof( * V_4 ) , V_30 ) ;
if ( ! V_4 )
return - V_31 ;
V_4 -> V_2 . V_32 = V_23 -> V_32 ;
#ifndef F_18
V_4 -> V_2 . V_33 = F_1 ;
V_4 -> V_2 . V_34 = F_6 ;
#endif
V_4 -> V_2 . V_35 = F_10 ;
V_4 -> V_2 . V_4 = ( unsigned long ) & V_23 -> V_28 ;
V_4 -> V_7 = F_19 ( & V_23 -> V_28 , L_2 ) ;
if ( F_20 ( V_4 -> V_7 ) ) {
V_26 = F_21 ( V_4 -> V_7 ) ;
F_16 ( & V_23 -> V_28 , L_3 , V_26 ) ;
return V_26 ;
}
V_4 -> V_8 = F_22 ( & V_23 -> V_28 , V_25 ) ;
if ( F_20 ( V_4 -> V_8 ) )
return F_21 ( V_4 -> V_8 ) ;
V_26 = F_23 ( & V_23 -> V_28 , & V_4 -> V_2 ) ;
if ( V_26 ) {
F_16 ( & V_23 -> V_28 , L_4 ,
V_26 ) ;
return V_26 ;
}
F_24 ( & V_23 -> V_28 , V_4 ) ;
F_25 ( & V_23 -> V_28 , V_36 ) ;
F_26 ( & V_23 -> V_28 ) ;
F_27 ( & V_23 -> V_28 ) ;
F_28 ( & V_23 -> V_28 , L_5 ) ;
return 0 ;
}
static int F_29 ( struct V_19 * V_28 )
{
struct V_3 * V_4 = F_30 ( V_28 ) ;
F_6 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_19 * V_28 )
{
struct V_3 * V_4 = F_30 ( V_28 ) ;
return F_1 ( & V_4 -> V_2 ) ;
}

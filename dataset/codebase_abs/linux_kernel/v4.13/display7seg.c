static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( V_4 != F_2 ( V_1 ) )
return - V_5 ;
F_3 ( & V_6 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( F_5 ( & V_6 ) && ! V_7 ) {
struct V_8 * V_9 = V_10 ;
T_1 V_11 = 0 ;
V_11 = F_6 ( V_9 -> V_12 ) ;
if ( V_9 -> V_13 )
V_11 |= V_14 ;
else
V_11 &= ~ V_14 ;
F_7 ( V_11 , V_9 -> V_12 ) ;
}
return 0 ;
}
static long F_8 ( struct V_2 * V_2 , unsigned int V_15 , unsigned long V_16 )
{
struct V_8 * V_9 = V_10 ;
T_1 V_12 = F_6 ( V_9 -> V_12 ) ;
int error = 0 ;
T_1 V_17 = 0 ;
if ( V_4 != F_2 ( F_9 ( V_2 ) ) )
return - V_5 ;
F_10 ( & V_18 ) ;
switch ( V_15 ) {
case V_19 :
if ( F_11 ( V_17 , ( int V_20 * ) V_16 ) ) {
error = - V_21 ;
break;
}
if ( V_7 ) {
if ( V_12 & V_14 )
V_17 |= V_14 ;
else
V_17 &= ~ V_14 ;
}
F_7 ( V_17 , V_9 -> V_12 ) ;
break;
case V_22 :
if ( F_12 ( V_12 , ( int V_20 * ) V_16 ) ) {
error = - V_21 ;
break;
}
break;
case V_23 :
V_12 ^= V_14 ;
F_7 ( V_12 , V_9 -> V_12 ) ;
break;
}
F_13 ( & V_18 ) ;
return error ;
}
static int F_14 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
int V_28 = - V_29 ;
struct V_8 * V_9 ;
T_1 V_12 ;
if ( V_10 )
goto V_30;
V_9 = F_15 ( & V_25 -> V_31 , sizeof( * V_9 ) , V_32 ) ;
V_28 = - V_33 ;
if ( ! V_9 )
goto V_30;
V_9 -> V_12 = F_16 ( & V_25 -> V_34 [ 0 ] , 0 , sizeof( T_1 ) , L_1 ) ;
if ( ! V_9 -> V_12 ) {
F_17 (KERN_ERR PFX L_2 ) ;
goto V_35;
}
V_28 = F_18 ( & V_36 ) ;
if ( V_28 ) {
F_17 (KERN_ERR PFX L_3 ,
D7S_MINOR) ;
goto V_37;
}
V_12 = F_6 ( V_9 -> V_12 ) ;
V_27 = F_19 ( L_4 ) ;
if ( V_27 &&
F_20 ( V_27 , L_5 , NULL ) )
V_9 -> V_13 = true ;
if ( V_9 -> V_13 )
V_12 |= V_14 ;
else
V_12 &= ~ V_14 ;
F_7 ( V_12 , V_9 -> V_12 ) ;
F_17 (KERN_INFO PFX L_6 ,
op->dev.of_node,
(regs & D7S_FLIP) ? L_7 : L_8 ,
op->resource[0].start,
sol_compat ? L_9 : L_8 ) ;
F_21 ( & V_25 -> V_31 , V_9 ) ;
V_10 = V_9 ;
V_28 = 0 ;
V_30:
return V_28 ;
V_37:
F_22 ( & V_25 -> V_34 [ 0 ] , V_9 -> V_12 , sizeof( T_1 ) ) ;
V_35:
goto V_30;
}
static int F_23 ( struct V_24 * V_25 )
{
struct V_8 * V_9 = F_24 ( & V_25 -> V_31 ) ;
T_1 V_12 = F_6 ( V_9 -> V_12 ) ;
if ( V_7 ) {
if ( V_9 -> V_13 )
V_12 |= V_14 ;
else
V_12 &= ~ V_14 ;
F_7 ( V_12 , V_9 -> V_12 ) ;
}
F_25 ( & V_36 ) ;
F_22 ( & V_25 -> V_34 [ 0 ] , V_9 -> V_12 , sizeof( T_1 ) ) ;
return 0 ;
}

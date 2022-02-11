static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
T_1 V_4 ;
V_3 = F_2 ( V_1 ) ;
if ( ! V_3 )
return - V_5 ;
V_4 = F_3 ( V_3 -> V_4 ) ;
if ( V_3 -> V_6 )
V_4 |= V_7 ;
else
V_4 &= ~ V_7 ;
F_4 ( V_4 , V_3 -> V_4 ) ;
return 0 ;
}
static struct V_1 * F_5 ( struct V_8 * V_9 ,
struct V_10 * args )
{
struct V_2 * V_3 = F_6 ( V_9 ) ;
if ( ! V_3 )
return F_7 ( - V_5 ) ;
if ( F_8 ( ( V_3 -> V_11 != V_12 ) &&
( V_3 -> V_11 != args -> args [ 0 ] ) ) ) {
F_9 ( V_9 , L_1 ) ;
F_9 ( V_9 , L_2 ) ;
if ( args -> args [ 0 ] == V_13 )
return F_7 ( - V_14 ) ;
else
return F_7 ( - V_5 ) ;
}
if ( args -> args [ 0 ] == V_13 )
V_3 -> V_6 = false ;
else if ( args -> args [ 0 ] == V_15 )
V_3 -> V_6 = true ;
else {
F_9 ( V_9 , L_3 ) ;
return F_7 ( - V_5 ) ;
}
V_3 -> V_11 = args -> args [ 0 ] ;
return V_3 -> V_1 ;
}
static int F_10 ( struct V_16 * V_17 )
{
struct V_8 * V_9 = & V_17 -> V_9 ;
struct V_1 * V_1 ;
struct V_18 * V_18 ;
void T_2 * V_19 ;
struct V_20 * V_21 ;
struct V_2 * V_3 ;
V_3 = F_11 ( V_9 , sizeof( * V_3 ) , V_22 ) ;
if ( ! V_3 )
return - V_23 ;
V_21 = F_12 ( V_17 , V_24 , 0 ) ;
V_19 = F_13 ( & V_17 -> V_9 , V_21 ) ;
if ( F_14 ( V_19 ) )
return F_15 ( V_19 ) ;
V_1 = F_16 ( V_9 , NULL , & V_25 ) ;
if ( F_14 ( V_1 ) ) {
F_9 ( V_9 , L_4 ) ;
return F_15 ( V_1 ) ;
}
V_3 -> V_1 = V_1 ;
V_3 -> V_4 = V_19 ;
F_17 ( V_9 , V_3 ) ;
F_18 ( V_1 , V_3 ) ;
V_18 = F_19 ( & V_17 -> V_9 ,
F_5 ) ;
return F_20 ( V_18 ) ;
}

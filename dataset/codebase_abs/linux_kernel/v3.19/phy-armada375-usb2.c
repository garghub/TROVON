static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
T_1 V_4 ;
V_3 = F_2 ( V_1 -> V_5 . V_6 ) ;
if ( ! V_3 )
return - V_7 ;
V_4 = F_3 ( V_3 -> V_4 ) ;
if ( V_3 -> V_8 )
V_4 |= V_9 ;
else
V_4 &= ~ V_9 ;
F_4 ( V_4 , V_3 -> V_4 ) ;
return 0 ;
}
static struct V_1 * F_5 ( struct V_10 * V_5 ,
struct V_11 * args )
{
struct V_2 * V_3 = F_2 ( V_5 ) ;
if ( ! V_3 )
return F_6 ( - V_7 ) ;
if ( F_7 ( ( V_3 -> V_12 != V_13 ) &&
( V_3 -> V_12 != args -> args [ 0 ] ) ) ) {
F_8 ( V_5 , L_1 ) ;
F_8 ( V_5 , L_2 ) ;
if ( args -> args [ 0 ] == V_14 )
return F_6 ( - V_15 ) ;
else
return F_6 ( - V_7 ) ;
}
if ( args -> args [ 0 ] == V_14 )
V_3 -> V_8 = false ;
else if ( args -> args [ 0 ] == V_16 )
V_3 -> V_8 = true ;
else {
F_8 ( V_5 , L_3 ) ;
return F_6 ( - V_7 ) ;
}
V_3 -> V_12 = args -> args [ 0 ] ;
return V_3 -> V_1 ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_10 * V_5 = & V_18 -> V_5 ;
struct V_1 * V_1 ;
struct V_19 * V_19 ;
void T_2 * V_20 ;
struct V_21 * V_22 ;
struct V_2 * V_3 ;
V_3 = F_10 ( V_5 , sizeof( * V_3 ) , V_23 ) ;
if ( ! V_3 )
return - V_24 ;
V_22 = F_11 ( V_18 , V_25 , 0 ) ;
V_20 = F_12 ( & V_18 -> V_5 , V_22 ) ;
if ( ! V_20 )
return - V_24 ;
V_1 = F_13 ( V_5 , NULL , & V_26 ) ;
if ( F_14 ( V_1 ) ) {
F_8 ( V_5 , L_4 ) ;
return F_15 ( V_1 ) ;
}
V_3 -> V_1 = V_1 ;
V_3 -> V_4 = V_20 ;
F_16 ( V_5 , V_3 ) ;
V_19 = F_17 ( & V_18 -> V_5 ,
F_5 ) ;
return F_18 ( V_19 ) ;
}

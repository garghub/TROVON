static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
T_1 V_5 [ F_2 ( V_6 ) ] = { 0 } ;
T_1 V_7 [ F_2 ( V_8 ) ] = { 0 } ;
T_2 * V_9 ;
F_3 ( V_6 , V_5 , V_10 , V_11 ) ;
F_3 ( V_6 , V_5 , V_12 , V_3 ) ;
V_9 = F_4 ( V_6 , V_5 , V_13 ) ;
F_5 ( & V_9 [ 2 ] , V_4 ) ;
return F_6 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_5 [ F_2 ( V_14 ) ] = { 0 } ;
T_1 V_7 [ F_2 ( V_15 ) ] = { 0 } ;
F_3 ( V_14 , V_5 , V_10 , V_16 ) ;
F_3 ( V_14 , V_5 , V_12 , V_3 ) ;
return F_6 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
static int F_8 ( struct V_17 * V_18 , T_1 * V_19 )
{
int V_20 = 0 ;
* V_19 = F_9 ( V_18 -> V_21 , V_18 -> V_22 ) ;
if ( * V_19 >= V_18 -> V_22 )
V_20 = - V_23 ;
else
F_10 ( * V_19 , V_18 -> V_21 ) ;
return V_20 ;
}
static void F_11 ( struct V_17 * V_18 , T_1 V_19 )
{
F_12 ( V_19 , V_18 -> V_21 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_24 = 1 << F_14 ( V_2 , V_25 ) ;
struct V_17 * V_26 ;
if ( ! F_15 ( V_2 ) )
return 0 ;
V_26 = F_16 ( sizeof( * V_26 ) , V_27 ) ;
if ( ! V_26 )
return - V_28 ;
F_17 ( & V_26 -> V_29 ) ;
V_26 -> V_22 = V_24 ;
V_26 -> V_21 = F_18 ( F_19 ( V_24 ) ,
sizeof( V_30 ) , V_27 ) ;
if ( ! V_26 -> V_21 ) {
F_20 ( V_26 ) ;
return - V_28 ;
}
V_2 -> V_31 . V_26 = V_26 ;
return 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_17 * V_26 = V_2 -> V_31 . V_26 ;
if ( ! F_15 ( V_2 ) )
return;
F_22 ( ! F_23 ( V_26 -> V_32 ) ) ;
F_20 ( V_26 -> V_21 ) ;
F_20 ( V_26 ) ;
}
int F_24 ( struct V_1 * V_2 , T_2 * V_4 )
{
struct V_17 * V_26 = V_2 -> V_31 . V_26 ;
struct V_33 * V_34 ;
T_1 V_3 ;
int V_20 ;
if ( ! F_15 ( V_2 ) )
return 0 ;
F_25 ( & V_26 -> V_29 ) ;
V_34 = F_26 ( V_26 -> V_32 , V_4 , struct V_33 ) ;
if ( V_34 ) {
V_20 = - V_35 ;
goto abort;
}
V_20 = F_8 ( V_26 , & V_3 ) ;
if ( V_20 )
goto abort;
V_34 = F_27 ( V_26 -> V_32 , V_4 , struct V_33 , V_27 ) ;
if ( ! V_34 ) {
F_11 ( V_26 , V_3 ) ;
V_20 = - V_28 ;
goto abort;
}
V_34 -> V_3 = V_3 ;
V_20 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_20 ) {
F_28 ( V_34 ) ;
F_11 ( V_26 , V_3 ) ;
}
F_29 ( V_2 , L_1 , V_4 , V_3 ) ;
abort:
F_30 ( & V_26 -> V_29 ) ;
return V_20 ;
}
int F_31 ( struct V_1 * V_2 , T_2 * V_4 )
{
struct V_17 * V_26 = V_2 -> V_31 . V_26 ;
struct V_33 * V_34 ;
int V_20 = 0 ;
T_1 V_3 ;
if ( ! F_15 ( V_2 ) )
return 0 ;
F_25 ( & V_26 -> V_29 ) ;
V_34 = F_26 ( V_26 -> V_32 , V_4 , struct V_33 ) ;
if ( ! V_34 ) {
V_20 = - V_36 ;
goto V_37;
}
V_3 = V_34 -> V_3 ;
F_7 ( V_2 , V_3 ) ;
F_28 ( V_34 ) ;
F_11 ( V_26 , V_3 ) ;
F_29 ( V_2 , L_2 , V_4 , V_3 ) ;
V_37:
F_30 ( & V_26 -> V_29 ) ;
return V_20 ;
}

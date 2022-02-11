static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 ;
struct V_5 V_6 = { V_7 , NULL } ;
union V_8 * V_9 ;
int V_10 = 0 ;
V_4 = F_2 ( V_3 , L_1 , NULL , & V_6 ) ;
if ( F_3 ( V_4 ) )
return - V_11 ;
V_9 = V_6 . V_12 ;
if ( ! V_9 || ( V_9 -> type != V_13 )
|| V_9 -> V_14 . V_15 != 4 ) {
V_10 = - V_16 ;
goto V_17;
}
if ( V_9 -> V_14 . V_18 [ 0 ] . integer . V_19 )
V_2 -> V_20 = V_21 ;
else
V_2 -> V_20 = V_22 ;
V_17:
F_4 ( V_9 ) ;
return V_10 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 ;
struct V_23 V_24 ;
V_4 = F_6 ( V_3 , & V_24 ) ;
if ( F_3 ( V_4 ) )
return - V_11 ;
if ( V_24 . V_25 )
V_2 -> V_20 = V_21 ;
else
V_2 -> V_20 = V_22 ;
return 0 ;
}
static int F_7 ( struct V_26 * V_27 , T_1 * V_3 )
{
struct V_1 * V_2 ;
struct V_26 * V_28 ;
T_1 * V_29 ;
if ( ! F_8 ( V_27 ) )
return - V_11 ;
V_2 = F_9 ( V_27 ) ;
V_28 = V_27 -> V_28 ;
V_29 = F_10 ( V_28 ) ;
if ( ! V_29 )
return - V_11 ;
* V_3 = F_11 ( V_29 , V_2 -> V_30 ) ;
if ( ! * V_3 )
return - V_11 ;
if ( F_5 ( V_2 , * V_3 ) != 0 )
F_1 ( V_2 , * V_3 ) ;
return 0 ;
}
int F_12 ( void )
{
return F_13 ( & V_31 ) ;
}
void F_14 ( void )
{
F_15 ( & V_31 ) ;
}

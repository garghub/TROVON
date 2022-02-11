static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_2 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 , V_4 , V_3 ) ;
if ( V_5 < 0 )
F_3 ( V_2 -> V_6 , L_1 ,
V_4 , V_5 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
int V_5 ;
V_5 = F_5 ( V_2 -> V_6 -> V_7 , V_4 , V_3 ) ;
if ( V_5 < 0 )
F_3 ( V_2 -> V_6 , L_2 ,
V_4 , V_5 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 , bool V_8 )
{
int V_5 ;
T_1 V_9 = V_2 -> V_10 ;
if ( V_8 )
V_9 |= ( ( V_2 -> V_11 << V_12 ) & V_13 ) ;
else
V_9 &= ~ V_13 ;
V_5 = F_4 ( V_2 , V_9 , V_14 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_10 = V_9 ;
return 0 ;
}
static void F_7 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_8 ( V_16 , struct V_1 , V_16 ) ;
int V_5 ;
T_1 V_9 ;
V_5 = F_1 ( V_2 , & V_9 , V_14 ) ;
if ( V_5 < 0 )
return;
if ( V_2 -> V_17 ) {
V_2 -> V_18 = true ;
V_2 -> V_11 = ( ( V_19 * V_2 -> V_17 ) / V_20 ) +
V_21 ;
V_2 -> V_11 /= 100 ;
} else {
V_2 -> V_18 = false ;
V_2 -> V_11 = V_21 / 100 ;
}
F_6 ( V_2 , V_2 -> V_18 ) ;
}
static void F_9 ( struct V_22 * V_6 )
{
struct V_1 * V_2 = F_10 ( V_6 ) ;
F_11 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_18 )
F_6 ( V_2 , false ) ;
}
static int F_12 ( struct V_22 * V_6 , void * V_3 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_10 ( V_6 ) ;
V_2 -> V_17 = V_24 -> V_25 . V_26 . V_27 >> 8 ;
if ( ! V_2 -> V_17 )
V_2 -> V_17 = V_24 -> V_25 . V_26 . V_28 >> 9 ;
F_13 ( & V_2 -> V_16 ) ;
return 0 ;
}
static int T_3 F_14 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_22 * V_22 ;
int error ;
T_1 V_9 ;
V_2 = F_15 ( sizeof( * V_2 ) , V_31 ) ;
V_22 = F_16 () ;
if ( ! V_2 || ! V_22 ) {
F_17 ( & V_30 -> V_6 , L_3 ) ;
error = - V_32 ;
goto V_33;
}
F_18 ( & V_2 -> V_16 , F_7 ) ;
V_2 -> V_6 = & V_30 -> V_6 ;
V_2 -> V_34 = V_22 ;
error = F_1 ( V_2 , & V_9 , V_14 ) ;
if ( error < 0 )
goto V_33;
V_9 &= ~ V_35 ;
error = F_4 ( V_2 , V_9 , V_14 ) ;
if ( error < 0 )
goto V_33;
V_2 -> V_10 = V_9 ;
V_22 -> V_36 = L_4 ;
V_22 -> V_37 . V_38 = 1 ;
V_22 -> V_6 . V_7 = & V_30 -> V_6 ;
V_22 -> V_39 = F_9 ;
F_19 ( V_22 , V_2 ) ;
F_20 ( V_2 -> V_34 , V_40 , V_41 ) ;
error = F_21 ( V_22 , NULL ,
F_12 ) ;
if ( error ) {
F_17 ( & V_30 -> V_6 ,
L_5 ) ;
goto V_33;
}
error = F_22 ( V_22 ) ;
if ( error ) {
F_17 ( & V_30 -> V_6 , L_6 ) ;
goto V_42;
}
F_23 ( V_30 , V_2 ) ;
return 0 ;
V_42:
F_24 ( V_22 ) ;
V_33:
F_25 ( V_22 ) ;
F_26 ( V_2 ) ;
return error ;
}
static int T_4 F_27 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_28 ( V_30 ) ;
F_29 ( V_2 -> V_34 ) ;
F_26 ( V_2 ) ;
F_23 ( V_30 , NULL ) ;
return 0 ;
}
static int F_30 ( struct V_43 * V_6 )
{
struct V_1 * V_2 = F_31 ( V_6 ) ;
F_6 ( V_2 , false ) ;
return 0 ;
}
static int T_5 F_32 ( void )
{
return F_33 ( & V_44 ) ;
}
static void T_6 F_34 ( void )
{
F_35 ( & V_44 ) ;
}

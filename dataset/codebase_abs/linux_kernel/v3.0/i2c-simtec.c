static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
F_2 ( V_5 | ( V_2 ? V_6 : 0 ) , V_4 -> V_7 ) ;
}
static void F_3 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
F_2 ( V_8 | ( V_2 ? V_9 : 0 ) , V_4 -> V_7 ) ;
}
static int F_4 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
return F_5 ( V_4 -> V_7 ) & V_6 ? 1 : 0 ;
}
static int F_6 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
return F_5 ( V_4 -> V_7 ) & V_9 ? 1 : 0 ;
}
static int F_7 ( struct V_10 * V_11 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
int V_14 ;
int V_15 ;
V_4 = F_8 ( sizeof( struct V_3 ) , V_16 ) ;
if ( V_4 == NULL ) {
F_9 ( & V_11 -> V_11 , L_1 ) ;
return - V_17 ;
}
F_10 ( V_11 , V_4 ) ;
V_13 = F_11 ( V_11 , V_18 , 0 ) ;
if ( V_13 == NULL ) {
F_9 ( & V_11 -> V_11 , L_2 ) ;
V_15 = - V_19 ;
goto V_20;
}
V_14 = F_12 ( V_13 ) ;
V_4 -> V_21 = F_13 ( V_13 -> V_22 , V_14 , V_11 -> V_23 ) ;
if ( V_4 -> V_21 == NULL ) {
F_9 ( & V_11 -> V_11 , L_3 ) ;
V_15 = - V_24 ;
goto V_20;
}
V_4 -> V_7 = F_14 ( V_13 -> V_22 , V_14 ) ;
if ( V_4 -> V_7 == NULL ) {
F_9 ( & V_11 -> V_11 , L_4 ) ;
V_15 = - V_24 ;
goto V_25;
}
V_4 -> V_26 . V_27 = V_28 ;
V_4 -> V_26 . V_29 = & V_4 -> V_30 ;
V_4 -> V_26 . V_11 . V_31 = & V_11 -> V_11 ;
F_15 ( V_4 -> V_26 . V_23 , L_5 , sizeof( V_4 -> V_26 . V_23 ) ) ;
V_4 -> V_30 . V_32 = V_4 ;
V_4 -> V_30 . V_33 = F_1 ;
V_4 -> V_30 . V_34 = F_3 ;
V_4 -> V_30 . V_35 = F_4 ;
V_4 -> V_30 . V_36 = F_6 ;
V_4 -> V_30 . V_37 = V_38 ;
V_4 -> V_30 . V_39 = 20 ;
V_15 = F_16 ( & V_4 -> V_26 ) ;
if ( V_15 )
goto V_40;
return 0 ;
V_40:
F_17 ( V_4 -> V_7 ) ;
V_25:
F_18 ( V_4 -> V_21 ) ;
F_19 ( V_4 -> V_21 ) ;
V_20:
F_19 ( V_4 ) ;
return V_15 ;
}
static int F_20 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_21 ( V_11 ) ;
F_22 ( & V_4 -> V_26 ) ;
F_17 ( V_4 -> V_7 ) ;
F_18 ( V_4 -> V_21 ) ;
F_19 ( V_4 -> V_21 ) ;
F_19 ( V_4 ) ;
return 0 ;
}
static int T_1 F_23 ( void )
{
return F_24 ( & V_41 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_41 ) ;
}

static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
F_2 ( V_5 , V_4 -> V_6 + ( V_2 ? V_7 : V_8 ) ) ;
}
static void F_3 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
F_2 ( V_9 , V_4 -> V_6 + ( V_2 ? V_7 : V_8 ) ) ;
}
static int F_4 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
return ! ! ( F_5 ( V_4 -> V_6 + V_10 ) & V_5 ) ;
}
static int F_6 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
return ! ! ( F_5 ( V_4 -> V_6 + V_10 ) & V_9 ) ;
}
static int F_7 ( struct V_11 * V_12 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
int V_15 ;
V_14 = F_8 ( V_12 , V_16 , 0 ) ;
if ( ! V_14 ) {
V_15 = - V_17 ;
goto V_18;
}
if ( ! F_9 ( V_14 -> V_19 , F_10 ( V_14 ) , L_1 ) ) {
V_15 = - V_20 ;
goto V_18;
}
V_4 = F_11 ( sizeof( struct V_3 ) , V_21 ) ;
if ( ! V_4 ) {
V_15 = - V_22 ;
goto V_23;
}
V_4 -> V_6 = F_12 ( V_14 -> V_19 , F_10 ( V_14 ) ) ;
if ( ! V_4 -> V_6 ) {
V_15 = - V_22 ;
goto V_24;
}
F_2 ( V_9 | V_5 , V_4 -> V_6 + V_7 ) ;
V_4 -> V_25 . V_26 = V_27 ;
F_13 ( V_4 -> V_25 . V_28 , L_2 , sizeof( V_4 -> V_25 . V_28 ) ) ;
V_4 -> V_25 . V_29 = & V_4 -> V_30 ;
V_4 -> V_25 . V_12 . V_31 = & V_12 -> V_12 ;
V_4 -> V_25 . V_12 . V_32 = V_12 -> V_12 . V_32 ;
V_4 -> V_30 = V_33 ;
V_4 -> V_30 . V_1 = V_4 ;
V_4 -> V_25 . V_34 = V_12 -> V_35 ;
V_15 = F_14 ( & V_4 -> V_25 ) ;
if ( V_15 >= 0 ) {
F_15 ( V_12 , V_4 ) ;
F_16 ( & V_4 -> V_25 ) ;
return 0 ;
}
F_17 ( V_4 -> V_6 ) ;
V_24:
F_18 ( V_4 ) ;
V_23:
F_19 ( V_14 -> V_19 , F_10 ( V_14 ) ) ;
V_18:
return V_15 ;
}
static int F_20 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = F_21 ( V_12 ) ;
F_22 ( & V_4 -> V_25 ) ;
return 0 ;
}
static int T_1 F_23 ( void )
{
return F_24 ( & V_36 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_36 ) ;
}

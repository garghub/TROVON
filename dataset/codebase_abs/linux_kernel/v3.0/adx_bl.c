static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = V_2 -> V_6 . V_7 ;
F_3 ( V_5 , V_4 -> V_8 + V_9 ) ;
V_5 = F_4 ( V_4 -> V_8 + V_10 ) ;
if ( V_2 -> V_6 . V_11 & V_12 )
V_5 &= ~ V_13 ;
else
V_5 |= V_13 ;
F_3 ( V_5 , V_4 -> V_8 + V_10 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_4 -> V_8 + V_9 ) ;
return V_7 & 0xff ;
}
static int F_6 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
return 1 ;
}
static int T_2 F_7 ( struct V_16 * V_17 )
{
struct V_18 V_6 ;
struct V_1 * V_2 ;
struct V_19 * V_20 ;
struct V_3 * V_4 ;
int V_21 = 0 ;
V_20 = F_8 ( V_17 , V_22 , 0 ) ;
if ( ! V_20 ) {
V_21 = - V_23 ;
goto V_24;
}
V_20 = F_9 ( & V_17 -> V_25 , V_20 -> V_26 ,
F_10 ( V_20 ) , V_20 -> V_27 ) ;
if ( ! V_20 ) {
V_21 = - V_23 ;
goto V_24;
}
V_4 = F_11 ( & V_17 -> V_25 , sizeof( * V_4 ) , V_28 ) ;
if ( ! V_4 ) {
V_21 = - V_29 ;
goto V_24;
}
V_4 -> V_8 = F_12 ( & V_17 -> V_25 , V_20 -> V_26 ,
F_10 ( V_20 ) ) ;
if ( ! V_4 -> V_8 ) {
V_21 = - V_23 ;
goto V_24;
}
memset ( & V_6 , 0 , sizeof( struct V_18 ) ) ;
V_6 . type = V_30 ;
V_6 . V_31 = 0xff ;
V_2 = F_13 ( F_14 ( & V_17 -> V_25 ) , & V_17 -> V_25 ,
V_4 , & V_32 , & V_6 ) ;
if ( F_15 ( V_2 ) ) {
V_21 = F_16 ( V_2 ) ;
goto V_24;
}
V_2 -> V_6 . V_7 = 0xff ;
V_2 -> V_6 . V_33 = V_34 ;
F_17 ( V_17 , V_2 ) ;
V_24:
return V_21 ;
}
static int T_3 F_18 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
int V_21 = 0 ;
V_2 = F_19 ( V_17 ) ;
V_2 -> V_6 . V_33 = V_34 ;
V_2 -> V_6 . V_7 = 0xff ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_17 ( V_17 , NULL ) ;
return V_21 ;
}
static int F_22 ( struct V_16 * V_17 ,
T_4 V_11 )
{
return 0 ;
}
static int F_23 ( struct V_16 * V_17 )
{
return 0 ;
}
static int T_5 F_24 ( void )
{
return F_25 ( & V_35 ) ;
}
static void T_6 F_26 ( void )
{
F_27 ( & V_35 ) ;
}

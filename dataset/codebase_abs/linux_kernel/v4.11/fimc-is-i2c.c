static T_1 F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static int F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 . V_9 ;
struct V_10 * V_11 ;
struct V_1 * V_12 ;
int V_13 ;
V_11 = F_3 ( & V_5 -> V_8 , sizeof( * V_11 ) , V_14 ) ;
if ( ! V_11 )
return - V_15 ;
V_11 -> clock = F_4 ( & V_5 -> V_8 , L_1 ) ;
if ( F_5 ( V_11 -> clock ) ) {
F_6 ( & V_5 -> V_8 , L_2 ) ;
return F_7 ( V_11 -> clock ) ;
}
V_12 = & V_11 -> V_16 ;
V_12 -> V_8 . V_9 = V_7 ;
V_12 -> V_8 . V_17 = & V_5 -> V_8 ;
F_8 ( V_12 -> V_18 , L_3 , sizeof( V_12 -> V_18 ) ) ;
V_12 -> V_19 = V_20 ;
V_12 -> V_21 = & V_22 ;
V_12 -> V_23 = V_24 ;
F_9 ( V_5 , V_11 ) ;
F_10 ( & V_5 -> V_8 ) ;
V_13 = F_11 ( V_12 ) ;
if ( V_13 < 0 )
goto V_25;
F_12 ( & V_12 -> V_8 , false ) ;
return 0 ;
V_25:
F_13 ( & V_5 -> V_8 ) ;
return V_13 ;
}
static int F_14 ( struct V_4 * V_5 )
{
struct V_10 * V_11 = F_15 ( V_5 ) ;
F_13 ( & V_5 -> V_8 ) ;
F_16 ( & V_11 -> V_16 ) ;
return 0 ;
}
static int F_17 ( struct V_26 * V_8 )
{
struct V_10 * V_11 = F_18 ( V_8 ) ;
F_19 ( V_11 -> clock ) ;
return 0 ;
}
static int F_20 ( struct V_26 * V_8 )
{
struct V_10 * V_11 = F_18 ( V_8 ) ;
return F_21 ( V_11 -> clock ) ;
}
static int F_22 ( struct V_26 * V_8 )
{
if ( F_23 ( V_8 ) )
return 0 ;
return F_17 ( V_8 ) ;
}
static int F_24 ( struct V_26 * V_8 )
{
if ( F_23 ( V_8 ) )
return 0 ;
return F_20 ( V_8 ) ;
}
int F_25 ( void )
{
return F_26 ( & V_27 ) ;
}
void F_27 ( void )
{
F_28 ( & V_27 ) ;
}

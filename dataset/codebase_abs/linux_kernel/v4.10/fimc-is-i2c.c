static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_8 = F_2 ( & V_2 -> V_5 , sizeof( * V_8 ) , V_12 ) ;
if ( ! V_8 )
return - V_13 ;
V_8 -> clock = F_3 ( & V_2 -> V_5 , L_1 ) ;
if ( F_4 ( V_8 -> clock ) ) {
F_5 ( & V_2 -> V_5 , L_2 ) ;
return F_6 ( V_8 -> clock ) ;
}
V_10 = & V_8 -> V_14 ;
V_10 -> V_5 . V_6 = V_4 ;
V_10 -> V_5 . V_15 = & V_2 -> V_5 ;
F_7 ( V_10 -> V_16 , L_3 , sizeof( V_10 -> V_16 ) ) ;
V_10 -> V_17 = V_18 ;
V_10 -> V_19 = & V_20 ;
V_10 -> V_21 = V_22 ;
F_8 ( V_2 , V_8 ) ;
F_9 ( & V_2 -> V_5 ) ;
V_11 = F_10 ( V_10 ) ;
if ( V_11 < 0 )
goto V_23;
F_11 ( & V_10 -> V_5 , false ) ;
return 0 ;
V_23:
F_12 ( & V_2 -> V_5 ) ;
return V_11 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_14 ( V_2 ) ;
F_12 ( & V_2 -> V_5 ) ;
F_15 ( & V_8 -> V_14 ) ;
return 0 ;
}
static int F_16 ( struct V_24 * V_5 )
{
struct V_7 * V_8 = F_17 ( V_5 ) ;
F_18 ( V_8 -> clock ) ;
return 0 ;
}
static int F_19 ( struct V_24 * V_5 )
{
struct V_7 * V_8 = F_17 ( V_5 ) ;
return F_20 ( V_8 -> clock ) ;
}
static int F_21 ( struct V_24 * V_5 )
{
if ( F_22 ( V_5 ) )
return 0 ;
return F_16 ( V_5 ) ;
}
static int F_23 ( struct V_24 * V_5 )
{
if ( F_22 ( V_5 ) )
return 0 ;
return F_19 ( V_5 ) ;
}
int F_24 ( void )
{
return F_25 ( & V_25 ) ;
}
void F_26 ( void )
{
F_27 ( & V_25 ) ;
}

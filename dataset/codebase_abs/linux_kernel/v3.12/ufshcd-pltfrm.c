static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_4 ( V_6 -> V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_6 ( V_6 -> V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_8 ( V_2 ) ;
if ( ! V_6 )
return 0 ;
return F_9 ( V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_8 ( V_2 ) ;
if ( ! V_6 )
return 0 ;
return F_11 ( V_6 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_8 ( V_2 ) ;
if ( ! V_6 )
return 0 ;
return F_13 ( V_6 ) ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
void T_1 * V_8 ;
struct V_9 * V_10 ;
int V_7 , V_11 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
V_10 = F_15 ( V_4 , V_12 , 0 ) ;
V_8 = F_16 ( V_2 , V_10 ) ;
if ( F_17 ( V_8 ) ) {
V_11 = F_18 ( V_8 ) ;
goto V_13;
}
V_7 = F_19 ( V_4 , 0 ) ;
if ( V_7 < 0 ) {
F_20 ( V_2 , L_1 ) ;
V_11 = - V_14 ;
goto V_13;
}
F_21 ( & V_4 -> V_2 ) ;
F_22 ( & V_4 -> V_2 ) ;
V_11 = F_23 ( V_2 , & V_6 , V_8 , V_7 ) ;
if ( V_11 ) {
F_20 ( V_2 , L_2 ) ;
goto V_15;
}
F_24 ( V_4 , V_6 ) ;
return 0 ;
V_15:
F_25 ( & V_4 -> V_2 ) ;
F_26 ( & V_4 -> V_2 ) ;
V_13:
return V_11 ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_28 ( & ( V_4 ) -> V_2 ) ;
F_29 ( V_6 ) ;
return 0 ;
}

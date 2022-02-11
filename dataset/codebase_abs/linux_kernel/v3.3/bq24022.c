static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , L_1 ,
V_4 >= 500000 ? L_2 : L_3 ) ;
F_5 ( V_6 -> V_7 , V_4 >= 500000 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_7 ( V_6 -> V_7 ) ? 500000 : 100000 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , L_4 ) ;
F_5 ( V_6 -> V_8 , 0 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , L_5 ) ;
F_5 ( V_6 -> V_8 , 1 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return ! F_7 ( V_6 -> V_8 ) ;
}
static int T_1 F_11 ( struct V_9 * V_10 )
{
struct V_5 * V_6 = V_10 -> V_11 . V_12 ;
struct V_1 * V_13 ;
int V_14 ;
if ( ! V_6 || ! V_6 -> V_8 || ! V_6 -> V_7 )
return - V_15 ;
V_14 = F_12 ( V_6 -> V_8 , L_6 ) ;
if ( V_14 ) {
F_3 ( & V_10 -> V_11 , L_7 ,
V_6 -> V_8 ) ;
goto V_16;
}
V_14 = F_12 ( V_6 -> V_7 , L_8 ) ;
if ( V_14 ) {
F_3 ( & V_10 -> V_11 , L_9 ,
V_6 -> V_7 ) ;
goto V_17;
}
V_14 = F_13 ( V_6 -> V_7 , 0 ) ;
V_14 = F_13 ( V_6 -> V_8 , 1 ) ;
V_13 = F_14 ( & V_18 , & V_10 -> V_11 ,
V_6 -> V_19 , V_6 , NULL ) ;
if ( F_15 ( V_13 ) ) {
F_3 ( & V_10 -> V_11 , L_10 ) ;
V_14 = F_16 ( V_13 ) ;
goto V_20;
}
F_17 ( V_10 , V_13 ) ;
F_3 ( & V_10 -> V_11 , L_11 ) ;
return 0 ;
V_20:
F_18 ( V_6 -> V_7 ) ;
V_17:
F_18 ( V_6 -> V_8 ) ;
V_16:
return V_14 ;
}
static int T_2 F_19 ( struct V_9 * V_10 )
{
struct V_5 * V_6 = V_10 -> V_11 . V_12 ;
struct V_1 * V_13 = F_20 ( V_10 ) ;
F_21 ( V_13 ) ;
F_18 ( V_6 -> V_7 ) ;
F_18 ( V_6 -> V_8 ) ;
return 0 ;
}
static int T_1 F_22 ( void )
{
return F_23 ( & V_21 , F_11 ) ;
}
static void T_3 F_24 ( void )
{
F_25 ( & V_21 ) ;
}

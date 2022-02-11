static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_2 ( V_2 -> V_5 ) ;
F_2 ( V_2 -> V_6 ) ;
}
static int F_3 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 -> V_10 ;
int V_11 = 0 ;
F_4 ( V_12 L_1 , V_13 ) ;
V_11 = F_5 ( V_2 -> V_3 , L_2 ) ;
if ( V_11 == 0 )
V_11 = F_6 ( V_2 -> V_3 , 1 ) ;
if ( V_11 != 0 )
goto V_14;
V_11 = F_5 ( V_2 -> V_4 , L_3 ) ;
if ( V_11 == 0 )
V_11 = F_6 ( V_2 -> V_4 , 0 ) ;
if ( V_11 != 0 )
goto V_14;
V_11 = F_5 ( V_2 -> V_5 , L_4 ) ;
if ( V_11 == 0 )
V_11 = F_6 ( V_2 -> V_5 , 1 ) ;
if ( V_11 != 0 )
goto V_14;
V_11 = F_5 ( V_2 -> V_6 , L_5 ) ;
if ( V_11 == 0 )
V_11 = F_6 ( V_2 -> V_6 , 1 ) ;
if ( V_11 != 0 )
goto V_14;
return V_11 ;
V_14:
F_1 ( V_2 ) ;
return V_11 ;
}
static int F_7 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 -> V_10 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 -> V_10 ;
F_9 ( V_2 -> V_5 , 0 ) ;
F_9 ( V_2 -> V_6 , 0 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 -> V_10 ;
F_9 ( V_2 -> V_5 , 1 ) ;
F_9 ( V_2 -> V_6 , 1 ) ;
return 0 ;
}
static int T_1 F_11 ( struct V_15 * V_16 )
{
return F_12 ( & V_16 -> V_9 ,
& V_17 , & V_18 , 1 ) ;
}
static int T_2 F_13 ( struct V_15 * V_16 )
{
F_14 ( & V_16 -> V_9 ) ;
return 0 ;
}

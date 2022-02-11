static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 ,
bool V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
T_2 * V_8 = V_3 ;
if ( F_3 ( V_7 -> V_9 + V_10 ) & 1 ) {
* V_8 = F_3 ( V_7 -> V_9 + V_10 ) ;
return 4 ;
} else
return 0 ;
}
static int F_4 ( struct V_11 * V_12 )
{
struct V_6 * V_7 ;
struct V_13 * V_14 ;
int V_15 ;
V_14 = F_5 ( V_12 , V_16 , 0 ) ;
if ( ! V_14 )
return - V_17 ;
V_7 = F_6 ( & V_12 -> V_18 , sizeof( * V_7 ) , V_19 ) ;
if ( ! V_7 )
return - V_20 ;
if ( ! F_7 ( & V_12 -> V_18 , V_14 -> V_21 ,
F_8 ( V_14 ) , V_12 -> V_22 ) )
return - V_23 ;
V_7 -> V_9 = F_9 ( & V_12 -> V_18 , V_14 -> V_21 , F_8 ( V_14 ) ) ;
if ( ! V_7 -> V_9 )
return - V_23 ;
V_7 -> V_24 = F_10 ( & V_12 -> V_18 , NULL ) ;
if ( F_11 ( V_7 -> V_24 ) )
return F_12 ( V_7 -> V_24 ) ;
V_15 = F_13 ( V_7 -> V_24 ) ;
if ( V_15 )
goto V_25;
F_14 ( V_26 | 1 , V_7 -> V_9 + V_27 ) ;
V_7 -> V_2 . V_22 = V_12 -> V_22 ;
V_7 -> V_2 . V_28 = F_1 ;
V_15 = F_15 ( & V_7 -> V_2 ) ;
if ( V_15 )
goto V_29;
F_16 ( V_12 , V_7 ) ;
return 0 ;
V_29:
F_17 ( V_7 -> V_24 ) ;
V_25:
F_18 ( V_7 -> V_24 ) ;
return V_15 ;
}
static int T_3 F_19 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_20 ( V_12 ) ;
F_21 ( & V_7 -> V_2 ) ;
F_14 ( V_26 , V_7 -> V_9 + V_27 ) ;
F_17 ( V_7 -> V_24 ) ;
F_18 ( V_7 -> V_24 ) ;
F_16 ( V_12 , NULL ) ;
return 0 ;
}
static int F_22 ( struct V_30 * V_18 )
{
struct V_6 * V_7 = F_23 ( V_18 ) ;
F_17 ( V_7 -> V_24 ) ;
return 0 ;
}
static int F_24 ( struct V_30 * V_18 )
{
struct V_6 * V_7 = F_23 ( V_18 ) ;
return F_13 ( V_7 -> V_24 ) ;
}
static int T_4 F_25 ( void )
{
return F_26 ( & V_31 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_31 ) ;
}

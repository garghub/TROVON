static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
int V_4 ;
V_4 = V_3 -> V_5 . V_6 ;
if ( V_4 )
goto V_7;
V_4 = F_2 ( V_3 ) ;
if ( V_4 )
goto V_7;
return;
V_7:
F_3 ( & V_3 -> V_8 -> V_9 , L_1 ) ;
F_4 ( & V_3 -> V_10 ) ;
}
static int F_2 ( struct V_2 * V_3 )
{
T_1 V_11 ;
int V_4 ;
T_2 V_12 ;
V_12 = F_5 () ;
V_11 = F_6 ( V_12 , 1000000000 ) / 1000 ;
V_3 -> V_13 [ 0 ] = F_7 ( V_12 ) ;
V_3 -> V_13 [ 1 ] = F_7 ( V_11 ) ;
F_8 ( & V_3 -> V_5 , & V_3 -> V_14 , 1 ) ;
V_3 -> V_5 . F_4 = F_1 ;
V_3 -> V_5 . V_15 = V_3 ;
V_4 = F_9 ( V_3 -> V_8 , & V_3 -> V_5 ) ;
if ( V_4 )
F_10 ( & V_3 -> V_8 -> V_9 , L_2 , V_4 ) ;
return V_4 ;
}
static int F_11 ( struct V_16 * V_8 )
{
struct V_2 * V_3 ;
int V_4 ;
V_3 = F_12 ( & V_8 -> V_9 , sizeof( * V_3 ) , V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_3 -> V_8 = V_8 ;
F_13 ( & V_3 -> V_10 ) ;
V_3 -> V_14 . V_19 = V_3 -> V_13 ;
V_3 -> V_14 . V_20 = sizeof( V_3 -> V_13 ) ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 )
return V_4 ;
F_14 ( V_8 , V_3 ) ;
return 0 ;
}
static int F_15 ( struct V_16 * V_8 )
{
struct V_2 * V_3 = F_16 ( V_8 ) ;
F_17 ( V_8 ) ;
F_18 ( & V_3 -> V_10 ) ;
return 0 ;
}

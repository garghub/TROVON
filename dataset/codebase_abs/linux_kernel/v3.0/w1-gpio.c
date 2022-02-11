static void F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_2 )
F_2 ( V_4 -> V_5 ) ;
else
F_3 ( V_4 -> V_5 , 0 ) ;
}
static void F_4 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
F_5 ( V_4 -> V_5 , V_2 ) ;
}
static T_1 F_6 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
return F_7 ( V_4 -> V_5 ) ? 1 : 0 ;
}
static int T_2 F_8 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_3 * V_4 = V_7 -> V_10 . V_11 ;
int V_12 ;
if ( ! V_4 )
return - V_13 ;
V_9 = F_9 ( sizeof( struct V_8 ) , V_14 ) ;
if ( ! V_9 )
return - V_15 ;
V_12 = F_10 ( V_4 -> V_5 , L_1 ) ;
if ( V_12 )
goto V_16;
V_9 -> V_1 = V_4 ;
V_9 -> V_17 = F_6 ;
if ( V_4 -> V_18 ) {
F_3 ( V_4 -> V_5 , 1 ) ;
V_9 -> V_19 = F_4 ;
} else {
F_2 ( V_4 -> V_5 ) ;
V_9 -> V_19 = F_1 ;
}
V_12 = F_11 ( V_9 ) ;
if ( V_12 )
goto V_20;
if ( V_4 -> V_21 )
V_4 -> V_21 ( 1 ) ;
F_12 ( V_7 , V_9 ) ;
return 0 ;
V_20:
F_13 ( V_4 -> V_5 ) ;
V_16:
F_14 ( V_9 ) ;
return V_12 ;
}
static int T_3 F_15 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_16 ( V_7 ) ;
struct V_3 * V_4 = V_7 -> V_10 . V_11 ;
if ( V_4 -> V_21 )
V_4 -> V_21 ( 0 ) ;
F_17 ( V_9 ) ;
F_13 ( V_4 -> V_5 ) ;
F_14 ( V_9 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 , T_4 V_22 )
{
struct V_3 * V_4 = V_7 -> V_10 . V_11 ;
if ( V_4 -> V_21 )
V_4 -> V_21 ( 0 ) ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_10 . V_11 ;
if ( V_4 -> V_21 )
V_4 -> V_21 ( 1 ) ;
return 0 ;
}
static int T_2 F_20 ( void )
{
return F_21 ( & V_23 , F_8 ) ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_23 ) ;
}

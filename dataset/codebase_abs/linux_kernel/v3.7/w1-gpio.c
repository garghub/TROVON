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
static int F_8 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_8 . V_9 ;
struct V_10 * V_11 = V_7 -> V_8 . V_12 ;
const struct V_13 * V_14 =
F_9 ( V_15 , & V_7 -> V_8 ) ;
if ( ! V_14 )
return 0 ;
V_4 = F_10 ( & V_7 -> V_8 , sizeof( * V_4 ) , V_16 ) ;
if ( ! V_4 )
return - V_17 ;
if ( F_11 ( V_11 , L_1 , NULL ) )
V_4 -> V_18 = 1 ;
V_4 -> V_5 = F_12 ( V_11 , 0 ) ;
V_4 -> V_19 = F_12 ( V_11 , 1 ) ;
V_7 -> V_8 . V_9 = V_4 ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 )
{
return 0 ;
}
static int T_2 F_13 ( struct V_6 * V_7 )
{
struct V_20 * V_21 ;
struct V_3 * V_4 ;
int V_22 ;
V_22 = F_8 ( V_7 ) ;
if ( V_22 < 0 )
return V_22 ;
V_4 = V_7 -> V_8 . V_9 ;
if ( ! V_4 )
return - V_23 ;
V_21 = F_14 ( sizeof( struct V_20 ) , V_16 ) ;
if ( ! V_21 )
return - V_17 ;
V_22 = F_15 ( V_4 -> V_5 , L_2 ) ;
if ( V_22 )
goto V_24;
if ( F_16 ( V_4 -> V_19 ) ) {
V_22 = F_17 ( V_4 -> V_19 ,
V_25 , L_3 ) ;
if ( V_22 < 0 )
goto V_26;
}
V_21 -> V_1 = V_4 ;
V_21 -> V_27 = F_6 ;
if ( V_4 -> V_18 ) {
F_3 ( V_4 -> V_5 , 1 ) ;
V_21 -> V_28 = F_4 ;
} else {
F_2 ( V_4 -> V_5 ) ;
V_21 -> V_28 = F_1 ;
}
V_22 = F_18 ( V_21 ) ;
if ( V_22 )
goto V_29;
if ( V_4 -> V_30 )
V_4 -> V_30 ( 1 ) ;
if ( F_16 ( V_4 -> V_19 ) )
F_5 ( V_4 -> V_19 , 1 ) ;
F_19 ( V_7 , V_21 ) ;
return 0 ;
V_29:
if ( F_16 ( V_4 -> V_19 ) )
F_20 ( V_4 -> V_19 ) ;
V_26:
F_20 ( V_4 -> V_5 ) ;
V_24:
F_21 ( V_21 ) ;
return V_22 ;
}
static int T_3 F_22 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = F_23 ( V_7 ) ;
struct V_3 * V_4 = V_7 -> V_8 . V_9 ;
if ( V_4 -> V_30 )
V_4 -> V_30 ( 0 ) ;
if ( F_16 ( V_4 -> V_19 ) )
F_5 ( V_4 -> V_19 , 0 ) ;
F_24 ( V_21 ) ;
F_20 ( V_4 -> V_5 ) ;
F_21 ( V_21 ) ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 , T_4 V_31 )
{
struct V_3 * V_4 = V_7 -> V_8 . V_9 ;
if ( V_4 -> V_30 )
V_4 -> V_30 ( 0 ) ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_8 . V_9 ;
if ( V_4 -> V_30 )
V_4 -> V_30 ( 1 ) ;
return 0 ;
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_32 , F_13 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_32 ) ;
}

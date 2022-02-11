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
V_4 = F_9 ( & V_7 -> V_8 , sizeof( * V_4 ) , V_13 ) ;
if ( ! V_4 )
return - V_14 ;
if ( F_10 ( V_11 , L_1 , NULL ) )
V_4 -> V_15 = 1 ;
V_4 -> V_5 = F_11 ( V_11 , 0 ) ;
V_4 -> V_16 = F_11 ( V_11 , 1 ) ;
V_7 -> V_8 . V_9 = V_4 ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_17 * V_18 ;
struct V_3 * V_4 ;
struct V_19 * V_19 ;
int V_20 ;
V_19 = F_13 ( & V_7 -> V_8 ) ;
if ( F_14 ( V_19 ) )
F_15 ( & V_7 -> V_8 , L_2 ) ;
if ( F_16 () ) {
V_20 = F_8 ( V_7 ) ;
if ( V_20 < 0 ) {
F_17 ( & V_7 -> V_8 , L_3 ) ;
return V_20 ;
}
}
V_4 = V_7 -> V_8 . V_9 ;
if ( ! V_4 ) {
F_17 ( & V_7 -> V_8 , L_4 ) ;
return - V_21 ;
}
V_18 = F_18 ( sizeof( struct V_17 ) , V_13 ) ;
if ( ! V_18 ) {
F_17 ( & V_7 -> V_8 , L_5 ) ;
return - V_14 ;
}
V_20 = F_19 ( V_4 -> V_5 , L_6 ) ;
if ( V_20 ) {
F_17 ( & V_7 -> V_8 , L_7 ) ;
goto V_22;
}
if ( F_20 ( V_4 -> V_16 ) ) {
V_20 = F_21 ( V_4 -> V_16 ,
V_23 , L_8 ) ;
if ( V_20 < 0 ) {
F_17 ( & V_7 -> V_8 , L_9
L_10 ) ;
goto V_24;
}
}
V_18 -> V_1 = V_4 ;
V_18 -> V_25 = F_6 ;
if ( V_4 -> V_15 ) {
F_3 ( V_4 -> V_5 , 1 ) ;
V_18 -> V_26 = F_4 ;
} else {
F_2 ( V_4 -> V_5 ) ;
V_18 -> V_26 = F_1 ;
}
V_20 = F_22 ( V_18 ) ;
if ( V_20 ) {
F_17 ( & V_7 -> V_8 , L_11 ) ;
goto V_27;
}
if ( V_4 -> V_28 )
V_4 -> V_28 ( 1 ) ;
if ( F_20 ( V_4 -> V_16 ) )
F_5 ( V_4 -> V_16 , 1 ) ;
F_23 ( V_7 , V_18 ) ;
return 0 ;
V_27:
if ( F_20 ( V_4 -> V_16 ) )
F_24 ( V_4 -> V_16 ) ;
V_24:
F_24 ( V_4 -> V_5 ) ;
V_22:
F_25 ( V_18 ) ;
return V_20 ;
}
static int F_26 ( struct V_6 * V_7 )
{
struct V_17 * V_18 = F_27 ( V_7 ) ;
struct V_3 * V_4 = V_7 -> V_8 . V_9 ;
if ( V_4 -> V_28 )
V_4 -> V_28 ( 0 ) ;
if ( F_20 ( V_4 -> V_16 ) )
F_5 ( V_4 -> V_16 , 0 ) ;
F_28 ( V_18 ) ;
F_24 ( V_4 -> V_5 ) ;
F_25 ( V_18 ) ;
return 0 ;
}
static int F_29 ( struct V_6 * V_7 , T_2 V_29 )
{
struct V_3 * V_4 = V_7 -> V_8 . V_9 ;
if ( V_4 -> V_28 )
V_4 -> V_28 ( 0 ) ;
return 0 ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_8 . V_9 ;
if ( V_4 -> V_28 )
V_4 -> V_28 ( 1 ) ;
return 0 ;
}

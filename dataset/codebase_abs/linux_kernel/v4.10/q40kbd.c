static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned long V_4 ;
F_2 ( & V_3 -> V_5 , V_4 ) ;
if ( V_6 & F_3 ( V_7 ) )
F_4 ( V_3 -> V_8 , F_3 ( V_9 ) , 0 ) ;
F_5 ( - 1 , V_10 ) ;
F_6 ( & V_3 -> V_5 , V_4 ) ;
return V_11 ;
}
static void F_7 ( struct V_3 * V_3 )
{
int V_12 = 100 ;
unsigned long V_4 ;
F_2 ( & V_3 -> V_5 , V_4 ) ;
while ( V_12 -- && ( V_6 & F_3 ( V_7 ) ) )
F_3 ( V_9 ) ;
F_6 ( & V_3 -> V_5 , V_4 ) ;
}
static void F_8 ( void )
{
F_5 ( 0 , V_13 ) ;
F_5 ( - 1 , V_10 ) ;
}
static int F_9 ( struct V_14 * V_8 )
{
struct V_3 * V_3 = V_8 -> V_15 ;
F_7 ( V_3 ) ;
F_5 ( - 1 , V_10 ) ;
F_5 ( 1 , V_13 ) ;
return 0 ;
}
static void F_10 ( struct V_14 * V_8 )
{
struct V_3 * V_3 = V_8 -> V_15 ;
F_8 () ;
F_7 ( V_3 ) ;
}
static int F_11 ( struct V_16 * V_17 )
{
struct V_3 * V_3 ;
struct V_14 * V_8 ;
int error ;
V_3 = F_12 ( sizeof( struct V_3 ) , V_18 ) ;
V_8 = F_12 ( sizeof( struct V_14 ) , V_18 ) ;
if ( ! V_3 || ! V_8 ) {
error = - V_19 ;
goto V_20;
}
V_3 -> V_8 = V_8 ;
F_13 ( & V_3 -> V_5 ) ;
V_8 -> V_21 . type = V_22 ;
V_8 -> V_23 = F_9 ;
V_8 -> V_24 = F_10 ;
V_8 -> V_15 = V_3 ;
V_8 -> V_25 . V_26 = & V_17 -> V_25 ;
F_14 ( V_8 -> V_27 , L_1 , sizeof( V_8 -> V_27 ) ) ;
F_14 ( V_8 -> V_28 , L_2 , sizeof( V_8 -> V_28 ) ) ;
F_8 () ;
error = F_15 ( V_29 , F_1 , 0 ,
V_30 , V_3 ) ;
if ( error ) {
F_16 ( & V_17 -> V_25 , L_3 , V_29 ) ;
goto V_20;
}
F_17 ( V_3 -> V_8 ) ;
F_18 ( V_17 , V_3 ) ;
F_19 ( V_31 L_4 ) ;
return 0 ;
V_20:
F_20 ( V_8 ) ;
F_20 ( V_3 ) ;
return error ;
}
static int F_21 ( struct V_16 * V_17 )
{
struct V_3 * V_3 = F_22 ( V_17 ) ;
F_23 ( V_3 -> V_8 ) ;
F_24 ( V_29 , V_3 ) ;
F_20 ( V_3 ) ;
return 0 ;
}

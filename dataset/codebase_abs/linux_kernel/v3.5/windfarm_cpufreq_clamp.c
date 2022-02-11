static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
unsigned long V_7 ;
if ( V_3 != V_8 )
return 0 ;
V_7 = V_9 ? ( V_6 -> V_10 . V_11 ) : ( V_6 -> V_10 . V_7 ) ;
F_2 ( V_6 , 0 , V_7 ) ;
return 0 ;
}
static int F_3 ( struct V_12 * V_13 , T_1 V_14 )
{
if ( V_14 )
F_4 ( V_15 L_1
L_2 ) ;
else
F_4 ( V_15 L_3 ) ;
V_9 = V_14 ;
F_5 ( 0 ) ;
return 0 ;
}
static int F_6 ( struct V_12 * V_13 , T_1 * V_14 )
{
* V_14 = V_9 ;
return 0 ;
}
static T_1 F_7 ( struct V_12 * V_13 )
{
return 0 ;
}
static T_1 F_8 ( struct V_12 * V_13 )
{
return 1 ;
}
static int T_2 F_9 ( void )
{
struct V_12 * V_16 ;
V_16 = F_10 ( sizeof( struct V_12 ) , V_17 ) ;
if ( V_16 == NULL )
return - V_18 ;
F_11 ( & V_19 , V_20 ) ;
V_16 -> V_21 = & V_22 ;
V_16 -> V_23 = L_4 ;
if ( F_12 ( V_16 ) )
goto V_24;
V_25 = V_16 ;
return 0 ;
V_24:
F_13 ( V_16 ) ;
return - V_26 ;
}
static void T_3 F_14 ( void )
{
if ( V_25 )
F_15 ( V_25 ) ;
}

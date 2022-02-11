static int F_1 ( struct V_1 * V_2 , T_1 type , T_1 V_3 )
{
return 0 ;
}
static unsigned int F_2 ( struct V_4 * V_5 )
{
return V_5 -> V_6 ;
}
static int F_3 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_4 ( struct V_7 * V_8 , struct V_4 * V_5 )
{
struct V_9 V_10 ;
snprintf ( V_10 . type , V_11 , L_1 , L_2 ) ;
if ( F_5 ( V_8 , V_12 ,
sizeof( struct V_9 ) , & V_10 ) )
goto V_13;
return 0 ;
V_13:
return - V_14 ;
}
static int F_4 ( struct V_7 * V_8 , struct V_4 * V_5 )
{
return - V_15 ;
}
static void F_6 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
F_7 ( V_17 , L_3 ) ;
}
struct V_18 * F_8 ( const char * V_19 , T_1 type ,
T_1 V_3 )
{
return F_9 ( V_19 , & V_20 , type , V_3 ) ;
}
int F_10 ( struct V_21 * V_5 )
{
struct V_4 * V_22 = & V_5 -> V_22 ;
V_22 -> V_23 = & V_20 ;
V_22 -> V_24 &= ~ V_25 ;
V_22 -> V_24 |= V_26 ;
return F_11 ( V_22 ) ;
}
int F_12 ( struct V_21 * V_5 )
{
return F_13 ( & V_5 -> V_22 ) ;
}

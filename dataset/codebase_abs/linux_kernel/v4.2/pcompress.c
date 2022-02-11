static int F_1 ( struct V_1 * V_2 , T_1 type , T_1 V_3 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_3 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 V_9 ;
strncpy ( V_9 . type , L_1 , sizeof( V_9 . type ) ) ;
if ( F_4 ( V_5 , V_10 ,
sizeof( struct V_8 ) , & V_9 ) )
goto V_11;
return 0 ;
V_11:
return - V_12 ;
}
static int F_3 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
return - V_13 ;
}
static void F_5 ( struct V_14 * V_15 , struct V_6 * V_7 )
{
F_6 ( V_15 , L_2 ) ;
}
struct V_16 * F_7 ( const char * V_17 , T_1 type ,
T_1 V_3 )
{
return F_8 ( V_17 , & V_18 , type , V_3 ) ;
}
int F_9 ( struct V_19 * V_7 )
{
struct V_6 * V_20 = & V_7 -> V_20 ;
V_20 -> V_21 = & V_18 ;
V_20 -> V_22 &= ~ V_23 ;
V_20 -> V_22 |= V_24 ;
return F_10 ( V_20 ) ;
}
int F_11 ( struct V_19 * V_7 )
{
return F_12 ( & V_7 -> V_20 ) ;
}

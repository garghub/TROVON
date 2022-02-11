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
strncpy ( V_10 . type , L_1 , sizeof( V_10 . type ) ) ;
if ( F_5 ( V_8 , V_11 ,
sizeof( struct V_9 ) , & V_10 ) )
goto V_12;
return 0 ;
V_12:
return - V_13 ;
}
static int F_4 ( struct V_7 * V_8 , struct V_4 * V_5 )
{
return - V_14 ;
}
static void F_6 ( struct V_15 * V_16 , struct V_4 * V_5 )
{
F_7 ( V_16 , L_2 ) ;
}
struct V_17 * F_8 ( const char * V_18 , T_1 type ,
T_1 V_3 )
{
return F_9 ( V_18 , & V_19 , type , V_3 ) ;
}
int F_10 ( struct V_20 * V_5 )
{
struct V_4 * V_21 = & V_5 -> V_21 ;
V_21 -> V_22 = & V_19 ;
V_21 -> V_23 &= ~ V_24 ;
V_21 -> V_23 |= V_25 ;
return F_11 ( V_21 ) ;
}
int F_12 ( struct V_20 * V_5 )
{
return F_13 ( & V_5 -> V_21 ) ;
}

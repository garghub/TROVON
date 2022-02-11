static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
strncpy ( V_6 . type , L_1 , sizeof( V_6 . type ) ) ;
if ( F_2 ( V_2 , V_7 ,
sizeof( struct V_5 ) , & V_6 ) )
goto V_8;
return 0 ;
V_8:
return - V_9 ;
}
static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return - V_10 ;
}
static void F_3 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
F_4 ( V_12 , L_2 ) ;
}
static void F_5 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_6 ( V_14 ) ;
struct V_17 * V_4 = F_7 ( V_16 ) ;
V_4 -> exit ( V_16 ) ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_6 ( V_14 ) ;
struct V_17 * V_4 = F_7 ( V_16 ) ;
if ( V_4 -> exit )
V_16 -> V_18 . exit = F_5 ;
if ( V_4 -> V_19 )
return V_4 -> V_19 ( V_16 ) ;
return 0 ;
}
struct V_15 * F_9 ( const char * V_20 , T_1 type , T_1 V_21 )
{
return F_10 ( V_20 , & V_22 , type , V_21 ) ;
}
static void F_11 ( struct V_17 * V_4 )
{
struct V_3 * V_18 = & V_4 -> V_18 ;
V_18 -> V_23 = & V_22 ;
V_18 -> V_24 &= ~ V_25 ;
V_18 -> V_24 |= V_26 ;
}
int F_12 ( struct V_17 * V_4 )
{
struct V_3 * V_18 = & V_4 -> V_18 ;
F_11 ( V_4 ) ;
return F_13 ( V_18 ) ;
}
void F_14 ( struct V_17 * V_4 )
{
F_15 ( & V_4 -> V_18 ) ;
}

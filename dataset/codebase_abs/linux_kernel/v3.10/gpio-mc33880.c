static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , & V_2 -> V_4 , sizeof( V_2 -> V_4 ) ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned V_5 , int V_6 )
{
if ( V_6 )
V_2 -> V_4 |= 1 << V_5 ;
else
V_2 -> V_4 &= ~ ( 1 << V_5 ) ;
return F_1 ( V_2 ) ;
}
static void F_4 ( struct V_7 * V_8 , unsigned V_5 , int V_6 )
{
struct V_1 * V_2 = F_5 ( V_8 , struct V_1 , V_8 ) ;
F_6 ( & V_2 -> V_9 ) ;
F_3 ( V_2 , V_5 , V_6 ) ;
F_7 ( & V_2 -> V_9 ) ;
}
static int F_8 ( struct V_10 * V_3 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_13 ;
V_12 = V_3 -> V_14 . V_15 ;
if ( ! V_12 || ! V_12 -> V_16 ) {
F_9 ( & V_3 -> V_14 , L_1 ) ;
return - V_17 ;
}
V_3 -> V_18 = 8 ;
V_13 = F_10 ( V_3 ) ;
if ( V_13 < 0 )
return V_13 ;
V_2 = F_11 ( & V_3 -> V_14 , sizeof( struct V_1 ) , V_19 ) ;
if ( ! V_2 )
return - V_20 ;
F_12 ( & V_2 -> V_9 ) ;
F_13 ( V_3 , V_2 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_8 . V_21 = V_22 ,
V_2 -> V_8 . V_23 = F_4 ;
V_2 -> V_8 . V_16 = V_12 -> V_16 ;
V_2 -> V_8 . V_24 = V_25 ;
V_2 -> V_8 . V_26 = 1 ;
V_2 -> V_8 . V_14 = & V_3 -> V_14 ;
V_2 -> V_8 . V_27 = V_28 ;
V_2 -> V_4 = 0x00 ;
V_13 = F_1 ( V_2 ) ;
V_2 -> V_4 = 0x00 ;
if ( ! V_13 )
V_13 = F_1 ( V_2 ) ;
if ( V_13 ) {
F_14 ( & V_3 -> V_14 , L_2 V_22 L_3 ,
V_13 ) ;
goto V_29;
}
V_13 = F_15 ( & V_2 -> V_8 ) ;
if ( V_13 )
goto V_29;
return V_13 ;
V_29:
F_13 ( V_3 , NULL ) ;
F_16 ( & V_2 -> V_9 ) ;
return V_13 ;
}
static int F_17 ( struct V_10 * V_3 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_18 ( V_3 ) ;
if ( V_2 == NULL )
return - V_30 ;
F_13 ( V_3 , NULL ) ;
V_13 = F_19 ( & V_2 -> V_8 ) ;
if ( ! V_13 )
F_16 ( & V_2 -> V_9 ) ;
else
F_14 ( & V_3 -> V_14 , L_4 ,
V_13 ) ;
return V_13 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_31 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_31 ) ;
}

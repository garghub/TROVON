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
V_12 = F_9 ( & V_3 -> V_14 ) ;
if ( ! V_12 || ! V_12 -> V_15 ) {
F_10 ( & V_3 -> V_14 , L_1 ) ;
return - V_16 ;
}
V_3 -> V_17 = 8 ;
V_13 = F_11 ( V_3 ) ;
if ( V_13 < 0 )
return V_13 ;
V_2 = F_12 ( & V_3 -> V_14 , sizeof( struct V_1 ) , V_18 ) ;
if ( ! V_2 )
return - V_19 ;
F_13 ( & V_2 -> V_9 ) ;
F_14 ( V_3 , V_2 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_8 . V_20 = V_21 ,
V_2 -> V_8 . V_22 = F_4 ;
V_2 -> V_8 . V_15 = V_12 -> V_15 ;
V_2 -> V_8 . V_23 = V_24 ;
V_2 -> V_8 . V_25 = 1 ;
V_2 -> V_8 . V_14 = & V_3 -> V_14 ;
V_2 -> V_8 . V_26 = V_27 ;
V_2 -> V_4 = 0x00 ;
V_13 = F_1 ( V_2 ) ;
V_2 -> V_4 = 0x00 ;
if ( ! V_13 )
V_13 = F_1 ( V_2 ) ;
if ( V_13 ) {
F_15 ( & V_3 -> V_14 , L_2 V_21 L_3 ,
V_13 ) ;
goto V_28;
}
V_13 = F_16 ( & V_2 -> V_8 ) ;
if ( V_13 )
goto V_28;
return V_13 ;
V_28:
F_14 ( V_3 , NULL ) ;
F_17 ( & V_2 -> V_9 ) ;
return V_13 ;
}
static int F_18 ( struct V_10 * V_3 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_19 ( V_3 ) ;
if ( V_2 == NULL )
return - V_29 ;
F_14 ( V_3 , NULL ) ;
V_13 = F_20 ( & V_2 -> V_8 ) ;
if ( ! V_13 )
F_17 ( & V_2 -> V_9 ) ;
else
F_15 ( & V_3 -> V_14 , L_4 ,
V_13 ) ;
return V_13 ;
}
static int T_1 F_21 ( void )
{
return F_22 ( & V_30 ) ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_30 ) ;
}

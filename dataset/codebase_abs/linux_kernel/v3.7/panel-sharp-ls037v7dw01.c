static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
if ( ! V_4 -> V_7 )
return - V_8 ;
if ( V_2 -> V_9 . V_10 == V_11 &&
V_2 -> V_9 . V_12 == V_11 )
V_6 = V_2 -> V_9 . V_13 ;
else
V_6 = 0 ;
return V_4 -> V_7 ( V_4 , V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 . V_10 == V_11 &&
V_2 -> V_9 . V_12 == V_11 )
return V_2 -> V_9 . V_13 ;
return 0 ;
}
static int F_4 ( struct V_3 * V_4 )
{
struct V_14 V_9 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_17 ;
V_4 -> V_18 . V_19 = V_20 ;
V_16 = F_5 ( sizeof( * V_16 ) , V_21 ) ;
if ( ! V_16 )
return - V_22 ;
F_6 ( & V_4 -> V_5 , V_16 ) ;
memset ( & V_9 , 0 , sizeof( struct V_14 ) ) ;
V_9 . V_23 = V_4 -> V_24 ;
V_9 . type = V_25 ;
V_2 = F_7 ( L_1 , & V_4 -> V_5 , V_4 ,
& V_26 , & V_9 ) ;
if ( F_8 ( V_2 ) ) {
V_17 = F_9 ( V_2 ) ;
F_10 ( V_16 ) ;
return V_17 ;
}
V_16 -> V_2 = V_2 ;
V_2 -> V_9 . V_10 = V_11 ;
V_2 -> V_9 . V_12 = V_11 ;
V_2 -> V_9 . V_13 = V_4 -> V_24 ;
V_17 = F_1 ( V_2 ) ;
if ( V_17 < 0 )
F_11 ( & V_4 -> V_5 , L_2 ) ;
return 0 ;
}
static void T_1 F_12 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_2 ( & V_4 -> V_5 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
V_2 -> V_9 . V_12 = V_27 ;
F_1 ( V_2 ) ;
F_13 ( V_2 ) ;
F_10 ( V_16 ) ;
}
static int F_14 ( struct V_3 * V_4 )
{
int V_17 = 0 ;
if ( V_4 -> V_28 == V_29 )
return 0 ;
F_15 ( V_4 , & V_4 -> V_18 . V_19 ) ;
F_16 ( V_4 , V_4 -> V_30 . V_31 . V_32 ) ;
V_17 = F_17 ( V_4 ) ;
if ( V_17 )
goto V_33;
F_18 ( 50 ) ;
if ( V_4 -> V_34 ) {
V_17 = V_4 -> V_34 ( V_4 ) ;
if ( V_17 )
goto V_35;
}
return 0 ;
V_35:
F_19 ( V_4 ) ;
V_33:
return V_17 ;
}
static void F_20 ( struct V_3 * V_4 )
{
if ( V_4 -> V_28 != V_29 )
return;
if ( V_4 -> V_36 )
V_4 -> V_36 ( V_4 ) ;
F_18 ( 100 ) ;
F_19 ( V_4 ) ;
}
static int F_21 ( struct V_3 * V_4 )
{
int V_17 ;
V_17 = F_14 ( V_4 ) ;
V_4 -> V_28 = V_29 ;
return V_17 ;
}
static void F_22 ( struct V_3 * V_4 )
{
F_20 ( V_4 ) ;
V_4 -> V_28 = V_37 ;
}
static int F_23 ( struct V_3 * V_4 )
{
F_20 ( V_4 ) ;
V_4 -> V_28 = V_38 ;
return 0 ;
}
static int F_24 ( struct V_3 * V_4 )
{
int V_17 ;
V_17 = F_14 ( V_4 ) ;
V_4 -> V_28 = V_29 ;
return V_17 ;
}
static int T_2 F_25 ( void )
{
return F_26 ( & V_39 ) ;
}
static void T_1 F_27 ( void )
{
F_28 ( & V_39 ) ;
}

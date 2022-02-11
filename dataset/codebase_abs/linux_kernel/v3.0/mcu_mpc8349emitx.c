static void F_1 ( void )
{
struct V_1 * V_1 = V_2 ;
F_2 ( L_1 ) ;
F_3 ( & V_1 -> V_3 ) ;
F_4 ( V_2 -> V_4 , V_5 ,
V_1 -> V_6 | V_7 ) ;
F_5 ( & V_1 -> V_3 ) ;
}
static void F_6 ( struct V_8 * V_9 , unsigned int V_10 , int V_11 )
{
struct V_1 * V_1 = F_7 ( V_9 , struct V_1 , V_9 ) ;
T_1 V_12 = 1 << ( 4 + V_10 ) ;
F_3 ( & V_1 -> V_3 ) ;
if ( V_11 )
V_1 -> V_6 &= ~ V_12 ;
else
V_1 -> V_6 |= V_12 ;
F_4 ( V_1 -> V_4 , V_5 , V_1 -> V_6 ) ;
F_5 ( & V_1 -> V_3 ) ;
}
static int F_8 ( struct V_8 * V_9 , unsigned int V_10 , int V_11 )
{
F_6 ( V_9 , V_10 , V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_13 * V_14 ;
struct V_8 * V_9 = & V_1 -> V_9 ;
V_14 = F_10 ( NULL , NULL , L_2 ) ;
if ( ! V_14 )
return - V_15 ;
V_9 -> V_16 = V_17 ;
V_9 -> V_18 = V_14 -> V_19 ;
V_9 -> V_20 = 1 ;
V_9 -> V_21 = V_22 ;
V_9 -> V_23 = - 1 ;
V_9 -> V_24 = F_6 ;
V_9 -> V_25 = F_8 ;
V_9 -> V_26 = V_14 ;
return F_11 ( V_9 ) ;
}
static int F_12 ( struct V_1 * V_1 )
{
return F_13 ( & V_1 -> V_9 ) ;
}
static int T_2 F_14 ( struct V_27 * V_4 ,
const struct V_28 * V_29 )
{
struct V_1 * V_1 ;
int V_30 ;
V_1 = F_15 ( sizeof( * V_1 ) , V_31 ) ;
if ( ! V_1 )
return - V_32 ;
F_16 ( & V_1 -> V_3 ) ;
V_1 -> V_4 = V_4 ;
F_17 ( V_4 , V_1 ) ;
V_30 = F_18 ( V_1 -> V_4 , V_5 ) ;
if ( V_30 < 0 )
goto V_33;
V_1 -> V_6 = V_30 ;
V_30 = F_9 ( V_1 ) ;
if ( V_30 )
goto V_33;
if ( ! V_34 . V_35 ) {
V_2 = V_1 ;
V_34 . V_35 = F_1 ;
F_19 ( & V_4 -> V_36 , L_3 ) ;
}
return 0 ;
V_33:
F_20 ( V_1 ) ;
return V_30 ;
}
static int T_3 F_21 ( struct V_27 * V_4 )
{
struct V_1 * V_1 = F_22 ( V_4 ) ;
int V_30 ;
if ( V_2 == V_1 ) {
V_34 . V_35 = NULL ;
V_2 = NULL ;
}
V_30 = F_12 ( V_1 ) ;
if ( V_30 )
return V_30 ;
F_17 ( V_4 , NULL ) ;
F_20 ( V_1 ) ;
return 0 ;
}
static int T_4 F_23 ( void )
{
return F_24 ( & V_37 ) ;
}
static void T_5 F_25 ( void )
{
F_26 ( & V_37 ) ;
}

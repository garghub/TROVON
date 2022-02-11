static void F_1 ( struct V_1 * V_1 )
{
void T_1 * V_2 = V_1 -> V_3 . V_4 ;
F_2 ( V_2 + V_5 ) ;
F_3 ( 0 , V_2 + V_6 ) ;
F_3 ( V_7 |
V_8 ,
V_2 + V_9 ) ;
}
static int F_4 ( struct V_10 * V_3 )
{
struct V_1 * V_1 = F_5 ( V_3 ) ;
F_6 ( V_1 -> V_11 ) ;
F_1 ( V_1 ) ;
return 0 ;
}
static void F_7 ( struct V_10 * V_3 )
{
struct V_1 * V_1 = F_5 ( V_3 ) ;
F_3 ( V_12 ,
V_3 -> V_4 + V_9 ) ;
F_8 ( V_1 -> V_11 ) ;
}
static int F_9 ( struct V_10 * V_3 , int V_13 )
{
F_10 ( V_3 -> V_14 , L_1 , V_13 ) ;
F_1 ( F_5 ( V_3 ) ) ;
F_3 ( V_15 ,
V_3 -> V_4 + V_9 ) ;
return 0 ;
}
static int F_11 ( struct V_10 * V_3 , int V_13 )
{
F_10 ( V_3 -> V_14 , L_2 , V_13 ) ;
F_3 ( V_15 ,
V_3 -> V_4 + V_16 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
void T_1 * V_2 ;
struct V_11 * V_11 ;
struct V_1 * V_1 ;
V_20 = F_13 ( V_18 , V_21 , 0 ) ;
if ( ! V_20 ) {
F_14 ( & V_18 -> V_14 , L_3 ) ;
return - V_22 ;
}
V_2 = F_15 ( & V_18 -> V_14 , V_20 ) ;
if ( ! V_2 )
return - V_23 ;
V_11 = F_16 ( & V_18 -> V_14 , NULL ) ;
if ( F_17 ( V_11 ) ) {
F_14 ( & V_18 -> V_14 ,
L_4 , F_18 ( V_11 ) ) ;
return F_18 ( V_11 ) ;
}
V_1 = F_19 ( & V_18 -> V_14 , sizeof( * V_1 ) , V_24 ) ;
if ( ! V_1 ) {
F_14 ( & V_18 -> V_14 , L_5 ) ;
return - V_25 ;
}
V_1 -> V_3 . V_4 = V_2 ;
V_1 -> V_3 . V_14 = & V_18 -> V_14 ;
V_1 -> V_3 . V_26 = V_27 ;
V_1 -> V_3 . V_28 = F_4 ;
V_1 -> V_3 . V_29 = F_7 ;
V_1 -> V_3 . V_30 = F_9 ;
V_1 -> V_3 . V_31 = F_11 ;
F_20 ( & V_1 -> V_3 . V_32 ) ;
V_1 -> V_11 = V_11 ;
F_21 ( V_18 , & V_1 -> V_3 ) ;
return 0 ;
}
static int T_2 F_22 ( struct V_17 * V_18 )
{
F_21 ( V_18 , NULL ) ;
return 0 ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_33 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_33 ) ;
}

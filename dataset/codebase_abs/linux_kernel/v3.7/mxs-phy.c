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
F_7 ( & V_1 -> V_12 , NULL ) ;
return 0 ;
}
static void F_8 ( struct V_10 * V_3 )
{
struct V_1 * V_1 = F_5 ( V_3 ) ;
F_3 ( V_13 ,
V_3 -> V_4 + V_9 ) ;
F_9 ( V_1 -> V_11 ) ;
}
static void F_10 ( struct V_14 * V_15 )
{
struct V_1 * V_1 = F_11 ( V_15 , struct V_1 ,
V_12 . V_16 ) ;
F_12 ( V_1 -> V_3 . V_17 , L_1 ) ;
F_3 ( V_18 ,
V_1 -> V_3 . V_4 + V_9 ) ;
}
static int F_13 ( struct V_10 * V_3 , int V_19 )
{
struct V_1 * V_1 = F_5 ( V_3 ) ;
F_12 ( V_3 -> V_17 , L_2 , V_19 ) ;
F_1 ( V_1 ) ;
F_12 ( V_3 -> V_17 , L_3 ) ;
F_14 ( & V_1 -> V_12 ,
F_10 ) ;
F_15 ( & V_1 -> V_12 ,
F_16 ( V_20 ) ) ;
return 0 ;
}
static int F_17 ( struct V_10 * V_3 , int V_19 )
{
F_12 ( V_3 -> V_17 , L_4 , V_19 ) ;
F_12 ( V_3 -> V_17 , L_5 ) ;
F_3 ( V_18 ,
V_3 -> V_4 + V_21 ) ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
void T_1 * V_2 ;
struct V_11 * V_11 ;
struct V_1 * V_1 ;
V_25 = F_19 ( V_23 , V_26 , 0 ) ;
if ( ! V_25 ) {
F_20 ( & V_23 -> V_17 , L_6 ) ;
return - V_27 ;
}
V_2 = F_21 ( & V_23 -> V_17 , V_25 ) ;
if ( ! V_2 )
return - V_28 ;
V_11 = F_22 ( & V_23 -> V_17 , NULL ) ;
if ( F_23 ( V_11 ) ) {
F_20 ( & V_23 -> V_17 ,
L_7 , F_24 ( V_11 ) ) ;
return F_24 ( V_11 ) ;
}
V_1 = F_25 ( & V_23 -> V_17 , sizeof( * V_1 ) , V_29 ) ;
if ( ! V_1 ) {
F_20 ( & V_23 -> V_17 , L_8 ) ;
return - V_30 ;
}
V_1 -> V_3 . V_4 = V_2 ;
V_1 -> V_3 . V_17 = & V_23 -> V_17 ;
V_1 -> V_3 . V_31 = V_32 ;
V_1 -> V_3 . V_33 = F_4 ;
V_1 -> V_3 . V_34 = F_8 ;
V_1 -> V_3 . V_35 = F_13 ;
V_1 -> V_3 . V_36 = F_17 ;
F_26 ( & V_1 -> V_3 . V_37 ) ;
V_1 -> V_11 = V_11 ;
F_27 ( V_23 , & V_1 -> V_3 ) ;
return 0 ;
}
static int T_2 F_28 ( struct V_22 * V_23 )
{
F_27 ( V_23 , NULL ) ;
return 0 ;
}
static int T_3 F_29 ( void )
{
return F_30 ( & V_38 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_38 ) ;
}

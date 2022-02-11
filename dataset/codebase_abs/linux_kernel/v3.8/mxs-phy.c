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
static int F_9 ( struct V_10 * V_3 ,
enum V_13 V_14 )
{
F_10 ( V_3 -> V_15 , L_1 ,
( V_14 == V_16 ) ? L_2 : L_3 ) ;
if ( V_14 == V_16 )
F_3 ( V_17 ,
V_3 -> V_4 + V_9 ) ;
return 0 ;
}
static int F_11 ( struct V_10 * V_3 ,
enum V_13 V_14 )
{
F_10 ( V_3 -> V_15 , L_4 ,
( V_14 == V_16 ) ? L_2 : L_3 ) ;
if ( V_14 == V_16 )
F_3 ( V_17 ,
V_3 -> V_4 + V_18 ) ;
return 0 ;
}
static int F_12 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
void T_1 * V_2 ;
struct V_11 * V_11 ;
struct V_1 * V_1 ;
V_22 = F_13 ( V_20 , V_23 , 0 ) ;
if ( ! V_22 ) {
F_14 ( & V_20 -> V_15 , L_5 ) ;
return - V_24 ;
}
V_2 = F_15 ( & V_20 -> V_15 , V_22 ) ;
if ( ! V_2 )
return - V_25 ;
V_11 = F_16 ( & V_20 -> V_15 , NULL ) ;
if ( F_17 ( V_11 ) ) {
F_14 ( & V_20 -> V_15 ,
L_6 , F_18 ( V_11 ) ) ;
return F_18 ( V_11 ) ;
}
V_1 = F_19 ( & V_20 -> V_15 , sizeof( * V_1 ) , V_26 ) ;
if ( ! V_1 ) {
F_14 ( & V_20 -> V_15 , L_7 ) ;
return - V_27 ;
}
V_1 -> V_3 . V_4 = V_2 ;
V_1 -> V_3 . V_15 = & V_20 -> V_15 ;
V_1 -> V_3 . V_28 = V_29 ;
V_1 -> V_3 . V_30 = F_4 ;
V_1 -> V_3 . V_31 = F_7 ;
V_1 -> V_3 . V_32 = F_9 ;
V_1 -> V_3 . V_33 = F_11 ;
F_20 ( & V_1 -> V_3 . V_34 ) ;
V_1 -> V_11 = V_11 ;
F_21 ( V_20 , & V_1 -> V_3 ) ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 )
{
F_21 ( V_20 , NULL ) ;
return 0 ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_35 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_35 ) ;
}

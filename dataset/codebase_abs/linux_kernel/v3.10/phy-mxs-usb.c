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
static int F_9 ( struct V_10 * V_13 , int V_14 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
if ( V_14 ) {
F_3 ( 0xffffffff , V_13 -> V_4 + V_6 ) ;
F_3 ( V_12 ,
V_13 -> V_4 + V_9 ) ;
F_8 ( V_1 -> V_11 ) ;
} else {
F_6 ( V_1 -> V_11 ) ;
F_3 ( V_12 ,
V_13 -> V_4 + V_15 ) ;
F_3 ( 0 , V_13 -> V_4 + V_6 ) ;
}
return 0 ;
}
static int F_10 ( struct V_10 * V_3 ,
enum V_16 V_17 )
{
F_11 ( V_3 -> V_18 , L_1 ,
( V_17 == V_19 ) ? L_2 : L_3 ) ;
if ( V_17 == V_19 )
F_3 ( V_20 ,
V_3 -> V_4 + V_9 ) ;
return 0 ;
}
static int F_12 ( struct V_10 * V_3 ,
enum V_16 V_17 )
{
F_11 ( V_3 -> V_18 , L_4 ,
( V_17 == V_19 ) ? L_2 : L_3 ) ;
if ( V_17 == V_19 )
F_3 ( V_20 ,
V_3 -> V_4 + V_15 ) ;
return 0 ;
}
static int F_13 ( struct V_21 * V_22 )
{
struct V_23 * V_24 ;
void T_1 * V_2 ;
struct V_11 * V_11 ;
struct V_1 * V_1 ;
int V_25 ;
V_24 = F_14 ( V_22 , V_26 , 0 ) ;
V_2 = F_15 ( & V_22 -> V_18 , V_24 ) ;
if ( F_16 ( V_2 ) )
return F_17 ( V_2 ) ;
V_11 = F_18 ( & V_22 -> V_18 , NULL ) ;
if ( F_16 ( V_11 ) ) {
F_19 ( & V_22 -> V_18 ,
L_5 , F_17 ( V_11 ) ) ;
return F_17 ( V_11 ) ;
}
V_1 = F_20 ( & V_22 -> V_18 , sizeof( * V_1 ) , V_27 ) ;
if ( ! V_1 ) {
F_19 ( & V_22 -> V_18 , L_6 ) ;
return - V_28 ;
}
V_1 -> V_3 . V_4 = V_2 ;
V_1 -> V_3 . V_18 = & V_22 -> V_18 ;
V_1 -> V_3 . V_29 = V_30 ;
V_1 -> V_3 . V_31 = F_4 ;
V_1 -> V_3 . V_32 = F_7 ;
V_1 -> V_3 . V_33 = F_9 ;
V_1 -> V_3 . V_34 = F_10 ;
V_1 -> V_3 . V_35 = F_12 ;
V_1 -> V_3 . type = V_36 ;
F_21 ( & V_1 -> V_3 . V_37 ) ;
V_1 -> V_11 = V_11 ;
F_22 ( V_22 , & V_1 -> V_3 ) ;
V_25 = F_23 ( & V_1 -> V_3 ) ;
if ( V_25 )
return V_25 ;
return 0 ;
}
static int F_24 ( struct V_21 * V_22 )
{
struct V_1 * V_1 = F_25 ( V_22 ) ;
F_26 ( & V_1 -> V_3 ) ;
return 0 ;
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_38 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_38 ) ;
}

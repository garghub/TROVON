static int F_1 ( struct V_1 * V_1 )
{
int V_2 ;
void T_1 * V_3 = V_1 -> V_4 . V_5 ;
V_2 = F_2 ( V_3 + V_6 ) ;
if ( V_2 )
return V_2 ;
F_3 ( 0 , V_3 + V_7 ) ;
F_3 ( V_8 |
V_9 ,
V_3 + V_10 ) ;
return 0 ;
}
static int F_4 ( struct V_11 * V_4 )
{
struct V_1 * V_1 = F_5 ( V_4 ) ;
F_6 ( V_1 -> V_12 ) ;
return F_1 ( V_1 ) ;
}
static void F_7 ( struct V_11 * V_4 )
{
struct V_1 * V_1 = F_5 ( V_4 ) ;
F_3 ( V_13 ,
V_4 -> V_5 + V_10 ) ;
F_8 ( V_1 -> V_12 ) ;
}
static int F_9 ( struct V_11 * V_14 , int V_15 )
{
struct V_1 * V_1 = F_5 ( V_14 ) ;
if ( V_15 ) {
F_3 ( 0xffffffff , V_14 -> V_5 + V_7 ) ;
F_3 ( V_13 ,
V_14 -> V_5 + V_10 ) ;
F_8 ( V_1 -> V_12 ) ;
} else {
F_6 ( V_1 -> V_12 ) ;
F_3 ( V_13 ,
V_14 -> V_5 + V_16 ) ;
F_3 ( 0 , V_14 -> V_5 + V_7 ) ;
}
return 0 ;
}
static int F_10 ( struct V_11 * V_4 ,
enum V_17 V_18 )
{
F_11 ( V_4 -> V_19 , L_1 ,
( V_18 == V_20 ) ? L_2 : L_3 ) ;
if ( V_18 == V_20 )
F_3 ( V_21 ,
V_4 -> V_5 + V_10 ) ;
return 0 ;
}
static int F_12 ( struct V_11 * V_4 ,
enum V_17 V_18 )
{
F_11 ( V_4 -> V_19 , L_4 ,
( V_18 == V_20 ) ? L_2 : L_3 ) ;
if ( V_18 == V_20 )
F_3 ( V_21 ,
V_4 -> V_5 + V_16 ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
void T_1 * V_3 ;
struct V_12 * V_12 ;
struct V_1 * V_1 ;
int V_2 ;
V_25 = F_14 ( V_23 , V_26 , 0 ) ;
V_3 = F_15 ( & V_23 -> V_19 , V_25 ) ;
if ( F_16 ( V_3 ) )
return F_17 ( V_3 ) ;
V_12 = F_18 ( & V_23 -> V_19 , NULL ) ;
if ( F_16 ( V_12 ) ) {
F_19 ( & V_23 -> V_19 ,
L_5 , F_17 ( V_12 ) ) ;
return F_17 ( V_12 ) ;
}
V_1 = F_20 ( & V_23 -> V_19 , sizeof( * V_1 ) , V_27 ) ;
if ( ! V_1 ) {
F_19 ( & V_23 -> V_19 , L_6 ) ;
return - V_28 ;
}
V_1 -> V_4 . V_5 = V_3 ;
V_1 -> V_4 . V_19 = & V_23 -> V_19 ;
V_1 -> V_4 . V_29 = V_30 ;
V_1 -> V_4 . V_31 = F_4 ;
V_1 -> V_4 . V_32 = F_7 ;
V_1 -> V_4 . V_33 = F_9 ;
V_1 -> V_4 . V_34 = F_10 ;
V_1 -> V_4 . V_35 = F_12 ;
V_1 -> V_4 . type = V_36 ;
F_21 ( & V_1 -> V_4 . V_37 ) ;
V_1 -> V_12 = V_12 ;
F_22 ( V_23 , V_1 ) ;
V_2 = F_23 ( & V_1 -> V_4 ) ;
if ( V_2 )
return V_2 ;
return 0 ;
}
static int F_24 ( struct V_22 * V_23 )
{
struct V_1 * V_1 = F_25 ( V_23 ) ;
F_26 ( & V_1 -> V_4 ) ;
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

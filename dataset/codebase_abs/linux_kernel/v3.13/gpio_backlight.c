static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_2 -> V_6 . V_5 ;
if ( V_2 -> V_6 . V_7 != V_8 ||
V_2 -> V_6 . V_9 != V_8 ||
V_2 -> V_6 . V_10 & ( V_11 | V_12 ) )
V_5 = 0 ;
F_3 ( V_4 -> V_13 , V_5 ? V_4 -> V_14 : ! V_4 -> V_14 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_5 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_17 == NULL || V_4 -> V_17 == V_16 -> V_18 ;
}
static int F_6 ( struct V_19 * V_20 )
{
struct V_21 * V_22 =
F_7 ( & V_20 -> V_18 ) ;
struct V_23 V_6 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_24 ;
if ( ! V_22 ) {
F_8 ( & V_20 -> V_18 , L_1 ) ;
return - V_25 ;
}
V_4 = F_9 ( & V_20 -> V_18 , sizeof( * V_4 ) , V_26 ) ;
if ( V_4 == NULL )
return - V_27 ;
V_4 -> V_18 = & V_20 -> V_18 ;
V_4 -> V_17 = V_22 -> V_17 ;
V_4 -> V_13 = V_22 -> V_13 ;
V_4 -> V_14 = V_22 -> V_28 ? 0 : 1 ;
V_24 = F_10 ( V_4 -> V_18 , V_4 -> V_13 , V_29 |
( V_4 -> V_14 ? V_30
: V_31 ) ,
V_22 -> V_32 ) ;
if ( V_24 < 0 ) {
F_8 ( & V_20 -> V_18 , L_2 ) ;
return V_24 ;
}
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . type = V_33 ;
V_6 . V_34 = 1 ;
V_2 = F_11 ( & V_20 -> V_18 , F_12 ( & V_20 -> V_18 ) ,
& V_20 -> V_18 , V_4 , & V_35 ,
& V_6 ) ;
if ( F_13 ( V_2 ) ) {
F_8 ( & V_20 -> V_18 , L_3 ) ;
return F_14 ( V_2 ) ;
}
V_2 -> V_6 . V_5 = V_22 -> V_36 ;
F_15 ( V_2 ) ;
F_16 ( V_20 , V_2 ) ;
return 0 ;
}

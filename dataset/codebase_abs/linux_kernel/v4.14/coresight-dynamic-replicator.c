static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
F_3 ( V_6 -> V_9 ) ;
if ( V_4 == 0 ) {
F_4 ( 0x00 , V_6 -> V_9 + V_10 ) ;
F_4 ( 0xff , V_6 -> V_9 + V_11 ) ;
} else {
F_4 ( 0x00 , V_6 -> V_9 + V_11 ) ;
F_4 ( 0xff , V_6 -> V_9 + V_10 ) ;
}
F_5 ( V_6 -> V_9 ) ;
F_6 ( V_6 -> V_7 , L_1 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
F_3 ( V_6 -> V_9 ) ;
if ( V_4 == 0 )
F_4 ( 0xff , V_6 -> V_9 + V_10 ) ;
else
F_4 ( 0xff , V_6 -> V_9 + V_11 ) ;
F_5 ( V_6 -> V_9 ) ;
F_6 ( V_6 -> V_7 , L_2 ) ;
}
static int F_8 ( struct V_12 * V_13 , const struct V_14 * V_15 )
{
int V_16 ;
struct V_17 * V_7 = & V_13 -> V_7 ;
struct V_18 * V_19 = & V_13 -> V_19 ;
struct V_20 * V_21 = NULL ;
struct V_5 * V_6 ;
struct V_22 V_23 = { 0 } ;
struct V_24 * V_25 = V_13 -> V_7 . V_26 ;
void T_1 * V_9 ;
if ( V_25 ) {
V_21 = F_9 ( V_7 , V_25 ) ;
if ( F_10 ( V_21 ) )
return F_11 ( V_21 ) ;
V_13 -> V_7 . V_27 = V_21 ;
}
V_6 = F_12 ( V_7 , sizeof( * V_6 ) , V_28 ) ;
if ( ! V_6 )
return - V_29 ;
V_6 -> V_7 = & V_13 -> V_7 ;
V_6 -> V_30 = F_13 ( & V_13 -> V_7 , L_3 ) ;
if ( ! F_10 ( V_6 -> V_30 ) ) {
V_16 = F_14 ( V_6 -> V_30 ) ;
if ( V_16 )
return V_16 ;
}
V_9 = F_15 ( V_7 , V_19 ) ;
if ( F_10 ( V_9 ) )
return F_11 ( V_9 ) ;
V_6 -> V_9 = V_9 ;
F_16 ( V_7 , V_6 ) ;
F_17 ( & V_13 -> V_7 ) ;
V_23 . type = V_31 ;
V_23 . V_32 . V_33 = V_34 ;
V_23 . V_35 = & V_36 ;
V_23 . V_21 = V_13 -> V_7 . V_27 ;
V_23 . V_7 = & V_13 -> V_7 ;
V_23 . V_37 = V_38 ;
V_6 -> V_2 = F_18 ( & V_23 ) ;
if ( F_10 ( V_6 -> V_2 ) )
return F_11 ( V_6 -> V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_17 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
if ( V_6 && ! F_10 ( V_6 -> V_30 ) )
F_20 ( V_6 -> V_30 ) ;
return 0 ;
}
static int F_21 ( struct V_17 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
if ( V_6 && ! F_10 ( V_6 -> V_30 ) )
F_14 ( V_6 -> V_30 ) ;
return 0 ;
}

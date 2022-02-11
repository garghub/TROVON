static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
F_3 ( V_6 -> V_7 , L_1 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
F_3 ( V_6 -> V_7 , L_2 ) ;
}
static int F_5 ( struct V_9 * V_10 )
{
int V_11 ;
struct V_12 * V_7 = & V_10 -> V_7 ;
struct V_13 * V_14 = NULL ;
struct V_5 * V_6 ;
struct V_15 V_16 = { 0 } ;
struct V_17 * V_18 = V_10 -> V_7 . V_19 ;
if ( V_18 ) {
V_14 = F_6 ( V_7 , V_18 ) ;
if ( F_7 ( V_14 ) )
return F_8 ( V_14 ) ;
V_10 -> V_7 . V_20 = V_14 ;
}
V_6 = F_9 ( V_7 , sizeof( * V_6 ) , V_21 ) ;
if ( ! V_6 )
return - V_22 ;
V_6 -> V_7 = & V_10 -> V_7 ;
V_6 -> V_23 = F_10 ( & V_10 -> V_7 , L_3 ) ;
if ( ! F_7 ( V_6 -> V_23 ) ) {
V_11 = F_11 ( V_6 -> V_23 ) ;
if ( V_11 )
return V_11 ;
}
F_12 ( & V_10 -> V_7 ) ;
F_13 ( & V_10 -> V_7 ) ;
F_14 ( & V_10 -> V_7 ) ;
F_15 ( V_10 , V_6 ) ;
V_16 . type = V_24 ;
V_16 . V_25 . V_26 = V_27 ;
V_16 . V_28 = & V_29 ;
V_16 . V_14 = V_10 -> V_7 . V_20 ;
V_16 . V_7 = & V_10 -> V_7 ;
V_6 -> V_2 = F_16 ( & V_16 ) ;
if ( F_7 ( V_6 -> V_2 ) ) {
V_11 = F_8 ( V_6 -> V_2 ) ;
goto V_30;
}
F_17 ( & V_10 -> V_7 ) ;
return 0 ;
V_30:
if ( ! F_7 ( V_6 -> V_23 ) )
F_18 ( V_6 -> V_23 ) ;
F_19 ( & V_10 -> V_7 ) ;
F_20 ( & V_10 -> V_7 ) ;
return V_11 ;
}
static int F_21 ( struct V_12 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
if ( V_6 && ! F_7 ( V_6 -> V_23 ) )
F_18 ( V_6 -> V_23 ) ;
return 0 ;
}
static int F_22 ( struct V_12 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
if ( V_6 && ! F_7 ( V_6 -> V_23 ) )
F_11 ( V_6 -> V_23 ) ;
return 0 ;
}

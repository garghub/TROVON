void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static void F_3 ( struct V_4 * V_3 )
{
F_4 ( F_5 ( V_3 ) ) ;
}
struct V_1 * F_6 ( struct V_5 * V_6 , int V_7 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
return F_8 ( - V_9 ) ;
V_2 -> V_3 . V_10 = F_3 ;
V_2 -> V_3 . V_11 = & V_6 -> V_3 ;
V_2 -> V_3 . V_6 = & V_12 ;
V_2 -> V_13 = F_1 ;
V_2 -> V_14 = V_15 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_7 = V_7 ;
F_9 ( & V_2 -> V_3 , V_16 , V_6 -> V_17 , V_7 ) ;
F_10 ( & V_2 -> V_3 ) ;
return V_2 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_18 ;
F_12 ( & V_2 -> V_3 , L_1 ) ;
V_18 = F_13 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_14 ( & V_2 -> V_3 ) ;
if ( V_18 ) {
F_15 ( L_2 , V_2 -> V_7 ) ;
goto V_19;
}
return 0 ;
V_19:
F_16 ( V_2 ) ;
return V_18 ;
}
void V_15 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_3 ) ;
F_16 ( V_2 ) ;
}
static int F_18 ( struct V_4 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_3 ) ;
struct V_20 * V_21 = V_2 -> V_3 . V_22 ;
struct V_23 * V_24 = F_19 ( V_21 ) ;
int V_18 = 0 ;
if ( V_24 -> V_25 )
V_18 = V_24 -> V_25 ( V_2 ) ;
return V_18 ;
}
static int F_20 ( struct V_4 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_3 ) ;
struct V_20 * V_21 = V_2 -> V_3 . V_22 ;
struct V_23 * V_24 = F_19 ( V_21 ) ;
if ( V_24 -> remove )
V_24 -> remove ( V_2 ) ;
return 0 ;
}
int F_21 ( struct V_23 * V_21 )
{
struct V_26 * V_24 = & V_21 -> V_24 ;
int V_27 ;
F_22 ( L_3 , V_24 -> V_22 . V_28 ) ;
V_24 -> V_22 . V_6 = & V_12 ;
V_24 -> V_22 . V_25 = F_18 ;
V_24 -> V_22 . remove = F_20 ;
V_27 = F_23 ( & V_24 -> V_22 ) ;
if ( V_27 ) {
F_15 ( L_4 ,
V_24 -> V_22 . V_28 , V_27 ) ;
return V_27 ;
}
return 0 ;
}
void F_24 ( struct V_23 * V_21 )
{
struct V_26 * V_24 = & V_21 -> V_24 ;
F_25 ( & V_24 -> V_22 ) ;
}

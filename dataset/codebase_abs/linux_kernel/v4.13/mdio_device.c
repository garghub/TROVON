void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static void F_3 ( struct V_4 * V_3 )
{
F_4 ( F_5 ( V_3 ) ) ;
}
int F_6 ( struct V_4 * V_3 , struct V_5 * V_6 )
{
struct V_1 * V_2 = F_5 ( V_3 ) ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
if ( V_8 -> V_8 . V_9 & V_10 )
return 0 ;
return strcmp ( V_2 -> V_11 , V_6 -> V_12 ) == 0 ;
}
struct V_1 * F_8 ( struct V_13 * V_14 , int V_15 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
return F_10 ( - V_17 ) ;
V_2 -> V_3 . V_18 = F_3 ;
V_2 -> V_3 . V_19 = & V_14 -> V_3 ;
V_2 -> V_3 . V_14 = & V_20 ;
V_2 -> V_21 = F_1 ;
V_2 -> V_22 = V_23 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_15 = V_15 ;
F_11 ( & V_2 -> V_3 , V_24 , V_14 -> V_25 , V_15 ) ;
F_12 ( & V_2 -> V_3 ) ;
return V_2 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_26 ;
F_14 ( & V_2 -> V_3 , L_1 ) ;
V_26 = F_15 ( V_2 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_16 ( & V_2 -> V_3 ) ;
if ( V_26 ) {
F_17 ( L_2 , V_2 -> V_15 ) ;
goto V_27;
}
return 0 ;
V_27:
F_18 ( V_2 ) ;
return V_26 ;
}
void V_23 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_3 ) ;
F_18 ( V_2 ) ;
}
static int F_20 ( struct V_4 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_3 ) ;
struct V_5 * V_6 = V_2 -> V_3 . V_28 ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
int V_26 = 0 ;
if ( V_8 -> V_29 )
V_26 = V_8 -> V_29 ( V_2 ) ;
return V_26 ;
}
static int F_21 ( struct V_4 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_3 ) ;
struct V_5 * V_6 = V_2 -> V_3 . V_28 ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
if ( V_8 -> remove )
V_8 -> remove ( V_2 ) ;
return 0 ;
}
int F_22 ( struct V_7 * V_6 )
{
struct V_30 * V_8 = & V_6 -> V_8 ;
int V_31 ;
F_23 ( L_3 , V_8 -> V_28 . V_12 ) ;
V_8 -> V_28 . V_14 = & V_20 ;
V_8 -> V_28 . V_29 = F_20 ;
V_8 -> V_28 . remove = F_21 ;
V_31 = F_24 ( & V_8 -> V_28 ) ;
if ( V_31 ) {
F_17 ( L_4 ,
V_8 -> V_28 . V_12 , V_31 ) ;
return V_31 ;
}
return 0 ;
}
void F_25 ( struct V_7 * V_6 )
{
struct V_30 * V_8 = & V_6 -> V_8 ;
F_26 ( & V_8 -> V_28 ) ;
}

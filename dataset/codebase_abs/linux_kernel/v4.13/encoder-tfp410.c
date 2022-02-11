static int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_7 ;
if ( F_3 ( V_2 ) )
return - V_8 ;
V_7 = V_6 -> V_9 . V_10 -> V_11 ( V_6 , V_2 ) ;
if ( V_7 )
return V_7 ;
V_3 -> V_12 = V_2 ;
V_2 -> V_3 = V_3 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_5 ( ! F_3 ( V_2 ) ) ;
if ( ! F_3 ( V_2 ) )
return;
F_5 ( V_3 != V_2 -> V_3 ) ;
if ( V_3 != V_2 -> V_3 )
return;
V_3 -> V_12 = NULL ;
V_2 -> V_3 = NULL ;
V_6 -> V_9 . V_10 -> V_13 ( V_6 , & V_5 -> V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_7 ;
if ( ! F_3 ( V_2 ) )
return - V_14 ;
if ( F_7 ( V_2 ) )
return 0 ;
V_6 -> V_9 . V_10 -> V_15 ( V_6 , & V_5 -> V_16 ) ;
V_7 = V_6 -> V_9 . V_10 -> V_17 ( V_6 ) ;
if ( V_7 )
return V_7 ;
if ( F_8 ( V_5 -> V_18 ) )
F_9 ( V_5 -> V_18 , 1 ) ;
V_2 -> V_19 = V_20 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
if ( ! F_7 ( V_2 ) )
return;
if ( F_8 ( V_5 -> V_18 ) )
F_9 ( V_5 -> V_18 , 0 ) ;
V_6 -> V_9 . V_10 -> V_21 ( V_6 ) ;
V_2 -> V_19 = V_22 ;
}
static void F_11 ( struct V_23 * V_16 )
{
V_16 -> V_24 |= V_25 | V_26 |
V_27 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_23 * V_16 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_11 ( V_16 ) ;
V_5 -> V_16 = * V_16 ;
V_2 -> V_28 . V_16 = * V_16 ;
V_6 -> V_9 . V_10 -> V_15 ( V_6 , V_16 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_23 * V_16 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
* V_16 = V_5 -> V_16 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_23 * V_16 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_11 ( V_16 ) ;
return V_6 -> V_9 . V_10 -> V_29 ( V_6 , V_16 ) ;
}
static int F_15 ( struct V_30 * V_31 )
{
struct V_4 * V_5 = F_16 ( V_31 ) ;
struct V_32 * V_33 = V_31 -> V_34 . V_35 ;
struct V_1 * V_6 ;
int V_36 ;
V_36 = F_17 ( V_33 , L_1 , 0 ) ;
if ( F_8 ( V_36 ) || V_36 == - V_37 ) {
V_5 -> V_18 = V_36 ;
} else {
F_18 ( & V_31 -> V_34 , L_2 ) ;
return V_36 ;
}
V_6 = F_19 ( V_33 ) ;
if ( F_20 ( V_6 ) ) {
F_18 ( & V_31 -> V_34 , L_3 ) ;
return F_21 ( V_6 ) ;
}
V_5 -> V_6 = V_6 ;
return 0 ;
}
static int F_22 ( struct V_30 * V_31 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
int V_7 ;
V_5 = F_23 ( & V_31 -> V_34 , sizeof( * V_5 ) , V_38 ) ;
if ( ! V_5 )
return - V_39 ;
F_24 ( V_31 , V_5 ) ;
if ( ! V_31 -> V_34 . V_35 )
return - V_14 ;
V_7 = F_15 ( V_31 ) ;
if ( V_7 )
return V_7 ;
if ( F_8 ( V_5 -> V_18 ) ) {
V_7 = F_25 ( & V_31 -> V_34 , V_5 -> V_18 ,
V_40 , L_4 ) ;
if ( V_7 ) {
F_18 ( & V_31 -> V_34 , L_5 ,
V_5 -> V_18 ) ;
goto V_41;
}
}
V_2 = & V_5 -> V_2 ;
V_2 -> V_9 . V_42 = & V_43 ;
V_2 -> V_34 = & V_31 -> V_34 ;
V_2 -> type = V_44 ;
V_2 -> V_45 = V_46 ;
V_2 -> V_47 = V_48 ;
V_2 -> V_49 = 1 ;
V_7 = F_26 ( V_2 ) ;
if ( V_7 ) {
F_18 ( & V_31 -> V_34 , L_6 ) ;
goto V_50;
}
return 0 ;
V_50:
V_41:
F_27 ( V_5 -> V_6 ) ;
return V_7 ;
}
static int T_1 F_28 ( struct V_30 * V_31 )
{
struct V_4 * V_5 = F_16 ( V_31 ) ;
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_29 ( & V_5 -> V_2 ) ;
F_5 ( F_7 ( V_2 ) ) ;
if ( F_7 ( V_2 ) )
F_10 ( V_2 ) ;
F_5 ( F_3 ( V_2 ) ) ;
if ( F_3 ( V_2 ) )
F_4 ( V_2 , V_2 -> V_3 ) ;
F_27 ( V_6 ) ;
return 0 ;
}

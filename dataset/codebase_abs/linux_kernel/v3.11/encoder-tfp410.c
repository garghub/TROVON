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
V_2 -> V_13 = V_3 ;
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
F_5 ( V_3 != V_2 -> V_13 ) ;
if ( V_3 != V_2 -> V_13 )
return;
V_3 -> V_12 = NULL ;
V_2 -> V_13 = NULL ;
V_6 -> V_9 . V_10 -> V_14 ( V_6 , & V_5 -> V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_7 ;
if ( ! F_3 ( V_2 ) )
return - V_15 ;
if ( F_7 ( V_2 ) )
return 0 ;
V_6 -> V_9 . V_10 -> V_16 ( V_6 , & V_5 -> V_17 ) ;
V_6 -> V_9 . V_10 -> V_18 ( V_6 , V_5 -> V_19 ) ;
V_7 = V_6 -> V_9 . V_10 -> V_20 ( V_6 ) ;
if ( V_7 )
return V_7 ;
if ( F_8 ( V_5 -> V_21 ) )
F_9 ( V_5 -> V_21 , 1 ) ;
V_2 -> V_22 = V_23 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
if ( ! F_7 ( V_2 ) )
return;
if ( F_8 ( V_5 -> V_21 ) )
F_9 ( V_5 -> V_21 , 0 ) ;
V_6 -> V_9 . V_10 -> V_24 ( V_6 ) ;
V_2 -> V_22 = V_25 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_26 * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
V_5 -> V_17 = * V_17 ;
V_2 -> V_27 . V_17 = * V_17 ;
V_6 -> V_9 . V_10 -> V_16 ( V_6 , V_17 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_26 * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
* V_17 = V_5 -> V_17 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_26 * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
return V_6 -> V_9 . V_10 -> V_28 ( V_6 , V_17 ) ;
}
static int F_14 ( struct V_29 * V_30 )
{
struct V_4 * V_5 = F_15 ( V_30 ) ;
struct V_31 * V_32 ;
struct V_1 * V_2 , * V_6 ;
V_32 = F_16 ( & V_30 -> V_33 ) ;
V_5 -> V_21 = V_32 -> V_34 ;
V_5 -> V_19 = V_32 -> V_19 ;
V_6 = F_17 ( V_32 -> V_35 ) ;
if ( V_6 == NULL ) {
F_18 ( & V_30 -> V_33 , L_1 ) ;
return - V_15 ;
}
V_5 -> V_6 = V_6 ;
V_2 = & V_5 -> V_2 ;
V_2 -> V_36 = V_32 -> V_36 ;
return 0 ;
}
static int F_19 ( struct V_29 * V_30 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
int V_7 ;
V_5 = F_20 ( & V_30 -> V_33 , sizeof( * V_5 ) , V_37 ) ;
if ( ! V_5 )
return - V_38 ;
F_21 ( V_30 , V_5 ) ;
if ( F_16 ( & V_30 -> V_33 ) ) {
V_7 = F_14 ( V_30 ) ;
if ( V_7 )
return V_7 ;
} else {
return - V_15 ;
}
if ( F_8 ( V_5 -> V_21 ) ) {
V_7 = F_22 ( & V_30 -> V_33 , V_5 -> V_21 ,
V_39 , L_2 ) ;
if ( V_7 ) {
F_18 ( & V_30 -> V_33 , L_3 ,
V_5 -> V_21 ) ;
goto V_40;
}
}
V_2 = & V_5 -> V_2 ;
V_2 -> V_9 . V_41 = & V_42 ;
V_2 -> V_33 = & V_30 -> V_33 ;
V_2 -> type = V_43 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_46 = V_47 ;
V_2 -> V_48 . V_10 . V_19 = V_5 -> V_19 ;
V_7 = F_23 ( V_2 ) ;
if ( V_7 ) {
F_18 ( & V_30 -> V_33 , L_4 ) ;
goto V_49;
}
return 0 ;
V_49:
V_40:
F_24 ( V_5 -> V_6 ) ;
return V_7 ;
}
static int T_1 F_25 ( struct V_29 * V_30 )
{
struct V_4 * V_5 = F_15 ( V_30 ) ;
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_26 ( & V_5 -> V_2 ) ;
F_5 ( F_7 ( V_2 ) ) ;
if ( F_7 ( V_2 ) )
F_10 ( V_2 ) ;
F_5 ( F_3 ( V_2 ) ) ;
if ( F_3 ( V_2 ) )
F_4 ( V_2 , V_2 -> V_13 ) ;
F_24 ( V_6 ) ;
return 0 ;
}

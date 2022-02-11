static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
int V_6 ;
F_3 ( V_4 -> V_7 , L_1 ) ;
if ( F_4 ( V_2 ) )
return 0 ;
V_6 = V_5 -> V_8 . V_9 -> V_10 ( V_5 , V_2 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
F_3 ( V_4 -> V_7 , L_2 ) ;
if ( ! F_4 ( V_2 ) )
return;
V_5 -> V_8 . V_9 -> V_11 ( V_5 , V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
int V_6 ;
F_3 ( V_4 -> V_7 , L_3 ) ;
if ( ! F_4 ( V_2 ) )
return - V_12 ;
if ( F_7 ( V_2 ) )
return 0 ;
V_5 -> V_8 . V_9 -> V_13 ( V_5 , & V_4 -> V_14 ) ;
if ( ! V_4 -> V_7 -> V_15 ) {
V_5 -> V_8 . V_9 -> V_16 ( V_5 , V_17 ) ;
V_5 -> V_8 . V_9 -> V_18 ( V_5 ,
V_4 -> V_19 ) ;
}
V_6 = V_5 -> V_8 . V_9 -> V_20 ( V_5 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_21 = V_22 ;
return V_6 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
F_3 ( V_4 -> V_7 , L_4 ) ;
if ( ! F_7 ( V_2 ) )
return;
V_5 -> V_8 . V_9 -> V_23 ( V_5 ) ;
V_2 -> V_21 = V_24 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_25 * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
V_4 -> V_14 = * V_14 ;
V_2 -> V_26 . V_14 = * V_14 ;
V_5 -> V_8 . V_9 -> V_13 ( V_5 , V_14 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_25 * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_14 = V_4 -> V_14 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_25 * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
return V_5 -> V_8 . V_9 -> V_27 ( V_5 , V_14 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
return V_5 -> V_8 . V_9 -> V_28 ( V_5 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_29 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
return V_5 -> V_8 . V_9 -> V_30 ( V_5 , V_29 ) ;
}
static int F_14 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_15 ( V_32 ) ;
struct V_33 * V_34 ;
struct V_1 * V_5 , * V_2 ;
V_34 = F_16 ( & V_32 -> V_7 ) ;
V_5 = F_17 ( V_34 -> V_35 ) ;
if ( V_5 == NULL ) {
F_18 ( & V_32 -> V_7 , L_5 ) ;
return - V_36 ;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_19 = V_34 -> V_19 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_37 = V_34 -> V_37 ;
return 0 ;
}
static int F_19 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_15 ( V_32 ) ;
struct V_38 * V_39 = V_32 -> V_7 . V_15 ;
struct V_1 * V_5 ;
V_5 = F_20 ( V_39 ) ;
if ( F_21 ( V_5 ) ) {
F_18 ( & V_32 -> V_7 , L_6 ) ;
return F_22 ( V_5 ) ;
}
V_4 -> V_5 = V_5 ;
return 0 ;
}
static int F_23 ( struct V_31 * V_32 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_6 ;
V_4 = F_24 ( & V_32 -> V_7 , sizeof( * V_4 ) , V_40 ) ;
if ( ! V_4 )
return - V_41 ;
F_25 ( V_32 , V_4 ) ;
V_4 -> V_7 = & V_32 -> V_7 ;
if ( F_16 ( & V_32 -> V_7 ) ) {
V_6 = F_14 ( V_32 ) ;
if ( V_6 )
return V_6 ;
} else if ( V_32 -> V_7 . V_15 ) {
V_6 = F_19 ( V_32 ) ;
if ( V_6 )
return V_6 ;
} else {
return - V_12 ;
}
V_4 -> V_14 = V_42 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_43 = & V_44 ;
V_2 -> V_7 = & V_32 -> V_7 ;
V_2 -> type = V_45 ;
V_2 -> V_46 = V_47 ;
V_2 -> V_26 . V_14 = V_42 ;
V_6 = F_26 ( V_2 ) ;
if ( V_6 ) {
F_18 ( & V_32 -> V_7 , L_7 ) ;
goto V_48;
}
return 0 ;
V_48:
F_27 ( V_4 -> V_5 ) ;
return V_6 ;
}
static int T_2 F_28 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_15 ( V_32 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_5 = V_4 -> V_5 ;
F_29 ( & V_4 -> V_2 ) ;
F_8 ( V_2 ) ;
F_5 ( V_2 ) ;
F_27 ( V_5 ) ;
return 0 ;
}

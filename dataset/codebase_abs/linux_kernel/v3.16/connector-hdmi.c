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
V_6 = V_5 -> V_8 . V_9 -> V_15 ( V_5 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_16 = V_17 ;
return V_6 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
F_3 ( V_4 -> V_7 , L_4 ) ;
if ( ! F_7 ( V_2 ) )
return;
V_5 -> V_8 . V_9 -> V_18 ( V_5 ) ;
V_2 -> V_16 = V_19 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_20 * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
V_4 -> V_14 = * V_14 ;
V_2 -> V_21 . V_14 = * V_14 ;
V_5 -> V_8 . V_9 -> V_13 ( V_5 , V_14 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_20 * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_14 = V_4 -> V_14 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_20 * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
return V_5 -> V_8 . V_9 -> V_22 ( V_5 , V_14 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 * V_23 , int V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
return V_5 -> V_8 . V_9 -> V_25 ( V_5 , V_23 , V_24 ) ;
}
static bool F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
if ( F_14 ( V_4 -> V_26 ) )
return F_15 ( V_4 -> V_26 ) ;
else
return V_5 -> V_8 . V_9 -> V_27 ( V_5 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
int V_6 ;
if ( ! F_7 ( V_2 ) )
return - V_28 ;
V_6 = V_5 -> V_8 . V_9 -> V_29 ( V_5 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_30 = V_31 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
V_5 -> V_8 . V_9 -> V_32 ( V_5 ) ;
V_2 -> V_30 = V_33 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
int V_6 ;
if ( V_2 -> V_30 != V_31 )
return - V_28 ;
V_6 = V_5 -> V_8 . V_9 -> V_34 ( V_5 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_30 = V_35 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
V_5 -> V_8 . V_9 -> V_36 ( V_5 ) ;
V_2 -> V_30 = V_31 ;
}
static bool F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
if ( ! F_7 ( V_2 ) )
return false ;
return V_5 -> V_8 . V_9 -> V_37 ( V_5 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
int V_6 ;
if ( ! F_7 ( V_2 ) )
return - V_28 ;
V_6 = V_5 -> V_8 . V_9 -> V_40 ( V_5 , V_39 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_30 = V_41 ;
return 0 ;
}
static int F_22 ( struct V_42 * V_43 )
{
struct V_3 * V_4 = F_23 ( V_43 ) ;
struct V_44 * V_45 ;
struct V_1 * V_5 , * V_2 ;
V_45 = F_24 ( & V_43 -> V_7 ) ;
V_4 -> V_26 = - V_12 ;
V_5 = F_25 ( V_45 -> V_46 ) ;
if ( V_5 == NULL ) {
F_26 ( & V_43 -> V_7 , L_5 ) ;
return - V_47 ;
}
V_4 -> V_5 = V_5 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_48 = V_45 -> V_48 ;
return 0 ;
}
static int F_27 ( struct V_42 * V_43 )
{
struct V_3 * V_4 = F_23 ( V_43 ) ;
struct V_49 * V_50 = V_43 -> V_7 . V_51 ;
struct V_1 * V_5 ;
int V_52 ;
V_52 = F_28 ( V_50 , L_6 , 0 ) ;
if ( F_14 ( V_52 ) )
V_4 -> V_26 = V_52 ;
else
V_4 -> V_26 = - V_12 ;
V_5 = F_29 ( V_50 ) ;
if ( F_30 ( V_5 ) ) {
F_26 ( & V_43 -> V_7 , L_7 ) ;
return F_31 ( V_5 ) ;
}
V_4 -> V_5 = V_5 ;
return 0 ;
}
static int F_32 ( struct V_42 * V_43 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_6 ;
V_4 = F_33 ( & V_43 -> V_7 , sizeof( * V_4 ) , V_53 ) ;
if ( ! V_4 )
return - V_54 ;
F_34 ( V_43 , V_4 ) ;
V_4 -> V_7 = & V_43 -> V_7 ;
if ( F_24 ( & V_43 -> V_7 ) ) {
V_6 = F_22 ( V_43 ) ;
if ( V_6 )
return V_6 ;
} else if ( V_43 -> V_7 . V_51 ) {
V_6 = F_27 ( V_43 ) ;
if ( V_6 )
return V_6 ;
} else {
return - V_12 ;
}
if ( F_14 ( V_4 -> V_26 ) ) {
V_6 = F_35 ( & V_43 -> V_7 , V_4 -> V_26 ,
V_55 , L_8 ) ;
if ( V_6 )
goto V_56;
}
V_4 -> V_14 = V_57 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_58 = & V_59 ;
V_2 -> V_7 = & V_43 -> V_7 ;
V_2 -> type = V_60 ;
V_2 -> V_61 = V_62 ;
V_2 -> V_21 . V_14 = V_57 ;
V_6 = F_36 ( V_2 ) ;
if ( V_6 ) {
F_26 ( & V_43 -> V_7 , L_9 ) ;
goto V_56;
}
return 0 ;
V_56:
F_37 ( V_4 -> V_5 ) ;
return V_6 ;
}
static int T_2 F_38 ( struct V_42 * V_43 )
{
struct V_3 * V_4 = F_23 ( V_43 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_5 = V_4 -> V_5 ;
F_39 ( & V_4 -> V_2 ) ;
F_8 ( V_2 ) ;
F_5 ( V_2 ) ;
F_37 ( V_5 ) ;
return 0 ;
}

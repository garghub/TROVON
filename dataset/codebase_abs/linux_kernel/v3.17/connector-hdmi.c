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
static int F_22 ( struct V_1 * V_2 , bool V_42 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
return V_5 -> V_8 . V_9 -> V_43 ( V_5 , V_42 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_44 * V_45 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
return V_5 -> V_8 . V_9 -> V_46 ( V_5 , V_45 ) ;
}
static int F_24 ( struct V_47 * V_48 )
{
struct V_3 * V_4 = F_25 ( V_48 ) ;
struct V_49 * V_50 ;
struct V_1 * V_5 , * V_2 ;
V_50 = F_26 ( & V_48 -> V_7 ) ;
V_4 -> V_26 = - V_12 ;
V_5 = F_27 ( V_50 -> V_51 ) ;
if ( V_5 == NULL ) {
F_28 ( & V_48 -> V_7 , L_5 ) ;
return - V_52 ;
}
V_4 -> V_5 = V_5 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_53 = V_50 -> V_53 ;
return 0 ;
}
static int F_29 ( struct V_47 * V_48 )
{
struct V_3 * V_4 = F_25 ( V_48 ) ;
struct V_54 * V_55 = V_48 -> V_7 . V_56 ;
struct V_1 * V_5 ;
int V_57 ;
V_57 = F_30 ( V_55 , L_6 , 0 ) ;
if ( F_14 ( V_57 ) )
V_4 -> V_26 = V_57 ;
else
V_4 -> V_26 = - V_12 ;
V_5 = F_31 ( V_55 ) ;
if ( F_32 ( V_5 ) ) {
F_28 ( & V_48 -> V_7 , L_7 ) ;
return F_33 ( V_5 ) ;
}
V_4 -> V_5 = V_5 ;
return 0 ;
}
static int F_34 ( struct V_47 * V_48 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_6 ;
V_4 = F_35 ( & V_48 -> V_7 , sizeof( * V_4 ) , V_58 ) ;
if ( ! V_4 )
return - V_59 ;
F_36 ( V_48 , V_4 ) ;
V_4 -> V_7 = & V_48 -> V_7 ;
if ( F_26 ( & V_48 -> V_7 ) ) {
V_6 = F_24 ( V_48 ) ;
if ( V_6 )
return V_6 ;
} else if ( V_48 -> V_7 . V_56 ) {
V_6 = F_29 ( V_48 ) ;
if ( V_6 )
return V_6 ;
} else {
return - V_12 ;
}
if ( F_14 ( V_4 -> V_26 ) ) {
V_6 = F_37 ( & V_48 -> V_7 , V_4 -> V_26 ,
V_60 , L_8 ) ;
if ( V_6 )
goto V_61;
}
V_4 -> V_14 = V_62 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_63 = & V_64 ;
V_2 -> V_7 = & V_48 -> V_7 ;
V_2 -> type = V_65 ;
V_2 -> V_66 = V_67 ;
V_2 -> V_21 . V_14 = V_62 ;
V_6 = F_38 ( V_2 ) ;
if ( V_6 ) {
F_28 ( & V_48 -> V_7 , L_9 ) ;
goto V_61;
}
return 0 ;
V_61:
F_39 ( V_4 -> V_5 ) ;
return V_6 ;
}
static int T_2 F_40 ( struct V_47 * V_48 )
{
struct V_3 * V_4 = F_25 ( V_48 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_5 = V_4 -> V_5 ;
F_41 ( & V_4 -> V_2 ) ;
F_8 ( V_2 ) ;
F_5 ( V_2 ) ;
F_39 ( V_5 ) ;
return 0 ;
}

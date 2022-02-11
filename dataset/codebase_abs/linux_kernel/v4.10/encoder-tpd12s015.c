static int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_7 ;
V_7 = V_6 -> V_8 . V_9 -> V_10 ( V_6 , V_2 ) ;
if ( V_7 )
return V_7 ;
V_3 -> V_11 = V_2 ;
V_2 -> V_3 = V_3 ;
F_3 ( V_5 -> V_12 , 1 ) ;
F_4 ( 300 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_6 ( V_3 != V_2 -> V_3 ) ;
if ( V_3 != V_2 -> V_3 )
return;
F_3 ( V_5 -> V_12 , 0 ) ;
V_3 -> V_11 = NULL ;
V_2 -> V_3 = NULL ;
V_6 -> V_8 . V_9 -> V_13 ( V_6 , & V_5 -> V_2 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_7 ;
if ( V_2 -> V_14 == V_15 )
return 0 ;
V_6 -> V_8 . V_9 -> V_16 ( V_6 , & V_5 -> V_17 ) ;
V_7 = V_6 -> V_8 . V_9 -> V_18 ( V_6 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_14 = V_15 ;
return V_7 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
if ( V_2 -> V_14 != V_15 )
return;
V_6 -> V_8 . V_9 -> V_19 ( V_6 ) ;
V_2 -> V_14 = V_20 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_21 * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
V_5 -> V_17 = * V_17 ;
V_2 -> V_22 . V_17 = * V_17 ;
V_6 -> V_8 . V_9 -> V_16 ( V_6 , V_17 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_21 * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
* V_17 = V_5 -> V_17 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_21 * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_7 ;
V_7 = V_6 -> V_8 . V_9 -> V_23 ( V_6 , V_17 ) ;
return V_7 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 * V_24 , int V_25 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_7 ;
if ( ! F_13 ( V_5 -> V_26 ) )
return - V_27 ;
F_3 ( V_5 -> V_28 , 1 ) ;
V_7 = V_6 -> V_8 . V_9 -> V_29 ( V_6 , V_24 , V_25 ) ;
F_3 ( V_5 -> V_28 , 0 ) ;
return V_7 ;
}
static bool F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_13 ( V_5 -> V_26 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_30 * V_31 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
return V_6 -> V_8 . V_9 -> V_32 ( V_6 , V_31 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
bool V_33 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
return V_6 -> V_8 . V_9 -> V_34 ( V_6 , V_33 ) ;
}
static int F_17 ( struct V_35 * V_36 )
{
struct V_4 * V_5 = F_18 ( V_36 ) ;
struct V_37 * V_38 = V_36 -> V_39 . V_40 ;
struct V_1 * V_6 ;
V_6 = F_19 ( V_38 ) ;
if ( F_20 ( V_6 ) ) {
F_21 ( & V_36 -> V_39 , L_1 ) ;
return F_22 ( V_6 ) ;
}
V_5 -> V_6 = V_6 ;
return 0 ;
}
static int F_23 ( struct V_35 * V_36 )
{
struct V_1 * V_6 , * V_2 ;
struct V_4 * V_5 ;
int V_7 ;
struct V_41 * V_42 ;
V_5 = F_24 ( & V_36 -> V_39 , sizeof( * V_5 ) , V_43 ) ;
if ( ! V_5 )
return - V_44 ;
F_25 ( V_36 , V_5 ) ;
if ( ! V_36 -> V_39 . V_40 )
return - V_27 ;
V_7 = F_17 ( V_36 ) ;
if ( V_7 )
return V_7 ;
V_42 = F_26 ( & V_36 -> V_39 , NULL , 0 ,
V_45 ) ;
if ( F_20 ( V_42 ) ) {
V_7 = F_22 ( V_42 ) ;
goto V_46;
}
V_5 -> V_12 = V_42 ;
V_42 = F_26 ( & V_36 -> V_39 , NULL , 1 ,
V_45 ) ;
if ( F_20 ( V_42 ) ) {
V_7 = F_22 ( V_42 ) ;
goto V_46;
}
V_5 -> V_28 = V_42 ;
V_42 = F_27 ( & V_36 -> V_39 , NULL , 2 ,
V_47 ) ;
if ( F_20 ( V_42 ) ) {
V_7 = F_22 ( V_42 ) ;
goto V_46;
}
V_5 -> V_26 = V_42 ;
V_2 = & V_5 -> V_2 ;
V_2 -> V_8 . V_9 = & V_48 ;
V_2 -> V_39 = & V_36 -> V_39 ;
V_2 -> type = V_49 ;
V_2 -> V_50 = V_49 ;
V_2 -> V_51 = V_52 ;
V_2 -> V_53 = 1 ;
V_6 = V_5 -> V_6 ;
V_7 = F_28 ( V_2 ) ;
if ( V_7 ) {
F_21 ( & V_36 -> V_39 , L_2 ) ;
goto V_54;
}
return 0 ;
V_54:
V_46:
F_29 ( V_5 -> V_6 ) ;
return V_7 ;
}
static int T_2 F_30 ( struct V_35 * V_36 )
{
struct V_4 * V_5 = F_18 ( V_36 ) ;
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_31 ( & V_5 -> V_2 ) ;
F_6 ( F_32 ( V_2 ) ) ;
if ( F_32 ( V_2 ) )
F_8 ( V_2 ) ;
F_6 ( F_33 ( V_2 ) ) ;
if ( F_33 ( V_2 ) )
F_5 ( V_2 , V_2 -> V_3 ) ;
F_29 ( V_6 ) ;
return 0 ;
}

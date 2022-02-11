static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
int V_6 ;
if ( F_3 ( V_2 ) )
return 0 ;
V_6 = V_5 -> V_7 . V_8 -> V_9 ( V_5 , V_2 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
if ( ! F_3 ( V_2 ) )
return;
V_5 -> V_7 . V_8 -> V_10 ( V_5 , V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
int V_6 ;
if ( ! F_3 ( V_2 ) )
return - V_11 ;
if ( F_6 ( V_2 ) )
return 0 ;
V_5 -> V_7 . V_8 -> V_12 ( V_5 , & V_4 -> V_13 ) ;
if ( V_4 -> V_14 ) {
V_6 = F_7 ( V_4 -> V_14 ) ;
if ( V_6 != 0 )
return V_6 ;
}
V_6 = V_5 -> V_7 . V_8 -> V_15 ( V_5 ) ;
if ( V_6 ) {
F_8 ( V_4 -> V_14 ) ;
return V_6 ;
}
F_9 ( 50 ) ;
if ( V_4 -> V_16 )
F_10 ( V_4 -> V_16 , 1 ) ;
if ( V_4 -> V_17 )
F_10 ( V_4 -> V_17 , 1 ) ;
V_2 -> V_18 = V_19 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
if ( ! F_6 ( V_2 ) )
return;
if ( V_4 -> V_17 )
F_10 ( V_4 -> V_17 , 0 ) ;
if ( V_4 -> V_16 )
F_10 ( V_4 -> V_16 , 0 ) ;
F_9 ( 100 ) ;
V_5 -> V_7 . V_8 -> V_20 ( V_5 ) ;
if ( V_4 -> V_14 )
F_8 ( V_4 -> V_14 ) ;
V_2 -> V_18 = V_21 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_22 * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
V_4 -> V_13 = * V_13 ;
V_2 -> V_23 . V_13 = * V_13 ;
V_5 -> V_7 . V_8 -> V_12 ( V_5 , V_13 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_22 * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_13 = V_4 -> V_13 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_22 * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
return V_5 -> V_7 . V_8 -> V_24 ( V_5 , V_13 ) ;
}
static int F_15 ( struct V_25 * V_26 , int V_27 , int V_28 ,
const char * V_29 , struct V_30 * * V_31 )
{
struct V_30 * V_32 ;
* V_31 = NULL ;
V_32 = F_16 ( V_26 , V_29 , V_27 , V_33 ) ;
if ( F_17 ( V_32 ) )
return F_18 ( V_32 ) ;
* V_31 = V_32 ;
return 0 ;
}
static int F_19 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_20 ( V_35 ) ;
struct V_36 * V_37 = V_35 -> V_26 . V_38 ;
struct V_1 * V_5 ;
int V_6 ;
V_4 -> V_14 = F_21 ( & V_35 -> V_26 , L_1 ) ;
if ( F_17 ( V_4 -> V_14 ) ) {
F_22 ( & V_35 -> V_26 , L_2 ) ;
return F_18 ( V_4 -> V_14 ) ;
}
V_6 = F_15 ( & V_35 -> V_26 , 0 , 0 , L_3 , & V_4 -> V_17 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_15 ( & V_35 -> V_26 , 0 , 0 , L_4 , & V_4 -> V_16 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_15 ( & V_35 -> V_26 , 0 , 0 , L_5 , & V_4 -> V_39 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_15 ( & V_35 -> V_26 , 1 , 1 , L_5 , & V_4 -> V_40 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_15 ( & V_35 -> V_26 , 2 , 1 , L_5 , & V_4 -> V_41 ) ;
if ( V_6 )
return V_6 ;
V_5 = F_23 ( V_37 ) ;
if ( F_17 ( V_5 ) ) {
F_22 ( & V_35 -> V_26 , L_6 ) ;
return F_18 ( V_5 ) ;
}
V_4 -> V_5 = V_5 ;
return 0 ;
}
static int F_24 ( struct V_34 * V_35 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_6 ;
V_4 = F_25 ( & V_35 -> V_26 , sizeof( * V_4 ) , V_42 ) ;
if ( V_4 == NULL )
return - V_43 ;
F_26 ( V_35 , V_4 ) ;
if ( ! V_35 -> V_26 . V_38 )
return - V_11 ;
V_6 = F_19 ( V_35 ) ;
if ( V_6 )
return V_6 ;
V_4 -> V_13 = V_44 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_26 = & V_35 -> V_26 ;
V_2 -> V_45 = & V_46 ;
V_2 -> type = V_47 ;
V_2 -> V_48 = V_49 ;
V_2 -> V_23 . V_13 = V_4 -> V_13 ;
V_6 = F_27 ( V_2 ) ;
if ( V_6 ) {
F_22 ( & V_35 -> V_26 , L_7 ) ;
goto V_50;
}
return 0 ;
V_50:
F_28 ( V_4 -> V_5 ) ;
return V_6 ;
}
static int T_1 F_29 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_20 ( V_35 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_5 = V_4 -> V_5 ;
F_30 ( V_2 ) ;
F_11 ( V_2 ) ;
F_4 ( V_2 ) ;
F_28 ( V_5 ) ;
return 0 ;
}

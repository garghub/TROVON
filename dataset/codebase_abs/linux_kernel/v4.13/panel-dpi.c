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
V_6 = V_5 -> V_7 . V_8 -> V_14 ( V_5 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_7 ( V_4 -> V_15 ) ;
if ( V_6 ) {
V_5 -> V_7 . V_8 -> V_16 ( V_5 ) ;
return V_6 ;
}
F_8 ( V_4 -> V_17 , 1 ) ;
if ( V_4 -> V_18 ) {
V_4 -> V_18 -> V_19 . V_20 = V_21 ;
F_9 ( V_4 -> V_18 ) ;
}
V_2 -> V_22 = V_23 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
if ( ! F_6 ( V_2 ) )
return;
if ( V_4 -> V_18 ) {
V_4 -> V_18 -> V_19 . V_20 = V_24 ;
F_9 ( V_4 -> V_18 ) ;
}
F_8 ( V_4 -> V_17 , 0 ) ;
F_11 ( V_4 -> V_15 ) ;
V_5 -> V_7 . V_8 -> V_16 ( V_5 ) ;
V_2 -> V_22 = V_25 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_26 * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
V_4 -> V_13 = * V_13 ;
V_2 -> V_27 . V_13 = * V_13 ;
V_5 -> V_7 . V_8 -> V_12 ( V_5 , V_13 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_26 * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_13 = V_4 -> V_13 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_26 * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
return V_5 -> V_7 . V_8 -> V_28 ( V_5 , V_13 ) ;
}
static int F_15 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = F_16 ( V_30 ) ;
struct V_31 * V_32 = V_30 -> V_33 . V_34 ;
struct V_31 * V_35 ;
struct V_1 * V_5 ;
int V_6 ;
struct V_36 V_37 ;
struct V_38 * V_39 ;
V_39 = F_17 ( & V_30 -> V_33 , L_1 , V_40 ) ;
if ( F_18 ( V_39 ) )
return F_19 ( V_39 ) ;
V_4 -> V_17 = V_39 ;
V_39 = F_17 ( & V_30 -> V_33 , L_2 , V_40 ) ;
if ( F_18 ( V_39 ) )
return F_19 ( V_39 ) ;
V_4 -> V_15 = F_20 ( & V_30 -> V_33 , L_3 ) ;
if ( F_18 ( V_4 -> V_15 ) )
return F_19 ( V_4 -> V_15 ) ;
V_35 = F_21 ( V_32 , L_4 , 0 ) ;
if ( V_35 ) {
V_4 -> V_18 = F_22 ( V_35 ) ;
F_23 ( V_35 ) ;
if ( ! V_4 -> V_18 )
return - V_41 ;
}
V_6 = F_24 ( V_32 , L_5 , & V_37 ) ;
if ( V_6 ) {
F_25 ( & V_30 -> V_33 , L_6 ) ;
goto V_42;
}
F_26 ( & V_37 , & V_4 -> V_13 ) ;
V_5 = F_27 ( V_32 ) ;
if ( F_18 ( V_5 ) ) {
F_25 ( & V_30 -> V_33 , L_7 ) ;
V_6 = F_19 ( V_5 ) ;
goto V_42;
}
V_4 -> V_5 = V_5 ;
return 0 ;
V_42:
if ( V_4 -> V_18 )
F_28 ( & V_4 -> V_18 -> V_33 ) ;
return V_6 ;
}
static int F_29 ( struct V_29 * V_30 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_6 ;
V_4 = F_30 ( & V_30 -> V_33 , sizeof( * V_4 ) , V_43 ) ;
if ( V_4 == NULL )
return - V_44 ;
F_31 ( V_30 , V_4 ) ;
V_6 = F_15 ( V_30 ) ;
if ( V_6 )
return V_6 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_33 = & V_30 -> V_33 ;
V_2 -> V_45 = & V_46 ;
V_2 -> type = V_47 ;
V_2 -> V_48 = V_49 ;
V_2 -> V_27 . V_13 = V_4 -> V_13 ;
V_6 = F_32 ( V_2 ) ;
if ( V_6 ) {
F_25 ( & V_30 -> V_33 , L_8 ) ;
goto V_50;
}
return 0 ;
V_50:
F_33 ( V_4 -> V_5 ) ;
return V_6 ;
}
static int T_1 F_34 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = F_16 ( V_30 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_5 = V_4 -> V_5 ;
F_35 ( V_2 ) ;
F_10 ( V_2 ) ;
F_4 ( V_2 ) ;
F_33 ( V_5 ) ;
if ( V_4 -> V_18 )
F_28 ( & V_4 -> V_18 -> V_33 ) ;
return 0 ;
}

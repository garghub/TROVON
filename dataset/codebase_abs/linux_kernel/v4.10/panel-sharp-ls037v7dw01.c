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
if ( V_4 -> V_12 )
V_5 -> V_7 . V_8 -> V_13 ( V_5 , V_4 -> V_12 ) ;
V_5 -> V_7 . V_8 -> V_14 ( V_5 , & V_4 -> V_15 ) ;
if ( V_4 -> V_16 ) {
V_6 = F_7 ( V_4 -> V_16 ) ;
if ( V_6 != 0 )
return V_6 ;
}
V_6 = V_5 -> V_7 . V_8 -> V_17 ( V_5 ) ;
if ( V_6 ) {
F_8 ( V_4 -> V_16 ) ;
return V_6 ;
}
F_9 ( 50 ) ;
if ( V_4 -> V_18 )
F_10 ( V_4 -> V_18 , 1 ) ;
if ( V_4 -> V_19 )
F_10 ( V_4 -> V_19 , 1 ) ;
V_2 -> V_20 = V_21 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
if ( ! F_6 ( V_2 ) )
return;
if ( V_4 -> V_19 )
F_10 ( V_4 -> V_19 , 0 ) ;
if ( V_4 -> V_18 )
F_10 ( V_4 -> V_18 , 0 ) ;
F_9 ( 100 ) ;
V_5 -> V_7 . V_8 -> V_22 ( V_5 ) ;
if ( V_4 -> V_16 )
F_8 ( V_4 -> V_16 ) ;
V_2 -> V_20 = V_23 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
V_4 -> V_15 = * V_25 ;
V_2 -> V_26 . V_25 = * V_25 ;
V_5 -> V_7 . V_8 -> V_14 ( V_5 , V_25 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_25 = V_4 -> V_15 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
return V_5 -> V_7 . V_8 -> V_27 ( V_5 , V_25 ) ;
}
static int F_15 ( struct V_28 * V_29 , int V_30 , int V_31 ,
const char * V_32 , struct V_33 * * V_34 )
{
struct V_33 * V_35 ;
* V_34 = NULL ;
V_35 = F_16 ( V_29 , V_32 , V_30 , V_36 ) ;
if ( F_17 ( V_35 ) )
return F_18 ( V_35 ) ;
* V_34 = V_35 ;
return 0 ;
}
static int F_19 ( struct V_37 * V_38 )
{
struct V_3 * V_4 = F_20 ( V_38 ) ;
struct V_39 * V_40 = V_38 -> V_29 . V_41 ;
struct V_1 * V_5 ;
int V_6 ;
V_4 -> V_16 = F_21 ( & V_38 -> V_29 , L_1 ) ;
if ( F_17 ( V_4 -> V_16 ) ) {
F_22 ( & V_38 -> V_29 , L_2 ) ;
return F_18 ( V_4 -> V_16 ) ;
}
V_6 = F_15 ( & V_38 -> V_29 , 0 , 0 , L_3 , & V_4 -> V_19 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_15 ( & V_38 -> V_29 , 0 , 0 , L_4 , & V_4 -> V_18 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_15 ( & V_38 -> V_29 , 0 , 0 , L_5 , & V_4 -> V_42 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_15 ( & V_38 -> V_29 , 1 , 1 , L_5 , & V_4 -> V_43 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_15 ( & V_38 -> V_29 , 2 , 1 , L_5 , & V_4 -> V_44 ) ;
if ( V_6 )
return V_6 ;
V_5 = F_23 ( V_40 ) ;
if ( F_17 ( V_5 ) ) {
F_22 ( & V_38 -> V_29 , L_6 ) ;
return F_18 ( V_5 ) ;
}
V_4 -> V_5 = V_5 ;
return 0 ;
}
static int F_24 ( struct V_37 * V_38 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_6 ;
if ( ! V_38 -> V_29 . V_41 )
return - V_11 ;
V_4 = F_25 ( & V_38 -> V_29 , sizeof( * V_4 ) , V_45 ) ;
if ( V_4 == NULL )
return - V_46 ;
F_26 ( V_38 , V_4 ) ;
V_6 = F_19 ( V_38 ) ;
if ( V_6 )
return V_6 ;
V_4 -> V_15 = V_47 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_29 = & V_38 -> V_29 ;
V_2 -> V_48 = & V_49 ;
V_2 -> type = V_50 ;
V_2 -> V_51 = V_52 ;
V_2 -> V_26 . V_25 = V_4 -> V_15 ;
V_2 -> V_53 . V_8 . V_12 = V_4 -> V_12 ;
V_6 = F_27 ( V_2 ) ;
if ( V_6 ) {
F_22 ( & V_38 -> V_29 , L_7 ) ;
goto V_54;
}
return 0 ;
V_54:
F_28 ( V_4 -> V_5 ) ;
return V_6 ;
}
static int T_1 F_29 ( struct V_37 * V_38 )
{
struct V_3 * V_4 = F_20 ( V_38 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_5 = V_4 -> V_5 ;
F_30 ( V_2 ) ;
F_11 ( V_2 ) ;
F_4 ( V_2 ) ;
F_28 ( V_5 ) ;
return 0 ;
}

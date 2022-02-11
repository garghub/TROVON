static int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_7 ;
F_3 ( V_2 -> V_8 , L_1 ) ;
if ( F_4 ( V_2 ) )
return - V_9 ;
V_7 = V_6 -> V_10 . V_11 -> V_12 ( V_6 , V_2 ) ;
if ( V_7 )
return V_7 ;
V_3 -> V_13 = V_2 ;
V_2 -> V_3 = V_3 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_3 ( V_2 -> V_8 , L_2 ) ;
F_6 ( ! F_4 ( V_2 ) ) ;
if ( ! F_4 ( V_2 ) )
return;
F_6 ( V_3 != V_2 -> V_3 ) ;
if ( V_3 != V_2 -> V_3 )
return;
V_3 -> V_13 = NULL ;
V_2 -> V_3 = NULL ;
V_6 -> V_10 . V_11 -> V_14 ( V_6 , & V_5 -> V_2 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_7 ;
F_3 ( V_2 -> V_8 , L_3 ) ;
if ( ! F_4 ( V_2 ) )
return - V_15 ;
if ( F_8 ( V_2 ) )
return 0 ;
V_6 -> V_10 . V_11 -> V_16 ( V_6 , & V_5 -> V_17 ) ;
V_7 = V_6 -> V_10 . V_11 -> V_18 ( V_6 ) ;
if ( V_7 )
return V_7 ;
if ( V_5 -> V_19 )
F_9 ( V_5 -> V_19 , 1 ) ;
V_2 -> V_20 = V_21 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_3 ( V_2 -> V_8 , L_4 ) ;
if ( ! F_8 ( V_2 ) )
return;
if ( V_5 -> V_19 )
F_9 ( V_5 -> V_19 , 0 ) ;
V_6 -> V_10 . V_11 -> V_22 ( V_6 ) ;
V_2 -> V_20 = V_23 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_24 * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_3 ( V_2 -> V_8 , L_5 ) ;
V_5 -> V_17 = * V_17 ;
V_2 -> V_25 . V_17 = * V_17 ;
V_6 -> V_10 . V_11 -> V_16 ( V_6 , V_17 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_24 * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_2 -> V_8 , L_6 ) ;
* V_17 = V_5 -> V_17 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_24 * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_3 ( V_2 -> V_8 , L_7 ) ;
return V_6 -> V_10 . V_11 -> V_26 ( V_6 , V_17 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
enum V_27 type )
{
F_6 ( type != V_28 ) ;
}
static int F_15 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_8 . V_33 ;
struct V_4 * V_5 ;
struct V_1 * V_2 , * V_6 ;
struct V_34 * V_35 ;
int V_7 ;
F_3 ( & V_30 -> V_8 , L_8 ) ;
if ( V_32 == NULL ) {
F_16 ( & V_30 -> V_8 , L_9 ) ;
return - V_36 ;
}
V_5 = F_17 ( & V_30 -> V_8 , sizeof( * V_5 ) , V_37 ) ;
if ( ! V_5 )
return - V_38 ;
F_18 ( V_30 , V_5 ) ;
V_35 = F_19 ( & V_30 -> V_8 , L_10 , V_39 ) ;
if ( F_20 ( V_35 ) )
return F_21 ( V_35 ) ;
V_5 -> V_19 = V_35 ;
V_6 = F_22 ( V_32 ) ;
if ( F_20 ( V_6 ) ) {
F_16 ( & V_30 -> V_8 , L_11 ) ;
return F_21 ( V_6 ) ;
}
V_5 -> V_6 = V_6 ;
V_2 = & V_5 -> V_2 ;
V_2 -> V_10 . V_11 = & V_40 ;
V_2 -> V_8 = & V_30 -> V_8 ;
V_2 -> type = V_41 ;
V_2 -> V_42 = V_41 ;
V_2 -> V_43 = V_44 ;
V_7 = F_23 ( V_2 ) ;
if ( V_7 ) {
F_16 ( & V_30 -> V_8 , L_12 ) ;
goto V_45;
}
return 0 ;
V_45:
F_24 ( V_5 -> V_6 ) ;
return V_7 ;
}
static int T_1 F_25 ( struct V_29 * V_30 )
{
struct V_4 * V_5 = F_26 ( V_30 ) ;
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_27 ( & V_5 -> V_2 ) ;
F_6 ( F_8 ( V_2 ) ) ;
if ( F_8 ( V_2 ) )
F_10 ( V_2 ) ;
F_6 ( F_4 ( V_2 ) ) ;
if ( F_4 ( V_2 ) )
F_5 ( V_2 , V_2 -> V_3 ) ;
F_24 ( V_6 ) ;
return 0 ;
}

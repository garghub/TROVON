int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = F_2 ( V_7 ) ;
if ( F_3 ( V_6 ) )
return - V_8 ;
V_4 = F_4 ( V_6 ) ;
V_4 -> V_2 = V_2 ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 , bool V_11 )
{
struct V_3 * V_4 = F_4 ( V_10 -> V_4 ) ;
if ( ! V_4 -> V_2 )
return - V_8 ;
return V_4 -> V_2 -> V_12 ( V_4 -> V_2 , V_11 ) ;
}
static int F_6 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = F_4 ( V_10 -> V_4 ) ;
if ( ! V_4 -> V_2 )
return - V_8 ;
return V_4 -> V_2 -> V_13 ( V_4 -> V_2 ) ;
}
static int F_7 ( struct V_9 * V_10 , struct V_14 * V_15 )
{
struct V_5 * V_4 = V_10 -> V_4 ;
V_10 -> V_15 = V_15 ;
if ( ! V_15 )
V_4 -> V_16 = V_17 ;
return 0 ;
}
static int F_8 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_5 * V_4 = V_10 -> V_4 ;
V_10 -> V_19 = V_19 ;
if ( ! V_19 )
V_4 -> V_16 = V_17 ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , int V_20 )
{
struct V_3 * V_4 = F_4 ( V_6 ) ;
int V_21 ;
if ( V_20 && ! V_4 -> V_22 ) {
F_10 ( V_4 -> V_23 , 0 ) ;
F_11 ( V_4 -> V_24 ) ;
V_4 -> V_22 = 1 ;
} else if ( ! V_20 && V_4 -> V_22 ) {
V_21 = F_12 ( V_4 -> V_24 ) ;
if ( V_21 < 0 ) {
F_13 ( V_4 -> V_24 , L_1 , V_21 ) ;
return V_21 ;
}
F_10 ( V_4 -> V_23 , 1 ) ;
V_4 -> V_22 = 0 ;
}
return 0 ;
}
static int F_14 ( struct V_4 * V_6 )
{
struct V_3 * V_4 = F_15 ( V_6 ) ;
F_10 ( V_4 -> V_23 , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_4 * V_6 )
{
struct V_3 * V_4 = F_15 ( V_6 ) ;
F_10 ( V_4 -> V_23 , 1 ) ;
return 0 ;
}
static int F_17 ( struct V_25 * V_26 )
{
struct V_3 * V_4 ;
struct V_4 * V_27 ;
struct V_28 * V_28 ;
struct V_9 * V_10 ;
struct V_29 * V_30 = V_26 -> V_24 . V_31 ;
struct V_29 * V_32 ;
struct V_25 * V_33 ;
if ( ! V_30 )
return - V_34 ;
V_4 = F_18 ( & V_26 -> V_24 , sizeof( * V_4 ) , V_35 ) ;
if ( ! V_4 ) {
F_13 ( & V_26 -> V_24 , L_2 ) ;
return - V_36 ;
}
V_10 = F_18 ( & V_26 -> V_24 , sizeof( * V_10 ) , V_35 ) ;
if ( ! V_10 ) {
F_13 ( & V_26 -> V_24 , L_3 ) ;
return - V_36 ;
}
V_4 -> V_24 = & V_26 -> V_24 ;
V_4 -> V_4 . V_24 = V_4 -> V_24 ;
V_4 -> V_4 . V_37 = L_4 ;
V_4 -> V_4 . V_38 = F_9 ;
V_4 -> V_4 . V_10 = V_10 ;
V_4 -> V_4 . type = V_7 ;
V_32 = F_19 ( V_30 , L_5 , 0 ) ;
if ( ! V_32 ) {
F_13 ( & V_26 -> V_24 , L_6 ) ;
return - V_34 ;
}
V_33 = F_20 ( V_32 ) ;
if ( ! V_33 ) {
F_13 ( & V_26 -> V_24 , L_7 ) ;
return - V_34 ;
}
V_4 -> V_23 = & V_33 -> V_24 ;
V_4 -> V_22 = 1 ;
F_10 ( V_4 -> V_23 , 0 ) ;
V_10 -> V_39 = F_7 ;
V_10 -> V_40 = F_8 ;
V_10 -> V_12 = F_5 ;
V_10 -> V_13 = F_6 ;
V_10 -> V_4 = & V_4 -> V_4 ;
F_21 ( V_26 , V_4 ) ;
F_22 ( V_4 -> V_24 ) ;
V_27 = F_23 ( V_4 -> V_24 , & V_41 , NULL ) ;
if ( F_3 ( V_27 ) )
return F_24 ( V_27 ) ;
F_25 ( V_27 , V_4 ) ;
V_28 = F_26 ( V_4 -> V_24 ,
V_42 ) ;
if ( F_3 ( V_28 ) )
return F_24 ( V_28 ) ;
V_4 -> V_43 = F_27 ( V_4 -> V_24 , L_8 ) ;
if ( F_3 ( V_4 -> V_43 ) ) {
F_13 ( & V_26 -> V_24 , L_9 ) ;
return F_24 ( V_4 -> V_43 ) ;
}
F_28 ( V_4 -> V_43 ) ;
V_4 -> V_44 = F_27 ( V_4 -> V_24 , L_10 ) ;
if ( F_3 ( V_4 -> V_44 ) )
F_29 ( & V_26 -> V_24 , L_11 ) ;
else
F_28 ( V_4 -> V_44 ) ;
F_30 ( & V_4 -> V_4 ) ;
return 0 ;
}
static int F_31 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_32 ( V_26 ) ;
F_33 ( V_4 -> V_43 ) ;
if ( ! F_3 ( V_4 -> V_44 ) )
F_33 ( V_4 -> V_44 ) ;
F_34 ( & V_4 -> V_4 ) ;
return 0 ;
}
static int F_35 ( struct V_45 * V_24 )
{
struct V_25 * V_26 = F_36 ( V_24 ) ;
struct V_3 * V_4 = F_32 ( V_26 ) ;
F_37 ( V_4 -> V_43 ) ;
if ( ! F_3 ( V_4 -> V_44 ) )
F_37 ( V_4 -> V_44 ) ;
return 0 ;
}
static int F_38 ( struct V_45 * V_24 )
{
struct V_25 * V_26 = F_36 ( V_24 ) ;
struct V_3 * V_4 = F_32 ( V_26 ) ;
int V_21 ;
V_21 = F_39 ( V_4 -> V_43 ) ;
if ( V_21 < 0 ) {
F_13 ( V_4 -> V_24 , L_12 , V_21 ) ;
goto V_46;
}
if ( ! F_3 ( V_4 -> V_44 ) ) {
V_21 = F_39 ( V_4 -> V_44 ) ;
if ( V_21 < 0 ) {
F_13 ( V_4 -> V_24 , L_13 , V_21 ) ;
goto V_47;
}
}
return 0 ;
V_47:
F_37 ( V_4 -> V_43 ) ;
V_46:
return V_21 ;
}

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
struct V_3 * V_4 = F_4 ( V_10 -> V_5 ) ;
if ( ! V_4 -> V_2 )
return - V_8 ;
return V_4 -> V_2 -> V_12 ( V_4 -> V_2 , V_11 ) ;
}
static int F_6 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = F_4 ( V_10 -> V_5 ) ;
if ( ! V_4 -> V_2 )
return - V_8 ;
return V_4 -> V_2 -> V_13 ( V_4 -> V_2 ) ;
}
static int F_7 ( struct V_9 * V_10 , struct V_14 * V_15 )
{
V_10 -> V_15 = V_15 ;
if ( ! V_15 )
V_10 -> V_16 = V_17 ;
return 0 ;
}
static int F_8 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
V_10 -> V_19 = V_19 ;
if ( ! V_19 )
V_10 -> V_16 = V_17 ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 , int V_20 )
{
T_1 V_21 ;
int V_22 ;
if ( ! V_4 -> V_23 ) {
F_10 ( V_4 -> V_24 , V_20 ) ;
return 0 ;
}
if ( V_20 )
V_21 = V_4 -> V_25 ;
else
V_21 = V_4 -> V_26 ;
V_22 = F_11 ( V_4 -> V_23 , V_4 -> V_27 ,
V_4 -> V_28 , V_21 ) ;
return V_22 ;
}
static int F_12 ( struct V_4 * V_6 )
{
struct V_3 * V_4 = F_13 ( V_6 ) ;
return F_9 ( V_4 , false ) ;
}
static int F_14 ( struct V_4 * V_6 )
{
struct V_3 * V_4 = F_13 ( V_6 ) ;
return F_9 ( V_4 , true ) ;
}
static int F_15 ( struct V_3 * V_4 )
{
F_16 ( V_4 -> V_29 ) ;
if ( ! F_3 ( V_4 -> V_30 ) )
F_16 ( V_4 -> V_30 ) ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 )
{
int V_22 ;
V_22 = F_18 ( V_4 -> V_29 ) ;
if ( V_22 < 0 ) {
F_19 ( V_4 -> V_31 , L_1 , V_22 ) ;
goto V_32;
}
if ( ! F_3 ( V_4 -> V_30 ) ) {
V_22 = F_18 ( V_4 -> V_30 ) ;
if ( V_22 < 0 ) {
F_19 ( V_4 -> V_31 , L_2 , V_22 ) ;
goto V_33;
}
}
return 0 ;
V_33:
F_16 ( V_4 -> V_29 ) ;
V_32:
return V_22 ;
}
static int F_20 ( struct V_4 * V_6 )
{
struct V_3 * V_4 = F_13 ( V_6 ) ;
T_1 V_21 ;
F_17 ( V_4 ) ;
if ( V_4 -> V_34 & V_35 ) {
V_21 = F_21 ( V_4 -> V_36 , V_37 ) ;
V_21 |= V_38 ;
F_22 ( V_4 -> V_36 , V_37 , V_21 ) ;
}
return 0 ;
}
static int F_23 ( struct V_4 * V_6 )
{
struct V_3 * V_4 = F_13 ( V_6 ) ;
return F_15 ( V_4 ) ;
}
static int F_24 ( struct V_39 * V_40 )
{
struct V_3 * V_4 ;
struct V_4 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_44 ;
struct V_9 * V_10 ;
struct V_45 * V_46 = V_40 -> V_31 . V_47 ;
struct V_45 * V_48 ;
struct V_39 * V_49 ;
const struct V_50 * V_51 ;
struct V_52 * V_53 ;
V_51 = F_25 ( V_54 , & V_40 -> V_31 ) ;
if ( ! V_51 )
return - V_55 ;
V_53 = (struct V_52 * ) V_51 -> V_56 ;
V_4 = F_26 ( & V_40 -> V_31 , sizeof( * V_4 ) , V_57 ) ;
if ( ! V_4 )
return - V_58 ;
V_10 = F_26 ( & V_40 -> V_31 , sizeof( * V_10 ) , V_57 ) ;
if ( ! V_10 )
return - V_58 ;
V_4 -> V_31 = & V_40 -> V_31 ;
V_4 -> V_4 . V_31 = V_4 -> V_31 ;
V_4 -> V_4 . V_59 = V_53 -> V_59 ;
V_4 -> V_4 . V_10 = V_10 ;
V_4 -> V_4 . type = V_7 ;
V_4 -> V_28 = V_53 -> V_28 ;
V_4 -> V_25 = V_53 -> V_25 ;
V_4 -> V_26 = V_53 -> V_26 ;
if ( V_53 -> V_34 & V_35 ) {
V_43 = F_27 ( V_40 , V_60 , 0 ) ;
V_4 -> V_36 = F_28 ( & V_40 -> V_31 , V_43 ) ;
if ( F_3 ( V_4 -> V_36 ) )
return F_29 ( V_4 -> V_36 ) ;
V_4 -> V_34 |= V_35 ;
}
V_4 -> V_23 = F_30 ( V_46 ,
L_3 ) ;
if ( F_3 ( V_4 -> V_23 ) ) {
F_31 ( & V_40 -> V_31 ,
L_4 ) ;
V_4 -> V_23 = NULL ;
V_48 = F_32 ( V_46 , L_5 , 0 ) ;
if ( ! V_48 ) {
F_19 ( & V_40 -> V_31 ,
L_6 ) ;
return - V_55 ;
}
V_49 = F_33 ( V_48 ) ;
if ( ! V_49 ) {
F_19 ( & V_40 -> V_31 , L_7 ) ;
return - V_55 ;
}
V_4 -> V_24 = & V_49 -> V_31 ;
} else {
if ( F_34 ( V_46 ,
L_3 , 1 ,
& V_4 -> V_27 ) ) {
F_19 ( & V_40 -> V_31 ,
L_8 ) ;
return - V_55 ;
}
}
V_10 -> V_61 = F_7 ;
V_10 -> V_62 = F_8 ;
if ( V_53 -> V_34 & V_63 )
V_10 -> V_12 = F_5 ;
if ( V_53 -> V_34 & V_64 )
V_10 -> V_13 = F_6 ;
V_10 -> V_5 = & V_4 -> V_4 ;
F_35 ( V_40 , V_4 ) ;
F_36 ( V_4 -> V_31 ) ;
V_41 = F_37 ( V_4 -> V_31 , NULL , & V_65 ) ;
if ( F_3 ( V_41 ) ) {
F_38 ( V_4 -> V_31 ) ;
return F_29 ( V_41 ) ;
}
F_39 ( V_41 , V_4 ) ;
F_12 ( V_41 ) ;
V_44 = F_40 ( V_4 -> V_31 ,
V_66 ) ;
if ( F_3 ( V_44 ) ) {
F_38 ( V_4 -> V_31 ) ;
return F_29 ( V_44 ) ;
}
V_4 -> V_29 = F_41 ( V_4 -> V_31 , L_9 ) ;
if ( F_3 ( V_4 -> V_29 ) ) {
F_42 ( & V_40 -> V_31 , L_10 ) ;
V_4 -> V_29 = F_41 ( V_4 -> V_31 , L_11 ) ;
if ( F_3 ( V_4 -> V_29 ) ) {
F_19 ( & V_40 -> V_31 , L_12 ) ;
F_38 ( V_4 -> V_31 ) ;
return F_29 ( V_4 -> V_29 ) ;
} else {
F_42 ( & V_40 -> V_31 ,
L_13 ) ;
}
}
F_43 ( V_4 -> V_29 ) ;
V_4 -> V_30 = F_41 ( V_4 -> V_31 , L_14 ) ;
if ( F_3 ( V_4 -> V_30 ) ) {
F_31 ( & V_40 -> V_31 , L_15 ) ;
V_4 -> V_30 = F_41 ( V_4 -> V_31 , L_16 ) ;
if ( F_3 ( V_4 -> V_30 ) ) {
F_31 ( & V_40 -> V_31 ,
L_17 ) ;
} else {
F_42 ( & V_40 -> V_31 ,
L_18 ) ;
}
}
if ( ! F_3 ( V_4 -> V_30 ) )
F_43 ( V_4 -> V_30 ) ;
F_44 ( & V_4 -> V_4 ) ;
return 0 ;
}
static int F_45 ( struct V_39 * V_40 )
{
struct V_3 * V_4 = F_46 ( V_40 ) ;
F_47 ( V_4 -> V_29 ) ;
if ( ! F_3 ( V_4 -> V_30 ) )
F_47 ( V_4 -> V_30 ) ;
F_48 ( & V_4 -> V_4 ) ;
F_38 ( V_4 -> V_31 ) ;
return 0 ;
}

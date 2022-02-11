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
static int F_15 ( struct V_4 * V_6 )
{
struct V_3 * V_4 = F_13 ( V_6 ) ;
T_1 V_21 ;
if ( V_4 -> V_29 & V_30 ) {
V_21 = F_16 ( V_4 -> V_31 , V_32 ) ;
V_21 |= V_33 ;
F_17 ( V_4 -> V_31 , V_32 , V_21 ) ;
}
return 0 ;
}
static int F_18 ( struct V_34 * V_35 )
{
struct V_3 * V_4 ;
struct V_4 * V_36 ;
struct V_37 * V_38 ;
struct V_39 * V_39 ;
struct V_9 * V_10 ;
struct V_40 * V_41 = V_35 -> V_42 . V_43 ;
struct V_40 * V_44 ;
struct V_34 * V_45 ;
const struct V_46 * V_47 ;
struct V_48 * V_49 ;
V_47 = F_19 ( V_50 , & V_35 -> V_42 ) ;
if ( ! V_47 )
return - V_51 ;
V_49 = (struct V_48 * ) V_47 -> V_52 ;
V_4 = F_20 ( & V_35 -> V_42 , sizeof( * V_4 ) , V_53 ) ;
if ( ! V_4 )
return - V_54 ;
V_10 = F_20 ( & V_35 -> V_42 , sizeof( * V_10 ) , V_53 ) ;
if ( ! V_10 )
return - V_54 ;
V_4 -> V_42 = & V_35 -> V_42 ;
V_4 -> V_4 . V_42 = V_4 -> V_42 ;
V_4 -> V_4 . V_55 = V_49 -> V_55 ;
V_4 -> V_4 . V_10 = V_10 ;
V_4 -> V_4 . type = V_7 ;
V_4 -> V_28 = V_49 -> V_28 ;
V_4 -> V_25 = V_49 -> V_25 ;
V_4 -> V_26 = V_49 -> V_26 ;
if ( V_49 -> V_29 & V_30 ) {
V_38 = F_21 ( V_35 , V_56 , 0 ) ;
V_4 -> V_31 = F_22 ( & V_35 -> V_42 , V_38 ) ;
if ( F_3 ( V_4 -> V_31 ) )
return F_23 ( V_4 -> V_31 ) ;
V_4 -> V_29 |= V_30 ;
}
V_4 -> V_23 = F_24 ( V_41 ,
L_1 ) ;
if ( F_3 ( V_4 -> V_23 ) ) {
F_25 ( & V_35 -> V_42 ,
L_2 ) ;
V_4 -> V_23 = NULL ;
V_44 = F_26 ( V_41 , L_3 , 0 ) ;
if ( ! V_44 ) {
F_27 ( & V_35 -> V_42 ,
L_4 ) ;
return - V_51 ;
}
V_45 = F_28 ( V_44 ) ;
if ( ! V_45 ) {
F_27 ( & V_35 -> V_42 , L_5 ) ;
return - V_51 ;
}
V_4 -> V_24 = & V_45 -> V_42 ;
} else {
if ( F_29 ( V_41 ,
L_1 , 1 ,
& V_4 -> V_27 ) ) {
F_27 ( & V_35 -> V_42 ,
L_6 ) ;
return - V_51 ;
}
}
V_10 -> V_57 = F_7 ;
V_10 -> V_58 = F_8 ;
if ( V_49 -> V_29 & V_59 )
V_10 -> V_12 = F_5 ;
if ( V_49 -> V_29 & V_60 )
V_10 -> V_13 = F_6 ;
V_10 -> V_5 = & V_4 -> V_4 ;
F_30 ( V_35 , V_4 ) ;
F_31 ( V_4 -> V_42 ) ;
V_36 = F_32 ( V_4 -> V_42 , NULL , & V_61 ) ;
if ( F_3 ( V_36 ) ) {
F_33 ( V_4 -> V_42 ) ;
return F_23 ( V_36 ) ;
}
F_34 ( V_36 , V_4 ) ;
F_12 ( V_36 ) ;
V_39 = F_35 ( V_4 -> V_42 ,
V_62 ) ;
if ( F_3 ( V_39 ) ) {
F_33 ( V_4 -> V_42 ) ;
return F_23 ( V_39 ) ;
}
V_4 -> V_63 = F_36 ( V_4 -> V_42 , L_7 ) ;
if ( F_3 ( V_4 -> V_63 ) ) {
F_37 ( & V_35 -> V_42 , L_8 ) ;
V_4 -> V_63 = F_36 ( V_4 -> V_42 , L_9 ) ;
if ( F_3 ( V_4 -> V_63 ) ) {
F_27 ( & V_35 -> V_42 , L_10 ) ;
F_33 ( V_4 -> V_42 ) ;
return F_23 ( V_4 -> V_63 ) ;
} else {
F_37 ( & V_35 -> V_42 ,
L_11 ) ;
}
}
F_38 ( V_4 -> V_63 ) ;
V_4 -> V_64 = F_36 ( V_4 -> V_42 , L_12 ) ;
if ( F_3 ( V_4 -> V_64 ) ) {
F_25 ( & V_35 -> V_42 , L_13 ) ;
V_4 -> V_64 = F_36 ( V_4 -> V_42 , L_14 ) ;
if ( F_3 ( V_4 -> V_64 ) ) {
F_25 ( & V_35 -> V_42 ,
L_15 ) ;
} else {
F_37 ( & V_35 -> V_42 ,
L_16 ) ;
}
}
if ( ! F_3 ( V_4 -> V_64 ) )
F_38 ( V_4 -> V_64 ) ;
F_39 ( & V_4 -> V_4 ) ;
return 0 ;
}
static int F_40 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_41 ( V_35 ) ;
F_42 ( V_4 -> V_63 ) ;
if ( ! F_3 ( V_4 -> V_64 ) )
F_42 ( V_4 -> V_64 ) ;
F_43 ( & V_4 -> V_4 ) ;
F_33 ( V_4 -> V_42 ) ;
return 0 ;
}
static int F_44 ( struct V_65 * V_42 )
{
struct V_34 * V_35 = F_45 ( V_42 ) ;
struct V_3 * V_4 = F_41 ( V_35 ) ;
F_46 ( V_4 -> V_63 ) ;
if ( ! F_3 ( V_4 -> V_64 ) )
F_46 ( V_4 -> V_64 ) ;
return 0 ;
}
static int F_47 ( struct V_65 * V_42 )
{
struct V_34 * V_35 = F_45 ( V_42 ) ;
struct V_3 * V_4 = F_41 ( V_35 ) ;
int V_22 ;
V_22 = F_48 ( V_4 -> V_63 ) ;
if ( V_22 < 0 ) {
F_27 ( V_4 -> V_42 , L_17 , V_22 ) ;
goto V_66;
}
if ( ! F_3 ( V_4 -> V_64 ) ) {
V_22 = F_48 ( V_4 -> V_64 ) ;
if ( V_22 < 0 ) {
F_27 ( V_4 -> V_42 , L_18 , V_22 ) ;
goto V_67;
}
}
return 0 ;
V_67:
F_46 ( V_4 -> V_63 ) ;
V_66:
return V_22 ;
}

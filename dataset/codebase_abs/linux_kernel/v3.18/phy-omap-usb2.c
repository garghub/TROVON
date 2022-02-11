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
static int F_9 ( struct V_4 * V_6 )
{
struct V_3 * V_4 = F_10 ( V_6 ) ;
F_11 ( V_4 -> V_20 , 0 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_6 )
{
struct V_3 * V_4 = F_10 ( V_6 ) ;
F_11 ( V_4 -> V_20 , 1 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_6 )
{
struct V_3 * V_4 = F_10 ( V_6 ) ;
T_1 V_21 ;
if ( V_4 -> V_22 & V_23 ) {
V_21 = F_14 ( V_4 -> V_24 , V_25 ) ;
V_21 |= V_26 ;
F_15 ( V_4 -> V_24 , V_25 , V_21 ) ;
}
return 0 ;
}
static int F_16 ( struct V_27 * V_28 )
{
struct V_3 * V_4 ;
struct V_4 * V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_32 ;
struct V_9 * V_10 ;
struct V_33 * V_34 = V_28 -> V_35 . V_36 ;
struct V_33 * V_37 ;
struct V_27 * V_38 ;
const struct V_39 * V_40 ;
struct V_41 * V_42 ;
V_40 = F_17 ( F_18 ( V_43 ) , & V_28 -> V_35 ) ;
if ( ! V_40 )
return - V_44 ;
V_42 = (struct V_41 * ) V_40 -> V_45 ;
V_4 = F_19 ( & V_28 -> V_35 , sizeof( * V_4 ) , V_46 ) ;
if ( ! V_4 )
return - V_47 ;
V_10 = F_19 ( & V_28 -> V_35 , sizeof( * V_10 ) , V_46 ) ;
if ( ! V_10 )
return - V_47 ;
V_4 -> V_35 = & V_28 -> V_35 ;
V_4 -> V_4 . V_35 = V_4 -> V_35 ;
V_4 -> V_4 . V_48 = V_42 -> V_48 ;
V_4 -> V_4 . V_10 = V_10 ;
V_4 -> V_4 . type = V_7 ;
if ( V_42 -> V_22 & V_23 ) {
V_31 = F_20 ( V_28 , V_49 , 0 ) ;
V_4 -> V_24 = F_21 ( & V_28 -> V_35 , V_31 ) ;
if ( F_3 ( V_4 -> V_24 ) )
return F_22 ( V_4 -> V_24 ) ;
V_4 -> V_22 |= V_23 ;
}
V_37 = F_23 ( V_34 , L_1 , 0 ) ;
if ( ! V_37 ) {
F_24 ( & V_28 -> V_35 , L_2 ) ;
return - V_44 ;
}
V_38 = F_25 ( V_37 ) ;
if ( ! V_38 ) {
F_24 ( & V_28 -> V_35 , L_3 ) ;
return - V_44 ;
}
V_4 -> V_20 = & V_38 -> V_35 ;
F_11 ( V_4 -> V_20 , 0 ) ;
V_10 -> V_50 = F_7 ;
V_10 -> V_51 = F_8 ;
if ( V_42 -> V_22 & V_52 )
V_10 -> V_12 = F_5 ;
if ( V_42 -> V_22 & V_53 )
V_10 -> V_13 = F_6 ;
V_10 -> V_4 = & V_4 -> V_4 ;
F_26 ( V_28 , V_4 ) ;
F_27 ( V_4 -> V_35 ) ;
V_29 = F_28 ( V_4 -> V_35 , NULL , & V_54 , NULL ) ;
if ( F_3 ( V_29 ) ) {
F_29 ( V_4 -> V_35 ) ;
return F_22 ( V_29 ) ;
}
F_30 ( V_29 , V_4 ) ;
V_32 = F_31 ( V_4 -> V_35 ,
V_55 ) ;
if ( F_3 ( V_32 ) ) {
F_29 ( V_4 -> V_35 ) ;
return F_22 ( V_32 ) ;
}
V_4 -> V_56 = F_32 ( V_4 -> V_35 , L_4 ) ;
if ( F_3 ( V_4 -> V_56 ) ) {
F_33 ( & V_28 -> V_35 , L_5 ) ;
V_4 -> V_56 = F_32 ( V_4 -> V_35 , L_6 ) ;
if ( F_3 ( V_4 -> V_56 ) ) {
F_24 ( & V_28 -> V_35 , L_7 ) ;
return F_22 ( V_4 -> V_56 ) ;
} else {
F_33 ( & V_28 -> V_35 ,
L_8 ) ;
}
}
F_34 ( V_4 -> V_56 ) ;
V_4 -> V_57 = F_32 ( V_4 -> V_35 , L_9 ) ;
if ( F_3 ( V_4 -> V_57 ) ) {
F_35 ( & V_28 -> V_35 , L_10 ) ;
V_4 -> V_57 = F_32 ( V_4 -> V_35 , L_11 ) ;
if ( F_3 ( V_4 -> V_57 ) ) {
F_35 ( & V_28 -> V_35 ,
L_12 ) ;
} else {
F_33 ( & V_28 -> V_35 ,
L_13 ) ;
}
} else {
F_34 ( V_4 -> V_57 ) ;
}
F_36 ( & V_4 -> V_4 ) ;
return 0 ;
}
static int F_37 ( struct V_27 * V_28 )
{
struct V_3 * V_4 = F_38 ( V_28 ) ;
F_39 ( V_4 -> V_56 ) ;
if ( ! F_3 ( V_4 -> V_57 ) )
F_39 ( V_4 -> V_57 ) ;
F_40 ( & V_4 -> V_4 ) ;
F_29 ( V_4 -> V_35 ) ;
return 0 ;
}
static int F_41 ( struct V_58 * V_35 )
{
struct V_27 * V_28 = F_42 ( V_35 ) ;
struct V_3 * V_4 = F_38 ( V_28 ) ;
F_43 ( V_4 -> V_56 ) ;
if ( ! F_3 ( V_4 -> V_57 ) )
F_43 ( V_4 -> V_57 ) ;
return 0 ;
}
static int F_44 ( struct V_58 * V_35 )
{
struct V_27 * V_28 = F_42 ( V_35 ) ;
struct V_3 * V_4 = F_38 ( V_28 ) ;
int V_59 ;
V_59 = F_45 ( V_4 -> V_56 ) ;
if ( V_59 < 0 ) {
F_24 ( V_4 -> V_35 , L_14 , V_59 ) ;
goto V_60;
}
if ( ! F_3 ( V_4 -> V_57 ) ) {
V_59 = F_45 ( V_4 -> V_57 ) ;
if ( V_59 < 0 ) {
F_24 ( V_4 -> V_35 , L_15 , V_59 ) ;
goto V_61;
}
}
return 0 ;
V_61:
F_43 ( V_4 -> V_56 ) ;
V_60:
return V_59 ;
}

static inline int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
int V_3 = F_2 ( V_1 , V_2 ) ;
if ( ! V_3 ) {
F_3 ( V_1 , V_2 ) ;
return 0 ;
}
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
return V_3 ;
}
static struct V_1 * F_6 ( struct V_2 * V_4 , struct V_1 * V_1 , struct V_5 * V_6 )
{
struct V_2 * V_2 = NULL ;
T_1 V_7 ;
if ( V_1 -> V_8 . V_9 > V_10 )
return F_7 ( - V_11 ) ;
F_8 ( V_4 -> V_12 ) ;
V_7 = F_9 ( V_4 , & V_1 -> V_8 ) ;
if ( V_7 )
V_2 = F_10 ( V_4 -> V_12 , V_7 ) ;
F_11 ( V_4 -> V_12 ) ;
return F_12 ( V_2 , V_1 ) ;
}
static int F_13 ( struct V_2 * V_4 , struct V_1 * V_1 , T_2 V_13 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 ;
int V_3 ;
F_14 ( L_1 ) ;
V_2 = F_15 ( V_4 , V_13 ) ;
V_3 = F_16 ( V_2 ) ;
if ( ! F_17 ( V_2 ) ) {
V_2 -> V_14 = & V_15 ;
V_2 -> V_16 = & V_17 ;
V_2 -> V_18 -> V_19 = & V_20 ;
F_18 ( V_2 ) ;
F_8 ( V_4 -> V_12 ) ;
V_3 = F_1 ( V_1 , V_2 ) ;
F_11 ( V_4 -> V_12 ) ;
}
F_14 ( L_2 , V_3 ) ;
return V_3 ;
}
static int F_19 ( struct V_2 * V_4 , struct V_1 * V_1 , T_2 V_13 , T_3 V_21 )
{
struct V_2 * V_2 ;
int V_3 ;
if ( ! F_20 ( V_21 ) )
return - V_22 ;
V_2 = F_15 ( V_4 , V_13 ) ;
V_3 = F_16 ( V_2 ) ;
if ( ! F_17 ( V_2 ) ) {
F_21 ( V_2 , V_13 , V_21 ) ;
F_22 ( V_2 -> V_12 , F_23 ( V_2 ) , V_21 ) ;
F_18 ( V_2 ) ;
F_8 ( V_4 -> V_12 ) ;
V_3 = F_1 ( V_1 , V_2 ) ;
F_11 ( V_4 -> V_12 ) ;
}
return V_3 ;
}
static int F_24 ( struct V_2 * V_4 , struct V_1 * V_1 ,
const char * V_23 )
{
struct V_24 * V_25 = V_4 -> V_12 ;
int V_3 = - V_11 ;
unsigned V_26 = strlen ( V_23 ) + 1 ;
struct V_2 * V_2 ;
if ( V_26 > V_25 -> V_27 )
goto V_28;
F_8 ( V_4 -> V_12 ) ;
V_2 = F_15 ( V_4 , V_29 | V_30 ) ;
V_3 = F_16 ( V_2 ) ;
if ( F_17 ( V_2 ) )
goto V_31;
if ( V_26 > F_25 ( V_25 ) -> V_32 -> V_33 ) {
V_2 -> V_14 = & V_34 ;
V_2 -> V_18 -> V_19 = & V_20 ;
V_3 = F_26 ( V_2 , V_23 , V_26 ) ;
if ( V_3 )
goto V_35;
} else {
V_2 -> V_14 = & V_36 ;
memcpy ( F_23 ( V_2 ) -> V_37 . V_38 , V_23 , V_26 ) ;
V_2 -> V_39 = V_26 - 1 ;
}
F_18 ( V_2 ) ;
V_3 = F_1 ( V_1 , V_2 ) ;
V_31:
F_11 ( V_4 -> V_12 ) ;
V_28:
return V_3 ;
V_35:
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
goto V_31;
}
static int F_27 ( struct V_1 * V_40 , struct V_2 * V_4 ,
struct V_1 * V_1 )
{
struct V_2 * V_2 = V_40 -> V_41 ;
int error ;
F_8 ( V_4 -> V_12 ) ;
V_2 -> V_42 = V_43 ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
error = F_1 ( V_1 , V_2 ) ;
F_11 ( V_4 -> V_12 ) ;
return error ;
}
static int F_30 ( struct V_2 * V_4 , struct V_1 * V_1 , T_2 V_13 )
{
struct V_2 * V_2 ;
int V_3 ;
F_8 ( V_4 -> V_12 ) ;
F_28 ( V_4 ) ;
V_2 = F_15 ( V_4 , V_44 | V_13 ) ;
V_3 = F_16 ( V_2 ) ;
if ( F_17 ( V_2 ) )
goto V_45;
V_2 -> V_14 = & V_46 ;
V_2 -> V_16 = & V_47 ;
V_2 -> V_18 -> V_19 = & V_20 ;
F_28 ( V_2 ) ;
V_3 = F_31 ( V_2 , V_4 ) ;
if ( V_3 )
goto V_35;
V_3 = F_2 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_35;
F_11 ( V_4 -> V_12 ) ;
F_3 ( V_1 , V_2 ) ;
V_31:
return V_3 ;
V_35:
F_4 ( V_2 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
V_45:
F_4 ( V_4 ) ;
F_11 ( V_4 -> V_12 ) ;
goto V_31;
}
static int F_32 ( struct V_2 * V_4 , struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_41 ;
struct V_48 * V_49 ;
struct V_50 * V_50 ;
int V_3 = - V_51 ;
V_49 = F_33 ( V_4 , & V_1 -> V_8 , & V_50 ) ;
if ( ! V_49 )
goto V_31;
V_3 = F_34 ( V_4 , V_49 , V_50 ) ;
if ( V_3 )
goto V_31;
V_2 -> V_42 = V_4 -> V_42 ;
F_4 ( V_2 ) ;
V_3 = 0 ;
V_31:
return V_3 ;
}
static int F_35 ( struct V_2 * V_4 , struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_41 ;
int V_3 = - V_52 ;
F_8 ( V_4 -> V_12 ) ;
if ( F_36 ( V_2 ) ) {
V_3 = F_32 ( V_4 , V_1 ) ;
if ( ! V_3 ) {
V_2 -> V_39 = 0 ;
F_4 ( V_2 ) ;
F_4 ( V_4 ) ;
}
}
F_11 ( V_4 -> V_12 ) ;
return V_3 ;
}
static int F_37 ( struct V_2 * V_53 , struct V_1 * V_40 ,
struct V_2 * V_54 , struct V_1 * V_55 )
{
struct V_2 * V_56 = V_40 -> V_41 ;
struct V_2 * V_57 = V_55 -> V_41 ;
struct V_50 * V_58 = NULL ;
struct V_48 * V_59 = NULL ;
struct V_50 * V_60 ;
struct V_48 * V_61 ;
int V_3 = - V_51 ;
V_61 = F_33 ( V_53 , & V_40 -> V_8 , & V_60 ) ;
if ( ! V_61 )
goto V_31;
if ( F_38 ( V_56 -> V_62 ) ) {
V_3 = - V_63 ;
V_59 = F_39 ( V_56 , & V_58 ) ;
if ( ! V_59 )
goto V_64;
}
if ( V_57 ) {
struct V_50 * V_65 ;
struct V_48 * V_66 ;
V_3 = - V_52 ;
if ( V_59 && ! F_36 ( V_57 ) )
goto V_45;
V_3 = - V_51 ;
V_66 = F_33 ( V_54 , & V_55 -> V_8 , & V_65 ) ;
if ( ! V_66 )
goto V_45;
F_40 ( V_54 , V_66 , V_65 , V_56 ) ;
V_57 -> V_42 = V_43 ;
if ( V_59 )
F_41 ( V_57 ) ;
F_4 ( V_57 ) ;
} else {
V_3 = F_2 ( V_55 , V_56 ) ;
if ( V_3 )
goto V_45;
if ( V_59 )
F_28 ( V_54 ) ;
}
V_56 -> V_42 = V_43 ;
F_34 ( V_53 , V_61 , V_60 ) ;
F_18 ( V_56 ) ;
if ( V_59 ) {
F_40 ( V_56 , V_59 , V_58 , V_54 ) ;
F_4 ( V_53 ) ;
}
return 0 ;
V_45:
if ( V_59 ) {
F_42 ( V_58 ) ;
F_43 ( V_58 ) ;
}
V_64:
F_42 ( V_60 ) ;
F_43 ( V_60 ) ;
V_31:
return V_3 ;
}

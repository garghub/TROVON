static inline int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
int V_3 = F_2 ( V_1 , V_2 ) ;
if ( ! V_3 ) {
F_3 ( V_2 ) ;
F_4 ( V_1 , V_2 ) ;
return 0 ;
}
F_5 ( V_2 ) ;
F_3 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_3 ;
}
static struct V_1 * F_7 ( struct V_2 * V_4 , struct V_1 * V_1 , unsigned int V_5 )
{
struct V_2 * V_2 = NULL ;
T_1 V_6 ;
if ( V_1 -> V_7 . V_8 > V_9 )
return F_8 ( - V_10 ) ;
F_9 ( V_4 -> V_11 ) ;
V_6 = F_10 ( V_4 , & V_1 -> V_7 ) ;
if ( V_6 )
V_2 = F_11 ( V_4 -> V_11 , V_6 ) ;
F_12 ( V_4 -> V_11 ) ;
return F_13 ( V_2 , V_1 ) ;
}
static int F_14 ( struct V_2 * V_4 , struct V_1 * V_1 , T_2 V_12 ,
bool V_13 )
{
struct V_2 * V_2 ;
int V_3 ;
F_15 ( L_1 ) ;
V_2 = F_16 ( V_4 , V_12 ) ;
V_3 = F_17 ( V_2 ) ;
if ( ! F_18 ( V_2 ) ) {
V_2 -> V_14 = & V_15 ;
V_2 -> V_16 = & V_17 ;
V_2 -> V_18 -> V_19 = & V_20 ;
F_19 ( V_2 ) ;
F_9 ( V_4 -> V_11 ) ;
V_3 = F_1 ( V_1 , V_2 ) ;
F_12 ( V_4 -> V_11 ) ;
}
F_15 ( L_2 , V_3 ) ;
return V_3 ;
}
static int F_20 ( struct V_2 * V_4 , struct V_1 * V_1 , T_2 V_12 , T_3 V_21 )
{
struct V_2 * V_2 ;
int V_3 ;
if ( ! F_21 ( V_21 ) )
return - V_22 ;
V_2 = F_16 ( V_4 , V_12 ) ;
V_3 = F_17 ( V_2 ) ;
if ( ! F_18 ( V_2 ) ) {
F_22 ( V_2 , V_12 , V_21 ) ;
F_23 ( V_2 -> V_11 , F_24 ( V_2 ) , V_21 ) ;
F_19 ( V_2 ) ;
F_9 ( V_4 -> V_11 ) ;
V_3 = F_1 ( V_1 , V_2 ) ;
F_12 ( V_4 -> V_11 ) ;
}
return V_3 ;
}
static int F_25 ( struct V_2 * V_4 , struct V_1 * V_1 ,
const char * V_23 )
{
struct V_24 * V_25 = V_4 -> V_11 ;
int V_3 = - V_10 ;
unsigned V_26 = strlen ( V_23 ) + 1 ;
struct V_2 * V_2 ;
if ( V_26 > V_25 -> V_27 )
goto V_28;
V_2 = F_16 ( V_4 , V_29 | V_30 ) ;
V_3 = F_17 ( V_2 ) ;
if ( F_18 ( V_2 ) )
goto V_28;
F_9 ( V_4 -> V_11 ) ;
if ( V_26 > F_26 ( V_25 ) -> V_31 -> V_32 ) {
V_2 -> V_14 = & V_33 ;
V_2 -> V_18 -> V_19 = & V_20 ;
V_3 = F_27 ( V_2 , V_23 , V_26 ) ;
if ( V_3 )
goto V_34;
} else {
V_2 -> V_14 = & V_35 ;
memcpy ( F_24 ( V_2 ) -> V_36 . V_37 , V_23 , V_26 ) ;
V_2 -> V_38 = V_26 - 1 ;
}
F_19 ( V_2 ) ;
V_3 = F_1 ( V_1 , V_2 ) ;
V_39:
F_12 ( V_4 -> V_11 ) ;
V_28:
return V_3 ;
V_34:
F_5 ( V_2 ) ;
F_3 ( V_2 ) ;
F_6 ( V_2 ) ;
goto V_39;
}
static int F_28 ( struct V_1 * V_40 , struct V_2 * V_4 ,
struct V_1 * V_1 )
{
struct V_2 * V_2 = F_29 ( V_40 ) ;
int error ;
F_9 ( V_4 -> V_11 ) ;
V_2 -> V_41 = V_42 ;
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
error = F_1 ( V_1 , V_2 ) ;
F_12 ( V_4 -> V_11 ) ;
return error ;
}
static int F_32 ( struct V_2 * V_4 , struct V_1 * V_1 , T_2 V_12 )
{
struct V_2 * V_2 ;
int V_3 ;
V_2 = F_16 ( V_4 , V_43 | V_12 ) ;
if ( F_18 ( V_2 ) )
return F_17 ( V_2 ) ;
V_2 -> V_14 = & V_44 ;
V_2 -> V_16 = & V_45 ;
V_2 -> V_18 -> V_19 = & V_20 ;
F_30 ( V_2 ) ;
F_9 ( V_4 -> V_11 ) ;
F_30 ( V_4 ) ;
V_3 = F_33 ( V_2 , V_4 ) ;
if ( V_3 )
goto V_34;
V_3 = F_2 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_34;
F_12 ( V_4 -> V_11 ) ;
F_4 ( V_1 , V_2 ) ;
V_39:
return V_3 ;
V_34:
F_5 ( V_2 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 ) ;
F_6 ( V_2 ) ;
F_5 ( V_4 ) ;
F_12 ( V_4 -> V_11 ) ;
goto V_39;
}
static int F_34 ( struct V_2 * V_4 , struct V_1 * V_1 )
{
struct V_2 * V_2 = F_29 ( V_1 ) ;
struct V_46 * V_47 ;
struct V_48 * V_48 ;
int V_3 = - V_49 ;
V_47 = F_35 ( V_4 , & V_1 -> V_7 , & V_48 ) ;
if ( ! V_47 )
goto V_39;
V_3 = F_36 ( V_4 , V_47 , V_48 ) ;
if ( V_3 )
goto V_39;
V_2 -> V_41 = V_4 -> V_41 ;
F_5 ( V_2 ) ;
V_3 = 0 ;
V_39:
return V_3 ;
}
static int F_37 ( struct V_2 * V_4 , struct V_1 * V_1 )
{
struct V_2 * V_2 = F_29 ( V_1 ) ;
int V_3 = - V_50 ;
F_9 ( V_4 -> V_11 ) ;
if ( F_38 ( V_2 ) ) {
V_3 = F_34 ( V_4 , V_1 ) ;
if ( ! V_3 ) {
V_2 -> V_38 = 0 ;
F_5 ( V_2 ) ;
F_5 ( V_4 ) ;
}
}
F_12 ( V_4 -> V_11 ) ;
return V_3 ;
}
static int F_39 ( struct V_2 * V_51 , struct V_1 * V_40 ,
struct V_2 * V_52 , struct V_1 * V_53 )
{
struct V_2 * V_54 = F_29 ( V_40 ) ;
struct V_2 * V_55 = F_29 ( V_53 ) ;
struct V_48 * V_56 = NULL ;
struct V_46 * V_57 = NULL ;
struct V_48 * V_58 ;
struct V_46 * V_59 ;
int V_3 = - V_49 ;
V_59 = F_35 ( V_51 , & V_40 -> V_7 , & V_58 ) ;
if ( ! V_59 )
goto V_39;
if ( F_40 ( V_54 -> V_60 ) ) {
V_3 = - V_61 ;
V_57 = F_41 ( V_54 , & V_56 ) ;
if ( ! V_57 )
goto V_62;
}
if ( V_55 ) {
struct V_48 * V_63 ;
struct V_46 * V_64 ;
V_3 = - V_50 ;
if ( V_57 && ! F_38 ( V_55 ) )
goto V_65;
V_3 = - V_49 ;
V_64 = F_35 ( V_52 , & V_53 -> V_7 , & V_63 ) ;
if ( ! V_64 )
goto V_65;
F_42 ( V_52 , V_64 , V_63 , V_54 ) ;
V_55 -> V_41 = V_42 ;
if ( V_57 )
F_43 ( V_55 ) ;
F_5 ( V_55 ) ;
} else {
V_3 = F_2 ( V_53 , V_54 ) ;
if ( V_3 )
goto V_65;
if ( V_57 )
F_30 ( V_52 ) ;
}
V_54 -> V_41 = V_42 ;
F_36 ( V_51 , V_59 , V_58 ) ;
F_19 ( V_54 ) ;
if ( V_57 ) {
F_42 ( V_54 , V_57 , V_56 , V_52 ) ;
F_5 ( V_51 ) ;
}
return 0 ;
V_65:
if ( V_57 ) {
F_44 ( V_56 ) ;
F_45 ( V_56 ) ;
}
V_62:
F_44 ( V_58 ) ;
F_45 ( V_58 ) ;
V_39:
return V_3 ;
}

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
V_6 = F_9 ( V_4 , & V_1 -> V_7 ) ;
if ( V_6 )
V_2 = F_10 ( V_4 -> V_11 , V_6 ) ;
return F_11 ( V_2 , V_1 ) ;
}
static int F_12 ( struct V_2 * V_4 , struct V_1 * V_1 , T_2 V_12 ,
bool V_13 )
{
struct V_2 * V_2 ;
V_2 = F_13 ( V_4 , V_12 ) ;
if ( F_14 ( V_2 ) )
return F_15 ( V_2 ) ;
V_2 -> V_14 = & V_15 ;
V_2 -> V_16 = & V_17 ;
V_2 -> V_18 -> V_19 = & V_20 ;
F_16 ( V_2 ) ;
return F_1 ( V_1 , V_2 ) ;
}
static int F_17 ( struct V_2 * V_4 , struct V_1 * V_1 , T_2 V_12 , T_3 V_21 )
{
struct V_2 * V_2 ;
int V_3 ;
if ( ! F_18 ( V_21 ) )
return - V_22 ;
V_2 = F_13 ( V_4 , V_12 ) ;
V_3 = F_15 ( V_2 ) ;
if ( ! F_14 ( V_2 ) ) {
F_19 ( V_2 , V_12 , V_21 ) ;
F_20 ( V_2 -> V_11 , F_21 ( V_2 ) , V_21 ) ;
F_16 ( V_2 ) ;
V_3 = F_1 ( V_1 , V_2 ) ;
}
return V_3 ;
}
static int F_22 ( struct V_2 * V_4 , struct V_1 * V_1 ,
const char * V_23 )
{
struct V_24 * V_25 = V_4 -> V_11 ;
int V_3 ;
unsigned V_26 = strlen ( V_23 ) + 1 ;
struct V_2 * V_2 ;
if ( V_26 > V_25 -> V_27 )
return - V_10 ;
V_2 = F_13 ( V_4 , V_28 | V_29 ) ;
V_3 = F_15 ( V_2 ) ;
if ( F_14 ( V_2 ) )
return V_3 ;
if ( V_26 > F_23 ( V_25 ) -> V_30 -> V_31 ) {
V_2 -> V_14 = & V_32 ;
V_2 -> V_18 -> V_19 = & V_20 ;
V_3 = F_24 ( V_2 , V_23 , V_26 ) ;
if ( V_3 )
goto V_33;
} else {
V_2 -> V_14 = & V_34 ;
V_2 -> V_35 = ( char * ) F_21 ( V_2 ) -> V_36 . V_37 ;
memcpy ( V_2 -> V_35 , V_23 , V_26 ) ;
V_2 -> V_38 = V_26 - 1 ;
}
F_16 ( V_2 ) ;
return F_1 ( V_1 , V_2 ) ;
V_33:
F_5 ( V_2 ) ;
F_3 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_3 ;
}
static int F_25 ( struct V_1 * V_39 , struct V_2 * V_4 ,
struct V_1 * V_1 )
{
struct V_2 * V_2 = F_26 ( V_39 ) ;
int error ;
V_2 -> V_40 = V_41 ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
error = F_2 ( V_1 , V_2 ) ;
if ( error ) {
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
} else
F_4 ( V_1 , V_2 ) ;
return error ;
}
static int F_29 ( struct V_2 * V_4 , struct V_1 * V_1 , T_2 V_12 )
{
struct V_2 * V_2 ;
int V_3 ;
F_27 ( V_4 ) ;
V_2 = F_13 ( V_4 , V_42 | V_12 ) ;
V_3 = F_15 ( V_2 ) ;
if ( F_14 ( V_2 ) )
goto V_43;
V_2 -> V_14 = & V_44 ;
V_2 -> V_16 = & V_45 ;
V_2 -> V_18 -> V_19 = & V_20 ;
F_27 ( V_2 ) ;
V_3 = F_30 ( V_2 , V_4 ) ;
if ( V_3 )
goto V_33;
V_3 = F_2 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_33;
F_3 ( V_2 ) ;
F_4 ( V_1 , V_2 ) ;
return 0 ;
V_33:
F_5 ( V_2 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 ) ;
F_6 ( V_2 ) ;
V_43:
F_5 ( V_4 ) ;
return V_3 ;
}
static int F_31 ( struct V_2 * V_4 , struct V_1 * V_1 )
{
struct V_2 * V_2 = F_26 ( V_1 ) ;
struct V_46 * V_47 ;
struct V_48 * V_48 ;
int V_3 = - V_49 ;
V_47 = F_32 ( V_4 , & V_1 -> V_7 , & V_48 ) ;
if ( ! V_47 )
goto V_50;
V_3 = F_33 ( V_4 , V_47 , V_48 ) ;
if ( V_3 )
goto V_50;
V_2 -> V_40 = V_4 -> V_40 ;
F_5 ( V_2 ) ;
V_3 = 0 ;
V_50:
return V_3 ;
}
static int F_34 ( struct V_2 * V_4 , struct V_1 * V_1 )
{
struct V_2 * V_2 = F_26 ( V_1 ) ;
int V_3 = - V_51 ;
if ( F_35 ( V_2 ) ) {
V_3 = F_31 ( V_4 , V_1 ) ;
if ( ! V_3 ) {
V_2 -> V_38 = 0 ;
F_5 ( V_2 ) ;
F_5 ( V_4 ) ;
}
}
return V_3 ;
}
static int F_36 ( struct V_2 * V_52 , struct V_1 * V_39 ,
struct V_2 * V_53 , struct V_1 * V_54 )
{
struct V_2 * V_55 = F_26 ( V_39 ) ;
struct V_2 * V_56 = F_26 ( V_54 ) ;
struct V_48 * V_57 = NULL ;
struct V_46 * V_58 = NULL ;
struct V_48 * V_59 ;
struct V_46 * V_60 ;
int V_3 = - V_49 ;
V_60 = F_32 ( V_52 , & V_39 -> V_7 , & V_59 ) ;
if ( ! V_60 )
goto V_50;
if ( F_37 ( V_55 -> V_61 ) ) {
V_3 = - V_62 ;
V_58 = F_38 ( V_55 , & V_57 ) ;
if ( ! V_58 )
goto V_63;
}
if ( V_56 ) {
struct V_48 * V_64 ;
struct V_46 * V_65 ;
V_3 = - V_51 ;
if ( V_58 && ! F_35 ( V_56 ) )
goto V_43;
V_3 = - V_49 ;
V_65 = F_32 ( V_53 , & V_54 -> V_7 , & V_64 ) ;
if ( ! V_65 )
goto V_43;
F_39 ( V_53 , V_65 , V_64 , V_55 , 1 ) ;
V_56 -> V_40 = V_41 ;
if ( V_58 )
F_40 ( V_56 ) ;
F_5 ( V_56 ) ;
} else {
V_3 = F_2 ( V_54 , V_55 ) ;
if ( V_3 )
goto V_43;
if ( V_58 )
F_27 ( V_53 ) ;
}
V_55 -> V_40 = V_41 ;
F_33 ( V_52 , V_60 , V_59 ) ;
F_16 ( V_55 ) ;
if ( V_58 ) {
if ( V_52 != V_53 )
F_39 ( V_55 , V_58 , V_57 , V_53 , 0 ) ;
else {
F_41 ( V_57 ) ;
F_42 ( V_57 ) ;
}
F_5 ( V_52 ) ;
}
return 0 ;
V_43:
if ( V_58 ) {
F_41 ( V_57 ) ;
F_42 ( V_57 ) ;
}
V_63:
F_41 ( V_59 ) ;
F_42 ( V_59 ) ;
V_50:
return V_3 ;
}

int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
if ( V_4 -> V_6 == 0 )
return 0 ;
if ( V_4 -> V_7 ) {
int V_8 ;
V_8 = F_2 ( & V_2 -> V_9 , V_4 -> V_10 , V_4 -> V_7 ,
V_5 ? V_11 : V_12 ) ;
if ( V_8 == 0 ) {
F_3 ( & V_2 -> V_9 , L_1 ) ;
return - V_13 ;
}
V_4 -> V_14 = V_8 ;
} else {
V_4 -> V_15 = F_4 ( & V_2 -> V_9 , V_4 -> V_16 , V_4 -> V_6 ,
V_5 ? V_11 : V_12 ) ;
if ( F_5 ( & V_2 -> V_9 , V_4 -> V_15 ) ) {
F_3 ( & V_2 -> V_9 , L_2 ) ;
return - V_13 ;
}
}
return 0 ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
if ( V_4 -> V_6 == 0 )
return;
if ( V_4 -> V_14 ) {
F_7 ( & V_2 -> V_9 , V_4 -> V_10 , V_4 -> V_14 ,
V_5 ? V_11 : V_12 ) ;
V_4 -> V_14 = 0 ;
} else {
F_8 ( & V_2 -> V_9 , V_4 -> V_15 , V_4 -> V_6 ,
V_5 ? V_11 : V_12 ) ;
}
}
static inline int F_9 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
int (* F_10)( struct V_1 * , struct V_17 * ) )
{
return V_2 -> V_19 -> V_20 ( V_18 , F_10 ) ;
}
static inline int F_11 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
return V_2 -> V_19 -> V_21 ( V_2 , V_18 ) ;
}
static inline void F_12 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
V_2 -> V_19 -> V_22 ( V_18 ) ;
}
static inline void F_13 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
V_2 -> V_19 -> V_23 ( V_2 , V_18 ) ;
}
static void F_14 ( struct V_24 * V_9 )
{
struct V_25 * V_26 ;
V_26 = F_15 ( V_9 , struct V_25 , V_9 ) ;
F_16 ( V_9 , L_3 , F_17 ( V_9 ) ) ;
F_18 ( V_26 ) ;
}
int F_19 ( struct V_24 * V_27 , struct V_1 * V_2 )
{
struct V_25 * V_26 ;
int V_28 = - V_29 ;
V_26 = F_20 ( sizeof( * V_26 ) , V_30 ) ;
if ( ! V_26 )
goto V_31;
F_21 ( & V_26 -> V_9 ) ;
V_26 -> V_9 . V_32 = F_14 ;
V_26 -> V_9 . V_33 = V_34 ;
V_26 -> V_9 . V_35 = V_36 ;
V_26 -> V_9 . V_27 = V_27 ;
V_28 = F_22 ( & V_26 -> V_9 , L_4 , F_23 ( & V_27 -> V_37 ) ) ;
if ( V_28 )
goto V_38;
V_26 -> V_2 = V_2 ;
F_24 ( & V_39 ) ;
F_25 ( & V_26 -> V_40 , & V_41 ) ;
V_28 = F_26 ( & V_26 -> V_9 ) ;
if ( V_28 )
goto V_42;
F_27 ( & V_39 ) ;
return 0 ;
V_42:
F_28 ( & V_26 -> V_40 ) ;
F_27 ( & V_39 ) ;
V_38:
F_29 ( & V_26 -> V_9 ) ;
V_31:
return V_28 ;
}
static int F_30 ( struct V_25 * V_26 )
{
if ( V_26 -> V_2 -> V_19 -> V_21 && V_26 -> V_2 -> V_19 -> V_23 )
return 1 ;
return 0 ;
}
static void F_31 ( struct V_25 * V_26 )
{
F_16 ( & V_26 -> V_9 , L_5 ,
V_26 -> V_2 -> V_43 ) ;
F_32 ( & V_26 -> V_9 . V_37 , V_44 ) ;
if ( F_30 ( V_26 ) ) {
F_33 ( V_26 -> V_2 ) ;
V_26 -> V_18 -> V_45 ( V_26 -> V_2 ) ;
V_26 -> V_18 -> V_46 ( V_26 -> V_2 ) ;
F_13 ( V_26 -> V_2 , V_26 -> V_18 ) ;
} else {
F_12 ( V_26 -> V_2 , V_26 -> V_18 ) ;
}
V_26 -> V_18 = NULL ;
V_26 -> V_9 . V_18 = NULL ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = NULL ;
F_24 ( & V_39 ) ;
F_35 (udc, &udc_list, list)
if ( V_26 -> V_2 == V_2 )
goto V_47;
F_3 ( V_2 -> V_9 . V_27 , L_6 ) ;
F_27 ( & V_39 ) ;
return;
V_47:
F_36 ( V_2 -> V_9 . V_27 , L_7 ) ;
F_28 ( & V_26 -> V_40 ) ;
F_27 ( & V_39 ) ;
if ( V_26 -> V_18 )
F_31 ( V_26 ) ;
F_32 ( & V_26 -> V_9 . V_37 , V_48 ) ;
F_37 ( & V_26 -> V_9 ) ;
}
int F_38 ( struct V_17 * V_18 )
{
struct V_25 * V_26 = NULL ;
int V_28 ;
if ( ! V_18 || ! V_18 -> F_10 || ! V_18 -> V_49 )
return - V_50 ;
F_24 ( & V_39 ) ;
F_35 (udc, &udc_list, list) {
if ( ! V_26 -> V_18 )
goto V_47;
}
F_39 ( L_8 ) ;
F_27 ( & V_39 ) ;
return - V_51 ;
V_47:
F_16 ( & V_26 -> V_9 , L_9 ,
V_18 -> V_52 ) ;
V_26 -> V_18 = V_18 ;
V_26 -> V_9 . V_18 = & V_18 -> V_18 ;
if ( F_30 ( V_26 ) ) {
V_28 = V_18 -> F_10 ( V_26 -> V_2 , V_18 ) ;
if ( V_28 )
goto V_31;
V_28 = F_11 ( V_26 -> V_2 , V_18 ) ;
if ( V_28 ) {
V_18 -> V_46 ( V_26 -> V_2 ) ;
goto V_31;
}
F_40 ( V_26 -> V_2 ) ;
} else {
V_28 = F_9 ( V_26 -> V_2 , V_18 , V_18 -> F_10 ) ;
if ( V_28 )
goto V_31;
}
F_32 ( & V_26 -> V_9 . V_37 , V_44 ) ;
F_27 ( & V_39 ) ;
return 0 ;
V_31:
F_3 ( & V_26 -> V_9 , L_10 ,
V_26 -> V_18 -> V_52 , V_28 ) ;
V_26 -> V_18 = NULL ;
V_26 -> V_9 . V_18 = NULL ;
F_27 ( & V_39 ) ;
return V_28 ;
}
int F_41 ( struct V_17 * V_18 )
{
struct V_25 * V_26 = NULL ;
int V_28 = - V_51 ;
if ( ! V_18 || ! V_18 -> V_46 )
return - V_50 ;
F_24 ( & V_39 ) ;
F_35 (udc, &udc_list, list)
if ( V_26 -> V_18 == V_18 ) {
F_31 ( V_26 ) ;
V_28 = 0 ;
break;
}
F_27 ( & V_39 ) ;
return V_28 ;
}
static T_1 F_42 ( struct V_24 * V_9 ,
struct V_53 * V_54 , const char * V_16 , T_2 V_55 )
{
struct V_25 * V_26 = F_15 ( V_9 , struct V_25 , V_9 ) ;
if ( F_43 ( V_16 , L_11 ) )
F_44 ( V_26 -> V_2 ) ;
return V_55 ;
}
static T_1 F_45 ( struct V_24 * V_9 ,
struct V_53 * V_54 , const char * V_16 , T_2 V_55 )
{
struct V_25 * V_26 = F_15 ( V_9 , struct V_25 , V_9 ) ;
if ( F_43 ( V_16 , L_12 ) ) {
if ( F_30 ( V_26 ) )
F_11 ( V_26 -> V_2 , V_26 -> V_18 ) ;
F_40 ( V_26 -> V_2 ) ;
} else if ( F_43 ( V_16 , L_13 ) ) {
F_33 ( V_26 -> V_2 ) ;
if ( F_30 ( V_26 ) )
F_13 ( V_26 -> V_2 , V_26 -> V_18 ) ;
} else {
F_3 ( V_9 , L_14 , V_16 ) ;
return - V_50 ;
}
return V_55 ;
}
static int F_46 ( struct V_24 * V_9 , struct V_56 * V_57 )
{
struct V_25 * V_26 = F_15 ( V_9 , struct V_25 , V_9 ) ;
int V_28 ;
V_28 = F_47 ( V_57 , L_15 , V_26 -> V_2 -> V_43 ) ;
if ( V_28 ) {
F_3 ( V_9 , L_16 ) ;
return V_28 ;
}
if ( V_26 -> V_18 ) {
V_28 = F_47 ( V_57 , L_17 ,
V_26 -> V_18 -> V_52 ) ;
if ( V_28 ) {
F_3 ( V_9 , L_18 ) ;
return V_28 ;
}
}
return 0 ;
}
static int T_3 F_48 ( void )
{
V_34 = F_49 ( V_58 , L_19 ) ;
if ( F_50 ( V_34 ) ) {
F_51 ( L_20 ,
F_52 ( V_34 ) ) ;
return F_52 ( V_34 ) ;
}
V_34 -> V_59 = F_46 ;
return 0 ;
}
static void T_4 F_53 ( void )
{
F_54 ( V_34 ) ;
}

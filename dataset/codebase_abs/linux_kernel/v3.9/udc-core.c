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
struct V_17 * V_18 )
{
return V_2 -> V_19 -> V_20 ( V_2 , V_18 ) ;
}
static inline void F_10 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
V_2 -> V_19 -> V_21 ( V_2 , V_18 ) ;
}
static void F_11 ( struct V_22 * V_9 )
{
struct V_23 * V_24 ;
V_24 = F_12 ( V_9 , struct V_23 , V_9 ) ;
F_13 ( V_9 , L_3 , F_14 ( V_9 ) ) ;
F_15 ( V_24 ) ;
}
int F_16 ( struct V_22 * V_25 , struct V_1 * V_2 )
{
struct V_23 * V_24 ;
int V_26 = - V_27 ;
V_24 = F_17 ( sizeof( * V_24 ) , V_28 ) ;
if ( ! V_24 )
goto V_29;
F_18 ( & V_24 -> V_9 ) ;
V_24 -> V_9 . V_30 = F_11 ;
V_24 -> V_9 . V_31 = V_32 ;
V_24 -> V_9 . V_33 = V_34 ;
V_24 -> V_9 . V_25 = V_25 ;
V_26 = F_19 ( & V_24 -> V_9 , L_4 , F_20 ( & V_25 -> V_35 ) ) ;
if ( V_26 )
goto V_36;
V_24 -> V_2 = V_2 ;
F_21 ( & V_37 ) ;
F_22 ( & V_24 -> V_38 , & V_39 ) ;
V_26 = F_23 ( & V_24 -> V_9 ) ;
if ( V_26 )
goto V_40;
F_24 ( & V_37 ) ;
return 0 ;
V_40:
F_25 ( & V_24 -> V_38 ) ;
F_24 ( & V_37 ) ;
V_36:
F_26 ( & V_24 -> V_9 ) ;
V_29:
return V_26 ;
}
static void F_27 ( struct V_23 * V_24 )
{
F_13 ( & V_24 -> V_9 , L_5 ,
V_24 -> V_2 -> V_41 ) ;
F_28 ( & V_24 -> V_9 . V_35 , V_42 ) ;
F_29 ( V_24 -> V_2 ) ;
V_24 -> V_18 -> V_43 ( V_24 -> V_2 ) ;
V_24 -> V_18 -> V_44 ( V_24 -> V_2 ) ;
F_10 ( V_24 -> V_2 , NULL ) ;
V_24 -> V_18 = NULL ;
V_24 -> V_9 . V_18 = NULL ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = NULL ;
F_21 ( & V_37 ) ;
F_31 (udc, &udc_list, list)
if ( V_24 -> V_2 == V_2 )
goto V_45;
F_3 ( V_2 -> V_9 . V_25 , L_6 ) ;
F_24 ( & V_37 ) ;
return;
V_45:
F_32 ( V_2 -> V_9 . V_25 , L_7 ) ;
F_25 ( & V_24 -> V_38 ) ;
F_24 ( & V_37 ) ;
if ( V_24 -> V_18 )
F_27 ( V_24 ) ;
F_28 ( & V_24 -> V_9 . V_35 , V_46 ) ;
F_33 ( & V_24 -> V_9 ) ;
}
static int F_34 ( struct V_23 * V_24 , struct V_17 * V_18 )
{
int V_26 ;
F_13 ( & V_24 -> V_9 , L_8 ,
V_18 -> V_47 ) ;
V_24 -> V_18 = V_18 ;
V_24 -> V_9 . V_18 = & V_18 -> V_18 ;
V_26 = V_18 -> V_48 ( V_24 -> V_2 , V_18 ) ;
if ( V_26 )
goto V_29;
V_26 = F_9 ( V_24 -> V_2 , V_18 ) ;
if ( V_26 ) {
V_18 -> V_44 ( V_24 -> V_2 ) ;
goto V_29;
}
F_35 ( V_24 -> V_2 ) ;
F_28 ( & V_24 -> V_9 . V_35 , V_42 ) ;
return 0 ;
V_29:
F_3 ( & V_24 -> V_9 , L_9 ,
V_24 -> V_18 -> V_47 , V_26 ) ;
V_24 -> V_18 = NULL ;
V_24 -> V_9 . V_18 = NULL ;
return V_26 ;
}
int F_36 ( const char * V_41 , struct V_17 * V_18 )
{
struct V_23 * V_24 = NULL ;
int V_26 = - V_49 ;
F_21 ( & V_37 ) ;
F_31 (udc, &udc_list, list) {
V_26 = strcmp ( V_41 , F_14 ( & V_24 -> V_9 ) ) ;
if ( ! V_26 )
break;
}
if ( V_26 ) {
V_26 = - V_49 ;
goto V_50;
}
if ( V_24 -> V_18 ) {
V_26 = - V_51 ;
goto V_50;
}
V_26 = F_34 ( V_24 , V_18 ) ;
V_50:
F_24 ( & V_37 ) ;
return V_26 ;
}
int F_37 ( struct V_17 * V_18 )
{
struct V_23 * V_24 = NULL ;
int V_26 ;
if ( ! V_18 || ! V_18 -> V_48 || ! V_18 -> V_52 )
return - V_53 ;
F_21 ( & V_37 ) ;
F_31 (udc, &udc_list, list) {
if ( ! V_24 -> V_18 )
goto V_45;
}
F_38 ( L_10 ) ;
F_24 ( & V_37 ) ;
return - V_49 ;
V_45:
V_26 = F_34 ( V_24 , V_18 ) ;
F_24 ( & V_37 ) ;
return V_26 ;
}
int F_39 ( struct V_17 * V_18 )
{
struct V_23 * V_24 = NULL ;
int V_26 = - V_49 ;
if ( ! V_18 || ! V_18 -> V_44 )
return - V_53 ;
F_21 ( & V_37 ) ;
F_31 (udc, &udc_list, list)
if ( V_24 -> V_18 == V_18 ) {
F_27 ( V_24 ) ;
V_26 = 0 ;
break;
}
F_24 ( & V_37 ) ;
return V_26 ;
}
static T_1 F_40 ( struct V_22 * V_9 ,
struct V_54 * V_55 , const char * V_16 , T_2 V_56 )
{
struct V_23 * V_24 = F_12 ( V_9 , struct V_23 , V_9 ) ;
if ( F_41 ( V_16 , L_11 ) )
F_42 ( V_24 -> V_2 ) ;
return V_56 ;
}
static T_1 F_43 ( struct V_22 * V_9 ,
struct V_54 * V_55 , const char * V_16 , T_2 V_56 )
{
struct V_23 * V_24 = F_12 ( V_9 , struct V_23 , V_9 ) ;
if ( F_41 ( V_16 , L_12 ) ) {
F_9 ( V_24 -> V_2 , V_24 -> V_18 ) ;
F_35 ( V_24 -> V_2 ) ;
} else if ( F_41 ( V_16 , L_13 ) ) {
F_29 ( V_24 -> V_2 ) ;
F_10 ( V_24 -> V_2 , V_24 -> V_18 ) ;
} else {
F_3 ( V_9 , L_14 , V_16 ) ;
return - V_53 ;
}
return V_56 ;
}
static int F_44 ( struct V_22 * V_9 , struct V_57 * V_58 )
{
struct V_23 * V_24 = F_12 ( V_9 , struct V_23 , V_9 ) ;
int V_26 ;
V_26 = F_45 ( V_58 , L_15 , V_24 -> V_2 -> V_41 ) ;
if ( V_26 ) {
F_3 ( V_9 , L_16 ) ;
return V_26 ;
}
if ( V_24 -> V_18 ) {
V_26 = F_45 ( V_58 , L_17 ,
V_24 -> V_18 -> V_47 ) ;
if ( V_26 ) {
F_3 ( V_9 , L_18 ) ;
return V_26 ;
}
}
return 0 ;
}
static int T_3 F_46 ( void )
{
V_32 = F_47 ( V_59 , L_19 ) ;
if ( F_48 ( V_32 ) ) {
F_49 ( L_20 ,
F_50 ( V_32 ) ) ;
return F_50 ( V_32 ) ;
}
V_32 -> V_60 = F_44 ;
return 0 ;
}
static void T_4 F_51 ( void )
{
F_52 ( V_32 ) ;
}

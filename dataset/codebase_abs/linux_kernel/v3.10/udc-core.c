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
void F_9 ( struct V_1 * V_2 ,
enum V_17 V_18 )
{
V_2 -> V_18 = V_18 ;
F_10 ( & V_2 -> V_9 . V_19 , NULL , L_3 ) ;
}
static inline int F_11 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
return V_2 -> V_22 -> V_23 ( V_2 , V_21 ) ;
}
static inline void F_12 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
V_2 -> V_22 -> V_24 ( V_2 , V_21 ) ;
}
static void F_13 ( struct V_25 * V_9 )
{
struct V_26 * V_27 ;
V_27 = F_14 ( V_9 , struct V_26 , V_9 ) ;
F_15 ( V_9 , L_4 , F_16 ( V_9 ) ) ;
F_17 ( V_27 ) ;
}
static void F_18 ( struct V_25 * V_9 )
{
F_19 ( V_9 , L_5 , V_28 ) ;
}
int F_20 ( struct V_25 * V_29 , struct V_1 * V_2 ,
void (* F_21)( struct V_25 * V_9 ) )
{
struct V_26 * V_27 ;
int V_30 = - V_31 ;
V_27 = F_22 ( sizeof( * V_27 ) , V_32 ) ;
if ( ! V_27 )
goto V_33;
F_23 ( & V_2 -> V_9 , L_6 ) ;
V_2 -> V_9 . V_29 = V_29 ;
F_24 ( & V_2 -> V_9 , V_29 -> V_34 ) ;
V_2 -> V_9 . V_35 = V_29 -> V_35 ;
V_2 -> V_9 . V_36 = V_29 -> V_36 ;
if ( F_21 )
V_2 -> V_9 . F_21 = F_21 ;
else
V_2 -> V_9 . F_21 = F_18 ;
V_30 = F_25 ( & V_2 -> V_9 ) ;
if ( V_30 )
goto V_37;
F_26 ( & V_27 -> V_9 ) ;
V_27 -> V_9 . F_21 = F_13 ;
V_27 -> V_9 . V_38 = V_39 ;
V_27 -> V_9 . V_40 = V_41 ;
V_27 -> V_9 . V_29 = V_29 ;
V_30 = F_23 ( & V_27 -> V_9 , L_7 , F_27 ( & V_29 -> V_19 ) ) ;
if ( V_30 )
goto V_42;
V_27 -> V_2 = V_2 ;
F_28 ( & V_43 ) ;
F_29 ( & V_27 -> V_44 , & V_45 ) ;
V_30 = F_30 ( & V_27 -> V_9 ) ;
if ( V_30 )
goto V_46;
F_9 ( V_2 , V_47 ) ;
F_31 ( & V_43 ) ;
return 0 ;
V_46:
F_32 ( & V_27 -> V_44 ) ;
F_31 ( & V_43 ) ;
V_42:
F_33 ( & V_27 -> V_9 ) ;
V_37:
F_33 ( & V_2 -> V_9 ) ;
F_17 ( V_27 ) ;
V_33:
return V_30 ;
}
int F_34 ( struct V_25 * V_29 , struct V_1 * V_2 )
{
return F_20 ( V_29 , V_2 , NULL ) ;
}
static void F_35 ( struct V_26 * V_27 )
{
F_15 ( & V_27 -> V_9 , L_8 ,
V_27 -> V_2 -> V_48 ) ;
F_36 ( & V_27 -> V_9 . V_19 , V_49 ) ;
F_37 ( V_27 -> V_2 ) ;
V_27 -> V_21 -> V_50 ( V_27 -> V_2 ) ;
V_27 -> V_21 -> V_51 ( V_27 -> V_2 ) ;
F_12 ( V_27 -> V_2 , NULL ) ;
V_27 -> V_21 = NULL ;
V_27 -> V_9 . V_21 = NULL ;
V_27 -> V_2 -> V_9 . V_21 = NULL ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = NULL ;
F_28 ( & V_43 ) ;
F_39 (udc, &udc_list, list)
if ( V_27 -> V_2 == V_2 )
goto V_52;
F_3 ( V_2 -> V_9 . V_29 , L_9 ) ;
F_31 ( & V_43 ) ;
return;
V_52:
F_19 ( V_2 -> V_9 . V_29 , L_10 ) ;
F_32 ( & V_27 -> V_44 ) ;
F_31 ( & V_43 ) ;
if ( V_27 -> V_21 )
F_35 ( V_27 ) ;
F_36 ( & V_27 -> V_9 . V_19 , V_53 ) ;
F_40 ( & V_27 -> V_9 ) ;
F_40 ( & V_2 -> V_9 ) ;
}
static int F_41 ( struct V_26 * V_27 , struct V_20 * V_21 )
{
int V_30 ;
F_15 ( & V_27 -> V_9 , L_11 ,
V_21 -> V_54 ) ;
V_27 -> V_21 = V_21 ;
V_27 -> V_9 . V_21 = & V_21 -> V_21 ;
V_27 -> V_2 -> V_9 . V_21 = & V_21 -> V_21 ;
V_30 = V_21 -> V_55 ( V_27 -> V_2 , V_21 ) ;
if ( V_30 )
goto V_33;
V_30 = F_11 ( V_27 -> V_2 , V_21 ) ;
if ( V_30 ) {
V_21 -> V_51 ( V_27 -> V_2 ) ;
goto V_33;
}
F_42 ( V_27 -> V_2 ) ;
F_36 ( & V_27 -> V_9 . V_19 , V_49 ) ;
return 0 ;
V_33:
F_3 ( & V_27 -> V_9 , L_12 ,
V_27 -> V_21 -> V_54 , V_30 ) ;
V_27 -> V_21 = NULL ;
V_27 -> V_9 . V_21 = NULL ;
V_27 -> V_2 -> V_9 . V_21 = NULL ;
return V_30 ;
}
int F_43 ( const char * V_48 , struct V_20 * V_21 )
{
struct V_26 * V_27 = NULL ;
int V_30 = - V_56 ;
F_28 ( & V_43 ) ;
F_39 (udc, &udc_list, list) {
V_30 = strcmp ( V_48 , F_16 ( & V_27 -> V_9 ) ) ;
if ( ! V_30 )
break;
}
if ( V_30 ) {
V_30 = - V_56 ;
goto V_57;
}
if ( V_27 -> V_21 ) {
V_30 = - V_58 ;
goto V_57;
}
V_30 = F_41 ( V_27 , V_21 ) ;
V_57:
F_31 ( & V_43 ) ;
return V_30 ;
}
int F_44 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = NULL ;
int V_30 ;
if ( ! V_21 || ! V_21 -> V_55 || ! V_21 -> V_59 )
return - V_60 ;
F_28 ( & V_43 ) ;
F_39 (udc, &udc_list, list) {
if ( ! V_27 -> V_21 )
goto V_52;
}
F_45 ( L_13 ) ;
F_31 ( & V_43 ) ;
return - V_56 ;
V_52:
V_30 = F_41 ( V_27 , V_21 ) ;
F_31 ( & V_43 ) ;
return V_30 ;
}
int F_46 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = NULL ;
int V_30 = - V_56 ;
if ( ! V_21 || ! V_21 -> V_51 )
return - V_60 ;
F_28 ( & V_43 ) ;
F_39 (udc, &udc_list, list)
if ( V_27 -> V_21 == V_21 ) {
F_35 ( V_27 ) ;
V_30 = 0 ;
break;
}
F_31 ( & V_43 ) ;
return V_30 ;
}
static T_1 F_47 ( struct V_25 * V_9 ,
struct V_61 * V_62 , const char * V_16 , T_2 V_63 )
{
struct V_26 * V_27 = F_14 ( V_9 , struct V_26 , V_9 ) ;
if ( F_48 ( V_16 , L_14 ) )
F_49 ( V_27 -> V_2 ) ;
return V_63 ;
}
static T_1 F_50 ( struct V_25 * V_9 ,
struct V_61 * V_62 , const char * V_16 , T_2 V_63 )
{
struct V_26 * V_27 = F_14 ( V_9 , struct V_26 , V_9 ) ;
if ( F_48 ( V_16 , L_15 ) ) {
F_11 ( V_27 -> V_2 , V_27 -> V_21 ) ;
F_42 ( V_27 -> V_2 ) ;
} else if ( F_48 ( V_16 , L_16 ) ) {
F_37 ( V_27 -> V_2 ) ;
F_12 ( V_27 -> V_2 , V_27 -> V_21 ) ;
} else {
F_3 ( V_9 , L_17 , V_16 ) ;
return - V_60 ;
}
return V_63 ;
}
static T_1 F_51 ( struct V_25 * V_9 ,
struct V_61 * V_62 , char * V_16 )
{
struct V_26 * V_27 = F_14 ( V_9 , struct V_26 , V_9 ) ;
struct V_1 * V_2 = V_27 -> V_2 ;
return sprintf ( V_16 , L_5 , F_52 ( V_2 -> V_18 ) ) ;
}
static int F_53 ( struct V_25 * V_9 , struct V_64 * V_65 )
{
struct V_26 * V_27 = F_14 ( V_9 , struct V_26 , V_9 ) ;
int V_30 ;
V_30 = F_54 ( V_65 , L_18 , V_27 -> V_2 -> V_48 ) ;
if ( V_30 ) {
F_3 ( V_9 , L_19 ) ;
return V_30 ;
}
if ( V_27 -> V_21 ) {
V_30 = F_54 ( V_65 , L_20 ,
V_27 -> V_21 -> V_54 ) ;
if ( V_30 ) {
F_3 ( V_9 , L_21 ) ;
return V_30 ;
}
}
return 0 ;
}
static int T_3 F_55 ( void )
{
V_39 = F_56 ( V_66 , L_22 ) ;
if ( F_57 ( V_39 ) ) {
F_58 ( L_23 ,
F_59 ( V_39 ) ) ;
return F_59 ( V_39 ) ;
}
V_39 -> V_67 = F_53 ;
return 0 ;
}
static void T_4 F_60 ( void )
{
F_61 ( V_39 ) ;
}

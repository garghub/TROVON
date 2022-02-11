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
static void F_9 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_10 ( V_18 ) ;
F_11 ( & V_2 -> V_9 . V_19 , NULL , L_3 ) ;
}
void F_12 ( struct V_1 * V_2 ,
enum V_20 V_21 )
{
V_2 -> V_21 = V_21 ;
F_13 ( & V_2 -> V_18 ) ;
}
static inline int F_14 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
return V_2 -> V_24 -> V_25 ( V_2 , V_23 ) ;
}
static inline void F_15 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
V_2 -> V_24 -> V_26 ( V_2 , V_23 ) ;
}
static void F_16 ( struct V_27 * V_9 )
{
struct V_28 * V_29 ;
V_29 = F_17 ( V_9 , struct V_28 , V_9 ) ;
F_18 ( V_9 , L_4 , F_19 ( V_9 ) ) ;
F_20 ( V_29 ) ;
}
static void F_21 ( struct V_27 * V_9 )
{
F_22 ( V_9 , L_5 , V_30 ) ;
}
int F_23 ( struct V_27 * V_31 , struct V_1 * V_2 ,
void (* F_24)( struct V_27 * V_9 ) )
{
struct V_28 * V_29 ;
int V_32 = - V_33 ;
V_29 = F_25 ( sizeof( * V_29 ) , V_34 ) ;
if ( ! V_29 )
goto V_35;
F_26 ( & V_2 -> V_9 , L_6 ) ;
F_27 ( & V_2 -> V_18 , F_9 ) ;
V_2 -> V_9 . V_31 = V_31 ;
#ifdef F_28
F_29 ( & V_2 -> V_9 , V_31 -> V_36 ) ;
V_2 -> V_9 . V_37 = V_31 -> V_37 ;
V_2 -> V_9 . V_38 = V_31 -> V_38 ;
#endif
if ( F_24 )
V_2 -> V_9 . F_24 = F_24 ;
else
V_2 -> V_9 . F_24 = F_21 ;
V_32 = F_30 ( & V_2 -> V_9 ) ;
if ( V_32 )
goto V_39;
F_31 ( & V_29 -> V_9 ) ;
V_29 -> V_9 . F_24 = F_16 ;
V_29 -> V_9 . V_40 = V_41 ;
V_29 -> V_9 . V_42 = V_43 ;
V_29 -> V_9 . V_31 = V_31 ;
V_32 = F_26 ( & V_29 -> V_9 , L_7 , F_32 ( & V_31 -> V_19 ) ) ;
if ( V_32 )
goto V_44;
V_29 -> V_2 = V_2 ;
F_33 ( & V_45 ) ;
F_34 ( & V_29 -> V_46 , & V_47 ) ;
V_32 = F_35 ( & V_29 -> V_9 ) ;
if ( V_32 )
goto V_48;
F_12 ( V_2 , V_49 ) ;
F_36 ( & V_45 ) ;
return 0 ;
V_48:
F_37 ( & V_29 -> V_46 ) ;
F_36 ( & V_45 ) ;
V_44:
F_38 ( & V_29 -> V_9 ) ;
V_39:
F_38 ( & V_2 -> V_9 ) ;
F_20 ( V_29 ) ;
V_35:
return V_32 ;
}
int F_39 ( struct V_27 * V_31 , struct V_1 * V_2 )
{
return F_23 ( V_31 , V_2 , NULL ) ;
}
static void F_40 ( struct V_28 * V_29 )
{
F_18 ( & V_29 -> V_9 , L_8 ,
V_29 -> V_2 -> V_50 ) ;
F_41 ( & V_29 -> V_9 . V_19 , V_51 ) ;
F_42 ( V_29 -> V_2 ) ;
V_29 -> V_23 -> V_52 ( V_29 -> V_2 ) ;
V_29 -> V_23 -> V_53 ( V_29 -> V_2 ) ;
F_15 ( V_29 -> V_2 , NULL ) ;
V_29 -> V_23 = NULL ;
V_29 -> V_9 . V_23 = NULL ;
V_29 -> V_2 -> V_9 . V_23 = NULL ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = NULL ;
F_33 ( & V_45 ) ;
F_44 (udc, &udc_list, list)
if ( V_29 -> V_2 == V_2 )
goto V_54;
F_3 ( V_2 -> V_9 . V_31 , L_9 ) ;
F_36 ( & V_45 ) ;
return;
V_54:
F_22 ( V_2 -> V_9 . V_31 , L_10 ) ;
F_37 ( & V_29 -> V_46 ) ;
F_36 ( & V_45 ) ;
if ( V_29 -> V_23 )
F_40 ( V_29 ) ;
F_41 ( & V_29 -> V_9 . V_19 , V_55 ) ;
F_45 ( & V_2 -> V_18 ) ;
F_46 ( & V_29 -> V_9 ) ;
F_46 ( & V_2 -> V_9 ) ;
}
static int F_47 ( struct V_28 * V_29 , struct V_22 * V_23 )
{
int V_32 ;
F_18 ( & V_29 -> V_9 , L_11 ,
V_23 -> V_56 ) ;
V_29 -> V_23 = V_23 ;
V_29 -> V_9 . V_23 = & V_23 -> V_23 ;
V_29 -> V_2 -> V_9 . V_23 = & V_23 -> V_23 ;
V_32 = V_23 -> V_57 ( V_29 -> V_2 , V_23 ) ;
if ( V_32 )
goto V_35;
V_32 = F_14 ( V_29 -> V_2 , V_23 ) ;
if ( V_32 ) {
V_23 -> V_53 ( V_29 -> V_2 ) ;
goto V_35;
}
F_48 ( V_29 -> V_2 ) ;
F_41 ( & V_29 -> V_9 . V_19 , V_51 ) ;
return 0 ;
V_35:
if ( V_32 != - V_58 )
F_3 ( & V_29 -> V_9 , L_12 ,
V_29 -> V_23 -> V_56 , V_32 ) ;
V_29 -> V_23 = NULL ;
V_29 -> V_9 . V_23 = NULL ;
V_29 -> V_2 -> V_9 . V_23 = NULL ;
return V_32 ;
}
int F_49 ( const char * V_50 , struct V_22 * V_23 )
{
struct V_28 * V_29 = NULL ;
int V_32 = - V_59 ;
F_33 ( & V_45 ) ;
F_44 (udc, &udc_list, list) {
V_32 = strcmp ( V_50 , F_19 ( & V_29 -> V_9 ) ) ;
if ( ! V_32 )
break;
}
if ( V_32 ) {
V_32 = - V_59 ;
goto V_60;
}
if ( V_29 -> V_23 ) {
V_32 = - V_61 ;
goto V_60;
}
V_32 = F_47 ( V_29 , V_23 ) ;
V_60:
F_36 ( & V_45 ) ;
return V_32 ;
}
int F_50 ( struct V_22 * V_23 )
{
struct V_28 * V_29 = NULL ;
int V_32 ;
if ( ! V_23 || ! V_23 -> V_57 || ! V_23 -> V_62 )
return - V_63 ;
F_33 ( & V_45 ) ;
F_44 (udc, &udc_list, list) {
if ( ! V_29 -> V_23 )
goto V_54;
}
F_51 ( L_13 ) ;
F_36 ( & V_45 ) ;
return - V_59 ;
V_54:
V_32 = F_47 ( V_29 , V_23 ) ;
F_36 ( & V_45 ) ;
return V_32 ;
}
int F_52 ( struct V_22 * V_23 )
{
struct V_28 * V_29 = NULL ;
int V_32 = - V_59 ;
if ( ! V_23 || ! V_23 -> V_53 )
return - V_63 ;
F_33 ( & V_45 ) ;
F_44 (udc, &udc_list, list)
if ( V_29 -> V_23 == V_23 ) {
F_40 ( V_29 ) ;
V_32 = 0 ;
break;
}
F_36 ( & V_45 ) ;
return V_32 ;
}
static T_1 F_53 ( struct V_27 * V_9 ,
struct V_64 * V_65 , const char * V_16 , T_2 V_66 )
{
struct V_28 * V_29 = F_17 ( V_9 , struct V_28 , V_9 ) ;
if ( F_54 ( V_16 , L_14 ) )
F_55 ( V_29 -> V_2 ) ;
return V_66 ;
}
static T_1 F_56 ( struct V_27 * V_9 ,
struct V_64 * V_65 , const char * V_16 , T_2 V_66 )
{
struct V_28 * V_29 = F_17 ( V_9 , struct V_28 , V_9 ) ;
if ( F_54 ( V_16 , L_15 ) ) {
F_14 ( V_29 -> V_2 , V_29 -> V_23 ) ;
F_48 ( V_29 -> V_2 ) ;
} else if ( F_54 ( V_16 , L_16 ) ) {
F_42 ( V_29 -> V_2 ) ;
F_15 ( V_29 -> V_2 , V_29 -> V_23 ) ;
} else {
F_3 ( V_9 , L_17 , V_16 ) ;
return - V_63 ;
}
return V_66 ;
}
static T_1 F_57 ( struct V_27 * V_9 , struct V_64 * V_65 ,
char * V_16 )
{
struct V_28 * V_29 = F_17 ( V_9 , struct V_28 , V_9 ) ;
struct V_1 * V_2 = V_29 -> V_2 ;
return sprintf ( V_16 , L_5 , F_58 ( V_2 -> V_21 ) ) ;
}
static int F_59 ( struct V_27 * V_9 , struct V_67 * V_68 )
{
struct V_28 * V_29 = F_17 ( V_9 , struct V_28 , V_9 ) ;
int V_32 ;
V_32 = F_60 ( V_68 , L_18 , V_29 -> V_2 -> V_50 ) ;
if ( V_32 ) {
F_3 ( V_9 , L_19 ) ;
return V_32 ;
}
if ( V_29 -> V_23 ) {
V_32 = F_60 ( V_68 , L_20 ,
V_29 -> V_23 -> V_56 ) ;
if ( V_32 ) {
F_3 ( V_9 , L_21 ) ;
return V_32 ;
}
}
return 0 ;
}
static int T_3 F_61 ( void )
{
V_41 = F_62 ( V_69 , L_22 ) ;
if ( F_63 ( V_41 ) ) {
F_64 ( L_23 ,
F_65 ( V_41 ) ) ;
return F_65 ( V_41 ) ;
}
V_41 -> V_70 = F_59 ;
return 0 ;
}
static void T_4 F_66 ( void )
{
F_67 ( V_41 ) ;
}

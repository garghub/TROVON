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
void F_9 ( struct V_17 * V_18 ,
struct V_3 * V_4 )
{
if ( F_10 ( V_4 -> V_19 == 0 ) )
F_11 ( V_20 ) ;
V_4 -> V_21 ( V_18 , V_4 ) ;
}
static void F_12 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_13 ( V_23 ) ;
struct V_24 * V_25 = NULL ;
F_14 ( & V_26 ) ;
F_15 (udc, &udc_list, list)
if ( V_25 -> V_2 == V_2 )
goto V_27;
F_16 ( & V_26 ) ;
return;
V_27:
F_16 ( & V_26 ) ;
F_17 ( & V_25 -> V_9 . V_28 , NULL , L_3 ) ;
}
void F_18 ( struct V_1 * V_2 ,
enum V_29 V_30 )
{
V_2 -> V_30 = V_30 ;
F_19 ( & V_2 -> V_23 ) ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
V_32 -> V_33 ( V_2 ) ;
F_18 ( V_2 , V_34 ) ;
}
static inline int F_21 ( struct V_24 * V_25 )
{
return V_25 -> V_2 -> V_35 -> V_36 ( V_25 -> V_2 , V_25 -> V_32 ) ;
}
static inline void F_22 ( struct V_24 * V_25 )
{
V_25 -> V_2 -> V_35 -> V_37 ( V_25 -> V_2 ) ;
}
static void F_23 ( struct V_38 * V_9 )
{
struct V_24 * V_25 ;
V_25 = F_24 ( V_9 , struct V_24 , V_9 ) ;
F_25 ( V_9 , L_4 , F_26 ( V_9 ) ) ;
F_27 ( V_25 ) ;
}
static void F_28 ( struct V_38 * V_9 )
{
F_29 ( V_9 , L_5 , V_39 ) ;
}
int F_30 ( struct V_38 * V_40 , struct V_1 * V_2 ,
void (* F_31)( struct V_38 * V_9 ) )
{
struct V_24 * V_25 ;
int V_41 = - V_42 ;
V_25 = F_32 ( sizeof( * V_25 ) , V_43 ) ;
if ( ! V_25 )
goto V_44;
F_33 ( & V_2 -> V_9 , L_6 ) ;
F_34 ( & V_2 -> V_23 , F_12 ) ;
V_2 -> V_9 . V_40 = V_40 ;
#ifdef F_35
F_36 ( & V_2 -> V_9 , V_40 -> V_45 ) ;
V_2 -> V_9 . V_46 = V_40 -> V_46 ;
V_2 -> V_9 . V_47 = V_40 -> V_47 ;
#endif
if ( F_31 )
V_2 -> V_9 . F_31 = F_31 ;
else
V_2 -> V_9 . F_31 = F_28 ;
V_41 = F_37 ( & V_2 -> V_9 ) ;
if ( V_41 )
goto V_48;
F_38 ( & V_25 -> V_9 ) ;
V_25 -> V_9 . F_31 = F_23 ;
V_25 -> V_9 . V_49 = V_50 ;
V_25 -> V_9 . V_51 = V_52 ;
V_25 -> V_9 . V_40 = V_40 ;
V_41 = F_33 ( & V_25 -> V_9 , L_7 , F_39 ( & V_40 -> V_28 ) ) ;
if ( V_41 )
goto V_53;
V_25 -> V_2 = V_2 ;
F_14 ( & V_26 ) ;
F_40 ( & V_25 -> V_54 , & V_55 ) ;
V_41 = F_41 ( & V_25 -> V_9 ) ;
if ( V_41 )
goto V_56;
F_18 ( V_2 , V_57 ) ;
F_16 ( & V_26 ) ;
return 0 ;
V_56:
F_42 ( & V_25 -> V_54 ) ;
F_16 ( & V_26 ) ;
V_53:
F_43 ( & V_25 -> V_9 ) ;
V_48:
F_43 ( & V_2 -> V_9 ) ;
F_27 ( V_25 ) ;
V_44:
return V_41 ;
}
int F_44 ( struct V_38 * V_40 , struct V_1 * V_2 )
{
return F_30 ( V_40 , V_2 , NULL ) ;
}
static void F_45 ( struct V_24 * V_25 )
{
F_25 ( & V_25 -> V_9 , L_8 ,
V_25 -> V_32 -> V_58 ) ;
F_46 ( & V_25 -> V_9 . V_28 , V_59 ) ;
F_47 ( V_25 -> V_2 ) ;
V_25 -> V_32 -> V_60 ( V_25 -> V_2 ) ;
V_25 -> V_32 -> V_61 ( V_25 -> V_2 ) ;
F_22 ( V_25 ) ;
V_25 -> V_32 = NULL ;
V_25 -> V_9 . V_32 = NULL ;
V_25 -> V_2 -> V_9 . V_32 = NULL ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = NULL ;
F_14 ( & V_26 ) ;
F_15 (udc, &udc_list, list)
if ( V_25 -> V_2 == V_2 )
goto V_27;
F_3 ( V_2 -> V_9 . V_40 , L_9 ) ;
F_16 ( & V_26 ) ;
return;
V_27:
F_29 ( V_2 -> V_9 . V_40 , L_10 ) ;
F_42 ( & V_25 -> V_54 ) ;
F_16 ( & V_26 ) ;
if ( V_25 -> V_32 )
F_45 ( V_25 ) ;
F_46 ( & V_25 -> V_9 . V_28 , V_62 ) ;
F_49 ( & V_2 -> V_23 ) ;
F_50 ( & V_25 -> V_9 ) ;
F_50 ( & V_2 -> V_9 ) ;
}
static int F_51 ( struct V_24 * V_25 , struct V_31 * V_32 )
{
int V_41 ;
F_25 ( & V_25 -> V_9 , L_11 ,
V_32 -> V_58 ) ;
V_25 -> V_32 = V_32 ;
V_25 -> V_9 . V_32 = & V_32 -> V_32 ;
V_25 -> V_2 -> V_9 . V_32 = & V_32 -> V_32 ;
V_41 = V_32 -> V_63 ( V_25 -> V_2 , V_32 ) ;
if ( V_41 )
goto V_44;
V_41 = F_21 ( V_25 ) ;
if ( V_41 ) {
V_32 -> V_61 ( V_25 -> V_2 ) ;
goto V_44;
}
F_52 ( V_25 -> V_2 ) ;
F_46 ( & V_25 -> V_9 . V_28 , V_59 ) ;
return 0 ;
V_44:
if ( V_41 != - V_64 )
F_3 ( & V_25 -> V_9 , L_12 ,
V_25 -> V_32 -> V_58 , V_41 ) ;
V_25 -> V_32 = NULL ;
V_25 -> V_9 . V_32 = NULL ;
V_25 -> V_2 -> V_9 . V_32 = NULL ;
return V_41 ;
}
int F_53 ( const char * V_65 , struct V_31 * V_32 )
{
struct V_24 * V_25 = NULL ;
int V_41 = - V_66 ;
F_14 ( & V_26 ) ;
F_15 (udc, &udc_list, list) {
V_41 = strcmp ( V_65 , F_26 ( & V_25 -> V_9 ) ) ;
if ( ! V_41 )
break;
}
if ( V_41 ) {
V_41 = - V_66 ;
goto V_67;
}
if ( V_25 -> V_32 ) {
V_41 = - V_68 ;
goto V_67;
}
V_41 = F_51 ( V_25 , V_32 ) ;
V_67:
F_16 ( & V_26 ) ;
return V_41 ;
}
int F_54 ( struct V_31 * V_32 )
{
struct V_24 * V_25 = NULL ;
int V_41 ;
if ( ! V_32 || ! V_32 -> V_63 || ! V_32 -> V_69 )
return - V_70 ;
F_14 ( & V_26 ) ;
F_15 (udc, &udc_list, list) {
if ( ! V_25 -> V_32 )
goto V_27;
}
F_55 ( L_13 ) ;
F_16 ( & V_26 ) ;
return - V_66 ;
V_27:
V_41 = F_51 ( V_25 , V_32 ) ;
F_16 ( & V_26 ) ;
return V_41 ;
}
int F_56 ( struct V_31 * V_32 )
{
struct V_24 * V_25 = NULL ;
int V_41 = - V_66 ;
if ( ! V_32 || ! V_32 -> V_61 )
return - V_70 ;
F_14 ( & V_26 ) ;
F_15 (udc, &udc_list, list)
if ( V_25 -> V_32 == V_32 ) {
F_45 ( V_25 ) ;
F_18 ( V_25 -> V_2 ,
V_57 ) ;
V_41 = 0 ;
break;
}
F_16 ( & V_26 ) ;
return V_41 ;
}
static T_1 F_57 ( struct V_38 * V_9 ,
struct V_71 * V_72 , const char * V_16 , T_2 V_73 )
{
struct V_24 * V_25 = F_24 ( V_9 , struct V_24 , V_9 ) ;
if ( F_58 ( V_16 , L_14 ) )
F_59 ( V_25 -> V_2 ) ;
return V_73 ;
}
static T_1 F_60 ( struct V_38 * V_9 ,
struct V_71 * V_72 , const char * V_16 , T_2 V_73 )
{
struct V_24 * V_25 = F_24 ( V_9 , struct V_24 , V_9 ) ;
if ( ! V_25 -> V_32 ) {
F_3 ( V_9 , L_15 ) ;
return - V_74 ;
}
if ( F_58 ( V_16 , L_16 ) ) {
F_21 ( V_25 ) ;
F_52 ( V_25 -> V_2 ) ;
} else if ( F_58 ( V_16 , L_17 ) ) {
F_47 ( V_25 -> V_2 ) ;
V_25 -> V_32 -> V_60 ( V_25 -> V_2 ) ;
F_22 ( V_25 ) ;
} else {
F_3 ( V_9 , L_18 , V_16 ) ;
return - V_70 ;
}
return V_73 ;
}
static T_1 F_61 ( struct V_38 * V_9 , struct V_71 * V_72 ,
char * V_16 )
{
struct V_24 * V_25 = F_24 ( V_9 , struct V_24 , V_9 ) ;
struct V_1 * V_2 = V_25 -> V_2 ;
return sprintf ( V_16 , L_5 , F_62 ( V_2 -> V_30 ) ) ;
}
static int F_63 ( struct V_38 * V_9 , struct V_75 * V_76 )
{
struct V_24 * V_25 = F_24 ( V_9 , struct V_24 , V_9 ) ;
int V_41 ;
V_41 = F_64 ( V_76 , L_19 , V_25 -> V_2 -> V_65 ) ;
if ( V_41 ) {
F_3 ( V_9 , L_20 ) ;
return V_41 ;
}
if ( V_25 -> V_32 ) {
V_41 = F_64 ( V_76 , L_21 ,
V_25 -> V_32 -> V_58 ) ;
if ( V_41 ) {
F_3 ( V_9 , L_22 ) ;
return V_41 ;
}
}
return 0 ;
}
static int T_3 F_65 ( void )
{
V_50 = F_66 ( V_77 , L_23 ) ;
if ( F_67 ( V_50 ) ) {
F_68 ( L_24 ,
F_69 ( V_50 ) ) ;
return F_69 ( V_50 ) ;
}
V_50 -> V_78 = F_63 ;
return 0 ;
}
static void T_4 F_70 ( void )
{
F_71 ( V_50 ) ;
}

int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 . V_8 ;
if ( V_4 -> V_9 == 0 )
return 0 ;
if ( V_4 -> V_10 ) {
int V_11 ;
V_11 = F_2 ( V_7 , V_4 -> V_12 , V_4 -> V_10 ,
V_5 ? V_13 : V_14 ) ;
if ( V_11 == 0 ) {
F_3 ( & V_2 -> V_7 , L_1 ) ;
return - V_15 ;
}
V_4 -> V_16 = V_11 ;
} else {
V_4 -> V_17 = F_4 ( V_7 , V_4 -> V_18 , V_4 -> V_9 ,
V_5 ? V_13 : V_14 ) ;
if ( F_5 ( V_7 , V_4 -> V_17 ) ) {
F_3 ( V_7 , L_2 ) ;
return - V_15 ;
}
}
return 0 ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
if ( V_4 -> V_9 == 0 )
return;
if ( V_4 -> V_16 ) {
F_7 ( V_2 -> V_7 . V_8 , V_4 -> V_12 , V_4 -> V_16 ,
V_5 ? V_13 : V_14 ) ;
V_4 -> V_16 = 0 ;
} else {
F_8 ( V_2 -> V_7 . V_8 , V_4 -> V_17 , V_4 -> V_9 ,
V_5 ? V_13 : V_14 ) ;
}
}
void F_9 ( struct V_19 * V_20 ,
struct V_3 * V_4 )
{
if ( F_10 ( V_4 -> V_21 == 0 ) )
F_11 ( V_22 ) ;
V_4 -> V_23 ( V_20 , V_4 ) ;
}
static void F_12 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_13 ( V_25 ) ;
struct V_26 * V_27 = V_2 -> V_27 ;
if ( V_27 )
F_14 ( & V_27 -> V_7 . V_28 , NULL , L_3 ) ;
}
void F_15 ( struct V_1 * V_2 ,
enum V_29 V_30 )
{
V_2 -> V_30 = V_30 ;
F_16 ( & V_2 -> V_25 ) ;
}
static void F_17 ( struct V_26 * V_27 )
{
if ( V_27 -> V_31 )
F_18 ( V_27 -> V_2 ) ;
else
F_19 ( V_27 -> V_2 ) ;
}
void F_20 ( struct V_1 * V_2 , bool V_21 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
if ( V_27 ) {
V_27 -> V_31 = V_21 ;
F_17 ( V_27 ) ;
}
}
void F_21 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
V_33 -> V_34 ( V_2 ) ;
F_15 ( V_2 , V_35 ) ;
}
static inline int F_22 ( struct V_26 * V_27 )
{
return V_27 -> V_2 -> V_36 -> V_37 ( V_27 -> V_2 , V_27 -> V_33 ) ;
}
static inline void F_23 ( struct V_26 * V_27 )
{
V_27 -> V_2 -> V_36 -> V_38 ( V_27 -> V_2 ) ;
}
static void F_24 ( struct V_6 * V_7 )
{
struct V_26 * V_27 ;
V_27 = F_25 ( V_7 , struct V_26 , V_7 ) ;
F_26 ( V_7 , L_4 , F_27 ( V_7 ) ) ;
F_28 ( V_27 ) ;
}
static void F_29 ( struct V_6 * V_7 )
{
F_30 ( V_7 , L_5 , V_39 ) ;
}
int F_31 ( struct V_6 * V_8 , struct V_1 * V_2 ,
void (* F_32)( struct V_6 * V_7 ) )
{
struct V_26 * V_27 ;
int V_40 = - V_41 ;
V_27 = F_33 ( sizeof( * V_27 ) , V_42 ) ;
if ( ! V_27 )
goto V_43;
F_34 ( & V_2 -> V_7 , L_6 ) ;
F_35 ( & V_2 -> V_25 , F_12 ) ;
V_2 -> V_7 . V_8 = V_8 ;
#ifdef F_36
F_37 ( & V_2 -> V_7 , V_8 -> V_44 ) ;
V_2 -> V_7 . V_45 = V_8 -> V_45 ;
V_2 -> V_7 . V_46 = V_8 -> V_46 ;
#endif
if ( F_32 )
V_2 -> V_7 . F_32 = F_32 ;
else
V_2 -> V_7 . F_32 = F_29 ;
V_40 = F_38 ( & V_2 -> V_7 ) ;
if ( V_40 )
goto V_47;
F_39 ( & V_27 -> V_7 ) ;
V_27 -> V_7 . F_32 = F_24 ;
V_27 -> V_7 . V_48 = V_49 ;
V_27 -> V_7 . V_50 = V_51 ;
V_27 -> V_7 . V_8 = V_8 ;
V_40 = F_34 ( & V_27 -> V_7 , L_7 , F_40 ( & V_8 -> V_28 ) ) ;
if ( V_40 )
goto V_52;
V_27 -> V_2 = V_2 ;
V_2 -> V_27 = V_27 ;
F_41 ( & V_53 ) ;
F_42 ( & V_27 -> V_54 , & V_55 ) ;
V_40 = F_43 ( & V_27 -> V_7 ) ;
if ( V_40 )
goto V_56;
F_15 ( V_2 , V_57 ) ;
V_27 -> V_31 = true ;
F_44 ( & V_53 ) ;
return 0 ;
V_56:
F_45 ( & V_27 -> V_54 ) ;
F_44 ( & V_53 ) ;
V_52:
F_46 ( & V_27 -> V_7 ) ;
F_47 ( & V_2 -> V_7 ) ;
V_47:
F_46 ( & V_2 -> V_7 ) ;
F_28 ( V_27 ) ;
V_43:
return V_40 ;
}
int F_48 ( struct V_6 * V_8 , struct V_1 * V_2 )
{
return F_31 ( V_8 , V_2 , NULL ) ;
}
static void F_49 ( struct V_26 * V_27 )
{
F_26 ( & V_27 -> V_7 , L_8 ,
V_27 -> V_33 -> V_58 ) ;
F_50 ( & V_27 -> V_7 . V_28 , V_59 ) ;
F_19 ( V_27 -> V_2 ) ;
V_27 -> V_33 -> V_60 ( V_27 -> V_2 ) ;
V_27 -> V_33 -> V_61 ( V_27 -> V_2 ) ;
F_23 ( V_27 ) ;
V_27 -> V_33 = NULL ;
V_27 -> V_7 . V_33 = NULL ;
V_27 -> V_2 -> V_7 . V_33 = NULL ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
if ( ! V_27 )
return;
F_30 ( V_2 -> V_7 . V_8 , L_9 ) ;
F_41 ( & V_53 ) ;
F_45 ( & V_27 -> V_54 ) ;
F_44 ( & V_53 ) ;
if ( V_27 -> V_33 )
F_49 ( V_27 ) ;
F_50 ( & V_27 -> V_7 . V_28 , V_62 ) ;
F_52 ( & V_2 -> V_25 ) ;
F_53 ( & V_27 -> V_7 ) ;
F_53 ( & V_2 -> V_7 ) ;
}
static int F_54 ( struct V_26 * V_27 , struct V_32 * V_33 )
{
int V_40 ;
F_26 ( & V_27 -> V_7 , L_10 ,
V_33 -> V_58 ) ;
V_27 -> V_33 = V_33 ;
V_27 -> V_7 . V_33 = & V_33 -> V_33 ;
V_27 -> V_2 -> V_7 . V_33 = & V_33 -> V_33 ;
V_40 = V_33 -> V_63 ( V_27 -> V_2 , V_33 ) ;
if ( V_40 )
goto V_43;
V_40 = F_22 ( V_27 ) ;
if ( V_40 ) {
V_33 -> V_61 ( V_27 -> V_2 ) ;
goto V_43;
}
F_17 ( V_27 ) ;
F_50 ( & V_27 -> V_7 . V_28 , V_59 ) ;
return 0 ;
V_43:
if ( V_40 != - V_64 )
F_3 ( & V_27 -> V_7 , L_11 ,
V_27 -> V_33 -> V_58 , V_40 ) ;
V_27 -> V_33 = NULL ;
V_27 -> V_7 . V_33 = NULL ;
V_27 -> V_2 -> V_7 . V_33 = NULL ;
return V_40 ;
}
int F_55 ( const char * V_65 , struct V_32 * V_33 )
{
struct V_26 * V_27 = NULL ;
int V_40 = - V_66 ;
F_41 ( & V_53 ) ;
F_56 (udc, &udc_list, list) {
V_40 = strcmp ( V_65 , F_27 ( & V_27 -> V_7 ) ) ;
if ( ! V_40 )
break;
}
if ( V_40 ) {
V_40 = - V_66 ;
goto V_67;
}
if ( V_27 -> V_33 ) {
V_40 = - V_68 ;
goto V_67;
}
V_40 = F_54 ( V_27 , V_33 ) ;
V_67:
F_44 ( & V_53 ) ;
return V_40 ;
}
int F_57 ( struct V_32 * V_33 )
{
struct V_26 * V_27 = NULL ;
int V_40 ;
if ( ! V_33 || ! V_33 -> V_63 || ! V_33 -> V_69 )
return - V_70 ;
F_41 ( & V_53 ) ;
F_56 (udc, &udc_list, list) {
if ( ! V_27 -> V_33 )
goto V_71;
}
F_58 ( L_12 ) ;
F_44 ( & V_53 ) ;
return - V_66 ;
V_71:
V_40 = F_54 ( V_27 , V_33 ) ;
F_44 ( & V_53 ) ;
return V_40 ;
}
int F_59 ( struct V_32 * V_33 )
{
struct V_26 * V_27 = NULL ;
int V_40 = - V_66 ;
if ( ! V_33 || ! V_33 -> V_61 )
return - V_70 ;
F_41 ( & V_53 ) ;
F_56 (udc, &udc_list, list)
if ( V_27 -> V_33 == V_33 ) {
F_49 ( V_27 ) ;
F_15 ( V_27 -> V_2 ,
V_57 ) ;
V_40 = 0 ;
break;
}
F_44 ( & V_53 ) ;
return V_40 ;
}
static T_1 F_60 ( struct V_6 * V_7 ,
struct V_72 * V_73 , const char * V_18 , T_2 V_74 )
{
struct V_26 * V_27 = F_25 ( V_7 , struct V_26 , V_7 ) ;
if ( F_61 ( V_18 , L_13 ) )
F_62 ( V_27 -> V_2 ) ;
return V_74 ;
}
static T_1 F_63 ( struct V_6 * V_7 ,
struct V_72 * V_73 , const char * V_18 , T_2 V_74 )
{
struct V_26 * V_27 = F_25 ( V_7 , struct V_26 , V_7 ) ;
if ( ! V_27 -> V_33 ) {
F_3 ( V_7 , L_14 ) ;
return - V_75 ;
}
if ( F_61 ( V_18 , L_15 ) ) {
F_22 ( V_27 ) ;
F_18 ( V_27 -> V_2 ) ;
} else if ( F_61 ( V_18 , L_16 ) ) {
F_19 ( V_27 -> V_2 ) ;
V_27 -> V_33 -> V_60 ( V_27 -> V_2 ) ;
F_23 ( V_27 ) ;
} else {
F_3 ( V_7 , L_17 , V_18 ) ;
return - V_70 ;
}
return V_74 ;
}
static T_1 F_64 ( struct V_6 * V_7 , struct V_72 * V_73 ,
char * V_18 )
{
struct V_26 * V_27 = F_25 ( V_7 , struct V_26 , V_7 ) ;
struct V_1 * V_2 = V_27 -> V_2 ;
return sprintf ( V_18 , L_5 , F_65 ( V_2 -> V_30 ) ) ;
}
static int F_66 ( struct V_6 * V_7 , struct V_76 * V_77 )
{
struct V_26 * V_27 = F_25 ( V_7 , struct V_26 , V_7 ) ;
int V_40 ;
V_40 = F_67 ( V_77 , L_18 , V_27 -> V_2 -> V_65 ) ;
if ( V_40 ) {
F_3 ( V_7 , L_19 ) ;
return V_40 ;
}
if ( V_27 -> V_33 ) {
V_40 = F_67 ( V_77 , L_20 ,
V_27 -> V_33 -> V_58 ) ;
if ( V_40 ) {
F_3 ( V_7 , L_21 ) ;
return V_40 ;
}
}
return 0 ;
}
static int T_3 F_68 ( void )
{
V_49 = F_69 ( V_78 , L_22 ) ;
if ( F_70 ( V_49 ) ) {
F_71 ( L_23 ,
F_72 ( V_49 ) ) ;
return F_72 ( V_49 ) ;
}
V_49 -> V_79 = F_66 ;
return 0 ;
}
static void T_4 F_73 ( void )
{
F_74 ( V_49 ) ;
}

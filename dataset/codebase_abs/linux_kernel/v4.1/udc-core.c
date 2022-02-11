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
struct V_24 * V_25 = V_2 -> V_25 ;
if ( V_25 )
F_14 ( & V_25 -> V_9 . V_26 , NULL , L_3 ) ;
}
void F_15 ( struct V_1 * V_2 ,
enum V_27 V_28 )
{
V_2 -> V_28 = V_28 ;
F_16 ( & V_2 -> V_23 ) ;
}
static void F_17 ( struct V_24 * V_25 )
{
if ( V_25 -> V_29 )
F_18 ( V_25 -> V_2 ) ;
else
F_19 ( V_25 -> V_2 ) ;
}
void F_20 ( struct V_1 * V_2 , bool V_19 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
if ( V_25 ) {
V_25 -> V_29 = V_19 ;
F_17 ( V_25 ) ;
}
}
void F_21 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
V_31 -> V_32 ( V_2 ) ;
F_15 ( V_2 , V_33 ) ;
}
static inline int F_22 ( struct V_24 * V_25 )
{
return V_25 -> V_2 -> V_34 -> V_35 ( V_25 -> V_2 , V_25 -> V_31 ) ;
}
static inline void F_23 ( struct V_24 * V_25 )
{
V_25 -> V_2 -> V_34 -> V_36 ( V_25 -> V_2 ) ;
}
static void F_24 ( struct V_37 * V_9 )
{
struct V_24 * V_25 ;
V_25 = F_25 ( V_9 , struct V_24 , V_9 ) ;
F_26 ( V_9 , L_4 , F_27 ( V_9 ) ) ;
F_28 ( V_25 ) ;
}
static void F_29 ( struct V_37 * V_9 )
{
F_30 ( V_9 , L_5 , V_38 ) ;
}
int F_31 ( struct V_37 * V_39 , struct V_1 * V_2 ,
void (* F_32)( struct V_37 * V_9 ) )
{
struct V_24 * V_25 ;
int V_40 = - V_41 ;
V_25 = F_33 ( sizeof( * V_25 ) , V_42 ) ;
if ( ! V_25 )
goto V_43;
F_34 ( & V_2 -> V_9 , L_6 ) ;
F_35 ( & V_2 -> V_23 , F_12 ) ;
V_2 -> V_9 . V_39 = V_39 ;
#ifdef F_36
F_37 ( & V_2 -> V_9 , V_39 -> V_44 ) ;
V_2 -> V_9 . V_45 = V_39 -> V_45 ;
V_2 -> V_9 . V_46 = V_39 -> V_46 ;
#endif
if ( F_32 )
V_2 -> V_9 . F_32 = F_32 ;
else
V_2 -> V_9 . F_32 = F_29 ;
V_40 = F_38 ( & V_2 -> V_9 ) ;
if ( V_40 )
goto V_47;
F_39 ( & V_25 -> V_9 ) ;
V_25 -> V_9 . F_32 = F_24 ;
V_25 -> V_9 . V_48 = V_49 ;
V_25 -> V_9 . V_50 = V_51 ;
V_25 -> V_9 . V_39 = V_39 ;
V_40 = F_34 ( & V_25 -> V_9 , L_7 , F_40 ( & V_39 -> V_26 ) ) ;
if ( V_40 )
goto V_52;
V_25 -> V_2 = V_2 ;
V_2 -> V_25 = V_25 ;
F_41 ( & V_53 ) ;
F_42 ( & V_25 -> V_54 , & V_55 ) ;
V_40 = F_43 ( & V_25 -> V_9 ) ;
if ( V_40 )
goto V_56;
F_15 ( V_2 , V_57 ) ;
V_25 -> V_29 = true ;
F_44 ( & V_53 ) ;
return 0 ;
V_56:
F_45 ( & V_25 -> V_54 ) ;
F_44 ( & V_53 ) ;
V_52:
F_46 ( & V_25 -> V_9 ) ;
V_47:
F_46 ( & V_2 -> V_9 ) ;
F_28 ( V_25 ) ;
V_43:
return V_40 ;
}
int F_47 ( struct V_37 * V_39 , struct V_1 * V_2 )
{
return F_31 ( V_39 , V_2 , NULL ) ;
}
static void F_48 ( struct V_24 * V_25 )
{
F_26 ( & V_25 -> V_9 , L_8 ,
V_25 -> V_31 -> V_58 ) ;
F_49 ( & V_25 -> V_9 . V_26 , V_59 ) ;
F_19 ( V_25 -> V_2 ) ;
V_25 -> V_31 -> V_60 ( V_25 -> V_2 ) ;
V_25 -> V_31 -> V_61 ( V_25 -> V_2 ) ;
F_23 ( V_25 ) ;
V_25 -> V_31 = NULL ;
V_25 -> V_9 . V_31 = NULL ;
V_25 -> V_2 -> V_9 . V_31 = NULL ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
if ( ! V_25 )
return;
F_30 ( V_2 -> V_9 . V_39 , L_9 ) ;
F_41 ( & V_53 ) ;
F_45 ( & V_25 -> V_54 ) ;
F_44 ( & V_53 ) ;
if ( V_25 -> V_31 )
F_48 ( V_25 ) ;
F_49 ( & V_25 -> V_9 . V_26 , V_62 ) ;
F_51 ( & V_2 -> V_23 ) ;
F_52 ( & V_25 -> V_9 ) ;
F_52 ( & V_2 -> V_9 ) ;
}
static int F_53 ( struct V_24 * V_25 , struct V_30 * V_31 )
{
int V_40 ;
F_26 ( & V_25 -> V_9 , L_10 ,
V_31 -> V_58 ) ;
V_25 -> V_31 = V_31 ;
V_25 -> V_9 . V_31 = & V_31 -> V_31 ;
V_25 -> V_2 -> V_9 . V_31 = & V_31 -> V_31 ;
V_40 = V_31 -> V_63 ( V_25 -> V_2 , V_31 ) ;
if ( V_40 )
goto V_43;
V_40 = F_22 ( V_25 ) ;
if ( V_40 ) {
V_31 -> V_61 ( V_25 -> V_2 ) ;
goto V_43;
}
F_17 ( V_25 ) ;
F_49 ( & V_25 -> V_9 . V_26 , V_59 ) ;
return 0 ;
V_43:
if ( V_40 != - V_64 )
F_3 ( & V_25 -> V_9 , L_11 ,
V_25 -> V_31 -> V_58 , V_40 ) ;
V_25 -> V_31 = NULL ;
V_25 -> V_9 . V_31 = NULL ;
V_25 -> V_2 -> V_9 . V_31 = NULL ;
return V_40 ;
}
int F_54 ( const char * V_65 , struct V_30 * V_31 )
{
struct V_24 * V_25 = NULL ;
int V_40 = - V_66 ;
F_41 ( & V_53 ) ;
F_55 (udc, &udc_list, list) {
V_40 = strcmp ( V_65 , F_27 ( & V_25 -> V_9 ) ) ;
if ( ! V_40 )
break;
}
if ( V_40 ) {
V_40 = - V_66 ;
goto V_67;
}
if ( V_25 -> V_31 ) {
V_40 = - V_68 ;
goto V_67;
}
V_40 = F_53 ( V_25 , V_31 ) ;
V_67:
F_44 ( & V_53 ) ;
return V_40 ;
}
int F_56 ( struct V_30 * V_31 )
{
struct V_24 * V_25 = NULL ;
int V_40 ;
if ( ! V_31 || ! V_31 -> V_63 || ! V_31 -> V_69 )
return - V_70 ;
F_41 ( & V_53 ) ;
F_55 (udc, &udc_list, list) {
if ( ! V_25 -> V_31 )
goto V_71;
}
F_57 ( L_12 ) ;
F_44 ( & V_53 ) ;
return - V_66 ;
V_71:
V_40 = F_53 ( V_25 , V_31 ) ;
F_44 ( & V_53 ) ;
return V_40 ;
}
int F_58 ( struct V_30 * V_31 )
{
struct V_24 * V_25 = NULL ;
int V_40 = - V_66 ;
if ( ! V_31 || ! V_31 -> V_61 )
return - V_70 ;
F_41 ( & V_53 ) ;
F_55 (udc, &udc_list, list)
if ( V_25 -> V_31 == V_31 ) {
F_48 ( V_25 ) ;
F_15 ( V_25 -> V_2 ,
V_57 ) ;
V_40 = 0 ;
break;
}
F_44 ( & V_53 ) ;
return V_40 ;
}
static T_1 F_59 ( struct V_37 * V_9 ,
struct V_72 * V_73 , const char * V_16 , T_2 V_74 )
{
struct V_24 * V_25 = F_25 ( V_9 , struct V_24 , V_9 ) ;
if ( F_60 ( V_16 , L_13 ) )
F_61 ( V_25 -> V_2 ) ;
return V_74 ;
}
static T_1 F_62 ( struct V_37 * V_9 ,
struct V_72 * V_73 , const char * V_16 , T_2 V_74 )
{
struct V_24 * V_25 = F_25 ( V_9 , struct V_24 , V_9 ) ;
if ( ! V_25 -> V_31 ) {
F_3 ( V_9 , L_14 ) ;
return - V_75 ;
}
if ( F_60 ( V_16 , L_15 ) ) {
F_22 ( V_25 ) ;
F_18 ( V_25 -> V_2 ) ;
} else if ( F_60 ( V_16 , L_16 ) ) {
F_19 ( V_25 -> V_2 ) ;
V_25 -> V_31 -> V_60 ( V_25 -> V_2 ) ;
F_23 ( V_25 ) ;
} else {
F_3 ( V_9 , L_17 , V_16 ) ;
return - V_70 ;
}
return V_74 ;
}
static T_1 F_63 ( struct V_37 * V_9 , struct V_72 * V_73 ,
char * V_16 )
{
struct V_24 * V_25 = F_25 ( V_9 , struct V_24 , V_9 ) ;
struct V_1 * V_2 = V_25 -> V_2 ;
return sprintf ( V_16 , L_5 , F_64 ( V_2 -> V_28 ) ) ;
}
static int F_65 ( struct V_37 * V_9 , struct V_76 * V_77 )
{
struct V_24 * V_25 = F_25 ( V_9 , struct V_24 , V_9 ) ;
int V_40 ;
V_40 = F_66 ( V_77 , L_18 , V_25 -> V_2 -> V_65 ) ;
if ( V_40 ) {
F_3 ( V_9 , L_19 ) ;
return V_40 ;
}
if ( V_25 -> V_31 ) {
V_40 = F_66 ( V_77 , L_20 ,
V_25 -> V_31 -> V_58 ) ;
if ( V_40 ) {
F_3 ( V_9 , L_21 ) ;
return V_40 ;
}
}
return 0 ;
}
static int T_3 F_67 ( void )
{
V_49 = F_68 ( V_78 , L_22 ) ;
if ( F_69 ( V_49 ) ) {
F_70 ( L_23 ,
F_71 ( V_49 ) ) ;
return F_71 ( V_49 ) ;
}
V_49 -> V_79 = F_65 ;
return 0 ;
}
static void T_4 F_72 ( void )
{
F_73 ( V_49 ) ;
}

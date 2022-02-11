int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
if ( V_4 -> V_6 == 0 )
return 0 ;
if ( V_4 -> V_7 ) {
int V_8 ;
V_8 = F_2 ( V_2 , V_4 -> V_9 , V_4 -> V_7 ,
V_5 ? V_10 : V_11 ) ;
if ( V_8 == 0 ) {
F_3 ( V_2 , L_1 ) ;
return - V_12 ;
}
V_4 -> V_13 = V_8 ;
} else {
V_4 -> V_14 = F_4 ( V_2 , V_4 -> V_15 , V_4 -> V_6 ,
V_5 ? V_10 : V_11 ) ;
if ( F_5 ( V_2 , V_4 -> V_14 ) ) {
F_3 ( V_2 , L_2 ) ;
return - V_12 ;
}
}
return 0 ;
}
int F_6 ( struct V_16 * V_17 ,
struct V_3 * V_4 , int V_5 )
{
return F_1 ( V_17 -> V_2 . V_18 , V_4 , V_5 ) ;
}
void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
if ( V_4 -> V_6 == 0 )
return;
if ( V_4 -> V_13 ) {
F_8 ( V_2 , V_4 -> V_9 , V_4 -> V_13 ,
V_5 ? V_10 : V_11 ) ;
V_4 -> V_13 = 0 ;
} else {
F_9 ( V_2 , V_4 -> V_14 , V_4 -> V_6 ,
V_5 ? V_10 : V_11 ) ;
}
}
void F_10 ( struct V_16 * V_17 ,
struct V_3 * V_4 , int V_5 )
{
F_7 ( V_17 -> V_2 . V_18 , V_4 , V_5 ) ;
}
void F_11 ( struct V_19 * V_20 ,
struct V_3 * V_4 )
{
if ( F_12 ( V_4 -> V_21 == 0 ) )
F_13 ( V_22 ) ;
V_4 -> V_23 ( V_20 , V_4 ) ;
}
struct V_19 * F_14 ( struct V_16 * V_24 , const char * V_25 )
{
struct V_19 * V_20 ;
F_15 (ep, g) {
if ( ! strcmp ( V_20 -> V_25 , V_25 ) )
return V_20 ;
}
return NULL ;
}
int F_16 ( struct V_16 * V_17 ,
struct V_19 * V_20 , struct V_26 * V_27 ,
struct V_28 * V_29 )
{
T_1 type ;
T_2 V_30 ;
int V_31 = 0 ;
if ( V_20 -> V_32 )
return 0 ;
type = F_17 ( V_27 ) ;
V_30 = 0x7ff & F_18 ( V_27 ) ;
if ( F_19 ( V_27 ) && ! V_20 -> V_33 . V_34 )
return 0 ;
if ( F_20 ( V_27 ) && ! V_20 -> V_33 . V_35 )
return 0 ;
if ( V_30 > V_20 -> V_36 )
return 0 ;
if ( ! F_21 ( V_17 ) && F_18 ( V_27 ) & ( 3 << 11 ) )
return 0 ;
switch ( type ) {
case V_37 :
return 0 ;
case V_38 :
if ( ! V_20 -> V_33 . V_39 )
return 0 ;
if ( ! F_21 ( V_17 ) && V_30 > 1023 )
return 0 ;
break;
case V_40 :
if ( ! V_20 -> V_33 . V_41 )
return 0 ;
if ( V_29 && F_22 ( V_17 ) ) {
V_31 = V_29 -> V_42 & 0x1f ;
if ( V_31 > V_20 -> V_43 )
return 0 ;
}
break;
case V_44 :
if ( ! V_20 -> V_33 . V_45 && ! V_20 -> V_33 . V_41 )
return 0 ;
if ( ! F_21 ( V_17 ) && V_30 > 64 )
return 0 ;
break;
}
return 1 ;
}
static void F_23 ( struct V_46 * V_47 )
{
struct V_16 * V_17 = F_24 ( V_47 ) ;
struct V_48 * V_49 = V_17 -> V_49 ;
if ( V_49 )
F_25 ( & V_49 -> V_2 . V_50 , NULL , L_3 ) ;
}
void F_26 ( struct V_16 * V_17 ,
enum V_51 V_52 )
{
V_17 -> V_52 = V_52 ;
F_27 ( & V_17 -> V_47 ) ;
}
static void F_28 ( struct V_48 * V_49 )
{
if ( V_49 -> V_53 )
F_29 ( V_49 -> V_17 ) ;
else
F_30 ( V_49 -> V_17 ) ;
}
void F_31 ( struct V_16 * V_17 , bool V_21 )
{
struct V_48 * V_49 = V_17 -> V_49 ;
if ( V_49 ) {
V_49 -> V_53 = V_21 ;
F_28 ( V_49 ) ;
}
}
void F_32 ( struct V_16 * V_17 ,
struct V_54 * V_55 )
{
V_55 -> V_56 ( V_17 ) ;
F_26 ( V_17 , V_57 ) ;
}
static inline int F_33 ( struct V_48 * V_49 )
{
return V_49 -> V_17 -> V_58 -> V_59 ( V_49 -> V_17 , V_49 -> V_55 ) ;
}
static inline void F_34 ( struct V_48 * V_49 )
{
V_49 -> V_17 -> V_58 -> V_60 ( V_49 -> V_17 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
V_49 = F_36 ( V_2 , struct V_48 , V_2 ) ;
F_37 ( V_2 , L_4 , F_38 ( V_2 ) ) ;
F_39 ( V_49 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_41 ( V_2 , L_5 , V_61 ) ;
}
int F_42 ( struct V_1 * V_18 , struct V_16 * V_17 ,
void (* F_43)( struct V_1 * V_2 ) )
{
struct V_48 * V_49 ;
struct V_54 * V_55 ;
int V_62 = - V_63 ;
V_49 = F_44 ( sizeof( * V_49 ) , V_64 ) ;
if ( ! V_49 )
goto V_65;
F_45 ( & V_17 -> V_2 , L_6 ) ;
F_46 ( & V_17 -> V_47 , F_23 ) ;
V_17 -> V_2 . V_18 = V_18 ;
if ( F_43 )
V_17 -> V_2 . F_43 = F_43 ;
else
V_17 -> V_2 . F_43 = F_40 ;
V_62 = F_47 ( & V_17 -> V_2 ) ;
if ( V_62 )
goto V_66;
F_48 ( & V_49 -> V_2 ) ;
V_49 -> V_2 . F_43 = F_35 ;
V_49 -> V_2 . V_67 = V_68 ;
V_49 -> V_2 . V_69 = V_70 ;
V_49 -> V_2 . V_18 = V_18 ;
V_62 = F_45 ( & V_49 -> V_2 , L_7 , F_49 ( & V_18 -> V_50 ) ) ;
if ( V_62 )
goto V_71;
V_49 -> V_17 = V_17 ;
V_17 -> V_49 = V_49 ;
F_50 ( & V_72 ) ;
F_51 ( & V_49 -> V_73 , & V_74 ) ;
V_62 = F_52 ( & V_49 -> V_2 ) ;
if ( V_62 )
goto V_75;
F_26 ( V_17 , V_76 ) ;
V_49 -> V_53 = true ;
F_53 (driver, &gadget_driver_pending_list, pending) {
if ( ! V_55 -> V_77 || strcmp ( V_55 -> V_77 ,
F_38 ( & V_49 -> V_2 ) ) == 0 ) {
V_62 = F_54 ( V_49 , V_55 ) ;
if ( V_62 != - V_78 )
F_55 ( & V_55 -> V_79 ) ;
if ( V_62 )
goto V_75;
break;
}
}
F_56 ( & V_72 ) ;
return 0 ;
V_75:
F_55 ( & V_49 -> V_73 ) ;
F_56 ( & V_72 ) ;
V_71:
F_57 ( & V_49 -> V_2 ) ;
F_58 ( & V_17 -> V_2 ) ;
V_66:
F_57 ( & V_17 -> V_2 ) ;
F_39 ( V_49 ) ;
V_65:
return V_62 ;
}
char * F_59 ( void )
{
struct V_48 * V_49 ;
char * V_25 = NULL ;
F_50 ( & V_72 ) ;
F_53 (udc, &udc_list, list) {
if ( ! V_49 -> V_55 ) {
V_25 = F_60 ( V_49 -> V_17 -> V_25 , V_64 ) ;
break;
}
}
F_56 ( & V_72 ) ;
return V_25 ;
}
int F_61 ( struct V_1 * V_18 , struct V_16 * V_17 )
{
return F_42 ( V_18 , V_17 , NULL ) ;
}
static void F_62 ( struct V_48 * V_49 )
{
F_37 ( & V_49 -> V_2 , L_8 ,
V_49 -> V_55 -> V_80 ) ;
F_63 ( & V_49 -> V_2 . V_50 , V_81 ) ;
F_30 ( V_49 -> V_17 ) ;
V_49 -> V_55 -> V_82 ( V_49 -> V_17 ) ;
V_49 -> V_55 -> V_83 ( V_49 -> V_17 ) ;
F_34 ( V_49 ) ;
V_49 -> V_55 = NULL ;
V_49 -> V_2 . V_55 = NULL ;
V_49 -> V_17 -> V_2 . V_55 = NULL ;
}
void F_64 ( struct V_16 * V_17 )
{
struct V_48 * V_49 = V_17 -> V_49 ;
if ( ! V_49 )
return;
F_41 ( V_17 -> V_2 . V_18 , L_9 ) ;
F_50 ( & V_72 ) ;
F_55 ( & V_49 -> V_73 ) ;
if ( V_49 -> V_55 ) {
struct V_54 * V_55 = V_49 -> V_55 ;
F_62 ( V_49 ) ;
F_65 ( & V_55 -> V_79 , & V_84 ) ;
}
F_56 ( & V_72 ) ;
F_63 ( & V_49 -> V_2 . V_50 , V_85 ) ;
F_66 ( & V_17 -> V_47 ) ;
F_67 ( & V_49 -> V_2 ) ;
F_67 ( & V_17 -> V_2 ) ;
}
static int F_54 ( struct V_48 * V_49 , struct V_54 * V_55 )
{
int V_62 ;
F_37 ( & V_49 -> V_2 , L_10 ,
V_55 -> V_80 ) ;
V_49 -> V_55 = V_55 ;
V_49 -> V_2 . V_55 = & V_55 -> V_55 ;
V_49 -> V_17 -> V_2 . V_55 = & V_55 -> V_55 ;
V_62 = V_55 -> V_86 ( V_49 -> V_17 , V_55 ) ;
if ( V_62 )
goto V_65;
V_62 = F_33 ( V_49 ) ;
if ( V_62 ) {
V_55 -> V_83 ( V_49 -> V_17 ) ;
goto V_65;
}
F_28 ( V_49 ) ;
F_63 ( & V_49 -> V_2 . V_50 , V_81 ) ;
return 0 ;
V_65:
if ( V_62 != - V_87 )
F_3 ( & V_49 -> V_2 , L_11 ,
V_49 -> V_55 -> V_80 , V_62 ) ;
V_49 -> V_55 = NULL ;
V_49 -> V_2 . V_55 = NULL ;
V_49 -> V_17 -> V_2 . V_55 = NULL ;
return V_62 ;
}
int F_68 ( struct V_54 * V_55 )
{
struct V_48 * V_49 = NULL ;
int V_62 = - V_88 ;
if ( ! V_55 || ! V_55 -> V_86 || ! V_55 -> V_89 )
return - V_90 ;
F_50 ( & V_72 ) ;
if ( V_55 -> V_77 ) {
F_53 (udc, &udc_list, list) {
V_62 = strcmp ( V_55 -> V_77 , F_38 ( & V_49 -> V_2 ) ) ;
if ( ! V_62 )
break;
}
if ( ! V_62 && ! V_49 -> V_55 )
goto V_91;
} else {
F_53 (udc, &udc_list, list) {
if ( ! V_49 -> V_55 )
goto V_91;
}
}
if ( ! V_55 -> V_92 ) {
F_51 ( & V_55 -> V_79 , & V_84 ) ;
F_69 ( L_12 ,
V_55 -> V_80 ) ;
V_62 = 0 ;
}
F_56 ( & V_72 ) ;
return V_62 ;
V_91:
V_62 = F_54 ( V_49 , V_55 ) ;
F_56 ( & V_72 ) ;
return V_62 ;
}
int F_70 ( struct V_54 * V_55 )
{
struct V_48 * V_49 = NULL ;
int V_62 = - V_88 ;
if ( ! V_55 || ! V_55 -> V_83 )
return - V_90 ;
F_50 ( & V_72 ) ;
F_53 (udc, &udc_list, list)
if ( V_49 -> V_55 == V_55 ) {
F_62 ( V_49 ) ;
F_26 ( V_49 -> V_17 ,
V_76 ) ;
V_62 = 0 ;
break;
}
if ( V_62 ) {
F_55 ( & V_55 -> V_79 ) ;
V_62 = 0 ;
}
F_56 ( & V_72 ) ;
return V_62 ;
}
static T_3 F_71 ( struct V_1 * V_2 ,
struct V_93 * V_94 , const char * V_15 , T_4 V_95 )
{
struct V_48 * V_49 = F_36 ( V_2 , struct V_48 , V_2 ) ;
if ( F_72 ( V_15 , L_13 ) )
F_73 ( V_49 -> V_17 ) ;
return V_95 ;
}
static T_3 F_74 ( struct V_1 * V_2 ,
struct V_93 * V_94 , const char * V_15 , T_4 V_95 )
{
struct V_48 * V_49 = F_36 ( V_2 , struct V_48 , V_2 ) ;
if ( ! V_49 -> V_55 ) {
F_3 ( V_2 , L_14 ) ;
return - V_96 ;
}
if ( F_72 ( V_15 , L_15 ) ) {
F_33 ( V_49 ) ;
F_29 ( V_49 -> V_17 ) ;
} else if ( F_72 ( V_15 , L_16 ) ) {
F_30 ( V_49 -> V_17 ) ;
V_49 -> V_55 -> V_82 ( V_49 -> V_17 ) ;
F_34 ( V_49 ) ;
} else {
F_3 ( V_2 , L_17 , V_15 ) ;
return - V_90 ;
}
return V_95 ;
}
static T_3 F_75 ( struct V_1 * V_2 , struct V_93 * V_94 ,
char * V_15 )
{
struct V_48 * V_49 = F_36 ( V_2 , struct V_48 , V_2 ) ;
struct V_16 * V_17 = V_49 -> V_17 ;
return sprintf ( V_15 , L_5 , F_76 ( V_17 -> V_52 ) ) ;
}
static int F_77 ( struct V_1 * V_2 , struct V_97 * V_98 )
{
struct V_48 * V_49 = F_36 ( V_2 , struct V_48 , V_2 ) ;
int V_62 ;
V_62 = F_78 ( V_98 , L_18 , V_49 -> V_17 -> V_25 ) ;
if ( V_62 ) {
F_3 ( V_2 , L_19 ) ;
return V_62 ;
}
if ( V_49 -> V_55 ) {
V_62 = F_78 ( V_98 , L_20 ,
V_49 -> V_55 -> V_80 ) ;
if ( V_62 ) {
F_3 ( V_2 , L_21 ) ;
return V_62 ;
}
}
return 0 ;
}
static int T_5 F_79 ( void )
{
V_68 = F_80 ( V_99 , L_22 ) ;
if ( F_81 ( V_68 ) ) {
F_82 ( L_23 ,
F_83 ( V_68 ) ) ;
return F_83 ( V_68 ) ;
}
V_68 -> V_100 = F_77 ;
return 0 ;
}
static void T_6 F_84 ( void )
{
F_85 ( V_68 ) ;
}

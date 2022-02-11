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
struct V_19 * F_12 ( struct V_1 * V_24 , const char * V_25 )
{
struct V_19 * V_20 ;
F_13 (ep, g) {
if ( ! strcmp ( V_20 -> V_25 , V_25 ) )
return V_20 ;
}
return NULL ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_19 * V_20 , struct V_26 * V_27 ,
struct V_28 * V_29 )
{
T_1 type ;
T_2 V_30 ;
int V_31 = 0 ;
if ( V_20 -> V_32 )
return 0 ;
type = F_15 ( V_27 ) ;
V_30 = 0x7ff & F_16 ( V_27 ) ;
if ( F_17 ( V_27 ) && ! V_20 -> V_33 . V_34 )
return 0 ;
if ( F_18 ( V_27 ) && ! V_20 -> V_33 . V_35 )
return 0 ;
if ( V_30 > V_20 -> V_36 )
return 0 ;
if ( ! F_19 ( V_2 ) && F_16 ( V_27 ) & ( 3 << 11 ) )
return 0 ;
switch ( type ) {
case V_37 :
return 0 ;
case V_38 :
if ( ! V_20 -> V_33 . V_39 )
return 0 ;
if ( ! F_19 ( V_2 ) && V_30 > 1023 )
return 0 ;
break;
case V_40 :
if ( ! V_20 -> V_33 . V_41 )
return 0 ;
if ( V_29 && F_20 ( V_2 ) ) {
V_31 = V_29 -> V_42 & 0x1f ;
if ( V_31 > V_20 -> V_43 )
return 0 ;
}
break;
case V_44 :
if ( ! V_20 -> V_33 . V_45 && ! V_20 -> V_33 . V_41 )
return 0 ;
if ( ! F_19 ( V_2 ) && V_30 > 64 )
return 0 ;
break;
}
return 1 ;
}
static void F_21 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_22 ( V_47 ) ;
struct V_48 * V_49 = V_2 -> V_49 ;
if ( V_49 )
F_23 ( & V_49 -> V_7 . V_50 , NULL , L_3 ) ;
}
void F_24 ( struct V_1 * V_2 ,
enum V_51 V_52 )
{
V_2 -> V_52 = V_52 ;
F_25 ( & V_2 -> V_47 ) ;
}
static void F_26 ( struct V_48 * V_49 )
{
if ( V_49 -> V_53 )
F_27 ( V_49 -> V_2 ) ;
else
F_28 ( V_49 -> V_2 ) ;
}
void F_29 ( struct V_1 * V_2 , bool V_21 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
if ( V_49 ) {
V_49 -> V_53 = V_21 ;
F_26 ( V_49 ) ;
}
}
void F_30 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
V_55 -> V_56 ( V_2 ) ;
F_24 ( V_2 , V_57 ) ;
}
static inline int F_31 ( struct V_48 * V_49 )
{
return V_49 -> V_2 -> V_58 -> V_59 ( V_49 -> V_2 , V_49 -> V_55 ) ;
}
static inline void F_32 ( struct V_48 * V_49 )
{
V_49 -> V_2 -> V_58 -> V_60 ( V_49 -> V_2 ) ;
}
static void F_33 ( struct V_6 * V_7 )
{
struct V_48 * V_49 ;
V_49 = F_34 ( V_7 , struct V_48 , V_7 ) ;
F_35 ( V_7 , L_4 , F_36 ( V_7 ) ) ;
F_37 ( V_49 ) ;
}
static void F_38 ( struct V_6 * V_7 )
{
F_39 ( V_7 , L_5 , V_61 ) ;
}
int F_40 ( struct V_6 * V_8 , struct V_1 * V_2 ,
void (* F_41)( struct V_6 * V_7 ) )
{
struct V_48 * V_49 ;
struct V_54 * V_55 ;
int V_62 = - V_63 ;
V_49 = F_42 ( sizeof( * V_49 ) , V_64 ) ;
if ( ! V_49 )
goto V_65;
F_43 ( & V_2 -> V_7 , L_6 ) ;
F_44 ( & V_2 -> V_47 , F_21 ) ;
V_2 -> V_7 . V_8 = V_8 ;
#ifdef F_45
F_46 ( & V_2 -> V_7 , V_8 -> V_66 ) ;
V_2 -> V_7 . V_67 = V_8 -> V_67 ;
V_2 -> V_7 . V_68 = V_8 -> V_68 ;
#endif
if ( F_41 )
V_2 -> V_7 . F_41 = F_41 ;
else
V_2 -> V_7 . F_41 = F_38 ;
V_62 = F_47 ( & V_2 -> V_7 ) ;
if ( V_62 )
goto V_69;
F_48 ( & V_49 -> V_7 ) ;
V_49 -> V_7 . F_41 = F_33 ;
V_49 -> V_7 . V_70 = V_71 ;
V_49 -> V_7 . V_72 = V_73 ;
V_49 -> V_7 . V_8 = V_8 ;
V_62 = F_43 ( & V_49 -> V_7 , L_7 , F_49 ( & V_8 -> V_50 ) ) ;
if ( V_62 )
goto V_74;
V_49 -> V_2 = V_2 ;
V_2 -> V_49 = V_49 ;
F_50 ( & V_75 ) ;
F_51 ( & V_49 -> V_76 , & V_77 ) ;
V_62 = F_52 ( & V_49 -> V_7 ) ;
if ( V_62 )
goto V_78;
F_24 ( V_2 , V_79 ) ;
V_49 -> V_53 = true ;
F_53 (driver, &gadget_driver_pending_list, pending) {
if ( ! V_55 -> V_80 || strcmp ( V_55 -> V_80 ,
F_36 ( & V_49 -> V_7 ) ) == 0 ) {
V_62 = F_54 ( V_49 , V_55 ) ;
if ( V_62 != - V_81 )
F_55 ( & V_55 -> V_82 ) ;
if ( V_62 )
goto V_78;
break;
}
}
F_56 ( & V_75 ) ;
return 0 ;
V_78:
F_55 ( & V_49 -> V_76 ) ;
F_56 ( & V_75 ) ;
V_74:
F_57 ( & V_49 -> V_7 ) ;
F_58 ( & V_2 -> V_7 ) ;
V_69:
F_57 ( & V_2 -> V_7 ) ;
F_37 ( V_49 ) ;
V_65:
return V_62 ;
}
int F_59 ( struct V_6 * V_8 , struct V_1 * V_2 )
{
return F_40 ( V_8 , V_2 , NULL ) ;
}
static void F_60 ( struct V_48 * V_49 )
{
F_35 ( & V_49 -> V_7 , L_8 ,
V_49 -> V_55 -> V_83 ) ;
F_61 ( & V_49 -> V_7 . V_50 , V_84 ) ;
F_28 ( V_49 -> V_2 ) ;
V_49 -> V_55 -> V_85 ( V_49 -> V_2 ) ;
V_49 -> V_55 -> V_86 ( V_49 -> V_2 ) ;
F_32 ( V_49 ) ;
V_49 -> V_55 = NULL ;
V_49 -> V_7 . V_55 = NULL ;
V_49 -> V_2 -> V_7 . V_55 = NULL ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
if ( ! V_49 )
return;
F_39 ( V_2 -> V_7 . V_8 , L_9 ) ;
F_50 ( & V_75 ) ;
F_55 ( & V_49 -> V_76 ) ;
if ( V_49 -> V_55 ) {
struct V_54 * V_55 = V_49 -> V_55 ;
F_60 ( V_49 ) ;
F_63 ( & V_55 -> V_82 , & V_87 ) ;
}
F_56 ( & V_75 ) ;
F_61 ( & V_49 -> V_7 . V_50 , V_88 ) ;
F_64 ( & V_2 -> V_47 ) ;
F_65 ( & V_49 -> V_7 ) ;
F_65 ( & V_2 -> V_7 ) ;
}
static int F_54 ( struct V_48 * V_49 , struct V_54 * V_55 )
{
int V_62 ;
F_35 ( & V_49 -> V_7 , L_10 ,
V_55 -> V_83 ) ;
V_49 -> V_55 = V_55 ;
V_49 -> V_7 . V_55 = & V_55 -> V_55 ;
V_49 -> V_2 -> V_7 . V_55 = & V_55 -> V_55 ;
V_62 = V_55 -> V_89 ( V_49 -> V_2 , V_55 ) ;
if ( V_62 )
goto V_65;
V_62 = F_31 ( V_49 ) ;
if ( V_62 ) {
V_55 -> V_86 ( V_49 -> V_2 ) ;
goto V_65;
}
F_26 ( V_49 ) ;
F_61 ( & V_49 -> V_7 . V_50 , V_84 ) ;
return 0 ;
V_65:
if ( V_62 != - V_90 )
F_3 ( & V_49 -> V_7 , L_11 ,
V_49 -> V_55 -> V_83 , V_62 ) ;
V_49 -> V_55 = NULL ;
V_49 -> V_7 . V_55 = NULL ;
V_49 -> V_2 -> V_7 . V_55 = NULL ;
return V_62 ;
}
int F_66 ( struct V_54 * V_55 )
{
struct V_48 * V_49 = NULL ;
int V_62 = - V_91 ;
if ( ! V_55 || ! V_55 -> V_89 || ! V_55 -> V_92 )
return - V_93 ;
F_50 ( & V_75 ) ;
if ( V_55 -> V_80 ) {
F_53 (udc, &udc_list, list) {
V_62 = strcmp ( V_55 -> V_80 , F_36 ( & V_49 -> V_7 ) ) ;
if ( ! V_62 )
break;
}
if ( ! V_62 && ! V_49 -> V_55 )
goto V_94;
} else {
F_53 (udc, &udc_list, list) {
if ( ! V_49 -> V_55 )
goto V_94;
}
}
F_51 ( & V_55 -> V_82 , & V_87 ) ;
F_67 ( L_12 ,
V_55 -> V_83 ) ;
F_56 ( & V_75 ) ;
return 0 ;
V_94:
V_62 = F_54 ( V_49 , V_55 ) ;
F_56 ( & V_75 ) ;
return V_62 ;
}
int F_68 ( struct V_54 * V_55 )
{
struct V_48 * V_49 = NULL ;
int V_62 = - V_91 ;
if ( ! V_55 || ! V_55 -> V_86 )
return - V_93 ;
F_50 ( & V_75 ) ;
F_53 (udc, &udc_list, list)
if ( V_49 -> V_55 == V_55 ) {
F_60 ( V_49 ) ;
F_24 ( V_49 -> V_2 ,
V_79 ) ;
V_62 = 0 ;
break;
}
if ( V_62 ) {
F_55 ( & V_55 -> V_82 ) ;
V_62 = 0 ;
}
F_56 ( & V_75 ) ;
return V_62 ;
}
static T_3 F_69 ( struct V_6 * V_7 ,
struct V_95 * V_96 , const char * V_18 , T_4 V_97 )
{
struct V_48 * V_49 = F_34 ( V_7 , struct V_48 , V_7 ) ;
if ( F_70 ( V_18 , L_13 ) )
F_71 ( V_49 -> V_2 ) ;
return V_97 ;
}
static T_3 F_72 ( struct V_6 * V_7 ,
struct V_95 * V_96 , const char * V_18 , T_4 V_97 )
{
struct V_48 * V_49 = F_34 ( V_7 , struct V_48 , V_7 ) ;
if ( ! V_49 -> V_55 ) {
F_3 ( V_7 , L_14 ) ;
return - V_98 ;
}
if ( F_70 ( V_18 , L_15 ) ) {
F_31 ( V_49 ) ;
F_27 ( V_49 -> V_2 ) ;
} else if ( F_70 ( V_18 , L_16 ) ) {
F_28 ( V_49 -> V_2 ) ;
V_49 -> V_55 -> V_85 ( V_49 -> V_2 ) ;
F_32 ( V_49 ) ;
} else {
F_3 ( V_7 , L_17 , V_18 ) ;
return - V_93 ;
}
return V_97 ;
}
static T_3 F_73 ( struct V_6 * V_7 , struct V_95 * V_96 ,
char * V_18 )
{
struct V_48 * V_49 = F_34 ( V_7 , struct V_48 , V_7 ) ;
struct V_1 * V_2 = V_49 -> V_2 ;
return sprintf ( V_18 , L_5 , F_74 ( V_2 -> V_52 ) ) ;
}
static int F_75 ( struct V_6 * V_7 , struct V_99 * V_100 )
{
struct V_48 * V_49 = F_34 ( V_7 , struct V_48 , V_7 ) ;
int V_62 ;
V_62 = F_76 ( V_100 , L_18 , V_49 -> V_2 -> V_25 ) ;
if ( V_62 ) {
F_3 ( V_7 , L_19 ) ;
return V_62 ;
}
if ( V_49 -> V_55 ) {
V_62 = F_76 ( V_100 , L_20 ,
V_49 -> V_55 -> V_83 ) ;
if ( V_62 ) {
F_3 ( V_7 , L_21 ) ;
return V_62 ;
}
}
return 0 ;
}
static int T_5 F_77 ( void )
{
V_71 = F_78 ( V_101 , L_22 ) ;
if ( F_79 ( V_71 ) ) {
F_80 ( L_23 ,
F_81 ( V_71 ) ) ;
return F_81 ( V_71 ) ;
}
V_71 -> V_102 = F_75 ;
return 0 ;
}
static void T_6 F_82 ( void )
{
F_83 ( V_71 ) ;
}

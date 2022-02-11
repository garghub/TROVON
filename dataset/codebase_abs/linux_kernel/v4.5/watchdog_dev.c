static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( V_2 -> V_4 -> V_5 )
V_3 = V_2 -> V_4 -> V_5 ( V_2 ) ;
else
V_3 = V_2 -> V_4 -> V_6 ( V_2 ) ;
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 ) )
return 0 ;
V_3 = V_2 -> V_4 -> V_6 ( V_2 ) ;
if ( V_3 == 0 )
F_4 ( V_7 , & V_2 -> V_8 ) ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( F_6 ( V_9 , & V_2 -> V_8 ) ) {
F_7 ( L_1 ,
V_2 -> V_10 ) ;
return - V_11 ;
}
V_3 = V_2 -> V_4 -> V_12 ( V_2 ) ;
if ( V_3 == 0 )
F_8 ( V_7 , & V_2 -> V_8 ) ;
return V_3 ;
}
static unsigned int F_9 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 -> V_8 )
return 0 ;
return V_2 -> V_4 -> V_8 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_13 )
{
if ( ! V_2 -> V_4 -> V_14 || ! ( V_2 -> V_15 -> V_16 & V_17 ) )
return - V_18 ;
if ( F_11 ( V_2 , V_13 ) )
return - V_19 ;
return V_2 -> V_4 -> V_14 ( V_2 , V_13 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int * V_20 )
{
* V_20 = 0 ;
if ( ! V_2 -> V_4 -> V_21 )
return - V_18 ;
* V_20 = V_2 -> V_4 -> V_21 ( V_2 ) ;
return 0 ;
}
static T_1 F_13 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_2 = F_14 ( V_23 ) ;
return sprintf ( V_26 , L_2 , ! ! F_6 ( V_9 , & V_2 -> V_8 ) ) ;
}
static T_1 F_15 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_2 = F_14 ( V_23 ) ;
struct V_27 * V_28 = V_2 -> V_28 ;
unsigned int V_8 ;
F_16 ( & V_28 -> V_29 ) ;
V_8 = F_9 ( V_2 ) ;
F_17 ( & V_28 -> V_29 ) ;
return sprintf ( V_26 , L_3 , V_8 ) ;
}
static T_1 F_18 ( struct V_22 * V_23 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_1 * V_2 = F_14 ( V_23 ) ;
return sprintf ( V_26 , L_3 , V_2 -> V_30 ) ;
}
static T_1 F_19 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_2 = F_14 ( V_23 ) ;
struct V_27 * V_28 = V_2 -> V_28 ;
T_1 V_8 ;
unsigned int V_31 ;
F_16 ( & V_28 -> V_29 ) ;
V_8 = F_12 ( V_2 , & V_31 ) ;
F_17 ( & V_28 -> V_29 ) ;
if ( ! V_8 )
V_8 = sprintf ( V_26 , L_3 , V_31 ) ;
return V_8 ;
}
static T_1 F_20 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_2 = F_14 ( V_23 ) ;
return sprintf ( V_26 , L_3 , V_2 -> V_13 ) ;
}
static T_1 F_21 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_2 = F_14 ( V_23 ) ;
return sprintf ( V_26 , L_4 , V_2 -> V_15 -> V_32 ) ;
}
static T_1 F_22 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_2 = F_14 ( V_23 ) ;
if ( F_2 ( V_2 ) )
return sprintf ( V_26 , L_5 ) ;
return sprintf ( V_26 , L_6 ) ;
}
static T_2 F_23 ( struct V_33 * V_34 , struct V_35 * V_25 ,
int V_36 )
{
struct V_22 * V_23 = F_24 ( V_34 , struct V_22 , V_34 ) ;
struct V_1 * V_2 = F_14 ( V_23 ) ;
T_2 V_37 = V_25 -> V_37 ;
if ( V_25 == & V_38 . V_25 && ! V_2 -> V_4 -> V_8 )
V_37 = 0 ;
else if ( V_25 == & V_39 . V_25 && ! V_2 -> V_4 -> V_21 )
V_37 = 0 ;
return V_37 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned int V_40 ,
unsigned long V_41 )
{
if ( ! V_2 -> V_4 -> V_42 )
return - V_43 ;
return V_2 -> V_4 -> V_42 ( V_2 , V_40 , V_41 ) ;
}
static T_1 F_26 ( struct V_44 * V_44 , const char T_3 * V_45 ,
T_4 V_46 , T_5 * V_47 )
{
struct V_27 * V_28 = V_44 -> V_48 ;
struct V_1 * V_2 ;
int V_3 ;
T_4 V_49 ;
char V_50 ;
if ( V_46 == 0 )
return 0 ;
F_8 ( V_51 , & V_28 -> V_8 ) ;
for ( V_49 = 0 ; V_49 != V_46 ; V_49 ++ ) {
if ( F_27 ( V_50 , V_45 + V_49 ) )
return - V_52 ;
if ( V_50 == 'V' )
F_4 ( V_51 , & V_28 -> V_8 ) ;
}
V_3 = - V_53 ;
F_16 ( & V_28 -> V_29 ) ;
V_2 = V_28 -> V_2 ;
if ( V_2 )
V_3 = F_1 ( V_2 ) ;
F_17 ( & V_28 -> V_29 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_46 ;
}
static long F_28 ( struct V_44 * V_44 , unsigned int V_40 ,
unsigned long V_41 )
{
struct V_27 * V_28 = V_44 -> V_48 ;
void T_3 * V_54 = ( void T_3 * ) V_41 ;
struct V_1 * V_2 ;
int T_3 * V_55 = V_54 ;
unsigned int V_31 ;
int V_3 ;
F_16 ( & V_28 -> V_29 ) ;
V_2 = V_28 -> V_2 ;
if ( ! V_2 ) {
V_3 = - V_53 ;
goto V_56;
}
V_3 = F_25 ( V_2 , V_40 , V_41 ) ;
if ( V_3 != - V_43 )
goto V_56;
switch ( V_40 ) {
case V_57 :
V_3 = F_29 ( V_54 , V_2 -> V_15 ,
sizeof( struct V_58 ) ) ? - V_52 : 0 ;
break;
case V_59 :
V_31 = F_9 ( V_2 ) ;
V_3 = F_30 ( V_31 , V_55 ) ;
break;
case V_60 :
V_3 = F_30 ( V_2 -> V_30 , V_55 ) ;
break;
case V_61 :
if ( F_27 ( V_31 , V_55 ) ) {
V_3 = - V_52 ;
break;
}
if ( V_31 & V_62 ) {
V_3 = F_5 ( V_2 ) ;
if ( V_3 < 0 )
break;
}
if ( V_31 & V_63 )
V_3 = F_3 ( V_2 ) ;
break;
case V_64 :
if ( ! ( V_2 -> V_15 -> V_16 & V_65 ) ) {
V_3 = - V_18 ;
break;
}
V_3 = F_1 ( V_2 ) ;
break;
case V_66 :
if ( F_27 ( V_31 , V_55 ) ) {
V_3 = - V_52 ;
break;
}
V_3 = F_10 ( V_2 , V_31 ) ;
if ( V_3 < 0 )
break;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
break;
case V_67 :
if ( V_2 -> V_13 == 0 ) {
V_3 = - V_18 ;
break;
}
V_3 = F_30 ( V_2 -> V_13 , V_55 ) ;
break;
case V_68 :
V_3 = F_12 ( V_2 , & V_31 ) ;
if ( V_3 < 0 )
break;
V_3 = F_30 ( V_31 , V_55 ) ;
break;
default:
V_3 = - V_69 ;
break;
}
V_56:
F_17 ( & V_28 -> V_29 ) ;
return V_3 ;
}
static int F_31 ( struct V_70 * V_70 , struct V_44 * V_44 )
{
struct V_27 * V_28 ;
struct V_1 * V_2 ;
int V_3 ;
if ( F_32 ( V_70 ) == V_71 )
V_28 = V_72 ;
else
V_28 = F_24 ( V_70 -> V_73 , struct V_27 ,
V_74 ) ;
if ( F_33 ( V_75 , & V_28 -> V_8 ) )
return - V_11 ;
V_2 = V_28 -> V_2 ;
if ( ! F_34 ( V_2 -> V_4 -> V_76 ) ) {
V_3 = - V_11 ;
goto V_77;
}
V_3 = F_3 ( V_2 ) ;
if ( V_3 < 0 )
goto V_78;
V_44 -> V_48 = V_28 ;
F_35 ( & V_28 -> V_79 ) ;
return F_36 ( V_70 , V_44 ) ;
V_78:
F_37 ( V_28 -> V_2 -> V_4 -> V_76 ) ;
V_77:
F_8 ( V_75 , & V_28 -> V_8 ) ;
return V_3 ;
}
static void F_38 ( struct V_79 * V_79 )
{
struct V_27 * V_28 ;
V_28 = F_24 ( V_79 , struct V_27 , V_79 ) ;
F_39 ( V_28 ) ;
}
static int F_40 ( struct V_70 * V_70 , struct V_44 * V_44 )
{
struct V_27 * V_28 = V_44 -> V_48 ;
struct V_1 * V_2 ;
int V_3 = - V_11 ;
F_16 ( & V_28 -> V_29 ) ;
V_2 = V_28 -> V_2 ;
if ( ! V_2 )
goto V_80;
if ( ! F_6 ( V_7 , & V_2 -> V_8 ) )
V_3 = 0 ;
else if ( F_41 ( V_51 , & V_28 -> V_8 ) ||
! ( V_2 -> V_15 -> V_16 & V_81 ) )
V_3 = F_5 ( V_2 ) ;
if ( V_3 < 0 ) {
F_42 ( L_7 , V_2 -> V_10 ) ;
F_1 ( V_2 ) ;
}
F_8 ( V_75 , & V_28 -> V_8 ) ;
V_80:
F_17 ( & V_28 -> V_29 ) ;
F_37 ( V_28 -> V_74 . V_76 ) ;
F_43 ( & V_28 -> V_79 , F_38 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , T_6 V_82 )
{
struct V_27 * V_28 ;
int V_3 ;
V_28 = F_45 ( sizeof( struct V_27 ) , V_83 ) ;
if ( ! V_28 )
return - V_84 ;
F_46 ( & V_28 -> V_79 ) ;
F_47 ( & V_28 -> V_29 ) ;
V_28 -> V_2 = V_2 ;
V_2 -> V_28 = V_28 ;
if ( V_2 -> V_10 == 0 ) {
V_72 = V_28 ;
V_85 . V_86 = V_2 -> V_86 ;
V_3 = F_48 ( & V_85 ) ;
if ( V_3 != 0 ) {
F_49 ( L_8 ,
V_2 -> V_15 -> V_32 , V_87 , V_3 ) ;
if ( V_3 == - V_11 )
F_49 ( L_9 ,
V_2 -> V_15 -> V_32 ) ;
V_72 = NULL ;
F_39 ( V_28 ) ;
return V_3 ;
}
}
F_50 ( & V_28 -> V_74 , & V_88 ) ;
V_28 -> V_74 . V_76 = V_2 -> V_4 -> V_76 ;
V_3 = F_51 ( & V_28 -> V_74 , V_82 , 1 ) ;
if ( V_3 ) {
F_49 ( L_10 ,
V_2 -> V_10 , F_52 ( V_89 ) , V_2 -> V_10 ) ;
if ( V_2 -> V_10 == 0 ) {
F_53 ( & V_85 ) ;
V_72 = NULL ;
F_43 ( & V_28 -> V_79 , F_38 ) ;
}
}
return V_3 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
F_55 ( & V_28 -> V_74 ) ;
if ( V_2 -> V_10 == 0 ) {
F_53 ( & V_85 ) ;
V_72 = NULL ;
}
F_16 ( & V_28 -> V_29 ) ;
V_28 -> V_2 = NULL ;
V_2 -> V_28 = NULL ;
F_17 ( & V_28 -> V_29 ) ;
F_43 ( & V_28 -> V_79 , F_38 ) ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
T_6 V_82 ;
int V_90 ;
V_82 = F_57 ( F_52 ( V_89 ) , V_2 -> V_10 ) ;
V_90 = F_44 ( V_2 , V_82 ) ;
if ( V_90 )
return V_90 ;
V_23 = F_58 ( & V_91 , V_2 -> V_86 ,
V_82 , V_2 , V_2 -> V_92 ,
L_11 , V_2 -> V_10 ) ;
if ( F_59 ( V_23 ) ) {
F_54 ( V_2 ) ;
return F_60 ( V_23 ) ;
}
return V_90 ;
}
void F_61 ( struct V_1 * V_2 )
{
F_62 ( & V_91 , V_2 -> V_28 -> V_74 . V_23 ) ;
F_54 ( V_2 ) ;
}
int T_7 F_63 ( void )
{
int V_3 ;
V_3 = F_64 ( & V_91 ) ;
if ( V_3 < 0 ) {
F_49 ( L_12 ) ;
return V_3 ;
}
V_3 = F_65 ( & V_89 , 0 , V_93 , L_13 ) ;
if ( V_3 < 0 ) {
F_49 ( L_14 ) ;
F_66 ( & V_91 ) ;
return V_3 ;
}
return 0 ;
}
void T_8 F_67 ( void )
{
F_68 ( V_89 , V_93 ) ;
F_66 ( & V_91 ) ;
}

static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
F_2 ( & V_2 -> V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) ) {
V_3 = - V_7 ;
goto V_8;
}
if ( ! F_4 ( V_2 ) )
goto V_8;
if ( V_2 -> V_9 -> V_10 )
V_3 = V_2 -> V_9 -> V_10 ( V_2 ) ;
else
V_3 = V_2 -> V_9 -> V_11 ( V_2 ) ;
V_8:
F_5 ( & V_2 -> V_4 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
F_2 ( & V_2 -> V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) ) {
V_3 = - V_7 ;
goto V_12;
}
if ( F_4 ( V_2 ) )
goto V_12;
V_3 = V_2 -> V_9 -> V_11 ( V_2 ) ;
if ( V_3 == 0 )
F_7 ( V_13 , & V_2 -> V_6 ) ;
V_12:
F_5 ( & V_2 -> V_4 ) ;
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
F_2 ( & V_2 -> V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) ) {
V_3 = - V_7 ;
goto V_14;
}
if ( ! F_4 ( V_2 ) )
goto V_14;
if ( F_3 ( V_15 , & V_2 -> V_6 ) ) {
F_9 ( V_2 -> V_16 , L_1 ) ;
V_3 = - V_17 ;
goto V_14;
}
V_3 = V_2 -> V_9 -> V_18 ( V_2 ) ;
if ( V_3 == 0 )
F_10 ( V_13 , & V_2 -> V_6 ) ;
V_14:
F_5 ( & V_2 -> V_4 ) ;
return V_3 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int * V_6 )
{
int V_3 = 0 ;
* V_6 = 0 ;
if ( ! V_2 -> V_9 -> V_6 )
return - V_19 ;
F_2 ( & V_2 -> V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) ) {
V_3 = - V_7 ;
goto V_20;
}
* V_6 = V_2 -> V_9 -> V_6 ( V_2 ) ;
V_20:
F_5 ( & V_2 -> V_4 ) ;
return V_3 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
int V_3 ;
if ( ( V_2 -> V_9 -> V_22 == NULL ) ||
! ( V_2 -> V_23 -> V_24 & V_25 ) )
return - V_19 ;
if ( F_13 ( V_2 , V_21 ) )
return - V_26 ;
F_2 ( & V_2 -> V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) ) {
V_3 = - V_7 ;
goto V_27;
}
V_3 = V_2 -> V_9 -> V_22 ( V_2 , V_21 ) ;
V_27:
F_5 ( & V_2 -> V_4 ) ;
return V_3 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned int * V_28 )
{
int V_3 = 0 ;
* V_28 = 0 ;
if ( ! V_2 -> V_9 -> V_29 )
return - V_19 ;
F_2 ( & V_2 -> V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) ) {
V_3 = - V_7 ;
goto V_30;
}
* V_28 = V_2 -> V_9 -> V_29 ( V_2 ) ;
V_30:
F_5 ( & V_2 -> V_4 ) ;
return V_3 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_31 ,
unsigned long V_32 )
{
int V_3 ;
if ( ! V_2 -> V_9 -> V_33 )
return - V_34 ;
F_2 ( & V_2 -> V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) ) {
V_3 = - V_7 ;
goto V_35;
}
V_3 = V_2 -> V_9 -> V_33 ( V_2 , V_31 , V_32 ) ;
V_35:
F_5 ( & V_2 -> V_4 ) ;
return V_3 ;
}
static T_1 F_16 ( struct V_36 * V_36 , const char T_2 * V_37 ,
T_3 V_38 , T_4 * V_39 )
{
struct V_1 * V_40 = V_36 -> V_41 ;
T_3 V_42 ;
char V_43 ;
if ( V_38 == 0 )
return 0 ;
F_10 ( V_44 , & V_40 -> V_6 ) ;
for ( V_42 = 0 ; V_42 != V_38 ; V_42 ++ ) {
if ( F_17 ( V_43 , V_37 + V_42 ) )
return - V_45 ;
if ( V_43 == 'V' )
F_7 ( V_44 , & V_40 -> V_6 ) ;
}
F_1 ( V_40 ) ;
return V_38 ;
}
static long F_18 ( struct V_36 * V_36 , unsigned int V_31 ,
unsigned long V_32 )
{
struct V_1 * V_40 = V_36 -> V_41 ;
void T_2 * V_46 = ( void T_2 * ) V_32 ;
int T_2 * V_47 = V_46 ;
unsigned int V_48 ;
int V_3 ;
V_3 = F_15 ( V_40 , V_31 , V_32 ) ;
if ( V_3 != - V_34 )
return V_3 ;
switch ( V_31 ) {
case V_49 :
return F_19 ( V_46 , V_40 -> V_23 ,
sizeof( struct V_50 ) ) ? - V_45 : 0 ;
case V_51 :
V_3 = F_11 ( V_40 , & V_48 ) ;
if ( V_3 == - V_7 )
return V_3 ;
return F_20 ( V_48 , V_47 ) ;
case V_52 :
return F_20 ( V_40 -> V_53 , V_47 ) ;
case V_54 :
if ( F_17 ( V_48 , V_47 ) )
return - V_45 ;
if ( V_48 & V_55 ) {
V_3 = F_8 ( V_40 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_48 & V_56 ) {
V_3 = F_6 ( V_40 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return 0 ;
case V_57 :
if ( ! ( V_40 -> V_23 -> V_24 & V_58 ) )
return - V_19 ;
F_1 ( V_40 ) ;
return 0 ;
case V_59 :
if ( F_17 ( V_48 , V_47 ) )
return - V_45 ;
V_3 = F_12 ( V_40 , V_48 ) ;
if ( V_3 < 0 )
return V_3 ;
F_1 ( V_40 ) ;
case V_60 :
if ( V_40 -> V_21 == 0 )
return - V_19 ;
return F_20 ( V_40 -> V_21 , V_47 ) ;
case V_61 :
V_3 = F_14 ( V_40 , & V_48 ) ;
if ( V_3 )
return V_3 ;
return F_20 ( V_48 , V_47 ) ;
default:
return - V_62 ;
}
}
static int F_21 ( struct V_63 * V_63 , struct V_36 * V_36 )
{
int V_3 = - V_17 ;
struct V_1 * V_40 ;
if ( F_22 ( V_63 ) == V_64 )
V_40 = V_65 ;
else
V_40 = F_23 ( V_63 -> V_66 , struct V_1 , V_67 ) ;
if ( F_24 ( V_68 , & V_40 -> V_6 ) )
return - V_17 ;
if ( ! F_25 ( V_40 -> V_9 -> V_69 ) )
goto V_70;
V_3 = F_6 ( V_40 ) ;
if ( V_3 < 0 )
goto V_71;
V_36 -> V_41 = V_40 ;
if ( V_40 -> V_9 -> V_72 )
V_40 -> V_9 -> V_72 ( V_40 ) ;
return F_26 ( V_63 , V_36 ) ;
V_71:
F_27 ( V_40 -> V_9 -> V_69 ) ;
V_70:
F_10 ( V_68 , & V_40 -> V_6 ) ;
return V_3 ;
}
static int F_28 ( struct V_63 * V_63 , struct V_36 * V_36 )
{
struct V_1 * V_40 = V_36 -> V_41 ;
int V_3 = - V_17 ;
if ( F_29 ( V_44 , & V_40 -> V_6 ) ||
! ( V_40 -> V_23 -> V_24 & V_73 ) )
V_3 = F_8 ( V_40 ) ;
if ( V_3 < 0 ) {
F_2 ( & V_40 -> V_4 ) ;
if ( ! F_3 ( V_5 , & V_40 -> V_6 ) )
F_30 ( V_40 -> V_16 , L_2 ) ;
F_5 ( & V_40 -> V_4 ) ;
F_1 ( V_40 ) ;
}
F_27 ( V_40 -> V_9 -> V_69 ) ;
F_10 ( V_68 , & V_40 -> V_6 ) ;
if ( V_40 -> V_9 -> V_74 )
V_40 -> V_9 -> V_74 ( V_40 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_75 )
{
int V_3 , V_76 ;
if ( V_75 -> V_77 == 0 ) {
V_65 = V_75 ;
V_78 . V_79 = V_75 -> V_79 ;
V_3 = F_32 ( & V_78 ) ;
if ( V_3 != 0 ) {
F_33 ( L_3 ,
V_75 -> V_23 -> V_80 , V_81 , V_3 ) ;
if ( V_3 == - V_17 )
F_33 ( L_4 ,
V_75 -> V_23 -> V_80 ) ;
V_65 = NULL ;
return V_3 ;
}
}
V_76 = F_34 ( F_35 ( V_82 ) , V_75 -> V_77 ) ;
F_36 ( & V_75 -> V_67 , & V_83 ) ;
V_75 -> V_67 . V_69 = V_75 -> V_9 -> V_69 ;
V_3 = F_37 ( & V_75 -> V_67 , V_76 , 1 ) ;
if ( V_3 ) {
F_33 ( L_5 ,
V_75 -> V_77 , F_35 ( V_82 ) , V_75 -> V_77 ) ;
if ( V_75 -> V_77 == 0 ) {
F_38 ( & V_78 ) ;
V_65 = NULL ;
}
}
return V_3 ;
}
int F_39 ( struct V_1 * V_75 )
{
F_2 ( & V_75 -> V_4 ) ;
F_7 ( V_5 , & V_75 -> V_6 ) ;
F_5 ( & V_75 -> V_4 ) ;
F_40 ( & V_75 -> V_67 ) ;
if ( V_75 -> V_77 == 0 ) {
F_38 ( & V_78 ) ;
V_65 = NULL ;
}
return 0 ;
}
int T_5 F_41 ( void )
{
int V_3 = F_42 ( & V_82 , 0 , V_84 , L_6 ) ;
if ( V_3 < 0 )
F_33 ( L_7 ) ;
return V_3 ;
}
void T_6 F_43 ( void )
{
F_44 ( V_82 , V_84 ) ;
}

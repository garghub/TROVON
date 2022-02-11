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
if ( ! V_2 -> V_9 -> V_22 || ! ( V_2 -> V_23 -> V_24 & V_25 ) )
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
struct V_1 * V_2 = V_36 -> V_40 ;
T_3 V_41 ;
char V_42 ;
int V_3 ;
if ( V_38 == 0 )
return 0 ;
F_10 ( V_43 , & V_2 -> V_6 ) ;
for ( V_41 = 0 ; V_41 != V_38 ; V_41 ++ ) {
if ( F_17 ( V_42 , V_37 + V_41 ) )
return - V_44 ;
if ( V_42 == 'V' )
F_7 ( V_43 , & V_2 -> V_6 ) ;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_38 ;
}
static long F_18 ( struct V_36 * V_36 , unsigned int V_31 ,
unsigned long V_32 )
{
struct V_1 * V_2 = V_36 -> V_40 ;
void T_2 * V_45 = ( void T_2 * ) V_32 ;
int T_2 * V_46 = V_45 ;
unsigned int V_47 ;
int V_3 ;
V_3 = F_15 ( V_2 , V_31 , V_32 ) ;
if ( V_3 != - V_34 )
return V_3 ;
switch ( V_31 ) {
case V_48 :
return F_19 ( V_45 , V_2 -> V_23 ,
sizeof( struct V_49 ) ) ? - V_44 : 0 ;
case V_50 :
V_3 = F_11 ( V_2 , & V_47 ) ;
if ( V_3 == - V_7 )
return V_3 ;
return F_20 ( V_47 , V_46 ) ;
case V_51 :
return F_20 ( V_2 -> V_52 , V_46 ) ;
case V_53 :
if ( F_17 ( V_47 , V_46 ) )
return - V_44 ;
if ( V_47 & V_54 ) {
V_3 = F_8 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_47 & V_55 ) {
V_3 = F_6 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return 0 ;
case V_56 :
if ( ! ( V_2 -> V_23 -> V_24 & V_57 ) )
return - V_19 ;
return F_1 ( V_2 ) ;
case V_58 :
if ( F_17 ( V_47 , V_46 ) )
return - V_44 ;
V_3 = F_12 ( V_2 , V_47 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
case V_59 :
if ( V_2 -> V_21 == 0 )
return - V_19 ;
return F_20 ( V_2 -> V_21 , V_46 ) ;
case V_60 :
V_3 = F_14 ( V_2 , & V_47 ) ;
if ( V_3 )
return V_3 ;
return F_20 ( V_47 , V_46 ) ;
default:
return - V_61 ;
}
}
static int F_21 ( struct V_62 * V_62 , struct V_36 * V_36 )
{
int V_3 = - V_17 ;
struct V_1 * V_2 ;
if ( F_22 ( V_62 ) == V_63 )
V_2 = V_64 ;
else
V_2 = F_23 ( V_62 -> V_65 , struct V_1 , V_66 ) ;
if ( F_24 ( V_67 , & V_2 -> V_6 ) )
return - V_17 ;
if ( ! F_25 ( V_2 -> V_9 -> V_68 ) )
goto V_69;
V_3 = F_6 ( V_2 ) ;
if ( V_3 < 0 )
goto V_70;
V_36 -> V_40 = V_2 ;
if ( V_2 -> V_9 -> V_71 )
V_2 -> V_9 -> V_71 ( V_2 ) ;
return F_26 ( V_62 , V_36 ) ;
V_70:
F_27 ( V_2 -> V_9 -> V_68 ) ;
V_69:
F_10 ( V_67 , & V_2 -> V_6 ) ;
return V_3 ;
}
static int F_28 ( struct V_62 * V_62 , struct V_36 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_40 ;
int V_3 = - V_17 ;
if ( ! F_3 ( V_13 , & V_2 -> V_6 ) )
V_3 = 0 ;
else if ( F_29 ( V_43 , & V_2 -> V_6 ) ||
! ( V_2 -> V_23 -> V_24 & V_72 ) )
V_3 = F_8 ( V_2 ) ;
if ( V_3 < 0 ) {
F_2 ( & V_2 -> V_4 ) ;
if ( ! F_3 ( V_5 , & V_2 -> V_6 ) )
F_30 ( V_2 -> V_16 , L_2 ) ;
F_5 ( & V_2 -> V_4 ) ;
F_1 ( V_2 ) ;
}
F_27 ( V_2 -> V_9 -> V_68 ) ;
F_10 ( V_67 , & V_2 -> V_6 ) ;
if ( V_2 -> V_9 -> V_73 )
V_2 -> V_9 -> V_73 ( V_2 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_3 , V_74 ;
if ( V_2 -> V_75 == 0 ) {
V_64 = V_2 ;
V_76 . V_77 = V_2 -> V_77 ;
V_3 = F_32 ( & V_76 ) ;
if ( V_3 != 0 ) {
F_33 ( L_3 ,
V_2 -> V_23 -> V_78 , V_79 , V_3 ) ;
if ( V_3 == - V_17 )
F_33 ( L_4 ,
V_2 -> V_23 -> V_78 ) ;
V_64 = NULL ;
return V_3 ;
}
}
V_74 = F_34 ( F_35 ( V_80 ) , V_2 -> V_75 ) ;
F_36 ( & V_2 -> V_66 , & V_81 ) ;
V_2 -> V_66 . V_68 = V_2 -> V_9 -> V_68 ;
V_3 = F_37 ( & V_2 -> V_66 , V_74 , 1 ) ;
if ( V_3 ) {
F_33 ( L_5 ,
V_2 -> V_75 , F_35 ( V_80 ) , V_2 -> V_75 ) ;
if ( V_2 -> V_75 == 0 ) {
F_38 ( & V_76 ) ;
V_64 = NULL ;
}
}
return V_3 ;
}
int F_39 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_4 ) ;
F_7 ( V_5 , & V_2 -> V_6 ) ;
F_5 ( & V_2 -> V_4 ) ;
F_40 ( & V_2 -> V_66 ) ;
if ( V_2 -> V_75 == 0 ) {
F_38 ( & V_76 ) ;
V_64 = NULL ;
}
return 0 ;
}
int T_5 F_41 ( void )
{
int V_3 = F_42 ( & V_80 , 0 , V_82 , L_6 ) ;
if ( V_3 < 0 )
F_33 ( L_7 ) ;
return V_3 ;
}
void T_6 F_43 ( void )
{
F_44 ( V_80 , V_82 ) ;
}

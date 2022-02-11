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
if ( ( V_2 -> V_26 != 0 ) &&
( V_21 < V_2 -> V_27 || V_21 > V_2 -> V_26 ) )
return - V_28 ;
F_2 ( & V_2 -> V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) ) {
V_3 = - V_7 ;
goto V_29;
}
V_3 = V_2 -> V_9 -> V_22 ( V_2 , V_21 ) ;
V_29:
F_5 ( & V_2 -> V_4 ) ;
return V_3 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned int * V_30 )
{
int V_3 = 0 ;
* V_30 = 0 ;
if ( ! V_2 -> V_9 -> V_31 )
return - V_19 ;
F_2 ( & V_2 -> V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) ) {
V_3 = - V_7 ;
goto V_32;
}
* V_30 = V_2 -> V_9 -> V_31 ( V_2 ) ;
V_32:
F_5 ( & V_2 -> V_4 ) ;
return V_3 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_33 ,
unsigned long V_34 )
{
int V_3 ;
if ( ! V_2 -> V_9 -> V_35 )
return - V_36 ;
F_2 ( & V_2 -> V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) ) {
V_3 = - V_7 ;
goto V_37;
}
V_3 = V_2 -> V_9 -> V_35 ( V_2 , V_33 , V_34 ) ;
V_37:
F_5 ( & V_2 -> V_4 ) ;
return V_3 ;
}
static T_1 F_15 ( struct V_38 * V_38 , const char T_2 * V_39 ,
T_3 V_40 , T_4 * V_41 )
{
struct V_1 * V_42 = V_38 -> V_43 ;
T_3 V_44 ;
char V_45 ;
if ( V_40 == 0 )
return 0 ;
F_10 ( V_46 , & V_42 -> V_6 ) ;
for ( V_44 = 0 ; V_44 != V_40 ; V_44 ++ ) {
if ( F_16 ( V_45 , V_39 + V_44 ) )
return - V_47 ;
if ( V_45 == 'V' )
F_7 ( V_46 , & V_42 -> V_6 ) ;
}
F_1 ( V_42 ) ;
return V_40 ;
}
static long F_17 ( struct V_38 * V_38 , unsigned int V_33 ,
unsigned long V_34 )
{
struct V_1 * V_42 = V_38 -> V_43 ;
void T_2 * V_48 = ( void T_2 * ) V_34 ;
int T_2 * V_49 = V_48 ;
unsigned int V_50 ;
int V_3 ;
V_3 = F_14 ( V_42 , V_33 , V_34 ) ;
if ( V_3 != - V_36 )
return V_3 ;
switch ( V_33 ) {
case V_51 :
return F_18 ( V_48 , V_42 -> V_23 ,
sizeof( struct V_52 ) ) ? - V_47 : 0 ;
case V_53 :
V_3 = F_11 ( V_42 , & V_50 ) ;
if ( V_3 == - V_7 )
return V_3 ;
return F_19 ( V_50 , V_49 ) ;
case V_54 :
return F_19 ( V_42 -> V_55 , V_49 ) ;
case V_56 :
if ( F_16 ( V_50 , V_49 ) )
return - V_47 ;
if ( V_50 & V_57 ) {
V_3 = F_8 ( V_42 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_50 & V_58 ) {
V_3 = F_6 ( V_42 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return 0 ;
case V_59 :
if ( ! ( V_42 -> V_23 -> V_24 & V_60 ) )
return - V_19 ;
F_1 ( V_42 ) ;
return 0 ;
case V_61 :
if ( F_16 ( V_50 , V_49 ) )
return - V_47 ;
V_3 = F_12 ( V_42 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
F_1 ( V_42 ) ;
case V_62 :
if ( V_42 -> V_21 == 0 )
return - V_19 ;
return F_19 ( V_42 -> V_21 , V_49 ) ;
case V_63 :
V_3 = F_13 ( V_42 , & V_50 ) ;
if ( V_3 )
return V_3 ;
return F_19 ( V_50 , V_49 ) ;
default:
return - V_64 ;
}
}
static int F_20 ( struct V_65 * V_65 , struct V_38 * V_38 )
{
int V_3 = - V_17 ;
struct V_1 * V_42 ;
if ( F_21 ( V_65 ) == V_66 )
V_42 = V_67 ;
else
V_42 = F_22 ( V_65 -> V_68 , struct V_1 , V_69 ) ;
if ( F_23 ( V_70 , & V_42 -> V_6 ) )
return - V_17 ;
if ( ! F_24 ( V_42 -> V_9 -> V_71 ) )
goto V_72;
V_3 = F_6 ( V_42 ) ;
if ( V_3 < 0 )
goto V_73;
V_38 -> V_43 = V_42 ;
if ( V_42 -> V_9 -> V_74 )
V_42 -> V_9 -> V_74 ( V_42 ) ;
return F_25 ( V_65 , V_38 ) ;
V_73:
F_26 ( V_42 -> V_9 -> V_71 ) ;
V_72:
F_10 ( V_70 , & V_42 -> V_6 ) ;
return V_3 ;
}
static int F_27 ( struct V_65 * V_65 , struct V_38 * V_38 )
{
struct V_1 * V_42 = V_38 -> V_43 ;
int V_3 = - V_17 ;
if ( F_28 ( V_46 , & V_42 -> V_6 ) ||
! ( V_42 -> V_23 -> V_24 & V_75 ) )
V_3 = F_8 ( V_42 ) ;
if ( V_3 < 0 ) {
F_2 ( & V_42 -> V_4 ) ;
if ( ! F_3 ( V_5 , & V_42 -> V_6 ) )
F_29 ( V_42 -> V_16 , L_2 ) ;
F_5 ( & V_42 -> V_4 ) ;
F_1 ( V_42 ) ;
}
F_26 ( V_42 -> V_9 -> V_71 ) ;
F_10 ( V_70 , & V_42 -> V_6 ) ;
if ( V_42 -> V_9 -> V_76 )
V_42 -> V_9 -> V_76 ( V_42 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_77 )
{
int V_3 , V_78 ;
if ( V_77 -> V_79 == 0 ) {
V_80 . V_81 = V_77 -> V_81 ;
V_3 = F_31 ( & V_80 ) ;
if ( V_3 != 0 ) {
F_32 ( L_3 ,
V_77 -> V_23 -> V_82 , V_83 , V_3 ) ;
if ( V_3 == - V_17 )
F_32 ( L_4 ,
V_77 -> V_23 -> V_82 ) ;
return V_3 ;
}
V_67 = V_77 ;
}
V_78 = F_33 ( F_34 ( V_84 ) , V_77 -> V_79 ) ;
F_35 ( & V_77 -> V_69 , & V_85 ) ;
V_77 -> V_69 . V_71 = V_77 -> V_9 -> V_71 ;
V_3 = F_36 ( & V_77 -> V_69 , V_78 , 1 ) ;
if ( V_3 ) {
F_32 ( L_5 ,
V_77 -> V_79 , F_34 ( V_84 ) , V_77 -> V_79 ) ;
if ( V_77 -> V_79 == 0 ) {
F_37 ( & V_80 ) ;
V_67 = NULL ;
}
}
return V_3 ;
}
int F_38 ( struct V_1 * V_77 )
{
F_2 ( & V_77 -> V_4 ) ;
F_7 ( V_5 , & V_77 -> V_6 ) ;
F_5 ( & V_77 -> V_4 ) ;
F_39 ( & V_77 -> V_69 ) ;
if ( V_77 -> V_79 == 0 ) {
F_37 ( & V_80 ) ;
V_67 = NULL ;
}
return 0 ;
}
int T_5 F_40 ( void )
{
int V_3 = F_41 ( & V_84 , 0 , V_86 , L_6 ) ;
if ( V_3 < 0 )
F_32 ( L_7 ) ;
return V_3 ;
}
void T_6 F_42 ( void )
{
F_43 ( V_84 , V_86 ) ;
}

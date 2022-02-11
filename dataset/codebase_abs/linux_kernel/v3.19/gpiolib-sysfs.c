static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 ;
F_3 ( & V_9 ) ;
if ( ! F_4 ( V_10 , & V_7 -> V_11 ) ) {
V_8 = - V_12 ;
} else {
F_5 ( V_7 ) ;
V_8 = sprintf ( V_5 , L_1 ,
F_4 ( V_13 , & V_7 -> V_11 )
? L_2 : L_3 ) ;
}
F_6 ( & V_9 ) ;
return V_8 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 ;
F_3 ( & V_9 ) ;
if ( ! F_4 ( V_10 , & V_7 -> V_11 ) )
V_8 = - V_12 ;
else if ( F_8 ( V_5 , L_4 ) )
V_8 = F_9 ( V_7 , 1 ) ;
else if ( F_8 ( V_5 , L_2 ) || F_8 ( V_5 , L_5 ) )
V_8 = F_9 ( V_7 , 0 ) ;
else if ( F_8 ( V_5 , L_3 ) )
V_8 = F_10 ( V_7 ) ;
else
V_8 = - V_15 ;
F_6 ( & V_9 ) ;
return V_8 ? : V_14 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 ;
F_3 ( & V_9 ) ;
if ( ! F_4 ( V_10 , & V_7 -> V_11 ) )
V_8 = - V_12 ;
else
V_8 = sprintf ( V_5 , L_6 , F_12 ( V_7 ) ) ;
F_6 ( & V_9 ) ;
return V_8 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 ;
F_3 ( & V_9 ) ;
if ( ! F_4 ( V_10 , & V_7 -> V_11 ) )
V_8 = - V_12 ;
else if ( ! F_4 ( V_13 , & V_7 -> V_11 ) )
V_8 = - V_16 ;
else {
long V_17 ;
V_8 = F_14 ( V_5 , 0 , & V_17 ) ;
if ( V_8 == 0 ) {
F_15 ( V_7 , V_17 ) ;
V_8 = V_14 ;
}
}
F_6 ( & V_9 ) ;
return V_8 ;
}
static T_3 F_16 ( int V_18 , void * V_19 )
{
struct V_20 * V_21 = V_19 ;
F_17 ( V_21 ) ;
return V_22 ;
}
static int F_18 ( struct V_6 * V_7 , struct V_1 * V_2 ,
unsigned long V_23 )
{
struct V_20 * V_21 ;
unsigned long V_24 ;
int V_25 , V_18 , V_26 ;
if ( ( V_7 -> V_11 & V_27 ) == V_23 )
return 0 ;
V_18 = F_19 ( V_7 ) ;
if ( V_18 < 0 )
return - V_12 ;
V_26 = V_7 -> V_11 >> V_28 ;
V_21 = F_20 ( & V_29 , V_26 ) ;
if ( V_21 )
F_21 ( V_18 , V_21 ) ;
V_7 -> V_11 &= ~ V_27 ;
if ( ! V_23 ) {
F_22 ( V_7 -> V_30 , F_23 ( V_7 ) ) ;
V_25 = 0 ;
goto V_31;
}
V_24 = V_32 ;
if ( F_4 ( V_33 , & V_23 ) )
V_24 |= F_4 ( V_34 , & V_7 -> V_11 ) ?
V_35 : V_36 ;
if ( F_4 ( V_37 , & V_23 ) )
V_24 |= F_4 ( V_34 , & V_7 -> V_11 ) ?
V_36 : V_35 ;
if ( ! V_21 ) {
V_21 = F_24 ( V_2 -> V_38 . V_39 , L_7 ) ;
if ( ! V_21 ) {
V_25 = - V_40 ;
goto V_41;
}
V_25 = F_25 ( & V_29 , V_21 , 1 , 0 , V_42 ) ;
if ( V_25 < 0 )
goto V_43;
V_26 = V_25 ;
V_7 -> V_11 &= V_44 ;
V_7 -> V_11 |= ( unsigned long ) V_26 << V_28 ;
if ( V_7 -> V_11 >> V_28 != V_26 ) {
V_25 = - V_45 ;
goto V_31;
}
}
V_25 = F_26 ( V_18 , F_16 , V_24 ,
L_8 , V_21 ) ;
if ( V_25 < 0 )
goto V_31;
V_25 = F_27 ( V_7 -> V_30 , F_23 ( V_7 ) ) ;
if ( V_25 < 0 ) {
F_28 ( V_7 , L_9 ) ;
goto V_31;
}
V_7 -> V_11 |= V_23 ;
return 0 ;
V_31:
F_29 ( & V_29 , V_26 ) ;
V_7 -> V_11 &= V_44 ;
V_43:
if ( V_21 )
F_30 ( V_21 ) ;
V_41:
return V_25 ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 ;
F_3 ( & V_9 ) ;
if ( ! F_4 ( V_10 , & V_7 -> V_11 ) )
V_8 = - V_12 ;
else {
int V_46 ;
V_8 = 0 ;
for ( V_46 = 0 ; V_46 < F_32 ( V_47 ) ; V_46 ++ )
if ( ( V_7 -> V_11 & V_27 )
== V_47 [ V_46 ] . V_11 ) {
V_8 = sprintf ( V_5 , L_1 ,
V_47 [ V_46 ] . V_48 ) ;
break;
}
}
F_6 ( & V_9 ) ;
return V_8 ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_32 ( V_47 ) ; V_46 ++ )
if ( F_8 ( V_47 [ V_46 ] . V_48 , V_5 ) )
goto V_49;
return - V_15 ;
V_49:
F_3 ( & V_9 ) ;
if ( ! F_4 ( V_10 , & V_7 -> V_11 ) )
V_8 = - V_12 ;
else {
V_8 = F_18 ( V_7 , V_2 , V_47 [ V_46 ] . V_11 ) ;
if ( ! V_8 )
V_8 = V_14 ;
}
F_6 ( & V_9 ) ;
return V_8 ;
}
static int F_34 ( struct V_6 * V_7 , struct V_1 * V_2 ,
int V_17 )
{
int V_8 = 0 ;
if ( ! ! F_4 ( V_34 , & V_7 -> V_11 ) == ! ! V_17 )
return 0 ;
if ( V_17 )
F_35 ( V_34 , & V_7 -> V_11 ) ;
else
F_36 ( V_34 , & V_7 -> V_11 ) ;
if ( V_2 != NULL && ( ! ! F_4 ( V_37 , & V_7 -> V_11 ) ^
! ! F_4 ( V_33 , & V_7 -> V_11 ) ) ) {
unsigned long V_50 = V_7 -> V_11 & V_27 ;
F_18 ( V_7 , V_2 , 0 ) ;
V_8 = F_18 ( V_7 , V_2 , V_50 ) ;
}
return V_8 ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 ;
F_3 ( & V_9 ) ;
if ( ! F_4 ( V_10 , & V_7 -> V_11 ) )
V_8 = - V_12 ;
else
V_8 = sprintf ( V_5 , L_6 ,
! ! F_4 ( V_34 , & V_7 -> V_11 ) ) ;
F_6 ( & V_9 ) ;
return V_8 ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 ;
F_3 ( & V_9 ) ;
if ( ! F_4 ( V_10 , & V_7 -> V_11 ) ) {
V_8 = - V_12 ;
} else {
long V_17 ;
V_8 = F_14 ( V_5 , 0 , & V_17 ) ;
if ( V_8 == 0 )
V_8 = F_34 ( V_7 , V_2 , V_17 != 0 ) ;
}
F_6 ( & V_9 ) ;
return V_8 ? : V_14 ;
}
static T_4 F_39 ( struct V_51 * V_38 , struct V_52 * V_4 ,
int V_53 )
{
struct V_1 * V_2 = F_40 ( V_38 , struct V_1 , V_38 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_4 V_54 = V_4 -> V_54 ;
bool V_55 = F_4 ( V_56 , & V_7 -> V_11 ) ;
if ( V_4 == & V_57 . V_4 ) {
if ( ! V_55 )
V_54 = 0 ;
} else if ( V_4 == & V_58 . V_4 ) {
if ( F_19 ( V_7 ) < 0 )
V_54 = 0 ;
if ( ! V_55 && F_4 ( V_13 , & V_7 -> V_11 ) )
V_54 = 0 ;
}
return V_54 ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const struct V_59 * V_30 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_6 , V_30 -> V_60 ) ;
}
static T_1 F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const struct V_59 * V_30 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_30 -> V_61 ? : L_10 ) ;
}
static T_1 F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const struct V_59 * V_30 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_11 , V_30 -> V_62 ) ;
}
static T_1 F_44 ( struct V_63 * V_63 ,
struct V_64 * V_4 ,
const char * V_5 , T_2 V_65 )
{
long V_66 ;
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_14 ( V_5 , 0 , & V_66 ) ;
if ( V_8 < 0 )
goto V_67;
V_7 = F_45 ( V_66 ) ;
if ( ! V_7 ) {
F_46 ( L_12 , V_68 , V_66 ) ;
return - V_15 ;
}
V_8 = F_47 ( V_7 , L_13 ) ;
if ( V_8 < 0 ) {
if ( V_8 == - V_69 )
V_8 = - V_40 ;
goto V_67;
}
V_8 = F_48 ( V_7 , true ) ;
if ( V_8 < 0 )
F_49 ( V_7 ) ;
else
F_35 ( V_70 , & V_7 -> V_11 ) ;
V_67:
if ( V_8 )
F_50 ( L_14 , V_68 , V_8 ) ;
return V_8 ? : V_65 ;
}
static T_1 F_51 ( struct V_63 * V_63 ,
struct V_64 * V_4 ,
const char * V_5 , T_2 V_65 )
{
long V_66 ;
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_14 ( V_5 , 0 , & V_66 ) ;
if ( V_8 < 0 )
goto V_67;
V_7 = F_45 ( V_66 ) ;
if ( ! V_7 ) {
F_46 ( L_12 , V_68 , V_66 ) ;
return - V_15 ;
}
V_8 = - V_15 ;
if ( F_52 ( V_70 , & V_7 -> V_11 ) ) {
V_8 = 0 ;
F_49 ( V_7 ) ;
}
V_67:
if ( V_8 )
F_50 ( L_14 , V_68 , V_8 ) ;
return V_8 ? : V_65 ;
}
int F_48 ( struct V_6 * V_7 , bool V_71 )
{
unsigned long V_11 ;
int V_8 ;
const char * V_72 = NULL ;
struct V_1 * V_2 ;
int V_73 ;
if ( ! V_74 . V_75 ) {
F_50 ( L_15 , V_68 ) ;
return - V_76 ;
}
if ( ! V_7 ) {
F_50 ( L_16 , V_68 ) ;
return - V_15 ;
}
F_3 ( & V_9 ) ;
F_53 ( & V_77 , V_11 ) ;
if ( ! F_4 ( V_78 , & V_7 -> V_11 ) ||
F_4 ( V_10 , & V_7 -> V_11 ) ) {
F_54 ( & V_77 , V_11 ) ;
F_55 ( V_7 , L_17 ,
V_68 ,
F_4 ( V_78 , & V_7 -> V_11 ) ,
F_4 ( V_10 , & V_7 -> V_11 ) ) ;
V_8 = - V_16 ;
goto V_79;
}
if ( V_7 -> V_30 -> V_80 && V_7 -> V_30 -> V_81 &&
V_71 ) {
F_35 ( V_56 , & V_7 -> V_11 ) ;
}
F_54 ( & V_77 , V_11 ) ;
V_73 = F_23 ( V_7 ) ;
if ( V_7 -> V_30 -> V_82 && V_7 -> V_30 -> V_82 [ V_73 ] )
V_72 = V_7 -> V_30 -> V_82 [ V_73 ] ;
V_2 = F_56 ( & V_74 , V_7 -> V_30 -> V_2 ,
F_57 ( 0 , 0 ) , V_7 , V_83 ,
V_72 ? V_72 : L_18 ,
F_58 ( V_7 ) ) ;
if ( F_59 ( V_2 ) ) {
V_8 = F_60 ( V_2 ) ;
goto V_79;
}
F_35 ( V_10 , & V_7 -> V_11 ) ;
F_6 ( & V_9 ) ;
return 0 ;
V_79:
F_6 ( & V_9 ) ;
F_55 ( V_7 , L_14 , V_68 , V_8 ) ;
return V_8 ;
}
static int F_61 ( struct V_1 * V_2 , const void * V_84 )
{
return F_2 ( V_2 ) == V_84 ;
}
int F_62 ( struct V_1 * V_2 , const char * V_48 ,
struct V_6 * V_7 )
{
int V_8 = - V_15 ;
if ( ! V_7 ) {
F_46 ( L_19 , V_68 ) ;
return - V_15 ;
}
F_3 ( & V_9 ) ;
if ( F_4 ( V_10 , & V_7 -> V_11 ) ) {
struct V_1 * V_85 ;
V_85 = F_63 ( & V_74 , NULL , V_7 , F_61 ) ;
if ( V_85 != NULL ) {
V_8 = F_64 ( & V_2 -> V_38 , & V_85 -> V_38 ,
V_48 ) ;
F_65 ( V_85 ) ;
} else {
V_8 = - V_40 ;
}
}
F_6 ( & V_9 ) ;
if ( V_8 )
F_55 ( V_7 , L_14 , V_68 , V_8 ) ;
return V_8 ;
}
int F_66 ( struct V_6 * V_7 , int V_17 )
{
struct V_1 * V_2 = NULL ;
int V_8 = - V_15 ;
if ( ! V_7 ) {
F_46 ( L_19 , V_68 ) ;
return - V_15 ;
}
F_3 ( & V_9 ) ;
if ( F_4 ( V_10 , & V_7 -> V_11 ) ) {
V_2 = F_63 ( & V_74 , NULL , V_7 , F_61 ) ;
if ( V_2 == NULL ) {
V_8 = - V_40 ;
goto V_86;
}
}
V_8 = F_34 ( V_7 , V_2 , V_17 ) ;
F_65 ( V_2 ) ;
V_86:
F_6 ( & V_9 ) ;
if ( V_8 )
F_55 ( V_7 , L_14 , V_68 , V_8 ) ;
return V_8 ;
}
void F_67 ( struct V_6 * V_7 )
{
int V_8 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_7 ) {
F_46 ( L_19 , V_68 ) ;
return;
}
F_3 ( & V_9 ) ;
if ( F_4 ( V_10 , & V_7 -> V_11 ) ) {
V_2 = F_63 ( & V_74 , NULL , V_7 , F_61 ) ;
if ( V_2 ) {
F_18 ( V_7 , V_2 , 0 ) ;
F_36 ( V_56 , & V_7 -> V_11 ) ;
F_36 ( V_10 , & V_7 -> V_11 ) ;
} else
V_8 = - V_40 ;
}
F_6 ( & V_9 ) ;
if ( V_2 ) {
F_68 ( V_2 ) ;
F_65 ( V_2 ) ;
}
if ( V_8 )
F_55 ( V_7 , L_14 , V_68 , V_8 ) ;
}
int F_69 ( struct V_59 * V_30 )
{
int V_8 ;
struct V_1 * V_2 ;
if ( ! V_74 . V_75 )
return 0 ;
F_3 ( & V_9 ) ;
V_2 = F_56 ( & V_74 , V_30 -> V_2 , F_57 ( 0 , 0 ) ,
V_30 , V_87 ,
L_20 , V_30 -> V_60 ) ;
if ( F_59 ( V_2 ) )
V_8 = F_60 ( V_2 ) ;
else
V_8 = 0 ;
V_30 -> V_88 = ( V_8 == 0 ) ;
F_6 ( & V_9 ) ;
if ( V_8 )
F_70 ( V_30 , L_14 , V_68 , V_8 ) ;
return V_8 ;
}
void F_71 ( struct V_59 * V_30 )
{
int V_8 ;
struct V_1 * V_2 ;
F_3 ( & V_9 ) ;
V_2 = F_63 ( & V_74 , NULL , V_30 , F_61 ) ;
if ( V_2 ) {
F_65 ( V_2 ) ;
F_68 ( V_2 ) ;
V_30 -> V_88 = false ;
V_8 = 0 ;
} else
V_8 = - V_40 ;
F_6 ( & V_9 ) ;
if ( V_8 )
F_70 ( V_30 , L_14 , V_68 , V_8 ) ;
}
static int T_5 F_72 ( void )
{
int V_8 ;
unsigned long V_11 ;
struct V_59 * V_30 ;
V_8 = F_73 ( & V_74 ) ;
if ( V_8 < 0 )
return V_8 ;
F_53 ( & V_77 , V_11 ) ;
F_74 (chip, &gpio_chips, list) {
if ( V_30 -> V_88 )
continue;
F_54 ( & V_77 , V_11 ) ;
V_8 = F_69 ( V_30 ) ;
F_53 ( & V_77 , V_11 ) ;
}
F_54 ( & V_77 , V_11 ) ;
return V_8 ;
}

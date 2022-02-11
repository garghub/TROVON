static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
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
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const struct V_51 * V_30 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_6 , V_30 -> V_52 ) ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const struct V_51 * V_30 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_30 -> V_53 ? : L_10 ) ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const struct V_51 * V_30 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_11 , V_30 -> V_54 ) ;
}
static T_1 F_42 ( struct V_55 * V_55 ,
struct V_56 * V_4 ,
const char * V_5 , T_2 V_57 )
{
long V_58 ;
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_14 ( V_5 , 0 , & V_58 ) ;
if ( V_8 < 0 )
goto V_59;
V_7 = F_43 ( V_58 ) ;
if ( ! V_7 ) {
F_44 ( L_12 , V_60 , V_58 ) ;
return - V_15 ;
}
V_8 = F_45 ( V_7 , L_13 ) ;
if ( V_8 < 0 ) {
if ( V_8 == - V_61 )
V_8 = - V_40 ;
goto V_59;
}
V_8 = F_46 ( V_7 , true ) ;
if ( V_8 < 0 )
F_47 ( V_7 ) ;
else
F_35 ( V_62 , & V_7 -> V_11 ) ;
V_59:
if ( V_8 )
F_48 ( L_14 , V_60 , V_8 ) ;
return V_8 ? : V_57 ;
}
static T_1 F_49 ( struct V_55 * V_55 ,
struct V_56 * V_4 ,
const char * V_5 , T_2 V_57 )
{
long V_58 ;
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_14 ( V_5 , 0 , & V_58 ) ;
if ( V_8 < 0 )
goto V_59;
V_7 = F_43 ( V_58 ) ;
if ( ! V_7 ) {
F_44 ( L_12 , V_60 , V_58 ) ;
return - V_15 ;
}
V_8 = - V_15 ;
if ( F_50 ( V_62 , & V_7 -> V_11 ) ) {
V_8 = 0 ;
F_47 ( V_7 ) ;
}
V_59:
if ( V_8 )
F_48 ( L_14 , V_60 , V_8 ) ;
return V_8 ? : V_57 ;
}
int F_46 ( struct V_6 * V_7 , bool V_63 )
{
unsigned long V_11 ;
int V_8 ;
const char * V_64 = NULL ;
struct V_1 * V_2 ;
int V_65 ;
if ( ! V_66 . V_67 ) {
F_48 ( L_15 , V_60 ) ;
return - V_68 ;
}
if ( ! V_7 ) {
F_48 ( L_16 , V_60 ) ;
return - V_15 ;
}
F_3 ( & V_9 ) ;
F_51 ( & V_69 , V_11 ) ;
if ( ! F_4 ( V_70 , & V_7 -> V_11 ) ||
F_4 ( V_10 , & V_7 -> V_11 ) ) {
F_52 ( & V_69 , V_11 ) ;
F_53 ( V_7 , L_17 ,
V_60 ,
F_4 ( V_70 , & V_7 -> V_11 ) ,
F_4 ( V_10 , & V_7 -> V_11 ) ) ;
V_8 = - V_16 ;
goto V_71;
}
if ( ! V_7 -> V_30 -> V_72 || ! V_7 -> V_30 -> V_73 )
V_63 = false ;
F_52 ( & V_69 , V_11 ) ;
V_65 = F_23 ( V_7 ) ;
if ( V_7 -> V_30 -> V_74 && V_7 -> V_30 -> V_74 [ V_65 ] )
V_64 = V_7 -> V_30 -> V_74 [ V_65 ] ;
V_2 = F_54 ( & V_66 , V_7 -> V_30 -> V_2 , F_55 ( 0 , 0 ) ,
V_7 , V_64 ? V_64 : L_18 ,
F_56 ( V_7 ) ) ;
if ( F_57 ( V_2 ) ) {
V_8 = F_58 ( V_2 ) ;
goto V_71;
}
V_8 = F_59 ( & V_2 -> V_38 , & V_75 ) ;
if ( V_8 )
goto V_76;
if ( V_63 ) {
V_8 = F_60 ( V_2 , & V_77 ) ;
if ( V_8 )
goto V_76;
}
if ( F_19 ( V_7 ) >= 0 && ( V_63 ||
! F_4 ( V_13 , & V_7 -> V_11 ) ) ) {
V_8 = F_60 ( V_2 , & V_78 ) ;
if ( V_8 )
goto V_76;
}
F_35 ( V_10 , & V_7 -> V_11 ) ;
F_6 ( & V_9 ) ;
return 0 ;
V_76:
F_61 ( V_2 ) ;
V_71:
F_6 ( & V_9 ) ;
F_53 ( V_7 , L_14 , V_60 , V_8 ) ;
return V_8 ;
}
static int F_62 ( struct V_1 * V_2 , const void * V_79 )
{
return F_2 ( V_2 ) == V_79 ;
}
int F_63 ( struct V_1 * V_2 , const char * V_48 ,
struct V_6 * V_7 )
{
int V_8 = - V_15 ;
if ( ! V_7 ) {
F_44 ( L_19 , V_60 ) ;
return - V_15 ;
}
F_3 ( & V_9 ) ;
if ( F_4 ( V_10 , & V_7 -> V_11 ) ) {
struct V_1 * V_80 ;
V_80 = F_64 ( & V_66 , NULL , V_7 , F_62 ) ;
if ( V_80 != NULL ) {
V_8 = F_65 ( & V_2 -> V_38 , & V_80 -> V_38 ,
V_48 ) ;
} else {
V_8 = - V_40 ;
}
}
F_6 ( & V_9 ) ;
if ( V_8 )
F_53 ( V_7 , L_14 , V_60 , V_8 ) ;
return V_8 ;
}
int F_66 ( struct V_6 * V_7 , int V_17 )
{
struct V_1 * V_2 = NULL ;
int V_8 = - V_15 ;
if ( ! V_7 ) {
F_44 ( L_19 , V_60 ) ;
return - V_15 ;
}
F_3 ( & V_9 ) ;
if ( F_4 ( V_10 , & V_7 -> V_11 ) ) {
V_2 = F_64 ( & V_66 , NULL , V_7 , F_62 ) ;
if ( V_2 == NULL ) {
V_8 = - V_40 ;
goto V_81;
}
}
V_8 = F_34 ( V_7 , V_2 , V_17 ) ;
V_81:
F_6 ( & V_9 ) ;
if ( V_8 )
F_53 ( V_7 , L_14 , V_60 , V_8 ) ;
return V_8 ;
}
void F_67 ( struct V_6 * V_7 )
{
int V_8 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_7 ) {
F_44 ( L_19 , V_60 ) ;
return;
}
F_3 ( & V_9 ) ;
if ( F_4 ( V_10 , & V_7 -> V_11 ) ) {
V_2 = F_64 ( & V_66 , NULL , V_7 , F_62 ) ;
if ( V_2 ) {
F_18 ( V_7 , V_2 , 0 ) ;
F_36 ( V_10 , & V_7 -> V_11 ) ;
} else
V_8 = - V_40 ;
}
F_6 ( & V_9 ) ;
if ( V_2 ) {
F_61 ( V_2 ) ;
F_68 ( V_2 ) ;
}
if ( V_8 )
F_53 ( V_7 , L_14 , V_60 , V_8 ) ;
}
int F_69 ( struct V_51 * V_30 )
{
int V_8 ;
struct V_1 * V_2 ;
if ( ! V_66 . V_67 )
return 0 ;
F_3 ( & V_9 ) ;
V_2 = F_54 ( & V_66 , V_30 -> V_2 , F_55 ( 0 , 0 ) , V_30 ,
L_20 , V_30 -> V_52 ) ;
if ( ! F_57 ( V_2 ) ) {
V_8 = F_59 ( & V_2 -> V_38 ,
& V_82 ) ;
} else
V_8 = F_58 ( V_2 ) ;
V_30 -> V_83 = ( V_8 == 0 ) ;
F_6 ( & V_9 ) ;
if ( V_8 )
F_70 ( V_30 , L_14 , V_60 , V_8 ) ;
return V_8 ;
}
void F_71 ( struct V_51 * V_30 )
{
int V_8 ;
struct V_1 * V_2 ;
F_3 ( & V_9 ) ;
V_2 = F_64 ( & V_66 , NULL , V_30 , F_62 ) ;
if ( V_2 ) {
F_68 ( V_2 ) ;
F_61 ( V_2 ) ;
V_30 -> V_83 = false ;
V_8 = 0 ;
} else
V_8 = - V_40 ;
F_6 ( & V_9 ) ;
if ( V_8 )
F_70 ( V_30 , L_14 , V_60 , V_8 ) ;
}
static int T_4 F_72 ( void )
{
int V_8 ;
unsigned long V_11 ;
struct V_51 * V_30 ;
V_8 = F_73 ( & V_66 ) ;
if ( V_8 < 0 )
return V_8 ;
F_51 ( & V_69 , V_11 ) ;
F_74 (chip, &gpio_chips, list) {
if ( V_30 -> V_83 )
continue;
F_52 ( & V_69 , V_11 ) ;
V_8 = F_69 ( V_30 ) ;
F_51 ( & V_69 , V_11 ) ;
}
F_52 ( & V_69 , V_11 ) ;
return V_8 ;
}

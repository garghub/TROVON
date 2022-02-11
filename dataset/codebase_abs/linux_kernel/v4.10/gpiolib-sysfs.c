static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 V_10 ;
F_3 ( & V_7 -> V_11 ) ;
F_4 ( V_9 ) ;
V_10 = sprintf ( V_5 , L_1 ,
F_5 ( V_12 , & V_9 -> V_13 )
? L_2 : L_3 ) ;
F_6 ( & V_7 -> V_11 ) ;
return V_10 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 V_10 ;
F_3 ( & V_7 -> V_11 ) ;
if ( F_8 ( V_5 , L_4 ) )
V_10 = F_9 ( V_9 , 1 ) ;
else if ( F_8 ( V_5 , L_2 ) || F_8 ( V_5 , L_5 ) )
V_10 = F_9 ( V_9 , 0 ) ;
else if ( F_8 ( V_5 , L_3 ) )
V_10 = F_10 ( V_9 ) ;
else
V_10 = - V_15 ;
F_6 ( & V_7 -> V_11 ) ;
return V_10 ? : V_14 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 V_10 ;
F_3 ( & V_7 -> V_11 ) ;
V_10 = sprintf ( V_5 , L_6 , F_12 ( V_9 ) ) ;
F_6 ( & V_7 -> V_11 ) ;
return V_10 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 V_10 ;
F_3 ( & V_7 -> V_11 ) ;
if ( ! F_5 ( V_12 , & V_9 -> V_13 ) ) {
V_10 = - V_16 ;
} else {
long V_17 ;
V_10 = F_14 ( V_5 , 0 , & V_17 ) ;
if ( V_10 == 0 ) {
F_15 ( V_9 , V_17 ) ;
V_10 = V_14 ;
}
}
F_6 ( & V_7 -> V_11 ) ;
return V_10 ;
}
static T_3 F_16 ( int V_18 , void * V_19 )
{
struct V_6 * V_7 = V_19 ;
F_17 ( V_7 -> V_20 ) ;
return V_21 ;
}
static int F_18 ( struct V_1 * V_2 , unsigned char V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long V_22 ;
int V_23 ;
V_7 -> V_18 = F_19 ( V_9 ) ;
if ( V_7 -> V_18 < 0 )
return - V_24 ;
V_7 -> V_20 = F_20 ( V_2 -> V_25 . V_26 , L_7 ) ;
if ( ! V_7 -> V_20 )
return - V_27 ;
V_22 = V_28 ;
if ( V_13 & V_29 )
V_22 |= F_5 ( V_30 , & V_9 -> V_13 ) ?
V_31 : V_32 ;
if ( V_13 & V_33 )
V_22 |= F_5 ( V_30 , & V_9 -> V_13 ) ?
V_32 : V_31 ;
V_23 = F_21 ( V_9 -> V_34 -> V_35 , F_22 ( V_9 ) ) ;
if ( V_23 < 0 )
goto V_36;
V_23 = F_23 ( V_7 -> V_18 , F_16 , V_22 ,
L_8 , V_7 ) ;
if ( V_23 < 0 )
goto V_37;
V_7 -> V_22 = V_13 ;
return 0 ;
V_37:
F_24 ( V_9 -> V_34 -> V_35 , F_22 ( V_9 ) ) ;
V_36:
F_25 ( V_7 -> V_20 ) ;
return V_23 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
V_7 -> V_22 = 0 ;
F_27 ( V_7 -> V_18 , V_7 ) ;
F_24 ( V_9 -> V_34 -> V_35 , F_22 ( V_9 ) ) ;
F_25 ( V_7 -> V_20 ) ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_10 = 0 ;
int V_38 ;
F_3 ( & V_7 -> V_11 ) ;
for ( V_38 = 0 ; V_38 < F_29 ( V_39 ) ; V_38 ++ ) {
if ( V_7 -> V_22 == V_39 [ V_38 ] . V_13 ) {
V_10 = sprintf ( V_5 , L_1 , V_39 [ V_38 ] . V_40 ) ;
break;
}
}
F_6 ( & V_7 -> V_11 ) ;
return V_10 ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned char V_13 ;
T_1 V_10 = V_14 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < F_29 ( V_39 ) ; V_38 ++ ) {
if ( F_8 ( V_39 [ V_38 ] . V_40 , V_5 ) )
break;
}
if ( V_38 == F_29 ( V_39 ) )
return - V_15 ;
V_13 = V_39 [ V_38 ] . V_13 ;
F_3 ( & V_7 -> V_11 ) ;
if ( V_13 == V_7 -> V_22 ) {
V_10 = V_14 ;
goto V_41;
}
if ( V_7 -> V_22 )
F_26 ( V_2 ) ;
if ( V_13 ) {
V_10 = F_18 ( V_2 , V_13 ) ;
if ( ! V_10 )
V_10 = V_14 ;
}
V_41:
F_6 ( & V_7 -> V_11 ) ;
return V_10 ;
}
static int F_31 ( struct V_1 * V_2 , int V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
int V_10 = 0 ;
unsigned int V_13 = V_7 -> V_22 ;
if ( ! ! F_5 ( V_30 , & V_9 -> V_13 ) == ! ! V_17 )
return 0 ;
if ( V_17 )
F_32 ( V_30 , & V_9 -> V_13 ) ;
else
F_33 ( V_30 , & V_9 -> V_13 ) ;
if ( V_13 == V_29 ||
V_13 == V_33 ) {
F_26 ( V_2 ) ;
V_10 = F_18 ( V_2 , V_13 ) ;
}
return V_10 ;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 V_10 ;
F_3 ( & V_7 -> V_11 ) ;
V_10 = sprintf ( V_5 , L_6 ,
! ! F_5 ( V_30 , & V_9 -> V_13 ) ) ;
F_6 ( & V_7 -> V_11 ) ;
return V_10 ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_10 ;
long V_17 ;
F_3 ( & V_7 -> V_11 ) ;
V_10 = F_14 ( V_5 , 0 , & V_17 ) ;
if ( V_10 == 0 )
V_10 = F_31 ( V_2 , V_17 ) ;
F_6 ( & V_7 -> V_11 ) ;
return V_10 ? : V_14 ;
}
static T_4 F_36 ( struct V_42 * V_25 , struct V_43 * V_4 ,
int V_44 )
{
struct V_1 * V_2 = F_37 ( V_25 , struct V_1 , V_25 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
T_4 V_45 = V_4 -> V_45 ;
bool V_46 = V_7 -> V_47 ;
if ( V_4 == & V_48 . V_4 ) {
if ( ! V_46 )
V_45 = 0 ;
} else if ( V_4 == & V_49 . V_4 ) {
if ( F_19 ( V_9 ) < 0 )
V_45 = 0 ;
if ( ! V_46 && F_5 ( V_12 , & V_9 -> V_13 ) )
V_45 = 0 ;
}
return V_45 ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const struct V_50 * V_35 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_6 , V_35 -> V_51 ) ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const struct V_50 * V_35 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_35 -> V_52 ? : L_9 ) ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const struct V_50 * V_35 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , V_35 -> V_53 ) ;
}
static T_1 F_41 ( struct V_54 * V_54 ,
struct V_55 * V_4 ,
const char * V_5 , T_2 V_56 )
{
long V_57 ;
struct V_8 * V_9 ;
int V_10 ;
V_10 = F_14 ( V_5 , 0 , & V_57 ) ;
if ( V_10 < 0 )
goto V_58;
V_9 = F_42 ( V_57 ) ;
if ( ! V_9 ) {
F_43 ( L_11 , V_59 , V_57 ) ;
return - V_15 ;
}
V_10 = F_44 ( V_9 , L_12 ) ;
if ( V_10 < 0 ) {
if ( V_10 == - V_60 )
V_10 = - V_27 ;
goto V_58;
}
V_10 = F_45 ( V_9 , true ) ;
if ( V_10 < 0 )
F_46 ( V_9 ) ;
else
F_32 ( V_61 , & V_9 -> V_13 ) ;
V_58:
if ( V_10 )
F_47 ( L_13 , V_59 , V_10 ) ;
return V_10 ? : V_56 ;
}
static T_1 F_48 ( struct V_54 * V_54 ,
struct V_55 * V_4 ,
const char * V_5 , T_2 V_56 )
{
long V_57 ;
struct V_8 * V_9 ;
int V_10 ;
V_10 = F_14 ( V_5 , 0 , & V_57 ) ;
if ( V_10 < 0 )
goto V_58;
V_9 = F_42 ( V_57 ) ;
if ( ! V_9 ) {
F_43 ( L_11 , V_59 , V_57 ) ;
return - V_15 ;
}
V_10 = - V_15 ;
if ( F_49 ( V_61 , & V_9 -> V_13 ) ) {
V_10 = 0 ;
F_46 ( V_9 ) ;
}
V_58:
if ( V_10 )
F_47 ( L_13 , V_59 , V_10 ) ;
return V_10 ? : V_56 ;
}
int F_45 ( struct V_8 * V_9 , bool V_62 )
{
struct V_50 * V_35 ;
struct V_63 * V_34 ;
struct V_6 * V_7 ;
unsigned long V_13 ;
int V_10 ;
const char * V_64 = NULL ;
struct V_1 * V_2 ;
int V_65 ;
if ( ! V_66 . V_67 ) {
F_47 ( L_14 , V_59 ) ;
return - V_68 ;
}
if ( ! V_9 ) {
F_47 ( L_15 , V_59 ) ;
return - V_15 ;
}
V_34 = V_9 -> V_34 ;
V_35 = V_34 -> V_35 ;
F_3 ( & V_69 ) ;
if ( ! V_35 || ! V_34 -> V_70 ) {
V_10 = - V_27 ;
goto V_37;
}
F_50 ( & V_71 , V_13 ) ;
if ( ! F_5 ( V_72 , & V_9 -> V_13 ) ||
F_5 ( V_73 , & V_9 -> V_13 ) ) {
F_51 ( & V_71 , V_13 ) ;
F_52 ( V_9 , L_16 ,
V_59 ,
F_5 ( V_72 , & V_9 -> V_13 ) ,
F_5 ( V_73 , & V_9 -> V_13 ) ) ;
V_10 = - V_16 ;
goto V_37;
}
F_51 ( & V_71 , V_13 ) ;
V_7 = F_53 ( sizeof( * V_7 ) , V_74 ) ;
if ( ! V_7 ) {
V_10 = - V_75 ;
goto V_37;
}
V_7 -> V_9 = V_9 ;
F_54 ( & V_7 -> V_11 ) ;
if ( V_35 -> V_76 && V_35 -> V_77 )
V_7 -> V_47 = V_62 ;
else
V_7 -> V_47 = false ;
V_65 = F_22 ( V_9 ) ;
if ( V_35 -> V_78 && V_35 -> V_78 [ V_65 ] )
V_64 = V_35 -> V_78 [ V_65 ] ;
V_2 = F_55 ( & V_66 , & V_34 -> V_2 ,
F_56 ( 0 , 0 ) , V_7 , V_79 ,
V_64 ? V_64 : L_17 ,
F_57 ( V_9 ) ) ;
if ( F_58 ( V_2 ) ) {
V_10 = F_59 ( V_2 ) ;
goto V_80;
}
F_32 ( V_73 , & V_9 -> V_13 ) ;
F_6 ( & V_69 ) ;
return 0 ;
V_80:
F_60 ( V_7 ) ;
V_37:
F_6 ( & V_69 ) ;
F_52 ( V_9 , L_13 , V_59 , V_10 ) ;
return V_10 ;
}
static int F_61 ( struct V_1 * V_2 , const void * V_9 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_9 == V_9 ;
}
int F_62 ( struct V_1 * V_2 , const char * V_40 ,
struct V_8 * V_9 )
{
struct V_1 * V_81 ;
int V_23 ;
if ( ! V_9 ) {
F_43 ( L_18 , V_59 ) ;
return - V_15 ;
}
V_81 = F_63 ( & V_66 , NULL , V_9 , F_61 ) ;
if ( ! V_81 )
return - V_27 ;
V_23 = F_64 ( & V_2 -> V_25 , & V_81 -> V_25 , V_40 ) ;
F_65 ( V_81 ) ;
return V_23 ;
}
void F_66 ( struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
if ( ! V_9 ) {
F_43 ( L_18 , V_59 ) ;
return;
}
F_3 ( & V_69 ) ;
if ( ! F_5 ( V_73 , & V_9 -> V_13 ) )
goto V_37;
V_2 = F_63 ( & V_66 , NULL , V_9 , F_61 ) ;
if ( ! V_2 )
goto V_37;
V_7 = F_2 ( V_2 ) ;
F_33 ( V_73 , & V_9 -> V_13 ) ;
F_67 ( V_2 ) ;
if ( V_7 -> V_22 )
F_26 ( V_2 ) ;
F_6 ( & V_69 ) ;
F_65 ( V_2 ) ;
F_60 ( V_7 ) ;
return;
V_37:
F_6 ( & V_69 ) ;
}
int F_68 ( struct V_63 * V_34 )
{
struct V_1 * V_2 ;
struct V_1 * V_82 ;
struct V_50 * V_35 = V_34 -> V_35 ;
if ( ! V_66 . V_67 )
return 0 ;
if ( V_35 -> V_82 )
V_82 = V_35 -> V_82 ;
else
V_82 = & V_34 -> V_2 ;
V_2 = F_55 ( & V_66 , V_82 ,
F_56 ( 0 , 0 ) ,
V_35 , V_83 ,
L_19 , V_35 -> V_51 ) ;
if ( F_58 ( V_2 ) )
return F_59 ( V_2 ) ;
F_3 ( & V_69 ) ;
V_34 -> V_70 = V_2 ;
F_6 ( & V_69 ) ;
return 0 ;
}
void F_69 ( struct V_63 * V_34 )
{
struct V_8 * V_9 ;
struct V_50 * V_35 = V_34 -> V_35 ;
unsigned int V_38 ;
if ( ! V_34 -> V_70 )
return;
F_67 ( V_34 -> V_70 ) ;
F_3 ( & V_69 ) ;
V_34 -> V_70 = NULL ;
F_6 ( & V_69 ) ;
for ( V_38 = 0 ; V_38 < V_35 -> V_53 ; V_38 ++ ) {
V_9 = & V_34 -> V_84 [ V_38 ] ;
if ( F_49 ( V_61 , & V_9 -> V_13 ) )
F_46 ( V_9 ) ;
}
}
static int T_5 F_70 ( void )
{
int V_10 ;
unsigned long V_13 ;
struct V_63 * V_34 ;
V_10 = F_71 ( & V_66 ) ;
if ( V_10 < 0 )
return V_10 ;
F_50 ( & V_71 , V_13 ) ;
F_72 (gdev, &gpio_devices, list) {
if ( V_34 -> V_70 )
continue;
F_51 ( & V_71 , V_13 ) ;
V_10 = F_68 ( V_34 ) ;
F_50 ( & V_71 , V_13 ) ;
}
F_51 ( & V_71 , V_13 ) ;
return V_10 ;
}

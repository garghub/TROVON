static int T_1 F_1 ( char * V_1 )
{
F_2 ( V_2 , V_1 , V_3 ) ;
return 1 ;
}
static int T_1 F_3 ( void )
{
F_4 ( & V_4 . V_5 ) ;
F_5 ( & V_4 . V_6 ) ;
return F_6 ( & V_4 ) ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_4 ) ;
}
static void F_9 ( struct V_7 * V_8 )
{
if ( F_10 ( & V_8 -> V_9 ) )
F_11 ( & V_8 -> V_9 ) ;
}
static void F_12 ( struct V_7 * V_8 )
{
if ( F_10 ( & V_8 -> V_9 ) )
F_13 ( & V_8 -> V_9 ) ;
}
static int T_1 F_3 ( void )
{
return 0 ;
}
static void T_2 F_7 ( void )
{
}
static void F_9 ( struct V_7 * V_8 )
{
}
static void F_12 ( struct V_7 * V_8 )
{
}
static struct V_7 * F_14 ( char * V_10 )
{
int V_11 = - V_12 ;
struct V_7 * V_8 ;
V_8 = F_15 ( sizeof( * V_8 ) , V_13 ) ;
if ( ! V_8 )
goto V_14;
V_8 -> V_15 . V_16 = L_1 ;
F_2 ( V_8 -> V_15 . V_17 , L_2 , V_18 ) ;
V_8 -> V_15 . V_19 = 6665 ;
V_8 -> V_15 . V_20 = 6666 ;
F_5 ( & V_8 -> V_21 ) ;
memset ( V_8 -> V_15 . V_22 , 0xff , V_23 ) ;
V_11 = F_16 ( & V_8 -> V_15 , V_10 ) ;
if ( V_11 )
goto V_14;
V_11 = F_17 ( & V_8 -> V_15 ) ;
if ( V_11 )
goto V_14;
V_8 -> V_24 = 1 ;
return V_8 ;
V_14:
F_18 ( V_8 ) ;
return F_19 ( V_11 ) ;
}
static void F_20 ( struct V_7 * V_8 )
{
F_21 ( & V_8 -> V_15 ) ;
F_18 ( V_8 ) ;
}
static struct V_7 * F_22 ( struct V_25 * V_9 )
{
return V_9 ?
F_23 ( V_9 , struct V_7 , V_9 ) :
NULL ;
}
static T_3 F_24 ( struct V_7 * V_8 , char * V_26 )
{
return snprintf ( V_26 , V_27 , L_3 , V_8 -> V_24 ) ;
}
static T_3 F_25 ( struct V_7 * V_8 , char * V_26 )
{
return snprintf ( V_26 , V_27 , L_4 , V_8 -> V_15 . V_17 ) ;
}
static T_3 F_26 ( struct V_7 * V_8 , char * V_26 )
{
return snprintf ( V_26 , V_27 , L_3 , V_8 -> V_15 . V_19 ) ;
}
static T_3 F_27 ( struct V_7 * V_8 , char * V_26 )
{
return snprintf ( V_26 , V_27 , L_3 , V_8 -> V_15 . V_20 ) ;
}
static T_3 F_28 ( struct V_7 * V_8 , char * V_26 )
{
if ( V_8 -> V_15 . V_28 )
return snprintf ( V_26 , V_27 , L_5 , & V_8 -> V_15 . V_29 . V_30 ) ;
else
return snprintf ( V_26 , V_27 , L_6 , & V_8 -> V_15 . V_29 ) ;
}
static T_3 F_29 ( struct V_7 * V_8 , char * V_26 )
{
if ( V_8 -> V_15 . V_28 )
return snprintf ( V_26 , V_27 , L_5 , & V_8 -> V_15 . V_31 . V_30 ) ;
else
return snprintf ( V_26 , V_27 , L_6 , & V_8 -> V_15 . V_31 ) ;
}
static T_3 F_30 ( struct V_7 * V_8 , char * V_26 )
{
struct V_32 * V_33 = V_8 -> V_15 . V_33 ;
static const T_4 V_34 [ V_23 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
return snprintf ( V_26 , V_27 , L_7 , V_33 ? V_33 -> V_35 : V_34 ) ;
}
static T_3 F_31 ( struct V_7 * V_8 , char * V_26 )
{
return snprintf ( V_26 , V_27 , L_7 , V_8 -> V_15 . V_22 ) ;
}
static T_3 F_32 ( struct V_7 * V_8 ,
const char * V_26 ,
T_5 V_36 )
{
unsigned long V_37 ;
int V_24 ;
int V_11 ;
V_11 = F_33 ( V_26 , 10 , & V_24 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_24 < 0 || V_24 > 1 )
return - V_38 ;
if ( V_24 == V_8 -> V_24 ) {
F_34 ( L_8 ,
V_8 -> V_24 ? L_9 : L_10 ) ;
return - V_38 ;
}
if ( V_24 ) {
F_35 ( & V_8 -> V_15 ) ;
V_11 = F_17 ( & V_8 -> V_15 ) ;
if ( V_11 )
return V_11 ;
F_34 ( L_11 ) ;
} else {
F_36 ( & V_39 , V_37 ) ;
V_8 -> V_24 = 0 ;
F_37 ( & V_39 , V_37 ) ;
F_21 ( & V_8 -> V_15 ) ;
}
V_8 -> V_24 = V_24 ;
return F_38 ( V_26 , V_36 ) ;
}
static T_3 F_39 ( struct V_7 * V_8 ,
const char * V_26 ,
T_5 V_36 )
{
T_5 V_40 ;
if ( V_8 -> V_24 ) {
F_40 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_38 ;
}
F_2 ( V_8 -> V_15 . V_17 , V_26 , V_18 ) ;
V_40 = F_38 ( V_8 -> V_15 . V_17 , V_18 ) ;
if ( V_8 -> V_15 . V_17 [ V_40 - 1 ] == '\n' )
V_8 -> V_15 . V_17 [ V_40 - 1 ] = '\0' ;
return F_38 ( V_26 , V_36 ) ;
}
static T_3 F_41 ( struct V_7 * V_8 ,
const char * V_26 ,
T_5 V_36 )
{
int V_41 ;
if ( V_8 -> V_24 ) {
F_40 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_38 ;
}
V_41 = F_42 ( V_26 , 10 , & V_8 -> V_15 . V_19 ) ;
if ( V_41 < 0 )
return V_41 ;
return F_38 ( V_26 , V_36 ) ;
}
static T_3 F_43 ( struct V_7 * V_8 ,
const char * V_26 ,
T_5 V_36 )
{
int V_41 ;
if ( V_8 -> V_24 ) {
F_40 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_38 ;
}
V_41 = F_42 ( V_26 , 10 , & V_8 -> V_15 . V_20 ) ;
if ( V_41 < 0 )
return V_41 ;
return F_38 ( V_26 , V_36 ) ;
}
static T_3 F_44 ( struct V_7 * V_8 ,
const char * V_26 ,
T_5 V_36 )
{
if ( V_8 -> V_24 ) {
F_40 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_38 ;
}
if ( F_45 ( V_26 , V_36 , ':' ) ) {
const char * V_42 ;
if ( F_46 ( V_26 , V_36 , V_8 -> V_15 . V_29 . V_30 . V_43 , - 1 , & V_42 ) > 0 ) {
if ( * V_42 && * V_42 != '\n' ) {
F_40 ( L_13 , * V_42 ) ;
return - V_38 ;
}
V_8 -> V_15 . V_28 = true ;
} else
return - V_38 ;
} else {
if ( ! V_8 -> V_15 . V_28 ) {
V_8 -> V_15 . V_29 . V_44 = F_47 ( V_26 ) ;
} else
return - V_38 ;
}
return F_38 ( V_26 , V_36 ) ;
}
static T_3 F_48 ( struct V_7 * V_8 ,
const char * V_26 ,
T_5 V_36 )
{
if ( V_8 -> V_24 ) {
F_40 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_38 ;
}
if ( F_45 ( V_26 , V_36 , ':' ) ) {
const char * V_42 ;
if ( F_46 ( V_26 , V_36 , V_8 -> V_15 . V_31 . V_30 . V_43 , - 1 , & V_42 ) > 0 ) {
if ( * V_42 && * V_42 != '\n' ) {
F_40 ( L_13 , * V_42 ) ;
return - V_38 ;
}
V_8 -> V_15 . V_28 = true ;
} else
return - V_38 ;
} else {
if ( ! V_8 -> V_15 . V_28 ) {
V_8 -> V_15 . V_31 . V_44 = F_47 ( V_26 ) ;
} else
return - V_38 ;
}
return F_38 ( V_26 , V_36 ) ;
}
static T_3 F_49 ( struct V_7 * V_8 ,
const char * V_26 ,
T_5 V_36 )
{
T_4 V_22 [ V_23 ] ;
if ( V_8 -> V_24 ) {
F_40 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_38 ;
}
if ( ! F_50 ( V_26 , V_22 ) )
return - V_38 ;
if ( V_26 [ 3 * V_23 - 1 ] && V_26 [ 3 * V_23 - 1 ] != '\n' )
return - V_38 ;
memcpy ( V_8 -> V_15 . V_22 , V_22 , V_23 ) ;
return F_38 ( V_26 , V_36 ) ;
}
static void F_51 ( struct V_25 * V_9 )
{
F_18 ( F_22 ( V_9 ) ) ;
}
static T_3 F_52 ( struct V_25 * V_9 ,
struct V_45 * V_46 ,
char * V_26 )
{
T_3 V_47 = - V_38 ;
struct V_7 * V_8 = F_22 ( V_9 ) ;
struct V_48 * V_49 =
F_23 ( V_46 , struct V_48 , V_46 ) ;
if ( V_49 -> V_50 )
V_47 = V_49 -> V_50 ( V_8 , V_26 ) ;
return V_47 ;
}
static T_3 F_53 ( struct V_25 * V_9 ,
struct V_45 * V_46 ,
const char * V_26 ,
T_5 V_36 )
{
T_3 V_47 = - V_38 ;
struct V_7 * V_8 = F_22 ( V_9 ) ;
struct V_48 * V_49 =
F_23 ( V_46 , struct V_48 , V_46 ) ;
F_54 ( & V_8 -> V_21 ) ;
if ( V_49 -> V_51 )
V_47 = V_49 -> V_51 ( V_8 , V_26 , V_36 ) ;
F_55 ( & V_8 -> V_21 ) ;
return V_47 ;
}
static struct V_25 * F_56 ( struct V_52 * V_53 ,
const char * V_16 )
{
unsigned long V_37 ;
struct V_7 * V_8 ;
V_8 = F_15 ( sizeof( * V_8 ) , V_13 ) ;
if ( ! V_8 )
return F_19 ( - V_12 ) ;
V_8 -> V_15 . V_16 = L_1 ;
F_2 ( V_8 -> V_15 . V_17 , L_2 , V_18 ) ;
V_8 -> V_15 . V_19 = 6665 ;
V_8 -> V_15 . V_20 = 6666 ;
F_5 ( & V_8 -> V_21 ) ;
memset ( V_8 -> V_15 . V_22 , 0xff , V_23 ) ;
F_57 ( & V_8 -> V_9 , V_16 , & V_54 ) ;
F_36 ( & V_39 , V_37 ) ;
F_58 ( & V_8 -> V_55 , & V_56 ) ;
F_37 ( & V_39 , V_37 ) ;
return & V_8 -> V_9 ;
}
static void F_59 ( struct V_52 * V_53 ,
struct V_25 * V_9 )
{
unsigned long V_37 ;
struct V_7 * V_8 = F_22 ( V_9 ) ;
F_36 ( & V_39 , V_37 ) ;
F_60 ( & V_8 -> V_55 ) ;
F_37 ( & V_39 , V_37 ) ;
if ( V_8 -> V_24 )
F_21 ( & V_8 -> V_15 ) ;
F_13 ( & V_8 -> V_9 ) ;
}
static int F_61 ( struct V_57 * V_58 ,
unsigned long V_59 , void * V_60 )
{
unsigned long V_37 ;
struct V_7 * V_8 ;
struct V_32 * V_33 = F_62 ( V_60 ) ;
bool V_61 = false ;
if ( ! ( V_59 == V_62 || V_59 == V_63 ||
V_59 == V_64 || V_59 == V_65 ) )
goto V_66;
F_36 ( & V_39 , V_37 ) ;
V_67:
F_63 (nt, &target_list, list) {
F_9 ( V_8 ) ;
if ( V_8 -> V_15 . V_33 == V_33 ) {
switch ( V_59 ) {
case V_62 :
F_2 ( V_8 -> V_15 . V_17 , V_33 -> V_16 , V_18 ) ;
break;
case V_64 :
case V_65 :
case V_63 :
F_37 ( & V_39 , V_37 ) ;
F_64 ( & V_8 -> V_15 ) ;
F_36 ( & V_39 , V_37 ) ;
F_65 ( V_8 -> V_15 . V_33 ) ;
V_8 -> V_15 . V_33 = NULL ;
V_8 -> V_24 = 0 ;
V_61 = true ;
F_12 ( V_8 ) ;
goto V_67;
}
}
F_12 ( V_8 ) ;
}
F_37 ( & V_39 , V_37 ) ;
if ( V_61 ) {
const char * V_68 = L_14 ;
switch ( V_59 ) {
case V_63 :
V_68 = L_15 ;
break;
case V_64 :
V_68 = L_16 ;
break;
case V_65 :
V_68 = L_17 ;
break;
}
F_34 ( L_18 ,
V_33 -> V_16 , V_68 ) ;
}
V_66:
return V_69 ;
}
static void F_66 ( struct V_70 * V_71 , const char * V_68 , unsigned int V_40 )
{
int V_72 , V_73 ;
unsigned long V_37 ;
struct V_7 * V_8 ;
const char * V_74 ;
if ( V_75 && ! V_76 )
return;
if ( F_67 ( & V_56 ) )
return;
F_36 ( & V_39 , V_37 ) ;
F_63 (nt, &target_list, list) {
F_9 ( V_8 ) ;
if ( V_8 -> V_24 && F_68 ( V_8 -> V_15 . V_33 ) ) {
V_74 = V_68 ;
for ( V_73 = V_40 ; V_73 ; ) {
V_72 = F_69 ( V_73 , V_77 ) ;
F_70 ( & V_8 -> V_15 , V_74 , V_72 ) ;
V_74 += V_72 ;
V_73 -= V_72 ;
}
}
F_12 ( V_8 ) ;
}
F_37 ( & V_39 , V_37 ) ;
}
static int T_1 F_71 ( void )
{
int V_11 ;
struct V_7 * V_8 , * V_74 ;
unsigned long V_37 ;
char * V_10 ;
char * V_78 = V_2 ;
if ( F_38 ( V_78 , V_3 ) ) {
while ( ( V_10 = F_72 ( & V_78 , L_19 ) ) ) {
V_8 = F_14 ( V_10 ) ;
if ( F_73 ( V_8 ) ) {
V_11 = F_74 ( V_8 ) ;
goto V_14;
}
V_79 . V_37 |= V_80 ;
F_36 ( & V_39 , V_37 ) ;
F_58 ( & V_8 -> V_55 , & V_56 ) ;
F_37 ( & V_39 , V_37 ) ;
}
}
V_11 = F_75 ( & V_81 ) ;
if ( V_11 )
goto V_14;
V_11 = F_3 () ;
if ( V_11 )
goto V_82;
F_76 ( & V_79 ) ;
F_34 ( L_20 ) ;
return V_11 ;
V_82:
F_77 ( & V_81 ) ;
V_14:
F_40 ( L_21 ) ;
F_78 (nt, tmp, &target_list, list) {
F_60 ( & V_8 -> V_55 ) ;
F_20 ( V_8 ) ;
}
return V_11 ;
}
static void T_2 F_79 ( void )
{
struct V_7 * V_8 , * V_74 ;
F_80 ( & V_79 ) ;
F_7 () ;
F_77 ( & V_81 ) ;
F_78 (nt, tmp, &target_list, list) {
F_60 ( & V_8 -> V_55 ) ;
F_20 ( V_8 ) ;
}
}

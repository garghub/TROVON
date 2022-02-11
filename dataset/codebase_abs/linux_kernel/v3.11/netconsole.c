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
memset ( V_8 -> V_15 . V_21 , 0xff , V_22 ) ;
V_11 = F_16 ( & V_8 -> V_15 , V_10 ) ;
if ( V_11 )
goto V_14;
V_11 = F_17 ( & V_8 -> V_15 ) ;
if ( V_11 )
goto V_14;
V_8 -> V_23 = 1 ;
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
static struct V_7 * F_22 ( struct V_24 * V_9 )
{
return V_9 ?
F_23 ( V_9 , struct V_7 , V_9 ) :
NULL ;
}
static T_3 F_24 ( struct V_7 * V_8 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_3 , V_8 -> V_23 ) ;
}
static T_3 F_25 ( struct V_7 * V_8 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_4 , V_8 -> V_15 . V_17 ) ;
}
static T_3 F_26 ( struct V_7 * V_8 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_3 , V_8 -> V_15 . V_19 ) ;
}
static T_3 F_27 ( struct V_7 * V_8 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_3 , V_8 -> V_15 . V_20 ) ;
}
static T_3 F_28 ( struct V_7 * V_8 , char * V_25 )
{
if ( V_8 -> V_15 . V_27 )
return snprintf ( V_25 , V_26 , L_5 , & V_8 -> V_15 . V_28 . V_29 ) ;
else
return snprintf ( V_25 , V_26 , L_6 , & V_8 -> V_15 . V_28 ) ;
}
static T_3 F_29 ( struct V_7 * V_8 , char * V_25 )
{
if ( V_8 -> V_15 . V_27 )
return snprintf ( V_25 , V_26 , L_5 , & V_8 -> V_15 . V_30 . V_29 ) ;
else
return snprintf ( V_25 , V_26 , L_6 , & V_8 -> V_15 . V_30 ) ;
}
static T_3 F_30 ( struct V_7 * V_8 , char * V_25 )
{
struct V_31 * V_32 = V_8 -> V_15 . V_32 ;
static const T_4 V_33 [ V_22 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
return snprintf ( V_25 , V_26 , L_7 , V_32 ? V_32 -> V_34 : V_33 ) ;
}
static T_3 F_31 ( struct V_7 * V_8 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_7 , V_8 -> V_15 . V_21 ) ;
}
static T_3 F_32 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_35 )
{
int V_23 ;
int V_11 ;
V_11 = F_33 ( V_25 , 10 , & V_23 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_23 < 0 || V_23 > 1 )
return - V_36 ;
if ( V_23 == V_8 -> V_23 ) {
F_34 ( V_37 L_8 ,
V_8 -> V_23 ? L_9 : L_10 ) ;
return - V_36 ;
}
if ( V_23 ) {
F_35 ( & V_8 -> V_15 ) ;
V_11 = F_17 ( & V_8 -> V_15 ) ;
if ( V_11 )
return V_11 ;
F_34 ( V_37 L_11 ) ;
} else {
F_21 ( & V_8 -> V_15 ) ;
}
V_8 -> V_23 = V_23 ;
return F_36 ( V_25 , V_35 ) ;
}
static T_3 F_37 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_35 )
{
T_5 V_38 ;
if ( V_8 -> V_23 ) {
F_34 ( V_39 L_12
L_13 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_36 ;
}
F_2 ( V_8 -> V_15 . V_17 , V_25 , V_18 ) ;
V_38 = F_36 ( V_8 -> V_15 . V_17 , V_18 ) ;
if ( V_8 -> V_15 . V_17 [ V_38 - 1 ] == '\n' )
V_8 -> V_15 . V_17 [ V_38 - 1 ] = '\0' ;
return F_36 ( V_25 , V_35 ) ;
}
static T_3 F_38 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_35 )
{
int V_40 ;
if ( V_8 -> V_23 ) {
F_34 ( V_39 L_12
L_13 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_36 ;
}
V_40 = F_39 ( V_25 , 10 , & V_8 -> V_15 . V_19 ) ;
if ( V_40 < 0 )
return V_40 ;
return F_36 ( V_25 , V_35 ) ;
}
static T_3 F_40 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_35 )
{
int V_40 ;
if ( V_8 -> V_23 ) {
F_34 ( V_39 L_12
L_13 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_36 ;
}
V_40 = F_39 ( V_25 , 10 , & V_8 -> V_15 . V_20 ) ;
if ( V_40 < 0 )
return V_40 ;
return F_36 ( V_25 , V_35 ) ;
}
static T_3 F_41 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_35 )
{
if ( V_8 -> V_23 ) {
F_34 ( V_39 L_12
L_13 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_36 ;
}
if ( F_42 ( V_25 , V_35 , ':' ) ) {
const char * V_41 ;
if ( F_43 ( V_25 , V_35 , V_8 -> V_15 . V_28 . V_29 . V_42 , - 1 , & V_41 ) > 0 ) {
if ( * V_41 && * V_41 != '\n' ) {
F_34 ( V_39 L_14 , * V_41 ) ;
return - V_36 ;
}
V_8 -> V_15 . V_27 = true ;
} else
return - V_36 ;
} else {
if ( ! V_8 -> V_15 . V_27 ) {
V_8 -> V_15 . V_28 . V_43 = F_44 ( V_25 ) ;
} else
return - V_36 ;
}
return F_36 ( V_25 , V_35 ) ;
}
static T_3 F_45 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_35 )
{
if ( V_8 -> V_23 ) {
F_34 ( V_39 L_12
L_13 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_36 ;
}
if ( F_42 ( V_25 , V_35 , ':' ) ) {
const char * V_41 ;
if ( F_43 ( V_25 , V_35 , V_8 -> V_15 . V_30 . V_29 . V_42 , - 1 , & V_41 ) > 0 ) {
if ( * V_41 && * V_41 != '\n' ) {
F_34 ( V_39 L_14 , * V_41 ) ;
return - V_36 ;
}
V_8 -> V_15 . V_27 = true ;
} else
return - V_36 ;
} else {
if ( ! V_8 -> V_15 . V_27 ) {
V_8 -> V_15 . V_30 . V_43 = F_44 ( V_25 ) ;
} else
return - V_36 ;
}
return F_36 ( V_25 , V_35 ) ;
}
static T_3 F_46 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_35 )
{
T_4 V_21 [ V_22 ] ;
if ( V_8 -> V_23 ) {
F_34 ( V_39 L_12
L_13 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_36 ;
}
if ( ! F_47 ( V_25 , V_21 ) )
return - V_36 ;
if ( V_25 [ 3 * V_22 - 1 ] && V_25 [ 3 * V_22 - 1 ] != '\n' )
return - V_36 ;
memcpy ( V_8 -> V_15 . V_21 , V_21 , V_22 ) ;
return F_36 ( V_25 , V_35 ) ;
}
static void F_48 ( struct V_24 * V_9 )
{
F_18 ( F_22 ( V_9 ) ) ;
}
static T_3 F_49 ( struct V_24 * V_9 ,
struct V_44 * V_45 ,
char * V_25 )
{
T_3 V_46 = - V_36 ;
struct V_7 * V_8 = F_22 ( V_9 ) ;
struct V_47 * V_48 =
F_23 ( V_45 , struct V_47 , V_45 ) ;
if ( V_48 -> V_49 )
V_46 = V_48 -> V_49 ( V_8 , V_25 ) ;
return V_46 ;
}
static T_3 F_50 ( struct V_24 * V_9 ,
struct V_44 * V_45 ,
const char * V_25 ,
T_5 V_35 )
{
T_3 V_46 = - V_36 ;
struct V_7 * V_8 = F_22 ( V_9 ) ;
struct V_47 * V_48 =
F_23 ( V_45 , struct V_47 , V_45 ) ;
if ( V_48 -> V_50 )
V_46 = V_48 -> V_50 ( V_8 , V_25 , V_35 ) ;
return V_46 ;
}
static struct V_24 * F_51 ( struct V_51 * V_52 ,
const char * V_16 )
{
unsigned long V_53 ;
struct V_7 * V_8 ;
V_8 = F_15 ( sizeof( * V_8 ) , V_13 ) ;
if ( ! V_8 )
return F_19 ( - V_12 ) ;
V_8 -> V_15 . V_16 = L_1 ;
F_2 ( V_8 -> V_15 . V_17 , L_2 , V_18 ) ;
V_8 -> V_15 . V_19 = 6665 ;
V_8 -> V_15 . V_20 = 6666 ;
memset ( V_8 -> V_15 . V_21 , 0xff , V_22 ) ;
F_52 ( & V_8 -> V_9 , V_16 , & V_54 ) ;
F_53 ( & V_55 , V_53 ) ;
F_54 ( & V_8 -> V_56 , & V_57 ) ;
F_55 ( & V_55 , V_53 ) ;
return & V_8 -> V_9 ;
}
static void F_56 ( struct V_51 * V_52 ,
struct V_24 * V_9 )
{
unsigned long V_53 ;
struct V_7 * V_8 = F_22 ( V_9 ) ;
F_53 ( & V_55 , V_53 ) ;
F_57 ( & V_8 -> V_56 ) ;
F_55 ( & V_55 , V_53 ) ;
if ( V_8 -> V_23 )
F_21 ( & V_8 -> V_15 ) ;
F_13 ( & V_8 -> V_9 ) ;
}
static int F_58 ( struct V_58 * V_59 ,
unsigned long V_60 , void * V_61 )
{
unsigned long V_53 ;
struct V_7 * V_8 ;
struct V_31 * V_32 = F_59 ( V_61 ) ;
bool V_62 = false ;
if ( ! ( V_60 == V_63 || V_60 == V_64 ||
V_60 == V_65 || V_60 == V_66 ) )
goto V_67;
F_53 ( & V_55 , V_53 ) ;
V_68:
F_60 (nt, &target_list, list) {
F_9 ( V_8 ) ;
if ( V_8 -> V_15 . V_32 == V_32 ) {
switch ( V_60 ) {
case V_63 :
F_2 ( V_8 -> V_15 . V_17 , V_32 -> V_16 , V_18 ) ;
break;
case V_65 :
case V_66 :
case V_64 :
F_55 ( & V_55 , V_53 ) ;
F_61 ( & V_8 -> V_15 ) ;
F_53 ( & V_55 , V_53 ) ;
F_62 ( V_8 -> V_15 . V_32 ) ;
V_8 -> V_15 . V_32 = NULL ;
V_8 -> V_23 = 0 ;
V_62 = true ;
F_12 ( V_8 ) ;
goto V_68;
}
}
F_12 ( V_8 ) ;
}
F_55 ( & V_55 , V_53 ) ;
if ( V_62 ) {
F_34 ( V_37 L_15
L_16 , V_32 -> V_16 ) ;
switch ( V_60 ) {
case V_64 :
F_34 ( V_69 L_17 ) ;
break;
case V_65 :
F_34 ( V_69 L_18 ) ;
break;
case V_66 :
F_34 ( V_69 L_19 ) ;
break;
}
}
V_67:
return V_70 ;
}
static void F_63 ( struct V_71 * V_72 , const char * V_73 , unsigned int V_38 )
{
int V_74 , V_75 ;
unsigned long V_53 ;
struct V_7 * V_8 ;
const char * V_76 ;
if ( V_77 && ! V_78 )
return;
if ( F_64 ( & V_57 ) )
return;
F_53 ( & V_55 , V_53 ) ;
F_60 (nt, &target_list, list) {
F_9 ( V_8 ) ;
if ( V_8 -> V_23 && F_65 ( V_8 -> V_15 . V_32 ) ) {
V_76 = V_73 ;
for ( V_75 = V_38 ; V_75 ; ) {
V_74 = F_66 ( V_75 , V_79 ) ;
F_67 ( & V_8 -> V_15 , V_76 , V_74 ) ;
V_76 += V_74 ;
V_75 -= V_74 ;
}
}
F_12 ( V_8 ) ;
}
F_55 ( & V_55 , V_53 ) ;
}
static int T_1 F_68 ( void )
{
int V_11 ;
struct V_7 * V_8 , * V_76 ;
unsigned long V_53 ;
char * V_10 ;
char * V_80 = V_2 ;
if ( F_36 ( V_80 , V_3 ) ) {
while ( ( V_10 = F_69 ( & V_80 , L_20 ) ) ) {
V_8 = F_14 ( V_10 ) ;
if ( F_70 ( V_8 ) ) {
V_11 = F_71 ( V_8 ) ;
goto V_14;
}
V_81 . V_53 |= V_82 ;
F_53 ( & V_55 , V_53 ) ;
F_54 ( & V_8 -> V_56 , & V_57 ) ;
F_55 ( & V_55 , V_53 ) ;
}
}
V_11 = F_72 ( & V_83 ) ;
if ( V_11 )
goto V_14;
V_11 = F_3 () ;
if ( V_11 )
goto V_84;
F_73 ( & V_81 ) ;
F_34 ( V_37 L_11 ) ;
return V_11 ;
V_84:
F_74 ( & V_83 ) ;
V_14:
F_34 ( V_39 L_21 ) ;
F_75 (nt, tmp, &target_list, list) {
F_57 ( & V_8 -> V_56 ) ;
F_20 ( V_8 ) ;
}
return V_11 ;
}
static void T_2 F_76 ( void )
{
struct V_7 * V_8 , * V_76 ;
F_77 ( & V_81 ) ;
F_7 () ;
F_74 ( & V_83 ) ;
F_75 (nt, tmp, &target_list, list) {
F_57 ( & V_8 -> V_56 ) ;
F_20 ( V_8 ) ;
}
}

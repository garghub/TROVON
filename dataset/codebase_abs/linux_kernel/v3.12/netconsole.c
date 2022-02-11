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
int V_24 ;
int V_11 ;
V_11 = F_33 ( V_26 , 10 , & V_24 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_24 < 0 || V_24 > 1 )
return - V_37 ;
if ( V_24 == V_8 -> V_24 ) {
F_34 ( V_38 L_8 ,
V_8 -> V_24 ? L_9 : L_10 ) ;
return - V_37 ;
}
F_35 ( & V_8 -> V_21 ) ;
if ( V_24 ) {
F_36 ( & V_8 -> V_15 ) ;
V_11 = F_17 ( & V_8 -> V_15 ) ;
if ( V_11 ) {
F_37 ( & V_8 -> V_21 ) ;
return V_11 ;
}
F_34 ( V_38 L_11 ) ;
} else {
F_21 ( & V_8 -> V_15 ) ;
}
V_8 -> V_24 = V_24 ;
F_37 ( & V_8 -> V_21 ) ;
return F_38 ( V_26 , V_36 ) ;
}
static T_3 F_39 ( struct V_7 * V_8 ,
const char * V_26 ,
T_5 V_36 )
{
T_5 V_39 ;
if ( V_8 -> V_24 ) {
F_34 ( V_40 L_12
L_13 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_37 ;
}
F_2 ( V_8 -> V_15 . V_17 , V_26 , V_18 ) ;
V_39 = F_38 ( V_8 -> V_15 . V_17 , V_18 ) ;
if ( V_8 -> V_15 . V_17 [ V_39 - 1 ] == '\n' )
V_8 -> V_15 . V_17 [ V_39 - 1 ] = '\0' ;
return F_38 ( V_26 , V_36 ) ;
}
static T_3 F_40 ( struct V_7 * V_8 ,
const char * V_26 ,
T_5 V_36 )
{
int V_41 ;
if ( V_8 -> V_24 ) {
F_34 ( V_40 L_12
L_13 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_37 ;
}
V_41 = F_41 ( V_26 , 10 , & V_8 -> V_15 . V_19 ) ;
if ( V_41 < 0 )
return V_41 ;
return F_38 ( V_26 , V_36 ) ;
}
static T_3 F_42 ( struct V_7 * V_8 ,
const char * V_26 ,
T_5 V_36 )
{
int V_41 ;
if ( V_8 -> V_24 ) {
F_34 ( V_40 L_12
L_13 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_37 ;
}
V_41 = F_41 ( V_26 , 10 , & V_8 -> V_15 . V_20 ) ;
if ( V_41 < 0 )
return V_41 ;
return F_38 ( V_26 , V_36 ) ;
}
static T_3 F_43 ( struct V_7 * V_8 ,
const char * V_26 ,
T_5 V_36 )
{
if ( V_8 -> V_24 ) {
F_34 ( V_40 L_12
L_13 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_37 ;
}
if ( F_44 ( V_26 , V_36 , ':' ) ) {
const char * V_42 ;
if ( F_45 ( V_26 , V_36 , V_8 -> V_15 . V_29 . V_30 . V_43 , - 1 , & V_42 ) > 0 ) {
if ( * V_42 && * V_42 != '\n' ) {
F_34 ( V_40 L_14 , * V_42 ) ;
return - V_37 ;
}
V_8 -> V_15 . V_28 = true ;
} else
return - V_37 ;
} else {
if ( ! V_8 -> V_15 . V_28 ) {
V_8 -> V_15 . V_29 . V_44 = F_46 ( V_26 ) ;
} else
return - V_37 ;
}
return F_38 ( V_26 , V_36 ) ;
}
static T_3 F_47 ( struct V_7 * V_8 ,
const char * V_26 ,
T_5 V_36 )
{
if ( V_8 -> V_24 ) {
F_34 ( V_40 L_12
L_13 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_37 ;
}
if ( F_44 ( V_26 , V_36 , ':' ) ) {
const char * V_42 ;
if ( F_45 ( V_26 , V_36 , V_8 -> V_15 . V_31 . V_30 . V_43 , - 1 , & V_42 ) > 0 ) {
if ( * V_42 && * V_42 != '\n' ) {
F_34 ( V_40 L_14 , * V_42 ) ;
return - V_37 ;
}
V_8 -> V_15 . V_28 = true ;
} else
return - V_37 ;
} else {
if ( ! V_8 -> V_15 . V_28 ) {
V_8 -> V_15 . V_31 . V_44 = F_46 ( V_26 ) ;
} else
return - V_37 ;
}
return F_38 ( V_26 , V_36 ) ;
}
static T_3 F_48 ( struct V_7 * V_8 ,
const char * V_26 ,
T_5 V_36 )
{
T_4 V_22 [ V_23 ] ;
if ( V_8 -> V_24 ) {
F_34 ( V_40 L_12
L_13 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_37 ;
}
if ( ! F_49 ( V_26 , V_22 ) )
return - V_37 ;
if ( V_26 [ 3 * V_23 - 1 ] && V_26 [ 3 * V_23 - 1 ] != '\n' )
return - V_37 ;
memcpy ( V_8 -> V_15 . V_22 , V_22 , V_23 ) ;
return F_38 ( V_26 , V_36 ) ;
}
static void F_50 ( struct V_25 * V_9 )
{
F_18 ( F_22 ( V_9 ) ) ;
}
static T_3 F_51 ( struct V_25 * V_9 ,
struct V_45 * V_46 ,
char * V_26 )
{
T_3 V_47 = - V_37 ;
struct V_7 * V_8 = F_22 ( V_9 ) ;
struct V_48 * V_49 =
F_23 ( V_46 , struct V_48 , V_46 ) ;
if ( V_49 -> V_50 )
V_47 = V_49 -> V_50 ( V_8 , V_26 ) ;
return V_47 ;
}
static T_3 F_52 ( struct V_25 * V_9 ,
struct V_45 * V_46 ,
const char * V_26 ,
T_5 V_36 )
{
T_3 V_47 = - V_37 ;
struct V_7 * V_8 = F_22 ( V_9 ) ;
struct V_48 * V_49 =
F_23 ( V_46 , struct V_48 , V_46 ) ;
if ( V_49 -> V_51 )
V_47 = V_49 -> V_51 ( V_8 , V_26 , V_36 ) ;
return V_47 ;
}
static struct V_25 * F_53 ( struct V_52 * V_53 ,
const char * V_16 )
{
unsigned long V_54 ;
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
F_54 ( & V_8 -> V_9 , V_16 , & V_55 ) ;
F_55 ( & V_56 , V_54 ) ;
F_56 ( & V_8 -> V_57 , & V_58 ) ;
F_57 ( & V_56 , V_54 ) ;
return & V_8 -> V_9 ;
}
static void F_58 ( struct V_52 * V_53 ,
struct V_25 * V_9 )
{
unsigned long V_54 ;
struct V_7 * V_8 = F_22 ( V_9 ) ;
F_55 ( & V_56 , V_54 ) ;
F_59 ( & V_8 -> V_57 ) ;
F_57 ( & V_56 , V_54 ) ;
if ( V_8 -> V_24 )
F_21 ( & V_8 -> V_15 ) ;
F_13 ( & V_8 -> V_9 ) ;
}
static int F_60 ( struct V_59 * V_60 ,
unsigned long V_61 , void * V_62 )
{
unsigned long V_54 ;
struct V_7 * V_8 ;
struct V_32 * V_33 = F_61 ( V_62 ) ;
bool V_63 = false ;
if ( ! ( V_61 == V_64 || V_61 == V_65 ||
V_61 == V_66 || V_61 == V_67 ) )
goto V_68;
F_55 ( & V_56 , V_54 ) ;
V_69:
F_62 (nt, &target_list, list) {
F_9 ( V_8 ) ;
if ( V_8 -> V_15 . V_33 == V_33 ) {
switch ( V_61 ) {
case V_64 :
F_2 ( V_8 -> V_15 . V_17 , V_33 -> V_16 , V_18 ) ;
break;
case V_66 :
case V_67 :
case V_65 :
F_57 ( & V_56 , V_54 ) ;
F_63 ( & V_8 -> V_15 ) ;
F_55 ( & V_56 , V_54 ) ;
F_64 ( V_8 -> V_15 . V_33 ) ;
V_8 -> V_15 . V_33 = NULL ;
V_8 -> V_24 = 0 ;
V_63 = true ;
F_12 ( V_8 ) ;
goto V_69;
}
}
F_12 ( V_8 ) ;
}
F_57 ( & V_56 , V_54 ) ;
if ( V_63 ) {
F_34 ( V_38 L_15
L_16 , V_33 -> V_16 ) ;
switch ( V_61 ) {
case V_65 :
F_34 ( V_70 L_17 ) ;
break;
case V_66 :
F_34 ( V_70 L_18 ) ;
break;
case V_67 :
F_34 ( V_70 L_19 ) ;
break;
}
}
V_68:
return V_71 ;
}
static void F_65 ( struct V_72 * V_73 , const char * V_74 , unsigned int V_39 )
{
int V_75 , V_76 ;
unsigned long V_54 ;
struct V_7 * V_8 ;
const char * V_77 ;
if ( V_78 && ! V_79 )
return;
if ( F_66 ( & V_58 ) )
return;
F_55 ( & V_56 , V_54 ) ;
F_62 (nt, &target_list, list) {
F_9 ( V_8 ) ;
if ( V_8 -> V_24 && F_67 ( V_8 -> V_15 . V_33 ) ) {
V_77 = V_74 ;
for ( V_76 = V_39 ; V_76 ; ) {
V_75 = F_68 ( V_76 , V_80 ) ;
F_69 ( & V_8 -> V_15 , V_77 , V_75 ) ;
V_77 += V_75 ;
V_76 -= V_75 ;
}
}
F_12 ( V_8 ) ;
}
F_57 ( & V_56 , V_54 ) ;
}
static int T_1 F_70 ( void )
{
int V_11 ;
struct V_7 * V_8 , * V_77 ;
unsigned long V_54 ;
char * V_10 ;
char * V_81 = V_2 ;
if ( F_38 ( V_81 , V_3 ) ) {
while ( ( V_10 = F_71 ( & V_81 , L_20 ) ) ) {
V_8 = F_14 ( V_10 ) ;
if ( F_72 ( V_8 ) ) {
V_11 = F_73 ( V_8 ) ;
goto V_14;
}
V_82 . V_54 |= V_83 ;
F_55 ( & V_56 , V_54 ) ;
F_56 ( & V_8 -> V_57 , & V_58 ) ;
F_57 ( & V_56 , V_54 ) ;
}
}
V_11 = F_74 ( & V_84 ) ;
if ( V_11 )
goto V_14;
V_11 = F_3 () ;
if ( V_11 )
goto V_85;
F_75 ( & V_82 ) ;
F_34 ( V_38 L_11 ) ;
return V_11 ;
V_85:
F_76 ( & V_84 ) ;
V_14:
F_34 ( V_40 L_21 ) ;
F_77 (nt, tmp, &target_list, list) {
F_59 ( & V_8 -> V_57 ) ;
F_20 ( V_8 ) ;
}
return V_11 ;
}
static void T_2 F_78 ( void )
{
struct V_7 * V_8 , * V_77 ;
F_79 ( & V_82 ) ;
F_7 () ;
F_76 ( & V_84 ) ;
F_77 (nt, tmp, &target_list, list) {
F_59 ( & V_8 -> V_57 ) ;
F_20 ( V_8 ) ;
}
}

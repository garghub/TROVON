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
return snprintf ( V_25 , V_26 , L_5 , & V_8 -> V_15 . V_27 ) ;
}
static T_3 F_29 ( struct V_7 * V_8 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_5 , & V_8 -> V_15 . V_28 ) ;
}
static T_3 F_30 ( struct V_7 * V_8 , char * V_25 )
{
struct V_29 * V_30 = V_8 -> V_15 . V_30 ;
static const T_4 V_31 [ V_22 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
return snprintf ( V_25 , V_26 , L_6 , V_30 ? V_30 -> V_32 : V_31 ) ;
}
static T_3 F_31 ( struct V_7 * V_8 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_6 , V_8 -> V_15 . V_21 ) ;
}
static T_3 F_32 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_33 )
{
int V_23 ;
int V_11 ;
V_11 = F_33 ( V_25 , 10 , & V_23 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_23 < 0 || V_23 > 1 )
return - V_34 ;
if ( V_23 == V_8 -> V_23 ) {
F_34 ( V_35 L_7 ,
V_8 -> V_23 ? L_8 : L_9 ) ;
return - V_34 ;
}
if ( V_23 ) {
F_35 ( & V_8 -> V_15 ) ;
V_11 = F_17 ( & V_8 -> V_15 ) ;
if ( V_11 )
return V_11 ;
F_34 ( V_35 L_10 ) ;
} else {
F_21 ( & V_8 -> V_15 ) ;
}
V_8 -> V_23 = V_23 ;
return F_36 ( V_25 , V_33 ) ;
}
static T_3 F_37 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_33 )
{
T_5 V_36 ;
if ( V_8 -> V_23 ) {
F_34 ( V_37 L_11
L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_34 ;
}
F_2 ( V_8 -> V_15 . V_17 , V_25 , V_18 ) ;
V_36 = F_36 ( V_8 -> V_15 . V_17 , V_18 ) ;
if ( V_8 -> V_15 . V_17 [ V_36 - 1 ] == '\n' )
V_8 -> V_15 . V_17 [ V_36 - 1 ] = '\0' ;
return F_36 ( V_25 , V_33 ) ;
}
static T_3 F_38 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_33 )
{
int V_38 ;
if ( V_8 -> V_23 ) {
F_34 ( V_37 L_11
L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_34 ;
}
V_38 = F_39 ( V_25 , 10 , & V_8 -> V_15 . V_19 ) ;
if ( V_38 < 0 )
return V_38 ;
return F_36 ( V_25 , V_33 ) ;
}
static T_3 F_40 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_33 )
{
int V_38 ;
if ( V_8 -> V_23 ) {
F_34 ( V_37 L_11
L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_34 ;
}
V_38 = F_39 ( V_25 , 10 , & V_8 -> V_15 . V_20 ) ;
if ( V_38 < 0 )
return V_38 ;
return F_36 ( V_25 , V_33 ) ;
}
static T_3 F_41 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_33 )
{
if ( V_8 -> V_23 ) {
F_34 ( V_37 L_11
L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_34 ;
}
V_8 -> V_15 . V_27 = F_42 ( V_25 ) ;
return F_36 ( V_25 , V_33 ) ;
}
static T_3 F_43 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_33 )
{
if ( V_8 -> V_23 ) {
F_34 ( V_37 L_11
L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_34 ;
}
V_8 -> V_15 . V_28 = F_42 ( V_25 ) ;
return F_36 ( V_25 , V_33 ) ;
}
static T_3 F_44 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_33 )
{
T_4 V_21 [ V_22 ] ;
if ( V_8 -> V_23 ) {
F_34 ( V_37 L_11
L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_34 ;
}
if ( ! F_45 ( V_25 , V_21 ) )
return - V_34 ;
if ( V_25 [ 3 * V_22 - 1 ] && V_25 [ 3 * V_22 - 1 ] != '\n' )
return - V_34 ;
memcpy ( V_8 -> V_15 . V_21 , V_21 , V_22 ) ;
return F_36 ( V_25 , V_33 ) ;
}
static void F_46 ( struct V_24 * V_9 )
{
F_18 ( F_22 ( V_9 ) ) ;
}
static T_3 F_47 ( struct V_24 * V_9 ,
struct V_39 * V_40 ,
char * V_25 )
{
T_3 V_41 = - V_34 ;
struct V_7 * V_8 = F_22 ( V_9 ) ;
struct V_42 * V_43 =
F_23 ( V_40 , struct V_42 , V_40 ) ;
if ( V_43 -> V_44 )
V_41 = V_43 -> V_44 ( V_8 , V_25 ) ;
return V_41 ;
}
static T_3 F_48 ( struct V_24 * V_9 ,
struct V_39 * V_40 ,
const char * V_25 ,
T_5 V_33 )
{
T_3 V_41 = - V_34 ;
struct V_7 * V_8 = F_22 ( V_9 ) ;
struct V_42 * V_43 =
F_23 ( V_40 , struct V_42 , V_40 ) ;
if ( V_43 -> V_45 )
V_41 = V_43 -> V_45 ( V_8 , V_25 , V_33 ) ;
return V_41 ;
}
static struct V_24 * F_49 ( struct V_46 * V_47 ,
const char * V_16 )
{
unsigned long V_48 ;
struct V_7 * V_8 ;
V_8 = F_15 ( sizeof( * V_8 ) , V_13 ) ;
if ( ! V_8 )
return F_19 ( - V_12 ) ;
V_8 -> V_15 . V_16 = L_1 ;
F_2 ( V_8 -> V_15 . V_17 , L_2 , V_18 ) ;
V_8 -> V_15 . V_19 = 6665 ;
V_8 -> V_15 . V_20 = 6666 ;
memset ( V_8 -> V_15 . V_21 , 0xff , V_22 ) ;
F_50 ( & V_8 -> V_9 , V_16 , & V_49 ) ;
F_51 ( & V_50 , V_48 ) ;
F_52 ( & V_8 -> V_51 , & V_52 ) ;
F_53 ( & V_50 , V_48 ) ;
return & V_8 -> V_9 ;
}
static void F_54 ( struct V_46 * V_47 ,
struct V_24 * V_9 )
{
unsigned long V_48 ;
struct V_7 * V_8 = F_22 ( V_9 ) ;
F_51 ( & V_50 , V_48 ) ;
F_55 ( & V_8 -> V_51 ) ;
F_53 ( & V_50 , V_48 ) ;
if ( V_8 -> V_23 )
F_21 ( & V_8 -> V_15 ) ;
F_13 ( & V_8 -> V_9 ) ;
}
static int F_56 ( struct V_53 * V_54 ,
unsigned long V_55 ,
void * V_56 )
{
unsigned long V_48 ;
struct V_7 * V_8 ;
struct V_29 * V_30 = V_56 ;
bool V_57 = false ;
if ( ! ( V_55 == V_58 || V_55 == V_59 ||
V_55 == V_60 || V_55 == V_61 ) )
goto V_62;
F_51 ( & V_50 , V_48 ) ;
F_57 (nt, &target_list, list) {
F_9 ( V_8 ) ;
if ( V_8 -> V_15 . V_30 == V_30 ) {
switch ( V_55 ) {
case V_58 :
F_2 ( V_8 -> V_15 . V_17 , V_30 -> V_16 , V_18 ) ;
break;
case V_60 :
case V_61 :
case V_59 :
if ( V_8 -> V_15 . V_30 ) {
F_58 ( & V_8 -> V_15 ) ;
F_59 ( V_8 -> V_15 . V_30 ) ;
V_8 -> V_15 . V_30 = NULL ;
}
V_8 -> V_23 = 0 ;
V_57 = true ;
break;
}
}
F_12 ( V_8 ) ;
}
F_53 ( & V_50 , V_48 ) ;
if ( V_57 ) {
F_34 ( V_35 L_13
L_14 , V_30 -> V_16 ) ;
switch ( V_55 ) {
case V_59 :
F_34 ( V_63 L_15 ) ;
break;
case V_60 :
F_34 ( V_63 L_16 ) ;
break;
case V_61 :
F_34 ( V_63 L_17 ) ;
break;
}
}
V_62:
return V_64 ;
}
static void F_60 ( struct V_65 * V_66 , const char * V_67 , unsigned int V_36 )
{
int V_68 , V_69 ;
unsigned long V_48 ;
struct V_7 * V_8 ;
const char * V_70 ;
if ( F_61 ( & V_52 ) )
return;
F_51 ( & V_50 , V_48 ) ;
F_57 (nt, &target_list, list) {
F_9 ( V_8 ) ;
if ( V_8 -> V_23 && F_62 ( V_8 -> V_15 . V_30 ) ) {
V_70 = V_67 ;
for ( V_69 = V_36 ; V_69 ; ) {
V_68 = F_63 ( V_69 , V_71 ) ;
F_64 ( & V_8 -> V_15 , V_70 , V_68 ) ;
V_70 += V_68 ;
V_69 -= V_68 ;
}
}
F_12 ( V_8 ) ;
}
F_53 ( & V_50 , V_48 ) ;
}
static int T_1 F_65 ( void )
{
int V_11 ;
struct V_7 * V_8 , * V_70 ;
unsigned long V_48 ;
char * V_10 ;
char * V_72 = V_2 ;
if ( F_36 ( V_72 , V_3 ) ) {
while ( ( V_10 = F_66 ( & V_72 , L_18 ) ) ) {
V_8 = F_14 ( V_10 ) ;
if ( F_67 ( V_8 ) ) {
V_11 = F_68 ( V_8 ) ;
goto V_14;
}
V_73 . V_48 |= V_74 ;
F_51 ( & V_50 , V_48 ) ;
F_52 ( & V_8 -> V_51 , & V_52 ) ;
F_53 ( & V_50 , V_48 ) ;
}
}
V_11 = F_69 ( & V_75 ) ;
if ( V_11 )
goto V_14;
V_11 = F_3 () ;
if ( V_11 )
goto V_76;
F_70 ( & V_73 ) ;
F_34 ( V_35 L_10 ) ;
return V_11 ;
V_76:
F_71 ( & V_75 ) ;
V_14:
F_34 ( V_37 L_19 ) ;
F_72 (nt, tmp, &target_list, list) {
F_55 ( & V_8 -> V_51 ) ;
F_20 ( V_8 ) ;
}
return V_11 ;
}
static void T_2 F_73 ( void )
{
struct V_7 * V_8 , * V_70 ;
F_74 ( & V_73 ) ;
F_7 () ;
F_71 ( & V_75 ) ;
F_72 (nt, tmp, &target_list, list) {
F_55 ( & V_8 -> V_51 ) ;
F_20 ( V_8 ) ;
}
}

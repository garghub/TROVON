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
F_16 ( V_8 -> V_15 . V_21 ) ;
if ( * V_10 == '+' ) {
V_8 -> V_22 = true ;
V_10 ++ ;
}
V_11 = F_17 ( & V_8 -> V_15 , V_10 ) ;
if ( V_11 )
goto V_14;
V_11 = F_18 ( & V_8 -> V_15 ) ;
if ( V_11 )
goto V_14;
V_8 -> V_23 = true ;
return V_8 ;
V_14:
F_19 ( V_8 ) ;
return F_20 ( V_11 ) ;
}
static void F_21 ( struct V_7 * V_8 )
{
F_22 ( & V_8 -> V_15 ) ;
F_19 ( V_8 ) ;
}
static struct V_7 * F_23 ( struct V_24 * V_9 )
{
return V_9 ?
F_24 ( V_9 , struct V_7 , V_9 ) :
NULL ;
}
static T_3 F_25 ( struct V_7 * V_8 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_3 , V_8 -> V_23 ) ;
}
static T_3 F_26 ( struct V_7 * V_8 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_3 , V_8 -> V_22 ) ;
}
static T_3 F_27 ( struct V_7 * V_8 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_4 , V_8 -> V_15 . V_17 ) ;
}
static T_3 F_28 ( struct V_7 * V_8 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_3 , V_8 -> V_15 . V_19 ) ;
}
static T_3 F_29 ( struct V_7 * V_8 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_3 , V_8 -> V_15 . V_20 ) ;
}
static T_3 F_30 ( struct V_7 * V_8 , char * V_25 )
{
if ( V_8 -> V_15 . V_27 )
return snprintf ( V_25 , V_26 , L_5 , & V_8 -> V_15 . V_28 . V_29 ) ;
else
return snprintf ( V_25 , V_26 , L_6 , & V_8 -> V_15 . V_28 ) ;
}
static T_3 F_31 ( struct V_7 * V_8 , char * V_25 )
{
if ( V_8 -> V_15 . V_27 )
return snprintf ( V_25 , V_26 , L_5 , & V_8 -> V_15 . V_30 . V_29 ) ;
else
return snprintf ( V_25 , V_26 , L_6 , & V_8 -> V_15 . V_30 ) ;
}
static T_3 F_32 ( struct V_7 * V_8 , char * V_25 )
{
struct V_31 * V_32 = V_8 -> V_15 . V_32 ;
static const T_4 V_33 [ V_34 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
return snprintf ( V_25 , V_26 , L_7 , V_32 ? V_32 -> V_35 : V_33 ) ;
}
static T_3 F_33 ( struct V_7 * V_8 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_7 , V_8 -> V_15 . V_21 ) ;
}
static T_3 F_34 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_36 )
{
unsigned long V_37 ;
int V_23 ;
int V_11 ;
V_11 = F_35 ( V_25 , 10 , & V_23 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_23 < 0 || V_23 > 1 )
return - V_38 ;
if ( ( bool ) V_23 == V_8 -> V_23 ) {
F_36 ( L_8 ,
V_8 -> V_23 ? L_9 : L_10 ) ;
return - V_38 ;
}
if ( V_23 ) {
if ( V_8 -> V_22 && ! ( V_39 . V_37 & V_40 ) ) {
V_39 . V_37 |= V_40 ;
F_37 ( & V_39 ) ;
}
F_38 ( & V_8 -> V_15 ) ;
V_11 = F_18 ( & V_8 -> V_15 ) ;
if ( V_11 )
return V_11 ;
F_36 ( L_11 ) ;
} else {
F_39 ( & V_41 , V_37 ) ;
V_8 -> V_23 = false ;
F_40 ( & V_41 , V_37 ) ;
F_22 ( & V_8 -> V_15 ) ;
}
V_8 -> V_23 = V_23 ;
return F_41 ( V_25 , V_36 ) ;
}
static T_3 F_42 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_36 )
{
int V_22 ;
int V_11 ;
if ( V_8 -> V_23 ) {
F_43 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_38 ;
}
V_11 = F_35 ( V_25 , 10 , & V_22 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_22 < 0 || V_22 > 1 )
return - V_38 ;
V_8 -> V_22 = V_22 ;
return F_41 ( V_25 , V_36 ) ;
}
static T_3 F_44 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_36 )
{
T_5 V_42 ;
if ( V_8 -> V_23 ) {
F_43 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_38 ;
}
F_2 ( V_8 -> V_15 . V_17 , V_25 , V_18 ) ;
V_42 = F_41 ( V_8 -> V_15 . V_17 , V_18 ) ;
if ( V_8 -> V_15 . V_17 [ V_42 - 1 ] == '\n' )
V_8 -> V_15 . V_17 [ V_42 - 1 ] = '\0' ;
return F_41 ( V_25 , V_36 ) ;
}
static T_3 F_45 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_36 )
{
int V_43 ;
if ( V_8 -> V_23 ) {
F_43 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_38 ;
}
V_43 = F_46 ( V_25 , 10 , & V_8 -> V_15 . V_19 ) ;
if ( V_43 < 0 )
return V_43 ;
return F_41 ( V_25 , V_36 ) ;
}
static T_3 F_47 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_36 )
{
int V_43 ;
if ( V_8 -> V_23 ) {
F_43 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_38 ;
}
V_43 = F_46 ( V_25 , 10 , & V_8 -> V_15 . V_20 ) ;
if ( V_43 < 0 )
return V_43 ;
return F_41 ( V_25 , V_36 ) ;
}
static T_3 F_48 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_36 )
{
if ( V_8 -> V_23 ) {
F_43 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_38 ;
}
if ( F_49 ( V_25 , V_36 , ':' ) ) {
const char * V_44 ;
if ( F_50 ( V_25 , V_36 , V_8 -> V_15 . V_28 . V_29 . V_45 , - 1 , & V_44 ) > 0 ) {
if ( * V_44 && * V_44 != '\n' ) {
F_43 ( L_13 , * V_44 ) ;
return - V_38 ;
}
V_8 -> V_15 . V_27 = true ;
} else
return - V_38 ;
} else {
if ( ! V_8 -> V_15 . V_27 ) {
V_8 -> V_15 . V_28 . V_46 = F_51 ( V_25 ) ;
} else
return - V_38 ;
}
return F_41 ( V_25 , V_36 ) ;
}
static T_3 F_52 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_36 )
{
if ( V_8 -> V_23 ) {
F_43 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_38 ;
}
if ( F_49 ( V_25 , V_36 , ':' ) ) {
const char * V_44 ;
if ( F_50 ( V_25 , V_36 , V_8 -> V_15 . V_30 . V_29 . V_45 , - 1 , & V_44 ) > 0 ) {
if ( * V_44 && * V_44 != '\n' ) {
F_43 ( L_13 , * V_44 ) ;
return - V_38 ;
}
V_8 -> V_15 . V_27 = true ;
} else
return - V_38 ;
} else {
if ( ! V_8 -> V_15 . V_27 ) {
V_8 -> V_15 . V_30 . V_46 = F_51 ( V_25 ) ;
} else
return - V_38 ;
}
return F_41 ( V_25 , V_36 ) ;
}
static T_3 F_53 ( struct V_7 * V_8 ,
const char * V_25 ,
T_5 V_36 )
{
T_4 V_21 [ V_34 ] ;
if ( V_8 -> V_23 ) {
F_43 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
return - V_38 ;
}
if ( ! F_54 ( V_25 , V_21 ) )
return - V_38 ;
if ( V_25 [ 3 * V_34 - 1 ] && V_25 [ 3 * V_34 - 1 ] != '\n' )
return - V_38 ;
memcpy ( V_8 -> V_15 . V_21 , V_21 , V_34 ) ;
return F_41 ( V_25 , V_36 ) ;
}
static void F_55 ( struct V_24 * V_9 )
{
F_19 ( F_23 ( V_9 ) ) ;
}
static T_3 F_56 ( struct V_24 * V_9 ,
struct V_47 * V_48 ,
char * V_25 )
{
T_3 V_49 = - V_38 ;
struct V_7 * V_8 = F_23 ( V_9 ) ;
struct V_50 * V_51 =
F_24 ( V_48 , struct V_50 , V_48 ) ;
if ( V_51 -> V_52 )
V_49 = V_51 -> V_52 ( V_8 , V_25 ) ;
return V_49 ;
}
static T_3 F_57 ( struct V_24 * V_9 ,
struct V_47 * V_48 ,
const char * V_25 ,
T_5 V_36 )
{
T_3 V_49 = - V_38 ;
struct V_7 * V_8 = F_23 ( V_9 ) ;
struct V_50 * V_51 =
F_24 ( V_48 , struct V_50 , V_48 ) ;
F_58 ( & V_53 ) ;
if ( V_51 -> V_54 )
V_49 = V_51 -> V_54 ( V_8 , V_25 , V_36 ) ;
F_59 ( & V_53 ) ;
return V_49 ;
}
static struct V_24 * F_60 ( struct V_55 * V_56 ,
const char * V_16 )
{
unsigned long V_37 ;
struct V_7 * V_8 ;
V_8 = F_15 ( sizeof( * V_8 ) , V_13 ) ;
if ( ! V_8 )
return F_20 ( - V_12 ) ;
V_8 -> V_15 . V_16 = L_1 ;
F_2 ( V_8 -> V_15 . V_17 , L_2 , V_18 ) ;
V_8 -> V_15 . V_19 = 6665 ;
V_8 -> V_15 . V_20 = 6666 ;
F_16 ( V_8 -> V_15 . V_21 ) ;
F_61 ( & V_8 -> V_9 , V_16 , & V_57 ) ;
F_39 ( & V_41 , V_37 ) ;
F_62 ( & V_8 -> V_58 , & V_59 ) ;
F_40 ( & V_41 , V_37 ) ;
return & V_8 -> V_9 ;
}
static void F_63 ( struct V_55 * V_56 ,
struct V_24 * V_9 )
{
unsigned long V_37 ;
struct V_7 * V_8 = F_23 ( V_9 ) ;
F_39 ( & V_41 , V_37 ) ;
F_64 ( & V_8 -> V_58 ) ;
F_40 ( & V_41 , V_37 ) ;
if ( V_8 -> V_23 )
F_22 ( & V_8 -> V_15 ) ;
F_13 ( & V_8 -> V_9 ) ;
}
static int F_65 ( struct V_60 * V_61 ,
unsigned long V_62 , void * V_63 )
{
unsigned long V_37 ;
struct V_7 * V_8 ;
struct V_31 * V_32 = F_66 ( V_63 ) ;
bool V_64 = false ;
if ( ! ( V_62 == V_65 || V_62 == V_66 ||
V_62 == V_67 || V_62 == V_68 ) )
goto V_69;
F_39 ( & V_41 , V_37 ) ;
V_70:
F_67 (nt, &target_list, list) {
F_9 ( V_8 ) ;
if ( V_8 -> V_15 . V_32 == V_32 ) {
switch ( V_62 ) {
case V_65 :
F_2 ( V_8 -> V_15 . V_17 , V_32 -> V_16 , V_18 ) ;
break;
case V_67 :
case V_68 :
case V_66 :
F_40 ( & V_41 , V_37 ) ;
F_68 ( & V_8 -> V_15 ) ;
F_39 ( & V_41 , V_37 ) ;
F_69 ( V_8 -> V_15 . V_32 ) ;
V_8 -> V_15 . V_32 = NULL ;
V_8 -> V_23 = false ;
V_64 = true ;
F_12 ( V_8 ) ;
goto V_70;
}
}
F_12 ( V_8 ) ;
}
F_40 ( & V_41 , V_37 ) ;
if ( V_64 ) {
const char * V_71 = L_14 ;
switch ( V_62 ) {
case V_66 :
V_71 = L_15 ;
break;
case V_67 :
V_71 = L_16 ;
break;
case V_68 :
V_71 = L_17 ;
break;
}
F_36 ( L_18 ,
V_32 -> V_16 , V_71 ) ;
}
V_69:
return V_72 ;
}
static void F_70 ( struct V_7 * V_8 , const char * V_71 ,
int V_73 )
{
static char V_25 [ V_74 ] ;
const char * V_75 , * V_76 ;
int V_77 = 0 ;
int V_78 , V_79 ;
if ( V_73 <= V_74 ) {
F_71 ( & V_8 -> V_15 , V_71 , V_73 ) ;
return;
}
V_75 = V_71 ;
V_76 = memchr ( V_71 , ';' , V_73 ) ;
if ( F_72 ( ! V_76 ) )
return;
V_78 = V_76 - V_75 ;
V_79 = V_73 - V_78 - 1 ;
V_76 ++ ;
memcpy ( V_25 , V_75 , V_78 ) ;
while ( V_77 < V_79 ) {
int V_80 = V_78 ;
int V_81 ;
V_80 += F_73 ( V_25 + V_80 ,
sizeof( V_25 ) - V_80 ,
L_19 , V_77 , V_79 ) ;
V_81 = F_74 ( V_79 - V_77 ,
V_74 - V_80 ) ;
if ( F_72 ( V_81 <= 0 ) )
return;
memcpy ( V_25 + V_80 , V_76 + V_77 , V_81 ) ;
F_71 ( & V_8 -> V_15 , V_25 , V_80 + V_81 ) ;
V_77 += V_81 ;
}
}
static void F_75 ( struct V_82 * V_83 , const char * V_71 ,
unsigned int V_42 )
{
struct V_7 * V_8 ;
unsigned long V_37 ;
if ( ( V_84 && ! V_85 ) || F_76 ( & V_59 ) )
return;
F_39 ( & V_41 , V_37 ) ;
F_67 (nt, &target_list, list)
if ( V_8 -> V_22 && V_8 -> V_23 && F_77 ( V_8 -> V_15 . V_32 ) )
F_70 ( V_8 , V_71 , V_42 ) ;
F_40 ( & V_41 , V_37 ) ;
}
static void F_78 ( struct V_82 * V_83 , const char * V_71 , unsigned int V_42 )
{
int V_86 , V_87 ;
unsigned long V_37 ;
struct V_7 * V_8 ;
const char * V_88 ;
if ( V_84 && ! V_85 )
return;
if ( F_76 ( & V_59 ) )
return;
F_39 ( & V_41 , V_37 ) ;
F_67 (nt, &target_list, list) {
if ( ! V_8 -> V_22 && V_8 -> V_23 && F_77 ( V_8 -> V_15 . V_32 ) ) {
V_88 = V_71 ;
for ( V_87 = V_42 ; V_87 ; ) {
V_86 = F_74 ( V_87 , V_74 ) ;
F_71 ( & V_8 -> V_15 , V_88 , V_86 ) ;
V_88 += V_86 ;
V_87 -= V_86 ;
}
}
}
F_40 ( & V_41 , V_37 ) ;
}
static int T_1 F_79 ( void )
{
int V_11 ;
struct V_7 * V_8 , * V_88 ;
unsigned long V_37 ;
char * V_10 ;
char * V_89 = V_2 ;
if ( F_41 ( V_89 , V_3 ) ) {
while ( ( V_10 = F_80 ( & V_89 , L_20 ) ) ) {
V_8 = F_14 ( V_10 ) ;
if ( F_81 ( V_8 ) ) {
V_11 = F_82 ( V_8 ) ;
goto V_14;
}
if ( V_8 -> V_22 )
V_39 . V_37 |= V_90 |
V_40 ;
else
V_91 . V_37 |= V_90 ;
F_39 ( & V_41 , V_37 ) ;
F_62 ( & V_8 -> V_58 , & V_59 ) ;
F_40 ( & V_41 , V_37 ) ;
}
}
V_11 = F_83 ( & V_92 ) ;
if ( V_11 )
goto V_14;
V_11 = F_3 () ;
if ( V_11 )
goto V_93;
if ( V_39 . V_37 & V_40 )
F_37 ( & V_39 ) ;
F_37 ( & V_91 ) ;
F_36 ( L_21 ) ;
return V_11 ;
V_93:
F_84 ( & V_92 ) ;
V_14:
F_43 ( L_22 ) ;
F_85 (nt, tmp, &target_list, list) {
F_64 ( & V_8 -> V_58 ) ;
F_21 ( V_8 ) ;
}
return V_11 ;
}
static void T_2 F_86 ( void )
{
struct V_7 * V_8 , * V_88 ;
F_87 ( & V_39 ) ;
F_87 ( & V_91 ) ;
F_7 () ;
F_84 ( & V_92 ) ;
F_85 (nt, tmp, &target_list, list) {
F_64 ( & V_8 -> V_58 ) ;
F_21 ( V_8 ) ;
}
}

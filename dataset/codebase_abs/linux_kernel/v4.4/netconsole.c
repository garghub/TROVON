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
static T_3 F_25 ( struct V_24 * V_9 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_3 , F_23 ( V_9 ) -> V_23 ) ;
}
static T_3 F_26 ( struct V_24 * V_9 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_3 , F_23 ( V_9 ) -> V_22 ) ;
}
static T_3 F_27 ( struct V_24 * V_9 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_4 , F_23 ( V_9 ) -> V_15 . V_17 ) ;
}
static T_3 F_28 ( struct V_24 * V_9 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_3 , F_23 ( V_9 ) -> V_15 . V_19 ) ;
}
static T_3 F_29 ( struct V_24 * V_9 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_3 , F_23 ( V_9 ) -> V_15 . V_20 ) ;
}
static T_3 F_30 ( struct V_24 * V_9 , char * V_25 )
{
struct V_7 * V_8 = F_23 ( V_9 ) ;
if ( V_8 -> V_15 . V_27 )
return snprintf ( V_25 , V_26 , L_5 , & V_8 -> V_15 . V_28 . V_29 ) ;
else
return snprintf ( V_25 , V_26 , L_6 , & V_8 -> V_15 . V_28 ) ;
}
static T_3 F_31 ( struct V_24 * V_9 , char * V_25 )
{
struct V_7 * V_8 = F_23 ( V_9 ) ;
if ( V_8 -> V_15 . V_27 )
return snprintf ( V_25 , V_26 , L_5 , & V_8 -> V_15 . V_30 . V_29 ) ;
else
return snprintf ( V_25 , V_26 , L_6 , & V_8 -> V_15 . V_30 ) ;
}
static T_3 F_32 ( struct V_24 * V_9 , char * V_25 )
{
struct V_31 * V_32 = F_23 ( V_9 ) -> V_15 . V_32 ;
static const T_4 V_33 [ V_34 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
return snprintf ( V_25 , V_26 , L_7 , V_32 ? V_32 -> V_35 : V_33 ) ;
}
static T_3 F_33 ( struct V_24 * V_9 , char * V_25 )
{
return snprintf ( V_25 , V_26 , L_7 , F_23 ( V_9 ) -> V_15 . V_21 ) ;
}
static T_3 F_34 ( struct V_24 * V_9 ,
const char * V_25 , T_5 V_36 )
{
struct V_7 * V_8 = F_23 ( V_9 ) ;
unsigned long V_37 ;
int V_23 ;
int V_11 ;
F_35 ( & V_38 ) ;
V_11 = F_36 ( V_25 , 10 , & V_23 ) ;
if ( V_11 < 0 )
goto V_39;
V_11 = - V_40 ;
if ( V_23 < 0 || V_23 > 1 )
goto V_39;
if ( ( bool ) V_23 == V_8 -> V_23 ) {
F_37 ( L_8 ,
V_8 -> V_23 ? L_9 : L_10 ) ;
goto V_39;
}
if ( V_23 ) {
if ( V_8 -> V_22 && ! ( V_41 . V_37 & V_42 ) ) {
V_41 . V_37 |= V_42 ;
F_38 ( & V_41 ) ;
}
F_39 ( & V_8 -> V_15 ) ;
V_11 = F_18 ( & V_8 -> V_15 ) ;
if ( V_11 )
goto V_39;
F_37 ( L_11 ) ;
} else {
F_40 ( & V_43 , V_37 ) ;
V_8 -> V_23 = false ;
F_41 ( & V_43 , V_37 ) ;
F_22 ( & V_8 -> V_15 ) ;
}
V_8 -> V_23 = V_23 ;
F_42 ( & V_38 ) ;
return F_43 ( V_25 , V_36 ) ;
V_39:
F_42 ( & V_38 ) ;
return V_11 ;
}
static T_3 F_44 ( struct V_24 * V_9 , const char * V_25 ,
T_5 V_36 )
{
struct V_7 * V_8 = F_23 ( V_9 ) ;
int V_22 ;
int V_11 ;
F_35 ( & V_38 ) ;
if ( V_8 -> V_23 ) {
F_45 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
V_11 = - V_40 ;
goto V_39;
}
V_11 = F_36 ( V_25 , 10 , & V_22 ) ;
if ( V_11 < 0 )
goto V_39;
if ( V_22 < 0 || V_22 > 1 ) {
V_11 = - V_40 ;
goto V_39;
}
V_8 -> V_22 = V_22 ;
F_42 ( & V_38 ) ;
return F_43 ( V_25 , V_36 ) ;
V_39:
F_42 ( & V_38 ) ;
return V_11 ;
}
static T_3 F_46 ( struct V_24 * V_9 , const char * V_25 ,
T_5 V_36 )
{
struct V_7 * V_8 = F_23 ( V_9 ) ;
T_5 V_44 ;
F_35 ( & V_38 ) ;
if ( V_8 -> V_23 ) {
F_45 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
F_42 ( & V_38 ) ;
return - V_40 ;
}
F_2 ( V_8 -> V_15 . V_17 , V_25 , V_18 ) ;
V_44 = F_43 ( V_8 -> V_15 . V_17 , V_18 ) ;
if ( V_8 -> V_15 . V_17 [ V_44 - 1 ] == '\n' )
V_8 -> V_15 . V_17 [ V_44 - 1 ] = '\0' ;
F_42 ( & V_38 ) ;
return F_43 ( V_25 , V_36 ) ;
}
static T_3 F_47 ( struct V_24 * V_9 , const char * V_25 ,
T_5 V_36 )
{
struct V_7 * V_8 = F_23 ( V_9 ) ;
int V_45 = - V_40 ;
F_35 ( & V_38 ) ;
if ( V_8 -> V_23 ) {
F_45 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
goto V_39;
}
V_45 = F_48 ( V_25 , 10 , & V_8 -> V_15 . V_19 ) ;
if ( V_45 < 0 )
goto V_39;
F_42 ( & V_38 ) ;
return F_43 ( V_25 , V_36 ) ;
V_39:
F_42 ( & V_38 ) ;
return V_45 ;
}
static T_3 F_49 ( struct V_24 * V_9 ,
const char * V_25 , T_5 V_36 )
{
struct V_7 * V_8 = F_23 ( V_9 ) ;
int V_45 = - V_40 ;
F_35 ( & V_38 ) ;
if ( V_8 -> V_23 ) {
F_45 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
goto V_39;
}
V_45 = F_48 ( V_25 , 10 , & V_8 -> V_15 . V_20 ) ;
if ( V_45 < 0 )
goto V_39;
F_42 ( & V_38 ) ;
return F_43 ( V_25 , V_36 ) ;
V_39:
F_42 ( & V_38 ) ;
return V_45 ;
}
static T_3 F_50 ( struct V_24 * V_9 , const char * V_25 ,
T_5 V_36 )
{
struct V_7 * V_8 = F_23 ( V_9 ) ;
F_35 ( & V_38 ) ;
if ( V_8 -> V_23 ) {
F_45 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
goto V_39;
}
if ( F_51 ( V_25 , V_36 , ':' ) ) {
const char * V_46 ;
if ( F_52 ( V_25 , V_36 , V_8 -> V_15 . V_28 . V_29 . V_47 , - 1 , & V_46 ) > 0 ) {
if ( * V_46 && * V_46 != '\n' ) {
F_45 ( L_13 , * V_46 ) ;
goto V_39;
}
V_8 -> V_15 . V_27 = true ;
} else
goto V_39;
} else {
if ( ! V_8 -> V_15 . V_27 ) {
V_8 -> V_15 . V_28 . V_48 = F_53 ( V_25 ) ;
} else
goto V_39;
}
F_42 ( & V_38 ) ;
return F_43 ( V_25 , V_36 ) ;
V_39:
F_42 ( & V_38 ) ;
return - V_40 ;
}
static T_3 F_54 ( struct V_24 * V_9 , const char * V_25 ,
T_5 V_36 )
{
struct V_7 * V_8 = F_23 ( V_9 ) ;
F_35 ( & V_38 ) ;
if ( V_8 -> V_23 ) {
F_45 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
goto V_39;
}
if ( F_51 ( V_25 , V_36 , ':' ) ) {
const char * V_46 ;
if ( F_52 ( V_25 , V_36 , V_8 -> V_15 . V_30 . V_29 . V_47 , - 1 , & V_46 ) > 0 ) {
if ( * V_46 && * V_46 != '\n' ) {
F_45 ( L_13 , * V_46 ) ;
goto V_39;
}
V_8 -> V_15 . V_27 = true ;
} else
goto V_39;
} else {
if ( ! V_8 -> V_15 . V_27 ) {
V_8 -> V_15 . V_30 . V_48 = F_53 ( V_25 ) ;
} else
goto V_39;
}
F_42 ( & V_38 ) ;
return F_43 ( V_25 , V_36 ) ;
V_39:
F_42 ( & V_38 ) ;
return - V_40 ;
}
static T_3 F_55 ( struct V_24 * V_9 , const char * V_25 ,
T_5 V_36 )
{
struct V_7 * V_8 = F_23 ( V_9 ) ;
T_4 V_21 [ V_34 ] ;
F_35 ( & V_38 ) ;
if ( V_8 -> V_23 ) {
F_45 ( L_12 ,
F_10 ( & V_8 -> V_9 ) ) ;
goto V_39;
}
if ( ! F_56 ( V_25 , V_21 ) )
goto V_39;
if ( V_25 [ 3 * V_34 - 1 ] && V_25 [ 3 * V_34 - 1 ] != '\n' )
goto V_39;
memcpy ( V_8 -> V_15 . V_21 , V_21 , V_34 ) ;
F_42 ( & V_38 ) ;
return F_43 ( V_25 , V_36 ) ;
V_39:
F_42 ( & V_38 ) ;
return - V_40 ;
}
static void F_57 ( struct V_24 * V_9 )
{
F_19 ( F_23 ( V_9 ) ) ;
}
static struct V_24 * F_58 ( struct V_49 * V_50 ,
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
F_59 ( & V_8 -> V_9 , V_16 , & V_51 ) ;
F_40 ( & V_43 , V_37 ) ;
F_60 ( & V_8 -> V_52 , & V_53 ) ;
F_41 ( & V_43 , V_37 ) ;
return & V_8 -> V_9 ;
}
static void F_61 ( struct V_49 * V_50 ,
struct V_24 * V_9 )
{
unsigned long V_37 ;
struct V_7 * V_8 = F_23 ( V_9 ) ;
F_40 ( & V_43 , V_37 ) ;
F_62 ( & V_8 -> V_52 ) ;
F_41 ( & V_43 , V_37 ) ;
if ( V_8 -> V_23 )
F_22 ( & V_8 -> V_15 ) ;
F_13 ( & V_8 -> V_9 ) ;
}
static int F_63 ( struct V_54 * V_55 ,
unsigned long V_56 , void * V_57 )
{
unsigned long V_37 ;
struct V_7 * V_8 ;
struct V_31 * V_32 = F_64 ( V_57 ) ;
bool V_58 = false ;
if ( ! ( V_56 == V_59 || V_56 == V_60 ||
V_56 == V_61 || V_56 == V_62 ) )
goto V_63;
F_40 ( & V_43 , V_37 ) ;
V_64:
F_65 (nt, &target_list, list) {
F_9 ( V_8 ) ;
if ( V_8 -> V_15 . V_32 == V_32 ) {
switch ( V_56 ) {
case V_59 :
F_2 ( V_8 -> V_15 . V_17 , V_32 -> V_16 , V_18 ) ;
break;
case V_61 :
case V_62 :
case V_60 :
F_41 ( & V_43 , V_37 ) ;
F_66 ( & V_8 -> V_15 ) ;
F_40 ( & V_43 , V_37 ) ;
F_67 ( V_8 -> V_15 . V_32 ) ;
V_8 -> V_15 . V_32 = NULL ;
V_8 -> V_23 = false ;
V_58 = true ;
F_12 ( V_8 ) ;
goto V_64;
}
}
F_12 ( V_8 ) ;
}
F_41 ( & V_43 , V_37 ) ;
if ( V_58 ) {
const char * V_65 = L_14 ;
switch ( V_56 ) {
case V_60 :
V_65 = L_15 ;
break;
case V_61 :
V_65 = L_16 ;
break;
case V_62 :
V_65 = L_17 ;
break;
}
F_37 ( L_18 ,
V_32 -> V_16 , V_65 ) ;
}
V_63:
return V_66 ;
}
static void F_68 ( struct V_7 * V_8 , const char * V_65 ,
int V_67 )
{
static char V_25 [ V_68 ] ;
const char * V_69 , * V_70 ;
int V_71 = 0 ;
int V_72 , V_73 ;
if ( V_67 <= V_68 ) {
F_69 ( & V_8 -> V_15 , V_65 , V_67 ) ;
return;
}
V_69 = V_65 ;
V_70 = memchr ( V_65 , ';' , V_67 ) ;
if ( F_70 ( ! V_70 ) )
return;
V_72 = V_70 - V_69 ;
V_73 = V_67 - V_72 - 1 ;
V_70 ++ ;
memcpy ( V_25 , V_69 , V_72 ) ;
while ( V_71 < V_73 ) {
int V_74 = V_72 ;
int V_75 ;
V_74 += F_71 ( V_25 + V_74 ,
sizeof( V_25 ) - V_74 ,
L_19 , V_71 , V_73 ) ;
V_75 = F_72 ( V_73 - V_71 ,
V_68 - V_74 ) ;
if ( F_70 ( V_75 <= 0 ) )
return;
memcpy ( V_25 + V_74 , V_70 + V_71 , V_75 ) ;
F_69 ( & V_8 -> V_15 , V_25 , V_74 + V_75 ) ;
V_71 += V_75 ;
}
}
static void F_73 ( struct V_76 * V_77 , const char * V_65 ,
unsigned int V_44 )
{
struct V_7 * V_8 ;
unsigned long V_37 ;
if ( ( V_78 && ! V_79 ) || F_74 ( & V_53 ) )
return;
F_40 ( & V_43 , V_37 ) ;
F_65 (nt, &target_list, list)
if ( V_8 -> V_22 && V_8 -> V_23 && F_75 ( V_8 -> V_15 . V_32 ) )
F_68 ( V_8 , V_65 , V_44 ) ;
F_41 ( & V_43 , V_37 ) ;
}
static void F_76 ( struct V_76 * V_77 , const char * V_65 , unsigned int V_44 )
{
int V_80 , V_81 ;
unsigned long V_37 ;
struct V_7 * V_8 ;
const char * V_82 ;
if ( V_78 && ! V_79 )
return;
if ( F_74 ( & V_53 ) )
return;
F_40 ( & V_43 , V_37 ) ;
F_65 (nt, &target_list, list) {
if ( ! V_8 -> V_22 && V_8 -> V_23 && F_75 ( V_8 -> V_15 . V_32 ) ) {
V_82 = V_65 ;
for ( V_81 = V_44 ; V_81 ; ) {
V_80 = F_72 ( V_81 , V_68 ) ;
F_69 ( & V_8 -> V_15 , V_82 , V_80 ) ;
V_82 += V_80 ;
V_81 -= V_80 ;
}
}
}
F_41 ( & V_43 , V_37 ) ;
}
static int T_1 F_77 ( void )
{
int V_11 ;
struct V_7 * V_8 , * V_82 ;
unsigned long V_37 ;
char * V_10 ;
char * V_83 = V_2 ;
if ( F_43 ( V_83 , V_3 ) ) {
while ( ( V_10 = F_78 ( & V_83 , L_20 ) ) ) {
V_8 = F_14 ( V_10 ) ;
if ( F_79 ( V_8 ) ) {
V_11 = F_80 ( V_8 ) ;
goto V_14;
}
if ( V_8 -> V_22 )
V_41 . V_37 |= V_84 |
V_42 ;
else
V_85 . V_37 |= V_84 ;
F_40 ( & V_43 , V_37 ) ;
F_60 ( & V_8 -> V_52 , & V_53 ) ;
F_41 ( & V_43 , V_37 ) ;
}
}
V_11 = F_81 ( & V_86 ) ;
if ( V_11 )
goto V_14;
V_11 = F_3 () ;
if ( V_11 )
goto V_87;
if ( V_41 . V_37 & V_42 )
F_38 ( & V_41 ) ;
F_38 ( & V_85 ) ;
F_37 ( L_21 ) ;
return V_11 ;
V_87:
F_82 ( & V_86 ) ;
V_14:
F_45 ( L_22 ) ;
F_83 (nt, tmp, &target_list, list) {
F_62 ( & V_8 -> V_52 ) ;
F_21 ( V_8 ) ;
}
return V_11 ;
}
static void T_2 F_84 ( void )
{
struct V_7 * V_8 , * V_82 ;
F_85 ( & V_41 ) ;
F_85 ( & V_85 ) ;
F_7 () ;
F_82 ( & V_86 ) ;
F_83 (nt, tmp, &target_list, list) {
F_62 ( & V_8 -> V_52 ) ;
F_21 ( V_8 ) ;
}
}

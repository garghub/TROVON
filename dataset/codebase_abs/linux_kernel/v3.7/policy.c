static const char * F_1 ( const char * V_1 )
{
char * V_2 ;
V_1 = F_2 ( ( char * ) V_1 ) ;
for ( V_2 = strstr ( V_1 , L_1 ) ; V_2 ; V_2 = strstr ( V_1 , L_1 ) )
V_1 = V_2 + 2 ;
return V_1 ;
}
static bool F_3 ( struct V_3 * V_4 , const char * V_5 ,
const char * V_6 )
{
if ( V_5 ) {
V_4 -> V_1 = F_4 ( strlen ( V_5 ) + strlen ( V_6 ) + 3 ,
V_7 ) ;
if ( V_4 -> V_1 )
sprintf ( V_4 -> V_1 , L_2 , V_5 , V_6 ) ;
} else
V_4 -> V_1 = F_5 ( V_6 , V_7 ) ;
if ( ! V_4 -> V_1 )
return 0 ;
V_4 -> V_6 = ( char * ) F_1 ( V_4 -> V_1 ) ;
F_6 ( & V_4 -> V_8 ) ;
F_6 ( & V_4 -> V_9 ) ;
F_7 ( & V_4 -> V_10 ) ;
return 1 ;
}
static void F_8 ( struct V_3 * V_4 )
{
if ( ! F_9 ( & V_4 -> V_9 ) ) {
F_10 ( L_3
L_4 ,
V_11 , V_4 -> V_6 ) ;
F_11 () ;
}
if ( ! F_9 ( & V_4 -> V_8 ) ) {
F_10 ( L_5 ,
V_11 , V_4 -> V_6 ) ;
F_11 () ;
}
F_12 ( V_4 -> V_1 ) ;
}
static struct V_3 * F_13 ( struct V_12 * V_13 , const char * V_6 )
{
struct V_3 * V_4 ;
F_14 (policy, head, list) {
if ( ! strcmp ( V_4 -> V_6 , V_6 ) )
return V_4 ;
}
return NULL ;
}
static struct V_3 * F_15 ( struct V_12 * V_13 ,
const char * V_14 , int V_15 )
{
struct V_3 * V_4 ;
F_14 (policy, head, list) {
if ( F_16 ( V_4 -> V_6 , V_14 , V_15 ) )
return V_4 ;
}
return NULL ;
}
bool F_17 ( struct V_16 * V_17 , struct V_16 * V_18 )
{
if ( V_17 == V_18 )
return true ;
for ( ; V_18 ; V_18 = V_18 -> V_19 ) {
if ( V_18 -> V_19 == V_17 )
return true ;
}
return false ;
}
const char * F_18 ( struct V_16 * V_17 , struct V_16 * V_18 )
{
if ( V_17 == V_18 )
return L_6 ;
if ( F_17 ( V_17 , V_18 ) ) {
return V_18 -> V_20 . V_1 + strlen ( V_17 -> V_20 . V_1 ) + 2 ;
} else
return V_21 ;
}
static struct V_16 * F_19 ( const char * V_5 ,
const char * V_6 )
{
struct V_16 * V_22 ;
V_22 = F_20 ( sizeof( * V_22 ) , V_7 ) ;
F_21 ( L_7 , V_11 , V_22 ) ;
if ( ! V_22 )
return NULL ;
if ( ! F_3 ( & V_22 -> V_20 , V_5 , V_6 ) )
goto V_23;
F_6 ( & V_22 -> V_24 ) ;
F_22 ( & V_22 -> V_25 ) ;
V_22 -> V_26 = F_23 ( L_8 ) ;
if ( ! V_22 -> V_26 )
goto V_27;
V_22 -> V_26 -> V_28 = F_24 () ;
V_22 -> V_26 -> V_29 = V_30 | V_31 |
V_32 ;
V_22 -> V_26 -> V_22 = F_25 ( V_22 ) ;
return V_22 ;
V_27:
F_12 ( V_22 -> V_20 . V_1 ) ;
V_23:
F_12 ( V_22 ) ;
return NULL ;
}
static void F_26 ( struct V_16 * V_22 )
{
if ( ! V_22 )
return;
F_8 ( & V_22 -> V_20 ) ;
F_27 ( V_22 -> V_19 ) ;
if ( V_22 -> V_26 && V_22 -> V_26 -> V_22 == V_22 )
V_22 -> V_26 -> V_22 = NULL ;
F_28 ( V_22 -> V_26 ) ;
F_12 ( V_22 ) ;
}
void F_29 ( struct V_33 * V_33 )
{
F_26 ( F_30 ( V_33 , struct V_16 , V_20 . V_10 ) ) ;
}
static struct V_16 * F_31 ( struct V_12 * V_13 ,
const char * V_6 )
{
return (struct V_16 * ) F_13 ( V_13 , V_6 ) ;
}
struct V_16 * F_32 ( struct V_16 * V_34 ,
const char * V_6 )
{
struct V_16 * V_22 = NULL ;
F_33 ( & V_34 -> V_25 ) ;
V_22 = F_25 ( F_31 ( & V_34 -> V_24 , V_6 ) ) ;
F_34 ( & V_34 -> V_25 ) ;
return V_22 ;
}
static struct V_16 * F_35 ( const char * V_6 )
{
struct V_16 * V_22 , * V_34 ;
V_34 = F_36 () -> V_22 ;
F_37 ( & V_34 -> V_25 ) ;
if ( ! V_6 ) {
V_22 = F_25 ( V_34 ) ;
goto V_35;
}
V_22 = F_25 ( F_31 ( & V_34 -> V_24 , V_6 ) ) ;
if ( ! V_22 ) {
struct V_16 * V_36 ;
F_38 ( & V_34 -> V_25 ) ;
V_36 = F_19 ( V_34 -> V_20 . V_1 , V_6 ) ;
if ( ! V_36 )
return NULL ;
F_37 ( & V_34 -> V_25 ) ;
V_22 = F_31 ( & V_34 -> V_24 , V_6 ) ;
if ( ! V_22 ) {
V_36 -> V_19 = F_25 ( V_34 ) ;
F_39 ( & V_36 -> V_20 . V_8 , & V_34 -> V_24 ) ;
V_22 = F_25 ( V_36 ) ;
} else {
F_26 ( V_36 ) ;
F_25 ( V_22 ) ;
}
}
V_35:
F_38 ( & V_34 -> V_25 ) ;
return V_22 ;
}
static void F_40 ( struct V_12 * V_8 ,
struct V_37 * V_38 )
{
F_39 ( & V_38 -> V_20 . V_8 , V_8 ) ;
F_41 ( V_38 ) ;
}
static void F_42 ( struct V_37 * V_38 )
{
F_43 ( & V_38 -> V_20 . V_8 ) ;
if ( ! ( V_38 -> V_29 & V_39 ) )
F_28 ( V_38 ) ;
}
static void F_44 ( struct V_37 * V_40 , struct V_37 * V_41 )
{
struct V_3 * V_4 ;
struct V_37 * V_42 , * V_43 ;
if ( V_40 -> V_19 )
V_4 = & V_40 -> V_19 -> V_20 ;
else
V_4 = & V_40 -> V_22 -> V_20 ;
V_41 -> V_19 = F_41 ( V_40 -> V_19 ) ;
V_41 -> V_22 = F_25 ( V_40 -> V_22 ) ;
V_41 -> V_28 = V_40 -> V_28 ;
F_40 ( & V_4 -> V_9 , V_41 ) ;
F_45 (child, tmp, &old->base.profiles, base.list) {
F_28 ( V_42 -> V_19 ) ;
V_42 -> V_19 = F_41 ( V_41 ) ;
F_46 ( & V_42 -> V_20 . V_8 , & V_41 -> V_20 . V_9 ) ;
}
V_40 -> V_44 = F_41 ( V_41 ) ;
F_42 ( V_40 ) ;
}
static void F_47 ( struct V_37 * V_38 )
{
F_48 ( & V_38 -> V_20 . V_9 ) ;
V_38 -> V_44 = F_41 ( V_38 -> V_22 -> V_26 ) ;
F_42 ( V_38 ) ;
}
static void F_48 ( struct V_12 * V_13 )
{
struct V_37 * V_38 , * V_43 ;
F_45 (profile, tmp, head, base.list)
F_47 ( V_38 ) ;
}
static void F_49 ( struct V_16 * V_22 )
{
if ( ! V_22 )
return;
F_37 ( & V_22 -> V_25 ) ;
F_48 ( & V_22 -> V_20 . V_9 ) ;
F_50 ( & V_22 -> V_24 ) ;
F_38 ( & V_22 -> V_25 ) ;
}
static void F_51 ( struct V_16 * V_22 )
{
struct V_37 * V_26 = V_22 -> V_26 ;
F_43 ( & V_22 -> V_20 . V_8 ) ;
if ( V_22 -> V_19 )
V_22 -> V_26 = F_41 ( V_22 -> V_19 -> V_26 ) ;
F_49 ( V_22 ) ;
F_28 ( V_26 ) ;
F_27 ( V_22 ) ;
}
static void F_50 ( struct V_12 * V_13 )
{
struct V_16 * V_22 , * V_43 ;
F_45 (ns, tmp, head, base.list)
F_51 ( V_22 ) ;
}
int T_1 F_52 ( void )
{
V_45 = F_19 ( NULL , L_9 ) ;
if ( ! V_45 )
return - V_46 ;
return 0 ;
}
void T_1 F_53 ( void )
{
struct V_16 * V_22 = V_45 ;
V_45 = NULL ;
F_49 ( V_22 ) ;
F_27 ( V_22 ) ;
}
struct V_37 * F_23 ( const char * V_1 )
{
struct V_37 * V_38 ;
V_38 = F_20 ( sizeof( * V_38 ) , V_7 ) ;
if ( ! V_38 )
return NULL ;
if ( ! F_3 ( & V_38 -> V_20 , NULL , V_1 ) ) {
F_12 ( V_38 ) ;
return NULL ;
}
return V_38 ;
}
struct V_37 * F_54 ( struct V_37 * V_19 , int V_47 )
{
struct V_37 * V_38 = NULL ;
char * V_6 ;
T_2 V_28 = F_24 () ;
V_6 = F_4 ( strlen ( V_19 -> V_20 . V_1 ) + 2 + 7 + 8 , V_7 ) ;
if ( ! V_6 )
goto V_48;
sprintf ( V_6 , L_10 , V_19 -> V_20 . V_1 , V_28 ) ;
V_38 = F_23 ( V_6 ) ;
F_55 ( V_6 ) ;
if ( ! V_38 )
goto V_48;
V_38 -> V_28 = V_28 ;
V_38 -> V_49 = V_50 ;
V_38 -> V_29 = V_51 ;
if ( V_47 )
V_38 -> V_29 |= V_52 ;
V_38 -> V_19 = F_41 ( V_19 ) ;
V_38 -> V_22 = F_25 ( V_19 -> V_22 ) ;
F_37 ( & V_38 -> V_22 -> V_25 ) ;
F_40 ( & V_19 -> V_20 . V_9 , V_38 ) ;
F_38 ( & V_38 -> V_22 -> V_25 ) ;
return V_38 ;
V_48:
F_56 ( V_28 ) ;
return NULL ;
}
static void F_57 ( struct V_37 * V_38 )
{
struct V_37 * V_53 ;
F_21 ( L_7 , V_11 , V_38 ) ;
if ( ! V_38 )
return;
if ( ! F_9 ( & V_38 -> V_20 . V_8 ) ) {
F_10 ( L_3
L_11 ,
V_11 , V_38 -> V_20 . V_6 ) ;
F_11 () ;
}
F_8 ( & V_38 -> V_20 ) ;
F_28 ( V_38 -> V_19 ) ;
F_27 ( V_38 -> V_22 ) ;
F_12 ( V_38 -> rename ) ;
F_58 ( & V_38 -> V_54 ) ;
F_59 ( & V_38 -> V_55 ) ;
F_60 ( & V_38 -> V_56 ) ;
F_56 ( V_38 -> V_28 ) ;
F_61 ( V_38 -> V_57 ) ;
F_61 ( V_38 -> V_4 . V_58 ) ;
for ( V_53 = V_38 -> V_44 ; V_53 ; ) {
if ( F_62 ( & V_53 -> V_20 . V_10 . V_59 ) ) {
struct V_37 * V_60 = V_53 -> V_44 ;
V_53 -> V_44 = NULL ;
F_57 ( V_53 ) ;
V_53 = V_60 ;
} else
break;
}
F_12 ( V_38 ) ;
}
void F_63 ( struct V_33 * V_33 )
{
struct V_37 * V_53 = F_30 ( V_33 , struct V_37 ,
V_20 . V_10 ) ;
F_57 ( V_53 ) ;
}
static struct V_37 * F_64 ( struct V_12 * V_13 , const char * V_6 )
{
return (struct V_37 * ) F_13 ( V_13 , V_6 ) ;
}
static struct V_37 * F_65 ( struct V_12 * V_13 ,
const char * V_6 , int V_15 )
{
return (struct V_37 * ) F_15 ( V_13 , V_6 , V_15 ) ;
}
struct V_37 * F_66 ( struct V_37 * V_19 , const char * V_6 )
{
struct V_37 * V_38 ;
F_33 ( & V_19 -> V_22 -> V_25 ) ;
V_38 = F_41 ( F_64 ( & V_19 -> V_20 . V_9 , V_6 ) ) ;
F_34 ( & V_19 -> V_22 -> V_25 ) ;
return V_38 ;
}
static struct V_3 * F_67 ( struct V_16 * V_22 ,
const char * V_1 )
{
struct V_3 * V_4 ;
struct V_37 * V_38 = NULL ;
char * V_2 ;
V_4 = & V_22 -> V_20 ;
for ( V_2 = strstr ( V_1 , L_1 ) ; V_2 ; ) {
V_38 = F_65 ( & V_4 -> V_9 , V_1 ,
V_2 - V_1 ) ;
if ( ! V_38 )
return NULL ;
V_4 = & V_38 -> V_20 ;
V_1 = V_2 + 2 ;
V_2 = strstr ( V_1 , L_1 ) ;
}
if ( ! V_38 )
return & V_22 -> V_20 ;
return & V_38 -> V_20 ;
}
static struct V_37 * F_68 ( struct V_3 * V_20 ,
const char * V_1 )
{
struct V_37 * V_38 = NULL ;
char * V_2 ;
for ( V_2 = strstr ( V_1 , L_1 ) ; V_2 ; ) {
V_38 = F_65 ( & V_20 -> V_9 , V_1 ,
V_2 - V_1 ) ;
if ( ! V_38 )
return NULL ;
V_20 = & V_38 -> V_20 ;
V_1 = V_2 + 2 ;
V_2 = strstr ( V_1 , L_1 ) ;
}
V_38 = F_64 ( & V_20 -> V_9 , V_1 ) ;
return V_38 ;
}
struct V_37 * F_69 ( struct V_16 * V_22 , const char * V_1 )
{
struct V_37 * V_38 ;
F_33 ( & V_22 -> V_25 ) ;
V_38 = F_41 ( F_68 ( & V_22 -> V_20 , V_1 ) ) ;
F_34 ( & V_22 -> V_25 ) ;
if ( ! V_38 && strcmp ( V_1 , L_8 ) == 0 )
V_38 = F_41 ( V_22 -> V_26 ) ;
return V_38 ;
}
static int F_70 ( struct V_37 * V_38 , int V_61 ,
const char * * V_62 )
{
if ( V_38 ) {
if ( V_38 -> V_29 & V_32 ) {
* V_62 = L_12 ;
return - V_63 ;
} else if ( V_61 ) {
* V_62 = L_13 ;
return - V_64 ;
}
}
return 0 ;
}
static void F_71 ( struct V_16 * V_22 , struct V_3 * V_4 ,
struct V_37 * V_38 )
{
if ( V_4 != & V_22 -> V_20 )
V_38 -> V_19 = F_41 ( (struct V_37 * ) V_4 ) ;
F_40 ( & V_4 -> V_9 , V_38 ) ;
V_38 -> V_28 = F_24 () ;
V_38 -> V_22 = F_25 ( V_22 ) ;
}
static int F_72 ( int V_65 , T_3 V_66 , const char * V_6 , const char * V_62 ,
int error )
{
struct V_67 V_68 ;
struct V_69 V_70 = { 0 ,} ;
V_68 . type = V_71 ;
V_68 . V_70 = & V_70 ;
V_70 . V_65 = V_65 ;
V_70 . V_6 = V_6 ;
V_70 . V_62 = V_62 ;
V_70 . error = error ;
return F_73 ( V_72 , F_74 () , V_66 ,
& V_68 , NULL ) ;
}
bool F_75 ( int V_65 )
{
if ( V_73 ) {
F_72 ( V_65 , V_7 , NULL , L_14 , - V_74 ) ;
return 0 ;
}
if ( ! F_76 ( V_75 ) ) {
F_72 ( V_65 , V_7 , NULL , L_15 , - V_74 ) ;
return 0 ;
}
return 1 ;
}
T_4 F_77 ( void * V_76 , T_5 V_77 , bool V_61 )
{
struct V_3 * V_4 ;
struct V_37 * V_78 = NULL , * V_79 = NULL ;
struct V_37 * V_80 = NULL ;
struct V_16 * V_22 = NULL ;
const char * V_81 , * V_6 = NULL , * V_62 = NULL ;
int V_65 = V_82 ;
T_4 error ;
V_79 = F_78 ( V_76 , V_77 , & V_81 ) ;
if ( F_79 ( V_79 ) ) {
error = F_80 ( V_79 ) ;
V_79 = NULL ;
goto V_48;
}
V_22 = F_35 ( V_81 ) ;
if ( ! V_22 ) {
V_62 = L_16 ;
error = - V_46 ;
V_6 = V_81 ;
goto V_48;
}
V_6 = V_79 -> V_20 . V_1 ;
F_37 ( & V_22 -> V_25 ) ;
V_4 = F_67 ( V_22 , V_79 -> V_20 . V_1 ) ;
if ( ! V_4 ) {
V_62 = L_17 ;
error = - V_83 ;
goto V_84;
}
V_78 = F_64 ( & V_4 -> V_9 , V_79 -> V_20 . V_6 ) ;
F_41 ( V_78 ) ;
if ( V_79 -> rename ) {
V_80 = F_68 ( & V_22 -> V_20 ,
V_79 -> rename ) ;
F_41 ( V_80 ) ;
if ( ! V_80 ) {
V_62 = L_18 ;
V_6 = V_79 -> rename ;
error = - V_83 ;
goto V_84;
}
}
error = F_70 ( V_78 , V_61 , & V_62 ) ;
if ( error )
goto V_84;
error = F_70 ( V_80 , V_61 , & V_62 ) ;
if ( error )
goto V_84;
V_84:
if ( ! V_78 && ! V_80 )
V_65 = V_85 ;
error = F_72 ( V_65 , V_86 , V_6 , V_62 , error ) ;
if ( ! error ) {
if ( V_80 )
F_44 ( V_80 , V_79 ) ;
if ( V_78 ) {
if ( V_80 )
F_56 ( V_79 -> V_28 ) ;
F_44 ( V_78 , V_79 ) ;
}
if ( ! ( V_78 || V_80 ) )
F_71 ( V_22 , V_4 , V_79 ) ;
}
F_38 ( & V_22 -> V_25 ) ;
V_35:
F_27 ( V_22 ) ;
F_28 ( V_80 ) ;
F_28 ( V_78 ) ;
F_28 ( V_79 ) ;
if ( error )
return error ;
return V_77 ;
V_48:
error = F_72 ( V_65 , V_7 , V_6 , V_62 , error ) ;
goto V_35;
}
T_4 F_81 ( char * V_87 , T_5 V_77 )
{
struct V_16 * V_34 , * V_22 = NULL ;
struct V_37 * V_38 = NULL ;
const char * V_6 = V_87 , * V_62 = NULL ;
T_4 error = 0 ;
if ( * V_87 == 0 ) {
V_62 = L_19 ;
error = - V_83 ;
goto V_48;
}
V_34 = F_36 () -> V_22 ;
if ( V_87 [ 0 ] == ':' ) {
char * V_81 ;
V_6 = F_82 ( V_87 , & V_81 ) ;
if ( V_81 ) {
V_22 = F_32 ( V_34 , V_81 ) ;
if ( ! V_22 ) {
V_62 = L_20 ;
error = - V_83 ;
goto V_48;
}
}
} else
V_22 = F_25 ( V_34 ) ;
if ( ! V_6 ) {
F_37 ( & V_22 -> V_19 -> V_25 ) ;
F_51 ( V_22 ) ;
F_38 ( & V_22 -> V_19 -> V_25 ) ;
} else {
F_37 ( & V_22 -> V_25 ) ;
V_38 = F_41 ( F_68 ( & V_22 -> V_20 , V_6 ) ) ;
if ( ! V_38 ) {
error = - V_83 ;
V_62 = L_21 ;
goto V_88;
}
V_6 = V_38 -> V_20 . V_1 ;
F_47 ( V_38 ) ;
F_38 ( & V_22 -> V_25 ) ;
}
( void ) F_72 ( V_89 , V_7 , V_6 , V_62 , error ) ;
F_27 ( V_22 ) ;
F_28 ( V_38 ) ;
return V_77 ;
V_88:
F_38 ( & V_22 -> V_25 ) ;
F_27 ( V_22 ) ;
V_48:
( void ) F_72 ( V_89 , V_7 , V_6 , V_62 , error ) ;
return error ;
}

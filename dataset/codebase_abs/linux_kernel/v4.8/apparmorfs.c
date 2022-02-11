static int F_1 ( char * V_1 , char * V_2 )
{
char * V_3 = V_2 ;
while ( * V_1 == '/' || * V_1 == '.' )
V_1 ++ ;
if ( V_2 ) {
for (; * V_1 ; V_1 ++ ) {
if ( * V_1 == '/' )
* ( V_3 ) ++ = '.' ;
else if ( isspace ( * V_1 ) )
* ( V_3 ) ++ = '_' ;
else if ( isalnum ( * V_1 ) || strchr ( L_1 , * V_1 ) )
* ( V_3 ) ++ = * V_1 ;
}
* V_3 = 0 ;
} else {
int V_4 = 0 ;
for (; * V_1 ; V_1 ++ ) {
if ( isalnum ( * V_1 ) || isspace ( * V_1 ) ||
strchr ( L_2 , * V_1 ) )
V_4 ++ ;
}
return V_4 ;
}
return V_3 - V_2 ;
}
static char * F_2 ( int V_5 , const char T_1 * V_6 ,
T_2 V_7 , T_2 V_8 ,
T_3 * V_9 )
{
char * V_10 ;
F_3 ( V_8 > V_7 ) ;
if ( * V_9 != 0 )
return F_4 ( - V_11 ) ;
if ( ! F_5 ( V_5 ) )
return F_4 ( - V_12 ) ;
V_10 = F_6 ( V_7 ) ;
if ( V_10 == NULL )
return F_4 ( - V_13 ) ;
if ( F_7 ( V_10 , V_6 , V_8 ) ) {
F_8 ( V_10 ) ;
return F_4 ( - V_14 ) ;
}
return V_10 ;
}
static T_4 F_9 ( struct V_15 * V_16 , const char T_1 * V_17 , T_2 V_18 ,
T_3 * V_9 )
{
char * V_10 ;
T_4 error ;
V_10 = F_2 ( V_19 , V_17 , V_18 , V_18 , V_9 ) ;
error = F_10 ( V_10 ) ;
if ( ! F_11 ( V_10 ) ) {
error = F_12 ( V_10 , V_18 , V_20 ) ;
F_8 ( V_10 ) ;
}
return error ;
}
static T_4 F_13 ( struct V_15 * V_16 , const char T_1 * V_17 ,
T_2 V_18 , T_3 * V_9 )
{
char * V_10 ;
T_4 error ;
V_10 = F_2 ( V_21 , V_17 , V_18 , V_18 , V_9 ) ;
error = F_10 ( V_10 ) ;
if ( ! F_11 ( V_10 ) ) {
error = F_12 ( V_10 , V_18 , V_22 ) ;
F_8 ( V_10 ) ;
}
return error ;
}
static T_4 F_14 ( struct V_15 * V_16 , const char T_1 * V_17 ,
T_2 V_18 , T_3 * V_9 )
{
char * V_10 ;
T_4 error ;
V_10 = F_2 ( V_23 , V_17 , V_18 + 1 , V_18 , V_9 ) ;
error = F_10 ( V_10 ) ;
if ( ! F_11 ( V_10 ) ) {
V_10 [ V_18 ] = 0 ;
error = F_15 ( V_10 , V_18 ) ;
F_8 ( V_10 ) ;
}
return error ;
}
static int F_16 ( struct V_24 * V_25 , void * V_26 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
if ( ! V_28 )
return 0 ;
switch ( V_28 -> V_30 ) {
case V_31 :
F_17 ( V_25 , L_3 , V_28 -> V_26 . boolean ? L_4 : L_5 ) ;
break;
case V_32 :
F_17 ( V_25 , L_3 , V_28 -> V_26 . string ) ;
break;
case V_33 :
F_17 ( V_25 , L_6 , V_28 -> V_26 . V_34 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_18 ( struct V_35 * V_35 , struct V_15 * V_15 )
{
return F_19 ( V_15 , F_16 , V_35 -> V_36 ) ;
}
static int F_20 ( struct V_35 * V_35 , struct V_15 * V_15 ,
int (* F_21)( struct V_24 * , void * ) )
{
struct V_37 * V_38 = F_22 ( V_35 -> V_36 ) ;
int error = F_19 ( V_15 , F_21 , V_38 ) ;
if ( error ) {
V_15 -> V_39 = NULL ;
F_23 ( V_38 ) ;
}
return error ;
}
static int F_24 ( struct V_35 * V_35 , struct V_15 * V_15 )
{
struct V_24 * V_25 = (struct V_24 * ) V_15 -> V_39 ;
if ( V_25 )
F_23 ( V_25 -> V_29 ) ;
return F_25 ( V_35 , V_15 ) ;
}
static int F_26 ( struct V_24 * V_25 , void * V_26 )
{
struct V_37 * V_38 = V_25 -> V_29 ;
struct V_40 * V_41 = F_27 ( & V_38 -> V_41 ) ;
F_17 ( V_25 , L_3 , V_41 -> V_42 . V_1 ) ;
F_28 ( V_41 ) ;
return 0 ;
}
static int F_29 ( struct V_35 * V_35 , struct V_15 * V_15 )
{
return F_20 ( V_35 , V_15 , F_26 ) ;
}
static int F_30 ( struct V_24 * V_25 , void * V_26 )
{
struct V_37 * V_38 = V_25 -> V_29 ;
struct V_40 * V_41 = F_27 ( & V_38 -> V_41 ) ;
F_17 ( V_25 , L_3 , V_43 [ V_41 -> V_44 ] ) ;
F_28 ( V_41 ) ;
return 0 ;
}
static int F_31 ( struct V_35 * V_35 , struct V_15 * V_15 )
{
return F_20 ( V_35 , V_15 , F_30 ) ;
}
static int F_32 ( struct V_24 * V_25 , void * V_26 )
{
struct V_37 * V_38 = V_25 -> V_29 ;
struct V_40 * V_41 = F_27 ( & V_38 -> V_41 ) ;
if ( V_41 -> V_45 )
F_17 ( V_25 , L_3 , V_41 -> V_45 ) ;
else if ( V_41 -> V_46 )
F_33 ( V_25 , L_7 ) ;
else
F_17 ( V_25 , L_3 , V_41 -> V_42 . V_1 ) ;
F_28 ( V_41 ) ;
return 0 ;
}
static int F_34 ( struct V_35 * V_35 , struct V_15 * V_15 )
{
return F_20 ( V_35 , V_15 , F_32 ) ;
}
static int F_35 ( struct V_24 * V_25 , void * V_26 )
{
struct V_37 * V_38 = V_25 -> V_29 ;
struct V_40 * V_41 = F_27 ( & V_38 -> V_41 ) ;
unsigned int V_47 , V_18 = F_36 () ;
if ( V_41 -> V_48 ) {
for ( V_47 = 0 ; V_47 < V_18 ; V_47 ++ )
F_17 ( V_25 , L_8 , V_41 -> V_48 [ V_47 ] ) ;
F_33 ( V_25 , L_9 ) ;
}
F_28 ( V_41 ) ;
return 0 ;
}
static int F_37 ( struct V_35 * V_35 , struct V_15 * V_15 )
{
return F_19 ( V_15 , F_35 , V_35 -> V_36 ) ;
}
void F_38 ( struct V_40 * V_41 )
{
struct V_40 * V_49 ;
int V_47 ;
if ( ! V_41 )
return;
F_39 (child, &profile->base.profiles, base.list)
F_38 ( V_49 ) ;
for ( V_47 = V_50 - 1 ; V_47 >= 0 ; -- V_47 ) {
struct V_37 * V_38 ;
if ( ! V_41 -> V_51 [ V_47 ] )
continue;
V_38 = F_40 ( V_41 -> V_51 [ V_47 ] ) -> V_36 ;
F_41 ( V_41 -> V_51 [ V_47 ] ) ;
F_23 ( V_38 ) ;
V_41 -> V_51 [ V_47 ] = NULL ;
}
}
void F_42 ( struct V_40 * V_52 ,
struct V_40 * V_53 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
V_53 -> V_51 [ V_47 ] = V_52 -> V_51 [ V_47 ] ;
if ( V_53 -> V_51 [ V_47 ] )
V_53 -> V_51 [ V_47 ] -> F_40 -> V_54 = V_55 ;
V_52 -> V_51 [ V_47 ] = NULL ;
}
}
static struct V_56 * F_43 ( struct V_56 * V_57 , const char * V_1 ,
struct V_40 * V_41 ,
const struct V_58 * V_59 )
{
struct V_37 * V_38 = F_22 ( V_41 -> V_60 ) ;
struct V_56 * V_61 ;
V_61 = F_44 ( V_1 , V_62 | 0444 , V_57 , V_38 , V_59 ) ;
if ( F_11 ( V_61 ) )
F_23 ( V_38 ) ;
return V_61 ;
}
int F_45 ( struct V_40 * V_41 , struct V_56 * V_63 )
{
struct V_40 * V_49 ;
struct V_56 * V_61 = NULL , * V_57 ;
int error ;
if ( ! V_63 ) {
struct V_40 * V_64 ;
V_64 = F_46 ( V_41 ) ;
V_61 = F_47 ( V_64 ) ;
V_61 = F_48 ( L_10 , V_61 ) ;
if ( F_11 ( V_61 ) )
goto V_65;
F_49 ( V_64 ) = V_63 = V_61 ;
}
if ( ! V_41 -> V_66 ) {
int V_4 , V_67 ;
V_4 = F_1 ( V_41 -> V_42 . V_1 , NULL ) ;
V_67 = snprintf ( NULL , 0 , L_11 , V_41 -> V_68 -> V_69 ) ;
V_41 -> V_66 = F_50 ( V_4 + V_67 + 1 , V_70 ) ;
if ( ! V_41 -> V_66 )
goto V_65;
F_1 ( V_41 -> V_42 . V_1 , V_41 -> V_66 ) ;
sprintf ( V_41 -> V_66 + V_4 , L_11 , V_41 -> V_68 -> V_69 ++ ) ;
}
V_61 = F_48 ( V_41 -> V_66 , V_63 ) ;
if ( F_11 ( V_61 ) )
goto V_65;
F_47 ( V_41 ) = V_57 = V_61 ;
V_61 = F_43 ( V_57 , L_12 , V_41 , & V_71 ) ;
if ( F_11 ( V_61 ) )
goto V_65;
V_41 -> V_51 [ V_72 ] = V_61 ;
V_61 = F_43 ( V_57 , L_13 , V_41 , & V_73 ) ;
if ( F_11 ( V_61 ) )
goto V_65;
V_41 -> V_51 [ V_74 ] = V_61 ;
V_61 = F_43 ( V_57 , L_14 , V_41 ,
& V_75 ) ;
if ( F_11 ( V_61 ) )
goto V_65;
V_41 -> V_51 [ V_76 ] = V_61 ;
if ( V_41 -> V_48 ) {
V_61 = F_43 ( V_57 , L_15 , V_41 ,
& V_77 ) ;
if ( F_11 ( V_61 ) )
goto V_65;
V_41 -> V_51 [ V_78 ] = V_61 ;
}
F_39 (child, &profile->base.profiles, base.list) {
error = F_45 ( V_49 , F_49 ( V_41 ) ) ;
if ( error )
goto V_79;
}
return 0 ;
V_65:
error = F_10 ( V_61 ) ;
V_79:
F_38 ( V_41 ) ;
return error ;
}
void F_51 ( struct V_80 * V_68 )
{
struct V_80 * V_81 ;
struct V_40 * V_49 ;
int V_47 ;
if ( ! V_68 )
return;
F_39 (child, &ns->base.profiles, base.list)
F_38 ( V_49 ) ;
F_39 (sub, &ns->sub_ns, base.list) {
F_52 ( & V_81 -> V_82 ) ;
F_51 ( V_81 ) ;
F_53 ( & V_81 -> V_82 ) ;
}
for ( V_47 = V_83 - 1 ; V_47 >= 0 ; -- V_47 ) {
F_41 ( V_68 -> V_51 [ V_47 ] ) ;
V_68 -> V_51 [ V_47 ] = NULL ;
}
}
int F_54 ( struct V_80 * V_68 , struct V_56 * V_63 ,
const char * V_1 )
{
struct V_80 * V_81 ;
struct V_40 * V_49 ;
struct V_56 * V_61 , * V_57 ;
int error ;
if ( ! V_1 )
V_1 = V_68 -> V_42 . V_1 ;
V_61 = F_48 ( V_1 , V_63 ) ;
if ( F_11 ( V_61 ) )
goto V_65;
F_55 ( V_68 ) = V_57 = V_61 ;
V_61 = F_48 ( L_10 , V_57 ) ;
if ( F_11 ( V_61 ) )
goto V_65;
F_56 ( V_68 ) = V_61 ;
V_61 = F_48 ( L_16 , V_57 ) ;
if ( F_11 ( V_61 ) )
goto V_65;
F_57 ( V_68 ) = V_61 ;
F_39 (child, &ns->base.profiles, base.list) {
error = F_45 ( V_49 , F_56 ( V_68 ) ) ;
if ( error )
goto V_79;
}
F_39 (sub, &ns->sub_ns, base.list) {
F_52 ( & V_81 -> V_82 ) ;
error = F_54 ( V_81 , F_57 ( V_68 ) , NULL ) ;
F_53 ( & V_81 -> V_82 ) ;
if ( error )
goto V_79;
}
return 0 ;
V_65:
error = F_10 ( V_61 ) ;
V_79:
F_51 ( V_68 ) ;
return error ;
}
static struct V_80 * F_58 ( struct V_80 * V_84 ,
struct V_80 * V_68 )
{
struct V_80 * V_63 , * V_85 ;
if ( ! F_59 ( & V_68 -> V_86 ) ) {
V_85 = F_60 ( & V_68 -> V_86 , F_61 ( * V_68 ) , V_42 . V_87 ) ;
F_52 ( & V_85 -> V_82 ) ;
return V_85 ;
}
V_63 = V_68 -> V_63 ;
while ( V_68 != V_84 ) {
F_53 ( & V_68 -> V_82 ) ;
V_85 = F_62 ( V_68 , V_42 . V_87 ) ;
if ( ! F_63 ( V_85 , & V_63 -> V_86 , V_42 . V_87 ) ) {
F_52 ( & V_85 -> V_82 ) ;
return V_85 ;
}
V_68 = V_63 ;
V_63 = V_63 -> V_63 ;
}
return NULL ;
}
static struct V_40 * F_64 ( struct V_80 * V_84 ,
struct V_80 * V_68 )
{
for (; V_68 ; V_68 = F_58 ( V_84 , V_68 ) ) {
if ( ! F_59 ( & V_68 -> V_42 . V_88 ) )
return F_60 ( & V_68 -> V_42 . V_88 ,
struct V_40 , V_42 . V_87 ) ;
}
return NULL ;
}
static struct V_40 * F_65 ( struct V_40 * V_64 )
{
struct V_40 * V_63 ;
struct V_80 * V_68 = V_64 -> V_68 ;
if ( ! F_59 ( & V_64 -> V_42 . V_88 ) )
return F_60 ( & V_64 -> V_42 . V_88 , F_61 ( * V_64 ) ,
V_42 . V_87 ) ;
V_63 = F_66 ( V_64 -> V_63 ,
F_67 ( & V_64 -> V_68 -> V_82 ) ) ;
while ( V_63 ) {
V_64 = F_62 ( V_64 , V_42 . V_87 ) ;
if ( ! F_63 ( V_64 , & V_63 -> V_42 . V_88 , V_42 . V_87 ) )
return V_64 ;
V_64 = V_63 ;
V_63 = F_66 ( V_63 -> V_63 ,
F_67 ( & V_63 -> V_68 -> V_82 ) ) ;
}
V_64 = F_62 ( V_64 , V_42 . V_87 ) ;
if ( ! F_63 ( V_64 , & V_68 -> V_42 . V_88 , V_42 . V_87 ) )
return V_64 ;
return NULL ;
}
static struct V_40 * F_68 ( struct V_80 * V_84 ,
struct V_40 * V_41 )
{
struct V_40 * V_85 = F_65 ( V_41 ) ;
if ( V_85 )
return V_85 ;
return F_64 ( V_84 , F_58 ( V_84 , V_41 -> V_68 ) ) ;
}
static void * F_69 ( struct V_24 * V_16 , T_3 * V_9 )
{
struct V_40 * V_41 = NULL ;
struct V_80 * V_84 = F_70 () -> V_68 ;
T_3 V_89 = * V_9 ;
V_16 -> V_29 = F_71 ( V_84 ) ;
F_52 ( & V_84 -> V_82 ) ;
V_41 = F_64 ( V_84 , V_84 ) ;
for (; V_41 && V_89 > 0 ; V_89 -- )
V_41 = F_68 ( V_84 , V_41 ) ;
return V_41 ;
}
static void * F_72 ( struct V_24 * V_16 , void * V_64 , T_3 * V_9 )
{
struct V_40 * V_41 = V_64 ;
struct V_80 * V_68 = V_16 -> V_29 ;
( * V_9 ) ++ ;
return F_68 ( V_68 , V_41 ) ;
}
static void F_73 ( struct V_24 * V_16 , void * V_64 )
{
struct V_40 * V_41 = V_64 ;
struct V_80 * V_84 = V_16 -> V_29 , * V_68 ;
if ( V_41 ) {
for ( V_68 = V_41 -> V_68 ; V_68 && V_68 != V_84 ; V_68 = V_68 -> V_63 )
F_53 ( & V_68 -> V_82 ) ;
}
F_53 ( & V_84 -> V_82 ) ;
F_74 ( V_84 ) ;
}
static int F_75 ( struct V_24 * V_16 , void * V_64 )
{
struct V_40 * V_41 = (struct V_40 * ) V_64 ;
struct V_80 * V_84 = V_16 -> V_29 ;
if ( V_41 -> V_68 != V_84 )
F_17 ( V_16 , L_17 , F_76 ( V_84 , V_41 -> V_68 ) ) ;
F_17 ( V_16 , L_18 , V_41 -> V_42 . V_90 ,
V_43 [ V_41 -> V_44 ] ) ;
return 0 ;
}
static int F_77 ( struct V_35 * V_35 , struct V_15 * V_15 )
{
return F_78 ( V_15 , & V_91 ) ;
}
static int F_79 ( struct V_35 * V_35 , struct V_15 * V_15 )
{
return F_80 ( V_35 , V_15 ) ;
}
static int T_5 F_81 ( struct V_27 * V_28 ,
struct V_56 * V_63 )
{
int error = 0 ;
V_28 -> V_56 = F_44 ( V_28 -> V_1 ,
V_62 | V_28 -> V_44 ,
V_63 , V_28 ,
V_28 -> V_92 ) ;
if ( F_11 ( V_28 -> V_56 ) ) {
error = F_10 ( V_28 -> V_56 ) ;
V_28 -> V_56 = NULL ;
}
return error ;
}
static int T_5 F_82 ( struct V_27 * V_93 ,
struct V_56 * V_63 )
{
struct V_27 * V_28 ;
struct V_56 * V_57 ;
int error ;
V_57 = F_48 ( V_93 -> V_1 , V_63 ) ;
if ( F_11 ( V_57 ) )
return F_10 ( V_57 ) ;
V_93 -> V_56 = V_57 ;
for ( V_28 = V_93 -> V_26 . V_94 ; V_28 && V_28 -> V_1 ; ++ V_28 ) {
if ( V_28 -> V_30 == V_95 )
error = F_82 ( V_28 , V_93 -> V_56 ) ;
else
error = F_81 ( V_28 , V_93 -> V_56 ) ;
if ( error )
goto V_96;
}
return 0 ;
V_96:
F_83 ( V_93 ) ;
return error ;
}
static void T_5 F_84 ( struct V_27 * V_28 )
{
if ( ! V_28 -> V_56 )
return;
F_41 ( V_28 -> V_56 ) ;
V_28 -> V_56 = NULL ;
}
static void T_5 F_83 ( struct V_27 * V_93 )
{
struct V_27 * V_28 ;
for ( V_28 = V_93 -> V_26 . V_94 ; V_28 && V_28 -> V_1 ; ++ V_28 ) {
if ( V_28 -> V_30 == V_95 )
F_83 ( V_28 ) ;
else
F_84 ( V_28 ) ;
}
F_84 ( V_93 ) ;
}
void T_5 F_85 ( void )
{
F_83 ( & V_27 ) ;
}
static int T_5 F_86 ( void )
{
int error ;
if ( ! V_97 )
return 0 ;
if ( V_27 . V_56 ) {
F_87 ( L_19 , V_98 ) ;
return - V_99 ;
}
error = F_82 ( & V_27 , NULL ) ;
if ( error )
goto error;
error = F_54 ( V_100 , V_27 . V_56 ,
L_20 ) ;
if ( error )
goto error;
F_88 ( L_21 ) ;
return 0 ;
error:
F_85 () ;
F_87 ( L_22 ) ;
return error ;
}

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
V_38 = V_41 -> V_51 [ V_47 ] -> V_52 -> V_36 ;
F_40 ( V_41 -> V_51 [ V_47 ] ) ;
F_23 ( V_38 ) ;
V_41 -> V_51 [ V_47 ] = NULL ;
}
}
void F_41 ( struct V_40 * V_53 ,
struct V_40 * V_54 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
V_54 -> V_51 [ V_47 ] = V_53 -> V_51 [ V_47 ] ;
V_53 -> V_51 [ V_47 ] = NULL ;
}
}
static struct V_55 * F_42 ( struct V_55 * V_56 , const char * V_1 ,
struct V_40 * V_41 ,
const struct V_57 * V_58 )
{
struct V_37 * V_38 = F_22 ( V_41 -> V_59 ) ;
struct V_55 * V_60 ;
V_60 = F_43 ( V_1 , V_61 | 0444 , V_56 , V_38 , V_58 ) ;
if ( F_11 ( V_60 ) )
F_23 ( V_38 ) ;
return V_60 ;
}
int F_44 ( struct V_40 * V_41 , struct V_55 * V_62 )
{
struct V_40 * V_49 ;
struct V_55 * V_60 = NULL , * V_56 ;
int error ;
if ( ! V_62 ) {
struct V_40 * V_63 ;
V_63 = F_45 ( V_41 ) ;
V_60 = F_46 ( V_63 ) ;
V_60 = F_47 ( L_10 , V_60 ) ;
if ( F_11 ( V_60 ) )
goto V_64;
F_48 ( V_63 ) = V_62 = V_60 ;
}
if ( ! V_41 -> V_65 ) {
int V_4 , V_66 ;
V_4 = F_1 ( V_41 -> V_42 . V_1 , NULL ) ;
V_66 = snprintf ( NULL , 0 , L_11 , V_41 -> V_67 -> V_68 ) ;
V_41 -> V_65 = F_49 ( V_4 + V_66 + 1 , V_69 ) ;
if ( ! V_41 -> V_65 )
goto V_64;
F_1 ( V_41 -> V_42 . V_1 , V_41 -> V_65 ) ;
sprintf ( V_41 -> V_65 + V_4 , L_11 , V_41 -> V_67 -> V_68 ++ ) ;
}
V_60 = F_47 ( V_41 -> V_65 , V_62 ) ;
if ( F_11 ( V_60 ) )
goto V_64;
F_46 ( V_41 ) = V_56 = V_60 ;
V_60 = F_42 ( V_56 , L_12 , V_41 , & V_70 ) ;
if ( F_11 ( V_60 ) )
goto V_64;
V_41 -> V_51 [ V_71 ] = V_60 ;
V_60 = F_42 ( V_56 , L_13 , V_41 , & V_72 ) ;
if ( F_11 ( V_60 ) )
goto V_64;
V_41 -> V_51 [ V_73 ] = V_60 ;
V_60 = F_42 ( V_56 , L_14 , V_41 ,
& V_74 ) ;
if ( F_11 ( V_60 ) )
goto V_64;
V_41 -> V_51 [ V_75 ] = V_60 ;
if ( V_41 -> V_48 ) {
V_60 = F_42 ( V_56 , L_15 , V_41 ,
& V_76 ) ;
if ( F_11 ( V_60 ) )
goto V_64;
V_41 -> V_51 [ V_77 ] = V_60 ;
}
F_39 (child, &profile->base.profiles, base.list) {
error = F_44 ( V_49 , F_48 ( V_41 ) ) ;
if ( error )
goto V_78;
}
return 0 ;
V_64:
error = F_10 ( V_60 ) ;
V_78:
F_38 ( V_41 ) ;
return error ;
}
void F_50 ( struct V_79 * V_67 )
{
struct V_79 * V_80 ;
struct V_40 * V_49 ;
int V_47 ;
if ( ! V_67 )
return;
F_39 (child, &ns->base.profiles, base.list)
F_38 ( V_49 ) ;
F_39 (sub, &ns->sub_ns, base.list) {
F_51 ( & V_80 -> V_81 ) ;
F_50 ( V_80 ) ;
F_52 ( & V_80 -> V_81 ) ;
}
for ( V_47 = V_82 - 1 ; V_47 >= 0 ; -- V_47 ) {
F_40 ( V_67 -> V_51 [ V_47 ] ) ;
V_67 -> V_51 [ V_47 ] = NULL ;
}
}
int F_53 ( struct V_79 * V_67 , struct V_55 * V_62 ,
const char * V_1 )
{
struct V_79 * V_80 ;
struct V_40 * V_49 ;
struct V_55 * V_60 , * V_56 ;
int error ;
if ( ! V_1 )
V_1 = V_67 -> V_42 . V_1 ;
V_60 = F_47 ( V_1 , V_62 ) ;
if ( F_11 ( V_60 ) )
goto V_64;
F_54 ( V_67 ) = V_56 = V_60 ;
V_60 = F_47 ( L_10 , V_56 ) ;
if ( F_11 ( V_60 ) )
goto V_64;
F_55 ( V_67 ) = V_60 ;
V_60 = F_47 ( L_16 , V_56 ) ;
if ( F_11 ( V_60 ) )
goto V_64;
F_56 ( V_67 ) = V_60 ;
F_39 (child, &ns->base.profiles, base.list) {
error = F_44 ( V_49 , F_55 ( V_67 ) ) ;
if ( error )
goto V_78;
}
F_39 (sub, &ns->sub_ns, base.list) {
F_51 ( & V_80 -> V_81 ) ;
error = F_53 ( V_80 , F_56 ( V_67 ) , NULL ) ;
F_52 ( & V_80 -> V_81 ) ;
if ( error )
goto V_78;
}
return 0 ;
V_64:
error = F_10 ( V_60 ) ;
V_78:
F_50 ( V_67 ) ;
return error ;
}
static struct V_79 * F_57 ( struct V_79 * V_83 ,
struct V_79 * V_67 )
{
struct V_79 * V_62 , * V_84 ;
if ( ! F_58 ( & V_67 -> V_85 ) ) {
V_84 = F_59 ( & V_67 -> V_85 , F_60 ( * V_67 ) , V_42 . V_86 ) ;
F_51 ( & V_84 -> V_81 ) ;
return V_84 ;
}
V_62 = V_67 -> V_62 ;
while ( V_67 != V_83 ) {
F_52 ( & V_67 -> V_81 ) ;
V_84 = F_61 ( V_67 , V_42 . V_86 ) ;
if ( ! F_62 ( V_84 , & V_62 -> V_85 , V_42 . V_86 ) ) {
F_51 ( & V_84 -> V_81 ) ;
return V_84 ;
}
V_67 = V_62 ;
V_62 = V_62 -> V_62 ;
}
return NULL ;
}
static struct V_40 * F_63 ( struct V_79 * V_83 ,
struct V_79 * V_67 )
{
for (; V_67 ; V_67 = F_57 ( V_83 , V_67 ) ) {
if ( ! F_58 ( & V_67 -> V_42 . V_87 ) )
return F_59 ( & V_67 -> V_42 . V_87 ,
struct V_40 , V_42 . V_86 ) ;
}
return NULL ;
}
static struct V_40 * F_64 ( struct V_40 * V_63 )
{
struct V_40 * V_62 ;
struct V_79 * V_67 = V_63 -> V_67 ;
if ( ! F_58 ( & V_63 -> V_42 . V_87 ) )
return F_59 ( & V_63 -> V_42 . V_87 , F_60 ( * V_63 ) ,
V_42 . V_86 ) ;
V_62 = F_65 ( V_63 -> V_62 ,
F_66 ( & V_63 -> V_67 -> V_81 ) ) ;
while ( V_62 ) {
V_63 = F_61 ( V_63 , V_42 . V_86 ) ;
if ( ! F_62 ( V_63 , & V_62 -> V_42 . V_87 , V_42 . V_86 ) )
return V_63 ;
V_63 = V_62 ;
V_62 = F_65 ( V_62 -> V_62 ,
F_66 ( & V_62 -> V_67 -> V_81 ) ) ;
}
V_63 = F_61 ( V_63 , V_42 . V_86 ) ;
if ( ! F_62 ( V_63 , & V_67 -> V_42 . V_87 , V_42 . V_86 ) )
return V_63 ;
return NULL ;
}
static struct V_40 * F_67 ( struct V_79 * V_83 ,
struct V_40 * V_41 )
{
struct V_40 * V_84 = F_64 ( V_41 ) ;
if ( V_84 )
return V_84 ;
return F_63 ( V_83 , F_57 ( V_83 , V_41 -> V_67 ) ) ;
}
static void * F_68 ( struct V_24 * V_16 , T_3 * V_9 )
{
struct V_40 * V_41 = NULL ;
struct V_79 * V_83 = F_69 () -> V_67 ;
T_3 V_88 = * V_9 ;
V_16 -> V_29 = F_70 ( V_83 ) ;
F_51 ( & V_83 -> V_81 ) ;
V_41 = F_63 ( V_83 , V_83 ) ;
for (; V_41 && V_88 > 0 ; V_88 -- )
V_41 = F_67 ( V_83 , V_41 ) ;
return V_41 ;
}
static void * F_71 ( struct V_24 * V_16 , void * V_63 , T_3 * V_9 )
{
struct V_40 * V_41 = V_63 ;
struct V_79 * V_67 = V_16 -> V_29 ;
( * V_9 ) ++ ;
return F_67 ( V_67 , V_41 ) ;
}
static void F_72 ( struct V_24 * V_16 , void * V_63 )
{
struct V_40 * V_41 = V_63 ;
struct V_79 * V_83 = V_16 -> V_29 , * V_67 ;
if ( V_41 ) {
for ( V_67 = V_41 -> V_67 ; V_67 && V_67 != V_83 ; V_67 = V_67 -> V_62 )
F_52 ( & V_67 -> V_81 ) ;
}
F_52 ( & V_83 -> V_81 ) ;
F_73 ( V_83 ) ;
}
static int F_74 ( struct V_24 * V_16 , void * V_63 )
{
struct V_40 * V_41 = (struct V_40 * ) V_63 ;
struct V_79 * V_83 = V_16 -> V_29 ;
if ( V_41 -> V_67 != V_83 )
F_17 ( V_16 , L_17 , F_75 ( V_83 , V_41 -> V_67 ) ) ;
F_17 ( V_16 , L_18 , V_41 -> V_42 . V_89 ,
V_43 [ V_41 -> V_44 ] ) ;
return 0 ;
}
static int F_76 ( struct V_35 * V_35 , struct V_15 * V_15 )
{
return F_77 ( V_15 , & V_90 ) ;
}
static int F_78 ( struct V_35 * V_35 , struct V_15 * V_15 )
{
return F_79 ( V_35 , V_15 ) ;
}
static int T_5 F_80 ( struct V_27 * V_28 ,
struct V_55 * V_62 )
{
int error = 0 ;
V_28 -> V_55 = F_43 ( V_28 -> V_1 ,
V_61 | V_28 -> V_44 ,
V_62 , V_28 ,
V_28 -> V_91 ) ;
if ( F_11 ( V_28 -> V_55 ) ) {
error = F_10 ( V_28 -> V_55 ) ;
V_28 -> V_55 = NULL ;
}
return error ;
}
static int T_5 F_81 ( struct V_27 * V_92 ,
struct V_55 * V_62 )
{
struct V_27 * V_28 ;
struct V_55 * V_56 ;
int error ;
V_56 = F_47 ( V_92 -> V_1 , V_62 ) ;
if ( F_11 ( V_56 ) )
return F_10 ( V_56 ) ;
V_92 -> V_55 = V_56 ;
for ( V_28 = V_92 -> V_26 . V_93 ; V_28 && V_28 -> V_1 ; ++ V_28 ) {
if ( V_28 -> V_30 == V_94 )
error = F_81 ( V_28 , V_92 -> V_55 ) ;
else
error = F_80 ( V_28 , V_92 -> V_55 ) ;
if ( error )
goto V_95;
}
return 0 ;
V_95:
F_82 ( V_92 ) ;
return error ;
}
static void T_5 F_83 ( struct V_27 * V_28 )
{
if ( ! V_28 -> V_55 )
return;
F_40 ( V_28 -> V_55 ) ;
V_28 -> V_55 = NULL ;
}
static void T_5 F_82 ( struct V_27 * V_92 )
{
struct V_27 * V_28 ;
for ( V_28 = V_92 -> V_26 . V_93 ; V_28 && V_28 -> V_1 ; ++ V_28 ) {
if ( V_28 -> V_30 == V_94 )
F_82 ( V_28 ) ;
else
F_83 ( V_28 ) ;
}
F_83 ( V_92 ) ;
}
void T_5 F_84 ( void )
{
F_82 ( & V_27 ) ;
}
static int T_5 F_85 ( void )
{
int error ;
if ( ! V_96 )
return 0 ;
if ( V_27 . V_55 ) {
F_86 ( L_19 , V_97 ) ;
return - V_98 ;
}
error = F_81 ( & V_27 , NULL ) ;
if ( error )
goto error;
error = F_53 ( V_99 , V_27 . V_55 ,
L_20 ) ;
if ( error )
goto error;
F_87 ( L_21 ) ;
return 0 ;
error:
F_84 () ;
F_86 ( L_22 ) ;
return error ;
}

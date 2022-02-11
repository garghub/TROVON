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
V_52 -> V_51 [ V_47 ] = NULL ;
}
}
static struct V_54 * F_43 ( struct V_54 * V_55 , const char * V_1 ,
struct V_40 * V_41 ,
const struct V_56 * V_57 )
{
struct V_37 * V_38 = F_22 ( V_41 -> V_58 ) ;
struct V_54 * V_59 ;
V_59 = F_44 ( V_1 , V_60 | 0444 , V_55 , V_38 , V_57 ) ;
if ( F_11 ( V_59 ) )
F_23 ( V_38 ) ;
return V_59 ;
}
int F_45 ( struct V_40 * V_41 , struct V_54 * V_61 )
{
struct V_40 * V_49 ;
struct V_54 * V_59 = NULL , * V_55 ;
int error ;
if ( ! V_61 ) {
struct V_40 * V_62 ;
V_62 = F_46 ( V_41 ) ;
V_59 = F_47 ( V_62 ) ;
V_59 = F_48 ( L_10 , V_59 ) ;
if ( F_11 ( V_59 ) )
goto V_63;
F_49 ( V_62 ) = V_61 = V_59 ;
}
if ( ! V_41 -> V_64 ) {
int V_4 , V_65 ;
V_4 = F_1 ( V_41 -> V_42 . V_1 , NULL ) ;
V_65 = snprintf ( NULL , 0 , L_11 , V_41 -> V_66 -> V_67 ) ;
V_41 -> V_64 = F_50 ( V_4 + V_65 + 1 , V_68 ) ;
if ( ! V_41 -> V_64 )
goto V_63;
F_1 ( V_41 -> V_42 . V_1 , V_41 -> V_64 ) ;
sprintf ( V_41 -> V_64 + V_4 , L_11 , V_41 -> V_66 -> V_67 ++ ) ;
}
V_59 = F_48 ( V_41 -> V_64 , V_61 ) ;
if ( F_11 ( V_59 ) )
goto V_63;
F_47 ( V_41 ) = V_55 = V_59 ;
V_59 = F_43 ( V_55 , L_12 , V_41 , & V_69 ) ;
if ( F_11 ( V_59 ) )
goto V_63;
V_41 -> V_51 [ V_70 ] = V_59 ;
V_59 = F_43 ( V_55 , L_13 , V_41 , & V_71 ) ;
if ( F_11 ( V_59 ) )
goto V_63;
V_41 -> V_51 [ V_72 ] = V_59 ;
V_59 = F_43 ( V_55 , L_14 , V_41 ,
& V_73 ) ;
if ( F_11 ( V_59 ) )
goto V_63;
V_41 -> V_51 [ V_74 ] = V_59 ;
if ( V_41 -> V_48 ) {
V_59 = F_43 ( V_55 , L_15 , V_41 ,
& V_75 ) ;
if ( F_11 ( V_59 ) )
goto V_63;
V_41 -> V_51 [ V_76 ] = V_59 ;
}
F_39 (child, &profile->base.profiles, base.list) {
error = F_45 ( V_49 , F_49 ( V_41 ) ) ;
if ( error )
goto V_77;
}
return 0 ;
V_63:
error = F_10 ( V_59 ) ;
V_77:
F_38 ( V_41 ) ;
return error ;
}
void F_51 ( struct V_78 * V_66 )
{
struct V_78 * V_79 ;
struct V_40 * V_49 ;
int V_47 ;
if ( ! V_66 )
return;
F_39 (child, &ns->base.profiles, base.list)
F_38 ( V_49 ) ;
F_39 (sub, &ns->sub_ns, base.list) {
F_52 ( & V_79 -> V_80 ) ;
F_51 ( V_79 ) ;
F_53 ( & V_79 -> V_80 ) ;
}
for ( V_47 = V_81 - 1 ; V_47 >= 0 ; -- V_47 ) {
F_41 ( V_66 -> V_51 [ V_47 ] ) ;
V_66 -> V_51 [ V_47 ] = NULL ;
}
}
int F_54 ( struct V_78 * V_66 , struct V_54 * V_61 ,
const char * V_1 )
{
struct V_78 * V_79 ;
struct V_40 * V_49 ;
struct V_54 * V_59 , * V_55 ;
int error ;
if ( ! V_1 )
V_1 = V_66 -> V_42 . V_1 ;
V_59 = F_48 ( V_1 , V_61 ) ;
if ( F_11 ( V_59 ) )
goto V_63;
F_55 ( V_66 ) = V_55 = V_59 ;
V_59 = F_48 ( L_10 , V_55 ) ;
if ( F_11 ( V_59 ) )
goto V_63;
F_56 ( V_66 ) = V_59 ;
V_59 = F_48 ( L_16 , V_55 ) ;
if ( F_11 ( V_59 ) )
goto V_63;
F_57 ( V_66 ) = V_59 ;
F_39 (child, &ns->base.profiles, base.list) {
error = F_45 ( V_49 , F_56 ( V_66 ) ) ;
if ( error )
goto V_77;
}
F_39 (sub, &ns->sub_ns, base.list) {
F_52 ( & V_79 -> V_80 ) ;
error = F_54 ( V_79 , F_57 ( V_66 ) , NULL ) ;
F_53 ( & V_79 -> V_80 ) ;
if ( error )
goto V_77;
}
return 0 ;
V_63:
error = F_10 ( V_59 ) ;
V_77:
F_51 ( V_66 ) ;
return error ;
}
static struct V_78 * F_58 ( struct V_78 * V_82 ,
struct V_78 * V_66 )
{
struct V_78 * V_61 , * V_83 ;
if ( ! F_59 ( & V_66 -> V_84 ) ) {
V_83 = F_60 ( & V_66 -> V_84 , F_61 ( * V_66 ) , V_42 . V_85 ) ;
F_52 ( & V_83 -> V_80 ) ;
return V_83 ;
}
V_61 = V_66 -> V_61 ;
while ( V_66 != V_82 ) {
F_53 ( & V_66 -> V_80 ) ;
V_83 = F_62 ( V_66 , V_42 . V_85 ) ;
if ( ! F_63 ( V_83 , & V_61 -> V_84 , V_42 . V_85 ) ) {
F_52 ( & V_83 -> V_80 ) ;
return V_83 ;
}
V_66 = V_61 ;
V_61 = V_61 -> V_61 ;
}
return NULL ;
}
static struct V_40 * F_64 ( struct V_78 * V_82 ,
struct V_78 * V_66 )
{
for (; V_66 ; V_66 = F_58 ( V_82 , V_66 ) ) {
if ( ! F_59 ( & V_66 -> V_42 . V_86 ) )
return F_60 ( & V_66 -> V_42 . V_86 ,
struct V_40 , V_42 . V_85 ) ;
}
return NULL ;
}
static struct V_40 * F_65 ( struct V_40 * V_62 )
{
struct V_40 * V_61 ;
struct V_78 * V_66 = V_62 -> V_66 ;
if ( ! F_59 ( & V_62 -> V_42 . V_86 ) )
return F_60 ( & V_62 -> V_42 . V_86 , F_61 ( * V_62 ) ,
V_42 . V_85 ) ;
V_61 = F_66 ( V_62 -> V_61 ,
F_67 ( & V_62 -> V_66 -> V_80 ) ) ;
while ( V_61 ) {
V_62 = F_62 ( V_62 , V_42 . V_85 ) ;
if ( ! F_63 ( V_62 , & V_61 -> V_42 . V_86 , V_42 . V_85 ) )
return V_62 ;
V_62 = V_61 ;
V_61 = F_66 ( V_61 -> V_61 ,
F_67 ( & V_61 -> V_66 -> V_80 ) ) ;
}
V_62 = F_62 ( V_62 , V_42 . V_85 ) ;
if ( ! F_63 ( V_62 , & V_66 -> V_42 . V_86 , V_42 . V_85 ) )
return V_62 ;
return NULL ;
}
static struct V_40 * F_68 ( struct V_78 * V_82 ,
struct V_40 * V_41 )
{
struct V_40 * V_83 = F_65 ( V_41 ) ;
if ( V_83 )
return V_83 ;
return F_64 ( V_82 , F_58 ( V_82 , V_41 -> V_66 ) ) ;
}
static void * F_69 ( struct V_24 * V_16 , T_3 * V_9 )
{
struct V_40 * V_41 = NULL ;
struct V_78 * V_82 = F_70 () -> V_66 ;
T_3 V_87 = * V_9 ;
V_16 -> V_29 = F_71 ( V_82 ) ;
F_52 ( & V_82 -> V_80 ) ;
V_41 = F_64 ( V_82 , V_82 ) ;
for (; V_41 && V_87 > 0 ; V_87 -- )
V_41 = F_68 ( V_82 , V_41 ) ;
return V_41 ;
}
static void * F_72 ( struct V_24 * V_16 , void * V_62 , T_3 * V_9 )
{
struct V_40 * V_41 = V_62 ;
struct V_78 * V_66 = V_16 -> V_29 ;
( * V_9 ) ++ ;
return F_68 ( V_66 , V_41 ) ;
}
static void F_73 ( struct V_24 * V_16 , void * V_62 )
{
struct V_40 * V_41 = V_62 ;
struct V_78 * V_82 = V_16 -> V_29 , * V_66 ;
if ( V_41 ) {
for ( V_66 = V_41 -> V_66 ; V_66 && V_66 != V_82 ; V_66 = V_66 -> V_61 )
F_53 ( & V_66 -> V_80 ) ;
}
F_53 ( & V_82 -> V_80 ) ;
F_74 ( V_82 ) ;
}
static int F_75 ( struct V_24 * V_16 , void * V_62 )
{
struct V_40 * V_41 = (struct V_40 * ) V_62 ;
struct V_78 * V_82 = V_16 -> V_29 ;
if ( V_41 -> V_66 != V_82 )
F_17 ( V_16 , L_17 , F_76 ( V_82 , V_41 -> V_66 ) ) ;
F_17 ( V_16 , L_18 , V_41 -> V_42 . V_88 ,
V_43 [ V_41 -> V_44 ] ) ;
return 0 ;
}
static int F_77 ( struct V_35 * V_35 , struct V_15 * V_15 )
{
return F_78 ( V_15 , & V_89 ) ;
}
static int F_79 ( struct V_35 * V_35 , struct V_15 * V_15 )
{
return F_80 ( V_35 , V_15 ) ;
}
static int T_5 F_81 ( struct V_27 * V_28 ,
struct V_54 * V_61 )
{
int error = 0 ;
V_28 -> V_54 = F_44 ( V_28 -> V_1 ,
V_60 | V_28 -> V_44 ,
V_61 , V_28 ,
V_28 -> V_90 ) ;
if ( F_11 ( V_28 -> V_54 ) ) {
error = F_10 ( V_28 -> V_54 ) ;
V_28 -> V_54 = NULL ;
}
return error ;
}
static int T_5 F_82 ( struct V_27 * V_91 ,
struct V_54 * V_61 )
{
struct V_27 * V_28 ;
struct V_54 * V_55 ;
int error ;
V_55 = F_48 ( V_91 -> V_1 , V_61 ) ;
if ( F_11 ( V_55 ) )
return F_10 ( V_55 ) ;
V_91 -> V_54 = V_55 ;
for ( V_28 = V_91 -> V_26 . V_92 ; V_28 && V_28 -> V_1 ; ++ V_28 ) {
if ( V_28 -> V_30 == V_93 )
error = F_82 ( V_28 , V_91 -> V_54 ) ;
else
error = F_81 ( V_28 , V_91 -> V_54 ) ;
if ( error )
goto V_94;
}
return 0 ;
V_94:
F_83 ( V_91 ) ;
return error ;
}
static void T_5 F_84 ( struct V_27 * V_28 )
{
if ( ! V_28 -> V_54 )
return;
F_41 ( V_28 -> V_54 ) ;
V_28 -> V_54 = NULL ;
}
static void T_5 F_83 ( struct V_27 * V_91 )
{
struct V_27 * V_28 ;
for ( V_28 = V_91 -> V_26 . V_92 ; V_28 && V_28 -> V_1 ; ++ V_28 ) {
if ( V_28 -> V_30 == V_93 )
F_83 ( V_28 ) ;
else
F_84 ( V_28 ) ;
}
F_84 ( V_91 ) ;
}
void T_5 F_85 ( void )
{
F_83 ( & V_27 ) ;
}
static int T_5 F_86 ( void )
{
int error ;
if ( ! V_95 )
return 0 ;
if ( V_27 . V_54 ) {
F_87 ( L_19 , V_96 ) ;
return - V_97 ;
}
error = F_82 ( & V_27 , NULL ) ;
if ( error )
goto error;
error = F_54 ( V_98 , V_27 . V_54 ,
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

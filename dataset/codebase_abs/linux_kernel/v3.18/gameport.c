static unsigned int F_1 ( void )
{
unsigned long V_1 ;
unsigned int V_2 ;
F_2 ( & V_3 , V_1 ) ;
F_3 ( 0x00 , 0x43 ) ;
V_2 = F_4 ( 0x40 ) ;
V_2 |= F_4 ( 0x40 ) << 8 ;
F_5 ( & V_3 , V_1 ) ;
return V_2 ;
}
static int F_6 ( struct V_4 * V_4 )
{
unsigned int V_5 , V_6 , V_7 ;
T_1 V_8 , V_9 , V_10 ;
unsigned long V_1 ;
if ( F_7 ( V_4 , NULL , V_11 ) )
return 0 ;
V_7 = ~ 0 ;
for ( V_5 = 0 ; V_5 < 50 ; V_5 ++ ) {
F_8 ( V_1 ) ;
V_8 = F_9 () ;
for ( V_6 = 0 ; V_6 < 50 ; V_6 ++ )
F_10 ( V_4 ) ;
V_9 = F_9 () ;
V_10 = F_9 () ;
F_11 ( V_1 ) ;
F_12 ( V_5 * 10 ) ;
V_6 = ( V_9 - V_8 ) - ( V_10 - V_9 ) ;
if ( V_6 < V_7 )
V_7 = V_6 ;
}
F_13 ( V_4 ) ;
V_6 = 1000000 * 50 ;
if ( V_7 )
V_6 /= V_7 ;
return V_6 ;
}
static int F_14 ( struct V_4 * V_4 )
{
#if F_15 ( V_12 )
unsigned int V_5 , V_6 , V_8 , V_9 , V_10 , V_7 ;
unsigned long V_1 ;
if ( F_7 ( V_4 , NULL , V_11 ) )
return 0 ;
V_7 = 1 << 30 ;
for( V_5 = 0 ; V_5 < 50 ; V_5 ++ ) {
F_8 ( V_1 ) ;
F_16 ( V_8 ) ;
for ( V_6 = 0 ; V_6 < 50 ; V_6 ++ ) F_10 ( V_4 ) ;
F_16 ( V_9 ) ;
F_16 ( V_10 ) ;
F_11 ( V_1 ) ;
F_12 ( V_5 * 10 ) ;
if ( ( V_6 = F_17 ( V_9 , V_8 ) - F_17 ( V_10 , V_9 ) ) < V_7 ) V_7 = V_6 ;
}
F_13 ( V_4 ) ;
return 59659 / ( V_7 < 1 ? 1 : V_7 ) ;
#elif F_15 ( V_13 )
unsigned int V_5 , V_6 ;
unsigned long V_7 , V_8 , V_9 , V_1 ;
if ( F_7 ( V_4 , NULL , V_11 ) )
return 0 ;
V_7 = 1 << 30 ;
for( V_5 = 0 ; V_5 < 50 ; V_5 ++ ) {
F_8 ( V_1 ) ;
F_18 ( V_8 ) ;
for ( V_6 = 0 ; V_6 < 50 ; V_6 ++ ) F_10 ( V_4 ) ;
F_18 ( V_9 ) ;
F_11 ( V_1 ) ;
F_12 ( V_5 * 10 ) ;
if ( V_9 - V_8 < V_7 ) V_7 = V_9 - V_8 ;
}
F_13 ( V_4 ) ;
return ( F_19 ( V_14 . V_15 ) *
( unsigned long ) V_16 / ( 1000 / 50 ) ) / ( V_7 < 1 ? 1 : V_7 ) ;
#else
unsigned int V_17 , V_6 = 0 ;
if ( F_7 ( V_4 , NULL , V_11 ) )
return 0 ;
V_17 = V_18 ; while ( V_17 == V_18 ) ;
V_17 = V_18 ; while ( V_17 == V_18 ) { V_6 ++ ; F_10 ( V_4 ) ; }
F_13 ( V_4 ) ;
return V_6 * V_16 / 1000 ;
#endif
}
void F_20 ( struct V_4 * V_4 )
{
F_21 ( & V_4 -> V_19 ) ;
if ( ! V_4 -> V_20 ++ ) {
F_22 ( ! V_4 -> V_21 ) ;
F_22 ( ! V_4 -> V_22 ) ;
F_23 ( & V_4 -> V_23 , V_18 + F_24 ( V_4 -> V_22 ) ) ;
}
F_25 ( & V_4 -> V_19 ) ;
}
void F_26 ( struct V_4 * V_4 )
{
F_21 ( & V_4 -> V_19 ) ;
if ( ! -- V_4 -> V_20 )
F_27 ( & V_4 -> V_23 ) ;
F_25 ( & V_4 -> V_19 ) ;
}
static void F_28 ( unsigned long V_24 )
{
struct V_4 * V_4 = (struct V_4 * ) V_24 ;
V_4 -> V_21 ( V_4 ) ;
if ( V_4 -> V_20 )
F_23 ( & V_4 -> V_23 , V_18 + F_24 ( V_4 -> V_22 ) ) ;
}
static int F_29 ( struct V_4 * V_4 , struct V_25 * V_26 )
{
int error ;
V_4 -> V_27 . V_28 = & V_26 -> V_28 ;
if ( V_26 -> V_29 ( V_4 , V_26 ) ) {
V_4 -> V_27 . V_28 = NULL ;
return - V_30 ;
}
error = F_30 ( & V_4 -> V_27 ) ;
if ( error ) {
F_31 ( & V_4 -> V_27 ,
L_1 ,
V_4 -> V_31 , V_4 -> V_32 ,
V_26 -> V_33 , error ) ;
V_26 -> V_34 ( V_4 ) ;
V_4 -> V_27 . V_28 = NULL ;
return error ;
}
return 0 ;
}
static void F_32 ( struct V_4 * V_4 )
{
int error ;
error = F_33 ( & V_4 -> V_27 ) ;
if ( error < 0 )
F_31 ( & V_4 -> V_27 ,
L_2 ,
V_4 -> V_31 , V_4 -> V_32 , error ) ;
}
static struct V_35 * F_34 ( void )
{
struct V_35 * V_36 = NULL ;
unsigned long V_1 ;
F_35 ( & V_37 , V_1 ) ;
if ( ! F_36 ( & V_38 ) ) {
V_36 = F_37 ( & V_38 ,
struct V_35 , V_39 ) ;
F_38 ( & V_36 -> V_39 ) ;
}
F_39 ( & V_37 , V_1 ) ;
return V_36 ;
}
static void F_40 ( struct V_35 * V_36 )
{
F_41 ( V_36 -> V_40 ) ;
F_42 ( V_36 ) ;
}
static void F_43 ( struct V_35 * V_36 )
{
struct V_35 * V_41 , * V_42 ;
unsigned long V_1 ;
F_35 ( & V_37 , V_1 ) ;
F_44 (e, next, &gameport_event_list, node) {
if ( V_36 -> V_43 == V_41 -> V_43 ) {
if ( V_36 -> type != V_41 -> type )
break;
F_38 ( & V_41 -> V_39 ) ;
F_40 ( V_41 ) ;
}
}
F_39 ( & V_37 , V_1 ) ;
}
static void F_45 ( struct V_44 * V_45 )
{
struct V_35 * V_36 ;
F_46 ( & V_46 ) ;
if ( ( V_36 = F_34 () ) ) {
switch ( V_36 -> type ) {
case V_47 :
F_47 ( V_36 -> V_43 ) ;
break;
case V_48 :
F_48 ( V_36 -> V_43 ) ;
break;
}
F_43 ( V_36 ) ;
F_40 ( V_36 ) ;
}
F_49 ( & V_46 ) ;
}
static int F_50 ( void * V_43 , struct V_49 * V_40 ,
enum V_50 V_51 )
{
unsigned long V_1 ;
struct V_35 * V_36 ;
int V_52 = 0 ;
F_35 ( & V_37 , V_1 ) ;
F_51 (event, &gameport_event_list, node) {
if ( V_36 -> V_43 == V_43 ) {
if ( V_36 -> type == V_51 )
goto V_53;
break;
}
}
V_36 = F_52 ( sizeof( struct V_35 ) , V_54 ) ;
if ( ! V_36 ) {
F_53 ( L_3 , V_51 ) ;
V_52 = - V_55 ;
goto V_53;
}
if ( ! F_54 ( V_40 ) ) {
F_55 ( L_4 ,
V_51 ) ;
F_42 ( V_36 ) ;
V_52 = - V_56 ;
goto V_53;
}
V_36 -> type = V_51 ;
V_36 -> V_43 = V_43 ;
V_36 -> V_40 = V_40 ;
F_56 ( & V_36 -> V_39 , & V_38 ) ;
F_57 ( V_57 , & V_58 ) ;
V_53:
F_39 ( & V_37 , V_1 ) ;
return V_52 ;
}
static void F_58 ( void * V_43 )
{
struct V_35 * V_36 , * V_42 ;
unsigned long V_1 ;
F_35 ( & V_37 , V_1 ) ;
F_44 (event, next, &gameport_event_list, node) {
if ( V_36 -> V_43 == V_43 ) {
F_38 ( & V_36 -> V_39 ) ;
F_40 ( V_36 ) ;
}
}
F_39 ( & V_37 , V_1 ) ;
}
static struct V_4 * F_59 ( struct V_4 * V_59 )
{
struct V_35 * V_36 ;
struct V_4 * V_4 , * V_60 = NULL ;
unsigned long V_1 ;
F_35 ( & V_37 , V_1 ) ;
F_60 (event, &gameport_event_list, node) {
if ( V_36 -> type == V_47 ) {
V_4 = V_36 -> V_43 ;
if ( V_4 -> V_59 == V_59 ) {
V_60 = V_4 ;
break;
}
}
}
F_39 ( & V_37 , V_1 ) ;
return V_60 ;
}
static T_2 F_61 ( struct V_61 * V_27 , struct V_62 * V_63 , char * V_64 )
{
struct V_4 * V_4 = F_62 ( V_27 ) ;
return sprintf ( V_64 , L_5 , V_4 -> V_32 ) ;
}
static T_2 F_63 ( struct V_61 * V_27 , struct V_62 * V_63 , const char * V_64 , T_3 V_2 )
{
struct V_4 * V_4 = F_62 ( V_27 ) ;
struct V_65 * V_26 ;
int error ;
error = F_64 ( & V_46 ) ;
if ( error )
return error ;
if ( ! strncmp ( V_64 , L_6 , V_2 ) ) {
F_65 ( V_4 ) ;
} else if ( ! strncmp ( V_64 , L_7 , V_2 ) ) {
F_66 ( V_4 ) ;
} else if ( ! strncmp ( V_64 , L_8 , V_2 ) ) {
F_65 ( V_4 ) ;
F_32 ( V_4 ) ;
} else if ( ( V_26 = F_67 ( V_64 , & V_66 ) ) != NULL ) {
F_65 ( V_4 ) ;
error = F_29 ( V_4 , F_68 ( V_26 ) ) ;
} else {
error = - V_56 ;
}
F_49 ( & V_46 ) ;
return error ? error : V_2 ;
}
static void F_69 ( struct V_61 * V_27 )
{
struct V_4 * V_4 = F_62 ( V_27 ) ;
F_42 ( V_4 ) ;
F_41 ( V_67 ) ;
}
void F_70 ( struct V_4 * V_4 , const char * V_68 , ... )
{
T_4 args ;
va_start ( args , V_68 ) ;
vsnprintf ( V_4 -> V_31 , sizeof( V_4 -> V_31 ) , V_68 , args ) ;
va_end ( args ) ;
}
static void F_71 ( struct V_4 * V_4 )
{
static T_5 V_69 = F_72 ( 0 ) ;
F_73 ( V_67 ) ;
F_74 ( & V_4 -> V_70 ) ;
F_75 ( & V_4 -> V_27 ) ;
F_76 ( & V_4 -> V_27 , L_9 ,
( unsigned long ) F_77 ( & V_69 ) - 1 ) ;
V_4 -> V_27 . V_71 = & V_66 ;
V_4 -> V_27 . V_72 = F_69 ;
if ( V_4 -> V_59 )
V_4 -> V_27 . V_59 = & V_4 -> V_59 -> V_27 ;
F_78 ( & V_4 -> V_39 ) ;
F_79 ( & V_4 -> V_19 ) ;
F_80 ( & V_4 -> V_23 ) ;
V_4 -> V_23 . V_73 = F_28 ;
V_4 -> V_23 . V_74 = ( unsigned long ) V_4 ;
}
static void F_47 ( struct V_4 * V_4 )
{
int error ;
if ( V_4 -> V_59 )
V_4 -> V_59 -> V_60 = V_4 ;
V_4 -> V_75 = V_76 ?
F_6 ( V_4 ) :
F_14 ( V_4 ) ;
F_56 ( & V_4 -> V_39 , & V_77 ) ;
if ( V_4 -> V_78 )
F_81 ( & V_4 -> V_27 , L_10 ,
V_4 -> V_32 , V_4 -> V_31 , V_4 -> V_78 , V_4 -> V_75 ) ;
else
F_81 ( & V_4 -> V_27 , L_11 ,
V_4 -> V_32 , V_4 -> V_31 , V_4 -> V_75 ) ;
error = F_82 ( & V_4 -> V_27 ) ;
if ( error )
F_83 ( & V_4 -> V_27 ,
L_12 ,
V_4 -> V_31 , V_4 -> V_32 , error ) ;
}
static void F_84 ( struct V_4 * V_4 )
{
struct V_4 * V_60 ;
V_60 = F_59 ( V_4 ) ;
if ( V_60 ) {
F_58 ( V_60 ) ;
F_85 ( & V_60 -> V_27 ) ;
}
if ( V_4 -> V_59 ) {
V_4 -> V_59 -> V_60 = NULL ;
V_4 -> V_59 = NULL ;
}
if ( F_86 ( & V_4 -> V_27 ) )
F_87 ( & V_4 -> V_27 ) ;
F_38 ( & V_4 -> V_39 ) ;
F_58 ( V_4 ) ;
F_85 ( & V_4 -> V_27 ) ;
}
static void F_66 ( struct V_4 * V_4 )
{
do {
if ( ! V_4 -> V_26 || ! V_4 -> V_26 -> V_79 || V_4 -> V_26 -> V_79 ( V_4 ) ) {
F_65 ( V_4 ) ;
F_32 ( V_4 ) ;
break;
}
V_4 = V_4 -> V_60 ;
} while ( V_4 );
}
static void F_65 ( struct V_4 * V_4 )
{
struct V_4 * V_80 , * V_59 ;
if ( V_4 -> V_60 ) {
for ( V_80 = V_4 ; V_80 -> V_60 ; V_80 = V_80 -> V_60 )
;
do {
V_59 = V_80 -> V_59 ;
F_88 ( & V_80 -> V_27 ) ;
F_84 ( V_80 ) ;
} while ( ( V_80 = V_59 ) != V_4 );
}
F_88 ( & V_4 -> V_27 ) ;
}
void F_89 ( struct V_4 * V_4 , struct V_49 * V_40 )
{
F_71 ( V_4 ) ;
F_50 ( V_4 , V_40 , V_47 ) ;
}
void F_90 ( struct V_4 * V_4 )
{
F_46 ( & V_46 ) ;
F_65 ( V_4 ) ;
F_84 ( V_4 ) ;
F_49 ( & V_46 ) ;
}
static T_2 F_91 ( struct V_65 * V_26 , char * V_64 )
{
struct V_25 * V_28 = F_68 ( V_26 ) ;
return sprintf ( V_64 , L_5 , V_28 -> V_33 ? V_28 -> V_33 : L_13 ) ;
}
static int F_92 ( struct V_61 * V_27 )
{
struct V_4 * V_4 = F_62 ( V_27 ) ;
struct V_25 * V_26 = F_68 ( V_27 -> V_28 ) ;
V_26 -> V_29 ( V_4 , V_26 ) ;
return V_4 -> V_26 ? 0 : - V_30 ;
}
static int F_93 ( struct V_61 * V_27 )
{
struct V_4 * V_4 = F_62 ( V_27 ) ;
struct V_25 * V_26 = F_68 ( V_27 -> V_28 ) ;
V_26 -> V_34 ( V_4 ) ;
return 0 ;
}
static void F_48 ( struct V_25 * V_26 )
{
int error ;
error = F_94 ( & V_26 -> V_28 ) ;
if ( error )
F_53 ( L_14 ,
V_26 -> V_28 . V_32 , error ) ;
}
int F_95 ( struct V_25 * V_26 , struct V_49 * V_40 ,
const char * V_81 )
{
int error ;
V_26 -> V_28 . V_71 = & V_66 ;
V_26 -> V_28 . V_40 = V_40 ;
V_26 -> V_28 . V_81 = V_81 ;
V_26 -> V_82 = true ;
error = F_96 ( & V_26 -> V_28 ) ;
if ( error ) {
F_53 ( L_15 ,
V_26 -> V_28 . V_32 , error ) ;
return error ;
}
V_26 -> V_82 = false ;
error = F_50 ( V_26 , NULL , V_48 ) ;
if ( error ) {
F_97 ( & V_26 -> V_28 ) ;
return error ;
}
return 0 ;
}
void F_98 ( struct V_25 * V_26 )
{
struct V_4 * V_4 ;
F_46 ( & V_46 ) ;
V_26 -> V_82 = true ;
F_58 ( V_26 ) ;
V_83:
F_60 (gameport, &gameport_list, node) {
if ( V_4 -> V_26 == V_26 ) {
F_65 ( V_4 ) ;
F_32 ( V_4 ) ;
goto V_83;
}
}
F_97 ( & V_26 -> V_28 ) ;
F_49 ( & V_46 ) ;
}
static int F_99 ( struct V_61 * V_27 , struct V_65 * V_26 )
{
struct V_25 * V_84 = F_68 ( V_26 ) ;
return ! V_84 -> V_82 ;
}
static void F_100 ( struct V_4 * V_4 , struct V_25 * V_26 )
{
F_46 ( & V_4 -> V_70 ) ;
V_4 -> V_26 = V_26 ;
F_49 ( & V_4 -> V_70 ) ;
}
int F_7 ( struct V_4 * V_4 , struct V_25 * V_26 , int V_85 )
{
if ( V_4 -> V_86 ) {
if ( V_4 -> V_86 ( V_4 , V_85 ) ) {
return - 1 ;
}
} else {
if ( V_85 != V_11 )
return - 1 ;
}
F_100 ( V_4 , V_26 ) ;
return 0 ;
}
void F_13 ( struct V_4 * V_4 )
{
F_101 ( & V_4 -> V_23 ) ;
V_4 -> V_21 = NULL ;
V_4 -> V_22 = 0 ;
F_100 ( V_4 , NULL ) ;
if ( V_4 -> V_87 )
V_4 -> V_87 ( V_4 ) ;
}
static int T_6 F_102 ( void )
{
int error ;
error = F_103 ( & V_66 ) ;
if ( error ) {
F_53 ( L_16 , error ) ;
return error ;
}
return 0 ;
}
static void T_7 F_104 ( void )
{
F_105 ( & V_66 ) ;
F_106 ( & V_58 ) ;
}

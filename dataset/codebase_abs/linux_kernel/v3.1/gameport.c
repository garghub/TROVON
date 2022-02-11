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
#if F_7 ( V_5 )
unsigned int V_6 , V_7 , V_8 , V_9 , V_10 , V_11 ;
unsigned long V_1 ;
if ( F_8 ( V_4 , NULL , V_12 ) )
return 0 ;
V_11 = 1 << 30 ;
for( V_6 = 0 ; V_6 < 50 ; V_6 ++ ) {
F_9 ( V_1 ) ;
F_10 ( V_8 ) ;
for ( V_7 = 0 ; V_7 < 50 ; V_7 ++ ) F_11 ( V_4 ) ;
F_10 ( V_9 ) ;
F_10 ( V_10 ) ;
F_12 ( V_1 ) ;
F_13 ( V_6 * 10 ) ;
if ( ( V_7 = F_14 ( V_9 , V_8 ) - F_14 ( V_10 , V_9 ) ) < V_11 ) V_11 = V_7 ;
}
F_15 ( V_4 ) ;
return 59659 / ( V_11 < 1 ? 1 : V_11 ) ;
#elif F_7 ( V_13 )
unsigned int V_6 , V_7 ;
unsigned long V_11 , V_8 , V_9 , V_1 ;
if ( F_8 ( V_4 , NULL , V_12 ) )
return 0 ;
V_11 = 1 << 30 ;
for( V_6 = 0 ; V_6 < 50 ; V_6 ++ ) {
F_9 ( V_1 ) ;
F_16 ( V_8 ) ;
for ( V_7 = 0 ; V_7 < 50 ; V_7 ++ ) F_11 ( V_4 ) ;
F_16 ( V_9 ) ;
F_12 ( V_1 ) ;
F_13 ( V_6 * 10 ) ;
if ( V_9 - V_8 < V_11 ) V_11 = V_9 - V_8 ;
}
F_15 ( V_4 ) ;
return ( F_17 ( V_14 . V_15 ) *
( unsigned long ) V_16 / ( 1000 / 50 ) ) / ( V_11 < 1 ? 1 : V_11 ) ;
#else
unsigned int V_17 , V_7 = 0 ;
if ( F_8 ( V_4 , NULL , V_12 ) )
return 0 ;
V_17 = V_18 ; while ( V_17 == V_18 ) ;
V_17 = V_18 ; while ( V_17 == V_18 ) { V_7 ++ ; F_11 ( V_4 ) ; }
F_15 ( V_4 ) ;
return V_7 * V_16 / 1000 ;
#endif
}
void F_18 ( struct V_4 * V_4 )
{
F_19 ( & V_4 -> V_19 ) ;
if ( ! V_4 -> V_20 ++ ) {
F_20 ( ! V_4 -> V_21 ) ;
F_20 ( ! V_4 -> V_22 ) ;
F_21 ( & V_4 -> V_23 , V_18 + F_22 ( V_4 -> V_22 ) ) ;
}
F_23 ( & V_4 -> V_19 ) ;
}
void F_24 ( struct V_4 * V_4 )
{
F_19 ( & V_4 -> V_19 ) ;
if ( ! -- V_4 -> V_20 )
F_25 ( & V_4 -> V_23 ) ;
F_23 ( & V_4 -> V_19 ) ;
}
static void F_26 ( unsigned long V_24 )
{
struct V_4 * V_4 = (struct V_4 * ) V_24 ;
V_4 -> V_21 ( V_4 ) ;
if ( V_4 -> V_20 )
F_21 ( & V_4 -> V_23 , V_18 + F_22 ( V_4 -> V_22 ) ) ;
}
static int F_27 ( struct V_4 * V_4 , struct V_25 * V_26 )
{
int error ;
V_4 -> V_27 . V_28 = & V_26 -> V_28 ;
if ( V_26 -> V_29 ( V_4 , V_26 ) ) {
V_4 -> V_27 . V_28 = NULL ;
return - V_30 ;
}
error = F_28 ( & V_4 -> V_27 ) ;
if ( error ) {
F_29 ( & V_4 -> V_27 ,
L_1 ,
V_4 -> V_31 , V_4 -> V_32 ,
V_26 -> V_33 , error ) ;
V_26 -> V_34 ( V_4 ) ;
V_4 -> V_27 . V_28 = NULL ;
return error ;
}
return 0 ;
}
static void F_30 ( struct V_4 * V_4 )
{
int error ;
error = F_31 ( & V_4 -> V_27 ) ;
if ( error < 0 )
F_29 ( & V_4 -> V_27 ,
L_2 ,
V_4 -> V_31 , V_4 -> V_32 , error ) ;
}
static struct V_35 * F_32 ( void )
{
struct V_35 * V_36 = NULL ;
unsigned long V_1 ;
F_33 ( & V_37 , V_1 ) ;
if ( ! F_34 ( & V_38 ) ) {
V_36 = F_35 ( & V_38 ,
struct V_35 , V_39 ) ;
F_36 ( & V_36 -> V_39 ) ;
}
F_37 ( & V_37 , V_1 ) ;
return V_36 ;
}
static void F_38 ( struct V_35 * V_36 )
{
F_39 ( V_36 -> V_40 ) ;
F_40 ( V_36 ) ;
}
static void F_41 ( struct V_35 * V_36 )
{
struct V_35 * V_41 , * V_42 ;
unsigned long V_1 ;
F_33 ( & V_37 , V_1 ) ;
F_42 (e, next, &gameport_event_list, node) {
if ( V_36 -> V_43 == V_41 -> V_43 ) {
if ( V_36 -> type != V_41 -> type )
break;
F_36 ( & V_41 -> V_39 ) ;
F_38 ( V_41 ) ;
}
}
F_37 ( & V_37 , V_1 ) ;
}
static void F_43 ( struct V_44 * V_45 )
{
struct V_35 * V_36 ;
F_44 ( & V_46 ) ;
if ( ( V_36 = F_32 () ) ) {
switch ( V_36 -> type ) {
case V_47 :
F_45 ( V_36 -> V_43 ) ;
break;
case V_48 :
F_46 ( V_36 -> V_43 ) ;
break;
}
F_41 ( V_36 ) ;
F_38 ( V_36 ) ;
}
F_47 ( & V_46 ) ;
}
static int F_48 ( void * V_43 , struct V_49 * V_40 ,
enum V_50 V_51 )
{
unsigned long V_1 ;
struct V_35 * V_36 ;
int V_52 = 0 ;
F_33 ( & V_37 , V_1 ) ;
F_49 (event, &gameport_event_list, node) {
if ( V_36 -> V_43 == V_43 ) {
if ( V_36 -> type == V_51 )
goto V_53;
break;
}
}
V_36 = F_50 ( sizeof( struct V_35 ) , V_54 ) ;
if ( ! V_36 ) {
F_51 ( L_3 , V_51 ) ;
V_52 = - V_55 ;
goto V_53;
}
if ( ! F_52 ( V_40 ) ) {
F_53 ( L_4 ,
V_51 ) ;
F_40 ( V_36 ) ;
V_52 = - V_56 ;
goto V_53;
}
V_36 -> type = V_51 ;
V_36 -> V_43 = V_43 ;
V_36 -> V_40 = V_40 ;
F_54 ( & V_36 -> V_39 , & V_38 ) ;
F_55 ( V_57 , & V_58 ) ;
V_53:
F_37 ( & V_37 , V_1 ) ;
return V_52 ;
}
static void F_56 ( void * V_43 )
{
struct V_35 * V_36 , * V_42 ;
unsigned long V_1 ;
F_33 ( & V_37 , V_1 ) ;
F_42 (event, next, &gameport_event_list, node) {
if ( V_36 -> V_43 == V_43 ) {
F_36 ( & V_36 -> V_39 ) ;
F_38 ( V_36 ) ;
}
}
F_37 ( & V_37 , V_1 ) ;
}
static struct V_4 * F_57 ( struct V_4 * V_59 )
{
struct V_35 * V_36 ;
struct V_4 * V_4 , * V_60 = NULL ;
unsigned long V_1 ;
F_33 ( & V_37 , V_1 ) ;
F_58 (event, &gameport_event_list, node) {
if ( V_36 -> type == V_47 ) {
V_4 = V_36 -> V_43 ;
if ( V_4 -> V_59 == V_59 ) {
V_60 = V_4 ;
break;
}
}
}
F_37 ( & V_37 , V_1 ) ;
return V_60 ;
}
static T_1 F_59 ( struct V_61 * V_27 , struct V_62 * V_63 , char * V_64 )
{
struct V_4 * V_4 = F_60 ( V_27 ) ;
return sprintf ( V_64 , L_5 , V_4 -> V_32 ) ;
}
static T_1 F_61 ( struct V_61 * V_27 , struct V_62 * V_63 , const char * V_64 , T_2 V_2 )
{
struct V_4 * V_4 = F_60 ( V_27 ) ;
struct V_65 * V_26 ;
int error ;
error = F_62 ( & V_46 ) ;
if ( error )
return error ;
if ( ! strncmp ( V_64 , L_6 , V_2 ) ) {
F_63 ( V_4 ) ;
} else if ( ! strncmp ( V_64 , L_7 , V_2 ) ) {
F_64 ( V_4 ) ;
} else if ( ! strncmp ( V_64 , L_8 , V_2 ) ) {
F_63 ( V_4 ) ;
F_30 ( V_4 ) ;
} else if ( ( V_26 = F_65 ( V_64 , & V_66 ) ) != NULL ) {
F_63 ( V_4 ) ;
error = F_27 ( V_4 , F_66 ( V_26 ) ) ;
F_67 ( V_26 ) ;
} else {
error = - V_56 ;
}
F_47 ( & V_46 ) ;
return error ? error : V_2 ;
}
static void F_68 ( struct V_61 * V_27 )
{
struct V_4 * V_4 = F_60 ( V_27 ) ;
F_40 ( V_4 ) ;
F_39 ( V_67 ) ;
}
void F_69 ( struct V_4 * V_4 , const char * V_68 , ... )
{
T_3 args ;
va_start ( args , V_68 ) ;
vsnprintf ( V_4 -> V_31 , sizeof( V_4 -> V_31 ) , V_68 , args ) ;
va_end ( args ) ;
}
static void F_70 ( struct V_4 * V_4 )
{
static T_4 V_69 = F_71 ( 0 ) ;
F_72 ( V_67 ) ;
F_73 ( & V_4 -> V_70 ) ;
F_74 ( & V_4 -> V_27 ) ;
F_75 ( & V_4 -> V_27 , L_9 ,
( unsigned long ) F_76 ( & V_69 ) - 1 ) ;
V_4 -> V_27 . V_71 = & V_66 ;
V_4 -> V_27 . V_72 = F_68 ;
if ( V_4 -> V_59 )
V_4 -> V_27 . V_59 = & V_4 -> V_59 -> V_27 ;
F_77 ( & V_4 -> V_39 ) ;
F_78 ( & V_4 -> V_19 ) ;
F_79 ( & V_4 -> V_23 ) ;
V_4 -> V_23 . V_73 = F_26 ;
V_4 -> V_23 . V_74 = ( unsigned long ) V_4 ;
}
static void F_45 ( struct V_4 * V_4 )
{
int error ;
if ( V_4 -> V_59 )
V_4 -> V_59 -> V_60 = V_4 ;
V_4 -> V_75 = F_6 ( V_4 ) ;
F_54 ( & V_4 -> V_39 , & V_76 ) ;
if ( V_4 -> V_77 )
F_80 ( & V_4 -> V_27 , L_10 ,
V_4 -> V_32 , V_4 -> V_31 , V_4 -> V_77 , V_4 -> V_75 ) ;
else
F_80 ( & V_4 -> V_27 , L_11 ,
V_4 -> V_32 , V_4 -> V_31 , V_4 -> V_75 ) ;
error = F_81 ( & V_4 -> V_27 ) ;
if ( error )
F_82 ( & V_4 -> V_27 ,
L_12 ,
V_4 -> V_31 , V_4 -> V_32 , error ) ;
}
static void F_83 ( struct V_4 * V_4 )
{
struct V_4 * V_60 ;
V_60 = F_57 ( V_4 ) ;
if ( V_60 ) {
F_56 ( V_60 ) ;
F_84 ( & V_60 -> V_27 ) ;
}
if ( V_4 -> V_59 ) {
V_4 -> V_59 -> V_60 = NULL ;
V_4 -> V_59 = NULL ;
}
if ( F_85 ( & V_4 -> V_27 ) )
F_86 ( & V_4 -> V_27 ) ;
F_36 ( & V_4 -> V_39 ) ;
F_56 ( V_4 ) ;
F_84 ( & V_4 -> V_27 ) ;
}
static void F_64 ( struct V_4 * V_4 )
{
do {
if ( ! V_4 -> V_26 || ! V_4 -> V_26 -> V_78 || V_4 -> V_26 -> V_78 ( V_4 ) ) {
F_63 ( V_4 ) ;
F_30 ( V_4 ) ;
break;
}
V_4 = V_4 -> V_60 ;
} while ( V_4 );
}
static void F_63 ( struct V_4 * V_4 )
{
struct V_4 * V_79 , * V_59 ;
if ( V_4 -> V_60 ) {
for ( V_79 = V_4 ; V_79 -> V_60 ; V_79 = V_79 -> V_60 )
;
do {
V_59 = V_79 -> V_59 ;
F_87 ( & V_79 -> V_27 ) ;
F_83 ( V_79 ) ;
} while ( ( V_79 = V_59 ) != V_4 );
}
F_87 ( & V_4 -> V_27 ) ;
}
void F_88 ( struct V_4 * V_4 , struct V_49 * V_40 )
{
F_70 ( V_4 ) ;
F_48 ( V_4 , V_40 , V_47 ) ;
}
void F_89 ( struct V_4 * V_4 )
{
F_44 ( & V_46 ) ;
F_63 ( V_4 ) ;
F_83 ( V_4 ) ;
F_47 ( & V_46 ) ;
}
static T_1 F_90 ( struct V_65 * V_26 , char * V_64 )
{
struct V_25 * V_28 = F_66 ( V_26 ) ;
return sprintf ( V_64 , L_5 , V_28 -> V_33 ? V_28 -> V_33 : L_13 ) ;
}
static int F_91 ( struct V_61 * V_27 )
{
struct V_4 * V_4 = F_60 ( V_27 ) ;
struct V_25 * V_26 = F_66 ( V_27 -> V_28 ) ;
V_26 -> V_29 ( V_4 , V_26 ) ;
return V_4 -> V_26 ? 0 : - V_30 ;
}
static int F_92 ( struct V_61 * V_27 )
{
struct V_4 * V_4 = F_60 ( V_27 ) ;
struct V_25 * V_26 = F_66 ( V_27 -> V_28 ) ;
V_26 -> V_34 ( V_4 ) ;
return 0 ;
}
static void F_46 ( struct V_25 * V_26 )
{
int error ;
error = F_93 ( & V_26 -> V_28 ) ;
if ( error )
F_51 ( L_14 ,
V_26 -> V_28 . V_32 , error ) ;
}
int F_94 ( struct V_25 * V_26 , struct V_49 * V_40 ,
const char * V_80 )
{
int error ;
V_26 -> V_28 . V_71 = & V_66 ;
V_26 -> V_28 . V_40 = V_40 ;
V_26 -> V_28 . V_80 = V_80 ;
V_26 -> V_81 = true ;
error = F_95 ( & V_26 -> V_28 ) ;
if ( error ) {
F_51 ( L_15 ,
V_26 -> V_28 . V_32 , error ) ;
return error ;
}
V_26 -> V_81 = false ;
error = F_48 ( V_26 , NULL , V_48 ) ;
if ( error ) {
F_96 ( & V_26 -> V_28 ) ;
return error ;
}
return 0 ;
}
void F_97 ( struct V_25 * V_26 )
{
struct V_4 * V_4 ;
F_44 ( & V_46 ) ;
V_26 -> V_81 = true ;
F_56 ( V_26 ) ;
V_82:
F_58 (gameport, &gameport_list, node) {
if ( V_4 -> V_26 == V_26 ) {
F_63 ( V_4 ) ;
F_30 ( V_4 ) ;
goto V_82;
}
}
F_96 ( & V_26 -> V_28 ) ;
F_47 ( & V_46 ) ;
}
static int F_98 ( struct V_61 * V_27 , struct V_65 * V_26 )
{
struct V_25 * V_83 = F_66 ( V_26 ) ;
return ! V_83 -> V_81 ;
}
static void F_99 ( struct V_4 * V_4 , struct V_25 * V_26 )
{
F_44 ( & V_4 -> V_70 ) ;
V_4 -> V_26 = V_26 ;
F_47 ( & V_4 -> V_70 ) ;
}
int F_8 ( struct V_4 * V_4 , struct V_25 * V_26 , int V_84 )
{
if ( V_4 -> V_85 ) {
if ( V_4 -> V_85 ( V_4 , V_84 ) ) {
return - 1 ;
}
} else {
if ( V_84 != V_12 )
return - 1 ;
}
F_99 ( V_4 , V_26 ) ;
return 0 ;
}
void F_15 ( struct V_4 * V_4 )
{
F_100 ( & V_4 -> V_23 ) ;
V_4 -> V_21 = NULL ;
V_4 -> V_22 = 0 ;
F_99 ( V_4 , NULL ) ;
if ( V_4 -> V_86 )
V_4 -> V_86 ( V_4 ) ;
}
static int T_5 F_101 ( void )
{
int error ;
error = F_102 ( & V_66 ) ;
if ( error ) {
F_51 ( L_16 , error ) ;
return error ;
}
return 0 ;
}
static void T_6 F_103 ( void )
{
F_104 ( & V_66 ) ;
F_105 ( & V_58 ) ;
}

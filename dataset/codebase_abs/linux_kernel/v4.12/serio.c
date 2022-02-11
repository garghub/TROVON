static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
int V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = V_3 -> V_6 ( V_1 , V_3 ) ;
F_3 ( & V_1 -> V_5 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_1 )
{
int V_4 = - 1 ;
F_2 ( & V_1 -> V_5 ) ;
if ( V_1 -> V_3 && V_1 -> V_3 -> V_7 )
V_4 = V_1 -> V_3 -> V_7 ( V_1 ) ;
F_3 ( & V_1 -> V_5 ) ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_5 ) ;
if ( V_1 -> V_3 )
V_1 -> V_3 -> V_8 ( V_1 ) ;
F_3 ( & V_1 -> V_5 ) ;
}
static int F_6 ( const struct V_9 * V_10 , struct V_1 * V_1 )
{
while ( V_10 -> type || V_10 -> V_11 ) {
if ( ( V_10 -> type == V_12 || V_10 -> type == V_1 -> V_13 . type ) &&
( V_10 -> V_11 == V_12 || V_10 -> V_11 == V_1 -> V_13 . V_11 ) &&
( V_10 -> V_14 == V_12 || V_10 -> V_14 == V_1 -> V_13 . V_14 ) &&
( V_10 -> V_13 == V_12 || V_10 -> V_13 == V_1 -> V_13 . V_13 ) )
return 1 ;
V_10 ++ ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
int error ;
if ( F_6 ( V_3 -> V_15 , V_1 ) ) {
V_1 -> V_16 . V_17 = & V_3 -> V_17 ;
if ( F_1 ( V_1 , V_3 ) ) {
V_1 -> V_16 . V_17 = NULL ;
return - V_18 ;
}
error = F_8 ( & V_1 -> V_16 ) ;
if ( error ) {
F_9 ( & V_1 -> V_16 ,
L_1 ,
V_1 -> V_19 , V_1 -> V_20 ,
V_3 -> V_21 , error ) ;
F_5 ( V_1 ) ;
V_1 -> V_16 . V_17 = NULL ;
return error ;
}
}
return 0 ;
}
static void F_10 ( struct V_1 * V_1 )
{
int error ;
error = F_11 ( & V_1 -> V_16 ) ;
if ( error < 0 && error != - V_22 )
F_9 ( & V_1 -> V_16 ,
L_2 ,
V_1 -> V_19 , V_1 -> V_20 , error ) ;
}
static struct V_23 * F_12 ( void )
{
struct V_23 * V_24 = NULL ;
unsigned long V_25 ;
F_13 ( & V_26 , V_25 ) ;
if ( ! F_14 ( & V_27 ) ) {
V_24 = F_15 ( & V_27 ,
struct V_23 , V_28 ) ;
F_16 ( & V_24 -> V_28 ) ;
}
F_17 ( & V_26 , V_25 ) ;
return V_24 ;
}
static void F_18 ( struct V_23 * V_24 )
{
F_19 ( V_24 -> V_29 ) ;
F_20 ( V_24 ) ;
}
static void F_21 ( void * V_30 ,
enum V_31 type )
{
struct V_23 * V_32 , * V_33 ;
unsigned long V_25 ;
F_13 ( & V_26 , V_25 ) ;
F_22 (e, next, &serio_event_list, node) {
if ( V_30 == V_32 -> V_30 ) {
if ( type != V_32 -> type )
break;
F_16 ( & V_32 -> V_28 ) ;
F_18 ( V_32 ) ;
}
}
F_17 ( & V_26 , V_25 ) ;
}
static void F_23 ( struct V_34 * V_35 )
{
struct V_23 * V_24 ;
F_2 ( & V_36 ) ;
while ( ( V_24 = F_12 () ) ) {
switch ( V_24 -> type ) {
case V_37 :
F_24 ( V_24 -> V_30 ) ;
break;
case V_38 :
F_25 ( V_24 -> V_30 ) ;
break;
case V_39 :
F_26 ( V_24 -> V_30 ) ;
F_10 ( V_24 -> V_30 ) ;
break;
case V_40 :
F_27 ( V_24 -> V_30 ) ;
break;
case V_41 :
F_28 ( V_24 -> V_30 ) ;
break;
}
F_21 ( V_24 -> V_30 , V_24 -> type ) ;
F_18 ( V_24 ) ;
}
F_3 ( & V_36 ) ;
}
static int F_29 ( void * V_30 , struct V_42 * V_29 ,
enum V_31 V_43 )
{
unsigned long V_25 ;
struct V_23 * V_24 ;
int V_4 = 0 ;
F_13 ( & V_26 , V_25 ) ;
F_30 (event, &serio_event_list, node) {
if ( V_24 -> V_30 == V_30 ) {
if ( V_24 -> type == V_43 )
goto V_44;
break;
}
}
V_24 = F_31 ( sizeof( struct V_23 ) , V_45 ) ;
if ( ! V_24 ) {
F_32 ( L_3 , V_43 ) ;
V_4 = - V_46 ;
goto V_44;
}
if ( ! F_33 ( V_29 ) ) {
F_34 ( L_4 ,
V_43 ) ;
F_20 ( V_24 ) ;
V_4 = - V_47 ;
goto V_44;
}
V_24 -> type = V_43 ;
V_24 -> V_30 = V_30 ;
V_24 -> V_29 = V_29 ;
F_35 ( & V_24 -> V_28 , & V_27 ) ;
F_36 ( V_48 , & V_49 ) ;
V_44:
F_17 ( & V_26 , V_25 ) ;
return V_4 ;
}
static void F_37 ( void * V_30 )
{
struct V_23 * V_24 , * V_33 ;
unsigned long V_25 ;
F_13 ( & V_26 , V_25 ) ;
F_22 (event, next, &serio_event_list, node) {
if ( V_24 -> V_30 == V_30 ) {
F_16 ( & V_24 -> V_28 ) ;
F_18 ( V_24 ) ;
}
}
F_17 ( & V_26 , V_25 ) ;
}
static struct V_1 * F_38 ( struct V_1 * V_50 )
{
struct V_23 * V_24 ;
struct V_1 * V_1 , * V_51 = NULL ;
unsigned long V_25 ;
F_13 ( & V_26 , V_25 ) ;
F_39 (event, &serio_event_list, node) {
if ( V_24 -> type == V_37 ) {
V_1 = V_24 -> V_30 ;
if ( V_1 -> V_50 == V_50 ) {
V_51 = V_1 ;
break;
}
}
}
F_17 ( & V_26 , V_25 ) ;
return V_51 ;
}
static T_1 F_40 ( struct V_52 * V_16 , struct V_53 * V_54 , char * V_55 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
return sprintf ( V_55 , L_5 , V_1 -> V_20 ) ;
}
static T_1 F_42 ( struct V_52 * V_16 , struct V_53 * V_54 , char * V_55 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
return sprintf ( V_55 , L_6 ,
V_1 -> V_13 . type , V_1 -> V_13 . V_11 , V_1 -> V_13 . V_13 , V_1 -> V_13 . V_14 ) ;
}
static T_1 F_43 ( struct V_52 * V_16 , struct V_53 * V_54 , char * V_55 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
return sprintf ( V_55 , L_7 , V_1 -> V_13 . type ) ;
}
static T_1 F_44 ( struct V_52 * V_16 , struct V_53 * V_54 , char * V_55 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
return sprintf ( V_55 , L_7 , V_1 -> V_13 . V_11 ) ;
}
static T_1 F_45 ( struct V_52 * V_16 , struct V_53 * V_54 , char * V_55 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
return sprintf ( V_55 , L_7 , V_1 -> V_13 . V_13 ) ;
}
static T_1 F_46 ( struct V_52 * V_16 , struct V_53 * V_54 , char * V_55 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
return sprintf ( V_55 , L_7 , V_1 -> V_13 . V_14 ) ;
}
static T_1 F_47 ( struct V_52 * V_16 , struct V_53 * V_54 , const char * V_55 , T_2 V_56 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
struct V_57 * V_3 ;
int error ;
error = F_48 ( & V_36 ) ;
if ( error )
return error ;
if ( ! strncmp ( V_55 , L_8 , V_56 ) ) {
F_26 ( V_1 ) ;
} else if ( ! strncmp ( V_55 , L_9 , V_56 ) ) {
F_27 ( V_1 ) ;
} else if ( ! strncmp ( V_55 , L_10 , V_56 ) ) {
F_26 ( V_1 ) ;
F_10 ( V_1 ) ;
F_21 ( V_1 , V_39 ) ;
} else if ( ( V_3 = F_49 ( V_55 , & V_58 ) ) != NULL ) {
F_26 ( V_1 ) ;
error = F_7 ( V_1 , F_50 ( V_3 ) ) ;
F_21 ( V_1 , V_39 ) ;
} else {
error = - V_47 ;
}
F_3 ( & V_36 ) ;
return error ? error : V_56 ;
}
static T_1 F_51 ( struct V_52 * V_16 , struct V_53 * V_54 , char * V_55 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
return sprintf ( V_55 , L_5 , V_1 -> V_59 ? L_11 : L_12 ) ;
}
static T_1 F_52 ( struct V_52 * V_16 , struct V_53 * V_54 , const char * V_55 , T_2 V_56 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
int V_4 ;
V_4 = V_56 ;
if ( ! strncmp ( V_55 , L_11 , V_56 ) ) {
V_1 -> V_59 = true ;
} else if ( ! strncmp ( V_55 , L_12 , V_56 ) ) {
V_1 -> V_59 = false ;
} else {
V_4 = - V_47 ;
}
return V_4 ;
}
static T_1 F_53 ( struct V_52 * V_16 , struct V_53 * V_54 , char * V_55 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
return sprintf ( V_55 , L_5 , V_1 -> V_60 ) ;
}
static void F_54 ( struct V_52 * V_16 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
F_20 ( V_1 ) ;
F_19 ( V_61 ) ;
}
static void F_55 ( struct V_1 * V_1 )
{
static T_3 V_62 = F_56 ( - 1 ) ;
F_57 ( V_61 ) ;
F_58 ( & V_1 -> V_28 ) ;
F_58 ( & V_1 -> V_63 ) ;
F_58 ( & V_1 -> V_64 ) ;
F_59 ( & V_1 -> V_65 ) ;
F_60 ( & V_1 -> V_5 ) ;
F_61 ( & V_1 -> V_16 ) ;
F_62 ( & V_1 -> V_16 , L_13 ,
( unsigned long ) F_63 ( & V_62 ) ) ;
V_1 -> V_16 . V_66 = & V_58 ;
V_1 -> V_16 . V_67 = F_54 ;
V_1 -> V_16 . V_68 = V_69 ;
if ( V_1 -> V_50 ) {
V_1 -> V_16 . V_50 = & V_1 -> V_50 -> V_16 ;
V_1 -> V_70 = V_1 -> V_50 -> V_70 + 1 ;
} else
V_1 -> V_70 = 0 ;
F_64 ( & V_1 -> V_65 , V_1 -> V_70 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_1 * V_50 = V_1 -> V_50 ;
int error ;
if ( V_50 ) {
F_65 ( V_50 ) ;
F_35 ( & V_1 -> V_63 , & V_50 -> V_64 ) ;
F_66 ( V_50 ) ;
}
F_35 ( & V_1 -> V_28 , & V_71 ) ;
if ( V_1 -> V_72 )
V_1 -> V_72 ( V_1 ) ;
error = F_67 ( & V_1 -> V_16 ) ;
if ( error )
F_68 ( & V_1 -> V_16 ,
L_14 ,
V_1 -> V_19 , V_1 -> V_20 , error ) ;
}
static void F_69 ( struct V_1 * V_1 )
{
struct V_1 * V_51 ;
while ( ( V_51 = F_38 ( V_1 ) ) != NULL ) {
F_37 ( V_51 ) ;
F_70 ( & V_51 -> V_16 ) ;
}
if ( V_1 -> V_73 )
V_1 -> V_73 ( V_1 ) ;
if ( V_1 -> V_50 ) {
F_65 ( V_1 -> V_50 ) ;
F_16 ( & V_1 -> V_63 ) ;
F_66 ( V_1 -> V_50 ) ;
V_1 -> V_50 = NULL ;
}
if ( F_71 ( & V_1 -> V_16 ) )
F_72 ( & V_1 -> V_16 ) ;
F_16 ( & V_1 -> V_28 ) ;
F_37 ( V_1 ) ;
F_70 ( & V_1 -> V_16 ) ;
}
static int F_25 ( struct V_1 * V_1 )
{
int error = F_4 ( V_1 ) ;
if ( error ) {
F_26 ( V_1 ) ;
F_10 ( V_1 ) ;
}
return error ;
}
static void F_27 ( struct V_1 * V_74 )
{
struct V_1 * V_75 = V_74 ;
int error ;
do {
error = F_25 ( V_75 ) ;
if ( ! error ) {
if ( ! F_14 ( & V_75 -> V_64 ) ) {
V_75 = F_15 ( & V_75 -> V_64 ,
struct V_1 , V_63 ) ;
continue;
}
}
while ( V_75 != V_74 ) {
struct V_1 * V_50 = V_75 -> V_50 ;
if ( ! F_73 ( & V_75 -> V_63 , & V_50 -> V_64 ) ) {
V_75 = F_74 ( V_75 -> V_63 . V_33 ,
struct V_1 , V_63 ) ;
break;
}
V_75 = V_50 ;
}
} while ( V_75 != V_74 );
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_1 * V_75 = V_1 ;
while ( ! F_14 ( & V_1 -> V_64 ) ) {
while ( ! F_14 ( & V_75 -> V_64 ) )
V_75 = F_15 ( & V_75 -> V_64 ,
struct V_1 , V_63 ) ;
if ( V_75 != V_1 ) {
struct V_1 * V_50 = V_75 -> V_50 ;
F_75 ( & V_75 -> V_16 ) ;
F_69 ( V_75 ) ;
V_75 = V_50 ;
}
}
F_75 ( & V_1 -> V_16 ) ;
}
void F_76 ( struct V_1 * V_1 )
{
F_29 ( V_1 , NULL , V_39 ) ;
}
void F_77 ( struct V_1 * V_1 )
{
F_29 ( V_1 , NULL , V_40 ) ;
}
void F_78 ( struct V_1 * V_1 , struct V_42 * V_29 )
{
F_55 ( V_1 ) ;
F_29 ( V_1 , V_29 , V_37 ) ;
}
void F_79 ( struct V_1 * V_1 )
{
F_2 ( & V_36 ) ;
F_26 ( V_1 ) ;
F_69 ( V_1 ) ;
F_3 ( & V_36 ) ;
}
void F_80 ( struct V_1 * V_1 )
{
struct V_1 * V_75 , * V_33 ;
F_2 ( & V_36 ) ;
F_22 (s, next, &serio->children, child_node) {
F_26 ( V_75 ) ;
F_69 ( V_75 ) ;
}
F_3 ( & V_36 ) ;
}
static T_1 F_81 ( struct V_57 * V_3 , char * V_55 )
{
struct V_2 * V_17 = F_50 ( V_3 ) ;
return sprintf ( V_55 , L_5 , V_17 -> V_21 ? V_17 -> V_21 : L_15 ) ;
}
static T_1 F_82 ( struct V_57 * V_3 , char * V_55 )
{
struct V_2 * V_76 = F_50 ( V_3 ) ;
return sprintf ( V_55 , L_5 , V_76 -> V_59 ? L_11 : L_12 ) ;
}
static T_1 F_83 ( struct V_57 * V_3 , const char * V_55 , T_2 V_56 )
{
struct V_2 * V_76 = F_50 ( V_3 ) ;
int V_4 ;
V_4 = V_56 ;
if ( ! strncmp ( V_55 , L_11 , V_56 ) ) {
V_76 -> V_59 = true ;
} else if ( ! strncmp ( V_55 , L_12 , V_56 ) ) {
V_76 -> V_59 = false ;
} else {
V_4 = - V_47 ;
}
return V_4 ;
}
static int F_84 ( struct V_52 * V_16 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
struct V_2 * V_3 = F_50 ( V_16 -> V_17 ) ;
return F_1 ( V_1 , V_3 ) ;
}
static int F_85 ( struct V_52 * V_16 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
F_5 ( V_1 ) ;
return 0 ;
}
static void F_86 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_5 ) ;
if ( V_1 -> V_3 && V_1 -> V_3 -> V_77 )
V_1 -> V_3 -> V_77 ( V_1 ) ;
F_3 ( & V_1 -> V_5 ) ;
}
static void F_87 ( struct V_52 * V_16 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
F_86 ( V_1 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
int error ;
error = F_88 ( & V_3 -> V_17 ) ;
if ( error )
F_34 ( L_16 ,
V_3 -> V_17 . V_20 , error ) ;
}
int F_89 ( struct V_2 * V_3 , struct V_42 * V_29 , const char * V_78 )
{
bool V_59 = V_3 -> V_59 ;
int error ;
V_3 -> V_17 . V_66 = & V_58 ;
V_3 -> V_17 . V_29 = V_29 ;
V_3 -> V_17 . V_78 = V_78 ;
V_3 -> V_59 = true ;
error = F_90 ( & V_3 -> V_17 ) ;
if ( error ) {
F_32 ( L_17 ,
V_3 -> V_17 . V_20 , error ) ;
return error ;
}
if ( ! V_59 ) {
V_3 -> V_59 = false ;
error = F_29 ( V_3 , NULL , V_41 ) ;
if ( error ) {
F_91 ( & V_3 -> V_17 ) ;
return error ;
}
}
return 0 ;
}
void F_92 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
F_2 ( & V_36 ) ;
V_3 -> V_59 = true ;
F_37 ( V_3 ) ;
V_79:
F_39 (serio, &serio_list, node) {
if ( V_1 -> V_3 == V_3 ) {
F_26 ( V_1 ) ;
F_10 ( V_1 ) ;
goto V_79;
}
}
F_91 ( & V_3 -> V_17 ) ;
F_3 ( & V_36 ) ;
}
static void F_93 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_65 ( V_1 ) ;
V_1 -> V_3 = V_3 ;
F_66 ( V_1 ) ;
}
static int F_94 ( struct V_52 * V_16 , struct V_57 * V_3 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
struct V_2 * V_76 = F_50 ( V_3 ) ;
if ( V_1 -> V_59 || V_76 -> V_59 )
return 0 ;
return F_6 ( V_76 -> V_15 , V_1 ) ;
}
static int F_95 ( struct V_52 * V_16 , struct V_80 * V_81 )
{
struct V_1 * V_1 ;
if ( ! V_16 )
return - V_18 ;
V_1 = F_41 ( V_16 ) ;
F_96 ( L_18 , V_1 -> V_13 . type ) ;
F_96 ( L_19 , V_1 -> V_13 . V_11 ) ;
F_96 ( L_20 , V_1 -> V_13 . V_13 ) ;
F_96 ( L_21 , V_1 -> V_13 . V_14 ) ;
F_96 ( L_22 ,
V_1 -> V_13 . type , V_1 -> V_13 . V_11 , V_1 -> V_13 . V_13 , V_1 -> V_13 . V_14 ) ;
if ( V_1 -> V_60 [ 0 ] )
F_96 ( L_23 ,
V_1 -> V_60 ) ;
return 0 ;
}
static int F_97 ( struct V_52 * V_16 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
F_86 ( V_1 ) ;
return 0 ;
}
static int F_98 ( struct V_52 * V_16 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
int error = - V_82 ;
F_2 ( & V_1 -> V_5 ) ;
if ( V_1 -> V_3 && V_1 -> V_3 -> V_83 ) {
error = V_1 -> V_3 -> V_83 ( V_1 ) ;
if ( error && error != - V_82 )
F_9 ( V_16 , L_24 ,
error ) ;
}
F_3 ( & V_1 -> V_5 ) ;
if ( error ) {
F_29 ( V_1 , NULL , V_38 ) ;
}
return 0 ;
}
int F_99 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_93 ( V_1 , V_3 ) ;
if ( V_1 -> V_84 && V_1 -> V_84 ( V_1 ) ) {
F_93 ( V_1 , NULL ) ;
return - 1 ;
}
return 0 ;
}
void F_100 ( struct V_1 * V_1 )
{
if ( V_1 -> V_85 )
V_1 -> V_85 ( V_1 ) ;
F_93 ( V_1 , NULL ) ;
}
T_4 F_101 ( struct V_1 * V_1 ,
unsigned char V_86 , unsigned int V_87 )
{
unsigned long V_25 ;
T_4 V_88 = V_89 ;
F_13 ( & V_1 -> V_65 , V_25 ) ;
if ( F_102 ( V_1 -> V_3 ) ) {
V_88 = V_1 -> V_3 -> V_90 ( V_1 , V_86 , V_87 ) ;
} else if ( ! V_87 && F_71 ( & V_1 -> V_16 ) ) {
F_76 ( V_1 ) ;
V_88 = V_91 ;
}
F_17 ( & V_1 -> V_65 , V_25 ) ;
return V_88 ;
}
static int T_5 F_103 ( void )
{
int error ;
error = F_104 ( & V_58 ) ;
if ( error ) {
F_32 ( L_25 , error ) ;
return error ;
}
return 0 ;
}
static void T_6 F_105 ( void )
{
F_106 ( & V_58 ) ;
F_107 ( & V_49 ) ;
}

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
if ( error < 0 )
F_9 ( & V_1 -> V_16 ,
L_2 ,
V_1 -> V_19 , V_1 -> V_20 , error ) ;
}
static struct V_22 * F_12 ( void )
{
struct V_22 * V_23 = NULL ;
unsigned long V_24 ;
F_13 ( & V_25 , V_24 ) ;
if ( ! F_14 ( & V_26 ) ) {
V_23 = F_15 ( & V_26 ,
struct V_22 , V_27 ) ;
F_16 ( & V_23 -> V_27 ) ;
}
F_17 ( & V_25 , V_24 ) ;
return V_23 ;
}
static void F_18 ( struct V_22 * V_23 )
{
F_19 ( V_23 -> V_28 ) ;
F_20 ( V_23 ) ;
}
static void F_21 ( void * V_29 ,
enum V_30 type )
{
struct V_22 * V_31 , * V_32 ;
unsigned long V_24 ;
F_13 ( & V_25 , V_24 ) ;
F_22 (e, next, &serio_event_list, node) {
if ( V_29 == V_31 -> V_29 ) {
if ( type != V_31 -> type )
break;
F_16 ( & V_31 -> V_27 ) ;
F_18 ( V_31 ) ;
}
}
F_17 ( & V_25 , V_24 ) ;
}
static void F_23 ( struct V_33 * V_34 )
{
struct V_22 * V_23 ;
F_2 ( & V_35 ) ;
while ( ( V_23 = F_12 () ) ) {
switch ( V_23 -> type ) {
case V_36 :
F_24 ( V_23 -> V_29 ) ;
break;
case V_37 :
F_25 ( V_23 -> V_29 ) ;
break;
case V_38 :
F_26 ( V_23 -> V_29 ) ;
F_10 ( V_23 -> V_29 ) ;
break;
case V_39 :
F_27 ( V_23 -> V_29 ) ;
break;
case V_40 :
F_28 ( V_23 -> V_29 ) ;
break;
}
F_21 ( V_23 -> V_29 , V_23 -> type ) ;
F_18 ( V_23 ) ;
}
F_3 ( & V_35 ) ;
}
static int F_29 ( void * V_29 , struct V_41 * V_28 ,
enum V_30 V_42 )
{
unsigned long V_24 ;
struct V_22 * V_23 ;
int V_4 = 0 ;
F_13 ( & V_25 , V_24 ) ;
F_30 (event, &serio_event_list, node) {
if ( V_23 -> V_29 == V_29 ) {
if ( V_23 -> type == V_42 )
goto V_43;
break;
}
}
V_23 = F_31 ( sizeof( struct V_22 ) , V_44 ) ;
if ( ! V_23 ) {
F_32 ( L_3 , V_42 ) ;
V_4 = - V_45 ;
goto V_43;
}
if ( ! F_33 ( V_28 ) ) {
F_34 ( L_4 ,
V_42 ) ;
F_20 ( V_23 ) ;
V_4 = - V_46 ;
goto V_43;
}
V_23 -> type = V_42 ;
V_23 -> V_29 = V_29 ;
V_23 -> V_28 = V_28 ;
F_35 ( & V_23 -> V_27 , & V_26 ) ;
F_36 ( V_47 , & V_48 ) ;
V_43:
F_17 ( & V_25 , V_24 ) ;
return V_4 ;
}
static void F_37 ( void * V_29 )
{
struct V_22 * V_23 , * V_32 ;
unsigned long V_24 ;
F_13 ( & V_25 , V_24 ) ;
F_22 (event, next, &serio_event_list, node) {
if ( V_23 -> V_29 == V_29 ) {
F_16 ( & V_23 -> V_27 ) ;
F_18 ( V_23 ) ;
}
}
F_17 ( & V_25 , V_24 ) ;
}
static struct V_1 * F_38 ( struct V_1 * V_49 )
{
struct V_22 * V_23 ;
struct V_1 * V_1 , * V_50 = NULL ;
unsigned long V_24 ;
F_13 ( & V_25 , V_24 ) ;
F_39 (event, &serio_event_list, node) {
if ( V_23 -> type == V_36 ) {
V_1 = V_23 -> V_29 ;
if ( V_1 -> V_49 == V_49 ) {
V_50 = V_1 ;
break;
}
}
}
F_17 ( & V_25 , V_24 ) ;
return V_50 ;
}
static T_1 F_40 ( struct V_51 * V_16 , struct V_52 * V_53 , char * V_54 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
return sprintf ( V_54 , L_5 , V_1 -> V_20 ) ;
}
static T_1 F_42 ( struct V_51 * V_16 , struct V_52 * V_53 , char * V_54 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
return sprintf ( V_54 , L_6 ,
V_1 -> V_13 . type , V_1 -> V_13 . V_11 , V_1 -> V_13 . V_13 , V_1 -> V_13 . V_14 ) ;
}
static T_1 F_43 ( struct V_51 * V_16 , struct V_52 * V_53 , char * V_54 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
return sprintf ( V_54 , L_7 , V_1 -> V_13 . type ) ;
}
static T_1 F_44 ( struct V_51 * V_16 , struct V_52 * V_53 , char * V_54 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
return sprintf ( V_54 , L_7 , V_1 -> V_13 . V_11 ) ;
}
static T_1 F_45 ( struct V_51 * V_16 , struct V_52 * V_53 , char * V_54 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
return sprintf ( V_54 , L_7 , V_1 -> V_13 . V_13 ) ;
}
static T_1 F_46 ( struct V_51 * V_16 , struct V_52 * V_53 , char * V_54 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
return sprintf ( V_54 , L_7 , V_1 -> V_13 . V_14 ) ;
}
static T_1 F_47 ( struct V_51 * V_16 , struct V_52 * V_53 , const char * V_54 , T_2 V_55 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
struct V_56 * V_3 ;
int error ;
error = F_48 ( & V_35 ) ;
if ( error )
return error ;
if ( ! strncmp ( V_54 , L_8 , V_55 ) ) {
F_26 ( V_1 ) ;
} else if ( ! strncmp ( V_54 , L_9 , V_55 ) ) {
F_27 ( V_1 ) ;
} else if ( ! strncmp ( V_54 , L_10 , V_55 ) ) {
F_26 ( V_1 ) ;
F_10 ( V_1 ) ;
F_21 ( V_1 , V_38 ) ;
} else if ( ( V_3 = F_49 ( V_54 , & V_57 ) ) != NULL ) {
F_26 ( V_1 ) ;
error = F_7 ( V_1 , F_50 ( V_3 ) ) ;
F_21 ( V_1 , V_38 ) ;
} else {
error = - V_46 ;
}
F_3 ( & V_35 ) ;
return error ? error : V_55 ;
}
static T_1 F_51 ( struct V_51 * V_16 , struct V_52 * V_53 , char * V_54 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
return sprintf ( V_54 , L_5 , V_1 -> V_58 ? L_11 : L_12 ) ;
}
static T_1 F_52 ( struct V_51 * V_16 , struct V_52 * V_53 , const char * V_54 , T_2 V_55 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
int V_4 ;
V_4 = V_55 ;
if ( ! strncmp ( V_54 , L_11 , V_55 ) ) {
V_1 -> V_58 = true ;
} else if ( ! strncmp ( V_54 , L_12 , V_55 ) ) {
V_1 -> V_58 = false ;
} else {
V_4 = - V_46 ;
}
return V_4 ;
}
static void F_53 ( struct V_51 * V_16 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
F_20 ( V_1 ) ;
F_19 ( V_59 ) ;
}
static void F_54 ( struct V_1 * V_1 )
{
static T_3 V_60 = F_55 ( 0 ) ;
F_56 ( V_59 ) ;
F_57 ( & V_1 -> V_27 ) ;
F_57 ( & V_1 -> V_61 ) ;
F_57 ( & V_1 -> V_62 ) ;
F_58 ( & V_1 -> V_63 ) ;
F_59 ( & V_1 -> V_5 ) ;
F_60 ( & V_1 -> V_16 ) ;
F_61 ( & V_1 -> V_16 , L_13 ,
( long ) F_62 ( & V_60 ) - 1 ) ;
V_1 -> V_16 . V_64 = & V_57 ;
V_1 -> V_16 . V_65 = F_53 ;
V_1 -> V_16 . V_66 = V_67 ;
if ( V_1 -> V_49 ) {
V_1 -> V_16 . V_49 = & V_1 -> V_49 -> V_16 ;
V_1 -> V_68 = V_1 -> V_49 -> V_68 + 1 ;
} else
V_1 -> V_68 = 0 ;
F_63 ( & V_1 -> V_63 , V_1 -> V_68 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_1 * V_49 = V_1 -> V_49 ;
int error ;
if ( V_49 ) {
F_64 ( V_49 ) ;
F_35 ( & V_1 -> V_61 , & V_49 -> V_62 ) ;
F_65 ( V_49 ) ;
}
F_35 ( & V_1 -> V_27 , & V_69 ) ;
if ( V_1 -> V_70 )
V_1 -> V_70 ( V_1 ) ;
error = F_66 ( & V_1 -> V_16 ) ;
if ( error )
F_67 ( & V_1 -> V_16 ,
L_14 ,
V_1 -> V_19 , V_1 -> V_20 , error ) ;
}
static void F_68 ( struct V_1 * V_1 )
{
struct V_1 * V_50 ;
while ( ( V_50 = F_38 ( V_1 ) ) != NULL ) {
F_37 ( V_50 ) ;
F_69 ( & V_50 -> V_16 ) ;
}
if ( V_1 -> V_71 )
V_1 -> V_71 ( V_1 ) ;
if ( V_1 -> V_49 ) {
F_64 ( V_1 -> V_49 ) ;
F_16 ( & V_1 -> V_61 ) ;
F_65 ( V_1 -> V_49 ) ;
V_1 -> V_49 = NULL ;
}
if ( F_70 ( & V_1 -> V_16 ) )
F_71 ( & V_1 -> V_16 ) ;
F_16 ( & V_1 -> V_27 ) ;
F_37 ( V_1 ) ;
F_69 ( & V_1 -> V_16 ) ;
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
static void F_27 ( struct V_1 * V_72 )
{
struct V_1 * V_73 = V_72 ;
int error ;
do {
error = F_25 ( V_73 ) ;
if ( ! error ) {
if ( ! F_14 ( & V_73 -> V_62 ) ) {
V_73 = F_15 ( & V_73 -> V_62 ,
struct V_1 , V_61 ) ;
continue;
}
}
while ( V_73 != V_72 ) {
struct V_1 * V_49 = V_73 -> V_49 ;
if ( ! F_72 ( & V_73 -> V_61 , & V_49 -> V_62 ) ) {
V_73 = F_73 ( V_73 -> V_61 . V_32 ,
struct V_1 , V_61 ) ;
break;
}
V_73 = V_49 ;
}
} while ( V_73 != V_72 );
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_1 * V_73 = V_1 ;
while ( ! F_14 ( & V_1 -> V_62 ) ) {
while ( ! F_14 ( & V_73 -> V_62 ) )
V_73 = F_15 ( & V_73 -> V_62 ,
struct V_1 , V_61 ) ;
if ( V_73 != V_1 ) {
struct V_1 * V_49 = V_73 -> V_49 ;
F_74 ( & V_73 -> V_16 ) ;
F_68 ( V_73 ) ;
V_73 = V_49 ;
}
}
F_74 ( & V_1 -> V_16 ) ;
}
void F_75 ( struct V_1 * V_1 )
{
F_29 ( V_1 , NULL , V_38 ) ;
}
void F_76 ( struct V_1 * V_1 )
{
F_29 ( V_1 , NULL , V_39 ) ;
}
void F_77 ( struct V_1 * V_1 , struct V_41 * V_28 )
{
F_54 ( V_1 ) ;
F_29 ( V_1 , V_28 , V_36 ) ;
}
void F_78 ( struct V_1 * V_1 )
{
F_2 ( & V_35 ) ;
F_26 ( V_1 ) ;
F_68 ( V_1 ) ;
F_3 ( & V_35 ) ;
}
void F_79 ( struct V_1 * V_1 )
{
struct V_1 * V_73 , * V_32 ;
F_2 ( & V_35 ) ;
F_22 (s, next, &serio->children, child_node) {
F_26 ( V_73 ) ;
F_68 ( V_73 ) ;
}
F_3 ( & V_35 ) ;
}
static T_1 F_80 ( struct V_56 * V_3 , char * V_54 )
{
struct V_2 * V_17 = F_50 ( V_3 ) ;
return sprintf ( V_54 , L_5 , V_17 -> V_21 ? V_17 -> V_21 : L_15 ) ;
}
static T_1 F_81 ( struct V_56 * V_3 , char * V_54 )
{
struct V_2 * V_74 = F_50 ( V_3 ) ;
return sprintf ( V_54 , L_5 , V_74 -> V_58 ? L_11 : L_12 ) ;
}
static T_1 F_82 ( struct V_56 * V_3 , const char * V_54 , T_2 V_55 )
{
struct V_2 * V_74 = F_50 ( V_3 ) ;
int V_4 ;
V_4 = V_55 ;
if ( ! strncmp ( V_54 , L_11 , V_55 ) ) {
V_74 -> V_58 = true ;
} else if ( ! strncmp ( V_54 , L_12 , V_55 ) ) {
V_74 -> V_58 = false ;
} else {
V_4 = - V_46 ;
}
return V_4 ;
}
static int F_83 ( struct V_51 * V_16 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
struct V_2 * V_3 = F_50 ( V_16 -> V_17 ) ;
return F_1 ( V_1 , V_3 ) ;
}
static int F_84 ( struct V_51 * V_16 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
F_5 ( V_1 ) ;
return 0 ;
}
static void F_85 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_5 ) ;
if ( V_1 -> V_3 && V_1 -> V_3 -> V_75 )
V_1 -> V_3 -> V_75 ( V_1 ) ;
F_3 ( & V_1 -> V_5 ) ;
}
static void F_86 ( struct V_51 * V_16 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
F_85 ( V_1 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
int error ;
error = F_87 ( & V_3 -> V_17 ) ;
if ( error )
F_34 ( L_16 ,
V_3 -> V_17 . V_20 , error ) ;
}
int F_88 ( struct V_2 * V_3 , struct V_41 * V_28 , const char * V_76 )
{
bool V_58 = V_3 -> V_58 ;
int error ;
V_3 -> V_17 . V_64 = & V_57 ;
V_3 -> V_17 . V_28 = V_28 ;
V_3 -> V_17 . V_76 = V_76 ;
V_3 -> V_58 = true ;
error = F_89 ( & V_3 -> V_17 ) ;
if ( error ) {
F_32 ( L_17 ,
V_3 -> V_17 . V_20 , error ) ;
return error ;
}
if ( ! V_58 ) {
V_3 -> V_58 = false ;
error = F_29 ( V_3 , NULL , V_40 ) ;
if ( error ) {
F_90 ( & V_3 -> V_17 ) ;
return error ;
}
}
return 0 ;
}
void F_91 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
F_2 ( & V_35 ) ;
V_3 -> V_58 = true ;
F_37 ( V_3 ) ;
V_77:
F_39 (serio, &serio_list, node) {
if ( V_1 -> V_3 == V_3 ) {
F_26 ( V_1 ) ;
F_10 ( V_1 ) ;
goto V_77;
}
}
F_90 ( & V_3 -> V_17 ) ;
F_3 ( & V_35 ) ;
}
static void F_92 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_64 ( V_1 ) ;
V_1 -> V_3 = V_3 ;
F_65 ( V_1 ) ;
}
static int F_93 ( struct V_51 * V_16 , struct V_56 * V_3 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
struct V_2 * V_74 = F_50 ( V_3 ) ;
if ( V_1 -> V_58 || V_74 -> V_58 )
return 0 ;
return F_6 ( V_74 -> V_15 , V_1 ) ;
}
static int F_94 ( struct V_51 * V_16 , struct V_78 * V_79 )
{
struct V_1 * V_1 ;
if ( ! V_16 )
return - V_18 ;
V_1 = F_41 ( V_16 ) ;
F_95 ( L_18 , V_1 -> V_13 . type ) ;
F_95 ( L_19 , V_1 -> V_13 . V_11 ) ;
F_95 ( L_20 , V_1 -> V_13 . V_13 ) ;
F_95 ( L_21 , V_1 -> V_13 . V_14 ) ;
F_95 ( L_22 ,
V_1 -> V_13 . type , V_1 -> V_13 . V_11 , V_1 -> V_13 . V_13 , V_1 -> V_13 . V_14 ) ;
return 0 ;
}
static int F_94 ( struct V_51 * V_16 , struct V_78 * V_79 )
{
return - V_18 ;
}
static int F_96 ( struct V_51 * V_16 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
F_85 ( V_1 ) ;
return 0 ;
}
static int F_97 ( struct V_51 * V_16 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
F_29 ( V_1 , NULL , V_37 ) ;
return 0 ;
}
int F_98 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_92 ( V_1 , V_3 ) ;
if ( V_1 -> V_80 && V_1 -> V_80 ( V_1 ) ) {
F_92 ( V_1 , NULL ) ;
return - 1 ;
}
return 0 ;
}
void F_99 ( struct V_1 * V_1 )
{
if ( V_1 -> V_81 )
V_1 -> V_81 ( V_1 ) ;
F_92 ( V_1 , NULL ) ;
}
T_4 F_100 ( struct V_1 * V_1 ,
unsigned char V_82 , unsigned int V_83 )
{
unsigned long V_24 ;
T_4 V_84 = V_85 ;
F_13 ( & V_1 -> V_63 , V_24 ) ;
if ( F_101 ( V_1 -> V_3 ) ) {
V_84 = V_1 -> V_3 -> V_86 ( V_1 , V_82 , V_83 ) ;
} else if ( ! V_83 && F_70 ( & V_1 -> V_16 ) ) {
F_75 ( V_1 ) ;
V_84 = V_87 ;
}
F_17 ( & V_1 -> V_63 , V_24 ) ;
return V_84 ;
}
static int T_5 F_102 ( void )
{
int error ;
error = F_103 ( & V_57 ) ;
if ( error ) {
F_32 ( L_23 , error ) ;
return error ;
}
return 0 ;
}
static void T_6 F_104 ( void )
{
F_105 ( & V_57 ) ;
F_106 ( & V_48 ) ;
}

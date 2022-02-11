static T_1
F_1 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
char * V_6 = V_3 ;
if ( ! V_2 || ! V_3 )
return 0 ;
F_2 ( & V_5 -> V_7 , V_6 ) ;
V_6 += strlen ( V_6 ) ;
V_6 += sprintf ( V_6 , L_1 ) ;
return V_6 - V_3 ;
}
static T_1
F_3 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
char * V_6 = V_3 ;
if ( ! V_2 || ! V_3 )
return - V_8 ;
V_5 -> V_9 = 1024 ;
if ( F_4 ( V_2 , & V_5 -> V_10 , & V_5 -> V_9 , V_5 -> V_11 ) )
return - V_12 ;
if ( V_5 -> V_10 & V_13 )
V_6 += sprintf ( V_6 , L_2 ) ;
if ( V_5 -> V_10 & V_14 )
V_6 += sprintf ( V_6 , L_3 ) ;
if ( V_5 -> V_10 & V_15 )
V_6 += sprintf ( V_6 , L_4 ) ;
if ( V_5 -> V_10 & V_16 )
V_6 += sprintf ( V_6 , L_5 ) ;
if ( V_5 -> V_10 & V_17 )
V_6 += sprintf ( V_6 ,
L_6 ) ;
if ( V_5 -> V_10 &
V_18 )
V_6 += sprintf ( V_6 ,
L_7 ) ;
if ( V_5 -> V_10 & V_19 )
V_6 += sprintf ( V_6 , L_8 ) ;
return V_6 - V_3 ;
}
static T_1
F_5 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
char * V_6 = V_3 ;
if ( ! V_2 || ! V_3 )
return - V_8 ;
V_5 -> V_9 = 1024 ;
if ( F_4 ( V_2 , & V_5 -> V_10 , & V_5 -> V_9 , V_5 -> V_11 ) )
return - V_12 ;
V_6 += sprintf ( V_6 , L_9 , V_5 -> V_9 ) ;
return V_6 - V_3 ;
}
static T_1
F_6 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
if ( ! V_2 || ! V_3 )
return - V_8 ;
V_5 -> V_9 = 1024 ;
if ( F_4 ( V_2 , & V_5 -> V_10 , & V_5 -> V_9 , V_5 -> V_11 ) )
return - V_12 ;
memcpy ( V_3 , V_5 -> V_11 , V_5 -> V_9 ) ;
return V_5 -> V_9 ;
}
static inline int
F_7 ( struct V_4 * V_5 , T_2 * V_20 , T_3 V_21 ,
unsigned long V_22 , T_4 V_23 , T_5 * V_24 )
{
if ( memcmp ( V_20 , V_5 -> V_25 , sizeof( V_5 -> V_25 ) ) ||
F_8 ( V_21 , V_5 -> V_7 ) ) {
F_9 ( V_26 L_10 ) ;
return - V_8 ;
}
if ( ( V_22 <= 0 ) || ( V_23 == 0 ) ) {
F_9 ( V_26 L_11 ) ;
return - V_8 ;
}
if ( ( V_23 & ~ V_27 ) != 0 ||
F_10 ( V_21 , V_20 , V_24 , V_22 ) == false ) {
F_9 ( V_26 L_12 ) ;
return - V_8 ;
}
return 0 ;
}
static inline bool F_11 ( void )
{
if ( F_12 ( V_28 ) && F_13 () )
return true ;
return false ;
}
static void
F_14 ( struct V_4 * V_29 , struct V_30 * V_31 )
{
memcpy ( V_29 -> V_25 , V_31 -> V_25 , V_32 ) ;
memcpy ( V_29 -> V_11 , V_31 -> V_11 , sizeof( V_31 -> V_11 ) ) ;
V_29 -> V_7 = V_31 -> V_7 ;
V_29 -> V_9 = V_31 -> V_9 ;
V_29 -> V_10 = V_31 -> V_10 ;
}
static T_1
F_15 ( struct V_1 * V_2 , const char * V_3 , T_6 V_33 )
{
struct V_4 * V_34 , * V_5 = & V_2 -> V_5 ;
T_2 * V_20 ;
unsigned long V_22 ;
T_3 V_21 ;
T_4 V_23 ;
T_5 * V_24 ;
int V_35 ;
if ( F_11 () ) {
struct V_30 * V_36 ;
if ( V_33 != sizeof( * V_36 ) )
return - V_8 ;
V_36 = (struct V_30 * ) V_3 ;
V_23 = V_36 -> V_10 ;
V_21 = V_36 -> V_7 ;
V_20 = V_36 -> V_25 ;
V_22 = V_36 -> V_9 ;
V_24 = V_36 -> V_11 ;
V_35 = F_7 ( V_5 , V_20 , V_21 , V_22 , V_23 , V_24 ) ;
if ( V_35 )
return V_35 ;
F_14 ( & V_2 -> V_5 , V_36 ) ;
} else {
if ( V_33 != sizeof( struct V_4 ) )
return - V_8 ;
V_34 = (struct V_4 * ) V_3 ;
V_23 = V_34 -> V_10 ;
V_21 = V_34 -> V_7 ;
V_20 = V_34 -> V_25 ;
V_22 = V_34 -> V_9 ;
V_24 = V_34 -> V_11 ;
V_35 = F_7 ( V_5 , V_20 , V_21 , V_22 , V_23 , V_24 ) ;
if ( V_35 )
return V_35 ;
memcpy ( & V_2 -> V_5 , V_34 , V_33 ) ;
}
V_35 = F_16 ( V_2 , V_23 , V_22 , V_24 , NULL ) ;
if ( V_35 ) {
F_9 ( V_37 L_13 , V_35 ) ;
return - V_12 ;
}
return V_33 ;
}
static T_1
F_17 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_30 * V_36 ;
T_6 V_22 ;
if ( ! V_2 || ! V_3 )
return 0 ;
V_5 -> V_9 = 1024 ;
if ( F_4 ( V_2 , & V_2 -> V_5 . V_10 ,
& V_2 -> V_5 . V_9 , V_2 -> V_5 . V_11 ) )
return - V_12 ;
if ( F_11 () ) {
V_36 = (struct V_30 * ) V_3 ;
V_22 = sizeof( * V_36 ) ;
memcpy ( V_36 -> V_25 , V_5 -> V_25 ,
V_32 ) ;
memcpy ( V_36 -> V_11 , V_5 -> V_11 , sizeof( V_36 -> V_11 ) ) ;
V_36 -> V_7 = V_5 -> V_7 ;
V_36 -> V_9 = V_5 -> V_9 ;
V_36 -> V_10 = V_5 -> V_10 ;
} else {
V_22 = sizeof( * V_5 ) ;
memcpy ( V_3 , V_5 , V_22 ) ;
}
return V_22 ;
}
static T_1 F_18 ( struct V_38 * V_39 , struct V_40 * V_41 ,
char * V_3 )
{
struct V_1 * V_5 = F_19 ( V_39 ) ;
struct V_42 * V_43 = F_20 ( V_41 ) ;
T_1 V_44 = - V_12 ;
if ( ! F_21 ( V_45 ) )
return - V_46 ;
if ( V_43 -> V_47 ) {
V_44 = V_43 -> V_47 ( V_5 , V_3 ) ;
}
return V_44 ;
}
static T_1 F_22 ( struct V_38 * V_39 , struct V_40 * V_41 ,
const char * V_3 , T_6 V_33 )
{
struct V_1 * V_5 = F_19 ( V_39 ) ;
struct V_42 * V_43 = F_20 ( V_41 ) ;
T_1 V_44 = - V_12 ;
if ( ! F_21 ( V_45 ) )
return - V_46 ;
if ( V_43 -> V_48 )
V_44 = V_43 -> V_48 ( V_5 , V_3 , V_33 ) ;
return V_44 ;
}
static void F_23 ( struct V_38 * V_39 )
{
struct V_1 * V_5 = F_19 ( V_39 ) ;
F_24 ( V_5 ) ;
}
static T_1 F_25 ( struct V_49 * V_50 , struct V_38 * V_39 ,
struct V_51 * V_52 ,
char * V_3 , T_7 V_53 , T_6 V_33 )
{
struct V_30 * V_36 = (struct V_30 * ) V_3 ;
struct V_4 * V_34 = (struct V_4 * ) V_3 ;
struct V_1 * V_54 ;
bool V_55 = F_11 () ;
T_2 * V_20 ;
unsigned long V_22 ;
T_4 V_23 ;
T_5 * V_24 ;
int V_35 ;
if ( ! F_21 ( V_45 ) )
return - V_46 ;
if ( V_55 ) {
if ( V_33 != sizeof( * V_36 ) )
return - V_8 ;
V_23 = V_36 -> V_10 ;
V_20 = V_36 -> V_25 ;
V_22 = V_36 -> V_9 ;
V_24 = V_36 -> V_11 ;
} else {
if ( V_33 != sizeof( * V_34 ) )
return - V_8 ;
V_23 = V_34 -> V_10 ;
V_20 = V_34 -> V_25 ;
V_22 = V_34 -> V_9 ;
V_24 = V_34 -> V_11 ;
}
if ( ( V_23 & ~ V_27 ) != 0 ||
F_10 ( V_34 -> V_7 , V_20 , V_24 ,
V_22 ) == false ) {
F_9 ( V_26 L_12 ) ;
return - V_8 ;
}
V_54 = F_26 ( sizeof( * V_54 ) , V_56 ) ;
if ( ! V_54 )
return - V_57 ;
if ( V_55 )
F_14 ( & V_54 -> V_5 , V_36 ) ;
else
memcpy ( & V_54 -> V_5 , V_34 , sizeof( * V_34 ) ) ;
V_35 = F_16 ( V_54 , V_23 , V_22 ,
V_24 , & V_58 ) ;
if ( V_35 ) {
if ( V_35 == - V_59 )
V_35 = - V_8 ;
goto V_60;
}
if ( F_27 ( V_54 ) ) {
F_9 ( V_37 L_14 ) ;
F_24 ( V_54 ) ;
}
return V_33 ;
V_60:
F_24 ( V_54 ) ;
return V_35 ;
}
static T_1 F_28 ( struct V_49 * V_50 , struct V_38 * V_39 ,
struct V_51 * V_52 ,
char * V_3 , T_7 V_53 , T_6 V_33 )
{
struct V_4 * V_61 = (struct V_4 * ) V_3 ;
struct V_30 * V_36 ;
struct V_1 * V_2 ;
T_2 * V_20 ;
T_3 V_21 ;
int V_35 = 0 ;
if ( ! F_21 ( V_45 ) )
return - V_46 ;
if ( F_11 () ) {
if ( V_33 != sizeof( * V_36 ) )
return - V_8 ;
V_36 = (struct V_30 * ) V_3 ;
V_20 = V_36 -> V_25 ;
V_21 = V_36 -> V_7 ;
} else {
if ( V_33 != sizeof( * V_61 ) )
return - V_8 ;
V_20 = V_61 -> V_25 ;
V_21 = V_61 -> V_7 ;
}
F_29 () ;
V_2 = F_30 ( V_20 , V_21 , & V_58 , true ) ;
if ( ! V_2 )
V_35 = - V_8 ;
else if ( F_31 ( V_2 ) )
V_35 = - V_12 ;
if ( V_35 ) {
F_32 () ;
return V_35 ;
}
if ( ! V_2 -> V_62 ) {
F_32 () ;
F_33 ( V_2 ) ;
} else
F_32 () ;
return V_33 ;
}
static int
F_27 ( struct V_1 * V_34 )
{
int V_63 ;
char * V_64 ;
unsigned long V_65 ;
T_2 * V_66 = V_34 -> V_5 . V_25 ;
int V_44 ;
V_65 = F_34 ( V_66 ) ;
V_63 = V_65 + 1 + V_67 + 1 ;
V_64 = F_35 ( V_63 , V_56 ) ;
if ( ! V_64 )
return - V_57 ;
F_36 ( V_64 , V_66 , V_63 ) ;
V_64 [ V_65 ] = '-' ;
F_2 ( & V_34 -> V_5 . V_7 ,
V_64 + V_65 + 1 ) ;
V_34 -> V_39 . V_68 = V_69 ;
V_44 = F_37 ( & V_34 -> V_39 , & V_70 ,
NULL , L_15 , V_64 ) ;
F_24 ( V_64 ) ;
if ( V_44 )
return V_44 ;
F_38 ( & V_34 -> V_39 , V_71 ) ;
F_39 ( V_34 , & V_58 ) ;
return 0 ;
}
static int
F_40 ( void )
{
struct V_51 * V_41 ;
int error ;
V_41 = F_26 ( sizeof( * V_41 ) , V_56 ) ;
if ( ! V_41 )
return - V_57 ;
V_41 -> V_41 . V_20 = L_16 ;
V_41 -> V_41 . V_72 = 0200 ;
V_41 -> V_73 = F_25 ;
V_74 = V_41 ;
V_41 = F_26 ( sizeof( * V_41 ) , V_56 ) ;
if ( ! V_41 ) {
error = - V_57 ;
goto V_75;
}
V_41 -> V_41 . V_20 = L_17 ;
V_41 -> V_41 . V_72 = 0200 ;
V_41 -> V_73 = F_28 ;
V_76 = V_41 ;
F_41 ( V_74 ) ;
F_41 ( V_76 ) ;
error = F_42 ( & V_69 -> V_39 , V_74 ) ;
if ( error ) {
F_9 ( V_26 L_18
L_19 , error ) ;
goto V_75;
}
error = F_42 ( & V_69 -> V_39 , V_76 ) ;
if ( error ) {
F_9 ( V_26 L_20
L_19 , error ) ;
F_43 ( & V_69 -> V_39 , V_74 ) ;
goto V_75;
}
return 0 ;
V_75:
F_24 ( V_76 ) ;
V_76 = NULL ;
F_24 ( V_74 ) ;
V_74 = NULL ;
return error ;
}
static int F_44 ( T_2 * V_20 , T_3 V_21 ,
unsigned long V_77 , void * V_24 )
{
struct V_1 * V_2 = V_24 ;
if ( F_30 ( V_20 , V_21 , & V_58 , false ) )
return 0 ;
memcpy ( V_2 -> V_5 . V_25 , V_20 , V_77 ) ;
memcpy ( & ( V_2 -> V_5 . V_7 ) , & V_21 , sizeof( T_3 ) ) ;
return 1 ;
}
static void F_45 ( struct V_78 * V_79 )
{
struct V_1 * V_2 ;
int V_35 ;
while ( 1 ) {
V_2 = F_26 ( sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 )
return;
V_35 = F_46 ( F_44 , V_2 ,
false , & V_58 ) ;
if ( ! V_35 )
break;
F_27 ( V_2 ) ;
}
F_24 ( V_2 ) ;
}
static int F_47 ( T_2 * V_20 , T_3 V_21 ,
unsigned long V_77 , void * V_24 )
{
struct V_1 * V_2 ;
V_2 = F_26 ( sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 )
return - V_57 ;
memcpy ( V_2 -> V_5 . V_25 , V_20 , V_77 ) ;
memcpy ( & ( V_2 -> V_5 . V_7 ) , & V_21 , sizeof( T_3 ) ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , void * V_24 )
{
F_49 ( V_2 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static void F_50 ( void )
{
F_51 ( F_48 , & V_58 , NULL , NULL ) ;
if ( V_74 )
F_43 ( & V_69 -> V_39 , V_74 ) ;
if ( V_76 )
F_43 ( & V_69 -> V_39 , V_76 ) ;
F_24 ( V_74 ) ;
F_24 ( V_76 ) ;
F_52 ( V_69 ) ;
}
int F_53 ( void )
{
struct V_38 * V_80 = F_54 () ;
int error = 0 ;
if ( ! F_55 ( V_81 ) )
return - V_82 ;
if ( ! V_80 )
return 0 ;
F_9 ( V_83 L_21 , V_84 ,
V_85 ) ;
V_69 = F_56 ( L_22 , NULL , V_80 ) ;
if ( ! V_69 ) {
F_9 ( V_26 L_23 ) ;
return - V_57 ;
}
F_46 ( F_47 , NULL , true , & V_58 ) ;
error = F_40 () ;
if ( error ) {
F_50 () ;
return error ;
}
F_57 ( & V_86 , F_45 ) ;
return 0 ;
}

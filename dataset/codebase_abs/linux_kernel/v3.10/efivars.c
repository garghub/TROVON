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
static T_1
F_7 ( struct V_1 * V_2 , const char * V_3 , T_2 V_20 )
{
struct V_4 * V_21 , * V_5 = & V_2 -> V_5 ;
int V_22 ;
if ( V_20 != sizeof( struct V_4 ) )
return - V_8 ;
V_21 = (struct V_4 * ) V_3 ;
if ( memcmp ( V_21 -> V_23 , V_5 -> V_23 , sizeof( V_5 -> V_23 ) ) ||
F_8 ( V_21 -> V_7 , V_5 -> V_7 ) ) {
F_9 ( V_24 L_10 ) ;
return - V_8 ;
}
if ( ( V_21 -> V_9 <= 0 ) || ( V_21 -> V_10 == 0 ) ) {
F_9 ( V_24 L_11 ) ;
return - V_8 ;
}
if ( ( V_21 -> V_10 & ~ V_25 ) != 0 ||
F_10 ( V_21 , V_21 -> V_11 , V_21 -> V_9 ) == false ) {
F_9 ( V_24 L_12 ) ;
return - V_8 ;
}
memcpy ( & V_2 -> V_5 , V_21 , V_20 ) ;
V_22 = F_11 ( V_2 , V_21 -> V_10 ,
V_21 -> V_9 , V_21 -> V_11 , false ) ;
if ( V_22 ) {
F_9 ( V_26 L_13 , V_22 ) ;
return - V_12 ;
}
return V_20 ;
}
static T_1
F_12 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
if ( ! V_2 || ! V_3 )
return 0 ;
V_5 -> V_9 = 1024 ;
if ( F_4 ( V_2 , & V_2 -> V_5 . V_10 ,
& V_2 -> V_5 . V_9 , V_2 -> V_5 . V_11 ) )
return - V_12 ;
memcpy ( V_3 , V_5 , sizeof( * V_5 ) ) ;
return sizeof( * V_5 ) ;
}
static T_1 F_13 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_3 )
{
struct V_1 * V_5 = F_14 ( V_28 ) ;
struct V_31 * V_32 = F_15 ( V_30 ) ;
T_1 V_33 = - V_12 ;
if ( ! F_16 ( V_34 ) )
return - V_35 ;
if ( V_32 -> V_36 ) {
V_33 = V_32 -> V_36 ( V_5 , V_3 ) ;
}
return V_33 ;
}
static T_1 F_17 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_3 , T_2 V_20 )
{
struct V_1 * V_5 = F_14 ( V_28 ) ;
struct V_31 * V_32 = F_15 ( V_30 ) ;
T_1 V_33 = - V_12 ;
if ( ! F_16 ( V_34 ) )
return - V_35 ;
if ( V_32 -> V_37 )
V_33 = V_32 -> V_37 ( V_5 , V_3 , V_20 ) ;
return V_33 ;
}
static void F_18 ( struct V_27 * V_28 )
{
struct V_1 * V_5 = F_19 ( V_28 , struct V_1 , V_28 ) ;
F_20 ( V_5 ) ;
}
static T_1 F_21 ( struct V_38 * V_39 , struct V_27 * V_28 ,
struct V_40 * V_41 ,
char * V_3 , T_3 V_42 , T_2 V_20 )
{
struct V_4 * V_21 = (struct V_4 * ) V_3 ;
struct V_1 * V_43 ;
int V_22 ;
if ( ! F_16 ( V_34 ) )
return - V_35 ;
if ( ( V_21 -> V_10 & ~ V_25 ) != 0 ||
F_10 ( V_21 , V_21 -> V_11 , V_21 -> V_9 ) == false ) {
F_9 ( V_24 L_12 ) ;
return - V_8 ;
}
V_43 = F_22 ( sizeof( * V_43 ) , V_44 ) ;
if ( ! V_43 )
return - V_45 ;
memcpy ( & V_43 -> V_5 , V_21 , sizeof( * V_21 ) ) ;
V_22 = F_11 ( V_43 , V_21 -> V_10 , V_21 -> V_9 ,
V_21 -> V_11 , & V_46 ) ;
if ( V_22 ) {
if ( V_22 == - V_47 )
V_22 = - V_8 ;
goto V_48;
}
if ( F_23 ( V_43 ) ) {
F_9 ( V_26 L_14 ) ;
F_20 ( V_43 ) ;
}
return V_20 ;
V_48:
F_20 ( V_43 ) ;
return V_22 ;
}
static T_1 F_24 ( struct V_38 * V_39 , struct V_27 * V_28 ,
struct V_40 * V_41 ,
char * V_3 , T_3 V_42 , T_2 V_20 )
{
struct V_4 * V_49 = (struct V_4 * ) V_3 ;
struct V_1 * V_2 ;
int V_22 = 0 ;
if ( ! F_16 ( V_34 ) )
return - V_35 ;
F_25 () ;
V_2 = F_26 ( V_49 -> V_23 , V_49 -> V_7 ,
& V_46 , true ) ;
if ( ! V_2 )
V_22 = - V_8 ;
else if ( F_27 ( V_2 ) )
V_22 = - V_12 ;
F_28 () ;
if ( V_22 )
return V_22 ;
F_29 ( V_2 ) ;
return V_20 ;
}
static int
F_23 ( struct V_1 * V_21 )
{
int V_50 , V_51 ;
char * V_52 ;
unsigned long V_53 ;
T_4 * V_54 ;
V_54 = V_21 -> V_5 . V_23 ;
V_53 = F_30 ( V_54 ) * sizeof( T_4 ) ;
V_51 = V_53 / sizeof( T_4 )
+ 1 + V_55 + 1 ;
V_52 = F_22 ( V_51 , V_44 ) ;
if ( ! V_52 )
return 1 ;
for ( V_50 = 0 ; V_50 < ( int ) ( V_53 / sizeof( T_4 ) ) ; V_50 ++ ) {
V_52 [ V_50 ] = V_54 [ V_50 ] & 0xFF ;
}
* ( V_52 + strlen ( V_52 ) ) = '-' ;
F_2 ( & V_21 -> V_5 . V_7 ,
V_52 + strlen ( V_52 ) ) ;
V_21 -> V_28 . V_56 = V_57 ;
V_50 = F_31 ( & V_21 -> V_28 , & V_58 ,
NULL , L_15 , V_52 ) ;
F_20 ( V_52 ) ;
if ( V_50 )
return 1 ;
F_32 ( & V_21 -> V_28 , V_59 ) ;
F_33 ( V_21 , & V_46 ) ;
return 0 ;
}
static int
F_34 ( void )
{
struct V_40 * V_30 ;
int error ;
V_30 = F_22 ( sizeof( * V_30 ) , V_44 ) ;
if ( ! V_30 )
return - V_45 ;
V_30 -> V_30 . V_60 = L_16 ;
V_30 -> V_30 . V_61 = 0200 ;
V_30 -> V_62 = F_21 ;
V_63 = V_30 ;
V_30 = F_22 ( sizeof( * V_30 ) , V_44 ) ;
if ( ! V_30 ) {
error = - V_45 ;
goto V_64;
}
V_30 -> V_30 . V_60 = L_17 ;
V_30 -> V_30 . V_61 = 0200 ;
V_30 -> V_62 = F_24 ;
V_65 = V_30 ;
F_35 ( V_63 ) ;
F_35 ( V_65 ) ;
error = F_36 ( & V_57 -> V_28 , V_63 ) ;
if ( error ) {
F_9 ( V_24 L_18
L_19 , error ) ;
goto V_64;
}
error = F_36 ( & V_57 -> V_28 , V_65 ) ;
if ( error ) {
F_9 ( V_24 L_20
L_19 , error ) ;
F_37 ( & V_57 -> V_28 , V_63 ) ;
goto V_64;
}
return 0 ;
V_64:
F_20 ( V_65 ) ;
V_65 = NULL ;
F_20 ( V_63 ) ;
V_63 = NULL ;
return error ;
}
static int F_38 ( T_4 * V_60 , T_5 V_66 ,
unsigned long V_67 , void * V_68 )
{
struct V_1 * V_2 = V_68 ;
if ( F_26 ( V_60 , V_66 , & V_46 , false ) )
return 0 ;
memcpy ( V_2 -> V_5 . V_23 , V_60 , V_67 ) ;
memcpy ( & ( V_2 -> V_5 . V_7 ) , & V_66 , sizeof( T_5 ) ) ;
return 1 ;
}
static void F_39 ( struct V_69 * V_70 )
{
struct V_1 * V_2 ;
int V_22 ;
while ( 1 ) {
V_2 = F_22 ( sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 )
return;
V_22 = F_40 ( F_38 , V_2 ,
true , false , & V_46 ) ;
if ( ! V_22 )
break;
F_23 ( V_2 ) ;
}
F_20 ( V_2 ) ;
}
static int F_41 ( T_4 * V_60 , T_5 V_66 ,
unsigned long V_67 , void * V_68 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 )
return - V_45 ;
memcpy ( V_2 -> V_5 . V_23 , V_60 , V_67 ) ;
memcpy ( & ( V_2 -> V_5 . V_7 ) , & V_66 , sizeof( T_5 ) ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , void * V_68 )
{
F_43 ( V_2 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
void F_44 ( void )
{
F_45 ( F_42 , & V_46 , NULL , NULL ) ;
if ( V_63 )
F_37 ( & V_57 -> V_28 , V_63 ) ;
if ( V_65 )
F_37 ( & V_57 -> V_28 , V_65 ) ;
F_20 ( V_63 ) ;
F_20 ( V_65 ) ;
F_46 ( V_57 ) ;
}
int F_47 ( void )
{
struct V_27 * V_71 = F_48 () ;
int error = 0 ;
if ( ! V_71 )
return 0 ;
F_9 ( V_72 L_21 , V_73 ,
V_74 ) ;
V_57 = F_49 ( L_22 , NULL , V_71 ) ;
if ( ! V_57 ) {
F_9 ( V_24 L_23 ) ;
return - V_45 ;
}
F_40 ( F_41 , NULL , false ,
true , & V_46 ) ;
error = F_34 () ;
if ( error ) {
F_44 () ;
return error ;
}
F_50 ( & V_75 , F_39 ) ;
return 0 ;
}

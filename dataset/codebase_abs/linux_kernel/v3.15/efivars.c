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
V_21 -> V_9 , V_21 -> V_11 , NULL ) ;
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
if ( V_22 ) {
F_28 () ;
return V_22 ;
}
if ( ! V_2 -> V_50 ) {
F_28 () ;
F_29 ( V_2 ) ;
} else
F_28 () ;
return V_20 ;
}
static int
F_23 ( struct V_1 * V_21 )
{
int V_51 , V_52 ;
char * V_53 ;
unsigned long V_54 ;
T_4 * V_55 ;
V_55 = V_21 -> V_5 . V_23 ;
V_54 = F_30 ( V_55 ) * sizeof( T_4 ) ;
V_52 = V_54 / sizeof( T_4 )
+ 1 + V_56 + 1 ;
V_53 = F_22 ( V_52 , V_44 ) ;
if ( ! V_53 )
return 1 ;
for ( V_51 = 0 ; V_51 < ( int ) ( V_54 / sizeof( T_4 ) ) ; V_51 ++ ) {
V_53 [ V_51 ] = V_55 [ V_51 ] & 0xFF ;
}
* ( V_53 + strlen ( V_53 ) ) = '-' ;
F_2 ( & V_21 -> V_5 . V_7 ,
V_53 + strlen ( V_53 ) ) ;
V_21 -> V_28 . V_57 = V_58 ;
V_51 = F_31 ( & V_21 -> V_28 , & V_59 ,
NULL , L_15 , V_53 ) ;
F_20 ( V_53 ) ;
if ( V_51 )
return 1 ;
F_32 ( & V_21 -> V_28 , V_60 ) ;
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
V_30 -> V_30 . V_61 = L_16 ;
V_30 -> V_30 . V_62 = 0200 ;
V_30 -> V_63 = F_21 ;
V_64 = V_30 ;
V_30 = F_22 ( sizeof( * V_30 ) , V_44 ) ;
if ( ! V_30 ) {
error = - V_45 ;
goto V_65;
}
V_30 -> V_30 . V_61 = L_17 ;
V_30 -> V_30 . V_62 = 0200 ;
V_30 -> V_63 = F_24 ;
V_66 = V_30 ;
F_35 ( V_64 ) ;
F_35 ( V_66 ) ;
error = F_36 ( & V_58 -> V_28 , V_64 ) ;
if ( error ) {
F_9 ( V_24 L_18
L_19 , error ) ;
goto V_65;
}
error = F_36 ( & V_58 -> V_28 , V_66 ) ;
if ( error ) {
F_9 ( V_24 L_20
L_19 , error ) ;
F_37 ( & V_58 -> V_28 , V_64 ) ;
goto V_65;
}
return 0 ;
V_65:
F_20 ( V_66 ) ;
V_66 = NULL ;
F_20 ( V_64 ) ;
V_64 = NULL ;
return error ;
}
static int F_38 ( T_4 * V_61 , T_5 V_67 ,
unsigned long V_68 , void * V_69 )
{
struct V_1 * V_2 = V_69 ;
if ( F_26 ( V_61 , V_67 , & V_46 , false ) )
return 0 ;
memcpy ( V_2 -> V_5 . V_23 , V_61 , V_68 ) ;
memcpy ( & ( V_2 -> V_5 . V_7 ) , & V_67 , sizeof( T_5 ) ) ;
return 1 ;
}
static void F_39 ( struct V_70 * V_71 )
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
static int F_41 ( T_4 * V_61 , T_5 V_67 ,
unsigned long V_68 , void * V_69 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 )
return - V_45 ;
memcpy ( V_2 -> V_5 . V_23 , V_61 , V_68 ) ;
memcpy ( & ( V_2 -> V_5 . V_7 ) , & V_67 , sizeof( T_5 ) ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , void * V_69 )
{
F_43 ( V_2 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
static void F_44 ( void )
{
F_45 ( F_42 , & V_46 , NULL , NULL ) ;
if ( V_64 )
F_37 ( & V_58 -> V_28 , V_64 ) ;
if ( V_66 )
F_37 ( & V_58 -> V_28 , V_66 ) ;
F_20 ( V_64 ) ;
F_20 ( V_66 ) ;
F_46 ( V_58 ) ;
}
int F_47 ( void )
{
struct V_27 * V_72 = F_48 () ;
int error = 0 ;
if ( ! F_49 ( V_73 ) )
return - V_74 ;
if ( ! V_72 )
return 0 ;
F_9 ( V_75 L_21 , V_76 ,
V_77 ) ;
V_58 = F_50 ( L_22 , NULL , V_72 ) ;
if ( ! V_58 ) {
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
F_51 ( & V_78 , F_39 ) ;
return 0 ;
}

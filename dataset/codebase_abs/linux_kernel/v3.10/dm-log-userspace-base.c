static void * F_1 ( T_1 V_1 , void * V_2 )
{
return F_2 ( sizeof( struct V_3 ) , V_1 ) ;
}
static void F_3 ( void * V_4 , void * V_2 )
{
F_4 ( V_4 ) ;
}
static int F_5 ( struct V_5 * V_6 , const char * V_7 ,
int V_8 , char * V_9 , T_2 V_10 ,
char * V_11 , T_2 * V_12 )
{
int V_13 ;
V_14:
V_13 = F_6 ( V_7 , V_6 -> V_15 , V_8 , V_9 ,
V_10 , V_11 , V_12 ) ;
if ( V_13 != - V_16 )
return V_13 ;
F_7 ( L_1 ) ;
while ( 1 ) {
F_8 ( V_17 ) ;
F_9 ( 2 * V_18 ) ;
F_10 ( L_2 ) ;
V_13 = F_6 ( V_7 , V_6 -> V_15 , V_19 ,
V_6 -> V_20 ,
strlen ( V_6 -> V_20 ) + 1 ,
NULL , NULL ) ;
if ( ! V_13 )
break;
}
F_11 ( L_3 ) ;
V_13 = F_6 ( V_7 , V_6 -> V_15 , V_21 , NULL ,
0 , NULL , NULL ) ;
if ( ! V_13 )
goto V_14;
F_7 ( L_4 , V_13 ) ;
return - V_16 ;
}
static int F_12 ( struct V_22 * V_23 ,
unsigned V_24 , char * * V_25 ,
char * * V_26 )
{
int V_27 , V_28 ;
char * V_29 = NULL ;
* V_26 = NULL ;
for ( V_27 = 0 , V_28 = 0 ; V_27 < V_24 ; V_27 ++ )
V_28 += strlen ( V_25 [ V_27 ] ) + 1 ;
V_28 += 20 ;
V_29 = F_13 ( V_28 , V_30 ) ;
if ( ! V_29 ) {
F_10 ( L_5 ) ;
return - V_31 ;
}
V_28 = sprintf ( V_29 , L_6 , ( unsigned long long ) V_23 -> V_32 ) ;
for ( V_27 = 0 ; V_27 < V_24 ; V_27 ++ )
V_28 += sprintf ( V_29 + V_28 , L_7 , V_25 [ V_27 ] ) ;
* V_26 = V_29 ;
return V_28 ;
}
static int F_14 ( struct V_33 * log , struct V_22 * V_23 ,
unsigned V_24 , char * * V_25 )
{
int V_13 = 0 ;
int V_28 ;
char * V_26 = NULL ;
struct V_5 * V_6 = NULL ;
T_3 V_11 ;
T_2 V_12 = sizeof( V_11 ) ;
char * V_34 = NULL ;
T_2 V_35 = V_36 ;
if ( V_24 < 3 ) {
F_10 ( L_8 ) ;
return - V_37 ;
}
V_6 = F_13 ( sizeof( * V_6 ) , V_30 ) ;
if ( ! V_6 ) {
F_10 ( L_9 ) ;
return - V_31 ;
}
V_6 -> V_15 = ( unsigned long ) V_6 ;
V_6 -> V_23 = V_23 ;
if ( strlen ( V_25 [ 0 ] ) > ( V_38 - 1 ) ) {
F_10 ( L_10 ) ;
F_4 ( V_6 ) ;
return - V_37 ;
}
strncpy ( V_6 -> V_7 , V_25 [ 0 ] , V_38 ) ;
F_15 ( & V_6 -> V_39 ) ;
F_16 ( & V_6 -> V_40 ) ;
F_16 ( & V_6 -> V_41 ) ;
V_28 = F_12 ( V_23 , V_24 - 1 , V_25 + 1 , & V_26 ) ;
if ( V_28 < 0 ) {
F_4 ( V_6 ) ;
return V_28 ;
}
V_34 = F_13 ( V_35 , V_30 ) ;
if ( ! V_34 ) {
F_7 ( L_11 ) ;
V_13 = - V_31 ;
goto V_42;
}
V_13 = F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_19 ,
V_26 , V_28 ,
V_34 , & V_35 ) ;
if ( V_13 < 0 ) {
if ( V_13 == - V_16 )
F_7 ( L_12 ) ;
else
F_7 ( L_13 ) ;
goto V_42;
}
V_12 = sizeof( V_11 ) ;
V_13 = F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_43 ,
NULL , 0 , ( char * ) & V_11 , & V_12 ) ;
if ( V_13 ) {
F_7 ( L_14 ) ;
goto V_42;
}
V_6 -> V_44 = ( V_45 ) V_11 ;
V_6 -> V_46 = F_17 ( V_23 -> V_32 , V_6 -> V_44 ) ;
if ( V_35 ) {
if ( V_34 [ V_35 - 1 ] != '\0' ) {
F_7 ( L_15 ) ;
V_13 = - V_37 ;
goto V_42;
}
V_13 = F_18 ( V_23 , V_34 ,
F_19 ( V_23 -> V_47 ) , & V_6 -> V_48 ) ;
if ( V_13 )
F_7 ( L_16 ,
V_34 ) ;
}
V_42:
F_4 ( V_34 ) ;
if ( V_13 ) {
F_4 ( V_6 ) ;
F_4 ( V_26 ) ;
} else {
V_6 -> V_20 = V_26 ;
V_6 -> V_49 = V_24 ;
log -> V_50 = V_6 ;
}
return V_13 ;
}
static void F_20 ( struct V_33 * log )
{
struct V_5 * V_6 = log -> V_50 ;
( void ) F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_51 ,
NULL , 0 ,
NULL , NULL ) ;
if ( V_6 -> V_48 )
F_21 ( V_6 -> V_23 , V_6 -> V_48 ) ;
F_4 ( V_6 -> V_20 ) ;
F_4 ( V_6 ) ;
return;
}
static int F_22 ( struct V_33 * log )
{
int V_13 ;
struct V_5 * V_6 = log -> V_50 ;
V_13 = F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_52 ,
NULL , 0 ,
NULL , NULL ) ;
return V_13 ;
}
static int F_23 ( struct V_33 * log )
{
int V_13 ;
struct V_5 * V_6 = log -> V_50 ;
V_13 = F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_53 ,
NULL , 0 ,
NULL , NULL ) ;
return V_13 ;
}
static int F_24 ( struct V_33 * log )
{
int V_13 ;
struct V_5 * V_6 = log -> V_50 ;
V_6 -> V_54 = 0 ;
V_13 = F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_21 ,
NULL , 0 ,
NULL , NULL ) ;
return V_13 ;
}
static V_45 F_25 ( struct V_33 * log )
{
struct V_5 * V_6 = log -> V_50 ;
return V_6 -> V_44 ;
}
static int F_26 ( struct V_33 * log , T_4 V_55 )
{
int V_13 ;
T_3 V_56 = ( T_3 ) V_55 ;
T_5 V_57 ;
T_2 V_12 ;
struct V_5 * V_6 = log -> V_50 ;
V_12 = sizeof( V_57 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_58 ,
( char * ) & V_56 , sizeof( V_56 ) ,
( char * ) & V_57 , & V_12 ) ;
return ( V_13 ) ? 0 : ( int ) V_57 ;
}
static int F_27 ( struct V_33 * log , T_4 V_55 ,
int V_59 )
{
int V_13 ;
T_3 V_56 = V_55 ;
T_5 V_60 ;
T_2 V_12 ;
struct V_5 * V_6 = log -> V_50 ;
if ( ! V_59 )
return - V_61 ;
V_12 = sizeof( V_60 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_62 ,
( char * ) & V_56 , sizeof( V_56 ) ,
( char * ) & V_60 , & V_12 ) ;
return ( V_13 ) ? 0 : ( int ) V_60 ;
}
static int F_28 ( struct V_5 * V_6 , struct V_63 * V_64 )
{
int V_13 = 0 ;
struct V_3 * V_65 ;
F_29 (fe, flush_list, list) {
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_65 -> type ,
( char * ) & V_65 -> V_55 ,
sizeof( V_65 -> V_55 ) ,
NULL , NULL ) ;
if ( V_13 )
break;
}
return V_13 ;
}
static int F_30 ( struct V_5 * V_6 , struct V_63 * V_64 )
{
int V_13 = 0 ;
int V_66 ;
V_45 type = 0 ;
struct V_3 * V_65 , * V_67 ;
F_31 ( V_68 ) ;
T_3 V_69 [ V_70 ] ;
while ( ! F_32 ( V_64 ) ) {
V_66 = 0 ;
F_33 (fe, tmp_fe, flush_list, list) {
V_69 [ V_66 ] = V_65 -> V_55 ;
V_66 ++ ;
F_34 ( & V_65 -> V_71 , & V_68 ) ;
type = V_65 -> type ;
if ( V_66 >= V_70 )
break;
}
V_13 = F_5 ( V_6 , V_6 -> V_7 , type ,
( char * ) ( V_69 ) ,
V_66 * sizeof( T_3 ) ,
NULL , NULL ) ;
if ( V_13 ) {
F_35 ( & V_68 , V_64 ) ;
V_13 = F_28 ( V_6 , V_64 ) ;
break;
}
}
F_35 ( & V_68 , V_64 ) ;
return V_13 ;
}
static int F_36 ( struct V_33 * log )
{
int V_13 = 0 ;
unsigned long V_72 ;
struct V_5 * V_6 = log -> V_50 ;
F_31 ( V_40 ) ;
F_31 ( V_41 ) ;
struct V_3 * V_65 , * V_67 ;
F_37 ( & V_6 -> V_39 , V_72 ) ;
F_35 ( & V_6 -> V_40 , & V_40 ) ;
F_35 ( & V_6 -> V_41 , & V_41 ) ;
F_38 ( & V_6 -> V_39 , V_72 ) ;
if ( F_32 ( & V_40 ) && F_32 ( & V_41 ) )
return 0 ;
V_13 = F_30 ( V_6 , & V_40 ) ;
if ( V_13 )
goto V_73;
V_13 = F_30 ( V_6 , & V_41 ) ;
if ( V_13 )
goto V_73;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_74 ,
NULL , 0 , NULL , NULL ) ;
V_73:
F_33 (fe, tmp_fe, &mark_list, list) {
F_39 ( & V_65 -> V_71 ) ;
F_40 ( V_65 , V_75 ) ;
}
F_33 (fe, tmp_fe, &clear_list, list) {
F_39 ( & V_65 -> V_71 ) ;
F_40 ( V_65 , V_75 ) ;
}
if ( V_13 )
F_41 ( V_6 -> V_23 -> V_47 ) ;
return V_13 ;
}
static void F_42 ( struct V_33 * log , T_4 V_55 )
{
unsigned long V_72 ;
struct V_5 * V_6 = log -> V_50 ;
struct V_3 * V_65 ;
V_65 = F_43 ( V_75 , V_76 ) ;
F_44 ( ! V_65 ) ;
F_37 ( & V_6 -> V_39 , V_72 ) ;
V_65 -> type = V_77 ;
V_65 -> V_55 = V_55 ;
F_45 ( & V_65 -> V_71 , & V_6 -> V_40 ) ;
F_38 ( & V_6 -> V_39 , V_72 ) ;
return;
}
static void F_46 ( struct V_33 * log , T_4 V_55 )
{
unsigned long V_72 ;
struct V_5 * V_6 = log -> V_50 ;
struct V_3 * V_65 ;
V_65 = F_43 ( V_75 , V_78 ) ;
if ( ! V_65 ) {
F_7 ( L_17 ) ;
return;
}
F_37 ( & V_6 -> V_39 , V_72 ) ;
V_65 -> type = V_79 ;
V_65 -> V_55 = V_55 ;
F_45 ( & V_65 -> V_71 , & V_6 -> V_41 ) ;
F_38 ( & V_6 -> V_39 , V_72 ) ;
return;
}
static int F_47 ( struct V_33 * log , T_4 * V_55 )
{
int V_13 ;
T_2 V_12 ;
struct V_5 * V_6 = log -> V_50 ;
struct {
T_5 V_27 ;
T_4 V_13 ;
} V_80 ;
if ( V_6 -> V_54 >= V_6 -> V_46 )
return 0 ;
V_12 = sizeof( V_80 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_81 ,
NULL , 0 ,
( char * ) & V_80 , & V_12 ) ;
* V_55 = V_80 . V_13 ;
return ( V_13 ) ? V_13 : ( int ) V_80 . V_27 ;
}
static void F_48 ( struct V_33 * log ,
T_4 V_55 , int V_60 )
{
int V_13 ;
struct V_5 * V_6 = log -> V_50 ;
struct {
T_4 V_13 ;
T_5 V_27 ;
} V_80 ;
V_80 . V_13 = V_55 ;
V_80 . V_27 = ( T_5 ) V_60 ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_82 ,
( char * ) & V_80 , sizeof( V_80 ) ,
NULL , NULL ) ;
return;
}
static T_4 F_49 ( struct V_33 * log )
{
int V_13 ;
T_2 V_12 ;
T_3 V_83 ;
struct V_5 * V_6 = log -> V_50 ;
V_12 = sizeof( V_83 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_84 ,
NULL , 0 ,
( char * ) & V_83 , & V_12 ) ;
if ( V_13 )
return 0 ;
if ( V_83 >= V_6 -> V_46 )
V_6 -> V_54 = V_6 -> V_46 ;
return ( T_4 ) V_83 ;
}
static int F_50 ( struct V_33 * log , T_6 V_85 ,
char * V_86 , unsigned V_87 )
{
int V_13 = 0 ;
char * V_88 ;
T_2 V_89 = ( T_2 ) V_87 ;
struct V_5 * V_6 = log -> V_50 ;
switch ( V_85 ) {
case V_90 :
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_91 ,
NULL , 0 ,
V_86 , & V_89 ) ;
if ( V_13 ) {
V_89 = 0 ;
F_51 ( L_18 , log -> type -> V_92 ) ;
}
break;
case V_93 :
V_89 = 0 ;
V_88 = strchr ( V_6 -> V_20 , ' ' ) ;
F_44 ( ! V_88 ) ;
V_88 ++ ;
F_51 ( L_19 , log -> type -> V_92 , V_6 -> V_49 ,
V_6 -> V_7 , V_88 ) ;
break;
}
return ( V_13 ) ? 0 : ( int ) V_89 ;
}
static int F_52 ( struct V_33 * log ,
T_4 V_55 )
{
int V_13 ;
T_3 V_56 = V_55 ;
struct V_5 * V_6 = log -> V_50 ;
static unsigned long long V_94 ;
struct {
T_5 V_95 ;
T_3 V_54 ;
} V_80 ;
T_2 V_12 = sizeof( V_80 ) ;
if ( V_55 < V_6 -> V_54 )
return 0 ;
else if ( V_96 < V_94 )
return 1 ;
V_94 = V_96 + ( V_18 / 4 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_97 ,
( char * ) & V_56 , sizeof( V_56 ) ,
( char * ) & V_80 , & V_12 ) ;
if ( V_13 )
return 1 ;
V_6 -> V_54 = V_80 . V_54 ;
return ( int ) V_80 . V_95 ;
}
static int T_7 F_53 ( void )
{
int V_13 = 0 ;
V_75 = F_54 ( 100 , F_1 ,
F_3 , NULL ) ;
if ( ! V_75 ) {
F_10 ( L_20 ) ;
return - V_31 ;
}
V_13 = F_55 () ;
if ( V_13 ) {
F_10 ( L_21 ) ;
F_56 ( V_75 ) ;
return V_13 ;
}
V_13 = F_57 ( & V_98 ) ;
if ( V_13 ) {
F_10 ( L_22 ) ;
F_58 () ;
F_56 ( V_75 ) ;
return V_13 ;
}
F_11 ( L_23 V_99 L_24 ) ;
return 0 ;
}
static void T_8 F_59 ( void )
{
F_60 ( & V_98 ) ;
F_58 () ;
F_56 ( V_75 ) ;
F_11 ( L_23 V_99 L_25 ) ;
return;
}

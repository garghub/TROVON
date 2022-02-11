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
if ( V_24 < 3 ) {
F_10 ( L_8 ) ;
return - V_34 ;
}
V_6 = F_2 ( sizeof( * V_6 ) , V_30 ) ;
if ( ! V_6 ) {
F_10 ( L_9 ) ;
return - V_31 ;
}
V_6 -> V_15 = ( unsigned long ) V_6 ;
V_6 -> V_23 = V_23 ;
if ( strlen ( V_25 [ 0 ] ) > ( V_35 - 1 ) ) {
F_10 ( L_10 ) ;
F_4 ( V_6 ) ;
return - V_34 ;
}
strncpy ( V_6 -> V_7 , V_25 [ 0 ] , V_35 ) ;
F_15 ( & V_6 -> V_36 ) ;
F_16 ( & V_6 -> V_37 ) ;
F_16 ( & V_6 -> V_38 ) ;
V_28 = F_12 ( V_23 , V_24 - 1 , V_25 + 1 , & V_26 ) ;
if ( V_28 < 0 ) {
F_4 ( V_6 ) ;
return V_28 ;
}
V_13 = F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_19 ,
V_26 , V_28 , NULL , NULL ) ;
if ( V_13 < 0 ) {
if ( V_13 == - V_16 )
F_7 ( L_11 ) ;
else
F_7 ( L_12 ) ;
goto V_39;
}
V_12 = sizeof( V_11 ) ;
V_13 = F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_40 ,
NULL , 0 , ( char * ) & V_11 , & V_12 ) ;
if ( V_13 ) {
F_7 ( L_13 ) ;
goto V_39;
}
V_6 -> V_41 = ( V_42 ) V_11 ;
V_6 -> V_43 = F_17 ( V_23 -> V_32 , V_6 -> V_41 ) ;
V_39:
if ( V_13 ) {
F_4 ( V_6 ) ;
F_4 ( V_26 ) ;
} else {
V_6 -> V_20 = V_26 ;
V_6 -> V_44 = V_24 ;
log -> V_45 = V_6 ;
}
return V_13 ;
}
static void F_18 ( struct V_33 * log )
{
struct V_5 * V_6 = log -> V_45 ;
( void ) F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_46 ,
NULL , 0 ,
NULL , NULL ) ;
F_4 ( V_6 -> V_20 ) ;
F_4 ( V_6 ) ;
return;
}
static int F_19 ( struct V_33 * log )
{
int V_13 ;
struct V_5 * V_6 = log -> V_45 ;
V_13 = F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_47 ,
NULL , 0 ,
NULL , NULL ) ;
return V_13 ;
}
static int F_20 ( struct V_33 * log )
{
int V_13 ;
struct V_5 * V_6 = log -> V_45 ;
V_13 = F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_48 ,
NULL , 0 ,
NULL , NULL ) ;
return V_13 ;
}
static int F_21 ( struct V_33 * log )
{
int V_13 ;
struct V_5 * V_6 = log -> V_45 ;
V_6 -> V_49 = 0 ;
V_13 = F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_21 ,
NULL , 0 ,
NULL , NULL ) ;
return V_13 ;
}
static V_42 F_22 ( struct V_33 * log )
{
struct V_5 * V_6 = log -> V_45 ;
return V_6 -> V_41 ;
}
static int F_23 ( struct V_33 * log , T_4 V_50 )
{
int V_13 ;
T_3 V_51 = ( T_3 ) V_50 ;
T_5 V_52 ;
T_2 V_12 ;
struct V_5 * V_6 = log -> V_45 ;
V_12 = sizeof( V_52 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_53 ,
( char * ) & V_51 , sizeof( V_51 ) ,
( char * ) & V_52 , & V_12 ) ;
return ( V_13 ) ? 0 : ( int ) V_52 ;
}
static int F_24 ( struct V_33 * log , T_4 V_50 ,
int V_54 )
{
int V_13 ;
T_3 V_51 = V_50 ;
T_5 V_55 ;
T_2 V_12 ;
struct V_5 * V_6 = log -> V_45 ;
if ( ! V_54 )
return - V_56 ;
V_12 = sizeof( V_55 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_57 ,
( char * ) & V_51 , sizeof( V_51 ) ,
( char * ) & V_55 , & V_12 ) ;
return ( V_13 ) ? 0 : ( int ) V_55 ;
}
static int F_25 ( struct V_5 * V_6 , struct V_58 * V_59 )
{
int V_13 = 0 ;
struct V_3 * V_60 ;
F_26 (fe, flush_list, list) {
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_60 -> type ,
( char * ) & V_60 -> V_50 ,
sizeof( V_60 -> V_50 ) ,
NULL , NULL ) ;
if ( V_13 )
break;
}
return V_13 ;
}
static int F_27 ( struct V_5 * V_6 , struct V_58 * V_59 )
{
int V_13 = 0 ;
int V_61 ;
V_42 type = 0 ;
struct V_3 * V_60 , * V_62 ;
F_28 ( V_63 ) ;
T_3 V_64 [ V_65 ] ;
while ( ! F_29 ( V_59 ) ) {
V_61 = 0 ;
F_30 (fe, tmp_fe, flush_list, list) {
V_64 [ V_61 ] = V_60 -> V_50 ;
V_61 ++ ;
F_31 ( & V_60 -> V_66 ) ;
F_32 ( & V_60 -> V_66 , & V_63 ) ;
type = V_60 -> type ;
if ( V_61 >= V_65 )
break;
}
V_13 = F_5 ( V_6 , V_6 -> V_7 , type ,
( char * ) ( V_64 ) ,
V_61 * sizeof( T_3 ) ,
NULL , NULL ) ;
if ( V_13 ) {
F_33 ( & V_63 , V_59 ) ;
V_13 = F_25 ( V_6 , V_59 ) ;
break;
}
}
F_33 ( & V_63 , V_59 ) ;
return V_13 ;
}
static int F_34 ( struct V_33 * log )
{
int V_13 = 0 ;
unsigned long V_67 ;
struct V_5 * V_6 = log -> V_45 ;
F_28 ( V_37 ) ;
F_28 ( V_38 ) ;
struct V_3 * V_60 , * V_62 ;
F_35 ( & V_6 -> V_36 , V_67 ) ;
F_33 ( & V_6 -> V_37 , & V_37 ) ;
F_33 ( & V_6 -> V_38 , & V_38 ) ;
F_36 ( & V_6 -> V_36 , V_67 ) ;
if ( F_29 ( & V_37 ) && F_29 ( & V_38 ) )
return 0 ;
V_13 = F_27 ( V_6 , & V_37 ) ;
if ( V_13 )
goto V_68;
V_13 = F_27 ( V_6 , & V_38 ) ;
if ( V_13 )
goto V_68;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_69 ,
NULL , 0 , NULL , NULL ) ;
V_68:
F_30 (fe, tmp_fe, &mark_list, list) {
F_31 ( & V_60 -> V_66 ) ;
F_37 ( V_60 , V_70 ) ;
}
F_30 (fe, tmp_fe, &clear_list, list) {
F_31 ( & V_60 -> V_66 ) ;
F_37 ( V_60 , V_70 ) ;
}
if ( V_13 )
F_38 ( V_6 -> V_23 -> V_71 ) ;
return V_13 ;
}
static void F_39 ( struct V_33 * log , T_4 V_50 )
{
unsigned long V_67 ;
struct V_5 * V_6 = log -> V_45 ;
struct V_3 * V_60 ;
V_60 = F_40 ( V_70 , V_72 ) ;
F_41 ( ! V_60 ) ;
F_35 ( & V_6 -> V_36 , V_67 ) ;
V_60 -> type = V_73 ;
V_60 -> V_50 = V_50 ;
F_32 ( & V_60 -> V_66 , & V_6 -> V_37 ) ;
F_36 ( & V_6 -> V_36 , V_67 ) ;
return;
}
static void F_42 ( struct V_33 * log , T_4 V_50 )
{
unsigned long V_67 ;
struct V_5 * V_6 = log -> V_45 ;
struct V_3 * V_60 ;
V_60 = F_40 ( V_70 , V_74 ) ;
if ( ! V_60 ) {
F_7 ( L_14 ) ;
return;
}
F_35 ( & V_6 -> V_36 , V_67 ) ;
V_60 -> type = V_75 ;
V_60 -> V_50 = V_50 ;
F_32 ( & V_60 -> V_66 , & V_6 -> V_38 ) ;
F_36 ( & V_6 -> V_36 , V_67 ) ;
return;
}
static int F_43 ( struct V_33 * log , T_4 * V_50 )
{
int V_13 ;
T_2 V_12 ;
struct V_5 * V_6 = log -> V_45 ;
struct {
T_5 V_27 ;
T_4 V_13 ;
} V_76 ;
if ( V_6 -> V_49 >= V_6 -> V_43 )
return 0 ;
V_12 = sizeof( V_76 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_77 ,
NULL , 0 ,
( char * ) & V_76 , & V_12 ) ;
* V_50 = V_76 . V_13 ;
return ( V_13 ) ? V_13 : ( int ) V_76 . V_27 ;
}
static void F_44 ( struct V_33 * log ,
T_4 V_50 , int V_55 )
{
int V_13 ;
struct V_5 * V_6 = log -> V_45 ;
struct {
T_4 V_13 ;
T_5 V_27 ;
} V_76 ;
V_76 . V_13 = V_50 ;
V_76 . V_27 = ( T_5 ) V_55 ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_78 ,
( char * ) & V_76 , sizeof( V_76 ) ,
NULL , NULL ) ;
return;
}
static T_4 F_45 ( struct V_33 * log )
{
int V_13 ;
T_2 V_12 ;
T_3 V_79 ;
struct V_5 * V_6 = log -> V_45 ;
V_12 = sizeof( V_79 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_80 ,
NULL , 0 ,
( char * ) & V_79 , & V_12 ) ;
if ( V_13 )
return 0 ;
if ( V_79 >= V_6 -> V_43 )
V_6 -> V_49 = V_6 -> V_43 ;
return ( T_4 ) V_79 ;
}
static int F_46 ( struct V_33 * log , T_6 V_81 ,
char * V_82 , unsigned V_83 )
{
int V_13 = 0 ;
char * V_84 ;
T_2 V_85 = ( T_2 ) V_83 ;
struct V_5 * V_6 = log -> V_45 ;
switch ( V_81 ) {
case V_86 :
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_87 ,
NULL , 0 ,
V_82 , & V_85 ) ;
if ( V_13 ) {
V_85 = 0 ;
F_47 ( L_15 , log -> type -> V_88 ) ;
}
break;
case V_89 :
V_85 = 0 ;
V_84 = strchr ( V_6 -> V_20 , ' ' ) ;
F_41 ( ! V_84 ) ;
V_84 ++ ;
F_47 ( L_16 , log -> type -> V_88 , V_6 -> V_44 ,
V_6 -> V_7 , V_84 ) ;
break;
}
return ( V_13 ) ? 0 : ( int ) V_85 ;
}
static int F_48 ( struct V_33 * log ,
T_4 V_50 )
{
int V_13 ;
T_3 V_51 = V_50 ;
struct V_5 * V_6 = log -> V_45 ;
static unsigned long long V_90 ;
struct {
T_5 V_91 ;
T_3 V_49 ;
} V_76 ;
T_2 V_12 = sizeof( V_76 ) ;
if ( V_50 < V_6 -> V_49 )
return 0 ;
else if ( V_92 < V_90 )
return 1 ;
V_90 = V_92 + ( V_18 / 4 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_93 ,
( char * ) & V_51 , sizeof( V_51 ) ,
( char * ) & V_76 , & V_12 ) ;
if ( V_13 )
return 1 ;
V_6 -> V_49 = V_76 . V_49 ;
return ( int ) V_76 . V_91 ;
}
static int T_7 F_49 ( void )
{
int V_13 = 0 ;
V_70 = F_50 ( 100 , F_1 ,
F_3 , NULL ) ;
if ( ! V_70 ) {
F_10 ( L_17 ) ;
return - V_31 ;
}
V_13 = F_51 () ;
if ( V_13 ) {
F_10 ( L_18 ) ;
F_52 ( V_70 ) ;
return V_13 ;
}
V_13 = F_53 ( & V_94 ) ;
if ( V_13 ) {
F_10 ( L_19 ) ;
F_54 () ;
F_52 ( V_70 ) ;
return V_13 ;
}
F_11 ( L_20 V_95 L_21 ) ;
return 0 ;
}
static void T_8 F_55 ( void )
{
F_56 ( & V_94 ) ;
F_54 () ;
F_52 ( V_70 ) ;
F_11 ( L_20 V_95 L_22 ) ;
return;
}

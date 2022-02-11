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
static void F_14 ( struct V_33 * V_34 )
{
int V_13 ;
struct V_5 * V_6 = F_15 ( V_34 , struct V_5 , V_35 . V_34 ) ;
F_16 ( & V_6 -> V_36 , 0 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_37 , NULL , 0 , NULL , NULL ) ;
if ( V_13 )
F_17 ( V_6 -> V_23 -> V_38 ) ;
}
static int F_18 ( struct V_39 * log , struct V_22 * V_23 ,
unsigned V_24 , char * * V_25 )
{
int V_13 = 0 ;
int V_28 ;
char * V_26 = NULL ;
struct V_5 * V_6 = NULL ;
T_3 V_11 ;
T_2 V_12 = sizeof( V_11 ) ;
char * V_40 = NULL ;
T_2 V_41 = V_42 ;
if ( V_24 < 3 ) {
F_10 ( L_8 ) ;
return - V_43 ;
}
V_6 = F_13 ( sizeof( * V_6 ) , V_30 ) ;
if ( ! V_6 ) {
F_10 ( L_9 ) ;
return - V_31 ;
}
V_6 -> V_15 = ( unsigned long ) V_6 ;
V_6 -> V_23 = V_23 ;
if ( strlen ( V_25 [ 0 ] ) > ( V_44 - 1 ) ) {
F_10 ( L_10 ) ;
F_4 ( V_6 ) ;
return - V_43 ;
}
V_6 -> V_45 = V_24 ;
strncpy ( V_6 -> V_7 , V_25 [ 0 ] , V_44 ) ;
V_24 -- ;
V_25 ++ ;
F_19 ( & V_6 -> V_46 ) ;
F_20 ( & V_6 -> V_47 ) ;
F_20 ( & V_6 -> V_48 ) ;
if ( ! strcasecmp ( V_25 [ 0 ] , L_11 ) ) {
V_6 -> V_49 = 1 ;
V_24 -- ;
V_25 ++ ;
}
V_28 = F_12 ( V_23 , V_24 , V_25 , & V_26 ) ;
if ( V_28 < 0 ) {
F_4 ( V_6 ) ;
return V_28 ;
}
V_40 = F_13 ( V_41 , V_30 ) ;
if ( ! V_40 ) {
F_7 ( L_12 ) ;
V_13 = - V_31 ;
goto V_50;
}
V_13 = F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_19 ,
V_26 , V_28 ,
V_40 , & V_41 ) ;
if ( V_13 < 0 ) {
if ( V_13 == - V_16 )
F_7 ( L_13 ) ;
else
F_7 ( L_14 ) ;
goto V_50;
}
V_12 = sizeof( V_11 ) ;
V_13 = F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_51 ,
NULL , 0 , ( char * ) & V_11 , & V_12 ) ;
if ( V_13 ) {
F_7 ( L_15 ) ;
goto V_50;
}
V_6 -> V_52 = ( V_53 ) V_11 ;
V_6 -> V_54 = F_21 ( V_23 -> V_32 , V_6 -> V_52 ) ;
if ( V_41 ) {
if ( V_40 [ V_41 - 1 ] != '\0' ) {
F_7 ( L_16 ) ;
V_13 = - V_43 ;
goto V_50;
}
V_13 = F_22 ( V_23 , V_40 ,
F_23 ( V_23 -> V_38 ) , & V_6 -> V_55 ) ;
if ( V_13 )
F_7 ( L_17 ,
V_40 ) ;
}
if ( V_6 -> V_49 ) {
V_6 -> V_56 = F_24 ( L_18 , V_57 , 0 ) ;
if ( ! V_6 -> V_56 ) {
F_7 ( L_19 ) ;
V_13 = - V_31 ;
goto V_50;
}
F_25 ( & V_6 -> V_35 , F_14 ) ;
F_16 ( & V_6 -> V_36 , 0 ) ;
}
V_50:
F_4 ( V_40 ) ;
if ( V_13 ) {
F_4 ( V_6 ) ;
F_4 ( V_26 ) ;
} else {
V_6 -> V_20 = V_26 ;
log -> V_58 = V_6 ;
}
return V_13 ;
}
static void F_26 ( struct V_39 * log )
{
struct V_5 * V_6 = log -> V_58 ;
if ( V_6 -> V_49 ) {
if ( F_27 ( & V_6 -> V_36 ) )
F_28 ( & V_6 -> V_35 ) ;
F_29 ( V_6 -> V_56 ) ;
}
( void ) F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_59 ,
NULL , 0 , NULL , NULL ) ;
if ( V_6 -> V_55 )
F_30 ( V_6 -> V_23 , V_6 -> V_55 ) ;
F_4 ( V_6 -> V_20 ) ;
F_4 ( V_6 ) ;
return;
}
static int F_31 ( struct V_39 * log )
{
int V_13 ;
struct V_5 * V_6 = log -> V_58 ;
V_13 = F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_60 ,
NULL , 0 , NULL , NULL ) ;
return V_13 ;
}
static int F_32 ( struct V_39 * log )
{
int V_13 ;
struct V_5 * V_6 = log -> V_58 ;
if ( V_6 -> V_49 && F_27 ( & V_6 -> V_36 ) )
F_28 ( & V_6 -> V_35 ) ;
V_13 = F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_61 ,
NULL , 0 , NULL , NULL ) ;
return V_13 ;
}
static int F_33 ( struct V_39 * log )
{
int V_13 ;
struct V_5 * V_6 = log -> V_58 ;
V_6 -> V_62 = 0 ;
V_13 = F_6 ( V_6 -> V_7 , V_6 -> V_15 , V_21 ,
NULL , 0 , NULL , NULL ) ;
return V_13 ;
}
static V_53 F_34 ( struct V_39 * log )
{
struct V_5 * V_6 = log -> V_58 ;
return V_6 -> V_52 ;
}
static int F_35 ( struct V_39 * log , T_4 V_63 )
{
int V_13 ;
T_3 V_64 = ( T_3 ) V_63 ;
T_5 V_65 ;
T_2 V_12 ;
struct V_5 * V_6 = log -> V_58 ;
V_12 = sizeof( V_65 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_66 ,
( char * ) & V_64 , sizeof( V_64 ) ,
( char * ) & V_65 , & V_12 ) ;
return ( V_13 ) ? 0 : ( int ) V_65 ;
}
static int F_36 ( struct V_39 * log , T_4 V_63 ,
int V_67 )
{
int V_13 ;
T_3 V_64 = V_63 ;
T_5 V_68 ;
T_2 V_12 ;
struct V_5 * V_6 = log -> V_58 ;
if ( ! V_67 )
return - V_69 ;
V_12 = sizeof( V_68 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_70 ,
( char * ) & V_64 , sizeof( V_64 ) ,
( char * ) & V_68 , & V_12 ) ;
return ( V_13 ) ? 0 : ( int ) V_68 ;
}
static int F_37 ( struct V_5 * V_6 , struct V_71 * V_72 )
{
int V_13 = 0 ;
struct V_3 * V_73 ;
F_38 (fe, flush_list, list) {
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_73 -> type ,
( char * ) & V_73 -> V_63 ,
sizeof( V_73 -> V_63 ) ,
NULL , NULL ) ;
if ( V_13 )
break;
}
return V_13 ;
}
static int F_39 ( struct V_5 * V_6 , struct V_71 * V_72 ,
int V_74 )
{
int V_13 = 0 ;
int V_75 ;
V_53 type = 0 ;
struct V_3 * V_73 , * V_76 ;
F_40 ( V_77 ) ;
T_3 V_78 [ V_79 ] ;
while ( ! F_41 ( V_72 ) ) {
V_75 = 0 ;
F_42 (fe, tmp_fe, flush_list, list) {
V_78 [ V_75 ] = V_73 -> V_63 ;
V_75 ++ ;
F_43 ( & V_73 -> V_80 , & V_77 ) ;
type = V_73 -> type ;
if ( V_75 >= V_79 )
break;
}
if ( V_74 ) {
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_37 ,
( char * ) ( V_78 ) ,
V_75 * sizeof( T_3 ) ,
NULL , NULL ) ;
if ( V_13 )
break;
} else {
V_13 = F_5 ( V_6 , V_6 -> V_7 , type ,
( char * ) ( V_78 ) ,
V_75 * sizeof( T_3 ) ,
NULL , NULL ) ;
if ( V_13 ) {
F_44 ( & V_77 , V_72 ) ;
V_13 = F_37 ( V_6 , V_72 ) ;
break;
}
}
}
F_44 ( & V_77 , V_72 ) ;
return V_13 ;
}
static int F_45 ( struct V_39 * log )
{
int V_13 = 0 ;
unsigned long V_81 ;
struct V_5 * V_6 = log -> V_58 ;
F_40 ( V_47 ) ;
F_40 ( V_48 ) ;
int V_82 ;
int V_83 ;
struct V_3 * V_73 , * V_76 ;
F_46 ( & V_6 -> V_46 , V_81 ) ;
F_44 ( & V_6 -> V_47 , & V_47 ) ;
F_44 ( & V_6 -> V_48 , & V_48 ) ;
F_47 ( & V_6 -> V_46 , V_81 ) ;
V_82 = F_41 ( & V_47 ) ;
V_83 = F_41 ( & V_48 ) ;
if ( V_82 && V_83 )
return 0 ;
V_13 = F_39 ( V_6 , & V_48 , 0 ) ;
if ( V_13 )
goto V_50;
if ( ! V_6 -> V_49 ) {
V_13 = F_39 ( V_6 , & V_47 , 0 ) ;
if ( V_13 )
goto V_50;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_37 ,
NULL , 0 , NULL , NULL ) ;
goto V_50;
}
V_13 = F_39 ( V_6 , & V_47 , 1 ) ;
if ( V_13 )
goto V_50;
if ( V_82 && ! F_27 ( & V_6 -> V_36 ) ) {
F_48 ( V_6 -> V_56 , & V_6 -> V_35 , 3 * V_18 ) ;
F_16 ( & V_6 -> V_36 , 1 ) ;
} else {
F_49 ( & V_6 -> V_35 ) ;
F_16 ( & V_6 -> V_36 , 0 ) ;
}
V_50:
F_42 (fe, tmp_fe, &mark_list, list) {
F_50 ( & V_73 -> V_80 ) ;
F_51 ( V_73 , V_84 ) ;
}
F_42 (fe, tmp_fe, &clear_list, list) {
F_50 ( & V_73 -> V_80 ) ;
F_51 ( V_73 , V_84 ) ;
}
if ( V_13 )
F_17 ( V_6 -> V_23 -> V_38 ) ;
return V_13 ;
}
static void F_52 ( struct V_39 * log , T_4 V_63 )
{
unsigned long V_81 ;
struct V_5 * V_6 = log -> V_58 ;
struct V_3 * V_73 ;
V_73 = F_53 ( V_84 , V_85 ) ;
F_54 ( ! V_73 ) ;
F_46 ( & V_6 -> V_46 , V_81 ) ;
V_73 -> type = V_86 ;
V_73 -> V_63 = V_63 ;
F_55 ( & V_73 -> V_80 , & V_6 -> V_47 ) ;
F_47 ( & V_6 -> V_46 , V_81 ) ;
return;
}
static void F_56 ( struct V_39 * log , T_4 V_63 )
{
unsigned long V_81 ;
struct V_5 * V_6 = log -> V_58 ;
struct V_3 * V_73 ;
V_73 = F_53 ( V_84 , V_87 ) ;
if ( ! V_73 ) {
F_7 ( L_20 ) ;
return;
}
F_46 ( & V_6 -> V_46 , V_81 ) ;
V_73 -> type = V_88 ;
V_73 -> V_63 = V_63 ;
F_55 ( & V_73 -> V_80 , & V_6 -> V_48 ) ;
F_47 ( & V_6 -> V_46 , V_81 ) ;
return;
}
static int F_57 ( struct V_39 * log , T_4 * V_63 )
{
int V_13 ;
T_2 V_12 ;
struct V_5 * V_6 = log -> V_58 ;
struct {
T_5 V_27 ;
T_4 V_13 ;
} V_89 ;
if ( V_6 -> V_62 >= V_6 -> V_54 )
return 0 ;
V_12 = sizeof( V_89 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_90 ,
NULL , 0 , ( char * ) & V_89 , & V_12 ) ;
* V_63 = V_89 . V_13 ;
return ( V_13 ) ? V_13 : ( int ) V_89 . V_27 ;
}
static void F_58 ( struct V_39 * log ,
T_4 V_63 , int V_68 )
{
int V_13 ;
struct V_5 * V_6 = log -> V_58 ;
struct {
T_4 V_13 ;
T_5 V_27 ;
} V_89 ;
V_89 . V_13 = V_63 ;
V_89 . V_27 = ( T_5 ) V_68 ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_91 ,
( char * ) & V_89 , sizeof( V_89 ) , NULL , NULL ) ;
return;
}
static T_4 F_59 ( struct V_39 * log )
{
int V_13 ;
T_2 V_12 ;
T_3 V_92 ;
struct V_5 * V_6 = log -> V_58 ;
V_12 = sizeof( V_92 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_93 ,
NULL , 0 , ( char * ) & V_92 , & V_12 ) ;
if ( V_13 )
return 0 ;
if ( V_92 >= V_6 -> V_54 )
V_6 -> V_62 = V_6 -> V_54 ;
return ( T_4 ) V_92 ;
}
static int F_60 ( struct V_39 * log , T_6 V_94 ,
char * V_95 , unsigned V_96 )
{
int V_13 = 0 ;
char * V_97 ;
T_2 V_98 = ( T_2 ) V_96 ;
struct V_5 * V_6 = log -> V_58 ;
switch ( V_94 ) {
case V_99 :
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_100 ,
NULL , 0 , V_95 , & V_98 ) ;
if ( V_13 ) {
V_98 = 0 ;
F_61 ( L_21 , log -> type -> V_101 ) ;
}
break;
case V_102 :
V_98 = 0 ;
V_97 = strchr ( V_6 -> V_20 , ' ' ) ;
F_54 ( ! V_97 ) ;
V_97 ++ ;
F_61 ( L_22 , log -> type -> V_101 , V_6 -> V_45 , V_6 -> V_7 ) ;
if ( V_6 -> V_49 )
F_61 ( L_23 ) ;
F_61 ( L_24 , V_97 ) ;
break;
}
return ( V_13 ) ? 0 : ( int ) V_98 ;
}
static int F_62 ( struct V_39 * log ,
T_4 V_63 )
{
int V_13 ;
T_3 V_64 = V_63 ;
struct V_5 * V_6 = log -> V_58 ;
static unsigned long V_103 ;
struct {
T_5 V_104 ;
T_3 V_62 ;
} V_89 ;
T_2 V_12 = sizeof( V_89 ) ;
if ( V_63 < V_6 -> V_62 )
return 0 ;
else if ( F_63 ( V_103 , V_105 ) )
return 1 ;
V_103 = V_105 + ( V_18 / 4 ) ;
V_13 = F_5 ( V_6 , V_6 -> V_7 , V_106 ,
( char * ) & V_64 , sizeof( V_64 ) ,
( char * ) & V_89 , & V_12 ) ;
if ( V_13 )
return 1 ;
V_6 -> V_62 = V_89 . V_62 ;
return ( int ) V_89 . V_104 ;
}
static int T_7 F_64 ( void )
{
int V_13 = 0 ;
V_84 = F_65 ( 100 , F_1 ,
F_3 , NULL ) ;
if ( ! V_84 ) {
F_10 ( L_25 ) ;
return - V_31 ;
}
V_13 = F_66 () ;
if ( V_13 ) {
F_10 ( L_26 ) ;
F_67 ( V_84 ) ;
return V_13 ;
}
V_13 = F_68 ( & V_107 ) ;
if ( V_13 ) {
F_10 ( L_27 ) ;
F_69 () ;
F_67 ( V_84 ) ;
return V_13 ;
}
F_11 ( L_28 V_108 L_29 ) ;
return 0 ;
}
static void T_8 F_70 ( void )
{
F_71 ( & V_107 ) ;
F_69 () ;
F_67 ( V_84 ) ;
F_11 ( L_28 V_108 L_30 ) ;
return;
}

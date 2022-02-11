static int F_1 ( struct V_1 * V_2 , const char * V_3 ,
int V_4 , char * V_5 , T_1 V_6 ,
char * V_7 , T_1 * V_8 )
{
int V_9 ;
V_10:
V_9 = F_2 ( V_3 , V_2 -> V_11 , V_4 , V_5 ,
V_6 , V_7 , V_8 ) ;
if ( V_9 != - V_12 )
return V_9 ;
F_3 ( L_1 ) ;
while ( 1 ) {
F_4 ( V_13 ) ;
F_5 ( 2 * V_14 ) ;
F_6 ( L_2 ) ;
V_9 = F_2 ( V_3 , V_2 -> V_11 , V_15 ,
V_2 -> V_16 ,
strlen ( V_2 -> V_16 ) + 1 ,
NULL , NULL ) ;
if ( ! V_9 )
break;
}
F_7 ( L_3 ) ;
V_9 = F_2 ( V_3 , V_2 -> V_11 , V_17 , NULL ,
0 , NULL , NULL ) ;
if ( ! V_9 )
goto V_10;
F_3 ( L_4 , V_9 ) ;
return - V_12 ;
}
static int F_8 ( struct V_18 * V_19 ,
unsigned V_20 , char * * V_21 ,
char * * V_22 )
{
int V_23 , V_24 ;
char * V_25 = NULL ;
* V_22 = NULL ;
for ( V_23 = 0 , V_24 = 0 ; V_23 < V_20 ; V_23 ++ )
V_24 += strlen ( V_21 [ V_23 ] ) + 1 ;
V_24 += 20 ;
V_25 = F_9 ( V_24 , V_26 ) ;
if ( ! V_25 ) {
F_6 ( L_5 ) ;
return - V_27 ;
}
V_24 = sprintf ( V_25 , L_6 , ( unsigned long long ) V_19 -> V_28 ) ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ )
V_24 += sprintf ( V_25 + V_24 , L_7 , V_21 [ V_23 ] ) ;
* V_22 = V_25 ;
return V_24 ;
}
static void F_10 ( struct V_29 * V_30 )
{
int V_9 ;
struct V_1 * V_2 = F_11 ( V_30 , struct V_1 , V_31 . V_30 ) ;
F_12 ( & V_2 -> V_32 , 0 ) ;
V_9 = F_1 ( V_2 , V_2 -> V_3 , V_33 , NULL , 0 , NULL , NULL ) ;
if ( V_9 )
F_13 ( V_2 -> V_19 -> V_34 ) ;
}
static int F_14 ( struct V_35 * log , struct V_18 * V_19 ,
unsigned V_20 , char * * V_21 )
{
int V_9 = 0 ;
int V_24 ;
char * V_22 = NULL ;
struct V_1 * V_2 = NULL ;
T_2 V_7 ;
T_1 V_8 = sizeof( V_7 ) ;
char * V_36 = NULL ;
T_1 V_37 = V_38 ;
if ( V_20 < 3 ) {
F_6 ( L_8 ) ;
return - V_39 ;
}
V_2 = F_9 ( sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 ) {
F_6 ( L_9 ) ;
return - V_27 ;
}
V_2 -> V_11 = ( unsigned long ) V_2 ;
V_2 -> V_19 = V_19 ;
if ( strlen ( V_21 [ 0 ] ) > ( V_40 - 1 ) ) {
F_6 ( L_10 ) ;
F_15 ( V_2 ) ;
return - V_39 ;
}
V_2 -> V_41 = V_20 ;
strncpy ( V_2 -> V_3 , V_21 [ 0 ] , V_40 ) ;
V_20 -- ;
V_21 ++ ;
F_16 ( & V_2 -> V_42 ) ;
F_17 ( & V_2 -> V_43 ) ;
F_17 ( & V_2 -> V_44 ) ;
if ( ! strcasecmp ( V_21 [ 0 ] , L_11 ) ) {
V_2 -> V_45 = 1 ;
V_20 -- ;
V_21 ++ ;
}
V_24 = F_8 ( V_19 , V_20 , V_21 , & V_22 ) ;
if ( V_24 < 0 ) {
F_15 ( V_2 ) ;
return V_24 ;
}
V_36 = F_9 ( V_37 , V_26 ) ;
if ( ! V_36 ) {
F_3 ( L_12 ) ;
V_9 = - V_27 ;
goto V_46;
}
V_2 -> V_47 = F_18 ( V_48 ,
V_49 ) ;
if ( ! V_2 -> V_47 ) {
F_3 ( L_13 ) ;
V_9 = - V_27 ;
goto V_46;
}
V_9 = F_2 ( V_2 -> V_3 , V_2 -> V_11 , V_15 ,
V_22 , V_24 ,
V_36 , & V_37 ) ;
if ( V_9 < 0 ) {
if ( V_9 == - V_12 )
F_3 ( L_14 ) ;
else
F_3 ( L_15 ) ;
goto V_46;
}
V_8 = sizeof( V_7 ) ;
V_9 = F_2 ( V_2 -> V_3 , V_2 -> V_11 , V_50 ,
NULL , 0 , ( char * ) & V_7 , & V_8 ) ;
if ( V_9 ) {
F_3 ( L_16 ) ;
goto V_46;
}
V_2 -> V_51 = ( V_52 ) V_7 ;
V_2 -> V_53 = F_19 ( V_19 -> V_28 , V_2 -> V_51 ) ;
if ( V_37 ) {
if ( V_36 [ V_37 - 1 ] != '\0' ) {
F_3 ( L_17 ) ;
V_9 = - V_39 ;
goto V_46;
}
V_9 = F_20 ( V_19 , V_36 ,
F_21 ( V_19 -> V_34 ) , & V_2 -> V_54 ) ;
if ( V_9 )
F_3 ( L_18 ,
V_36 ) ;
}
if ( V_2 -> V_45 ) {
V_2 -> V_55 = F_22 ( L_19 , V_56 , 0 ) ;
if ( ! V_2 -> V_55 ) {
F_3 ( L_20 ) ;
V_9 = - V_27 ;
goto V_46;
}
F_23 ( & V_2 -> V_31 , F_10 ) ;
F_12 ( & V_2 -> V_32 , 0 ) ;
}
V_46:
F_15 ( V_36 ) ;
if ( V_9 ) {
if ( V_2 -> V_47 )
F_24 ( V_2 -> V_47 ) ;
F_15 ( V_2 ) ;
F_15 ( V_22 ) ;
} else {
V_2 -> V_16 = V_22 ;
log -> V_57 = V_2 ;
}
return V_9 ;
}
static void F_25 ( struct V_35 * log )
{
struct V_1 * V_2 = log -> V_57 ;
if ( V_2 -> V_45 ) {
if ( F_26 ( & V_2 -> V_32 ) )
F_27 ( & V_2 -> V_31 ) ;
F_28 ( V_2 -> V_55 ) ;
}
( void ) F_2 ( V_2 -> V_3 , V_2 -> V_11 , V_58 ,
NULL , 0 , NULL , NULL ) ;
if ( V_2 -> V_54 )
F_29 ( V_2 -> V_19 , V_2 -> V_54 ) ;
F_24 ( V_2 -> V_47 ) ;
F_15 ( V_2 -> V_16 ) ;
F_15 ( V_2 ) ;
return;
}
static int F_30 ( struct V_35 * log )
{
int V_9 ;
struct V_1 * V_2 = log -> V_57 ;
V_9 = F_2 ( V_2 -> V_3 , V_2 -> V_11 , V_59 ,
NULL , 0 , NULL , NULL ) ;
return V_9 ;
}
static int F_31 ( struct V_35 * log )
{
int V_9 ;
struct V_1 * V_2 = log -> V_57 ;
if ( V_2 -> V_45 && F_26 ( & V_2 -> V_32 ) )
F_27 ( & V_2 -> V_31 ) ;
V_9 = F_2 ( V_2 -> V_3 , V_2 -> V_11 , V_60 ,
NULL , 0 , NULL , NULL ) ;
return V_9 ;
}
static int F_32 ( struct V_35 * log )
{
int V_9 ;
struct V_1 * V_2 = log -> V_57 ;
V_2 -> V_61 = 0 ;
V_9 = F_2 ( V_2 -> V_3 , V_2 -> V_11 , V_17 ,
NULL , 0 , NULL , NULL ) ;
return V_9 ;
}
static V_52 F_33 ( struct V_35 * log )
{
struct V_1 * V_2 = log -> V_57 ;
return V_2 -> V_51 ;
}
static int F_34 ( struct V_35 * log , T_3 V_62 )
{
int V_9 ;
T_2 V_63 = ( T_2 ) V_62 ;
T_4 V_64 ;
T_1 V_8 ;
struct V_1 * V_2 = log -> V_57 ;
V_8 = sizeof( V_64 ) ;
V_9 = F_1 ( V_2 , V_2 -> V_3 , V_65 ,
( char * ) & V_63 , sizeof( V_63 ) ,
( char * ) & V_64 , & V_8 ) ;
return ( V_9 ) ? 0 : ( int ) V_64 ;
}
static int F_35 ( struct V_35 * log , T_3 V_62 ,
int V_66 )
{
int V_9 ;
T_2 V_63 = V_62 ;
T_4 V_67 ;
T_1 V_8 ;
struct V_1 * V_2 = log -> V_57 ;
if ( ! V_66 )
return - V_68 ;
V_8 = sizeof( V_67 ) ;
V_9 = F_1 ( V_2 , V_2 -> V_3 , V_69 ,
( char * ) & V_63 , sizeof( V_63 ) ,
( char * ) & V_67 , & V_8 ) ;
return ( V_9 ) ? 0 : ( int ) V_67 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_70 * V_71 )
{
int V_9 = 0 ;
struct V_72 * V_73 ;
F_37 (fe, flush_list, list) {
V_9 = F_1 ( V_2 , V_2 -> V_3 , V_73 -> type ,
( char * ) & V_73 -> V_62 ,
sizeof( V_73 -> V_62 ) ,
NULL , NULL ) ;
if ( V_9 )
break;
}
return V_9 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_70 * V_71 ,
int V_74 )
{
int V_9 = 0 ;
int V_75 ;
V_52 type = 0 ;
struct V_72 * V_73 , * V_76 ;
F_39 ( V_77 ) ;
T_2 V_78 [ V_79 ] ;
while ( ! F_40 ( V_71 ) ) {
V_75 = 0 ;
F_41 (fe, tmp_fe, flush_list, list) {
V_78 [ V_75 ] = V_73 -> V_62 ;
V_75 ++ ;
F_42 ( & V_73 -> V_80 , & V_77 ) ;
type = V_73 -> type ;
if ( V_75 >= V_79 )
break;
}
if ( V_74 ) {
V_9 = F_1 ( V_2 , V_2 -> V_3 , V_33 ,
( char * ) ( V_78 ) ,
V_75 * sizeof( T_2 ) ,
NULL , NULL ) ;
if ( V_9 )
break;
} else {
V_9 = F_1 ( V_2 , V_2 -> V_3 , type ,
( char * ) ( V_78 ) ,
V_75 * sizeof( T_2 ) ,
NULL , NULL ) ;
if ( V_9 ) {
F_43 ( & V_77 , V_71 ) ;
V_9 = F_36 ( V_2 , V_71 ) ;
break;
}
}
}
F_43 ( & V_77 , V_71 ) ;
return V_9 ;
}
static int F_44 ( struct V_35 * log )
{
int V_9 = 0 ;
unsigned long V_81 ;
struct V_1 * V_2 = log -> V_57 ;
F_39 ( V_43 ) ;
F_39 ( V_44 ) ;
int V_82 ;
int V_83 ;
struct V_72 * V_73 , * V_76 ;
T_5 * V_47 = V_2 -> V_47 ;
F_45 ( & V_2 -> V_42 , V_81 ) ;
F_43 ( & V_2 -> V_43 , & V_43 ) ;
F_43 ( & V_2 -> V_44 , & V_44 ) ;
F_46 ( & V_2 -> V_42 , V_81 ) ;
V_82 = F_40 ( & V_43 ) ;
V_83 = F_40 ( & V_44 ) ;
if ( V_82 && V_83 )
return 0 ;
V_9 = F_38 ( V_2 , & V_44 , 0 ) ;
if ( V_9 )
goto V_46;
if ( ! V_2 -> V_45 ) {
V_9 = F_38 ( V_2 , & V_43 , 0 ) ;
if ( V_9 )
goto V_46;
V_9 = F_1 ( V_2 , V_2 -> V_3 , V_33 ,
NULL , 0 , NULL , NULL ) ;
goto V_46;
}
V_9 = F_38 ( V_2 , & V_43 , 1 ) ;
if ( V_9 )
goto V_46;
if ( V_82 && ! F_26 ( & V_2 -> V_32 ) ) {
F_47 ( V_2 -> V_55 , & V_2 -> V_31 , 3 * V_14 ) ;
F_12 ( & V_2 -> V_32 , 1 ) ;
} else {
F_48 ( & V_2 -> V_31 ) ;
F_12 ( & V_2 -> V_32 , 0 ) ;
}
V_46:
F_41 (fe, tmp_fe, &mark_list, list) {
F_49 ( & V_73 -> V_80 ) ;
F_50 ( V_73 , V_47 ) ;
}
F_41 (fe, tmp_fe, &clear_list, list) {
F_49 ( & V_73 -> V_80 ) ;
F_50 ( V_73 , V_47 ) ;
}
if ( V_9 )
F_13 ( V_2 -> V_19 -> V_34 ) ;
return V_9 ;
}
static void F_51 ( struct V_35 * log , T_3 V_62 )
{
unsigned long V_81 ;
struct V_1 * V_2 = log -> V_57 ;
struct V_72 * V_73 ;
V_73 = F_52 ( V_2 -> V_47 , V_84 ) ;
F_53 ( ! V_73 ) ;
F_45 ( & V_2 -> V_42 , V_81 ) ;
V_73 -> type = V_85 ;
V_73 -> V_62 = V_62 ;
F_54 ( & V_73 -> V_80 , & V_2 -> V_43 ) ;
F_46 ( & V_2 -> V_42 , V_81 ) ;
return;
}
static void F_55 ( struct V_35 * log , T_3 V_62 )
{
unsigned long V_81 ;
struct V_1 * V_2 = log -> V_57 ;
struct V_72 * V_73 ;
V_73 = F_52 ( V_2 -> V_47 , V_86 ) ;
if ( ! V_73 ) {
F_3 ( L_21 ) ;
return;
}
F_45 ( & V_2 -> V_42 , V_81 ) ;
V_73 -> type = V_87 ;
V_73 -> V_62 = V_62 ;
F_54 ( & V_73 -> V_80 , & V_2 -> V_44 ) ;
F_46 ( & V_2 -> V_42 , V_81 ) ;
return;
}
static int F_56 ( struct V_35 * log , T_3 * V_62 )
{
int V_9 ;
T_1 V_8 ;
struct V_1 * V_2 = log -> V_57 ;
struct {
T_4 V_23 ;
T_3 V_9 ;
} V_88 ;
if ( V_2 -> V_61 >= V_2 -> V_53 )
return 0 ;
V_8 = sizeof( V_88 ) ;
V_9 = F_1 ( V_2 , V_2 -> V_3 , V_89 ,
NULL , 0 , ( char * ) & V_88 , & V_8 ) ;
* V_62 = V_88 . V_9 ;
return ( V_9 ) ? V_9 : ( int ) V_88 . V_23 ;
}
static void F_57 ( struct V_35 * log ,
T_3 V_62 , int V_67 )
{
struct V_1 * V_2 = log -> V_57 ;
struct {
T_3 V_9 ;
T_4 V_23 ;
} V_88 ;
V_88 . V_9 = V_62 ;
V_88 . V_23 = ( T_4 ) V_67 ;
( void ) F_1 ( V_2 , V_2 -> V_3 , V_90 ,
( char * ) & V_88 , sizeof( V_88 ) , NULL , NULL ) ;
return;
}
static T_3 F_58 ( struct V_35 * log )
{
int V_9 ;
T_1 V_8 ;
T_2 V_91 ;
struct V_1 * V_2 = log -> V_57 ;
V_8 = sizeof( V_91 ) ;
V_9 = F_1 ( V_2 , V_2 -> V_3 , V_92 ,
NULL , 0 , ( char * ) & V_91 , & V_8 ) ;
if ( V_9 )
return 0 ;
if ( V_91 >= V_2 -> V_53 )
V_2 -> V_61 = V_2 -> V_53 ;
return ( T_3 ) V_91 ;
}
static int F_59 ( struct V_35 * log , T_6 V_93 ,
char * V_94 , unsigned V_95 )
{
int V_9 = 0 ;
char * V_96 ;
T_1 V_97 = ( T_1 ) V_95 ;
struct V_1 * V_2 = log -> V_57 ;
switch ( V_93 ) {
case V_98 :
V_9 = F_1 ( V_2 , V_2 -> V_3 , V_99 ,
NULL , 0 , V_94 , & V_97 ) ;
if ( V_9 ) {
V_97 = 0 ;
F_60 ( L_22 , log -> type -> V_100 ) ;
}
break;
case V_101 :
V_97 = 0 ;
V_96 = strchr ( V_2 -> V_16 , ' ' ) ;
F_53 ( ! V_96 ) ;
V_96 ++ ;
F_60 ( L_23 , log -> type -> V_100 , V_2 -> V_41 , V_2 -> V_3 ) ;
if ( V_2 -> V_45 )
F_60 ( L_24 ) ;
F_60 ( L_25 , V_96 ) ;
break;
}
return ( V_9 ) ? 0 : ( int ) V_97 ;
}
static int F_61 ( struct V_35 * log ,
T_3 V_62 )
{
int V_9 ;
T_2 V_63 = V_62 ;
struct V_1 * V_2 = log -> V_57 ;
static unsigned long V_102 ;
struct {
T_4 V_103 ;
T_2 V_61 ;
} V_88 ;
T_1 V_8 = sizeof( V_88 ) ;
if ( V_62 < V_2 -> V_61 )
return 0 ;
else if ( F_62 ( V_102 , V_104 ) )
return 1 ;
V_102 = V_104 + ( V_14 / 4 ) ;
V_9 = F_1 ( V_2 , V_2 -> V_3 , V_105 ,
( char * ) & V_63 , sizeof( V_63 ) ,
( char * ) & V_88 , & V_8 ) ;
if ( V_9 )
return 1 ;
V_2 -> V_61 = V_88 . V_61 ;
return ( int ) V_88 . V_103 ;
}
static int T_7 F_63 ( void )
{
int V_9 = 0 ;
V_49 = F_64 ( V_72 , 0 ) ;
if ( ! V_49 ) {
F_6 ( L_26 ) ;
return - V_27 ;
}
V_9 = F_65 () ;
if ( V_9 ) {
F_6 ( L_27 ) ;
F_66 ( V_49 ) ;
return V_9 ;
}
V_9 = F_67 ( & V_106 ) ;
if ( V_9 ) {
F_6 ( L_28 ) ;
F_68 () ;
F_66 ( V_49 ) ;
return V_9 ;
}
F_7 ( L_29 V_107 L_30 ) ;
return 0 ;
}
static void T_8 F_69 ( void )
{
F_70 ( & V_106 ) ;
F_68 () ;
F_66 ( V_49 ) ;
F_7 ( L_29 V_107 L_31 ) ;
return;
}

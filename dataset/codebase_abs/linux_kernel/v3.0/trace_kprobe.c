static inline void * F_1 ( T_1 * V_1 )
{
return ( V_2 * ) V_1 + F_2 ( * V_1 ) ;
}
static inline void * F_3 ( T_1 * V_1 , void * V_3 )
{
return ( V_2 * ) V_3 + F_2 ( * V_1 ) ;
}
static T_2 int T_3 (string)( struct V_4 * V_5 ,
const char * V_6 ,
void * V_7 , void * V_3 )
{
int V_8 = * ( T_1 * ) V_7 >> 16 ;
if ( ! V_8 )
return F_4 ( V_5 , L_1 , V_6 ) ;
else
return F_4 ( V_5 , L_2 , V_6 ,
( const char * ) F_3 ( V_7 , V_3 ) ) ;
}
static T_2 void F_5 ( struct V_9 * V_10 ,
struct V_11 * V_12 , void * V_13 )
{
return V_10 -> V_14 ( V_12 , V_10 -> V_7 , V_13 ) ;
}
static unsigned long F_6 ( struct V_15 * V_16 )
{
V_16 -> V_17 = ( unsigned long ) F_7 ( V_16 -> V_18 ) ;
if ( V_16 -> V_17 )
V_16 -> V_17 += V_16 -> V_19 ;
return V_16 -> V_17 ;
}
static void F_8 ( struct V_15 * V_16 )
{
F_9 ( V_16 -> V_18 ) ;
F_9 ( V_16 ) ;
}
static struct V_15 * F_10 ( const char * V_20 , long V_19 )
{
struct V_15 * V_16 ;
if ( ! V_20 || strlen ( V_20 ) == 0 )
return NULL ;
V_16 = F_11 ( sizeof( struct V_15 ) , V_21 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_18 = F_12 ( V_20 , V_21 ) ;
if ( ! V_16 -> V_18 ) {
F_9 ( V_16 ) ;
return NULL ;
}
V_16 -> V_19 = V_19 ;
F_6 ( V_16 ) ;
return V_16 ;
}
static T_2 void F_13 ( struct V_22 * V_7 )
{
if ( F_14 ( V_23 , V_7 -> V_24 . V_14 ) )
F_13 ( V_7 -> V_24 . V_7 ) ;
else if ( F_14 ( V_18 , V_7 -> V_24 . V_14 ) )
F_8 ( V_7 -> V_24 . V_7 ) ;
F_9 ( V_7 ) ;
}
static T_2 void
F_15 ( struct V_25 * V_7 )
{
if ( F_14 ( V_23 , V_7 -> V_24 . V_14 ) )
F_13 ( V_7 -> V_24 . V_7 ) ;
else if ( F_14 ( V_18 , V_7 -> V_24 . V_14 ) )
F_8 ( V_7 -> V_24 . V_7 ) ;
F_9 ( V_7 ) ;
}
static const struct V_26 * F_16 ( const char * type )
{
int V_27 ;
if ( ! type )
type = V_28 ;
if ( * type == 'b' ) {
unsigned long V_29 ;
type = strchr ( type , '/' ) ;
if ( ! type )
goto V_30;
type ++ ;
if ( F_17 ( type , 0 , & V_29 ) )
goto V_30;
switch ( V_29 ) {
case 8 :
return F_16 ( L_3 ) ;
case 16 :
return F_16 ( L_4 ) ;
case 32 :
return F_16 ( L_5 ) ;
case 64 :
return F_16 ( L_6 ) ;
default:
goto V_30;
}
}
for ( V_27 = 0 ; V_27 < F_18 ( V_31 ) ; V_27 ++ )
if ( strcmp ( type , V_31 [ V_27 ] . V_6 ) == 0 )
return & V_31 [ V_27 ] ;
V_30:
return NULL ;
}
static T_2 void F_19 ( struct V_11 * V_12 ,
void * V_32 , void * V_13 )
{
* ( unsigned long * ) V_13 = F_20 ( V_12 ) ;
}
static T_4 F_21 ( const struct V_26 * type ,
T_4 V_33 )
{
int V_27 ;
if ( type != & V_31 [ V_34 ] )
return NULL ;
for ( V_27 = 0 ; V_27 < V_35 ; V_27 ++ )
if ( type -> V_36 [ V_27 ] == V_33 )
return V_31 [ V_37 ] . V_36 [ V_27 ] ;
F_22 ( 1 ) ;
return NULL ;
}
static T_2 int F_23 ( struct V_38 * V_39 )
{
return V_39 -> V_40 . V_41 != NULL ;
}
static T_2 const char * F_24 ( struct V_38 * V_39 )
{
return V_39 -> V_18 ? V_39 -> V_18 : L_7 ;
}
static int F_25 ( const char * V_6 )
{
if ( ! isalpha ( * V_6 ) && * V_6 != '_' )
return 0 ;
while ( * ++ V_6 != '\0' ) {
if ( ! isalpha ( * V_6 ) && ! isdigit ( * V_6 ) && * V_6 != '_' )
return 0 ;
}
return 1 ;
}
static struct V_38 * F_26 ( const char * V_42 ,
const char * V_43 ,
void * V_17 ,
const char * V_18 ,
unsigned long V_44 ,
int V_45 , int V_46 )
{
struct V_38 * V_39 ;
int V_47 = - V_48 ;
V_39 = F_11 ( F_27 ( V_45 ) , V_21 ) ;
if ( ! V_39 )
return F_28 ( V_47 ) ;
if ( V_18 ) {
V_39 -> V_18 = F_12 ( V_18 , V_21 ) ;
if ( ! V_39 -> V_18 )
goto error;
V_39 -> V_40 . V_49 . V_50 = V_39 -> V_18 ;
V_39 -> V_40 . V_49 . V_19 = V_44 ;
} else
V_39 -> V_40 . V_49 . V_17 = V_17 ;
if ( V_46 )
V_39 -> V_40 . V_41 = V_51 ;
else
V_39 -> V_40 . V_49 . V_52 = V_53 ;
if ( ! V_43 || ! F_25 ( V_43 ) ) {
V_47 = - V_54 ;
goto error;
}
V_39 -> V_55 . V_56 = & V_39 -> V_56 ;
V_39 -> V_55 . V_6 = F_12 ( V_43 , V_21 ) ;
if ( ! V_39 -> V_55 . V_6 )
goto error;
if ( ! V_42 || ! F_25 ( V_42 ) ) {
V_47 = - V_54 ;
goto error;
}
V_39 -> V_56 . system = F_12 ( V_42 , V_21 ) ;
if ( ! V_39 -> V_56 . system )
goto error;
F_29 ( & V_39 -> V_57 ) ;
return V_39 ;
error:
F_9 ( V_39 -> V_55 . V_6 ) ;
F_9 ( V_39 -> V_18 ) ;
F_9 ( V_39 ) ;
return F_28 ( V_47 ) ;
}
static void F_30 ( struct V_58 * V_59 )
{
if ( F_14 ( V_60 , V_59 -> V_36 . V_14 ) )
F_15 ( V_59 -> V_36 . V_7 ) ;
else if ( F_14 ( V_23 , V_59 -> V_36 . V_14 ) )
F_13 ( V_59 -> V_36 . V_7 ) ;
else if ( F_14 ( V_18 , V_59 -> V_36 . V_14 ) )
F_8 ( V_59 -> V_36 . V_7 ) ;
F_9 ( V_59 -> V_6 ) ;
F_9 ( V_59 -> V_61 ) ;
}
static void F_31 ( struct V_38 * V_39 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_39 -> V_62 ; V_27 ++ )
F_30 ( & V_39 -> args [ V_27 ] ) ;
F_9 ( V_39 -> V_55 . V_56 -> system ) ;
F_9 ( V_39 -> V_55 . V_6 ) ;
F_9 ( V_39 -> V_18 ) ;
F_9 ( V_39 ) ;
}
static struct V_38 * F_32 ( const char * V_43 ,
const char * V_42 )
{
struct V_38 * V_39 ;
F_33 (tp, &probe_list, list)
if ( strcmp ( V_39 -> V_55 . V_6 , V_43 ) == 0 &&
strcmp ( V_39 -> V_55 . V_56 -> system , V_42 ) == 0 )
return V_39 ;
return NULL ;
}
static void F_34 ( struct V_38 * V_39 )
{
if ( F_23 ( V_39 ) )
F_35 ( & V_39 -> V_40 ) ;
else
F_36 ( & V_39 -> V_40 . V_49 ) ;
F_37 ( & V_39 -> V_57 ) ;
F_38 ( V_39 ) ;
}
static int F_39 ( struct V_38 * V_39 )
{
struct V_38 * V_63 ;
int V_47 ;
F_40 ( & V_64 ) ;
V_63 = F_32 ( V_39 -> V_55 . V_6 , V_39 -> V_55 . V_56 -> system ) ;
if ( V_63 ) {
F_34 ( V_63 ) ;
F_31 ( V_63 ) ;
}
V_47 = F_41 ( V_39 ) ;
if ( V_47 ) {
F_42 ( L_8 , V_47 ) ;
goto V_65;
}
V_39 -> V_40 . V_49 . V_66 |= V_67 ;
if ( F_23 ( V_39 ) )
V_47 = F_43 ( & V_39 -> V_40 ) ;
else
V_47 = F_44 ( & V_39 -> V_40 . V_49 ) ;
if ( V_47 ) {
F_42 ( L_9 , V_47 ) ;
if ( V_47 == - V_68 ) {
F_42 ( L_10
L_11 ,
V_39 -> V_40 . V_49 . V_17 ) ;
V_47 = - V_54 ;
}
F_38 ( V_39 ) ;
} else
F_45 ( & V_39 -> V_57 , & V_69 ) ;
V_65:
F_46 ( & V_64 ) ;
return V_47 ;
}
static int F_47 ( char * V_18 , unsigned long * V_19 )
{
char * V_70 ;
int V_47 ;
if ( ! V_19 )
return - V_54 ;
V_70 = strchr ( V_18 , '+' ) ;
if ( V_70 ) {
V_47 = F_17 ( V_70 + 1 , 0 , V_19 ) ;
if ( V_47 )
return V_47 ;
* V_70 = '\0' ;
} else
* V_19 = 0 ;
return 0 ;
}
static int F_48 ( char * V_59 , const struct V_26 * V_71 ,
struct V_9 * V_72 , int V_46 )
{
int V_47 = 0 ;
unsigned long V_73 ;
if ( strcmp ( V_59 , L_12 ) == 0 ) {
if ( V_46 )
V_72 -> V_14 = V_71 -> V_36 [ V_74 ] ;
else
V_47 = - V_54 ;
} else if ( strncmp ( V_59 , L_13 , 5 ) == 0 ) {
if ( V_59 [ 5 ] == '\0' ) {
if ( strcmp ( V_71 -> V_6 , V_28 ) == 0 )
V_72 -> V_14 = F_19 ;
else
V_47 = - V_54 ;
} else if ( isdigit ( V_59 [ 5 ] ) ) {
V_47 = F_17 ( V_59 + 5 , 10 , & V_73 ) ;
if ( V_47 || V_73 > V_75 )
V_47 = - V_54 ;
else {
V_72 -> V_14 = V_71 -> V_36 [ V_76 ] ;
V_72 -> V_7 = ( void * ) V_73 ;
}
} else
V_47 = - V_54 ;
} else
V_47 = - V_54 ;
return V_47 ;
}
static int F_49 ( char * V_59 , const struct V_26 * V_71 ,
struct V_9 * V_72 , int V_46 )
{
int V_47 = 0 ;
unsigned long V_73 ;
long V_19 ;
char * V_70 ;
switch ( V_59 [ 0 ] ) {
case '$' :
V_47 = F_48 ( V_59 + 1 , V_71 , V_72 , V_46 ) ;
break;
case '%' :
V_47 = F_50 ( V_59 + 1 ) ;
if ( V_47 >= 0 ) {
V_72 -> V_14 = V_71 -> V_36 [ V_77 ] ;
V_72 -> V_7 = ( void * ) ( unsigned long ) V_47 ;
V_47 = 0 ;
}
break;
case '@' :
if ( isdigit ( V_59 [ 1 ] ) ) {
V_47 = F_17 ( V_59 + 1 , 0 , & V_73 ) ;
if ( V_47 )
break;
V_72 -> V_14 = V_71 -> V_36 [ V_78 ] ;
V_72 -> V_7 = ( void * ) V_73 ;
} else {
V_47 = F_47 ( V_59 + 1 , & V_19 ) ;
if ( V_47 )
break;
V_72 -> V_7 = F_10 ( V_59 + 1 , V_19 ) ;
if ( V_72 -> V_7 )
V_72 -> V_14 = V_71 -> V_36 [ V_79 ] ;
}
break;
case '+' :
V_59 ++ ;
case '-' :
V_70 = strchr ( V_59 , '(' ) ;
if ( ! V_70 )
break;
* V_70 = '\0' ;
V_47 = F_51 ( V_59 , 0 , & V_19 ) ;
if ( V_47 )
break;
V_59 = V_70 + 1 ;
V_70 = strrchr ( V_59 , ')' ) ;
if ( V_70 ) {
struct V_22 * V_80 ;
const struct V_26 * V_81 = F_16 ( NULL ) ;
* V_70 = '\0' ;
V_80 = F_11 ( sizeof( struct V_22 ) ,
V_21 ) ;
if ( ! V_80 )
return - V_48 ;
V_80 -> V_19 = V_19 ;
V_47 = F_49 ( V_59 , V_81 , & V_80 -> V_24 ,
V_46 ) ;
if ( V_47 )
F_9 ( V_80 ) ;
else {
V_72 -> V_14 = V_71 -> V_36 [ V_82 ] ;
V_72 -> V_7 = ( void * ) V_80 ;
}
}
break;
}
if ( ! V_47 && ! V_72 -> V_14 ) {
F_52 ( L_14 ,
V_71 -> V_6 ) ;
V_47 = - V_54 ;
}
return V_47 ;
}
static int F_53 ( const char * V_83 ,
const struct V_26 * V_71 ,
struct V_9 * V_72 )
{
struct V_25 * V_84 ;
unsigned long V_85 , V_86 ;
char * V_87 ;
if ( * V_83 != 'b' )
return 0 ;
V_84 = F_11 ( sizeof( * V_84 ) , V_21 ) ;
if ( ! V_84 )
return - V_48 ;
V_84 -> V_24 = * V_72 ;
V_72 -> V_14 = V_71 -> V_36 [ V_88 ] ;
V_72 -> V_7 = ( void * ) V_84 ;
V_85 = F_54 ( V_83 + 1 , & V_87 , 0 ) ;
if ( V_85 == 0 || * V_87 != '@' )
return - V_54 ;
V_83 = V_87 + 1 ;
V_86 = F_54 ( V_83 , & V_87 , 0 ) ;
if ( V_87 == V_83 || * V_87 != '/' )
return - V_54 ;
V_84 -> V_89 = F_55 ( V_71 -> V_90 ) - ( V_85 + V_86 ) ;
V_84 -> V_91 = V_84 -> V_89 + V_86 ;
return ( F_55 ( V_71 -> V_90 ) < ( V_85 + V_86 ) ) ? - V_54 : 0 ;
}
static int F_56 ( char * V_59 , struct V_38 * V_39 ,
struct V_58 * V_92 , int V_46 )
{
const char * V_71 ;
int V_47 ;
if ( strlen ( V_59 ) > V_93 ) {
F_52 ( L_15 , V_59 ) ;
return - V_94 ;
}
V_92 -> V_61 = F_12 ( V_59 , V_21 ) ;
if ( ! V_92 -> V_61 ) {
F_52 ( L_16 , V_59 ) ;
return - V_48 ;
}
V_71 = strchr ( V_92 -> V_61 , ':' ) ;
if ( V_71 ) {
V_59 [ V_71 - V_92 -> V_61 ] = '\0' ;
V_71 ++ ;
}
V_92 -> type = F_16 ( V_71 ) ;
if ( ! V_92 -> type ) {
F_52 ( L_17 , V_71 ) ;
return - V_54 ;
}
V_92 -> V_19 = V_39 -> V_90 ;
V_39 -> V_90 += V_92 -> type -> V_90 ;
V_47 = F_49 ( V_59 , V_92 -> type , & V_92 -> V_36 , V_46 ) ;
if ( V_47 >= 0 && V_71 != NULL )
V_47 = F_53 ( V_71 , V_92 -> type , & V_92 -> V_36 ) ;
if ( V_47 >= 0 ) {
V_92 -> V_95 . V_14 = F_21 ( V_92 -> type ,
V_92 -> V_36 . V_14 ) ;
V_92 -> V_95 . V_7 = V_92 -> V_36 . V_7 ;
}
return V_47 ;
}
static int F_57 ( const char * V_6 ,
struct V_58 * args , int V_96 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < F_18 ( V_97 ) ; V_27 ++ )
if ( strcmp ( V_97 [ V_27 ] , V_6 ) == 0 )
return 1 ;
for ( V_27 = 0 ; V_27 < V_96 ; V_27 ++ )
if ( strcmp ( args [ V_27 ] . V_6 , V_6 ) == 0 )
return 1 ;
return 0 ;
}
static int F_58 ( int V_98 , char * * V_99 )
{
struct V_38 * V_39 ;
int V_27 , V_47 = 0 ;
int V_46 = 0 , V_100 = 0 ;
char * V_18 = NULL , * V_43 = NULL , * V_42 = NULL ;
char * V_59 ;
unsigned long V_19 = 0 ;
void * V_17 = NULL ;
char V_101 [ V_102 ] ;
if ( V_99 [ 0 ] [ 0 ] == 'p' )
V_46 = 0 ;
else if ( V_99 [ 0 ] [ 0 ] == 'r' )
V_46 = 1 ;
else if ( V_99 [ 0 ] [ 0 ] == '-' )
V_100 = 1 ;
else {
F_52 ( L_18
L_19 ) ;
return - V_54 ;
}
if ( V_99 [ 0 ] [ 1 ] == ':' ) {
V_43 = & V_99 [ 0 ] [ 2 ] ;
if ( strchr ( V_43 , '/' ) ) {
V_42 = V_43 ;
V_43 = strchr ( V_42 , '/' ) + 1 ;
V_43 [ - 1 ] = '\0' ;
if ( strlen ( V_42 ) == 0 ) {
F_52 ( L_20 ) ;
return - V_54 ;
}
}
if ( strlen ( V_43 ) == 0 ) {
F_52 ( L_21 ) ;
return - V_54 ;
}
}
if ( ! V_42 )
V_42 = V_103 ;
if ( V_100 ) {
if ( ! V_43 ) {
F_52 ( L_22 ) ;
return - V_54 ;
}
F_40 ( & V_64 ) ;
V_39 = F_32 ( V_43 , V_42 ) ;
if ( ! V_39 ) {
F_46 ( & V_64 ) ;
F_52 ( L_23 , V_42 , V_43 ) ;
return - V_104 ;
}
F_34 ( V_39 ) ;
F_31 ( V_39 ) ;
F_46 ( & V_64 ) ;
return 0 ;
}
if ( V_98 < 2 ) {
F_52 ( L_24 ) ;
return - V_54 ;
}
if ( isdigit ( V_99 [ 1 ] [ 0 ] ) ) {
if ( V_46 ) {
F_52 ( L_25 ) ;
return - V_54 ;
}
V_47 = F_17 ( & V_99 [ 1 ] [ 0 ] , 0 , ( unsigned long * ) & V_17 ) ;
if ( V_47 ) {
F_52 ( L_26 ) ;
return V_47 ;
}
} else {
V_18 = V_99 [ 1 ] ;
V_47 = F_47 ( V_18 , & V_19 ) ;
if ( V_47 ) {
F_52 ( L_27 ) ;
return V_47 ;
}
if ( V_19 && V_46 ) {
F_52 ( L_28 ) ;
return - V_54 ;
}
}
V_98 -= 2 ; V_99 += 2 ;
if ( ! V_43 ) {
if ( V_18 )
snprintf ( V_101 , V_102 , L_29 ,
V_46 ? 'r' : 'p' , V_18 , V_19 ) ;
else
snprintf ( V_101 , V_102 , L_30 ,
V_46 ? 'r' : 'p' , V_17 ) ;
V_43 = V_101 ;
}
V_39 = F_26 ( V_42 , V_43 , V_17 , V_18 , V_19 , V_98 ,
V_46 ) ;
if ( F_59 ( V_39 ) ) {
F_52 ( L_31 ,
( int ) F_60 ( V_39 ) ) ;
return F_60 ( V_39 ) ;
}
V_47 = 0 ;
for ( V_27 = 0 ; V_27 < V_98 && V_27 < V_105 ; V_27 ++ ) {
V_39 -> V_62 ++ ;
V_59 = strchr ( V_99 [ V_27 ] , '=' ) ;
if ( V_59 ) {
* V_59 ++ = '\0' ;
V_39 -> args [ V_27 ] . V_6 = F_12 ( V_99 [ V_27 ] , V_21 ) ;
} else {
V_59 = V_99 [ V_27 ] ;
snprintf ( V_101 , V_102 , L_32 , V_27 + 1 ) ;
V_39 -> args [ V_27 ] . V_6 = F_12 ( V_101 , V_21 ) ;
}
if ( ! V_39 -> args [ V_27 ] . V_6 ) {
F_52 ( L_33 , V_27 ) ;
V_47 = - V_48 ;
goto error;
}
if ( ! F_25 ( V_39 -> args [ V_27 ] . V_6 ) ) {
F_52 ( L_34 ,
V_27 , V_39 -> args [ V_27 ] . V_6 ) ;
V_47 = - V_54 ;
goto error;
}
if ( F_57 ( V_39 -> args [ V_27 ] . V_6 , V_39 -> args , V_27 ) ) {
F_52 ( L_35
L_36 , V_27 , V_99 [ V_27 ] ) ;
V_47 = - V_54 ;
goto error;
}
V_47 = F_56 ( V_59 , V_39 , & V_39 -> args [ V_27 ] , V_46 ) ;
if ( V_47 ) {
F_52 ( L_37 , V_27 , V_47 ) ;
goto error;
}
}
V_47 = F_39 ( V_39 ) ;
if ( V_47 )
goto error;
return 0 ;
error:
F_31 ( V_39 ) ;
return V_47 ;
}
static void F_61 ( void )
{
struct V_38 * V_39 ;
F_40 ( & V_64 ) ;
while ( ! F_62 ( & V_69 ) ) {
V_39 = F_63 ( V_69 . V_106 , struct V_38 , V_57 ) ;
F_34 ( V_39 ) ;
F_31 ( V_39 ) ;
}
F_46 ( & V_64 ) ;
}
static void * F_64 ( struct V_107 * V_108 , T_5 * V_109 )
{
F_40 ( & V_64 ) ;
return F_65 ( & V_69 , * V_109 ) ;
}
static void * F_66 ( struct V_107 * V_108 , void * V_110 , T_5 * V_109 )
{
return F_67 ( V_110 , & V_69 , V_109 ) ;
}
static void F_68 ( struct V_107 * V_108 , void * V_110 )
{
F_46 ( & V_64 ) ;
}
static int F_69 ( struct V_107 * V_108 , void * V_110 )
{
struct V_38 * V_39 = V_110 ;
int V_27 ;
F_70 ( V_108 , L_38 , F_23 ( V_39 ) ? 'r' : 'p' ) ;
F_70 ( V_108 , L_39 , V_39 -> V_55 . V_56 -> system , V_39 -> V_55 . V_6 ) ;
if ( ! V_39 -> V_18 )
F_70 ( V_108 , L_40 , V_39 -> V_40 . V_49 . V_17 ) ;
else if ( V_39 -> V_40 . V_49 . V_19 )
F_70 ( V_108 , L_41 , F_24 ( V_39 ) , V_39 -> V_40 . V_49 . V_19 ) ;
else
F_70 ( V_108 , L_42 , F_24 ( V_39 ) ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_62 ; V_27 ++ )
F_70 ( V_108 , L_43 , V_39 -> args [ V_27 ] . V_6 , V_39 -> args [ V_27 ] . V_61 ) ;
F_70 ( V_108 , L_44 ) ;
return 0 ;
}
static int F_71 ( struct V_111 * V_111 , struct V_112 * V_112 )
{
if ( ( V_112 -> V_113 & V_114 ) &&
( V_112 -> V_115 & V_116 ) )
F_61 () ;
return F_72 ( V_112 , & V_117 ) ;
}
static int F_73 ( const char * V_101 )
{
char * * V_99 ;
int V_98 = 0 , V_47 = 0 ;
V_99 = F_74 ( V_21 , V_101 , & V_98 ) ;
if ( ! V_99 )
return - V_48 ;
if ( V_98 )
V_47 = F_58 ( V_98 , V_99 ) ;
F_75 ( V_99 ) ;
return V_47 ;
}
static T_6 F_76 ( struct V_112 * V_112 , const char T_7 * V_118 ,
T_8 V_119 , T_5 * V_120 )
{
char * V_121 , * V_70 ;
int V_47 ;
T_8 V_122 ;
T_8 V_90 ;
V_121 = F_77 ( V_123 , V_21 ) ;
if ( ! V_121 )
return - V_48 ;
V_47 = V_122 = 0 ;
while ( V_122 < V_119 ) {
V_90 = V_119 - V_122 ;
if ( V_90 >= V_123 )
V_90 = V_123 - 1 ;
if ( F_78 ( V_121 , V_118 + V_122 , V_90 ) ) {
V_47 = - V_124 ;
goto V_125;
}
V_121 [ V_90 ] = '\0' ;
V_70 = strchr ( V_121 , '\n' ) ;
if ( V_70 ) {
* V_70 = '\0' ;
V_90 = V_70 - V_121 + 1 ;
} else if ( V_122 + V_90 < V_119 ) {
F_42 ( L_45
L_46 , V_123 ) ;
V_47 = - V_54 ;
goto V_125;
}
V_122 += V_90 ;
V_70 = strchr ( V_121 , '#' ) ;
if ( V_70 )
* V_70 = '\0' ;
V_47 = F_73 ( V_121 ) ;
if ( V_47 )
goto V_125;
}
V_47 = V_122 ;
V_125:
F_9 ( V_121 ) ;
return V_47 ;
}
static int F_79 ( struct V_107 * V_108 , void * V_110 )
{
struct V_38 * V_39 = V_110 ;
F_70 ( V_108 , L_47 , V_39 -> V_55 . V_6 , V_39 -> V_126 ,
V_39 -> V_40 . V_49 . V_127 ) ;
return 0 ;
}
static int F_80 ( struct V_111 * V_111 , struct V_112 * V_112 )
{
return F_72 ( V_112 , & V_128 ) ;
}
static T_2 int F_81 ( struct V_38 * V_39 ,
struct V_11 * V_12 )
{
int V_27 , V_47 = 0 ;
T_1 V_8 ;
for ( V_27 = 0 ; V_27 < V_39 -> V_62 ; V_27 ++ )
if ( F_82 ( V_39 -> args [ V_27 ] . V_95 . V_14 ) ) {
F_5 ( & V_39 -> args [ V_27 ] . V_95 , V_12 , & V_8 ) ;
V_47 += V_8 ;
}
return V_47 ;
}
static T_2 void F_83 ( int V_129 , struct V_38 * V_39 ,
struct V_11 * V_12 ,
V_2 * V_7 , int V_130 )
{
int V_27 ;
T_1 V_65 = V_39 -> V_90 ;
T_1 * V_1 ;
for ( V_27 = 0 ; V_27 < V_39 -> V_62 ; V_27 ++ ) {
if ( F_82 ( V_39 -> args [ V_27 ] . V_95 . V_14 ) ) {
V_1 = ( T_1 * ) ( V_7 + V_39 -> args [ V_27 ] . V_19 ) ;
* V_1 = F_84 ( V_130 , V_65 - V_39 -> args [ V_27 ] . V_19 ) ;
F_5 ( & V_39 -> args [ V_27 ] . V_36 , V_12 , V_1 ) ;
V_65 += F_85 ( * V_1 ) ;
V_130 -= F_85 ( * V_1 ) ;
* V_1 = F_86 ( * V_1 ,
V_129 + V_39 -> args [ V_27 ] . V_19 ) ;
} else
F_5 ( & V_39 -> args [ V_27 ] . V_36 , V_12 ,
V_7 + V_39 -> args [ V_27 ] . V_19 ) ;
}
}
static T_2 void F_87 ( struct V_131 * V_49 , struct V_11 * V_12 )
{
struct V_38 * V_39 = F_88 ( V_49 , struct V_38 , V_40 . V_49 ) ;
struct V_132 * V_133 ;
struct V_134 * V_43 ;
struct V_135 * V_118 ;
int V_90 , V_136 , V_137 ;
unsigned long V_138 ;
struct V_139 * V_55 = & V_39 -> V_55 ;
V_39 -> V_126 ++ ;
F_89 ( V_138 ) ;
V_137 = F_90 () ;
V_136 = F_81 ( V_39 , V_12 ) ;
V_90 = sizeof( * V_133 ) + V_39 -> V_90 + V_136 ;
V_43 = F_91 ( & V_118 , V_55 -> V_43 . type ,
V_90 , V_138 , V_137 ) ;
if ( ! V_43 )
return;
V_133 = F_92 ( V_43 ) ;
V_133 -> V_140 = ( unsigned long ) V_49 -> V_17 ;
F_83 ( sizeof( * V_133 ) , V_39 , V_12 , ( V_2 * ) & V_133 [ 1 ] , V_136 ) ;
if ( ! F_93 ( V_118 , V_55 , V_133 , V_43 ) )
F_94 ( V_118 , V_43 , V_138 , V_137 ) ;
}
static T_2 void F_95 ( struct V_141 * V_142 ,
struct V_11 * V_12 )
{
struct V_38 * V_39 = F_88 ( V_142 -> V_40 , struct V_38 , V_40 ) ;
struct V_143 * V_133 ;
struct V_134 * V_43 ;
struct V_135 * V_118 ;
int V_90 , V_137 , V_136 ;
unsigned long V_138 ;
struct V_139 * V_55 = & V_39 -> V_55 ;
F_89 ( V_138 ) ;
V_137 = F_90 () ;
V_136 = F_81 ( V_39 , V_12 ) ;
V_90 = sizeof( * V_133 ) + V_39 -> V_90 + V_136 ;
V_43 = F_91 ( & V_118 , V_55 -> V_43 . type ,
V_90 , V_138 , V_137 ) ;
if ( ! V_43 )
return;
V_133 = F_92 ( V_43 ) ;
V_133 -> V_144 = ( unsigned long ) V_39 -> V_40 . V_49 . V_17 ;
V_133 -> V_145 = ( unsigned long ) V_142 -> V_146 ;
F_83 ( sizeof( * V_133 ) , V_39 , V_12 , ( V_2 * ) & V_133 [ 1 ] , V_136 ) ;
if ( ! F_93 ( V_118 , V_55 , V_133 , V_43 ) )
F_94 ( V_118 , V_43 , V_138 , V_137 ) ;
}
enum V_147
F_96 ( struct V_148 * V_149 , int V_66 ,
struct V_150 * V_43 )
{
struct V_132 * V_151 ;
struct V_4 * V_5 = & V_149 -> V_152 ;
struct V_38 * V_39 ;
V_2 * V_7 ;
int V_27 ;
V_151 = (struct V_132 * ) V_149 -> V_3 ;
V_39 = F_88 ( V_43 , struct V_38 , V_55 . V_43 ) ;
if ( ! F_4 ( V_5 , L_48 , V_39 -> V_55 . V_6 ) )
goto V_153;
if ( ! F_97 ( V_5 , V_151 -> V_140 , V_66 | V_154 ) )
goto V_153;
if ( ! F_98 ( V_5 , L_49 ) )
goto V_153;
V_7 = ( V_2 * ) & V_151 [ 1 ] ;
for ( V_27 = 0 ; V_27 < V_39 -> V_62 ; V_27 ++ )
if ( ! V_39 -> args [ V_27 ] . type -> V_155 ( V_5 , V_39 -> args [ V_27 ] . V_6 ,
V_7 + V_39 -> args [ V_27 ] . V_19 , V_151 ) )
goto V_153;
if ( ! F_98 ( V_5 , L_44 ) )
goto V_153;
return V_156 ;
V_153:
return V_157 ;
}
enum V_147
F_99 ( struct V_148 * V_149 , int V_66 ,
struct V_150 * V_43 )
{
struct V_143 * V_151 ;
struct V_4 * V_5 = & V_149 -> V_152 ;
struct V_38 * V_39 ;
V_2 * V_7 ;
int V_27 ;
V_151 = (struct V_143 * ) V_149 -> V_3 ;
V_39 = F_88 ( V_43 , struct V_38 , V_55 . V_43 ) ;
if ( ! F_4 ( V_5 , L_48 , V_39 -> V_55 . V_6 ) )
goto V_153;
if ( ! F_97 ( V_5 , V_151 -> V_145 , V_66 | V_154 ) )
goto V_153;
if ( ! F_98 ( V_5 , L_50 ) )
goto V_153;
if ( ! F_97 ( V_5 , V_151 -> V_144 , V_66 & ~ V_154 ) )
goto V_153;
if ( ! F_98 ( V_5 , L_49 ) )
goto V_153;
V_7 = ( V_2 * ) & V_151 [ 1 ] ;
for ( V_27 = 0 ; V_27 < V_39 -> V_62 ; V_27 ++ )
if ( ! V_39 -> args [ V_27 ] . type -> V_155 ( V_5 , V_39 -> args [ V_27 ] . V_6 ,
V_7 + V_39 -> args [ V_27 ] . V_19 , V_151 ) )
goto V_153;
if ( ! F_98 ( V_5 , L_44 ) )
goto V_153;
return V_156 ;
V_153:
return V_157 ;
}
static int F_100 ( struct V_139 * V_55 )
{
struct V_38 * V_39 = (struct V_38 * ) V_55 -> V_7 ;
V_39 -> V_66 |= V_158 ;
if ( F_23 ( V_39 ) )
return F_101 ( & V_39 -> V_40 ) ;
else
return F_102 ( & V_39 -> V_40 . V_49 ) ;
}
static void F_103 ( struct V_139 * V_55 )
{
struct V_38 * V_39 = (struct V_38 * ) V_55 -> V_7 ;
V_39 -> V_66 &= ~ V_158 ;
if ( ! ( V_39 -> V_66 & ( V_158 | V_159 ) ) ) {
if ( F_23 ( V_39 ) )
F_104 ( & V_39 -> V_40 ) ;
else
F_105 ( & V_39 -> V_40 . V_49 ) ;
}
}
static int F_106 ( struct V_139 * V_160 )
{
int V_47 , V_27 ;
struct V_132 V_151 ;
struct V_38 * V_39 = (struct V_38 * ) V_160 -> V_7 ;
F_107 (unsigned long, ip, FIELD_STRING_IP, 0 ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_62 ; V_27 ++ ) {
V_47 = F_108 ( V_160 , V_39 -> args [ V_27 ] . type -> V_161 ,
V_39 -> args [ V_27 ] . V_6 ,
sizeof( V_151 ) + V_39 -> args [ V_27 ] . V_19 ,
V_39 -> args [ V_27 ] . type -> V_90 ,
V_39 -> args [ V_27 ] . type -> V_162 ,
V_163 ) ;
if ( V_47 )
return V_47 ;
}
return 0 ;
}
static int F_109 ( struct V_139 * V_160 )
{
int V_47 , V_27 ;
struct V_143 V_151 ;
struct V_38 * V_39 = (struct V_38 * ) V_160 -> V_7 ;
F_107 (unsigned long, func, FIELD_STRING_FUNC, 0 ) ;
F_107 (unsigned long, ret_ip, FIELD_STRING_RETIP, 0 ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_62 ; V_27 ++ ) {
V_47 = F_108 ( V_160 , V_39 -> args [ V_27 ] . type -> V_161 ,
V_39 -> args [ V_27 ] . V_6 ,
sizeof( V_151 ) + V_39 -> args [ V_27 ] . V_19 ,
V_39 -> args [ V_27 ] . type -> V_90 ,
V_39 -> args [ V_27 ] . type -> V_162 ,
V_163 ) ;
if ( V_47 )
return V_47 ;
}
return 0 ;
}
static int F_110 ( struct V_38 * V_39 , char * V_101 , int V_8 )
{
int V_27 ;
int V_109 = 0 ;
const char * V_164 , * V_59 ;
if ( ! F_23 ( V_39 ) ) {
V_164 = L_51 ;
V_59 = L_52 V_165 ;
} else {
V_164 = L_53 ;
V_59 = L_52 V_166 L_54 V_167 ;
}
#define F_111 (len ? len - pos : 0)
V_109 += snprintf ( V_101 + V_109 , F_111 , L_55 , V_164 ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_62 ; V_27 ++ ) {
V_109 += snprintf ( V_101 + V_109 , F_111 , L_43 ,
V_39 -> args [ V_27 ] . V_6 , V_39 -> args [ V_27 ] . type -> V_164 ) ;
}
V_109 += snprintf ( V_101 + V_109 , F_111 , L_56 , V_59 ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_62 ; V_27 ++ ) {
if ( strcmp ( V_39 -> args [ V_27 ] . type -> V_6 , L_57 ) == 0 )
V_109 += snprintf ( V_101 + V_109 , F_111 ,
L_58 ,
V_39 -> args [ V_27 ] . V_6 ) ;
else
V_109 += snprintf ( V_101 + V_109 , F_111 , L_59 ,
V_39 -> args [ V_27 ] . V_6 ) ;
}
#undef F_111
return V_109 ;
}
static int F_112 ( struct V_38 * V_39 )
{
int V_8 ;
char * V_168 ;
V_8 = F_110 ( V_39 , NULL , 0 ) ;
V_168 = F_77 ( V_8 + 1 , V_21 ) ;
if ( ! V_168 )
return - V_48 ;
F_110 ( V_39 , V_168 , V_8 + 1 ) ;
V_39 -> V_55 . V_168 = V_168 ;
return 0 ;
}
static T_2 void F_113 ( struct V_131 * V_49 ,
struct V_11 * V_12 )
{
struct V_38 * V_39 = F_88 ( V_49 , struct V_38 , V_40 . V_49 ) ;
struct V_139 * V_55 = & V_39 -> V_55 ;
struct V_132 * V_133 ;
struct V_169 * V_170 ;
int V_90 , V_171 , V_136 ;
int V_172 ;
V_136 = F_81 ( V_39 , V_12 ) ;
V_171 = sizeof( * V_133 ) + V_39 -> V_90 + V_136 ;
V_90 = F_114 ( V_171 + sizeof( T_1 ) , sizeof( V_173 ) ) ;
V_90 -= sizeof( T_1 ) ;
if ( F_115 ( V_90 > V_174 ,
L_60 ) )
return;
V_133 = F_116 ( V_90 , V_55 -> V_43 . type , V_12 , & V_172 ) ;
if ( ! V_133 )
return;
V_133 -> V_140 = ( unsigned long ) V_49 -> V_17 ;
memset ( & V_133 [ 1 ] , 0 , V_136 ) ;
F_83 ( sizeof( * V_133 ) , V_39 , V_12 , ( V_2 * ) & V_133 [ 1 ] , V_136 ) ;
V_170 = F_117 ( V_55 -> V_175 ) ;
F_118 ( V_133 , V_90 , V_172 , V_133 -> V_140 , 1 , V_12 , V_170 ) ;
}
static T_2 void F_119 ( struct V_141 * V_142 ,
struct V_11 * V_12 )
{
struct V_38 * V_39 = F_88 ( V_142 -> V_40 , struct V_38 , V_40 ) ;
struct V_139 * V_55 = & V_39 -> V_55 ;
struct V_143 * V_133 ;
struct V_169 * V_170 ;
int V_90 , V_171 , V_136 ;
int V_172 ;
V_136 = F_81 ( V_39 , V_12 ) ;
V_171 = sizeof( * V_133 ) + V_39 -> V_90 + V_136 ;
V_90 = F_114 ( V_171 + sizeof( T_1 ) , sizeof( V_173 ) ) ;
V_90 -= sizeof( T_1 ) ;
if ( F_115 ( V_90 > V_174 ,
L_60 ) )
return;
V_133 = F_116 ( V_90 , V_55 -> V_43 . type , V_12 , & V_172 ) ;
if ( ! V_133 )
return;
V_133 -> V_144 = ( unsigned long ) V_39 -> V_40 . V_49 . V_17 ;
V_133 -> V_145 = ( unsigned long ) V_142 -> V_146 ;
F_83 ( sizeof( * V_133 ) , V_39 , V_12 , ( V_2 * ) & V_133 [ 1 ] , V_136 ) ;
V_170 = F_117 ( V_55 -> V_175 ) ;
F_118 ( V_133 , V_90 , V_172 , V_133 -> V_145 , 1 , V_12 , V_170 ) ;
}
static int F_120 ( struct V_139 * V_55 )
{
struct V_38 * V_39 = (struct V_38 * ) V_55 -> V_7 ;
V_39 -> V_66 |= V_159 ;
if ( F_23 ( V_39 ) )
return F_101 ( & V_39 -> V_40 ) ;
else
return F_102 ( & V_39 -> V_40 . V_49 ) ;
}
static void F_121 ( struct V_139 * V_55 )
{
struct V_38 * V_39 = (struct V_38 * ) V_55 -> V_7 ;
V_39 -> V_66 &= ~ V_159 ;
if ( ! ( V_39 -> V_66 & V_158 ) ) {
if ( F_23 ( V_39 ) )
F_104 ( & V_39 -> V_40 ) ;
else
F_105 ( & V_39 -> V_40 . V_49 ) ;
}
}
static T_2
int F_122 ( struct V_139 * V_43 , enum V_176 type )
{
switch ( type ) {
case V_177 :
return F_100 ( V_43 ) ;
case V_178 :
F_103 ( V_43 ) ;
return 0 ;
#ifdef F_123
case V_179 :
return F_120 ( V_43 ) ;
case V_180 :
F_121 ( V_43 ) ;
return 0 ;
#endif
}
return 0 ;
}
static T_2
int V_53 ( struct V_131 * V_49 , struct V_11 * V_12 )
{
struct V_38 * V_39 = F_88 ( V_49 , struct V_38 , V_40 . V_49 ) ;
if ( V_39 -> V_66 & V_158 )
F_87 ( V_49 , V_12 ) ;
#ifdef F_123
if ( V_39 -> V_66 & V_159 )
F_113 ( V_49 , V_12 ) ;
#endif
return 0 ;
}
static T_2
int V_51 ( struct V_141 * V_142 , struct V_11 * V_12 )
{
struct V_38 * V_39 = F_88 ( V_142 -> V_40 , struct V_38 , V_40 ) ;
if ( V_39 -> V_66 & V_158 )
F_95 ( V_142 , V_12 ) ;
#ifdef F_123
if ( V_39 -> V_66 & V_159 )
F_119 ( V_142 , V_12 ) ;
#endif
return 0 ;
}
static int F_41 ( struct V_38 * V_39 )
{
struct V_139 * V_55 = & V_39 -> V_55 ;
int V_47 ;
F_29 ( & V_55 -> V_56 -> V_181 ) ;
if ( F_23 ( V_39 ) ) {
V_55 -> V_43 . V_182 = & V_183 ;
V_55 -> V_56 -> V_184 = F_109 ;
} else {
V_55 -> V_43 . V_182 = & V_185 ;
V_55 -> V_56 -> V_184 = F_106 ;
}
if ( F_112 ( V_39 ) < 0 )
return - V_48 ;
V_47 = F_124 ( & V_55 -> V_43 ) ;
if ( ! V_47 ) {
F_9 ( V_55 -> V_168 ) ;
return - V_186 ;
}
V_55 -> V_66 = 0 ;
V_55 -> V_56 -> V_187 = F_122 ;
V_55 -> V_7 = V_39 ;
V_47 = F_125 ( V_55 ) ;
if ( V_47 ) {
F_52 ( L_61 , V_55 -> V_6 ) ;
F_9 ( V_55 -> V_168 ) ;
F_126 ( & V_55 -> V_43 ) ;
}
return V_47 ;
}
static void F_38 ( struct V_38 * V_39 )
{
F_127 ( & V_39 -> V_55 ) ;
F_9 ( V_39 -> V_55 . V_168 ) ;
}
static T_9 int F_128 ( void )
{
struct V_188 * V_189 ;
struct V_188 * V_133 ;
V_189 = F_129 () ;
if ( ! V_189 )
return 0 ;
V_133 = F_130 ( L_62 , 0644 , V_189 ,
NULL , & V_190 ) ;
if ( ! V_133 )
F_42 ( L_63
L_64 ) ;
V_133 = F_130 ( L_65 , 0444 , V_189 ,
NULL , & V_191 ) ;
if ( ! V_133 )
F_42 ( L_63
L_66 ) ;
return 0 ;
}
static T_10 int F_131 ( int V_192 , int V_193 , int V_194 ,
int V_195 , int V_196 , int V_197 )
{
return V_192 + V_193 + V_194 + V_195 + V_196 + V_197 ;
}
static T_9 int F_132 ( void )
{
int V_47 , V_198 = 0 ;
int (* F_133)( int , int , int , int , int , int );
struct V_38 * V_39 ;
F_133 = F_131 ;
F_52 ( L_67 ) ;
V_47 = F_73 ( L_68
L_69 ) ;
if ( F_134 ( V_47 ) ) {
F_42 ( L_70 ) ;
V_198 ++ ;
} else {
V_39 = F_32 ( L_71 , V_103 ) ;
if ( F_134 ( V_39 == NULL ) ) {
F_42 ( L_72 ) ;
V_198 ++ ;
} else
F_100 ( & V_39 -> V_55 ) ;
}
V_47 = F_73 ( L_73
L_74 ) ;
if ( F_134 ( V_47 ) ) {
F_42 ( L_75 ) ;
V_198 ++ ;
} else {
V_39 = F_32 ( L_76 , V_103 ) ;
if ( F_134 ( V_39 == NULL ) ) {
F_42 ( L_72 ) ;
V_198 ++ ;
} else
F_100 ( & V_39 -> V_55 ) ;
}
if ( V_198 )
goto V_65;
V_47 = F_133 ( 1 , 2 , 3 , 4 , 5 , 6 ) ;
V_47 = F_73 ( L_77 ) ;
if ( F_134 ( V_47 ) ) {
F_42 ( L_78 ) ;
V_198 ++ ;
}
V_47 = F_73 ( L_79 ) ;
if ( F_134 ( V_47 ) ) {
F_42 ( L_78 ) ;
V_198 ++ ;
}
V_65:
F_61 () ;
if ( V_198 )
F_135 ( L_80 ) ;
else
F_135 ( L_81 ) ;
return 0 ;
}

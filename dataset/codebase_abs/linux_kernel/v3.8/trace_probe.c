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
static unsigned long F_5 ( struct V_9 * V_10 )
{
V_10 -> V_11 = ( unsigned long ) F_6 ( V_10 -> V_12 ) ;
if ( V_10 -> V_11 )
V_10 -> V_11 += V_10 -> V_13 ;
return V_10 -> V_11 ;
}
static void F_7 ( struct V_9 * V_10 )
{
F_8 ( V_10 -> V_12 ) ;
F_8 ( V_10 ) ;
}
static struct V_9 * F_9 ( const char * V_14 , long V_13 )
{
struct V_9 * V_10 ;
if ( ! V_14 || strlen ( V_14 ) == 0 )
return NULL ;
V_10 = F_10 ( sizeof( struct V_9 ) , V_15 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_12 = F_11 ( V_14 , V_15 ) ;
if ( ! V_10 -> V_12 ) {
F_8 ( V_10 ) ;
return NULL ;
}
V_10 -> V_13 = V_13 ;
F_5 ( V_10 ) ;
return V_10 ;
}
static T_2 void F_12 ( struct V_16 * V_7 )
{
if ( F_13 ( V_17 , V_7 -> V_18 . V_19 ) )
F_12 ( V_7 -> V_18 . V_7 ) ;
else if ( F_13 ( V_12 , V_7 -> V_18 . V_19 ) )
F_5 ( V_7 -> V_18 . V_7 ) ;
}
static T_2 void F_14 ( struct V_16 * V_7 )
{
if ( F_13 ( V_17 , V_7 -> V_18 . V_19 ) )
F_14 ( V_7 -> V_18 . V_7 ) ;
else if ( F_13 ( V_12 , V_7 -> V_18 . V_19 ) )
F_7 ( V_7 -> V_18 . V_7 ) ;
F_8 ( V_7 ) ;
}
static T_2 void
F_15 ( struct V_20 * V_7 )
{
if ( F_13 ( V_17 , V_7 -> V_18 . V_19 ) )
F_12 ( V_7 -> V_18 . V_7 ) ;
else if ( F_13 ( V_12 , V_7 -> V_18 . V_19 ) )
F_5 ( V_7 -> V_18 . V_7 ) ;
}
static T_2 void
F_16 ( struct V_20 * V_7 )
{
if ( F_13 ( V_17 , V_7 -> V_18 . V_19 ) )
F_14 ( V_7 -> V_18 . V_7 ) ;
else if ( F_13 ( V_12 , V_7 -> V_18 . V_19 ) )
F_7 ( V_7 -> V_18 . V_7 ) ;
F_8 ( V_7 ) ;
}
static const struct V_21 * F_17 ( const char * type )
{
int V_22 ;
if ( ! type )
type = V_23 ;
if ( * type == 'b' ) {
unsigned long V_24 ;
type = strchr ( type , '/' ) ;
if ( ! type )
goto V_25;
type ++ ;
if ( F_18 ( type , 0 , & V_24 ) )
goto V_25;
switch ( V_24 ) {
case 8 :
return F_17 ( L_3 ) ;
case 16 :
return F_17 ( L_4 ) ;
case 32 :
return F_17 ( L_5 ) ;
case 64 :
return F_17 ( L_6 ) ;
default:
goto V_25;
}
}
for ( V_22 = 0 ; V_22 < F_19 ( V_26 ) ; V_22 ++ )
if ( strcmp ( type , V_26 [ V_22 ] . V_6 ) == 0 )
return & V_26 [ V_22 ] ;
V_25:
return NULL ;
}
static T_2 void F_20 ( struct V_27 * V_28 ,
void * V_29 , void * V_30 )
{
* ( unsigned long * ) V_30 = F_21 ( V_28 ) ;
}
static T_4 F_22 ( const struct V_21 * type ,
T_4 V_31 )
{
int V_22 ;
if ( type != & V_26 [ V_32 ] )
return NULL ;
for ( V_22 = 0 ; V_22 < V_33 ; V_22 ++ )
if ( type -> V_34 [ V_22 ] == V_31 )
return V_26 [ V_35 ] . V_34 [ V_22 ] ;
F_23 ( 1 ) ;
return NULL ;
}
int F_24 ( char * V_12 , unsigned long * V_13 )
{
char * V_36 ;
int V_37 ;
if ( ! V_13 )
return - V_38 ;
V_36 = strchr ( V_12 , '+' ) ;
if ( V_36 ) {
V_37 = F_18 ( V_36 + 1 , 0 , V_13 ) ;
if ( V_37 )
return V_37 ;
* V_36 = '\0' ;
} else
* V_13 = 0 ;
return 0 ;
}
static int F_25 ( char * V_39 , const struct V_21 * V_40 ,
struct V_41 * V_42 , bool V_43 )
{
int V_37 = 0 ;
unsigned long V_44 ;
if ( strcmp ( V_39 , L_7 ) == 0 ) {
if ( V_43 )
V_42 -> V_19 = V_40 -> V_34 [ V_45 ] ;
else
V_37 = - V_38 ;
} else if ( strncmp ( V_39 , L_8 , 5 ) == 0 ) {
if ( V_39 [ 5 ] == '\0' ) {
if ( strcmp ( V_40 -> V_6 , V_23 ) == 0 )
V_42 -> V_19 = F_20 ;
else
V_37 = - V_38 ;
} else if ( isdigit ( V_39 [ 5 ] ) ) {
V_37 = F_18 ( V_39 + 5 , 10 , & V_44 ) ;
if ( V_37 || V_44 > V_46 )
V_37 = - V_38 ;
else {
V_42 -> V_19 = V_40 -> V_34 [ V_47 ] ;
V_42 -> V_7 = ( void * ) V_44 ;
}
} else
V_37 = - V_38 ;
} else
V_37 = - V_38 ;
return V_37 ;
}
static int F_26 ( char * V_39 , const struct V_21 * V_40 ,
struct V_41 * V_42 , bool V_43 , bool V_48 )
{
unsigned long V_44 ;
long V_13 ;
char * V_36 ;
int V_37 ;
V_37 = 0 ;
if ( ! V_48 && V_39 [ 0 ] != '%' )
return - V_38 ;
switch ( V_39 [ 0 ] ) {
case '$' :
V_37 = F_25 ( V_39 + 1 , V_40 , V_42 , V_43 ) ;
break;
case '%' :
V_37 = F_27 ( V_39 + 1 ) ;
if ( V_37 >= 0 ) {
V_42 -> V_19 = V_40 -> V_34 [ V_49 ] ;
V_42 -> V_7 = ( void * ) ( unsigned long ) V_37 ;
V_37 = 0 ;
}
break;
case '@' :
if ( isdigit ( V_39 [ 1 ] ) ) {
V_37 = F_18 ( V_39 + 1 , 0 , & V_44 ) ;
if ( V_37 )
break;
V_42 -> V_19 = V_40 -> V_34 [ V_50 ] ;
V_42 -> V_7 = ( void * ) V_44 ;
} else {
V_37 = F_24 ( V_39 + 1 , & V_13 ) ;
if ( V_37 )
break;
V_42 -> V_7 = F_9 ( V_39 + 1 , V_13 ) ;
if ( V_42 -> V_7 )
V_42 -> V_19 = V_40 -> V_34 [ V_51 ] ;
}
break;
case '+' :
V_39 ++ ;
case '-' :
V_36 = strchr ( V_39 , '(' ) ;
if ( ! V_36 )
break;
* V_36 = '\0' ;
V_37 = F_28 ( V_39 , 0 , & V_13 ) ;
if ( V_37 )
break;
V_39 = V_36 + 1 ;
V_36 = strrchr ( V_39 , ')' ) ;
if ( V_36 ) {
struct V_16 * V_52 ;
const struct V_21 * V_53 ;
V_53 = F_17 ( NULL ) ;
* V_36 = '\0' ;
V_52 = F_10 ( sizeof( struct V_16 ) , V_15 ) ;
if ( ! V_52 )
return - V_54 ;
V_52 -> V_13 = V_13 ;
V_37 = F_26 ( V_39 , V_53 , & V_52 -> V_18 , V_43 ,
V_48 ) ;
if ( V_37 )
F_8 ( V_52 ) ;
else {
V_42 -> V_19 = V_40 -> V_34 [ V_55 ] ;
V_42 -> V_7 = ( void * ) V_52 ;
}
}
break;
}
if ( ! V_37 && ! V_42 -> V_19 ) {
F_29 ( L_9 , V_40 -> V_6 ) ;
V_37 = - V_38 ;
}
return V_37 ;
}
static int F_30 ( const char * V_56 ,
const struct V_21 * V_40 ,
struct V_41 * V_42 )
{
struct V_20 * V_57 ;
unsigned long V_58 , V_59 ;
char * V_60 ;
if ( * V_56 != 'b' )
return 0 ;
V_57 = F_10 ( sizeof( * V_57 ) , V_15 ) ;
if ( ! V_57 )
return - V_54 ;
V_57 -> V_18 = * V_42 ;
V_42 -> V_19 = V_40 -> V_34 [ V_61 ] ;
V_42 -> V_7 = ( void * ) V_57 ;
V_58 = F_31 ( V_56 + 1 , & V_60 , 0 ) ;
if ( V_58 == 0 || * V_60 != '@' )
return - V_38 ;
V_56 = V_60 + 1 ;
V_59 = F_31 ( V_56 , & V_60 , 0 ) ;
if ( V_60 == V_56 || * V_60 != '/' )
return - V_38 ;
V_57 -> V_62 = F_32 ( V_40 -> V_63 ) - ( V_58 + V_59 ) ;
V_57 -> V_64 = V_57 -> V_62 + V_59 ;
return ( F_32 ( V_40 -> V_63 ) < ( V_58 + V_59 ) ) ? - V_38 : 0 ;
}
int F_33 ( char * V_39 , T_5 * V_63 ,
struct V_65 * V_66 , bool V_43 , bool V_48 )
{
const char * V_40 ;
int V_37 ;
if ( strlen ( V_39 ) > V_67 ) {
F_29 ( L_10 , V_39 ) ;
return - V_68 ;
}
V_66 -> V_69 = F_11 ( V_39 , V_15 ) ;
if ( ! V_66 -> V_69 ) {
F_29 ( L_11 , V_39 ) ;
return - V_54 ;
}
V_40 = strchr ( V_66 -> V_69 , ':' ) ;
if ( V_40 ) {
V_39 [ V_40 - V_66 -> V_69 ] = '\0' ;
V_40 ++ ;
}
V_66 -> type = F_17 ( V_40 ) ;
if ( ! V_66 -> type ) {
F_29 ( L_12 , V_40 ) ;
return - V_38 ;
}
V_66 -> V_13 = * V_63 ;
* V_63 += V_66 -> type -> V_63 ;
V_37 = F_26 ( V_39 , V_66 -> type , & V_66 -> V_34 , V_43 , V_48 ) ;
if ( V_37 >= 0 && V_40 != NULL )
V_37 = F_30 ( V_40 , V_66 -> type , & V_66 -> V_34 ) ;
if ( V_37 >= 0 ) {
V_66 -> V_70 . V_19 = F_22 ( V_66 -> type ,
V_66 -> V_34 . V_19 ) ;
V_66 -> V_70 . V_7 = V_66 -> V_34 . V_7 ;
}
return V_37 ;
}
int F_34 ( const char * V_6 ,
struct V_65 * args , int V_71 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < F_19 ( V_72 ) ; V_22 ++ )
if ( strcmp ( V_72 [ V_22 ] , V_6 ) == 0 )
return 1 ;
for ( V_22 = 0 ; V_22 < V_71 ; V_22 ++ )
if ( strcmp ( args [ V_22 ] . V_6 , V_6 ) == 0 )
return 1 ;
return 0 ;
}
void F_35 ( struct V_65 * V_39 )
{
if ( F_13 ( V_73 , V_39 -> V_34 . V_19 ) )
F_15 ( V_39 -> V_34 . V_7 ) ;
else if ( F_13 ( V_17 , V_39 -> V_34 . V_19 ) )
F_12 ( V_39 -> V_34 . V_7 ) ;
else if ( F_13 ( V_12 , V_39 -> V_34 . V_19 ) )
F_5 ( V_39 -> V_34 . V_7 ) ;
}
void F_36 ( struct V_65 * V_39 )
{
if ( F_13 ( V_73 , V_39 -> V_34 . V_19 ) )
F_16 ( V_39 -> V_34 . V_7 ) ;
else if ( F_13 ( V_17 , V_39 -> V_34 . V_19 ) )
F_14 ( V_39 -> V_34 . V_7 ) ;
else if ( F_13 ( V_12 , V_39 -> V_34 . V_19 ) )
F_7 ( V_39 -> V_34 . V_7 ) ;
F_8 ( V_39 -> V_6 ) ;
F_8 ( V_39 -> V_69 ) ;
}
int F_37 ( const char * V_74 , int (* F_38)( int , char * * ) )
{
char * * V_75 ;
int V_76 , V_37 ;
V_76 = 0 ;
V_37 = 0 ;
V_75 = F_39 ( V_15 , V_74 , & V_76 ) ;
if ( ! V_75 )
return - V_54 ;
if ( V_76 )
V_37 = F_38 ( V_76 , V_75 ) ;
F_40 ( V_75 ) ;
return V_37 ;
}
T_5 F_41 ( struct V_77 * V_77 , const char T_6 * V_78 ,
T_7 V_79 , T_8 * V_80 ,
int (* F_38)( int , char * * ) )
{
char * V_81 , * V_36 ;
int V_37 = 0 ;
T_7 V_82 = 0 ;
T_7 V_63 ;
V_81 = F_42 ( V_83 , V_15 ) ;
if ( ! V_81 )
return - V_54 ;
while ( V_82 < V_79 ) {
V_63 = V_79 - V_82 ;
if ( V_63 >= V_83 )
V_63 = V_83 - 1 ;
if ( F_43 ( V_81 , V_78 + V_82 , V_63 ) ) {
V_37 = - V_84 ;
goto V_85;
}
V_81 [ V_63 ] = '\0' ;
V_36 = strchr ( V_81 , '\n' ) ;
if ( V_36 ) {
* V_36 = '\0' ;
V_63 = V_36 - V_81 + 1 ;
} else if ( V_82 + V_63 < V_79 ) {
F_44 ( L_13
L_14 , V_83 ) ;
V_37 = - V_38 ;
goto V_85;
}
V_82 += V_63 ;
V_36 = strchr ( V_81 , '#' ) ;
if ( V_36 )
* V_36 = '\0' ;
V_37 = F_37 ( V_81 , F_38 ) ;
if ( V_37 )
goto V_85;
}
V_37 = V_82 ;
V_85:
F_8 ( V_81 ) ;
return V_37 ;
}

int T_1 (string)( struct V_1 * V_2 , const char * V_3 ,
void * V_4 , void * V_5 )
{
int V_6 = * ( V_7 * ) V_4 >> 16 ;
if ( ! V_6 )
F_1 ( V_2 , L_1 , V_3 ) ;
else
F_1 ( V_2 , L_2 , V_3 ,
( const char * ) F_2 ( V_4 , V_5 ) ) ;
return ! F_3 ( V_2 ) ;
}
static void F_4 ( struct V_8 * V_4 )
{
if ( F_5 ( V_9 , V_4 -> V_10 . V_11 ) )
F_4 ( V_4 -> V_10 . V_4 ) ;
else if ( F_5 ( V_12 , V_4 -> V_10 . V_11 ) )
F_6 ( V_4 -> V_10 . V_4 ) ;
}
static void F_7 ( struct V_8 * V_4 )
{
if ( F_5 ( V_9 , V_4 -> V_10 . V_11 ) )
F_7 ( V_4 -> V_10 . V_4 ) ;
else if ( F_5 ( V_12 , V_4 -> V_10 . V_11 ) )
F_8 ( V_4 -> V_10 . V_4 ) ;
F_9 ( V_4 ) ;
}
static void
F_10 ( struct V_13 * V_4 )
{
if ( F_5 ( V_9 , V_4 -> V_10 . V_11 ) )
F_4 ( V_4 -> V_10 . V_4 ) ;
else if ( F_5 ( V_12 , V_4 -> V_10 . V_11 ) )
F_6 ( V_4 -> V_10 . V_4 ) ;
}
static void
F_11 ( struct V_13 * V_4 )
{
if ( F_5 ( V_9 , V_4 -> V_10 . V_11 ) )
F_7 ( V_4 -> V_10 . V_4 ) ;
else if ( F_5 ( V_12 , V_4 -> V_10 . V_11 ) )
F_8 ( V_4 -> V_10 . V_4 ) ;
F_9 ( V_4 ) ;
}
static const struct V_14 * F_12 ( const char * type ,
const struct V_14 * V_15 )
{
int V_16 ;
if ( ! type )
type = V_17 ;
if ( * type == 'b' ) {
unsigned long V_18 ;
type = strchr ( type , '/' ) ;
if ( ! type )
goto V_19;
type ++ ;
if ( F_13 ( type , 0 , & V_18 ) )
goto V_19;
switch ( V_18 ) {
case 8 :
return F_12 ( L_3 , V_15 ) ;
case 16 :
return F_12 ( L_4 , V_15 ) ;
case 32 :
return F_12 ( L_5 , V_15 ) ;
case 64 :
return F_12 ( L_6 , V_15 ) ;
default:
goto V_19;
}
}
for ( V_16 = 0 ; V_15 [ V_16 ] . V_3 ; V_16 ++ ) {
if ( strcmp ( type , V_15 [ V_16 ] . V_3 ) == 0 )
return & V_15 [ V_16 ] ;
}
V_19:
return NULL ;
}
static void F_14 ( struct V_20 * V_21 , void * V_22 , void * V_23 )
{
* ( unsigned long * ) V_23 = F_15 ( V_21 ) ;
}
static void F_16 ( struct V_20 * V_21 , void * V_22 , void * V_23 )
{
* ( unsigned long * ) V_23 = F_17 ( V_21 ) ;
}
static T_2 F_18 ( const struct V_14 * type ,
T_2 V_24 ,
const struct V_14 * V_15 )
{
int V_16 ;
if ( type != & V_15 [ V_25 ] )
return NULL ;
for ( V_16 = 0 ; V_16 < V_26 ; V_16 ++ )
if ( type -> V_27 [ V_16 ] == V_24 )
return V_15 [ V_28 ] . V_27 [ V_16 ] ;
F_19 ( 1 ) ;
return NULL ;
}
int F_20 ( char * V_12 , unsigned long * V_29 )
{
char * V_30 ;
int V_31 ;
if ( ! V_29 )
return - V_32 ;
V_30 = strchr ( V_12 , '+' ) ;
if ( V_30 ) {
V_31 = F_13 ( V_30 + 1 , 0 , V_29 ) ;
if ( V_31 )
return V_31 ;
* V_30 = '\0' ;
} else
* V_29 = 0 ;
return 0 ;
}
static int F_21 ( char * V_33 , const struct V_14 * V_34 ,
struct V_35 * V_36 , bool V_37 ,
bool V_38 )
{
int V_31 = 0 ;
unsigned long V_39 ;
if ( strcmp ( V_33 , L_7 ) == 0 ) {
if ( V_37 )
V_36 -> V_11 = V_34 -> V_27 [ V_40 ] ;
else
V_31 = - V_32 ;
} else if ( strncmp ( V_33 , L_8 , 5 ) == 0 ) {
if ( V_33 [ 5 ] == '\0' ) {
if ( strcmp ( V_34 -> V_3 , V_17 ) )
return - V_32 ;
if ( V_38 )
V_36 -> V_11 = F_14 ;
else
V_36 -> V_11 = F_16 ;
} else if ( isdigit ( V_33 [ 5 ] ) ) {
V_31 = F_13 ( V_33 + 5 , 10 , & V_39 ) ;
if ( V_31 || ( V_38 && V_39 > V_41 ) )
V_31 = - V_32 ;
else {
V_36 -> V_11 = V_34 -> V_27 [ V_42 ] ;
V_36 -> V_4 = ( void * ) V_39 ;
}
} else
V_31 = - V_32 ;
} else
V_31 = - V_32 ;
return V_31 ;
}
static int F_22 ( char * V_33 , const struct V_14 * V_34 ,
struct V_35 * V_36 , bool V_37 , bool V_38 ,
const struct V_14 * V_15 )
{
unsigned long V_39 ;
long V_29 ;
char * V_30 ;
int V_31 = 0 ;
switch ( V_33 [ 0 ] ) {
case '$' :
V_31 = F_21 ( V_33 + 1 , V_34 , V_36 , V_37 , V_38 ) ;
break;
case '%' :
V_31 = F_23 ( V_33 + 1 ) ;
if ( V_31 >= 0 ) {
V_36 -> V_11 = V_34 -> V_27 [ V_43 ] ;
V_36 -> V_4 = ( void * ) ( unsigned long ) V_31 ;
V_31 = 0 ;
}
break;
case '@' :
if ( isdigit ( V_33 [ 1 ] ) ) {
V_31 = F_13 ( V_33 + 1 , 0 , & V_39 ) ;
if ( V_31 )
break;
V_36 -> V_11 = V_34 -> V_27 [ V_44 ] ;
V_36 -> V_4 = ( void * ) V_39 ;
} else if ( V_33 [ 1 ] == '+' ) {
if ( V_38 )
return - V_32 ;
V_31 = F_24 ( V_33 + 2 , 0 , & V_29 ) ;
if ( V_31 )
break;
V_36 -> V_11 = V_34 -> V_27 [ V_45 ] ;
V_36 -> V_4 = ( void * ) V_29 ;
} else {
if ( ! V_38 )
return - V_32 ;
V_31 = F_20 ( V_33 + 1 , & V_29 ) ;
if ( V_31 )
break;
V_36 -> V_4 = F_25 ( V_33 + 1 , V_29 ) ;
if ( V_36 -> V_4 )
V_36 -> V_11 = V_34 -> V_27 [ V_46 ] ;
}
break;
case '+' :
V_33 ++ ;
case '-' :
V_30 = strchr ( V_33 , '(' ) ;
if ( ! V_30 )
break;
* V_30 = '\0' ;
V_31 = F_24 ( V_33 , 0 , & V_29 ) ;
if ( V_31 )
break;
V_33 = V_30 + 1 ;
V_30 = strrchr ( V_33 , ')' ) ;
if ( V_30 ) {
struct V_8 * V_47 ;
const struct V_14 * V_48 ;
V_48 = F_12 ( NULL , V_15 ) ;
* V_30 = '\0' ;
V_47 = F_26 ( sizeof( struct V_8 ) , V_49 ) ;
if ( ! V_47 )
return - V_50 ;
V_47 -> V_29 = V_29 ;
V_47 -> V_27 = V_34 -> V_27 [ V_44 ] ;
V_47 -> V_51 = F_18 ( V_34 ,
V_47 -> V_27 , V_15 ) ;
V_31 = F_22 ( V_33 , V_48 , & V_47 -> V_10 , V_37 ,
V_38 , V_15 ) ;
if ( V_31 )
F_9 ( V_47 ) ;
else {
V_36 -> V_11 = V_34 -> V_27 [ V_52 ] ;
V_36 -> V_4 = ( void * ) V_47 ;
}
}
break;
}
if ( ! V_31 && ! V_36 -> V_11 ) {
F_27 ( L_9 , V_34 -> V_3 ) ;
V_31 = - V_32 ;
}
return V_31 ;
}
static int F_28 ( const char * V_53 ,
const struct V_14 * V_34 ,
struct V_35 * V_36 )
{
struct V_13 * V_54 ;
unsigned long V_55 , V_56 ;
char * V_57 ;
if ( * V_53 != 'b' )
return 0 ;
V_54 = F_26 ( sizeof( * V_54 ) , V_49 ) ;
if ( ! V_54 )
return - V_50 ;
V_54 -> V_10 = * V_36 ;
V_36 -> V_11 = V_34 -> V_27 [ V_58 ] ;
V_36 -> V_4 = ( void * ) V_54 ;
V_55 = F_29 ( V_53 + 1 , & V_57 , 0 ) ;
if ( V_55 == 0 || * V_57 != '@' )
return - V_32 ;
V_53 = V_57 + 1 ;
V_56 = F_29 ( V_53 , & V_57 , 0 ) ;
if ( V_57 == V_53 || * V_57 != '/' )
return - V_32 ;
V_54 -> V_59 = F_30 ( V_34 -> V_60 ) - ( V_55 + V_56 ) ;
V_54 -> V_61 = V_54 -> V_59 + V_56 ;
return ( F_30 ( V_34 -> V_60 ) < ( V_55 + V_56 ) ) ? - V_32 : 0 ;
}
int F_31 ( char * V_33 , T_3 * V_60 ,
struct V_62 * V_63 , bool V_37 , bool V_38 ,
const struct V_14 * V_15 )
{
const char * V_34 ;
int V_31 ;
if ( strlen ( V_33 ) > V_64 ) {
F_27 ( L_10 , V_33 ) ;
return - V_65 ;
}
V_63 -> V_66 = F_32 ( V_33 , V_49 ) ;
if ( ! V_63 -> V_66 ) {
F_27 ( L_11 , V_33 ) ;
return - V_50 ;
}
V_34 = strchr ( V_63 -> V_66 , ':' ) ;
if ( V_34 ) {
V_33 [ V_34 - V_63 -> V_66 ] = '\0' ;
V_34 ++ ;
}
V_63 -> type = F_12 ( V_34 , V_15 ) ;
if ( ! V_63 -> type ) {
F_27 ( L_12 , V_34 ) ;
return - V_32 ;
}
V_63 -> V_29 = * V_60 ;
* V_60 += V_63 -> type -> V_60 ;
V_31 = F_22 ( V_33 , V_63 -> type , & V_63 -> V_27 , V_37 ,
V_38 , V_15 ) ;
if ( V_31 >= 0 && V_34 != NULL )
V_31 = F_28 ( V_34 , V_63 -> type , & V_63 -> V_27 ) ;
if ( V_31 >= 0 ) {
V_63 -> V_51 . V_11 = F_18 ( V_63 -> type ,
V_63 -> V_27 . V_11 ,
V_15 ) ;
V_63 -> V_51 . V_4 = V_63 -> V_27 . V_4 ;
}
return V_31 ;
}
int F_33 ( const char * V_3 ,
struct V_62 * args , int V_67 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < F_34 ( V_68 ) ; V_16 ++ )
if ( strcmp ( V_68 [ V_16 ] , V_3 ) == 0 )
return 1 ;
for ( V_16 = 0 ; V_16 < V_67 ; V_16 ++ )
if ( strcmp ( args [ V_16 ] . V_3 , V_3 ) == 0 )
return 1 ;
return 0 ;
}
void F_35 ( struct V_62 * V_33 )
{
if ( F_5 ( V_69 , V_33 -> V_27 . V_11 ) )
F_10 ( V_33 -> V_27 . V_4 ) ;
else if ( F_5 ( V_9 , V_33 -> V_27 . V_11 ) )
F_4 ( V_33 -> V_27 . V_4 ) ;
else if ( F_5 ( V_12 , V_33 -> V_27 . V_11 ) )
F_6 ( V_33 -> V_27 . V_4 ) ;
}
void F_36 ( struct V_62 * V_33 )
{
if ( F_5 ( V_69 , V_33 -> V_27 . V_11 ) )
F_11 ( V_33 -> V_27 . V_4 ) ;
else if ( F_5 ( V_9 , V_33 -> V_27 . V_11 ) )
F_7 ( V_33 -> V_27 . V_4 ) ;
else if ( F_5 ( V_12 , V_33 -> V_27 . V_11 ) )
F_8 ( V_33 -> V_27 . V_4 ) ;
F_9 ( V_33 -> V_3 ) ;
F_9 ( V_33 -> V_66 ) ;
}
int F_37 ( const char * V_70 , int (* F_38)( int , char * * ) )
{
char * * V_71 ;
int V_72 , V_31 ;
V_72 = 0 ;
V_31 = 0 ;
V_71 = F_39 ( V_49 , V_70 , & V_72 ) ;
if ( ! V_71 )
return - V_50 ;
if ( V_72 )
V_31 = F_38 ( V_72 , V_71 ) ;
F_40 ( V_71 ) ;
return V_31 ;
}
T_3 F_41 ( struct V_73 * V_73 , const char T_4 * V_74 ,
T_5 V_75 , T_6 * V_76 ,
int (* F_38)( int , char * * ) )
{
char * V_77 , * V_30 ;
int V_31 = 0 ;
T_5 V_78 = 0 ;
T_5 V_60 ;
V_77 = F_42 ( V_79 , V_49 ) ;
if ( ! V_77 )
return - V_50 ;
while ( V_78 < V_75 ) {
V_60 = V_75 - V_78 ;
if ( V_60 >= V_79 )
V_60 = V_79 - 1 ;
if ( F_43 ( V_77 , V_74 + V_78 , V_60 ) ) {
V_31 = - V_80 ;
goto V_81;
}
V_77 [ V_60 ] = '\0' ;
V_30 = strchr ( V_77 , '\n' ) ;
if ( V_30 ) {
* V_30 = '\0' ;
V_60 = V_30 - V_77 + 1 ;
} else if ( V_78 + V_60 < V_75 ) {
F_44 ( L_13 ,
V_79 ) ;
V_31 = - V_32 ;
goto V_81;
}
V_78 += V_60 ;
V_30 = strchr ( V_77 , '#' ) ;
if ( V_30 )
* V_30 = '\0' ;
V_31 = F_37 ( V_77 , F_38 ) ;
if ( V_31 )
goto V_81;
}
V_31 = V_78 ;
V_81:
F_9 ( V_77 ) ;
return V_31 ;
}
static int F_45 ( struct V_82 * V_83 , char * V_70 , int V_6 ,
bool V_37 )
{
int V_16 ;
int V_84 = 0 ;
const char * V_85 , * V_33 ;
if ( ! V_37 ) {
V_85 = L_14 ;
V_33 = L_15 V_86 ;
} else {
V_85 = L_16 ;
V_33 = L_15 V_87 L_17 V_88 ;
}
#define F_46 (len ? len - pos : 0)
V_84 += snprintf ( V_70 + V_84 , F_46 , L_18 , V_85 ) ;
for ( V_16 = 0 ; V_16 < V_83 -> V_89 ; V_16 ++ ) {
V_84 += snprintf ( V_70 + V_84 , F_46 , L_19 ,
V_83 -> args [ V_16 ] . V_3 , V_83 -> args [ V_16 ] . type -> V_85 ) ;
}
V_84 += snprintf ( V_70 + V_84 , F_46 , L_20 , V_33 ) ;
for ( V_16 = 0 ; V_16 < V_83 -> V_89 ; V_16 ++ ) {
if ( strcmp ( V_83 -> args [ V_16 ] . type -> V_3 , L_21 ) == 0 )
V_84 += snprintf ( V_70 + V_84 , F_46 ,
L_22 ,
V_83 -> args [ V_16 ] . V_3 ) ;
else
V_84 += snprintf ( V_70 + V_84 , F_46 , L_23 ,
V_83 -> args [ V_16 ] . V_3 ) ;
}
#undef F_46
return V_84 ;
}
int F_47 ( struct V_82 * V_83 , bool V_37 )
{
int V_6 ;
char * V_90 ;
V_6 = F_45 ( V_83 , NULL , 0 , V_37 ) ;
V_90 = F_42 ( V_6 + 1 , V_49 ) ;
if ( ! V_90 )
return - V_50 ;
F_45 ( V_83 , V_90 , V_6 + 1 , V_37 ) ;
V_83 -> V_91 . V_90 = V_90 ;
return 0 ;
}

int T_1 (string)( struct V_1 * V_2 , const char * V_3 ,
void * V_4 , void * V_5 )
{
int V_6 = * ( V_7 * ) V_4 >> 16 ;
if ( ! V_6 )
return F_1 ( V_2 , L_1 , V_3 ) ;
else
return F_1 ( V_2 , L_2 , V_3 ,
( const char * ) F_2 ( V_4 , V_5 ) ) ;
}
static void F_3 ( struct V_8 * V_4 )
{
if ( F_4 ( V_9 , V_4 -> V_10 . V_11 ) )
F_3 ( V_4 -> V_10 . V_4 ) ;
else if ( F_4 ( V_12 , V_4 -> V_10 . V_11 ) )
F_5 ( V_4 -> V_10 . V_4 ) ;
}
static void F_6 ( struct V_8 * V_4 )
{
if ( F_4 ( V_9 , V_4 -> V_10 . V_11 ) )
F_6 ( V_4 -> V_10 . V_4 ) ;
else if ( F_4 ( V_12 , V_4 -> V_10 . V_11 ) )
F_7 ( V_4 -> V_10 . V_4 ) ;
F_8 ( V_4 ) ;
}
static void
F_9 ( struct V_13 * V_4 )
{
if ( F_4 ( V_9 , V_4 -> V_10 . V_11 ) )
F_3 ( V_4 -> V_10 . V_4 ) ;
else if ( F_4 ( V_12 , V_4 -> V_10 . V_11 ) )
F_5 ( V_4 -> V_10 . V_4 ) ;
}
static void
F_10 ( struct V_13 * V_4 )
{
if ( F_4 ( V_9 , V_4 -> V_10 . V_11 ) )
F_6 ( V_4 -> V_10 . V_4 ) ;
else if ( F_4 ( V_12 , V_4 -> V_10 . V_11 ) )
F_7 ( V_4 -> V_10 . V_4 ) ;
F_8 ( V_4 ) ;
}
static const struct V_14 * F_11 ( const char * type ,
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
if ( F_12 ( type , 0 , & V_18 ) )
goto V_19;
switch ( V_18 ) {
case 8 :
return F_11 ( L_3 , V_15 ) ;
case 16 :
return F_11 ( L_4 , V_15 ) ;
case 32 :
return F_11 ( L_5 , V_15 ) ;
case 64 :
return F_11 ( L_6 , V_15 ) ;
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
static void F_13 ( struct V_20 * V_21 , void * V_22 , void * V_23 )
{
* ( unsigned long * ) V_23 = F_14 ( V_21 ) ;
}
static void F_15 ( struct V_20 * V_21 , void * V_22 , void * V_23 )
{
* ( unsigned long * ) V_23 = F_16 ( V_21 ) ;
}
static T_2 F_17 ( const struct V_14 * type ,
T_2 V_24 ,
const struct V_14 * V_15 )
{
int V_16 ;
if ( type != & V_15 [ V_25 ] )
return NULL ;
for ( V_16 = 0 ; V_16 < V_26 ; V_16 ++ )
if ( type -> V_27 [ V_16 ] == V_24 )
return V_15 [ V_28 ] . V_27 [ V_16 ] ;
F_18 ( 1 ) ;
return NULL ;
}
int F_19 ( char * V_12 , unsigned long * V_29 )
{
char * V_30 ;
int V_31 ;
if ( ! V_29 )
return - V_32 ;
V_30 = strchr ( V_12 , '+' ) ;
if ( V_30 ) {
V_31 = F_12 ( V_30 + 1 , 0 , V_29 ) ;
if ( V_31 )
return V_31 ;
* V_30 = '\0' ;
} else
* V_29 = 0 ;
return 0 ;
}
static int F_20 ( char * V_33 , const struct V_14 * V_34 ,
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
V_36 -> V_11 = F_13 ;
else
V_36 -> V_11 = F_15 ;
} else if ( isdigit ( V_33 [ 5 ] ) ) {
V_31 = F_12 ( V_33 + 5 , 10 , & V_39 ) ;
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
static int F_21 ( char * V_33 , const struct V_14 * V_34 ,
struct V_35 * V_36 , bool V_37 , bool V_38 )
{
const struct V_14 * V_15 ;
unsigned long V_39 ;
long V_29 ;
char * V_30 ;
int V_31 = 0 ;
V_15 = V_38 ? V_43 : V_44 ;
F_22 ( V_15 == NULL ) ;
switch ( V_33 [ 0 ] ) {
case '$' :
V_31 = F_20 ( V_33 + 1 , V_34 , V_36 , V_37 , V_38 ) ;
break;
case '%' :
V_31 = F_23 ( V_33 + 1 ) ;
if ( V_31 >= 0 ) {
V_36 -> V_11 = V_34 -> V_27 [ V_45 ] ;
V_36 -> V_4 = ( void * ) ( unsigned long ) V_31 ;
V_31 = 0 ;
}
break;
case '@' :
if ( isdigit ( V_33 [ 1 ] ) ) {
V_31 = F_12 ( V_33 + 1 , 0 , & V_39 ) ;
if ( V_31 )
break;
V_36 -> V_11 = V_34 -> V_27 [ V_46 ] ;
V_36 -> V_4 = ( void * ) V_39 ;
} else if ( V_33 [ 1 ] == '+' ) {
if ( V_38 )
return - V_32 ;
V_31 = F_24 ( V_33 + 2 , 0 , & V_29 ) ;
if ( V_31 )
break;
V_36 -> V_11 = V_34 -> V_27 [ V_47 ] ;
V_36 -> V_4 = ( void * ) V_29 ;
} else {
if ( ! V_38 )
return - V_32 ;
V_31 = F_19 ( V_33 + 1 , & V_29 ) ;
if ( V_31 )
break;
V_36 -> V_4 = F_25 ( V_33 + 1 , V_29 ) ;
if ( V_36 -> V_4 )
V_36 -> V_11 = V_34 -> V_27 [ V_48 ] ;
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
struct V_8 * V_49 ;
const struct V_14 * V_50 ;
V_50 = F_11 ( NULL , V_15 ) ;
* V_30 = '\0' ;
V_49 = F_26 ( sizeof( struct V_8 ) , V_51 ) ;
if ( ! V_49 )
return - V_52 ;
V_49 -> V_29 = V_29 ;
V_49 -> V_27 = V_34 -> V_27 [ V_46 ] ;
V_49 -> V_53 = F_17 ( V_34 ,
V_49 -> V_27 , V_15 ) ;
V_31 = F_21 ( V_33 , V_50 , & V_49 -> V_10 , V_37 ,
V_38 ) ;
if ( V_31 )
F_8 ( V_49 ) ;
else {
V_36 -> V_11 = V_34 -> V_27 [ V_54 ] ;
V_36 -> V_4 = ( void * ) V_49 ;
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
static int F_28 ( const char * V_55 ,
const struct V_14 * V_34 ,
struct V_35 * V_36 )
{
struct V_13 * V_56 ;
unsigned long V_57 , V_58 ;
char * V_59 ;
if ( * V_55 != 'b' )
return 0 ;
V_56 = F_26 ( sizeof( * V_56 ) , V_51 ) ;
if ( ! V_56 )
return - V_52 ;
V_56 -> V_10 = * V_36 ;
V_36 -> V_11 = V_34 -> V_27 [ V_60 ] ;
V_36 -> V_4 = ( void * ) V_56 ;
V_57 = F_29 ( V_55 + 1 , & V_59 , 0 ) ;
if ( V_57 == 0 || * V_59 != '@' )
return - V_32 ;
V_55 = V_59 + 1 ;
V_58 = F_29 ( V_55 , & V_59 , 0 ) ;
if ( V_59 == V_55 || * V_59 != '/' )
return - V_32 ;
V_56 -> V_61 = F_30 ( V_34 -> V_62 ) - ( V_57 + V_58 ) ;
V_56 -> V_63 = V_56 -> V_61 + V_58 ;
return ( F_30 ( V_34 -> V_62 ) < ( V_57 + V_58 ) ) ? - V_32 : 0 ;
}
int F_31 ( char * V_33 , T_3 * V_62 ,
struct V_64 * V_65 , bool V_37 , bool V_38 )
{
const struct V_14 * V_15 ;
const char * V_34 ;
int V_31 ;
V_15 = V_38 ? V_43 : V_44 ;
F_22 ( V_15 == NULL ) ;
if ( strlen ( V_33 ) > V_66 ) {
F_27 ( L_10 , V_33 ) ;
return - V_67 ;
}
V_65 -> V_68 = F_32 ( V_33 , V_51 ) ;
if ( ! V_65 -> V_68 ) {
F_27 ( L_11 , V_33 ) ;
return - V_52 ;
}
V_34 = strchr ( V_65 -> V_68 , ':' ) ;
if ( V_34 ) {
V_33 [ V_34 - V_65 -> V_68 ] = '\0' ;
V_34 ++ ;
}
V_65 -> type = F_11 ( V_34 , V_15 ) ;
if ( ! V_65 -> type ) {
F_27 ( L_12 , V_34 ) ;
return - V_32 ;
}
V_65 -> V_29 = * V_62 ;
* V_62 += V_65 -> type -> V_62 ;
V_31 = F_21 ( V_33 , V_65 -> type , & V_65 -> V_27 , V_37 , V_38 ) ;
if ( V_31 >= 0 && V_34 != NULL )
V_31 = F_28 ( V_34 , V_65 -> type , & V_65 -> V_27 ) ;
if ( V_31 >= 0 ) {
V_65 -> V_53 . V_11 = F_17 ( V_65 -> type ,
V_65 -> V_27 . V_11 ,
V_15 ) ;
V_65 -> V_53 . V_4 = V_65 -> V_27 . V_4 ;
}
return V_31 ;
}
int F_33 ( const char * V_3 ,
struct V_64 * args , int V_69 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < F_34 ( V_70 ) ; V_16 ++ )
if ( strcmp ( V_70 [ V_16 ] , V_3 ) == 0 )
return 1 ;
for ( V_16 = 0 ; V_16 < V_69 ; V_16 ++ )
if ( strcmp ( args [ V_16 ] . V_3 , V_3 ) == 0 )
return 1 ;
return 0 ;
}
void F_35 ( struct V_64 * V_33 )
{
if ( F_4 ( V_71 , V_33 -> V_27 . V_11 ) )
F_9 ( V_33 -> V_27 . V_4 ) ;
else if ( F_4 ( V_9 , V_33 -> V_27 . V_11 ) )
F_3 ( V_33 -> V_27 . V_4 ) ;
else if ( F_4 ( V_12 , V_33 -> V_27 . V_11 ) )
F_5 ( V_33 -> V_27 . V_4 ) ;
}
void F_36 ( struct V_64 * V_33 )
{
if ( F_4 ( V_71 , V_33 -> V_27 . V_11 ) )
F_10 ( V_33 -> V_27 . V_4 ) ;
else if ( F_4 ( V_9 , V_33 -> V_27 . V_11 ) )
F_6 ( V_33 -> V_27 . V_4 ) ;
else if ( F_4 ( V_12 , V_33 -> V_27 . V_11 ) )
F_7 ( V_33 -> V_27 . V_4 ) ;
F_8 ( V_33 -> V_3 ) ;
F_8 ( V_33 -> V_68 ) ;
}
int F_37 ( const char * V_72 , int (* F_38)( int , char * * ) )
{
char * * V_73 ;
int V_74 , V_31 ;
V_74 = 0 ;
V_31 = 0 ;
V_73 = F_39 ( V_51 , V_72 , & V_74 ) ;
if ( ! V_73 )
return - V_52 ;
if ( V_74 )
V_31 = F_38 ( V_74 , V_73 ) ;
F_40 ( V_73 ) ;
return V_31 ;
}
T_3 F_41 ( struct V_75 * V_75 , const char T_4 * V_76 ,
T_5 V_77 , T_6 * V_78 ,
int (* F_38)( int , char * * ) )
{
char * V_79 , * V_30 ;
int V_31 = 0 ;
T_5 V_80 = 0 ;
T_5 V_62 ;
V_79 = F_42 ( V_81 , V_51 ) ;
if ( ! V_79 )
return - V_52 ;
while ( V_80 < V_77 ) {
V_62 = V_77 - V_80 ;
if ( V_62 >= V_81 )
V_62 = V_81 - 1 ;
if ( F_43 ( V_79 , V_76 + V_80 , V_62 ) ) {
V_31 = - V_82 ;
goto V_83;
}
V_79 [ V_62 ] = '\0' ;
V_30 = strchr ( V_79 , '\n' ) ;
if ( V_30 ) {
* V_30 = '\0' ;
V_62 = V_30 - V_79 + 1 ;
} else if ( V_80 + V_62 < V_77 ) {
F_44 ( L_13
L_14 , V_81 ) ;
V_31 = - V_32 ;
goto V_83;
}
V_80 += V_62 ;
V_30 = strchr ( V_79 , '#' ) ;
if ( V_30 )
* V_30 = '\0' ;
V_31 = F_37 ( V_79 , F_38 ) ;
if ( V_31 )
goto V_83;
}
V_31 = V_80 ;
V_83:
F_8 ( V_79 ) ;
return V_31 ;
}
static int F_45 ( struct V_84 * V_85 , char * V_72 , int V_6 ,
bool V_37 )
{
int V_16 ;
int V_86 = 0 ;
const char * V_87 , * V_33 ;
if ( ! V_37 ) {
V_87 = L_15 ;
V_33 = L_16 V_88 ;
} else {
V_87 = L_17 ;
V_33 = L_16 V_89 L_18 V_90 ;
}
#define F_46 (len ? len - pos : 0)
V_86 += snprintf ( V_72 + V_86 , F_46 , L_19 , V_87 ) ;
for ( V_16 = 0 ; V_16 < V_85 -> V_91 ; V_16 ++ ) {
V_86 += snprintf ( V_72 + V_86 , F_46 , L_20 ,
V_85 -> args [ V_16 ] . V_3 , V_85 -> args [ V_16 ] . type -> V_87 ) ;
}
V_86 += snprintf ( V_72 + V_86 , F_46 , L_21 , V_33 ) ;
for ( V_16 = 0 ; V_16 < V_85 -> V_91 ; V_16 ++ ) {
if ( strcmp ( V_85 -> args [ V_16 ] . type -> V_3 , L_22 ) == 0 )
V_86 += snprintf ( V_72 + V_86 , F_46 ,
L_23 ,
V_85 -> args [ V_16 ] . V_3 ) ;
else
V_86 += snprintf ( V_72 + V_86 , F_46 , L_24 ,
V_85 -> args [ V_16 ] . V_3 ) ;
}
#undef F_46
return V_86 ;
}
int F_47 ( struct V_84 * V_85 , bool V_37 )
{
int V_6 ;
char * V_92 ;
V_6 = F_45 ( V_85 , NULL , 0 , V_37 ) ;
V_92 = F_42 ( V_6 + 1 , V_51 ) ;
if ( ! V_92 )
return - V_52 ;
F_45 ( V_85 , V_92 , V_6 + 1 , V_37 ) ;
V_85 -> V_93 . V_92 = V_92 ;
return 0 ;
}

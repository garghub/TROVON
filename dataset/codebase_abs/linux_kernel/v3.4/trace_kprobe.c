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
F_6 ( V_7 -> V_24 . V_7 ) ;
}
static T_2 void F_15 ( struct V_22 * V_7 )
{
if ( F_14 ( V_23 , V_7 -> V_24 . V_14 ) )
F_15 ( V_7 -> V_24 . V_7 ) ;
else if ( F_14 ( V_18 , V_7 -> V_24 . V_14 ) )
F_8 ( V_7 -> V_24 . V_7 ) ;
F_9 ( V_7 ) ;
}
static T_2 void
F_16 ( struct V_25 * V_7 )
{
if ( F_14 ( V_23 , V_7 -> V_24 . V_14 ) )
F_13 ( V_7 -> V_24 . V_7 ) ;
else if ( F_14 ( V_18 , V_7 -> V_24 . V_14 ) )
F_6 ( V_7 -> V_24 . V_7 ) ;
}
static T_2 void
F_17 ( struct V_25 * V_7 )
{
if ( F_14 ( V_23 , V_7 -> V_24 . V_14 ) )
F_15 ( V_7 -> V_24 . V_7 ) ;
else if ( F_14 ( V_18 , V_7 -> V_24 . V_14 ) )
F_8 ( V_7 -> V_24 . V_7 ) ;
F_9 ( V_7 ) ;
}
static const struct V_26 * F_18 ( const char * type )
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
if ( F_19 ( type , 0 , & V_29 ) )
goto V_30;
switch ( V_29 ) {
case 8 :
return F_18 ( L_3 ) ;
case 16 :
return F_18 ( L_4 ) ;
case 32 :
return F_18 ( L_5 ) ;
case 64 :
return F_18 ( L_6 ) ;
default:
goto V_30;
}
}
for ( V_27 = 0 ; V_27 < F_20 ( V_31 ) ; V_27 ++ )
if ( strcmp ( type , V_31 [ V_27 ] . V_6 ) == 0 )
return & V_31 [ V_27 ] ;
V_30:
return NULL ;
}
static T_2 void F_21 ( struct V_11 * V_12 ,
void * V_32 , void * V_13 )
{
* ( unsigned long * ) V_13 = F_22 ( V_12 ) ;
}
static T_4 F_23 ( const struct V_26 * type ,
T_4 V_33 )
{
int V_27 ;
if ( type != & V_31 [ V_34 ] )
return NULL ;
for ( V_27 = 0 ; V_27 < V_35 ; V_27 ++ )
if ( type -> V_36 [ V_27 ] == V_33 )
return V_31 [ V_37 ] . V_36 [ V_27 ] ;
F_24 ( 1 ) ;
return NULL ;
}
static T_2 int F_25 ( struct V_38 * V_39 )
{
return V_39 -> V_40 . V_41 != NULL ;
}
static T_2 const char * F_26 ( struct V_38 * V_39 )
{
return V_39 -> V_18 ? V_39 -> V_18 : L_7 ;
}
static T_2 unsigned long F_27 ( struct V_38 * V_39 )
{
return V_39 -> V_40 . V_42 . V_19 ;
}
static T_2 bool F_28 ( struct V_38 * V_39 )
{
return ! ! ( V_39 -> V_43 & ( V_44 | V_45 ) ) ;
}
static T_2 bool F_29 ( struct V_38 * V_39 )
{
return ! ! ( V_39 -> V_43 & V_46 ) ;
}
static T_2 bool F_30 ( struct V_38 * V_39 )
{
return ! ! ( F_31 ( & V_39 -> V_40 . V_42 ) ) ;
}
static T_2 bool F_32 ( struct V_38 * V_39 ,
struct V_47 * V_48 )
{
int V_8 = strlen ( V_48 -> V_6 ) ;
const char * V_6 = F_26 ( V_39 ) ;
return strncmp ( V_48 -> V_6 , V_6 , V_8 ) == 0 && V_6 [ V_8 ] == ':' ;
}
static T_2 bool F_33 ( struct V_38 * V_39 )
{
return ! ! strchr ( F_26 ( V_39 ) , ':' ) ;
}
static int F_34 ( const char * V_6 )
{
if ( ! isalpha ( * V_6 ) && * V_6 != '_' )
return 0 ;
while ( * ++ V_6 != '\0' ) {
if ( ! isalpha ( * V_6 ) && ! isdigit ( * V_6 ) && * V_6 != '_' )
return 0 ;
}
return 1 ;
}
static struct V_38 * F_35 ( const char * V_49 ,
const char * V_50 ,
void * V_17 ,
const char * V_18 ,
unsigned long V_51 ,
int V_52 , int V_53 )
{
struct V_38 * V_39 ;
int V_54 = - V_55 ;
V_39 = F_11 ( F_36 ( V_52 ) , V_21 ) ;
if ( ! V_39 )
return F_37 ( V_54 ) ;
if ( V_18 ) {
V_39 -> V_18 = F_12 ( V_18 , V_21 ) ;
if ( ! V_39 -> V_18 )
goto error;
V_39 -> V_40 . V_42 . V_56 = V_39 -> V_18 ;
V_39 -> V_40 . V_42 . V_19 = V_51 ;
} else
V_39 -> V_40 . V_42 . V_17 = V_17 ;
if ( V_53 )
V_39 -> V_40 . V_41 = V_57 ;
else
V_39 -> V_40 . V_42 . V_58 = V_59 ;
if ( ! V_50 || ! F_34 ( V_50 ) ) {
V_54 = - V_60 ;
goto error;
}
V_39 -> V_61 . V_62 = & V_39 -> V_62 ;
V_39 -> V_61 . V_6 = F_12 ( V_50 , V_21 ) ;
if ( ! V_39 -> V_61 . V_6 )
goto error;
if ( ! V_49 || ! F_34 ( V_49 ) ) {
V_54 = - V_60 ;
goto error;
}
V_39 -> V_62 . system = F_12 ( V_49 , V_21 ) ;
if ( ! V_39 -> V_62 . system )
goto error;
F_38 ( & V_39 -> V_63 ) ;
return V_39 ;
error:
F_9 ( V_39 -> V_61 . V_6 ) ;
F_9 ( V_39 -> V_18 ) ;
F_9 ( V_39 ) ;
return F_37 ( V_54 ) ;
}
static void F_39 ( struct V_64 * V_65 )
{
if ( F_14 ( V_66 , V_65 -> V_36 . V_14 ) )
F_16 ( V_65 -> V_36 . V_7 ) ;
else if ( F_14 ( V_23 , V_65 -> V_36 . V_14 ) )
F_13 ( V_65 -> V_36 . V_7 ) ;
else if ( F_14 ( V_18 , V_65 -> V_36 . V_14 ) )
F_6 ( V_65 -> V_36 . V_7 ) ;
}
static void F_40 ( struct V_64 * V_65 )
{
if ( F_14 ( V_66 , V_65 -> V_36 . V_14 ) )
F_17 ( V_65 -> V_36 . V_7 ) ;
else if ( F_14 ( V_23 , V_65 -> V_36 . V_14 ) )
F_15 ( V_65 -> V_36 . V_7 ) ;
else if ( F_14 ( V_18 , V_65 -> V_36 . V_14 ) )
F_8 ( V_65 -> V_36 . V_7 ) ;
F_9 ( V_65 -> V_6 ) ;
F_9 ( V_65 -> V_67 ) ;
}
static void F_41 ( struct V_38 * V_39 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ )
F_40 ( & V_39 -> args [ V_27 ] ) ;
F_9 ( V_39 -> V_61 . V_62 -> system ) ;
F_9 ( V_39 -> V_61 . V_6 ) ;
F_9 ( V_39 -> V_18 ) ;
F_9 ( V_39 ) ;
}
static struct V_38 * F_42 ( const char * V_50 ,
const char * V_49 )
{
struct V_38 * V_39 ;
F_43 (tp, &probe_list, list)
if ( strcmp ( V_39 -> V_61 . V_6 , V_50 ) == 0 &&
strcmp ( V_39 -> V_61 . V_62 -> system , V_49 ) == 0 )
return V_39 ;
return NULL ;
}
static int F_44 ( struct V_38 * V_39 , int V_69 )
{
int V_54 = 0 ;
V_39 -> V_43 |= V_69 ;
if ( F_28 ( V_39 ) && F_29 ( V_39 ) &&
! F_30 ( V_39 ) ) {
if ( F_25 ( V_39 ) )
V_54 = F_45 ( & V_39 -> V_40 ) ;
else
V_54 = F_46 ( & V_39 -> V_40 . V_42 ) ;
}
return V_54 ;
}
static void F_47 ( struct V_38 * V_39 , int V_69 )
{
V_39 -> V_43 &= ~ V_69 ;
if ( ! F_28 ( V_39 ) && F_29 ( V_39 ) ) {
if ( F_25 ( V_39 ) )
F_48 ( & V_39 -> V_40 ) ;
else
F_49 ( & V_39 -> V_40 . V_42 ) ;
}
}
static int F_50 ( struct V_38 * V_39 )
{
int V_27 , V_54 ;
if ( F_29 ( V_39 ) )
return - V_60 ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ )
F_39 ( & V_39 -> args [ V_27 ] ) ;
if ( F_28 ( V_39 ) )
V_39 -> V_40 . V_42 . V_43 &= ~ V_70 ;
else
V_39 -> V_40 . V_42 . V_43 |= V_70 ;
if ( F_25 ( V_39 ) )
V_54 = F_51 ( & V_39 -> V_40 ) ;
else
V_54 = F_52 ( & V_39 -> V_40 . V_42 ) ;
if ( V_54 == 0 )
V_39 -> V_43 |= V_46 ;
else {
F_53 ( L_8 ,
F_26 ( V_39 ) , F_27 ( V_39 ) , V_54 ) ;
if ( V_54 == - V_71 && F_33 ( V_39 ) ) {
F_53 ( L_9
L_10 ) ;
V_54 = 0 ;
} else if ( V_54 == - V_72 ) {
F_53 ( L_11
L_12 ,
V_39 -> V_40 . V_42 . V_17 ) ;
V_54 = - V_60 ;
}
}
return V_54 ;
}
static void F_54 ( struct V_38 * V_39 )
{
if ( F_29 ( V_39 ) ) {
if ( F_25 ( V_39 ) )
F_55 ( & V_39 -> V_40 ) ;
else
F_56 ( & V_39 -> V_40 . V_42 ) ;
V_39 -> V_43 &= ~ V_46 ;
if ( V_39 -> V_40 . V_42 . V_56 )
V_39 -> V_40 . V_42 . V_17 = NULL ;
}
}
static int F_57 ( struct V_38 * V_39 )
{
if ( F_28 ( V_39 ) )
return - V_73 ;
F_54 ( V_39 ) ;
F_58 ( & V_39 -> V_63 ) ;
F_59 ( V_39 ) ;
return 0 ;
}
static int F_60 ( struct V_38 * V_39 )
{
struct V_38 * V_74 ;
int V_54 ;
F_61 ( & V_75 ) ;
V_74 = F_42 ( V_39 -> V_61 . V_6 , V_39 -> V_61 . V_62 -> system ) ;
if ( V_74 ) {
V_54 = F_57 ( V_74 ) ;
if ( V_54 < 0 )
goto V_76;
F_41 ( V_74 ) ;
}
V_54 = F_62 ( V_39 ) ;
if ( V_54 ) {
F_53 ( L_13 , V_54 ) ;
goto V_76;
}
V_54 = F_50 ( V_39 ) ;
if ( V_54 < 0 )
F_59 ( V_39 ) ;
else
F_63 ( & V_39 -> V_63 , & V_77 ) ;
V_76:
F_64 ( & V_75 ) ;
return V_54 ;
}
static int F_65 ( struct V_78 * V_79 ,
unsigned long V_80 , void * V_7 )
{
struct V_47 * V_48 = V_7 ;
struct V_38 * V_39 ;
int V_54 ;
if ( V_80 != V_81 )
return V_82 ;
F_61 ( & V_75 ) ;
F_43 (tp, &probe_list, list) {
if ( F_32 ( V_39 , V_48 ) ) {
F_54 ( V_39 ) ;
V_54 = F_50 ( V_39 ) ;
if ( V_54 )
F_53 ( L_14
L_15 ,
V_39 -> V_61 . V_6 , V_48 -> V_6 , V_54 ) ;
}
}
F_64 ( & V_75 ) ;
return V_82 ;
}
static int F_66 ( char * V_18 , unsigned long * V_19 )
{
char * V_83 ;
int V_54 ;
if ( ! V_19 )
return - V_60 ;
V_83 = strchr ( V_18 , '+' ) ;
if ( V_83 ) {
V_54 = F_19 ( V_83 + 1 , 0 , V_19 ) ;
if ( V_54 )
return V_54 ;
* V_83 = '\0' ;
} else
* V_19 = 0 ;
return 0 ;
}
static int F_67 ( char * V_65 , const struct V_26 * V_84 ,
struct V_9 * V_85 , int V_53 )
{
int V_54 = 0 ;
unsigned long V_86 ;
if ( strcmp ( V_65 , L_16 ) == 0 ) {
if ( V_53 )
V_85 -> V_14 = V_84 -> V_36 [ V_87 ] ;
else
V_54 = - V_60 ;
} else if ( strncmp ( V_65 , L_17 , 5 ) == 0 ) {
if ( V_65 [ 5 ] == '\0' ) {
if ( strcmp ( V_84 -> V_6 , V_28 ) == 0 )
V_85 -> V_14 = F_21 ;
else
V_54 = - V_60 ;
} else if ( isdigit ( V_65 [ 5 ] ) ) {
V_54 = F_19 ( V_65 + 5 , 10 , & V_86 ) ;
if ( V_54 || V_86 > V_88 )
V_54 = - V_60 ;
else {
V_85 -> V_14 = V_84 -> V_36 [ V_89 ] ;
V_85 -> V_7 = ( void * ) V_86 ;
}
} else
V_54 = - V_60 ;
} else
V_54 = - V_60 ;
return V_54 ;
}
static int F_68 ( char * V_65 , const struct V_26 * V_84 ,
struct V_9 * V_85 , int V_53 )
{
int V_54 = 0 ;
unsigned long V_86 ;
long V_19 ;
char * V_83 ;
switch ( V_65 [ 0 ] ) {
case '$' :
V_54 = F_67 ( V_65 + 1 , V_84 , V_85 , V_53 ) ;
break;
case '%' :
V_54 = F_69 ( V_65 + 1 ) ;
if ( V_54 >= 0 ) {
V_85 -> V_14 = V_84 -> V_36 [ V_90 ] ;
V_85 -> V_7 = ( void * ) ( unsigned long ) V_54 ;
V_54 = 0 ;
}
break;
case '@' :
if ( isdigit ( V_65 [ 1 ] ) ) {
V_54 = F_19 ( V_65 + 1 , 0 , & V_86 ) ;
if ( V_54 )
break;
V_85 -> V_14 = V_84 -> V_36 [ V_91 ] ;
V_85 -> V_7 = ( void * ) V_86 ;
} else {
V_54 = F_66 ( V_65 + 1 , & V_19 ) ;
if ( V_54 )
break;
V_85 -> V_7 = F_10 ( V_65 + 1 , V_19 ) ;
if ( V_85 -> V_7 )
V_85 -> V_14 = V_84 -> V_36 [ V_92 ] ;
}
break;
case '+' :
V_65 ++ ;
case '-' :
V_83 = strchr ( V_65 , '(' ) ;
if ( ! V_83 )
break;
* V_83 = '\0' ;
V_54 = F_70 ( V_65 , 0 , & V_19 ) ;
if ( V_54 )
break;
V_65 = V_83 + 1 ;
V_83 = strrchr ( V_65 , ')' ) ;
if ( V_83 ) {
struct V_22 * V_93 ;
const struct V_26 * V_94 = F_18 ( NULL ) ;
* V_83 = '\0' ;
V_93 = F_11 ( sizeof( struct V_22 ) ,
V_21 ) ;
if ( ! V_93 )
return - V_55 ;
V_93 -> V_19 = V_19 ;
V_54 = F_68 ( V_65 , V_94 , & V_93 -> V_24 ,
V_53 ) ;
if ( V_54 )
F_9 ( V_93 ) ;
else {
V_85 -> V_14 = V_84 -> V_36 [ V_95 ] ;
V_85 -> V_7 = ( void * ) V_93 ;
}
}
break;
}
if ( ! V_54 && ! V_85 -> V_14 ) {
F_71 ( L_18 ,
V_84 -> V_6 ) ;
V_54 = - V_60 ;
}
return V_54 ;
}
static int F_72 ( const char * V_96 ,
const struct V_26 * V_84 ,
struct V_9 * V_85 )
{
struct V_25 * V_97 ;
unsigned long V_98 , V_99 ;
char * V_100 ;
if ( * V_96 != 'b' )
return 0 ;
V_97 = F_11 ( sizeof( * V_97 ) , V_21 ) ;
if ( ! V_97 )
return - V_55 ;
V_97 -> V_24 = * V_85 ;
V_85 -> V_14 = V_84 -> V_36 [ V_101 ] ;
V_85 -> V_7 = ( void * ) V_97 ;
V_98 = F_73 ( V_96 + 1 , & V_100 , 0 ) ;
if ( V_98 == 0 || * V_100 != '@' )
return - V_60 ;
V_96 = V_100 + 1 ;
V_99 = F_73 ( V_96 , & V_100 , 0 ) ;
if ( V_100 == V_96 || * V_100 != '/' )
return - V_60 ;
V_97 -> V_102 = F_74 ( V_84 -> V_103 ) - ( V_98 + V_99 ) ;
V_97 -> V_104 = V_97 -> V_102 + V_99 ;
return ( F_74 ( V_84 -> V_103 ) < ( V_98 + V_99 ) ) ? - V_60 : 0 ;
}
static int F_75 ( char * V_65 , struct V_38 * V_39 ,
struct V_64 * V_105 , int V_53 )
{
const char * V_84 ;
int V_54 ;
if ( strlen ( V_65 ) > V_106 ) {
F_71 ( L_19 , V_65 ) ;
return - V_107 ;
}
V_105 -> V_67 = F_12 ( V_65 , V_21 ) ;
if ( ! V_105 -> V_67 ) {
F_71 ( L_20 , V_65 ) ;
return - V_55 ;
}
V_84 = strchr ( V_105 -> V_67 , ':' ) ;
if ( V_84 ) {
V_65 [ V_84 - V_105 -> V_67 ] = '\0' ;
V_84 ++ ;
}
V_105 -> type = F_18 ( V_84 ) ;
if ( ! V_105 -> type ) {
F_71 ( L_21 , V_84 ) ;
return - V_60 ;
}
V_105 -> V_19 = V_39 -> V_103 ;
V_39 -> V_103 += V_105 -> type -> V_103 ;
V_54 = F_68 ( V_65 , V_105 -> type , & V_105 -> V_36 , V_53 ) ;
if ( V_54 >= 0 && V_84 != NULL )
V_54 = F_72 ( V_84 , V_105 -> type , & V_105 -> V_36 ) ;
if ( V_54 >= 0 ) {
V_105 -> V_108 . V_14 = F_23 ( V_105 -> type ,
V_105 -> V_36 . V_14 ) ;
V_105 -> V_108 . V_7 = V_105 -> V_36 . V_7 ;
}
return V_54 ;
}
static int F_76 ( const char * V_6 ,
struct V_64 * args , int V_109 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < F_20 ( V_110 ) ; V_27 ++ )
if ( strcmp ( V_110 [ V_27 ] , V_6 ) == 0 )
return 1 ;
for ( V_27 = 0 ; V_27 < V_109 ; V_27 ++ )
if ( strcmp ( args [ V_27 ] . V_6 , V_6 ) == 0 )
return 1 ;
return 0 ;
}
static int F_77 ( int V_111 , char * * V_112 )
{
struct V_38 * V_39 ;
int V_27 , V_54 = 0 ;
int V_53 = 0 , V_113 = 0 ;
char * V_18 = NULL , * V_50 = NULL , * V_49 = NULL ;
char * V_65 ;
unsigned long V_19 = 0 ;
void * V_17 = NULL ;
char V_114 [ V_115 ] ;
if ( V_112 [ 0 ] [ 0 ] == 'p' )
V_53 = 0 ;
else if ( V_112 [ 0 ] [ 0 ] == 'r' )
V_53 = 1 ;
else if ( V_112 [ 0 ] [ 0 ] == '-' )
V_113 = 1 ;
else {
F_71 ( L_22
L_23 ) ;
return - V_60 ;
}
if ( V_112 [ 0 ] [ 1 ] == ':' ) {
V_50 = & V_112 [ 0 ] [ 2 ] ;
if ( strchr ( V_50 , '/' ) ) {
V_49 = V_50 ;
V_50 = strchr ( V_49 , '/' ) + 1 ;
V_50 [ - 1 ] = '\0' ;
if ( strlen ( V_49 ) == 0 ) {
F_71 ( L_24 ) ;
return - V_60 ;
}
}
if ( strlen ( V_50 ) == 0 ) {
F_71 ( L_25 ) ;
return - V_60 ;
}
}
if ( ! V_49 )
V_49 = V_116 ;
if ( V_113 ) {
if ( ! V_50 ) {
F_71 ( L_26 ) ;
return - V_60 ;
}
F_61 ( & V_75 ) ;
V_39 = F_42 ( V_50 , V_49 ) ;
if ( ! V_39 ) {
F_64 ( & V_75 ) ;
F_71 ( L_27 , V_49 , V_50 ) ;
return - V_71 ;
}
V_54 = F_57 ( V_39 ) ;
if ( V_54 == 0 )
F_41 ( V_39 ) ;
F_64 ( & V_75 ) ;
return V_54 ;
}
if ( V_111 < 2 ) {
F_71 ( L_28 ) ;
return - V_60 ;
}
if ( isdigit ( V_112 [ 1 ] [ 0 ] ) ) {
if ( V_53 ) {
F_71 ( L_29 ) ;
return - V_60 ;
}
V_54 = F_19 ( & V_112 [ 1 ] [ 0 ] , 0 , ( unsigned long * ) & V_17 ) ;
if ( V_54 ) {
F_71 ( L_30 ) ;
return V_54 ;
}
} else {
V_18 = V_112 [ 1 ] ;
V_54 = F_66 ( V_18 , & V_19 ) ;
if ( V_54 ) {
F_71 ( L_31 ) ;
return V_54 ;
}
if ( V_19 && V_53 ) {
F_71 ( L_32 ) ;
return - V_60 ;
}
}
V_111 -= 2 ; V_112 += 2 ;
if ( ! V_50 ) {
if ( V_18 )
snprintf ( V_114 , V_115 , L_33 ,
V_53 ? 'r' : 'p' , V_18 , V_19 ) ;
else
snprintf ( V_114 , V_115 , L_34 ,
V_53 ? 'r' : 'p' , V_17 ) ;
V_50 = V_114 ;
}
V_39 = F_35 ( V_49 , V_50 , V_17 , V_18 , V_19 , V_111 ,
V_53 ) ;
if ( F_78 ( V_39 ) ) {
F_71 ( L_35 ,
( int ) F_79 ( V_39 ) ) ;
return F_79 ( V_39 ) ;
}
V_54 = 0 ;
for ( V_27 = 0 ; V_27 < V_111 && V_27 < V_117 ; V_27 ++ ) {
V_39 -> V_68 ++ ;
V_65 = strchr ( V_112 [ V_27 ] , '=' ) ;
if ( V_65 ) {
* V_65 ++ = '\0' ;
V_39 -> args [ V_27 ] . V_6 = F_12 ( V_112 [ V_27 ] , V_21 ) ;
} else {
V_65 = V_112 [ V_27 ] ;
snprintf ( V_114 , V_115 , L_36 , V_27 + 1 ) ;
V_39 -> args [ V_27 ] . V_6 = F_12 ( V_114 , V_21 ) ;
}
if ( ! V_39 -> args [ V_27 ] . V_6 ) {
F_71 ( L_37 , V_27 ) ;
V_54 = - V_55 ;
goto error;
}
if ( ! F_34 ( V_39 -> args [ V_27 ] . V_6 ) ) {
F_71 ( L_38 ,
V_27 , V_39 -> args [ V_27 ] . V_6 ) ;
V_54 = - V_60 ;
goto error;
}
if ( F_76 ( V_39 -> args [ V_27 ] . V_6 , V_39 -> args , V_27 ) ) {
F_71 ( L_39
L_40 , V_27 , V_112 [ V_27 ] ) ;
V_54 = - V_60 ;
goto error;
}
V_54 = F_75 ( V_65 , V_39 , & V_39 -> args [ V_27 ] , V_53 ) ;
if ( V_54 ) {
F_71 ( L_41 , V_27 , V_54 ) ;
goto error;
}
}
V_54 = F_60 ( V_39 ) ;
if ( V_54 )
goto error;
return 0 ;
error:
F_41 ( V_39 ) ;
return V_54 ;
}
static int F_80 ( void )
{
struct V_38 * V_39 ;
int V_54 = 0 ;
F_61 ( & V_75 ) ;
F_43 (tp, &probe_list, list)
if ( F_28 ( V_39 ) ) {
V_54 = - V_73 ;
goto V_76;
}
while ( ! F_81 ( & V_77 ) ) {
V_39 = F_82 ( V_77 . V_118 , struct V_38 , V_63 ) ;
F_57 ( V_39 ) ;
F_41 ( V_39 ) ;
}
V_76:
F_64 ( & V_75 ) ;
return V_54 ;
}
static void * F_83 ( struct V_119 * V_120 , T_5 * V_121 )
{
F_61 ( & V_75 ) ;
return F_84 ( & V_77 , * V_121 ) ;
}
static void * F_85 ( struct V_119 * V_120 , void * V_122 , T_5 * V_121 )
{
return F_86 ( V_122 , & V_77 , V_121 ) ;
}
static void F_87 ( struct V_119 * V_120 , void * V_122 )
{
F_64 ( & V_75 ) ;
}
static int F_88 ( struct V_119 * V_120 , void * V_122 )
{
struct V_38 * V_39 = V_122 ;
int V_27 ;
F_89 ( V_120 , L_42 , F_25 ( V_39 ) ? 'r' : 'p' ) ;
F_89 ( V_120 , L_43 , V_39 -> V_61 . V_62 -> system , V_39 -> V_61 . V_6 ) ;
if ( ! V_39 -> V_18 )
F_89 ( V_120 , L_44 , V_39 -> V_40 . V_42 . V_17 ) ;
else if ( V_39 -> V_40 . V_42 . V_19 )
F_89 ( V_120 , L_45 , F_26 ( V_39 ) ,
V_39 -> V_40 . V_42 . V_19 ) ;
else
F_89 ( V_120 , L_46 , F_26 ( V_39 ) ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ )
F_89 ( V_120 , L_47 , V_39 -> args [ V_27 ] . V_6 , V_39 -> args [ V_27 ] . V_67 ) ;
F_89 ( V_120 , L_48 ) ;
return 0 ;
}
static int F_90 ( struct V_123 * V_123 , struct V_124 * V_124 )
{
int V_54 ;
if ( ( V_124 -> V_125 & V_126 ) && ( V_124 -> V_127 & V_128 ) ) {
V_54 = F_80 () ;
if ( V_54 < 0 )
return V_54 ;
}
return F_91 ( V_124 , & V_129 ) ;
}
static int F_92 ( const char * V_114 )
{
char * * V_112 ;
int V_111 = 0 , V_54 = 0 ;
V_112 = F_93 ( V_21 , V_114 , & V_111 ) ;
if ( ! V_112 )
return - V_55 ;
if ( V_111 )
V_54 = F_77 ( V_111 , V_112 ) ;
F_94 ( V_112 ) ;
return V_54 ;
}
static T_6 F_95 ( struct V_124 * V_124 , const char T_7 * V_130 ,
T_8 V_131 , T_5 * V_132 )
{
char * V_133 , * V_83 ;
int V_54 ;
T_8 V_134 ;
T_8 V_103 ;
V_133 = F_96 ( V_135 , V_21 ) ;
if ( ! V_133 )
return - V_55 ;
V_54 = V_134 = 0 ;
while ( V_134 < V_131 ) {
V_103 = V_131 - V_134 ;
if ( V_103 >= V_135 )
V_103 = V_135 - 1 ;
if ( F_97 ( V_133 , V_130 + V_134 , V_103 ) ) {
V_54 = - V_136 ;
goto V_137;
}
V_133 [ V_103 ] = '\0' ;
V_83 = strchr ( V_133 , '\n' ) ;
if ( V_83 ) {
* V_83 = '\0' ;
V_103 = V_83 - V_133 + 1 ;
} else if ( V_134 + V_103 < V_131 ) {
F_53 ( L_49
L_50 , V_135 ) ;
V_54 = - V_60 ;
goto V_137;
}
V_134 += V_103 ;
V_83 = strchr ( V_133 , '#' ) ;
if ( V_83 )
* V_83 = '\0' ;
V_54 = F_92 ( V_133 ) ;
if ( V_54 )
goto V_137;
}
V_54 = V_134 ;
V_137:
F_9 ( V_133 ) ;
return V_54 ;
}
static int F_98 ( struct V_119 * V_120 , void * V_122 )
{
struct V_38 * V_39 = V_122 ;
F_89 ( V_120 , L_51 , V_39 -> V_61 . V_6 , V_39 -> V_138 ,
V_39 -> V_40 . V_42 . V_139 ) ;
return 0 ;
}
static int F_99 ( struct V_123 * V_123 , struct V_124 * V_124 )
{
return F_91 ( V_124 , & V_140 ) ;
}
static T_2 int F_100 ( struct V_38 * V_39 ,
struct V_11 * V_12 )
{
int V_27 , V_54 = 0 ;
T_1 V_8 ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ )
if ( F_101 ( V_39 -> args [ V_27 ] . V_108 . V_14 ) ) {
F_5 ( & V_39 -> args [ V_27 ] . V_108 , V_12 , & V_8 ) ;
V_54 += V_8 ;
}
return V_54 ;
}
static T_2 void F_102 ( int V_141 , struct V_38 * V_39 ,
struct V_11 * V_12 ,
V_2 * V_7 , int V_142 )
{
int V_27 ;
T_1 V_76 = V_39 -> V_103 ;
T_1 * V_1 ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ ) {
if ( F_101 ( V_39 -> args [ V_27 ] . V_108 . V_14 ) ) {
V_1 = ( T_1 * ) ( V_7 + V_39 -> args [ V_27 ] . V_19 ) ;
* V_1 = F_103 ( V_142 , V_76 - V_39 -> args [ V_27 ] . V_19 ) ;
F_5 ( & V_39 -> args [ V_27 ] . V_36 , V_12 , V_1 ) ;
V_76 += F_104 ( * V_1 ) ;
V_142 -= F_104 ( * V_1 ) ;
* V_1 = F_105 ( * V_1 ,
V_141 + V_39 -> args [ V_27 ] . V_19 ) ;
} else
F_5 ( & V_39 -> args [ V_27 ] . V_36 , V_12 ,
V_7 + V_39 -> args [ V_27 ] . V_19 ) ;
}
}
static T_2 void F_106 ( struct V_143 * V_42 , struct V_11 * V_12 )
{
struct V_38 * V_39 = F_107 ( V_42 , struct V_38 , V_40 . V_42 ) ;
struct V_144 * V_145 ;
struct V_146 * V_50 ;
struct V_147 * V_130 ;
int V_103 , V_148 , V_149 ;
unsigned long V_150 ;
struct V_151 * V_61 = & V_39 -> V_61 ;
V_39 -> V_138 ++ ;
F_108 ( V_150 ) ;
V_149 = F_109 () ;
V_148 = F_100 ( V_39 , V_12 ) ;
V_103 = sizeof( * V_145 ) + V_39 -> V_103 + V_148 ;
V_50 = F_110 ( & V_130 , V_61 -> V_50 . type ,
V_103 , V_150 , V_149 ) ;
if ( ! V_50 )
return;
V_145 = F_111 ( V_50 ) ;
V_145 -> V_152 = ( unsigned long ) V_42 -> V_17 ;
F_102 ( sizeof( * V_145 ) , V_39 , V_12 , ( V_2 * ) & V_145 [ 1 ] , V_148 ) ;
if ( ! F_112 ( V_130 , V_61 , V_145 , V_50 ) )
F_113 ( V_130 , V_50 ,
V_150 , V_149 , V_12 ) ;
}
static T_2 void F_114 ( struct V_153 * V_154 ,
struct V_11 * V_12 )
{
struct V_38 * V_39 = F_107 ( V_154 -> V_40 , struct V_38 , V_40 ) ;
struct V_155 * V_145 ;
struct V_146 * V_50 ;
struct V_147 * V_130 ;
int V_103 , V_149 , V_148 ;
unsigned long V_150 ;
struct V_151 * V_61 = & V_39 -> V_61 ;
F_108 ( V_150 ) ;
V_149 = F_109 () ;
V_148 = F_100 ( V_39 , V_12 ) ;
V_103 = sizeof( * V_145 ) + V_39 -> V_103 + V_148 ;
V_50 = F_110 ( & V_130 , V_61 -> V_50 . type ,
V_103 , V_150 , V_149 ) ;
if ( ! V_50 )
return;
V_145 = F_111 ( V_50 ) ;
V_145 -> V_156 = ( unsigned long ) V_39 -> V_40 . V_42 . V_17 ;
V_145 -> V_157 = ( unsigned long ) V_154 -> V_158 ;
F_102 ( sizeof( * V_145 ) , V_39 , V_12 , ( V_2 * ) & V_145 [ 1 ] , V_148 ) ;
if ( ! F_112 ( V_130 , V_61 , V_145 , V_50 ) )
F_113 ( V_130 , V_50 ,
V_150 , V_149 , V_12 ) ;
}
enum V_159
F_115 ( struct V_160 * V_161 , int V_43 ,
struct V_162 * V_50 )
{
struct V_144 * V_163 ;
struct V_4 * V_5 = & V_161 -> V_164 ;
struct V_38 * V_39 ;
V_2 * V_7 ;
int V_27 ;
V_163 = (struct V_144 * ) V_161 -> V_3 ;
V_39 = F_107 ( V_50 , struct V_38 , V_61 . V_50 ) ;
if ( ! F_4 ( V_5 , L_52 , V_39 -> V_61 . V_6 ) )
goto V_165;
if ( ! F_116 ( V_5 , V_163 -> V_152 , V_43 | V_166 ) )
goto V_165;
if ( ! F_117 ( V_5 , L_53 ) )
goto V_165;
V_7 = ( V_2 * ) & V_163 [ 1 ] ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ )
if ( ! V_39 -> args [ V_27 ] . type -> V_167 ( V_5 , V_39 -> args [ V_27 ] . V_6 ,
V_7 + V_39 -> args [ V_27 ] . V_19 , V_163 ) )
goto V_165;
if ( ! F_117 ( V_5 , L_48 ) )
goto V_165;
return V_168 ;
V_165:
return V_169 ;
}
enum V_159
F_118 ( struct V_160 * V_161 , int V_43 ,
struct V_162 * V_50 )
{
struct V_155 * V_163 ;
struct V_4 * V_5 = & V_161 -> V_164 ;
struct V_38 * V_39 ;
V_2 * V_7 ;
int V_27 ;
V_163 = (struct V_155 * ) V_161 -> V_3 ;
V_39 = F_107 ( V_50 , struct V_38 , V_61 . V_50 ) ;
if ( ! F_4 ( V_5 , L_52 , V_39 -> V_61 . V_6 ) )
goto V_165;
if ( ! F_116 ( V_5 , V_163 -> V_157 , V_43 | V_166 ) )
goto V_165;
if ( ! F_117 ( V_5 , L_54 ) )
goto V_165;
if ( ! F_116 ( V_5 , V_163 -> V_156 , V_43 & ~ V_166 ) )
goto V_165;
if ( ! F_117 ( V_5 , L_53 ) )
goto V_165;
V_7 = ( V_2 * ) & V_163 [ 1 ] ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ )
if ( ! V_39 -> args [ V_27 ] . type -> V_167 ( V_5 , V_39 -> args [ V_27 ] . V_6 ,
V_7 + V_39 -> args [ V_27 ] . V_19 , V_163 ) )
goto V_165;
if ( ! F_117 ( V_5 , L_48 ) )
goto V_165;
return V_168 ;
V_165:
return V_169 ;
}
static int F_119 ( struct V_151 * V_170 )
{
int V_54 , V_27 ;
struct V_144 V_163 ;
struct V_38 * V_39 = (struct V_38 * ) V_170 -> V_7 ;
F_120 (unsigned long, ip, FIELD_STRING_IP, 0 ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ ) {
V_54 = F_121 ( V_170 , V_39 -> args [ V_27 ] . type -> V_171 ,
V_39 -> args [ V_27 ] . V_6 ,
sizeof( V_163 ) + V_39 -> args [ V_27 ] . V_19 ,
V_39 -> args [ V_27 ] . type -> V_103 ,
V_39 -> args [ V_27 ] . type -> V_172 ,
V_173 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_122 ( struct V_151 * V_170 )
{
int V_54 , V_27 ;
struct V_155 V_163 ;
struct V_38 * V_39 = (struct V_38 * ) V_170 -> V_7 ;
F_120 (unsigned long, func, FIELD_STRING_FUNC, 0 ) ;
F_120 (unsigned long, ret_ip, FIELD_STRING_RETIP, 0 ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ ) {
V_54 = F_121 ( V_170 , V_39 -> args [ V_27 ] . type -> V_171 ,
V_39 -> args [ V_27 ] . V_6 ,
sizeof( V_163 ) + V_39 -> args [ V_27 ] . V_19 ,
V_39 -> args [ V_27 ] . type -> V_103 ,
V_39 -> args [ V_27 ] . type -> V_172 ,
V_173 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_123 ( struct V_38 * V_39 , char * V_114 , int V_8 )
{
int V_27 ;
int V_121 = 0 ;
const char * V_174 , * V_65 ;
if ( ! F_25 ( V_39 ) ) {
V_174 = L_55 ;
V_65 = L_56 V_175 ;
} else {
V_174 = L_57 ;
V_65 = L_56 V_176 L_58 V_177 ;
}
#define F_124 (len ? len - pos : 0)
V_121 += snprintf ( V_114 + V_121 , F_124 , L_59 , V_174 ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ ) {
V_121 += snprintf ( V_114 + V_121 , F_124 , L_47 ,
V_39 -> args [ V_27 ] . V_6 , V_39 -> args [ V_27 ] . type -> V_174 ) ;
}
V_121 += snprintf ( V_114 + V_121 , F_124 , L_60 , V_65 ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ ) {
if ( strcmp ( V_39 -> args [ V_27 ] . type -> V_6 , L_61 ) == 0 )
V_121 += snprintf ( V_114 + V_121 , F_124 ,
L_62 ,
V_39 -> args [ V_27 ] . V_6 ) ;
else
V_121 += snprintf ( V_114 + V_121 , F_124 , L_63 ,
V_39 -> args [ V_27 ] . V_6 ) ;
}
#undef F_124
return V_121 ;
}
static int F_125 ( struct V_38 * V_39 )
{
int V_8 ;
char * V_178 ;
V_8 = F_123 ( V_39 , NULL , 0 ) ;
V_178 = F_96 ( V_8 + 1 , V_21 ) ;
if ( ! V_178 )
return - V_55 ;
F_123 ( V_39 , V_178 , V_8 + 1 ) ;
V_39 -> V_61 . V_178 = V_178 ;
return 0 ;
}
static T_2 void F_126 ( struct V_143 * V_42 ,
struct V_11 * V_12 )
{
struct V_38 * V_39 = F_107 ( V_42 , struct V_38 , V_40 . V_42 ) ;
struct V_151 * V_61 = & V_39 -> V_61 ;
struct V_144 * V_145 ;
struct V_179 * V_180 ;
int V_103 , V_181 , V_148 ;
int V_182 ;
V_148 = F_100 ( V_39 , V_12 ) ;
V_181 = sizeof( * V_145 ) + V_39 -> V_103 + V_148 ;
V_103 = F_127 ( V_181 + sizeof( T_1 ) , sizeof( V_183 ) ) ;
V_103 -= sizeof( T_1 ) ;
if ( F_128 ( V_103 > V_184 ,
L_64 ) )
return;
V_145 = F_129 ( V_103 , V_61 -> V_50 . type , V_12 , & V_182 ) ;
if ( ! V_145 )
return;
V_145 -> V_152 = ( unsigned long ) V_42 -> V_17 ;
memset ( & V_145 [ 1 ] , 0 , V_148 ) ;
F_102 ( sizeof( * V_145 ) , V_39 , V_12 , ( V_2 * ) & V_145 [ 1 ] , V_148 ) ;
V_180 = F_130 ( V_61 -> V_185 ) ;
F_131 ( V_145 , V_103 , V_182 , V_145 -> V_152 , 1 , V_12 , V_180 ) ;
}
static T_2 void F_132 ( struct V_153 * V_154 ,
struct V_11 * V_12 )
{
struct V_38 * V_39 = F_107 ( V_154 -> V_40 , struct V_38 , V_40 ) ;
struct V_151 * V_61 = & V_39 -> V_61 ;
struct V_155 * V_145 ;
struct V_179 * V_180 ;
int V_103 , V_181 , V_148 ;
int V_182 ;
V_148 = F_100 ( V_39 , V_12 ) ;
V_181 = sizeof( * V_145 ) + V_39 -> V_103 + V_148 ;
V_103 = F_127 ( V_181 + sizeof( T_1 ) , sizeof( V_183 ) ) ;
V_103 -= sizeof( T_1 ) ;
if ( F_128 ( V_103 > V_184 ,
L_64 ) )
return;
V_145 = F_129 ( V_103 , V_61 -> V_50 . type , V_12 , & V_182 ) ;
if ( ! V_145 )
return;
V_145 -> V_156 = ( unsigned long ) V_39 -> V_40 . V_42 . V_17 ;
V_145 -> V_157 = ( unsigned long ) V_154 -> V_158 ;
F_102 ( sizeof( * V_145 ) , V_39 , V_12 , ( V_2 * ) & V_145 [ 1 ] , V_148 ) ;
V_180 = F_130 ( V_61 -> V_185 ) ;
F_131 ( V_145 , V_103 , V_182 , V_145 -> V_157 , 1 , V_12 , V_180 ) ;
}
static T_2
int F_133 ( struct V_151 * V_50 ,
enum V_186 type , void * V_7 )
{
struct V_38 * V_39 = (struct V_38 * ) V_50 -> V_7 ;
switch ( type ) {
case V_187 :
return F_44 ( V_39 , V_44 ) ;
case V_188 :
F_47 ( V_39 , V_44 ) ;
return 0 ;
#ifdef F_134
case V_189 :
return F_44 ( V_39 , V_45 ) ;
case V_190 :
F_47 ( V_39 , V_45 ) ;
return 0 ;
case V_191 :
case V_192 :
case V_193 :
case V_194 :
return 0 ;
#endif
}
return 0 ;
}
static T_2
int V_59 ( struct V_143 * V_42 , struct V_11 * V_12 )
{
struct V_38 * V_39 = F_107 ( V_42 , struct V_38 , V_40 . V_42 ) ;
if ( V_39 -> V_43 & V_44 )
F_106 ( V_42 , V_12 ) ;
#ifdef F_134
if ( V_39 -> V_43 & V_45 )
F_126 ( V_42 , V_12 ) ;
#endif
return 0 ;
}
static T_2
int V_57 ( struct V_153 * V_154 , struct V_11 * V_12 )
{
struct V_38 * V_39 = F_107 ( V_154 -> V_40 , struct V_38 , V_40 ) ;
if ( V_39 -> V_43 & V_44 )
F_114 ( V_154 , V_12 ) ;
#ifdef F_134
if ( V_39 -> V_43 & V_45 )
F_132 ( V_154 , V_12 ) ;
#endif
return 0 ;
}
static int F_62 ( struct V_38 * V_39 )
{
struct V_151 * V_61 = & V_39 -> V_61 ;
int V_54 ;
F_38 ( & V_61 -> V_62 -> V_195 ) ;
if ( F_25 ( V_39 ) ) {
V_61 -> V_50 . V_196 = & V_197 ;
V_61 -> V_62 -> V_198 = F_122 ;
} else {
V_61 -> V_50 . V_196 = & V_199 ;
V_61 -> V_62 -> V_198 = F_119 ;
}
if ( F_125 ( V_39 ) < 0 )
return - V_55 ;
V_54 = F_135 ( & V_61 -> V_50 ) ;
if ( ! V_54 ) {
F_9 ( V_61 -> V_178 ) ;
return - V_200 ;
}
V_61 -> V_43 = 0 ;
V_61 -> V_62 -> V_201 = F_133 ;
V_61 -> V_7 = V_39 ;
V_54 = F_136 ( V_61 ) ;
if ( V_54 ) {
F_71 ( L_65 , V_61 -> V_6 ) ;
F_9 ( V_61 -> V_178 ) ;
F_137 ( & V_61 -> V_50 ) ;
}
return V_54 ;
}
static void F_59 ( struct V_38 * V_39 )
{
F_138 ( & V_39 -> V_61 ) ;
F_9 ( V_39 -> V_61 . V_178 ) ;
}
static T_9 int F_139 ( void )
{
struct V_202 * V_203 ;
struct V_202 * V_145 ;
if ( F_140 ( & V_204 ) )
return - V_60 ;
V_203 = F_141 () ;
if ( ! V_203 )
return 0 ;
V_145 = F_142 ( L_66 , 0644 , V_203 ,
NULL , & V_205 ) ;
if ( ! V_145 )
F_53 ( L_67
L_68 ) ;
V_145 = F_142 ( L_69 , 0444 , V_203 ,
NULL , & V_206 ) ;
if ( ! V_145 )
F_53 ( L_67
L_70 ) ;
return 0 ;
}
static T_10 int F_143 ( int V_207 , int V_208 , int V_209 ,
int V_210 , int V_211 , int V_212 )
{
return V_207 + V_208 + V_209 + V_210 + V_211 + V_212 ;
}
static T_9 int F_144 ( void )
{
int V_54 , V_213 = 0 ;
int (* F_145)( int , int , int , int , int , int );
struct V_38 * V_39 ;
F_145 = F_143 ;
F_71 ( L_71 ) ;
V_54 = F_92 ( L_72
L_73 ) ;
if ( F_146 ( V_54 ) ) {
F_53 ( L_74 ) ;
V_213 ++ ;
} else {
V_39 = F_42 ( L_75 , V_116 ) ;
if ( F_146 ( V_39 == NULL ) ) {
F_53 ( L_76 ) ;
V_213 ++ ;
} else
F_44 ( V_39 , V_44 ) ;
}
V_54 = F_92 ( L_77
L_78 ) ;
if ( F_146 ( V_54 ) ) {
F_53 ( L_79 ) ;
V_213 ++ ;
} else {
V_39 = F_42 ( L_80 , V_116 ) ;
if ( F_146 ( V_39 == NULL ) ) {
F_53 ( L_76 ) ;
V_213 ++ ;
} else
F_44 ( V_39 , V_44 ) ;
}
if ( V_213 )
goto V_76;
V_54 = F_145 ( 1 , 2 , 3 , 4 , 5 , 6 ) ;
V_39 = F_42 ( L_75 , V_116 ) ;
if ( F_146 ( V_39 == NULL ) ) {
F_53 ( L_81 ) ;
V_213 ++ ;
} else
F_47 ( V_39 , V_44 ) ;
V_39 = F_42 ( L_80 , V_116 ) ;
if ( F_146 ( V_39 == NULL ) ) {
F_53 ( L_82 ) ;
V_213 ++ ;
} else
F_47 ( V_39 , V_44 ) ;
V_54 = F_92 ( L_83 ) ;
if ( F_146 ( V_54 ) ) {
F_53 ( L_84 ) ;
V_213 ++ ;
}
V_54 = F_92 ( L_85 ) ;
if ( F_146 ( V_54 ) ) {
F_53 ( L_84 ) ;
V_213 ++ ;
}
V_76:
F_80 () ;
if ( V_213 )
F_147 ( L_86 ) ;
else
F_147 ( L_87 ) ;
return 0 ;
}

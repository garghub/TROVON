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
static void F_57 ( struct V_38 * V_39 )
{
F_54 ( V_39 ) ;
F_58 ( & V_39 -> V_63 ) ;
F_59 ( V_39 ) ;
}
static int F_60 ( struct V_38 * V_39 )
{
struct V_38 * V_73 ;
int V_54 ;
F_61 ( & V_74 ) ;
V_73 = F_42 ( V_39 -> V_61 . V_6 , V_39 -> V_61 . V_62 -> system ) ;
if ( V_73 ) {
F_57 ( V_73 ) ;
F_41 ( V_73 ) ;
}
V_54 = F_62 ( V_39 ) ;
if ( V_54 ) {
F_53 ( L_13 , V_54 ) ;
goto V_75;
}
V_54 = F_50 ( V_39 ) ;
if ( V_54 < 0 )
F_59 ( V_39 ) ;
else
F_63 ( & V_39 -> V_63 , & V_76 ) ;
V_75:
F_64 ( & V_74 ) ;
return V_54 ;
}
static int F_65 ( struct V_77 * V_78 ,
unsigned long V_79 , void * V_7 )
{
struct V_47 * V_48 = V_7 ;
struct V_38 * V_39 ;
int V_54 ;
if ( V_79 != V_80 )
return V_81 ;
F_61 ( & V_74 ) ;
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
F_64 ( & V_74 ) ;
return V_81 ;
}
static int F_66 ( char * V_18 , unsigned long * V_19 )
{
char * V_82 ;
int V_54 ;
if ( ! V_19 )
return - V_60 ;
V_82 = strchr ( V_18 , '+' ) ;
if ( V_82 ) {
V_54 = F_19 ( V_82 + 1 , 0 , V_19 ) ;
if ( V_54 )
return V_54 ;
* V_82 = '\0' ;
} else
* V_19 = 0 ;
return 0 ;
}
static int F_67 ( char * V_65 , const struct V_26 * V_83 ,
struct V_9 * V_84 , int V_53 )
{
int V_54 = 0 ;
unsigned long V_85 ;
if ( strcmp ( V_65 , L_16 ) == 0 ) {
if ( V_53 )
V_84 -> V_14 = V_83 -> V_36 [ V_86 ] ;
else
V_54 = - V_60 ;
} else if ( strncmp ( V_65 , L_17 , 5 ) == 0 ) {
if ( V_65 [ 5 ] == '\0' ) {
if ( strcmp ( V_83 -> V_6 , V_28 ) == 0 )
V_84 -> V_14 = F_21 ;
else
V_54 = - V_60 ;
} else if ( isdigit ( V_65 [ 5 ] ) ) {
V_54 = F_19 ( V_65 + 5 , 10 , & V_85 ) ;
if ( V_54 || V_85 > V_87 )
V_54 = - V_60 ;
else {
V_84 -> V_14 = V_83 -> V_36 [ V_88 ] ;
V_84 -> V_7 = ( void * ) V_85 ;
}
} else
V_54 = - V_60 ;
} else
V_54 = - V_60 ;
return V_54 ;
}
static int F_68 ( char * V_65 , const struct V_26 * V_83 ,
struct V_9 * V_84 , int V_53 )
{
int V_54 = 0 ;
unsigned long V_85 ;
long V_19 ;
char * V_82 ;
switch ( V_65 [ 0 ] ) {
case '$' :
V_54 = F_67 ( V_65 + 1 , V_83 , V_84 , V_53 ) ;
break;
case '%' :
V_54 = F_69 ( V_65 + 1 ) ;
if ( V_54 >= 0 ) {
V_84 -> V_14 = V_83 -> V_36 [ V_89 ] ;
V_84 -> V_7 = ( void * ) ( unsigned long ) V_54 ;
V_54 = 0 ;
}
break;
case '@' :
if ( isdigit ( V_65 [ 1 ] ) ) {
V_54 = F_19 ( V_65 + 1 , 0 , & V_85 ) ;
if ( V_54 )
break;
V_84 -> V_14 = V_83 -> V_36 [ V_90 ] ;
V_84 -> V_7 = ( void * ) V_85 ;
} else {
V_54 = F_66 ( V_65 + 1 , & V_19 ) ;
if ( V_54 )
break;
V_84 -> V_7 = F_10 ( V_65 + 1 , V_19 ) ;
if ( V_84 -> V_7 )
V_84 -> V_14 = V_83 -> V_36 [ V_91 ] ;
}
break;
case '+' :
V_65 ++ ;
case '-' :
V_82 = strchr ( V_65 , '(' ) ;
if ( ! V_82 )
break;
* V_82 = '\0' ;
V_54 = F_70 ( V_65 , 0 , & V_19 ) ;
if ( V_54 )
break;
V_65 = V_82 + 1 ;
V_82 = strrchr ( V_65 , ')' ) ;
if ( V_82 ) {
struct V_22 * V_92 ;
const struct V_26 * V_93 = F_18 ( NULL ) ;
* V_82 = '\0' ;
V_92 = F_11 ( sizeof( struct V_22 ) ,
V_21 ) ;
if ( ! V_92 )
return - V_55 ;
V_92 -> V_19 = V_19 ;
V_54 = F_68 ( V_65 , V_93 , & V_92 -> V_24 ,
V_53 ) ;
if ( V_54 )
F_9 ( V_92 ) ;
else {
V_84 -> V_14 = V_83 -> V_36 [ V_94 ] ;
V_84 -> V_7 = ( void * ) V_92 ;
}
}
break;
}
if ( ! V_54 && ! V_84 -> V_14 ) {
F_71 ( L_18 ,
V_83 -> V_6 ) ;
V_54 = - V_60 ;
}
return V_54 ;
}
static int F_72 ( const char * V_95 ,
const struct V_26 * V_83 ,
struct V_9 * V_84 )
{
struct V_25 * V_96 ;
unsigned long V_97 , V_98 ;
char * V_99 ;
if ( * V_95 != 'b' )
return 0 ;
V_96 = F_11 ( sizeof( * V_96 ) , V_21 ) ;
if ( ! V_96 )
return - V_55 ;
V_96 -> V_24 = * V_84 ;
V_84 -> V_14 = V_83 -> V_36 [ V_100 ] ;
V_84 -> V_7 = ( void * ) V_96 ;
V_97 = F_73 ( V_95 + 1 , & V_99 , 0 ) ;
if ( V_97 == 0 || * V_99 != '@' )
return - V_60 ;
V_95 = V_99 + 1 ;
V_98 = F_73 ( V_95 , & V_99 , 0 ) ;
if ( V_99 == V_95 || * V_99 != '/' )
return - V_60 ;
V_96 -> V_101 = F_74 ( V_83 -> V_102 ) - ( V_97 + V_98 ) ;
V_96 -> V_103 = V_96 -> V_101 + V_98 ;
return ( F_74 ( V_83 -> V_102 ) < ( V_97 + V_98 ) ) ? - V_60 : 0 ;
}
static int F_75 ( char * V_65 , struct V_38 * V_39 ,
struct V_64 * V_104 , int V_53 )
{
const char * V_83 ;
int V_54 ;
if ( strlen ( V_65 ) > V_105 ) {
F_71 ( L_19 , V_65 ) ;
return - V_106 ;
}
V_104 -> V_67 = F_12 ( V_65 , V_21 ) ;
if ( ! V_104 -> V_67 ) {
F_71 ( L_20 , V_65 ) ;
return - V_55 ;
}
V_83 = strchr ( V_104 -> V_67 , ':' ) ;
if ( V_83 ) {
V_65 [ V_83 - V_104 -> V_67 ] = '\0' ;
V_83 ++ ;
}
V_104 -> type = F_18 ( V_83 ) ;
if ( ! V_104 -> type ) {
F_71 ( L_21 , V_83 ) ;
return - V_60 ;
}
V_104 -> V_19 = V_39 -> V_102 ;
V_39 -> V_102 += V_104 -> type -> V_102 ;
V_54 = F_68 ( V_65 , V_104 -> type , & V_104 -> V_36 , V_53 ) ;
if ( V_54 >= 0 && V_83 != NULL )
V_54 = F_72 ( V_83 , V_104 -> type , & V_104 -> V_36 ) ;
if ( V_54 >= 0 ) {
V_104 -> V_107 . V_14 = F_23 ( V_104 -> type ,
V_104 -> V_36 . V_14 ) ;
V_104 -> V_107 . V_7 = V_104 -> V_36 . V_7 ;
}
return V_54 ;
}
static int F_76 ( const char * V_6 ,
struct V_64 * args , int V_108 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < F_20 ( V_109 ) ; V_27 ++ )
if ( strcmp ( V_109 [ V_27 ] , V_6 ) == 0 )
return 1 ;
for ( V_27 = 0 ; V_27 < V_108 ; V_27 ++ )
if ( strcmp ( args [ V_27 ] . V_6 , V_6 ) == 0 )
return 1 ;
return 0 ;
}
static int F_77 ( int V_110 , char * * V_111 )
{
struct V_38 * V_39 ;
int V_27 , V_54 = 0 ;
int V_53 = 0 , V_112 = 0 ;
char * V_18 = NULL , * V_50 = NULL , * V_49 = NULL ;
char * V_65 ;
unsigned long V_19 = 0 ;
void * V_17 = NULL ;
char V_113 [ V_114 ] ;
if ( V_111 [ 0 ] [ 0 ] == 'p' )
V_53 = 0 ;
else if ( V_111 [ 0 ] [ 0 ] == 'r' )
V_53 = 1 ;
else if ( V_111 [ 0 ] [ 0 ] == '-' )
V_112 = 1 ;
else {
F_71 ( L_22
L_23 ) ;
return - V_60 ;
}
if ( V_111 [ 0 ] [ 1 ] == ':' ) {
V_50 = & V_111 [ 0 ] [ 2 ] ;
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
V_49 = V_115 ;
if ( V_112 ) {
if ( ! V_50 ) {
F_71 ( L_26 ) ;
return - V_60 ;
}
F_61 ( & V_74 ) ;
V_39 = F_42 ( V_50 , V_49 ) ;
if ( ! V_39 ) {
F_64 ( & V_74 ) ;
F_71 ( L_27 , V_49 , V_50 ) ;
return - V_71 ;
}
F_57 ( V_39 ) ;
F_41 ( V_39 ) ;
F_64 ( & V_74 ) ;
return 0 ;
}
if ( V_110 < 2 ) {
F_71 ( L_28 ) ;
return - V_60 ;
}
if ( isdigit ( V_111 [ 1 ] [ 0 ] ) ) {
if ( V_53 ) {
F_71 ( L_29 ) ;
return - V_60 ;
}
V_54 = F_19 ( & V_111 [ 1 ] [ 0 ] , 0 , ( unsigned long * ) & V_17 ) ;
if ( V_54 ) {
F_71 ( L_30 ) ;
return V_54 ;
}
} else {
V_18 = V_111 [ 1 ] ;
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
V_110 -= 2 ; V_111 += 2 ;
if ( ! V_50 ) {
if ( V_18 )
snprintf ( V_113 , V_114 , L_33 ,
V_53 ? 'r' : 'p' , V_18 , V_19 ) ;
else
snprintf ( V_113 , V_114 , L_34 ,
V_53 ? 'r' : 'p' , V_17 ) ;
V_50 = V_113 ;
}
V_39 = F_35 ( V_49 , V_50 , V_17 , V_18 , V_19 , V_110 ,
V_53 ) ;
if ( F_78 ( V_39 ) ) {
F_71 ( L_35 ,
( int ) F_79 ( V_39 ) ) ;
return F_79 ( V_39 ) ;
}
V_54 = 0 ;
for ( V_27 = 0 ; V_27 < V_110 && V_27 < V_116 ; V_27 ++ ) {
V_39 -> V_68 ++ ;
V_65 = strchr ( V_111 [ V_27 ] , '=' ) ;
if ( V_65 ) {
* V_65 ++ = '\0' ;
V_39 -> args [ V_27 ] . V_6 = F_12 ( V_111 [ V_27 ] , V_21 ) ;
} else {
V_65 = V_111 [ V_27 ] ;
snprintf ( V_113 , V_114 , L_36 , V_27 + 1 ) ;
V_39 -> args [ V_27 ] . V_6 = F_12 ( V_113 , V_21 ) ;
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
L_40 , V_27 , V_111 [ V_27 ] ) ;
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
static void F_80 ( void )
{
struct V_38 * V_39 ;
F_61 ( & V_74 ) ;
while ( ! F_81 ( & V_76 ) ) {
V_39 = F_82 ( V_76 . V_117 , struct V_38 , V_63 ) ;
F_57 ( V_39 ) ;
F_41 ( V_39 ) ;
}
F_64 ( & V_74 ) ;
}
static void * F_83 ( struct V_118 * V_119 , T_5 * V_120 )
{
F_61 ( & V_74 ) ;
return F_84 ( & V_76 , * V_120 ) ;
}
static void * F_85 ( struct V_118 * V_119 , void * V_121 , T_5 * V_120 )
{
return F_86 ( V_121 , & V_76 , V_120 ) ;
}
static void F_87 ( struct V_118 * V_119 , void * V_121 )
{
F_64 ( & V_74 ) ;
}
static int F_88 ( struct V_118 * V_119 , void * V_121 )
{
struct V_38 * V_39 = V_121 ;
int V_27 ;
F_89 ( V_119 , L_42 , F_25 ( V_39 ) ? 'r' : 'p' ) ;
F_89 ( V_119 , L_43 , V_39 -> V_61 . V_62 -> system , V_39 -> V_61 . V_6 ) ;
if ( ! V_39 -> V_18 )
F_89 ( V_119 , L_44 , V_39 -> V_40 . V_42 . V_17 ) ;
else if ( V_39 -> V_40 . V_42 . V_19 )
F_89 ( V_119 , L_45 , F_26 ( V_39 ) ,
V_39 -> V_40 . V_42 . V_19 ) ;
else
F_89 ( V_119 , L_46 , F_26 ( V_39 ) ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ )
F_89 ( V_119 , L_47 , V_39 -> args [ V_27 ] . V_6 , V_39 -> args [ V_27 ] . V_67 ) ;
F_89 ( V_119 , L_48 ) ;
return 0 ;
}
static int F_90 ( struct V_122 * V_122 , struct V_123 * V_123 )
{
if ( ( V_123 -> V_124 & V_125 ) &&
( V_123 -> V_126 & V_127 ) )
F_80 () ;
return F_91 ( V_123 , & V_128 ) ;
}
static int F_92 ( const char * V_113 )
{
char * * V_111 ;
int V_110 = 0 , V_54 = 0 ;
V_111 = F_93 ( V_21 , V_113 , & V_110 ) ;
if ( ! V_111 )
return - V_55 ;
if ( V_110 )
V_54 = F_77 ( V_110 , V_111 ) ;
F_94 ( V_111 ) ;
return V_54 ;
}
static T_6 F_95 ( struct V_123 * V_123 , const char T_7 * V_129 ,
T_8 V_130 , T_5 * V_131 )
{
char * V_132 , * V_82 ;
int V_54 ;
T_8 V_133 ;
T_8 V_102 ;
V_132 = F_96 ( V_134 , V_21 ) ;
if ( ! V_132 )
return - V_55 ;
V_54 = V_133 = 0 ;
while ( V_133 < V_130 ) {
V_102 = V_130 - V_133 ;
if ( V_102 >= V_134 )
V_102 = V_134 - 1 ;
if ( F_97 ( V_132 , V_129 + V_133 , V_102 ) ) {
V_54 = - V_135 ;
goto V_136;
}
V_132 [ V_102 ] = '\0' ;
V_82 = strchr ( V_132 , '\n' ) ;
if ( V_82 ) {
* V_82 = '\0' ;
V_102 = V_82 - V_132 + 1 ;
} else if ( V_133 + V_102 < V_130 ) {
F_53 ( L_49
L_50 , V_134 ) ;
V_54 = - V_60 ;
goto V_136;
}
V_133 += V_102 ;
V_82 = strchr ( V_132 , '#' ) ;
if ( V_82 )
* V_82 = '\0' ;
V_54 = F_92 ( V_132 ) ;
if ( V_54 )
goto V_136;
}
V_54 = V_133 ;
V_136:
F_9 ( V_132 ) ;
return V_54 ;
}
static int F_98 ( struct V_118 * V_119 , void * V_121 )
{
struct V_38 * V_39 = V_121 ;
F_89 ( V_119 , L_51 , V_39 -> V_61 . V_6 , V_39 -> V_137 ,
V_39 -> V_40 . V_42 . V_138 ) ;
return 0 ;
}
static int F_99 ( struct V_122 * V_122 , struct V_123 * V_123 )
{
return F_91 ( V_123 , & V_139 ) ;
}
static T_2 int F_100 ( struct V_38 * V_39 ,
struct V_11 * V_12 )
{
int V_27 , V_54 = 0 ;
T_1 V_8 ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ )
if ( F_101 ( V_39 -> args [ V_27 ] . V_107 . V_14 ) ) {
F_5 ( & V_39 -> args [ V_27 ] . V_107 , V_12 , & V_8 ) ;
V_54 += V_8 ;
}
return V_54 ;
}
static T_2 void F_102 ( int V_140 , struct V_38 * V_39 ,
struct V_11 * V_12 ,
V_2 * V_7 , int V_141 )
{
int V_27 ;
T_1 V_75 = V_39 -> V_102 ;
T_1 * V_1 ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ ) {
if ( F_101 ( V_39 -> args [ V_27 ] . V_107 . V_14 ) ) {
V_1 = ( T_1 * ) ( V_7 + V_39 -> args [ V_27 ] . V_19 ) ;
* V_1 = F_103 ( V_141 , V_75 - V_39 -> args [ V_27 ] . V_19 ) ;
F_5 ( & V_39 -> args [ V_27 ] . V_36 , V_12 , V_1 ) ;
V_75 += F_104 ( * V_1 ) ;
V_141 -= F_104 ( * V_1 ) ;
* V_1 = F_105 ( * V_1 ,
V_140 + V_39 -> args [ V_27 ] . V_19 ) ;
} else
F_5 ( & V_39 -> args [ V_27 ] . V_36 , V_12 ,
V_7 + V_39 -> args [ V_27 ] . V_19 ) ;
}
}
static T_2 void F_106 ( struct V_142 * V_42 , struct V_11 * V_12 )
{
struct V_38 * V_39 = F_107 ( V_42 , struct V_38 , V_40 . V_42 ) ;
struct V_143 * V_144 ;
struct V_145 * V_50 ;
struct V_146 * V_129 ;
int V_102 , V_147 , V_148 ;
unsigned long V_149 ;
struct V_150 * V_61 = & V_39 -> V_61 ;
V_39 -> V_137 ++ ;
F_108 ( V_149 ) ;
V_148 = F_109 () ;
V_147 = F_100 ( V_39 , V_12 ) ;
V_102 = sizeof( * V_144 ) + V_39 -> V_102 + V_147 ;
V_50 = F_110 ( & V_129 , V_61 -> V_50 . type ,
V_102 , V_149 , V_148 ) ;
if ( ! V_50 )
return;
V_144 = F_111 ( V_50 ) ;
V_144 -> V_151 = ( unsigned long ) V_42 -> V_17 ;
F_102 ( sizeof( * V_144 ) , V_39 , V_12 , ( V_2 * ) & V_144 [ 1 ] , V_147 ) ;
if ( ! F_112 ( V_129 , V_61 , V_144 , V_50 ) )
F_113 ( V_129 , V_50 ,
V_149 , V_148 , V_12 ) ;
}
static T_2 void F_114 ( struct V_152 * V_153 ,
struct V_11 * V_12 )
{
struct V_38 * V_39 = F_107 ( V_153 -> V_40 , struct V_38 , V_40 ) ;
struct V_154 * V_144 ;
struct V_145 * V_50 ;
struct V_146 * V_129 ;
int V_102 , V_148 , V_147 ;
unsigned long V_149 ;
struct V_150 * V_61 = & V_39 -> V_61 ;
F_108 ( V_149 ) ;
V_148 = F_109 () ;
V_147 = F_100 ( V_39 , V_12 ) ;
V_102 = sizeof( * V_144 ) + V_39 -> V_102 + V_147 ;
V_50 = F_110 ( & V_129 , V_61 -> V_50 . type ,
V_102 , V_149 , V_148 ) ;
if ( ! V_50 )
return;
V_144 = F_111 ( V_50 ) ;
V_144 -> V_155 = ( unsigned long ) V_39 -> V_40 . V_42 . V_17 ;
V_144 -> V_156 = ( unsigned long ) V_153 -> V_157 ;
F_102 ( sizeof( * V_144 ) , V_39 , V_12 , ( V_2 * ) & V_144 [ 1 ] , V_147 ) ;
if ( ! F_112 ( V_129 , V_61 , V_144 , V_50 ) )
F_113 ( V_129 , V_50 ,
V_149 , V_148 , V_12 ) ;
}
enum V_158
F_115 ( struct V_159 * V_160 , int V_43 ,
struct V_161 * V_50 )
{
struct V_143 * V_162 ;
struct V_4 * V_5 = & V_160 -> V_163 ;
struct V_38 * V_39 ;
V_2 * V_7 ;
int V_27 ;
V_162 = (struct V_143 * ) V_160 -> V_3 ;
V_39 = F_107 ( V_50 , struct V_38 , V_61 . V_50 ) ;
if ( ! F_4 ( V_5 , L_52 , V_39 -> V_61 . V_6 ) )
goto V_164;
if ( ! F_116 ( V_5 , V_162 -> V_151 , V_43 | V_165 ) )
goto V_164;
if ( ! F_117 ( V_5 , L_53 ) )
goto V_164;
V_7 = ( V_2 * ) & V_162 [ 1 ] ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ )
if ( ! V_39 -> args [ V_27 ] . type -> V_166 ( V_5 , V_39 -> args [ V_27 ] . V_6 ,
V_7 + V_39 -> args [ V_27 ] . V_19 , V_162 ) )
goto V_164;
if ( ! F_117 ( V_5 , L_48 ) )
goto V_164;
return V_167 ;
V_164:
return V_168 ;
}
enum V_158
F_118 ( struct V_159 * V_160 , int V_43 ,
struct V_161 * V_50 )
{
struct V_154 * V_162 ;
struct V_4 * V_5 = & V_160 -> V_163 ;
struct V_38 * V_39 ;
V_2 * V_7 ;
int V_27 ;
V_162 = (struct V_154 * ) V_160 -> V_3 ;
V_39 = F_107 ( V_50 , struct V_38 , V_61 . V_50 ) ;
if ( ! F_4 ( V_5 , L_52 , V_39 -> V_61 . V_6 ) )
goto V_164;
if ( ! F_116 ( V_5 , V_162 -> V_156 , V_43 | V_165 ) )
goto V_164;
if ( ! F_117 ( V_5 , L_54 ) )
goto V_164;
if ( ! F_116 ( V_5 , V_162 -> V_155 , V_43 & ~ V_165 ) )
goto V_164;
if ( ! F_117 ( V_5 , L_53 ) )
goto V_164;
V_7 = ( V_2 * ) & V_162 [ 1 ] ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ )
if ( ! V_39 -> args [ V_27 ] . type -> V_166 ( V_5 , V_39 -> args [ V_27 ] . V_6 ,
V_7 + V_39 -> args [ V_27 ] . V_19 , V_162 ) )
goto V_164;
if ( ! F_117 ( V_5 , L_48 ) )
goto V_164;
return V_167 ;
V_164:
return V_168 ;
}
static int F_119 ( struct V_150 * V_169 )
{
int V_54 , V_27 ;
struct V_143 V_162 ;
struct V_38 * V_39 = (struct V_38 * ) V_169 -> V_7 ;
F_120 (unsigned long, ip, FIELD_STRING_IP, 0 ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ ) {
V_54 = F_121 ( V_169 , V_39 -> args [ V_27 ] . type -> V_170 ,
V_39 -> args [ V_27 ] . V_6 ,
sizeof( V_162 ) + V_39 -> args [ V_27 ] . V_19 ,
V_39 -> args [ V_27 ] . type -> V_102 ,
V_39 -> args [ V_27 ] . type -> V_171 ,
V_172 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_122 ( struct V_150 * V_169 )
{
int V_54 , V_27 ;
struct V_154 V_162 ;
struct V_38 * V_39 = (struct V_38 * ) V_169 -> V_7 ;
F_120 (unsigned long, func, FIELD_STRING_FUNC, 0 ) ;
F_120 (unsigned long, ret_ip, FIELD_STRING_RETIP, 0 ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ ) {
V_54 = F_121 ( V_169 , V_39 -> args [ V_27 ] . type -> V_170 ,
V_39 -> args [ V_27 ] . V_6 ,
sizeof( V_162 ) + V_39 -> args [ V_27 ] . V_19 ,
V_39 -> args [ V_27 ] . type -> V_102 ,
V_39 -> args [ V_27 ] . type -> V_171 ,
V_172 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_123 ( struct V_38 * V_39 , char * V_113 , int V_8 )
{
int V_27 ;
int V_120 = 0 ;
const char * V_173 , * V_65 ;
if ( ! F_25 ( V_39 ) ) {
V_173 = L_55 ;
V_65 = L_56 V_174 ;
} else {
V_173 = L_57 ;
V_65 = L_56 V_175 L_58 V_176 ;
}
#define F_124 (len ? len - pos : 0)
V_120 += snprintf ( V_113 + V_120 , F_124 , L_59 , V_173 ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ ) {
V_120 += snprintf ( V_113 + V_120 , F_124 , L_47 ,
V_39 -> args [ V_27 ] . V_6 , V_39 -> args [ V_27 ] . type -> V_173 ) ;
}
V_120 += snprintf ( V_113 + V_120 , F_124 , L_60 , V_65 ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_68 ; V_27 ++ ) {
if ( strcmp ( V_39 -> args [ V_27 ] . type -> V_6 , L_61 ) == 0 )
V_120 += snprintf ( V_113 + V_120 , F_124 ,
L_62 ,
V_39 -> args [ V_27 ] . V_6 ) ;
else
V_120 += snprintf ( V_113 + V_120 , F_124 , L_63 ,
V_39 -> args [ V_27 ] . V_6 ) ;
}
#undef F_124
return V_120 ;
}
static int F_125 ( struct V_38 * V_39 )
{
int V_8 ;
char * V_177 ;
V_8 = F_123 ( V_39 , NULL , 0 ) ;
V_177 = F_96 ( V_8 + 1 , V_21 ) ;
if ( ! V_177 )
return - V_55 ;
F_123 ( V_39 , V_177 , V_8 + 1 ) ;
V_39 -> V_61 . V_177 = V_177 ;
return 0 ;
}
static T_2 void F_126 ( struct V_142 * V_42 ,
struct V_11 * V_12 )
{
struct V_38 * V_39 = F_107 ( V_42 , struct V_38 , V_40 . V_42 ) ;
struct V_150 * V_61 = & V_39 -> V_61 ;
struct V_143 * V_144 ;
struct V_178 * V_179 ;
int V_102 , V_180 , V_147 ;
int V_181 ;
V_147 = F_100 ( V_39 , V_12 ) ;
V_180 = sizeof( * V_144 ) + V_39 -> V_102 + V_147 ;
V_102 = F_127 ( V_180 + sizeof( T_1 ) , sizeof( V_182 ) ) ;
V_102 -= sizeof( T_1 ) ;
if ( F_128 ( V_102 > V_183 ,
L_64 ) )
return;
V_144 = F_129 ( V_102 , V_61 -> V_50 . type , V_12 , & V_181 ) ;
if ( ! V_144 )
return;
V_144 -> V_151 = ( unsigned long ) V_42 -> V_17 ;
memset ( & V_144 [ 1 ] , 0 , V_147 ) ;
F_102 ( sizeof( * V_144 ) , V_39 , V_12 , ( V_2 * ) & V_144 [ 1 ] , V_147 ) ;
V_179 = F_130 ( V_61 -> V_184 ) ;
F_131 ( V_144 , V_102 , V_181 , V_144 -> V_151 , 1 , V_12 , V_179 ) ;
}
static T_2 void F_132 ( struct V_152 * V_153 ,
struct V_11 * V_12 )
{
struct V_38 * V_39 = F_107 ( V_153 -> V_40 , struct V_38 , V_40 ) ;
struct V_150 * V_61 = & V_39 -> V_61 ;
struct V_154 * V_144 ;
struct V_178 * V_179 ;
int V_102 , V_180 , V_147 ;
int V_181 ;
V_147 = F_100 ( V_39 , V_12 ) ;
V_180 = sizeof( * V_144 ) + V_39 -> V_102 + V_147 ;
V_102 = F_127 ( V_180 + sizeof( T_1 ) , sizeof( V_182 ) ) ;
V_102 -= sizeof( T_1 ) ;
if ( F_128 ( V_102 > V_183 ,
L_64 ) )
return;
V_144 = F_129 ( V_102 , V_61 -> V_50 . type , V_12 , & V_181 ) ;
if ( ! V_144 )
return;
V_144 -> V_155 = ( unsigned long ) V_39 -> V_40 . V_42 . V_17 ;
V_144 -> V_156 = ( unsigned long ) V_153 -> V_157 ;
F_102 ( sizeof( * V_144 ) , V_39 , V_12 , ( V_2 * ) & V_144 [ 1 ] , V_147 ) ;
V_179 = F_130 ( V_61 -> V_184 ) ;
F_131 ( V_144 , V_102 , V_181 , V_144 -> V_156 , 1 , V_12 , V_179 ) ;
}
static T_2
int F_133 ( struct V_150 * V_50 , enum V_185 type )
{
struct V_38 * V_39 = (struct V_38 * ) V_50 -> V_7 ;
switch ( type ) {
case V_186 :
return F_44 ( V_39 , V_44 ) ;
case V_187 :
F_47 ( V_39 , V_44 ) ;
return 0 ;
#ifdef F_134
case V_188 :
return F_44 ( V_39 , V_45 ) ;
case V_189 :
F_47 ( V_39 , V_45 ) ;
return 0 ;
#endif
}
return 0 ;
}
static T_2
int V_59 ( struct V_142 * V_42 , struct V_11 * V_12 )
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
int V_57 ( struct V_152 * V_153 , struct V_11 * V_12 )
{
struct V_38 * V_39 = F_107 ( V_153 -> V_40 , struct V_38 , V_40 ) ;
if ( V_39 -> V_43 & V_44 )
F_114 ( V_153 , V_12 ) ;
#ifdef F_134
if ( V_39 -> V_43 & V_45 )
F_132 ( V_153 , V_12 ) ;
#endif
return 0 ;
}
static int F_62 ( struct V_38 * V_39 )
{
struct V_150 * V_61 = & V_39 -> V_61 ;
int V_54 ;
F_38 ( & V_61 -> V_62 -> V_190 ) ;
if ( F_25 ( V_39 ) ) {
V_61 -> V_50 . V_191 = & V_192 ;
V_61 -> V_62 -> V_193 = F_122 ;
} else {
V_61 -> V_50 . V_191 = & V_194 ;
V_61 -> V_62 -> V_193 = F_119 ;
}
if ( F_125 ( V_39 ) < 0 )
return - V_55 ;
V_54 = F_135 ( & V_61 -> V_50 ) ;
if ( ! V_54 ) {
F_9 ( V_61 -> V_177 ) ;
return - V_195 ;
}
V_61 -> V_43 = 0 ;
V_61 -> V_62 -> V_196 = F_133 ;
V_61 -> V_7 = V_39 ;
V_54 = F_136 ( V_61 ) ;
if ( V_54 ) {
F_71 ( L_65 , V_61 -> V_6 ) ;
F_9 ( V_61 -> V_177 ) ;
F_137 ( & V_61 -> V_50 ) ;
}
return V_54 ;
}
static void F_59 ( struct V_38 * V_39 )
{
F_138 ( & V_39 -> V_61 ) ;
F_9 ( V_39 -> V_61 . V_177 ) ;
}
static T_9 int F_139 ( void )
{
struct V_197 * V_198 ;
struct V_197 * V_144 ;
if ( F_140 ( & V_199 ) )
return - V_60 ;
V_198 = F_141 () ;
if ( ! V_198 )
return 0 ;
V_144 = F_142 ( L_66 , 0644 , V_198 ,
NULL , & V_200 ) ;
if ( ! V_144 )
F_53 ( L_67
L_68 ) ;
V_144 = F_142 ( L_69 , 0444 , V_198 ,
NULL , & V_201 ) ;
if ( ! V_144 )
F_53 ( L_67
L_70 ) ;
return 0 ;
}
static T_10 int F_143 ( int V_202 , int V_203 , int V_204 ,
int V_205 , int V_206 , int V_207 )
{
return V_202 + V_203 + V_204 + V_205 + V_206 + V_207 ;
}
static T_9 int F_144 ( void )
{
int V_54 , V_208 = 0 ;
int (* F_145)( int , int , int , int , int , int );
struct V_38 * V_39 ;
F_145 = F_143 ;
F_71 ( L_71 ) ;
V_54 = F_92 ( L_72
L_73 ) ;
if ( F_146 ( V_54 ) ) {
F_53 ( L_74 ) ;
V_208 ++ ;
} else {
V_39 = F_42 ( L_75 , V_115 ) ;
if ( F_146 ( V_39 == NULL ) ) {
F_53 ( L_76 ) ;
V_208 ++ ;
} else
F_44 ( V_39 , V_44 ) ;
}
V_54 = F_92 ( L_77
L_78 ) ;
if ( F_146 ( V_54 ) ) {
F_53 ( L_79 ) ;
V_208 ++ ;
} else {
V_39 = F_42 ( L_80 , V_115 ) ;
if ( F_146 ( V_39 == NULL ) ) {
F_53 ( L_76 ) ;
V_208 ++ ;
} else
F_44 ( V_39 , V_44 ) ;
}
if ( V_208 )
goto V_75;
V_54 = F_145 ( 1 , 2 , 3 , 4 , 5 , 6 ) ;
V_54 = F_92 ( L_81 ) ;
if ( F_146 ( V_54 ) ) {
F_53 ( L_82 ) ;
V_208 ++ ;
}
V_54 = F_92 ( L_83 ) ;
if ( F_146 ( V_54 ) ) {
F_53 ( L_82 ) ;
V_208 ++ ;
}
V_75:
F_80 () ;
if ( V_208 )
F_147 ( L_84 ) ;
else
F_147 ( L_85 ) ;
return 0 ;
}

T_1 * F_1 ( void )
{
return NULL ;
}
T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
void * V_3 = NULL ;
char * V_4 = F_3 ( V_2 , NULL ) ;
# if V_5 == 64
# define F_4 _malloc32
# pragma V_6 V_7
# pragma V_6 V_8
# else
# define F_4 OPENSSL_malloc
# endif
T_3 * V_9 = NULL ;
# if V_5 == 64
# pragma V_6 V_10
# endif
const char * V_11 , * V_12 ;
if ( V_4 == NULL ) {
F_5 ( V_13 , V_14 ) ;
goto V_15;
}
V_11 = strrchr ( V_4 , ']' ) ;
V_12 = strrchr ( V_4 , '>' ) ;
if ( V_11 == NULL )
V_11 = V_12 ;
if ( V_12 != NULL && V_12 > V_11 )
V_11 = V_12 ;
if ( V_11 == NULL )
V_11 = strrchr ( V_4 , ':' ) ;
if ( V_11 == NULL )
V_11 = V_4 ;
else
V_11 ++ ;
V_12 = strchr ( V_11 , '.' ) ;
if ( V_12 == NULL )
V_12 = strchr ( V_11 , ';' ) ;
if ( V_12 == NULL )
V_12 = V_11 + strlen ( V_11 ) ;
if ( V_12 - V_11 > V_16
|| ( V_11 - V_4 ) + strlen ( V_12 ) > V_16 ) {
F_5 ( V_13 , V_17 ) ;
goto V_15;
}
V_9 = F_4 ( sizeof( T_3 ) ) ;
if ( V_9 == NULL ) {
F_5 ( V_13 , V_18 ) ;
goto V_15;
}
strncpy ( V_9 -> V_4 , V_11 , V_12 - V_11 ) ;
V_9 -> V_4 [ V_12 - V_11 ] = '\0' ;
strncpy ( V_9 -> V_19 , V_4 , V_11 - V_4 ) ;
V_9 -> V_19 [ V_11 - V_4 ] = '\0' ;
strcat ( V_9 -> V_19 , V_12 ) ;
V_9 -> V_20 . V_21 = strlen ( V_9 -> V_4 ) ;
V_9 -> V_20 . V_22 = V_23 ;
V_9 -> V_20 . V_24 = V_25 ;
V_9 -> V_20 . V_26 = V_9 -> V_4 ;
V_9 -> V_27 . V_21 = strlen ( V_9 -> V_19 ) ;
V_9 -> V_27 . V_22 = V_23 ;
V_9 -> V_27 . V_24 = V_25 ;
V_9 -> V_27 . V_26 = V_9 -> V_19 ;
if ( ! F_6 ( V_2 -> V_28 , ( char * ) V_9 ) ) {
F_5 ( V_13 , V_29 ) ;
goto V_15;
}
V_2 -> V_30 = V_4 ;
return ( 1 ) ;
V_15:
if ( V_9 != NULL )
F_7 ( V_9 ) ;
if ( V_4 != NULL )
F_7 ( V_4 ) ;
return ( 0 ) ;
}
static int F_8 ( T_2 * V_2 )
{
T_3 * V_9 ;
if ( V_2 == NULL ) {
F_5 ( V_31 , V_32 ) ;
return ( 0 ) ;
}
if ( F_9 ( V_2 -> V_28 ) < 1 )
return ( 1 ) ;
V_9 = ( T_3 * ) F_10 ( V_2 -> V_28 ) ;
if ( V_9 == NULL ) {
F_5 ( V_31 , V_33 ) ;
return ( 0 ) ;
}
F_7 ( V_9 ) ;
return ( 1 ) ;
}
static int F_11 ( T_3 * V_3 ,
struct V_34 * V_35 , void * * V_36 ,
unsigned long V_37 )
{
F_12 ( V_38 ) ;
if ( V_3 -> V_27 . V_21 )
return F_13 ( & V_3 -> V_20 ,
V_35 , V_36 ,
& V_3 -> V_27 , V_37 ) ;
else
return F_13 ( & V_3 -> V_20 ,
V_35 , V_36 , 0 , V_37 ) ;
}
void F_14 ( T_2 * V_2 , const char * V_39 , void * * V_36 )
{
T_3 * V_3 ;
int V_40 ;
# if 0
int flags = (1 << 4);
# else
int V_37 = 0 ;
# endif
struct V_34 V_35 ;
# if V_5 == 64
# define F_15 symname_32p
# pragma V_6 V_7
# pragma V_6 V_8
char * V_41 ;
# pragma V_6 V_10
char V_42 [ V_43 + 1 ] ;
# else
# define F_15 ((char *) symname)
# endif
* V_36 = NULL ;
if ( ( V_2 == NULL ) || ( V_39 == NULL ) ) {
F_5 ( V_44 , V_32 ) ;
return;
}
# if V_5 == 64
V_41 = V_42 ;
strcpy ( V_41 , V_39 ) ;
# endif
V_35 . V_21 = strlen ( F_15 ) ;
V_35 . V_22 = V_23 ;
V_35 . V_24 = V_25 ;
V_35 . V_26 = F_15 ;
if ( F_9 ( V_2 -> V_28 ) < 1 ) {
F_5 ( V_44 , V_29 ) ;
return;
}
V_3 = ( T_3 * ) F_16 ( V_2 -> V_28 ,
F_9 ( V_2 -> V_28 ) - 1 ) ;
if ( V_3 == NULL ) {
F_5 ( V_44 , V_33 ) ;
return;
}
if ( V_2 -> V_37 & V_45 )
V_37 = 0 ;
V_40 = F_11 ( V_3 , & V_35 , V_36 , V_37 ) ;
if ( ! F_17 ( V_40 ) ) {
unsigned short V_46 ;
char V_47 [ 257 ] ;
struct V_34 V_48 ;
V_48 . V_21 = sizeof( V_47 ) ;
V_48 . V_22 = V_23 ;
V_48 . V_24 = V_25 ;
V_48 . V_26 = V_47 ;
* V_36 = NULL ;
V_40 = F_18 ( V_40 , & V_46 , & V_48 , 1 , 0 ) ;
if ( ! F_17 ( V_40 ) )
F_19 ( V_40 ) ;
else {
V_47 [ V_46 ] = '\0' ;
F_5 ( V_44 , V_49 ) ;
if ( V_3 -> V_27 . V_21 )
F_20 ( 9 ,
L_1 , V_39 ,
L_2 , V_3 -> V_4 ,
L_3 , V_3 -> V_19 , L_4 ,
L_5 , V_47 ) ;
else
F_20 ( 6 ,
L_1 , V_39 ,
L_2 , V_3 -> V_4 , L_5 , V_47 ) ;
}
return;
}
return;
}
static void * F_21 ( T_2 * V_2 , const char * V_39 )
{
void * V_36 = 0 ;
F_14 ( V_2 , V_39 , & V_36 ) ;
return V_36 ;
}
static T_4 F_22 ( T_2 * V_2 , const char * V_39 )
{
T_4 V_36 = 0 ;
F_14 ( V_2 , V_39 , ( void * * ) & V_36 ) ;
return V_36 ;
}
static char * F_23 ( T_2 * V_2 , const char * V_50 ,
const char * V_51 )
{
int V_40 ;
int V_52 , V_53 ;
struct V_54 V_55 ;
struct V_56 V_57 ;
char V_58 [ V_43 + 1 ] ;
char * V_59 ;
# if V_5 == 64
# define F_24 filespec1_32p;
# define F_25 filespec2_32p;
# pragma V_6 V_7
# pragma V_6 V_8
char * V_60 ;
char * V_61 ;
# pragma V_6 V_10
char V_62 [ V_43 + 1 ] ;
char V_63 [ V_43 + 1 ] ;
# else
# define F_24 ((char *) filespec1)
# define F_25 ((char *) filespec2)
# endif
if ( ! V_50 )
V_50 = L_6 ;
if ( ! V_51 )
V_51 = L_6 ;
V_52 = strlen ( V_50 ) ;
V_53 = strlen ( V_51 ) ;
# if V_5 == 64
V_60 = V_62 ;
V_61 = V_63 ;
strcpy ( V_60 , V_50 ) ;
strcpy ( V_61 , V_51 ) ;
# endif
V_55 = V_64 ;
V_57 = V_65 ;
F_26 ( V_55 , V_57 ) . V_66 = F_24 ;
F_26 ( V_55 , V_57 ) . V_67 = V_52 ;
F_26 ( V_55 , V_57 ) . V_68 = F_25 ;
F_26 ( V_55 , V_57 ) . V_69 = V_53 ;
F_27 (fab)
V_57 . V_70 = V_58 ;
V_57 . V_71 = V_43 ;
V_57 . V_72 = V_73 | V_74 ;
F_28 ( V_57 ) ;
V_55 . V_75 = & V_57 ;
V_40 = F_29 ( & V_55 , 0 , 0 ) ;
if ( ! F_17 ( V_40 ) ) {
unsigned short V_46 ;
char V_47 [ 257 ] ;
struct V_34 V_48 ;
V_48 . V_21 = sizeof( V_47 ) ;
V_48 . V_22 = V_23 ;
V_48 . V_24 = V_25 ;
V_48 . V_26 = V_47 ;
V_40 = F_18 ( V_40 , & V_46 , & V_48 , 1 , 0 ) ;
if ( ! F_17 ( V_40 ) )
F_19 ( V_40 ) ;
else {
V_47 [ V_46 ] = '\0' ;
F_5 ( V_76 , V_77 ) ;
F_20 ( 7 ,
L_7 , V_50 , L_8 ,
L_9 , V_51 , L_10 , V_47 ) ;
}
return ( NULL ) ;
}
V_59 = F_30 ( V_57 . V_78 + 1 ) ;
if ( ! V_59 )
goto V_79;
strncpy ( V_59 , V_57 . V_70 , V_57 . V_78 ) ;
V_59 [ V_57 . V_78 ] = '\0' ;
return ( V_59 ) ;
V_79:
F_5 ( V_76 , V_18 ) ;
}
static char * F_31 ( T_2 * V_2 , const char * V_4 )
{
int V_80 = strlen ( V_4 ) ;
char * V_81 = F_30 ( V_80 + 1 ) ;
strcpy ( V_81 , V_4 ) ;
return ( V_81 ) ;
}

T_1 * F_1 ( void )
{
return & V_1 ;
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
const char * V_13 = NULL ;
if ( V_4 == NULL ) {
F_5 ( V_14 , V_15 ) ;
goto V_16;
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
if ( V_12 != NULL && V_12 [ 1 ] == ';' )
V_13 = L_1 ;
if ( V_12 == NULL ) {
V_12 = strchr ( V_11 , ';' ) ;
V_13 = L_1 ;
}
if ( V_12 == NULL )
V_12 = V_11 + strlen ( V_11 ) ;
if ( V_12 - V_11 > V_17
|| ( V_11 - V_4 ) + strlen ( V_12 ) > V_17 ) {
F_5 ( V_14 , V_18 ) ;
goto V_16;
}
V_9 = F_4 ( sizeof( * V_9 ) ) ;
if ( V_9 == NULL ) {
F_5 ( V_14 , V_19 ) ;
goto V_16;
}
strncpy ( V_9 -> V_4 , V_11 , V_12 - V_11 ) ;
V_9 -> V_4 [ V_12 - V_11 ] = '\0' ;
strncpy ( V_9 -> V_20 , V_4 , V_11 - V_4 ) ;
V_9 -> V_20 [ V_11 - V_4 ] = '\0' ;
if ( V_13 ) {
strcat ( V_9 -> V_20 , V_13 ) ;
if ( * V_12 == '.' )
V_12 ++ ;
}
strcat ( V_9 -> V_20 , V_12 ) ;
V_9 -> V_21 . V_22 = strlen ( V_9 -> V_4 ) ;
V_9 -> V_21 . V_23 = V_24 ;
V_9 -> V_21 . V_25 = V_26 ;
V_9 -> V_21 . V_27 = V_9 -> V_4 ;
V_9 -> V_28 . V_22 = strlen ( V_9 -> V_20 ) ;
V_9 -> V_28 . V_23 = V_24 ;
V_9 -> V_28 . V_25 = V_26 ;
V_9 -> V_28 . V_27 = V_9 -> V_20 ;
if ( ! F_6 ( V_2 -> V_29 , ( char * ) V_9 ) ) {
F_5 ( V_14 , V_30 ) ;
goto V_16;
}
V_2 -> V_31 = V_4 ;
return ( 1 ) ;
V_16:
F_7 ( V_9 ) ;
F_7 ( V_4 ) ;
return ( 0 ) ;
}
static int F_8 ( T_2 * V_2 )
{
T_3 * V_9 ;
if ( V_2 == NULL ) {
F_5 ( V_32 , V_33 ) ;
return ( 0 ) ;
}
if ( F_9 ( V_2 -> V_29 ) < 1 )
return ( 1 ) ;
V_9 = ( T_3 * ) F_10 ( V_2 -> V_29 ) ;
if ( V_9 == NULL ) {
F_5 ( V_32 , V_34 ) ;
return ( 0 ) ;
}
F_7 ( V_9 ) ;
return ( 1 ) ;
}
static int F_11 ( T_3 * V_3 ,
struct V_35 * V_36 , void * * V_37 ,
unsigned long V_38 )
{
F_12 ( V_39 ) ;
if ( V_3 -> V_28 . V_22 )
return F_13 ( & V_3 -> V_21 ,
V_36 , V_37 ,
& V_3 -> V_28 , V_38 ) ;
else
return F_13 ( & V_3 -> V_21 ,
V_36 , V_37 , 0 , V_38 ) ;
}
void F_14 ( T_2 * V_2 , const char * V_40 , void * * V_37 )
{
T_3 * V_3 ;
int V_41 ;
# ifdef F_15
int V_38 = F_15 ;
# else
int V_38 = ( 1 << 4 ) ;
# endif
struct V_35 V_36 ;
# if V_5 == 64
# define F_16 symname_32p
# pragma V_6 V_7
# pragma V_6 V_8
char * V_42 ;
# pragma V_6 V_10
char V_43 [ V_44 + 1 ] ;
# else
# define F_16 ((char *) symname)
# endif
* V_37 = NULL ;
if ( ( V_2 == NULL ) || ( V_40 == NULL ) ) {
F_5 ( V_45 , V_33 ) ;
return;
}
# if V_5 == 64
V_42 = V_43 ;
strcpy ( V_42 , V_40 ) ;
# endif
V_36 . V_22 = strlen ( F_16 ) ;
V_36 . V_23 = V_24 ;
V_36 . V_25 = V_26 ;
V_36 . V_27 = F_16 ;
if ( F_9 ( V_2 -> V_29 ) < 1 ) {
F_5 ( V_45 , V_30 ) ;
return;
}
V_3 = ( T_3 * ) F_17 ( V_2 -> V_29 ,
F_9 ( V_2 -> V_29 ) - 1 ) ;
if ( V_3 == NULL ) {
F_5 ( V_45 , V_34 ) ;
return;
}
if ( V_2 -> V_38 & V_46 )
V_38 = 0 ;
V_41 = F_11 ( V_3 , & V_36 , V_37 , V_38 ) ;
if ( ! F_18 ( V_41 ) ) {
unsigned short V_47 ;
char V_48 [ 257 ] ;
struct V_35 V_49 ;
V_49 . V_22 = sizeof( V_48 ) ;
V_49 . V_23 = V_24 ;
V_49 . V_25 = V_26 ;
V_49 . V_27 = V_48 ;
* V_37 = NULL ;
V_41 = F_19 ( V_41 , & V_47 , & V_49 , 1 , 0 ) ;
if ( ! F_18 ( V_41 ) )
F_20 ( V_41 ) ;
else {
V_48 [ V_47 ] = '\0' ;
F_5 ( V_45 , V_50 ) ;
if ( V_3 -> V_28 . V_22 )
F_21 ( 9 ,
L_2 , V_40 ,
L_3 , V_3 -> V_4 ,
L_4 , V_3 -> V_20 , L_5 ,
L_6 , V_48 ) ;
else
F_21 ( 6 ,
L_2 , V_40 ,
L_3 , V_3 -> V_4 , L_6 , V_48 ) ;
}
return;
}
return;
}
static T_4 F_22 ( T_2 * V_2 , const char * V_40 )
{
T_4 V_37 = 0 ;
F_14 ( V_2 , V_40 , ( void * * ) & V_37 ) ;
return V_37 ;
}
static char * F_23 ( T_2 * V_2 , const char * V_51 ,
const char * V_52 )
{
int V_41 ;
int V_53 , V_54 ;
struct V_55 V_56 ;
struct V_57 V_58 ;
char V_59 [ V_44 + 1 ] ;
char * V_60 ;
# if V_5 == 64
# define F_24 filespec1_32p;
# define F_25 filespec2_32p;
# pragma V_6 V_7
# pragma V_6 V_8
char * V_61 ;
char * V_62 ;
# pragma V_6 V_10
char V_63 [ V_44 + 1 ] ;
char V_64 [ V_44 + 1 ] ;
# else
# define F_24 ((char *) filespec1)
# define F_25 ((char *) filespec2)
# endif
if ( ! V_51 )
V_51 = L_7 ;
if ( ! V_52 )
V_52 = L_7 ;
V_53 = strlen ( V_51 ) ;
V_54 = strlen ( V_52 ) ;
# if V_5 == 64
V_61 = V_63 ;
V_62 = V_64 ;
strcpy ( V_61 , V_51 ) ;
strcpy ( V_62 , V_52 ) ;
# endif
V_56 = V_65 ;
V_58 = V_66 ;
F_26 ( V_56 , V_58 ) . V_67 = F_24 ;
F_26 ( V_56 , V_58 ) . V_68 = V_53 ;
F_26 ( V_56 , V_58 ) . V_69 = F_25 ;
F_26 ( V_56 , V_58 ) . V_70 = V_54 ;
F_27 (fab)
V_58 . V_71 = V_59 ;
V_58 . V_72 = V_44 ;
V_58 . V_73 = V_74 | V_75 ;
F_28 ( V_58 ) ;
V_56 . V_76 = & V_58 ;
V_41 = F_29 ( & V_56 , 0 , 0 ) ;
if ( ! F_18 ( V_41 ) ) {
unsigned short V_47 ;
char V_48 [ 257 ] ;
struct V_35 V_49 ;
V_49 . V_22 = sizeof( V_48 ) ;
V_49 . V_23 = V_24 ;
V_49 . V_25 = V_26 ;
V_49 . V_27 = V_48 ;
V_41 = F_19 ( V_41 , & V_47 , & V_49 , 1 , 0 ) ;
if ( ! F_18 ( V_41 ) )
F_20 ( V_41 ) ;
else {
V_48 [ V_47 ] = '\0' ;
F_5 ( V_77 , V_78 ) ;
F_21 ( 7 ,
L_8 , V_51 , L_9 ,
L_10 , V_52 , L_11 , V_48 ) ;
}
return ( NULL ) ;
}
V_60 = F_30 ( V_58 . V_79 + 1 ) ;
if ( V_60 == NULL )
goto V_80;
strncpy ( V_60 , V_58 . V_71 , V_58 . V_79 ) ;
V_60 [ V_58 . V_79 ] = '\0' ;
return ( V_60 ) ;
V_80:
F_5 ( V_77 , V_19 ) ;
}
static char * F_31 ( T_2 * V_2 , const char * V_4 )
{
int V_81 = strlen ( V_4 ) ;
char * V_82 = F_30 ( V_81 + 1 ) ;
if ( V_82 != NULL )
strcpy ( V_82 , V_4 ) ;
return ( V_82 ) ;
}

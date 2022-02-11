T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 , int V_3 , const char * V_4 , long V_5 ,
char * * V_6 )
{
int V_7 = 0 ;
T_3 * V_8 ;
char * V_9 = NULL ;
V_8 = ( T_3 * ) V_2 -> V_10 ;
switch ( V_3 ) {
case V_11 :
if ( V_5 == V_12 ) {
V_9 = ( char * ) getenv ( F_3 () ) ;
if ( V_9 )
V_7 = F_4 ( V_8 , V_9 , V_13 ) ;
else
V_7 = F_4 ( V_8 , F_5 () ,
V_13 ) ;
if ( ! V_7 ) {
F_6 ( V_14 , V_15 ) ;
}
} else
V_7 = F_4 ( V_8 , V_4 , ( int ) V_5 ) ;
break;
}
return ( V_7 ) ;
}
static int F_7 ( T_2 * V_16 )
{
T_3 * V_17 ;
if ( ( V_17 = ( T_3 * ) F_8 ( sizeof( T_3 ) ) ) == NULL )
return ( 0 ) ;
if ( ( V_17 -> V_18 = F_9 () ) == NULL ) {
F_10 ( V_17 ) ;
return ( 0 ) ;
}
V_17 -> V_19 = NULL ;
V_16 -> V_10 = ( char * ) V_17 ;
return ( 1 ) ;
}
static void F_11 ( T_4 * V_20 )
{
F_10 ( V_20 ) ;
}
static int F_12 ( const T_4 * const * V_17 ,
const T_4 * const * V_21 )
{
if ( ( * V_17 ) -> V_20 > ( * V_21 ) -> V_20 )
return 1 ;
if ( ( * V_17 ) -> V_20 < ( * V_21 ) -> V_20 )
return - 1 ;
return 0 ;
}
static void F_13 ( T_5 * V_22 )
{
if ( V_22 -> V_9 )
F_10 ( V_22 -> V_9 ) ;
if ( V_22 -> V_23 )
F_14 ( V_22 -> V_23 , F_11 ) ;
F_10 ( V_22 ) ;
}
static void F_15 ( T_2 * V_16 )
{
T_3 * V_17 ;
V_17 = ( T_3 * ) V_16 -> V_10 ;
if ( V_17 -> V_19 != NULL )
F_16 ( V_17 -> V_19 , F_13 ) ;
if ( V_17 -> V_18 != NULL )
F_17 ( V_17 -> V_18 ) ;
F_10 ( V_17 ) ;
}
static int F_4 ( T_3 * V_2 , const char * V_9 , int type )
{
int V_24 , V_25 ;
const char * V_26 , * V_27 , * V_28 ;
if ( V_9 == NULL || ! * V_9 ) {
F_6 ( V_29 , V_30 ) ;
return 0 ;
}
V_26 = V_9 ;
V_28 = V_26 ;
do {
if ( ( * V_28 == V_31 ) || ( * V_28 == '\0' ) ) {
T_5 * V_22 ;
V_27 = V_26 ;
V_26 = V_28 + 1 ;
V_25 = ( int ) ( V_28 - V_27 ) ;
if ( V_25 == 0 )
continue;
for ( V_24 = 0 ; V_24 < F_18 ( V_2 -> V_19 ) ; V_24 ++ ) {
V_22 = F_19 ( V_2 -> V_19 , V_24 ) ;
if ( strlen ( V_22 -> V_9 ) == ( V_32 ) V_25 &&
strncmp ( V_22 -> V_9 , V_27 , ( unsigned int ) V_25 ) == 0 )
break;
}
if ( V_24 < F_18 ( V_2 -> V_19 ) )
continue;
if ( V_2 -> V_19 == NULL ) {
V_2 -> V_19 = F_20 () ;
if ( ! V_2 -> V_19 ) {
F_6 ( V_29 , V_33 ) ;
return 0 ;
}
}
V_22 = F_8 ( sizeof( T_5 ) ) ;
if ( ! V_22 )
return 0 ;
V_22 -> V_34 = type ;
V_22 -> V_23 = F_21 ( F_12 ) ;
V_22 -> V_9 = F_8 ( ( unsigned int ) V_25 + 1 ) ;
if ( ! V_22 -> V_9 || ! V_22 -> V_23 ) {
F_13 ( V_22 ) ;
return 0 ;
}
strncpy ( V_22 -> V_9 , V_27 , ( unsigned int ) V_25 ) ;
V_22 -> V_9 [ V_25 ] = '\0' ;
if ( ! F_22 ( V_2 -> V_19 , V_22 ) ) {
F_13 ( V_22 ) ;
return 0 ;
}
}
} while ( * V_28 ++ != '\0' );
return 1 ;
}
static int F_23 ( T_2 * V_35 , int type , T_6 * V_36 ,
T_7 * V_7 )
{
T_3 * V_2 ;
union {
struct {
T_8 V_37 ;
T_9 V_38 ;
} V_39 ;
struct {
T_10 V_40 ;
T_11 V_41 ;
} V_42 ;
} V_43 ;
int V_44 = 0 ;
int V_45 , V_24 , V_46 ;
unsigned long V_47 ;
T_12 * V_21 = NULL ;
T_7 V_48 , * V_49 ;
const char * V_50 = L_1 ;
if ( V_36 == NULL )
return ( 0 ) ;
V_48 . type = type ;
if ( type == V_51 ) {
V_43 . V_39 . V_37 . V_52 = & V_43 . V_39 . V_38 ;
V_43 . V_39 . V_38 . V_53 = V_36 ;
V_48 . V_43 . V_39 = & V_43 . V_39 . V_37 ;
V_50 = L_1 ;
} else if ( type == V_54 ) {
V_43 . V_42 . V_40 . V_42 = & V_43 . V_42 . V_41 ;
V_43 . V_42 . V_41 . V_55 = V_36 ;
V_48 . V_43 . V_42 = & V_43 . V_42 . V_40 ;
V_50 = L_2 ;
} else {
F_6 ( V_56 , V_57 ) ;
goto V_58;
}
if ( ( V_21 = F_9 () ) == NULL ) {
F_6 ( V_56 , V_59 ) ;
goto V_58;
}
V_2 = ( T_3 * ) V_35 -> V_10 ;
V_47 = F_24 ( V_36 ) ;
for ( V_45 = 0 ; V_45 < F_18 ( V_2 -> V_19 ) ; V_45 ++ ) {
T_5 * V_22 ;
int V_60 ;
T_4 V_61 , * V_62 ;
V_22 = F_19 ( V_2 -> V_19 , V_45 ) ;
V_24 = strlen ( V_22 -> V_9 ) + 1 + 8 + 6 + 1 + 1 ;
if ( ! F_25 ( V_21 , V_24 ) ) {
F_6 ( V_56 , V_33 ) ;
goto V_58;
}
if ( type == V_54 && V_22 -> V_23 ) {
V_61 . V_20 = V_47 ;
F_26 ( V_63 ) ;
V_60 = F_27 ( V_22 -> V_23 , & V_61 ) ;
if ( V_60 >= 0 ) {
V_62 = F_28 ( V_22 -> V_23 , V_60 ) ;
V_46 = V_62 -> V_64 ;
} else {
V_62 = NULL ;
V_46 = 0 ;
}
F_29 ( V_63 ) ;
} else {
V_46 = 0 ;
V_62 = NULL ;
}
for (; ; ) {
char V_65 = '/' ;
#ifdef F_30
V_65 = V_22 -> V_9 [ strlen ( V_22 -> V_9 ) - 1 ] ;
if ( V_65 != ':' && V_65 != '>' && V_65 != ']' ) {
V_65 = ':' ;
} else {
V_65 = '\0' ;
}
#endif
if ( V_65 == '\0' ) {
F_31 ( V_21 -> V_43 , V_21 -> V_66 ,
L_3 , V_22 -> V_9 , V_47 , V_50 , V_46 ) ;
} else {
F_31 ( V_21 -> V_43 , V_21 -> V_66 ,
L_4 , V_22 -> V_9 , V_65 , V_47 , V_50 , V_46 ) ;
}
#ifndef F_32
# ifdef F_33
# define F_34 _stat
# endif
{
struct F_34 V_67 ;
if ( F_34 ( V_21 -> V_43 , & V_67 ) < 0 )
break;
}
#endif
if ( type == V_51 ) {
if ( ( F_35 ( V_35 , V_21 -> V_43 , V_22 -> V_34 ) ) == 0 )
break;
} else if ( type == V_54 ) {
if ( ( F_36 ( V_35 , V_21 -> V_43 , V_22 -> V_34 ) ) == 0 )
break;
}
V_46 ++ ;
}
F_37 ( V_63 ) ;
V_24 = F_38 ( V_35 -> V_68 -> V_69 , & V_48 ) ;
if ( V_24 != - 1 )
V_49 = F_39 ( V_35 -> V_68 -> V_69 , V_24 ) ;
else
V_49 = NULL ;
F_40 ( V_63 ) ;
if ( type == V_54 ) {
F_37 ( V_63 ) ;
if ( ! V_62 ) {
V_61 . V_20 = V_47 ;
V_60 = F_27 ( V_22 -> V_23 , & V_61 ) ;
if ( V_60 >= 0 )
V_62 = F_28 ( V_22 -> V_23 , V_60 ) ;
}
if ( ! V_62 ) {
V_62 = F_8 ( sizeof( T_4 ) ) ;
V_62 -> V_20 = V_47 ;
V_62 -> V_64 = V_46 ;
if ( ! F_41 ( V_22 -> V_23 , V_62 ) ) {
F_40 ( V_63 ) ;
F_10 ( V_62 ) ;
V_44 = 0 ;
goto V_58;
}
} else if ( V_62 -> V_64 < V_46 )
V_62 -> V_64 = V_46 ;
F_40 ( V_63 ) ;
}
if ( V_49 != NULL ) {
V_44 = 1 ;
V_7 -> type = V_49 -> type ;
memcpy ( & V_7 -> V_43 , & V_49 -> V_43 , sizeof( V_7 -> V_43 ) ) ;
goto V_58;
}
}
V_58:
if ( V_21 != NULL )
F_17 ( V_21 ) ;
return ( V_44 ) ;
}

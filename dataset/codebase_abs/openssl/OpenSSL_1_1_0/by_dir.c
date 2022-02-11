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
if ( ( V_17 = F_8 ( sizeof( * V_17 ) ) ) == NULL )
return 0 ;
if ( ( V_17 -> V_18 = F_9 () ) == NULL ) {
F_10 ( V_17 ) ;
return 0 ;
}
V_17 -> V_19 = NULL ;
V_17 -> V_20 = F_11 () ;
if ( V_17 -> V_20 == NULL ) {
F_12 ( V_17 -> V_18 ) ;
F_10 ( V_17 ) ;
return 0 ;
}
V_16 -> V_10 = ( char * ) V_17 ;
return 1 ;
}
static void F_13 ( T_4 * V_21 )
{
F_10 ( V_21 ) ;
}
static int F_14 ( const T_4 * const * V_17 ,
const T_4 * const * V_22 )
{
if ( ( * V_17 ) -> V_21 > ( * V_22 ) -> V_21 )
return 1 ;
if ( ( * V_17 ) -> V_21 < ( * V_22 ) -> V_21 )
return - 1 ;
return 0 ;
}
static void F_15 ( T_5 * V_23 )
{
F_10 ( V_23 -> V_9 ) ;
F_16 ( V_23 -> V_24 , F_13 ) ;
F_10 ( V_23 ) ;
}
static void F_17 ( T_2 * V_16 )
{
T_3 * V_17 ;
V_17 = ( T_3 * ) V_16 -> V_10 ;
F_18 ( V_17 -> V_19 , F_15 ) ;
F_12 ( V_17 -> V_18 ) ;
F_19 ( V_17 -> V_20 ) ;
F_10 ( V_17 ) ;
}
static int F_4 ( T_3 * V_2 , const char * V_9 , int type )
{
const char * V_25 , * V_26 ;
if ( V_9 == NULL || ! * V_9 ) {
F_6 ( V_27 , V_28 ) ;
return 0 ;
}
V_25 = V_9 ;
V_26 = V_25 ;
do {
if ( ( * V_26 == V_29 ) || ( * V_26 == '\0' ) ) {
T_5 * V_23 ;
int V_30 ;
T_6 V_31 ;
const char * V_32 = V_25 ;
V_25 = V_26 + 1 ;
V_31 = V_26 - V_32 ;
if ( V_31 == 0 )
continue;
for ( V_30 = 0 ; V_30 < F_20 ( V_2 -> V_19 ) ; V_30 ++ ) {
V_23 = F_21 ( V_2 -> V_19 , V_30 ) ;
if ( strlen ( V_23 -> V_9 ) == V_31 &&
strncmp ( V_23 -> V_9 , V_32 , V_31 ) == 0 )
break;
}
if ( V_30 < F_20 ( V_2 -> V_19 ) )
continue;
if ( V_2 -> V_19 == NULL ) {
V_2 -> V_19 = F_22 () ;
if ( ! V_2 -> V_19 ) {
F_6 ( V_27 , V_33 ) ;
return 0 ;
}
}
V_23 = F_8 ( sizeof( * V_23 ) ) ;
if ( V_23 == NULL )
return 0 ;
V_23 -> V_34 = type ;
V_23 -> V_24 = F_23 ( F_14 ) ;
V_23 -> V_9 = F_24 ( V_32 , V_31 ) ;
if ( V_23 -> V_9 == NULL || V_23 -> V_24 == NULL ) {
F_15 ( V_23 ) ;
return 0 ;
}
if ( ! F_25 ( V_2 -> V_19 , V_23 ) ) {
F_15 ( V_23 ) ;
return 0 ;
}
}
} while ( * V_26 ++ != '\0' );
return 1 ;
}
static int F_26 ( T_2 * V_35 , T_7 type ,
T_8 * V_36 , T_9 * V_7 )
{
T_3 * V_2 ;
union {
T_10 V_37 ;
T_11 V_38 ;
} V_39 ;
int V_40 = 0 ;
int V_41 , V_30 , V_42 ;
unsigned long V_43 ;
T_12 * V_22 = NULL ;
T_9 V_44 , * V_45 ;
const char * V_46 = L_1 ;
if ( V_36 == NULL )
return ( 0 ) ;
V_44 . type = type ;
if ( type == V_47 ) {
V_39 . V_37 . V_48 . V_49 = V_36 ;
V_44 . V_39 . V_50 = & V_39 . V_37 ;
V_46 = L_1 ;
} else if ( type == V_51 ) {
V_39 . V_38 . V_38 . V_52 = V_36 ;
V_44 . V_39 . V_38 = & V_39 . V_38 ;
V_46 = L_2 ;
} else {
F_6 ( V_53 , V_54 ) ;
goto V_55;
}
if ( ( V_22 = F_9 () ) == NULL ) {
F_6 ( V_53 , V_56 ) ;
goto V_55;
}
V_2 = ( T_3 * ) V_35 -> V_10 ;
V_43 = F_27 ( V_36 ) ;
for ( V_41 = 0 ; V_41 < F_20 ( V_2 -> V_19 ) ; V_41 ++ ) {
T_5 * V_23 ;
int V_57 ;
T_4 V_58 , * V_59 ;
V_23 = F_21 ( V_2 -> V_19 , V_41 ) ;
V_30 = strlen ( V_23 -> V_9 ) + 1 + 8 + 6 + 1 + 1 ;
if ( ! F_28 ( V_22 , V_30 ) ) {
F_6 ( V_53 , V_33 ) ;
goto V_55;
}
if ( type == V_51 && V_23 -> V_24 ) {
V_58 . V_21 = V_43 ;
F_29 ( V_2 -> V_20 ) ;
V_57 = F_30 ( V_23 -> V_24 , & V_58 ) ;
if ( V_57 >= 0 ) {
V_59 = F_31 ( V_23 -> V_24 , V_57 ) ;
V_42 = V_59 -> V_60 ;
} else {
V_59 = NULL ;
V_42 = 0 ;
}
F_32 ( V_2 -> V_20 ) ;
} else {
V_42 = 0 ;
V_59 = NULL ;
}
for (; ; ) {
char V_61 = '/' ;
#ifdef F_33
V_61 = V_23 -> V_9 [ strlen ( V_23 -> V_9 ) - 1 ] ;
if ( V_61 != ':' && V_61 != '>' && V_61 != ']' ) {
V_61 = ':' ;
} else {
V_61 = '\0' ;
}
#endif
if ( V_61 == '\0' ) {
F_34 ( V_22 -> V_39 , V_22 -> V_62 ,
L_3 , V_23 -> V_9 , V_43 , V_46 , V_42 ) ;
} else {
F_34 ( V_22 -> V_39 , V_22 -> V_62 ,
L_4 , V_23 -> V_9 , V_61 , V_43 , V_46 , V_42 ) ;
}
#ifndef F_35
# ifdef F_36
# define F_37 _stat
# endif
{
struct F_37 V_63 ;
if ( F_37 ( V_22 -> V_39 , & V_63 ) < 0 )
break;
}
#endif
if ( type == V_47 ) {
if ( ( F_38 ( V_35 , V_22 -> V_39 , V_23 -> V_34 ) ) == 0 )
break;
} else if ( type == V_51 ) {
if ( ( F_39 ( V_35 , V_22 -> V_39 , V_23 -> V_34 ) ) == 0 )
break;
}
V_42 ++ ;
}
F_40 ( V_2 -> V_20 ) ;
V_30 = F_41 ( V_35 -> V_64 -> V_65 , & V_44 ) ;
if ( V_30 != - 1 )
V_45 = F_42 ( V_35 -> V_64 -> V_65 , V_30 ) ;
else
V_45 = NULL ;
F_32 ( V_2 -> V_20 ) ;
if ( type == V_51 ) {
F_40 ( V_2 -> V_20 ) ;
if ( ! V_59 ) {
V_58 . V_21 = V_43 ;
V_57 = F_30 ( V_23 -> V_24 , & V_58 ) ;
if ( V_57 >= 0 )
V_59 = F_31 ( V_23 -> V_24 , V_57 ) ;
}
if ( ! V_59 ) {
V_59 = F_8 ( sizeof( * V_59 ) ) ;
if ( V_59 == NULL ) {
F_32 ( V_2 -> V_20 ) ;
F_6 ( V_53 , V_33 ) ;
V_40 = 0 ;
goto V_55;
}
V_59 -> V_21 = V_43 ;
V_59 -> V_60 = V_42 ;
if ( ! F_43 ( V_23 -> V_24 , V_59 ) ) {
F_32 ( V_2 -> V_20 ) ;
F_10 ( V_59 ) ;
V_40 = 0 ;
goto V_55;
}
} else if ( V_59 -> V_60 < V_42 ) {
V_59 -> V_60 = V_42 ;
}
F_32 ( V_2 -> V_20 ) ;
}
if ( V_45 != NULL ) {
V_40 = 1 ;
V_7 -> type = V_45 -> type ;
memcpy ( & V_7 -> V_39 , & V_45 -> V_39 , sizeof( V_7 -> V_39 ) ) ;
goto V_55;
}
}
V_55:
F_12 ( V_22 ) ;
return ( V_40 ) ;
}

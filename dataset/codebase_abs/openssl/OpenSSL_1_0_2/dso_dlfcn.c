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
int V_5 = V_6 ;
if ( V_4 == NULL ) {
F_4 ( V_7 , V_8 ) ;
goto V_9;
}
# ifdef F_5
if ( V_2 -> V_5 & V_10 )
V_5 |= F_5 ;
# endif
V_3 = F_6 ( V_4 , V_5 ) ;
if ( V_3 == NULL ) {
F_4 ( V_7 , V_11 ) ;
F_7 ( 4 , L_1 , V_4 , L_2 , F_8 () ) ;
goto V_9;
}
if ( ! F_9 ( V_2 -> V_12 , ( char * ) V_3 ) ) {
F_4 ( V_7 , V_13 ) ;
goto V_9;
}
V_2 -> V_14 = V_4 ;
return ( 1 ) ;
V_9:
if ( V_4 != NULL )
F_10 ( V_4 ) ;
if ( V_3 != NULL )
F_11 ( V_3 ) ;
return ( 0 ) ;
}
static int F_12 ( T_2 * V_2 )
{
void * V_3 ;
if ( V_2 == NULL ) {
F_4 ( V_15 , V_16 ) ;
return ( 0 ) ;
}
if ( F_13 ( V_2 -> V_12 ) < 1 )
return ( 1 ) ;
V_3 = F_14 ( V_2 -> V_12 ) ;
if ( V_3 == NULL ) {
F_4 ( V_15 , V_17 ) ;
F_9 ( V_2 -> V_12 , V_3 ) ;
return ( 0 ) ;
}
F_11 ( V_3 ) ;
return ( 1 ) ;
}
static void * F_15 ( T_2 * V_2 , const char * V_18 )
{
void * V_3 , * V_19 ;
if ( ( V_2 == NULL ) || ( V_18 == NULL ) ) {
F_4 ( V_20 , V_16 ) ;
return ( NULL ) ;
}
if ( F_13 ( V_2 -> V_12 ) < 1 ) {
F_4 ( V_20 , V_13 ) ;
return ( NULL ) ;
}
V_3 = F_16 ( V_2 -> V_12 , F_13 ( V_2 -> V_12 ) - 1 ) ;
if ( V_3 == NULL ) {
F_4 ( V_20 , V_17 ) ;
return ( NULL ) ;
}
V_19 = F_17 ( V_3 , V_18 ) ;
if ( V_19 == NULL ) {
F_4 ( V_20 , V_21 ) ;
F_7 ( 4 , L_3 , V_18 , L_2 , F_8 () ) ;
return ( NULL ) ;
}
return ( V_19 ) ;
}
static T_3 F_18 ( T_2 * V_2 , const char * V_18 )
{
void * V_3 ;
union {
T_3 V_19 ;
void * V_22 ;
} V_23 ;
if ( ( V_2 == NULL ) || ( V_18 == NULL ) ) {
F_4 ( V_24 , V_16 ) ;
return ( NULL ) ;
}
if ( F_13 ( V_2 -> V_12 ) < 1 ) {
F_4 ( V_24 , V_13 ) ;
return ( NULL ) ;
}
V_3 = F_16 ( V_2 -> V_12 , F_13 ( V_2 -> V_12 ) - 1 ) ;
if ( V_3 == NULL ) {
F_4 ( V_24 , V_17 ) ;
return ( NULL ) ;
}
V_23 . V_22 = F_17 ( V_3 , V_18 ) ;
if ( V_23 . V_22 == NULL ) {
F_4 ( V_24 , V_21 ) ;
F_7 ( 4 , L_3 , V_18 , L_2 , F_8 () ) ;
return ( NULL ) ;
}
return V_23 . V_19 ;
}
static char * F_19 ( T_2 * V_2 , const char * V_25 ,
const char * V_26 )
{
char * V_27 ;
if ( ! V_25 && ! V_26 ) {
F_4 ( V_28 , V_16 ) ;
return ( NULL ) ;
}
if ( ! V_26 || ( V_25 != NULL && V_25 [ 0 ] == '/' ) ) {
V_27 = F_20 ( strlen ( V_25 ) + 1 ) ;
if ( ! V_27 ) {
F_4 ( V_28 , V_29 ) ;
return ( NULL ) ;
}
strcpy ( V_27 , V_25 ) ;
}
else if ( ! V_25 ) {
V_27 = F_20 ( strlen ( V_26 ) + 1 ) ;
if ( ! V_27 ) {
F_4 ( V_28 , V_29 ) ;
return ( NULL ) ;
}
strcpy ( V_27 , V_26 ) ;
} else
{
int V_30 , V_31 ;
V_30 = strlen ( V_26 ) ;
V_31 = V_30 + ( V_25 ? strlen ( V_25 ) : 0 ) ;
if ( V_26 && V_26 [ V_30 - 1 ] == '/' ) {
V_30 -- ;
V_31 -- ;
}
V_27 = F_20 ( V_31 + 2 ) ;
if ( ! V_27 ) {
F_4 ( V_28 , V_29 ) ;
return ( NULL ) ;
}
strcpy ( V_27 , V_26 ) ;
V_27 [ V_30 ] = '/' ;
strcpy ( & V_27 [ V_30 + 1 ] , V_25 ) ;
}
return ( V_27 ) ;
}
static char * F_21 ( T_2 * V_2 , const char * V_4 )
{
char * V_32 ;
int V_31 , V_33 , V_34 ;
V_31 = strlen ( V_4 ) ;
V_33 = V_31 + 1 ;
V_34 = ( strstr ( V_4 , L_4 ) == NULL ) ;
if ( V_34 ) {
V_33 += V_35 ;
if ( ( F_22 ( V_2 ) & V_36 ) == 0 )
V_33 += 3 ;
}
V_32 = F_20 ( V_33 ) ;
if ( V_32 == NULL ) {
F_4 ( V_37 , V_38 ) ;
return ( NULL ) ;
}
if ( V_34 ) {
if ( ( F_22 ( V_2 ) & V_36 ) == 0 )
sprintf ( V_32 , L_5 V_39 , V_4 ) ;
else
sprintf ( V_32 , L_6 V_39 , V_4 ) ;
} else
sprintf ( V_32 , L_6 , V_4 ) ;
return ( V_32 ) ;
}
static int F_23 ( void * V_40 , T_4 * V_41 )
{
void * V_42 ;
V_42 = F_24 ( V_43 , V_40 , V_41 ) ;
return ( int ) V_42 ;
}
static int F_25 ( void * V_44 , char * V_45 , int V_46 )
{
# ifdef F_26
T_4 V_47 ;
int V_31 ;
if ( V_44 == NULL ) {
union {
int (* F_27) ( void * , char * , int );
void * V_48 ;
} V_49 = {
F_25
} ;
V_44 = V_49 . V_48 ;
}
if ( F_23 ( V_44 , & V_47 ) ) {
V_31 = ( int ) strlen ( V_47 . V_50 ) ;
if ( V_46 <= 0 )
return V_31 + 1 ;
if ( V_31 >= V_46 )
V_31 = V_46 - 1 ;
memcpy ( V_45 , V_47 . V_50 , V_31 ) ;
V_45 [ V_31 ++ ] = 0 ;
return V_31 ;
}
F_7 ( 2 , L_7 , F_8 () ) ;
# endif
return - 1 ;
}
static void * F_28 ( const char * V_51 )
{
void * V_52 = NULL , * V_53 = F_6 ( NULL , V_54 ) ;
if ( V_53 ) {
V_52 = F_17 ( V_53 , V_51 ) ;
F_11 ( V_53 ) ;
}
return V_52 ;
}

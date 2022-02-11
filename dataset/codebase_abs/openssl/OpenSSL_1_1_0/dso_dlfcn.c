T_1 * F_1 ( void )
{
return & V_1 ;
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
static T_3 F_15 ( T_2 * V_2 , const char * V_18 )
{
void * V_3 ;
union {
T_3 V_19 ;
void * V_20 ;
} V_21 ;
if ( ( V_2 == NULL ) || ( V_18 == NULL ) ) {
F_4 ( V_22 , V_16 ) ;
return ( NULL ) ;
}
if ( F_13 ( V_2 -> V_12 ) < 1 ) {
F_4 ( V_22 , V_13 ) ;
return ( NULL ) ;
}
V_3 = F_16 ( V_2 -> V_12 , F_13 ( V_2 -> V_12 ) - 1 ) ;
if ( V_3 == NULL ) {
F_4 ( V_22 , V_17 ) ;
return ( NULL ) ;
}
V_21 . V_20 = F_17 ( V_3 , V_18 ) ;
if ( V_21 . V_20 == NULL ) {
F_4 ( V_22 , V_23 ) ;
F_7 ( 4 , L_3 , V_18 , L_2 , F_8 () ) ;
return ( NULL ) ;
}
return V_21 . V_19 ;
}
static char * F_18 ( T_2 * V_2 , const char * V_24 ,
const char * V_25 )
{
char * V_26 ;
if ( ! V_24 && ! V_25 ) {
F_4 ( V_27 , V_16 ) ;
return ( NULL ) ;
}
if ( ! V_25 || ( V_24 != NULL && V_24 [ 0 ] == '/' ) ) {
V_26 = F_19 ( V_24 ) ;
if ( V_26 == NULL ) {
F_4 ( V_27 , V_28 ) ;
return ( NULL ) ;
}
}
else if ( ! V_24 ) {
V_26 = F_19 ( V_25 ) ;
if ( V_26 == NULL ) {
F_4 ( V_27 , V_28 ) ;
return ( NULL ) ;
}
} else {
int V_29 , V_30 ;
V_29 = strlen ( V_25 ) ;
V_30 = V_29 + strlen ( V_24 ) ;
if ( V_29 && V_25 [ V_29 - 1 ] == '/' ) {
V_29 -- ;
V_30 -- ;
}
V_26 = F_20 ( V_30 + 2 ) ;
if ( V_26 == NULL ) {
F_4 ( V_27 , V_28 ) ;
return ( NULL ) ;
}
strcpy ( V_26 , V_25 ) ;
V_26 [ V_29 ] = '/' ;
strcpy ( & V_26 [ V_29 + 1 ] , V_24 ) ;
}
return ( V_26 ) ;
}
static char * F_21 ( T_2 * V_2 , const char * V_4 )
{
char * V_31 ;
int V_30 , V_32 , V_33 ;
V_30 = strlen ( V_4 ) ;
V_32 = V_30 + 1 ;
V_33 = ( strstr ( V_4 , L_4 ) == NULL ) ;
if ( V_33 ) {
V_32 += strlen ( V_34 ) ;
if ( ( F_22 ( V_2 ) & V_35 ) == 0 )
V_32 += 3 ;
}
V_31 = F_20 ( V_32 ) ;
if ( V_31 == NULL ) {
F_4 ( V_36 , V_37 ) ;
return ( NULL ) ;
}
if ( V_33 ) {
if ( ( F_22 ( V_2 ) & V_35 ) == 0 )
sprintf ( V_31 , L_5 V_34 , V_4 ) ;
else
sprintf ( V_31 , L_6 V_34 , V_4 ) ;
} else
sprintf ( V_31 , L_6 , V_4 ) ;
return ( V_31 ) ;
}
static int F_23 ( void * V_38 , T_4 * V_39 )
{
void * V_40 ;
V_40 = F_24 ( V_41 , V_38 , V_39 ) ;
return ( int ) V_40 ;
}
static void * F_25 ( const char * V_42 )
{
void * V_43 = NULL , * V_44 = F_6 ( NULL , V_45 ) ;
if ( V_44 ) {
V_43 = F_17 ( V_44 , V_42 ) ;
F_11 ( V_44 ) ;
}
return V_43 ;
}

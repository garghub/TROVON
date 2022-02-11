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
T_3 V_3 = NULL ;
char * V_4 = F_3 ( V_2 , NULL ) ;
if ( V_4 == NULL ) {
F_4 ( V_5 , V_6 ) ;
goto V_7;
}
V_3 = F_5 ( V_4 , V_8 |
( V_2 -> V_9 & V_10 ? 0 :
V_11 ) , 0L ) ;
if ( V_3 == NULL ) {
F_4 ( V_5 , V_12 ) ;
F_6 ( 4 , L_1 , V_4 , L_2 , strerror ( V_13 ) ) ;
goto V_7;
}
if ( ! F_7 ( V_2 -> V_14 , ( char * ) V_3 ) ) {
F_4 ( V_5 , V_15 ) ;
goto V_7;
}
V_2 -> V_16 = V_4 ;
return ( 1 ) ;
V_7:
if ( V_4 != NULL )
F_8 ( V_4 ) ;
if ( V_3 != NULL )
F_9 ( V_3 ) ;
return ( 0 ) ;
}
static int F_10 ( T_2 * V_2 )
{
T_3 V_3 ;
if ( V_2 == NULL ) {
F_4 ( V_17 , V_18 ) ;
return ( 0 ) ;
}
if ( F_11 ( V_2 -> V_14 ) < 1 )
return ( 1 ) ;
V_3 = ( T_3 ) F_12 ( V_2 -> V_14 ) ;
if ( V_3 == NULL ) {
F_4 ( V_17 , V_19 ) ;
F_7 ( V_2 -> V_14 , ( char * ) V_3 ) ;
return ( 0 ) ;
}
F_9 ( V_3 ) ;
return ( 1 ) ;
}
static void * F_13 ( T_2 * V_2 , const char * V_20 )
{
T_3 V_3 ;
void * V_21 ;
if ( ( V_2 == NULL ) || ( V_20 == NULL ) ) {
F_4 ( V_22 , V_18 ) ;
return ( NULL ) ;
}
if ( F_11 ( V_2 -> V_14 ) < 1 ) {
F_4 ( V_22 , V_15 ) ;
return ( NULL ) ;
}
V_3 = ( T_3 ) F_14 ( V_2 -> V_14 , F_11 ( V_2 -> V_14 ) - 1 ) ;
if ( V_3 == NULL ) {
F_4 ( V_22 , V_19 ) ;
return ( NULL ) ;
}
if ( F_15 ( & V_3 , V_20 , V_23 , & V_21 ) < 0 ) {
F_4 ( V_22 , V_24 ) ;
F_6 ( 4 , L_3 , V_20 , L_2 , strerror ( V_13 ) ) ;
return ( NULL ) ;
}
return ( V_21 ) ;
}
static T_4 F_16 ( T_2 * V_2 , const char * V_20 )
{
T_3 V_3 ;
void * V_21 ;
if ( ( V_2 == NULL ) || ( V_20 == NULL ) ) {
F_4 ( V_25 , V_18 ) ;
return ( NULL ) ;
}
if ( F_11 ( V_2 -> V_14 ) < 1 ) {
F_4 ( V_25 , V_15 ) ;
return ( NULL ) ;
}
V_3 = ( T_3 ) F_14 ( V_2 -> V_14 , F_11 ( V_2 -> V_14 ) - 1 ) ;
if ( V_3 == NULL ) {
F_4 ( V_25 , V_19 ) ;
return ( NULL ) ;
}
if ( F_15 ( & V_3 , V_20 , V_23 , & V_21 ) < 0 ) {
F_4 ( V_25 , V_24 ) ;
F_6 ( 4 , L_3 , V_20 , L_2 , strerror ( V_13 ) ) ;
return ( NULL ) ;
}
return ( ( T_4 ) V_21 ) ;
}
static char * F_17 ( T_2 * V_2 , const char * V_26 , const char * V_27 )
{
char * V_28 ;
if ( ! V_26 && ! V_27 ) {
F_4 ( V_29 , V_18 ) ;
return ( NULL ) ;
}
if ( ! V_27 || V_26 [ 0 ] == '/' ) {
V_28 = F_18 ( strlen ( V_26 ) + 1 ) ;
if ( ! V_28 ) {
F_4 ( V_29 , V_30 ) ;
return ( NULL ) ;
}
strcpy ( V_28 , V_26 ) ;
}
else if ( ! V_26 ) {
V_28 = F_18 ( strlen ( V_27 ) + 1 ) ;
if ( ! V_28 ) {
F_4 ( V_29 , V_30 ) ;
return ( NULL ) ;
}
strcpy ( V_28 , V_27 ) ;
} else
{
int V_31 , V_32 ;
V_31 = ( V_27 ? strlen ( V_27 ) : 0 ) ;
V_32 = V_31 + ( V_26 ? strlen ( V_26 ) : 0 ) ;
if ( V_27 && V_27 [ V_31 - 1 ] == '/' ) {
V_31 -- ;
V_32 -- ;
}
V_28 = F_18 ( V_32 + 2 ) ;
if ( ! V_28 ) {
F_4 ( V_29 , V_30 ) ;
return ( NULL ) ;
}
strcpy ( V_28 , V_27 ) ;
V_28 [ V_31 ] = '/' ;
strcpy ( & V_28 [ V_31 + 1 ] , V_26 ) ;
}
return ( V_28 ) ;
}
static char * F_19 ( T_2 * V_2 , const char * V_4 )
{
char * V_33 ;
int V_32 , V_34 , V_35 ;
V_32 = strlen ( V_4 ) ;
V_34 = V_32 + 1 ;
V_35 = ( strstr ( V_4 , L_4 ) == NULL ) ;
{
V_34 += strlen ( V_36 ) ;
if ( ( F_20 ( V_2 ) & V_37 ) == 0 )
V_34 += 3 ;
}
V_33 = F_18 ( V_34 ) ;
if ( V_33 == NULL ) {
F_4 ( V_38 , V_39 ) ;
return ( NULL ) ;
}
if ( V_35 ) {
if ( ( F_20 ( V_2 ) & V_37 ) == 0 )
sprintf ( V_33 , L_5 , V_4 , V_36 ) ;
else
sprintf ( V_33 , L_6 , V_4 , V_36 ) ;
} else
sprintf ( V_33 , L_7 , V_4 ) ;
return ( V_33 ) ;
}
static int F_21 ( void * V_40 , char * V_41 , int V_42 )
{
struct V_43 V_44 ;
int V_45 , V_32 ;
if ( V_40 == NULL ) {
union {
int (* F_22) ( void * , char * , int );
void * V_46 ;
} V_47 = {
F_21
} ;
V_40 = V_47 . V_46 ;
}
for ( V_45 = - 1 ; F_23 ( V_45 , & V_44 ) == 0 ; V_45 ++ ) {
if ( ( ( V_48 ) V_40 >= V_44 . V_49 && ( V_48 ) V_40 < V_44 . V_50 ) ||
( ( V_48 ) V_40 >= V_44 . V_51 && ( V_48 ) V_40 < V_44 . V_52 ) ) {
V_32 = ( int ) strlen ( V_44 . V_4 ) ;
if ( V_42 <= 0 )
return V_32 + 1 ;
if ( V_32 >= V_42 )
V_32 = V_42 - 1 ;
memcpy ( V_41 , V_44 . V_4 , V_32 ) ;
V_41 [ V_32 ++ ] = 0 ;
return V_32 ;
}
}
return - 1 ;
}
static void * F_24 ( const char * V_53 )
{
void * V_54 ;
T_3 V_55 = NULL ;
return F_15 ( & V_55 , V_53 , V_23 , & V_54 ) ? NULL : V_54 ;
}

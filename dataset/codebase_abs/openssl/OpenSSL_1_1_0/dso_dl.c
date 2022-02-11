T_1 * F_1 ( void )
{
return & V_1 ;
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
char V_12 [ 160 ] ;
F_4 ( V_5 , V_13 ) ;
if ( F_6 ( V_14 , V_12 , sizeof( V_12 ) ) )
F_7 ( 4 , L_1 , V_4 , L_2 , V_12 ) ;
goto V_7;
}
if ( ! F_8 ( V_2 -> V_15 , ( char * ) V_3 ) ) {
F_4 ( V_5 , V_16 ) ;
goto V_7;
}
V_2 -> V_17 = V_4 ;
return ( 1 ) ;
V_7:
F_9 ( V_4 ) ;
if ( V_3 != NULL )
F_10 ( V_3 ) ;
return ( 0 ) ;
}
static int F_11 ( T_2 * V_2 )
{
T_3 V_3 ;
if ( V_2 == NULL ) {
F_4 ( V_18 , V_19 ) ;
return ( 0 ) ;
}
if ( F_12 ( V_2 -> V_15 ) < 1 )
return ( 1 ) ;
V_3 = ( T_3 ) F_13 ( V_2 -> V_15 ) ;
if ( V_3 == NULL ) {
F_4 ( V_18 , V_20 ) ;
F_8 ( V_2 -> V_15 , ( char * ) V_3 ) ;
return ( 0 ) ;
}
F_10 ( V_3 ) ;
return ( 1 ) ;
}
static T_4 F_14 ( T_2 * V_2 , const char * V_21 )
{
T_3 V_3 ;
void * V_22 ;
if ( ( V_2 == NULL ) || ( V_21 == NULL ) ) {
F_4 ( V_23 , V_19 ) ;
return ( NULL ) ;
}
if ( F_12 ( V_2 -> V_15 ) < 1 ) {
F_4 ( V_23 , V_16 ) ;
return ( NULL ) ;
}
V_3 = ( T_3 ) F_15 ( V_2 -> V_15 , F_12 ( V_2 -> V_15 ) - 1 ) ;
if ( V_3 == NULL ) {
F_4 ( V_23 , V_20 ) ;
return ( NULL ) ;
}
if ( F_16 ( & V_3 , V_21 , V_24 , & V_22 ) < 0 ) {
char V_12 [ 160 ] ;
F_4 ( V_23 , V_25 ) ;
if ( F_6 ( V_14 , V_12 , sizeof( V_12 ) ) )
F_7 ( 4 , L_3 , V_21 , L_2 , V_12 ) ;
return ( NULL ) ;
}
return ( ( T_4 ) V_22 ) ;
}
static char * F_17 ( T_2 * V_2 , const char * V_26 , const char * V_27 )
{
char * V_28 ;
if ( ! V_26 && ! V_27 ) {
F_4 ( V_29 , V_19 ) ;
return ( NULL ) ;
}
if ( ! V_27 || V_26 [ 0 ] == '/' ) {
V_28 = F_18 ( V_26 ) ;
if ( V_28 == NULL ) {
F_4 ( V_29 , V_30 ) ;
return ( NULL ) ;
}
}
else if ( ! V_26 ) {
V_28 = F_18 ( V_27 ) ;
if ( V_28 == NULL ) {
F_4 ( V_29 , V_30 ) ;
return ( NULL ) ;
}
} else
{
int V_31 , V_32 ;
V_31 = ( V_27 ? strlen ( V_27 ) : 0 ) ;
V_32 = V_31 + ( V_26 ? strlen ( V_26 ) : 0 ) ;
if ( V_31 && V_27 [ V_31 - 1 ] == '/' ) {
V_31 -- ;
V_32 -- ;
}
V_28 = F_19 ( V_32 + 2 ) ;
if ( V_28 == NULL ) {
F_4 ( V_29 , V_30 ) ;
return ( NULL ) ;
}
strcpy ( V_28 , V_27 ) ;
V_28 [ V_31 ] = '/' ;
strcpy ( & V_28 [ V_31 + 1 ] , V_26 ) ;
}
return ( V_28 ) ;
}
static char * F_20 ( T_2 * V_2 , const char * V_4 )
{
char * V_33 ;
int V_32 , V_34 , V_35 ;
V_32 = strlen ( V_4 ) ;
V_34 = V_32 + 1 ;
V_35 = ( strstr ( V_4 , L_4 ) == NULL ) ;
{
V_34 += strlen ( V_36 ) ;
if ( ( F_21 ( V_2 ) & V_37 ) == 0 )
V_34 += 3 ;
}
V_33 = F_19 ( V_34 ) ;
if ( V_33 == NULL ) {
F_4 ( V_38 , V_39 ) ;
return ( NULL ) ;
}
if ( V_35 ) {
if ( ( F_21 ( V_2 ) & V_37 ) == 0 )
sprintf ( V_33 , L_5 , V_4 , V_36 ) ;
else
sprintf ( V_33 , L_6 , V_4 , V_36 ) ;
} else
sprintf ( V_33 , L_7 , V_4 ) ;
return ( V_33 ) ;
}
static void * F_22 ( const char * V_40 )
{
void * V_41 ;
T_3 V_42 = NULL ;
return F_16 ( & V_42 , V_40 , V_24 , & V_41 ) ? NULL : V_41 ;
}

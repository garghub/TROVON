static struct V_1 * F_1 ( const T_1 V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] -> V_5 == V_2 )
return V_4 [ V_3 ] ;
return NULL ;
}
bool F_3 ( T_1 const * V_6 , T_1 V_7 )
{
while ( V_7 > 0 )
if ( F_1 ( V_6 [ -- V_7 ] ) == NULL )
return false ;
return true ;
}
int F_4 ( T_1 * * V_6 , T_1 * V_7 )
{
* V_6 = F_5 ( F_2 ( V_4 ) , F_6 () ) ;
if ( * V_6 == NULL )
return - V_8 ;
for ( * V_7 = 0 ; * V_7 < F_2 ( V_4 ) ; * V_7 += 1 )
( * V_6 ) [ * V_7 ] = V_4 [ * V_7 ] -> V_5 ;
return 0 ;
}
int F_7 ( struct V_9 * V_10 , int V_11 ,
char T_2 * V_12 , int T_2 * V_13 )
{
T_1 * V_6 , V_7 ;
int V_14 = 0 ;
if ( F_4 ( & V_6 , & V_7 ) )
return - V_8 ;
if ( F_8 ( V_7 , V_13 ) )
V_14 = - V_15 ;
else if ( V_11 > 0 && F_9 ( V_12 , V_6 ,
V_11 > V_7 ? V_7 : V_11 ) )
V_14 = - V_15 ;
F_10 ( V_6 ) ;
return V_14 ;
}
static struct V_16 * F_11 ( int V_17 , char * V_18 , const char * V_19 , ... )
{
struct V_16 * V_20 ;
T_3 args ;
va_start ( args , V_19 ) ;
vsnprintf ( V_18 , V_21 , V_19 , args ) ;
va_end ( args ) ;
V_20 = F_12 ( V_18 , sizeof( struct V_22 ) + V_17 , 0 ,
V_23 , NULL ) ;
return V_20 ;
}
static void F_13 ( struct V_16 * V_20 )
{
if ( V_20 != NULL )
F_14 ( V_20 ) ;
}
static int F_15 ( struct V_1 * V_24 )
{
int V_14 = - V_8 ;
V_24 -> V_25 =
F_11 ( V_24 -> V_26 ,
V_24 -> V_27 ,
L_1 ,
V_24 -> V_5 ) ;
if ( V_24 -> V_25 == NULL )
goto V_28;
V_24 -> V_29 =
F_11 ( V_24 -> V_30 ,
V_24 -> V_31 ,
L_2 ,
V_24 -> V_5 ) ;
if ( V_24 -> V_29 == NULL )
goto V_32;
F_16 ( L_3 ,
V_24 -> V_5 , V_24 -> V_33 ) ;
V_14 = 0 ;
V_28:
return V_14 ;
V_32:
F_13 ( V_24 -> V_25 ) ;
V_24 -> V_25 = NULL ;
goto V_28;
}
static void F_17 ( struct V_1 * V_24 )
{
F_13 ( V_24 -> V_29 ) ;
V_24 -> V_29 = NULL ;
F_13 ( V_24 -> V_25 ) ;
V_24 -> V_25 = NULL ;
F_16 ( L_4 ,
V_24 -> V_5 , V_24 -> V_33 ) ;
}
struct V_22 * F_18 ( const T_1 V_2 , struct V_9 * V_10 , bool V_34 )
{
struct V_1 * V_24 = F_1 ( V_2 ) ;
struct V_22 * V_22 = NULL ;
if ( V_24 == NULL )
goto V_28;
V_22 = F_19 ( V_34 ? V_24 -> V_25 :
V_24 -> V_29 , F_6 () ) ;
if ( V_22 == NULL )
goto V_28;
V_22 -> V_24 = V_24 ;
if ( V_34 ) {
memset ( V_22 + 1 , 0 , V_24 -> V_26 ) ;
if ( V_22 -> V_24 -> V_35 != NULL &&
V_22 -> V_24 -> V_35 ( V_22 , V_10 ) != 0 )
goto V_36;
} else {
memset ( V_22 + 1 , 0 , V_24 -> V_30 ) ;
if ( V_22 -> V_24 -> V_37 != NULL &&
V_22 -> V_24 -> V_37 ( V_22 , V_10 ) != 0 )
goto V_36;
}
V_28:
return V_22 ;
V_36:
F_20 ( V_34 ? V_24 -> V_25 :
V_24 -> V_29 , V_22 ) ;
V_22 = NULL ;
goto V_28;
}
void F_21 ( struct V_22 * V_22 , struct V_9 * V_10 )
{
if ( V_22 != NULL ) {
if ( V_22 -> V_24 -> V_38 != NULL )
V_22 -> V_24 -> V_38 ( V_10 ) ;
F_20 ( V_22 -> V_24 -> V_25 , V_22 ) ;
}
}
void F_22 ( struct V_22 * V_22 , struct V_9 * V_10 )
{
if ( V_22 != NULL ) {
if ( V_22 -> V_24 -> V_39 != NULL )
V_22 -> V_24 -> V_39 ( V_10 ) ;
F_20 ( V_22 -> V_24 -> V_29 , V_22 ) ;
}
}
int T_4 F_23 ( void )
{
int V_3 , V_14 = F_24 () ;
if ( V_14 )
return V_14 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
V_14 = F_15 ( V_4 [ V_3 ] ) ;
if ( V_14 )
goto V_40;
}
return 0 ;
V_40:
while( -- V_3 >= 0 )
F_17 ( V_4 [ V_3 ] ) ;
F_25 () ;
return V_14 ;
}
void F_26 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
F_17 ( V_4 [ V_3 ] ) ;
F_25 () ;
}

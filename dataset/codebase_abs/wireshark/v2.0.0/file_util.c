int
F_1 ( const T_1 * V_1 ,
int V_2 ,
int V_3 )
{
T_2 * V_4 = F_2 ( V_1 , - 1 , NULL , NULL , NULL ) ;
int V_5 ;
int V_6 ;
if ( V_4 == NULL )
{
V_7 = V_8 ;
return - 1 ;
}
V_5 = F_3 ( V_4 , V_2 , V_3 ) ;
V_6 = V_7 ;
F_4 ( V_4 ) ;
V_7 = V_6 ;
return V_5 ;
}
int
F_5 ( const T_1 * V_9 ,
const T_1 * V_10 )
{
T_2 * V_11 = F_2 ( V_9 , - 1 , NULL , NULL , NULL ) ;
T_2 * V_12 ;
int V_5 ;
int V_6 = 0 ;
if ( V_11 == NULL )
{
V_7 = V_8 ;
return - 1 ;
}
V_12 = F_2 ( V_10 , - 1 , NULL , NULL , NULL ) ;
if ( V_12 == NULL )
{
F_4 ( V_11 ) ;
V_7 = V_8 ;
return - 1 ;
}
if ( F_6 ( V_11 , V_12 , V_13 ) )
V_5 = 0 ;
else
{
V_5 = - 1 ;
switch ( F_7 () )
{
#define CASE ( T_3 , T_4 ) case ERROR_##a: save_errno = b; break
CASE ( V_14 , V_15 ) ;
CASE ( V_16 , V_15 ) ;
CASE ( V_17 , V_18 ) ;
CASE ( V_19 , V_20 ) ;
CASE ( V_21 , V_18 ) ;
CASE ( V_22 , V_18 ) ;
CASE ( V_23 , V_24 ) ;
CASE ( V_25 , V_24 ) ;
#undef CASE
default: V_6 = V_26 ;
}
}
F_4 ( V_11 ) ;
F_4 ( V_12 ) ;
V_7 = V_6 ;
return V_5 ;
}
int
F_8 ( const T_1 * V_1 ,
int V_3 )
{
T_2 * V_4 = F_2 ( V_1 , - 1 , NULL , NULL , NULL ) ;
int V_5 ;
int V_6 ;
if ( V_4 == NULL )
{
V_7 = V_8 ;
return - 1 ;
}
V_5 = F_9 ( V_4 ) ;
V_6 = V_7 ;
F_4 ( V_4 ) ;
V_7 = V_6 ;
return V_5 ;
}
int
F_10 ( const T_1 * V_1 ,
T_5 * V_27 )
{
T_2 * V_4 = F_2 ( V_1 , - 1 , NULL , NULL , NULL ) ;
int V_5 ;
int V_6 ;
T_6 V_28 ;
if ( V_4 == NULL )
{
V_7 = V_8 ;
return - 1 ;
}
V_28 = wcslen ( V_4 ) ;
while ( V_28 > 0 && F_11 ( V_4 [ V_28 - 1 ] ) )
V_28 -- ;
if ( V_28 > 0 &&
( ! F_12 ( V_1 ) || V_28 > ( T_6 ) ( F_13 ( V_1 ) - V_1 ) ) )
V_4 [ V_28 ] = '\0' ;
V_5 = F_14 ( V_4 , V_27 ) ;
V_6 = V_7 ;
F_4 ( V_4 ) ;
V_7 = V_6 ;
return V_5 ;
}
int
F_15 ( const T_1 * V_1 )
{
T_2 * V_4 = F_2 ( V_1 , - 1 , NULL , NULL , NULL ) ;
int V_5 ;
int V_6 ;
if ( V_4 == NULL )
{
V_7 = V_8 ;
return - 1 ;
}
V_5 = F_16 ( V_4 ) ;
V_6 = V_7 ;
F_4 ( V_4 ) ;
V_7 = V_6 ;
return V_5 ;
}
int
F_17 ( const T_1 * V_1 )
{
T_2 * V_4 = F_2 ( V_1 , - 1 , NULL , NULL , NULL ) ;
int V_5 ;
int V_6 ;
if ( V_4 == NULL )
{
V_7 = V_8 ;
return - 1 ;
}
V_5 = F_18 ( V_4 ) ;
if ( V_5 == - 1 )
V_5 = F_19 ( V_4 ) ;
V_6 = V_7 ;
F_4 ( V_4 ) ;
V_7 = V_6 ;
return V_5 ;
}
T_7 *
F_20 ( const T_1 * V_1 ,
const T_1 * V_3 )
{
T_2 * V_4 = F_2 ( V_1 , - 1 , NULL , NULL , NULL ) ;
T_2 * V_29 ;
T_7 * V_5 ;
int V_6 ;
if ( V_4 == NULL )
{
V_7 = V_8 ;
return NULL ;
}
V_29 = F_2 ( V_3 , - 1 , NULL , NULL , NULL ) ;
if ( V_29 == NULL )
{
F_4 ( V_4 ) ;
V_7 = V_8 ;
return NULL ;
}
V_5 = F_21 ( V_4 , V_29 ) ;
V_6 = V_7 ;
F_4 ( V_4 ) ;
F_4 ( V_29 ) ;
V_7 = V_6 ;
return V_5 ;
}
T_7 *
F_22 ( const T_1 * V_1 ,
const T_1 * V_3 ,
T_7 * V_30 )
{
T_2 * V_4 = F_2 ( V_1 , - 1 , NULL , NULL , NULL ) ;
T_2 * V_29 ;
T_7 * V_5 ;
int V_6 ;
if ( V_4 == NULL )
{
V_7 = V_8 ;
return NULL ;
}
V_29 = F_2 ( V_3 , - 1 , NULL , NULL , NULL ) ;
if ( V_29 == NULL )
{
F_4 ( V_4 ) ;
V_7 = V_8 ;
return NULL ;
}
V_5 = F_23 ( V_4 , V_29 , V_30 ) ;
V_6 = V_7 ;
F_4 ( V_4 ) ;
F_4 ( V_29 ) ;
V_7 = V_6 ;
return V_5 ;
}
static T_8
F_24 ()
{
T_9 V_31 [ V_32 ] ;
if ( V_33 && V_34 )
return TRUE ;
if ( F_25 ( NULL , V_31 , V_32 ) == 0 || F_7 () == V_35 ) {
return FALSE ;
}
if ( ! V_33 ) {
T_1 * V_36 ;
V_36 = F_26 ( V_31 , - 1 , NULL , NULL , NULL ) ;
V_33 = F_27 ( V_36 ) ;
F_4 ( V_36 ) ;
}
if ( F_28 ( V_31 , V_32 ) == 0 ) {
return FALSE ;
}
if ( ! V_34 ) {
V_34 = F_26 ( V_31 , - 1 , NULL , NULL , NULL ) ;
}
if ( V_33 && V_34 )
return TRUE ;
return FALSE ;
}
T_8
F_29 ()
{
T_8 V_37 = FALSE ;
T_2 * V_38 ;
typedef BOOL (F_30 * F_31)( T_10 );
F_31 V_39 ;
V_39 = ( F_31 ) F_32 ( F_33 ( F_34 ( L_1 ) ) , L_2 ) ;
if ( V_39 ) {
V_37 = V_39 ( F_34 ( L_3 ) ) ;
}
if ( ! V_37 && F_24 () ) {
V_38 = F_2 ( V_33 , - 1 , NULL , NULL , NULL ) ;
F_35 ( V_38 ) ;
F_4 ( V_38 ) ;
}
return V_37 ;
}
void *
F_36 ( T_1 * V_40 )
{
T_1 * V_41 ;
T_2 * V_42 ;
T_11 V_43 ;
if ( ! F_24 () || ! V_40 )
return NULL ;
V_41 = F_37 ( V_33 , V_40 ) ;
V_42 = F_2 ( V_41 , - 1 , NULL , NULL , NULL ) ;
if ( V_41 && V_42 ) {
V_43 = F_38 ( V_42 ) ;
if ( V_43 ) {
F_4 ( V_41 ) ;
F_4 ( V_42 ) ;
return V_43 ;
}
}
V_41 = F_37 ( V_34 , V_40 ) ;
V_42 = F_2 ( V_41 , - 1 , NULL , NULL , NULL ) ;
if ( V_41 && V_42 ) {
V_43 = F_38 ( V_42 ) ;
if ( V_43 ) {
F_4 ( V_41 ) ;
F_4 ( V_42 ) ;
return V_43 ;
}
}
return NULL ;
}
T_12 *
F_39 ( T_1 * V_44 , T_13 V_2 )
{
T_1 * V_41 ;
T_12 * V_45 ;
if ( ! F_24 () || ! V_44 )
return NULL ;
V_41 = F_37 ( V_33 , V_44 ) ;
if ( V_41 ) {
V_45 = F_40 ( V_41 , V_2 ) ;
if ( V_45 ) {
F_4 ( V_41 ) ;
return V_45 ;
}
}
V_41 = F_37 ( V_34 , V_44 ) ;
if ( V_41 ) {
V_45 = F_40 ( V_41 , V_2 ) ;
if ( V_45 ) {
F_4 ( V_41 ) ;
return V_45 ;
}
}
return NULL ;
}
char *
F_41 ( const char * V_46 )
{
char * V_47 ;
T_2 * V_48 ;
T_2 * V_49 ;
V_47 = getenv ( V_46 ) ;
V_49 = F_2 ( V_46 , - 1 , NULL , NULL , NULL ) ;
if ( V_49 == NULL ) {
return V_47 ;
}
V_48 = F_42 ( V_49 ) ;
F_4 ( V_49 ) ;
if ( V_48 == NULL ) {
return V_47 ;
}
V_47 = F_26 ( V_48 , - 1 , NULL , NULL , NULL ) ;
return V_47 ;
}
void F_43 () {
T_14 * V_50 = NULL ;
if ( ! V_51 ) V_51 = F_44 ( T_14 , 1 ) ;
V_51 -> V_52 = sizeof( T_14 ) ;
V_51 -> V_53 = F_44 ( V_54 , 1 ) ;
V_51 -> V_55 = TRUE ;
if ( F_45 ( V_51 -> V_53 , V_56 ) ) {
if ( F_46 ( V_51 -> V_53 , TRUE , NULL , FALSE ) ) {
V_50 = V_51 ;
}
}
if ( ! V_50 ) {
F_4 ( V_51 -> V_53 ) ;
F_4 ( V_51 ) ;
V_51 = NULL ;
}
F_47 ( V_50 , FALSE , F_34 ( L_4 ) F_34 (WIRESHARK_IS_RUNNING_UUID) F_34 ( L_5 ) ) ;
F_47 ( V_50 , FALSE , F_34 ( L_6 ) F_34 (WIRESHARK_IS_RUNNING_UUID) F_34 ( L_5 ) ) ;
}

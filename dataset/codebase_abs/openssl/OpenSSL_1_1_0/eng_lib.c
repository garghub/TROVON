T_1 * F_1 ( void )
{
T_1 * V_1 ;
if ( ! F_2 ( & V_2 , V_3 )
|| ( V_1 = F_3 ( sizeof( * V_1 ) ) ) == NULL ) {
F_4 ( V_4 , V_5 ) ;
return NULL ;
}
V_1 -> V_6 = 1 ;
F_5 ( V_1 , 0 , 1 ) ;
if ( ! F_6 ( V_7 , V_1 , & V_1 -> V_8 ) ) {
F_7 ( V_1 ) ;
return NULL ;
}
return V_1 ;
}
void F_8 ( T_1 * V_9 )
{
V_9 -> V_10 = NULL ;
V_9 -> V_11 = NULL ;
V_9 -> V_12 = NULL ;
V_9 -> V_13 = NULL ;
V_9 -> V_14 = NULL ;
V_9 -> V_15 = NULL ;
V_9 -> V_16 = NULL ;
V_9 -> V_17 = NULL ;
V_9 -> V_18 = NULL ;
V_9 -> V_19 = NULL ;
V_9 -> V_20 = NULL ;
V_9 -> V_21 = NULL ;
V_9 -> V_22 = NULL ;
V_9 -> V_23 = NULL ;
V_9 -> V_24 = NULL ;
V_9 -> V_25 = 0 ;
}
int F_9 ( T_1 * V_9 , int V_26 )
{
int V_27 ;
if ( V_9 == NULL )
return 1 ;
if ( V_26 )
F_10 ( & V_9 -> V_6 , - 1 , & V_27 , V_28 ) ;
else
V_27 = -- V_9 -> V_6 ;
F_5 (e, 0 , -1 )
if ( V_27 > 0 )
return 1 ;
F_11 ( V_27 < 0 ) ;
F_12 ( V_9 ) ;
F_13 ( V_9 ) ;
if ( V_9 -> V_18 )
V_9 -> V_18 ( V_9 ) ;
F_14 ( V_7 , V_9 , & V_9 -> V_8 ) ;
F_7 ( V_9 ) ;
return 1 ;
}
int F_15 ( T_1 * V_9 )
{
return F_9 ( V_9 , 1 ) ;
}
static int F_16 ( int V_29 )
{
if ( V_30 )
return 1 ;
if ( ! V_29 )
return 0 ;
V_30 = F_17 () ;
return ( V_30 ? 1 : 0 ) ;
}
static T_2 * F_18 ( T_3 * V_31 )
{
T_2 * V_32 = F_19 ( sizeof( * V_32 ) ) ;
if ( V_32 == NULL )
return NULL ;
V_32 -> V_31 = V_31 ;
return V_32 ;
}
void F_20 ( T_3 * V_31 )
{
T_2 * V_32 ;
if ( ! F_16 ( 1 ) )
return;
V_32 = F_18 ( V_31 ) ;
if ( V_32 )
F_21 ( V_30 , V_32 , 0 ) ;
}
void F_22 ( T_3 * V_31 )
{
T_2 * V_32 ;
if ( ! F_16 ( 1 ) )
return;
V_32 = F_18 ( V_31 ) ;
if ( V_32 )
F_23 ( V_30 , V_32 ) ;
}
static void F_24 ( T_2 * V_32 )
{
( * ( V_32 -> V_31 ) ) ( ) ;
F_7 ( V_32 ) ;
}
void F_25 ( void )
{
if ( F_16 ( 0 ) ) {
F_26 ( V_30 ,
F_24 ) ;
V_30 = NULL ;
}
F_27 ( NULL ) ;
F_28 ( V_28 ) ;
}
int F_29 ( T_1 * V_9 , int V_33 , void * V_34 )
{
return ( F_30 ( & V_9 -> V_8 , V_33 , V_34 ) ) ;
}
void * F_31 ( const T_1 * V_9 , int V_33 )
{
return ( F_32 ( & V_9 -> V_8 , V_33 ) ) ;
}
int F_33 ( T_1 * V_9 , const char * V_10 )
{
if ( V_10 == NULL ) {
F_4 ( V_35 , V_36 ) ;
return 0 ;
}
V_9 -> V_10 = V_10 ;
return 1 ;
}
int F_34 ( T_1 * V_9 , const char * V_11 )
{
if ( V_11 == NULL ) {
F_4 ( V_37 , V_36 ) ;
return 0 ;
}
V_9 -> V_11 = V_11 ;
return 1 ;
}
int F_35 ( T_1 * V_9 , T_4 V_38 )
{
V_9 -> V_18 = V_38 ;
return 1 ;
}
int F_36 ( T_1 * V_9 , T_4 V_39 )
{
V_9 -> V_19 = V_39 ;
return 1 ;
}
int F_37 ( T_1 * V_9 , T_4 V_40 )
{
V_9 -> V_20 = V_40 ;
return 1 ;
}
int F_38 ( T_1 * V_9 , T_5 V_41 )
{
V_9 -> V_21 = V_41 ;
return 1 ;
}
int F_39 ( T_1 * V_9 , int V_25 )
{
V_9 -> V_25 = V_25 ;
return 1 ;
}
int F_40 ( T_1 * V_9 , const T_6 * V_42 )
{
V_9 -> V_24 = V_42 ;
return 1 ;
}
const char * F_41 ( const T_1 * V_9 )
{
return V_9 -> V_10 ;
}
const char * F_42 ( const T_1 * V_9 )
{
return V_9 -> V_11 ;
}
T_4 F_43 ( const T_1 * V_9 )
{
return V_9 -> V_18 ;
}
T_4 F_44 ( const T_1 * V_9 )
{
return V_9 -> V_19 ;
}
T_4 F_45 ( const T_1 * V_9 )
{
return V_9 -> V_20 ;
}
T_5 F_46 ( const T_1 * V_9 )
{
return V_9 -> V_21 ;
}
int F_47 ( const T_1 * V_9 )
{
return V_9 -> V_25 ;
}
const T_6 * F_48 ( const T_1 * V_9 )
{
return V_9 -> V_24 ;
}
void * F_49 ( void )
{
return & V_43 ;
}

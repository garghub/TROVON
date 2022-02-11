static char * F_1 ( const char * V_1 )
{
return F_2 ( V_1 ) ;
}
static void F_3 ( char * V_1 )
{
F_4 ( V_1 ) ;
}
static int F_5 ( T_1 * V_2 , int V_3 ,
const char * V_4 , T_2 V_5 )
{
char * V_6 ;
if ( V_5 == 0 )
V_5 = V_4 ? strlen ( V_4 ) : 0 ;
else if ( V_4 && memchr ( V_4 , '\0' , V_5 > 1 ? V_5 - 1 : V_5 ) )
return 0 ;
if ( V_4 && V_4 [ V_5 - 1 ] == '\0' )
-- V_5 ;
if ( V_3 == V_7 && V_2 -> V_8 ) {
F_6 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
if ( V_4 == NULL || V_5 == 0 )
return 1 ;
V_6 = F_7 ( V_4 , V_5 ) ;
if ( V_6 == NULL )
return 0 ;
if ( V_2 -> V_8 == NULL &&
( V_2 -> V_8 = F_8 () ) == NULL ) {
F_4 ( V_6 ) ;
return 0 ;
}
if ( ! F_9 ( V_2 -> V_8 , V_6 ) ) {
F_4 ( V_6 ) ;
if ( F_10 ( V_2 -> V_8 ) == 0 ) {
F_11 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
return 0 ;
}
return 1 ;
}
static void F_12 ( T_3 * V_9 )
{
T_1 * V_10 ;
if ( ! V_9 )
return;
V_9 -> V_4 = NULL ;
V_9 -> V_11 = 0 ;
V_9 -> V_12 = 0 ;
V_9 -> V_13 = 0 ;
V_9 -> V_14 = 0 ;
V_9 -> V_15 = - 1 ;
if ( V_9 -> V_16 ) {
F_13 ( V_9 -> V_16 , V_17 ) ;
V_9 -> V_16 = NULL ;
}
V_10 = V_9 -> V_2 ;
if ( V_10 -> V_8 ) {
F_6 ( V_10 -> V_8 ) ;
V_10 -> V_8 = NULL ;
}
if ( V_10 -> V_18 )
F_4 ( V_10 -> V_18 ) ;
if ( V_10 -> V_19 ) {
F_4 ( V_10 -> V_19 ) ;
V_10 -> V_19 = NULL ;
V_10 -> V_20 = 0 ;
}
if ( V_10 -> V_21 ) {
F_4 ( V_10 -> V_21 ) ;
V_10 -> V_21 = NULL ;
V_10 -> V_22 = 0 ;
}
}
T_3 * F_14 ( void )
{
T_3 * V_9 ;
T_1 * V_10 ;
V_9 = F_15 ( sizeof( T_3 ) ) ;
if ( ! V_9 )
return NULL ;
V_10 = F_15 ( sizeof( T_3 ) ) ;
if ( ! V_10 ) {
F_4 ( V_9 ) ;
return NULL ;
}
memset ( V_9 , 0 , sizeof( T_3 ) ) ;
memset ( V_10 , 0 , sizeof( T_1 ) ) ;
V_9 -> V_2 = V_10 ;
F_12 ( V_9 ) ;
return V_9 ;
}
void F_16 ( T_3 * V_9 )
{
F_12 ( V_9 ) ;
F_4 ( V_9 -> V_2 ) ;
F_4 ( V_9 ) ;
}
int F_17 ( T_3 * V_23 ,
const T_3 * V_24 )
{
unsigned long V_13 ;
int V_25 , V_26 ;
T_1 * V_2 ;
if ( ! V_24 )
return 1 ;
V_2 = V_24 -> V_2 ;
V_13 = V_23 -> V_13 | V_24 -> V_13 ;
if ( V_13 & V_27 )
V_23 -> V_13 = 0 ;
if ( V_13 & V_28 )
return 1 ;
if ( V_13 & V_29 )
V_25 = 1 ;
else
V_25 = 0 ;
if ( V_13 & V_30 )
V_26 = 1 ;
else
V_26 = 0 ;
F_18 ( V_11 , 0 ) ;
F_18 ( V_12 , 0 ) ;
F_18 ( V_15 , - 1 ) ;
if ( V_26 || ! ( V_23 -> V_14 & V_31 ) ) {
V_23 -> V_32 = V_24 -> V_32 ;
V_23 -> V_14 &= ~ V_31 ;
}
if ( V_13 & V_33 )
V_23 -> V_14 = 0 ;
V_23 -> V_14 |= V_24 -> V_14 ;
if ( F_19 ( V_16 , NULL ) ) {
if ( ! F_20 ( V_23 , V_24 -> V_16 ) )
return 0 ;
}
if ( F_21 ( V_8 , NULL ) ) {
if ( V_23 -> V_2 -> V_8 ) {
F_6 ( V_23 -> V_2 -> V_8 ) ;
V_23 -> V_2 -> V_8 = NULL ;
}
if ( V_2 -> V_8 ) {
V_23 -> V_2 -> V_8 =
F_22 ( V_2 -> V_8 , F_1 , F_3 ) ;
if ( V_23 -> V_2 -> V_8 == NULL )
return 0 ;
V_23 -> V_2 -> V_34 = V_2 -> V_34 ;
}
}
if ( F_21 ( V_19 , NULL ) ) {
if ( ! F_23 ( V_23 , V_2 -> V_19 , V_2 -> V_20 ) )
return 0 ;
}
if ( F_21 ( V_21 , NULL ) ) {
if ( ! F_24 ( V_23 , V_2 -> V_21 , V_2 -> V_22 ) )
return 0 ;
}
return 1 ;
}
int F_25 ( T_3 * V_35 ,
const T_3 * V_36 )
{
unsigned long V_37 = V_35 -> V_13 ;
int V_38 ;
V_35 -> V_13 |= V_29 ;
V_38 = F_17 ( V_35 , V_36 ) ;
V_35 -> V_13 = V_37 ;
return V_38 ;
}
static int F_26 ( char * * V_39 , T_2 * V_40 ,
const char * V_24 , T_2 V_41 )
{
void * V_42 ;
if ( V_24 ) {
if ( V_41 == 0 ) {
V_42 = F_27 ( V_24 ) ;
V_41 = strlen ( V_24 ) ;
} else
V_42 = F_28 ( V_24 , V_41 ) ;
if ( ! V_42 )
return 0 ;
} else {
V_42 = NULL ;
V_41 = 0 ;
}
if ( * V_39 )
F_4 ( * V_39 ) ;
* V_39 = V_42 ;
if ( V_40 )
* V_40 = V_41 ;
return 1 ;
}
int F_29 ( T_3 * V_9 , const char * V_4 )
{
if ( V_9 -> V_4 )
F_4 ( V_9 -> V_4 ) ;
V_9 -> V_4 = F_27 ( V_4 ) ;
if ( V_9 -> V_4 )
return 1 ;
return 0 ;
}
int F_30 ( T_3 * V_9 , unsigned long V_14 )
{
V_9 -> V_14 |= V_14 ;
if ( V_14 & V_43 )
V_9 -> V_14 |= V_44 ;
return 1 ;
}
int F_31 ( T_3 * V_9 ,
unsigned long V_14 )
{
V_9 -> V_14 &= ~ V_14 ;
return 1 ;
}
unsigned long F_32 ( T_3 * V_9 )
{
return V_9 -> V_14 ;
}
int F_33 ( T_3 * V_9 , int V_11 )
{
return F_34 ( & V_9 -> V_11 , V_11 ) ;
}
int F_35 ( T_3 * V_9 , int V_12 )
{
return F_36 ( & V_9 -> V_12 , V_12 ) ;
}
void F_37 ( T_3 * V_9 , int V_15 )
{
V_9 -> V_15 = V_15 ;
}
void F_38 ( T_3 * V_9 , T_4 V_45 )
{
V_9 -> V_32 = V_45 ;
V_9 -> V_14 |= V_31 ;
}
int F_39 ( T_3 * V_9 ,
T_5 * V_46 )
{
if ( ! V_9 -> V_16 ) {
V_9 -> V_16 = F_40 () ;
if ( ! V_9 -> V_16 )
return 0 ;
}
if ( ! F_41 ( V_9 -> V_16 , V_46 ) )
return 0 ;
return 1 ;
}
int F_42 ( T_3 * V_9 ,
const char * V_4 , T_2 V_5 )
{
return F_5 ( V_9 -> V_2 , V_7 , V_4 , V_5 ) ;
}
int F_43 ( T_3 * V_9 ,
const char * V_4 , T_2 V_5 )
{
return F_5 ( V_9 -> V_2 , V_47 , V_4 , V_5 ) ;
}
void F_44 ( T_3 * V_9 ,
unsigned int V_14 )
{
V_9 -> V_2 -> V_34 = V_14 ;
}
char * F_45 ( T_3 * V_9 )
{
return V_9 -> V_2 -> V_18 ;
}
int F_23 ( T_3 * V_9 ,
const char * V_19 , T_2 V_20 )
{
return F_26 ( & V_9 -> V_2 -> V_19 , & V_9 -> V_2 -> V_20 ,
V_19 , V_20 ) ;
}
int F_24 ( T_3 * V_9 ,
const unsigned char * V_21 , T_2 V_22 )
{
if ( V_22 != 0 && V_22 != 4 && V_22 != 16 )
return 0 ;
return F_26 ( ( char * * ) & V_9 -> V_2 -> V_21 , & V_9 -> V_2 -> V_22 ,
( char * ) V_21 , V_22 ) ;
}
int F_46 ( T_3 * V_9 , const char * V_48 )
{
unsigned char V_49 [ 16 ] ;
T_2 V_22 ;
V_22 = ( T_2 ) F_47 ( V_49 , V_48 ) ;
if ( V_22 == 0 )
return 0 ;
return F_24 ( V_9 , V_49 , V_22 ) ;
}
int F_48 ( const T_3 * V_9 )
{
return V_9 -> V_15 ;
}
const char * F_49 ( const T_3 * V_9 )
{
return V_9 -> V_4 ;
}
static int F_50 ( const T_3 * V_50 , const T_3 * V_51 )
{
return strcmp ( V_50 -> V_4 , V_51 -> V_4 ) ;
}
static int F_51 ( const T_3 * const * V_50 ,
const T_3 * const * V_51 )
{
return strcmp ( ( * V_50 ) -> V_4 , ( * V_51 ) -> V_4 ) ;
}
int F_52 ( T_3 * V_9 )
{
int V_52 ;
T_3 * V_53 ;
if ( ! V_54 ) {
V_54 = F_53 ( F_51 ) ;
if ( ! V_54 )
return 0 ;
} else {
V_52 = F_54 ( V_54 , V_9 ) ;
if ( V_52 != - 1 ) {
V_53 = F_55 ( V_54 , V_52 ) ;
F_16 ( V_53 ) ;
( void ) F_56 ( V_54 , V_52 ) ;
}
}
if ( ! F_57 ( V_54 , V_9 ) )
return 0 ;
return 1 ;
}
int F_58 ( void )
{
int V_55 = sizeof( V_56 ) / sizeof( T_3 ) ;
if ( V_54 )
V_55 += F_59 ( V_54 ) ;
return V_55 ;
}
const T_3 * F_60 ( int V_2 )
{
int V_55 = sizeof( V_56 ) / sizeof( T_3 ) ;
if ( V_2 < V_55 )
return V_56 + V_2 ;
return F_55 ( V_54 , V_2 - V_55 ) ;
}
const T_3 * F_61 ( const char * V_4 )
{
int V_52 ;
T_3 V_57 ;
V_57 . V_4 = ( char * ) V_4 ;
if ( V_54 ) {
V_52 = F_54 ( V_54 , & V_57 ) ;
if ( V_52 != - 1 )
return F_55 ( V_54 , V_52 ) ;
}
return F_62 ( & V_57 , V_56 ,
sizeof( V_56 ) /
sizeof( T_3 ) ) ;
}
void F_63 ( void )
{
if ( V_54 )
F_64 ( V_54 , F_16 ) ;
V_54 = NULL ;
}

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
if ( V_5 == 0 || V_4 == NULL )
V_5 = V_4 ? strlen ( V_4 ) : 0 ;
else if ( V_4 && memchr ( V_4 , '\0' , V_5 > 1 ? V_5 - 1 : V_5 ) )
return 0 ;
if ( V_5 > 0 && V_4 [ V_5 - 1 ] == '\0' )
-- V_5 ;
if ( V_3 == V_7 ) {
F_6 ( V_2 -> V_8 , F_3 ) ;
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
static void F_12 ( T_1 * V_9 )
{
if ( ! V_9 )
return;
V_9 -> V_4 = NULL ;
V_9 -> V_10 = 0 ;
V_9 -> V_11 = V_12 ;
V_9 -> V_13 = 0 ;
V_9 -> V_14 = 0 ;
V_9 -> V_15 = - 1 ;
V_9 -> V_16 = - 1 ;
F_13 ( V_9 -> V_17 , V_18 ) ;
V_9 -> V_17 = NULL ;
F_6 ( V_9 -> V_8 , F_3 ) ;
V_9 -> V_8 = NULL ;
F_4 ( V_9 -> V_19 ) ;
V_9 -> V_19 = NULL ;
F_4 ( V_9 -> V_20 ) ;
V_9 -> V_20 = NULL ;
V_9 -> V_21 = 0 ;
F_4 ( V_9 -> V_22 ) ;
V_9 -> V_22 = NULL ;
V_9 -> V_23 = 0 ;
}
T_1 * F_14 ( void )
{
T_1 * V_9 ;
V_9 = F_15 ( sizeof( * V_9 ) ) ;
if ( V_9 == NULL )
return NULL ;
F_12 ( V_9 ) ;
return V_9 ;
}
void F_16 ( T_1 * V_9 )
{
if ( ! V_9 )
return;
F_12 ( V_9 ) ;
F_4 ( V_9 ) ;
}
int F_17 ( T_1 * V_24 ,
const T_1 * V_25 )
{
unsigned long V_13 ;
int V_26 , V_27 ;
if ( ! V_25 )
return 1 ;
V_13 = V_24 -> V_13 | V_25 -> V_13 ;
if ( V_13 & V_28 )
V_24 -> V_13 = 0 ;
if ( V_13 & V_29 )
return 1 ;
if ( V_13 & V_30 )
V_26 = 1 ;
else
V_26 = 0 ;
if ( V_13 & V_31 )
V_27 = 1 ;
else
V_27 = 0 ;
F_18 ( V_10 , 0 ) ;
F_18 ( V_11 , V_12 ) ;
F_18 ( V_15 , - 1 ) ;
F_18 ( V_16 , - 1 ) ;
if ( V_27 || ! ( V_24 -> V_14 & V_32 ) ) {
V_24 -> V_33 = V_25 -> V_33 ;
V_24 -> V_14 &= ~ V_32 ;
}
if ( V_13 & V_34 )
V_24 -> V_14 = 0 ;
V_24 -> V_14 |= V_25 -> V_14 ;
if ( F_19 ( V_17 , NULL ) ) {
if ( ! F_20 ( V_24 , V_25 -> V_17 ) )
return 0 ;
}
if ( F_19 ( V_8 , NULL ) ) {
F_6 ( V_24 -> V_8 , F_3 ) ;
V_24 -> V_8 = NULL ;
if ( V_25 -> V_8 ) {
V_24 -> V_8 =
F_21 ( V_25 -> V_8 , F_1 , F_3 ) ;
if ( V_24 -> V_8 == NULL )
return 0 ;
V_24 -> V_35 = V_25 -> V_35 ;
}
}
if ( F_19 ( V_20 , NULL ) ) {
if ( ! F_22 ( V_24 , V_25 -> V_20 , V_25 -> V_21 ) )
return 0 ;
}
if ( F_19 ( V_22 , NULL ) ) {
if ( ! F_23 ( V_24 , V_25 -> V_22 , V_25 -> V_23 ) )
return 0 ;
}
return 1 ;
}
int F_24 ( T_1 * V_36 ,
const T_1 * V_37 )
{
unsigned long V_38 = V_36 -> V_13 ;
int V_39 ;
V_36 -> V_13 |= V_30 ;
V_39 = F_17 ( V_36 , V_37 ) ;
V_36 -> V_13 = V_38 ;
return V_39 ;
}
static int F_25 ( char * * V_40 , T_2 * V_41 ,
const char * V_25 , T_2 V_42 )
{
void * V_43 ;
if ( V_25 ) {
if ( V_42 == 0 )
V_42 = strlen ( V_25 ) ;
V_43 = F_26 ( V_25 , V_42 ) ;
if ( V_43 == NULL )
return 0 ;
} else {
V_43 = NULL ;
V_42 = 0 ;
}
F_4 ( * V_40 ) ;
* V_40 = V_43 ;
if ( V_41 != NULL )
* V_41 = V_42 ;
return 1 ;
}
int F_27 ( T_1 * V_9 , const char * V_4 )
{
F_4 ( V_9 -> V_4 ) ;
V_9 -> V_4 = F_2 ( V_4 ) ;
if ( V_9 -> V_4 )
return 1 ;
return 0 ;
}
int F_28 ( T_1 * V_9 , unsigned long V_14 )
{
V_9 -> V_14 |= V_14 ;
if ( V_14 & V_44 )
V_9 -> V_14 |= V_45 ;
return 1 ;
}
int F_29 ( T_1 * V_9 ,
unsigned long V_14 )
{
V_9 -> V_14 &= ~ V_14 ;
return 1 ;
}
unsigned long F_30 ( T_1 * V_9 )
{
return V_9 -> V_14 ;
}
int F_31 ( T_1 * V_9 , int V_10 )
{
return F_32 ( & V_9 -> V_10 , V_10 ) ;
}
int F_33 ( T_1 * V_9 , int V_11 )
{
return F_34 ( & V_9 -> V_11 , V_11 ) ;
}
void F_35 ( T_1 * V_9 , int V_15 )
{
V_9 -> V_15 = V_15 ;
}
void F_36 ( T_1 * V_9 , int V_16 )
{
V_9 -> V_16 = V_16 ;
}
void F_37 ( T_1 * V_9 , T_3 V_46 )
{
V_9 -> V_33 = V_46 ;
V_9 -> V_14 |= V_32 ;
}
int F_38 ( T_1 * V_9 ,
T_4 * V_47 )
{
if ( ! V_9 -> V_17 ) {
V_9 -> V_17 = F_39 () ;
if ( ! V_9 -> V_17 )
return 0 ;
}
if ( ! F_40 ( V_9 -> V_17 , V_47 ) )
return 0 ;
return 1 ;
}
int F_41 ( T_1 * V_9 ,
const char * V_4 , T_2 V_5 )
{
return F_5 ( V_9 , V_7 , V_4 , V_5 ) ;
}
int F_42 ( T_1 * V_9 ,
const char * V_4 , T_2 V_5 )
{
return F_5 ( V_9 , V_48 , V_4 , V_5 ) ;
}
void F_43 ( T_1 * V_9 ,
unsigned int V_14 )
{
V_9 -> V_35 = V_14 ;
}
char * F_44 ( T_1 * V_9 )
{
return V_9 -> V_19 ;
}
void F_45 ( T_1 * V_36 ,
T_1 * V_37 )
{
char * V_19 = ( V_37 != NULL ) ? V_37 -> V_19 : NULL ;
if ( V_36 -> V_19 != V_19 ) {
F_4 ( V_36 -> V_19 ) ;
V_36 -> V_19 = V_19 ;
}
if ( V_37 )
V_37 -> V_19 = NULL ;
}
int F_22 ( T_1 * V_9 ,
const char * V_20 , T_2 V_21 )
{
return F_25 ( & V_9 -> V_20 , & V_9 -> V_21 ,
V_20 , V_21 ) ;
}
int F_23 ( T_1 * V_9 ,
const unsigned char * V_22 , T_2 V_23 )
{
if ( V_23 != 0 && V_23 != 4 && V_23 != 16 )
return 0 ;
return F_25 ( ( char * * ) & V_9 -> V_22 , & V_9 -> V_23 ,
( char * ) V_22 , V_23 ) ;
}
int F_46 ( T_1 * V_9 , const char * V_49 )
{
unsigned char V_50 [ 16 ] ;
T_2 V_23 ;
V_23 = ( T_2 ) F_47 ( V_50 , V_49 ) ;
if ( V_23 == 0 )
return 0 ;
return F_23 ( V_9 , V_50 , V_23 ) ;
}
int F_48 ( const T_1 * V_9 )
{
return V_9 -> V_15 ;
}
int F_49 ( const T_1 * V_9 )
{
return V_9 -> V_16 ;
}
const char * F_50 ( const T_1 * V_9 )
{
return V_9 -> V_4 ;
}
static int F_51 ( const T_1 * V_51 , const T_1 * V_52 )
{
return strcmp ( V_51 -> V_4 , V_52 -> V_4 ) ;
}
static int F_52 ( const T_1 * const * V_51 ,
const T_1 * const * V_52 )
{
return strcmp ( ( * V_51 ) -> V_4 , ( * V_52 ) -> V_4 ) ;
}
int F_53 ( T_1 * V_9 )
{
int V_53 ;
T_1 * V_54 ;
if ( V_55 == NULL ) {
V_55 = F_54 ( F_52 ) ;
if ( V_55 == NULL )
return 0 ;
} else {
V_53 = F_55 ( V_55 , V_9 ) ;
if ( V_53 != - 1 ) {
V_54 = F_56 ( V_55 , V_53 ) ;
F_16 ( V_54 ) ;
( void ) F_57 ( V_55 , V_53 ) ;
}
}
if ( ! F_58 ( V_55 , V_9 ) )
return 0 ;
return 1 ;
}
int F_59 ( void )
{
int V_56 = F_60 ( V_57 ) ;
if ( V_55 )
V_56 += F_61 ( V_55 ) ;
return V_56 ;
}
const T_1 * F_62 ( int V_58 )
{
int V_56 = F_60 ( V_57 ) ;
if ( V_58 < V_56 )
return V_57 + V_58 ;
return F_56 ( V_55 , V_58 - V_56 ) ;
}
const T_1 * F_63 ( const char * V_4 )
{
int V_53 ;
T_1 V_59 ;
V_59 . V_4 = ( char * ) V_4 ;
if ( V_55 ) {
V_53 = F_55 ( V_55 , & V_59 ) ;
if ( V_53 != - 1 )
return F_56 ( V_55 , V_53 ) ;
}
return F_64 ( & V_59 , V_57 , F_60 ( V_57 ) ) ;
}
void F_65 ( void )
{
F_66 ( V_55 , F_16 ) ;
V_55 = NULL ;
}

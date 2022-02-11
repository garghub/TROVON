int F_1 ( const T_1 * V_1 , const char * V_2 ,
unsigned long V_3 )
{
F_2 ( V_4 ) * V_5 ;
V_4 * V_6 ;
char * V_7 = NULL ;
int V_8 , V_9 ;
if ( ! V_1 )
return 1 ;
if ( V_2 )
V_7 = F_3 ( V_1 , NULL , V_2 ) ;
if ( ! V_2 || ( ! V_7 && ( V_3 & V_10 ) ) )
V_7 = F_3 ( V_1 , NULL , L_1 ) ;
if ( ! V_7 ) {
F_4 () ;
return 1 ;
}
V_5 = F_5 ( V_1 , V_7 ) ;
if ( ! V_5 )
return 0 ;
for ( V_9 = 0 ; V_9 < F_6 ( V_5 ) ; V_9 ++ ) {
V_6 = F_7 ( V_5 , V_9 ) ;
V_8 = F_8 ( V_1 , V_6 -> V_11 , V_6 -> V_12 , V_3 ) ;
if ( V_8 <= 0 )
if ( ! ( V_3 & V_13 ) )
return V_8 ;
}
return 1 ;
}
int F_9 ( const char * V_14 , const char * V_2 ,
unsigned long V_3 )
{
char * V_15 = NULL ;
T_1 * V_16 = NULL ;
int V_8 = 0 ;
V_16 = F_10 ( NULL ) ;
if ( V_16 == NULL )
goto V_17;
if ( V_14 == NULL ) {
V_15 = F_11 () ;
if ( ! V_15 )
goto V_17;
} else
V_15 = ( char * ) V_14 ;
if ( F_12 ( V_16 , V_15 , NULL ) <= 0 ) {
if ( ( V_3 & V_18 ) &&
( F_13 ( F_14 () ) == V_19 ) ) {
F_4 () ;
V_8 = 1 ;
}
goto V_17;
}
V_8 = F_1 ( V_16 , V_2 , V_3 ) ;
V_17:
if ( V_14 == NULL )
F_15 ( V_15 ) ;
F_16 ( V_16 ) ;
return V_8 ;
}
static int F_8 ( const T_1 * V_1 , const char * V_11 , const char * V_12 ,
unsigned long V_3 )
{
T_2 * V_20 ;
int V_8 ;
V_20 = F_17 ( V_11 ) ;
if ( ! V_20 && ! ( V_3 & V_21 ) )
V_20 = F_18 ( V_1 , V_11 , V_12 ) ;
if ( ! V_20 ) {
if ( ! ( V_3 & V_22 ) ) {
F_19 ( V_23 , V_24 ) ;
F_20 ( 2 , L_2 , V_11 ) ;
}
return - 1 ;
}
V_8 = F_21 ( V_20 , V_11 , V_12 , V_1 ) ;
if ( V_8 <= 0 ) {
if ( ! ( V_3 & V_22 ) ) {
char V_25 [ F_22 ( V_8 ) + 1 ] ;
F_19 ( V_23 , V_26 ) ;
F_23 ( V_25 , sizeof V_25 , L_3 , V_8 ) ;
F_20 ( 6 , L_2 , V_11 , L_4 , V_12 ,
L_5 , V_25 ) ;
}
}
return V_8 ;
}
static T_2 * F_18 ( const T_1 * V_1 ,
const char * V_11 , const char * V_12 )
{
T_3 * V_27 = NULL ;
T_4 * V_28 ;
T_5 * V_29 ;
const char * V_30 = NULL ;
int V_31 = 0 ;
T_2 * V_20 ;
V_30 = F_3 ( V_1 , V_12 , L_6 ) ;
if ( ! V_30 ) {
F_4 () ;
V_30 = V_11 ;
}
V_27 = F_24 ( NULL , V_30 , NULL , 0 ) ;
if ( ! V_27 ) {
V_31 = V_32 ;
goto V_17;
}
V_28 = ( T_4 * ) F_25 ( V_27 , V_33 ) ;
if ( ! V_28 ) {
V_31 = V_34 ;
goto V_17;
}
V_29 = ( T_5 * ) F_25 ( V_27 , V_35 ) ;
V_20 = F_26 ( V_27 , V_11 , V_28 , V_29 ) ;
if ( ! V_20 )
goto V_17;
return V_20 ;
V_17:
F_27 ( V_27 ) ;
F_19 ( V_36 , V_31 ) ;
F_20 ( 4 , L_2 , V_11 , L_7 , V_30 ) ;
return NULL ;
}
static T_2 * F_26 ( T_3 * V_27 , const char * V_11 ,
T_4 * V_28 , T_5 * V_29 )
{
T_2 * V_37 = NULL ;
if ( V_38 == NULL )
V_38 = F_28 () ;
if ( V_38 == NULL )
return NULL ;
V_37 = F_29 ( sizeof( * V_37 ) ) ;
if ( V_37 == NULL )
return NULL ;
V_37 -> V_27 = V_27 ;
V_37 -> V_11 = F_30 ( V_11 ) ;
V_37 -> V_39 = V_28 ;
V_37 -> V_40 = V_29 ;
if ( V_37 -> V_11 == NULL ) {
F_15 ( V_37 ) ;
return NULL ;
}
if ( ! F_31 ( V_38 , V_37 ) ) {
F_15 ( V_37 -> V_11 ) ;
F_15 ( V_37 ) ;
return NULL ;
}
return V_37 ;
}
static T_2 * F_17 ( const char * V_11 )
{
T_2 * V_37 ;
int V_9 , V_41 ;
char * V_42 ;
V_42 = strrchr ( V_11 , '.' ) ;
if ( V_42 )
V_41 = V_42 - V_11 ;
else
V_41 = strlen ( V_11 ) ;
for ( V_9 = 0 ; V_9 < F_32 ( V_38 ) ; V_9 ++ ) {
V_37 = F_33 ( V_38 , V_9 ) ;
if ( strncmp ( V_37 -> V_11 , V_11 , V_41 ) == 0 )
return V_37 ;
}
return NULL ;
}
static int F_21 ( T_2 * V_43 , const char * V_11 , const char * V_12 ,
const T_1 * V_1 )
{
int V_8 = 1 ;
int V_44 = 0 ;
T_6 * V_45 = NULL ;
V_45 = F_34 ( sizeof( * V_45 ) ) ;
if ( V_45 == NULL )
goto V_17;
V_45 -> V_43 = V_43 ;
V_45 -> V_11 = F_30 ( V_11 ) ;
V_45 -> V_12 = F_30 ( V_12 ) ;
V_45 -> V_46 = NULL ;
if ( ! V_45 -> V_11 || ! V_45 -> V_12 )
goto V_47;
if ( V_43 -> V_39 ) {
V_8 = V_43 -> V_39 ( V_45 , V_1 ) ;
V_44 = 1 ;
if ( V_8 <= 0 )
goto V_17;
}
if ( V_48 == NULL ) {
V_48 = F_35 () ;
if ( ! V_48 ) {
F_19 ( V_49 , V_50 ) ;
goto V_17;
}
}
if ( ! F_36 ( V_48 , V_45 ) ) {
F_19 ( V_49 , V_50 ) ;
goto V_17;
}
V_43 -> V_51 ++ ;
return V_8 ;
V_17:
if ( V_43 -> V_40 && V_44 )
V_43 -> V_40 ( V_45 ) ;
V_47:
if ( V_45 ) {
F_15 ( V_45 -> V_11 ) ;
F_15 ( V_45 -> V_12 ) ;
F_15 ( V_45 ) ;
}
return - 1 ;
}
void F_37 ( int V_52 )
{
int V_9 ;
T_2 * V_20 ;
F_38 () ;
for ( V_9 = F_32 ( V_38 ) - 1 ; V_9 >= 0 ; V_9 -- ) {
V_20 = F_33 ( V_38 , V_9 ) ;
if ( ( ( V_20 -> V_51 > 0 ) || ! V_20 -> V_27 ) && ! V_52 )
continue;
( void ) F_39 ( V_38 , V_9 ) ;
F_40 ( V_20 ) ;
}
if ( F_32 ( V_38 ) == 0 ) {
F_41 ( V_38 ) ;
V_38 = NULL ;
}
}
static void F_40 ( T_2 * V_20 )
{
F_27 ( V_20 -> V_27 ) ;
F_15 ( V_20 -> V_11 ) ;
F_15 ( V_20 ) ;
}
void F_38 ( void )
{
T_6 * V_45 ;
while ( F_42 ( V_48 ) > 0 ) {
V_45 = F_43 ( V_48 ) ;
F_44 ( V_45 ) ;
}
F_45 ( V_48 ) ;
V_48 = NULL ;
}
static void F_44 ( T_6 * V_45 )
{
if ( ! V_45 )
return;
if ( V_45 -> V_43 -> V_40 )
V_45 -> V_43 -> V_40 ( V_45 ) ;
V_45 -> V_43 -> V_51 -- ;
F_15 ( V_45 -> V_11 ) ;
F_15 ( V_45 -> V_12 ) ;
F_15 ( V_45 ) ;
}
int F_46 ( const char * V_11 , T_4 * V_28 ,
T_5 * V_29 )
{
if ( F_26 ( NULL , V_11 , V_28 , V_29 ) )
return 1 ;
else
return 0 ;
}
void F_47 ( void )
{
F_38 () ;
F_37 ( 1 ) ;
}
const char * F_48 ( const T_6 * V_20 )
{
return V_20 -> V_11 ;
}
const char * F_49 ( const T_6 * V_20 )
{
return V_20 -> V_12 ;
}
void * F_50 ( const T_6 * V_20 )
{
return V_20 -> V_46 ;
}
void F_51 ( T_6 * V_20 , void * V_46 )
{
V_20 -> V_46 = V_46 ;
}
T_2 * F_52 ( const T_6 * V_20 )
{
return V_20 -> V_43 ;
}
unsigned long F_53 ( const T_6 * V_20 )
{
return V_20 -> V_3 ;
}
void F_54 ( T_6 * V_20 , unsigned long V_3 )
{
V_20 -> V_3 = V_3 ;
}
void * F_55 ( T_2 * V_43 )
{
return V_43 -> V_46 ;
}
void F_56 ( T_2 * V_43 , void * V_46 )
{
V_43 -> V_46 = V_46 ;
}
char * F_11 ( void )
{
char * V_15 ;
int V_53 ;
V_15 = getenv ( L_8 ) ;
if ( V_15 )
return F_30 ( V_15 ) ;
V_53 = strlen ( F_57 () ) ;
#ifndef F_58
V_53 ++ ;
#endif
V_53 += strlen ( V_54 ) ;
V_15 = F_34 ( V_53 + 1 ) ;
if ( V_15 == NULL )
return NULL ;
F_59 ( V_15 , F_57 () , V_53 + 1 ) ;
#ifndef F_58
F_60 ( V_15 , L_9 , V_53 + 1 ) ;
#endif
F_60 ( V_15 , V_54 , V_53 + 1 ) ;
return V_15 ;
}
int F_61 ( const char * V_55 , int V_56 , int V_57 ,
int (* F_62) ( const char * V_58 , int V_53 , void * V_59 ) ,
void * V_60 )
{
int V_8 ;
const char * V_61 , * V_62 , * V_42 ;
if ( V_55 == NULL ) {
F_19 ( V_63 , V_64 ) ;
return 0 ;
}
V_61 = V_55 ;
for (; ; ) {
if ( V_57 ) {
while ( * V_61 && isspace ( ( unsigned char ) * V_61 ) )
V_61 ++ ;
}
V_42 = strchr ( V_61 , V_56 ) ;
if ( V_42 == V_61 || ! * V_61 )
V_8 = F_62 ( NULL , 0 , V_60 ) ;
else {
if ( V_42 )
V_62 = V_42 - 1 ;
else
V_62 = V_61 + strlen ( V_61 ) - 1 ;
if ( V_57 ) {
while ( isspace ( ( unsigned char ) * V_62 ) )
V_62 -- ;
}
V_8 = F_62 ( V_61 , V_62 - V_61 + 1 , V_60 ) ;
}
if ( V_8 <= 0 )
return V_8 ;
if ( V_42 == NULL )
return 1 ;
V_61 = V_42 + 1 ;
}
}

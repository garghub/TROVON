static T_1 * F_1 ()
{
T_1 * V_1 = F_2 ( sizeof( * V_1 ) ) ;
if ( V_1 == NULL )
F_3 ( V_2 , V_3 ) ;
return V_1 ;
}
static void F_4 ( T_1 * V_1 )
{
F_5 ( V_1 ) ;
}
static int F_6 ( T_2 * V_4 ,
unsigned char V_5 [ V_6 ] )
{
int V_7 = 0 ;
unsigned char * V_8 = NULL ;
int V_9 = F_7 ( V_4 , & V_8 ) ;
if ( V_9 <= 0 ) {
F_3 ( V_10 , V_11 ) ;
goto V_12;
}
F_8 ( V_8 , V_9 , V_5 ) ;
V_7 = 1 ;
V_12:
F_5 ( V_8 ) ;
return V_7 ;
}
T_3 * F_9 ( void )
{
T_3 * V_7 = F_2 ( sizeof( * V_7 ) ) ;
if ( V_7 == NULL ) {
F_3 ( V_13 , V_3 ) ;
return NULL ;
}
V_7 -> V_14 = F_10 () ;
if ( V_7 -> V_14 == NULL )
goto V_12;
return V_7 ;
V_12:
F_5 ( V_7 ) ;
return NULL ;
}
void F_11 ( T_3 * V_15 )
{
if ( V_15 != NULL ) {
F_12 ( V_15 -> V_14 , V_16 ) ;
F_5 ( V_15 ) ;
}
}
static int F_13 ( T_4 * * V_17 , const T_5 * V_18 , const char * V_19 )
{
const char * V_20 = F_14 ( V_18 , V_19 , L_1 ) ;
char * V_21 ;
if ( V_20 == NULL ) {
F_3 ( V_22 , V_23 ) ;
return 0 ;
}
V_21 = F_14 ( V_18 , V_19 , L_2 ) ;
if ( V_21 == NULL ) {
F_3 ( V_22 , V_24 ) ;
return 0 ;
}
return F_15 ( V_17 , V_21 , V_20 ) ;
}
int F_16 ( T_3 * V_15 )
{
const char * V_25 = getenv ( V_26 ) ;
if ( V_25 == NULL )
V_25 = V_27 ;
return F_17 ( V_15 , V_25 ) ;
}
static int F_18 ( const char * V_28 , int V_29 ,
void * V_30 )
{
T_1 * V_31 = V_30 ;
T_4 * V_17 = NULL ;
char * V_32 ;
int V_7 = 0 ;
if ( V_28 == NULL )
return 1 ;
V_32 = F_19 ( V_28 , V_29 ) ;
if ( V_32 == NULL )
goto V_33;
V_7 = F_13 ( & V_17 , V_31 -> V_18 , V_32 ) ;
F_5 ( V_32 ) ;
if ( V_7 < 0 ) {
return V_7 ;
}
if ( V_7 == 0 ) {
++ V_31 -> V_34 ;
return 1 ;
}
if ( ! F_20 ( V_31 -> V_35 -> V_14 , V_17 ) ) {
goto V_33;
}
return 1 ;
V_33:
V_16 ( V_17 ) ;
F_3 ( V_36 , V_3 ) ;
return - 1 ;
}
int F_17 ( T_3 * V_15 , const char * V_37 )
{
int V_7 = 0 ;
char * V_38 ;
T_1 * V_31 = F_1 () ;
V_31 -> V_35 = V_15 ;
V_31 -> V_18 = F_21 ( NULL ) ;
if ( V_31 -> V_18 == NULL )
goto V_39;
if ( F_22 ( V_31 -> V_18 , V_37 , NULL ) <= 0 ) {
F_3 ( V_40 , V_41 ) ;
goto V_39;
}
V_38 = F_14 ( V_31 -> V_18 , NULL , L_3 ) ;
if ( V_38 == NULL ) {
F_3 ( V_40 , V_41 ) ;
goto V_39;
}
if ( ! F_23 ( V_38 , ',' , 1 , F_18 , V_31 ) ||
V_31 -> V_34 > 0 ) {
F_3 ( V_40 , V_41 ) ;
goto V_39;
}
V_7 = 1 ;
V_39:
F_24 ( V_31 -> V_18 ) ;
F_4 ( V_31 ) ;
return V_7 ;
}
T_4 * F_25 ( T_2 * V_42 , const char * V_43 )
{
T_4 * V_7 = F_2 ( sizeof( * V_7 ) ) ;
if ( V_7 == NULL ) {
F_3 ( V_44 , V_3 ) ;
return NULL ;
}
V_7 -> V_43 = F_26 ( V_43 ) ;
if ( V_7 -> V_43 == NULL ) {
F_3 ( V_44 , V_3 ) ;
goto V_12;
}
if ( F_6 ( V_42 , V_7 -> V_5 ) != 1 )
goto V_12;
V_7 -> V_42 = V_42 ;
return V_7 ;
V_12:
V_16 ( V_7 ) ;
return NULL ;
}
void V_16 ( T_4 * log )
{
if ( log != NULL ) {
F_5 ( log -> V_43 ) ;
F_27 ( log -> V_42 ) ;
F_5 ( log ) ;
}
}
const char * F_28 ( const T_4 * log )
{
return log -> V_43 ;
}
void F_29 ( const T_4 * log , const T_6 * * V_5 ,
T_7 * V_45 )
{
* V_5 = log -> V_5 ;
* V_45 = V_6 ;
}
T_2 * F_30 ( const T_4 * log )
{
return log -> V_42 ;
}
const T_4 * F_31 ( const T_3 * V_15 ,
const T_6 * V_5 ,
T_7 V_45 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < F_32 ( V_15 -> V_14 ) ; ++ V_46 ) {
const T_4 * log = F_33 ( V_15 -> V_14 , V_46 ) ;
if ( memcmp ( log -> V_5 , V_5 , V_45 ) == 0 )
return log ;
}
return NULL ;
}

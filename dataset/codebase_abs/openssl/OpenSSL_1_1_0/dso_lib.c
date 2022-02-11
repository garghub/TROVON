static T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 ;
if ( V_3 == NULL ) {
V_3 = F_2 () ;
}
V_2 = F_3 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL ) {
F_4 ( V_4 , V_5 ) ;
return ( NULL ) ;
}
V_2 -> V_6 = F_5 () ;
if ( V_2 -> V_6 == NULL ) {
F_4 ( V_4 , V_5 ) ;
F_6 ( V_2 ) ;
return ( NULL ) ;
}
V_2 -> V_1 = V_3 ;
V_2 -> V_7 = 1 ;
V_2 -> V_8 = F_7 () ;
if ( V_2 -> V_8 == NULL ) {
F_4 ( V_4 , V_5 ) ;
F_8 ( V_2 -> V_6 ) ;
F_6 ( V_2 ) ;
return NULL ;
}
if ( ( V_2 -> V_1 -> V_9 != NULL ) && ! V_2 -> V_1 -> V_9 ( V_2 ) ) {
F_9 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
T_1 * F_10 ( void )
{
return F_1 ( NULL ) ;
}
int F_9 ( T_1 * V_10 )
{
int V_11 ;
if ( V_10 == NULL )
return ( 1 ) ;
if ( F_11 ( & V_10 -> V_7 , - 1 , & V_11 , V_10 -> V_8 ) <= 0 )
return 0 ;
F_12 ( L_1 , V_10 ) ;
if ( V_11 > 0 )
return 1 ;
F_13 ( V_11 < 0 ) ;
if ( ( V_10 -> V_1 -> V_12 != NULL ) && ! V_10 -> V_1 -> V_12 ( V_10 ) ) {
F_4 ( V_13 , V_14 ) ;
return 0 ;
}
if ( ( V_10 -> V_1 -> V_15 != NULL ) && ! V_10 -> V_1 -> V_15 ( V_10 ) ) {
F_4 ( V_13 , V_16 ) ;
return 0 ;
}
F_8 ( V_10 -> V_6 ) ;
F_6 ( V_10 -> V_17 ) ;
F_6 ( V_10 -> V_18 ) ;
F_14 ( V_10 -> V_8 ) ;
F_6 ( V_10 ) ;
return 1 ;
}
int F_15 ( T_1 * V_10 )
{
return ( ( V_10 == NULL ) ? 0 : V_10 -> V_19 ) ;
}
int F_16 ( T_1 * V_10 )
{
int V_11 ;
if ( V_10 == NULL ) {
F_4 ( V_20 , V_21 ) ;
return 0 ;
}
if ( F_11 ( & V_10 -> V_7 , 1 , & V_11 , V_10 -> V_8 ) <= 0 )
return 0 ;
F_12 ( L_1 , V_22 ) ;
F_13 ( V_11 < 2 ) ;
return ( ( V_11 > 1 ) ? 1 : 0 ) ;
}
T_1 * F_17 ( T_1 * V_10 , const char * V_17 , T_2 * V_1 , int V_19 )
{
T_1 * V_2 ;
int V_23 = 0 ;
if ( V_10 == NULL ) {
V_2 = F_1 ( V_1 ) ;
if ( V_2 == NULL ) {
F_4 ( V_24 , V_5 ) ;
goto V_25;
}
V_23 = 1 ;
if ( F_18 ( V_2 , V_26 , V_19 , NULL ) < 0 ) {
F_4 ( V_24 , V_27 ) ;
goto V_25;
}
} else
V_2 = V_10 ;
if ( V_2 -> V_17 != NULL ) {
F_4 ( V_24 , V_28 ) ;
goto V_25;
}
if ( V_17 != NULL )
if ( ! F_19 ( V_2 , V_17 ) ) {
F_4 ( V_24 , V_29 ) ;
goto V_25;
}
V_17 = V_2 -> V_17 ;
if ( V_17 == NULL ) {
F_4 ( V_24 , V_30 ) ;
goto V_25;
}
if ( V_2 -> V_1 -> V_31 == NULL ) {
F_4 ( V_24 , V_32 ) ;
goto V_25;
}
if ( ! V_2 -> V_1 -> V_31 ( V_2 ) ) {
F_4 ( V_24 , V_33 ) ;
goto V_25;
}
return ( V_2 ) ;
V_25:
if ( V_23 )
F_9 ( V_2 ) ;
return ( NULL ) ;
}
T_3 F_20 ( T_1 * V_10 , const char * V_34 )
{
T_3 V_2 = NULL ;
if ( ( V_10 == NULL ) || ( V_34 == NULL ) ) {
F_4 ( V_35 , V_21 ) ;
return ( NULL ) ;
}
if ( V_10 -> V_1 -> V_36 == NULL ) {
F_4 ( V_35 , V_32 ) ;
return ( NULL ) ;
}
if ( ( V_2 = V_10 -> V_1 -> V_36 ( V_10 , V_34 ) ) == NULL ) {
F_4 ( V_35 , V_37 ) ;
return ( NULL ) ;
}
return ( V_2 ) ;
}
long F_18 ( T_1 * V_10 , int V_38 , long V_39 , void * V_40 )
{
if ( V_10 == NULL ) {
F_4 ( V_41 , V_21 ) ;
return ( - 1 ) ;
}
switch ( V_38 ) {
case V_42 :
return V_10 -> V_19 ;
case V_26 :
V_10 -> V_19 = ( int ) V_39 ;
return ( 0 ) ;
case V_43 :
V_10 -> V_19 |= ( int ) V_39 ;
return ( 0 ) ;
default:
break;
}
if ( ( V_10 -> V_1 == NULL ) || ( V_10 -> V_1 -> V_44 == NULL ) ) {
F_4 ( V_41 , V_32 ) ;
return ( - 1 ) ;
}
return ( V_10 -> V_1 -> V_44 ( V_10 , V_38 , V_39 , V_40 ) ) ;
}
const char * F_21 ( T_1 * V_10 )
{
if ( V_10 == NULL ) {
F_4 ( V_45 , V_21 ) ;
return ( NULL ) ;
}
return ( V_10 -> V_17 ) ;
}
int F_19 ( T_1 * V_10 , const char * V_17 )
{
char * V_46 ;
if ( ( V_10 == NULL ) || ( V_17 == NULL ) ) {
F_4 ( V_47 , V_21 ) ;
return ( 0 ) ;
}
if ( V_10 -> V_18 ) {
F_4 ( V_47 , V_28 ) ;
return ( 0 ) ;
}
V_46 = F_22 ( V_17 ) ;
if ( V_46 == NULL ) {
F_4 ( V_47 , V_5 ) ;
return ( 0 ) ;
}
F_6 ( V_10 -> V_17 ) ;
V_10 -> V_17 = V_46 ;
return ( 1 ) ;
}
char * F_23 ( T_1 * V_10 , const char * V_48 , const char * V_49 )
{
char * V_50 = NULL ;
if ( V_10 == NULL || V_48 == NULL ) {
F_4 ( V_51 , V_21 ) ;
return ( NULL ) ;
}
if ( ( V_10 -> V_19 & V_52 ) == 0 ) {
if ( V_10 -> V_53 != NULL )
V_50 = V_10 -> V_53 ( V_10 , V_48 , V_49 ) ;
else if ( V_10 -> V_1 -> V_54 != NULL )
V_50 = V_10 -> V_1 -> V_54 ( V_10 , V_48 , V_49 ) ;
}
return ( V_50 ) ;
}
char * F_24 ( T_1 * V_10 , const char * V_17 )
{
char * V_50 = NULL ;
if ( V_10 == NULL ) {
F_4 ( V_55 , V_21 ) ;
return ( NULL ) ;
}
if ( V_17 == NULL )
V_17 = V_10 -> V_17 ;
if ( V_17 == NULL ) {
F_4 ( V_55 , V_30 ) ;
return ( NULL ) ;
}
if ( ( V_10 -> V_19 & V_52 ) == 0 ) {
if ( V_10 -> V_56 != NULL )
V_50 = V_10 -> V_56 ( V_10 , V_17 ) ;
else if ( V_10 -> V_1 -> V_57 != NULL )
V_50 = V_10 -> V_1 -> V_57 ( V_10 , V_17 ) ;
}
if ( V_50 == NULL ) {
V_50 = F_22 ( V_17 ) ;
if ( V_50 == NULL ) {
F_4 ( V_55 , V_5 ) ;
return ( NULL ) ;
}
}
return ( V_50 ) ;
}
void * F_25 ( const char * V_58 )
{
T_2 * V_1 = V_3 ;
if ( V_1 == NULL )
V_1 = F_2 () ;
if ( V_1 -> V_59 == NULL ) {
F_4 ( V_60 , V_32 ) ;
return NULL ;
}
return (* V_1 -> V_59 ) ( V_58 ) ;
}

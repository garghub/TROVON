static T_1 *
F_1 ( T_1 * V_1 )
{
T_1 * V_2 , * V_3 ;
V_2 = V_1 -> V_2 ;
if ( V_2 == NULL ) {
return NULL ;
}
V_3 = V_2 -> V_2 ;
if ( V_3 == NULL ) {
return NULL ;
}
if ( V_2 == V_3 -> V_4 ) {
return V_3 -> V_5 ;
}
else {
return V_3 -> V_4 ;
}
}
static void
F_2 ( T_2 * V_6 , T_1 * V_1 )
{
if ( V_1 -> V_2 ) {
if ( V_1 -> V_2 -> V_4 == V_1 ) {
V_1 -> V_2 -> V_4 = V_1 -> V_5 ;
}
else {
V_1 -> V_2 -> V_5 = V_1 -> V_5 ;
}
}
else {
V_6 -> V_7 = V_1 -> V_5 ;
}
V_1 -> V_5 -> V_2 = V_1 -> V_2 ;
V_1 -> V_2 = V_1 -> V_5 ;
V_1 -> V_5 = V_1 -> V_5 -> V_4 ;
if ( V_1 -> V_5 ) {
V_1 -> V_5 -> V_2 = V_1 ;
}
V_1 -> V_2 -> V_4 = V_1 ;
if ( V_6 -> V_8 ) {
V_6 -> V_8 ( V_1 ) ;
}
}
static void
F_3 ( T_2 * V_6 , T_1 * V_1 )
{
if ( V_1 -> V_2 ) {
if ( V_1 -> V_2 -> V_4 == V_1 ) {
V_1 -> V_2 -> V_4 = V_1 -> V_4 ;
}
else {
V_1 -> V_2 -> V_5 = V_1 -> V_4 ;
}
}
else {
V_6 -> V_7 = V_1 -> V_4 ;
}
V_1 -> V_4 -> V_2 = V_1 -> V_2 ;
V_1 -> V_2 = V_1 -> V_4 ;
V_1 -> V_4 = V_1 -> V_4 -> V_5 ;
if ( V_1 -> V_4 ) {
V_1 -> V_4 -> V_2 = V_1 ;
}
V_1 -> V_2 -> V_5 = V_1 ;
if ( V_6 -> V_8 ) {
V_6 -> V_8 ( V_1 ) ;
}
}
static void
F_4 ( T_2 * V_6 , T_1 * V_1 )
{
T_1 * V_2 , * V_3 ;
V_2 = V_1 -> V_2 ;
V_3 = V_2 -> V_2 ;
V_2 -> V_9 = V_10 ;
V_3 -> V_9 = V_11 ;
if ( V_1 == V_2 -> V_4 && V_2 == V_3 -> V_4 ) {
F_3 ( V_6 , V_3 ) ;
}
else {
F_2 ( V_6 , V_3 ) ;
}
}
static void
F_5 ( T_2 * V_6 , T_1 * V_1 )
{
T_1 * V_2 , * V_3 ;
V_2 = V_1 -> V_2 ;
V_3 = V_2 -> V_2 ;
if ( ! V_3 ) {
return;
}
if ( V_1 == V_2 -> V_5 && V_2 == V_3 -> V_4 ) {
F_2 ( V_6 , V_2 ) ;
V_1 = V_1 -> V_4 ;
}
else if ( V_1 == V_2 -> V_4 && V_2 == V_3 -> V_5 ) {
F_3 ( V_6 , V_2 ) ;
V_1 = V_1 -> V_5 ;
}
F_4 ( V_6 , V_1 ) ;
}
static void
F_6 ( T_2 * V_6 , T_1 * V_1 )
{
T_1 * V_2 , * V_3 , * V_12 ;
V_12 = F_1 ( V_1 ) ;
if ( V_12 && V_12 -> V_9 == V_11 ) {
V_2 = V_1 -> V_2 ;
V_3 = V_2 -> V_2 ;
V_2 -> V_9 = V_10 ;
V_12 -> V_9 = V_10 ;
V_3 -> V_9 = V_11 ;
F_7 ( V_6 , V_3 ) ;
}
else {
F_5 ( V_6 , V_1 ) ;
}
}
static void
F_8 ( T_2 * V_6 , T_1 * V_1 )
{
if ( V_1 -> V_2 -> V_9 == V_11 ) {
F_6 ( V_6 , V_1 ) ;
}
}
static void
F_7 ( T_2 * V_6 , T_1 * V_1 )
{
T_1 * V_2 = V_1 -> V_2 ;
if ( V_2 == NULL ) {
V_1 -> V_9 = V_10 ;
}
else {
F_8 ( V_6 , V_1 ) ;
}
}
T_2 *
F_9 ( T_3 * V_13 )
{
T_2 * V_6 ;
V_6 = F_10 ( V_13 , T_2 ) ;
V_6 -> V_14 = V_13 ;
V_6 -> V_13 = V_13 ;
return V_6 ;
}
static T_4
F_11 ( T_3 * V_13 V_15 , T_5 V_16 ,
void * V_17 )
{
T_2 * V_6 = ( T_2 * ) V_17 ;
V_6 -> V_7 = NULL ;
if ( V_16 == V_18 ) {
F_12 ( V_6 -> V_14 , V_6 -> V_19 ) ;
F_13 ( V_6 -> V_14 , V_6 ) ;
}
return TRUE ;
}
static T_4
F_14 ( T_3 * V_13 V_15 , T_5 V_16 V_15 ,
void * V_17 )
{
T_2 * V_6 = ( T_2 * ) V_17 ;
F_12 ( V_6 -> V_13 , V_6 -> V_20 ) ;
return FALSE ;
}
T_2 *
F_15 ( T_3 * V_14 , T_3 * V_21 )
{
T_2 * V_6 ;
V_6 = F_10 ( V_14 , T_2 ) ;
V_6 -> V_14 = V_14 ;
V_6 -> V_13 = V_21 ;
V_6 -> V_19 = F_16 ( V_14 , F_14 ,
V_6 ) ;
V_6 -> V_20 = F_16 ( V_21 , F_11 ,
V_6 ) ;
return V_6 ;
}
static void
F_17 ( T_3 * V_13 , T_1 * V_1 , T_4 V_22 , T_4 V_23 )
{
if ( V_1 == NULL ) {
return;
}
if ( V_1 -> V_4 ) {
F_17 ( V_13 , V_1 -> V_4 , V_22 , V_23 ) ;
}
if ( V_1 -> V_24 ) {
F_18 ( ( T_2 * ) V_1 -> V_25 , V_22 , V_23 ) ;
V_1 -> V_25 = NULL ;
}
if ( V_1 -> V_5 ) {
F_17 ( V_13 , V_1 -> V_5 , V_22 , V_23 ) ;
}
if ( V_22 ) {
F_13 ( V_13 , ( void * ) V_1 -> V_26 ) ;
}
if ( V_23 ) {
F_13 ( V_13 , V_1 -> V_25 ) ;
}
F_13 ( V_13 , V_1 ) ;
}
void
F_18 ( T_2 * V_6 , T_4 V_22 , T_4 V_23 )
{
F_17 ( V_6 -> V_13 , V_6 -> V_7 , V_22 , V_23 ) ;
F_12 ( V_6 -> V_14 , V_6 -> V_19 ) ;
F_12 ( V_6 -> V_13 , V_6 -> V_20 ) ;
F_13 ( V_6 -> V_14 , V_6 ) ;
}
T_4
F_19 ( T_2 * V_6 )
{
return V_6 -> V_7 == NULL ;
}
static T_4
F_20 ( const void * V_26 V_15 , void * T_6 V_15 , void * V_27 )
{
T_7 * V_28 = ( T_7 * ) V_27 ;
( * V_28 ) ++ ;
return FALSE ;
}
T_7
F_21 ( T_2 * V_6 )
{
T_7 V_28 = 0 ;
F_22 ( V_6 , F_20 , & V_28 ) ;
return V_28 ;
}
static T_1 *
F_23 ( T_3 * V_13 , T_1 * V_2 , const void * V_26 ,
void * V_25 , T_8 V_9 , T_4 V_24 )
{
T_1 * V_1 ;
V_1 = F_24 ( V_13 , T_1 ) ;
V_1 -> V_4 = NULL ;
V_1 -> V_5 = NULL ;
V_1 -> V_2 = V_2 ;
V_1 -> V_26 = V_26 ;
V_1 -> V_25 = V_25 ;
V_1 -> V_9 = V_9 ;
V_1 -> V_24 = V_24 ;
V_1 -> V_29 = FALSE ;
return V_1 ;
}
static T_1 *
F_25 ( T_2 * V_6 , T_9 V_26 ,
void * (* F_26)( void * ) , void * V_25 , T_4 V_24 , T_4 V_30 )
{
T_1 * V_1 = V_6 -> V_7 ;
T_1 * V_31 = NULL ;
if ( ! V_1 ) {
V_31 = F_23 ( V_6 -> V_13 , NULL , F_27 ( V_26 ) ,
F_28 ( F_26 , V_25 ) , V_10 , V_24 ) ;
V_6 -> V_7 = V_31 ;
return V_31 ;
}
while ( ! V_31 ) {
if ( V_26 == F_29 ( V_1 -> V_26 ) ) {
if ( V_30 ) {
V_1 -> V_25 = F_28 ( F_26 , V_25 ) ;
}
return V_1 ;
}
else if ( V_26 < F_29 ( V_1 -> V_26 ) ) {
if ( V_1 -> V_4 ) {
V_1 = V_1 -> V_4 ;
}
else {
V_31 = F_23 ( V_6 -> V_13 , V_1 , F_27 ( V_26 ) ,
F_28 ( F_26 , V_25 ) , V_11 ,
V_24 ) ;
V_1 -> V_4 = V_31 ;
}
}
else if ( V_26 > F_29 ( V_1 -> V_26 ) ) {
if ( V_1 -> V_5 ) {
V_1 = V_1 -> V_5 ;
}
else {
V_31 = F_23 ( V_6 -> V_13 , V_1 , F_27 ( V_26 ) ,
F_28 ( F_26 , V_25 ) , V_11 ,
V_24 ) ;
V_1 -> V_5 = V_31 ;
}
}
}
F_7 ( V_6 , V_31 ) ;
return V_31 ;
}
static void *
F_30 ( T_2 * V_6 , T_9 V_26 ,
void * (* F_26)( void * ) , void * V_25 , T_4 V_24 , T_4 V_30 )
{
T_1 * V_1 = F_25 ( V_6 , V_26 , F_26 , V_25 , V_24 , V_30 ) ;
return V_1 -> V_25 ;
}
static void *
F_31 ( T_2 * V_6 , const void * V_26 , T_10 V_32 )
{
T_1 * V_1 ;
if ( V_6 == NULL || V_26 == NULL ) {
return NULL ;
}
V_1 = V_6 -> V_7 ;
while ( V_1 ) {
int V_33 = V_32 ( V_26 , V_1 -> V_26 ) ;
if ( V_33 == 0 ) {
return V_1 -> V_25 ;
}
else if ( V_33 < 0 ) {
V_1 = V_1 -> V_4 ;
}
else if ( V_33 > 0 ) {
V_1 = V_1 -> V_5 ;
}
}
return NULL ;
}
T_1 *
F_32 ( T_2 * V_6 , const void * V_26 , void * V_25 , T_10 V_32 )
{
T_1 * V_1 = V_6 -> V_7 ;
T_1 * V_31 = NULL ;
if ( ! V_1 ) {
V_6 -> V_7 = F_23 ( V_6 -> V_13 , V_1 , V_26 ,
V_25 , V_10 , FALSE ) ;
return V_6 -> V_7 ;
}
while ( ! V_31 ) {
int V_33 = V_32 ( V_26 , V_1 -> V_26 ) ;
if ( V_33 == 0 ) {
V_1 -> V_25 = V_25 ;
V_1 -> V_29 = V_25 ? FALSE : TRUE ;
return V_1 ;
}
else if ( V_33 < 0 ) {
if ( V_1 -> V_4 ) {
V_1 = V_1 -> V_4 ;
}
else {
V_31 = F_23 ( V_6 -> V_13 , V_1 , V_26 ,
V_25 , V_11 , FALSE ) ;
V_1 -> V_4 = V_31 ;
}
}
else if ( V_33 > 0 ) {
if ( V_1 -> V_5 ) {
V_1 = V_1 -> V_5 ;
}
else {
V_31 = F_23 ( V_6 -> V_13 , V_1 , V_26 ,
V_25 , V_11 , FALSE ) ;
V_1 -> V_5 = V_31 ;
}
}
}
F_7 ( V_6 , V_31 ) ;
return V_31 ;
}
void
F_33 ( T_2 * V_6 , T_9 V_26 , void * V_25 )
{
F_30 ( V_6 , V_26 , NULL , V_25 , FALSE , TRUE ) ;
}
void *
F_34 ( T_2 * V_6 , T_9 V_26 )
{
T_1 * V_1 = V_6 -> V_7 ;
while ( V_1 ) {
if ( V_26 == F_29 ( V_1 -> V_26 ) ) {
return V_1 -> V_25 ;
}
else if ( V_26 < F_29 ( V_1 -> V_26 ) ) {
V_1 = V_1 -> V_4 ;
}
else if ( V_26 > F_29 ( V_1 -> V_26 ) ) {
V_1 = V_1 -> V_5 ;
}
}
return NULL ;
}
void *
F_35 ( T_2 * V_6 , T_9 V_26 )
{
T_1 * V_1 = V_6 -> V_7 ;
while ( V_1 ) {
if ( V_26 == F_29 ( V_1 -> V_26 ) ) {
return V_1 -> V_25 ;
}
else if ( V_26 < F_29 ( V_1 -> V_26 ) ) {
if ( V_1 -> V_4 == NULL ) {
break;
}
V_1 = V_1 -> V_4 ;
}
else if ( V_26 > F_29 ( V_1 -> V_26 ) ) {
if ( V_1 -> V_5 == NULL ) {
break;
}
V_1 = V_1 -> V_5 ;
}
}
if ( ! V_1 ) {
return NULL ;
}
if ( V_1 -> V_2 == NULL ) {
if ( V_26 > F_29 ( V_1 -> V_26 ) ) {
return V_1 -> V_25 ;
} else {
return NULL ;
}
}
if ( F_29 ( V_1 -> V_26 ) <= V_26 ) {
return V_1 -> V_25 ;
}
else if ( V_1 == V_1 -> V_2 -> V_4 ) {
while ( V_1 ) {
if ( V_26 > F_29 ( V_1 -> V_26 ) ) {
return V_1 -> V_25 ;
}
V_1 = V_1 -> V_2 ;
}
return NULL ;
}
else {
return V_1 -> V_2 -> V_25 ;
}
}
void *
F_36 ( T_2 * V_6 , T_9 V_26 )
{
void * V_34 = F_34 ( V_6 , V_26 ) ;
if ( V_34 ) {
F_33 ( V_6 , V_26 , NULL ) ;
}
return V_34 ;
}
void
F_37 ( T_2 * V_6 , const T_11 * V_35 , void * V_36 , T_9 V_37 )
{
char * V_26 ;
T_10 V_32 ;
V_26 = F_38 ( V_6 -> V_13 , V_35 ) ;
if ( V_37 & V_38 ) {
V_32 = ( T_10 ) V_39 ;
} else {
V_32 = ( T_10 ) strcmp ;
}
F_32 ( V_6 , V_26 , V_36 , V_32 ) ;
}
void *
F_39 ( T_2 * V_6 , const T_11 * V_35 , T_9 V_37 )
{
T_10 V_32 ;
if ( V_37 & V_38 ) {
V_32 = ( T_10 ) V_39 ;
} else {
V_32 = ( T_10 ) strcmp ;
}
return F_31 ( V_6 , V_35 , V_32 ) ;
}
void *
F_40 ( T_2 * V_6 , const T_11 * V_35 , T_9 V_37 )
{
void * V_34 = F_39 ( V_6 , V_35 , V_37 ) ;
if ( V_34 ) {
F_37 ( V_6 , V_35 , NULL , V_37 ) ;
}
return V_34 ;
}
static void *
F_41 ( void * V_40 )
{
return F_9 ( ( ( T_2 * ) V_40 ) -> V_13 ) ;
}
void
F_42 ( T_2 * V_6 , T_12 * V_26 , void * V_25 )
{
T_2 * V_41 = NULL ;
T_12 * V_42 ;
T_9 V_43 , V_44 = 0 ;
for ( V_42 = V_26 ; V_42 -> V_45 > 0 ; V_42 ++ ) {
for ( V_43 = 0 ; V_43 < V_42 -> V_45 ; V_43 ++ ) {
if ( ! V_41 ) {
V_41 = V_6 ;
} else {
V_41 = ( T_2 * ) F_30 ( V_41 ,
V_44 , F_41 , V_6 , TRUE , FALSE ) ;
}
V_44 = V_42 -> V_26 [ V_43 ] ;
}
}
F_43 ( V_41 ) ;
F_33 ( V_41 , V_44 , V_25 ) ;
}
static void *
F_44 ( T_2 * V_6 , T_12 * V_26 ,
void * (* F_45)( T_2 * , T_9 ) )
{
T_2 * V_46 = NULL ;
T_12 * V_42 ;
T_9 V_43 , V_47 = 0 ;
if ( ! V_6 || ! V_26 ) {
return NULL ;
}
for ( V_42 = V_26 ; V_42 -> V_45 > 0 ; V_42 ++ ) {
for ( V_43 = 0 ; V_43 < V_42 -> V_45 ; V_43 ++ ) {
if ( ! V_46 ) {
V_46 = V_6 ;
}
else {
V_46 =
( T_2 * ) (* F_45)( V_46 , V_47 ) ;
if ( ! V_46 ) {
return NULL ;
}
}
V_47 = V_42 -> V_26 [ V_43 ] ;
}
}
F_43 ( V_46 ) ;
return (* F_45)( V_46 , V_47 ) ;
}
void *
F_46 ( T_2 * V_6 , T_12 * V_26 )
{
return F_44 ( V_6 , V_26 , F_34 ) ;
}
void *
F_47 ( T_2 * V_6 , T_12 * V_26 )
{
return F_44 ( V_6 , V_26 , F_35 ) ;
}
static T_4
F_48 ( T_1 * V_1 , T_13 V_48 ,
void * V_17 )
{
T_4 V_49 = FALSE ;
if ( ! V_1 ) {
return FALSE ;
}
if ( V_1 -> V_4 ) {
if ( F_48 ( V_1 -> V_4 , V_48 , V_17 ) ) {
return TRUE ;
}
}
if ( V_1 -> V_24 ) {
V_49 = F_22 ( ( T_2 * ) V_1 -> V_25 ,
V_48 , V_17 ) ;
} else if ( ! V_1 -> V_29 ) {
V_49 = V_48 ( V_1 -> V_26 , V_1 -> V_25 , V_17 ) ;
}
if ( V_49 ) {
return TRUE ;
}
if( V_1 -> V_5 ) {
if ( F_48 ( V_1 -> V_5 , V_48 , V_17 ) ) {
return TRUE ;
}
}
return FALSE ;
}
T_4
F_22 ( T_2 * V_6 , T_13 V_48 ,
void * V_17 )
{
if( ! V_6 -> V_7 )
return FALSE ;
return F_48 ( V_6 -> V_7 , V_48 , V_17 ) ;
}
static void
F_49 ( T_9 V_50 ) {
T_9 V_43 ;
for ( V_43 = 0 ; V_43 < V_50 ; V_43 ++ ) {
F_50 ( L_1 ) ;
}
}
static void
F_51 ( const char * V_51 , T_1 * V_1 , T_9 V_50 ,
T_14 V_52 , T_14 V_53 )
{
if ( ! V_1 )
return;
F_49 ( V_50 ) ;
F_50 ( L_2 ,
V_51 ,
( void * ) V_1 , ( void * ) V_1 -> V_2 ,
( void * ) V_1 -> V_4 , ( void * ) V_1 -> V_5 ,
V_1 -> V_9 ? L_3 : L_4 , V_1 -> V_26 ,
V_1 -> V_24 ? L_5 : L_6 , V_1 -> V_25 ) ;
if ( V_52 ) {
F_49 ( V_50 ) ;
V_52 ( V_1 -> V_26 ) ;
F_50 ( L_7 ) ;
}
if ( V_53 && ! V_1 -> V_24 ) {
F_49 ( V_50 ) ;
V_53 ( V_1 -> V_25 ) ;
F_50 ( L_7 ) ;
}
if ( V_1 -> V_4 )
F_51 ( L_8 , V_1 -> V_4 , V_50 + 1 , V_52 , V_53 ) ;
if ( V_1 -> V_5 )
F_51 ( L_9 , V_1 -> V_5 , V_50 + 1 , V_52 , V_53 ) ;
if ( V_1 -> V_24 )
F_52 ( ( T_2 * ) V_1 -> V_25 , V_50 + 1 , V_52 , V_53 ) ;
}
static void
F_52 ( T_2 * V_6 , T_9 V_50 , T_14 V_52 , T_14 V_53 )
{
if ( ! V_6 )
return;
F_49 ( V_50 ) ;
F_50 ( L_10 , ( void * ) V_6 , ( void * ) V_6 -> V_7 ) ;
if ( V_6 -> V_7 ) {
F_51 ( L_11 , V_6 -> V_7 , V_50 , V_52 , V_53 ) ;
}
}
void
F_53 ( T_2 * V_6 , T_14 V_52 , T_14 V_53 )
{
F_52 ( V_6 , 0 , V_52 , V_53 ) ;
}

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
}
static void
F_4 ( T_2 * V_6 , T_1 * V_1 )
{
T_1 * V_2 , * V_3 ;
V_2 = V_1 -> V_2 ;
V_3 = V_2 -> V_2 ;
V_2 -> V_8 = V_9 ;
V_3 -> V_8 = V_10 ;
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
T_1 * V_2 , * V_3 , * V_11 ;
V_11 = F_1 ( V_1 ) ;
if ( V_11 && V_11 -> V_8 == V_10 ) {
V_2 = V_1 -> V_2 ;
V_3 = V_2 -> V_2 ;
V_2 -> V_8 = V_9 ;
V_11 -> V_8 = V_9 ;
V_3 -> V_8 = V_10 ;
F_7 ( V_6 , V_3 ) ;
}
else {
F_5 ( V_6 , V_1 ) ;
}
}
static void
F_8 ( T_2 * V_6 , T_1 * V_1 )
{
if ( V_1 -> V_2 -> V_8 == V_10 ) {
F_6 ( V_6 , V_1 ) ;
}
}
static void
F_7 ( T_2 * V_6 , T_1 * V_1 )
{
T_1 * V_2 = V_1 -> V_2 ;
if ( V_2 == NULL ) {
V_1 -> V_8 = V_9 ;
}
else {
F_8 ( V_6 , V_1 ) ;
}
}
T_2 *
F_9 ( T_3 * V_12 )
{
T_2 * V_6 ;
V_6 = F_10 ( V_12 , T_2 ) ;
V_6 -> V_13 = V_12 ;
V_6 -> V_12 = V_12 ;
V_6 -> V_7 = NULL ;
return V_6 ;
}
static T_4
F_11 ( T_3 * V_12 V_14 , T_5 V_15 ,
void * V_16 )
{
T_2 * V_6 = ( T_2 * ) V_16 ;
V_6 -> V_7 = NULL ;
if ( V_15 == V_17 ) {
F_12 ( V_6 -> V_13 , V_6 -> V_18 ) ;
F_13 ( V_6 -> V_13 , V_6 ) ;
}
return TRUE ;
}
static T_4
F_14 ( T_3 * V_12 V_14 , T_5 V_15 V_14 ,
void * V_16 )
{
T_2 * V_6 = ( T_2 * ) V_16 ;
F_12 ( V_6 -> V_12 , V_6 -> V_19 ) ;
return FALSE ;
}
T_2 *
F_15 ( T_3 * V_13 , T_3 * V_20 )
{
T_2 * V_6 ;
V_6 = F_10 ( V_13 , T_2 ) ;
V_6 -> V_13 = V_13 ;
V_6 -> V_12 = V_20 ;
V_6 -> V_7 = NULL ;
V_6 -> V_18 = F_16 ( V_13 , F_14 ,
V_6 ) ;
V_6 -> V_19 = F_16 ( V_20 , F_11 ,
V_6 ) ;
return V_6 ;
}
T_4
F_17 ( T_2 * V_6 )
{
return V_6 -> V_7 == NULL ;
}
static T_1 *
F_18 ( T_3 * V_12 , T_1 * V_2 , const void * V_21 ,
void * V_22 , T_6 V_8 , T_4 V_23 )
{
T_1 * V_1 ;
V_1 = F_10 ( V_12 , T_1 ) ;
V_1 -> V_4 = NULL ;
V_1 -> V_5 = NULL ;
V_1 -> V_2 = V_2 ;
V_1 -> V_21 = V_21 ;
V_1 -> V_22 = V_22 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_23 = V_23 ;
V_1 -> V_24 = FALSE ;
return V_1 ;
}
static void *
F_19 ( T_2 * V_6 , T_7 V_21 ,
void * (* F_20)( void * ) , void * V_22 , T_4 V_23 , T_4 V_25 )
{
T_1 * V_1 = V_6 -> V_7 ;
T_1 * V_26 = NULL ;
if ( ! V_1 ) {
V_26 = F_18 ( V_6 -> V_12 , NULL , F_21 ( V_21 ) ,
F_22 ( F_20 , V_22 ) , V_9 , V_23 ) ;
V_6 -> V_7 = V_26 ;
return V_26 -> V_22 ;
}
while ( ! V_26 ) {
if ( V_21 == F_23 ( V_1 -> V_21 ) ) {
if ( V_25 ) {
V_1 -> V_22 = F_22 ( F_20 , V_22 ) ;
}
return V_1 -> V_22 ;
}
else if ( V_21 < F_23 ( V_1 -> V_21 ) ) {
if ( V_1 -> V_4 ) {
V_1 = V_1 -> V_4 ;
}
else {
V_26 = F_18 ( V_6 -> V_12 , V_1 , F_21 ( V_21 ) ,
F_22 ( F_20 , V_22 ) , V_10 ,
V_23 ) ;
V_1 -> V_4 = V_26 ;
}
}
else if ( V_21 > F_23 ( V_1 -> V_21 ) ) {
if ( V_1 -> V_5 ) {
V_1 = V_1 -> V_5 ;
}
else {
V_26 = F_18 ( V_6 -> V_12 , V_1 , F_21 ( V_21 ) ,
F_22 ( F_20 , V_22 ) , V_10 ,
V_23 ) ;
V_1 -> V_5 = V_26 ;
}
}
}
F_7 ( V_6 , V_26 ) ;
return V_26 -> V_22 ;
}
static void *
F_24 ( T_2 * V_6 , const void * V_21 , T_8 V_27 )
{
T_1 * V_1 ;
if ( V_6 == NULL || V_21 == NULL ) {
return NULL ;
}
V_1 = V_6 -> V_7 ;
while ( V_1 ) {
int V_28 = V_27 ( V_21 , V_1 -> V_21 ) ;
if ( V_28 == 0 ) {
return V_1 -> V_22 ;
}
else if ( V_28 < 0 ) {
V_1 = V_1 -> V_4 ;
}
else if ( V_28 > 0 ) {
V_1 = V_1 -> V_5 ;
}
}
return NULL ;
}
static void
F_25 ( T_2 * V_6 , const void * V_21 , void * V_22 , T_8 V_27 )
{
T_1 * V_1 = V_6 -> V_7 ;
T_1 * V_26 = NULL ;
if ( ! V_1 ) {
V_6 -> V_7 = F_18 ( V_6 -> V_12 , V_1 , V_21 ,
V_22 , V_9 , FALSE ) ;
return;
}
while ( ! V_26 ) {
int V_28 = V_27 ( V_21 , V_1 -> V_21 ) ;
if ( V_28 == 0 ) {
V_1 -> V_22 = V_22 ;
V_1 -> V_24 = V_22 ? FALSE : TRUE ;
return;
}
else if ( V_28 < 0 ) {
if ( V_1 -> V_4 ) {
V_1 = V_1 -> V_4 ;
}
else {
V_26 = F_18 ( V_6 -> V_12 , V_1 , V_21 ,
V_22 , V_10 , FALSE ) ;
V_1 -> V_4 = V_26 ;
}
}
else if ( V_28 > 0 ) {
if ( V_1 -> V_5 ) {
V_1 = V_1 -> V_5 ;
}
else {
V_26 = F_18 ( V_6 -> V_12 , V_1 , V_21 ,
V_22 , V_10 , FALSE ) ;
V_1 -> V_5 = V_26 ;
}
}
}
F_7 ( V_6 , V_26 ) ;
}
void
F_26 ( T_2 * V_6 , T_7 V_21 , void * V_22 )
{
F_19 ( V_6 , V_21 , NULL , V_22 , FALSE , TRUE ) ;
}
void *
F_27 ( T_2 * V_6 , T_7 V_21 )
{
T_1 * V_1 = V_6 -> V_7 ;
while ( V_1 ) {
if ( V_21 == F_23 ( V_1 -> V_21 ) ) {
return V_1 -> V_22 ;
}
else if ( V_21 < F_23 ( V_1 -> V_21 ) ) {
V_1 = V_1 -> V_4 ;
}
else if ( V_21 > F_23 ( V_1 -> V_21 ) ) {
V_1 = V_1 -> V_5 ;
}
}
return NULL ;
}
void *
F_28 ( T_2 * V_6 , T_7 V_21 )
{
T_1 * V_1 = V_6 -> V_7 ;
while ( V_1 ) {
if ( V_21 == F_23 ( V_1 -> V_21 ) ) {
return V_1 -> V_22 ;
}
else if ( V_21 < F_23 ( V_1 -> V_21 ) ) {
if ( V_1 -> V_4 == NULL ) {
break;
}
V_1 = V_1 -> V_4 ;
}
else if ( V_21 > F_23 ( V_1 -> V_21 ) ) {
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
if ( V_21 > F_23 ( V_1 -> V_21 ) ) {
return V_1 -> V_22 ;
} else {
return NULL ;
}
}
if ( F_23 ( V_1 -> V_21 ) <= V_21 ) {
return V_1 -> V_22 ;
}
else if ( V_1 == V_1 -> V_2 -> V_4 ) {
while ( V_1 ) {
if ( V_21 > F_23 ( V_1 -> V_21 ) ) {
return V_1 -> V_22 ;
}
V_1 = V_1 -> V_2 ;
}
return NULL ;
}
else {
return V_1 -> V_2 -> V_22 ;
}
}
void
F_29 ( T_2 * V_6 , const T_9 * V_29 , void * V_30 , T_7 V_31 )
{
char * V_21 ;
T_8 V_27 ;
V_21 = F_30 ( V_6 -> V_12 , V_29 ) ;
if ( V_31 & V_32 ) {
V_27 = ( T_8 ) V_33 ;
} else {
V_27 = ( T_8 ) strcmp ;
}
F_25 ( V_6 , V_21 , V_30 , V_27 ) ;
}
void *
F_31 ( T_2 * V_6 , const T_9 * V_29 , T_7 V_31 )
{
T_8 V_27 ;
if ( V_31 & V_32 ) {
V_27 = ( T_8 ) V_33 ;
} else {
V_27 = ( T_8 ) strcmp ;
}
return F_24 ( V_6 , V_29 , V_27 ) ;
}
void *
F_32 ( T_2 * V_6 , const T_9 * V_29 , T_7 V_31 )
{
void * V_34 = F_31 ( V_6 , V_29 , V_31 ) ;
if ( V_34 ) {
F_29 ( V_6 , V_29 , NULL , V_31 ) ;
}
return V_34 ;
}
static void *
F_33 ( void * V_35 )
{
return F_9 ( ( ( T_2 * ) V_35 ) -> V_12 ) ;
}
void
F_34 ( T_2 * V_6 , T_10 * V_21 , void * V_22 )
{
T_2 * V_36 = NULL ;
T_10 * V_37 ;
T_7 V_38 , V_39 = 0 ;
for ( V_37 = V_21 ; V_37 -> V_40 > 0 ; V_37 ++ ) {
for ( V_38 = 0 ; V_38 < V_37 -> V_40 ; V_38 ++ ) {
if ( ! V_36 ) {
V_36 = V_6 ;
} else {
V_36 = ( T_2 * ) F_19 ( V_36 ,
V_39 , F_33 , V_6 , TRUE , FALSE ) ;
}
V_39 = V_37 -> V_21 [ V_38 ] ;
}
}
F_35 ( V_36 ) ;
F_26 ( V_36 , V_39 , V_22 ) ;
}
static void *
F_36 ( T_2 * V_6 , T_10 * V_21 ,
void * (* F_37)( T_2 * , T_7 ) )
{
T_2 * V_41 = NULL ;
T_10 * V_37 ;
T_7 V_38 , V_42 = 0 ;
if ( ! V_6 || ! V_21 ) {
return NULL ;
}
for ( V_37 = V_21 ; V_37 -> V_40 > 0 ; V_37 ++ ) {
for ( V_38 = 0 ; V_38 < V_37 -> V_40 ; V_38 ++ ) {
if ( ! V_41 ) {
V_41 = V_6 ;
}
else {
V_41 =
( T_2 * ) (* F_37)( V_41 , V_42 ) ;
if ( ! V_41 ) {
return NULL ;
}
}
V_42 = V_37 -> V_21 [ V_38 ] ;
}
}
F_35 ( V_41 ) ;
return (* F_37)( V_41 , V_42 ) ;
}
void *
F_38 ( T_2 * V_6 , T_10 * V_21 )
{
return F_36 ( V_6 , V_21 , F_27 ) ;
}
void *
F_39 ( T_2 * V_6 , T_10 * V_21 )
{
return F_36 ( V_6 , V_21 , F_28 ) ;
}
static T_4
F_40 ( T_1 * V_1 , T_11 V_43 ,
void * V_16 )
{
T_4 V_44 = FALSE ;
if ( ! V_1 ) {
return FALSE ;
}
if ( V_1 -> V_4 ) {
if ( F_40 ( V_1 -> V_4 , V_43 , V_16 ) ) {
return TRUE ;
}
}
if ( V_1 -> V_23 ) {
V_44 = F_41 ( ( T_2 * ) V_1 -> V_22 ,
V_43 , V_16 ) ;
} else if ( ! V_1 -> V_24 ) {
V_44 = V_43 ( V_1 -> V_21 , V_1 -> V_22 , V_16 ) ;
}
if ( V_44 ) {
return TRUE ;
}
if( V_1 -> V_5 ) {
if ( F_40 ( V_1 -> V_5 , V_43 , V_16 ) ) {
return TRUE ;
}
}
return FALSE ;
}
T_4
F_41 ( T_2 * V_6 , T_11 V_43 ,
void * V_16 )
{
if( ! V_6 -> V_7 )
return FALSE ;
return F_40 ( V_6 -> V_7 , V_43 , V_16 ) ;
}
static void
F_42 ( const char * V_45 , T_1 * V_1 , T_7 V_46 )
{
T_7 V_38 ;
if ( ! V_1 )
return;
for ( V_38 = 0 ; V_38 < V_46 ; V_38 ++ ) {
printf ( L_1 ) ;
}
printf ( L_2 ,
V_45 ,
( void * ) V_1 , ( void * ) V_1 -> V_2 ,
( void * ) V_1 -> V_4 , ( void * ) V_1 -> V_5 ,
V_1 -> V_8 ? L_3 : L_4 , F_23 ( V_1 -> V_21 ) ,
V_1 -> V_23 ? L_5 : L_6 , V_1 -> V_22 ) ;
if ( V_1 -> V_4 )
F_42 ( L_7 , V_1 -> V_4 , V_46 + 1 ) ;
if ( V_1 -> V_5 )
F_42 ( L_8 , V_1 -> V_5 , V_46 + 1 ) ;
if ( V_1 -> V_23 )
F_43 ( ( T_2 * ) V_1 -> V_22 , V_46 + 1 ) ;
}
static void
F_43 ( T_2 * V_6 , T_7 V_46 )
{
T_7 V_38 ;
if ( ! V_6 )
return;
for ( V_38 = 0 ; V_38 < V_46 ; V_38 ++ ) {
printf ( L_1 ) ;
}
printf ( L_9 , ( void * ) V_6 , ( void * ) V_6 -> V_7 ) ;
if ( V_6 -> V_7 ) {
F_42 ( L_10 , V_6 -> V_7 , V_46 ) ;
}
}
void
F_44 ( T_2 * V_6 )
{
F_43 ( V_6 , 0 ) ;
}

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
V_6 -> V_7 = NULL ;
V_6 -> V_8 = NULL ;
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
V_6 -> V_7 = NULL ;
V_6 -> V_8 = NULL ;
V_6 -> V_19 = F_16 ( V_14 , F_14 ,
V_6 ) ;
V_6 -> V_20 = F_16 ( V_21 , F_11 ,
V_6 ) ;
return V_6 ;
}
T_4
F_17 ( T_2 * V_6 )
{
return V_6 -> V_7 == NULL ;
}
static T_1 *
F_18 ( T_3 * V_13 , T_1 * V_2 , const void * V_22 ,
void * V_23 , T_6 V_9 , T_4 V_24 )
{
T_1 * V_1 ;
V_1 = F_10 ( V_13 , T_1 ) ;
V_1 -> V_4 = NULL ;
V_1 -> V_5 = NULL ;
V_1 -> V_2 = V_2 ;
V_1 -> V_22 = V_22 ;
V_1 -> V_23 = V_23 ;
V_1 -> V_9 = V_9 ;
V_1 -> V_24 = V_24 ;
V_1 -> V_25 = FALSE ;
return V_1 ;
}
static T_1 *
F_19 ( T_2 * V_6 , T_7 V_22 ,
void * (* F_20)( void * ) , void * V_23 , T_4 V_24 , T_4 V_26 )
{
T_1 * V_1 = V_6 -> V_7 ;
T_1 * V_27 = NULL ;
if ( ! V_1 ) {
V_27 = F_18 ( V_6 -> V_13 , NULL , F_21 ( V_22 ) ,
F_22 ( F_20 , V_23 ) , V_10 , V_24 ) ;
V_6 -> V_7 = V_27 ;
return V_27 ;
}
while ( ! V_27 ) {
if ( V_22 == F_23 ( V_1 -> V_22 ) ) {
if ( V_26 ) {
V_1 -> V_23 = F_22 ( F_20 , V_23 ) ;
}
return V_1 ;
}
else if ( V_22 < F_23 ( V_1 -> V_22 ) ) {
if ( V_1 -> V_4 ) {
V_1 = V_1 -> V_4 ;
}
else {
V_27 = F_18 ( V_6 -> V_13 , V_1 , F_21 ( V_22 ) ,
F_22 ( F_20 , V_23 ) , V_11 ,
V_24 ) ;
V_1 -> V_4 = V_27 ;
}
}
else if ( V_22 > F_23 ( V_1 -> V_22 ) ) {
if ( V_1 -> V_5 ) {
V_1 = V_1 -> V_5 ;
}
else {
V_27 = F_18 ( V_6 -> V_13 , V_1 , F_21 ( V_22 ) ,
F_22 ( F_20 , V_23 ) , V_11 ,
V_24 ) ;
V_1 -> V_5 = V_27 ;
}
}
}
F_7 ( V_6 , V_27 ) ;
return V_27 ;
}
static void *
F_24 ( T_2 * V_6 , T_7 V_22 ,
void * (* F_20)( void * ) , void * V_23 , T_4 V_24 , T_4 V_26 )
{
T_1 * V_1 = F_19 ( V_6 , V_22 , F_20 , V_23 , V_24 , V_26 ) ;
return V_1 -> V_23 ;
}
static void *
F_25 ( T_2 * V_6 , const void * V_22 , T_8 V_28 )
{
T_1 * V_1 ;
if ( V_6 == NULL || V_22 == NULL ) {
return NULL ;
}
V_1 = V_6 -> V_7 ;
while ( V_1 ) {
int V_29 = V_28 ( V_22 , V_1 -> V_22 ) ;
if ( V_29 == 0 ) {
return V_1 -> V_23 ;
}
else if ( V_29 < 0 ) {
V_1 = V_1 -> V_4 ;
}
else if ( V_29 > 0 ) {
V_1 = V_1 -> V_5 ;
}
}
return NULL ;
}
T_1 *
F_26 ( T_2 * V_6 , const void * V_22 , void * V_23 , T_8 V_28 )
{
T_1 * V_1 = V_6 -> V_7 ;
T_1 * V_27 = NULL ;
if ( ! V_1 ) {
V_6 -> V_7 = F_18 ( V_6 -> V_13 , V_1 , V_22 ,
V_23 , V_10 , FALSE ) ;
return V_6 -> V_7 ;
}
while ( ! V_27 ) {
int V_29 = V_28 ( V_22 , V_1 -> V_22 ) ;
if ( V_29 == 0 ) {
V_1 -> V_23 = V_23 ;
V_1 -> V_25 = V_23 ? FALSE : TRUE ;
return V_1 ;
}
else if ( V_29 < 0 ) {
if ( V_1 -> V_4 ) {
V_1 = V_1 -> V_4 ;
}
else {
V_27 = F_18 ( V_6 -> V_13 , V_1 , V_22 ,
V_23 , V_11 , FALSE ) ;
V_1 -> V_4 = V_27 ;
}
}
else if ( V_29 > 0 ) {
if ( V_1 -> V_5 ) {
V_1 = V_1 -> V_5 ;
}
else {
V_27 = F_18 ( V_6 -> V_13 , V_1 , V_22 ,
V_23 , V_11 , FALSE ) ;
V_1 -> V_5 = V_27 ;
}
}
}
F_7 ( V_6 , V_27 ) ;
return V_27 ;
}
void
F_27 ( T_2 * V_6 , T_7 V_22 , void * V_23 )
{
F_24 ( V_6 , V_22 , NULL , V_23 , FALSE , TRUE ) ;
}
void *
F_28 ( T_2 * V_6 , T_7 V_22 )
{
T_1 * V_1 = V_6 -> V_7 ;
while ( V_1 ) {
if ( V_22 == F_23 ( V_1 -> V_22 ) ) {
return V_1 -> V_23 ;
}
else if ( V_22 < F_23 ( V_1 -> V_22 ) ) {
V_1 = V_1 -> V_4 ;
}
else if ( V_22 > F_23 ( V_1 -> V_22 ) ) {
V_1 = V_1 -> V_5 ;
}
}
return NULL ;
}
void *
F_29 ( T_2 * V_6 , T_7 V_22 )
{
T_1 * V_1 = V_6 -> V_7 ;
while ( V_1 ) {
if ( V_22 == F_23 ( V_1 -> V_22 ) ) {
return V_1 -> V_23 ;
}
else if ( V_22 < F_23 ( V_1 -> V_22 ) ) {
if ( V_1 -> V_4 == NULL ) {
break;
}
V_1 = V_1 -> V_4 ;
}
else if ( V_22 > F_23 ( V_1 -> V_22 ) ) {
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
if ( V_22 > F_23 ( V_1 -> V_22 ) ) {
return V_1 -> V_23 ;
} else {
return NULL ;
}
}
if ( F_23 ( V_1 -> V_22 ) <= V_22 ) {
return V_1 -> V_23 ;
}
else if ( V_1 == V_1 -> V_2 -> V_4 ) {
while ( V_1 ) {
if ( V_22 > F_23 ( V_1 -> V_22 ) ) {
return V_1 -> V_23 ;
}
V_1 = V_1 -> V_2 ;
}
return NULL ;
}
else {
return V_1 -> V_2 -> V_23 ;
}
}
void
F_30 ( T_2 * V_6 , const T_9 * V_30 , void * V_31 , T_7 V_32 )
{
char * V_22 ;
T_8 V_28 ;
V_22 = F_31 ( V_6 -> V_13 , V_30 ) ;
if ( V_32 & V_33 ) {
V_28 = ( T_8 ) V_34 ;
} else {
V_28 = ( T_8 ) strcmp ;
}
F_26 ( V_6 , V_22 , V_31 , V_28 ) ;
}
void *
F_32 ( T_2 * V_6 , const T_9 * V_30 , T_7 V_32 )
{
T_8 V_28 ;
if ( V_32 & V_33 ) {
V_28 = ( T_8 ) V_34 ;
} else {
V_28 = ( T_8 ) strcmp ;
}
return F_25 ( V_6 , V_30 , V_28 ) ;
}
void *
F_33 ( T_2 * V_6 , const T_9 * V_30 , T_7 V_32 )
{
void * V_35 = F_32 ( V_6 , V_30 , V_32 ) ;
if ( V_35 ) {
F_30 ( V_6 , V_30 , NULL , V_32 ) ;
}
return V_35 ;
}
static void *
F_34 ( void * V_36 )
{
return F_9 ( ( ( T_2 * ) V_36 ) -> V_13 ) ;
}
void
F_35 ( T_2 * V_6 , T_10 * V_22 , void * V_23 )
{
T_2 * V_37 = NULL ;
T_10 * V_38 ;
T_7 V_39 , V_40 = 0 ;
for ( V_38 = V_22 ; V_38 -> V_41 > 0 ; V_38 ++ ) {
for ( V_39 = 0 ; V_39 < V_38 -> V_41 ; V_39 ++ ) {
if ( ! V_37 ) {
V_37 = V_6 ;
} else {
V_37 = ( T_2 * ) F_24 ( V_37 ,
V_40 , F_34 , V_6 , TRUE , FALSE ) ;
}
V_40 = V_38 -> V_22 [ V_39 ] ;
}
}
F_36 ( V_37 ) ;
F_27 ( V_37 , V_40 , V_23 ) ;
}
static void *
F_37 ( T_2 * V_6 , T_10 * V_22 ,
void * (* F_38)( T_2 * , T_7 ) )
{
T_2 * V_42 = NULL ;
T_10 * V_38 ;
T_7 V_39 , V_43 = 0 ;
if ( ! V_6 || ! V_22 ) {
return NULL ;
}
for ( V_38 = V_22 ; V_38 -> V_41 > 0 ; V_38 ++ ) {
for ( V_39 = 0 ; V_39 < V_38 -> V_41 ; V_39 ++ ) {
if ( ! V_42 ) {
V_42 = V_6 ;
}
else {
V_42 =
( T_2 * ) (* F_38)( V_42 , V_43 ) ;
if ( ! V_42 ) {
return NULL ;
}
}
V_43 = V_38 -> V_22 [ V_39 ] ;
}
}
F_36 ( V_42 ) ;
return (* F_38)( V_42 , V_43 ) ;
}
void *
F_39 ( T_2 * V_6 , T_10 * V_22 )
{
return F_37 ( V_6 , V_22 , F_28 ) ;
}
void *
F_40 ( T_2 * V_6 , T_10 * V_22 )
{
return F_37 ( V_6 , V_22 , F_29 ) ;
}
static T_4
F_41 ( T_1 * V_1 , T_11 V_44 ,
void * V_17 )
{
T_4 V_45 = FALSE ;
if ( ! V_1 ) {
return FALSE ;
}
if ( V_1 -> V_4 ) {
if ( F_41 ( V_1 -> V_4 , V_44 , V_17 ) ) {
return TRUE ;
}
}
if ( V_1 -> V_24 ) {
V_45 = F_42 ( ( T_2 * ) V_1 -> V_23 ,
V_44 , V_17 ) ;
} else if ( ! V_1 -> V_25 ) {
V_45 = V_44 ( V_1 -> V_22 , V_1 -> V_23 , V_17 ) ;
}
if ( V_45 ) {
return TRUE ;
}
if( V_1 -> V_5 ) {
if ( F_41 ( V_1 -> V_5 , V_44 , V_17 ) ) {
return TRUE ;
}
}
return FALSE ;
}
T_4
F_42 ( T_2 * V_6 , T_11 V_44 ,
void * V_17 )
{
if( ! V_6 -> V_7 )
return FALSE ;
return F_41 ( V_6 -> V_7 , V_44 , V_17 ) ;
}
static void
F_43 ( T_7 V_46 ) {
T_7 V_39 ;
for ( V_39 = 0 ; V_39 < V_46 ; V_39 ++ ) {
printf ( L_1 ) ;
}
}
static void
F_44 ( const char * V_47 , T_1 * V_1 , T_7 V_46 ,
T_12 V_48 , T_12 V_49 )
{
if ( ! V_1 )
return;
F_43 ( V_46 ) ;
printf ( L_2 ,
V_47 ,
( void * ) V_1 , ( void * ) V_1 -> V_2 ,
( void * ) V_1 -> V_4 , ( void * ) V_1 -> V_5 ,
V_1 -> V_9 ? L_3 : L_4 , V_1 -> V_22 ,
V_1 -> V_24 ? L_5 : L_6 , V_1 -> V_23 ) ;
if( V_48 ) {
F_43 ( V_46 ) ;
V_48 ( V_1 -> V_22 ) ;
printf ( L_7 ) ;
}
if( V_49 ) {
F_43 ( V_46 ) ;
V_49 ( V_1 -> V_23 ) ;
printf ( L_7 ) ;
}
if ( V_1 -> V_4 )
F_44 ( L_8 , V_1 -> V_4 , V_46 + 1 , V_48 , V_49 ) ;
if ( V_1 -> V_5 )
F_44 ( L_9 , V_1 -> V_5 , V_46 + 1 , V_48 , V_49 ) ;
if ( V_1 -> V_24 )
F_45 ( ( T_2 * ) V_1 -> V_23 , V_46 + 1 , V_48 , V_49 ) ;
}
static void
F_45 ( T_2 * V_6 , T_7 V_46 , T_12 V_48 , T_12 V_49 )
{
if ( ! V_6 )
return;
F_43 ( V_46 ) ;
printf ( L_10 , ( void * ) V_6 , ( void * ) V_6 -> V_7 ) ;
if ( V_6 -> V_7 ) {
F_44 ( L_11 , V_6 -> V_7 , V_46 , V_48 , V_49 ) ;
}
}
void
F_46 ( T_2 * V_6 , T_12 V_48 , T_12 V_49 )
{
F_45 ( V_6 , 0 , V_48 , V_49 ) ;
}

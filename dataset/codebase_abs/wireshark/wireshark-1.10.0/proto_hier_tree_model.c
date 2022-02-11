static T_1
F_1 ( T_2 * V_1 )
{
F_2 ( F_3 ( V_1 ) , ( T_1 ) 0 ) ;
return V_2 ;
}
static T_3
F_4 ( T_2 * V_1 )
{
F_2 ( F_3 ( V_1 ) , 0 ) ;
return 2 ;
}
static T_4
F_5 ( T_2 * V_1 , T_3 V_3 )
{
F_2 ( F_3 ( V_1 ) , V_4 ) ;
F_2 ( V_3 == 0 || V_3 == 1 , V_4 ) ;
switch ( V_3 ) {
case 0 :
return V_5 ;
case 1 :
return V_6 ;
}
return V_4 ;
}
static T_5
F_6 ( T_2 * V_1 , T_6 * V_7 , T_6 * V_8 , T_3 V_9 )
{
T_7 * V_10 ;
T_3 V_11 ;
void * V_12 ;
F_2 ( F_3 ( V_1 ) , FALSE ) ;
V_10 = ( T_7 * ) V_1 ;
if ( V_8 ) {
T_8 * V_13 ;
F_2 ( V_8 -> V_14 == V_10 -> V_14 , FALSE ) ;
if ( V_8 -> V_15 != NULL )
return FALSE ;
V_11 = F_7 ( V_8 -> V_16 ) ;
V_13 = F_8 ( V_11 , & V_12 ) ;
while ( V_13 ) {
if ( V_13 -> V_17 == NULL ) {
if ( ! V_9 )
break;
V_9 -- ;
}
V_13 = F_9 ( & V_12 ) ;
}
if ( ! V_13 )
return FALSE ;
V_7 -> V_14 = V_10 -> V_14 ;
V_7 -> V_16 = V_8 -> V_16 ;
V_7 -> V_15 = V_12 ;
V_7 -> V_18 = V_13 ;
return TRUE ;
}
V_11 = F_10 ( & V_12 ) ;
while ( V_11 != - 1 ) {
T_9 * V_19 = F_11 ( V_11 ) ;
if ( F_12 ( V_19 ) ) {
if ( ! V_9 )
break;
V_9 -- ;
}
V_11 = F_13 ( & V_12 ) ;
}
if ( V_11 == - 1 )
return FALSE ;
V_7 -> V_14 = V_10 -> V_14 ;
V_7 -> V_16 = V_12 ;
V_7 -> V_15 = NULL ;
V_7 -> V_18 = F_14 ( V_11 ) ;
return TRUE ;
}
static T_5
F_15 ( T_2 * V_1 , T_6 * V_7 , T_10 * V_20 )
{
T_3 * V_21 , V_22 ;
F_16 ( F_3 ( V_1 ) ) ;
F_16 ( V_20 != NULL ) ;
V_21 = F_17 ( V_20 ) ;
V_22 = F_18 ( V_20 ) ;
F_16 ( V_22 == 1 || V_22 == 2 ) ;
if ( ! F_6 ( V_1 , V_7 , NULL , V_21 [ 0 ] ) )
return FALSE ;
if ( V_22 == 2 ) {
if ( ! F_6 ( V_1 , V_7 , V_7 , V_21 [ 1 ] ) )
return FALSE ;
}
return TRUE ;
}
static char *
F_19 ( const T_8 * V_13 )
{
if ( V_13 -> V_8 == - 1 ) {
T_9 * V_23 = F_11 ( V_13 -> V_24 ) ;
return F_20 ( L_1 , F_21 ( V_23 ) , F_22 ( V_23 ) ) ;
}
if ( V_13 -> V_25 != NULL && V_13 -> V_25 [ 0 ] != '\0' )
return F_20 ( L_2 , V_13 -> V_26 , V_13 -> V_27 , V_13 -> V_25 ) ;
else
return F_20 ( L_1 , V_13 -> V_26 , V_13 -> V_27 ) ;
}
static void
F_23 ( T_2 * V_1 , T_6 * V_7 , T_3 V_28 , T_11 * V_29 )
{
T_7 * V_10 ;
T_8 * V_13 ;
F_24 ( F_3 ( V_1 ) ) ;
V_10 = ( T_7 * ) V_1 ;
F_24 ( V_7 != NULL ) ;
F_24 ( V_7 -> V_14 == V_10 -> V_14 ) ;
F_24 ( V_28 == 0 || V_28 == 1 ) ;
V_13 = ( T_8 * ) V_7 -> V_18 ;
switch ( V_28 ) {
case 0 :
F_25 ( V_29 , V_5 ) ;
F_26 ( V_29 , V_13 ) ;
break;
case 1 :
F_25 ( V_29 , V_6 ) ;
F_27 ( V_29 , F_19 ( V_13 ) ) ;
break;
}
}
static T_5
F_28 ( T_2 * V_1 , T_6 * V_7 )
{
T_7 * V_10 ;
F_2 ( F_3 ( V_1 ) , FALSE ) ;
V_10 = ( T_7 * ) V_1 ;
F_2 ( V_7 -> V_14 == V_10 -> V_14 , FALSE ) ;
if ( V_7 -> V_15 == NULL ) {
void * V_12 = V_7 -> V_16 ;
int V_11 ;
V_11 = F_13 ( & V_12 ) ;
while ( V_11 != - 1 ) {
T_9 * V_19 = F_11 ( V_11 ) ;
if ( F_12 ( V_19 ) )
break;
V_11 = F_13 ( & V_12 ) ;
}
if ( V_11 == - 1 )
return FALSE ;
V_7 -> V_16 = V_12 ;
V_7 -> V_18 = F_14 ( V_11 ) ;
return TRUE ;
}
{
void * V_30 = V_7 -> V_15 ;
T_8 * V_13 ;
V_13 = F_9 ( & V_30 ) ;
while ( V_13 ) {
if ( V_13 -> V_17 == NULL )
break;
V_13 = F_9 ( & V_30 ) ;
}
if ( ! V_13 )
return FALSE ;
V_7 -> V_15 = V_30 ;
V_7 -> V_18 = V_13 ;
return TRUE ;
}
}
static T_5
F_29 ( T_2 * V_1 , T_6 * V_7 , T_6 * V_8 )
{
return F_6 ( V_1 , V_7 , V_8 , 0 ) ;
}
static T_3
F_30 ( T_2 * V_1 , T_6 * V_7 )
{
T_7 * V_10 ;
T_3 V_31 = 0 ;
int V_32 ;
void * V_12 ;
F_2 ( F_3 ( V_1 ) , 0 ) ;
V_10 = ( T_7 * ) V_1 ;
F_2 ( V_7 == NULL || V_7 -> V_16 != NULL , 0 ) ;
if ( V_7 ) {
T_8 * V_13 ;
F_2 ( V_7 -> V_14 == V_10 -> V_14 , 0 ) ;
if ( V_7 -> V_15 != NULL )
return 0 ;
V_32 = F_7 ( V_7 -> V_16 ) ;
for ( V_13 = F_8 ( V_32 , & V_12 ) ; V_13 ; V_13 = F_9 ( & V_12 ) ) {
if ( V_13 -> V_17 )
continue;
V_31 ++ ;
}
} else {
for ( V_32 = F_10 ( & V_12 ) ; V_32 != - 1 ; V_32 = F_13 ( & V_12 ) ) {
T_9 * V_19 = F_11 ( V_32 ) ;
if ( ! F_12 ( V_19 ) )
continue;
V_31 ++ ;
}
}
return V_31 ;
}
static T_10 *
F_31 ( T_2 * V_1 , T_6 * V_7 )
{
T_7 * V_10 ;
T_10 * V_20 ;
int V_33 ;
int V_32 ;
void * V_12 ;
F_2 ( F_3 ( V_1 ) , NULL ) ;
V_10 = ( T_7 * ) V_1 ;
F_2 ( V_7 != NULL , NULL ) ;
F_2 ( V_7 -> V_14 == V_10 -> V_14 , FALSE ) ;
V_32 = F_7 ( V_7 -> V_16 ) ;
V_20 = F_32 () ;
{
int V_24 ;
V_33 = 0 ;
for ( V_24 = F_10 ( & V_12 ) ; V_24 != V_32 && V_24 != - 1 ; V_24 = F_13 ( & V_12 ) ) {
T_9 * V_19 = F_11 ( V_24 ) ;
if ( ! F_12 ( V_19 ) )
continue;
V_33 ++ ;
}
F_33 ( V_20 , V_33 ) ;
}
if ( V_7 -> V_15 != NULL ) {
T_8 * V_13 ;
V_33 = 0 ;
for ( V_13 = F_8 ( V_32 , & V_12 ) ; V_13 && V_13 != V_7 -> V_18 ; V_13 = F_9 ( & V_12 ) ) {
if ( V_13 -> V_17 )
continue;
V_33 ++ ;
}
F_33 ( V_20 , V_33 ) ;
}
return V_20 ;
}
static T_5
F_34 ( T_2 * V_1 , T_6 * V_7 )
{
return F_30 ( V_1 , V_7 ) != 0 ;
}
static T_5
F_35 ( T_2 * V_1 , T_6 * V_7 , T_6 * V_34 )
{
T_7 * V_10 ;
F_2 ( F_3 ( V_1 ) , FALSE ) ;
V_10 = ( T_7 * ) V_1 ;
F_2 ( V_7 != NULL , FALSE ) ;
F_2 ( V_34 -> V_14 == V_10 -> V_14 , FALSE ) ;
if ( V_34 -> V_15 != NULL ) {
int V_32 = F_7 ( V_34 -> V_16 ) ;
V_7 -> V_14 = V_10 -> V_14 ;
V_7 -> V_16 = V_34 -> V_16 ;
V_7 -> V_15 = NULL ;
V_7 -> V_18 = F_14 ( V_32 ) ;
return TRUE ;
}
return FALSE ;
}
static void
F_36 ( T_12 * V_35 )
{
V_35 -> V_36 = F_1 ;
V_35 -> V_37 = F_4 ;
V_35 -> V_38 = F_5 ;
V_35 -> V_39 = F_15 ;
V_35 -> V_40 = F_31 ;
V_35 -> V_41 = F_23 ;
V_35 -> V_42 = F_28 ;
V_35 -> V_43 = F_29 ;
V_35 -> V_44 = F_34 ;
V_35 -> V_45 = F_30 ;
V_35 -> V_46 = F_6 ;
V_35 -> V_47 = F_35 ;
}
static void
F_37 ( T_7 * V_10 )
{
V_10 -> V_14 = F_38 () ;
}
static void
F_39 ( T_13 * V_48 )
{
(* V_49 -> V_50 )( V_48 ) ;
}
static void
F_40 ( T_14 * V_51 )
{
T_15 * V_52 ;
V_49 = ( T_15 * ) F_41 ( V_51 ) ;
V_52 = ( T_15 * ) V_51 ;
V_52 -> V_50 = F_39 ;
}
T_4
F_42 ( void )
{
static T_4 V_53 = 0 ;
if ( V_53 == 0 ) {
static const T_16 V_54 = {
sizeof( T_14 ) ,
NULL ,
NULL ,
( V_55 ) F_40 ,
NULL ,
NULL ,
sizeof( T_7 ) ,
0 ,
( V_56 ) F_37 ,
NULL
} ;
static const T_17 V_57 = {
( V_58 ) F_36 ,
NULL ,
NULL
} ;
V_53 = F_43 ( V_59 ,
L_3 ,
& V_54 ,
( V_60 ) 0 ) ;
F_44 ( V_53 ,
V_61 ,
& V_57 ) ;
}
return V_53 ;
}
T_7 *
F_45 ( void )
{
T_7 * V_10 ;
V_10 = ( T_7 * ) F_46 ( V_62 , NULL ) ;
F_16 ( V_10 != NULL ) ;
return V_10 ;
}

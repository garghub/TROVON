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
return 1 ;
}
static T_4
F_5 ( T_2 * V_1 , T_3 V_3 )
{
F_2 ( F_3 ( V_1 ) , V_4 ) ;
F_2 ( V_3 == 0 , V_4 ) ;
return V_5 ;
}
static T_5
F_6 ( T_2 * V_1 , T_6 * V_6 , T_6 * V_7 , T_3 V_8 )
{
T_7 * V_9 ;
T_3 V_10 ;
void * V_11 ;
F_2 ( F_3 ( V_1 ) , FALSE ) ;
V_9 = ( T_7 * ) V_1 ;
if ( V_7 ) {
T_8 * V_12 ;
F_2 ( V_7 -> V_13 == V_9 -> V_13 , FALSE ) ;
if ( V_7 -> V_14 != NULL )
return FALSE ;
V_10 = F_7 ( V_7 -> V_15 ) ;
V_12 = F_8 ( V_10 , & V_11 ) ;
while ( V_12 ) {
if ( V_12 -> V_16 == NULL ) {
if ( ! V_8 )
break;
V_8 -- ;
}
V_12 = F_9 ( & V_11 ) ;
}
if ( ! V_12 )
return FALSE ;
V_6 -> V_13 = V_9 -> V_13 ;
V_6 -> V_15 = V_7 -> V_15 ;
V_6 -> V_14 = V_11 ;
V_6 -> V_17 = V_12 ;
return TRUE ;
}
V_10 = F_10 ( & V_11 ) ;
while ( V_10 != - 1 ) {
T_9 * V_18 = F_11 ( V_10 ) ;
if ( F_12 ( V_18 ) ) {
if ( ! V_8 )
break;
V_8 -- ;
}
V_10 = F_13 ( & V_11 ) ;
}
if ( V_10 == - 1 )
return FALSE ;
V_6 -> V_13 = V_9 -> V_13 ;
V_6 -> V_15 = V_11 ;
V_6 -> V_14 = NULL ;
V_6 -> V_17 = F_14 ( V_10 ) ;
return TRUE ;
}
static T_5
F_15 ( T_2 * V_1 , T_6 * V_6 , T_10 * V_19 )
{
T_3 * V_20 , V_21 ;
F_16 ( F_3 ( V_1 ) ) ;
F_16 ( V_19 != NULL ) ;
V_20 = F_17 ( V_19 ) ;
V_21 = F_18 ( V_19 ) ;
F_16 ( V_21 == 1 || V_21 == 2 ) ;
if ( ! F_6 ( V_1 , V_6 , NULL , V_20 [ 0 ] ) )
return FALSE ;
if ( V_21 == 2 ) {
if ( ! F_6 ( V_1 , V_6 , V_6 , V_20 [ 1 ] ) )
return FALSE ;
}
return TRUE ;
}
static void
F_19 ( T_2 * V_1 , T_6 * V_6 , T_3 V_22 , T_11 * V_23 )
{
T_7 * V_9 ;
T_8 * V_12 ;
F_20 ( F_3 ( V_1 ) ) ;
V_9 = ( T_7 * ) V_1 ;
F_20 ( V_6 != NULL ) ;
F_20 ( V_6 -> V_13 == V_9 -> V_13 ) ;
F_20 ( V_22 == 0 ) ;
V_12 = V_6 -> V_17 ;
F_21 ( V_23 , V_5 ) ;
F_22 ( V_23 , V_12 ) ;
}
static T_5
F_23 ( T_2 * V_1 , T_6 * V_6 )
{
T_7 * V_9 ;
F_2 ( F_3 ( V_1 ) , FALSE ) ;
V_9 = ( T_7 * ) V_1 ;
F_2 ( V_6 -> V_13 == V_9 -> V_13 , FALSE ) ;
if ( V_6 -> V_14 == NULL ) {
void * V_11 = V_6 -> V_15 ;
int V_10 ;
V_10 = F_13 ( & V_11 ) ;
while ( V_10 != - 1 ) {
T_9 * V_18 = F_11 ( V_10 ) ;
if ( F_12 ( V_18 ) )
break;
V_10 = F_13 ( & V_11 ) ;
}
if ( V_10 == - 1 )
return FALSE ;
V_6 -> V_15 = V_11 ;
V_6 -> V_17 = F_14 ( V_10 ) ;
return TRUE ;
}
{
void * V_24 = V_6 -> V_14 ;
T_8 * V_12 ;
V_12 = F_9 ( & V_24 ) ;
while ( V_12 ) {
if ( V_12 -> V_16 == NULL )
break;
V_12 = F_9 ( & V_24 ) ;
}
if ( ! V_12 )
return FALSE ;
V_6 -> V_14 = V_24 ;
V_6 -> V_17 = V_12 ;
return TRUE ;
}
}
static T_5
F_24 ( T_2 * V_1 , T_6 * V_6 , T_6 * V_7 )
{
return F_6 ( V_1 , V_6 , V_7 , 0 ) ;
}
static T_3
F_25 ( T_2 * V_1 , T_6 * V_6 )
{
T_7 * V_9 ;
T_3 V_25 = 0 ;
int V_26 ;
void * V_11 ;
F_2 ( F_3 ( V_1 ) , 0 ) ;
V_9 = ( T_7 * ) V_1 ;
F_2 ( V_6 == NULL || V_6 -> V_15 != NULL , 0 ) ;
if ( V_6 ) {
T_8 * V_12 ;
F_2 ( V_6 -> V_13 == V_9 -> V_13 , 0 ) ;
if ( V_6 -> V_14 != NULL )
return 0 ;
V_26 = F_7 ( V_6 -> V_15 ) ;
for ( V_12 = F_8 ( V_26 , & V_11 ) ; V_12 ; V_12 = F_9 ( & V_11 ) ) {
if ( V_12 -> V_16 )
continue;
V_25 ++ ;
}
} else {
for ( V_26 = F_10 ( & V_11 ) ; V_26 != - 1 ; V_26 = F_13 ( & V_11 ) ) {
T_9 * V_18 = F_11 ( V_26 ) ;
if ( ! F_12 ( V_18 ) )
continue;
V_25 ++ ;
}
}
return V_25 ;
}
static T_10 *
F_26 ( T_2 * V_1 , T_6 * V_6 )
{
T_7 * V_9 ;
T_10 * V_19 ;
int V_27 ;
int V_26 ;
void * V_11 ;
F_2 ( F_3 ( V_1 ) , NULL ) ;
V_9 = ( T_7 * ) V_1 ;
F_2 ( V_6 != NULL , NULL ) ;
F_2 ( V_6 -> V_13 == V_9 -> V_13 , FALSE ) ;
V_26 = F_7 ( V_6 -> V_15 ) ;
V_19 = F_27 () ;
{
int V_28 ;
V_27 = 0 ;
for ( V_28 = F_10 ( & V_11 ) ; V_28 != V_26 && V_28 != - 1 ; V_28 = F_13 ( & V_11 ) ) {
T_9 * V_18 = F_11 ( V_28 ) ;
if ( ! F_12 ( V_18 ) )
continue;
V_27 ++ ;
}
F_28 ( V_19 , V_27 ) ;
}
if ( V_6 -> V_14 != NULL ) {
T_8 * V_12 ;
V_27 = 0 ;
for ( V_12 = F_8 ( V_26 , & V_11 ) ; V_12 && V_12 != V_6 -> V_17 ; V_12 = F_9 ( & V_11 ) ) {
if ( V_12 -> V_16 )
continue;
V_27 ++ ;
}
F_28 ( V_19 , V_27 ) ;
}
return V_19 ;
}
static T_5
F_29 ( T_2 * V_1 , T_6 * V_6 )
{
return F_25 ( V_1 , V_6 ) != 0 ;
}
static T_5
F_30 ( T_2 * V_1 , T_6 * V_6 , T_6 * V_29 )
{
T_7 * V_9 ;
F_2 ( F_3 ( V_1 ) , FALSE ) ;
V_9 = ( T_7 * ) V_1 ;
F_2 ( V_6 != NULL , FALSE ) ;
F_2 ( V_29 -> V_13 == V_9 -> V_13 , FALSE ) ;
if ( V_29 -> V_14 != NULL ) {
int V_26 = F_7 ( V_29 -> V_15 ) ;
V_6 -> V_13 = V_9 -> V_13 ;
V_6 -> V_15 = V_29 -> V_15 ;
V_6 -> V_14 = NULL ;
V_6 -> V_17 = F_14 ( V_26 ) ;
return TRUE ;
}
return FALSE ;
}
static void
F_31 ( T_12 * V_30 )
{
V_30 -> V_31 = F_1 ;
V_30 -> V_32 = F_4 ;
V_30 -> V_33 = F_5 ;
V_30 -> V_34 = F_15 ;
V_30 -> V_35 = F_26 ;
V_30 -> V_36 = F_19 ;
V_30 -> V_37 = F_23 ;
V_30 -> V_38 = F_24 ;
V_30 -> V_39 = F_29 ;
V_30 -> V_40 = F_25 ;
V_30 -> V_41 = F_6 ;
V_30 -> V_42 = F_30 ;
}
static void
F_32 ( T_7 * V_9 )
{
V_9 -> V_13 = F_33 () ;
}
static void
F_34 ( T_13 * V_43 )
{
(* V_44 -> V_45 )( V_43 ) ;
}
static void
F_35 ( T_14 * V_46 )
{
T_15 * V_47 ;
V_44 = ( T_15 * ) F_36 ( V_46 ) ;
V_47 = ( T_15 * ) V_46 ;
V_47 -> V_45 = F_34 ;
}
T_4
F_37 ( void )
{
static T_4 V_48 = 0 ;
if ( V_48 == 0 ) {
static const T_16 V_49 = {
sizeof( T_14 ) ,
NULL ,
NULL ,
( V_50 ) F_35 ,
NULL ,
NULL ,
sizeof( T_7 ) ,
0 ,
( V_51 ) F_32 ,
NULL
} ;
static const T_17 V_52 = {
( V_53 ) F_31 ,
NULL ,
NULL
} ;
V_48 = F_38 ( V_54 ,
L_1 ,
& V_49 ,
( V_55 ) 0 ) ;
F_39 ( V_48 ,
V_56 ,
& V_52 ) ;
}
return V_48 ;
}
T_7 *
F_40 ( void )
{
T_7 * V_9 ;
V_9 = ( T_7 * ) F_41 ( V_57 , NULL ) ;
F_16 ( V_9 != NULL ) ;
return V_9 ;
}

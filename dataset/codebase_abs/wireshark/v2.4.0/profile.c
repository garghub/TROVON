T_1 * F_1 ( void ) {
return F_2 ( V_1 ) ;
}
T_1 * F_3 ( void ) {
return F_2 ( V_2 ) ;
}
static T_1 *
F_4 ( T_1 * V_3 , const char * V_4 , const char * V_5 , int V_6 ,
T_2 V_7 , T_2 V_8 )
{
T_3 * V_9 ;
V_9 = ( T_3 * ) F_5 ( sizeof( T_3 ) ) ;
V_9 -> V_10 = F_6 ( V_4 ) ;
V_9 -> V_5 = F_6 ( V_5 ) ;
V_9 -> V_6 = V_6 ;
V_9 -> V_7 = V_7 ;
V_9 -> V_8 = V_8 ;
return F_7 ( V_3 , V_9 ) ;
}
static T_1 *
F_8 ( T_1 * V_3 , T_1 * V_11 )
{
T_3 * V_9 ;
V_9 = ( T_3 * ) V_11 -> V_12 ;
F_9 ( V_9 -> V_10 ) ;
F_9 ( V_9 -> V_5 ) ;
F_9 ( V_9 ) ;
return F_10 ( V_3 , V_11 ) ;
}
const T_4 *
F_11 ( const T_4 * V_4 )
{
T_1 * V_11 = F_2 ( V_2 ) ;
T_5 V_13 = F_12 ( V_2 ) ;
T_3 * V_9 ;
T_5 V_14 ;
if ( V_11 ) {
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
while ( V_11 ) {
V_9 = ( T_3 * ) V_11 -> V_12 ;
if ( strcmp ( V_9 -> V_10 , V_4 ) == 0 ) {
if ( ( V_9 -> V_6 == V_15 ) ||
( V_9 -> V_5 == NULL ) ) {
return NULL ;
} else {
V_4 = V_9 -> V_5 ;
}
}
V_11 = F_13 ( V_11 ) ;
}
V_11 = F_2 ( V_2 ) ;
}
}
return V_4 ;
}
const T_4 * F_14 ( void )
{
char * V_16 , * V_17 , * V_18 ;
T_1 * V_19 , * V_20 ;
T_3 * V_21 , * V_22 ;
T_2 V_23 ;
const T_4 * V_24 ;
V_19 = F_3 () ;
while ( V_19 ) {
V_21 = ( T_3 * ) V_19 -> V_12 ;
F_15 ( V_21 -> V_10 ) ;
if ( ( V_24 = F_16 ( V_21 -> V_10 ) ) != NULL ) {
T_4 * V_25 = F_17 ( L_1 , V_24 ) ;
F_9 ( ( T_4 * ) V_24 ) ;
return V_25 ;
}
V_19 = F_13 ( V_19 ) ;
}
F_18 () ;
V_19 = F_3 () ;
while ( V_19 ) {
V_21 = ( T_3 * ) V_19 -> V_12 ;
F_15 ( V_21 -> V_10 ) ;
if ( V_21 -> V_6 == V_26 ) {
if ( F_19 ( V_21 -> V_10 , & V_16 ) == - 1 ) {
V_24 = F_17 ( L_2 ,
V_16 , F_20 ( V_27 ) ) ;
F_9 ( V_16 ) ;
return V_24 ;
}
V_21 -> V_6 = V_28 ;
if ( V_21 -> V_5 ) {
if ( F_21 ( V_21 -> V_10 , V_21 -> V_5 , V_21 -> V_8 ,
& V_18 , & V_16 , & V_17 ) == - 1 ) {
F_22 ( V_29 , V_30 ,
L_3 ,
V_18 , V_17 , V_16 , F_20 ( V_27 ) ) ;
F_9 ( V_18 ) ;
F_9 ( V_16 ) ;
F_9 ( V_17 ) ;
}
}
F_9 ( V_21 -> V_5 ) ;
V_21 -> V_5 = F_6 ( V_21 -> V_10 ) ;
}
V_19 = F_13 ( V_19 ) ;
}
V_19 = F_3 () ;
while ( V_19 ) {
V_21 = ( T_3 * ) V_19 -> V_12 ;
F_15 ( V_21 -> V_10 ) ;
if ( V_21 -> V_6 == V_15 ) {
if ( strcmp ( V_21 -> V_10 , V_31 ) != 0 ) {
if ( F_19 ( V_21 -> V_10 , & V_16 ) == - 1 ) {
F_22 ( V_29 , V_30 ,
L_2 ,
V_16 , F_20 ( V_27 ) ) ;
F_9 ( V_16 ) ;
}
V_21 -> V_6 = V_28 ;
F_9 ( V_21 -> V_5 ) ;
V_21 -> V_5 = F_6 ( V_21 -> V_10 ) ;
}
} else if ( V_21 -> V_6 == V_32 ) {
if ( strcmp ( V_21 -> V_5 , V_21 -> V_10 ) != 0 ) {
if ( F_23 ( V_21 -> V_5 , V_21 -> V_10 ,
& V_16 , & V_17 ) == - 1 ) {
F_22 ( V_29 , V_30 ,
L_4 ,
V_16 , V_17 , F_20 ( V_27 ) ) ;
F_9 ( V_16 ) ;
F_9 ( V_17 ) ;
}
V_21 -> V_6 = V_28 ;
F_9 ( V_21 -> V_5 ) ;
V_21 -> V_5 = F_6 ( V_21 -> V_10 ) ;
}
}
V_19 = F_13 ( V_19 ) ;
}
V_19 = F_1 () ;
while ( V_19 ) {
V_23 = FALSE ;
V_21 = ( T_3 * ) V_19 -> V_12 ;
V_20 = F_3 () ;
while ( V_20 ) {
V_22 = ( T_3 * ) V_20 -> V_12 ;
if ( ! V_22 -> V_7 ) {
if ( strcmp ( V_21 -> V_10 , V_22 -> V_10 ) == 0 ) {
V_23 = TRUE ;
} else if ( strcmp ( V_21 -> V_10 , V_22 -> V_5 ) == 0 ) {
V_23 = TRUE ;
}
}
V_20 = F_13 ( V_20 ) ;
}
if ( ! V_23 ) {
if ( F_24 ( V_21 -> V_10 , & V_16 ) == - 1 ) {
F_22 ( V_29 , V_30 ,
L_5 ,
V_16 , F_20 ( V_27 ) ) ;
F_9 ( V_16 ) ;
}
}
V_19 = F_13 ( V_19 ) ;
}
F_25 () ;
return NULL ;
}
T_1 *
F_26 ( const char * V_10 , const char * V_33 , int V_6 ,
T_2 V_7 , T_2 V_8 )
{
V_2 = F_4 ( V_2 , V_10 , V_33 , V_6 ,
V_7 , V_8 ) ;
return F_27 ( V_2 ) ;
}
void
F_28 ( T_1 * V_11 )
{
V_2 = F_8 ( V_2 , V_11 ) ;
}
void
F_29 ( T_2 V_34 )
{
T_1 * * V_35 ;
if ( V_34 ) {
V_35 = & V_2 ;
while( * V_35 ) {
* V_35 = F_8 ( * V_35 , F_2 ( * V_35 ) ) ;
}
F_30 ( F_12 ( * V_35 ) == 0 ) ;
}
V_35 = & V_1 ;
while( * V_35 ) {
* V_35 = F_8 ( * V_35 , F_2 ( * V_35 ) ) ;
}
F_30 ( F_12 ( * V_35 ) == 0 ) ;
}
void
F_25 ( void )
{
T_1 * V_36 ;
T_3 * V_9 ;
V_36 = V_2 ;
F_29 ( FALSE ) ;
while( V_36 ) {
V_9 = ( T_3 * ) ( V_36 ) -> V_12 ;
V_1 = F_4 ( V_1 , V_9 -> V_10 ,
V_9 -> V_5 , V_9 -> V_6 ,
V_9 -> V_7 , V_9 -> V_8 ) ;
V_36 = F_13 ( V_36 ) ;
}
}
void
F_31 ( void )
{
T_6 * V_37 ;
T_7 * V_38 ;
const T_4 * V_10 ;
T_4 * V_39 , * V_40 ;
F_29 ( TRUE ) ;
F_26 ( V_31 , V_31 , V_41 , FALSE , FALSE ) ;
V_39 = F_32 () ;
if ( ( V_37 = F_33 ( V_39 , 0 , NULL ) ) != NULL ) {
while ( ( V_38 = F_34 ( V_37 ) ) != NULL ) {
V_10 = F_35 ( V_38 ) ;
V_40 = F_17 ( L_6 , V_39 , V_42 , V_10 ) ;
if ( F_36 ( V_40 ) == V_43 ) {
F_26 ( V_10 , V_10 , V_28 , FALSE , FALSE ) ;
}
F_9 ( V_40 ) ;
}
F_37 ( V_37 ) ;
}
F_9 ( V_39 ) ;
V_39 = F_38 () ;
if ( ( V_37 = F_33 ( V_39 , 0 , NULL ) ) != NULL ) {
while ( ( V_38 = F_34 ( V_37 ) ) != NULL ) {
V_10 = F_35 ( V_38 ) ;
V_40 = F_17 ( L_6 , V_39 , V_42 , V_10 ) ;
if ( F_36 ( V_40 ) == V_43 ) {
F_26 ( V_10 , V_10 , V_28 , TRUE , TRUE ) ;
}
F_9 ( V_40 ) ;
}
F_37 ( V_37 ) ;
}
F_9 ( V_39 ) ;
F_25 () ;
}
T_4 *
F_16 ( const T_4 * V_10 )
{
T_4 * V_44 = NULL ;
T_4 * V_25 ;
#ifdef F_39
char * V_45 = L_7 ;
T_2 V_46 = FALSE ;
int V_14 ;
for ( V_14 = 0 ; V_14 < 9 ; V_14 ++ ) {
if ( strchr ( V_10 , V_45 [ V_14 ] ) ) {
V_46 = TRUE ;
}
}
if ( V_10 [ 0 ] == '.' || V_10 [ strlen ( V_10 ) - 1 ] == '.' ) {
V_46 = TRUE ;
}
if ( V_46 ) {
V_44 = F_17 ( L_8
L_9 ) ;
}
#else
if ( strchr ( V_10 , '/' ) ) {
V_44 = F_17 ( L_10 ) ;
}
#endif
if ( V_44 ) {
V_25 = F_17 ( L_11 , V_44 ) ;
F_9 ( V_44 ) ;
return V_25 ;
}
return NULL ;
}
T_2 F_40 ( void ) {
const T_4 * V_10 = F_41 () ;
char * V_16 ;
if ( F_42 ( V_10 , FALSE ) && strcmp ( V_10 , V_31 ) != 0 ) {
if ( F_24 ( V_10 , & V_16 ) == - 1 ) {
F_22 ( V_29 , V_30 ,
L_5 ,
V_16 , F_20 ( V_27 ) ) ;
F_9 ( V_16 ) ;
} else {
return TRUE ;
}
}
return FALSE ;
}

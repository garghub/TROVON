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
const T_4 * F_14 ( void ) {
char * V_16 , * V_17 , * V_18 ;
T_1 * V_19 , * V_20 ;
T_3 * V_21 , * V_22 ;
T_2 V_23 ;
T_6 * V_24 = F_15 ( NULL ) ;
const T_4 * V_25 ;
V_19 = F_3 () ;
while ( V_19 ) {
V_21 = ( T_3 * ) V_19 -> V_12 ;
F_16 ( V_21 -> V_10 ) ;
if ( ( V_25 = F_17 ( V_21 -> V_10 ) ) != NULL ) {
F_18 ( V_24 , L_1 , V_25 ) ;
return V_24 -> V_26 ;
}
V_19 = F_13 ( V_19 ) ;
}
V_19 = F_3 () ;
while ( V_19 ) {
V_21 = ( T_3 * ) V_19 -> V_12 ;
F_16 ( V_21 -> V_10 ) ;
if ( V_21 -> V_6 == V_27 ) {
if ( F_19 ( V_21 -> V_10 , & V_16 ) == - 1 ) {
F_18 ( V_24 ,
L_2 ,
V_16 , F_20 ( V_28 ) ) ;
F_9 ( V_16 ) ;
}
V_21 -> V_6 = V_29 ;
if ( V_21 -> V_5 ) {
if ( F_21 ( V_21 -> V_10 , V_21 -> V_5 , V_21 -> V_8 ,
& V_18 , & V_16 , & V_17 ) == - 1 ) {
F_22 ( V_30 , V_31 ,
L_3 ,
V_18 , V_17 , V_16 , F_20 ( V_28 ) ) ;
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
F_16 ( V_21 -> V_10 ) ;
if ( V_21 -> V_6 == V_15 ) {
if ( strcmp ( V_21 -> V_10 , V_32 ) != 0 ) {
if ( F_19 ( V_21 -> V_10 , & V_16 ) == - 1 ) {
F_22 ( V_30 , V_31 ,
L_2 ,
V_16 , F_20 ( V_28 ) ) ;
F_9 ( V_16 ) ;
}
V_21 -> V_6 = V_29 ;
F_9 ( V_21 -> V_5 ) ;
V_21 -> V_5 = F_6 ( V_21 -> V_10 ) ;
}
} else if ( V_21 -> V_6 == V_33 ) {
if ( strcmp ( V_21 -> V_5 , V_21 -> V_10 ) != 0 ) {
if ( F_23 ( V_21 -> V_5 , V_21 -> V_10 ,
& V_16 , & V_17 ) == - 1 ) {
F_22 ( V_30 , V_31 ,
L_4 ,
V_16 , V_17 , F_20 ( V_28 ) ) ;
F_9 ( V_16 ) ;
F_9 ( V_17 ) ;
}
V_21 -> V_6 = V_29 ;
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
F_22 ( V_30 , V_31 ,
L_5 ,
V_16 , F_20 ( V_28 ) ) ;
F_9 ( V_16 ) ;
}
}
V_19 = F_13 ( V_19 ) ;
}
F_25 () ;
return NULL ;
}
T_1 *
F_26 ( const char * V_10 , const char * V_34 , int V_6 ,
T_2 V_7 , T_2 V_8 )
{
V_2 = F_4 ( V_2 , V_10 , V_34 , V_6 ,
V_7 , V_8 ) ;
return F_27 ( V_2 ) ;
}
void
F_28 ( T_1 * V_11 )
{
V_2 = F_8 ( V_2 , V_11 ) ;
}
void
F_29 ( T_2 V_35 )
{
T_1 * * V_36 ;
if ( V_35 ) {
V_36 = & V_2 ;
while( * V_36 ) {
* V_36 = F_8 ( * V_36 , F_2 ( * V_36 ) ) ;
}
F_30 ( F_12 ( * V_36 ) == 0 ) ;
}
V_36 = & V_1 ;
while( * V_36 ) {
* V_36 = F_8 ( * V_36 , F_2 ( * V_36 ) ) ;
}
F_30 ( F_12 ( * V_36 ) == 0 ) ;
}
void
F_25 ( void )
{
T_1 * V_37 ;
T_3 * V_9 ;
V_37 = V_2 ;
F_29 ( FALSE ) ;
while( V_37 ) {
V_9 = ( T_3 * ) ( V_37 ) -> V_12 ;
V_1 = F_4 ( V_1 , V_9 -> V_10 ,
V_9 -> V_5 , V_9 -> V_6 ,
V_9 -> V_7 , V_9 -> V_8 ) ;
V_37 = F_13 ( V_37 ) ;
}
}
void
F_31 ( void )
{
T_7 * V_38 ;
T_8 * V_39 ;
const T_4 * V_40 , * V_10 ;
T_4 * V_41 ;
F_29 ( TRUE ) ;
F_26 ( V_32 , V_32 , V_42 , FALSE , FALSE ) ;
V_40 = F_32 () ;
if ( ( V_38 = F_33 ( V_40 , 0 , NULL ) ) != NULL ) {
while ( ( V_39 = F_34 ( V_38 ) ) != NULL ) {
V_10 = F_35 ( V_39 ) ;
V_41 = F_36 ( L_6 , V_40 , V_43 , V_10 ) ;
if ( F_37 ( V_41 ) == V_44 ) {
F_26 ( V_10 , V_10 , V_29 , FALSE , FALSE ) ;
}
F_9 ( V_41 ) ;
}
F_38 ( V_38 ) ;
}
V_40 = F_39 () ;
if ( ( V_38 = F_33 ( V_40 , 0 , NULL ) ) != NULL ) {
while ( ( V_39 = F_34 ( V_38 ) ) != NULL ) {
V_10 = F_35 ( V_39 ) ;
V_41 = F_36 ( L_6 , V_40 , V_43 , V_10 ) ;
if ( F_37 ( V_41 ) == V_44 ) {
F_26 ( V_10 , V_10 , V_29 , TRUE , TRUE ) ;
}
F_9 ( V_41 ) ;
}
F_38 ( V_38 ) ;
}
F_25 () ;
}
const T_4 *
F_17 ( const T_4 * V_10 )
{
T_4 * V_45 = NULL ;
T_6 * V_24 = F_15 ( NULL ) ;
#ifdef F_40
char * V_46 = L_7 ;
T_2 V_47 = FALSE ;
int V_14 ;
for ( V_14 = 0 ; V_14 < 9 ; V_14 ++ ) {
if ( strchr ( V_10 , V_46 [ V_14 ] ) ) {
V_47 = TRUE ;
}
}
if ( V_10 [ 0 ] == '.' || V_10 [ strlen ( V_10 ) - 1 ] == '.' ) {
V_47 = TRUE ;
}
if ( V_47 ) {
V_45 = F_36 ( L_8
L_9 ) ;
}
#else
if ( strchr ( V_10 , '/' ) ) {
V_45 = F_36 ( L_10 ) ;
}
#endif
if ( V_45 ) {
F_18 ( V_24 , L_11 , V_45 ) ;
F_9 ( V_45 ) ;
return V_24 -> V_26 ;
}
return NULL ;
}
T_2 F_41 ( void ) {
const T_4 * V_10 = F_42 () ;
char * V_16 ;
if ( F_43 ( V_10 , FALSE ) && strcmp ( V_10 , V_32 ) != 0 ) {
if ( F_24 ( V_10 , & V_16 ) == - 1 ) {
F_22 ( V_30 , V_31 ,
L_5 ,
V_16 , F_20 ( V_28 ) ) ;
F_9 ( V_16 ) ;
} else {
return TRUE ;
}
}
return FALSE ;
}

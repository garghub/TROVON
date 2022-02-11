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
const T_4 * V_24 ;
V_19 = F_3 () ;
while ( V_19 ) {
V_21 = ( T_3 * ) V_19 -> V_12 ;
F_15 ( V_21 -> V_10 ) ;
if ( ( V_24 = F_16 ( V_21 -> V_10 ) ) != NULL ) {
return V_24 ;
}
V_19 = F_13 ( V_19 ) ;
}
V_19 = F_3 () ;
while ( V_19 ) {
V_21 = ( T_3 * ) V_19 -> V_12 ;
F_15 ( V_21 -> V_10 ) ;
if ( V_21 -> V_6 == V_25 ) {
if ( F_17 ( V_21 -> V_10 , & V_16 ) == - 1 ) {
V_24 = F_18 ( L_1 ,
V_16 , F_19 ( V_26 ) ) ;
F_9 ( V_16 ) ;
return V_24 ;
}
V_21 -> V_6 = V_27 ;
if ( V_21 -> V_5 ) {
if ( F_20 ( V_21 -> V_10 , V_21 -> V_5 , V_21 -> V_8 ,
& V_18 , & V_16 , & V_17 ) == - 1 ) {
F_21 ( V_28 , V_29 ,
L_2 ,
V_18 , V_17 , V_16 , F_19 ( V_26 ) ) ;
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
if ( strcmp ( V_21 -> V_10 , V_30 ) != 0 ) {
if ( F_17 ( V_21 -> V_10 , & V_16 ) == - 1 ) {
F_21 ( V_28 , V_29 ,
L_1 ,
V_16 , F_19 ( V_26 ) ) ;
F_9 ( V_16 ) ;
}
V_21 -> V_6 = V_27 ;
F_9 ( V_21 -> V_5 ) ;
V_21 -> V_5 = F_6 ( V_21 -> V_10 ) ;
}
} else if ( V_21 -> V_6 == V_31 ) {
if ( strcmp ( V_21 -> V_5 , V_21 -> V_10 ) != 0 ) {
if ( F_22 ( V_21 -> V_5 , V_21 -> V_10 ,
& V_16 , & V_17 ) == - 1 ) {
F_21 ( V_28 , V_29 ,
L_3 ,
V_16 , V_17 , F_19 ( V_26 ) ) ;
F_9 ( V_16 ) ;
F_9 ( V_17 ) ;
}
V_21 -> V_6 = V_27 ;
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
if ( F_23 ( V_21 -> V_10 , & V_16 ) == - 1 ) {
F_21 ( V_28 , V_29 ,
L_4 ,
V_16 , F_19 ( V_26 ) ) ;
F_9 ( V_16 ) ;
}
}
V_19 = F_13 ( V_19 ) ;
}
F_24 () ;
return NULL ;
}
T_1 *
F_25 ( const char * V_10 , const char * V_32 , int V_6 ,
T_2 V_7 , T_2 V_8 )
{
V_2 = F_4 ( V_2 , V_10 , V_32 , V_6 ,
V_7 , V_8 ) ;
return F_26 ( V_2 ) ;
}
void
F_27 ( T_1 * V_11 )
{
V_2 = F_8 ( V_2 , V_11 ) ;
}
void
F_28 ( T_2 V_33 )
{
T_1 * * V_34 ;
if ( V_33 ) {
V_34 = & V_2 ;
while( * V_34 ) {
* V_34 = F_8 ( * V_34 , F_2 ( * V_34 ) ) ;
}
F_29 ( F_12 ( * V_34 ) == 0 ) ;
}
V_34 = & V_1 ;
while( * V_34 ) {
* V_34 = F_8 ( * V_34 , F_2 ( * V_34 ) ) ;
}
F_29 ( F_12 ( * V_34 ) == 0 ) ;
}
void
F_24 ( void )
{
T_1 * V_35 ;
T_3 * V_9 ;
V_35 = V_2 ;
F_28 ( FALSE ) ;
while( V_35 ) {
V_9 = ( T_3 * ) ( V_35 ) -> V_12 ;
V_1 = F_4 ( V_1 , V_9 -> V_10 ,
V_9 -> V_5 , V_9 -> V_6 ,
V_9 -> V_7 , V_9 -> V_8 ) ;
V_35 = F_13 ( V_35 ) ;
}
}
void
F_30 ( void )
{
T_6 * V_36 ;
T_7 * V_37 ;
const T_4 * V_38 , * V_10 ;
T_4 * V_39 ;
F_28 ( TRUE ) ;
F_25 ( V_30 , V_30 , V_40 , FALSE , FALSE ) ;
V_38 = F_31 () ;
if ( ( V_36 = F_32 ( V_38 , 0 , NULL ) ) != NULL ) {
while ( ( V_37 = F_33 ( V_36 ) ) != NULL ) {
V_10 = F_34 ( V_37 ) ;
V_39 = F_18 ( L_5 , V_38 , V_41 , V_10 ) ;
if ( F_35 ( V_39 ) == V_42 ) {
F_25 ( V_10 , V_10 , V_27 , FALSE , FALSE ) ;
}
F_9 ( V_39 ) ;
}
F_36 ( V_36 ) ;
}
V_38 = F_37 () ;
if ( ( V_36 = F_32 ( V_38 , 0 , NULL ) ) != NULL ) {
while ( ( V_37 = F_33 ( V_36 ) ) != NULL ) {
V_10 = F_34 ( V_37 ) ;
V_39 = F_18 ( L_5 , V_38 , V_41 , V_10 ) ;
if ( F_35 ( V_39 ) == V_42 ) {
F_25 ( V_10 , V_10 , V_27 , TRUE , TRUE ) ;
}
F_9 ( V_39 ) ;
}
F_36 ( V_36 ) ;
}
F_24 () ;
}
T_4 *
F_16 ( const T_4 * V_10 )
{
T_4 * V_43 = NULL ;
T_4 * V_44 ;
#ifdef F_38
char * V_45 = L_6 ;
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
V_43 = F_18 ( L_7
L_8 ) ;
}
#else
if ( strchr ( V_10 , '/' ) ) {
V_43 = F_18 ( L_9 ) ;
}
#endif
if ( V_43 ) {
V_44 = F_18 ( L_10 , V_43 ) ;
F_9 ( V_43 ) ;
return V_44 ;
}
return NULL ;
}
T_2 F_39 ( void ) {
const T_4 * V_10 = F_40 () ;
char * V_16 ;
if ( F_41 ( V_10 , FALSE ) && strcmp ( V_10 , V_30 ) != 0 ) {
if ( F_23 ( V_10 , & V_16 ) == - 1 ) {
F_21 ( V_28 , V_29 ,
L_4 ,
V_16 , F_19 ( V_26 ) ) ;
F_9 ( V_16 ) ;
} else {
return TRUE ;
}
}
return FALSE ;
}

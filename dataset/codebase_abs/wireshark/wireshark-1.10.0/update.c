int
F_1 ( const char * V_1 , const char * V_2 ) {
T_1 * V_3 ;
char V_4 [ 100 ] ;
int V_5 ;
int V_6 ;
int V_7 ;
int V_8 = 0 ;
V_6 = F_2 ( V_2 , V_9 | V_10 | V_11 | V_12 , 0644 ) ;
if( V_6 == - 1 ) {
F_3 ( L_1 , V_2 ) ;
return - 1 ;
}
V_3 = F_4 ( V_1 ) ;
if ( V_3 == NULL ) {
F_5 ( V_6 ) ;
F_3 ( L_2 , V_1 ) ;
return - 1 ;
}
do {
V_5 = F_6 ( V_3 , V_4 , sizeof( V_4 ) ) ;
V_7 = F_7 ( V_6 , V_4 , V_5 ) ;
if( V_7 != V_5 ) {
F_3 ( L_3 , V_7 , V_5 ) ;
V_8 = - 1 ;
break;
}
} while( V_5 > 0 );
F_8 ( V_3 ) ;
F_5 ( V_6 ) ;
return V_8 ;
}
T_2 *
F_9 ( void )
{
return F_10 ( sizeof( T_2 ) ) ;
}
void
F_11 ( T_2 * V_13 )
{
F_12 ( V_13 -> V_14 ) ;
F_12 ( V_13 -> V_15 ) ;
F_12 ( V_13 -> V_16 ) ;
F_12 ( V_13 -> V_17 ) ;
F_12 ( V_13 -> V_18 ) ;
F_12 ( V_13 -> V_1 ) ;
F_12 ( V_13 -> V_19 ) ;
F_12 ( V_13 -> V_20 ) ;
F_12 ( V_13 ) ;
}
static void
F_13 ( T_3 * V_21 , T_3 * V_22 , char * V_23 , char * V_24 , char * * V_25 )
{
T_4 * V_26 = F_14 ( V_23 ) ;
F_15 ( V_26 , V_24 ) ;
if( strcmp ( V_21 , V_26 -> V_27 ) == 0 ) {
if( * V_25 )
F_3 ( L_4 , V_21 , V_22 , * V_25 ) ;
else
* V_25 = F_16 ( V_22 ) ;
}
F_17 ( V_26 , TRUE ) ;
}
static T_5
F_18 ( T_3 * V_21 , T_3 * V_22 , void * V_28 )
{
T_2 * V_13 = V_28 ;
F_13 ( V_21 , V_22 , V_13 -> V_14 , L_5 , & V_13 -> V_16 ) ;
F_13 ( V_21 , V_22 , V_13 -> V_14 , L_6 , & V_13 -> V_17 ) ;
F_13 ( V_21 , V_22 , V_13 -> V_14 , L_7 , & V_13 -> V_18 ) ;
F_13 ( V_21 , V_22 , V_13 -> V_14 , L_8 , & V_13 -> V_1 ) ;
F_13 ( V_21 , V_22 , V_13 -> V_14 , L_9 , & V_13 -> V_19 ) ;
F_13 ( V_21 , V_22 , V_13 -> V_14 , L_10 , & V_13 -> V_20 ) ;
return V_29 ;
}
static void
F_19 ( T_2 * V_13 )
{
T_4 * V_30 ;
V_30 = F_14 ( L_11 ) ;
if( V_13 -> V_16 ) {
F_20 ( V_30 , L_12 ,
F_21 () , V_13 -> V_16 , F_22 () ) ;
} else {
F_20 ( V_30 , L_13 ,
F_21 () , F_22 () ) ;
}
F_15 ( V_30 , L_14 ) ;
if( V_13 -> V_17 )
F_20 ( V_30 , L_15 , V_13 -> V_17 ) ;
F_20 ( V_30 , L_16 , V_13 -> V_15 ) ;
if( V_13 -> V_18 )
F_20 ( V_30 , L_17 , V_13 -> V_18 ) ;
else
F_15 ( V_30 , L_18 ) ;
if( V_13 -> V_18 && V_13 -> V_1 )
F_20 ( V_30 , L_19 , V_13 -> V_1 ) ;
if( V_13 -> V_20 )
F_20 ( V_30 , L_20 , V_13 -> V_20 ) ;
F_23 ( V_31 , V_32 , V_30 -> V_27 ) ;
F_17 ( V_30 , TRUE ) ;
}
static T_2 *
F_24 ( const char * V_33 )
{
T_6 * V_34 ;
T_2 * V_13 = F_9 () ;
V_13 -> V_15 = F_16 ( V_35 ) ;
V_13 -> V_14 = L_21 ;
V_34 = F_25 ( V_33 , L_22 ) ;
if( V_34 != NULL ) {
F_26 ( V_33 , V_34 , F_18 , V_13 ) ;
fclose ( V_34 ) ;
if( V_13 -> V_15 && V_13 -> V_18 &&
strcmp ( V_13 -> V_15 , V_13 -> V_18 ) != 0 )
{
V_13 -> V_36 = TRUE ;
}
} else {
F_3 ( L_23 , V_33 ) ;
}
return V_13 ;
}
static T_2 *
F_27 ( const char * V_33 )
{
T_6 * V_34 ;
T_2 * V_13 = F_9 () ;
T_4 * V_37 ;
char * V_38 = NULL ;
char * V_39 ;
char * V_40 ;
V_13 -> V_14 = L_24 ;
V_34 = F_25 ( V_33 , L_22 ) ;
if( V_34 != NULL ) {
F_26 ( V_33 , V_34 , F_18 , V_13 ) ;
fclose ( V_34 ) ;
V_37 = F_14 ( L_11 ) ;
F_28 ( V_37 ) ;
V_39 = strstr ( V_37 -> V_27 , L_25 ) ;
if( V_39 != NULL ) {
V_39 += sizeof( L_26 ) ;
V_40 = strstr ( V_39 , L_27 ) ;
if( V_40 != NULL ) {
V_40 [ 0 ] = 0 ;
V_38 = F_16 ( V_39 ) ;
}
}
V_13 -> V_15 = F_16 ( V_38 ) ;
if( V_38 && V_13 -> V_18 &&
strcmp ( V_38 , V_13 -> V_18 ) != 0 )
{
V_13 -> V_36 = TRUE ;
}
} else {
F_3 ( L_23 , V_33 ) ;
}
F_17 ( V_37 , TRUE ) ;
F_12 ( V_38 ) ;
return V_13 ;
}
void
F_29 ( T_7 V_41 )
{
char * V_33 ;
const char * V_42 = L_28 ;
T_2 * V_43 ;
T_2 * V_44 ;
V_33 = F_30 ( L_29 , FALSE ) ;
if( V_33 == NULL ) {
F_3 ( L_30 ) ;
return;
}
if( F_1 ( V_42 , V_33 ) == - 1 ) {
F_3 ( L_31 , V_33 ) ;
F_12 ( V_33 ) ;
return;
}
V_43 = F_24 ( V_33 ) ;
V_44 = F_27 ( V_33 ) ;
if( V_43 -> V_36 || V_44 -> V_36 ) {
if( V_43 -> V_36 )
F_19 ( V_43 ) ;
if( V_44 -> V_36 )
F_19 ( V_44 ) ;
} else {
if( V_41 ) {
F_23 ( V_31 , V_32 , L_32 ) ;
}
}
F_11 ( V_43 ) ;
F_11 ( V_44 ) ;
F_12 ( V_33 ) ;
}

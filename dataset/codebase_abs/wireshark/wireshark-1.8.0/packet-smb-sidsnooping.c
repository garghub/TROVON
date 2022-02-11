char *
F_1 ( char * V_1 )
{
T_1 * V_2 ;
T_1 V_3 ;
V_3 . V_1 = V_1 ;
V_2 = F_2 ( V_4 , & V_3 ) ;
if( ! V_2 ) {
return NULL ;
}
return V_2 -> V_5 ;
}
static void
F_3 ( char * V_1 , char * V_5 )
{
T_1 * V_2 ;
T_1 V_3 ;
V_3 . V_1 = V_1 ;
V_2 = F_2 ( V_4 , & V_3 ) ;
if( V_2 ) {
return;
}
V_2 = F_4 ( sizeof( T_1 ) ) ;
V_2 -> V_1 = F_5 ( V_1 ) ;
V_2 -> V_5 = F_5 ( V_5 ) ;
F_6 ( V_4 , V_2 , V_2 ) ;
}
static int
F_7 ( void * T_2 V_6 , T_3 * V_7 , T_4 * V_8 , const void * V_9 )
{
const T_5 * V_10 = V_9 ;
void * V_11 = NULL ;
char * V_12 ;
char * V_1 ;
int V_13 ;
int V_14 ;
int V_15 ;
T_6 * V_16 ;
T_6 * V_17 ;
T_6 * V_18 ;
T_7 * V_19 ;
T_7 * V_20 ;
T_7 * V_21 ;
char V_22 [ 256 ] ;
int V_23 ;
V_16 = F_8 ( V_8 -> V_24 , V_25 ) ;
if( ! V_16 || V_16 -> V_26 != 1 ) {
return 0 ;
}
V_19 = V_16 -> V_27 [ 0 ] ;
V_23 = V_19 -> V_28 . V_28 . V_29 ;
if( V_23 != 1 ) {
return 0 ;
}
if( ! V_10 ) {
return 0 ;
}
if( ! V_10 -> V_30 ) {
return 0 ;
}
if( V_10 -> V_31 == V_32 ) {
V_16 = F_8 ( V_8 -> V_24 , V_33 ) ;
if( ! V_16 || V_16 -> V_26 != 1 ) {
return 0 ;
}
V_19 = V_16 -> V_27 [ 0 ] ;
V_11 = F_2 ( V_34 , F_9 ( V_7 -> V_35 -> V_36 ) ) ;
if( V_11 ) {
F_10 ( V_34 , F_9 ( V_7 -> V_35 -> V_36 ) ) ;
}
if( ! V_11 ) {
V_11 = F_11 ( V_19 -> V_28 . V_28 . V_37 -> V_38 , 20 ) ;
}
F_6 ( V_34 , F_9 ( V_7 -> V_35 -> V_36 ) , V_11 ) ;
return 0 ;
}
if( ! V_10 -> V_30 -> V_39 ) {
return 0 ;
}
V_11 = F_2 ( V_34 , F_9 ( V_10 -> V_30 -> V_39 ) ) ;
if( ! V_11 ) {
return 0 ;
}
if ( ! F_12 ( V_11 , & V_12 , NULL , NULL , NULL , V_10 -> V_30 -> V_39 ) ) {
return 0 ;
}
if ( ! V_12 )
return 0 ;
V_1 = strstr ( V_12 , L_1 ) ;
if( ! V_1 ) {
return 0 ;
}
for( V_13 = 4 ; 1 ; V_13 ++ ) {
if( ( V_1 [ V_13 ] >= '0' ) && ( V_1 [ V_13 ] <= '9' ) ) {
continue;
}
if( V_1 [ V_13 ] == '-' ) {
continue;
}
break;
}
V_17 = F_8 ( V_8 -> V_24 , V_40 ) ;
if( ! V_17 || V_17 -> V_26 < 1 ) {
return 0 ;
}
V_14 = V_17 -> V_26 ;
V_18 = F_8 ( V_8 -> V_24 , V_41 ) ;
if( ! V_18 || V_18 -> V_26 < 1 ) {
return 0 ;
}
V_15 = V_18 -> V_26 ;
if( V_14 > V_15 ) {
V_14 = V_15 ;
}
for(; V_14 ; V_14 -- ) {
int V_26 = V_13 ;
if ( V_26 > 247 )
V_26 = 247 ;
V_20 = V_17 -> V_27 [ V_14 - 1 ] ;
V_21 = V_18 -> V_27 [ V_14 - 1 ] ;
F_13 ( V_22 , V_1 , 256 ) ;
V_22 [ V_26 ++ ] = '-' ;
F_14 ( V_22 + V_26 , 256 - V_26 , L_2 , V_20 -> V_28 . V_28 . V_29 ) ;
F_3 ( V_22 , V_21 -> V_28 . V_28 . string ) ;
}
return 1 ;
}
static int
F_15 ( void * T_2 V_6 , T_3 * V_7 V_6 , T_4 * V_8 , const void * V_9 V_6 )
{
T_6 * V_16 ;
T_7 * V_19 ;
char * V_42 ;
char * V_1 ;
int V_23 ;
V_16 = F_8 ( V_8 -> V_24 , V_43 ) ;
if( ! V_16 || V_16 -> V_26 != 1 ) {
return 0 ;
}
V_19 = V_16 -> V_27 [ 0 ] ;
V_23 = V_19 -> V_28 . V_28 . V_29 ;
switch( V_23 ) {
case 3 :
case 5 :
case 12 :
V_16 = F_8 ( V_8 -> V_24 , V_44 ) ;
if( ! V_16 || V_16 -> V_26 != 1 ) {
return 0 ;
}
V_19 = V_16 -> V_27 [ 0 ] ;
V_42 = V_19 -> V_28 . V_28 . string ;
V_16 = F_8 ( V_8 -> V_24 , V_45 ) ;
if( ! V_16 || V_16 -> V_26 != 1 ) {
return 0 ;
}
V_19 = V_16 -> V_27 [ 0 ] ;
V_1 = V_19 -> V_28 . V_28 . string ;
F_3 ( V_1 , V_42 ) ;
break;
}
return 0 ;
}
static T_8
F_16 ( T_9 V_46 , T_9 V_28 V_6 , T_9 T_10 V_6 )
{
T_1 * V_2 = ( T_1 * ) V_46 ;
if( V_2 -> V_1 ) {
F_17 ( ( T_9 ) V_2 -> V_1 ) ;
V_2 -> V_1 = NULL ;
}
if( V_2 -> V_5 ) {
F_17 ( ( T_9 ) V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
return TRUE ;
}
static T_11
F_18 ( T_12 V_47 , T_12 V_48 )
{
const T_1 * V_49 = ( const T_1 * ) V_47 ;
const T_1 * V_50 = ( const T_1 * ) V_48 ;
return ! strcmp ( V_49 -> V_1 , V_50 -> V_1 ) ;
}
static T_13
F_19 ( T_12 V_51 )
{
const T_1 * V_2 = ( const T_1 * ) V_51 ;
int V_52 , V_53 ;
for( V_53 = 0 , V_52 = ( int ) strlen ( V_2 -> V_1 ) - 1 ; V_52 >= 0 ; V_52 -- ) {
V_53 += V_2 -> V_1 [ V_52 ] ;
}
return V_53 ;
}
static T_8
F_20 ( T_9 V_46 V_6 , T_9 V_28 V_6 , T_9 T_10 V_6 )
{
return TRUE ;
}
static T_11
F_21 ( T_12 V_47 , T_12 V_48 )
{
int V_49 = F_22 ( V_47 ) ;
int V_50 = F_22 ( V_48 ) ;
return V_49 == V_50 ;
}
static T_13
F_23 ( T_12 V_51 )
{
int V_2 = F_22 ( V_51 ) ;
return V_2 ;
}
static void
F_24 ( void )
{
T_14 * V_54 ;
T_15 * V_55 ;
if( V_56 ) {
F_25 ( & V_56 ) ;
V_56 = FALSE ;
}
if( V_57 ) {
F_25 ( & V_57 ) ;
V_57 = FALSE ;
}
if( V_4 ) {
F_26 ( V_4 , F_16 , NULL ) ;
V_4 = NULL ;
}
if( V_34 ) {
F_26 ( V_34 , F_20 , NULL ) ;
V_34 = NULL ;
}
V_58 = 0 ;
if( ! V_58 ) {
return;
}
V_4 = F_27 ( F_19 , F_18 ) ;
V_34 = F_27 ( F_23 , F_21 ) ;
V_59 = F_28 ( L_3 ) ;
V_54 = F_29 ( L_4 ) ;
if( V_54 ) {
V_60 = V_54 -> V_61 ;
}
V_54 = F_29 ( L_5 ) ;
if( V_54 ) {
V_45 = V_54 -> V_61 ;
}
V_54 = F_29 ( L_6 ) ;
if( V_54 ) {
V_44 = V_54 -> V_61 ;
}
V_54 = F_29 ( L_7 ) ;
if( V_54 ) {
V_43 = V_54 -> V_61 ;
}
V_54 = F_29 ( L_8 ) ;
if( V_54 ) {
V_33 = V_54 -> V_61 ;
}
V_54 = F_29 ( L_9 ) ;
if( V_54 ) {
V_40 = V_54 -> V_61 ;
}
V_54 = F_29 ( L_10 ) ;
if( V_54 ) {
V_41 = V_54 -> V_61 ;
}
V_54 = F_29 ( L_11 ) ;
if( V_54 ) {
V_25 = V_54 -> V_61 ;
}
V_55 = F_30 ( L_12 ,
& V_56 ,
L_13 ,
V_62 , NULL , F_15 , NULL ) ;
if( V_55 ) {
fprintf ( V_63 , L_14 ,
V_55 -> V_64 ) ;
F_31 ( V_55 , TRUE ) ;
return;
}
V_56 = TRUE ;
V_55 = F_30 ( L_12 ,
& V_57 ,
L_15 ,
V_62 , NULL , F_7 , NULL ) ;
if( V_55 ) {
fprintf ( V_63 , L_16 ,
V_55 -> V_64 ) ;
F_31 ( V_55 , TRUE ) ;
return;
}
V_57 = TRUE ;
}
void
F_32 ( void )
{
F_33 ( F_24 ) ;
}
void
F_34 ( void )
{
}

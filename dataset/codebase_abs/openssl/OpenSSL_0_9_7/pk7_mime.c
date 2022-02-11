static int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_1 * V_3 ;
if( ! ( V_3 = F_2 ( F_3 () ) ) ) {
F_4 ( V_4 , V_5 ) ;
return 0 ;
}
V_1 = F_5 ( V_3 , V_1 ) ;
F_6 ( V_1 , V_2 ) ;
F_7 ( V_1 ) ;
V_1 = F_8 ( V_1 ) ;
F_9 ( V_3 ) ;
return 1 ;
}
static T_2 * F_10 ( T_1 * V_1 )
{
T_1 * V_3 ;
T_2 * V_2 ;
if( ! ( V_3 = F_2 ( F_3 () ) ) ) {
F_4 ( V_6 , V_5 ) ;
return 0 ;
}
V_1 = F_5 ( V_3 , V_1 ) ;
if( ! ( V_2 = F_11 ( V_1 , NULL ) ) )
F_4 ( V_6 , V_7 ) ;
F_7 ( V_1 ) ;
V_1 = F_8 ( V_1 ) ;
F_9 ( V_3 ) ;
return V_2 ;
}
int F_12 ( T_1 * V_1 , T_2 * V_2 , T_1 * V_8 , int V_9 )
{
char V_10 [ V_11 ] ;
char V_12 [ 33 ] , V_13 ;
int V_14 ;
if( ( V_9 & V_15 ) && V_8 ) {
F_13 ( ( unsigned char * ) V_12 , 32 ) ;
for( V_14 = 0 ; V_14 < 32 ; V_14 ++ ) {
V_13 = V_12 [ V_14 ] & 0xf ;
if( V_13 < 10 ) V_13 += '0' ;
else V_13 += 'A' - 10 ;
V_12 [ V_14 ] = V_13 ;
}
V_12 [ 32 ] = 0 ;
F_14 ( V_1 , L_1 ) ;
F_14 ( V_1 , L_2 ) ;
F_14 ( V_1 , L_3 ) ;
F_14 ( V_1 , L_4 , V_12 ) ;
F_14 ( V_1 , L_5 ) ;
F_14 ( V_1 , L_6 , V_12 ) ;
if( V_9 & V_16 ) F_14 ( V_1 , L_7 ) ;
while( ( V_14 = F_15 ( V_8 , V_10 , V_11 ) ) > 0 )
F_16 ( V_1 , V_10 , V_14 ) ;
F_14 ( V_1 , L_8 , V_12 ) ;
F_14 ( V_1 , L_9 ) ;
F_14 ( V_1 , L_10 ) ;
F_14 ( V_1 , L_11 ) ;
F_1 ( V_1 , V_2 ) ;
F_14 ( V_1 , L_12 , V_12 ) ;
return 1 ;
}
F_14 ( V_1 , L_1 ) ;
F_14 ( V_1 , L_13 ) ;
F_14 ( V_1 , L_14 ) ;
F_14 ( V_1 , L_15 ) ;
F_1 ( V_1 , V_2 ) ;
F_14 ( V_1 , L_16 ) ;
return 1 ;
}
T_2 * F_17 ( T_1 * V_1 , T_1 * * V_17 )
{
T_1 * V_18 ;
F_18 ( V_19 ) * V_20 = NULL ;
F_18 ( T_1 ) * V_21 = NULL ;
V_19 * V_22 ;
T_3 * V_23 ;
T_2 * V_2 ;
int V_24 ;
if( V_17 ) * V_17 = NULL ;
if ( ! ( V_20 = F_19 ( V_1 ) ) ) {
F_4 ( V_25 , V_26 ) ;
return NULL ;
}
if( ! ( V_22 = F_20 ( V_20 , L_17 ) ) || ! V_22 -> V_27 ) {
F_21 ( V_20 , V_28 ) ;
F_4 ( V_25 , V_29 ) ;
return NULL ;
}
if( ! strcmp ( V_22 -> V_27 , L_18 ) ) {
V_23 = F_22 ( V_22 , L_19 ) ;
if( ! V_23 || ! V_23 -> V_30 ) {
F_21 ( V_20 , V_28 ) ;
F_4 ( V_25 , V_31 ) ;
return NULL ;
}
V_24 = F_23 ( V_1 , V_23 -> V_30 , & V_21 ) ;
F_21 ( V_20 , V_28 ) ;
if( ! V_24 || ( F_24 ( V_21 ) != 2 ) ) {
F_4 ( V_25 , V_32 ) ;
F_25 ( V_21 , V_33 ) ;
return NULL ;
}
V_18 = F_26 ( V_21 , 1 ) ;
if ( ! ( V_20 = F_19 ( V_18 ) ) ) {
F_4 ( V_25 , V_34 ) ;
F_25 ( V_21 , V_33 ) ;
return NULL ;
}
if( ! ( V_22 = F_20 ( V_20 , L_17 ) ) ||
! V_22 -> V_27 ) {
F_21 ( V_20 , V_28 ) ;
F_4 ( V_25 , V_35 ) ;
return NULL ;
}
if( strcmp ( V_22 -> V_27 , L_20 ) &&
strcmp ( V_22 -> V_27 , L_21 ) ) {
F_21 ( V_20 , V_28 ) ;
F_4 ( V_25 , V_36 ) ;
F_27 ( 2 , L_22 , V_22 -> V_27 ) ;
F_25 ( V_21 , V_33 ) ;
return NULL ;
}
F_21 ( V_20 , V_28 ) ;
if( ! ( V_2 = F_10 ( V_18 ) ) ) {
F_4 ( V_25 , V_37 ) ;
F_25 ( V_21 , V_33 ) ;
return NULL ;
}
if( V_17 ) {
* V_17 = F_26 ( V_21 , 0 ) ;
F_9 ( V_18 ) ;
F_28 ( V_21 ) ;
} else F_25 ( V_21 , V_33 ) ;
return V_2 ;
}
if ( strcmp ( V_22 -> V_27 , L_23 ) &&
strcmp ( V_22 -> V_27 , L_24 ) ) {
F_4 ( V_25 , V_38 ) ;
F_27 ( 2 , L_22 , V_22 -> V_27 ) ;
F_21 ( V_20 , V_28 ) ;
return NULL ;
}
F_21 ( V_20 , V_28 ) ;
if( ! ( V_2 = F_10 ( V_1 ) ) ) {
F_4 ( V_25 , V_39 ) ;
return NULL ;
}
return V_2 ;
}
int F_29 ( T_1 * V_40 , T_1 * V_41 , int V_9 )
{
char V_42 ;
int V_43 ;
char V_10 [ V_11 ] ;
if( V_9 & V_44 ) {
while( ( V_43 = F_15 ( V_40 , V_10 , V_11 ) ) > 0 )
F_16 ( V_41 , V_10 , V_43 ) ;
return 1 ;
}
if( V_9 & V_16 ) F_14 ( V_41 , L_25 ) ;
while ( ( V_43 = F_30 ( V_40 , V_10 , V_11 ) ) > 0 ) {
V_42 = 0 ;
while( F_31 ( V_10 [ V_43 - 1 ] ) ) {
V_43 -- ;
V_42 = 1 ;
}
F_16 ( V_41 , V_10 , V_43 ) ;
if( V_42 ) F_16 ( V_41 , L_26 , 2 ) ;
}
return 1 ;
}
int F_32 ( T_1 * V_40 , T_1 * V_41 )
{
char V_45 [ 4096 ] ;
int V_43 ;
F_18 ( V_19 ) * V_20 ;
V_19 * V_22 ;
if ( ! ( V_20 = F_19 ( V_40 ) ) ) {
F_4 ( V_46 , V_26 ) ;
return 0 ;
}
if( ! ( V_22 = F_20 ( V_20 , L_17 ) ) || ! V_22 -> V_27 ) {
F_4 ( V_46 , V_47 ) ;
F_21 ( V_20 , V_28 ) ;
return 0 ;
}
if ( strcmp ( V_22 -> V_27 , L_27 ) ) {
F_4 ( V_46 , V_38 ) ;
F_27 ( 2 , L_22 , V_22 -> V_27 ) ;
F_21 ( V_20 , V_28 ) ;
return 0 ;
}
F_21 ( V_20 , V_28 ) ;
while ( ( V_43 = F_15 ( V_40 , V_45 , sizeof( V_45 ) ) ) > 0 )
F_16 ( V_41 , V_45 , V_43 ) ;
return 1 ;
}
static int F_31 ( char V_13 )
{
if( V_13 == '\r' || V_13 == '\n' ) return 1 ;
return 0 ;
}
char * F_33 ( char * V_48 )
{
return F_34 ( F_35 ( V_48 ) ) ;
}
static char * F_35 ( char * V_48 )
{
char * V_49 , V_13 ;
for( V_49 = V_48 ; ( V_13 = * V_49 ) ; V_49 ++ ) {
if( V_13 == '"' ) {
if( V_49 [ 1 ] ) return V_49 + 1 ;
return NULL ;
}
if( ! isspace ( ( unsigned char ) V_13 ) ) return V_49 ;
}
return NULL ;
}
static char * F_34 ( char * V_48 )
{
char * V_49 , V_13 ;
if( ! V_48 ) return NULL ;
for( V_49 = V_48 + strlen ( V_48 ) - 1 ; V_49 >= V_48 ; V_49 -- ) {
V_13 = * V_49 ;
if( V_13 == '"' ) {
if( V_49 - 1 == V_48 ) return NULL ;
* V_49 = 0 ;
return V_48 ;
}
if( isspace ( ( unsigned char ) V_13 ) ) * V_49 = 0 ;
else return V_48 ;
}
return NULL ;
}
static V_19 * F_36 ( char * V_48 , char * V_27 )
{
V_19 * V_50 ;
char * V_51 , * V_52 , * V_49 ;
int V_13 ;
if( V_48 ) {
if( ! ( V_51 = F_37 ( V_48 ) ) ) return NULL ;
for( V_49 = V_51 ; * V_49 ; V_49 ++ ) {
V_13 = * V_49 ;
if( isupper ( V_13 ) ) {
V_13 = tolower ( V_13 ) ;
* V_49 = V_13 ;
}
}
} else V_51 = NULL ;
if( V_27 ) {
if( ! ( V_52 = F_37 ( V_27 ) ) ) return NULL ;
for( V_49 = V_52 ; * V_49 ; V_49 ++ ) {
V_13 = * V_49 ;
if( isupper ( V_13 ) ) {
V_13 = tolower ( V_13 ) ;
* V_49 = V_13 ;
}
}
} else V_52 = NULL ;
V_50 = ( V_19 * ) F_38 ( sizeof( V_19 ) ) ;
if( ! V_50 ) return NULL ;
V_50 -> V_48 = V_51 ;
V_50 -> V_27 = V_52 ;
if( ! ( V_50 -> V_53 = F_39 ( V_54 ) ) ) return NULL ;
return V_50 ;
}
static int F_40 ( V_19 * V_50 , char * V_48 , char * V_27 )
{
char * V_51 , * V_52 , * V_49 ;
int V_13 ;
T_3 * V_55 ;
if( V_48 ) {
V_51 = F_37 ( V_48 ) ;
if( ! V_51 ) return 0 ;
for( V_49 = V_51 ; * V_49 ; V_49 ++ ) {
V_13 = * V_49 ;
if( isupper ( V_13 ) ) {
V_13 = tolower ( V_13 ) ;
* V_49 = V_13 ;
}
}
} else V_51 = NULL ;
if( V_27 ) {
V_52 = F_37 ( V_27 ) ;
if( ! V_52 ) return 0 ;
} else V_52 = NULL ;
V_55 = ( T_3 * ) F_38 ( sizeof( T_3 ) ) ;
if( ! V_55 ) return 0 ;
V_55 -> V_56 = V_51 ;
V_55 -> V_30 = V_52 ;
F_41 ( V_50 -> V_53 , V_55 ) ;
return 1 ;
}
static int F_42 ( const V_19 * const * V_57 ,
const V_19 * const * V_58 )
{
return ( strcmp ( ( * V_57 ) -> V_48 , ( * V_58 ) -> V_48 ) ) ;
}
static int V_54 ( const T_3 * const * V_57 ,
const T_3 * const * V_58 )
{
return ( strcmp ( ( * V_57 ) -> V_56 , ( * V_58 ) -> V_56 ) ) ;
}
static T_3 * F_22 ( V_19 * V_22 , char * V_48 )
{
T_3 V_59 ;
int V_60 ;
V_59 . V_56 = V_48 ;
V_60 = F_43 ( V_22 -> V_53 , & V_59 ) ;
if( V_60 < 0 ) return NULL ;
return F_44 ( V_22 -> V_53 , V_60 ) ;
}
static void V_28 ( V_19 * V_22 )
{
if( V_22 -> V_48 ) F_45 ( V_22 -> V_48 ) ;
if( V_22 -> V_27 ) F_45 ( V_22 -> V_27 ) ;
if( V_22 -> V_53 ) F_46 ( V_22 -> V_53 , V_61 ) ;
F_45 ( V_22 ) ;
}
static void V_61 ( T_3 * V_59 )
{
if( V_59 -> V_56 ) F_45 ( V_59 -> V_56 ) ;
if( V_59 -> V_30 ) F_45 ( V_59 -> V_30 ) ;
F_45 ( V_59 ) ;
}
static int F_47 ( char * line , int V_62 , char * V_12 , int V_63 )
{
if( V_62 == - 1 ) V_62 = strlen ( line ) ;
if( V_63 == - 1 ) V_63 = strlen ( V_12 ) ;
if( V_63 + 2 > V_62 ) return 0 ;
if( ! strncmp ( line , L_28 , 2 ) && ! strncmp ( line + 2 , V_12 , V_63 ) ) {
if( ! strncmp ( line + V_63 + 2 , L_28 , 2 ) ) return 2 ;
else return 1 ;
}
return 0 ;
}

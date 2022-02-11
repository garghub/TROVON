static int F_1 ( const char * V_1 )
{
if( * V_1 >= '0' && * V_1 <= '9' ) {
return * V_1 - '0' ;
} else if( * V_1 >= 'A' && * V_1 <= 'F' ) {
return * V_1 - 'A' + 0xA ;
} else if( * V_1 >= 'a' && * V_1 <= 'f' ) {
return * V_1 - 'a' + 0xa ;
} else{
return - 1 ;
}
}
static T_1 F_2 ( const char * V_1 , T_2 * V_2 )
{
int V_3 ;
T_2 V_4 ;
int V_5 ;
V_4 = 0 ;
for( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
V_3 = F_1 ( V_1 ++ ) ;
if( V_3 == - 1 ) {
return FALSE ;
}
V_4 = ( V_4 << 4 ) | V_3 ;
}
* V_2 = V_4 ;
return TRUE ;
}
static T_1 F_3 ( const char * V_1 , T_3 * V_6 )
{
int V_3 ;
T_3 V_4 ;
int V_5 ;
V_4 = 0 ;
for( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
V_3 = F_1 ( V_1 ++ ) ;
if( V_3 == - 1 ) {
return FALSE ;
}
V_4 = ( V_4 << 4 ) | V_3 ;
}
* V_6 = V_4 ;
return TRUE ;
}
T_1
F_4 ( const char * V_7 , T_4 * V_8 )
{
int V_5 ;
int V_9 , V_10 ;
if( * V_7 != '{' ) {
return FALSE ;
}
V_7 ++ ;
if( ! F_2 ( V_7 , & V_8 -> V_11 ) ) {
return FALSE ;
}
V_7 += 8 ;
if( * V_7 != '-' ) {
return FALSE ;
}
V_7 ++ ;
if( ! F_3 ( V_7 , & V_8 -> V_12 ) ) {
return FALSE ;
}
V_7 += 4 ;
if( * V_7 != '-' ) {
return FALSE ;
}
V_7 ++ ;
if( ! F_3 ( V_7 , & V_8 -> V_13 ) ) {
return FALSE ;
}
V_7 += 4 ;
if( * V_7 != '-' ) {
return FALSE ;
}
V_7 ++ ;
for( V_5 = 0 ; V_5 < 2 ; V_5 ++ ) {
V_9 = F_1 ( V_7 ) ;
if( V_9 == - 1 ) {
return FALSE ;
}
V_7 ++ ;
V_10 = F_1 ( V_7 ) ;
if( V_10 == - 1 ) {
return FALSE ;
}
V_7 ++ ;
V_8 -> V_14 [ V_5 ] = ( V_9 << 4 ) | ( V_10 ) ;
}
if( * V_7 != '-' ) {
return FALSE ;
}
V_7 ++ ;
for( V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
V_9 = F_1 ( V_7 ) ;
if( V_9 == - 1 ) {
return FALSE ;
}
V_7 ++ ;
V_10 = F_1 ( V_7 ) ;
if( V_10 == - 1 ) {
return FALSE ;
}
V_7 ++ ;
V_8 -> V_14 [ V_5 + 2 ] = ( V_9 << 4 ) | ( V_10 ) ;
}
if( * V_7 != '}' ) {
return FALSE ;
}
V_7 ++ ;
if( * V_7 != '\0' ) {
return FALSE ;
}
return TRUE ;
}
T_1 F_5 ()
{
T_5 V_15 ;
F_6 ( & V_15 , sizeof( T_5 ) ) ;
V_15 . V_16 = sizeof( T_5 ) ;
if( F_7 ( & V_15 ) ) {
return V_15 . V_17 >= 6 ;
}
return FALSE ;
}
char *
F_8 ( T_6 T_4 * V_8 )
{
T_7 V_18 ;
T_8 V_19 ;
T_9 V_20 [ V_21 + 1 ] ;
T_8 V_22 ;
T_1 V_23 = TRUE ;
T_1 V_24 = FALSE ;
int V_25 ;
char * V_26 ;
V_18 = F_9 ( F_10 ( L_1 ) ) ;
if ( V_18 == NULL ) {
return NULL ;
}
if( F_5 () ) {
typedef T_10 (F_11 * F_12) ( T_6 CONST T_4 * V_27 , T_11 T_12 V_28 );
typedef T_10 (WINAPI *ProcAddr_CIL2A) ( T_6 CONST V_29 * V_28 , F_13 (Length) V_30 V_31 , T_6 V_32 V_33 ) ;
F_12 V_34 = ( F_12 ) F_14 ( V_18 , L_2 ) ;
if( V_34 != NULL ) {
T_13 V_35 = ( T_13 ) F_14 ( V_18 , L_3 ) ;
if( V_35 != NULL ) {
V_29 V_28 ;
V_22 = V_34 ( V_8 , & V_28 ) ;
if( V_22 == V_36 ) {
V_22 = V_35 ( & V_28 , V_20 , V_21 + 1 ) ;
if( V_22 == V_36 ) {
V_24 = TRUE ;
} else{
V_23 = FALSE ;
}
} else{
V_23 = FALSE ;
}
}
}
}
if( V_23 && ! V_24 ) {
typedef T_8 (F_11 * F_15) ( T_6 T_4 * V_27 , T_11 T_14 V_31 , T_15 T_2 * V_37 , T_16 * V_38 , T_16 * V_39 );
F_15 V_40 = NULL ;
V_40 = ( F_15 ) F_14 ( V_18 , L_4 ) ;
if ( V_40 != NULL ) {
T_16 * V_41 = NULL , * V_42 = NULL ;
T_2 V_43 ;
V_43 = sizeof( V_20 ) ;
V_19 = V_40 ( V_8 , V_20 , & V_43 , V_41 , V_42 ) ;
if( V_19 == 0 ) {
V_24 = TRUE ;
}
}
}
F_16 ( V_18 ) ;
if( ! V_24 ) {
return NULL ;
}
V_25 = F_17 ( V_44 , 0 , V_20 , - 1 , NULL , 0 , NULL , NULL ) ;
V_26 = ( char * ) F_18 ( V_25 ) ;
if ( V_26 == NULL ) {
return NULL ;
}
V_25 = F_17 ( V_44 , 0 , V_20 , - 1 , V_26 , V_25 , NULL , NULL ) ;
if( V_25 == 0 ) {
F_19 ( V_26 ) ;
return NULL ;
}
return V_26 ;
}
char *
F_20 ( const char * V_45 )
{
const char * V_7 ;
T_4 V_8 ;
if( strncmp ( L_5 , V_45 , 12 ) == 0 ) {
V_7 = V_45 + 12 ;
} else{
V_7 = V_45 ;
}
if ( ! F_4 ( V_7 , & V_8 ) ) {
return NULL ;
}
return F_8 ( & V_8 ) ;
}

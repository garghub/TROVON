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
#if ( V_15 >= 1800 )
T_5 V_16 ;
T_6 V_17 = 0 ;
int V_18 = V_19 ;
F_6 ( & V_16 , sizeof( T_5 ) ) ;
V_16 . V_20 = sizeof( T_5 ) ;
V_16 . V_21 = 6 ;
F_7 ( V_17 , V_22 , V_18 ) ;
return F_8 ( & V_16 , V_22 , V_17 ) ;
#else
T_7 V_16 ;
F_6 ( & V_16 , sizeof( T_7 ) ) ;
V_16 . V_20 = sizeof( T_7 ) ;
if( F_9 ( & V_16 ) ) {
return V_16 . V_21 >= 6 ;
}
return FALSE ;
#endif
}
char *
F_10 ( T_8 T_4 * V_8 )
{
T_9 V_23 ;
T_10 V_24 ;
T_11 V_25 [ V_26 + 1 ] ;
T_10 V_27 ;
T_1 V_28 = TRUE ;
T_1 V_29 = FALSE ;
int V_30 ;
char * V_31 ;
V_23 = F_11 ( F_12 ( L_1 ) ) ;
if ( V_23 == NULL ) {
return NULL ;
}
if( F_5 () ) {
typedef T_12 (F_13 * F_14) ( T_8 CONST T_4 * V_32 , T_13 T_14 V_33 );
typedef T_12 (WINAPI *ProcAddr_CIL2A) ( T_8 CONST V_34 * V_33 , F_15 (Length) V_35 V_36 , T_8 V_37 V_38 ) ;
F_14 V_39 = ( F_14 ) F_16 ( V_23 , L_2 ) ;
if( V_39 != NULL ) {
T_15 V_40 = ( T_15 ) F_16 ( V_23 , L_3 ) ;
if( V_40 != NULL ) {
V_34 V_33 ;
V_27 = V_39 ( V_8 , & V_33 ) ;
if( V_27 == V_41 ) {
V_27 = V_40 ( & V_33 , V_25 , V_26 + 1 ) ;
if( V_27 == V_41 ) {
V_29 = TRUE ;
} else{
V_28 = FALSE ;
}
} else{
V_28 = FALSE ;
}
}
}
}
if( V_28 && ! V_29 ) {
typedef T_10 (F_13 * F_17) ( T_8 T_4 * V_32 , T_13 T_16 V_36 , T_17 T_2 * V_42 , T_18 * V_43 , T_18 * V_44 );
F_17 V_45 = NULL ;
V_45 = ( F_17 ) F_16 ( V_23 , L_4 ) ;
if ( V_45 != NULL ) {
T_18 * V_46 = NULL , * V_47 = NULL ;
T_2 V_48 ;
V_48 = sizeof( V_25 ) ;
V_24 = V_45 ( V_8 , V_25 , & V_48 , V_46 , V_47 ) ;
if( V_24 == 0 ) {
V_29 = TRUE ;
}
}
}
F_18 ( V_23 ) ;
if( ! V_29 ) {
return NULL ;
}
V_30 = F_19 ( V_49 , 0 , V_25 , - 1 , NULL , 0 , NULL , NULL ) ;
V_31 = ( char * ) F_20 ( V_30 ) ;
if ( V_31 == NULL ) {
return NULL ;
}
V_30 = F_19 ( V_49 , 0 , V_25 , - 1 , V_31 , V_30 , NULL , NULL ) ;
if( V_30 == 0 ) {
F_21 ( V_31 ) ;
return NULL ;
}
return V_31 ;
}
char *
F_22 ( const char * V_50 )
{
const char * V_7 ;
T_4 V_8 ;
if( strncmp ( L_5 , V_50 , 12 ) == 0 ) {
V_7 = V_50 + 12 ;
} else{
V_7 = V_50 ;
}
if ( ! F_4 ( V_7 , & V_8 ) ) {
return NULL ;
}
return F_10 ( & V_8 ) ;
}

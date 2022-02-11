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
char V_10 [ 33 ] , V_11 ;
int V_12 ;
char * V_13 , * V_14 , * V_15 = NULL ;
if ( V_9 & V_16 )
V_13 = L_1 ;
else
V_13 = L_2 ;
if ( V_9 & V_17 )
V_14 = L_3 ;
else
V_14 = L_4 ;
if( ( V_9 & V_18 ) && V_8 ) {
F_13 ( ( unsigned char * ) V_10 , 32 ) ;
for( V_12 = 0 ; V_12 < 32 ; V_12 ++ ) {
V_11 = V_10 [ V_12 ] & 0xf ;
if( V_11 < 10 ) V_11 += '0' ;
else V_11 += 'A' - 10 ;
V_10 [ V_12 ] = V_11 ;
}
V_10 [ 32 ] = 0 ;
F_14 ( V_1 , L_5 , V_14 ) ;
F_14 ( V_1 , L_6 ) ;
F_14 ( V_1 , L_7 , V_13 ) ;
F_14 ( V_1 , L_8 ,
V_10 , V_14 , V_14 ) ;
F_14 ( V_1 , L_9 ,
V_14 , V_14 ) ;
F_14 ( V_1 , L_10 , V_10 , V_14 ) ;
F_15 ( V_1 , V_8 , V_2 , V_9 ) ;
F_14 ( V_1 , L_11 , V_14 , V_10 , V_14 ) ;
F_14 ( V_1 , L_12 , V_13 ) ;
F_14 ( V_1 , L_13 , V_14 ) ;
F_14 ( V_1 , L_14 ,
V_14 ) ;
F_14 ( V_1 , L_15 ) ;
F_14 ( V_1 , L_16 ,
V_14 , V_14 ) ;
F_1 ( V_1 , V_2 ) ;
F_14 ( V_1 , L_17 , V_14 , V_10 ,
V_14 , V_14 ) ;
return 1 ;
}
if ( F_16 ( V_2 ) )
V_15 = L_18 ;
else if ( F_17 ( V_2 ) )
{
F_18 ( V_19 ) * V_20 ;
V_20 = F_19 ( V_2 ) ;
if ( F_20 ( V_20 ) > 0 )
V_15 = L_19 ;
else
V_15 = L_20 ;
}
F_14 ( V_1 , L_5 , V_14 ) ;
F_14 ( V_1 , L_15 ) ;
F_14 ( V_1 , L_21 , V_14 ) ;
F_14 ( V_1 , L_22 , V_13 ) ;
if ( V_15 )
F_14 ( V_1 , L_23 , V_15 ) ;
F_14 ( V_1 , L_24 , V_14 ) ;
F_14 ( V_1 , L_25 ,
V_14 , V_14 ) ;
F_1 ( V_1 , V_2 ) ;
F_14 ( V_1 , L_26 , V_14 ) ;
return 1 ;
}
static int F_15 ( T_1 * V_21 , T_1 * V_8 , T_2 * V_2 , int V_9 )
{
T_1 * V_22 , * V_23 ;
if ( ! ( V_9 & V_24 ) )
{
F_21 ( V_8 , V_21 , V_9 ) ;
return 1 ;
}
V_23 = F_22 ( V_2 , V_21 ) ;
F_21 ( V_8 , V_23 , V_9 ) ;
F_23 ( V_2 , 1 ) ;
F_24 ( V_2 , V_23 ) ;
while ( V_23 != V_21 )
{
V_22 = F_8 ( V_23 ) ;
F_9 ( V_23 ) ;
V_23 = V_22 ;
}
return 1 ;
}
T_2 * F_25 ( T_1 * V_1 , T_1 * * V_25 )
{
T_1 * V_26 ;
F_18 ( V_27 ) * V_28 = NULL ;
F_18 ( T_1 ) * V_29 = NULL ;
V_27 * V_30 ;
T_3 * V_31 ;
T_2 * V_2 ;
int V_32 ;
if( V_25 ) * V_25 = NULL ;
if ( ! ( V_28 = F_26 ( V_1 ) ) ) {
F_4 ( V_33 , V_34 ) ;
return NULL ;
}
if( ! ( V_30 = F_27 ( V_28 , L_27 ) ) || ! V_30 -> V_35 ) {
F_28 ( V_28 , V_36 ) ;
F_4 ( V_33 , V_37 ) ;
return NULL ;
}
if( ! strcmp ( V_30 -> V_35 , L_28 ) ) {
V_31 = F_29 ( V_30 , L_29 ) ;
if( ! V_31 || ! V_31 -> V_38 ) {
F_28 ( V_28 , V_36 ) ;
F_4 ( V_33 , V_39 ) ;
return NULL ;
}
V_32 = F_30 ( V_1 , V_31 -> V_38 , & V_29 ) ;
F_28 ( V_28 , V_36 ) ;
if( ! V_32 || ( F_31 ( V_29 ) != 2 ) ) {
F_4 ( V_33 , V_40 ) ;
F_32 ( V_29 , V_41 ) ;
return NULL ;
}
V_26 = F_33 ( V_29 , 1 ) ;
if ( ! ( V_28 = F_26 ( V_26 ) ) ) {
F_4 ( V_33 , V_42 ) ;
F_32 ( V_29 , V_41 ) ;
return NULL ;
}
if( ! ( V_30 = F_27 ( V_28 , L_27 ) ) ||
! V_30 -> V_35 ) {
F_28 ( V_28 , V_36 ) ;
F_4 ( V_33 , V_43 ) ;
return NULL ;
}
if( strcmp ( V_30 -> V_35 , L_30 ) &&
strcmp ( V_30 -> V_35 , L_31 ) ) {
F_28 ( V_28 , V_36 ) ;
F_4 ( V_33 , V_44 ) ;
F_34 ( 2 , L_32 , V_30 -> V_35 ) ;
F_32 ( V_29 , V_41 ) ;
return NULL ;
}
F_28 ( V_28 , V_36 ) ;
if( ! ( V_2 = F_10 ( V_26 ) ) ) {
F_4 ( V_33 , V_45 ) ;
F_32 ( V_29 , V_41 ) ;
return NULL ;
}
if( V_25 ) {
* V_25 = F_33 ( V_29 , 0 ) ;
F_9 ( V_26 ) ;
F_35 ( V_29 ) ;
} else F_32 ( V_29 , V_41 ) ;
return V_2 ;
}
if ( strcmp ( V_30 -> V_35 , L_33 ) &&
strcmp ( V_30 -> V_35 , L_34 ) ) {
F_4 ( V_33 , V_46 ) ;
F_34 ( 2 , L_32 , V_30 -> V_35 ) ;
F_28 ( V_28 , V_36 ) ;
return NULL ;
}
F_28 ( V_28 , V_36 ) ;
if( ! ( V_2 = F_10 ( V_1 ) ) ) {
F_4 ( V_33 , V_47 ) ;
return NULL ;
}
return V_2 ;
}
int F_21 ( T_1 * V_48 , T_1 * V_21 , int V_9 )
{
char V_49 ;
int V_50 ;
char V_51 [ V_52 ] ;
if( V_9 & V_53 ) {
while( ( V_50 = F_36 ( V_48 , V_51 , V_52 ) ) > 0 )
F_37 ( V_21 , V_51 , V_50 ) ;
return 1 ;
}
if( V_9 & V_54 )
F_14 ( V_21 , L_35 ) ;
while ( ( V_50 = F_38 ( V_48 , V_51 , V_52 ) ) > 0 ) {
V_49 = F_39 ( V_51 , & V_50 ) ;
if ( V_50 )
F_37 ( V_21 , V_51 , V_50 ) ;
if( V_49 ) F_37 ( V_21 , L_3 , 2 ) ;
}
return 1 ;
}
int F_40 ( T_1 * V_48 , T_1 * V_21 )
{
char V_55 [ 4096 ] ;
int V_50 ;
F_18 ( V_27 ) * V_28 ;
V_27 * V_30 ;
if ( ! ( V_28 = F_26 ( V_48 ) ) ) {
F_4 ( V_56 , V_34 ) ;
return 0 ;
}
if( ! ( V_30 = F_27 ( V_28 , L_27 ) ) || ! V_30 -> V_35 ) {
F_4 ( V_56 , V_57 ) ;
F_28 ( V_28 , V_36 ) ;
return 0 ;
}
if ( strcmp ( V_30 -> V_35 , L_36 ) ) {
F_4 ( V_56 , V_46 ) ;
F_34 ( 2 , L_32 , V_30 -> V_35 ) ;
F_28 ( V_28 , V_36 ) ;
return 0 ;
}
F_28 ( V_28 , V_36 ) ;
while ( ( V_50 = F_36 ( V_48 , V_55 , sizeof( V_55 ) ) ) > 0 )
F_37 ( V_21 , V_55 , V_50 ) ;
return 1 ;
}
char * F_41 ( char * V_58 )
{
return F_42 ( F_43 ( V_58 ) ) ;
}
static char * F_43 ( char * V_58 )
{
char * V_59 , V_11 ;
for( V_59 = V_58 ; ( V_11 = * V_59 ) ; V_59 ++ ) {
if( V_11 == '"' ) {
if( V_59 [ 1 ] ) return V_59 + 1 ;
return NULL ;
}
if( ! isspace ( ( unsigned char ) V_11 ) ) return V_59 ;
}
return NULL ;
}
static char * F_42 ( char * V_58 )
{
char * V_59 , V_11 ;
if( ! V_58 ) return NULL ;
for( V_59 = V_58 + strlen ( V_58 ) - 1 ; V_59 >= V_58 ; V_59 -- ) {
V_11 = * V_59 ;
if( V_11 == '"' ) {
if( V_59 - 1 == V_58 ) return NULL ;
* V_59 = 0 ;
return V_58 ;
}
if( isspace ( ( unsigned char ) V_11 ) ) * V_59 = 0 ;
else return V_58 ;
}
return NULL ;
}
static V_27 * F_44 ( char * V_58 , char * V_35 )
{
V_27 * V_60 ;
char * V_61 , * V_62 , * V_59 ;
int V_11 ;
if( V_58 ) {
if( ! ( V_61 = F_45 ( V_58 ) ) ) return NULL ;
for( V_59 = V_61 ; * V_59 ; V_59 ++ ) {
V_11 = * V_59 ;
if( isupper ( V_11 ) ) {
V_11 = tolower ( V_11 ) ;
* V_59 = V_11 ;
}
}
} else V_61 = NULL ;
if( V_35 ) {
if( ! ( V_62 = F_45 ( V_35 ) ) ) return NULL ;
for( V_59 = V_62 ; * V_59 ; V_59 ++ ) {
V_11 = * V_59 ;
if( isupper ( V_11 ) ) {
V_11 = tolower ( V_11 ) ;
* V_59 = V_11 ;
}
}
} else V_62 = NULL ;
V_60 = ( V_27 * ) F_46 ( sizeof( V_27 ) ) ;
if( ! V_60 ) return NULL ;
V_60 -> V_58 = V_61 ;
V_60 -> V_35 = V_62 ;
if( ! ( V_60 -> V_63 = F_47 ( V_64 ) ) ) return NULL ;
return V_60 ;
}
static int F_48 ( V_27 * V_60 , char * V_58 , char * V_35 )
{
char * V_61 , * V_62 , * V_59 ;
int V_11 ;
T_3 * V_65 ;
if( V_58 ) {
V_61 = F_45 ( V_58 ) ;
if( ! V_61 ) return 0 ;
for( V_59 = V_61 ; * V_59 ; V_59 ++ ) {
V_11 = * V_59 ;
if( isupper ( V_11 ) ) {
V_11 = tolower ( V_11 ) ;
* V_59 = V_11 ;
}
}
} else V_61 = NULL ;
if( V_35 ) {
V_62 = F_45 ( V_35 ) ;
if( ! V_62 ) return 0 ;
} else V_62 = NULL ;
V_65 = ( T_3 * ) F_46 ( sizeof( T_3 ) ) ;
if( ! V_65 ) return 0 ;
V_65 -> V_66 = V_61 ;
V_65 -> V_38 = V_62 ;
F_49 ( V_60 -> V_63 , V_65 ) ;
return 1 ;
}
static int F_50 ( const V_27 * const * V_67 ,
const V_27 * const * V_68 )
{
return ( strcmp ( ( * V_67 ) -> V_58 , ( * V_68 ) -> V_58 ) ) ;
}
static int V_64 ( const T_3 * const * V_67 ,
const T_3 * const * V_68 )
{
return ( strcmp ( ( * V_67 ) -> V_66 , ( * V_68 ) -> V_66 ) ) ;
}
static T_3 * F_29 ( V_27 * V_30 , char * V_58 )
{
T_3 V_69 ;
int V_70 ;
V_69 . V_66 = V_58 ;
V_70 = F_51 ( V_30 -> V_63 , & V_69 ) ;
if( V_70 < 0 ) return NULL ;
return F_52 ( V_30 -> V_63 , V_70 ) ;
}
static void V_36 ( V_27 * V_30 )
{
if( V_30 -> V_58 ) F_53 ( V_30 -> V_58 ) ;
if( V_30 -> V_35 ) F_53 ( V_30 -> V_35 ) ;
if( V_30 -> V_63 ) F_54 ( V_30 -> V_63 , V_71 ) ;
F_53 ( V_30 ) ;
}
static void V_71 ( T_3 * V_69 )
{
if( V_69 -> V_66 ) F_53 ( V_69 -> V_66 ) ;
if( V_69 -> V_38 ) F_53 ( V_69 -> V_38 ) ;
F_53 ( V_69 ) ;
}
static int F_55 ( char * line , int V_72 , char * V_10 , int V_73 )
{
if( V_72 == - 1 ) V_72 = strlen ( line ) ;
if( V_73 == - 1 ) V_73 = strlen ( V_10 ) ;
if( V_73 + 2 > V_72 ) return 0 ;
if( ! strncmp ( line , L_37 , 2 ) && ! strncmp ( line + 2 , V_10 , V_73 ) ) {
if( ! strncmp ( line + V_73 + 2 , L_37 , 2 ) ) return 2 ;
else return 1 ;
}
return 0 ;
}
static int F_39 ( char * V_51 , int * V_74 )
{
int V_50 = * V_74 ;
char * V_59 , V_11 ;
int V_75 = 0 ;
V_59 = V_51 + V_50 - 1 ;
for ( V_59 = V_51 + V_50 - 1 ; V_50 > 0 ; V_50 -- , V_59 -- )
{
V_11 = * V_59 ;
if ( V_11 == '\n' )
V_75 = 1 ;
else if ( V_11 != '\r' )
break;
}
* V_74 = V_50 ;
return V_75 ;
}

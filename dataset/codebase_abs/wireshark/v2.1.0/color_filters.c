T_1 *
F_1 ( const T_2 * V_1 ,
const T_2 * V_2 ,
T_3 * V_3 ,
T_3 * V_4 ,
T_4 V_5 )
{
T_1 * V_6 ;
V_6 = ( T_1 * ) F_2 ( sizeof ( T_1 ) ) ;
V_6 -> V_7 = F_3 ( V_1 ) ;
V_6 -> V_8 = F_3 ( V_2 ) ;
V_6 -> V_3 = * V_3 ;
V_6 -> V_4 = * V_4 ;
V_6 -> V_5 = V_5 ;
return V_6 ;
}
static void
F_4 ( T_5 * * V_9 )
{
T_2 * V_1 = NULL ;
T_6 V_10 ;
T_2 * * V_11 ;
T_2 * * V_12 ;
T_7 V_13 ;
T_3 V_3 , V_4 ;
T_1 * V_6 ;
F_5 ( strlen ( V_14 . V_15 ) == 69 ) ;
F_5 ( strlen ( V_14 . V_16 ) == 69 ) ;
V_12 = F_6 ( V_14 . V_15 , L_1 , - 1 ) ;
V_11 = F_6 ( V_14 . V_16 , L_1 , - 1 ) ;
for ( V_10 = 1 ; V_10 <= 10 ; V_10 ++ ) {
V_1 = F_7 ( L_2 , V_17 , V_10 ) ;
V_13 = strtoul ( V_12 [ V_10 - 1 ] , NULL , 16 ) ;
V_4 . V_18 = F_8 ( V_13 ) ;
V_4 . V_19 = F_9 ( V_13 ) ;
V_4 . V_20 = F_10 ( V_13 ) ;
V_13 = strtoul ( V_11 [ V_10 - 1 ] , NULL , 16 ) ;
V_3 . V_18 = F_8 ( V_13 ) ;
V_3 . V_19 = F_9 ( V_13 ) ;
V_3 . V_20 = F_10 ( V_13 ) ;
V_6 = F_1 ( V_1 , NULL , & V_3 , & V_4 , TRUE ) ;
V_6 -> V_8 = F_3 ( L_3 ) ;
* V_9 = F_11 ( * V_9 , V_6 ) ;
F_12 ( V_1 ) ;
}
F_13 ( V_12 ) ;
F_13 ( V_11 ) ;
return;
}
static T_8
F_14 ( T_9 V_21 , T_9 V_22 )
{
const T_1 * V_6 = ( const T_1 * ) V_21 ;
const T_2 * V_1 = ( const T_2 * ) V_22 ;
return strcmp ( V_6 -> V_7 , V_1 ) ;
}
T_4
F_15 ( T_10 V_23 , const T_2 * V_24 , T_4 V_5 , T_2 * * V_25 )
{
T_2 * V_1 = NULL ;
const T_2 * V_26 = NULL ;
T_5 * V_9 ;
T_1 * V_6 ;
T_11 * V_27 ;
T_10 V_10 ;
T_2 * V_28 = NULL ;
for ( V_10 = 1 ; V_10 <= 10 ; V_10 ++ ) {
if( V_10 != V_23 && V_24 == NULL )
continue;
V_1 = F_7 ( L_2 , V_17 , V_10 ) ;
V_9 = F_16 ( V_29 , V_1 , F_14 ) ;
V_6 = ( T_1 * ) V_9 -> V_30 ;
if( V_6 && ( ( V_10 == V_23 ) || ( ! strcmp ( V_24 , V_6 -> V_8 ) ) ) ) {
V_26 = ( ( V_24 == NULL ) || ( V_10 != V_23 ) ) ? L_3 : V_24 ;
if ( ! F_17 ( V_26 , & V_27 , & V_28 ) ) {
* V_25 = F_7 ( L_4 , V_1 , V_24 , V_28 ) ;
F_12 ( V_28 ) ;
return FALSE ;
} else {
if ( V_6 -> V_8 != NULL )
F_12 ( V_6 -> V_8 ) ;
if ( V_6 -> V_31 != NULL )
F_18 ( V_6 -> V_31 ) ;
V_6 -> V_8 = F_3 ( V_26 ) ;
V_6 -> V_31 = V_27 ;
V_6 -> V_5 = ( ( V_10 != V_23 ) ? TRUE : V_5 ) ;
if( V_24 )
V_32 = TRUE ;
}
}
F_12 ( V_1 ) ;
}
return TRUE ;
}
const T_1 *
F_19 ( T_10 V_33 ) {
T_2 * V_1 ;
T_1 * V_6 = NULL ;
T_5 * V_9 ;
V_1 = F_7 ( L_2 , V_17 , V_33 ) ;
V_9 = F_16 ( V_29 , V_1 , F_14 ) ;
if ( V_9 ) {
V_6 = ( T_1 * ) V_9 -> V_30 ;
}
F_12 ( V_1 ) ;
return V_6 ;
}
T_4
F_20 ( T_2 * * V_25 )
{
T_10 V_10 ;
for ( V_10 = 1 ; V_10 <= 10 ; V_10 ++ ) {
if ( ! F_15 ( V_10 , NULL , TRUE , V_25 ) )
return FALSE ;
}
V_32 = FALSE ;
return TRUE ;
}
void
F_21 ( T_1 * V_6 )
{
if ( V_6 -> V_7 != NULL )
F_12 ( V_6 -> V_7 ) ;
if ( V_6 -> V_8 != NULL )
F_12 ( V_6 -> V_8 ) ;
if ( V_6 -> V_31 != NULL )
F_18 ( V_6 -> V_31 ) ;
F_12 ( V_6 ) ;
}
static void
F_22 ( T_12 V_34 , T_12 T_13 V_35 )
{
T_1 * V_6 = ( T_1 * ) V_34 ;
F_21 ( V_6 ) ;
}
void
F_23 ( T_5 * * V_9 )
{
F_24 ( * V_9 , F_22 , NULL ) ;
F_25 ( * V_9 ) ;
* V_9 = NULL ;
}
static T_1 *
F_26 ( T_1 * V_6 )
{
T_1 * V_36 ;
V_36 = ( T_1 * ) F_27 ( sizeof ( T_1 ) ) ;
V_36 -> V_7 = F_3 ( V_6 -> V_7 ) ;
V_36 -> V_8 = F_3 ( V_6 -> V_8 ) ;
V_36 -> V_3 = V_6 -> V_3 ;
V_36 -> V_4 = V_6 -> V_4 ;
V_36 -> V_5 = V_6 -> V_5 ;
V_36 -> V_31 = NULL ;
V_36 -> V_37 = NULL ;
V_36 -> V_38 = FALSE ;
return V_36 ;
}
static void
F_28 ( T_12 V_34 , T_12 V_39 )
{
T_5 * * V_9 = ( T_5 * * ) V_39 ;
T_1 * V_36 ;
V_36 = F_26 ( ( T_1 * ) V_34 ) ;
* V_9 = F_11 ( * V_9 , V_36 ) ;
}
static T_5 *
F_29 ( T_5 * V_9 )
{
T_5 * V_40 = NULL ;
F_24 ( V_9 , F_28 , & V_40 ) ;
return V_40 ;
}
T_4
F_30 ( T_2 * * V_25 , T_14 V_41 )
{
F_23 ( & V_29 ) ;
F_4 ( & V_29 ) ;
if ( ! F_31 ( & V_29 , V_25 , V_41 ) ) {
T_2 * V_28 = NULL ;
if ( ! F_32 ( & V_29 , & V_28 , V_41 ) ) {
F_12 ( V_28 ) ;
}
return ( * V_25 == NULL ) ;
}
return TRUE ;
}
T_4
F_33 ( T_2 * * V_25 , T_14 V_41 )
{
V_42 = F_34 ( V_42 , V_29 ) ;
V_29 = NULL ;
F_4 ( & V_29 ) ;
if ( ! F_31 ( & V_29 , V_25 , V_41 ) ) {
T_2 * V_28 = NULL ;
if ( ! F_32 ( & V_29 , & V_28 , V_41 ) ) {
F_12 ( V_28 ) ;
}
return ( * V_25 == NULL ) ;
}
return TRUE ;
}
void
F_35 ( void )
{
F_23 ( & V_42 ) ;
}
static void
F_36 ( T_12 V_34 , T_12 V_43 )
{
T_15 * V_44 = ( T_15 * ) V_43 ;
T_1 * V_36 = F_26 ( ( T_1 * ) V_34 ) ;
V_44 -> V_41 ( V_36 , V_44 -> V_43 ) ;
}
void
F_37 ( T_12 V_43 , T_14 V_41 )
{
T_15 V_44 ;
V_44 . V_43 = V_43 ;
V_44 . V_41 = V_41 ;
F_24 ( V_29 , F_36 , & V_44 ) ;
}
static void
F_38 ( T_12 V_34 , T_12 V_45 )
{
T_1 * V_6 = ( T_1 * ) V_34 ;
T_2 * * V_25 = ( T_2 * * ) V_45 ;
T_2 * V_28 = NULL ;
F_5 ( V_6 -> V_31 == NULL ) ;
if ( ! F_17 ( V_6 -> V_8 , & V_6 -> V_31 , & V_28 ) ) {
* V_25 = F_7 ( L_4 ,
V_6 -> V_7 , V_6 -> V_8 , V_28 ) ;
F_12 ( V_28 ) ;
}
}
static void
F_39 ( T_12 V_34 , T_12 V_45 )
{
T_1 * V_6 = ( T_1 * ) V_34 ;
T_2 * * V_25 = ( T_2 * * ) V_45 ;
T_2 * V_28 ;
F_5 ( V_6 -> V_31 == NULL ) ;
if ( ! F_17 ( V_6 -> V_8 , & V_6 -> V_31 , & V_28 ) ) {
* V_25 = F_7 ( L_5 ,
V_6 -> V_7 , V_6 -> V_8 , V_28 ) ;
F_12 ( V_28 ) ;
V_46 = F_40 ( V_46 , V_6 ) ;
F_21 ( V_6 ) ;
}
}
T_4
F_41 ( T_5 * V_47 , T_5 * V_48 , T_2 * * V_25 )
{
T_4 V_49 = TRUE ;
* V_25 = NULL ;
V_42 = F_34 ( V_42 , V_29 ) ;
V_29 = NULL ;
V_46 = NULL ;
V_46 = F_29 ( V_47 ) ;
V_46 = F_34 ( V_46 ,
F_29 ( V_48 ) ) ;
F_24 ( V_46 , F_39 , V_25 ) ;
if ( * V_25 != NULL ) {
V_49 = FALSE ;
}
V_29 = F_29 ( V_46 ) ;
F_24 ( V_29 , F_38 , V_25 ) ;
if ( * V_25 != NULL ) {
V_49 = FALSE ;
}
return V_49 ;
}
T_4
F_42 ( void )
{
return V_29 != NULL && V_50 ;
}
T_4
F_43 ( void )
{
return V_32 ;
}
static void
F_44 ( T_12 V_30 , T_12 V_43 )
{
T_1 * V_6 = ( T_1 * ) V_30 ;
T_16 * V_51 = ( T_16 * ) V_43 ;
if ( V_6 -> V_31 != NULL )
F_45 ( V_51 , V_6 -> V_31 ) ;
}
void
F_46 ( T_16 * V_51 )
{
if ( F_42 () )
F_24 ( V_29 , F_44 , V_51 ) ;
}
const T_1 *
F_47 ( T_16 * V_51 )
{
T_5 * V_52 ;
T_1 * V_6 ;
if ( ( V_51 -> V_53 != NULL ) && ( F_42 () ) ) {
V_52 = V_29 ;
while( V_52 != NULL ) {
V_6 = ( T_1 * ) V_52 -> V_30 ;
if ( ( ! V_6 -> V_5 ) &&
( V_6 -> V_31 != NULL ) &&
F_48 ( V_6 -> V_31 , V_51 ) ) {
return V_6 ;
}
V_52 = F_49 ( V_52 ) ;
}
}
return NULL ;
}
static int
F_50 ( T_17 * V_54 , T_12 V_43 , T_14 V_41 )
{
#define F_51 128
T_2 * V_1 = NULL ;
T_2 * V_55 = NULL ;
T_6 V_56 = F_51 ;
T_6 V_57 = F_51 ;
T_6 V_10 = 0 ;
int V_58 ;
T_18 V_59 , V_60 , V_61 , V_62 , V_63 , V_64 ;
T_4 V_5 = FALSE ;
T_4 V_65 = FALSE ;
int V_49 = 0 ;
V_1 = ( T_2 * ) F_27 ( V_56 + 1 ) ;
V_55 = ( T_2 * ) F_27 ( V_57 + 1 ) ;
while ( 1 ) {
if ( V_65 ) {
do {
V_58 = getc ( V_54 ) ;
} while ( V_58 != V_66 && V_58 != '\n' );
if ( V_58 == V_66 )
break;
V_5 = FALSE ;
V_65 = FALSE ;
}
while ( ( V_58 = getc ( V_54 ) ) != V_66 && F_52 ( V_58 ) ) {
if ( V_58 == '\n' ) {
continue;
}
}
if ( V_58 == V_66 )
break;
if ( V_58 == '!' ) {
V_5 = TRUE ;
continue;
}
if ( V_58 != '@' ) {
V_65 = TRUE ;
continue;
}
V_10 = 0 ;
while ( 1 ) {
V_58 = getc ( V_54 ) ;
if ( V_58 == V_66 || V_58 == '@' )
break;
if ( V_10 >= V_56 ) {
V_56 *= 2 ;
V_1 = ( T_2 * ) F_53 ( V_1 , V_56 + 1 ) ;
}
V_1 [ V_10 ++ ] = V_58 ;
}
V_1 [ V_10 ] = '\0' ;
if ( V_58 == V_66 ) {
break;
} else if ( V_10 == 0 ) {
V_65 = TRUE ;
continue;
}
V_10 = 0 ;
while ( 1 ) {
V_58 = getc ( V_54 ) ;
if ( V_58 == V_66 || V_58 == '@' )
break;
if ( V_10 >= V_57 ) {
V_57 *= 2 ;
V_55 = ( T_2 * ) F_53 ( V_55 , V_57 + 1 ) ;
}
V_55 [ V_10 ++ ] = V_58 ;
}
V_55 [ V_10 ] = '\0' ;
if ( V_58 == V_66 ) {
break;
} else if ( V_10 == 0 ) {
V_65 = TRUE ;
continue;
}
if ( fscanf ( V_54 , L_6 ,
& V_62 , & V_63 , & V_64 , & V_59 , & V_60 , & V_61 ) == 6 ) {
T_3 V_3 , V_4 ;
T_1 * V_6 ;
T_11 * V_67 ;
T_2 * V_28 = NULL ;
if ( ! F_17 ( V_55 , & V_67 , & V_28 ) ) {
F_54 ( L_7 ,
V_1 , V_28 ) ;
F_12 ( V_28 ) ;
V_14 . V_68 = TRUE ;
V_65 = TRUE ;
continue;
}
V_4 . V_18 = V_59 ;
V_4 . V_19 = V_60 ;
V_4 . V_20 = V_61 ;
V_3 . V_18 = V_62 ;
V_3 . V_19 = V_63 ;
V_3 . V_20 = V_64 ;
V_6 = F_1 ( V_1 , V_55 , & V_3 ,
& V_4 , V_5 ) ;
if( V_43 == & V_29 ) {
T_5 * * V_9 = ( T_5 * * ) V_43 ;
V_6 -> V_31 = V_67 ;
* V_9 = F_11 ( * V_9 , V_6 ) ;
} else {
F_18 ( V_67 ) ;
V_41 ( V_6 , V_43 ) ;
}
}
V_65 = TRUE ;
}
if ( ferror ( V_54 ) )
V_49 = V_69 ;
F_12 ( V_1 ) ;
F_12 ( V_55 ) ;
return V_49 ;
}
static T_4
F_31 ( T_5 * * V_9 , T_2 * * V_25 , T_14 V_41 )
{
T_2 * V_70 ;
T_17 * V_54 ;
int V_49 ;
V_70 = F_55 ( L_8 , TRUE ) ;
if ( ( V_54 = F_56 ( V_70 , L_9 ) ) == NULL ) {
if ( V_69 != V_71 ) {
* V_25 = F_7 ( L_10 , V_70 ,
F_57 ( V_69 ) ) ;
}
F_12 ( V_70 ) ;
return FALSE ;
}
F_12 ( V_70 ) ;
V_70 = NULL ;
V_49 = F_50 ( V_54 , V_9 , V_41 ) ;
if ( V_49 != 0 ) {
* V_25 = F_7 ( L_11 ,
V_70 , F_57 ( V_69 ) ) ;
fclose ( V_54 ) ;
return FALSE ;
}
fclose ( V_54 ) ;
return TRUE ;
}
T_4
F_32 ( T_12 V_43 , T_2 * * V_25 , T_14 V_41 )
{
T_2 * V_70 ;
T_17 * V_54 ;
int V_49 ;
V_70 = F_58 ( L_8 ) ;
if ( ( V_54 = F_56 ( V_70 , L_9 ) ) == NULL ) {
if ( V_69 != V_71 ) {
* V_25 = F_7 ( L_12 , V_70 ,
F_57 ( V_69 ) ) ;
}
F_12 ( V_70 ) ;
return FALSE ;
}
F_12 ( V_70 ) ;
V_70 = NULL ;
V_49 = F_50 ( V_54 , V_43 , V_41 ) ;
if ( V_49 != 0 ) {
* V_25 = F_7 ( L_13 ,
V_70 , F_57 ( V_69 ) ) ;
fclose ( V_54 ) ;
return FALSE ;
}
fclose ( V_54 ) ;
return TRUE ;
}
T_4
F_59 ( const T_2 * V_70 , T_12 V_43 , T_2 * * V_25 , T_14 V_41 )
{
T_17 * V_54 ;
int V_49 ;
if ( ( V_54 = F_56 ( V_70 , L_9 ) ) == NULL ) {
* V_25 = F_7 ( L_14 ,
V_70 , F_57 ( V_69 ) ) ;
return FALSE ;
}
V_49 = F_50 ( V_54 , V_43 , V_41 ) ;
if ( V_49 != 0 ) {
* V_25 = F_7 ( L_11 ,
V_70 , F_57 ( V_69 ) ) ;
fclose ( V_54 ) ;
return FALSE ;
}
fclose ( V_54 ) ;
return TRUE ;
}
static void
F_60 ( T_12 V_34 , T_12 V_72 )
{
struct V_73 * V_30 = (struct V_73 * ) V_72 ;
T_1 * V_6 = ( T_1 * ) V_34 ;
T_17 * V_54 = V_30 -> V_54 ;
if ( ( V_6 -> V_38 || ! V_30 -> V_74 ) &&
( strstr ( V_6 -> V_7 , V_17 ) == NULL ) ) {
fprintf ( V_54 , L_15 ,
V_6 -> V_5 ? L_16 : L_17 ,
V_6 -> V_7 ,
V_6 -> V_8 ,
V_6 -> V_3 . V_18 ,
V_6 -> V_3 . V_19 ,
V_6 -> V_3 . V_20 ,
V_6 -> V_4 . V_18 ,
V_6 -> V_4 . V_19 ,
V_6 -> V_4 . V_20 ) ;
}
}
static T_4
F_61 ( T_5 * V_9 , T_17 * V_54 , T_4 V_74 )
{
struct V_73 V_30 ;
V_30 . V_54 = V_54 ;
V_30 . V_74 = V_74 ;
fprintf ( V_54 , L_18 ) ;
F_24 ( V_9 , F_60 , & V_30 ) ;
return TRUE ;
}
T_4
F_62 ( T_5 * V_9 , T_2 * * V_25 )
{
T_2 * V_75 ;
T_2 * V_70 ;
T_17 * V_54 ;
if ( F_63 ( & V_75 ) == - 1 ) {
* V_25 = F_7 ( L_19 ,
V_75 , F_57 ( V_69 ) ) ;
F_12 ( V_75 ) ;
return FALSE ;
}
V_70 = F_55 ( L_8 , TRUE ) ;
if ( ( V_54 = F_56 ( V_70 , L_20 ) ) == NULL ) {
* V_25 = F_7 ( L_21 ,
V_70 , F_57 ( V_69 ) ) ;
F_12 ( V_70 ) ;
return FALSE ;
}
F_12 ( V_70 ) ;
F_61 ( V_9 , V_54 , FALSE ) ;
fclose ( V_54 ) ;
return TRUE ;
}
T_4
F_64 ( const T_2 * V_70 , T_5 * V_9 , T_4 V_76 , T_2 * * V_25 )
{
T_17 * V_54 ;
if ( ( V_54 = F_56 ( V_70 , L_20 ) ) == NULL ) {
* V_25 = F_7 ( L_21 ,
V_70 , F_57 ( V_69 ) ) ;
return FALSE ;
}
F_61 ( V_9 , V_54 , V_76 ) ;
fclose ( V_54 ) ;
return TRUE ;
}

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
static T_4
F_30 ( T_2 * * V_25 , T_14 V_41 )
{
T_2 * V_42 ;
T_15 * V_43 ;
int V_44 ;
F_4 ( & V_29 ) ;
V_42 = F_31 ( L_5 , TRUE ) ;
if ( ( V_43 = F_32 ( V_42 , L_6 ) ) == NULL ) {
if ( V_45 != V_46 ) {
* V_25 = F_7 ( L_7 , V_42 ,
F_33 ( V_45 ) ) ;
F_12 ( V_42 ) ;
return FALSE ;
}
F_12 ( V_42 ) ;
return F_34 ( & V_29 , V_25 , V_41 ) ;
}
V_44 = F_35 ( V_42 , V_43 , & V_29 , V_41 ) ;
if ( V_44 != 0 ) {
* V_25 = F_7 ( L_8 ,
V_42 , F_33 ( V_45 ) ) ;
fclose ( V_43 ) ;
F_12 ( V_42 ) ;
return FALSE ;
}
fclose ( V_43 ) ;
F_12 ( V_42 ) ;
return TRUE ;
}
T_4
F_36 ( T_2 * * V_25 , T_14 V_41 )
{
F_23 ( & V_29 ) ;
return F_30 ( V_25 , V_41 ) ;
}
T_4
F_37 ( T_2 * * V_25 , T_14 V_41 )
{
V_47 = F_38 ( V_47 , V_29 ) ;
V_29 = NULL ;
return F_30 ( V_25 , V_41 ) ;
}
void
F_39 ( void )
{
F_23 ( & V_47 ) ;
}
static void
F_40 ( T_12 V_34 , T_12 V_48 )
{
T_16 * V_49 = ( T_16 * ) V_48 ;
T_1 * V_36 = F_26 ( ( T_1 * ) V_34 ) ;
V_49 -> V_41 ( V_36 , V_49 -> V_48 ) ;
}
void
F_41 ( T_12 V_48 , T_14 V_41 )
{
T_16 V_49 ;
V_49 . V_48 = V_48 ;
V_49 . V_41 = V_41 ;
F_24 ( V_29 , F_40 , & V_49 ) ;
}
static void
F_42 ( T_12 V_34 , T_12 V_50 )
{
T_1 * V_6 = ( T_1 * ) V_34 ;
T_2 * * V_25 = ( T_2 * * ) V_50 ;
T_2 * V_28 = NULL ;
F_5 ( V_6 -> V_31 == NULL ) ;
if ( V_6 -> V_5 ) return;
if ( ! F_17 ( V_6 -> V_8 , & V_6 -> V_31 , & V_28 ) ) {
* V_25 = F_7 ( L_4 ,
V_6 -> V_7 , V_6 -> V_8 , V_28 ) ;
F_12 ( V_28 ) ;
}
}
static void
F_43 ( T_12 V_34 , T_12 V_50 )
{
T_1 * V_6 = ( T_1 * ) V_34 ;
T_2 * * V_25 = ( T_2 * * ) V_50 ;
T_2 * V_28 ;
F_5 ( V_6 -> V_31 == NULL ) ;
if ( V_6 -> V_5 ) return;
if ( ! F_17 ( V_6 -> V_8 , & V_6 -> V_31 , & V_28 ) ) {
* V_25 = F_7 ( L_9 ,
V_6 -> V_7 , V_6 -> V_8 , V_28 ) ;
F_12 ( V_28 ) ;
V_51 = F_44 ( V_51 , V_6 ) ;
F_21 ( V_6 ) ;
}
}
T_4
F_45 ( T_5 * V_52 , T_5 * V_53 , T_2 * * V_25 )
{
T_4 V_44 = TRUE ;
* V_25 = NULL ;
V_47 = F_38 ( V_47 , V_29 ) ;
V_29 = NULL ;
V_51 = NULL ;
V_51 = F_29 ( V_52 ) ;
V_51 = F_38 ( V_51 ,
F_29 ( V_53 ) ) ;
F_24 ( V_51 , F_43 , V_25 ) ;
if ( * V_25 != NULL ) {
V_44 = FALSE ;
}
V_29 = F_29 ( V_51 ) ;
F_24 ( V_29 , F_42 , V_25 ) ;
if ( * V_25 != NULL ) {
V_44 = FALSE ;
}
return V_44 ;
}
T_4
F_46 ( void )
{
return V_29 != NULL && V_54 ;
}
T_4
F_47 ( void )
{
return V_32 ;
}
static void
F_48 ( T_12 V_30 , T_12 V_48 )
{
T_1 * V_6 = ( T_1 * ) V_30 ;
T_17 * V_55 = ( T_17 * ) V_48 ;
if ( V_6 -> V_31 != NULL )
F_49 ( V_55 , V_6 -> V_31 ) ;
}
void
F_50 ( T_17 * V_55 )
{
if ( F_46 () )
F_24 ( V_29 , F_48 , V_55 ) ;
}
const T_1 *
F_51 ( T_17 * V_55 )
{
T_5 * V_56 ;
T_1 * V_6 ;
if ( ( V_55 -> V_57 != NULL ) && ( F_46 () ) ) {
V_56 = V_29 ;
while( V_56 != NULL ) {
V_6 = ( T_1 * ) V_56 -> V_30 ;
if ( ( ! V_6 -> V_5 ) &&
( V_6 -> V_31 != NULL ) &&
F_52 ( V_6 -> V_31 , V_55 ) ) {
return V_6 ;
}
V_56 = F_53 ( V_56 ) ;
}
}
return NULL ;
}
static int
F_35 ( const T_2 * V_42 , T_15 * V_43 , T_12 V_48 , T_14 V_41 )
{
#define F_54 128
T_2 * V_1 = NULL ;
T_2 * V_58 = NULL ;
T_6 V_59 = F_54 ;
T_6 V_60 = F_54 ;
T_6 V_10 = 0 ;
int V_61 ;
T_18 V_62 , V_63 , V_64 , V_65 , V_66 , V_67 ;
T_4 V_5 = FALSE ;
T_4 V_68 = FALSE ;
int V_44 = 0 ;
V_1 = ( T_2 * ) F_27 ( V_59 + 1 ) ;
V_58 = ( T_2 * ) F_27 ( V_60 + 1 ) ;
while ( 1 ) {
if ( V_68 ) {
do {
V_61 = F_55 ( V_43 ) ;
} while ( V_61 != V_69 && V_61 != '\n' );
if ( V_61 == V_69 )
break;
V_5 = FALSE ;
V_68 = FALSE ;
}
while ( ( V_61 = F_55 ( V_43 ) ) != V_69 && F_56 ( V_61 ) ) {
if ( V_61 == '\n' ) {
continue;
}
}
if ( V_61 == V_69 )
break;
if ( V_61 == '!' ) {
V_5 = TRUE ;
continue;
}
if ( V_61 != '@' ) {
V_68 = TRUE ;
continue;
}
V_10 = 0 ;
while ( 1 ) {
V_61 = F_55 ( V_43 ) ;
if ( V_61 == V_69 || V_61 == '@' )
break;
if ( V_10 >= V_59 ) {
V_59 *= 2 ;
V_1 = ( T_2 * ) F_57 ( V_1 , V_59 + 1 ) ;
}
V_1 [ V_10 ++ ] = V_61 ;
}
V_1 [ V_10 ] = '\0' ;
if ( V_61 == V_69 ) {
break;
} else if ( V_10 == 0 ) {
V_68 = TRUE ;
continue;
}
V_10 = 0 ;
while ( 1 ) {
V_61 = F_55 ( V_43 ) ;
if ( V_61 == V_69 || V_61 == '@' )
break;
if ( V_10 >= V_60 ) {
V_60 *= 2 ;
V_58 = ( T_2 * ) F_57 ( V_58 , V_60 + 1 ) ;
}
V_58 [ V_10 ++ ] = V_61 ;
}
V_58 [ V_10 ] = '\0' ;
if ( V_61 == V_69 ) {
break;
} else if ( V_10 == 0 ) {
V_68 = TRUE ;
continue;
}
if ( fscanf ( V_43 , L_10 ,
& V_65 , & V_66 , & V_67 , & V_62 , & V_63 , & V_64 ) == 6 ) {
T_3 V_3 , V_4 ;
T_1 * V_6 ;
T_11 * V_70 = NULL ;
T_2 * V_28 = NULL ;
if ( ! V_5 && ! F_17 ( V_58 , & V_70 , & V_28 ) ) {
F_58 ( L_11 ,
V_1 , V_42 , V_28 ) ;
F_12 ( V_28 ) ;
V_14 . V_71 = TRUE ;
V_5 = TRUE ;
}
V_4 . V_18 = V_62 ;
V_4 . V_19 = V_63 ;
V_4 . V_20 = V_64 ;
V_3 . V_18 = V_65 ;
V_3 . V_19 = V_66 ;
V_3 . V_20 = V_67 ;
V_6 = F_1 ( V_1 , V_58 , & V_3 ,
& V_4 , V_5 ) ;
if( V_48 == & V_29 ) {
T_5 * * V_9 = ( T_5 * * ) V_48 ;
V_6 -> V_31 = V_70 ;
* V_9 = F_11 ( * V_9 , V_6 ) ;
} else {
F_18 ( V_70 ) ;
V_41 ( V_6 , V_48 ) ;
}
}
V_68 = TRUE ;
}
if ( ferror ( V_43 ) )
V_44 = V_45 ;
F_12 ( V_1 ) ;
F_12 ( V_58 ) ;
return V_44 ;
}
T_4
F_34 ( T_12 V_48 , T_2 * * V_25 , T_14 V_41 )
{
T_2 * V_42 ;
T_15 * V_43 ;
int V_44 ;
V_42 = F_59 ( L_5 ) ;
if ( ( V_43 = F_32 ( V_42 , L_6 ) ) == NULL ) {
if ( V_45 != V_46 ) {
* V_25 = F_7 ( L_12 , V_42 ,
F_33 ( V_45 ) ) ;
F_12 ( V_42 ) ;
return FALSE ;
}
return TRUE ;
}
V_44 = F_35 ( V_42 , V_43 , V_48 , V_41 ) ;
if ( V_44 != 0 ) {
* V_25 = F_7 ( L_13 ,
V_42 , F_33 ( V_45 ) ) ;
fclose ( V_43 ) ;
F_12 ( V_42 ) ;
return FALSE ;
}
fclose ( V_43 ) ;
F_12 ( V_42 ) ;
return TRUE ;
}
T_4
F_60 ( const T_2 * V_42 , T_12 V_48 , T_2 * * V_25 , T_14 V_41 )
{
T_15 * V_43 ;
int V_44 ;
if ( ( V_43 = F_32 ( V_42 , L_6 ) ) == NULL ) {
* V_25 = F_7 ( L_14 ,
V_42 , F_33 ( V_45 ) ) ;
return FALSE ;
}
V_44 = F_35 ( V_42 , V_43 , V_48 , V_41 ) ;
if ( V_44 != 0 ) {
* V_25 = F_7 ( L_8 ,
V_42 , F_33 ( V_45 ) ) ;
fclose ( V_43 ) ;
return FALSE ;
}
fclose ( V_43 ) ;
return TRUE ;
}
static void
F_61 ( T_12 V_34 , T_12 V_72 )
{
struct V_73 * V_30 = (struct V_73 * ) V_72 ;
T_1 * V_6 = ( T_1 * ) V_34 ;
T_15 * V_43 = V_30 -> V_43 ;
if ( ( V_6 -> V_38 || ! V_30 -> V_74 ) &&
( strstr ( V_6 -> V_7 , V_17 ) == NULL ) ) {
fprintf ( V_43 , L_15 ,
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
F_62 ( T_5 * V_9 , T_15 * V_43 , T_4 V_74 )
{
struct V_73 V_30 ;
V_30 . V_43 = V_43 ;
V_30 . V_74 = V_74 ;
fprintf ( V_43 , L_18 ) ;
F_24 ( V_9 , F_61 , & V_30 ) ;
return TRUE ;
}
T_4
F_63 ( T_5 * V_9 , T_2 * * V_25 )
{
T_2 * V_75 ;
T_2 * V_42 ;
T_15 * V_43 ;
if ( F_64 ( & V_75 ) == - 1 ) {
* V_25 = F_7 ( L_19 ,
V_75 , F_33 ( V_45 ) ) ;
F_12 ( V_75 ) ;
return FALSE ;
}
V_42 = F_31 ( L_5 , TRUE ) ;
if ( ( V_43 = F_32 ( V_42 , L_20 ) ) == NULL ) {
* V_25 = F_7 ( L_21 ,
V_42 , F_33 ( V_45 ) ) ;
F_12 ( V_42 ) ;
return FALSE ;
}
F_12 ( V_42 ) ;
F_62 ( V_9 , V_43 , FALSE ) ;
fclose ( V_43 ) ;
return TRUE ;
}
T_4
F_65 ( const T_2 * V_42 , T_5 * V_9 , T_4 V_76 , T_2 * * V_25 )
{
T_15 * V_43 ;
if ( ( V_43 = F_32 ( V_42 , L_20 ) ) == NULL ) {
* V_25 = F_7 ( L_21 ,
V_42 , F_33 ( V_45 ) ) ;
return FALSE ;
}
F_62 ( V_9 , V_43 , V_76 ) ;
fclose ( V_43 ) ;
return TRUE ;
}

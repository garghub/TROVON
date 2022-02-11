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
F_8 ( & V_4 , F_9 ( V_13 ) ,
F_10 ( V_13 ) ,
F_11 ( V_13 ) ) ;
V_13 = strtoul ( V_11 [ V_10 - 1 ] , NULL , 16 ) ;
F_8 ( & V_3 , F_9 ( V_13 ) ,
F_10 ( V_13 ) ,
F_11 ( V_13 ) ) ;
V_6 = F_1 ( V_1 , NULL , & V_3 , & V_4 , TRUE ) ;
V_6 -> V_8 = F_3 ( L_3 ) ;
* V_9 = F_12 ( * V_9 , V_6 ) ;
F_13 ( V_1 ) ;
}
F_14 ( V_12 ) ;
F_14 ( V_11 ) ;
return;
}
static T_8
F_15 ( T_9 V_18 , T_9 V_19 )
{
const T_1 * V_6 = ( const T_1 * ) V_18 ;
const T_2 * V_1 = ( const T_2 * ) V_19 ;
return ( strstr ( V_6 -> V_7 , V_1 ) == NULL ) ? - 1 : 0 ;
}
void
F_16 ( T_10 V_20 , const T_2 * V_21 , T_4 V_5 )
{
T_2 * V_1 = NULL ;
const T_2 * V_22 = NULL ;
T_5 * V_9 ;
T_1 * V_6 ;
T_11 * V_23 ;
T_2 * V_24 ;
T_10 V_10 ;
for ( V_10 = 1 ; V_10 <= 10 ; V_10 ++ ) {
if( V_10 != V_20 && V_21 == NULL )
continue;
V_1 = F_7 ( L_2 , V_17 , V_10 ) ;
V_9 = F_17 ( V_25 , V_1 , F_15 ) ;
V_6 = ( T_1 * ) V_9 -> V_26 ;
if( V_6 && ( ( V_10 == V_20 ) || ( strstr ( V_21 , V_6 -> V_8 ) != NULL ) ) ) {
V_22 = ( ( V_21 == NULL ) || ( V_10 != V_20 ) ) ? L_3 : V_21 ;
if ( ! F_18 ( V_22 , & V_23 , & V_24 ) ) {
F_19 ( V_27 , V_28 ,
L_4
L_5 , V_1 , V_21 , V_24 ) ;
F_13 ( V_24 ) ;
} else {
if ( V_6 -> V_8 != NULL )
F_13 ( V_6 -> V_8 ) ;
if ( V_6 -> V_29 != NULL )
F_20 ( V_6 -> V_29 ) ;
V_6 -> V_8 = F_3 ( V_22 ) ;
V_6 -> V_29 = V_23 ;
V_6 -> V_5 = ( ( V_10 != V_20 ) ? TRUE : V_5 ) ;
if( V_21 )
V_30 = TRUE ;
}
}
F_13 ( V_1 ) ;
}
return;
}
const T_1 *
F_21 ( T_10 V_31 ) {
T_2 * V_1 ;
T_1 * V_6 = NULL ;
T_5 * V_9 ;
V_1 = F_7 ( L_2 , V_17 , V_31 ) ;
V_9 = F_17 ( V_25 , V_1 , F_15 ) ;
if ( V_9 ) {
V_6 = ( T_1 * ) V_9 -> V_26 ;
}
F_13 ( V_1 ) ;
return V_6 ;
}
void
F_22 ( void )
{
T_10 V_10 ;
for ( V_10 = 1 ; V_10 <= 10 ; V_10 ++ ) {
F_16 ( V_10 , NULL , TRUE ) ;
}
V_30 = FALSE ;
return;
}
void
F_23 ( T_1 * V_6 )
{
if ( V_6 -> V_7 != NULL )
F_13 ( V_6 -> V_7 ) ;
if ( V_6 -> V_8 != NULL )
F_13 ( V_6 -> V_8 ) ;
if ( V_6 -> V_29 != NULL )
F_20 ( V_6 -> V_29 ) ;
F_13 ( V_6 ) ;
}
static void
F_24 ( T_12 V_32 , T_12 T_13 V_33 )
{
T_1 * V_6 = ( T_1 * ) V_32 ;
F_23 ( V_6 ) ;
}
void
F_25 ( T_5 * * V_9 )
{
F_26 ( * V_9 , F_24 , NULL ) ;
F_27 ( * V_9 ) ;
* V_9 = NULL ;
}
static T_1 *
F_28 ( T_1 * V_6 )
{
T_1 * V_34 ;
V_34 = ( T_1 * ) F_29 ( sizeof ( T_1 ) ) ;
V_34 -> V_7 = F_3 ( V_6 -> V_7 ) ;
V_34 -> V_8 = F_3 ( V_6 -> V_8 ) ;
V_34 -> V_3 = V_6 -> V_3 ;
V_34 -> V_4 = V_6 -> V_4 ;
V_34 -> V_5 = V_6 -> V_5 ;
V_34 -> V_29 = NULL ;
V_34 -> V_35 = NULL ;
V_34 -> V_36 = FALSE ;
return V_34 ;
}
static void
F_30 ( T_12 V_32 , T_12 V_37 )
{
T_5 * * V_9 = ( T_5 * * ) V_37 ;
T_1 * V_34 ;
V_34 = F_28 ( ( T_1 * ) V_32 ) ;
* V_9 = F_12 ( * V_9 , V_34 ) ;
}
static T_5 *
F_31 ( T_5 * V_9 )
{
T_5 * V_38 = NULL ;
F_26 ( V_9 , F_30 , & V_38 ) ;
return V_38 ;
}
void
F_32 ( void )
{
F_25 ( & V_25 ) ;
F_4 ( & V_25 ) ;
if ( ! F_33 ( & V_25 ) )
F_34 ( & V_25 ) ;
}
void
F_35 ( void )
{
V_39 = F_36 ( V_39 , V_25 ) ;
V_25 = NULL ;
F_4 ( & V_25 ) ;
if ( ! F_33 ( & V_25 ) )
F_34 ( & V_25 ) ;
}
void
F_37 ( void )
{
F_25 ( & V_39 ) ;
}
static void
F_38 ( T_12 V_32 , T_12 V_40 )
{
T_1 * V_34 = F_28 ( ( T_1 * ) V_32 ) ;
F_39 ( V_34 , V_40 ) ;
}
void
F_40 ( T_12 V_40 )
{
F_26 ( V_25 , F_38 , V_40 ) ;
}
static void
F_41 ( T_12 V_32 , T_12 T_13 V_33 )
{
T_1 * V_6 = ( T_1 * ) V_32 ;
T_2 * V_24 ;
F_5 ( V_6 -> V_29 == NULL ) ;
if ( ! F_18 ( V_6 -> V_8 , & V_6 -> V_29 , & V_24 ) ) {
F_19 ( V_27 , V_28 ,
L_6 ,
V_6 -> V_7 , V_6 -> V_8 , V_24 ) ;
F_13 ( V_24 ) ;
}
}
static void
F_42 ( T_12 V_32 , T_12 T_13 V_33 )
{
T_1 * V_6 = ( T_1 * ) V_32 ;
T_2 * V_24 ;
F_5 ( V_6 -> V_29 == NULL ) ;
if ( ! F_18 ( V_6 -> V_8 , & V_6 -> V_29 , & V_24 ) ) {
F_19 ( V_27 , V_28 ,
L_7 ,
V_6 -> V_7 , V_6 -> V_8 , V_24 ) ;
F_13 ( V_24 ) ;
V_41 = F_43 ( V_41 , V_6 ) ;
F_23 ( V_6 ) ;
}
}
void
F_44 ( T_5 * V_42 , T_5 * V_43 )
{
V_39 = F_36 ( V_39 , V_25 ) ;
V_25 = NULL ;
V_41 = NULL ;
V_41 = F_31 ( V_42 ) ;
V_41 = F_36 ( V_41 ,
F_31 ( V_43 ) ) ;
F_26 ( V_41 , F_42 , NULL ) ;
V_25 = F_31 ( V_41 ) ;
F_26 ( V_25 , F_41 , NULL ) ;
}
T_4
F_45 ( void )
{
return V_25 != NULL && V_44 ;
}
T_4
F_46 ( void )
{
return V_30 ;
}
void
F_47 ( T_4 V_45 )
{
F_48 ( V_45 ) ;
}
static void
F_49 ( T_12 V_26 , T_12 V_40 )
{
T_1 * V_6 = ( T_1 * ) V_26 ;
T_14 * V_46 = ( T_14 * ) V_40 ;
if ( V_6 -> V_29 != NULL )
F_50 ( V_46 , V_6 -> V_29 ) ;
}
void
F_51 ( T_14 * V_46 )
{
if ( F_45 () )
F_26 ( V_25 , F_49 , V_46 ) ;
}
const T_1 *
F_52 ( T_14 * V_46 )
{
T_5 * V_47 ;
T_1 * V_6 ;
if ( F_45 () ) {
V_47 = V_25 ;
while( V_47 != NULL ) {
V_6 = ( T_1 * ) V_47 -> V_26 ;
if ( ( ! V_6 -> V_5 ) &&
( V_6 -> V_29 != NULL ) &&
F_53 ( V_6 -> V_29 , V_46 ) ) {
return V_6 ;
}
V_47 = F_54 ( V_47 ) ;
}
}
return NULL ;
}
static T_4
F_55 ( T_15 * V_48 , T_12 V_40 )
{
#define F_56 128
T_2 * V_1 = NULL ;
T_2 * V_49 = NULL ;
T_6 V_50 = F_56 ;
T_6 V_51 = F_56 ;
T_6 V_10 = 0 ;
int V_52 ;
T_16 V_53 , V_54 , V_55 , V_56 , V_57 , V_58 ;
T_4 V_5 = FALSE ;
T_4 V_59 = FALSE ;
V_1 = ( T_2 * ) F_29 ( V_50 + 1 ) ;
V_49 = ( T_2 * ) F_29 ( V_51 + 1 ) ;
while ( 1 ) {
if ( V_59 ) {
do {
V_52 = getc ( V_48 ) ;
} while ( V_52 != V_60 && V_52 != '\n' );
if ( V_52 == V_60 )
break;
V_5 = FALSE ;
V_59 = FALSE ;
}
while ( ( V_52 = getc ( V_48 ) ) != V_60 && F_57 ( V_52 ) ) {
if ( V_52 == '\n' ) {
continue;
}
}
if ( V_52 == V_60 )
break;
if ( V_52 == '!' ) {
V_5 = TRUE ;
continue;
}
if ( V_52 != '@' ) {
V_59 = TRUE ;
continue;
}
V_10 = 0 ;
while ( 1 ) {
V_52 = getc ( V_48 ) ;
if ( V_52 == V_60 || V_52 == '@' )
break;
if ( V_10 >= V_50 ) {
V_50 *= 2 ;
V_1 = ( T_2 * ) F_58 ( V_1 , V_50 + 1 ) ;
}
V_1 [ V_10 ++ ] = V_52 ;
}
V_1 [ V_10 ] = '\0' ;
if ( V_52 == V_60 ) {
break;
} else if ( V_10 == 0 ) {
V_59 = TRUE ;
continue;
}
V_10 = 0 ;
while ( 1 ) {
V_52 = getc ( V_48 ) ;
if ( V_52 == V_60 || V_52 == '@' )
break;
if ( V_10 >= V_51 ) {
V_51 *= 2 ;
V_49 = ( T_2 * ) F_58 ( V_49 , V_51 + 1 ) ;
}
V_49 [ V_10 ++ ] = V_52 ;
}
V_49 [ V_10 ] = '\0' ;
if ( V_52 == V_60 ) {
break;
} else if ( V_10 == 0 ) {
V_59 = TRUE ;
continue;
}
if ( fscanf ( V_48 , L_8 ,
& V_56 , & V_57 , & V_58 , & V_53 , & V_54 , & V_55 ) == 6 ) {
T_3 V_3 , V_4 ;
T_1 * V_6 ;
T_11 * V_61 ;
T_2 * V_24 ;
if ( ! F_18 ( V_49 , & V_61 , & V_24 ) ) {
F_59 ( L_9 ,
V_1 , V_24 ) ;
F_13 ( V_24 ) ;
V_14 . V_62 = TRUE ;
V_59 = TRUE ;
continue;
}
if ( ! F_8 ( & V_4 , V_53 , V_54 , V_55 ) ) {
F_19 ( V_27 , V_28 ,
L_10
L_11 , V_1 ) ;
F_20 ( V_61 ) ;
V_59 = TRUE ;
continue;
}
if ( ! F_8 ( & V_3 , V_56 , V_57 , V_58 ) ) {
F_19 ( V_27 , V_28 ,
L_12
L_11 , V_1 ) ;
F_20 ( V_61 ) ;
V_59 = TRUE ;
continue;
}
V_6 = F_1 ( V_1 , V_49 , & V_3 ,
& V_4 , V_5 ) ;
if( V_40 == & V_25 ) {
T_5 * * V_9 = ( T_5 * * ) V_40 ;
V_6 -> V_29 = V_61 ;
* V_9 = F_12 ( * V_9 , V_6 ) ;
} else {
F_20 ( V_61 ) ;
F_39 ( V_6 , V_40 ) ;
}
}
V_59 = TRUE ;
}
F_13 ( V_1 ) ;
F_13 ( V_49 ) ;
return TRUE ;
}
static T_4
F_33 ( T_5 * * V_9 )
{
T_2 * V_63 ;
T_15 * V_48 ;
T_4 V_64 ;
V_63 = F_60 ( L_13 , TRUE ) ;
if ( ( V_48 = F_61 ( V_63 , L_14 ) ) == NULL ) {
if ( V_65 != V_66 ) {
F_19 ( V_27 , V_28 ,
L_15 , V_63 ,
F_62 ( V_65 ) ) ;
}
F_13 ( V_63 ) ;
return FALSE ;
}
F_13 ( V_63 ) ;
V_63 = NULL ;
V_64 = F_55 ( V_48 , V_9 ) ;
fclose ( V_48 ) ;
return V_64 ;
}
T_4
F_34 ( T_12 V_40 )
{
T_2 * V_63 ;
T_15 * V_48 ;
T_4 V_64 ;
V_63 = F_63 ( L_13 ) ;
if ( ( V_48 = F_61 ( V_63 , L_14 ) ) == NULL ) {
if ( V_65 != V_66 ) {
F_19 ( V_27 , V_28 ,
L_16 , V_63 ,
F_62 ( V_65 ) ) ;
}
F_13 ( V_63 ) ;
return FALSE ;
}
F_13 ( V_63 ) ;
V_63 = NULL ;
V_64 = F_55 ( V_48 , V_40 ) ;
fclose ( V_48 ) ;
return V_64 ;
}
T_4
F_64 ( const T_2 * V_63 , const T_12 V_40 )
{
T_15 * V_48 ;
T_4 V_64 ;
if ( ( V_48 = F_61 ( V_63 , L_14 ) ) == NULL ) {
F_19 ( V_27 , V_28 ,
L_17 ,
V_63 , F_62 ( V_65 ) ) ;
return FALSE ;
}
V_64 = F_55 ( V_48 , V_40 ) ;
fclose ( V_48 ) ;
return V_64 ;
}
static void
F_65 ( T_12 V_32 , T_12 V_67 )
{
struct V_68 * V_26 = (struct V_68 * ) V_67 ;
T_1 * V_6 = ( T_1 * ) V_32 ;
T_15 * V_48 = V_26 -> V_48 ;
if ( ( V_6 -> V_36 || ! V_26 -> V_69 ) &&
( strstr ( V_6 -> V_7 , V_17 ) == NULL ) ) {
fprintf ( V_48 , L_18 ,
V_6 -> V_5 ? L_19 : L_20 ,
V_6 -> V_7 ,
V_6 -> V_8 ,
V_6 -> V_3 . V_70 ,
V_6 -> V_3 . V_71 ,
V_6 -> V_3 . V_72 ,
V_6 -> V_4 . V_70 ,
V_6 -> V_4 . V_71 ,
V_6 -> V_4 . V_72 ) ;
}
}
static T_4
F_66 ( const T_5 * V_9 , T_15 * V_48 , T_4 V_69 )
{
struct V_68 V_26 ;
V_26 . V_48 = V_48 ;
V_26 . V_69 = V_69 ;
fprintf ( V_48 , L_21 ) ;
F_26 ( ( T_5 * ) V_9 , F_65 , & V_26 ) ;
return TRUE ;
}
T_4
F_67 ( T_5 * V_9 )
{
T_2 * V_73 ;
T_2 * V_63 ;
T_15 * V_48 ;
if ( F_68 ( & V_73 ) == - 1 ) {
F_19 ( V_27 , V_28 ,
L_22 ,
V_73 , F_62 ( V_65 ) ) ;
F_13 ( V_73 ) ;
return FALSE ;
}
V_63 = F_60 ( L_13 , TRUE ) ;
if ( ( V_48 = F_61 ( V_63 , L_23 ) ) == NULL ) {
F_19 ( V_27 , V_28 ,
L_24 ,
V_63 , F_62 ( V_65 ) ) ;
F_13 ( V_63 ) ;
return FALSE ;
}
F_13 ( V_63 ) ;
F_66 ( V_9 , V_48 , FALSE ) ;
fclose ( V_48 ) ;
return TRUE ;
}
T_4
F_69 ( const T_2 * V_63 , const T_5 * V_9 , T_4 V_74 )
{
T_15 * V_48 ;
if ( ( V_48 = F_61 ( V_63 , L_23 ) ) == NULL ) {
F_19 ( V_27 , V_28 ,
L_24 ,
V_63 , F_62 ( V_65 ) ) ;
return FALSE ;
}
F_66 ( V_9 , V_48 , V_74 ) ;
fclose ( V_48 ) ;
return TRUE ;
}

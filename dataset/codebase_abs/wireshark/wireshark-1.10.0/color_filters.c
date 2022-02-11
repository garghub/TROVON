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
V_6 -> V_9 = NULL ;
V_6 -> V_10 = NULL ;
V_6 -> V_11 = FALSE ;
return V_6 ;
}
static void
F_4 ( T_5 * * V_12 )
{
T_2 * V_1 = NULL ;
T_6 V_13 ;
T_2 * * V_14 ;
T_2 * * V_15 ;
T_7 V_16 ;
T_3 V_3 , V_4 ;
T_1 * V_6 ;
F_5 ( strlen ( V_17 . V_18 ) == 69 ) ;
F_5 ( strlen ( V_17 . V_19 ) == 69 ) ;
V_15 = F_6 ( V_17 . V_18 , L_1 , - 1 ) ;
V_14 = F_6 ( V_17 . V_19 , L_1 , - 1 ) ;
for ( V_13 = 1 ; V_13 <= 10 ; V_13 ++ ) {
V_1 = F_7 ( L_2 , V_20 , V_13 ) ;
V_16 = strtoul ( V_15 [ V_13 - 1 ] , NULL , 16 ) ;
F_8 ( & V_4 , F_9 ( V_16 ) ,
F_10 ( V_16 ) ,
F_11 ( V_16 ) ) ;
V_16 = strtoul ( V_14 [ V_13 - 1 ] , NULL , 16 ) ;
F_8 ( & V_3 , F_9 ( V_16 ) ,
F_10 ( V_16 ) ,
F_11 ( V_16 ) ) ;
V_6 = F_1 ( V_1 , NULL , & V_3 , & V_4 , TRUE ) ;
V_6 -> V_8 = F_3 ( L_3 ) ;
V_6 -> V_9 = NULL ;
* V_12 = F_12 ( * V_12 , V_6 ) ;
F_13 ( V_1 ) ;
}
F_14 ( V_15 ) ;
F_14 ( V_14 ) ;
return;
}
static T_8
F_15 ( T_9 V_21 , T_9 V_22 )
{
const T_1 * V_6 = ( const T_1 * ) V_21 ;
const T_2 * V_1 = ( const T_2 * ) V_22 ;
return ( strstr ( V_6 -> V_7 , V_1 ) == NULL ) ? - 1 : 0 ;
}
void
F_16 ( T_10 V_23 , T_2 * V_24 , T_4 V_5 )
{
T_2 * V_1 = NULL ;
const T_2 * V_25 = NULL ;
T_5 * V_12 ;
T_1 * V_6 ;
T_11 * V_26 ;
T_10 V_13 ;
for ( V_13 = 1 ; V_13 <= 10 ; V_13 ++ ) {
if( V_13 != V_23 && V_24 == NULL )
continue;
V_1 = F_7 ( L_2 , V_20 , V_13 ) ;
V_12 = F_17 ( V_27 , V_1 , F_15 ) ;
V_6 = ( T_1 * ) V_12 -> V_28 ;
if( V_6 && ( ( V_13 == V_23 ) || ( strstr ( V_24 , V_6 -> V_8 ) != NULL ) ) ) {
V_25 = ( ( V_24 == NULL ) || ( V_13 != V_23 ) ) ? L_3 : V_24 ;
if ( ! F_18 ( V_25 , & V_26 ) ) {
F_19 ( V_29 , V_30 ,
L_4
L_5 , V_1 , V_24 , V_31 ) ;
} else {
if ( V_6 -> V_8 != NULL )
F_13 ( V_6 -> V_8 ) ;
if ( V_6 -> V_9 != NULL )
F_20 ( V_6 -> V_9 ) ;
V_6 -> V_8 = F_3 ( V_25 ) ;
V_6 -> V_9 = V_26 ;
V_6 -> V_5 = ( ( V_13 != V_23 ) ? TRUE : V_5 ) ;
if( V_24 )
V_32 = TRUE ;
}
}
F_13 ( V_1 ) ;
}
return;
}
void
F_21 ( void )
{
T_10 V_13 ;
for ( V_13 = 1 ; V_13 <= 10 ; V_13 ++ ) {
F_16 ( V_13 , NULL , TRUE ) ;
}
V_32 = FALSE ;
return;
}
void
F_22 ( T_1 * V_6 )
{
if ( V_6 -> V_7 != NULL )
F_13 ( V_6 -> V_7 ) ;
if ( V_6 -> V_8 != NULL )
F_13 ( V_6 -> V_8 ) ;
if ( V_6 -> V_9 != NULL )
F_20 ( V_6 -> V_9 ) ;
F_13 ( V_6 ) ;
}
static void
F_23 ( T_12 V_33 , T_12 T_13 V_34 )
{
T_1 * V_6 = ( T_1 * ) V_33 ;
F_22 ( V_6 ) ;
}
void
F_24 ( T_5 * * V_12 )
{
F_25 ( * V_12 , F_23 , NULL ) ;
F_26 ( * V_12 ) ;
* V_12 = NULL ;
}
static T_1 *
F_27 ( T_1 * V_6 )
{
T_1 * V_35 ;
V_35 = ( T_1 * ) F_2 ( sizeof ( T_1 ) ) ;
V_35 -> V_7 = F_3 ( V_6 -> V_7 ) ;
V_35 -> V_8 = F_3 ( V_6 -> V_8 ) ;
V_35 -> V_3 = V_6 -> V_3 ;
V_35 -> V_4 = V_6 -> V_4 ;
V_35 -> V_5 = V_6 -> V_5 ;
V_35 -> V_9 = NULL ;
V_35 -> V_10 = NULL ;
V_35 -> V_11 = FALSE ;
return V_35 ;
}
static void
F_28 ( T_12 V_33 , T_12 V_36 )
{
T_5 * * V_12 = ( T_5 * * ) V_36 ;
T_1 * V_35 ;
V_35 = F_27 ( ( T_1 * ) V_33 ) ;
* V_12 = F_12 ( * V_12 , V_35 ) ;
}
static T_5 *
F_29 ( T_5 * V_12 )
{
T_5 * V_37 = NULL ;
F_25 ( V_12 , F_28 , & V_37 ) ;
return V_37 ;
}
void
F_30 ( void )
{
F_24 ( & V_27 ) ;
F_4 ( & V_27 ) ;
if ( ! F_31 ( & V_27 ) )
F_32 ( & V_27 ) ;
}
void
F_33 ( void )
{
V_38 = F_34 ( V_38 , V_27 ) ;
V_27 = NULL ;
F_4 ( & V_27 ) ;
if ( ! F_31 ( & V_27 ) )
F_32 ( & V_27 ) ;
}
void
F_35 ( void )
{
F_24 ( & V_38 ) ;
}
static void
F_36 ( T_12 V_33 , T_12 V_39 )
{
T_1 * V_35 = F_27 ( ( T_1 * ) V_33 ) ;
F_37 ( V_35 , V_39 ) ;
}
void
F_38 ( T_12 V_39 )
{
F_25 ( V_27 , F_36 , V_39 ) ;
}
static void
F_39 ( T_12 V_33 , T_12 T_13 V_34 )
{
T_1 * V_6 = ( T_1 * ) V_33 ;
F_5 ( V_6 -> V_9 == NULL ) ;
if ( ! F_18 ( V_6 -> V_8 , & V_6 -> V_9 ) ) {
F_19 ( V_29 , V_30 ,
L_6 ,
V_6 -> V_7 , V_6 -> V_8 , V_31 ) ;
}
}
static void
F_40 ( T_12 V_33 , T_12 T_13 V_34 )
{
T_1 * V_6 = ( T_1 * ) V_33 ;
F_5 ( V_6 -> V_9 == NULL ) ;
if ( ! F_18 ( V_6 -> V_8 , & V_6 -> V_9 ) ) {
F_19 ( V_29 , V_30 ,
L_7 ,
V_6 -> V_7 , V_6 -> V_8 , V_31 ) ;
V_40 = F_41 ( V_40 , V_6 ) ;
F_22 ( V_6 ) ;
}
}
void
F_42 ( T_5 * V_41 , T_5 * V_42 )
{
V_38 = F_34 ( V_38 , V_27 ) ;
V_27 = NULL ;
V_40 = NULL ;
V_40 = F_29 ( V_41 ) ;
V_40 = F_34 ( V_40 ,
F_29 ( V_42 ) ) ;
F_25 ( V_40 , F_40 , NULL ) ;
V_27 = F_29 ( V_40 ) ;
F_25 ( V_27 , F_39 , NULL ) ;
}
T_4
F_43 ( void )
{
return V_27 != NULL && V_43 ;
}
T_4
F_44 ( void )
{
return V_32 ;
}
void
F_45 ( T_4 V_44 )
{
F_46 ( V_44 ) ;
}
static void
F_47 ( T_12 V_28 , T_12 V_39 )
{
T_1 * V_6 = ( T_1 * ) V_28 ;
T_14 * V_45 = ( T_14 * ) V_39 ;
if ( V_6 -> V_9 != NULL )
F_48 ( V_45 , V_6 -> V_9 ) ;
}
void
F_49 ( T_14 * V_45 )
{
if ( F_43 () )
F_25 ( V_27 , F_47 , V_45 ) ;
}
const T_1 *
F_50 ( T_14 * V_45 )
{
T_5 * V_46 ;
T_1 * V_6 ;
if ( F_43 () ) {
V_46 = V_27 ;
while( V_46 != NULL ) {
V_6 = ( T_1 * ) V_46 -> V_28 ;
if ( ( ! V_6 -> V_5 ) &&
( V_6 -> V_9 != NULL ) &&
F_51 ( V_6 -> V_9 , V_45 ) ) {
return V_6 ;
}
V_46 = F_52 ( V_46 ) ;
}
}
return NULL ;
}
static T_4
F_53 ( T_15 * V_47 , T_12 V_39 )
{
#define F_54 128
T_2 * V_1 = NULL ;
T_2 * V_48 = NULL ;
T_6 V_49 = F_54 ;
T_6 V_50 = F_54 ;
T_6 V_13 = 0 ;
T_16 V_51 ;
T_17 V_52 , V_53 , V_54 , V_55 , V_56 , V_57 ;
T_4 V_5 = FALSE ;
T_4 V_58 = FALSE ;
V_1 = ( T_2 * ) F_2 ( V_49 + 1 ) ;
V_48 = ( T_2 * ) F_2 ( V_50 + 1 ) ;
while ( 1 ) {
if ( V_58 ) {
do {
V_51 = getc ( V_47 ) ;
} while ( V_51 != V_59 && V_51 != '\n' );
if ( V_51 == V_59 )
break;
V_5 = FALSE ;
V_58 = FALSE ;
}
while ( ( V_51 = getc ( V_47 ) ) != V_59 && isspace ( V_51 ) ) {
if ( V_51 == '\n' ) {
continue;
}
}
if ( V_51 == V_59 )
break;
if ( V_51 == '!' ) {
V_5 = TRUE ;
continue;
}
if ( V_51 != '@' ) {
V_58 = TRUE ;
continue;
}
V_13 = 0 ;
while ( 1 ) {
V_51 = getc ( V_47 ) ;
if ( V_51 == V_59 || V_51 == '@' )
break;
if ( V_13 >= V_49 ) {
V_49 *= 2 ;
V_1 = ( T_2 * ) F_55 ( V_1 , V_49 + 1 ) ;
}
V_1 [ V_13 ++ ] = V_51 ;
}
V_1 [ V_13 ] = '\0' ;
if ( V_51 == V_59 ) {
break;
} else if ( V_13 == 0 ) {
V_58 = TRUE ;
continue;
}
V_13 = 0 ;
while ( 1 ) {
V_51 = getc ( V_47 ) ;
if ( V_51 == V_59 || V_51 == '@' )
break;
if ( V_13 >= V_50 ) {
V_50 *= 2 ;
V_48 = ( T_2 * ) F_55 ( V_48 , V_50 + 1 ) ;
}
V_48 [ V_13 ++ ] = V_51 ;
}
V_48 [ V_13 ] = '\0' ;
if ( V_51 == V_59 ) {
break;
} else if ( V_13 == 0 ) {
V_58 = TRUE ;
continue;
}
if ( fscanf ( V_47 , L_8 ,
& V_55 , & V_56 , & V_57 , & V_52 , & V_53 , & V_54 ) == 6 ) {
T_3 V_3 , V_4 ;
T_1 * V_6 ;
T_11 * V_60 ;
if ( ! F_18 ( V_48 , & V_60 ) ) {
F_56 ( L_9 ,
V_1 , V_31 ) ;
V_58 = TRUE ;
continue;
}
if ( ! F_8 ( & V_4 , V_52 , V_53 , V_54 ) ) {
F_19 ( V_29 , V_30 ,
L_10
L_11 , V_1 ) ;
F_20 ( V_60 ) ;
V_58 = TRUE ;
continue;
}
if ( ! F_8 ( & V_3 , V_55 , V_56 , V_57 ) ) {
F_19 ( V_29 , V_30 ,
L_12
L_11 , V_1 ) ;
F_20 ( V_60 ) ;
V_58 = TRUE ;
continue;
}
V_6 = F_1 ( V_1 , V_48 , & V_3 ,
& V_4 , V_5 ) ;
if( V_39 == & V_27 ) {
T_5 * * V_12 = ( T_5 * * ) V_39 ;
V_6 -> V_9 = V_60 ;
* V_12 = F_12 ( * V_12 , V_6 ) ;
} else {
F_20 ( V_60 ) ;
F_37 ( V_6 , V_39 ) ;
}
}
V_58 = TRUE ;
}
F_13 ( V_1 ) ;
F_13 ( V_48 ) ;
return TRUE ;
}
static T_4
F_31 ( T_5 * * V_12 )
{
T_2 * V_61 ;
T_15 * V_47 ;
T_4 V_62 ;
V_61 = F_57 ( L_13 , TRUE ) ;
if ( ( V_47 = F_58 ( V_61 , L_14 ) ) == NULL ) {
if ( V_63 != V_64 ) {
F_19 ( V_29 , V_30 ,
L_15 , V_61 ,
F_59 ( V_63 ) ) ;
}
F_13 ( V_61 ) ;
return FALSE ;
}
F_13 ( V_61 ) ;
V_61 = NULL ;
V_62 = F_53 ( V_47 , V_12 ) ;
fclose ( V_47 ) ;
return V_62 ;
}
T_4
F_32 ( T_12 V_39 )
{
T_2 * V_61 ;
T_15 * V_47 ;
T_4 V_62 ;
V_61 = F_60 ( L_13 ) ;
if ( ( V_47 = F_58 ( V_61 , L_14 ) ) == NULL ) {
if ( V_63 != V_64 ) {
F_19 ( V_29 , V_30 ,
L_16 , V_61 ,
F_59 ( V_63 ) ) ;
}
F_13 ( V_61 ) ;
return FALSE ;
}
F_13 ( V_61 ) ;
V_61 = NULL ;
V_62 = F_53 ( V_47 , V_39 ) ;
fclose ( V_47 ) ;
return V_62 ;
}
T_4
F_61 ( T_2 * V_61 , T_12 V_39 )
{
T_15 * V_47 ;
T_4 V_62 ;
if ( ( V_47 = F_58 ( V_61 , L_14 ) ) == NULL ) {
F_19 ( V_29 , V_30 ,
L_17 ,
V_61 , F_59 ( V_63 ) ) ;
return FALSE ;
}
V_62 = F_53 ( V_47 , V_39 ) ;
fclose ( V_47 ) ;
return V_62 ;
}
static void
F_62 ( T_12 V_33 , T_12 V_65 )
{
struct V_66 * V_28 = (struct V_66 * ) V_65 ;
T_1 * V_6 = ( T_1 * ) V_33 ;
T_15 * V_47 = V_28 -> V_47 ;
if ( ( V_6 -> V_11 || ! V_28 -> V_67 ) &&
( strstr ( V_6 -> V_7 , V_20 ) == NULL ) ) {
fprintf ( V_47 , L_18 ,
V_6 -> V_5 ? L_19 : L_20 ,
V_6 -> V_7 ,
V_6 -> V_8 ,
V_6 -> V_3 . V_68 ,
V_6 -> V_3 . V_69 ,
V_6 -> V_3 . V_70 ,
V_6 -> V_4 . V_68 ,
V_6 -> V_4 . V_69 ,
V_6 -> V_4 . V_70 ) ;
}
}
static T_4
F_63 ( T_5 * V_12 , T_15 * V_47 , T_4 V_67 )
{
struct V_66 V_28 ;
V_28 . V_47 = V_47 ;
V_28 . V_67 = V_67 ;
fprintf ( V_47 , L_21 ) ;
F_25 ( V_12 , F_62 , & V_28 ) ;
return TRUE ;
}
T_4
F_64 ( T_5 * V_12 )
{
T_2 * V_71 ;
T_2 * V_61 ;
T_15 * V_47 ;
if ( F_65 ( & V_71 ) == - 1 ) {
F_19 ( V_29 , V_30 ,
L_22 ,
V_71 , F_59 ( V_63 ) ) ;
F_13 ( V_71 ) ;
return FALSE ;
}
V_61 = F_57 ( L_13 , TRUE ) ;
if ( ( V_47 = F_58 ( V_61 , L_23 ) ) == NULL ) {
F_19 ( V_29 , V_30 ,
L_24 ,
V_61 , F_59 ( V_63 ) ) ;
F_13 ( V_61 ) ;
return FALSE ;
}
F_13 ( V_61 ) ;
F_63 ( V_12 , V_47 , FALSE ) ;
fclose ( V_47 ) ;
return TRUE ;
}
T_4
F_66 ( T_2 * V_61 , T_5 * V_12 , T_4 V_72 )
{
T_15 * V_47 ;
if ( ( V_47 = F_58 ( V_61 , L_23 ) ) == NULL ) {
F_19 ( V_29 , V_30 ,
L_24 ,
V_61 , F_59 ( V_63 ) ) ;
return FALSE ;
}
F_63 ( V_12 , V_47 , V_72 ) ;
fclose ( V_47 ) ;
return TRUE ;
}

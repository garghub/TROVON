static void
F_1 ( T_1 * * V_1 )
{
T_1 * V_2 ;
T_2 * V_3 ;
if ( * V_1 != NULL ) {
V_2 = F_2 ( * V_1 ) ;
while ( V_2 != NULL ) {
V_3 = ( T_2 * ) V_2 -> V_4 ;
F_3 ( V_3 -> V_5 ) ;
F_3 ( V_3 ) ;
V_2 = V_2 -> V_6 ;
}
F_4 ( * V_1 ) ;
* V_1 = NULL ;
}
}
static void
F_5 ( T_1 * * V_1 )
{
T_1 * V_2 ;
T_3 * V_3 ;
if ( * V_1 != NULL ) {
V_2 = F_2 ( * V_1 ) ;
while ( V_2 != NULL ) {
V_3 = ( T_3 * ) V_2 -> V_4 ;
F_3 ( V_3 -> V_5 ) ;
F_3 ( V_3 ) ;
V_2 = V_2 -> V_6 ;
}
F_4 ( * V_1 ) ;
* V_1 = NULL ;
}
}
static void
F_6 ( T_1 * V_7 , T_1 * V_8 , T_4 V_9 )
{
T_5 V_10 ;
T_1 * V_2 ;
T_2 * V_3 ;
if ( V_7 == NULL )
goto V_11;
V_2 = F_2 ( V_7 ) ;
while ( V_2 != NULL ) {
V_3 = ( T_2 * ) V_2 -> V_4 ;
V_10 = F_7 ( V_3 -> V_5 ) ;
if ( V_10 == - 1 ) {
} else {
if ( F_8 ( V_10 ) )
F_9 ( V_10 , V_9 ) ;
}
V_2 = V_2 -> V_6 ;
}
V_11:
if ( V_8 == NULL )
return;
V_2 = F_2 ( V_8 ) ;
while ( V_2 != NULL ) {
V_3 = ( T_2 * ) V_2 -> V_4 ;
V_10 = F_7 ( V_3 -> V_5 ) ;
if ( V_10 == - 1 ) {
} else {
if ( F_8 ( V_10 ) ) {
F_9 ( V_10 , V_9 ) ;
F_10 ( V_10 ) ;
}
}
V_2 = V_2 -> V_6 ;
}
}
static void
F_11 ( char * * V_12 , int * V_13 , const char * V_14 ,
const char * V_15 , T_4 (* F_12)( T_6 * V_16 ) )
{
T_7 * V_17 , * V_18 ;
T_8 * V_19 ;
T_5 V_10 ;
T_6 * V_16 ;
void * V_20 ;
T_4 V_21 = TRUE ;
* V_12 = NULL ;
V_17 = F_13 ( V_14 , TRUE ) ;
V_18 = F_14 ( L_1 , V_17 ) ;
if ( ( V_19 = F_15 ( V_18 , L_2 ) ) == NULL ) {
* V_12 = V_17 ;
* V_13 = V_22 ;
F_3 ( V_18 ) ;
return;
}
for ( V_10 = F_16 ( & V_20 ) ; V_10 != - 1 ;
V_10 = F_17 ( & V_20 ) ) {
if ( ! F_8 ( V_10 ) ) {
continue;
}
V_16 = F_18 ( V_10 ) ;
if ( F_12 ( V_16 ) == FALSE )
continue;
if ( V_21 ) {
if ( V_15 != NULL ) {
fprintf ( V_19 , L_3 , V_15 ) ;
}
V_21 = FALSE ;
}
fprintf ( V_19 , L_3 , F_19 ( V_10 ) ) ;
}
if ( fclose ( V_19 ) == V_23 ) {
* V_12 = V_17 ;
* V_13 = V_22 ;
F_20 ( V_18 ) ;
F_3 ( V_18 ) ;
return;
}
#ifdef F_21
if ( F_22 ( V_17 ) < 0 && V_22 != V_24 ) {
* V_12 = V_17 ;
* V_13 = V_22 ;
F_20 ( V_18 ) ;
F_3 ( V_18 ) ;
return;
}
#endif
if ( F_23 ( V_18 , V_17 ) < 0 ) {
* V_12 = V_17 ;
* V_13 = V_22 ;
F_20 ( V_18 ) ;
F_3 ( V_18 ) ;
return;
}
F_3 ( V_18 ) ;
F_3 ( V_17 ) ;
}
static int
F_24 ( const char * V_17 , T_8 * V_19 , T_1 * * V_1 )
{
T_2 * V_3 ;
int V_25 ;
char * V_26 ;
int V_27 ;
int V_28 ;
int line = 1 ;
T_4 V_29 = FALSE ;
V_27 = V_30 ;
V_26 = ( char * ) F_25 ( V_27 + 1 ) ;
for ( line = 1 ; ; line ++ ) {
while ( ( V_25 = F_26 ( V_19 ) ) != V_23 && F_27 ( V_25 ) ) {
if ( V_25 == '\n' ) {
continue;
}
}
if ( V_25 == V_23 ) {
if ( ferror ( V_19 ) )
goto error;
else
break;
}
ungetc ( V_25 , V_19 ) ;
V_28 = 0 ;
for (; ; ) {
V_25 = F_26 ( V_19 ) ;
if ( V_25 == V_23 )
break;
if ( F_27 ( V_25 ) )
break;
if ( V_25 == '#' ) {
V_29 = TRUE ;
break;
}
if ( V_28 >= V_27 ) {
V_27 *= 2 ;
V_26 = ( char * ) F_28 ( V_26 , V_27 + 1 ) ;
}
V_26 [ V_28 ] = V_25 ;
V_28 ++ ;
}
if ( F_27 ( V_25 ) && V_25 != '\n' ) {
while ( ( V_25 = F_26 ( V_19 ) ) != V_23 && V_25 != '\n' && F_27 ( V_25 ) )
;
if ( V_25 != V_23 && V_25 != '\n' && V_25 != '#' ) {
F_29 ( L_4 ,
V_17 , line ) ;
}
}
if ( V_25 != V_23 && V_25 != '\n' && V_29 == TRUE ) {
while ( ( V_25 = F_26 ( V_19 ) ) != V_23 && V_25 != '\n' )
;
}
if ( V_25 == V_23 ) {
if ( ferror ( V_19 ) )
goto error;
else {
F_29 ( L_5 , V_17 ,
line ) ;
}
break;
}
if ( V_29 ) {
V_29 = FALSE ;
continue;
}
if ( V_28 >= V_27 ) {
V_27 *= 2 ;
V_26 = ( char * ) F_28 ( V_26 , V_27 + 1 ) ;
}
V_26 [ V_28 ] = '\0' ;
V_3 = ( T_2 * ) F_25 ( sizeof( T_2 ) ) ;
V_3 -> V_5 = F_30 ( V_26 ) ;
* V_1 = F_31 ( * V_1 , V_3 ) ;
}
F_3 ( V_26 ) ;
return 0 ;
error:
F_3 ( V_26 ) ;
return V_22 ;
}
static void
F_32 ( char * * V_31 , int * V_32 ,
int * V_33 ,
char * * V_34 , int * V_35 ,
int * V_36 ,
const char * V_14 ,
T_1 * * V_8 , T_1 * * V_7 )
{
int V_37 ;
char * V_38 , * V_17 ;
T_8 * V_19 ;
V_38 = F_33 ( V_14 ) ;
F_1 ( V_8 ) ;
* V_31 = NULL ;
if ( ( V_19 = F_15 ( V_38 , L_6 ) ) != NULL ) {
V_37 = F_24 ( V_38 , V_19 , V_8 ) ;
if ( V_37 != 0 ) {
* V_32 = 0 ;
* V_33 = V_37 ;
* V_31 = V_38 ;
} else
F_3 ( V_38 ) ;
fclose ( V_19 ) ;
} else {
if ( V_22 != V_24 ) {
* V_32 = V_22 ;
* V_33 = 0 ;
* V_31 = V_38 ;
} else
F_3 ( V_38 ) ;
}
V_17 = F_13 ( V_14 , TRUE ) ;
F_1 ( V_7 ) ;
* V_34 = NULL ;
if ( ( V_19 = F_15 ( V_17 , L_6 ) ) != NULL ) {
V_37 = F_24 ( V_17 , V_19 , V_7 ) ;
if ( V_37 != 0 ) {
* V_35 = 0 ;
* V_36 = V_37 ;
* V_34 = V_17 ;
} else
F_3 ( V_17 ) ;
fclose ( V_19 ) ;
} else {
if ( V_22 != V_24 ) {
* V_35 = V_22 ;
* V_36 = 0 ;
* V_34 = V_17 ;
} else
F_3 ( V_17 ) ;
}
}
void
F_34 ( const char * V_5 )
{
T_6 * V_16 ;
int V_39 ;
V_39 = F_7 ( V_5 ) ;
if ( V_39 >= 0 ) {
V_16 = F_18 ( V_39 ) ;
if ( F_35 ( V_16 ) == TRUE ) {
if ( F_8 ( V_39 ) == TRUE ) {
F_9 ( V_39 , FALSE ) ;
}
}
}
}
static T_4 F_36 ( T_6 * V_16 )
{
if ( F_35 ( V_16 ) == FALSE )
return TRUE ;
return FALSE ;
}
T_9 void
F_37 ( const char * V_5 )
{
T_6 * V_16 ;
int V_39 ;
V_39 = F_7 ( V_5 ) ;
if ( V_39 >= 0 ) {
V_16 = F_18 ( V_39 ) ;
if ( ( F_38 ( V_16 ) == FALSE ) &&
( F_35 ( V_16 ) == FALSE ) ) {
if ( F_8 ( V_39 ) == TRUE ) {
F_9 ( V_39 , TRUE ) ;
}
}
}
}
static T_4 F_39 ( T_6 * V_16 )
{
if ( ( F_38 ( V_16 ) == FALSE ) &&
( F_35 ( V_16 ) == TRUE ) )
return TRUE ;
return FALSE ;
}
static void
F_40 ( void )
{
T_1 * V_2 ;
T_3 * V_40 ;
T_10 * V_41 ;
if ( V_42 == NULL )
goto V_11;
V_2 = F_2 ( V_42 ) ;
while ( V_2 != NULL ) {
V_40 = ( T_3 * ) V_2 -> V_4 ;
V_41 = F_41 ( V_40 -> V_5 ) ;
if ( V_41 != NULL ) {
V_41 -> V_43 = V_40 -> V_43 ;
}
V_2 = V_2 -> V_6 ;
}
V_11:
if ( V_44 == NULL )
return;
V_2 = F_2 ( V_44 ) ;
while ( V_2 != NULL ) {
V_40 = ( T_3 * ) V_2 -> V_4 ;
V_41 = F_41 ( V_40 -> V_5 ) ;
if ( V_41 != NULL ) {
V_41 -> V_43 = V_40 -> V_43 ;
}
V_2 = V_2 -> V_6 ;
}
}
static int
F_42 ( const char * V_17 , T_8 * V_19 , T_1 * * V_1 )
{
T_3 * V_40 ;
int V_25 ;
char * V_45 ;
int V_46 ;
int V_47 ;
T_4 V_48 ;
T_4 V_43 ;
int line = 1 ;
V_46 = V_30 ;
V_45 = ( char * ) F_25 ( V_46 + 1 ) ;
for ( line = 1 ; ; line ++ ) {
while ( ( V_25 = F_26 ( V_19 ) ) != V_23 && F_27 ( V_25 ) ) {
if ( V_25 == '\n' ) {
continue;
}
}
if ( V_25 == V_23 ) {
if ( ferror ( V_19 ) )
goto error;
else
break;
}
ungetc ( V_25 , V_19 ) ;
V_47 = 0 ;
V_43 = FALSE ;
V_48 = FALSE ;
for (; ; ) {
V_25 = F_26 ( V_19 ) ;
if ( V_25 == V_23 )
break;
if ( F_27 ( V_25 ) )
break;
if ( V_25 == ',' ) {
V_48 = TRUE ;
continue;
}
if ( V_25 == '#' )
break;
if ( V_48 ) {
V_43 = ( ( V_25 == '1' ) ? TRUE : FALSE ) ;
break;
}
if ( V_47 >= V_46 ) {
V_46 *= 2 ;
V_45 = ( char * ) F_28 ( V_45 , V_46 + 1 ) ;
}
V_45 [ V_47 ] = V_25 ;
V_47 ++ ;
}
if ( F_27 ( V_25 ) && V_25 != '\n' ) {
while ( ( V_25 = F_26 ( V_19 ) ) != V_23 && V_25 != '\n' && F_27 ( V_25 ) )
;
if ( V_25 != V_23 && V_25 != '\n' && V_25 != '#' ) {
F_29 ( L_4 ,
V_17 , line ) ;
}
}
if ( V_25 != V_23 && V_25 != '\n' ) {
while ( ( V_25 = F_26 ( V_19 ) ) != V_23 && V_25 != '\n' )
;
}
if ( V_25 == V_23 ) {
if ( ferror ( V_19 ) )
goto error;
else {
F_29 ( L_5 , V_17 ,
line ) ;
}
break;
}
if ( V_47 >= V_46 ) {
V_46 *= 2 ;
V_45 = ( char * ) F_28 ( V_45 , V_46 + 1 ) ;
}
V_45 [ V_47 ] = '\0' ;
V_40 = ( T_3 * ) F_25 ( sizeof( T_3 ) ) ;
V_40 -> V_5 = F_30 ( V_45 ) ;
V_40 -> V_43 = V_43 ;
* V_1 = F_31 ( * V_1 , V_40 ) ;
}
F_3 ( V_45 ) ;
return 0 ;
error:
F_3 ( V_45 ) ;
return V_22 ;
}
static void
F_43 ( char * * V_31 , int * V_32 ,
int * V_33 ,
char * * V_34 , int * V_35 ,
int * V_36 )
{
int V_37 ;
char * V_38 , * V_17 ;
T_8 * V_19 ;
F_5 ( & V_44 ) ;
V_38 = F_33 ( V_49 ) ;
* V_31 = NULL ;
if ( ( V_19 = F_15 ( V_38 , L_6 ) ) != NULL ) {
V_37 = F_42 ( V_38 , V_19 ,
& V_44 ) ;
if ( V_37 != 0 ) {
* V_32 = 0 ;
* V_33 = V_37 ;
* V_31 = V_38 ;
} else
F_3 ( V_38 ) ;
fclose ( V_19 ) ;
} else {
if ( V_22 != V_24 ) {
* V_32 = V_22 ;
* V_33 = 0 ;
* V_31 = V_38 ;
} else
F_3 ( V_38 ) ;
}
V_17 = F_13 ( V_49 , TRUE ) ;
F_5 ( & V_42 ) ;
* V_34 = NULL ;
if ( ( V_19 = F_15 ( V_17 , L_6 ) ) != NULL ) {
V_37 = F_42 ( V_17 , V_19 , & V_42 ) ;
if ( V_37 != 0 ) {
* V_35 = 0 ;
* V_36 = V_37 ;
* V_34 = V_17 ;
} else
F_3 ( V_17 ) ;
fclose ( V_19 ) ;
} else {
if ( V_22 != V_24 ) {
* V_35 = V_22 ;
* V_36 = 0 ;
* V_34 = V_17 ;
} else
F_3 ( V_17 ) ;
}
}
static T_5
F_44 ( T_11 V_50 , T_11 V_51 )
{
return strcmp ( ( ( const T_10 * ) V_50 ) -> V_52 ,
( ( const T_10 * ) V_51 ) -> V_52 ) ;
}
static void
F_45 ( T_12 V_4 , T_12 V_53 )
{
T_10 * V_54 = ( T_10 * ) V_4 ;
T_8 * V_19 = ( T_8 * ) V_53 ;
fprintf ( V_19 , L_7 , V_54 -> V_52 , V_54 -> V_43 ? 1 : 0 ) ;
}
static void
F_46 ( const char * T_13 V_55 ,
T_10 * V_54 , T_12 V_53 )
{
T_14 * * V_56 = ( T_14 * * ) V_53 ;
* V_56 = F_47 ( * V_56 , V_54 , F_44 ) ;
}
static void
F_48 ( const char * T_13 , struct V_57 * V_56 , T_12 V_58 )
{
if ( V_56 ) {
F_49 ( T_13 , F_46 , V_58 ) ;
}
}
static void
F_50 ( char * * V_12 , int * V_13 )
{
T_7 * V_17 , * V_18 ;
T_14 * V_59 = NULL ;
T_8 * V_19 ;
* V_12 = NULL ;
V_17 = F_13 ( V_49 , TRUE ) ;
V_18 = F_14 ( L_1 , V_17 ) ;
if ( ( V_19 = F_15 ( V_18 , L_2 ) ) == NULL ) {
* V_12 = V_17 ;
* V_13 = V_22 ;
F_3 ( V_18 ) ;
return;
}
F_51 ( F_48 , & V_59 , NULL ) ;
F_52 ( V_59 , F_45 , V_19 ) ;
F_53 ( V_59 ) ;
if ( fclose ( V_19 ) == V_23 ) {
* V_12 = V_17 ;
* V_13 = V_22 ;
F_20 ( V_18 ) ;
F_3 ( V_18 ) ;
return;
}
#ifdef F_21
if ( F_22 ( V_17 ) < 0 && V_22 != V_24 ) {
* V_12 = V_17 ;
* V_13 = V_22 ;
F_20 ( V_18 ) ;
F_3 ( V_18 ) ;
return;
}
#endif
if ( F_23 ( V_18 , V_17 ) < 0 ) {
* V_12 = V_17 ;
* V_13 = V_22 ;
F_20 ( V_18 ) ;
F_3 ( V_18 ) ;
return;
}
F_3 ( V_18 ) ;
F_3 ( V_17 ) ;
}
T_4
F_54 ( const char * V_5 , T_4 V_9 )
{
T_10 * V_40 = F_41 ( V_5 ) ;
if ( V_40 != NULL ) {
V_40 -> V_43 = V_9 ;
return TRUE ;
} else {
return FALSE ;
}
}
static void
F_55 ( T_12 V_60 , T_12 V_53 V_55 )
{
T_2 * V_61 = ( T_2 * ) V_60 ;
F_3 ( V_61 -> V_5 ) ;
F_3 ( V_60 ) ;
}
void
F_56 ( void )
{
char * V_62 , * V_63 ;
int V_64 , V_65 ;
int V_66 , V_67 ;
F_32 ( & V_62 , & V_64 , & V_65 ,
& V_63 , & V_66 , & V_67 ,
V_68 ,
& V_69 , & V_70 ) ;
if ( V_62 != NULL ) {
if ( V_64 != 0 ) {
F_57 ( L_8 ,
V_62 , F_58 ( V_64 ) ) ;
}
if ( V_65 != 0 ) {
F_57 ( L_9 ,
V_62 , F_58 ( V_65 ) ) ;
}
F_3 ( V_62 ) ;
V_62 = NULL ;
}
if ( V_63 != NULL ) {
if ( V_66 != 0 ) {
F_57 ( L_10 ,
V_63 , F_58 ( V_66 ) ) ;
}
if ( V_67 != 0 ) {
F_57 ( L_11 ,
V_63 , F_58 ( V_67 ) ) ;
}
F_3 ( V_63 ) ;
V_63 = NULL ;
}
F_32 ( & V_62 , & V_64 , & V_65 ,
& V_63 , & V_66 , & V_67 ,
V_71 ,
& V_72 , & V_73 ) ;
if ( V_62 != NULL ) {
if ( V_64 != 0 ) {
F_57 ( L_12 ,
V_62 , F_58 ( V_64 ) ) ;
}
if ( V_65 != 0 ) {
F_57 ( L_13 ,
V_62 , F_58 ( V_65 ) ) ;
}
F_3 ( V_62 ) ;
V_62 = NULL ;
}
if ( V_63 != NULL ) {
if ( V_66 != 0 ) {
F_57 ( L_14 ,
V_63 , F_58 ( V_66 ) ) ;
}
if ( V_67 != 0 ) {
F_57 ( L_15 ,
V_63 , F_58 ( V_67 ) ) ;
}
F_3 ( V_63 ) ;
V_63 = NULL ;
}
F_43 ( & V_62 , & V_64 , & V_65 ,
& V_63 , & V_66 , & V_67 ) ;
if ( V_62 != NULL ) {
if ( V_64 != 0 ) {
F_57 ( L_16 ,
V_62 , F_58 ( V_64 ) ) ;
}
if ( V_65 != 0 ) {
F_57 ( L_17 ,
V_62 , F_58 ( V_65 ) ) ;
}
F_3 ( V_62 ) ;
V_62 = NULL ;
}
if ( V_63 != NULL ) {
if ( V_66 != 0 ) {
F_57 ( L_18 ,
V_63 , F_58 ( V_66 ) ) ;
}
if ( V_67 != 0 ) {
F_57 ( L_19 ,
V_63 , F_58 ( V_67 ) ) ;
}
F_3 ( V_63 ) ;
V_63 = NULL ;
}
F_6 ( V_70 , V_69 , FALSE ) ;
F_6 ( V_73 , V_72 , TRUE ) ;
F_40 () ;
}
void
F_59 ( void )
{
char * V_74 ;
char * V_75 ;
int V_76 ;
if ( F_60 ( & V_74 ) == - 1 ) {
F_61 ( L_20 ,
V_74 , F_58 ( V_22 ) ) ;
F_3 ( V_74 ) ;
return;
}
F_11 ( & V_75 , & V_76 , V_68 ,
NULL , F_36 ) ;
if ( V_75 != NULL ) {
F_61 ( L_21 ,
V_75 , F_58 ( V_76 ) ) ;
F_3 ( V_75 ) ;
}
F_11 ( & V_75 , & V_76 , V_71 ,
L_22 ,
F_39 ) ;
if ( V_75 != NULL ) {
F_61 ( L_23 ,
V_75 , F_58 ( V_76 ) ) ;
F_3 ( V_75 ) ;
}
F_50 ( & V_75 , & V_76 ) ;
if ( V_75 != NULL ) {
F_61 ( L_24 ,
V_75 , F_58 ( V_76 ) ) ;
F_3 ( V_75 ) ;
}
}
void
F_62 ( void )
{
F_63 ( V_44 , F_55 , NULL ) ;
F_4 ( V_44 ) ;
F_63 ( V_42 , F_55 , NULL ) ;
F_4 ( V_42 ) ;
F_63 ( V_69 , F_55 , NULL ) ;
F_4 ( V_69 ) ;
F_63 ( V_70 , F_55 , NULL ) ;
F_4 ( V_70 ) ;
}

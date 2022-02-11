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
void
F_6 ( char * * V_7 , int * V_8 ,
int * V_9 ,
char * * V_10 , int * V_11 ,
int * V_12 )
{
int V_13 ;
char * V_14 , * V_15 ;
T_4 * V_16 ;
V_14 = F_7 ( V_17 ) ;
F_1 ( & V_18 ) ;
* V_7 = NULL ;
if ( ( V_16 = F_8 ( V_14 , L_1 ) ) != NULL ) {
V_13 = F_9 ( V_14 , V_16 ,
& V_18 ) ;
if ( V_13 != 0 ) {
* V_8 = 0 ;
* V_9 = V_13 ;
* V_7 = V_14 ;
} else
F_3 ( V_14 ) ;
fclose ( V_16 ) ;
} else {
if ( V_19 != V_20 ) {
* V_8 = V_19 ;
* V_9 = 0 ;
* V_7 = V_14 ;
} else
F_3 ( V_14 ) ;
}
V_15 = F_10 ( V_17 , TRUE ) ;
F_1 ( & V_21 ) ;
* V_10 = NULL ;
if ( ( V_16 = F_8 ( V_15 , L_1 ) ) != NULL ) {
V_13 = F_9 ( V_15 , V_16 , & V_21 ) ;
if ( V_13 != 0 ) {
* V_11 = 0 ;
* V_12 = V_13 ;
* V_10 = V_15 ;
} else
F_3 ( V_15 ) ;
fclose ( V_16 ) ;
} else {
if ( V_19 != V_20 ) {
* V_11 = V_19 ;
* V_12 = 0 ;
* V_10 = V_15 ;
} else
F_3 ( V_15 ) ;
}
}
static int
F_9 ( const char * V_15 , T_4 * V_16 ,
T_1 * * V_1 )
{
T_2 * V_3 ;
int V_22 ;
char * V_23 ;
int V_24 ;
int V_25 ;
int line = 1 ;
V_24 = V_26 ;
V_23 = ( char * ) F_11 ( V_24 + 1 ) ;
for ( line = 1 ; ; line ++ ) {
while ( ( V_22 = F_12 ( V_16 ) ) != V_27 && F_13 ( V_22 ) ) {
if ( V_22 == '\n' ) {
continue;
}
}
if ( V_22 == V_27 ) {
if ( ferror ( V_16 ) )
goto error;
else
break;
}
ungetc ( V_22 , V_16 ) ;
V_25 = 0 ;
for (; ; ) {
V_22 = F_12 ( V_16 ) ;
if ( V_22 == V_27 )
break;
if ( F_13 ( V_22 ) )
break;
if ( V_22 == '#' )
break;
if ( V_25 >= V_24 ) {
V_24 *= 2 ;
V_23 = ( char * ) F_14 ( V_23 , V_24 + 1 ) ;
}
V_23 [ V_25 ] = V_22 ;
V_25 ++ ;
}
if ( F_13 ( V_22 ) && V_22 != '\n' ) {
while ( ( V_22 = F_12 ( V_16 ) ) != V_27 && V_22 != '\n' && F_13 ( V_22 ) )
;
if ( V_22 != V_27 && V_22 != '\n' && V_22 != '#' ) {
F_15 ( L_2 ,
V_15 , line ) ;
}
}
if ( V_22 != V_27 && V_22 != '\n' ) {
while ( ( V_22 = F_12 ( V_16 ) ) != V_27 && V_22 != '\n' )
;
}
if ( V_22 == V_27 ) {
if ( ferror ( V_16 ) )
goto error;
else {
F_15 ( L_3 , V_15 ,
line ) ;
}
break;
}
if ( V_25 >= V_24 ) {
V_24 *= 2 ;
V_23 = ( char * ) F_14 ( V_23 , V_24 + 1 ) ;
}
V_23 [ V_25 ] = '\0' ;
V_3 = ( T_2 * ) F_11 ( sizeof( T_2 ) ) ;
V_3 -> V_5 = F_16 ( V_23 ) ;
* V_1 = F_17 ( * V_1 , V_3 ) ;
}
F_3 ( V_23 ) ;
return 0 ;
error:
F_3 ( V_23 ) ;
return V_19 ;
}
void
F_18 ( void )
{
T_5 V_28 ;
T_1 * V_2 ;
T_2 * V_3 ;
if ( V_21 == NULL )
goto V_29;
V_2 = F_2 ( V_21 ) ;
while ( V_2 != NULL ) {
V_3 = ( T_2 * ) V_2 -> V_4 ;
V_28 = F_19 ( V_3 -> V_5 ) ;
if ( V_28 == - 1 ) {
} else {
if ( F_20 ( V_28 ) )
F_21 ( V_28 , FALSE ) ;
}
V_2 = V_2 -> V_6 ;
}
V_29:
if ( V_18 == NULL )
return;
V_2 = F_2 ( V_18 ) ;
while ( V_2 != NULL ) {
V_3 = ( T_2 * ) V_2 -> V_4 ;
V_28 = F_19 ( V_3 -> V_5 ) ;
if ( V_28 == - 1 ) {
} else {
if ( F_20 ( V_28 ) ) {
F_21 ( V_28 , FALSE ) ;
F_22 ( V_28 ) ;
}
}
V_2 = V_2 -> V_6 ;
}
}
void
F_23 ( const char * V_5 )
{
T_6 * V_30 ;
int V_31 ;
V_31 = F_19 ( V_5 ) ;
if ( V_31 >= 0 ) {
V_30 = F_24 ( V_31 ) ;
if ( F_25 ( V_30 ) == TRUE ) {
if ( F_20 ( V_31 ) == TRUE ) {
F_21 ( V_31 , FALSE ) ;
}
}
}
}
void
F_26 ( char * * V_32 , int * V_33 )
{
T_7 * V_15 , * V_34 ;
T_4 * V_16 ;
T_5 V_28 ;
T_6 * V_30 ;
void * V_35 ;
* V_32 = NULL ;
V_15 = F_10 ( V_17 , TRUE ) ;
V_34 = F_27 ( L_4 , V_15 ) ;
if ( ( V_16 = F_8 ( V_34 , L_5 ) ) == NULL ) {
* V_32 = V_15 ;
* V_33 = V_19 ;
F_3 ( V_34 ) ;
return;
}
for ( V_28 = F_28 ( & V_35 ) ; V_28 != - 1 ;
V_28 = F_29 ( & V_35 ) ) {
if ( ! F_20 ( V_28 ) ) {
continue;
}
V_30 = F_24 ( V_28 ) ;
if ( F_25 ( V_30 ) ) {
continue;
}
fprintf ( V_16 , L_6 , F_30 ( V_28 ) ) ;
}
if ( fclose ( V_16 ) == V_27 ) {
* V_32 = V_15 ;
* V_33 = V_19 ;
F_31 ( V_34 ) ;
F_3 ( V_34 ) ;
return;
}
#ifdef F_32
if ( F_33 ( V_15 ) < 0 && V_19 != V_20 ) {
* V_32 = V_15 ;
* V_33 = V_19 ;
F_31 ( V_34 ) ;
F_3 ( V_34 ) ;
return;
}
#endif
if ( F_34 ( V_34 , V_15 ) < 0 ) {
* V_32 = V_15 ;
* V_33 = V_19 ;
F_31 ( V_34 ) ;
F_3 ( V_34 ) ;
return;
}
F_3 ( V_34 ) ;
F_3 ( V_15 ) ;
}
void
F_35 ( void )
{
T_1 * V_2 ;
T_3 * V_36 ;
T_8 * V_37 ;
if ( V_38 == NULL )
goto V_29;
V_2 = F_2 ( V_38 ) ;
while ( V_2 != NULL ) {
V_36 = ( T_3 * ) V_2 -> V_4 ;
V_37 = F_36 ( V_36 -> V_5 ) ;
if ( V_37 != NULL ) {
V_37 -> V_39 = V_36 -> V_39 ;
}
V_2 = V_2 -> V_6 ;
}
V_29:
if ( V_40 == NULL )
return;
V_2 = F_2 ( V_40 ) ;
while ( V_2 != NULL ) {
V_36 = ( T_3 * ) V_2 -> V_4 ;
V_37 = F_36 ( V_36 -> V_5 ) ;
if ( V_37 != NULL ) {
V_37 -> V_39 = V_36 -> V_39 ;
}
V_2 = V_2 -> V_6 ;
}
}
static int
F_37 ( const char * V_15 , T_4 * V_16 ,
T_1 * * V_1 )
{
T_3 * V_36 ;
int V_22 ;
char * V_41 ;
int V_42 ;
int V_43 ;
T_9 V_44 ;
T_9 V_39 ;
int line = 1 ;
V_42 = V_26 ;
V_41 = ( char * ) F_11 ( V_42 + 1 ) ;
for ( line = 1 ; ; line ++ ) {
while ( ( V_22 = F_12 ( V_16 ) ) != V_27 && F_13 ( V_22 ) ) {
if ( V_22 == '\n' ) {
continue;
}
}
if ( V_22 == V_27 ) {
if ( ferror ( V_16 ) )
goto error;
else
break;
}
ungetc ( V_22 , V_16 ) ;
V_43 = 0 ;
V_39 = FALSE ;
V_44 = FALSE ;
for (; ; ) {
V_22 = F_12 ( V_16 ) ;
if ( V_22 == V_27 )
break;
if ( F_13 ( V_22 ) )
break;
if ( V_22 == ',' ) {
V_44 = TRUE ;
continue;
}
if ( V_22 == '#' )
break;
if ( V_44 ) {
V_39 = ( ( V_22 == '1' ) ? TRUE : FALSE ) ;
break;
}
if ( V_43 >= V_42 ) {
V_42 *= 2 ;
V_41 = ( char * ) F_14 ( V_41 , V_42 + 1 ) ;
}
V_41 [ V_43 ] = V_22 ;
V_43 ++ ;
}
if ( F_13 ( V_22 ) && V_22 != '\n' ) {
while ( ( V_22 = F_12 ( V_16 ) ) != V_27 && V_22 != '\n' && F_13 ( V_22 ) )
;
if ( V_22 != V_27 && V_22 != '\n' && V_22 != '#' ) {
F_15 ( L_2 ,
V_15 , line ) ;
}
}
if ( V_22 != V_27 && V_22 != '\n' ) {
while ( ( V_22 = F_12 ( V_16 ) ) != V_27 && V_22 != '\n' )
;
}
if ( V_22 == V_27 ) {
if ( ferror ( V_16 ) )
goto error;
else {
F_15 ( L_3 , V_15 ,
line ) ;
}
break;
}
if ( V_43 >= V_42 ) {
V_42 *= 2 ;
V_41 = ( char * ) F_14 ( V_41 , V_42 + 1 ) ;
}
V_41 [ V_43 ] = '\0' ;
V_36 = ( T_3 * ) F_11 ( sizeof( T_3 ) ) ;
V_36 -> V_5 = F_16 ( V_41 ) ;
V_36 -> V_39 = V_39 ;
* V_1 = F_17 ( * V_1 , V_36 ) ;
}
F_3 ( V_41 ) ;
return 0 ;
error:
F_3 ( V_41 ) ;
return V_19 ;
}
void
F_38 ( char * * V_7 , int * V_8 ,
int * V_9 ,
char * * V_10 , int * V_11 ,
int * V_12 )
{
int V_13 ;
char * V_14 , * V_15 ;
T_4 * V_16 ;
V_14 = F_7 ( V_45 ) ;
F_5 ( & V_40 ) ;
* V_7 = NULL ;
if ( ( V_16 = F_8 ( V_14 , L_1 ) ) != NULL ) {
V_13 = F_37 ( V_14 , V_16 ,
& V_40 ) ;
if ( V_13 != 0 ) {
* V_8 = 0 ;
* V_9 = V_13 ;
* V_7 = V_14 ;
} else
F_3 ( V_14 ) ;
fclose ( V_16 ) ;
} else {
if ( V_19 != V_20 ) {
* V_8 = V_19 ;
* V_9 = 0 ;
* V_7 = V_14 ;
} else
F_3 ( V_14 ) ;
}
V_15 = F_10 ( V_45 , TRUE ) ;
F_5 ( & V_38 ) ;
* V_10 = NULL ;
if ( ( V_16 = F_8 ( V_15 , L_1 ) ) != NULL ) {
V_13 = F_37 ( V_15 , V_16 , & V_38 ) ;
if ( V_13 != 0 ) {
* V_11 = 0 ;
* V_12 = V_13 ;
* V_10 = V_15 ;
} else
F_3 ( V_15 ) ;
fclose ( V_16 ) ;
} else {
if ( V_19 != V_20 ) {
* V_11 = V_19 ;
* V_12 = 0 ;
* V_10 = V_15 ;
} else
F_3 ( V_15 ) ;
}
}
static T_5
F_39 ( T_10 V_46 , T_10 V_47 )
{
return strcmp ( ( ( const T_8 * ) V_46 ) -> V_48 ,
( ( const T_8 * ) V_47 ) -> V_48 ) ;
}
static void
F_40 ( T_11 V_4 , T_11 V_49 )
{
T_8 * V_50 = ( T_8 * ) V_4 ;
T_4 * V_16 = ( T_4 * ) V_49 ;
fprintf ( V_16 , L_7 , V_50 -> V_48 , V_50 -> V_39 ? 1 : 0 ) ;
}
static void
F_41 ( const char * T_12 V_51 ,
T_8 * V_50 , T_11 V_49 )
{
T_13 * * V_52 = ( T_13 * * ) V_49 ;
* V_52 = F_42 ( * V_52 , V_50 , F_39 ) ;
}
static void
F_43 ( const char * T_12 , struct V_53 * V_52 , T_11 V_54 )
{
if ( V_52 ) {
F_44 ( T_12 , F_41 , V_54 ) ;
}
}
T_14 void
F_45 ( char * * V_32 , int * V_33 )
{
T_7 * V_15 , * V_34 ;
T_13 * V_55 = NULL ;
T_4 * V_16 ;
* V_32 = NULL ;
V_15 = F_10 ( V_45 , TRUE ) ;
V_34 = F_27 ( L_4 , V_15 ) ;
if ( ( V_16 = F_8 ( V_34 , L_5 ) ) == NULL ) {
* V_32 = V_15 ;
* V_33 = V_19 ;
F_3 ( V_34 ) ;
return;
}
F_46 ( F_43 , & V_55 , NULL ) ;
F_47 ( V_55 , F_40 , V_16 ) ;
F_48 ( V_55 ) ;
if ( fclose ( V_16 ) == V_27 ) {
* V_32 = V_15 ;
* V_33 = V_19 ;
F_31 ( V_34 ) ;
F_3 ( V_34 ) ;
return;
}
#ifdef F_32
if ( F_33 ( V_15 ) < 0 && V_19 != V_20 ) {
* V_32 = V_15 ;
* V_33 = V_19 ;
F_31 ( V_34 ) ;
F_3 ( V_34 ) ;
return;
}
#endif
if ( F_34 ( V_34 , V_15 ) < 0 ) {
* V_32 = V_15 ;
* V_33 = V_19 ;
F_31 ( V_34 ) ;
F_3 ( V_34 ) ;
return;
}
F_3 ( V_34 ) ;
F_3 ( V_15 ) ;
}
void
F_49 ( const char * V_5 , T_9 V_56 )
{
T_8 * V_36 = F_36 ( V_5 ) ;
if ( V_36 != NULL ) {
V_36 -> V_39 = V_56 ;
}
}

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
void
F_5 ( char * * V_7 , int * V_8 ,
int * V_9 ,
char * * V_10 , int * V_11 ,
int * V_12 )
{
int V_13 ;
char * V_14 , * V_15 ;
T_3 * V_16 ;
V_14 = F_6 ( V_17 ) ;
F_1 ( & V_18 ) ;
* V_7 = NULL ;
if ( ( V_16 = F_7 ( V_14 , L_1 ) ) != NULL ) {
V_13 = F_8 ( V_14 , V_16 ,
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
V_15 = F_9 ( V_21 , TRUE ) ;
F_1 ( & V_22 ) ;
* V_10 = NULL ;
if ( ( V_16 = F_7 ( V_15 , L_1 ) ) != NULL ) {
V_13 = F_8 ( V_15 , V_16 , & V_22 ) ;
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
F_8 ( const char * V_15 , T_3 * V_16 ,
T_1 * * V_1 )
{
T_2 * V_3 ;
int V_23 ;
char * V_24 ;
int V_25 ;
int V_26 ;
int line = 1 ;
V_25 = V_27 ;
V_24 = ( char * ) F_10 ( V_25 + 1 ) ;
for ( line = 1 ; ; line ++ ) {
while ( ( V_23 = getc ( V_16 ) ) != V_28 && isspace ( V_23 ) ) {
if ( V_23 == '\n' ) {
continue;
}
}
if ( V_23 == V_28 ) {
if ( ferror ( V_16 ) )
goto error;
else
break;
}
ungetc ( V_23 , V_16 ) ;
V_26 = 0 ;
for (; ; ) {
V_23 = getc ( V_16 ) ;
if ( V_23 == V_28 )
break;
if ( isspace ( V_23 ) )
break;
if ( V_23 == '#' )
break;
if ( V_26 >= V_25 ) {
V_25 *= 2 ;
V_24 = ( char * ) F_11 ( V_24 , V_25 + 1 ) ;
}
V_24 [ V_26 ] = V_23 ;
V_26 ++ ;
}
if ( isspace ( V_23 ) && V_23 != '\n' ) {
while ( ( V_23 = getc ( V_16 ) ) != V_28 && V_23 != '\n' && isspace ( V_23 ) )
;
if ( V_23 != V_28 && V_23 != '\n' && V_23 != '#' ) {
F_12 ( L_2 ,
V_15 , line ) ;
}
}
if ( V_23 != V_28 && V_23 != '\n' ) {
while ( ( V_23 = getc ( V_16 ) ) != V_28 && V_23 != '\n' )
;
}
if ( V_23 == V_28 ) {
if ( ferror ( V_16 ) )
goto error;
else {
F_12 ( L_3 , V_15 ,
line ) ;
}
break;
}
if ( V_26 >= V_25 ) {
V_25 *= 2 ;
V_24 = ( char * ) F_11 ( V_24 , V_25 + 1 ) ;
}
V_24 [ V_26 ] = '\0' ;
V_3 = ( T_2 * ) F_10 ( sizeof( T_2 ) ) ;
V_3 -> V_5 = F_13 ( V_24 ) ;
* V_1 = F_14 ( * V_1 , V_3 ) ;
}
F_3 ( V_24 ) ;
return 0 ;
error:
return V_19 ;
}
void
F_15 ( void )
{
T_4 V_29 ;
T_1 * V_2 ;
T_2 * V_3 ;
if ( V_22 == NULL )
goto V_30;
V_2 = F_2 ( V_22 ) ;
while ( V_2 != NULL ) {
V_3 = ( T_2 * ) V_2 -> V_4 ;
V_29 = F_16 ( V_3 -> V_5 ) ;
if ( V_29 == - 1 ) {
} else {
if ( F_17 ( V_29 ) )
F_18 ( V_29 , FALSE ) ;
}
V_2 = V_2 -> V_6 ;
}
V_30:
if ( V_18 == NULL )
return;
V_2 = F_2 ( V_18 ) ;
while ( V_2 != NULL ) {
V_3 = ( T_2 * ) V_2 -> V_4 ;
V_29 = F_16 ( V_3 -> V_5 ) ;
if ( V_29 == - 1 ) {
} else {
if ( F_17 ( V_29 ) ) {
F_18 ( V_29 , FALSE ) ;
F_19 ( V_29 ) ;
}
}
V_2 = V_2 -> V_6 ;
}
}
void
F_20 ( char * * V_31 , int * V_32 )
{
T_5 * V_15 , * V_33 ;
T_3 * V_16 ;
T_4 V_29 ;
T_6 * V_34 ;
void * V_35 ;
* V_31 = NULL ;
V_15 = F_9 ( V_21 , TRUE ) ;
V_33 = F_21 ( L_4 , V_15 ) ;
if ( ( V_16 = F_7 ( V_33 , L_5 ) ) == NULL ) {
* V_31 = V_15 ;
* V_32 = V_19 ;
F_3 ( V_33 ) ;
return;
}
for ( V_29 = F_22 ( & V_35 ) ; V_29 != - 1 ;
V_29 = F_23 ( & V_35 ) ) {
if ( ! F_17 ( V_29 ) ) {
continue;
}
V_34 = F_24 ( V_29 ) ;
if ( F_25 ( V_34 ) ) {
continue;
}
fprintf ( V_16 , L_6 , F_26 ( V_29 ) ) ;
}
if ( fclose ( V_16 ) == V_28 ) {
* V_31 = V_15 ;
* V_32 = V_19 ;
F_27 ( V_33 ) ;
F_3 ( V_33 ) ;
return;
}
#ifdef F_28
if ( F_29 ( V_15 ) < 0 && V_19 != V_20 ) {
* V_31 = V_15 ;
* V_32 = V_19 ;
F_27 ( V_33 ) ;
F_3 ( V_33 ) ;
return;
}
#endif
if ( F_30 ( V_33 , V_15 ) < 0 ) {
* V_31 = V_15 ;
* V_32 = V_19 ;
F_27 ( V_33 ) ;
F_3 ( V_33 ) ;
return;
}
F_3 ( V_33 ) ;
F_3 ( V_15 ) ;
}

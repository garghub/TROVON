static T_1 *
F_1 ( T_1 * V_1 , const char * V_2 , const char * V_3 )
{
T_2 * V_4 ;
V_4 = ( T_2 * ) F_2 ( sizeof( T_2 ) ) ;
V_4 -> V_5 = F_3 ( V_2 ) ;
V_4 -> V_6 = F_3 ( V_3 ) ;
return F_4 ( V_1 , V_4 ) ;
}
static T_1 *
F_5 ( T_1 * V_1 , T_1 * V_7 )
{
T_2 * V_4 ;
V_4 = ( T_2 * ) V_7 -> V_8 ;
F_6 ( V_4 -> V_5 ) ;
F_6 ( V_4 -> V_6 ) ;
F_6 ( V_4 ) ;
return F_7 ( V_1 , V_7 ) ;
}
void
F_8 ( T_3 V_9 , char * * V_10 ,
int * V_11 )
{
const char * V_12 ;
char * V_13 ;
T_4 * V_14 ;
T_1 * * V_15 ;
int V_16 ;
char * V_2 , * V_3 ;
int V_17 , V_18 ;
int V_19 , V_20 ;
int line = 1 ;
* V_10 = NULL ;
switch ( V_9 ) {
case V_21 :
V_12 = V_22 ;
V_15 = & V_23 ;
break;
case V_24 :
V_12 = V_25 ;
V_15 = & V_26 ;
break;
default:
F_9 () ;
return;
}
V_13 = F_10 ( V_12 , TRUE , FALSE ) ;
if ( ( V_14 = F_11 ( V_13 , L_1 ) ) == NULL ) {
if ( V_27 != V_28 ) {
* V_10 = V_13 ;
* V_11 = V_27 ;
return;
}
F_6 ( V_13 ) ;
V_13 = F_10 ( V_29 , FALSE , FALSE ) ;
if ( ( V_14 = F_11 ( V_13 , L_1 ) ) == NULL ) {
if ( V_27 != V_28 ) {
* V_10 = V_13 ;
* V_11 = V_27 ;
return;
}
F_6 ( V_13 ) ;
V_13 = F_12 ( V_12 ) ;
if ( ( V_14 = F_11 ( V_13 , L_1 ) ) == NULL ) {
if ( V_27 != V_28 ) {
* V_10 = V_13 ;
* V_11 = V_27 ;
} else {
F_6 ( V_13 ) ;
}
return;
}
}
}
while( * V_15 ) {
* V_15 = F_5 ( * V_15 , F_13 ( * V_15 ) ) ;
}
V_17 = V_30 ;
V_2 = ( char * ) F_2 ( V_17 + 1 ) ;
V_18 = V_30 ;
V_3 = ( char * ) F_2 ( V_18 + 1 ) ;
for ( line = 1 ; ; line ++ ) {
while ( ( V_16 = getc ( V_14 ) ) != V_31 && isspace ( V_16 ) ) {
if ( V_16 == '\n' ) {
continue;
}
}
if ( V_16 == V_31 )
break;
if ( V_16 != '"' ) {
F_14 ( L_2 , V_13 ,
line ) ;
while ( V_16 != '\n' )
V_16 = getc ( V_14 ) ;
continue;
}
V_19 = 0 ;
for (; ; ) {
V_16 = getc ( V_14 ) ;
if ( V_16 == V_31 || V_16 == '\n' )
break;
if ( V_16 == '"' ) {
if ( V_19 >= V_17 ) {
V_17 *= 2 ;
V_2 = ( char * ) F_15 ( V_2 , V_17 + 1 ) ;
}
V_2 [ V_19 ] = '\0' ;
break;
}
if ( V_16 == '\\' ) {
V_16 = getc ( V_14 ) ;
if ( V_16 == V_31 || V_16 == '\n' )
break;
}
if ( V_19 >= V_17 ) {
V_17 *= 2 ;
V_2 = ( char * ) F_15 ( V_2 , V_17 + 1 ) ;
}
V_2 [ V_19 ] = V_16 ;
V_19 ++ ;
}
if ( V_16 == V_31 ) {
if ( ! ferror ( V_14 ) ) {
F_14 ( L_3 , V_13 ,
line ) ;
}
break;
}
if ( V_16 != '"' ) {
F_14 ( L_4 , V_13 ,
line ) ;
continue;
}
while ( ( V_16 = getc ( V_14 ) ) != V_31 && isspace ( V_16 ) ) {
if ( V_16 == '\n' )
break;
}
if ( V_16 == V_31 ) {
if ( ! ferror ( V_14 ) ) {
F_14 ( L_3 , V_13 ,
line ) ;
}
break;
}
if ( V_16 == '\n' ) {
F_14 ( L_5 , V_13 ,
line ) ;
continue;
}
V_20 = 0 ;
for (; ; ) {
if ( V_20 >= V_18 ) {
V_18 *= 2 ;
V_3 = ( char * ) F_15 ( V_3 , V_18 + 1 ) ;
}
V_3 [ V_20 ] = V_16 ;
V_20 ++ ;
V_16 = getc ( V_14 ) ;
if ( V_16 == V_31 || V_16 == '\n' )
break;
}
if ( V_16 == V_31 ) {
if ( ! ferror ( V_14 ) ) {
F_14 ( L_3 , V_13 ,
line ) ;
}
break;
}
if ( V_20 >= V_18 ) {
V_18 *= 2 ;
V_3 = ( char * ) F_15 ( V_3 , V_18 + 1 ) ;
}
V_3 [ V_20 ] = '\0' ;
* V_15 = F_1 ( * V_15 , V_2 , V_3 ) ;
}
if ( ferror ( V_14 ) ) {
* V_10 = V_13 ;
* V_11 = V_27 ;
} else
F_6 ( V_13 ) ;
fclose ( V_14 ) ;
F_6 ( V_2 ) ;
F_6 ( V_3 ) ;
switch ( V_9 ) {
case V_21 :
F_16 ( V_32 , V_21 ) ;
break;
case V_24 :
F_16 ( V_33 , V_24 ) ;
break;
default:
F_9 () ;
return;
}
}
static T_1 * *
F_17 ( T_3 V_9 )
{
T_1 * * V_15 ;
switch ( V_9 ) {
case V_21 :
V_15 = & V_23 ;
break;
case V_24 :
V_15 = & V_26 ;
break;
case V_32 :
V_15 = & V_34 ;
break;
case V_33 :
V_15 = & V_35 ;
break;
default:
F_9 () ;
V_15 = NULL ;
}
return V_15 ;
}
T_1 *
F_18 ( T_3 V_9 )
{
T_1 * * V_15 ;
V_15 = F_17 ( V_9 ) ;
return F_13 ( * V_15 ) ;
}
T_1 *
F_19 ( T_3 V_9 , const char * V_5 ,
const char * V_36 )
{
T_1 * * V_15 ;
V_15 = F_17 ( V_9 ) ;
* V_15 = F_1 ( * V_15 , V_5 , V_36 ) ;
return F_20 ( * V_15 ) ;
}
void
F_21 ( T_3 V_9 , T_1 * V_7 )
{
T_1 * * V_15 ;
V_15 = F_17 ( V_9 ) ;
* V_15 = F_5 ( * V_15 , V_7 ) ;
}
void
F_22 ( T_3 V_9 , char * * V_10 ,
int * V_11 )
{
const T_5 * V_12 ;
T_5 * V_13 , * V_37 ;
T_1 * V_1 ;
T_1 * V_15 ;
T_2 * V_4 ;
T_4 * V_14 ;
T_6 * V_38 , V_16 ;
* V_10 = NULL ;
switch ( V_9 ) {
case V_21 :
V_12 = V_22 ;
V_1 = V_23 ;
break;
case V_24 :
V_12 = V_25 ;
V_1 = V_26 ;
break;
default:
F_9 () ;
return;
}
V_13 = F_10 ( V_12 , TRUE , TRUE ) ;
V_37 = F_23 ( L_6 , V_13 ) ;
if ( ( V_14 = F_11 ( V_37 , L_7 ) ) == NULL ) {
* V_10 = V_13 ;
* V_11 = V_27 ;
F_6 ( V_37 ) ;
return;
}
V_15 = F_13 ( V_1 ) ;
while ( V_15 ) {
V_4 = ( T_2 * ) V_15 -> V_8 ;
putc ( '"' , V_14 ) ;
for ( V_38 = ( T_6 * ) V_4 -> V_5 ; ( V_16 = * V_38 ) != '\0' ; V_38 ++ ) {
if ( V_16 == '"' || V_16 == '\\' )
putc ( '\\' , V_14 ) ;
putc ( V_16 , V_14 ) ;
}
putc ( '"' , V_14 ) ;
putc ( ' ' , V_14 ) ;
fprintf ( V_14 , L_8 , V_4 -> V_6 ) ;
if ( ferror ( V_14 ) ) {
* V_10 = V_13 ;
* V_11 = V_27 ;
fclose ( V_14 ) ;
F_24 ( V_37 ) ;
F_6 ( V_37 ) ;
return;
}
V_15 = V_15 -> V_39 ;
}
if ( fclose ( V_14 ) == V_31 ) {
* V_10 = V_13 ;
* V_11 = V_27 ;
F_24 ( V_37 ) ;
F_6 ( V_37 ) ;
return;
}
#ifdef F_25
if ( F_26 ( V_13 ) < 0 && V_27 != V_28 ) {
* V_10 = V_13 ;
* V_11 = V_27 ;
F_24 ( V_37 ) ;
F_6 ( V_37 ) ;
return;
}
#endif
if ( F_27 ( V_37 , V_13 ) < 0 ) {
* V_10 = V_13 ;
* V_11 = V_27 ;
F_24 ( V_37 ) ;
F_6 ( V_37 ) ;
return;
}
F_6 ( V_37 ) ;
F_6 ( V_13 ) ;
}
void F_16 ( T_3 V_40 , T_3 V_41 )
{
T_1 * * V_42 ;
T_1 * * V_43 ;
T_1 * V_44 ;
T_2 * V_4 ;
F_28 ( V_40 != V_41 ) ;
V_42 = F_17 ( V_40 ) ;
V_43 = F_17 ( V_41 ) ;
while( * V_42 ) {
* V_42 = F_5 ( * V_42 , F_13 ( * V_42 ) ) ;
}
F_28 ( F_29 ( * V_42 ) == 0 ) ;
for( V_44 = F_13 ( * V_43 ) ; V_44 ; V_44 = F_30 ( V_44 ) ) {
V_4 = ( T_2 * ) ( V_44 -> V_8 ) ;
* V_42 = F_1 ( * V_42 , V_4 -> V_5 , V_4 -> V_6 ) ;
}
}

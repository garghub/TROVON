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
static int
F_8 ( T_3 * V_9 )
{
int V_10 ;
while ( ( V_10 = getc ( V_9 ) ) != V_11 && V_10 != '\n' && F_9 ( V_10 ) )
;
return V_10 ;
}
static int
F_10 ( T_3 * V_9 )
{
int V_10 ;
V_10 = getc ( V_9 ) ;
if ( V_10 == '\r' ) {
V_10 = getc ( V_9 ) ;
if ( V_10 != V_11 && V_10 != '\n' ) {
ungetc ( V_10 , V_9 ) ;
V_10 = '\r' ;
}
}
return V_10 ;
}
void
F_11 ( T_4 V_12 , char * * V_13 ,
int * V_14 )
{
const char * V_15 ;
char * V_16 ;
T_3 * V_9 ;
T_1 * * V_17 ;
int V_10 ;
char * V_2 , * V_3 ;
int V_18 , V_19 ;
int V_20 , V_21 ;
int line = 1 ;
* V_13 = NULL ;
switch ( V_12 ) {
case V_22 :
V_15 = V_23 ;
V_17 = & V_24 ;
break;
case V_25 :
V_15 = V_26 ;
V_17 = & V_27 ;
break;
default:
F_12 () ;
return;
}
V_16 = F_13 ( V_15 , TRUE ) ;
if ( ( V_9 = F_14 ( V_16 , L_1 ) ) == NULL ) {
if ( V_28 != V_29 ) {
* V_13 = V_16 ;
* V_14 = V_28 ;
return;
}
F_6 ( V_16 ) ;
V_16 = F_13 ( V_30 , FALSE ) ;
if ( ( V_9 = F_14 ( V_16 , L_1 ) ) == NULL ) {
if ( V_28 != V_29 ) {
* V_13 = V_16 ;
* V_14 = V_28 ;
return;
}
F_6 ( V_16 ) ;
V_16 = F_15 ( V_15 ) ;
if ( ( V_9 = F_14 ( V_16 , L_1 ) ) == NULL ) {
if ( V_28 != V_29 ) {
* V_13 = V_16 ;
* V_14 = V_28 ;
} else {
F_6 ( V_16 ) ;
}
return;
}
}
}
while( * V_17 ) {
* V_17 = F_5 ( * V_17 , F_16 ( * V_17 ) ) ;
}
V_18 = V_31 ;
V_2 = ( char * ) F_2 ( V_18 + 1 ) ;
V_19 = V_31 ;
V_3 = ( char * ) F_2 ( V_19 + 1 ) ;
for ( line = 1 ; ; line ++ ) {
V_10 = F_8 ( V_9 ) ;
if ( V_10 == V_11 )
break;
if ( V_10 == '\n' )
continue;
if ( V_10 != '"' ) {
F_17 ( L_2 , V_16 ,
line ) ;
while ( V_10 != '\n' )
V_10 = getc ( V_9 ) ;
continue;
}
V_20 = 0 ;
for (; ; ) {
V_10 = F_10 ( V_9 ) ;
if ( V_10 == V_11 || V_10 == '\n' )
break;
if ( V_10 == '"' ) {
if ( V_20 >= V_18 ) {
V_18 *= 2 ;
V_2 = ( char * ) F_18 ( V_2 , V_18 + 1 ) ;
}
V_2 [ V_20 ] = '\0' ;
break;
}
if ( V_10 == '\\' ) {
V_10 = F_10 ( V_9 ) ;
if ( V_10 == V_11 || V_10 == '\n' )
break;
}
if ( V_20 >= V_18 ) {
V_18 *= 2 ;
V_2 = ( char * ) F_18 ( V_2 , V_18 + 1 ) ;
}
V_2 [ V_20 ] = V_10 ;
V_20 ++ ;
}
if ( V_10 == V_11 ) {
if ( ! ferror ( V_9 ) ) {
F_17 ( L_3 , V_16 ,
line ) ;
}
break;
}
if ( V_10 != '"' ) {
F_17 ( L_4 , V_16 ,
line ) ;
continue;
}
V_10 = F_8 ( V_9 ) ;
if ( V_10 == V_11 ) {
if ( ! ferror ( V_9 ) ) {
F_17 ( L_3 , V_16 ,
line ) ;
}
break;
}
if ( V_10 == '\n' ) {
F_17 ( L_5 , V_16 ,
line ) ;
continue;
}
V_21 = 0 ;
for (; ; ) {
if ( V_21 >= V_19 ) {
V_19 *= 2 ;
V_3 = ( char * ) F_18 ( V_3 , V_19 + 1 ) ;
}
V_3 [ V_21 ] = V_10 ;
V_21 ++ ;
V_10 = F_10 ( V_9 ) ;
if ( V_10 == V_11 || V_10 == '\n' )
break;
}
if ( V_10 == V_11 ) {
if ( ! ferror ( V_9 ) ) {
F_17 ( L_3 , V_16 ,
line ) ;
}
break;
}
if ( V_21 >= V_19 ) {
V_19 *= 2 ;
V_3 = ( char * ) F_18 ( V_3 , V_19 + 1 ) ;
}
V_3 [ V_21 ] = '\0' ;
* V_17 = F_1 ( * V_17 , V_2 , V_3 ) ;
}
if ( ferror ( V_9 ) ) {
* V_13 = V_16 ;
* V_14 = V_28 ;
} else
F_6 ( V_16 ) ;
fclose ( V_9 ) ;
F_6 ( V_2 ) ;
F_6 ( V_3 ) ;
switch ( V_12 ) {
case V_22 :
F_19 ( V_32 , V_22 ) ;
break;
case V_25 :
F_19 ( V_33 , V_25 ) ;
break;
default:
F_12 () ;
return;
}
}
static T_1 * *
F_20 ( T_4 V_12 )
{
T_1 * * V_17 ;
switch ( V_12 ) {
case V_22 :
V_17 = & V_24 ;
break;
case V_25 :
V_17 = & V_27 ;
break;
case V_32 :
V_17 = & V_34 ;
break;
case V_33 :
V_17 = & V_35 ;
break;
default:
F_12 () ;
V_17 = NULL ;
}
return V_17 ;
}
T_1 *
F_21 ( T_4 V_12 )
{
T_1 * * V_17 ;
V_17 = F_20 ( V_12 ) ;
return F_16 ( * V_17 ) ;
}
T_1 *
F_22 ( T_4 V_12 , const char * V_5 ,
const char * V_36 )
{
T_1 * * V_17 ;
V_17 = F_20 ( V_12 ) ;
* V_17 = F_1 ( * V_17 , V_5 , V_36 ) ;
return F_23 ( * V_17 ) ;
}
void
F_24 ( T_4 V_12 , T_1 * V_7 )
{
T_1 * * V_17 ;
V_17 = F_20 ( V_12 ) ;
* V_17 = F_5 ( * V_17 , V_7 ) ;
}
void
F_25 ( T_4 V_12 , char * * V_13 ,
int * V_14 )
{
const T_5 * V_15 ;
T_5 * V_16 , * V_37 ;
T_1 * V_1 ;
T_1 * V_17 ;
T_2 * V_4 ;
T_3 * V_9 ;
T_6 * V_38 , V_10 ;
* V_13 = NULL ;
switch ( V_12 ) {
case V_22 :
V_15 = V_23 ;
V_1 = V_24 ;
break;
case V_25 :
V_15 = V_26 ;
V_1 = V_27 ;
break;
default:
F_12 () ;
return;
}
V_16 = F_13 ( V_15 , TRUE ) ;
V_37 = F_26 ( L_6 , V_16 ) ;
if ( ( V_9 = F_14 ( V_37 , L_7 ) ) == NULL ) {
* V_13 = V_16 ;
* V_14 = V_28 ;
F_6 ( V_37 ) ;
return;
}
V_17 = F_16 ( V_1 ) ;
while ( V_17 ) {
V_4 = ( T_2 * ) V_17 -> V_8 ;
putc ( '"' , V_9 ) ;
for ( V_38 = ( T_6 * ) V_4 -> V_5 ; ( V_10 = * V_38 ) != '\0' ; V_38 ++ ) {
if ( V_10 == '"' || V_10 == '\\' )
putc ( '\\' , V_9 ) ;
putc ( V_10 , V_9 ) ;
}
putc ( '"' , V_9 ) ;
putc ( ' ' , V_9 ) ;
fprintf ( V_9 , L_8 , V_4 -> V_6 ) ;
if ( ferror ( V_9 ) ) {
* V_13 = V_16 ;
* V_14 = V_28 ;
fclose ( V_9 ) ;
F_27 ( V_37 ) ;
F_6 ( V_37 ) ;
return;
}
V_17 = V_17 -> V_39 ;
}
if ( fclose ( V_9 ) == V_11 ) {
* V_13 = V_16 ;
* V_14 = V_28 ;
F_27 ( V_37 ) ;
F_6 ( V_37 ) ;
return;
}
#ifdef F_28
if ( F_29 ( V_16 ) < 0 && V_28 != V_29 ) {
* V_13 = V_16 ;
* V_14 = V_28 ;
F_27 ( V_37 ) ;
F_6 ( V_37 ) ;
return;
}
#endif
if ( F_30 ( V_37 , V_16 ) < 0 ) {
* V_13 = V_16 ;
* V_14 = V_28 ;
F_27 ( V_37 ) ;
F_6 ( V_37 ) ;
return;
}
F_6 ( V_37 ) ;
F_6 ( V_16 ) ;
}
void F_19 ( T_4 V_40 , T_4 V_41 )
{
T_1 * * V_42 ;
T_1 * * V_43 ;
T_1 * V_44 ;
T_2 * V_4 ;
F_31 ( V_40 != V_41 ) ;
V_42 = F_20 ( V_40 ) ;
V_43 = F_20 ( V_41 ) ;
while( * V_42 ) {
* V_42 = F_5 ( * V_42 , F_16 ( * V_42 ) ) ;
}
F_31 ( F_32 ( * V_42 ) == 0 ) ;
for( V_44 = F_16 ( * V_43 ) ; V_44 ; V_44 = F_33 ( V_44 ) ) {
V_4 = ( T_2 * ) ( V_44 -> V_8 ) ;
* V_42 = F_1 ( * V_42 , V_4 -> V_5 , V_4 -> V_6 ) ;
}
}

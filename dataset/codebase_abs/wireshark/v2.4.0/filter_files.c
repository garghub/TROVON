static T_1 *
F_1 ( T_1 * V_1 , const char * V_2 , const char * V_3 )
{
T_2 * V_4 ;
V_4 = ( T_2 * ) F_2 ( sizeof( T_2 ) ) ;
V_4 -> V_5 = F_3 ( V_2 ) ;
V_4 -> V_6 = F_3 ( V_3 ) ;
return F_4 ( V_1 , V_4 ) ;
}
static void
F_5 ( T_3 V_7 )
{
T_2 * V_4 = ( T_2 * ) V_7 ;
F_6 ( V_4 -> V_5 ) ;
F_6 ( V_4 -> V_6 ) ;
F_6 ( V_4 ) ;
}
void F_7 ( void )
{
if ( V_8 ) {
F_8 ( V_8 , F_5 ) ;
V_8 = NULL ;
}
if ( V_9 ) {
F_8 ( V_9 , F_5 ) ;
V_9 = NULL ;
}
if ( V_10 ) {
F_8 ( V_10 , F_5 ) ;
V_10 = NULL ;
}
if ( V_11 ) {
F_8 ( V_11 , F_5 ) ;
V_11 = NULL ;
}
}
static T_1 *
F_9 ( T_1 * V_1 , T_1 * V_12 )
{
T_2 * V_4 ;
V_4 = ( T_2 * ) V_12 -> V_7 ;
F_6 ( V_4 -> V_5 ) ;
F_6 ( V_4 -> V_6 ) ;
F_6 ( V_4 ) ;
return F_10 ( V_1 , V_12 ) ;
}
static int
F_11 ( T_4 * V_13 )
{
int V_14 ;
while ( ( V_14 = getc ( V_13 ) ) != V_15 && V_14 != '\n' && F_12 ( V_14 ) )
;
return V_14 ;
}
static int
F_13 ( T_4 * V_13 )
{
int V_14 ;
V_14 = getc ( V_13 ) ;
if ( V_14 == '\r' ) {
V_14 = getc ( V_13 ) ;
if ( V_14 != V_15 && V_14 != '\n' ) {
ungetc ( V_14 , V_13 ) ;
V_14 = '\r' ;
}
}
return V_14 ;
}
void
F_14 ( T_5 V_16 )
{
const char * V_17 , * V_18 ;
char * V_19 ;
T_4 * V_13 ;
T_1 * * V_20 ;
int V_14 ;
char * V_2 , * V_3 ;
int V_21 , V_22 ;
int V_23 , V_24 ;
int line = 1 ;
switch ( V_16 ) {
case V_25 :
V_17 = V_26 ;
V_18 = L_1 ;
V_20 = & V_8 ;
break;
case V_27 :
V_17 = V_28 ;
V_18 = L_2 ;
V_20 = & V_9 ;
break;
default:
F_15 () ;
return;
}
V_19 = F_16 ( V_17 , TRUE ) ;
if ( ( V_13 = F_17 ( V_19 , L_3 ) ) == NULL ) {
if ( V_29 != V_30 ) {
F_18 ( L_4 ,
V_18 , V_19 , F_19 ( V_29 ) ) ;
F_6 ( V_19 ) ;
return;
}
F_6 ( V_19 ) ;
V_19 = F_16 ( V_31 , FALSE ) ;
if ( ( V_13 = F_17 ( V_19 , L_3 ) ) == NULL ) {
if ( V_29 != V_30 ) {
F_18 ( L_4 ,
V_18 , V_19 , F_19 ( V_29 ) ) ;
F_6 ( V_19 ) ;
return;
}
F_6 ( V_19 ) ;
V_19 = F_20 ( V_17 ) ;
if ( ( V_13 = F_17 ( V_19 , L_3 ) ) == NULL ) {
if ( V_29 != V_30 ) {
F_18 ( L_4 ,
V_18 , V_19 , F_19 ( V_29 ) ) ;
}
F_6 ( V_19 ) ;
return;
}
}
}
while( * V_20 ) {
* V_20 = F_9 ( * V_20 , F_21 ( * V_20 ) ) ;
}
V_21 = V_32 ;
V_2 = ( char * ) F_2 ( V_21 + 1 ) ;
V_22 = V_32 ;
V_3 = ( char * ) F_2 ( V_22 + 1 ) ;
for ( line = 1 ; ; line ++ ) {
V_14 = F_11 ( V_13 ) ;
if ( V_14 == V_15 )
break;
if ( V_14 == '\n' )
continue;
if ( V_14 != '"' ) {
F_22 ( L_5 , V_19 ,
line ) ;
while ( V_14 != '\n' )
V_14 = getc ( V_13 ) ;
continue;
}
V_23 = 0 ;
for (; ; ) {
V_14 = F_13 ( V_13 ) ;
if ( V_14 == V_15 || V_14 == '\n' )
break;
if ( V_14 == '"' ) {
if ( V_23 >= V_21 ) {
V_21 *= 2 ;
V_2 = ( char * ) F_23 ( V_2 , V_21 + 1 ) ;
}
V_2 [ V_23 ] = '\0' ;
break;
}
if ( V_14 == '\\' ) {
V_14 = F_13 ( V_13 ) ;
if ( V_14 == V_15 || V_14 == '\n' )
break;
}
if ( V_23 >= V_21 ) {
V_21 *= 2 ;
V_2 = ( char * ) F_23 ( V_2 , V_21 + 1 ) ;
}
V_2 [ V_23 ] = V_14 ;
V_23 ++ ;
}
if ( V_14 == V_15 ) {
if ( ! ferror ( V_13 ) ) {
F_22 ( L_6 , V_19 ,
line ) ;
}
break;
}
if ( V_14 != '"' ) {
F_22 ( L_7 , V_19 ,
line ) ;
continue;
}
V_14 = F_11 ( V_13 ) ;
if ( V_14 == V_15 ) {
if ( ! ferror ( V_13 ) ) {
F_22 ( L_6 , V_19 ,
line ) ;
}
break;
}
if ( V_14 == '\n' ) {
F_22 ( L_8 , V_19 ,
line ) ;
continue;
}
V_24 = 0 ;
for (; ; ) {
if ( V_24 >= V_22 ) {
V_22 *= 2 ;
V_3 = ( char * ) F_23 ( V_3 , V_22 + 1 ) ;
}
V_3 [ V_24 ] = V_14 ;
V_24 ++ ;
V_14 = F_13 ( V_13 ) ;
if ( V_14 == V_15 || V_14 == '\n' )
break;
}
if ( V_14 == V_15 ) {
if ( ! ferror ( V_13 ) ) {
F_22 ( L_6 , V_19 ,
line ) ;
}
break;
}
if ( V_24 >= V_22 ) {
V_22 *= 2 ;
V_3 = ( char * ) F_23 ( V_3 , V_22 + 1 ) ;
}
V_3 [ V_24 ] = '\0' ;
* V_20 = F_1 ( * V_20 , V_2 , V_3 ) ;
}
if ( ferror ( V_13 ) ) {
F_18 ( L_9 ,
V_18 , V_19 , F_19 ( V_29 ) ) ;
}
F_6 ( V_19 ) ;
fclose ( V_13 ) ;
F_6 ( V_2 ) ;
F_6 ( V_3 ) ;
switch ( V_16 ) {
case V_25 :
F_24 ( V_33 , V_25 ) ;
break;
case V_27 :
F_24 ( V_34 , V_27 ) ;
break;
default:
F_15 () ;
return;
}
}
static T_1 * *
F_25 ( T_5 V_16 )
{
T_1 * * V_20 ;
switch ( V_16 ) {
case V_25 :
V_20 = & V_8 ;
break;
case V_27 :
V_20 = & V_9 ;
break;
case V_33 :
V_20 = & V_10 ;
break;
case V_34 :
V_20 = & V_11 ;
break;
default:
F_15 () ;
V_20 = NULL ;
}
return V_20 ;
}
T_1 *
F_26 ( T_5 V_16 )
{
T_1 * * V_20 ;
V_20 = F_25 ( V_16 ) ;
return F_21 ( * V_20 ) ;
}
T_1 *
F_27 ( T_5 V_16 , const char * V_5 ,
const char * V_35 )
{
T_1 * * V_20 ;
V_20 = F_25 ( V_16 ) ;
* V_20 = F_1 ( * V_20 , V_5 , V_35 ) ;
return F_28 ( * V_20 ) ;
}
void
F_29 ( T_5 V_16 , T_1 * V_12 )
{
T_1 * * V_20 ;
V_20 = F_25 ( V_16 ) ;
* V_20 = F_9 ( * V_20 , V_12 ) ;
}
void
F_30 ( T_5 V_16 )
{
char * V_36 ;
const T_6 * V_17 , * V_18 ;
T_6 * V_19 , * V_37 ;
T_1 * V_1 ;
T_1 * V_20 ;
T_2 * V_4 ;
T_4 * V_13 ;
T_7 * V_38 , V_14 ;
switch ( V_16 ) {
case V_25 :
V_17 = V_26 ;
V_18 = L_1 ;
V_1 = V_8 ;
break;
case V_27 :
V_17 = V_28 ;
V_18 = L_2 ;
V_1 = V_9 ;
break;
default:
F_15 () ;
return;
}
if ( F_31 ( & V_36 ) == - 1 ) {
F_32 ( L_10 ,
V_36 , F_19 ( V_29 ) ) ;
F_6 ( V_36 ) ;
return;
}
V_19 = F_16 ( V_17 , TRUE ) ;
V_37 = F_33 ( L_11 , V_19 ) ;
if ( ( V_13 = F_17 ( V_37 , L_12 ) ) == NULL ) {
F_32 ( L_13 ,
V_18 , V_37 , F_19 ( V_29 ) ) ;
F_6 ( V_37 ) ;
F_6 ( V_19 ) ;
return;
}
V_20 = F_21 ( V_1 ) ;
while ( V_20 ) {
V_4 = ( T_2 * ) V_20 -> V_7 ;
putc ( '"' , V_13 ) ;
for ( V_38 = ( T_7 * ) V_4 -> V_5 ; ( V_14 = * V_38 ) != '\0' ; V_38 ++ ) {
if ( V_14 == '"' || V_14 == '\\' )
putc ( '\\' , V_13 ) ;
putc ( V_14 , V_13 ) ;
}
putc ( '"' , V_13 ) ;
putc ( ' ' , V_13 ) ;
fprintf ( V_13 , L_14 , V_4 -> V_6 ) ;
if ( ferror ( V_13 ) ) {
F_32 ( L_15 ,
V_18 , V_37 , F_19 ( V_29 ) ) ;
fclose ( V_13 ) ;
F_34 ( V_37 ) ;
F_6 ( V_37 ) ;
F_6 ( V_19 ) ;
return;
}
V_20 = V_20 -> V_39 ;
}
if ( fclose ( V_13 ) == V_15 ) {
F_32 ( L_15 ,
V_18 , V_37 , F_19 ( V_29 ) ) ;
F_34 ( V_37 ) ;
F_6 ( V_37 ) ;
F_6 ( V_19 ) ;
return;
}
#ifdef F_35
if ( F_36 ( V_19 ) < 0 && V_29 != V_30 ) {
F_32 ( L_16 ,
V_18 , V_19 , F_19 ( V_29 ) ) ;
F_34 ( V_37 ) ;
F_6 ( V_37 ) ;
F_6 ( V_19 ) ;
return;
}
#endif
if ( F_37 ( V_37 , V_19 ) < 0 ) {
F_32 ( L_17 ,
V_18 , V_37 , V_19 , F_19 ( V_29 ) ) ;
F_34 ( V_37 ) ;
F_6 ( V_37 ) ;
F_6 ( V_19 ) ;
return;
}
F_6 ( V_37 ) ;
F_6 ( V_19 ) ;
}
void F_24 ( T_5 V_40 , T_5 V_41 )
{
T_1 * * V_42 ;
T_1 * * V_43 ;
T_1 * V_44 ;
T_2 * V_4 ;
F_38 ( V_40 != V_41 ) ;
V_42 = F_25 ( V_40 ) ;
V_43 = F_25 ( V_41 ) ;
while( * V_42 ) {
* V_42 = F_9 ( * V_42 , F_21 ( * V_42 ) ) ;
}
F_38 ( F_39 ( * V_42 ) == 0 ) ;
for( V_44 = F_21 ( * V_43 ) ; V_44 ; V_44 = F_40 ( V_44 ) ) {
V_4 = ( T_2 * ) ( V_44 -> V_7 ) ;
* V_42 = F_1 ( * V_42 , V_4 -> V_5 , V_4 -> V_6 ) ;
}
}

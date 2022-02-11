static int F_1 ( void * V_1 , T_1 * V_2 , int V_3 , T_1 V_4 ,
T_2 type , T_3 V_5 )
{
T_4 V_6 ;
int V_7 ;
V_6 . V_4 = V_4 ;
V_6 . V_8 = 0 ;
V_7 = (* V_5)( V_1 , & V_6 , V_9 ) ;
F_2 ( V_2 , L_1 , V_6 . V_4 , V_6 . V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
return 2 ;
}
static int F_3 ( void * V_1 , T_1 * V_2 , int V_3 , T_1 V_4 ,
T_2 type , T_3 V_5 )
{
T_4 V_6 ;
int V_7 ;
F_4 ( V_2 , L_1 , & V_6 . V_4 , & V_6 . V_8 ) ;
V_7 = (* V_5)( V_1 , & V_6 , V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
return 2 ;
}
static int F_5 ( void * V_1 , T_1 * V_2 , int V_3 , T_1 V_4 ,
T_2 type , T_3 V_5 )
{
T_4 V_6 ;
int V_11 = 0 ;
int V_12 ;
V_6 . V_4 = V_4 ;
V_6 . V_8 = type & V_13 ;
V_6 . V_14 . V_15 = 0 ;
V_12 = (* V_5)( V_1 , & V_6 , V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_6 . V_8 == 0 ) {
if ( V_6 . V_14 . V_15 < 0xff ) {
F_6 ( L_2 , V_16 ) ;
V_6 . V_8 = 1 ;
} else if ( V_6 . V_14 . V_15 < 0xffff ) {
F_6 ( L_3 , V_16 ) ;
V_6 . V_8 = 2 ;
} else {
F_6 ( L_4 , V_16 ) ;
V_6 . V_8 = 4 ;
}
}
if ( V_3 < ( 2 + V_6 . V_8 ) ) {
F_7 ( L_5 ,
V_16 ) ;
return - 1 ;
}
F_6 ( L_6 , V_16 ,
V_6 . V_4 , V_6 . V_8 , V_6 . V_14 . V_15 ) ;
switch ( V_6 . V_8 ) {
case 1 :
V_11 += F_2 ( V_2 , L_7 , V_6 . V_4 , V_6 . V_8 , ( T_1 ) V_6 . V_14 . V_15 ) ;
break;
case 2 :
if ( type & V_17 )
V_6 . V_14 . V_15 = F_8 ( ( V_18 ) V_6 . V_14 . V_15 ) ;
else
V_6 . V_14 . V_15 = F_9 ( ( V_18 ) V_6 . V_14 . V_15 ) ;
V_11 += F_2 ( V_2 , L_8 , V_6 . V_4 , V_6 . V_8 , ( V_18 ) V_6 . V_14 . V_15 ) ;
break;
case 4 :
if ( type & V_17 )
F_10 ( & V_6 . V_14 . V_15 ) ;
else
F_11 ( & V_6 . V_14 . V_15 ) ;
V_11 += F_2 ( V_2 , L_9 , V_6 . V_4 , V_6 . V_8 , V_6 . V_14 . V_15 ) ;
break;
default:
F_7 ( L_10 ,
V_16 , V_6 . V_8 ) ;
return - 1 ;
}
return V_6 . V_8 + 2 ;
}
static int F_12 ( void * V_1 , T_1 * V_2 , int V_3 , T_1 V_4 ,
T_2 type , T_3 V_5 )
{
T_4 V_6 ;
int V_11 = 0 ;
int V_19 ;
int V_12 ;
V_6 . V_4 = V_4 ;
V_6 . V_8 = V_2 [ 1 ] ;
V_6 . V_14 . V_15 = 0 ;
V_19 = V_6 . V_8 ;
if ( V_3 < ( 2 + V_6 . V_8 ) ) {
F_7 ( L_11 ,
V_16 , V_6 . V_8 , V_3 ) ;
return - 1 ;
}
if ( ( ( type & V_13 ) != V_20 ) && ( ( type & V_13 ) != V_6 . V_8 ) ) {
F_13 ( L_12 ,
V_16 , type & V_13 , V_6 . V_8 ) ;
if( ( V_6 . V_8 < ( type & V_13 ) ) || ( type & V_17 ) ) {
return V_6 . V_8 + 2 ;
} else {
V_19 = type & V_13 ;
}
}
switch ( V_19 ) {
case 1 :
V_11 += F_4 ( V_2 + 2 , L_13 , & V_6 . V_14 . V_15 ) ;
break;
case 2 :
V_11 += F_4 ( V_2 + 2 , L_14 , & V_6 . V_14 . V_15 ) ;
if ( type & V_17 )
V_6 . V_14 . V_15 = F_14 ( ( V_18 ) V_6 . V_14 . V_15 ) ;
else
V_6 . V_14 . V_15 = F_15 ( ( V_18 ) V_6 . V_14 . V_15 ) ;
break;
case 4 :
V_11 += F_4 ( V_2 + 2 , L_15 , & V_6 . V_14 . V_15 ) ;
if ( type & V_17 )
F_16 ( & V_6 . V_14 . V_15 ) ;
else
F_17 ( & V_6 . V_14 . V_15 ) ;
break;
default:
F_7 ( L_10 ,
V_16 , V_6 . V_8 ) ;
return V_6 . V_8 + 2 ;
}
F_6 ( L_6 , V_16 ,
V_6 . V_4 , V_6 . V_8 , V_6 . V_14 . V_15 ) ;
V_12 = (* V_5)( V_1 , & V_6 , V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
return V_6 . V_8 + 2 ;
}
static int F_18 ( void * V_1 , T_1 * V_2 , int V_3 , T_1 V_4 ,
T_2 type , T_3 V_5 )
{
char V_21 [ 33 ] ;
T_4 V_6 ;
int V_12 ;
V_6 . V_4 = V_4 ;
V_6 . V_8 = V_2 [ 1 ] ;
if ( V_6 . V_8 > 32 )
V_6 . V_8 = 32 ;
F_6 ( L_16 , V_16 ,
V_6 . V_4 , V_6 . V_8 ) ;
if ( V_3 < ( 2 + V_6 . V_8 ) ) {
F_7 ( L_11 ,
V_16 , V_6 . V_8 , V_3 ) ;
return - 1 ;
}
strncpy ( V_21 , V_2 + 2 , V_6 . V_8 ) ;
F_6 ( L_17 ,
V_16 , ( T_1 ) V_21 [ 0 ] , ( T_1 ) V_21 [ 1 ] ) ;
V_21 [ V_6 . V_8 ] = '\0' ;
V_6 . V_14 . V_22 = V_21 ;
V_12 = (* V_5)( V_1 , & V_6 , V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
return V_6 . V_8 + 2 ;
}
static int F_19 ( void * V_1 , T_1 * V_2 , int V_3 , T_1 V_4 ,
T_2 type , T_3 V_5 )
{
T_4 V_6 ;
V_6 . V_4 = V_4 ;
V_6 . V_8 = V_2 [ 1 ] ;
if ( V_3 < ( 2 + V_6 . V_8 ) ) {
F_7 ( L_11 ,
V_16 , V_6 . V_8 , V_3 ) ;
return - 1 ;
}
F_6 ( L_18 , V_16 ) ;
return V_6 . V_8 + 2 ;
}
int F_2 ( T_1 * V_2 , char * V_23 , ... )
{
T_5 V_24 ;
T_6 args ;
char * V_6 ;
int V_11 = 0 ;
va_start ( args , V_23 ) ;
for ( V_6 = V_23 ; * V_6 != '\0' ; V_6 ++ ) {
switch ( * V_6 ) {
case 'b' :
V_2 [ V_11 ++ ] = ( T_1 ) va_arg ( args , int ) ;
break;
case 's' :
V_24 . V_15 = ( V_18 ) va_arg ( args , int ) ;
F_20 ( ( V_18 ) V_24 . V_15 , ( V_18 * ) ( V_2 + V_11 ) ) ; V_11 += 2 ;
break;
case 'i' :
V_24 . V_15 = va_arg ( args , V_25 ) ;
F_20 ( V_24 . V_15 , ( V_25 * ) ( V_2 + V_11 ) ) ; V_11 += 4 ;
break;
#if 0
case 'c':
arg.c = va_arg(args, char *);
strcpy(buf+n, arg.c);
n += strlen(arg.c) + 1;
break;
#endif
default:
va_end ( args ) ;
return - 1 ;
}
}
va_end ( args ) ;
return 0 ;
}
static int F_4 ( T_1 * V_2 , char * V_23 , ... )
{
T_5 V_24 ;
T_6 args ;
char * V_6 ;
int V_11 = 0 ;
va_start ( args , V_23 ) ;
for ( V_6 = V_23 ; * V_6 != '\0' ; V_6 ++ ) {
switch ( * V_6 ) {
case 'b' :
V_24 . V_26 = va_arg ( args , V_25 * ) ;
* V_24 . V_26 = V_2 [ V_11 ++ ] ;
break;
case 's' :
V_24 . V_26 = va_arg ( args , V_25 * ) ;
* V_24 . V_26 = F_21 ( ( V_18 * ) ( V_2 + V_11 ) ) ; V_11 += 2 ;
break;
case 'i' :
V_24 . V_26 = va_arg ( args , V_25 * ) ;
* V_24 . V_26 = F_21 ( ( V_25 * ) ( V_2 + V_11 ) ) ; V_11 += 4 ;
break;
#if 0
case 'c':
arg.c = va_arg(args, char *);
strcpy(arg.c, buf+n);
n += strlen(arg.c) + 1;
break;
#endif
default:
va_end ( args ) ;
return - 1 ;
}
}
va_end ( args ) ;
return 0 ;
}
int F_22 ( void * V_1 , T_1 V_4 , T_1 * V_2 , int V_3 ,
T_7 * V_27 )
{
const T_8 * V_28 ;
T_1 V_29 ;
T_1 V_30 ;
int type ;
int V_7 = - 1 ;
int V_11 = 0 ;
F_23 (buf != NULL, return ret;) ;
F_23 (info != NULL, return ret;) ;
V_29 = V_4 & V_27 -> V_31 ;
V_30 = V_4 >> V_27 -> V_32 ;
if ( ( V_30 > V_27 -> V_3 - 1 ) ||
( V_29 > V_27 -> V_33 [ V_30 ] . V_3 - 1 ) )
{
F_6 ( L_19 ,
V_16 , V_4 ) ;
return - 1 ;
}
V_28 = & V_27 -> V_33 [ V_30 ] . V_34 [ V_29 ] ;
type = V_28 -> type ;
if ( ! V_28 -> V_5 ) {
F_24 ( L_20 ,
V_16 , V_4 ) ;
return - 1 ;
}
V_7 = (* F_25 [ type & V_13 ])( V_1 , V_2 + V_11 , V_3 , V_4 , type ,
V_28 -> V_5 ) ;
return V_7 ;
}
static int F_26 ( void * V_1 , T_1 * V_2 , int V_3 ,
T_7 * V_27 )
{
const T_8 * V_28 ;
T_1 V_29 ;
T_1 V_30 ;
int type ;
int V_7 = - 1 ;
int V_11 = 0 ;
F_23 (buf != NULL, return ret;) ;
F_23 (info != NULL, return ret;) ;
V_29 = V_2 [ V_11 ] & V_27 -> V_31 ;
V_30 = V_2 [ V_11 ] >> V_27 -> V_32 ;
if ( ( V_30 > V_27 -> V_3 - 1 ) ||
( V_29 > V_27 -> V_33 [ V_30 ] . V_3 - 1 ) )
{
F_6 ( L_19 ,
V_16 , V_2 [ 0 ] ) ;
return 2 + V_2 [ V_11 + 1 ] ;
}
V_28 = & V_27 -> V_33 [ V_30 ] . V_34 [ V_29 ] ;
type = V_28 -> type ;
F_6 ( L_21 , V_16 ,
V_30 , V_29 , type ) ;
if ( ! V_28 -> V_5 ) {
F_24 ( L_20 ,
V_16 , V_2 [ V_11 ] ) ;
return 2 + V_2 [ V_11 + 1 ] ;
}
V_7 = (* F_27 [ type & V_13 ])( V_1 , V_2 + V_11 , V_3 , V_2 [ V_11 ] ,
type , V_28 -> V_5 ) ;
return V_7 ;
}
int F_28 ( void * V_1 , T_1 * V_2 , int V_3 ,
T_7 * V_27 )
{
int V_7 = - 1 ;
int V_11 = 0 ;
F_23 (buf != NULL, return ret;) ;
F_23 (info != NULL, return ret;) ;
while ( V_3 > 2 ) {
V_7 = F_26 ( V_1 , V_2 + V_11 , V_3 , V_27 ) ;
if ( V_7 < 0 )
return V_7 ;
V_11 += V_7 ;
V_3 -= V_7 ;
}
return V_11 ;
}

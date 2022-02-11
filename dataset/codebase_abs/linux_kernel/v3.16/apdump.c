T_1 F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 -> V_3 ) ) {
if ( ! F_3 ( V_2 -> V_3 ) ) {
fprintf ( V_4 ,
L_1 ,
* ( V_5 * ) V_2 -> V_3 ) ;
return ( FALSE ) ;
}
if ( V_2 -> V_6 < sizeof( struct V_1 ) ) {
fprintf ( V_4 , L_2 ,
V_2 -> V_6 ) ;
return ( FALSE ) ;
}
}
return ( TRUE ) ;
}
T_1 F_4 ( struct V_1 * V_2 )
{
T_2 V_7 ;
struct V_8 * V_9 ;
if ( F_2 ( V_2 -> V_3 ) ) {
V_9 = F_5 ( struct V_8 , V_2 ) ;
V_7 = F_6 ( V_9 ) ;
} else {
V_7 = F_7 ( V_2 , V_2 -> V_6 ) ;
}
if ( F_8 ( V_7 ) ) {
fprintf ( V_4 , L_3 ,
V_2 -> V_3 ) ;
}
return ( V_10 ) ;
}
V_5 F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( ! F_1 ( V_2 ) ) {
return ( 0 ) ;
}
if ( F_2 ( V_2 -> V_3 ) ) {
V_9 = F_5 ( struct V_8 , V_2 ) ;
return ( V_9 -> V_6 ) ;
}
return ( V_2 -> V_6 ) ;
}
static int
F_10 ( struct V_1 * V_2 ,
V_5 V_11 , T_3 V_12 )
{
V_5 V_13 ;
V_13 = F_9 ( V_2 ) ;
if ( V_14 ) {
F_11 ( V_12 , V_2 ) ;
return ( 0 ) ;
}
if ( V_15 ) {
return ( F_12 ( V_2 , V_11 ) ) ;
}
printf ( L_4 , V_2 -> V_3 ,
F_13 ( V_12 ) ) ;
F_14 ( F_5 ( T_1 , V_2 ) , V_13 ,
V_16 , 0 ) ;
printf ( L_5 ) ;
return ( 0 ) ;
}
int F_15 ( void )
{
struct V_1 * V_2 ;
V_5 V_11 = 0 ;
T_3 V_12 ;
T_2 V_7 ;
int V_17 ;
V_5 V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
V_7 =
F_16 ( V_18 , & V_2 , & V_11 , & V_12 ) ;
if ( F_8 ( V_7 ) ) {
if ( V_7 == V_20 ) {
return ( 0 ) ;
} else if ( V_18 == 0 ) {
fprintf ( V_4 ,
L_6 ,
F_17 ( V_7 ) ) ;
return ( - 1 ) ;
} else {
fprintf ( V_4 ,
L_7 ,
V_18 , F_17 ( V_7 ) ) ;
continue;
}
}
V_17 = F_10 ( V_2 , V_11 , V_12 ) ;
free ( V_2 ) ;
if ( V_17 ) {
break;
}
}
return ( - 1 ) ;
}
int F_18 ( char * V_21 )
{
T_3 V_12 ;
struct V_1 * V_2 ;
T_2 V_7 ;
int V_17 ;
T_4 V_22 ;
V_7 = F_19 ( V_21 , 0 , & V_22 ) ;
if ( F_8 ( V_7 ) ) {
fprintf ( V_4 , L_8 ,
V_21 ) ;
return ( - 1 ) ;
}
V_12 = ( T_3 ) V_22 ;
V_7 = F_20 ( V_12 , & V_2 ) ;
if ( F_8 ( V_7 ) ) {
fprintf ( V_4 , L_9 ,
F_13 ( V_12 ) ,
F_17 ( V_7 ) ) ;
return ( - 1 ) ;
}
V_17 = F_10 ( V_2 , 0 , V_12 ) ;
free ( V_2 ) ;
return ( V_17 ) ;
}
int F_21 ( char * V_3 )
{
char V_23 [ V_24 + 1 ] ;
V_5 V_11 ;
struct V_1 * V_2 ;
T_3 V_12 ;
T_2 V_7 ;
int V_17 ;
if ( strlen ( V_3 ) != V_24 ) {
fprintf ( V_4 ,
L_10 ,
V_3 ) ;
return ( - 1 ) ;
}
strcpy ( V_23 , V_3 ) ;
F_22 ( V_23 ) ;
if ( F_23 ( V_23 , L_11 ) ) {
strcpy ( V_23 , V_25 ) ;
} else if ( F_23 ( V_23 , L_12 ) ) {
strcpy ( V_23 , V_26 ) ;
}
for ( V_11 = 0 ; V_11 < V_19 ; V_11 ++ ) {
V_7 = F_24 ( V_23 , V_11 ,
& V_2 , & V_12 ) ;
if ( F_8 ( V_7 ) ) {
if ( V_7 == V_20 ) {
return ( 0 ) ;
}
fprintf ( V_4 ,
L_13 ,
V_23 , F_17 ( V_7 ) ) ;
return ( - 1 ) ;
}
V_17 = F_10 ( V_2 , V_11 , V_12 ) ;
free ( V_2 ) ;
if ( V_17 ) {
break;
}
}
return ( - 1 ) ;
}
int F_25 ( char * V_27 )
{
struct V_1 * V_2 ;
V_5 V_28 = 0 ;
int V_17 = - 1 ;
V_2 = F_26 ( V_27 , & V_28 ) ;
if ( ! V_2 ) {
return ( - 1 ) ;
}
if ( V_2 -> V_6 > V_28 ) {
fprintf ( V_4 ,
L_14 ,
V_2 -> V_6 , V_28 , V_27 ) ;
goto exit;
}
if ( V_29 ) {
fprintf ( V_4 ,
L_15 ,
V_27 , V_2 -> V_3 , V_28 , V_28 ) ;
}
V_17 = F_10 ( V_2 , 0 , 0 ) ;
exit:
free ( V_2 ) ;
return ( V_17 ) ;
}
void T_5 F_27 ( const char * V_30 , ... )
{
T_6 args ;
va_start ( args , V_30 ) ;
vfprintf ( stdout , V_30 , args ) ;
va_end ( args ) ;
}
void F_28 ( const char * V_30 , T_6 args )
{
vfprintf ( stdout , V_30 , args ) ;
}

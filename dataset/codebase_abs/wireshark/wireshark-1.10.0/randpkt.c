int
main ( int V_1 , char * * V_2 )
{
T_1 * V_3 ;
struct V_4 V_5 ;
union V_6 * V_7 = & V_5 . V_8 ;
int V_9 , V_10 , V_11 , V_12 , V_13 ;
T_2 V_14 [ 65536 ] ;
int V_15 ;
int V_16 = 1000 ;
int V_17 = V_18 ;
char * V_19 = NULL ;
int V_20 = 5000 ;
T_3 * V_21 ;
#ifdef F_1
F_2 ( V_1 , V_2 ) ;
F_3 () ;
#endif
while ( ( V_15 = F_4 ( V_1 , V_2 , L_1 ) ) != - 1 ) {
switch ( V_15 ) {
case 'b' :
V_20 = atoi ( V_22 ) ;
if ( V_20 > 65536 ) {
fprintf ( V_23 ,
L_2 ) ;
exit ( 1 ) ;
}
break;
case 'c' :
V_16 = atoi ( V_22 ) ;
break;
case 't' :
V_17 = F_5 ( V_22 ) ;
break;
case 'h' :
default:
F_6 () ;
break;
}
}
if ( V_1 > V_24 ) {
V_19 = V_2 [ V_24 ] ;
}
else {
F_6 () ;
}
V_21 = F_7 ( V_17 ) ;
V_3 = F_8 ( V_19 , V_25 ,
V_21 -> V_26 , V_20 , FALSE , & V_13 ) ;
if ( ! V_3 ) {
fprintf ( V_23 ,
L_3 , V_19 ) ;
exit ( 2 ) ;
}
F_9 () ;
if ( V_20 <= V_21 -> V_27 ) {
fprintf ( V_23 ,
L_4 ,
V_21 -> V_27 ) ;
fprintf ( V_23 , L_5 ,
V_20 ) ;
exit ( 1 ) ;
}
else {
V_20 -= V_21 -> V_27 ;
}
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
memset ( V_14 , 0 , sizeof( V_14 ) ) ;
V_5 . V_28 = V_21 -> V_26 ;
if ( V_21 -> V_29 )
memcpy ( V_7 , V_21 -> V_29 , V_21 -> V_30 ) ;
if ( V_21 -> V_31 )
memcpy ( & V_14 [ 0 ] , V_21 -> V_31 , V_21 -> V_27 ) ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ ) {
if ( V_20 > 0 ) {
V_12 = ( rand () % V_20 + 1 ) ;
}
else {
V_12 = 0 ;
}
V_11 = V_21 -> V_27 + V_12 ;
V_5 . V_32 = V_11 ;
V_5 . V_33 = V_11 ;
V_5 . V_34 . V_35 = V_9 ;
for ( V_10 = V_21 -> V_30 ; V_10 < ( int ) sizeof( * V_7 ) ; V_10 ++ ) {
( ( T_2 * ) V_7 ) [ V_10 ] = ( rand () % 0x100 ) ;
}
for ( V_10 = V_21 -> V_27 ; V_10 < V_11 ; V_10 ++ ) {
if ( ( int ) ( 100.0 * rand () / ( V_36 + 1.0 ) ) < 3 && V_10 < ( V_12 - 3 ) ) {
memcpy ( & V_14 [ V_10 ] , L_6 , 3 ) ;
V_10 += 2 ;
} else {
V_14 [ V_10 ] = ( rand () % 0x100 ) ;
}
}
F_10 ( V_3 , & V_5 , & V_14 [ 0 ] , & V_13 ) ;
}
F_11 ( V_3 , & V_13 ) ;
return 0 ;
}
static
void F_6 ( void )
{
int V_37 = F_12 ( V_38 ) ;
int V_9 ;
printf ( L_7 ) ;
printf ( L_8 ) ;
printf ( L_9 ) ;
printf ( L_10 ) ;
for ( V_9 = 0 ; V_9 < V_37 ; V_9 ++ ) {
printf ( L_11 , V_38 [ V_9 ] . V_39 , V_38 [ V_9 ] . V_40 ) ;
}
printf ( L_12 ) ;
exit ( 0 ) ;
}
static
int F_5 ( char * string )
{
int V_37 = F_12 ( V_38 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_37 ; V_9 ++ ) {
if ( strcmp ( V_38 [ V_9 ] . V_39 , string ) == 0 ) {
return V_38 [ V_9 ] . V_41 ;
}
}
fprintf ( V_23 , L_13 , string ) ;
exit ( 1 ) ;
}
static
T_3 * F_7 ( int type )
{
int V_37 = F_12 ( V_38 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_37 ; V_9 ++ ) {
if ( V_38 [ V_9 ] . V_41 == type ) {
return & V_38 [ V_9 ] ;
}
}
fprintf ( V_23 ,
L_14 ,
type ) ;
exit ( 1 ) ;
}
void
F_9 ( void )
{
unsigned int V_42 ;
T_4 V_43 ;
#ifndef F_1
int V_44 ;
T_5 V_45 ;
#define F_13 "/dev/urandom"
V_44 = F_14 ( F_13 , V_46 ) ;
if ( V_44 == - 1 ) {
if ( V_47 != V_48 ) {
fprintf ( V_23 ,
L_15 F_13 L_16 ,
F_15 ( V_47 ) ) ;
exit ( 2 ) ;
}
goto V_49;
}
V_45 = F_16 ( V_44 , & V_42 , sizeof V_42 ) ;
if ( V_45 == - 1 ) {
fprintf ( V_23 ,
L_17 F_13 L_18 ,
F_15 ( V_47 ) ) ;
exit ( 2 ) ;
}
if ( ( V_50 ) V_45 != sizeof V_42 ) {
fprintf ( V_23 ,
L_19 F_13 L_20 ,
( unsigned long ) sizeof V_42 , ( long ) V_45 ) ;
exit ( 2 ) ;
}
srand ( V_42 ) ;
F_17 ( V_44 ) ;
return;
V_49:
#endif
V_43 = time ( NULL ) ;
V_42 = ( unsigned int ) V_43 ;
srand ( V_42 ) ;
}

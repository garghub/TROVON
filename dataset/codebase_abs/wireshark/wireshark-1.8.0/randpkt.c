int
main ( int V_1 , char * * V_2 )
{
T_1 * V_3 ;
struct V_4 V_5 ;
union V_6 V_7 ;
int V_8 , V_9 , V_10 , V_11 , V_12 ;
T_2 V_13 [ 65536 ] ;
int V_14 ;
int V_15 = 1000 ;
int V_16 = V_17 ;
char * V_18 = NULL ;
int V_19 = 5000 ;
T_3 * V_20 ;
#ifdef F_1
F_2 ( V_1 , V_2 ) ;
#endif
while ( ( V_14 = F_3 ( V_1 , V_2 , L_1 ) ) != - 1 ) {
switch ( V_14 ) {
case 'b' :
V_19 = atoi ( V_21 ) ;
if ( V_19 > 65536 ) {
fprintf ( V_22 ,
L_2 ) ;
exit ( 1 ) ;
}
break;
case 'c' :
V_15 = atoi ( V_21 ) ;
break;
case 't' :
V_16 = F_4 ( V_21 ) ;
break;
case 'h' :
default:
F_5 () ;
break;
}
}
if ( V_1 > V_23 ) {
V_18 = V_2 [ V_23 ] ;
}
else {
F_5 () ;
}
V_20 = F_6 ( V_16 ) ;
V_3 = F_7 ( V_18 , V_24 ,
V_20 -> V_25 , V_19 , FALSE , & V_12 ) ;
if ( ! V_3 ) {
fprintf ( V_22 ,
L_3 , V_18 ) ;
exit ( 2 ) ;
}
F_8 () ;
if ( V_19 <= V_20 -> V_26 ) {
fprintf ( V_22 ,
L_4 ,
V_20 -> V_26 ) ;
fprintf ( V_22 , L_5 ,
V_19 ) ;
exit ( 1 ) ;
}
else {
V_19 -= V_20 -> V_26 ;
}
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
V_5 . V_27 = V_20 -> V_25 ;
if ( V_20 -> V_28 )
memcpy ( & V_7 , V_20 -> V_28 , V_20 -> V_29 ) ;
if ( V_20 -> V_30 )
memcpy ( & V_13 [ 0 ] , V_20 -> V_30 , V_20 -> V_26 ) ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ ) {
if ( V_19 > 0 ) {
V_11 = ( rand () % V_19 + 1 ) ;
}
else {
V_11 = 0 ;
}
V_10 = V_20 -> V_26 + V_11 ;
V_5 . V_31 = V_10 ;
V_5 . V_32 = V_10 ;
V_5 . V_33 . V_34 = V_8 ;
for ( V_9 = V_20 -> V_29 ; V_9 < ( int ) sizeof( V_7 ) ; V_9 ++ ) {
( ( T_2 * ) & V_7 ) [ V_9 ] = ( rand () % 0x100 ) ;
}
for ( V_9 = V_20 -> V_26 ; V_9 < V_10 ; V_9 ++ ) {
if ( ( int ) ( 100.0 * rand () / ( V_35 + 1.0 ) ) < 3 && V_9 < ( V_11 - 3 ) ) {
memcpy ( & V_13 [ V_9 ] , L_6 , 3 ) ;
V_9 += 2 ;
} else {
V_13 [ V_9 ] = ( rand () % 0x100 ) ;
}
}
F_9 ( V_3 , & V_5 , & V_7 , & V_13 [ 0 ] , & V_12 ) ;
}
F_10 ( V_3 , & V_12 ) ;
return 0 ;
}
static
void F_5 ( void )
{
int V_36 = F_11 ( V_37 ) ;
int V_8 ;
printf ( L_7 ) ;
printf ( L_8 ) ;
printf ( L_9 ) ;
printf ( L_10 ) ;
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ ) {
printf ( L_11 , V_37 [ V_8 ] . V_38 , V_37 [ V_8 ] . V_39 ) ;
}
printf ( L_12 ) ;
exit ( 0 ) ;
}
static
int F_4 ( char * string )
{
int V_36 = F_11 ( V_37 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ ) {
if ( strcmp ( V_37 [ V_8 ] . V_38 , string ) == 0 ) {
return V_37 [ V_8 ] . V_40 ;
}
}
fprintf ( V_22 , L_13 , string ) ;
exit ( 1 ) ;
}
static
T_3 * F_6 ( int type )
{
int V_36 = F_11 ( V_37 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ ) {
if ( V_37 [ V_8 ] . V_40 == type ) {
return & V_37 [ V_8 ] ;
}
}
fprintf ( V_22 ,
L_14 ,
type ) ;
exit ( 1 ) ;
}
void
F_8 ( void )
{
unsigned int V_41 ;
T_4 V_42 ;
#ifndef F_1
int V_43 ;
T_5 V_44 ;
#define F_12 "/dev/urandom"
V_43 = F_13 ( F_12 , V_45 ) ;
if ( V_43 == - 1 ) {
if ( V_46 != V_47 ) {
fprintf ( V_22 ,
L_15 F_12 L_16 ,
F_14 ( V_46 ) ) ;
exit ( 2 ) ;
}
goto V_48;
}
V_44 = F_15 ( V_43 , & V_41 , sizeof V_41 ) ;
if ( V_44 == - 1 ) {
fprintf ( V_22 ,
L_17 F_12 L_18 ,
F_14 ( V_46 ) ) ;
exit ( 2 ) ;
}
if ( ( V_49 ) V_44 != sizeof V_41 ) {
fprintf ( V_22 ,
L_19 F_12 L_20 ,
( unsigned long ) sizeof V_41 , ( long ) V_44 ) ;
exit ( 2 ) ;
}
srand ( V_41 ) ;
F_16 ( V_43 ) ;
return;
V_48:
#endif
V_42 = time ( NULL ) ;
V_41 = ( unsigned int ) V_42 ;
srand ( V_41 ) ;
}

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
F_6 ( FALSE ) ;
break;
default:
F_6 ( TRUE ) ;
break;
}
}
if ( V_1 > V_24 ) {
V_19 = V_2 [ V_24 ] ;
}
else {
F_6 ( TRUE ) ;
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
V_5 . V_28 = V_29 ;
V_5 . V_30 = V_31 ;
V_5 . V_32 = V_21 -> V_26 ;
if ( V_21 -> V_33 )
memcpy ( V_7 , V_21 -> V_33 , V_21 -> V_34 ) ;
if ( V_21 -> V_35 )
memcpy ( & V_14 [ 0 ] , V_21 -> V_35 , V_21 -> V_27 ) ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ ) {
if ( V_20 > 0 ) {
V_12 = ( rand () % V_20 + 1 ) ;
}
else {
V_12 = 0 ;
}
V_11 = V_21 -> V_27 + V_12 ;
V_5 . V_36 = V_11 ;
V_5 . V_37 = V_11 ;
V_5 . V_38 . V_39 = V_9 ;
for ( V_10 = V_21 -> V_34 ; V_10 < ( int ) sizeof( * V_7 ) ; V_10 ++ ) {
( ( T_2 * ) V_7 ) [ V_10 ] = ( rand () % 0x100 ) ;
}
for ( V_10 = V_21 -> V_27 ; V_10 < V_11 ; V_10 ++ ) {
if ( ( int ) ( 100.0 * rand () / ( V_40 + 1.0 ) ) < 3 && V_10 < ( V_12 - 3 ) ) {
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
static void
F_6 ( T_4 V_41 )
{
T_5 * V_42 ;
int V_43 = F_12 ( V_44 ) ;
int V_9 ;
if ( ! V_41 ) {
V_42 = stdout ;
}
else {
V_42 = V_23 ;
}
fprintf ( V_42 , L_7 ) ;
fprintf ( V_42 , L_8 ) ;
fprintf ( V_42 , L_9 ) ;
fprintf ( V_42 , L_10 ) ;
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ ) {
fprintf ( V_42 , L_11 , V_44 [ V_9 ] . V_45 , V_44 [ V_9 ] . V_46 ) ;
}
fprintf ( V_42 , L_12 ) ;
exit ( V_41 ? 1 : 0 ) ;
}
static
int F_5 ( char * string )
{
int V_43 = F_12 ( V_44 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ ) {
if ( strcmp ( V_44 [ V_9 ] . V_45 , string ) == 0 ) {
return V_44 [ V_9 ] . V_47 ;
}
}
fprintf ( V_23 , L_13 , string ) ;
exit ( 1 ) ;
}
static
T_3 * F_7 ( int type )
{
int V_43 = F_12 ( V_44 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ ) {
if ( V_44 [ V_9 ] . V_47 == type ) {
return & V_44 [ V_9 ] ;
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
unsigned int V_48 ;
T_6 V_49 ;
#ifndef F_1
int V_50 ;
T_7 V_51 ;
#define F_13 "/dev/urandom"
V_50 = F_14 ( F_13 , V_52 ) ;
if ( V_50 == - 1 ) {
if ( V_53 != V_54 ) {
fprintf ( V_23 ,
L_15 F_13 L_16 ,
F_15 ( V_53 ) ) ;
exit ( 2 ) ;
}
goto V_55;
}
V_51 = F_16 ( V_50 , & V_48 , sizeof V_48 ) ;
if ( V_51 == - 1 ) {
fprintf ( V_23 ,
L_17 F_13 L_18 ,
F_15 ( V_53 ) ) ;
exit ( 2 ) ;
}
if ( ( V_56 ) V_51 != sizeof V_48 ) {
fprintf ( V_23 ,
L_19 F_13 L_20 ,
( unsigned long ) sizeof V_48 , ( long ) V_51 ) ;
exit ( 2 ) ;
}
srand ( V_48 ) ;
F_17 ( V_50 ) ;
return;
V_55:
#endif
V_49 = time ( NULL ) ;
V_48 = ( unsigned int ) V_49 ;
srand ( V_48 ) ;
}

int
main ( int V_1 , char * * V_2 )
{
T_1 * V_3 ;
const char * V_4 ;
struct V_5 V_6 ;
union V_7 * V_8 = & V_6 . V_9 ;
int V_10 , V_11 , V_12 , V_13 , V_14 ;
T_2 * V_15 ;
T_3 V_16 [ 65536 ] ;
int V_17 ;
int V_18 = 1000 ;
int V_19 = V_20 ;
char * V_21 = NULL ;
int V_22 = 5000 ;
T_4 * V_23 ;
F_1 (cast-qual)
static const struct V_24 V_25 [] = {
{ ( char * ) L_1 , V_26 , NULL , 'h' } ,
{ 0 , 0 , 0 , 0 }
} ;
F_2 (cast-qual)
#ifdef F_3
F_4 ( V_1 , V_2 ) ;
F_5 () ;
#endif
while ( ( V_17 = F_6 ( V_1 , V_2 , L_2 , V_25 , NULL ) ) != - 1 ) {
switch ( V_17 ) {
case 'b' :
V_22 = atoi ( V_27 ) ;
if ( V_22 > 65536 ) {
fprintf ( V_28 ,
L_3 ) ;
exit ( 1 ) ;
}
break;
case 'c' :
V_18 = atoi ( V_27 ) ;
break;
case 't' :
V_19 = F_7 ( V_27 ) ;
break;
case 'h' :
F_8 ( FALSE ) ;
break;
default:
F_8 ( TRUE ) ;
break;
}
}
if ( V_1 > V_29 ) {
V_21 = V_2 [ V_29 ] ;
}
else {
F_8 ( TRUE ) ;
}
V_23 = F_9 ( V_19 ) ;
if ( strcmp ( V_21 , L_4 ) == 0 ) {
V_3 = F_10 ( V_30 ,
V_23 -> V_31 , V_22 , FALSE , & V_14 ) ;
V_4 = L_5 ;
} else {
V_3 = F_11 ( V_21 , V_30 ,
V_23 -> V_31 , V_22 , FALSE , & V_14 ) ;
V_4 = V_21 ;
}
if ( ! V_3 ) {
fprintf ( V_28 ,
L_6 , V_4 ) ;
exit ( 2 ) ;
}
F_12 () ;
if ( V_22 <= V_23 -> V_32 ) {
fprintf ( V_28 ,
L_7 ,
V_23 -> V_32 ) ;
fprintf ( V_28 , L_8 ,
V_22 ) ;
exit ( 1 ) ;
}
else {
V_22 -= V_23 -> V_32 ;
}
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
V_6 . V_33 = V_34 ;
V_6 . V_35 = V_36 ;
V_6 . V_37 = V_23 -> V_31 ;
if ( V_23 -> V_38 )
memcpy ( V_8 , V_23 -> V_38 , V_23 -> V_39 ) ;
if ( V_23 -> V_40 )
memcpy ( & V_16 [ 0 ] , V_23 -> V_40 , V_23 -> V_32 ) ;
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ ) {
if ( V_22 > 0 ) {
V_13 = ( rand () % V_22 + 1 ) ;
}
else {
V_13 = 0 ;
}
V_12 = V_23 -> V_32 + V_13 ;
V_6 . V_41 = V_12 ;
V_6 . V_42 = V_12 ;
V_6 . V_43 . V_44 = V_10 ;
for ( V_11 = V_23 -> V_39 ; V_11 < ( int ) sizeof( * V_8 ) ; V_11 ++ ) {
( ( T_3 * ) V_8 ) [ V_11 ] = ( rand () % 0x100 ) ;
}
for ( V_11 = V_23 -> V_32 ; V_11 < V_12 ; V_11 ++ ) {
if ( ( int ) ( 100.0 * rand () / ( V_45 + 1.0 ) ) < 3 && V_11 < ( V_13 - 3 ) ) {
memcpy ( & V_16 [ V_11 ] , L_9 , 3 ) ;
V_11 += 2 ;
} else {
V_16 [ V_11 ] = ( rand () % 0x100 ) ;
}
}
if ( ! F_13 ( V_3 , & V_6 , & V_16 [ 0 ] , & V_14 , & V_15 ) ) {
fprintf ( V_28 , L_10 ,
V_4 , F_14 ( V_14 ) ) ;
switch ( V_14 ) {
case V_46 :
fprintf ( V_28 ,
L_11 ,
F_15 ( V_30 ) ) ;
break;
case V_47 :
fprintf ( V_28 ,
L_12 ,
F_15 ( V_30 ) ) ;
break;
case V_48 :
fprintf ( V_28 ,
L_13 ,
F_15 ( V_30 ) ) ;
break;
case V_49 :
fprintf ( V_28 ,
L_14 ,
F_15 ( V_30 ) ,
V_15 != NULL ? V_15 : L_15 ) ;
F_16 ( V_15 ) ;
break;
default:
break;
}
}
}
if ( ! F_17 ( V_3 , & V_14 ) ) {
fprintf ( V_28 , L_16 ,
V_4 , F_14 ( V_14 ) ) ;
return 2 ;
}
return 0 ;
}
static void
F_8 ( T_5 V_50 )
{
T_6 * V_51 ;
int V_52 = F_18 ( V_53 ) ;
int V_10 ;
if ( ! V_50 ) {
V_51 = stdout ;
}
else {
V_51 = V_28 ;
}
fprintf ( V_51 , L_17 ) ;
fprintf ( V_51 , L_18 ) ;
fprintf ( V_51 , L_19 ) ;
fprintf ( V_51 , L_20 ) ;
for ( V_10 = 0 ; V_10 < V_52 ; V_10 ++ ) {
fprintf ( V_51 , L_21 , V_53 [ V_10 ] . V_54 , V_53 [ V_10 ] . V_55 ) ;
}
fprintf ( V_51 , L_22 ) ;
exit ( V_50 ? 1 : 0 ) ;
}
static
int F_7 ( char * string )
{
int V_52 = F_18 ( V_53 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_52 ; V_10 ++ ) {
if ( strcmp ( V_53 [ V_10 ] . V_54 , string ) == 0 ) {
return V_53 [ V_10 ] . V_56 ;
}
}
fprintf ( V_28 , L_23 , string ) ;
exit ( 1 ) ;
}
static
T_4 * F_9 ( int type )
{
int V_52 = F_18 ( V_53 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_52 ; V_10 ++ ) {
if ( V_53 [ V_10 ] . V_56 == type ) {
return & V_53 [ V_10 ] ;
}
}
fprintf ( V_28 ,
L_24 ,
type ) ;
exit ( 1 ) ;
}
void
F_12 ( void )
{
unsigned int V_57 ;
T_7 V_58 ;
#ifndef F_3
int V_59 ;
T_8 V_60 ;
#define F_19 "/dev/urandom"
V_59 = F_20 ( F_19 , V_61 ) ;
if ( V_59 == - 1 ) {
if ( V_62 != V_63 ) {
fprintf ( V_28 ,
L_25 F_19 L_26 ,
F_21 ( V_62 ) ) ;
exit ( 2 ) ;
}
goto V_64;
}
V_60 = F_22 ( V_59 , & V_57 , sizeof V_57 ) ;
if ( V_60 == - 1 ) {
fprintf ( V_28 ,
L_27 F_19 L_28 ,
F_21 ( V_62 ) ) ;
exit ( 2 ) ;
}
if ( ( V_65 ) V_60 != sizeof V_57 ) {
fprintf ( V_28 ,
L_29 F_19 L_30 ,
( unsigned long ) sizeof V_57 , ( long ) V_60 ) ;
exit ( 2 ) ;
}
srand ( V_57 ) ;
F_23 ( V_59 ) ;
return;
V_64:
#endif
V_58 = time ( NULL ) ;
V_57 = ( unsigned int ) V_58 ;
srand ( V_57 ) ;
}

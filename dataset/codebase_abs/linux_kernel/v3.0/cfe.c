static void T_1 F_1 ( void * V_1 )
{
int V_2 = * ( int * ) V_1 ;
if ( F_2 () ) {
static int V_3 ;
if ( ! V_3 ) {
V_3 = 1 ;
F_3 ( F_1 , V_1 , 0 ) ;
}
} else {
F_4 ( L_1 ) ;
F_5 ( V_2 , 0 ) ;
F_4 ( L_2 ) ;
}
while ( 1 ) ;
}
static void T_1 F_6 ( char * V_4 )
{
static const int V_5 ;
F_1 ( ( void * ) & V_5 ) ;
}
static void T_1 F_7 ( void )
{
static const int V_6 = 1 ;
F_1 ( ( void * ) & V_6 ) ;
}
static T_2 void F_8 ( void )
{
T_3 V_7 , V_8 , type ;
int V_9 = 0 ;
unsigned int V_10 ;
int V_11 ;
#ifdef F_9
unsigned long V_12 ;
unsigned long V_13 ;
V_12 = F_10 ( V_14 ) ;
V_13 = F_10 ( V_15 ) ;
if ( V_14 &&
( ( V_12 > V_16 )
|| ( V_13 > V_16 ) ) ) {
F_11 ( L_3 ) ;
}
#endif
for ( V_10 = 0 ; F_12 ( V_10 , V_9 , & V_7 , & V_8 , & type ) != V_17 ;
V_10 ++ ) {
V_11 = 0 ;
if ( type == V_18 ) {
#ifdef F_9
if ( V_14 ) {
if ( ( V_12 > V_7 ) &&
( V_12 < ( V_7 + V_8 ) ) ) {
F_13 ( V_7 ,
V_12 - V_7 ,
V_19 ) ;
V_11 = 1 ;
}
if ( ( V_13 > V_7 ) &&
( V_13 < ( V_7 + V_8 ) ) ) {
F_13 ( V_13 ,
( V_7 + V_8 ) - V_13 ,
V_19 ) ;
V_11 = 1 ;
}
}
#endif
if ( ! V_11 ) {
if ( V_7 > V_16 )
continue;
if ( V_7 + V_8 > V_16 )
V_8 = V_16 - ( V_7 + V_8 ) + 1 ;
if ( V_8 > 512 )
V_8 -= 512 ;
F_13 ( V_7 , V_8 , V_19 ) ;
}
V_20 [ V_21 ] = V_7 ;
V_22 [ V_21 ] = V_8 ;
V_21 ++ ;
if ( V_21 ==
V_23 ) {
while( 1 ) ;
}
}
}
#ifdef F_9
if ( V_14 ) {
F_13 ( V_12 , V_13 - V_12 ,
V_24 ) ;
}
#endif
}
static int T_2 F_14 ( char * V_25 )
{
char V_26 [ 64 ] ;
int V_10 ;
char * V_27 , * V_28 ;
unsigned long V_29 ;
for ( V_10 = 0 ; V_10 < sizeof( V_26 ) - 1 ; V_10 ++ ) {
if ( ! V_25 [ V_10 ] || ( V_25 [ V_10 ] == ' ' ) ) break;
V_26 [ V_10 ] = V_25 [ V_10 ] ;
}
V_26 [ V_10 ] = 0 ;
V_25 = V_26 ;
for ( V_27 = V_25 ; * V_27 != '@' ; V_27 ++ ) {
if ( ! * V_27 ) {
goto V_30;
}
}
* V_27 = 0 ;
V_27 ++ ;
if ( ! * V_27 ) {
goto V_30;
}
V_29 = F_15 ( V_25 , & V_28 , 16 ) ;
if ( * V_28 ) {
* ( V_27 - 1 ) = '@' ;
goto V_30;
}
* ( V_27 - 1 ) = '@' ;
V_14 = F_15 ( V_27 , & V_28 , 16 ) ;
if ( * V_28 ) {
goto V_30;
}
V_15 = V_14 + V_29 ;
F_4 ( L_4 , V_29 , V_14 ) ;
return 1 ;
V_30:
F_4 ( L_5 ) ;
V_14 = 0 ;
V_15 = 0 ;
return 1 ;
}
void T_2 F_16 ( void )
{
T_4 V_31 , V_32 ;
unsigned int V_33 ;
int V_34 = V_35 ;
char * * V_36 = ( char * * ) V_37 ;
int * V_38 = ( int * ) V_39 ;
V_40 = F_6 ;
V_41 = F_7 ;
V_42 = F_7 ;
if ( V_34 < 0 ) {
V_32 = ( T_4 ) ( long ) V_34 ;
V_31 = ( long ) V_36 ;
V_33 = ( V_43 ) ( unsigned long ) V_38 ;
} else {
if ( ( V_44 ) ( long ) V_38 < 0 ) {
V_32 = ( T_4 ) ( long ) V_38 ;
V_31 = ( T_4 ) ( ( V_44 ) 0x9fc00500 ) ;
V_33 = V_45 ;
} else {
V_32 = ( T_4 ) ( ( V_44 * ) V_38 ) [ 0 ] ;
V_31 = ( T_4 ) ( ( V_44 * ) V_38 ) [ 2 ] ;
V_33 = ( unsigned int ) ( ( V_43 * ) V_38 ) [ 3 ] ;
}
}
if ( V_33 != V_45 ) {
F_4 ( L_6 ) ;
while ( 1 ) ;
}
F_17 ( V_32 , V_31 ) ;
V_46 = F_18 ( V_47 ) ;
if ( F_19 ( L_7 , V_48 , V_49 ) < 0 ) {
if ( V_34 >= 0 ) {
F_4 ( L_8 ) ;
while ( 1 ) ;
}
}
#ifdef F_9
{
char * V_50 ;
for ( V_50 = V_48 ; * V_50 ; V_50 ++ ) {
while ( * V_50 == ' ' ) {
V_50 ++ ;
}
if ( ! strncmp ( V_50 , L_9 , 7 ) ) {
F_14 ( V_50 + 7 ) ;
break;
} else {
while ( * V_50 && ( * V_50 != ' ' ) ) {
V_50 ++ ;
}
}
}
}
#endif
V_48 [ V_49 - 1 ] = 0 ;
F_8 () ;
#if F_20 ( V_51 ) || F_20 ( V_52 )
F_21 ( & V_53 ) ;
#endif
#if F_20 ( V_54 ) || F_20 ( V_55 )
F_21 ( & V_56 ) ;
#endif
}
void T_2 F_22 ( void )
{
}
void F_23 ( char V_57 )
{
int V_58 ;
while ( ( V_58 = F_24 ( V_46 , & V_57 , 1 ) ) == 0 )
;
}

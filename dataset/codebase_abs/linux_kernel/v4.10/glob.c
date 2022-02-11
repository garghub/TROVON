bool T_1 F_1 ( char const * V_1 , char const * V_2 )
{
char const * V_3 = NULL , * V_4 = V_4 ;
for (; ; ) {
unsigned char V_5 = * V_2 ++ ;
unsigned char V_6 = * V_1 ++ ;
switch ( V_6 ) {
case '?' :
if ( V_5 == '\0' )
return false ;
break;
case '*' :
if ( * V_1 == '\0' )
return true ;
V_3 = V_1 ;
V_4 = -- V_2 ;
break;
case '[' : {
bool V_7 = false , V_8 = ( * V_1 == '!' ) ;
char const * V_9 = V_1 + V_8 ;
unsigned char V_10 = * V_9 ++ ;
do {
unsigned char V_11 = V_10 ;
if ( V_10 == '\0' )
goto V_12;
if ( V_9 [ 0 ] == '-' && V_9 [ 1 ] != ']' ) {
V_11 = V_9 [ 1 ] ;
if ( V_11 == '\0' )
goto V_12;
V_9 += 2 ;
}
V_7 |= ( V_10 <= V_5 && V_5 <= V_11 ) ;
} while ( ( V_10 = * V_9 ++ ) != ']' );
if ( V_7 == V_8 )
goto V_13;
V_1 = V_9 ;
}
break;
case '\\' :
V_6 = * V_1 ++ ;
default:
V_12:
if ( V_5 == V_6 ) {
if ( V_6 == '\0' )
return true ;
break;
}
V_13:
if ( V_5 == '\0' || ! V_3 )
return false ;
V_1 = V_3 ;
V_2 = ++ V_4 ;
break;
}
}
}
static bool T_1 T_2 F_2 ( char const * V_1 , char const * V_2 , bool V_14 )
{
bool V_7 = F_1 ( V_1 , V_2 ) ;
bool V_15 = V_7 == V_14 ;
static char const V_16 [] V_17 =
V_18 L_1 ;
static char const V_19 [] V_17 =
V_20 L_2 ;
static char const V_21 [] V_17 = L_3 ;
char const * V_22 ;
if ( ! V_15 )
V_22 = V_16 ;
else if ( V_23 )
V_22 = V_19 ;
else
return V_15 ;
F_3 ( V_22 , V_1 , V_2 , V_21 + 3 * V_7 ) ;
return V_15 ;
}
static int T_2 F_4 ( void )
{
unsigned V_24 = 0 ;
unsigned V_25 = 0 ;
char const * V_26 = V_27 ;
static char const V_22 [] V_17 =
V_28 L_4 ;
while ( * V_26 ) {
bool V_14 = * V_26 ++ & 1 ;
char const * V_1 = V_26 ;
V_26 += strlen ( V_26 ) + 1 ;
V_24 += F_2 ( V_1 , V_26 , V_14 ) ;
V_26 += strlen ( V_26 ) + 1 ;
V_25 ++ ;
}
V_25 -= V_24 ;
F_3 ( V_22 , V_24 , V_25 ) ;
return V_25 ? - V_29 : 0 ;
}
static void T_3 F_5 ( void ) { }

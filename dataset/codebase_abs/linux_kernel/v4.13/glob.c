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

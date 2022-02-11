int
F_1 ( T_1 , T_2 )
const char * T_1 ;
struct V_1 * T_2 ;
{
register const T_3 * V_2 = T_1 ;
register T_4 V_3 ;
register int V_4 ;
register T_5 V_5 ;
register T_3 V_6 ;
T_6 V_7 [ 4 ] ;
register T_6 * V_8 = V_7 ;
for (; ; ) {
V_3 = 0 ; V_4 = 10 ;
if ( * V_2 == '0' ) {
if ( * ++ V_2 == 'x' || * V_2 == 'X' )
V_4 = 16 , V_2 ++ ;
else
V_4 = 8 ;
}
while ( ( V_6 = * V_2 ) != '\0' ) {
if ( isascii ( V_6 ) && isdigit ( V_6 ) ) {
V_3 = ( V_3 * V_4 ) + ( V_6 - '0' ) ;
V_2 ++ ;
continue;
}
if ( V_4 == 16 && isascii ( V_6 ) && isxdigit ( V_6 ) ) {
V_3 = ( V_3 << 4 ) +
( V_6 + 10 - ( islower ( V_6 ) ? 'a' : 'A' ) ) ;
V_2 ++ ;
continue;
}
break;
}
if ( * V_2 == '.' ) {
if ( V_8 >= V_7 + 3 || V_3 > 0xff )
return ( 0 ) ;
* V_8 ++ = V_3 , V_2 ++ ;
} else
break;
}
if ( * V_2 && ( ! isascii ( * V_2 ) || ! isspace ( * V_2 ) ) )
return ( 0 ) ;
V_5 = V_8 - V_7 + 1 ;
switch ( V_5 ) {
case 1 :
break;
case 2 :
if ( V_3 > 0xffffff )
return ( 0 ) ;
V_3 |= V_7 [ 0 ] << 24 ;
break;
case 3 :
if ( V_3 > 0xffff )
return ( 0 ) ;
V_3 |= ( V_7 [ 0 ] << 24 ) | ( V_7 [ 1 ] << 16 ) ;
break;
case 4 :
if ( V_3 > 0xff )
return ( 0 ) ;
V_3 |= ( V_7 [ 0 ] << 24 ) | ( V_7 [ 1 ] << 16 ) | ( V_7 [ 2 ] << 8 ) ;
break;
}
if ( T_2 )
T_2 -> V_9 = F_2 ( V_3 ) ;
return ( 1 ) ;
}

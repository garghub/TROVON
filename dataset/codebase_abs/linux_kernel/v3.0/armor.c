static int F_1 ( int V_1 )
{
return V_2 [ V_1 ] ;
}
static int F_2 ( char V_1 )
{
if ( V_1 >= 'A' && V_1 <= 'Z' )
return V_1 - 'A' ;
if ( V_1 >= 'a' && V_1 <= 'z' )
return V_1 - 'a' + 26 ;
if ( V_1 >= '0' && V_1 <= '9' )
return V_1 - '0' + 52 ;
if ( V_1 == '+' )
return 62 ;
if ( V_1 == '/' )
return 63 ;
if ( V_1 == '=' )
return 0 ;
return - V_3 ;
}
int F_3 ( char * V_4 , const char * V_5 , const char * V_6 )
{
int V_7 = 0 ;
int line = 0 ;
while ( V_5 < V_6 ) {
unsigned char V_8 , V_9 , V_1 ;
V_8 = * V_5 ++ ;
* V_4 ++ = F_1 ( V_8 >> 2 ) ;
if ( V_5 < V_6 ) {
V_9 = * V_5 ++ ;
* V_4 ++ = F_1 ( ( ( V_8 & 3 ) << 4 ) | ( V_9 >> 4 ) ) ;
if ( V_5 < V_6 ) {
V_1 = * V_5 ++ ;
* V_4 ++ = F_1 ( ( ( V_9 & 15 ) << 2 ) |
( V_1 >> 6 ) ) ;
* V_4 ++ = F_1 ( V_1 & 63 ) ;
} else {
* V_4 ++ = F_1 ( ( V_9 & 15 ) << 2 ) ;
* V_4 ++ = '=' ;
}
} else {
* V_4 ++ = F_1 ( ( ( V_8 & 3 ) << 4 ) ) ;
* V_4 ++ = '=' ;
* V_4 ++ = '=' ;
}
V_7 += 4 ;
line += 4 ;
if ( line == 64 ) {
line = 0 ;
* ( V_4 ++ ) = '\n' ;
V_7 ++ ;
}
}
return V_7 ;
}
int F_4 ( char * V_4 , const char * V_5 , const char * V_6 )
{
int V_7 = 0 ;
while ( V_5 < V_6 ) {
int V_8 , V_9 , V_1 , V_10 ;
if ( V_5 [ 0 ] == '\n' ) {
V_5 ++ ;
continue;
}
if ( V_5 + 4 > V_6 )
return - V_3 ;
V_8 = F_2 ( V_5 [ 0 ] ) ;
V_9 = F_2 ( V_5 [ 1 ] ) ;
V_1 = F_2 ( V_5 [ 2 ] ) ;
V_10 = F_2 ( V_5 [ 3 ] ) ;
if ( V_8 < 0 || V_9 < 0 || V_1 < 0 || V_10 < 0 )
return - V_3 ;
* V_4 ++ = ( V_8 << 2 ) | ( V_9 >> 4 ) ;
if ( V_5 [ 2 ] == '=' )
return V_7 + 1 ;
* V_4 ++ = ( ( V_9 & 15 ) << 4 ) | ( V_1 >> 2 ) ;
if ( V_5 [ 3 ] == '=' )
return V_7 + 2 ;
* V_4 ++ = ( ( V_1 & 3 ) << 6 ) | V_10 ;
V_7 += 3 ;
V_5 += 4 ;
}
return V_7 ;
}
